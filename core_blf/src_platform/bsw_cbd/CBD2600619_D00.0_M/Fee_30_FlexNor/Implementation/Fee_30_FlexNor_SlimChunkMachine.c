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
/*!        \file  Fee_30_FlexNor_SlimChunkMachine.c
 *        \brief  Slim chunk state machine implementation
 *      \details  Provides the implementation of the state machine logic for the slim chunk unit.
 *         \unit  SlimChunk
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#define FEE_30_FLEXNOR_SLIMCHUNKMACHINE_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Fee_30_FlexNor_SlimChunkMachine.h"
#include "Fee_30_FlexNor_ChunkInternal.h"
#include "Fee_30_FlexNor_Scheduler.h"
#include "Fee_30_FlexNor_LookupTable.h"

#if (FEE_30_FLEXNOR_SLIMLAYOUT_ENABLED == STD_ON) /* COV_MSR_UT_OPTIONAL_UNIT */

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/
# if !defined(FEE_30_FLEXNOR_LOCAL) /* COV_FEE_30_FLEXNOR_COMPATIBILITY */
#   define FEE_30_FLEXNOR_LOCAL static
# endif

# if !defined(FEE_30_FLEXNOR_LOCAL_INLINE) /* COV_FEE_30_FLEXNOR_COMPATIBILITY */
#   define FEE_30_FLEXNOR_LOCAL_INLINE LOCAL_INLINE
# endif

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/
#define FEE_30_FLEXNOR_START_SEC_CONST_UNSPECIFIED
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_SlimChunk_ConstStateType Fee_30_FlexNor_SlimChunkDefaultState = {
    &Fee_30_FlexNor_SlimChunk_DefaultProcessEvent,
    &Fee_30_FlexNor_SlimChunk_DefaultFailEvent
};

/* PRQA S 3218 1 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_SlimChunk_ConstStateType Fee_30_FlexNor_SlimChunkReadChunkHeaderState = {
    &Fee_30_FlexNor_SlimChunk_ReadChunkHeader_ProcessEvent,
    &Fee_30_FlexNor_SlimChunk_ReadChunkHeader_FailEvent
};

/* PRQA S 3218 1 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_SlimChunk_ConstStateType Fee_30_FlexNor_SlimChunkReadPropertiesState = {
    &Fee_30_FlexNor_SlimChunk_ReadProperties_ProcessEvent,
    &Fee_30_FlexNor_SlimChunk_ReadProperties_FailEvent
};

/* PRQA S 3218 1 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_SlimChunk_ConstStateType Fee_30_FlexNor_SlimChunkReadCommitMarkerState = {
    &Fee_30_FlexNor_SlimChunk_ReadCommitMarker_ProcessEvent,
    &Fee_30_FlexNor_SlimChunk_ReadCommitMarker_FailEvent
};

/* PRQA S 3218 1 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_SlimChunk_ConstStateType Fee_30_FlexNor_SlimChunkReadLinkState = {
    &Fee_30_FlexNor_SlimChunk_ReadLink_ProcessEvent,
    &Fee_30_FlexNor_SlimChunk_ReadLink_FailEvent
};

/* PRQA S 3218 1 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_SlimChunk_ConstStateType Fee_30_FlexNor_SlimChunkCheckFirstInstanceState = {
    &Fee_30_FlexNor_SlimChunk_CheckFirstInstance_ProcessEvent,
    &Fee_30_FlexNor_SlimChunk_JobFailEvent
};

/* PRQA S 3218 1 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_SlimChunk_ConstStateType Fee_30_FlexNor_SlimChunkWritePropertiesState = {
    &Fee_30_FlexNor_SlimChunk_WriteProperties_ProcessEvent,
    &Fee_30_FlexNor_SlimChunk_WriteFailEvent
};

/* PRQA S 3218 1 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_SlimChunk_ConstStateType Fee_30_FlexNor_SlimChunkWritePredecessorLinkState = {
    &Fee_30_FlexNor_SlimChunk_WritePredecessorLink_ProcessEvent,
    &Fee_30_FlexNor_SlimChunk_JobFailEvent
};

FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_SlimChunk_ConstStateType Fee_30_FlexNor_SlimChunkWriteInstanceState = {
    &Fee_30_FlexNor_SlimChunk_WriteInstance_ProcessEvent,
    &Fee_30_FlexNor_SlimChunk_JobFailEvent
};

/* PRQA S 3218 1 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_SlimChunk_ConstStateType Fee_30_FlexNor_SlimChunkWriteCommitMarkerState = {
    &Fee_30_FlexNor_SlimChunk_WriteCommitMarker_ProcessEvent,
    &Fee_30_FlexNor_SlimChunk_WriteFailEvent
};

# define FEE_30_FLEXNOR_STOP_SEC_CONST_UNSPECIFIED
# include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
# define FEE_30_FLEXNOR_START_SEC_CODE
# include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimChunk_HandleCorruptedProperties()
 *********************************************************************************************************************/
