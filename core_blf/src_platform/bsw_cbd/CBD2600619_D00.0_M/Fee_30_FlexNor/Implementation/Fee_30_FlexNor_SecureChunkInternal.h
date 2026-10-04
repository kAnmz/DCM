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
/*!        \file  Fee_30_FlexNor_SecureChunkInternal.h
 *        \brief  Internal secure chunk business logic prototypes
 *      \details  Provides the internal prototypes for the business logic of the secure chunk implementation.
 *         \unit  SecureChunk
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 **********************************************************************************************************************/

#if !defined(FEE_30_FLEXNOR_SECURECHUNKINTERNAL_H)
# define FEE_30_FLEXNOR_SECURECHUNKINTERNAL_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Fee_30_FlexNor_Chunk.h"
#include "Fee_30_FlexNor_ChunkInternal.h"

#include "Fee_30_FlexNor_Types.h"
#include "Fee_30_FlexNor_ConfigInterface.h"
#include "Fee_30_FlexNor_Instance.h"

# if (FEE_30_FLEXNOR_SECURELAYOUT_ENABLED == STD_ON) /* COV_MSR_UT_OPTIONAL_UNIT */

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef struct Fee_30_FlexNor_SecureChunk
{
    Fee_30_FlexNor_ChunkPtrType GenericChunk;           /*!< Pointer to the generic chunk. */
    Fee_30_FlexNor_ConstChunkPtrType ConstGenericChunk; /*!< Pointer to the const generic chunk. */
} Fee_30_FlexNor_SecureChunkType;                       /*!< Holds all private data used by the concrete type. */

typedef P2VAR(struct Fee_30_FlexNor_SecureChunk_Context, AUTOMATIC, FEE_30_FLEXNOR_VAR) Fee_30_FlexNor_SecureChunk_ContextPtrType;
typedef P2CONST(struct Fee_30_FlexNor_SecureChunk_Context, AUTOMATIC, FEE_30_FLEXNOR_VAR) Fee_30_FlexNor_SecureChunk_ConstContextPtrType;

/* Module state */
typedef P2FUNC(Fee_30_FlexNor_ScheduleBehaviorType, AUTOMATIC, Fee_30_FlexNor_SecureChunk_ProcessEvt)(Fee_30_FlexNor_SecureChunk_ContextPtrType ctx);
typedef P2FUNC(void, AUTOMATIC, Fee_30_FlexNor_SecureChunk_FailEvt)(Fee_30_FlexNor_SecureChunk_ContextPtrType ctx);

typedef struct Fee_30_FlexNor_SecureChunk_State
{
    Fee_30_FlexNor_SecureChunk_ProcessEvt ProcessEvent; /*!< Pointer to the handler for the process event of the state */
    Fee_30_FlexNor_SecureChunk_FailEvt FailEvent;       /*!< Pointer to the handler for the fail event of the state */
} Fee_30_FlexNor_SecureChunk_StateType;                 /*!< Represents a state of the internal unit state machine */

typedef CONST(Fee_30_FlexNor_SecureChunk_StateType, AUTOMATIC) Fee_30_FlexNor_SecureChunk_ConstStateType;
typedef P2CONST(Fee_30_FlexNor_SecureChunk_StateType, AUTOMATIC, FEE_30_FLEXNOR_VAR) Fee_30_FlexNor_SecureChunk_ConstStatePtrType;

