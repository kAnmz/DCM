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
/*!        \file  NvM_ReadAllFsm.c
 *        \brief  NvM_ReadAllFsm source file
 *      \details  Implementation of read all state machine
 *         \unit  NvM_ReadAllFsm
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#define NVM_READALLFSM_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "NvM_ReadAllFsm.h"
#include "NvM_CfgDefines.h"
#include "NvM_FsmLib.h"
#include "NvM_SingleBlockJobFsm.h"
#include "NvM_GlobalUtilityLib.h"
#include "NvM_Notification.h"
#include "NvM_ErrorCheck.h"
#include "NvM_DataSync.h"
#include "vstdlib.h"
#include "NvM_PrivateCfg.h"
/*
 * Skip reading of valid data is only available for data integrity int buffer enabled configurations at the moment.
 * This is the case, because an internal buffer to hold payload and DataIntegrityRecord is always available.
 * at the moment. So the user does not care about data integrity data at all and skip reading can only be provided
 * if data integrity int buffer is enabled.
 */
#if (NVM_USE_DATA_INTEGRITY_INT_BUFFER == STD_ON)
#include "NvM_DataIntegrityFsm.h"
#endif /* NVM_USE_DATA_INTEGRITY_INT_BUFFER == STD_ON */

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

/* Read Block Error Flag bit mask */
#define NVM_READ_BLOCK_ERROR_FLAG_TRUE      1u
#define NVM_READ_BLOCK_ERROR_FLAG_FALSE     0u

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

/***********************************************************************************************************************
 *  FSM FUNCTION PROTOTYPES
 **********************************************************************************************************************/
#define NVM_START_SEC_CODE
#include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * NvM_ReadAllFsm_Entry()
 *********************************************************************************************************************/
/*!  \brief       ENTRY action of ReadAllFsm
 *   \details     -
 *   \param[in]   partitionId Partition ID.
 *   \pre         -
 *   \context     TASK
 *   \reentrant   FALSE
 *   \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, NVM_PRIVATE_CODE) NvM_ReadAllFsm_Entry(NvM_PartitionIdType partitionId);

/**********************************************************************************************************************
 * NvM_ReadAllFsm_FindNextRelevantBlockState_Do()
 *********************************************************************************************************************/
/*!  \brief       DO action of ReadAllFsm state FindNextRelevantBlock
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
FUNC(NvM_FsmLib_ProcessingResultType, NVM_PRIVATE_CODE) NvM_ReadAllFsm_FindNextRelevantBlockState_Do(
  NvM_PartitionIdType partitionId);

#if (NVM_DYNAMIC_CONFIGURATION == STD_ON)

/**********************************************************************************************************************
 * NvM_ReadAllFsm_CheckConfigBlockState_Entry()
 *********************************************************************************************************************/
/*!  \brief       ENTRY action of ReadAllFsm state CheckConfigBlock
 *   \details     -
 *   \param[in]   partitionId Partition ID.
 *   \pre         -
 *   \context     TASK
 *   \reentrant   FALSE
 *   \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, NVM_PRIVATE_CODE) NvM_ReadAllFsm_CheckConfigBlockState_Entry(NvM_PartitionIdType partitionId);

/**********************************************************************************************************************
 * NvM_ReadAllFsm_CheckConfigBlockState_Do()
 *********************************************************************************************************************/
/*!  \brief       DO action of ReadAllFsm state CheckConfigBlock
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
FUNC(NvM_FsmLib_ProcessingResultType, NVM_PRIVATE_CODE) NvM_ReadAllFsm_CheckConfigBlockState_Do(
  NvM_PartitionIdType partitionId);

#endif

/*
 * Skip reading of valid data is only available for data integrity int buffer enabled configurations at the moment.
 * This is the case, because an internal buffer to hold payload and DataIntegrityRecord is always available.
 * at the moment. So the user does not care about data integrity data at all and skip reading can only be provided
 * if data integrity int buffer is enabled.
 */
#if (NVM_USE_DATA_INTEGRITY_INT_BUFFER == STD_ON)

/**********************************************************************************************************************
 * NvM_ReadAllFsm_EvaluateNvReadSkipState_Entry()
 *********************************************************************************************************************/
/*!  \brief       ENTRY action of ReadAllFsm state EvaluateNvReadSkip
 *   \details     -
 *   \param[in]   partitionId Partition ID.
 *   \pre         -
 *   \context     TASK
 *   \reentrant   FALSE
 *   \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, NVM_PRIVATE_CODE) NvM_ReadAllFsm_EvaluateNvReadSkipState_Entry(NvM_PartitionIdType partitionId);

/**********************************************************************************************************************
 * NvM_ReadAllFsm_EvaluateNvReadSkipState_Do()
 *********************************************************************************************************************/
/*!  \brief       DO action of ReadAllFsm state EvaluateNvReadSkip
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
FUNC(NvM_FsmLib_ProcessingResultType, NVM_PRIVATE_CODE) NvM_ReadAllFsm_EvaluateNvReadSkipState_Do(
  NvM_PartitionIdType partitionId);

#endif /* NVM_USE_DATA_INTEGRITY_INT_BUFFER == STD_ON */

#if (NVM_JOB_PRIORITIZATION == STD_ON)
/**********************************************************************************************************************
 * NvM_ReadAllFsm_WaitForReadAllReadyToResumeState_Do()
 *********************************************************************************************************************/
/*!  \brief       DO action of ReadAllFsm state WaitForReadAllReadyToResume
 *   \details     This state is only entered if an immediate job has interrupted the ReadAll job
 *                and hence the ReadAllFsm was notified about this interruption.
 *                This state automatically acts as waiting state until the immediate block job
 *                was processed, because the ServiceProcessor FSM does no longer process the multi block job stack
 *                till the immediate job is finished. After the finalization of the immediate block job,
 *                the ReadAll FSM is resumed by the ServiceProcessor FSM by continuing to process the multi
 *                block job stack again.
 *   \param[in]   partitionId Partition ID.
 *   \return      CONTINUE to resume ReadAll processing
 *   \pre         -
 *   \context     TASK
 *   \reentrant   FALSE
 *   \synchronous TRUE
 *********************************************************************************************************************/
FUNC(NvM_FsmLib_ProcessingResultType, NVM_PRIVATE_CODE) NvM_ReadAllFsm_WaitForReadAllReadyToResumeState_Do(
  NvM_PartitionIdType partitionId);
#endif /* NVM_JOB_PRIORITIZATION == STD_ON */

/**********************************************************************************************************************
 * NvM_ReadAllFsm_ReadCurrentBlockState_Entry()
 *********************************************************************************************************************/
/*!  \brief       ENTRY action of ReadAllFsm state ReadCurrentBlock
 *   \details     -
 *   \param[in]   partitionId Partition ID.
 *   \pre         -
 *   \context     TASK
 *   \reentrant   FALSE
 *   \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, NVM_PRIVATE_CODE) NvM_ReadAllFsm_ReadCurrentBlockState_Entry(NvM_PartitionIdType partitionId);

/**********************************************************************************************************************
 * NvM_ReadAllFsm_ReadCurrentBlockState_Do()
 *********************************************************************************************************************/
/*!  \brief       DO action of ReadAllFsm state ReadCurrentBlock
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
FUNC(NvM_FsmLib_ProcessingResultType, NVM_PRIVATE_CODE) NvM_ReadAllFsm_ReadCurrentBlockState_Do(
  NvM_PartitionIdType partitionId);

#if (NVM_DYNAMIC_CONFIGURATION == STD_ON)
/**********************************************************************************************************************
 * NvM_ReadAllFsm_RestoreBlockDefaultsState_Do()
 *********************************************************************************************************************/
