/**********************************************************************************************************************
 *  COPYRIGHT
 *  --------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2025 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  --------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/*!        \file  Fee_30_FlexNor_SectorMachine.h
 *        \brief  State machine prototypes for the sector unit
 *      \details  Provides the prototypes for the state machine implementation of the sector unit.
 *         \unit  Sector
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 **********************************************************************************************************************/

#if !defined (FEE_30_FLEXNOR_SECTORMACHINE_H)
# define FEE_30_FLEXNOR_SECTORMACHINE_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Fee_30_FlexNor_SectorInternal.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
# define FEE_30_FLEXNOR_START_SEC_CODE
# include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_InitState()
 *********************************************************************************************************************/
/*! \brief          Initialize the internal state machine
 *  \details        -
 *  \param[in,out]  ctx                   Pointer to the context that shall be initialized. Must not be NULL.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_InitState(Fee_30_FlexNor_Sector_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_DefaultProcessEvent()
 *********************************************************************************************************************/
/*! \brief          Default Process event handler
 *  \details        This function is never called in normal operation. It exists to be able to set the state machine
 *                  to a defined state in case no job is being executed.
 *  \param[in,out]  ctx                           Pointer to the context for the state machine processing. Must not be NULL.
 *  \return         FEE_30_FLEXNOR_STOP_SCHEDULE  Always stops the scheduler
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_DefaultProcessEvent(Fee_30_FlexNor_Sector_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_DefaultFailEvent()
 *********************************************************************************************************************/
/*! \brief          Default Fail event handler
 *  \details        This function is never called in normal operation. It exists to be able to set the state machine
 *                  to a defined state in case no job is being executed.
 *  \param[in,out]  ctx                           Pointer to the context for the state machine processing. Must not be NULL.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_DefaultFailEvent(Fee_30_FlexNor_Sector_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_JobFailEvent()
 *********************************************************************************************************************/
/*! \brief       Fail event handler
 *  \details     Ends the current job and notifies the caller about the fail of the service.
 *  \param[in]   ctx            Pointer to the context of the service that failed. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_JobFailEvent(Fee_30_FlexNor_Sector_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_AllocateChunk_FailEvent()
 *********************************************************************************************************************/
/*! \brief          Fail event handler of the AllocateChunk state
 *  \details        -
 *  \param[in,out]  ctx                               Pointer to the context for the state machine processing. Must not be NULL.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_AllocateChunk_FailEvent(Fee_30_FlexNor_Sector_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_JobFailEventErrorCallback()
 *********************************************************************************************************************/
/*! \brief       Fail event handler additionally invoking a user error callback
 *  \details     Ends the current job, notifies the caller about the fail of the service
 *               and invokes a user error callback.
 *  \param[in]   ctx            Pointer to the context of the service that failed. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_JobFailEventErrorCallback(Fee_30_FlexNor_Sector_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ReadHeader_Initialize()
 *********************************************************************************************************************/
/*! \brief          Initializes the ReadHeader state machine
 *  \details        -
 *  \param[in,out]  ctx     Pointer to the context for the state machine processing. Must not be NULL.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ReadHeader_Initialize(Fee_30_FlexNor_Sector_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ReadMetadata_ProcessEvent()
 *********************************************************************************************************************/
/*! \brief          Event handler for the Process event of the ReadMetadata state
 *  \details        -
 *  \param[in,out]  ctx                               Pointer to the context for the state machine processing. Must not be NULL.
 *  \return         FEE_30_FLEXNOR_CONTINUE_SCHEDULE  Let the execution continue
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ReadMetadata_ProcessEvent(Fee_30_FlexNor_Sector_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ReadMetadata_FailEvent()
 *********************************************************************************************************************/
/*! \brief          Fail event handler of the ReadMetadata state
 *  \details        -
 *  \param[in,out]  ctx                               Pointer to the context for the state machine processing. Must not be NULL.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ReadMetadata_FailEvent(
    Fee_30_FlexNor_Sector_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ReadAdditionalInfo_ProcessEvent()
 *********************************************************************************************************************/
