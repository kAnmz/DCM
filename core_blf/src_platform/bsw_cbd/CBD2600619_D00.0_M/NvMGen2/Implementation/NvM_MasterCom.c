/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2026 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!        \file  NvM_MasterCom.c
 *        \brief  NvM_MasterCom source file
 *      \details  Implementation of the NvM_MasterCom unit.
 *         \unit  NvM_MasterCom
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#define NVM_MASTERCOM_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "NvM_MasterCom.h"

#if (NVM_MULTIPARTITION_USAGE_SCENARIO == STD_ON) /* COV_MSR_UT_OPTIONAL_UNIT */

#include "NvM_GlobalUtilityLib.h"
#include "vstdlib.h"

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**!<
 * Context information of communication port.
 * \spec
 *  strong invariant (NvM_MasterCom_Context.isJobActive && NvM_MasterCom_Context.masterSatellitePortPtr ==
 *                    NvM_GetMasterSatellitePorts_SingleBlockJobOfMasterSatellitePortsStruct_SingleBlockJob(
 *                      $range(0, GetSizeOfPartitionIdentifiers()-1),NVM_PARTITION_ID_MASTER))
 *                    || NvM_MasterCom_Context.masterSatellitePortPtr == NULL_PTR;
 * \endspec
 */
typedef struct
{
  NvM_MasterSatellitePort_SingleBlockJobPtrType masterSatellitePortPtr;   /*! Pointer to the active
                                                                              master-satellite-port */
  NvM_PartitionIdentifiersIterType lastProcessedSatellitePartitionId;     /*! Satellite which was processed last */
  boolean isJobActive;                                                    /*! Is a requested job active? */
} NvM_MasterCom_ContextType;

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**!<
 * Context information of communication port.
 */
NVM_LOCAL VAR(NvM_MasterCom_ContextType, NVM_PRIVATE_DATA) NvM_MasterCom_Context = {
  NULL_PTR,   /* No master-satellite-port */
  0u,         /* No known last processed partition */
  FALSE,      /* No job active */
};

#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define NVM_START_SEC_CODE
#include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * NvM_MasterCom_MapResult()
 *********************************************************************************************************************/
/*! \brief           Maps a service job result to a master port job status
 *  \details         -
 *  \param[in]       result               Service result of executed NV job.
 *  \pre             -
 *  \context         TASK
 *  \reentrant       FALSE
 *  \synchronous     TRUE
 *  \return          Mapped result.
 *********************************************************************************************************************/
NVM_LOCAL_INLINE FUNC(NvM_MasterSingleBlockJobStatusType, NVM_PRIVATE_CODE) NvM_MasterCom_MapResult(
  const NvM_ServiceJobResultType result);


/**********************************************************************************************************************
 * NvM_MasterCom_FindScanStartPartitionId()
 *********************************************************************************************************************/
/*! \brief       Finds next partition id to start scanning at
 *  \details     Necessary function to determine the partition to start scanning at
 *               due to the introduction of a round robin principal
 *               to not start scanning at the same satellite all the time.
 *               Implements a necessary overflow protection.
 *  \param[in]   partitionCount               Partition Count
 *  \pre         -
 *  \return      Start to scan partition id
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
NVM_LOCAL_INLINE FUNC(NvM_PartitionIdentifiersIterType, NVM_PRIVATE_CODE) NvM_MasterCom_FindScanStartPartitionId(
    const NvM_PartitionIdentifiersIterType partitionCount);

/**********************************************************************************************************************
 * NvM_MasterCom_FindNextAcceptedPartitionId()
 *********************************************************************************************************************/
/*! \brief       Finds next partition id to get accepted
 *  \details     Necessary function to determine the next accepted partition ID
 *  \param[in]   acceptedPartitionId               Accepted Partition ID
 *  \param[out]  acceptedPartitionId               Accepted Partition ID
 *  \pre         -
 *  \return      E_OK if found, E_NOT_OK otherwise
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
NVM_LOCAL_INLINE FUNC(Std_ReturnType, NVM_PRIVATE_CODE) NvM_MasterCom_FindNextAcceptedPartitionId(
  NvM_PartitionIdPtrType acceptedPartitionId);

#if (NVM_JOB_PRIORITIZATION == STD_ON)

/**********************************************************************************************************************
 * NvM_MasterCom_IsImmediateWriteJob()
 *********************************************************************************************************************/
/*! \brief       Determine if requested partition has an immediate write job requested
 *  \details     -
 *  \param[in]   satPortPtr      Satellite Port Pointer to check
 *  \param[in]   partitionId     Partition ID
 *  \pre         -
 *  \return      TRUE if immediate write job is requested, FALSE otherwise
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
NVM_LOCAL_INLINE FUNC(boolean, NVM_PRIVATE_CODE) NvM_MasterCom_IsImmediateWriteJob(
  NvM_SatellitePort_SingleBlockJobConstPtrToConstType satPortPtr,
  const NvM_PartitionIdType partitionId);

/**********************************************************************************************************************
 * NvM_MasterCom_HasPartitionAnyImmediateJobRequest()
 *********************************************************************************************************************/
