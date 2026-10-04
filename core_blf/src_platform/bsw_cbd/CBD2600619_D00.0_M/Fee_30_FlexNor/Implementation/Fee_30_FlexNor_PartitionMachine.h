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
/*!        \file  Fee_30_FlexNor_PartitionMachine.h
 *        \brief  State machine prototypes for the partition unit
 *      \details  Provides the prototypes for the state machine implementation of the partition unit.
 *         \unit  Partition
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 **********************************************************************************************************************/

#if !defined (FEE_30_FLEXNOR_PARTITIONMACHINE_H)
# define FEE_30_FLEXNOR_PARTITIONMACHINE_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Fee_30_FlexNor_PartitionInternal.h"

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
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_InitState()
 *********************************************************************************************************************/
/*! \brief          Initialize the internal state machine
 *  \details        -
 *  \param[in,out]  ctx                   Pointer to the context that shall be initialized. Must not be NULL.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_InitState(Fee_30_FlexNor_Partition_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_DefaultProcessEvent()
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
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_DefaultProcessEvent(Fee_30_FlexNor_Partition_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_DefaultFailEvent()
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
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_DefaultFailEvent(Fee_30_FlexNor_Partition_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_JobFailEvent()
 *********************************************************************************************************************/
/*! \brief       Fail event handler for the read service.
 *  \details     Ends the current job and notifies the caller about the fail of the service.
 *  \param[in]   ctx            Pointer to the context of the service that failed. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_JobFailEvent(Fee_30_FlexNor_Partition_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_InstanceSearchFailEvent()
 *********************************************************************************************************************/
/*! \brief       Fail event handler for the instance search.
 *  \details     Requests a recovery garbage collection if the chunk does not have a valid instance. Otherwise, it
 *               resets the startup. Furthermore it ends the current job and notifies the caller about the fail of the 
 *               service.
 *  \param[in]   ctx            Pointer to the context of the service that failed. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_InstanceSearchFailEvent(
    Fee_30_FlexNor_Partition_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_ResetStartupFailEvent()
 *********************************************************************************************************************/
/*! \brief       Fail event handler for the write service.
 *  \details     Ends the current job, resets the startup of the partition and notifies the caller about the fail of the 
 *               service.
 *  \param[in]   ctx            Pointer to the context of the service that failed. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_ResetStartupFailEvent(Fee_30_FlexNor_Partition_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_StartupJobFailEvent()
 *********************************************************************************************************************/
/*! \brief       Fail event handler for the startup service.
 *  \details     Ends the current job and notifies the caller about the fail of the service.
 *  \param[in]   ctx            Pointer to the context of the service that failed. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_StartupJobFailEvent(Fee_30_FlexNor_Partition_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_StartUp_Initialize()
 *********************************************************************************************************************/
/*! \brief          Initializes the startup state machine
 *  \details        -
 *  \param[in,out]  ctx     Pointer to the context for the state machine processing. Must not be NULL.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_StartUp_Initialize(Fee_30_FlexNor_Partition_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_ReadSectorHeaders_ProcessEvent()
 *********************************************************************************************************************/
/*! \brief          Event handler for the Process event of the ReadSectorHeaders state
 *  \details        -
 *  \param[in,out]  ctx                               Pointer to the context for the state machine processing. Must not be NULL.
 *  \return         FEE_30_FLEXNOR_CONTINUE_SCHEDULE  Let the execution continue
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_ReadSectorHeaders_ProcessEvent(Fee_30_FlexNor_Partition_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_GetLookupTable_ProcessEvent()
 *********************************************************************************************************************/
/*! \brief          Event handler for the Process event of the GetLookupTable state
 *  \details        -
 *  \param[in,out]  ctx                               Pointer to the context for the state machine processing. Must not be NULL.
 *  \return         FEE_30_FLEXNOR_CONTINUE_SCHEDULE  Let the execution continue
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_GetLookupTable_ProcessEvent(Fee_30_FlexNor_Partition_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_ReadBlock_Initialize()
 *********************************************************************************************************************/
/*! \brief          Initializes the read block state machine
 *  \details        -
 *  \param[in,out]  ctx     Pointer to the context for the state machine processing. Must not be NULL.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_ReadBlock_Initialize(Fee_30_FlexNor_Partition_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_SearchLatestChunk_OnEnter()
 *********************************************************************************************************************/
/*! \brief          OnEnter function for SearchLatestChunk state
 *  \details        -
 *  \param[in,out]  ctx     Pointer to the context for the state machine processing. Must not be NULL.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_SearchLatestChunk_OnEnter(Fee_30_FlexNor_Partition_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_SearchLatestChunk_ProcessEvent()
 *********************************************************************************************************************/
