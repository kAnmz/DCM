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
/*!        \file  NvM_GlobalUtilityLib.c
 *        \brief  NvM_GlobalUtilityLib source file
 *      \details  Implementation of the global utility library unit of the NvM.
 *         \unit  NvM_GlobalUtilityLib
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#define NVM_GLOBALUTILITYLIB_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "NvM_GlobalUtilityLib.h"
/* #include "SchM_NvM.h" */
#include "NvM_Cfg.h"
#include "NvM_CfgDefines.h"

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

/*
 * Macro for Bit Selection
 */

/*! Supports bitfield with up to 16 bits */
#define NVM_SELECT_BIT(x) (((uint16)(1u)) << ((uint16)(x)))

/*! Macro to mask out the DCM_BLOCK info bit (block aliasing) to obtain original BlockId */
#define NVM_BLOCK_FROM_DCM_ID(blockId)   ((NvM_BlockIdType)((blockId) & ((NVM_DCM_BLOCK_OFFSET) ^ 0xFFFFu)))            /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/*! Macro to check if block is DCM block */
#define NVM_BLOCK_IS_DCM_BLOCK(blockId)  ((blockId & NVM_DCM_BLOCK_OFFSET) == NVM_DCM_BLOCK_OFFSET)                     /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

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
 * NvM_GlobalUtilityLib_GetDataIntegrityRecordSize()
 *********************************************************************************************************************/
/*! \brief           Return the size of DataIntegrityRecord configured for the given BlockDescriptor
 *  \details         -
 *  \param[in]       dataIntegritySetting    Data Integrity Setting of the block
 *  \param[in]       macLength               The length of the MAC, only relevant if the data integrity setting is MAC
 *  \pre             -
 *  \context         TASK
 *  \reentrant       FALSE
 *  \synchronous     TRUE
 *  \return          Size of the DataIntegrityRecord, Zero if no strategy configured
 *********************************************************************************************************************/
NVM_LOCAL_INLINE FUNC(uint16, NVM_PRIVATE_CODE) NvM_GlobalUtilityLib_GetDataIntegrityRecordSize(
  const NvM_DataIntegrityType dataIntegritySetting, const uint16 macLength);

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
#define NVM_START_SEC_CODE
#include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * NvM_GlobalUtilityLib_GetDataIntegrityRecordSize()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
NVM_LOCAL_INLINE FUNC(uint16, NVM_PRIVATE_CODE) NvM_GlobalUtilityLib_GetDataIntegrityRecordSize(
  const NvM_DataIntegrityType dataIntegritySetting, const uint16 macLength)
{
  uint16 dataIntegrityRecordSize = 0;

  switch(dataIntegritySetting)
  {
    case NVM_BLOCK_DATA_INTEGRITY_CRC_16:
      dataIntegrityRecordSize = NVM_DATAINTEGRITYRECORD_SIZE_CRC16;
      break;
    case NVM_BLOCK_DATA_INTEGRITY_CRC_32:
      dataIntegrityRecordSize = NVM_DATAINTEGRITYRECORD_SIZE_CRC32;
      break;
    case NVM_BLOCK_DATA_INTEGRITY_MAC:
      dataIntegrityRecordSize = macLength;
      break;

    /* No strategy configured */
    default:
      dataIntegrityRecordSize = 0;
      break;
  }

  return dataIntegrityRecordSize;
}

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
*  NvM_GlobalUtilityLib_ConvertMemIfResultToServiceJobResult
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(NvM_ServiceJobResultType, NVM_PRIVATE_CODE) NvM_GlobalUtilityLib_ConvertMemIfResultToServiceJobResult(
  const MemIf_JobResultType memIfJobResult)
{
  NvM_ServiceJobResultType result = NVM_SERVICE_JOB_NOT_OK;

  switch(memIfJobResult)
  {
    case MEMIF_JOB_OK:
      result = NVM_SERVICE_JOB_OK;
      break;

    /* MEMIF_BLOCK_INVALID and MEMIF_BLOCK_INCONSISTENT same processing for Config Block */
    case MEMIF_BLOCK_INVALID:
    case MEMIF_BLOCK_INCONSISTENT:
      result = NVM_SERVICE_JOB_INVALIDATED;
      break;

    default:
      result = NVM_SERVICE_JOB_NOT_OK;
      break;
  }

  return result;
}

