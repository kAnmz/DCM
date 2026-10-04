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
/*!        \file  NvM_WriteNvBlockFsm.c
 *        \brief  NvM_WriteNvBlockFsm source file
 *      \details  Implementation of the NvM_WriteNvBlockFsm unit.
 *         \unit  NvM_WriteNvBlockFsm
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#define NVM_WRITENVBLOCKFSM_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "NvM_WriteNvBlockFsm.h"
#include "NvM_FsmLib.h"
#include "MemIf.h"
#include "NvM_Cfg.h"
#include "NvM_GlobalUtilityLib.h"
#include "NvM_ErrorCheck.h"

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

/***********************************************************************************************************************
 *  FSM FUNCTION PROTOTYPES
 **********************************************************************************************************************/
#define NVM_START_SEC_CODE
#include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * NvM_WriteNvBlockFsm_Entry()
 *********************************************************************************************************************/
/*!  \brief       ENTRY action of WriteNvBlockFsm
 *   \details     -
 *   \param[in]   partitionId Partition ID.
 *   \pre         -
 *   \context     TASK
 *   \reentrant   FALSE
 *   \synchronous TRUE
 *   \spec
 *      requires partitionId == NVM_PARTITION_ID_MASTER;
 *   \endspec
 *********************************************************************************************************************/
FUNC(void, NVM_PRIVATE_CODE) NvM_WriteNvBlockFsm_Entry(NvM_PartitionIdType partitionId);

/**********************************************************************************************************************
 * NvM_WriteNvBlockFsm_WriteNvBlockState_Do()
 *********************************************************************************************************************/
/*!  \brief       DO action of WriteNvBlockFsm state WriteNvBlock
 *   \details     -
 *   \param[in]   partitionId Partition ID.
 *   \return      Based on state evaluation:
 *                 - STOP       if no further processing is required
 *                 - CONTINUE   if further processing shall be executed
 *   \pre         -
 *   \context     TASK
 *   \reentrant   FALSE
 *   \synchronous TRUE
 *   \spec
 *      requires partitionId == NVM_PARTITION_ID_MASTER;
 *   \endspec
 *********************************************************************************************************************/
FUNC(NvM_FsmLib_ProcessingResultType, NVM_PRIVATE_CODE) NvM_WriteNvBlockFsm_WriteNvBlockState_Do(
  NvM_PartitionIdType partitionId);

/**********************************************************************************************************************
 * NvM_WriteNvBlockFsm_WriteRedundantNvBlockState_Do()
 *********************************************************************************************************************/
/*!  \brief       DO action of WriteNvBlockFsm state WriteRedundantNvBlock
 *   \details     -
 *   \param[in]   partitionId Partition ID.
 *   \return      Based on state evaluation:
 *                 - STOP       if no further processing is required
 *                 - CONTINUE   if further processing shall be executed
 *   \pre         -
 *   \context     TASK
 *   \reentrant   FALSE
 *   \synchronous TRUE
 *   \spec
 *      requires partitionId == NVM_PARTITION_ID_MASTER;
 *   \endspec
 *********************************************************************************************************************/
FUNC(NvM_FsmLib_ProcessingResultType, NVM_PRIVATE_CODE) NvM_WriteNvBlockFsm_WriteRedundantNvBlockState_Do(
  NvM_PartitionIdType partitionId);

/**********************************************************************************************************************
 * NvM_WriteNvBlockFsm_MemIfWriteState_Entry()
 *********************************************************************************************************************/
/*!  \brief       ENTRY action of WriteNvBlockFsm state MemIfWrite
 *   \details     -
 *   \param[in]   partitionId Partition ID.
 *   \pre         -
 *   \context     TASK
 *   \reentrant   FALSE
 *   \synchronous TRUE
 *   \spec
 *      requires partitionId == NVM_PARTITION_ID_MASTER;
 *   \endspec
 *********************************************************************************************************************/
FUNC(void, NVM_PRIVATE_CODE) NvM_WriteNvBlockFsm_MemIfWriteState_Entry(NvM_PartitionIdType partitionId);

