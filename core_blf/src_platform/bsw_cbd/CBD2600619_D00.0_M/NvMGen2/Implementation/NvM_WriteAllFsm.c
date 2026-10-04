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
/*!        \file  NvM_WriteAllFsm.c
 *        \brief  NvM_WriteAllFsm source file
 *      \details  Implementation of write all state machine
 *         \unit  NvM_WriteAllFsm
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#define NVM_WRITEALLFSM_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "NvM_WriteAllFsm.h"
#include "NvM_CfgDefines.h"
#include "NvM_FsmLib.h"
#include "NvM_SingleBlockJobFsm.h"
#include "NvM_GlobalUtilityLib.h"
#include "MemIf.h"

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

/* Write Block Error Flag bit mask */
#define NVM_WRITE_BLOCK_ERROR_FLAG_TRUE      1u
#define NVM_WRITE_BLOCK_ERROR_FLAG_FALSE     0u

/*
 * Identifier for end of blocks of WriteAll iteration:
 * If config block is available: Last actual block to be processed is one after config block
 * Otherwise: Last block is first internal block id (= 0u)
 */
#if (NVM_DYNAMIC_CONFIGURATION == STD_ON)
#define NVM_FIRST_RELEVANT_BLOCK_ID          (NVM_CONFIG_BLOCK_ID + 1u)
#else
#define NVM_FIRST_RELEVANT_BLOCK_ID          NVM_FIRST_INTERNAL_BLOCK_ID
#endif /* NVM_DYNAMIC_CONFIGURATION */

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

/***********************************************************************************************************************
 *  FSM FUNCTION PROTOTYPES
 **********************************************************************************************************************/
#define NVM_START_SEC_CODE
#include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * NvM_WriteAllFsm_Entry()
 *********************************************************************************************************************/
/*!  \brief       ENTRY action of WriteAllFsm
 *   \details     -
 *   \param[in]   partitionId Partition ID.
 *   \pre         -
 *   \context     TASK
 *   \reentrant   FALSE
 *   \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, NVM_PRIVATE_CODE) NvM_WriteAllFsm_Entry(NvM_PartitionIdType partitionId);

/**********************************************************************************************************************
 * NvM_WriteAllFsm_FindNextRelevantBlockState_Do()
 *********************************************************************************************************************/
/*!  \brief       DO action of WriteAllFsm state FindNextRelevantBlock
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
FUNC(NvM_FsmLib_ProcessingResultType, NVM_PRIVATE_CODE) NvM_WriteAllFsm_FindNextRelevantBlockState_Do(
  NvM_PartitionIdType partitionId);

/**********************************************************************************************************************
 * NvM_WriteAllFsm_WriteCurrentBlockState_Entry()
 *********************************************************************************************************************/
/*!  \brief       ENTRY action of WriteAllFsm state WriteCurrentBlock
 *   \details     -
 *   \param[in]   partitionId Partition ID.
 *   \pre         -
 *   \context     TASK
 *   \reentrant   FALSE
 *   \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, NVM_PRIVATE_CODE) NvM_WriteAllFsm_WriteCurrentBlockState_Entry(NvM_PartitionIdType partitionId);

/**********************************************************************************************************************
 * NvM_WriteAllFsm_WriteCurrentBlockState_Do()
 *********************************************************************************************************************/
/*!  \brief       DO action of WriteAllFsm state WriteCurrentBlock
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
FUNC(NvM_FsmLib_ProcessingResultType, NVM_PRIVATE_CODE) NvM_WriteAllFsm_WriteCurrentBlockState_Do(
  NvM_PartitionIdType partitionId);

#if (NVM_DYNAMIC_CONFIGURATION == STD_ON)
/**********************************************************************************************************************
 * NvM_WriteAllFsm_ProcessConfigBlockState_Entry()
 *********************************************************************************************************************/
/*!  \brief       ENTRY action of WriteAllFsm state ProcessConfigBlock
 *   \details     -
 *   \param[in]   partitionId Partition ID.
 *   \pre         -
 *   \context     TASK
 *   \reentrant   FALSE
 *   \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, NVM_PRIVATE_CODE) NvM_WriteAllFsm_ProcessConfigBlockState_Entry(NvM_PartitionIdType partitionId);

/**********************************************************************************************************************
 * NvM_WriteAllFsm_ProcessConfigBlockState_Do()
 *********************************************************************************************************************/
/*!  \brief       DO action of WriteAllFsm state ProcessConfigBlock
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
FUNC(NvM_FsmLib_ProcessingResultType, NVM_PRIVATE_CODE) NvM_WriteAllFsm_ProcessConfigBlockState_Do(
  NvM_PartitionIdType partitionId);
#endif /* NVM_DYNAMIC_CONFIGURATION */

/**********************************************************************************************************************
 * NvM_WriteAllFsm_CancelWriteAllState_Do()
 *********************************************************************************************************************/
/*!  \brief       DO action of WriteAllFsm state CancelWriteAll
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
FUNC(NvM_FsmLib_ProcessingResultType, NVM_PRIVATE_CODE) NvM_WriteAllFsm_CancelWriteAllState_Do(
  NvM_PartitionIdType partitionId);

#if (NVM_JOB_PRIORITIZATION == STD_ON)

/**********************************************************************************************************************
 * NvM_WriteAllFsm_WaitForWriteAllReadyToResumeState_Do()
 *********************************************************************************************************************/
