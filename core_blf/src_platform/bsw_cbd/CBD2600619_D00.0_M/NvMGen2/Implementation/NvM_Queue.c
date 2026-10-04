/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2026 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!        \file  NvM_Queue.c
 *        \brief  NvM_Queue source file
 *      \details  Implementation of the queue unit of the NvM.
 *         \unit  NvM_Queue
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/
#define NVM_QUEUE_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "NvM_Queue.h"
#include "NvM_CfgDefines.h"
#include "NvM_GlobalUtilityLib.h"
#include "NvM_ErrorCheck.h"
#include "NvM.h"
#include "NvM_Notification.h"

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define NVM_START_SEC_CODE
#include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  NvM_Queue_ResetQueueJob
 *********************************************************************************************************************/
/*! \brief       Reset all information in the given job.
 *  \details     -
 *  \param[in]   Job - Pointer to the job which shall be cleared.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
NVM_LOCAL_INLINE FUNC(void, NVM_PRIVATE_CODE) NvM_Queue_ResetQueueJob(
    NvM_Queue_JobPtrType jobPtr
);

/**********************************************************************************************************************
 *  NvM_Queue_CopyQueueJob
 *********************************************************************************************************************/
/*! \brief       Copy the job parameters from the source pointer into the destination pointer.
 *  \details     -
 *  \param[in]   srcJobPtr - Pointer to the job which shall be copied.
 *  \param[out]  dstJobPtr - Pointer to the job where the SrcJobPtr shall be copied to.
 *   \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
NVM_LOCAL_INLINE FUNC(void, NVM_PRIVATE_CODE) NvM_Queue_CopyQueueJob(
    NvM_Queue_JobPtrType dstJobPtr,
    NvM_Queue_JobPtrToConstType srcJobPtr
);

/**********************************************************************************************************************
 *  NvM_Queue_HasFreeSlots
 *********************************************************************************************************************/
/*! \brief       Check if the queue has free slots.
 *  \details     -
 *  \param[in]   queuePtr - Pointer to type of queue
 *  \return      TRUE - Queue has at least one free entry.
 *  \return      FALSE - Queue is full.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
NVM_LOCAL_INLINE FUNC(boolean, NVM_PRIVATE_CODE) NvM_Queue_HasFreeSlots(NvM_Queue_InstancePtrToConstType queuePtr);

/**********************************************************************************************************************
 *  NvM_Queue_AddListElement
 *********************************************************************************************************************/
/*! \brief       Adjusts neighbour relations in such way that the given element is entered into the list after the
 *               given predecessor.
 *  \details     -
 *  \param[in]   queuePtr - Pointer to type of queue
 *  \param[in]   indexNewElement - Index of added element
 *  \param[in]   predecessorOfNewElement - Predecessor index of added element; Ignored when one of the lists is empty
 *  \pre         The length of list the element shall be added to is smaller than the maximum size of the queue
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
NVM_LOCAL_INLINE FUNC(void, NVM_PRIVATE_CODE) NvM_Queue_AddListElement(
    NvM_Queue_InstancePtrType queuePtr,
    NvM_QueueEntryRefType indexNewElement,
    NvM_QueueEntryRefType predecessorOfNewElement
);

/**********************************************************************************************************************
 *  NvM_Queue_RemoveListElement
 *********************************************************************************************************************/
/*! \brief       Adjusts neighbour relations in such way that the given element is removed the list
 *  \details     -
 *  \param[in]   queuePtr - Pointer to type of queue
 *  \param[in]   queueIndex - Index of the element to pop from the list
 *  \pre         The list to be removed from is not empty
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
NVM_LOCAL_INLINE FUNC(void, NVM_PRIVATE_CODE) NvM_Queue_RemoveListElement(
    NvM_Queue_InstancePtrType queuePtr,
    NvM_QueueEntryRefType queueIndex
);

#if (NVM_JOB_PRIORITIZATION == STD_ON)
/**********************************************************************************************************************
 *  NvM_Queue_FindMostPriorElement
 *********************************************************************************************************************/
