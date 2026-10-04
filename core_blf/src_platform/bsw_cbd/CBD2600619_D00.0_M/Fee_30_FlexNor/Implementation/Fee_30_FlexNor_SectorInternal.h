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
/*!        \file  Fee_30_FlexNor_SectorInternal.h
 *        \brief  Internal sector business logic prototypes
 *      \details  Provides the internal prototypes for the business logic of the sector implementation.
 *         \unit  Sector
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 **********************************************************************************************************************/

#if !defined (FEE_30_FLEXNOR_SECTORINTERNAL_H)
# define FEE_30_FLEXNOR_SECTORINTERNAL_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Fee_30_FlexNor_Sector.h"
#include "Fee_30_FlexNor_Types.h"
#include "Fee_30_FlexNor_ConfigInterface.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define FEE_30_FLEXNOR_SECTOR_INVALID_INSTANCE_COUNT 0u

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef P2VAR(struct Fee_30_FlexNor_Sector_Context, AUTOMATIC, FEE_30_FLEXNOR_VAR) Fee_30_FlexNor_Sector_ContextPtrType;
typedef P2CONST(struct Fee_30_FlexNor_Sector_Context, AUTOMATIC, FEE_30_FLEXNOR_VAR) Fee_30_FlexNor_Sector_ConstContextPtrType;

/* Module state */
typedef P2FUNC(Fee_30_FlexNor_ScheduleBehaviorType, AUTOMATIC, Fee_30_FlexNor_Sector_ProcessEvt)(Fee_30_FlexNor_Sector_ContextPtrType ctx);
typedef P2FUNC(void, AUTOMATIC, Fee_30_FlexNor_Sector_FailEvt)(Fee_30_FlexNor_Sector_ContextPtrType ctx);

typedef struct Fee_30_FlexNor_Sector_State
{
    Fee_30_FlexNor_Sector_ProcessEvt ProcessEvent;     /*!< Pointer to the handler for the process event of the state */
    Fee_30_FlexNor_Sector_FailEvt FailEvent;           /*!< Pointer to the handler for the fail event of the state */
} Fee_30_FlexNor_Sector_StateType;                     /*!< Represents a state of the internal unit state machine */

typedef CONST(Fee_30_FlexNor_Sector_StateType, AUTOMATIC) Fee_30_FlexNor_Sector_ConstStateType;
typedef P2CONST(Fee_30_FlexNor_Sector_StateType, AUTOMATIC, FEE_30_FLEXNOR_VAR) Fee_30_FlexNor_Sector_ConstStatePtrType;

/* Module context */
typedef struct Fee_30_FlexNor_Sector_Context
{
    Fee_30_FlexNor_Sector_ConstStatePtrType CurrentState;           /*!< Current state of the state machine */
    
    Fee_30_FlexNor_SectorPtrType Sector;                            /*!< Sector to operates on */
    Fee_30_FlexNor_DataPtrType SectorBuffer;                        /*!< Internal buffer to store the sector header data read from flash. */
    Fee_30_FlexNor_AddressType TemporaryNextFreeAddress;            /*!< Temporary next free address during the sector scan. */

    Fee_30_FlexNor_ChunkPtrType Chunk;                              /*!< Pointer to the chunk that is being used for chunk operations depending on the currently executed service. */
    Fee_30_FlexNor_ConstInstancePtrType SourceInstance;             /*!< Pointer to the source instance whose payload is copied to a newly allocated chunk. */
    Fee_30_FlexNor_InstancePtrType TargetInstance;                  /*!< Pointer to the target instance that is used to write the first instance to a newly allocated chunk. */
    Fee_30_FlexNor_ChunkPtrType PredecessorChunk;                   /*!< Pointer to the predecessor of the chunk that shall be allocated. */
    Fee_30_FlexNor_ResultCallback ResultCallback;                   /*!< Result callback that is used to communicate the service result back to the caller. */
    boolean resetInstanceCount;                                     /*!< Flag indicating whether the instance count shall be reset */
    Fee_30_FlexNor_SectorIdType SourceSectorId;                     /*!< Id of the source sector, which is used for Garbage Collection */
} Fee_30_FlexNor_Sector_ContextType;                                /*!< Represents the context for the internal state machine of the unit */

typedef enum
{
    FEE_30_FLEXNOR_SECTOR_SCAN_CONTINUE,                            /*!< Sector Scan is not over yet */
    FEE_30_FLEXNOR_SECTOR_SCAN_FINISHED                             /*!< Sector Scan is over */
}Fee_30_FlexNor_Sector_ScanCurrentResult;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
# define FEE_30_FLEXNOR_START_SEC_CODE
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_StartJob()
 *********************************************************************************************************************/
