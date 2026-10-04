/***********************************************************************************************************************
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
/*!        \file  NvM_SingleBlockJobFsm.c
 *        \brief  NvM_SingleBlockJobFsm source file
 *      \details  Implementation of service base state machine
 *         \unit  NvM_SingleBlockJobFsm
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *
 *  FILE VERSION
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the VERSION CHECK below.
 **********************************************************************************************************************/

#define NVM_SingleBlockJobFsm_SOURCE

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
#include "NvM_SingleBlockJobFsm.h"
#include "NvM_Types.h"
#include "NvM_FsmLib.h"
#include "NvM_GlobalUtilityLib.h"
#include "NvM_WriteBlockFsm.h"
#include "NvM_ReadBlockFsm.h"
#include "NvM_NvJobFsm.h"
#include "NvM_DataSync.h"

/***********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  FSM FUNCTION PROTOTYPES
 **********************************************************************************************************************/
#define NVM_START_SEC_CODE
#include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * NvM_SingleBlockJobFsm_Entry()
 *********************************************************************************************************************/
/*!  \brief       ENTRY action of SingleBlockJobFsm.
 *   \details     -
 *   \param[in]   partitionId Partition ID.
 *   \pre         -
 *   \context     TASK
 *   \reentrant   FALSE
 *   \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, NVM_PRIVATE_CODE) NvM_SingleBlockJobFsm_Entry(NvM_PartitionIdType partitionId);

/**********************************************************************************************************************
 * NvM_SingleBlockJobFsm_WaitForFinishedJobState_Entry()
 *********************************************************************************************************************/
/*!  \brief       ENTRY action of SingleBlockJobFsm state WaitForFinishedJobState
 *   \details     -
 *   \param[in]   partitionId Partition ID.
 *   \pre         -
 *   \context     TASK
 *   \reentrant   FALSE
 *   \synchronous TRUE
 *********************************************************************************************************************/
NVM_LOCAL FUNC(void, NVM_PRIVATE_CODE) NvM_SingleBlockJobFsm_WaitForFinishedJobState_Entry(
  NvM_PartitionIdType partitionId);

/**********************************************************************************************************************
 * NvM_SingleBlockJobFsm_WaitForFinishedJobState_Do()
 *********************************************************************************************************************/
/*!  \brief       DO action of SingleBlockJobFsm state WaitForFinishedJobState
 *   \details     -
 *   \param[in]   partitionId Partition ID.
 *   \return      Always NVM_FSMLIB_PROCESSINGRESULT_CONTINUE.
 *   \pre         -
 *   \context     TASK
 *   \reentrant   FALSE
 *   \synchronous TRUE
 *********************************************************************************************************************/
NVM_LOCAL FUNC(NvM_FsmLib_ProcessingResultType, NVM_PRIVATE_CODE) NvM_SingleBlockJobFsm_WaitForFinishedJobState_Do(
  NvM_PartitionIdType partitionId);

#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 **********************************************************************************************************************/

#define NVM_START_SEC_CONST_UNSPECIFIED
#include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*
 * Initializing a const structure (NvM_SingleBlockJobFsm_InitialState) can only be done with compile-time constants.
 * Therefore this defines are introduced to minimize code duplication within NvM_SingleBlockJobFsm_InitialState and
 * NvM_SingleBlockJobFsm_IdleState initialization.
 */
#define NVM_SINGLEBLOCKJOBFSM_WAITFORFINISHEDJOBSTATE_ENTRY NvM_SingleBlockJobFsm_WaitForFinishedJobState_Entry
#define NVM_SINGLEBLOCKJOBFSM_WAITFORFINISHEDJOBSTATE_DO NvM_SingleBlockJobFsm_WaitForFinishedJobState_Do

/*! STATE: WaitForFinishedJobState */

