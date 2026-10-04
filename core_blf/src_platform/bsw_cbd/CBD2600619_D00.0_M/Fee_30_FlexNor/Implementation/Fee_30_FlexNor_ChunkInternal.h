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
/*!        \file  Fee_30_FlexNor_ChunkInternal.h
 *        \brief  Internal chunk business logic prototypes
 *      \details  Provides the internal prototypes for the business logic of the chunk implementation.
 *         \unit  Chunk
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 **********************************************************************************************************************/

#if !defined(FEE_30_FLEXNOR_CHUNKINTERNAL_H)
#define FEE_30_FLEXNOR_CHUNKINTERNAL_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Fee_30_FlexNor_Chunk.h"
#include "Fee_30_FlexNor_Types.h"
#include "Fee_30_FlexNor_ConfigInterface.h"
#include "Fee_30_FlexNor_FlashAccess.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

#define FEE_30_FLEXNOR_INVALID_INDEX 0xFFFFu

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum
{
    FEE_30_FLEXNOR_CHUNK_INSTANCESEARCH,    /*!< Search for the latest valid instance */
    FEE_30_FLEXNOR_CHUNK_INSTANCEALLOCATION /*!< Try to allocate a new instance in the chunk */
} Fee_30_FlexNor_ChunkJobType;

typedef enum
{
    FEE_30_FLEXNOR_SEARCH_EMPTY, /*!< Search shall return the first empty instance */
    FEE_30_FLEXNOR_SEARCH_VALID  /*!< Search shall return the last valid instance */
} Fee_30_FlexNor_InstanceSearchType;

typedef enum
{
    FEE_30_FLEXNOR_SEARCH_PENDING, /*!< Search is ongoing. */
    FEE_30_FLEXNOR_SEARCH_ABORTED, /*!< Search (binary) is aborted due to invalid instance, linear search is necessary. */
    FEE_30_FLEXNOR_SEARCH_FINISHED /*!< Search is finished. */
} Fee_30_FlexNor_InstanceSearchStatus;

typedef enum
{
    FEE_30_FLEXNOR_CHUNK_VALIDATION_AS_WHOLE,         /*!< The whole chunk header lies in the buffer. */
    FEE_30_FLEXNOR_CHUNK_VALIDATION_AS_SINGLE_PARTS   /*!< The individual single parts of the chunk header  */
} Fee_30_FlexNor_ChunkHeaderValidationStrategy;

typedef P2VAR(struct Fee_30_FlexNor_SearchContext, AUTOMATIC, FEE_30_FLEXNOR_VAR) 
    Fee_30_FlexNor_Chunk_SearchContextPtrType;
typedef P2VAR(struct Fee_30_FlexNor_Chunk_Context, AUTOMATIC, FEE_30_FLEXNOR_VAR) 
    Fee_30_FlexNor_Chunk_ContextPtrType;
typedef P2CONST(struct Fee_30_FlexNor_Chunk_Context, AUTOMATIC, FEE_30_FLEXNOR_VAR) 
    Fee_30_FlexNor_Chunk_ConstContextPtrType;
typedef P2FUNC(void, AUTOMATIC, Fee_30_FlexNor_Chunk_InitializeFunctionPtrType)(
    Fee_30_FlexNor_Chunk_ContextPtrType ctx);

/* Module state */
typedef P2FUNC(Fee_30_FlexNor_ScheduleBehaviorType, AUTOMATIC, Fee_30_FlexNor_Chunk_ProcessEvt)(
    Fee_30_FlexNor_Chunk_ContextPtrType ctx);
typedef P2FUNC(void, AUTOMATIC, Fee_30_FlexNor_Chunk_FailEvt)(
    Fee_30_FlexNor_Chunk_ContextPtrType ctx);

