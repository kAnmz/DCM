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
/*!        \file  Fee_30_FlexNor_LookupTableMachine.h
 *        \brief  State machine prototypes for the lookup table unit
 *      \details  Provides the prototypes for the state machine implementation of the lookup table unit.
 *         \unit  LookupTable
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 **********************************************************************************************************************/

#if !defined (FEE_30_FLEXNOR_LOOKUPTABLEMACHINE_H)
# define FEE_30_FLEXNOR_LOOKUPTABLEMACHINE_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Fee_30_FlexNor_LookupTableInternal.h"

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
 * Fee_30_FlexNor_LookupTable_InitState()
 *********************************************************************************************************************/
/*! \brief          Initialize the internal state machine
 *  \details        -
 *  \param[in,out]  ctx    Pointer to the context that shall be initialized. Must not be NULL.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_InitState(Fee_30_FlexNor_LookupTable_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_DefaultProcessEvent()
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
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_DefaultProcessEvent(
        Fee_30_FlexNor_LookupTable_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_DefaultFailEvent()
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
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_DefaultFailEvent(
        Fee_30_FlexNor_LookupTable_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_JobFailEventWithoutNotification()
 *********************************************************************************************************************/
/*! \brief       Fail event handler
 *  \details     Ends the current job.
 *  \param[in]   ctx    Pointer to the context of the service that failed. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_JobFailEventWithoutNotification(
        Fee_30_FlexNor_LookupTable_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_JobFailEventWithNotification()
 *********************************************************************************************************************/
/*! \brief       Fail event handler
 *  \details     Ends the current job and notifies the caller about the fail of the service.
 *  \param[in]   ctx    Pointer to the context of the service that failed. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_JobFailEventWithNotification(
        Fee_30_FlexNor_LookupTable_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_LoadLutFailEventWithNotification()
 *********************************************************************************************************************/
/*! \brief       Fail event handler for lookup table load service.
 *  \details     Sets the milestone that the lookup table loading is finished, ends the current job and notifies the 
 *               caller about the fail of the service.
 *  \param[in]   ctx    Pointer to the context of the service that failed. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_LoadLutFailEventWithNotification(
        Fee_30_FlexNor_LookupTable_ContextPtrType ctx);
        
/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_InstanceSearchFailEvent()
 *********************************************************************************************************************/
/*! \brief       Fail event handler which handles the case that no lookup table instance was found. 
 *  \details     Ends the current job and notifies the caller that no lookup table can be loaded. 
 *  \param[in]   ctx    Pointer to the context of the service that failed. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_InstanceSearchFailEvent(
        Fee_30_FlexNor_LookupTable_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_Recover_Initialize()
 *********************************************************************************************************************/
/*! \brief          Initializes the Recover state machine
 *  \details        -
 *  \param[in,out]  ctx    Pointer to the context for the state machine processing. Must not be NULL.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_Recover_Initialize(
        Fee_30_FlexNor_LookupTable_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_ScanSector_ProcessEvent
 *********************************************************************************************************************/
/*! \brief          Event handler for the Process event of the ScanSector state
 *  \details        -
 *  \param[in,out]  ctx    Pointer to the context for the state machine processing. Must not be NULL.
 *  \return         FEE_30_FLEXNOR_CONTINUE_SCHEDULE  Let the execution continue
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_ScanSector_ProcessEvent
(Fee_30_FlexNor_LookupTable_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_Persist_Initialize()
 *********************************************************************************************************************/
/*! \brief          Initializes the Persist state machine
 *  \details        -
 *  \param[in,out]  ctx    Pointer to the context for the state machine processing. Must not be NULL.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_Persist_Initialize(
        Fee_30_FlexNor_LookupTable_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_WriteBlock_ProcessEvent
 *********************************************************************************************************************/
/*! \brief          Event handler for the Process event of the WriteBlock state
 *  \details        -
 *  \param[in,out]  ctx    Pointer to the context for the state machine processing. Must not be NULL.
 *  \return         FEE_30_FLEXNOR_CONTINUE_SCHEDULE  Let the execution continue
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_WriteBlock_ProcessEvent(
        Fee_30_FlexNor_LookupTable_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_WriteShortcut_ProcessEvent
 *********************************************************************************************************************/
/*! \brief          Event handler for the Process event of the WriteShortcut state
 *  \details        -
 *  \param[in,out]  ctx    Pointer to the context for the state machine processing. Must not be NULL.
 *  \return         FEE_30_FLEXNOR_CONTINUE_SCHEDULE  Let the execution continue
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_WriteShortcut_ProcessEvent(
        Fee_30_FlexNor_LookupTable_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_Load_Initialize()
 *********************************************************************************************************************/
/*! \brief          Initializes the Load state machine
 *  \details        -
 *  \param[in,out]  ctx    Pointer to the context for the state machine processing. Must not be NULL.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_Load_Initialize(
        Fee_30_FlexNor_LookupTable_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_FindMostRecentLutChunk_ProcessEvent
 *********************************************************************************************************************/
/*! \brief          Event handler for the Process event of the FindMostRecentLutChunk state
 *  \details        -
 *  \param[in,out]  ctx    Pointer to the context for the state machine processing. Must not be NULL.
 *  \return         FEE_30_FLEXNOR_CONTINUE_SCHEDULE  Let the execution continue
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) 
        Fee_30_FlexNor_LookupTable_FindMostRecentLutChunk_ProcessEvent(Fee_30_FlexNor_LookupTable_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_FindMostRecentLutInstance_ProcessEvent
 *********************************************************************************************************************/
/*! \brief          Event handler for the Process event of the FindMostRecentLutInstance state
 *  \details        -
 *  \param[in,out]  ctx    Pointer to the context for the state machine processing. Must not be NULL.
 *  \return         FEE_30_FLEXNOR_CONTINUE_SCHEDULE  Let the execution continue
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) 
        Fee_30_FlexNor_LookupTable_FindMostRecentLutInstance_ProcessEvent(
                Fee_30_FlexNor_LookupTable_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_ReadMostRecentLutPayload_ProcessEvent
 *********************************************************************************************************************/
/*! \brief          Event handler for the Process event of the ReadMostRecentLutPayload state
 *  \details        -
 *  \param[in,out]  ctx    Pointer to the context for the state machine processing. Must not be NULL.
 *  \return         FEE_30_FLEXNOR_CONTINUE_SCHEDULE  Let the execution continue
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) 
        Fee_30_FlexNor_LookupTable_ReadMostRecentLutPayload_ProcessEvent(Fee_30_FlexNor_LookupTable_ContextPtrType ctx);

# define FEE_30_FLEXNOR_STOP_SEC_CODE
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* FEE_30_FLEXNOR_LOOKUPTABLEMACHINE_H */

/**********************************************************************************************************************
 *  END OF FILE: Fee_30_Flexnor_LookupTableMachine.h
 *********************************************************************************************************************/
