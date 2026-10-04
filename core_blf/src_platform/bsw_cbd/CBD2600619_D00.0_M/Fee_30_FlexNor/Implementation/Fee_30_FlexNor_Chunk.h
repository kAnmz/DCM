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
/*!        \file  Fee_30_FlexNor_Chunk.h
 *        \brief  Generic chunk interface
 *      \details  Provides the chunk definition and layout independent services.
 *         \unit  Chunk
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 **********************************************************************************************************************/

#if !defined(FEE_30_FLEXNOR_CHUNK_H)
#define FEE_30_FLEXNOR_CHUNK_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Fee_30_FlexNor_Types.h"
#include "Fee_30_FlexNor_Instance.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum
{
    FEE_30_FLEXNOR_CHUNK_ERROR_STARTMARKER,     /*!< Chunk is invalid because of faulty start marker */
    FEE_30_FLEXNOR_CHUNK_ERROR_PROPERTIES,      /*!< Chunk is invalid because of faulty properties */
    FEE_30_FLEXNOR_CHUNK_ERROR_COMMITMARKER,    /*!< Chunk is invalid because of faulty commit marker */
    FEE_30_FLEXNOR_CHUNK_ERROR_NOERROR          /*!< Chunk is correct */
}Fee_30_FlexNor_Chunk_ErrorLocation;

typedef enum 
{
    FEE_30_FLEXNOR_INSTANCESEARCH_OK,                      /*!< Instance search finished successfully - valid instance found. */
    FEE_30_FLEXNOR_INSTANCESEARCH_PENDING,                 /*!< Instance search is pending. */
    FEE_30_FLEXNOR_INSTANCESEARCH_FAIL,                    /*!< Instance search failed. */
    FEE_30_FLEXNOR_INSTANCESEARCH_NO_VALID_INSTANCE_FOUND  /*!< No valid instance was found in the current chunk. */
} Fee_30_FlexNor_Chunk_InstanceSearchResultType;     /*!< Result type for the instance search. */

typedef uint16 Fee_30_FlexNor_InstanceCountType;
typedef uint16 Fee_30_FlexNor_ChunkInstanceIndex;

typedef struct
{
    Fee_30_FlexNor_ChunkLocationType Target;       	    /*!< Link containing the target sector and the address of the chunk */
    Fee_30_FlexNor_StructureValidityType Validity;      /*!< Information containing the validity of the structure */
} Fee_30_FlexNor_ChunkLinkType;                         /*!< Structure which holds all information about a chunk link */

typedef struct
{
    Fee_30_FlexNor_StructureValidityType Validity;              /*!< Information containing the validity of the structure */
    Fee_30_FlexNor_Chunk_ErrorLocation ErrorLocation;           /*!< Describes the location of an error in case of an invalid chunk */
    Fee_30_FlexNor_StructureFlagsType ReallocationRequired;     /*!< Indicates if the chunk needs a reallocation */
    Fee_30_FlexNor_PartitionIdType PartitionId;                 /*!< Id of the partition the chunk belongs to */
    Fee_30_FlexNor_SectorIdType SectorId;                       /*!< Id of the sector the chunk belongs to */
    Fee_30_FlexNor_BlockIdType BlockId;                         /*!< Id of the block the chunk belongs to */
    Fee_30_FlexNor_PayloadSizeType PayloadSize;                 /*!< Size of the payload in each contained instance */
    Fee_30_FlexNor_InstanceCountType InstanceCount;             /*!< Number of instances in the chunk */
    Fee_30_FlexNor_AddressType StartAddress;                    /*!< Start address of the chunk in flash */
    Fee_30_FlexNor_ChunkLinkType ChunkLink;                     /*!< Link to the successor chunk */
} Fee_30_FlexNor_ChunkDataType;                                 /*!< Structure which holds all public data */

typedef P2VAR(Fee_30_FlexNor_ChunkDataType, AUTOMATIC, FEE_30_FLEXNOR_VAR) Fee_30_FlexNor_ChunkDataPtrType;
typedef P2CONST(Fee_30_FlexNor_ChunkDataType, AUTOMATIC, FEE_30_FLEXNOR_VAR) Fee_30_FlexNor_ConstChunkDataPtrType;

