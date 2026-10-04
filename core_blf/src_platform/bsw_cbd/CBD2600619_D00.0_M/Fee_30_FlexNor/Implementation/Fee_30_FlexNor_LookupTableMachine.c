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
/*!        \file  Fee_30_FlexNor_LookupTableMachine.c
 *        \brief  Lookup table state machine implementation
 *      \details  Provides the implementation of the state machine logic for the lookup table unit.
 *         \unit  LookupTable
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#define FEE_30_FLEXNOR_LOOKUPTABLEMACHINE_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Fee_30_FlexNor_LookupTableMachine.h"
#include "Fee_30_FlexNor_SectorContainer.h"
#include "Fee_30_FlexNor_DiagnosticHandler.h"

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/
#if !defined (FEE_30_FLEXNOR_LOCAL) /* COV_FEE_30_FLEXNOR_COMPATIBILITY */
# define FEE_30_FLEXNOR_LOCAL static
#endif

#if !defined (FEE_30_FLEXNOR_LOCAL_INLINE) /* COV_FEE_30_FLEXNOR_COMPATIBILITY */
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

FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_LookupTable_ConstStateType Fee_30_FlexNor_LookupTableDefaultState = {
    &Fee_30_FlexNor_LookupTable_DefaultProcessEvent, 
    &Fee_30_FlexNor_LookupTable_DefaultFailEvent
};

FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_LookupTable_ConstStateType Fee_30_FlexNor_LookupTableScanSectorState = { /* PRQA S 3218 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
    &Fee_30_FlexNor_LookupTable_ScanSector_ProcessEvent, 
    &Fee_30_FlexNor_LookupTable_JobFailEventWithNotification
};

FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_LookupTable_ConstStateType Fee_30_FlexNor_LookupTableWriteBlockState = { /* PRQA S 3218 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
    &Fee_30_FlexNor_LookupTable_WriteBlock_ProcessEvent, 
    &Fee_30_FlexNor_LookupTable_JobFailEventWithoutNotification
};

FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_LookupTable_ConstStateType Fee_30_FlexNor_LookupTableWriteShortcutState = { /* PRQA S 3218 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
    &Fee_30_FlexNor_LookupTable_WriteShortcut_ProcessEvent, 
    &Fee_30_FlexNor_LookupTable_JobFailEventWithoutNotification
};

FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_LookupTable_ConstStateType Fee_30_FlexNor_LookupTableFindMostRecentLutChunk = { /* PRQA S 3218 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
    &Fee_30_FlexNor_LookupTable_FindMostRecentLutChunk_ProcessEvent, 
    &Fee_30_FlexNor_LookupTable_LoadLutFailEventWithNotification
};

FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_LookupTable_ConstStateType Fee_30_FlexNor_LookupTableFindMostRecentLutInstance = { /* PRQA S 3218 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
    &Fee_30_FlexNor_LookupTable_FindMostRecentLutInstance_ProcessEvent, 
    &Fee_30_FlexNor_LookupTable_InstanceSearchFailEvent
};

FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_LookupTable_ConstStateType Fee_30_FlexNor_LookupTableReadMostRecentLutPayload = { /* PRQA S 3218 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
    &Fee_30_FlexNor_LookupTable_ReadMostRecentLutPayload_ProcessEvent, 
    &Fee_30_FlexNor_LookupTable_LoadLutFailEventWithNotification
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
 * Fee_30_FlexNor_LookupTable_InitState()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_InitState(Fee_30_FlexNor_LookupTable_ContextPtrType ctx)
{
    ctx->CurrentState = &Fee_30_FlexNor_LookupTableDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_DefaultProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_DefaultProcessEvent(
    Fee_30_FlexNor_LookupTable_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    FEE_DUMMY_STATEMENT(ctx);
    return FEE_30_FLEXNOR_STOP_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_DefaultFailEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_DefaultFailEvent(
    Fee_30_FlexNor_LookupTable_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    FEE_DUMMY_STATEMENT(ctx);
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_JobFailEventWithoutNotification()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_JobFailEventWithoutNotification(
    Fee_30_FlexNor_LookupTable_ContextPtrType ctx)
{
    ctx->CurrentState = &Fee_30_FlexNor_LookupTableDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_LookupTable_EndJob();
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_JobFailEventWithNotification()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_LoadLutFailEventWithNotification(
    Fee_30_FlexNor_LookupTable_ContextPtrType ctx)
{
    Fee_30_FlexNor_DiagnosticHandler_SetCurrentMilestone(FEE_30_FLEXNOR_DIAGID_LUTLOADING_FINISHED);

    ctx->CurrentState = &Fee_30_FlexNor_LookupTableDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_LookupTable_EndJob();
    ctx->ResultCallback(FEE_30_FLEXNOR_SERVICE_FAIL); /* SBSW_Fee_30_FlexNor_ContextFunctionPointerCall */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_JobFailEventWithNotification()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_JobFailEventWithNotification(
    Fee_30_FlexNor_LookupTable_ContextPtrType ctx)
{
    ctx->CurrentState = &Fee_30_FlexNor_LookupTableDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_LookupTable_EndJob();
    ctx->ResultCallback(FEE_30_FLEXNOR_SERVICE_FAIL); /* SBSW_Fee_30_FlexNor_ContextFunctionPointerCall */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_InstanceSearchFailEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_InstanceSearchFailEvent(
    Fee_30_FlexNor_LookupTable_ContextPtrType ctx)
{
    Fee_30_FlexNor_InternalJobs_RequestRecoveryGarbageCollection(ctx->PartitionConfig->PartitionId, 
        ctx->LutChunk.Data.StartAddress);

    Fee_30_FlexNor_LookupTable_LoadLutFailEventWithNotification(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_Recover_Initialize
 *********************************************************************************************************************/
/*!
 * Internal comment removed. *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_Recover_Initialize(
    Fee_30_FlexNor_LookupTable_ContextPtrType ctx)
{   
    Fee_30_FlexNor_LookupTable_StartJob();
    ctx->NextSectorToProcess = Fee_30_FlexNor_SectorContainer_GetOldestValid(ctx->PartitionConfig->PartitionId); /* SBSW_Fee_30_FlexNor_ContextPointerAccess */

    ctx->CurrentState = &Fee_30_FlexNor_LookupTableScanSectorState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_LookupTable_TriggerSectorScan(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_ScanSector_ProcessEvent
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
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_ScanSector_ProcessEvent(
    Fee_30_FlexNor_LookupTable_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{   
    /* in case no valid sector exists the current sector is NULL */
    if(ctx->NextSectorToProcess != NULL_PTR)
    {
        ctx->NextSectorToProcess = Fee_30_FlexNor_SectorContainer_GetNextNewerValid(ctx->NextSectorToProcess); /* SBSW_Fee_30_FlexNor_ContextPointerAccess */ /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }

    if(ctx->NextSectorToProcess == NULL_PTR)
    {
        /*
         * After scanning each sector, for every block the corresponding lookup table entry points to the newest valid 
         * chunk, i.e. the lookup table for this partition is valid.
         */
        Fee_30_FlexNor_LookupTable_Validate(ctx->PartitionConfig->PartitionId); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */

        ctx->CurrentState = &Fee_30_FlexNor_LookupTableDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        Fee_30_FlexNor_LookupTable_EndJob();
        ctx->ResultCallback(FEE_30_FLEXNOR_SERVICE_OK); /* SBSW_Fee_30_FlexNor_ContextFunctionPointerCall */
    }
    else
    {
        Fee_30_FlexNor_LookupTable_TriggerSectorScan(ctx);   /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }
    
    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_Persist_Initialize
 *********************************************************************************************************************/
/*!
 * Internal comment removed. *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_Persist_Initialize(
    Fee_30_FlexNor_LookupTable_ContextPtrType ctx)
{   
    Fee_30_FlexNor_LookupTable_StartJob();
    ctx->CurrentState = &Fee_30_FlexNor_LookupTableWriteBlockState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_LookupTable_TriggerLutBlockWrite(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_WriteBlock_ProcessEvent
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_WriteBlock_ProcessEvent(
    Fee_30_FlexNor_LookupTable_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    /* Reset the persist LUT request flag even if the LUT was not persisted due to 
    some fail scenarios (e.g. GC and LUT Recovery necessary). This is done to avoid
    triggering the persist LUT job over and over again within the MainFunction. */
    Fee_30_FlexNor_LookupTable_ResetPersistLutRequest(ctx->PartitionConfig->PartitionId);

    /* During the partial LUT recovery one already known chunk is read per sector. This offset must be added manually 
    here. */
    Fee_30_FlexNor_LookupTable_SetOffsetForNumberOfNewChunks(ctx->PartitionConfig->PartitionId);

    if(Fee_30_FlexNor_LookupTable_IsShortcutNecessary(ctx) == TRUE) /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    {
        ctx->CurrentState = &Fee_30_FlexNor_LookupTableWriteShortcutState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        Fee_30_FlexNor_LookupTable_TriggerLutShortcutWrite(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }
    else
    {
        ctx->CurrentState = &Fee_30_FlexNor_LookupTableDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        Fee_30_FlexNor_LookupTable_EndJob();
    }
    
    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_WriteShortcut_ProcessEvent
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_WriteShortcut_ProcessEvent(
    Fee_30_FlexNor_LookupTable_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    Fee_30_FlexNor_LookupTable_EndJob();
    ctx->CurrentState = &Fee_30_FlexNor_LookupTableDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_Load_Initialize
 *********************************************************************************************************************/
/*!
 * Internal comment removed. *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_Load_Initialize(
    Fee_30_FlexNor_LookupTable_ContextPtrType ctx)
{   
    Fee_30_FlexNor_DiagnosticHandler_SetCurrentMilestone(FEE_30_FLEXNOR_DIAGID_LUTLOADING_STARTED);

    Fee_30_FlexNor_LookupTable_StartJob();
    ctx->CurrentState = &Fee_30_FlexNor_LookupTableFindMostRecentLutChunk; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_LookupTable_TriggerLutChunkSearch(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_FindMostRecentLutChunk_ProcessEvent
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) 
    Fee_30_FlexNor_LookupTable_FindMostRecentLutChunk_ProcessEvent(Fee_30_FlexNor_LookupTable_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    if((ctx->LutChunkSearchSucceeded == TRUE) &&
       (ctx->LutChunk.Data.BlockId == FEE_30_FLEXNOR_LUTBLOCKID))
    {
        /* If the LUT chunk needs a reallocation the complete sector shall be recovered because the link chain can not be 
        maintained and a sector scan must be performed. This degrades the startup performance massively. */
        if(ctx->LutChunk.Data.ReallocationRequired == TRUE)
        {
            Fee_30_FlexNor_InternalJobs_RequestRecoveryGarbageCollection(ctx->PartitionConfig->PartitionId, 
                ctx->LutChunk.Data.StartAddress);
        }

        ctx->CurrentState = &Fee_30_FlexNor_LookupTableFindMostRecentLutInstance; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        Fee_30_FlexNor_LookupTable_TriggerLutInstanceSearch(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }
    else
    {
        Fee_30_FlexNor_DiagnosticHandler_SetCurrentMilestone(FEE_30_FLEXNOR_DIAGID_LUTLOADING_FINISHED);

        ctx->CurrentState = &Fee_30_FlexNor_LookupTableDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        Fee_30_FlexNor_LookupTable_EndJob();
        ctx->ResultCallback(FEE_30_FLEXNOR_SERVICE_NOT_OK); /* SBSW_Fee_30_FlexNor_ContextFunctionPointerCall */
    }
    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_FindMostRecentLutInstance_ProcessEvent
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) 
    Fee_30_FlexNor_LookupTable_FindMostRecentLutInstance_ProcessEvent(Fee_30_FlexNor_LookupTable_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    /* The LUT chunk location is cached to avoid overwriting the RAM content after loading the LUT from NVRAM. */
    ctx->LutChunkLocation = ctx->PartitionConfig->LookupTable[FEE_30_FLEXNOR_LUTBLOCKID]; /* SBSW_Fee_30_FlexNor_ModifyGivenObject */

    /* In case the size of the persisted LUT in Flash differs to the size of the currently configured LUT block,
    * the length of the payload to be read into RAM has to be explicitly set.
    * In this case the smaller value of these two values shall be taken as the length of the read request.
    */
    ctx->LutInstance.Data.PayloadSize = Fee_30_FlexNor_LookupTable_GetLutBlockContentLength(ctx); /* SBSW_Fee_30_FlexNor_ContextPointerAccess */ /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    ctx->CurrentState = &Fee_30_FlexNor_LookupTableReadMostRecentLutPayload; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_LookupTable_TriggerLutPayloadRead(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */

    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_ReadMostRecentLutPayload_ProcessEvent
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) 
    Fee_30_FlexNor_LookupTable_ReadMostRecentLutPayload_ProcessEvent(Fee_30_FlexNor_LookupTable_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    Fee_30_FlexNor_DiagnosticHandler_SetCurrentMilestone(FEE_30_FLEXNOR_DIAGID_LUTLOADING_FINISHED);

    ctx->PartitionConfig->LookupTable[FEE_30_FLEXNOR_LUTBLOCKID] = ctx->LutChunkLocation; /* SBSW_Fee_30_FlexNor_LookupTableModifications */

    ctx->CurrentState = &Fee_30_FlexNor_LookupTableDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_LookupTable_EndJob();
    ctx->ResultCallback(FEE_30_FLEXNOR_SERVICE_OK); /* SBSW_Fee_30_FlexNor_ContextFunctionPointerCall */
    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

#define FEE_30_FLEXNOR_STOP_SEC_CODE
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: Fee_30_Flexnor_LookupTableMachine.c
 *********************************************************************************************************************/
