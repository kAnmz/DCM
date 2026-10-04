/**********************************************************************************************************************
 *  COPYRIGHT
 *  --------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2026 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  --------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/*!        \file  MemAcc.c
 *        \brief  MemAcc source file
 *      \details  The Memory Access module provides access to different memory devices by an address-based API.
 *         \unit  General
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#define MEMACC_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "MemAcc.h"
#include "MemAcc_InternalTypes.h"
// #include "SchM_MemAcc.h"
#include "MemAcc_MainFsm.h"
#include "MemAcc_Queue.h"
#include "MemAcc_ErrorCheck.h"
#include "MemAcc_Utils.h"
#include "MemAcc_BBM.h"
#include "MemAcc_MemAb.h"
#include "MemAcc_MemAccessControl.h"

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/
/* Check the version of the configuration header file to ensure that the generated files match the static files. */
#if (  (MEMACC_CFG_MAJOR_VERSION != (3u)) \
    || (MEMACC_CFG_MINOR_VERSION != (5u)) )
# error "Version numbers of MemAcc.c and MemAcc_Cfg.h are inconsistent!"
#endif
/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/
#if !defined (MEMACC_LOCAL)
# define MEMACC_LOCAL static
#endif

#if !defined (MEMACC_LOCAL_INLINE)
# define MEMACC_LOCAL_INLINE LOCAL_INLINE
#endif

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/
#define MEMACC_START_SEC_VAR_CLEARED
#include "MemAcc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Initialization state of the module */
/* PRQA S 3408 1 */ /* MD_MemAcc_LocalVariableExternalLinkage */
MEMACC_LOCAL uint8 MemAcc_ModuleInitialized = MEMACC_UNINIT;

#define MEMACC_STOP_SEC_VAR_CLEARED
#include "MemAcc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define MEMACC_START_SEC_CODE
#include "MemAcc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * MemAcc_MemAccMemJobResultMapping
 *********************************************************************************************************************/
/*! \brief         Maps the MemAcc JobResult to a MemAcc Mem JobResult
 *  \details       -
 *  \param[in]     JobStep Pointer to a JobStep containing the Result and the Status
 *  \return        MemAcc_MemJobResultType
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
MEMACC_LOCAL MemAcc_MemJobResultType MemAcc_MemAccMemJobResultMapping(
const MemAcc_JobStepType* JobStep);

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  MemAcc_MemAccMemJobResultMapping
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
MEMACC_LOCAL MemAcc_MemJobResultType MemAcc_MemAccMemJobResultMapping(
const MemAcc_JobStepType* JobStep)
{
  MemAcc_MemJobResultType retValue = MEM_JOB_PENDING;

  if (JobStep->Status == MEMACC_JOB_IDLE)
  {
    switch (JobStep->Result)
    {
    case MEMACC_OK:
      retValue = MEM_JOB_OK;
      break;
    case MEMACC_INCONSISTENT:
      retValue = MEM_INCONSISTENT;
      break;
    case MEMACC_ECC_UNCORRECTED:
      retValue = MEM_ECC_UNCORRECTED;
      break;
    case MEMACC_ECC_CORRECTED:
      retValue = MEM_ECC_CORRECTED;
      break;
    case MEMACC_FAILED:
    case MEMACC_CANCELED:
    default: /* COV_MemAcc_MemAb_MISRA */
      retValue = MEM_JOB_FAILED;
      break;
    }
  }

  return retValue;
}

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  MemAcc_InitMemory
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *

 */
void MemAcc_InitMemory(void)
{
  MemAcc_ModuleInitialized = MEMACC_UNINIT;
} /* MemAcc_InitMemory() */

/**********************************************************************************************************************
 *  MemAcc_Init
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
void MemAcc_Init(const MemAcc_ConfigType* configPtr)
{
  MEMACC_DUMMY_STATEMENT(configPtr);

  MemAcc_Queue_Reset();

  MemAcc_MainFsm_Reset();

#if (MEMACC_BBM_ENABLED == STD_ON)
  MemAcc_BBM_Reset();
#endif /* (MEMACC_BBM_ENABLED == STD_ON) */

  MemAcc_MemAccessControl_Reset();

  MemAcc_MemAb_Init();

  MemAcc_ModuleInitialized = MEMACC_INIT;
} /* MemAcc_Init() */