/**********************************************************************************************************************
 * NvM_WriteNvBlockFsm_MemIfWriteState_Do()
 *********************************************************************************************************************/
/*!  \brief       DO action of WriteNvBlockFsm state MemIfWrite
 *   \details     -
 *   \param[in]   partitionId Partition ID.
 *   \return      Based on state evaluation:
 *                 - STOP       if no further processing is required
 *                 - CONTINUE   if further processing shall be executed
 *   \pre         -
 *   \context     TASK
 *   \reentrant   FALSE
 *   \synchronous TRUE
 *   \spec
 *      requires partitionId == NVM_PARTITION_ID_MASTER;
 *   \endspec
 *********************************************************************************************************************/
FUNC(NvM_FsmLib_ProcessingResultType, NVM_PRIVATE_CODE) NvM_WriteNvBlockFsm_MemIfWriteState_Do(
  NvM_PartitionIdType partitionId);

#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/
#define NVM_START_SEC_CONST_UNSPECIFIED
#include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*
 * Initializing a const structure (NvM_WriteNvBlockFsm) can only be done with compile-time constants.
 * Therefore this defines are introduced to minimize code duplication within NvM_WriteNvBlockFsm and
 * NvM_WriteNvBlockFsm_WriteNvBlockState initialization.
 */
#define NVM_WRITENVBLOCKFSM_WRITENVBLOCKSTATE_DO NvM_WriteNvBlockFsm_WriteNvBlockState_Do

/*! STATE: WriteNvBlock */

/* PRQA S 3218 1 */ /* MD_WriteNvBlockFsm_WriteRedundantNvBlockStateUsedOnlyInSingleFunction */
NVM_LOCAL CONST(NvM_StateType, NVM_PRIVATE_DATA) NvM_WriteNvBlockFsm_WriteNvBlockState = {
  NvM_FsmLib_EntryNoOp,
  NVM_WRITENVBLOCKFSM_WRITENVBLOCKSTATE_DO
};

/*! STATE: WriteRedundantNvBlock */

/* PRQA S 3218 1 */ /* MD_WriteNvBlockFsm_WriteRedundantNvBlockStateUsedOnlyInSingleFunction */
NVM_LOCAL CONST(NvM_StateType, NVM_PRIVATE_DATA) NvM_WriteNvBlockFsm_WriteRedundantNvBlockState = {
  NvM_FsmLib_EntryNoOp,
  NvM_WriteNvBlockFsm_WriteRedundantNvBlockState_Do
};

/*! STATE: MemIfWrite */

/* PRQA S 3218 1 */ /* MD_WriteNvBlockFsm_WriteRedundantNvBlockStateUsedOnlyInSingleFunction */
NVM_LOCAL CONST(NvM_StateType, NVM_PRIVATE_DATA) NvM_WriteNvBlockFsm_MemIfWriteState = {
  NvM_WriteNvBlockFsm_MemIfWriteState_Entry,
  NvM_WriteNvBlockFsm_MemIfWriteState_Do
};

/*! FSM: WriteNvBlock with ENTRY action and initial state */
/* PRQA S 3218 1 */ /* MD_Fsm_StateDefinitionStaticUsedOnlyInSingleFunction */
NVM_LOCAL CONST(NvM_FsmType, NVM_PRIVATE_DATA) NvM_WriteNvBlockFsm = {
  NvM_WriteNvBlockFsm_Entry,
  {NvM_FsmLib_EntryNoOp, NVM_WRITENVBLOCKFSM_WRITENVBLOCKSTATE_DO}
};

