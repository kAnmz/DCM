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
/*!        \file  NvM_ServiceProcessorFsm.c
 *        \brief  NvM_ServiceProcessorFsm source file
 *      \details  Implementation of service base state machine
 *         \unit  NvM_ServiceProcessorFsm
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

#define NVM_ServiceProcessorFsm_SOURCE

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
#include "NvM_ServiceProcessorFsm.h"

#include "NvM_Types.h"
#include "NvM_CfgDefines.h"
#include "NvM_FsmLib.h"
#include "NvM_GlobalUtilityLib.h"
#include "NvM_Queue.h"
#include "NvM_MultiBlockJobFsm.h"
#include "NvM_SingleBlockJobFsm.h"
#include "NvM_Notification.h"
#if (NVM_MULTIPARTITION_USAGE_SCENARIO == STD_ON)
#include "NvM_SatelliteCom.h"
#endif
#if (NVM_MULTIPARTITION_USAGE_SCENARIO == STD_OFF)
#include "MemIf.h"
#endif

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
 * NvM_ServiceProcessorFsm_Entry()
 *********************************************************************************************************************/
/*!  \brief       ENTRY action of ServiceProcessorFsm.
 *   \details     -
 *   \param[in]   partitionId Partition ID.
 *   \pre         -
 *   \context     TASK
 *   \reentrant   FALSE
 *   \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, NVM_PRIVATE_CODE) NvM_ServiceProcessorFsm_Entry(NvM_PartitionIdType partitionId);

/**********************************************************************************************************************
 * NvM_ServiceProcessorFsm_IdleState_Do()
 *********************************************************************************************************************/
/*!  \brief       DO action of ServiceProcessorFsm state Idle.
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
FUNC(NvM_FsmLib_ProcessingResultType, NVM_PRIVATE_CODE) NvM_ServiceProcessorFsm_IdleState_Do(
  NvM_PartitionIdType partitionId);

/**********************************************************************************************************************
 * NvM_ServiceProcessorFsm_ProcessNormalPrioJobState_Entry()
 *********************************************************************************************************************/
/*!  \brief       ENTRY action of ProcessNormalPrioJob state.
 *   \details     -
 *   \param[in]   partitionId Partition ID.
 *   \pre         -
 *   \context     TASK
 *   \reentrant   FALSE
 *   \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, NVM_PRIVATE_CODE) NvM_ServiceProcessorFsm_ProcessNormalPrioJobState_Entry(
  NvM_PartitionIdType partitionId);

/**********************************************************************************************************************
 * NvM_ServiceProcessorFsm_ProcessNormalPrioJobState_Do()
 *********************************************************************************************************************/
/*!  \brief       DO action of ServiceProcessorFsm state ProcessNormalPrioJob.
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
FUNC(NvM_FsmLib_ProcessingResultType, NVM_PRIVATE_CODE) NvM_ServiceProcessorFsm_ProcessNormalPrioJobState_Do(
  NvM_PartitionIdType partitionId);

/**********************************************************************************************************************
 * NvM_ServiceProcessorFsm_ProcessMultiBlockServiceState_Entry()
 *********************************************************************************************************************/
/*!  \brief       ENTRY action of ProcessMultiBlockService state.
 *   \details     -
 *   \param[in]   partitionId Partition ID.
 *   \pre         -
 *   \context     TASK
 *   \reentrant   FALSE
 *   \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, NVM_PRIVATE_CODE) NvM_ServiceProcessorFsm_ProcessMultiBlockServiceState_Entry(NvM_PartitionIdType partitionId);

/**********************************************************************************************************************
 * NvM_ServiceProcessorFsm_ProcessMultiBlockServiceState_Do()
 *********************************************************************************************************************/
/*!  \brief       DO action of ServiceProcessorFsm state ProcessMultiBlockService.
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
FUNC(NvM_FsmLib_ProcessingResultType, NVM_PRIVATE_CODE) NvM_ServiceProcessorFsm_ProcessMultiBlockServiceState_Do(
  NvM_PartitionIdType partitionId);

#if(NVM_JOB_PRIORITIZATION == STD_ON)
# if (NVM_MULTIPARTITION_USAGE_SCENARIO == STD_OFF)
/**********************************************************************************************************************
 * NvM_ServiceProcessorFsm_CancelMemIfState_Do()
 *********************************************************************************************************************/
/*!  \brief       DO action of ServiceProcessorFsm state CancelMemIfState.
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
FUNC(NvM_FsmLib_ProcessingResultType, NVM_PRIVATE_CODE) NvM_ServiceProcessorFsm_CancelMemIfState_Do(
  NvM_PartitionIdType partitionId);
# endif /* (NVM_MULTIPARTITION_USAGE_SCENARIO == STD_OFF) */

/**********************************************************************************************************************
 * NvM_ServiceProcessorFsm_ImmediateJobInterruptSetupState_Do()
 *********************************************************************************************************************/
/*!  \brief       DO action of ImmediateJobInterruptSetup state.
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
FUNC(NvM_FsmLib_ProcessingResultType, NVM_PRIVATE_CODE) NvM_ServiceProcessorFsm_ImmediateJobInterruptSetupState_Do(
  NvM_PartitionIdType partitionId);

/**********************************************************************************************************************
 * NvM_ServiceProcessorFsm_ProcessImmediateBlockServiceState_Entry()
 *********************************************************************************************************************/
/*!  \brief       ENTRY action of ProcessImmediateBlockService state.
 *   \details     -
 *   \param[in]   partitionId Partition ID.
 *   \pre         -
 *   \context     TASK
 *   \reentrant   FALSE
 *   \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, NVM_PRIVATE_CODE) NvM_ServiceProcessorFsm_ProcessImmediateBlockServiceState_Entry(
  NvM_PartitionIdType partitionId);

/**********************************************************************************************************************
 * NvM_ServiceProcessorFsm_ProcessImmediateBlockServiceState_Do()
 *********************************************************************************************************************/
/*!  \brief       DO action of ServiceProcessorFsm state ProcessImmediateBlockService.
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
FUNC(NvM_FsmLib_ProcessingResultType, NVM_PRIVATE_CODE) NvM_ServiceProcessorFsm_ProcessImmediateBlockServiceState_Do(
  NvM_PartitionIdType partitionId);

/**********************************************************************************************************************
 * NvM_ServiceProcessorFsm_ResumeMultiBlockJobState_Do()
 *********************************************************************************************************************/
