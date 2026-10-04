/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2026 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!        \file  MemAcc_Queue.h
 *        \brief  MemAcc_Queue header file
 *      \details  Header of Queue unit of the MemAcc.
 *         \unit  Queue
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#if !defined (MEMACC_QUEUE_H)
# define MEMACC_QUEUE_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "MemAcc_InternalTypes.h"

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define MEMACC_START_SEC_CODE
#include "MemAcc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * MemAcc_Queue_Reset
 *********************************************************************************************************************/
/*! \brief       Resets the queue unit to its initial state.
 *  \details     -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
void MemAcc_Queue_Reset(void);

/**********************************************************************************************************************
 * MemAcc_Queue_PushJob
 *********************************************************************************************************************/
/*! \brief       Add a new job to the queue.
 *  \details     -
 *  \param[in]   newJob - Pointer to the job which shall be added to the queue
 *  \return      E_OK - Job was successfully added to the queue.
 *  \return      E_NOT_OK - Job could not be added to the queue.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
Std_ReturnType MemAcc_Queue_PushJob(const MemAcc_JobAreaType* newJob);

/**********************************************************************************************************************
 * MemAcc_Queue_PopJob
 *********************************************************************************************************************/
/*! \brief       Remove the job from the queue.
 *  \details     -
 *  \param[in]   job - Pointer to the job which shall be removed from the queue.
 *  \pre         JobResult has to be set before calling this function. Job must point to an element of the queue.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
void MemAcc_Queue_PopJob(MemAcc_JobContextType* job);

/**********************************************************************************************************************
 * MemAcc_Queue_PopCanceledJobs
 *********************************************************************************************************************/
/*! \brief       Evaluate canceled jobs in queue and pop them.
 *  \details     -
 *  \pre         May only be called from MainFunction
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
void MemAcc_Queue_PopCanceledJobs(void);

/**********************************************************************************************************************
 * MemAcc_Queue_GetNextJob
 *********************************************************************************************************************/
/*! \brief       Return next job of a synchronization group to be processed depending on the priority.
 *  \details     -
 *  \param[in]   syncGroupIndex         - Index of the synchronization group for which a job shall be picked.
 *  \return      MemAcc_JobContextType* - Pointer to the next job; NULL_PTR if no next job is found.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
MemAcc_JobContextType* MemAcc_Queue_GetNextJob(MemAcc_SyncGroupIndexType syncGroupIndex);

/**********************************************************************************************************************
 * MemAcc_Queue_GetJob
 *********************************************************************************************************************/
/*! \brief       Determine the job for given AddressArea Index.
 *  \details     -
 *  \param[in]   addressAreaIdx - Index of the address area of the job.
 *  \param[in]   isInternalJob  - boolean if the job to get is an internal job.
 *  \return      MemAcc_JobContextType* - Pointer to the related job
 *               NULL_PTR will be returned for invalid input or configuration.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
MemAcc_JobContextType* MemAcc_Queue_GetJob(MemAcc_AddressAreaIndexType addressAreaIdx, boolean isInternalJob);

/**********************************************************************************************************************
 * MemAcc_Queue_HasJob
 *********************************************************************************************************************/
/*! \brief       Determine if a job exists for the given AddressArea Index.
 *  \details     -
 *  \param[in]   addressAreaIndex - Index of the address area of the job.
 *  \param[in]   isInternalJob    - boolean if the job to get is an internal job.
 *  \return      TRUE - if a job exists.
 *               FALSE - if no job exists.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
boolean MemAcc_Queue_HasJob(MemAcc_AddressAreaIndexType addressAreaIdx, boolean isInternalJob);

/**********************************************************************************************************************
 * MemAcc_Queue_RequestLock
 *********************************************************************************************************************/
/*! \brief       Add request lock job to queue.
 *  \details     -
 *  \param[in]   addressAreaIdx          - Index of the address area.
 *  \param[in]   address                 - Logical start address to identify lock area.
 *  \param[in]   length                  - Length to identify lock area.
 *  \param[in]   lockNotificationFctPtr  - Pointer to address area lock notification callback function.
 *  \return      E_OK - Lock job was successfully added to the queue.
 *  \return      E_NOT_OK - Lock job could not be added to the queue.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
Std_ReturnType MemAcc_Queue_RequestLock(
   MemAcc_AddressAreaIndexType addressAreaIdx,
   MemAcc_AddressType address,
   MemAcc_LengthType length,
   MemAcc_ApplicationLockNotificationType lockNotificationFctPtr);

/**********************************************************************************************************************
 * MemAcc_Queue_ReleaseLock
 *********************************************************************************************************************/
/*! \brief       Process release lock job.
 *  \details     -
 *  \param[in]   addressAreaIdx    - Index of the address area.
 *  \param[in]   address           - Logical start address to identify lock area.
 *  \param[in]   length            - Length to identify lock area.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
void MemAcc_Queue_ReleaseLock(
   MemAcc_AddressAreaIndexType addressAreaIdx,
   MemAcc_AddressType address,
   MemAcc_LengthType length);

#if (MEMACC_BBM_ENABLED == STD_ON) /* COV_MSR_UT_OPTIONAL_UNIT */

/**********************************************************************************************************************
 * MemAcc_Queue_RaiseError()
 *********************************************************************************************************************/
/*!
 *  \brief         Raises an error for a given address area ID and error type.
 *  \details       -
 *  \param[in]     addressAreaIdx Index of the address area.
 *  \param[in]     errorType Type of the error to raise.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 */
void MemAcc_Queue_RaiseError(
   MemAcc_AddressAreaIndexType addressAreaIdx,
   MemAcc_ErrorType errorType);

#endif /* MEMACC_BBM_ENABLED */

#if (MEMACC_SUSPENDRESUME_ENABLED == STD_ON)

/**********************************************************************************************************************
 * MemAcc_Queue_IsSuspensionNeededAndAllowed
 *********************************************************************************************************************/
/*! \brief       Returns whether suspension of current processed job is possible
 *  \details     -
 *  \param[in]   hwId              - HwId of the current processed job step
 *  \param[in]   addressAreaIdx    - addressAreaIdx of the current processed job step
 *  \param[in]   isInternalJob     - boolean if the job to get is an internal job.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
boolean MemAcc_Queue_IsSuspensionNeededAndAllowed(const MemAcc_HwIdType hwId,
  const MemAcc_AddressAreaIndexType addressAreaIdx,
  const boolean isInternalJob);

#endif /* MEMACC_SUSPENDRESUME_ENABLED == STD_ON */

/**********************************************************************************************************************
 * MemAcc_Queue_HasJobForLowerLayerIdx
 *********************************************************************************************************************/
/*! \brief       Returns whether there is a job in queue which targets the given lower layer index.
 *  \details     -
 *  \param[in]   llIdx - Lower layer index.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
boolean MemAcc_Queue_HasJobForLowerLayerIdx(MemAcc_LowerLayerIndexType llIdx);

#define MEMACC_STOP_SEC_CODE
#include "MemAcc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* MEMACC_QUEUE_H */

/**********************************************************************************************************************
 *  END OF FILE: MemAcc_Queue.h
 *********************************************************************************************************************/
