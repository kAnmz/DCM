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
/*!        \file  MemAcc_MainFsm.c
 *        \brief  MemAcc_MainFsm source file
 *      \details  Implementation of the MainFsm unit of the MemAcc.
 *         \unit  MainFsm
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#define MEMACC_MAINFSM_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "MemAcc_MainFsm.h"
#include "MemAcc_Queue.h"
#include "MemAcc_JobProcessing.h"
#include "MemAcc_MultiBinary.h"
#include "MemAcc_MemAb.h"
#include "MemAcc_Utils.h"

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/
#if !defined (MEMACC_LOCAL)
# define MEMACC_LOCAL                                                    static
#endif

#if !defined (MEMACC_LOCAL_INLINE)
# define MEMACC_LOCAL_INLINE                                             LOCAL_INLINE
#endif

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
# define MEMACC_START_SEC_CODE
# include "MemAcc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * MemAcc_MainFsm_TransitionToState()
 *********************************************************************************************************************/
/*!  \brief       Execute a transition to a new state for the given synchronization group.
 *   \details     ENTRY action of new state will automatically be invoked.
 *   \param[in]   newStatePtr         Pointer to const state that shall be achieved.
 *   \param[in]   syncGroupIndex      Index of synchronization group that is currently processed.
 *   \pre         -
 *   \context     TASK
 *   \reentrant   FALSE
 *   \synchronous TRUE
 *********************************************************************************************************************/
void MemAcc_MainFsm_TransitionToState(
  const MemAcc_MainFsm_StateType* newStatePtr,
  MemAcc_SyncGroupIndexType syncGroupIndex);

/**********************************************************************************************************************
 * MemAcc_MainFsm_EntryNoOp()
 *********************************************************************************************************************/
/*!  \brief       No-operation function to be used when a state needs no ENTRY action.
 *   \details     -
 *   \param[in]   syncGroupIndex      Index of synchronization group (needed to match signature).
 *   \pre         -
 *   \context     TASK
 *   \reentrant   FALSE
 *   \synchronous TRUE
 *********************************************************************************************************************/
void MemAcc_MainFsm_EntryNoOp(MemAcc_SyncGroupIndexType syncGroupIndex);

/**********************************************************************************************************************
 * MemAcc_MainFsm_SchedulingDo()
 *********************************************************************************************************************/
/*!  \brief       DO action of MainFsm state Scheduling.
 *   \details     Check if there is a job in the queue to process in the given synchronization group.
 *                If a job is found, start processing it as singlebinary or multibinary job depending on configuration.
 *   \param[in]   syncGroupIndex      Index of synchronization group (needed to match signature).
 *   \return      Based on state evaluation:
 *                  - STOP     if no job is currently queued
 *                  - CONTINUE if a job was found in queue
 *   \pre         -
 *   \context     TASK
 *   \reentrant   FALSE
 *   \synchronous TRUE
 *********************************************************************************************************************/
MemAcc_MainFsm_ProcessingResultType MemAcc_MainFsm_SchedulingDo(MemAcc_SyncGroupIndexType syncGroupIndex);

#if (MEMACC_MULTIBINARY_ISMULTIBINARYUSECASE == STD_ON)

/**********************************************************************************************************************
 * MemAcc_MainFsm_MultiBinaryDispatchingEntry()
 *********************************************************************************************************************/
/*!  \brief       ENTRY action of MainFsm state MultiBinaryDispatching.
 *   \details     Dispatches the active job to the shared memory as access request.
 *   \param[in]   syncGroupIndex      Index of synchronization group (needed to match signature).
 *   \pre         The MemAcc_MainFsm_ActiveJob for the given syncGroupIndex must contain a valid MultiBinary job.
 *                The active job must have a valid job step to execute.
 *                MemAcc_MultiBinary_CanDispatchAccessRequest returns TRUE.
 *   \context     TASK
 *   \reentrant   FALSE
 *   \synchronous TRUE
 *********************************************************************************************************************/
void MemAcc_MainFsm_MultiBinaryDispatchingEntry(MemAcc_SyncGroupIndexType syncGroupIndex);

/**********************************************************************************************************************
 * MemAcc_MainFsm_MultiBinaryDispatchingDo()
 *********************************************************************************************************************/
