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
/*!        \file  Fee_30_FlexNor_ChunkSearchMachine.c
 *        \brief  Chunk search state machine implementation
 *      \details  Provides the implementation of the state machine logic for the chunk search unit.
 *         \unit  ChunkSearch
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#define FEE_30_FLEXNOR_CHUNKSEARCHMACHINE_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Fee_30_FlexNor_ChunkSearchInternal.h"
#include "Fee_30_FlexNor_ChunkSearchMachine.h"

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

FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_ChunkSearch_ConstStateType Fee_30_FlexNor_ChunkSearchDefaultState = {
    &Fee_30_FlexNor_ChunkSearch_DefaultProcessEvent, 
    &Fee_30_FlexNor_ChunkSearch_DefaultFailEvent
};

FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_ChunkSearch_ConstStateType Fee_30_FlexNor_ChunkSearchCheckChunkState = { /* PRQA S 3218 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
    &Fee_30_FlexNor_ChunkSearch_CheckChunk_ProcessEvent, 
    &Fee_30_FlexNor_ChunkSearch_JobFailEvent
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
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * Fee_30_FlexNor_ChunkSearch_InitState()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_ChunkSearch_InitState(Fee_30_FlexNor_ChunkSearch_ContextPtrType ctx)
{
    ctx->CurrentState = &Fee_30_FlexNor_ChunkSearchDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_ChunkSearch_DefaultProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_ChunkSearch_DefaultProcessEvent(
    Fee_30_FlexNor_ChunkSearch_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    FEE_DUMMY_STATEMENT(ctx);
    return FEE_30_FLEXNOR_STOP_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_ChunkSearch_DefaultFailEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_ChunkSearch_DefaultFailEvent(
    Fee_30_FlexNor_ChunkSearch_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    FEE_DUMMY_STATEMENT(ctx);
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_ChunkSearch_JobFailEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_ChunkSearch_JobFailEvent(Fee_30_FlexNor_ChunkSearch_ContextPtrType ctx)
{
    ctx->CurrentState = &Fee_30_FlexNor_ChunkSearchDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_ChunkSearch_EndJob();
    ctx->ResultCallback(FEE_30_FLEXNOR_SERVICE_FAIL); /* SBSW_Fee_30_FlexNor_ContextFunctionPointerCall */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_ChunkSearch_FollowLink_Initialize()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_ChunkSearch_FollowLink_Initialize(
    Fee_30_FlexNor_ChunkSearch_ContextPtrType ctx)
{
    Fee_30_FlexNor_ChunkSearch_StartJob();
    ctx->CurrentState = &Fee_30_FlexNor_ChunkSearchCheckChunkState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_ChunkSearch_CheckChunk_OnEnter(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_ChunkSearch_CheckChunk_OnEnter()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_ChunkSearch_CheckChunk_OnEnter(
    Fee_30_FlexNor_ChunkSearch_ContextPtrType ctx)
{
    Std_ReturnType readResult = Fee_30_FlexNor_ChunkSearch_ReadChunk(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */

    if(readResult != E_OK)
    {
        ctx->CurrentChunk->Data.Validity = FEE_30_FLEXNOR_INVALID; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */

        Fee_30_FlexNor_ChunkSearch_EndJob();
        ctx->CurrentState = &Fee_30_FlexNor_ChunkSearchDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        ctx->ResultCallback(FEE_30_FLEXNOR_SERVICE_NOT_OK); /* SBSW_Fee_30_FlexNor_ContextFunctionPointerCall */
    }
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_ChunkSearch_CheckChunk_ProcessEvent()
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
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_ChunkSearch_CheckChunk_ProcessEvent(
    Fee_30_FlexNor_ChunkSearch_ContextPtrType ctx)
{
    boolean abortChunkSearch = FALSE;

    if(ctx->CurrentChunk->Data.Validity == FEE_30_FLEXNOR_VALID)
    {
        boolean isSuccessorChunkNewer = Fee_30_FlexNor_ChunkSearch_IsSuccessorChunkNewer(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
        if((ctx->CurrentChunk->Data.ChunkLink.Validity == FEE_30_FLEXNOR_VALID) && (isSuccessorChunkNewer == TRUE))
        {
            ctx->NextChunk = ctx->CurrentChunk->Data.ChunkLink; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
            Fee_30_FlexNor_ChunkSearch_CheckChunk_OnEnter(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
        }
        else if(ctx->CurrentChunk->Data.ChunkLink.Validity == FEE_30_FLEXNOR_EMPTY)
        {
            Fee_30_FlexNor_LookupTable_LinkType parsedLink = Fee_30_FlexNor_ChunkSearch_ParseChunkLink(ctx->NextChunk);
            
            Fee_30_FlexNor_LookupTable_SetLinkIfNewer(ctx->PartitionId, 
                ctx->CurrentChunk->Data.BlockId, 
                parsedLink,
                ctx->CurrentChunk->Data.ReallocationRequired);

            Fee_30_FlexNor_ChunkSearch_EndJob();
            ctx->CurrentState = &Fee_30_FlexNor_ChunkSearchDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
            ctx->ResultCallback(FEE_30_FLEXNOR_SERVICE_OK); /* SBSW_Fee_30_FlexNor_ContextFunctionPointerCall */
        }
        else
        {
            abortChunkSearch = TRUE;
        }
    }
    else 
    {
        abortChunkSearch = TRUE;
    }

    if(abortChunkSearch == TRUE)
    {
        ctx->CurrentChunk->Data.Validity = FEE_30_FLEXNOR_INVALID; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */

        Fee_30_FlexNor_ChunkSearch_EndJob();
        ctx->CurrentState = &Fee_30_FlexNor_ChunkSearchDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        ctx->ResultCallback(FEE_30_FLEXNOR_SERVICE_NOT_OK); /* SBSW_Fee_30_FlexNor_ContextFunctionPointerCall */
    }

    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

#define FEE_30_FLEXNOR_STOP_SEC_CODE
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: Fee_30_FlexNor_ChunkSearchMachine.c
 *********************************************************************************************************************/