/**********************************************************************************************************************
 *  MemAcc_DeInit
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
void MemAcc_DeInit(void)
{
  MemAcc_ModuleInitialized = MEMACC_UNINIT;

  MemAcc_Queue_Reset();

  MemAcc_MainFsm_Reset();

#if (MEMACC_BBM_ENABLED == STD_ON)
  MemAcc_BBM_Reset();
#endif /* (MEMACC_BBM_ENABLED == STD_ON) */

  MemAcc_MemAb_DeInit();

  /* Need to be after MemAb to ensure Activated Mems are de-initialized. */
  MemAcc_MemAccessControl_Reset();
} /* MemAcc_DeInit() */

/**********************************************************************************************************************
 *   MemAcc_Cancel()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
void MemAcc_Cancel(MemAcc_AddressAreaIdType addressAreaId)
{
  MemAcc_AddressAreaIndexType aaIdx = MemAcc_Utils_GetIndexOfAddrAreaId(addressAreaId);

  if(MemAcc_ErrorCheck_IsSynchServiceInvocationValid(
    MEMACC_SID_CANCEL,
    MemAcc_ModuleInitialized,
    aaIdx,
    NULL_PTR,
    FALSE))
  {
    /*@ assert aaIdx < MemAcc_GetSizeOfAddressArea(); */ /* VCA_MemAcc_AddressAreaIndexAssertionFail */
    MemAcc_JobContextType* job = MemAcc_Queue_GetJob(aaIdx, FALSE);

    if(job->JobArea.JobType != (MemAcc_AtomicJobType)MEMACC_NO_JOB)
    {
      job->MngmtArea.JobCanceled = TRUE;
    }
  }
} /* MemAcc_Cancel() */

/**********************************************************************************************************************
 *   MemAcc_Read()
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
Std_ReturnType MemAcc_Read(
  MemAcc_AddressAreaIdType addressAreaId,
  MemAcc_AddressType sourceAddress,
  MemAcc_DataType* destinationDataPtr,
  MemAcc_LengthType length)
{
  Std_ReturnType retVal = E_NOT_OK;

  MemAcc_JobAreaType job;
  job.JobType = (MemAcc_AtomicJobType)MEMACC_READ_JOB;
  job.AddressAreaIndex = MemAcc_Utils_GetIndexOfAddrAreaId(addressAreaId);
  job.Address = sourceAddress;
  job.Length = length;
  job.DataBuffer = destinationDataPtr;
  job.ConstDataBuffer = NULL_PTR;
  job.HwId = (MemAcc_HwIdType) 0;    /* PRQA S 4332 */ /* MD_MemAcc_HwIdEnumCasting */
  job.HwServiceId = 0u;
  job.LengthPtr = NULL_PTR;
  job.LockNotificationFctPtr = NULL_PTR;
  job.JobClassification = MEMACC_JOBCLASSIFICATION_USERJOB;

  if(MemAcc_ErrorCheck_IsAsynchServiceInvocationValid(
    MEMACC_SID_READ,
    MemAcc_ModuleInitialized,
    &job))
  {
    /*@ assert job.AddressAreaIndex < MemAcc_GetSizeOfAddressArea(); */ /* VCA_MemAcc_AddressAreaIndexAssertionFail */
    retVal = MemAcc_Queue_PushJob(&job);
  }

  return retVal;
} /* MemAcc_Read() */

/**********************************************************************************************************************
 *  MemAcc_Write()
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
Std_ReturnType MemAcc_Write(
  MemAcc_AddressAreaIdType addressAreaId,
  MemAcc_AddressType targetAddress,
  const MemAcc_DataType* sourceDataPtr,
  MemAcc_LengthType length)
{
  Std_ReturnType retVal = E_NOT_OK;

  MemAcc_JobAreaType job;
  job.JobType = (MemAcc_AtomicJobType)MEMACC_WRITE_JOB;
  job.AddressAreaIndex = MemAcc_Utils_GetIndexOfAddrAreaId(addressAreaId);
  job.Address = targetAddress;
  job.Length = length;
  job.DataBuffer = NULL_PTR;
  job.ConstDataBuffer = sourceDataPtr;
  job.HwId = (MemAcc_HwIdType) 0;    /* PRQA S 4332 */ /* MD_MemAcc_HwIdEnumCasting */
  job.HwServiceId = 0u;
  job.LengthPtr = NULL_PTR;
  job.LockNotificationFctPtr = NULL_PTR;
  job.JobClassification = MEMACC_JOBCLASSIFICATION_USERJOB;

  if(MemAcc_ErrorCheck_IsAsynchServiceInvocationValid(
    MEMACC_SID_WRITE,
    MemAcc_ModuleInitialized,
    &job))
  {
    /*@ assert job.AddressAreaIndex < MemAcc_GetSizeOfAddressArea(); */ /* VCA_MemAcc_AddressAreaIndexAssertionFail */
    retVal = MemAcc_Queue_PushJob(&job);
  }

  return retVal;
}