/*! \brief       Returns a reference to the most prior queue entry
 *  \details     -
 *  \param[in]   queuePtr - Pointer to type of queue
 *  \pre         The queue given contains jobs
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
NVM_LOCAL_INLINE FUNC(NvM_QueueEntryRefType, NVM_PRIVATE_CODE) NvM_Queue_FindMostPriorElement(
    NvM_Queue_InstancePtrType queuePtr
);
#endif

/**********************************************************************************************************************
 *  NvM_Queue_MoveListElementToEmptyList
 *********************************************************************************************************************/
/*! \brief       Moves a listElement from the queue to the emptyList and resets its values
 *  \details     -
 *  \param[in]   queuePtr - Pointer to type of queue
 *  \param[in]   queueIndex - Index of the listElement to move
 *  \pre         The queue given contains jobs
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
NVM_LOCAL_INLINE FUNC(void, NVM_PRIVATE_CODE) NvM_Queue_MoveListElementToEmptyList(
    NvM_Queue_InstancePtrType queuePtr,
    NvM_QueueEntryRefType queueIndex
);

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  NvM_Queue_ResetQueueJob
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
NVM_LOCAL_INLINE FUNC(void, NVM_PRIVATE_CODE) NvM_Queue_ResetQueueJob(
    NvM_Queue_JobPtrType jobPtr
)
{
  jobPtr->BlockId = 0u;
  jobPtr->BlockDescriptorLookupTableId = 0u;
  jobPtr->TemporaryRamBlockAddr = NULL_PTR;
}

/**********************************************************************************************************************
 *  NvM_Queue_CopyQueueJob
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
NVM_LOCAL_INLINE FUNC(void, NVM_PRIVATE_CODE) NvM_Queue_CopyQueueJob(
    NvM_Queue_JobPtrType dstJobPtr,
    NvM_Queue_JobPtrToConstType srcJobPtr
)
{
  dstJobPtr->SingleBlockJobType = srcJobPtr->SingleBlockJobType;
  dstJobPtr->BlockId = srcJobPtr->BlockId;
  dstJobPtr->BlockDescriptorLookupTableId = srcJobPtr->BlockDescriptorLookupTableId;
  dstJobPtr->TemporaryRamBlockAddr = srcJobPtr->TemporaryRamBlockAddr;

}

/**********************************************************************************************************************
 *  NvM_Queue_HasFreeSlots
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
NVM_LOCAL_INLINE FUNC(boolean, NVM_PRIVATE_CODE) NvM_Queue_HasFreeSlots(NvM_Queue_InstancePtrToConstType queuePtr)
{
  boolean returnValue = FALSE;

  if(queuePtr->JobCounter < queuePtr->QueueSize)
  {
    returnValue = TRUE;
  }

  return returnValue;
}

/**********************************************************************************************************************
 * NvM_Queue_AddListElement
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
NVM_LOCAL_INLINE FUNC(void, NVM_PRIVATE_CODE) NvM_Queue_AddListElement(
    NvM_Queue_InstancePtrType queuePtr,
    NvM_QueueEntryRefType indexNewElement,
    NvM_QueueEntryRefType predecessorOfNewElement
)
{
#if !defined(__VCA__) /* COV_NVM_VCA */
/* VCA Disable SLC-10, SLC-11 : VCA_NVM_QueueList */
  NvM_Queue_ListElement *newElement = &queuePtr->QueueEntries[indexNewElement];

  if ((!NvM_Queue_HasEntries(queuePtr)) || (!NvM_Queue_HasFreeSlots(queuePtr)))
  {
    /* New List Element */
    newElement->Predecessor = indexNewElement;
    newElement->Successor = indexNewElement;

    /* No Neighbouring Elements yet */
  }
  else
  {
    NvM_Queue_ListElement *newPredecessor = &queuePtr->QueueEntries[predecessorOfNewElement];
    NvM_Queue_ListElement *newSuccessor = &queuePtr->QueueEntries[newPredecessor->Successor];

    /* New List Element */
    newElement->Predecessor = predecessorOfNewElement;
    newElement->Successor = newPredecessor->Successor;

    /* Neighbouring Elements in List */
    newSuccessor->Predecessor = indexNewElement;
    newPredecessor->Successor = indexNewElement;

  }
/* VCA Enable : VCA_NVM_QueueList */
#endif
}

