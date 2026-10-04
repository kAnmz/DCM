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
/*!        \file  Fee_30_FlexNor_SecureInstance.c
 *        \brief  Secure instance unit implementation
 *      \details  Implementation of the instance services based on the secure instance layout.
 *         \unit  SecureInstance
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#define FEE_30_FLEXNOR_SECUREINSTANCE_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Fee_30_FlexNor_SecureInstance.h"
#include "Fee_30_FlexNor_SecureInstanceInternal.h"
#include "Fee_30_FlexNor_SecureInstanceMachine.h"

#include "Fee_30_FlexNor_ConfigInterface.h"
#include "Fee_30_FlexNor_Scheduler.h"
#include "Fee_30_FlexNor_Shared.h"
#include "Fee_30_FlexNor_InternalJobs.h"
#include "Fee_30_FlexNor_FlashAccess.h"

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
#    define FEE_30_FLEXNOR_START_SEC_VAR_CLEARED_UNSPECIFIED
#    include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Context variable of the secure instance state machine. */
FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_SecureInstance_ContextType Fee_30_FlexNor_SecureInstanceStmContext = { 0u };

#    define FEE_30_FLEXNOR_STOP_SEC_VAR_CLEARED_UNSPECIFIED
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
 * Fee_30_FlexNor_SecureInstance_ProcessingHandler()
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
FEE_30_FLEXNOR_LOCAL FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_ProcessingHandler(void);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_ParseInstanceMetadata()
 *********************************************************************************************************************/
/*! \brief       Parses and validates the instance markers from the given buffer
 *  \details     Parses the instance markers from the data previously read from flash.
 *  \param[in]   ctx        Context containing the buffer that shall be parsed. Must not be NULL.
 *  \pre         The instance metadata must already be read from flash
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FEE_30_FLEXNOR_LOCAL FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_ParseInstanceMetadata(
    Fee_30_FlexNor_SecureInstance_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_GetCommitMarkerOffset()
 *********************************************************************************************************************/
