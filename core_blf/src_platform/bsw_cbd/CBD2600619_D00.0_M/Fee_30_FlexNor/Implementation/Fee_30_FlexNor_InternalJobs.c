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
/*!        \file  Fee_30_FlexNor_InternalJobs.c
 *        \brief  Internal jobs implementation
 *      \details  Provides the business logic for the internal jobs services.
 *         \unit  InternalJobs
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#define FEE_30_FLEXNOR_INTENALJOBS_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Fee_30_FlexNor_InternalJobs.h"
#include "Fee_30_FlexNor_InternalJobsInternal.h"
#include "Fee_30_FlexNor_InternalJobsMachine.h"

#include "Fee_30_FlexNor_Scheduler.h"
#include "Fee_30_FlexNor_CopyBlock.h"
#include "Fee_30_FlexNor_GarbageCollection.h"
#include "Fee_30_FlexNor_SectorContainer.h"
#include "Fee_30_FlexNor_Partition.h"
#include "Fee_30_FlexNor_CopyBlock.h"
#include "Fee_30_FlexNor_Shared.h"
#include "Fee_30_FlexNor_DiagnosticHandler.h"

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
/* The maximal allowed sector ID span is 63. If the ID span exceeds this limit, the Fee cannot order the sector by their 
   age anymore. The GC allocates the target sector with an incremented ID before it marks the source sector for erase. 
   So while the GC is running, the sector ID span is incremented by one. So FEE_30_FLEXNOR_MAX_RECOVERY_ID_SPAN must be 
   smaller than 62. To have a little buffer FEE_30_FLEXNOR_MAX_RECOVERY_ID_SPAN is set to 60. */
 # define FEE_30_FLEXNOR_MAX_RECOVERY_ID_SPAN (60u) 

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
#define FEE_30_FLEXNOR_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Context variable of the internal jobs state machine. */
FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_InternalJobs_ContextType Fee_30_FlexNor_InternalJobsStmContext = { 0u }; /* PRQA S 3218 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */

#define FEE_30_FLEXNOR_STOP_SEC_VAR_CLEARED_UNSPECIFIED
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
 * Fee_30_FlexNor_InternalJobs_ResultHandler()
 *********************************************************************************************************************/
/*! \brief       Handels the result of services called by the internal jobs unit
 *  \details     -
 *  \param[in]   result     Result of the called service
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_InternalJobs_ResultHandler(Fee_30_FlexNor_ServiceResult result);

/**********************************************************************************************************************
 * Fee_30_FlexNor_InternalJobs_ProcessingHandler()
 *********************************************************************************************************************/
