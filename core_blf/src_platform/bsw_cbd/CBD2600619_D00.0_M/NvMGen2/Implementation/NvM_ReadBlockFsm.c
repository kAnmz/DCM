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
/*!        \file  NvM_ReadBlockFsm.c
 *        \brief  NvM_ReadBlockFsm source file
 *      \details  Implementation of read block state machine
 *         \unit  NvM_ReadBlockFsm
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#define NVM_READBLOCKFSM_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "NvM_ReadBlockFsm.h"
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
 * NvM_ReadBlockFsm_Entry()
 *********************************************************************************************************************/
/*!  \brief       ENTRY action of ReadBlockFsm
 *   \details     -
 *   \param[in]   partitionId Partition ID.
 *   \pre         -
 *   \context     TASK
 *   \reentrant   FALSE
 *   \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, NVM_PRIVATE_CODE) NvM_ReadBlockFsm_Entry(NvM_PartitionIdType partitionId);

/**********************************************************************************************************************
 * NvM_ReadBlockFsm_ReadBlockDataState_Entry()
 *********************************************************************************************************************/
/*!  \brief       ENTRY action of ReadBlockFsm state ReadBlockData
 *   \details     -
 *   \param[in]   partitionId Partition ID.
 *   \pre         -
 *   \context     TASK
 *   \reentrant   FALSE
 *   \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, NVM_PRIVATE_CODE) NvM_ReadBlockFsm_ReadBlockDataState_Entry(NvM_PartitionIdType partitionId);

/**********************************************************************************************************************
 * NvM_ReadBlockFsm_ReadBlockDataState_Do()
 *********************************************************************************************************************/
/*!  \brief       DO action of ReadBlockFsm state ReadBlockData
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
FUNC(NvM_FsmLib_ProcessingResultType, NVM_PRIVATE_CODE) NvM_ReadBlockFsm_ReadBlockDataState_Do(
  NvM_PartitionIdType partitionId);

/**********************************************************************************************************************
 * NvM_ReadBlockFsm_ValidateDataIntegrityState_Entry()
 *********************************************************************************************************************/
/*!  \brief       ENTRY action of ReadBlockFsm state ValidateDataIntegrity
 *   \details     -
 *   \param[in]   partitionId Partition ID.
 *   \pre         -
 *   \context     TASK
 *   \reentrant   FALSE
 *   \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, NVM_PRIVATE_CODE) NvM_ReadBlockFsm_ValidateDataIntegrityState_Entry(NvM_PartitionIdType partitionId);

/**********************************************************************************************************************
 * NvM_ReadBlockFsm_ValidateDataIntegrityState_Do()
 *********************************************************************************************************************/
/*!  \brief       DO action of ReadBlockFsm state ValidateDataIntegrity
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
FUNC(NvM_FsmLib_ProcessingResultType, NVM_PRIVATE_CODE) NvM_ReadBlockFsm_ValidateDataIntegrityState_Do(
  NvM_PartitionIdType partitionId);

/**********************************************************************************************************************
 * NvM_ReadBlockFsm_ProvideDataState_Do()
 *********************************************************************************************************************/
/*!  \brief       DO action of ReadBlockFsm state ProvideData
 *   \details     -
 *   \param[in]   partitionId Partition ID.
 *   \return      Always NVM_FSMLIB_PROCESSINGRESULT_CONTINUE.
 *   \pre         -
 *   \context     TASK
 *   \reentrant   FALSE
 *   \synchronous TRUE
 *********************************************************************************************************************/
FUNC(NvM_FsmLib_ProcessingResultType, NVM_PRIVATE_CODE) NvM_ReadBlockFsm_ProvideDataState_Do(
  NvM_PartitionIdType partitionId);

/**********************************************************************************************************************
 * NvM_ReadBlockFsm_AttemptDefaultDataRecoveryState_Do()
 *********************************************************************************************************************/
