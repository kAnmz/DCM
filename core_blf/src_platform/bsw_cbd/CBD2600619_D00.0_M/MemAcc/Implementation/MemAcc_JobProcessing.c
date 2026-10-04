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
/*!        \file  MemAcc_JobProcessing.c
 *        \brief  MemAcc_JobProcessing source file
 *      \details  Implementation of the JobProc unit of the MemAcc.
 *         \unit  JobProcessing
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/


#define MEMACC_JOBPROCESSING_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "MemAcc_JobProcessing.h"
#include "vstdlib.h"
// #include "SchM_MemAcc.h"
#include "MemAcc_Utils.h"
#include "MemAcc_MemAb.h"
#include "MemAcc_Queue.h"
#include "MemAcc_BBM.h"
#include "MemAcc_MultiBinary.h"
#include "MemAcc_MemAccessControl.h"

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

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
# define MEMACC_START_SEC_CODE
# include "MemAcc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * MemAcc_JobProcessing_EndJobStep
 *********************************************************************************************************************/
/*! \brief       Ends the current job step.
 *  \details     -
 *  \param[in]   mngmtArea - Pointer to the job mngmt area.
 *  \param[in]   result - Job step result.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
MEMACC_LOCAL void MemAcc_JobProcessing_EndJobStep(MemAcc_MngmtAreaType* mngmtArea, MemAcc_JobResultType result);

/**********************************************************************************************************************
 * MemAcc_JobProcessing_EndJob
 *********************************************************************************************************************/
/*! \brief       Ends the current job.
 *  \details     -
 *  \param[in]   mngmtArea - Pointer to the job mngmt area.
 *  \param[in]   jobLength - Length of the job.
 *  \param[in]   result - Job step result.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
MEMACC_LOCAL void MemAcc_JobProcessing_EndJob(MemAcc_MngmtAreaType* mngmtArea,
  MemAcc_LengthType jobLength,
  MemAcc_JobResultType result);

/**********************************************************************************************************************
 * MemAcc_JobProcessing_CalculateJobStepLength
 *********************************************************************************************************************/
/*! \brief       Gets the job step length for a specific sub address area index, address, burst setting, and job type.
 *  \details     -
 *  \param[in]   JobArea Pointer to the job area.
 *  \param[in]   JobStep Pointer to the job step.
 *  \param[in]   Offset Offset for which the job step should be calculated.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
MEMACC_LOCAL MemAcc_LengthType MemAcc_JobProcessing_CalculateJobStepLength(
  const MemAcc_JobAreaType* JobArea,
  const MemAcc_JobStepType* JobStep,
  MemAcc_LengthType Offset);

/**********************************************************************************************************************
 * MemAcc_JobProcessing_UpdateJobStepPhysicalAddress()
 *********************************************************************************************************************/
/*! \brief       Updates the physical address of the given job step.
 *  \details     If configured: Includes handling of bad blocks.
 *  \param[in]   job - Pointer to the job.
 *  \return      E_OK - if the address update worked.
 *  \return      E_NOT_OK - if an error occurred and the job should not be processed further.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
MEMACC_LOCAL Std_ReturnType MemAcc_JobProcessing_UpdateJobStepPhysicalAddress(MemAcc_JobContextType* job);

/**********************************************************************************************************************
 * MemAcc_JobProcessing_DispatchJobStepToMemDriver()
 *********************************************************************************************************************/
/*! \brief       Dispatches the given job to the Mem Driver.
 *  \details     -
 *  \param[in]   job - Pointer to the job.
 *  \return      E_OK - if the job was accepted by the Mem.
 *  \return      E_NOT_OK - if the job was not accepted by the Mem.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
MEMACC_LOCAL Std_ReturnType MemAcc_JobProcessing_DispatchJobStepToMemDriver(const MemAcc_JobContextType* job);

#if (MEMACC_BBM_ENABLED == STD_ON)

/**********************************************************************************************************************
 * MemAcc_JobProcessing_HandlePFailErrorState()
 *********************************************************************************************************************/
/*! \brief       Handles the P_FAIL error.
 *  \details     -
 *  \param[in]   job - Pointer to the job.
 *  \param[in]   error - Type of error that occurred.
 *  \return      TRUE - if job should be failed.
 *  \return      FALSE - if job should be retried.
 *  \pre         Job has finished with result failed.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
MEMACC_LOCAL boolean MemAcc_JobProcessing_HandlePFailErrorState(
  const MemAcc_JobContextType* job,
  const MemAcc_MemLastErrorJobDataType error);

/**********************************************************************************************************************
 * MemAcc_JobProcessing_HandleEFailErrorState()
 *********************************************************************************************************************/
/*! \brief       Handles the E_FAIL error.
 *  \details     -
 *  \param[in]   job - Pointer to the job.
 *  \param[in]   error - Type of error that occurred.
 *  \return      TRUE - if job should be failed.
 *  \return      FALSE - if job should be retried.
 *  \pre         Job has finished with result failed.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
MEMACC_LOCAL boolean MemAcc_JobProcessing_HandleEFailErrorState(
  const MemAcc_JobContextType* job,
  const MemAcc_MemLastErrorJobDataType error);

/**********************************************************************************************************************
 * MemAcc_JobProcessing_HandleErrorState()
 *********************************************************************************************************************/
/*! \brief       Handles errors in memory access jobs by evaluating the error state.
 *  \details     -
 *  \param[in]   job - Pointer to the job.
 *  \return      TRUE - if job should be failed.
 *  \return      FALSE - if job should be retried (bad block handling in between).
 *  \pre         Job has finished with result failed.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
MEMACC_LOCAL boolean MemAcc_JobProcessing_HandleErrorState(MemAcc_JobContextType* job);

#endif /* (MEMACC_BBM_ENABLED == STD_ON) */

/**********************************************************************************************************************
 * MemAcc_JobProcessing_ProcessJobStepFailure()
 *********************************************************************************************************************/
/*! \brief       Process job step in case of job failure. This includes retry and error handling.
 *  \details     -
 *  \param[in]   job - Pointer to the job.
 *  \pre         Job has finished with result failed.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
MEMACC_LOCAL void MemAcc_JobProcessing_ProcessJobStepFailure(MemAcc_JobContextType* job);

/**********************************************************************************************************************
 * MemAcc_JobProcessing_GetJobStepResult()
 *********************************************************************************************************************/
/*! \brief       Gets the current job result for the given job step.
 *  \details     -
 *  \param[in]   job - Pointer to the job.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
MEMACC_LOCAL MemAcc_MemJobResultType MemAcc_JobProcessing_GetJobStepResult(const MemAcc_JobContextType* job);

/**********************************************************************************************************************
 * MemAcc_JobProcessing_ProcessJobStepResult()
 *********************************************************************************************************************/
/*! \brief       Checks the Mem job result and process the job step.
 *  \details     -
 *  \param[in]   job - Pointer to the job.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
MEMACC_LOCAL void MemAcc_JobProcessing_ProcessJobStepResult(MemAcc_JobContextType* job);

/**********************************************************************************************************************
 * MemAcc_JobProcessing_ProcessJobStepFinished()
 *********************************************************************************************************************/