/***********************************************************************************************************************
 * NvM_GlobalUtilityLib_ConvertServiceJobResultToNvMRequestResult()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(NvM_RequestResultType, NVM_PRIVATE_CODE) NvM_GlobalUtilityLib_ConvertServiceJobResultToNvMRequestResult(
  const NvM_ServiceJobResultType serviceJobResult)
{
  NvM_RequestResultType requestResult = NVM_REQ_NOT_OK;

  /* NOTE: PENDING should be an unreachable statement and would indicate an implementation error on lower level.
           In order to not block the SWC all other results will be mapped as an error to at least have a
           sensible end state. */
  switch(serviceJobResult)
  {
    case NVM_SERVICE_JOB_OK:
      requestResult = NVM_REQ_OK;
      break;

    case NVM_SERVICE_JOB_RESTORED_DEFAULTS:
      requestResult = NVM_REQ_RESTORED_DEFAULTS;
      break;

    case NVM_SERVICE_JOB_CANCELED:
      requestResult = NVM_REQ_CANCELED;
      break;

    default:
      requestResult = NVM_REQ_NOT_OK;
      break;
  }
  return requestResult;
}

/**********************************************************************************************************************
 * NvM_GlobalUtilityLib_ConvertServiceJobResultToSatelliteMultiBlockJobStatus()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(NvM_SatelliteMultiBlockJobStatusType, NVM_PRIVATE_CODE)
NvM_GlobalUtilityLib_ConvertServiceJobResultToSatelliteMultiBlockJobStatus(
  const NvM_ServiceJobResultType serviceJobResult)
{
  NvM_SatelliteMultiBlockJobStatusType result = NVM_SATELLITE_MULTIBLOCK_JOB_STATUS_NOT_OK;

  /* NOTE: PENDING should be an unreachable statement and would indicate an implementation error on lower level.
           In order to not block the SWC all other results will be mapped as an error to at least have a
           sensible end state. */
  switch(serviceJobResult)
  {
    case NVM_SERVICE_JOB_OK:
      result = NVM_SATELLITE_MULTIBLOCK_JOB_STATUS_OK;
      break;

    default:
      result = NVM_SATELLITE_MULTIBLOCK_JOB_STATUS_NOT_OK;
      break;
  }
  return result;
}

/***********************************************************************************************************************
 * NvM_GlobalUtilityLib_IsFlagSet()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(boolean, NVM_PRIVATE_CODE) NvM_GlobalUtilityLib_IsFlagSet(const uint16 bitmask, const uint8 flagPosition)
{
  return ((bitmask & NVM_SELECT_BIT(flagPosition)) == NVM_SELECT_BIT(flagPosition));
}

/***********************************************************************************************************************
 * NvM_GlobalUtilityLib_SetFlag()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(uint16, NVM_PRIVATE_CODE) NvM_GlobalUtilityLib_SetFlag(const uint16 bitmask, const uint8 flagPosition)
{
  return (bitmask | NVM_SELECT_BIT(flagPosition));
}

/**********************************************************************************************************************
 *  NvM_GlobalUtilityLib_IsAnyMultiBlockJobRequested
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(boolean, NVM_PRIVATE_CODE) NvM_GlobalUtilityLib_IsAnyMultiBlockJobRequested(
  const NvM_MultiBlockJobFlagType multiBlockJobStatusFlag)
{
  return (NvM_GlobalUtilityLib_IsFlagSet(multiBlockJobStatusFlag, NVM_MULTIBLOCK_FLAG_READALL_REQUESTED) ||
      NvM_GlobalUtilityLib_IsFlagSet(multiBlockJobStatusFlag, NVM_MULTIBLOCK_FLAG_WRITEALL_REQUESTED)) ||
      NvM_GlobalUtilityLib_IsFlagSet(multiBlockJobStatusFlag, NVM_MULTIBLOCK_FLAG_VALIDATEALL_REQUESTED);
}

/**********************************************************************************************************************
*  NvM_GlobalUtilityLib_EnterCriticalSection
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, NVM_PRIVATE_CODE) NvM_GlobalUtilityLib_EnterCriticalSection(void)
{
  /* SchM_Enter_NvM_NVM_EXCLUSIVE_AREA_0(); */
}