/*! \brief          Event handler for the Process event of the ReadAdditionalInfo state
 *  \details        -
 *  \param[in,out]  ctx                               Pointer to the context for the state machine processing. Must not be NULL.
 *  \return         FEE_30_FLEXNOR_CONTINUE_SCHEDULE  Let the execution continue
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ReadAdditionalInfo_ProcessEvent(Fee_30_FlexNor_Sector_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ReadAdditionalInfo_FailEvent()
 *********************************************************************************************************************/
/*! \brief          Fail event handler of the ReadAdditionalInfo state
 *  \details        -
 *  \param[in,out]  ctx    Pointer to the context for the state machine processing. Must not be NULL.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ReadAdditionalInfo_FailEvent(
    Fee_30_FlexNor_Sector_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ReadEraseMarker_ProcessEvent()
 *********************************************************************************************************************/
/*! \brief          Event handler for the Process event of the ReadEraseMarker state
 *  \details        -
 *  \param[in,out]  ctx    Pointer to the context for the state machine processing. Must not be NULL.
 *  \return         FEE_30_FLEXNOR_CONTINUE_SCHEDULE  Let the execution continue
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ReadEraseMarker_ProcessEvent(Fee_30_FlexNor_Sector_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ReadEraseMarker_FailEvent()
 *********************************************************************************************************************/
/*! \brief          Fail event handler of the ReadEraseMarker state
 *  \details        -
 *  \param[in,out]  ctx    Pointer to the context for the state machine processing. Must not be NULL.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ReadEraseMarker_FailEvent(
    Fee_30_FlexNor_Sector_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ReadProperties_ProcessEvent()
 *********************************************************************************************************************/
/*! \brief          Event handler for the Process event of the ReadProperties state
 *  \details        -
 *  \param[in,out]  ctx    Pointer to the context for the state machine processing. Must not be NULL.
 *  \return         FEE_30_FLEXNOR_CONTINUE_SCHEDULE  Let the execution continue
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ReadProperties_ProcessEvent(Fee_30_FlexNor_Sector_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ReadProperties_FailEvent()
 *********************************************************************************************************************/
/*! \brief          Fail event handler of the ReadProperties state
 *  \details        -
 *  \param[in,out]  ctx    Pointer to the context for the state machine processing. Must not be NULL.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ReadProperties_FailEvent(
    Fee_30_FlexNor_Sector_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ReadCommitMarker_ProcessEvent()
 *********************************************************************************************************************/
/*! \brief          Event handler for the Process event of the ReadCommitMarker state
 *  \details        -
 *  \param[in,out]  ctx                               Pointer to the context for the state machine processing. Must not be NULL.
 *  \return         FEE_30_FLEXNOR_CONTINUE_SCHEDULE  Let the execution continue
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ReadCommitMarker_ProcessEvent(Fee_30_FlexNor_Sector_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ReadCommitMarker_FailEvent()
 *********************************************************************************************************************/
/*! \brief          Fail event handler of the ReadCommitMarker state
 *  \details        -
 *  \param[in,out]  ctx                               Pointer to the context for the state machine processing. Must not be NULL.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ReadCommitMarker_FailEvent(
    Fee_30_FlexNor_Sector_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ReadSealMarker_ProcessEvent()
 *********************************************************************************************************************/
/*! \brief          Event handler for the Process event of the ReadSealMarker state
 *  \details        -
 *  \param[in,out]  ctx    Pointer to the context for the state machine processing. Must not be NULL.
 *  \return         FEE_30_FLEXNOR_CONTINUE_SCHEDULE  Let the execution continue
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ReadSealMarker_ProcessEvent(Fee_30_FlexNor_Sector_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ReadSealMarker_FailEvent()
 *********************************************************************************************************************/
/*! \brief          Fail event handler of the ReadSealMarker state
 *  \details        -
 *  \param[in,out]  ctx    Pointer to the context for the state machine processing. Must not be NULL.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ReadSealMarker_FailEvent(
    Fee_30_FlexNor_Sector_ContextPtrType ctx);


/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ReadLutLink_ProcessEvent()
 *********************************************************************************************************************/
