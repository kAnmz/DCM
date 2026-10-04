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
/*!        \file  NvM_NvJobDispatcherFsm.c
 *        \brief  NvM_NvJobDispatcherFsm source file
 *      \details  Implementation of the NvM_NvJobDispatcherFsm unit.
 *         \unit  NvM_NvJobDispatcherFsm
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#define NVM_NVJOBDISPATCHERFSM_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "NvM_NvJobDispatcherFsm.h"
#include "NvM_FsmLib.h"
#include "NvM_ReadNvBlockFsm.h"
#include "NvM_WriteNvBlockFsm.h"
#include "NvM_ResetNvBlockFsm.h"
#include "NvM_Cfg.h"
#include "NvM_GlobalUtilityLib.h"

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
 * NvM_NvJobDispatcherFsm_Entry()
 *********************************************************************************************************************/
/*!  \brief       ENTRY action of NvJobDispatcherFsm
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
FUNC(void, NVM_PRIVATE_CODE) NvM_NvJobDispatcherFsm_Entry(NvM_PartitionIdType partitionId);

/**********************************************************************************************************************
 * NvM_NvJobDispatcherFsm_WaitForFinishedJobState_Entry()
 *********************************************************************************************************************/
/*!  \brief       ENTRY action of NvJobDispatcherFsm state WaitForFinishedJob
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
FUNC(void, NVM_PRIVATE_CODE) NvM_NvJobDispatcherFsm_WaitForFinishedJobState_Entry(NvM_PartitionIdType partitionId);

/**********************************************************************************************************************
 * NvM_NvJobDispatcherFsm_WaitForFinishedJobState_Do()
 *********************************************************************************************************************/
/*!  \brief       DO action of NvJobDispatcherFsm state WaitForFinishedJob
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
FUNC(NvM_FsmLib_ProcessingResultType, NVM_PRIVATE_CODE) NvM_NvJobDispatcherFsm_WaitForFinishedJobState_Do(
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
 * Initializing a const structure (NvM_NvJobDispatcherFsm) can only be done with compile-time constants.
 * Therefore this defines are introduced to minimize code duplication within NvM_NvJobDispatcherFsm and
 * NvM_NvJobDispatcherFsm_WaitForFinishedJobState initialization.
 */
#define NVM_NVJOBDISPATCHERFSM_WAITFORFINISHEDJOBSTATE_ENTRY NvM_NvJobDispatcherFsm_WaitForFinishedJobState_Entry
#define NVM_NVJOBDISPATCHERFSM_WAITFORFINISHEDJOBSTATE_DO NvM_NvJobDispatcherFsm_WaitForFinishedJobState_Do

/*! STATE: WaitForFinishedJob */
/* PRQA S 3218 1 */ /* MD_Fsm_StateDefinitionStaticUsedOnlyInSingleFunction */
NVM_LOCAL CONST(NvM_StateType, NVM_PRIVATE_DATA) NvM_NvJobDispatcherFsm_WaitForFinishedJobState = {
  NVM_NVJOBDISPATCHERFSM_WAITFORFINISHEDJOBSTATE_ENTRY,
  NVM_NVJOBDISPATCHERFSM_WAITFORFINISHEDJOBSTATE_DO
};

/*! FSM: NvJobDispatcher with ENTRY action and initial state */
/* PRQA S 3218 1 */ /* MD_Fsm_StateDefinitionStaticUsedOnlyInSingleFunction */
NVM_LOCAL CONST(NvM_FsmType, NVM_PRIVATE_DATA) NvM_NvJobDispatcherFsm = {
  NvM_NvJobDispatcherFsm_Entry,
  {NVM_NVJOBDISPATCHERFSM_WAITFORFINISHEDJOBSTATE_ENTRY, NVM_NVJOBDISPATCHERFSM_WAITFORFINISHEDJOBSTATE_DO}
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
 * NvM_NvJobDispatcherFsm_GetBlockNumber()
 *********************************************************************************************************************/
/*! \brief       Determines the hardware abstraction block number.
 *  \details     -
 *  \param[in]   blockDescriptorLookupTableId     Block Id to retrieve correct block descriptor
 *  \param[in]   dataIndex                        Data Index to take into account for block number
 *  \pre         -
 *  \return      Block number
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
NVM_LOCAL_INLINE FUNC(uint16, NVM_PRIVATE_CODE) NvM_NvJobDispatcherFsm_GetBlockNumber(
  const NvM_BlockDescriptorLookupTableIdType blockDescriptorLookupTableId,
  const uint8 dataIndex);


/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * NvM_NvJobDispatcherFsm_Entry()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, NVM_PRIVATE_CODE) NvM_NvJobDispatcherFsm_Entry(NvM_PartitionIdType partitionId)
{
  NvM_FsmLib_InstancePtrType fsmLibInstance =
    (NvM_FsmLib_InstancePtrType)NvM_GetAddrNvServiceFsmLib_Instance(partitionId);

  NvM_FsmLib_TransitionToState(fsmLibInstance, NvM_NvJobDispatcherFsm_WaitForFinishedJobState);

  /*
   * The parameter partitionId is not used within this function in single partition use case.
   * To avoid compiler warnings the following dummy statement is added.
   */
  NVM_DUMMY_STATEMENT(partitionId);                                                                                     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
}

