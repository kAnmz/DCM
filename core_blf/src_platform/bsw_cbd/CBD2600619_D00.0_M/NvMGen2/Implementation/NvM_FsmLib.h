/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2026 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!        \file  NvM_FsmLib.h
 *        \brief  NvM_FsmLib header file
 *      \details  Header of FSM library unit of the NvM.
 *                This unit takes care of two tasks:
 *                - Utility methods for FSM/state handling (acting as a library to normalize usage)
 *                - Processing interface for the current active NvM FSM
 *                It acts as a broker between the NvM main function and the FSM world.
 *         \unit  NvM_FsmLib
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#if !defined (NVM_FSMLIB)
# define NVM_FSMLIB

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "NvM_Types.h"
# include "NvM_InternalTypes.h"
# include "NvM_Cfg.h"

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define NVM_START_SEC_CODE
#include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * NvM_FsmLib_Init()
 *********************************************************************************************************************/
/*!  \brief       Initializes the FSM library. Must be called before any usage of other service functions.
 *   \details     -
 *   \param[in]   instance            FsmLib instance pointer.
 *   \param[in]   processingStack     Processing stack of FsmLib instance.
 *   \param[in]   processingStackSize Processing stack size.
 *   \param[in]   partitionId         Partition ID to which instance belongs to.
 *   \pre         -
 *   \context     TASK
 *   \reentrant   FALSE
 *   \synchronous TRUE
 *   \vcaAttr FETA_ReportCaller
 * \spec
 *    requires $lengthOf(processingStack) == processingStackSize;
 * \endspec
 *********************************************************************************************************************/
FUNC(void, NVM_PRIVATE_CODE) NvM_FsmLib_Init(
    NvM_FsmLib_InstancePtrType instance,
    NvM_ProcessingStackElementPtrType processingStack,
    const uint8 processingStackSize,
    NvM_PartitionIdType partitionId);

/**********************************************************************************************************************
 * NvM_FsmLib_ProcessCurrentActiveFsm()
 *********************************************************************************************************************/
/*!  \brief       Processes the current active FSM.
 *   \details     As long as current FSM entity is reporting continuation of processing, this function will iteratively
 *                process the active entity.
 *   \param[in]   instance            FsmLib instance pointer.
 *   \pre         -
 *   \context     TASK
 *   \reentrant   FALSE
 *   \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, NVM_PRIVATE_CODE) NvM_FsmLib_ProcessCurrentActiveFsm(NvM_FsmLib_InstancePtrToConstType instance);

/**********************************************************************************************************************
 * NvM_FsmLib_SpawnFsm()
 *********************************************************************************************************************/
/*!  \brief       Place given FSM on top of the processing stack.
 *   \details     The ENTRY action of the given FSM will be invoked automatically.
 *   \param[in]   instance            FsmLib instance pointer.
 *   \param[in]   newFsm              FSM that shall be spawned.
 *   \pre         -
 *   \context     TASK
 *   \reentrant   FALSE
 *   \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, NVM_PRIVATE_CODE) NvM_FsmLib_SpawnFsm(
  NvM_FsmLib_InstancePtrType instance,
  const NvM_FsmType newFsm);

/**********************************************************************************************************************
 * NvM_FsmLib_FinalizeCurrentActiveFsm()
 *********************************************************************************************************************/
/*!  \brief       Remove the FSM entry on top of the processing stack.
 *   \details     Shall only be invoked by the FSM itself (pseude THIS pointer)!
 *                False usage of this function can lead to processing errors!
 *   \param[in]   instance            FsmLib instance pointer.
 *   \param[in]   result              Result of the current FSM.
 *   \pre         NvM_FsmLib_SpawnFsm() must have been executed for the FSM before usage of this function.
 *   \context     TASK
 *   \reentrant   FALSE
 *   \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, NVM_PRIVATE_CODE) NvM_FsmLib_FinalizeCurrentActiveFsm(
  NvM_FsmLib_InstancePtrType instance,
  NvM_ServiceJobResultType result);

/**********************************************************************************************************************
 * NvM_FsmLib_TransitionToState()
 *********************************************************************************************************************/
/*!  \brief       Execute a transition to a new state for the given FSM.
 *   \details     ENTRY action of new state will automatically be invoked.
 *   \param[in]   instance            FsmLib instance pointer.
 *   \param[in]   newState            State that shall be achieved.
 *   \pre         -
 *   \context     TASK
 *   \reentrant   FALSE
 *   \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, NVM_PRIVATE_CODE) NvM_FsmLib_TransitionToState(
  NvM_FsmLib_InstancePtrToConstType instance,
  const NvM_StateType newState);

/**********************************************************************************************************************
 * NvM_FsmLib_EntryNoOp()
 *********************************************************************************************************************/
/*!  \brief       No-operation function to be used when a state needs no ENTRY action.
 *   \details     -
 *   \param[in]   partitionId         Partition ID.
 *   \pre         -
 *   \context     TASK
 *   \reentrant   FALSE
 *   \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, NVM_PRIVATE_CODE) NvM_FsmLib_EntryNoOp(NvM_PartitionIdType partitionId);

/**********************************************************************************************************************
 * NvM_FsmLib_ClearProcessingStack()
 *********************************************************************************************************************/
/*!  \brief       Clears the processing stack of the FsmLib instance.
 *   \details     -
 *   \param[in]   instance            FsmLib instance pointer.
 *   \pre         -
 *   \context     TASK
 *   \reentrant   FALSE
 *   \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, NVM_PRIVATE_CODE) NvM_FsmLib_ClearProcessingStack(NvM_FsmLib_InstancePtrType instance);

/**********************************************************************************************************************
 * NvM_FsmLib_GetSubFsmResult()
 *********************************************************************************************************************/
/*!  \brief       Gets the result of the sub FSM.
 *   \details     The sub FSM is spawned by the current active FSM and therefore the result has to be retrieved
 *                after the sub FSM was finalized.
 *   \param[in]   instance            FsmLib instance pointer.
 *   \pre         -
 *   \context     TASK
 *   \reentrant   FALSE
 *   \synchronous TRUE
 *********************************************************************************************************************/
FUNC(NvM_ServiceJobResultType, NVM_PRIVATE_CODE) NvM_FsmLib_GetSubFsmResult(
  NvM_FsmLib_InstancePtrToConstType instance);

/**********************************************************************************************************************
 * NvM_FsmLib_IsProcessingStackEmpty()
 *********************************************************************************************************************/
/*!  \brief       Checks if the FSM library instance has finished processing.
 *   \details     -
 *   \param[in]   instance            FsmLib instance pointer.
 *   \pre         -
 *   \return      TRUE if the FSM library instance has finished processing, FALSE otherwise.
 *   \context     TASK
 *   \reentrant   FALSE
 *   \synchronous TRUE
 *********************************************************************************************************************/
FUNC(boolean, NVM_PRIVATE_CODE) NvM_FsmLib_IsProcessingStackEmpty(
  NvM_FsmLib_InstancePtrToConstType instance);

#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* NVM_FSMLIB */

/**********************************************************************************************************************
 *  END OF FILE: NvM_FsmLib.h
 *********************************************************************************************************************/