/*!  \brief       DO action of WriteAllFsm state WaitForWriteAllReadyToResume
 *   \details     This state is only entered if an immediate job has interrupted the WriteAll job
 *                and hence the WriteAllFsm was notified about this interruption.
 *                This state automatically acts as waiting state until the immediate block job
 *                was processed, because the ServiceProcessor FSM does no longer process the multi block job stack
 *                till the immediate job is finished. After the finalization of the immediate block job,
 *                the WriteAll FSM is resumed by the ServiceProcessor FSM by continuing to process the multi
 *                block job stack again.
 *   \param[in]   partitionId Partition ID.
 *   \return      CONTINUE to resume WriteAll processing
 *   \pre         -
 *   \context     TASK
 *   \reentrant   FALSE
 *   \synchronous TRUE
 *********************************************************************************************************************/
FUNC(NvM_FsmLib_ProcessingResultType, NVM_PRIVATE_CODE) NvM_WriteAllFsm_WaitForWriteAllReadyToResumeState_Do(
  NvM_PartitionIdType partitionId);
#endif /* NVM_JOB_PRIORITIZATION == STD_ON */

/**********************************************************************************************************************
 * NvM_WriteAllFsm_CheckFinalizationDelayState_Do()
 *********************************************************************************************************************/
/*!  \brief       DO action of WriteAllFsm state CheckFinalizationDelay
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
FUNC(NvM_FsmLib_ProcessingResultType, NVM_PRIVATE_CODE) NvM_WriteAllFsm_CheckFinalizationDelayState_Do(
  NvM_PartitionIdType partitionId);

#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/
#define NVM_START_SEC_CONST_UNSPECIFIED
#include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*
 * Initializing a const structure (NvM_WriteAllFsm_InitialState) can only be done with compile-time constants.
 * Therefore this defines are introduced to minimize code duplication within NvM_WriteAllFsm_InitialState and
 * NvM_WriteAllFsm_FindNextRelevantBlockState initialization.
 */
#define NVM_WRITEALLFSM_FINDNEXTRELEVANTBLOCKSTATE_ENTRY NvM_FsmLib_EntryNoOp
#define NVM_WRITEALLFSM_FINDNEXTRELEVANTBLOCKSTATE_DO NvM_WriteAllFsm_FindNextRelevantBlockState_Do

/*! STATE: FindNextRelevantBlock */
NVM_LOCAL CONST(NvM_StateType, NVM_PRIVATE_DATA) NvM_WriteAllFsm_FindNextRelevantBlockState = {
  NVM_WRITEALLFSM_FINDNEXTRELEVANTBLOCKSTATE_ENTRY, /* no ENTRY action required */
  NVM_WRITEALLFSM_FINDNEXTRELEVANTBLOCKSTATE_DO
};

/*! STATE: WriteCurrentBlock */
/* PRQA S 3218 1 */ /* MD_Fsm_StateDefinitionStaticUsedOnlyInSingleFunction */
NVM_LOCAL CONST(NvM_StateType, NVM_PRIVATE_DATA) NvM_WriteAllFsm_WriteCurrentBlockState = {
  NvM_WriteAllFsm_WriteCurrentBlockState_Entry,
  NvM_WriteAllFsm_WriteCurrentBlockState_Do
};

#if (NVM_DYNAMIC_CONFIGURATION == STD_ON)
/*! STATE: ProcessConfigBlock */
/* PRQA S 3218 1 */ /* MD_Fsm_StateDefinitionStaticUsedOnlyInSingleFunction */
NVM_LOCAL CONST(NvM_StateType, NVM_PRIVATE_DATA) NvM_WriteAllFsm_ProcessConfigBlockState = {
  NvM_WriteAllFsm_ProcessConfigBlockState_Entry,
  NvM_WriteAllFsm_ProcessConfigBlockState_Do
};
#endif /* NVM_DYNAMIC_CONFIGURATION */

/*! STATE: CancelWriteAll */
/* PRQA S 3218 1 */ /* MD_Fsm_StateDefinitionStaticUsedOnlyInSingleFunction */
NVM_LOCAL CONST(NvM_StateType, NVM_PRIVATE_DATA) NvM_WriteAllFsm_CancelWriteAllState = {
  NvM_FsmLib_EntryNoOp, /* no ENTRY action required */
  NvM_WriteAllFsm_CancelWriteAllState_Do
};

#if (NVM_JOB_PRIORITIZATION == STD_ON)
/*! STATE: WaitForWriteAllReadyToResume */
/* PRQA S 3218 1 */ /* MD_Fsm_StateDefinitionStaticUsedOnlyInSingleFunction */
NVM_LOCAL CONST(NvM_StateType, NVM_PRIVATE_DATA) NvM_WriteAllFsm_WaitForWriteAllReadyToResumeState = {
  NvM_FsmLib_EntryNoOp, /* no ENTRY action required */
  NvM_WriteAllFsm_WaitForWriteAllReadyToResumeState_Do
};
#endif /* NVM_JOB_PRIORITIZATION == STD_ON */

/*! STATE: CheckFinalizationDelay */
/* PRQA S 3218 1 */ /* MD_Fsm_StateDefinitionStaticUsedOnlyInSingleFunction */
NVM_LOCAL CONST(NvM_StateType, NVM_PRIVATE_DATA) NvM_WriteAllFsm_CheckFinalizationDelayState = {
  NvM_FsmLib_EntryNoOp, /* no ENTRY action required */
  NvM_WriteAllFsm_CheckFinalizationDelayState_Do
};

