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
/*!        \file  NvM_ResetNvBlockFsm.c
 *        \brief  NvM_ResetNvBlockFsm source file
 *      \details  Implementation of the NvM_ResetNvBlockFsm unit.
 *         \unit  NvM_ResetNvBlockFsm
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#define NVM_RESETNVBLOCKFSM_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "NvM_ResetNvBlockFsm.h"
#include "NvM_FsmLib.h"
#include "MemIf.h"
#include "NvM_Cfg.h"
#include "NvM_GlobalUtilityLib.h"
#include "NvM_ErrorCheck.h"

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

/***********************************************************************************************************************
 *  FUNCTION PROTOTYPES
 **********************************************************************************************************************/
#define NVM_START_SEC_CODE
#include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/***********************************************************************************************************************
 *  FSM FUNCTION PROTOTYPES
 **********************************************************************************************************************/

/**********************************************************************************************************************
 * NvM_ResetNvBlockFsm_Entry()
 *********************************************************************************************************************/
/*!  \brief       ENTRY action of ResetNvBlockFsm
 *   \details     -
 *   \param[in]   partitionId Partition ID.
 *   \pre         -
 *   \context     TASK
 *   \reentrant   FALSE
 *   \synchronous TRUE
 *   \spec
 *      requires partitionId == NVM_PARTITION_ID_MASTER;
 *   \endspec
 *********************************************************************************************************************/
FUNC(void, NVM_PRIVATE_CODE) NvM_ResetNvBlockFsm_Entry(NvM_PartitionIdType partitionId);

/**********************************************************************************************************************
 * NvM_ResetNvBlockFsm_ResetNvBlockState_Entry()
 *********************************************************************************************************************/
/*!  \brief       ENTRY action of ResetNvBlockFsm state ResetNvBlock
 *   \details     -
 *   \param[in]   partitionId Partition ID.
 *   \pre         -
 *   \context     TASK
 *   \reentrant   FALSE
 *   \synchronous TRUE
 *   \spec
 *      requires partitionId == NVM_PARTITION_ID_MASTER;
 *   \endspec
 *********************************************************************************************************************/
FUNC(void, NVM_PRIVATE_CODE) NvM_ResetNvBlockFsm_ResetNvBlockState_Entry(NvM_PartitionIdType partitionId);

/**********************************************************************************************************************
 * NvM_ResetNvBlockFsm_ResetNvBlockState_Do()
 *********************************************************************************************************************/
/*!  \brief       DO action of ResetNvBlockFsm state ResetNvBlock
 *   \details     -
 *   \param[in]   partitionId Partition ID.
 *   \return      Based on state evaluation:
 *                 - STOP       if no further processing is required
 *                 - CONTINUE   if further processing shall be executed
 *   \pre         -
 *   \context     TASK
 *   \reentrant   FALSE
 *   \synchronous TRUE
 *   \spec
 *      requires partitionId == NVM_PARTITION_ID_MASTER;
 *   \endspec
 *********************************************************************************************************************/
FUNC(NvM_FsmLib_ProcessingResultType, NVM_PRIVATE_CODE) NvM_ResetNvBlockFsm_ResetNvBlockState_Do(
  NvM_PartitionIdType partitionId);

/**********************************************************************************************************************
 * NvM_ResetNvBlockFsm_ResetRedundantNvBlockState_Entry()
 *********************************************************************************************************************/
/*!  \brief       ENTRY action of ResetNvBlockFsm state ResetRedundantNvBlock
 *   \details     -
 *   \param[in]   partitionId Partition ID.
 *   \pre         -
 *   \context     TASK
 *   \reentrant   FALSE
 *   \synchronous TRUE
 *   \spec
 *      requires partitionId == NVM_PARTITION_ID_MASTER;
 *   \endspec
 *********************************************************************************************************************/
FUNC(void, NVM_PRIVATE_CODE) NvM_ResetNvBlockFsm_ResetRedundantNvBlockState_Entry(NvM_PartitionIdType partitionId);

/**********************************************************************************************************************
 * NvM_ResetNvBlockFsm_EsetRedundantNvBlockState_Do()
 *********************************************************************************************************************/
/*!  \brief       DO action of ResetNvBlockFsm state ResetRedundantNvBlock
 *   \details     -
 *   \param[in]   partitionId Partition ID.
 *   \return      Based on state evaluation:
 *                 - STOP       if no further processing is required
 *                 - CONTINUE   if further processing shall be executed
 *   \pre         -
 *   \context     TASK
 *   \reentrant   FALSE
 *   \synchronous TRUE
 *   \spec
 *      requires partitionId == NVM_PARTITION_ID_MASTER;
 *   \endspec
 *********************************************************************************************************************/