/*!  \brief       DO action of ServiceProcessorFsm state ResumeMultiBlockJob.
 *   \details     The resuming of the multi block job processing after an immediate job interruption
 *                is handled within this state. The ServiceProcessor FSM does no longer process the
 *                multi block job stack till the immediate job is finished. After the finalization of the
 *                immediate block job, the multi block job stack is resumed by the ServiceProcessor FSM
 *                by continuing to process the multi block job stack again.
 *   \param[in]   partitionId Partition ID.
 *   \return      Based on state evaluation:
 *                 - STOP       if no further processing is required
 *                 - CONTINUE   if further processing shall be executed
 *   \pre         -
 *   \context     TASK
 *   \reentrant   FALSE
 *   \synchronous TRUE
 *********************************************************************************************************************/
FUNC(NvM_FsmLib_ProcessingResultType, NVM_PRIVATE_CODE) NvM_ServiceProcessorFsm_ResumeMultiBlockJobState_Do(
  NvM_PartitionIdType partitionId);
#endif /* (NVM_JOB_PRIORITIZATION == STD_ON) */


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
 * Initializing a const structure (NvM_ServiceProcessorFsm_InitialState) can only be done with compile-time constants.
 * Therefore this defines are introduced to minimize code duplication within NvM_ServiceProcessorFsm_InitialState and
 * NvM_ServiceProcessorFsm_IdleState initialization.
 */
#define NVM_ServiceProcessorFsm_IDLESTATE_ENTRY NvM_FsmLib_EntryNoOp
#define NVM_ServiceProcessorFsm_IDLESTATE_DO NvM_ServiceProcessorFsm_IdleState_Do

/*! STATE: Idle */
NVM_LOCAL CONST(NvM_StateType, NVM_PRIVATE_DATA) NvM_ServiceProcessorFsm_IdleState = {
  NVM_ServiceProcessorFsm_IDLESTATE_ENTRY, /* no ENTRY action required */
  NVM_ServiceProcessorFsm_IDLESTATE_DO
};

/*! STATE: ProcessNormalPrioJob */
NVM_LOCAL CONST(NvM_StateType, NVM_PRIVATE_DATA) NvM_ServiceProcessorFsm_ProcessNormalPrioJobState = {
  NvM_ServiceProcessorFsm_ProcessNormalPrioJobState_Entry,
  NvM_ServiceProcessorFsm_ProcessNormalPrioJobState_Do
};

/*! STATE: ProcessMultiBlockService */
NVM_LOCAL CONST(NvM_StateType, NVM_PRIVATE_DATA) NvM_ServiceProcessorFsm_ProcessMultiBlockServiceState = {
  NvM_ServiceProcessorFsm_ProcessMultiBlockServiceState_Entry,
  NvM_ServiceProcessorFsm_ProcessMultiBlockServiceState_Do
};

#if(NVM_JOB_PRIORITIZATION == STD_ON)
#if (NVM_MULTIPARTITION_USAGE_SCENARIO == STD_OFF)
/*! STATE: CancelMemIf*/
NVM_LOCAL CONST(NvM_StateType, NVM_PRIVATE_DATA) NvM_ServiceProcessorFsm_CancelMemIfState = {
  NvM_FsmLib_EntryNoOp,
  NvM_ServiceProcessorFsm_CancelMemIfState_Do
};
#endif /* (NVM_MULTIPARTITION_USAGE_SCENARIO == STD_OFF) */

/*! STATE: ImmediateJobInterruptSetup*/
NVM_LOCAL CONST(NvM_StateType, NVM_PRIVATE_DATA) NvM_ServiceProcessorFsm_ImmediateJobInterruptSetupState = {
  NvM_FsmLib_EntryNoOp,
  NvM_ServiceProcessorFsm_ImmediateJobInterruptSetupState_Do
};

/*! STATE: ProcessImmediateBlockService */
NVM_LOCAL CONST(NvM_StateType, NVM_PRIVATE_DATA) NvM_ServiceProcessorFsm_ProcessImmediateBlockServiceState = {
  NvM_ServiceProcessorFsm_ProcessImmediateBlockServiceState_Entry,
  NvM_ServiceProcessorFsm_ProcessImmediateBlockServiceState_Do
};

/*! STATE: ResumeMultiBlockJob */
NVM_LOCAL CONST(NvM_StateType, NVM_PRIVATE_DATA) NvM_ServiceProcessorFsm_ResumeMultiBlockJobState = {
  NvM_FsmLib_EntryNoOp,
  NvM_ServiceProcessorFsm_ResumeMultiBlockJobState_Do
};
#endif /* (NVM_JOB_PRIORITIZATION == STD_ON) */

