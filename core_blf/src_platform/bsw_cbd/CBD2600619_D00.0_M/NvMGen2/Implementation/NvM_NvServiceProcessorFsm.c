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
/*!        \file  NvM_NvServiceProcessorFsm.c
 *        \brief  NvM_NvServiceProcessorFsm source file
 *      \details  Implementation of the NvM_NvServiceProcessorFsm unit.
 *         \unit  NvM_NvServiceProcessorFsm
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#define NVM_NVSERVICEPROCESSORFSM_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "NvM_NvServiceProcessorFsm.h"

#if (NVM_MULTIPARTITION_USAGE_SCENARIO == STD_ON) /* COV_MSR_UT_OPTIONAL_UNIT */

#include "NvM_FsmLib.h"
#include "NvM_MasterCom.h"
#include "NvM_NvJobDispatcherFsm.h"
#include "NvM_GlobalUtilityLib.h"
#include "MemIf.h"


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
 * NvM_NvServiceProcessorFsm_Entry()
 *********************************************************************************************************************/
/*!  \brief          ENTRY action of NvServiceProcessorFsm.
 *   \details        -
 *   \param[in]      partitionId Partition ID.
 *   \pre            -
 *   \context        TASK
 *   \reentrant      FALSE
 *   \synchronous    TRUE
 *   \spec
 *      requires partitionId == NVM_PARTITION_ID_MASTER;
 *   \endspec
 *********************************************************************************************************************/
FUNC(void, NVM_PRIVATE_CODE) NvM_NvServiceProcessorFsm_Entry(NvM_PartitionIdType partitionId);

/**********************************************************************************************************************
 * NvM_NvServiceProcessorFsm_ScanSingleBlockJobsState_Do()
 *********************************************************************************************************************/
/*! \brief           DO action of state ScanSingleBlockJobs
 *  \details         -
 *  \param[in]       partitionId Partition ID.
 *  \pre             -
 *  \context         TASK
 *  \reentrant       FALSE
 *  \synchronous     TRUE
 *  \return          Based on state evaluation:
 *                    - STOP       if no further processing is required
 *                    - CONTINUE   if further processing shall be executed
 *   \spec
 *      requires partitionId == NVM_PARTITION_ID_MASTER;
 *  \endspec
 *********************************************************************************************************************/
FUNC(NvM_FsmLib_ProcessingResultType, NVM_PRIVATE_CODE) NvM_NvServiceProcessorFsm_ScanSingleBlockJobsState_Do(
  NvM_PartitionIdType partitionId);

/**********************************************************************************************************************
 * NvM_NvServiceProcessorFsm_ProcessNormalPrioJobState_Entry()
 *********************************************************************************************************************/
/*! \brief           ENTRY action of state ProcessNormalPrioJob
 *  \details         -
 *  \param[in]       partitionId Partition ID.
 *  \pre             -
 *  \context         TASK
 *  \reentrant       FALSE
 *  \synchronous     TRUE
 *  \spec
 *      requires partitionId == NVM_PARTITION_ID_MASTER;
 *  \endspec
 *********************************************************************************************************************/
FUNC(void, NVM_PRIVATE_CODE) NvM_NvServiceProcessorFsm_ProcessNormalPrioJobState_Entry(NvM_PartitionIdType partitionId);

/**********************************************************************************************************************
 * NvM_NvServiceProcessorFsm_ProcessNormalPrioJobState_Do()
 *********************************************************************************************************************/
/*! \brief           DO action of state ProcessNormalPrioJob
 *  \details         -
 *  \param[in]       partitionId Partition ID.
 *  \pre             -
 *  \context         TASK
 *  \reentrant       FALSE
 *  \synchronous     TRUE
 *  \return          Based on state evaluation:
 *                    - STOP       if no further processing is required
 *                    - CONTINUE   if further processing shall be executed
 *  \spec
 *      requires partitionId == NVM_PARTITION_ID_MASTER;
 *  \endspec
 *********************************************************************************************************************/
FUNC(NvM_FsmLib_ProcessingResultType, NVM_PRIVATE_CODE) NvM_NvServiceProcessorFsm_ProcessNormalPrioJobState_Do(
  NvM_PartitionIdType partitionId);