/* Module context */
typedef struct Fee_30_FlexNor_SecureChunk_Context
{
    Fee_30_FlexNor_SecureChunk_ConstStatePtrType CurrentState; /*!< Current state of the state machine */

    Fee_30_FlexNor_SecureChunkType Chunk;                       /*!< Secure chunk data the unit operates on. */
    Fee_30_FlexNor_DataPtrType ChunkBuffer;                     /*!< Internal buffer to store the chunk header (metadata + link) data read from flash. */
    Fee_30_FlexNor_ConstPartitionConfigPtrType PartitionConfig; /*!< Pointer to the partition configuration of the processed chunk. */

    Fee_30_FlexNor_ConstInstancePtrType SourceInstance; /*!< Pointer to the source instance whose payload is copied to the new chunk during the chunk allocation. */
    Fee_30_FlexNor_InstancePtrType TargetInstance;      /*!< Pointer to the target instance that is written during the chunk allocation. */
    Fee_30_FlexNor_ChunkPtrType PredecessorChunk;       /*!< Pointer to the predecessor chunk whose link is updated to point to the allocated chunk. */
    Fee_30_FlexNor_ConstChunkPtrType SuccessorChunk;    /*!< Pointer to the successor chunk whose link is written into the chunk write link service is called for. */
    Fee_30_FlexNor_InstanceType Instance;               /*!< Internal buffer to store the instance which is being operated on. */

    Fee_30_FlexNor_ResultCallback ResultCallback;       /*!< Result callback that is used to communicate the service result back to the caller. */
} Fee_30_FlexNor_SecureChunk_ContextType;         /*!< Represents the context for the internal state machine of the unit */

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
# define FEE_30_FLEXNOR_START_SEC_CODE
# include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureChunk_ResultHandler()
 *********************************************************************************************************************/
/*! \brief       Handles the result of a called service
 *  \details     This function is used as a result callback for services called by this unit.
 *  \param[in]   result               Result of the called service
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureChunk_ResultHandler(Fee_30_FlexNor_ServiceResult result);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureChunk_StartJob()
 *********************************************************************************************************************/
/*! \brief       Start a job for the unit
 *  \details     Registers the unit at the scheduler to start the asynchronous processing for the unit.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureChunk_StartJob(void);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureChunk_EndJob()
 *********************************************************************************************************************/
/*! \brief       Ends a job for the unit
 *  \details     Unregisters the unit from the scheduler.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureChunk_EndJob(void);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureChunk_ReadChunkHeader()
 *********************************************************************************************************************/
/*! \brief       Reads the chunk header from flash.
 *  \details     Reads the chunk header (containing chunk metadata and chunk link) from flash.
 *  \param[in]   ctx        Context the chunk header shall be read in. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureChunk_ReadChunkHeader(Fee_30_FlexNor_SecureChunk_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureChunk_ValidateChunkHeader()
 *********************************************************************************************************************/
/*! \brief         Validates the chunk header
 *  \details       Validates the chunk header previously read from flash. Validates metadata and chunk link.
 *  \param[in,out] ctx            Context that contains the read chunk header that shall be validated. Must not be NULL.
 *  \pre           Chunk header must have been read from flash.
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureChunk_ValidateChunkHeader(Fee_30_FlexNor_SecureChunk_ConstContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureChunk_WriteStartMarker()
 *********************************************************************************************************************/
/*! \brief       Writes the chunks start marker to flash
 *  \details     -
 *  \param[in]   ctx              Context that contains the informations about the chunk that start marker shall be written. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureChunk_WriteStartMarker(Fee_30_FlexNor_SecureChunk_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureChunk_WriteProperties()
 *********************************************************************************************************************/
/*! \brief       Writes the chunk properties to flash
 *  \details     -
 *  \param[in]   ctx               Context that contains the chunk properties that shall be written to flash. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureChunk_WriteProperties(Fee_30_FlexNor_SecureChunk_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureChunk_WriteCommitMarker()
 *********************************************************************************************************************/
/*! \brief       Writes the chunk commit marker to flash
 *  \details     -
 *  \param[in]   ctx               Context that contains the chunk whose commit marker shall be written. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureChunk_WriteCommitMarker(Fee_30_FlexNor_SecureChunk_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureChunk_ReadStartMarker()
 *********************************************************************************************************************/
/*! \brief       Reads the start marker from flash.
 *  \details     -
 *  \param[in]   ctx        Context the start marker shall be read in. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureChunk_ReadStartMarker(Fee_30_FlexNor_SecureChunk_ConstContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureChunk_ValidateStartMarker()
 *********************************************************************************************************************/