/*! \brief          Do the necessary steps if corrupted properties were found.
 *  \details        -
 *  \param[in,out]  ctx     Pointer to the context for the state machine processing. Must not be NULL.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimChunk_HandleCorruptedProperties(Fee_30_FlexNor_SlimChunk_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimChunk_HandleCorruptedCommitMarker()
 *********************************************************************************************************************/
/*! \brief          Do the necessary steps if a corrupted commit marker was found.
 *  \details        -
 *  \param[in,out]  ctx     Pointer to the context for the state machine processing. Must not be NULL.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimChunk_HandleCorruptedCommitMarker(Fee_30_FlexNor_SlimChunk_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimChunk_HandleCorruptedLink()
 *********************************************************************************************************************/
/*! \brief          Do the necessary steps if a corrupted link was found.
 *  \details        -
 *  \param[in,out]  ctx     Pointer to the context for the state machine processing. Must not be NULL.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimChunk_HandleCorruptedLink(Fee_30_FlexNor_SlimChunk_ContextPtrType ctx);

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimChunk_HandleCorruptedProperties()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimChunk_HandleCorruptedProperties(Fee_30_FlexNor_SlimChunk_ContextPtrType ctx)
{
    ctx->Chunk.GenericChunk->Data.Validity = FEE_30_FLEXNOR_INVALID; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    ctx->Chunk.GenericChunk->Data.ErrorLocation = FEE_30_FLEXNOR_CHUNK_ERROR_PROPERTIES; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */

    ctx->CurrentState = &Fee_30_FlexNor_SlimChunkDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */

    Fee_30_FlexNor_SlimChunk_EndJob();
    ctx->ResultCallback(FEE_30_FLEXNOR_SERVICE_OK); /* SBSW_Fee_30_FlexNor_ContextFunctionPointerCall */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimChunk_HandleCorruptedCommitMarker()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimChunk_HandleCorruptedCommitMarker(Fee_30_FlexNor_SlimChunk_ContextPtrType ctx)
{
    ctx->Chunk.GenericChunk->Data.Validity = FEE_30_FLEXNOR_VALID; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    ctx->Chunk.GenericChunk->Data.ErrorLocation = FEE_30_FLEXNOR_CHUNK_ERROR_COMMITMARKER; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */

    ctx->CurrentState = &Fee_30_FlexNor_SlimChunkReadLinkState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_SlimChunk_ReadLink(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimChunk_HandleCorruptedLink()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimChunk_HandleCorruptedLink(Fee_30_FlexNor_SlimChunk_ContextPtrType ctx)
{
    ctx->Chunk.GenericChunk->Data.ChunkLink.Target = 0x0; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    ctx->Chunk.GenericChunk->Data.ChunkLink.Validity = FEE_30_FLEXNOR_INVALID; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_SlimChunk_EndJob();

    ctx->CurrentState = &Fee_30_FlexNor_SlimChunkDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    ctx->ResultCallback(FEE_30_FLEXNOR_SERVICE_OK); /* SBSW_Fee_30_FlexNor_ContextFunctionPointerCall */
}

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimChunk_InitState()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimChunk_InitState(Fee_30_FlexNor_SlimChunk_ContextPtrType ctx)
{
    ctx->CurrentState = &Fee_30_FlexNor_SlimChunkDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimChunk_DefaultProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimChunk_DefaultProcessEvent(
    Fee_30_FlexNor_SlimChunk_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    FEE_DUMMY_STATEMENT(ctx);
    return FEE_30_FLEXNOR_STOP_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimChunk_DefaultFailEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimChunk_DefaultFailEvent(
    Fee_30_FlexNor_SlimChunk_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    FEE_DUMMY_STATEMENT(ctx);
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimChunk_JobFailEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimChunk_JobFailEvent(Fee_30_FlexNor_SlimChunk_ContextPtrType ctx)
{
    ctx->CurrentState = &Fee_30_FlexNor_SlimChunkDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_SlimChunk_EndJob();
    ctx->ResultCallback(FEE_30_FLEXNOR_SERVICE_FAIL); /* SBSW_Fee_30_FlexNor_ContextFunctionPointerCall */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimChunk_WriteFailEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimChunk_WriteFailEvent(Fee_30_FlexNor_SlimChunk_ContextPtrType ctx)
{
    Fee_30_FlexNor_Chunk_RequestRecoveryGarbageCollection(
        ctx->PartitionConfig->PartitionId,
        ctx->Chunk.ConstGenericChunk->Data.StartAddress
    );

    ctx->CurrentState = &Fee_30_FlexNor_SlimChunkDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_SlimChunk_EndJob();
    ctx->ResultCallback(FEE_30_FLEXNOR_SERVICE_FAIL); /* SBSW_Fee_30_FlexNor_ContextFunctionPointerCall */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimChunk_ReadChunkHeader_FailEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimChunk_ReadChunkHeader_FailEvent(
    Fee_30_FlexNor_SlimChunk_ContextPtrType ctx)
{
    if(Fee_30_FlexNor_FlashAccess_GetReadJobResult() == FEE_30_FLEXNOR_FLASH_ECCERROR)
    {
        ctx->CurrentState = &Fee_30_FlexNor_SlimChunkReadPropertiesState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        Fee_30_FlexNor_SlimChunk_ReadProperties(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }
    else /* FEE_30_FLEXNOR_FLASH_FAIL */
    {
        Fee_30_FlexNor_SlimChunk_JobFailEvent(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimChunk_ReadProperties_FailEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimChunk_ReadProperties_FailEvent(Fee_30_FlexNor_SlimChunk_ContextPtrType ctx)
{
    if(Fee_30_FlexNor_FlashAccess_GetReadJobResult() == FEE_30_FLEXNOR_FLASH_ECCERROR)
    {
        Fee_30_FlexNor_SlimChunk_HandleCorruptedProperties(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }
    else /* FEE_30_FLEXNOR_FLASH_FAIL */
    {
        Fee_30_FlexNor_SlimChunk_JobFailEvent(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimChunk_ReadCommitMarker_FailEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimChunk_ReadCommitMarker_FailEvent(Fee_30_FlexNor_SlimChunk_ContextPtrType ctx)
{
    if(Fee_30_FlexNor_FlashAccess_GetReadJobResult() == FEE_30_FLEXNOR_FLASH_ECCERROR)
    {
        Fee_30_FlexNor_SlimChunk_HandleCorruptedCommitMarker(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }
    else /* FEE_30_FLEXNOR_FLASH_FAIL */
    {
        Fee_30_FlexNor_SlimChunk_JobFailEvent(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimChunk_ReadLink_FailEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimChunk_ReadLink_FailEvent(Fee_30_FlexNor_SlimChunk_ContextPtrType ctx)
{
    if(Fee_30_FlexNor_FlashAccess_GetReadJobResult() == FEE_30_FLEXNOR_FLASH_ECCERROR)
    {
        Fee_30_FlexNor_SlimChunk_HandleCorruptedLink(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }
    else /* FEE_30_FLEXNOR_FLASH_FAIL */
    {
        Fee_30_FlexNor_SlimChunk_JobFailEvent(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimChunk_ReadHeader_Initialize()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimChunk_ReadHeader_Initialize(Fee_30_FlexNor_SlimChunk_ContextPtrType ctx)
{
    Fee_30_FlexNor_SlimChunk_StartJob();

    ctx->CurrentState = &Fee_30_FlexNor_SlimChunkReadChunkHeaderState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_SlimChunk_ReadChunkHeader(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimChunk_ReadChunkHeader_ProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimChunk_ReadChunkHeader_ProcessEvent(Fee_30_FlexNor_SlimChunk_ContextPtrType ctx)
{
    ctx->Chunk.GenericChunk->Data.Validity = Fee_30_FlexNor_SlimChunk_ValidateChunkHeader(ctx); /* SBSW_Fee_30_FlexNor_ContextPointerAccess */ /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    ctx->Chunk.GenericChunk->Data.ChunkLink.Validity = Fee_30_FlexNor_SlimChunk_ValidateLink(ctx, FEE_30_FLEXNOR_CHUNK_VALIDATION_AS_WHOLE); /* SBSW_Fee_30_FlexNor_ContextPointerAccess */ /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */

    if((ctx->Chunk.GenericChunk->Data.Validity == FEE_30_FLEXNOR_INVALID) && 
        (ctx->Chunk.GenericChunk->Data.ErrorLocation == FEE_30_FLEXNOR_CHUNK_ERROR_COMMITMARKER))
    {
        ctx->CurrentState = &Fee_30_FlexNor_SlimChunkCheckFirstInstanceState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        Fee_30_FlexNor_SlimChunk_ReadFirstInstance(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }
    else
    {
        ctx->CurrentState = &Fee_30_FlexNor_SlimChunkDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */

        Fee_30_FlexNor_SlimChunk_EndJob();
        ctx->ResultCallback(FEE_30_FLEXNOR_SERVICE_OK); /* SBSW_Fee_30_FlexNor_ContextFunctionPointerCall */
    }

    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimChunk_ReadProperties_ProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimChunk_ReadProperties_ProcessEvent(Fee_30_FlexNor_SlimChunk_ContextPtrType ctx)
{
    Fee_30_FlexNor_StructureValidityType propertiesValidity = Fee_30_FlexNor_SlimChunk_ValidateProperties(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */

    if(propertiesValidity == FEE_30_FLEXNOR_VALID)
    {
        ctx->CurrentState = &Fee_30_FlexNor_SlimChunkReadCommitMarkerState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        Fee_30_FlexNor_SlimChunk_ReadCommitMarker(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }
    else if(propertiesValidity == FEE_30_FLEXNOR_INVALID)
    {
        Fee_30_FlexNor_SlimChunk_HandleCorruptedProperties(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }
    else
    {
        ctx->Chunk.GenericChunk->Data.Validity = FEE_30_FLEXNOR_EMPTY; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        ctx->Chunk.GenericChunk->Data.ChunkLink.Validity = FEE_30_FLEXNOR_EMPTY; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        ctx->Chunk.GenericChunk->Data.ErrorLocation = FEE_30_FLEXNOR_CHUNK_ERROR_NOERROR; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */

        ctx->CurrentState = &Fee_30_FlexNor_SlimChunkDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */

        Fee_30_FlexNor_SlimChunk_EndJob();
        ctx->ResultCallback(FEE_30_FLEXNOR_SERVICE_OK); /* SBSW_Fee_30_FlexNor_ContextFunctionPointerCall */
    }

    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimChunk_ReadCommitMarker_ProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimChunk_ReadCommitMarker_ProcessEvent(Fee_30_FlexNor_SlimChunk_ContextPtrType ctx)
{
    Fee_30_FlexNor_StructureValidityType commitMarkerValidity = Fee_30_FlexNor_SlimChunk_ValidateCommitMarker(ctx, FEE_30_FLEXNOR_CHUNK_VALIDATION_AS_SINGLE_PARTS); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */

    if(commitMarkerValidity == FEE_30_FLEXNOR_VALID)
    {
        ctx->Chunk.GenericChunk->Data.Validity = FEE_30_FLEXNOR_VALID; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */

        ctx->CurrentState = &Fee_30_FlexNor_SlimChunkReadLinkState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        Fee_30_FlexNor_SlimChunk_ReadLink(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }
    else if(commitMarkerValidity == FEE_30_FLEXNOR_INVALID)
    {
        Fee_30_FlexNor_SlimChunk_HandleCorruptedCommitMarker(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }
    else
    {
        ctx->Chunk.GenericChunk->Data.ErrorLocation = FEE_30_FLEXNOR_CHUNK_ERROR_COMMITMARKER; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        ctx->CurrentState = &Fee_30_FlexNor_SlimChunkCheckFirstInstanceState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        Fee_30_FlexNor_SlimChunk_ReadFirstInstance(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }

    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimChunk_CheckFirstInstance_ProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimChunk_CheckFirstInstance_ProcessEvent(Fee_30_FlexNor_SlimChunk_ContextPtrType ctx)
{
    Fee_30_FlexNor_StructureValidityType instanceValidity = Fee_30_FlexNor_SlimChunk_ValidateFirstInstance(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */

    if(instanceValidity == FEE_30_FLEXNOR_VALID)
    {
        ctx->Chunk.GenericChunk->Data.Validity = FEE_30_FLEXNOR_VALID; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */

        ctx->CurrentState = &Fee_30_FlexNor_SlimChunkReadLinkState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        Fee_30_FlexNor_SlimChunk_ReadLink(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }
    else
    {
        ctx->Chunk.GenericChunk->Data.Validity = FEE_30_FLEXNOR_INVALID; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        ctx->CurrentState = &Fee_30_FlexNor_SlimChunkDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */

        Fee_30_FlexNor_SlimChunk_EndJob();
        ctx->ResultCallback(FEE_30_FLEXNOR_SERVICE_OK); /* SBSW_Fee_30_FlexNor_ContextFunctionPointerCall */
    }

    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimChunk_ReadLink_ProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimChunk_ReadLink_ProcessEvent(Fee_30_FlexNor_SlimChunk_ContextPtrType ctx)
{
    ctx->Chunk.GenericChunk->Data.ChunkLink.Validity = Fee_30_FlexNor_SlimChunk_ValidateLink(ctx, FEE_30_FLEXNOR_CHUNK_VALIDATION_AS_SINGLE_PARTS); /* SBSW_Fee_30_FlexNor_ContextPointerAccess */ /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    Fee_30_FlexNor_SlimChunk_EndJob();

    ctx->CurrentState = &Fee_30_FlexNor_SlimChunkDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    ctx->ResultCallback(FEE_30_FLEXNOR_SERVICE_OK); /* SBSW_Fee_30_FlexNor_ContextFunctionPointerCall */

    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimChunk_Allocate_Initialize()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimChunk_Allocate_Initialize(Fee_30_FlexNor_SlimChunk_ContextPtrType ctx)
{
    Fee_30_FlexNor_SlimChunk_StartJob();
    ctx->CurrentState = &Fee_30_FlexNor_SlimChunkWritePropertiesState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_SlimChunk_WriteProperties(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimChunk_WriteProperties_ProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimChunk_WriteProperties_ProcessEvent(Fee_30_FlexNor_SlimChunk_ContextPtrType ctx)
{
    if ((ctx->PredecessorChunk == NULL_PTR) || (ctx->PredecessorChunk->Data.ChunkLink.Validity != FEE_30_FLEXNOR_EMPTY))
    {
        ctx->CurrentState = &Fee_30_FlexNor_SlimChunkWriteInstanceState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        Fee_30_FlexNor_Chunk_WriteInstanceAt(
            0u,
            ctx->Chunk.ConstGenericChunk,
            ctx->SourceInstance,
            ctx->TargetInstance,
            &Fee_30_FlexNor_SlimChunk_ResultHandler); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
    }
    else
    {
        ctx->CurrentState = &Fee_30_FlexNor_SlimChunkWritePredecessorLinkState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        ctx->PredecessorChunk->Services.WriteLink(
            ctx->PredecessorChunk,
            ctx->Chunk.ConstGenericChunk,
            &Fee_30_FlexNor_SlimChunk_ResultHandler); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
    }

    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimChunk_WritePredecessorLink_ProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimChunk_WritePredecessorLink_ProcessEvent(Fee_30_FlexNor_SlimChunk_ContextPtrType ctx)
{
    ctx->CurrentState = &Fee_30_FlexNor_SlimChunkWriteInstanceState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_Chunk_WriteInstanceAt(
        0u,
        ctx->Chunk.ConstGenericChunk,
        ctx->SourceInstance,
        ctx->TargetInstance,
        &Fee_30_FlexNor_SlimChunk_ResultHandler); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
        
    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimChunk_WriteInstance_ProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimChunk_WriteInstance_ProcessEvent(Fee_30_FlexNor_SlimChunk_ContextPtrType ctx)
{
    ctx->CurrentState = &Fee_30_FlexNor_SlimChunkWriteCommitMarkerState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_SlimChunk_WriteCommitMarker(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */

    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimChunk_WriteCommitMarker_ProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimChunk_WriteCommitMarker_ProcessEvent(Fee_30_FlexNor_SlimChunk_ContextPtrType ctx)
{
    Fee_30_FlexNor_SlimChunk_EndJob();
    ctx->CurrentState = &Fee_30_FlexNor_SlimChunkDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    ctx->ResultCallback(FEE_30_FLEXNOR_SERVICE_OK);            /* SBSW_Fee_30_FlexNor_ContextFunctionPointerCall */

    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

#define FEE_30_FLEXNOR_STOP_SEC_CODE
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif

/**********************************************************************************************************************
 *  END OF FILE: Fee_30_FlexNor_SlimChunkMachine.c
 *********************************************************************************************************************/
