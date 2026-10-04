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
/*!        \file  NvM_WriteBlockFsm.c
 *        \brief  NvM_WriteBlockFsm source file
 *      \details  Implementation of write block state machine
 *         \unit  NvM_WriteBlockFsm
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#define NVM_WRITEBLOCKFSM_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "NvM_WriteBlockFsm.h"
#include "NvM_FsmLib.h"
#include "NvM_DataSync.h"
#include "NvM_NvJobFsm.h"
#include "NvM_DataIntegrityFsm.h"
#include "NvM_ErrorCheck.h"
#include "NvM_GlobalUtilityLib.h"

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
 * NvM_WriteBlockFsm_Entry()
 *********************************************************************************************************************/
/*!  \brief       ENTRY action of WriteBlockFsm
 *   \details     -
 *   \param[in]   partitionId Partition ID.
 *   \pre         -
 *   \context     TASK
 *   \reentrant   FALSE
 *   \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, NVM_PRIVATE_CODE) NvM_WriteBlockFsm_Entry(NvM_PartitionIdType partitionId);

/**********************************************************************************************************************
 * NvM_WriteBlockFsm_PrepareDataState_Do()
 *********************************************************************************************************************/
/*!  \brief       DO action of WriteBlockFsm state PrepareData
 *   \details     -
 *   \param[in]   partitionId Partition ID.
 *   \return      Always NVM_FSMLIB_PROCESSINGRESULT_CONTINUE.
 *   \pre         -
 *   \context     TASK
 *   \reentrant   FALSE
 *   \synchronous TRUE
 *********************************************************************************************************************/
FUNC(NvM_FsmLib_ProcessingResultType, NVM_PRIVATE_CODE) NvM_WriteBlockFsm_PrepareDataState_Do(
  NvM_PartitionIdType partitionId);

/**********************************************************************************************************************
 * NvM_WriteBlockFsm_GenerateDataIntegrityRecordState_Entry()
 *********************************************************************************************************************/
/*!  \brief       ENTRY action of WriteBlockFsm state GenerateDataIntegrityRecord
 *   \details     -
 *   \param[in]   partitionId Partition ID.
 *   \pre         -
 *   \context     TASK
 *   \reentrant   FALSE
 *   \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, NVM_PRIVATE_CODE) NvM_WriteBlockFsm_GenerateDataIntegrityRecordState_Entry(NvM_PartitionIdType partitionId);

/**********************************************************************************************************************
 * NvM_WriteBlockFsm_GenerateDataIntegrityRecordState_Do()
 *********************************************************************************************************************/
/*!  \brief       DO action of WriteBlockFsm state GenerateDataIntegrityRecord
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
FUNC(NvM_FsmLib_ProcessingResultType, NVM_PRIVATE_CODE) NvM_WriteBlockFsm_GenerateDataIntegrityRecordState_Do(
  NvM_PartitionIdType partitionId);

/**********************************************************************************************************************
 * NvM_WriteBlockFsm_EvaluateSkipWriteState_Do()
 *********************************************************************************************************************/
/*!  \brief       DO action of WriteBlockFsm state EvaluateSkipWriting
 *   \details     -
 *   \param[in]   partitionId Partition ID.
 *   \pre         -
 *   \context     TASK
 *   \reentrant   FALSE
 *   \synchronous TRUE
 *********************************************************************************************************************/
FUNC(NvM_FsmLib_ProcessingResultType, NVM_PRIVATE_CODE) NvM_WriteBlockFsm_EvaluateSkipWriteState_Do(
  NvM_PartitionIdType partitionId);

/**********************************************************************************************************************
 * NvM_WriteBlockFsm_WriteBlockDataState_Entry()
 *********************************************************************************************************************/
/*!  \brief       ENTRY action of WriteBlockFsm state WriteBlockData
 *   \details     -
 *   \param[in]   partitionId Partition ID.
 *   \pre         -
 *   \context     TASK
 *   \reentrant   FALSE
 *   \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, NVM_PRIVATE_CODE) NvM_WriteBlockFsm_WriteBlockDataState_Entry(NvM_PartitionIdType partitionId);

/**********************************************************************************************************************
 * NvM_WriteBlockFsm_WriteBlockDataState_Do()
 *********************************************************************************************************************/