/*! FSM: WriteAll with ENTRY action and initial state */
/* PRQA S 3218 1 */ /* MD_Fsm_StateDefinitionStaticUsedOnlyInSingleFunction */
NVM_LOCAL CONST(NvM_FsmType, NVM_PRIVATE_DATA) NvM_WriteAllFsm_InitialState = {
  NvM_WriteAllFsm_Entry,
  {NVM_WRITEALLFSM_FINDNEXTRELEVANTBLOCKSTATE_ENTRY, NVM_WRITEALLFSM_FINDNEXTRELEVANTBLOCKSTATE_DO}
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

/**********************************************************************************************************************
 *  NvM_WriteAllFsm_IsWriteBlockRestricted()
 *********************************************************************************************************************/
/*! \brief       Check if current block is either write protected or locked.
 *  \details     -
 *  \param[in]   blockDescriptor Current Block to be checked.
 *  \return      TRUE, if block is write protected or locked, otherwise FALSE.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(boolean, NVM_PRIVATE_CODE) NvM_WriteAllFsm_IsWriteBlockRestricted(NvM_BlockDescriptorPtrType blockDescriptor);

/**********************************************************************************************************************
 *  NvM_WriteAllFsm_CheckRamBlockStatus()
 *********************************************************************************************************************/
/*! \brief       Check if RamBlockStatus is VALID/CHANGED if enabled.
 *  \details     -
 *  \param[in]   blockDescriptor Current Block to be checked.
 *  \return      TRUE, if VALID/CHANGED and enabled, otherwise FALSE.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(boolean, NVM_PRIVATE_CODE) NvM_WriteAllFsm_CheckRamBlockStatus(NvM_BlockDescriptorPtrType blockDescriptor);

/**********************************************************************************************************************
 *  NvM_WriteAllFsm_IsBlockRelevant()
 *********************************************************************************************************************/
/*! \brief       Check if current block is relevant for write all.
 *  \details     -
 *  \param[in]   blockDescriptor Current Block to be checked.
 *  \return      TRUE, if block is relevant, otherwise FALSE.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(boolean, NVM_PRIVATE_CODE) NvM_WriteAllFsm_IsBlockRelevant(NvM_BlockDescriptorPtrType blockDescriptor);

/**********************************************************************************************************************
 *  NvM_WriteAllFsm_CheckCurrentBlockWriteJobStatus()
 *********************************************************************************************************************/
/*! \brief       Checks the write job status of the current block and sets any job iteration flag accordingly.
 *  \details     -
 *  \param[in]   blockDescriptorLookupTableId      Current Block Descriptor Lookup Table ID to be checked.
 *  \param[in]   fsmContext                        Current FSM context.
 *  \param[in]   fsmLibInstance                    Current FSM library instance.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, NVM_PRIVATE_CODE) NvM_WriteAllFsm_CheckCurrentBlockWriteJobStatus(
  const NvM_BlockDescriptorLookupTableIdType blockDescriptorLookupTableId,
  NvM_WriteAllFsm_ContextPtrType fsmContext,
  NvM_FsmLib_InstancePtrToConstType fsmLibInstance
);

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  NvM_WriteAllFsm_IsWriteBlockRestricted
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
FUNC(boolean, NVM_PRIVATE_CODE) NvM_WriteAllFsm_IsWriteBlockRestricted(NvM_BlockDescriptorPtrType blockDescriptor)
{
  boolean returnValue = FALSE;

  if (blockDescriptor->BlockManagementInfo->WriteProtection == TRUE)
  {
    returnValue = TRUE;
  }
  else
  {
    if (blockDescriptor->BlockManagementInfo->BlockLocked == TRUE)
    {
      returnValue = TRUE;
    }
  }

  return returnValue;
}

/**********************************************************************************************************************
 *  NvM_WriteAllFsm_CheckRamBlockStatus
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
FUNC(boolean, NVM_PRIVATE_CODE) NvM_WriteAllFsm_CheckRamBlockStatus(NvM_BlockDescriptorPtrType blockDescriptor)
{
  boolean returnValue = FALSE;

  if (blockDescriptor->Flags.BlockUseSetRamBlockStatusEnabled == NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON)
  {
    if (blockDescriptor->BlockManagementInfo->RamBlockState == NVM_RAMBLOCKSTATE_VALID_CHANGED)
    {
      returnValue = TRUE;
    }
    else
    {
      returnValue = FALSE;
    }
  }
  else
  {
    returnValue = TRUE;
  }

  return returnValue;
}

/**********************************************************************************************************************
 *  NvM_WriteAllFsm_IsBlockRelevant
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
FUNC(boolean, NVM_PRIVATE_CODE) NvM_WriteAllFsm_IsBlockRelevant(NvM_BlockDescriptorPtrType blockDescriptor)
{
  boolean returnValue = FALSE;

  if (blockDescriptor->Flags.SelectBlockForWriteAllEnabled == NVM_SELECT_BLOCK_FOR_WRITEALL_ON)
  {
    if (NvM_WriteAllFsm_IsWriteBlockRestricted(blockDescriptor) == TRUE)
    {
      returnValue = FALSE;
    }
    else
    {
      returnValue = NvM_WriteAllFsm_CheckRamBlockStatus(blockDescriptor);
    }
  }
  else
  {
    returnValue = FALSE;
  }

  return returnValue;
}

/**********************************************************************************************************************
 *  NvM_WriteAllFsm_CheckCurrentBlockWriteJobStatus
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, NVM_PRIVATE_CODE) NvM_WriteAllFsm_CheckCurrentBlockWriteJobStatus(
  const NvM_BlockDescriptorLookupTableIdType blockDescriptorLookupTableId,
  NvM_WriteAllFsm_ContextPtrType fsmContext,
  NvM_FsmLib_InstancePtrToConstType fsmLibInstance)
{
  NvM_BlockDescriptorPtrType blockDescriptor = NvM_GetAddrBlockDescriptor(blockDescriptorLookupTableId);

  /* Poll result */
  NvM_ServiceJobResultType serviceJobResult = NvM_FsmLib_GetSubFsmResult(fsmLibInstance);

  blockDescriptor->BlockManagementInfo->ErrorStatus =
    NvM_GlobalUtilityLib_ConvertServiceJobResultToNvMRequestResult(serviceJobResult);

  if(blockDescriptor->BlockManagementInfo->ErrorStatus != NVM_REQ_OK)
  {
    fsmContext->HasAnyJobIterationFailed = TRUE;
  }
}