/*!  \brief       DO action of MainFsm state MultiBinaryDispatching.
 *   \details     Waits for the master binary to approve the current pending direct MultiBinary access request.
 *   \param[in]   syncGroupIndex      Index of synchronization group (needed to match signature).
 *   \return      Based on state evaluation:
 *                  - STOP     the master binary did not approve the direct execution yet.
 *                  - CONTINUE the master binary approved the execution or it is a redirect request.
 *   \pre         MemAcc_MainFsm_MultiBinaryDispatchingEntry must be called beforehand.
 *   \context     TASK
 *   \reentrant   FALSE
 *   \synchronous TRUE
 *********************************************************************************************************************/
MemAcc_MainFsm_ProcessingResultType MemAcc_MainFsm_MultiBinaryDispatchingDo(MemAcc_SyncGroupIndexType syncGroupIndex);

#endif /* MEMACC_MULTIBINARY_ISMULTIBINARYUSECASE */

/**********************************************************************************************************************
 * MemAcc_MainFsm_ProcessingEntry()
 *********************************************************************************************************************/
/*!  \brief       ENTRY action of MainFsm state Processing.
 *   \details     Forwards single binary and direct jobs to Memory abstraction for dispatching.
 *   \param[in]   syncGroupIndex Index of currently processed Sync Group.
 *   \pre         -
 *   \context     TASK
 *   \reentrant   FALSE
 *   \synchronous TRUE
 *********************************************************************************************************************/
void MemAcc_MainFsm_ProcessingEntry(MemAcc_SyncGroupIndexType syncGroupIndex);

/**********************************************************************************************************************
 * MemAcc_MainFsm_ProcessingDo()
 *********************************************************************************************************************/
/*!  \brief       DO action of MainFsm state Processing.
 *   \details     Update job state.
 *   \param[in]   syncGroupIndex Index of currently processed Sync Group.
 *   \return      Based on state evaluation:
 *                  - STOP     if forwarded job was not yet finished by underlying layer
 *                  - CONTINUE if forwarded job was finished by underlying layer
 *   \pre         -
 *   \context     TASK
 *   \reentrant   FALSE
 *   \synchronous TRUE
 *********************************************************************************************************************/
MemAcc_MainFsm_ProcessingResultType MemAcc_MainFsm_ProcessingDo(MemAcc_SyncGroupIndexType syncGroupIndex);

#if (MEMACC_SUSPENDRESUME_ENABLED == STD_ON)

/**********************************************************************************************************************
 * MemAcc_MainFsm_CheckAndTryJobResumption()
 *********************************************************************************************************************/
/*! \brief       Check if the given job is suspended and resume it if needed.
 *  \details     -
 *  \param[in]   job - Pointer to the job.
 *  \return      TRUE if the job was resumed, FALSE otherwise.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
boolean MemAcc_MainFsm_CheckAndTryJobResumption(MemAcc_JobContextType* job);

/**********************************************************************************************************************
 * MemAcc_MainFsm_CheckAndTryJobSuspension()
 *********************************************************************************************************************/
/*! \brief       Check if the given job need to be suspended and suspend it if needed.
 *  \details     -
 *  \param[in]   job - Pointer to the job.
 *  \return      TRUE if the job was suspended, FALSE otherwise.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
boolean MemAcc_MainFsm_CheckAndTryJobSuspension(MemAcc_JobContextType* job);

#endif /* MEMACC_SUSPENDRESUME_ENABLED == STD_ON */

#define MEMACC_STOP_SEC_CODE
#include "MemAcc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/
#define MEMACC_START_SEC_CONST_UNSPECIFIED
#include "MemAcc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* state definitions */
/* PRQA S 3408 1 */ /* MD_MemAcc_LocalVariableExternalLinkage */
MEMACC_LOCAL const MemAcc_MainFsm_StateType MemAcc_MainFsm_SchedulingState = {
  &MemAcc_MainFsm_EntryNoOp,
  &MemAcc_MainFsm_SchedulingDo
};