/*!  \brief       DO action of ReadBlockFsm state AttemptDefaultDataRecovery
 *   \details     -
 *   \param[in]   partitionId Partition ID.
 *   \return      Always NVM_FSMLIB_PROCESSINGRESULT_CONTINUE.
 *   \pre         -
 *   \context     TASK
 *   \reentrant   FALSE
 *   \synchronous TRUE
 *********************************************************************************************************************/
FUNC(NvM_FsmLib_ProcessingResultType, NVM_PRIVATE_CODE) NvM_ReadBlockFsm_AttemptDefaultDataRecoveryState_Do(
  NvM_PartitionIdType partitionId);

/**********************************************************************************************************************
 * NvM_ReadBlockFsm_UpdateBlockMetadataState_Do()
 *********************************************************************************************************************/
/*!  \brief       DO action of ReadBlockFsm state UpdateBlockMetadata
 *   \details     -
 *   \param[in]   partitionId Partition ID.
 *   \return      Always NVM_FSMLIB_PROCESSINGRESULT_CONTINUE.
 *   \pre         -
 *   \context     TASK
 *   \reentrant   FALSE
 *   \synchronous TRUE
 *********************************************************************************************************************/
FUNC(NvM_FsmLib_ProcessingResultType, NVM_PRIVATE_CODE) NvM_ReadBlockFsm_UpdateBlockMetadataState_Do(
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
 * Initializing a const structure (NvM_ReadBlockFsm_InitialState) can only be done with compile-time constants.
 * Therefore this defines are introduced to minimize code duplication within NvM_ReadBlockFsm_InitialState and
 * NvM_ReadBlockFsm_ReadBlockDataState initialization.
 */
#define NVM_READBLOCKFSM_READBLOCKDATASTATE_ENTRY NvM_ReadBlockFsm_ReadBlockDataState_Entry
#define NVM_READBLOCKFSM_READBLOCKDATASTATE_DO NvM_ReadBlockFsm_ReadBlockDataState_Do

/*! STATE: ReadBlockData */
/* PRQA S 3218 1 */ /* MD_Fsm_StateDefinitionStaticUsedOnlyInSingleFunction */
NVM_LOCAL CONST(NvM_StateType, NVM_PRIVATE_DATA) NvM_ReadBlockFsm_ReadBlockDataState = {
  NVM_READBLOCKFSM_READBLOCKDATASTATE_ENTRY,
  NVM_READBLOCKFSM_READBLOCKDATASTATE_DO
};

/*! STATE: ValidateDataIntegrity */
/* PRQA S 3218 1 */ /* MD_Fsm_StateDefinitionStaticUsedOnlyInSingleFunction */
NVM_LOCAL CONST(NvM_StateType, NVM_PRIVATE_DATA) NvM_ReadBlockFsm_ValidateDataIntegrityState = {
  NvM_ReadBlockFsm_ValidateDataIntegrityState_Entry,
  NvM_ReadBlockFsm_ValidateDataIntegrityState_Do
};

/*! STATE: ProvideData */
/* PRQA S 3218 1 */ /* MD_Fsm_StateDefinitionStaticUsedOnlyInSingleFunction */
NVM_LOCAL CONST(NvM_StateType, NVM_PRIVATE_DATA) NvM_ReadBlockFsm_ProvideDataState = {
  NvM_FsmLib_EntryNoOp, /* no ENTRY action required */
  NvM_ReadBlockFsm_ProvideDataState_Do
};

/*! STATE: AttemptDefaultDataRecovery */
/* PRQA S 3218 1 */ /* MD_Fsm_StateDefinitionStaticUsedOnlyInSingleFunction */
NVM_LOCAL CONST(NvM_StateType, NVM_PRIVATE_DATA) NvM_ReadBlockFsm_AttemptDefaultDataRecoveryState = {
  NvM_FsmLib_EntryNoOp, /* no ENTRY action required */
  NvM_ReadBlockFsm_AttemptDefaultDataRecoveryState_Do
};

/*! STATE: UpdateBlockMetadata */
/* PRQA S 3218 1 */ /* MD_Fsm_StateDefinitionStaticUsedOnlyInSingleFunction */
NVM_LOCAL CONST(NvM_StateType, NVM_PRIVATE_DATA) NvM_ReadBlockFsm_UpdateBlockMetadataState = {
  NvM_FsmLib_EntryNoOp, /* no ENTRY action required */
  NvM_ReadBlockFsm_UpdateBlockMetadataState_Do
};

/*! FSM: ReadBlock with ENTRY action and initial state */
/* PRQA S 3218 1 */ /* MD_Fsm_StateDefinitionStaticUsedOnlyInSingleFunction */
NVM_LOCAL CONST(NvM_FsmType, NVM_PRIVATE_DATA) NvM_ReadBlockFsm_InitialState = {
  NvM_ReadBlockFsm_Entry,
  {NVM_READBLOCKFSM_READBLOCKDATASTATE_ENTRY, NVM_READBLOCKFSM_READBLOCKDATASTATE_DO}
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
 * NvM_ReadBlockFsm_Entry()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, NVM_PRIVATE_CODE) NvM_ReadBlockFsm_Entry(NvM_PartitionIdType partitionId)                                    /* PRQA S 3206 */ /* MD_NvM_CslMacroNotUsingPartitionId */
{
  NvM_FsmLib_InstancePtrToConstType fsmLibInstance =
    (NvM_FsmLib_InstancePtrToConstType)NvM_GetAddrSingleBlockServiceFsmLib_Instance(partitionId);
  NvM_FsmLib_TransitionToState(fsmLibInstance, NvM_ReadBlockFsm_ReadBlockDataState);

  /*
   * The parameter partitionId is not used within this function in single partition use case.
   * To avoid compiler warnings the following dummy statement is added.
   */
  NVM_DUMMY_STATEMENT(partitionId);                                                                                     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
}

/*!
 * STATE: ReadBlockData
 */

/**********************************************************************************************************************
 * NvM_ReadBlockFsm_ReadBlockDataState_Entry()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, NVM_PRIVATE_CODE) NvM_ReadBlockFsm_ReadBlockDataState_Entry(NvM_PartitionIdType partitionId)
{
  /* Spawn NvJobFsm read service FSM */
  NvM_NvJobFsm_Execute(partitionId);
}

