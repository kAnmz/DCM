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
/*!        \file  MemAcc_MemAccessControl.c
 *        \brief  MemAcc_MemAccessControl source file
 *      \details  Implementation of the unit MemAccessControl.
 *         \unit  MemAccessControl
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/
#define MEMACC_MEMACCESSCONTROL_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "MemAcc_MemAccessControl.h"
# include "MemAcc_MemAb.h"
# include "MemAcc_Queue.h"
# include "vstdlib.h"

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

#if (MEMACC_READONLYMODE_ENABLED == STD_ON)

/**********************************************************************************************************************
 * MemAcc_MemAccessControl_IsMemAccessAllowedByReadOnlyConfiguration()
 *********************************************************************************************************************/
/*!
 *  \brief         Checks if ReadOnlyConfiguration allows the execution of the given job type.
 *  \details       -
 *  \param[in]     saaIdx - Subaddressarea Index
 *  \param[in]     jobType - Job Type
 *  \return        TRUE if the job execution is allowed, FALSE otherwise.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 */
MEMACC_LOCAL boolean MemAcc_MemAccessControl_IsMemAccessAllowedByReadOnlyConfiguration(
  const MemAcc_SubAddressAreaIndexType saaIdx,
  const MemAcc_JobType jobType);

/**********************************************************************************************************************
 * MemAcc_MemAccessControl_GetReadOnlyModeConfiguration()
 *********************************************************************************************************************/
/*!
 *  \brief         Gets the read only mode configuration that matches the given hardware ID and unlock token.
 *  \details       -
 *  \param[in]     hwId - Hardware ID
 *  \param[in]     unlockToken - Unlock Token
 *  \return        Index of the read only mode configuration table that targets the matches the given parameters.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 */
MEMACC_LOCAL MemAcc_CReadOnlyConfigurationIterType MemAcc_MemAccessControl_GetReadOnlyModeConfiguration(
  const MemAcc_HwIdType hwId,
  const uint8* unlockToken);

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * MemAcc_MemAccessControl_IsMemAccessAllowedByReadOnlyConfiguration()
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
MEMACC_LOCAL boolean MemAcc_MemAccessControl_IsMemAccessAllowedByReadOnlyConfiguration(
  const MemAcc_SubAddressAreaIndexType saaIdx,
  const MemAcc_JobType jobType)
{
  boolean executionAllowed = TRUE;

  const MemAcc_CReadOnlyConfigurationIterType roConfigIdx =
        MemAcc_GetReadOnlyConfigurationIdxOfSubAddressArea(saaIdx);

  if (roConfigIdx < MemAcc_GetSizeOfCReadOnlyConfiguration())
  {
    switch (jobType)
    {
    case MEMACC_WRITE_JOB:
    case MEMACC_ERASE_JOB:
      executionAllowed = !MemAcc_IsReadOnlyEnabledOfReadOnlyConfiguration(roConfigIdx);
      break;
    case MEMACC_MEMHWSPECIFIC_JOB:
      executionAllowed = !MemAcc_IsReadOnlyEnabledOfReadOnlyConfiguration(roConfigIdx)
        || MemAcc_IsReadOnlyModeSupportsHwSpecificServiceOfReadOnlyConfiguration(roConfigIdx);
      break;
    case MEMACC_BLANKCHECK_JOB:
    case MEMACC_READ_JOB:
    case MEMACC_COMPARE_JOB:
    case MEMACC_NO_JOB:
    case MEMACC_REQUESTLOCK_JOB:
    default: /* COV_MemAcc_MemAccessControl_MISRA */
      break;
    }
  }

  return executionAllowed;
}

/**********************************************************************************************************************
 * MemAcc_MemAccessControl_GetReadOnlyModeConfiguration()
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
MEMACC_LOCAL MemAcc_CReadOnlyConfigurationIterType MemAcc_MemAccessControl_GetReadOnlyModeConfiguration(
  const MemAcc_HwIdType hwId,
  const uint8* unlockToken)
{
  MemAcc_CReadOnlyConfigurationIterType roConfigIdx = MemAcc_GetSizeOfCReadOnlyConfiguration();

  for(MemAcc_SubAddressAreaIndexType saaIdx = 0u; saaIdx < MemAcc_GetSizeOfSubAddressArea(); saaIdx++)
  {
    if (MemAcc_GetHardwareIdOfMemInstance(MemAcc_GetMemInstanceIdxOfSubAddressArea(saaIdx)) == hwId)
    {
      const MemAcc_CReadOnlyConfigurationIterType saaRoConfigIdx =
        MemAcc_GetReadOnlyConfigurationIdxOfSubAddressArea(saaIdx);

      if (saaRoConfigIdx < MemAcc_GetSizeOfCReadOnlyConfiguration())
      {
        if (VStdLib_MemCmp(unlockToken,
          MemAcc_GetUnlockTokenPointerOfReadOnlyConfiguration(saaRoConfigIdx),
          MemAcc_GetUnlockTokenSizeOfReadOnlyConfiguration(saaRoConfigIdx)) == 0)
        {
          roConfigIdx = saaRoConfigIdx;
          break;
        }
      }
    }
  }

  return roConfigIdx;
}

#endif /* MEMACC_READONLYMODE_ENABLED */

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * MemAcc_MemAccessControl_Reset()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
void MemAcc_MemAccessControl_Reset(void)
{
#if (MEMACC_READONLYMODE_ENABLED == STD_ON)

  for (MemAcc_CReadOnlyConfigurationIterType roConfigIdx = 0u;
    roConfigIdx < MemAcc_GetSizeOfCReadOnlyConfiguration();
    roConfigIdx++)
  {
    MemAcc_SetReadOnlyEnabledOfReadOnlyConfiguration(roConfigIdx, TRUE);
  }

#endif /* MEMACC_READONLYMODE_ENABLED */

  for(MemAcc_LowerLayerIndexType llIdx = 0; llIdx < MemAcc_GetSizeOfLowerLayer(); llIdx++)
  {
    MemAcc_SetIndirectDynamicMemBinaryHeaderOfLowerLayer(llIdx, NULL_PTR);
  }
}

