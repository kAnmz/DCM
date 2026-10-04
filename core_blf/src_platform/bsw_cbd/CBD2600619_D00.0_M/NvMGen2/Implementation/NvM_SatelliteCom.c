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
/*!        \file  NvM_SatelliteCom.c
 *        \brief  NvM_SatelliteCom source file
 *      \details  Implementation of the satellite communication unit of the NvM.
 *         \unit  NvM_SatelliteCom
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#define NVM_SATELLITECOM_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "NvM_SatelliteCom.h"

#if (NVM_MULTIPARTITION_USAGE_SCENARIO == STD_ON) /* COV_MSR_UT_OPTIONAL_UNIT */

#include "NvM_Cfg.h"
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

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * NvM_SatelliteCom_MapMasterSingleBlockJobStatusToServiceJobResult()
 *********************************************************************************************************************/
/*! \brief       Retrieve the job status from master and converts it to service job result.
 *  \details     -
 *  \param[in]   jobStatus Job status of corresponding mastersatellite single block job port.
 *  \pre         -
 *  \return      Mapped ServiceJobResult result.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(NvM_ServiceJobResultType, NVM_PRIVATE_CODE) NvM_SatelliteCom_MapMasterSingleBlockJobStatusToServiceJobResult(
  const NvM_MasterSingleBlockJobStatusType jobStatus);

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
#define NVM_START_SEC_CODE
#include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
*  NvM_SatelliteCom_ConvertMasterSingleBlockJobStatusToServiceJobResult
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(NvM_ServiceJobResultType, NVM_PRIVATE_CODE) NvM_SatelliteCom_MapMasterSingleBlockJobStatusToServiceJobResult(
  const NvM_MasterSingleBlockJobStatusType jobStatus)
{
  NvM_ServiceJobResultType result = NVM_SERVICE_JOB_PENDING;

  switch(jobStatus)
  {
    case NVM_MASTERSATELLITE_SINGLEBLOCK_JOB_STATUS_NOT_OK:               result = NVM_SERVICE_JOB_NOT_OK; break;
    case NVM_MASTERSATELLITE_SINGLEBLOCK_JOB_STATUS_OK:                   result = NVM_SERVICE_JOB_OK; break;
    case NVM_MASTERSATELLITE_SINGLEBLOCK_JOB_STATUS_CANCELED:             result = NVM_SERVICE_JOB_CANCELED; break;

    default:
      result = NVM_SERVICE_JOB_PENDING;
      break;
  }

  return result;
}

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
*  NvM_SatelliteCom_RequestSingleBlockJob
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, NVM_PRIVATE_CODE) NvM_SatelliteCom_RequestSingleBlockJob(
  NvM_SingleBlockJobContextPtrToConstType singleBlockJobContext,
  const NvM_PartitionIdType partitionId)
{
  NvM_SatellitePort_SingleBlockJobPtrType satellitePort = NvM_GetAddrSatellitePort_SingleBlockJob(partitionId);

  /*
   * It is important to keep the order of the satellite port variable assignment as it is,
   * so the complete information can be expected to be correct.
   */
  satellitePort->JobInformation.BlockDescriptorLookupTableId = singleBlockJobContext->BlockDescriptorLookupTableId;
  satellitePort->JobInformation.SingleBlockJobType = singleBlockJobContext->SingleBlockJobType;
  satellitePort->JobInformation.DataIndex = singleBlockJobContext->DataIndex;

  satellitePort->RequestCounter++;

  satellitePort->JobRequest = NVM_SATELLITE_SINGLEBLOCK_JOB_REQUEST_REQUESTED;
}

