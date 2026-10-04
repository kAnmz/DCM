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
/*!        \file  Fee_30_FlexNor_LookupTable.c
 *        \brief  Lookup table implementation
 *      \details  Provides the business logic for the lookup table services.
 *         \unit  LookupTable
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#define FEE_30_FLEXNOR_LOOKUPTABLE_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Fee_30_FlexNor_LookupTable.h"
#include "Fee_30_FlexNor_LookupTableInternal.h"
#include "Fee_30_FlexNor_LookupTableMachine.h"

#include "Fee_30_FlexNor_Scheduler.h"
#include "Fee_30_FlexNor_ChunkSearch.h"
#include "Fee_30_FlexNor_SectorContainer.h"
#include "Fee_30_FlexNor_Partition.h"
#include "Fee_30_FlexNor_ChunkFactory.h"
#include "Fee_30_FlexNor_InstanceFactory.h"

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
#define FEE_30_FLEXNOR_LOOKUPTABLE_OFFSET_MASK (0xFFFFFFu)            /*!< The first byte will be used for the sector id 
                                                                           for the offset we need the following 3 bytes. 
                                                                           */
#define FEE_30_FLEXNOR_LOOKUPTABLE_LINK_DEFAULT_VALUE (0x0u)          /*!< The default value for a lookup table link. */
#define FEE_30_FLEXNOR_LOOKUPTABLE_MAX_NUMBER_OF_CHUNKS_TO_SCAN (50u) /*!< Maximum number of chunks which which must be 
                                                                           read during a partial sector scan. */
#define FEE_30_FLEXNOR_LOOKUPTABLE_VERSION (2u)                       /*!< Version of the persisted lookup table. */
#define FEE_30_FLEXNOR_LOOKUPTABLE_MAX_LUTLINK_ID_SPAN (63u)          /*!< Maximum allowed sector id span between LUT 
                                                                           entries and newest valid sector before a full 
                                                                           LUT recovery is triggered */

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/
#if !defined (FEE_30_FLEXNOR_LOCAL) /* COV_FEE_30_FLEXNOR_COMPATIBILITY */
# define FEE_30_FLEXNOR_LOCAL static
#endif

#if !defined (FEE_30_FLEXNOR_LOCAL_INLINE) /* COV_FEE_30_FLEXNOR_COMPATIBILITY */
# define FEE_30_FLEXNOR_LOCAL_INLINE LOCAL_INLINE
#endif

/* Sets the k bit in the given array A */
#define SetBit(A, k) (A[(k/8u)] |= (1u << (k%8u))) 

/* Clears the k bit in the given array A */
#define ClearBit(A, k) (A[(k/8u)] &= ~(1u << (k%8u))) 

/* Tests the k bit in the given array A */
#define TestBit(A, k) ((A[(k/8u)] & (1u << (k%8u))) >> (k%8u))


/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef struct 
{
    uint16 NumberOfNewChunks;  /*!< Counter for the number of chunks which were allocated after the last LUT 
                                    persistence. */
    boolean PersistLutRequested; /*!< Flag which is set in case the persist LUT job was requested explicitly. */
} Fee_30_FlexNor_LookupTablePersistDataType;  /*!< Stores all data for the automatic triggering of persist LUT. */

typedef P2VAR(Fee_30_FlexNor_LookupTablePersistDataType, AUTOMATIC, FEE_30_FLEXNOR_VAR) 
    Fee_30_FlexNor_LookupTablePersistDataPtrType;
typedef P2CONST(Fee_30_FlexNor_LookupTablePersistDataType, AUTOMATIC, FEE_30_FLEXNOR_VAR) 
    Fee_30_FlexNor_ConstLookupTablePersistDataPtrType;

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/
#define FEE_30_FLEXNOR_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Context variable of the lookup table state machine. */
FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_LookupTable_ContextType Fee_30_FlexNor_LookupTableStmContext = { 0u }; /* PRQA S 3218 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */

FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_LookupTablePersistDataType 
    Fee_30_FlexNor_LookupTablePersistData[FEE_30_FLEXNOR_CONFIGURED_PARTITIONS] = { 0u }; /* PRQA S 3218 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */

FEE_30_FLEXNOR_LOCAL boolean Fee_30_FlexNor_LookupTableValidity[FEE_30_FLEXNOR_CONFIGURED_PARTITIONS] = { 0u }; /* PRQA S 3218 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */

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
 * Fee_30_FlexNor_LookupTable_ProcessingHandler()
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
    Fee_30_FlexNor_LookupTable_ProcessingHandler(void);

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_ToLookupTableLink()
 *********************************************************************************************************************/
/*! \brief       Converts the given chunk location to a lookup table link.
 *  \details     -
 *  \param[in]   chunkLocation  Chunk location that shall be converted
 *  \return      The converted lookup table link
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FEE_30_FLEXNOR_LOCAL FUNC(Fee_30_FlexNor_LookupTable_LinkType, FEE_30_FLEXNOR_CODE) 
    Fee_30_FlexNor_LookupTable_ToLookupTableLink(Fee_30_FlexNor_ChunkLocationType chunkLocation);

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_ToChunkLocation()
 *********************************************************************************************************************/
/*! \brief       Converts a given lookup table link to a chunk location
 *  \details     -
 *  \param[in]   link   Given link that shall be converted
 *  \return      The converted chunk location
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FEE_30_FLEXNOR_LOCAL FUNC(Fee_30_FlexNor_ChunkLocationType, FEE_30_FLEXNOR_CODE) 
    Fee_30_FlexNor_LookupTable_ToChunkLocation(Fee_30_FlexNor_LookupTable_LinkType link);

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_GetSectorOfLatestLutBlock
 *********************************************************************************************************************/