/*! FSM: ServiceProcessorFsm instance with ENTRY action and initial state Idle */
/* PRQA S 3218 1 */ /* MD_Fsm_StateDefinitionStaticUsedOnlyInSingleFunction */
NVM_LOCAL CONST(NvM_FsmType, NVM_PRIVATE_DATA) NvM_ServiceProcessorFsm_InitialState = {
  NvM_ServiceProcessorFsm_Entry,
  {NVM_ServiceProcessorFsm_IDLESTATE_ENTRY, NVM_ServiceProcessorFsm_IDLESTATE_DO}
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
 * NvM_ServiceProcessorFsm_IsTransitionToSingleBlockProcessingAllowed()
 *********************************************************************************************************************/
/*! \brief           Checks whether a transition to single block processing is allowed.
 *  \details         Either a job is in the normal prio queue or a job was cached because of an immediate job request.
 *  \param[in]       partitionId Partition ID.
 *  \pre             -
 *  \context         TASK
 *  \reentrant       FALSE
 *  \synchronous     TRUE
 * \return           TRUE if transition is allowed, FALSE otherwise.
 *********************************************************************************************************************/
NVM_LOCAL_INLINE FUNC(boolean, NVM_PRIVATE_CODE) NvM_ServiceProcessorFsm_IsTransitionToSingleBlockProcessingAllowed(
  NvM_PartitionIdType partitionId);

/**********************************************************************************************************************
 * NvM_ServiceProcessorFsm_ProvideActiveMultiBlockJob()
 *********************************************************************************************************************/
/*! \brief           Provides an active multiblock job if available.
 *  \details         -
 *  \param[in]       partitionId       Partition ID.
 *  \pre             -
 *  \context         TASK
 *  \reentrant       FALSE
 *  \synchronous     TRUE
 *  \return          If multiblock job available, return E_OK, otherwise return E_NOT_OK.
 *********************************************************************************************************************/
FUNC(Std_ReturnType, NVM_PRIVATE_CODE) NvM_ServiceProcessorFsm_ProvideActiveMultiBlockJob(
  const NvM_PartitionIdType partitionId);

/**********************************************************************************************************************
 * NvM_ServiceProcessorFsm_SetUpSingleBlockJobContext()
 *********************************************************************************************************************/
/*! \brief           Sets up the single block job context based on the provided job.
 *  \details         -
 *  \param[out]      singleBlockJobContext   Pointer to single block job context to be set up.
 *  \param[in]       job                     Job information.
 *  \param[in]       partitionId             Partition ID.
 *  \pre             -
 *  \context         TASK
 *  \reentrant       FALSE
 *  \synchronous     TRUE
 *********************************************************************************************************************/
NVM_LOCAL_INLINE FUNC(void, NVM_PRIVATE_CODE) NvM_ServiceProcessorFsm_SetUpSingleBlockJobContext(
  NvM_SingleBlockJobContextPtrType singleBlockJobContext,
  NvM_Queue_JobType job,
  NvM_PartitionIdType partitionId);

/**********************************************************************************************************************
 * NvM_ServiceProcessorFsm_ProcessSingleBlockJobFsm()
 *********************************************************************************************************************/
/*! \brief           Processes the single block job FSM and
 *                   updates the error status in case it is already finished processing.
 *  \details         -
 *  \param[in]       partitionId Partition ID.
 *  \pre             -
 *  \context         TASK
 *  \reentrant       FALSE
 *  \synchronous     TRUE
 *  \return          STOP in case no further processing is required, CONTINUE otherwise.
 *********************************************************************************************************************/
FUNC(NvM_FsmLib_ProcessingResultType, NVM_PRIVATE_CODE) NvM_ServiceProcessorFsm_ProcessSingleBlockJobFsm(
  NvM_PartitionIdType partitionId);

#if (NVM_JOB_PRIORITIZATION == STD_ON)
/**********************************************************************************************************************
 * NvM_ServiceProcessorFsm_CleanUpProcessingStacks()
 *********************************************************************************************************************/
/*! \brief           Resets the processing stacks of all involved state machines.
 *  \details         -
 *  \param[in]       partitionId Partition ID.
 *  \pre             -
 *  \context         TASK
 *  \reentrant       FALSE
 *  \synchronous     TRUE
 *********************************************************************************************************************/
NVM_LOCAL_INLINE FUNC(void, NVM_PRIVATE_CODE) NvM_ServiceProcessorFsm_CleanUpProcessingStacks(
  NvM_PartitionIdType partitionId);

/**********************************************************************************************************************
 * NvM_ServiceProcessorFsm_IsImmediateJobRequested()
 *********************************************************************************************************************/
/*! \brief           Helper function to check whether an immediate job is requested.
 *  \details         -
 *  \pre             -
 *  \context         TASK
 *  \reentrant       FALSE
 *  \synchronous     TRUE
 *  \return          TRUE if an immediate job is requested, FALSE otherwise.
 *********************************************************************************************************************/
NVM_LOCAL_INLINE FUNC(boolean, NVM_PRIVATE_CODE) NvM_ServiceProcessorFsm_IsImmediateJobRequested(
    NvM_PartitionIdType partitionId);
#endif /* (NVM_JOB_PRIORITIZATION == STD_ON) */

/***********************************************************************************************************************
 *  LOCAL FUNCTIONS
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  NvM_ServiceProcessorFsm_ProvideActiveMultiBlockJob
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
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, NVM_PRIVATE_CODE) NvM_ServiceProcessorFsm_ProvideActiveMultiBlockJob(
  const NvM_PartitionIdType partitionId)
{
  Std_ReturnType status = E_NOT_OK;
  NvM_MultiBlockJobType foundMultiBlockJob = NVM_MULTIBLOCKJOBTYPE_READ_ALL;

#if (NVM_MULTIPARTITION_USAGE_SCENARIO == STD_ON)
  if (NvM_SatelliteCom_GetMultiBlockJobStatus(partitionId) == NVM_MASTERSATELLITE_MULTIBLOCK_JOB_REQUEST_REQUESTED)
  {
    foundMultiBlockJob = NvM_SatelliteCom_GetRequestedMultiBlockJob(partitionId);

    status = E_OK;
  }
#else
  NvM_GlobalUtilityLib_EnterCriticalSection();
  {
    NvM_MultiBlockJobInformationPtrType multiBlockJobInfo =
      NvM_GetAddrMultiBlockJobInformation(NVM_PARTITION_ID_MASTER);

    if(NvM_GlobalUtilityLib_IsFlagSet(multiBlockJobInfo->JobStatusFlag, NVM_MULTIBLOCK_FLAG_READALL_REQUESTED))
    {
      multiBlockJobInfo->JobStatusFlag = NvM_GlobalUtilityLib_SetFlag(multiBlockJobInfo->JobStatusFlag,
                                                                        NVM_MULTIBLOCK_FLAG_READALL_ACTIVE);

      foundMultiBlockJob = NVM_MULTIBLOCKJOBTYPE_READ_ALL;

      status = E_OK;
    }
    else if (NvM_GlobalUtilityLib_IsFlagSet(multiBlockJobInfo->JobStatusFlag, NVM_MULTIBLOCK_FLAG_WRITEALL_REQUESTED))
    {
      multiBlockJobInfo->JobStatusFlag = NvM_GlobalUtilityLib_SetFlag(multiBlockJobInfo->JobStatusFlag,
                                                                        NVM_MULTIBLOCK_FLAG_WRITEALL_ACTIVE);

      foundMultiBlockJob = NVM_MULTIBLOCKJOBTYPE_WRITE_ALL;

      status = E_OK;
    }
    else if (NvM_GlobalUtilityLib_IsFlagSet(multiBlockJobInfo->JobStatusFlag, NVM_MULTIBLOCK_FLAG_VALIDATEALL_REQUESTED))
    {
      multiBlockJobInfo->JobStatusFlag = NvM_GlobalUtilityLib_SetFlag(multiBlockJobInfo->JobStatusFlag,
                                                                        NVM_MULTIBLOCK_FLAG_VALIDATEALL_ACTIVE);

      foundMultiBlockJob = NVM_MULTIBLOCKJOBTYPE_VALIDATE_ALL;

      status = E_OK;
    }
    else
    {
      /*
       * MISRA case. Do nothing.
       * This default case is empty due to the fact that this function
       * does not process cancel and kill requests.
      */
    }
  }
  NvM_GlobalUtilityLib_ExitCriticalSection();

  NVM_DUMMY_STATEMENT_CONST(partitionId);                                                                               /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif /*(NVM_MULTIPARTITION_USAGE_SCENARIO == STD_ON)*/

  if (status == E_OK)
  {
    NvM_SetMultiBlockJob(foundMultiBlockJob, partitionId);
  }

  return status;
}

