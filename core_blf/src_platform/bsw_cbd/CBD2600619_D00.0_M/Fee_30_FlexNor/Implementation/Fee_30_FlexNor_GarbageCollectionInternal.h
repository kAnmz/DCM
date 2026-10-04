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
/*!        \file  Fee_30_FlexNor_GarbageCollectionInternal.h
 *        \brief  Internal garbage collection prototypes
 *      \details  Provides the internal prototypes for the business logic of the garbage collection implementation.
 *         \unit  GarbageCollection
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 **********************************************************************************************************************/

#if !defined (FEE_30_FLEXNOR_GARBAGECOLLECTIONINTERNAL_H)
# define FEE_30_FLEXNOR_GARBAGECOLLECTIONINTERNAL_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Fee_30_FlexNor_Types.h"
#include "Fee_30_FlexNor_ConfigInterface.h"
#include "Fee_30_FlexNor_LookupTable.h"
#include "Fee_30_FlexNor_Sector.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define FEE_30_FLEXNOR_MAX_RETRY 2u           /*!< Maximum number of retries of garbage collection in case of a fail */

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum
{
    FEE_30_FLEXNOR_GARBAGECOLLECTION_NEW,       /*!< A new garbage collection shall be started */
    FEE_30_FLEXNOR_GARBAGECOLLECTION_CONTINUE   /*!< An unfinished garbage collection shall be completed */
} Fee_30_FlexNor_GarbageCollectionModeType;     /*!< Garbage collection mode */

typedef struct
{
    Fee_30_FlexNor_BlockIdType BlockId;                 /*!< Id of the block that is being copied */
    Fee_30_FlexNor_PagebasedOffsetType ChunkOffset;     /*!< Location of the blocks latest chunk in flash */
} Fee_30_FlexNor_GarbageCollection_BlockCopyType;       /*!< Binds together the information abouth the block that is 
                                                             being copied and its location in flash */

typedef P2VAR(struct Fee_30_FlexNor_GarbageCollection_Context, AUTOMATIC, FEE_30_FLEXNOR_VAR) 
    Fee_30_FlexNor_GarbageCollection_ContextPtrType;
typedef P2CONST(struct Fee_30_FlexNor_GarbageCollection_Context, AUTOMATIC, FEE_30_FLEXNOR_VAR) 
    Fee_30_FlexNor_GarbageCollection_ConstContextPtrType;

/* Module state */
typedef P2FUNC(Fee_30_FlexNor_ScheduleBehaviorType, AUTOMATIC, Fee_30_FlexNor_GarbageCollection_ProcessEvt)(
    Fee_30_FlexNor_GarbageCollection_ContextPtrType ctx);
typedef P2FUNC(void, AUTOMATIC, Fee_30_FlexNor_GarbageCollection_FailEvt)(
    Fee_30_FlexNor_GarbageCollection_ContextPtrType ctx);

typedef struct Fee_30_FlexNor_GarbageCollection_State
{
    Fee_30_FlexNor_GarbageCollection_ProcessEvt ProcessEvent; /*!< Pointer to the handler for the process event of the state */
    Fee_30_FlexNor_GarbageCollection_FailEvt FailEvent;       /*!< Pointer to the handler for the fail event of the state */
} Fee_30_FlexNor_GarbageCollection_StateType;                 /*!< Represents a state of the internal unit state machine */

typedef CONST(Fee_30_FlexNor_GarbageCollection_StateType, AUTOMATIC) Fee_30_FlexNor_GarbageCollection_ConstStateType;
typedef P2CONST(Fee_30_FlexNor_GarbageCollection_StateType, AUTOMATIC, FEE_30_FLEXNOR_VAR) 
    Fee_30_FlexNor_GarbageCollection_ConstStatePtrType;

typedef uint8 Fee_30_FlexNor_RetryCounterType;                    
/* Module context */
typedef struct Fee_30_FlexNor_GarbageCollection_Context
{
    Fee_30_FlexNor_GarbageCollection_ConstStatePtrType CurrentState; /*!< Current state of the state machine */
    
    Fee_30_FlexNor_ConstPartitionConfigPtrType PartitionConfig; /*!< Pointer to the configuration of the partition the garbage collection shall be executed for */
    Fee_30_FlexNor_SectorPtrType SourceSector;                  /*!< Pointer to the sector that is garbage collected */
    Fee_30_FlexNor_SectorPtrType TargetSector;                  /*!< Pointer to the sector the valid data from the source sector is copied to */
    Fee_30_FlexNor_GarbageCollection_BlockCopyType BlockToCopy; /*!< Contains information about the block that is being copied */
    Fee_30_FlexNor_RetryCounterType RetryCounter;               /*!< Counter of retries of garbage collection in case of a fail event */
    boolean IsPersistLutJobRunning;                             /*!< Indicates if the GC is executed in context of a perist LUT job. In this case no LUT recovery is allowed. */
    Fee_30_FlexNor_ResultCallback ResultCallback;               /*!< Result callback that is used to communicate the service result back to the caller */
} Fee_30_FlexNor_GarbageCollection_ContextType;                 /*!< Represents the context for the internal state machine of the unit */

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
# define FEE_30_FLEXNOR_START_SEC_CODE
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Fee_30_FlexNor_GarbageCollection_StartJob()
 *********************************************************************************************************************/