/*! \brief       After job step finished, handle error and calculate next job step if necessary.
 *  \details     -
 *  \param[in]   job - Pointer to the job.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
MEMACC_LOCAL void MemAcc_JobProcessing_ProcessJobStepFinished(MemAcc_JobContextType* job);

#if (MEMACC_COMPAREAPI_ENABLED == STD_ON)

/**********************************************************************************************************************
 * MemAcc_JobProcessing_ProcessCompareJobStepBuffer()
 *********************************************************************************************************************/
/*! \brief       Processes the data buffer comparison for compare jobs.
 *  \details     -
 *  \param[in]   job - Pointer to the job.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
MEMACC_LOCAL void MemAcc_JobProcessing_ProcessCompareJobStepBuffer(MemAcc_JobContextType* job);

#endif /* MEMACC_COMPAREAPI_ENABLED */

/**********************************************************************************************************************
 * MemAcc_JobProcessing_ProcessJobCompletion()
 *********************************************************************************************************************/
/*! \brief       Evaluates the result of the current job step.
 *  \details     Check for and handles jobs which are canceled or finished.
 *  \param[in]   job - Pointer to the job.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
MEMACC_LOCAL void MemAcc_JobProcessing_ProcessJobCompletion(MemAcc_JobContextType* job);

#if (MEMACC_READCOMPAREALIGNMENT_REQUIRED == STD_OFF)

/**********************************************************************************************************************
 * MemAcc_JobProcessing_IsUnalignedReadCompareStep()
 *********************************************************************************************************************/
/*! \brief       Determines whether the job is read or compare and is unaligned.
 *  \details     -
 *  \param[in]   job - Pointer to the job context.
 *  \return      TRUE - The current read or compare step is unaligned.
 *               FALSE - The step is aligned or not a read or compare job.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
MEMACC_LOCAL boolean MemAcc_JobProcessing_IsUnalignedReadCompareStep(const MemAcc_JobContextType* job);

/**********************************************************************************************************************
 * MemAcc_JobProcessing_CopyAlignmentBufferToJobDataBuffer()
 *********************************************************************************************************************/
/*! \brief       Copies relevant bytes from the alignment buffer to the job data buffer for unaligned read/compare jobs.
 *  \details     -
 *  \param[in]   job - Pointer to the job context.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
MEMACC_LOCAL void MemAcc_JobProcessing_CopyAlignmentBufferToJobDataBuffer(const MemAcc_JobContextType* job);

#endif /* (MEMACC_READCOMPAREALIGNMENT_REQUIRED == STD_OFF) */

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  MemAcc_JobProcessing_EndJobStep()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 * \spec
 *   requires mngmtArea != NULL_PTR;
 * \endspec
 */
MEMACC_LOCAL void MemAcc_JobProcessing_EndJobStep(MemAcc_MngmtAreaType* mngmtArea, MemAcc_JobResultType result)
{
  mngmtArea->JobStep.Result = result;
  // SchM_Enter_MemAcc_MEMACC_EXCLUSIVE_AREA_1();
  mngmtArea->Offset += mngmtArea->JobStep.Length;
  // SchM_Exit_MemAcc_MEMACC_EXCLUSIVE_AREA_1();

  if (result == MEMACC_ECC_CORRECTED)
  {
    mngmtArea->ReadJobEccCorrected = TRUE;
  }
}

/**********************************************************************************************************************
 *  MemAcc_JobProcessing_EndJob()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 * \spec
 *   requires mngmtArea != NULL_PTR;
 * \endspec
 */
MEMACC_LOCAL void MemAcc_JobProcessing_EndJob(MemAcc_MngmtAreaType* mngmtArea,
  MemAcc_LengthType jobLength,
  MemAcc_JobResultType result)
{
  mngmtArea->JobStep.Result = result;
  // SchM_Enter_MemAcc_MEMACC_EXCLUSIVE_AREA_1();
  mngmtArea->Offset = jobLength;
  // SchM_Exit_MemAcc_MEMACC_EXCLUSIVE_AREA_1();
}

/**********************************************************************************************************************
 *  MemAcc_JobProcessing_CalculateJobStepLength()
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
 *
 */
MEMACC_LOCAL MemAcc_LengthType MemAcc_JobProcessing_CalculateJobStepLength(
  const MemAcc_JobAreaType* JobArea,
  const MemAcc_JobStepType* JobStep,
  MemAcc_LengthType Offset)
{
  MemAcc_AddressType logicalAddress = JobArea->Address + Offset;
  MemAcc_LengthType remainingSAALength = ((MemAcc_LengthType) MemAcc_GetLogicalEndAddressOfSubAddressArea(JobStep->SubAddrAreaIdx) - logicalAddress + 1u);
  MemAcc_LengthType remainingJobLength = JobArea->Length - Offset;
  MemAcc_LengthType requestedLength = (remainingSAALength <= remainingJobLength) ? remainingSAALength : remainingJobLength;

  MemAcc_LengthType subAddrAreaOffset = logicalAddress - MemAcc_GetLogicalStartAddressOfSubAddressArea(JobStep->SubAddrAreaIdx);
  MemAcc_LengthType normalLength = 0u;
  MemAcc_LengthType burstLength = 0u;
  MemAcc_LengthType jobStepLength = 0u;

  MemAcc_MemSectorBatchIterType memSectorBatchIdx = MemAcc_GetMemSectorBatchIdxOfSubAddressArea(JobStep->SubAddrAreaIdx);

  switch ((MemAcc_JobType)JobArea->JobType) /* PRQA S 4342 */ /* MD_MemAcc_JobTypeEnumCasting */
  {
  case MEMACC_READ_JOB:
  case MEMACC_COMPARE_JOB:
#if (MEMACC_READCOMPAREALIGNMENT_REQUIRED == STD_OFF)
  {
    const MemAcc_LengthType minReadSize = MemAcc_GetMinReadSizeOfMemSectorBatch(memSectorBatchIdx);
    /* Calculate the would-be physical address to determine alignment. */
    const MemAcc_AddressType physAddr = MemAcc_GetPhysicalStartAddressOfSubAddressArea(JobStep->SubAddrAreaIdx)
      + (logicalAddress - MemAcc_GetLogicalStartAddressOfSubAddressArea(JobStep->SubAddrAreaIdx));
    const MemAcc_LengthType misalignment = (MemAcc_LengthType)(physAddr % minReadSize);

    if (misalignment != 0u)
    {
      /* Head step: read only the bytes up to the next minReadSize multiple. */
      const MemAcc_LengthType headBytes = minReadSize - misalignment;
      jobStepLength = (requestedLength <= headBytes) ? requestedLength : headBytes;
    }
    else if (requestedLength < minReadSize)
    {
      /* Tail step: remaining bytes less than the minReadSize. */
      jobStepLength = requestedLength;
    }
    else
    {
      /* Interior step: fully aligned, use normal burst logic. */
      burstLength = MemAcc_GetMaxReadSizeOfMemSectorBatch(memSectorBatchIdx);
      jobStepLength = (requestedLength >= burstLength) ? burstLength : requestedLength;
      jobStepLength -= (jobStepLength % minReadSize);
    }
    break;
  }
#else
    /* Both READ and COMPARE can have any integer multiple of the Min Read Size up to the Max Read Size as their step length.
     * The RequestedLength is guaranteed to be aligned to the Min Read Size due to prior checks. */
    burstLength = MemAcc_GetMaxReadSizeOfMemSectorBatch(memSectorBatchIdx);
    jobStepLength = (requestedLength >= burstLength) ? burstLength : requestedLength;
    break;
#endif /* (MEMACC_READCOMPAREALIGNMENT_REQUIRED == STD_OFF) */
  case MEMACC_WRITE_JOB:
    normalLength = MemAcc_GetWritePageSizeOfMemSectorBatch(memSectorBatchIdx);
    burstLength = MemAcc_GetWriteBurstSizeOfMemSectorBatch(memSectorBatchIdx);
    jobStepLength = (MemAcc_IsUseWriteBurstOfSubAddressArea(JobStep->SubAddrAreaIdx)
                      && ((subAddrAreaOffset % burstLength) == 0u)
                      && (requestedLength >= burstLength))
                    ? burstLength : normalLength;
    break;
  case MEMACC_BLANKCHECK_JOB:
    /* BLANKCHECK jobs use the write page size, but never the write burst length. */
    jobStepLength = MemAcc_GetWritePageSizeOfMemSectorBatch(memSectorBatchIdx);
    break;
  case MEMACC_ERASE_JOB:
    normalLength = MemAcc_GetEraseSectorSizeOfMemSectorBatch(memSectorBatchIdx);
    burstLength = MemAcc_GetEraseBurstSizeOfMemSectorBatch(memSectorBatchIdx);
    jobStepLength = (MemAcc_IsUseEraseBurstOfSubAddressArea(JobStep->SubAddrAreaIdx)
                      && ((subAddrAreaOffset % burstLength) == 0u)
                      && (requestedLength >= burstLength))
                    ? burstLength : normalLength;
    break;
  case MEMACC_NO_JOB:
  case MEMACC_MEMHWSPECIFIC_JOB:
  case MEMACC_REQUESTLOCK_JOB:
  default:  /* COV_MemAcc_JobProcessing_MISRA */
    break;
  }

  return jobStepLength;
}