/*!  \brief       DO action of ReadAllFsm state RestoreBlockDefaults
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
FUNC(NvM_FsmLib_ProcessingResultType, NVM_PRIVATE_CODE) NvM_ReadAllFsm_RestoreBlockDefaultsState_Do(
  NvM_PartitionIdType partitionId);
#endif /* NVM_DYNAMIC_CONFIGURATION */

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
 * Initializing a const structure (NvM_ReadAllFsm_InitialState) can only be done with compile-time constants.
 * Therefore this defines are introduced to minimize code duplication within NvM_ReadAllFsm_InitialState,
 * NvM_ReadAllFsm_FindNextRelevantBlockState and NvM_ReadAllFsm_CheckConfigBlockState initialization.
 */
#define NVM_READALLFSM_FINDNEXTRELEVANTBLOCKSTATE_ENTRY NvM_FsmLib_EntryNoOp
#define NVM_READALLFSM_FINDNEXTRELEVANTBLOCKSTATE_DO NvM_ReadAllFsm_FindNextRelevantBlockState_Do

#if (NVM_DYNAMIC_CONFIGURATION == STD_ON)
#define NVM_READALLFSM_CHECKCONFIGBLOCKSTATE_ENTRY NvM_ReadAllFsm_CheckConfigBlockState_Entry
#define NVM_READALLFSM_CHECKCONFIGBLOCKSTATE_DO NvM_ReadAllFsm_CheckConfigBlockState_Do
#endif

/*! STATE: FindNextRelevantBlock */
NVM_LOCAL CONST(NvM_StateType, NVM_PRIVATE_DATA) NvM_ReadAllFsm_FindNextRelevantBlockState = {
  NVM_READALLFSM_FINDNEXTRELEVANTBLOCKSTATE_ENTRY, /* no ENTRY action required */
  NVM_READALLFSM_FINDNEXTRELEVANTBLOCKSTATE_DO
};

#if (NVM_DYNAMIC_CONFIGURATION == STD_ON)

/*! STATE: CheckConfigBlock */
NVM_LOCAL CONST(NvM_StateType, NVM_PRIVATE_DATA) NvM_ReadAllFsm_CheckConfigBlockState = {
  NVM_READALLFSM_CHECKCONFIGBLOCKSTATE_ENTRY, /* no ENTRY action required */
  NVM_READALLFSM_CHECKCONFIGBLOCKSTATE_DO
};

#endif

/*
 * Skip reading of valid data is only available for data integrity int buffer enabled configurations at the moment.
 * This is the case, because an internal buffer to hold payload and DataIntegrityRecord is always available.
 * at the moment. So the user does not care about data integrity data at all and skip reading can only be provided
 * if data integrity int buffer is enabled.
 */
#if (NVM_USE_DATA_INTEGRITY_INT_BUFFER == STD_ON)
/*! STATE: EvaluateNvReadSkip */
/* PRQA S 3218 1 */ /* MD_Fsm_StateDefinitionStaticUsedOnlyInSingleFunction */
NVM_LOCAL CONST(NvM_StateType, NVM_PRIVATE_DATA) NvM_ReadAllFsm_EvaluateNvReadSkipState = {
  NvM_ReadAllFsm_EvaluateNvReadSkipState_Entry,
  NvM_ReadAllFsm_EvaluateNvReadSkipState_Do
};
#endif /* NVM_USE_DATA_INTEGRITY_INT_BUFFER == STD_ON */

#if (NVM_JOB_PRIORITIZATION == STD_ON)
/*! STATE: WaitForReadAllReadyToResume */
/* PRQA S 3218 1 */ /* MD_Fsm_StateDefinitionStaticUsedOnlyInSingleFunction */
NVM_LOCAL CONST(NvM_StateType, NVM_PRIVATE_DATA) NvM_ReadAllFsm_WaitForReadAllReadyToResumeState = {
  NvM_FsmLib_EntryNoOp,
  NvM_ReadAllFsm_WaitForReadAllReadyToResumeState_Do
};
#endif /* NVM_JOB_PRIORITIZATION == STD_ON */

/*! STATE: ReadCurrentBlock */
/* PRQA S 3218 1 */ /* MD_Fsm_StateDefinitionStaticUsedOnlyInSingleFunction */
NVM_LOCAL CONST(NvM_StateType, NVM_PRIVATE_DATA) NvM_ReadAllFsm_ReadCurrentBlockState = {
  NvM_ReadAllFsm_ReadCurrentBlockState_Entry,
  NvM_ReadAllFsm_ReadCurrentBlockState_Do
};

#if (NVM_DYNAMIC_CONFIGURATION == STD_ON)
/*! STATE: RestoreBlockDefaults */
/* PRQA S 3218 1 */ /* MD_Fsm_StateDefinitionStaticUsedOnlyInSingleFunction */
NVM_LOCAL CONST(NvM_StateType, NVM_PRIVATE_DATA) NvM_ReadAllFsm_RestoreBlockDefaultsState = {
  NvM_FsmLib_EntryNoOp,
  NvM_ReadAllFsm_RestoreBlockDefaultsState_Do
};
#endif /* NVM_DYNAMIC_CONFIGURATION */

