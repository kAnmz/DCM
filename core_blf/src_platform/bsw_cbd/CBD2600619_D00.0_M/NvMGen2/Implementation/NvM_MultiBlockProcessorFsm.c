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
/*!        \file  NvM_MultiBlockProcessorFsm.c
 *        \brief  NvM_MultiBlockProcessorFsm source file
 *      \details  Implementation of the multiblock processor FSM unit of the NvM.
 *         \unit  NvM_MultiBlockProcessorFsm
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

 #define NVM_MULTIBLOCKPROCESSORFSM_SOURCE

 /**********************************************************************************************************************
  *  INCLUDES
  *********************************************************************************************************************/
 #include "NvM_MultiBlockProcessorFsm.h"

#if (NVM_MULTIPARTITION_USAGE_SCENARIO == STD_ON) /* COV_MSR_UT_OPTIONAL_UNIT */

#include "NvM_FsmLib.h"
#include "NvM_MasterCom.h"
#include "NvM_Notification.h"
#include "NvM_GlobalUtilityLib.h"
#include "NvM_Cfg.h"

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
 * NvM_MultiBlockProcessorFsm_Entry()
 *********************************************************************************************************************/
/*!  \brief          ENTRY action of MultiBlockProcessorFsm.
 *   \details        -
 *   \param[in]      partitionId Partition ID.
 *   \pre            -
 *   \context        TASK
 *   \reentrant      FALSE
 *   \synchronous    TRUE
 *   \spec
 *      requires partitionId == NVM_PARTITION_ID_MASTER;
 *   \endspec
 *********************************************************************************************************************/
FUNC(void, NVM_PRIVATE_CODE) NvM_MultiBlockProcessorFsm_Entry(NvM_PartitionIdType partitionId);

/**********************************************************************************************************************
 * NvM_MultiBlockProcessorFsm_IdleState_Do()
 *********************************************************************************************************************/
/*! \brief           DO action of state Idle
 *  \details         -
 *  \param[in]       partitionId Partition ID.
 *  \return          Based on state evaluation:
 *                   - STOP       if no further processing is required
 *                   - CONTINUE   if further processing shall be executed
 *  \pre             -
 *  \context         TASK
 *  \reentrant       FALSE
 *  \synchronous     TRUE
 *   \spec
 *      requires partitionId == NVM_PARTITION_ID_MASTER;
 *   \endspec
 *********************************************************************************************************************/
FUNC(NvM_FsmLib_ProcessingResultType, NVM_PRIVATE_CODE) NvM_MultiBlockProcessorFsm_IdleState_Do(
  NvM_PartitionIdType partitionId);

/**********************************************************************************************************************
 * NvM_MultiBlockProcessorFsm_WaitForSatellitesReadyState_Entry()
 *********************************************************************************************************************/
/*! \brief           ENTRY action of state WaitForSatellitesReady
 *  \details         -
 *  \param[in]       partitionId Partition ID.
 *  \pre             -
 *  \context         TASK
 *  \reentrant       FALSE
 *  \synchronous     TRUE
 *********************************************************************************************************************/
FUNC(void, NVM_PRIVATE_CODE) NvM_MultiBlockProcessorFsm_WaitForSatellitesReadyState_Entry(
  NvM_PartitionIdType partitionId);

/**********************************************************************************************************************
 * NvM_MultiBlockProcessorFsm_WaitForSatellitesReadyState_Do()
 *********************************************************************************************************************/
/*! \brief           DO action of state WaitForSatellitesReady
 *  \details         -
 *  \param[in]       partitionId Partition ID.
 *  \return          Based on state evaluation:
 *                   - STOP       if no further processing is required
 *                   - CONTINUE   if further processing shall be executed
 *  \pre             -
 *  \context         TASK
 *  \reentrant       FALSE
 *  \synchronous     TRUE
 *   \spec
 *      requires partitionId == NVM_PARTITION_ID_MASTER;
 *   \endspec
 *********************************************************************************************************************/
FUNC(NvM_FsmLib_ProcessingResultType, NVM_PRIVATE_CODE) NvM_MultiBlockProcessorFsm_WaitForSatellitesReadyState_Do(
  NvM_PartitionIdType partitionId);

/**********************************************************************************************************************
 * NvM_MultiBlockProcessorFsm_ProcessReadOrWriteAllState_Entry()
 *********************************************************************************************************************/
