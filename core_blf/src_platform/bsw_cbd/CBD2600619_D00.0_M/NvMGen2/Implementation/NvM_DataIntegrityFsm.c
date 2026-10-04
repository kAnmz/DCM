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
/*!        \file  NvM_DataIntegrityFsm.c
 *        \brief  NvM_DataIntegrityFsm source file
 *      \details  Implementation of data integrity state machine
 *         \unit  NvM_DataIntegrityFsm
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#define NVM_DATAINTEGRITYFSM_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "NvM_DataIntegrityFsm.h"
#include "NvM_FsmLib.h"
#include "NvM_CfgDefines.h"
#include "NvM_DataIntegrityService.h"

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
 * NvM_DataIntegrityFsm_Entry()
 *********************************************************************************************************************/
/*!  \brief       ENTRY action of DataIntegrityFsm
 *   \details     -
 *   \param[in]   partitionId Partition ID.
 *   \pre         -
 *   \context     TASK
 *   \reentrant   FALSE
 *   \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, NVM_PRIVATE_CODE) NvM_DataIntegrityFsm_Entry(NvM_PartitionIdType partitionId);


/**********************************************************************************************************************
 * NvM_DataIntegrityFsm_GenerateDataIntegrityRecord_Do()
 *********************************************************************************************************************/
/*!  \brief       DO action of DataIntegrityFsm state ProcessDataIntegrityJob
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
FUNC(NvM_FsmLib_ProcessingResultType, NVM_PRIVATE_CODE) NvM_DataIntegrityFsm_ProcessDataIntegrityJobState_Do(
  NvM_PartitionIdType partitionId);


#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/***********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/


/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/
#define NVM_START_SEC_CONST_UNSPECIFIED
#include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*
 * Initializing a const structure (NvM_DataIntegrityFsm_InitialState) can only be done with compile-time constants.
 * Therefore this defines are introduced to minimize code duplication within NvM_DataIntegrityFsm_InitialState and
 * NvM_DataIntegrityFsm_ProcessDataIntegrityJobState initialization.
 */
#define NVM_DATAINTEGRITYFSM_PROCESSDATAINTEGRITYJOBSTATE_ENTRY NvM_FsmLib_EntryNoOp
#define NVM_DATAINTEGRITYFSM_PROCESSDATAINTEGRITYJOBSTATE_DO NvM_DataIntegrityFsm_ProcessDataIntegrityJobState_Do

/*! STATE: ProcessDataIntegrityJobState */
/* PRQA S 3218 1 */ /* MD_Fsm_StateDefinitionStaticUsedOnlyInSingleFunction */
NVM_LOCAL CONST(NvM_StateType, NVM_PRIVATE_DATA) NvM_DataIntegrityFsm_ProcessDataIntegrityJobState = {
  NVM_DATAINTEGRITYFSM_PROCESSDATAINTEGRITYJOBSTATE_ENTRY, 
  NVM_DATAINTEGRITYFSM_PROCESSDATAINTEGRITYJOBSTATE_DO
};

/*! FSM: DataIntegrity with ENTRY action and initial state */
/* PRQA S 3218 1 */ /* MD_Fsm_StateDefinitionStaticUsedOnlyInSingleFunction */
NVM_LOCAL CONST(NvM_FsmType, NVM_PRIVATE_DATA) NvM_DataIntegrityFsm_InitialState = {
  NvM_DataIntegrityFsm_Entry,
  {
    NVM_DATAINTEGRITYFSM_PROCESSDATAINTEGRITYJOBSTATE_ENTRY, 
    NVM_DATAINTEGRITYFSM_PROCESSDATAINTEGRITYJOBSTATE_DO
  }
};

#define NVM_STOP_SEC_CONST_UNSPECIFIED
#include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

#define NVM_START_SEC_CODE
#include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * NvM_DataIntegrityFsm_Entry()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, NVM_PRIVATE_CODE) NvM_DataIntegrityFsm_Entry(NvM_PartitionIdType partitionId)                                /* PRQA S 3206 */ /* MD_NvM_CslMacroNotUsingPartitionId */
{
  NvM_FsmLib_InstancePtrToConstType fsmLibInstance =
    (NvM_FsmLib_InstancePtrToConstType)NvM_GetAddrSingleBlockServiceFsmLib_Instance(partitionId);

  NvM_FsmLib_TransitionToState(fsmLibInstance, NvM_DataIntegrityFsm_ProcessDataIntegrityJobState);

  /* 
   * The parameter partitionId is not used within this function in single partition use case.
   * To avoid compiler warnings the following dummy statement is added.
   */
  NVM_DUMMY_STATEMENT(partitionId);                                                                                     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
}

/**********************************************************************************************************************
 * NvM_DataIntegrityFsm_ProcessDataIntegrityJobState_Do()
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
FUNC(NvM_FsmLib_ProcessingResultType, NVM_PRIVATE_CODE) NvM_DataIntegrityFsm_ProcessDataIntegrityJobState_Do(
  NvM_PartitionIdType partitionId)
{
  NvM_FsmLib_ProcessingResultType retVal = NVM_FSMLIB_PROCESSINGRESULT_STOP;

  NvM_ForegroundDataIntegrityService_InstancePtrType serviceInstance =
    NvM_GetAddrForegroundDataIntegrityService_Instance(partitionId);

  NvM_DataIntegrityService_Status jobStatus = NvM_DataIntegrityService_GetStatus(serviceInstance);

  if(jobStatus == NVM_DATAINTEGRITYSERVICE_STATUS_PENDING)
  {
     NvM_DataIntegrityService_Process(serviceInstance);
  }
  else
  {
    NvM_FsmLib_InstancePtrType fsmLibInstance =
    (NvM_FsmLib_InstancePtrType)NvM_GetAddrSingleBlockServiceFsmLib_Instance(partitionId);

     NvM_ServiceJobResultType serviceResult = (jobStatus == NVM_DATAINTEGRITYSERVICE_STATUS_FINISHED_SUCCESSFUL)
      ? NVM_SERVICE_JOB_OK
      : NVM_SERVICE_JOB_NOT_OK;
    
    NvM_FsmLib_FinalizeCurrentActiveFsm(fsmLibInstance, serviceResult);

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
 * NvM_DataIntegrityFsm_Process()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, NVM_PRIVATE_CODE) NvM_DataIntegrityFsm_Process(
  NvM_DataIntegrityJobContextConstPtrType dataIntegrityJobContext)
{
  NvM_FsmLib_InstancePtrType fsmLibInstance = (NvM_FsmLib_InstancePtrType)NvM_GetAddrSingleBlockServiceFsmLib_Instance(
    dataIntegrityJobContext->PartitionId);
  
  /* Initialization of Foreground Service Instance done here, due to access to data integrity job context */
  NvM_ForegroundDataIntegrityService_InstancePtrType serviceInstance =
   NvM_GetAddrForegroundDataIntegrityService_Instance(dataIntegrityJobContext->PartitionId);

  NvM_DataIntegrityService_Init(serviceInstance, dataIntegrityJobContext);

  /* COM-4978: Wait for CSL feature to store init value of generated partion data */
  NvM_DataIntegrityFsm_InstancePtrType fsmInstance =
    NvM_GetAddrDataIntegrityFsm_Instance(dataIntegrityJobContext->PartitionId);
  *fsmInstance = NvM_DataIntegrityFsm_InitialState;

  (void)NvM_FsmLib_SpawnFsm(fsmLibInstance, *fsmInstance);
}

#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: NvM_DataIntegrityFsm.c
 *********************************************************************************************************************/
