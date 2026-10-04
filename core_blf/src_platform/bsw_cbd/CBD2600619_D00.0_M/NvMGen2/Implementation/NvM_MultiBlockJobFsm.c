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
/*!        \file  NvM_MultiBlockJobFsm.c
 *        \brief  NvM_MultiBlockJobFsm source file
 *      \details  Implementation of multi-block job state machine
 *         \unit  NvM_MultiBlockJobFsm
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

#define NVM_MULTIBLOCKJOBFSM_SOURCE

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
#include "NvM_MultiBlockJobFsm.h"
#include "NvM_Types.h"
#include "NvM_FsmLib.h"
#include "NvM_GlobalUtilityLib.h"
#include "NvM_Notification.h"

#if (NVM_MULTIPARTITION_USAGE_SCENARIO == STD_ON)
#include "NvM_SatelliteCom.h"
#endif

#include "NvM_ReadAllFsm.h"
#include "NvM_WriteAllFsm.h"
#include "NvM_ValidateAllFsm.h"

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
 * NvM_MultiBlockJobFsm_Entry()
 *********************************************************************************************************************/
/*!  \brief       ENTRY action of MultiBlockJobFsm.
 *   \details     -
 *   \param[in]   partitionId Partition ID.
 *   \pre         -
 *   \context     TASK
 *   \reentrant   FALSE
 *   \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, NVM_PRIVATE_CODE) NvM_MultiBlockJobFsm_Entry(NvM_PartitionIdType partitionId);

/**********************************************************************************************************************
 * NvM_MultiBlockJobFsm_WaitForFinishedMultiBlockServiceState_Entry()
 *********************************************************************************************************************/
/*!  \brief       ENTRY action of MultiBlockJobFsm state WaitForFinishedMultiBlockService
 *   \details     -
 *   \param[in]   partitionId Partition ID.
 *   \pre         -
 *   \context     TASK
 *   \reentrant   FALSE
 *   \synchronous TRUE
 *********************************************************************************************************************/
NVM_LOCAL FUNC(void, NVM_PRIVATE_CODE) NvM_MultiBlockJobFsm_WaitForFinishedMultiBlockServiceState_Entry(
  NvM_PartitionIdType partitionId);

/**********************************************************************************************************************
 * NvM_MultiBlockJobFsm_WaitForFinishedMultiBlockServiceState_Do()
 *********************************************************************************************************************/
/*!  \brief       DO action of MultiBlockJobFsm state WaitForFinishedMultiBlockService
 *   \details     -
 *   \param[in]   partitionId Partition ID.
 *   \return      Always NVM_FSMLIB_PROCESSINGRESULT_CONTINUE.
 *   \pre         -
 *   \context     TASK
 *   \reentrant   FALSE
 *   \synchronous TRUE
 *********************************************************************************************************************/
NVM_LOCAL FUNC(NvM_FsmLib_ProcessingResultType, NVM_PRIVATE_CODE) NvM_MultiBlockJobFsm_WaitForFinishedMultiBlockServiceState_Do(
  NvM_PartitionIdType partitionId);

#if (NVM_MULTIPARTITION_USAGE_SCENARIO == STD_ON)

/**********************************************************************************************************************
 * NvM_MultiBlockJobFsm_ReadyForMultiBlockServiceState_Entry()
 *********************************************************************************************************************/
/*! \brief           ENTRY action of MultiBlockJobFsm state ReadyForMultiBlockServiceState
 *  \details         -
 *  \param[in]       partitionId Partition ID.
 *  \pre             -
 *  \context         TASK
 *  \reentrant       FALSE
 *  \synchronous     TRUE
 *********************************************************************************************************************/
NVM_LOCAL FUNC(void, NVM_PRIVATE_CODE) NvM_MultiBlockJobFsm_ReadyForMultiBlockServiceState_Entry(
  NvM_PartitionIdType partitionId);

/**********************************************************************************************************************
 * NvM_MultiBlockJobFsm_ReadyForMultiBlockServiceState_Do()
 *********************************************************************************************************************/
