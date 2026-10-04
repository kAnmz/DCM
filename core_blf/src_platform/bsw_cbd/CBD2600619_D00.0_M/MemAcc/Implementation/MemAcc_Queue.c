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
/*!        \file  MemAcc_Queue.c
 *        \brief  MemAcc_Queue source file
 *      \details  Implementation of the Queue unit of the MemAcc.
 *         \unit  Queue
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/


#define MEMACC_QUEUE_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "MemAcc_Queue.h"
#include "MemAcc_Utils.h"
#include "MemAcc_JobProcessing.h"
#include "MemAcc_BBM.h"

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
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/
#define MEMACC_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemAcc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 3408 3 */ /* MD_MemAcc_LocalVariableExternalLinkage */
MEMACC_LOCAL MemAcc_JobContextType MemAcc_User_Queue[MemAcc_GetSizeOfAddressArea()];      /* Stores all jobs queued from the User via MemAcc.h. */
MEMACC_LOCAL MemAcc_JobContextType MemAcc_Internal_Queue[MemAcc_GetSizeOfAddressArea()];  /* Stores all jobs queued internally. */
MEMACC_LOCAL MemAcc_MemLockStateType MemAcc_MemInstanceLockStates[MEMACC_NUMBER_OF_HARDWARE_IDS];

#define MEMACC_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemAcc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
# define MEMACC_START_SEC_CODE
# include "MemAcc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if (MEMACC_COMPAREAPI_ENABLED == STD_ON)

/**********************************************************************************************************************
 * MemAcc_Queue_IsCompareJobDispatched()
 *********************************************************************************************************************/
/*! \brief         Checks if there is a higher priority or pending compare job in queue.
 *  \details       -
 *  \param[in]     priority - Priority to check against.
 *  \return        TRUE   Higher Prio or Pending compare job exists.
 *                 FALSE  Otherwise
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
MEMACC_LOCAL boolean MemAcc_Queue_HasHigherPrioOrPendingCompareJob(const MemAcc_PriorityOfAddressAreaType priority);

#endif /* (MEMACC_COMPAREAPI_ENABLED == STD_ON) */

/**********************************************************************************************************************
 * MemAcc_Queue_JobUsesLowerLayerIdx()
 *********************************************************************************************************************/
/*! \brief         Checks if the given job targets the given lower layer index.
 *  \details       -
 *  \param[in]     job - Job Area.
 *  \param[in]     llIdx - Lower layer index.
 *  \return        TRUE   Uses the llIdx
 *                 FALSE  Otherwise
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
MEMACC_LOCAL boolean MemAcc_Queue_JobUsesLowerLayerIdx(MemAcc_JobAreaType job, MemAcc_LowerLayerIndexType llIdx);

/**********************************************************************************************************************
 * MemAcc_Queue_IsMemInstancePending()
 *********************************************************************************************************************/
/*! \brief         Checks if the MemInstance defined by the HwId is currently pending.
 *  \details       -
 *  \param[in]     hwId hardware Id of the MemInstance.
 *  \return        TRUE   MemInstance is Idle
 *                 FALSE  MemInstance is Pending
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
MEMACC_LOCAL boolean MemAcc_Queue_IsMemInstancePending(MemAcc_HwIdType hwId);

/**********************************************************************************************************************
 * MemAcc_Queue_ProcessLockRequest()
 *********************************************************************************************************************/
/*! \brief         Checks that all affected Mem driver instances are currently unlocked and idle, then locks them.
 *  \details       -
 *  \param[in]     lockJob Pointer to the job with the lock request.
 *  \pre           Given job is a lock request.
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
MEMACC_LOCAL void MemAcc_Queue_ProcessLockRequest(MemAcc_JobContextType* lockJob);

/**********************************************************************************************************************
 * MemAcc_Queue_ResetJob()
 *********************************************************************************************************************/
/*! \brief         Resets the job for the specified address area index.
 *  \details       This function resets the job context for a given address area index.
 *  \param[in]     job    Pointer to the job context to reset.
 *  \param[in]     aaIdx  Address area index for which the job needs to be reset.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
MEMACC_LOCAL void MemAcc_Queue_ResetJob(MemAcc_JobContextType* job, MemAcc_AddressAreaIndexType aaIdx);

/**********************************************************************************************************************
 * MemAcc_Queue_GetQueuedJob()
 *********************************************************************************************************************/
/*! \brief         Retrieves a queued job based on if it is a internal job and priority.
 *  \details       This function returns a pointer to a job context from either the user queue or the internal queue,
 *                 depending on whether the job is internal or not, and based on the specified priority.
 *  \param[in]     isInternalJob  Boolean indicating if the job is a internal or user job.
 *  \param[in]     priority       Priority of the job.
 *  \return        Pointer to the job context corresponding to the specified parameters.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
MEMACC_LOCAL MemAcc_JobContextType* MemAcc_Queue_GetQueuedJob(boolean isInternalJob, MemAcc_JobPriorityIndexType priority);

/**********************************************************************************************************************
 * MemAcc_Queue_GetOrExecuteJob()
 *********************************************************************************************************************/
