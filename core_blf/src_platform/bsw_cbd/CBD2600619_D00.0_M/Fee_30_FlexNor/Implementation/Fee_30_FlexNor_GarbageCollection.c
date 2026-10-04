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
/*!        \file  Fee_30_FlexNor_GarbageCollection.c
 *        \brief  Garbage collection implementation
 *      \details  Provides the business logic for the garbage collection services.
 *         \unit  GarbageCollection
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#define FEE_30_FLEXNOR_GARBAGECOLLECTION_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Fee_30_FlexNor_GarbageCollection.h"
#include "Fee_30_FlexNor_GarbageCollectionInternal.h"
#include "Fee_30_FlexNor_GarbageCollectionMachine.h"

#include "Fee_30_FlexNor_Scheduler.h"
#include "Fee_30_FlexNor_CopyBlock.h"
#include "Fee_30_FlexNor_LookupTable.h"
#include "Fee_30_FlexNor_SectorContainer.h"
#include "Fee_30_FlexNor_ChunkFactory.h"
#include "Fee_30_FlexNor_InstanceFactory.h"

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
#define FEE_30_FLEXNOR_MAX_ID_SPAN 50u
#define FEE_30_FLEXNOR_MAX_SCORE 1024u

#define FEE_30_FLEXNOR_SCALER 1000u
#define FEE_30_FLEXNOR_MAX_WEIGHT 100u
#define FEE_30_FLEXNOR_SCORE_WEIGHT 80u

#define FEE_30_FLEXNOR_UINT32_MAX 0xFFFFFFFFu

#define FEE_30_FLEXNOR_INITIAL_VALUE_BLOCK_ID_COPY_BLOCKS 1u  /*!< This value is incremented by 1 so that the LUT 
                                                                   block is not copied during a GC */

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

/*! Context variable of the garbage collection state machine. */
FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_GarbageCollection_ContextType Fee_30_FlexNor_GarbageCollectionStmContext = { 0u }; /* PRQA S 3218 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */

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
 * Fee_30_FlexNor_GarbageCollection_ResultHandler()
 *********************************************************************************************************************/
/*! \brief       Handels the result of services called by the garbage collection unit
 *  \details     -
 *  \param[in]   result     Result of the called service
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_GarbageCollection_ResultHandler(Fee_30_FlexNor_ServiceResult result);

/**********************************************************************************************************************
 * Fee_30_FlexNor_GarbageCollection_ProcessingHandler()
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
FEE_30_FLEXNOR_LOCAL FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) 
    Fee_30_FlexNor_GarbageCollection_ProcessingHandler(void);

/**********************************************************************************************************************
 * Fee_30_FlexNor_GarbageCollection_GetTargetSector()
 *********************************************************************************************************************/
/*! \brief       Gets the target sector for the garbage collection based on the current state of logical sectors
 *  \details     The target sector is either the only remaining unused sector or in case all sectors are in use
 *               it is the one with the latest sector id.
 *  \param[in]   ctx    Pointer to the context containing the garbage collection information. Must not be NULL.
 *  \return      Pointer to the target sector for the garbage collection
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FEE_30_FLEXNOR_LOCAL FUNC(Fee_30_FlexNor_SectorPtrType, FEE_30_FLEXNOR_CODE) 
    Fee_30_FlexNor_GarbageCollection_GetTargetSector(Fee_30_FlexNor_GarbageCollection_ConstContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_GarbageCollection_GetPendingSourceSector()
 *********************************************************************************************************************/
/*! \brief       Gets a pointer to the source sector used in the currently pending garbage collection from the 
 *               target sectors header
 *  \details     -
 *  \param[in]   ctx    Pointer to the context containing the garbage collection information. Must not be NULL.
 *  \return      Pointer to the source sector in case the target sector header contained a valid sector id; otherwise 
 *               NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FEE_30_FLEXNOR_LOCAL FUNC(Fee_30_FlexNor_SectorPtrType, FEE_30_FLEXNOR_CODE) 
    Fee_30_FlexNor_GarbageCollection_GetPendingSourceSector(Fee_30_FlexNor_GarbageCollection_ConstContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_GarbageCollection_SelectNewSourceSector()
 *********************************************************************************************************************/
