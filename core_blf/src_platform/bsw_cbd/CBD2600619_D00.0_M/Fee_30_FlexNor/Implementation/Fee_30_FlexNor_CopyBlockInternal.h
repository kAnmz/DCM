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
/*!        \file  Fee_30_FlexNor_CopyBlockInternal.h
 *        \brief  Internal copy block prototypes
 *      \details  Provides the internal prototypes for the business logic of the copy block implementation.
 *         \unit  CopyBlock
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 **********************************************************************************************************************/

#if !defined (FEE_30_FLEXNOR_COPYBLOCKINTERNAL_H)
# define FEE_30_FLEXNOR_COPYBLOCKINTERNAL_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Fee_30_FlexNor_Types.h"
#include "Fee_30_FlexNor_ConfigInterface.h"
#include "Fee_30_FlexNor_Sector.h"
#include "Fee_30_FlexNor_Chunk.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef struct
{
    Fee_30_FlexNor_ConstBlockConfigPtrType BlockConfig; /*!< Pointer to the block configuration */
    Fee_30_FlexNor_ChunkType SourceChunk;               /*!< Chunk that hold the read source chunk data */
    Fee_30_FlexNor_ChunkType TargetChunk;               /*!< Chunk that is used for allocation routines */
    Fee_30_FlexNor_InstanceType SourceInstance;         /*!< Instance that holds the information about the source instance that shall be copied to the target sector. */
    Fee_30_FlexNor_InstanceType TargetInstance;         /*!< Instance that represents the target instance the source instance is copied to. */
    Fee_30_FlexNor_PagebasedOffsetType ChunkOffset;     /*!< Offset of the chunk in pages relative to the sector start address.*/
} Fee_30_FlexNor_CopyBlock_BlockCopyType;       /*!< Binds together the information about the block that is being copied and its location in flash */

typedef P2VAR(struct Fee_30_FlexNor_CopyBlock_Context, AUTOMATIC, FEE_30_FLEXNOR_VAR) Fee_30_FlexNor_CopyBlock_ContextPtrType;
typedef P2CONST(struct Fee_30_FlexNor_CopyBlock_Context, AUTOMATIC, FEE_30_FLEXNOR_VAR) Fee_30_FlexNor_CopyBlock_ConstContextPtrType;

/* Module state */
typedef P2FUNC(Fee_30_FlexNor_ScheduleBehaviorType, AUTOMATIC, Fee_30_FlexNor_CopyBlock_ProcessEvt)(Fee_30_FlexNor_CopyBlock_ContextPtrType ctx);
typedef P2FUNC(void, AUTOMATIC, Fee_30_FlexNor_CopyBlock_FailEvt)(Fee_30_FlexNor_CopyBlock_ContextPtrType ctx);

typedef struct Fee_30_FlexNor_CopyBlock_State
{
    Fee_30_FlexNor_CopyBlock_ProcessEvt ProcessEvent;     /*!< Pointer to the handler for the process event of the state */
    Fee_30_FlexNor_CopyBlock_FailEvt FailEvent;           /*!< Pointer to the handler for the fail event of the state */
} Fee_30_FlexNor_CopyBlock_StateType;                     /*!< Represents a state of the internal unit state machine */

typedef CONST(Fee_30_FlexNor_CopyBlock_StateType, AUTOMATIC) Fee_30_FlexNor_CopyBlock_ConstStateType;
typedef P2CONST(Fee_30_FlexNor_CopyBlock_StateType, AUTOMATIC, FEE_30_FLEXNOR_VAR) Fee_30_FlexNor_CopyBlock_ConstStatePtrType;

/* Module context */
typedef struct Fee_30_FlexNor_CopyBlock_Context
{
    Fee_30_FlexNor_CopyBlock_ConstStatePtrType CurrentState;         /*!< Current state of the state machine */

    Fee_30_FlexNor_ConstPartitionConfigPtrType PartitionConfig;      /*!< Pointer to the configuration of the partition the copy block shall be executed for */
    Fee_30_FlexNor_SectorPtrType SourceSector;                       /*!< Pointer to the sector from which block is copied */
    Fee_30_FlexNor_SectorPtrType TargetSector;                       /*!< Pointer to the sector the block is copied to */
    Fee_30_FlexNor_CopyBlock_BlockCopyType BlockToCopy;              /*!< Contains information about the block that is being copied */
    Fee_30_FlexNor_ResultCallback ResultCallback;                    /*!< Result callback that is used to communicate the service result back to the caller */
    boolean resetInstanceCount;                                      /*!< Flag indicating whether the instance count shall be reset to one */
} Fee_30_FlexNor_CopyBlock_ContextType;                              /*!< Represents the context for the internal state machine of the unit */

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
# define FEE_30_FLEXNOR_START_SEC_CODE
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Fee_30_FlexNor_CopyBlock_StartJob()
 *********************************************************************************************************************/
/*! \brief       Start a job for the unit
 *  \details     Registers the unit at the scheduler to start the asynchronous processing for the unit.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_CopyBlock_StartJob(void);

/**********************************************************************************************************************
 * Fee_30_FlexNor_CopyBlock_EndJob()
 *********************************************************************************************************************/
/*! \brief       Ends a job for the unit
 *  \details     Unregisters the unit from the scheduler.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_CopyBlock_EndJob(void);

/**********************************************************************************************************************
 * Fee_30_FlexNor_CopyBlock_ReadSourceChunk()
 *********************************************************************************************************************/
/*! \brief          Reads the source chunk that shall be copied.
 *  \details        The address of the source chunk that shall be copied is computed from information provided by 
 *                  context: start address of source sector, offset to the chunk and payload size.                 
 *  \param[in,out]  ctx  Pointer to the context containing the current copy block information. Must not be null.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_CopyBlock_ReadSourceChunk(Fee_30_FlexNor_CopyBlock_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_CopyBlock_FindLatestInstance()
 *********************************************************************************************************************/
/*! \brief          Finds the latest instance of the chunk that shall be copied
 *  \details        -
 *  \param[in,out]  ctx  Pointer to the context containing the current copy block information. Must not be null.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_CopyBlock_FindLatestInstance(Fee_30_FlexNor_CopyBlock_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_CopyBlock_AllocateCopy()
 *********************************************************************************************************************/
/*! \brief          Allocates a new chunk and a new instance inside it to store the previously read data 
 *                  of the block that shall be copied
 *  \details        -
 *  \param[in,out]  ctx  Pointer to the context containing the current copy block information. Must not be null.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_CopyBlock_AllocateCopy(Fee_30_FlexNor_CopyBlock_ContextPtrType ctx);

# define FEE_30_FLEXNOR_STOP_SEC_CODE
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* FEE_30_FLEXNOR_COPYBLOCKINTERNAL_H */

/**********************************************************************************************************************
 *  END OF FILE: Fee_30_FlexNor_CopyBlockInternal.h
 *********************************************************************************************************************/
