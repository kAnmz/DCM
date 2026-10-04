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
/*!        \file  Fee_30_FlexNor_PartitionMachine.c
 *        \brief  Partition state machine implementation
 *      \details  Provides the implementation of the state machine logic for the partition unit.
 *         \unit  Partition
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/
#define FEE_30_FLEXNOR_PARTITIONMACHINE_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Fee_30_FlexNor_PartitionMachine.h"
#include "Fee_30_FlexNor_PartitionInternal.h"
#include "Fee_30_FlexNor_Partition.h"

#include "Fee_30_FlexNor_Types.h"
#include "Fee_30_FlexNor_Shared.h"
#include "Fee_30_FlexNor_GarbageCollection.h"
#include "Fee_30_FlexNor_LookupTable.h"
#include "Fee_30_FlexNor_SectorContainer.h"

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

FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_Partition_ConstStateType Fee_30_FlexNor_PartitionDefaultState = { /* PRQA S 3218 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
    &Fee_30_FlexNor_Partition_DefaultProcessEvent, 
    &Fee_30_FlexNor_Partition_DefaultFailEvent
};

FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_Partition_ConstStateType Fee_30_FlexNor_PartitionReadSectorHeadersState = { /* PRQA S 3218 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
    &Fee_30_FlexNor_Partition_ReadSectorHeaders_ProcessEvent, 
    &Fee_30_FlexNor_Partition_StartupJobFailEvent
};

FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_Partition_ConstStateType Fee_30_FlexNor_PartitionGetLookupTableState = { /* PRQA S 3218 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
    &Fee_30_FlexNor_Partition_GetLookupTable_ProcessEvent, 
    &Fee_30_FlexNor_Partition_StartupJobFailEvent
};

FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_Partition_ConstStateType Fee_30_FlexNor_PartitionSearchLatestChunkState = { /* PRQA S 3218 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
    &Fee_30_FlexNor_Partition_SearchLatestChunk_ProcessEvent, 
    &Fee_30_FlexNor_Partition_ResetStartupFailEvent
};

FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_Partition_ConstStateType Fee_30_FlexNor_PartitionRecoverLookupTableState = { /* PRQA S 3218 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
    &Fee_30_FlexNor_Partition_RecoverLookupTable_ProcessEvent, 
    &Fee_30_FlexNor_Partition_ResetStartupFailEvent
};

FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_Partition_ConstStateType Fee_30_FlexNor_PartitionSearchLatestInstanceState = { /* PRQA S 3218 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
    &Fee_30_FlexNor_Partition_SearchLatestInstance_ProcessEvent, 
    &Fee_30_FlexNor_Partition_InstanceSearchFailEvent
};

FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_Partition_ConstStateType Fee_30_FlexNor_PartitionReadLatestInstanceContentState = { /* PRQA S 3218 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
    &Fee_30_FlexNor_Partition_ReadLatestInstanceContent_ProcessEvent, 
    &Fee_30_FlexNor_Partition_ResetStartupFailEvent
};

FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_Partition_ConstStateType Fee_30_FlexNor_PartitionAllocateInExistingChunkState = { /* PRQA S 3218 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
    &Fee_30_FlexNor_Partition_AllocateInExistingChunk_ProcessEvent, 
    &Fee_30_FlexNor_Partition_ResetStartupFailEvent
};

FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_Partition_ConstStateType Fee_30_FlexNor_PartitionAllocateNewChunkState = { /* PRQA S 3218 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
    &Fee_30_FlexNor_Partition_AllocateNewChunk_ProcessEvent, 
    &Fee_30_FlexNor_Partition_ResetStartupFailEvent
};

FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_Partition_ConstStateType Fee_30_FlexNor_PartitionGetNewSectorState = { /* PRQA S 3218 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
    &Fee_30_FlexNor_Partition_GetNewSector_ProcessEvent, 
    &Fee_30_FlexNor_Partition_ResetStartupFailEvent
};

FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_Partition_ConstStateType Fee_30_FlexNor_PartitionGarbageCollectionState = { /* PRQA S 3218 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
    &Fee_30_FlexNor_Partition_GarbageCollection_ProcessEvent, 
    &Fee_30_FlexNor_Partition_ResetStartupFailEvent
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
 * Fee_30_FlexNor_Partition_ReadBlock_NoChunkFound()
 *********************************************************************************************************************/