/*! \brief         Retrieves or executes a job based on sync group index, job type, and priority.
 *  \details       This function retrieves a queued job if it matches the specified sync group index, job type, and
 *                 priority. If the job is a lock request and the conditions are met, it processes the lock request.
 *  \param[in]     syncGroupIndex  Index of the synchronization group.
 *  \param[in]     isInternalJob   Boolean indicating if the job is internal.
 *  \param[in]     priority        Priority level of the job.
 *  \return        Pointer to the job context if the job can be executed, otherwise NULL_PTR.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
MEMACC_LOCAL MemAcc_JobContextType* MemAcc_Queue_GetOrExecuteJob(
  MemAcc_SyncGroupIndexType syncGroupIndex,
  boolean isInternalJob,
  MemAcc_JobPriorityIndexType priority);

/**********************************************************************************************************************
 * MemAcc_Queue_ProcessJobResultByClassification()
 *********************************************************************************************************************/
/*! \brief       In case the job has completed, process potential followup actions.
 *  \details     -
 *  \param[in]   job - Pointer to the job.
 *  \pre         Job was completed and popped from the queue.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
MEMACC_LOCAL void MemAcc_Queue_ProcessJobResultByClassification(const MemAcc_JobContextType* job);

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

#if (MEMACC_COMPAREAPI_ENABLED == STD_ON)

/**********************************************************************************************************************
 *  MemAcc_Queue_HasHigherPrioOrPendingCompareJob()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
MEMACC_LOCAL boolean MemAcc_Queue_HasHigherPrioOrPendingCompareJob(const MemAcc_PriorityOfAddressAreaType priority)
{
  boolean ret = FALSE;

  for (MemAcc_AddressAreaIndexType aaIdx = 0u; aaIdx < MemAcc_GetSizeOfAddressArea(); aaIdx++)
  {
    /* Internal Queue cannot have compare jobs. */
    const MemAcc_JobContextType *userJob = &MemAcc_User_Queue[aaIdx];

    if ((userJob->JobArea.JobType == (MemAcc_AtomicJobType)MEMACC_COMPARE_JOB)
        && ((userJob->MngmtArea.JobStep.Status == MEMACC_JOB_PENDING)
          || (priority < MemAcc_GetPriorityOfAddressArea(userJob->JobArea.AddressAreaIndex))))
    {
      ret = TRUE;
      break;
    }
  }

  return ret;
}

#endif /* (MEMACC_COMPAREAPI_ENABLED == STD_ON) */

/**********************************************************************************************************************
 *  MemAcc_Queue_JobUsesLowerLayerIdx()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
MEMACC_LOCAL boolean MemAcc_Queue_JobUsesLowerLayerIdx(MemAcc_JobAreaType job, MemAcc_LowerLayerIndexType llIdx)
{
  boolean retVal = FALSE;
  MemAcc_LengthType length = job.Length;
  MemAcc_AddressType address = job.Address;
  MemAcc_SubAddressAreaIndexType subAddressAreaIndex;

  while (MemAcc_Utils_GetSAAIndicesForAddressRange(job.AddressAreaIndex, &address, &length, &subAddressAreaIndex))
  {
    if (MemAcc_GetLowerLayerIdxOfSubAddressArea(subAddressAreaIndex) == llIdx)
    {
      retVal = TRUE;
      break;
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  MemAcc_Queue_IsMemInstancePending()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
MEMACC_LOCAL boolean MemAcc_Queue_IsMemInstancePending(MemAcc_HwIdType hwId)
{
  boolean ret = FALSE;

  for (MemAcc_AddressAreaIndexType tempIndex = 0; tempIndex < MemAcc_GetSizeOfAddressArea(); tempIndex++)
  {
    if(((MemAcc_User_Queue[tempIndex].MngmtArea.JobStep.Status == MEMACC_JOB_PENDING)
        && (MemAcc_GetHardwareIdOfMemInstance(MemAcc_GetMemInstanceIdxOfSubAddressArea(
          MemAcc_User_Queue[tempIndex].MngmtArea.JobStep.SubAddrAreaIdx)) == hwId))
      || ((MemAcc_Internal_Queue[tempIndex].MngmtArea.JobStep.Status == MEMACC_JOB_PENDING)
        && (MemAcc_GetHardwareIdOfMemInstance(MemAcc_GetMemInstanceIdxOfSubAddressArea(
          MemAcc_Internal_Queue[tempIndex].MngmtArea.JobStep.SubAddrAreaIdx)) == hwId)))
    {
      ret = TRUE;
      break;
    }
  }

  return ret;
}

/**********************************************************************************************************************
 *  MemAcc_Queue_ProcessLockRequest()
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
 *   requires lockJob != NULL_PTR;
 * \endspec
 */