/**********************************************************************************************************************
 * MemAcc_JobProcessing_UpdateJobStepPhysicalAddress()
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
MEMACC_LOCAL Std_ReturnType MemAcc_JobProcessing_UpdateJobStepPhysicalAddress(MemAcc_JobContextType* job)
{
  /*
   * The physical address is updated right before the job is dispatched to Mem to make sure that the correct address is used.
   * In case of NAND Memory a BB for a SAA could be detected after the physical address was calculated.
   * In this case the physical address for the NAND Skip Method addressing might be off by one block.
   */
  Std_ReturnType retVal = E_OK;

  if((job->JobArea.JobType != (MemAcc_AtomicJobType)MEMACC_MEMHWSPECIFIC_JOB)
    && (job->JobArea.JobType != (MemAcc_AtomicJobType)MEMACC_REQUESTLOCK_JOB)
    && (job->JobArea.JobType != (MemAcc_AtomicJobType)MEMACC_NO_JOB))
  {
    job->MngmtArea.JobStep.PhysicalAddress = MemAcc_GetPhysicalStartAddressOfSubAddressArea(job->MngmtArea.JobStep.SubAddrAreaIdx)
      + job->MngmtArea.JobStep.LogicalAddress
      - MemAcc_GetLogicalStartAddressOfSubAddressArea(job->MngmtArea.JobStep.SubAddrAreaIdx);

#if (MEMACC_BBM_ENABLED == STD_ON)

    /* Safe the default calculated physical address to compare against the BBM physical address for a potential integer overflow. */
    const MemAcc_AddressType defaultPhysicalAddress = job->MngmtArea.JobStep.PhysicalAddress;

    job->MngmtArea.JobStep.PhysicalAddress = MemAcc_BBM_TranslateLogicalToPhysicalAddress(
      job->JobArea.JobClassification,
      job->MngmtArea.JobStep.SubAddrAreaIdx,
      job->MngmtArea.JobStep.LogicalAddress);

    /* Check after calculation of physical address if job step is out of bounds of the SAA. This can happen with a high logical address and bad blocks. */
    if (((job->MngmtArea.JobStep.PhysicalAddress + job->MngmtArea.JobStep.Length - 1u) > MemAcc_GetPhysicalEndAddressOfSubAddressArea(job->MngmtArea.JobStep.SubAddrAreaIdx))
    /* Check if the physical address calculated a address with integer overflow. The calculated BBM physical address is always equal or greater than the default physical address. */
      || (job->MngmtArea.JobStep.PhysicalAddress < defaultPhysicalAddress))
    {
      retVal = E_NOT_OK;
      /* VCA Line+1 SPC-01 : VCA_MemAcc_AddressAreaIndexOfJobAlwaysValid */
      MemAcc_Queue_RaiseError(job->JobArea.AddressAreaIndex, MEMACC_ERRORTYPE_BBM_TRANSLATEDADDRESSOUTOFBOUNDS);
    }

#endif /* (MEMACC_BBM_ENABLED == STD_ON) */

  }
  else
  {
    job->MngmtArea.JobStep.PhysicalAddress = 0u;
  }

  return retVal;
}

/**********************************************************************************************************************
 * MemAcc_JobProcessing_DispatchJobStepToMemDriver()
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
 *   requires job != NULL_PTR;
 * \endspec
 */