/*!
 * STATE: WaitForFinishedJob
 */

/**********************************************************************************************************************
 * NvM_NvJobDispatcherFsm_WaitForFinishedJobState_Entry()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, NVM_PRIVATE_CODE) NvM_NvJobDispatcherFsm_WaitForFinishedJobState_Entry(NvM_PartitionIdType partitionId)
{
  const NvM_NvJobContextPtrType nvJobContext = NvM_GetAddrNvJobContext(partitionId);
  switch(nvJobContext->SingleBlockJobType)
  {
    case NVM_SINGLEBLOCKJOBTYPE_READ_BLOCK:
    case NVM_SINGLEBLOCKJOBTYPE_READ_ALL_BLOCK:
      /* Spawn ReadNvBlock service FSM */
      NvM_ReadNvBlockFsm_ReadBlock(partitionId);
      break;

    case NVM_SINGLEBLOCKJOBTYPE_WRITE_BLOCK:
    case NVM_SINGLEBLOCKJOBTYPE_WRITE_ALL_BLOCK:
      /* Spawn WriteNvBlock service FSM */
      NvM_WriteNvBlockFsm_WriteBlock(partitionId);
      break;

    case NVM_SINGLEBLOCKJOBTYPE_INVALIDATE_NV_BLOCK:
    case NVM_SINGLEBLOCKJOBTYPE_ERASE_NV_BLOCK:
      /* Spawn ResetNvBlock service FSM */
      NvM_ResetNvBlockFsm_ResetBlock(partitionId);
      break;

    default:                                                                                                            /* COV_NVM_MISRA_BRANCH */
      /*
       * MISRA case. Do nothing.
       * This default case is empty due to the fact
       * that NVM_SINGLEBLOCKJOBTYPE_RESTORE_BLOCK_DEFAULTS is processed beforehand.
      */
      break;
  }
}

/**********************************************************************************************************************
 * NvM_NvJobDispatcherFsm_WaitForFinishedJobState_Do()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(NvM_FsmLib_ProcessingResultType, NVM_PRIVATE_CODE) NvM_NvJobDispatcherFsm_WaitForFinishedJobState_Do(
  NvM_PartitionIdType partitionId)
{
  /*
   * The parameter partitionId is not used within this function in single partition use case.
   * To avoid compiler warnings the following dummy statement is added.
   */
  NVM_DUMMY_STATEMENT(partitionId);                                                                                     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  NvM_FsmLib_InstancePtrType fsmLibInstance =
    (NvM_FsmLib_InstancePtrType)NvM_GetAddrNvServiceFsmLib_Instance(partitionId);

  NvM_ServiceJobResultType serviceJobResult = NvM_FsmLib_GetSubFsmResult(fsmLibInstance);

  NvM_FsmLib_FinalizeCurrentActiveFsm(fsmLibInstance, serviceJobResult);
  return NVM_FSMLIB_PROCESSINGRESULT_CONTINUE;
}

/**********************************************************************************************************************
 * NvM_NvJobDispatcherFsm_GetBlockNumber()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
NVM_LOCAL_INLINE FUNC(uint16, NVM_PRIVATE_CODE) NvM_NvJobDispatcherFsm_GetBlockNumber(
  const NvM_BlockDescriptorLookupTableIdType blockDescriptorLookupTableId,
  const uint8 dataIndex)
{
  NvM_BlockDescriptorPtrType blockDescriptor = NvM_GetAddrBlockDescriptor(blockDescriptorLookupTableId);
  uint16 retVal = blockDescriptor->HwAbsBlockNumber;

  if ((blockDescriptor->BlockManagementType == NVM_BLOCK_MANAGEMENT_TYPE_DATASET))
  {
    retVal |= dataIndex;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * NvM_NvJobDispatcherFsm_Execute()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, NVM_PRIVATE_CODE) NvM_NvJobDispatcherFsm_Execute(
  NvM_SingleBlockJobContextPtrToConstType singleBlockJobContext,
  NvM_PartitionIdType partitionId)
{
  NvM_FsmLib_InstancePtrType fsmLibInstance =
    (NvM_FsmLib_InstancePtrType)NvM_GetAddrNvServiceFsmLib_Instance(partitionId);

  NvM_NvJobContextPtrType nvJobContext = NvM_GetAddrNvJobContext(partitionId);

  /* setup master job context */
  nvJobContext->BlockDescriptorLookupTableId = singleBlockJobContext->BlockDescriptorLookupTableId;
  nvJobContext->DataBuffer = singleBlockJobContext->DataBuffer;
  nvJobContext->SingleBlockJobType = singleBlockJobContext->SingleBlockJobType;
  nvJobContext->BlockNumber = NvM_NvJobDispatcherFsm_GetBlockNumber(
    singleBlockJobContext->BlockDescriptorLookupTableId, singleBlockJobContext->DataIndex);

  (void)NvM_FsmLib_SpawnFsm(fsmLibInstance, NvM_NvJobDispatcherFsm);

  /*
   * The parameter partitionId is not used within this function in single partition use case.
   * To avoid compiler warnings the following dummy statement is added.
   */
  NVM_DUMMY_STATEMENT(partitionId);                                                                                     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
}

#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: NvM_NvJobDispatcherFsm.c
 *********************************************************************************************************************/