/*! \brief       Handels the event that no chunk was found for the block during a read job
 *  \details     -
 *  \param[in]   ctx    Pointer to the context that contains the data for handling the event. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FEE_30_FLEXNOR_LOCAL FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_ReadBlock_NoChunkFound(
    Fee_30_FlexNor_Partition_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_ReadBlock_LatestChunkFound()
 *********************************************************************************************************************/
/*! \brief       Handels the event that the latest chunk for the block was found during a read job
 *  \details     -
 *  \param[in]   ctx    Pointer to the context that contains the data for handling the event. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FEE_30_FLEXNOR_LOCAL FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_ReadBlock_LatestChunkFound(
    Fee_30_FlexNor_Partition_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_WriteBlock_NoChunkFound()
 *********************************************************************************************************************/
/*! \brief       Handels the event that no chunk was found for the block during a write job
 *  \details     -
 *  \param[in]   ctx    Pointer to the context that contains the data for handling the event. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FEE_30_FLEXNOR_LOCAL FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_WriteBlock_NoChunkFound(
    Fee_30_FlexNor_Partition_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_WriteBlock_LatestChunkFound()
 *********************************************************************************************************************/
/*! \brief       Handels the event that the latest chunk for the block was found during a write job
 *  \details     -
 *  \param[in]   ctx    Pointer to the context that contains the data for handling the event. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FEE_30_FLEXNOR_LOCAL FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_WriteBlock_LatestChunkFound(
    Fee_30_FlexNor_Partition_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_IsLinkValid()
 *********************************************************************************************************************/
