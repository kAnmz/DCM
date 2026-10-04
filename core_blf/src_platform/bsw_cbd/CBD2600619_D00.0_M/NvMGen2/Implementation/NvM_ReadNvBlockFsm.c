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
/*!        \file  NvM_ReadNvBlockFsm.c
 *        \brief  NvM_ReadNvBlockFsm source file
 *      \details  Implementation of the NvM_ReadNvBlockFsm unit.
 *         \unit  NvM_ReadNvBlockFsm
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#define NVM_READNVBLOCKFSM_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "NvM_ReadNvBlockFsm.h"
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
 * NvM_ReadNvBlockFsm_Entry()
 *********************************************************************************************************************/
/*!  \brief       ENTRY action of ReadNvBlockFsm
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
FUNC(void, NVM_PRIVATE_CODE) NvM_ReadNvBlockFsm_Entry(NvM_PartitionIdType partitionId);

/**********************************************************************************************************************
 * NvM_ReadNvBlockFsm_ReadNvBlockState_Entry()
 *********************************************************************************************************************/
/*!  \brief       ENTRY action of ReadNvBlockFsm state ReadNvBlock
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
FUNC(void, NVM_PRIVATE_CODE) NvM_ReadNvBlockFsm_ReadNvBlockState_Entry(NvM_PartitionIdType partitionId);

/**********************************************************************************************************************
 * NvM_ReadNvBlockFsm_ReadNvBlockState_Do()
 *********************************************************************************************************************/
/*!  \brief       DO action of ReadNvBlockFsm state ReadNvBlock
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
FUNC(NvM_FsmLib_ProcessingResultType, NVM_PRIVATE_CODE) NvM_ReadNvBlockFsm_ReadNvBlockState_Do(
  NvM_PartitionIdType partitionId);

/**********************************************************************************************************************
 * NvM_ReadNvBlockFsm_ReadRedundantNvBlockState_Entry()
 *********************************************************************************************************************/
/*!  \brief       ENTRY action of ReadNvBlockFsm state ReadRedundantNvBlock
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
FUNC(void, NVM_PRIVATE_CODE) NvM_ReadNvBlockFsm_ReadRedundantNvBlockState_Entry(NvM_PartitionIdType partitionId);

/**********************************************************************************************************************
 * NvM_ReadNvBlockFsm_ReadRedundantNvBlockState_Do()
 *********************************************************************************************************************/
/*!  \brief       DO action of ReadNvBlockFsm state ReadRedundantNvBlock
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
FUNC(NvM_FsmLib_ProcessingResultType, NVM_PRIVATE_CODE) NvM_ReadNvBlockFsm_ReadRedundantNvBlockState_Do(
  NvM_PartitionIdType partitionId);

/***********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

/**********************************************************************************************************************
 * NvM_ReadNvBlockFsm_ExecuteNvRead()
 *********************************************************************************************************************/
/*! \brief           Executes the MemIf_Read() with the correct length information
 *  \details         Includes optional DataIntegrityRecord length.
 *  \param[in]       partitionId    Partition ID
 *  \param[in]       blockNumber    Block number for lower layer
 *  \pre             -
 *  \context         TASK
 *  \reentrant       FALSE
 *  \synchronous     TRUE
 *  \return          MemIf result
 *  \spec
 *      requires partitionId == NVM_PARTITION_ID_MASTER;
 *  \endspec
 *********************************************************************************************************************/