#define NVM_STOP_SEC_CONST_UNSPECIFIED
#include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define NVM_START_SEC_CODE
#include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * NvM_WriteNvBlockFsm_Entry()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(void, NVM_PRIVATE_CODE) NvM_WriteNvBlockFsm_Entry(NvM_PartitionIdType partitionId)
{
  NvM_WriteNvBlockFsm_ContextPtrType fsmContext = NvM_GetAddrWriteNvBlockFsm_Context(partitionId);
  NvM_FsmLib_InstancePtrToConstType fsmLibInstance =
    (NvM_FsmLib_InstancePtrToConstType)NvM_GetAddrNvServiceFsmLib_Instance(partitionId);
  const NvM_NvJobContextPtrType nvJobContext = NvM_GetAddrNvJobContext(partitionId);

  /*
  * Reset CurrentMemIfWriteResult to NOT_OK to prepare DO action of WriteNvBlockState to process MemIf Write at least
  * once.
  */
  fsmContext->CurrentMemIfWriteResult = NVM_SERVICE_JOB_NOT_OK;

  /*
   * Not possible to do it in entry action of next state. The entry action can also be entered
   * from the MemIfWriteState during each retry. In this case RetryCounter, BlockNumber and WriteResult would be
   * altered without intention.
   */
  fsmContext->WriteRetryCounter = 0u;
  fsmContext->BlockNumber = nvJobContext->BlockNumber;
  fsmContext->WriteBlockState = NvM_WriteNvBlockFsm_WriteNvBlockState;

  NvM_FsmLib_TransitionToState(fsmLibInstance, NvM_WriteNvBlockFsm_WriteNvBlockState);

  /*
   * The parameter partitionId is not used within this function in single partition use case.
   * To avoid compiler warnings the following dummy statement is added.
   */
  NVM_DUMMY_STATEMENT(partitionId);                                                                                     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
}


/**********************************************************************************************************************
 * NvM_WriteNvBlockFsm_WriteNvBlockState_Do()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(NvM_FsmLib_ProcessingResultType, NVM_PRIVATE_CODE) NvM_WriteNvBlockFsm_WriteNvBlockState_Do(
  NvM_PartitionIdType partitionId)
{
  /*
   * The parameter partitionId is not used within this function in single partition use case.
   * To avoid compiler warnings the following dummy statement is added.
   */
  NVM_DUMMY_STATEMENT(partitionId);                                                                                     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  NvM_FsmLib_InstancePtrType fsmLibInstance =
    (NvM_FsmLib_InstancePtrType)NvM_GetAddrNvServiceFsmLib_Instance(partitionId);
  NvM_WriteNvBlockFsm_ContextPtrType fsmContext = NvM_GetAddrWriteNvBlockFsm_Context(partitionId);
  const NvM_NvJobContextPtrType nvJobContext = NvM_GetAddrNvJobContext(partitionId);                                    /* PRQA S 2983 */ /* MD_NvM_QACReportsFalsePositive2983 */
  NvM_BlockDescriptorPtrType blockDescriptor = NvM_GetAddrBlockDescriptor(nvJobContext->BlockDescriptorLookupTableId);

  /* Each negative MemIf result leads to retry (including INVALID) if retry counter has not exceeded */
  if ((fsmContext->CurrentMemIfWriteResult == NVM_SERVICE_JOB_OK)
      || (fsmContext->WriteRetryCounter > NVM_MAX_NO_OF_WRITE_RETRIES))
  {
    fsmContext->PrimaryNvBlockResult = fsmContext->CurrentMemIfWriteResult;

    /* Report DEM error in case job is not successful and retry counter has exceeded maximum retries */
    if (fsmContext->PrimaryNvBlockResult != NVM_SERVICE_JOB_OK)
    {
      NvM_ErrorCheck_DispatchDemErrorConditionally(NVM_DEM_ERROR_TYPE_REQ_FAILED);
    }

    if (blockDescriptor->BlockManagementType == NVM_BLOCK_MANAGEMENT_TYPE_REDUNDANT)
    {
      /*
      * Not possible to do it in entry action of next state. The entry action can also be entered
      * from the MemIfWriteState during each retry. In this case RetryCounter, BlockNumber and WriteResult would be
      * altered without intention.
      */
      fsmContext->BlockNumber++; /* Access the redundant block */
      fsmContext->CurrentMemIfWriteResult = NVM_SERVICE_JOB_NOT_OK;
      fsmContext->WriteBlockState = NvM_WriteNvBlockFsm_WriteRedundantNvBlockState;
      fsmContext->WriteRetryCounter = 0u;
      NvM_FsmLib_TransitionToState(fsmLibInstance, NvM_WriteNvBlockFsm_WriteRedundantNvBlockState);
    }
    else
    {
      NvM_FsmLib_FinalizeCurrentActiveFsm(fsmLibInstance, fsmContext->PrimaryNvBlockResult);
    }
  }
  else
  {
    NvM_FsmLib_TransitionToState(fsmLibInstance, NvM_WriteNvBlockFsm_MemIfWriteState);
  }

  return NVM_FSMLIB_PROCESSINGRESULT_CONTINUE;
}