MEMACC_LOCAL Std_ReturnType MemAcc_JobProcessing_DispatchJobStepToMemDriver(const MemAcc_JobContextType* job)
{
  Std_ReturnType memJobReturnValue;
  const MemAcc_LowerLayerIndexType lowerLayerIndex =
    MemAcc_GetLowerLayerIdxOfSubAddressArea(job->MngmtArea.JobStep.SubAddrAreaIdx);
  /*@ assert lowerLayerIndex < MemAcc_GetSizeOfLowerLayer(); */  /* VCA_MemAcc_LowerLayerIndexAlwaysValid */
  const MemAcc_InstanceIdOfMemInstanceType instanceId =
    MemAcc_GetInstanceIdOfMemInstance(MemAcc_GetMemInstanceIdxOfSubAddressArea(job->MngmtArea.JobStep.SubAddrAreaIdx));

  /*!
   * MEMACC_DEBUG_BREAKPOINT:
   * This breakpoint can be used to debug the interaction with the Mem Driver for singlebinary or multi-binary 
   * direct access job steps. It is hit right before the job step is dispatched to the Mem Driver.
   * To verify the return value of the Mem Driver, the breakpoint can be set after the switch case.
   */

  switch((MemAcc_JobType)job->JobArea.JobType)/* PRQA S 4342 */ /* MD_MemAcc_JobTypeEnumCasting */
  {
    case MEMACC_READ_JOB:
#if (MEMACC_READCOMPAREALIGNMENT_REQUIRED == STD_OFF)
      if (MemAcc_JobProcessing_IsUnalignedReadCompareStep(job))
      {
        const MemAcc_MinReadSizeOfMemSectorBatchType minReadSize = MemAcc_GetMinReadSizeOfMemSectorBatch(
          MemAcc_GetMemSectorBatchIdxOfSubAddressArea(job->MngmtArea.JobStep.SubAddrAreaIdx));

        memJobReturnValue = MemAcc_MemAb_InvokeRead(
          lowerLayerIndex,
          instanceId,
          job->MngmtArea.JobStep.PhysicalAddress - (job->MngmtArea.JobStep.PhysicalAddress % minReadSize),
          MemAcc_GetReadAlignmentBufferPtrOfSyncGroup(
            MemAcc_GetSyncGroupIdOfSubAddressArea(job->MngmtArea.JobStep.SubAddrAreaIdx)),
          minReadSize);
      }
      else
#endif /* (MEMACC_READCOMPAREALIGNMENT_REQUIRED == STD_OFF) */
      {
        memJobReturnValue = MemAcc_MemAb_InvokeRead(
          lowerLayerIndex,
          instanceId,
          job->MngmtArea.JobStep.PhysicalAddress,
          &(job->JobArea.DataBuffer[job->MngmtArea.Offset]),
          job->MngmtArea.JobStep.Length
        );
      }
      break;
    case MEMACC_WRITE_JOB:
      memJobReturnValue = MemAcc_MemAb_InvokeWrite(
        lowerLayerIndex,
        instanceId,
        job->MngmtArea.JobStep.PhysicalAddress,
        &(job->JobArea.ConstDataBuffer[job->MngmtArea.Offset]),
        job->MngmtArea.JobStep.Length
      );
      break;
    case MEMACC_ERASE_JOB:
      memJobReturnValue = MemAcc_MemAb_InvokeErase(
        lowerLayerIndex,
        instanceId,
        job->MngmtArea.JobStep.PhysicalAddress,
        job->MngmtArea.JobStep.Length
      );
      break;
    case MEMACC_COMPARE_JOB:
#if (MEMACC_READCOMPAREALIGNMENT_REQUIRED == STD_OFF)
      if (MemAcc_JobProcessing_IsUnalignedReadCompareStep(job))
      {
        const MemAcc_MinReadSizeOfMemSectorBatchType minReadSize = MemAcc_GetMinReadSizeOfMemSectorBatch(
          MemAcc_GetMemSectorBatchIdxOfSubAddressArea(job->MngmtArea.JobStep.SubAddrAreaIdx));

        memJobReturnValue = MemAcc_MemAb_InvokeRead(
          lowerLayerIndex,
          instanceId,
          job->MngmtArea.JobStep.PhysicalAddress - (job->MngmtArea.JobStep.PhysicalAddress % minReadSize),
          MemAcc_GetReadAlignmentBufferPtrOfSyncGroup(
            MemAcc_GetSyncGroupIdOfSubAddressArea(job->MngmtArea.JobStep.SubAddrAreaIdx)),
          minReadSize);
      }
      else
#endif /* (MEMACC_READCOMPAREALIGNMENT_REQUIRED == STD_OFF) */
      {
        memJobReturnValue = MemAcc_MemAb_InvokeRead(
          lowerLayerIndex,
          instanceId,
          job->MngmtArea.JobStep.PhysicalAddress,
          job->JobArea.DataBuffer,
          job->MngmtArea.JobStep.Length
        );
      }
      break;
    case MEMACC_BLANKCHECK_JOB:
      memJobReturnValue = MemAcc_MemAb_InvokeBlankCheck(
        lowerLayerIndex,
        instanceId,
        job->MngmtArea.JobStep.PhysicalAddress,
        job->MngmtArea.JobStep.Length
      );
      break;
    case MEMACC_MEMHWSPECIFIC_JOB:
      memJobReturnValue = MemAcc_MemAb_InvokeHwSpecificService(
        lowerLayerIndex,
        instanceId,
        job->JobArea.HwServiceId,
        job->JobArea.DataBuffer,
        job->JobArea.LengthPtr
      );
      break;
    case MEMACC_NO_JOB:
    case MEMACC_REQUESTLOCK_JOB:
    default: /* COV_MemAcc_JobProcessing_MISRA */
      memJobReturnValue = E_NOT_OK;
      break;
  }

  return memJobReturnValue;
}

#if (MEMACC_BBM_ENABLED == STD_ON)

/**********************************************************************************************************************
 * MemAcc_JobProcessing_HandlePFailErrorState()
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
 * \spec
 *   requires job != NULL_PTR;
 *   requires error.LastErrorType == MEMACC_MEMERRORTYPE_P_FAIL;
 * \endspec
 */
MEMACC_LOCAL boolean MemAcc_JobProcessing_HandlePFailErrorState(
  const MemAcc_JobContextType* job,
  const MemAcc_MemLastErrorJobDataType error)
{
  boolean failJob = TRUE;

  MemAcc_SubAddressAreaIndexType saaIdx = job->MngmtArea.JobStep.SubAddrAreaIdx;
  /*@ assert saaIdx < MemAcc_GetSizeOfSubAddressArea(); */ /* VCA_MemAcc_SubAddressAreaIndexOfJobStepAlwaysValid */

  if ((job->JobArea.JobClassification == MEMACC_JOBCLASSIFICATION_USERJOB)
    && (job->JobArea.JobType == (MemAcc_AtomicJobType)MEMACC_WRITE_JOB))
  {
    failJob = FALSE; /* User Write jobs are retried. */

    MemAcc_BBM_UpsertBadBlock(
      MEMACC_BBM_BBMARKERSTATE_MARKEDINLUT,
      saaIdx,
      MemAcc_Utils_GetPhysicalBlockNr(job->MngmtArea.JobStep.SubAddrAreaIdx, error.LastErrorSectorAddress));
  }
  else if (job->JobArea.JobClassification == MEMACC_JOBCLASSIFICATION_BBM_RECOVERSECTOR)
  {
    /* P_FAIL during data recovery means that the target block where the data is being recovered to is a bad block.*/
    MemAcc_BBM_UpsertBadBlock(
      MEMACC_BBM_BBMARKERSTATE_DATARECOVERED,
      saaIdx,
      MemAcc_Utils_GetPhysicalBlockNr(job->MngmtArea.JobStep.SubAddrAreaIdx, error.LastErrorSectorAddress));
  }
  else
  {
    /* Other HwSpecificService jobs that cause P_FAIL are not supported. */
    /* Internal write jobs are not expected. */
    /* VCA Line+1 SPC-01 : VCA_MemAcc_AddressAreaIndexOfJobAlwaysValid */
    MemAcc_Queue_RaiseError(job->JobArea.AddressAreaIndex, MEMACC_ERRORTYPE_BBM_UNEXPECTED_P_FAIL);
  }

  return failJob;
}

/**********************************************************************************************************************
 * MemAcc_JobProcessing_HandleEFailErrorState()
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
 * \spec
 *   requires job != NULL_PTR;
 *   requires error.LastErrorType == MEMACC_MEMERRORTYPE_E_FAIL;
 * \endspec
 */