/*! FSM: ReadAll with ENTRY action and initial state */
/* PRQA S 3218 1 */ /* MD_Fsm_StateDefinitionStaticUsedOnlyInSingleFunction */
NVM_LOCAL CONST(NvM_FsmType, NVM_PRIVATE_DATA) NvM_ReadAllFsm_InitialState = {
  NvM_ReadAllFsm_Entry,
  {NVM_READALLFSM_FINDNEXTRELEVANTBLOCKSTATE_ENTRY, NVM_READALLFSM_FINDNEXTRELEVANTBLOCKSTATE_DO}
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
 *  NvM_ReadAllFsm_ProcessInitialTransition()
 *********************************************************************************************************************/
/*! \brief       Decide which initial transition is needed.
 *  \details     -
 *  \param[in]   partitionId      Partition ID.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, NVM_PRIVATE_CODE) NvM_ReadAllFsm_ProcessInitialTransition(const NvM_PartitionIdType partitionId);

#if (NVM_DYNAMIC_CONFIGURATION == STD_ON)
/**********************************************************************************************************************
 *  NvM_ReadAllFsm_UpdateConfigBlock()
 *********************************************************************************************************************/
/*! \brief       Updates the config block.
 *  \details     -
 *  \param[in]   configId         Current config Id pointer.
 *  \param[in]   errorStatus      Error status to be set.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, NVM_PRIVATE_CODE) NvM_ReadAllFsm_UpdateConfigBlock(const uint8 *configId,
  const NvM_RequestResultType errorStatus);

#if (NVM_JOB_PRIORITIZATION == STD_ON)
/**********************************************************************************************************************
 *  NvM_ReadAllFsm_ProcessResumeTransitionForDynamicConfigurationEnabled()
 *********************************************************************************************************************/
/*! \brief       Determines the appropriate state to transition to after resuming from an immediate job.
 *  \details     Only relevant in case dynamic configuration is enabled.
 *  \param[in]   partitionId      Partition ID.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, NVM_PRIVATE_CODE) NvM_ReadAllFsm_ProcessResumeTransitionForDynamicConfigurationEnabled(
  const NvM_PartitionIdType partitionId);
#endif /* NVM_JOB_PRIORITIZATION == STD_ON */
#endif /* NVM_DYNAMIC_CONFIGURATION == STD_ON */

/*
 * Skip reading of valid data is only available for data integrity int buffer enabled configurations at the moment.
 * This is the case, because an internal buffer to hold payload and DataIntegrityRecord is always available.
 * at the moment. So the user does not care about data integrity data at all and skip reading can only be provided
 * if data integrity int buffer is enabled.
 */
#if (NVM_USE_DATA_INTEGRITY_INT_BUFFER == STD_ON)
/**********************************************************************************************************************
 *  NvM_ReadAllFsm_IsBlockSelectedForSkipReadEvaluation()
 *********************************************************************************************************************/
/*! \brief       Check if the current block is selected for skip read evaluation
 *  \details     -
 *  \param[in]   blockDescriptor Current Block to be checked.
 *  \return      TRUE, if block can be evaluated, otherwise FALSE.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(boolean, NVM_PRIVATE_CODE) NvM_ReadAllFsm_IsBlockSelectedForSkipReadEvaluation(
  NvM_BlockDescriptorPtrType blockDescriptor);
#endif /* NVM_USE_DATA_INTEGRITY_INT_BUFFER == STD_ON */

/**********************************************************************************************************************
 *  NvM_ReadAllFsm_SelectRuntimePreparation()
 *********************************************************************************************************************/
/*! \brief       Proceed with normal or extended runtime preparation.
 *  \details     -
 *  \param[in]   fsmContext      Current FSM Context.
 *  \param[in]   fsmLibInstance  Processed FsmLib Instance.
 *  \return      TRUE, if block is relevant, otherwise FALSE.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, NVM_PRIVATE_CODE) NvM_ReadAllFsm_SelectRuntimePreparation(
  NvM_ReadAllFsm_ContextPtrType fsmContext,
  NvM_FsmLib_InstancePtrToConstType fsmLibInstance);

#if (NVM_DYNAMIC_CONFIGURATION == STD_ON)
/**********************************************************************************************************************
 *  NvM_ReadAllFsm_UpdateManagementDataForConfigBlock()
 *********************************************************************************************************************/
/*! \brief       Updates management data of config block
 *  \details     -
 *  \param[in]   partitionId Partition identifier.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, NVM_PRIVATE_CODE) NvM_ReadAllFsm_UpdateManagementDataForConfigBlock(const NvM_PartitionIdType partitionId);
#endif /* NVM_DYNAMIC_CONFIGURATION == STD_ON */

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

#if (NVM_DYNAMIC_CONFIGURATION == STD_ON)
/**********************************************************************************************************************
 *  NvM_ReadAllFsm_UpdateManagementDataForConfigBlock
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
FUNC(void, NVM_PRIVATE_CODE) NvM_ReadAllFsm_UpdateManagementDataForConfigBlock(const NvM_PartitionIdType partitionId)
{
  NvM_ReadAllFsm_ContextPtrType fsmContext = NvM_GetAddrReadAllFsm_Context(partitionId);
  NvM_FsmLib_InstancePtrToConstType singleBlockJobFsmLibInstance =
    (NvM_FsmLib_InstancePtrToConstType)NvM_GetAddrSingleBlockServiceFsmLib_Instance(partitionId);

  NvM_BlockDescriptorPtrType blockDescriptor = NvM_GetAddrBlockDescriptor(NVM_CONFIG_BLOCK_ID);
  NvM_ServiceJobResultType serviceJobResult = NvM_FsmLib_GetSubFsmResult(singleBlockJobFsmLibInstance);

  uint8 configId[NVM_CONFIG_BLOCK_PAYLOAD_LENGTH];

#if (NVM_USE_CONFIG_ID_CALLBACK == STD_ON)
    /* VCA Disable SLC-20 : VCA_NVM_CALL_EXTERNAL_FUNCTION_VAR_POINTER_ARGUMENT */
    NvM_InvokeConfigIdCallback(configId, NVM_CONFIG_BLOCK_PAYLOAD_LENGTH);
    /* VCA Enable : VCA_NVM_CALL_EXTERNAL_FUNCTION_VAR_POINTER_ARGUMENT */
#else
    uint16 compiledConfigId = (uint16)NVM_COMPILED_CONFIG_ID;
    VStdLib_MemCpy(configId, &compiledConfigId, NVM_CONFIG_BLOCK_PAYLOAD_LENGTH);                                        /* VCA_NVM_VStdLibMemCpyCalls */
#endif

  if(serviceJobResult == NVM_SERVICE_JOB_OK)
  {
    if(VStdLib_MemCmp(configId, blockDescriptor->RamBlockDataAddress, NVM_CONFIG_BLOCK_PAYLOAD_LENGTH) == 0)
    {
      blockDescriptor->BlockManagementInfo->ErrorStatus = NVM_REQ_OK;
      fsmContext->ConfigBlockMismatch = FALSE;
    }
    else
    {
      NvM_ReadAllFsm_UpdateConfigBlock(configId, NVM_REQ_NOT_OK);
      fsmContext->ConfigBlockMismatch = TRUE;
    }
  }
  /* MEMIF_BLOCK_INCONSISTENT and  MEMIF_BLOCK_INVALID are mapped to NVM_SERVICE_JOB_INVALIDATED */
  else if(serviceJobResult == NVM_SERVICE_JOB_INVALIDATED)
  {
    NvM_ReadAllFsm_UpdateConfigBlock(configId, NVM_REQ_NV_INVALIDATED);

    /* Defined in AUTOSAR spec R23-11 SWS_NvM_00673 in case of INCONSISTENT and INVALIDATED */
    fsmContext->ConfigBlockMismatch = FALSE;
  }
  /* Every other error */
  else
  {
    NvM_ReadAllFsm_UpdateConfigBlock(configId, NVM_REQ_INTEGRITY_FAILED);

    fsmContext->ConfigBlockMismatch = TRUE;

    /* Defined in AUTOSAR spec R23-11 SWS_NvM_00305 in case of INTEGRITY_FAILED */
    NvM_ErrorCheck_DispatchDemErrorConditionally(NVM_DEM_ERROR_TYPE_REQ_FAILED);
  }

  /*
   * The parameter partitionId is not used within this function in single partition use case.
   * To avoid compiler warnings the following dummy statement is added.
   */
  NVM_DUMMY_STATEMENT_CONST(partitionId);                                                                                     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
}
#endif /* NVM_DYNAMIC_CONFIGURATION == STD_ON */

/**********************************************************************************************************************
 *  NvM_ReadAllFsm_ProcessInitialTransition
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
FUNC(void, NVM_PRIVATE_CODE) NvM_ReadAllFsm_ProcessInitialTransition(const NvM_PartitionIdType partitionId)
{
  NvM_FsmLib_InstancePtrToConstType multiBlockJobFsmInstance =
    (NvM_FsmLib_InstancePtrToConstType)NvM_GetAddrMultiBlockServiceFsmLib_Instance(partitionId);

#if (NVM_DYNAMIC_CONFIGURATION == STD_ON)
# if (NVM_MULTIPARTITION_USAGE_SCENARIO == STD_ON)
  NvM_BlockDescriptorPtrType blockDescriptor = NvM_GetAddrBlockDescriptor(NVM_CONFIG_BLOCK_ID);
  if (blockDescriptor->PartitionId != partitionId)
  {
    NvM_FsmLib_TransitionToState(multiBlockJobFsmInstance, NvM_ReadAllFsm_FindNextRelevantBlockState);
  }
  else
# endif /* NVM_MULTIPARTITION_USAGE_SCENARIO */
  {
    NvM_FsmLib_TransitionToState(multiBlockJobFsmInstance, NvM_ReadAllFsm_CheckConfigBlockState);
  }