typedef struct Fee_30_FlexNor_Chunk_State
{
    Fee_30_FlexNor_Chunk_ProcessEvt ProcessEvent; /*!< Pointer to the handler for the process event of the state */
    Fee_30_FlexNor_Chunk_FailEvt FailEvent;       /*!< Pointer to the handler for the fail event of the state */
} Fee_30_FlexNor_Chunk_StateType;                 /*!< Represents a state of the internal unit state machine */

typedef CONST(Fee_30_FlexNor_Chunk_StateType, AUTOMATIC) Fee_30_FlexNor_Chunk_ConstStateType;
typedef P2CONST(Fee_30_FlexNor_Chunk_StateType, AUTOMATIC, FEE_30_FLEXNOR_VAR) Fee_30_FlexNor_Chunk_ConstStatePtrType;

typedef struct Fee_30_FlexNor_SearchContext
{
    Fee_30_FlexNor_ChunkInstanceIndex StartIndex;     /*!< Index where the search shall start its search each iteration */
    Fee_30_FlexNor_ChunkInstanceIndex EndIndex;       /*!< Index where the search shall end its search each iteration */
    Fee_30_FlexNor_ChunkInstanceIndex CurrentIndex;   /*!< Index where the search is currently searching */
    Fee_30_FlexNor_ChunkInstanceIndex ValidIndex;     /*!< Index where a possible valid instance was found */
    Fee_30_FlexNor_InstanceSearchStatus SearchStatus; /*!< Status of the search */
} Fee_30_FlexNor_SearchContextType;

/* Module context */
typedef struct Fee_30_FlexNor_Chunk_Context
{
    boolean AllocationSuccessful;                                       /*!< Flag which indicates that the allocation of a new instance was successful */
    Fee_30_FlexNor_Chunk_ConstStatePtrType CurrentState;                /*!< Current state of the state machine */

    Fee_30_FlexNor_ConstChunkPtrType ConstChunk;                        /*!< Const chunk that is used to store given const chunk pointers
                                                                             the TryAllocateInstance and FindLatestValidInstance services operate on. */
    Fee_30_FlexNor_ChunkPtrType Chunk;                                  /*!< Chunk that is used for the WriteLink service. The const chunk can't be used
                                                                             because the written link is also copied to the given chunk whose link is written. */
    Fee_30_FlexNor_InstancePtrType InstanceToCheck;                     /*!< Current instance to check in the search */
    Fee_30_FlexNor_ResultCallback ResultCallback;                       /*!< Result callback that is used to communicate the service result back to the caller. */

    Fee_30_FlexNor_ChunkJobType ChunkJob;                               /*!< Stores the currently running chunk job */
    Fee_30_FlexNor_InstanceSearchType SearchType;                       /*!< Type of instance the search shall return */
    Fee_30_FlexNor_SearchContextType SearchContext;                     /*!< Context which stores the current information needed for the search */

    Fee_30_FlexNor_ConstPartitionConfigPtrType PartitionConfig;         /*!< Pointer to the partition configuration of the processed chunk. */
    Fee_30_FlexNor_DataPtrType ChunkBuffer;                             /*!< Internal buffer to store the chunk header (metadata + link) data read from flash. */
    Fee_30_FlexNor_Chunk_InstanceSearchResultType InstanceSearchResult; /*!< Result of the latest instance search. */
} Fee_30_FlexNor_Chunk_ContextType;                                     /*!< Represents the context for the internal state machine of the unit */

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
# define FEE_30_FLEXNOR_START_SEC_CODE
# include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Fee_30_FlexNor_Chunk_StartJob()
 *********************************************************************************************************************/
/*! \brief       Start a job for the unit
 *  \details     Registers the unit at the scheduler to start the asynchronous processing for the unit.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Chunk_StartJob(void);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Chunk_EndJob()
 *********************************************************************************************************************/
/*! \brief       Ends a job for the unit
 *  \details     Unregisters the unit from the scheduler.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Chunk_EndJob(void);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Chunk_ResultHandler()
 *********************************************************************************************************************/
