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
/*!        \file  Fee_30_FlexNor_CopyBlockMachine.c
 *        \brief  Copy block state machine implementation
 *      \details  Provides the implementation of the state machine logic for the copy block unit.
 *         \unit  CopyBlock
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#define FEE_30_FLEXNOR_COPYBLOCKMACHINE_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Fee_30_FlexNor_CopyBlockMachine.h"
#include "Fee_30_FlexNor_CopyBlockInternal.h"

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

FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_CopyBlock_ConstStateType Fee_30_FlexNor_CopyBlockDefaultState = { /* PRQA S 3218 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
    &Fee_30_FlexNor_CopyBlock_DefaultProcessEvent, 
    &Fee_30_FlexNor_CopyBlock_DefaultFailEvent
};

FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_CopyBlock_ConstStateType Fee_30_FlexNor_CopyBlockReadSourceChunkState = { /* PRQA S 3218 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
    &Fee_30_FlexNor_CopyBlock_ReadSourceChunk_ProcessEvent, 
    &Fee_30_FlexNor_CopyBlock_JobFailEvent
};

FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_CopyBlock_ConstStateType Fee_30_FlexNor_CopyBlockFindLatestInstanceState = { /* PRQA S 3218 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
    &Fee_30_FlexNor_CopyBlock_FindLatestInstance_ProcessEvent, 
    &Fee_30_FlexNor_CopyBlock_FindLatestInstanceFailEvent
};

FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_CopyBlock_ConstStateType Fee_30_FlexNor_CopyBlockAllocateCopyState = { /* PRQA S 3218 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
    &Fee_30_FlexNor_CopyBlock_AllocateCopy_ProcessEvent, 
    &Fee_30_FlexNor_CopyBlock_JobFailEvent
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
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * Fee_30_FlexNor_CopyBlock_InitState()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_CopyBlock_InitState(Fee_30_FlexNor_CopyBlock_ContextPtrType ctx)
{
    ctx->CurrentState = &Fee_30_FlexNor_CopyBlockDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_CopyBlock_DefaultProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_CopyBlock_DefaultProcessEvent(
    Fee_30_FlexNor_CopyBlock_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    FEE_DUMMY_STATEMENT(ctx);
    return FEE_30_FLEXNOR_STOP_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_CopyBlock_DefaultFailEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_CopyBlock_DefaultFailEvent(Fee_30_FlexNor_CopyBlock_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    FEE_DUMMY_STATEMENT(ctx);
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_CopyBlock_JobFailEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_CopyBlock_JobFailEvent(Fee_30_FlexNor_CopyBlock_ContextPtrType ctx)
{
    ctx->CurrentState = &Fee_30_FlexNor_CopyBlockDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_CopyBlock_EndJob();
    ctx->ResultCallback(FEE_30_FLEXNOR_SERVICE_FAIL); /* SBSW_Fee_30_FlexNor_ContextFunctionPointerCall */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_CopyBlock_FindLatestInstanceFailEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_CopyBlock_FindLatestInstanceFailEvent(
    Fee_30_FlexNor_CopyBlock_ContextPtrType ctx)
{
    ctx->CurrentState = &Fee_30_FlexNor_CopyBlockDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_CopyBlock_EndJob();
 
    Fee_30_FlexNor_Chunk_InstanceSearchResultType instanceSearchResult
        = ctx->BlockToCopy.SourceChunk.Services.GetJobResultOfInstanceSearch(); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    if(instanceSearchResult == FEE_30_FLEXNOR_INSTANCESEARCH_NO_VALID_INSTANCE_FOUND)
    {
        /* This fail event is called in case no valid instance can be found in an valid chunk. Since the first instance 
           is written within the chunk allocation, this situation is excluded by design. It can only happen if the 
           flash driver does not fulfill the requirements listed in the TechRef. 
           - By finishing with FEE_30_FLEXNOR_SERVICE_NOT_OK the GC skips the current block and continues. This allows 
             the Fee to recover via a GC but the (latest) data of this block can be lost. 
           - The chunk reallocation requests a recovery GC to recover from this situation in case the CopyBlock finishes 
             with FEE_30_FLEXNOR_SERVICE_NOT_OK. 
        */
        ctx->ResultCallback(FEE_30_FLEXNOR_SERVICE_NOT_OK); /* SBSW_Fee_30_FlexNor_ContextFunctionPointerCall */
    }
    else
    {
        /* Any other fail leads to GC retries or a failing user job. */
        ctx->ResultCallback(FEE_30_FLEXNOR_SERVICE_FAIL); /* SBSW_Fee_30_FlexNor_ContextFunctionPointerCall */
    }
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_CopyBlock_Copy_Initialize()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_CopyBlock_Copy_Initialize(Fee_30_FlexNor_CopyBlock_ContextPtrType ctx)
{
    Fee_30_FlexNor_CopyBlock_StartJob();

    ctx->CurrentState = &Fee_30_FlexNor_CopyBlockReadSourceChunkState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_CopyBlock_ReadSourceChunk(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_CopyBlock_ReadSourceChunk_ProcessEvent
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
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_CopyBlock_ReadSourceChunk_ProcessEvent(
    Fee_30_FlexNor_CopyBlock_ContextPtrType ctx)
{
    /* In bootloader mode, the configuration always matches. */
    boolean readChunkMatches = (Fee_30_FlexNor_ConfigInterface_IsBootloaderModeEnabled() == TRUE) ||
                               (ctx->BlockToCopy.BlockConfig->Length == ctx->BlockToCopy.SourceChunk.Data.PayloadSize);

    Fee_30_FlexNor_ServiceResult result = (ctx->BlockToCopy.SourceChunk.Data.Validity == FEE_30_FLEXNOR_VALID) 
                                        ? FEE_30_FLEXNOR_SERVICE_OK : FEE_30_FLEXNOR_SERVICE_NOT_OK;

    if ((readChunkMatches == TRUE) && (result == FEE_30_FLEXNOR_SERVICE_OK))
    {
        ctx->CurrentState = &Fee_30_FlexNor_CopyBlockFindLatestInstanceState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        Fee_30_FlexNor_CopyBlock_FindLatestInstance(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }
    else
    {
        Fee_30_FlexNor_CopyBlock_EndJob();

        ctx->CurrentState = &Fee_30_FlexNor_CopyBlockDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        ctx->ResultCallback(result); /* SBSW_Fee_30_FlexNor_ContextFunctionPointerCall */
    }
    
    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_CopyBlock_FindLatestInstance_ProcessEvent
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_CopyBlock_FindLatestInstance_ProcessEvent(
    Fee_30_FlexNor_CopyBlock_ContextPtrType ctx)
{
    ctx->CurrentState = &Fee_30_FlexNor_CopyBlockAllocateCopyState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_CopyBlock_AllocateCopy(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */

    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_CopyBlock_AllocateCopy_ProcessEvent
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_CopyBlock_AllocateCopy_ProcessEvent(
    Fee_30_FlexNor_CopyBlock_ContextPtrType ctx)
{
    Fee_30_FlexNor_CopyBlock_EndJob();

    ctx->CurrentState = &Fee_30_FlexNor_CopyBlockDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    ctx->ResultCallback(FEE_30_FLEXNOR_SERVICE_OK); /* SBSW_Fee_30_FlexNor_ContextFunctionPointerCall */

    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

#define FEE_30_FLEXNOR_STOP_SEC_CODE
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: Fee_30_FlexNor_CopyBlockMachine.c
 *********************************************************************************************************************/
