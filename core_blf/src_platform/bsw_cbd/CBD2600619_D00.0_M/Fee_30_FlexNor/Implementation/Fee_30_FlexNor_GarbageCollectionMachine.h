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
/*!        \file  Fee_30_FlexNor_GarbageCollectionMachine.h
 *        \brief  State machine prototypes for the garbage collection unit
 *      \details  Provides the prototypes for the state machine implementation of the garbage collection unit.
 *         \unit  GarbageCollection
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 **********************************************************************************************************************/

#if !defined (FEE_30_FLEXNOR_GARBAGECOLLECTIONMACHINE_H)
# define FEE_30_FLEXNOR_GARBAGECOLLECTIONMACHINE_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Fee_30_FlexNor_GarbageCollectionInternal.h"

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
# define FEE_30_FLEXNOR_START_SEC_CODE
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Fee_30_FlexNor_GarbageCollection_InitState()
 *********************************************************************************************************************/
/*! \brief          Initialize the internal state machine
 *  \details        -
 *  \param[in,out]  ctx                   Pointer to the context that shall be initialized. Must not be NULL.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_GarbageCollection_InitState(
    Fee_30_FlexNor_GarbageCollection_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_GarbageCollection_DefaultProcessEvent()
 *********************************************************************************************************************/
/*! \brief          Default Process event handler
 *  \details        This function is never called in normal operation. It exists to be able to set the state machine
 *                  to a defined state in case no job is being executed.
 *  \param[in,out]  ctx    Pointer to the context for the state machine processing. Must not be NULL.
 *  \return         FEE_30_FLEXNOR_STOP_SCHEDULE  Always stops the scheduler
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_GarbageCollection_DefaultProcessEvent(
    Fee_30_FlexNor_GarbageCollection_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_GarbageCollection_DefaultFailEvent()
 *********************************************************************************************************************/
/*! \brief          Default Fail event handler
 *  \details        This function is never called in normal operation. It exists to be able to set the state machine
 *                  to a defined state in case no job is being executed.
 *  \param[in,out]  ctx    Pointer to the context for the state machine processing. Must not be NULL.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_GarbageCollection_DefaultFailEvent(
    Fee_30_FlexNor_GarbageCollection_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_GarbageCollection_JobFailEvent()
 *********************************************************************************************************************/
/*! \brief       Fail event handler
 *  \details     Ends the current job and notifies the caller about the fail of the service.
 *  \param[in]   ctx    Pointer to the context of the service that failed. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_GarbageCollection_JobFailEvent(
    Fee_30_FlexNor_GarbageCollection_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_GarbageCollection_FailRetryEvent()
 *********************************************************************************************************************/
/*! \brief       Fail event handler for states with retry mechanism
 *  \details     If retry counter is not exceeded: Prepares garbage collection restart and triggeres look up table 
 *               recovery.
 *               If retry counter is exceeded: Ends the current job and notifies the caller about the fail of the 
 *               service.
 *  \param[in]   ctx    Pointer to the context of the service that failed. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_GarbageCollection_FailRetryEvent(
    Fee_30_FlexNor_GarbageCollection_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_GarbageCollection_Run_Initialize()
 *********************************************************************************************************************/
/*! \brief       Initializes the garbage collection state machine
 *  \details     -
 *  \param[in]   ctx    Pointer to the context containting the garbage collection data. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_GarbageCollection_Run_Initialize(
    Fee_30_FlexNor_GarbageCollection_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_GarbageCollection_RecoverLookupTable_ProcessEvent
 *********************************************************************************************************************/
/*! \brief          Event handler for the Process event of the RecoverLookupTable state
 *  \details        -
 *  \param[in,out]  ctx    Pointer to the context for the state machine processing. Must not be NULL.
 *  \return         FEE_30_FLEXNOR_CONTINUE_SCHEDULE  Let the execution continue
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) 
    Fee_30_FlexNor_GarbageCollection_RecoverLookupTable_ProcessEvent(
        Fee_30_FlexNor_GarbageCollection_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_GarbageCollection_SetupTargetSector_ProcessEvent
 *********************************************************************************************************************/
/*! \brief          Event handler for the Process event of the SetupTargetSector state
 *  \details        -
 *  \param[in,out]  ctx    Pointer to the context for the state machine processing. Must not be NULL.
 *  \return         FEE_30_FLEXNOR_CONTINUE_SCHEDULE  Let the execution continue
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) 
    Fee_30_FlexNor_GarbageCollection_SetupTargetSector_ProcessEvent(
        Fee_30_FlexNor_GarbageCollection_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_GarbageCollection_StoreSourceSector_ProcessEvent
 *********************************************************************************************************************/
/*! \brief          Event handler for the Process event of the StoreSourceSector state
 *  \details        -
 *  \param[in,out]  ctx    Pointer to the context for the state machine processing. Must not be NULL.
 *  \return         FEE_30_FLEXNOR_CONTINUE_SCHEDULE  Let the execution continue
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) 
    Fee_30_FlexNor_GarbageCollection_StoreSourceSector_ProcessEvent(
        Fee_30_FlexNor_GarbageCollection_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_GarbageCollection_CopyBlock_ProcessEvent
 *********************************************************************************************************************/
/*! \brief          Event handler for the Process event of the CopyBlock state
 *  \details        -
 *  \param[in,out]  ctx    Pointer to the context for the state machine processing. Must not be NULL.
 *  \return         FEE_30_FLEXNOR_CONTINUE_SCHEDULE  Let the execution continue
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_GarbageCollection_CopyBlock_ProcessEvent(
    Fee_30_FlexNor_GarbageCollection_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_GarbageCollection_MarkForErase_ProcessEvent
 *********************************************************************************************************************/
/*! \brief          Event handler for the Process event of the MarkForErase state
 *  \details        -
 *  \param[in,out]  ctx    Pointer to the context for the state machine processing. Must not be NULL.
 *  \return         FEE_30_FLEXNOR_CONTINUE_SCHEDULE  Let the execution continue
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) 
    Fee_30_FlexNor_GarbageCollection_MarkForErase_ProcessEvent(Fee_30_FlexNor_GarbageCollection_ContextPtrType ctx);

# define FEE_30_FLEXNOR_STOP_SEC_CODE
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* FEE_30_FLEXNOR_GARBAGECOLLECTIONMACHINE_H */

/**********************************************************************************************************************
 *  END OF FILE: Fee_30_FlexNor_GarbageCollectionMachine.h
 *********************************************************************************************************************/