#else
  NvM_FsmLib_TransitionToState(multiBlockJobFsmInstance, NvM_ReadAllFsm_FindNextRelevantBlockState);
#endif /* NVM_DYNAMIC_CONFIGURATION */

  /*
   * The parameter partitionId is not used within this function in single partition use case.
   * To avoid compiler warnings the following dummy statement is added.
   */
  NVM_DUMMY_STATEMENT_CONST(partitionId);                                                                               /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
}

#if (NVM_DYNAMIC_CONFIGURATION == STD_ON)
/**********************************************************************************************************************
 *  NvM_ReadAllFsm_UpdateConfigBlock
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, NVM_PRIVATE_CODE) NvM_ReadAllFsm_UpdateConfigBlock(const uint8 *configId,
  const NvM_RequestResultType errorStatus)
{
  NvM_BlockDescriptorPtrType blockDescriptor = NvM_GetAddrBlockDescriptor(NVM_CONFIG_BLOCK_ID);

  VStdLib_MemCpy(blockDescriptor->RamBlockDataAddress, configId, NVM_CONFIG_BLOCK_PAYLOAD_LENGTH);                      /* VCA_NVM_VStdLibMemCpyCalls */

  blockDescriptor->BlockManagementInfo->RamBlockState = NVM_RAMBLOCKSTATE_VALID_CHANGED;
  blockDescriptor->BlockManagementInfo->ErrorStatus = errorStatus;
}

#if (NVM_JOB_PRIORITIZATION == STD_ON)
/**********************************************************************************************************************
 *  NvM_ReadAllFsm_ProcessResumeTransitionForDynamicConfigurationEnabled
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
FUNC(void, NVM_PRIVATE_CODE) NvM_ReadAllFsm_ProcessResumeTransitionForDynamicConfigurationEnabled(
  const NvM_PartitionIdType partitionId)
{
  NvM_FsmLib_InstancePtrToConstType multiBlockJobFsmInstance =
    (NvM_FsmLib_InstancePtrToConstType)NvM_GetAddrMultiBlockServiceFsmLib_Instance(partitionId);

  NvM_ReadAllFsm_ContextPtrToConstType fsmContext = NvM_GetAddrReadAllFsm_Context(partitionId);
  NvM_BlockDescriptorLookupTableIdType currentLookupTableId =
    fsmContext->MultiBlockContext.CurrentBlockDescriptorLookupTableId;

  if(currentLookupTableId == NVM_CONFIG_BLOCK_ID)
  {
#if (NVM_MULTIPARTITION_USAGE_SCENARIO == STD_ON)
    NvM_BlockDescriptorPtrType blockDescriptor = NvM_GetAddrBlockDescriptor(NVM_CONFIG_BLOCK_ID);
    if (blockDescriptor->PartitionId == partitionId)
    {
      NvM_FsmLib_TransitionToState(multiBlockJobFsmInstance, NvM_ReadAllFsm_CheckConfigBlockState);
    }
    else
    {
      NvM_FsmLib_TransitionToState(multiBlockJobFsmInstance, NvM_ReadAllFsm_FindNextRelevantBlockState);                /* COV_NVM_ImmediateInterruption_MultiPartition_ConfigBlockInOtherPartition */
    }
#else
    NvM_FsmLib_TransitionToState(multiBlockJobFsmInstance, NvM_ReadAllFsm_CheckConfigBlockState);
#endif /* NVM_MULTIPARTITION_USAGE_SCENARIO */
  }
  else
  {
    NvM_FsmLib_TransitionToState(multiBlockJobFsmInstance, NvM_ReadAllFsm_FindNextRelevantBlockState);
  }

  /*
   * The parameter partitionId is not used within this function in single partition use case.
   * To avoid compiler warnings the following dummy statement is added.
   */
  NVM_DUMMY_STATEMENT_CONST(partitionId);                                                                               /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
}
#endif /* NVM_JOB_PRIORITIZATION == STD_ON */
#endif /* NVM_DYNAMIC_CONFIGURATION == STD_ON */

/*
 * Skip reading of valid data is only available for data integrity int buffer enabled configurations at the moment.
 * This is the case, because an internal buffer to hold payload and DataIntegrityRecord is always available.
 * at the moment. So the user does not care about data integrity data at all and skip reading can only be provided
 * if data integrity int buffer is enabled.
 */
#if (NVM_USE_DATA_INTEGRITY_INT_BUFFER == STD_ON)
/**********************************************************************************************************************
 *  NvM_ReadAllFsm_IsBlockSelectedForSkipReadEvaluation
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
FUNC(boolean, NVM_PRIVATE_CODE) NvM_ReadAllFsm_IsBlockSelectedForSkipReadEvaluation(
  NvM_BlockDescriptorPtrType blockDescriptor)
{
  boolean isRelevantForSkipReadingEvaluation = (blockDescriptor->Flags.CalcRamBlockCrcEnabled == NVM_CALC_RAM_BLOCK_CRC_ON)
    && (blockDescriptor->Flags.BlockUseSetRamBlockStatusEnabled == NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON)
    && ((blockDescriptor->BlockManagementInfo->RamBlockState == NVM_RAMBLOCKSTATE_VALID_UNCHANGED)
    || (blockDescriptor->BlockManagementInfo->RamBlockState == NVM_RAMBLOCKSTATE_VALID_CHANGED));

  return isRelevantForSkipReadingEvaluation;
}
#endif /* NVM_USE_DATA_INTEGRITY_INT_BUFFER == STD_ON */

/**********************************************************************************************************************
 *  NvM_ReadAllFsm_SelectRuntimePreparation
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
FUNC(void, NVM_PRIVATE_CODE) NvM_ReadAllFsm_SelectRuntimePreparation(
  NvM_ReadAllFsm_ContextPtrType fsmContext,
  NvM_FsmLib_InstancePtrToConstType fsmLibInstance)
{
  NvM_BlockDescriptorPtrType blockDescriptor =
    NvM_GetAddrBlockDescriptor(fsmContext->MultiBlockContext.CurrentBlockDescriptorLookupTableId);

#if (NVM_DYNAMIC_CONFIGURATION == STD_ON)
  /* Mismatch flag is only detectable by master partition,
      Runtime assures that master partition is processed at start of ReadAll */
  if (NvM_GetAddrReadAllFsm_Context(NVM_PARTITION_ID_MASTER)->ConfigBlockMismatch
      && (blockDescriptor->Flags.ResistantToChangedSwEnabled == NVM_RESISTANT_TO_CHANGED_SW_OFF))
  {
    /* Extended Runtime Preparation */
    NvM_FsmLib_TransitionToState(fsmLibInstance, NvM_ReadAllFsm_RestoreBlockDefaultsState);
  }
  else
#endif /* NVM_DYNAMIC_CONFIGURATION */
  {
    /* Normal Runtime Preparation */
/*
 * Skip reading of valid data is only available for data integrity int buffer enabled configurations at the moment.
 * This is the case, because an internal buffer to hold payload and DataIntegrityRecord is always available.
 * at the moment. So the user does not care about data integrity data at all and skip reading can only be provided
 * if data integrity int buffer is enabled.
 */
#if (NVM_USE_DATA_INTEGRITY_INT_BUFFER == STD_ON)
    if (NvM_ReadAllFsm_IsBlockSelectedForSkipReadEvaluation(blockDescriptor))
    {
      NvM_FsmLib_TransitionToState(fsmLibInstance, NvM_ReadAllFsm_EvaluateNvReadSkipState);
    }
    else
#endif /* NVM_USE_DATA_INTEGRITY_INT_BUFFER == STD_ON */
    {
      NvM_FsmLib_TransitionToState(fsmLibInstance, NvM_ReadAllFsm_ReadCurrentBlockState);
    }
  }

  /*
   * The parameter blockDescriptor is not used within this function if dynamic configuration is disabled
   * and data integrity int buffer is disabled.
   * To avoid compiler warnings the following dummy statement is added.
   */
  NVM_DUMMY_STATEMENT_CONST(blockDescriptor);                                                                               /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
}

