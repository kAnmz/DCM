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
/*!        \file  MemAcc_ErrorCheck.c
 *        \brief  MemAcc_ErrorCheck source file
 *      \details  Implementation of the unit ErrorCheck.
 *         \unit  ErrorCheck
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/
#define MEMACC_ERRORCHECK_SOURCE


/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "MemAcc_ErrorCheck.h"
# include "MemAcc_Queue.h"
# include "MemAcc_Utils.h"

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

#if !defined (MEMACC_LOCAL)
# define MEMACC_LOCAL                                                    static
#endif

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
# define MEMACC_START_SEC_CODE
# include "MemAcc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * MemAcc_ErrorCheck_IsMemBinaryHeaderAddressValid
 *********************************************************************************************************************/
/*! \brief         Verify if the given headerAddress is valid.
 *  \details       -
 *  \param[in]     headerAddress - Address of the Mem binary header structure.
 *  \return        TRUE If the headerAddress is valid
 *                 FALSE Otherwise
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
MEMACC_LOCAL boolean MemAcc_ErrorCheck_IsMemBinaryHeaderAddressValid(const MemAcc_AddressType headerAddress);

#if (MEMACC_MULTIBINARY_ISSATELLITEBINARY == STD_ON)

/**********************************************************************************************************************
 * MemAcc_ErrorCheck_IsAccessTypeRedirect
 *********************************************************************************************************************/
/*! \brief         Checks whether the passed HwId is a redirect access request.
 *  \details       -
 *  \param[in]     addressAreaIdx Index of address area
 *  \param[in]     hwId Target HwId
 *  \return        TRUE In case job for given HwId is redirect
 *                 FALSE Otherwise
 *  \pre           Given AdressAreaId and HwId must be valid.
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
MEMACC_LOCAL boolean MemAcc_ErrorCheck_IsAccessTypeRedirect(
  MemAcc_AddressAreaIndexType addressAreaIdx,
  MemAcc_HwIdType hwId);

#endif /* MEMACC_MULTIBINARY_ISSATELLITEBINARY */

/**********************************************************************************************************************
 * MemAcc_ErrorCheck_IsPointerValid
 *********************************************************************************************************************/
/*! \brief         Checks if the DataPtr is valid (only relevant for read and write job types).
 *  \details       -
 *  \param[in]     JobPtr Contains job type and data ptr.
 *  \return        TRUE In case Pointer is valid or job type != (Read || Write)
 *                 FALSE Otherwise
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
MEMACC_LOCAL boolean MemAcc_ErrorCheck_IsPointerValid(
  const MemAcc_JobAreaType* JobPtr);

/**********************************************************************************************************************
 * MemAcc_ErrorCheck_IsLengthAligned
 *********************************************************************************************************************/
/*! \brief         Check whether the length is aligned to page or sector dependent from job type.
 *  \details       -
 *  \param[in]     Job job type like MEMACC_WRITE_JOB
 *  \param[in]     SubAddressAreaIdx Numeric identifier of subaddress area
 *  \param[in]     Length Length in bytes
 *  \return        TRUE  In case the length is aligned
 *                 FALSE Otherwise
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
MEMACC_LOCAL boolean MemAcc_ErrorCheck_IsLengthAligned(
  MemAcc_JobType Job,
  MemAcc_SubAddressAreaIndexType SubAddrAreaIdx,
  MemAcc_LengthType Length);

/**********************************************************************************************************************
 * MemAcc_ErrorCheck_IsAddressLengthValid
 *********************************************************************************************************************/
/*! \brief         Checks whether the address and length fits to the given address area.
 *  \details       -
 *  \param[in]     job job type like MEMACC_WRITE_JOB
 *  \param[in]     addressAreaIdx Index of address area
 *  \param[in]     logicalAddress Address in logical address space
 *  \param[in]     length Length in bytes
 *  \return        TRUE  In case address and length are valid
 *                 FALSE Otherwise
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
MEMACC_LOCAL boolean MemAcc_ErrorCheck_IsAddressLengthValid(
  MemAcc_JobType job,
  MemAcc_AddressAreaIndexType addressAreaIdx,
  MemAcc_AddressType logicalAddress,
  MemAcc_LengthType length);

/**********************************************************************************************************************
 * MemAcc_ErrorCheck_IsHwIdValid
 *********************************************************************************************************************/