/**********************************************************************************************************************
*  NvM_GlobalUtilityLib_ExitCriticalSection
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, NVM_PRIVATE_CODE) NvM_GlobalUtilityLib_ExitCriticalSection(void)
{
  /* SchM_Exit_NvM_NVM_EXCLUSIVE_AREA_0(); */
}

#if (NVM_MULTIPARTITION_USAGE_SCENARIO == STD_ON)
/**********************************************************************************************************************
 * NvM_GlobalUtilityLib_GetPartitionId
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
 */
FUNC(Std_ReturnType, NVM_PRIVATE_CODE) NvM_GlobalUtilityLib_GetPartitionId(
  NvM_PartitionIdType* partitionId,
  ApplicationType applicationId)
{
  Std_ReturnType retVal = E_NOT_OK;
  NvM_SizeOfPartitionIdentifiersType sizeOfPartitionIdentifiers = NvM_GetSizeOfPartitionIdentifiers();

  for (NvM_PartitionIdentifiersIterType i = 0; i < sizeOfPartitionIdentifiers; i++)                                     /* FETA_NVM_CSL_SizeOfIterableGenDataObject */
  {
    ApplicationType cslIdentifier = (ApplicationType)NvM_GetPartitionSNVOfPartitionIdentifiers(i);
    if (applicationId == cslIdentifier)
    {
      /* Transition point from CSL's partition identifier type to NvM's internal NvM_PartitionIdType.
         This is necessary to ensure that NvM's internal partition ID representation is consistent. */
      *partitionId = (NvM_PartitionIdType)NvM_GetPCPartitionConfigIdxOfPartitionIdentifiers(i);
      retVal = E_OK;
      break;
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 * NvM_GlobalUtilityLib_FindOsApplicationId
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
 */
FUNC(Std_ReturnType, NVM_PRIVATE_CODE) NvM_GlobalUtilityLib_FindOsApplicationId(
  ApplicationType* foundApplicationIdPtr,
  const NvM_PartitionIdType partitionId)
{
  Std_ReturnType retVal = E_NOT_OK;
  const NvM_SizeOfPartitionIdentifiersType sizeOfPartitionIdentifiers = NvM_GetSizeOfPartitionIdentifiers();

  for (NvM_PartitionIdentifiersIterType i = 0u; i < sizeOfPartitionIdentifiers; i++)                                     /* FETA_NVM_CSL_SizeOfIterableGenDataObject */
  {
    const NvM_PartitionIdType tempPartitionId = (NvM_PartitionIdType)NvM_GetPCPartitionConfigIdxOfPartitionIdentifiers(i);

    if (partitionId == tempPartitionId)
    {
      *foundApplicationIdPtr = (ApplicationType)NvM_GetPartitionSNVOfPartitionIdentifiers(i);
      retVal = E_OK;
      break;
    }
  }

  return retVal;
}
#endif /* (NVM_MULTIPARTITION_USAGE_SCENARIO == STD_ON) */

/**********************************************************************************************************************
 * NvM_GlobalUtilityLib_CopyDataIntegrityRecord()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, NVM_PRIVATE_CODE) NvM_GlobalUtilityLib_CopyDataIntegrityRecord(
  const NvM_DataIntegrityType dataIntegritySetting,
  NvM_DataPtrType targetBuffer,
  NvM_DataConstPtrToConstType srcBuffer)
{
  switch(dataIntegritySetting)
  {
    case NVM_BLOCK_DATA_INTEGRITY_CRC_16:
#if !defined(__VCA__) /* COV_NVM_VCA */
/* VCA Disable SLC-10, SLC-22 : VCA_NVM_DataIntegrityRecordBuffer */
      targetBuffer[0] = srcBuffer[0];
      targetBuffer[1] = srcBuffer[1];
/* VCA Enable : VCA_NVM_DataIntegrityRecordBuffer */
#endif
      break;
    case NVM_BLOCK_DATA_INTEGRITY_CRC_32:
#if !defined(__VCA__) /* COV_NVM_VCA */
/* VCA Disable SLC-10, SLC-22 : VCA_NVM_DataIntegrityRecordBuffer */
      targetBuffer[0] = srcBuffer[0];
      targetBuffer[1] = srcBuffer[1];
      targetBuffer[2] = srcBuffer[2];
      targetBuffer[3] = srcBuffer[3];
/* VCA Enable : VCA_NVM_DataIntegrityRecordBuffer */
#endif
      break;

      /* For MAC this is not needed for now as this copy is used for the SkipRead feature 
      but MAC is not yet supported for this feature. Stored in: MEMMAN-12960 */

    /* No strategy configured */
    default:
      NVM_DUMMY_STATEMENT_CONST(dataIntegritySetting);
      break;
  }
}

/**********************************************************************************************************************
 * NvM_GlobalUtilityLib_CompareDataIntegrityRecords()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(boolean, NVM_PRIVATE_CODE) NvM_GlobalUtilityLib_CompareDataIntegrityRecords(
  const NvM_DataIntegrityType dataIntegritySetting,
  NvM_DataConstPtrToConstType buffer1,
  NvM_DataConstPtrToConstType buffer2)
{
  boolean buffersEqual = FALSE;

  switch(dataIntegritySetting)
  {
    case NVM_BLOCK_DATA_INTEGRITY_CRC_16:
#if !defined(__VCA__) /* COV_NVM_VCA */
/* VCA Disable SLC-10, SLC-22 : VCA_NVM_DataIntegrityRecordBuffer */
      buffersEqual = (buffer1[0] == buffer2[0]) &&
          (buffer1[1] == buffer2[1]);
/* VCA Enable : VCA_NVM_DataIntegrityRecordBuffer */
#endif
      break;
    case NVM_BLOCK_DATA_INTEGRITY_CRC_32:
#if !defined(__VCA__) /* COV_NVM_VCA */
/* VCA Disable SLC-10, SLC-22 : VCA_NVM_DataIntegrityRecordBuffer */
      buffersEqual = (buffer1[0] == buffer2[0]) &&
          (buffer1[1] == buffer2[1]) &&
          (buffer1[2] == buffer2[2]) &&
          (buffer1[3] == buffer2[3]);
/* VCA Enable : VCA_NVM_DataIntegrityRecordBuffer */
#endif
      break;

    /* No strategy configured, always return FALSE */
    default:
      NVM_DUMMY_STATEMENT_CONST(dataIntegritySetting);
      break;
  }

  return buffersEqual;
}

