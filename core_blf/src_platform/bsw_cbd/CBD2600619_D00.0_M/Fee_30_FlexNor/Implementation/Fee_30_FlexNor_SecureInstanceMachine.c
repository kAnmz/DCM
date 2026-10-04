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
/*!        \file  Fee_30_FlexNor_SecureInstanceMachine.c
 *        \brief  Secure instance state machine implementation
 *      \details  Provides the implementation of the state machine logic for the secure instance unit.
 *         \unit  SecureInstance
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#define FEE_30_FLEXNOR_SECUREINSTANCEMACHINE_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Fee_30_FlexNor_SecureInstanceMachine.h"
#include "Fee_30_FlexNor_Scheduler.h"

#if (FEE_30_FLEXNOR_SECURELAYOUT_ENABLED == STD_ON) /* COV_MSR_UT_OPTIONAL_UNIT */

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/
#    if !defined(FEE_30_FLEXNOR_LOCAL) /* COV_FEE_30_FLEXNOR_COMPATIBILITY */
#        define FEE_30_FLEXNOR_LOCAL static
#    endif

#    if !defined(FEE_30_FLEXNOR_LOCAL_INLINE) /* COV_FEE_30_FLEXNOR_COMPATIBILITY */
#        define FEE_30_FLEXNOR_LOCAL_INLINE LOCAL_INLINE
#    endif

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/
#    define FEE_30_FLEXNOR_START_SEC_CONST_UNSPECIFIED
#    include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 3218 1 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_SecureInstance_ConstStateType Fee_30_FlexNor_SecureInstanceDefaultState = {
    &Fee_30_FlexNor_SecureInstance_DefaultProcessEvent,
    &Fee_30_FlexNor_SecureInstance_DefaultFailEvent
};