/*! \brief          Event handler for the Process event of the ReadLutLink state
 *  \details        -
 *  \param[in,out]  ctx    Pointer to the context for the state machine processing. Must not be NULL.
 *  \return         FEE_30_FLEXNOR_CONTINUE_SCHEDULE  Let the execution continue
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ReadLutLink_ProcessEvent(Fee_30_FlexNor_Sector_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ReadLutLink_FailEvent()
 *********************************************************************************************************************/
/*! \brief          Fail event handler of the ReadLutLink state
 *  \details        -
 *  \param[in,out]  ctx    Pointer to the context for the state machine processing. Must not be NULL.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ReadLutLink_FailEvent(
    Fee_30_FlexNor_Sector_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ReadSourceSector_ProcessEvent()
 *********************************************************************************************************************/
/*! \brief          Event handler for the Process event of the ReadSourceSector state
 *  \details        -
 *  \param[in,out]  ctx    Pointer to the context for the state machine processing. Must not be NULL.
 *  \return         FEE_30_FLEXNOR_CONTINUE_SCHEDULE  Let the execution continue
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ReadSourceSector_ProcessEvent(Fee_30_FlexNor_Sector_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ReadSourceSector_FailEvent()
 *********************************************************************************************************************/
/*! \brief          Fail event handler of the ReadSourceSector state
 *  \details        -
 *  \param[in,out]  ctx    Pointer to the context for the state machine processing. Must not be NULL.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ReadSourceSector_FailEvent(
    Fee_30_FlexNor_Sector_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_WriteEraseMarker_Initialize()
 *********************************************************************************************************************/
/*! \brief          Initializes the WriteEraseMarker state machine
 *  \details        -
 *  \param[in,out]  ctx     Pointer to the context for the state machine processing. Must not be NULL.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_WriteEraseMarker_Initialize(Fee_30_FlexNor_Sector_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_WriteEraseMarker_ProcessEvent()
 *********************************************************************************************************************/
/*! \brief          Event handler for the Process event of the WriteEraseMarker state
 *  \details        -
 *  \param[in,out]  ctx                               Pointer to the context for the state machine processing. Must not be NULL.
 *  \return         FEE_30_FLEXNOR_CONTINUE_SCHEDULE  Let the execution continue
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_WriteEraseMarker_ProcessEvent(Fee_30_FlexNor_Sector_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_WriteLutLink_Initialize()
 *********************************************************************************************************************/
/*! \brief          Initializes the WriteLutLink state machine
 *  \details        -
 *  \param[in,out]  ctx     Pointer to the context for the state machine processing. Must not be NULL.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_WriteLutLink_Initialize(Fee_30_FlexNor_Sector_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_WriteLutLink_ProcessEvent()
 *********************************************************************************************************************/
/*! \brief          Event handler for the Process event of the WriteLutLink state
 *  \details        -
 *  \param[in,out]  ctx                               Pointer to the context for the state machine processing. Must not be NULL.
 *  \return         FEE_30_FLEXNOR_CONTINUE_SCHEDULE  Let the execution continue
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_WriteLutLink_ProcessEvent(Fee_30_FlexNor_Sector_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_WriteSourceSector_Initialize()
 *********************************************************************************************************************/
/*! \brief          Initializes the WriteSourceSector state machine
 *  \details        -
 *  \param[in,out]  ctx     Pointer to the context for the state machine processing. Must not be NULL.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_WriteSourceSector_Initialize(Fee_30_FlexNor_Sector_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_WriteSourceSector_ProcessEvent()
 *********************************************************************************************************************/
/*! \brief          Event handler for the Process event of the WriteSourceSector state
 *  \details        -
 *  \param[in,out]  ctx                               Pointer to the context for the state machine processing. Must not be NULL.
 *  \return         FEE_30_FLEXNOR_CONTINUE_SCHEDULE  Let the execution continue
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_WriteSourceSector_ProcessEvent(Fee_30_FlexNor_Sector_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_Allocate_Initialize()
 *********************************************************************************************************************/