#if (NVM_JOB_PRIORITIZATION == STD_ON)

/**********************************************************************************************************************
 * NvM_NvServiceProcessorFsm_ImmediateJobInterruptSetupState_Do()
 *********************************************************************************************************************/
/*! \brief           DO action of state ImmediateJobInterruptSetup
 *  \details         -
 *  \param[in]       partitionId Partition ID.
 *  \pre             -
 *  \context         TASK
 *  \reentrant       FALSE
 *  \synchronous     TRUE
 *  \return          Based on state evaluation:
 *                    - STOP       if no further processing is required
 *                    - CONTINUE   if further processing shall be executed
 *  \spec
 *      requires partitionId == NVM_PARTITION_ID_MASTER;
 *  \endspec
 *********************************************************************************************************************/
FUNC(NvM_FsmLib_ProcessingResultType, NVM_PRIVATE_CODE) NvM_NvServiceProcessorFsm_ImmediateJobInterruptSetupState_Do(
  NvM_PartitionIdType partitionId);

/**********************************************************************************************************************
 * NvM_NvServiceProcessorFsm_CancelMemIfState_Do()
 *********************************************************************************************************************/
/*! \brief           DO action of state CancelMemIf
 *  \details         -
 *  \param[in]       partitionId Partition ID.
 *  \pre             -
 *  \context         TASK
 *  \reentrant       FALSE
 *  \synchronous     TRUE
 *  \return          Based on state evaluation:
 *                    - STOP       if no further processing is required
 *                    - CONTINUE   if further processing shall be executed
 *  \spec
 *      requires partitionId == NVM_PARTITION_ID_MASTER;
 *  \endspec
 *********************************************************************************************************************/
FUNC(NvM_FsmLib_ProcessingResultType, NVM_PRIVATE_CODE) NvM_NvServiceProcessorFsm_CancelMemIfState_Do(
  NvM_PartitionIdType partitionId);

/**********************************************************************************************************************
 * NvM_NvServiceProcessorFsm_WaitForImmediateJobReadyForNvProcessingState_Do()
 *********************************************************************************************************************/
/*! \brief           DO action of state WaitForImmediateJobReadyForNvProcessing
 *  \details         -
 *  \param[in]       partitionId Partition ID.
 *  \pre             -
 *  \context         TASK
 *  \reentrant       FALSE
 *  \synchronous     TRUE
 *  \return          Based on state evaluation:
 *                    - STOP       if no further processing is required
 *                    - CONTINUE   if further processing shall be executed
 *  \spec
 *      requires partitionId == NVM_PARTITION_ID_MASTER;
 *  \endspec
 *********************************************************************************************************************/
FUNC(NvM_FsmLib_ProcessingResultType, NVM_PRIVATE_CODE)
  NvM_NvServiceProcessorFsm_WaitForImmediateJobReadyForNvProcessingState_Do(NvM_PartitionIdType partitionId);

/**********************************************************************************************************************
 * NvM_NvServiceProcessorFsm_ProcessImmediateJobState_Entry()
 *********************************************************************************************************************/
/*! \brief           ENTRY action of state ProcessImmediateJob
 *  \details         -
 *  \param[in]       partitionId Partition ID.
 *  \pre             -
 *  \context         TASK
 *  \reentrant       FALSE
 *  \synchronous     TRUE
 *  \return          Based on state evaluation:
 *                    - STOP       if no further processing is required
 *                    - CONTINUE   if further processing shall be executed
 *  \spec
 *      requires partitionId == NVM_PARTITION_ID_MASTER;
 *  \endspec
 *********************************************************************************************************************/
FUNC(void, NVM_PRIVATE_CODE) NvM_NvServiceProcessorFsm_ProcessImmediateJobState_Entry(NvM_PartitionIdType partitionId);

/**********************************************************************************************************************
 * NvM_NvServiceProcessorFsm_ProcessImmediateJobState_Do()
 *********************************************************************************************************************/