/*! \brief          Event handler for the Process event of the SearchLatestChunk state
 *  \details        -
 *  \param[in,out]  ctx                               Pointer to the context for the state machine processing. Must not be NULL.
 *  \return         FEE_30_FLEXNOR_CONTINUE_SCHEDULE  Let the execution continue
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_SearchLatestChunk_ProcessEvent(Fee_30_FlexNor_Partition_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_RecoverLookupTable_ProcessEvent()
 *********************************************************************************************************************/
/*! \brief          Event handler for the Process event of the RecoverLookupTable state
 *  \details        -
 *  \param[in,out]  ctx                               Pointer to the context for the state machine processing. Must not be NULL.
 *  \return         FEE_30_FLEXNOR_CONTINUE_SCHEDULE  Let the execution continue
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_RecoverLookupTable_ProcessEvent(Fee_30_FlexNor_Partition_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_SearchLatestInstance_ProcessEvent()
 *********************************************************************************************************************/
/*! \brief          Event handler for the Process event of the SearchLatestInstance state
 *  \details        -
 *  \param[in,out]  ctx                               Pointer to the context for the state machine processing. Must not be NULL.
 *  \return         FEE_30_FLEXNOR_CONTINUE_SCHEDULE  Let the execution continue
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_SearchLatestInstance_ProcessEvent(Fee_30_FlexNor_Partition_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_ReadLatestInstanceContent_ProcessEvent()
 *********************************************************************************************************************/
/*! \brief          Event handler for the Process event of the ReadLatestInstanceContent state
 *  \details        -
 *  \param[in,out]  ctx                               Pointer to the context for the state machine processing. Must not be NULL.
 *  \return         FEE_30_FLEXNOR_CONTINUE_SCHEDULE  Let the execution continue
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_ReadLatestInstanceContent_ProcessEvent(Fee_30_FlexNor_Partition_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_WriteBlock_Initialize()
 *********************************************************************************************************************/
/*! \brief          Initializes the write block state machine
 *  \details        -
 *  \param[in,out]  ctx     Pointer to the context for the state machine processing. Must not be NULL.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_WriteBlock_Initialize(Fee_30_FlexNor_Partition_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_AllocateInExistingChunk_ProcessEvent()
 *********************************************************************************************************************/
/*! \brief          Event handler for the Process event of the AllocateInExistingChunk state
 *  \details        -
 *  \param[in,out]  ctx                               Pointer to the context for the state machine processing. Must not be NULL.
 *  \return         FEE_30_FLEXNOR_CONTINUE_SCHEDULE  Let the execution continue
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_AllocateInExistingChunk_ProcessEvent(Fee_30_FlexNor_Partition_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_AllocateNewChunk_OnEnter()
 *********************************************************************************************************************/
/*! \brief          OnEnter function for AllocateNewChunk state
 *  \details        -
 *  \param[in,out]  ctx     Pointer to the context for the state machine processing. Must not be NULL.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_AllocateNewChunk_OnEnter(Fee_30_FlexNor_Partition_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_AllocateNewChunk_ProcessEvent()
 *********************************************************************************************************************/
/*! \brief          Event handler for the Process event of the AllocateNewChunk state
 *  \details        -
 *  \param[in,out]  ctx                               Pointer to the context for the state machine processing. Must not be NULL.
 *  \return         FEE_30_FLEXNOR_CONTINUE_SCHEDULE  Let the execution continue
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_AllocateNewChunk_ProcessEvent(Fee_30_FlexNor_Partition_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_GetNewSector_OnEnter()
 *********************************************************************************************************************/
/*! \brief          OnEnter function for GetNewSector state
 *  \details        -
 *  \param[in,out]  ctx     Pointer to the context for the state machine processing. Must not be NULL.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_GetNewSector_OnEnter(Fee_30_FlexNor_Partition_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_GetNewSector_ProcessEvent()
 *********************************************************************************************************************/
/*! \brief          Event handler for the Process event of the GetNewSector state
 *  \details        -
 *  \param[in,out]  ctx                               Pointer to the context for the state machine processing. Must not be NULL.
 *  \return         FEE_30_FLEXNOR_CONTINUE_SCHEDULE  Let the execution continue
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_GetNewSector_ProcessEvent(Fee_30_FlexNor_Partition_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_GarbageCollection_ProcessEvent()
 *********************************************************************************************************************/
/*! \brief          Event handler for the Process event of the GarbageCollection state
 *  \details        -
 *  \param[in,out]  ctx                               Pointer to the context for the state machine processing. Must not be NULL.
 *  \return         FEE_30_FLEXNOR_CONTINUE_SCHEDULE  Let the execution continue
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_GarbageCollection_ProcessEvent(Fee_30_FlexNor_Partition_ContextPtrType ctx);

# define FEE_30_FLEXNOR_STOP_SEC_CODE
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* FEE_30_FLEXNOR_PARTITIONMACHINE_H */

/**********************************************************************************************************************
 *  END OF FILE: Fee_30_FlexNor_PartitionMachine.h
 *********************************************************************************************************************/
