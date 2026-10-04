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
/*!        \file  Fee_30_FlexNor_CopyBlockMachine.h
 *        \brief  State machine prototypes for the copy block unit
 *      \details  Provides the prototypes for the state machine implementation of the copy block unit.
 *         \unit  CopyBlock
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 **********************************************************************************************************************/

#if !defined (FEE_30_FLEXNOR_COPYBLOCKMACHINE_H)
# define FEE_30_FLEXNOR_COPYBLOCKMACHINE_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Fee_30_FlexNor_CopyBlockInternal.h"

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
 * Fee_30_FlexNor_CopyBlock_InitState()
 *********************************************************************************************************************/
/*! \brief          Initialize the internal state machine
 *  \details        -
 *  \param[in,out]  ctx                   Pointer to the context that shall be initialized. Must not be NULL.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_CopyBlock_InitState(Fee_30_FlexNor_CopyBlock_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_CopyBlock_DefaultProcessEvent()
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
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_CopyBlock_DefaultProcessEvent(Fee_30_FlexNor_CopyBlock_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_CopyBlock_DefaultFailEvent()
 *********************************************************************************************************************/
/*! \brief          Default Fail event handler
 *  \details        This function is never called in normal operation. It exists to be able to set the state machine
 *                  to a defined state in case no job is being executed.
 *  \param[in,out]  ctx         Pointer to the context for the state machine processing. Must not be NULL.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_CopyBlock_DefaultFailEvent(Fee_30_FlexNor_CopyBlock_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_CopyBlock_JobFailEvent()
 *********************************************************************************************************************/
/*! \brief       Fail event handler
 *  \details     Ends the current job and notifies the caller about the fail of the service.
 *  \param[in]   ctx            Pointer to the context of the service that failed. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_CopyBlock_JobFailEvent(Fee_30_FlexNor_CopyBlock_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_CopyBlock_FindLatestInstanceFailEvent()
 *********************************************************************************************************************/
/*! \brief       Fail event handler for the case that no valid instance was found.
 *  \details     Ends the current job. The caller is notified that the job finished successfully because the garbage
 *               collection shall skip the current block and proceed. Additionally it raises an exception that no valid 
 *               instance was found.
 *  \param[in]   ctx            Pointer to the context of the service that failed. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_CopyBlock_FindLatestInstanceFailEvent(
    Fee_30_FlexNor_CopyBlock_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_CopyBlock_Copy_Initialize()
 *********************************************************************************************************************/
/*! \brief       Initializes the copy state machine
 *  \details     -
 *  \param[in]   ctx            Pointer to the context containting the copy block data. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_CopyBlock_Copy_Initialize(
    Fee_30_FlexNor_CopyBlock_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_CopyBlock_ReadSourceChunk_ProcessEvent
 *********************************************************************************************************************/
/*! \brief          Event handler for the Process event of the ReadSourceChunk state
 *  \details        -
 *  \param[in,out]  ctx                               Pointer to the context for the state machine processing. Must not be NULL.
 *  \return         FEE_30_FLEXNOR_CONTINUE_SCHEDULE  Let the execution continue
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_CopyBlock_ReadSourceChunk_ProcessEvent(
    Fee_30_FlexNor_CopyBlock_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_CopyBlock_FindLatestInstance_ProcessEvent
 *********************************************************************************************************************/
/*! \brief          Event handler for the Process event of the FindLatestInstance state
 *  \details        -
 *  \param[in,out]  ctx                               Pointer to the context for the state machine processing. Must not be NULL.
 *  \return         FEE_30_FLEXNOR_CONTINUE_SCHEDULE  Let the execution continue
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_CopyBlock_FindLatestInstance_ProcessEvent(
    Fee_30_FlexNor_CopyBlock_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_CopyBlock_AllocateCopy_ProcessEvent
 *********************************************************************************************************************/
/*! \brief          Event handler for the Process event of the AllocateCopy state
 *  \details        -
 *  \param[in,out]  ctx                               Pointer to the context for the state machine processing. Must not be NULL.
 *  \return         FEE_30_FLEXNOR_CONTINUE_SCHEDULE  Let the execution continue
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_CopyBlock_AllocateCopy_ProcessEvent(
    Fee_30_FlexNor_CopyBlock_ContextPtrType ctx);


# define FEE_30_FLEXNOR_STOP_SEC_CODE
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* FEE_30_FLEXNOR_COPYBLOCKMACHINE_H */

/**********************************************************************************************************************
 *  END OF FILE: Fee_30_FlexNor_CopyBlockMachine.h
 *********************************************************************************************************************/