/**********************************************************************************************************************
 * NvM_GlobalUtilityLib_ResetCrcCompMechanismBuffer()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, NVM_PRIVATE_CODE) NvM_GlobalUtilityLib_ResetCrcCompMechanismBuffer(
  const NvM_DataPtrType crcCompMechanismBuffer,
  const NvM_DataIntegrityType dataIntegritySetting)
{
  if(crcCompMechanismBuffer != NULL_PTR)
  {
    NvM_DataType crcResetValue[4]; 
    crcResetValue[0] = (NvM_DataType)NVM_CRCCOMPBUFFER_RESET_VALUE;
    crcResetValue[1] = (NvM_DataType)NVM_CRCCOMPBUFFER_RESET_VALUE;
    crcResetValue[2] = (NvM_DataType)NVM_CRCCOMPBUFFER_RESET_VALUE;
    crcResetValue[3] = (NvM_DataType)NVM_CRCCOMPBUFFER_RESET_VALUE;

    /* Update CrcCompMechanismBuffer with Reset value */
    NvM_GlobalUtilityLib_CopyDataIntegrityRecord(dataIntegritySetting, 
      crcCompMechanismBuffer, 
      crcResetValue);
  }
}

/**********************************************************************************************************************
 * NvM_GlobalUtilityLib_GetNvDataLength()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(uint16, NVM_PRIVATE_CODE) NvM_GlobalUtilityLib_GetNvDataLength(const NvM_BlockDescriptorPtrType descPtr)
{
  const uint16 dataIntegrityRecordSize = NvM_GlobalUtilityLib_GetDataIntegrityRecordSize(descPtr->DataIntegritySettings, 
    descPtr->MacLength);

  return descPtr->NvBlockLength + dataIntegrityRecordSize;
}

/**********************************************************************************************************************
 * NvM_GlobalUtilityLib_FindBlockDescriptorLookupTableId()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(boolean, NVM_PRIVATE_CODE) NvM_GlobalUtilityLib_FindBlockDescriptorLookupTableId(
  const NvM_BlockIdType externalBlockId,
  NvM_BlockDescriptorLookupTableIdType* outBlockDescriptorLookupTableIdPtr)
{
  boolean isInternalBlockValid = FALSE;

  NvM_BlockIdType blockId = NVM_BLOCK_FROM_DCM_ID(externalBlockId);

  for (NvM_BlockDescriptorIterType index = 0u; index < NvM_GetSizeOfBlockDescriptor(); index++)
  {
    NvM_BlockDescriptorPtrType blockDescriptor = NvM_GetAddrBlockDescriptor(index);
    if (blockDescriptor->NvramBlockIdentifier == blockId)
    {
      *outBlockDescriptorLookupTableIdPtr = (NvM_BlockDescriptorLookupTableIdType)index;
      isInternalBlockValid = TRUE;
      break;
    }
  }

  return isInternalBlockValid;
}

/**********************************************************************************************************************
 * NvM_GlobalUtilityLib_GetBlockManagementInfo
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(NvM_BlockManagementInformationPtrType, NVM_PRIVATE_CODE) NvM_GlobalUtilityLib_GetBlockManagementInfo(
  const NvM_BlockIdType externalBlockId,
  const NvM_BlockDescriptorLookupTableIdType blockDescriptorLookupTableId,
  const NvM_PartitionIdType partitionId)                                                                                /* PRQA S 3206 */ /* MD_NvM_CslMacroNotUsingPartitionId */
{
  NvM_BlockManagementInformationPtrType blockManagementInfo = NULL_PTR;

  if (NVM_BLOCK_IS_DCM_BLOCK(externalBlockId))
  {
    blockManagementInfo = (NvM_BlockManagementInformationPtrType)NvM_GetAddrDcmBlockManagementInfo(partitionId);
  }
  else
  {
    /*
     * The parameter partitionId is not used within this function when block is not a DCM block.
     * To avoid compiler warnings the following dummy statement is added.
     */
    NVM_DUMMY_STATEMENT_CONST(partitionId);                                                                             /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

    blockManagementInfo = NvM_GetAddrBlockDescriptor(blockDescriptorLookupTableId)->BlockManagementInfo;
  }

  return blockManagementInfo;
}

