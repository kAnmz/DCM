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
/*!        \file  Fee_30_FlexNor_CopyBlock.c
 *        \brief  Copy block implementation
 *      \details  Provides the business logic for the copy block services.
 *         \unit  CopyBlock
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#define FEE_30_FLEXNOR_COPYBLOCK_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Fee_30_FlexNor_CopyBlock.h"
#include "Fee_30_FlexNor_CopyBlockInternal.h"
#include "Fee_30_FlexNor_CopyBlockMachine.h"

#include "Fee_30_FlexNor_Scheduler.h"
#include "Fee_30_FlexNor_ChunkFactory.h"

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
#define FEE_30_FLEXNOR_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Context variable of the copy block state machine. */
FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_CopyBlock_ContextType Fee_30_FlexNor_CopyBlockStmContext = { 0u }; /* PRQA S 3218 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */

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
 * Fee_30_FlexNor_CopyBlock_ResultHandler()
 *********************************************************************************************************************/
/*! \brief       Handels the result of services called by the copy block unit
 *  \details     -
 *  \param[in]   result     Result of the called service
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_CopyBlock_ResultHandler(Fee_30_FlexNor_ServiceResult result);

/**********************************************************************************************************************
 * Fee_30_FlexNor_CopyBlock_ProcessingHandler()
 *********************************************************************************************************************/
/*! \brief       Handles the processing event
 *  \details     Triggers the process event at the local state machine.
 *  \return      FEE_30_FLEXNOR_STOP_SCHEDULE       In case the scheduling shall be stopped
 *               FEE_30_FLEXNOR_CONTINUE_SCHEDULE   In case the scheduling can be continued
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FEE_30_FLEXNOR_LOCAL FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_CopyBlock_ProcessingHandler(void);

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * Fee_30_FlexNor_CopyBlock_ResultHandler()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_CopyBlock_ResultHandler(Fee_30_FlexNor_ServiceResult result)
{
    /* If the sector is full, TryAllocateChunk returns with FEE_30_FLEXNOR_SERVICE_NOT_OK. This case will 
    be treated the same as a failed job by garbage collection: restart with RecoverLookupTable. */ 
    if((result == FEE_30_FLEXNOR_SERVICE_FAIL) || (result == FEE_30_FLEXNOR_SERVICE_NOT_OK))
    {
        Fee_30_FlexNor_CopyBlockStmContext.CurrentState->FailEvent(&Fee_30_FlexNor_CopyBlockStmContext); /* SBSW_Fee_30_FlexNor_TriggerEventAtState */
    }
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_CopyBlock_ProcessingHandler()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FEE_30_FLEXNOR_LOCAL FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_CopyBlock_ProcessingHandler(void)
{
    return Fee_30_FlexNor_CopyBlockStmContext.CurrentState->ProcessEvent(&Fee_30_FlexNor_CopyBlockStmContext); /* SBSW_Fee_30_FlexNor_TriggerEventAtState */
}

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Fee_30_FlexNor_CopyBlock_Init()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_CopyBlock_Init(void)
{
    Fee_30_FlexNor_CopyBlock_InitState(&Fee_30_FlexNor_CopyBlockStmContext); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_CopyBlock_StartJob()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_CopyBlock_StartJob(void)
{
    Fee_30_FlexNor_Scheduler_RegisterUnit(&Fee_30_FlexNor_CopyBlock_ProcessingHandler); /* SBSW_Fee_30_FlexNor_RegisterUnit */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_CopyBlock_EndJob()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_CopyBlock_EndJob(void)
{
    Fee_30_FlexNor_Scheduler_UnregisterUnit();
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_CopyBlock_Copy()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_CopyBlock_Copy(  /* PRQA S 6060 */ /* MD_MSR_STPAR */
    Fee_30_FlexNor_PartitionIdType partitionId,
    Fee_30_FlexNor_BlockIdType blockId, 
    Fee_30_FlexNor_SectorPtrType sourceSector,
    Fee_30_FlexNor_SectorPtrType targetSector, 
    Fee_30_FlexNor_PagebasedOffsetType chunkOffset,
    boolean resetInstanceCount,
    Fee_30_FlexNor_ResultCallback resultCbk)
{
    Fee_30_FlexNor_CopyBlockStmContext.PartitionConfig = Fee_30_FlexNor_ConfigInterface_GetPartitionConfig(partitionId);
    Fee_30_FlexNor_CopyBlockStmContext.BlockToCopy.BlockConfig = Fee_30_FlexNor_ConfigInterface_GetBlockConfigById(partitionId, blockId);
    Fee_30_FlexNor_CopyBlockStmContext.SourceSector = sourceSector; 
    Fee_30_FlexNor_CopyBlockStmContext.TargetSector = targetSector; 
    Fee_30_FlexNor_CopyBlockStmContext.BlockToCopy.ChunkOffset = chunkOffset;
    Fee_30_FlexNor_CopyBlockStmContext.resetInstanceCount = resetInstanceCount;
    Fee_30_FlexNor_CopyBlockStmContext.ResultCallback = resultCbk;

    Fee_30_FlexNor_CopyBlock_Copy_Initialize(&Fee_30_FlexNor_CopyBlockStmContext); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_CopyBlock_ReadSourceChunk()
*********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_CopyBlock_ReadSourceChunk(Fee_30_FlexNor_CopyBlock_ContextPtrType ctx)
{
    Fee_30_FlexNor_AddressType chunkAddress = 
        ctx->SourceSector->StartAddress + (ctx->BlockToCopy.ChunkOffset * ctx->PartitionConfig->PageAlignment);

    Fee_30_FlexNor_ChunkFactory_CreateChunk(chunkAddress, 
        ctx->PartitionConfig->PartitionId, 
        ctx->SourceSector->SectorId, 
        &ctx->BlockToCopy.SourceChunk); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    ctx->BlockToCopy.SourceChunk.Services.ReadHeader(&ctx->BlockToCopy.SourceChunk, &Fee_30_FlexNor_CopyBlock_ResultHandler); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */ 
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_CopyBlock_FindLatestInstance()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_CopyBlock_FindLatestInstance(Fee_30_FlexNor_CopyBlock_ContextPtrType ctx)
{
    ctx->BlockToCopy.SourceChunk.Services.FindLatestValidInstance(
        &ctx->BlockToCopy.SourceChunk, 
        &ctx->BlockToCopy.SourceInstance, 
        &Fee_30_FlexNor_CopyBlock_ResultHandler); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_CopyBlock_AllocateCopy()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_CopyBlock_AllocateCopy(Fee_30_FlexNor_CopyBlock_ContextPtrType ctx)
{
    ctx->BlockToCopy.SourceInstance.Data.PayloadSize = ctx->BlockToCopy.SourceChunk.Data.PayloadSize; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    ctx->BlockToCopy.SourceInstance.Data.PayloadOffset = 0u; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */

    ctx->BlockToCopy.TargetChunk = ctx->BlockToCopy.SourceChunk; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */

    Fee_30_FlexNor_Sector_TryAllocateChunk(
        ctx->TargetSector, 
        &ctx->BlockToCopy.TargetChunk, 
        &ctx->BlockToCopy.SourceInstance, 
        &ctx->BlockToCopy.TargetInstance, 
        &ctx->BlockToCopy.SourceChunk, 
        ctx->resetInstanceCount,
        &Fee_30_FlexNor_CopyBlock_ResultHandler); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
}

#define FEE_30_FLEXNOR_STOP_SEC_CODE
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: Fee_30_FlexNor_CopyBlock.c
 *********************************************************************************************************************/