FUNC(NvM_FsmLib_ProcessingResultType, NVM_PRIVATE_CODE) NvM_ResetNvBlockFsm_ResetRedundantNvBlockState_Do(
  NvM_PartitionIdType partitionId);

/***********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

/**********************************************************************************************************************
 * NvM_ResetNvBlockFsm_ExecuteNvReset()
 *********************************************************************************************************************/
/*! \brief           Executes the correct memif function depending on the reset job.
 *  \details         -
 *  \param[in]       partitionId    Partition ID
 *  \param[in]       blockNumber    Block number for lower layer
 *  \pre             -
 *  \context         TASK
 *  \reentrant       FALSE
 *  \synchronous     TRUE
 *  \return          MemIf result
 *   \spec
 *      requires partitionId == NVM_PARTITION_ID_MASTER;
 *   \endspec
 *********************************************************************************************************************/
NVM_LOCAL FUNC(Std_ReturnType, NVM_PRIVATE_CODE) NvM_ResetNvBlockFsm_ExecuteNvReset(
  const NvM_PartitionIdType partitionId,
  const uint16 blockNumber);

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
 * Initializing a const structure (NvM_ResetNvBlockFsm) can only be done with compile-time constants.
 * Therefore this defines are introduced to minimize code duplication within NvM_ResetNvBlockFsm and
 * NvM_ResetNvBlockFsm_ResetNvBlockState initialization.
 */
#define NVM_RESETNVBLOCKFSM_RESETNVBLOCKSTATE_ENTRY NvM_ResetNvBlockFsm_ResetNvBlockState_Entry
#define NVM_RESETNVBLOCKFSM_RESETNVBLOCKSTATE_DO NvM_ResetNvBlockFsm_ResetNvBlockState_Do

/*! STATE: ResetNvBlock */

/* PRQA S 3218 1 */ /* MD_Fsm_StateDefinitionStaticUsedOnlyInSingleFunction */
NVM_LOCAL CONST(NvM_StateType, NVM_PRIVATE_DATA) NvM_ResetNvBlockFsm_ResetNvBlockState = {
  NVM_RESETNVBLOCKFSM_RESETNVBLOCKSTATE_ENTRY,
  NVM_RESETNVBLOCKFSM_RESETNVBLOCKSTATE_DO
};

/*! STATE: ResetRedundantNvBlock */

/* PRQA S 3218 1 */ /* MD_Fsm_StateDefinitionStaticUsedOnlyInSingleFunction */
NVM_LOCAL CONST(NvM_StateType, NVM_PRIVATE_DATA) NvM_ResetNvBlockFsm_ResetRedundantNvBlockState = {
  NvM_ResetNvBlockFsm_ResetRedundantNvBlockState_Entry,
  NvM_ResetNvBlockFsm_ResetRedundantNvBlockState_Do
};

/*! FSM: ResetNvBlock with ENTRY action and initial state */
/* PRQA S 3218 1 */ /* MD_Fsm_StateDefinitionStaticUsedOnlyInSingleFunction */
NVM_LOCAL CONST(NvM_FsmType, NVM_PRIVATE_DATA) NvM_ResetNvBlockFsm = {
  NvM_ResetNvBlockFsm_Entry,
  {
    NVM_RESETNVBLOCKFSM_RESETNVBLOCKSTATE_ENTRY,
    NVM_RESETNVBLOCKFSM_RESETNVBLOCKSTATE_DO
  }
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
 * NvM_ResetNvBlockFsm_Entry()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, NVM_PRIVATE_CODE) NvM_ResetNvBlockFsm_Entry(
  NvM_PartitionIdType partitionId)
{
  NvM_FsmLib_InstancePtrToConstType fsmLibInstance =
    (NvM_FsmLib_InstancePtrToConstType)NvM_GetAddrNvServiceFsmLib_Instance(partitionId);

  NvM_FsmLib_TransitionToState(fsmLibInstance, NvM_ResetNvBlockFsm_ResetNvBlockState);

  /*
   * The parameter partitionId is not used within this function in single partition use case.
   * To avoid compiler warnings the following dummy statement is added.
   */
  NVM_DUMMY_STATEMENT(partitionId);                                                                                     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
}

