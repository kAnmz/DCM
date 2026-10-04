/**********************************************************************************************************************
 *  COPYRIGHT
 *  --------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2025 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  --------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/*!        \file  Fee_30_FlexNor_DiagnosticHandler.c
 *        \brief  Exception handler unit implementation
 *      \details  Implementation of the exception handler unit.
 *         \unit  DiagnosticHandler
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/
#define FEE_30_FLEXNOR_DIAGNOSTICHANDLER_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/
#if !defined (FEE_30_FLEXNOR_LOCAL) /* COV_FEE_30_FLEXNOR_COMPATIBILITY */
# define FEE_30_FLEXNOR_LOCAL static
#endif

#if !defined (FEE_30_FLEXNOR_LOCAL_INLINE) /* COV_FEE_30_FLEXNOR_COMPATIBILITY */
# define FEE_30_FLEXNOR_LOCAL_INLINE LOCAL_INLINE
#endif

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
#include "Fee_30_FlexNor_DiagnosticHandler.h"
#include "Fee_30_FlexNor_ConfigInterface.h"
#include "Fee_30_FlexNor_DiagnosticHandler_Cbk.h"
#include "Fee_30_FlexNor_Internal.h"

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/
#define FEE_30_FLEXNOR_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

typedef struct
{
  Fee_30_FlexNor_MileStoneIdType currentMilestone;  /* Latest reached milestone of the diagnostic handler */
  uint32 eventMask;                                 /* Event mask for caching all errors and warnings */
} Fee_30_FlexNor_DiagnosticHandlerContextType;      /* Context of the diagnostic handler unit */

FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_DiagnosticHandlerContextType Fee_30_FlexNor_DiagnosticHandlerContext =
{
	.currentMilestone = FEE_30_FLEXNOR_DIAGMST_NO_MILESTONE_SET,
	.eventMask = 0u
};

#define FEE_30_FLEXNOR_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define FEE_30_FLEXNOR_START_SEC_CODE
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Fee_30_FlexNor_DiagnosticHandler_RaiseEvent()
 *********************************************************************************************************************/
/*! \brief		 Notifies the user about the occurred event in case it was configured.
 *  \details     -
 *  \pre         -
 *  \param[in]   eventMetaData  Meta data of the event
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FEE_30_FLEXNOR_LOCAL FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_DiagnosticHandler_RaiseEvent(
	Fee_30_FlexNor_EventPublishedInfoType eventMetaData);

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Fee_30_FlexNor_DiagnosticHandler_RaiseEvent()
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
FEE_30_FLEXNOR_LOCAL FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_DiagnosticHandler_RaiseEvent(
	Fee_30_FlexNor_EventPublishedInfoType eventMetaData)
{
	Fee_30_FlexNor_EventPublishedInfoType publishedInfo;
	publishedInfo.currentJobInformation = eventMetaData.currentJobInformation;
	publishedInfo.diagnosticInformation = eventMetaData.diagnosticInformation;

	if(eventMetaData.diagnosticInformation.severity != FEE_30_FLEXNOR_DIAGSEVERITY_INFORMATION)
	{	
		Fee_30_FlexNor_DiagnosticIdType diagnosticId = eventMetaData.diagnosticInformation.diagnosticId;
		Fee_30_FlexNor_DiagnosticHandlerContext.eventMask |= ((uint32) 1u << (uint32) diagnosticId);

		Fee_30_FlexNor_DiagnosticHandler_UserCallback(&publishedInfo); /* SBSW_Fee_30_FlexNor_FunctionCallWithPointerToLocal */
	}
#if (FEE_30_FLEXNOR_REPORT_DEBUG_NOTIFICATIONS_ENABLED == STD_ON)
	else
	{
		Fee_30_FlexNor_DiagnosticHandler_UserCallback(&publishedInfo); /* SBSW_Fee_30_FlexNor_FunctionCallWithPointerToLocal */
	}