/*! \brief       Checks if there is any requested immediate job (write job or CANCEL_IMMEDIATE) for the given partition
 *  \details     -
 *  \param[in]   partitionId     Partition ID
 *  \pre         -
 *  \return      TRUE if any immediate job is requested, FALSE otherwise
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
NVM_LOCAL_INLINE FUNC(boolean, NVM_PRIVATE_CODE) NvM_MasterCom_HasPartitionAnyImmediateJobRequest(
  const NvM_PartitionIdType partitionId);

#endif

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * NvM_MasterCom_MapResult()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
NVM_LOCAL_INLINE FUNC(NvM_MasterSingleBlockJobStatusType, NVM_PRIVATE_CODE) NvM_MasterCom_MapResult(
  const NvM_ServiceJobResultType result)
{
  NvM_MasterSingleBlockJobStatusType retVal = NVM_MASTERSATELLITE_SINGLEBLOCK_JOB_STATUS_NOT_OK;

  switch (result)
  {
    case NVM_SERVICE_JOB_PENDING:               retVal = NVM_MASTERSATELLITE_SINGLEBLOCK_JOB_STATUS_PENDING; break;
    case NVM_SERVICE_JOB_OK:                    retVal = NVM_MASTERSATELLITE_SINGLEBLOCK_JOB_STATUS_OK; break;
    case NVM_SERVICE_JOB_CANCELED:              retVal = NVM_MASTERSATELLITE_SINGLEBLOCK_JOB_STATUS_CANCELED; break;

    default:
      retVal = NVM_MASTERSATELLITE_SINGLEBLOCK_JOB_STATUS_NOT_OK;
      break;
  }

  return retVal;
}

/**********************************************************************************************************************
 * NvM_MasterCom_FindScanStartPartitionId()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
NVM_LOCAL_INLINE FUNC(NvM_PartitionIdentifiersIterType, NVM_PRIVATE_CODE) NvM_MasterCom_FindScanStartPartitionId(
  const NvM_PartitionIdentifiersIterType partitionCount)
{
  return ((NvM_MasterCom_Context.lastProcessedSatellitePartitionId < (partitionCount - 1u))
            ? (NvM_MasterCom_Context.lastProcessedSatellitePartitionId + 1u)
            : 0u);
}

#if (NVM_JOB_PRIORITIZATION == STD_ON)

/**********************************************************************************************************************
 * NvM_MasterCom_IsImmediateWriteJob()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
NVM_LOCAL_INLINE FUNC(boolean, NVM_PRIVATE_CODE) NvM_MasterCom_IsImmediateWriteJob(
  NvM_SatellitePort_SingleBlockJobConstPtrToConstType satPortPtr,
  const NvM_PartitionIdType partitionId)
{
  boolean isImmediateWriteJob = FALSE;

  if ((satPortPtr->JobRequest == NVM_SATELLITE_SINGLEBLOCK_JOB_REQUEST_REQUESTED)
    && (satPortPtr->JobInformation.BlockDescriptorLookupTableId < NvM_GetSizeOfBlockDescriptor())
    && (satPortPtr->JobInformation.SingleBlockJobType == NVM_SINGLEBLOCKJOBTYPE_WRITE_BLOCK))
  {
    NvM_BlockDescriptorPtrToConstType satelliteBlockDescriptor =
      NvM_GetAddrBlockDescriptor(satPortPtr->JobInformation.BlockDescriptorLookupTableId);

    if ((satelliteBlockDescriptor->PartitionId == partitionId)
        && (satelliteBlockDescriptor->Priority == NVM_IMMEDIATE_JOB_PRIORITY))
    {
      isImmediateWriteJob = TRUE;
    }
  }

  return isImmediateWriteJob;
}

/**********************************************************************************************************************
 * NvM_MasterCom_HasPartitionAnyImmediateJobRequest()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
NVM_LOCAL_INLINE FUNC(boolean, NVM_PRIVATE_CODE) NvM_MasterCom_HasPartitionAnyImmediateJobRequest(
  const NvM_PartitionIdType partitionId)
{
  boolean hasPartitionAnyImmediateJobRequest = FALSE;

  /* DO NOT CHANGE: Use copy of port due to safety reason */
  NvM_SatellitePort_SingleBlockJobType currentSatPort = NvM_GetSatellitePort_SingleBlockJob(partitionId);

  /* Check for cancel immediate job */
  if (currentSatPort.JobRequest == NVM_SATELLITE_SINGLEBLOCK_JOB_REQUEST_CANCEL_IMMEDIATE)
  {
    hasPartitionAnyImmediateJobRequest = TRUE;
  }
  else 
  {
    NvM_MasterSatellitePortsStruct_SingleBlockJobIterType accessIndex =
      NvM_GlobalUtilityLib_GetAccessIndexForMasterSatellitePorts_SingleBlockJob(partitionId);

    /* CSL can generate data for master only. Nevertheless, the NvM_PCPartitionConfigType struct definition needs an entry
    (filled with NULL_PTR if not available). Therefore the CSL getter remains the same. Hence fix partition to MASTER here. */
    NvM_MasterSatellitePort_SingleBlockJobConstPtrType masterSatellitePort =
      NvM_GetMasterSatellitePorts_SingleBlockJobOfMasterSatellitePortsStruct_SingleBlockJob(
        accessIndex, NVM_PARTITION_ID_MASTER);

    /* Check for non matching request counter as an indication of a new job request.
       It is not necessary to check for already acknowledged immediate jobs here */
    if((currentSatPort.RequestCounter != masterSatellitePort->RequestCounter))
    {
      /* Check for immediate write job request */
      hasPartitionAnyImmediateJobRequest = NvM_MasterCom_IsImmediateWriteJob(&currentSatPort, partitionId);             /* VCA_NVM_IsImmediateWriteJobBlockDescriptorLookupTableId */
    }
  }

  return hasPartitionAnyImmediateJobRequest;                                               
}

