/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2025 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!        \file  Mem_30_LegacyAdapter_ErrorChecks_Int.h
 *        \brief  Static inline header file containing Det check functions for Mem driver.
 *
 *      \details  -
 *         \unit  ErrorChecks
 *********************************************************************************************************************/

#if !defined (MEM_30_LEGACYADAPTER_ERRORCHECKS_INT_H)
# define MEM_30_LEGACYADAPTER_ERRORCHECKS_INT_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "Mem_30_LegacyAdapter_Cfg.h"


/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
# if !defined (MEM_30_LEGACYADAPTER_ERRORCHECKS_LOCAL_INLINE)
#  define MEM_30_LEGACYADAPTER_ERRORCHECKS_LOCAL_INLINE               LOCAL_INLINE
# endif
/**********************************************************************************************************************
 *  GLOBAL STATIC VCA ASSERTIONS
 *********************************************************************************************************************/
/*@ static_assert MEM_30_LEGACYADAPTER_DEV_ERROR_DETECT == STD_ON, "error detection on"; */
/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
# define MEM_30_LEGACYADAPTER_START_SEC_CODE_ASIL_D
# include "Mem_30_LegacyAdapter_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 * Mem_30_LegacyAdapter_ErrorChecks_IsDetConditionTrue()
 **********************************************************************************************************************/
/*! \brief        Generic Condition Check; modified by Development error Detection switch
 *  \details      Any given condition becomes FALSE, if development error Detection is DISABLED;
 *  \param[in]    condition    The condition, i.e. the result of a boolean expression
 *  \return       FALSE - Condition is FALSE or Development Error Detection is DISABLED.
 *  \return       TRUE  - Condition is TRUE AND Development Error Detection is ENABLED.
 *  \pre          -
 *  \context      TASK
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 **********************************************************************************************************************/
MEM_30_LEGACYADAPTER_ERRORCHECKS_LOCAL_INLINE FUNC(boolean, MEM_30_LEGACYADAPTER_CODE)
Mem_30_LegacyAdapter_ErrorChecks_IsDetConditionTrue(boolean condition);

/***********************************************************************************************************************
 * Mem_30_LegacyAdapter_ErrorChecks_ReportDetError()
 **********************************************************************************************************************/
/*! \brief        Report given error to DET, or drop it (if Development Error Reporting is disabled)
 *  \details      Does nothing if error is MEM_30_LEGACYADAPTER_E_NO_ERROR
 *  \param[in]    apiId      ApiId of calling service
 *  \param[in]    errorId    Error Code
 *  \pre          -
 *  \context      TASK
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 **********************************************************************************************************************/
MEM_30_LEGACYADAPTER_ERRORCHECKS_LOCAL_INLINE FUNC(void, MEM_30_LEGACYADAPTER_CODE)
Mem_30_LegacyAdapter_ErrorChecks_ReportDetError(
  uint8 apiId,
  uint8 errorId);

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
# ifndef MEM_30_LEGACYADAPTER_NOUNIT_ERRORCHECKS
/*! This NOUNIT macro is defined to enable the mocking of the function contained in this unit when testing other units.
This is required since the present unit/file contains only inline function as well as their implementation.
If another unit is tested, this macro is used to disable the actual implementation so that their function mocks can be
used instead. */

/**********************************************************************************************************************
 * Mem_30_LegacyAdapter_ErrorChecks_ReportDetError()
 *********************************************************************************************************************/
/*!
* \internal
* - #100 Check if DET reporting is active
* - #110 Call DET Error Reporting
* \endinternal
*/
MEM_30_LEGACYADAPTER_ERRORCHECKS_LOCAL_INLINE FUNC(void, MEM_30_LEGACYADAPTER_CODE)
Mem_30_LegacyAdapter_ErrorChecks_ReportDetError(
  uint8 apiId,
  uint8 errorId)
{
#  if MEM_30_LEGACYADAPTER_DEV_ERROR_REPORT == STD_ON
  if (errorId != MEM_30_LEGACYADAPTER_E_NO_ERROR) /* PRQA S 2995,2996 */ /* MD_MSR_ConstantCondition */
  {
    (void) Det_ReportError(MEM_30_LEGACYADAPTER_MODULE_ID, MEM_30_LEGACYADAPTER_INSTANCE_ID_DET, apiId, errorId);
  }
#  else
  MEM_30_LEGACYADAPTER_DUMMY_STATEMENT(apiId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  MEM_30_LEGACYADAPTER_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif
} /* Mem_30_LegacyAdapter_ErrorChecks_ReportDetError */

/**********************************************************************************************************************
 * Mem_30_LegacyAdapter_ErrorChecks_IsDetConditionTrue()
 *********************************************************************************************************************/
/*!
* \internal
* - #100 Check if DET check is enabled and in that case return condition
* \endinternal
*/
MEM_30_LEGACYADAPTER_ERRORCHECKS_LOCAL_INLINE FUNC(boolean, MEM_30_LEGACYADAPTER_CODE)
Mem_30_LegacyAdapter_ErrorChecks_IsDetConditionTrue(boolean condition)
{
#  if (MEM_30_LEGACYADAPTER_DEV_ERROR_DETECT == STD_ON)
  return condition;
#  else
  MEM_30_LEGACYADAPTER_DUMMY_STATEMENT(condition); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return FALSE;
#  endif /* MEM_30_LEGACYADAPTER_DEV_ERROR_DETECT */
} /* Mem_30_LegacyAdapter_ErrorChecks_IsDetConditionTrue */

# endif /* MEM_30_LEGACYADAPTER_NOUNIT_ERRORCHECKS */

# define MEM_30_LEGACYADAPTER_STOP_SEC_CODE_ASIL_D
# include "Mem_30_LegacyAdapter_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* MEM_30_LEGACYADAPTER_ERRORCHECKS_INT_H */
/**********************************************************************************************************************
 *  END OF FILE: Mem_30_LegacyAdapter_ErrorChecks_Int.h
 *********************************************************************************************************************/
