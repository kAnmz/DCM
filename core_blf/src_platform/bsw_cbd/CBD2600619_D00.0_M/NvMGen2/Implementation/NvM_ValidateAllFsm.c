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
/*!        \file  NvM_ValidateAllFsm.c
 *        \brief  NvM_ValidateAllFsm source file
 *      \details  Implementation of validate all state machine
 *         \unit  NvM_ValidateAllFsm
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#define NVM_VALIDATEALLFSM_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "NvM_ValidateAllFsm.h"
#include "NvM_FsmLib.h"
#include "NvM_DataIntegrityRecalcQueue.h"

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
 * NvM_ValidateAllFsm_Entry()
 *********************************************************************************************************************/
/*!  \brief       ENTRY action of ValidateAllFsm.
 *   \details     -
 *   \param[in]   partitionId Partition ID.
 *   \pre         -
 *   \context     TASK
 *   \reentrant   FALSE
 *   \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, NVM_PRIVATE_CODE) NvM_ValidateAllFsm_Entry(NvM_PartitionIdType partitionId);

/**********************************************************************************************************************
 * NvM_ValidateAllFsm_ValidateAll_Do()
 *********************************************************************************************************************/
/*!  \brief       DO action of ValidateAllFsm state ValidateBlock.
 *   \details     -
 *   \param[in]   partitionId Partition ID.
 *   \return      Based on state evaluation:
 *                 - STOP       if no further processing is required
 *                 - CONTINUE   if further processing shall be executed
 *   \pre         -
 *   \context     TASK
 *   \reentrant   FALSE
 *   \synchronous TRUE
 *********************************************************************************************************************/
FUNC(NvM_FsmLib_ProcessingResultType, NVM_PRIVATE_CODE) NvM_ValidateAllFsm_ValidateAll_Do(
  NvM_PartitionIdType partitionId);

#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/
#define NVM_START_SEC_CONST_UNSPECIFIED
#include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*
 * Initializing a const structure (NvM_ValidateAllFsm_InitialState) can only be done with compile-time constants.
 * Therefore this defines are introduced to minimize code duplication within NvM_ValidateAllFsm_InitialState and
 * NvM_ValidateAllFsm_ValidateAllState initialization.
 */
#define NVM_VALIDATEALLFSM_VALIDATEALLSTATE_ENTRY NvM_FsmLib_EntryNoOp
#define NVM_VALIDATEALLFSM_VALIDATEALL_DO NvM_ValidateAllFsm_ValidateAll_Do


/*! STATE: ValidateAllState */
/* PRQA S 3218 1 */ /* MD_Fsm_StateDefinitionStaticUsedOnlyInSingleFunction */
NVM_LOCAL CONST(NvM_StateType, NVM_PRIVATE_DATA) NvM_ValidateAllFsm_ValidateAllState = {
  NVM_VALIDATEALLFSM_VALIDATEALLSTATE_ENTRY,
  NVM_VALIDATEALLFSM_VALIDATEALL_DO
};

/*! FSM: ValidateAllFsm with ENTRY action and initial state */
/* PRQA S 3218 1 */ /* MD_Fsm_StateDefinitionStaticUsedOnlyInSingleFunction */
NVM_LOCAL CONST(NvM_FsmType, NVM_PRIVATE_DATA) NvM_ValidateAllFsm_InitialState = {
  NvM_ValidateAllFsm_Entry,
  {
    NVM_VALIDATEALLFSM_VALIDATEALLSTATE_ENTRY,
    NVM_VALIDATEALLFSM_VALIDATEALL_DO
  }
};

#define NVM_STOP_SEC_CONST_UNSPECIFIED
#include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  LOCAL FUNCTIONS
 **********************************************************************************************************************/

 /**********************************************************************************************************************
 * NvM_ValidateAllFsm_Entry()
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
FUNC(void, NVM_PRIVATE_CODE) NvM_ValidateAllFsm_Entry(NvM_PartitionIdType partitionId)                                  /* PRQA S 3206 */ /* MD_NvM_CslMacroNotUsingPartitionId */
{
  NvM_BlockDescriptorPtrType blockDescriptor = (NvM_BlockDescriptorPtrType)NULL_PTR;
  const NvM_BlockDescriptorLookupTableIdType blockCount = NvM_GetSizeOfBlockDescriptor();

  for (NvM_BlockDescriptorLookupTableIdType i = NVM_FIRST_INTERNAL_BLOCK_ID; i < blockCount; i++)
  {
    blockDescriptor = NvM_GetAddrBlockDescriptor(i);

    if (blockDescriptor->Flags.UseAutoValidationEnabled == NVM_BLOCK_USE_AUTO_VALIDATION_ON)
    {
#if (NVM_MULTIPARTITION_USAGE_SCENARIO == STD_ON)
      if (blockDescriptor->PartitionId == partitionId)
#endif /* NVM_MULTIPARTITION_USAGE_SCENARIO */
      {
        blockDescriptor->BlockManagementInfo->ErrorStatus = NVM_REQ_PENDING;
      }
    }
  }

  NvM_FsmLib_InstancePtrType fsmLibInstance =
    (NvM_FsmLib_InstancePtrType)NvM_GetAddrMultiBlockServiceFsmLib_Instance(partitionId);

  NvM_FsmLib_TransitionToState(fsmLibInstance, NvM_ValidateAllFsm_ValidateAllState);

  /*
   * The parameter partitionId is not used within this function in single partition use case.
   * To avoid compiler warnings the following dummy statement is added.
   */
  NVM_DUMMY_STATEMENT(partitionId);                                                                                     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
}