/**********************************************************************************************************************
 * NvM_WriteAllFsm_Entry()
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
/* VCA Next Line SPC-24 : VCA_NVM_WriteAllFsm_CurrentBlockDescriptorLookupTableId */
FUNC(void, NVM_PRIVATE_CODE) NvM_WriteAllFsm_Entry(NvM_PartitionIdType partitionId)                                     /* PRQA S 3206 */ /* MD_NvM_CslMacroNotUsingPartitionId */
{
  NvM_FsmLib_InstancePtrToConstType multiBlockJobFsmLibInstance =
    (NvM_FsmLib_InstancePtrToConstType)NvM_GetAddrMultiBlockServiceFsmLib_Instance(partitionId);
  NvM_WriteAllFsm_ContextPtrType fsmContext = NvM_GetAddrWriteAllFsm_Context(partitionId);
  const NvM_BlockDescriptorLookupTableIdType blockCount = NvM_GetSizeOfBlockDescriptor();

  /* Initial set block ID to block count because the last block is the first block to handled
   * and initial value is decremented in the FindNextRelevantBlock state.
   */
  fsmContext->CurrentBlockDescriptorLookupTableId = (uint16)blockCount;

  for (NvM_BlockDescriptorLookupTableIdType i = NVM_FIRST_INTERNAL_BLOCK_ID; i < blockCount; i++)
  {
    NvM_BlockDescriptorPtrType blockDescriptor = NvM_GetAddrBlockDescriptor(i);

    if(blockDescriptor->Flags.SelectBlockForWriteAllEnabled == NVM_SELECT_BLOCK_FOR_WRITEALL_ON)
    {
#if (NVM_MULTIPARTITION_USAGE_SCENARIO == STD_ON)
      if (blockDescriptor->PartitionId == partitionId)
#endif
      {
        blockDescriptor->BlockManagementInfo->ErrorStatus = NVM_REQ_PENDING;
      }
    }
  }

  NvM_FsmLib_TransitionToState(multiBlockJobFsmLibInstance, NvM_WriteAllFsm_FindNextRelevantBlockState);

  /*
   * The parameter partitionId is not used within this function in single partition use case.
   * To avoid compiler warnings the following dummy statement is added.
   */
  NVM_DUMMY_STATEMENT(partitionId);                                                                                     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
}

/*!
 * STATE: FindNextRelevantBlock
 */

/**********************************************************************************************************************
 * NvM_WriteAllFsm_FindNextRelevantBlockState_Do()
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
/* VCA Next Line SPC-24 : VCA_NVM_WriteAllFsm_CurrentBlockDescriptorLookupTableId */
FUNC(NvM_FsmLib_ProcessingResultType, NVM_PRIVATE_CODE) NvM_WriteAllFsm_FindNextRelevantBlockState_Do(
  NvM_PartitionIdType partitionId)                                                                                      /* PRQA S 3206 */ /* MD_NvM_CslMacroNotUsingPartitionId */
{
  NvM_FsmLib_ProcessingResultType retVal = NVM_FSMLIB_PROCESSINGRESULT_CONTINUE;

  NvM_FsmLib_InstancePtrToConstType multiBlockJobFsmLibInstance =
    (NvM_FsmLib_InstancePtrToConstType)NvM_GetAddrMultiBlockServiceFsmLib_Instance(partitionId);
  NvM_WriteAllFsm_ContextPtrType fsmContext = NvM_GetAddrWriteAllFsm_Context(partitionId);

  /* MUST read from master partition, only available there*/
  NvM_MultiBlockJobInformationType multiBlockJobInfo = NvM_GetMultiBlockJobInformation(NVM_PARTITION_ID_MASTER);

  if (NvM_GlobalUtilityLib_IsFlagSet(multiBlockJobInfo.JobStatusFlag, NVM_MULTIBLOCK_FLAG_WRITEALL_CANCEL_REQUESTED))
  {
    /* CurrentBlockDescriptorLookupTableId is decremented to set first not processed block to CANCELED */
    fsmContext->CurrentBlockDescriptorLookupTableId--;
    NvM_FsmLib_TransitionToState(multiBlockJobFsmLibInstance, NvM_WriteAllFsm_CancelWriteAllState);
  }
  else
  {
    /*  Global variable must be copied to stack for correct VCA analysis, see TAR-70879 */
    NvM_BlockDescriptorLookupTableIdType currentBlockDescriptorLookupTableId =
     fsmContext->CurrentBlockDescriptorLookupTableId;

    if(currentBlockDescriptorLookupTableId <= NVM_FIRST_RELEVANT_BLOCK_ID)
    {
#if (NVM_DYNAMIC_CONFIGURATION == STD_ON)

      /* Decrement block ID to point to the config block.
        This is important to successfully resume the WriteAll with the correct block in case
        of an immediate interruption. */
      fsmContext->CurrentBlockDescriptorLookupTableId--;

      NvM_FsmLib_TransitionToState(multiBlockJobFsmLibInstance, NvM_WriteAllFsm_ProcessConfigBlockState);
#else
      NvM_FsmLib_TransitionToState(multiBlockJobFsmLibInstance, NvM_WriteAllFsm_CheckFinalizationDelayState);
#endif /* NVM_DYNAMIC_CONFIGURATION */
    }
    else
    {
      fsmContext->CurrentBlockDescriptorLookupTableId = currentBlockDescriptorLookupTableId - 1u;

      NvM_BlockDescriptorPtrType blockDescriptor =
       NvM_GetAddrBlockDescriptor(fsmContext->CurrentBlockDescriptorLookupTableId);

  #if (NVM_MULTIPARTITION_USAGE_SCENARIO == STD_ON)
      if (blockDescriptor->PartitionId == partitionId)
  #endif
      {
        if (NvM_WriteAllFsm_IsBlockRelevant(blockDescriptor))
        {
          NvM_FsmLib_TransitionToState(multiBlockJobFsmLibInstance, NvM_WriteAllFsm_WriteCurrentBlockState);
        }
        else
        {
          blockDescriptor->BlockManagementInfo->ErrorStatus = NVM_REQ_BLOCK_SKIPPED;
        }
      }
    }
  }

  /*
   * The parameter partitionId is not used within this function in single partition use case.
   * To avoid compiler warnings the following dummy statement is added.
   */
  NVM_DUMMY_STATEMENT(partitionId);                                                                                     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  return retVal;
}