/**********************************************************************************************************************
 * NvM_ReadAllFsm_Entry()
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
FUNC(void, NVM_PRIVATE_CODE) NvM_ReadAllFsm_Entry(NvM_PartitionIdType partitionId)                                      /* PRQA S 3206 */ /* MD_NvM_CslMacroNotUsingPartitionId */
{
  NvM_BlockDescriptorPtrType blockDescriptor = (NvM_BlockDescriptorPtrType)NULL_PTR;

  NvM_ReadAllFsm_ContextPtrType fsmContext = NvM_GetAddrReadAllFsm_Context(partitionId);
  const NvM_BlockDescriptorLookupTableIdType blockCount = NvM_GetSizeOfBlockDescriptor();

  fsmContext->MultiBlockContext.CurrentBlockDescriptorLookupTableId = NVM_FIRST_INTERNAL_BLOCK_ID;

  for (NvM_BlockDescriptorLookupTableIdType i = NVM_FIRST_INTERNAL_BLOCK_ID; i < blockCount; i++)
  {
    blockDescriptor = NvM_GetAddrBlockDescriptor(i);

    if(blockDescriptor->Flags.SelectBlockForReadAllEnabled == NVM_SELECT_BLOCK_FOR_READALL_ON)
    {
#if (NVM_MULTIPARTITION_USAGE_SCENARIO == STD_ON)
      if (blockDescriptor->PartitionId == partitionId)
#endif /* NVM_MULTIPARTITION_USAGE_SCENARIO */
      {
        blockDescriptor->BlockManagementInfo->ErrorStatus = NVM_REQ_PENDING;
      }
    }
  }

  /*
   * The parameter partitionId is not used within this function in single partition use case.
   * To avoid compiler warnings the following dummy statement is added.
   */
  NVM_DUMMY_STATEMENT(partitionId);                                                                                     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  NvM_ReadAllFsm_ProcessInitialTransition(partitionId);
}

#if (NVM_DYNAMIC_CONFIGURATION == STD_ON)

/*!
 * STATE: CheckConfigBlock
 */

/**********************************************************************************************************************
 * NvM_ReadAllFsm_CheckConfigBlockState_Entry()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, NVM_PRIVATE_CODE) NvM_ReadAllFsm_CheckConfigBlockState_Entry(NvM_PartitionIdType partitionId)
{
  NvM_SingleBlockJobContextPtrType singleBlockJobContext = NvM_GetAddrSingleBlockJobContext(partitionId);
  NvM_BlockDescriptorPtrType blockDescriptor = NvM_GetAddrBlockDescriptor(NVM_CONFIG_BLOCK_ID);

  /* Setup block id for sub FSM */
  singleBlockJobContext->BlockDescriptorLookupTableId = NVM_CONFIG_BLOCK_ID;
  singleBlockJobContext->BlockId = blockDescriptor->NvramBlockIdentifier;

  NvM_SingleBlockJobFsm_Spawn(partitionId);

  /*
   * The parameter partitionId is not used within this function in single partition use case.
   * To avoid compiler warnings the following dummy statement is added.
   */
  NVM_DUMMY_STATEMENT(partitionId);                                                                                     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
}

/**********************************************************************************************************************
 * NvM_ReadAllFsm_CheckConfigBlockBlockState_Do()
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
/* VCA Next Line SPC-24 : VCA_NVM_ReadAllFsm_CurrentBlockDescriptorLookupTableId */
FUNC(NvM_FsmLib_ProcessingResultType, NVM_PRIVATE_CODE) NvM_ReadAllFsm_CheckConfigBlockState_Do(
  NvM_PartitionIdType partitionId)                                                                                      /* PRQA S 3206 */ /* MD_NvM_CslMacroNotUsingPartitionId */
{
  NVM_DUMMY_STATEMENT(partitionId); /* Unused in single partition use case */                                           /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  NvM_FsmLib_ProcessingResultType retVal = NVM_FSMLIB_PROCESSINGRESULT_STOP;
  NvM_FsmLib_InstancePtrToConstType multiBlockJobFsmInstance =
    (NvM_FsmLib_InstancePtrToConstType)NvM_GetAddrMultiBlockServiceFsmLib_Instance(partitionId);

  NvM_FsmLib_InstancePtrToConstType singleBlockJobFsmLibInstance =
    (NvM_FsmLib_InstancePtrToConstType)NvM_GetAddrSingleBlockServiceFsmLib_Instance(partitionId);
  NvM_ReadAllFsm_ContextPtrType fsmContext = NvM_GetAddrReadAllFsm_Context(partitionId);

  NvM_FsmLib_ProcessCurrentActiveFsm(singleBlockJobFsmLibInstance);

  /* In case the processing stack of the single block job stack is empty,
    the single block job was successfully finished and hence
    it can be continued with the next individual block job. */
  if (NvM_FsmLib_IsProcessingStackEmpty(singleBlockJobFsmLibInstance) == TRUE)
  {
    NvM_ReadAllFsm_UpdateManagementDataForConfigBlock(partitionId);

    fsmContext->MultiBlockContext.CurrentBlockDescriptorLookupTableId++;

    NvM_FsmLib_TransitionToState(multiBlockJobFsmInstance, NvM_ReadAllFsm_FindNextRelevantBlockState);
    retVal = NVM_FSMLIB_PROCESSINGRESULT_CONTINUE;
  }

  return retVal;
}

#endif

/*!
 * STATE: FindNextRelevantBlock
 */

/**********************************************************************************************************************
 * NvM_ReadAllFsm_FindNextRelevantBlockState_Do()
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
/* VCA Next Line SPC-24 : VCA_NVM_ReadAllFsm_CurrentBlockDescriptorLookupTableId */
FUNC(NvM_FsmLib_ProcessingResultType, NVM_PRIVATE_CODE) NvM_ReadAllFsm_FindNextRelevantBlockState_Do(
  NvM_PartitionIdType partitionId)                                                                                      /* PRQA S 3206 */ /* MD_NvM_CslMacroNotUsingPartitionId */
{
  NvM_FsmLib_ProcessingResultType retVal = NVM_FSMLIB_PROCESSINGRESULT_CONTINUE;

  NvM_FsmLib_InstancePtrType multiBlockJobFsmInstance =
    (NvM_FsmLib_InstancePtrType)NvM_GetAddrMultiBlockServiceFsmLib_Instance(partitionId);
  NvM_ReadAllFsm_ContextPtrType fsmContext = NvM_GetAddrReadAllFsm_Context(partitionId);

  if(fsmContext->MultiBlockContext.CurrentBlockDescriptorLookupTableId >= NvM_GetSizeOfBlockDescriptor())
  {
    NvM_ServiceJobResultType serviceJobResult = NVM_SERVICE_JOB_OK;

    if(fsmContext->MultiBlockContext.HasAnyJobIterationFailed)
    {
      serviceJobResult = NVM_SERVICE_JOB_NOT_OK;
    }

    NvM_FsmLib_FinalizeCurrentActiveFsm(multiBlockJobFsmInstance, serviceJobResult);
  }
  else
  {
    NvM_BlockDescriptorPtrType currentBlockDescriptor =
      NvM_GetAddrBlockDescriptor(fsmContext->MultiBlockContext.CurrentBlockDescriptorLookupTableId);

#if (NVM_MULTIPARTITION_USAGE_SCENARIO == STD_ON)
    if (currentBlockDescriptor->PartitionId == partitionId)
#endif /* NVM_MULTIPARTITION_USAGE_SCENARIO */
    {
      if(currentBlockDescriptor->Flags.SelectBlockForReadAllEnabled == NVM_SELECT_BLOCK_FOR_READALL_ON)
      {
        NvM_ReadAllFsm_SelectRuntimePreparation(fsmContext, multiBlockJobFsmInstance);
      }
      else
      {
        fsmContext->MultiBlockContext.CurrentBlockDescriptorLookupTableId++;

        currentBlockDescriptor->BlockManagementInfo->ErrorStatus = NVM_REQ_BLOCK_SKIPPED;
      }
    }
#if (NVM_MULTIPARTITION_USAGE_SCENARIO == STD_ON)
    else
    {
      fsmContext->MultiBlockContext.CurrentBlockDescriptorLookupTableId++;
    }
#endif /* NVM_MULTIPARTITION_USAGE_SCENARIO */
  }

  /*
   * The parameter partitionId is not used within this function in single partition use case.
   * To avoid compiler warnings the following dummy statement is added.
   */
  NVM_DUMMY_STATEMENT(partitionId);                                                                                     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  return retVal;
}