/*! \brief           DO action of MultiBlockJobFsm state ReadyForMultiBlockServiceState
 *  \details         -
 *  \param[in]       partitionId Partition ID.
 *  \pre             -
 *  \context         TASK
 *  \reentrant       FALSE
 *  \synchronous     TRUE
 *********************************************************************************************************************/
NVM_LOCAL FUNC(NvM_FsmLib_ProcessingResultType, NVM_PRIVATE_CODE) NvM_MultiBlockJobFsm_ReadyForMultiBlockServiceState_Do(
  NvM_PartitionIdType partitionId);

/**********************************************************************************************************************
 * NvM_MultiBlockJobFsm_WaitForFinishedMasterMultiBlockServiceState_Entry()
 *********************************************************************************************************************/
/*! \brief           ENTRY action of MultiBlockJobFsm state WaitForFinishedMasterMultiBlockServiceState
 *  \details         -
 *  \param[in]       partitionId Partition ID.
 *  \pre             -
 *  \context         TASK
 *  \reentrant       FALSE
 *  \synchronous     TRUE
 *********************************************************************************************************************/
NVM_LOCAL FUNC(void, NVM_PRIVATE_CODE) NvM_MultiBlockJobFsm_WaitForFinishedMasterMultiBlockServiceState_Entry(
  NvM_PartitionIdType partitionId);

/**********************************************************************************************************************
 * NvM_MultiBlockJobFsm_WaitForFinishedMasterMultiBlockServiceState_Do()
 *********************************************************************************************************************/
/*! \brief           DO action of MultiBlockJobFsm state WaitForFinishedMasterMultiBlockServiceState
 *  \details         -
 *  \param[in]       partitionId Partition ID.
 *  \pre             -
 *  \context         TASK
 *  \reentrant       FALSE
 *  \synchronous     TRUE
 *********************************************************************************************************************/
NVM_LOCAL FUNC(NvM_FsmLib_ProcessingResultType, NVM_PRIVATE_CODE)
NvM_MultiBlockJobFsm_WaitForFinishedMasterMultiBlockServiceState_Do(NvM_PartitionIdType partitionId);

#endif /* (NVM_MULTIPARTITION_USAGE_SCENARIO == STD_ON) */

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
 * Initializing a const structure (NvM_MultiBlockJobFsm_InitialState) can only be done with compile-time constants.
 * Therefore this defines are introduced to minimize code duplication within NvM_MultiBlockJobFsm_InitialState and
 * NvM_MultiBlockJobFsm_IdleState initialization.
 */
#define NVM_MULTIBLOCKJOBFSM_WAITFORFINISHEDMULTIBLOCKSERVICESTATE_ENTRY NvM_MultiBlockJobFsm_WaitForFinishedMultiBlockServiceState_Entry
#define NVM_MULTIBLOCKJOBFSM_WAITFORFINISHEDMULTIBLOCKSERVICESTATE_DO NvM_MultiBlockJobFsm_WaitForFinishedMultiBlockServiceState_Do

/*! STATE: WaitForFinishedMultiBlockService */

/* PRQA S 3218 1 */ /* MD_Fsm_StateDefinitionStaticUsedOnlyInSingleFunction */
NVM_LOCAL CONST(NvM_StateType, NVM_PRIVATE_DATA) NvM_MultiBlockJobFsm_WaitForFinishedMultiBlockServiceState = {
  NVM_MULTIBLOCKJOBFSM_WAITFORFINISHEDMULTIBLOCKSERVICESTATE_ENTRY,
  NVM_MULTIBLOCKJOBFSM_WAITFORFINISHEDMULTIBLOCKSERVICESTATE_DO
};

#if (NVM_MULTIPARTITION_USAGE_SCENARIO == STD_ON)

/*! STATE: ReadyForMultiBlockService */
/* PRQA S 3218 1 */ /* MD_Fsm_StateDefinitionStaticUsedOnlyInSingleFunction */
NVM_LOCAL CONST(NvM_StateType, NVM_PRIVATE_DATA) NvM_MultiBlockJobFsm_ReadyForMultiBlockServiceState = {
  NvM_MultiBlockJobFsm_ReadyForMultiBlockServiceState_Entry,
  NvM_MultiBlockJobFsm_ReadyForMultiBlockServiceState_Do
};