/**********************************************************************************************************************
 * NvM_ServiceProcessorFsm_SetUpSingleBlockJobContext()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
NVM_LOCAL_INLINE FUNC(void, NVM_PRIVATE_CODE) NvM_ServiceProcessorFsm_SetUpSingleBlockJobContext(
  NvM_SingleBlockJobContextPtrType singleBlockJobContext,
  NvM_Queue_JobType job,
  NvM_PartitionIdType partitionId)
{
  NvM_InternalBufferPtrType internalBuffer = NvM_GetAddrInternalBuffer(0u, partitionId);

  NvM_BlockManagementInformationPtrType blockManagementInfo = NvM_GlobalUtilityLib_GetBlockManagementInfo(
    job.BlockId,
    job.BlockDescriptorLookupTableId,
    partitionId);

  /* Setup job */
  singleBlockJobContext->SingleBlockJobType = job.SingleBlockJobType;
  singleBlockJobContext->BlockId = job.BlockId;
  singleBlockJobContext->BlockDescriptorLookupTableId = job.BlockDescriptorLookupTableId;
  singleBlockJobContext->TemporaryRamBlockAddr = job.TemporaryRamBlockAddr;
  singleBlockJobContext->DataIndex = blockManagementInfo->DataIndex;
  singleBlockJobContext->DataBuffer = internalBuffer;
}

#if(NVM_JOB_PRIORITIZATION == STD_ON)
/**********************************************************************************************************************
 * NvM_ServiceProcessorFsm_CleanUpProcessingStacks()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
NVM_LOCAL_INLINE FUNC(void, NVM_PRIVATE_CODE) NvM_ServiceProcessorFsm_CleanUpProcessingStacks(NvM_PartitionIdType partitionId)
{
  NVM_DUMMY_STATEMENT(partitionId);                                                                                     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  NvM_FsmLib_InstancePtrType singleBlockJobFsmLibInstance =
    (NvM_FsmLib_InstancePtrType)NvM_GetAddrSingleBlockServiceFsmLib_Instance(partitionId);

  NvM_FsmLib_ClearProcessingStack(singleBlockJobFsmLibInstance);

# if (NVM_MULTIPARTITION_USAGE_SCENARIO == STD_OFF)
  NvM_FsmLib_InstancePtrType nvServiceFsmLibInstance =
    (NvM_FsmLib_InstancePtrType)NvM_GetAddrNvServiceFsmLib_Instance(partitionId);

  NvM_FsmLib_ClearProcessingStack(nvServiceFsmLibInstance);
# endif /* (NVM_MULTIPARTITION_USAGE_SCENARIO == STD_OFF)  */
}

/**********************************************************************************************************************
 * NvM_ServiceProcessorFsm_IsImmediateJobRequested()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
NVM_LOCAL_INLINE FUNC(boolean, NVM_PRIVATE_CODE) NvM_ServiceProcessorFsm_IsImmediateJobRequested(
  NvM_PartitionIdType partitionId)
{
  NVM_DUMMY_STATEMENT(partitionId);                                                                                     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  NvM_Queue_InstancePtrType immediateJobQueue = NvM_GetAddrImmediateQueue_Instance(partitionId);

  return NvM_Queue_HasEntries(immediateJobQueue);
}
#endif /* (NVM_JOB_PRIORITIZATION == STD_ON) */

/**********************************************************************************************************************
 * NvM_ServiceProcessorFsm_IsTransitionToSingleBlockProcessingAllowed()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
NVM_LOCAL_INLINE FUNC(boolean, NVM_PRIVATE_CODE) NvM_ServiceProcessorFsm_IsTransitionToSingleBlockProcessingAllowed(
  NvM_PartitionIdType partitionId)
{
  NVM_DUMMY_STATEMENT(partitionId);                                                                                     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  NvM_Queue_InstancePtrType queueInstance = NvM_GetAddrQueue_Instance(partitionId);

#if(NVM_JOB_PRIORITIZATION == STD_ON)
  NvM_ServiceProcessorFsm_ContextType serviceProcessorContext = NvM_GetServiceProcessorFsm_Context(partitionId);

  return (NvM_Queue_HasEntries(queueInstance) == TRUE)
        || (serviceProcessorContext.SingleBlockJobToResume.SingleBlockJobType != NVM_SINGLEBLOCKJOBTYPE_NONE);
#else
  return NvM_Queue_HasEntries(queueInstance);
#endif
}

/**********************************************************************************************************************
 * NvM_ServiceProcessorFsm_ProcessSingleBlockJobFsm()
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
FUNC(NvM_FsmLib_ProcessingResultType, NVM_PRIVATE_CODE) NvM_ServiceProcessorFsm_ProcessSingleBlockJobFsm(
  NvM_PartitionIdType partitionId)
{
  NvM_FsmLib_ProcessingResultType retVal = NVM_FSMLIB_PROCESSINGRESULT_STOP;

  NvM_FsmLib_InstancePtrType singleBlockFsmLibInstance =
    (NvM_FsmLib_InstancePtrType)NvM_GetAddrSingleBlockServiceFsmLib_Instance(partitionId);

  NvM_FsmLib_ProcessCurrentActiveFsm(singleBlockFsmLibInstance);

  if (NvM_FsmLib_IsProcessingStackEmpty(singleBlockFsmLibInstance) == TRUE)
  {
    NvM_SingleBlockJobContextPtrType singleBlockJobContext = NvM_GetAddrSingleBlockJobContext(partitionId);
    NvM_ServiceJobResultType serviceJobResult = NvM_FsmLib_GetSubFsmResult(singleBlockFsmLibInstance);
    NvM_BlockManagementInformationPtrType blockManagementInfo = NvM_GlobalUtilityLib_GetBlockManagementInfo(
      singleBlockJobContext->BlockId,
      singleBlockJobContext->BlockDescriptorLookupTableId,
      partitionId);

    blockManagementInfo->ErrorStatus =
      NvM_GlobalUtilityLib_ConvertServiceJobResultToNvMRequestResult(serviceJobResult);

    NvM_Notification_ProcessSingleBlockCallback(singleBlockJobContext, partitionId);

    retVal = NVM_FSMLIB_PROCESSINGRESULT_CONTINUE;
  }

  return retVal;
}

/**********************************************************************************************************************
 * NvM_ServiceProcessorFsm_Entry()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, NVM_PRIVATE_CODE) NvM_ServiceProcessorFsm_Entry(NvM_PartitionIdType partitionId)
{
  NVM_DUMMY_STATEMENT(partitionId);                                                                                     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  NvM_FsmLib_InstancePtrToConstType serviceProcessorFsmLibInstance =
    (NvM_FsmLib_InstancePtrToConstType)NvM_GetAddrServiceProcessorFsmLib_Instance(partitionId);

  NvM_FsmLib_TransitionToState(serviceProcessorFsmLibInstance, NvM_ServiceProcessorFsm_IdleState);
}

/*!
 * STATE: Idle
 */

