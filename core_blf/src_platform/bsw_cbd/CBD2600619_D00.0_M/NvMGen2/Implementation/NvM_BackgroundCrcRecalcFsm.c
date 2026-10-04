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
/*!        \file  NvM_BackgroundCrcRecalcFsm.c
 *        \brief  NvM_BackgroundCrcRecalcFsm source file
 *      \details  Implementation of the background data integrity recalculation state machine
 *         \unit  NvM_BackgroundCrcRecalcFsm
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#define NVM_BACKGROUNDCRCRECALCFSM_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "NvM_DataIntegrityService.h"
#include "NvM_BackgroundCrcRecalcFsm.h"
#include "NvM_DataIntegrityRecalcQueue.h"
#include "NvM_GlobalUtilityLib.h"
#include "NvM_FsmLib.h"
#include "NvM_DataSync.h"
#include "NvM_Notification.h"
#include "NvM_Cfg.h"

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
 * NvM_BackgroundCrcRecalcFsm_Entry()
 *********************************************************************************************************************/
/*!  \brief       ENTRY action of BackgroundCrcRecalcFsm.
 *   \details     -
 *   \param[in]   partitionId Partition ID.
 *   \pre         -
 *   \context     TASK
 *   \reentrant   FALSE
 *   \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, NVM_PRIVATE_CODE) NvM_BackgroundCrcRecalcFsm_Entry(NvM_PartitionIdType partitionId);

/**********************************************************************************************************************
 * NvM_BackgroundCrcRecalcFsm_IdleState_Do()
 *********************************************************************************************************************/
/*!  \brief       DO action of BackgroundCrcRecalcFsm state Idle.
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
FUNC(NvM_FsmLib_ProcessingResultType, NVM_PRIVATE_CODE) NvM_BackgroundCrcRecalcFsm_IdleState_Do(
  NvM_PartitionIdType partitionId);

/**********************************************************************************************************************
 * NvM_BackgroundCrcRecalcFsm_RecalculateCrcState_Do()
 *********************************************************************************************************************/
/*!  \brief       DO action of BackgroundCrcRecalcFsm state RecalculateCrcState.
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
FUNC(NvM_FsmLib_ProcessingResultType, NVM_PRIVATE_CODE) NvM_BackgroundCrcRecalcFsm_RecalculateCrcState_Do(
  NvM_PartitionIdType partitionId);

/***********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

/**********************************************************************************************************************
 * NvM_BackgroundCrcRecalcFsm_SetupDataIntegrityServiceJob()
 *********************************************************************************************************************/
/*! \brief           Setup the data integrtity service job.
 *  \details         -
 *  \param[in]       dataIntegrityDataBuffer        Data Buffer to calculate CRC from.
 *  \param[in]       blockDescriptor                Current Block Descriptor.
 *  \param[in]       blockDescriptorLookupTableId   Current Block Descriptor Look Up Table ID.
 *  \param[in]       partitionId                    Partition ID.
 *  \pre             -
 *  \context         TASK
 *  \reentrant       FALSE
 *  \synchronous     TRUE
 *********************************************************************************************************************/
NVM_LOCAL FUNC(void, NVM_PRIVATE_CODE) NvM_BackgroundCrcRecalcFsm_SetupDataIntegrityServiceJob(
  NvM_DataPtrType dataIntegrityDataBuffer,
  NvM_BlockDescriptorPtrToConstType blockDescriptor,
  const NvM_BlockDescriptorLookupTableIdType blockDescriptorLookupTableId,
  const NvM_PartitionIdType partitionId);

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
 * Initializing a const structure (NvM_BackgroundCrcRecalcFsm_InitialState) can only be done with compile-time constants.
 * Therefore this defines are introduced to minimize code duplication within NvM_BackgroundCrcRecalcFsm_InitialState and
 * NvM_BackgroundCrcRecalcFsm_IdleState initialization.
 */
#define NVM_BACKGROUNDCRCRECALCFSM_IDLESTATE_ENTRY NvM_FsmLib_EntryNoOp
#define NVM_BACKGROUNDCRCRECALCFSM_IDLESTATE_DO NvM_BackgroundCrcRecalcFsm_IdleState_Do