/**********************************************************************************************************************
 *  MemAcc_Erase()
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
Std_ReturnType MemAcc_Erase(
  MemAcc_AddressAreaIdType addressAreaId,
  MemAcc_AddressType targetAddress,
  MemAcc_LengthType length)
{
  Std_ReturnType retVal = E_NOT_OK;

  MemAcc_JobAreaType job;
  job.JobType = (MemAcc_AtomicJobType)MEMACC_ERASE_JOB;
  job.AddressAreaIndex = MemAcc_Utils_GetIndexOfAddrAreaId(addressAreaId);
  job.Address = targetAddress;
  job.Length = length;
  job.DataBuffer = NULL_PTR;
  job.ConstDataBuffer = NULL_PTR;
  job.HwId = (MemAcc_HwIdType) 0;    /* PRQA S 4332 */ /* MD_MemAcc_HwIdEnumCasting */
  job.HwServiceId = 0u;
  job.LengthPtr = NULL_PTR;
  job.LockNotificationFctPtr = NULL_PTR;
  job.JobClassification = MEMACC_JOBCLASSIFICATION_USERJOB;

  if(MemAcc_ErrorCheck_IsAsynchServiceInvocationValid(
    MEMACC_SID_ERASE,
    MemAcc_ModuleInitialized,
    &job))
  {
    /*@ assert job.AddressAreaIndex < MemAcc_GetSizeOfAddressArea(); */ /* VCA_MemAcc_AddressAreaIndexAssertionFail */
    retVal = MemAcc_Queue_PushJob(&job);
  }

  return retVal;
}

#if (MEMACC_COMPAREAPI_ENABLED == STD_ON)

/**********************************************************************************************************************
 *  MemAcc_Compare()
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
Std_ReturnType MemAcc_Compare(
  MemAcc_AddressAreaIdType addressAreaId,
  MemAcc_AddressType sourceAddress,
  const MemAcc_DataType* dataPtr,
  MemAcc_LengthType length)
{
  Std_ReturnType retVal = E_NOT_OK;

  MemAcc_JobAreaType job;
  job.JobType = (MemAcc_AtomicJobType)MEMACC_COMPARE_JOB;
  job.AddressAreaIndex = MemAcc_Utils_GetIndexOfAddrAreaId(addressAreaId);
  job.Address = sourceAddress;
  job.Length = length;
  job.DataBuffer = MemAcc_CompareBuffer;
  job.ConstDataBuffer = dataPtr;
  job.HwId = (MemAcc_HwIdType) 0;    /* PRQA S 4332 */ /* MD_MemAcc_HwIdEnumCasting */
  job.HwServiceId = 0u;
  job.LengthPtr = NULL_PTR;
  job.LockNotificationFctPtr = NULL_PTR;
  job.JobClassification = MEMACC_JOBCLASSIFICATION_USERJOB;

  if(MemAcc_ErrorCheck_IsAsynchServiceInvocationValid(
    MEMACC_SID_COMPARE,
    MemAcc_ModuleInitialized,
    &job))
  {
    /*@ assert job.AddressAreaIndex < MemAcc_GetSizeOfAddressArea(); */ /* VCA_MemAcc_AddressAreaIndexAssertionFail */
    retVal = MemAcc_Queue_PushJob(&job);
  }

  return retVal;
}

#endif /* MEMACC_COMPAREAPI_ENABLED */

