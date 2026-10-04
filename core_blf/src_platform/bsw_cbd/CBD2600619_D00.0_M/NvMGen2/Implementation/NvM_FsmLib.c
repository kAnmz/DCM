/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2026 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!        \file  NvM_FsmLib.c
 *        \brief  NvM_FsmLib source file
 *      \details  Implementation of the FSM library unit of the NvM.
 *         \unit  NvM_FsmLib
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#define NVM_FSMLIB_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "NvM_FsmLib.h"
#include "NvM_CfgDefines.h"
/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
# define NVM_START_SEC_CODE
# include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * NvM_FsmLib_Init()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, NVM_PRIVATE_CODE) NvM_FsmLib_Init(
    NvM_FsmLib_InstancePtrType instance,
    NvM_ProcessingStackElementPtrType processingStack,
    const uint8 processingStackSize,
    NvM_PartitionIdType partitionId)
{
  instance->PartitionId = partitionId;
  instance->ProcessingStack = processingStack;
  instance->CurrentProcessingStackIndex = NVM_FSMLIB_PROCESSING_STACK_INDEX_NONE;
  instance->StackSize = processingStackSize;

  for (NvM_FsmLib_ProcessingStackElementIterType i = 0; i < instance->StackSize; i++)                                   /* FETA_NVM_ConstantProcessingStackSize_Callee */
  {
#if !defined(__VCA__) /* COV_NVM_VCA */
    /* VCA Disable SLC-10, SLC-22 : VCA_NVM_ProcessingStack */
    instance->ProcessingStack[i].CurrentFsm.Entry = NULL_PTR;
    instance->ProcessingStack[i].CurrentFsm.CurrentState.Entry = NULL_PTR;
    instance->ProcessingStack[i].CurrentFsm.CurrentState.Do = NULL_PTR;
    /* VCA Enable : VCA_NVM_ProcessingStack */
#endif
  }
}

/**********************************************************************************************************************
 * NvM_FsmLib_ProcessCurrentActiveFsm()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, NVM_PRIVATE_CODE) NvM_FsmLib_ProcessCurrentActiveFsm(NvM_FsmLib_InstancePtrToConstType instance)
{
  /* Ensure loop entrance at least once */
  NvM_FsmLib_ProcessingResultType processResult = NVM_FSMLIB_PROCESSINGRESULT_CONTINUE;
  uint8 processStepCounter = 0;

  /* Check stack index each iteration: while processing a FSM finalization can occur and stack is now empty */
  while ((instance->CurrentProcessingStackIndex >= 0)                                                                   /* FETA_NVM_FsmLib_StackProcessing */
    && (processResult == NVM_FSMLIB_PROCESSINGRESULT_CONTINUE))
  {
    /*@ assert instance->CurrentProcessingStackIndex < $lengthOf(instance->ProcessingStack); */                         /* VCA_NVM_ProcessingStack */
    /*@ assert instance->PartitionId < NvM_GetSizeOfPartitionIdentifiers(); */
#if !defined(__VCA__) /* COV_NVM_VCA */
    /* VCA Disable SLC-10, SLC-22 : VCA_NVM_FsmActionFunctionPointerCall */
    processResult = instance->ProcessingStack[instance->CurrentProcessingStackIndex].CurrentFsm.CurrentState.Do(
        instance->PartitionId);
    /* VCA Enable : VCA_NVM_FsmFunctionPointerCall */
#endif

    /* Ensure that loop terminates when misusing FsmLib */
    ++processStepCounter;

    if (processStepCounter >= NVM_FSMLIB_PROCESSING_MAX_STEPS)
    {
      processResult = NVM_FSMLIB_PROCESSINGRESULT_STOP;
    }
  }
}