NVM_LOCAL FUNC(Std_ReturnType, NVM_PRIVATE_CODE) NvM_ReadNvBlockFsm_ExecuteNvRead(
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
 * Initializing a const structure (NvM_ReadNvBlockFsm) can only be done with compile-time constants.
 * Therefore this defines are introduced to minimize code duplication within NvM_ReadNvBlockFsm and
 * NvM_ReadNvBlockFsm_ReadNvBlockState initialization.
 */
#define NVM_READNVBLOCKFSM_READNVBLOCKSTATE_ENTRY NvM_ReadNvBlockFsm_ReadNvBlockState_Entry
#define NVM_READNVBLOCKFSM_READNVBLOCKSTATE_DO NvM_ReadNvBlockFsm_ReadNvBlockState_Do

/*! STATE: ReadNvBlock */

/* PRQA S 3218 1 */ /* MD_ReadNvBlockFsm_ReadRedundantNvBlockStateUsedOnlyInSingleFunction */
NVM_LOCAL CONST(NvM_StateType, NVM_PRIVATE_DATA) NvM_ReadNvBlockFsm_ReadNvBlockState = {
  NVM_READNVBLOCKFSM_READNVBLOCKSTATE_ENTRY,
  NVM_READNVBLOCKFSM_READNVBLOCKSTATE_DO
};

/*! STATE: ReadRedundantNvBlock */

/* PRQA S 3218 1 */ /* MD_ReadNvBlockFsm_ReadRedundantNvBlockStateUsedOnlyInSingleFunction */
NVM_LOCAL CONST(NvM_StateType, NVM_PRIVATE_DATA) NvM_ReadNvBlockFsm_ReadRedundantNvBlockState = {
  NvM_ReadNvBlockFsm_ReadRedundantNvBlockState_Entry,
  NvM_ReadNvBlockFsm_ReadRedundantNvBlockState_Do
};

/*! FSM: ReadNvBlock with ENTRY action and initial state */
/* PRQA S 3218 1 */ /* MD_Fsm_StateDefinitionStaticUsedOnlyInSingleFunction */
NVM_LOCAL CONST(NvM_FsmType, NVM_PRIVATE_DATA) NvM_ReadNvBlockFsm = {
  NvM_ReadNvBlockFsm_Entry,
  {NVM_READNVBLOCKFSM_READNVBLOCKSTATE_ENTRY, NVM_READNVBLOCKFSM_READNVBLOCKSTATE_DO}
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
 * NvM_ReadNvBlockFsm_Entry()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, NVM_PRIVATE_CODE) NvM_ReadNvBlockFsm_Entry(
  NvM_PartitionIdType partitionId)
{
  NvM_FsmLib_InstancePtrToConstType fsmLibInstance =
    (NvM_FsmLib_InstancePtrToConstType)NvM_GetAddrNvServiceFsmLib_Instance(partitionId);

  NvM_FsmLib_TransitionToState(fsmLibInstance, NvM_ReadNvBlockFsm_ReadNvBlockState);

  /*
   * The parameter partitionId is not used within this function in single partition use case.
   * To avoid compiler warnings the following dummy statement is added.
   */
  NVM_DUMMY_STATEMENT(partitionId);                                                                                     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
}

/**********************************************************************************************************************
 * NvM_ReadNvBlockFsm_ReadNvBlockState_Entry()
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
FUNC(void, NVM_PRIVATE_CODE) NvM_ReadNvBlockFsm_ReadNvBlockState_Entry(NvM_PartitionIdType partitionId)
{
  NvM_FsmLib_InstancePtrType fsmLibInstance =
    (NvM_FsmLib_InstancePtrType)NvM_GetAddrNvServiceFsmLib_Instance(partitionId);
  const NvM_NvJobContextPtrType nvJobContext = NvM_GetAddrNvJobContext(partitionId);
  NvM_BlockDescriptorPtrType blockDescriptor = NvM_GetAddrBlockDescriptor(nvJobContext->BlockDescriptorLookupTableId);

  if (NvM_ReadNvBlockFsm_ExecuteNvRead(partitionId, nvJobContext->BlockNumber) != E_OK)
  {
    if (blockDescriptor->BlockManagementType == NVM_BLOCK_MANAGEMENT_TYPE_REDUNDANT)
    {
      NvM_FsmLib_TransitionToState(fsmLibInstance, NvM_ReadNvBlockFsm_ReadRedundantNvBlockState);
    }
    else
    {
      NvM_ErrorCheck_DispatchDemErrorConditionally(NVM_DEM_ERROR_TYPE_REQ_FAILED);
      NvM_FsmLib_FinalizeCurrentActiveFsm(fsmLibInstance, NVM_SERVICE_JOB_NOT_OK);
    }
  }
}

/**********************************************************************************************************************
 * NvM_ReadNvBlockFsm_ReadNvBlockState_Do()
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
FUNC(NvM_FsmLib_ProcessingResultType, NVM_PRIVATE_CODE) NvM_ReadNvBlockFsm_ReadNvBlockState_Do(
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
    if (blockDescriptor->BlockManagementType != NVM_BLOCK_MANAGEMENT_TYPE_REDUNDANT)
    {
      /* DEM error dispatching */
      NvM_DemErrorIdType demError = NVM_DEM_ERROR_TYPE_NO_ERROR;

      switch (jobResult)
      {
        case MEMIF_JOB_FAILED:
          demError = NVM_DEM_ERROR_TYPE_REQ_FAILED;
          break;
        case MEMIF_BLOCK_INCONSISTENT:
          demError = NVM_DEM_ERROR_TYPE_INTEGRITY_FAILED;
          break;

        default:
        /*
        * MISRA case. Do nothing.
        * This default case is empty due to the fact that only the queried memif types
        * can lead to a corresponding dem error.
        * The dem error id type NVM_DEM_ERROR_TYPE_LOSS_OF_REDUNDANCY
        * can only be correctly dispatched when reading the redundant block
        */
          break;
      }

      NvM_ErrorCheck_DispatchDemErrorConditionally(demError);
    }

    if ((jobResult != MEMIF_JOB_OK) &&
        (blockDescriptor->BlockManagementType == NVM_BLOCK_MANAGEMENT_TYPE_REDUNDANT))
    {
      NvM_FsmLib_TransitionToState(fsmLibInstance, NvM_ReadNvBlockFsm_ReadRedundantNvBlockState);
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
 * NvM_ReadNvBlockFsm_ReadRedundantNvBlockState_Entry()
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
FUNC(void, NVM_PRIVATE_CODE) NvM_ReadNvBlockFsm_ReadRedundantNvBlockState_Entry(NvM_PartitionIdType partitionId)
{
  NvM_FsmLib_InstancePtrType fsmLibInstance =
    (NvM_FsmLib_InstancePtrType)NvM_GetAddrNvServiceFsmLib_Instance(partitionId);
  const NvM_NvJobContextPtrType nvJobContext = NvM_GetAddrNvJobContext(partitionId);

  const uint16 redundantBlockNumber = nvJobContext->BlockNumber + 1u;

  if (NvM_ReadNvBlockFsm_ExecuteNvRead(partitionId, redundantBlockNumber) != E_OK)
  {
    NvM_ErrorCheck_DispatchDemErrorConditionally(NVM_DEM_ERROR_TYPE_REQ_FAILED);

    NvM_FsmLib_FinalizeCurrentActiveFsm(fsmLibInstance, NVM_SERVICE_JOB_NOT_OK);
  }
}

/**********************************************************************************************************************
 * NvM_ReadNvBlockFsm_ReadRedundantNvBlockState_Do()
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
FUNC(NvM_FsmLib_ProcessingResultType, NVM_PRIVATE_CODE) NvM_ReadNvBlockFsm_ReadRedundantNvBlockState_Do(
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
    NvM_DemErrorIdType demError = NVM_DEM_ERROR_TYPE_NO_ERROR;

    switch (jobResult)
    {
      case MEMIF_JOB_OK:
        /*
         * Redundant block will only be attempted to be read when primary dataset has failed.
         * Indicate the loss of redundancy to the DEM as the secondary data set could be read.
         */
        demError = NVM_DEM_ERROR_TYPE_LOSS_OF_REDUNDANCY;
        break;
      case MEMIF_JOB_FAILED:
        demError = NVM_DEM_ERROR_TYPE_REQ_FAILED;
        break;
      case MEMIF_BLOCK_INCONSISTENT:
        demError = NVM_DEM_ERROR_TYPE_INTEGRITY_FAILED;
        break;

      default:
        /*
         * MISRA case. Do nothing.
         * This default case is empty due to the fact that only the queried memif types
         * can lead to a corresponding dem error.
         */
        break;
    }

    NvM_ErrorCheck_DispatchDemErrorConditionally(demError);

    NvM_ServiceJobResultType serviceJobResult = NvM_GlobalUtilityLib_ConvertMemIfResultToServiceJobResult(jobResult);

    NvM_FsmLib_FinalizeCurrentActiveFsm(fsmLibInstance, serviceJobResult);

    retVal = NVM_FSMLIB_PROCESSINGRESULT_CONTINUE;
  }

  return retVal;
}

