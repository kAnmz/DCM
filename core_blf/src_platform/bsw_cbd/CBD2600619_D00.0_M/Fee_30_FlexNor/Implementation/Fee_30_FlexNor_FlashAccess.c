/**********************************************************************************************************************
 *  COPYRIGHT
 *  --------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2025 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  --------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/*!        \file  Fee_30_FlexNor_FlashAccess.c
 *        \brief  Flash access business logic implementation
 *      \details  Provides the implementation of the business logic for the flash access.
 *         \unit  FlashAccess
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#define FEE_30_FLEXNOR_FLASHACCESS_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Fee_30_FlexNor_FlashAccess.h"
#include "Fee_30_FlexNor_FlashAccessMachine.h"
#include "Fee_30_FlexNor_FlashAccessInternal.h"

#include "Fee_30_FlexNor_ConfigInterface.h"
#include "Fee_30_FlexNor_MemoryInterface.h"
#include "Fee_30_FlexNor_Scheduler.h"
#include "Fee_30_FlexNor_Cbk.h"

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

/*! Context variable of the flash access state machine. */
FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_FlashAccess_ContextType Fee_30_FlexNor_FlashAccessStmContext = { 0u };

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
 * Fee_30_FlexNor_FlashAccess_ProcessingHandler()
 *********************************************************************************************************************/
/*! \brief       Handles the processing event
 *  \details     Triggers the Process event at the local state machine.
 *  \return      FEE_30_FLEXNOR_STOP_SCHEDULE       In case the scheduling shall be stopped
 *               FEE_30_FLEXNOR_CONTINUE_SCHEDULE   In case the scheduling can be continued
 *  \pre         The flash access unit needs to be initialized.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FEE_30_FLEXNOR_LOCAL FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) 
    Fee_30_FlexNor_FlashAccess_ProcessingHandler(void);

/**********************************************************************************************************************
 * Fee_30_FlexNor_FlashAccess_GetMappedFlashJobResult()
 *********************************************************************************************************************/
/*! \brief       Gets the result of the latest flash job from the lower layer and maps it to the FEE result type
 *  \details     -
 *  \return      FEE_30_FLEXNOR_OK          The job was completed successfully
                 FEE_30_FLEXNOR_FAIL        The job failed
                 FEE_30_FLEXNOR_PENDING     The job is still pending
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FEE_30_FLEXNOR_LOCAL FUNC(Fee_30_FlexNor_FlashAccess_FlashResultType, FEE_30_FLEXNOR_CODE) 
    Fee_30_FlexNor_FlashAccess_GetMappedFlashJobResult(boolean isReadJob);

#if(FEE_30_FLEXNOR_CFG_POLLING_MODE == STD_ON)
/**********************************************************************************************************************
 * Fee_30_FlexNor_FlashAccess_GetMappedMemoryStatus()
 *********************************************************************************************************************/
