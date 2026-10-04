/**********************************************************************************************************************
 *  COPYRIGHT
 *  ------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2025 by Vector Informatik GmbH. All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  ------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/*!        \file  Fee_30_FlexNor.c
 *        \brief  Fee_30_FlexNor component source file.
 *      \details  Implementation of the Fee_30_FlexNor component interface.
 *         \unit  Fee
 *********************************************************************************************************************/

#define FEE_30_FLEXNOR_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Fee_30_FlexNor.h"

#include "Fee_30_FlexNor_ErrorChecks.h"
#include "Fee_30_FlexNor_Initializer.h"

#include "Fee_30_FlexNor_ConfigInterface.h"
#include "Fee_30_FlexNor_Scheduler.h"
#include "Fee_30_FlexNor_Shared.h"

#include "Fee_30_FlexNor_InternalJobs.h"
#include "Fee_30_FlexNor_LookupTable.h"
#include "Fee_30_FlexNor_Partition.h"
#include "Fee_30_FlexNor_SectorContainer.h"

#include "Fee_30_FlexNor_FlashAccess.h"
#include "Fee_30_FlexNor_DiagnosticHandler.h"
#include "Fee_30_FlexNor_Internal.h"

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/
/* Check the version of Fee_30_FlexNor header file */
#if (  (FEE_30_FLEXNOR_SW_MAJOR_VERSION != (4u)) \
    || (FEE_30_FLEXNOR_SW_MINOR_VERSION != (4u)) \
    || (FEE_30_FLEXNOR_SW_PATCH_VERSION != (1u)) )
# error "Vendor specific version numbers of Fee_30_FlexNor.c and Fee_30_FlexNor.h are inconsistent"
#endif

/* Check the version of the configuration header file */
#if (  (FEE_30_FLEXNOR_CFG_MAJOR_VERSION != (4u)) \
    || (FEE_30_FLEXNOR_CFG_MINOR_VERSION != (4u)) )
# error "Version numbers of Fee_30_FlexNor.c and Fee_30_FlexNor_Cfg.h are inconsistent!"
#endif

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/
#if !defined (FEE_30_FLEXNOR_LOCAL) /* COV_FEE_30_FLEXNOR_COMPATIBILITY */
# define FEE_30_FLEXNOR_LOCAL static
#endif

#if !defined (FEE_30_FLEXNOR_LOCAL_INLINE) /* COV_FEE_30_FLEXNOR_COMPATIBILITY */
# define FEE_30_FLEXNOR_LOCAL_INLINE LOCAL_INLINE
#endif

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/
#define FEE_30_FLEXNOR_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Indicates if the Fee is already initialized. */
FEE_30_FLEXNOR_LOCAL boolean Fee_30_FlexNor_IsInitialized = FALSE;

/*! Indicates if an API is currently active. */
FEE_30_FLEXNOR_LOCAL volatile boolean Fee_30_FlexNor_IsApiActive = FALSE;

/*! Indicates if an internal job is currently running. */
FEE_30_FLEXNOR_LOCAL boolean Fee_30_FlexNor_InternalJobsActive = FALSE;

/*! Indicates if a user job is currently stored. */
FEE_30_FLEXNOR_LOCAL boolean Fee_30_FlexNor_JobStored = FALSE;

/*! Variable which stores the user job data. */
FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_JobType Fee_30_FlexNor_Job = {
    .Service = FEE_30_FLEXNOR_SID_INIT,
    .PartitionId = 0u,
    .BlockId = 0u,
    .Length = 0u,
    .Offset = 0u,
    .ReadBuffer = NULL_PTR,
    .WriteBuffer = NULL_PTR,
    .JobResult = MEMIF_JOB_OK
 };

/*! Variable which stores the data of the stored user job. */
FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_JobType Fee_30_FlexNor_StoredJob = {
    .Service = FEE_30_FLEXNOR_SID_INIT,
    .PartitionId = 0u,
    .BlockId = 0u,
    .Length = 0u,
    .Offset = 0u,
    .ReadBuffer = NULL_PTR,
    .WriteBuffer = NULL_PTR,
    .JobResult = MEMIF_JOB_OK
 };

#define FEE_30_FLEXNOR_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define FEE_30_FLEXNOR_START_SEC_CODE
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Fee_30_FlexNor_DispatchJob()
 *********************************************************************************************************************/
/*! \brief       Dispatches the given job.
 *  \details     If a job is currently canceled by underlying layer: Saves the public job.
 *               If an internal job is pending: Triggers internal Job.
                 Otherwise public job is forwarded.
 *  \param[in]   job               Job that shall be dispatched
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FEE_30_FLEXNOR_LOCAL FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_DispatchJob(Fee_30_FlexNor_JobType job);

/**********************************************************************************************************************
 * Fee_30_FlexNor_NotifyNvMIfNecessary()
 *********************************************************************************************************************/
/*! \brief       Notifies the NvM about a finished Fee job
 *  \details     -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FEE_30_FLEXNOR_LOCAL FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_NotifyNvMIfNecessary(void);

/**********************************************************************************************************************
 * Fee_30_FlexNor_ForwardPublicJob()
 *********************************************************************************************************************/
/*! \brief       Forwards the stored public job.
 *  \details     -
 *  \pre         No internal job is pending anymore.
 *  \pre         Public job is pending, therefore Fee_30_FlexNor_Job is set.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FEE_30_FLEXNOR_LOCAL FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_ForwardPublicJob(void);

/**********************************************************************************************************************
 * Fee_30_FlexNor_IsBlockNumberInvalid()
 *********************************************************************************************************************/
/*! \brief       Checks if the block number in the given block configuration is invalid
 *  \details     A block number is invalid if the given block config is null oder the block is a lookup table block.
 *  \param[in]   blockConfig    Pointer to the block configuration to check
 *  \return      TRUE   The given block number is invalid
 *               FALSE  The given block number is valid
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FEE_30_FLEXNOR_LOCAL_INLINE FUNC(boolean, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_IsBlockNumberInvalid(
    Fee_30_FlexNor_ConstBlockConfigPtrType const blockConfig);

/**********************************************************************************************************************
 * Fee_30_FlexNor_IsOffsetInvalid()
 *********************************************************************************************************************/
/*! \brief       Checks if the given offset is invalid for the block
 *  \details     An offset is invalid if the given block config is null or the offset is larger than the block length.
 *  \param[in]   blockConfig    Pointer to the block configuration containing the block length
 *  \param[in]   offset         Offset to check
 *  \return      TRUE   The given offset is invalid
 *               FALSE  The given offset is valid
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FEE_30_FLEXNOR_LOCAL_INLINE FUNC(boolean, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_IsOffsetInvalid(
    Fee_30_FlexNor_ConstBlockConfigPtrType const blockConfig,
    Fee_30_FlexNor_BlockOffsetType offset);

/**********************************************************************************************************************
 * Fee_30_FlexNor_IsLengthInvalid()
 *********************************************************************************************************************/
