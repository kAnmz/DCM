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
/*!        \file  NvM_NvJobFsm.c
 *        \brief  NvM_NvJobFsm source file
 *      \details  Implementation of the NvJobFsm unit.
 *         \unit  NvM_NvJobFsm
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#define NVM_NVJOBFSM_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "NvM_NvJobFsm.h"
#include "NvM_FsmLib.h"
#include "NvM_CfgDefines.h"
#include "NvM_NvJobDispatcherFsm.h"

#if (NVM_MULTIPARTITION_USAGE_SCENARIO == STD_ON)
  #include "NvM_SatelliteCom.h"
#endif

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
 * NvM_NvJobFsm_Entry()
 *********************************************************************************************************************/
/*!  \brief       ENTRY action of NvJobFsm
 *   \details     -
 *   \param[in]   partitionId Partition ID.
 *   \pre         -
 *   \context     TASK
 *   \reentrant   FALSE
 *   \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, NVM_PRIVATE_CODE) NvM_NvJobFsm_Entry(NvM_PartitionIdType partitionId);

/**********************************************************************************************************************
 * NvM_NvJobFsm_WaitForFinishedNvJobState_Entry()
 *********************************************************************************************************************/
/*!  \brief       ENTRY action of NvJobFsm state WaitForFinishedNvJob
 *   \details     -
 *   \param[in]   partitionId Partition ID.
 *   \pre         -
 *   \context     TASK
 *   \reentrant   FALSE
 *   \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, NVM_PRIVATE_CODE) NvM_NvJobFsm_WaitForFinishedNvJobState_Entry(NvM_PartitionIdType partitionId);

/**********************************************************************************************************************
 * NvM_NvJobFsm_WaitForFinishedNvJobState_Do()
 *********************************************************************************************************************/
/*!  \brief       DO action of NvJobFsm state WaitForFinishedNvJob
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
FUNC(NvM_FsmLib_ProcessingResultType, NVM_PRIVATE_CODE) NvM_NvJobFsm_WaitForFinishedNvJobState_Do(
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
 * Initializing a const structure (NvM_NvJobFsm_InitialState) can only be done with compile-time constants.
 * Therefore this defines are introduced to minimize code duplication within NvM_NvJobFsm_InitialState and
 * NvM_NvJobFsm_WaitForFinishedJobState initialization.
 */
#define NVM_NVJOBFSM_WAITFORFINISHEDJOBSTATE_ENTRY NvM_NvJobFsm_WaitForFinishedNvJobState_Entry
#define NVM_NVJOBFSM_WAITFORFINISHEDJOBSTATE_DO NvM_NvJobFsm_WaitForFinishedNvJobState_Do

/*! STATE: WaitForFinishedJob */
/* PRQA S 3218 1 */ /* MD_Fsm_StateDefinitionStaticUsedOnlyInSingleFunction */
NVM_LOCAL CONST(NvM_StateType, NVM_PRIVATE_DATA) NvM_NvJobFsm_WaitForFinishedJobState = {
  NVM_NVJOBFSM_WAITFORFINISHEDJOBSTATE_ENTRY,
  NVM_NVJOBFSM_WAITFORFINISHEDJOBSTATE_DO
};