/*! \brief           DO action of state ProcessImmediateJob
 *  \details         -
 *  \param[in]       partitionId Partition ID.
 *  \pre             -
 *  \context         TASK
 *  \reentrant       FALSE
 *  \synchronous     TRUE
 *  \return          Based on state evaluation:
 *                    - STOP       if no further processing is required
 *                    - CONTINUE   if further processing shall be executed
 *  \spec
 *      requires partitionId == NVM_PARTITION_ID_MASTER;
 *  \endspec
 *********************************************************************************************************************/
FUNC(NvM_FsmLib_ProcessingResultType, NVM_PRIVATE_CODE) NvM_NvServiceProcessorFsm_ProcessImmediateJobState_Do(
  NvM_PartitionIdType partitionId);

#endif /* (NVM_JOB_PRIORITIZATION == STD_ON) */

#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**! Contains job information of selected job from COM port */
NVM_LOCAL VAR(NvM_SingleBlockJobContextType, NVM_PRIVATE_DATA) NvM_NvServiceProcessorFsm_AcceptedJobInfo;

#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define NVM_START_SEC_CONST_UNSPECIFIED
#include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*
 * Initializing a const structure (NvM_NvServiceProcessorFsm) can only be done with compile-time constants.
 * Therefore this defines are introduced to minimize code duplication within NvM_NvServiceProcessorFsm and
 * NvM_NvServiceProcessorFsm_ScanSingleBlockJobsState initialization.
 */
#define NVM_NVSERVICEPROCESSORFSM_SCANSINGLEBLOCKJOBSSTATE_ENTRY NvM_FsmLib_EntryNoOp
#define NVM_NVSERVICEPROCESSORFSM_SCANSINGLEBLOCKJOBSSTATE_DO NvM_NvServiceProcessorFsm_ScanSingleBlockJobsState_Do

/*! STATE: ScanSingleBlockJobs */

/* PRQA S 3218 1 */ /* MD_Fsm_StateDefinitionStaticUsedOnlyInSingleFunction */
NVM_LOCAL CONST(NvM_StateType, NVM_PRIVATE_DATA) NvM_NvServiceProcessorFsm_ScanSingleBlockJobsState = {
  NvM_FsmLib_EntryNoOp,
  NvM_NvServiceProcessorFsm_ScanSingleBlockJobsState_Do
};

/*! STATE: ProcessNormalPrioJob */

/* PRQA S 3218 1 */ /* MD_Fsm_StateDefinitionStaticUsedOnlyInSingleFunction */
NVM_LOCAL CONST(NvM_StateType, NVM_PRIVATE_DATA) NvM_NvServiceProcessorFsm_ProcessNormalPrioJobState = {
  NvM_NvServiceProcessorFsm_ProcessNormalPrioJobState_Entry,
  NvM_NvServiceProcessorFsm_ProcessNormalPrioJobState_Do
};

#if(NVM_JOB_PRIORITIZATION == STD_ON)

/*! STATE: ImmediateJobInterruptSetup */

/* PRQA S 3218 1 */ /* MD_Fsm_StateDefinitionStaticUsedOnlyInSingleFunction */
NVM_LOCAL CONST(NvM_StateType, NVM_PRIVATE_DATA) NvM_NvServiceProcessorFsm_ImmediateJobInterruptSetupState = {
  NvM_FsmLib_EntryNoOp,
  NvM_NvServiceProcessorFsm_ImmediateJobInterruptSetupState_Do
};

/*! STATE: CancelMemIf */

/* PRQA S 3218 1 */ /* MD_Fsm_StateDefinitionStaticUsedOnlyInSingleFunction */
NVM_LOCAL CONST(NvM_StateType, NVM_PRIVATE_DATA) NvM_NvServiceProcessorFsm_CancelMemIfState = {
  NvM_FsmLib_EntryNoOp,
  NvM_NvServiceProcessorFsm_CancelMemIfState_Do
};

/*! STATE: WaitForImmediateJobReadyForNvProcessing */

