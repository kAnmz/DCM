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
/*!        \file  Fee_30_FlexNor_InternalJobsMachine.c
 *        \brief  Internal jobs state machine implementation
 *      \details  Provides the implementation of the state machine logic for the internal jobs unit.
 *         \unit  InternalJobs
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#define FEE_30_FLEXNOR_INTERNALJOBSMACHINE_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Fee_30_FlexNor_InternalJobs.h"
#include "Fee_30_FlexNor_InternalJobsMachine.h"
#include "Fee_30_FlexNor_InternalJobsInternal.h"

#include "Fee_30_FlexNor_Shared.h"
#include "Fee_30_FlexNor_GarbageCollection.h"
#include "Fee_30_FlexNor_Partition.h"
#include "Fee_30_FlexNor_SectorContainer.h"

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/
#if !defined(FEE_30_FLEXNOR_LOCAL) /* COV_FEE_30_FLEXNOR_COMPATIBILITY */
# define FEE_30_FLEXNOR_LOCAL static
#endif

#if !defined(FEE_30_FLEXNOR_LOCAL_INLINE) /* COV_FEE_30_FLEXNOR_COMPATIBILITY */
# define FEE_30_FLEXNOR_LOCAL_INLINE LOCAL_INLINE
#endif

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/
#define FEE_30_FLEXNOR_START_SEC_CONST_UNSPECIFIED
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_InternalJobs_ConstStateType Fee_30_FlexNor_InternalJobsDefaultState = {
  &Fee_30_FlexNor_InternalJobs_DefaultProcessEvent,
  &Fee_30_FlexNor_InternalJobs_DefaultFailEvent
};

/* PRQA S 3218 1 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_InternalJobs_ConstStateType Fee_30_FlexNor_InternalJobsStartupState = {
  &Fee_30_FlexNor_InternalJobs_Startup_ProcessEvent, 
  &Fee_30_FlexNor_InternalJobs_JobFailEvent
};

/* PRQA S 3218 1 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_InternalJobs_ConstStateType Fee_30_FlexNor_InternalJobsFinishGarbageCollectionState 
= {
  &Fee_30_FlexNor_InternalJobs_FinishGarbageCollection_ProcessEvent, 
  &Fee_30_FlexNor_InternalJobs_JobFailEvent
};

/* PRQA S 3218 1 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_InternalJobs_ConstStateType Fee_30_FlexNor_InternalJobsRecoverSectorState = {
  &Fee_30_FlexNor_InternalJobs_RecoverSector_ProcessEvent,
  &Fee_30_FlexNor_InternalJobs_JobFailEvent
};

/* PRQA S 3218 1 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_InternalJobs_ConstStateType Fee_30_FlexNor_InternalJobsReallocateChunkState = {
  &Fee_30_FlexNor_InternalJobs_ReallocateChunk_ProcessEvent,
  &Fee_30_FlexNor_InternalJobs_ReallocateChunkFailEvent
};

#define FEE_30_FLEXNOR_STOP_SEC_CONST_UNSPECIFIED
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
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Fee_30_FlexNor_InternalJobs_InitState()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_InternalJobs_InitState(Fee_30_FlexNor_InternalJobs_ContextPtrType ctx)
{
  ctx->CurrentState = &Fee_30_FlexNor_InternalJobsDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_InternalJobs_DefaultProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_InternalJobs_DefaultProcessEvent(
  Fee_30_FlexNor_InternalJobs_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
  FEE_DUMMY_STATEMENT(ctx);
  return FEE_30_FLEXNOR_STOP_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_InternalJobs_DefaultFailEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_InternalJobs_DefaultFailEvent(
  Fee_30_FlexNor_InternalJobs_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
  FEE_DUMMY_STATEMENT(ctx);
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_InternalJobs_JobFailEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_InternalJobs_JobFailEvent(Fee_30_FlexNor_InternalJobs_ContextPtrType ctx)
{
  Fee_30_FlexNor_Partition_ResetStartup(ctx->CurrentJob->PartitionId);
  ctx->CurrentState = &Fee_30_FlexNor_InternalJobsDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
  Fee_30_FlexNor_InternalJobs_EndJob();

  ctx->CurrentJob->JobResult = MEMIF_JOB_FAILED; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_InternalJobs_Run_Initialize()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_InternalJobs_Run_Initialize(Fee_30_FlexNor_InternalJobs_ContextPtrType 
    ctx)
{
  Fee_30_FlexNor_InternalJobs_StartJob();

  ctx->CurrentState = &Fee_30_FlexNor_InternalJobsStartupState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
  Fee_30_FlexNor_InternalJobs_Startup_OnEnter(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}


/**********************************************************************************************************************
 * Fee_30_FlexNor_InternalJobs_Startup_OnEnter
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_InternalJobs_Startup_OnEnter(
  Fee_30_FlexNor_InternalJobs_ContextPtrType ctx)
{
  if(Fee_30_FlexNor_Partition_IsStartedUp(ctx->CurrentJob->PartitionId) == TRUE)
  {
    (void) Fee_30_FlexNor_InternalJobs_Startup_ProcessEvent(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
  }
  else 
  {
    Fee_30_FlexNor_InternalJobs_Startup(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
  }
}


/**********************************************************************************************************************
 * Fee_30_FlexNor_InternalJobs_Startup_ProcessEvent
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_InternalJobs_Startup_ProcessEvent(
  Fee_30_FlexNor_InternalJobs_ContextPtrType ctx)
{
  if(Fee_30_FlexNor_Shared_IsWriteLikeJob(ctx->CurrentJob->Service) == TRUE)
  {
      ctx->CurrentState = &Fee_30_FlexNor_InternalJobsFinishGarbageCollectionState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
      Fee_30_FlexNor_InternalJobs_FinishGarbageCollection_OnEnter(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
  }
  else /* Read Job */
  {
      ctx->CurrentState = &Fee_30_FlexNor_InternalJobsDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
      Fee_30_FlexNor_InternalJobs_EndJob();
  }

  return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}