/*! FSM: NvJob with ENTRY action and initial state */
/* PRQA S 3218 1 */ /* MD_Fsm_StateDefinitionStaticUsedOnlyInSingleFunction */
NVM_LOCAL CONST(NvM_FsmType, NVM_PRIVATE_DATA) NvM_NvJobFsm_InitialState = {
  NvM_NvJobFsm_Entry,
  {NVM_NVJOBFSM_WAITFORFINISHEDJOBSTATE_ENTRY, NVM_NVJOBFSM_WAITFORFINISHEDJOBSTATE_DO}
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
 * NvM_NvJobFsm_Spawn()
 *********************************************************************************************************************/
/*! \brief       Prepare job context and spawn NvJobFsm.
 *  \details     -
 *  \param[in]   partitionId  Partition ID.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, NVM_PRIVATE_CODE) NvM_NvJobFsm_Spawn(NvM_PartitionIdType partitionId);

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * NvM_NvJobFsm_Spawn()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, NVM_PRIVATE_CODE) NvM_NvJobFsm_Spawn(NvM_PartitionIdType partitionId)                                        /* PRQA S 3206 */ /* MD_NvM_CslMacroNotUsingPartitionId */
{
  NvM_FsmLib_InstancePtrType fsmLibInstance =
    (NvM_FsmLib_InstancePtrType)NvM_GetAddrSingleBlockServiceFsmLib_Instance(partitionId);

  /* COM-4978: Wait for CSL feature to store init value of generated partion data */
  NvM_NvJobFsm_InstancePtrType fsmInstance = NvM_GetAddrNvJobFsm_Instance(partitionId);
  *fsmInstance = NvM_NvJobFsm_InitialState;

  (void)NvM_FsmLib_SpawnFsm(fsmLibInstance, *fsmInstance);

  /*
   * The parameter partitionId is not used within this function in single partition use case.
   * To avoid compiler warnings the following dummy statement is added.
   */
  NVM_DUMMY_STATEMENT(partitionId);                                                                                     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
}

/**********************************************************************************************************************
 * NvM_NvJobFsm_Entry()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, NVM_PRIVATE_CODE) NvM_NvJobFsm_Entry(NvM_PartitionIdType partitionId)                                        /* PRQA S 3206 */ /* MD_NvM_CslMacroNotUsingPartitionId */
{
  NvM_FsmLib_InstancePtrToConstType fsmLibInstance =
    (NvM_FsmLib_InstancePtrToConstType)NvM_GetAddrSingleBlockServiceFsmLib_Instance(partitionId);

  NvM_FsmLib_TransitionToState(fsmLibInstance, NvM_NvJobFsm_WaitForFinishedJobState);

  /*
   * The parameter partitionId is not used within this function in single partition use case.
   * To avoid compiler warnings the following dummy statement is added.
   */
  NVM_DUMMY_STATEMENT(partitionId);                                                                                     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
}

/*!
 * STATE: WaitForFinishedJob
 */

/**********************************************************************************************************************
 * NvM_NvJobFsm_WaitForFinishedNvJobState_Entry()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, NVM_PRIVATE_CODE) NvM_NvJobFsm_WaitForFinishedNvJobState_Entry(NvM_PartitionIdType partitionId)
{
  NvM_SingleBlockJobContextPtrToConstType singleBlockJobContext = NvM_GetAddrSingleBlockJobContext(partitionId);

#if (NVM_MULTIPARTITION_USAGE_SCENARIO == STD_ON)
  /* Request job via SatelliteCom */
  NvM_SatelliteCom_RequestSingleBlockJob(singleBlockJobContext, partitionId);
#else
  /* Spawn NvJobDispatcher service FSM */
  NvM_NvJobDispatcherFsm_Execute(singleBlockJobContext, partitionId);
#endif
}

/**********************************************************************************************************************
 * NvM_NvJobFsm_WaitForFinishedNvJobState_Do()
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
FUNC(NvM_FsmLib_ProcessingResultType, NVM_PRIVATE_CODE) NvM_NvJobFsm_WaitForFinishedNvJobState_Do(
  NvM_PartitionIdType partitionId)                                                                                      /* PRQA S 3206 */ /* MD_NvM_CslMacroNotUsingPartitionId */
{
  NvM_FsmLib_ProcessingResultType status = NVM_FSMLIB_PROCESSINGRESULT_STOP;

  NvM_FsmLib_InstancePtrType fsmLibInstance =
    (NvM_FsmLib_InstancePtrType)NvM_GetAddrSingleBlockServiceFsmLib_Instance(partitionId);

#if (NVM_MULTIPARTITION_USAGE_SCENARIO == STD_ON)
  NvM_ServiceJobResultType serviceJobResult = NvM_SatelliteCom_GetSingleBlockJobStatus(partitionId);

  if (serviceJobResult != NVM_SERVICE_JOB_PENDING)
  {
    NvM_SatelliteCom_FinalizeSingleBlockJob(partitionId);
    NvM_FsmLib_FinalizeCurrentActiveFsm(fsmLibInstance, serviceJobResult);

    status = NVM_FSMLIB_PROCESSINGRESULT_CONTINUE;
  }
#else
  NvM_FsmLib_InstancePtrToConstType nvServiceFsmLibInstance =
    (NvM_FsmLib_InstancePtrToConstType)NvM_GetAddrNvServiceFsmLib_Instance(partitionId);

  NvM_FsmLib_ProcessCurrentActiveFsm(nvServiceFsmLibInstance);

  if (NvM_FsmLib_IsProcessingStackEmpty(nvServiceFsmLibInstance) == TRUE)
  {
    NvM_ServiceJobResultType serviceJobResult = NvM_FsmLib_GetSubFsmResult(nvServiceFsmLibInstance);
    NvM_FsmLib_FinalizeCurrentActiveFsm(fsmLibInstance, serviceJobResult);

    status = NVM_FSMLIB_PROCESSINGRESULT_CONTINUE;
  }
#endif

  /*
   * The parameter partitionId is not used within this function in single partition use case.
   * To avoid compiler warnings the following dummy statement is added.
   */
  NVM_DUMMY_STATEMENT(partitionId);                                                                                     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  return status;
}

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * NvM_NvJobFsm_Execute()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, NVM_PRIVATE_CODE) NvM_NvJobFsm_Execute(NvM_PartitionIdType partitionId)
{
  NvM_NvJobFsm_Spawn(partitionId);
}

#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: NvM_NvJobFsm.c
 *********************************************************************************************************************/