/*!
 * STATE: WriteCurrentBlock
 */

/**********************************************************************************************************************
 * NvM_WriteAllFsm_WriteCurrentBlockState_Entry()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, NVM_PRIVATE_CODE) NvM_WriteAllFsm_WriteCurrentBlockState_Entry(NvM_PartitionIdType partitionId)
{
  NvM_WriteAllFsm_ContextPtrToConstType fsmContext = NvM_GetAddrWriteAllFsm_Context(partitionId);
  NvM_SingleBlockJobContextPtrType singleBlockJobContext = NvM_GetAddrSingleBlockJobContext(partitionId);
  NvM_BlockDescriptorPtrType blockDescriptor =
   NvM_GetAddrBlockDescriptor(fsmContext->CurrentBlockDescriptorLookupTableId);

  /* Setup block ID for sub FSM */
  singleBlockJobContext->BlockDescriptorLookupTableId = fsmContext->CurrentBlockDescriptorLookupTableId;
  singleBlockJobContext->BlockId = blockDescriptor->NvramBlockIdentifier;

  /* Spawn SingleBlockJobFsm */
  NvM_SingleBlockJobFsm_Spawn(partitionId);
}

/**********************************************************************************************************************
 * NvM_WriteAllFsm_WriteCurrentBlockState_Do()
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
FUNC(NvM_FsmLib_ProcessingResultType, NVM_PRIVATE_CODE) NvM_WriteAllFsm_WriteCurrentBlockState_Do(
  NvM_PartitionIdType partitionId)                                                                                      /* PRQA S 3206 */ /* MD_NvM_CslMacroNotUsingPartitionId */
{
  NvM_FsmLib_ProcessingResultType retVal = NVM_FSMLIB_PROCESSINGRESULT_STOP;

  NvM_FsmLib_InstancePtrToConstType multiBlockJobFsmLibInstance =
    (NvM_FsmLib_InstancePtrToConstType)NvM_GetAddrMultiBlockServiceFsmLib_Instance(partitionId);
  NvM_FsmLib_InstancePtrToConstType singleBlockJobFsmLibInstance =
    (NvM_FsmLib_InstancePtrToConstType)NvM_GetAddrSingleBlockServiceFsmLib_Instance(partitionId);
  NvM_WriteAllFsm_ContextPtrType fsmContext = NvM_GetAddrWriteAllFsm_Context(partitionId);

  NvM_FsmLib_ProcessCurrentActiveFsm(singleBlockJobFsmLibInstance);

  /* In case the processing stack of the single block job stack is empty,
    the single block job was successfully finished and hence
    it can be continued with the next individual block job. */
  if (NvM_FsmLib_IsProcessingStackEmpty(singleBlockJobFsmLibInstance) == TRUE)
  {
    NvM_WriteAllFsm_CheckCurrentBlockWriteJobStatus(fsmContext->CurrentBlockDescriptorLookupTableId,
      fsmContext, singleBlockJobFsmLibInstance);
    NvM_FsmLib_TransitionToState(multiBlockJobFsmLibInstance, NvM_WriteAllFsm_FindNextRelevantBlockState);

    retVal = NVM_FSMLIB_PROCESSINGRESULT_CONTINUE;
  }

  /*
   * The parameter partitionId is not used within this function in single partition use case.
   * To avoid compiler warnings the following dummy statement is added.
   */
  NVM_DUMMY_STATEMENT(partitionId);                                                                                     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  return retVal;
}

#if (NVM_DYNAMIC_CONFIGURATION == STD_ON)

/*!
 * STATE: ProcessConfigBlock
 */

