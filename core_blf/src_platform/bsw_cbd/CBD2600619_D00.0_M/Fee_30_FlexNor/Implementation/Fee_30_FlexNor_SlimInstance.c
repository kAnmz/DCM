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
/*!        \file  Fee_30_FlexNor_SlimInstance.c
 *        \brief  Slim instance unit implementation
 *      \details  Implementation of the instance services based on the slim instance layout.
 *         \unit  SlimInstance
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#define FEE_30_FLEXNOR_SLIMINSTANCE_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Fee_30_FlexNor_SlimInstance.h"
#include "Fee_30_FlexNor_SlimInstanceInternal.h"
#include "Fee_30_FlexNor_SlimInstanceMachine.h"

#include "Fee_30_FlexNor_ConfigInterface.h"
#include "Fee_30_FlexNor_Scheduler.h"
#include "Fee_30_FlexNor_Shared.h"
#include "Fee_30_FlexNor_FlashAccess.h"

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
#    define FEE_30_FLEXNOR_START_SEC_VAR_CLEARED_UNSPECIFIED
#    include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Context variable of the slim instance state machine. */
FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_SlimInstance_ContextType Fee_30_FlexNor_SlimInstanceStmContext = { 0u };

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
 * Fee_30_FlexNor_SlimInstance_ProcessingHandler()
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
FEE_30_FLEXNOR_LOCAL FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimInstance_ProcessingHandler(void);

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimInstance_ProcessingHandler()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FEE_30_FLEXNOR_LOCAL FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimInstance_ProcessingHandler(void)
{
    return Fee_30_FlexNor_SlimInstanceStmContext.CurrentState->ProcessEvent(
        &Fee_30_FlexNor_SlimInstanceStmContext); /* SBSW_Fee_30_FlexNor_TriggerEventAtState */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimInstance_ResultHandler()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimInstance_ResultHandler(Fee_30_FlexNor_ServiceResult result)
{
    if (result == FEE_30_FLEXNOR_SERVICE_FAIL)
    {
        Fee_30_FlexNor_SlimInstanceStmContext.CurrentState->FailEvent(
            &Fee_30_FlexNor_SlimInstanceStmContext); /* SBSW_Fee_30_FlexNor_TriggerEventAtState */
    }
}

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimInstance_Init()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimInstance_Init(void)
{
    Fee_30_FlexNor_SlimInstanceStmContext.GenericContext.InstanceBuffer = Fee_30_FlexNor_ConfigInterface_GetInternalBuffer();
    Fee_30_FlexNor_SlimInstance_InitState(&Fee_30_FlexNor_SlimInstanceStmContext); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimInstance_GetTotalSize()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(uint32, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimInstance_GetTotalSize(Fee_30_FlexNor_ConstInstanceDataPtrType instance)
{
    Fee_30_FlexNor_ConstPartitionConfigPtrType partitionConfig = Fee_30_FlexNor_ConfigInterface_GetPartitionConfig(instance->PartitionId);

    uint32 metadataSize = partitionConfig->InterferenceFreeAlignment;
    uint32 contentSize  = Fee_30_FlexNor_Shared_AlignUp(instance->PayloadSize + FEE_30_FLEXNOR_INSTANCE_STATUS_SIZE, partitionConfig->PageAlignment);

    return Fee_30_FlexNor_Shared_AlignUp(metadataSize + contentSize, partitionConfig->InterferenceFreeAlignment);
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimInstance_Validate()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimInstance_Validate(
    Fee_30_FlexNor_InstanceDataPtrType instance,
    Fee_30_FlexNor_ResultCallback resultCbk)
{
    Fee_30_FlexNor_SlimInstanceStmContext.Instance.InstanceData         = instance;
    Fee_30_FlexNor_SlimInstanceStmContext.GenericContext.ResultCallback = resultCbk;

    Fee_30_FlexNor_SlimInstanceStmContext.GenericContext.PartitionConfig =
        Fee_30_FlexNor_ConfigInterface_GetPartitionConfig(instance->PartitionId);

    Fee_30_FlexNor_SlimInstance_Validate_Initialize(
        &Fee_30_FlexNor_SlimInstanceStmContext); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimInstance_Write()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimInstance_Write(
    Fee_30_FlexNor_ConstInstanceDataPtrType instance,
    Fee_30_FlexNor_ResultCallback resultCbk)
{
    Fee_30_FlexNor_SlimInstanceStmContext.Instance.ConstInstanceData    = instance;
    Fee_30_FlexNor_SlimInstanceStmContext.GenericContext.ResultCallback = resultCbk;

    Fee_30_FlexNor_SlimInstanceStmContext.GenericContext.ContentWritten = 0;
    Fee_30_FlexNor_SlimInstanceStmContext.GenericContext.PartitionConfig =
        Fee_30_FlexNor_ConfigInterface_GetPartitionConfig(instance->PartitionId);

    Fee_30_FlexNor_SlimInstance_Write_Initialize(&Fee_30_FlexNor_SlimInstanceStmContext); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimInstance_StartJob()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimInstance_StartJob(void)
{
    Fee_30_FlexNor_Scheduler_RegisterUnit(&Fee_30_FlexNor_SlimInstance_ProcessingHandler); /* SBSW_Fee_30_FlexNor_RegisterUnit */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimInstance_EndJob()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimInstance_EndJob(void)
{
    Fee_30_FlexNor_Scheduler_UnregisterUnit();
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimInstance_ReadInstanceMetadata()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimInstance_ReadInstanceMetadataAndStatus(
    Fee_30_FlexNor_SlimInstance_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    /* 
     * The status is also read because it is required to detect if the instance is empty or not. 
     * In case the instance allocation is interrupted before the commit marker is written, the validation can't decide
     * if the instance is empty or invalid without evaluating the instance status also.
     */
    Fee_30_FlexNor_LengthType metadataSize = ctx->GenericContext.PartitionConfig->InterferenceFreeAlignment;
    Fee_30_FlexNor_LengthType readLength  = (Fee_30_FlexNor_LengthType) Fee_30_FlexNor_Shared_AlignUp(
        metadataSize + FEE_30_FLEXNOR_INSTANCE_STATUS_SIZE, ctx->GenericContext.PartitionConfig->ReadAlignment);

    Fee_30_FlexNor_Shared_SetBufferValues(
        ctx->GenericContext.InstanceBuffer,
        readLength,
        ctx->GenericContext.PartitionConfig->ErasedValue); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    Fee_30_FlexNor_FlashAccess_ReadFlash(
        ctx->Instance.InstanceData->PartitionId,
        ctx->Instance.InstanceData->StartAddress,
        ctx->GenericContext.InstanceBuffer,
        readLength,
        &Fee_30_FlexNor_SlimInstance_ResultHandler); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimInstance_ValidateInstanceMetadata()
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
FUNC(Fee_30_FlexNor_StructureValidityType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimInstance_ValidateInstanceMetadata(
    Fee_30_FlexNor_SlimInstance_ConstContextPtrType ctx)
{
    Fee_30_FlexNor_StructureValidityType metadataStatus = FEE_30_FLEXNOR_INVALID;
    Fee_30_FlexNor_StructureValidityType commitMarkerValidity = FEE_30_FLEXNOR_INVALID;

    Fee_30_FlexNor_LengthType alignedMetadataSize = ctx->GenericContext.PartitionConfig->InterferenceFreeAlignment;

    Fee_30_FlexNor_LengthType alignedStatusLength = (Fee_30_FlexNor_LengthType) Fee_30_FlexNor_Shared_AlignUp(
        FEE_30_FLEXNOR_INSTANCE_STATUS_SIZE, ctx->GenericContext.PartitionConfig->ReadAlignment);

    boolean isStatusPageErased  = Fee_30_FlexNor_Shared_IsErased(
        &(ctx->GenericContext.InstanceBuffer[alignedMetadataSize]), alignedStatusLength,
        ctx->GenericContext.PartitionConfig->ErasedValue); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    commitMarkerValidity = Fee_30_FlexNor_SlimInstance_ValidateCommitMarker(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    if ((commitMarkerValidity == FEE_30_FLEXNOR_EMPTY) && (isStatusPageErased == TRUE))
    {
        metadataStatus = FEE_30_FLEXNOR_EMPTY;
    }
    else if (commitMarkerValidity == FEE_30_FLEXNOR_EMPTY)
    {
        metadataStatus = FEE_30_FLEXNOR_INVALID;
    }
    else
    {
        metadataStatus = FEE_30_FLEXNOR_VALID;
    }
    return metadataStatus;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimInstance_ReadContent()
 *********************************************************************************************************************/
/*! 
 * Internal comment removed. *
 *
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimInstance_ReadContent(
    Fee_30_FlexNor_InstanceDataPtrType instance,
    Fee_30_FlexNor_ResultCallback resultCbk)
{
    Fee_30_FlexNor_SlimInstanceStmContext.Instance.InstanceData         = instance;
    Fee_30_FlexNor_SlimInstanceStmContext.GenericContext.ResultCallback = resultCbk;

    Fee_30_FlexNor_SlimInstanceStmContext.GenericContext.PartitionConfig =
        Fee_30_FlexNor_ConfigInterface_GetPartitionConfig(instance->PartitionId);

    Fee_30_FlexNor_SlimInstance_ReadContent_Initialize(
        &Fee_30_FlexNor_SlimInstanceStmContext); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimInstance_WritePayload()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimInstance_WritePayload(Fee_30_FlexNor_SlimInstance_ContextPtrType ctx)
{
    Fee_30_FlexNor_LengthType metadataSize = ctx->GenericContext.PartitionConfig->InterferenceFreeAlignment;

    Fee_30_FlexNor_Instance_WritePayload(
        &ctx->GenericContext,
        ctx->Instance.ConstInstanceData,
        metadataSize,
        &Fee_30_FlexNor_SlimInstance_ResultHandler); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimInstance_WriteCommitMarker()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimInstance_WriteCommitMarker(
    Fee_30_FlexNor_SlimInstance_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    Fee_30_FlexNor_Shared_SetBufferValues(
        ctx->GenericContext.InstanceBuffer,
        ctx->GenericContext.PartitionConfig->PageAlignment,
        Fee_30_FlexNor_CommitMarker); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    Fee_30_FlexNor_FlashAccess_WriteFlash(
        ctx->Instance.ConstInstanceData->PartitionId,
        ctx->Instance.ConstInstanceData->StartAddress,
        ctx->GenericContext.InstanceBuffer,
        ctx->GenericContext.PartitionConfig->PageAlignment,
        &Fee_30_FlexNor_SlimInstance_ResultHandler); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimInstance_Copy()
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
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimInstance_Copy(
    Fee_30_FlexNor_ConstInstanceDataPtrType sourceInstance,
    Fee_30_FlexNor_InstanceDataPtrType targetInstance,
    Fee_30_FlexNor_ResultCallback resultCbk)
{
    targetInstance->PayloadSize = sourceInstance->PayloadSize; /* SBSW_Fee_30_FlexNor_ModifyGivenObject */

    Fee_30_FlexNor_SlimInstanceStmContext.Instance.InstanceData         = targetInstance;
    Fee_30_FlexNor_SlimInstanceStmContext.Instance.ConstInstanceData    = targetInstance;
    Fee_30_FlexNor_SlimInstanceStmContext.GenericContext.SourceInstance = sourceInstance;
    Fee_30_FlexNor_SlimInstanceStmContext.GenericContext.ResultCallback = resultCbk;

    Fee_30_FlexNor_SlimInstanceStmContext.GenericContext.ContentWritten = 0;
    Fee_30_FlexNor_SlimInstanceStmContext.GenericContext.PartitionConfig =
        Fee_30_FlexNor_ConfigInterface_GetPartitionConfig(sourceInstance->PartitionId);

    Fee_30_FlexNor_SlimInstance_Copy_Initialize(&Fee_30_FlexNor_SlimInstanceStmContext); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimInstance_ReadSourceContent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimInstance_ReadSourceContent(Fee_30_FlexNor_SlimInstance_ConstContextPtrType ctx)
{
    Fee_30_FlexNor_LengthType metadataSize = ctx->GenericContext.PartitionConfig->InterferenceFreeAlignment;

    Fee_30_FlexNor_Instance_ReadSourceContent(
        &ctx->GenericContext,
        metadataSize,
        &Fee_30_FlexNor_SlimInstance_ResultHandler); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimInstance_WriteTargetContent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimInstance_WriteTargetContent(Fee_30_FlexNor_SlimInstance_ContextPtrType ctx)
{
    Fee_30_FlexNor_LengthType metadataSize = ctx->GenericContext.PartitionConfig->InterferenceFreeAlignment;

    Fee_30_FlexNor_Instance_WriteTargetContent(
        &ctx->GenericContext,
        ctx->Instance.InstanceData,
        metadataSize,
        &Fee_30_FlexNor_SlimInstance_ResultHandler); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimInstance_ReadCommitMarker()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimInstance_ReadCommitMarker(Fee_30_FlexNor_SlimInstance_ConstContextPtrType ctx)
{
    Fee_30_FlexNor_Instance_ReadCommitMarker(&ctx->GenericContext, ctx->Instance.InstanceData->StartAddress,
        &Fee_30_FlexNor_SlimInstance_ResultHandler); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
}

/**********************************************************************************************************************
* Fee_30_FlexNor_SlimInstance_ValidateCommitMarker()
*********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Fee_30_FlexNor_StructureValidityType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimInstance_ValidateCommitMarker(
    Fee_30_FlexNor_SlimInstance_ConstContextPtrType ctx)
{
    return Fee_30_FlexNor_Shared_GetMarkerValidity(
        ctx->GenericContext.InstanceBuffer,
        0u,
        Fee_30_FlexNor_CommitMarker,
        ctx->GenericContext.PartitionConfig->PageAlignment,
        ctx->GenericContext.PartitionConfig->ErasedValue
    ); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
}

#    define FEE_30_FLEXNOR_STOP_SEC_CODE
#    include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif

    /**********************************************************************************************************************
     *  END OF FILE: Fee_30_FlexNor_SlimInstance.c
     *********************************************************************************************************************/