MEMACC_LOCAL boolean MemAcc_JobProcessing_HandleEFailErrorState(
  const MemAcc_JobContextType* job,
  const MemAcc_MemLastErrorJobDataType error)
{
  boolean failJob = TRUE;

  if ((job->JobArea.JobClassification == MEMACC_JOBCLASSIFICATION_USERJOB)
    && (job->JobArea.JobType == (MemAcc_AtomicJobType)MEMACC_ERASE_JOB))
  {
    failJob = FALSE; /* User Erase jobs are retried. */

    MemAcc_SubAddressAreaIndexType saaIdx = job->MngmtArea.JobStep.SubAddrAreaIdx;
    /*@ assert saaIdx < MemAcc_GetSizeOfSubAddressArea(); */ /* VCA_MemAcc_SubAddressAreaIndexOfJobStepAlwaysValid */
    MemAcc_BBM_UpsertBadBlock(
      MEMACC_BBM_BBMARKERSTATE_BLOCKERASED,
      saaIdx,
      MemAcc_Utils_GetPhysicalBlockNr(job->MngmtArea.JobStep.SubAddrAreaIdx, error.LastErrorSectorAddress));
  }
  else if (job->JobArea.JobClassification == MEMACC_JOBCLASSIFICATION_BBM_ERASEBLOCK)
  {
    /* E_FAIL is ignored. As long the WriteBBMarker job afterwards succeeds this error can be neglected. */
  }
  else
  {
    /* HwSpecificService jobs that cause E_FAIL are not supported. */
    /* Other internal erase jobs are not expected. */
    /* VCA Line+1 SPC-01 : VCA_MemAcc_AddressAreaIndexOfJobAlwaysValid */
    MemAcc_Queue_RaiseError(job->JobArea.AddressAreaIndex, MEMACC_ERRORTYPE_BBM_UNEXPECTED_E_FAIL);
  }

  return failJob;
}

/**********************************************************************************************************************
 * MemAcc_JobProcessing_HandleErrorState()
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
 * \spec
 *   requires job != NULL_PTR;
 * \endspec
 */
MEMACC_LOCAL boolean MemAcc_JobProcessing_HandleErrorState(MemAcc_JobContextType* job)
{
  boolean failJob = TRUE;
  MemAcc_MemLastErrorJobDataType error;
  MemAcc_LowerLayerIndexType lowerLayerIndex = MemAcc_GetLowerLayerIdxOfSubAddressArea(job->MngmtArea.JobStep.SubAddrAreaIdx);
  /*@ assert lowerLayerIndex < MemAcc_GetSizeOfLowerLayer(); */  /* VCA_MemAcc_LowerLayerIndexAlwaysValid */

  if (MemAcc_MemAb_InvokeReadErrorState(lowerLayerIndex, MemAcc_GetInstanceIdOfMemInstance(
    MemAcc_GetMemInstanceIdxOfSubAddressArea(job->MngmtArea.JobStep.SubAddrAreaIdx)), &error) != E_OK)
  {
    /* Invocation of Error was not accepted/processed. This is a critical error. Further correct processing cannot be guaranteed. */
    /* VCA Line+1 SPC-01 : VCA_MemAcc_AddressAreaIndexOfJobAlwaysValid */
    MemAcc_Queue_RaiseError(job->JobArea.AddressAreaIndex, MEMACC_ERRORTYPE_BBM_READERRORSTATE_REJECTED);
  }
  else if((error.LastErrorSectorAddress < MemAcc_GetPhysicalStartAddressOfSubAddressArea(job->MngmtArea.JobStep.SubAddrAreaIdx))
    || (error.LastErrorSectorAddress > MemAcc_GetPhysicalEndAddressOfSubAddressArea(job->MngmtArea.JobStep.SubAddrAreaIdx)))
  {
    /* Received physical address is out of range. Likely a problem with the used Mem driver. */
    /* VCA Line+1 SPC-01 : VCA_MemAcc_AddressAreaIndexOfJobAlwaysValid */
    MemAcc_Queue_RaiseError(job->JobArea.AddressAreaIndex, MEMACC_ERRORTYPE_BBM_READERRORSTATE_INVALIDADDRESS);
  }
  else
  {
    job->MngmtArea.JobStep.MemError = error.LastErrorType;

    if (error.LastErrorType == MEMACC_MEMERRORTYPE_E_FAIL)
    {
      failJob = MemAcc_JobProcessing_HandleEFailErrorState(job, error);
    }
    else if (error.LastErrorType == MEMACC_MEMERRORTYPE_P_FAIL)
    {
      failJob = MemAcc_JobProcessing_HandlePFailErrorState(job, error);
    }
    else
    {
      /* do nothing */
    }
  }

  return failJob;
}

#endif /* (MEMACC_BBM_ENABLED == STD_ON) */

/**********************************************************************************************************************
 * MemAcc_JobProcessing_ProcessJobStepFailure()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 * \spec
 *   requires job != NULL_PTR;
 * \endspec
 */
MEMACC_LOCAL void MemAcc_JobProcessing_ProcessJobStepFailure(MemAcc_JobContextType* job)
{
  if (job->MngmtArea.JobStep.RetryCounter != 0u)
  {
    job->MngmtArea.JobStep.RetryCounter--;
  }
  else

#if (MEMACC_BBM_ENABLED == STD_ON)

  if(MemAcc_GetBBStrategyOfMemInstance(MemAcc_GetMemInstanceIdxOfSubAddressArea(job->MngmtArea.JobStep.SubAddrAreaIdx)) == MEMACC_BBM_BBSTRATEGY_NONE)

#endif /* (MEMACC_BBM_ENABLED == STD_ON) */

  {
    MemAcc_JobProcessing_EndJob(&job->MngmtArea, job->JobArea.Length, MEMACC_FAILED);
  }

#if (MEMACC_BBM_ENABLED == STD_ON)

  else if (MemAcc_JobProcessing_HandleErrorState(job) == TRUE)
  {
    MemAcc_JobProcessing_EndJob(&job->MngmtArea, job->JobArea.Length, MEMACC_FAILED);
  }
  else
  {
    /* do nothing */
  }

#endif /* (MEMACC_BBM_ENABLED == STD_ON) */
}


/**********************************************************************************************************************
 * MemAcc_JobProcessing_GetJobStepResult()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 * \spec
 *   requires job != NULL_PTR;
 * \endspec
 */
MEMACC_LOCAL MemAcc_MemJobResultType MemAcc_JobProcessing_GetJobStepResult(const MemAcc_JobContextType* job)
{
  MemAcc_MemJobResultType jobStepResult;

#if (MEMACC_MULTIBINARY_ISSATELLITEBINARY == STD_ON)
# if (MEMACC_MULTIBINARY_HASREDIRECTREQUESTS == STD_ON)

  if(MemAcc_GetAccessTypeOfSubAddressArea(job->MngmtArea.JobStep.SubAddrAreaIdx) == MEMACC_MULTIBINARY_REDIRECT_ACCESS)
  {
    MemAcc_LengthType srcBufferOffset = 0u;

#if (MEMACC_READCOMPAREALIGNMENT_REQUIRED == STD_OFF)
    if (MemAcc_JobProcessing_IsUnalignedReadCompareStep(job))
    {
      const MemAcc_MinReadSizeOfMemSectorBatchType minReadSize = MemAcc_GetMinReadSizeOfMemSectorBatch(
        MemAcc_GetMemSectorBatchIdxOfSubAddressArea(job->MngmtArea.JobStep.SubAddrAreaIdx));
      srcBufferOffset =
        (MemAcc_LengthType)(job->MngmtArea.JobStep.PhysicalAddress % minReadSize);
    }
#endif /* (MEMACC_READCOMPAREALIGNMENT_REQUIRED == STD_OFF) */

    jobStepResult = MemAcc_MultiBinary_GetRedirectJobStepResultAndUpdateJobContext(job, srcBufferOffset);
  }
  else
# endif /* MEMACC_MULTIBINARY_HASREDIRECTREQUESTS */
#endif /* MEMACC_MULTIBINARY_ISSATELLITEBINARY */

  {
    MemAcc_LowerLayerIndexType lowerLayerIndex = MemAcc_GetLowerLayerIdxOfSubAddressArea(job->MngmtArea.JobStep.SubAddrAreaIdx);
    /*@ assert lowerLayerIndex < MemAcc_GetSizeOfLowerLayer(); */  /* VCA_MemAcc_LowerLayerIndexAlwaysValid */
    MemAcc_MemAb_InvokeMainFunction(lowerLayerIndex);
    jobStepResult = MemAcc_MemAb_InvokeGetJobResult(lowerLayerIndex,
      MemAcc_GetInstanceIdOfMemInstance(MemAcc_GetMemInstanceIdxOfSubAddressArea(job->MngmtArea.JobStep.SubAddrAreaIdx)));

#if (MEMACC_READCOMPAREALIGNMENT_REQUIRED == STD_OFF)
    if ((jobStepResult == MEM_JOB_OK) || (jobStepResult == MEM_ECC_CORRECTED))
    {
      /* For redirect jobs, the data is already copied by MultiBinary_GetRedirectJobStepResultAndUpdateJobContext.
       * Only required for Singlebinary and Direct job steps. */
      MemAcc_JobProcessing_CopyAlignmentBufferToJobDataBuffer(job);
    }
#endif /* (MEMACC_READCOMPAREALIGNMENT_REQUIRED == STD_OFF) */
  }

  return jobStepResult;
}

