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
/*!        \file  Fee_30_FlexNor_InternalJobsInternal.h
 *        \brief  Internal internal jobs prototypes
 *      \details  Provides the internal prototypes for the business logic of the internal jobs implementation.
 *         \unit  InternalJobs
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 **********************************************************************************************************************/

#if !defined(FEE_30_FLEXNOR_INTERNALJOBSINTERNAL_H)
# define FEE_30_FLEXNOR_INTERNALJOBSINTERNAL_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "Fee_30_FlexNor_Types.h"
# include "Fee_30_FlexNor_ConfigInterface.h"
# include "Fee_30_FlexNor_LookupTable.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef P2VAR(struct Fee_30_FlexNor_InternalJobs_Context, AUTOMATIC, FEE_30_FLEXNOR_VAR)
  Fee_30_FlexNor_InternalJobs_ContextPtrType;
typedef P2CONST(struct Fee_30_FlexNor_InternalJobs_Context, AUTOMATIC, FEE_30_FLEXNOR_VAR)
  Fee_30_FlexNor_InternalJobs_ConstContextPtrType;

/* Module state */
typedef P2FUNC(Fee_30_FlexNor_ScheduleBehaviorType, AUTOMATIC, Fee_30_FlexNor_InternalJobs_ProcessEvt)(
  Fee_30_FlexNor_InternalJobs_ContextPtrType ctx);
typedef P2FUNC(void, AUTOMATIC, Fee_30_FlexNor_InternalJobs_FailEvt)(Fee_30_FlexNor_InternalJobs_ContextPtrType ctx);

typedef struct Fee_30_FlexNor_InternalJobs_State
{
  Fee_30_FlexNor_InternalJobs_ProcessEvt ProcessEvent; /*!< Pointer to the handler for the process event of the state */
  Fee_30_FlexNor_InternalJobs_FailEvt FailEvent;       /*!< Pointer to the handler for the fail event of the state */
} Fee_30_FlexNor_InternalJobs_StateType;               /*!< Represents a state of the internal unit state machine */

typedef CONST(Fee_30_FlexNor_InternalJobs_StateType, AUTOMATIC) Fee_30_FlexNor_InternalJobs_ConstStateType;
typedef P2CONST(Fee_30_FlexNor_InternalJobs_StateType, AUTOMATIC, FEE_30_FLEXNOR_VAR)
  Fee_30_FlexNor_InternalJobs_ConstStatePtrType;

/* Module context */
typedef struct Fee_30_FlexNor_InternalJobs_Context
{
  Fee_30_FlexNor_InternalJobs_ConstStatePtrType CurrentState;  /*!< Current state of the state machine */
  Fee_30_FlexNor_JobPtrType CurrentJob;                        /*!< Pointer to the current job */
  Fee_30_FlexNor_LookupTable_LinkType linkToReallocatedChunk;  /*!< Link to the latest reallocated chunk */
  boolean SuspendRecoveryJobsEnabled;                          /*!< Flag indicating whether suspension of recovery jobs is enabled */
} Fee_30_FlexNor_InternalJobs_ContextType;                     /*!< Represents the context for the internal state machine of the unit */

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
# define FEE_30_FLEXNOR_START_SEC_CODE
# include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Fee_30_FlexNor_InternalJobs_StartJob()
 *********************************************************************************************************************/
/*! \brief       Start a job for the unit
 *  \details     Registers the unit at the scheduler to start the asynchronous processing for the unit.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_InternalJobs_StartJob(void);

/**********************************************************************************************************************
 * Fee_30_FlexNor_InternalJobs_EndJob()
 *********************************************************************************************************************/
/*! \brief       Ends a job for the unit
 *  \details     Unregisters the unit from the scheduler.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_InternalJobs_EndJob(void);

/**********************************************************************************************************************
 * Fee_30_FlexNor_InternalJobs_DefaultProcessEvent()
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
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_InternalJobs_DefaultProcessEvent(
  Fee_30_FlexNor_InternalJobs_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_InternalJobs_DefaultFailEvent()
 *********************************************************************************************************************/