#if (NVM_MULTIPARTITION_USAGE_SCENARIO == STD_ON)
/**********************************************************************************************************************
 * NvM_GlobalUtilityLib_GetAccessIndexForInternalMasterBuffers
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(NvM_InternalMasterBuffersStructIterType, NVM_PRIVATE_CODE)NvM_GlobalUtilityLib_GetAccessIndexForInternalMasterBuffers(
  const NvM_PartitionIdentifiersIterType expectedPartitionId)
{
  /*
   * The access index is initialized to a default value.
   * This value is never reached because the provided partition ID is always valid because:
   *  - The PartitionIdentifiers table is generated by the CSL
   *    and the partition ID is fetched using the NvM_GetSizeOfPartitionIdentifiers() macro
   *  - A partition ID mismatch is always detected by the method NvM_GlobalUtilityLib_GetPartitionId()
   * In addition the internal master buffers table is assumed to be correctly generated and hence a partition ID
   * mismatch is excluded. This is also enforced by the MSSV check CheckMasterSatelliteDataForConsistentPartitionIdentifiers.
  */
  NvM_InternalMasterBuffersStructIterType accessIndex = 0u;

  NvM_SizeOfInternalMasterBuffersStructType sizeOfInternalMasterBuffersStruct =
    NvM_GetSizeOfInternalMasterBuffersStruct(NVM_PARTITION_ID_MASTER);

  for (NvM_InternalMasterBuffersStructIterType currentIndex = 0;                                                        /* FETA_NVM_CSL_SizeOfIterableGenDataObject */
    currentIndex < sizeOfInternalMasterBuffersStruct; currentIndex++)
  {
    if (NvM_GetPartitionConfigIdxOfInternalMasterBuffersStruct(currentIndex, NVM_PARTITION_ID_MASTER) == expectedPartitionId)
    {
      accessIndex = currentIndex;
      break;
    }
  }
  return accessIndex;
}