/**********************************************************************************************************************
 * NvM_ReadBlockFsm_ReadBlockDataState_Do()
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
FUNC(NvM_FsmLib_ProcessingResultType, NVM_PRIVATE_CODE) NvM_ReadBlockFsm_ReadBlockDataState_Do(
  NvM_PartitionIdType partitionId)                                                                                      /* PRQA S 3206 */ /* MD_NvM_CslMacroNotUsingPartitionId */
{
  NvM_FsmLib_InstancePtrType fsmLibInstance =
    (NvM_FsmLib_InstancePtrType)NvM_GetAddrSingleBlockServiceFsmLib_Instance(partitionId);
  NvM_ReadBlockFsm_ContextPtrType fsmContext = NvM_GetAddrReadBlockFsm_Context(partitionId);
  NvM_SingleBlockJobContextPtrToConstType singleBlockJobContext = NvM_GetAddrSingleBlockJobContext(partitionId);

  NvM_BlockDescriptorPtrType blockDescriptor =
    NvM_GetAddrBlockDescriptor(singleBlockJobContext->BlockDescriptorLookupTableId);

  /* Poll and map result */
  fsmContext->NvJobResult = NvM_FsmLib_GetSubFsmResult(fsmLibInstance);

  if (fsmContext->NvJobResult == NVM_SERVICE_JOB_OK)
  {
    if (blockDescriptor->DataIntegritySettings == NVM_BLOCK_DATA_INTEGRITY_OFF)
    {
      NvM_FsmLib_TransitionToState(fsmLibInstance, NvM_ReadBlockFsm_ProvideDataState);
    }
    else
    {
      NvM_FsmLib_TransitionToState(fsmLibInstance, NvM_ReadBlockFsm_ValidateDataIntegrityState);
    }
  }
  else
  {
    NvM_FsmLib_TransitionToState(fsmLibInstance, NvM_ReadBlockFsm_AttemptDefaultDataRecoveryState);
  }

  /*
   * The parameter partitionId is not used within this function in single partition use case.
   * To avoid compiler warnings the following dummy statement is added.
   */
  NVM_DUMMY_STATEMENT(partitionId);                                                                                     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  return NVM_FSMLIB_PROCESSINGRESULT_CONTINUE;
}