/**********************************************************************************************************************
 * MemAcc_JobProcessing_ProcessJobStepResult()
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
 * \spec
 *   requires job != NULL_PTR;
 * \endspec
 */
MEMACC_LOCAL void MemAcc_JobProcessing_ProcessJobStepResult(MemAcc_JobContextType* job)
{
  MemAcc_MemJobResultType jobStepResult = MemAcc_JobProcessing_GetJobStepResult(job);

  /*!
   * MEMACC_DEBUG_BREAKPOINT:
   * This breakpoint can be used to debug the result returned by the Mem Driver for the current job step.
   * In case only non PENDING results are of interest, set the breakpoint in the if statement below to only break 
   * on completed job steps.
   * In case of MEM_JOB_FAILED or MEM_ECC_UNCORRECTED results, please check further in the Mem Driver.
   */

  if(jobStepResult != MEM_JOB_PENDING)
  {
    job->MngmtArea.JobStep.Status = MEMACC_JOB_IDLE;
  }

  switch(jobStepResult)
  {
    case MEM_JOB_PENDING:
      break;
    case MEM_JOB_OK:
      MemAcc_JobProcessing_EndJobStep(&job->MngmtArea, MEMACC_OK);
      break;
    case MEM_ECC_CORRECTED:
      MemAcc_JobProcessing_EndJobStep(&job->MngmtArea, MEMACC_ECC_CORRECTED);
      break;
    case MEM_INCONSISTENT:
      MemAcc_JobProcessing_EndJob(&job->MngmtArea, job->JobArea.Length, MEMACC_INCONSISTENT);
      break;
    case MEM_ECC_UNCORRECTED:
      MemAcc_JobProcessing_EndJob(&job->MngmtArea, job->JobArea.Length, MEMACC_ECC_UNCORRECTED);
      break;
    case MEM_JOB_FAILED:
    default:                                                      /* COV_MemAcc_JobProcessing_MISRA */
      MemAcc_JobProcessing_ProcessJobStepFailure(job);
      break;
  }
}

/**********************************************************************************************************************
 * MemAcc_JobProcessing_ProcessJobStepFinished()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 * \spec
 *   requires job != NULL_PTR;
 * \endspec
 */
MEMACC_LOCAL void MemAcc_JobProcessing_ProcessJobStepFinished(MemAcc_JobContextType* job)
{
  if (job->MngmtArea.JobStep.Status == MEMACC_JOB_IDLE)
  {
    if (job->MngmtArea.JobError != MEMACC_ERRORTYPE_NONE)
    {
      MemAcc_JobProcessing_EndJob(&job->MngmtArea, job->JobArea.Length, MEMACC_FAILED);
    }

    if (job->MngmtArea.Offset < job->JobArea.Length)
    {
      if (MemAcc_JobProcessing_CalculateNextJobStep(&job->JobArea, &job->MngmtArea.JobStep, job->MngmtArea.Offset, FALSE) != E_OK)
      {
        MemAcc_JobProcessing_EndJob(&job->MngmtArea, job->JobArea.Length, MEMACC_FAILED);
      }
    }
  }
}

#if (MEMACC_COMPAREAPI_ENABLED == STD_ON)

/*********************************************************************************************************************
 * MemAcc_JobProcessing_ProcessCompareJobStepBuffer()
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
 *   requires job != NULL_PTR;
 * \endspec
 */
MEMACC_LOCAL void MemAcc_JobProcessing_ProcessCompareJobStepBuffer(MemAcc_JobContextType* job)
{
  if ((job->MngmtArea.JobStep.Status == MEMACC_JOB_IDLE)
    && (job->JobArea.JobType == (MemAcc_AtomicJobType)MEMACC_COMPARE_JOB))
  {
    if (job->MngmtArea.JobStep.Result == MEMACC_ECC_CORRECTED)
    {
      job->MngmtArea.ReadJobEccCorrected = FALSE;
      job->MngmtArea.JobStep.Result = MEMACC_OK;
    }

    /*
     * Compare the data of a job step before the new job step length is calculated.
     * In case the read retry counter expires the job step result would be set to MEMACC_FAILED.
     * The compare is just done in case the jobStep.Status is IDLE and jobStep.Result is OK.
     *  | data | data | data | data |
     *         |
     *        offset => start compare = offset - job step length,
     *        therefor the condition for comparing is: offset <= job length
     */
    if (job->MngmtArea.JobStep.Result == MEMACC_OK)
    {
      if (job->MngmtArea.Offset >= job->MngmtArea.JobStep.Length) /* COV_MemAcc_JobProcessing_ProcessCompareJobStepBuffer_DefensiveCheck */
      {
        MemAcc_LengthType compareStart = job->MngmtArea.Offset - job->MngmtArea.JobStep.Length;
        MemAcc_LengthType compareLength = job->MngmtArea.JobStep.Length;

        if (VStdLib_MemCmp(&(job->JobArea.ConstDataBuffer[compareStart]), job->JobArea.DataBuffer, compareLength) != 0)
        {
          MemAcc_JobProcessing_EndJob(&job->MngmtArea, job->JobArea.Length, MEMACC_INCONSISTENT);
        }
      }
    }
  }
}

#endif /* MEMACC_COMPAREAPI_ENABLED */

/*********************************************************************************************************************
 * MemAcc_JobProcessing_ProcessJobCompletion()
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
 * \spec
 *   requires job != NULL_PTR;
 * \endspec
 */
MEMACC_LOCAL void MemAcc_JobProcessing_ProcessJobCompletion(MemAcc_JobContextType* job)
{
  if (job->MngmtArea.JobCanceled == TRUE)
  {
    /* If no internal job exists for a user job, the user job may be cancelled. */
    if(MemAcc_Queue_HasJob(job->JobArea.AddressAreaIndex, TRUE) == FALSE)
    {
      job->MngmtArea.JobResult = MEMACC_CANCELED;
      MemAcc_Queue_PopJob(job);
    }
  }
  /* Handle jobs which are finished and not canceled */
  else if (job->MngmtArea.Offset >= job->JobArea.Length)
  {
    if ((job->MngmtArea.JobStep.Result == MEMACC_OK) && (job->MngmtArea.ReadJobEccCorrected == TRUE))
    {
      job->MngmtArea.JobResult = MEMACC_ECC_CORRECTED;
    }
    else
    {
      job->MngmtArea.JobResult = job->MngmtArea.JobStep.Result;
    }

    MemAcc_Queue_PopJob(job);
  }
  else
  {
    /* do nothing */
  }
}