/*! STATE: WaitForFinishedMasterMultiBlockService */
/* PRQA S 3218 1 */ /* MD_Fsm_StateDefinitionStaticUsedOnlyInSingleFunction */
NVM_LOCAL CONST(NvM_StateType, NVM_PRIVATE_DATA) NvM_MultiBlockJobFsm_WaitForFinishedMasterMultiBlockServiceState = {
  NvM_MultiBlockJobFsm_WaitForFinishedMasterMultiBlockServiceState_Entry,
  NvM_MultiBlockJobFsm_WaitForFinishedMasterMultiBlockServiceState_Do
};

#endif /* (NVM_MULTIPARTITION_USAGE_SCENARIO == STD_ON) */

/*! FSM: MultiBlockJobFsm instance with ENTRY action and initial state Idle */
/* PRQA S 3218 1 */ /* MD_Fsm_StateDefinitionStaticUsedOnlyInSingleFunction */
NVM_LOCAL CONST(NvM_FsmType, NVM_PRIVATE_DATA) NvM_MultiBlockJobFsm_InitialState = {
  NvM_MultiBlockJobFsm_Entry,
  {NVM_MULTIBLOCKJOBFSM_WAITFORFINISHEDMULTIBLOCKSERVICESTATE_ENTRY, NVM_MULTIBLOCKJOBFSM_WAITFORFINISHEDMULTIBLOCKSERVICESTATE_DO}
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

/***********************************************************************************************************************
 *  LOCAL FUNCTIONS
 **********************************************************************************************************************/


/**********************************************************************************************************************
 * NvM_MultiBlockJobFsm_Entry()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, NVM_PRIVATE_CODE) NvM_MultiBlockJobFsm_Entry(NvM_PartitionIdType partitionId)
{
  NvM_FsmLib_InstancePtrToConstType multiblockJobFsmLibInstance =
    (NvM_FsmLib_InstancePtrToConstType)NvM_GetAddrMultiBlockServiceFsmLib_Instance(partitionId);

  NvM_StateType targetState = {0};

#if (NVM_MULTIPARTITION_USAGE_SCENARIO == STD_ON)
    targetState = NvM_MultiBlockJobFsm_ReadyForMultiBlockServiceState;
#else
    targetState = NvM_MultiBlockJobFsm_WaitForFinishedMultiBlockServiceState;
#endif /*(NVM_MULTIPARTITION_USAGE_SCENARIO == STD_ON)*/

    NvM_FsmLib_TransitionToState(multiblockJobFsmLibInstance, targetState);

  /*
   * The parameter partitionId is not used within this function in single partition use case.
   * To avoid compiler warnings the following dummy statement is added.
   */
  NVM_DUMMY_STATEMENT(partitionId);                                                                                     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
}

/**********************************************************************************************************************
 * NvM_MultiBlockJobFsm_WaitForFinishedMultiBlockServiceState_Entry()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
NVM_LOCAL FUNC(void, NVM_PRIVATE_CODE) NvM_MultiBlockJobFsm_WaitForFinishedMultiBlockServiceState_Entry(
  NvM_PartitionIdType partitionId)
{
  NvM_MultiBlockJobType jobType = NvM_GetMultiBlockJob(partitionId);
  NvM_MultiBlockJobFsm_ContextPtrType multiBlockJobFsmContext = NvM_GetAddrMultiBlockJobFsm_Context(partitionId);

  switch(jobType)
  {
    case NVM_MULTIBLOCKJOBTYPE_READ_ALL:
      multiBlockJobFsmContext->activeMultiBlockJobType = NVM_MULTIBLOCKJOBTYPE_READ_ALL;
      NvM_ReadAllFsm_ReadAll(partitionId);
      break;
    case NVM_MULTIBLOCKJOBTYPE_WRITE_ALL:
      multiBlockJobFsmContext->activeMultiBlockJobType = NVM_MULTIBLOCKJOBTYPE_WRITE_ALL;
      NvM_WriteAllFsm_WriteAll(partitionId);
      break;
    case NVM_MULTIBLOCKJOBTYPE_VALIDATE_ALL:
      multiBlockJobFsmContext->activeMultiBlockJobType = NVM_MULTIBLOCKJOBTYPE_VALIDATE_ALL;
      NvM_ValidateAllFsm_ValidateAll(partitionId);
      break;
    default: /* COV_NVM_MISRA_BRANCH */
      /*
       * MISRA case. Do nothing.
       * This default case is empty because this function
       * does not process cancel and kill requests.
       */
      break;
  }
}