/* PRQA S 3218, 1514 2 */ /* MD_MemAcc_StateDefinitionStaticUsedOnlyInSingleFunction */
/* PRQA S 3408 1 */ /* MD_MemAcc_LocalVariableExternalLinkage */
MEMACC_LOCAL const MemAcc_MainFsm_StateType MemAcc_MainFsm_ProcessingState = {
  &MemAcc_MainFsm_ProcessingEntry,
  &MemAcc_MainFsm_ProcessingDo
};

#if (MEMACC_MULTIBINARY_ISMULTIBINARYUSECASE == STD_ON)

/* PRQA S 3218, 1514 2 */ /* MD_MemAcc_StateDefinitionStaticUsedOnlyInSingleFunction */
/* PRQA S 3408 1 */ /* MD_MemAcc_LocalVariableExternalLinkage */
MEMACC_LOCAL const MemAcc_MainFsm_StateType MemAcc_MainFsm_MultiBinaryDispatchingState = {
  &MemAcc_MainFsm_MultiBinaryDispatchingEntry,
  &MemAcc_MainFsm_MultiBinaryDispatchingDo
};

#endif /* MEMACC_MULTIBINARY_ISMULTIBINARYUSECASE */

#define MEMACC_STOP_SEC_CONST_UNSPECIFIED
#include "MemAcc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define MEMACC_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemAcc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 3408 1 */ /* MD_MemAcc_LocalVariableExternalLinkage */
MEMACC_LOCAL MemAcc_JobContextType* MemAcc_MainFsm_ActiveJob[MEMACC_NUMBER_OF_SYNCHRONIZATION_GROUPS];

/* PRQA S 3408 1 */ /* MD_MemAcc_LocalVariableExternalLinkage */
MEMACC_LOCAL const MemAcc_MainFsm_StateType* MemAcc_MainFsm_CurrentState[MEMACC_NUMBER_OF_SYNCHRONIZATION_GROUPS];

#define MEMACC_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemAcc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
# define MEMACC_START_SEC_CODE
# include "MemAcc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * MemAcc_MainFsm_TransitionToState()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
void MemAcc_MainFsm_TransitionToState(
  const MemAcc_MainFsm_StateType* newStatePtr,
  MemAcc_SyncGroupIndexType syncGroupIndex)
{
  /* Perform state transition */
  MemAcc_MainFsm_CurrentState[syncGroupIndex] = newStatePtr;

  /* Enter new state */
  newStatePtr->Entry(syncGroupIndex); /* VCA_MEMACC_STATEPROXY */
}

/**********************************************************************************************************************
 * MemAcc_MainFsm_EntryNoOp()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
void MemAcc_MainFsm_EntryNoOp(MemAcc_SyncGroupIndexType syncGroupIndex)
{
  /* do nothing */
  MEMACC_DUMMY_STATEMENT(syncGroupIndex);
}

/**********************************************************************************************************************
 * MemAcc_MainFsm_SchedulingDo()
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
 *
 *
 */