#endif


/**********************************************************************************************************************
 * NvM_MasterCom_FindNextAcceptedPartitionId()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
NVM_LOCAL_INLINE FUNC(Std_ReturnType, NVM_PRIVATE_CODE) NvM_MasterCom_FindNextAcceptedPartitionId(
  NvM_PartitionIdPtrType acceptedPartitionId)
{
  const NvM_PartitionIdType partitionCount = NvM_GetSizeOfPartitionIdentifiers();
  NvM_PartitionIdType partitionId = 0u;
  NvM_PartitionIdType startToScanPartitionId = (NvM_PartitionIdType)NvM_MasterCom_FindScanStartPartitionId(partitionCount);
  Std_ReturnType jobFound = E_NOT_OK;
#if (NVM_JOB_PRIORITIZATION == STD_ON)
  uint8 maxJobPriority = 0xFF;
#endif

  for (NvM_PartitionIdType i = 0; i < partitionCount; i++)
  {
    /*
     * A satellite partition id overflow is necessary to iterate over all satellites
     * no matter at which index you start.
     */
    partitionId = startToScanPartitionId + i;
    if (partitionId >= partitionCount)
    {
      partitionId -= partitionCount;
    }

    /* DO NOT CHANGE: Use copy of port due to safety reason */
    NvM_SatellitePort_SingleBlockJobType currentSatPort = NvM_GetSatellitePort_SingleBlockJob(partitionId);

    NvM_MasterSatellitePortsStruct_SingleBlockJobIterType accessIndex =
      NvM_GlobalUtilityLib_GetAccessIndexForMasterSatellitePorts_SingleBlockJob(partitionId);

    /* CSL can generate data for master only. Nevertheless, the NvM_PCPartitionConfigType struct definition needs an entry
    (filled with NULL_PTR if not available). Therefore the CSL getter remains the same. Hence fix partition to MASTER here. */
    NvM_MasterSatellitePort_SingleBlockJobConstPtrType currentMasterPort =
      NvM_GetMasterSatellitePorts_SingleBlockJobOfMasterSatellitePortsStruct_SingleBlockJob(
        accessIndex, NVM_PARTITION_ID_MASTER);

    if ((currentSatPort.JobRequest == NVM_SATELLITE_SINGLEBLOCK_JOB_REQUEST_REQUESTED)
      && (currentMasterPort->RequestCounter != currentSatPort.RequestCounter)
      && (currentSatPort.JobInformation.BlockDescriptorLookupTableId < NvM_GetSizeOfBlockDescriptor()))
    {
      NvM_BlockDescriptorPtrToConstType satelliteBlockDescriptor =
        NvM_GetAddrBlockDescriptor(currentSatPort.JobInformation.BlockDescriptorLookupTableId);

      /* DO NOT CHANGE: Check if block belongs to requested partition */
      if(satelliteBlockDescriptor->PartitionId == partitionId)
      {
#if (NVM_JOB_PRIORITIZATION == STD_ON)
        const boolean isImmediateWriteJob = (satelliteBlockDescriptor->Priority == NVM_IMMEDIATE_JOB_PRIORITY)
                                            && (currentSatPort.JobInformation.SingleBlockJobType == NVM_SINGLEBLOCKJOBTYPE_WRITE_BLOCK);

        if (isImmediateWriteJob || (satelliteBlockDescriptor->Priority < maxJobPriority))
        {
          *acceptedPartitionId = partitionId;
          jobFound = E_OK;
          maxJobPriority = satelliteBlockDescriptor->Priority;
        }
        /* Immediate write job found, no higher priority possible */
        if (isImmediateWriteJob)
        {
          break;
        }
#else
        *acceptedPartitionId = partitionId;
        jobFound = E_OK;
        break;
#endif /* NVM_JOB_PRIORITIZATION == STD_ON */
      }
    }
  }
  return jobFound;
}

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * NvM_MasterCom_AcceptSingleBlockJobRequest()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, NVM_PRIVATE_CODE) NvM_MasterCom_AcceptSingleBlockJobRequest(
  NvM_SingleBlockJobContextPtrType acceptedJobPtr)
{
  Std_ReturnType jobAccepted = E_NOT_OK;
  NvM_PartitionIdType acceptedPartitionId = 0u;

  jobAccepted = NvM_MasterCom_FindNextAcceptedPartitionId(&acceptedPartitionId);
  if (jobAccepted == E_OK)
  {
    /* Get References to Port of accepted PartitionId*/
    NvM_SatellitePort_SingleBlockJobType acceptedSatPort = NvM_GetSatellitePort_SingleBlockJob(acceptedPartitionId);
    const NvM_BlockDescriptorPtrType acceptedSatelliteBlockDescriptor =
        NvM_GetAddrBlockDescriptor(acceptedSatPort.JobInformation.BlockDescriptorLookupTableId);

    NvM_MasterSatellitePortsStruct_SingleBlockJobIterType accessIndexForMasterSatellitePort =
      NvM_GlobalUtilityLib_GetAccessIndexForMasterSatellitePorts_SingleBlockJob(acceptedPartitionId);

    /* CSL can generate data for master only. Nevertheless, the NvM_PCPartitionConfigType struct definition needs an entry
    (filled with NULL_PTR if not available). Therefore the CSL getter remains the same. Hence fix partition to MASTER here. */
    NvM_MasterSatellitePort_SingleBlockJobConstPtrType acceptedMasterPort =
      NvM_GetMasterSatellitePorts_SingleBlockJobOfMasterSatellitePortsStruct_SingleBlockJob(
        accessIndexForMasterSatellitePort, NVM_PARTITION_ID_MASTER);

    /* Fill out-structure */
    acceptedJobPtr->BlockDescriptorLookupTableId = acceptedSatPort.JobInformation.BlockDescriptorLookupTableId;
    acceptedJobPtr->SingleBlockJobType = acceptedSatPort.JobInformation.SingleBlockJobType;
    acceptedJobPtr->DataIndex = acceptedSatPort.JobInformation.DataIndex;

    NvM_InternalMasterBuffersStructIterType accessIndexForInternalMasterBuffer =
      NvM_GlobalUtilityLib_GetAccessIndexForInternalMasterBuffers(acceptedPartitionId);

    /* CSL can generate data for master only. Nevertheless, the NvM_PCPartitionConfigType struct definition needs an entry
    (filled with NULL_PTR if not available). Therefore the CSL getter remains the same. Hence fix partition to MASTER here. */
    acceptedJobPtr->DataBuffer =
      NvM_GetInternalMasterBuffersOfInternalMasterBuffersStruct(accessIndexForInternalMasterBuffer, NVM_PARTITION_ID_MASTER);
    /* left out, not relevant at this level: acceptedJobPtr->TemporaryRamBlockAddr */

    /* Update context information */
    NvM_MasterCom_Context.masterSatellitePortPtr = acceptedMasterPort;
    NvM_MasterCom_Context.isJobActive = TRUE;
    /*
      * DO NOT CHANGE: Copy satellite internal buffer content to internal master buffer
      *                in case of write/writeall job.
      */
    if ((acceptedJobPtr->SingleBlockJobType == NVM_SINGLEBLOCKJOBTYPE_WRITE_BLOCK)
        || (acceptedJobPtr->SingleBlockJobType == NVM_SINGLEBLOCKJOBTYPE_WRITE_ALL_BLOCK))
    {
      const uint16 nvDataLength = NvM_GlobalUtilityLib_GetNvDataLength(acceptedSatelliteBlockDescriptor);               /* VCA_NVM_PartitionIdOfAcceptedBlockDescriptor */

      NvM_DataPtrToConstType satelliteBuffer = NvM_GetAddrInternalBuffer(0u, acceptedPartitionId);

      VStdLib_MemCpy(acceptedJobPtr->DataBuffer, satelliteBuffer, nvDataLength);                                        /* VCA_NVM_VStdLibMemCpyCalls */
    }

    /* Acknowledge accepted request */
    acceptedMasterPort->RequestCounter = acceptedSatPort.RequestCounter;
    acceptedMasterPort->JobStatus = NVM_MASTERSATELLITE_SINGLEBLOCK_JOB_STATUS_PENDING;

    /* Store last processed satellite */
    NvM_MasterCom_Context.lastProcessedSatellitePartitionId = acceptedPartitionId;
  }

  return jobAccepted;
}