/*! \brief           ENTRY action of state ProcessSatellites
 *  \details         -
 *  \param[in]       partitionId Partition ID.
 *  \pre             -
 *  \context         TASK
 *  \reentrant       FALSE
 *  \synchronous     TRUE
 *********************************************************************************************************************/
FUNC(void, NVM_PRIVATE_CODE) NvM_MultiBlockProcessorFsm_ProcessReadOrWriteAllState_Entry(NvM_PartitionIdType partitionId);

/**********************************************************************************************************************
 * NvM_MultiBlockProcessorFsm_ProcessReadOrWriteAllState_Do()
 *********************************************************************************************************************/
/*! \brief           DO action of state ProcessSatellites
 *  \details         -
 *  \param[in]       partitionId Partition ID.
 *  \return          Based on state evaluation:
 *                   - STOP       if no further processing is required
 *                   - CONTINUE   if further processing shall be executed
 *  \pre             -
 *  \context         TASK
 *  \reentrant       FALSE
 *  \synchronous     TRUE
 *   \spec
 *      requires partitionId == NVM_PARTITION_ID_MASTER;
 *   \endspec
 *********************************************************************************************************************/
FUNC(NvM_FsmLib_ProcessingResultType, NVM_PRIVATE_CODE) NvM_MultiBlockProcessorFsm_ProcessReadOrWriteAllState_Do(
  NvM_PartitionIdType partitionId);

/**********************************************************************************************************************
 * NvM_MultiBlockProcessorFsm_ProcessValidateAllState_Entry()
 *********************************************************************************************************************/
/*! \brief           ENTRY action of state ProcessValidateAll
 *  \details         -
 *  \param[in]       partitionId Partition ID.
 *  \return          Based on state evaluation:
 *                   - STOP       if no further processing is required
 *                   - CONTINUE   if further processing shall be executed
 *  \pre             -
 *  \context         TASK
 *  \reentrant       FALSE
 *  \synchronous     TRUE
 *   \spec
 *      requires partitionId == NVM_PARTITION_ID_MASTER;
 *   \endspec
 *********************************************************************************************************************/
FUNC(void, NVM_PRIVATE_CODE) NvM_MultiBlockProcessorFsm_ProcessValidateAllState_Entry(
  NvM_PartitionIdType partitionId);

  /**********************************************************************************************************************
 * NvM_MultiBlockProcessorFsm_ProcessValidateAllState_Do()
 *********************************************************************************************************************/
/*! \brief           DO action of state ProcessValidateAll
 *  \details         -
 *  \param[in]       partitionId Partition ID.
 *  \return          Based on state evaluation:
 *                   - STOP       if no further processing is required
 *                   - CONTINUE   if further processing shall be executed
 *  \pre             -
 *  \context         TASK
 *  \reentrant       FALSE
 *  \synchronous     TRUE
 *   \spec
 *      requires partitionId == NVM_PARTITION_ID_MASTER;
 *   \endspec
 *********************************************************************************************************************/
FUNC(NvM_FsmLib_ProcessingResultType, NVM_PRIVATE_CODE) NvM_MultiBlockProcessorFsm_ProcessValidateAllState_Do(
  NvM_PartitionIdType partitionId);

/**********************************************************************************************************************
 * NvM_MultiBlockProcessorFsm_FinalizeMultiBlockJobState_Do()
 *********************************************************************************************************************/
/*! \brief           DO action of state FinalizeMultiBlockJob
 *  \details         -
 *  \param[in]       partitionId Partition ID.
 *  \return          Based on state evaluation:
 *                   - STOP       if no further processing is required
 *                   - CONTINUE   if further processing shall be executed
 *  \pre             -
 *  \context         TASK
 *  \reentrant       FALSE
 *  \synchronous     TRUE
 *   \spec
 *      requires partitionId == NVM_PARTITION_ID_MASTER;
 *   \endspec
 *********************************************************************************************************************/
FUNC(NvM_FsmLib_ProcessingResultType, NVM_PRIVATE_CODE) NvM_MultiBlockProcessorFsm_FinalizeMultiBlockJobState_Do(
  NvM_PartitionIdType partitionId);

#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
*  LOCAL DATA TYPES AND STRUCTURES
*********************************************************************************************************************/

/**!<
 * Structured information about the state of the communication port.
 */
typedef struct
{
  NvM_PartitionIdType CurrentSatellitePartitionId;  /*! Current satellite partition id to be processed */
  NvM_PartitionIdType StartSatellitePartitionId;    /*! Start partition id of processing */
  NvM_PartitionIdType ProcessedSatelliteCount;      /*! Count of processed satellites */
  NvM_MultiBlockJobType JobType;                    /*! Job Type to be processed */
} NvM_MultiBlockProcessorFsm_ContextType;