/*! \brief       Checks if the given read length is invalid for the block
 *  \details     The length is invalid if the block config is null, the length plus the offset exceeds the block lenght
 *               or the given length is zero.
 *  \param[in]   blockConfig    Pointer to the block configuration containing the block length
 *  \param[in]   offset         Given read offset
 *  \param[in]   length         Length to check
 *  \return      TRUE   The given length is invalid
 *               FALSE  The given length is valid
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FEE_30_FLEXNOR_LOCAL_INLINE FUNC(boolean, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_IsLengthInvalid(
    Fee_30_FlexNor_ConstBlockConfigPtrType const blockConfig,
    Fee_30_FlexNor_BlockOffsetType offset,
    Fee_30_FlexNor_LengthType length);

/**********************************************************************************************************************
 * Fee_30_FlexNor_IsNoImmediateBlock()
 *********************************************************************************************************************/
/*! \brief       Checks if the given block is no immediate block
 *  \details     The block is no immediate block if the given block config is null or the HasImmediateData flag is turned off.
 *  \param[in]   blockConfig    Pointer to the block configuration containing containing the flag
 *  \return      TRUE   The given block is not an immediate block
 *               FALSE  The given block is an immediate block
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FEE_30_FLEXNOR_LOCAL_INLINE FUNC(boolean, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_IsNoImmediateBlock(
    Fee_30_FlexNor_ConstBlockConfigPtrType const blockConfig);

/**********************************************************************************************************************
 * Fee_30_FlexNor_IsPersistLookuptableAllowed()
 *********************************************************************************************************************/
/*! \brief       Checks if it is allowed to persist the LUT.
 *  \details     -
 *  \param[in]   job                  Previously executed user job.
 *  \return      TRUE                 Persist LUT is allowd.
 *               FALSE                Persist LUT is not allowed.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(boolean, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_IsPersistLookuptableAllowed(Fee_30_FlexNor_JobType job);


/**********************************************************************************************************************
 * Fee_30_FlexNor_SetupFollowUpJob()
 *********************************************************************************************************************/
