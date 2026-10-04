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
/*!        \file  Fee_30_FlexNor_Instance.c
 *        \brief  Instance unit implementation
 *      \details  Implementation of the instance services based on no specific layout.
 *         \unit  SecureInstance
 *         \unit  SlimInstance
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#define FEE_30_FLEXNOR_INSTANCE_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Fee_30_FlexNor_InstanceInternal.h"

#include "Fee_30_FlexNor_ConfigInterface.h"
#include "Fee_30_FlexNor_Shared.h"
#include "Fee_30_FlexNor_InternalJobs.h"
#include "Fee_30_FlexNor_FlashAccess.h"
#include "Fee_30_FlexNor_DiagnosticHandler.h"

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
#    define FEE_30_FLEXNOR_CONTENT_STATUS_INDEX (0x0u)

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

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define FEE_30_FLEXNOR_START_SEC_CODE
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
/**********************************************************************************************************************
 * Fee_30_FlexNor_Instance_WritePayloadViaInternalBuffer
 *********************************************************************************************************************/
/*! \brief       Writes the corresponding part of the instance via the internal buffer.
 *  \details     Adds the status byte(s) at the beginning if necessary
 *  \param[in]   ctx            Context for the instance payload write.
 *  \param[in]       instance       Instance that shall be written
 *  \param[in]       metadataSize   Size of the metadata, depending on the target layout
 *  \param[in]       resultCbk      Pointer to the result handler for the flash write jobs.
 *  \return      Number of bytes written in this step
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_LengthType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Instance_WritePayloadViaInternalBuffer(
    Fee_30_FlexNor_Instance_ConstContextPtrType ctx,
    Fee_30_FlexNor_ConstInstanceDataPtrType instance,
    Fee_30_FlexNor_LengthType metadataSize,
    Fee_30_FlexNor_ResultCallback resultCbk);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Instance_WritePayloadViaUserBuffer
 *********************************************************************************************************************/
/*! \brief       Writes the middle part of the instance via the user buffer.
 *  \details     Number of bytes that are written depends on the alignment. This function only writes in multiples of the alignment.
 *  \param[in]   ctx            Context for the instance payload write.
 *  \param[in]       instance       Instance that shall be written
 *  \param[in]       metadataSize   Size of the metadata, depending on the target layout
 *  \param[in]       resultCbk      Pointer to the result handler for the flash write jobs. 
 *  \return      Number of bytes written in this step
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_LengthType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Instance_WritePayloadViaUserBuffer(
    Fee_30_FlexNor_Instance_ConstContextPtrType ctx,
    Fee_30_FlexNor_ConstInstanceDataPtrType instance,
    Fee_30_FlexNor_LengthType metadataSize,
    Fee_30_FlexNor_ResultCallback resultCbk);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Instance_PrepareInternalBufferForFirstWrite
 *********************************************************************************************************************/
/*! \brief       Prepares the buffer for the first write step.
 *  \details     Adds status bytes and corresponding number of payload bytes to the buffer.
 *  \param[in]   ctx                  Context for the instance payload write.
 *  \param[in]       instance             Instance that shall be written
 *  \return      Number of bytes in buffer, always aligned.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_LengthType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Instance_PrepareInternalBufferForFirstWrite(
    Fee_30_FlexNor_Instance_ConstContextPtrType ctx,
    Fee_30_FlexNor_ConstInstanceDataPtrType instance);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Instance_PrepareInternalBufferForLastWrite
 *********************************************************************************************************************/
/*! \brief       Prepares the buffer for the last write step.
 *  \details     Adds the corresponding number of payload bytes to the buffer.
 *  \param[in]   ctx                  Context for the instance payload write.
 *  \param[in]       instance             Instance that shall be written
 *  \return      Number of bytes in buffer, always aligned
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_LengthType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Instance_PrepareInternalBufferForLastWrite(
    Fee_30_FlexNor_Instance_ConstContextPtrType ctx,
    Fee_30_FlexNor_ConstInstanceDataPtrType instance);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Instance_PrepareInternalBuffer
 *********************************************************************************************************************/
