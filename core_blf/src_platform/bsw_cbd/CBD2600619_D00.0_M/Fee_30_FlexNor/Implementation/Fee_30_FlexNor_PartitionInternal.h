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
/*!        \file  Fee_30_FlexNor_PartitionInternal.h
 *        \brief  Internal partition prototypes
 *      \details  Provides the internal prototypes for the business logic of the partition implementation.
 *         \unit  Partition
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 **********************************************************************************************************************/

#if !defined (FEE_30_FLEXNOR_PARTITIONINTERNAL_H)
# define FEE_30_FLEXNOR_PARTITIONINTERNAL_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Fee_30_FlexNor_Types.h"
#include "Fee_30_FlexNor_ConfigInterface.h"
#include "Fee_30_FlexNor_Sector.h"
#include "Fee_30_FlexNor_Chunk.h"
#include "Fee_30_FlexNor_Instance.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef struct Fee_30_FlexNor_Partition_Flags
{
    boolean StartupExecuted;                        /*!< Flag indicating whether the startup has already been executed */
} Fee_30_FlexNor_Partition_FlagsType;               /*!< Contains different flags for a partition to represent its state */

typedef P2VAR(Fee_30_FlexNor_Partition_FlagsType, AUTOMATIC, FEE_30_FLEXNOR_VAR) Fee_30_FlexNor_Partition_FlagsPtrType;

typedef P2VAR(struct Fee_30_FlexNor_Partition_Context, AUTOMATIC, FEE_30_FLEXNOR_VAR) Fee_30_FlexNor_Partition_ContextPtrType;
typedef P2CONST(struct Fee_30_FlexNor_Partition_Context, AUTOMATIC, FEE_30_FLEXNOR_VAR) Fee_30_FlexNor_Partition_ConstContextPtrType;

typedef P2FUNC(void, AUTOMATIC, Fee_30_FlexNor_Partition_ActionPtrType)(Fee_30_FlexNor_Partition_ContextPtrType ctx);

/* Module state */
typedef P2FUNC(Fee_30_FlexNor_ScheduleBehaviorType, AUTOMATIC, Fee_30_FlexNor_Partition_ProcessEvt)(Fee_30_FlexNor_Partition_ContextPtrType ctx);
typedef P2FUNC(void, AUTOMATIC, Fee_30_FlexNor_Partition_FailEvt)(Fee_30_FlexNor_Partition_ContextPtrType ctx);

typedef struct Fee_30_FlexNor_Partition_State
{
    Fee_30_FlexNor_Partition_ProcessEvt ProcessEvent;     /*!< Pointer to the handler for the process event of the state */
    Fee_30_FlexNor_Partition_FailEvt FailEvent;           /*!< Pointer to the handler for the fail event of the state */
} Fee_30_FlexNor_Partition_StateType;                     /*!< Represents a state of the internal unit state machine */

typedef CONST(Fee_30_FlexNor_Partition_StateType, AUTOMATIC) Fee_30_FlexNor_Partition_ConstStateType;
typedef P2CONST(Fee_30_FlexNor_Partition_StateType, AUTOMATIC, FEE_30_FLEXNOR_VAR) Fee_30_FlexNor_Partition_ConstStatePtrType;

/* Module context */
typedef struct Fee_30_FlexNor_Partition_Context
{
    Fee_30_FlexNor_Partition_FlagsPtrType Flags;                    /*!< State flags for all configured partition */

    Fee_30_FlexNor_ChunkType LatestChunk;                           /*!< Chunk that stores the latest chunk found for the block that is processed in the current job */
    Fee_30_FlexNor_ChunkType ChunkToAllocate;                       /*!< Chunk that is used for allocation routines */
    Fee_30_FlexNor_InstanceType Instance;                           /*!< Instance which will be used during the processing of services */
    Fee_30_FlexNor_SectorPtrType TargetSector;                      /*!< Pointer to the sector that is currently used as allocation target */

    Fee_30_FlexNor_Partition_ActionPtrType NoChunkFoundAction;      /*!< Action that is called when the chunk search can't find a chunk for the block */
    Fee_30_FlexNor_Partition_ActionPtrType LatestChunkFoundAction;  /*!< Action that is called when the chunk search has found the latest chunk for the block */

    Fee_30_FlexNor_Partition_ConstStatePtrType CurrentState;        /*!< Current state of the state machine */
    Fee_30_FlexNor_JobPtrType CurrentJob;                           /*!< Pointer to the current job */

    boolean LatestChunkFound;                                       /*!< Flag indicating whether the latest chunk was found during the chunk search */
    Fee_30_FlexNor_ServiceResult AllocationResult;                  /*!< Result of the triggered allocation service (instance or chunk) */

    Fee_30_FlexNor_PartitionIdType PartitionId;                     /*!< Id of the partition which shall be started up */
    Fee_30_FlexNor_ResultCallback ResultCallback;                   /*!< Result callback that is used to communicate the startup service result back to the caller. */
} Fee_30_FlexNor_Partition_ContextType;                             /*!< Represents the context for the internal state machine of the unit */

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
# define FEE_30_FLEXNOR_START_SEC_CODE
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_StartJob()
 *********************************************************************************************************************/
/*! \brief       Start a job for the unit
 *  \details     Registers the unit at the scheduler to start the asynchronous processing for the unit.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_StartJob(void);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_EndJob()
 *********************************************************************************************************************/