/*! \brief       Start a job for the unit
 *  \details     Registers the unit at the scheduler to start the asynchronous processing for the unit.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_GarbageCollection_StartJob(void);

/**********************************************************************************************************************
 * Fee_30_FlexNor_GarbageCollection_EndJob()
 *********************************************************************************************************************/
/*! \brief       Ends a job for the unit
 *  \details     Unregisters the unit from the scheduler.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_GarbageCollection_EndJob(void);

/**********************************************************************************************************************
 * Fee_30_FlexNor_GarbageCollection_TriggerLookupTableRecoveryIfInvalid()
 *********************************************************************************************************************/
/*! \brief          Triggers a lookup table recovery for the partition the garbage collection shall be executed for. 
 *  \details        The lookup table recovery is triggered if the lookup table is invalid.
 *  \param[in,out]  ctx     Pointer to the context for the state machine processing. Must not be NULL.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(boolean, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_GarbageCollection_TriggerLookupTableRecoveryIfInvalid(
    Fee_30_FlexNor_GarbageCollection_ConstContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_GarbageCollection_InitializeGarbageCollectionMode()
 *********************************************************************************************************************/
/*! \brief          Checks which kind of garbage collection needs to be executed and initializes the context accordingly
 *  \details        Depending of the state of the sectors and the given parameters either a new garbage collection is 
 *                  started or an unfinished one is continued.
 *  \param[in,out]  ctx  Pointer to the context containing the current garbage collection information. Must not be null.
 *  \return         FEE_30_FLEXNOR_GARBAGECOLLECTION_NEW      A new garbage collection is started
 *                  FEE_30_FLEXNOR_GARBAGECOLLECTION_CONTINUE An unfinished garbage collection will be further processed
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_GarbageCollectionModeType, FEE_30_FLEXNOR_CODE) 
    Fee_30_FlexNor_GarbageCollection_InitializeGarbageCollectionMode(
        Fee_30_FlexNor_GarbageCollection_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_GarbageCollection_TriggerSectorAllocation()
 *********************************************************************************************************************/
/*! \brief          Triggers the setup of a new sector for the selected target sector
 *  \details        -
 *  \param[in,out]  ctx  Pointer to the context containing the current garbage collection information. Must not be null.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_GarbageCollection_TriggerSectorAllocation(
    Fee_30_FlexNor_GarbageCollection_ConstContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_GarbageCollection_StoreSourceSector()
 *********************************************************************************************************************/
/*! \brief          Writes the sector id of the selected source sector to the sector header of the target sector
 *  \details        -
 *  \param[in,out]  ctx  Pointer to the context containing the current garbage collection information. Must not be null.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_GarbageCollection_StoreSourceSector(
    Fee_30_FlexNor_GarbageCollection_ConstContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_GarbageCollection_GetNextBlockToCopy()
 *********************************************************************************************************************/
/*! \brief          Gets the next block that needs to be copied and stores it in the given context
 *  \details        -
 *  \param[in,out]  ctx  Pointer to the context containing the current garbage collection information. Must not be null.
 *  \return         TRUE    There is another block that needs to be copied
 *                  FALSE   All blocks in the source sector were copied to the target sector
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(boolean, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_GarbageCollection_GetNextBlockToCopy(
    Fee_30_FlexNor_GarbageCollection_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_GarbageCollection_TriggerCopyBlock()
 *********************************************************************************************************************/
/*! \brief          Triggers a copy block job for the partition the garbage collection shall be executed for
 *  \details        -
 *  \param[in,out]  ctx     Pointer to the context for the state machine processing. Must not be NULL.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_GarbageCollection_TriggerCopyBlock(
    Fee_30_FlexNor_GarbageCollection_ConstContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_GarbageCollection_MarkForErase()
 *********************************************************************************************************************/
/*! \brief          Writes the erase marker to the source sector to mark it as garbage collected
 *  \details        -
 *  \param[in,out]  ctx  Pointer to the context containing the current garbage collection information. Must not be null.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_GarbageCollection_MarkForErase(
    Fee_30_FlexNor_GarbageCollection_ConstContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_GarbageCollection_PrepareRestart()
 *********************************************************************************************************************/
/*! \brief       Prepares the restart of the garbage collection process
 *  \details     Invalidates all lookup table links and the target sector and resets the id of the block that was copied 
 *               last to prepare the restart of the whole garbage collection process. Also clears the source sector 
 *               selection if no garbage collection of a specific sector was requested originally.
 *  \param[in,out]  ctx  Pointer to the context containing the current garbage collection information. Must not be null.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_GarbageCollection_PrepareRestart(
    Fee_30_FlexNor_GarbageCollection_ContextPtrType ctx);

# define FEE_30_FLEXNOR_STOP_SEC_CODE
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* FEE_30_FLEXNOR_GARBAGECOLLECTIONINTERNAL_H */

/**********************************************************************************************************************
 *  END OF FILE: Fee_30_FlexNor_GarbageCollectionInternal.h
 *********************************************************************************************************************/