#endif /* FEE_30_FLEXNOR_REPORT_DEBUG_NOTIFICATIONS_ENABLED == STD_ON */
}

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Fee_30_FlexNor_DiagnosticHandler_Init()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_DiagnosticHandler_Init(void)
{
	Fee_30_FlexNor_DiagnosticHandlerContext.eventMask = 0;
	Fee_30_FlexNor_DiagnosticHandlerContext.currentMilestone = FEE_30_FLEXNOR_DIAGMST_NO_MILESTONE_SET;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_DiagnosticHandler_RaiseError()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
void Fee_30_FlexNor_DiagnosticHandler_RaiseError(Fee_30_FlexNor_DiagnosticIdType diagnosticId)
{
    Fee_30_FlexNor_EventPublishedInfoType currentErrorMetaData;
    currentErrorMetaData.diagnosticInformation.diagnosticId = diagnosticId;
    currentErrorMetaData.diagnosticInformation.severity = FEE_30_FLEXNOR_DIAGSEVERITY_ERROR;
	 currentErrorMetaData.diagnosticInformation.currentMilestone
		= Fee_30_FlexNor_DiagnosticHandlerContext.currentMilestone;

    currentErrorMetaData.currentJobInformation = Fee_30_FlexNor_GetCurrentJobBaseInformation();

    Fee_30_FlexNor_DiagnosticHandler_RaiseEvent(currentErrorMetaData);
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_DiagnosticHandler_RaiseWarning()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
void Fee_30_FlexNor_DiagnosticHandler_RaiseWarning(Fee_30_FlexNor_DiagnosticIdType diagnosticId)
{
    Fee_30_FlexNor_EventPublishedInfoType currentWarningMetaData;
    currentWarningMetaData.diagnosticInformation.diagnosticId = diagnosticId;
    currentWarningMetaData.diagnosticInformation.severity = FEE_30_FLEXNOR_DIAGSEVERITY_WARNING;
	 currentWarningMetaData.diagnosticInformation.currentMilestone

		= Fee_30_FlexNor_DiagnosticHandlerContext.currentMilestone;
    currentWarningMetaData.currentJobInformation = Fee_30_FlexNor_GetCurrentJobBaseInformation();

    Fee_30_FlexNor_DiagnosticHandler_RaiseEvent(currentWarningMetaData);
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_DiagnosticHandler_RaiseInformation()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
void Fee_30_FlexNor_DiagnosticHandler_SetCurrentMilestone(Fee_30_FlexNor_MileStoneIdType currentMilestone)
{
    Fee_30_FlexNor_DiagnosticHandlerContext.currentMilestone = currentMilestone;

    Fee_30_FlexNor_EventPublishedInfoType informationMetaData;
    informationMetaData.diagnosticInformation.diagnosticId = FEE_30_FLEXNOR_DIAGID_NO_ERROR;
    informationMetaData.diagnosticInformation.currentMilestone = currentMilestone;
    informationMetaData.diagnosticInformation.severity = FEE_30_FLEXNOR_DIAGSEVERITY_INFORMATION;
    informationMetaData.currentJobInformation = Fee_30_FlexNor_GetCurrentJobBaseInformation();

    Fee_30_FlexNor_DiagnosticHandler_RaiseEvent(informationMetaData);
}

#if ((FEE_30_FLEXNOR_REPORT_EXCEPTION_ENABLED == STD_OFF) \
    && (FEE_30_FLEXNOR_REPORT_DEBUG_NOTIFICATIONS_ENABLED == STD_OFF))
/**********************************************************************************************************************
 * Fee_30_FlexNor_DiagnosticHandler_UserCallback()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_DiagnosticHandler_UserCallback(
    Fee_30_FlexNor_EventPublishedInfoPtrType publishedInfo)
{
	/* This is a dummy implementation. It makes the Fee compile in case the exception reporting and debug notifications 
	   are disabled and the user does not implement the callback. */
	FEE_DUMMY_STATEMENT(publishedInfo);
}
#endif /* (FEE_30_FLEXNOR_REPORT_EXCEPTION_ENABLED == STD_OFF) \
          && (FEE_30_FLEXNOR_REPORT_DEBUG_NOTIFICATIONS_ENABLED == STD_OFF) */

#define FEE_30_FLEXNOR_STOP_SEC_CODE
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: Fee_30_FlexNor_DiagnosticHandler.c
 *********************************************************************************************************************/