/*! \brief       Validates the start marker
 *  \details     -
 *  \param[in]   ctx            Context that contains the start marker that shall be validated. Must not be NULL.
 *  \return      validity of the structure
 *  \pre         Start marker must have been read from flash.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_StructureValidityType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureChunk_ValidateStartMarker(Fee_30_FlexNor_SecureChunk_ConstContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureChunk_ReadProperties()
 *********************************************************************************************************************/
/*! \brief       Reads the chunk header properties from flash.
 *  \details     -
 *  \param[in]   ctx        Context the chunk header properties shall be read in. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureChunk_ReadProperties(Fee_30_FlexNor_SecureChunk_ConstContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureChunk_ValidateProperties()
 *********************************************************************************************************************/
/*! \brief       Validates the chunk header properties
 *  \details     -
 *  \param[in]   ctx            Context that contains the chunk header properties that shall be validated. Must not be NULL.
 *  \param[in]   strategy       Determines whether the whole chunk header is in the buffer or only the properties itself.
 *  \return      Validity of the structure
 *  \pre         Chunk header properties must have been read from flash.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_StructureValidityType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureChunk_ValidateProperties(
    Fee_30_FlexNor_SecureChunk_ConstContextPtrType ctx,
    Fee_30_FlexNor_ChunkHeaderValidationStrategy strategy);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureChunk_ReadCommitMarker()
 *********************************************************************************************************************/
/*! \brief       Reads the commit marker from flash.
 *  \details     -
 *  \param[in]   ctx        Context the commit marker shall be read in. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureChunk_ReadCommitMarker(Fee_30_FlexNor_SecureChunk_ConstContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureChunk_ValidateCommitMarker()
 *********************************************************************************************************************/
/*! \brief       Validates the commit marker
 *  \details     -
 *  \param[in]   ctx            Context that contains the commit marker that shall be validated. Must not be NULL.
 *  \param[in]   strategy       Determines whether the whole chunk header is in the buffer or only the commit marker itself.
 *  \return      Validity of the structure
 *  \pre         Commit marker must have been read from flash.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_StructureValidityType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureChunk_ValidateCommitMarker(
    Fee_30_FlexNor_SecureChunk_ConstContextPtrType ctx,
    Fee_30_FlexNor_ChunkHeaderValidationStrategy strategy);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureChunk_ReadFirstInstance()
 *********************************************************************************************************************/
/*! \brief       Requests to read the first instance from instance submodule.
 *  \details     -
 *  \param[in]   ctx        Context for getting the first instance. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureChunk_ReadFirstInstance(Fee_30_FlexNor_SecureChunk_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureChunk_ValidateFirstInstance()
 *********************************************************************************************************************/
/*! \brief       Validates the first instance
 *  \details     -
 *  \param[in]   ctx            Context that contains the first instance that shall be validated. Must not be NULL.
 *  \return      Validity of the first instance
 *  \pre         First instance must have been read via instance submodule.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_StructureValidityType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureChunk_ValidateFirstInstance(Fee_30_FlexNor_SecureChunk_ConstContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureChunk_ReadLink()
 *********************************************************************************************************************/
/*! \brief       Reads the link from flash.
 *  \details     -
 *  \param[in]   ctx        Context the link shall be read in. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureChunk_ReadLink(Fee_30_FlexNor_SecureChunk_ConstContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureChunk_ValidateLink()
 *********************************************************************************************************************/
/*! \brief       Validates the link
 *  \details     -
 *  \param[in]   ctx            Context that contains the link that shall be validated. Must not be NULL.
 *  \param[in]   strategy       Determines whether the whole chunk header is in the buffer or only the link itself.
 *  \return      Validity of the structure
 *  \pre         Link must have been read from flash.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_StructureValidityType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureChunk_ValidateLink(
    Fee_30_FlexNor_SecureChunk_ConstContextPtrType ctx,
    Fee_30_FlexNor_ChunkHeaderValidationStrategy strategy);

#define FEE_30_FLEXNOR_STOP_SEC_CODE
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# endif

#endif /* FEE_30_FLEXNOR_SECURECHUNKINTERNAL_H */

/**********************************************************************************************************************
 *  END OF FILE: Fee_30_FlexNor_SecureChunkInternal.h
 *********************************************************************************************************************/