/**********************************************************************************************************************
 * NvM_ReadNvBlockFsm_ExecuteNvRead()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
NVM_LOCAL FUNC(Std_ReturnType, NVM_PRIVATE_CODE) NvM_ReadNvBlockFsm_ExecuteNvRead(
  const NvM_PartitionIdType partitionId,
  const uint16 blockNumber)
{
  /* CSL optimization in single partition use case */
  NVM_DUMMY_STATEMENT_CONST(partitionId);                                                                               /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  const uint16 blockOffset = 0u;

  const NvM_NvJobContextPtrType nvJobContext = NvM_GetAddrNvJobContext(partitionId);
  NvM_BlockDescriptorPtrToConstType blockDescriptor = NvM_GetAddrBlockDescriptor(nvJobContext->BlockDescriptorLookupTableId);

  const uint16 nvDataLength = NvM_GlobalUtilityLib_GetNvDataLength(blockDescriptor);

  return MemIf_Read((uint8)blockDescriptor->MemIfDeviceIndex,                                                           /* VCA_NVM_MemIfRead */
                    blockNumber,
                    blockOffset,
                    nvJobContext->DataBuffer,
                    nvDataLength);
}

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * NvM_ReadNvBlockFsm_ReadBlock()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, NVM_PRIVATE_CODE) NvM_ReadNvBlockFsm_ReadBlock(NvM_PartitionIdType partitionId)
{
  NvM_FsmLib_InstancePtrType fsmLibInstance =
    (NvM_FsmLib_InstancePtrType)NvM_GetAddrNvServiceFsmLib_Instance(partitionId);

  (void)NvM_FsmLib_SpawnFsm(fsmLibInstance, NvM_ReadNvBlockFsm);

  /*
   * The parameter partitionId is not used within this function in single partition use case.
   * To avoid compiler warnings the following dummy statement is added.
   */
  NVM_DUMMY_STATEMENT(partitionId);                                                                                     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
}

#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  MISRA JUSTIFICATIONS
 **********************************************************************************************************************/

/* Justification for module-specific MISRA deviations:

MD_ReadNvBlockFsm_ReadRedundantNvBlockStateUsedOnlyInSingleFunction: rule 8.9
  Reason:     There is only one transition in the FSM to ReadRedundantNvBlockState.
              Therefore the state is only used in a single function where the transition is done.
  Risk:       None.
  Prevention: A code review shall ensure that there is no side effect.

*/

/***********************************************************************************************************************
 *  VCA JUSTIFICATIONS
 **********************************************************************************************************************/
/* VCA_JUSTIFICATION_BEGIN

\ID VCA_NVM_MemIfRead
   \DESCRIPTION A function with pointer parameters is directly called, but the function is not
                defined within the analyzed sources. VCA is unable to determine the
                behavior of the function.

   \COUNTERMEASURE \N Arguments that contain var pointer are checked by review:
                      Pointer type corresponds to function parameter type

VCA_JUSTIFICATION_END */

/**********************************************************************************************************************
 *  END OF FILE: NvM_ReadNvBlockFsm.c
 *********************************************************************************************************************/