/**********************************************************************************************************************
 * NvM_ServiceProcessorFsm_IdleState_Do()
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
FUNC(NvM_FsmLib_ProcessingResultType, NVM_PRIVATE_CODE) NvM_ServiceProcessorFsm_IdleState_Do(
  NvM_PartitionIdType partitionId)
{
  NVM_DUMMY_STATEMENT(partitionId);                                                                                     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  NvM_FsmLib_ProcessingResultType retVal = NVM_FSMLIB_PROCESSINGRESULT_STOP;

  NvM_FsmLib_InstancePtrToConstType serviceProcessorFsmLibInstance =
    (NvM_FsmLib_InstancePtrToConstType)NvM_GetAddrServiceProcessorFsmLib_Instance(partitionId);

#if(NVM_JOB_PRIORITIZATION == STD_ON)
  if (NvM_ServiceProcessorFsm_IsImmediateJobRequested(partitionId) == TRUE)
  {
    NvM_FsmLib_TransitionToState(serviceProcessorFsmLibInstance, NvM_ServiceProcessorFsm_ProcessImmediateBlockServiceState);
    retVal = NVM_FSMLIB_PROCESSINGRESULT_CONTINUE;
  }
  else
#endif /* (NVM_JOB_PRIORITIZATION == STD_ON) */
  {
    boolean isSingleBlockProcessingAllowed =
      NvM_ServiceProcessorFsm_IsTransitionToSingleBlockProcessingAllowed(partitionId);

    if (isSingleBlockProcessingAllowed == TRUE)
    {
      NvM_FsmLib_TransitionToState(serviceProcessorFsmLibInstance, NvM_ServiceProcessorFsm_ProcessNormalPrioJobState);
      retVal = NVM_FSMLIB_PROCESSINGRESULT_CONTINUE;
    }
    else if (NvM_ServiceProcessorFsm_ProvideActiveMultiBlockJob(partitionId) == E_OK)
    {
      NvM_FsmLib_TransitionToState(serviceProcessorFsmLibInstance, NvM_ServiceProcessorFsm_ProcessMultiBlockServiceState);
      retVal = NVM_FSMLIB_PROCESSINGRESULT_CONTINUE;
    }
    else
    {
      /*
      * MISRA case. Do nothing.
      * This default case is empty, because it can happen that the queue is empty,
      * or no multiblock job is available.
      */
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 * NvM_ServiceProcessorFsm_ProcessNormalPrioJobState_Entry()
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
FUNC(void, NVM_PRIVATE_CODE) NvM_ServiceProcessorFsm_ProcessNormalPrioJobState_Entry(
  NvM_PartitionIdType partitionId)
{
  NVM_DUMMY_STATEMENT(partitionId);                                                                                     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  NvM_Queue_JobType job = {0};
  NvM_SingleBlockJobContextPtrType singleBlockJobContext = NvM_GetAddrSingleBlockJobContext(partitionId);
  NvM_Queue_InstancePtrType queueInstance = NvM_GetAddrQueue_Instance(partitionId);

#if(NVM_JOB_PRIORITIZATION == STD_ON)
  NvM_ServiceProcessorFsm_ContextPtrType serviceProcessorContext = NvM_GetAddrServiceProcessorFsm_Context(partitionId);

  if(serviceProcessorContext->SingleBlockJobToResume.SingleBlockJobType == NVM_SINGLEBLOCKJOBTYPE_NONE)
  {
    NvM_GlobalUtilityLib_EnterCriticalSection();
    {
      NvM_Queue_Pop(queueInstance, &job);                                                                               /* VCA_NVM_InitialQueueJob */
    }
    NvM_GlobalUtilityLib_ExitCriticalSection();
  }
  else
  {
    job.BlockDescriptorLookupTableId = serviceProcessorContext->SingleBlockJobToResume.BlockDescriptorLookupTableId;
    job.BlockId = serviceProcessorContext->SingleBlockJobToResume.BlockId;
    job.TemporaryRamBlockAddr = serviceProcessorContext->SingleBlockJobToResume.TemporaryRamBlockAddr;
    job.SingleBlockJobType = serviceProcessorContext->SingleBlockJobToResume.SingleBlockJobType;
  }
#else
    NvM_GlobalUtilityLib_EnterCriticalSection();
    {
      NvM_Queue_Pop(queueInstance, &job);                                                                               /* VCA_NVM_InitialQueueJob */
    }
    NvM_GlobalUtilityLib_ExitCriticalSection();
#endif /* (NVM_JOB_PRIORITIZATION == STD_ON) */

  NvM_ServiceProcessorFsm_SetUpSingleBlockJobContext(singleBlockJobContext, job, partitionId);
  NvM_SingleBlockJobFsm_Spawn(partitionId);
}

/**********************************************************************************************************************
 * NvM_ServiceProcessorFsm_ProcessNormalPrioJobState_Do()
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
FUNC(NvM_FsmLib_ProcessingResultType, NVM_PRIVATE_CODE) NvM_ServiceProcessorFsm_ProcessNormalPrioJobState_Do(
  NvM_PartitionIdType partitionId)
{
  NVM_DUMMY_STATEMENT(partitionId);                                                                                     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  NvM_FsmLib_ProcessingResultType retVal = NVM_FSMLIB_PROCESSINGRESULT_STOP;

#if(NVM_JOB_PRIORITIZATION == STD_ON)
  if (NvM_ServiceProcessorFsm_IsImmediateJobRequested(partitionId) == TRUE)
  {
    NvM_FsmLib_InstancePtrType serviceProcessorFsmLibInstance =
      (NvM_FsmLib_InstancePtrType)NvM_GetAddrServiceProcessorFsmLib_Instance(partitionId);

    NvM_FsmLib_TransitionToState(serviceProcessorFsmLibInstance, NvM_ServiceProcessorFsm_ImmediateJobInterruptSetupState);
    retVal = NVM_FSMLIB_PROCESSINGRESULT_CONTINUE;
  }
  else
#endif /* (NVM_JOB_PRIORITIZATION == STD_ON) */
  {
    retVal = NvM_ServiceProcessorFsm_ProcessSingleBlockJobFsm(partitionId);

    if (retVal == NVM_FSMLIB_PROCESSINGRESULT_CONTINUE)
    {
      NvM_FsmLib_InstancePtrType serviceProcessorFsmLibInstance =
        (NvM_FsmLib_InstancePtrType)NvM_GetAddrServiceProcessorFsmLib_Instance(partitionId);

      NvM_FsmLib_TransitionToState(serviceProcessorFsmLibInstance, NvM_ServiceProcessorFsm_IdleState);
#if(NVM_JOB_PRIORITIZATION == STD_ON)
      /* Reset the cached job always after normal priority job processing is finished.
      In case of a non-cached job this is not directly necessary but keeps the implementation consistent. */
      NvM_ServiceProcessorFsm_ContextPtrType serviceProcessorContext = NvM_GetAddrServiceProcessorFsm_Context(partitionId);
      serviceProcessorContext->SingleBlockJobToResume.SingleBlockJobType = NVM_SINGLEBLOCKJOBTYPE_NONE;
#endif /* (NVM_JOB_PRIORITIZATION == STD_ON) */
    }
  }

  return retVal;
}

#if(NVM_JOB_PRIORITIZATION == STD_ON)
/**********************************************************************************************************************
 * NvM_ServiceProcessorFsm_ProcessImmediateBlockServiceState_Entry()
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
FUNC(void, NVM_PRIVATE_CODE) NvM_ServiceProcessorFsm_ProcessImmediateBlockServiceState_Entry(
  NvM_PartitionIdType partitionId)
{
  NVM_DUMMY_STATEMENT(partitionId);                                                                                     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  NvM_SingleBlockJobContextPtrType singleBlockJobContext = NvM_GetAddrSingleBlockJobContext(partitionId);

#if (NVM_MULTIPARTITION_USAGE_SCENARIO == STD_ON)
  NvM_SatelliteCom_PropagateImmediateBlockJob(partitionId);
#endif /* (NVM_MULTIPARTITION_USAGE_SCENARIO == STD_ON) */

  NvM_Queue_JobType job = {0};
  NvM_Queue_InstancePtrType immediateQueueInstance = NvM_GetAddrImmediateQueue_Instance(partitionId);

  NvM_GlobalUtilityLib_EnterCriticalSection();
  {
    NvM_Queue_Pop(immediateQueueInstance, &job);                                                                         /* VCA_NVM_InitialQueueJob */
  }
  NvM_GlobalUtilityLib_ExitCriticalSection();

  NvM_ServiceProcessorFsm_SetUpSingleBlockJobContext(singleBlockJobContext, job, partitionId);

  NvM_SingleBlockJobFsm_Spawn(partitionId);
}

