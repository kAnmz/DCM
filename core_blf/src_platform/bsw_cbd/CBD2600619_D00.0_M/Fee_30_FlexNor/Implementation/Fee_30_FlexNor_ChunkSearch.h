/**********************************************************************************************************************
 *  COPYRIGHT
 *  --------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2025 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  --------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/*!        \file  Fee_30_FlexNor_ChunkSearch.h
 *        \brief  Chunk search interface
 *      \details  Provides service to search chunks in memory.
 *         \unit  ChunkSearch
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 **********************************************************************************************************************/

#if !defined (FEE_30_FLEXNOR_CHUNKSEARCH_H)
# define FEE_30_FLEXNOR_CHUNKSEARCH_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Fee_30_FlexNor_Types.h"
#include "Fee_30_FlexNor_ConfigInterface.h"
#include "Fee_30_FlexNor_ChunkFactory.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define FEE_30_FLEXNOR_CHUNKSEARCH_INVALID_CHUNKLOCATION (0u)   /*!< Describes an invalid location where no chunk can 
                                                                     be read from */

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
# define FEE_30_FLEXNOR_START_SEC_CODE
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Fee_30_FlexNor_ChunkSearch_Init()
 *********************************************************************************************************************/
/*! \brief       Initialize the chunk search unit
 *  \details     -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_ChunkSearch_Init(void);

/**********************************************************************************************************************
 * Fee_30_FlexNor_ChunkSearch_CalculateChunkAddress()
 *********************************************************************************************************************/
/*! \brief       Calculates the address of a chunk based on the given partition id, sector id and page based offset.
 *  \details     -
 *  \param[in]   partitionId               Id of the partition the target chunk resides in.
 *  \param[in]   sectorId                  Id of the sector the target chunk resides in.
 *  \param[in]   chunkOffset               Offset of the chunk relativ to the sector start address.
 *  \return      The calculated address of the chunk. If currently no sector with the given sector id exists in the 
 *               partition, FEE_30_FLEXNOR_CHUNKSEARCH_INVALID_CHUNKLOCATION is returned.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_AddressType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_ChunkSearch_CalculateChunkAddress(
    Fee_30_FlexNor_PartitionIdType partitionId, Fee_30_FlexNor_SectorIdType sectorId, 
    Fee_30_FlexNor_PagebasedOffsetType chunkOffset);

/**********************************************************************************************************************
 * Fee_30_FlexNor_ChunkSearch_FollowLink()
 *********************************************************************************************************************/
/*! \brief       Follows the chunk chain until the last chunk is reached
 *  \details     Traverses a chain of linked chunks, starting from a given chunk link.
 *  \param[in]   partitionId    Id of the partition the chunk search shall be executed in.
 *  \param[in]   startLink      Chunk link pointing to the chunk where the search is started.
 *  \param[out]  foundChunk     Pointer to the chunk where the search result is stored. Must not be NULL.
 *  \param[in]   resultCbk      The result callback that is called in case the service is complete. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous FALSE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_ChunkSearch_FollowLink(Fee_30_FlexNor_PartitionIdType partitionId, 
    Fee_30_FlexNor_ChunkLinkType startLink, Fee_30_FlexNor_ChunkPtrType foundChunk, 
    Fee_30_FlexNor_ResultCallback resultCbk);

# define FEE_30_FLEXNOR_STOP_SEC_CODE
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* FEE_30_FLEXNOR_CHUNKSEARCH_H */

/**********************************************************************************************************************
 *  END OF FILE: Fee_30_FlexNor_ChunkSearch.h
 *********************************************************************************************************************/