MEMACC_LOCAL void MemAcc_Queue_ProcessLockRequest(
  MemAcc_JobContextType* lockJob)
{
  MemAcc_LengthType length = lockJob->JobArea.Length;
  MemAcc_AddressType address = lockJob->JobArea.Address;
  MemAcc_SubAddressAreaIndexType subAddressAreaIndex;
  boolean allMemInstancesUnlockedAndIdle = TRUE;

  /* Iterate over all affected sub address areas */
  while (MemAcc_Utils_GetSAAIndicesForAddressRange(lockJob->JobArea.AddressAreaIndex, &address, &length, &subAddressAreaIndex) == TRUE)
  {
    /* Check the respective underlying Mem Instance */
    MemAcc_HwIdType hwId = MemAcc_GetHardwareIdOfMemInstance(MemAcc_GetMemInstanceIdxOfSubAddressArea(subAddressAreaIndex));
    if ((uint32) hwId < MEMACC_NUMBER_OF_HARDWARE_IDS)
    {
      /* Check that the Mem Instance is UNLOCKED to avoid nested locks.
         Check also that the Mem Instance is IDLE to consider the scenario that currently
         a job step is pending for this mem instance within another sync group. */
      if ((MemAcc_Queue_IsMemInstancePending(hwId) == TRUE) || (MemAcc_MemInstanceLockStates[hwId] == MEMACC_LOCKSTATE_LOCKED))
      {
        allMemInstancesUnlockedAndIdle = FALSE;
        break;
      }
    }
  }

  if (allMemInstancesUnlockedAndIdle == TRUE)
  {
    /* Reset the length and address values as they are modified by the iterator function above */
    length = lockJob->JobArea.Length;
    address = lockJob->JobArea.Address;

    while (MemAcc_Utils_GetSAAIndicesForAddressRange(lockJob->JobArea.AddressAreaIndex, &address, &length, &subAddressAreaIndex) == TRUE)
    {
      /* Lock the respective underlying Mem */
      MemAcc_HwIdType hwId = MemAcc_GetHardwareIdOfMemInstance(MemAcc_GetMemInstanceIdxOfSubAddressArea(subAddressAreaIndex));
      if ((uint32) hwId < MEMACC_NUMBER_OF_HARDWARE_IDS)
      {
        MemAcc_MemInstanceLockStates[hwId] = MEMACC_LOCKSTATE_LOCKED;
      }
    }

    if (lockJob->JobArea.LockNotificationFctPtr != NULL_PTR)
    {
      /* VCA Line+1 SLC-10, SLC-22 : VCA_MemAcc_LockNotificationInvocation */
      lockJob->JobArea.LockNotificationFctPtr();
    }

    MemAcc_Queue_PopJob(lockJob);
  }
}

/**********************************************************************************************************************
 * MemAcc_Queue_ResetJob()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 * \spec
 *   requires job != NULL_PTR;
 * \endspec
 */
MEMACC_LOCAL void MemAcc_Queue_ResetJob(MemAcc_JobContextType* job, MemAcc_AddressAreaIndexType aaIdx)
{
  job->JobArea.AddressAreaIndex = aaIdx;
  job->JobArea.JobType = (MemAcc_AtomicJobType)MEMACC_NO_JOB;
  job->JobArea.Address = 0u;
  job->JobArea.Length = 0u;
  job->JobArea.DataBuffer = NULL_PTR;
  job->JobArea.ConstDataBuffer = NULL_PTR;
  job->JobArea.HwId = (MemAcc_HwIdType) 0u;    /* PRQA S 4342 */ /* MD_MemAcc_HwIdEnumCasting */
  job->JobArea.HwServiceId = 0u;
  job->JobArea.LengthPtr = NULL_PTR;
  job->JobArea.LockNotificationFctPtr = NULL_PTR;
  job->JobArea.JobClassification = MEMACC_JOBCLASSIFICATION_USERJOB;

  job->MngmtArea.JobResult = MEMACC_OK;
  job->MngmtArea.Offset = 0u;
  job->MngmtArea.ReadJobEccCorrected = FALSE;
  job->MngmtArea.JobCanceled = FALSE;
  job->MngmtArea.JobError = MEMACC_ERRORTYPE_NONE;

  job->MngmtArea.JobStep.Status = MEMACC_JOB_IDLE;
  job->MngmtArea.JobStep.Result = MEMACC_OK;
  job->MngmtArea.JobStep.SubAddrAreaIdx = 0u;
  job->MngmtArea.JobStep.LogicalAddress = 0u;
  job->MngmtArea.JobStep.PhysicalAddress = 0u;
  job->MngmtArea.JobStep.Length = 0u;
  job->MngmtArea.JobStep.IsSuspended = FALSE;
  job->MngmtArea.JobStep.RetryCounter = 0u;
  job->MngmtArea.JobStep.Rejected = FALSE;
#if (MEMACC_BBM_ENABLED == STD_ON)
  job->MngmtArea.JobStep.MemError = MEMACC_MEMERRORTYPE_NONE;
#endif /* (MEMACC_BBM_ENABLED == STD_ON) */
}

