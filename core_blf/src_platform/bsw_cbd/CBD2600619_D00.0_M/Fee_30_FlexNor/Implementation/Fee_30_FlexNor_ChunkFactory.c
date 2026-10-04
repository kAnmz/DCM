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
/*!        \file  Fee_30_FlexNor_ChunkFactory.c
 *        \brief  Interface to create the generic chunk.
 *      \details  Provides the implementation of an interface to create a chunk.
 *         \unit  ChunkFactory
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#define FEE_30_FLEXNOR_CHUNKFACTORY_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Fee_30_FlexNor_Chunk.h"
#include "Fee_30_FlexNor_SecureChunk.h"
#include "Fee_30_FlexNor_SlimChunk.h"
#include "Fee_30_FlexNor_ChunkFactory.h"

#include "Fee_30_FlexNor_ConfigInterface.h"

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/
#if !defined(FEE_30_FLEXNOR_LOCAL) /* COV_FEE_30_FLEXNOR_COMPATIBILITY */
#   define FEE_30_FLEXNOR_LOCAL static
#endif

#if !defined(FEE_30_FLEXNOR_LOCAL_INLINE) /* COV_FEE_30_FLEXNOR_COMPATIBILITY */
#    define FEE_30_FLEXNOR_LOCAL_INLINE LOCAL_INLINE
#endif

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define FEE_30_FLEXNOR_START_SEC_CODE
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

#if (FEE_30_FLEXNOR_SECURELAYOUT_ENABLED == STD_ON) /* COV_MSR_UT_OPTIONAL_UNIT */
/**********************************************************************************************************************
 * Fee_30_FlexNor_ChunkFactory_CreateSecurePartOfChunk()
 *********************************************************************************************************************/
/*! \brief       Creates the part of the chunk that is specific to the secure chunk into the given pointer.
 *  \details     -
 *  \param[out]  chunkToCreate      Pointer to the structure the chunk shall be created in. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FEE_30_FLEXNOR_LOCAL FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_ChunkFactory_CreateSecurePartOfChunk(
    Fee_30_FlexNor_ChunkPtrType chunkToCreate);
#endif

#if (FEE_30_FLEXNOR_SLIMLAYOUT_ENABLED == STD_ON) /* COV_MSR_UT_OPTIONAL_UNIT */
/**********************************************************************************************************************
 * Fee_30_FlexNor_ChunkFactory_CreateSlimPartOfChunk()
 *********************************************************************************************************************/
/*! \brief       Creates the part of the chunk that is specific to the slim chunk into the given pointer.
 *  \details     -
 *  \param[out]  chunkToCreate      Pointer to the structure the chunk shall be created in. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FEE_30_FLEXNOR_LOCAL FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_ChunkFactory_CreateSlimPartOfChunk(
    Fee_30_FlexNor_ChunkPtrType chunkToCreate);
#endif

/**********************************************************************************************************************
 * Fee_30_FlexNor_ChunkFactory_CreateGeneralPartOfChunk()
 *********************************************************************************************************************/
/*! \brief       Creates the general part of the chunk, i.e. the information that is independent from the layout.
 *  \details     -
 *  \param[in]   address            Address of the chunk that shall be created
 *  \param[in]   partitionId        Id of the partition the chunk belongs to
 *  \param[in]   sectorId           Id of the sector the chunk belongs to
 *  \param[out]  chunkToCreate      Pointer to the structure the chunk shall be created in.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FEE_30_FLEXNOR_LOCAL FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_ChunkFactory_CreateGeneralPartOfChunk(
    Fee_30_FlexNor_AddressType address,
    Fee_30_FlexNor_PartitionIdType partitionId,
    Fee_30_FlexNor_SectorIdType sectorId,
    Fee_30_FlexNor_ChunkPtrType chunkToCreate);

#if (FEE_30_FLEXNOR_SECURELAYOUT_ENABLED == STD_ON) /* COV_MSR_UT_OPTIONAL_UNIT */
/**********************************************************************************************************************
 * Fee_30_FlexNor_ChunkFactory_CreateSecurePartOfChunk()
 *********************************************************************************************************************/