/**********************************************************************************************************************
 * NvM_WriteAllFsm_ProcessConfigBlockState_Entry()
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
FUNC(void, NVM_PRIVATE_CODE) NvM_WriteAllFsm_ProcessConfigBlockState_Entry(NvM_PartitionIdType partitionId)
{
  NvM_FsmLib_InstancePtrToConstType multiBlockJobFsmLibInstance =
    (NvM_FsmLib_InstancePtrToConstType)NvM_GetAddrMultiBlockServiceFsmLib_Instance(partitionId);
  NvM_BlockDescriptorPtrType blockDescriptor = NvM_GetAddrBlockDescriptor(NVM_CONFIG_BLOCK_ID);

#if (NVM_MULTIPARTITION_USAGE_SCENARIO == STD_ON)
  if (blockDescriptor->PartitionId != partitionId)
  {
    NvM_FsmLib_TransitionToState(multiBlockJobFsmLibInstance, NvM_WriteAllFsm_CheckFinalizationDelayState);
  }
  else
#endif /* NVM_MULTIPARTITION_USAGE_SCENARIO */
  {
    if (blockDescriptor->BlockManagementInfo->RamBlockState == NVM_RAMBLOCKSTATE_VALID_CHANGED)
    {
      NvM_SingleBlockJobContextPtrType singleBlockJobContext = NvM_GetAddrSingleBlockJobContext(partitionId);

      /* Setup block ID for sub FSM */
      singleBlockJobContext->BlockDescriptorLookupTableId = NVM_CONFIG_BLOCK_ID;
      singleBlockJobContext->BlockId = blockDescriptor->NvramBlockIdentifier;

      /* Spawn SingleBlockJobFsm  */
      NvM_SingleBlockJobFsm_Spawn(partitionId);
    }
    else
    {
      blockDescriptor->BlockManagementInfo->ErrorStatus = NVM_REQ_BLOCK_SKIPPED;

      NvM_FsmLib_TransitionToState(multiBlockJobFsmLibInstance, NvM_WriteAllFsm_CheckFinalizationDelayState);
    }
  }

  /*
   * The parameter partitionId is not used within this function in single partition use case.
   * To avoid compiler warnings the following dummy statement is added.
   */
  NVM_DUMMY_STATEMENT(partitionId);                                                                                     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
}

/**********************************************************************************************************************
 * NvM_WriteAllFsm_ProcessConfigBlockState_Do()
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
FUNC(NvM_FsmLib_ProcessingResultType, NVM_PRIVATE_CODE) NvM_WriteAllFsm_ProcessConfigBlockState_Do(
  NvM_PartitionIdType partitionId)                                                                                      /* PRQA S 3206 */ /* MD_NvM_CslMacroNotUsingPartitionId */
{
  NvM_FsmLib_ProcessingResultType retVal = NVM_FSMLIB_PROCESSINGRESULT_STOP;

  NvM_FsmLib_InstancePtrToConstType multiBlockJobFsmLibInstance =
    (NvM_FsmLib_InstancePtrToConstType)NvM_GetAddrMultiBlockServiceFsmLib_Instance(partitionId);

  NvM_FsmLib_InstancePtrToConstType singleBlockJobFsmLibInstance =
    (NvM_FsmLib_InstancePtrToConstType)NvM_GetAddrSingleBlockServiceFsmLib_Instance(partitionId);

  NvM_WriteAllFsm_ContextPtrType fsmContext = NvM_GetAddrWriteAllFsm_Context(partitionId);

  NvM_FsmLib_ProcessCurrentActiveFsm(singleBlockJobFsmLibInstance);

  /* In case the processing stack of the single block job stack is empty,
    the single block job was successfully finished and hence
    it can be continued with the finalization delay. */
  if (NvM_FsmLib_IsProcessingStackEmpty(singleBlockJobFsmLibInstance) == TRUE)
  {
    NvM_WriteAllFsm_CheckCurrentBlockWriteJobStatus(NVM_CONFIG_BLOCK_ID, fsmContext, singleBlockJobFsmLibInstance);
    NvM_FsmLib_TransitionToState(multiBlockJobFsmLibInstance, NvM_WriteAllFsm_CheckFinalizationDelayState);

    retVal = NVM_FSMLIB_PROCESSINGRESULT_CONTINUE;
  }

  /*
   * The parameter partitionId is not used within this function in single partition use case.
   * To avoid compiler warnings the following dummy statement is added.
   */
  NVM_DUMMY_STATEMENT(partitionId);                                                                                     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  return retVal;
}
#endif /* NVM_DYNAMIC_CONFIGURATION */

/**********************************************************************************************************************
 * NvM_WriteAllFsm_CancelWriteAllState_Do()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(NvM_FsmLib_ProcessingResultType, NVM_PRIVATE_CODE) NvM_WriteAllFsm_CancelWriteAllState_Do(
  NvM_PartitionIdType partitionId)                                                                                      /* PRQA S 3206 */ /* MD_NvM_CslMacroNotUsingPartitionId */
{
  NvM_FsmLib_InstancePtrType multiBlockJobFsmLibInstance =
    (NvM_FsmLib_InstancePtrType)NvM_GetAddrMultiBlockServiceFsmLib_Instance(partitionId);
  NvM_WriteAllFsm_ContextPtrToConstType fsmContext = NvM_GetAddrWriteAllFsm_Context(partitionId);

  for (NvM_BlockDescriptorLookupTableIdType i = NVM_FIRST_INTERNAL_BLOCK_ID;
    i <= fsmContext->CurrentBlockDescriptorLookupTableId; i++)                                                          /* FETA_NVM_WriteAllFsm_CancelUnprocessedBlocks */
  {
    NvM_BlockDescriptorPtrType blockDescriptor = NvM_GetAddrBlockDescriptor(i);
    blockDescriptor->BlockManagementInfo->ErrorStatus = NVM_REQ_CANCELED;
  }

  NvM_FsmLib_FinalizeCurrentActiveFsm(multiBlockJobFsmLibInstance, NVM_SERVICE_JOB_CANCELED);

  /*
   * The parameter partitionId is not used within this function in single partition use case.
   * To avoid compiler warnings the following dummy statement is added.
   */
  NVM_DUMMY_STATEMENT(partitionId);                                                                                     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  return NVM_FSMLIB_PROCESSINGRESULT_CONTINUE;
}

