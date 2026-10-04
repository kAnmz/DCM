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
/*!        \file  Fee_30_FlexNor_Partition.c
 *        \brief  Partition implementation
 *      \details  Provides the business logic for the partition services.
 *         \unit  Partition
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#define FEE_30_FLEXNOR_PARTITION_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Fee_30_FlexNor_Partition.h"
#include "Fee_30_FlexNor_PartitionInternal.h"
#include "Fee_30_FlexNor_PartitionMachine.h"

#include "Fee_30_FlexNor_Scheduler.h"
#include "Fee_30_FlexNor_Shared.h"
#include "Fee_30_FlexNor_ChunkSearch.h"
#include "Fee_30_FlexNor_GarbageCollection.h"
#include "Fee_30_FlexNor_LookupTable.h"
#include "Fee_30_FlexNor_SectorContainer.h"
#include "Fee_30_FlexNor_Startup.h"
#include "Fee_30_FlexNor_InstanceFactory.h"

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
#define FEE_30_FLEXNOR_PARTITION_SECTORIDCONVERSION_SHIFT 24u
#define FEE_30_FLEXNOR_PARTITION_TARGETADDRESS_MASK 0x00FFFFFFuL

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

/*! Context variable of the partition state machine. */
FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_Partition_ContextType Fee_30_FlexNor_PartitionStmContext = { 0u }; /* PRQA S 3218 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */

/*! Stores all flags of the partitions. */
FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_Partition_FlagsType Fee_30_FlexNor_PartitionsFlags[FEE_30_FLEXNOR_CONFIGURED_PARTITIONS] = { 0u }; /* PRQA S 3218 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */

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
 * Fee_30_FlexNor_Partition_ProcessingHandler()
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
FEE_30_FLEXNOR_LOCAL FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_ProcessingHandler(void);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_SetupInstance()
 *********************************************************************************************************************/
/*! \brief       Sets up the instance for allocation with data from the current write job
 *  \details     -
 *  \param[in]   ctx    Context that contains the instance to set up as well as the current job. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FEE_30_FLEXNOR_LOCAL FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_SetupInstance(Fee_30_FlexNor_Partition_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_SetupChunk()
 *********************************************************************************************************************/
