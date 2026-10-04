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
/*!        \file  Fee_30_FlexNor_GarbageCollectionMachine.c
 *        \brief  Garbage collection state machine implementation
 *      \details  Provides the implementation of the state machine logic for the garbage collection unit.
 *         \unit  GarbageCollection
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#define FEE_30_FLEXNOR_GARBAGECOLLECTIONMACHINE_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Fee_30_FlexNor_GarbageCollectionMachine.h"
#include "Fee_30_FlexNor_GarbageCollectionInternal.h"

#include "Fee_30_FlexNor_LookupTable.h"

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

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/
#define FEE_30_FLEXNOR_START_SEC_CONST_UNSPECIFIED
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_GarbageCollection_ConstStateType 
    Fee_30_FlexNor_GarbageCollectionDefaultState = {
        &Fee_30_FlexNor_GarbageCollection_DefaultProcessEvent, 
        &Fee_30_FlexNor_GarbageCollection_DefaultFailEvent
};

FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_GarbageCollection_ConstStateType 
    Fee_30_FlexNor_GarbageCollectionRecoverLookupTableState = { /* PRQA S 3218 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
        &Fee_30_FlexNor_GarbageCollection_RecoverLookupTable_ProcessEvent, 
        &Fee_30_FlexNor_GarbageCollection_JobFailEvent
};

FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_GarbageCollection_ConstStateType 
    Fee_30_FlexNor_GarbageCollectionSetupTargetSectorState = { /* PRQA S 3218 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
        &Fee_30_FlexNor_GarbageCollection_SetupTargetSector_ProcessEvent, 
        &Fee_30_FlexNor_GarbageCollection_FailRetryEvent
};

FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_GarbageCollection_ConstStateType 
    Fee_30_FlexNor_GarbageCollectionStoreSourceSectorState = { /* PRQA S 3218 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
        &Fee_30_FlexNor_GarbageCollection_StoreSourceSector_ProcessEvent, 
        &Fee_30_FlexNor_GarbageCollection_FailRetryEvent
};

FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_GarbageCollection_ConstStateType 
    Fee_30_FlexNor_GarbageCollectionCopyBlockState = { /* PRQA S 3218 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
        &Fee_30_FlexNor_GarbageCollection_CopyBlock_ProcessEvent, 
        &Fee_30_FlexNor_GarbageCollection_FailRetryEvent
};

FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_GarbageCollection_ConstStateType 
    Fee_30_FlexNor_GarbageCollectionMarkForEraseState = { /* PRQA S 3218 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
        &Fee_30_FlexNor_GarbageCollection_MarkForErase_ProcessEvent, 
        &Fee_30_FlexNor_GarbageCollection_JobFailEvent
};

#define FEE_30_FLEXNOR_STOP_SEC_CONST_UNSPECIFIED
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
 * Fee_30_FlexNor_GarbageCollection_InitializeGarbageCollection()
 *********************************************************************************************************************/
/*! \brief          Evaluates the the partition state and initializes the garbage collection state machine accordingly
 *  \details        -
 *  \param[in,out]  ctx     Pointer to the context for the state machine processing. Must not be NULL.
 *  \param[in]      isRetry States if the GC is started or not.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FEE_30_FLEXNOR_LOCAL_INLINE FUNC(void, FEE_30_FLEXNOR_CODE) 
    Fee_30_FlexNor_GarbageCollection_InitializeGarbageCollection(
        Fee_30_FlexNor_GarbageCollection_ContextPtrType ctx, boolean isRetry);

/**********************************************************************************************************************
 * Fee_30_FlexNor_GarbageCollection_RecoverLookupTable_OnEnter()
 *********************************************************************************************************************/
/*! \brief          Entry action for the RecoverLookupTable state.
 *  \details        Triggers a lookup table recovery if it is not valid. Otherwise it transitions to the CopyBlock 
 *                  state. 
 *  \param[in,out]  ctx     Pointer to the context for the state machine processing. Must not be NULL.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FEE_30_FLEXNOR_LOCAL_INLINE FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_GarbageCollection_RecoverLookupTable_OnEnter(
    Fee_30_FlexNor_GarbageCollection_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_GarbageCollection_CopyBlock_OnEnter()
 *********************************************************************************************************************/