/**********************************************************************************************************************
 * NvM_MasterCom_FinalizeActiveSingleBlockJobRequest()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, NVM_PRIVATE_CODE) NvM_MasterCom_FinalizeActiveSingleBlockJobRequest(const NvM_ServiceJobResultType result)
{
  /* VCA Next Line ANO-01 : VCA_NVM_FinalizeActiveSingleBlockJobRequest */
  /*@ assert NvM_MasterCom_Context.isJobActive && NvM_MasterCom_Context.masterSatellitePortPtr ==
  NvM_GetMasterSatellitePorts_SingleBlockJobOfMasterSatellitePortsStruct_SingleBlockJob(
    $range(0, GetSizeOfPartitionIdentifiers()-1),NVM_PARTITION_ID_MASTER); */
  NvM_MasterCom_Context.masterSatellitePortPtr->JobStatus = NvM_MasterCom_MapResult(result);                            /* VCA_NVM_FinalizeActiveSingleBlockJobRequest */

  NvM_MasterCom_Context.isJobActive = FALSE;
  NvM_MasterCom_Context.masterSatellitePortPtr = NULL_PTR;
}

/**********************************************************************************************************************
 * NvM_MasterCom_BroadcastMultiBlockRequestToSatellites()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, NVM_PRIVATE_CODE) NvM_MasterCom_BroadcastMultiBlockRequestToSatellites(const NvM_MultiBlockJobType jobType)
{
  const NvM_PartitionIdentifiersIterType partitionCount = NvM_GetSizeOfPartitionIdentifiers();

  for (NvM_PartitionIdentifiersIterType i = 0; i < partitionCount; i++)
  {
    NvM_MasterSatellitePortsStruct_MultiBlockJobIterType accessIndex =
      NvM_GlobalUtilityLib_GetAccessIndexForMasterSatellitePorts_MultiBlockJob(i);

    /* CSL can generate data for master only. Nevertheless, the NvM_PCPartitionConfigType struct definition needs an entry
    (filled with NULL_PTR if not available). Therefore the CSL getter remains the same. Hence fix partition to MASTER here. */
    NvM_MasterSatellitePort_MultiBlockJobConstPtrType masterPort =
      NvM_GetMasterSatellitePorts_MultiBlockJobOfMasterSatellitePortsStruct_MultiBlockJob(
        accessIndex, NVM_PARTITION_ID_MASTER);

    /*
    * It is important to keep the order of the master - satellite port variable assignment as it is,
    * so the complete information can be expected to be correct.
    */

    masterPort->JobType = jobType;
    masterPort->JobRequest = NVM_MASTERSATELLITE_MULTIBLOCK_JOB_REQUEST_REQUESTED;
  }
}