/**********************************************************************************************************************
 * NvM_ResetNvBlockFsm_ResetNvBlockState_Entry()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, NVM_PRIVATE_CODE) NvM_ResetNvBlockFsm_ResetNvBlockState_Entry(NvM_PartitionIdType partitionId)
{
  NvM_FsmLib_InstancePtrType fsmLibInstance =
    (NvM_FsmLib_InstancePtrType)NvM_GetAddrNvServiceFsmLib_Instance(partitionId);
  const NvM_NvJobContextPtrType nvJobContext = NvM_GetAddrNvJobContext(partitionId);

  if (NvM_ResetNvBlockFsm_ExecuteNvReset(partitionId, nvJobContext->BlockNumber) != E_OK)
  {
    NvM_ErrorCheck_DispatchDemErrorConditionally(NVM_DEM_ERROR_TYPE_REQ_FAILED);

    NvM_FsmLib_FinalizeCurrentActiveFsm(fsmLibInstance, NVM_SERVICE_JOB_NOT_OK);
  }
}

/**********************************************************************************************************************
 * NvM_ResetNvBlockFsm_ResetNvBlockState_Do()
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
FUNC(NvM_FsmLib_ProcessingResultType, NVM_PRIVATE_CODE) NvM_ResetNvBlockFsm_ResetNvBlockState_Do(
  NvM_PartitionIdType partitionId)
{
  /*
   * The parameter partitionId is not used within this function in single partition use case.
   * To avoid compiler warnings the following dummy statement is added.
   */
  NVM_DUMMY_STATEMENT(partitionId);                                                                                     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  NvM_FsmLib_ProcessingResultType retVal = NVM_FSMLIB_PROCESSINGRESULT_STOP;

  NvM_FsmLib_InstancePtrType fsmLibInstance =
    (NvM_FsmLib_InstancePtrType)NvM_GetAddrNvServiceFsmLib_Instance(partitionId);
  const NvM_NvJobContextPtrType nvJobContext = NvM_GetAddrNvJobContext(partitionId);                                    /* PRQA S 2983 */ /* MD_NvM_QACReportsFalsePositive2983 */
  NvM_BlockDescriptorPtrType blockDescriptor = NvM_GetAddrBlockDescriptor(nvJobContext->BlockDescriptorLookupTableId);

  /* Poll and map result */
  MemIf_JobResultType jobResult = MemIf_GetJobResult((uint8)blockDescriptor->MemIfDeviceIndex);

  if (jobResult == MEMIF_JOB_PENDING)
  {
    retVal = NVM_FSMLIB_PROCESSINGRESULT_STOP;
  }
  else
  {
    if(jobResult == MEMIF_JOB_FAILED)
    {
      NvM_ErrorCheck_DispatchDemErrorConditionally(NVM_DEM_ERROR_TYPE_REQ_FAILED);
    }

    if ((jobResult == MEMIF_JOB_OK) &&
        (blockDescriptor->BlockManagementType == NVM_BLOCK_MANAGEMENT_TYPE_REDUNDANT))
    {
      NvM_FsmLib_TransitionToState(fsmLibInstance, NvM_ResetNvBlockFsm_ResetRedundantNvBlockState);
    }
    else
    {
      NvM_ServiceJobResultType serviceJobResult = NvM_GlobalUtilityLib_ConvertMemIfResultToServiceJobResult(jobResult);

      NvM_FsmLib_FinalizeCurrentActiveFsm(fsmLibInstance, serviceJobResult);
    }
    retVal = NVM_FSMLIB_PROCESSINGRESULT_CONTINUE;
  }

  return retVal;
}