/* PRQA S 3218 1 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_SecureInstance_ConstStateType Fee_30_FlexNor_SecureInstanceReadMetadataState = {
    &Fee_30_FlexNor_SecureInstance_ReadMetadata_ProcessEvent,
    &Fee_30_FlexNor_SecureInstance_ReadMetadata_FailEvent
};

/* PRQA S 3218 1 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_SecureInstance_ConstStateType Fee_30_FlexNor_SecureInstanceReadStartMarkerState = {
    &Fee_30_FlexNor_SecureInstance_ReadStartMarker_ProcessEvent,
    &Fee_30_FlexNor_SecureInstance_ReadStartMarker_FailEvent
};

/* PRQA S 3218 1 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_SecureInstance_ConstStateType Fee_30_FlexNor_SecureInstanceReadCommitMarkerState = {
    &Fee_30_FlexNor_SecureInstance_ReadCommitMarker_ProcessEvent,
    &Fee_30_FlexNor_SecureInstance_ReadCommitMarker_FailEvent
};

/* PRQA S 3218 1 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_SecureInstance_ConstStateType Fee_30_FlexNor_SecureInstanceReadSealMarkerState = {
    &Fee_30_FlexNor_SecureInstance_ReadSealMarker_ProcessEvent,
    &Fee_30_FlexNor_SecureInstance_ReadSealMarker_FailEvent
};

/* PRQA S 3218 1 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_SecureInstance_ConstStateType Fee_30_FlexNor_SecureInstanceWriteStartMarkerState = {
    &Fee_30_FlexNor_SecureInstance_WriteStartMarker_ProcessEvent,
    &Fee_30_FlexNor_SecureInstance_CancelProtectedWriteFailEvent
};

/* PRQA S 3218 1 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_SecureInstance_ConstStateType Fee_30_FlexNor_SecureInstanceWritePayloadState = {
    &Fee_30_FlexNor_SecureInstance_WritePayload_ProcessEvent,
    &Fee_30_FlexNor_SecureInstance_WriteFailEvent
};

/* PRQA S 3218 1 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_SecureInstance_ConstStateType Fee_30_FlexNor_SecureInstanceWriteSealMarkerState = {
    &Fee_30_FlexNor_SecureInstance_WriteSealMarker_ProcessEvent,
    &Fee_30_FlexNor_SecureInstance_WriteFailEvent
};

/* PRQA S 3218 1 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_SecureInstance_ConstStateType Fee_30_FlexNor_SecureInstanceWriteCommitMarkerState 
= {
    &Fee_30_FlexNor_SecureInstance_WriteCommitMarker_ProcessEvent,
    &Fee_30_FlexNor_SecureInstance_WriteFailEvent
};

/* PRQA S 3218 1 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_SecureInstance_ConstStateType Fee_30_FlexNor_SecureInstanceCopyStartMarkerState = {
    &Fee_30_FlexNor_SecureInstance_CopyStartMarker_ProcessEvent,
    &Fee_30_FlexNor_SecureInstance_CancelProtectedWriteFailEvent
};

/* PRQA S 3218 1 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_SecureInstance_ConstStateType Fee_30_FlexNor_SecureInstanceReadSourceContentState 
= {
    &Fee_30_FlexNor_SecureInstance_ReadSourceContent_ProcessEvent,
    &Fee_30_FlexNor_SecureInstance_JobFailEvent
};

/* PRQA S 3218 1 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_SecureInstance_ConstStateType Fee_30_FlexNor_SecureInstanceWriteTargetContentState 
= {
    &Fee_30_FlexNor_SecureInstance_WriteTargetContent_ProcessEvent,
    &Fee_30_FlexNor_SecureInstance_WriteFailEvent
};

/* PRQA S 3218 1 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_SecureInstance_ConstStateType Fee_30_FlexNor_SecureInstanceCopySealMarkerState = {
    &Fee_30_FlexNor_SecureInstance_CopySealMarker_ProcessEvent,
    &Fee_30_FlexNor_SecureInstance_WriteFailEvent
};

/* PRQA S 3218 1 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_SecureInstance_ConstStateType Fee_30_FlexNor_SecureInstanceCopyCommitMarkerState = {
    &Fee_30_FlexNor_SecureInstance_CopyCommitMarker_ProcessEvent,
    &Fee_30_FlexNor_SecureInstance_WriteFailEvent
};

/* PRQA S 3218 1 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_SecureInstance_ConstStateType Fee_30_FlexNor_SecureInstanceReadStatusState = {
    &Fee_30_FlexNor_SecureInstance_ReadStatus_ProcessEvent,
    &Fee_30_FlexNor_SecureInstance_JobFailEvent
};

/* PRQA S 3218 1 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_SecureInstance_ConstStateType Fee_30_FlexNor_SecureInstanceReadOffsetPage = {
    &Fee_30_FlexNor_SecureInstance_ReadOffsetPage_ProcessEvent,
    &Fee_30_FlexNor_SecureInstance_JobFailEvent
};

/* PRQA S 3218 1 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_SecureInstance_ConstStateType Fee_30_FlexNor_SecureInstanceReadCompletelyFilledPages
 = {
    &Fee_30_FlexNor_SecureInstance_ReadCompletelyFilledPages_ProcessEvent,
    &Fee_30_FlexNor_SecureInstance_JobFailEvent
};

/* PRQA S 3218 1 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_SecureInstance_ConstStateType Fee_30_FlexNor_SecureInstanceReadLastPage
 = {
    &Fee_30_FlexNor_SecureInstance_ReadLastPage_ProcessEvent,
    &Fee_30_FlexNor_SecureInstance_JobFailEvent
};

#    define FEE_30_FLEXNOR_STOP_SEC_CONST_UNSPECIFIED
#    include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#    define FEE_30_FLEXNOR_START_SEC_CODE
#    include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_HandleCorruptedStartMarker()
 *********************************************************************************************************************/