/*! \brief       Get the status of the lower layer and map it to the FEE status type.
 *  \details     -
 *  \return      FEE_30_FLEXNOR_OK          The job was completed successfully
                 FEE_30_FLEXNOR_FAIL        The job failed
                 FEE_30_FLEXNOR_PENDING     The job is still pending
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FEE_30_FLEXNOR_LOCAL FUNC(Fee_30_FlexNor_StatusType, FEE_30_FLEXNOR_CODE) 
    Fee_30_FlexNor_FlashAccess_GetMappedMemoryStatus(void);
#endif /* FEE_30_FLEXNOR_CFG_POLLING_MODE == STD_ON */

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * Fee_30_FlexNor_FlashAccess_ProcessingHandler()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FEE_30_FLEXNOR_LOCAL FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) 
    Fee_30_FlexNor_FlashAccess_ProcessingHandler(void)
{
    return Fee_30_FlexNor_FlashAccessStmContext.CurrentState->ProcessEvent(&Fee_30_FlexNor_FlashAccessStmContext); /* SBSW_Fee_30_FlexNor_TriggerEventAtState */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_FlashAccess_GetMappedFlashJobResult()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FEE_30_FLEXNOR_LOCAL FUNC(Fee_30_FlexNor_FlashAccess_FlashResultType, FEE_30_FLEXNOR_CODE) 
    Fee_30_FlexNor_FlashAccess_GetMappedFlashJobResult(boolean isReadJob)
{    
    Fee_30_FlexNor_FlashAccess_FlashResultType jobProgress = FEE_30_FLEXNOR_FLASH_FAIL;

#if (FEE_30_FLEXNOR_MEMORY_VARIANT == FEE_30_FLEXNOR_MEMORY_VARIANT_FLS)

    MemIf_JobResultType flsJobResult = FEE_30_FLEXNOR_MEMORY_GETJOBRESULT();

    switch(flsJobResult)
    {
        case MEMIF_JOB_OK:
            jobProgress = FEE_30_FLEXNOR_FLASH_OK;
            break;
        case MEMIF_JOB_PENDING:
            jobProgress = FEE_30_FLEXNOR_FLASH_PENDING;
            break;
        case MEMIF_JOB_FAILED:
            if(isReadJob == TRUE)
            {
                /* Fls drivers cannot distinguish read fails which are caused by ECC errors or other reasons. So 
                   consider every read fail as ECC error. */
                jobProgress = FEE_30_FLEXNOR_FLASH_ECCERROR;
            }
            else 
            {
                jobProgress = FEE_30_FLEXNOR_FLASH_FAIL;
            }
            break;    
        default: /* MEMIF_JOB_CANCELED, MEMIF_BLOCK_INCONSISTENT, MEMIF_BLOCK_INVALID */
            jobProgress = FEE_30_FLEXNOR_FLASH_FAIL;
            break;
    }

#else /* FEE_30_FLEXNOR_MEMORY_VARIANT == FEE_30_FLEXNOR_MEMORY_VARIANT_MEMACC */

    MemAcc_JobResultType memAccJobResult = FEE_30_FLEXNOR_MEMORY_GETJOBRESULT();

    switch(memAccJobResult)
    {
    case MEMACC_OK:
    case MEMACC_ECC_CORRECTED: 
        jobProgress = FEE_30_FLEXNOR_FLASH_OK;
        break;
    case MEMACC_ECC_UNCORRECTED:
        jobProgress = FEE_30_FLEXNOR_FLASH_ECCERROR;
        break;
    default: /* MEMACC_INCONSISTENT, MEMACC_CANCELED, MEMACC_FAILED */
        jobProgress = FEE_30_FLEXNOR_FLASH_FAIL;
        break;
    }

    FEE_DUMMY_STATEMENT(isReadJob);

#endif 

    return jobProgress;
}

#if(FEE_30_FLEXNOR_CFG_POLLING_MODE == STD_ON)
/**********************************************************************************************************************
 * Fee_30_FlexNor_FlashAccess_GetMappedMemoryStatus()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FEE_30_FLEXNOR_LOCAL FUNC(Fee_30_FlexNor_StatusType, FEE_30_FLEXNOR_CODE) 
    Fee_30_FlexNor_FlashAccess_GetMappedMemoryStatus(void)
{
    Fee_30_FlexNor_StatusType memStatus = FEE_30_FLEXNOR_BUSY;

# if (FEE_30_FLEXNOR_MEMORY_VARIANT == FEE_30_FLEXNOR_MEMORY_VARIANT_FLS)

    MemIf_StatusType flsStatus = FEE_30_FLEXNOR_MEMORY_GETSTATUS();

    switch (flsStatus)
    {
        case MEMIF_IDLE:
            memStatus = FEE_30_FLEXNOR_IDLE;
            break;
        default: /* MEMIF_UNINIT, MEMIF_BUSY, MEMIF_BUSY_INTERNAL */
            memStatus = FEE_30_FLEXNOR_BUSY;
            break;
    }