/*
 * Skip reading of valid data is only available for data integrity int buffer enabled configurations at the moment.
 * This is the case, because an internal buffer to hold payload and DataIntegrityRecord is always available.
 * at the moment. So the user does not care about data integrity data at all and skip reading can only be provided
 * if data integrity int buffer is enabled.
 */
#if (NVM_USE_DATA_INTEGRITY_INT_BUFFER == STD_ON)

/*!
 * STATE: EvaluateNvReadSkipState
 */

/**********************************************************************************************************************
 * NvM_ReadAllFsm_EvaluateNvReadSkipStateState_Entry()
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
FUNC(void, NVM_PRIVATE_CODE) NvM_ReadAllFsm_EvaluateNvReadSkipState_Entry(NvM_PartitionIdType partitionId)
{
  NvM_ReadAllFsm_ContextPtrToConstType fsmContext = NvM_GetAddrReadAllFsm_Context(partitionId);
  NvM_SingleBlockJobContextPtrType singleBlockJobContext = NvM_GetAddrSingleBlockJobContext(partitionId);
  NvM_BlockDescriptorPtrType blockDescriptor =
   NvM_GetAddrBlockDescriptor(fsmContext->MultiBlockContext.CurrentBlockDescriptorLookupTableId);

  if(NvM_DataSync_RequestData(fsmContext->MultiBlockContext.CurrentBlockDescriptorLookupTableId,
                              singleBlockJobContext->DataBuffer,
                              NULL_PTR) == E_OK)
  {
    /* NULL_PTR check not necessary because if configured every block with CRC contains a valid buffer */
    NvM_DataPtrType storedDataIntegrityRecordBuffer = blockDescriptor->DataIntegrityIntBuffer;

    /* Setup block id for sub FSM */
    singleBlockJobContext->BlockDescriptorLookupTableId =
      fsmContext->MultiBlockContext.CurrentBlockDescriptorLookupTableId;
    singleBlockJobContext->BlockId = blockDescriptor->NvramBlockIdentifier;

    NvM_DataIntegrityJobContextType dataIntegrityJobContext = {
      NVM_DATAINTEGRITYSERVICE_JOB_VERIFY,
      singleBlockJobContext->DataBuffer,
      storedDataIntegrityRecordBuffer,
      singleBlockJobContext->BlockId,
      singleBlockJobContext->BlockDescriptorLookupTableId,
      singleBlockJobContext->DataIndex,
      partitionId
    };

    NvM_DataIntegrityFsm_Process(&dataIntegrityJobContext);
  }
  else
  {
    NvM_FsmLib_InstancePtrToConstType multiBlockJobFsmInstance =
      (NvM_FsmLib_InstancePtrToConstType)NvM_GetAddrMultiBlockServiceFsmLib_Instance(partitionId);

    NvM_FsmLib_TransitionToState(multiBlockJobFsmInstance, NvM_ReadAllFsm_ReadCurrentBlockState);
  }
}

/**********************************************************************************************************************
 * NvM_ReadAllFsm_EvaluateNvReadSkipState_Do()
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
/* VCA Next Line SPC-24 : VCA_NVM_ReadAllFsm_CurrentBlockDescriptorLookupTableId */
FUNC(NvM_FsmLib_ProcessingResultType, NVM_PRIVATE_CODE) NvM_ReadAllFsm_EvaluateNvReadSkipState_Do(
  NvM_PartitionIdType partitionId)
{
  NvM_FsmLib_ProcessingResultType retVal = NVM_FSMLIB_PROCESSINGRESULT_STOP;
  NvM_FsmLib_InstancePtrToConstType multiBlockJobFsmInstance =
    (NvM_FsmLib_InstancePtrToConstType)NvM_GetAddrMultiBlockServiceFsmLib_Instance(partitionId);

  NvM_FsmLib_InstancePtrToConstType singleBlockJobFsmLibInstance =
    (NvM_FsmLib_InstancePtrToConstType)NvM_GetAddrSingleBlockServiceFsmLib_Instance(partitionId);
  NvM_ReadAllFsm_ContextPtrType fsmContext = NvM_GetAddrReadAllFsm_Context(partitionId);
  NvM_BlockDescriptorPtrType blockDescriptor =
    NvM_GetAddrBlockDescriptor(fsmContext->MultiBlockContext.CurrentBlockDescriptorLookupTableId);

  NvM_FsmLib_ProcessCurrentActiveFsm(singleBlockJobFsmLibInstance);

  /* In case the processing stack of the single block job stack is empty,
    the evaluation of the skipping is finished and hence
    it can be continued with either reading the current block (in case of a data integrity mismatch)
    or finding the next relevant one. */
  if (NvM_FsmLib_IsProcessingStackEmpty(singleBlockJobFsmLibInstance) == TRUE)
  {
    /* Poll and map result */
    NvM_ServiceJobResultType result = NvM_FsmLib_GetSubFsmResult(singleBlockJobFsmLibInstance);

    if (result == NVM_SERVICE_JOB_OK)
    {
      NvM_SingleBlockJobContextPtrType singleBlockJobContext = NvM_GetAddrSingleBlockJobContext(partitionId);
      blockDescriptor->BlockManagementInfo->ErrorStatus = NVM_REQ_OK;

      NvM_Notification_ProcessSingleBlockCallback(singleBlockJobContext, partitionId);

      fsmContext->MultiBlockContext.CurrentBlockDescriptorLookupTableId++;

      NvM_FsmLib_TransitionToState(multiBlockJobFsmInstance, NvM_ReadAllFsm_FindNextRelevantBlockState);
    }
    else
    {
      NvM_FsmLib_TransitionToState(multiBlockJobFsmInstance, NvM_ReadAllFsm_ReadCurrentBlockState);
    }

    retVal = NVM_FSMLIB_PROCESSINGRESULT_CONTINUE;
  }

  return retVal;
}

#endif /* NVM_USE_DATA_INTEGRITY_INT_BUFFER == STD_ON */

#if (NVM_JOB_PRIORITIZATION == STD_ON)

/*!
 * STATE: WaitForReadAllReadyToResume
 */