/*! Internal comment removed.
 *
 *
 */
FEE_30_FLEXNOR_LOCAL FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_ChunkFactory_CreateSecurePartOfChunk(
    Fee_30_FlexNor_ChunkPtrType chunkToCreate)
{
    chunkToCreate->Services.ReadHeader                   = &Fee_30_FlexNor_SecureChunk_ReadHeader;             /* SBSW_Fee_30_FlexNor_Factory */
    chunkToCreate->Services.Allocate                     = &Fee_30_FlexNor_SecureChunk_Allocate;               /* SBSW_Fee_30_FlexNor_Factory */
    chunkToCreate->Services.GetHeaderSize                = &Fee_30_FlexNor_SecureChunk_GetHeaderSize;          /* SBSW_Fee_30_FlexNor_Factory */
    chunkToCreate->Services.GetTotalSize                 = &Fee_30_FlexNor_SecureChunk_GetTotalSize;           /* SBSW_Fee_30_FlexNor_Factory */
    chunkToCreate->Services.WriteLink                    = &Fee_30_FlexNor_Chunk_WriteLink;                    /* SBSW_Fee_30_FlexNor_Factory */
    chunkToCreate->Services.FindLatestValidInstance      = &Fee_30_FlexNor_Chunk_FindLatestValidInstance;      /* SBSW_Fee_30_FlexNor_Factory */
    chunkToCreate->Services.GetJobResultOfInstanceSearch = &Fee_30_FlexNor_Chunk_GetJobResultOfInstanceSearch; /* SBSW_Fee_30_FlexNor_Factory */
    chunkToCreate->Services.TryAllocateInstance          = &Fee_30_FlexNor_Chunk_TryAllocateInstance;          /* SBSW_Fee_30_FlexNor_Factory */
}
#endif

#if (FEE_30_FLEXNOR_SLIMLAYOUT_ENABLED == STD_ON) /* COV_MSR_UT_OPTIONAL_UNIT */
/**********************************************************************************************************************
 * Fee_30_FlexNor_ChunkFactory_CreateSlimPartOfChunk()
 *********************************************************************************************************************/
/*! Internal comment removed.
 *
 *
 */
FEE_30_FLEXNOR_LOCAL FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_ChunkFactory_CreateSlimPartOfChunk(
    Fee_30_FlexNor_ChunkPtrType chunkToCreate)
{
    chunkToCreate->Services.ReadHeader                   = &Fee_30_FlexNor_SlimChunk_ReadHeader;               /* SBSW_Fee_30_FlexNor_Factory */
    chunkToCreate->Services.Allocate                     = &Fee_30_FlexNor_SlimChunk_Allocate;                 /* SBSW_Fee_30_FlexNor_Factory */
    chunkToCreate->Services.GetHeaderSize                = &Fee_30_FlexNor_SlimChunk_GetHeaderSize;            /* SBSW_Fee_30_FlexNor_Factory */
    chunkToCreate->Services.GetTotalSize                 = &Fee_30_FlexNor_SlimChunk_GetTotalSize;             /* SBSW_Fee_30_FlexNor_Factory */
    chunkToCreate->Services.WriteLink                    = &Fee_30_FlexNor_Chunk_WriteLink;                    /* SBSW_Fee_30_FlexNor_Factory */
    chunkToCreate->Services.FindLatestValidInstance      = &Fee_30_FlexNor_Chunk_FindLatestValidInstance;      /* SBSW_Fee_30_FlexNor_Factory */
    chunkToCreate->Services.GetJobResultOfInstanceSearch = &Fee_30_FlexNor_Chunk_GetJobResultOfInstanceSearch; /* SBSW_Fee_30_FlexNor_Factory */
    chunkToCreate->Services.TryAllocateInstance          = &Fee_30_FlexNor_Chunk_TryAllocateInstance;          /* SBSW_Fee_30_FlexNor_Factory */
}
#endif