/*! \brief         Checks whether the hardware id is valid and fits to the given address area.
 *  \details       -
 *  \param[in]     addressAreaIdx Index of address area
 *  \param[in]     hwId Numeric identifier of hardware instance
 *  \return        TRUE  In case hardware id is valid
 *                 FALSE Otherwise
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
MEMACC_LOCAL boolean MemAcc_ErrorCheck_IsHwIdValid(
  MemAcc_AddressAreaIndexType addressAreaIdx,
  MemAcc_HwIdType hwId);

/**********************************************************************************************************************
 * MemAcc_ErrorCheck_ReportDetError
 *********************************************************************************************************************/
/*! \brief         Reports the error to DET.
 *  \details       -
 *  \param[in]     ServiceId The API ID.
 *  \param[in]     ErrorId The error code.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
MEMACC_LOCAL void MemAcc_ErrorCheck_ReportDetError(
  uint8 ServiceId,
  uint8 ErrorId);

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * MemAcc_ErrorCheck_IsMemBinaryHeaderAddressValid()
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
MEMACC_LOCAL boolean MemAcc_ErrorCheck_IsMemBinaryHeaderAddressValid(const MemAcc_AddressType headerAddress)
{
  boolean retVal = TRUE;
  const MemAcc_MemBinaryHeaderType* binaryHeaderPtr = (MemAcc_MemBinaryHeaderType*)headerAddress; /* PRQA S 0306 */ /* MD_MemAcc_HeaderAddressToMemBinaryHeaderPointerCast */

  if(binaryHeaderPtr == NULL_PTR)
  {
    retVal = FALSE;
  }
  else
  {
    const uint16 abiVersion = (uint16)(binaryHeaderPtr->UniqueID & 0xFFFFu);
    const boolean relocatableBinary = (binaryHeaderPtr->Flags & 0x1u) > 0u;

    if (
      /* ABI version must be 0x0001. SWS_Mem_00043 */
         (abiVersion != 0x0001u)
      /* Relocatable binaries are not supported. */
      || (relocatableBinary)
      /* Header and delimiter address must be set if the binary is not relocatable. SWS_Mem_00044, SWS_Mem_00046 */
      || (binaryHeaderPtr->Header == 0u)
      || (binaryHeaderPtr->Delimiter == 0u)
      /* Verify that the header address is the same address as the binaryheader. SWS_Mem_00044 */
      || (headerAddress != binaryHeaderPtr->Header)
      /* Verify that the delimiter address is the ones' complement of the unique ID. SWS_Mem_00051 */
      /* VCA Line+1 SLC-11 : VCA_MemAcc_DelimiterAddressIsNoNullPointer */
      || ((~binaryHeaderPtr->UniqueID) != *((uint64*)binaryHeaderPtr->Delimiter))) /* PRQA S 0306 */ /* MD_MemAcc_DelimiterAddressToDelimiterValueCast */
    {
      retVal = FALSE;
    }
  }

  return retVal;
}

#if (MEMACC_MULTIBINARY_ISSATELLITEBINARY == STD_ON)

/**********************************************************************************************************************
 * MemAcc_ErrorCheck_IsAccessTypeRedirect()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
MEMACC_LOCAL boolean MemAcc_ErrorCheck_IsAccessTypeRedirect(
  MemAcc_AddressAreaIndexType addressAreaIdx,
  MemAcc_HwIdType hwId)
{
  MemAcc_SubAddressAreaIndexType subAAIndex = MemAcc_Utils_GetSubAddrAreaIndexOfHwId(addressAreaIdx, hwId);

  return MemAcc_GetAccessTypeOfSubAddressArea(subAAIndex) == MEMACC_MULTIBINARY_REDIRECT_ACCESS;
}

#endif /* MEMACC_MULTIBINARY_ISSATELLITEBINARY */

