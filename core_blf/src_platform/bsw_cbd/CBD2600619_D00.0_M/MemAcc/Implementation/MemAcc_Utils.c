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
/*!        \file  MemAcc_Utils.c
 *        \brief  MemAcc_Utils source file
 *      \details  Implementation of the unit Utils.
 *         \unit  Utils
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/
#define MEMACC_UTILS_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "MemAcc_Utils.h"

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/
#if !defined (MEMACC_LOCAL)
# define MEMACC_LOCAL                                                    static
#endif

#if !defined (MEMACC_LOCAL_INLINE)
# define MEMACC_LOCAL_INLINE                                             LOCAL_INLINE
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
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * MemAcc_Utils_GetLowerLayerIndexOfHwId()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
MemAcc_SizeOfCLowerLayerType MemAcc_Utils_GetLowerLayerIndexOfHwId(MemAcc_HwIdType hwId)
{
  MemAcc_SizeOfCLowerLayerType llIdx = MemAcc_GetSizeOfLowerLayer();

  for(MemAcc_SubAddressAreaIndexType saa = 0u; saa < MemAcc_GetSizeOfSubAddressArea(); saa++)
  {
    if(MemAcc_GetHardwareIdOfMemInstance(MemAcc_GetMemInstanceIdxOfSubAddressArea(saa)) == hwId)
    {
      llIdx = MemAcc_GetLowerLayerIdxOfSubAddressArea(saa);
      break;
    }
  }

  return llIdx;
}

/**********************************************************************************************************************
 * MemAcc_Utils_IsInternalJob()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
boolean MemAcc_Utils_IsInternalJob(MemAcc_JobClassificationType jobClassification)
{
  return jobClassification != MEMACC_JOBCLASSIFICATION_USERJOB;
}

#if (MEMACC_BBM_ENABLED == STD_ON) /* COV_MSR_UT_OPTIONAL_UNIT */

/**********************************************************************************************************************
 * MemAcc_Utils_GetAddrAreaIdxOfSubAddrAreaIdx()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
MemAcc_AddressAreaIndexType MemAcc_Utils_GetAddrAreaIdxOfSubAddrAreaIdx(MemAcc_SubAddressAreaIndexType saaIdx)
{
  MemAcc_AddressAreaIndexType ret = 0u;

  for(ret = 0u; ret < MemAcc_GetSizeOfAddressArea(); ret++)
  {
    if((saaIdx >= MemAcc_GetSubAddressAreaStartIdxOfAddressArea(ret))
      && (saaIdx < MemAcc_GetSubAddressAreaEndIdxOfAddressArea(ret)))
    {
      break;
    }
  }

  return ret;
}

/**********************************************************************************************************************
 * MemAcc_Utils_GetPhysicalBlockNr()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
MemAcc_NumberOfSectorsOfSubAddressAreaType MemAcc_Utils_GetPhysicalBlockNr(
  MemAcc_SubAddressAreaIndexType saaIdx,
  MemAcc_AddressType physicalAddress)
{
  return (MemAcc_NumberOfSectorsOfSubAddressAreaType)
    ((physicalAddress - MemAcc_GetPhysicalStartAddressOfSubAddressArea(saaIdx))
      / MemAcc_GetEraseSectorSizeOfMemSectorBatch(MemAcc_GetMemSectorBatchIdxOfSubAddressArea(saaIdx)));
}

/**********************************************************************************************************************
 * MemAcc_Utils_GetPhysicalAddress
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
MemAcc_AddressType MemAcc_Utils_GetPhysicalAddress(
  MemAcc_SubAddressAreaIndexType saaIdx,
  MemAcc_NumberOfSectorsOfSubAddressAreaType physicalBlockNr)
{
  return MemAcc_GetPhysicalStartAddressOfSubAddressArea(saaIdx)
    + (((MemAcc_AddressType)physicalBlockNr)
    * MemAcc_GetEraseSectorSizeOfMemSectorBatch(MemAcc_GetMemSectorBatchIdxOfSubAddressArea(saaIdx)));
}

#endif /* MEMACC_BBM_ENABLED */

/**********************************************************************************************************************
 *  MemAcc_Utils_GetSubAddrAreaIndexOfAddress
 *********************************************************************************************************************/
/*!
 * Internal comment removed. *
 *
 *
 *
 *
 */
MemAcc_SubAddressAreaIndexType MemAcc_Utils_GetSubAddrAreaIndexOfAddress(
  MemAcc_AddressAreaIndexType addressAreaIdx,
  MemAcc_AddressType logicalAddress)
{
  MemAcc_SubAddressAreaIndexType saaIdx = MemAcc_GetSubAddressAreaStartIdxOfAddressArea(addressAreaIdx);

  for(; saaIdx < MemAcc_GetSubAddressAreaEndIdxOfAddressArea(addressAreaIdx); saaIdx++)
  {
    if((logicalAddress >= MemAcc_GetLogicalStartAddressOfSubAddressArea(saaIdx)) &&
       (logicalAddress <= MemAcc_GetLogicalEndAddressOfSubAddressArea(saaIdx)))
    {
      /* Sub Address Area found, return its index. */
      break;
    }
  }

  return saaIdx;
}