/**********************************************************************************************************************
 * NvM_ServiceProcessorFsm_ProcessImmediateBlockServiceState_Do()
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
FUNC(NvM_FsmLib_ProcessingResultType, NVM_PRIVATE_CODE) NvM_ServiceProcessorFsm_ProcessImmediateBlockServiceState_Do(
  NvM_PartitionIdType partitionId)
{
  NVM_DUMMY_STATEMENT(partitionId);                                                                                     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  NvM_FsmLib_ProcessingResultType retVal = NVM_FSMLIB_PROCESSINGRESULT_STOP;

  NvM_FsmLib_InstancePtrType serviceProcessorFsmLibInstance =
    (NvM_FsmLib_InstancePtrType)NvM_GetAddrServiceProcessorFsmLib_Instance(partitionId);

  retVal = NvM_ServiceProcessorFsm_ProcessSingleBlockJobFsm(partitionId);

  if (retVal == NVM_FSMLIB_PROCESSINGRESULT_CONTINUE)
  {
    NvM_ServiceProcessorFsm_ContextPtrType serviceProcessorContext = NvM_GetAddrServiceProcessorFsm_Context(partitionId);
    NvM_FsmLib_InstancePtrType multiBlockFsmLibInstance =
      (NvM_FsmLib_InstancePtrType)NvM_GetAddrMultiBlockServiceFsmLib_Instance(partitionId);

    serviceProcessorContext->IsImmediateJobActive = FALSE;

    /* In case the multi block job stack is NOT empty,
      a multi block job is currently active and was interrupted by an immediate block job.
      In this case the multi block job has to be resumed.
      The resuming of the multi block job is done by processing the multi block job stack again. */
    if (NvM_FsmLib_IsProcessingStackEmpty(multiBlockFsmLibInstance) == FALSE)
    {
      NvM_FsmLib_TransitionToState(serviceProcessorFsmLibInstance, NvM_ServiceProcessorFsm_ResumeMultiBlockJobState);
    }
    else
    {
      /* There could be a single block job to resume or not. In both case a transition to the Idle
      state is performed, which handles the dispatching of the next job. */
      NvM_FsmLib_TransitionToState(serviceProcessorFsmLibInstance, NvM_ServiceProcessorFsm_IdleState);
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 * NvM_ServiceProcessorFsm_ResumeMultiBlockJobState_Do()
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
FUNC(NvM_FsmLib_ProcessingResultType, NVM_PRIVATE_CODE) NvM_ServiceProcessorFsm_ResumeMultiBlockJobState_Do(
  NvM_PartitionIdType partitionId)
{
  NvM_FsmLib_ProcessingResultType retVal = NVM_FSMLIB_PROCESSINGRESULT_STOP;

  if (NvM_ServiceProcessorFsm_IsImmediateJobRequested(partitionId) == TRUE)
  {
    NvM_FsmLib_InstancePtrType serviceProcessorFsmLibInstance =
      (NvM_FsmLib_InstancePtrType)NvM_GetAddrServiceProcessorFsmLib_Instance(partitionId);

    NvM_FsmLib_TransitionToState(serviceProcessorFsmLibInstance, NvM_ServiceProcessorFsm_ImmediateJobInterruptSetupState);

    retVal = NVM_FSMLIB_PROCESSINGRESULT_CONTINUE;
  }
  else
  {
    NvM_FsmLib_InstancePtrType multiBlockFsmLibInstance =
      (NvM_FsmLib_InstancePtrType)NvM_GetAddrMultiBlockServiceFsmLib_Instance(partitionId);

    NvM_FsmLib_ProcessCurrentActiveFsm(multiBlockFsmLibInstance);

    /* In case the multi block job stack is empty,
      the requested multi block job is finished processing and hence
      a transition to the Idle state is performed. */
    if (NvM_FsmLib_IsProcessingStackEmpty(multiBlockFsmLibInstance) == TRUE)
    {
      NvM_FsmLib_InstancePtrType serviceProcessorFsmLibInstance =
        (NvM_FsmLib_InstancePtrType)NvM_GetAddrServiceProcessorFsmLib_Instance(partitionId);

      NvM_FsmLib_TransitionToState(serviceProcessorFsmLibInstance, NvM_ServiceProcessorFsm_IdleState);

      retVal = NVM_FSMLIB_PROCESSINGRESULT_CONTINUE;
    }
  }

  return retVal;
}

# if (NVM_MULTIPARTITION_USAGE_SCENARIO == STD_OFF)
/**********************************************************************************************************************
 * NvM_ServiceProcessorFsm_CancelMemIfState_Do()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(NvM_FsmLib_ProcessingResultType, NVM_PRIVATE_CODE) NvM_ServiceProcessorFsm_CancelMemIfState_Do(
  NvM_PartitionIdType partitionId)
{
  NVM_DUMMY_STATEMENT(partitionId);                                                                                     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  NvM_FsmLib_ProcessingResultType retVal = NVM_FSMLIB_PROCESSINGRESULT_STOP;

  NvM_FsmLib_InstancePtrType serviceProcessorFsmLibInstance =
    (NvM_FsmLib_InstancePtrType)NvM_GetAddrServiceProcessorFsmLib_Instance(partitionId);

  /* In case of a multi block job, the single block job context
    is used to set up the individual jobs, which are part of the multi block job.
    Hence the single block job context contains the correct MemIfDeviceIndex
    for the individual job, which is currently processed during the multi block job. */
  NvM_SingleBlockJobContextPtrType singleBlockJobContext = NvM_GetAddrSingleBlockJobContext(partitionId);

  NvM_BlockDescriptorPtrType blockDescriptor = NvM_GetAddrBlockDescriptor(
    singleBlockJobContext->BlockDescriptorLookupTableId);

  if (MemIf_GetStatus((uint8)(blockDescriptor->MemIfDeviceIndex)) == MEMIF_BUSY)
  {
    MemIf_Cancel((uint8)(blockDescriptor->MemIfDeviceIndex));
  }

  NvM_FsmLib_TransitionToState(serviceProcessorFsmLibInstance,
    NvM_ServiceProcessorFsm_ProcessImmediateBlockServiceState);

  retVal = NVM_FSMLIB_PROCESSINGRESULT_CONTINUE;

  return retVal;
}
# endif /* (NVM_MULTIPARTITION_USAGE_SCENARIO == STD_OFF) */