/**********************************************************************************************************************
 * NvM_GlobalUtilityLib_GetAccessIndexForMasterSatellitePorts_SingleBlockJob
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(NvM_MasterSatellitePortsStruct_SingleBlockJobIterType, NVM_PRIVATE_CODE)
  NvM_GlobalUtilityLib_GetAccessIndexForMasterSatellitePorts_SingleBlockJob(
    const NvM_PartitionIdentifiersIterType expectedPartitionId)
{
  /*
   * The access index is initialized to a default value.
   * This value is never reached because the provided partition ID is always valid because:
   *  - The PartitionIdentifiers table is generated by the CSL
   *    and the partition ID is fetched using the NvM_GetSizeOfPartitionIdentifiers() macro
   *  - A partition ID mismatch is always detected by the method NvM_GlobalUtilityLib_GetPartitionId()
   * In addition the internal master satellite single block job ports table is assumed
   * to be correctly generated and hence a partition ID mismatch is excluded.
   * This is also enforced by the MSSV check CheckMasterSatelliteDataForConsistentPartitionIdentifiers.
  */
  NvM_MasterSatellitePortsStruct_SingleBlockJobIterType accessIndex = 0u;

  NvM_SizeOfMasterSatellitePortsStruct_SingleBlockJobType sizeOfMasterSatellitePortsStruct =
    NvM_GetSizeOfMasterSatellitePortsStruct_SingleBlockJob(NVM_PARTITION_ID_MASTER);

  for (NvM_MasterSatellitePortsStruct_SingleBlockJobIterType currentIndex = 0;                                          /* FETA_NVM_CSL_SizeOfIterableGenDataObject */
    currentIndex < sizeOfMasterSatellitePortsStruct; currentIndex++)
  {
    if (NvM_GetPartitionConfigIdxOfMasterSatellitePortsStruct_SingleBlockJob(currentIndex, NVM_PARTITION_ID_MASTER)
        == expectedPartitionId)
    {
      accessIndex = currentIndex;
      break;
    }
  }
  return accessIndex;
}

