/**********************************************************************************************************************
 *  COPYRIGHT
 *  --------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2025 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  --------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/*!        \file  Fee_30_FlexNor_ErrorChecks.h
 *        \brief  Provides error checks
 *      \details  Provides the declarations for error check functions of API parameters.
 *         \unit  ErrorChecks
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 **********************************************************************************************************************/

#if !defined (FEE_30_FLEXNOR_ERRORCHECKS_H)
# define FEE_30_FLEXNOR_ERRORCHECKS_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Fee_30_FlexNor_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
# define FEE_30_FLEXNOR_START_SEC_CODE
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Fee_30_FlexNor_ErrorChecks_IsDetConditionTrue()
 *********************************************************************************************************************/
/*! \brief       Checks if the given condition evaluates to TRUE and the DET is enabled
 *  \details     -
 *  \param[in]   condition      Condition to check
 *  \return      TRUE    The condition evaluates to true and DET is enabled.
 *               FALSE   The condition doesn't matter but DET is disabled.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(boolean, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_ErrorChecks_IsDetConditionTrue(boolean condition);

/**********************************************************************************************************************
 * Fee_30_FlexNor_DetChecks_ReportDetError()
 *********************************************************************************************************************/
/*! \brief       Reports an error to the DET in case DET error reporting is enabled
 *  \details     -
 *  \param[in]   serviceId  Id of the service reporting the error
 *  \param[in]   errorCode  Error code that needs to be reported
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_ErrorChecks_ReportDetError(Fee_30_FlexNor_ServiceId serviceId, Fee_30_FlexNor_ErrorCode errorCode);

/**********************************************************************************************************************
 * Fee_30_FlexNor_DetChecks_ReportRuntimeError()
 *********************************************************************************************************************/
/*! \brief       Reports the given error as runtime error
 *  \details     -
 *  \param[in]   serviceId  Id of the service reporting the error
 *  \param[in]   errorCode  Error code that needs to be reported
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_ErrorChecks_ReportRuntimeError(Fee_30_FlexNor_ServiceId serviceId, Fee_30_FlexNor_ErrorCode errorCode);

# define FEE_30_FLEXNOR_STOP_SEC_CODE
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* FEE_30_FLEXNOR_ERRORCHECKS_H */

/**********************************************************************************************************************
 *  END OF FILE: Fee_30_FlexNor_ErrorChecks.h
 *********************************************************************************************************************/