/**********************************************************************************************************************
 * Fee_30_FlexNor_InternalJobs_FinishGarbageCollection_OnEnter
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_InternalJobs_FinishGarbageCollection_OnEnter(
  Fee_30_FlexNor_InternalJobs_ContextPtrType ctx)
{
    if (Fee_30_FlexNor_GarbageCollection_IsPending(ctx->CurrentJob->PartitionId) == TRUE)
    {
      Fee_30_FlexNor_InternalJobs_FinishGarbageCollection(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }
    else
    {
      (void) Fee_30_FlexNor_InternalJobs_FinishGarbageCollection_ProcessEvent(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_InternalJobs_FinishGarbageCollection_ProcessEvent
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) 
  Fee_30_FlexNor_InternalJobs_FinishGarbageCollection_ProcessEvent(Fee_30_FlexNor_InternalJobs_ContextPtrType ctx)
{
  if (ctx->SuspendRecoveryJobsEnabled == TRUE)
  {
    ctx->CurrentState = &Fee_30_FlexNor_InternalJobsDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_InternalJobs_EndJob();
  }
  else
  {
    ctx->CurrentState = &Fee_30_FlexNor_InternalJobsRecoverSectorState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_InternalJobs_RecoverSector_OnEnter(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
  }

  return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_InternalJobs_RecoverSector_ProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_InternalJobs_RecoverSector_OnEnter(
  Fee_30_FlexNor_InternalJobs_ContextPtrType ctx)
{
  (void) Fee_30_FlexNor_InternalJobs_RecoverSector_ProcessEvent(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_InternalJobs_RecoverSector_ProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_InternalJobs_RecoverSector_ProcessEvent(
  Fee_30_FlexNor_InternalJobs_ContextPtrType ctx)
{
  if (Fee_30_FlexNor_InternalJobs_TryTriggerSectorRecovery(ctx) == FALSE) /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
  {
    ctx->CurrentState = &Fee_30_FlexNor_InternalJobsReallocateChunkState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_InternalJobs_ReallocateChunk_OnEnter(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
  }

  return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}


/**********************************************************************************************************************
 * Fee_30_FlexNor_InternalJobs_ReallocateChunk_OnEnter
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_InternalJobs_ReallocateChunk_OnEnter(
  Fee_30_FlexNor_InternalJobs_ContextPtrType ctx)
{
    (void) Fee_30_FlexNor_InternalJobs_ReallocateChunk_ProcessEvent(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_InternalJobs_ReallocateChunk_ProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_InternalJobs_ReallocateChunk_ProcessEvent(
  Fee_30_FlexNor_InternalJobs_ContextPtrType ctx)
{
  if (Fee_30_FlexNor_InternalJobs_TryTriggerReallocateChunk(ctx) == FALSE) /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
  {
    ctx->CurrentState = &Fee_30_FlexNor_InternalJobsDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_InternalJobs_EndJob();
  }

  return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_InternalJobs_ReallocateChunkFailEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_InternalJobs_ReallocateChunkFailEvent(
  Fee_30_FlexNor_InternalJobs_ContextPtrType ctx)
{
  Fee_30_FlexNor_ConstSectorPtrType sector = Fee_30_FlexNor_SectorContainer_Get(ctx->CurrentJob->PartitionId, 
    ctx->linkToReallocatedChunk.SectorId, TRUE);
  Fee_30_FlexNor_InternalJobs_RequestRecoveryGarbageCollection(ctx->CurrentJob->PartitionId, sector->StartAddress);

  ctx->CurrentState = &Fee_30_FlexNor_InternalJobsDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
  Fee_30_FlexNor_InternalJobs_EndJob();
}

#define FEE_30_FLEXNOR_STOP_SEC_CODE
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: Fee_30_FlexNor_InternalJobsMachine.c
 *********************************************************************************************************************/