/*!
 * STATE: ValidateDataIntegrity
 */

/**********************************************************************************************************************
 * NvM_ReadBlockFsm_ValidateDataIntegrityState_Entry()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, NVM_PRIVATE_CODE) NvM_ReadBlockFsm_ValidateDataIntegrityState_Entry(NvM_PartitionIdType partitionId)
{
  NvM_SingleBlockJobContextPtrToConstType singleBlockJobContext = NvM_GetAddrSingleBlockJobContext(partitionId);
  NvM_BlockDescriptorPtrType blockDescriptor =
    NvM_GetAddrBlockDescriptor(singleBlockJobContext->BlockDescriptorLookupTableId);
  
  /* Read-out data integrity data from NV RAM */
  NvM_DataPtrType readOutDataIntegrityRecord = &singleBlockJobContext->DataBuffer[blockDescriptor->NvBlockLength];

  NvM_DataIntegrityJobContextType dataIntegrityJobContext = {
    NVM_DATAINTEGRITYSERVICE_JOB_VERIFY,
    singleBlockJobContext->DataBuffer,
    readOutDataIntegrityRecord,
    singleBlockJobContext->BlockId,
    singleBlockJobContext->BlockDescriptorLookupTableId,
    singleBlockJobContext->DataIndex,
    partitionId
  };

  /* Spawn DataIntegrityFsm validate job */
  NvM_DataIntegrityFsm_Process(&dataIntegrityJobContext);
}

/**********************************************************************************************************************
 * NvM_ReadBlockFsm_ValidateDataIntegrityState_Do()
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
FUNC(NvM_FsmLib_ProcessingResultType, NVM_PRIVATE_CODE) NvM_ReadBlockFsm_ValidateDataIntegrityState_Do(
  NvM_PartitionIdType partitionId)                                                                                      /* PRQA S 3206 */ /* MD_NvM_CslMacroNotUsingPartitionId */
{
  NvM_FsmLib_InstancePtrToConstType fsmLibInstance =
    (NvM_FsmLib_InstancePtrToConstType)NvM_GetAddrSingleBlockServiceFsmLib_Instance(partitionId);

  /* Poll and map result */
  NvM_ServiceJobResultType result = NvM_FsmLib_GetSubFsmResult(fsmLibInstance);

  if (result == NVM_SERVICE_JOB_OK)
  {
#if (NVM_USE_DATA_INTEGRITY_INT_BUFFER == STD_ON)
    NvM_SingleBlockJobContextPtrToConstType singleBlockJobContext = NvM_GetAddrSingleBlockJobContext(partitionId);
    NvM_BlockDescriptorPtrType blockDescriptor =
      NvM_GetAddrBlockDescriptor(singleBlockJobContext->BlockDescriptorLookupTableId);

    if((blockDescriptor->DataIntegrityIntBuffer != NULL_PTR) &&
       (singleBlockJobContext->TemporaryRamBlockAddr == NULL_PTR))
    {
      /* Read-out data integrity data from NV RAM */
      NvM_DataConstPtrToConstType readOutDataIntegrityRecord =
        &singleBlockJobContext->DataBuffer[blockDescriptor->NvBlockLength];

      NvM_GlobalUtilityLib_CopyDataIntegrityRecord(blockDescriptor->DataIntegritySettings,
        blockDescriptor->DataIntegrityIntBuffer, readOutDataIntegrityRecord);
    }
#endif /* NVM_USE_DATA_INTEGRITY_INT_BUFFER == STD_ON */

    NvM_FsmLib_TransitionToState(fsmLibInstance, NvM_ReadBlockFsm_ProvideDataState);
  }
  else
  {
    NvM_ErrorCheck_ReportDemError(NVM_DEM_ERROR_TYPE_INTEGRITY_FAILED, partitionId);
    NvM_FsmLib_TransitionToState(fsmLibInstance, NvM_ReadBlockFsm_AttemptDefaultDataRecoveryState);
  }

  /*
   * The parameter partitionId is not used within this function in single partition use case.
   * To avoid compiler warnings the following dummy statement is added.
   */
  NVM_DUMMY_STATEMENT(partitionId);                                                                                     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  return NVM_FSMLIB_PROCESSINGRESULT_CONTINUE;
}