/**********************************************************************************************************************
 * NvM_FsmLib_SpawnFsm()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, NVM_PRIVATE_CODE) NvM_FsmLib_SpawnFsm(
  NvM_FsmLib_InstancePtrType instance,
  const NvM_FsmType newFsm)
{
  Std_ReturnType retVal = E_NOT_OK;

  if ((instance->CurrentProcessingStackIndex >= NVM_FSMLIB_PROCESSING_STACK_INDEX_NONE) &&
      (instance->CurrentProcessingStackIndex < (sint8)(instance->StackSize - 1)))                                       /* PRQA S 1860 1 */ /* MD_NvMFsmLib_StackIndexSignedInteger */
  {
    instance->CurrentProcessingStackIndex++;
#if !defined(__VCA__) /* COV_NVM_VCA */
    /* VCA Disable SLC-10, SLC-22 : VCA_NVM_ProcessingStack */
    instance->ProcessingStack[instance->CurrentProcessingStackIndex].CurrentFsm = newFsm;
    newFsm.Entry(instance->PartitionId);
    /* VCA Enable : VCA_NVM_ProcessingStack */
#endif

    retVal = E_OK;
  }

  return retVal;
}

/**********************************************************************************************************************
 * NvM_FsmLib_FinalizeCurrentActiveFsm()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, NVM_PRIVATE_CODE) NvM_FsmLib_FinalizeCurrentActiveFsm(
  NvM_FsmLib_InstancePtrType instance,
  NvM_ServiceJobResultType result)
{
  if (instance->CurrentProcessingStackIndex > NVM_FSMLIB_PROCESSING_STACK_INDEX_NONE)
  {
#if !defined(__VCA__) /* COV_NVM_VCA */
    /* VCA Disable SLC-10, SLC-22 : VCA_NVM_ProcessingStack */
    instance->ProcessingStack[instance->CurrentProcessingStackIndex].CurrentFsm.Entry = NULL_PTR;
    instance->ProcessingStack[instance->CurrentProcessingStackIndex].CurrentFsm.CurrentState.Entry = NULL_PTR;
    instance->ProcessingStack[instance->CurrentProcessingStackIndex].CurrentFsm.CurrentState.Do = NULL_PTR;
    instance->ProcessingStack[instance->CurrentProcessingStackIndex].FsmJobResult = result;

    instance->CurrentProcessingStackIndex--;

    /* VCA Enable : VCA_NVM_ProcessingStack */
#endif
  }
}

/**********************************************************************************************************************
 * NvM_FsmLib_TransitionToState()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, NVM_PRIVATE_CODE) NvM_FsmLib_TransitionToState(
  NvM_FsmLib_InstancePtrToConstType instance,
  const NvM_StateType newState)
{
  NvM_FsmPtrType fsmPtr = &instance->ProcessingStack[instance->CurrentProcessingStackIndex].CurrentFsm;

#if !defined(__VCA__) /* COV_NVM_VCA */
  /* VCA Disable SLC-10, SLC-22 : VCA_NVM_ProcessingStack */

  /* Perform state transition */
  fsmPtr->CurrentState = newState;

  /* Enter new state */
  fsmPtr->CurrentState.Entry(instance->PartitionId);
  /* VCA Enable : VCA_NVM_ProcessingStack */
#endif
}

/**********************************************************************************************************************
 * NvM_FsmLib_EntryNoOp()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, NVM_PRIVATE_CODE) NvM_FsmLib_EntryNoOp(NvM_PartitionIdType partitionId)
{
  /* Do nothing */
  NVM_DUMMY_STATEMENT(partitionId);                                                                                     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
}

