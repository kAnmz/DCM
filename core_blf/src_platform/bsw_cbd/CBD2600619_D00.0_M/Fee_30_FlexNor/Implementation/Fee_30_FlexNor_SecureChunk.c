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
/*!        \file  Fee_30_FlexNor_SecureChunk.c
 *        \brief  Secure chunk unit implementation
 *      \details  Implementation of the chunk services based on the secure chunk layout.
 *         \unit  SecureChunk
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/
#define FEE_30_FLEXNOR_SECURECHUNK_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Fee_30_FlexNor_SecureChunk.h"
#include "Fee_30_FlexNor_ChunkInternal.h"
#include "Fee_30_FlexNor_SecureChunkInternal.h"
#include "Fee_30_FlexNor_SecureChunkMachine.h"

#include "Fee_30_FlexNor_Types.h"
#include "Fee_30_FlexNor_ConfigInterface.h"
#include "Fee_30_FlexNor_Scheduler.h"
#include "Fee_30_FlexNor_Shared.h"
#include "Fee_30_FlexNor_InternalJobs.h"
#include "Fee_30_FlexNor_FlashAccess.h"
#include "Fee_30_FlexNor_InstanceFactory.h"

#if (FEE_30_FLEXNOR_SECURELAYOUT_ENABLED == STD_ON) /* COV_MSR_UT_OPTIONAL_UNIT */

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

# define FEE_30_FLEXNOR_SECURECHUNKHEADER_RESERVED_INDEX 0x06u

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
#define FEE_30_FLEXNOR_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Context variable of the secure chunk state machine. */
FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_SecureChunk_ContextType Fee_30_FlexNor_SecureChunkStmContext = { 0u };

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
 * Fee_30_FlexNor_SecureChunk_ProcessingHandler()
 *********************************************************************************************************************/
/*! \brief       Handles the processing event
 *  \details     Triggers the Process event at the local state machine.
 *  \return      FEE_30_FLEXNOR_STOP_SCHEDULE       In case the scheduling shall be stopped
 *               FEE_30_FLEXNOR_CONTINUE_SCHEDULE   In case the scheduling can be continued
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FEE_30_FLEXNOR_LOCAL FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureChunk_ProcessingHandler(void);


/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureChunk_GetAlignedCommitMarkerSize()
 *********************************************************************************************************************/
/*! \brief       Gets the aligned size of the chunk commit marker
 *  \details     -
 *  \param[in]   pageAlignment               Page alignment in bytes
 *  \param[in]   interferenceFreeAlignment   Interference free alignment in bytes
 *  \return      The aligned size of the chunk commit marker
 *  \pre         -
 *  \context     TASK
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FEE_30_FLEXNOR_LOCAL_INLINE FUNC(uint32, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureChunk_GetAlignedCommitMarkerSize(uint16 pageAlignment, uint16 interferenceFreeAlignment);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureChunk_GetCommitMarkerOffset()
 *********************************************************************************************************************/
/*! \brief       Gets the offset of the commit marker relative to the chunk's start address
 *  \details     -
 *  \param[in]   pageAlignment               Page alignment in bytes
 *  \param[in]   interferenceFreeAlignment   Interference free alignment in bytes
 *  \return      The commit marker offset in bytes
 *  \pre         -
 *  \context     TASK
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FEE_30_FLEXNOR_LOCAL_INLINE FUNC(uint32, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureChunk_GetCommitMarkerOffset(uint16 pageAlignment, uint16 interferenceFreeAlignment);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureChunk_GetAlignedMetadataSize()
 *********************************************************************************************************************/
/*! \brief       Gets the aligned size of the metadata.
 *  \details     Gets the aligned size of the metadata. Does not contain the chunk link.
 *  \param[in]   pageAlignment               Page alignment in bytes
 *  \param[in]   interferenceFreeAlignment   Interference free alignment in bytes
 *  \return      The aligned size of the metadata
 *  \pre         -
 *  \context     TASK
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FEE_30_FLEXNOR_LOCAL_INLINE FUNC(uint32, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureChunk_GetAlignedMetadataSize(uint16 pageAlignment, uint16 interferenceFreeAlignment);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureChunk_GetAlignedHeaderSize()
 *********************************************************************************************************************/