/**********************************************************************************************************************
 *  MemAcc_BlankCheck()
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
Std_ReturnType MemAcc_BlankCheck(
  MemAcc_AddressAreaIdType addressAreaId,
  MemAcc_AddressType targetAddress,
  MemAcc_LengthType length)
{
  Std_ReturnType retVal = E_NOT_OK;

  MemAcc_JobAreaType job;
  job.JobType = (MemAcc_AtomicJobType)MEMACC_BLANKCHECK_JOB;
  job.AddressAreaIndex = MemAcc_Utils_GetIndexOfAddrAreaId(addressAreaId);
  job.Address = targetAddress;
  job.Length = length;
  job.DataBuffer = NULL_PTR;
  job.ConstDataBuffer = NULL_PTR;
  job.HwId = (MemAcc_HwIdType) 0;    /* PRQA S 4332 */ /* MD_MemAcc_HwIdEnumCasting */
  job.HwServiceId = 0u;
  job.LengthPtr = NULL_PTR;
  job.LockNotificationFctPtr = NULL_PTR;
  job.JobClassification = MEMACC_JOBCLASSIFICATION_USERJOB;

  if(MemAcc_ErrorCheck_IsAsynchServiceInvocationValid(
    MEMACC_SID_BLANKCHECK,
    MemAcc_ModuleInitialized,
    &job))
  {
    /*@ assert job.AddressAreaIndex < MemAcc_GetSizeOfAddressArea(); */ /* VCA_MemAcc_AddressAreaIndexAssertionFail */
    retVal = MemAcc_Queue_PushJob(&job);
  }

  return retVal;
}

/**********************************************************************************************************************
 *  MemAcc_HwSpecificService()
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
Std_ReturnType MemAcc_HwSpecificService(
  MemAcc_AddressAreaIdType addressAreaId,
  MemAcc_HwIdType hwId,
  MemAcc_MemHwServiceIdType hwServiceId,
  MemAcc_DataType* dataPtr,
  MemAcc_LengthType* lengthPtr)
{
  Std_ReturnType retVal = E_NOT_OK;

  MemAcc_JobAreaType job;
  job.JobType = (MemAcc_AtomicJobType)MEMACC_MEMHWSPECIFIC_JOB;
  job.AddressAreaIndex = MemAcc_Utils_GetIndexOfAddrAreaId(addressAreaId);
  job.Address = 0u;
  job.Length = 0u;
  job.DataBuffer = dataPtr;
  job.ConstDataBuffer = NULL_PTR;
  job.HwId = hwId;
  job.HwServiceId = hwServiceId;
  job.LengthPtr = lengthPtr;
  job.LockNotificationFctPtr = NULL_PTR;
  job.JobClassification = MEMACC_JOBCLASSIFICATION_USERJOB;

  if(MemAcc_ErrorCheck_IsHwSpecificServiceInvocationValid(
    MEMACC_SID_HWSPECIFICSERVICE,
    MemAcc_ModuleInitialized,
    &job))
  {
    /*@ assert job.AddressAreaIndex < MemAcc_GetSizeOfAddressArea(); */ /* VCA_MemAcc_AddressAreaIndexAssertionFail */
    retVal = MemAcc_Queue_PushJob(&job);
  }

  return retVal;
}

/**********************************************************************************************************************
 * MemAcc_RequestLock
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
Std_ReturnType MemAcc_RequestLock(
  MemAcc_AddressAreaIdType addressAreaId,
  MemAcc_AddressType address,
  MemAcc_LengthType length,
  MemAcc_ApplicationLockNotificationType lockNotificationFctPtr)
{
  Std_ReturnType retVal = E_NOT_OK;
  MemAcc_AddressAreaIndexType aaIdx = MemAcc_Utils_GetIndexOfAddrAreaId(addressAreaId);

  if(MemAcc_ErrorCheck_IsLockInvocationValid(
    MEMACC_SID_REQUESTLOCK,
    MemAcc_ModuleInitialized,
    aaIdx,
    address,
    length,
    lockNotificationFctPtr,
    TRUE))
  {
    /*@ assert aaIdx < MemAcc_GetSizeOfAddressArea(); */ /* VCA_MemAcc_AddressAreaIndexAssertionFail */
    retVal = MemAcc_Queue_RequestLock(aaIdx, address, length, lockNotificationFctPtr);
  }

  return retVal;
}