/**********************************************************************************************************************
 * MemAcc_MemAccessControl_IsMemAccessAllowed()
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
boolean MemAcc_MemAccessControl_IsMemAccessAllowed(
  const MemAcc_SubAddressAreaIndexType saaIdx,
  const MemAcc_JobType jobType)
{
  boolean executionAllowed = TRUE;
  const MemAcc_LowerLayerIndexType llIdx = MemAcc_GetLowerLayerIdxOfSubAddressArea(saaIdx);
  MEMACC_DUMMY_STATEMENT(jobType);

  /* If llIdx is INDIRECT_DYNAMIC */
  if (MemAcc_GetStaticMemBinaryHeaderOfLowerLayer(llIdx) == NULL_PTR)
  {
    executionAllowed = MemAcc_GetIndirectDynamicMemBinaryHeaderOfLowerLayer(llIdx) != NULL_PTR;
  }
  else
  {

#if (MEMACC_READONLYMODE_ENABLED == STD_ON)

    executionAllowed = MemAcc_MemAccessControl_IsMemAccessAllowedByReadOnlyConfiguration(saaIdx, jobType);

#endif /* MEMACC_READONLYMODE_ENABLED */

  }

  return executionAllowed;
}

/**********************************************************************************************************************
 * MemAcc_MemAccessControl_ActivateMemBinaryHeader()
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
boolean MemAcc_MemAccessControl_ActivateMemBinaryHeader(
  const MemAcc_SizeOfCLowerLayerType llIdx,
  MemAcc_MemBinaryHeaderType *memBinaryHeader)
{
  boolean operationSuccessful = FALSE;

  if (MemAcc_GetIndirectDynamicMemBinaryHeaderOfLowerLayer(llIdx) == NULL_PTR)
  {
    MemAcc_SetIndirectDynamicMemBinaryHeaderOfLowerLayer(llIdx, memBinaryHeader);
    MemAcc_MemAb_InvokeInit(llIdx, NULL_PTR);
    operationSuccessful = TRUE;
  }

  return operationSuccessful;
}

/**********************************************************************************************************************
 * MemAcc_MemAccessControl_DeactivateMemBinaryHeader()
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
boolean MemAcc_MemAccessControl_DeactivateMemBinaryHeader(
  const MemAcc_SizeOfCLowerLayerType llIdx,
  const MemAcc_MemBinaryHeaderType *memBinaryHeader)
{
  boolean operationSuccessful = FALSE;

  if ((MemAcc_Queue_HasJobForLowerLayerIdx(llIdx) == FALSE)
    && (MemAcc_GetIndirectDynamicMemBinaryHeaderOfLowerLayer(llIdx) == memBinaryHeader))
  {
    MemAcc_MemAb_InvokeDeInit(llIdx);
    MemAcc_SetIndirectDynamicMemBinaryHeaderOfLowerLayer(llIdx, NULL_PTR);
    operationSuccessful = TRUE;
  }

  return operationSuccessful;
}

#if (MEMACC_READONLYMODE_ENABLED == STD_ON)

/**********************************************************************************************************************
 * MemAcc_MemAccessControl_SetMemReadOnlyAccess()
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
boolean MemAcc_MemAccessControl_SetMemReadOnlyAccess(
  const MemAcc_HwIdType hwId,
  const uint8 *unlockToken,
  const boolean isReadOnlyEnabled)
{
  boolean operationSuccessful = FALSE;

  if (unlockToken != NULL_PTR)
  {
    MemAcc_CReadOnlyConfigurationIterType roConfigIdx
      = MemAcc_MemAccessControl_GetReadOnlyModeConfiguration(hwId, unlockToken);

    if ((roConfigIdx < MemAcc_GetSizeOfCReadOnlyConfiguration())
      && (MemAcc_IsReadOnlyEnabledOfReadOnlyConfiguration(roConfigIdx) != isReadOnlyEnabled))
    {
      MemAcc_SetReadOnlyEnabledOfReadOnlyConfiguration(roConfigIdx, isReadOnlyEnabled);
      operationSuccessful = TRUE;
    }
  }

  return operationSuccessful;
}

#endif /* MEMACC_READONLYMODE_ENABLED */

#define MEMACC_STOP_SEC_CODE
#include "MemAcc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  COV JUSTIFICATION
 **********************************************************************************************************************/
/* COV_JUSTIFICATION_BEGIN

\ID COV_MemAcc_MemAccessControl_MISRA
\ACCEPT XX
\REASON [COV_MSR_MISRA]

COV_JUSTIFICATION_END */

/**********************************************************************************************************************
 *  END OF FILE: MemAcc_MemAccessControl.c
 *********************************************************************************************************************/