/**********************************************************************************************************************
 * MemAcc_ErrorCheck_IsPointerValid()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
MEMACC_LOCAL boolean MemAcc_ErrorCheck_IsPointerValid(const MemAcc_JobAreaType* JobPtr)
{
  boolean retVal;
  if((JobPtr->JobType == (MemAcc_AtomicJobType)MEMACC_READ_JOB)
    && (JobPtr->DataBuffer == NULL_PTR))
  {
    retVal = FALSE;
  }
  else if (((JobPtr->JobType == (MemAcc_AtomicJobType)MEMACC_WRITE_JOB)
    || (JobPtr->JobType == (MemAcc_AtomicJobType)MEMACC_COMPARE_JOB))
    && (JobPtr->ConstDataBuffer == NULL_PTR))
  {
    retVal = FALSE;
  }
  else
  {
    retVal = TRUE;
  }

  return retVal;
}

/**********************************************************************************************************************
 * MemAcc_ErrorCheck_IsLengthAligned()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
MEMACC_LOCAL boolean MemAcc_ErrorCheck_IsLengthAligned(
  MemAcc_JobType Job,
  MemAcc_SubAddressAreaIndexType SubAddrAreaIdx,
  MemAcc_LengthType Length)
{
  boolean retVal;
  MemAcc_MemSectorBatchIterType memSectorBatchIter = MemAcc_GetMemSectorBatchIdxOfSubAddressArea(SubAddrAreaIdx);

  switch(Job)
  {
    case MEMACC_ERASE_JOB:
      retVal = (boolean)((Length % MemAcc_GetEraseSectorSizeOfMemSectorBatch(memSectorBatchIter)) == 0u);
      break;
    case MEMACC_WRITE_JOB:
      retVal = (boolean)((Length % MemAcc_GetWritePageSizeOfMemSectorBatch(memSectorBatchIter)) == 0u);
      break;
    case MEMACC_BLANKCHECK_JOB:
      retVal = (boolean)((Length % MemAcc_GetWritePageSizeOfMemSectorBatch(memSectorBatchIter)) == 0u);
      break;
    case MEMACC_READ_JOB:
    case MEMACC_COMPARE_JOB:
#if (MEMACC_READCOMPAREALIGNMENT_REQUIRED == STD_OFF)
      retVal = TRUE;
#else
      retVal = (boolean)((Length % MemAcc_GetMinReadSizeOfMemSectorBatch(memSectorBatchIter)) == 0u);
#endif
      break;
    case MEMACC_REQUESTLOCK_JOB:
      retVal = TRUE;
      break;
    case MEMACC_NO_JOB:
    case MEMACC_MEMHWSPECIFIC_JOB:
    default:                                              /* COV_MemAcc_ErrorCheck_MISRA */
      retVal = FALSE;
      break;
  }

  return retVal;
}

