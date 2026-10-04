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
/*!        \file  Fee_30_FlexNor_ChunkMachine.h
 *        \brief  State machine prototypes for the chunk unit
 *      \details  Provides the prototypes for the state machine implementation of the generic chunk unit.
 *         \unit  Chunk
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 **********************************************************************************************************************/

#if !defined(FEE_30_FLEXNOR_CHUNKMACHINE_H)
#define FEE_30_FLEXNOR_CHUNKMACHINE_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Fee_30_FlexNor_ChunkInternal.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

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
#define FEE_30_FLEXNOR_START_SEC_CODE
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Fee_30_FlexNor_Chunk_InitState()
 *********************************************************************************************************************/
/*! \brief          Initialize the internal state machine
 *  \details        -
 *  \param[in,out]  ctx                   Pointer to the context that shall be initialized. Must not be NULL.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Chunk_InitState(Fee_30_FlexNor_Chunk_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Chunk_DefaultProcessEvent()
 *********************************************************************************************************************/
/*! \brief          Default Process event handler
 *  \details        This function is never called in normal operation. It exists to be able to set the state machine
 *                  to a defined state in case no job is being executed.
 *  \param[in,out]  ctx        Pointer to the context for the state machine processing. Must not be NULL.
 *  \return         FEE_30_FLEXNOR_STOP_SCHEDULE  Always stops the scheduler
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Chunk_DefaultProcessEvent(
    Fee_30_FlexNor_Chunk_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Chunk_DefaultFailEvent()
 *********************************************************************************************************************/
/*! \brief          Default Fail event handler
 *  \details        This function is never called in normal operation. It exists to be able to set the state machine
 *                  to a defined state in case no job is being executed.
 *  \param[in,out]  ctx        Pointer to the context for the state machine processing. Must not be NULL.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Chunk_DefaultFailEvent(Fee_30_FlexNor_Chunk_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Chunk_JobFailEvent()
 *********************************************************************************************************************/
/*! \brief       Fail event handler
 *  \details     Ends the current job and notifies the caller about the fail of the service.
 *  \param[in]   ctx           Pointer to the context of the service that failed. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Chunk_JobFailEvent(Fee_30_FlexNor_Chunk_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Chunk_WriteFailEvent()
 *********************************************************************************************************************/
/*! \brief       Fail event handler for failed write job
 *  \details     Ends the current job, triggers a garbage collection for the sector and notifies the caller about the 
 *               fail of the service.
 *  \param[in]   ctx           Pointer to the context of the service that failed. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Chunk_WriteFailEvent(Fee_30_FlexNor_Chunk_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Chunk_BinarySearch_Initialize()
 *********************************************************************************************************************/
/*! \brief          Initializes the binary search for a valid or empty instance
 *  \details        Depending on the search type, the binary either searches for the first empty instance or the latest
 *                  valid instance in the chunk.
 *  \param[in,out]  ctx        Pointer to the context for the state machine processing. Must not be NULL.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Chunk_BinarySearch_Initialize(Fee_30_FlexNor_Chunk_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Chunk_BinarySearch_ProcessEvent()
 *********************************************************************************************************************/
/*! \brief          Event handler for the Process event of the BinarySearch state
 *  \details        -
 *  \param[in,out]  ctx        Pointer to the context for the state machine processing. Must not be NULL.
 *  \return         FEE_30_FLEXNOR_CONTINUE_SCHEDULE  Let the execution continue
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Chunk_BinarySearch_ProcessEvent(
    Fee_30_FlexNor_Chunk_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Chunk_LinearSearch_Initialize()
 *********************************************************************************************************************/
/*! \brief          Initializes the linear search for a valid instance
 *  \details        -
 *  \param[in,out]  ctx        Pointer to the context for the state machine processing. Must not be NULL.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Chunk_LinearSearch_Initialize(Fee_30_FlexNor_Chunk_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Chunk_FindLatestValidInstance_Initialize()
 *********************************************************************************************************************/
/*! \brief       Initialize find latest valid instance state machine
 *  \details     -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Chunk_FindLatestValidInstance_Initialize(void);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Chunk_TryAllocateInstance_Initialize()
 *********************************************************************************************************************/
/*! \brief       Initialize try allocate instance state machine
 *  \details     -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Chunk_TryAllocateInstance_Initialize(void);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Chunk_LinearSearch_ProcessEvent()
 *********************************************************************************************************************/
/*! \brief          Event handler for the Process event of the LinearSearch state
 *  \details        -
 *  \param[in,out]  ctx        Pointer to the context for the state machine processing. Must not be NULL.
 *  \return         FEE_30_FLEXNOR_CONTINUE_SCHEDULE  Let the execution continue
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Chunk_LinearSearch_ProcessEvent(
    Fee_30_FlexNor_Chunk_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Chunk_AllocateInstance_Initialize()
 *********************************************************************************************************************/
/*! \brief       Initialize allocate instance state machine
 *  \details     -
 *  \param[in,out]  ctx        Pointer to the context for the read instance processing. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Chunk_AllocateInstance_Initialize(
    Fee_30_FlexNor_Chunk_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Chunk_AllocateInstance_ProcessEvent()
 *********************************************************************************************************************/
/*! \brief          Event handler for the Process event of the AllocateInstance state
 *  \details        -
 *  \param[in,out]  ctx        Pointer to the context for the state machine processing. Must not be NULL.
 *  \return         FEE_30_FLEXNOR_CONTINUE_SCHEDULE  Let the execution continue
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Chunk_AllocateInstance_ProcessEvent(
    Fee_30_FlexNor_Chunk_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Chunk_WriteLink_Initialize()
 *********************************************************************************************************************/
/*! \brief       Initializes the state machine for the write link service
 *  \details     -
 *  \param[in]   ctx           Context the state machine shall be initialized in. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Chunk_WriteLink_Initialize(Fee_30_FlexNor_Chunk_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Chunk_WriteLink_ProcessEvent()
 *********************************************************************************************************************/
/*! \brief          Event handler for the Process event of the WriteLink state
 *  \details        -
 *  \param[in,out]  ctx        Pointer to the context for the state machine processing. Must not be NULL.
 *  \return         FEE_30_FLEXNOR_CONTINUE_SCHEDULE  Let the execution continue
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Chunk_WriteLink_ProcessEvent(
    Fee_30_FlexNor_Chunk_ContextPtrType ctx);

#define FEE_30_FLEXNOR_STOP_SEC_CODE
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* FEE_30_FLEXNOR_CHUNKMACHINE_H */

/**********************************************************************************************************************
 *  END OF FILE: Fee_30_FlexNor_ChunkMachine.h
 *********************************************************************************************************************/
