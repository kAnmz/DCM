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
/*!        \file  Fee_30_FlexNor_Startup.c
 *        \brief  Startup unit implementation
 *      \details  Implementation of the startup services.
 *         \unit  Startup
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/
#define FEE_30_FLEXNOR_STARTUP_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Fee_30_FlexNor_Startup.h"
#include "Fee_30_FlexNor_StartupInternal.h"
#include "Fee_30_FlexNor_StartupMachine.h"

#include "Fee_30_FlexNor_Scheduler.h"
#include "Fee_30_FlexNor_LookupTable.h"
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
#define FEE_30_FLEXNOR_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Context variable of the startup state machine. */
FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_Startup_ContextType Fee_30_FlexNor_StartupStmContext = { 0u }; /* PRQA S 3218 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */

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
 * Fee_30_FlexNor_Startup_ProcessingHandler()
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
    Fee_30_FlexNor_Startup_ProcessingHandler(void);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Startup_LutLoadResultHandler()
 *********************************************************************************************************************/
/*! \brief       Handles the result of the called load lut service
 *  \details     This function is used as a result callback for the load lut service called by this unit.
 *               Load lut result handling requires a different implementation than the generic result handler.
 *  \param[in]   result               Result of the called service
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Startup_LutLoadResultHandler(Fee_30_FlexNor_ServiceResult result);

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * Fee_30_FlexNor_Startup_ProcessingHandler()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FEE_30_FLEXNOR_LOCAL FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) 
    Fee_30_FlexNor_Startup_ProcessingHandler(void)
{
    return Fee_30_FlexNor_StartupStmContext.CurrentState->ProcessEvent(&Fee_30_FlexNor_StartupStmContext); /* SBSW_Fee_30_FlexNor_TriggerEventAtState */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Startup_LutLoadResultHandler()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Startup_LutLoadResultHandler(Fee_30_FlexNor_ServiceResult result)
{
    if(result == FEE_30_FLEXNOR_SERVICE_OK)
    {
        Fee_30_FlexNor_StartupStmContext.LoadingLutSucceeded = TRUE;
    }
    else
    {
        Fee_30_FlexNor_StartupStmContext.LoadingLutSucceeded = FALSE;
    }
}

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * Fee_30_FlexNor_Startup_Init()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Startup_Init(void)
{
    Fee_30_FlexNor_Startup_InitState(&Fee_30_FlexNor_StartupStmContext); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Startup_StartJob()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Startup_StartJob(void)
{
    Fee_30_FlexNor_Scheduler_RegisterUnit(&Fee_30_FlexNor_Startup_ProcessingHandler); /* SBSW_Fee_30_FlexNor_RegisterUnit */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Startup_EndJob()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Startup_EndJob(void)
{
    Fee_30_FlexNor_Scheduler_UnregisterUnit();
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Startup_ResultHandler()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Startup_ResultHandler(Fee_30_FlexNor_ServiceResult result)
{
    if(result == FEE_30_FLEXNOR_SERVICE_FAIL)
    {
        Fee_30_FlexNor_StartupStmContext.CurrentState->FailEvent(&Fee_30_FlexNor_StartupStmContext); /* SBSW_Fee_30_FlexNor_TriggerEventAtState */
    }
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Startup_ReadSectorHeaders()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Startup_ReadSectorHeaders(Fee_30_FlexNor_PartitionIdType partitionId, 
        Fee_30_FlexNor_ResultCallback resultCbk)
{
    Fee_30_FlexNor_StartupStmContext.PartitionConfig = Fee_30_FlexNor_ConfigInterface_GetPartitionConfig(partitionId);
    Fee_30_FlexNor_StartupStmContext.ResultCallback = resultCbk;
    Fee_30_FlexNor_Startup_ReadSectorHeaders_Initialize(&Fee_30_FlexNor_StartupStmContext); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Startup_GetLookupTable()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Startup_GetLookupTable(Fee_30_FlexNor_PartitionIdType partitionId, 
        Fee_30_FlexNor_ResultCallback resultCbk)
{
    Fee_30_FlexNor_StartupStmContext.PartitionConfig = Fee_30_FlexNor_ConfigInterface_GetPartitionConfig(partitionId);
    Fee_30_FlexNor_StartupStmContext.ResultCallback = resultCbk;
    Fee_30_FlexNor_Startup_GetLookupTable_Initialize(&Fee_30_FlexNor_StartupStmContext); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Startup_ReadNextSectorHeader()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Startup_ReadNextSectorHeader(Fee_30_FlexNor_Startup_ContextPtrType ctx)  /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    Fee_30_FlexNor_Sector_ReadHeader(ctx->NextSectorToProcess, &Fee_30_FlexNor_Startup_ResultHandler);  /* SBSW_Fee_30_FlexNor_ResultHandler */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Startup_TriggerLutLoading()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Startup_TriggerLutLoading(Fee_30_FlexNor_Startup_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    Fee_30_FlexNor_LookupTable_Load(ctx->PartitionConfig->PartitionId, &Fee_30_FlexNor_Startup_LutLoadResultHandler); /* SBSW_Fee_30_FlexNor_ResultHandler */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Startup_TriggerLutRecovery()
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
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Startup_TriggerLutRecovery(Fee_30_FlexNor_Startup_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    boolean isLoadedLutSuitableForPartialRecovery = Fee_30_FlexNor_LookupTable_IsLoadedLutSuitableForPartialRecovery(
        ctx->PartitionConfig->PartitionId);

    if((ctx->LoadingLutSucceeded == TRUE) && (isLoadedLutSuitableForPartialRecovery == TRUE))
    {
        Fee_30_FlexNor_LookupTable_PartialRecovery(ctx->PartitionConfig->PartitionId,
            &Fee_30_FlexNor_Startup_ResultHandler); /* SBSW_Fee_30_FlexNor_ResultHandler */
    }
    else
    {
        Fee_30_FlexNor_LookupTable_FullRecovery(ctx->PartitionConfig->PartitionId,
            &Fee_30_FlexNor_Startup_ResultHandler); /* SBSW_Fee_30_FlexNor_ResultHandler */

        Fee_30_FlexNor_LookupTable_RequestPersistLut(ctx->PartitionConfig->PartitionId);
    }
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Startup_IsSectorIdDoubled()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(boolean, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Startup_IsSectorIdDoubled(
    Fee_30_FlexNor_ConstSectorPtrType sectorToCheck) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    boolean isDoubled = FALSE;

    Fee_30_FlexNor_ConstSectorPtrType sector = Fee_30_FlexNor_SectorContainer_GetFirst(sectorToCheck->PartitionId); /* SBSW_Fee_30_FlexNor_ContextPointerAccess */

    while (sector != sectorToCheck)
    {
        if((sector->Validity == FEE_30_FLEXNOR_VALID)
            && (sectorToCheck->Validity == FEE_30_FLEXNOR_VALID)
            && (sector->SectorId == sectorToCheck->SectorId))
        {
            isDoubled = TRUE;
            break;
        }

        sector = Fee_30_FlexNor_SectorContainer_GetNext(sector); /* SBSW_Fee_30_FlexNor_LoopStoredSectors */
    }

    return isDoubled;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Startup_RaiseExceptionIfEraseCycleLimitExceeded()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Startup_RaiseExceptionIfEraseCycleLimitExceeded(
    Fee_30_FlexNor_EraseCycleCounterType eraseCycle, Fee_30_FlexNor_EraseCycleCounterType maximalEraseCycles)
{
    if(eraseCycle > maximalEraseCycles)
    {
        Fee_30_FlexNor_DiagnosticHandler_RaiseWarning(FEE_30_FLEXNOR_DIAGID_MAX_ERASE_CYCLES_REACHED);
    }
    else if((5u * eraseCycle) > (4u * maximalEraseCycles)) /* Check that eraseCycle > 80% maximalEraseCycle without a division. */
    {
        Fee_30_FlexNor_DiagnosticHandler_RaiseWarning(FEE_30_FLEXNOR_DIAGID_MAX_ERASE_CYCLES_ALMOST_REACHED);
    }
    else
    {
        /* No exception occurred. */
    }
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Startup_RaiseExceptionAndInvalidate()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Startup_RaiseExceptionAndInvalidate(
    Fee_30_FlexNor_SectorPtrType sector, Fee_30_FlexNor_ConstPartitionConfigPtrType partitionConfig)
{
    if(Fee_30_FlexNor_Startup_IsSectorIdDoubled(sector) == TRUE) /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    {
        sector->Validity = FEE_30_FLEXNOR_INVALID; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        sector->ErrorLocation = FEE_30_FLEXNOR_SECTOR_ERROR_ERASEMARKERSET; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */

        Fee_30_FlexNor_DiagnosticHandler_RaiseError(FEE_30_FLEXNOR_DIAGID_DOUBLEDSECTORID);
    }

    if(sector->Validity == FEE_30_FLEXNOR_VALID)
    {
        Fee_30_FlexNor_Startup_RaiseExceptionIfEraseCycleLimitExceeded(
            sector->EraseCycle, partitionConfig->MaximalEraseCycles);
    }
}

#define FEE_30_FLEXNOR_STOP_SEC_CODE
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: Fee_30_FlexNor_Startup.c
 *********************************************************************************************************************/