/**********************************************************************************************************************
 * MemAcc_Queue_GetQueuedJob()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
MEMACC_LOCAL MemAcc_JobContextType* MemAcc_Queue_GetQueuedJob(boolean isInternalJob, MemAcc_JobPriorityIndexType priority)
{
  return (isInternalJob == FALSE) ? &MemAcc_User_Queue[priority] : &MemAcc_Internal_Queue[priority];
}

/**********************************************************************************************************************
 * MemAcc_Queue_GetOrExecuteJob()
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
MEMACC_LOCAL MemAcc_JobContextType* MemAcc_Queue_GetOrExecuteJob(MemAcc_SyncGroupIndexType syncGroupIndex,
  boolean isInternalJob,
  MemAcc_JobPriorityIndexType priority)
{
  MemAcc_JobContextType* jobContext = NULL_PTR;
  MemAcc_JobContextType* job = MemAcc_Queue_GetQueuedJob(isInternalJob, priority);

  if ((job->JobArea.JobType != (MemAcc_AtomicJobType)MEMACC_NO_JOB)
    && (MemAcc_GetSyncGroupIdOfSubAddressArea(job->MngmtArea.JobStep.SubAddrAreaIdx) == syncGroupIndex))
  {
    boolean setJobContext = TRUE;

    if (job->JobArea.JobType == (MemAcc_AtomicJobType)MEMACC_REQUESTLOCK_JOB)
    {
      MemAcc_Queue_ProcessLockRequest(job);
      setJobContext = FALSE;
    }

    MemAcc_HwIdType hwId = MemAcc_GetHardwareIdOfMemInstance(MemAcc_GetMemInstanceIdxOfSubAddressArea(job->MngmtArea.JobStep.SubAddrAreaIdx));
    if (((uint32) hwId < MEMACC_NUMBER_OF_HARDWARE_IDS) && (MemAcc_MemInstanceLockStates[hwId] != MEMACC_LOCKSTATE_UNLOCKED))
    {
      setJobContext = FALSE;
    }

#if (MEMACC_COMPAREAPI_ENABLED == STD_ON)

    if (job->JobArea.JobType == (MemAcc_AtomicJobType)MEMACC_COMPARE_JOB)
    {
      /* For reduced footprint only one compare buffer exists. Therefore only one compare job can be processed at a time. */
      if (MemAcc_Queue_HasHigherPrioOrPendingCompareJob(MemAcc_GetPriorityOfAddressArea(job->JobArea.AddressAreaIndex)))
      {
        setJobContext = FALSE;
      }
    }

#endif /* (MEMACC_COMPAREAPI_ENABLED == STD_ON) */

    if (setJobContext)
    {
      jobContext = job;
    }
  }

  return jobContext;
}

/**********************************************************************************************************************
 * MemAcc_Queue_ProcessJobResultByClassification()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 * \spec
 *   requires job != NULL_PTR;
 * \endspec
 */
MEMACC_LOCAL void MemAcc_Queue_ProcessJobResultByClassification(const MemAcc_JobContextType* job)
{
#if (MEMACC_BBM_ENABLED == STD_ON)

  if(job->JobArea.JobClassification != MEMACC_JOBCLASSIFICATION_USERJOB)
  {
#if !defined(MEMACC_VCA_SILENT) /* COV_MEMACC_VCA */
    /* VCA Disable SLC-10, SLC-11, SLC-22 : VCA_MemAcc_DisabledFunctionCallToProcessInternalJobResult */
    MemAcc_BBM_ProcessInternalJobResult(job);
    /* VCA Enable : VCA_MemAcc_DisabledFunctionCallToProcessInternalJobResult */
#endif
  }

#else

  /* do nothing */
  MEMACC_DUMMY_STATEMENT(job);

#endif /* (MEMACC_BBM_ENABLED == STD_ON) */
}

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * MemAcc_Queue_Reset
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
void MemAcc_Queue_Reset(void)
{
  for (MemAcc_AddressAreaIndexType aaIdx = 0; aaIdx < MemAcc_GetSizeOfAddressArea(); aaIdx++)
  {
    MemAcc_JobPriorityIndexType priority = MemAcc_GetPriorityBasedIndexOfAddressArea(aaIdx);

    MemAcc_Queue_ResetJob(&MemAcc_User_Queue[priority], aaIdx);
    MemAcc_Queue_ResetJob(&MemAcc_Internal_Queue[priority], aaIdx);
  }

  for (uint32 hwId = 0; hwId < MEMACC_NUMBER_OF_HARDWARE_IDS; hwId++)
  {
    MemAcc_MemInstanceLockStates[hwId] = MEMACC_LOCKSTATE_UNLOCKED;
  }
}

