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
/*!        \file  NvM_Queue.h
 *        \brief  NvM_Queue header file
 *      \details  Header of the queue unit of the NvM.
 *         \unit  NvM_Queue
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#if !defined (NVM_QUEUE_H)
# define NVM_QUEUE_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "NvM_Cfg.h"
#include "NvM_InternalTypes.h"


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
# define NVM_START_SEC_CODE
# include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * NvM_Queue_Init
 *********************************************************************************************************************/
/*! \brief       Initialize the queue unit.
 *  \details     -
 *  \pre         Unit is uninitialized.
 *  \param[out]  queuePtr - Pointer to the queue which shall be initialized.
 *  \param[in]   queueSize - Size of the queue.
 *  \param[in]   queueEntries - Pointer to the array of queue entries.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \vcaAttr FETA_ReportCaller
 * \spec
 *    requires $lengthOf(queueEntries) == queueSize;
 * \endspec
 *********************************************************************************************************************/
FUNC(void, NVM_PRIVATE_CODE) NvM_Queue_Init(
  NvM_Queue_InstancePtrType queuePtr,
  const uint16 queueSize,
  NvM_QueueListPtrType queueEntries
);

/**********************************************************************************************************************
 *  NvM_Queue_Push
 *********************************************************************************************************************/
/*! \brief       Add a new job to the queue.
 *  \details     -
 *  \param[in,out] queuePtr - Pointer to the queue were the job shall be pushed.
 *  \param[in]     jobPtr - Pointer to the job which shall be added to the queue.
 *  \param[in]     serviceId - Caller's Service ID.
 *  \return      E_OK - Job was successfully added to the queue.
 *  \return      E_NOT_OK - Job could not be added to the queue.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, NVM_PRIVATE_CODE) NvM_Queue_Push(
    NvM_Queue_InstancePtrType queuePtr,
    NvM_Queue_JobPtrToConstType jobPtr,
    const uint8 serviceId
);

/**********************************************************************************************************************
 *  NvM_Queue_Pop
 *********************************************************************************************************************/
/*! \brief       Get the job from the queue which shall be processed next.
 *  \details     Additionally the job will be removed from the queue.
 *  \param[in,out] queuePtr - Pointer to the queue were the job shall be popped.
 *  \param[out]    jobPtr - Pointer to the job which shall be processed.
 *  \pre         Has_Entries() has to be called beforehand and return TRUE.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, NVM_PRIVATE_CODE) NvM_Queue_Pop(
    NvM_Queue_InstancePtrType queuePtr,
    NvM_Queue_JobPtrType jobPtr
);

/**********************************************************************************************************************
 *  NvM_Queue_HasEntries
 *********************************************************************************************************************/
/*! \brief       Check if the queue has entries.
 *  \details     -
 *  \param[in]   queuePtr - Pointer to type of queue
 *  \return      TRUE - The queue has entries.
 *  \return      FALSE- The queue is empty.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(boolean, NVM_PRIVATE_CODE) NvM_Queue_HasEntries(NvM_Queue_InstancePtrToConstType queuePtr);

/**********************************************************************************************************************
 *  NvM_Queue_CancelJobs
 *********************************************************************************************************************/
/*! \brief       Search and remove jobs with requested BlockId from queue.
 *  \details     Removed jobs will not be processed.
 *  \param[in,out] queuePtr - Pointer to the queue which shall be searched.
 *  \param[in]    partitionId - Id of the partition that queued the block.
 *  \param[in]    blockId - BlockId to be used as search criteria.
 *  \return      E_OK - Job was found and removed.
 *  \return      E_NOT_OK - No matching job found.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, NVM_PRIVATE_CODE) NvM_Queue_CancelJobs(
    NvM_Queue_InstancePtrType queuePtr,
    NvM_PartitionIdType partitionId,
    NvM_BlockIdType blockId
);

# define NVM_STOP_SEC_CODE
# include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* NVM_QUEUE_H */

/**********************************************************************************************************************
 *  END OF FILE: NvM_Queue.h
 *********************************************************************************************************************/