/**********************************************************************************************************************
*  LOCAL DATA PROTOTYPES
*********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**! Contains context information of the MultiBlockProcessorFsm */
NVM_LOCAL VAR(NvM_MultiBlockProcessorFsm_ContextType, NVM_PRIVATE_DATA) NvM_MultiBlockProcessorFsm_Context;

#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define NVM_START_SEC_CONST_UNSPECIFIED
#include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*
 * Initializing a const structure (NvM_MultiBlockProcessorFsm) can only be done with compile-time constants.
 * Therefore this defines are introduced to minimize code duplication within NvM_MultiBlockProcessorFsm and
 * NvM_MultiBlockProcessorFsm_IdleState initialization.
 */
#define NVM_MULTIBLOCKPROCESSORFSM_IDLESTATE_ENTRY NvM_FsmLib_EntryNoOp
#define NVM_MULTIBLOCKPROCESSORFSM_IDLESTATE_DO NvM_MultiBlockProcessorFsm_IdleState_Do

/*! STATE: Idle */

/* PRQA S 3218 1 */ /* MD_Fsm_StateDefinitionStaticUsedOnlyInSingleFunction */
NVM_LOCAL CONST(NvM_StateType, NVM_PRIVATE_DATA) NvM_MultiBlockProcessorFsm_IdleState= {
  NVM_MULTIBLOCKPROCESSORFSM_IDLESTATE_ENTRY,
  NVM_MULTIBLOCKPROCESSORFSM_IDLESTATE_DO
};

/*! STATE: WaitForSatellitesReady */

/* PRQA S 3218 1 */ /* MD_Fsm_StateDefinitionStaticUsedOnlyInSingleFunction */
NVM_LOCAL CONST(NvM_StateType, NVM_PRIVATE_DATA) NvM_MultiBlockProcessorFsm_WaitForSatellitesReadyState= {
  NvM_MultiBlockProcessorFsm_WaitForSatellitesReadyState_Entry,
  NvM_MultiBlockProcessorFsm_WaitForSatellitesReadyState_Do
};

/*! STATE: ProcessReadOrWriteAll */

/* PRQA S 3218 1 */ /* MD_Fsm_StateDefinitionStaticUsedOnlyInSingleFunction */
NVM_LOCAL CONST(NvM_StateType, NVM_PRIVATE_DATA) NvM_MultiBlockProcessorFsm_ProcessReadOrWriteAllState= {
  NvM_MultiBlockProcessorFsm_ProcessReadOrWriteAllState_Entry,
  NvM_MultiBlockProcessorFsm_ProcessReadOrWriteAllState_Do
};

/*! STATE: ProcessValidateAll */

/* PRQA S 3218 1 */ /* MD_Fsm_StateDefinitionStaticUsedOnlyInSingleFunction */
NVM_LOCAL CONST(NvM_StateType, NVM_PRIVATE_DATA) NvM_MultiBlockProcessorFsm_ProcessValidateAllState= {
  NvM_MultiBlockProcessorFsm_ProcessValidateAllState_Entry,
  NvM_MultiBlockProcessorFsm_ProcessValidateAllState_Do
};

/*! STATE: FinalizeMultiBlockJob */

/* PRQA S 3218 1 */ /* MD_Fsm_StateDefinitionStaticUsedOnlyInSingleFunction */
NVM_LOCAL CONST(NvM_StateType, NVM_PRIVATE_DATA) NvM_MultiBlockProcessorFsm_FinalizeMultiBlockJobState= {
  NvM_FsmLib_EntryNoOp,
  NvM_MultiBlockProcessorFsm_FinalizeMultiBlockJobState_Do
};

 /*! FSM: NvM_MultiBlockProcessorFsm instance with ENTRY action and initial state Idle */
/* PRQA S 3218 1 */ /* MD_Fsm_StateDefinitionStaticUsedOnlyInSingleFunction */
NVM_LOCAL CONST(NvM_FsmType, NVM_PRIVATE_DATA) NvM_MultiBlockProcessorFsm = {
  NvM_MultiBlockProcessorFsm_Entry,
  {NVM_MULTIBLOCKPROCESSORFSM_IDLESTATE_ENTRY, NVM_MULTIBLOCKPROCESSORFSM_IDLESTATE_DO}
};