/* PRQA S 3218 1 */ /* MD_Fsm_StateDefinitionStaticUsedOnlyInSingleFunction */
NVM_LOCAL CONST(NvM_StateType, NVM_PRIVATE_DATA)
  NvM_NvServiceProcessorFsm_WaitForImmediateJobReadyForNvProcessingState = {
   NvM_FsmLib_EntryNoOp,
   NvM_NvServiceProcessorFsm_WaitForImmediateJobReadyForNvProcessingState_Do
};

/*! STATE: ProcessImmediateJob */

/* PRQA S 3218 1 */ /* MD_Fsm_StateDefinitionStaticUsedOnlyInSingleFunction */
NVM_LOCAL CONST(NvM_StateType, NVM_PRIVATE_DATA) NvM_NvServiceProcessorFsm_ProcessImmediateJobState = {
  NvM_NvServiceProcessorFsm_ProcessImmediateJobState_Entry,
  NvM_NvServiceProcessorFsm_ProcessImmediateJobState_Do
};

#endif /* (NVM_JOB_PRIORITIZATION == STD_ON) */

/*! FSM: NvServiceProcessorFsm instance with ENTRY action and initial state Idle */
/* PRQA S 3218 1 */ /* MD_Fsm_StateDefinitionStaticUsedOnlyInSingleFunction */
NVM_LOCAL CONST(NvM_FsmType, NVM_PRIVATE_DATA) NvM_NvServiceProcessorFsm = {
  NvM_NvServiceProcessorFsm_Entry,
  {NVM_NVSERVICEPROCESSORFSM_SCANSINGLEBLOCKJOBSSTATE_ENTRY, NVM_NVSERVICEPROCESSORFSM_SCANSINGLEBLOCKJOBSSTATE_DO}
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

#if (NVM_JOB_PRIORITIZATION == STD_ON)

/**********************************************************************************************************************
 * NvM_NvServiceProcessorFsm_ResetNvLayerProcessing()
 *********************************************************************************************************************/
/*! \brief           Resets the Nv Layer processing.
 *  \details         Includes NvLayer Stack reset, master satellite port reset and transition to MemIf Cancel.
 *  \param[in]       currentProcessingPartitionId    Partition ID of current processing partition
 *  \param[in]       acceptedJobPartitionId          Partition ID of accepted job
 *  \pre             -
 *  \context         TASK
 *  \reentrant       FALSE
 *  \synchronous     TRUE
 *  \spec
 *      requires currentProcessingPartitionId == NVM_PARTITION_ID_MASTER;
 *  \endspec
 *********************************************************************************************************************/
NVM_LOCAL_INLINE FUNC(void, NVM_PRIVATE_CODE) NvM_NvServiceProcessorFsm_ResetNvLayerProcessing(
  const NvM_PartitionIdType currentProcessingPartitionId,
  const NvM_PartitionIdType acceptedJobPartitionId);

#endif /* (NVM_JOB_PRIORITIZATION == STD_ON) */

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * NvM_NvServiceProcessorFsm_Entry()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, NVM_PRIVATE_CODE) NvM_NvServiceProcessorFsm_Entry(NvM_PartitionIdType partitionId)
{
  NvM_FsmLib_InstancePtrToConstType nvServiceProcessorFsmLibInstance =
    (NvM_FsmLib_InstancePtrType)NvM_GetAddrNvServiceProcessorFsmLib_Instance(partitionId);

  NvM_FsmLib_TransitionToState(nvServiceProcessorFsmLibInstance, NvM_NvServiceProcessorFsm_ScanSingleBlockJobsState);
}

/*
 * State: ScanSingleBlockJobsState
 */