/*! STATE: IdleState */
/* PRQA S 3218 1 */ /* MD_Fsm_StateDefinitionStaticUsedOnlyInSingleFunction */
NVM_LOCAL CONST(NvM_StateType, NVM_PRIVATE_DATA) NvM_BackgroundCrcRecalcFsm_IdleState = {
  NVM_BACKGROUNDCRCRECALCFSM_IDLESTATE_ENTRY,
  NVM_BACKGROUNDCRCRECALCFSM_IDLESTATE_DO
};

/*! STATE: RecalculateCrcState */
/* PRQA S 3218 1 */ /* MD_Fsm_StateDefinitionStaticUsedOnlyInSingleFunction */
NVM_LOCAL CONST(NvM_StateType, NVM_PRIVATE_DATA) NvM_BackgroundCrcRecalcFsm_RecalculateCrcState = {
  NvM_FsmLib_EntryNoOp,
  NvM_BackgroundCrcRecalcFsm_RecalculateCrcState_Do
};

/*! FSM: BackgroundCrcRecalc with ENTRY action and initial state */
/* PRQA S 3218 1 */ /* MD_Fsm_StateDefinitionStaticUsedOnlyInSingleFunction */
NVM_LOCAL CONST(NvM_FsmType, NVM_PRIVATE_DATA) NvM_BackgroundCrcRecalcFsm_InitialState = {
  NvM_BackgroundCrcRecalcFsm_Entry,
  {
    NVM_BACKGROUNDCRCRECALCFSM_IDLESTATE_ENTRY,
    NVM_BACKGROUNDCRCRECALCFSM_IDLESTATE_DO
  }
};

#define NVM_STOP_SEC_CONST_UNSPECIFIED
#include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  LOCAL FUNCTIONS
 **********************************************************************************************************************/
#define NVM_START_SEC_CODE
#include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * NvM_BackgroundCrcRecalcFsm_Entry()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, NVM_PRIVATE_CODE) NvM_BackgroundCrcRecalcFsm_Entry(NvM_PartitionIdType partitionId)                          /* PRQA S 3206 */ /* MD_NvM_CslMacroNotUsingPartitionId */
{
  NvM_FsmLib_InstancePtrType fsmLibInstance =
    (NvM_FsmLib_InstancePtrType)NvM_GetAddrBackgroundCrcRecalcFsmLib_Instance(partitionId);

  NvM_FsmLib_TransitionToState(fsmLibInstance, NvM_BackgroundCrcRecalcFsm_IdleState);

  /*
   * The parameter partitionId is not used within this function in single partition use case.
   * To avoid compiler warnings the following dummy statement is added.
   */
  NVM_DUMMY_STATEMENT(partitionId);                                                                                     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
}

/**********************************************************************************************************************
 * NvM_BackgroundCrcRecalcFsm_IdleState_Do()
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
 *
 *
 *
 *
 *
 */
