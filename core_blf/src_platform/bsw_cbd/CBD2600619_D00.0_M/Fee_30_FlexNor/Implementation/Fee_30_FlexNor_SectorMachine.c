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
/*!        \file  Fee_30_FlexNor_SectorMachine.c
 *        \brief  Sector state machine implementation
 *      \details  Provides the implementation of the state machine logic for the sector unit.
 *         \unit  Sector
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#define FEE_30_FLEXNOR_SECTORMACHINE_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Fee_30_FlexNor_SectorMachine.h"
#include "Fee_30_FlexNor_Scheduler.h"
#include "Fee_30_FlexNor_ConfigInterface.h"
#include "Fee_30_FlexNor_LookupTable.h"
#include "Fee_30_FlexNor_Shared.h"
#include "Fee_30_FlexNor_DiagnosticHandler.h"
#include "Fee_30_FlexNor_FlashAccess.h"

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

FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_Sector_ConstStateType Fee_30_FlexNor_SectorDefaultState = {
    &Fee_30_FlexNor_Sector_DefaultProcessEvent,
    &Fee_30_FlexNor_Sector_DefaultFailEvent
};

FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_Sector_ConstStateType Fee_30_FlexNor_SectorReadMetadataState = {   /* PRQA S 3218 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
    &Fee_30_FlexNor_Sector_ReadMetadata_ProcessEvent,
    &Fee_30_FlexNor_Sector_ReadMetadata_FailEvent
};

FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_Sector_ConstStateType Fee_30_FlexNor_SectorReadAdditionalInfoState = {    /* PRQA S 3218 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
    &Fee_30_FlexNor_Sector_ReadAdditionalInfo_ProcessEvent,
    &Fee_30_FlexNor_Sector_ReadAdditionalInfo_FailEvent
};

FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_Sector_ConstStateType Fee_30_FlexNor_SectorReadEraseMarkerState = {   /* PRQA S 3218 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
    &Fee_30_FlexNor_Sector_ReadEraseMarker_ProcessEvent,
    &Fee_30_FlexNor_Sector_ReadEraseMarker_FailEvent
};

FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_Sector_ConstStateType Fee_30_FlexNor_SectorReadPropertiesState = {   /* PRQA S 3218 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
    &Fee_30_FlexNor_Sector_ReadProperties_ProcessEvent,
    &Fee_30_FlexNor_Sector_ReadProperties_FailEvent
};

FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_Sector_ConstStateType Fee_30_FlexNor_SectorReadCommitMarkerState = {   /* PRQA S 3218 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
    &Fee_30_FlexNor_Sector_ReadCommitMarker_ProcessEvent,
    &Fee_30_FlexNor_Sector_ReadCommitMarker_FailEvent
};

FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_Sector_ConstStateType Fee_30_FlexNor_SectorReadSealMarkerState = {   /* PRQA S 3218 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
    &Fee_30_FlexNor_Sector_ReadSealMarker_ProcessEvent,
    &Fee_30_FlexNor_Sector_ReadSealMarker_FailEvent
};

FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_Sector_ConstStateType Fee_30_FlexNor_SectorReadLutLinkState = {   /* PRQA S 3218 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
    &Fee_30_FlexNor_Sector_ReadLutLink_ProcessEvent,
    &Fee_30_FlexNor_Sector_ReadLutLink_FailEvent
};

FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_Sector_ConstStateType Fee_30_FlexNor_SectorReadSourceSectorState = {   /* PRQA S 3218 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
    &Fee_30_FlexNor_Sector_ReadSourceSector_ProcessEvent,
    &Fee_30_FlexNor_Sector_ReadSourceSector_FailEvent
};

FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_Sector_ConstStateType Fee_30_FlexNor_SectorWriteEraseMarkerState = {    /* PRQA S 3218 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
    &Fee_30_FlexNor_Sector_WriteEraseMarker_ProcessEvent,
    &Fee_30_FlexNor_Sector_JobFailEvent
};

FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_Sector_ConstStateType Fee_30_FlexNor_SectorWriteLutLinkState = {    /* PRQA S 3218 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
    &Fee_30_FlexNor_Sector_WriteLutLink_ProcessEvent,
    &Fee_30_FlexNor_Sector_JobFailEvent
};

FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_Sector_ConstStateType Fee_30_FlexNor_SectorWriteSourceSectorState = {    /* PRQA S 3218 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
    &Fee_30_FlexNor_Sector_WriteSourceSector_ProcessEvent,
    &Fee_30_FlexNor_Sector_JobFailEvent
};

FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_Sector_ConstStateType Fee_30_FlexNor_SectorEraseSectorState = {    /* PRQA S 3218 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
    &Fee_30_FlexNor_Sector_EraseSector_ProcessEvent,
    &Fee_30_FlexNor_Sector_JobFailEventErrorCallback
};

FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_Sector_ConstStateType Fee_30_FlexNor_SectorWritePropertiesState = {    /* PRQA S 3218 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
    &Fee_30_FlexNor_Sector_WriteProperties_ProcessEvent,
    &Fee_30_FlexNor_Sector_JobFailEventErrorCallback
};

FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_Sector_ConstStateType Fee_30_FlexNor_SectorWriteSealMarkerState = {    /* PRQA S 3218 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
    &Fee_30_FlexNor_Sector_WriteSealMarker_ProcessEvent,
    &Fee_30_FlexNor_Sector_JobFailEventErrorCallback
};

FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_Sector_ConstStateType Fee_30_FlexNor_SectorWriteCommitMarkerState = {    /* PRQA S 3218 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
    &Fee_30_FlexNor_Sector_WriteCommitMarker_ProcessEvent,
    &Fee_30_FlexNor_Sector_JobFailEventErrorCallback
};

FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_Sector_ConstStateType Fee_30_FlexNor_SectorValidateChunkState = {    /* PRQA S 3218 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
    &Fee_30_FlexNor_Sector_ValidateChunk_ProcessEvent,
    &Fee_30_FlexNor_Sector_JobFailEvent
};

FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_Sector_ConstStateType Fee_30_FlexNor_SectorAllocateChunkState = {    /* PRQA S 3218 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
    &Fee_30_FlexNor_Sector_AllocateChunk_ProcessEvent,
    &Fee_30_FlexNor_Sector_AllocateChunk_FailEvent
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
 * Fee_30_FlexNor_Sector_EndJobExtended()
 *********************************************************************************************************************/