#if (NVM_JOB_PRIORITIZATION == STD_ON)
/**********************************************************************************************************************
 * NvM_WriteAllFsm_WaitForWriteAllReadyToResumeState_Do()
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
/* VCA Next Line SPC-24 : VCA_NVM_WriteAllFsm_CurrentBlockDescriptorLookupTableId */
FUNC(NvM_FsmLib_ProcessingResultType, NVM_PRIVATE_CODE) NvM_WriteAllFsm_WaitForWriteAllReadyToResumeState_Do(
  NvM_PartitionIdType partitionId)
{
  NVM_DUMMY_STATEMENT(partitionId); /* Unused in single partition use case */                                           /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  NvM_FsmLib_InstancePtrToConstType multiBlockJobFsmLibInstance =
    (NvM_FsmLib_InstancePtrToConstType)NvM_GetAddrMultiBlockServiceFsmLib_Instance(partitionId);

  NvM_WriteAllFsm_ContextPtrType fsmContext = NvM_GetAddrWriteAllFsm_Context(partitionId);
  NvM_SingleBlockJobContextPtrType singleBlockJobContext = NvM_GetAddrSingleBlockJobContext(partitionId);

  /* Setup single block job context to ensure correct resuming after immediate interruption */
  singleBlockJobContext->DataBuffer = NvM_GetAddrInternalBuffer(0u, partitionId);
  singleBlockJobContext->TemporaryRamBlockAddr = NULL_PTR;
  singleBlockJobContext->SingleBlockJobType = NVM_SINGLEBLOCKJOBTYPE_WRITE_ALL_BLOCK;
  singleBlockJobContext->DataIndex = 0u; /* Default value since dataset blocks are not relevant for WriteAll */

  /* In case the finalization of the WriteAll was already ongoing before an immediate job was requested,
    a transition to the CheckFinalizationDelay state is made to get rid of an additional write for the config block. */
  if (fsmContext->IsFinalizationDelayOngoing == TRUE)
  {
    NvM_FsmLib_TransitionToState(multiBlockJobFsmLibInstance, NvM_WriteAllFsm_CheckFinalizationDelayState);
  }
  else
  {
    const NvM_BlockDescriptorLookupTableIdType blockCount = NvM_GetSizeOfBlockDescriptor();

    /* Increment current block descriptor lookup table Id for reprocessing the block which was interrupted
      due to an immediate block job. */
    if (fsmContext->CurrentBlockDescriptorLookupTableId < blockCount)
    {
      fsmContext->CurrentBlockDescriptorLookupTableId++;
    }

    NvM_FsmLib_TransitionToState(multiBlockJobFsmLibInstance, NvM_WriteAllFsm_FindNextRelevantBlockState);
  }

  return NVM_FSMLIB_PROCESSINGRESULT_CONTINUE;
}
#endif /* NVM_JOB_PRIORITIZATION == STD_ON */