/**********************************************************************************************************************
 * NvM_MultiBlockJobFsm_WaitForFinishedMultiBlockServiceState_Do()
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
NVM_LOCAL FUNC(NvM_FsmLib_ProcessingResultType, NVM_PRIVATE_CODE) NvM_MultiBlockJobFsm_WaitForFinishedMultiBlockServiceState_Do(
  NvM_PartitionIdType partitionId)
{
  /* ENTRY action of state spawns sub FSM ,
     this function is only entered when processing of it has finished */

  NVM_DUMMY_STATEMENT(partitionId);                                                                                     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  /* Reset active multiblock job type to get rid of accidentally make a transition
  in a FSM (ReadAll/WriteAll), which is already finished processing. */
  NvM_MultiBlockJobFsm_ContextPtrType multiBlockJobFsmContext = NvM_GetAddrMultiBlockJobFsm_Context(partitionId);
  multiBlockJobFsmContext->activeMultiBlockJobType = NVM_MULTIBLOCKJOBTYPE_NONE;

#if (NVM_MULTIPARTITION_USAGE_SCENARIO == STD_ON)
  NvM_FsmLib_InstancePtrToConstType multiblockJobFsmLibInstance =
    (NvM_FsmLib_InstancePtrType)NvM_GetAddrMultiBlockServiceFsmLib_Instance(partitionId);

  NvM_FsmLib_TransitionToState(multiblockJobFsmLibInstance, NvM_MultiBlockJobFsm_WaitForFinishedMasterMultiBlockServiceState);
#else
  NvM_MultiBlockJobType multiBlockJobType = NvM_GetMultiBlockJob(partitionId);
  NvM_FsmLib_InstancePtrType multiblockJobFsmLibInstance =
    (NvM_FsmLib_InstancePtrType)NvM_GetAddrMultiBlockServiceFsmLib_Instance(partitionId);

  NvM_MultiBlockJobInformationType multiBlockJobInfo = NvM_GetMultiBlockJobInformation(NVM_PARTITION_ID_MASTER);

  NvM_ServiceJobResultType serviceJobResult = NvM_FsmLib_GetSubFsmResult(multiblockJobFsmLibInstance);

  multiBlockJobInfo.ErrorStatus =
    NvM_GlobalUtilityLib_ConvertServiceJobResultToNvMRequestResult(serviceJobResult);

  /*
   * MultiBlock callbacks have to be processed before clearing of multiblock job status flag
   * since CancelWriteAll callback processing only is done when WriteAll is active and
   * a cancel is requested.
   */
  NvM_Notification_ProcessMultiBlockNotification(multiBlockJobType, multiBlockJobInfo.ErrorStatus);

  const boolean isWriteAllProcessed =
    NvM_GlobalUtilityLib_IsFlagSet(multiBlockJobInfo.JobStatusFlag, NVM_MULTIBLOCK_FLAG_WRITEALL_ACTIVE);
  const boolean isCancelWriteAllProcessed =
    NvM_GlobalUtilityLib_IsFlagSet(multiBlockJobInfo.JobStatusFlag, NVM_MULTIBLOCK_FLAG_WRITEALL_CANCEL_REQUESTED);

  if (isWriteAllProcessed && isCancelWriteAllProcessed)
  {
    NvM_Notification_ProcessMultiBlockNotification(NVM_MULTIBLOCKJOBTYPE_CANCEL_WRITE_ALL, NVM_REQ_CANCELED);
  }

  /*
   * Clear all multiblock job flags. Only possible since
   * no more than one multiblock job can be requested at a time
   */
  multiBlockJobInfo.JobStatusFlag = 0u;

  NvM_GlobalUtilityLib_EnterCriticalSection();
  {
    NvM_SetMultiBlockJobInformation(multiBlockJobInfo, NVM_PARTITION_ID_MASTER);
  }
  NvM_GlobalUtilityLib_ExitCriticalSection();

  NvM_FsmLib_FinalizeCurrentActiveFsm(multiblockJobFsmLibInstance, serviceJobResult);