/**********************************************************************************************************************
 * MemAcc_ReleaseLock()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
Std_ReturnType MemAcc_ReleaseLock(
  MemAcc_AddressAreaIdType addressAreaId,
  MemAcc_AddressType address,
  MemAcc_LengthType length)
{
  Std_ReturnType retVal = E_NOT_OK;
  MemAcc_AddressAreaIndexType aaIdx = MemAcc_Utils_GetIndexOfAddrAreaId(addressAreaId);

  if(MemAcc_ErrorCheck_IsLockInvocationValid(
    MEMACC_SID_RELEASELOCK,
    MemAcc_ModuleInitialized,
    aaIdx,
    address,
    length,
    NULL_PTR,
    FALSE))
  {
    MemAcc_Queue_ReleaseLock(aaIdx, address, length);
    retVal = E_OK;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  MemAcc_GetVersionInfo()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
void MemAcc_GetVersionInfo(Std_VersionInfoType* versionInfoPtr)
{
  if(MemAcc_ErrorCheck_IsGetVersionInfoInvocationValid(
    MEMACC_SID_GETVERSIONINFO,
    versionInfoPtr))
  {
    versionInfoPtr->vendorID = MEMACC_VENDOR_ID;
    versionInfoPtr->moduleID = MEMACC_MODULE_ID;
    versionInfoPtr->sw_major_version = MEMACC_SW_MAJOR_VERSION;
    versionInfoPtr->sw_minor_version = MEMACC_SW_MINOR_VERSION;
    versionInfoPtr->sw_patch_version = MEMACC_SW_PATCH_VERSION;
  }
}

/**********************************************************************************************************************
 *  MemAcc_GetJobResult()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
MemAcc_JobResultType MemAcc_GetJobResult(MemAcc_AddressAreaIdType addressAreaId)
{
  MemAcc_JobResultType retVal = MEMACC_FAILED;
  MemAcc_AddressAreaIndexType aaIdx = MemAcc_Utils_GetIndexOfAddrAreaId(addressAreaId);

  if(MemAcc_ErrorCheck_IsSynchServiceInvocationValid(
    MEMACC_SID_GETJOBRESULT,
    MemAcc_ModuleInitialized,
    aaIdx,
    NULL_PTR,
    FALSE))
  {
    retVal = MemAcc_Queue_GetJob(aaIdx, FALSE)->MngmtArea.JobResult;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  MemAcc_GetJobStatus()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
MemAcc_JobStatusType MemAcc_GetJobStatus(MemAcc_AddressAreaIdType addressAreaId)
{
  MemAcc_JobStatusType retVal = MEMACC_JOB_IDLE;
  MemAcc_AddressAreaIndexType aaIdx = MemAcc_Utils_GetIndexOfAddrAreaId(addressAreaId);

  if(MemAcc_ErrorCheck_IsSynchServiceInvocationValid(
    MEMACC_SID_GETJOBSTATUS,
    MemAcc_ModuleInitialized,
    aaIdx,
    NULL_PTR,
    FALSE))
  {
    retVal = MemAcc_Queue_HasJob(aaIdx, FALSE) ? MEMACC_JOB_PENDING : MEMACC_JOB_IDLE;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  MemAcc_GetMemoryInfo()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
Std_ReturnType MemAcc_GetMemoryInfo(
  MemAcc_AddressAreaIdType addressAreaId,
  MemAcc_AddressType address,
  MemAcc_MemoryInfoType* memoryInfoPtr)
{
  Std_ReturnType retVal = E_NOT_OK;
  MemAcc_AddressAreaIndexType aaIdx = MemAcc_Utils_GetIndexOfAddrAreaId(addressAreaId);

  if(MemAcc_ErrorCheck_IsSynchServiceInvocationValid(
    MEMACC_SID_GETMEMORYINFO,
    MemAcc_ModuleInitialized,
    aaIdx,
    memoryInfoPtr,
    TRUE))
  {
    MemAcc_SubAddressAreaIndexType subAAIdx = MemAcc_Utils_GetSubAddrAreaIndexOfAddress(aaIdx, address);

    if(subAAIdx < MemAcc_GetSubAddressAreaEndIdxOfAddressArea(aaIdx))
    {
      MemAcc_MemSectorBatchIterType memSectorBatchIdx = MemAcc_GetMemSectorBatchIdxOfSubAddressArea(subAAIdx);

      memoryInfoPtr->LogicalStartAddress = MemAcc_GetLogicalStartAddressOfSubAddressArea(subAAIdx);

      memoryInfoPtr->PhysicalStartAddress = MemAcc_GetPhysicalStartAddressOfSubAddressArea(subAAIdx);

      memoryInfoPtr->MaxOffset = (MemAcc_LengthType) MemAcc_GetLogicalEndAddressOfSubAddressArea(subAAIdx)
                                                   - MemAcc_GetLogicalStartAddressOfSubAddressArea(subAAIdx);

      memoryInfoPtr->EraseSectorSize = MemAcc_GetEraseSectorSizeOfMemSectorBatch(memSectorBatchIdx);

      memoryInfoPtr->EraseSectorBurstSize = MemAcc_IsUseEraseBurstOfSubAddressArea(subAAIdx)
                                            ? MemAcc_GetEraseBurstSizeOfMemSectorBatch(memSectorBatchIdx)
                                            : MemAcc_GetEraseSectorSizeOfMemSectorBatch(memSectorBatchIdx);

#ifdef MEMACC_ASR22_11_COMPATIBILITY /* COV_MemAcc_COMPATIBILITY */
      memoryInfoPtr->ReadPageSize = MemAcc_GetMinReadSizeOfMemSectorBatch(memSectorBatchIdx);
      memoryInfoPtr->ReadPageBurstSize = MemAcc_GetMaxReadSizeOfMemSectorBatch(memSectorBatchIdx);