#define NVM_STOP_SEC_CONST_UNSPECIFIED
#include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
*  GLOBAL DATA
*********************************************************************************************************************/

/**********************************************************************************************************************
*  LOCAL FUNCTION PROTOTYPES
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  NvM_MultiBlockProcessorFsm_GetMultiBlockJob()
 *********************************************************************************************************************/
/*! \brief       Gets the multiblock job type via the multiblock job information.
 *  \details     -
 *  \param[out]  jobType Retrieved Job Type.
 *  \return      E_OK:     A multiblock job was found.
 *               E_NOT_OK: No multiblock request was found.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, NVM_PRIVATE_CODE) NvM_MultiBlockProcessorFsm_GetMultiBlockJob(NvM_MultiBlockJobPtrType jobType);

/**********************************************************************************************************************
 * NvM_MultiBlockProcessorFsm_MapMultiBlockJobResultToNvMRequestResult()
 *********************************************************************************************************************/
/*! \brief       Convert the multiblock job result to NvM request result.
 *  \details     -
 *  \param[in]   jobStatus Job status.
 *  \pre         -
 *  \return      Mapped NvM request result.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(NvM_RequestResultType, NVM_PRIVATE_CODE) NvM_MultiBlockProcessorFsm_MapMultiBlockJobResultToNvMRequestResult(
  const NvM_SatelliteMultiBlockJobStatusType jobStatus);

/**********************************************************************************************************************
 * NvM_MultiBlockProcessorFsm_SafeIncrementCurrentActivePartition()
 *********************************************************************************************************************/
/*! \brief           Safely increments the current active partition; ensuring no invalid index is ever set
 *  \details         Automatically rolls over to 0 when partition count is reached.
 *  \pre             -
 *  \context         TASK
 *  \reentrant       FALSE
 *  \synchronous     TRUE
 *********************************************************************************************************************/
NVM_LOCAL FUNC(void, NVM_PRIVATE_CODE) NvM_MultiBlockProcessorFsm_SafeIncrementCurrentActivePartition(void);

/**********************************************************************************************************************
*  LOCAL FUNCTIONS
*********************************************************************************************************************/
#define NVM_START_SEC_CODE
#include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  NvM_MultiBlockProcessorFsm_GetMultiBlockJob
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
 */
FUNC(Std_ReturnType, NVM_PRIVATE_CODE) NvM_MultiBlockProcessorFsm_GetMultiBlockJob(NvM_MultiBlockJobPtrType jobType)
{
  Std_ReturnType retVal = E_NOT_OK;

  NvM_GlobalUtilityLib_EnterCriticalSection();
  {
    NvM_MultiBlockJobInformationType multiBlockJobInfo = NvM_GetMultiBlockJobInformation(NVM_PARTITION_ID_MASTER);

    if (NvM_GlobalUtilityLib_IsFlagSet(multiBlockJobInfo.JobStatusFlag, NVM_MULTIBLOCK_FLAG_READALL_REQUESTED))
    {
      *jobType = NVM_MULTIBLOCKJOBTYPE_READ_ALL;
      retVal = E_OK;
    }
    else if (NvM_GlobalUtilityLib_IsFlagSet(multiBlockJobInfo.JobStatusFlag, NVM_MULTIBLOCK_FLAG_WRITEALL_REQUESTED))
    {
      *jobType = NVM_MULTIBLOCKJOBTYPE_WRITE_ALL;
      retVal = E_OK;
    }
    else if (NvM_GlobalUtilityLib_IsFlagSet(multiBlockJobInfo.JobStatusFlag, NVM_MULTIBLOCK_FLAG_VALIDATEALL_REQUESTED))
    {
      *jobType = NVM_MULTIBLOCKJOBTYPE_VALIDATE_ALL;
      retVal = E_OK;
    }
    else
    {
      retVal = E_NOT_OK;
    }
  }
  NvM_GlobalUtilityLib_ExitCriticalSection();

  return retVal;
}