/*! \brief       Checks all used sectors to select a source sector for the garbage collection
 *  \details     Calculates a score for each sector in used and uses this score as selection metric to choose one as 
 *               source sector.
 *  \param[in]   ctx    Pointer to the context containing the garbage collection information. Must not be NULL.
 *  \return      Pointer to the selected source sector that is used for the garbage collection.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FEE_30_FLEXNOR_LOCAL FUNC(Fee_30_FlexNor_SectorPtrType, FEE_30_FLEXNOR_CODE) 
    Fee_30_FlexNor_GarbageCollection_SelectNewSourceSector(Fee_30_FlexNor_GarbageCollection_ConstContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_GarbageCollection_CalculateSectorScore()
 *********************************************************************************************************************/
/*! \brief       Calculates the total selection score based on the given base scores
 *  \details     -
 *  \param[in]   copyScore          Score that reflects the amount of data that needs to be copied for the sector.
 *  \param[in]   eraseCycleScore    Score that reflects the amount of erase cycles of the sector, relative to the other 
 *                                  sectors.
 *  \return      Calculated total sector score
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FEE_30_FLEXNOR_LOCAL FUNC(uint32, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_GarbageCollection_CalculateSectorScore(
    uint32 copyScore, 
    uint32 eraseCycleScore);

/**********************************************************************************************************************
 * Fee_30_FlexNor_GarbageCollection_CalculateCopyScore()
 *********************************************************************************************************************/
/*! \brief       Calculates the copy score for the given sector that reflects the amount of data that must be copied 
 *               in case the sector is garbage collected.
 *  \details     -
 *  \param[in]   ctx    Pointer to the context containing the garbage collection information. Must not be NULL.
 *  \param[in]   sector Pointer to the sector the score shall be calculated for. Must not be NULL.
 *  \return      Copy score for the sector between 0 and 1024.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FEE_30_FLEXNOR_LOCAL FUNC(uint32, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_GarbageCollection_CalculateCopyScore(
    Fee_30_FlexNor_GarbageCollection_ConstContextPtrType ctx, 
    Fee_30_FlexNor_ConstSectorPtrType sector);

/**********************************************************************************************************************
 * Fee_30_FlexNor_GarbageCollection_CalculateEraseCycleScore()
 *********************************************************************************************************************/