#if (MEMACC_READCOMPAREALIGNMENT_REQUIRED == STD_OFF)

/**********************************************************************************************************************
 * MemAcc_JobProcessing_IsUnalignedReadCompareStep()
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
MEMACC_LOCAL boolean MemAcc_JobProcessing_IsUnalignedReadCompareStep(const MemAcc_JobContextType* job)
{
  boolean isUnaligned = FALSE;

  if ((job->JobArea.JobType == (MemAcc_AtomicJobType)MEMACC_READ_JOB)
    || (job->JobArea.JobType == (MemAcc_AtomicJobType)MEMACC_COMPARE_JOB))
  {
    const MemAcc_MinReadSizeOfMemSectorBatchType minReadSize = MemAcc_GetMinReadSizeOfMemSectorBatch(
      MemAcc_GetMemSectorBatchIdxOfSubAddressArea(job->MngmtArea.JobStep.SubAddrAreaIdx));

    if (((job->MngmtArea.JobStep.PhysicalAddress % minReadSize) != 0u)
      || ((job->MngmtArea.JobStep.Length % minReadSize) != 0u))
    {
      isUnaligned = TRUE;
    }
  }

  return isUnaligned;
}

/**********************************************************************************************************************
 * MemAcc_JobProcessing_CopyAlignmentBufferToJobDataBuffer()
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
MEMACC_LOCAL void MemAcc_JobProcessing_CopyAlignmentBufferToJobDataBuffer(const MemAcc_JobContextType* job)
{
  if (MemAcc_JobProcessing_IsUnalignedReadCompareStep(job))
  {
    const MemAcc_MinReadSizeOfMemSectorBatchType minReadSize = MemAcc_GetMinReadSizeOfMemSectorBatch(
      MemAcc_GetMemSectorBatchIdxOfSubAddressArea(job->MngmtArea.JobStep.SubAddrAreaIdx));
    const MemAcc_DataType* alignmentBufferPtr = MemAcc_GetReadAlignmentBufferPtrOfSyncGroup(
      MemAcc_GetSyncGroupIdOfSubAddressArea(job->MngmtArea.JobStep.SubAddrAreaIdx));
    const MemAcc_LengthType bufferOffset = (MemAcc_LengthType)(job->MngmtArea.JobStep.PhysicalAddress % minReadSize);

    VStdLib_MemCpy(
      (job->JobArea.JobType == (MemAcc_AtomicJobType)MEMACC_COMPARE_JOB)
        ? job->JobArea.DataBuffer
        : &(job->JobArea.DataBuffer[job->MngmtArea.Offset]),
      &(alignmentBufferPtr[bufferOffset]),
      job->MngmtArea.JobStep.Length);
  }
}

#endif /* (MEMACC_READCOMPAREALIGNMENT_REQUIRED == STD_OFF) */

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

#if (MEMACC_MULTIBINARY_ISMULTIBINARYUSECASE == STD_ON)

/**********************************************************************************************************************
 * MemAcc_JobProcessing_DispatchJobStepToSharedMemory()
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
 *   requires job != NULL_PTR;
 * \endspec
 */
void MemAcc_JobProcessing_DispatchJobStepToSharedMemory(MemAcc_JobContextType* job) /* PRQA S 3673 */ /* MD_MemAcc_DispatchJobStepToSharedMemoryConstQualifier */
{
  MemAcc_AccessType saaAccessType = MemAcc_GetAccessTypeOfSubAddressArea(job->MngmtArea.JobStep.SubAddrAreaIdx);

  if (saaAccessType == MEMACC_MULTIBINARY_DIRECT_ACCESS)
  {
    MemAcc_MultiBinary_DispatchDirectJobStepToSharedMemory(job);
  }

#if (MEMACC_MULTIBINARY_ISSATELLITEBINARY == STD_ON)
# if (MEMACC_MULTIBINARY_HASREDIRECTREQUESTS == STD_ON)

  if (saaAccessType == MEMACC_MULTIBINARY_REDIRECT_ACCESS)
  {
    /* Could fail if BBM is enabled, however enabling BBM and MultiBinary is not allowed. */
    (void)MemAcc_JobProcessing_UpdateJobStepPhysicalAddress(job);

    /*
    * Direct and singlebinary jobs are set to pending when they are dispatched to memory.
    * For redirect jobs updating the shared memory is the point where the job is dispatched.
    */
    job->MngmtArea.JobStep.Status = MEMACC_JOB_PENDING;

#if (MEMACC_READCOMPAREALIGNMENT_REQUIRED == STD_OFF)
    if (MemAcc_JobProcessing_IsUnalignedReadCompareStep(job))
    {
      /* Change the address and length for unaligned read steps for dispatching and restore them afterwards. */
      const MemAcc_AddressType originalAddr = job->MngmtArea.JobStep.PhysicalAddress;
      const MemAcc_LengthType originalLength = job->MngmtArea.JobStep.Length;
      const MemAcc_MinReadSizeOfMemSectorBatchType minReadSize = MemAcc_GetMinReadSizeOfMemSectorBatch(
        MemAcc_GetMemSectorBatchIdxOfSubAddressArea(job->MngmtArea.JobStep.SubAddrAreaIdx));
      job->MngmtArea.JobStep.PhysicalAddress -= (job->MngmtArea.JobStep.PhysicalAddress % minReadSize);
      job->MngmtArea.JobStep.Length = (MemAcc_LengthType)minReadSize;
      MemAcc_MultiBinary_DispatchRedirectJobStepToSharedMemory(job);
      job->MngmtArea.JobStep.PhysicalAddress = originalAddr;
      job->MngmtArea.JobStep.Length = originalLength;
    }
    else
#endif /* (MEMACC_READCOMPAREALIGNMENT_REQUIRED == STD_OFF) */
    {
      MemAcc_MultiBinary_DispatchRedirectJobStepToSharedMemory(job);
    }
  }

# endif /* MEMACC_MULTIBINARY_HASREDIRECTREQUESTS */
#endif /* MEMACC_MULTIBINARY_ISSATELLITEBINARY */
}

#endif /* MEMACC_MULTIBINARY_ISMULTIBINARYUSECASE */

/**********************************************************************************************************************
 * MemAcc_JobProcessing_DispatchJobStepToMem()
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
 *   requires job != NULL_PTR;
 * \endspec
 */