/**********************************************************************************************************************
*  NvM_MultiBlockProcessorFsm_MapMultiBlockJobResultToNvMRequestResult
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(NvM_RequestResultType, NVM_PRIVATE_CODE) NvM_MultiBlockProcessorFsm_MapMultiBlockJobResultToNvMRequestResult(
  const NvM_SatelliteMultiBlockJobStatusType jobStatus)
{
  NvM_RequestResultType result = NVM_REQ_NOT_OK;

  if (jobStatus == NVM_SATELLITE_MULTIBLOCK_JOB_STATUS_OK)
  {
    result = NVM_REQ_OK;
  }

  return result;
}

/**********************************************************************************************************************
 * NvM_MultiBlockProcessorFsm_SafeIncrementCurrentActivePartition()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
NVM_LOCAL FUNC(void, NVM_PRIVATE_CODE) NvM_MultiBlockProcessorFsm_SafeIncrementCurrentActivePartition(void)
{
  NvM_MultiBlockProcessorFsm_Context.CurrentSatellitePartitionId++;

  if (NvM_MultiBlockProcessorFsm_Context.CurrentSatellitePartitionId >= NvM_GetSizeOfPartitionIdentifiers())
  {
    NvM_MultiBlockProcessorFsm_Context.CurrentSatellitePartitionId = 0u;
  }
}

/**********************************************************************************************************************
 * NvM_MultiBlockProcessorFsm_Entry()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, NVM_PRIVATE_CODE) NvM_MultiBlockProcessorFsm_Entry(NvM_PartitionIdType partitionId)
{
  NvM_FsmLib_InstancePtrToConstType fsmLibInstance =
    (NvM_FsmLib_InstancePtrType)NvM_GetAddrMultiBlockProcessorFsmLib_Instance(partitionId);

  NvM_MultiBlockProcessorFsm_Context.ProcessedSatelliteCount = 0u;

  NvM_FsmLib_TransitionToState(fsmLibInstance, NvM_MultiBlockProcessorFsm_IdleState);
}

/*
 * State: IdleState
 */

/**********************************************************************************************************************
 * NvM_MultiBlockProcessorFsm_IdleState_Do()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(NvM_FsmLib_ProcessingResultType, NVM_PRIVATE_CODE) NvM_MultiBlockProcessorFsm_IdleState_Do(
  NvM_PartitionIdType partitionId)
{
  NvM_FsmLib_ProcessingResultType result = NVM_FSMLIB_PROCESSINGRESULT_STOP;

  if (NvM_MultiBlockProcessorFsm_GetMultiBlockJob(&NvM_MultiBlockProcessorFsm_Context.JobType) == E_OK)
  {
    NvM_FsmLib_InstancePtrToConstType fsmLibInstance =
      (NvM_FsmLib_InstancePtrToConstType)NvM_GetAddrMultiBlockProcessorFsmLib_Instance(partitionId);

    NvM_FsmLib_TransitionToState(fsmLibInstance, NvM_MultiBlockProcessorFsm_WaitForSatellitesReadyState);

    result = NVM_FSMLIB_PROCESSINGRESULT_CONTINUE;
  }

  return result;
}

/*
 * State: WaitForSatellitesReadyState
 */

/**********************************************************************************************************************
 * NvM_MultiBlockProcessorFsm_WaitForSatellitesReadyState_Entry()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, NVM_PRIVATE_CODE) NvM_MultiBlockProcessorFsm_WaitForSatellitesReadyState_Entry(
  NvM_PartitionIdType partitionId)
{
  /* Reset current satellite partition id */
  NvM_MultiBlockProcessorFsm_Context.CurrentSatellitePartitionId = 0u;

  /* Do nothing */
  NVM_DUMMY_STATEMENT(partitionId);                                                                                     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  NvM_MasterCom_BroadcastMultiBlockRequestToSatellites(NvM_MultiBlockProcessorFsm_Context.JobType);
}