/**********************************************************************************************************************
 * NvM_NvServiceProcessorFsm_ScanSingleBlockJobsState_Do()
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
/* VCA Next Line SPC-24 : VCA_NVM_BlockDescriptorLookupTableIdAcceptedJobInfo */
FUNC(NvM_FsmLib_ProcessingResultType, NVM_PRIVATE_CODE) NvM_NvServiceProcessorFsm_ScanSingleBlockJobsState_Do(
  NvM_PartitionIdType partitionId)
{
  NvM_FsmLib_ProcessingResultType result = NVM_FSMLIB_PROCESSINGRESULT_STOP;

  NvM_FsmLib_InstancePtrToConstType nvServiceProcessorFsmLibInstance =
    (NvM_FsmLib_InstancePtrToConstType)NvM_GetAddrNvServiceProcessorFsmLib_Instance(partitionId);

  NvM_MasterCom_CleanupAcknowledgedSingleBlockJobSatellitePorts();

 #if (NVM_JOB_PRIORITIZATION == STD_ON)
  if (NvM_MasterCom_IsAnyImmediateJobRequested() == TRUE)
  {
    NvM_FsmLib_TransitionToState(nvServiceProcessorFsmLibInstance,
      NvM_NvServiceProcessorFsm_WaitForImmediateJobReadyForNvProcessingState);

    result = NVM_FSMLIB_PROCESSINGRESULT_CONTINUE;
  }
  else
#endif /* (NVM_JOB_PRIORITIZATION == STD_ON) */
  {
    if (NvM_MasterCom_AcceptSingleBlockJobRequest(&NvM_NvServiceProcessorFsm_AcceptedJobInfo) == E_OK)
    {
      NvM_FsmLib_TransitionToState(nvServiceProcessorFsmLibInstance,
        NvM_NvServiceProcessorFsm_ProcessNormalPrioJobState);

      result = NVM_FSMLIB_PROCESSINGRESULT_CONTINUE;
    }
  }

  return result;
}

/*
 * State: ProcessNormalPrioJob
 */

/**********************************************************************************************************************
 * NvM_NvServiceProcessorFsm_ProcessNormalPrioJobState_Entry()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, NVM_PRIVATE_CODE) NvM_NvServiceProcessorFsm_ProcessNormalPrioJobState_Entry(NvM_PartitionIdType partitionId)
{
  NvM_NvJobDispatcherFsm_Execute(&NvM_NvServiceProcessorFsm_AcceptedJobInfo, partitionId);
}

/**********************************************************************************************************************
 * NvM_NvServiceProcessorFsm_ProcessNormalPrioJobState_Do()
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
FUNC(NvM_FsmLib_ProcessingResultType, NVM_PRIVATE_CODE) NvM_NvServiceProcessorFsm_ProcessNormalPrioJobState_Do(         /* VCA_NVM_MasterSatelliterPortPtrInMasterContext */
  NvM_PartitionIdType partitionId)
{
  NvM_FsmLib_ProcessingResultType retVal = NVM_FSMLIB_PROCESSINGRESULT_STOP;

  NvM_FsmLib_InstancePtrToConstType nvFsmLibInstance =
    (NvM_FsmLib_InstancePtrType)NvM_GetAddrNvServiceFsmLib_Instance(partitionId);

  NvM_FsmLib_InstancePtrToConstType nvServiceProcessorFsmLibInstance =
    (NvM_FsmLib_InstancePtrType)NvM_GetAddrNvServiceProcessorFsmLib_Instance(partitionId);

#if (NVM_JOB_PRIORITIZATION == STD_ON)
  if (NvM_MasterCom_IsAnyImmediateJobRequested() == TRUE)
  {
    NvM_FsmLib_TransitionToState(nvServiceProcessorFsmLibInstance,
      NvM_NvServiceProcessorFsm_ImmediateJobInterruptSetupState);

    retVal = NVM_FSMLIB_PROCESSINGRESULT_CONTINUE;
  }
  else
#endif /* (NVM_JOB_PRIORITIZATION == STD_ON) */
  {
    NvM_FsmLib_ProcessCurrentActiveFsm(nvFsmLibInstance);

    if (NvM_FsmLib_IsProcessingStackEmpty(nvFsmLibInstance) == TRUE)
    {
      const NvM_ServiceJobResultType result = NvM_FsmLib_GetSubFsmResult(nvFsmLibInstance);
      NvM_MasterCom_FinalizeActiveSingleBlockJobRequest(result);

      NvM_FsmLib_TransitionToState(nvServiceProcessorFsmLibInstance,                                                    /* VCA_NVM_NvServiceProcessorFsmLibInstance */
        NvM_NvServiceProcessorFsm_ScanSingleBlockJobsState);

      retVal = NVM_FSMLIB_PROCESSINGRESULT_CONTINUE;
    }
  }

  return retVal;
}