typedef P2VAR(struct Fee_30_FlexNor_Chunk, AUTOMATIC, FEE_30_FLEXNOR_VAR) Fee_30_FlexNor_ChunkPtrType;
typedef P2CONST(struct Fee_30_FlexNor_Chunk, AUTOMATIC, FEE_30_FLEXNOR_VAR) Fee_30_FlexNor_ConstChunkPtrType;

/* Service function pointers */
typedef P2FUNC(void, AUTOMATIC, Fee_30_FlexNor_Chunk_ReadHeaderPtr)(Fee_30_FlexNor_ChunkPtrType chunk, 
    Fee_30_FlexNor_ResultCallback resultCbk);

typedef P2FUNC(void, AUTOMATIC, Fee_30_FlexNor_Chunk_AllocatePtr)(
    Fee_30_FlexNor_ConstChunkPtrType chunk,
    Fee_30_FlexNor_ChunkPtrType predecessorChunk,
    Fee_30_FlexNor_ConstInstancePtrType sourceInstance,
    Fee_30_FlexNor_InstancePtrType targetInstance,
    Fee_30_FlexNor_ResultCallback resultCbk);

typedef P2FUNC(void, AUTOMATIC, Fee_30_FlexNor_Chunk_WriteLinkPtr)(Fee_30_FlexNor_ChunkPtrType chunk, 
    Fee_30_FlexNor_ConstChunkPtrType targetChunk, 
    Fee_30_FlexNor_ResultCallback resultCbk);

typedef P2FUNC(uint32, AUTOMATIC, Fee_30_FlexNor_Chunk_GetTotalSizePtr)(Fee_30_FlexNor_ConstChunkPtrType chunk);
typedef P2FUNC(uint32, AUTOMATIC, Fee_30_FlexNor_Chunk_GetHeaderSizePtr)(Fee_30_FlexNor_ConstChunkPtrType chunk);
typedef P2FUNC(void, AUTOMATIC, Fee_30_FlexNor_Chunk_FindLatestValidInstancePtr)(Fee_30_FlexNor_ChunkPtrType chunk, 
    Fee_30_FlexNor_InstancePtrType instance, Fee_30_FlexNor_ResultCallback resultCbk);
typedef P2FUNC(Fee_30_FlexNor_Chunk_InstanceSearchResultType, AUTOMATIC, 
    Fee_30_FlexNor_Chunk_GetJobResultOfInstanceSearchPtr)(void);
typedef P2FUNC(void, AUTOMATIC, Fee_30_FlexNor_Chunk_TryAllocateInstancePtr)(Fee_30_FlexNor_ChunkPtrType chunk, 
    Fee_30_FlexNor_InstancePtrType instance, Fee_30_FlexNor_ResultCallback resultCbk);

typedef struct
{
    Fee_30_FlexNor_Chunk_ReadHeaderPtr ReadHeader;                                     /*!< Pointer to the read header service of the chunk */
    Fee_30_FlexNor_Chunk_AllocatePtr Allocate;                                         /*!< Pointer to the allocate service of the chunk */
    Fee_30_FlexNor_Chunk_WriteLinkPtr WriteLink;                                       /*!< Pointer to the write link service of the chunk */
    Fee_30_FlexNor_Chunk_GetTotalSizePtr GetTotalSize;                                 /*!< Pointer to the get total size service of the chunk */
    Fee_30_FlexNor_Chunk_GetHeaderSizePtr GetHeaderSize;                               /*!< Pointer to the get header size service of the chunk */
    Fee_30_FlexNor_Chunk_FindLatestValidInstancePtr FindLatestValidInstance;           /*!< Pointer to the find latest valid instance service of the chunk */
    Fee_30_FlexNor_Chunk_GetJobResultOfInstanceSearchPtr GetJobResultOfInstanceSearch; /*!< Pointer to the get job result of instance search service of the chunk */
    Fee_30_FlexNor_Chunk_TryAllocateInstancePtr TryAllocateInstance;                   /*!< Pointer to the try allocate instance service of the chunk */
} Fee_30_FlexNor_ChunkServicesType;                                                    /*!< Structure which holds all public services a chunk offers */