/**********************************************************************************************************************
 * NvM_ResetNvBlockFsm_ResetRedundantNvBlockState_Entry()
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
FUNC(void, NVM_PRIVATE_CODE) NvM_ResetNvBlockFsm_ResetRedundantNvBlockState_Entry(NvM_PartitionIdType partitionId)
{
  NvM_FsmLib_InstancePtrType fsmLibInstance =
    (NvM_FsmLib_InstancePtrType)NvM_GetAddrNvServiceFsmLib_Instance(partitionId);
  const NvM_NvJobContextPtrType nvJobContext = NvM_GetAddrNvJobContext(partitionId);

  const uint16 redundantBlockNumber = nvJobContext->BlockNumber + 1u;

  if (NvM_ResetNvBlockFsm_ExecuteNvReset(partitionId, redundantBlockNumber) != E_OK)
  {
    NvM_ErrorCheck_DispatchDemErrorConditionally(NVM_DEM_ERROR_TYPE_REQ_FAILED);

    NvM_FsmLib_FinalizeCurrentActiveFsm(fsmLibInstance, NVM_SERVICE_JOB_NOT_OK);
  }
}

/**********************************************************************************************************************
 * NvM_ResetNvBlockFsm_ResetRedundantNvBlockState_Do()
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
FUNC(NvM_FsmLib_ProcessingResultType, NVM_PRIVATE_CODE) NvM_ResetNvBlockFsm_ResetRedundantNvBlockState_Do(
  NvM_PartitionIdType partitionId)
{
  /*
   * The parameter partitionId is not used within this function in single partition use case.
   * To avoid compiler warnings the following dummy statement is added.
   */
  NVM_DUMMY_STATEMENT(partitionId);                                                                                     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  NvM_FsmLib_ProcessingResultType retVal = NVM_FSMLIB_PROCESSINGRESULT_STOP;

  NvM_FsmLib_InstancePtrType fsmLibInstance =
    (NvM_FsmLib_InstancePtrType)NvM_GetAddrNvServiceFsmLib_Instance(partitionId);
  const NvM_NvJobContextPtrType nvJobContext = NvM_GetAddrNvJobContext(partitionId);                                    /* PRQA S 2983 */ /* MD_NvM_QACReportsFalsePositive2983 */
  NvM_BlockDescriptorPtrType blockDescriptor = NvM_GetAddrBlockDescriptor(nvJobContext->BlockDescriptorLookupTableId);

  MemIf_JobResultType jobResult = MemIf_GetJobResult((uint8)blockDescriptor->MemIfDeviceIndex);

  if (jobResult == MEMIF_JOB_PENDING)
  {
    retVal = NVM_FSMLIB_PROCESSINGRESULT_STOP;
  }
  else
  {
    if(jobResult == MEMIF_JOB_FAILED)
    {
      NvM_ErrorCheck_DispatchDemErrorConditionally(NVM_DEM_ERROR_TYPE_REQ_FAILED);
    }

    NvM_ServiceJobResultType serviceJobResult = NvM_GlobalUtilityLib_ConvertMemIfResultToServiceJobResult(jobResult);

    NvM_FsmLib_FinalizeCurrentActiveFsm(fsmLibInstance, serviceJobResult);

    retVal = NVM_FSMLIB_PROCESSINGRESULT_CONTINUE;
  }

  return retVal;
}

/**********************************************************************************************************************
 * NvM_ResetNvBlockFsm_ExecuteNvReset()
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
NVM_LOCAL FUNC(Std_ReturnType, NVM_PRIVATE_CODE) NvM_ResetNvBlockFsm_ExecuteNvReset(
  const NvM_PartitionIdType partitionId,
  const uint16 blockNumber)
{
  /* CSL optimization in single partition use case */
  NVM_DUMMY_STATEMENT_CONST(partitionId);                                                                               /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  const NvM_NvJobContextPtrType nvJobContext = NvM_GetAddrNvJobContext(partitionId);
  NvM_BlockDescriptorPtrToConstType blockDescriptor = NvM_GetAddrBlockDescriptor(nvJobContext->BlockDescriptorLookupTableId);

  Std_ReturnType returnValue = E_NOT_OK;

  if(nvJobContext->SingleBlockJobType == NVM_SINGLEBLOCKJOBTYPE_INVALIDATE_NV_BLOCK)
  {
    returnValue = MemIf_InvalidateBlock((uint8)blockDescriptor->MemIfDeviceIndex,
      blockNumber);
  }
  else
  {
    returnValue = MemIf_EraseImmediateBlock((uint8)blockDescriptor->MemIfDeviceIndex,
      blockNumber);
  }

  return returnValue;
}

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * NvM_ResetNvBlockFsm_ResetBlock()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, NVM_PRIVATE_CODE) NvM_ResetNvBlockFsm_ResetBlock(NvM_PartitionIdType partitionId)
{
  NvM_FsmLib_InstancePtrType fsmLibInstance =
    (NvM_FsmLib_InstancePtrType)NvM_GetAddrNvServiceFsmLib_Instance(partitionId);

  (void)NvM_FsmLib_SpawnFsm(fsmLibInstance, NvM_ResetNvBlockFsm);

  /*
   * The parameter partitionId is not used within this function in single partition use case.
   * To avoid compiler warnings the following dummy statement is added.
   */
  NVM_DUMMY_STATEMENT(partitionId);                                                                                     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
}

#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: NvM_ResetNvBlockFsm.c
 *********************************************************************************************************************/