/**********************************************************************************************************************
 * NvM_WriteAllFsm_CheckFinalizationDelayState_Do()
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
FUNC(NvM_FsmLib_ProcessingResultType, NVM_PRIVATE_CODE) NvM_WriteAllFsm_CheckFinalizationDelayState_Do(
  NvM_PartitionIdType partitionId)                                                                                      /* PRQA S 3206 */ /* MD_NvM_CslMacroNotUsingPartitionId */
{
  NvM_FsmLib_ProcessingResultType retVal = NVM_FSMLIB_PROCESSINGRESULT_STOP;

  NvM_FsmLib_InstancePtrType multiBlockJobFsmLibInstance =
    (NvM_FsmLib_InstancePtrType)NvM_GetAddrMultiBlockServiceFsmLib_Instance(partitionId);
  NvM_WriteAllFsm_ContextPtrType fsmContext = NvM_GetAddrWriteAllFsm_Context(partitionId);

#if (NVM_JOB_PRIORITIZATION == STD_ON)
  /* Set finalization delay ongoing flag to TRUE.
    This is important for resuming to get rid of writing some block again, which was actually written
    successfully before the immediate job interruption.
    This flag is used in order to ensure that a transition to the finalization state is performed
    after an immediate interruption in case the finalization was already in process beforehand. */
  fsmContext->IsFinalizationDelayOngoing = TRUE;
#endif /* NVM_JOB_PRIORITIZATION == STD_ON */

  /* Short term solution: direct MemIf access is normally only allowed on master partition.
     Nonetheless, for now the possible additional waiting loop per satellite execution of WriteAll()
     does not hurt for now and will be optimized later.
     See MEMSLP-10443.
  */
  MemIf_StatusType memIfStatus = MemIf_GetStatus(MEMIF_BROADCAST_ID);

  if (memIfStatus == MEMIF_BUSY_INTERNAL)
  {
    retVal = NVM_FSMLIB_PROCESSINGRESULT_STOP;
  }
  else
  {
    NvM_ServiceJobResultType serviceJobResult;

    if(fsmContext->HasAnyJobIterationFailed)
    {
      serviceJobResult = NVM_SERVICE_JOB_NOT_OK;
    }
    else
    {
      serviceJobResult = NVM_SERVICE_JOB_OK;
    }

#if (NVM_JOB_PRIORITIZATION == STD_ON)
    fsmContext->IsFinalizationDelayOngoing = FALSE;
#endif /* NVM_JOB_PRIORITIZATION == STD_ON */
    NvM_FsmLib_FinalizeCurrentActiveFsm(multiBlockJobFsmLibInstance, serviceJobResult);

    retVal = NVM_FSMLIB_PROCESSINGRESULT_CONTINUE;
  }

  /*
   * The parameter partitionId is not used within this function in single partition use case.
   * To avoid compiler warnings the following dummy statement is added.
   */
  NVM_DUMMY_STATEMENT(partitionId);                                                                                     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  return retVal;
}

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * NvM_WriteAllFsm_WriteAll()
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
FUNC(void, NVM_PRIVATE_CODE) NvM_WriteAllFsm_WriteAll(NvM_PartitionIdType partitionId)                                  /* PRQA S 3206 */ /* MD_NvM_CslMacroNotUsingPartitionId */
{
  NvM_FsmLib_InstancePtrType multiBlockJobFsmLibInstance =
    (NvM_FsmLib_InstancePtrType)NvM_GetAddrMultiBlockServiceFsmLib_Instance(partitionId);
  NvM_WriteAllFsm_ContextPtrType fsmContext = NvM_GetAddrWriteAllFsm_Context(partitionId);
  NvM_SingleBlockJobContextPtrType singleBlockJobContext = NvM_GetAddrSingleBlockJobContext(partitionId);

  /* Setup single block job context */
  singleBlockJobContext->SingleBlockJobType = NVM_SINGLEBLOCKJOBTYPE_WRITE_ALL_BLOCK;
  singleBlockJobContext->DataBuffer = NvM_GetAddrInternalBuffer(0u, partitionId);
  singleBlockJobContext->TemporaryRamBlockAddr = NULL_PTR;
  singleBlockJobContext->DataIndex = 0u; /* Default value since dataset blocks are not relevant for WriteAll */

  fsmContext->HasAnyJobIterationFailed = FALSE;
#if (NVM_JOB_PRIORITIZATION == STD_ON)
  fsmContext->IsFinalizationDelayOngoing  = FALSE;
#endif /* NVM_JOB_PRIORITIZATION == STD_ON */

  /* COM-4978: Wait for CSL feature to store init value of generated partion data */
  NvM_WriteAllFsm_InstancePtrType fsmInstance = NvM_GetAddrWriteAllFsm_Instance(partitionId);
  *fsmInstance = NvM_WriteAllFsm_InitialState;
  (void)NvM_FsmLib_SpawnFsm(multiBlockJobFsmLibInstance, *fsmInstance);

  /*
   * The parameter partitionId is not used within this function in single partition use case.
   * To avoid compiler warnings the following dummy statement is added.
   */
  NVM_DUMMY_STATEMENT(partitionId);                                                                                     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
}

/**********************************************************************************************************************
 * NvM_WriteAllFsm_GetCurrentProcessedBlockDescriptorLookupTableId()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(NvM_BlockDescriptorLookupTableIdType, NVM_PRIVATE_CODE)
  NvM_WriteAllFsm_GetCurrentProcessedBlockDescriptorLookupTableId(NvM_PartitionIdType partitionId)                      /* PRQA S 3206 */ /* MD_NvM_CslMacroNotUsingPartitionId */
{
  NvM_WriteAllFsm_ContextPtrToConstType fsmContext = NvM_GetAddrWriteAllFsm_Context(partitionId);

  /*
   * The parameter partitionId is not used within this function in single partition use case.
   * To avoid compiler warnings the following dummy statement is added.
   */
  NVM_DUMMY_STATEMENT(partitionId);                                                                                     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  return fsmContext->CurrentBlockDescriptorLookupTableId;
}

#if (NVM_JOB_PRIORITIZATION == STD_ON)
/**********************************************************************************************************************
 * NvM_WriteAllFsm_NotifyImmediateJobInterrupt()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, NVM_PRIVATE_CODE) NvM_WriteAllFsm_NotifyImmediateJobInterrupt(const NvM_PartitionIdType partitionId)
{
  NVM_DUMMY_STATEMENT_CONST(partitionId); /* Unused in single partition use case */                                           /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  NvM_FsmLib_InstancePtrType multiBlockJobFsmLibInstance =
    (NvM_FsmLib_InstancePtrType)NvM_GetAddrMultiBlockServiceFsmLib_Instance(partitionId);

  NvM_FsmLib_TransitionToState(multiBlockJobFsmLibInstance, NvM_WriteAllFsm_WaitForWriteAllReadyToResumeState);
}
#endif /* NVM_JOB_PRIORITIZATION == STD_ON */

#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  VCA JUSTIFICATIONS
 **********************************************************************************************************************/
/* VCA_JUSTIFICATION_BEGIN

\ID VCA_NVM_WriteAllFsm_CurrentBlockDescriptorLookupTableId
  \DESCRIPTION The CurrentBlockDescriptorLookupTableId is set to values out of its typical range
               (less than SizeOfBlockDescriptor) in some places of the code (Entry of FSM).
               In addition, it is decremented without any explicit boundary checks,
               but it is excluded by design that the value is outside the limits.
               This is a conscious decision in regards of an better usage of the FSM idea.

  \COUNTERMEASURE \N A code review ensures that the CurrentBlockDescriptorLookupTableId is always in range when used.

VCA_JUSTIFICATION_END */

/**********************************************************************************************************************
 *  END OF FILE: NvM_WriteAllFsm.c
 *********************************************************************************************************************/