/*!  \brief       DO action of WriteBlockFsm state WriteBlockData
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
FUNC(NvM_FsmLib_ProcessingResultType, NVM_PRIVATE_CODE) NvM_WriteBlockFsm_WriteBlockDataState_Do(
  NvM_PartitionIdType partitionId);

/**********************************************************************************************************************
 * NvM_WriteBlockFsm_UpdateBlockMetadataState_Do()
 *********************************************************************************************************************/
/*!  \brief       DO action of WriteBlockFsm state UpdateBlockMetadataState
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
FUNC(NvM_FsmLib_ProcessingResultType, NVM_PRIVATE_CODE) NvM_WriteBlockFsm_UpdateBlockMetadataState_Do(
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
 * Initializing a const structure (NvM_WriteBlockFsm_InitialState) can only be done with compile-time constants.
 * Therefore this defines are introduced to minimize code duplication within NvM_WriteBlockFsm_InitialState and
 * NvM_WriteBlockFsm_PrepareDataState initialization.
 */
#define NVM_WRITELOCKFSM_PREPAREDATASTATE_ENTRY NvM_FsmLib_EntryNoOp
#define NVM_WRITELOCKFSM_PREPAREDATASTATE_DO NvM_WriteBlockFsm_PrepareDataState_Do

/*! STATE: PrepareData */
/* PRQA S 3218 1 */ /* MD_Fsm_StateDefinitionStaticUsedOnlyInSingleFunction */
NVM_LOCAL CONST(NvM_StateType, NVM_PRIVATE_DATA) NvM_WriteBlockFsm_PrepareDataState = {
  NVM_WRITELOCKFSM_PREPAREDATASTATE_ENTRY, /* no ENTRY action required */
  NVM_WRITELOCKFSM_PREPAREDATASTATE_DO
};

/*! STATE: GenerateDataIntegrityRecord */
/* PRQA S 3218 1 */ /* MD_Fsm_StateDefinitionStaticUsedOnlyInSingleFunction */
NVM_LOCAL CONST(NvM_StateType, NVM_PRIVATE_DATA) NvM_WriteBlockFsm_GenerateDataIntegrityRecordState = {
  NvM_WriteBlockFsm_GenerateDataIntegrityRecordState_Entry,
  NvM_WriteBlockFsm_GenerateDataIntegrityRecordState_Do
};

/*! STATE: EvaluateSkipWrite */
/* PRQA S 3218 1 */ /* MD_Fsm_StateDefinitionStaticUsedOnlyInSingleFunction */
NVM_LOCAL CONST(NvM_StateType, NVM_PRIVATE_DATA) NvM_WriteBlockFsm_EvaluateSkipWriteState = {
  NvM_FsmLib_EntryNoOp, /* no ENTRY action required */
  NvM_WriteBlockFsm_EvaluateSkipWriteState_Do
};

/*! STATE: WriteBlockData */
/* PRQA S 3218 1 */ /* MD_Fsm_StateDefinitionStaticUsedOnlyInSingleFunction */
NVM_LOCAL CONST(NvM_StateType, NVM_PRIVATE_DATA) NvM_WriteBlockFsm_WriteBlockDataState = {
  NvM_WriteBlockFsm_WriteBlockDataState_Entry,
  NvM_WriteBlockFsm_WriteBlockDataState_Do
};

/*! STATE: UpdateBlockMetadataState */
/* PRQA S 3218 1 */ /* MD_Fsm_StateDefinitionStaticUsedOnlyInSingleFunction */
NVM_LOCAL CONST(NvM_StateType, NVM_PRIVATE_DATA) NvM_WriteBlockFsm_UpdateBlockMetadataState = {
  NvM_FsmLib_EntryNoOp, /* no ENTRY action required */
  NvM_WriteBlockFsm_UpdateBlockMetadataState_Do
};