/*! \brief          Do the necessary steps if a corrupted start marker was found.
 *  \details        -
 *  \param[in,out]  ctx                               Pointer to the context for the state machine processing. Must not be NULL.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_HandleCorruptedStartMarker(Fee_30_FlexNor_SecureInstance_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_HandleCorruptedCommitMarker()
 *********************************************************************************************************************/
/*! \brief          Do the necessary steps if a corrupted commit marker was found.
 *  \details        -
 *  \param[in,out]  ctx                               Pointer to the context for the state machine processing. Must not be NULL.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_HandleCorruptedCommitMarker(Fee_30_FlexNor_SecureInstance_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_HandleCorruptedSealMarker()
 *********************************************************************************************************************/
/*! \brief          Do the necessary steps if a corrupted seal marker was found.
 *  \details        -
 *  \param[in,out]  ctx                               Pointer to the context for the state machine processing. Must not be NULL.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_HandleCorruptedSealMarker(Fee_30_FlexNor_SecureInstance_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_HandleCorruptedStartMarker()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_HandleCorruptedStartMarker(Fee_30_FlexNor_SecureInstance_ContextPtrType ctx)
{
    ctx->Instance.InstanceData->ReallocationRequired = TRUE; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */

    ctx->Instance.InstanceData->Validity = FEE_30_FLEXNOR_INVALID;                     /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    ctx->CurrentState                    = &Fee_30_FlexNor_SecureInstanceDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */

    Fee_30_FlexNor_SecureInstance_EndJob();
    ctx->GenericContext.ResultCallback(FEE_30_FLEXNOR_SERVICE_OK); /* SBSW_Fee_30_FlexNor_ContextFunctionPointerCall */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_HandleCorruptedCommitMarker()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_HandleCorruptedCommitMarker(Fee_30_FlexNor_SecureInstance_ContextPtrType ctx)
{
    ctx->Instance.InstanceData->ReallocationRequired = TRUE; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */

    ctx->Instance.InstanceData->Validity = FEE_30_FLEXNOR_VALID;                       /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    ctx->CurrentState                    = &Fee_30_FlexNor_SecureInstanceDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */

    Fee_30_FlexNor_SecureInstance_EndJob();
    ctx->GenericContext.ResultCallback(FEE_30_FLEXNOR_SERVICE_OK); /* SBSW_Fee_30_FlexNor_ContextFunctionPointerCall */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_HandleCorruptedSealMarker()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_HandleCorruptedSealMarker(Fee_30_FlexNor_SecureInstance_ContextPtrType ctx)
{
    ctx->Instance.InstanceData->Validity = FEE_30_FLEXNOR_INVALID;                     /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    ctx->CurrentState = &Fee_30_FlexNor_SecureInstanceDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */

    Fee_30_FlexNor_SecureInstance_EndJob();
    ctx->GenericContext.ResultCallback(FEE_30_FLEXNOR_SERVICE_OK); /* SBSW_Fee_30_FlexNor_ContextFunctionPointerCall */
}

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_InitState()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_InitState(Fee_30_FlexNor_SecureInstance_ContextPtrType ctx)
{
    ctx->CurrentState = &Fee_30_FlexNor_SecureInstanceDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_DefaultProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_DefaultProcessEvent(
    Fee_30_FlexNor_SecureInstance_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    FEE_DUMMY_STATEMENT(ctx);
    return FEE_30_FLEXNOR_STOP_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_DefaultFailEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_DefaultFailEvent(
    Fee_30_FlexNor_SecureInstance_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    FEE_DUMMY_STATEMENT(ctx);
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_ReadMetadata_FailEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_ReadMetadata_FailEvent(
    Fee_30_FlexNor_SecureInstance_ContextPtrType ctx)
{
    if(Fee_30_FlexNor_FlashAccess_GetReadJobResult() == FEE_30_FLEXNOR_FLASH_ECCERROR)
    {
        ctx->CurrentState = &Fee_30_FlexNor_SecureInstanceReadStartMarkerState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        Fee_30_FlexNor_SecureInstance_ReadStartMarker(ctx);                     /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }
    else /* FEE_30_FLEXNOR_FLASH_FAIL */
    {
        Fee_30_FlexNor_SecureInstance_JobFailEvent(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_ReadStartMarker_FailEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_ReadStartMarker_FailEvent(
    Fee_30_FlexNor_SecureInstance_ContextPtrType ctx)
{
    if(Fee_30_FlexNor_FlashAccess_GetReadJobResult() == FEE_30_FLEXNOR_FLASH_ECCERROR)
    {
        Fee_30_FlexNor_SecureInstance_HandleCorruptedStartMarker(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }
    else /* FEE_30_FLEXNOR_FLASH_FAIL */
    {
        Fee_30_FlexNor_SecureInstance_JobFailEvent(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_ReadCommitMarker_FailEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_ReadCommitMarker_FailEvent(
    Fee_30_FlexNor_SecureInstance_ContextPtrType ctx)
{
    if(Fee_30_FlexNor_FlashAccess_GetReadJobResult() == FEE_30_FLEXNOR_FLASH_ECCERROR)
    {
        Fee_30_FlexNor_SecureInstance_HandleCorruptedCommitMarker(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }
    else /* FEE_30_FLEXNOR_FLASH_FAIL */
    {
        Fee_30_FlexNor_SecureInstance_JobFailEvent(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_ReadSealMarker_FailEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_ReadSealMarker_FailEvent(
    Fee_30_FlexNor_SecureInstance_ContextPtrType ctx)
{
    if(Fee_30_FlexNor_FlashAccess_GetReadJobResult() == FEE_30_FLEXNOR_FLASH_ECCERROR)
    {
        Fee_30_FlexNor_SecureInstance_HandleCorruptedSealMarker(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }
    else /* FEE_30_FLEXNOR_FLASH_FAIL */
    {
        Fee_30_FlexNor_SecureInstance_JobFailEvent(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_JobFailEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_JobFailEvent(Fee_30_FlexNor_SecureInstance_ContextPtrType ctx)
{
    ctx->CurrentState = &Fee_30_FlexNor_SecureInstanceDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_SecureInstance_EndJob();
    ctx->GenericContext.ResultCallback(FEE_30_FLEXNOR_SERVICE_FAIL); /* SBSW_Fee_30_FlexNor_ContextFunctionPointerCall */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_WriteFailEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_WriteFailEvent(Fee_30_FlexNor_SecureInstance_ContextPtrType ctx)
{
    Fee_30_FlexNor_Instance_RequestRecoveryGarbageCollection(
        ctx->GenericContext.PartitionConfig->PartitionId,
        ctx->Instance.ConstInstanceData->StartAddress
    );

    ctx->CurrentState = &Fee_30_FlexNor_SecureInstanceDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_SecureInstance_EndJob();
    ctx->GenericContext.ResultCallback(FEE_30_FLEXNOR_SERVICE_FAIL); /* SBSW_Fee_30_FlexNor_ContextFunctionPointerCall */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_CancelProtectedWriteFailEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_CancelProtectedWriteFailEvent(Fee_30_FlexNor_SecureInstance_ContextPtrType ctx)
{
    Fee_30_FlexNor_Scheduler_AllowCancel();
    Fee_30_FlexNor_SecureInstance_WriteFailEvent(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_Validate_Initialize()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_Validate_Initialize(Fee_30_FlexNor_SecureInstance_ContextPtrType ctx)
{
    Fee_30_FlexNor_SecureInstance_StartJob();

    ctx->CurrentState = &Fee_30_FlexNor_SecureInstanceReadMetadataState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_SecureInstance_ReadInstanceMetadata(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_ReadMetadata_ProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_ReadMetadata_ProcessEvent(
    Fee_30_FlexNor_SecureInstance_ContextPtrType ctx)
{
    ctx->Instance.InstanceData->Validity = Fee_30_FlexNor_SecureInstance_ValidateInstanceMetadata(ctx); /* SBSW_Fee_30_FlexNor_ContextPointerAccess */ /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */

    ctx->CurrentState = &Fee_30_FlexNor_SecureInstanceDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_SecureInstance_EndJob();

    ctx->GenericContext.ResultCallback(FEE_30_FLEXNOR_SERVICE_OK); /* SBSW_Fee_30_FlexNor_ContextFunctionPointerCall */
    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_ReadStartMarker_ProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_ReadStartMarker_ProcessEvent(
    Fee_30_FlexNor_SecureInstance_ContextPtrType ctx)
{
    Fee_30_FlexNor_StructureValidityType startMarkerValidity = 
        Fee_30_FlexNor_SecureInstance_ValidateStartMarker(ctx, 0u); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
        
    if(startMarkerValidity == FEE_30_FLEXNOR_VALID)
    {
        ctx->CurrentState = &Fee_30_FlexNor_SecureInstanceReadCommitMarkerState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        Fee_30_FlexNor_SecureInstance_ReadCommitMarker(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }
    else if(startMarkerValidity == FEE_30_FLEXNOR_EMPTY)
    {
        ctx->Instance.InstanceData->Validity = FEE_30_FLEXNOR_EMPTY; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        ctx->CurrentState = &Fee_30_FlexNor_SecureInstanceDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */

        Fee_30_FlexNor_SecureInstance_EndJob();
        ctx->GenericContext.ResultCallback(FEE_30_FLEXNOR_SERVICE_OK); /* SBSW_Fee_30_FlexNor_ContextFunctionPointerCall */
    }
    else
    {
        Fee_30_FlexNor_SecureInstance_HandleCorruptedStartMarker(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }    
    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_ReadCommitMarker_ProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_ReadCommitMarker_ProcessEvent(
    Fee_30_FlexNor_SecureInstance_ContextPtrType ctx)
{
    Fee_30_FlexNor_StructureValidityType commitMarkerValidity = 
        Fee_30_FlexNor_SecureInstance_ValidateCommitMarker(ctx, 0u); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
        
    if (commitMarkerValidity == FEE_30_FLEXNOR_VALID)
    {
        ctx->Instance.InstanceData->Validity = FEE_30_FLEXNOR_VALID; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        ctx->CurrentState = &Fee_30_FlexNor_SecureInstanceDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */

        Fee_30_FlexNor_SecureInstance_EndJob();
        ctx->GenericContext.ResultCallback(FEE_30_FLEXNOR_SERVICE_OK); /* SBSW_Fee_30_FlexNor_ContextFunctionPointerCall */
    }
    else if(commitMarkerValidity == FEE_30_FLEXNOR_EMPTY)
    {
        ctx->CurrentState = &Fee_30_FlexNor_SecureInstanceReadSealMarkerState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        Fee_30_FlexNor_SecureInstance_ReadSealMarker(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }
    else
    {
        Fee_30_FlexNor_SecureInstance_HandleCorruptedCommitMarker(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }
    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_ReadSealMarker_ProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_ReadSealMarker_ProcessEvent(
    Fee_30_FlexNor_SecureInstance_ContextPtrType ctx)
{
    Fee_30_FlexNor_StructureValidityType sealMarkerValidity = 
        Fee_30_FlexNor_SecureInstance_ValidateSealMarker(ctx, 0u); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    if (sealMarkerValidity == FEE_30_FLEXNOR_VALID)
    {
        ctx->Instance.InstanceData->ReallocationRequired = TRUE; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */

        ctx->Instance.InstanceData->Validity = FEE_30_FLEXNOR_VALID; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        ctx->CurrentState = &Fee_30_FlexNor_SecureInstanceDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */

        Fee_30_FlexNor_SecureInstance_EndJob();
        ctx->GenericContext.ResultCallback(FEE_30_FLEXNOR_SERVICE_OK); /* SBSW_Fee_30_FlexNor_ContextFunctionPointerCall */
    }
    else
    {
        Fee_30_FlexNor_SecureInstance_HandleCorruptedSealMarker(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }
    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_Write_Initialize()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_Write_Initialize(Fee_30_FlexNor_SecureInstance_ContextPtrType ctx)
{
    Fee_30_FlexNor_SecureInstance_StartJob();
    Fee_30_FlexNor_Scheduler_DenyCancel();

    ctx->CurrentState = &Fee_30_FlexNor_SecureInstanceWriteStartMarkerState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_SecureInstance_WriteStartMarker(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_WriteStartMarker_ProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_WriteStartMarker_ProcessEvent(
    Fee_30_FlexNor_SecureInstance_ContextPtrType ctx)
{
    Fee_30_FlexNor_Scheduler_AllowCancel();
    Fee_30_FlexNor_SecureInstance_WritePayload(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */

    ctx->CurrentState = &Fee_30_FlexNor_SecureInstanceWritePayloadState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_WritePayload_ProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_WritePayload_ProcessEvent(
    Fee_30_FlexNor_SecureInstance_ContextPtrType ctx)
{
    boolean anotherWriteNecessary = Fee_30_FlexNor_Instance_IsAnotherWriteStepNecessary(
        &ctx->GenericContext,
        ctx->Instance.ConstInstanceData); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    if (anotherWriteNecessary == TRUE)
    {
        Fee_30_FlexNor_SecureInstance_WritePayload(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }
    else
    {
        ctx->CurrentState = &Fee_30_FlexNor_SecureInstanceWriteSealMarkerState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        Fee_30_FlexNor_SecureInstance_WriteSealMarker(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }

    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_WriteSealMarker_ProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_WriteSealMarker_ProcessEvent(
    Fee_30_FlexNor_SecureInstance_ContextPtrType ctx)
{
    ctx->CurrentState = &Fee_30_FlexNor_SecureInstanceWriteCommitMarkerState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_SecureInstance_WriteCommitMarker(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_WriteCommitMarker_ProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_WriteCommitMarker_ProcessEvent(
    Fee_30_FlexNor_SecureInstance_ContextPtrType ctx)
{
    ctx->CurrentState = &Fee_30_FlexNor_SecureInstanceDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_SecureInstance_EndJob();

    ctx->GenericContext.ResultCallback(FEE_30_FLEXNOR_SERVICE_OK); /* SBSW_Fee_30_FlexNor_ContextFunctionPointerCall */
    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_Copy_Initialize()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_Copy_Initialize(Fee_30_FlexNor_SecureInstance_ContextPtrType ctx)
{
    Fee_30_FlexNor_SecureInstance_StartJob();
    Fee_30_FlexNor_Scheduler_DenyCancel();

    ctx->CurrentState = &Fee_30_FlexNor_SecureInstanceCopyStartMarkerState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_SecureInstance_WriteStartMarker(ctx);                    /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_CopyStartMarker_ProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_CopyStartMarker_ProcessEvent(
    Fee_30_FlexNor_SecureInstance_ContextPtrType ctx)
{
    Fee_30_FlexNor_Scheduler_AllowCancel();

    ctx->CurrentState = &Fee_30_FlexNor_SecureInstanceReadSourceContentState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_SecureInstance_ReadSourceContent(ctx);                     /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */

    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_ReadSourceContent_ProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) 
    Fee_30_FlexNor_SecureInstance_ReadSourceContent_ProcessEvent(Fee_30_FlexNor_SecureInstance_ContextPtrType ctx)
{
    if (ctx->GenericContext.ContentWritten == 0u)
    {
        ctx->Instance.InstanceData->Status =  Fee_30_FlexNor_Instance_ParseInstanceStatus( /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
            ctx->GenericContext.InstanceBuffer); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }

    ctx->CurrentState = &Fee_30_FlexNor_SecureInstanceWriteTargetContentState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_SecureInstance_WriteTargetContent(ctx);                     /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */

    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_WriteTargetContent_ProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_WriteTargetContent_ProcessEvent(
    Fee_30_FlexNor_SecureInstance_ContextPtrType ctx)
{
    boolean anotherWriteNecessary = Fee_30_FlexNor_Instance_IsAnotherWriteStepNecessary(
        &ctx->GenericContext,
        ctx->Instance.ConstInstanceData); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    if (anotherWriteNecessary == TRUE)
    {
        ctx->CurrentState = &Fee_30_FlexNor_SecureInstanceReadSourceContentState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        Fee_30_FlexNor_SecureInstance_ReadSourceContent(ctx);                     /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }
    else
    {
        ctx->CurrentState = &Fee_30_FlexNor_SecureInstanceCopySealMarkerState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        Fee_30_FlexNor_SecureInstance_WriteSealMarker(ctx);                    /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }

    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_CopySealMarker_ProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_CopySealMarker_ProcessEvent(
    Fee_30_FlexNor_SecureInstance_ContextPtrType ctx)
{
    ctx->CurrentState = &Fee_30_FlexNor_SecureInstanceCopyCommitMarkerState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_SecureInstance_WriteCommitMarker(ctx);                    /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */

    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_CopyCommitMarker_ProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_CopyCommitMarker_ProcessEvent(
    Fee_30_FlexNor_SecureInstance_ContextPtrType ctx)
{
    Fee_30_FlexNor_SecureInstance_EndJob();

    ctx->CurrentState = &Fee_30_FlexNor_SecureInstanceDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    ctx->GenericContext.ResultCallback(FEE_30_FLEXNOR_SERVICE_OK);  /* SBSW_Fee_30_FlexNor_ContextFunctionPointerCall */

    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_ReadContent_Initialize()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_ReadContent_Initialize(Fee_30_FlexNor_SecureInstance_ContextPtrType ctx)
{
    Fee_30_FlexNor_SecureInstance_StartJob();

    Fee_30_FlexNor_LengthType alignedMetadataSize = Fee_30_FlexNor_SecureInstance_GetAlignedMetadataSize( /* SBSW_Fee_30_FlexNor_FunctionCallWithConstPointer */
        ctx->GenericContext.PartitionConfig);

    ctx->CurrentState = &Fee_30_FlexNor_SecureInstanceReadStatusState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_Instance_ReadStatus(ctx->Instance.InstanceData, &ctx->GenericContext, alignedMetadataSize, 
        &Fee_30_FlexNor_SecureInstance_ResultHandler); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_ReadStatus_ProcessEvent()
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
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_ReadStatus_ProcessEvent(
    Fee_30_FlexNor_SecureInstance_ContextPtrType ctx)
{
    ctx->Instance.InstanceData->Status /* SBSW_Fee_30_FlexNor_ParamPointerWriteAccess */
        = Fee_30_FlexNor_Instance_ParseInstanceStatus(ctx->GenericContext.InstanceBuffer); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */

    if (ctx->Instance.InstanceData->Status == FEE_30_FLEXNOR_INSTANCE_VALID)
    {
        Fee_30_FlexNor_Instance_CopyDataFromStatusPageInUserBuffer(  /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
            ctx->Instance.InstanceData, &ctx->GenericContext);
        
        Fee_30_FlexNor_LengthType metaDataSize = Fee_30_FlexNor_SecureInstance_GetAlignedMetadataSize( /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
            ctx->GenericContext.PartitionConfig);

        ctx->CurrentState = &Fee_30_FlexNor_SecureInstanceReadOffsetPage; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        boolean isJobPending = Fee_30_FlexNor_Instance_ReadOffsetPage(
            ctx->Instance.InstanceData, &ctx->GenericContext, metaDataSize, 
            &Fee_30_FlexNor_SecureInstance_ResultHandler); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */

        if(isJobPending == FALSE)
        {
            (void) Fee_30_FlexNor_SecureInstance_ReadOffsetPage_ProcessEvent(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
        }
    }
    else
    {
        Fee_30_FlexNor_SecureInstance_EndJob();

        ctx->CurrentState = &Fee_30_FlexNor_SecureInstanceDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        ctx->GenericContext.ResultCallback(FEE_30_FLEXNOR_SERVICE_OK);  /* SBSW_Fee_30_FlexNor_ContextFunctionPointerCall */
    }

    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_ReadOffsetPage_ProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_ReadOffsetPage_ProcessEvent(
    Fee_30_FlexNor_SecureInstance_ContextPtrType ctx)
{
    Fee_30_FlexNor_LengthType metaDataSize = Fee_30_FlexNor_SecureInstance_GetAlignedMetadataSize( /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
        ctx->GenericContext.PartitionConfig);

    Fee_30_FlexNor_Instance_CopyDataFromOffsetPageInUserBuffer(  /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
        ctx->Instance.InstanceData, &ctx->GenericContext, metaDataSize);

    ctx->CurrentState = &Fee_30_FlexNor_SecureInstanceReadCompletelyFilledPages; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    boolean isFlashJobRequested = Fee_30_FlexNor_Instance_ReadCompletelyFilledPages(  /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
        ctx->Instance.InstanceData, &ctx->GenericContext, metaDataSize, &Fee_30_FlexNor_SecureInstance_ResultHandler);

    if(isFlashJobRequested == FALSE)
    {
        (void) Fee_30_FlexNor_SecureInstance_ReadCompletelyFilledPages_ProcessEvent(ctx);  /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }

    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_ReadCompletelyFilledPages_ProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) 
    Fee_30_FlexNor_SecureInstance_ReadCompletelyFilledPages_ProcessEvent(
        Fee_30_FlexNor_SecureInstance_ContextPtrType ctx)
{
    Fee_30_FlexNor_LengthType metaDataSize = Fee_30_FlexNor_SecureInstance_GetAlignedMetadataSize(  /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
        ctx->GenericContext.PartitionConfig);

    ctx->CurrentState = &Fee_30_FlexNor_SecureInstanceReadLastPage; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    boolean isFlashJobRequested = Fee_30_FlexNor_Instance_ReadLastPage( /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
        ctx->Instance.InstanceData, &ctx->GenericContext, metaDataSize, &Fee_30_FlexNor_SecureInstance_ResultHandler);

    if(isFlashJobRequested == FALSE)
    {
        Fee_30_FlexNor_SecureInstance_EndJob();

        ctx->CurrentState = &Fee_30_FlexNor_SecureInstanceDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        ctx->GenericContext.ResultCallback(FEE_30_FLEXNOR_SERVICE_OK);  /* SBSW_Fee_30_FlexNor_ContextFunctionPointerCall */
    }

    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_ReadLastPage_ProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) 
    Fee_30_FlexNor_SecureInstance_ReadLastPage_ProcessEvent(
        Fee_30_FlexNor_SecureInstance_ContextPtrType ctx)
{
    Fee_30_FlexNor_Instance_CopyDataFromLastPageInUserBuffer(ctx->Instance.InstanceData, &ctx->GenericContext); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */

    Fee_30_FlexNor_SecureInstance_EndJob();

    ctx->CurrentState = &Fee_30_FlexNor_SecureInstanceDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    ctx->GenericContext.ResultCallback(FEE_30_FLEXNOR_SERVICE_OK);  /* SBSW_Fee_30_FlexNor_ContextFunctionPointerCall */

    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

#    define FEE_30_FLEXNOR_STOP_SEC_CODE
#    include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif

/**********************************************************************************************************************
 *  END OF FILE: Fee_30_FlexNor_SecureInstanceMachine.c
 *********************************************************************************************************************/
