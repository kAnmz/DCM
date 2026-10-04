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
/*!        \file  Fee_30_FlexNor_SlimInstanceMachine.h
 *        \brief  state machine prototypes for slim instance
 *      \details  Provides the prototypes for the state machine implementation of the slim instance unit.
 *         \unit  SlimInstance
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 **********************************************************************************************************************/

#if !defined(FEE_30_FLEXNOR_SLIMINSTANCEMACHINE_H)
#    define FEE_30_FLEXNOR_SLIMINSTANCEMACHINE_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#    include "Fee_30_FlexNor_SlimInstanceInternal.h"

#    if (FEE_30_FLEXNOR_SLIMLAYOUT_ENABLED == STD_ON) /* COV_MSR_UT_OPTIONAL_UNIT */

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
#        define FEE_30_FLEXNOR_START_SEC_CODE
#        include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimInstance_InitState()
 *********************************************************************************************************************/
/*! \brief          Initialize the internal state machine
 *  \details        -
 *  \param[in,out]  ctx                   Pointer to the context that shall be initialized. Must not be NULL.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimInstance_InitState(Fee_30_FlexNor_SlimInstance_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimInstance_DefaultProcessEvent()
 *********************************************************************************************************************/
/*! \brief          Default Process event handler
 *  \details        This function is never called in normal operation. It exists to be able to set the state machine
 *                  to a defined state in case no job is being executed.
 *  \param[in,out]  ctx                           Pointer to the context for the state machine processing. Must not be NULL.
 *  \return         FEE_30_FLEXNOR_STOP_SCHEDULE  Always stops the scheduler
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimInstance_DefaultProcessEvent(
    Fee_30_FlexNor_SlimInstance_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimInstance_DefaultFailEvent()
 *********************************************************************************************************************/
/*! \brief          Default Fail event handler
 *  \details        This function is never called in normal operation. It exists to be able to set the state machine
 *                  to a defined state in case no job is being executed.
 *  \param[in,out]  ctx                           Pointer to the context for the state machine processing. Must not be NULL.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimInstance_DefaultFailEvent(Fee_30_FlexNor_SlimInstance_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimInstance_JobFailEvent()
 *********************************************************************************************************************/
/*! \brief       Fail event handler
 *  \details     Ends the current job and notifies the caller about the fail of the service.
 *  \param[in]   ctx               Pointer to the context of the service that failed. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimInstance_JobFailEvent(Fee_30_FlexNor_SlimInstance_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimInstance_WriteFailEvent()
 *********************************************************************************************************************/
/*! \brief       Fail event handler for failed write jobs
 *  \details     Ends the current job, triggers a garbage collection for the sector and notifies the caller about the fail of the service.
 *  \param[in]   ctx               Pointer to the context of the service that failed. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimInstance_WriteFailEvent(Fee_30_FlexNor_SlimInstance_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimInstance_CancelProtectedWriteFailEvent()
 *********************************************************************************************************************/
/*! \brief       Fail event handler for failed write jobs of cancel protected writes
 *  \details     Allows cancellation again and executes the normal write fail event procedure afterwards.
 *  \param[in]   ctx               Pointer to the context of the service that failed. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimInstance_CancelProtectedWriteFailEvent(Fee_30_FlexNor_SlimInstance_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimInstance_CancelProtectedJobFailEvent()
 *********************************************************************************************************************/
/*! \brief       Fail event handler for failed cancel protected jobs
 *  \details     Allows cancellation again and executes the normal job fail event procedure afterwards.
 *  \param[in]   ctx               Pointer to the context of the service that failed. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimInstance_CancelProtectedJobFailEvent(Fee_30_FlexNor_SlimInstance_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimInstance_Validate_Initialize()
 *********************************************************************************************************************/
/*! \brief          Initialize validate state machine
 *  \details        Initializes and starts the asynchronous state machine for validating the instances.
 *  \param[in,out]  ctx                 Pointer to the context for the state machine processing. Must not be NULL.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimInstance_Validate_Initialize(Fee_30_FlexNor_SlimInstance_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimInstance_ReadMetadata_ProcessEvent()
 *********************************************************************************************************************/