/*! \brief       Setup the follow up job.
 *  \details     Setup one of the following jobs in this order:
 *               - Requested user job if internal jobs have finished.
 *               - Stored user job, if a job was stored during cancel was denied.
 *               - Persist lookup table, if it is allowed and requerd.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SetupFollowUpJob(void);


/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * Fee_30_FlexNor_DispatchJob()
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
FEE_30_FLEXNOR_LOCAL FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_DispatchJob(Fee_30_FlexNor_JobType job)
{
    if(Fee_30_FlexNor_Scheduler_GetStatus() == FEE_30_FLEXNOR_CANCELLING)
    {
        Fee_30_FlexNor_StoredJob = job;
        Fee_30_FlexNor_JobStored = TRUE;
    }
    else
    {
        Fee_30_FlexNor_Job = job;

        Fee_30_FlexNor_InternalJobs_Run(&Fee_30_FlexNor_Job); /* SBSW_Fee_30_FlexNor_FunctionCallWithJobPointer */
        if(Fee_30_FlexNor_Scheduler_GetStatus() == FEE_30_FLEXNOR_BUSY)
        {
            Fee_30_FlexNor_InternalJobsActive = TRUE;
        }
        else if(Fee_30_FlexNor_Job.JobResult != MEMIF_JOB_FAILED)
        {
            Fee_30_FlexNor_ForwardPublicJob();
        }
        else
        {
            /* Intentionally left empty. */
        }
    }
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_NotifyNvMIfNecessary()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FEE_30_FLEXNOR_LOCAL FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_NotifyNvMIfNecessary(void)
{
    if (Fee_30_FlexNor_GetStatus() == MEMIF_IDLE)
    {
        Fee_30_FlexNor_Shared_NotifyNvM(Fee_30_FlexNor_Job.JobResult);
    }
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_ForwardPublicJob()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FEE_30_FLEXNOR_LOCAL FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_ForwardPublicJob(void)
{
    switch (Fee_30_FlexNor_Job.Service)
    {
        case FEE_30_FLEXNOR_SID_READ:
            Fee_30_FlexNor_Partition_ReadBlock(&Fee_30_FlexNor_Job); /* SBSW_Fee_30_FlexNor_FunctionCallWithJobPointer */
            break;
        case FEE_30_FLEXNOR_SID_WRITE:
        case FEE_30_FLEXNOR_SID_INVALIDATEBLOCK:
        case FEE_30_FLEXNOR_SID_ERASEIMMEDIATEBLOCK:
            Fee_30_FlexNor_Partition_WriteBlock(&Fee_30_FlexNor_Job); /* SBSW_Fee_30_FlexNor_FunctionCallWithJobPointer */
            break;
        default:
            /* Unsupported service ids doesn't lead to a job setup. */
            /* FEE_30_FLEXNOR_SID_PERSIST_LOOKUP_TABLE cannot be requested by the user anymore because it was turned to
               an internal job. */
            break;
    }
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_IsBlockNumberInvalid()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FEE_30_FLEXNOR_LOCAL_INLINE FUNC(boolean, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_IsBlockNumberInvalid(
    Fee_30_FlexNor_ConstBlockConfigPtrType const blockConfig)
{
    return (blockConfig == NULL_PTR) || (blockConfig->Id == FEE_30_FLEXNOR_LUTBLOCKID);
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_IsOffsetInvalid()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FEE_30_FLEXNOR_LOCAL_INLINE FUNC(boolean, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_IsOffsetInvalid(
    Fee_30_FlexNor_ConstBlockConfigPtrType const blockConfig,
    Fee_30_FlexNor_BlockOffsetType offset)
{
    return (blockConfig == NULL_PTR) || (offset >= blockConfig->Length);
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_IsLengthInvalid()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FEE_30_FLEXNOR_LOCAL_INLINE FUNC(boolean, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_IsLengthInvalid(
    Fee_30_FlexNor_ConstBlockConfigPtrType const blockConfig,
    Fee_30_FlexNor_BlockOffsetType offset,
    Fee_30_FlexNor_LengthType length)
{
    return (blockConfig == NULL_PTR) || ((offset + length) > blockConfig->Length) || (length == 0u);
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_IsNoImmediateBlock()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FEE_30_FLEXNOR_LOCAL_INLINE FUNC(boolean, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_IsNoImmediateBlock(
    Fee_30_FlexNor_ConstBlockConfigPtrType const blockConfig)
{
    return (blockConfig == NULL_PTR) || (blockConfig->HasImmediateData == FALSE);
}

/***********************************************************************************************************************
 *  Fee_30_FlexNor_IsPersistLookuptableAllowed()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
FUNC(boolean, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_IsPersistLookuptableAllowed(Fee_30_FlexNor_JobType job)
{
    boolean isPersistLookuptableAllowed = FALSE;

    boolean isBootloaderModeEnabled = Fee_30_FlexNor_ConfigInterface_IsBootloaderModeEnabled();
    boolean isWriteLikeJob = Fee_30_FlexNor_Shared_IsWriteLikeJob(job.Service);

    if((isBootloaderModeEnabled == FALSE) && (isWriteLikeJob == TRUE) && (job.JobResult != MEMIF_JOB_FAILED))
    {
        isPersistLookuptableAllowed = TRUE;
    }

    return isPersistLookuptableAllowed;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SetupFollowUpJob()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SetupFollowUpJob(void)
{
    if(Fee_30_FlexNor_InternalJobsActive == TRUE)
    {
        Fee_30_FlexNor_InternalJobsActive = FALSE;
        if(Fee_30_FlexNor_Job.JobResult != MEMIF_JOB_FAILED)
        {
            Fee_30_FlexNor_ForwardPublicJob();
        }
    }
    else if(Fee_30_FlexNor_JobStored == TRUE)
    {
        Fee_30_FlexNor_JobStored = FALSE;
        Fee_30_FlexNor_DispatchJob(Fee_30_FlexNor_StoredJob); /* SBSW_Fee_30_FlexNor_JobDispatching */
    }
    else if (Fee_30_FlexNor_IsPersistLookuptableAllowed(Fee_30_FlexNor_Job)) /* SBSW_Fee_30_FlexNor_ForwardJobToCheckIfPersistLutIsAllowed */
    {
        Fee_30_FlexNor_LookupTable_PersistIfRequired(Fee_30_FlexNor_Job.PartitionId);
    }
    else
    {
        /* Intentionally left empty. */
    }
}

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  Fee_30_FlexNor_Init()
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
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Init(void)
{
    if(Fee_30_FlexNor_IsApiActive == TRUE)
    {
        Fee_30_FlexNor_ErrorChecks_ReportDetError(FEE_30_FLEXNOR_SID_INIT, FEE_30_FLEXNOR_E_REENTRANCY_VIOLATED);
    }
    else
    {
        Fee_30_FlexNor_IsApiActive = TRUE;
        Fee_30_FlexNor_ConfigInterface_SetConfig(&Fee_30_FlexNor_Config); /* SBSW_Fee_30_FlexNor_ConfigPointer */

        Fee_30_FlexNor_Initializer_Init();

        Fee_30_FlexNor_IsInitialized = TRUE;
        Fee_30_FlexNor_InternalJobsActive = FALSE;
        Fee_30_FlexNor_JobStored = FALSE;
        Fee_30_FlexNor_Job.JobResult = MEMIF_JOB_OK;
    }

    Fee_30_FlexNor_IsApiActive = FALSE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SetMode()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SetMode(MemIf_ModeType mode)
{
    /*
     * Because there is no use case for changing the mode of the FEE and the underlying FLS, the service does nothing.
     * The API itself is still provided to prevent compilation errors.
     */
    FEE_DUMMY_STATEMENT(mode);
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Read()
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
FUNC(Std_ReturnType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Read( /* PRQA S 6050, 6080, 6030 */ /* MD_MSR_STCAL, MD_MSR_STMIF, MD_MSR_STCYC */
    Fee_30_FlexNor_BlockNumberType blockNumber,
    Fee_30_FlexNor_BlockOffsetType offset,
    Fee_30_FlexNor_DataPtrType dataBufferPtr,
    uint16 length)
{
    Std_ReturnType jobAcceptance = E_NOT_OK;
    Fee_30_FlexNor_ErrorCode errorId = FEE_30_FLEXNOR_E_NO_ERROR;
    Fee_30_FlexNor_ConstBlockConfigPtrType const blockConfig = Fee_30_FlexNor_ConfigInterface_GetBlockConfig(blockNumber);
    MemIf_StatusType currentStatus = Fee_30_FlexNor_GetStatus();

    if(Fee_30_FlexNor_ErrorChecks_IsDetConditionTrue(Fee_30_FlexNor_GetStatus() == MEMIF_UNINIT) == TRUE)
    {
        errorId = FEE_30_FLEXNOR_E_UNINIT;
    }
    else if (Fee_30_FlexNor_ErrorChecks_IsDetConditionTrue(Fee_30_FlexNor_IsBlockNumberInvalid(blockConfig)) == TRUE) /* SBSW_Fee_30_FlexNor_FunctionCallWithConstPointer */
    {
        errorId = FEE_30_FLEXNOR_E_INVALID_BLOCK_NO;
    }
    else if (Fee_30_FlexNor_ErrorChecks_IsDetConditionTrue(Fee_30_FlexNor_IsOffsetInvalid(blockConfig, offset)) == TRUE) /* SBSW_Fee_30_FlexNor_FunctionCallWithConstPointer */
    {
        errorId = FEE_30_FLEXNOR_E_INVALID_BLOCK_OFS;
    }
    else if (Fee_30_FlexNor_ErrorChecks_IsDetConditionTrue(Fee_30_FlexNor_IsLengthInvalid(blockConfig, offset, length)) == TRUE) /* SBSW_Fee_30_FlexNor_FunctionCallWithConstPointer */
    {
        errorId = FEE_30_FLEXNOR_E_INVALID_BLOCK_LEN;
    }
    else if(Fee_30_FlexNor_ErrorChecks_IsDetConditionTrue(dataBufferPtr == NULL_PTR) == TRUE)
    {
        errorId = FEE_30_FLEXNOR_E_PARAM_POINTER;
    }
    else if (Fee_30_FlexNor_IsApiActive == TRUE)
    {
        errorId = FEE_30_FLEXNOR_E_REENTRANCY_VIOLATED;
    }
    else if(currentStatus == MEMIF_BUSY)
    {
        errorId = FEE_30_FLEXNOR_E_BUSY;
    }
    else
    {
        Fee_30_FlexNor_IsApiActive = TRUE;
        if(currentStatus != MEMIF_UNINIT)
        {
            Fee_30_FlexNor_ConstPartitionConfigPtrType partitionConfig = Fee_30_FlexNor_ConfigInterface_GetPartitionConfigOfBlock(blockNumber);

            Fee_30_FlexNor_JobType readJob;
            readJob.Service = FEE_30_FLEXNOR_SID_READ;
            readJob.PartitionId = partitionConfig->PartitionId;
            readJob.BlockId = blockConfig->Id;
            readJob.Offset = offset;
            readJob.ReadBuffer = dataBufferPtr;
            readJob.WriteBuffer = NULL_PTR;
            readJob.Length = length;
            readJob.JobResult = MEMIF_JOB_PENDING;

            Fee_30_FlexNor_DispatchJob(readJob); /* SBSW_Fee_30_FlexNor_JobDispatching */

            Fee_30_FlexNor_NotifyNvMIfNecessary();
            jobAcceptance = E_OK;
        }
    }

    if(errorId != FEE_30_FLEXNOR_E_NO_ERROR)
    {
        Fee_30_FlexNor_ErrorChecks_ReportDetError(FEE_30_FLEXNOR_SID_READ, errorId);
    }

    Fee_30_FlexNor_IsApiActive = FALSE;
    return jobAcceptance;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Write()
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
 */
FUNC(Std_ReturnType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Write( /* PRQA S 6050, 6080 */ /* MD_MSR_STCAL, MD_MSR_STMIF */
    Fee_30_FlexNor_BlockNumberType blockNumber,
    Fee_30_FlexNor_ConstDataPtrType dataBufferPtr)
{
    Std_ReturnType jobAcceptance = E_NOT_OK;
    Fee_30_FlexNor_ErrorCode errorId = FEE_30_FLEXNOR_E_NO_ERROR;
    Fee_30_FlexNor_ConstBlockConfigPtrType const blockConfig = Fee_30_FlexNor_ConfigInterface_GetBlockConfig(blockNumber);
    MemIf_StatusType currentStatus = Fee_30_FlexNor_GetStatus();

    if(Fee_30_FlexNor_ErrorChecks_IsDetConditionTrue(Fee_30_FlexNor_GetStatus() == MEMIF_UNINIT) == TRUE)
    {
        errorId = FEE_30_FLEXNOR_E_UNINIT;
    }
    else if (Fee_30_FlexNor_ErrorChecks_IsDetConditionTrue(Fee_30_FlexNor_IsBlockNumberInvalid(blockConfig)) == TRUE) /* SBSW_Fee_30_FlexNor_FunctionCallWithConstPointer */
    {
        errorId = FEE_30_FLEXNOR_E_INVALID_BLOCK_NO;
    }
    else if(Fee_30_FlexNor_ErrorChecks_IsDetConditionTrue(dataBufferPtr == NULL_PTR) == TRUE)
    {
        errorId = FEE_30_FLEXNOR_E_PARAM_POINTER;
    }
    else if (Fee_30_FlexNor_IsApiActive == TRUE)
    {
        errorId = FEE_30_FLEXNOR_E_REENTRANCY_VIOLATED;
    }
    else if(currentStatus == MEMIF_BUSY)
    {
        errorId = FEE_30_FLEXNOR_E_BUSY;
    }
    else
    {
        Fee_30_FlexNor_IsApiActive = TRUE;
        if(currentStatus != MEMIF_UNINIT)
        {
            Fee_30_FlexNor_ConstPartitionConfigPtrType partitionConfig = Fee_30_FlexNor_ConfigInterface_GetPartitionConfigOfBlock(blockNumber);

            Fee_30_FlexNor_JobType writeJob;
            writeJob.Service = FEE_30_FLEXNOR_SID_WRITE;
            writeJob.PartitionId = partitionConfig->PartitionId;
            writeJob.BlockId = blockConfig->Id;
            writeJob.ReadBuffer = NULL_PTR;
            writeJob.WriteBuffer = dataBufferPtr;
            writeJob.Length = blockConfig->Length;
            writeJob.Offset = 0u;
            writeJob.JobResult = MEMIF_JOB_PENDING;

            Fee_30_FlexNor_DispatchJob(writeJob); /* SBSW_Fee_30_FlexNor_JobDispatching */

            Fee_30_FlexNor_NotifyNvMIfNecessary();
            jobAcceptance = E_OK;
        }
    }

    if(errorId != FEE_30_FLEXNOR_E_NO_ERROR)
    {
        Fee_30_FlexNor_ErrorChecks_ReportDetError(FEE_30_FLEXNOR_SID_WRITE, errorId);
    }

    Fee_30_FlexNor_IsApiActive = FALSE;
    return jobAcceptance;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Cancel()
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
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Cancel(void) /* PRQA S 6050, 6080 */ /* MD_MSR_STCAL, MD_MSR_STMIF */
{
    Fee_30_FlexNor_ErrorCode errorId = FEE_30_FLEXNOR_E_NO_ERROR;
    MemIf_StatusType currentStatus = Fee_30_FlexNor_GetStatus();

    if(Fee_30_FlexNor_ErrorChecks_IsDetConditionTrue(Fee_30_FlexNor_GetStatus() == MEMIF_UNINIT) == TRUE)
    {
        errorId = FEE_30_FLEXNOR_E_UNINIT;
    }
    else if (Fee_30_FlexNor_IsApiActive == TRUE)
    {
        errorId = FEE_30_FLEXNOR_E_REENTRANCY_VIOLATED;
    }
    else if(currentStatus != MEMIF_BUSY)
    {
        Fee_30_FlexNor_ErrorChecks_ReportRuntimeError(FEE_30_FLEXNOR_SID_CANCEL, FEE_30_FLEXNOR_E_INVALID_CANCEL);
    }
    else
    {
        Fee_30_FlexNor_IsApiActive = TRUE;
        Fee_30_FlexNor_Scheduler_Cancel();

        if(Fee_30_FlexNor_Scheduler_GetStatus() == FEE_30_FLEXNOR_IDLE)
        {
            Fee_30_FlexNor_FlashAccess_Cancel();
        }

        Fee_30_FlexNor_JobStored = FALSE;
        Fee_30_FlexNor_InternalJobsActive = FALSE;
        Fee_30_FlexNor_Job.JobResult = MEMIF_JOB_CANCELED;
        Fee_30_FlexNor_NotifyNvMIfNecessary();
    }

    if(errorId != FEE_30_FLEXNOR_E_NO_ERROR)
    {
        Fee_30_FlexNor_ErrorChecks_ReportDetError(FEE_30_FLEXNOR_SID_CANCEL, errorId);
    }

    Fee_30_FlexNor_IsApiActive = FALSE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_InvalidateBlock()
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
FUNC(Std_ReturnType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_InvalidateBlock(Fee_30_FlexNor_BlockNumberType blockNumber) /* PRQA S 6050, 6080 */ /* MD_MSR_STCAL, MD_MSR_STMIF */
{
    Std_ReturnType jobAcceptance = E_NOT_OK;
    Fee_30_FlexNor_ErrorCode errorId = FEE_30_FLEXNOR_E_NO_ERROR;
    Fee_30_FlexNor_ConstBlockConfigPtrType const blockConfig = Fee_30_FlexNor_ConfigInterface_GetBlockConfig(blockNumber);
    MemIf_StatusType currentStatus = Fee_30_FlexNor_GetStatus();

    if(Fee_30_FlexNor_ErrorChecks_IsDetConditionTrue(Fee_30_FlexNor_GetStatus() == MEMIF_UNINIT) == TRUE)
    {
        errorId = FEE_30_FLEXNOR_E_UNINIT;
    }
    else if (Fee_30_FlexNor_ErrorChecks_IsDetConditionTrue(Fee_30_FlexNor_IsBlockNumberInvalid(blockConfig)) == TRUE) /* SBSW_Fee_30_FlexNor_FunctionCallWithConstPointer */
    {
        errorId = FEE_30_FLEXNOR_E_INVALID_BLOCK_NO;
    }
    else if (Fee_30_FlexNor_IsApiActive == TRUE)
    {
        errorId = FEE_30_FLEXNOR_E_REENTRANCY_VIOLATED;
    }
    else if(currentStatus == MEMIF_BUSY)
    {
        errorId = FEE_30_FLEXNOR_E_BUSY;
    }
    else
    {
        Fee_30_FlexNor_IsApiActive = TRUE;
        if(currentStatus != MEMIF_UNINIT)
        {
            Fee_30_FlexNor_ConstPartitionConfigPtrType partitionConfig = Fee_30_FlexNor_ConfigInterface_GetPartitionConfigOfBlock(blockNumber);

            Fee_30_FlexNor_JobType invalidationJob;
            invalidationJob.Service = FEE_30_FLEXNOR_SID_INVALIDATEBLOCK;
            invalidationJob.PartitionId = partitionConfig->PartitionId;
            invalidationJob.BlockId = blockConfig->Id;
            invalidationJob.ReadBuffer = NULL_PTR;
            invalidationJob.WriteBuffer = NULL_PTR;
            invalidationJob.Length = 0u;
            invalidationJob.Offset = 0u;
            invalidationJob.JobResult = MEMIF_JOB_PENDING;

            Fee_30_FlexNor_DispatchJob(invalidationJob); /* SBSW_Fee_30_FlexNor_JobDispatching */

            Fee_30_FlexNor_NotifyNvMIfNecessary();
            jobAcceptance = E_OK;
        }
    }

    if(errorId != FEE_30_FLEXNOR_E_NO_ERROR)
    {
        Fee_30_FlexNor_ErrorChecks_ReportDetError(FEE_30_FLEXNOR_SID_INVALIDATEBLOCK, errorId);
    }

    Fee_30_FlexNor_IsApiActive = FALSE;
    return jobAcceptance;
} /* PRQA S 6050, 6080 */ /* MD_MSR_STCAL, MD_MSR_STMIF */

/**********************************************************************************************************************
 * Fee_30_FlexNor_EraseImmediateBlock()
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
 */
FUNC(Std_ReturnType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_EraseImmediateBlock(Fee_30_FlexNor_BlockNumberType blockNumber) /* PRQA S 6050, 6080 */ /* MD_MSR_STCAL, MD_MSR_STMIF */
{
    Std_ReturnType jobAcceptance = E_NOT_OK;
    Fee_30_FlexNor_ErrorCode errorId = FEE_30_FLEXNOR_E_NO_ERROR;
    Fee_30_FlexNor_ConstBlockConfigPtrType const blockConfig = Fee_30_FlexNor_ConfigInterface_GetBlockConfig(blockNumber);
    MemIf_StatusType currentStatus = Fee_30_FlexNor_GetStatus();

    if(Fee_30_FlexNor_ErrorChecks_IsDetConditionTrue(Fee_30_FlexNor_GetStatus() == MEMIF_UNINIT) == TRUE)
    {
        errorId = FEE_30_FLEXNOR_E_UNINIT;
    }
    else if (Fee_30_FlexNor_ErrorChecks_IsDetConditionTrue(Fee_30_FlexNor_IsBlockNumberInvalid(blockConfig)) == TRUE) /* SBSW_Fee_30_FlexNor_FunctionCallWithConstPointer */
    {
        errorId = FEE_30_FLEXNOR_E_INVALID_BLOCK_NO;
    }
    else if (Fee_30_FlexNor_ErrorChecks_IsDetConditionTrue(Fee_30_FlexNor_IsNoImmediateBlock(blockConfig)) == TRUE) /* SBSW_Fee_30_FlexNor_FunctionCallWithConstPointer */
    {
        errorId = FEE_30_FLEXNOR_E_INVALID_BLOCK_NO;
    }
    else if (Fee_30_FlexNor_IsApiActive == TRUE)
    {
        errorId = FEE_30_FLEXNOR_E_REENTRANCY_VIOLATED;
    }
    else if(currentStatus == MEMIF_BUSY)
    {
        errorId = FEE_30_FLEXNOR_E_BUSY;
    }
    else
    {
        Fee_30_FlexNor_IsApiActive = TRUE;
        if(currentStatus != MEMIF_UNINIT)
        {
            Fee_30_FlexNor_ConstPartitionConfigPtrType partitionConfig = Fee_30_FlexNor_ConfigInterface_GetPartitionConfigOfBlock(blockNumber);

            Fee_30_FlexNor_JobType eraseImmediateJob;
            eraseImmediateJob.Service = FEE_30_FLEXNOR_SID_ERASEIMMEDIATEBLOCK;
            eraseImmediateJob.PartitionId = partitionConfig->PartitionId;
            eraseImmediateJob.BlockId = blockConfig->Id;
            eraseImmediateJob.ReadBuffer = NULL_PTR;
            eraseImmediateJob.WriteBuffer = NULL_PTR;
            eraseImmediateJob.Length = 0u;
            eraseImmediateJob.Offset = 0u;
            eraseImmediateJob.JobResult = MEMIF_JOB_PENDING;

            Fee_30_FlexNor_DispatchJob(eraseImmediateJob); /* SBSW_Fee_30_FlexNor_JobDispatching */

            Fee_30_FlexNor_NotifyNvMIfNecessary();
            jobAcceptance = E_OK;
        }
    }

    if(errorId != FEE_30_FLEXNOR_E_NO_ERROR)
    {
        Fee_30_FlexNor_ErrorChecks_ReportDetError(FEE_30_FLEXNOR_SID_ERASEIMMEDIATEBLOCK, errorId);
    }

    Fee_30_FlexNor_IsApiActive = FALSE;
    return jobAcceptance;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_GetStatus()
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
FUNC(MemIf_StatusType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_GetStatus(void)
{
    Fee_30_FlexNor_StatusType schedulerStatus = Fee_30_FlexNor_Scheduler_GetStatus();
    MemIf_StatusType currentStatus = MEMIF_UNINIT;

    if(Fee_30_FlexNor_IsInitialized == FALSE)
    {
        currentStatus = MEMIF_UNINIT;
    }
    else if(schedulerStatus == FEE_30_FLEXNOR_BUSY)
    {
        currentStatus = MEMIF_BUSY;
    }
    else if((schedulerStatus == FEE_30_FLEXNOR_CANCELLING) && (Fee_30_FlexNor_JobStored == TRUE))
    {
        currentStatus = MEMIF_BUSY;
    }
    else
    {
        currentStatus = MEMIF_IDLE;
    }

    return currentStatus;
}
volatile Fee_30_FlexNor_ErrorCode get_errorId = 0;
/**********************************************************************************************************************
 * Fee_30_FlexNor_GetJobResult()
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
FUNC(MemIf_JobResultType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_GetJobResult(void)
{
    Fee_30_FlexNor_ErrorCode errorId = FEE_30_FLEXNOR_E_NO_ERROR;
    MemIf_JobResultType currentJobResult = MEMIF_JOB_FAILED;

    MemIf_StatusType status = Fee_30_FlexNor_GetStatus();

    if(Fee_30_FlexNor_ErrorChecks_IsDetConditionTrue(status == MEMIF_UNINIT) == TRUE)
    {
        errorId = FEE_30_FLEXNOR_E_UNINIT;
        currentJobResult = MEMIF_JOB_FAILED;
        get_errorId = errorId;
    }
    else
    {
        if(status == MEMIF_BUSY)
        {
            currentJobResult = MEMIF_JOB_PENDING;
        }
        else
        {
            currentJobResult = Fee_30_FlexNor_Job.JobResult;
        }
    }

    if(errorId != FEE_30_FLEXNOR_E_NO_ERROR)
    {
        Fee_30_FlexNor_ErrorChecks_ReportDetError(FEE_30_FLEXNOR_SID_GET_JOB_RESULT, errorId);
    }

    return currentJobResult;
}

/***********************************************************************************************************************
 *  Fee_30_FlexNor_MainFunction()
 **********************************************************************************************************************/
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
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_MainFunction(void)
{
    if(Fee_30_FlexNor_IsApiActive == TRUE)
    {
        Fee_30_FlexNor_ErrorChecks_ReportDetError(FEE_30_FLEXNOR_SID_MAIN_FUNCTION, FEE_30_FLEXNOR_E_REENTRANCY_VIOLATED);
    }
    else
    {
        Fee_30_FlexNor_IsApiActive = TRUE;
        if ((Fee_30_FlexNor_Scheduler_GetStatus() != FEE_30_FLEXNOR_IDLE) && (Fee_30_FlexNor_IsInitialized == TRUE))
        {
            Fee_30_FlexNor_Scheduler_Schedule();

            if(Fee_30_FlexNor_Scheduler_GetStatus() == FEE_30_FLEXNOR_IDLE)
            {
                Fee_30_FlexNor_SetupFollowUpJob();
            }

            Fee_30_FlexNor_NotifyNvMIfNecessary();
        }
    }

    Fee_30_FlexNor_IsApiActive = FALSE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_PersistLookupTable()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_PersistLookupTable(Fee_30_FlexNor_PartitionIdType partitionId)
{
    FEE_DUMMY_STATEMENT(partitionId);
    return E_OK;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SuspendRecoveryJobs()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SuspendRecoveryJobs(void)
{
    if(Fee_30_FlexNor_ErrorChecks_IsDetConditionTrue(Fee_30_FlexNor_GetStatus() == MEMIF_UNINIT) == TRUE)
    {
        Fee_30_FlexNor_ErrorChecks_ReportDetError(FEE_30_FLEXNOR_SID_SUSPEND_RECOVERY_JOBS, FEE_30_FLEXNOR_E_UNINIT);
    }
    else
    {
        Fee_30_FlexNor_InternalJobs_SuspendRecoveryJobs(TRUE);
    }
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_ResumeRecoveryJobs()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_ResumeRecoveryJobs(void)
{
    if(Fee_30_FlexNor_ErrorChecks_IsDetConditionTrue(Fee_30_FlexNor_GetStatus() == MEMIF_UNINIT) == TRUE)
    {
        Fee_30_FlexNor_ErrorChecks_ReportDetError(FEE_30_FLEXNOR_SID_RESUME_RECOVERY_JOBS, FEE_30_FLEXNOR_E_UNINIT);
    }
    else
    {
        Fee_30_FlexNor_InternalJobs_SuspendRecoveryJobs(FALSE);
    }
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SuspendFlashWrites()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SuspendFlashWrites(void)
{
    if(Fee_30_FlexNor_ErrorChecks_IsDetConditionTrue(Fee_30_FlexNor_GetStatus() == MEMIF_UNINIT) == TRUE)
    {
        Fee_30_FlexNor_ErrorChecks_ReportDetError(FEE_30_FLEXNOR_SID_SUSPEND_FLASH_WRITES, FEE_30_FLEXNOR_E_UNINIT);
    }
    else
    {
        Fee_30_FlexNor_FlashAccess_SuspendWrites(TRUE);
    }
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_ResumeFlashWrites()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_ResumeFlashWrites(void)
{
    if(Fee_30_FlexNor_ErrorChecks_IsDetConditionTrue(Fee_30_FlexNor_GetStatus() == MEMIF_UNINIT) == TRUE)
    {
        Fee_30_FlexNor_ErrorChecks_ReportDetError(FEE_30_FLEXNOR_SID_RESUME_FLASH_WRITES, FEE_30_FLEXNOR_E_UNINIT);
    }
    else
    {
        Fee_30_FlexNor_FlashAccess_SuspendWrites(FALSE);
    }
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_GetEraseCycleCounter()
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
 */
FUNC(Std_ReturnType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_GetEraseCycleCounter(
    Fee_30_FlexNor_PartitionIdType partitionId,
    Fee_30_FlexNor_EraseCycleCounterType* eraseCycleCounter)
{
    Std_ReturnType jobAcceptance = E_NOT_OK;
    Fee_30_FlexNor_ErrorCode errorId = FEE_30_FLEXNOR_E_NO_ERROR;

    if (Fee_30_FlexNor_ErrorChecks_IsDetConditionTrue(Fee_30_FlexNor_GetStatus() == MEMIF_UNINIT) == TRUE)
    {
        errorId = FEE_30_FLEXNOR_E_UNINIT;
    }
    else if(Fee_30_FlexNor_ErrorChecks_IsDetConditionTrue(partitionId >= FEE_30_FLEXNOR_CONFIGURED_PARTITIONS) == TRUE)
    {
        errorId = FEE_30_FLEXNOR_E_INVALID_PARTITION_ID;
    }
    else if(Fee_30_FlexNor_ErrorChecks_IsDetConditionTrue(eraseCycleCounter == NULL_PTR) == TRUE)
    {
        errorId = FEE_30_FLEXNOR_E_PARAM_POINTER;
    }
    else if (Fee_30_FlexNor_Partition_IsStartedUp(partitionId) == FALSE)
    {
        errorId = FEE_30_FLEXNOR_E_PARTITION_NOT_STARTED_UP;
    }
    else
    {
        *eraseCycleCounter = Fee_30_FlexNor_SectorContainer_GetEraseCycleCounter(partitionId); /* SBSW_Fee_30_FlexNor_ModifyGivenObject */
        jobAcceptance = E_OK;
    }

    if(errorId != FEE_30_FLEXNOR_E_NO_ERROR)
    {
        Fee_30_FlexNor_ErrorChecks_ReportDetError(FEE_30_FLEXNOR_SID_GET_ERASE_CYCLE_COUNTER, errorId);
    }

    return jobAcceptance;
}

#if (FEE_30_FLEXNOR_VERSION_INFO_API == STD_ON)
/**********************************************************************************************************************
 *  Fee_30_FlexNor_GetVersionInfo()
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
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_GetVersionInfo(Fee_30_FlexNor_VersionInfoPtrType versioninfo)
{
    Fee_30_FlexNor_ErrorCode errorId = FEE_30_FLEXNOR_E_NO_ERROR;

    if(Fee_30_FlexNor_ErrorChecks_IsDetConditionTrue(versioninfo == NULL_PTR) == TRUE)
    {
        errorId = FEE_30_FLEXNOR_E_PARAM_POINTER;
    }
    else
    {
        versioninfo->vendorID = FEE_30_FLEXNOR_VENDOR_ID; /* SBSW_Fee_30_FlexNor_ParamPointerWriteAccess */
        versioninfo->moduleID = FEE_30_FLEXNOR_MODULE_ID; /* SBSW_Fee_30_FlexNor_ParamPointerWriteAccess */
        versioninfo->sw_major_version = FEE_30_FLEXNOR_SW_MAJOR_VERSION; /* SBSW_Fee_30_FlexNor_ParamPointerWriteAccess */
        versioninfo->sw_minor_version = FEE_30_FLEXNOR_SW_MINOR_VERSION; /* SBSW_Fee_30_FlexNor_ParamPointerWriteAccess */
        versioninfo->sw_patch_version = FEE_30_FLEXNOR_SW_PATCH_VERSION; /* SBSW_Fee_30_FlexNor_ParamPointerWriteAccess */
    }

    if(errorId != FEE_30_FLEXNOR_E_NO_ERROR)
    {
        Fee_30_FlexNor_ErrorChecks_ReportDetError(FEE_30_FLEXNOR_SID_GET_VERSION_INFO, errorId);
    }
}
#endif

/**********************************************************************************************************************
 * Fee_30_FlexNor_GetCurrentJobBaseInformation()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Fee_30_FlexNor_CurrentJobInformationType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_GetCurrentJobBaseInformation(void)
{
    Fee_30_FlexNor_JobType currentActiveJob = Fee_30_FlexNor_Job;

    Fee_30_FlexNor_CurrentJobInformationType publicBaseInformation;
    publicBaseInformation.blockId = currentActiveJob.BlockId;
    publicBaseInformation.partitionId = currentActiveJob.PartitionId;
    publicBaseInformation.serviceId = currentActiveJob.Service;

    return publicBaseInformation;
}

#define FEE_30_FLEXNOR_STOP_SEC_CODE
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  MISRA JUSTIFICATIONS
 **********************************************************************************************************************/
/* Justification for module-specific MISRA deviations:
  MD_Fee_30_FlexNor_StateFileScopeStatic: rule 8.9
  Reason:     The variable must be declared file scope static because the memory needs to be allocated permanently
              and not temporarily on the stack.
  Risk:       No risk.
  Prevention: No prevention.

  MD_Fee_30_FlexNor_CouldBeConstPointer: rule 8.13
  Reason:     The context is not modified in this function but can't be made const since the function signature must match
              the function pointer used for state machine state definition.
  Risk:       Missing const can lead to unwanted modification.
  Prevention: No prevention.

  MD_Fee_30_FlexNor_GreaterPointerLifetime: rule 18.6
  Reason:     A pointer to the pending source sector is assigned from a local variable to the context.
  Risk:       No risk because the pointer points to a sector in the sector container which is valid the whole time.
  Prevention: No prevention.

  MD_Fee_30_FlexNor_IntegerSuffixedWithLOrLL: rule 10.3
  Reason:     The data types which have a range of an unit32 are generated with suifx L, even if this would not be necessary.
  Risk:       No risk.
  Prevention: No prevention.
*/

/***********************************************************************************************************************
 *  SILENTBSW JUSTIFICATIONS
 **********************************************************************************************************************/
/* SBSW_JUSTIFICATION_BEGIN

    \ID SBSW_Fee_30_FlexNor_TriggerEventAtState
    \DESCRIPTION    An event is triggered at the state machine that shall be processed by the current state.
    \COUNTERMEASURE \N No countermeasure is required because the function pointer is only set to valid processing functions
                    by the implementation as long as the unit was initialized.

    \ID SBSW_Fee_30_FlexNor_FunctionCallWithContext
    \DESCRIPTION    A function is called with the state machine context pointer as parameter. Each unit manages the context
                    itself so either the local context is referenced directly or the context pointer is retrieved as a
                    function parameter that is passed down further.
    \COUNTERMEASURE \N No countermeasure is required because each function call with the context pointer can be traced back
                    to the point where the self managed context object is referenced and pushed down the callstack.

    \ID SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer
    \DESCRIPTION    A function is called using a pointer stored in the state machine context.
    \COUNTERMEASURE \N No countermeasure is required because the correct context setup is ensured in the service function and
                    verified by review and testing. The correctness of the pointer and length must be ensure by the caller
                    of the service.

    \ID SBSW_Fee_30_FlexNor_FunctionCallWithJobPointer
    \DESCRIPTION    A function is called using a pointer to an object that was created locally.
    \COUNTERMEASURE \N No countermeasure is required because the correct job setup is ensured in the service function and is
                    verified by review and testing.

    \ID SBSW_Fee_30_FlexNor_FunctionCallWithGivenPointer
    \DESCRIPTION    Calls a function with a pointer that was retrieved as a function parameter.
    \COUNTERMEASURE \N No countermeasure is required because the caller of the function is responsible for providing a valid pointer.

    \ID SBSW_Fee_30_FlexNor_FunctionCallWithGivenFunctionPointer
    \DESCRIPTION    Calls a function with a pointer to a function.
    \COUNTERMEASURE \N No countermeasure is required because the compiler checks that the function really exists. Otherwise, it would not compile.

    \ID SBSW_Fee_30_FlexNor_FunctionPointerCallWithGivenPointer
    \DESCRIPTION    Calls a function using a function pointer that is stored in a structure whose pointer was retrieved as a function parameter.
    \COUNTERMEASURE \N No countermeasure is required because the caller of the function is responsible for providing a valid pointer.

    \ID SBSW_Fee_30_FlexNor_FunctionPointerCallFromCreatedObject
    \DESCRIPTION    Calls a function using a function pointer that is stored in an object that was created locally.
    \COUNTERMEASURE \N No countermeasure is required because the factory ensures that the function pointers are correctly set.

    \ID SBSW_Fee_30_FlexNor_FunctionCallWithPointerToLocal
    \DESCRIPTION    Calls a function with a pointer to a variable defined in the scope of the function.
    \COUNTERMEASURE \N No countermeasure is required because the memory of the variable is correctly allocated in the scope.

    \ID SBSW_Fee_30_FlexNor_LoopStoredSectors
    \DESCRIPTION    A function is called with a pointer to a sector object managed by the sector container unit.
    \COUNTERMEASURE \N No countermeasure is required because the pointer is retrieved by the sector container itself.
                    It ensures the correctness of the pointer internally.

    \ID SBSW_Fee_30_FlexNor_ContextFunctionPointerCall
    \DESCRIPTION    A function pointer is called that is stored in the state machine context.
    \COUNTERMEASURE \N No countermeasure is required because the function pointer is always correctly initialized when setting
                    up the job.

    \ID SBSW_Fee_30_FlexNor_ContextPointerAccess
    \DESCRIPTION    Modifies the content of state machine context given by the calling function.
    \COUNTERMEASURE \N No countermeasure is required because each function call with the context pointer can be traced back
                    to the point where the self managed context object is referenced and pushed down the callstack.

    \ID SBSW_Fee_30_FlexNor_ModifyGivenObject
    \DESCRIPTION    Modifies the content of objects using a given pointer to that object.
    \COUNTERMEASURE \N No countermeasure is required because the caller of the function must make sure that the pointer points to
                    a valid object.

    \ID SBSW_Fee_30_FlexNor_ResultHandler
    \DESCRIPTION    A function is called with a pointer to a local result handler callback function.
    \COUNTERMEASURE \N No countermeasure is required because a pointer to a local function is used that is called by the called service.

    \ID SBSW_Fee_30_FlexNor_RegisterUnit
    \DESCRIPTION    The unit registers itself at the scheduler for processing time. The function is calles with a pointer
                    to the internal unit processing function.
    \COUNTERMEASURE \N No countermeasure is required because the correctness is enforced by the compiler.

    \ID SBSW_Fee_30_FlexNor_ModifyContextArray
    \DESCRIPTION    Modifies an array stored in the state machine context. Both the pointer to the array as well as
                    the length is set when the context is initialized in the implementation of the units service function.
    \COUNTERMEASURE \N No countermeasure is required because the correct context setup is ensured in the service function and
                    verified by review and testing. The correctness of the pointer and length must be ensure by the caller
                    of the service.

    \ID SBSW_Fee_30_FlexNor_ModifySchedulerProcessingStack
    \DESCRIPTION    Modifies the function pointer at the procesing function stack of the scheduler by either initializing it
                    with a default handler or pushing a given processing function on the stack.
    \COUNTERMEASURE \N No countermeasure is required because the maximum amount of processing handler that can be pushed
                    on the stack is limited by the amount of units in the component. It is ensured by design that no unit
                    registers itself twice at the scheduler therefore the required stack size can be determined during
                    development time.

    \ID SBSW_Fee_30_FlexNor_CallProcessingHandler
    \DESCRIPTION    Calls a processing handler function from the schedulers stack.
    \COUNTERMEASURE \N No countermeasure is required because there is either a correctly registered process event handler of a
                    unit or the default handler on the stack.

    \ID SBSW_Fee_30_FlexNor_ModifyGivenArray
    \DESCRIPTION    Modifies an array that was passed to the function as parameter.
    \COUNTERMEASURE \N No countermeasure is required because the caller of the function is responsible for providing a valid
                    pointer.

    \ID SBSW_Fee_30_FlexNor_Factory
    \DESCRIPTION    Creating objects (i.e. a structure including data and function pointers) to abstract from the current layout.
                    This will be done once for every object at a specified "creation time" and the object is ready for use afterwards.
                    The user has to hand a valid pointer to the corresponding structure when the object shall be created. This pointer
                    will not be stored internally and just used during the creation itself. The user has only to care that the pointer
                    is valid when the create function is called.
    \COUNTERMEASURE \N The user has to assure that the given pointer points to a valid instance structure.

    \ID SBSW_Fee_30_FlexNor_SectorInit
    \DESCRIPTION    A sector object is initialized using a given pointer to the sector object. The pointer to the sector object
                    was retrieved using the configured amount of partitions and sectors for each partition.
    \COUNTERMEASURE \N The pointer is guaranteed to be valid because the function is only called internally to initialize
                    the locally stored sector objects.

    \ID SBSW_Fee_30_FlexNor_LookupTablePersistData
    \DESCRIPTION    The lookup table data object is written accessing the array directly with the partition id as
                    index or via a pointer which was obtained from the array with the partition id as index.
    \COUNTERMEASURE \N The access to the array is valid, because its size is the number of partitions and the partition
                       id, which is used as index, is always smaller.

    \ID SBSW_Fee_30_FlexNor_LookupTableValidity
    \DESCRIPTION    The lookup table validity flag is written accessing the array directly with the partition id as
                    index or via a pointer which was obtained from the array with the partition id as index.
    \COUNTERMEASURE \N The access to the array is valid, because its size is the number of partitions and the partition
                       id, which is used as index, is always smaller.

    \ID SBSW_Fee_30_FlexNor_SectorContainer_GetSector
    \DESCRIPTION    The sector container module works as a kind of object holder and returns references to the concrete objects.
    \COUNTERMEASURE \N The sector container stores the sectors as concrete objects. It promises to return only valid references to these
                    concrete objects.

    \ID SBSW_Fee_30_FlexNor_PartitionFlags
    \DESCRIPTION    The partition flags are initialized using a given pointer to the local partition flags array. The pointer to the partition flags array
                    was retrieved using the configured amount of partitions, i.e. there is enough memory allocated because the allocation and access are
                    both bound to the same value.
    \COUNTERMEASURE \N The pointer is guaranteed to be valid because the function is only called internally to initialize
                    the locally stored partition flags.

    \ID SBSW_Fee_30_FlexNor_LookupTableModifications
    \DESCRIPTION    The lookup table is updated with new values.
    \COUNTERMEASURE \R The access location is calculated based on a given block id. Before accessing the array it is checked that
                    the block id fits the lookup table.

    \ID SBSW_Fee_30_FlexNor_ChunkReallocationModifications
    \DESCRIPTION    The chunk reallocation flags are updated with new values.
    \COUNTERMEASURE \R The access location is calculated based on a given block id. Before accessing the array it is checked that
                    the block id fits.

    \ID SBSW_Fee_30_FlexNor_ConfigPointer
    \DESCRIPTION    The config pointer given as parameter to the components init function is used to set the configuration in the
                    config interface.
    \COUNTERMEASURE \N The user has to assure that the init function is called with a valid config pointer.

    \ID SBSW_Fee_30_FlexNor_ParamPointerFunctionCall
    \DESCRIPTION    A given pointer is used to call internal functions.
    \COUNTERMEASURE \N The user has to assure that the component service is called with a valid pointer.

    \ID SBSW_Fee_30_FlexNor_ParamPointerWriteAccess
    \DESCRIPTION    Write access to a pointer given as parameter in a component service call.
    \COUNTERMEASURE \N The user has to assure that the component service is called with a valid pointer.

    \ID SBSW_Fee_30_FlexNor_ParamPointerJobResultWriteAccess
    \DESCRIPTION    A pointer to the job structure is used to update its job result.
    \COUNTERMEASURE \N No countermeasure is required because the function pointer is always correctly initialized when setting
                    up the job.

    \ID SBSW_Fee_30_FlexNor_LookupTableVersion
    \DESCRIPTION    Writes the version in the first (LookupTable[0]) entry of the LUT.
    \COUNTERMEASURE \M There are two MSSV checks in place that verify that the configured sized actually match the size of the
                       accessed arrays.The LUT size is at lest two because the entry LookupTable[1] is necessary for the
                       LUT block.

    \ID SBSW_Fee_30_FlexNor_JobDispatching
    \DESCRIPTION    A requested job is dispatched by a single function that handels the cancellation special cases.
                    The job is copied by value, therefore this shouldn't be a dangerous function call.
    \COUNTERMEASURE \N No pointer is transferred here, therefore there is nothing to do.

    \ID SBSW_Fee_30_FlexNor_ForwardJobToCheckIfPersistLutIsAllowed
    \DESCRIPTION    Forwared the previous job to the check if a persist LUT job is allowed.
                    The job is copied by value, therefore this shouldn't be a dangerous function call.
    \COUNTERMEASURE \N No pointer is transferred here, therefore there is nothing to do.

    \ID SBSW_Fee_30_FlexNor_FunctionCallWithConstPointer
    \DESCRIPTION    A function is called with a const pointer.
    \COUNTERMEASURE \N The function cannot write to the pointer, otherwise it would not compile. Writing to const is forbidden.

    \ID SBSW_Fee_30_FlexNor_FunctionCallForwardsResultCallback
    \DESCRIPTION    A function is called with a pointer to the result callback, which is provided as an argument.
    \COUNTERMEASURE \N All callers of the outer function call it with a valid result callback.

SBSW_JUSTIFICATION_END */

/***********************************************************************************************************************
 *  COVERAGE JUSTIFICATIONS
 **********************************************************************************************************************/
/* START_COVERAGE_JUSTIFICATION

Variant coverage:

\ID COV_FEE_30_FLEXNOR_COMPATIBILITY
 \ACCEPT TX
 \REASON COV_MSR_COMPATIBILITY

\ID COV_FEE_30_FLEXNOR_MULTIPLE_OPTIONAL_UNITS
 \ACCEPT TX tx tx
 \REASON Code is enabled depending on the existence of multiple optional units. For unit testing,
         these units are always present in the unit test configurations. Variants with only one unit enabled
         are tested on component level.
 \LEVEL Unit

END_COVERAGE_JUSTIFICATION */


/**********************************************************************************************************************
 *  END OF FILE: Fee_30_FlexNor.c
 *********************************************************************************************************************/