/**********************************************************************************************************************
 *  MemAcc_Utils_GetIndexOfAddrAreaId
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
MemAcc_AddressAreaIndexType MemAcc_Utils_GetIndexOfAddrAreaId(MemAcc_AddressAreaIdType addressAreaId)
{
  MemAcc_AddressAreaIndexType index = 0u;

  for(; index < MemAcc_GetSizeOfAddressArea(); index++)
  {
    if(MemAcc_GetAddressAreaIdOfAddressArea(index) == addressAreaId)
    {
      break;
    }
  }

  return index;
}

/**********************************************************************************************************************
 *  MemAcc_Utils_GetSubAddrAreaIndexOfHwId
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
MemAcc_SubAddressAreaIndexType MemAcc_Utils_GetSubAddrAreaIndexOfHwId(
  MemAcc_AddressAreaIndexType addressAreaIdx,
  MemAcc_HwIdType hwId)
{
  MemAcc_SubAddressAreaIndexType subAddrAreaIdx = MemAcc_GetSubAddressAreaStartIdxOfAddressArea(addressAreaIdx);

  for(; subAddrAreaIdx < MemAcc_GetSubAddressAreaEndIdxOfAddressArea(addressAreaIdx); subAddrAreaIdx++)
  {
    if(MemAcc_GetHardwareIdOfMemInstance(MemAcc_GetMemInstanceIdxOfSubAddressArea(subAddrAreaIdx)) == hwId)
    {
      break;
    }
  }

  return subAddrAreaIdx;
}

/**********************************************************************************************************************
 *  MemAcc_Utils_GetNumberOfJobStepRetries
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
MemAcc_JobStepRetryCounterType MemAcc_Utils_GetNumberOfJobStepRetries(
  MemAcc_SubAddressAreaIndexType subAddrAreaIdx,
  MemAcc_JobType jobType)
{
  MemAcc_JobStepRetryCounterType ret = 0u;

  switch (jobType)
  {
  case MEMACC_WRITE_JOB:
    ret = MemAcc_GetNumberOfWriteRetriesOfSubAddressArea(subAddrAreaIdx);
    break;
  case MEMACC_ERASE_JOB:
    ret = MemAcc_GetNumberOfEraseRetriesOfSubAddressArea(subAddrAreaIdx);
    break;
  case MEMACC_READ_JOB:
  case MEMACC_COMPARE_JOB:
    ret = MemAcc_GetNumberOfReadRetriesOfSubAddressArea(subAddrAreaIdx);
    break;
  case MEMACC_BLANKCHECK_JOB:
  case MEMACC_NO_JOB:
  case MEMACC_MEMHWSPECIFIC_JOB:
  case MEMACC_REQUESTLOCK_JOB:
  default: /* COV_MemAcc_Utils_MISRA */
    ret = 0u;
    break;
  }

  return ret;
}

/**********************************************************************************************************************
 *  MemAcc_Utils_GetSAAIndicesForAddressRange
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
boolean MemAcc_Utils_GetSAAIndicesForAddressRange(
  MemAcc_AddressAreaIndexType AddressAreaIndex,
  MemAcc_AddressType* Address,
  MemAcc_LengthType* Length,
  MemAcc_SubAddressAreaIndexType* SubAddressAreaIndex)
{
  boolean retVal = FALSE;

  /* Check whether the current address belongs to any sub address area. */
  *SubAddressAreaIndex = MemAcc_Utils_GetSubAddrAreaIndexOfAddress(AddressAreaIndex, *Address);
  if((*SubAddressAreaIndex < MemAcc_GetSubAddressAreaEndIdxOfAddressArea(AddressAreaIndex)) && (*Length > 0u))
  {
    retVal = TRUE;

    /* Number of bytes within current sub address area from Address to the end. */
    MemAcc_LengthType remainingSAALength = ((MemAcc_LengthType)MemAcc_GetLogicalEndAddressOfSubAddressArea(*SubAddressAreaIndex) - *Address + 1u);

    /* Address is valid, the requested address space belongs to one single sub address area (is max the remaining
      * size within the SAA) -> set Length to 0u to return FALSE in next function call. */
    if(*Length <= remainingSAALength)
    {
      *Length = 0u;
    }
    /* Requested length > current sub address area, we need to check the following sub address area
      * (if there is any) -> adjust address and length. */
    else
    {
      /* Subtract the already checked number of bytes from requested length. */
      *Length -= remainingSAALength;
      /* Calculate the next address - shall always point to the first byte after the current sub address area. */
      *Address = ((MemAcc_AddressType)MemAcc_GetLogicalEndAddressOfSubAddressArea(*SubAddressAreaIndex) + 1u);
    }
  }
  /* Address invalid, abort and return. */
  else
  {
    /* do nothing */
  }

  return retVal;
}

#define MEMACC_STOP_SEC_CODE
#include "MemAcc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  COV JUSTIFICATION
 **********************************************************************************************************************/
/* COV_JUSTIFICATION_BEGIN

\ID COV_MemAcc_Utils_MISRA
\ACCEPT XX
\REASON [COV_MSR_MISRA]

COV_JUSTIFICATION_END */

/**********************************************************************************************************************
 *  END OF FILE: MemAcc_Utils.c
 *********************************************************************************************************************/
