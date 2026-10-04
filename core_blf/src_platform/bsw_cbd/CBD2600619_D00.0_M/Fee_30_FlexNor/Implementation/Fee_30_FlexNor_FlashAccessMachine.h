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
/*!        \file  Fee_30_FlexNor_FlashAccessMachine.h
 *        \brief  State machine prototypes for flash access
 *      \details  Provides the prototypes for the state machine implementation of the flash access unit.
 *         \unit  FlashAccess
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 **********************************************************************************************************************/

#if !defined (FEE_30_FLEXNOR_FLASHACCESSMACHINE_H)
# define FEE_30_FLEXNOR_FLASHACCESSMACHINE_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Fee_30_FlexNor_FlashAccessInternal.h"

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
# define FEE_30_FLEXNOR_START_SEC_CODE
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Fee_30_FlexNor_FlashAccess_InitState()
 *********************************************************************************************************************/
/*! \brief          Initialize the internal state machine
 *  \details        -
 *  \param[in,out]  ctx                   Pointer to the context that shall be initialized. Must not be NULL.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_FlashAccess_InitState(Fee_30_FlexNor_FlashAccess_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_FlashAccess_DefaultProcessEvent()
 *********************************************************************************************************************/
/*! \brief          Default Process event handler
 *  \details        This function is never called in normal operation. It exists to be able to set the state machine
 *                  to a defined state in case no job is being executed.
 *  \param[in,out]  ctx                     Pointer to the context for the state machine processing. Must not be NULL.
 *  \return         FEE_30_FLEXNOR_STOP_SCHEDULE  Always stops the scheduler
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_FlashAccess_DefaultProcessEvent(
    Fee_30_FlexNor_FlashAccess_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_FlashAccess_InitializeJob()
 *********************************************************************************************************************/
/*! \brief          Initialize state machine of the requested job.
 *  \details        Initializes and starts the asynchronous state machine for the requested job.
 *  \param[in,out]  ctx                 Pointer to the context for the state machine processing. Must not be NULL.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_FlashAccess_InitializeJob(Fee_30_FlexNor_FlashAccess_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_FlashAccess_WaitUntilIdle_OnEnter()
 *********************************************************************************************************************/
/*! \brief          OnEnter function for WaitUntilIdle state
 *  \details        -
 *  \param[in,out]  ctx                 Pointer to the context for the state machine processing. Must not be NULL.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_FlashAccess_WaitUntilIdle_OnEnter(
    Fee_30_FlexNor_FlashAccess_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_FlashAccess_WaitUntilIdle_ProcessEvent()
 *********************************************************************************************************************/
/*! \brief          Event handler for the Process event of the WaitUntilIdle state
 *  \details        -
 *  \param[in,out]  ctx                               Pointer to the context for the state machine processing. 
 *                                                    Must not be NULL.
 *  \return         FEE_30_FLEXNOR_STOP_SCHEDULE      If the lower layer is still pending
 *                  FEE_30_FLEXNOR_CONTINUE_SCHEDULE  If the lower layer is idle and the execution can be continued
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) 
    Fee_30_FlexNor_FlashAccess_WaitUntilIdle_ProcessEvent(Fee_30_FlexNor_FlashAccess_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_FlashAccess_ReadFlash_OnEnter()
 *********************************************************************************************************************/
/*! \brief          OnEnter function for ReadFlash state
 *  \details        -
 *  \param[in,out]  ctx                 Pointer to the context for the state machine processing. Must not be NULL.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_FlashAccess_ReadFlash_OnEnter(
    Fee_30_FlexNor_FlashAccess_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_FlashAccess_ReadFlash_ProcessEvent()
 *********************************************************************************************************************/
/*! \brief          Event handler for the Process event of the ReadFlash state
 *  \details        -
 *  \param[in,out]  ctx                               Pointer to the context for the state machine processing. 
 *                                                    Must not be NULL.
 *  \return         FEE_30_FLEXNOR_STOP_SCHEDULE      If the job is still pending
 *                  FEE_30_FLEXNOR_CONTINUE_SCHEDULE  If the job was completed and the execution can be continued
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_FlashAccess_ReadFlash_ProcessEvent(
    Fee_30_FlexNor_FlashAccess_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_FlashAccess_BlankCheck_OnEnter()
 *********************************************************************************************************************/
/*! \brief          OnEnter function for BlankCheck state
 *  \details        -
 *  \param[in,out]  ctx                 Pointer to the context for the state machine processing. Must not be NULL.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_FlashAccess_BlankCheck_OnEnter(
    Fee_30_FlexNor_FlashAccess_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_FlashAccess_BlankCheck_ProcessEvent()
 *********************************************************************************************************************/
/*! \brief          Event handler for the Process event of the BlankCheck state
 *  \details        -
 *  \param[in,out]  ctx                 Pointer to the context for the state machine processing. Must not be NULL.
 *  \return         FEE_30_FLEXNOR_STOP_SCHEDULE      If the job is still pending
 *                  FEE_30_FLEXNOR_CONTINUE_SCHEDULE  If the job was completed and the execution can be continued
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_FlashAccess_BlankCheck_ProcessEvent(
    Fee_30_FlexNor_FlashAccess_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_FlashAccess_WriteFlash_OnEnter()
 *********************************************************************************************************************/
/*! \brief          OnEnter function for WriteFlash state
 *  \details        -
 *  \param[in,out]  ctx                 Pointer to the context for the state machine processing. Must not be NULL.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_FlashAccess_WriteFlash_OnEnter(
    Fee_30_FlexNor_FlashAccess_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_FlashAccess_WriteFlash_ProcessEvent()
 *********************************************************************************************************************/
/*! \brief          Event handler for the Process event of the WriteFlash state
 *  \details        -
 *  \param[in,out]  ctx                 Pointer to the context for the state machine processing. Must not be NULL.
 *  \return         FEE_30_FLEXNOR_STOP_SCHEDULE      If the job is still pending
 *                  FEE_30_FLEXNOR_CONTINUE_SCHEDULE  If the job was completed and the execution can be continued
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_FlashAccess_WriteFlash_ProcessEvent(
    Fee_30_FlexNor_FlashAccess_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_FlashAccess_EraseFlash_OnEnter()
 *********************************************************************************************************************/
/*! \brief          OnEnter function for EraseFlash state
 *  \details        -
 *  \param[in,out]  ctx                 Pointer to the context for the state machine processing. Must not be NULL.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_FlashAccess_EraseFlash_OnEnter(
    Fee_30_FlexNor_FlashAccess_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_FlashAccess_EraseFlash_ProcessEvent()
 *********************************************************************************************************************/
/*! \brief          Event handler for the Process event of the EraseFlash state
 *  \details        -
 *  \param[in,out]  ctx                 Pointer to the context for the state machine processing. Must not be NULL.
 *  \return         FEE_30_FLEXNOR_STOP_SCHEDULE      If the job is still pending
 *                  FEE_30_FLEXNOR_CONTINUE_SCHEDULE  If the job was completed and the execution can be continued
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_FlashAccess_EraseFlash_ProcessEvent(
    Fee_30_FlexNor_FlashAccess_ContextPtrType ctx);

# define FEE_30_FLEXNOR_STOP_SEC_CODE
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* FEE_30_FLEXNOR_FLASHACCESSMACHINE_H */

/**********************************************************************************************************************
 *  END OF FILE: Fee_30_FlexNor_FlashAccessMachine.h
 *********************************************************************************************************************/
