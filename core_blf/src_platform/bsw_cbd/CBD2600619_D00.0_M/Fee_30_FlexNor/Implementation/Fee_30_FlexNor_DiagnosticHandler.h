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
/*!        \file  Fee_30_FlexNor_DiagnosticHandler.h
 *        \brief  Exception handler interface
 *      \details  Provides the exception handler services.
 *         \unit  DiagnosticHandler
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 **********************************************************************************************************************/

#if !defined(FEE_30_FLEXNOR_DIAGNOSTICHANDLER_H)
 #define FEE_30_FLEXNOR_DIAGNOSTICHANDLER_H

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

/***********************************************************************************************************************
*  GLOBAL FUNCTION PROTOTYPES
***********************************************************************************************************************/
# define FEE_30_FLEXNOR_START_SEC_CODE
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Fee_30_FlexNor_DiagnosticHandler_Init()
 *********************************************************************************************************************/
/*! \brief       Initialize the diagnostic handler unit
 *  \details     -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_DiagnosticHandler_Init(void);

/**********************************************************************************************************************
 * Fee_30_FlexNor_DiagnosticHandler_RaiseError()
 *********************************************************************************************************************/
/*! \brief       Raise an error, if one was detected. 
 *  \details     -
 *  \pre         -
 *  \param[in]   diagnosticId     ID of the detected error.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_DiagnosticHandler_RaiseError(
    Fee_30_FlexNor_DiagnosticIdType diagnosticId);

/**********************************************************************************************************************
 * Fee_30_FlexNor_DiagnosticHandler_RaiseWarning()
 *********************************************************************************************************************/
/*! \brief       Raise a error, if one was detected. 
 *  \details     -
 *  \pre         -
 *  \param[in]   diagnosticId     ID of the detected error.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_DiagnosticHandler_RaiseWarning(
  Fee_30_FlexNor_DiagnosticIdType diagnosticId);

/**********************************************************************************************************************
 * Fee_30_FlexNor_DiagnosticHandler_SetCurrentMilestone()
 *********************************************************************************************************************/
/*! \brief       Log the current milestone.
 *  \details     Set the reached milestone and notify the user if configured. 
 *  \pre         -
 *  \param[in]   currentMilestone   Id of the reached milestone. 
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_DiagnosticHandler_SetCurrentMilestone(
  Fee_30_FlexNor_MileStoneIdType currentMilestone);

#define FEE_30_FLEXNOR_STOP_SEC_CODE
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* FEE_30_FLEXNOR_DIAGNOSTICHANDLER_H */

/**********************************************************************************************************************
*  END OF FILE: Fee_30_FlexNor_ExceptionHandler.h
 *********************************************************************************************************************/