FUNC(NvM_FsmLib_ProcessingResultType, NVM_PRIVATE_CODE) NvM_BackgroundCrcRecalcFsm_IdleState_Do(
  NvM_PartitionIdType partitionId)                                                                                      /* PRQA S 3206 */ /* MD_NvM_CslMacroNotUsingPartitionId */
{
  NvM_FsmLib_ProcessingResultType result = NVM_FSMLIB_PROCESSINGRESULT_STOP;

  NvM_DataIntegrityRecalcQueue_InstancePtrType recalcQueueInstance =
   NvM_GetAddrDataIntegrityRecalcQueue_Instance(partitionId);

  NvM_BlockDescriptorLookupTableIdType blockDescriptorLookupTableId = 0u;

  if (NvM_DataIntegrityRecalcQueue_Pop(recalcQueueInstance, &blockDescriptorLookupTableId) == E_OK)
  {
    /*@ assert blockDescriptorLookupTableId < GetSizeOfBlockDescriptor(); */                                            /* VCA_NVM_BlockDescriptorLookupTableId */

    NvM_FsmLib_InstancePtrType fsmLibInstance =
      (NvM_FsmLib_InstancePtrType)NvM_GetAddrBackgroundCrcRecalcFsmLib_Instance(partitionId);

    /*
     * Has to be set when job is popped from the queue, so in the potential following state
     * the background CRC recalc notification can be invoked with correct block context.
     */
    NvM_BackgroundCrcRecalcFsm_ContextPtrType fsmContext = NvM_GetAddrBackgroundCrcRecalcFsm_Context(partitionId);
    fsmContext->CurrentBlockDescriptorLookUpTableId = blockDescriptorLookupTableId;

    NvM_BlockDescriptorPtrType blockDescriptor = NvM_GetAddrBlockDescriptor(blockDescriptorLookupTableId);

    NvM_DataPtrType dataIntegrityDataBuffer = NULL_PTR;

#if (NVM_CRCINTERNALEXPLICITSYNCBUFFER == STD_ON)
    if (blockDescriptor->WriteRamBlockToNvCallback != NULL_PTR)
    {
      dataIntegrityDataBuffer = NvM_GetAddrCrcInternalExplicitSyncBuffer(0u, partitionId);
      if (NvM_DataSync_RequestData(blockDescriptorLookupTableId, dataIntegrityDataBuffer, NULL_PTR) == E_OK)
      {
        NvM_BackgroundCrcRecalcFsm_SetupDataIntegrityServiceJob(
            dataIntegrityDataBuffer,
            blockDescriptor,
            blockDescriptorLookupTableId,
            partitionId);

        NvM_FsmLib_TransitionToState(fsmLibInstance, NvM_BackgroundCrcRecalcFsm_RecalculateCrcState);
        result = NVM_FSMLIB_PROCESSINGRESULT_CONTINUE;
      }
      else
      {
        NvM_Notification_ProcessBackgroundCrcRecalcNotification(
          fsmContext->CurrentBlockDescriptorLookUpTableId, NVM_REQ_NOT_OK);
      }
    }
    else
#endif
    {
      dataIntegrityDataBuffer = blockDescriptor->RamBlockDataAddress;

      NvM_BackgroundCrcRecalcFsm_SetupDataIntegrityServiceJob(
          dataIntegrityDataBuffer,
          blockDescriptor,
          blockDescriptorLookupTableId,
          partitionId);

      NvM_FsmLib_TransitionToState(fsmLibInstance, NvM_BackgroundCrcRecalcFsm_RecalculateCrcState);
      result = NVM_FSMLIB_PROCESSINGRESULT_CONTINUE;
    }
  }

  /*
   * The parameter partitionId is not used within this function in single partition use case.
   * To avoid compiler warnings the following dummy statement is added.
   */
  NVM_DUMMY_STATEMENT(partitionId);                                                                                     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  return result;
}

/**********************************************************************************************************************
 * NvM_BackgroundCrcRecalcFsm_RecalculateCrcState_Do()
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
FUNC(NvM_FsmLib_ProcessingResultType, NVM_PRIVATE_CODE)
  NvM_BackgroundCrcRecalcFsm_RecalculateCrcState_Do(NvM_PartitionIdType partitionId)     /* PRQA S 3206 */ /* MD_NvM_CslMacroNotUsingPartitionId */
{
  NvM_FsmLib_ProcessingResultType result = NVM_FSMLIB_PROCESSINGRESULT_STOP;

  NvM_FsmLib_InstancePtrType fsmLibInstance =
    (NvM_FsmLib_InstancePtrType)NvM_GetAddrBackgroundCrcRecalcFsmLib_Instance(partitionId);

  NvM_DataIntegrityService_InstancePtrType backgroundDataIntegrityServiceInstance =
    (NvM_DataIntegrityService_InstancePtrType)NvM_GetAddrBackgroundDataIntegrityService_Instance(partitionId);

  NvM_DataIntegrityService_Status jobStatus = NvM_DataIntegrityService_GetStatus(backgroundDataIntegrityServiceInstance);

  if(jobStatus == NVM_DATAINTEGRITYSERVICE_STATUS_PENDING)
  {
    NvM_DataIntegrityService_Process(backgroundDataIntegrityServiceInstance);
  }
  else
  {
    NvM_BackgroundCrcRecalcFsm_ContextPtrType fsmContext = NvM_GetAddrBackgroundCrcRecalcFsm_Context(partitionId);

    /* The generation job of DataIntegrityService for CRC is always successful */
    NvM_Notification_ProcessBackgroundCrcRecalcNotification(
      fsmContext->CurrentBlockDescriptorLookUpTableId, NVM_REQ_OK);

    NvM_FsmLib_TransitionToState(fsmLibInstance, NvM_BackgroundCrcRecalcFsm_IdleState);

    result = NVM_FSMLIB_PROCESSINGRESULT_CONTINUE;
  }

  /*
   * The parameter partitionId is not used within this function in single partition use case.
   * To avoid compiler warnings the following dummy statement is added.
   */
  NVM_DUMMY_STATEMENT(partitionId);                                                                                     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  return result;
}