/*! \brief       Prepares the buffer with payload bytes.
 *  \details     Also recognizes if status bytes must be added to buffer too.
 *  \param[in]   ctx            Context for the instance payload write.
 *  \param[in]   instance       Instance that shall be written.
 *  \return      Number of bytes in buffer, always aligned.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_LengthType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Instance_PrepareInternalBuffer(
    Fee_30_FlexNor_Instance_ConstContextPtrType ctx,
    Fee_30_FlexNor_ConstInstanceDataPtrType instance);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Instance_GetNextCopyStepSize()
 *********************************************************************************************************************/
/*! \brief       Calculates the next copy step size based on the already copied payload and the total content size
 *  \details     -
 *  \param[in]   ctx                Context containing the copy progress and the source instance required for the calculation.
 *  \param[in]   instance           Target instance.
 *  \return      Size of the next copy step.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_LengthType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Instance_GetNextCopyStepSize(
    Fee_30_FlexNor_Instance_ConstContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Instance_GetRemainingContentBytes()
 *********************************************************************************************************************/
/*! \brief       Calculates the number of content bytes that are still left to be written
 *  \details     -
 *  \param[in]   ctx                Context containing the write progress.
 *  \return      Number of remaining content bytes.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_LengthType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Instance_GetRemainingContentBytes(
    Fee_30_FlexNor_Instance_ConstContextPtrType ctx,
    Fee_30_FlexNor_ConstInstanceDataPtrType instance);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Instance_CalculateContentStartAddress()
 *********************************************************************************************************************/
/*! \brief       Calculates the start address of the instances content.
 *  \details     -
 *  \param[in]   instance                Instance which contains the content. Must not be NULL.
 * \param[in]    metaDataSize            Aligned size of the instances metadata.
 *  \return      Number of remaining content bytes.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_AddressType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Instance_CalculateContentStartAddress(
    Fee_30_FlexNor_ConstInstanceDataPtrType instance, 
    Fee_30_FlexNor_LengthType metaDataSize);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Instance_CalculateSecondPageStartAddress()
 *********************************************************************************************************************/
/*! \brief       Calculates the start address of the page, which after the instances status. 
 *  \details     -
 *  \param[in]   instance                Instance which contains the content. Must not be NULL.
 *  \param[in]   ctx                     Context of the read content service. Must not be NULL.
 *  \param[in]   metaDataSize            Aligned size of the instances metadata.
 *  \return      Number of remaining content bytes.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_AddressType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Instance_CalculateSecondPageStartAddress(
    Fee_30_FlexNor_ConstInstanceDataPtrType instance,
    Fee_30_FlexNor_Instance_ConstContextPtrType ctx, 
    Fee_30_FlexNor_LengthType metaDataSize);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Instance_CalculatePayloadStartAddress()
 *********************************************************************************************************************/
/*! \brief       Calculates the start address of the instances payload.
 *  \details     -
 *  \param[in]   instance                Instance which contains the payload.
 * \param[in]    metaDataSize            Aligned size of the instances metadata.
 *  \return      Number of remaining content bytes.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_AddressType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Instance_CalculatePayloadStartAddress(
    Fee_30_FlexNor_ConstInstanceDataPtrType instance,
    Fee_30_FlexNor_LengthType metaDataSize);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Instance_CalculatePayloadEndAddress()
 *********************************************************************************************************************/