/*! \brief          Default Fail event handler
 *  \details        This function is never called in normal operation. It exists to be able to set the state machine
 *                  to a defined state in case no job is being executed.
 *  \param[in,out]  ctx         Pointer to the context for the state machine processing. Must not be NULL.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_InternalJobs_DefaultFailEvent(
  Fee_30_FlexNor_InternalJobs_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_InternalJobs_JobFailEvent()
 *********************************************************************************************************************/
/*! \brief       Fail event handler
 *  \details     Ends the current job and notifies the caller about the fail of the service.
 *  \param[in]   ctx            Pointer to the context of the service that failed. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_InternalJobs_JobFailEvent(
    Fee_30_FlexNor_InternalJobs_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_InternalJobs_ReallocateChunkFailEvent()
 *********************************************************************************************************************/
/*! \brief       ReallocateChunk fail event handler
 *  \details     Triggers a recovery garbage collection for the sector which contains the chunk whose reallocation 
 *               failed and transitions into the RecoverSector state.  
 *  \param[in]   ctx            Pointer to the context of the service that failed. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_InternalJobs_ReallocateChunkFailEvent(
    Fee_30_FlexNor_InternalJobs_ContextPtrType ctx);


/**********************************************************************************************************************
 * Fee_30_FlexNor_InternalJobs_Startup()
 *********************************************************************************************************************/
/*! \brief       Triggers the start up for the current partition.
 *  \details     -
 *  \param[in]   ctx    Pointer to the context containing the pointer to the current partition configuration. Must not 
 *                      be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_InternalJobs_Startup(
  Fee_30_FlexNor_InternalJobs_ConstContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_InternalJobs_FinishGarbageCollection()
 *********************************************************************************************************************/
/*! \brief       Triggers the garbage collection of the current partition
 *  \details     -
 *  \param[in]   ctx    Pointer to the context containing the pointer to the current partition configuration. Must not 
 *                      be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_InternalJobs_FinishGarbageCollection(
  Fee_30_FlexNor_InternalJobs_ConstContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_InternalJobs_TryTriggerSectorRecovery()
 *********************************************************************************************************************/
/*! \brief       Tries to trigger a sector recovery job for the current partition. 
 *  \details     If a sector recovery job was requested, the job will be forwarded to the garbage collection unit.
 *  \param[in]   ctx    Pointer to the context containing the required data for the sector recovery handling. Must not 
 *                      be NULL.
 *  \pre         -
 *  \return      TRUE   A sector recovery was triggered
 *               FALSE  No sector recovery was triggered
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(boolean, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_InternalJobs_TryTriggerSectorRecovery(
  Fee_30_FlexNor_InternalJobs_ConstContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_InternalJobs_TryTriggerReallocateChunk()
 *********************************************************************************************************************/
/*! \brief       Tries to reallocate a chunk if necessary.
 *  \details     Checks if the reallocation flag is set for the latest chunk of any block of the current partition. In 
 *               this case it triggers a copy service to reallocate the chunk and copy its data into the new chunk.
 *  \param[in]   ctx    Pointer to the context containing the required data for the chunk reallocation handling. 
 *                      Must not be NULL.
 *  \pre         -
 *  \return      TRUE   A chunk reallocation was triggered
 *               FALSE  No chunk reallocation was triggered
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(boolean, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_InternalJobs_TryTriggerReallocateChunk(
  Fee_30_FlexNor_InternalJobs_ContextPtrType ctx);

# define FEE_30_FLEXNOR_STOP_SEC_CODE
# include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* FEE_30_FLEXNOR_INTERNALJOBSINTERNAL_H */

/**********************************************************************************************************************
 *  END OF FILE: Fee_30_FlexNor_InternalJobsInternal.h
 *********************************************************************************************************************/