#if (NVM_JOB_PRIORITIZATION == STD_ON)

/*
 * State: ImmediateJobInterruptSetup
 */

/**********************************************************************************************************************
 * NvM_NvServiceProcessorFsm_ImmediateJobInterruptSetupState_Do()
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
FUNC(NvM_FsmLib_ProcessingResultType, NVM_PRIVATE_CODE) NvM_NvServiceProcessorFsm_ImmediateJobInterruptSetupState_Do(
  NvM_PartitionIdType partitionId)
{
  NvM_BlockDescriptorPtrType acceptedJobBlockDescriptor = NvM_GetAddrBlockDescriptor(
    NvM_NvServiceProcessorFsm_AcceptedJobInfo.BlockDescriptorLookupTableId);

  if (NvM_MasterCom_IsImmediateJobRequestedForPartition(acceptedJobBlockDescriptor->PartitionId) == TRUE)
  {
    NvM_NvServiceProcessorFsm_ResetNvLayerProcessing(partitionId, acceptedJobBlockDescriptor->PartitionId);
  }
  else
  {
    NvM_FsmLib_InstancePtrToConstType nvFsmLibInstance =
      (NvM_FsmLib_InstancePtrType)NvM_GetAddrNvServiceFsmLib_Instance(partitionId);

    NvM_FsmLib_InstancePtrToConstType nvServiceProcessorFsmLibInstance =
      (NvM_FsmLib_InstancePtrType)NvM_GetAddrNvServiceProcessorFsmLib_Instance(partitionId);

    /* Process one last time to check if MemIf already has finished processing, so no progress for the job is lost */
    NvM_FsmLib_ProcessCurrentActiveFsm(nvFsmLibInstance);

    /* Check if already processing job has already finished for partition which has no requested immediate job.
     * If processing stack is empty of NvFsmLib instance, MemIf processing has already finished for the job
     * and the master can finalize this job request.
     */
    if (NvM_FsmLib_IsProcessingStackEmpty(nvFsmLibInstance) == TRUE)
    {
      const NvM_ServiceJobResultType result = NvM_FsmLib_GetSubFsmResult(nvFsmLibInstance);
      NvM_MasterCom_FinalizeActiveSingleBlockJobRequest(result);

      NvM_FsmLib_TransitionToState(nvServiceProcessorFsmLibInstance,                                                    /* VCA_NVM_NvServiceProcessorFsmLibInstance */
        NvM_NvServiceProcessorFsm_WaitForImmediateJobReadyForNvProcessingState);
    }
    else
    {
      NvM_NvServiceProcessorFsm_ResetNvLayerProcessing(partitionId, acceptedJobBlockDescriptor->PartitionId);
    }
  }

  return NVM_FSMLIB_PROCESSINGRESULT_CONTINUE;
}

/*
 * State: CancelMemIf
 */

/**********************************************************************************************************************
 * NvM_NvServiceProcessorFsm_CancelMemIfState_Do()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(NvM_FsmLib_ProcessingResultType, NVM_PRIVATE_CODE) NvM_NvServiceProcessorFsm_CancelMemIfState_Do(
  NvM_PartitionIdType partitionId)
{
  NvM_FsmLib_InstancePtrToConstType nvServiceProcessorFsmLibInstance =
    (NvM_FsmLib_InstancePtrType)NvM_GetAddrNvServiceProcessorFsmLib_Instance(partitionId);

  NvM_BlockDescriptorPtrType acceptedJobBlockDescriptor = NvM_GetAddrBlockDescriptor(
    NvM_NvServiceProcessorFsm_AcceptedJobInfo.BlockDescriptorLookupTableId);

  if (MemIf_GetStatus((uint8)acceptedJobBlockDescriptor->MemIfDeviceIndex) == MEMIF_BUSY)
  {
    MemIf_Cancel((uint8)acceptedJobBlockDescriptor->MemIfDeviceIndex);
  }

  NvM_FsmLib_TransitionToState(nvServiceProcessorFsmLibInstance,
    NvM_NvServiceProcessorFsm_WaitForImmediateJobReadyForNvProcessingState);

  return NVM_FSMLIB_PROCESSINGRESULT_CONTINUE;
}

/*
 * State: WaitForImmediateJobReadyForNvProcessing
 */