/**********************************************************************************************************************
 * MemAcc_Queue_PushJob
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
Std_ReturnType MemAcc_Queue_PushJob(const MemAcc_JobAreaType* newJob)
{
  Std_ReturnType result = E_NOT_OK;

  MemAcc_JobContextType *job = MemAcc_Queue_GetQueuedJob(
    MemAcc_Utils_IsInternalJob(newJob->JobClassification),
    MemAcc_GetPriorityBasedIndexOfAddressArea(newJob->AddressAreaIndex));

  if(job->JobArea.JobType == (MemAcc_AtomicJobType)MEMACC_NO_JOB)
  {
    result = MemAcc_JobProcessing_CalculateNextJobStep(newJob, &job->MngmtArea.JobStep, 0u, TRUE);

    if (result == E_OK)
    {
      /*!
       * MEMACC_DEBUG_BREAKPOINT:
       * This breakpoint can be used to debug check when jobs are pushed into the queue for processing.
       * These come either from the public functions in MemAcc.c|h or from internal processing requirements e.g. BBM.
       */

      job->MngmtArea.JobStep.Status = MEMACC_JOB_IDLE;
      job->MngmtArea.ReadJobEccCorrected = FALSE;
      job->MngmtArea.JobCanceled = FALSE;
      job->MngmtArea.Offset = 0u;
      job->MngmtArea.JobError = MEMACC_ERRORTYPE_NONE;

      job->JobArea.Address = newJob->Address;
      job->JobArea.Length = newJob->Length;
      job->JobArea.DataBuffer = newJob->DataBuffer;
      job->JobArea.ConstDataBuffer = newJob->ConstDataBuffer;
      job->JobArea.HwId = newJob->HwId;
      job->JobArea.HwServiceId = newJob->HwServiceId;
      job->JobArea.LengthPtr = newJob->LengthPtr;

      job->JobArea.JobClassification = newJob->JobClassification;
      job->JobArea.JobType = newJob->JobType;
    }
  }

  return result;
}

/**********************************************************************************************************************
 * MemAcc_Queue_PopJob
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
 *   requires job != NULL_PTR;
 * \endspec
 */
void MemAcc_Queue_PopJob(MemAcc_JobContextType* job)
{
  if (job->JobArea.JobType != (MemAcc_AtomicJobType)MEMACC_NO_JOB)
  {
    job->JobArea.DataBuffer = NULL_PTR;
    job->JobArea.ConstDataBuffer = NULL_PTR;
    job->JobArea.LockNotificationFctPtr = NULL_PTR;
    job->JobArea.JobType = (MemAcc_AtomicJobType)MEMACC_NO_JOB;

    /* Invoke the Job End Notication callback function if defined. Not for internal jobs. */
    if ((MemAcc_Utils_IsInternalJob(job->JobArea.JobClassification) == FALSE)
      && (MemAcc_GetJobEndNotificationOfAddressArea(job->JobArea.AddressAreaIndex) != NULL_PTR))
    {
      /* VCA Line+1 SLC-20, SLC-22 : VCA_MemAcc_JobEndNotificationInvocation */
      MemAcc_GetJobEndNotificationOfAddressArea(job->JobArea.AddressAreaIndex)(
        MemAcc_GetAddressAreaIdOfAddressArea(job->JobArea.AddressAreaIndex), job->MngmtArea.JobResult);
    }

    if ((MemAcc_GetErrorNotificationOfAddressArea(job->JobArea.AddressAreaIndex) != NULL_PTR)
      && (job->MngmtArea.JobError != MEMACC_ERRORTYPE_NONE))
    {
      /* VCA Line+1 SLC-20, SLC-22 : VCA_MemAcc_ErrorNotificationInvocation */
      MemAcc_GetErrorNotificationOfAddressArea(job->JobArea.AddressAreaIndex)(
        MemAcc_GetAddressAreaIdOfAddressArea(job->JobArea.AddressAreaIndex), job->MngmtArea.JobError);
    }

    MemAcc_Queue_ProcessJobResultByClassification(job);
  }
}

