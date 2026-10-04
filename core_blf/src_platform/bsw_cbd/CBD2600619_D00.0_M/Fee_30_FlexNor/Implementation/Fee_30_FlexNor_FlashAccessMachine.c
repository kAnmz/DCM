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
/*!        \file  Fee_30_FlexNor_FlashAccessMachine.c
 *        \brief  Flash access state machine implementation
 *      \details  Provides the implementation of the state machine logic for the flash access unit.
 *         \unit  FlashAccess
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#define FEE_30_FLEXNOR_FLASHACCESSMACHINE_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Fee_30_FlexNor_FlashAccessMachine.h"
#include "Fee_30_FlexNor_ConfigInterface.h"
#include "Fee_30_FlexNor_SectorContainer.h"
#include "Fee_30_FlexNor_DiagnosticHandler.h"

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
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/
#define FEE_30_FLEXNOR_START_SEC_CONST_UNSPECIFIED
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_FlashAccess_ConstStateType Fee_30_FlexNor_FlashAccessDefaultState = { /* PRQA S 3218 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
    &Fee_30_FlexNor_FlashAccess_DefaultProcessEvent
};
FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_FlashAccess_ConstStateType Fee_30_FlexNor_FlashAccessWaitUntilIdle = { /* PRQA S 3218 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
    &Fee_30_FlexNor_FlashAccess_WaitUntilIdle_ProcessEvent
};
FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_FlashAccess_ConstStateType Fee_30_FlexNor_FlashAccessReadFlashState = { /* PRQA S 3218 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
    &Fee_30_FlexNor_FlashAccess_ReadFlash_ProcessEvent
};
FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_FlashAccess_ConstStateType Fee_30_FlexNor_FlashAccessBlankCheckState = { /* PRQA S 3218 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
    &Fee_30_FlexNor_FlashAccess_BlankCheck_ProcessEvent
};
FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_FlashAccess_ConstStateType Fee_30_FlexNor_FlashAccessWriteFlashState = { /* PRQA S 3218 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
    &Fee_30_FlexNor_FlashAccess_WriteFlash_ProcessEvent
};
FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_FlashAccess_ConstStateType Fee_30_FlexNor_FlashAccessEraseFlashState = { /* PRQA S 3218 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
    &Fee_30_FlexNor_FlashAccess_EraseFlash_ProcessEvent
};

#define FEE_30_FLEXNOR_STOP_SEC_CONST_UNSPECIFIED
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define FEE_30_FLEXNOR_START_SEC_CODE
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Fee_30_FlexNor_FlashAccess_CheckJobProgress()
 *********************************************************************************************************************/
/*! \brief          Check the job progress
 *  \details        Checks the progress of the currently running flash job and ends the job if the flash job was completed.
 *  \param[in,out]  ctx                                Context the progress check shall be executed in. Must not be NULL.
 *  \return         FEE_30_FLEXNOR_STOP_SCHEDULE       In case the scheduling shall be stopped
 *                  FEE_30_FLEXNOR_CONTINUE_SCHEDULE   In case the scheduling can be continued
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FEE_30_FLEXNOR_LOCAL FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) 
    Fee_30_FlexNor_FlashAccess_CheckJobProgress(Fee_30_FlexNor_FlashAccess_ContextPtrType ctx, boolean isReadJob);

/**********************************************************************************************************************
 * Fee_30_FlexNor_FlashAccess_ProcessJobSetupResult()
 *********************************************************************************************************************/
/*! \brief       Processes the job setup result
 *  \details     Handels the result of the job setup of the underlying flash driver.
 *  \param[in]   ctx                       Context the setup result is processed in. Must not be NULL.
 *  \param[in]   setupResult               Result of the job setup at the underlying flash driver
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FEE_30_FLEXNOR_LOCAL FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_FlashAccess_ProcessJobSetupResult(
    Fee_30_FlexNor_FlashAccess_ContextPtrType ctx,
    Std_ReturnType setupResult);

/**********************************************************************************************************************
 * Fee_30_FlexNor_FlashAccess_TransitionToRead()
 *********************************************************************************************************************/