/*! \brief       Returns a pointer to the sector object the latest lut block was written
 *  \details     -
 *  \param[in]   partitionConfig Partition the lut block belongs to.
 *  \return      Pointer to the sector. Never NULL.
 *  \pre         Lut block was written before.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FEE_30_FLEXNOR_LOCAL FUNC(Fee_30_FlexNor_SectorPtrType, FEE_30_FLEXNOR_CODE) 
    Fee_30_FlexNor_LookupTable_GetSectorOfLatestLutBlock(Fee_30_FlexNor_ConstPartitionConfigPtrType partitionConfig);

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_CreateLutJob
 *********************************************************************************************************************/
/*! \brief       Sets the relevant parameters in the job object that are necessary for loading and persisting the lut
 *  \details     -
 *  \param[in,out]  ctx     Pointer to the context for the state machine processing. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FEE_30_FLEXNOR_LOCAL FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_CreateLutJob(
    Fee_30_FlexNor_LookupTable_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_SetVersionInFirstLutEntry
 *********************************************************************************************************************/
/*! \brief       Sets the version number into the first entry of the given lookup table. 
 *  \details     -
 *  \param[out]  lookupTable     Pointer to the lookup table where the version shall be set.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FEE_30_FLEXNOR_LOCAL FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_SetVersionInFirstLutEntry(
    Fee_30_FlexNor_ChunkLocationPtrType lookupTable);

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_LutChunkSearchResultHandler()
 *********************************************************************************************************************/
/*! \brief       Handles the result of a called chunk search service
 *  \details     This function is used as a result callback for chunk search services called by this unit.
 *               Chunk search result handling requires a different implementation than the generic result handler.
 *  \param[in]   result               Result of the called service
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_LutChunkSearchResultHandler(
    Fee_30_FlexNor_ServiceResult result);

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_GetSectorWithLatestLutLink()
 *********************************************************************************************************************/
/*! \brief       Gets the sector with the most recent LUT link 
 *  \details     -
 *  \param[in]   partitionId    Id of the partition
 *  \return      Pointer to the sector. NULL, if no sector is found.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_SectorPtrType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_GetSectorWithLatestLutLink(
    Fee_30_FlexNor_PartitionIdType partitionId);

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_GetLatestKnownChunkInSector()
 *********************************************************************************************************************/
/*! \brief       Calculates the address of the latest chunk in the sector with the given id.
 *  \details     -
 *  \param[in]   partitionId         Id of the partition which contains the sector of whom the latest known chunk shall 
 *                                   be obtained.
 *  \param[in]   sectorId            Id of the sector of whom the latest known chunk shall be obtained.
 *  \return                          If the sector contains known chunks, link to the latest known chunk. 
 *                                   Otherwise an invalid link. 
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_LookupTable_LinkType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_GetLatestKnownChunkInSector(
    Fee_30_FlexNor_PartitionIdType partitionId, Fee_30_FlexNor_SectorIdType sectorId);

#if (FEE_30_FLEXNOR_LOOKUPTABLE_COMPATIBILITY_MODE == STD_OFF)
/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_DoesLookupTableLinkToANewerSector()
 *********************************************************************************************************************/
/*! \brief       Checks if any link in the lookup table points to a sector which is newer than the given sector. 
 *  \details     -
 *  \param[in]   sector         Comparison sector for stored LUT links.
 *  \return                     TRUE:  The lookup table contains a link to a newer sector. 
 *                              FALSE: The lookup table does not contain a link to a newer sector. 
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(boolean, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_DoesLookupTableLinkToANewerSector(
    Fee_30_FlexNor_ConstSectorPtrType sector);
#endif

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_InvalidateNewChunkCounter
 *********************************************************************************************************************/
/*! \brief          Invalidates the counter for new chunks.
 *  \details        -
 *  \param[in]      partitionId     Id of the partition for which the persist Lut request shall be reset
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_InvalidateNewChunkCounter(
    Fee_30_FlexNor_PartitionIdType partitionId);

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_IsLoadedLutCompatibleWithFlashSectors()
 *********************************************************************************************************************/