/**********************************************************************************************************************
 * MemAcc_Queue_PopCanceledJobs
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
void MemAcc_Queue_PopCanceledJobs(void)
{
  for(MemAcc_AddressAreaIndexType aaIdx = 0; aaIdx < MemAcc_GetSizeOfAddressArea(); aaIdx++)
  {
    MemAcc_JobContextType* userJob = &MemAcc_User_Queue[aaIdx];
    const MemAcc_JobContextType* internalJob = &MemAcc_Internal_Queue[aaIdx];

    if((userJob->MngmtArea.JobCanceled == TRUE) &&
       (userJob->MngmtArea.JobStep.Status == MEMACC_JOB_IDLE) &&
       (userJob->JobArea.JobType != (MemAcc_AtomicJobType)MEMACC_NO_JOB) &&
       (internalJob->JobArea.JobType == (MemAcc_AtomicJobType)MEMACC_NO_JOB))
    {
      userJob->MngmtArea.JobResult = MEMACC_CANCELED;
      MemAcc_Queue_PopJob(userJob);
    }
  }
}

/**********************************************************************************************************************
 * MemAcc_Queue_GetNextJob
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
MemAcc_JobContextType* MemAcc_Queue_GetNextJob(MemAcc_SyncGroupIndexType syncGroupIndex)
{
  MemAcc_JobContextType* job = NULL_PTR;

  /* Higher address area priorities (i.e. higher values) have a higher queue index and are processed first.
   * To find the job with the highest priority, the queue is stepped through in reverse order and the JobType
   * is checked. As the index of the queue is an unsigned int, the for loop cannot have the trivial condition
   * index >= 0, since this is always true for an unsigned integer. Due to MISRA restrictions, the iteration
   * expression can also not be left empty, which requires the introduction of the temporary tempIndex variable. */
  for (MemAcc_JobPriorityIndexType tempIndex = MemAcc_GetSizeOfAddressArea();
    (tempIndex > 0u) && (job == NULL_PTR);
    tempIndex--)
  {
    MemAcc_JobPriorityIndexType priority = (MemAcc_JobPriorityIndexType)(tempIndex - 1u);

    job = MemAcc_Queue_GetOrExecuteJob(syncGroupIndex, TRUE, priority);

    if(job == NULL_PTR)
    {
      job = MemAcc_Queue_GetOrExecuteJob(syncGroupIndex, FALSE, priority);
    }
  }

  return job;
}

/**********************************************************************************************************************
 * MemAcc_Queue_GetJob
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
MemAcc_JobContextType* MemAcc_Queue_GetJob(MemAcc_AddressAreaIndexType addressAreaIdx, boolean isInternalJob)
{
  return MemAcc_Queue_GetQueuedJob(isInternalJob, MemAcc_GetPriorityBasedIndexOfAddressArea(addressAreaIdx));
}

/**********************************************************************************************************************
 * MemAcc_Queue_HasJob
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
boolean MemAcc_Queue_HasJob(MemAcc_AddressAreaIndexType addressAreaIdx, boolean isInternalJob)
{
  return MemAcc_Queue_GetJob(addressAreaIdx, isInternalJob)->JobArea.JobType != (MemAcc_AtomicJobType)MEMACC_NO_JOB;
}

/**********************************************************************************************************************
 * MemAcc_Queue_RequestLock
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 * \spec
 *   requires addressAreaIdx < MemAcc_GetSizeOfAddressArea();
 * \endspec
 */
Std_ReturnType MemAcc_Queue_RequestLock(
  MemAcc_AddressAreaIndexType addressAreaIdx,
  MemAcc_AddressType address,
  MemAcc_LengthType length,
  MemAcc_ApplicationLockNotificationType lockNotificationFctPtr)
{
  Std_ReturnType retVal = E_NOT_OK;
  MemAcc_SubAddressAreaIndexType subAAIndex = MemAcc_Utils_GetSubAddrAreaIndexOfAddress(addressAreaIdx, address);
  /*@ assert subAAIndex < MemAcc_GetSizeOfSubAddressArea(); */  /* VCA_MemAcc_SaaRequestLockAssertion */
  MemAcc_JobContextType *job = MemAcc_Queue_GetQueuedJob(FALSE,
    MemAcc_GetPriorityBasedIndexOfAddressArea(addressAreaIdx));

  if (job->JobArea.JobType == (MemAcc_AtomicJobType)MEMACC_NO_JOB)
  {
    job->MngmtArea.JobStep.SubAddrAreaIdx = subAAIndex;
    job->JobArea.Address = address;
    job->JobArea.Length = length;
    job->JobArea.HwId = (MemAcc_HwIdType) 0u; /* PRQA S 4342 */ /* MD_MemAcc_HwIdEnumCasting */
    job->JobArea.LockNotificationFctPtr = lockNotificationFctPtr;
    job->JobArea.JobClassification = MEMACC_JOBCLASSIFICATION_USERJOB;
    job->JobArea.JobType = (MemAcc_AtomicJobType)MEMACC_REQUESTLOCK_JOB;

    retVal = E_OK;
  }

  return retVal;
}

/**********************************************************************************************************************
 * MemAcc_Queue_ReleaseLock
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
void MemAcc_Queue_ReleaseLock(
  MemAcc_AddressAreaIndexType addressAreaIdx,
  MemAcc_AddressType address,
  MemAcc_LengthType length)
{
  MemAcc_SubAddressAreaIndexType subAddressAreaIndex;
  MemAcc_AddressType addressTemp = address;
  MemAcc_LengthType lengthTemp = length;

  while (MemAcc_Utils_GetSAAIndicesForAddressRange(addressAreaIdx, &addressTemp, &lengthTemp, &subAddressAreaIndex) == TRUE)
  {
    /* Unlock the respective underlying Mem driver instance */
    MemAcc_HwIdType hwId = MemAcc_GetHardwareIdOfMemInstance(MemAcc_GetMemInstanceIdxOfSubAddressArea(subAddressAreaIndex));
    if ((uint32) hwId < MEMACC_NUMBER_OF_HARDWARE_IDS)
    {
      MemAcc_MemInstanceLockStates[hwId] = MEMACC_LOCKSTATE_UNLOCKED;
    }
  }
}