/*! \brief       Start a job for the unit
 *  \details     Registers the unit at the scheduler to start the asynchronous processing for the unit.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_StartJob(void);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_EndJob()
 *********************************************************************************************************************/
/*! \brief       Ends a job for the unit
 *  \details     Unregisters the unit from the scheduler.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_EndJob(void);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ResultHandler()
 *********************************************************************************************************************/
/*! \brief       Handles the result of a called service
 *  \details     This function is used as a result callback for services called by this unit.
 *  \param[in]   result               Result of the called service
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ResultHandler(Fee_30_FlexNor_ServiceResult result);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ReadMetadata()
 *********************************************************************************************************************/
/*! \brief         Request reading the sector header meta data from flash access layer and store them in given buffer.
 *  \details       -
 *  \param[in,out] ctx               Context that contains the sector whose header shall be read. Must not be NULL.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ReadMetadata(Fee_30_FlexNor_Sector_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ReadAdditionalInfo()
 *********************************************************************************************************************/
/*! \brief         Request reading the sector header additional info from flash access layer and store them in given buffer.
 *  \details       -
 *  \param[in,out] ctx               Context that contains the sector whose header shall be read. Must not be NULL.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ReadAdditionalInfo(Fee_30_FlexNor_Sector_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ReadEraseMarker()
 *********************************************************************************************************************/
/*! \brief         Request reading the sector erase marker from flash access layer and store them in given buffer.
 *  \details       -
 *  \param[in,out] ctx               Context that contains the sector whose header shall be read. Must not be NULL.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ReadEraseMarker(Fee_30_FlexNor_Sector_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ReadProperties()
 *********************************************************************************************************************/
/*! \brief         Request reading the sector properties from flash access layer and store them in given buffer.
 *  \details       -
 *  \param[in,out] ctx               Context that contains the sector whose header shall be read. Must not be NULL.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ReadProperties(Fee_30_FlexNor_Sector_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ReadCommitMarker()
 *********************************************************************************************************************/
/*! \brief         Request reading the sector header commit marker from flash access layer and store them in given buffer.
 *  \details       -
 *  \param[in,out] ctx               Context that contains the sector whose header commit marker shall be read. Must not be NULL.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ReadCommitMarker(Fee_30_FlexNor_Sector_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ReadSealMarker()
 *********************************************************************************************************************/
/*! \brief         Request reading the sector header seal marker from flash access layer and store them in given buffer.
 *  \details       -
 *  \param[in,out] ctx         Context that contains the sector whose header seal marker shall be read. Must not be NULL.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ReadSealMarker(Fee_30_FlexNor_Sector_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ReadLutLink()
 *********************************************************************************************************************/
/*! \brief         Request reading the sector header Lut link from flash access layer and store them in given buffer.
 *  \details       -
 *  \param[in,out] ctx               Context that contains the sector whose header shall be read. Must not be NULL.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ReadLutLink(Fee_30_FlexNor_Sector_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ReadSourceSector()
 *********************************************************************************************************************/
/*! \brief         Request reading the sector header source sector from flash access layer and store them in given buffer.
 *  \details       -
 *  \param[in,out] ctx               Context that contains the sector whose header shall be read. Must not be NULL.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ReadSourceSector(Fee_30_FlexNor_Sector_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ValidateMetadata()
 *********************************************************************************************************************/
/*! \brief       Validates the sector header meta data previously read from flash.
 *  \details     -
 *  \param[in]   ctx            Context that contains the sector header meta data that shall be validated. Must not be NULL.
 *  \return      Result of the validation.
 *  \pre         Sector header meta data must have been read from flash.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_Sector_ErrorLocation, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ValidateMetadata(Fee_30_FlexNor_Sector_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ParseAdditionalInfo()
 *********************************************************************************************************************/
/*! \brief       Parses the sector header additional info previously read from flash.
 *  \details     -
 *  \param[in]   ctx            Context that contains the read sector header additional info that shall be validated. Must not be NULL.
 *  \pre         Sector header additional info must have been read from flash.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ParseAdditionalInfo(Fee_30_FlexNor_Sector_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ParseAdditionalInfoLutLink()
 *********************************************************************************************************************/
/*! \brief          Parses the lookup table link from the read additional sector data
 *  \details        -
 *  \param[in,out]  ctx            Context that contains the read sector header additional info that shall be validated. Must not be NULL.
 *  \pre            Sector header additional info must have been read from flash.
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ParseAdditionalInfoLutLink(Fee_30_FlexNor_Sector_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ParseAdditionalInfoSourceSector()
 *********************************************************************************************************************/