/*! FSM: WriteBlock with ENTRY action and initial state */
/* PRQA S 3218 1 */ /* MD_Fsm_StateDefinitionStaticUsedOnlyInSingleFunction */
NVM_LOCAL CONST(NvM_FsmType, NVM_PRIVATE_DATA) NvM_WriteBlockFsm_InitialState = {
  NvM_WriteBlockFsm_Entry,
  {NVM_WRITELOCKFSM_PREPAREDATASTATE_ENTRY, NVM_WRITELOCKFSM_PREPAREDATASTATE_DO}
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
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * NvM_WriteBlockFsm_Entry()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, NVM_PRIVATE_CODE) NvM_WriteBlockFsm_Entry(
  NvM_PartitionIdType partitionId)                                                                                      /* PRQA S 3206 */ /* MD_NvM_CslMacroNotUsingPartitionId */
{
  NvM_FsmLib_InstancePtrToConstType fsmLibInstance =
    (NvM_FsmLib_InstancePtrToConstType)NvM_GetAddrSingleBlockServiceFsmLib_Instance(partitionId);
  NvM_FsmLib_TransitionToState(fsmLibInstance, NvM_WriteBlockFsm_PrepareDataState);

  /*
   * The parameter partitionId is not used within this function in single partition use case.
   * To avoid compiler warnings the following dummy statement is added.
   */
  NVM_DUMMY_STATEMENT(partitionId);                                                                                     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
}

/*!
 * STATE: PrepareData
 */

/**********************************************************************************************************************
 * NvM_WriteBlockFsm_PrepareDataState_Do()
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
FUNC(NvM_FsmLib_ProcessingResultType, NVM_PRIVATE_CODE) NvM_WriteBlockFsm_PrepareDataState_Do(
  NvM_PartitionIdType partitionId)                                                                                      /* PRQA S 3206 */ /* MD_NvM_CslMacroNotUsingPartitionId */
{
  NvM_FsmLib_InstancePtrToConstType fsmLibInstance =
    (NvM_FsmLib_InstancePtrToConstType)NvM_GetAddrSingleBlockServiceFsmLib_Instance(partitionId);
  NvM_WriteBlockFsm_ContextPtrType fsmContext = NvM_GetAddrWriteBlockFsm_Context(partitionId);
  NvM_SingleBlockJobContextPtrToConstType singleBlockJobContext = NvM_GetAddrSingleBlockJobContext(partitionId);
  NvM_BlockDescriptorPtrType blockDescriptor =
    NvM_GetAddrBlockDescriptor(singleBlockJobContext->BlockDescriptorLookupTableId);

  /* TemporaryRamBlockAddr can be a NULL_PTR */
  if(NvM_DataSync_RequestData(singleBlockJobContext->BlockDescriptorLookupTableId,
                              singleBlockJobContext->DataBuffer,
                              singleBlockJobContext->TemporaryRamBlockAddr) == E_OK)
  {
    if(blockDescriptor->DataIntegritySettings == NVM_BLOCK_DATA_INTEGRITY_OFF)
    {
      NvM_FsmLib_TransitionToState(fsmLibInstance, NvM_WriteBlockFsm_WriteBlockDataState);
    }
    else
    {
      NvM_FsmLib_TransitionToState(fsmLibInstance, NvM_WriteBlockFsm_GenerateDataIntegrityRecordState);
    }
  }
  else
  {
    NvM_ErrorCheck_ReportDemError(NVM_DEM_ERROR_TYPE_REQ_FAILED, partitionId);
    fsmContext->RequestResult = NVM_SERVICE_JOB_NOT_OK;
    NvM_FsmLib_TransitionToState(fsmLibInstance, NvM_WriteBlockFsm_UpdateBlockMetadataState);
  }

  /*
   * The parameter partitionId is not used within this function in single partition use case.
   * To avoid compiler warnings the following dummy statement is added.
   */
  NVM_DUMMY_STATEMENT(partitionId);                                                                                     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  return NVM_FSMLIB_PROCESSINGRESULT_CONTINUE;
}

/*!
 * STATE: GenerateDataIntegrityRecord
 */

/**********************************************************************************************************************
 * NvM_WriteBlockFsm_GenerateDataIntegrityRecordState_Entry()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, NVM_PRIVATE_CODE) NvM_WriteBlockFsm_GenerateDataIntegrityRecordState_Entry(NvM_PartitionIdType partitionId)
{
  NvM_SingleBlockJobContextPtrToConstType singleBlockJobContext = NvM_GetAddrSingleBlockJobContext(partitionId);
  NvM_BlockDescriptorPtrType blockDescriptor =
    NvM_GetAddrBlockDescriptor(singleBlockJobContext->BlockDescriptorLookupTableId);

  /* Generated data integrity record */
  NvM_DataPtrType generatedDataIntegrityRecord =
    &singleBlockJobContext->DataBuffer[blockDescriptor->NvBlockLength];

  /* The temporary pointer has not to be valid in the future and therefore can be used here,
   * because the data integrity record is copied to the given address.
   * So the data can be accessed via the address where the temporary pointer points at.
   */
  NvM_DataIntegrityJobContextType dataIntegrityJobContext = {
    NVM_DATAINTEGRITYSERVICE_JOB_GENERATE,
    singleBlockJobContext->DataBuffer,
    generatedDataIntegrityRecord,
    singleBlockJobContext->BlockId,
    singleBlockJobContext->BlockDescriptorLookupTableId,
    singleBlockJobContext->DataIndex,
    partitionId
  };

  /* Spawn DataIntegrityFsm generate job */
  NvM_DataIntegrityFsm_Process(&dataIntegrityJobContext);
}