/*! \brief       Checks if the given link is valid
 *  \details     The link is valid in case it consists of an valid sector id and offset.
 *  \param[in]   link           Link that shall be checked
 *  \param[in]   partitionId    Id of the currently processed partition
 *  \return      TRUE           The given link is valid
 *               FALSE          The given link is invalid (sector Id is zero, chunk offset is zero or sector is not valid)
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FEE_30_FLEXNOR_LOCAL FUNC(boolean, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_IsLinkValid(
    Fee_30_FlexNor_LookupTable_ConstLinkPtrType link, const Fee_30_FlexNor_PartitionIdType partitionId);

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_ReadBlock_NoChunkFound()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FEE_30_FLEXNOR_LOCAL FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_ReadBlock_NoChunkFound(
    Fee_30_FlexNor_Partition_ContextPtrType ctx)
{
    ctx->CurrentJob->JobResult = MEMIF_BLOCK_INVALID; /* SBSW_Fee_30_FlexNor_ParamPointerJobResultWriteAccess */
    ctx->CurrentState = &Fee_30_FlexNor_PartitionDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_Partition_EndJob(); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_ReadBlock_LatestChunkFound()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FEE_30_FLEXNOR_LOCAL FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_ReadBlock_LatestChunkFound(
    Fee_30_FlexNor_Partition_ContextPtrType ctx)
{
    Fee_30_FlexNor_ConstBlockConfigPtrType blockCfg = Fee_30_FlexNor_ConfigInterface_GetBlockConfigById(
        ctx->LatestChunk.Data.PartitionId, ctx->LatestChunk.Data.BlockId);

    if(blockCfg->Length == ctx->LatestChunk.Data.PayloadSize)
    {
        ctx->CurrentState = &Fee_30_FlexNor_PartitionSearchLatestInstanceState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        Fee_30_FlexNor_Partition_GetLatestValidInstanceFromChunk(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }
    else
    {
        Fee_30_FlexNor_Partition_ReadBlock_NoChunkFound(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_WriteBlock_NoChunkFound()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FEE_30_FLEXNOR_LOCAL FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_WriteBlock_NoChunkFound(
    Fee_30_FlexNor_Partition_ContextPtrType ctx)
{
    ctx->TargetSector = Fee_30_FlexNor_SectorContainer_GetNewestValid(ctx->CurrentJob->PartitionId); /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    ctx->CurrentState = &Fee_30_FlexNor_PartitionAllocateNewChunkState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_Partition_AllocateNewChunk_OnEnter(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_WriteBlock_LatestChunkFound()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FEE_30_FLEXNOR_LOCAL FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_WriteBlock_LatestChunkFound(
    Fee_30_FlexNor_Partition_ContextPtrType ctx)
{
    Fee_30_FlexNor_ConstBlockConfigPtrType blockCfg = Fee_30_FlexNor_ConfigInterface_GetBlockConfigById(
        ctx->LatestChunk.Data.PartitionId, ctx->LatestChunk.Data.BlockId);

    if((blockCfg->Length == ctx->LatestChunk.Data.PayloadSize) && (ctx->LatestChunk.Data.InstanceCount > 1u))
    {
        ctx->CurrentState = &Fee_30_FlexNor_PartitionAllocateInExistingChunkState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        Fee_30_FlexNor_Partition_TriggerInstanceAllocation(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }
    else
    {
        ctx->TargetSector = Fee_30_FlexNor_SectorContainer_GetNewestValid(ctx->CurrentJob->PartitionId); /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        ctx->CurrentState = &Fee_30_FlexNor_PartitionAllocateNewChunkState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        Fee_30_FlexNor_Partition_AllocateNewChunk_OnEnter(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }   
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_IsLinkValid()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FEE_30_FLEXNOR_LOCAL FUNC(boolean, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_IsLinkValid(
    Fee_30_FlexNor_LookupTable_ConstLinkPtrType link, const Fee_30_FlexNor_PartitionIdType partitionId)
{
    Fee_30_FlexNor_ConstSectorPtrType sector = Fee_30_FlexNor_SectorContainer_Get(partitionId, link->SectorId, TRUE);

    return ((link->SectorId == 0u) || (link->ChunkOffset == 0u) || (sector == NULL_PTR)) ?  FALSE : TRUE;
}

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_InitState()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_InitState(Fee_30_FlexNor_Partition_ContextPtrType ctx)
{
    ctx->CurrentState = &Fee_30_FlexNor_PartitionDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_DefaultProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_DefaultProcessEvent(
    Fee_30_FlexNor_Partition_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    FEE_DUMMY_STATEMENT(ctx);
    return FEE_30_FLEXNOR_STOP_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_DefaultFailEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_DefaultFailEvent(Fee_30_FlexNor_Partition_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    FEE_DUMMY_STATEMENT(ctx);
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_JobFailEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_JobFailEvent(Fee_30_FlexNor_Partition_ContextPtrType ctx)
{
    ctx->CurrentJob->JobResult = MEMIF_JOB_FAILED;  /* SBSW_Fee_30_FlexNor_ParamPointerJobResultWriteAccess */
    ctx->CurrentState = &Fee_30_FlexNor_PartitionDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_Partition_EndJob(); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_InstanceSearchFailEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_InstanceSearchFailEvent(
    Fee_30_FlexNor_Partition_ContextPtrType ctx)
{
    Fee_30_FlexNor_Chunk_InstanceSearchResultType instanceSearchResult 
        = ctx->LatestChunk.Services.GetJobResultOfInstanceSearch(); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    if(instanceSearchResult == FEE_30_FLEXNOR_INSTANCESEARCH_NO_VALID_INSTANCE_FOUND)
    {
        Fee_30_FlexNor_InternalJobs_RequestRecoveryGarbageCollection(ctx->LatestChunk.Data.PartitionId,
            ctx->LatestChunk.Data.StartAddress);
    }
    else
    {
        /* The instance search fails only due to read errors. So the startup must be repeated. */
        Fee_30_FlexNor_Partition_ResetStartup(ctx->CurrentJob->PartitionId);
    }
    
    Fee_30_FlexNor_Partition_JobFailEvent(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_ResetStartupFailEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_ResetStartupFailEvent(
    Fee_30_FlexNor_Partition_ContextPtrType ctx)
{
    Fee_30_FlexNor_Partition_ResetStartup(ctx->CurrentJob->PartitionId);
    Fee_30_FlexNor_Partition_JobFailEvent(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_StartupJobFailEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_StartupJobFailEvent(
    Fee_30_FlexNor_Partition_ContextPtrType ctx)
{
    ctx->CurrentState = &Fee_30_FlexNor_PartitionDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_Partition_EndStartupJob();

    ctx->ResultCallback(FEE_30_FLEXNOR_SERVICE_FAIL); /* SBSW_Fee_30_FlexNor_ContextFunctionPointerCall */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_StartUp_Initialize
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_StartUp_Initialize(Fee_30_FlexNor_Partition_ContextPtrType ctx)
{
    Fee_30_FlexNor_Partition_StartJob();

    ctx->CurrentState = &Fee_30_FlexNor_PartitionReadSectorHeadersState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_Partition_ReadSectorHeaders(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_ReadSectorHeaders_ProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_ReadSectorHeaders_ProcessEvent(
    Fee_30_FlexNor_Partition_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    ctx->CurrentState = &Fee_30_FlexNor_PartitionGetLookupTableState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_Partition_GetLookupTable(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_GetLookupTable_ProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_GetLookupTable_ProcessEvent(
    Fee_30_FlexNor_Partition_ContextPtrType ctx)
{
    ctx->Flags[ctx->PartitionId].StartupExecuted = TRUE; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */

    ctx->CurrentState = &Fee_30_FlexNor_PartitionDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_Partition_EndStartupJob();

    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_ReadBlock_Initialize
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_ReadBlock_Initialize(
    Fee_30_FlexNor_Partition_ContextPtrType ctx)
{
    ctx->NoChunkFoundAction = &Fee_30_FlexNor_Partition_ReadBlock_NoChunkFound; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    ctx->LatestChunkFoundAction = &Fee_30_FlexNor_Partition_ReadBlock_LatestChunkFound; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */

    Fee_30_FlexNor_Partition_StartJob();

    ctx->CurrentState = &Fee_30_FlexNor_PartitionSearchLatestChunkState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_Partition_SearchLatestChunk_OnEnter(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */ 
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_SearchLatestChunk_OnEnter()
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
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_SearchLatestChunk_OnEnter(
    Fee_30_FlexNor_Partition_ContextPtrType ctx)
{
    Fee_30_FlexNor_LookupTable_LinkType lutLink = Fee_30_FlexNor_LookupTable_GetLink(
        ctx->CurrentJob->PartitionId, ctx->CurrentJob->BlockId);
    boolean isLutValid = Fee_30_FlexNor_LookupTable_IsValid(ctx->CurrentJob->PartitionId);
    boolean isLinkValid = Fee_30_FlexNor_Partition_IsLinkValid(&lutLink, ctx->CurrentJob->PartitionId); /* SBSW_Fee_30_FlexNor_FunctionCallWithPointerToLocal */

    ctx->LatestChunkFound = FALSE; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    
    if(isLutValid == TRUE)
    {
        if(isLinkValid == TRUE)
        {
            Fee_30_FlexNor_Partition_ReadChunk(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
        }
        else
        {
            ctx->NoChunkFoundAction(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
        }
    }
    else
    {
        ctx->CurrentState = &Fee_30_FlexNor_PartitionRecoverLookupTableState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        Fee_30_FlexNor_Partition_TriggerLookupTableRecovery(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_SearchLatestChunk_ProcessEvent()
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
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE)Fee_30_FlexNor_Partition_SearchLatestChunk_ProcessEvent(
    Fee_30_FlexNor_Partition_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    Fee_30_FlexNor_StructureValidityType chunkValidity = ctx->LatestChunk.Data.Validity;

    if((chunkValidity != FEE_30_FLEXNOR_VALID) || (ctx->CurrentJob->BlockId != ctx->LatestChunk.Data.BlockId))
    {
        if(ctx->CurrentJob->BlockId == FEE_30_FLEXNOR_LUTBLOCKID)
        {
            ctx->CurrentJob->JobResult = MEMIF_JOB_FAILED;  /* SBSW_Fee_30_FlexNor_ParamPointerJobResultWriteAccess */
            ctx->CurrentState = &Fee_30_FlexNor_PartitionDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
            Fee_30_FlexNor_Partition_EndJob();
        }
        else
        {
            ctx->CurrentState = &Fee_30_FlexNor_PartitionRecoverLookupTableState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
            Fee_30_FlexNor_Partition_TriggerLookupTableRecovery(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
        }
    }
    else /* FEE_30_FLEXNOR_VALID */
    {
        ctx->LatestChunkFound = TRUE; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        ctx->LatestChunkFoundAction(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }

    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_RecoverLookupTable_ProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) 
    Fee_30_FlexNor_Partition_RecoverLookupTable_ProcessEvent(Fee_30_FlexNor_Partition_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    ctx->CurrentState = &Fee_30_FlexNor_PartitionSearchLatestChunkState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_Partition_SearchLatestChunk_OnEnter(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */

    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_SearchLatestInstance_ProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) 
    Fee_30_FlexNor_Partition_SearchLatestInstance_ProcessEvent(Fee_30_FlexNor_Partition_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    Fee_30_FlexNor_LookupTable_RequestChunkReallocation(ctx->LatestChunk.Data.PartitionId, 
    ctx->LatestChunk.Data.BlockId, ctx->LatestChunk.Data.ReallocationRequired);

    ctx->CurrentState = &Fee_30_FlexNor_PartitionReadLatestInstanceContentState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_Partition_ReadInstanceContent(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */

    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_ReadLatestInstanceContent_ProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) 
    Fee_30_FlexNor_Partition_ReadLatestInstanceContent_ProcessEvent(Fee_30_FlexNor_Partition_ContextPtrType ctx)
{
    if(ctx->Instance.Data.Status == FEE_30_FLEXNOR_INSTANCE_VALID)
    {
        ctx->CurrentJob->JobResult = MEMIF_JOB_OK; /* SBSW_Fee_30_FlexNor_ParamPointerJobResultWriteAccess */
    }
    else
    {
        ctx->CurrentJob->JobResult = MEMIF_BLOCK_INVALID; /* SBSW_Fee_30_FlexNor_ParamPointerJobResultWriteAccess */
    }

    ctx->CurrentState = &Fee_30_FlexNor_PartitionDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_Partition_EndJob(); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */

    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_WriteBlock_Initialize()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_WriteBlock_Initialize(
    Fee_30_FlexNor_Partition_ContextPtrType ctx)
{
    ctx->NoChunkFoundAction = &Fee_30_FlexNor_Partition_WriteBlock_NoChunkFound; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    ctx->LatestChunkFoundAction = &Fee_30_FlexNor_Partition_WriteBlock_LatestChunkFound; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */

    Fee_30_FlexNor_Partition_StartJob();

    ctx->CurrentState = &Fee_30_FlexNor_PartitionSearchLatestChunkState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_Partition_SearchLatestChunk_OnEnter(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */ 
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_AllocateInExistingChunk_ProcessEvent()
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
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) 
    Fee_30_FlexNor_Partition_AllocateInExistingChunk_ProcessEvent(Fee_30_FlexNor_Partition_ContextPtrType ctx)
{
    if(ctx->AllocationResult == FEE_30_FLEXNOR_SERVICE_OK)
    {
        ctx->CurrentState = &Fee_30_FlexNor_PartitionDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */ 
        ctx->CurrentJob->JobResult = MEMIF_JOB_OK; /* SBSW_Fee_30_FlexNor_ParamPointerJobResultWriteAccess */
        Fee_30_FlexNor_Partition_EndJob(); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }
    else if(ctx->AllocationResult == FEE_30_FLEXNOR_SERVICE_NOT_OK)
    {
        ctx->TargetSector = Fee_30_FlexNor_SectorContainer_GetNewestValid(ctx->CurrentJob->PartitionId); /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        ctx->CurrentState = &Fee_30_FlexNor_PartitionAllocateNewChunkState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        Fee_30_FlexNor_Partition_AllocateNewChunk_OnEnter(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }
    else /* FEE_30_FLEXNOR_SERVICE_FAIL */
    {
        ctx->CurrentState = &Fee_30_FlexNor_PartitionDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */ 
        ctx->CurrentJob->JobResult = MEMIF_JOB_FAILED; /* SBSW_Fee_30_FlexNor_ParamPointerJobResultWriteAccess */
        Fee_30_FlexNor_Partition_EndJob(); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }

    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_AllocateNewChunk_OnEnter()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_AllocateNewChunk_OnEnter(
    Fee_30_FlexNor_Partition_ContextPtrType ctx)
{
    if(ctx->TargetSector != NULL_PTR)
    {
        Fee_30_FlexNor_Partition_TriggerChunkAllocation(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }
    else
    {
        ctx->CurrentState = &Fee_30_FlexNor_PartitionGetNewSectorState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        Fee_30_FlexNor_Partition_GetNewSector_OnEnter(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_AllocateNewChunk_ProcessEvent()
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
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_AllocateNewChunk_ProcessEvent(
    Fee_30_FlexNor_Partition_ContextPtrType ctx)
{
    if(ctx->AllocationResult == FEE_30_FLEXNOR_SERVICE_OK)
    {
        ctx->CurrentJob->JobResult = MEMIF_JOB_OK;  /* SBSW_Fee_30_FlexNor_ParamPointerJobResultWriteAccess */
        ctx->CurrentState = &Fee_30_FlexNor_PartitionDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */ 
        Fee_30_FlexNor_Partition_EndJob(); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }
    else if(ctx->AllocationResult == FEE_30_FLEXNOR_SERVICE_NOT_OK)
    {
        ctx->CurrentState = &Fee_30_FlexNor_PartitionGetNewSectorState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        Fee_30_FlexNor_Partition_GetNewSector_OnEnter(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }
    else /* FEE_30_FLEXNOR_SERVICE_FAIL */
    {
        Fee_30_FlexNor_Partition_ResetStartup(ctx->CurrentJob->PartitionId);
        ctx->CurrentState = &Fee_30_FlexNor_PartitionDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */ 
        ctx->CurrentJob->JobResult = MEMIF_JOB_FAILED; /* SBSW_Fee_30_FlexNor_ParamPointerJobResultWriteAccess */
        Fee_30_FlexNor_Partition_EndJob(); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }

    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_GetNewSector_OnEnter()
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
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_GetNewSector_OnEnter(
    Fee_30_FlexNor_Partition_ContextPtrType ctx)
{
    ctx->TargetSector = Fee_30_FlexNor_Partition_GetAvailableSector(ctx); /* SBSW_Fee_30_FlexNor_ContextPointerAccess */ /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */

    if(ctx->TargetSector != NULL_PTR)
    {
        Fee_30_FlexNor_Partition_TriggerSectorAllocation(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }
    else
    {
        ctx->CurrentState = &Fee_30_FlexNor_PartitionGarbageCollectionState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        Fee_30_FlexNor_Partition_TriggerGarbageCollection(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_GetNewSector_ProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_GetNewSector_ProcessEvent(
    Fee_30_FlexNor_Partition_ContextPtrType ctx)
{
    ctx->CurrentState = &Fee_30_FlexNor_PartitionAllocateNewChunkState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_Partition_AllocateNewChunk_OnEnter(ctx);             /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_GarbageCollection_ProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_GarbageCollection_ProcessEvent(
    Fee_30_FlexNor_Partition_ContextPtrType ctx)
{
    ctx->CurrentState = &Fee_30_FlexNor_PartitionSearchLatestChunkState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_Partition_SearchLatestChunk_OnEnter(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */ 
    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}
#define FEE_30_FLEXNOR_STOP_SEC_CODE
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: Fee_30_FlexNor_PartitionMachine.c
 *********************************************************************************************************************/