/*! \brief       Transitions to the the first state of the read job.
 *  \details     Transitions to the ReadFlash state or, if required, to the BlankCheck state.
 *  \param[out]  ctx                       Context the setup result is processed in. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FEE_30_FLEXNOR_LOCAL FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_FlashAccess_TransitionToRead(
    Fee_30_FlexNor_FlashAccess_ContextPtrType ctx);

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * Fee_30_FlexNor_FlashAccess_CheckJobProgress()
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
FEE_30_FLEXNOR_LOCAL FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE)
    Fee_30_FlexNor_FlashAccess_CheckJobProgress(Fee_30_FlexNor_FlashAccess_ContextPtrType ctx, boolean isReadJob)
{
    Fee_30_FlexNor_ScheduleBehaviorType scheduleBehavior = FEE_30_FLEXNOR_STOP_SCHEDULE;
    Fee_30_FlexNor_FlashAccess_FlashResultType jobResult = Fee_30_FlexNor_FlashAccess_CheckJobResult(ctx, isReadJob); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */

    if(jobResult != FEE_30_FLEXNOR_FLASH_PENDING)
    {
        Fee_30_FlexNor_ServiceResult callbackResult 
            = (jobResult == FEE_30_FLEXNOR_FLASH_OK) ? FEE_30_FLEXNOR_SERVICE_OK : FEE_30_FLEXNOR_SERVICE_FAIL;

        ctx->CurrentState = &Fee_30_FlexNor_FlashAccessDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        Fee_30_FlexNor_FlashAccess_EndJob();

        if((isReadJob == TRUE) && (jobResult == FEE_30_FLEXNOR_FLASH_FAIL))
        {
            Fee_30_FlexNor_DiagnosticHandler_RaiseError(FEE_30_FLEXNOR_DIAGID_SPONTANEOUSREADFAIL);
        }

        /* ReadJobResult is used in the result callback. So it is set before the result callback invoked. */
        ctx->ReadJobResult = jobResult; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        ctx->ResultCallback(callbackResult); /* SBSW_Fee_30_FlexNor_ContextFunctionPointerCall */
		
        scheduleBehavior = FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
    }

    return scheduleBehavior;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_FlashAccess_ProcessJobSetupResult()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FEE_30_FLEXNOR_LOCAL FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_FlashAccess_ProcessJobSetupResult(
    Fee_30_FlexNor_FlashAccess_ContextPtrType ctx,
    Std_ReturnType setupResult)
{
    if(setupResult != E_OK)
    {
        Fee_30_FlexNor_FlashAccess_EndJob();
        Fee_30_FlexNor_FlashAccess_InitState(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */

        ctx->ResultCallback(FEE_30_FLEXNOR_SERVICE_FAIL); /* SBSW_Fee_30_FlexNor_ContextFunctionPointerCall */
    }
#if(FEE_30_FLEXNOR_CFG_POLLING_MODE == STD_OFF)
    else
    {
        ctx->FlashJobStatus = FEE_30_FLEXNOR_BUSY; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    }
#endif
}


/**********************************************************************************************************************
 * Fee_30_FlexNor_FlashAccess_TransitionToRead()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FEE_30_FLEXNOR_LOCAL FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_FlashAccess_TransitionToRead(
    Fee_30_FlexNor_FlashAccess_ContextPtrType ctx)
{
    Fee_30_FlexNor_ConstPartitionConfigPtrType partitionConfig =
								Fee_30_FlexNor_ConfigInterface_GetPartitionConfig(ctx->PartitionId);

    if(partitionConfig->BlankCheckRequired == TRUE)
    {
        ctx->CurrentState = &Fee_30_FlexNor_FlashAccessBlankCheckState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        Fee_30_FlexNor_FlashAccess_BlankCheck_OnEnter(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }
    else
    {
        ctx->CurrentState = &Fee_30_FlexNor_FlashAccessReadFlashState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        Fee_30_FlexNor_FlashAccess_ReadFlash_OnEnter(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }
}

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * Fee_30_FlexNor_FlashAccess_InitState()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_FlashAccess_InitState(Fee_30_FlexNor_FlashAccess_ContextPtrType ctx)
{
    ctx->CurrentState = &Fee_30_FlexNor_FlashAccessDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_FlashAccess_DefaultProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_FlashAccess_DefaultProcessEvent(
    Fee_30_FlexNor_FlashAccess_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    FEE_DUMMY_STATEMENT(ctx);
    return FEE_30_FLEXNOR_STOP_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_FlashAccess_InitializeJob()
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
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_FlashAccess_InitializeJob(Fee_30_FlexNor_FlashAccess_ContextPtrType ctx)
{
    Fee_30_FlexNor_ConstSectorPtrType sector = Fee_30_FlexNor_SectorContainer_GetSectorByAddress(
        ctx->PartitionId, ctx->JobAddress);

    if ((sector == NULL_PTR) || ((ctx->JobAddress + ctx->JobLength) > (sector->StartAddress + sector->Length))) 
    {
        Fee_30_FlexNor_DiagnosticHandler_RaiseError(FEE_30_FLEXNOR_DIAGID_ILLEGALADDRESS);
        
        /* ReadJobResult is used in the result callback. So it is set before the result callback invoked. */
        ctx->ReadJobResult = FEE_30_FLEXNOR_FLASH_FAIL; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        ctx->ResultCallback(FEE_30_FLEXNOR_SERVICE_FAIL); /* SBSW_Fee_30_FlexNor_ContextFunctionPointerCall */
    }
    else
    {
        ctx->CurrentState = &Fee_30_FlexNor_FlashAccessWaitUntilIdle; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        Fee_30_FlexNor_FlashAccess_StartJob();

        Fee_30_FlexNor_FlashAccess_WaitUntilIdle_OnEnter(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }
}
/**********************************************************************************************************************
 * Fee_30_FlexNor_FlashAccess_WaitUntilIdle_OnEnter()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_FlashAccess_WaitUntilIdle_OnEnter(
    Fee_30_FlexNor_FlashAccess_ContextPtrType ctx)
{
    (void) Fee_30_FlexNor_FlashAccess_WaitUntilIdle_ProcessEvent(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_FlashAccess_WaitUntilIdle_ProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE)
    Fee_30_FlexNor_FlashAccess_WaitUntilIdle_ProcessEvent(Fee_30_FlexNor_FlashAccess_ContextPtrType ctx)
{
    Fee_30_FlexNor_ScheduleBehaviorType scheduleBehavior = FEE_30_FLEXNOR_STOP_SCHEDULE;
    Fee_30_FlexNor_FlashAccess_FlashResultType jobResult 
        = Fee_30_FlexNor_FlashAccess_CheckJobResult(ctx, /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
            FALSE /* Parameter irrelevant because this is only a pending check. */ ); 

    if((jobResult != FEE_30_FLEXNOR_FLASH_PENDING) && ((ctx->SuspendWritesEnabled == FALSE)
        || (ctx->RequestedJob == FEE_30_FLEXNOR_FLASHACCESS_READ)
        || (ctx->RequestedJob == FEE_30_FLEXNOR_FLASHACCESS_READIMMEDIATE)))
    {
        switch(ctx->RequestedJob)
        {
        case FEE_30_FLEXNOR_FLASHACCESS_READ:
            Fee_30_FlexNor_FlashAccess_TransitionToRead(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
            break;

        case FEE_30_FLEXNOR_FLASHACCESS_READIMMEDIATE:
            ctx->CurrentState = &Fee_30_FlexNor_FlashAccessReadFlashState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
            Fee_30_FlexNor_FlashAccess_ReadFlash_OnEnter(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
            break;

        case FEE_30_FLEXNOR_FLASHACCESS_WRITE:
            ctx->CurrentState = &Fee_30_FlexNor_FlashAccessWriteFlashState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
            Fee_30_FlexNor_FlashAccess_WriteFlash_OnEnter(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
            break;

        default: /* FEE_30_FLEXNOR_FLASHACCESS_ERASE */
            ctx->CurrentState = &Fee_30_FlexNor_FlashAccessEraseFlashState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
            Fee_30_FlexNor_FlashAccess_EraseFlash_OnEnter(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
            break;
        }

        scheduleBehavior = FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
    }

    return scheduleBehavior;
}


/**********************************************************************************************************************
 *  Fee_30_FlexNor_FlashAccess_ReadFlash_OnEnter()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_FlashAccess_ReadFlash_OnEnter(
    Fee_30_FlexNor_FlashAccess_ContextPtrType ctx)
{
    Std_ReturnType setupResult = Fee_30_FlexNor_FlashAccess_SetupReadJob(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    Fee_30_FlexNor_FlashAccess_ProcessJobSetupResult(ctx, setupResult); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_FlashAccess_ReadFlash_ProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_FlashAccess_ReadFlash_ProcessEvent(
    Fee_30_FlexNor_FlashAccess_ContextPtrType ctx)
{
    return Fee_30_FlexNor_FlashAccess_CheckJobProgress(ctx, TRUE); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_FlashAccess_BlankCheck_OnEnter()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_FlashAccess_BlankCheck_OnEnter(
    Fee_30_FlexNor_FlashAccess_ContextPtrType ctx)
{
    Std_ReturnType setupResult = Fee_30_FlexNor_FlashAccess_SetupBlankCheck(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    Fee_30_FlexNor_FlashAccess_ProcessJobSetupResult(ctx, setupResult); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_FlashAccess_BlankCheck_ProcessEvent()
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
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_FlashAccess_BlankCheck_ProcessEvent(
    Fee_30_FlexNor_FlashAccess_ContextPtrType ctx)
{
    Fee_30_FlexNor_ScheduleBehaviorType scheduleBehavior = FEE_30_FLEXNOR_STOP_SCHEDULE;
    Fee_30_FlexNor_FlashAccess_FlashResultType jobResult = Fee_30_FlexNor_FlashAccess_CheckJobResult(ctx, FALSE); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */

    if(jobResult != FEE_30_FLEXNOR_FLASH_PENDING)
    {
        Fee_30_FlexNor_BlankCheckResultType blankCheckResult = Fee_30_FlexNor_FlashAccess_IsFlashBlank();

        if(blankCheckResult == FEE_30_FLEXNOR_ISBLANK)
        {
            Fee_30_FlexNor_FlashAccess_SetBufferToErasedValue(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */

            ctx->CurrentState = &Fee_30_FlexNor_FlashAccessDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
            Fee_30_FlexNor_FlashAccess_EndJob();

            ctx->ResultCallback(FEE_30_FLEXNOR_SERVICE_OK); /* SBSW_Fee_30_FlexNor_ContextFunctionPointerCall */
            scheduleBehavior = FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
        }
        else if(blankCheckResult == FEE_30_FLEXNOR_ISNOTBLANK)
        {
            ctx->CurrentState = &Fee_30_FlexNor_FlashAccessReadFlashState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
            Fee_30_FlexNor_FlashAccess_ReadFlash_OnEnter(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */

            scheduleBehavior = FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
        }
        else
        {
            ctx->CurrentState = &Fee_30_FlexNor_FlashAccessDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
            Fee_30_FlexNor_FlashAccess_EndJob();
        
            Fee_30_FlexNor_DiagnosticHandler_RaiseError(FEE_30_FLEXNOR_DIAGID_BLANKCHECK_FAILED);

            /* ReadJobResult is used in the result callback. So it is set before the result callback invoked. */
            ctx->ReadJobResult = FEE_30_FLEXNOR_FLASH_FAIL; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
            ctx->ResultCallback(FEE_30_FLEXNOR_SERVICE_FAIL); /* SBSW_Fee_30_FlexNor_ContextFunctionPointerCall */

            scheduleBehavior = FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
        }
    }

    return scheduleBehavior;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_FlashAccess_WriteFlash_OnEnter()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_FlashAccess_WriteFlash_OnEnter(
    Fee_30_FlexNor_FlashAccess_ContextPtrType ctx)
{
    Std_ReturnType setupResult = Fee_30_FlexNor_FlashAccess_SetupWriteJob(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    Fee_30_FlexNor_FlashAccess_ProcessJobSetupResult(ctx, setupResult); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_FlashAccess_WriteFlash_ProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_FlashAccess_WriteFlash_ProcessEvent(
    Fee_30_FlexNor_FlashAccess_ContextPtrType ctx)
{
    return Fee_30_FlexNor_FlashAccess_CheckJobProgress(ctx, FALSE); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_FlashAccess_EraseFlash_OnEnter()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_FlashAccess_EraseFlash_OnEnter(
    Fee_30_FlexNor_FlashAccess_ContextPtrType ctx)
{
    Std_ReturnType setupResult = Fee_30_FlexNor_FlashAccess_SetupEraseJob(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    Fee_30_FlexNor_FlashAccess_ProcessJobSetupResult(ctx, setupResult); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_FlashAccess_EraseFlash_ProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_FlashAccess_EraseFlash_ProcessEvent(
    Fee_30_FlexNor_FlashAccess_ContextPtrType ctx)
{
    return Fee_30_FlexNor_FlashAccess_CheckJobProgress(ctx, FALSE); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

#define FEE_30_FLEXNOR_STOP_SEC_CODE
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: Fee_30_FlexNor_FlashAccessMachine.c
 *********************************************************************************************************************/