/**********************************************************************************************************************
 * NvM_WriteNvBlockFsm_WriteRedundantNvBlockState_Do()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(NvM_FsmLib_ProcessingResultType, NVM_PRIVATE_CODE) NvM_WriteNvBlockFsm_WriteRedundantNvBlockState_Do(
  NvM_PartitionIdType partitionId)
{
  /*
   * The parameter partitionId is not used within this function in single partition use case.
   * To avoid compiler warnings the following dummy statement is added.
   */
  NVM_DUMMY_STATEMENT(partitionId);                                                                                     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  NvM_FsmLib_InstancePtrType fsmLibInstance =
    (NvM_FsmLib_InstancePtrType)NvM_GetAddrNvServiceFsmLib_Instance(partitionId);
  NvM_WriteNvBlockFsm_ContextPtrType fsmContext = NvM_GetAddrWriteNvBlockFsm_Context(partitionId);

  /* Each negative MemIf result leads to retry (including INVALID) if retry counter has not exceeded */
  if ((fsmContext->CurrentMemIfWriteResult == NVM_SERVICE_JOB_OK)
      || (fsmContext->WriteRetryCounter > NVM_MAX_NO_OF_WRITE_RETRIES))
  {
    NvM_ServiceJobResultType serviceJobResult = fsmContext->CurrentMemIfWriteResult;

    /* Report DEM error in case job is not successful and retry counter has exceeded maximum retries */
    if (serviceJobResult != NVM_SERVICE_JOB_OK)
    {
      NvM_ErrorCheck_DispatchDemErrorConditionally(NVM_DEM_ERROR_TYPE_REQ_FAILED);
    }

    /* Only one NV block has to be written successfully to finish write job successfully. */
    if ((serviceJobResult != NVM_SERVICE_JOB_OK) &&
        (fsmContext->PrimaryNvBlockResult == NVM_SERVICE_JOB_OK))
    {
      serviceJobResult= NVM_SERVICE_JOB_OK;
    }

    NvM_FsmLib_FinalizeCurrentActiveFsm(fsmLibInstance, serviceJobResult);
  }
  else
  {
    NvM_FsmLib_TransitionToState(fsmLibInstance, NvM_WriteNvBlockFsm_MemIfWriteState);
  }

  return NVM_FSMLIB_PROCESSINGRESULT_CONTINUE;
}

/**********************************************************************************************************************
 * NvM_WriteNvBlockFsm_MemIfWriteState_Entry()
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
FUNC(void, NVM_PRIVATE_CODE) NvM_WriteNvBlockFsm_MemIfWriteState_Entry(NvM_PartitionIdType partitionId)
{
  /*
   * The parameter partitionId is not used within this function in single partition use case.
   * To avoid compiler warnings the following dummy statement is added.
   */
  NVM_DUMMY_STATEMENT(partitionId);                                                                                     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  NvM_FsmLib_InstancePtrType fsmLibInstance =
    (NvM_FsmLib_InstancePtrType)NvM_GetAddrNvServiceFsmLib_Instance(partitionId);
  NvM_WriteNvBlockFsm_ContextPtrType fsmContext = NvM_GetAddrWriteNvBlockFsm_Context(partitionId);
  const NvM_NvJobContextPtrType nvJobContext = NvM_GetAddrNvJobContext(partitionId);
  NvM_BlockDescriptorPtrType blockDescriptor = NvM_GetAddrBlockDescriptor(nvJobContext->BlockDescriptorLookupTableId);

  if (MemIf_Write((uint8)blockDescriptor->MemIfDeviceIndex,
                  fsmContext->BlockNumber,
                  nvJobContext->DataBuffer) != E_OK)
  {
    fsmContext->CurrentMemIfWriteResult = NVM_SERVICE_JOB_NOT_OK;
    fsmContext->WriteRetryCounter++;

    NvM_FsmLib_TransitionToState(fsmLibInstance, fsmContext->WriteBlockState);
  }
}