void MemAcc_JobProcessing_DispatchJobStepToMem(MemAcc_JobContextType* job)
{
  if((job->MngmtArea.JobError == MEMACC_ERRORTYPE_NONE)
    && (job->MngmtArea.JobCanceled == FALSE))
  {
    /* E_NOT_OK can only occur if BBM is enabled. Otherwise it always returns E_OK. Preprocessor switch is only due to QAC issue id 2991 and 2995. */
#if (MEMACC_BBM_ENABLED == STD_ON)
    if(MemAcc_JobProcessing_UpdateJobStepPhysicalAddress(job) == E_OK)
#else
    (void)MemAcc_JobProcessing_UpdateJobStepPhysicalAddress(job);
#endif
    {
      /* It is important that the job step status is set to PENDING before the Mem driver job is called.
         Reason: GetJobInfo should always return mem driver job is pending, for example if for a Mem_Read
         an ECC error occurs as an interrupt during read operation */
      job->MngmtArea.JobStep.Status = MEMACC_JOB_PENDING;
      if(MemAcc_JobProcessing_DispatchJobStepToMemDriver(job) != E_OK)
      {
        job->MngmtArea.JobStep.Status = MEMACC_JOB_IDLE;
        job->MngmtArea.JobStep.Rejected = TRUE;
      }
    }
  }
}

/**********************************************************************************************************************
 * MemAcc_JobProcessing_UpdateJobStep()
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
 *   requires job != NULL_PTR;
 * \endspec
 */
void MemAcc_JobProcessing_UpdateJobStep(MemAcc_JobContextType* job)
{
  if(job->MngmtArea.JobStep.Status == MEMACC_JOB_PENDING)
  {
    MemAcc_JobProcessing_ProcessJobStepResult(job);
#if (MEMACC_COMPAREAPI_ENABLED == STD_ON)
    MemAcc_JobProcessing_ProcessCompareJobStepBuffer(job);
#endif /* MEMACC_COMPAREAPI_ENABLED */
    MemAcc_JobProcessing_ProcessJobStepFinished(job);
  }
  else if (job->MngmtArea.JobCanceled == FALSE)
  {
    MemAcc_JobProcessing_EndJob(&job->MngmtArea, job->JobArea.Length, MEMACC_FAILED);
  }
  else
  {
    /* do nothing */
  }

  if(job->MngmtArea.JobStep.Status == MEMACC_JOB_IDLE)
  {
    MemAcc_JobProcessing_ProcessJobCompletion(job);
  }
}

/**********************************************************************************************************************
 *  MemAcc_JobProcessing_CalculateNextJobStep()
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
Std_ReturnType MemAcc_JobProcessing_CalculateNextJobStep(
const MemAcc_JobAreaType* JobArea,
MemAcc_JobStepType* JobStep,
const MemAcc_LengthType Offset,
const boolean isNewJob
)
{
  Std_ReturnType retValue = E_NOT_OK;

  const MemAcc_AddressType logicalAddress = JobArea->Address + Offset;

  const MemAcc_SubAddressAreaIndexType subAAIndex = (JobArea->JobType == (MemAcc_AtomicJobType)MEMACC_MEMHWSPECIFIC_JOB)
                            ? MemAcc_Utils_GetSubAddrAreaIndexOfHwId(JobArea->AddressAreaIndex, JobArea->HwId)
                            : MemAcc_Utils_GetSubAddrAreaIndexOfAddress(JobArea->AddressAreaIndex, logicalAddress);

  if(subAAIndex < MemAcc_GetSubAddressAreaEndIdxOfAddressArea(JobArea->AddressAreaIndex))
  {
    /*@ assert subAAIndex < MemAcc_GetSizeOfSubAddressArea(); */  /* VCA_MemAcc_SubAddressAreaIndexOfJobStepAlwaysValid */
    if (MemAcc_MemAccessControl_IsMemAccessAllowed(subAAIndex, (MemAcc_JobType) JobArea->JobType)) /* PRQA S 4342 */ /* MD_MemAcc_JobTypeEnumCasting */
    {
      retValue = E_OK;

      if((JobStep->LogicalAddress == logicalAddress) && (JobStep->SubAddrAreaIdx == subAAIndex) && (isNewJob == FALSE))
      {
        /* Its a job step retry (either for BBM or for retry counter). In this case just reset a few values. */
        JobStep->PhysicalAddress = 0u;
        JobStep->Rejected = FALSE;
        JobStep->IsSuspended = FALSE;
#if (MEMACC_BBM_ENABLED == STD_ON)
        JobStep->MemError = MEMACC_MEMERRORTYPE_NONE;
#endif /* MEMACC_BBM_ENABLED == STD_ON */
      }
      else
      {
        JobStep->SubAddrAreaIdx = subAAIndex;
        JobStep->LogicalAddress = logicalAddress;
        JobStep->PhysicalAddress = 0u;
        JobStep->Length = MemAcc_JobProcessing_CalculateJobStepLength(JobArea, JobStep, Offset);
        JobStep->RetryCounter = MemAcc_Utils_GetNumberOfJobStepRetries(subAAIndex, (MemAcc_JobType)JobArea->JobType); /* PRQA S 4342 */ /* MD_MemAcc_JobTypeEnumCasting */
        JobStep->Rejected = FALSE;
        JobStep->IsSuspended = FALSE;
#if (MEMACC_BBM_ENABLED == STD_ON)
        JobStep->MemError = MEMACC_MEMERRORTYPE_NONE;
#endif /* MEMACC_BBM_ENABLED == STD_ON */
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

/***********************************************************************************************************************
 *  VCA JUSTIFICATIONS
 **********************************************************************************************************************/
/* VCA_JUSTIFICATION_BEGIN

\ID VCA_MemAcc_LowerLayerIndexAlwaysValid
  \DESCRIPTION Access to MemAcc_LowerLayer via indirection over MemAcc_SubAddressArea.
  \COUNTERMEASURE \N Qualified use-case CSL03 of ComStackLib.

\ID VCA_MemAcc_AddressAreaIndexOfJobAlwaysValid
  \DESCRIPTION Job store the AddressArea Index they are associated with.
               The JobProcessing Unit only processes valid jobs with valid address area indices from the MemAcc_Queue.
               AddressAreaIndex is only set during MemAcc_Queue_ResetJob where only valid indices are processed.
  \COUNTERMEASURE \R The MemAcc_Queue_ResetJob is only called in a for loop that iterates over all valid
                     AddressArea indices.

\ID VCA_MemAcc_SubAddressAreaIndexOfJobStepAlwaysValid
  \DESCRIPTION Job steps store the SubAddressArea Index they are associated with.
               This SubAddressArea Index will be used to retrieve other necessary job step information.
               If a SubAddressArea Index is invalid it can result in out of bounds accesses off the configuration array.
               The SubAddressArea Index used within the JobProcessing Unit is only calculated within
               MemAcc_JobProcessing_CalculateNextJobStep().
  \COUNTERMEASURE \R A runtime check within the MemAcc_JobProcessing_CalculateNextJobStep() ensures that the
                     SubAddressAreaIndex is always valid.

VCA_JUSTIFICATION_END */

/***********************************************************************************************************************
 *  COV JUSTIFICATION
 **********************************************************************************************************************/
/* COV_JUSTIFICATION_BEGIN

\ID COV_MemAcc_JobProcessing_MISRA
\ACCEPT XX
\REASON [COV_MSR_MISRA]

\ID COV_MemAcc_JobProcessing_ProcessCompareJobStepBuffer_DefensiveCheck
\ACCEPT TX
\REASON Defensive check to prevent unsigned integer underflow when calculating compareStart. Under normal operation,
        Offset is always >= JobStep.Length after EndJobStep is called. This check guards against a UBSAN error.

COV_JUSTIFICATION_END */

/**********************************************************************************************************************
 *  END OF FILE: MemAcc_JobProcessing.c
 *********************************************************************************************************************/