/*!
 * STATE: ProvideData
 */

/**********************************************************************************************************************
 * NvM_ReadBlockFsm_ProvideDataState_Do()
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
FUNC(NvM_FsmLib_ProcessingResultType, NVM_PRIVATE_CODE) NvM_ReadBlockFsm_ProvideDataState_Do(
  NvM_PartitionIdType partitionId)                                                                                      /* PRQA S 3206 */ /* MD_NvM_CslMacroNotUsingPartitionId */
{
  NvM_FsmLib_InstancePtrToConstType fsmLibInstance =
    (NvM_FsmLib_InstancePtrToConstType)NvM_GetAddrSingleBlockServiceFsmLib_Instance(partitionId);
  NvM_ReadBlockFsm_ContextPtrType fsmContext = NvM_GetAddrReadBlockFsm_Context(partitionId);
  NvM_SingleBlockJobContextPtrToConstType singleBlockJobContext = NvM_GetAddrSingleBlockJobContext(partitionId);

  /* TemporaryRamBlockAddr can be a NULL_PTR. */
  if (NvM_DataSync_ProvideData(singleBlockJobContext->BlockDescriptorLookupTableId, singleBlockJobContext->DataBuffer,
                                singleBlockJobContext->TemporaryRamBlockAddr) == E_OK)
  {
    fsmContext->RequestResult = fsmContext->NvJobResult;
  }
  else
  {
    NvM_ErrorCheck_ReportDemError(NVM_DEM_ERROR_TYPE_REQ_FAILED, partitionId);
    fsmContext->RequestResult = NVM_SERVICE_JOB_NOT_OK;
  }

  NvM_FsmLib_TransitionToState(fsmLibInstance, NvM_ReadBlockFsm_UpdateBlockMetadataState);

  /*
   * The parameter partitionId is not used within this function in single partition use case.
   * To avoid compiler warnings the following dummy statement is added.
   */
  NVM_DUMMY_STATEMENT(partitionId);                                                                                     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  return NVM_FSMLIB_PROCESSINGRESULT_CONTINUE;
}

/*!
 * STATE: AttemptDefaultDataRecovery
 */