/* PRQA S 3218 1 */ /* MD_Fsm_StateDefinitionStaticUsedOnlyInSingleFunction */
NVM_LOCAL CONST(NvM_StateType, NVM_PRIVATE_DATA) NvM_SingleBlockJobFsm_WaitForFinishedJobState = {
  NvM_SingleBlockJobFsm_WaitForFinishedJobState_Entry,
  NvM_SingleBlockJobFsm_WaitForFinishedJobState_Do
};

/*! FSM: SingleBlockJobFsm instance with ENTRY action and initial state Idle */
/* PRQA S 3218 1 */ /* MD_Fsm_StateDefinitionStaticUsedOnlyInSingleFunction */
NVM_LOCAL CONST(NvM_FsmType, NVM_PRIVATE_DATA) NvM_SingleBlockJobFsm_InitialState = {
  NvM_SingleBlockJobFsm_Entry,
  {NVM_SINGLEBLOCKJOBFSM_WAITFORFINISHEDJOBSTATE_ENTRY, NVM_SINGLEBLOCKJOBFSM_WAITFORFINISHEDJOBSTATE_DO}
};

#define NVM_STOP_SEC_CONST_UNSPECIFIED
#include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  GLOBAL DATA
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/
#define NVM_START_SEC_CODE
#include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 * NvM_RecoverBlockDefaultData()
 *********************************************************************************************************************/
/*! \brief       Attempt default data recovery for specific block.
 *  \details     -
 *  \param[in]   partitionId PartitionId.
 *  \param[in]   blockDescriptorLookupTableId Block Descriptor Lookup Table Id of block for default data recovery.
 *  \pre         -
 *  \return      Service job result indicating success or failure of default data recovery
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
NVM_LOCAL_INLINE FUNC(NvM_ServiceJobResultType, NVM_PRIVATE_CODE) NvM_RecoverBlockDefaultData(
  const NvM_PartitionIdType partitionId,
  const NvM_BlockDescriptorLookupTableIdType blockDescriptorLookupTableId);

/**********************************************************************************************************************
 * NvM_AttemptResetCrcCompMechanismBuffer()
 *********************************************************************************************************************/
/*! \brief       Attempt to reset CrcCompMechanismBuffer based on job result and job type.
 *  \details     -
 *  \param[in]   partitionId PartitionId.
 *  \param[in]   serviceJobResult Service job result.
 *  \pre         -
 *  \return      None
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
NVM_LOCAL_INLINE FUNC(void, NVM_PRIVATE_CODE) NvM_AttemptResetCrcCompMechanismBuffer(
  const NvM_PartitionIdType partitionId,
  const NvM_ServiceJobResultType serviceJobResult);

/***********************************************************************************************************************
 *  LOCAL FUNCTIONS
 **********************************************************************************************************************/

/**********************************************************************************************************************
 * NvM_RecoverBlockDefaultData()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
NVM_LOCAL_INLINE FUNC(NvM_ServiceJobResultType, NVM_PRIVATE_CODE) NvM_RecoverBlockDefaultData(
  const NvM_PartitionIdType partitionId,
  const NvM_BlockDescriptorLookupTableIdType blockDescriptorLookupTableId)
{
  /* unused in single partition use case */
  NVM_DUMMY_STATEMENT_CONST(partitionId);                                                                               /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  NvM_SingleBlockJobContextPtrType singleBlockJobContext = NvM_GetAddrSingleBlockJobContext(partitionId);

  NvM_ServiceJobResultType serviceJobResult = NVM_SERVICE_JOB_OK;

  if(NvM_DataSync_RestoreDefaultData(blockDescriptorLookupTableId, singleBlockJobContext->SingleBlockJobType,
      singleBlockJobContext->TemporaryRamBlockAddr) != E_OK)
  {
    serviceJobResult = NVM_SERVICE_JOB_NOT_OK;
  }

  return serviceJobResult;
}