/**********************************************************************************************************************
 * NvM_MultiBlockProcessorFsm_WaitForSatellitesReadyState_Do()
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
FUNC(NvM_FsmLib_ProcessingResultType, NVM_PRIVATE_CODE) NvM_MultiBlockProcessorFsm_WaitForSatellitesReadyState_Do(
  NvM_PartitionIdType partitionId)
{
  /*
    This routine is a busy-waiting loop until all satellites inform to be READY.
    The goal is to mirror each partition as "active" via the getter NvM_MultiBlockProcessorFsm_GetActivePartitionId(),
    allowing the integrator to schedule a call to the NvM_MainFunction() from correct context.

    Without this busy-waiting loop a multiblock would never be started as no satellite ever gets ready.
  */

  NvM_FsmLib_ProcessingResultType result = NVM_FSMLIB_PROCESSINGRESULT_STOP;

  const NvM_PartitionIdentifiersIterType partitionCount = NvM_GetSizeOfPartitionIdentifiers();
  const NvM_SatelliteMultiBlockJobStatusType partitionStatus = NvM_MasterCom_GetMultiBlockJobStatus(
      NvM_MultiBlockProcessorFsm_Context.CurrentSatellitePartitionId);

  if (partitionStatus == NVM_SATELLITE_MULTIBLOCK_JOB_STATUS_READY)
  {
    NvM_MultiBlockProcessorFsm_Context.CurrentSatellitePartitionId++;

    if (NvM_MultiBlockProcessorFsm_Context.CurrentSatellitePartitionId >= partitionCount)
    {
      /* Least satellite got READY */

      NvM_FsmLib_InstancePtrToConstType fsmLibInstance =
          (NvM_FsmLib_InstancePtrToConstType)NvM_GetAddrMultiBlockProcessorFsmLib_Instance(partitionId);

      /* Reset, never point to an invalid index */
      NvM_MultiBlockProcessorFsm_Context.CurrentSatellitePartitionId = 0u;

      if (NvM_MultiBlockProcessorFsm_Context.JobType == NVM_MULTIBLOCKJOBTYPE_VALIDATE_ALL)
      {
        NvM_FsmLib_TransitionToState(fsmLibInstance, NvM_MultiBlockProcessorFsm_ProcessValidateAllState);
      }
      else
      {
        NvM_FsmLib_TransitionToState(fsmLibInstance, NvM_MultiBlockProcessorFsm_ProcessReadOrWriteAllState);
      }

      result = NVM_FSMLIB_PROCESSINGRESULT_CONTINUE;
    }
  }

  return result;
}

/*
 * State: ProcessReadOrWriteAllState
 */

/**********************************************************************************************************************
 * NvM_MultiBlockProcessorFsm_ProcessReadOrWriteAllState_Entry()
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
FUNC(void, NVM_PRIVATE_CODE) NvM_MultiBlockProcessorFsm_ProcessReadOrWriteAllState_Entry(
  NvM_PartitionIdType partitionId)
{
  /* Do nothing */
  NVM_DUMMY_STATEMENT(partitionId);                                                                                     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  NvM_GlobalUtilityLib_EnterCriticalSection();
  {
    NvM_MultiBlockJobInformationPtrType multiBlockJobInfo =
        NvM_GetAddrMultiBlockJobInformation(NVM_PARTITION_ID_MASTER);

    switch(NvM_MultiBlockProcessorFsm_Context.JobType)
    {
      case NVM_MULTIBLOCKJOBTYPE_READ_ALL:
        multiBlockJobInfo->JobStatusFlag = NvM_GlobalUtilityLib_SetFlag(multiBlockJobInfo->JobStatusFlag,
                                                          NVM_MULTIBLOCK_FLAG_READALL_ACTIVE);

        /* Start processing at master partition: config block must be read first */
        NvM_MultiBlockProcessorFsm_Context.StartSatellitePartitionId = NVM_PARTITION_ID_MASTER;
        break;
      case NVM_MULTIBLOCKJOBTYPE_WRITE_ALL:
        multiBlockJobInfo->JobStatusFlag = NvM_GlobalUtilityLib_SetFlag(multiBlockJobInfo->JobStatusFlag,
                                                          NVM_MULTIBLOCK_FLAG_WRITEALL_ACTIVE);

        /* Start processing NOT at master partition: config block must be written last.
           Master is ensured to be the lowest entry, incrementing here is therefore safe.
           The DO action of this state takes over overflow handling. */
        NvM_MultiBlockProcessorFsm_Context.StartSatellitePartitionId = NVM_PARTITION_ID_MASTER + 1u;
        break;

      default: /* COV_NVM_MISRA_BRANCH */
        /*
         * MISRA case. Do nothing.
         * This default case is empty due to the fact that it does not process
         * cancel and kill requests.
         */
        break;
    }
  }
  NvM_GlobalUtilityLib_ExitCriticalSection();

  /* Start processing of first satellite */
  NvM_MultiBlockProcessorFsm_Context.CurrentSatellitePartitionId =
    NvM_MultiBlockProcessorFsm_Context.StartSatellitePartitionId;

  NvM_MasterCom_StartMultiBlockJobProcessing(NvM_MultiBlockProcessorFsm_Context.CurrentSatellitePartitionId);
}

