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
/*!        \file  Fee_30_FlexNor_StartupMachine.c
 *        \brief  Startup state machine implementation
 *      \details  Provides the implementation of the state machine logic for the startup unit.
 *         \unit  Startup
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/
#define FEE_30_FLEXNOR_STARTUPMACHINE_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Fee_30_FlexNor_StartupMachine.h"
#include "Fee_30_FlexNor_SectorContainer.h"
#include "Fee_30_FlexNor_Shared.h"

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

FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_Startup_ConstStateType Fee_30_FlexNor_StartupDefaultState = {
    &Fee_30_FlexNor_Startup_DefaultProcessEvent,
    &Fee_30_FlexNor_Startup_DefaultFailEvent
};

FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_Startup_ConstStateType Fee_30_FlexNor_StartupReadSectorHeaderState = {   /* PRQA S 3218 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
    &Fee_30_FlexNor_Startup_ReadSectorHeader_ProcessEvent,
    &Fee_30_FlexNor_Startup_JobFailEvent
};

FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_Startup_ConstStateType Fee_30_FlexNor_StartupLoadLutState = {   /* PRQA S 3218 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
    &Fee_30_FlexNor_Startup_LoadLut_ProcessEvent,
    &Fee_30_FlexNor_Startup_JobFailEvent
};

FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_Startup_ConstStateType Fee_30_FlexNor_StartupRecoverLutState = {   /* PRQA S 3218 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
    &Fee_30_FlexNor_Startup_RecoverLut_ProcessEvent,
    &Fee_30_FlexNor_Startup_JobFailEvent
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
 * Fee_30_FlexNor_Startup_InitState()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Startup_InitState(Fee_30_FlexNor_Startup_ContextPtrType ctx)
{
    ctx->CurrentState = &Fee_30_FlexNor_StartupDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Startup_DefaultProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Startup_DefaultProcessEvent(
        Fee_30_FlexNor_Startup_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    FEE_DUMMY_STATEMENT(ctx);
    return FEE_30_FLEXNOR_STOP_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Startup_DefaultFailEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Startup_DefaultFailEvent(Fee_30_FlexNor_Startup_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    FEE_DUMMY_STATEMENT(ctx);
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Startup_JobFailEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Startup_JobFailEvent(Fee_30_FlexNor_Startup_ContextPtrType ctx)
{
    ctx->CurrentState = &Fee_30_FlexNor_StartupDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_Startup_EndJob();
    ctx->ResultCallback(FEE_30_FLEXNOR_SERVICE_FAIL); /* SBSW_Fee_30_FlexNor_ContextFunctionPointerCall */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Startup_ReadSectorHeader_Initialize()
 *********************************************************************************************************************/
/*!
 * Internal comment removed. *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Startup_ReadSectorHeaders_Initialize(
    Fee_30_FlexNor_Startup_ContextPtrType ctx)
{
    Fee_30_FlexNor_Startup_StartJob();
    ctx->NextSectorToProcess = Fee_30_FlexNor_SectorContainer_GetFirst(ctx->PartitionConfig->PartitionId); /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    ctx->CurrentState = &Fee_30_FlexNor_StartupReadSectorHeaderState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_Startup_ReadNextSectorHeader(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Startup_ReadSectorHeaders_ProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Startup_ReadSectorHeader_ProcessEvent(
    Fee_30_FlexNor_Startup_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    Fee_30_FlexNor_Startup_RaiseExceptionAndInvalidate(ctx->NextSectorToProcess, ctx->PartitionConfig); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */

    ctx->NextSectorToProcess = Fee_30_FlexNor_SectorContainer_GetNext(ctx->NextSectorToProcess); /* SBSW_Fee_30_FlexNor_ContextPointerAccess */ /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */

    if(ctx->NextSectorToProcess == NULL_PTR)
    {
        ctx->CurrentState = &Fee_30_FlexNor_StartupDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        Fee_30_FlexNor_Startup_EndJob();
        ctx->ResultCallback(FEE_30_FLEXNOR_SERVICE_OK); /* SBSW_Fee_30_FlexNor_ContextFunctionPointerCall */
    }
    else
    {
        Fee_30_FlexNor_Startup_ReadNextSectorHeader(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }

    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Startup_GetLookupTable_Initialize()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Startup_GetLookupTable_Initialize(
        Fee_30_FlexNor_Startup_ContextPtrType ctx)
{
    Fee_30_FlexNor_Startup_StartJob();

    ctx->CurrentState = &Fee_30_FlexNor_StartupLoadLutState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_Startup_TriggerLutLoading(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Startup_LoadLut_ProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Startup_LoadLut_ProcessEvent(
    Fee_30_FlexNor_Startup_ContextPtrType ctx)
{
    ctx->CurrentState = &Fee_30_FlexNor_StartupRecoverLutState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_Startup_TriggerLutRecovery(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Startup_RecoverLut_ProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Startup_RecoverLut_ProcessEvent(
    Fee_30_FlexNor_Startup_ContextPtrType ctx)
{
    Fee_30_FlexNor_Startup_EndJob();

    ctx->CurrentState = &Fee_30_FlexNor_StartupDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    ctx->ResultCallback(FEE_30_FLEXNOR_SERVICE_OK); /* SBSW_Fee_30_FlexNor_ContextFunctionPointerCall */

    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

#define FEE_30_FLEXNOR_STOP_SEC_CODE
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: Fee_30_FlexNor_StartupMachine.c
 *********************************************************************************************************************/