/**********************************************************************************************************************
 * NvM_ServiceProcessorFsm_ImmediateJobInterruptSetupState_Do()
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
FUNC(NvM_FsmLib_ProcessingResultType, NVM_PRIVATE_CODE) NvM_ServiceProcessorFsm_ImmediateJobInterruptSetupState_Do(
  NvM_PartitionIdType partitionId)
{
  NVM_DUMMY_STATEMENT(partitionId);                                                                                     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  NvM_FsmLib_InstancePtrType serviceProcessorFsmLibInstance =
    (NvM_FsmLib_InstancePtrType)NvM_GetAddrServiceProcessorFsmLib_Instance(partitionId);

  NvM_SingleBlockJobContextPtrType singleBlockJobContext = NvM_GetAddrSingleBlockJobContext(partitionId);
  NvM_ServiceProcessorFsm_ContextPtrType serviceProcessorContext = NvM_GetAddrServiceProcessorFsm_Context(partitionId);

  NvM_FsmLib_InstancePtrType multiBlockFsmLibInstance =
    (NvM_FsmLib_InstancePtrType)NvM_GetAddrMultiBlockServiceFsmLib_Instance(partitionId);

  /* Used for KillRead/KillWriteAll to know which processing stacks are allowed to be cleared */
  serviceProcessorContext->IsImmediateJobActive = TRUE;

  /* In case the multi block job stack is NOT empty,
    a multi block job is currently active and was interrupted by an immediate block job.
    In this case the MultiBlockJobFsm has to be notified about the interruption
    to ensure that the ReaAllFsm (resp. WriteAllFsm) can be set on hold
    and successfully resumed after the immediate job is processed.
    After the immediate job is processed, the resuming of the multi block job is done
    by processing the multi block job stack again. */
  if (NvM_FsmLib_IsProcessingStackEmpty(multiBlockFsmLibInstance) == FALSE)
  {
    NvM_MultiBlockJobFsm_NotifyImmediateJobInterrupt(partitionId);
  }
  else
  {
    serviceProcessorContext->SingleBlockJobToResume.SingleBlockJobType = singleBlockJobContext->SingleBlockJobType;
    serviceProcessorContext->SingleBlockJobToResume.BlockId = singleBlockJobContext->BlockId;
    serviceProcessorContext->SingleBlockJobToResume.BlockDescriptorLookupTableId =
      singleBlockJobContext->BlockDescriptorLookupTableId;
    serviceProcessorContext->SingleBlockJobToResume.TemporaryRamBlockAddr = singleBlockJobContext->TemporaryRamBlockAddr;
  }

  NvM_ServiceProcessorFsm_CleanUpProcessingStacks(partitionId);

  /* Only in single partition use case MemIf_Cancel() is allowed to be invoked.
  In multi partition use case only the master partition is allowed to perform a cancel operation.
  In this case the NvM_ServiceProcessorFsm takes over this task. */
#if (NVM_MULTIPARTITION_USAGE_SCENARIO == STD_ON)
  NvM_FsmLib_TransitionToState(serviceProcessorFsmLibInstance, NvM_ServiceProcessorFsm_ProcessImmediateBlockServiceState);
#else
  NvM_FsmLib_TransitionToState(serviceProcessorFsmLibInstance, NvM_ServiceProcessorFsm_CancelMemIfState);
#endif /* (NVM_MULTIPARTITION_USAGE_SCENARIO == STD_ON) */

  return NVM_FSMLIB_PROCESSINGRESULT_CONTINUE;
}

#endif /* (NVM_JOB_PRIORITIZATION == STD_ON) */