/*! \brief       Handles the result of a called service
 *  \details     This function is used as a result callback for services called by this unit.
 *  \param[in]   result               Result of the called service
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Chunk_ResultHandler(Fee_30_FlexNor_ServiceResult result);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Chunk_GetAlignedLinkSize()
 *********************************************************************************************************************/
/*! \brief       Gets the aligned size of the chunk link
 *  \details     -
 *  \param[in]   alignment   Target alignment for the link size
 *  \return      The aligned size of the chunk link
 *  \pre         -
 *  \context     TASK
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(uint32, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Chunk_GetAlignedLinkSize(uint16 alignment);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Chunk_ValidateInstanceAt()
 *********************************************************************************************************************/
/*! \brief       Validates the instance at given index.
 *  \details     Reads and validates the instance at given index.
 *  \param[in]   index            Index of the instance to validate.
 *  \param[in]   chunk            Context that contains the read chunk header that shall be validated. Must not be NULL.
 *  \param[out]  instance        Pointer to the instance to validate. Must not be NULL.
 *  \param[in]   resultCbk       Pointer to the result handler for called services. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Chunk_ValidateInstanceAt(
    Fee_30_FlexNor_ChunkInstanceIndex index,
    Fee_30_FlexNor_ConstChunkPtrType chunk,
    Fee_30_FlexNor_InstancePtrType instance,
    Fee_30_FlexNor_ResultCallback resultCbk);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Chunk_WriteInstanceAt()
 *********************************************************************************************************************/
/*! \brief       Writes the given instance to the slot defined by the given target index
 *  \details     -
 *  \param[in]   targetIndex            Index of the slot the instance shall be written to.
 *  \param[in]   chunk                  Chunk the instance shall be written to. Must not be NULL.
 *  \param[in]   sourceInstance         Pointer to the source instance whose payload is copied to the instance that 
 *                                      shall be written.
 *                                      If NULL, the payload from the given targetInstance is written directly.
 *  \param[in]   targetInstance         Pointer to the target instance that is written. Must not be NULL.
 *  \param[in]   resultCbk              Pointer to the result handler for called services. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Chunk_WriteInstanceAt(
    Fee_30_FlexNor_ChunkInstanceIndex targetIndex,
    Fee_30_FlexNor_ConstChunkPtrType chunk,
    Fee_30_FlexNor_ConstInstancePtrType sourceInstance,
    Fee_30_FlexNor_InstancePtrType targetInstance,
    Fee_30_FlexNor_ResultCallback resultCbk);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Chunk_SearchInstance()
 *********************************************************************************************************************/
/*! \brief       Searches for an instance inside of a chunk with the given search type
 *  \details     -
 *  \param[in]   searchType             Signifies whether the instance shall be empty or valid.
 *  \param[in]   jobType                Specifies the type of chunk job that is currently being executed.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Chunk_SearchInstance(
    Fee_30_FlexNor_InstanceSearchType searchType,
    Fee_30_FlexNor_ChunkJobType jobType);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Chunk_DoBinarySearchStep()
 *********************************************************************************************************************/
/*! \brief       Executes a single step of the binary search
 *  \details     -
 *  \param[in,out]  ctx     Pointer to the context for the search processing. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Chunk_DoBinarySearchStep(Fee_30_FlexNor_Chunk_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Chunk_EvaluateBinarySearchEmpty()
 *********************************************************************************************************************/
/*! \brief       Evaluates how the binary search needs to progress based on the validated instance
 *  \details     -
 *  \param[in,out]  ctx     Pointer to the context for the search processing. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Chunk_EvaluateBinarySearchEmpty(Fee_30_FlexNor_Chunk_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Chunk_EvaluateBinarySearchValid()
 *********************************************************************************************************************/
/*! \brief       Evaluates how the binary search needs to progress based on the validated instance
 *  \details     -
 *  \param[in,out]  ctx     Pointer to the context for the search processing. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Chunk_EvaluateBinarySearchValid(Fee_30_FlexNor_Chunk_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Chunk_SetupFoundInstance()
 *********************************************************************************************************************/