/*! \brief          Event handler for the Process event of the ReadMetadata state
 *  \details        -
 *  \param[in,out]  ctx                               Pointer to the context for the state machine processing. Must not be NULL.
 *  \return         FEE_30_FLEXNOR_CONTINUE_SCHEDULE  Let the execution continue
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimInstance_ReadMetadata_ProcessEvent(
    Fee_30_FlexNor_SlimInstance_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimInstance_ReadMetaDataFailEvent()
 *********************************************************************************************************************/
/*! \brief       Fail event handler for ReadMetadata state
 *  \details     Ends the current job and notifies the caller about the fail of the service.
 *  \param[in]   ctx               Pointer to the context for the state machine processing. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimInstance_ReadMetaDataFailEvent(Fee_30_FlexNor_SlimInstance_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimInstance_ReadCommitMarker_ProcessEvent()
 *********************************************************************************************************************/
/*! \brief          Event handler for the Process event of the ReadCommitMarker state
 *  \details        -
 *  \param[in,out]  ctx                               Pointer to the context for the state machine processing. Must not be NULL.
 *  \return         FEE_30_FLEXNOR_CONTINUE_SCHEDULE  Let the execution continue
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimInstance_ReadCommitMarker_ProcessEvent(Fee_30_FlexNor_SlimInstance_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimInstance_ReadCommitMarkerFailEvent()
 *********************************************************************************************************************/
/*! \brief       Fail event handler for ReadCommitMarker state
 *  \details     Ends the current job and notifies the caller about the fail of the service.
 *  \param[in]   ctx               Pointer to the context for the state machine processing. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE)Fee_30_FlexNor_SlimInstance_ReadCommitMarkerFailEvent(Fee_30_FlexNor_SlimInstance_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimInstance_ReadStatusForValidation_ProcessEvent()
 *********************************************************************************************************************/
/*! \brief          Event handler for the Process event of the ReadStatusForValidation state
 *  \details        -
 *  \param[in,out]  ctx                               Pointer to the context for the state machine processing. Must not be NULL.
 *  \return         FEE_30_FLEXNOR_CONTINUE_SCHEDULE  Let the execution continue
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimInstance_ReadStatusForValidation_ProcessEvent(Fee_30_FlexNor_SlimInstance_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimInstance_ReadStatusForValidationFailEvent()
 *********************************************************************************************************************/
/*! \brief       Fail event handler for ReadStatusForValidation state
 *  \details     Ends the current job and notifies the caller about the fail of the service.
 *  \param[in]   ctx               Pointer to the context for the state machine processing. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE)Fee_30_FlexNor_SlimInstance_ReadStatusForValidationFailEvent(Fee_30_FlexNor_SlimInstance_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimInstance_ReadContent_Initialize()
 *********************************************************************************************************************/
/*! \brief          Initialize read content state machine
 *  \details        Initializes and starts the asynchronous state machine for reading the instance content.
 *  \param[in,out]  ctx                 Pointer to the context for the state machine processing. Must not be NULL.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimInstance_ReadContent_Initialize(Fee_30_FlexNor_SlimInstance_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimInstance_Write_Initialize()
 *********************************************************************************************************************/
/*! \brief          Initialize write state machine
 *  \details        Initializes and starts the asynchronous state machine for writing and instance to the flash.
 *  \param[in,out]  ctx                 Pointer to the context for the state machine processing. Must not be NULL.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimInstance_Write_Initialize(Fee_30_FlexNor_SlimInstance_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimInstance_WritePayload_ProcessEvent()
 *********************************************************************************************************************/
/*! \brief          Event handler for the Process event of the WritePayload state
 *  \details        -
 *  \param[in,out]  ctx                               Pointer to the context for the state machine processing. Must not be NULL.
 *  \return         FEE_30_FLEXNOR_CONTINUE_SCHEDULE  Let the execution continue
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimInstance_WritePayload_ProcessEvent(
    Fee_30_FlexNor_SlimInstance_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimInstance_WriteCommitMarker_ProcessEvent()
 *********************************************************************************************************************/
/*! \brief          Event handler for the Process event of the WriteCommitMarker state
 *  \details        -
 *  \param[in,out]  ctx                               Pointer to the context for the state machine processing. Must not be NULL.
 *  \return         FEE_30_FLEXNOR_CONTINUE_SCHEDULE  Let the execution continue
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimInstance_WriteCommitMarker_ProcessEvent(
    Fee_30_FlexNor_SlimInstance_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimInstance_Copy_Initialize()
 *********************************************************************************************************************/