/*! \brief       Gets the offset of the commit marker relative to the instances start address
 *  \details     -
 *  \param[in]   pageAlignment               Page alignment in bytes
 *  \param[in]   interferenceFreeAlignment   Interference free alignment in bytes
 *  \return      The commit marker offset in bytes
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FEE_30_FLEXNOR_LOCAL_INLINE FUNC(Fee_30_FlexNor_AddressType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_GetCommitMarkerOffset(
    uint16 pageAlignment,
    uint16 interferenceFreeAlignment);

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_ProcessingHandler()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FEE_30_FLEXNOR_LOCAL FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_ProcessingHandler(void)
{
    return Fee_30_FlexNor_SecureInstanceStmContext.CurrentState->ProcessEvent(
        &Fee_30_FlexNor_SecureInstanceStmContext); /* SBSW_Fee_30_FlexNor_TriggerEventAtState */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_ResultHandler()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_ResultHandler(Fee_30_FlexNor_ServiceResult result)
{
    if (result == FEE_30_FLEXNOR_SERVICE_FAIL)
    {
        Fee_30_FlexNor_SecureInstanceStmContext.CurrentState->FailEvent(
            &Fee_30_FlexNor_SecureInstanceStmContext); /* SBSW_Fee_30_FlexNor_TriggerEventAtState */
    }
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_GetAlignedMetadataSize()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(uint32, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_GetAlignedMetadataSize(
    Fee_30_FlexNor_ConstPartitionConfigPtrType partition)
{
    uint32 alignedStartMarkerSize = partition->PageAlignment;
    uint32 alignedStartAndSealMarkerSize =
        Fee_30_FlexNor_Shared_AlignUp(alignedStartMarkerSize + partition->PageAlignment, 
            partition->InterferenceFreeAlignment);
    uint32 alignedCommitMarkerSize = Fee_30_FlexNor_Shared_AlignUp(partition->PageAlignment, 
        partition->InterferenceFreeAlignment);

    return alignedStartAndSealMarkerSize + alignedCommitMarkerSize;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_ParseInstanceMetadata()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FEE_30_FLEXNOR_LOCAL FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_ParseInstanceMetadata(
    Fee_30_FlexNor_SecureInstance_ContextPtrType ctx)
{
    Fee_30_FlexNor_LengthType sealMarkerOffset   = ctx->GenericContext.PartitionConfig->PageAlignment;
    Fee_30_FlexNor_LengthType commitMarkerOffset = Fee_30_FlexNor_SecureInstance_GetCommitMarkerOffset(
        ctx->GenericContext.PartitionConfig->PageAlignment,
        ctx->GenericContext.PartitionConfig->InterferenceFreeAlignment);

    ctx->Instance.StartMarkerValidity = Fee_30_FlexNor_SecureInstance_ValidateStartMarker(
        ctx, 
        0u); /* SBSW_Fee_30_FlexNor_ContextPointerAccess */ /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
    
    ctx->Instance.SealMarkerValidity = Fee_30_FlexNor_SecureInstance_ValidateSealMarker(
        ctx, 
        sealMarkerOffset); /* SBSW_Fee_30_FlexNor_ContextPointerAccess */ /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
    
    ctx->Instance.CommitMarkerValidity = Fee_30_FlexNor_SecureInstance_ValidateCommitMarker(
        ctx, 
        commitMarkerOffset); /* SBSW_Fee_30_FlexNor_ContextPointerAccess */ /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_GetCommitMarkerOffset()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FEE_30_FLEXNOR_LOCAL_INLINE FUNC(Fee_30_FlexNor_AddressType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_GetCommitMarkerOffset(
    uint16 pageAlignment,
    uint16 interferenceFreeAlignment)
{
    uint16 sealMarkerEnd = pageAlignment + pageAlignment;
    return Fee_30_FlexNor_Shared_AlignUp(sealMarkerEnd, interferenceFreeAlignment);
}

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_Init()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_Init(void)
{
    Fee_30_FlexNor_SecureInstanceStmContext.GenericContext.InstanceBuffer = Fee_30_FlexNor_ConfigInterface_GetInternalBuffer();
    Fee_30_FlexNor_SecureInstance_InitState(&Fee_30_FlexNor_SecureInstanceStmContext); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_GetTotalSize()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(uint32, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_GetTotalSize(Fee_30_FlexNor_ConstInstanceDataPtrType instance)
{
    Fee_30_FlexNor_ConstPartitionConfigPtrType partitionConfig = Fee_30_FlexNor_ConfigInterface_GetPartitionConfig(
        instance->PartitionId);

    uint32 totalSize = Fee_30_FlexNor_SecureInstance_GetAlignedMetadataSize(partitionConfig); /* SBSW_Fee_30_FlexNor_FunctionCallWithConstPointer */

    totalSize += Fee_30_FlexNor_Shared_AlignUp(instance->PayloadSize + FEE_30_FLEXNOR_INSTANCE_STATUS_SIZE, 
        partitionConfig->InterferenceFreeAlignment);

    return totalSize;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_Validate()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_Validate(
    Fee_30_FlexNor_InstanceDataPtrType instance,
    Fee_30_FlexNor_ResultCallback resultCbk)
{
    Fee_30_FlexNor_SecureInstanceStmContext.Instance.InstanceData         = instance;
    Fee_30_FlexNor_SecureInstanceStmContext.GenericContext.ResultCallback = resultCbk;

    Fee_30_FlexNor_SecureInstanceStmContext.GenericContext.PartitionConfig =
        Fee_30_FlexNor_ConfigInterface_GetPartitionConfig(instance->PartitionId);

    Fee_30_FlexNor_SecureInstance_Validate_Initialize(
        &Fee_30_FlexNor_SecureInstanceStmContext); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_Write()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_Write(
    Fee_30_FlexNor_ConstInstanceDataPtrType instance,
    Fee_30_FlexNor_ResultCallback resultCbk)
{
    Fee_30_FlexNor_SecureInstanceStmContext.Instance.ConstInstanceData    = instance;
    Fee_30_FlexNor_SecureInstanceStmContext.GenericContext.ResultCallback = resultCbk;

    Fee_30_FlexNor_SecureInstanceStmContext.GenericContext.ContentWritten = 0;
    Fee_30_FlexNor_SecureInstanceStmContext.GenericContext.PartitionConfig =
        Fee_30_FlexNor_ConfigInterface_GetPartitionConfig(instance->PartitionId);

    Fee_30_FlexNor_SecureInstance_Write_Initialize(
        &Fee_30_FlexNor_SecureInstanceStmContext); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_Copy()
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
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_Copy(
    Fee_30_FlexNor_ConstInstanceDataPtrType sourceInstance,
    Fee_30_FlexNor_InstanceDataPtrType targetInstance,
    Fee_30_FlexNor_ResultCallback resultCbk)
{
    targetInstance->PayloadSize = sourceInstance->PayloadSize; /* SBSW_Fee_30_FlexNor_ModifyGivenObject */

    Fee_30_FlexNor_SecureInstanceStmContext.Instance.InstanceData         = targetInstance;
    Fee_30_FlexNor_SecureInstanceStmContext.Instance.ConstInstanceData    = targetInstance;
    Fee_30_FlexNor_SecureInstanceStmContext.GenericContext.SourceInstance = sourceInstance;
    Fee_30_FlexNor_SecureInstanceStmContext.GenericContext.ResultCallback = resultCbk;

    Fee_30_FlexNor_SecureInstanceStmContext.GenericContext.ContentWritten = 0;
    Fee_30_FlexNor_SecureInstanceStmContext.GenericContext.PartitionConfig =
        Fee_30_FlexNor_ConfigInterface_GetPartitionConfig(sourceInstance->PartitionId);

    Fee_30_FlexNor_SecureInstance_Copy_Initialize(
        &Fee_30_FlexNor_SecureInstanceStmContext); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_ReadContent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_ReadContent(
    Fee_30_FlexNor_InstanceDataPtrType instance,
    Fee_30_FlexNor_ResultCallback resultCbk)
{
    Fee_30_FlexNor_SecureInstanceStmContext.Instance.InstanceData         = instance;
    Fee_30_FlexNor_SecureInstanceStmContext.GenericContext.ResultCallback = resultCbk;

    Fee_30_FlexNor_SecureInstanceStmContext.GenericContext.PartitionConfig =
        Fee_30_FlexNor_ConfigInterface_GetPartitionConfig(instance->PartitionId);

    Fee_30_FlexNor_SecureInstance_ReadContent_Initialize(
        &Fee_30_FlexNor_SecureInstanceStmContext); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_StartJob()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_StartJob(void)
{
    Fee_30_FlexNor_Scheduler_RegisterUnit(&Fee_30_FlexNor_SecureInstance_ProcessingHandler); /* SBSW_Fee_30_FlexNor_RegisterUnit */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_EndJob()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_EndJob(void)
{
    Fee_30_FlexNor_Scheduler_UnregisterUnit();
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_ReadInstanceMetadata()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_ReadInstanceMetadata(
    Fee_30_FlexNor_SecureInstance_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    Fee_30_FlexNor_LengthType metadataLength;
    metadataLength = Fee_30_FlexNor_SecureInstance_GetAlignedMetadataSize(ctx->GenericContext.PartitionConfig); /* SBSW_Fee_30_FlexNor_ContextFunctionPointerCall */

    Fee_30_FlexNor_Shared_SetBufferValues(
        ctx->GenericContext.InstanceBuffer,
        metadataLength,
        ctx->GenericContext.PartitionConfig->ErasedValue); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    Fee_30_FlexNor_FlashAccess_ReadFlash(
        ctx->Instance.InstanceData->PartitionId,
        ctx->Instance.InstanceData->StartAddress,
        ctx->GenericContext.InstanceBuffer,
        metadataLength,
        &Fee_30_FlexNor_SecureInstance_ResultHandler); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_ValidateInstanceMetadata()
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
 *
 */
FUNC(Fee_30_FlexNor_StructureValidityType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_ValidateInstanceMetadata(Fee_30_FlexNor_SecureInstance_ContextPtrType ctx)
{
    Fee_30_FlexNor_StructureValidityType returnValue = FEE_30_FLEXNOR_INVALID;

    Fee_30_FlexNor_SecureInstance_ParseInstanceMetadata(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */

    if (ctx->Instance.StartMarkerValidity == FEE_30_FLEXNOR_EMPTY)
    {
        returnValue = FEE_30_FLEXNOR_EMPTY;
    }
    else if (ctx->Instance.StartMarkerValidity == FEE_30_FLEXNOR_VALID)
    {
        if (ctx->Instance.CommitMarkerValidity == FEE_30_FLEXNOR_EMPTY)
        {
            if(ctx->Instance.SealMarkerValidity == FEE_30_FLEXNOR_VALID)
            {
                ctx->Instance.InstanceData->ReallocationRequired = TRUE; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
                returnValue = FEE_30_FLEXNOR_VALID;
            }
            else
            {
                returnValue = FEE_30_FLEXNOR_INVALID;
            }
        }
        else if (ctx->Instance.CommitMarkerValidity == FEE_30_FLEXNOR_VALID)
        {
            returnValue = FEE_30_FLEXNOR_VALID;
        }
        else
        {
            ctx->Instance.InstanceData->ReallocationRequired = TRUE; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
            returnValue = FEE_30_FLEXNOR_VALID;
        }
    }
    else
    {
        ctx->Instance.InstanceData->ReallocationRequired = TRUE; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        returnValue = FEE_30_FLEXNOR_INVALID;
    }
    return returnValue;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_WriteStartMarker()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_WriteStartMarker(
    Fee_30_FlexNor_SecureInstance_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    Fee_30_FlexNor_Shared_SetBufferValues(
        ctx->GenericContext.InstanceBuffer,
        ctx->GenericContext.PartitionConfig->PageAlignment,
        Fee_30_FlexNor_InstanceStartMarker); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    Fee_30_FlexNor_FlashAccess_WriteFlash(
        ctx->Instance.ConstInstanceData->PartitionId,
        ctx->Instance.ConstInstanceData->StartAddress,
        ctx->GenericContext.InstanceBuffer,
        ctx->GenericContext.PartitionConfig->PageAlignment,
        &Fee_30_FlexNor_SecureInstance_ResultHandler); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_WritePayload()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_WritePayload(Fee_30_FlexNor_SecureInstance_ContextPtrType ctx)
{
    Fee_30_FlexNor_LengthType metadataSize = Fee_30_FlexNor_SecureInstance_GetAlignedMetadataSize( 
        ctx->GenericContext.PartitionConfig); /* SBSW_Fee_30_FlexNor_FunctionCallWithConstPointer */

    Fee_30_FlexNor_Instance_WritePayload(
        &ctx->GenericContext,
        ctx->Instance.ConstInstanceData,
        metadataSize,
        &Fee_30_FlexNor_SecureInstance_ResultHandler); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_WriteSealMarker()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_WriteSealMarker(
    Fee_30_FlexNor_SecureInstance_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    uint16 markerSize = ctx->GenericContext.PartitionConfig->PageAlignment;
    uint16 sealMarkerOffset = ctx->GenericContext.PartitionConfig->PageAlignment;

    Fee_30_FlexNor_Shared_SetBufferValues(
        ctx->GenericContext.InstanceBuffer,
        markerSize,
        Fee_30_FlexNor_SealMarker); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    Fee_30_FlexNor_FlashAccess_WriteFlash(
        ctx->Instance.ConstInstanceData->PartitionId,
        ctx->Instance.ConstInstanceData->StartAddress + sealMarkerOffset,
        ctx->GenericContext.InstanceBuffer,
        markerSize,
        &Fee_30_FlexNor_SecureInstance_ResultHandler); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_WriteCommitMarker()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_WriteCommitMarker(
    Fee_30_FlexNor_SecureInstance_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    uint16 markerSize = ctx->GenericContext.PartitionConfig->PageAlignment;
    Fee_30_FlexNor_AddressType commitMarkerOffset = Fee_30_FlexNor_SecureInstance_GetCommitMarkerOffset(
        ctx->GenericContext.PartitionConfig->PageAlignment,
        ctx->GenericContext.PartitionConfig->InterferenceFreeAlignment);

    Fee_30_FlexNor_Shared_SetBufferValues(
        ctx->GenericContext.InstanceBuffer,
        markerSize,
        Fee_30_FlexNor_CommitMarker); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    Fee_30_FlexNor_FlashAccess_WriteFlash(
        ctx->Instance.ConstInstanceData->PartitionId,
        ctx->Instance.ConstInstanceData->StartAddress + commitMarkerOffset,
        ctx->GenericContext.InstanceBuffer,
        markerSize,
        &Fee_30_FlexNor_SecureInstance_ResultHandler); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
}



/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_ReadSourceContent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_ReadSourceContent(
    Fee_30_FlexNor_SecureInstance_ConstContextPtrType ctx)
{
    Fee_30_FlexNor_LengthType metadataSize = Fee_30_FlexNor_SecureInstance_GetAlignedMetadataSize( 
        ctx->GenericContext.PartitionConfig); /* SBSW_Fee_30_FlexNor_FunctionCallWithConstPointer */

    Fee_30_FlexNor_Instance_ReadSourceContent(
        &ctx->GenericContext,
        metadataSize,
        &Fee_30_FlexNor_SecureInstance_ResultHandler); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_WriteTargetContent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_WriteTargetContent(Fee_30_FlexNor_SecureInstance_ContextPtrType ctx)
{
    Fee_30_FlexNor_LengthType metadataSize = Fee_30_FlexNor_SecureInstance_GetAlignedMetadataSize(
        ctx->GenericContext.PartitionConfig); /* SBSW_Fee_30_FlexNor_FunctionCallWithConstPointer */

    Fee_30_FlexNor_Instance_WriteTargetContent(
        &ctx->GenericContext,
        ctx->Instance.InstanceData,
        metadataSize,
        &Fee_30_FlexNor_SecureInstance_ResultHandler); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_ReadStartMarker()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_ReadStartMarker(Fee_30_FlexNor_SecureInstance_ConstContextPtrType ctx)
{
    Fee_30_FlexNor_LengthType startMarkerLength = ctx->GenericContext.PartitionConfig->PageAlignment;

    Fee_30_FlexNor_Shared_SetBufferValues(
        ctx->GenericContext.InstanceBuffer,
        startMarkerLength,
        ctx->GenericContext.PartitionConfig->ErasedValue); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    Fee_30_FlexNor_FlashAccess_ReadFlash(
        ctx->GenericContext.PartitionConfig->PartitionId,
        ctx->Instance.InstanceData->StartAddress,
        ctx->GenericContext.InstanceBuffer,
        startMarkerLength,
        &Fee_30_FlexNor_SecureInstance_ResultHandler); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_ValidateStartMarker()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Fee_30_FlexNor_StructureValidityType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_ValidateStartMarker(
    Fee_30_FlexNor_SecureInstance_ConstContextPtrType ctx,
    Fee_30_FlexNor_LengthType offset)
{
    return Fee_30_FlexNor_Shared_GetMarkerValidity(
        ctx->GenericContext.InstanceBuffer,
        offset,
        Fee_30_FlexNor_InstanceStartMarker,
        ctx->GenericContext.PartitionConfig->PageAlignment,
        ctx->GenericContext.PartitionConfig->ErasedValue
    ); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_ReadCommitMarker()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_ReadCommitMarker(Fee_30_FlexNor_SecureInstance_ConstContextPtrType ctx)
{
    Fee_30_FlexNor_AddressType commitMarkerStartAddress = ctx->Instance.InstanceData->StartAddress + 
        Fee_30_FlexNor_SecureInstance_GetCommitMarkerOffset(
            ctx->GenericContext.PartitionConfig->PageAlignment,
            ctx->GenericContext.PartitionConfig->InterferenceFreeAlignment);

    Fee_30_FlexNor_Instance_ReadCommitMarker(&ctx->GenericContext, commitMarkerStartAddress, &Fee_30_FlexNor_SecureInstance_ResultHandler); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_ValidateCommitMarker()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Fee_30_FlexNor_StructureValidityType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_ValidateCommitMarker(
    Fee_30_FlexNor_SecureInstance_ConstContextPtrType ctx,
    Fee_30_FlexNor_LengthType offset)
{
    return Fee_30_FlexNor_Shared_GetMarkerValidity(
        ctx->GenericContext.InstanceBuffer,
        offset,
        Fee_30_FlexNor_CommitMarker,
        ctx->GenericContext.PartitionConfig->PageAlignment,
        ctx->GenericContext.PartitionConfig->ErasedValue
    ); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_ReadSealMarker()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_ReadSealMarker(Fee_30_FlexNor_SecureInstance_ConstContextPtrType ctx)
{
    Fee_30_FlexNor_AddressType sealMarkerStartAddress = ctx->Instance.InstanceData->StartAddress +
        ctx->GenericContext.PartitionConfig->PageAlignment;
    Fee_30_FlexNor_LengthType sealMarkerLength = ctx->GenericContext.PartitionConfig->PageAlignment;

    Fee_30_FlexNor_Shared_SetBufferValues(
        ctx->GenericContext.InstanceBuffer,
        sealMarkerLength,
        ctx->GenericContext.PartitionConfig->ErasedValue); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    Fee_30_FlexNor_FlashAccess_ReadFlash(
        ctx->GenericContext.PartitionConfig->PartitionId,
        sealMarkerStartAddress,
        ctx->GenericContext.InstanceBuffer,
        sealMarkerLength,
        &Fee_30_FlexNor_SecureInstance_ResultHandler); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_ValidateSealMarker()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Fee_30_FlexNor_StructureValidityType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_ValidateSealMarker(
    Fee_30_FlexNor_SecureInstance_ConstContextPtrType ctx,
    Fee_30_FlexNor_LengthType offset)
{
    return Fee_30_FlexNor_Shared_GetMarkerValidity(
        ctx->GenericContext.InstanceBuffer,
        offset,
        Fee_30_FlexNor_SealMarker,
        ctx->GenericContext.PartitionConfig->PageAlignment,
        ctx->GenericContext.PartitionConfig->ErasedValue
    ); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
}

#    define FEE_30_FLEXNOR_STOP_SEC_CODE
#    include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif

/**********************************************************************************************************************
 *  END OF FILE: Fee_30_FlexNor_SecureInstance.c
 *********************************************************************************************************************/