/*! \brief       Ends a job for the unit write and read service
 *  \details     Unregisters the unit from the scheduler
 *  \param[in]   ctx    Pointer to the context containing the job result
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_EndJob(void);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_EndStartupJob()
 *********************************************************************************************************************/
/*! \brief       Ends a job for the unit startup service.
 *  \details     Unregisters the unit from the scheduler.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_EndStartupJob(void);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_ResultHandler()
 *********************************************************************************************************************/
/*! \brief       Handles the result of a called service
 *  \details     This function is used as a result callback for services called by this unit.
 *  \param[in]   result               Result of the called service
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_ResultHandler(Fee_30_FlexNor_ServiceResult result);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_AllocationResultHandler()
 *********************************************************************************************************************/
/*! \brief       Handles the result of a called allocation service
 *  \details     This function is used as a result callback for allocation services called by this unit.
 *               Allocation result handling requires a different implementation than the generic result handler.
 *  \param[in]   result               Result of the called service
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_AllocationResultHandler(Fee_30_FlexNor_ServiceResult result);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_ReadChunk()
 *********************************************************************************************************************/
/*! \brief       Retrieves a link from the LUT and reads the chunk header the link points to
 *  \details     -
 *  \param[in,out]   ctx    Context that contains all necessary information for the chunk search service.
 *                          Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_ReadChunk(Fee_30_FlexNor_Partition_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_ReadSectorHeaders()
 *********************************************************************************************************************/
/*! \brief       Triggers the startups ReadSectorHeaders service
 *  \details     -
 *  \param[in]   ctx    Context that contains the PartitionId which the service shall check. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_ReadSectorHeaders(Fee_30_FlexNor_Partition_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_GetLookupTable()
 *********************************************************************************************************************/
/*! \brief       Triggers the startups GetLookupTable service
 *  \details     -
 *  \param[in]   ctx    Context that contains the PartitionId which the service needs. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_GetLookupTable(Fee_30_FlexNor_Partition_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_GetLatestValidInstanceFromChunk()
 *********************************************************************************************************************/
/*! \brief          Triggers the chunks FindLatestValidInstance service
 *  \details        -
 *  \param[in,out]  ctx Context containing the chunk whose latest valid instance shall be found. Must not be NULL.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_GetLatestValidInstanceFromChunk(Fee_30_FlexNor_Partition_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_ReadInstanceContent()
 *********************************************************************************************************************/
/*! \brief          Triggers the ReadContent service of the found instance given in the context
 *  \details        -
 *  \param[in,out]  ctx Context containing the instance whose content shall be read. Must not be NULL.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_ReadInstanceContent(Fee_30_FlexNor_Partition_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_TriggerLookupTableRecovery()
 *********************************************************************************************************************/
/*! \brief       Triggers the lookup tables Recover service
 *  \details     -
 *  \param[in]   ctx    Context that contains the PartitionId which the service needs. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_TriggerLookupTableRecovery(Fee_30_FlexNor_Partition_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_TriggerInstanceAllocation()
 *********************************************************************************************************************/
/*! \brief       Triggers the instance allocation in the found latest chunk of the block that shall be written
 *  \details     -
 *  \param[in]   ctx    Context that contains found chunk and the information required for triggering the instance allocation. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_TriggerInstanceAllocation(Fee_30_FlexNor_Partition_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_TriggerChunkAllocation()
 *********************************************************************************************************************/
/*! \brief       Triggers the chunk allocation in the target sector stored in given context
 *  \details     -
 *  \param[in]   ctx    Context that contains the target sector and job data for the chunk allocation. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_TriggerChunkAllocation(Fee_30_FlexNor_Partition_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_TriggerSectorAllocation()
 *********************************************************************************************************************/
/*! \brief       Triggers the allocation of a new sector in an available (i.e. empty or invalid) sector.
 *  \details     -
 *  \param[in]   ctx    Context that contains the pointer to the sector that shall be newly allocated. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_TriggerSectorAllocation(Fee_30_FlexNor_Partition_ConstContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_GetAvailableSector()
 *********************************************************************************************************************/
/*! \brief       Gets an available sector from the pool of sectors managed by the sector container
 *  \details     Searches for an empty or invalid sector that could be used for a new sector allocation. An available
 *               sector is only returned if more than one sector is available. One available sector is always kept 
 *               as garbage collection target.
 *  \param[in]   ctx    Context that contains the information about the currently running job. Must not be NULL.
 *  \return      Pointer to the next available sector. NULL if no sector is available for allocation.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_SectorPtrType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_GetAvailableSector(Fee_30_FlexNor_Partition_ConstContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_TriggerGarbageCollection()
 *********************************************************************************************************************/
/*! \brief       Triggers the garbage collection for the partition the current job belongs tos
 *  \details     Depending on the state of the flash, either a pending garbage collection is finished or a new one is started.
 *  \param[in]   ctx    Context that contains the information about the currently running job. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_TriggerGarbageCollection(Fee_30_FlexNor_Partition_ConstContextPtrType ctx);

# define FEE_30_FLEXNOR_STOP_SEC_CODE
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* FEE_30_FLEXNOR_PARTITIONINTERNAL_H */

/**********************************************************************************************************************
 *  END OF FILE: Fee_30_FlexNor_PartitionInternal.h
 *********************************************************************************************************************/