/*! \brief       Responsible for setting up the instance based on the found valid instance index
 *  \details     -
 *  \param[in]   ctx     Pointer to the context for the read instance processing. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Chunk_SetupFoundInstance(Fee_30_FlexNor_Chunk_ConstContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Chunk_DoLinearSearchStep()
 *********************************************************************************************************************/
/*! \brief       Executes a single step of the linear search
 *  \details     -
 *  \param[in,out]  ctx     Pointer to the context for the search processing. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Chunk_DoLinearSearchStep(Fee_30_FlexNor_Chunk_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Chunk_EvaluateLinearSearchValid()
 *********************************************************************************************************************/
/*! \brief       Evaluates how the linear search needs to progress based on the validated instance
 *  \details     -
 *  \param[in,out]  ctx     Pointer to the context for the search processing. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Chunk_EvaluateLinearSearchValid(Fee_30_FlexNor_Chunk_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_AllocateInstance()
 *********************************************************************************************************************/
/*! \brief       Executes the instance allocation
 *  \details     -
 *  \param[in,out]  ctx     Pointer to the context for the search processing. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Chunk_AllocateInstance(Fee_30_FlexNor_Chunk_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Chunk_BuildLink()
 *********************************************************************************************************************/
/*! \brief       Builds the link to the successor chunk
 *  \details     The relative link that is written to flash is built from the sector id of the successor chunk and its
 *               relative start address.
 *  \param[in]   ctx                Context that contains the chunk the calculated link is stored in as well as the
 *                                  successor chunk the link is built from. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Chunk_BuildLink(Fee_30_FlexNor_Chunk_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Chunk_WriteLinkToMemory()
 *********************************************************************************************************************/
/*! \brief       Writes the chunk link to flash
 *  \details     -
 *  \param[in]   ctx               Context that contains the (predecessor) chunk whose chunk link shall be written
 *                                 and the target chunk. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Chunk_WriteLinkToMemory(Fee_30_FlexNor_Chunk_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Chunk_ReadMarker()
 *********************************************************************************************************************/
/*! \brief       Reads the wanted marker from flash.
 *  \details     -
 *  \param[in,out]   chunkbuffer   Buffer that can be used as target for the reading. Must not be NULL.
 *  \param[in]       chunk         Chunk object for the reading. Must not be NULL.
 *  \param[in]       markerOffset  Offset of the marker in relation to the chunk header start address.
 *  \param[in]       cfg           Configuration of the involved partition.
 *  \param[in]       cbk           Result callback of the calling concrete chunk module.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Chunk_ReadMarker(
    Fee_30_FlexNor_DataPtrType chunkBuffer,
    Fee_30_FlexNor_ConstChunkPtrType chunk,
    Fee_30_FlexNor_AddressType markerOffset,
    Fee_30_FlexNor_ConstPartitionConfigPtrType cfg,
    Fee_30_FlexNor_ResultCallback cbk);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Chunk_ReadProperties()
 *********************************************************************************************************************/
/*! \brief       Reads the chunk header properties from flash.
 *  \details     -
 *  \param[in,out]   chunkBuffer   Buffer that can be used as target for the reading. Must not be NULL.
 *  \param[in]       chunk         Chunk object for the reading. Must not be NULL.
 *  \param[in]       propertiesOffset  Offset of the properties in relation to the chunk header start address.
 *  \param[in]       cfg           Configuration of the involved partition.
 *  \param[in]       cbk           Result callback of the calling concrete chunk module.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Chunk_ReadProperties(
    Fee_30_FlexNor_DataPtrType chunkBuffer,
    Fee_30_FlexNor_ConstChunkPtrType chunk,
    Fee_30_FlexNor_AddressType propertiesOffset,
    Fee_30_FlexNor_ConstPartitionConfigPtrType cfg,
    Fee_30_FlexNor_ResultCallback cbk
);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Chunk_ValidateProperties()
 *********************************************************************************************************************/