/**********************************************************************************************************************
 * NvM_ReadAllFsm_WaitForReadAllReadyToResumeState_Do()
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
FUNC(NvM_FsmLib_ProcessingResultType, NVM_PRIVATE_CODE) NvM_ReadAllFsm_WaitForReadAllReadyToResumeState_Do(
  NvM_PartitionIdType partitionId)
{
  NVM_DUMMY_STATEMENT(partitionId); /* Unused in single partition use case */                                           /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  NvM_SingleBlockJobContextPtrType singleBlockJobContext = NvM_GetAddrSingleBlockJobContext(partitionId);

  /* Setup single block job context to ensure correct resuming after immediate interruption */
  singleBlockJobContext->DataBuffer = NvM_GetAddrInternalBuffer(0u, partitionId);
  singleBlockJobContext->TemporaryRamBlockAddr = NULL_PTR;
  singleBlockJobContext->SingleBlockJobType = NVM_SINGLEBLOCKJOBTYPE_READ_ALL_BLOCK;
  singleBlockJobContext->DataIndex = 0u; /* Default value since dataset blocks are not relevant for ReadAll */

#if (NVM_DYNAMIC_CONFIGURATION == STD_ON)
  NvM_ReadAllFsm_ProcessResumeTransitionForDynamicConfigurationEnabled(partitionId);
#else
  NvM_FsmLib_InstancePtrToConstType multiBlockJobFsmInstance =
    (NvM_FsmLib_InstancePtrToConstType)NvM_GetAddrMultiBlockServiceFsmLib_Instance(partitionId);

  NvM_FsmLib_TransitionToState(multiBlockJobFsmInstance, NvM_ReadAllFsm_FindNextRelevantBlockState);
#endif /* NVM_DYNAMIC_CONFIGURATION */

  return NVM_FSMLIB_PROCESSINGRESULT_CONTINUE;
}
#endif /* NVM_JOB_PRIORITIZATION == STD_ON */

/*!
 * STATE: ReadCurrentBlock
 */

/**********************************************************************************************************************
 * NvM_ReadAllFsm_ReadCurrentBlockState_Entry()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, NVM_PRIVATE_CODE) NvM_ReadAllFsm_ReadCurrentBlockState_Entry(NvM_PartitionIdType partitionId)
{
  NvM_ReadAllFsm_ContextPtrToConstType fsmContext = NvM_GetAddrReadAllFsm_Context(partitionId);
  NvM_SingleBlockJobContextPtrType singleBlockJobContext = NvM_GetAddrSingleBlockJobContext(partitionId);
  NvM_BlockDescriptorPtrType blockDescriptor =
   NvM_GetAddrBlockDescriptor(fsmContext->MultiBlockContext.CurrentBlockDescriptorLookupTableId);

  /* Setup block id for sub FSM */
  singleBlockJobContext->BlockDescriptorLookupTableId =
    fsmContext->MultiBlockContext.CurrentBlockDescriptorLookupTableId;
  singleBlockJobContext->BlockId = blockDescriptor->NvramBlockIdentifier;

  /* Spawn SingleBlockJobFsm */
  NvM_SingleBlockJobFsm_Spawn(partitionId);

  /*
   * The parameter partitionId is not used within this function in single partition use case.
   * To avoid compiler warnings the following dummy statement is added.
   */
  NVM_DUMMY_STATEMENT(partitionId);                                                                                     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
}