typedef struct Fee_30_FlexNor_Chunk
{
    Fee_30_FlexNor_ChunkDataType Data;         /*!< Properties of the chunk */
    Fee_30_FlexNor_ChunkServicesType Services; /*!< Services the chunk offers */
} Fee_30_FlexNor_ChunkType;                    /*!< Structure which holds all public data and services */

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define FEE_30_FLEXNOR_START_SEC_CODE
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Fee_30_FlexNor_Chunk_Init()
 *********************************************************************************************************************/
/*! \brief       Initialize the chunk unit
 *  \details     -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Chunk_Init(void);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Chunk_FindLatestValidInstance()
 *********************************************************************************************************************/
/*! \brief           Searches the last valid instance in a given chunk.
 *  \details         -
 *  \param[in]       chunk              Chunk in which to search the instance. Must not be NULL.
 *  \param[in,out]   instance           Instance where the returned valid instance shall be stored. Must not be NULL.
 *  \param[in]       resultCbk          The result call back that is called in case the service is complete. Must not be 
 *                                      NULL.
 *  \pre             Chunk must be valid.
 *  \context         TASK
 *  \reentrant       FALSE
 *  \synchronous     FALSE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Chunk_FindLatestValidInstance(
    Fee_30_FlexNor_ChunkPtrType chunk, 
    Fee_30_FlexNor_InstancePtrType instance, 
    Fee_30_FlexNor_ResultCallback resultCbk);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Chunk_GetJobResultOfInstanceSearch()
 *********************************************************************************************************************/
/*! \brief           Get the result of the latest instance search.
 *  \details         -
 *  \return          FEE_30_FLEXNOR_INSTANCESEARCH_OK                 
 *                   FEE_30_FLEXNOR_INSTANCESEARCH_PENDING
 *                   FEE_30_FLEXNOR_INSTANCESEARCH_NO_VALID_INSTANCE_FOUND   
 *  \pre             -
 *  \context         TASK
 *  \reentrant       FALSE
 *  \synchronous     FALSE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_Chunk_InstanceSearchResultType, FEE_30_FLEXNOR_CODE) 
    Fee_30_FlexNor_Chunk_GetJobResultOfInstanceSearch(void);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Chunk_TryAllocateInstance()
 *********************************************************************************************************************/
/*! \brief       Tries to allocate an instance in a given chunk.
 *  \details     Searches the next empty slot in the given chunk and if there is space left, it will allocate an 
 *               instance.
 *  \param[in]   chunk              Chunk in which to allocate the instance. Must not be NULL.
 *  \param[in]   instance           Instance which shall be allocated. Must not be NULL.
 *  \param[in]   resultCbk          The result call back that is called in case the service is complete. Must not be 
 *                                  NULL.
 *  \pre         Chunk must be valid.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous FALSE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Chunk_TryAllocateInstance(
    Fee_30_FlexNor_ChunkPtrType chunk, 
    Fee_30_FlexNor_InstancePtrType instance, 
    Fee_30_FlexNor_ResultCallback resultCbk);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Chunk_WriteLink()
 *********************************************************************************************************************/
/*! \brief       Writes a link to the given chunk.
 *  \details     Writes the stored chunk link of the given chunk into the flash.
 *  \param[in]   chunk              Chunk data that shall be used for the allocation. Must not be NULL.
 *  \param[in]   targetChunk        Chunk to which the link will point to. Must not be NULL.
 *  \param[in]   resultCbk          The result call back that is called in case the service is complete. Must not be 
 *                                  NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous FALSE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Chunk_WriteLink(
    Fee_30_FlexNor_ChunkPtrType chunk, 
    Fee_30_FlexNor_ConstChunkPtrType targetChunk, 
    Fee_30_FlexNor_ResultCallback resultCbk);

#define FEE_30_FLEXNOR_STOP_SEC_CODE
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* FEE_30_FLEXNOR_CHUNK_H */

/**********************************************************************************************************************
 *  END OF FILE: Fee_30_FlexNor_Chunk.h
 *********************************************************************************************************************/