/**********************************************************************************************************************
 * NvM_MasterCom_StartMultiBlockJobProcessing()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, NVM_PRIVATE_CODE) NvM_MasterCom_StartMultiBlockJobProcessing(
  const NvM_PartitionIdType targetSatellitePartitionId)
{
  NvM_MasterSatellitePortsStruct_MultiBlockJobIterType accessIndex =
    NvM_GlobalUtilityLib_GetAccessIndexForMasterSatellitePorts_MultiBlockJob(targetSatellitePartitionId);

  /* CSL can generate data for master only. Nevertheless, the NvM_PCPartitionConfigType struct definition needs an entry
  (filled with NULL_PTR if not available). Therefore the CSL getter remains the same. Hence fix partition to MASTER here. */
  NvM_MasterSatellitePort_MultiBlockJobConstPtrType masterPort =
    NvM_GetMasterSatellitePorts_MultiBlockJobOfMasterSatellitePortsStruct_MultiBlockJob(
      accessIndex, NVM_PARTITION_ID_MASTER);

  masterPort->JobRequest = NVM_MASTERSATELLITE_MULTIBLOCK_JOB_REQUEST_PROCESSING;
}

/**********************************************************************************************************************
 * NvM_MasterCom_StartMultiBlockJobProcessingInParallel()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, NVM_PRIVATE_CODE) NvM_MasterCom_StartMultiBlockJobProcessingInParallel(void)
{
  const NvM_PartitionIdentifiersIterType partitionCount = NvM_GetSizeOfPartitionIdentifiers();

  for (NvM_PartitionIdentifiersIterType i = 0; i < partitionCount; i++)
  {
    NvM_MasterSatellitePortsStruct_MultiBlockJobIterType accessIndex =
      NvM_GlobalUtilityLib_GetAccessIndexForMasterSatellitePorts_MultiBlockJob(i);

    /* CSL can generate data for master only. Nevertheless, the NvM_PCPartitionConfigType struct definition needs an entry
    (filled with NULL_PTR if not available). Therefore the CSL getter remains the same. Hence fix partition to MASTER here. */
    NvM_MasterSatellitePort_MultiBlockJobConstPtrType masterPort =
      NvM_GetMasterSatellitePorts_MultiBlockJobOfMasterSatellitePortsStruct_MultiBlockJob(
        accessIndex, NVM_PARTITION_ID_MASTER);

    masterPort->JobRequest = NVM_MASTERSATELLITE_MULTIBLOCK_JOB_REQUEST_PROCESSING;
  }
}

/**********************************************************************************************************************
 * NvM_MasterCom_GetMultiBlockJobStatus()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(NvM_SatelliteMultiBlockJobStatusType, NVM_PRIVATE_CODE) NvM_MasterCom_GetMultiBlockJobStatus(
  const NvM_PartitionIdType targetSatellitePartitionId)
{
  /* DO NOT CHANGE: Use copy of port due to safety reason */
  NvM_SatellitePort_MultiBlockJobType satellitePort = NvM_GetSatellitePort_MultiBlockJob(targetSatellitePartitionId);

  return satellitePort.JobStatus;
}