#endif /*(NVM_MULTIPARTITION_USAGE_SCENARIO == STD_ON)*/

  return NVM_FSMLIB_PROCESSINGRESULT_CONTINUE;
}

#if (NVM_MULTIPARTITION_USAGE_SCENARIO == STD_ON)

/**********************************************************************************************************************
 * NvM_MultiBlockJobFsm_ReadyForMultiBlockServiceState_Entry()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
NVM_LOCAL FUNC(void, NVM_PRIVATE_CODE) NvM_MultiBlockJobFsm_ReadyForMultiBlockServiceState_Entry(
  NvM_PartitionIdType partitionId)
{
  NvM_SatelliteCom_SetMultiBlockJobStatus(NVM_SATELLITE_MULTIBLOCK_JOB_STATUS_READY, partitionId);
}

/**********************************************************************************************************************
 * NvM_MultiBlockJobFsm_ReadyForMultiBlockServiceState_Do()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
NVM_LOCAL FUNC(NvM_FsmLib_ProcessingResultType, NVM_PRIVATE_CODE) NvM_MultiBlockJobFsm_ReadyForMultiBlockServiceState_Do(
  NvM_PartitionIdType partitionId)
{
  NvM_FsmLib_InstancePtrToConstType multiblockJobFsmLibInstance =
    (NvM_FsmLib_InstancePtrType)NvM_GetAddrMultiBlockServiceFsmLib_Instance(partitionId);

  NvM_FsmLib_ProcessingResultType retval = NVM_FSMLIB_PROCESSINGRESULT_STOP;

  if (NvM_SatelliteCom_GetMultiBlockJobStatus(partitionId) == NVM_MASTERSATELLITE_MULTIBLOCK_JOB_REQUEST_PROCESSING)
  {
    NvM_FsmLib_TransitionToState(multiblockJobFsmLibInstance, NvM_MultiBlockJobFsm_WaitForFinishedMultiBlockServiceState);
    retval = NVM_FSMLIB_PROCESSINGRESULT_CONTINUE;
  }

  return retval;
}

/**********************************************************************************************************************
 * NvM_MultiBlockJobFsm_WaitForFinishedMasterMultiBlockServiceState_Entry()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
NVM_LOCAL FUNC(void, NVM_PRIVATE_CODE) NvM_MultiBlockJobFsm_WaitForFinishedMasterMultiBlockServiceState_Entry(
  NvM_PartitionIdType partitionId)
{
  NvM_FsmLib_InstancePtrToConstType multiblockJobFsmLibInstance =
    (NvM_FsmLib_InstancePtrType)NvM_GetAddrMultiBlockServiceFsmLib_Instance(partitionId);

  NvM_ServiceJobResultType serviceJobResult = NvM_FsmLib_GetSubFsmResult(multiblockJobFsmLibInstance);

  NvM_SatelliteCom_SetMultiBlockJobStatus(
    NvM_GlobalUtilityLib_ConvertServiceJobResultToSatelliteMultiBlockJobStatus(serviceJobResult),
    partitionId);
}

/**********************************************************************************************************************
 * NvM_MultiBlockJobFsm_WaitForFinishedMasterMultiBlockServiceState_Do()
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
NVM_LOCAL FUNC(NvM_FsmLib_ProcessingResultType, NVM_PRIVATE_CODE)
NvM_MultiBlockJobFsm_WaitForFinishedMasterMultiBlockServiceState_Do(
  NvM_PartitionIdType partitionId)
{
  NvM_FsmLib_InstancePtrType multiblockJobFsmLibInstance =
    (NvM_FsmLib_InstancePtrType)NvM_GetAddrMultiBlockServiceFsmLib_Instance(partitionId);

  NvM_FsmLib_ProcessingResultType retval = NVM_FSMLIB_PROCESSINGRESULT_STOP;

  if (NvM_SatelliteCom_GetMultiBlockJobStatus(partitionId) == NVM_MASTERSATELLITE_MULTIBLOCK_JOB_REQUEST_NONE)
  {
    NvM_SatelliteCom_SetMultiBlockJobStatus(NVM_SATELLITE_MULTIBLOCK_JOB_STATUS_NONE, partitionId);

    NvM_ServiceJobResultType serviceJobResult = NvM_FsmLib_GetSubFsmResult(multiblockJobFsmLibInstance);

    NvM_FsmLib_FinalizeCurrentActiveFsm(multiblockJobFsmLibInstance, serviceJobResult);
    retval = NVM_FSMLIB_PROCESSINGRESULT_CONTINUE;
  }

  return retval;
}

#endif /* (NVM_MULTIPARTITION_USAGE_SCENARIO == STD_ON) */