#if (MEMACC_SUSPENDRESUME_ENABLED == STD_ON)

/**********************************************************************************************************************
 * MemAcc_Queue_IsSuspensionNeededAndAllowed
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
boolean MemAcc_Queue_IsSuspensionNeededAndAllowed(const MemAcc_HwIdType hwId,
  const MemAcc_AddressAreaIndexType addressAreaIdx,
  const boolean isInternalJob)
{
  boolean memSuspensionAllowed = TRUE;
  boolean existsHigherPriorityJob = FALSE;

  for (MemAcc_JobPriorityIndexType tempIndex = MemAcc_GetSizeOfAddressArea(); tempIndex > 0u; tempIndex--)
  {
    MemAcc_JobPriorityIndexType priority = tempIndex - (MemAcc_JobPriorityIndexType) 1u;
    const MemAcc_JobContextType *job = MemAcc_Queue_GetQueuedJob(isInternalJob, priority);
    MemAcc_JobType jobType = (MemAcc_JobType)(job->JobArea.JobType); /* PRQA S 4342 */ /* MD_MemAcc_JobTypeEnumCasting */

    if ((jobType != MEMACC_NO_JOB) &&
      ((MemAcc_GetHardwareIdOfMemInstance(MemAcc_GetMemInstanceIdxOfSubAddressArea(job->MngmtArea.JobStep.SubAddrAreaIdx))) == hwId))
    {
      if (priority > MemAcc_GetPriorityBasedIndexOfAddressArea(addressAreaIdx))
      {
        existsHigherPriorityJob = TRUE;
      }
      else if (job->MngmtArea.JobStep.IsSuspended == TRUE)
      {
        memSuspensionAllowed = FALSE;
        break;
      }
      else
      {
        /* Intentionally left empty */
      }
    }
  }

  return (existsHigherPriorityJob && memSuspensionAllowed);
}

#endif /* MEMACC_SUSPENDRESUME_ENABLED == STD_ON */

#if (MEMACC_BBM_ENABLED == STD_ON) /* COV_MSR_UT_OPTIONAL_UNIT */

/**********************************************************************************************************************
 * MemAcc_Queue_RaiseError()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 * \spec
 *   requires addressAreaIdx < MemAcc_GetSizeOfAddressArea();
 *   requires errorType != MEMACC_ERRORTYPE_NONE;
 * \endspec
 */
void MemAcc_Queue_RaiseError(MemAcc_AddressAreaIndexType addressAreaIdx, MemAcc_ErrorType errorType)
{
  /*!
   * MEMACC_DEBUG_BREAKPOINT:
   * This breakpoint can be used to see if error notifications are raised within the MemAcc module.
   */
  MemAcc_JobContextType* userJob = MemAcc_Queue_GetJob(addressAreaIdx, FALSE);
  if (userJob->JobArea.JobType != (MemAcc_AtomicJobType)MEMACC_NO_JOB)
  {
    userJob->MngmtArea.JobError = errorType;
  }
  else
  {
    /* Only the case if no user job exists during internal job error. Currently only possible during BBM init scan. */
    if (MemAcc_GetErrorNotificationOfAddressArea(addressAreaIdx) != NULL_PTR)
    {
      /* VCA Line+1 SLC-20 : VCA_MemAcc_ErrorNotificationInvocation */
      MemAcc_GetErrorNotificationOfAddressArea(addressAreaIdx)(
        MemAcc_GetAddressAreaIdOfAddressArea(addressAreaIdx), errorType);
    }
  }
}

#endif /* MEMACC_BBM_ENABLED */

/**********************************************************************************************************************
 * MemAcc_Queue_HasJobForLowerLayerIdx()
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
 * \spec
 *   requires llIdx < MemAcc_GetSizeOfLowerLayer();
 * \endspec
 */
boolean MemAcc_Queue_HasJobForLowerLayerIdx(MemAcc_LowerLayerIndexType llIdx)
{
  boolean retValue = FALSE;

  for (MemAcc_AddressAreaIndexType aaIdx = 0u; (aaIdx < MemAcc_GetSizeOfAddressArea()) && !retValue; aaIdx++)
  {
    if (MemAcc_User_Queue[aaIdx].JobArea.JobType != (MemAcc_AtomicJobType)MEMACC_NO_JOB)
    {
      if (MemAcc_Queue_JobUsesLowerLayerIdx(MemAcc_User_Queue[aaIdx].JobArea, llIdx))
      {
        retValue = TRUE;
        break;
      }
    }

    if (MemAcc_Internal_Queue[aaIdx].JobArea.JobType != (MemAcc_AtomicJobType)MEMACC_NO_JOB)
    {
      if (MemAcc_Queue_JobUsesLowerLayerIdx(MemAcc_Internal_Queue[aaIdx].JobArea, llIdx))
      {
        retValue = TRUE;
      }
    }
  }

  return retValue;
}