/**********************************************************************************************************************
 * NvM_MasterCom_AreAllSatellitesFinishedWithMultiBlockJob()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(boolean, NVM_PRIVATE_CODE) NvM_MasterCom_AreAllSatellitesFinishedWithMultiBlockJob(void)
{
  boolean areAllSatellitesFinished = FALSE;
  const NvM_PartitionIdentifiersIterType partitionCount = NvM_GetSizeOfPartitionIdentifiers();

  for (NvM_PartitionIdentifiersIterType i = 0; i < partitionCount; i++)
  {
    const NvM_SatelliteMultiBlockJobStatusType jobStatus = NvM_MasterCom_GetMultiBlockJobStatus((NvM_PartitionIdType)i);

    if ((jobStatus != NVM_SATELLITE_MULTIBLOCK_JOB_STATUS_READY)
        && (jobStatus != NVM_SATELLITE_MULTIBLOCK_JOB_STATUS_ACTIVE))
    {
      areAllSatellitesFinished = TRUE;
    }
    else
    {
      areAllSatellitesFinished = FALSE;
      break;
    }
  }

  return areAllSatellitesFinished;
}

/**********************************************************************************************************************
 * NvM_MasterCom_CleanupAcknowledgedSingleBlockJobSatellitePorts()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, NVM_PRIVATE_CODE) NvM_MasterCom_CleanupAcknowledgedSingleBlockJobSatellitePorts(void)
{
  const NvM_PartitionIdentifiersIterType partitionCount = NvM_GetSizeOfPartitionIdentifiers();

  for (NvM_PartitionIdentifiersIterType partitionId = 0u; partitionId < partitionCount; partitionId++)
  {
    NvM_MasterSatellitePortsStruct_SingleBlockJobIterType accessIndex =
      NvM_GlobalUtilityLib_GetAccessIndexForMasterSatellitePorts_SingleBlockJob(partitionId);

    /* CSL can generate data for master only. Nevertheless, the NvM_PCPartitionConfigType struct definition needs an entry
    (filled with NULL_PTR if not available). Therefore the CSL getter remains the same. Hence fix partition to MASTER here. */
    NvM_MasterSatellitePort_SingleBlockJobConstPtrType currentMasterPort =
      NvM_GetMasterSatellitePorts_SingleBlockJobOfMasterSatellitePortsStruct_SingleBlockJob(
        accessIndex, NVM_PARTITION_ID_MASTER);

    /* DO NOT CHANGE: Use copy of port due to safety reason */
    NvM_SatellitePort_SingleBlockJobType currentSatPort = NvM_GetSatellitePort_SingleBlockJob(
        (NvM_PCPartitionConfigIdxOfPartitionIdentifiersType)partitionId);

    const boolean isMasterJobWaitingForAcknowledgement =
        (currentMasterPort->JobStatus != NVM_MASTERSATELLITE_SINGLEBLOCK_JOB_STATUS_PENDING)
        && (currentMasterPort->JobStatus != NVM_MASTERSATELLITE_SINGLEBLOCK_JOB_STATUS_NONE);

    /*
     * Satellite-port acknowledged the finalized job on master side.
     * Note:
     *  - The port counters are only relevant for satellites, hence can be ignored here
     *  - If a new request from satellite is directly published, it will be accepted later on
     */
    if (isMasterJobWaitingForAcknowledgement
        && (currentSatPort.JobRequest == NVM_SATELLITE_SINGLEBLOCK_JOB_REQUEST_NONE))
    {
      currentMasterPort->JobStatus = NVM_MASTERSATELLITE_SINGLEBLOCK_JOB_STATUS_NONE;
    }
  }
}

/**********************************************************************************************************************
 * NvM_MasterCom_ResetMultiBlockJobPorts()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, NVM_PRIVATE_CODE) NvM_MasterCom_ResetMultiBlockJobPorts(void)
{
  const NvM_PartitionIdentifiersIterType partitionCount = NvM_GetSizeOfPartitionIdentifiers();

  for (NvM_PartitionIdentifiersIterType i = 0; i < partitionCount; i++)
  {
    NvM_MasterSatellitePortsStruct_MultiBlockJobIterType accessIndex =
      NvM_GlobalUtilityLib_GetAccessIndexForMasterSatellitePorts_MultiBlockJob(i);

    /* CSL can generate data for master only. Nevertheless, the NvM_PCPartitionConfigType struct definition needs an entry
    (filled with NULL_PTR if not available). Therefore the CSL getter remains the same. Hence fix partition to MASTER here. */
    NvM_MasterSatellitePort_MultiBlockJobConstPtrType masterPort =
      NvM_GetMasterSatellitePorts_MultiBlockJobOfMasterSatellitePortsStruct_MultiBlockJob(
        accessIndex, NVM_PARTITION_ID_MASTER);

    masterPort->JobRequest = NVM_MASTERSATELLITE_MULTIBLOCK_JOB_REQUEST_NONE;
  }
}