/**********************************************************************************************************************
 * NvM_AttemptResetCrcCompMechanismBuffer()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
NVM_LOCAL_INLINE FUNC(void, NVM_PRIVATE_CODE) NvM_AttemptResetCrcCompMechanismBuffer(
  const NvM_PartitionIdType partitionId,
  const NvM_ServiceJobResultType serviceJobResult)
{
  /* unused in single partition use case */
  NVM_DUMMY_STATEMENT_CONST(partitionId);                                                                               /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  NvM_SingleBlockJobContextPtrType singleBlockJobContext = NvM_GetAddrSingleBlockJobContext(partitionId);

  const NvM_BlockDescriptorPtrType blockDescriptor = NvM_GetAddrBlockDescriptor(singleBlockJobContext->BlockDescriptorLookupTableId);

  switch(singleBlockJobContext->SingleBlockJobType)
  {
    case NVM_SINGLEBLOCKJOBTYPE_WRITE_BLOCK:
    case NVM_SINGLEBLOCKJOBTYPE_WRITE_ALL_BLOCK:
    case NVM_SINGLEBLOCKJOBTYPE_READ_BLOCK:
    case NVM_SINGLEBLOCKJOBTYPE_READ_ALL_BLOCK:
      if (serviceJobResult != NVM_SERVICE_JOB_OK)
      {
        /* Update CrcCompMechanismBuffer with Reset value */
        NvM_GlobalUtilityLib_ResetCrcCompMechanismBuffer(blockDescriptor->CrcCompMechanismBuffer, 
          blockDescriptor->DataIntegritySettings);
      }

      break;
    /* Invalidate DataIntegrityRecordCompMechanism data of current block (either no/invalid data in NV RAM 
      or unknown state because of failed erase/invalidation)
    case NVM_SINGLEBLOCKJOBTYPE_INVALIDATE_NV_BLOCK:
    case NVM_SINGLEBLOCKJOBTYPE_ERASE_NV_BLOCK:
      Better to reset the value as when the customer wanted to restore default data on RAM side customer 
      defintitely does not want the next write to be skipped
      (It does not matter if this restoration failed or succeeded)
    case NVM_SINGLEBLOCKJOBTYPE_RESTORE_BLOCK_DEFAULTS: */
    default:
      /* Update CrcCompMechanismBuffer with Reset value */
      NvM_GlobalUtilityLib_ResetCrcCompMechanismBuffer(blockDescriptor->CrcCompMechanismBuffer, 
        blockDescriptor->DataIntegritySettings);

        break; 
  }
}

/**********************************************************************************************************************
 * NvM_SingleBlockJobFsm_Entry()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, NVM_PRIVATE_CODE) NvM_SingleBlockJobFsm_Entry(NvM_PartitionIdType partitionId)
{
  NvM_FsmLib_InstancePtrToConstType singleBlockJobFsmInstance =
    (NvM_FsmLib_InstancePtrToConstType)NvM_GetAddrSingleBlockServiceFsmLib_Instance(partitionId);

  NvM_FsmLib_TransitionToState(singleBlockJobFsmInstance, NvM_SingleBlockJobFsm_WaitForFinishedJobState);

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
 * NvM_SingleBlockJobFsm_WaitForFinishedJobState_Entry()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
NVM_LOCAL FUNC(void, NVM_PRIVATE_CODE) NvM_SingleBlockJobFsm_WaitForFinishedJobState_Entry(
  NvM_PartitionIdType partitionId)
{
  NvM_SingleBlockJobContextPtrToConstType singleBlockJobContext = NvM_GetAddrSingleBlockJobContext(partitionId);

  switch(singleBlockJobContext->SingleBlockJobType)
  {
    case NVM_SINGLEBLOCKJOBTYPE_READ_BLOCK:
    case NVM_SINGLEBLOCKJOBTYPE_READ_ALL_BLOCK:
      NvM_ReadBlockFsm_ReadBlock(partitionId);
      break;

    case NVM_SINGLEBLOCKJOBTYPE_WRITE_BLOCK:
    case NVM_SINGLEBLOCKJOBTYPE_WRITE_ALL_BLOCK:
      NvM_WriteBlockFsm_WriteBlock(partitionId);
      break;

    case NVM_SINGLEBLOCKJOBTYPE_RESTORE_BLOCK_DEFAULTS:
      /* As the processing of the RestoreBlockDefaults API is trivial it is done in the Do Action of this state */
      break;

    case NVM_SINGLEBLOCKJOBTYPE_INVALIDATE_NV_BLOCK:
    case NVM_SINGLEBLOCKJOBTYPE_ERASE_NV_BLOCK:
      NvM_NvJobFsm_Execute(partitionId);
      break;

    default:                                                                                                            /* COV_NVM_MISRA_BRANCH */
      /*
       * MISRA case. Do nothing.
       * This default case is empty because this function only processes single block jobs
       * which are not in the context of read all and write all.
       */
      break;
  }

}