/**********************************************************************************************************************
 * MemAcc_ErrorCheck_IsAddressLengthValid()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
MEMACC_LOCAL boolean MemAcc_ErrorCheck_IsAddressLengthValid(
  MemAcc_JobType job,
  MemAcc_AddressAreaIndexType addressAreaIdx,
  MemAcc_AddressType logicalAddress,
  MemAcc_LengthType length)
{
  boolean retVal = FALSE;
  boolean breakLoop = FALSE;
  MemAcc_LengthType remainingLength = length;
  MemAcc_AddressType address = logicalAddress;
  MemAcc_SubAddressAreaIndexType subAddrAreaIdx;

  /* Do-While needed because a job can have a length greater than a subAddressAreaLength is. */
  do
  {
    /* Check whether the current address belongs to any sub address area. */
    subAddrAreaIdx = MemAcc_Utils_GetSubAddrAreaIndexOfAddress(addressAreaIdx, address);
    if (subAddrAreaIdx < MemAcc_GetSubAddressAreaEndIdxOfAddressArea(addressAreaIdx))
    {
      /* Number of bytes within current sub address area from Address to the end. */
      MemAcc_LengthType remainingSAALength = ((MemAcc_LengthType)MemAcc_GetLogicalEndAddressOfSubAddressArea(subAddrAreaIdx) - address + 1u);

      /* Address is valid, the requested address space belongs to one single sub address area (is max the remaining
       * size within the SAA) -> abort and return successfully. */
      if (remainingLength <= remainingSAALength)
      {
        /* no errors */
        retVal = TRUE;
        breakLoop = TRUE;
      }
      /* Requested length > current sub address area, we need to check the following sub address area
       * (if there is any) -> adjust address and length. */
      else
      {
        /* Subtract the already checked number of bytes from requested length. */
        remainingLength -= remainingSAALength;
        /* Calculate the next address - shall always point to the first byte after the current sub address area. */
        address = ((MemAcc_AddressType)MemAcc_GetLogicalEndAddressOfSubAddressArea(subAddrAreaIdx) + 1u);
      }
    }
    /* Address invalid, abort and return. */
    else
    {
      breakLoop = TRUE;
    }
  } while (breakLoop == FALSE);

  if(retVal == TRUE)
  {
    /* Perform alignment check for first sub address area (check that the start address is aligned). */
    MemAcc_SubAddressAreaIndexType initialSubAddrAreaIdx = MemAcc_Utils_GetSubAddrAreaIndexOfAddress(addressAreaIdx, address);
    MemAcc_LengthType startAddressOffset = address - MemAcc_GetLogicalStartAddressOfSubAddressArea(initialSubAddrAreaIdx);
    if(MemAcc_ErrorCheck_IsLengthAligned(job, initialSubAddrAreaIdx, startAddressOffset) == FALSE)
    {
      retVal = FALSE;
    }
    /* Perform alignment check for last sub address area (check that the remaining length is aligned). */
    if(MemAcc_ErrorCheck_IsLengthAligned(job, subAddrAreaIdx, remainingLength) == FALSE)
    {
      retVal = FALSE;
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 * MemAcc_ErrorCheck_IsHwIdValid()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
MEMACC_LOCAL boolean MemAcc_ErrorCheck_IsHwIdValid(
  MemAcc_AddressAreaIndexType addressAreaIdx,
  MemAcc_HwIdType hwId)
{
  boolean retValue = FALSE;
  MemAcc_AddressAreaIndexType subAaIndex = MemAcc_GetSubAddressAreaStartIdxOfAddressArea(addressAreaIdx);

  for (; subAaIndex < MemAcc_GetSubAddressAreaEndIdxOfAddressArea(addressAreaIdx); subAaIndex++)
  {
    if (MemAcc_GetHardwareIdOfMemInstance(MemAcc_GetMemInstanceIdxOfSubAddressArea(subAaIndex)) == hwId) {
      retValue = TRUE;
      break;
    }
  }

  return retValue;
}

/**********************************************************************************************************************
 * MemAcc_ErrorCheck_ReportDetError()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
MEMACC_LOCAL void MemAcc_ErrorCheck_ReportDetError(uint8 ServiceId, uint8 ErrorId)
{
  if (ErrorId != MEMACC_E_NO_ERROR)
  {
    MemAcc_CallDetReportError(MEMACC_MODULE_ID, MEMACC_INSTANCE_ID, ServiceId, ErrorId);
  }
}

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * MemAcc_ErrorCheck_IsSynchServiceInvocationValid()
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
boolean MemAcc_ErrorCheck_IsSynchServiceInvocationValid(
  uint8 serviceId,
  uint8 moduleInitialized,
  MemAcc_AddressAreaIndexType addressAreaIdx,
  const void* dataPtr,
  boolean isNullPtrCheckRequired)
{
  uint8 errorId = MEMACC_E_NO_ERROR;
  boolean retVal = FALSE;
  boolean AddressAreaIdCheckPassed = FALSE;

  /* check for valid AddressArea regardless of the DevErrorDetection settings */
  if(addressAreaIdx < MemAcc_GetSizeOfAddressArea())
  {
    AddressAreaIdCheckPassed = TRUE;
  }
  else
  {
    errorId = MEMACC_E_PARAM_ADDRESS_AREA_ID;
  }

  /* DET checks only if feature enabled and AAId check above passed successfully */
  if (MemAcc_IsDevErrorDetectionOfGeneralFeatures(0) && (AddressAreaIdCheckPassed == TRUE))
  {
    if(moduleInitialized == MEMACC_UNINIT)
    {
      errorId = MEMACC_E_UNINIT;
    }
    else if((isNullPtrCheckRequired == TRUE) && (dataPtr == NULL_PTR))
    {
      errorId = MEMACC_E_PARAM_POINTER;
    }
    else
    {
      /* intentionally left blank */
    }
  }

  if (MemAcc_IsDevErrorReportOfGeneralFeatures(0))
  {
    MemAcc_ErrorCheck_ReportDetError(serviceId, errorId);
  }

  if (errorId == MEMACC_E_NO_ERROR)
  {
    retVal = TRUE;
  }

  return retVal;
}

/**********************************************************************************************************************
 * MemAcc_ErrorCheck_IsGetVersionInfoInvocationValid()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
boolean MemAcc_ErrorCheck_IsGetVersionInfoInvocationValid(
  uint8 ServiceId,
  const Std_VersionInfoType* VersionInfoPtr)
{
  boolean retVal = TRUE;

  if (MemAcc_IsDevErrorDetectionOfGeneralFeatures(0) && (VersionInfoPtr == NULL_PTR))
  {
    retVal = FALSE;
    MemAcc_ErrorCheck_ReportDetError(ServiceId, MEMACC_E_PARAM_POINTER);
  }

  return retVal;
}

/**********************************************************************************************************************
 * MemAcc_ErrorCheck_IsAsynchServiceInvocationValid()
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
boolean MemAcc_ErrorCheck_IsAsynchServiceInvocationValid( /* PRQA S 6080 */ /* MD_MSR_STMIF */
  uint8 ServiceId,
  uint8 ModuleInitialized,
  const MemAcc_JobAreaType* JobPtr)
{
  uint8 errorId = MEMACC_E_NO_ERROR;
  boolean retVal = FALSE;
  boolean AddressAreaIdCheckPassed = FALSE;

  /* check for valid AddressArea regardless of the DevErrorDetection settings */
  if (JobPtr->AddressAreaIndex < MemAcc_GetSizeOfAddressArea())
  {
    AddressAreaIdCheckPassed = TRUE;
  }
  else
  {
    errorId = MEMACC_E_PARAM_ADDRESS_AREA_ID;
  }

  /* DET checks only if feature enabled and AAId check above passed successfully */
  if (MemAcc_IsDevErrorDetectionOfGeneralFeatures(0) && (AddressAreaIdCheckPassed == TRUE))
  {
    if(ModuleInitialized == MEMACC_UNINIT)
    {
      errorId =  MEMACC_E_UNINIT;
    }
    else if(MemAcc_ErrorCheck_IsAddressLengthValid((MemAcc_JobType)JobPtr->JobType, JobPtr->AddressAreaIndex, JobPtr->Address, JobPtr->Length) == FALSE) /* PRQA S 4342 */ /* MD_MemAcc_JobTypeEnumCasting */
    {
      errorId = MEMACC_E_PARAM_ADDRESS_LENGTH;
    }
    else if(MemAcc_Queue_HasJob(JobPtr->AddressAreaIndex, FALSE))
    {
      errorId = MEMACC_E_BUSY;
    }
    else if((MemAcc_ErrorCheck_IsPointerValid(JobPtr) == FALSE))
    {
      errorId = MEMACC_E_PARAM_POINTER;
    }
    else
    {
      /* do nothing */
    }
  }

  if (MemAcc_IsDevErrorReportOfGeneralFeatures(0))
  {
    MemAcc_ErrorCheck_ReportDetError(ServiceId, errorId);
  }

  if (errorId == MEMACC_E_NO_ERROR)
  {
    retVal = TRUE;
  }

  return retVal;
}