/*! \brief       Handles the processing event
 *  \details     Triggers the Process event at the local state machine.
 *  \return      FEE_30_FLEXNOR_STOP_SCHEDULE       In case the scheduling shall be stopped
 *               FEE_30_FLEXNOR_CONTINUE_SCHEDULE   In case the scheduling can be continued
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FEE_30_FLEXNOR_LOCAL FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) 
  Fee_30_FlexNor_InternalJobs_ProcessingHandler(void);

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * Fee_30_FlexNor_InternalJobs_ResultHandler()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_InternalJobs_ResultHandler(Fee_30_FlexNor_ServiceResult result)
{
  if ((result == FEE_30_FLEXNOR_SERVICE_FAIL) || (result == FEE_30_FLEXNOR_SERVICE_NOT_OK))
  {
    Fee_30_FlexNor_InternalJobsStmContext.CurrentState->FailEvent(
      &Fee_30_FlexNor_InternalJobsStmContext); /* SBSW_Fee_30_FlexNor_TriggerEventAtState */
  }
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_InternalJobs_ProcessingHandler()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FEE_30_FLEXNOR_LOCAL FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) 
  Fee_30_FlexNor_InternalJobs_ProcessingHandler(void)
{
  return Fee_30_FlexNor_InternalJobsStmContext.CurrentState->ProcessEvent(
    &Fee_30_FlexNor_InternalJobsStmContext); /* SBSW_Fee_30_FlexNor_TriggerEventAtState */
}

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * Fee_30_FlexNor_InternalJobs_Init()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_InternalJobs_Init(void)
{
  Fee_30_FlexNor_InternalJobs_InitState(
    &Fee_30_FlexNor_InternalJobsStmContext); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_InternalJobs_StartJob()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_InternalJobs_StartJob(void)
{
  Fee_30_FlexNor_Scheduler_RegisterUnit(
    &Fee_30_FlexNor_InternalJobs_ProcessingHandler); /* SBSW_Fee_30_FlexNor_RegisterUnit */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_InternalJobs_EndJob()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_InternalJobs_EndJob(void)
{
  Fee_30_FlexNor_Scheduler_UnregisterUnit();
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_InternalJobs_Run()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_InternalJobs_Run(Fee_30_FlexNor_JobPtrType currentJob)
{
  Fee_30_FlexNor_InternalJobsStmContext.CurrentJob = currentJob;
  Fee_30_FlexNor_InternalJobsStmContext.linkToReallocatedChunk.SectorId = 0u;
  Fee_30_FlexNor_InternalJobsStmContext.linkToReallocatedChunk.ChunkOffset = 0u;

  Fee_30_FlexNor_InternalJobs_Run_Initialize(&Fee_30_FlexNor_InternalJobsStmContext); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_InternalJobs_Startup()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_InternalJobs_Startup(
  Fee_30_FlexNor_InternalJobs_ConstContextPtrType ctx)
{
  Fee_30_FlexNor_Partition_StartUp(
    ctx->CurrentJob->PartitionId,
    &Fee_30_FlexNor_InternalJobs_ResultHandler); /* SBSW_Fee_30_FlexNor_ResultHandler */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_InternalJobs_FinishGarbageCollection()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_InternalJobs_FinishGarbageCollection(
  Fee_30_FlexNor_InternalJobs_ConstContextPtrType ctx)
{
  Fee_30_FlexNor_GarbageCollection_Run(
    ctx->CurrentJob->PartitionId,
    NULL_PTR,
    FALSE,
    &Fee_30_FlexNor_InternalJobs_ResultHandler); /* SBSW_Fee_30_FlexNor_ResultHandler */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_InternalJobs_TryTriggerSectorRecovery()
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
FUNC(boolean, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_InternalJobs_TryTriggerSectorRecovery(
  Fee_30_FlexNor_InternalJobs_ConstContextPtrType ctx)
{
  boolean recoveryPending = FALSE;
  Fee_30_FlexNor_SectorPtrType sector = Fee_30_FlexNor_SectorContainer_GetFirst(ctx->CurrentJob->PartitionId);

  const uint8 currentSectorIdSpan = Fee_30_FlexNor_SectorContainer_GetSectorIdSpan(ctx->CurrentJob->PartitionId);

  if (currentSectorIdSpan < FEE_30_FLEXNOR_MAX_RECOVERY_ID_SPAN)
  {
    while (sector != NULL_PTR)
    {
      if (sector->SelectedForRecoveryGarbageCollection == TRUE)
      {
        Fee_30_FlexNor_GarbageCollection_Run(
          ctx->CurrentJob->PartitionId,
          sector,
          FALSE,
          &Fee_30_FlexNor_InternalJobs_ResultHandler
        ); /* SBSW_Fee_30_FlexNor_ResultHandler */

        sector->SelectedForRecoveryGarbageCollection = FALSE; /* SBSW_Fee_30_FlexNor_SectorContainer_GetSector */
        recoveryPending = TRUE;
        break;
      }

      sector = Fee_30_FlexNor_SectorContainer_GetNext(sector); /* SBSW_Fee_30_FlexNor_LoopStoredSectors */
    }
  }
  else
  {
    Fee_30_FlexNor_DiagnosticHandler_RaiseWarning(FEE_30_FLEXNOR_DIAGID_SECTORIDSPAN_VERYHIGH);
  }

  return recoveryPending;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_InternalJobs_TryTriggerReallocateChunk()
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
FUNC(boolean, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_InternalJobs_TryTriggerReallocateChunk(
  Fee_30_FlexNor_InternalJobs_ContextPtrType ctx)
{
  boolean reallocationPending = FALSE;
  Fee_30_FlexNor_ConstPartitionConfigPtrType partition = Fee_30_FlexNor_ConfigInterface_GetPartitionConfig(
    ctx->CurrentJob->PartitionId);

  for (uint32 blockIdx = 0; blockIdx < partition->BlockCount; blockIdx++)
  {
      Fee_30_FlexNor_BlockConfigType block = partition->Blocks[blockIdx];

      if (Fee_30_FlexNor_LookupTable_IsReallocationRequested(ctx->CurrentJob->PartitionId, block.Id) == TRUE)
      {
        Fee_30_FlexNor_LookupTable_RequestChunkReallocation(ctx->CurrentJob->PartitionId, block.Id, FALSE);

        Fee_30_FlexNor_LookupTable_LinkType link = Fee_30_FlexNor_LookupTable_GetLink(ctx->CurrentJob->PartitionId, 
            block.Id);
        Fee_30_FlexNor_SectorPtrType sourceSector = Fee_30_FlexNor_SectorContainer_Get(ctx->CurrentJob->PartitionId, 
            link.SectorId, TRUE);
        Fee_30_FlexNor_SectorPtrType targetSector = Fee_30_FlexNor_SectorContainer_GetNewestValid(
          ctx->CurrentJob->PartitionId); /* SBSW_Fee_30_FlexNor_ContextPointerAccess */

        Fee_30_FlexNor_CopyBlock_Copy(
          ctx->CurrentJob->PartitionId,
          block.Id,
          sourceSector,
          targetSector,
          link.ChunkOffset,
          FALSE,
          &Fee_30_FlexNor_InternalJobs_ResultHandler); /* SBSW_Fee_30_FlexNor_ResultHandler */

        ctx->linkToReallocatedChunk = link; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        reallocationPending = TRUE;

        break;
      }
  }

  return reallocationPending;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_InternalJobs_RequestRecoveryGarbageCollection()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_InternalJobs_RequestRecoveryGarbageCollection(
  Fee_30_FlexNor_PartitionIdType partitionId,
  Fee_30_FlexNor_AddressType sectorAddress)
{
  Fee_30_FlexNor_SectorPtrType sector = Fee_30_FlexNor_SectorContainer_GetSectorByAddress(partitionId, sectorAddress);

  if(sector != NULL_PTR)
  {
    sector->SelectedForRecoveryGarbageCollection = TRUE; /* SBSW_Fee_30_FlexNor_SectorContainer_GetSector */
  }
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_InternalJobs_SuspendRecoveryJobs()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_InternalJobs_SuspendRecoveryJobs(boolean suspendRecoveryJobsEnabled)
{
  Fee_30_FlexNor_InternalJobsStmContext.SuspendRecoveryJobsEnabled = suspendRecoveryJobsEnabled;
}

#define FEE_30_FLEXNOR_STOP_SEC_CODE
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: Fee_30_FlexNor_InternalJobs.c
 *********************************************************************************************************************/