MemAcc_MainFsm_ProcessingResultType MemAcc_MainFsm_SchedulingDo(MemAcc_SyncGroupIndexType syncGroupIndex)
{
  MemAcc_MainFsm_ProcessingResultType result = MEMACC_MAINFSM_PROCESSINGRESULT_STOP;

  MemAcc_JobContextType* nextJob = MemAcc_Queue_GetNextJob(syncGroupIndex);

  if(nextJob != NULL_PTR)
  {

#if (MEMACC_MULTIBINARY_ISMULTIBINARYUSECASE == STD_ON)

    MemAcc_AccessType accessType = MemAcc_GetAccessTypeOfSubAddressArea(nextJob->MngmtArea.JobStep.SubAddrAreaIdx);

    if(accessType != MEMACC_SINGLEBINARY_ACCESS)
    {
      /* If the multi binary job step cannot be dispatched to the shared memory it is ignored. */
      if(MemAcc_MultiBinary_CanDispatchAccessRequest() == TRUE)
      {
        MemAcc_MainFsm_ActiveJob[syncGroupIndex] = nextJob;
        MemAcc_MainFsm_TransitionToState(&MemAcc_MainFsm_MultiBinaryDispatchingState, syncGroupIndex);
        result = MEMACC_MAINFSM_PROCESSINGRESULT_CONTINUE;
      }
      else
      {
        /*
        * When a multi-binary job is available but dispatching is not allowed
        * (indicated by the sync token stop flag), the access request must be set
        * to NO_REQUEST. This ensures that the master binary can safely update
        * the synchronization token and switch to another binary.
        */
        MemAcc_MultiBinary_DispatchNoAccessRequest();
      }
    }
    else /* accessType == MEMACC_SINGLEBINARY_ACCESS */

#endif /* MEMACC_MULTIBINARY_ISMULTIBINARYUSECASE */

    {
      MemAcc_MainFsm_ActiveJob[syncGroupIndex] = nextJob;
      MemAcc_MainFsm_TransitionToState(&MemAcc_MainFsm_ProcessingState, syncGroupIndex);
      result = MEMACC_MAINFSM_PROCESSINGRESULT_CONTINUE;
    }
  }

#if (MEMACC_MULTIBINARY_ISMULTIBINARYUSECASE == STD_ON)

  else if(syncGroupIndex == MEMACC_MULTIBINARY_SYNCGROUPID)
  {
    /* In case no job is available for the multibinary sync group, publish this information to the shared memory. */
    MemAcc_MultiBinary_DispatchNoAccessRequest();

#if (MEMACC_MULTIBINARY_ISMASTERBINARY == STD_ON)
# if (MEMACC_MULTIBINARY_HASREDIRECTREQUESTS == STD_ON)
    MemAcc_MultiBinary_ProcessRedirectRequest();
# endif /* MEMACC_MULTIBINARY_HASREDIRECTREQUESTS */
#endif /* MEMACC_MULTIBINARY_ISMASTERBINARY */

  }
  else
  {
    /* Intentionally left empty. */
  }

#endif /* MEMACC_MULTIBINARY_ISMULTIBINARYUSECASE */

  return result;
}

#if (MEMACC_MULTIBINARY_ISMULTIBINARYUSECASE == STD_ON)

/**********************************************************************************************************************
 * MemAcc_MainFsm_MultiBinaryDispatchingEntry()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 * \spec
 *   requires MemAcc_MainFsm_ActiveJob[syncGroupIndex] == GetMemAccQueueRange();
 * \endspec
 */
void MemAcc_MainFsm_MultiBinaryDispatchingEntry(MemAcc_SyncGroupIndexType syncGroupIndex)
{
  MemAcc_JobProcessing_DispatchJobStepToSharedMemory(MemAcc_MainFsm_ActiveJob[syncGroupIndex]);

#if (MEMACC_MULTIBINARY_ISMASTERBINARY == STD_ON)

  /*
   * In case this is the master binary and there is currently no job being executed by another binary this
   * call can safe a main function cycle and the master binary can directly start processing the job.
   */
  MemAcc_MultiBinary_UpdateSynchronizationToken();

#endif /* MEMACC_MULTIBINARY_ISMASTERBINARY */
}

/**********************************************************************************************************************
 * MemAcc_MainFsm_MultiBinaryDispatchingDo()
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
 * \spec
 *   requires MemAcc_MainFsm_ActiveJob[syncGroupIndex] == GetMemAccQueueRange();
 * \endspec
 */
MemAcc_MainFsm_ProcessingResultType MemAcc_MainFsm_MultiBinaryDispatchingDo(MemAcc_SyncGroupIndexType syncGroupIndex)
{
  MemAcc_MainFsm_ProcessingResultType result = MEMACC_MAINFSM_PROCESSINGRESULT_STOP;

  boolean isDirect = MemAcc_MultiBinary_IsDirectRequest();

  /*
   * If the direct job is canceled by the user while awaiting approval from the master binary,
   * the job type will be set to NO_JOB in accordance with the cancellation behavior.
   */
  if((MemAcc_MainFsm_ActiveJob[syncGroupIndex]->JobArea.JobType == (MemAcc_AtomicJobType)MEMACC_NO_JOB)
      && (isDirect == TRUE))
  {
    MemAcc_MainFsm_TransitionToState(&MemAcc_MainFsm_SchedulingState, syncGroupIndex);
    result = MEMACC_MAINFSM_PROCESSINGRESULT_CONTINUE;
  }
  else
  {
    boolean isRedirect = MemAcc_MultiBinary_IsRedirectRequest();
    boolean isActiveBinary = MemAcc_MultiBinary_IsActiveBinary();

    /* Redirect requests are directly passed through, since they are handled by the master binary. */
    if(((isDirect == TRUE) && (isActiveBinary == TRUE)) || (isRedirect == TRUE))
    {
      MemAcc_MainFsm_TransitionToState(&MemAcc_MainFsm_ProcessingState, syncGroupIndex);
      result = MEMACC_MAINFSM_PROCESSINGRESULT_CONTINUE;
    }

#if (MEMACC_MULTIBINARY_ISMASTERBINARY == STD_ON)
# if (MEMACC_MULTIBINARY_HASREDIRECTREQUESTS == STD_ON)

    else
    {
      MemAcc_MultiBinary_ProcessRedirectRequest();
    }

# endif /* MEMACC_MULTIBINARY_HASREDIRECTREQUESTS */
#endif /* MEMACC_MULTIBINARY_ISMASTERBINARY */

  }

  return result;
}

