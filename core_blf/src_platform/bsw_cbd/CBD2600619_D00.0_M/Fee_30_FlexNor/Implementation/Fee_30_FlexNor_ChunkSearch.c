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
/*!        \file  Fee_30_FlexNor_ChunkSearch.c
 *        \brief  Chunk search implementation
 *      \details  Provides the business logic for the chunk search services.
 *         \unit  ChunkSearch
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#define FEE_30_FLEXNOR_CHUNKSEARCH_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Fee_30_FlexNor_ChunkSearch.h"
#include "Fee_30_FlexNor_ChunkSearchInternal.h"
#include "Fee_30_FlexNor_ChunkSearchMachine.h"

#include "Fee_30_FlexNor_Scheduler.h"
#include "Fee_30_FlexNor_SectorContainer.h"

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
#define FEE_30_FLEXNOR_CHUNKSEARCH_OFFSET_MASK (0x00FFFFFFu)    /*!< The first byte will be used for the sector id for 
                                                                     the offset we need the following 3 bytes */
#define FEE_30_FLEXNOR_CHUNKSEARCH_SECTORID_SHIFTSIZE (24u)     /*!< Describes the with a chunk location must be shifted 
                                                                     to retrieve the sector id */

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

/*! Context variable of the chunk search state machine. */
FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_ChunkSearch_ContextType Fee_30_FlexNor_ChunkSearchStmContext = { 0u }; /* PRQA S 3218 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */

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
 * Fee_30_FlexNor_ChunkSearch_ProcessingHandler()
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
    Fee_30_FlexNor_ChunkSearch_ProcessingHandler(void);

/**********************************************************************************************************************
 * Fee_30_FlexNor_ChunkSearch_ResultHandler()
 *********************************************************************************************************************/
