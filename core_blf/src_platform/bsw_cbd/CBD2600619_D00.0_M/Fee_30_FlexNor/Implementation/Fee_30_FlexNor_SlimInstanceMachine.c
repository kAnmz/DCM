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
/*!        \file  Fee_30_FlexNor_SlimInstanceMachine.c
 *        \brief  Slim instance state machine implementation
 *      \details  Provides the implementation of the state machine logic for the slim instance unit.
 *         \unit  SlimInstance
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#define FEE_30_FLEXNOR_SLIMINSTANCEMACHINE_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Fee_30_FlexNor_SlimInstanceMachine.h"
#include "Fee_30_FlexNor_Scheduler.h"
#include "Fee_30_FlexNor_Shared.h"

#if (FEE_30_FLEXNOR_SLIMLAYOUT_ENABLED == STD_ON) /* COV_MSR_UT_OPTIONAL_UNIT */

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

FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_SlimInstance_ConstStateType Fee_30_FlexNor_SlimInstanceDefaultState = {
    &Fee_30_FlexNor_SlimInstance_DefaultProcessEvent,
    &Fee_30_FlexNor_SlimInstance_DefaultFailEvent
};

/* PRQA S 3218 1 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_SlimInstance_ConstStateType Fee_30_FlexNor_SlimInstanceReadMetadataState = {
    &Fee_30_FlexNor_SlimInstance_ReadMetadata_ProcessEvent,
    &Fee_30_FlexNor_SlimInstance_ReadMetaDataFailEvent
};

/* PRQA S 3218 1 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_SlimInstance_ConstStateType Fee_30_FlexNor_SlimInstanceReadCommitMarkerState = {
    &Fee_30_FlexNor_SlimInstance_ReadCommitMarker_ProcessEvent,
    &Fee_30_FlexNor_SlimInstance_ReadCommitMarkerFailEvent
};

/* PRQA S 3218 1 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_SlimInstance_ConstStateType Fee_30_FlexNor_SlimInstanceReadStatusForValidationState = {
    &Fee_30_FlexNor_SlimInstance_ReadStatusForValidation_ProcessEvent,
    &Fee_30_FlexNor_SlimInstance_ReadStatusForValidationFailEvent
};

/* PRQA S 3218 1 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_SlimInstance_ConstStateType Fee_30_FlexNor_SlimInstanceWritePayloadState = {
    &Fee_30_FlexNor_SlimInstance_WritePayload_ProcessEvent,
    &Fee_30_FlexNor_SlimInstance_CancelProtectedWriteFailEvent
};

/* PRQA S 3218 1 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_SlimInstance_ConstStateType Fee_30_FlexNor_SlimInstanceWriteCommitMarkerState = {
    &Fee_30_FlexNor_SlimInstance_WriteCommitMarker_ProcessEvent,
    &Fee_30_FlexNor_SlimInstance_WriteFailEvent
};

/* PRQA S 3218 1 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_SlimInstance_ConstStateType Fee_30_FlexNor_SlimInstanceReadSourceContentState = {
    &Fee_30_FlexNor_SlimInstance_ReadSourceContent_ProcessEvent,
    &Fee_30_FlexNor_SlimInstance_CancelProtectedJobFailEvent
};

/* PRQA S 3218 1 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_SlimInstance_ConstStateType Fee_30_FlexNor_SlimInstanceWriteTargetContentState = {
    &Fee_30_FlexNor_SlimInstance_WriteTargetContent_ProcessEvent,
    &Fee_30_FlexNor_SlimInstance_CancelProtectedWriteFailEvent
};

/* PRQA S 3218 1 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_SlimInstance_ConstStateType Fee_30_FlexNor_SlimInstanceCopyCommitMarkerState = {
    &Fee_30_FlexNor_SlimInstance_CopyCommitMarker_ProcessEvent,
    &Fee_30_FlexNor_SlimInstance_WriteFailEvent
};

/* PRQA S 3218 1 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_SlimInstance_ConstStateType Fee_30_FlexNor_SlimInstanceReadStatusState = {
    &Fee_30_FlexNor_SlimInstance_ReadStatus_ProcessEvent,
    &Fee_30_FlexNor_SlimInstance_JobFailEvent
};

/* PRQA S 3218 1 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_SlimInstance_ConstStateType Fee_30_FlexNor_SlimInstanceReadOffsetPage = {
    &Fee_30_FlexNor_SlimInstance_ReadOffsetPage_ProcessEvent,
    &Fee_30_FlexNor_SlimInstance_JobFailEvent
};

/* PRQA S 3218 1 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_SlimInstance_ConstStateType Fee_30_FlexNor_SlimInstanceReadCompletelyFilledPages
 = {
    &Fee_30_FlexNor_SlimInstance_ReadCompletelyFilledPages_ProcessEvent,
    &Fee_30_FlexNor_SlimInstance_JobFailEvent
};

/* PRQA S 3218 1 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_SlimInstance_ConstStateType Fee_30_FlexNor_SlimInstanceReadLastPage
 = {
    &Fee_30_FlexNor_SlimInstance_ReadLastPage_ProcessEvent,
    &Fee_30_FlexNor_SlimInstance_JobFailEvent
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
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimInstance_InitState()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimInstance_InitState(Fee_30_FlexNor_SlimInstance_ContextPtrType ctx)
{
    ctx->CurrentState = &Fee_30_FlexNor_SlimInstanceDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimInstance_DefaultProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimInstance_DefaultProcessEvent(
    Fee_30_FlexNor_SlimInstance_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    FEE_DUMMY_STATEMENT(ctx);
    return FEE_30_FLEXNOR_STOP_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimInstance_DefaultFailEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimInstance_DefaultFailEvent(
    Fee_30_FlexNor_SlimInstance_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    FEE_DUMMY_STATEMENT(ctx);
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimInstance_JobFailEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimInstance_JobFailEvent(Fee_30_FlexNor_SlimInstance_ContextPtrType ctx)
{
    ctx->CurrentState = &Fee_30_FlexNor_SlimInstanceDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_SlimInstance_EndJob();
    ctx->GenericContext.ResultCallback(FEE_30_FLEXNOR_SERVICE_FAIL); /* SBSW_Fee_30_FlexNor_ContextFunctionPointerCall */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimInstance_WriteFailEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimInstance_WriteFailEvent(Fee_30_FlexNor_SlimInstance_ContextPtrType ctx)
{
    Fee_30_FlexNor_Instance_RequestRecoveryGarbageCollection(
        ctx->GenericContext.PartitionConfig->PartitionId,
        ctx->Instance.ConstInstanceData->StartAddress
    );

    ctx->CurrentState = &Fee_30_FlexNor_SlimInstanceDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_SlimInstance_EndJob();
    ctx->GenericContext.ResultCallback(FEE_30_FLEXNOR_SERVICE_FAIL); /* SBSW_Fee_30_FlexNor_ContextFunctionPointerCall */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimInstance_CancelProtectedWriteFailEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimInstance_CancelProtectedWriteFailEvent(Fee_30_FlexNor_SlimInstance_ContextPtrType ctx)
{
    Fee_30_FlexNor_Scheduler_AllowCancel();
    Fee_30_FlexNor_SlimInstance_WriteFailEvent(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimInstance_CancelProtectedJobFailEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimInstance_CancelProtectedJobFailEvent(Fee_30_FlexNor_SlimInstance_ContextPtrType ctx)
{
    Fee_30_FlexNor_Scheduler_AllowCancel();
    Fee_30_FlexNor_SlimInstance_JobFailEvent(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimInstance_ReadMetaDataFailEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimInstance_ReadMetaDataFailEvent(Fee_30_FlexNor_SlimInstance_ContextPtrType ctx)
{
    if(Fee_30_FlexNor_FlashAccess_GetReadJobResult() == FEE_30_FLEXNOR_FLASH_ECCERROR)
    {
        ctx->CurrentState = &Fee_30_FlexNor_SlimInstanceReadCommitMarkerState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        Fee_30_FlexNor_SlimInstance_ReadCommitMarker(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }
    else /* FEE_30_FLEXNOR_FLASH_FAIL */
    {
        Fee_30_FlexNor_SlimInstance_JobFailEvent(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimInstance_ReadCommitMarkerFailEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimInstance_ReadCommitMarkerFailEvent(Fee_30_FlexNor_SlimInstance_ContextPtrType ctx)
{
    if(Fee_30_FlexNor_FlashAccess_GetReadJobResult() == FEE_30_FLEXNOR_FLASH_ECCERROR)
    {
        ctx->Instance.InstanceData->Validity = FEE_30_FLEXNOR_VALID; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        ctx->CurrentState = &Fee_30_FlexNor_SlimInstanceDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */

        Fee_30_FlexNor_SlimInstance_EndJob();
        ctx->GenericContext.ResultCallback(FEE_30_FLEXNOR_SERVICE_OK); /* SBSW_Fee_30_FlexNor_ContextFunctionPointerCall */
    }
    else /* FEE_30_FLEXNOR_FLASH_FAIL */
    {
        Fee_30_FlexNor_SlimInstance_JobFailEvent(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimInstance_ReadStatusForValidationFailEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimInstance_ReadStatusForValidationFailEvent(Fee_30_FlexNor_SlimInstance_ContextPtrType ctx)
{
    if(Fee_30_FlexNor_FlashAccess_GetReadJobResult() == FEE_30_FLEXNOR_FLASH_ECCERROR)
    {
        ctx->Instance.InstanceData->Validity = FEE_30_FLEXNOR_INVALID; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */

        ctx->CurrentState = &Fee_30_FlexNor_SlimInstanceDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        Fee_30_FlexNor_SlimInstance_EndJob();
        ctx->GenericContext.ResultCallback(FEE_30_FLEXNOR_SERVICE_OK); /* SBSW_Fee_30_FlexNor_ContextFunctionPointerCall */
    }
    else /* FEE_30_FLEXNOR_FLASH_FAIL */
    {
        Fee_30_FlexNor_SlimInstance_JobFailEvent(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimInstance_Validate_Initialize()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimInstance_Validate_Initialize(Fee_30_FlexNor_SlimInstance_ContextPtrType ctx)
{
    Fee_30_FlexNor_SlimInstance_StartJob();

    ctx->CurrentState = &Fee_30_FlexNor_SlimInstanceReadMetadataState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_SlimInstance_ReadInstanceMetadataAndStatus(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimInstance_ReadMetadata_ProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimInstance_ReadMetadata_ProcessEvent(
    Fee_30_FlexNor_SlimInstance_ContextPtrType ctx)
{
    ctx->Instance.InstanceData->Validity = Fee_30_FlexNor_SlimInstance_ValidateInstanceMetadata(ctx); /* SBSW_Fee_30_FlexNor_ContextPointerAccess */ /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */

    ctx->CurrentState = &Fee_30_FlexNor_SlimInstanceDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_SlimInstance_EndJob();
    ctx->GenericContext.ResultCallback(FEE_30_FLEXNOR_SERVICE_OK); /* SBSW_Fee_30_FlexNor_ContextFunctionPointerCall */

    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimInstance_ReadCommitMarker_ProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimInstance_ReadCommitMarker_ProcessEvent(
    Fee_30_FlexNor_SlimInstance_ContextPtrType ctx)
{
    Fee_30_FlexNor_StructureValidityType commitMarkerValidity = Fee_30_FlexNor_SlimInstance_ValidateCommitMarker(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */

    if (commitMarkerValidity == FEE_30_FLEXNOR_EMPTY)
    {
        Fee_30_FlexNor_LengthType alignedMetadataSize = ctx->GenericContext.PartitionConfig->InterferenceFreeAlignment;

        ctx->CurrentState = &Fee_30_FlexNor_SlimInstanceReadStatusForValidationState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        Fee_30_FlexNor_Instance_ReadStatus(ctx->Instance.InstanceData, &ctx->GenericContext, alignedMetadataSize,  /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
            &Fee_30_FlexNor_SlimInstance_ResultHandler);
    }
    else
    {
        ctx->Instance.InstanceData->Validity = FEE_30_FLEXNOR_VALID; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        ctx->CurrentState = &Fee_30_FlexNor_SlimInstanceDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */

        Fee_30_FlexNor_SlimInstance_EndJob();
        ctx->GenericContext.ResultCallback(FEE_30_FLEXNOR_SERVICE_OK); /* SBSW_Fee_30_FlexNor_ContextFunctionPointerCall */
    }
    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimInstance_ReadStatusForValidation_ProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimInstance_ReadStatusForValidation_ProcessEvent(
    Fee_30_FlexNor_SlimInstance_ContextPtrType ctx)
{
    boolean isStatusEmpty = Fee_30_FlexNor_Shared_IsErased(ctx->GenericContext.InstanceBuffer,
        ctx->GenericContext.PartitionConfig->PageAlignment,
        ctx->GenericContext.PartitionConfig->ErasedValue); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    ctx->Instance.InstanceData->Validity = (isStatusEmpty == TRUE) ? FEE_30_FLEXNOR_EMPTY : FEE_30_FLEXNOR_INVALID; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    ctx->CurrentState = &Fee_30_FlexNor_SlimInstanceDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */

    Fee_30_FlexNor_SlimInstance_EndJob();
    ctx->GenericContext.ResultCallback(FEE_30_FLEXNOR_SERVICE_OK); /* SBSW_Fee_30_FlexNor_ContextFunctionPointerCall */

    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimInstance_ReadContent_Initialize()
 *********************************************************************************************************************/
/*!
 * Internal comment removed. *
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimInstance_ReadContent_Initialize(Fee_30_FlexNor_SlimInstance_ContextPtrType ctx)
{
    Fee_30_FlexNor_SlimInstance_StartJob();

    Fee_30_FlexNor_LengthType alignedMetadataSize = ctx->GenericContext.PartitionConfig->InterferenceFreeAlignment;

    ctx->CurrentState = &Fee_30_FlexNor_SlimInstanceReadStatusState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_Instance_ReadStatus(ctx->Instance.InstanceData, &ctx->GenericContext, alignedMetadataSize,  /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
            &Fee_30_FlexNor_SlimInstance_ResultHandler);
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimInstance_Write_Initialize()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimInstance_Write_Initialize(Fee_30_FlexNor_SlimInstance_ContextPtrType ctx)
{
    Fee_30_FlexNor_SlimInstance_StartJob();
    Fee_30_FlexNor_Scheduler_DenyCancel();

    ctx->CurrentState = &Fee_30_FlexNor_SlimInstanceWritePayloadState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_SlimInstance_WritePayload(ctx);                     /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimInstance_WritePayload_ProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimInstance_WritePayload_ProcessEvent(
    Fee_30_FlexNor_SlimInstance_ContextPtrType ctx)
{
    boolean anotherWriteNecessary = Fee_30_FlexNor_Instance_IsAnotherWriteStepNecessary(
        &ctx->GenericContext,
        ctx->Instance.ConstInstanceData); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    if (anotherWriteNecessary == TRUE)
    {
        Fee_30_FlexNor_SlimInstance_WritePayload(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }
    else
    {
        Fee_30_FlexNor_Scheduler_AllowCancel();

        ctx->CurrentState = &Fee_30_FlexNor_SlimInstanceWriteCommitMarkerState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        Fee_30_FlexNor_SlimInstance_WriteCommitMarker(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }

    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimInstance_WriteCommitMarker_ProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimInstance_WriteCommitMarker_ProcessEvent(
    Fee_30_FlexNor_SlimInstance_ContextPtrType ctx)
{
    ctx->CurrentState = &Fee_30_FlexNor_SlimInstanceDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_SlimInstance_EndJob();

    ctx->GenericContext.ResultCallback(FEE_30_FLEXNOR_SERVICE_OK); /* SBSW_Fee_30_FlexNor_ContextFunctionPointerCall */
    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimInstance_Copy_Initialize()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimInstance_Copy_Initialize(Fee_30_FlexNor_SlimInstance_ContextPtrType ctx)
{
    Fee_30_FlexNor_SlimInstance_StartJob();
    Fee_30_FlexNor_Scheduler_DenyCancel();

    ctx->CurrentState = &Fee_30_FlexNor_SlimInstanceReadSourceContentState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_SlimInstance_ReadSourceContent(ctx);                     /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimInstance_ReadSourceContent_ProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimInstance_ReadSourceContent_ProcessEvent(
    Fee_30_FlexNor_SlimInstance_ContextPtrType ctx)
{
    if (ctx->GenericContext.ContentWritten == 0u)
    {
        ctx->Instance.InstanceData->Status 
            = Fee_30_FlexNor_Instance_ParseInstanceStatus(ctx->GenericContext.InstanceBuffer); /* SBSW_Fee_30_FlexNor_ContextPointerAccess */ /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }

    ctx->CurrentState = &Fee_30_FlexNor_SlimInstanceWriteTargetContentState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_SlimInstance_WriteTargetContent(ctx);                     /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */

    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimInstance_WriteTargetContent_ProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimInstance_WriteTargetContent_ProcessEvent(
    Fee_30_FlexNor_SlimInstance_ContextPtrType ctx)
{
    boolean anotherWriteNecessary = Fee_30_FlexNor_Instance_IsAnotherWriteStepNecessary(
        &ctx->GenericContext,
        ctx->Instance.ConstInstanceData); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    if (anotherWriteNecessary == TRUE)
    {
        ctx->CurrentState = &Fee_30_FlexNor_SlimInstanceReadSourceContentState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        Fee_30_FlexNor_SlimInstance_ReadSourceContent(ctx);                     /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }
    else
    {
        Fee_30_FlexNor_Scheduler_AllowCancel();

        ctx->CurrentState = &Fee_30_FlexNor_SlimInstanceCopyCommitMarkerState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        Fee_30_FlexNor_SlimInstance_WriteCommitMarker(ctx);                    /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }

    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimInstance_CopyCommitMarker_ProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimInstance_CopyCommitMarker_ProcessEvent(
    Fee_30_FlexNor_SlimInstance_ContextPtrType ctx)
{
    Fee_30_FlexNor_SlimInstance_EndJob();

    ctx->CurrentState = &Fee_30_FlexNor_SlimInstanceDefaultState;  /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    ctx->GenericContext.ResultCallback(FEE_30_FLEXNOR_SERVICE_OK); /* SBSW_Fee_30_FlexNor_ContextFunctionPointerCall */

    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimInstance_ReadStatus_ProcessEvent()
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
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimInstance_ReadStatus_ProcessEvent(
    Fee_30_FlexNor_SlimInstance_ContextPtrType ctx)
{
    ctx->Instance.InstanceData->Status /* SBSW_Fee_30_FlexNor_ParamPointerWriteAccess */
        = Fee_30_FlexNor_Instance_ParseInstanceStatus(ctx->GenericContext.InstanceBuffer); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */

    if (ctx->Instance.InstanceData->Status == FEE_30_FLEXNOR_INSTANCE_VALID)
    {
        Fee_30_FlexNor_Instance_CopyDataFromStatusPageInUserBuffer( /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
            ctx->Instance.InstanceData, &ctx->GenericContext);
        
        Fee_30_FlexNor_LengthType metaDataSize = ctx->GenericContext.PartitionConfig->InterferenceFreeAlignment;

        ctx->CurrentState = &Fee_30_FlexNor_SlimInstanceReadOffsetPage; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        boolean isJobPending = Fee_30_FlexNor_Instance_ReadOffsetPage(
            ctx->Instance.InstanceData, &ctx->GenericContext, metaDataSize, 
            &Fee_30_FlexNor_SlimInstance_ResultHandler); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */

        if(isJobPending == FALSE)
        {
            (void) Fee_30_FlexNor_SlimInstance_ReadOffsetPage_ProcessEvent(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
        }
    }
    else
    {
        Fee_30_FlexNor_SlimInstance_EndJob();

        ctx->CurrentState = &Fee_30_FlexNor_SlimInstanceDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        ctx->GenericContext.ResultCallback(FEE_30_FLEXNOR_SERVICE_OK);  /* SBSW_Fee_30_FlexNor_ContextFunctionPointerCall */
    }

    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimInstance_ReadOffsetPage_ProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimInstance_ReadOffsetPage_ProcessEvent(
    Fee_30_FlexNor_SlimInstance_ContextPtrType ctx)
{
    Fee_30_FlexNor_LengthType metaDataSize = ctx->GenericContext.PartitionConfig->InterferenceFreeAlignment;

    Fee_30_FlexNor_Instance_CopyDataFromOffsetPageInUserBuffer( /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
        ctx->Instance.InstanceData, &ctx->GenericContext, metaDataSize);

    ctx->CurrentState = &Fee_30_FlexNor_SlimInstanceReadCompletelyFilledPages; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    boolean isFlashJobRequested = Fee_30_FlexNor_Instance_ReadCompletelyFilledPages( /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
        ctx->Instance.InstanceData, &ctx->GenericContext, metaDataSize, &Fee_30_FlexNor_SlimInstance_ResultHandler);

    if(isFlashJobRequested == FALSE)
    {
        (void) Fee_30_FlexNor_SlimInstance_ReadCompletelyFilledPages_ProcessEvent(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }

    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimInstance_ReadCompletelyFilledPages_ProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) 
    Fee_30_FlexNor_SlimInstance_ReadCompletelyFilledPages_ProcessEvent(
        Fee_30_FlexNor_SlimInstance_ContextPtrType ctx)
{
    Fee_30_FlexNor_LengthType metaDataSize = ctx->GenericContext.PartitionConfig->InterferenceFreeAlignment;

    ctx->CurrentState = &Fee_30_FlexNor_SlimInstanceReadLastPage; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    boolean isFlashJobRequested = Fee_30_FlexNor_Instance_ReadLastPage( /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
        ctx->Instance.InstanceData, &ctx->GenericContext, metaDataSize, &Fee_30_FlexNor_SlimInstance_ResultHandler);

    if(isFlashJobRequested == FALSE)
    {
        Fee_30_FlexNor_SlimInstance_EndJob();

        ctx->CurrentState = &Fee_30_FlexNor_SlimInstanceDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        ctx->GenericContext.ResultCallback(FEE_30_FLEXNOR_SERVICE_OK);  /* SBSW_Fee_30_FlexNor_ContextFunctionPointerCall */
    }

    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimInstance_ReadLastPage_ProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) 
    Fee_30_FlexNor_SlimInstance_ReadLastPage_ProcessEvent(
        Fee_30_FlexNor_SlimInstance_ContextPtrType ctx)
{
    Fee_30_FlexNor_Instance_CopyDataFromLastPageInUserBuffer(ctx->Instance.InstanceData, &ctx->GenericContext); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */

    Fee_30_FlexNor_SlimInstance_EndJob();

    ctx->CurrentState = &Fee_30_FlexNor_SlimInstanceDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    ctx->GenericContext.ResultCallback(FEE_30_FLEXNOR_SERVICE_OK);  /* SBSW_Fee_30_FlexNor_ContextFunctionPointerCall */

    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

#    define FEE_30_FLEXNOR_STOP_SEC_CODE
#    include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif

/**********************************************************************************************************************
 *  END OF FILE: Fee_30_FlexNor_SlimInstanceMachine.c
 *********************************************************************************************************************/