#endif /* MEMACC_MULTIBINARY_ISMULTIBINARYUSECASE */

/**********************************************************************************************************************
 * MemAcc_MainFsm_ProcessingEntry()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 * \spec
 *   requires MemAcc_MainFsm_ActiveJob[syncGroupIndex] == GetMemAccQueueRange();
 * \endspec
 */
void MemAcc_MainFsm_ProcessingEntry(MemAcc_SyncGroupIndexType syncGroupIndex)
{
#if (MEMACC_MULTIBINARY_ISSATELLITEBINARY == STD_ON)

  /* Redirect jobs dont need to be dispatched to mem since master binary is responsible for them. */
  if (MemAcc_GetAccessTypeOfSubAddressArea(MemAcc_MainFsm_ActiveJob[syncGroupIndex]->MngmtArea.JobStep.SubAddrAreaIdx)
    != MEMACC_MULTIBINARY_REDIRECT_ACCESS)

#endif /* MEMACC_MULTIBINARY_ISSATELLITEBINARY */

  {

#if (MEMACC_SUSPENDRESUME_ENABLED == STD_ON)

    if (MemAcc_MainFsm_CheckAndTryJobResumption(MemAcc_MainFsm_ActiveJob[syncGroupIndex]) == FALSE)

#endif /* MEMACC_SUSPENDRESUME_ENABLED == STD_ON */

    {
      MemAcc_JobProcessing_DispatchJobStepToMem(MemAcc_MainFsm_ActiveJob[syncGroupIndex]);
    }
  }
}

/**********************************************************************************************************************
 * MemAcc_MainFsm_ProcessingDo()
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
 * \spec
 *   requires MemAcc_MainFsm_ActiveJob[syncGroupIndex] == GetMemAccQueueRange();
 * \endspec
 */
MemAcc_MainFsm_ProcessingResultType MemAcc_MainFsm_ProcessingDo(MemAcc_SyncGroupIndexType syncGroupIndex)
{
  MemAcc_MainFsm_ProcessingResultType result = MEMACC_MAINFSM_PROCESSINGRESULT_STOP;

  MemAcc_JobProcessing_UpdateJobStep(MemAcc_MainFsm_ActiveJob[syncGroupIndex]);

  if (MemAcc_MainFsm_ActiveJob[syncGroupIndex]->MngmtArea.JobStep.Status == MEMACC_JOB_PENDING)
  {

#if (MEMACC_SUSPENDRESUME_ENABLED == STD_ON)

    if (MemAcc_MainFsm_CheckAndTryJobSuspension(MemAcc_MainFsm_ActiveJob[syncGroupIndex]) == TRUE)
    {
      MemAcc_MainFsm_TransitionToState(&MemAcc_MainFsm_SchedulingState, syncGroupIndex);
      result = MEMACC_MAINFSM_PROCESSINGRESULT_CONTINUE;
    }

#endif /* MEMACC_SUSPENDRESUME_ENABLED == STD_ON */

  }
  else
  {
    MemAcc_MainFsm_TransitionToState(&MemAcc_MainFsm_SchedulingState, syncGroupIndex);
    result = MEMACC_MAINFSM_PROCESSINGRESULT_CONTINUE;
  }

  return result;
}