/*! \brief       Handles the result of a called service
 *  \details     This function is used as a result callback for services called by this unit.
 *  \param[in]   result         Result of the called service
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FEE_30_FLEXNOR_LOCAL FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_ChunkSearch_ResultHandler(
    Fee_30_FlexNor_ServiceResult result);

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * Fee_30_FlexNor_ChunkSearch_ProcessingHandler()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FEE_30_FLEXNOR_LOCAL FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) 
    Fee_30_FlexNor_ChunkSearch_ProcessingHandler(void)
{
    return Fee_30_FlexNor_ChunkSearchStmContext.CurrentState->ProcessEvent(&Fee_30_FlexNor_ChunkSearchStmContext); /* SBSW_Fee_30_FlexNor_TriggerEventAtState */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_ChunkSearch_ResultHandler()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FEE_30_FLEXNOR_LOCAL FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_ChunkSearch_ResultHandler(
    Fee_30_FlexNor_ServiceResult result)
{
    if(result == FEE_30_FLEXNOR_SERVICE_FAIL)
    {
        Fee_30_FlexNor_ChunkSearchStmContext.CurrentState->FailEvent(&Fee_30_FlexNor_ChunkSearchStmContext); /* SBSW_Fee_30_FlexNor_TriggerEventAtState */
    }
}

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * Fee_30_FlexNor_ChunkSearch_Init()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_ChunkSearch_Init(void)
{
    Fee_30_FlexNor_ChunkSearch_InitState(&Fee_30_FlexNor_ChunkSearchStmContext); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_ChunkSearch_CalculateChunkAddress()
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
FUNC(Fee_30_FlexNor_AddressType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_ChunkSearch_CalculateChunkAddress(
    Fee_30_FlexNor_PartitionIdType partitionId, Fee_30_FlexNor_SectorIdType sectorId, 
    Fee_30_FlexNor_PagebasedOffsetType chunkOffset)
{
    Fee_30_FlexNor_AddressType chunkAddress = FEE_30_FLEXNOR_CHUNKSEARCH_INVALID_CHUNKLOCATION;
    Fee_30_FlexNor_ConstPartitionConfigPtrType partitionConfig = Fee_30_FlexNor_ConfigInterface_GetPartitionConfig(
        partitionId);
    Fee_30_FlexNor_ConstSectorPtrType sector = Fee_30_FlexNor_SectorContainer_GetFirst(partitionId);

    do 
    {
        if((sector->SectorId == sectorId) && (sector->Validity == FEE_30_FLEXNOR_VALID))
        {
            Fee_30_FlexNor_LengthType sectorLength = Fee_30_FlexNor_ConfigInterface_GetSectorLength(partitionId, 
                sector->StartAddress);
            chunkAddress = sector->StartAddress + (chunkOffset * partitionConfig->PageAlignment);

            if(chunkAddress > (sector->StartAddress + sectorLength))
            {
                chunkAddress = FEE_30_FLEXNOR_CHUNKSEARCH_INVALID_CHUNKLOCATION;
            }

            break;
        }
        sector = Fee_30_FlexNor_SectorContainer_GetNext(sector); /* SBSW_Fee_30_FlexNor_LoopStoredSectors */
    } while (sector != NULL_PTR);

    return chunkAddress;
}
/**********************************************************************************************************************
 * Fee_30_FlexNor_ChunkSearch_StartJob()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_ChunkSearch_StartJob(void)
{
    Fee_30_FlexNor_Scheduler_RegisterUnit(&Fee_30_FlexNor_ChunkSearch_ProcessingHandler); /* SBSW_Fee_30_FlexNor_RegisterUnit */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_ChunkSearch_EndJob()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_ChunkSearch_EndJob(void)
{
    Fee_30_FlexNor_Scheduler_UnregisterUnit();
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_ChunkSearch_ParseChunkLink()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Fee_30_FlexNor_LookupTable_LinkType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_ChunkSearch_ParseChunkLink(
    Fee_30_FlexNor_ChunkLinkType link)
{
    Fee_30_FlexNor_LookupTable_LinkType parsedLink;

    parsedLink.SectorId = (Fee_30_FlexNor_SectorIdType)(link.Target >> FEE_30_FLEXNOR_CHUNKSEARCH_SECTORID_SHIFTSIZE);
    parsedLink.ChunkOffset = (Fee_30_FlexNor_PagebasedOffsetType)(link.Target & FEE_30_FLEXNOR_CHUNKSEARCH_OFFSET_MASK);

    return parsedLink;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_ChunkSearch_FollowLink()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_ChunkSearch_FollowLink(Fee_30_FlexNor_PartitionIdType partitionId, 
    Fee_30_FlexNor_ChunkLinkType startLink, Fee_30_FlexNor_ChunkPtrType foundChunk, 
    Fee_30_FlexNor_ResultCallback resultCbk)
{
    Fee_30_FlexNor_ChunkSearchStmContext.PartitionId = partitionId;
    Fee_30_FlexNor_ChunkSearchStmContext.NextChunk = startLink;
    Fee_30_FlexNor_ChunkSearchStmContext.CurrentChunk = foundChunk;
    Fee_30_FlexNor_ChunkSearchStmContext.ResultCallback = resultCbk;

    Fee_30_FlexNor_ChunkSearch_FollowLink_Initialize(&Fee_30_FlexNor_ChunkSearchStmContext); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_ChunkSearch_ReadChunk()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_ChunkSearch_ReadChunk(
    Fee_30_FlexNor_ChunkSearch_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    Std_ReturnType readResult = E_NOT_OK;
   
    Fee_30_FlexNor_LookupTable_LinkType parsedLink = Fee_30_FlexNor_ChunkSearch_ParseChunkLink(ctx->NextChunk);
    Fee_30_FlexNor_AddressType chunkAddress = Fee_30_FlexNor_ChunkSearch_CalculateChunkAddress(
        ctx->PartitionId,
        parsedLink.SectorId,
        parsedLink.ChunkOffset
    );

    if(chunkAddress != FEE_30_FLEXNOR_CHUNKSEARCH_INVALID_CHUNKLOCATION)
    {
        Fee_30_FlexNor_ChunkFactory_CreateChunk(chunkAddress, ctx->PartitionId, parsedLink.SectorId, ctx->CurrentChunk); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
        ctx->CurrentChunk->Services.ReadHeader(ctx->CurrentChunk, &Fee_30_FlexNor_ChunkSearch_ResultHandler); /* SBSW_Fee_30_FlexNor_ContextFunctionPointerCall */
        readResult = E_OK;
    }

    return readResult;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_ChunkSearch_IsSuccessorChunkNewer()
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
FUNC(boolean, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_ChunkSearch_IsSuccessorChunkNewer(
    Fee_30_FlexNor_ChunkSearch_ConstContextPtrType ctx)
{
    boolean isNewer = FALSE;

    Fee_30_FlexNor_LookupTable_LinkType parsedChunkLink = Fee_30_FlexNor_ChunkSearch_ParseChunkLink(
        ctx->CurrentChunk->Data.ChunkLink);
    Fee_30_FlexNor_AddressType successorChunkStartAddress = Fee_30_FlexNor_ChunkSearch_CalculateChunkAddress(
        ctx->PartitionId,
        parsedChunkLink.SectorId,
        parsedChunkLink.ChunkOffset
    );

    if (Fee_30_FlexNor_SectorContainer_IsOlder(ctx->CurrentChunk->Data.SectorId, parsedChunkLink.SectorId) == TRUE)
    {
        isNewer = TRUE;
    }
    else if ((ctx->CurrentChunk->Data.SectorId == parsedChunkLink.SectorId) &&
             (ctx->CurrentChunk->Data.StartAddress < successorChunkStartAddress))
    {
        isNewer = TRUE;
    }
    else
    {
        /* Intentionally left empty */
    }

    return isNewer;
}

#define FEE_30_FLEXNOR_STOP_SEC_CODE
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: Fee_30_FlexNor_ChunkSearch.c
 *********************************************************************************************************************/