/**********************************************************************************************************************
 * NvM_Queue_RemoveListElement
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
NVM_LOCAL_INLINE FUNC(void, NVM_PRIVATE_CODE) NvM_Queue_RemoveListElement(
    NvM_Queue_InstancePtrType queuePtr,
    NvM_QueueEntryRefType queueIndex
)
{
  /* No regard to the element being the last list entry is being taken. In this case the references being changed points
     to itself. It is expected that the element is afterwards pushed to the other list.
     There its references will be updated again. */

#if !defined(__VCA__) /* COV_NVM_VCA */
/* VCA Disable SLC-10, SLC-11 : VCA_NVM_QueueList */
  NvM_QueueEntryRefType successorOfRemovedElement = queuePtr->QueueEntries[queueIndex].Successor;
  NvM_QueueEntryRefType predecessorOfRemovedElement = queuePtr->QueueEntries[queueIndex].Predecessor;

  queuePtr->QueueEntries[successorOfRemovedElement].Predecessor = predecessorOfRemovedElement;
  queuePtr->QueueEntries[predecessorOfRemovedElement].Successor = successorOfRemovedElement;
/* VCA Enable : VCA_NVM_QueueList */
#endif
}

/**********************************************************************************************************************
 * NvM_Queue_MoveListElementToEmptyList
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
NVM_LOCAL_INLINE FUNC(void, NVM_PRIVATE_CODE) NvM_Queue_MoveListElementToEmptyList(
    NvM_Queue_InstancePtrType queuePtr,
    NvM_QueueEntryRefType queueIndex
)
{
  NvM_Queue_RemoveListElement(queuePtr, queueIndex);

#if !defined(__VCA__) /* COV_NVM_VCA */
/* VCA Disable SLC-10, SLC-11 : VCA_NVM_QueueList */
  queuePtr->QueueEntries[queueIndex].Priority = 0xFF;
  NvM_Queue_ResetQueueJob(&queuePtr->QueueEntries[queueIndex].Job);

  if (queueIndex == queuePtr->HeadIndex)
  {
    queuePtr->HeadIndex = queuePtr->QueueEntries[queueIndex].Successor;
  }

  /* Add to EmptyList */
  const NvM_QueueEntryRefType emptyListTail = queuePtr->QueueEntries[queuePtr->EmptyListHeadIndex].Predecessor;
  NvM_Queue_AddListElement(queuePtr, queueIndex, emptyListTail);
/* VCA Enable : VCA_NVM_QueueList */
#endif

  queuePtr->EmptyListHeadIndex = queueIndex;
  queuePtr->JobCounter--;
}

#if (NVM_JOB_PRIORITIZATION == STD_ON)
/**********************************************************************************************************************
 * NvM_Queue_FindMostPriorElement
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
NVM_LOCAL_INLINE FUNC(NvM_QueueEntryRefType, NVM_PRIVATE_CODE) NvM_Queue_FindMostPriorElement(
    NvM_Queue_InstancePtrType queuePtr)
{
  NvM_QueueEntryRefType mostPriorElement = queuePtr->HeadIndex;
  NvM_QueueEntryRefType currentElement = queuePtr->HeadIndex;

#if !defined(__VCA__) /* COV_NVM_VCA */
/* VCA Disable SLC-10, SLC-11 : VCA_NVM_QueueList */
  uint8 priorityMostPriorElement = queuePtr->QueueEntries[queuePtr->HeadIndex].Priority;

  for (uint16 idx = 0; idx < queuePtr->JobCounter; idx++)                                                               /* FETA_NVM_StaticQueueUpperBoundQueueSize */
  {
    uint8 currentPriority = queuePtr->QueueEntries[currentElement].Priority;
    if (currentPriority < priorityMostPriorElement)
    {
      priorityMostPriorElement = currentPriority;
      mostPriorElement = currentElement;
    }
    currentElement = queuePtr->QueueEntries[currentElement].Successor;
  }
/* VCA Enable : VCA_NVM_QueueList */
#endif

  return mostPriorElement;
}
#endif


