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
/*!        \file  Fee_30_FlexNor_Scheduler.c
 *        \brief  Implementation of FEE scheduler
 *      \details  Provides an implementation of the FEE internal unit scheduler that processes registered units.
 *         \unit  Scheduler
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#define FEE_30_FLEXNOR_SCHEDULER_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Fee_30_FlexNor_Scheduler.h"
#include "Fee_30_FlexNor_ConfigInterface.h"
#include "Fee_30_FlexNor_FlashAccess.h"

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

#define FEE_30_FLEXNOR_SCHEDULER_STACK_SIZE (8u)
#define FEE_30_FLEXNOR_SCHEDULER_IDLE_INDEX (-1)

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

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

#define FEE_30_FLEXNOR_START_SEC_VAR_NO_INIT_8
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Indicates if the current job shall be cancelled. */
FEE_30_FLEXNOR_LOCAL boolean Fee_30_FlexNor_CancelRequested;

/*! Indicates if it is allowed to cancel the current job. */
FEE_30_FLEXNOR_LOCAL boolean Fee_30_FlexNor_CancelAllowed;

/*! Counts how many units deny the cancelling of the current job. */
FEE_30_FLEXNOR_LOCAL uint8 Fee_30_FlexNor_CancelDenyCounter;

/*! Index to the function in the ProcessingHandlerStack which is currently processed. */
FEE_30_FLEXNOR_LOCAL sint8 Fee_30_FlexNor_CurrentProcessingIndex;

#define FEE_30_FLEXNOR_STOP_SEC_VAR_NO_INIT_8
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define FEE_30_FLEXNOR_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Stores the processing functions of the currently active unit. */
FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_ProcessingHandler 
    Fee_30_FlexNor_ProcessingHandlerStack[FEE_30_FLEXNOR_SCHEDULER_STACK_SIZE] = { 0u }; 

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
 * Fee_30_FlexNor_Scheduler_DummyHandler()
 *********************************************************************************************************************/
/*! \brief       Dummy processing handler
 *  \details     Dummy handler to catch faulty processing calls.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Scheduler_DummyHandler(void);

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * Fee_30_FlexNor_Scheduler_DummyHandler()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Scheduler_DummyHandler(void)
{
    return FEE_30_FLEXNOR_STOP_SCHEDULE;
}

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * Fee_30_FlexNor_Scheduler_Init()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Scheduler_Init(void)
{
    Fee_30_FlexNor_CurrentProcessingIndex = FEE_30_FLEXNOR_SCHEDULER_IDLE_INDEX;

    for(uint8 stackIndex = 0; stackIndex < FEE_30_FLEXNOR_SCHEDULER_STACK_SIZE; stackIndex++)
    {
        Fee_30_FlexNor_ProcessingHandlerStack[stackIndex] = &Fee_30_FlexNor_Scheduler_DummyHandler; /* SBSW_Fee_30_FlexNor_ModifySchedulerProcessingStack */
    }

    Fee_30_FlexNor_CancelRequested = FALSE;
    Fee_30_FlexNor_CancelAllowed = TRUE;
    Fee_30_FlexNor_CancelDenyCounter = 0;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Scheduler_GetStatus()
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
FUNC(Fee_30_FlexNor_StatusType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Scheduler_GetStatus(void)
{
    Fee_30_FlexNor_StatusType status;

    if(Fee_30_FlexNor_CurrentProcessingIndex > FEE_30_FLEXNOR_SCHEDULER_IDLE_INDEX)
    {
        if(Fee_30_FlexNor_CancelRequested == TRUE)
        {
            status = FEE_30_FLEXNOR_CANCELLING;
        }
        else 
        {
            status = FEE_30_FLEXNOR_BUSY;
        }
    }
    else 
    {
        status = FEE_30_FLEXNOR_IDLE;
    }

    return status;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Scheduler_RegisterUnit()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Scheduler_RegisterUnit(
    Fee_30_FlexNor_ProcessingHandler processingHandler)
{
    Fee_30_FlexNor_CurrentProcessingIndex++;
    Fee_30_FlexNor_ProcessingHandlerStack[Fee_30_FlexNor_CurrentProcessingIndex] = processingHandler; /* SBSW_Fee_30_FlexNor_ModifySchedulerProcessingStack */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Scheduler_UnregisterUnit()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Scheduler_UnregisterUnit(void)
{
    Fee_30_FlexNor_ProcessingHandlerStack[Fee_30_FlexNor_CurrentProcessingIndex] 
        = &Fee_30_FlexNor_Scheduler_DummyHandler; /* SBSW_Fee_30_FlexNor_ModifySchedulerProcessingStack */
    Fee_30_FlexNor_CurrentProcessingIndex--;

    if(Fee_30_FlexNor_Scheduler_GetStatus() == FEE_30_FLEXNOR_IDLE)
    {
        Fee_30_FlexNor_CancelRequested = FALSE;
    }
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Scheduler_Schedule()
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
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Scheduler_Schedule(void)
{
    Fee_30_FlexNor_ScheduleBehaviorType scheduleBehavior = FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
    
    while((scheduleBehavior == FEE_30_FLEXNOR_CONTINUE_SCHEDULE) && (Fee_30_FlexNor_CurrentProcessingIndex > -1))
    {
        if((Fee_30_FlexNor_CancelRequested == TRUE) && (Fee_30_FlexNor_CancelAllowed == TRUE))
        {
            Fee_30_FlexNor_Scheduler_Init();
            Fee_30_FlexNor_FlashAccess_Cancel(); 
            break;
        }

        scheduleBehavior = Fee_30_FlexNor_ProcessingHandlerStack[Fee_30_FlexNor_CurrentProcessingIndex](); /* SBSW_Fee_30_FlexNor_CallProcessingHandler */
    }
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Scheduler_AllowCancel()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Scheduler_AllowCancel(void)
{
    if(Fee_30_FlexNor_CancelDenyCounter > 0u)
    {
        Fee_30_FlexNor_CancelDenyCounter -= 1u;
    }

    if(Fee_30_FlexNor_CancelDenyCounter == 0u)
    {
        Fee_30_FlexNor_CancelAllowed = TRUE;
    }
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Scheduler_DenyCancel()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Scheduler_DenyCancel(void)
{
    Fee_30_FlexNor_CancelAllowed = FALSE;
    Fee_30_FlexNor_CancelDenyCounter += 1u;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Scheduler_Cancel()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Scheduler_Cancel(void)
{
    if(Fee_30_FlexNor_CancelAllowed == TRUE)
    {
        Fee_30_FlexNor_Scheduler_Init();
    }
    else
    {
        Fee_30_FlexNor_CancelRequested = TRUE;
    }
}

#define FEE_30_FLEXNOR_STOP_SEC_CODE
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: Fee_30_FlexNor_Scheduler.c
 *********************************************************************************************************************/