/*! \brief          Parses the source sector id from the read additional sector data
 *  \details        -
 *  \param[in,out]  ctx                           Context that contains the read sector header additional info that shall be validated. Must not be NULL.
 *  \param[in]      alignedSourceSectorStartIndex Start in dex of the source sector id in the sector buffer. 
 *  \pre            Sector header additional info must have been read from flash.
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ParseAdditionalInfoSourceSector(Fee_30_FlexNor_Sector_ContextPtrType ctx, Fee_30_FlexNor_AddressType alignedSourceSectorStartIndex);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ValidateEraseMarker()
 *********************************************************************************************************************/
/*! \brief       Validates the sector erase marker previously read from flash.
 *  \details     -
 *  \param[in]   ctx            Context that contains the sector header meta data that shall be validated. Must not be NULL.
 *  \return      Result of the validation.
 *  \pre         Sector erase marker must have been read from flash.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_Sector_ErrorLocation, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ValidateEraseMarker(Fee_30_FlexNor_Sector_ConstContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ValidateMetadataProperties()
 *********************************************************************************************************************/
/*! \brief          Validates the sector header meta data first alignment part previously read from flash.
 *  \details        -
 *  \param[in,out]  ctx            Context that contains the read sector header meta data that shall be validated. Must not be NULL.
 *  \return         Result of the validation (see enum Fee_30_FlexNor_StructureValidityType).
 *  \pre            Sector header meta data must have been read from flash.
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_StructureValidityType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ValidateMetadataProperties(Fee_30_FlexNor_Sector_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ValidateCommitMarker()
 *********************************************************************************************************************/
/*! \brief       Validates the sector header commit marker previously read from flash.
 *  \details     -
 *  \param[in]   ctx            Context that contains the sector header commit marker that shall be validated. Must not be NULL.
 *  \return      Result of the validation.
 *  \pre         Sector header commit marker must have been read from flash.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_Sector_ErrorLocation, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ValidateCommitMarker(Fee_30_FlexNor_Sector_ConstContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ValidateSealMarker()
 *********************************************************************************************************************/
/*! \brief       Validates the sector header seal marker previously read from flash.
 *  \details     -
 *  \param[in]   ctx            Context that contains the sector header seal marker that shall be validated. Must not be NULL.
 *  \return      Result of the validation.
 *  \pre         Sector header commit marker must have been read from flash.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_Sector_ErrorLocation, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ValidateSealMarker(Fee_30_FlexNor_Sector_ConstContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_WriteEraseMarkerToMemory()
 *********************************************************************************************************************/
/*! \brief       Writes the erase marker to the corresponding address of the sector.
 *  \details     -
 *  \param[in]   ctx            Context that contains the sector whose erase marker shall be written. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE)Fee_30_FlexNor_Sector_WriteEraseMarkerToMemory(Fee_30_FlexNor_Sector_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_WriteLutLinkToMemory()
 *********************************************************************************************************************/
/*! \brief       Writes the lut link to the corresponding address of the sector.
 *  \details     -
 *  \param[in]   ctx            Context that contains the sector whose lut link shall be written. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE)Fee_30_FlexNor_Sector_WriteLutLinkToMemory(Fee_30_FlexNor_Sector_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_WriteSourceSectorToMemory()
 *********************************************************************************************************************/
/*! \brief       Writes the source sector to the corresponding address of the sector.
 *  \details     -
 *  \param[in]   ctx            Context that contains the sector whose source sector shall be written. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE)Fee_30_FlexNor_Sector_WriteSourceSectorToMemory(Fee_30_FlexNor_Sector_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_EraseSector()
 *********************************************************************************************************************/
/*! \brief       Erases the corresponding sector.
 *  \details     -
 *  \param[in]   ctx            Context that contains the sector which shall be erased. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE)Fee_30_FlexNor_Sector_EraseSector(Fee_30_FlexNor_Sector_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_WritePropertiesToMemory()
 *********************************************************************************************************************/
/*! \brief       Writes the properties to the corresponding address of the sector.
 *  \details     -
 *  \param[in]   ctx            Context that contains the sector whose properties shall be written. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE)Fee_30_FlexNor_Sector_WritePropertiesToMemory(Fee_30_FlexNor_Sector_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_WriteSealMarkerToMemory()
 *********************************************************************************************************************/