/*! \brief       Validates the chunk header properties
 *  \details     -
 *  \param[in]     chunkbuffer         Buffer that contains the just read properties. Must not be NULL.
 *  \param[in,out] chunk               Chunk object for the validating. Must not be NULL.
 *  \param[in]     propertiesOffset    Offset of the properties in relation to the chunk header start address.
 *  \param[in]     cfg                 Partition configuration. Must not be NULL.
 *  \return      Validity of the structure
 *  \pre         Chunk header properties must have been read from flash.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_StructureValidityType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Chunk_ValidateProperties(
    Fee_30_FlexNor_ConstDataPtrType chunkBuffer,
    Fee_30_FlexNor_ChunkPtrType chunk,
    Fee_30_FlexNor_AddressType propertiesOffset,
    Fee_30_FlexNor_ConstPartitionConfigPtrType cfg);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Chunk_ReadLink()
 *********************************************************************************************************************/
/*! \brief       Reads the link from flash
 *  \details     -
 *  \param[in,out]   chunkbuffer   Buffer that can be used as target for the reading. Must not be NULL.
 *  \param[in]       chunk         Chunk object for the reading. Must not be NULL.
 *  \param[in]       linkOffset    Offset of the link in relation to the chunk header start address.
 *  \param[in]       cfg           Configuration of the involved partition.
 *  \param[in]       cbk           Result callback of the calling concrete chunk module.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Chunk_ReadLink(
    Fee_30_FlexNor_DataPtrType chunkBuffer,
    Fee_30_FlexNor_ConstChunkPtrType chunk,
    Fee_30_FlexNor_AddressType linkOffset,
    Fee_30_FlexNor_ConstPartitionConfigPtrType cfg,
    Fee_30_FlexNor_ResultCallback cbk);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Chunk_ValidateLink()
 *********************************************************************************************************************/
/*! \brief       Validates the link
 *  \details     -
 *  \param[in]     chunkbuffer   Buffer that contains the just read link. Must not be NULL.
 *  \param[in,out] chunk         Chunk object for the validating. Must not be NULL.
 *  \param[in]     linkOffset    Offset of the link in relation to the chunk header start address.
 *  \param[in]     cfg           Configuration of the involved partition.
 *  \return      Validity of the structure
 *  \pre         Link must have been read from flash.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_StructureValidityType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Chunk_ValidateLink(
    Fee_30_FlexNor_ConstDataPtrType chunkBuffer,
    Fee_30_FlexNor_ChunkPtrType chunk,
    Fee_30_FlexNor_AddressType linkOffset,
    Fee_30_FlexNor_ConstPartitionConfigPtrType cfg);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Chunk_GetChunkPropertiesSize()
 *********************************************************************************************************************/
/*! \brief       Gets the accumulated unaligend size of the chunk properties.
 *  \details     -
 *  \return      The aligned size of the header data
 *  \pre         -
 *  \context     TASK
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(uint32, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Chunk_GetChunkPropertiesSize(void);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Chunk_RequestRecoveryGarbageCollection
 *********************************************************************************************************************/
/*! \brief       Requests recovery garbage collection.
 *  \details     -
 *  \param[in]   partitionId    Id of the partition that contains the sector that shall be recovered
 *  \param[in]   address        Address within the sector that shall be recovered
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Chunk_RequestRecoveryGarbageCollection(
    Fee_30_FlexNor_PartitionIdType partitionId,
    Fee_30_FlexNor_AddressType address);

#define FEE_30_FLEXNOR_STOP_SEC_CODE
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* FEE_30_FLEXNOR_CHUNKINTERNAL_H */

/**********************************************************************************************************************
 *  END OF FILE: Fee_30_FlexNor_ChunkInternal.h
 *********************************************************************************************************************/