/**********************************************************************************************************************
 * NvM_NvServiceProcessorFsm_WaitForImmediateJobReadyForNvProcessingState_Do()
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
/* VCA Next Line SPC-24 : VCA_NVM_BlockDescriptorLookupTableIdAcceptedJobInfo */
  NvM_NvServiceProcessorFsm_WaitForImmediateJobReadyForNvProcessingState_Do(NvM_PartitionIdType partitionId)
{
  NvM_FsmLib_ProcessingResultType retVal = NVM_FSMLIB_PROCESSINGRESULT_STOP;

  NvM_FsmLib_InstancePtrToConstType nvServiceProcessorFsmLibInstance =
    (NvM_FsmLib_InstancePtrType)NvM_GetAddrNvServiceProcessorFsmLib_Instance(partitionId);

  if (NvM_MasterCom_IsAnyImmediateJobReadyForNvProcessing() == TRUE)
  {
    if (NvM_MasterCom_AcceptSingleBlockJobRequest(&NvM_NvServiceProcessorFsm_AcceptedJobInfo) == E_OK)
    {
      NvM_FsmLib_TransitionToState(nvServiceProcessorFsmLibInstance,
        NvM_NvServiceProcessorFsm_ProcessImmediateJobState);

      retVal = NVM_FSMLIB_PROCESSINGRESULT_CONTINUE;
    }
  }

  return retVal;
}

/*
 * State: ProcessImmediateJob
 */

/**********************************************************************************************************************
 * NvM_NvServiceProcessorFsm_ProcessImmediateJobState_Entry()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, NVM_PRIVATE_CODE) NvM_NvServiceProcessorFsm_ProcessImmediateJobState_Entry(NvM_PartitionIdType partitionId)
{
  /* Forward accepted job information to NvJobDispatcher for further processing */
  NvM_NvJobDispatcherFsm_Execute(&NvM_NvServiceProcessorFsm_AcceptedJobInfo, partitionId);
}

/**********************************************************************************************************************
 * NvM_NvServiceProcessorFsm_ProcessImmediateJobState_Do()
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
 */
FUNC(NvM_FsmLib_ProcessingResultType, NVM_PRIVATE_CODE) NvM_NvServiceProcessorFsm_ProcessImmediateJobState_Do(
  NvM_PartitionIdType partitionId)
{
  NvM_FsmLib_ProcessingResultType retVal = NVM_FSMLIB_PROCESSINGRESULT_STOP;

  NvM_FsmLib_InstancePtrToConstType nvFsmLibInstance =
    (NvM_FsmLib_InstancePtrType)NvM_GetAddrNvServiceFsmLib_Instance(partitionId);

  NvM_FsmLib_InstancePtrToConstType nvServiceProcessorFsmLibInstance =
    (NvM_FsmLib_InstancePtrType)NvM_GetAddrNvServiceProcessorFsmLib_Instance(partitionId);

  /* Process NvService layer */
  NvM_FsmLib_ProcessCurrentActiveFsm(nvFsmLibInstance);

  if (NvM_FsmLib_IsProcessingStackEmpty(nvFsmLibInstance) == TRUE)
  {
    const NvM_ServiceJobResultType result = NvM_FsmLib_GetSubFsmResult(nvFsmLibInstance);
    NvM_MasterCom_FinalizeActiveSingleBlockJobRequest(result);

    NvM_FsmLib_TransitionToState(nvServiceProcessorFsmLibInstance,                                                      /* VCA_NVM_NvServiceProcessorFsmLibInstance */
      NvM_NvServiceProcessorFsm_ScanSingleBlockJobsState);

    retVal = NVM_FSMLIB_PROCESSINGRESULT_CONTINUE;
  }

  return retVal;
}