/**********************************************************************************************************************
 * NvM_MultiBlockProcessorFsm_ProcessReadOrWriteAllState_Do()
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
FUNC(NvM_FsmLib_ProcessingResultType, NVM_PRIVATE_CODE) NvM_MultiBlockProcessorFsm_ProcessReadOrWriteAllState_Do(
  NvM_PartitionIdType partitionId)
{
  NvM_FsmLib_ProcessingResultType result = NVM_FSMLIB_PROCESSINGRESULT_STOP;

  NvM_SatelliteMultiBlockJobStatusType jobStatus =
    NvM_MasterCom_GetMultiBlockJobStatus(NvM_MultiBlockProcessorFsm_Context.CurrentSatellitePartitionId);

  const boolean isJobPending =
      (jobStatus == NVM_SATELLITE_MULTIBLOCK_JOB_STATUS_READY)
      || (jobStatus == NVM_SATELLITE_MULTIBLOCK_JOB_STATUS_ACTIVE);

  if (isJobPending)
  {
    result = NVM_FSMLIB_PROCESSINGRESULT_STOP;
  }
  else
  {
    NvM_FsmLib_InstancePtrToConstType fsmLibInstance =
      (NvM_FsmLib_InstancePtrToConstType)NvM_GetAddrMultiBlockProcessorFsmLib_Instance(partitionId);

    const NvM_PartitionIdType partitionCount = NvM_GetSizeOfPartitionIdentifiers();

    /*
     * Increment the processed satellite count after processing of satellite finished.
     * Due to VCA, a local variable for processed satellite count has to be used.
     * Otherwise ProcessedSatelliteCount of Fsm Context can be out of range at function exit.
     */
    NvM_PartitionIdType processedSatelliteCount = NvM_MultiBlockProcessorFsm_Context.ProcessedSatelliteCount;
    processedSatelliteCount++;

    if (processedSatelliteCount >= partitionCount)
    {
      NvM_FsmLib_TransitionToState(fsmLibInstance, NvM_MultiBlockProcessorFsm_FinalizeMultiBlockJobState);
    }
    else
    {
      NvM_MultiBlockProcessorFsm_Context.ProcessedSatelliteCount = processedSatelliteCount;

      NvM_MultiBlockProcessorFsm_SafeIncrementCurrentActivePartition();

      NvM_MasterCom_StartMultiBlockJobProcessing(NvM_MultiBlockProcessorFsm_Context.CurrentSatellitePartitionId);
    }

    result = NVM_FSMLIB_PROCESSINGRESULT_CONTINUE;
  }

  return result;
}

/*
 * State: ProcessValidateAllState
 */

/**********************************************************************************************************************
 * NvM_MultiBlockProcessorFsm_ProcessValidateAllState_Entry()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, NVM_PRIVATE_CODE) NvM_MultiBlockProcessorFsm_ProcessValidateAllState_Entry(
  NvM_PartitionIdType partitionId)
{
  NVM_DUMMY_STATEMENT(partitionId);                                                                                     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  NvM_GlobalUtilityLib_EnterCriticalSection();
  {
    NvM_MultiBlockJobInformationPtrType multiBlockJobInfo =
        NvM_GetAddrMultiBlockJobInformation(NVM_PARTITION_ID_MASTER);

    multiBlockJobInfo->JobStatusFlag = NvM_GlobalUtilityLib_SetFlag(multiBlockJobInfo->JobStatusFlag,
                                                      NVM_MULTIBLOCK_FLAG_VALIDATEALL_ACTIVE);
  }
  NvM_GlobalUtilityLib_ExitCriticalSection();

  NvM_MasterCom_StartMultiBlockJobProcessingInParallel();
}

/**********************************************************************************************************************
 * NvM_MultiBlockProcessorFsm_ProcessValidateAllState_Do()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(NvM_FsmLib_ProcessingResultType, NVM_PRIVATE_CODE) NvM_MultiBlockProcessorFsm_ProcessValidateAllState_Do(
  NvM_PartitionIdType partitionId)
{
  NvM_FsmLib_ProcessingResultType result = NVM_FSMLIB_PROCESSINGRESULT_STOP;

  const boolean areAllSatellitesFinished = NvM_MasterCom_AreAllSatellitesFinishedWithMultiBlockJob();

  if (areAllSatellitesFinished == TRUE)
  {
    NvM_FsmLib_InstancePtrToConstType fsmLibInstance =
      (NvM_FsmLib_InstancePtrToConstType)NvM_GetAddrMultiBlockProcessorFsmLib_Instance(partitionId);

    NvM_FsmLib_TransitionToState(fsmLibInstance, NvM_MultiBlockProcessorFsm_FinalizeMultiBlockJobState);
    result = NVM_FSMLIB_PROCESSINGRESULT_CONTINUE;
  }

  return result;
}

/*
 * State: FinalizeMultiBlockJobState
 */