/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * NvM_Queue_Init
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
FUNC(void, NVM_PRIVATE_CODE) NvM_Queue_Init(
  NvM_Queue_InstancePtrType queuePtr,
  const uint16 queueSize,
  NvM_QueueListPtrType queueEntries)
{
  queuePtr->QueueSize = queueSize;
  queuePtr->QueueEntries = queueEntries;

  for (uint16 idx = 0; idx < queuePtr->QueueSize; idx++)                                                                /* FETA_NVM_StaticQueueUpperBoundQueueSize */
  {
#if !defined(__VCA__) /* COV_NVM_VCA */
/* VCA Disable SLC-10, SLC-11 : VCA_NVM_QueueList */
    NvM_Queue_ResetQueueJob(&queuePtr->QueueEntries[idx].Job);
    queuePtr->QueueEntries[idx].Predecessor = (idx == 0u) ?
      (queuePtr->QueueSize - 1u) :
      (idx - 1u);

    queuePtr->QueueEntries[idx].Successor = (idx == (queuePtr->QueueSize - 1u)) ?
      0u :
      (idx + 1u);

    queuePtr->QueueEntries[idx].Priority = 0xFF;
/* VCA Enable : VCA_NVM_QueueList */
#endif
  }

  queuePtr->JobCounter = 0u;
  queuePtr->HeadIndex = 0u;
  queuePtr->EmptyListHeadIndex = 0u;
}


/**********************************************************************************************************************
 *  NvM_Queue_Push
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
 *
 */
FUNC(Std_ReturnType, NVM_PRIVATE_CODE) NvM_Queue_Push(
    NvM_Queue_InstancePtrType queuePtr,
    NvM_Queue_JobPtrToConstType jobPtr,
    const uint8 serviceId
)
{
    Std_ReturnType returnValue = E_NOT_OK;

    if(NvM_Queue_HasFreeSlots(queuePtr))
    {
      const NvM_QueueEntryRefType emptyElement = queuePtr->EmptyListHeadIndex;

      /* Get Element from EmptyList */
      NvM_Queue_RemoveListElement(queuePtr, emptyElement);

      /* Update EmptyListHeadIndex; Value not used when list is empty. For this checks using the JobCounter
         are in place and no special consideration are taken into account updating the HeadIndex */

#if !defined(__VCA__) /* COV_NVM_VCA */
/* VCA Disable SLC-10, SLC-11 : VCA_NVM_QueueList */
      queuePtr->EmptyListHeadIndex = queuePtr->QueueEntries[emptyElement].Successor;

      /* Currently hardcoded for FIFO; in future range check will be needed */
      NvM_QueueEntryRefType queueTailIndex = queuePtr->QueueEntries[queuePtr->HeadIndex].Predecessor;

      /* Add empty element to FullList */
      NvM_Queue_AddListElement(queuePtr, emptyElement, queueTailIndex);
      /* Pushed element is new Head of Queue as it is the only element; replacing head not needed for FIFO */
      if (!NvM_Queue_HasEntries(queuePtr))
      {
        queuePtr->HeadIndex = emptyElement;
      }

      /* Get job Priority from BlockDescriptor */
      NvM_Queue_CopyQueueJob(&queuePtr->QueueEntries[emptyElement].Job, jobPtr);
#if (NVM_JOB_PRIORITIZATION == STD_ON)
      NvM_BlockDescriptorPtrType blockDescriptor =
      NvM_GetAddrBlockDescriptor(jobPtr->BlockDescriptorLookupTableId);
      queuePtr->QueueEntries[emptyElement].Priority = blockDescriptor->Priority;
#endif
/* VCA Enable : VCA_NVM_QueueList */
#endif

      queuePtr->JobCounter++;
      returnValue = E_OK;
    }
    else
    {
      NvM_ErrorCheck_ReportDetRuntimeErrorConditionally(serviceId, NVM_E_QUEUE_FULL);
    }
    return returnValue;
}


/**********************************************************************************************************************
 *  NvM_Queue_Pop
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
FUNC(void, NVM_PRIVATE_CODE) NvM_Queue_Pop(
    NvM_Queue_InstancePtrType queuePtr,
    NvM_Queue_JobPtrType jobPtr
)
{
#if (NVM_JOB_PRIORITIZATION == STD_ON)
  NvM_QueueEntryRefType popIndex = NvM_Queue_FindMostPriorElement(queuePtr);
#else
  /* Without prioritization FIFO is applied. Always remove list head */
  NvM_QueueEntryRefType popIndex = queuePtr->HeadIndex;
#endif

#if !defined(__VCA__) /* COV_NVM_VCA */
/* VCA Disable SLC-10, SLC-11 : VCA_NVM_QueueList */
  NvM_Queue_CopyQueueJob(jobPtr, &queuePtr->QueueEntries[popIndex].Job);