/**********************************************************************************************************************
 * MemAcc_ErrorCheck_IsHwSpecificServiceInvocationValid()
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
 */
boolean MemAcc_ErrorCheck_IsHwSpecificServiceInvocationValid( /* PRQA S 6080 */ /* MD_MSR_STMIF */
  uint8 ServiceId,
  uint8 ModuleInitialized,
  const MemAcc_JobAreaType* JobPtr)
{
  uint8 errorId = MEMACC_E_NO_ERROR;
  boolean retVal = FALSE;
  boolean AddressAreaIdCheckPassed = FALSE;

  /* check for valid AddressArea regardless of the DevErrorDetection settings */
  if (JobPtr->AddressAreaIndex < MemAcc_GetSizeOfAddressArea())
  {
    AddressAreaIdCheckPassed = TRUE;
  }
  else
  {
    errorId = MEMACC_E_PARAM_ADDRESS_AREA_ID;
  }

  /* DET checks only if feature enabled and AAId check above passed successfully */
  if (MemAcc_IsDevErrorDetectionOfGeneralFeatures(0) && (AddressAreaIdCheckPassed == TRUE))
  {
    if(ModuleInitialized == MEMACC_UNINIT)
    {
      errorId =  MEMACC_E_UNINIT;
    }
    else if(MemAcc_ErrorCheck_IsHwIdValid(JobPtr->AddressAreaIndex, JobPtr->HwId) == FALSE)
    {
      errorId = MEMACC_E_PARAM_HW_ID;
    }
    else if(MemAcc_Queue_HasJob(JobPtr->AddressAreaIndex, FALSE))
    {
      errorId = MEMACC_E_BUSY;
    }

#if (MEMACC_MULTIBINARY_ISSATELLITEBINARY == STD_ON)

    else if(MemAcc_ErrorCheck_IsAccessTypeRedirect(JobPtr->AddressAreaIndex, JobPtr->HwId) == TRUE)
    {
      errorId = MEMACC_E_REDIRECT_JOB;
    }

#endif /* MEMACC_MULTIBINARY_ISSATELLITEBINARY */

    else
    {
      /* do nothing */
    }
  }

  if (MemAcc_IsDevErrorReportOfGeneralFeatures(0))
  {
    MemAcc_ErrorCheck_ReportDetError(ServiceId, errorId);
  }

  if (errorId == MEMACC_E_NO_ERROR)
  {
    retVal = TRUE;
  }

  return retVal;
}