/**********************************************************************************************************************
 * NvM_MultiBlockProcessorFsm_FinalizeMultiBlockJobState_Do()
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
/* note: VCA findings justified via TAR-78219 */
FUNC(NvM_FsmLib_ProcessingResultType, NVM_PRIVATE_CODE) NvM_MultiBlockProcessorFsm_FinalizeMultiBlockJobState_Do(
  NvM_PartitionIdType partitionId)
{
  NvM_SatelliteMultiBlockJobStatusType overallSatellitesJobStatus = NVM_SATELLITE_MULTIBLOCK_JOB_STATUS_NONE;

  NvM_FsmLib_InstancePtrToConstType fsmLibInstance =
    (NvM_FsmLib_InstancePtrToConstType)NvM_GetAddrMultiBlockProcessorFsmLib_Instance(partitionId);

  const NvM_PartitionIdentifiersIterType partitionCount = NvM_GetSizeOfPartitionIdentifiers();

  for (NvM_PartitionIdentifiersIterType i = 0u; i < partitionCount; i++)
  {
    overallSatellitesJobStatus = NvM_MasterCom_GetMultiBlockJobStatus((NvM_PartitionIdType)i);

    if (overallSatellitesJobStatus == NVM_SATELLITE_MULTIBLOCK_JOB_STATUS_NOT_OK)
    {
      break;
    }
  }

  NvM_MultiBlockProcessorFsm_Context.ProcessedSatelliteCount = 0u;

  NvM_MasterCom_ResetMultiBlockJobPorts();

  NvM_MultiBlockJobInformationType multiBlockJobInfo = NvM_GetMultiBlockJobInformation(NVM_PARTITION_ID_MASTER);

  /*
   * Clear all multiblock job flags. Only possible since
   * no more than one multiblock job can be requested at a time
   */
  multiBlockJobInfo.JobStatusFlag = 0u;

  multiBlockJobInfo.ErrorStatus =
    NvM_MultiBlockProcessorFsm_MapMultiBlockJobResultToNvMRequestResult(overallSatellitesJobStatus);

  NvM_GlobalUtilityLib_EnterCriticalSection();
  {
    NvM_SetMultiBlockJobInformation(multiBlockJobInfo, NVM_PARTITION_ID_MASTER);
  }
  NvM_GlobalUtilityLib_ExitCriticalSection();

  NvM_Notification_ProcessMultiBlockNotification(NvM_MultiBlockProcessorFsm_Context.JobType,
    multiBlockJobInfo.ErrorStatus);

  /* note: VCA findings justified via TAR-78219 */
  NvM_FsmLib_TransitionToState(fsmLibInstance, NvM_MultiBlockProcessorFsm_IdleState);

  return NVM_FSMLIB_PROCESSINGRESULT_CONTINUE;
}

/**********************************************************************************************************************
*  GLOBAL FUNCTIONS
*********************************************************************************************************************/

/**********************************************************************************************************************
 * NvM_MultiBlockProcessorFsm_Spawn()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, NVM_PRIVATE_CODE) NvM_MultiBlockProcessorFsm_Spawn(NvM_PartitionIdType partitionId)
{
  NvM_FsmLib_InstancePtrType fsmLibInstance =
    (NvM_FsmLib_InstancePtrType)NvM_GetAddrMultiBlockProcessorFsmLib_Instance(partitionId);

  (void)NvM_FsmLib_SpawnFsm(fsmLibInstance, NvM_MultiBlockProcessorFsm);
}


/**********************************************************************************************************************
 * NvM_MultiBlockProcessorFsm_GetActivePartitionId()
 *********************************************************************************************************************/
 /*!
  * Internal comment removed.
 *
 *
  */
FUNC(NvM_PartitionIdType, NVM_PRIVATE_CODE) NvM_MultiBlockProcessorFsm_GetActivePartitionId(void)                       /* PRQA S 3206 */ /* MD_NvM_CslMacroNotUsingPartitionId */
{
    return NvM_MultiBlockProcessorFsm_Context.CurrentSatellitePartitionId;
}

#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#endif /* NVM_MULTIPARTITION_USAGE_SCENARIO */

/**********************************************************************************************************************
*  END OF FILE: NvM_MultiBlockProcessorFsm.c
*********************************************************************************************************************/