/**********************************************************************************************************************
 * NvM_ReadBlockFsm_AttemptDefaultDataRecoveryState_Do()
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
FUNC(NvM_FsmLib_ProcessingResultType, NVM_PRIVATE_CODE) NvM_ReadBlockFsm_AttemptDefaultDataRecoveryState_Do(
  NvM_PartitionIdType partitionId)                                                                                      /* PRQA S 3206 */ /* MD_NvM_CslMacroNotUsingPartitionId */
{
  NvM_FsmLib_InstancePtrToConstType fsmLibInstance =
    (NvM_FsmLib_InstancePtrToConstType)NvM_GetAddrSingleBlockServiceFsmLib_Instance(partitionId);
  NvM_ReadBlockFsm_ContextPtrType fsmContext = NvM_GetAddrReadBlockFsm_Context(partitionId);
  NvM_SingleBlockJobContextPtrToConstType singleBlockJobContext = NvM_GetAddrSingleBlockJobContext(partitionId);

  /* TemporaryRamBlockAddr can be a NULL_PTR */
  if (NvM_DataSync_RestoreDefaultData(singleBlockJobContext->BlockDescriptorLookupTableId,
        singleBlockJobContext->SingleBlockJobType,
        singleBlockJobContext->TemporaryRamBlockAddr) == E_OK)
  {
    fsmContext->RequestResult = NVM_SERVICE_JOB_RESTORED_DEFAULTS;
  }
  else
  {
    fsmContext->RequestResult = NVM_SERVICE_JOB_NOT_OK;
  }

  NvM_FsmLib_TransitionToState(fsmLibInstance, NvM_ReadBlockFsm_UpdateBlockMetadataState);

  /*
   * The parameter partitionId is not used within this function in single partition use case.
   * To avoid compiler warnings the following dummy statement is added.
   */
  NVM_DUMMY_STATEMENT(partitionId);                                                                                     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  return NVM_FSMLIB_PROCESSINGRESULT_CONTINUE;
}

/*!
 * STATE: UpdateBlockMetadata
 */

/**********************************************************************************************************************
 * NvM_ReadBlockFsm_UpdateBlockMetadataState_Do()
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
FUNC(NvM_FsmLib_ProcessingResultType, NVM_PRIVATE_CODE) NvM_ReadBlockFsm_UpdateBlockMetadataState_Do(
  NvM_PartitionIdType partitionId)                                                                                      /* PRQA S 3206 */ /* MD_NvM_CslMacroNotUsingPartitionId */
{
  NvM_FsmLib_InstancePtrType fsmLibInstance =
    (NvM_FsmLib_InstancePtrType)NvM_GetAddrSingleBlockServiceFsmLib_Instance(partitionId);
  NvM_ReadBlockFsm_ContextPtrToConstType fsmContext = NvM_GetAddrReadBlockFsm_Context(partitionId);
  NvM_SingleBlockJobContextPtrToConstType singleBlockJobContext = NvM_GetAddrSingleBlockJobContext(partitionId);        /* PRQA S 2983 */ /* MD_NvM_QACReportsFalsePositive2983 */
  NvM_BlockManagementInformationPtrType blockManagementInfo = NvM_GlobalUtilityLib_GetBlockManagementInfo(
    singleBlockJobContext->BlockId,
    singleBlockJobContext->BlockDescriptorLookupTableId,
    partitionId);

  NvM_BlockDescriptorPtrType blockDescriptor = 
      NvM_GetAddrBlockDescriptor(singleBlockJobContext->BlockDescriptorLookupTableId);

  if ((fsmContext->RequestResult == NVM_SERVICE_JOB_OK))
  {
    blockManagementInfo->RamBlockState = NVM_RAMBLOCKSTATE_VALID_UNCHANGED;

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
  else if (fsmContext->RequestResult == NVM_SERVICE_JOB_RESTORED_DEFAULTS)
  {
    blockManagementInfo->RamBlockState = NVM_RAMBLOCKSTATE_VALID_CHANGED;
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
 * NvM_ReadBlockFsm_ReadBlock()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, NVM_PRIVATE_CODE) NvM_ReadBlockFsm_ReadBlock(NvM_PartitionIdType partitionId)                                /* PRQA S 3206 */ /* MD_NvM_CslMacroNotUsingPartitionId */
{
  NvM_FsmLib_InstancePtrType fsmLibInstance =
    (NvM_FsmLib_InstancePtrType)NvM_GetAddrSingleBlockServiceFsmLib_Instance(partitionId);

  /* COM-4978: Wait for CSL feature to store init value of generated partion data */
  NvM_ReadBlockFsm_InstancePtrType fsmInstance = NvM_GetAddrReadBlockFsm_Instance(partitionId);
  *fsmInstance = NvM_ReadBlockFsm_InitialState;

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
 *  END OF FILE: NvM_ReadBlockFsm.c
 *********************************************************************************************************************/