/**********************************************************************************************************************
 * NvM_MasterCom_DetermineDemErrorCount()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
FUNC(uint16, NVM_PRIVATE_CODE) NvM_MasterCom_DetermineDemErrorCount(const NvM_DemErrorIdType error)
{
  uint16 errorCountDifference = 0u;

#if (NVM_DEM_ERROR_REPORT == STD_ON)
  const NvM_PartitionIdentifiersIterType partitionCount = NvM_GetSizeOfPartitionIdentifiers();

  for (NvM_PartitionIdentifiersIterType i = 0u; i < partitionCount; i++)
  {
    const NvM_ErrorCountersPortType satellitePort = NvM_GetSatellitePort_ErrorCounters(
      (NvM_PCPartitionConfigIdxOfPartitionIdentifiersType)i);

    NvM_MasterSatellitePortsStruct_ErrorCountersMirrorIterType accessIndex =
      NvM_GlobalUtilityLib_GetAccessIndexForMasterSatellitePorts_ErrorCountersMirror(i);

    /* CSL can generate data for master only. Nevertheless, the NvM_PCPartitionConfigType struct definition needs an entry
    (filled with NULL_PTR if not available). Therefore the CSL getter remains the same. Hence fix partition to MASTER here. */
    NvM_ErrorCountersPortConstPtrType masterMirrorPort =
      NvM_GetMasterSatellitePorts_ErrorCountersMirrorOfMasterSatellitePortsStruct_ErrorCountersMirror(
        accessIndex, NVM_PARTITION_ID_MASTER);

    switch(error)
    {
      case NVM_DEM_ERROR_TYPE_INTEGRITY_FAILED:
        errorCountDifference +=
          (uint16)(satellitePort.DataIntegrityFailedError - masterMirrorPort->DataIntegrityFailedError);                /* PRQA S 4391 */ /* MD_MasterCom_DemErrorCountCast */
        masterMirrorPort->DataIntegrityFailedError = satellitePort.DataIntegrityFailedError;
        break;
      case NVM_DEM_ERROR_TYPE_REQ_FAILED:
        errorCountDifference += (uint16)(satellitePort.ReqFailedError - masterMirrorPort->ReqFailedError);              /* PRQA S 4391 */ /* MD_MasterCom_DemErrorCountCast */
        masterMirrorPort->ReqFailedError = satellitePort.ReqFailedError;
        break;

      default:
        /*
         * MISRA case. Do nothing.
         * This default case is empty due to the fact that NVM_DEM_ERROR_TYPE_LOSS_OF_REDUNDANCY
         * is only dispatched in the nv layer. This way the master can dispatch it directly and does not
         * need to derive it from the satellite ports.
         */
        break;
    }
  }
#else
  NVM_DUMMY_STATEMENT_CONST(error);                                                                                     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif /* NVM_DEM_ERROR_REPORT */
  return errorCountDifference;
}

#if (NVM_JOB_PRIORITIZATION == STD_ON)

/**********************************************************************************************************************
 * NvM_MasterCom_IsAnyImmediateJobRequested()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(boolean, NVM_PRIVATE_CODE) NvM_MasterCom_IsAnyImmediateJobRequested(void)
{
  boolean isAnyImmediateJobRequested = FALSE;

  const NvM_PartitionIdentifiersIterType partitionCount = NvM_GetSizeOfPartitionIdentifiers();

  for (NvM_PartitionIdentifiersIterType partitionId = 0; partitionId < partitionCount; partitionId++)
  {
    if (NvM_MasterCom_HasPartitionAnyImmediateJobRequest((NvM_PCPartitionConfigIdxOfPartitionIdentifiersType)partitionId))
    {
      isAnyImmediateJobRequested = TRUE;
      break;
    }
  }

  return isAnyImmediateJobRequested;
}

/**********************************************************************************************************************
 * NvM_MasterCom_IsImmediateJobRequestedForPartition()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(boolean, NVM_PRIVATE_CODE) NvM_MasterCom_IsImmediateJobRequestedForPartition(
  const NvM_PartitionIdType targetSatellitePartitionId)
{
  return NvM_MasterCom_HasPartitionAnyImmediateJobRequest(targetSatellitePartitionId);
}

/**********************************************************************************************************************
 * NvM_MasterCom_IsAnyImmediateJobReadyForNvProcessing()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(boolean, NVM_PRIVATE_CODE) NvM_MasterCom_IsAnyImmediateJobReadyForNvProcessing(void)
{
  boolean isAnyImmediateJobReadyForNvProcessing = FALSE;

  const NvM_PartitionIdentifiersIterType partitionCount = NvM_GetSizeOfPartitionIdentifiers();

  for (NvM_PartitionIdentifiersIterType partitionId = 0; partitionId < partitionCount; partitionId++)
  {
    /* DO NOT CHANGE: Use copy of port due to safety reason */
    NvM_SatellitePort_SingleBlockJobType currentSatPort = NvM_GetSatellitePort_SingleBlockJob(
      (NvM_PCPartitionConfigIdxOfPartitionIdentifiersType)partitionId);

    /* First check if it's an immediate write job */
    if (NvM_MasterCom_IsImmediateWriteJob(&currentSatPort,                                                              /* VCA_NVM_IsImmediateWriteJobBlockDescriptorLookupTableId */
        (NvM_PCPartitionConfigIdxOfPartitionIdentifiersType)partitionId))
    {
      /* Then verify it hasn't been acknowledged yet by checking request counter */
      NvM_MasterSatellitePortsStruct_SingleBlockJobIterType accessIndex =
        NvM_GlobalUtilityLib_GetAccessIndexForMasterSatellitePorts_SingleBlockJob(partitionId);

      /* CSL can generate data for master only. Nevertheless, the NvM_PCPartitionConfigType struct definition needs an entry
      (filled with NULL_PTR if not available). Therefore the CSL getter remains the same. Hence fix partition to MASTER here. */
      NvM_MasterSatellitePort_SingleBlockJobConstPtrType currentMasterSatellitePort =
        NvM_GetMasterSatellitePorts_SingleBlockJobOfMasterSatellitePortsStruct_SingleBlockJob(
          accessIndex, NVM_PARTITION_ID_MASTER);

      if (currentMasterSatellitePort->RequestCounter != currentSatPort.RequestCounter)
      {
        isAnyImmediateJobReadyForNvProcessing = TRUE;
        break;
      }
    }
  }

  return isAnyImmediateJobReadyForNvProcessing;
}