#else
      memoryInfoPtr->MinReadSize = MemAcc_GetMinReadSizeOfMemSectorBatch(memSectorBatchIdx);
      memoryInfoPtr->MaxReadSize = MemAcc_GetMaxReadSizeOfMemSectorBatch(memSectorBatchIdx);
#endif

      memoryInfoPtr->WritePageSize = MemAcc_GetWritePageSizeOfMemSectorBatch(memSectorBatchIdx);

      memoryInfoPtr->WritePageBurstSize = MemAcc_IsUseWriteBurstOfSubAddressArea(subAAIdx)
                                          ? MemAcc_GetWriteBurstSizeOfMemSectorBatch(memSectorBatchIdx)
                                          : MemAcc_GetWritePageSizeOfMemSectorBatch(memSectorBatchIdx);

      memoryInfoPtr->HwId = MemAcc_GetHardwareIdOfMemInstance(MemAcc_GetMemInstanceIdxOfSubAddressArea(subAAIdx));

      retVal = E_OK;
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  MemAcc_GetProcessedLength()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
MemAcc_LengthType MemAcc_GetProcessedLength(MemAcc_AddressAreaIdType addressAreaId)
{
  MemAcc_LengthType retVal = 0u;
  MemAcc_AddressAreaIndexType aaIdx = MemAcc_Utils_GetIndexOfAddrAreaId(addressAreaId);

  if(MemAcc_ErrorCheck_IsSynchServiceInvocationValid(
    MEMACC_SID_GETPROCESSEDLENGTH,
    MemAcc_ModuleInitialized,
    aaIdx,
    NULL_PTR,
    FALSE))
  {
    // SchM_Enter_MemAcc_MEMACC_EXCLUSIVE_AREA_1();
    retVal = MemAcc_Queue_GetJob(aaIdx, FALSE)->MngmtArea.Offset;
    // SchM_Exit_MemAcc_MEMACC_EXCLUSIVE_AREA_1();
  }

  return retVal;
}

/**********************************************************************************************************************
 *  MemAcc_GetJobInfo()
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
void MemAcc_GetJobInfo(
  MemAcc_AddressAreaIdType addressAreaId,
  MemAcc_JobInfoType* jobInfoPtr)
{
  MemAcc_AddressAreaIndexType aaIdx = MemAcc_Utils_GetIndexOfAddrAreaId(addressAreaId);

  if(MemAcc_ErrorCheck_IsSynchServiceInvocationValid(
    MEMACC_SID_GETJOBINFO,
    MemAcc_ModuleInitialized,
    aaIdx,
    jobInfoPtr,
    TRUE))
  {
    const MemAcc_JobContextType* job = MemAcc_Queue_GetJob(aaIdx, FALSE);

    jobInfoPtr->CurrentJob = (MemAcc_JobType)job->JobArea.JobType; /* PRQA S 4342 */ /* MD_MemAcc_JobTypeEnumCasting */
    jobInfoPtr->LogicalAddress = job->JobArea.Address;
    jobInfoPtr->Length = job->JobArea.Length;
    /* For hw specific jobs directly the hwId can be returned */
    jobInfoPtr->HwId = job->JobArea.HwId;
    jobInfoPtr->MemResult = MemAcc_MemAccMemJobResultMapping(&job->MngmtArea.JobStep);

    if (jobInfoPtr->MemResult == MEM_JOB_PENDING)
    {
      jobInfoPtr->MemInstanceId = MemAcc_GetInstanceIdOfMemInstance(
        MemAcc_GetMemInstanceIdxOfSubAddressArea(job->MngmtArea.JobStep.SubAddrAreaIdx));
      jobInfoPtr->MemAddress = job->MngmtArea.JobStep.PhysicalAddress;
      jobInfoPtr->MemLength = job->MngmtArea.JobStep.Length;
      /* For hw specific jobs, the job step hw id is the same as the hw id of the job area.
          For all other jobs the hw id of the current job step will be returned */
      jobInfoPtr->HwId = MemAcc_GetHardwareIdOfMemInstance(
        MemAcc_GetMemInstanceIdxOfSubAddressArea(job->MngmtArea.JobStep.SubAddrAreaIdx));
    }
    else
    {
      jobInfoPtr->MemInstanceId = 0u;
      jobInfoPtr->MemAddress = 0u;
      jobInfoPtr->MemLength = 0u;
    }
  }
}