/* VCA Enable : VCA_NVM_QueueList */
#endif

  NvM_Queue_MoveListElementToEmptyList(queuePtr, popIndex);
}

/**********************************************************************************************************************
 *  NvM_Queue_HasEntries
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(boolean, NVM_PRIVATE_CODE) NvM_Queue_HasEntries(NvM_Queue_InstancePtrToConstType queuePtr)
{
  boolean returnValue = TRUE;

  if(queuePtr->JobCounter == 0u)
  {
    returnValue = FALSE;
  }

  return returnValue;
}


/**********************************************************************************************************************
 *  NvM_Queue_CancelJobs
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
 *
 */
FUNC(Std_ReturnType, NVM_PRIVATE_CODE) NvM_Queue_CancelJobs( NvM_Queue_InstancePtrType queuePtr,
    NvM_PartitionIdType partitionId, NvM_BlockIdType blockId)
{
  Std_ReturnType retVal = E_NOT_OK;
  NvM_QueueEntryRefType nextJob = queuePtr->HeadIndex;
  uint16 jobsLeftToCheck = queuePtr->JobCounter;

  while (jobsLeftToCheck != 0u)                                                                                         /* FETA_NVM_ConstantQueueListSize_Callee */
  {
    NvM_QueueEntryRefType currentJob = nextJob;

#if !defined(__VCA__) /* COV_NVM_VCA */
/* VCA Disable SLC-10, SLC-11 : VCA_NVM_QueueList */
    nextJob = queuePtr->QueueEntries[currentJob].Successor;
    NvM_Queue_JobPtrType currentJobInformation = &queuePtr->QueueEntries[currentJob].Job;

    if(currentJobInformation->BlockId == blockId)
    {
      NvM_BlockManagementInformationPtrType blockManagementInfo =
        NvM_GlobalUtilityLib_GetBlockManagementInfo(blockId, currentJobInformation->BlockDescriptorLookupTableId, partitionId);
      blockManagementInfo->ErrorStatus = NVM_REQ_CANCELED;
      blockManagementInfo->RamBlockState = NVM_RAMBLOCKSTATE_INVALID_UNCHANGED;

      /*
       * Own SingleBlockJobContext is build as NvM_GetAddrSingleBlockJobContext() would
       * get currently processed SingleBlockJobContext.
      */
      NvM_SingleBlockJobContextType singleBlockJobContext;
      singleBlockJobContext.SingleBlockJobType = currentJobInformation->SingleBlockJobType;
      singleBlockJobContext.BlockId = currentJobInformation->BlockId;
      singleBlockJobContext.BlockDescriptorLookupTableId = currentJobInformation->BlockDescriptorLookupTableId;
      singleBlockJobContext.TemporaryRamBlockAddr = currentJobInformation->TemporaryRamBlockAddr;
      singleBlockJobContext.DataIndex = blockManagementInfo->DataIndex;
      NvM_Notification_ProcessSingleBlockCallback(&singleBlockJobContext, partitionId);

      NvM_Queue_MoveListElementToEmptyList(queuePtr, currentJob);
      retVal = E_OK;
    }
/* VCA Enable : VCA_NVM_QueueList */
#endif

    jobsLeftToCheck--;
  }
  return retVal;
}

#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  VCA JUSTIFICATIONS
 **********************************************************************************************************************/
/* VCA_JUSTIFICATION_BEGIN

\ID VCA_NVM_QueueList
  \DESCRIPTION The current queue list and the related queue size are assigned to the respective Queue instance
               within the Queue Init function.
               The queue size and the job counter are used to iterate over the queue list.
               It must be ensured that access to the queue list is always within the bounds of the respective list.
               In order to analyze the NvM in a meaningful way, code parts where the queue list is used,
               are deactivated during the VCA analysis, as it would lead to false-positive errors
               in other parts of the module.

  \COUNTERMEASURE \N The pre-condition about the queue size formulated for NvM_Queue_Init ensures that the assigned queue list
                     always has the assigned queue size.

VCA_JUSTIFICATION_END */

/**********************************************************************************************************************
 *  END OF FILE: NvM_Queue.c
 *********************************************************************************************************************/