/*! \brief       Sets up the chunk for allocation with data from the current write job
 *  \details     -
 *  \param[in]   ctx    Context that contains the chunk to set up as well as the current job. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FEE_30_FLEXNOR_LOCAL FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_SetupChunk(Fee_30_FlexNor_Partition_ContextPtrType ctx);

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_ProcessingHandler()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FEE_30_FLEXNOR_LOCAL FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_ProcessingHandler(void)
{
    return Fee_30_FlexNor_PartitionStmContext.CurrentState->ProcessEvent(&Fee_30_FlexNor_PartitionStmContext); /* SBSW_Fee_30_FlexNor_TriggerEventAtState */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_ResultHandler()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_ResultHandler(Fee_30_FlexNor_ServiceResult result)
{
    if(result == FEE_30_FLEXNOR_SERVICE_FAIL)
    {
        Fee_30_FlexNor_PartitionStmContext.CurrentState->FailEvent(&Fee_30_FlexNor_PartitionStmContext); /* SBSW_Fee_30_FlexNor_TriggerEventAtState */
    }
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_AllocationResultHandler()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_AllocationResultHandler(Fee_30_FlexNor_ServiceResult result)
{
    Fee_30_FlexNor_PartitionStmContext.AllocationResult = result;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_SetupInstance()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FEE_30_FLEXNOR_LOCAL FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_SetupInstance(Fee_30_FlexNor_Partition_ContextPtrType ctx)
{
    ctx->Instance.Data.Status = (ctx->CurrentJob->Length != 0u) ? FEE_30_FLEXNOR_INSTANCE_VALID : 
                                                                  FEE_30_FLEXNOR_INSTANCE_INVALIDATED; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    ctx->Instance.Data.WriteBuffer = ctx->CurrentJob->WriteBuffer; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    ctx->Instance.Data.PayloadSize = ctx->CurrentJob->Length; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    ctx->Instance.Data.PayloadOffset = 0u; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_SetupChunk()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FEE_30_FLEXNOR_LOCAL FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_SetupChunk(Fee_30_FlexNor_Partition_ContextPtrType ctx)
{
    ctx->ChunkToAllocate.Data.BlockId = ctx->CurrentJob->BlockId; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    ctx->ChunkToAllocate.Data.PayloadSize = (Fee_30_FlexNor_PayloadSizeType)ctx->CurrentJob->Length; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */

    ctx->ChunkToAllocate.Data.Validity = FEE_30_FLEXNOR_VALID; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    ctx->ChunkToAllocate.Data.ErrorLocation = FEE_30_FLEXNOR_CHUNK_ERROR_NOERROR; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */

    ctx->ChunkToAllocate.Data.ReallocationRequired = FALSE; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
}

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_Init()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_Init(void)
{
    for(uint16 pIndex = 0u; pIndex < FEE_30_FLEXNOR_CONFIGURED_PARTITIONS; pIndex++)
    {
        Fee_30_FlexNor_PartitionsFlags[pIndex].StartupExecuted = FALSE; /* SBSW_Fee_30_FlexNor_PartitionFlags */
    }

    Fee_30_FlexNor_PartitionStmContext.Flags = Fee_30_FlexNor_PartitionsFlags;
    Fee_30_FlexNor_Partition_InitState(&Fee_30_FlexNor_PartitionStmContext); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_StartJob()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_StartJob(void)
{
    Fee_30_FlexNor_Scheduler_RegisterUnit(&Fee_30_FlexNor_Partition_ProcessingHandler); /* SBSW_Fee_30_FlexNor_RegisterUnit */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_EndJob()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_EndJob(void)
{
    Fee_30_FlexNor_Scheduler_UnregisterUnit();
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_EndStartUpJob()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_EndStartupJob(void)
{
    Fee_30_FlexNor_Scheduler_UnregisterUnit();
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_IsStartedUp()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(boolean, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_IsStartedUp(Fee_30_FlexNor_PartitionIdType partitionId)
{
    return Fee_30_FlexNor_PartitionsFlags[partitionId].StartupExecuted;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_ResetStartup()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_ResetStartup(Fee_30_FlexNor_PartitionIdType partitionId)
{
    Fee_30_FlexNor_PartitionsFlags[partitionId].StartupExecuted = FALSE; /* SBSW_Fee_30_FlexNor_PartitionFlags */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_StartUp()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_StartUp(Fee_30_FlexNor_PartitionIdType partitionId,
                                                                 Fee_30_FlexNor_ResultCallback resultCbk)
{
    Fee_30_FlexNor_PartitionStmContext.PartitionId = partitionId;
    Fee_30_FlexNor_PartitionStmContext.ResultCallback = resultCbk;
    Fee_30_FlexNor_Partition_StartUp_Initialize(&Fee_30_FlexNor_PartitionStmContext); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_ReadBlock()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_ReadBlock(Fee_30_FlexNor_JobPtrType currentJob)
{
    Fee_30_FlexNor_PartitionStmContext.CurrentJob = currentJob;
    Fee_30_FlexNor_Partition_ReadBlock_Initialize(&Fee_30_FlexNor_PartitionStmContext); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_ReadChunk()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_ReadChunk(Fee_30_FlexNor_Partition_ContextPtrType ctx)
{
    Fee_30_FlexNor_LookupTable_LinkType lutLink = Fee_30_FlexNor_LookupTable_GetLink(ctx->CurrentJob->PartitionId, ctx->CurrentJob->BlockId);
    Fee_30_FlexNor_AddressType chunkAddress = Fee_30_FlexNor_ChunkSearch_CalculateChunkAddress(ctx->CurrentJob->PartitionId, lutLink.SectorId, lutLink.ChunkOffset);

    Fee_30_FlexNor_ChunkFactory_CreateChunk(chunkAddress, ctx->CurrentJob->PartitionId, lutLink.SectorId, &ctx->LatestChunk); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    ctx->LatestChunk.Services.ReadHeader(&ctx->LatestChunk, &Fee_30_FlexNor_Partition_ResultHandler); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_ReadSectorHeaders()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_ReadSectorHeaders(Fee_30_FlexNor_Partition_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    Fee_30_FlexNor_Startup_ReadSectorHeaders(ctx->PartitionId, &Fee_30_FlexNor_Partition_ResultHandler); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_GetLookupTable()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_GetLookupTable(Fee_30_FlexNor_Partition_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    Fee_30_FlexNor_Startup_GetLookupTable(ctx->PartitionId, &Fee_30_FlexNor_Partition_ResultHandler); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_GetLatestValidInstanceFromChunk()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_GetLatestValidInstanceFromChunk(Fee_30_FlexNor_Partition_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    Fee_30_FlexNor_InstanceFactory_CreateInstance(0x0u, ctx->CurrentJob->PartitionId, &ctx->Instance); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    /* The instance may be uninitialized here, since the chunk will allocate all necessary functions and data. */
    ctx->LatestChunk.Services.FindLatestValidInstance(&ctx->LatestChunk, &ctx->Instance, &Fee_30_FlexNor_Partition_ResultHandler); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_ReadInstanceContent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_ReadInstanceContent(Fee_30_FlexNor_Partition_ContextPtrType ctx)
{
    ctx->Instance.Data.ReadBuffer = ctx->CurrentJob->ReadBuffer; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    ctx->Instance.Data.PayloadSize = ctx->CurrentJob->Length; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    ctx->Instance.Data.PayloadOffset = ctx->CurrentJob->Offset; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */

    ctx->Instance.Services.ReadContent(&ctx->Instance.Data, &Fee_30_FlexNor_Partition_ResultHandler); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_TriggerLookupTableRecovery()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_TriggerLookupTableRecovery(Fee_30_FlexNor_Partition_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    Fee_30_FlexNor_LookupTable_FullRecovery(ctx->CurrentJob->PartitionId, &Fee_30_FlexNor_Partition_ResultHandler); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_WriteBlock()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_WriteBlock(Fee_30_FlexNor_JobPtrType currentJob)
{
    Fee_30_FlexNor_PartitionStmContext.CurrentJob = currentJob;
    Fee_30_FlexNor_Partition_WriteBlock_Initialize(&Fee_30_FlexNor_PartitionStmContext); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_TriggerInstanceAllocation()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_TriggerInstanceAllocation(Fee_30_FlexNor_Partition_ContextPtrType ctx)
{
    Fee_30_FlexNor_Partition_SetupInstance(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    ctx->LatestChunk.Services.TryAllocateInstance(&ctx->LatestChunk, &ctx->Instance, &Fee_30_FlexNor_Partition_AllocationResultHandler); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_TriggerChunkAllocation()
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
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_TriggerChunkAllocation(Fee_30_FlexNor_Partition_ContextPtrType ctx)
{    
    Fee_30_FlexNor_Partition_SetupChunk(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */

    Fee_30_FlexNor_Partition_SetupInstance(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */

    if((ctx->LatestChunkFound == TRUE) && (ctx->LatestChunk.Data.ChunkLink.Validity == FEE_30_FLEXNOR_EMPTY))
    {
        Fee_30_FlexNor_Sector_TryAllocateChunk(ctx->TargetSector, &ctx->ChunkToAllocate, NULL_PTR, &ctx->Instance,
                                            &ctx->LatestChunk, FALSE, &Fee_30_FlexNor_Partition_AllocationResultHandler); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
    }
    else
    {
        Fee_30_FlexNor_Sector_TryAllocateChunk(ctx->TargetSector, &ctx->ChunkToAllocate, NULL_PTR, &ctx->Instance, 
                                            NULL_PTR, FALSE, &Fee_30_FlexNor_Partition_AllocationResultHandler); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
    }
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_TriggerSectorAllocation()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_TriggerSectorAllocation(Fee_30_FlexNor_Partition_ConstContextPtrType ctx)
{
    Fee_30_FlexNor_ConstPartitionConfigPtrType partitionConfig = Fee_30_FlexNor_ConfigInterface_GetPartitionConfig(ctx->CurrentJob->PartitionId);
   
    ctx->TargetSector->SectorId = Fee_30_FlexNor_SectorContainer_GetNextSectorId(ctx->CurrentJob->PartitionId); /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    ctx->TargetSector->EraseCycle = Fee_30_FlexNor_SectorContainer_GetNextEraseCycle(ctx->TargetSector); /* SBSW_Fee_30_FlexNor_ContextPointerAccess */ /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
    ctx->TargetSector->GcReason = FEE_30_FLEXNOR_GC_REASON_SPACE; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    ctx->TargetSector->Layout = partitionConfig->Layout; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */

    Fee_30_FlexNor_Sector_Allocate(ctx->TargetSector, &Fee_30_FlexNor_Partition_ResultHandler); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_GetAvailableSector()
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
FUNC(Fee_30_FlexNor_SectorPtrType, FEE_30_FLEXNOR_CODE)  Fee_30_FlexNor_Partition_GetAvailableSector(Fee_30_FlexNor_Partition_ConstContextPtrType ctx)
{
    uint8 availableSectorCount = 0u;
    Fee_30_FlexNor_SectorPtrType nextAvailableSector = NULL_PTR;
    Fee_30_FlexNor_SectorPtrType storedSector = Fee_30_FlexNor_SectorContainer_GetFirst(ctx->CurrentJob->PartitionId);

    while(storedSector != NULL_PTR)
    {
        if(storedSector->Validity != FEE_30_FLEXNOR_VALID)
        {
            availableSectorCount++;

            if(nextAvailableSector == NULL_PTR)
            {
                nextAvailableSector = storedSector;
            }
        }

        storedSector = Fee_30_FlexNor_SectorContainer_GetNext(storedSector); /* SBSW_Fee_30_FlexNor_LoopStoredSectors */
    }

    if(availableSectorCount < 2u)
    {
        nextAvailableSector = NULL_PTR;
    }
    
    return nextAvailableSector;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_TriggerGarbageCollection()
 *********************************************************************************************************************/
/*!
 * Internal comment removed. *
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_TriggerGarbageCollection(Fee_30_FlexNor_Partition_ConstContextPtrType ctx)
{
    boolean isPersistLutJobRunning = (boolean) (ctx->CurrentJob->BlockId == FEE_30_FLEXNOR_LUTBLOCKID);

    Fee_30_FlexNor_GarbageCollection_Run(
        ctx->CurrentJob->PartitionId, 
        NULL_PTR, 
        isPersistLutJobRunning,
        &Fee_30_FlexNor_Partition_ResultHandler); /* SBSW_Fee_30_FlexNor_ResultHandler */

}

#define FEE_30_FLEXNOR_STOP_SEC_CODE
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: Fee_30_FlexNor_Partition.c
 *********************************************************************************************************************/