#define MEMACC_STOP_SEC_CODE
#include "MemAcc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  MISRA JUSTIFICATIONS
 **********************************************************************************************************************/

/* Justification for module-specific MISRA deviations:

MD_MemAcc_HwIdEnumCasting: rule 10.5
  Reason:     HwId in the JobInfo struct is to be initialized with a value. However, HwId is a generated enum where the
              values are not known in the static code. The value is initialized with a explicitly casted value HwIdType.
  Risk:       None, as the HwIdType always has a value corresponding to zero, and all code paths depending on this value
              are covered.
  Prevention: No prevention, as the HwIdType always has a value corresponding to zero.

MD_MemAcc_JobTypeEnumCasting: rule 10.5
  Reason:     The MemAcc_AtomicJobType values are always generated from MemAcc_JobType enum values. This is for atomic
              Access reasons. Therefore MemAcc_AtomicJobType and MemAcc_JobType are always in a valid range to each other
              and can be casted into each other.
  Risk:       None, as the casting between valid values propose no issues.
  Prevention: No prevention, as the casting is always only done between these compatible types.

*/

/***********************************************************************************************************************
 *  VCA JUSTIFICATIONS
 **********************************************************************************************************************/
/* VCA_JUSTIFICATION_BEGIN

\ID VCA_MemAcc_JobEndNotificationInvocation
  \DESCRIPTION When a user job is finished or canceled an optional JobEndNotification provided by the user can be called.
               Within the generated MemAcc_AddressArea the MemAcc hold the pointer to the JobEndNotification.
               It must be ensured that no null pointer is called.
               The function is not defined within the analyzed sources.

  \COUNTERMEASURE \R A runtime check ensures that a JobEndNotification is only called when the entry within
                     MemAcc_AddressArea is not a NULL_PTR.
                     The Reference of MemAcc_AddressArea itself is retrieved by array access over the addressAreaIndex.
                     A valid addressAreaIndex is ensured by a runtime check before placing any job into queue.

\ID VCA_MemAcc_ErrorNotificationInvocation
  \DESCRIPTION When a job is finished or canceled an optional ErrorNotification provided by the user can be called.
               Within the generated MemAcc_AddressArea the MemAcc hold the pointer to the ErrorNotification.
               It must be ensured that no null pointer is called.
               The function is not defined within the analyzed sources.

  \COUNTERMEASURE \R A runtime check ensures that a ErrorNotification is only called when the entry within
                     MemAcc_AddressArea is not a NULL_PTR.
                     The Reference of MemAcc_AddressArea itself is retrieved by array access over the addressAreaIndex.
                     A valid addressAreaIndex is ensured by a runtime check before placing any job into queue.

\ID VCA_MemAcc_LockNotificationInvocation
  \DESCRIPTION When a lock job is processed, a LockNotificationFct provided by the user is called.
               The LockNotificationFct is passed to the MemAcc as parameter in the MemAcc_RequestLock Api.
               Due to the nature of a unknown function VCA is not able to determine its behavior.

  \COUNTERMEASURE \N User has to use the Lock service as specified by AUTOSAR, therefore a valid notification function
                     should be forwarded. This is in the responsibility of the user.

\ID VCA_MemAcc_DisabledFunctionCallToProcessInternalJobResult
  \DESCRIPTION VCA is not able to analyze the source code fast enough. This leads to timeouts in the CI+ pipeline.
               Disabling this function call significantly improves VCA execution time.

  \COUNTERMEASURE \N The validity is verified via manual Review. Always a valid queue element is forwarded to the
                     BBM unit.

\ID VCA_MemAcc_SaaRequestLockAssertion
  \DESCRIPTION The MemAcc_Utils_GetSubAddrAreaIndexOfAddress() function calculates the SubAddressArea index for a given
               AddressArea and address. As long these parameters are valid, the returned SubAddressArea index is valid.

  \COUNTERMEASURE \R The ErrorCheck unit verifies that the used AddressArea and Address parameters are valid and that
                    a valid SubAddressArea index can be returned by the MemAcc_Utils_GetSubAddrAreaIndexOfAddress() function.

VCA_JUSTIFICATION_END */

/***********************************************************************************************************************
 *  COV JUSTIFICATION
 **********************************************************************************************************************/
/* COV_JUSTIFICATION_BEGIN

\ID COV_MEMACC_VCA
\ACCEPT TX
\ACCEPT XF
\REASON VCA needs additional functions to analyze to code in a meaningful way. Therefore, this code part is not enabled when using VCA.

COV_JUSTIFICATION_END */

/**********************************************************************************************************************
 *  END OF FILE: MemAcc_Queue.c
 *********************************************************************************************************************/