/**********************************************************************************************************************
 * NvM_WriteBlockFsm_GenerateDataIntegrityRecordState_Do()
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
FUNC(NvM_FsmLib_ProcessingResultType, NVM_PRIVATE_CODE) NvM_WriteBlockFsm_GenerateDataIntegrityRecordState_Do(
  NvM_PartitionIdType partitionId)                                                                                      /* PRQA S 3206 */ /* MD_NvM_CslMacroNotUsingPartitionId */
{
  NvM_StateType nextState = NvM_WriteBlockFsm_WriteBlockDataState;

  NvM_FsmLib_InstancePtrToConstType fsmLibInstance =
    (NvM_FsmLib_InstancePtrToConstType)NvM_GetAddrSingleBlockServiceFsmLib_Instance(partitionId);

  NvM_SingleBlockJobContextPtrToConstType singleBlockJobContext = NvM_GetAddrSingleBlockJobContext(partitionId);
  NvM_BlockDescriptorPtrType blockDescriptor =
    NvM_GetAddrBlockDescriptor(singleBlockJobContext->BlockDescriptorLookupTableId);

  const NvM_ServiceJobResultType subFsmResult = NvM_FsmLib_GetSubFsmResult(fsmLibInstance);

#if (NVM_USE_DATA_INTEGRITY_INT_BUFFER == STD_ON)
  if((blockDescriptor->DataIntegrityIntBuffer != NULL_PTR) &&
     (singleBlockJobContext->TemporaryRamBlockAddr == NULL_PTR) &&
     (subFsmResult == NVM_SERVICE_JOB_OK))
  {
    /* Generated data integrity data */
    NvM_DataConstPtrToConstType generatedDataIntegrityRecord =
      &singleBlockJobContext->DataBuffer[blockDescriptor->NvBlockLength];

    NvM_GlobalUtilityLib_CopyDataIntegrityRecord(blockDescriptor->DataIntegritySettings,
      blockDescriptor->DataIntegrityIntBuffer,
      generatedDataIntegrityRecord);
  }
#endif /* NVM_USE_DATA_INTEGRITY_INT_BUFFER == STD_ON */

  if (subFsmResult != NVM_SERVICE_JOB_OK)
  {
    NvM_WriteBlockFsm_ContextPtrType fsmContext = NvM_GetAddrWriteBlockFsm_Context(partitionId);

    NvM_ErrorCheck_ReportDemError(NVM_DEM_ERROR_TYPE_REQ_FAILED, partitionId);
    fsmContext->RequestResult = NVM_SERVICE_JOB_NOT_OK;
    nextState = NvM_WriteBlockFsm_UpdateBlockMetadataState;
  } 
  else if (blockDescriptor->CrcCompMechanismBuffer != NULL_PTR)
  {
    nextState = NvM_WriteBlockFsm_EvaluateSkipWriteState;
  }
  else
  {
    nextState = NvM_WriteBlockFsm_WriteBlockDataState;
  }

  NvM_FsmLib_TransitionToState(fsmLibInstance, nextState);

  /* 
   * The parameter partitionId is not used within this function in single partition use case.
   * To avoid compiler warnings the following dummy statement is added.
   */
  NVM_DUMMY_STATEMENT(partitionId);                                                                                     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  return NVM_FSMLIB_PROCESSINGRESULT_CONTINUE;
}

/*!
 * STATE: EvaluateSkipWriting
 */