/**********************************************************************************************************************
 * NvM_SingleBlockJobFsm_WaitForFinishedJobState_Do()
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
NVM_LOCAL FUNC(NvM_FsmLib_ProcessingResultType, NVM_PRIVATE_CODE) NvM_SingleBlockJobFsm_WaitForFinishedJobState_Do(
  NvM_PartitionIdType partitionId)
{
  NvM_ServiceJobResultType serviceJobResult = NVM_SERVICE_JOB_NOT_OK;
  NvM_FsmLib_InstancePtrType singleBlockJobFsmLibInstance =
    (NvM_FsmLib_InstancePtrType)NvM_GetAddrSingleBlockServiceFsmLib_Instance(partitionId);

  NvM_SingleBlockJobContextPtrToConstType singleBlockJobContext = NvM_GetAddrSingleBlockJobContext(partitionId);

  if(singleBlockJobContext->SingleBlockJobType == NVM_SINGLEBLOCKJOBTYPE_RESTORE_BLOCK_DEFAULTS)
  {
    serviceJobResult = NvM_RecoverBlockDefaultData(partitionId, singleBlockJobContext->BlockDescriptorLookupTableId);
  }
  else
  {
    serviceJobResult = NvM_FsmLib_GetSubFsmResult(singleBlockJobFsmLibInstance);
  }

  /* This state is the last state for every singleblockjob processing. Here it can be 
    attempted to reset the CrcCompMechanismBuffer (Exception: Extended runtime handling in ReadAllFsm) */
  NvM_AttemptResetCrcCompMechanismBuffer(partitionId, serviceJobResult);

  NvM_FsmLib_FinalizeCurrentActiveFsm(singleBlockJobFsmLibInstance, serviceJobResult);

  return NVM_FSMLIB_PROCESSINGRESULT_CONTINUE;
}

/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

/**********************************************************************************************************************
 * NvM_SingleBlockJobFsm_Spawn()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, NVM_PRIVATE_CODE) NvM_SingleBlockJobFsm_Spawn(NvM_PartitionIdType partitionId)                               /* PRQA S 3206 */ /* MD_NvM_CslMacroNotUsingPartitionId */
{
  NvM_FsmLib_InstancePtrType singleBlockJobFsmLibInstance =
    (NvM_FsmLib_InstancePtrType)NvM_GetAddrSingleBlockServiceFsmLib_Instance(partitionId);

  /* COM-4978: Wait for CSL feature to store init value of generated partition data */
  NvM_FsmPtrType fsmInstance = (NvM_FsmPtrType)NvM_GetAddrSingleBlockJobFsm_Instance(partitionId);
  *fsmInstance = NvM_SingleBlockJobFsm_InitialState;

  (void)NvM_FsmLib_SpawnFsm(singleBlockJobFsmLibInstance, *fsmInstance);

  /*
   * The parameter partitionId is not used within this function in single partition use case.
   * To avoid compiler warnings the following dummy statement is added.
   */
  NVM_DUMMY_STATEMENT(partitionId);                                                                                     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
}

#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  END OF FILE: NvM_SingleBlockJobFsm.c
 **********************************************************************************************************************/
