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
/*!        \file  Fee_30_FlexNor_InternalJobsMachine.h
 *        \brief  State machine prototypes for the internal jobs unit
 *      \details  Provides the prototypes for the state machine implementation of the internal jobs unit.
 *         \unit  InternalJobs
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 **********************************************************************************************************************/

#if !defined(FEE_30_FLEXNOR_INTERNALJOBSMACHINE_H)
# define FEE_30_FLEXNOR_INTERNALJOBSMACHINE_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "Fee_30_FlexNor_InternalJobsInternal.h"

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
# include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Fee_30_FlexNor_InternalJobs_InitState()
 *********************************************************************************************************************/
/*! \brief          Initialize the internal state machine
 *  \details        -
 *  \param[in,out]  ctx    Pointer to the context that shall be initialized. Must not be NULL.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_InternalJobs_InitState(Fee_30_FlexNor_InternalJobs_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_InternalJobs_Run_Initialize()
 *********************************************************************************************************************/
/*! \brief       Initializes the internal jobs run state machine
 *  \details     -
 *  \param[in]   ctx    Pointer to the context containing the internal jobs data. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_InternalJobs_Run_Initialize(
  Fee_30_FlexNor_InternalJobs_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_InternalJobs_Startup_OnEnter()
 *********************************************************************************************************************/
/*! \brief       OnEnter function for Startup state.
 *  \details     Checks if the current partition is started up and triggers the startup process if not.
 *  \param[in]   ctx    Pointer to the context containing the required data for the sector recovery handling. Must not 
 *                      be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_InternalJobs_Startup_OnEnter(
  Fee_30_FlexNor_InternalJobs_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_InternalJobs_Startup_ProcessEvent
 *********************************************************************************************************************/
/*! \brief          Event handler for the Process event of the Startup state
 *  \details        -
 *  \param[in,out]  ctx     Pointer to the context for the state machine processing. Must not be NULL.
 *  \return         FEE_30_FLEXNOR_CONTINUE_SCHEDULE  Let the execution continue
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_InternalJobs_Startup_ProcessEvent(
  Fee_30_FlexNor_InternalJobs_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_InternalJobs_FinishGarbageCollection_OnEnter()
 *********************************************************************************************************************/
/*! \brief       OnEnter function for FinishGarbageCollection state.
 *  \details     Checks if a garbage collection is pending for the current partition. If yes it triggers it.
 *  \param[in]   ctx    Pointer to the context containing the required data for the sector recovery handling. Must not 
 *                      be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_InternalJobs_FinishGarbageCollection_OnEnter(
  Fee_30_FlexNor_InternalJobs_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_InternalJobs_FinishGarbageCollection_ProcessEvent
 *********************************************************************************************************************/
/*! \brief          Event handler for the Process event of the FinishGarbageCollection state
 *  \details        -
 *  \param[in,out]  ctx     Pointer to the context for the state machine processing. Must not be NULL.
 *  \return         FEE_30_FLEXNOR_CONTINUE_SCHEDULE  Let the execution continue
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) 
Fee_30_FlexNor_InternalJobs_FinishGarbageCollection_ProcessEvent(Fee_30_FlexNor_InternalJobs_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_InternalJobs_RecoverSector_OnEnter()
 *********************************************************************************************************************/
/*! \brief       OnEnter function for RecoverSector state.
 *  \details     -
 *  \param[in]   ctx    Pointer to the context containing the required data for the sector recovery handling. Must not 
 *                      be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_InternalJobs_RecoverSector_OnEnter(
  Fee_30_FlexNor_InternalJobs_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_InternalJobs_RecoverSector_ProcessEvent()
 *********************************************************************************************************************/
/*! \brief          Event handler for the Process event of the RecoverSector state
 *  \details        -
 *  \param[in,out]  ctx    Pointer to the context for the state machine processing. Must not be NULL.
 *  \return         FEE_30_FLEXNOR_CONTINUE_SCHEDULE  Let the execution continue
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_InternalJobs_RecoverSector_ProcessEvent(
  Fee_30_FlexNor_InternalJobs_ContextPtrType ctx);

 /**********************************************************************************************************************
 * Fee_30_FlexNor_InternalJobs_ReallocateChunk_OnEnter()
 *********************************************************************************************************************/
/*! \brief       OnEnter function for ReallocateChunk state.
 *  \details     -
 *  \param[in]   ctx    Pointer to the context containing the required data for the sector recovery handling. Must not  
 *                      be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_InternalJobs_ReallocateChunk_OnEnter(
  Fee_30_FlexNor_InternalJobs_ContextPtrType ctx);


 /**********************************************************************************************************************
 * Fee_30_FlexNor_InternalJobs_ReallocateChunk_ProcessEvent()
 *********************************************************************************************************************/
/*! \brief          Event handler for the Process event of the ReallocateChunk state
 *  \details        -
 *  \param[in,out]  ctx    Pointer to the context for the state machine processing. Must not be NULL.
 *  \return         FEE_30_FLEXNOR_CONTINUE_SCHEDULE  Let the execution continue
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_InternalJobs_ReallocateChunk_ProcessEvent(
  Fee_30_FlexNor_InternalJobs_ContextPtrType ctx);


# define FEE_30_FLEXNOR_STOP_SEC_CODE
# include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* FEE_30_FLEXNOR_INTERNALJOBSMACHINE_H */

/**********************************************************************************************************************
 *  END OF FILE: Fee_30_FlexNor_InternalJobsMachine.h
 *********************************************************************************************************************/