/*! \brief          Initializes the EraseSector state machine
 *  \details        -
 *  \param[in,out]  ctx     Pointer to the context for the state machine processing. Must not be NULL.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_Allocate_Initialize(Fee_30_FlexNor_Sector_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_EraseSector_ProcessEvent()
 *********************************************************************************************************************/
/*! \brief          Event handler for the Process event of the EraseSector state
 *  \details        -
 *  \param[in,out]  ctx                               Pointer to the context for the state machine processing. Must not be NULL.
 *  \return         FEE_30_FLEXNOR_CONTINUE_SCHEDULE  Let the execution continue
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_EraseSector_ProcessEvent(Fee_30_FlexNor_Sector_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_WriteProperties_ProcessEvent()
 *********************************************************************************************************************/
/*! \brief          Event handler for the Process event of the WriteProperties state
 *  \details        -
 *  \param[in,out]  ctx                               Pointer to the context for the state machine processing. Must not be NULL.
 *  \return         FEE_30_FLEXNOR_CONTINUE_SCHEDULE  Let the execution continue
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_WriteProperties_ProcessEvent(Fee_30_FlexNor_Sector_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_WriteSealMarker_ProcessEvent()
 *********************************************************************************************************************/
/*! \brief          Event handler for the Process event of the WriteSealMarker state
 *  \details        -
 *  \param[in,out]  ctx                               Pointer to the context for the state machine processing. Must not be NULL.
 *  \return         FEE_30_FLEXNOR_CONTINUE_SCHEDULE  Let the execution continue
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_WriteSealMarker_ProcessEvent(Fee_30_FlexNor_Sector_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_WriteCommitMarker_ProcessEvent()
 *********************************************************************************************************************/
/*! \brief          Event handler for the Process event of the WriteCommitMarker state
 *  \details        -
 *  \param[in,out]  ctx                               Pointer to the context for the state machine processing. Must not be NULL.
 *  \return         FEE_30_FLEXNOR_CONTINUE_SCHEDULE  Let the execution continue
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_WriteCommitMarker_ProcessEvent(Fee_30_FlexNor_Sector_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_Scan_Initialize()
 *********************************************************************************************************************/
/*! \brief          Initializes the Scan state machine
 *  \details        -
 *  \param[in,out]  ctx     Pointer to the context for the state machine processing. Must not be NULL.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_Scan_Initialize(Fee_30_FlexNor_Sector_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ValidateChunk_ProcessEvent()
 *********************************************************************************************************************/
/*! \brief          Event handler for the Process event of the ValidateChunk state
 *  \details        -
 *  \param[in,out]  ctx                               Pointer to the context for the state machine processing. Must not be NULL.
 *  \return         FEE_30_FLEXNOR_CONTINUE_SCHEDULE  Let the execution continue
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ValidateChunk_ProcessEvent(Fee_30_FlexNor_Sector_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_TryAllocateChunk_Initialize()
 *********************************************************************************************************************/
/*! \brief          Initializes the TryAllocateChunk state machine
 *  \details        -
 *  \param[in,out]  ctx     Pointer to the context for the state machine processing. Must not be NULL.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_TryAllocateChunk_Initialize(Fee_30_FlexNor_Sector_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_AllocateChunk_ProcessEvent()
 *********************************************************************************************************************/
/*! \brief          Event handler for the Process event of the AllocateChunk state
 *  \details        -
 *  \param[in,out]  ctx                               Pointer to the context for the state machine processing. Must not be NULL.
 *  \return         FEE_30_FLEXNOR_CONTINUE_SCHEDULE  Let the execution continue
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_AllocateChunk_ProcessEvent(Fee_30_FlexNor_Sector_ContextPtrType ctx);

# define FEE_30_FLEXNOR_STOP_SEC_CODE
# include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* FEE_30_FLEXNOR_SECTORMACHINE_H */

/**********************************************************************************************************************
 *  END OF FILE: Fee_30_FlexNor_SectorMachine.h
 *********************************************************************************************************************/