/**********************************************************************************************************************
 * NvM_MasterCom_ResetMasterSatellitePort()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, NVM_PRIVATE_CODE) NvM_MasterCom_ResetMasterSatellitePort(
  const NvM_PartitionIdType targetSatellitePartitionId)
{
  NvM_MasterSatellitePortsStruct_SingleBlockJobIterType accessIndex =
    NvM_GlobalUtilityLib_GetAccessIndexForMasterSatellitePorts_SingleBlockJob(targetSatellitePartitionId);

  /* CSL can generate data for master only. Nevertheless, the NvM_PCPartitionConfigType struct definition needs an entry
  (filled with NULL_PTR if not available). Therefore the CSL getter remains the same. Hence fix partition to MASTER here. */
  NvM_MasterSatellitePort_SingleBlockJobConstPtrType currentMasterSatellitePort =
    NvM_GetMasterSatellitePorts_SingleBlockJobOfMasterSatellitePortsStruct_SingleBlockJob(
      accessIndex, NVM_PARTITION_ID_MASTER);

  currentMasterSatellitePort->JobStatus = NVM_MASTERSATELLITE_SINGLEBLOCK_JOB_STATUS_NONE;
  currentMasterSatellitePort->RequestCounter--; /* Resetting request counter to indicate canceled request */
}

#endif

#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* NVM_MULTIPARTITION_USAGE_SCENARIO */

/***********************************************************************************************************************
 *  MISRA JUSTIFICATIONS
 **********************************************************************************************************************/

/* Justification for module-specific MISRA deviations:

MD_MasterCom_DemErrorCountCast:
  Reason:     The DEM error count communicated over the master - satellite port interface contains uint8 variables
              to hold the corresponding DEM error count number.
              The overall error count is an unit16 variable to avoid overflow/underflow issues when reporting the
              correct number of DEM errors. So the difference between master mirror and satellite error count
              must be casted to uint16.
  Risk:       None.
  Prevention: A code review shall ensure that there is no side effect. Also tests show that the casting works.

*/

/***********************************************************************************************************************
 *  VCA JUSTIFICATIONS
 **********************************************************************************************************************/
/* VCA_JUSTIFICATION_BEGIN

\ID VCA_NVM_PartitionIdOfAcceptedBlockDescriptor
  \DESCRIPTION The function NvM_GlobalUtilityLib_GetNvDataLength takes the blockDescriptor variable to determine
               its nv length. This functions does not changes the value of this variable.
               The partition ID already gets checked for its range in the NvM_MasterCom_FindNextAcceptedPartitionId()
               function. The partition ID can therefore not be outside of its range by design.

  \COUNTERMEASURE \N A code review ensures that the partitionId is always in range when used.

\ID VCA_NVM_IsImmediateWriteJobBlockDescriptorLookupTableId
  \DESCRIPTION The function IsImmediateWrite takes takes a function pointer to the satPort variable to determine
               if a immediate write job is present. This function checks the BlockDescriptorLookupTableId to be 
               in range and does not change its value. The BlockDescriptorLookupTableId can therefore not be
               outside of its range by design.

  \COUNTERMEASURE \N A code review ensures that the BlockDescriptorLookupTableId is always in range when used.

\ID VCA_NVM_FinalizeActiveSingleBlockJobRequest
  \DESCRIPTION If the function NvM_MasterCom_FinalizeActiveSingleBlockJobRequest is called, the
               NvM_MasterCom_AcceptSingleBlockJobRequest function must have been called before. In this function
               a valid master satellite port context is set.
               The assertion and the following pointer access can therefore not be a NULL_PTR access,
               since by design it is not possible that the pointer is NULL when the Finalize function is invoked.

  \COUNTERMEASURE \N A code review ensures that the NvM_MasterCom_FinalizeActiveSingleBlockJobRequest is
                     always called after NvM_MasterCom_AcceptSingleBlockJobRequest.

VCA_JUSTIFICATION_END */

/**********************************************************************************************************************
 *  END OF FILE: NvM_MasterCom.c
 *********************************************************************************************************************/