#if (MEMACC_SUSPENDRESUME_ENABLED == STD_ON)

/*********************************************************************************************************************
 * MemAcc_MainFsm_CheckAndTryJobResumption()
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
 * \spec
 *   requires job != NULL_PTR;
 * \endspec
 */
boolean MemAcc_MainFsm_CheckAndTryJobResumption(MemAcc_JobContextType* job)
{
  boolean wasResumed = FALSE;

  if (job->MngmtArea.JobStep.IsSuspended == TRUE)
  {
    MemAcc_LowerLayerIndexType lowerLayerIndex = MemAcc_GetLowerLayerIdxOfSubAddressArea(job->MngmtArea.JobStep.SubAddrAreaIdx);
    /*@ assert lowerLayerIndex < MemAcc_GetSizeOfLowerLayer(); */  /* VCA_MemAcc_LowerLayerIndexAlwaysValid */

    wasResumed = MemAcc_MemAb_InvokeResume(lowerLayerIndex, MemAcc_GetInstanceIdOfMemInstance(
      MemAcc_GetMemInstanceIdxOfSubAddressArea(job->MngmtArea.JobStep.SubAddrAreaIdx))) == E_OK;

    job->MngmtArea.JobStep.IsSuspended = FALSE;
  }

  return wasResumed;
}

/*********************************************************************************************************************
 * MemAcc_MainFsm_CheckAndTryJobSuspension()
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
 * \spec
 *   requires job != NULL_PTR;
 * \endspec
 */
boolean MemAcc_MainFsm_CheckAndTryJobSuspension(MemAcc_JobContextType* job)
{
  boolean wasSuspended = FALSE;

#if (MEMACC_MULTIBINARY_ISSATELLITEBINARY == STD_ON)

  /* Redirect jobs cannot be suspended. */
  if (MemAcc_GetAccessTypeOfSubAddressArea(job->MngmtArea.JobStep.SubAddrAreaIdx) != MEMACC_MULTIBINARY_REDIRECT_ACCESS)

#endif /* MEMACC_MULTIBINARY_ISSATELLITEBINARY */

  {
    if (MemAcc_Queue_IsSuspensionNeededAndAllowed(
      MemAcc_GetHardwareIdOfMemInstance(MemAcc_GetMemInstanceIdxOfSubAddressArea(job->MngmtArea.JobStep.SubAddrAreaIdx)),
      job->JobArea.AddressAreaIndex,
      MemAcc_Utils_IsInternalJob(job->JobArea.JobClassification)) == TRUE)
    {
      MemAcc_LowerLayerIndexType lowerLayerIndex = MemAcc_GetLowerLayerIdxOfSubAddressArea(job->MngmtArea.JobStep.SubAddrAreaIdx);
      /*@ assert lowerLayerIndex < MemAcc_GetSizeOfLowerLayer(); */  /* VCA_MemAcc_LowerLayerIndexAlwaysValid */

      if (MemAcc_MemAb_InvokeSuspend(lowerLayerIndex, MemAcc_GetInstanceIdOfMemInstance(
        MemAcc_GetMemInstanceIdxOfSubAddressArea(job->MngmtArea.JobStep.SubAddrAreaIdx))) == E_OK)
      {
        job->MngmtArea.JobStep.IsSuspended = TRUE;
        wasSuspended = TRUE;
      }
    }
  }

  return wasSuspended;
}

#endif /* MEMACC_SUSPENDRESUME_ENABLED == STD_ON */

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * MemAcc_MainFsm_Reset()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
void MemAcc_MainFsm_Reset(void)
{
  for (MemAcc_SyncGroupIndexType syncGroupIndex = 0; syncGroupIndex < MEMACC_NUMBER_OF_SYNCHRONIZATION_GROUPS; syncGroupIndex++)
  {
    MemAcc_MainFsm_CurrentState[syncGroupIndex] = &MemAcc_MainFsm_SchedulingState;
    MemAcc_MainFsm_ActiveJob[syncGroupIndex] = NULL_PTR;
  }
}