/**********************************************************************************************************************
 * NvM_NvServiceProcessorFsm_ResetNvLayerProcessing()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
NVM_LOCAL_INLINE FUNC(void, NVM_PRIVATE_CODE) NvM_NvServiceProcessorFsm_ResetNvLayerProcessing(
  const NvM_PartitionIdType currentProcessingPartitionId,
  const NvM_PartitionIdType acceptedJobPartitionId)
{
  NvM_FsmLib_InstancePtrType nvFsmLibInstance =
    (NvM_FsmLib_InstancePtrType)NvM_GetAddrNvServiceFsmLib_Instance(currentProcessingPartitionId);

  NvM_FsmLib_InstancePtrToConstType nvServiceProcessorFsmLibInstance =
    (NvM_FsmLib_InstancePtrType)NvM_GetAddrNvServiceProcessorFsmLib_Instance(currentProcessingPartitionId);

  /* Reset NvLayer FSM stack */
  NvM_FsmLib_ClearProcessingStack(nvFsmLibInstance);

  /* Reset MasterSatellite COM port of requested partition */
  NvM_MasterCom_ResetMasterSatellitePort(acceptedJobPartitionId);

  /* Make state transition to CancelMemIfState */
  NvM_FsmLib_TransitionToState(nvServiceProcessorFsmLibInstance,
    NvM_NvServiceProcessorFsm_CancelMemIfState);
}

#endif /* (NVM_JOB_PRIORITIZATION == STD_ON) */

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * NvM_NvServiceProcessorFsm_Spawn()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, NVM_PRIVATE_CODE) NvM_NvServiceProcessorFsm_Spawn(NvM_PartitionIdType partitionId)
{
  NvM_FsmLib_InstancePtrType nvServiceProcessorFsmLibInstance =
    (NvM_FsmLib_InstancePtrType)NvM_GetAddrNvServiceProcessorFsmLib_Instance(partitionId);

  (void)NvM_FsmLib_SpawnFsm(nvServiceProcessorFsmLibInstance, NvM_NvServiceProcessorFsm);
}

#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* NVM_MULTIPARTITION_USAGE_SCENARIO */

/***********************************************************************************************************************
 *  VCA JUSTIFICATIONS
 **********************************************************************************************************************/
/* VCA_JUSTIFICATION_BEGIN

\ID VCA_NVM_BlockDescriptorLookupTableIdAcceptedJobInfo
  \DESCRIPTION The BlockDescriptorLookupTableId is used in several places to fetch the Block Descriptor from the Block Descriptor Table.
               The BlockDescriptorLookupTableId is assigned within the NvM_MasterCom_AcceptSingleBlockJobRequest function.
               The NvM_MasterCom_AcceptSingleBlockJobRequest function only assigns valid BlockDescriptorLookupTableId values
               that are in the range of the Block Descriptor Table size.
               This design inherently prevents assigning a blockDescriptorLookupTableId that is out of range.

  \COUNTERMEASURE \N A code review ensures that the BlockDescriptorLookupTableId is always in range when used.

\ID VCA_NVM_MasterSatelliterPortPtrInMasterContext
  \DESCRIPTION The master satellite port pointer is set within the NvM_MasterCom_AcceptSingleBlockJobRequest function
               only if a job is accepted. Therefore the master satellite port pointer has a defined value after a job was accepted
               and all strong invariants defined within the NvM_InternalTypes.h file are met.

  \COUNTERMEASURE \N A code review ensures that NvM_NvServiceProcessorFsm_WaitForFinishedSingleBlockJobState_Do is always called after accepting.

\ID VCA_NVM_NvServiceProcessorFsmLibInstance
  \DESCRIPTION The NvServiceProcessorFsmLib instance is fetched from the generated code. It is only available for the master partition,
               but which is being enforced by a formal VCA specification. Additionally, NvServiceProcessorFsmLib instance is initialized
               within the function NvM_Init and therefore all type invariants are met (including type invariant for PartitionId).
               It seems that this is a false positive finding from the VCA tool, as all preconditions are met.

  \COUNTERMEASURE \N A code review ensures that the NvServiceProcessorFsmLib instance is always initialized when used.

VCA_JUSTIFICATION_END */

/**********************************************************************************************************************
 *  END OF FILE: NvM_NvServiceProcessorFsm.c
 *********************************************************************************************************************/