/*! \brief       Calculates the end address of the payload. It is the address of the byte after the last payload byte. 
 *  \details     -
 *  \param[in]   instance                Instance which contains the content.
 * \param[in]    metaDataSize            Aligned size of the instances metadata.
 *  \return      Number of remaining content bytes.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_AddressType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Instance_CalculatePayloadEndAddress(
    Fee_30_FlexNor_ConstInstanceDataPtrType instance,
    Fee_30_FlexNor_LengthType metaDataSize);

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * Fee_30_FlexNor_Instance_WritePayloadViaInternalBuffer
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_LengthType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Instance_WritePayloadViaInternalBuffer(
    Fee_30_FlexNor_Instance_ConstContextPtrType ctx,
    Fee_30_FlexNor_ConstInstanceDataPtrType instance,
    Fee_30_FlexNor_LengthType metadataSize,
    Fee_30_FlexNor_ResultCallback resultCbk)
{
    Fee_30_FlexNor_LengthType lengthToWrite = Fee_30_FlexNor_Instance_PrepareInternalBuffer(ctx, instance); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    Fee_30_FlexNor_FlashAccess_WriteFlash(ctx->PartitionConfig->PartitionId,
        instance->StartAddress + metadataSize + ctx->ContentWritten,
        ctx->InstanceBuffer,
        lengthToWrite,
        resultCbk); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    return lengthToWrite;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Instance_WritePayloadViaUserBuffer
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_LengthType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Instance_WritePayloadViaUserBuffer(
    Fee_30_FlexNor_Instance_ConstContextPtrType ctx,
    Fee_30_FlexNor_ConstInstanceDataPtrType instance,
    Fee_30_FlexNor_LengthType metadataSize,
    Fee_30_FlexNor_ResultCallback resultCbk)
{
    Fee_30_FlexNor_LengthType pageSize = ctx->PartitionConfig->PageAlignment;

    /* Here we need the unaligned number of bytes. */
    Fee_30_FlexNor_LengthType remainingBytes = instance->PayloadSize + FEE_30_FLEXNOR_INSTANCE_STATUS_SIZE - ctx->ContentWritten; 
    Fee_30_FlexNor_LengthType numberOfBytesToWrite = ((Fee_30_FlexNor_LengthType)(remainingBytes / pageSize)) * pageSize;

    Fee_30_FlexNor_FlashAccess_WriteFlash(ctx->PartitionConfig->PartitionId,
        instance->StartAddress + metadataSize + ctx->ContentWritten,
        &instance->WriteBuffer[ctx->ContentWritten - FEE_30_FLEXNOR_INSTANCE_STATUS_SIZE],
        numberOfBytesToWrite,
        resultCbk); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    return numberOfBytesToWrite;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Instance_PrepareInternalBuffer
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_LengthType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Instance_PrepareInternalBuffer(
    Fee_30_FlexNor_Instance_ConstContextPtrType ctx,
    Fee_30_FlexNor_ConstInstanceDataPtrType instance)
{
    Fee_30_FlexNor_LengthType returnValue = 0u;
    Fee_30_FlexNor_Shared_SetBufferValues(ctx->InstanceBuffer, FEE_30_FLEXNOR_INTERNALBUFFER_SIZE, ctx->PartitionConfig->ErasedValue); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    if(ctx->ContentWritten == 0u)
    {
        returnValue = Fee_30_FlexNor_Instance_PrepareInternalBufferForFirstWrite(ctx, instance); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
    }
    else
    {
        returnValue = Fee_30_FlexNor_Instance_PrepareInternalBufferForLastWrite(ctx, instance); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
    }
   
    return returnValue;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Instance_PrepareInternalBufferForFirstWrite
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_LengthType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Instance_PrepareInternalBufferForFirstWrite(
    Fee_30_FlexNor_Instance_ConstContextPtrType ctx,
    Fee_30_FlexNor_ConstInstanceDataPtrType instance)
{
    Fee_30_FlexNor_LengthType currentBufferIndex = 0u, currentInstanceIndex = 0u;

    for(currentBufferIndex = 0u; currentBufferIndex < FEE_30_FLEXNOR_INSTANCE_STATUS_SIZE; currentBufferIndex++)
    {
        ctx->InstanceBuffer[currentBufferIndex] = (uint8)instance->Status; /* SBSW_Fee_30_FlexNor_ModifyContextArray */
    }

    if(instance->Status == FEE_30_FLEXNOR_INSTANCE_VALID)
    {
        while((currentBufferIndex < FEE_30_FLEXNOR_INTERNALBUFFER_SIZE) && (currentInstanceIndex < instance->PayloadSize))
        {
            ctx->InstanceBuffer[currentBufferIndex] = instance->WriteBuffer[currentInstanceIndex]; /* SBSW_Fee_30_FlexNor_ModifyContextArray */
            currentBufferIndex++;
            currentInstanceIndex++;
        }
    }

    return Fee_30_FlexNor_Shared_AlignUp(currentBufferIndex, ctx->PartitionConfig->PageAlignment);
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Instance_PrepareInternalBufferForLastWrite
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_LengthType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Instance_PrepareInternalBufferForLastWrite(
    Fee_30_FlexNor_Instance_ConstContextPtrType ctx,
    Fee_30_FlexNor_ConstInstanceDataPtrType instance)
{
    Fee_30_FlexNor_LengthType currentBufferIndex = 0u, currentInstanceIndex = ctx->ContentWritten - FEE_30_FLEXNOR_INSTANCE_STATUS_SIZE;

    while((currentInstanceIndex < instance->PayloadSize))
    {
        ctx->InstanceBuffer[currentBufferIndex] = instance->WriteBuffer[currentInstanceIndex]; /* SBSW_Fee_30_FlexNor_ModifyContextArray */
        currentBufferIndex++;
        currentInstanceIndex++;
    }

    return Fee_30_FlexNor_Shared_AlignUp(currentBufferIndex, ctx->PartitionConfig->PageAlignment);
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Instance_GetNextCopyStepSize()
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
FUNC(Fee_30_FlexNor_LengthType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Instance_GetNextCopyStepSize(Fee_30_FlexNor_Instance_ConstContextPtrType ctx)
{
    uint32 nextCopySize = ctx->PartitionConfig->PageAlignment;

    if(ctx->ContentWritten != 0u)
    {
        uint32 totalContentSize = Fee_30_FlexNor_Instance_GetAlignedContentSize(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

        nextCopySize = ((totalContentSize - ctx->ContentWritten) > FEE_30_FLEXNOR_INTERNALBUFFER_SIZE) ? 
            FEE_30_FLEXNOR_INTERNALBUFFER_SIZE : 
            (totalContentSize - ctx->ContentWritten);
    }

    return nextCopySize;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Instance_GetRemainingContentBytes()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Fee_30_FlexNor_LengthType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Instance_GetRemainingContentBytes(
    Fee_30_FlexNor_Instance_ConstContextPtrType ctx,
    Fee_30_FlexNor_ConstInstanceDataPtrType instance)
{
    return Fee_30_FlexNor_Shared_AlignUp(instance->PayloadSize + FEE_30_FLEXNOR_INSTANCE_STATUS_SIZE, ctx->PartitionConfig->PageAlignment) 
           - ctx->ContentWritten;
}
/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * Fee_30_FlexNor_Instance_IsAnotherWriteStepNecessary
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(boolean, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Instance_IsAnotherWriteStepNecessary(
    Fee_30_FlexNor_Instance_ConstContextPtrType ctx,
    Fee_30_FlexNor_ConstInstanceDataPtrType instance)
{
    return ((Fee_30_FlexNor_Instance_GetRemainingContentBytes(ctx, instance) != 0u) &&
            (instance->Status == FEE_30_FLEXNOR_INSTANCE_VALID)) ? TRUE: FALSE; /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
}
/**********************************************************************************************************************
 * Fee_30_FlexNor_Instance_WritePayload()
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
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Instance_WritePayload(Fee_30_FlexNor_Instance_ContextPtrType ctx,
    Fee_30_FlexNor_ConstInstanceDataPtrType instance,
    Fee_30_FlexNor_LengthType metadataSize,
    Fee_30_FlexNor_ResultCallback resultCbk)
{
    Fee_30_FlexNor_LengthType contentBytesLeft = Fee_30_FlexNor_Instance_GetRemainingContentBytes(ctx, instance); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
    Fee_30_FlexNor_LengthType bytesWrittenInThisStep = 0u;

    if(ctx->ContentWritten == 0u)
    {
        bytesWrittenInThisStep = Fee_30_FlexNor_Instance_WritePayloadViaInternalBuffer(ctx, instance, metadataSize, resultCbk); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
    }
    else if(contentBytesLeft > FEE_30_FLEXNOR_INTERNALBUFFER_SIZE)
    {
        bytesWrittenInThisStep = Fee_30_FlexNor_Instance_WritePayloadViaUserBuffer(ctx, instance, metadataSize, resultCbk); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
    }
    else
    {
        bytesWrittenInThisStep = Fee_30_FlexNor_Instance_WritePayloadViaInternalBuffer(ctx, instance, metadataSize, resultCbk); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
    }

    ctx->ContentWritten += bytesWrittenInThisStep; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Instance_ReadSourceContent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Instance_ReadSourceContent(Fee_30_FlexNor_Instance_ConstContextPtrType ctx,
    Fee_30_FlexNor_LengthType metadataSize,
    Fee_30_FlexNor_ResultCallback resultCbk)
{
    uint32 copySize = Fee_30_FlexNor_Instance_GetNextCopyStepSize(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */

    Fee_30_FlexNor_FlashAccess_ReadFlashImmediate(ctx->PartitionConfig->PartitionId, 
        ctx->SourceInstance->StartAddress + metadataSize + ctx->ContentWritten,
        ctx->InstanceBuffer,
        copySize,
        resultCbk); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Instance_WriteTargetContent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Instance_WriteTargetContent(Fee_30_FlexNor_Instance_ContextPtrType ctx,
    Fee_30_FlexNor_ConstInstanceDataPtrType targetInstance,
    Fee_30_FlexNor_LengthType metadataSize,
    Fee_30_FlexNor_ResultCallback resultCbk)
{
    uint32 writeSize = Fee_30_FlexNor_Instance_GetNextCopyStepSize(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */

    Fee_30_FlexNor_FlashAccess_WriteFlash(ctx->PartitionConfig->PartitionId,
        targetInstance->StartAddress + metadataSize + ctx->ContentWritten,
        ctx->InstanceBuffer,
        writeSize,
        resultCbk); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
    
    ctx->ContentWritten += writeSize; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Instance_GetAlignedContentSize()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Fee_30_FlexNor_LengthType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Instance_GetAlignedContentSize(Fee_30_FlexNor_Instance_ConstContextPtrType ctx)
{
    uint32 rawContentSize = ctx->SourceInstance->PayloadSize + FEE_30_FLEXNOR_INSTANCE_STATUS_SIZE;
    return Fee_30_FlexNor_Shared_AlignUp(rawContentSize, ctx->PartitionConfig->PageAlignment);
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Instance_ReadCommitMarker()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Instance_ReadCommitMarker(
    Fee_30_FlexNor_Instance_ConstContextPtrType ctx,
    Fee_30_FlexNor_AddressType commitMarkerStartAddress,
    Fee_30_FlexNor_ResultCallback resultCbk)
{
    Fee_30_FlexNor_Shared_SetBufferValues(
        ctx->InstanceBuffer,
        ctx->PartitionConfig->PageAlignment,
        ctx->PartitionConfig->ErasedValue); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    Fee_30_FlexNor_FlashAccess_ReadFlash(
        ctx->PartitionConfig->PartitionId,
        commitMarkerStartAddress,
        ctx->InstanceBuffer,
        ctx->PartitionConfig->PageAlignment,
        resultCbk); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Instance_RequestRecoveryGarbageCollection
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Instance_RequestRecoveryGarbageCollection(
    Fee_30_FlexNor_PartitionIdType partitionId,
    Fee_30_FlexNor_AddressType address)
{
    Fee_30_FlexNor_InternalJobs_RequestRecoveryGarbageCollection(partitionId, address);
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Instance_CalculateContentStartAddress
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
Fee_30_FlexNor_AddressType Fee_30_FlexNor_Instance_CalculateContentStartAddress(
    Fee_30_FlexNor_ConstInstanceDataPtrType instance, Fee_30_FlexNor_LengthType metaDataSize)
{
    Fee_30_FlexNor_AddressType contentStartAddress = instance->StartAddress + metaDataSize;

    return contentStartAddress;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Instance_CalculateSecondPageStartAddress
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
Fee_30_FlexNor_AddressType Fee_30_FlexNor_Instance_CalculateSecondPageStartAddress(
    Fee_30_FlexNor_ConstInstanceDataPtrType instance,
    Fee_30_FlexNor_Instance_ConstContextPtrType ctx, 
    Fee_30_FlexNor_LengthType metaDataSize)
{
    uint32 readAlignedStatusSize = Fee_30_FlexNor_Shared_AlignUp(FEE_30_FLEXNOR_INSTANCE_STATUS_SIZE, 
        ctx->PartitionConfig->ReadAlignment);

    Fee_30_FlexNor_AddressType secondPageStartAddress
        = Fee_30_FlexNor_Instance_CalculateContentStartAddress(instance, metaDataSize) + readAlignedStatusSize; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */

    return secondPageStartAddress;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Instance_CalculatePayloadStartAddress
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
Fee_30_FlexNor_AddressType Fee_30_FlexNor_Instance_CalculatePayloadStartAddress(
    Fee_30_FlexNor_ConstInstanceDataPtrType instance,
    Fee_30_FlexNor_LengthType metaDataSize)
{
    Fee_30_FlexNor_AddressType contentStartAddress 
        = Fee_30_FlexNor_Instance_CalculateContentStartAddress(instance, metaDataSize); /* SBSW_Fee_30_FlexNor_ContextPointerAccess */

    Fee_30_FlexNor_AddressType payloadStartAddress = contentStartAddress + FEE_30_FLEXNOR_INSTANCE_STATUS_SIZE 
        + instance->PayloadOffset;

    return payloadStartAddress;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Instance_CalculatePayloadStartAddress
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
Fee_30_FlexNor_AddressType Fee_30_FlexNor_Instance_CalculatePayloadEndAddress(
    Fee_30_FlexNor_ConstInstanceDataPtrType instance,
    Fee_30_FlexNor_LengthType metaDataSize)
{
    Fee_30_FlexNor_AddressType payloadEndAddress 
        = Fee_30_FlexNor_Instance_CalculatePayloadStartAddress(instance, metaDataSize) + instance->PayloadSize; /* SBSW_Fee_30_FlexNor_FunctionCallWithGivenPointer */

    return payloadEndAddress;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Instance_ReadStatus()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Instance_ReadStatus(
    Fee_30_FlexNor_ConstInstanceDataPtrType instance,
    Fee_30_FlexNor_Instance_ConstContextPtrType ctx, 
    Fee_30_FlexNor_LengthType metadataSize,
    Fee_30_FlexNor_ResultCallback resultCbk
) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    uint32 readAlignedStatusSize = Fee_30_FlexNor_Shared_AlignUp(FEE_30_FLEXNOR_INSTANCE_STATUS_SIZE, 
        ctx->PartitionConfig->ReadAlignment);

    Fee_30_FlexNor_Shared_SetBufferValues(
        ctx->InstanceBuffer,
        metadataSize,
        ctx->PartitionConfig->ErasedValue); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    Fee_30_FlexNor_FlashAccess_ReadFlashImmediate(
        instance->PartitionId,
        instance->StartAddress + metadataSize,
        ctx->InstanceBuffer,
        readAlignedStatusSize,
        resultCbk); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Instance_ParseInstanceStatus()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Fee_30_FlexNor_InstanceStatusType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Instance_ParseInstanceStatus(
    Fee_30_FlexNor_DataPtrType instanceBuffer) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    Fee_30_FlexNor_InstanceStatusType parsedInstanceStatus = FEE_30_FLEXNOR_INSTANCE_INVALIDATED;
    Fee_30_FlexNor_DataType readInstanceStatus = instanceBuffer[FEE_30_FLEXNOR_CONTENT_STATUS_INDEX];

    if (readInstanceStatus == (Fee_30_FlexNor_DataType) FEE_30_FLEXNOR_INSTANCE_VALID)
    {
        parsedInstanceStatus = FEE_30_FLEXNOR_INSTANCE_VALID; 
    }
    else if (readInstanceStatus == (Fee_30_FlexNor_DataType) FEE_30_FLEXNOR_INSTANCE_INVALIDATED)
    {
        parsedInstanceStatus = FEE_30_FLEXNOR_INSTANCE_INVALIDATED; 
    }
    else
    {
        Fee_30_FlexNor_DiagnosticHandler_RaiseWarning(FEE_30_FLEXNOR_DIAGID_INSTANCE_STATUS_INVALID);
        parsedInstanceStatus = FEE_30_FLEXNOR_INSTANCE_INVALIDATED; 
    }

    return parsedInstanceStatus;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Instance_CopyDataFromStatusPageInUserBuffer()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Instance_CopyDataFromStatusPageInUserBuffer(
    Fee_30_FlexNor_ConstInstanceDataPtrType instance,
    Fee_30_FlexNor_Instance_ContextPtrType ctx)
{
    uint32 readAlignedStatusSize = Fee_30_FlexNor_Shared_AlignUp(FEE_30_FLEXNOR_INSTANCE_STATUS_SIZE, 
        ctx->PartitionConfig->ReadAlignment);

    uint32 readBufferIdx = 0;
    uint32 statusPageIdx = FEE_30_FLEXNOR_INSTANCE_STATUS_SIZE + instance->PayloadOffset;

    while ((readBufferIdx < instance->PayloadSize) && (statusPageIdx < readAlignedStatusSize)) 
    {
        instance->ReadBuffer[readBufferIdx] = ctx->InstanceBuffer[statusPageIdx]; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */

        readBufferIdx++;
        statusPageIdx++;
    }

    ctx->ContentRead = readBufferIdx; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Instance_ReadOffsetPage()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(boolean, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Instance_ReadOffsetPage(
    Fee_30_FlexNor_ConstInstanceDataPtrType instance,
    Fee_30_FlexNor_Instance_ConstContextPtrType ctx, 
    Fee_30_FlexNor_LengthType metaDataSize,
    Fee_30_FlexNor_ResultCallback resultCbk) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    boolean isJobPending = FALSE;
    uint16 readPageSize = ctx->PartitionConfig->ReadAlignment;

    Fee_30_FlexNor_AddressType secondPageStartAddress 
        = Fee_30_FlexNor_Instance_CalculateSecondPageStartAddress(instance, ctx, metaDataSize); /* SBSW_Fee_30_FlexNor_FunctionCallWithGivenPointer */
    Fee_30_FlexNor_AddressType payloadStartAddress 
        = Fee_30_FlexNor_Instance_CalculatePayloadStartAddress(instance, metaDataSize); /* SBSW_Fee_30_FlexNor_FunctionCallWithGivenPointer */
    Fee_30_FlexNor_AddressType offsetPageStartAddress 
        = (Fee_30_FlexNor_AddressType) Fee_30_FlexNor_Shared_AlignDown(payloadStartAddress, readPageSize); /* SBSW_Fee_30_FlexNor_FunctionCallWithGivenPointer */

    if(( secondPageStartAddress <= payloadStartAddress ) /* Offset does not point into first page. */
        && (payloadStartAddress != offsetPageStartAddress)) /* Offset already read aligned. */
    {
        Fee_30_FlexNor_FlashAccess_ReadFlashImmediate(instance->PartitionId, 
            offsetPageStartAddress, 
            ctx->InstanceBuffer, 
            readPageSize, 
            resultCbk); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
        
        isJobPending = TRUE;
    }

    return isJobPending;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Instance_CopyDataFromOffsetPageInUserBuffer()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Instance_CopyDataFromOffsetPageInUserBuffer(
    Fee_30_FlexNor_ConstInstanceDataPtrType instance,
    Fee_30_FlexNor_Instance_ContextPtrType ctx, 
    Fee_30_FlexNor_LengthType metaDataSize)
{
    uint16 readPageSize = ctx->PartitionConfig->ReadAlignment;

    Fee_30_FlexNor_AddressType payloadStartAddress 
        = Fee_30_FlexNor_Instance_CalculatePayloadStartAddress(instance, metaDataSize); /* SBSW_Fee_30_FlexNor_FunctionCallWithGivenPointer */
    Fee_30_FlexNor_AddressType payloadEndAddress 
        = Fee_30_FlexNor_Instance_CalculatePayloadEndAddress(instance, metaDataSize); /* SBSW_Fee_30_FlexNor_FunctionCallWithGivenPointer */
    Fee_30_FlexNor_AddressType offsetPageStartAddress 
        = (Fee_30_FlexNor_AddressType) Fee_30_FlexNor_Shared_AlignDown(payloadStartAddress, readPageSize);
    Fee_30_FlexNor_AddressType secondPageStartAddress 
        = Fee_30_FlexNor_Instance_CalculateSecondPageStartAddress(instance, ctx, metaDataSize); /* SBSW_Fee_30_FlexNor_FunctionCallWithGivenPointer */

    /* Calculate indices of the payload within the offset page. */
    uint32 payloadStartIdx = payloadStartAddress - offsetPageStartAddress;
    uint32 payloadEndIdx = payloadEndAddress - offsetPageStartAddress;
    uint32 endIdx = (readPageSize < payloadEndIdx) ? readPageSize : payloadEndIdx; /* If the payload ends within the 
                                                                                    offset page, point to the end of the 
                                                                                    payload. If the payload exceeds the 
                                                                                    current page, point to the end of 
                                                                                    the current page. */

    if((0u < payloadStartIdx) /* Offset page is only read, if the offset is not read page aligned. */
        && (secondPageStartAddress < payloadStartAddress)) /* Offset page is only read, if the offset is not within the 
                                                              status (first) page. */
    {
        uint32 readBufferIdx = ctx->ContentRead;

        for (uint32 offsetPageIdx = payloadStartIdx; 
            offsetPageIdx < endIdx; /* Read until end of page, but not more payload as available.  */
            offsetPageIdx++)
        {
            instance->ReadBuffer[readBufferIdx] = ctx->InstanceBuffer[offsetPageIdx];  /* SBSW_Fee_30_FlexNor_ContextPointerAccess */

            readBufferIdx++;
        }

        ctx->ContentRead = readBufferIdx; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    }
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Instance_ReadCompletelyFilledPages()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(boolean, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Instance_ReadCompletelyFilledPages(
    Fee_30_FlexNor_ConstInstanceDataPtrType instance,
    Fee_30_FlexNor_Instance_ContextPtrType ctx, 
    Fee_30_FlexNor_LengthType metaDataSize,
    Fee_30_FlexNor_ResultCallback resultCbk) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    boolean isFlashJobRequested = FALSE;
    uint16 readPageSize = ctx->PartitionConfig->ReadAlignment;

    Fee_30_FlexNor_AddressType fullPagesStartAddress 
        = Fee_30_FlexNor_Instance_CalculatePayloadStartAddress(instance, metaDataSize) + ctx->ContentRead; /* SBSW_Fee_30_FlexNor_FunctionCallWithGivenPointer */
    Fee_30_FlexNor_AddressType payloadEndAddress 
        = Fee_30_FlexNor_Instance_CalculatePayloadEndAddress(instance, metaDataSize); /* SBSW_Fee_30_FlexNor_FunctionCallWithGivenPointer */
    Fee_30_FlexNor_AddressType lastPageStartAddress = (Fee_30_FlexNor_AddressType) Fee_30_FlexNor_Shared_AlignDown(
        payloadEndAddress, readPageSize);

    if(fullPagesStartAddress < lastPageStartAddress) /* Trigger this read only if a full page is available. */
    {
        Fee_30_FlexNor_LengthType fullPagesReadLength = lastPageStartAddress - fullPagesStartAddress;

        Fee_30_FlexNor_FlashAccess_ReadFlashImmediate(instance->PartitionId, 
            fullPagesStartAddress, 
            &instance->ReadBuffer[ctx->ContentRead], 
            fullPagesReadLength, 
            resultCbk); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

        ctx->ContentRead += fullPagesReadLength; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */

        isFlashJobRequested = TRUE;
    }

    return isFlashJobRequested;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Instance_ReadLastPage()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(boolean, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Instance_ReadLastPage(
    Fee_30_FlexNor_ConstInstanceDataPtrType instance,
    Fee_30_FlexNor_Instance_ConstContextPtrType ctx, 
    Fee_30_FlexNor_LengthType metaDataSize,
    Fee_30_FlexNor_ResultCallback resultCbk) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    boolean isFlashJobRequested = FALSE;
    uint16 readPageSize = ctx->PartitionConfig->ReadAlignment; 

    Fee_30_FlexNor_AddressType payloadEndAddress = Fee_30_FlexNor_Instance_CalculatePayloadEndAddress(instance, /* SBSW_Fee_30_FlexNor_FunctionCallWithGivenPointer */
        metaDataSize);
    Fee_30_FlexNor_AddressType lastPageStartAddress = (Fee_30_FlexNor_AddressType) Fee_30_FlexNor_Shared_AlignDown(
        payloadEndAddress, readPageSize);

    if(ctx->ContentRead < instance->PayloadSize) /* Data left. */
    {
        Fee_30_FlexNor_FlashAccess_ReadFlashImmediate(instance->PartitionId, 
            lastPageStartAddress, 
            ctx->InstanceBuffer, 
            readPageSize, 
            resultCbk); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

        isFlashJobRequested = TRUE;
    }

    return isFlashJobRequested;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Instance_CopyDataFromLastPageInUserBuffer()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Instance_CopyDataFromLastPageInUserBuffer(
    Fee_30_FlexNor_ConstInstanceDataPtrType instance,
    Fee_30_FlexNor_Instance_ContextPtrType ctx)
{
    uint32 readBufferIdx = ctx->ContentRead;
    uint32 lastPageIdx = 0u;

    while (readBufferIdx < instance->PayloadSize)
    {
        instance->ReadBuffer[readBufferIdx] = ctx->InstanceBuffer[lastPageIdx]; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */

        readBufferIdx++;
        lastPageIdx++;
    }

    ctx->ContentRead = readBufferIdx; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
}

#define FEE_30_FLEXNOR_STOP_SEC_CODE
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

    /**********************************************************************************************************************
 *  END OF FILE: Fee_30_FlexNor_Instance.c
 *********************************************************************************************************************/