/**********************************************************************************************************************
 * MemAcc_MainFsm_ProcessAllSyncGroups()
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
void MemAcc_MainFsm_ProcessAllSyncGroups(void)
{
  MemAcc_Queue_PopCanceledJobs();

#if (MEMACC_MULTIBINARY_ISMASTERBINARY == STD_ON)

  MemAcc_MultiBinary_UpdateSynchronizationToken();
  /*
   * Redirected job are processed within the MainFsm state machine in the multi binary synchronization group.
   * Two of the states are therefore relevant where the redirect jobs can be processed:
   * - Scheduling, when no master job is at all in the queue.
   * - Dispatching, when redirect job has higher priority as master job.
   * Within processing state no redirect job needs to be processed by design as token is set to master.
   */
#endif /* MEMACC_MULTIBINARY_ISMASTERBINARY */

  /*@ unroll MEMACC_NUMBER_OF_SYNCHRONIZATION_GROUPS; */
  for (MemAcc_SyncGroupIndexType syncGroupIndex = 0; syncGroupIndex < MEMACC_NUMBER_OF_SYNCHRONIZATION_GROUPS; syncGroupIndex++)
  {
    MemAcc_MainFsm_ProcessingResultType processResult = MEMACC_MAINFSM_PROCESSINGRESULT_CONTINUE;

    while (processResult == MEMACC_MAINFSM_PROCESSINGRESULT_CONTINUE)
    {
      processResult = MemAcc_MainFsm_CurrentState[syncGroupIndex]->Do(syncGroupIndex); /* VCA_MEMACC_STATEPROXY */
    }
  }

#if (MEMACC_MULTIBINARY_ISMASTERBINARY == STD_ON)

  /*
   * Updating the sync token here improves performance.
   * If a multibinary job finishes before this call, or if a new job is added to the queue,
   * the priority can be checked, and the stop flag can potentially be set.
   * If the stop flag is set at this point, the corresponding satellite might be executed before the next
   * master MainFunction call. This allows the binary ID in the sync token to be updated during the next master MainFunction cycle.
   */
  MemAcc_MultiBinary_UpdateSynchronizationToken();

#endif /* MEMACC_MULTIBINARY_ISMASTERBINARY */

}

#define MEMACC_STOP_SEC_CODE
#include "MemAcc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  MISRA JUSTIFICATIONS
 **********************************************************************************************************************/

/* Justification for module-specific MISRA deviations:

MD_MemAcc_StateDefinitionStaticUsedOnlyInSingleFunction: rule 8.9
  Reason:     State pointers are stored in MemAcc_MainFsm_CurrentState and must remain valid
              over multiple main function cycles.
  Risk:       None.
  Prevention: No preventions, as there is no risk.

*/

/***********************************************************************************************************************
 *  VCA JUSTIFICATIONS
 **********************************************************************************************************************/
/* VCA_JUSTIFICATION_BEGIN

\ID VCA_MEMACC_STATEPROXY
  \DESCRIPTION The MemAcc stores for each configured synchronisation group a pointer to the current state within
             MemAcc_MainFsm_CurrentState. A state itself consists of two function pointers (entry and do).
             MemAcc_MainFsm_CurrentState must refer to a valid state and the state itself must contain valid
             function pointers.
             Furthermore, the Processing State Do Action has a formal specification which requires the global
             MemAcc_MainFsm_ActiveJob array to be in range of the given queue jobs.
             It must be ensured that the active job is always popped from the queue.
  \COUNTERMEASURE \R A runtime check within the MemAcc_MainFunction will ensure that the MemAcc_MainFsm_CurrentState
                   pointer will be only used when the component was initialized, therefore the MemAcc_MainFsm_CurrentState
                   is set to a valid state.
                   The different states and its assigned function pointers are pre-defined within const variables
                   and are therefore always available and correct.
                  \T All Test Cases within CT__Services test fixture:
                   The current state pointer will only be set to valid states during execution, so calling
                   a null pointer is therefore excluded. Also the active job is always popped from the queue.
                   Correct behaviour is ensured by component testing, where complete jobs are processed for
                   all possible scenarios.

VCA_JUSTIFICATION_END */

/**********************************************************************************************************************
 *  END OF FILE: MemAcc_MainFsm.c
 *********************************************************************************************************************/