/*! \brief       Writes the seal marker to the corresponding address of the sector.
 *  \details     -
 *  \param[in]   ctx            Context that contains the sector whose seal marker shall be written. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE)Fee_30_FlexNor_Sector_WriteSealMarkerToMemory(Fee_30_FlexNor_Sector_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_WriteCommitMarkerToMemory()
 *********************************************************************************************************************/
/*! \brief       Writes the commit marker to the corresponding address of the sector.
 *  \details     -
 *  \param[in]   ctx            Context that contains the sector whose commit marker shall be written. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE)Fee_30_FlexNor_Sector_WriteCommitMarkerToMemory(Fee_30_FlexNor_Sector_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ReadChunkHeader()
 *********************************************************************************************************************/
/*! \brief       Reads the next chunk header for the scan sector service.
 *  \details     -
 *  \param[in]   ctx            Context that contains the sector for which the scan shall be done. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE)Fee_30_FlexNor_Sector_ReadChunkHeader(Fee_30_FlexNor_Sector_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ProcessReadChunkHeader()
 *********************************************************************************************************************/
/*! \brief       Evaluates the chunk header that has just been read and decides how to go on with sector scan.
 *  \details     Also updates the next free address and - if chunk is valid - the lut entry.
 *  \param[in]   ctx            Context that contains the sector for which the scan shall be done. Must not be NULL.
 *  \return      FEE_30_FLEXNOR_SECTOR_SCAN_CONTINUE: Not the last chunk, continue with next chunk.
 *  \return      FEE_30_FLEXNOR_SECTOR_SCAN_FINISHED: Latest chunk, sector scan is finished.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_Sector_ScanCurrentResult, FEE_30_FLEXNOR_CODE)Fee_30_FlexNor_Sector_ProcessReadChunkHeader(Fee_30_FlexNor_Sector_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_SetInstanceCountInChunkToAllocate()
 *********************************************************************************************************************/
/*! \brief       Calculates the number of instances for the chunk that shall be allocated.
 *  \details     In case the sector has not enough space that a chunk with one instance fits into it, 
                 the instance count is set to the invalid value.
 *  \param[in]   chunkToAllocate     Chunk that shall be allocated.
 *  \param[in]   predecessorChunk    Predecessor of the chunk that shall be allocted.
 *  \param[in]   targetSector        Sector in which the sector shall be allocated.
 *  \param[in]   resetInstanceCount  Specifies if the instance count shall be reset to one.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_SetInstanceCountInChunkToAllocate(
    Fee_30_FlexNor_ChunkPtrType chunkToAllocate, Fee_30_FlexNor_ConstChunkPtrType predecessorChunk,
    Fee_30_FlexNor_ConstSectorPtrType targetSector, boolean resetInstanceCount);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_TriggerChunkAllocation()
 *********************************************************************************************************************/
/*! \brief       Trigger the allocation of the chunk at the next free address of the sector
 *  \details     -
 *  \param[in]   ctx            Context that contains sector and the chunk. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_TriggerChunkAllocation(Fee_30_FlexNor_Sector_ConstContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_UpdateLookupTableAndNewChunkCounter()
 *********************************************************************************************************************/
/*! \brief       Updates the lookup table after successfull allocating a chunk
 *  \details     -
 *  \param[in]   ctx            Context that contains the current sector and the allocated chunk. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_UpdateLookupTableAndNewChunkCounter(
    Fee_30_FlexNor_Sector_ConstContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_UpdateNextFreeAddress()
 *********************************************************************************************************************/
/*! \brief       Updates the next free address of the sector according to the currently written chunk
 *  \details     -
 *  \param[in]   ctx            Context that contains the current sector and the allocated chunk. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_UpdateNextFreeAddress(Fee_30_FlexNor_Sector_ConstContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_GetFirstFreeAddress()
 *********************************************************************************************************************/
/*! \brief       Returns the first free address, i.e. the start address of the first chunk after the sector header
 *  \details     -
 *  \param[in]   ctx            Context that contains the current sector.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_AddressType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_GetFirstFreeAddress(Fee_30_FlexNor_Sector_ConstContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ResetRecoveryGarbageCollection()
 *********************************************************************************************************************/
/*! \brief       Reset the sector recovery garbage collection flag.
 *  \details     -
 *  \param[in]   sector         Sector whose flag shall be resetted.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ResetRecoveryGarbageCollection(
    Fee_30_FlexNor_SectorPtrType sector);

#    define FEE_30_FLEXNOR_STOP_SEC_CODE
#    include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* FEE_30_FLEXNOR_SECTORINTERNAL_H */

/**********************************************************************************************************************
 *  END OF FILE: Fee_30_FlexNor_ChunkInternal.h
 *********************************************************************************************************************/