/**********************************************************************************************************************
 * NvM_WriteNvBlockFsm_MemIfWriteState_Do()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(NvM_FsmLib_ProcessingResultType, NVM_PRIVATE_CODE) NvM_WriteNvBlockFsm_MemIfWriteState_Do(
  NvM_PartitionIdType partitionId)
{
   /*
   * The parameter partitionId is not used within this function in single partition use case.
   * To avoid compiler warnings the following dummy statement is added.
   */
  NVM_DUMMY_STATEMENT(partitionId);                                                                                     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  NvM_FsmLib_ProcessingResultType retVal = NVM_FSMLIB_PROCESSINGRESULT_STOP;

  NvM_FsmLib_InstancePtrType fsmLibInstance =
    (NvM_FsmLib_InstancePtrType)NvM_GetAddrNvServiceFsmLib_Instance(partitionId);
  NvM_WriteNvBlockFsm_ContextPtrType fsmContext = NvM_GetAddrWriteNvBlockFsm_Context(partitionId);
  const NvM_NvJobContextPtrType nvJobContext = NvM_GetAddrNvJobContext(partitionId);                                    /* PRQA S 2983 */ /* MD_NvM_QACReportsFalsePositive2983 */
  NvM_BlockDescriptorPtrType blockDescriptor = NvM_GetAddrBlockDescriptor(nvJobContext->BlockDescriptorLookupTableId);

  MemIf_JobResultType jobResult = MemIf_GetJobResult((uint8)blockDescriptor->MemIfDeviceIndex);

  if(jobResult == MEMIF_JOB_PENDING)
  {
    retVal = NVM_FSMLIB_PROCESSINGRESULT_STOP;
  }
  else
  {
    fsmContext->CurrentMemIfWriteResult = NvM_GlobalUtilityLib_ConvertMemIfResultToServiceJobResult(jobResult);

    /* Any negative MemIf job result leads to incremented WriteRetryCounter */
    if (fsmContext->CurrentMemIfWriteResult != NVM_SERVICE_JOB_OK)
    {
      fsmContext->WriteRetryCounter++;
    }

    NvM_FsmLib_TransitionToState(fsmLibInstance, fsmContext->WriteBlockState);
    retVal = NVM_FSMLIB_PROCESSINGRESULT_CONTINUE;
  }

  return retVal;
}


/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * NvM_WriteNvBlockFsm_WriteBlock()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, NVM_PRIVATE_CODE) NvM_WriteNvBlockFsm_WriteBlock(NvM_PartitionIdType partitionId)
{
  NVM_DUMMY_STATEMENT(partitionId);                                                                                     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  NvM_FsmLib_InstancePtrType fsmLibInstance =
    (NvM_FsmLib_InstancePtrType)NvM_GetAddrNvServiceFsmLib_Instance(partitionId);

  (void)NvM_FsmLib_SpawnFsm(fsmLibInstance, NvM_WriteNvBlockFsm);
}

#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  MISRA JUSTIFICATIONS
 **********************************************************************************************************************/

/* Justification for module-specific MISRA deviations:

MD_WriteNvBlockFsm_WriteRedundantNvBlockStateUsedOnlyInSingleFunction: rule 8.9
  Reason:     There is only one transition in the FSM to WriteRedundantNvBlockState.
              Therefore the state is only used in a single function where the transition is done.
  Risk:       None.
  Prevention: A code review shall ensure that there is no side effect.

*/

/**********************************************************************************************************************
 *  END OF FILE: NvM_WriteNvBlockFsm.c
 *********************************************************************************************************************/