/**********************************************************************************************************************
 * NvM_ServiceProcessorFsm_ProcessMultiBlockServiceState_Entry()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, NVM_PRIVATE_CODE) NvM_ServiceProcessorFsm_ProcessMultiBlockServiceState_Entry(
  NvM_PartitionIdType partitionId)
{
  NVM_DUMMY_STATEMENT(partitionId);                                                                                     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  NvM_MultiBlockJobFsm_Spawn(partitionId);
}

/**********************************************************************************************************************
 * NvM_ServiceProcessorFsm_ProcessMultiBlockServiceState_Do()
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
FUNC(NvM_FsmLib_ProcessingResultType, NVM_PRIVATE_CODE) NvM_ServiceProcessorFsm_ProcessMultiBlockServiceState_Do(
  NvM_PartitionIdType partitionId)
{
  NVM_DUMMY_STATEMENT(partitionId);                                                                                     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  NvM_FsmLib_ProcessingResultType retVal = NVM_FSMLIB_PROCESSINGRESULT_STOP;

#if(NVM_JOB_PRIORITIZATION == STD_ON)
  if (NvM_ServiceProcessorFsm_IsImmediateJobRequested(partitionId) == TRUE)
  {
    NvM_FsmLib_InstancePtrType serviceProcessorFsmLibInstance =
      (NvM_FsmLib_InstancePtrType)NvM_GetAddrServiceProcessorFsmLib_Instance(partitionId);

    NvM_FsmLib_TransitionToState(serviceProcessorFsmLibInstance, NvM_ServiceProcessorFsm_ImmediateJobInterruptSetupState);

    retVal = NVM_FSMLIB_PROCESSINGRESULT_CONTINUE;
  }
  else
#endif /* (NVM_JOB_PRIORITIZATION == STD_ON) */
  {
    NvM_FsmLib_InstancePtrType multiBlockFsmLibInstance =
      (NvM_FsmLib_InstancePtrType)NvM_GetAddrMultiBlockServiceFsmLib_Instance(partitionId);

    NvM_FsmLib_ProcessCurrentActiveFsm(multiBlockFsmLibInstance);

    /* In case the multi block job stack is empty,
      the requested multi block job is finished processing and hence
      a transition to the Idle state is performed. */
    if (NvM_FsmLib_IsProcessingStackEmpty(multiBlockFsmLibInstance) == TRUE)
    {
      NvM_FsmLib_InstancePtrType serviceProcessorFsmLibInstance =
        (NvM_FsmLib_InstancePtrType)NvM_GetAddrServiceProcessorFsmLib_Instance(partitionId);

      NvM_FsmLib_TransitionToState(serviceProcessorFsmLibInstance, NvM_ServiceProcessorFsm_IdleState);

      retVal = NVM_FSMLIB_PROCESSINGRESULT_CONTINUE;
    }
  }

  return retVal;
}

/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

/**********************************************************************************************************************
 * NvM_ServiceProcessorFsm_Spawn()
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
FUNC(void, NVM_PRIVATE_CODE) NvM_ServiceProcessorFsm_Spawn(NvM_PartitionIdType partitionId)
{
  NVM_DUMMY_STATEMENT(partitionId);                                                                                     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  NvM_FsmLib_InstancePtrType serviceProcessorFsmLibInstance =
    (NvM_FsmLib_InstancePtrType)NvM_GetAddrServiceProcessorFsmLib_Instance(partitionId);

  NvM_ServiceProcessorFsm_ContextPtrType serviceProcessorContext = NvM_GetAddrServiceProcessorFsm_Context(partitionId);
  serviceProcessorContext->SingleBlockJobToResume.SingleBlockJobType = NVM_SINGLEBLOCKJOBTYPE_NONE;
  serviceProcessorContext->SingleBlockJobToResume.BlockId = 0u;
  serviceProcessorContext->SingleBlockJobToResume.BlockDescriptorLookupTableId = 0u;
  serviceProcessorContext->SingleBlockJobToResume.TemporaryRamBlockAddr = NULL_PTR;
#if (NVM_JOB_PRIORITIZATION == STD_ON)
  serviceProcessorContext->IsImmediateJobActive = FALSE;
#endif /* (NVM_JOB_PRIORITIZATION == STD_ON) */

  /* COM-4978: Wait for CSL feature to store init value of generated partition data */
  NvM_ServiceProcessorFsm_InstancePtrType fsmInstance = NvM_GetAddrServiceProcessorFsm_Instance(partitionId);
  *fsmInstance = NvM_ServiceProcessorFsm_InitialState;

  (void)NvM_FsmLib_SpawnFsm(serviceProcessorFsmLibInstance, *fsmInstance);                                              /* VCA_NVM_FsmLibInstanceInit  */
}

#if (NVM_JOB_PRIORITIZATION == STD_ON)
/**********************************************************************************************************************
 * NvM_ServiceProcessorFsm_IsImmediateJobActive()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(boolean, NVM_PRIVATE_CODE) NvM_ServiceProcessorFsm_IsImmediateJobActive(
  const NvM_PartitionIdType partitionId)
{
  /*
   * The parameter partitionId is not used within this function in single partition use case.
   * To avoid compiler warnings the following dummy statement is added.
   */
  NVM_DUMMY_STATEMENT_CONST(partitionId);                                                                               /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  NvM_ServiceProcessorFsm_ContextPtrType serviceProcessorContext = NvM_GetAddrServiceProcessorFsm_Context(partitionId);
  return serviceProcessorContext->IsImmediateJobActive;
}
#endif /* (NVM_JOB_PRIORITIZATION == STD_ON) */

#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  VCA JUSTIFICATIONS
 **********************************************************************************************************************/
/* VCA_JUSTIFICATION_BEGIN

\ID VCA_NVM_InitialQueueJob
  \DESCRIPTION The local job queue variable is used to pop the next job from the queue.
               This local variable is initialized to {0} at definition. So the state of this variable is very clear
               at queue job pop point in time, but VCA provides a finding here.
               This is a false positive finding of the VCA and therefore justified.

  \COUNTERMEASURE \N No counter measure is necessary due to false positive finding of VCA.

\ID VCA_NVM_FsmLibInstanceInit
  \DESCRIPTION The FsmLib instance is not initalized before calling the inital SpawnFsm function within this unit.
               Nevertheless, the type invariant of the NvM_FsmLib_InstanceType is not violated.
               This is a false positive finding of the VCA and therefore justified.

  \COUNTERMEASURE \N A code review shall ensure that the current FsmLib instance is initialized correctly after
                     calling this initial SpawnFsm function.

VCA_JUSTIFICATION_END */

/***********************************************************************************************************************
 *  END OF FILE: NvM_ServiceProcessorFsm.c
 **********************************************************************************************************************/