/**********************************************************************************************************************
 * NvM_BackgroundCrcRecalcFsm_SetupDataIntegrityServiceJob()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
NVM_LOCAL FUNC(void, NVM_PRIVATE_CODE) NvM_BackgroundCrcRecalcFsm_SetupDataIntegrityServiceJob(
  NvM_DataPtrType dataIntegrityDataBuffer,
  NvM_BlockDescriptorPtrToConstType blockDescriptor,
  const NvM_BlockDescriptorLookupTableIdType blockDescriptorLookupTableId,
  const NvM_PartitionIdType partitionId)
{
  NvM_BackgroundDataIntegrityService_InstancePtrType backgroundDataIntegrityServiceInstance =
    NvM_GetAddrBackgroundDataIntegrityService_Instance(partitionId);

  NvM_BlockManagementInformationPtrType blockManagementInfo = NvM_GlobalUtilityLib_GetBlockManagementInfo(
    blockDescriptor->NvramBlockIdentifier,
    blockDescriptorLookupTableId,
    partitionId
  );

  NvM_DataIntegrityJobContextType dataIntegrityJobContext = {
    NVM_DATAINTEGRITYSERVICE_JOB_GENERATE,
    dataIntegrityDataBuffer,
    blockDescriptor->DataIntegrityIntBuffer,
    blockDescriptor->NvramBlockIdentifier,
    blockDescriptorLookupTableId,
    blockManagementInfo->DataIndex,
    partitionId
  };

  NvM_DataIntegrityService_Init(backgroundDataIntegrityServiceInstance, &dataIntegrityJobContext);
}

/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

/**********************************************************************************************************************
 * NvM_BackgroundCrcRecalcFsm_Spawn()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, NVM_PRIVATE_CODE) NvM_BackgroundCrcRecalcFsm_Spawn(NvM_PartitionIdType partitionId)
{
  NvM_FsmLib_InstancePtrType fsmLibInstance =
    (NvM_FsmLib_InstancePtrType)NvM_GetAddrBackgroundCrcRecalcFsmLib_Instance(partitionId);

  /* COM-4978: Wait for CSL feature to store init value of generated partion data */
  NvM_BackgroundCrcRecalcFsm_InstancePtrType fsmInstance = NvM_GetAddrBackgroundCrcRecalcFsm_Instance(partitionId);

  *fsmInstance = NvM_BackgroundCrcRecalcFsm_InitialState;

  (void)NvM_FsmLib_SpawnFsm(fsmLibInstance, *fsmInstance);

  /*
   * The parameter partitionId is not used within this function in single partition use case.
   * To avoid compiler warnings the following dummy statement is added.
   */
  NVM_DUMMY_STATEMENT(partitionId);                                                                                     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
}

# define NVM_STOP_SEC_CODE
# include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  VCA JUSTIFICATIONS
 **********************************************************************************************************************/
/* VCA_JUSTIFICATION_BEGIN

\ID VCA_NVM_BlockDescriptorLookupTableId
  \DESCRIPTION The NvM_DataIntegrityRecalcQueue_Pop takes the blockDescriptorLookupTableId variable as an in/out
               parameter. This functions changes the value of this variable, because in the data integrity recalc
               queue provides always the block descriptor look up table id to select the next block where the
               background CRC recalculation has to be done. Technical, it is possible that the
               NvM_DataIntegrityRecalcQueue_Pop can provide values outside the range of the blockDescriptorLookupTableId
               type invariant but this is excluded by design.

  \COUNTERMEASURE \N A code review ensures that the BlockDescriptorLookupTableId is always in range when used.

VCA_JUSTIFICATION_END */

/**********************************************************************************************************************
 *  END OF FILE: NvM_BackgroundCrcRecalcFsm.c
 *********************************************************************************************************************/