/**********************************************************************************************************************
*  NvM_SatelliteCom_GetSingleBlockJobStatus
**********************************************************************************************************************/
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
FUNC(NvM_ServiceJobResultType, NVM_PRIVATE_CODE) NvM_SatelliteCom_GetSingleBlockJobStatus(
  const NvM_PartitionIdType partitionId)
{
  NvM_ServiceJobResultType result = NVM_SERVICE_JOB_PENDING;

  NvM_MasterSatellitePortsStruct_SingleBlockJobIterType accessIndex =
    NvM_GlobalUtilityLib_GetAccessIndexForMasterSatellitePorts_SingleBlockJob(partitionId);

  /* CSL can generate data for master only. Nevertheless, the NvM_PCPartitionConfigType struct definition needs an entry
  (filled with NULL_PTR if not available). Therefore the CSL getter remains the same. Hence fix partition to MASTER here. */
  NvM_MasterSatellitePort_SingleBlockJobConstPtrType tempMasterPort =
    NvM_GetMasterSatellitePorts_SingleBlockJobOfMasterSatellitePortsStruct_SingleBlockJob(
      accessIndex, NVM_PARTITION_ID_MASTER);

  /* DO NOT CHANGE: Use copy of port for evaluation due to safety reason */
  NvM_MasterSatellitePort_SingleBlockJobType currentMasterPort = *tempMasterPort;

  /* DO NOT CHANGE: Use copy of port for evaluation due to safety reason */
  NvM_SatellitePort_SingleBlockJobType currentSatPort = NvM_GetSatellitePort_SingleBlockJob(partitionId);

  if (currentSatPort.RequestCounter == currentMasterPort.RequestCounter)
  {
    result = NvM_SatelliteCom_MapMasterSingleBlockJobStatusToServiceJobResult(currentMasterPort.JobStatus);
  }

  return result;
}

/**********************************************************************************************************************
*  NvM_SatelliteCom_FinalizeSingleBlockJob
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, NVM_PRIVATE_CODE) NvM_SatelliteCom_FinalizeSingleBlockJob(const NvM_PartitionIdType partitionId)
{
  /* DO NOT CHANGE: Use address of port for finalization of the job request */
  NvM_SatellitePort_SingleBlockJobPtrType satellitePort = NvM_GetAddrSatellitePort_SingleBlockJob(partitionId);

  /*
   * DO NOT CHANGE: Copy master internal buffer content to internal satellite buffer
   *                in case of read/readall job.
   */
  if ((satellitePort->JobInformation.SingleBlockJobType == NVM_SINGLEBLOCKJOBTYPE_READ_BLOCK)
      || (satellitePort->JobInformation.SingleBlockJobType == NVM_SINGLEBLOCKJOBTYPE_READ_ALL_BLOCK))
  {
    NvM_BlockDescriptorPtrType blockDescriptor =
      NvM_GetAddrBlockDescriptor(satellitePort->JobInformation.BlockDescriptorLookupTableId);
    const uint16 nvDataLength = NvM_GlobalUtilityLib_GetNvDataLength(blockDescriptor);

    NvM_InternalBufferPtrType satelliteBuffer = NvM_GetAddrInternalBuffer(0u, partitionId);

    NvM_InternalMasterBuffersStructIterType accessIndexForInternalMasterBuffer =
      NvM_GlobalUtilityLib_GetAccessIndexForInternalMasterBuffers(partitionId);

    /* CSL can generate data for master only. Nevertheless, the NvM_PCPartitionConfigType struct definition needs an entry
    (filled with NULL_PTR if not available). Therefore the CSL getter remains the same. Hence fix partition to MASTER here. */
    NvM_DataConstPtrToConstType masterBuffer =
      NvM_GetInternalMasterBuffersOfInternalMasterBuffersStruct(accessIndexForInternalMasterBuffer, NVM_PARTITION_ID_MASTER);

    VStdLib_MemCpy(satelliteBuffer, masterBuffer, nvDataLength);                                                        /* VCA_NVM_VStdLibMemCpyCalls */
  }

  satellitePort->JobRequest = NVM_SATELLITE_SINGLEBLOCK_JOB_REQUEST_NONE;
}

/**********************************************************************************************************************
 * NvM_SatelliteCom_GetMultiBlockJobStatus()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(NvM_MasterMultiBlockJobRequestType, NVM_PRIVATE_CODE) NvM_SatelliteCom_GetMultiBlockJobStatus(
  const NvM_PartitionIdType partitionId)
{
  NvM_MasterSatellitePortsStruct_MultiBlockJobIterType accessIndex =
    NvM_GlobalUtilityLib_GetAccessIndexForMasterSatellitePorts_MultiBlockJob(partitionId);

  /* CSL can generate data for master only. Nevertheless, the NvM_PCPartitionConfigType struct definition needs an entry
  (filled with NULL_PTR if not available). Therefore the CSL getter remains the same. Hence fix partition to MASTER here. */
  return NvM_GetMasterSatellitePorts_MultiBlockJobOfMasterSatellitePortsStruct_MultiBlockJob(
          accessIndex, NVM_PARTITION_ID_MASTER)->JobRequest;
}

