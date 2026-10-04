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
/*!        \file  Fee_30_FlexNor_ChunkMachine.c
 *        \brief  Chunk state machine implementation
 *      \details  Provides the implementation of the state machine logic for the generic chunk unit.
 *         \unit  Chunk
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#define FEE_30_FLEXNOR_CHUNKMACHINE_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Fee_30_FlexNor_ChunkMachine.h"
#include "Fee_30_FlexNor_DiagnosticHandler.h"

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/
#if !defined(FEE_30_FLEXNOR_LOCAL) /* COV_FEE_30_FLEXNOR_COMPATIBILITY */
#    define FEE_30_FLEXNOR_LOCAL static
#endif

#if !defined(FEE_30_FLEXNOR_LOCAL_INLINE) /* COV_FEE_30_FLEXNOR_COMPATIBILITY */
#    define FEE_30_FLEXNOR_LOCAL_INLINE LOCAL_INLINE
#endif

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/
#define FEE_30_FLEXNOR_START_SEC_CONST_UNSPECIFIED
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_Chunk_ConstStateType Fee_30_FlexNor_ChunkDefaultState = {
    &Fee_30_FlexNor_Chunk_DefaultProcessEvent,
    &Fee_30_FlexNor_Chunk_DefaultFailEvent
};

/* PRQA S 3218 1 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_Chunk_ConstStateType Fee_30_FlexNor_ChunkBinarySearchState = {
    &Fee_30_FlexNor_Chunk_BinarySearch_ProcessEvent,
    &Fee_30_FlexNor_Chunk_JobFailEvent
};

/* PRQA S 3218 1 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_Chunk_ConstStateType Fee_30_FlexNor_ChunkLinearSearchState = {
    &Fee_30_FlexNor_Chunk_LinearSearch_ProcessEvent,
    &Fee_30_FlexNor_Chunk_JobFailEvent
};

/* PRQA S 3218 1 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_Chunk_ConstStateType Fee_30_FlexNor_ChunkAllocateInstanceState = {
    &Fee_30_FlexNor_Chunk_AllocateInstance_ProcessEvent,
    &Fee_30_FlexNor_Chunk_JobFailEvent
};

/* PRQA S 3218 1 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_Chunk_ConstStateType Fee_30_FlexNor_ChunkWriteLinkState = {
    &Fee_30_FlexNor_Chunk_WriteLink_ProcessEvent,
    &Fee_30_FlexNor_Chunk_WriteFailEvent
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
 * Fee_30_FlexNor_Chunk_InitializeSearchContext()
 *********************************************************************************************************************/
/*! \brief       Sets up all variables that are needed for the instance search.
 *  \details     -
 *  \param[in]   ctx               Pointer to the chunk context
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FEE_30_FLEXNOR_LOCAL FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Chunk_InitializeSearchContext(
    Fee_30_FlexNor_Chunk_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Chunk_ContinueTriggeredJob()
 *********************************************************************************************************************/
/*! \brief       After completing the instance search inside the chunk this function continues 
 *               with the initially triggered job
 *  \details     -
 *  \param[in]   ctx    Context that contains the current job data
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FEE_30_FLEXNOR_LOCAL FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Chunk_ContinueTriggeredJob(
    Fee_30_FlexNor_Chunk_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Chunk_FinishJob()
 *********************************************************************************************************************/
/*! \brief       Finishes the currently running service and provides the result to the upper layer. 
 *  \details     -
 *  \param[in,out]  ctx                   Pointer to the context. Must not be NULL.
 *  \param[in]      serviceResult         Result of the currently running service.
 *  \param[in]      instanceSearchResult  Result of the instance search.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
void Fee_30_FlexNor_Chunk_FinishJob(Fee_30_FlexNor_Chunk_ContextPtrType ctx, Fee_30_FlexNor_ServiceResult serviceResult, 
    Fee_30_FlexNor_Chunk_InstanceSearchResultType instanceSearchResult);

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * Fee_30_FlexNor_Chunk_InitializeSearchContext()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FEE_30_FLEXNOR_LOCAL FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Chunk_InitializeSearchContext(
    Fee_30_FlexNor_Chunk_ContextPtrType ctx)
{
    ctx->SearchContext.StartIndex   = 0;                                                 /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    ctx->SearchContext.EndIndex     = ctx->Chunk->Data.InstanceCount - (uint16) 1u; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    ctx->SearchContext.CurrentIndex = 0u;                                                /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    ctx->SearchContext.ValidIndex   = FEE_30_FLEXNOR_INVALID_INDEX;                      /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    ctx->SearchContext.SearchStatus = FEE_30_FLEXNOR_SEARCH_PENDING;                     /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Chunk_ContinueTriggeredJob()
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
 *
 */