/*! \brief          Ending job helper function
 *  \details        -
 *  \param[in,out]  ctx      Pointer to the context for the state machine processing. Must not be NULL.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FEE_30_FLEXNOR_LOCAL_INLINE FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_EndJobExtended(
    Fee_30_FlexNor_Sector_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_EndReadJob()
 *********************************************************************************************************************/
/*! \brief          Ending job helper function for failing read jobs.
 *  \details        -
 *  \param[in,out]  ctx      Pointer to the context for the state machine processing. Must not be NULL.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FEE_30_FLEXNOR_LOCAL_INLINE FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_EndReadJob(
    Fee_30_FlexNor_Sector_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_EndJobExtended()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FEE_30_FLEXNOR_LOCAL_INLINE FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_EndJobExtended(Fee_30_FlexNor_Sector_ContextPtrType ctx)
{
    ctx->CurrentState = &Fee_30_FlexNor_SectorDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_Sector_EndJob();
    ctx->ResultCallback(FEE_30_FLEXNOR_SERVICE_OK); /* SBSW_Fee_30_FlexNor_ContextFunctionPointerCall */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_EndReadJob()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FEE_30_FLEXNOR_LOCAL_INLINE FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_EndReadJob(
    Fee_30_FlexNor_Sector_ContextPtrType ctx)
{
    if(Fee_30_FlexNor_FlashAccess_GetReadJobResult() == FEE_30_FLEXNOR_FLASH_ECCERROR)
    {
        Fee_30_FlexNor_Sector_EndJobExtended(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }
    else /* FEE_30_FLEXNOR_FLASH_FAIL */
    {
        Fee_30_FlexNor_Sector_JobFailEvent(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }
}

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_InitState()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_InitState(Fee_30_FlexNor_Sector_ContextPtrType ctx)
{
    ctx->CurrentState = &Fee_30_FlexNor_SectorDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_DefaultProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_DefaultProcessEvent(Fee_30_FlexNor_Sector_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    FEE_DUMMY_STATEMENT(ctx);
    return FEE_30_FLEXNOR_STOP_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_DefaultFailEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_DefaultFailEvent(Fee_30_FlexNor_Sector_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    FEE_DUMMY_STATEMENT(ctx);
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_JobFailEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_JobFailEvent(Fee_30_FlexNor_Sector_ContextPtrType ctx)
{
    ctx->CurrentState = &Fee_30_FlexNor_SectorDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_Sector_EndJob();
    ctx->ResultCallback(FEE_30_FLEXNOR_SERVICE_FAIL); /* SBSW_Fee_30_FlexNor_ContextFunctionPointerCall */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_JobFailEventErrorCallback()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_JobFailEventErrorCallback(Fee_30_FlexNor_Sector_ContextPtrType ctx)
{
    Fee_30_FlexNor_Scheduler_AllowCancel();
    Fee_30_FlexNor_Sector_JobFailEvent(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    Fee_30_FlexNor_ConfigInterface_UserErrorCallback();
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ReadHeader_Initialize()
 *********************************************************************************************************************/
/*!
 * Internal comment removed. *
 *
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ReadHeader_Initialize(Fee_30_FlexNor_Sector_ContextPtrType ctx)
{
    Fee_30_FlexNor_ConstPartitionConfigPtrType partitionConfig = Fee_30_FlexNor_ConfigInterface_GetPartitionConfig(ctx->Sector->PartitionId);

    Fee_30_FlexNor_Sector_StartJob();

    if (partitionConfig->BlankCheckRequired == TRUE)
    {
        /* The properties validation function reads the erase cycle counter from the memory. As long as the properties are
           valid, the value is used for the allocation of the next sector, even if the erase marker is set. To make
           sure that this value is available, the properties are validated first. */
        ctx->CurrentState = &Fee_30_FlexNor_SectorReadPropertiesState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        Fee_30_FlexNor_Sector_ReadProperties(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }
    else
    {
        ctx->CurrentState = &Fee_30_FlexNor_SectorReadMetadataState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        Fee_30_FlexNor_Sector_ReadMetadata(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ReadMetadata_ProcessEvent()
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
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ReadMetadata_ProcessEvent(Fee_30_FlexNor_Sector_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    Fee_30_FlexNor_Sector_ErrorLocation validationResult = Fee_30_FlexNor_Sector_ValidateMetadata(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */

    if(validationResult == FEE_30_FLEXNOR_SECTOR_ERROR_NOERROR)
    {
        ctx->CurrentState = &Fee_30_FlexNor_SectorReadAdditionalInfoState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        Fee_30_FlexNor_Sector_ReadAdditionalInfo(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }
    else /* SectorInvalid or SectorValidAndGarbageCollection */
    {
        Fee_30_FlexNor_Sector_EndJobExtended(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
        Fee_30_FlexNor_DiagnosticHandler_SetCurrentMilestone(FEE_30_FLEXNOR_DIAGMST_READ_SECTOR_HEADER_FINISHED);
    }

    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ReadMetadata_FailEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ReadMetadata_FailEvent(Fee_30_FlexNor_Sector_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    if(Fee_30_FlexNor_FlashAccess_GetReadJobResult() == FEE_30_FLEXNOR_FLASH_ECCERROR)
    {
        ctx->CurrentState = &Fee_30_FlexNor_SectorReadPropertiesState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        Fee_30_FlexNor_Sector_ReadProperties(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }
    else /* FEE_30_FLEXNOR_FLASH_FAIL */
    {
        Fee_30_FlexNor_Sector_JobFailEvent(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ReadAdditionalInfo_ProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ReadAdditionalInfo_ProcessEvent(Fee_30_FlexNor_Sector_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    Fee_30_FlexNor_Sector_ParseAdditionalInfo(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    Fee_30_FlexNor_Sector_EndJobExtended(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */

    Fee_30_FlexNor_DiagnosticHandler_SetCurrentMilestone(FEE_30_FLEXNOR_DIAGMST_READ_SECTOR_HEADER_FINISHED);
    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ReadAdditionalInfo_FailEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ReadAdditionalInfo_FailEvent(Fee_30_FlexNor_Sector_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    ctx->Sector->LutChunkLink.Validity = FEE_30_FLEXNOR_INVALID; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    ctx->Sector->SourceSectorId = FEE_30_FLEXNOR_SECTOR_ID_INVALID; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */

    Fee_30_FlexNor_Sector_EndReadJob(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ReadProperties_ProcessEvent()
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
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ReadProperties_ProcessEvent(Fee_30_FlexNor_Sector_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    Fee_30_FlexNor_StructureValidityType propertiesValidity = Fee_30_FlexNor_Sector_ValidateMetadataProperties(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */

    if(propertiesValidity == FEE_30_FLEXNOR_VALID)
    {
        ctx->Sector->ErrorLocation = FEE_30_FLEXNOR_SECTOR_ERROR_NOERROR; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        ctx->Sector->Validity = FEE_30_FLEXNOR_VALID; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */

        ctx->CurrentState = &Fee_30_FlexNor_SectorReadEraseMarkerState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        Fee_30_FlexNor_Sector_ReadEraseMarker(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }
    else
    {
        ctx->Sector->ErrorLocation = FEE_30_FLEXNOR_SECTOR_ERROR_PROPERTIESINVALID; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        ctx->Sector->Validity = FEE_30_FLEXNOR_INVALID; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */

        Fee_30_FlexNor_Sector_EndJobExtended(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */

        Fee_30_FlexNor_DiagnosticHandler_SetCurrentMilestone(FEE_30_FLEXNOR_DIAGMST_READ_SECTOR_HEADER_FINISHED);
    }

    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ReadProperties_FailEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ReadProperties_FailEvent(Fee_30_FlexNor_Sector_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    ctx->Sector->ErrorLocation = FEE_30_FLEXNOR_SECTOR_ERROR_PROPERTIESINVALID; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    ctx->Sector->Validity = FEE_30_FLEXNOR_INVALID; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */

    Fee_30_FlexNor_Sector_EndReadJob(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ReadEraseMarker_ProcessEvent()
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
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ReadEraseMarker_ProcessEvent(Fee_30_FlexNor_Sector_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    Fee_30_FlexNor_Sector_ErrorLocation validationResult = Fee_30_FlexNor_Sector_ValidateEraseMarker(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */

    if(validationResult == FEE_30_FLEXNOR_SECTOR_ERROR_NOERROR)
    {
        ctx->CurrentState = &Fee_30_FlexNor_SectorReadCommitMarkerState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        Fee_30_FlexNor_Sector_ReadCommitMarker(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }
    else
    {
        Fee_30_FlexNor_Sector_EndJobExtended(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
        Fee_30_FlexNor_DiagnosticHandler_SetCurrentMilestone(FEE_30_FLEXNOR_DIAGMST_READ_SECTOR_HEADER_FINISHED);
    }

    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ReadEraseMarker_FailEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ReadEraseMarker_FailEvent(Fee_30_FlexNor_Sector_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    ctx->Sector->ErrorLocation = FEE_30_FLEXNOR_SECTOR_ERROR_ERASEMARKERSET; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    ctx->Sector->Validity = FEE_30_FLEXNOR_INVALID; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */

    Fee_30_FlexNor_Sector_EndReadJob(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ReadCommitMarker_ProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ReadCommitMarker_ProcessEvent(Fee_30_FlexNor_Sector_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    Fee_30_FlexNor_Sector_ErrorLocation validationResult = Fee_30_FlexNor_Sector_ValidateCommitMarker(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */

    if(validationResult == FEE_30_FLEXNOR_SECTOR_ERROR_NOERROR)
    {
        ctx->CurrentState = &Fee_30_FlexNor_SectorReadLutLinkState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        Fee_30_FlexNor_Sector_ReadLutLink(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }
    else /* CommitMarker empty / Commit Marker invalid */
    {
        ctx->CurrentState = &Fee_30_FlexNor_SectorReadSealMarkerState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        Fee_30_FlexNor_Sector_ReadSealMarker(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }

    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ReadCommitMarker_FailEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ReadCommitMarker_FailEvent(Fee_30_FlexNor_Sector_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    if(Fee_30_FlexNor_FlashAccess_GetReadJobResult() == FEE_30_FLEXNOR_FLASH_ECCERROR)
    {
        ctx->CurrentState = &Fee_30_FlexNor_SectorReadSealMarkerState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        Fee_30_FlexNor_Sector_ReadSealMarker(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }
    else /* FEE_30_FLEXNOR_FLASH_FAIL */
    {
        Fee_30_FlexNor_Sector_JobFailEvent(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ReadSealMarker_ProcessEvent()
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
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ReadSealMarker_ProcessEvent(Fee_30_FlexNor_Sector_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    Fee_30_FlexNor_Sector_ErrorLocation sealMarkerValidity = Fee_30_FlexNor_Sector_ValidateSealMarker(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */

    if (sealMarkerValidity == FEE_30_FLEXNOR_SECTOR_ERROR_NOERROR)
    {
        ctx->CurrentState = &Fee_30_FlexNor_SectorReadLutLinkState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        Fee_30_FlexNor_Sector_ReadLutLink(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }
    else
    {
        ctx->Sector->ErrorLocation = FEE_30_FLEXNOR_SECTOR_ERROR_SEALMARKERBROKEN; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        Fee_30_FlexNor_Sector_EndJobExtended(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
        Fee_30_FlexNor_DiagnosticHandler_SetCurrentMilestone(FEE_30_FLEXNOR_DIAGMST_READ_SECTOR_HEADER_FINISHED);
    }

    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ReadSealMarker_FailEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ReadSealMarker_FailEvent(Fee_30_FlexNor_Sector_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    ctx->Sector->ErrorLocation = FEE_30_FLEXNOR_SECTOR_ERROR_SEALMARKERBROKEN; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    ctx->Sector->Validity = FEE_30_FLEXNOR_INVALID; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_Sector_EndReadJob(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ReadLutLink_ProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ReadLutLink_ProcessEvent(Fee_30_FlexNor_Sector_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    Fee_30_FlexNor_Sector_ParseAdditionalInfoLutLink(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    ctx->CurrentState = &Fee_30_FlexNor_SectorReadSourceSectorState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_Sector_ReadSourceSector(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */

    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ReadLutLink_FailEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ReadLutLink_FailEvent(Fee_30_FlexNor_Sector_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    ctx->Sector->LutChunkLink.Validity = FEE_30_FLEXNOR_INVALID; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    ctx->Sector->SourceSectorId = FEE_30_FLEXNOR_SECTOR_ID_INVALID; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */

    Fee_30_FlexNor_Sector_EndReadJob(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ReadSourceSector_ProcessEvent()
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
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ReadSourceSector_ProcessEvent(Fee_30_FlexNor_Sector_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    Fee_30_FlexNor_AddressType alignedSourceSectorStartIndex = 0u;
    Fee_30_FlexNor_Sector_ParseAdditionalInfoSourceSector(ctx, alignedSourceSectorStartIndex); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */

    Fee_30_FlexNor_Sector_EndJobExtended(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */

    Fee_30_FlexNor_DiagnosticHandler_SetCurrentMilestone(FEE_30_FLEXNOR_DIAGMST_READ_SECTOR_HEADER_FINISHED);

    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ReadSourceSector_FailEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ReadSourceSector_FailEvent(Fee_30_FlexNor_Sector_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    ctx->Sector->SourceSectorId = FEE_30_FLEXNOR_SECTOR_ID_INVALID; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */

    Fee_30_FlexNor_Sector_EndReadJob(ctx); /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_WriteEraseMarker_Initialize()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_WriteEraseMarker_Initialize(Fee_30_FlexNor_Sector_ContextPtrType ctx)
{
    Fee_30_FlexNor_Sector_StartJob();
    ctx->CurrentState = &Fee_30_FlexNor_SectorWriteEraseMarkerState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_Sector_WriteEraseMarkerToMemory(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_WriteEraseMarker_ProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_WriteEraseMarker_ProcessEvent(Fee_30_FlexNor_Sector_ContextPtrType ctx)
{
    ctx->Sector->Validity = FEE_30_FLEXNOR_INVALID; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    ctx->Sector->ErrorLocation = FEE_30_FLEXNOR_SECTOR_ERROR_ERASEMARKERSET; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */

    Fee_30_FlexNor_Sector_EndJobExtended(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */

    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_WriteLutLink_Initialize()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_WriteLutLink_Initialize(Fee_30_FlexNor_Sector_ContextPtrType ctx)
{
    Fee_30_FlexNor_Sector_StartJob();
    ctx->CurrentState = &Fee_30_FlexNor_SectorWriteLutLinkState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_Sector_WriteLutLinkToMemory(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_WriteLutLink_ProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_WriteLutLink_ProcessEvent(Fee_30_FlexNor_Sector_ContextPtrType ctx)
{
    Fee_30_FlexNor_Sector_EndJobExtended(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */

    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_WriteSourceSector_Initialize()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_WriteSourceSector_Initialize(Fee_30_FlexNor_Sector_ContextPtrType ctx)
{
    Fee_30_FlexNor_Sector_StartJob();
    ctx->CurrentState = &Fee_30_FlexNor_SectorWriteSourceSectorState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_Sector_WriteSourceSectorToMemory(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_WriteSourceSector_ProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_WriteSourceSector_ProcessEvent(Fee_30_FlexNor_Sector_ContextPtrType ctx)
{
    Fee_30_FlexNor_Sector_EndJobExtended(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */

    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_Allocate_Initialize()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_Allocate_Initialize(Fee_30_FlexNor_Sector_ContextPtrType ctx)
{
    Fee_30_FlexNor_Sector_StartJob();
    Fee_30_FlexNor_Scheduler_DenyCancel();

    Fee_30_FlexNor_Sector_ResetRecoveryGarbageCollection(ctx->Sector); /* SBSW_Fee_30_FlexNor_ContextPointerAccess */

    ctx->CurrentState = &Fee_30_FlexNor_SectorEraseSectorState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_Sector_EraseSector(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_EraseSector_ProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_EraseSector_ProcessEvent(Fee_30_FlexNor_Sector_ContextPtrType ctx)
{
    ctx->CurrentState = &Fee_30_FlexNor_SectorWritePropertiesState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_Sector_WritePropertiesToMemory(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_WriteProperties_ProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_WriteProperties_ProcessEvent(Fee_30_FlexNor_Sector_ContextPtrType ctx)
{
    ctx->CurrentState = &Fee_30_FlexNor_SectorWriteSealMarkerState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_Sector_WriteSealMarkerToMemory(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_WriteSealMarker_ProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_WriteSealMarker_ProcessEvent(Fee_30_FlexNor_Sector_ContextPtrType ctx)
{
    ctx->CurrentState = &Fee_30_FlexNor_SectorWriteCommitMarkerState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_Sector_WriteCommitMarkerToMemory(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_WriteCommitMarker_ProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_WriteCommitMarker_ProcessEvent(Fee_30_FlexNor_Sector_ContextPtrType ctx)
{
    Fee_30_FlexNor_Scheduler_AllowCancel();

    ctx->Sector->Validity = FEE_30_FLEXNOR_VALID; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    ctx->Sector->ErrorLocation = FEE_30_FLEXNOR_SECTOR_ERROR_NOERROR; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    ctx->Sector->NextFreeAddress = Fee_30_FlexNor_Sector_GetFirstFreeAddress(ctx); /* SBSW_Fee_30_FlexNor_ContextPointerAccess */ /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */

    Fee_30_FlexNor_Sector_EndJobExtended(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */

    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_Scan_Initialize()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_Scan_Initialize(Fee_30_FlexNor_Sector_ContextPtrType ctx)
{
    Fee_30_FlexNor_Sector_StartJob();
    ctx->CurrentState = &Fee_30_FlexNor_SectorValidateChunkState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */

    Fee_30_FlexNor_Sector_ReadChunkHeader(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ValidateChunk_ProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ValidateChunk_ProcessEvent(Fee_30_FlexNor_Sector_ContextPtrType ctx)
{
    Fee_30_FlexNor_Sector_ScanCurrentResult currentResult = Fee_30_FlexNor_Sector_ProcessReadChunkHeader(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */

    if(currentResult == FEE_30_FLEXNOR_SECTOR_SCAN_CONTINUE)
    {
        Fee_30_FlexNor_Sector_ReadChunkHeader(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }
    else
    {
        Fee_30_FlexNor_Sector_EndJobExtended(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }

    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_TryAllocateChunk_Initialize()
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
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_TryAllocateChunk_Initialize(Fee_30_FlexNor_Sector_ContextPtrType ctx)
{
    if((ctx->Sector->Validity == FEE_30_FLEXNOR_VALID) && (ctx->Sector->NextFreeAddress != 0x0u))
    {
        Fee_30_FlexNor_Sector_SetInstanceCountInChunkToAllocate(ctx->Chunk, ctx->PredecessorChunk, ctx->Sector, ctx->resetInstanceCount); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */

        if(ctx->Chunk->Data.InstanceCount != FEE_30_FLEXNOR_SECTOR_INVALID_INSTANCE_COUNT)
        {
            Fee_30_FlexNor_Scheduler_DenyCancel();

            Fee_30_FlexNor_Sector_StartJob();
            ctx->CurrentState = &Fee_30_FlexNor_SectorAllocateChunkState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
            Fee_30_FlexNor_Sector_TriggerChunkAllocation(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
        }
        else
        {
            ctx->ResultCallback(FEE_30_FLEXNOR_SERVICE_NOT_OK); /* SBSW_Fee_30_FlexNor_ContextFunctionPointerCall */
        }
    }
    else
    {
        ctx->ResultCallback(FEE_30_FLEXNOR_SERVICE_NOT_OK); /* SBSW_Fee_30_FlexNor_ContextFunctionPointerCall */
    }
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_AllocateChunk_ProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_AllocateChunk_ProcessEvent(
    Fee_30_FlexNor_Sector_ContextPtrType ctx)
{
    Fee_30_FlexNor_Scheduler_AllowCancel();
    Fee_30_FlexNor_Sector_UpdateLookupTableAndNewChunkCounter(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    Fee_30_FlexNor_Sector_EndJobExtended(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */

    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_AllocateChunk_FailEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_AllocateChunk_FailEvent(Fee_30_FlexNor_Sector_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    Fee_30_FlexNor_Scheduler_AllowCancel();
    ctx->Sector->NextFreeAddress = 0u; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_LookupTable_Invalidate(ctx->Chunk->Data.PartitionId);
    Fee_30_FlexNor_Sector_JobFailEvent(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

#define FEE_30_FLEXNOR_STOP_SEC_CODE
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: Fee_30_FlexNor_ChunkMachine.c
 *********************************************************************************************************************/