/*! \brief       Calculates the erase cycle score for the given sector that reflects the amount of erase cycles compared
 *               to the other sectors.
 *  \details     -
 *  \param[in]   ctx    Pointer to the context containing the garbage collection information. Must not be NULL.
 *  \param[in]   sector Pointer to the sector the score shall be calculated for. Must not be NULL.
 *  \return      Erase cycle score for the sector between 0 and 1024
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FEE_30_FLEXNOR_LOCAL FUNC(uint32, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_GarbageCollection_CalculateEraseCycleScore(
    Fee_30_FlexNor_GarbageCollection_ConstContextPtrType ctx, 
    Fee_30_FlexNor_ConstSectorPtrType sector);

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * Fee_30_FlexNor_GarbageCollection_ResultHandler()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_GarbageCollection_ResultHandler(Fee_30_FlexNor_ServiceResult result)
{
    if(result == FEE_30_FLEXNOR_SERVICE_FAIL)
    {
        Fee_30_FlexNor_GarbageCollectionStmContext.CurrentState->FailEvent(&Fee_30_FlexNor_GarbageCollectionStmContext); /* SBSW_Fee_30_FlexNor_TriggerEventAtState */
    }
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_GarbageCollection_ProcessingHandler()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FEE_30_FLEXNOR_LOCAL FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) 
    Fee_30_FlexNor_GarbageCollection_ProcessingHandler(void)
{
    return Fee_30_FlexNor_GarbageCollectionStmContext.CurrentState->ProcessEvent(
        &Fee_30_FlexNor_GarbageCollectionStmContext); /* SBSW_Fee_30_FlexNor_TriggerEventAtState */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_GarbageCollection_GetTargetSector()
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
 */
FEE_30_FLEXNOR_LOCAL FUNC(Fee_30_FlexNor_SectorPtrType, FEE_30_FLEXNOR_CODE) 
    Fee_30_FlexNor_GarbageCollection_GetTargetSector(Fee_30_FlexNor_GarbageCollection_ConstContextPtrType ctx)
{
    Fee_30_FlexNor_SectorPtrType currentSector = Fee_30_FlexNor_SectorContainer_GetFirst(
        ctx->PartitionConfig->PartitionId);
    Fee_30_FlexNor_SectorPtrType newestSector = currentSector;

    Fee_30_FlexNor_SectorPtrType availableSector = NULL_PTR;
    while(currentSector != NULL_PTR)
    {
        if(Fee_30_FlexNor_Sector_IsUsed(currentSector) == FALSE) /* SBSW_Fee_30_FlexNor_LoopStoredSectors */
        {
            availableSector = currentSector;
        }
        else if(Fee_30_FlexNor_SectorContainer_IsOlder(newestSector->SectorId, currentSector->SectorId) == TRUE)
        {
            newestSector = currentSector;
        }
        else 
        {
            /* Do nothing. */
        }

        currentSector = Fee_30_FlexNor_SectorContainer_GetNext(currentSector); /* SBSW_Fee_30_FlexNor_LoopStoredSectors */
    }

    Fee_30_FlexNor_SectorPtrType targetSector = NULL_PTR;
    if(availableSector == NULL_PTR)
    {
        targetSector = newestSector;
    }
    else
    {
        targetSector = availableSector;
        
        targetSector->SectorId = Fee_30_FlexNor_SectorContainer_GetNextSectorId(ctx->PartitionConfig->PartitionId); /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        targetSector->EraseCycle = Fee_30_FlexNor_SectorContainer_GetNextEraseCycle(targetSector); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */ /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    }

    return targetSector;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_GarbageCollection_GetPendingSourceSector()
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
FEE_30_FLEXNOR_LOCAL FUNC(Fee_30_FlexNor_SectorPtrType, FEE_30_FLEXNOR_CODE) 
    Fee_30_FlexNor_GarbageCollection_GetPendingSourceSector(Fee_30_FlexNor_GarbageCollection_ConstContextPtrType ctx)
{
    Fee_30_FlexNor_SectorPtrType pendingSectorPtr = NULL_PTR;

    Fee_30_FlexNor_SectorIdType pendingSectorId = ctx->TargetSector->SourceSectorId;
    Fee_30_FlexNor_SectorPtrType currentSector = Fee_30_FlexNor_SectorContainer_GetOldestValid(
        ctx->PartitionConfig->PartitionId);

    while(currentSector !=  NULL_PTR)
    {
        if(currentSector->SectorId == pendingSectorId)
        {
            pendingSectorPtr = currentSector;
        }

        currentSector = Fee_30_FlexNor_SectorContainer_GetNextNewerValid(currentSector); /* SBSW_Fee_30_FlexNor_LoopStoredSectors */
    }

    return pendingSectorPtr;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_GarbageCollection_SelectNewSourceSector()
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
FEE_30_FLEXNOR_LOCAL FUNC(Fee_30_FlexNor_SectorPtrType, FEE_30_FLEXNOR_CODE) 
    Fee_30_FlexNor_GarbageCollection_SelectNewSourceSector(Fee_30_FlexNor_GarbageCollection_ConstContextPtrType ctx)
{
    Fee_30_FlexNor_SectorPtrType sourceSector = NULL_PTR;

    uint8 idSpan = Fee_30_FlexNor_SectorContainer_GetSectorIdSpan(ctx->PartitionConfig->PartitionId);

    if(idSpan >= FEE_30_FLEXNOR_MAX_ID_SPAN)
    {
        sourceSector = Fee_30_FlexNor_SectorContainer_GetOldestValid(ctx->PartitionConfig->PartitionId);
    }
    else
    {
        uint32 currentScore = 0u;
        uint32 minScore = FEE_30_FLEXNOR_UINT32_MAX;
        Fee_30_FlexNor_SectorPtrType currentSector = Fee_30_FlexNor_SectorContainer_GetOldestValid(
            ctx->PartitionConfig->PartitionId);

        while(currentSector != NULL_PTR)
        {
            if(currentSector != ctx->TargetSector)
            {
                uint32 copyScore = Fee_30_FlexNor_GarbageCollection_CalculateCopyScore(ctx, currentSector); /* SBSW_Fee_30_FlexNor_LoopStoredSectors */
                uint32 eraseCycleScore = Fee_30_FlexNor_GarbageCollection_CalculateEraseCycleScore(ctx, currentSector); /* SBSW_Fee_30_FlexNor_LoopStoredSectors */

                currentScore = Fee_30_FlexNor_GarbageCollection_CalculateSectorScore(copyScore, eraseCycleScore);

                if(currentScore < minScore)
                {
                    sourceSector = currentSector;
                    minScore = currentScore;
                }
            }

            currentSector = Fee_30_FlexNor_SectorContainer_GetNextNewerValid(currentSector); /* SBSW_Fee_30_FlexNor_LoopStoredSectors */
        }
    }

    return sourceSector;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_GarbageCollection_CalculateSectorScore()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FEE_30_FLEXNOR_LOCAL FUNC(uint32, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_GarbageCollection_CalculateSectorScore(
    uint32 copyScore, 
    uint32 eraseCycleScore)
{
    /* The values are scaled up to not lose precision when weighting the two scores. */
    uint32 scaledCopyScore = copyScore * FEE_30_FLEXNOR_SCALER;
    uint32 scalederaseCycleScore = eraseCycleScore * FEE_30_FLEXNOR_SCALER;

    /* The two parts of the score are weighted to balance the copy effort and the erase cycle distribution. */
    uint32 totalScore = (uint32)
        (scaledCopyScore / FEE_30_FLEXNOR_MAX_WEIGHT * FEE_30_FLEXNOR_SCORE_WEIGHT) + 
        (scalederaseCycleScore / FEE_30_FLEXNOR_MAX_WEIGHT * (FEE_30_FLEXNOR_MAX_WEIGHT - FEE_30_FLEXNOR_SCORE_WEIGHT));

    totalScore /= FEE_30_FLEXNOR_SCALER;
    
    return totalScore;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_GarbageCollection_CalculateCopyScore()
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
FEE_30_FLEXNOR_LOCAL FUNC(uint32, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_GarbageCollection_CalculateCopyScore(
    Fee_30_FlexNor_GarbageCollection_ConstContextPtrType ctx, 
    Fee_30_FlexNor_ConstSectorPtrType sector)
{
    uint32 bytesToCopy = 0u;
    Fee_30_FlexNor_ConstPartitionConfigPtrType partitionConfig = Fee_30_FlexNor_ConfigInterface_GetPartitionConfig(
        ctx->PartitionConfig->PartitionId);
    uint32 totalPayload = partitionConfig->TotalConfiguredPayloadSize;

    for(uint32 blockIndex = 0; blockIndex < partitionConfig->BlockCount; blockIndex++)
    {
        Fee_30_FlexNor_ConstBlockConfigPtrType currentBlockConfig = &partitionConfig->Blocks[blockIndex];
    
        Fee_30_FlexNor_LookupTable_LinkType link = Fee_30_FlexNor_LookupTable_GetLink(
                                                                ctx->PartitionConfig->PartitionId,
                                                                currentBlockConfig->Id);

        /* In case of a configuration update or in bootloader mode, their might be no block config to get the length 
           from. There is also no other option to extract the length. Hence, we skip these blocks for the copy score. */
        if( link.SectorId == sector->SectorId)
        {
            bytesToCopy += currentBlockConfig->Length;
        }
    }

    uint32 copyScore = (bytesToCopy * FEE_30_FLEXNOR_MAX_SCORE) / totalPayload;

    return copyScore;
}


/**********************************************************************************************************************
 * Fee_30_FlexNor_GarbageCollection_CalculateEraseCycleScore()
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
FEE_30_FLEXNOR_LOCAL FUNC(uint32, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_GarbageCollection_CalculateEraseCycleScore(
    Fee_30_FlexNor_GarbageCollection_ConstContextPtrType ctx, 
    Fee_30_FlexNor_ConstSectorPtrType sector)
{
    uint32 maxEcc = 0u;
    uint32 minEcc = FEE_30_FLEXNOR_UINT32_MAX;
    Fee_30_FlexNor_SectorPtrType currentSector = Fee_30_FlexNor_SectorContainer_GetOldestValid(
        ctx->PartitionConfig->PartitionId);

    while(currentSector != NULL_PTR)
    {
        if (currentSector->EraseCycle < minEcc)
        {
            minEcc = currentSector->EraseCycle;
        }

        if (currentSector->EraseCycle > maxEcc)
        {
            maxEcc = currentSector->EraseCycle;
        }

        currentSector = Fee_30_FlexNor_SectorContainer_GetNextNewerValid(currentSector); /* SBSW_Fee_30_FlexNor_LoopStoredSectors */
    }

    uint32 eccRange = ((maxEcc - minEcc) > 0u) ? (maxEcc - minEcc) : 1u;
    uint32 eraseCycleScore = ((sector->EraseCycle - minEcc) * FEE_30_FLEXNOR_MAX_SCORE) / (eccRange);

    return eraseCycleScore;
}

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * Fee_30_FlexNor_GarbageCollection_Init()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_GarbageCollection_Init(void)
{
    Fee_30_FlexNor_GarbageCollection_InitState(&Fee_30_FlexNor_GarbageCollectionStmContext); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_GarbageCollection_StartJob()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_GarbageCollection_StartJob(void)
{
    Fee_30_FlexNor_Scheduler_RegisterUnit(&Fee_30_FlexNor_GarbageCollection_ProcessingHandler); /* SBSW_Fee_30_FlexNor_RegisterUnit */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_GarbageCollection_EndJob()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_GarbageCollection_EndJob(void)
{
    Fee_30_FlexNor_Scheduler_UnregisterUnit();
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_GarbageCollection_IsPending()
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
FUNC(boolean, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_GarbageCollection_IsPending(
    Fee_30_FlexNor_PartitionIdType partitionId)
{
    boolean garbageCollectionPending = FALSE;
    uint8 availableSectorCount = 0u;
    Fee_30_FlexNor_ConstSectorPtrType storedSector = Fee_30_FlexNor_SectorContainer_GetFirst(partitionId);

    while(storedSector != NULL_PTR)
    {
        if(storedSector->Validity != FEE_30_FLEXNOR_VALID)
        {
            availableSectorCount++;
        }

        storedSector = Fee_30_FlexNor_SectorContainer_GetNext(storedSector); /* SBSW_Fee_30_FlexNor_LoopStoredSectors */
    }

    if(availableSectorCount == 0u)
    {
        garbageCollectionPending = TRUE;
    }
    
    return garbageCollectionPending;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_GarbageCollection_Run()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_GarbageCollection_Run(
    Fee_30_FlexNor_PartitionIdType partitionId, 
    Fee_30_FlexNor_SectorPtrType sourceSector, 
    boolean isPersistLutJobRunning,
    Fee_30_FlexNor_ResultCallback resultCbk)
{
    Fee_30_FlexNor_GarbageCollectionStmContext.PartitionConfig = Fee_30_FlexNor_ConfigInterface_GetPartitionConfig(
        partitionId);
    Fee_30_FlexNor_GarbageCollectionStmContext.SourceSector = sourceSector;
    Fee_30_FlexNor_GarbageCollectionStmContext.IsPersistLutJobRunning = isPersistLutJobRunning;
    Fee_30_FlexNor_GarbageCollectionStmContext.ResultCallback = resultCbk;

    Fee_30_FlexNor_GarbageCollectionStmContext.RetryCounter = 0u;
    Fee_30_FlexNor_GarbageCollectionStmContext.BlockToCopy.BlockId = FEE_30_FLEXNOR_INITIAL_VALUE_BLOCK_ID_COPY_BLOCKS;

    Fee_30_FlexNor_GarbageCollection_Run_Initialize(&Fee_30_FlexNor_GarbageCollectionStmContext); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_GarbageCollection_TriggerLookupTableRecoveryIfInvalid()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(boolean, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_GarbageCollection_TriggerLookupTableRecoveryIfInvalid(
    Fee_30_FlexNor_GarbageCollection_ConstContextPtrType ctx)
{
    boolean lutRecoveryStarted = FALSE;

    if(Fee_30_FlexNor_LookupTable_IsValid(ctx->PartitionConfig->PartitionId) == FALSE)
    {
        Fee_30_FlexNor_LookupTable_FullRecovery(ctx->PartitionConfig->PartitionId, 
            &Fee_30_FlexNor_GarbageCollection_ResultHandler); /* SBSW_Fee_30_FlexNor_ResultHandler */
        lutRecoveryStarted = TRUE;
    }

    return lutRecoveryStarted;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_GarbageCollection_InitializeGarbageCollectionMode()
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
FUNC(Fee_30_FlexNor_GarbageCollectionModeType, FEE_30_FLEXNOR_CODE) 
Fee_30_FlexNor_GarbageCollection_InitializeGarbageCollectionMode(Fee_30_FlexNor_GarbageCollection_ContextPtrType ctx)
{
    ctx->TargetSector = Fee_30_FlexNor_GarbageCollection_GetTargetSector(ctx); /* SBSW_Fee_30_FlexNor_ContextPointerAccess */ /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
    ctx->TargetSector->GcReason = FEE_30_FLEXNOR_GC_REASON_SPACE; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    ctx->TargetSector->Layout = ctx->PartitionConfig->Layout; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    ctx->TargetSector->LutChunkLink.Target = 0x0u; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    ctx->TargetSector->LutChunkLink.Validity = FEE_30_FLEXNOR_EMPTY; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */

    Fee_30_FlexNor_GarbageCollectionModeType gcMode = FEE_30_FLEXNOR_GARBAGECOLLECTION_NEW;

    if(ctx->SourceSector != NULL_PTR)
    {
        ctx->TargetSector->GcReason = FEE_30_FLEXNOR_GC_REASON_RECOVERY; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        gcMode = FEE_30_FLEXNOR_GARBAGECOLLECTION_NEW;
    }
    else 
    {
        if(Fee_30_FlexNor_GarbageCollection_IsPending(ctx->PartitionConfig->PartitionId) == TRUE)
        {
            Fee_30_FlexNor_SectorPtrType previousSourceSector 
                = Fee_30_FlexNor_GarbageCollection_GetPendingSourceSector(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

            if((previousSourceSector != NULL_PTR) 
                && (previousSourceSector->SectorId != ctx->TargetSector->SectorId)
                && (ctx->TargetSector->SelectedForRecoveryGarbageCollection == FALSE))
            {
                ctx->SourceSector = previousSourceSector; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */ /* PRQA S 2916 */ /* MD_Fee_30_FlexNor_GreaterPointerLifetime */
                gcMode = FEE_30_FLEXNOR_GARBAGECOLLECTION_CONTINUE;
            }
            else
            {
                /*
                 * In case the stored source sector id in the target sector was invalid due to an interruption, 
                 * the old garbage collection is dismissed and a new one is started. 
                 */
                ctx->SourceSector = Fee_30_FlexNor_GarbageCollection_SelectNewSourceSector(ctx); /* SBSW_Fee_30_FlexNor_ContextPointerAccess */ /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
                Fee_30_FlexNor_LookupTable_Invalidate(ctx->PartitionConfig->PartitionId);
                gcMode = FEE_30_FLEXNOR_GARBAGECOLLECTION_NEW;
            }
        }
        else 
        {
            ctx->SourceSector = Fee_30_FlexNor_GarbageCollection_SelectNewSourceSector(ctx); /* SBSW_Fee_30_FlexNor_ContextPointerAccess */ /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
            gcMode = FEE_30_FLEXNOR_GARBAGECOLLECTION_NEW;
        }
    }

    return gcMode;

}

/**********************************************************************************************************************
 * Fee_30_FlexNor_GarbageCollection_GetNextBlockToCopy()
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
 */
FUNC(boolean, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_GarbageCollection_GetNextBlockToCopy(
    Fee_30_FlexNor_GarbageCollection_ContextPtrType ctx)
{
    boolean blockToCopyFound = FALSE;
    boolean isBootloaderModeEnabled = Fee_30_FlexNor_ConfigInterface_IsBootloaderModeEnabled();

    for(uint16 lIndex = (ctx->BlockToCopy.BlockId + 1u); lIndex < ctx->PartitionConfig->LookupTableSize; lIndex++)
    {
        /* The lookup table index is equal to the block id by definition */
        Fee_30_FlexNor_LookupTable_LinkType link = Fee_30_FlexNor_LookupTable_GetLink(
            ctx->PartitionConfig->PartitionId,
            lIndex);

        if(link.SectorId == ctx->SourceSector->SectorId)
        {
            Fee_30_FlexNor_ConstBlockConfigPtrType blockConfig = Fee_30_FlexNor_ConfigInterface_GetBlockConfigById(
                ctx->PartitionConfig->PartitionId, lIndex);

            if ((blockConfig != NULL_PTR) || (isBootloaderModeEnabled == TRUE))
            {
                ctx->BlockToCopy.BlockId = lIndex; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
                ctx->BlockToCopy.ChunkOffset = link.ChunkOffset; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
                blockToCopyFound = TRUE;
                break;
            }
        }
    }

    return blockToCopyFound;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_GarbageCollection_TriggerCopyBlock()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE)  Fee_30_FlexNor_GarbageCollection_TriggerCopyBlock(
    Fee_30_FlexNor_GarbageCollection_ConstContextPtrType ctx)
{
    Fee_30_FlexNor_CopyBlock_Copy(ctx->PartitionConfig->PartitionId,
                                  ctx->BlockToCopy.BlockId,
                                  ctx->SourceSector,
                                  ctx->TargetSector,
                                  ctx->BlockToCopy.ChunkOffset, 
                                  TRUE,
                                  &Fee_30_FlexNor_GarbageCollection_ResultHandler); /* SBSW_Fee_30_FlexNor_ResultHandler */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_GarbageCollection_TriggerSectorAllocation()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_GarbageCollection_TriggerSectorAllocation(
    Fee_30_FlexNor_GarbageCollection_ConstContextPtrType ctx)
{
    Fee_30_FlexNor_Sector_Allocate(ctx->TargetSector, &Fee_30_FlexNor_GarbageCollection_ResultHandler); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_GarbageCollection_StoreSourceSector()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_GarbageCollection_StoreSourceSector(
    Fee_30_FlexNor_GarbageCollection_ConstContextPtrType ctx)
{
    Fee_30_FlexNor_Sector_WriteSourceSector(ctx->TargetSector, ctx->SourceSector->SectorId, 
        &Fee_30_FlexNor_GarbageCollection_ResultHandler); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_GarbageCollection_MarkForErase()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_GarbageCollection_MarkForErase(
    Fee_30_FlexNor_GarbageCollection_ConstContextPtrType ctx)
{
    Fee_30_FlexNor_Sector_WriteEraseMarker(ctx->SourceSector, &Fee_30_FlexNor_GarbageCollection_ResultHandler); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_GarbageCollection_PrepareRestart()
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
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_GarbageCollection_PrepareRestart(
    Fee_30_FlexNor_GarbageCollection_ContextPtrType ctx)
{
    Fee_30_FlexNor_LookupTable_Invalidate(ctx->PartitionConfig->PartitionId);
    ctx->BlockToCopy.BlockId = FEE_30_FLEXNOR_INITIAL_VALUE_BLOCK_ID_COPY_BLOCKS; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */

    if(ctx->TargetSector->GcReason == FEE_30_FLEXNOR_GC_REASON_SPACE)
    {
        ctx->SourceSector = NULL_PTR; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    }
}

#define FEE_30_FLEXNOR_STOP_SEC_CODE
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: Fee_30_FlexNor_GarbageCollection.c
 *********************************************************************************************************************/