/**********************************************************************************************************************
 * MemAcc_ErrorCheck_IsLockInvocationValid()
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
boolean MemAcc_ErrorCheck_IsLockInvocationValid( /* PRQA S 6080 */ /* MD_MSR_STMIF */
  uint8 serviceId,
  uint8 moduleInitialized,
  MemAcc_AddressAreaIndexType addressAreaIdx,
  MemAcc_AddressType logicalAddress,
  MemAcc_AddressType length,
  MemAcc_ApplicationLockNotificationType lockNotificationFctPtr,
  boolean isRequestLockJob)
{
  uint8 errorId = MEMACC_E_NO_ERROR;
  boolean retVal = FALSE;
  boolean AddressAreaIdCheckPassed = FALSE;

  /* check for valid AddressArea regardless of the DevErrorDetection settings */
  if (addressAreaIdx < MemAcc_GetSizeOfAddressArea())
  {
    AddressAreaIdCheckPassed = TRUE;
  }
  else
  {
    errorId = MEMACC_E_PARAM_ADDRESS_AREA_ID;
  }

  /* DET checks only if feature enabled and AAId check above passed successfully */
  if (MemAcc_IsDevErrorDetectionOfGeneralFeatures(0) && (AddressAreaIdCheckPassed == TRUE))
  {
    if(moduleInitialized == MEMACC_UNINIT)
    {
      errorId =  MEMACC_E_UNINIT;
    }
    else if((isRequestLockJob == TRUE) && (lockNotificationFctPtr == NULL_PTR))
    {
      errorId = MEMACC_E_PARAM_POINTER;
    }
    else if(MemAcc_Queue_HasJob(addressAreaIdx, FALSE) && (isRequestLockJob == TRUE))
    {
      errorId = MEMACC_E_BUSY;
    }
    else if(MemAcc_ErrorCheck_IsAddressLengthValid(MEMACC_REQUESTLOCK_JOB, addressAreaIdx, logicalAddress, length) == FALSE)
    {
      errorId = MEMACC_E_PARAM_ADDRESS_LENGTH;
    }
    else
    {
      /* do nothing */
    }
  }

  if (MemAcc_IsDevErrorReportOfGeneralFeatures(0))
  {
    MemAcc_ErrorCheck_ReportDetError(serviceId, errorId);
  }

  if (errorId == MEMACC_E_NO_ERROR)
  {
    retVal = TRUE;
  }

  return retVal;
}

#if (MEMACC_MULTIBINARY_ISMASTERBINARY == STD_ON)