/*! \brief       Indicates whether the discrepancy between the flash sectors and the stored sectors in the LUT is
                 acceptable.
 *  \details     If the LUT is not persisted for a certain period the difference between the Id of the latest flash
 *               sector, which the Fee uses for writing chunks, and a sector Id stored in the LUT can be very large so
 *               that the outdated LUT link can appear newer due to the sector Id wrap around.
 *               Hence, before the Id span between the newest valid sector and any valid LUT link exceeds some limit a
 *               full LUT recovery shall be done.
 *  \param[in]   partitionId               Id of the partition the lookup table compatibility shall be checked.
 *  \return      TRUE       LUT sector Ids are close to flash sector Ids.
 *               FALSE      Full LUT recovery shall be done.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(boolean, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_IsLoadedLutCompatibleWithFlashSectors(
    Fee_30_FlexNor_PartitionIdType partitionId);

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_ProcessingHandler()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FEE_30_FLEXNOR_LOCAL FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) 
    Fee_30_FlexNor_LookupTable_ProcessingHandler(void)
{
    return Fee_30_FlexNor_LookupTableStmContext.CurrentState->ProcessEvent(&Fee_30_FlexNor_LookupTableStmContext); /* SBSW_Fee_30_FlexNor_TriggerEventAtState */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_ResultHandler()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_ResultHandler(Fee_30_FlexNor_ServiceResult result)
{
    if(result == FEE_30_FLEXNOR_SERVICE_FAIL)
    {
        Fee_30_FlexNor_LookupTableStmContext.CurrentState->FailEvent(&Fee_30_FlexNor_LookupTableStmContext); /* SBSW_Fee_30_FlexNor_TriggerEventAtState */
    }
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_ToLookupTableLink()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FEE_30_FLEXNOR_LOCAL FUNC(Fee_30_FlexNor_LookupTable_LinkType, FEE_30_FLEXNOR_CODE) 
    Fee_30_FlexNor_LookupTable_ToLookupTableLink(Fee_30_FlexNor_ChunkLocationType chunkLocation)
{
    Fee_30_FlexNor_LookupTable_LinkType link;
    link.SectorId = (Fee_30_FlexNor_SectorIdType)(chunkLocation >> 24u);
    link.ChunkOffset = (Fee_30_FlexNor_PagebasedOffsetType)(chunkLocation & FEE_30_FLEXNOR_LOOKUPTABLE_OFFSET_MASK);
    return link;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_ToChunkLocation()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FEE_30_FLEXNOR_LOCAL FUNC(Fee_30_FlexNor_ChunkLocationType, FEE_30_FLEXNOR_CODE) 
    Fee_30_FlexNor_LookupTable_ToChunkLocation(Fee_30_FlexNor_LookupTable_LinkType link)
{
    Fee_30_FlexNor_ChunkLocationType chunkLocation = (((Fee_30_FlexNor_ChunkLocationType)link.SectorId) << 24u);
    chunkLocation |= (link.ChunkOffset & FEE_30_FLEXNOR_LOOKUPTABLE_OFFSET_MASK);
    return chunkLocation;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_GetSectorOfLatestLutBlock
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FEE_30_FLEXNOR_LOCAL FUNC(Fee_30_FlexNor_SectorPtrType, FEE_30_FLEXNOR_CODE) 
    Fee_30_FlexNor_LookupTable_GetSectorOfLatestLutBlock(Fee_30_FlexNor_ConstPartitionConfigPtrType partitionConfig)
{
    Fee_30_FlexNor_LookupTable_LinkType lutEntry = Fee_30_FlexNor_LookupTable_GetLink(partitionConfig->PartitionId, 
        FEE_30_FLEXNOR_LUTBLOCKID);

    /* Here it is assured that there is a lut entry, because the precondition of this function states that the lut block has been written. */
    return Fee_30_FlexNor_SectorContainer_Get(partitionConfig->PartitionId, lutEntry.SectorId, FALSE);
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_CreateLutJob
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FEE_30_FLEXNOR_LOCAL FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_CreateLutJob(
    Fee_30_FlexNor_LookupTable_ContextPtrType ctx)
{
    /* The service id does not matter here. We can use it for write and for read...*/
    ctx->LutJob.Service = FEE_30_FLEXNOR_SID_WRITE; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    ctx->LutJob.BlockId = FEE_30_FLEXNOR_LUTBLOCKID; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    ctx->LutJob.PartitionId = ctx->PartitionConfig->PartitionId; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    ctx->LutJob.WriteBuffer = (Fee_30_FlexNor_ConstDataPtrType)ctx->PartitionConfig->LookupTable; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    ctx->LutJob.ReadBuffer = (Fee_30_FlexNor_DataPtrType)ctx->PartitionConfig->LookupTable; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    ctx->LutJob.Length = sizeof(*ctx->PartitionConfig->LookupTable) * ctx->PartitionConfig->LookupTableSize; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    ctx->LutJob.Offset = 0u; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_SetVersionInFirstLutEntry
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FEE_30_FLEXNOR_LOCAL FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_SetVersionInFirstLutEntry(
    Fee_30_FlexNor_ChunkLocationPtrType lookupTable)
{
    lookupTable[0u] = FEE_30_FLEXNOR_LOOKUPTABLE_VERSION; /* SBSW_Fee_30_FlexNor_LookupTableVersion */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_LutChunkSearchResultHandler()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_LutChunkSearchResultHandler(
    Fee_30_FlexNor_ServiceResult result)
{
    if(result == FEE_30_FLEXNOR_SERVICE_OK)
    {
        Fee_30_FlexNor_LookupTableStmContext.LutChunkSearchSucceeded = TRUE;
    }
    else
    {
        Fee_30_FlexNor_LookupTableStmContext.LutChunkSearchSucceeded = FALSE;
    }
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_GetSectorWithLatestLutLink
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_SectorPtrType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_GetSectorWithLatestLutLink(
    Fee_30_FlexNor_PartitionIdType partitionId)
{
    Fee_30_FlexNor_SectorPtrType matchingSector = NULL_PTR;
    Fee_30_FlexNor_SectorPtrType currentSector = Fee_30_FlexNor_SectorContainer_GetOldestValid(partitionId);

    while(currentSector != NULL_PTR)
    {
        if(currentSector->LutChunkLink.Validity == FEE_30_FLEXNOR_VALID)
        {
            matchingSector = currentSector;
        }
        currentSector = Fee_30_FlexNor_SectorContainer_GetNextNewerValid(currentSector); /* SBSW_Fee_30_FlexNor_LoopStoredSectors */
    }

    return matchingSector;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_GetLatestKnownChunkInSector()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_LookupTable_LinkType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_GetLatestKnownChunkInSector(
    Fee_30_FlexNor_PartitionIdType partitionId, Fee_30_FlexNor_SectorIdType sectorId)
{
    Fee_30_FlexNor_ConstPartitionConfigPtrType partitionConfig 
        = Fee_30_FlexNor_ConfigInterface_GetPartitionConfig(partitionId);

    Fee_30_FlexNor_LookupTable_LinkType linkToLatestChunk;
    linkToLatestChunk.SectorId = 0u;
    linkToLatestChunk.ChunkOffset = 0u;

    for(uint32 lutIndex = 1u; lutIndex < partitionConfig->LookupTableSize; lutIndex++)
    {
        Fee_30_FlexNor_ChunkLocationType chunkLocation = partitionConfig->LookupTable[lutIndex];

        Fee_30_FlexNor_LookupTable_LinkType currentLink = Fee_30_FlexNor_LookupTable_ToLookupTableLink(chunkLocation);

        if ((currentLink.SectorId == sectorId)
            && (currentLink.ChunkOffset > linkToLatestChunk.ChunkOffset))
        {
            linkToLatestChunk = currentLink;   
        }
    }

    return linkToLatestChunk;
}

#if (FEE_30_FLEXNOR_LOOKUPTABLE_COMPATIBILITY_MODE == STD_OFF)
/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_DoesLookupTableLinkToANewerSector()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(boolean, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_DoesLookupTableLinkToANewerSector(
    Fee_30_FlexNor_ConstSectorPtrType sector)
{
    boolean doesNewerSectorExist = FALSE;
    Fee_30_FlexNor_ConstPartitionConfigPtrType partitionConfig 
        = Fee_30_FlexNor_ConfigInterface_GetPartitionConfig(sector->PartitionId);

    
    /* The lutIndex excludes the LUT block by starting from 2u, because in a previous version the Fee copied the LUT 
     * block in a GC. This lead to the case that during the finish GC job the link to the newest LUT chunk pointed 
     * already into the newest (target) sector after the LUT loading has finished. The partial LUT recovery does not 
     * scan any older sector. So the previously latest sector is not scanned anymore and some blocks in it can be lost. 
     * It is technically correct to start with 1u here, but 2u is the more defensive value. */
    for(uint32 lutIndex = 2u; lutIndex < partitionConfig->LookupTableSize; lutIndex++)
    {
        Fee_30_FlexNor_ChunkLocationType chunkLocation = partitionConfig->LookupTable[lutIndex];
        Fee_30_FlexNor_LookupTable_LinkType currentLink = Fee_30_FlexNor_LookupTable_ToLookupTableLink(chunkLocation);
        if (currentLink.SectorId == FEE_30_FLEXNOR_LOOKUPTABLE_LINK_DEFAULT_VALUE)
        {
            continue;
        }
        if (Fee_30_FlexNor_SectorContainer_IsOlder(sector->SectorId, currentLink.SectorId))
        {
            doesNewerSectorExist = TRUE;   
            break;
        }
    }

    return doesNewerSectorExist;
}
#endif

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_InvalidateNewChunkCounter
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_InvalidateNewChunkCounter(
    Fee_30_FlexNor_PartitionIdType partitionId)
{
    Fee_30_FlexNor_LookupTablePersistData[partitionId].NumberOfNewChunks
        = FEE_30_FLEXNOR_LOOKUPTABLE_NEWCHUNKCOUNTINVALID;  /* SBSW_Fee_30_FlexNor_LookupTablePersistData */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_IsLoadedLutCompatibleWithFlashSectors()
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
FUNC(boolean, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_IsLoadedLutCompatibleWithFlashSectors(
    Fee_30_FlexNor_PartitionIdType partitionId)
{
    boolean isCompatible = TRUE;

    Fee_30_FlexNor_ConstPartitionConfigPtrType partitionConfig
        = Fee_30_FlexNor_ConfigInterface_GetPartitionConfig(partitionId);

    Fee_30_FlexNor_ConstSectorPtrType newestSector 
        = Fee_30_FlexNor_SectorContainer_GetNewestValid(partitionConfig->PartitionId);
    
    if (newestSector != NULL_PTR)
    {
        for(uint16 lutIndex = 0u; lutIndex < partitionConfig->LookupTableSize; lutIndex++)
        {
            Fee_30_FlexNor_LookupTable_LinkType currentLink 
                = Fee_30_FlexNor_LookupTable_GetLink(partitionConfig->PartitionId, lutIndex);
            if (currentLink.SectorId == FEE_30_FLEXNOR_LOOKUPTABLE_LINK_DEFAULT_VALUE)
            {
                continue;
            }

            boolean isOlder = Fee_30_FlexNor_SectorContainer_IsOlder(newestSector->SectorId, currentLink.SectorId);
            uint8 idDifference = Fee_30_FlexNor_SectorContainer_GetSectorIdDifference(
                newestSector->SectorId, currentLink.SectorId);

            if ((isOlder == TRUE) || (idDifference > FEE_30_FLEXNOR_LOOKUPTABLE_MAX_LUTLINK_ID_SPAN))
            {
                isCompatible = FALSE;
                break;
            }
        }
    }

    return isCompatible;
}

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_Init()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_Init(void)
{
    Fee_30_FlexNor_ConstConfigPtrType config = Fee_30_FlexNor_ConfigInterface_GetConfig();

    for(uint8 pIndex = 0; pIndex < config->PartitionCount; pIndex++)
    {
        Fee_30_FlexNor_LookupTable_Invalidate(config->Partitions[pIndex].PartitionId);
        Fee_30_FlexNor_LookupTable_ResetReallocationFlags(config->Partitions[pIndex].PartitionId);
        Fee_30_FlexNor_LookupTable_ResetPersistLutRequest(config->Partitions[pIndex].PartitionId);
    }

    Fee_30_FlexNor_LookupTable_InitState(&Fee_30_FlexNor_LookupTableStmContext); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_StartJob()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_StartJob(void)
{
    Fee_30_FlexNor_Scheduler_RegisterUnit(&Fee_30_FlexNor_LookupTable_ProcessingHandler); /* SBSW_Fee_30_FlexNor_RegisterUnit */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_EndJob()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_EndJob(void)
{
    Fee_30_FlexNor_Scheduler_UnregisterUnit();
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_GetLink()
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
FUNC(Fee_30_FlexNor_LookupTable_LinkType, FEE_30_FLEXNOR_CODE)  Fee_30_FlexNor_LookupTable_GetLink(
    Fee_30_FlexNor_PartitionIdType partitionId, Fee_30_FlexNor_BlockIdType blockId)
{
    Fee_30_FlexNor_ConstPartitionConfigPtrType partitionConfig = Fee_30_FlexNor_ConfigInterface_GetPartitionConfig(
        partitionId);

    Fee_30_FlexNor_LookupTable_LinkType link;
    link.SectorId = 0u;
    link.ChunkOffset = 0u;
    
    if(blockId < partitionConfig->LookupTableSize)
    {
        Fee_30_FlexNor_ChunkLocationType chunkLocation = partitionConfig->LookupTable[blockId];
        link = Fee_30_FlexNor_LookupTable_ToLookupTableLink(chunkLocation);
    }

    return link;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_SetLinkIfNewer()
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
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_SetLinkIfNewer(
    Fee_30_FlexNor_PartitionIdType partitionId, Fee_30_FlexNor_BlockIdType blockId, 
    Fee_30_FlexNor_LookupTable_LinkType link, Fee_30_FlexNor_StructureFlagsType reallocationRequired)
{
    Fee_30_FlexNor_ConstPartitionConfigPtrType partitionConfig = Fee_30_FlexNor_ConfigInterface_GetPartitionConfig(
        partitionId);
    
    if(blockId < partitionConfig->LookupTableSize)
    {
        Fee_30_FlexNor_LookupTable_LinkType storedLink 
            = Fee_30_FlexNor_LookupTable_ToLookupTableLink(partitionConfig->LookupTable[blockId]);
        boolean isStoredSectorOlder = Fee_30_FlexNor_SectorContainer_IsOlder(storedLink.SectorId, link.SectorId);

        if((isStoredSectorOlder == TRUE) || 
           (storedLink.SectorId == FEE_30_FLEXNOR_LOOKUPTABLE_LINK_DEFAULT_VALUE) ||
           ((storedLink.SectorId == link.SectorId) && (link.ChunkOffset > storedLink.ChunkOffset)))
        {
            Fee_30_FlexNor_ChunkLocationType chunkLocation = Fee_30_FlexNor_LookupTable_ToChunkLocation(link);
            partitionConfig->LookupTable[blockId] = chunkLocation; /* SBSW_Fee_30_FlexNor_LookupTableModifications */

            /* If the LUT chunk needs a reallocation the complete sector shall be recovered because the link chain can 
               not be maintained and a sector scan must be performed. This degrades the startup performance massively. 
            */
            if((blockId == FEE_30_FLEXNOR_LUTBLOCKID) && (reallocationRequired == TRUE))
            {
                Fee_30_FlexNor_ConstSectorPtrType currentSector = Fee_30_FlexNor_SectorContainer_Get(partitionId, 
                    link.SectorId, TRUE);
                Fee_30_FlexNor_InternalJobs_RequestRecoveryGarbageCollection(partitionId, currentSector->StartAddress);
            }
            else
            {
                Fee_30_FlexNor_LookupTable_RequestChunkReallocation(partitionId, blockId, reallocationRequired);
            }
        }
    }
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_IsValid()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(boolean, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_IsValid(Fee_30_FlexNor_PartitionIdType partitionId)
{
    return Fee_30_FlexNor_LookupTableValidity[partitionId];
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_Invalidate()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_Invalidate(Fee_30_FlexNor_PartitionIdType partitionId)
{
    Fee_30_FlexNor_ConstPartitionConfigPtrType partitionConfig = Fee_30_FlexNor_ConfigInterface_GetPartitionConfig(
        partitionId);

    for(uint32 lutIndex = 0u; lutIndex < partitionConfig->LookupTableSize; lutIndex++)
    {
        partitionConfig->LookupTable[lutIndex] = FEE_30_FLEXNOR_LOOKUPTABLE_LINK_DEFAULT_VALUE; /* SBSW_Fee_30_FlexNor_LookupTableModifications */
    }
    Fee_30_FlexNor_LookupTableValidity[partitionId] = FALSE;  /* SBSW_Fee_30_FlexNor_LookupTableValidity */

    Fee_30_FlexNor_LookupTable_ResetReallocationFlags(partitionId);
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_IsLoadedLutSuitableForPartialRecovery()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(boolean, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_IsLoadedLutSuitableForPartialRecovery(
    Fee_30_FlexNor_PartitionIdType partitionId)
{
    boolean isSuitable = FALSE;
    Fee_30_FlexNor_ConstPartitionConfigPtrType partitionConfig
        = Fee_30_FlexNor_ConfigInterface_GetPartitionConfig(partitionId);

    Fee_30_FlexNor_ChunkLocationType lutVersion = partitionConfig->LookupTable[0u];
    boolean isLoadedLutAndReadSectorIdsCompatible
        = Fee_30_FlexNor_LookupTable_IsLoadedLutCompatibleWithFlashSectors(partitionId);

    if ((lutVersion == FEE_30_FLEXNOR_LOOKUPTABLE_VERSION) && (isLoadedLutAndReadSectorIdsCompatible == TRUE))
    {
        isSuitable = TRUE;
    }

    return isSuitable;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_FullRecovery()
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
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_FullRecovery(Fee_30_FlexNor_PartitionIdType partitionId, 
    Fee_30_FlexNor_ResultCallback resultCbk)
{
    Fee_30_FlexNor_LookupTableStmContext.PartitionConfig 
        = Fee_30_FlexNor_ConfigInterface_GetPartitionConfig(partitionId);
    Fee_30_FlexNor_LookupTableStmContext.ResultCallback = resultCbk;
    Fee_30_FlexNor_LookupTableStmContext.RequestedRecoveryMode = FEE_30_FLEXNOR_LOOKUPTABLE_FULLRECOVERY;

    Fee_30_FlexNor_LookupTable_InvalidateNewChunkCounter(partitionId);
    Fee_30_FlexNor_LookupTable_Invalidate(partitionId);
    Fee_30_FlexNor_LookupTable_ResetReallocationFlags(partitionId);

    Fee_30_FlexNor_LookupTable_Recover_Initialize(&Fee_30_FlexNor_LookupTableStmContext); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_PartialRecovery()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_PartialRecovery(Fee_30_FlexNor_PartitionIdType partitionId, 
    Fee_30_FlexNor_ResultCallback resultCbk)
{
    Fee_30_FlexNor_LookupTableStmContext.PartitionConfig 
        = Fee_30_FlexNor_ConfigInterface_GetPartitionConfig(partitionId);
    Fee_30_FlexNor_LookupTableStmContext.ResultCallback = resultCbk;

    Fee_30_FlexNor_LookupTableStmContext.RequestedRecoveryMode = FEE_30_FLEXNOR_LOOKUPTABLE_PARTIALRECOVERY;

    Fee_30_FlexNor_LookupTable_ResetPersistLutRequest(partitionId);

    Fee_30_FlexNor_LookupTable_Recover_Initialize(&Fee_30_FlexNor_LookupTableStmContext); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_TriggerSectorScan()
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
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_TriggerSectorScan(
    Fee_30_FlexNor_LookupTable_ContextPtrType ctx)  /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    if(ctx->NextSectorToProcess != NULL_PTR) /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
    {   
        if(ctx->RequestedRecoveryMode == FEE_30_FLEXNOR_LOOKUPTABLE_FULLRECOVERY)
        {
            Fee_30_FlexNor_Sector_FullScan(ctx->NextSectorToProcess, &Fee_30_FlexNor_LookupTable_ResultHandler); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
        }
        else /* FEE_30_FLEXNOR_LOOKUPTABLE_PARTIALRECOVERY */
        {    
#if (FEE_30_FLEXNOR_LOOKUPTABLE_COMPATIBILITY_MODE == STD_OFF)
            boolean skipSector = Fee_30_FlexNor_LookupTable_DoesLookupTableLinkToANewerSector(ctx->NextSectorToProcess); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */

            if(skipSector == FALSE)
            {
#endif
                Fee_30_FlexNor_LookupTable_LinkType latestKnownChunk 
                    = Fee_30_FlexNor_LookupTable_GetLatestKnownChunkInSector(ctx->NextSectorToProcess->PartitionId, 
                        ctx->NextSectorToProcess->SectorId);
                Fee_30_FlexNor_AddressType addressOfLatestKnownChunk = Fee_30_FlexNor_ChunkSearch_CalculateChunkAddress(
                    ctx->NextSectorToProcess->PartitionId, latestKnownChunk.SectorId, latestKnownChunk.ChunkOffset);

                Fee_30_FlexNor_Sector_PartialScan(ctx->NextSectorToProcess, addressOfLatestKnownChunk, /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
                    &Fee_30_FlexNor_LookupTable_ResultHandler);
#if (FEE_30_FLEXNOR_LOOKUPTABLE_COMPATIBILITY_MODE == STD_OFF)
            }
#endif
        }
    }
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_Validate
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_Validate(Fee_30_FlexNor_PartitionIdType partitionId) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    Fee_30_FlexNor_LookupTableValidity[partitionId] = TRUE; /* SBSW_Fee_30_FlexNor_LookupTableValidity */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_PersistIfRequired()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_PersistIfRequired(
    Fee_30_FlexNor_PartitionIdType partitionId)
{
    if (Fee_30_FlexNor_LookupTable_IsPersistLutRequired(partitionId) == TRUE)
    {
        Fee_30_FlexNor_LookupTableStmContext.PartitionConfig 
            = Fee_30_FlexNor_ConfigInterface_GetPartitionConfig(partitionId);

        Fee_30_FlexNor_LookupTable_Persist_Initialize(&Fee_30_FlexNor_LookupTableStmContext); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_TriggerLutBlockWrite
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_TriggerLutBlockWrite(
    Fee_30_FlexNor_LookupTable_ContextPtrType ctx)
{
    Fee_30_FlexNor_LookupTable_CreateLutJob(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */   
    Fee_30_FlexNor_LookupTable_SetVersionInFirstLutEntry(ctx->PartitionConfig->LookupTable); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */   
    Fee_30_FlexNor_Partition_WriteBlock(&ctx->LutJob); /* SBSW_Fee_30_FlexNor_FunctionCallWithJobPointer */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_TriggerLutShortcutWrite
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_TriggerLutShortcutWrite(
    Fee_30_FlexNor_LookupTable_ConstContextPtrType ctx)
{
    Fee_30_FlexNor_SectorPtrType sector = Fee_30_FlexNor_LookupTable_GetSectorOfLatestLutBlock(ctx->PartitionConfig); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    Fee_30_FlexNor_LookupTable_LinkType lutLink = Fee_30_FlexNor_LookupTable_GetLink(ctx->PartitionConfig->PartitionId, 
        FEE_30_FLEXNOR_LUTBLOCKID);

    sector->LutChunkLink.Target = Fee_30_FlexNor_LookupTable_ToChunkLocation(lutLink); /* SBSW_Fee_30_FlexNor_SectorContainer_GetSector */
    sector->LutChunkLink.Validity = FEE_30_FLEXNOR_VALID; /* SBSW_Fee_30_FlexNor_SectorContainer_GetSector */

    Fee_30_FlexNor_Sector_WriteLutLink(sector, &Fee_30_FlexNor_LookupTable_ResultHandler); /* SBSW_Fee_30_FlexNor_SectorContainer_GetSector */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_IsShortcutNecessary
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(boolean, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_IsShortcutNecessary(
    Fee_30_FlexNor_LookupTable_ConstContextPtrType ctx)
{
    Fee_30_FlexNor_ConstSectorPtrType sector = Fee_30_FlexNor_LookupTable_GetSectorOfLatestLutBlock(
        ctx->PartitionConfig); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    boolean isShortcutNecessary = FALSE;

    if ((ctx->LutJob.JobResult == MEMIF_JOB_OK) && (sector != NULL_PTR))
    {
        isShortcutNecessary = (sector->LutChunkLink.Validity == FEE_30_FLEXNOR_EMPTY) ? TRUE : FALSE;
    }

    return isShortcutNecessary;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_Load()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_Load(Fee_30_FlexNor_PartitionIdType partitionId, 
    Fee_30_FlexNor_ResultCallback resultCbk)
{
    Fee_30_FlexNor_LookupTableStmContext.PartitionConfig = Fee_30_FlexNor_ConfigInterface_GetPartitionConfig(
        partitionId);
    Fee_30_FlexNor_LookupTableStmContext.ResultCallback = resultCbk;
    Fee_30_FlexNor_LookupTableStmContext.LutChunkLocation = FEE_30_FLEXNOR_LOOKUPTABLE_LINK_DEFAULT_VALUE;
    Fee_30_FlexNor_LookupTable_Load_Initialize(&Fee_30_FlexNor_LookupTableStmContext); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_IsReallocationRequested()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(boolean, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_IsReallocationRequested(
    Fee_30_FlexNor_PartitionIdType partitionId, Fee_30_FlexNor_BlockIdType blockId)
{
    Fee_30_FlexNor_ConstPartitionConfigPtrType partitionConfig = Fee_30_FlexNor_ConfigInterface_GetPartitionConfig(
        partitionId);
    return (TestBit(partitionConfig->ChunkReallocationFlags, blockId) == 1u) ? TRUE : FALSE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_RequestChunkReallocation()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_RequestChunkReallocation(
    Fee_30_FlexNor_PartitionIdType partitionId, Fee_30_FlexNor_BlockIdType blockId, 
    Fee_30_FlexNor_StructureFlagsType reallocationRequired)
{
    Fee_30_FlexNor_ConstPartitionConfigPtrType partitionConfig = Fee_30_FlexNor_ConfigInterface_GetPartitionConfig(
        partitionId);

    if(reallocationRequired == TRUE)
    {
        SetBit(partitionConfig->ChunkReallocationFlags, blockId); /* SBSW_Fee_30_FlexNor_ChunkReallocationModifications */
    }
    else
    {
        ClearBit(partitionConfig->ChunkReallocationFlags, blockId); /* SBSW_Fee_30_FlexNor_ChunkReallocationModifications */
    }
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_IncrementNewChunkCounter()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_IncrementNewChunkCounter(
    Fee_30_FlexNor_PartitionIdType partitionId)
{
    Fee_30_FlexNor_LookupTablePersistDataPtrType persistData = &Fee_30_FlexNor_LookupTablePersistData[partitionId];
    if (persistData->NumberOfNewChunks != FEE_30_FLEXNOR_LOOKUPTABLE_NEWCHUNKCOUNTINVALID)
    {
        persistData->NumberOfNewChunks++; /* SBSW_Fee_30_FlexNor_LookupTablePersistData */
    }
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_RequestPersistLut()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_RequestPersistLut(Fee_30_FlexNor_PartitionIdType partitionId)
{
    Fee_30_FlexNor_LookupTablePersistData[partitionId].PersistLutRequested = TRUE; /* SBSW_Fee_30_FlexNor_LookupTablePersistData */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_ResetReallocationFlags()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_ResetReallocationFlags(
    Fee_30_FlexNor_PartitionIdType partitionId)
{
    uint32 lutIndex;
    Fee_30_FlexNor_ConstPartitionConfigPtrType partitionConfig;
    
    partitionConfig = Fee_30_FlexNor_ConfigInterface_GetPartitionConfig(partitionId);

    for(lutIndex = 0u; lutIndex < partitionConfig->LookupTableSize; lutIndex++)
    {
        ClearBit(partitionConfig->ChunkReallocationFlags, lutIndex); /* SBSW_Fee_30_FlexNor_ChunkReallocationModifications */
    }
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_TriggerLutChunkSearch
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_TriggerLutChunkSearch(
    Fee_30_FlexNor_LookupTable_ContextPtrType ctx)
{
    Fee_30_FlexNor_LookupTable_CreateLutJob(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
    
    Fee_30_FlexNor_ConstSectorPtrType mostRecentLutSector =  Fee_30_FlexNor_LookupTable_GetSectorWithLatestLutLink(
        ctx->PartitionConfig->PartitionId);

    if(mostRecentLutSector != NULL_PTR)
    {
        Fee_30_FlexNor_ChunkFactory_CreateChunk(0u, ctx->PartitionConfig->PartitionId, mostRecentLutSector->SectorId, 
            &ctx->LutChunk); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
        
        Fee_30_FlexNor_ChunkSearch_FollowLink(
            ctx->PartitionConfig->PartitionId,
            mostRecentLutSector->LutChunkLink,
            &ctx->LutChunk,
            &Fee_30_FlexNor_LookupTable_LutChunkSearchResultHandler); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
    }
    else
    {
        ctx->LutChunkSearchSucceeded = FALSE; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    }
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_TriggerLutInstanceSearch
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_TriggerLutInstanceSearch(
    Fee_30_FlexNor_LookupTable_ContextPtrType ctx)
{
    Fee_30_FlexNor_InstanceFactory_CreateInstance(0u, ctx->PartitionConfig->PartitionId, &ctx->LutInstance); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
    
    ctx->LutInstance.Data.ReadBuffer = ctx->LutJob.ReadBuffer; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    ctx->LutInstance.Data.PayloadOffset = ctx->LutJob.Offset; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */

    ctx->LutChunk.Services.FindLatestValidInstance(&ctx->LutChunk, &ctx->LutInstance, 
        &Fee_30_FlexNor_LookupTable_ResultHandler); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_TriggerLutPayloadRead
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_TriggerLutPayloadRead(
    Fee_30_FlexNor_LookupTable_ContextPtrType ctx)
{
    ctx->LutInstance.Services.ReadContent(&ctx->LutInstance.Data, &Fee_30_FlexNor_LookupTable_ResultHandler); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_IsPersistLutRequired
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(boolean, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_IsPersistLutRequired(
    Fee_30_FlexNor_PartitionIdType partitionId)
{
    boolean persistLut = FALSE;

    Fee_30_FlexNor_ConstLookupTablePersistDataPtrType persistData = &Fee_30_FlexNor_LookupTablePersistData[partitionId];

    /* The LUT is only persisted in case it is valid, which also avoids performing a LUT 
    Recovery during latest chunk search. */
    boolean lutIsValid = Fee_30_FlexNor_LookupTable_IsValid(partitionId);
    boolean persistLutRequestedViaMetric = (boolean)  
        ((persistData->NumberOfNewChunks != FEE_30_FLEXNOR_LOOKUPTABLE_NEWCHUNKCOUNTINVALID)
        && (persistData->NumberOfNewChunks > FEE_30_FLEXNOR_LOOKUPTABLE_MAX_NUMBER_OF_CHUNKS_TO_SCAN));
    boolean persistLutExplicitlyRequested = persistData->PersistLutRequested;

    if ((lutIsValid == TRUE)
        && ((persistLutRequestedViaMetric == TRUE) || (persistLutExplicitlyRequested == TRUE)))
    {
        persistLut = TRUE;
    }

    return persistLut;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_ResetPersistLutRequest
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_ResetPersistLutRequest(
    Fee_30_FlexNor_PartitionIdType partitionId)
{
    Fee_30_FlexNor_LookupTablePersistDataPtrType persistData = &Fee_30_FlexNor_LookupTablePersistData[partitionId];

    persistData->PersistLutRequested = FALSE; /* SBSW_Fee_30_FlexNor_LookupTablePersistData */
    persistData->NumberOfNewChunks = 0; /* SBSW_Fee_30_FlexNor_LookupTablePersistData */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_SetOffsetForNumberOfNewChunks
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_SetOffsetForNumberOfNewChunks(
    Fee_30_FlexNor_PartitionIdType partitionId)
{
    Fee_30_FlexNor_ConstPartitionConfigPtrType partitionConfig
        = Fee_30_FlexNor_ConfigInterface_GetPartitionConfig(partitionId);

    Fee_30_FlexNor_LookupTablePersistDataPtrType persistData = &Fee_30_FlexNor_LookupTablePersistData[partitionId];

    /* The Fee tries to read at least one chunk per sector. So the minimal number of chunks to read during a LUT 
       recovery is the number of sectors. */
    persistData->NumberOfNewChunks = partitionConfig->SectorCount; /* SBSW_Fee_30_FlexNor_LookupTablePersistData */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_GetLutBlockContentLength()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_LengthType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_GetLutBlockContentLength(
    Fee_30_FlexNor_LookupTable_ConstContextPtrType ctx)
{
    return (ctx->LutChunk.Data.PayloadSize > ctx->LutJob.Length) ? ctx->LutJob.Length : ctx->LutChunk.Data.PayloadSize;
}

#define FEE_30_FLEXNOR_STOP_SEC_CODE
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: Fee_30_Flexnor_LookupTable.c
 *********************************************************************************************************************/