FEE_30_FLEXNOR_LOCAL FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Chunk_ContinueTriggeredJob(
    Fee_30_FlexNor_Chunk_ContextPtrType ctx)
{
    /*
     * Because the instance search is shared between the search and allocation services, the specific job state machine 
     * must be entered here.
     */
    switch (ctx->ChunkJob)
    {
        case FEE_30_FLEXNOR_CHUNK_INSTANCESEARCH:
            if(ctx->SearchContext.ValidIndex == FEE_30_FLEXNOR_INVALID_INDEX)
            {    
                /* No valid instance found. */
                Fee_30_FlexNor_DiagnosticHandler_RaiseError(FEE_30_FLEXNOR_DIAGID_NO_VALID_INSTANCE_FOUND);
                Fee_30_FlexNor_Chunk_FinishJob(ctx, FEE_30_FLEXNOR_SERVICE_FAIL, /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
                    FEE_30_FLEXNOR_INSTANCESEARCH_NO_VALID_INSTANCE_FOUND);
            }
            else
            {
                Fee_30_FlexNor_Chunk_SetupFoundInstance(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
                Fee_30_FlexNor_Chunk_FinishJob(ctx, FEE_30_FLEXNOR_SERVICE_OK, FEE_30_FLEXNOR_INSTANCESEARCH_OK); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
            }
            break;
        case FEE_30_FLEXNOR_CHUNK_INSTANCEALLOCATION:
            Fee_30_FlexNor_Chunk_AllocateInstance_Initialize(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
            break;
        default:
            Fee_30_FlexNor_Chunk_FinishJob(ctx, FEE_30_FLEXNOR_SERVICE_FAIL, FEE_30_FLEXNOR_INSTANCESEARCH_FAIL); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
            break;
    }
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Chunk_FinishJob()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
void Fee_30_FlexNor_Chunk_FinishJob(Fee_30_FlexNor_Chunk_ContextPtrType ctx, Fee_30_FlexNor_ServiceResult serviceResult, 
    Fee_30_FlexNor_Chunk_InstanceSearchResultType instanceSearchResult)
{
    ctx->InstanceSearchResult = instanceSearchResult; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_Chunk_EndJob();
    ctx->CurrentState = &Fee_30_FlexNor_ChunkDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    ctx->ResultCallback(serviceResult);        /* SBSW_Fee_30_FlexNor_ContextFunctionPointerCall */
}

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * Fee_30_FlexNor_Chunk_InitState()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Chunk_InitState(Fee_30_FlexNor_Chunk_ContextPtrType ctx)
{
    ctx->CurrentState = &Fee_30_FlexNor_ChunkDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Chunk_DefaultProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Chunk_DefaultProcessEvent(
    Fee_30_FlexNor_Chunk_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    FEE_DUMMY_STATEMENT(ctx);
    return FEE_30_FLEXNOR_STOP_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Chunk_DefaultFailEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Chunk_DefaultFailEvent(
    Fee_30_FlexNor_Chunk_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    FEE_DUMMY_STATEMENT(ctx);
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Chunk_JobFailEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Chunk_JobFailEvent(Fee_30_FlexNor_Chunk_ContextPtrType ctx)
{
    Fee_30_FlexNor_Chunk_FinishJob(ctx, FEE_30_FLEXNOR_SERVICE_FAIL, FEE_30_FLEXNOR_INSTANCESEARCH_FAIL); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Chunk_WriteFailEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Chunk_WriteFailEvent(Fee_30_FlexNor_Chunk_ContextPtrType ctx)
{
    Fee_30_FlexNor_Chunk_RequestRecoveryGarbageCollection(ctx->PartitionConfig->PartitionId, 
        ctx->Chunk->Data.StartAddress);
    Fee_30_FlexNor_Chunk_JobFailEvent(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Chunk_BinarySearch_Initialize()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Chunk_BinarySearch_Initialize(Fee_30_FlexNor_Chunk_ContextPtrType ctx)
{
    Fee_30_FlexNor_Chunk_InitializeSearchContext(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */

    ctx->CurrentState = &Fee_30_FlexNor_ChunkBinarySearchState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_Chunk_DoBinarySearchStep(ctx);               /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Chunk_BinarySearch_ProcessEvent()
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
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Chunk_BinarySearch_ProcessEvent(
    Fee_30_FlexNor_Chunk_ContextPtrType ctx)
{

    if(ctx->InstanceToCheck->Data.ReallocationRequired == TRUE)
    {
        ctx->Chunk->Data.ReallocationRequired = TRUE; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    }

    if (ctx->SearchType == FEE_30_FLEXNOR_SEARCH_EMPTY)
    {
        Fee_30_FlexNor_Chunk_EvaluateBinarySearchEmpty(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }
    else /* FEE_30_FLEXNOR_SEARCH_VALID */
    {
        Fee_30_FlexNor_Chunk_EvaluateBinarySearchValid(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }

    if (ctx->SearchContext.SearchStatus == FEE_30_FLEXNOR_SEARCH_FINISHED)
    {
        /*  When the search is done, change into the given initialization function.
            This transition is necessary to know which state must be initialized after the search. */
        Fee_30_FlexNor_Chunk_ContinueTriggeredJob(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
    }
    else if (ctx->SearchContext.SearchStatus == FEE_30_FLEXNOR_SEARCH_ABORTED)
    {
        Fee_30_FlexNor_Chunk_LinearSearch_Initialize(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }
    else
    {
        Fee_30_FlexNor_Chunk_DoBinarySearchStep(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }

    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Chunk_FindLatestValidInstance_Initialize()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Chunk_FindLatestValidInstance_Initialize(void)
{
    Fee_30_FlexNor_Chunk_StartJob();
    Fee_30_FlexNor_Chunk_SearchInstance(FEE_30_FLEXNOR_SEARCH_VALID, FEE_30_FLEXNOR_CHUNK_INSTANCESEARCH);
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Chunk_TryAllocateInstance_Initialize()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Chunk_TryAllocateInstance_Initialize(void)
{
    Fee_30_FlexNor_Chunk_StartJob();
    Fee_30_FlexNor_Chunk_SearchInstance(FEE_30_FLEXNOR_SEARCH_EMPTY, FEE_30_FLEXNOR_CHUNK_INSTANCEALLOCATION);
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Chunk_LinearSearch_Initialize()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Chunk_LinearSearch_Initialize(Fee_30_FlexNor_Chunk_ContextPtrType ctx)
{
    Fee_30_FlexNor_Chunk_InitializeSearchContext(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */

    ctx->CurrentState = &Fee_30_FlexNor_ChunkLinearSearchState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_Chunk_DoLinearSearchStep(ctx);               /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Chunk_LinearSearch_ProcessEvent()
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
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Chunk_LinearSearch_ProcessEvent(
    Fee_30_FlexNor_Chunk_ContextPtrType ctx)
{
    if(ctx->InstanceToCheck->Data.ReallocationRequired == TRUE)
    {
        ctx->Chunk->Data.ReallocationRequired = TRUE; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    }

    Fee_30_FlexNor_Chunk_EvaluateLinearSearchValid(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */

    if (ctx->SearchContext.SearchStatus == FEE_30_FLEXNOR_SEARCH_FINISHED)
    {
        Fee_30_FlexNor_Chunk_ContinueTriggeredJob(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }
    else
    {
        Fee_30_FlexNor_Chunk_DoLinearSearchStep(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }

    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Chunk_AllocateInstance_Initialize()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Chunk_AllocateInstance_Initialize(
    Fee_30_FlexNor_Chunk_ContextPtrType ctx)
{
    /* No StartJob necessary here, because the job should have been setup earlier. */

    ctx->CurrentState = &Fee_30_FlexNor_ChunkAllocateInstanceState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_Chunk_AllocateInstance(ctx);                     /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Chunk_AllocateInstance_ProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Chunk_AllocateInstance_ProcessEvent(
    Fee_30_FlexNor_Chunk_ContextPtrType ctx)
{
    Fee_30_FlexNor_Chunk_EndJob();

    ctx->CurrentState = &Fee_30_FlexNor_ChunkDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    if (ctx->AllocationSuccessful == TRUE)
    {
        ctx->InstanceSearchResult = FEE_30_FLEXNOR_INSTANCESEARCH_OK; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        ctx->ResultCallback(FEE_30_FLEXNOR_SERVICE_OK); /* SBSW_Fee_30_FlexNor_ContextFunctionPointerCall */
    }
    else
    {
        ctx->InstanceSearchResult = FEE_30_FLEXNOR_INSTANCESEARCH_OK; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        ctx->ResultCallback(FEE_30_FLEXNOR_SERVICE_NOT_OK); /* SBSW_Fee_30_FlexNor_ContextFunctionPointerCall */
    }

    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Chunk_WriteLink_Initialize()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Chunk_WriteLink_Initialize(Fee_30_FlexNor_Chunk_ContextPtrType ctx)
{
    Fee_30_FlexNor_Chunk_StartJob();

    ctx->CurrentState = &Fee_30_FlexNor_ChunkWriteLinkState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_Chunk_BuildLink(ctx);                     /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    Fee_30_FlexNor_Chunk_WriteLinkToMemory(ctx);             /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Chunk_WriteLink_ProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Chunk_WriteLink_ProcessEvent(
    Fee_30_FlexNor_Chunk_ContextPtrType ctx)
{
    Fee_30_FlexNor_Chunk_EndJob();

    ctx->CurrentState = &Fee_30_FlexNor_ChunkDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    ctx->ResultCallback(FEE_30_FLEXNOR_SERVICE_OK);        /* SBSW_Fee_30_FlexNor_ContextFunctionPointerCall */

    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

#define FEE_30_FLEXNOR_STOP_SEC_CODE
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: Fee_30_FlexNor_ChunkMachine.c
 *********************************************************************************************************************/