/**********************************************************************************************************************
 * NvM_WriteBlockFsm_EvaluateSkipWriteState_Do()
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
FUNC(NvM_FsmLib_ProcessingResultType, NVM_PRIVATE_CODE) NvM_WriteBlockFsm_EvaluateSkipWriteState_Do(
  NvM_PartitionIdType partitionId)                                                                                      /* PRQA S 3206 */ /* MD_NvM_CslMacroNotUsingPartitionId */
{
  NvM_FsmLib_InstancePtrToConstType fsmLibInstance =
      (NvM_FsmLib_InstancePtrToConstType)NvM_GetAddrSingleBlockServiceFsmLib_Instance(partitionId);
  NvM_SingleBlockJobContextPtrToConstType singleBlockJobContext = NvM_GetAddrSingleBlockJobContext(partitionId);

  NvM_BlockDescriptorPtrType blockDescriptor =
    NvM_GetAddrBlockDescriptor(singleBlockJobContext->BlockDescriptorLookupTableId);
  NvM_DataPtrType calculatedBuffer = &singleBlockJobContext->DataBuffer[blockDescriptor->NvBlockLength];

  NvM_DataType crcResetValueBuffer[4u];
  crcResetValueBuffer[0] = (NvM_DataType)NVM_CRCCOMPBUFFER_RESET_VALUE;
  crcResetValueBuffer[1] = (NvM_DataType)NVM_CRCCOMPBUFFER_RESET_VALUE;
  crcResetValueBuffer[2] = (NvM_DataType)NVM_CRCCOMPBUFFER_RESET_VALUE;
  crcResetValueBuffer[3] = (NvM_DataType)NVM_CRCCOMPBUFFER_RESET_VALUE;

  /* If CrcCompBuffer is reset block mustn't be skipped */
  boolean isCrcComparisonBufferReset = NvM_GlobalUtilityLib_CompareDataIntegrityRecords(
    blockDescriptor->DataIntegritySettings, crcResetValueBuffer, blockDescriptor->CrcCompMechanismBuffer);
  
  boolean isCrcComparisonMatch = NvM_GlobalUtilityLib_CompareDataIntegrityRecords(
    blockDescriptor->DataIntegritySettings, calculatedBuffer, blockDescriptor->CrcCompMechanismBuffer);

  if ((isCrcComparisonBufferReset == FALSE) && (isCrcComparisonMatch == TRUE))
  {
    NvM_WriteBlockFsm_ContextPtrType fsmContext = NvM_GetAddrWriteBlockFsm_Context(partitionId);

    fsmContext->RequestResult = NVM_SERVICE_JOB_OK;
    NvM_FsmLib_TransitionToState(fsmLibInstance, NvM_WriteBlockFsm_UpdateBlockMetadataState);
  }
  else
  {    
    NvM_FsmLib_TransitionToState(fsmLibInstance, NvM_WriteBlockFsm_WriteBlockDataState);
  }

  /*
   * The parameter partitionId is not used within this function in single partition use case.
   * To avoid compiler warnings the following dummy statement is added.
   */
  NVM_DUMMY_STATEMENT(partitionId);                                                                                     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  
  return NVM_FSMLIB_PROCESSINGRESULT_CONTINUE;
}

/*!
 * STATE: WriteBlockData
 */

/**********************************************************************************************************************
 * NvM_WriteBlockFsm_WriteBlockDataState_Entry()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, NVM_PRIVATE_CODE) NvM_WriteBlockFsm_WriteBlockDataState_Entry(NvM_PartitionIdType partitionId)
{
  /* Spawn NvJobFsm write service FSM */
  NvM_NvJobFsm_Execute(partitionId);
}

/**********************************************************************************************************************
 * NvM_WriteBlockFsm_WriteBlockDataState_Do()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(NvM_FsmLib_ProcessingResultType, NVM_PRIVATE_CODE) NvM_WriteBlockFsm_WriteBlockDataState_Do(
  NvM_PartitionIdType partitionId)                                                                                      /* PRQA S 3206 */ /* MD_NvM_CslMacroNotUsingPartitionId */
{
  NvM_FsmLib_InstancePtrToConstType fsmLibInstance =
    (NvM_FsmLib_InstancePtrToConstType)NvM_GetAddrSingleBlockServiceFsmLib_Instance(partitionId);
  NvM_WriteBlockFsm_ContextPtrType fsmContext = NvM_GetAddrWriteBlockFsm_Context(partitionId);

  fsmContext->RequestResult = NvM_FsmLib_GetSubFsmResult(fsmLibInstance);

  NvM_FsmLib_TransitionToState(fsmLibInstance, NvM_WriteBlockFsm_UpdateBlockMetadataState);

  /*
   * The parameter partitionId is not used within this function in single partition use case.
   * To avoid compiler warnings the following dummy statement is added.
   */
  NVM_DUMMY_STATEMENT(partitionId);                                                                                     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  return NVM_FSMLIB_PROCESSINGRESULT_CONTINUE;
}