/**********************************************************************************************************************
 *   MemAcc_MainFunction()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
void MemAcc_MainFunction(void)
{
  if(MemAcc_ModuleInitialized == MEMACC_INIT)
  {
    MemAcc_MainFsm_ProcessAllSyncGroups();
  }
}

/**********************************************************************************************************************
 *  MemAcc_ActivateMem()
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
 */
Std_ReturnType MemAcc_ActivateMem(
  MemAcc_AddressType headerAddress,
  MemAcc_HwIdType hwId)
{
  Std_ReturnType retVal = E_NOT_OK;
  MemAcc_SizeOfCLowerLayerType llIdx = MemAcc_Utils_GetLowerLayerIndexOfHwId(hwId);

  if (llIdx < MemAcc_GetSizeOfLowerLayer())
  {
    /* If llIdx is INDIRECT_DYNAMIC */
    if (MemAcc_GetStaticMemBinaryHeaderOfLowerLayer(llIdx) == NULL_PTR)
    {
      if (MemAcc_ErrorCheck_IsActivateMemInvocationValid(
        MEMACC_SID_ACTIVATEMEM,
        MemAcc_ModuleInitialized,
        headerAddress))
      {
        if (MemAcc_MemAccessControl_ActivateMemBinaryHeader(llIdx, (MemAcc_MemBinaryHeaderType*) headerAddress)) /* PRQA S 0306 */ /* MD_MemAcc_HeaderAddressToMemBinaryHeaderPointerCast */
        {
          retVal = E_OK;
        }
      }
    }
    else
    {

#if (MEMACC_READONLYMODE_ENABLED == STD_ON)

      if (MemAcc_ErrorCheck_IsInitialized(MEMACC_SID_ACTIVATEMEM, MemAcc_ModuleInitialized))
      {
        if (MemAcc_MemAccessControl_SetMemReadOnlyAccess(hwId, (uint8*) headerAddress, FALSE)) /* PRQA S 0306 */ /* MD_MemAcc_HeaderAddressToUint8PointerCast */
        {
          retVal = E_OK;
        }
      }

#endif /* (MEMACC_READONLYMODE_ENABLED == STD_ON) */

    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  MemAcc_DeactivateMem()
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
Std_ReturnType MemAcc_DeactivateMem(
  MemAcc_AddressType headerAddress,
  MemAcc_HwIdType hwId)
{
  Std_ReturnType retVal = E_NOT_OK;
  MemAcc_SizeOfCLowerLayerType llIdx = MemAcc_Utils_GetLowerLayerIndexOfHwId(hwId);

  if (llIdx < MemAcc_GetSizeOfLowerLayer())
  {
    if (MemAcc_ErrorCheck_IsInitialized(MEMACC_SID_DEACTIVATEMEM, MemAcc_ModuleInitialized))
    {
      /* If llIdx is INDIRECT_DYNAMIC */
      if (MemAcc_GetStaticMemBinaryHeaderOfLowerLayer(llIdx) == NULL_PTR)
      {
        if (MemAcc_MemAccessControl_DeactivateMemBinaryHeader(llIdx, (MemAcc_MemBinaryHeaderType*) headerAddress)) /* PRQA S 0306 */ /* MD_MemAcc_HeaderAddressToMemBinaryHeaderPointerCast */
        {
          retVal = E_OK;
        }
      }
      else
      {

#if (MEMACC_READONLYMODE_ENABLED == STD_ON)

        if (MemAcc_MemAccessControl_SetMemReadOnlyAccess(hwId, (uint8*) headerAddress, TRUE)) /* PRQA S 0306 */ /* MD_MemAcc_HeaderAddressToUint8PointerCast */
        {
          retVal = E_OK;
        }

#endif /* (MEMACC_READONLYMODE_ENABLED == STD_ON) */

      }
    }
  }

  return retVal;
}

#define MEMACC_STOP_SEC_CODE
#include "MemAcc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  MISRA JUSTIFICATIONS
 **********************************************************************************************************************/

/* Justification for module-specific MISRA deviations:

MD_MemAcc_LocalVariableExternalLinkage: rule 8.4
  Reason:     MEMACC_LOCAL is redefined to empty in test builds to allow unit tests to access internal state.
              This causes QAC warning 3408 because the variable has external linkage without prior declaration.
              In production builds, MEMACC_LOCAL expands to 'static', making this a file-scope variable.
  Risk:       None, as this only affects test builds where the variable needs to be accessible.
  Prevention: The production build uses the proper 'static' definition via MEMACC_LOCAL macro.

MD_MemAcc_HwIdEnumCasting: rule 10.5
  Reason:     HwId in the JobInfo struct is to be initialized with a value. However, HwId is a generated enum where the
              values are not known in the static code. The value is initialized with a explicitly casted value HwIdType.
  Risk:       None, as the HwIdType always has a value corresponding to zero, and all code paths depending on this value
              are covered.
  Prevention: No prevention, as the HwIdType always has a value corresponding to zero.

MD_MemAcc_DispatchJobStepToSharedMemoryConstQualifier: rule 8.13
  Reason:     In case MEMACC_MULTIBINARY_ISSATELLITEBINARY is STD_ON, the physical address of the job is updated.
  Risk:       The job could be modified inside the function.
  Prevention: Code review to make sure this parameter is not modified besides the physical address.

MD_MemAcc_HeaderAddressToMemBinaryHeaderPointerCast: rule 11.3
  Reason:     MemAcc_AddressType is casted to a MemAcc_MemBinaryHeaderType pointer.
  Risk:       If the headerAddress is invalid, the resulting pointer may be mapped to an invalid address and the
              Mem function calls may either result in undefined behavior or allows users for potential harmful code
              injection.
  Prevention: No prevention, as AUTOSAR defines the headerAddress to be passed as a MemAcc_AddressType that represents
              the address of a MemAcc_MemBinaryHeaderType and the User of the component is responsible for a valid
              address. There are plausibility checks to ensure the structure is correctly defined like the delimiter
              check, however the given function pointer cannot be validated for harmful code injection.

MD_MemAcc_HeaderAddressToUint8PointerCast: rule 11.3
  Reason:     MemAcc_AddressType is casted to a uint8 pointer.
  Risk:       If the headerAddress is invalid, the resulting pointer may be mapped to an invalid address.
  Prevention: No prevention, as AUTOSAR defines the headerAddress to be passed as a MemAcc_AddressType that represents
              the address of a MemAcc_MemBinaryHeaderType and the User of the component is responsible for a valid
              address. The Mem ReadOnlyMode Feature was defined to use the same function and has therefore the
              same problem.

*/

/***********************************************************************************************************************
 *  VCA JUSTIFICATIONS
 **********************************************************************************************************************/
/* VCA_JUSTIFICATION_BEGIN

\ID VCA_MemAcc_AddressAreaIndexAssertionFail
  \DESCRIPTION The AddressAreaIndex is used as the starting point to get all needed information to process
               a job for a specific addressAreaId. When a job is put into queue or the queue entry is processed
               this value has to be valid, therefore it must be smaller as the size of the generated AddressArea array.

  \COUNTERMEASURE \R A runtime check within the ErrorCheck unit ensures that the forwarded addressAreaIndex is valid.
                     Tooling currently does not consider the check placed in another unit automatically.

VCA_JUSTIFICATION_END */


/***********************************************************************************************************************
 *  COV JUSTIFICATION
 **********************************************************************************************************************/
/* COV_JUSTIFICATION_BEGIN

\ID COV_MemAcc_MemAb_MISRA
\ACCEPT XX
\REASON [COV_MSR_MISRA]

\ID COV_MemAcc_COMPATIBILITY
\ACCEPT TX
\ACCEPT XF
\REASON Compatibility modus defined through build system. Verified manually to be correct implementation.

\ID COV_MEMACC_VCA
\ACCEPT TX
\ACCEPT XF
\REASON VCA needs additional functions to analyze to code in a meaningful way. Therefore, this code part is not enabled when using VCA.

COV_JUSTIFICATION_END */

/**********************************************************************************************************************
 *  END OF FILE: MemAcc.c
 *********************************************************************************************************************/