/*! \brief       Gets the aligned size of the header.
 *  \details     Gets the aligned size of the header. Contains the metadata and the chunk link.
 *  \param[in]   pageAlignment               Page alignment in bytes
 *  \param[in]   interferenceFreeAlignment   Interference free alignment in bytes
 *  \return      The aligned size of the header
 *  \pre         -
 *  \context     TASK
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FEE_30_FLEXNOR_LOCAL_INLINE FUNC(uint32, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureChunk_GetAlignedHeaderSize(uint16 pageAlignment, uint16 interferenceFreeAlignment);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureChunk_SetChunkPropertiesToBuffer()
 *********************************************************************************************************************/
/*! \brief       Copies BlockId, PayloadSize and Instance Count to their proprer position in the chunk buffer.
 *  \details     -
 *  \param[in]   ctx               Context of the chunk. Must not be NULL.
 *  \param[in]   propertiesOffset  Offset of the properties in the buffer.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FEE_30_FLEXNOR_LOCAL FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureChunk_SetChunkPropertiesToBuffer(
    Fee_30_FlexNor_SecureChunk_ContextPtrType ctx,
    Fee_30_FlexNor_LengthType propertiesOffset);


/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureChunk_ProcessingHandler()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FEE_30_FLEXNOR_LOCAL FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureChunk_ProcessingHandler(void)
{
    return Fee_30_FlexNor_SecureChunkStmContext.CurrentState->ProcessEvent(&Fee_30_FlexNor_SecureChunkStmContext); /* SBSW_Fee_30_FlexNor_TriggerEventAtState */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureChunk_ResultHandler()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureChunk_ResultHandler(Fee_30_FlexNor_ServiceResult result)
{
    if (result == FEE_30_FLEXNOR_SERVICE_FAIL)
    {
        Fee_30_FlexNor_SecureChunkStmContext.CurrentState->FailEvent(&Fee_30_FlexNor_SecureChunkStmContext); /* SBSW_Fee_30_FlexNor_TriggerEventAtState */
    }
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureChunk_GetAlignedCommitMarkerSize()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FEE_30_FLEXNOR_LOCAL_INLINE FUNC(uint32, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureChunk_GetAlignedCommitMarkerSize(
    uint16 pageAlignment,
    uint16 interferenceFreeAlignment)
{
    return Fee_30_FlexNor_Shared_AlignUp(pageAlignment, interferenceFreeAlignment);
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureChunk_GetChunkPropertiesSize()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FEE_30_FLEXNOR_LOCAL_INLINE FUNC(uint32, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureChunk_GetChunkPropertiesSize(void)
{
    return sizeof(Fee_30_FlexNor_BlockIdType) + sizeof(Fee_30_FlexNor_PayloadSizeType) + sizeof(Fee_30_FlexNor_InstanceCountType) + sizeof(uint8) + /* Reserved byte */
           sizeof(Fee_30_FlexNor_ChecksumType);
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureChunk_GetAlignedMetadataSize()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FEE_30_FLEXNOR_LOCAL_INLINE FUNC(uint32, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureChunk_GetAlignedMetadataSize(uint16 pageAlignment, uint16 interferenceFreeAlignment)
{
    uint32 commitMarkerOffset      = Fee_30_FlexNor_SecureChunk_GetCommitMarkerOffset(pageAlignment, interferenceFreeAlignment);
    uint32 alignedCommitMarkerSize = Fee_30_FlexNor_SecureChunk_GetAlignedCommitMarkerSize(pageAlignment, interferenceFreeAlignment);

    return commitMarkerOffset + alignedCommitMarkerSize;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureChunk_GetAlignedHeaderSize()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FEE_30_FLEXNOR_LOCAL_INLINE FUNC(uint32, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureChunk_GetAlignedHeaderSize(uint16 pageAlignment, uint16 interferenceFreeAlignment)
{
    uint32 alignedMetadataSize = Fee_30_FlexNor_SecureChunk_GetAlignedMetadataSize(pageAlignment, interferenceFreeAlignment);
    uint32 alignedLinkSize     = Fee_30_FlexNor_Chunk_GetAlignedLinkSize(interferenceFreeAlignment);
    return alignedMetadataSize + alignedLinkSize;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureChunk_GetCommitMarkerOffset()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FEE_30_FLEXNOR_LOCAL_INLINE FUNC(uint32, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureChunk_GetCommitMarkerOffset(uint16 pageAlignment, uint16 interferenceFreeAlignment)
{
    uint32 chunkPropertiesSize    = Fee_30_FlexNor_SecureChunk_GetChunkPropertiesSize();
    return Fee_30_FlexNor_Shared_AlignUp(pageAlignment + chunkPropertiesSize, interferenceFreeAlignment); /* The start marker has the size of one page. */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureChunk_SetChunkPropertiesToBuffer()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FEE_30_FLEXNOR_LOCAL FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureChunk_SetChunkPropertiesToBuffer(
    Fee_30_FlexNor_SecureChunk_ContextPtrType ctx, /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
    Fee_30_FlexNor_LengthType propertiesOffset) 
{
    /* Set the chunk properties to the buffer */
    Fee_30_FlexNor_Shared_SetValueToBuffer(
        ctx->Chunk.ConstGenericChunk->Data.BlockId,
        ctx->ChunkBuffer,
        sizeof(Fee_30_FlexNor_BlockIdType),
        propertiesOffset); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    Fee_30_FlexNor_Shared_SetValueToBuffer(
        ctx->Chunk.ConstGenericChunk->Data.PayloadSize,
        ctx->ChunkBuffer,
        sizeof(Fee_30_FlexNor_PayloadSizeType),
        propertiesOffset + sizeof(Fee_30_FlexNor_BlockIdType)); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    Fee_30_FlexNor_Shared_SetValueToBuffer(
        ctx->Chunk.ConstGenericChunk->Data.InstanceCount,
        ctx->ChunkBuffer,
        sizeof(Fee_30_FlexNor_InstanceCountType),
        propertiesOffset + sizeof(Fee_30_FlexNor_BlockIdType) + sizeof(Fee_30_FlexNor_PayloadSizeType)); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
}

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureChunk_Init()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureChunk_Init(void)
{
    Fee_30_FlexNor_SecureChunkStmContext.ChunkBuffer = Fee_30_FlexNor_ConfigInterface_GetInternalBuffer();
    Fee_30_FlexNor_SecureChunk_InitState(&Fee_30_FlexNor_SecureChunkStmContext); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureChunk_StartJob()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureChunk_StartJob(void)
{
    Fee_30_FlexNor_Scheduler_RegisterUnit(&Fee_30_FlexNor_SecureChunk_ProcessingHandler); /* SBSW_Fee_30_FlexNor_RegisterUnit */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureChunk_EndJob()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureChunk_EndJob(void)
{
    Fee_30_FlexNor_Scheduler_UnregisterUnit();
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureChunk_ReadHeader()
 *********************************************************************************************************************/
/*! 
 * Internal comment removed. *
 *
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureChunk_ReadHeader(Fee_30_FlexNor_ChunkPtrType chunk, Fee_30_FlexNor_ResultCallback resultCbk)
{
    Fee_30_FlexNor_SecureChunkStmContext.Chunk.GenericChunk = chunk;
    Fee_30_FlexNor_SecureChunkStmContext.ResultCallback = resultCbk;

    Fee_30_FlexNor_SecureChunkStmContext.Chunk.GenericChunk->Data.ErrorLocation = FEE_30_FLEXNOR_CHUNK_ERROR_NOERROR; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_SecureChunkStmContext.Chunk.GenericChunk->Data.ChunkLink.Target = 0x0u; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_SecureChunkStmContext.Chunk.GenericChunk->Data.ChunkLink.Validity = FEE_30_FLEXNOR_INVALID; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */

    Fee_30_FlexNor_SecureChunkStmContext.PartitionConfig = Fee_30_FlexNor_ConfigInterface_GetPartitionConfig(chunk->Data.PartitionId);

    Fee_30_FlexNor_SecureChunk_ReadHeader_Initialize(&Fee_30_FlexNor_SecureChunkStmContext); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureChunk_ValidateChunkHeader()
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
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureChunk_ValidateChunkHeader(Fee_30_FlexNor_SecureChunk_ConstContextPtrType ctx)
{
    Fee_30_FlexNor_StructureValidityType validationResult = Fee_30_FlexNor_SecureChunk_ValidateStartMarker(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    if (validationResult == FEE_30_FLEXNOR_VALID)
    {
        Fee_30_FlexNor_StructureValidityType propertiesValidity = 
            Fee_30_FlexNor_SecureChunk_ValidateProperties(ctx, FEE_30_FLEXNOR_CHUNK_VALIDATION_AS_WHOLE); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

        if(propertiesValidity == FEE_30_FLEXNOR_VALID)
        {
            Fee_30_FlexNor_StructureValidityType commitMarkerValidity = 
                Fee_30_FlexNor_SecureChunk_ValidateCommitMarker(ctx, FEE_30_FLEXNOR_CHUNK_VALIDATION_AS_WHOLE); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

            if(commitMarkerValidity == FEE_30_FLEXNOR_VALID)
            {
                validationResult = FEE_30_FLEXNOR_VALID;
                ctx->Chunk.GenericChunk->Data.ErrorLocation = FEE_30_FLEXNOR_CHUNK_ERROR_NOERROR; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
            }
            else if(commitMarkerValidity == FEE_30_FLEXNOR_INVALID)
            {
                validationResult = FEE_30_FLEXNOR_VALID;
                ctx->Chunk.GenericChunk->Data.ErrorLocation = FEE_30_FLEXNOR_CHUNK_ERROR_COMMITMARKER; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */

                ctx->Chunk.GenericChunk->Data.ReallocationRequired = TRUE; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
            }
            else
            {
                validationResult = FEE_30_FLEXNOR_INVALID;
                ctx->Chunk.GenericChunk->Data.ErrorLocation = FEE_30_FLEXNOR_CHUNK_ERROR_COMMITMARKER; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
            }
        }
        else
        {
            validationResult = FEE_30_FLEXNOR_INVALID;
            ctx->Chunk.GenericChunk->Data.ErrorLocation = FEE_30_FLEXNOR_CHUNK_ERROR_PROPERTIES; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */

            Fee_30_FlexNor_Chunk_RequestRecoveryGarbageCollection(
                ctx->PartitionConfig->PartitionId,
                ctx->Chunk.GenericChunk->Data.StartAddress
            );

        }
    }
    else if(validationResult == FEE_30_FLEXNOR_INVALID)
    {
        ctx->Chunk.GenericChunk->Data.ErrorLocation = FEE_30_FLEXNOR_CHUNK_ERROR_STARTMARKER; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */

        Fee_30_FlexNor_Chunk_RequestRecoveryGarbageCollection(
            ctx->PartitionConfig->PartitionId,
            ctx->Chunk.GenericChunk->Data.StartAddress
        );
    }
    else
    {
        ctx->Chunk.GenericChunk->Data.ErrorLocation = FEE_30_FLEXNOR_CHUNK_ERROR_NOERROR; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */        
    }

    ctx->Chunk.GenericChunk->Data.Validity = validationResult; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureChunk_ReadChunkHeader()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureChunk_ReadChunkHeader(
    Fee_30_FlexNor_SecureChunk_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    Fee_30_FlexNor_LengthType headerLength = Fee_30_FlexNor_SecureChunk_GetAlignedHeaderSize(ctx->PartitionConfig->PageAlignment, ctx->PartitionConfig->InterferenceFreeAlignment);

    Fee_30_FlexNor_Shared_SetBufferValues(ctx->ChunkBuffer, headerLength, 0x0); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    Fee_30_FlexNor_FlashAccess_ReadFlash(
        ctx->Chunk.GenericChunk->Data.PartitionId,
        ctx->Chunk.GenericChunk->Data.StartAddress,
        ctx->ChunkBuffer,
        headerLength,
        &Fee_30_FlexNor_SecureChunk_ResultHandler); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
}


/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureChunk_GetHeaderSize()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(uint32, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureChunk_GetHeaderSize(Fee_30_FlexNor_ConstChunkPtrType chunk)
{
    Fee_30_FlexNor_ConstPartitionConfigPtrType partitionConfigPtr = Fee_30_FlexNor_ConfigInterface_GetPartitionConfig(chunk->Data.PartitionId);
    return Fee_30_FlexNor_SecureChunk_GetAlignedHeaderSize(partitionConfigPtr->PageAlignment, partitionConfigPtr->InterferenceFreeAlignment);
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureChunk_GetTotalSize()
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
 */
FUNC(uint32, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureChunk_GetTotalSize(Fee_30_FlexNor_ConstChunkPtrType chunk)
{
    uint32 totalChunkSize = 0u;
    uint32 alignedHeaderSize = Fee_30_FlexNor_SecureChunk_GetHeaderSize(chunk); /* SBSW_Fee_30_FlexNor_FunctionCallWithGivenPointer */

    if (chunk->Data.Validity == FEE_30_FLEXNOR_EMPTY)
    {
        totalChunkSize = 0u;
    }
    else if ((chunk->Data.ErrorLocation == FEE_30_FLEXNOR_CHUNK_ERROR_PROPERTIES) || (chunk->Data.ErrorLocation == FEE_30_FLEXNOR_CHUNK_ERROR_STARTMARKER))
    {
        totalChunkSize = alignedHeaderSize;
    }
    else
    {
        Fee_30_FlexNor_InstanceType instance = { 
            .Data = 
            {
                .Validity = FEE_30_FLEXNOR_INVALID,
                .Status = FEE_30_FLEXNOR_INSTANCE_VALID,
                .ReallocationRequired = FALSE,
                .StartAddress = 0u,
                .PartitionId = 0u,
                .ReadBuffer = NULL_PTR,
                .WriteBuffer = NULL_PTR,
                .PayloadSize = 0u,
                .PayloadOffset = 0u
            },
            .Services = { 0u }
        };

        Fee_30_FlexNor_InstanceFactory_CreateInstance(0x0, chunk->Data.PartitionId, &instance); /* SBSW_Fee_30_FlexNor_FunctionCallWithPointerToLocal */
        instance.Data.PayloadSize = chunk->Data.PayloadSize;

        totalChunkSize = alignedHeaderSize +
            (chunk->Data.InstanceCount * instance.Services.GetTotalSize(&instance.Data)); /* SBSW_Fee_30_FlexNor_FunctionPointerCallFromCreatedObject */
    }

    return totalChunkSize;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureChunk_Allocate()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureChunk_Allocate(
    Fee_30_FlexNor_ConstChunkPtrType chunk,
    Fee_30_FlexNor_ChunkPtrType predecessorChunk,
    Fee_30_FlexNor_ConstInstancePtrType sourceInstance,
    Fee_30_FlexNor_InstancePtrType targetInstance,
    Fee_30_FlexNor_ResultCallback resultCbk)
{
    Fee_30_FlexNor_SecureChunkStmContext.Chunk.ConstGenericChunk = chunk;
    Fee_30_FlexNor_SecureChunkStmContext.PredecessorChunk        = predecessorChunk;
    Fee_30_FlexNor_SecureChunkStmContext.SourceInstance          = sourceInstance;
    Fee_30_FlexNor_SecureChunkStmContext.TargetInstance          = targetInstance;
    Fee_30_FlexNor_SecureChunkStmContext.ResultCallback          = resultCbk;

    Fee_30_FlexNor_SecureChunkStmContext.PartitionConfig = Fee_30_FlexNor_ConfigInterface_GetPartitionConfig(chunk->Data.PartitionId);
    Fee_30_FlexNor_SecureChunk_Allocate_Initialize(&Fee_30_FlexNor_SecureChunkStmContext); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureChunk_WriteStartMarker()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureChunk_WriteStartMarker(
    Fee_30_FlexNor_SecureChunk_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    Fee_30_FlexNor_LengthType alignedStartMarkerSize = ctx->PartitionConfig->PageAlignment;

    Fee_30_FlexNor_Shared_SetBufferValues(
        ctx->ChunkBuffer, /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
        alignedStartMarkerSize,
        (Fee_30_FlexNor_DataType) Fee_30_FlexNor_ChunkStartMarker);

    Fee_30_FlexNor_FlashAccess_WriteFlash(
        ctx->Chunk.ConstGenericChunk->Data.PartitionId,
        ctx->Chunk.ConstGenericChunk->Data.StartAddress,
        ctx->ChunkBuffer,
        alignedStartMarkerSize,
        &Fee_30_FlexNor_SecureChunk_ResultHandler); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureChunk_WriteProperties()
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
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureChunk_WriteProperties(
    Fee_30_FlexNor_SecureChunk_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    Fee_30_FlexNor_LengthType alignedStartMarkerSize = ctx->PartitionConfig->PageAlignment;
    Fee_30_FlexNor_LengthType commitMarkerOffset = Fee_30_FlexNor_SecureChunk_GetCommitMarkerOffset(ctx->PartitionConfig->PageAlignment, 
                                                                                                    ctx->PartitionConfig->InterferenceFreeAlignment);
                                                                                                  
    Fee_30_FlexNor_LengthType alignedPropertiesSize  = commitMarkerOffset - alignedStartMarkerSize;

    Fee_30_FlexNor_Shared_SetBufferValues(
        ctx->ChunkBuffer,
        alignedPropertiesSize,
        ctx->PartitionConfig->ErasedValue); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    /* Set the properties to index 0 of the buffer. The correct offset relative to the chunk start is added by the WriteFlash call */
    Fee_30_FlexNor_SecureChunk_SetChunkPropertiesToBuffer(ctx, 0u); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    /* Explicitly set the reserved byte to zero */
    ctx->ChunkBuffer[FEE_30_FLEXNOR_SECURECHUNKHEADER_RESERVED_INDEX] = 0x0u; /* SBSW_Fee_30_FlexNor_ModifyContextArray */

    /* Calculate and set the checksum */
    Fee_30_FlexNor_LengthType checksumOffset = sizeof(Fee_30_FlexNor_BlockIdType) + 
                                               sizeof(Fee_30_FlexNor_PayloadSizeType) + sizeof(Fee_30_FlexNor_InstanceCountType) + 0x01u; /* +1u because of the reserved byte */

    /* The checksum offset acts as the length for the checksum calculation because all previous data shall be included in the checksum */
    ctx->ChunkBuffer[checksumOffset] = Fee_30_FlexNor_Shared_CalculateChecksum(ctx->ChunkBuffer, checksumOffset, 0); /* SBSW_Fee_30_FlexNor_ModifyContextArray */ /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    /* Write properties to flash */
    Fee_30_FlexNor_FlashAccess_WriteFlash(
        ctx->Chunk.ConstGenericChunk->Data.PartitionId,
        ctx->Chunk.ConstGenericChunk->Data.StartAddress + alignedStartMarkerSize,
        ctx->ChunkBuffer,
        alignedPropertiesSize,
        &Fee_30_FlexNor_SecureChunk_ResultHandler); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureChunk_WriteCommitMarker()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureChunk_WriteCommitMarker(
    Fee_30_FlexNor_SecureChunk_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    Fee_30_FlexNor_LengthType commitMarkerOffset      = Fee_30_FlexNor_SecureChunk_GetCommitMarkerOffset(ctx->PartitionConfig->PageAlignment, ctx->PartitionConfig->InterferenceFreeAlignment);
    Fee_30_FlexNor_LengthType alignedCommitMarkerSize = ctx->PartitionConfig->PageAlignment;

    Fee_30_FlexNor_Shared_SetBufferValues(
        ctx->ChunkBuffer,
        ctx->PartitionConfig->InterferenceFreeAlignment,
        ctx->PartitionConfig->ErasedValue); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    Fee_30_FlexNor_Shared_SetBufferValues(
        ctx->ChunkBuffer, /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
        alignedCommitMarkerSize,
        (Fee_30_FlexNor_DataType) Fee_30_FlexNor_CommitMarker);

    Fee_30_FlexNor_FlashAccess_WriteFlash(
        ctx->Chunk.ConstGenericChunk->Data.PartitionId,
        ctx->Chunk.ConstGenericChunk->Data.StartAddress + commitMarkerOffset,
        ctx->ChunkBuffer,
        ctx->PartitionConfig->InterferenceFreeAlignment,
        &Fee_30_FlexNor_SecureChunk_ResultHandler); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureChunk_ReadStartMarker()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureChunk_ReadStartMarker(Fee_30_FlexNor_SecureChunk_ConstContextPtrType ctx)
{
    Fee_30_FlexNor_AddressType startMarkerOffset = 0u;
    Fee_30_FlexNor_Chunk_ReadMarker(
        ctx->ChunkBuffer, 
        ctx->Chunk.GenericChunk,
        startMarkerOffset,
        ctx->PartitionConfig, 
        &Fee_30_FlexNor_SecureChunk_ResultHandler); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureChunk_ValidateStartMarker()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Fee_30_FlexNor_StructureValidityType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureChunk_ValidateStartMarker(Fee_30_FlexNor_SecureChunk_ConstContextPtrType ctx)
{ 
    Fee_30_FlexNor_AddressType startMarkerOffset = 0u;

    return Fee_30_FlexNor_Shared_GetMarkerValidity(
        ctx->ChunkBuffer, 
        startMarkerOffset, 
        Fee_30_FlexNor_ChunkStartMarker, 
        ctx->PartitionConfig->PageAlignment, 
        ctx->PartitionConfig->ErasedValue); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureChunk_ReadProperties()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureChunk_ReadProperties(Fee_30_FlexNor_SecureChunk_ConstContextPtrType ctx)
{
    Fee_30_FlexNor_Chunk_ReadProperties(
        ctx->ChunkBuffer, 
        ctx->Chunk.GenericChunk, 
        ctx->PartitionConfig->PageAlignment, /* Skip the start marker which occupies the first page. */
        ctx->PartitionConfig,
        &Fee_30_FlexNor_SecureChunk_ResultHandler); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureChunk_ValidateProperties()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Fee_30_FlexNor_StructureValidityType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureChunk_ValidateProperties(
    Fee_30_FlexNor_SecureChunk_ConstContextPtrType ctx,
    Fee_30_FlexNor_ChunkHeaderValidationStrategy strategy)
{
    Fee_30_FlexNor_AddressType propertiesOffset = ctx->PartitionConfig->PageAlignment; /* Start marker size */
    Fee_30_FlexNor_AddressType validationOffset = (strategy == FEE_30_FLEXNOR_CHUNK_VALIDATION_AS_WHOLE) ? propertiesOffset : 0u;
    return Fee_30_FlexNor_Chunk_ValidateProperties(ctx->ChunkBuffer, ctx->Chunk.GenericChunk, validationOffset, ctx->PartitionConfig); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureChunk_ReadCommitMarker()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureChunk_ReadCommitMarker(Fee_30_FlexNor_SecureChunk_ConstContextPtrType ctx)
{
    Fee_30_FlexNor_AddressType commitMarkerOffset = 
        Fee_30_FlexNor_SecureChunk_GetCommitMarkerOffset(ctx->PartitionConfig->PageAlignment, ctx->PartitionConfig->InterferenceFreeAlignment);

    Fee_30_FlexNor_Chunk_ReadMarker(
        ctx->ChunkBuffer, 
        ctx->Chunk.GenericChunk,
        commitMarkerOffset,
        ctx->PartitionConfig, 
        &Fee_30_FlexNor_SecureChunk_ResultHandler); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureChunk_ValidateCommitMarker()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Fee_30_FlexNor_StructureValidityType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureChunk_ValidateCommitMarker(
    Fee_30_FlexNor_SecureChunk_ConstContextPtrType ctx,
    Fee_30_FlexNor_ChunkHeaderValidationStrategy strategy)
{
    Fee_30_FlexNor_AddressType commitMarkerOffset = 
        Fee_30_FlexNor_SecureChunk_GetCommitMarkerOffset(ctx->PartitionConfig->PageAlignment, ctx->PartitionConfig->InterferenceFreeAlignment);

    Fee_30_FlexNor_AddressType validationOffset = (strategy == FEE_30_FLEXNOR_CHUNK_VALIDATION_AS_WHOLE) ? commitMarkerOffset : 0u;

    return Fee_30_FlexNor_Shared_GetMarkerValidity(
        ctx->ChunkBuffer, 
        validationOffset, 
        Fee_30_FlexNor_CommitMarker, 
        ctx->PartitionConfig->PageAlignment, 
        ctx->PartitionConfig->ErasedValue); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureChunk_ReadFirstInstance()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureChunk_ReadFirstInstance(Fee_30_FlexNor_SecureChunk_ContextPtrType ctx)
{
    const Fee_30_FlexNor_ChunkInstanceIndex firstIndex = 0u;

    /* Validate here means that the instance is read as first step, but not evaluated yet */
    Fee_30_FlexNor_Chunk_ValidateInstanceAt(
        firstIndex,
        (Fee_30_FlexNor_ConstChunkPtrType)ctx->Chunk.GenericChunk,
        &ctx->Instance,
        &Fee_30_FlexNor_SecureChunk_ResultHandler); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureChunk_ValidateFirstInstance()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Fee_30_FlexNor_StructureValidityType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureChunk_ValidateFirstInstance(Fee_30_FlexNor_SecureChunk_ConstContextPtrType ctx)
{
    return ctx->Instance.Data.Validity; 
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureChunk_ReadLink()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureChunk_ReadLink(Fee_30_FlexNor_SecureChunk_ConstContextPtrType ctx)
{
    Fee_30_FlexNor_AddressType linkOffset = 
        Fee_30_FlexNor_SecureChunk_GetAlignedMetadataSize(ctx->PartitionConfig->PageAlignment, ctx->PartitionConfig->InterferenceFreeAlignment);

    Fee_30_FlexNor_Chunk_ReadLink(
        ctx->ChunkBuffer, 
        ctx->Chunk.GenericChunk,
        linkOffset,
        ctx->PartitionConfig,
        &Fee_30_FlexNor_SecureChunk_ResultHandler); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureChunk_ValidateLink()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Fee_30_FlexNor_StructureValidityType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureChunk_ValidateLink(
    Fee_30_FlexNor_SecureChunk_ConstContextPtrType ctx,
    Fee_30_FlexNor_ChunkHeaderValidationStrategy strategy)
{
    Fee_30_FlexNor_AddressType linkOffset = 
        Fee_30_FlexNor_SecureChunk_GetAlignedMetadataSize(ctx->PartitionConfig->PageAlignment, ctx->PartitionConfig->InterferenceFreeAlignment);

    Fee_30_FlexNor_AddressType validationOffset = (strategy == FEE_30_FLEXNOR_CHUNK_VALIDATION_AS_WHOLE) ? linkOffset : 0u;

    return Fee_30_FlexNor_Chunk_ValidateLink(
        ctx->ChunkBuffer, 
        ctx->Chunk.GenericChunk,
        validationOffset,
        ctx->PartitionConfig); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
}

#define FEE_30_FLEXNOR_STOP_SEC_CODE
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif

/**********************************************************************************************************************
 *  END OF FILE: Fee_30_FlexNor_SecureChunk.c
 *********************************************************************************************************************/