/*! \brief          Entry action for the CopyBlock state.
 *  \details        Evaluates if there are still blocks to copy left and handles the garbage collection state machine 
 *                  accordingly.
 *  \param[in,out]  ctx     Pointer to the context for the state machine processing. Must not be NULL.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FEE_30_FLEXNOR_LOCAL_INLINE FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_GarbageCollection_CopyBlock_OnEnter(
    Fee_30_FlexNor_GarbageCollection_ContextPtrType ctx);


/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * Fee_30_FlexNor_GarbageCollection_InitializeGarbageCollection()
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
FEE_30_FLEXNOR_LOCAL_INLINE FUNC(void, FEE_30_FLEXNOR_CODE) 
    Fee_30_FlexNor_GarbageCollection_InitializeGarbageCollection(Fee_30_FlexNor_GarbageCollection_ContextPtrType ctx, 
        boolean isRetry)
{
    Fee_30_FlexNor_GarbageCollectionModeType gcMode = Fee_30_FlexNor_GarbageCollection_InitializeGarbageCollectionMode(
        ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */

    if((gcMode == FEE_30_FLEXNOR_GARBAGECOLLECTION_NEW) || (isRetry == TRUE))
    {
        /* Invalidate the source sector Id. Updated after the flash write operation was performed. */
        ctx->TargetSector->SourceSectorId = 0u; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        ctx->CurrentState = &Fee_30_FlexNor_GarbageCollectionSetupTargetSectorState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        Fee_30_FlexNor_GarbageCollection_TriggerSectorAllocation(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }
    else
    {
        ctx->CurrentState = &Fee_30_FlexNor_GarbageCollectionRecoverLookupTableState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        Fee_30_FlexNor_GarbageCollection_RecoverLookupTable_OnEnter(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_GarbageCollection_RecoverLookupTable_OnEnter()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FEE_30_FLEXNOR_LOCAL_INLINE FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_GarbageCollection_RecoverLookupTable_OnEnter(
    Fee_30_FlexNor_GarbageCollection_ContextPtrType ctx)
{
    boolean isLutRecoveryTriggered = Fee_30_FlexNor_GarbageCollection_TriggerLookupTableRecoveryIfInvalid(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */

    if(isLutRecoveryTriggered == FALSE)
    {
        (void) Fee_30_FlexNor_GarbageCollection_RecoverLookupTable_ProcessEvent(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }
}


/**********************************************************************************************************************
 * Fee_30_FlexNor_GarbageCollection_CopyBlock_OnEnter()
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
FEE_30_FLEXNOR_LOCAL_INLINE FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_GarbageCollection_CopyBlock_OnEnter(
    Fee_30_FlexNor_GarbageCollection_ContextPtrType ctx)
{
    boolean copyAnotherBlock = Fee_30_FlexNor_GarbageCollection_GetNextBlockToCopy(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    if(copyAnotherBlock == TRUE)
    {
        ctx->CurrentState = &Fee_30_FlexNor_GarbageCollectionCopyBlockState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        Fee_30_FlexNor_GarbageCollection_TriggerCopyBlock(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }
    else 
    {
        ctx->CurrentState = &Fee_30_FlexNor_GarbageCollectionMarkForEraseState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        Fee_30_FlexNor_GarbageCollection_MarkForErase(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }
}

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * Fee_30_FlexNor_GarbageCollection_InitState()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_GarbageCollection_InitState(
    Fee_30_FlexNor_GarbageCollection_ContextPtrType ctx)
{
    ctx->CurrentState = &Fee_30_FlexNor_GarbageCollectionDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_GarbageCollection_DefaultProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_GarbageCollection_DefaultProcessEvent(
    Fee_30_FlexNor_GarbageCollection_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    FEE_DUMMY_STATEMENT(ctx);
    return FEE_30_FLEXNOR_STOP_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_GarbageCollection_DefaultFailEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_GarbageCollection_DefaultFailEvent(
    Fee_30_FlexNor_GarbageCollection_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    FEE_DUMMY_STATEMENT(ctx);
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_GarbageCollection_JobFailEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_GarbageCollection_JobFailEvent(
    Fee_30_FlexNor_GarbageCollection_ContextPtrType ctx)
{
    ctx->CurrentState = &Fee_30_FlexNor_GarbageCollectionDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_GarbageCollection_EndJob();
    ctx->ResultCallback(FEE_30_FLEXNOR_SERVICE_FAIL); /* SBSW_Fee_30_FlexNor_ContextFunctionPointerCall */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_GarbageCollection_FailRetryEvent()
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
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_GarbageCollection_FailRetryEvent(
    Fee_30_FlexNor_GarbageCollection_ContextPtrType ctx)
{
    if((ctx->RetryCounter < FEE_30_FLEXNOR_MAX_RETRY) && (ctx->IsPersistLutJobRunning == FALSE))
    {
        ctx->RetryCounter++; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        Fee_30_FlexNor_GarbageCollection_PrepareRestart(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
        Fee_30_FlexNor_GarbageCollection_InitializeGarbageCollection(ctx, TRUE); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }
    else 
    {
        /* Let GC fail in case a persist LUT job is running to avoid that the processing handler of the lookup table 
        unit is registered twice for scheduling. */
        ctx->CurrentState = &Fee_30_FlexNor_GarbageCollectionDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        Fee_30_FlexNor_GarbageCollection_EndJob();
        ctx->ResultCallback(FEE_30_FLEXNOR_SERVICE_FAIL); /* SBSW_Fee_30_FlexNor_ContextFunctionPointerCall */
    }
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_GarbageCollection_Run_Initialize()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_GarbageCollection_Run_Initialize(
    Fee_30_FlexNor_GarbageCollection_ContextPtrType ctx)
{
    if((ctx->SourceSector == NULL_PTR) || (ctx->SourceSector->Validity == FEE_30_FLEXNOR_VALID))
    {
        boolean isLutValid = Fee_30_FlexNor_LookupTable_IsValid(ctx->PartitionConfig->PartitionId);

        if((isLutValid == FALSE) && (ctx->IsPersistLutJobRunning == TRUE))
        {
            /* Avoid that the processing handler of the lookup table unit is registered twice for scheduling. */
            ctx->ResultCallback(FEE_30_FLEXNOR_SERVICE_FAIL); /* SBSW_Fee_30_FlexNor_ContextFunctionPointerCall */
        }
        else
        {
            Fee_30_FlexNor_GarbageCollection_StartJob();
            Fee_30_FlexNor_GarbageCollection_InitializeGarbageCollection(ctx, FALSE); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
        }
    }
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_GarbageCollection_RecoverLookupTable_ProcessEvent
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) 
    Fee_30_FlexNor_GarbageCollection_RecoverLookupTable_ProcessEvent(
        Fee_30_FlexNor_GarbageCollection_ContextPtrType ctx)
{
    Fee_30_FlexNor_GarbageCollection_CopyBlock_OnEnter(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */

    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_GarbageCollection_SetupTargetSector_ProcessEvent
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) 
    Fee_30_FlexNor_GarbageCollection_SetupTargetSector_ProcessEvent(Fee_30_FlexNor_GarbageCollection_ContextPtrType ctx)
{
    ctx->CurrentState = &Fee_30_FlexNor_GarbageCollectionStoreSourceSectorState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_GarbageCollection_StoreSourceSector(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */

    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_GarbageCollection_StoreSourceSector_ProcessEvent
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) 
    Fee_30_FlexNor_GarbageCollection_StoreSourceSector_ProcessEvent(Fee_30_FlexNor_GarbageCollection_ContextPtrType ctx)
{
    ctx->TargetSector->SourceSectorId = ctx->SourceSector->SectorId; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */

    ctx->CurrentState = &Fee_30_FlexNor_GarbageCollectionRecoverLookupTableState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_GarbageCollection_RecoverLookupTable_OnEnter(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */

    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_GarbageCollection_CopyBlock_ProcessEvent
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_GarbageCollection_CopyBlock_ProcessEvent(
    Fee_30_FlexNor_GarbageCollection_ContextPtrType ctx)
{
    Fee_30_FlexNor_GarbageCollection_CopyBlock_OnEnter(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_GarbageCollection_MarkForErase_ProcessEvent
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) 
    Fee_30_FlexNor_GarbageCollection_MarkForErase_ProcessEvent(Fee_30_FlexNor_GarbageCollection_ContextPtrType ctx)
{
    Fee_30_FlexNor_LookupTable_RequestPersistLut(ctx->PartitionConfig->PartitionId);

    Fee_30_FlexNor_GarbageCollection_EndJob();

    ctx->CurrentState = &Fee_30_FlexNor_GarbageCollectionDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    ctx->ResultCallback(FEE_30_FLEXNOR_SERVICE_OK); /* SBSW_Fee_30_FlexNor_ContextFunctionPointerCall */
    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

#define FEE_30_FLEXNOR_STOP_SEC_CODE
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: Fee_30_FlexNor_GarbageCollectionMachine.c
 *********************************************************************************************************************/