/*! \brief          Initialize copy state machine
 *  \details        Initializes and starts the asynchronous state machine for copying an instance.
 *  \param[in,out]  ctx             Pointer to the context for the state machine processing. Must not be NULL.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimInstance_Copy_Initialize(Fee_30_FlexNor_SlimInstance_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimInstance_ReadSourceContent_ProcessEvent()
 *********************************************************************************************************************/
/*! \brief          Event handler for the Process event of the ReadSourceContent state
 *  \details        -
 *  \param[in,out]  ctx             Pointer to the context for the state machine processing. Must not be NULL.
 *  \return         FEE_30_FLEXNOR_CONTINUE_SCHEDULE  Let the execution continue
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimInstance_ReadSourceContent_ProcessEvent(
    Fee_30_FlexNor_SlimInstance_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimInstance_WriteTargetContent_ProcessEvent()
 *********************************************************************************************************************/
/*! \brief          Event handler for the Process event of the WriteTargetContent state
 *  \details        -
 *  \param[in,out]  ctx             Pointer to the context for the state machine processing. Must not be NULL.
 *  \return         FEE_30_FLEXNOR_CONTINUE_SCHEDULE  Let the execution continue
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimInstance_WriteTargetContent_ProcessEvent(
    Fee_30_FlexNor_SlimInstance_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimInstance_CopyCommitMarker_ProcessEvent()
 *********************************************************************************************************************/
/*! \brief          Event handler for the Process event of the CopyCommitMarker state
 *  \details        -
 *  \param[in,out]  ctx             Pointer to the context for the state machine processing. Must not be NULL.
 *  \return         FEE_30_FLEXNOR_CONTINUE_SCHEDULE  Let the execution continue
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimInstance_CopyCommitMarker_ProcessEvent(
    Fee_30_FlexNor_SlimInstance_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimInstance_ReadStatus_ProcessEvent()
 *********************************************************************************************************************/
/*! \brief          Event handler for the Process event of the ReadStatus state
 *  \details        -
 *  \param[in,out]  ctx                               Pointer to the context for the state machine processing. Must not 
 *                                                    be NULL.
 *  \return         FEE_30_FLEXNOR_CONTINUE_SCHEDULE  Let the execution continue
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimInstance_ReadStatus_ProcessEvent(
    Fee_30_FlexNor_SlimInstance_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimInstance_ReadOffsetPage_ProcessEvent()
 *********************************************************************************************************************/
/*! \brief          Event handler for the Process event of the ReadOffsetPage state
 *  \details        -
 *  \param[in,out]  ctx                               Pointer to the context for the state machine processing. Must not 
 *                                                    be NULL.
 *  \return         FEE_30_FLEXNOR_CONTINUE_SCHEDULE  Let the execution continue
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) 
    Fee_30_FlexNor_SlimInstance_ReadOffsetPage_ProcessEvent(
        Fee_30_FlexNor_SlimInstance_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimInstance_ReadCompletelyFilledPages_ProcessEvent()
 *********************************************************************************************************************/
/*! \brief          Event handler for the Process event of the ReadCompletelyFilledPages state
 *  \details        -
 *  \param[in,out]  ctx                               Pointer to the context for the state machine processing. Must not 
 *                                                    be NULL.
 *  \return         FEE_30_FLEXNOR_CONTINUE_SCHEDULE  Let the execution continue
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) 
    Fee_30_FlexNor_SlimInstance_ReadCompletelyFilledPages_ProcessEvent(
        Fee_30_FlexNor_SlimInstance_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimInstance_ReadLastPage_ProcessEvent()
 *********************************************************************************************************************/
/*! \brief          Event handler for the Process event of the ReadLastPage state
 *  \details        -
 *  \param[in,out]  ctx                               Pointer to the context for the state machine processing. Must not 
 *                                                    be NULL.
 *  \return         FEE_30_FLEXNOR_CONTINUE_SCHEDULE  Let the execution continue
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) 
    Fee_30_FlexNor_SlimInstance_ReadLastPage_ProcessEvent(
        Fee_30_FlexNor_SlimInstance_ContextPtrType ctx);

#        define FEE_30_FLEXNOR_STOP_SEC_CODE
#        include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#    endif

#endif /* FEE_30_FLEXNOR_SLIMINSTANCEMACHINE_H */

/**********************************************************************************************************************
 *  END OF FILE: Fee_30_FlexNor_SlimInstanceMachine.h
 *********************************************************************************************************************/