/**********************************************************************************************************************
 * MemAcc_ErrorCheck_ReportMultiBinaryDetError()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
void MemAcc_ErrorCheck_ReportMultiBinaryDetError(void)
{
  if (MemAcc_IsDevErrorReportOfGeneralFeatures(0))
  {
    MemAcc_ErrorCheck_ReportDetError(MEMACC_SID_REDIRECT_JOB, MEMACC_E_REDIRECT_JOB);
  }
}

#endif /* MEMACC_MULTIBINARY_ISMASTERBINARY */

/**********************************************************************************************************************
 * MemAcc_ErrorCheck_IsActivateMemInvocationValid()
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
 */
boolean MemAcc_ErrorCheck_IsActivateMemInvocationValid(
  const uint8 ServiceId,
  const uint8 ModuleInitialized,
  const MemAcc_AddressType headerAddress)
{
  uint8 errorId = MEMACC_E_NO_ERROR;
  boolean retVal = TRUE;

  if (MemAcc_IsDevErrorDetectionOfGeneralFeatures(0))
  {
    if(ModuleInitialized == MEMACC_UNINIT)
    {
      errorId = MEMACC_E_UNINIT;
      retVal = FALSE;
    }
    else if (!MemAcc_ErrorCheck_IsMemBinaryHeaderAddressValid(headerAddress))
    {
      errorId = MEMACC_E_MEM_INIT_FAILED;
      retVal = FALSE;
    }
    else
    {
      /* do nothing */
    }
  }

  if (MemAcc_IsDevErrorReportOfGeneralFeatures(0))
  {
    MemAcc_ErrorCheck_ReportDetError(ServiceId, errorId);
  }

  return retVal;
}

/**********************************************************************************************************************
 * MemAcc_ErrorCheck_IsInitialized()
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
boolean MemAcc_ErrorCheck_IsInitialized(
  const uint8 ServiceId,
  const uint8 ModuleInitialized)
{
  uint8 errorId = MEMACC_E_NO_ERROR;
  boolean retVal = TRUE;

  if (MemAcc_IsDevErrorDetectionOfGeneralFeatures(0))
  {
    if(ModuleInitialized == MEMACC_UNINIT)
    {
      errorId = MEMACC_E_UNINIT;
      retVal = FALSE;
    }
  }

  if (MemAcc_IsDevErrorReportOfGeneralFeatures(0))
  {
    MemAcc_ErrorCheck_ReportDetError(ServiceId, errorId);
  }

  return retVal;
}

#define MEMACC_STOP_SEC_CODE
#include "MemAcc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  MISRA JUSTIFICATIONS
 **********************************************************************************************************************/

/* Justification for module-specific MISRA deviations:

MD_MemAcc_DelimiterAddressToDelimiterValueCast: rule 11.3
  Reason:     MemAcc_AddressType is casted to a uint64 pointer and dereferenced.
  Risk:       If the delimiterAddress is invalid, the resulting pointer may be mapped to an invalid address and the
              validation may fail.
  Prevention: No prevention, as AUTOSAR defines the delimiterAddress to be passed as a MemAcc_AddressType that represents
              the address of a uint64 delimiter value and the User of the component is responsible for a valid
              address.
*/

/***********************************************************************************************************************
 *  VCA JUSTIFICATIONS
 **********************************************************************************************************************/
/* VCA_JUSTIFICATION_BEGIN

\ID VCA_MemAcc_DelimiterAddressIsNoNullPointer
  \DESCRIPTION The DelimiterAddress is a MemAcc_AddressType that is casted and dereferenced into a uint64 pointer.
               If the DelimiterAddress has the value 0, after the pointer cast it would dereference a NULL_PTR which
               is undefined behavior.

  \COUNTERMEASURE \R In the same if clause there is a check that the DelimiterAddress has not the value 0.
                     In the code section where the cast is performed, a 0 value is therefore not possible.

VCA_JUSTIFICATION_END */

/***********************************************************************************************************************
 *  COV JUSTIFICATION
 **********************************************************************************************************************/
/* COV_JUSTIFICATION_BEGIN

\ID COV_MemAcc_ErrorCheck_MISRA
\ACCEPT XX
\REASON [COV_MSR_MISRA]

COV_JUSTIFICATION_END */

/**********************************************************************************************************************
 *  END OF FILE: MemAcc_ErrorCheck.c
 *********************************************************************************************************************/