/**********************************************************************************************************************
 * NvM_SatelliteCom_GetRequestedMultiBlockJob()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(NvM_MultiBlockJobType, NVM_PRIVATE_CODE) NvM_SatelliteCom_GetRequestedMultiBlockJob(
  const NvM_PartitionIdType partitionId)
{
  NvM_MasterSatellitePortsStruct_MultiBlockJobIterType accessIndex =
    NvM_GlobalUtilityLib_GetAccessIndexForMasterSatellitePorts_MultiBlockJob(partitionId);

  /* CSL can generate data for master only. Nevertheless, the NvM_PCPartitionConfigType struct definition needs an entry
  (filled with NULL_PTR if not available). Therefore the CSL getter remains the same. Hence fix partition to MASTER here. */
  return NvM_GetMasterSatellitePorts_MultiBlockJobOfMasterSatellitePortsStruct_MultiBlockJob(
          accessIndex, NVM_PARTITION_ID_MASTER)->JobType;
}

/**********************************************************************************************************************
 * NvM_SatelliteCom_SetMultiBlockJobStatus()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, NVM_PRIVATE_CODE) NvM_SatelliteCom_SetMultiBlockJobStatus(
  const NvM_SatelliteMultiBlockJobStatusType status,
  const NvM_PartitionIdType partitionId)
{
  NvM_SatellitePort_MultiBlockJobPtrType satPort = NvM_GetAddrSatellitePort_MultiBlockJob(partitionId);
  satPort->JobStatus = status;
}


/**********************************************************************************************************************
 * NvM_SatelliteCom_IncrementDemErrorCount()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
void NvM_SatelliteCom_IncrementDemErrorCount(const NvM_DemErrorIdType error, const NvM_PartitionIdType partitionId)
{
#if (NVM_DEM_ERROR_REPORT == STD_ON)
  NvM_ErrorCountersPortConstPtrType satellitePort = NvM_GetAddrSatellitePort_ErrorCounters(partitionId);

  switch(error)
  {
    case NVM_DEM_ERROR_TYPE_INTEGRITY_FAILED:
      satellitePort->DataIntegrityFailedError++;
      break;
    case NVM_DEM_ERROR_TYPE_REQ_FAILED:
      satellitePort->ReqFailedError++;
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
#else
  NVM_DUMMY_STATEMENT_CONST(error);                                                                                     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  NVM_DUMMY_STATEMENT_CONST(partitionId);                                                                               /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif /* NVM_DEM_ERROR_REPORT */
}

#if (NVM_JOB_PRIORITIZATION == STD_ON)

/**********************************************************************************************************************
*  NvM_SatelliteCom_PropagateImmediateBlockJob
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, NVM_PRIVATE_CODE) NvM_SatelliteCom_PropagateImmediateBlockJob(const NvM_PartitionIdType partitionId)
{
  NvM_SatellitePort_SingleBlockJobPtrType satellitePort = NvM_GetAddrSatellitePort_SingleBlockJob(partitionId);

  /* By incrementing the request counter it also shows that this request is new and not yet acknowledged.
   This way NvM_SatelliteCom_GetSingleBlockJobStatus will also return that the request is still pending and should
   not be finalized */
  satellitePort->RequestCounter++;
  satellitePort->JobRequest = NVM_SATELLITE_SINGLEBLOCK_JOB_REQUEST_CANCEL_IMMEDIATE;
}

#endif /* (NVM_JOB_PRIORITIZATION == STD_ON) */

#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* NVM_MULTIPARTITION_USAGE_SCENARIO */

/**********************************************************************************************************************
 *  END OF FILE: NvM_SatelliteCom.c
 *********************************************************************************************************************/