/**********************************************************************************************************************
 * NvM_ReadAllFsm_ReadCurrentBlockState_Do()
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
/* VCA Next Line SPC-24 : VCA_NVM_ReadAllFsm_CurrentBlockDescriptorLookupTableId */
FUNC(NvM_FsmLib_ProcessingResultType, NVM_PRIVATE_CODE) NvM_ReadAllFsm_ReadCurrentBlockState_Do(
  NvM_PartitionIdType partitionId)                                                                                      /* PRQA S 3206 */ /* MD_NvM_CslMacroNotUsingPartitionId */
{
  NvM_FsmLib_ProcessingResultType retVal = NVM_FSMLIB_PROCESSINGRESULT_STOP;
  NvM_FsmLib_InstancePtrToConstType multiBlockJobFsmInstance =
    (NvM_FsmLib_InstancePtrToConstType)NvM_GetAddrMultiBlockServiceFsmLib_Instance(partitionId);

  NvM_FsmLib_InstancePtrToConstType singleBlockJobFsmLibInstance =
    (NvM_FsmLib_InstancePtrToConstType)NvM_GetAddrSingleBlockServiceFsmLib_Instance(partitionId);

  NvM_ReadAllFsm_ContextPtrType fsmContext = NvM_GetAddrReadAllFsm_Context(partitionId);
  NvM_SingleBlockJobContextPtrType singleBlockJobContext = NvM_GetAddrSingleBlockJobContext(partitionId);
  NvM_BlockDescriptorPtrType blockDescriptor =
   NvM_GetAddrBlockDescriptor(fsmContext->MultiBlockContext.CurrentBlockDescriptorLookupTableId);

  NvM_FsmLib_ProcessCurrentActiveFsm(singleBlockJobFsmLibInstance);

  /* In case the processing stack of the single block job stack is empty,
    the config block was successfully finished and hence
    it can be continued with the next individual block job. */
  if (NvM_FsmLib_IsProcessingStackEmpty(singleBlockJobFsmLibInstance) == TRUE)
  {
    NvM_ServiceJobResultType serviceJobResult = NvM_FsmLib_GetSubFsmResult(singleBlockJobFsmLibInstance);
    blockDescriptor->BlockManagementInfo->ErrorStatus =
      NvM_GlobalUtilityLib_ConvertServiceJobResultToNvMRequestResult(serviceJobResult);

    NvM_Notification_ProcessSingleBlockCallback(singleBlockJobContext, partitionId);

    if(blockDescriptor->BlockManagementInfo->ErrorStatus != NVM_REQ_OK)
    {
      fsmContext->MultiBlockContext.HasAnyJobIterationFailed = TRUE;
    }

    fsmContext->MultiBlockContext.CurrentBlockDescriptorLookupTableId++;

    NvM_FsmLib_TransitionToState(multiBlockJobFsmInstance, NvM_ReadAllFsm_FindNextRelevantBlockState);

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
 * STATE: RestoreBlockDefaults
 */

/**********************************************************************************************************************
 * NvM_ReadAllFsm_RestoreBlockDefaultsState_Do()
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
/* VCA Next Line SPC-24 : VCA_NVM_ReadAllFsm_CurrentBlockDescriptorLookupTableId */
FUNC(NvM_FsmLib_ProcessingResultType, NVM_PRIVATE_CODE) NvM_ReadAllFsm_RestoreBlockDefaultsState_Do(
  NvM_PartitionIdType partitionId)                                                                                      /* PRQA S 3206 */ /* MD_NvM_CslMacroNotUsingPartitionId */
{
  NvM_FsmLib_InstancePtrToConstType multiBlockJobFsmInstance =
    (NvM_FsmLib_InstancePtrToConstType)NvM_GetAddrMultiBlockServiceFsmLib_Instance(partitionId);
  NvM_ReadAllFsm_ContextPtrType fsmContext = NvM_GetAddrReadAllFsm_Context(partitionId);
  NvM_SingleBlockJobContextPtrToConstType singleBlockJobContext = NvM_GetAddrSingleBlockJobContext(partitionId);
  NvM_BlockDescriptorPtrType blockDescriptor =
   NvM_GetAddrBlockDescriptor(fsmContext->MultiBlockContext.CurrentBlockDescriptorLookupTableId);

  /* TemporaryRamBlockAddr can be a NULL_PTR */
  if (NvM_DataSync_RestoreDefaultData(fsmContext->MultiBlockContext.CurrentBlockDescriptorLookupTableId,
        singleBlockJobContext->SingleBlockJobType,
        singleBlockJobContext->TemporaryRamBlockAddr) == E_OK)
  {
    blockDescriptor->BlockManagementInfo->ErrorStatus = NVM_REQ_RESTORED_DEFAULTS;
  }
  else
  {
    blockDescriptor->BlockManagementInfo->ErrorStatus = NVM_REQ_INTEGRITY_FAILED;
  }

  /* Always Reset CrcCompMechanismBuffer in extended runtime to enable subsequent WriteBlock operations */
  NvM_GlobalUtilityLib_ResetCrcCompMechanismBuffer(blockDescriptor->CrcCompMechanismBuffer,
    blockDescriptor->DataIntegritySettings);

  NvM_Notification_ProcessSingleBlockCallback(singleBlockJobContext, partitionId);

  fsmContext->MultiBlockContext.CurrentBlockDescriptorLookupTableId++;

  NvM_FsmLib_TransitionToState(multiBlockJobFsmInstance, NvM_ReadAllFsm_FindNextRelevantBlockState);

  /*
   * The parameter partitionId is not used within this function in single partition use case.
   * To avoid compiler warnings the following dummy statement is added.
   */
  NVM_DUMMY_STATEMENT(partitionId);                                                                                     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  return NVM_FSMLIB_PROCESSINGRESULT_CONTINUE;
}
#endif /* NVM_DYNAMIC_CONFIGURATION */

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * NvM_ReadAllFsm_ReadAll()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, NVM_PRIVATE_CODE) NvM_ReadAllFsm_ReadAll(NvM_PartitionIdType partitionId)                                    /* PRQA S 3206 */ /* MD_NvM_CslMacroNotUsingPartitionId */
{
  NvM_FsmLib_InstancePtrType multiBlockJobFsmInstance =
    (NvM_FsmLib_InstancePtrType)NvM_GetAddrMultiBlockServiceFsmLib_Instance(partitionId);
  NvM_ReadAllFsm_ContextPtrType fsmContext = NvM_GetAddrReadAllFsm_Context(partitionId);
  NvM_SingleBlockJobContextPtrType singleBlockJobContext = NvM_GetAddrSingleBlockJobContext(partitionId);

  /* Setup single block job context */
  singleBlockJobContext->SingleBlockJobType = NVM_SINGLEBLOCKJOBTYPE_READ_ALL_BLOCK;
  singleBlockJobContext->DataBuffer = NvM_GetAddrInternalBuffer(0u, partitionId);
  singleBlockJobContext->TemporaryRamBlockAddr = NULL_PTR;
  singleBlockJobContext->DataIndex = 0u; /* Default value since dataset blocks are not relevant for ReadAll */

  fsmContext->MultiBlockContext.HasAnyJobIterationFailed = FALSE;
  fsmContext->ConfigBlockMismatch = FALSE;

  /* COM-4978: Wait for CSL feature to store init value of generated partition data */
  NvM_ReadAllFsm_InstancePtrType fsmInstance = NvM_GetAddrReadAllFsm_Instance(partitionId);
  *fsmInstance = NvM_ReadAllFsm_InitialState;

  (void)NvM_FsmLib_SpawnFsm(multiBlockJobFsmInstance, *fsmInstance);

  /*
   * The parameter partitionId is not used within this function in single partition use case.
   * To avoid compiler warnings the following dummy statement is added.
   */
  NVM_DUMMY_STATEMENT(partitionId);                                                                                     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
}

/**********************************************************************************************************************
 * NvM_ReadAllFsm_GetCurrentProcessedBlockDescriptorLookupTableId()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(NvM_BlockDescriptorLookupTableIdType, NVM_PRIVATE_CODE)
  NvM_ReadAllFsm_GetCurrentProcessedBlockDescriptorLookupTableId(NvM_PartitionIdType partitionId)                       /* PRQA S 3206 */ /* MD_NvM_CslMacroNotUsingPartitionId */
{
  NvM_ReadAllFsm_ContextPtrToConstType fsmContext = NvM_GetAddrReadAllFsm_Context(partitionId);

  /*
   * The parameter partitionId is not used within this function in single partition use case.
   * To avoid compiler warnings the following dummy statement is added.
   */
  NVM_DUMMY_STATEMENT(partitionId);                                                                                     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  return fsmContext->MultiBlockContext.CurrentBlockDescriptorLookupTableId;
}

#if (NVM_JOB_PRIORITIZATION == STD_ON)
/**********************************************************************************************************************
 * NvM_ReadAllFsm_NotifyImmediateJobInterrupt()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, NVM_PRIVATE_CODE) NvM_ReadAllFsm_NotifyImmediateJobInterrupt(const NvM_PartitionIdType partitionId)
{
  NVM_DUMMY_STATEMENT_CONST(partitionId); /* Unused in single partition use case */                                     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  NvM_FsmLib_InstancePtrType multiBlockJobFsmInstance =
    (NvM_FsmLib_InstancePtrType)NvM_GetAddrMultiBlockServiceFsmLib_Instance(partitionId);

  NvM_FsmLib_TransitionToState(multiBlockJobFsmInstance, NvM_ReadAllFsm_WaitForReadAllReadyToResumeState);
}
#endif /* NVM_JOB_PRIORITIZATION == STD_ON */

#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  VCA JUSTIFICATIONS
 **********************************************************************************************************************/
/* VCA_JUSTIFICATION_BEGIN

\ID VCA_NVM_CALL_EXTERNAL_FUNCTION_VAR_POINTER_ARGUMENT
\DESCRIPTION A function with pointer parameters is directly called, but the function is not
             defined within the analyzed sources. VCA is unable to determine the
             behavior of the function.
\COUNTERMEASURE \N Arguments that contain var pointer are checked by review: Pointer type corresponds to function
                   parameter type.

\ID VCA_NVM_ReadAllFsm_CurrentBlockDescriptorLookupTableId
  \DESCRIPTION The CurrentBlockDescriptorLookupTableId is incremented at the end of a block processing step, before
               entering the FindNextRelevantBlock state again. This can lead to a potential
               out of range CurrentBlockDescriptorLookupTableId before entering the FindNextRelevantBlock state,
               but at the beginning of this state, a check limits the CurrentBlockDescriptorLookupTableId.
               The CurrentBlockDescriptorLookupTableId is just used in its valid range
               when it is used to access any data.
               This is a conscious decision in regards of an better usage of the FSM idea.

  \COUNTERMEASURE \N A code review ensures that the CurrentBlockDescriptorLookupTableId is always in range when used.

VCA_JUSTIFICATION_END */

/* COV_JUSTIFICATION_BEGIN

Code coverage:

\ID COV_NVM_ImmediateInterruption_MultiPartition_ConfigBlockInOtherPartition
  \ACCEPT  XX
  \REASON  Uncovered function call is reported.
            In case a ReadAll is interrupted by an immediate block job, the ReadAll is resumed after the
            immediate job is finished. In case the config block was interrupted, it will be the first
            block for reprocessing the ReadAll. If dynamic configuration and multi partition usage scenario are enabled,
            a check is implemented verifying that the config block belongs indeed to the correct partition.
            Nevertheless, it is not possible to cover this scenario on component level, because the partition Id check
            will pass as it was the interrupted block. Otherwise, the interruption would have affected another block,
            because the config block would have been skipped.
            The implementation was chosen to ensure a defensive behavior.
  \LEVEL   Component

COV_JUSTIFICATION_END */
/**********************************************************************************************************************
 *  END OF FILE: NvM_ReadAllFsm.c
 *********************************************************************************************************************/