/**********************************************************************************************************************
 * NvM_FsmLib_ClearProcessingStack()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, NVM_PRIVATE_CODE) NvM_FsmLib_ClearProcessingStack(NvM_FsmLib_InstancePtrType instance)
{
  while (instance->CurrentProcessingStackIndex > NVM_FSMLIB_PROCESSING_STACK_INDEX_NONE)                                /* FETA_NVM_FsmLib_StackClearing */
  {
#if !defined(__VCA__) /* COV_NVM_VCA */
    /* VCA Disable SLC-10, SLC-22 : VCA_NVM_ProcessingStack */
    instance->ProcessingStack[instance->CurrentProcessingStackIndex].CurrentFsm.Entry = NULL_PTR;
    instance->ProcessingStack[instance->CurrentProcessingStackIndex].CurrentFsm.CurrentState.Entry = NULL_PTR;
    instance->ProcessingStack[instance->CurrentProcessingStackIndex].CurrentFsm.CurrentState.Do = NULL_PTR;
    /* VCA Enable : VCA_NVM_ProcessingStack */
#endif
    instance->CurrentProcessingStackIndex--;
  }
}

/**********************************************************************************************************************
 * NvM_FsmLib_GetSubFsmResult()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(NvM_ServiceJobResultType, NVM_PRIVATE_CODE) NvM_FsmLib_GetSubFsmResult(NvM_FsmLib_InstancePtrToConstType instance)
{
  NvM_ServiceJobResultType serviceJobResult = NVM_SERVICE_JOB_NOT_OK;

  const uint8 accessIndex = (uint8)instance->CurrentProcessingStackIndex + 1u;

  if (accessIndex < instance->StackSize)
  {
    serviceJobResult = instance->ProcessingStack[accessIndex].FsmJobResult;                                             /* VCA_NVM_ProcessingStack */
  }

  return serviceJobResult;
}

/**********************************************************************************************************************
 * NvM_FsmLib_IsProcessingStackEmpty()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(boolean, NVM_PRIVATE_CODE) NvM_FsmLib_IsProcessingStackEmpty(
  NvM_FsmLib_InstancePtrToConstType instance)
{
  boolean isFsmLibInstanceFinishedProcessing = FALSE;

  if (instance->CurrentProcessingStackIndex == NVM_FSMLIB_PROCESSING_STACK_INDEX_NONE)
  {
    isFsmLibInstanceFinishedProcessing = TRUE;
  }

  return isFsmLibInstanceFinishedProcessing;
}

#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  VCA JUSTIFICATIONS
 **********************************************************************************************************************/
/* VCA_JUSTIFICATION_BEGIN

\ID VCA_NVM_FsmFunctionPointerCall
  \DESCRIPTION The processing stack of the FSM instance contains always the current FSM instance.
               This instance holds the pointer to the ENTRY and DO action of the current FSM/State
               which has to be processed.
               It must be ensured that no null pointer is called.
               In order to analyze the NvM in a meaningful way, this part of the code is deactivated
               during the VCA analysis, as it would lead to false-positive errors in other parts of the module.

  \COUNTERMEASURE \N A code review ensures that a corresponding action is always assigned to the current active FSM.
                  \T Each FSM unit test and the component test verify the correct assignment of the function pointer.

\ID VCA_NVM_ProcessingStack
  \DESCRIPTION The processing stack variable is the basis for processing the FSM stack.
               The current processing stack and the related stack size are assigned to the respective FsmLib instance
               within the FsmLib Init function.
               The CurrentProcessingStackIndex is used to iterate over the processing stack.
               It must be ensured that access to the processing stack is always within the bounds of the respective stack.
               In order to analyze the NvM in a meaningful way, code parts where the processing stack is used,
               are deactivated during the VCA analysis, as it would lead to false-positive errors
               in other parts of the module.

  \COUNTERMEASURE \N The pre-condition formulated for NvM_FsmLib_Init ensures that the assigned processing stack
                     always has the assigned stack size. Furthermore, the runtime checks within the Spawn and
                     FinalizeCurrentActiveFsm functions ensure that the CurrentProcessingStackIndex is always in range,
                     because this index is only modified within these functions.

VCA_JUSTIFICATION_END */

/**********************************************************************************************************************
 *  END OF FILE: NvM_FsmLib.c
 *********************************************************************************************************************/