/**********************************************************************************************************************
 * Fee_30_FlexNor_ChunkFactory_CreateGeneralPartOfChunk()
 *********************************************************************************************************************/
/*! Internal comment removed.
 *
 *
 */
FEE_30_FLEXNOR_LOCAL FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_ChunkFactory_CreateGeneralPartOfChunk(
    Fee_30_FlexNor_AddressType address,
    Fee_30_FlexNor_PartitionIdType partitionId,
    Fee_30_FlexNor_SectorIdType sectorId,
    Fee_30_FlexNor_ChunkPtrType chunkToCreate)
{
    chunkToCreate->Data.PartitionId  = partitionId;   /* SBSW_Fee_30_FlexNor_Factory */
    chunkToCreate->Data.SectorId     = sectorId;      /* SBSW_Fee_30_FlexNor_Factory */
    chunkToCreate->Data.StartAddress = address;       /* SBSW_Fee_30_FlexNor_Factory */
    chunkToCreate->Data.ReallocationRequired = FALSE; /* SBSW_Fee_30_FlexNor_Factory */
}

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * Fee_30_FlexNor_ChunkFactory_CreateChunk()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_ChunkFactory_CreateChunk(
    Fee_30_FlexNor_AddressType address,
    Fee_30_FlexNor_PartitionIdType partitionId,
    Fee_30_FlexNor_SectorIdType sectorId,
    Fee_30_FlexNor_ChunkPtrType chunkToCreate)
{
    Fee_30_FlexNor_ChunkFactory_CreateGeneralPartOfChunk(address, partitionId, sectorId, chunkToCreate); /* SBSW_Fee_30_FlexNor_Factory */

#if ((FEE_30_FLEXNOR_SECURELAYOUT_ENABLED == STD_ON) && (FEE_30_FLEXNOR_SLIMLAYOUT_ENABLED == STD_ON)) /* COV_FEE_30_FLEXNOR_MULTIPLE_OPTIONAL_UNITS */
    if (Fee_30_FlexNor_ConfigInterface_GetPartitionLayout(partitionId) == FEE_30_FLEXNOR_SECURELAYOUT)
    {
#endif
#if (FEE_30_FLEXNOR_SECURELAYOUT_ENABLED == STD_ON) /* COV_MSR_UT_OPTIONAL_UNIT */
        Fee_30_FlexNor_ChunkFactory_CreateSecurePartOfChunk(chunkToCreate); /* SBSW_Fee_30_FlexNor_Factory */
#endif
#if ((FEE_30_FLEXNOR_SECURELAYOUT_ENABLED == STD_ON) && (FEE_30_FLEXNOR_SLIMLAYOUT_ENABLED == STD_ON)) /* COV_FEE_30_FLEXNOR_MULTIPLE_OPTIONAL_UNITS */
    }
    else
    {
#endif
#if (FEE_30_FLEXNOR_SLIMLAYOUT_ENABLED == STD_ON) /* COV_MSR_UT_OPTIONAL_UNIT */
        Fee_30_FlexNor_ChunkFactory_CreateSlimPartOfChunk(chunkToCreate); /* SBSW_Fee_30_FlexNor_Factory */
#endif
#if ((FEE_30_FLEXNOR_SECURELAYOUT_ENABLED == STD_ON) && (FEE_30_FLEXNOR_SLIMLAYOUT_ENABLED == STD_ON)) /* COV_FEE_30_FLEXNOR_MULTIPLE_OPTIONAL_UNITS */
    }
#endif
}

#define FEE_30_FLEXNOR_STOP_SEC_CODE
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: Fee_30_FlexNor_ChunkFactory.c
 *********************************************************************************************************************/