/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

/**********************************************************************************************************************
 * NvM_MultiBlockJobFsm_Spawn()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, NVM_PRIVATE_CODE) NvM_MultiBlockJobFsm_Spawn(NvM_PartitionIdType partitionId)                                /* PRQA S 3206 */ /* MD_NvM_CslMacroNotUsingPartitionId */
{
  NvM_FsmLib_InstancePtrType multiblockJobFsmLibInstance =
    (NvM_FsmLib_InstancePtrType)NvM_GetAddrMultiBlockServiceFsmLib_Instance(partitionId);

  NvM_MultiBlockJobFsm_ContextPtrType multiBlockJobFsmContext = NvM_GetAddrMultiBlockJobFsm_Context(partitionId);
  multiBlockJobFsmContext->activeMultiBlockJobType = NVM_MULTIBLOCKJOBTYPE_NONE;

  /* COM-4978: Wait for CSL feature to store init value of generated partition data */
  NvM_FsmPtrType fsmInstance = (NvM_FsmPtrType)NvM_GetAddrMultiBlockJobFsm_Instance(partitionId);
  *fsmInstance = NvM_MultiBlockJobFsm_InitialState;

  (void)NvM_FsmLib_SpawnFsm(multiblockJobFsmLibInstance, *fsmInstance);

  /*
   * The parameter partitionId is not used within this function in single partition use case.
   * To avoid compiler warnings the following dummy statement is added.
   */
  NVM_DUMMY_STATEMENT(partitionId);                                                                                     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
}

#if (NVM_JOB_PRIORITIZATION == STD_ON)
/**********************************************************************************************************************
 * NvM_MultiBlockJobFsm_NotifyImmediateJobInterrupt()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, NVM_PRIVATE_CODE) NvM_MultiBlockJobFsm_NotifyImmediateJobInterrupt(const NvM_PartitionIdType partitionId)
{
  NvM_MultiBlockJobFsm_ContextPtrType multiBlockJobFsmContext = NvM_GetAddrMultiBlockJobFsm_Context(partitionId);

  switch (multiBlockJobFsmContext->activeMultiBlockJobType)
  {
    case NVM_MULTIBLOCKJOBTYPE_READ_ALL:
      NvM_ReadAllFsm_NotifyImmediateJobInterrupt(partitionId);
      break;
    case NVM_MULTIBLOCKJOBTYPE_WRITE_ALL:
      NvM_WriteAllFsm_NotifyImmediateJobInterrupt(partitionId);
      break;
    default: /* COV_NVM_MISRA_BRANCH */
      /*
       * MISRA case. Do nothing.
       */
      break;
  }
}
#endif /* NVM_JOB_PRIORITIZATION == STD_ON */

#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  END OF FILE: NvM_MultiBlockJobFsm.c
 **********************************************************************************************************************/