/**********************************************************************************************************************
 * NvM_GlobalUtilityLib_GetAccessIndexForMasterSatellitePorts_MultiBlockJob
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(NvM_MasterSatellitePortsStruct_MultiBlockJobIterType, NVM_PRIVATE_CODE)
  NvM_GlobalUtilityLib_GetAccessIndexForMasterSatellitePorts_MultiBlockJob(
    const NvM_PartitionIdentifiersIterType expectedPartitionId)
{
  /*
   * The access index is initialized to a default value.
   * This value is never reached because the provided partition ID is always valid because:
   *  - The PartitionIdentifiers table is generated by the CSL
   *    and the partition ID is fetched using the NvM_GetSizeOfPartitionIdentifiers() macro
   *  - A partition ID mismatch is always detected by the method NvM_GlobalUtilityLib_GetPartitionId()
   * In addition the internal master satellite multi block job ports table is assumed
   * to be correctly generated and hence a partition ID mismatch is excluded.
   * This is also enforced by the MSSV check CheckMasterSatelliteDataForConsistentPartitionIdentifiers.
  */
  NvM_MasterSatellitePortsStruct_MultiBlockJobIterType accessIndex = 0u;

  NvM_SizeOfMasterSatellitePortsStruct_MultiBlockJobType sizeOfMasterSatellitePortsStruct =
    NvM_GetSizeOfMasterSatellitePortsStruct_MultiBlockJob(NVM_PARTITION_ID_MASTER);

  for (NvM_MasterSatellitePortsStruct_MultiBlockJobIterType currentIndex = 0;                                           /* FETA_NVM_CSL_SizeOfIterableGenDataObject */
    currentIndex < sizeOfMasterSatellitePortsStruct; currentIndex++)
  {
    if (NvM_GetPartitionConfigIdxOfMasterSatellitePortsStruct_MultiBlockJob(currentIndex, NVM_PARTITION_ID_MASTER)
        == expectedPartitionId)
    {
      accessIndex = currentIndex;
      break;
    }
  }
  return accessIndex;
}

#if (NVM_DEM_ERROR_REPORT == STD_ON)
/**********************************************************************************************************************
 * NvM_GlobalUtilityLib_GetAccessIndexForMasterSatellitePorts_ErrorCountersMirror
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(NvM_MasterSatellitePortsStruct_ErrorCountersMirrorIterType, NVM_PRIVATE_CODE)
  NvM_GlobalUtilityLib_GetAccessIndexForMasterSatellitePorts_ErrorCountersMirror(const NvM_PartitionIdentifiersIterType expectedPartitionId)
{
  /*
   * The access index is initialized to a default value.
   * This value is never reached because the provided partition ID is always valid because:
   *  - The PartitionIdentifiers table is generated by the CSL
   *    and the partition ID is fetched using the NvM_GetSizeOfPartitionIdentifiers() macro
   *  - A partition ID mismatch is always detected by the method NvM_GlobalUtilityLib_GetPartitionId()
   * In addition the internal master satellite error counters mirror ports table is assumed
   * to be correctly generated and hence a partition ID mismatch is excluded.
   * This is also enforced by the MSSV check CheckMasterSatelliteDataForConsistentPartitionIdentifiers.
  */
  NvM_MasterSatellitePortsStruct_MultiBlockJobIterType accessIndex = 0u;

  NvM_SizeOfMasterSatellitePortsStruct_ErrorCountersMirrorType sizeOfMasterSatellitePortsStruct =
    NvM_GetSizeOfMasterSatellitePortsStruct_ErrorCountersMirror(NVM_PARTITION_ID_MASTER);

  for (NvM_MasterSatellitePortsStruct_ErrorCountersMirrorIterType currentIndex = 0;                                     /* FETA_NVM_CSL_SizeOfIterableGenDataObject */
    currentIndex < sizeOfMasterSatellitePortsStruct; currentIndex++)
  {
    if (NvM_GetPartitionConfigIdxOfMasterSatellitePortsStruct_ErrorCountersMirror(currentIndex, NVM_PARTITION_ID_MASTER)
      == expectedPartitionId)
    {
      accessIndex = currentIndex;
      break;
    }
  }
  return accessIndex;
}
#endif  /* (NVM_DEM_ERROR_REPORT == STD_ON) */
#endif  /* (NVM_MULTIPARTITION_USAGE_SCENARIO == STD_ON) */

#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: NvM_GlobalUtilityLib.c
 *********************************************************************************************************************/