/**********************************************************************************************************************
 * NvM_ValidateAllFsm_ValidateAll_Do()
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
 */
FUNC(NvM_FsmLib_ProcessingResultType, NVM_PRIVATE_CODE) NvM_ValidateAllFsm_ValidateAll_Do(
  NvM_PartitionIdType partitionId)                                                                                      /* PRQA S 3206 */ /* MD_NvM_CslMacroNotUsingPartitionId */
{
  NvM_FsmLib_InstancePtrType fsmLibInstance =
    (NvM_FsmLib_InstancePtrType)NvM_GetAddrMultiBlockServiceFsmLib_Instance(partitionId);
  const NvM_BlockDescriptorLookupTableIdType blockCount = NvM_GetSizeOfBlockDescriptor();

  for (NvM_BlockDescriptorLookupTableIdType i = NVM_FIRST_INTERNAL_BLOCK_ID; i < blockCount; i++)
  {
    NvM_BlockDescriptorPtrType currentBlock = NvM_GetAddrBlockDescriptor(i);

    if (currentBlock->Flags.UseAutoValidationEnabled == NVM_BLOCK_USE_AUTO_VALIDATION_ON)
    {
#if (NVM_MULTIPARTITION_USAGE_SCENARIO == STD_ON)
      if (currentBlock->PartitionId == partitionId)
#endif /* NVM_MULTIPARTITION_USAGE_SCENARIO */
      {
        if ((currentBlock->Flags.BlockUseSetRamBlockStatusEnabled == NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON)
          && (currentBlock->Flags.CalcRamBlockCrcEnabled == NVM_CALC_RAM_BLOCK_CRC_ON))
        {
          NvM_DataIntegrityRecalcQueue_InstancePtrType recalcQueueInstance =
            NvM_GetAddrDataIntegrityRecalcQueue_Instance(partitionId);

          NvM_DataIntegrityRecalcQueue_Push(recalcQueueInstance, i);
        }

        currentBlock->BlockManagementInfo->ErrorStatus = NVM_REQ_OK;
        currentBlock->BlockManagementInfo->RamBlockState = NVM_RAMBLOCKSTATE_VALID_CHANGED;
      }
    }
  }

  NvM_FsmLib_FinalizeCurrentActiveFsm(fsmLibInstance, NVM_SERVICE_JOB_OK);

  /*
   * The parameter partitionId is not used within this function in single partition use case.
   * To avoid compiler warnings the following dummy statement is added.
   */
  NVM_DUMMY_STATEMENT(partitionId);                                                                                     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  return NVM_FSMLIB_PROCESSINGRESULT_CONTINUE;
}

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

#define NVM_START_SEC_CODE
#include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

 /**********************************************************************************************************************
 * NvM_ValidateAllFsm_ValidateAll()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, NVM_PRIVATE_CODE) NvM_ValidateAllFsm_ValidateAll(NvM_PartitionIdType partitionId)                            /* PRQA S 3206 */ /* MD_NvM_CslMacroNotUsingPartitionId */
{
  NvM_FsmLib_InstancePtrType fsmLibInstance =
    (NvM_FsmLib_InstancePtrType)NvM_GetAddrMultiBlockServiceFsmLib_Instance(partitionId);

  /* COM-4978: Wait for CSL feature to store init value of generated partition data */
  NvM_ValidateAllFsm_InstancePtrType fsmInstance = NvM_GetAddrValidateAllFsm_Instance(partitionId);
  *fsmInstance = NvM_ValidateAllFsm_InitialState;

  (void)NvM_FsmLib_SpawnFsm(fsmLibInstance, *fsmInstance);

  /*
   * The parameter partitionId is not used within this function in single partition use case.
   * To avoid compiler warnings the following dummy statement is added.
   */
  NVM_DUMMY_STATEMENT(partitionId);                                                                                     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
}

#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
/**********************************************************************************************************************
 *  END OF FILE: NvM_ValidateAllFsm.c
 *********************************************************************************************************************/