# else /* FEE_30_FLEXNOR_MEMORY_VARIANT == FEE_30_FLEXNOR_MEMORY_VARIANT_MEMACC */

    MemAcc_JobStatusType memAccStatus = FEE_30_FLEXNOR_MEMORY_GETSTATUS();

    switch(memAccStatus)
    {
        case MEMACC_JOB_IDLE:
            memStatus = FEE_30_FLEXNOR_IDLE;
            break;
        default: /* MEMACC_JOB_PENDING */
            memStatus = FEE_30_FLEXNOR_BUSY;
            break;
    }

# endif 

    return memStatus;
}
#endif /* FEE_30_FLEXNOR_CFG_POLLING_MODE == STD_ON */

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * Fee_30_FlexNor_FlashAccess_Init()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_FlashAccess_Init(void)
{
    Fee_30_FlexNor_FlashAccessStmContext.FlashJobStatus = FEE_30_FLEXNOR_IDLE;
    Fee_30_FlexNor_FlashAccess_InitState(&Fee_30_FlexNor_FlashAccessStmContext); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_FlashAccess_ReadFlash()
 *********************************************************************************************************************/
 /*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_FlashAccess_ReadFlash(
    Fee_30_FlexNor_PartitionIdType partitionId,
    Fee_30_FlexNor_AddressType address, 
    Fee_30_FlexNor_DataPtrType data, 
    Fee_30_FlexNor_LengthType length,
    Fee_30_FlexNor_ResultCallback resultCbk)
{
    Fee_30_FlexNor_FlashAccessStmContext.PartitionId = partitionId;
    Fee_30_FlexNor_FlashAccessStmContext.JobAddress = address;
    Fee_30_FlexNor_FlashAccessStmContext.JobData = data;
    Fee_30_FlexNor_FlashAccessStmContext.JobLength = length;
    Fee_30_FlexNor_FlashAccessStmContext.ResultCallback = resultCbk;
    Fee_30_FlexNor_FlashAccessStmContext.RequestedJob = FEE_30_FLEXNOR_FLASHACCESS_READ;
    Fee_30_FlexNor_FlashAccessStmContext.ReadJobResult = FEE_30_FLEXNOR_FLASH_PENDING;

    Fee_30_FlexNor_FlashAccess_InitializeJob(&Fee_30_FlexNor_FlashAccessStmContext); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_FlashAccess_ReadFlashImmediate()
 *********************************************************************************************************************/
 /*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_FlashAccess_ReadFlashImmediate(
    Fee_30_FlexNor_PartitionIdType partitionId,
    Fee_30_FlexNor_AddressType address, 
    Fee_30_FlexNor_DataPtrType data, 
    Fee_30_FlexNor_LengthType length,
    Fee_30_FlexNor_ResultCallback resultCbk)
{
    Fee_30_FlexNor_FlashAccessStmContext.PartitionId = partitionId;
    Fee_30_FlexNor_FlashAccessStmContext.JobAddress = address;
    Fee_30_FlexNor_FlashAccessStmContext.JobData = data;
    Fee_30_FlexNor_FlashAccessStmContext.JobLength = length;
    Fee_30_FlexNor_FlashAccessStmContext.ResultCallback = resultCbk;
    Fee_30_FlexNor_FlashAccessStmContext.RequestedJob = FEE_30_FLEXNOR_FLASHACCESS_READIMMEDIATE;
    Fee_30_FlexNor_FlashAccessStmContext.ReadJobResult = FEE_30_FLEXNOR_FLASH_PENDING;

    Fee_30_FlexNor_FlashAccess_InitializeJob(&Fee_30_FlexNor_FlashAccessStmContext); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_FlashAccess_WriteFlash()
 *********************************************************************************************************************/
 /*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_FlashAccess_WriteFlash(
    Fee_30_FlexNor_PartitionIdType partitionId,
    Fee_30_FlexNor_AddressType address, 
    Fee_30_FlexNor_ConstDataPtrType data, 
    Fee_30_FlexNor_LengthType length,
    Fee_30_FlexNor_ResultCallback resultCbk)
{
    Fee_30_FlexNor_FlashAccessStmContext.PartitionId = partitionId;
    Fee_30_FlexNor_FlashAccessStmContext.JobAddress = address;
    Fee_30_FlexNor_FlashAccessStmContext.JobConstData = data;
    Fee_30_FlexNor_FlashAccessStmContext.JobLength = length;
    Fee_30_FlexNor_FlashAccessStmContext.ResultCallback = resultCbk;
    Fee_30_FlexNor_FlashAccessStmContext.RequestedJob = FEE_30_FLEXNOR_FLASHACCESS_WRITE;
    Fee_30_FlexNor_FlashAccessStmContext.ReadJobResult = FEE_30_FLEXNOR_FLASH_FAIL;

    Fee_30_FlexNor_FlashAccess_InitializeJob(&Fee_30_FlexNor_FlashAccessStmContext); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_FlashAccess_EraseFlash()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_FlashAccess_EraseFlash(
    Fee_30_FlexNor_PartitionIdType partitionId,
    Fee_30_FlexNor_AddressType address, 
    Fee_30_FlexNor_LengthType length,
    Fee_30_FlexNor_ResultCallback resultCbk)
{
    Fee_30_FlexNor_FlashAccessStmContext.PartitionId = partitionId;
    Fee_30_FlexNor_FlashAccessStmContext.JobAddress = address;
    Fee_30_FlexNor_FlashAccessStmContext.JobLength = length;
    Fee_30_FlexNor_FlashAccessStmContext.ResultCallback = resultCbk;
    Fee_30_FlexNor_FlashAccessStmContext.RequestedJob = FEE_30_FLEXNOR_FLASHACCESS_ERASE;
    Fee_30_FlexNor_FlashAccessStmContext.ReadJobResult = FEE_30_FLEXNOR_FLASH_FAIL;

    Fee_30_FlexNor_FlashAccess_InitializeJob(&Fee_30_FlexNor_FlashAccessStmContext); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_FlashAccess_Cancel()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_FlashAccess_Cancel(void)
{
    Fee_30_FlexNor_FlashAccess_FlashResultType result = Fee_30_FlexNor_FlashAccess_CheckJobResult(
        &Fee_30_FlexNor_FlashAccessStmContext, FALSE); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */

    if(result == FEE_30_FLEXNOR_FLASH_PENDING)
    {
        FEE_30_FLEXNOR_MEMORY_CANCEL();
    }
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_FlashAccess_SuspendWrites()
 *********************************************************************************************************************/
 /*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_FlashAccess_SuspendWrites(boolean suspendWritesEnabled)
{
    Fee_30_FlexNor_FlashAccessStmContext.SuspendWritesEnabled = suspendWritesEnabled;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_FlashAccess_StartJob()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_FlashAccess_StartJob(void)
{
    Fee_30_FlexNor_Scheduler_RegisterUnit(&Fee_30_FlexNor_FlashAccess_ProcessingHandler); /* SBSW_Fee_30_FlexNor_RegisterUnit */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_FlashAccess_EndJob()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_FlashAccess_EndJob(void)
{
    Fee_30_FlexNor_Scheduler_UnregisterUnit();
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_FlashAccess_IsFlashBlank()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_BlankCheckResultType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_FlashAccess_IsFlashBlank(void)
{
    Fee_30_FlexNor_BlankCheckResultType blankCheckResult = FEE_30_FLEXNOR_BLANKCHECK_FAILED;

#if (FEE_30_FLEXNOR_MEMORY_VARIANT == FEE_30_FLEXNOR_MEMORY_VARIANT_FLS)

    MemIf_JobResultType flsJobResult = FEE_30_FLEXNOR_MEMORY_GETJOBRESULT();

    switch (flsJobResult)
    {
        case MEMIF_JOB_OK:
            blankCheckResult = FEE_30_FLEXNOR_ISBLANK;
            break;
        case MEMIF_BLOCK_INCONSISTENT:
            blankCheckResult = FEE_30_FLEXNOR_ISNOTBLANK;
            break;
        default: /* MEMIF_JOB_FAILED, MEMIF_JOB_PENDING, MEMIF_JOB_CANCELED, MEMIF_BLOCK_INVALID */
            blankCheckResult = FEE_30_FLEXNOR_BLANKCHECK_FAILED;
            break;
    }

#else /* FEE_30_FLEXNOR_MEMORY_VARIANT == FEE_30_FLEXNOR_MEMORY_VARIANT_MEMACC */

    MemAcc_JobResultType memAccJobResult = FEE_30_FLEXNOR_MEMORY_GETJOBRESULT();

    switch(memAccJobResult)
    {
        case MEMACC_OK:
            blankCheckResult = FEE_30_FLEXNOR_ISBLANK;
            break;
        case MEMACC_INCONSISTENT:
            blankCheckResult = FEE_30_FLEXNOR_ISNOTBLANK;
            break;
        default: /* MEMACC_ECC_CORRECTED, MEMACC_ECC_UNCORRECTED, MEMACC_CANCELED, MEMACC_FAILED */
            blankCheckResult = FEE_30_FLEXNOR_BLANKCHECK_FAILED;
            break;
    }

#endif

    return blankCheckResult;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_FlashAccess_CheckJobResult()
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
FUNC(Fee_30_FlexNor_FlashAccess_FlashResultType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_FlashAccess_CheckJobResult(
    Fee_30_FlexNor_FlashAccess_ContextPtrType ctx, boolean isReadJob) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    Fee_30_FlexNor_FlashAccess_FlashResultType jobResult = FEE_30_FLEXNOR_FLASH_PENDING;

#if(FEE_30_FLEXNOR_CFG_POLLING_MODE == STD_ON)
    if(Fee_30_FlexNor_FlashAccess_GetMappedMemoryStatus() == FEE_30_FLEXNOR_IDLE)
    {
        jobResult = Fee_30_FlexNor_FlashAccess_GetMappedFlashJobResult(isReadJob);
    }

    FEE_DUMMY_STATEMENT(ctx);
#else
    if(ctx->FlashJobStatus == FEE_30_FLEXNOR_IDLE)
    {
        jobResult = Fee_30_FlexNor_FlashAccess_GetMappedFlashJobResult(isReadJob);
    } 
#endif

    return jobResult;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_FlashAccess_SetBufferToErasedValue()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_FlashAccess_SetBufferToErasedValue(
    Fee_30_FlexNor_FlashAccess_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    Fee_30_FlexNor_ConstPartitionConfigPtrType partitionConfig = Fee_30_FlexNor_ConfigInterface_GetPartitionConfig(
        ctx->PartitionId);

    for(Fee_30_FlexNor_LengthType index = 0; index < ctx->JobLength; index++)
    {
        ctx->JobData[index] = partitionConfig->ErasedValue; /* SBSW_Fee_30_FlexNor_ModifyContextArray */
    }
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_FlashAccess_SetupReadJob()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_FlashAccess_SetupReadJob(
    Fee_30_FlexNor_FlashAccess_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    Std_ReturnType retVal = FEE_30_FLEXNOR_MEMORY_READ( /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
        (FEE_30_FLEXNOR_MEMORY_ADDRESS_TYPE)ctx->JobAddress, 
        ctx->JobData, 
        (FEE_30_FLEXNOR_MEMORY_LENGTH_TYPE)ctx->JobLength); 

    return retVal;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_FlashAccess_SetupBlankCheck()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_FlashAccess_SetupBlankCheck(
    Fee_30_FlexNor_FlashAccess_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    Std_ReturnType retVal = E_NOT_OK;
#if(FEE_30_FLEXNOR_CFG_BLANKCHECK_ENABLED == STD_ON)
    retVal = FEE_30_FLEXNOR_MEMORY_BLANKCHECK(
        (FEE_30_FLEXNOR_MEMORY_ADDRESS_TYPE)ctx->JobAddress, 
        (FEE_30_FLEXNOR_MEMORY_LENGTH_TYPE)ctx->JobLength);
#else
    /*
     * If the blank check feature is disabled for all partitions, the default return value for setting up a blank check 
     * is E_NOT_OK. During runtime the function is never called if no partition requires a blank check due to a runtime 
     * check in the state machine. The intention behind this solution is to reduce the preprocessor variance by using 
     * only preprocessor switches where it is necessary.
     */
    FEE_DUMMY_STATEMENT(ctx);
    retVal = E_NOT_OK;
#endif

    return retVal;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_FlashAccess_SetupWriteJob()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_FlashAccess_SetupWriteJob(
    Fee_30_FlexNor_FlashAccess_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    Std_ReturnType retVal = FEE_30_FLEXNOR_MEMORY_WRITE( /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
        (FEE_30_FLEXNOR_MEMORY_ADDRESS_TYPE)ctx->JobAddress, 
        ctx->JobConstData, 
        (FEE_30_FLEXNOR_MEMORY_LENGTH_TYPE)ctx->JobLength);

    return retVal;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_FlashAccess_SetupEraseJob()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_FlashAccess_SetupEraseJob(
    Fee_30_FlexNor_FlashAccess_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    Std_ReturnType retVal = FEE_30_FLEXNOR_MEMORY_ERASE(
        (FEE_30_FLEXNOR_MEMORY_ADDRESS_TYPE)ctx->JobAddress,
        (FEE_30_FLEXNOR_MEMORY_LENGTH_TYPE)ctx->JobLength);

    return retVal;
}

/**********************************************************************************************************************
 * Fee_JobErrorNotification
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_JobErrorNotification(void)
{
    Fee_30_FlexNor_FlashAccessStmContext.FlashJobStatus = FEE_30_FLEXNOR_IDLE;
}

/**********************************************************************************************************************
 * Fee_JobEndNotification
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_JobEndNotification(void)
{
    Fee_30_FlexNor_FlashAccessStmContext.FlashJobStatus = FEE_30_FLEXNOR_IDLE;
}

#if (FEE_30_FLEXNOR_MEMORY_VARIANT == FEE_30_FLEXNOR_MEMORY_VARIANT_MEMACC)
/**********************************************************************************************************************
 * Fee_30_FlexNor_AddressAreaJobEndNotification
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_AddressAreaJobEndNotification (
    MemAcc_AddressAreaIdType addressAreaId,
    MemAcc_JobResultType jobResult
)
{
    /* AddressArea is not used because Fee uses only one AddressArea, 
       so it is already known which one finished the job.
     */
    FEE_DUMMY_STATEMENT(addressAreaId);

    if ((jobResult == MEMACC_FAILED) 
        || (jobResult == MEMACC_CANCELED) 
        || (jobResult == MEMACC_ECC_UNCORRECTED) 
        || (jobResult == MEMACC_INCONSISTENT))
    {
        Fee_30_FlexNor_JobErrorNotification();
    }
    else
    {
        Fee_30_FlexNor_JobEndNotification();
    }
}
#endif /* FEE_30_FLEXNOR_MEMORY_VARIANT == FEE_30_FLEXNOR_MEMORY_VARIANT_MEMACC */

/**********************************************************************************************************************
 * Fee_30_FlexNor_FlashAccess_GetReadJobResult()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Fee_30_FlexNor_FlashAccess_FlashResultType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_FlashAccess_GetReadJobResult(void)
{
    return Fee_30_FlexNor_FlashAccessStmContext.ReadJobResult;
}

#define FEE_30_FLEXNOR_STOP_SEC_CODE
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: Fee_30_FlexNor_FlashAccess.c
 *********************************************************************************************************************/