/*!
 * STATE: UpdateBlockMetadataState
 */

/**********************************************************************************************************************
 * NvM_WriteBlockFsm_UpdateBlockMetadataState_Do()
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
FUNC(NvM_FsmLib_ProcessingResultType, NVM_PRIVATE_CODE) NvM_WriteBlockFsm_UpdateBlockMetadataState_Do(
  NvM_PartitionIdType partitionId)                                                                                      /* PRQA S 3206 */ /* MD_NvM_CslMacroNotUsingPartitionId */
{
  NvM_FsmLib_InstancePtrType fsmLibInstance =
    (NvM_FsmLib_InstancePtrType)NvM_GetAddrSingleBlockServiceFsmLib_Instance(partitionId);
  NvM_WriteBlockFsm_ContextPtrToConstType fsmContext = NvM_GetAddrWriteBlockFsm_Context(partitionId);
  NvM_SingleBlockJobContextPtrToConstType singleBlockJobContext = NvM_GetAddrSingleBlockJobContext(partitionId);        /* PRQA S 2983 */ /* MD_NvM_QACReportsFalsePositive2983 */
  NvM_BlockManagementInformationPtrType blockManagementInfo = NvM_GlobalUtilityLib_GetBlockManagementInfo(
    singleBlockJobContext->BlockId,
    singleBlockJobContext->BlockDescriptorLookupTableId,
    partitionId);

  if (fsmContext->RequestResult == NVM_SERVICE_JOB_OK)
  {
    blockManagementInfo->RamBlockState = NVM_RAMBLOCKSTATE_VALID_UNCHANGED;

    NvM_BlockDescriptorPtrType blockDescriptor = 
      NvM_GetAddrBlockDescriptor(singleBlockJobContext->BlockDescriptorLookupTableId);

    if (blockDescriptor->Flags.WriteBlockOnceEnabled == NVM_WRITE_BLOCK_ONCE_ON)
    {
      blockManagementInfo->WriteProtection = TRUE;
    }

    if (blockDescriptor->CrcCompMechanismBuffer != NULL_PTR)
    {
      /* Update CrcCompMechanismBuffer with the calculated CRC */
      NvM_GlobalUtilityLib_CopyDataIntegrityRecord(blockDescriptor->DataIntegritySettings, 
        blockDescriptor->CrcCompMechanismBuffer, 
        &singleBlockJobContext->DataBuffer[blockDescriptor->NvBlockLength]);
    }
  }
  else
  {
    blockManagementInfo->RamBlockState = NVM_RAMBLOCKSTATE_INVALID_UNCHANGED;
  }

  NvM_FsmLib_FinalizeCurrentActiveFsm(fsmLibInstance, fsmContext->RequestResult);

  /*
   * The parameter partitionId is not used within this function in single partition use case.
   * To avoid compiler warnings the following dummy statement is added.
   */
  NVM_DUMMY_STATEMENT(partitionId);                                                                                     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  return NVM_FSMLIB_PROCESSINGRESULT_CONTINUE;
}

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * NvM_WriteBlockFsm_WriteBlock()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, NVM_PRIVATE_CODE) NvM_WriteBlockFsm_WriteBlock(NvM_PartitionIdType partitionId)                              /* PRQA S 3206 */ /* MD_NvM_CslMacroNotUsingPartitionId */
{
  NvM_FsmLib_InstancePtrType fsmLibInstance =
    (NvM_FsmLib_InstancePtrType)NvM_GetAddrSingleBlockServiceFsmLib_Instance(partitionId);

  /* COM-4978: Wait for CSL feature to store init value of generated partion data */
  NvM_WriteBlockFsm_InstancePtrType fsmInstance = NvM_GetAddrWriteBlockFsm_Instance(partitionId);
  *fsmInstance = NvM_WriteBlockFsm_InitialState;

  (void)NvM_FsmLib_SpawnFsm(fsmLibInstance, *fsmInstance);

  /*
   * The parameter partitionId is not used within this function in single partition use case.
   * To avoid compiler warnings the following dummy statement is added.
   */
  NVM_DUMMY_STATEMENT(partitionId);                                                                                     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
}

#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: NvM_WriteBlockFsm.c
 *********************************************************************************************************************/
