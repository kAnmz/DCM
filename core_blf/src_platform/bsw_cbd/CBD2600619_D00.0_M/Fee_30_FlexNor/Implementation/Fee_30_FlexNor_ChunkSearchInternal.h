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
/*!        \file  Fee_30_FlexNor_ChunkSearchInternal.h
 *        \brief  Internal chunk search prototypes
 *      \details  Provides the internal prototypes for the business logic of the chunk search implementation.
 *         \unit  ChunkSearch
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 **********************************************************************************************************************/

#if !defined (FEE_30_FLEXNOR_CHUNKSEARCHINTERNAL_H)
# define FEE_30_FLEXNOR_CHUNKSEARCHINTERNAL_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Fee_30_FlexNor_Types.h"
#include "Fee_30_FlexNor_ConfigInterface.h"
#include "Fee_30_FlexNor_LookupTable.h"
#include "Fee_30_FlexNor_SectorContainer.h"
#include "Fee_30_FlexNor_ChunkFactory.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef P2VAR(struct Fee_30_FlexNor_ChunkSearch_Context, AUTOMATIC, FEE_30_FLEXNOR_VAR) 
    Fee_30_FlexNor_ChunkSearch_ContextPtrType;
typedef P2CONST(struct Fee_30_FlexNor_ChunkSearch_Context, AUTOMATIC, FEE_30_FLEXNOR_VAR) 
    Fee_30_FlexNor_ChunkSearch_ConstContextPtrType;

/* Module state */
typedef P2FUNC(Fee_30_FlexNor_ScheduleBehaviorType, AUTOMATIC, Fee_30_FlexNor_ChunkSearch_ProcessEvt)(
    Fee_30_FlexNor_ChunkSearch_ContextPtrType ctx);
typedef P2FUNC(void, AUTOMATIC, Fee_30_FlexNor_ChunkSearch_FailEvt)(Fee_30_FlexNor_ChunkSearch_ContextPtrType ctx);

typedef struct Fee_30_FlexNor_ChunkSearch_State
{
    Fee_30_FlexNor_ChunkSearch_ProcessEvt ProcessEvent;     /*!< Pointer to the handler for the process event of the state */
    Fee_30_FlexNor_ChunkSearch_FailEvt FailEvent;           /*!< Pointer to the handler for the fail event of the state */
} Fee_30_FlexNor_ChunkSearch_StateType;                     /*!< Represents a state of the internal unit state machine */

typedef CONST(Fee_30_FlexNor_ChunkSearch_StateType, AUTOMATIC) Fee_30_FlexNor_ChunkSearch_ConstStateType;
typedef P2CONST(Fee_30_FlexNor_ChunkSearch_StateType, AUTOMATIC, FEE_30_FLEXNOR_VAR) 
    Fee_30_FlexNor_ChunkSearch_ConstStatePtrType;

/* Module context */
typedef struct Fee_30_FlexNor_ChunkSearch_Context
{
    Fee_30_FlexNor_ChunkSearch_ConstStatePtrType CurrentState;       /*!< Current state of the state machine */
    Fee_30_FlexNor_PartitionIdType PartitionId;                      /*!< Id of the partition the search shall be executed in */
    Fee_30_FlexNor_ChunkLinkType NextChunk;                          /*!< Link to the next chunk that shall be read */
    Fee_30_FlexNor_ChunkPtrType CurrentChunk;                        /*!< Currently latest found chunk in the chunk chain */
    Fee_30_FlexNor_ResultCallback ResultCallback;                    /*!< Result callback that is used to communicate the service result back to the caller */
} Fee_30_FlexNor_ChunkSearch_ContextType;                            /*!< Represents the context for the internal state machine of the unit */

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
# define FEE_30_FLEXNOR_START_SEC_CODE
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Fee_30_FlexNor_ChunkSearch_StartJob()
 *********************************************************************************************************************/
/*! \brief       Start a job for the unit
 *  \details     Registers the unit at the scheduler to start the asynchronous processing for the unit.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_ChunkSearch_StartJob(void);

/**********************************************************************************************************************
 * Fee_30_FlexNor_ChunkSearch_EndJob()
 *********************************************************************************************************************/
/*! \brief       Ends a job for the unit
 *  \details     Unregisters the unit from the scheduler.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_ChunkSearch_EndJob(void);

/**********************************************************************************************************************
 * Fee_30_FlexNor_ChunkSearch_ParseChunkLink()
 *********************************************************************************************************************/
/*! \brief       Parses the chunk link read from flash and splits it into the sector id and offset parts
 *  \details     -
 *  \param[in]   link   Chunk link that shall be parsed
 *  \return      A lookup table link that contains the separated parts of the chunk link
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_LookupTable_LinkType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_ChunkSearch_ParseChunkLink(
    Fee_30_FlexNor_ChunkLinkType link);

/**********************************************************************************************************************
 * Fee_30_FlexNor_ChunkSearch_ReadChunk()
 *********************************************************************************************************************/
/*! \brief       Reads the chunk the link stored in the context points to.
 *  \details     -
 *  \param[in]   ctx            Pointer to the context. Must not be NULL.
 *  \return      E_OK           Reading the chunk was successfully triggered.
 *               E_NOT_OK       
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_ChunkSearch_ReadChunk(
    Fee_30_FlexNor_ChunkSearch_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_ChunkSearch_IsSuccessorChunkNewer()
 *********************************************************************************************************************/
/*! \brief       Checks whether the successor chunk is newer than the current chunk whose chunk link points to it.
 *  \details     The successor chunk is newer if the current chunk lies in an older sector or if both chunks are in the
 *               same sector and the successor chunk has a (strictly) higher address.
 *  \param[in]   ctx            Pointer to the context. Must not be NULL.
 *  \return      TRUE    successor chunk is newer
 *               FALSE   successor chunk is not newer     
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(boolean, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_ChunkSearch_IsSuccessorChunkNewer(
    Fee_30_FlexNor_ChunkSearch_ConstContextPtrType ctx);

# define FEE_30_FLEXNOR_STOP_SEC_CODE
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* FEE_30_FLEXNOR_CHUNKSEARCHINTERNAL_H */

/**********************************************************************************************************************
 *  END OF FILE: Fee_30_FlexNor_ChunkSearchInternal.h
 *********************************************************************************************************************/
