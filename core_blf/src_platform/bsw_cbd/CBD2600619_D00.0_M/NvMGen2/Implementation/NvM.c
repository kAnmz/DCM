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
/*!        \file  NvM.c
 *        \brief  NvM source file
 *      \details  The NVRAM Manager ensure the data storage and maintenance of NV data.
 *                The NVRAM Manager shall be able to administrate the NV data of an EEPROM
 *                and/or a FLASH EEPROM emulation device.
 *         \unit  NvM_Api
 *********************************************************************************************************************/

#define NVM_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
/* Standardized includes */
#include "NvM.h"

/* Non-standard includes */
#include "NvM_Cfg.h"
#include "NvM_CfgDefines.h"
#include "NvM_Queue.h"
#include "NvM_DataIntegrityRecalcQueue.h"
#include "NvM_FsmLib.h"
#include "NvM_GlobalUtilityLib.h"
#include "NvM_Notification.h"
#include "NvM_WriteAllFsm.h"
#include "NvM_ReadAllFsm.h"
#include "NvM_ErrorCheck.h"
#include "NvM_BackgroundCrcRecalcFsm.h"
#include "MemIf.h"
// #include "Os.h"

#include "NvM_NvServiceProcessorFsm.h"
#include "NvM_ServiceProcessorFsm.h"

#if (NVM_MULTIPARTITION_USAGE_SCENARIO == STD_ON)
  #include "NvM_MultiBlockProcessorFsm.h"
#endif /* NVM_MULTIPARTITION_USAGE_SCENARIO */


/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/
/* Check the version of the configuration header file */
# if (  (NVM_CFG_MAJOR_VERSION != (3u)) \
    || (NVM_CFG_MINOR_VERSION != (6u)) )
#  error "Version numbers of NvM.c and NvM_Cfg.h are inconsistent!"
# endif

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
#define NvM_GetOsPartitionId() GetApplicationID()

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/
#define NVM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Initialization state of the module */
NVM_LOCAL boolean NvM_IsModuleInitialized = FALSE;

#define NVM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

# define NVM_START_SEC_CODE
# include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * NvM_IsBlockPending()
 *********************************************************************************************************************/
/*! \brief       Check if block is pending.
 *  \details     -
 *  \param[in]   blockId                      Block ID of block to check.
 *  \param[in]   blockDescriptorLookupTableId Block Descriptor Lookup Table ID of block to check.
 *  \param[in]   partitionId                  Current Partition ID.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
NVM_LOCAL_INLINE FUNC(boolean, NVM_PRIVATE_CODE) NvM_IsBlockPending(
  const NvM_BlockIdType blockId,
  const NvM_BlockDescriptorLookupTableIdType blockDescriptorLookupTableId,
  const NvM_PartitionIdType partitionId);

/**********************************************************************************************************************
 * NvM_IsDataIndexValid()
 *********************************************************************************************************************/
/*! \brief       Check if dataindex is valid for given block ID.
 *  \details     -
 *  \param[in]   blockDescriptorLookupTableId Block ID of block to check.
 *  \param[in]   dataIndex Dataindex to check.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
NVM_LOCAL_INLINE FUNC(boolean, NVM_PRIVATE_CODE) NvM_IsDataIndexValid(
  const NvM_BlockDescriptorLookupTableIdType blockDescriptorLookupTableId, const uint8 dataIndex);

/**********************************************************************************************************************
 * NvM_IsDefaultDataConfigured()
 *********************************************************************************************************************/
/*! \brief       Check if default data is configured for given block ID.
 *  \details     -
 *  \param[in]   blockDescriptorLookupTableId Block ID of block to check.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
NVM_LOCAL_INLINE FUNC(boolean, NVM_PRIVATE_CODE) NvM_IsDefaultDataConfigured(
  const NvM_BlockDescriptorLookupTableIdType blockDescriptorLookupTableId);

/**********************************************************************************************************************
 * NvM_IsPartitionContextValid()
 *********************************************************************************************************************/
/*! \brief       Check if the current partition context is valid for the given blockID.
 *  \details     -
 *  \param[in]   blockDescriptorLookupTableId Block ID to check for validity.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
NVM_LOCAL_INLINE FUNC(boolean, NVM_PRIVATE_CODE) NvM_IsPartitionContextValid(
  const NvM_BlockDescriptorLookupTableIdType blockDescriptorLookupTableId);

/**********************************************************************************************************************
 * NvM_IsBlockWithImmediatePriority()
 *********************************************************************************************************************/
/*! \brief           Check if block for given blockID is configured with immediate priority.
 *  \details         -
 *  \param[in]       blockDescriptorLookupTableId ID of block that shall be checked
 *  \pre             -
 *  \context         TASK
 *  \reentrant       FALSE
 *  \synchronous     TRUE
 *********************************************************************************************************************/
NVM_LOCAL_INLINE FUNC(boolean, NVM_PRIVATE_CODE) NvM_IsBlockWithImmediatePriority(
  const NvM_BlockDescriptorLookupTableIdType blockDescriptorLookupTableId);

/**********************************************************************************************************************
 * NvM_IsWriteBlockOnceEnabled()
 *********************************************************************************************************************/
/*! \brief           Check if block for given blockID is configured with write once.
 *  \details         -
 *  \param[in]       blockDescriptorLookupTableId ID of block that shall be checked
 *  \pre             -
 *  \context         TASK
 *  \reentrant       FALSE
 *  \synchronous     TRUE
 *********************************************************************************************************************/
NVM_LOCAL_INLINE FUNC(boolean, NVM_PRIVATE_CODE) NvM_IsWriteBlockOnceEnabled(
  const NvM_BlockDescriptorLookupTableIdType blockDescriptorLookupTableId);

/**********************************************************************************************************************
 * NvM_CheckAddress
 *********************************************************************************************************************/
/*! \brief        Checks whether the given pointer is valid for given NvM Block Id.
 *  \details      -
 *  \param[in]    blockDescriptorLookupTableId in range [1, (number of blocks - 1)].
 *  \param[in]    ramPtr to be checked whether valid for the passed BlockId. May be NULL_PTR, depends on passed BlockId.
 *  \return       TRUE pointer is valid for NvM block references via BlockId
 *  \return       FALSE otherwise
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *  \pre -
 *********************************************************************************************************************/
NVM_LOCAL_INLINE FUNC(boolean, NVM_PRIVATE_CODE) NvM_CheckAddress(
  const NvM_BlockDescriptorLookupTableIdType blockDescriptorLookupTableId,
  const void * ramPtr);

/**********************************************************************************************************************
 * NvM_FinishMultiBlockJobTermination
 *********************************************************************************************************************/
/*! \brief        Resets the multiblock job flags and sets the error status of the multiblock job request to canceled.
 *  \details      -
 *  \param[in]    multiBlockInfo    MultiBlock Information Pointer
 *  \param[in]    multiBlockJobType Type of the multiblock job which needs to be forwarded
 *                to the processing of the multiblock callback
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *  \pre -
 *********************************************************************************************************************/
NVM_LOCAL_INLINE FUNC(void, NVM_PRIVATE_CODE) NvM_FinishMultiBlockJobTermination(
  NvM_MultiBlockJobInformationPtrType multiBlockInfo,
  const NvM_MultiBlockJobType multiBlockJobType);

/**********************************************************************************************************************
 * NvM_ResetAllSinglePartitionProcessingStacks
 *********************************************************************************************************************/
/*! \brief        Clears all single partition processing stacks.
 *                Spawns the Service FSM.
 *  \details      -
 *  \param[in]    partitionId Partition ID.
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *  \pre -
 *********************************************************************************************************************/
NVM_LOCAL_INLINE FUNC(void, NVM_PRIVATE_CODE) NvM_ResetAllSinglePartitionProcessingStacks(NvM_PartitionIdType partitionId);

/**********************************************************************************************************************
 * NvM_GetPartitionIdViaBlockId
 *********************************************************************************************************************/
/*! \brief        Gets the NvM partition id via the given block id.
 *  \details      -
 *  \param[in]    blockDescriptorLookupTableId Block ID.
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *  \pre -
 */
NVM_LOCAL_INLINE FUNC(NvM_PartitionIdType, NVM_PRIVATE_CODE) NvM_GetPartitionIdViaBlockId(
  const NvM_BlockDescriptorLookupTableIdType blockDescriptorLookupTableId);

/**********************************************************************************************************************
 * NvM_InitBasicFunctionality()
 *********************************************************************************************************************/
/*! \brief        Initializes basic functionality needed in singlepartition and multipartition scenarios.
 *  \details      -
 *  \param[in]    partitionId Partition ID.
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *  \pre -
 *********************************************************************************************************************/
NVM_LOCAL_INLINE FUNC(void, NVM_PRIVATE_CODE) NvM_InitBasicFunctionality(NvM_PartitionIdType partitionId);

/**********************************************************************************************************************
 * NvM_CheckBlockLockedStatus
 *********************************************************************************************************************/
/*! \brief        Checks whether the block is locked for the application or not.
 *  \details      -
 *  \param[in]    blockManagementInfo Block Management Information to be checked.
 *  \param[in]    partitionId         Current Partition Id.
 *  \return       TRUE if block is locked for application
 *  \return       FALSE otherwise
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *  \pre -
 *********************************************************************************************************************/
NVM_LOCAL_INLINE FUNC(boolean, NVM_PRIVATE_CODE) NvM_CheckBlockLockedStatus(
  const NvM_BlockManagementInformationPtrToConstType blockManagementInfo,
  const NvM_PartitionIdType partitionId);

/**********************************************************************************************************************
 * NvM_CancelMemIfConditionally
 *********************************************************************************************************************/
/*! \brief        Performs a MemIf_Cancel() in case no immediate job is active and MemIf is BUSY.
 *  \details      -
 *  \param[in]    partitionId           Current Partition Id.
 *  \param[in]    lastProcessedBlockId  Last processed block ID of the multi block job,
 *                                      which was processed before the kill operation
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *  \pre -
 *********************************************************************************************************************/
NVM_LOCAL_INLINE FUNC(void, NVM_PRIVATE_CODE) NvM_CancelMemIfConditionally(
  const NvM_BlockDescriptorLookupTableIdType lastProcessedBlockId);

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * NvM_IsBlockPending()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
NVM_LOCAL_INLINE FUNC(boolean, NVM_PRIVATE_CODE) NvM_IsBlockPending(
  const NvM_BlockIdType blockId,
  const NvM_BlockDescriptorLookupTableIdType blockDescriptorLookupTableId,
  const NvM_PartitionIdType partitionId)
{
  NvM_BlockManagementInformationPtrToConstType blockManagementInfo =
    NvM_GlobalUtilityLib_GetBlockManagementInfo(blockId, blockDescriptorLookupTableId, partitionId);

  return (blockManagementInfo->ErrorStatus == NVM_REQ_PENDING);
}

/**********************************************************************************************************************
 * NvM_IsDataIndexValid()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
NVM_LOCAL_INLINE FUNC(boolean, NVM_PRIVATE_CODE) NvM_IsDataIndexValid(
  const NvM_BlockDescriptorLookupTableIdType blockDescriptorLookupTableId, const uint8 dataIndex)
{
  return (dataIndex < NvM_GetAddrBlockDescriptor(blockDescriptorLookupTableId)->NvBlockNumber);
}

/**********************************************************************************************************************
 * NvM_IsDefaultDataConfigured()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
NVM_LOCAL_INLINE FUNC(boolean, NVM_PRIVATE_CODE) NvM_IsDefaultDataConfigured(
  const NvM_BlockDescriptorLookupTableIdType blockDescriptorLookupTableId)
{
  NvM_BlockDescriptorPtrType blockDescriptor = NvM_GetAddrBlockDescriptor(blockDescriptorLookupTableId);

  return ((blockDescriptor->RomBlockDataAddress != NULL_PTR)
          || (blockDescriptor->InitBlockCallback != NULL_PTR)
          || (blockDescriptor->ExtendedInitBlockCallback != NULL_PTR));
}

/**********************************************************************************************************************
 * NvM_IsPartitionContextValid()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
NVM_LOCAL_INLINE FUNC(boolean, NVM_PRIVATE_CODE) NvM_IsPartitionContextValid(
  const NvM_BlockDescriptorLookupTableIdType blockDescriptorLookupTableId)
{
#if (NVM_MULTIPARTITION_USAGE_SCENARIO == STD_ON)
  boolean returnValue = FALSE;

  const NvM_PartitionIdType blockPartitionId = NvM_GetPartitionIdViaBlockId(blockDescriptorLookupTableId);

  const ApplicationType osId = NvM_GetOsPartitionId();
  NvM_PartitionIdType partitionId = 0u;
  Std_ReturnType status = NvM_GlobalUtilityLib_GetPartitionId(&partitionId, osId);

  if (status == E_OK) {
    returnValue = (partitionId == blockPartitionId);
  }

  return returnValue;
#else
  NVM_DUMMY_STATEMENT_CONST(blockDescriptorLookupTableId);                                                              /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return TRUE;
#endif /* NVM_MULTIPARTITION_USAGE_SCENARIO */
}

/**********************************************************************************************************************
 * NvM_IsBlockWithImmediatePriority()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
NVM_LOCAL_INLINE FUNC(boolean, NVM_PRIVATE_CODE) NvM_IsBlockWithImmediatePriority(
  const NvM_BlockDescriptorLookupTableIdType blockDescriptorLookupTableId)
{
  return (NvM_GetAddrBlockDescriptor(blockDescriptorLookupTableId)->Priority == NVM_BLOCK_PRIORITY_IMMEDIATE);
}

/**********************************************************************************************************************
 * NvM_IsWriteBlockOnceEnabled()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
NVM_LOCAL_INLINE FUNC(boolean, NVM_PRIVATE_CODE) NvM_IsWriteBlockOnceEnabled(
  const NvM_BlockDescriptorLookupTableIdType blockDescriptorLookupTableId)
{
  return (NvM_GetAddrBlockDescriptor(blockDescriptorLookupTableId)->
    Flags.WriteBlockOnceEnabled == NVM_WRITE_BLOCK_ONCE_ON);
}

/**********************************************************************************************************************
*  NvM_CheckAddress
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
NVM_LOCAL_INLINE FUNC(boolean, NVM_PRIVATE_CODE) NvM_CheckAddress(
  const NvM_BlockDescriptorLookupTableIdType blockDescriptorLookupTableId,
  const void * ramPtr)
{
  boolean returnValue = FALSE;

  /* for a request setup with RamPtr == NULL_PTR:
   * - permanent RAM OR explicit synchronization has to be configured */
  if (ramPtr == NULL_PTR)
  {
    NvM_BlockDescriptorPtrType blockDescriptor = NvM_GetAddrBlockDescriptor(blockDescriptorLookupTableId);
    returnValue = ((blockDescriptor->RamBlockDataAddress != NULL_PTR)
                    || (blockDescriptor->WriteRamBlockToNvCallback != NULL_PTR));
  }
  /* for a request setup with a temporary RAM block:
   * - given pointer needs to not be a NULL_PTR */
  else
  {
    returnValue = TRUE;
  }

  return returnValue;
}

/**********************************************************************************************************************
 * NvM_FinishMultiBlockJobTermination
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
NVM_LOCAL_INLINE FUNC(void, NVM_PRIVATE_CODE) NvM_FinishMultiBlockJobTermination(
  NvM_MultiBlockJobInformationPtrType multiBlockInfo,
  const NvM_MultiBlockJobType multiBlockJobType)
{
  /* Clear all multiblock job flags. Only possible since
  no more than one multiblock job can be requested at a time */
  multiBlockInfo->JobStatusFlag = 0u;

  multiBlockInfo->ErrorStatus = NVM_REQ_CANCELED;

  NvM_Notification_ProcessMultiBlockNotification(multiBlockJobType, multiBlockInfo->ErrorStatus);
}

/**********************************************************************************************************************
 * NvM_ResetAllSinglePartitionProcessingStacks()
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
 */
NVM_LOCAL_INLINE FUNC(void, NVM_PRIVATE_CODE) NvM_ResetAllSinglePartitionProcessingStacks(NvM_PartitionIdType partitionId)
{
  NvM_FsmLib_InstancePtrType fsmLibInstance =
    (NvM_FsmLib_InstancePtrType)NvM_GetAddrMultiBlockServiceFsmLib_Instance(partitionId);
  NvM_FsmLib_ClearProcessingStack(fsmLibInstance);

  /* In case an immediate job is requested, only the MultiBlockService stack
    is allowed to be cleared. Otherwise the immediate block processing gets manipulated,
    because it uses the SingleBlock/ServiceProcessor/NvService stack.
    After an immediate interruption the multi block job stack is no longer processed
    and hence automatically set on hold. After the immediate block job is finished,
    the multi block job stack processing is continued again, which was already cleared
    and hence no resuming is necessary. */
#if (NVM_JOB_PRIORITIZATION == STD_ON)
  if(NvM_ServiceProcessorFsm_IsImmediateJobActive(partitionId) == FALSE)
#endif /* NVM_JOB_PRIORITIZATION == STD_ON */
  {
    fsmLibInstance = (NvM_FsmLib_InstancePtrType)NvM_GetAddrNvServiceFsmLib_Instance(partitionId);
    NvM_FsmLib_ClearProcessingStack(fsmLibInstance);

    fsmLibInstance = (NvM_FsmLib_InstancePtrType)NvM_GetAddrSingleBlockServiceFsmLib_Instance(partitionId);
    NvM_FsmLib_ClearProcessingStack(fsmLibInstance);

    fsmLibInstance = (NvM_FsmLib_InstancePtrType)NvM_GetAddrServiceProcessorFsmLib_Instance(partitionId);
    NvM_FsmLib_ClearProcessingStack(fsmLibInstance);

    NvM_ServiceProcessorFsm_Spawn(partitionId);
  }
}

/**********************************************************************************************************************
 * NvM_GetPartitionIdViaBlockId()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
NVM_LOCAL_INLINE FUNC(NvM_PartitionIdType, NVM_PRIVATE_CODE) NvM_GetPartitionIdViaBlockId(
  const NvM_BlockDescriptorLookupTableIdType blockDescriptorLookupTableId)
{
  NvM_BlockDescriptorPtrType blockDescriptor = NvM_GetAddrBlockDescriptor(blockDescriptorLookupTableId);

  return blockDescriptor->PartitionId;
}
volatile uint8 DebugTest = 0;
/**********************************************************************************************************************
 * NvM_InitBasicFunctionality()
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
NVM_LOCAL_INLINE FUNC(void, NVM_PRIVATE_CODE) NvM_InitBasicFunctionality(NvM_PartitionIdType partitionId)
{
  NvM_FsmLib_InstancePtrType fsmLibInstance =
    (NvM_FsmLib_InstancePtrType)NvM_GetAddrServiceProcessorFsmLib_Instance(partitionId);

  NvM_ProcessingStackElementPtrType processingStack =
    NvM_GetAddrServiceProcessorFsmLib_ProcessingStackElement(0u, partitionId);

  NvM_Queue_InstancePtrType queueInstance = NvM_GetAddrQueue_Instance(partitionId);
  NvM_QueueListPtrType queueList = NvM_GetAddrQueueList(0u, partitionId);
  NvM_Queue_Init(queueInstance, NVM_SIZE_STANDARD_JOB_QUEUE, queueList);                                                /* FETA_NVM_ConstantQueueListSize_Caller */

#if (NVM_JOB_PRIORITIZATION == STD_ON)
  queueInstance = NvM_GetAddrImmediateQueue_Instance(partitionId);
  queueList = NvM_GetAddrImmediateQueueList(0u, partitionId);
  NvM_Queue_Init(queueInstance, NVM_SIZE_IMMEDIATE_JOB_QUEUE, queueList);                                               /* FETA_NVM_ConstantQueueListSize_Caller */
#endif /* NVM_JOB_PRIORITIZATION == STD_ON */

  NvM_FsmLib_Init(fsmLibInstance, processingStack, NVM_SERVICE_PROCESSOR_FSMLIB_PROCESSING_STACK_SIZE,                  /* FETA_NVM_ConstantProcessingStackSize_Caller */
    partitionId);
  NvM_ServiceProcessorFsm_Spawn(partitionId);

  /* Init all application level FSM stacks (MultiBlockService, SingleBlockService) and the NvService stack */
  fsmLibInstance = (NvM_FsmLib_InstancePtrType)NvM_GetAddrMultiBlockServiceFsmLib_Instance(partitionId);
  processingStack = NvM_GetAddrMultiBlockFsmLib_ProcessingStackElement(0u, partitionId);
  NvM_FsmLib_Init(fsmLibInstance, processingStack, NVM_MULTIBLOCK_FSMLIB_PROCESSING_STACK_SIZE,                         /* FETA_NVM_ConstantProcessingStackSize_Caller */
    partitionId);

  fsmLibInstance = (NvM_FsmLib_InstancePtrType)NvM_GetAddrSingleBlockServiceFsmLib_Instance(partitionId);
  processingStack = NvM_GetAddrSingleBlockFsmLib_ProcessingStackElement(0u, partitionId);
  NvM_FsmLib_Init(fsmLibInstance, processingStack, NVM_SINGLEBLOCK_FSMLIB_PROCESSING_STACK_SIZE,                        /* FETA_NVM_ConstantProcessingStackSize_Caller */
    partitionId);

  fsmLibInstance = (NvM_FsmLib_InstancePtrType)NvM_GetAddrNvServiceFsmLib_Instance(partitionId);
  processingStack = NvM_GetAddrNvServiceFsmLib_ProcessingStackElement(0u, partitionId);
  NvM_FsmLib_Init(fsmLibInstance, processingStack, NVM_NVSERVICE_FSMLIB_PROCESSING_STACK_SIZE, partitionId);            /* FETA_NVM_ConstantProcessingStackSize_Caller */

  /* Init DataIntegrityRecalcQueue */
  NvM_DataIntegrityRecalcQueue_InstancePtrType dataIntegrityRecalcQueueInstance =
    NvM_GetAddrDataIntegrityRecalcQueue_Instance(partitionId);

  NvM_DataIntegrityRecalcQueue_Init(dataIntegrityRecalcQueueInstance);

  /* Init BackgroundCrcRecalc Fsm */
  fsmLibInstance = (NvM_FsmLib_InstancePtrType)NvM_GetAddrBackgroundCrcRecalcFsmLib_Instance(partitionId);
  processingStack = NvM_GetAddrBackgroundCrcRecalcFsmLib_ProcessingStackElement(0u, partitionId);

  NvM_FsmLib_Init(fsmLibInstance, processingStack, NVM_BACKGROUNDCRCRECALC_FSMLIB_PROCESSING_STACK_SIZE, partitionId);  /* FETA_NVM_ConstantProcessingStackSize_Caller */
  NvM_BackgroundCrcRecalcFsm_Spawn(partitionId);

  NvM_DcmBlockManagementInfoPtrType dcmBlockManagementInfo = NvM_GetAddrDcmBlockManagementInfo(partitionId);

  dcmBlockManagementInfo->DataIndex = 0u;
  dcmBlockManagementInfo->ErrorStatus = NVM_REQ_OK;
  /* This block management info data does not belong to a specific block so RamBlockState can be initialized here */
  dcmBlockManagementInfo->RamBlockState = NVM_RAMBLOCKSTATE_INVALID_UNCHANGED;
  dcmBlockManagementInfo->BlockLocked = FALSE;
  dcmBlockManagementInfo->WriteProtection = FALSE;

  const NvM_BlockDescriptorLookupTableIdType blockCount = NvM_GetSizeOfBlockDescriptor();
  for (NvM_BlockDescriptorLookupTableIdType i = 0u; i < blockCount; i++)
  {
    NvM_BlockDescriptorPtrType blockDescriptor = NvM_GetAddrBlockDescriptor(i);
    DebugTest =  i;
#if (NVM_MULTIPARTITION_USAGE_SCENARIO == STD_ON)
    if (blockDescriptor->PartitionId == partitionId)
#endif
    {
      /* RamBlockState not initialized because must survive soft reset */
      blockDescriptor->BlockManagementInfo->DataIndex  = 0u;
      blockDescriptor->BlockManagementInfo->ErrorStatus = NVM_REQ_OK;
      blockDescriptor->BlockManagementInfo->BlockLocked = FALSE;
      blockDescriptor->BlockManagementInfo->WriteProtection =
        (blockDescriptor->Flags.BlockWriteProtEnabled == NVM_BLOCK_WRITE_PROT_ON) ? TRUE : FALSE;
    }
  }
}

/**********************************************************************************************************************
 * NvM_CheckBlockLockedStatus()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
NVM_LOCAL_INLINE FUNC(boolean, NVM_PRIVATE_CODE) NvM_CheckBlockLockedStatus(
  const NvM_BlockManagementInformationPtrToConstType blockManagementInfo,
  const NvM_PartitionIdType partitionId)
{
  boolean retVal = FALSE;
  NvM_DcmBlockManagementInfoPtrType dcmBlockManagementInfo = NvM_GetAddrDcmBlockManagementInfo(partitionId);

  if (blockManagementInfo != dcmBlockManagementInfo)
  {
    retVal = blockManagementInfo->BlockLocked;
  }

  /*
   * The parameter partitionId is not used within this function in single partition use case.
   * To avoid compiler warnings the following dummy statement is added.
   */
  NVM_DUMMY_STATEMENT_CONST(partitionId);                                                                               /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  return retVal;
}

/**********************************************************************************************************************
 * NvM_CancelMemIfConditionally()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
NVM_LOCAL_INLINE FUNC(void, NVM_PRIVATE_CODE) NvM_CancelMemIfConditionally(
  const NvM_BlockDescriptorLookupTableIdType lastProcessedBlockId)
{
    NvM_BlockDescriptorPtrType blockDescriptor = NvM_GetAddrBlockDescriptor(lastProcessedBlockId);

#if (NVM_JOB_PRIORITIZATION == STD_ON)
    const boolean isImmediateJobActive = NvM_ServiceProcessorFsm_IsImmediateJobActive(NVM_PARTITION_ID_MASTER);

    /* It is not allowed to cancel the MemIf in case an immediate job is currently active,
      because otherwise the immediate job might be canceled in case the MemIfDeviceIndex is
      the same as for the last processed block of the ReadAll job. */
    if (isImmediateJobActive == FALSE)
#endif /* NVM_JOB_PRIORITIZATION == STD_ON */
    {
      if (MemIf_GetStatus((uint8)blockDescriptor->MemIfDeviceIndex) == MEMIF_BUSY)
      {
        MemIf_Cancel((uint8)blockDescriptor->MemIfDeviceIndex);
      }
    }
}

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * NvM_Init
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
 *
 *
 *
 *
 *
 *
 */
 FUNC(void, NVM_PUBLIC_CODE) NvM_Init(void)
{
  NvM_PartitionIdType partitionId = NVM_PARTITION_ID_MASTER;

#if (NVM_MULTIPARTITION_USAGE_SCENARIO == STD_ON)
  NvM_FsmLib_InstancePtrType fsmLibInstance = (NvM_FsmLib_InstancePtrType)NULL_PTR;
  NvM_ProcessingStackElementPtrType processingStack = (NvM_ProcessingStackElementPtrType)NULL_PTR;
  const ApplicationType osId = NvM_GetOsPartitionId();
  Std_ReturnType status = NvM_GlobalUtilityLib_GetPartitionId(&partitionId, osId);

  if (status == E_OK)
  {
    NvM_InitBasicFunctionality(partitionId);

    if (partitionId == NVM_PARTITION_ID_MASTER)
    {
      fsmLibInstance = (NvM_FsmLib_InstancePtrType)NvM_GetAddrNvServiceProcessorFsmLib_Instance(partitionId);
      processingStack = NvM_GetAddrNvServiceProcessorFsmLib_ProcessingStackElement(0u, partitionId);

      NvM_FsmLib_Init(fsmLibInstance, processingStack, NVM_NVSERVICE_PROCESSOR_FSMLIB_PROCESSING_STACK_SIZE,            /* FETA_NVM_ConstantProcessingStackSize_Caller */
        partitionId);
      NvM_NvServiceProcessorFsm_Spawn(partitionId);

      /* Init MultiBlockProcessor Fsm */
      fsmLibInstance = (NvM_FsmLib_InstancePtrType)NvM_GetAddrMultiBlockProcessorFsmLib_Instance(partitionId);
      processingStack = NvM_GetAddrMultiBlockProcessorFsmLib_ProcessingStackElement(0u, partitionId);

      NvM_FsmLib_Init(fsmLibInstance, processingStack, NVM_MULTIBLOCKPROCESSOR_FSMLIB_PROCESSING_STACK_SIZE,            /* FETA_NVM_ConstantProcessingStackSize_Caller */
        partitionId);
      NvM_MultiBlockProcessorFsm_Spawn(partitionId);

      /* Reset multiblock job status flag */
      NvM_MultiBlockJobInformationPtrType multiBlockJobInfo =
        NvM_GetAddrMultiBlockJobInformation(NVM_PARTITION_ID_MASTER);

      multiBlockJobInfo->JobStatusFlag = 0u;
      multiBlockJobInfo->ErrorStatus = NVM_REQ_OK;

      NvM_IsModuleInitialized = TRUE;
    }
  }

#else /* NVM_MULTIPARTITION_USAGE_SCENARIO == STD_OFF */

  NvM_InitBasicFunctionality(partitionId);

  /* Reset multiblock job status flag */
  NvM_MultiBlockJobInformationPtrType multiBlockJobInfo =
    NvM_GetAddrMultiBlockJobInformation(NVM_PARTITION_ID_MASTER);

  multiBlockJobInfo->JobStatusFlag = 0u;
  multiBlockJobInfo->ErrorStatus = NVM_REQ_OK;

  NvM_IsModuleInitialized = TRUE;

#endif /* NVM_MULTIPARTITION_USAGE_SCENARIO */

}

/**********************************************************************************************************************
 * NvM_MainFunction
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
FUNC(void, NVM_PUBLIC_CODE) NvM_MainFunction(void)                                                                      /* PRQA S 3206 */ /* MD_NvM_CslMacroNotUsingPartitionId */
{
#if (NVM_MULTIPARTITION_USAGE_SCENARIO == STD_ON)
  Std_ReturnType status = E_NOT_OK;
  NvM_PartitionIdType partitionId = NVM_PARTITION_ID_MASTER;

  const ApplicationType osId = NvM_GetOsPartitionId();

  status = NvM_GlobalUtilityLib_GetPartitionId(&partitionId, osId);

  if (status == E_OK)
  {
    /* Process BackgroundCrcRecalc Fsm */
    NvM_FsmLib_InstancePtrToConstType fsmLibInstance =
      (NvM_FsmLib_InstancePtrType)NvM_GetAddrBackgroundCrcRecalcFsmLib_Instance(partitionId);
    NvM_FsmLib_ProcessCurrentActiveFsm(fsmLibInstance);

    /* Process the service processor Fsm */
    fsmLibInstance = (NvM_FsmLib_InstancePtrType)NvM_GetAddrServiceProcessorFsmLib_Instance(partitionId);
    NvM_FsmLib_ProcessCurrentActiveFsm(fsmLibInstance);
  }
#else

  /* Process BackgroundCrcRecalc Fsm */
  NvM_FsmLib_InstancePtrToConstType fsmLibInstance =
    (NvM_FsmLib_InstancePtrType)NvM_GetAddrBackgroundCrcRecalcFsmLib_Instance(NVM_PARTITION_ID_MASTER);
  NvM_FsmLib_ProcessCurrentActiveFsm(fsmLibInstance);

  /* In single partition use case only one call context is valid, so the partition Id can be set to the following.
   * Partition id is only relevant for internal use in single partition usage scenario.
   */

  /* Process the service processor Fsm */
  fsmLibInstance = (NvM_FsmLib_InstancePtrType)NvM_GetAddrServiceProcessorFsmLib_Instance(NVM_PARTITION_ID_MASTER);
  NvM_FsmLib_ProcessCurrentActiveFsm(fsmLibInstance);

#endif /* NVM_MULTIPARTITION_USAGE_SCENARIO */
}

#if (NVM_MULTIPARTITION_USAGE_SCENARIO == STD_ON)
/**********************************************************************************************************************
 * NvM_MainFunctionMaster
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, NVM_PUBLIC_CODE) NvM_MainFunctionMaster(void)
{
  NvM_FsmLib_InstancePtrToConstType fsmLibInstance = (NvM_FsmLib_InstancePtrToConstType)NULL_PTR;

  fsmLibInstance = (NvM_FsmLib_InstancePtrType)NvM_GetAddrNvServiceProcessorFsmLib_Instance(NVM_PARTITION_ID_MASTER);
  NvM_FsmLib_ProcessCurrentActiveFsm(fsmLibInstance);

  fsmLibInstance = (NvM_FsmLib_InstancePtrType)NvM_GetAddrMultiBlockProcessorFsmLib_Instance(NVM_PARTITION_ID_MASTER);
  NvM_FsmLib_ProcessCurrentActiveFsm(fsmLibInstance);

  /* Only the following errors are supported at the moment. Therefore the function is just called twice. */
  NvM_ErrorCheck_DispatchDemErrorCountConditionally(NVM_DEM_ERROR_TYPE_REQ_FAILED);
  NvM_ErrorCheck_DispatchDemErrorCountConditionally(NVM_DEM_ERROR_TYPE_INTEGRITY_FAILED);
}
#endif /* NVM_MULTIPARTITION_USAGE_SCENARIO */

/**********************************************************************************************************************
 * NvM_GetErrorStatus
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
 * \spec
 *    requires RequestResultPtr != 0;
 * \endspec
 */
FUNC(Std_ReturnType, NVM_PUBLIC_CODE) NvM_GetErrorStatus(
  NvM_BlockIdType BlockId,
  P2VAR(NvM_RequestResultType, AUTOMATIC, NVM_APPL_DATA) RequestResultPtr)
{
  Std_ReturnType retVal = E_NOT_OK;
  NvM_DetErrorIdType detError = NVM_E_NO_ERROR;

  NvM_BlockDescriptorLookupTableIdType blockDescriptorLookupTableId = 0u;
  boolean isBlockValid = FALSE;

  if (BlockId == NvMConf_NvMBlockDescriptor_NvMMultiBlock)
  {
    isBlockValid = TRUE;
  }
  else
  {
    isBlockValid = NvM_GlobalUtilityLib_FindBlockDescriptorLookupTableId(BlockId, &blockDescriptorLookupTableId);
  }

  if (NvM_ErrorCheck_IsDetConditionTrue(NvM_IsModuleInitialized == FALSE))
  {
    detError = NVM_E_UNINIT;
  }
  else if (NvM_ErrorCheck_IsDetConditionTrue(!isBlockValid))
  {
    detError = NVM_E_PARAM_BLOCK_ID;
  }
  else if (NvM_ErrorCheck_IsDetConditionTrue(RequestResultPtr == NULL_PTR))
  {
    detError = NVM_E_PARAM_DATA;
  }
  else
  {
    if (BlockId == NvMConf_NvMBlockDescriptor_NvMMultiBlock)
    {
      NvM_MultiBlockJobInformationType multiBlockJobInfo = NvM_GetMultiBlockJobInformation(NVM_PARTITION_ID_MASTER);
      *RequestResultPtr = multiBlockJobInfo.ErrorStatus;
    }
    else
    {
      NvM_PartitionIdType partitionId = NvM_GetPartitionIdViaBlockId(blockDescriptorLookupTableId);                     /* PRQA S 3205 */ /* MD_NvM_CslMacroNotUsingPartitionId */
      NvM_BlockManagementInformationPtrType blockManagementInfo =
        NvM_GlobalUtilityLib_GetBlockManagementInfo(BlockId, blockDescriptorLookupTableId, partitionId);

      *RequestResultPtr = blockManagementInfo->ErrorStatus;
    }

    retVal = E_OK;
  }

  NvM_ErrorCheck_ReportDetErrorConditionally(NVM_SID_GETERRORSTATUS, detError);

  return retVal;
}


/**********************************************************************************************************************
 * NvM_SetRamBlockStatus
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
FUNC(Std_ReturnType, NVM_PUBLIC_CODE) NvM_SetRamBlockStatus(                                                            /* PRQA S 6080 */ /* MD_MSR_STMIF */
  NvM_BlockIdType BlockId,
  boolean BlockChanged)
{
  Std_ReturnType retVal = E_NOT_OK;
  NvM_DetErrorIdType detError = NVM_E_NO_ERROR;

  NvM_BlockDescriptorLookupTableIdType blockDescriptorLookupTableId = 0u;
  const boolean isBlockValid =
    NvM_GlobalUtilityLib_FindBlockDescriptorLookupTableId(BlockId, &blockDescriptorLookupTableId);

  const NvM_PartitionIdType partitionId = NvM_GetPartitionIdViaBlockId(blockDescriptorLookupTableId);                   /* PRQA S 3205 */ /* MD_NvM_CslMacroNotUsingPartitionId */

  if (NvM_ErrorCheck_IsDetConditionTrue(NvM_IsModuleInitialized == FALSE))
  {
    detError = NVM_E_UNINIT;
  }
  else if (NvM_ErrorCheck_IsDetConditionTrue(!isBlockValid))
  {
    detError = NVM_E_PARAM_BLOCK_ID;
  }
  else if (NvM_ErrorCheck_IsDetConditionTrue(
    NvM_IsBlockPending(BlockId, blockDescriptorLookupTableId, partitionId) == TRUE))
  {
    detError = NVM_E_BLOCK_PENDING;
  }
  else if (NvM_ErrorCheck_IsDetConditionTrue(NvM_IsPartitionContextValid(blockDescriptorLookupTableId) == FALSE))       /* PRQA S 2996 */ /* MD_NvM_SinglePartitionDefault */ /* COV_NVM_SINGLEPARTITION_DEFAULT */
  {
    detError = NVM_E_PARAM_BLOCK_ID;
  }
  else
  {
    NvM_BlockDescriptorPtrType blockDescriptor = NvM_GetAddrBlockDescriptor(blockDescriptorLookupTableId);

    if (blockDescriptor->Flags.BlockUseSetRamBlockStatusEnabled == NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON)
    {
      NvM_GlobalUtilityLib_EnterCriticalSection();
      {
        if (BlockChanged)
        {
          blockDescriptor->BlockManagementInfo->RamBlockState = NVM_RAMBLOCKSTATE_VALID_CHANGED;

          if (blockDescriptor->Flags.CalcRamBlockCrcEnabled == NVM_CALC_RAM_BLOCK_CRC_ON)
          {
            NvM_DataIntegrityRecalcQueue_InstancePtrType recalcQueueInstance = NvM_GetAddrDataIntegrityRecalcQueue_Instance(partitionId);
            NvM_DataIntegrityRecalcQueue_Push(recalcQueueInstance, blockDescriptorLookupTableId);
          }
        }
        else
        {
          blockDescriptor->BlockManagementInfo->RamBlockState = NVM_RAMBLOCKSTATE_INVALID_UNCHANGED;
        }
      }
      NvM_GlobalUtilityLib_ExitCriticalSection();

      retVal = E_OK;
    }
  }

  NvM_ErrorCheck_ReportDetErrorConditionally(NVM_SID_SETRAMBLOCKSTATUS, detError);

  return retVal;
}

/**********************************************************************************************************************
 * NvM_GetDataIndex
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
 *
 *
 *
 * \spec
 *    requires DataIndexPtr != 0;
 * \endspec
 */
FUNC(Std_ReturnType, NVM_PUBLIC_CODE) NvM_GetDataIndex(                                                                 /* PRQA S 6080 */ /* MD_MSR_STMIF */
  NvM_BlockIdType BlockId,
  P2VAR(uint8, AUTOMATIC, NVM_APPL_DATA) DataIndexPtr)
{
  Std_ReturnType retVal = E_NOT_OK;
  NvM_DetErrorIdType detError = NVM_E_NO_ERROR;

  NvM_BlockDescriptorLookupTableIdType blockDescriptorLookupTableId = 0u;
  const boolean isBlockValid =
    NvM_GlobalUtilityLib_FindBlockDescriptorLookupTableId(BlockId, &blockDescriptorLookupTableId);

  if (NvM_ErrorCheck_IsDetConditionTrue(NvM_IsModuleInitialized == FALSE))
  {
    detError = NVM_E_UNINIT;
  }
  else if (NvM_ErrorCheck_IsDetConditionTrue(!isBlockValid))
  {
    detError = NVM_E_PARAM_BLOCK_ID;
  }
  else if (NvM_ErrorCheck_IsDetConditionTrue(NvM_IsPartitionContextValid(blockDescriptorLookupTableId) == FALSE))       /* PRQA S 2996 */ /* MD_NvM_SinglePartitionDefault */ /* COV_NVM_SINGLEPARTITION_DEFAULT */
  {
    detError = NVM_E_PARAM_BLOCK_ID;
  }
  else if (NvM_ErrorCheck_IsDetConditionTrue(DataIndexPtr == NULL_PTR))
  {
    detError = NVM_E_PARAM_DATA;
  }
  else
  {
    NvM_BlockDescriptorPtrType blockDescriptor = NvM_GetAddrBlockDescriptor(blockDescriptorLookupTableId);
    const NvM_PartitionIdType partitionId = NvM_GetPartitionIdViaBlockId(blockDescriptorLookupTableId);                 /* PRQA S 3205 */ /* MD_NvM_CslMacroNotUsingPartitionId */
    NvM_BlockManagementInformationPtrType blockManagementInfo =
      NvM_GlobalUtilityLib_GetBlockManagementInfo(BlockId, blockDescriptorLookupTableId, partitionId);

    if (blockDescriptor->BlockManagementType == NVM_BLOCK_MANAGEMENT_TYPE_DATASET)
    {
      *DataIndexPtr = blockManagementInfo->DataIndex;
      retVal = E_OK;
    }
    else
    {
      *DataIndexPtr = 0u;
    }
  }

  NvM_ErrorCheck_ReportDetErrorConditionally(NVM_SID_GETDATAINDEX, detError);

  return retVal;
}


/**********************************************************************************************************************
 * NvM_SetDataIndex
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
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, NVM_PUBLIC_CODE) NvM_SetDataIndex(                                                                 /* PRQA S 6080 */ /* MD_MSR_STMIF */
  NvM_BlockIdType BlockId,
  uint8 DataIndex)
{
  Std_ReturnType retVal = E_NOT_OK;
  NvM_DetErrorIdType detError = NVM_E_NO_ERROR;

  NvM_BlockDescriptorLookupTableIdType blockDescriptorLookupTableId = 0u;
  const boolean isBlockValid =
    NvM_GlobalUtilityLib_FindBlockDescriptorLookupTableId(BlockId, &blockDescriptorLookupTableId);

  const NvM_PartitionIdType partitionId = NvM_GetPartitionIdViaBlockId(blockDescriptorLookupTableId);                   /* PRQA S 3205 */ /* MD_NvM_CslMacroNotUsingPartitionId */

  if (NvM_ErrorCheck_IsDetConditionTrue(NvM_IsModuleInitialized == FALSE))
  {
    detError = NVM_E_UNINIT;
  }
  else if (NvM_ErrorCheck_IsDetConditionTrue(!isBlockValid))
  {
    detError = NVM_E_PARAM_BLOCK_ID;
  }
  else if (NvM_ErrorCheck_IsDetConditionTrue(
    NvM_IsBlockPending(BlockId, blockDescriptorLookupTableId, partitionId) == TRUE))
  {
    detError = NVM_E_BLOCK_PENDING;
  }
  else if (NvM_ErrorCheck_IsDetConditionTrue(NvM_IsDataIndexValid(blockDescriptorLookupTableId, DataIndex) == FALSE))
  {
    detError = NVM_E_PARAM_BLOCK_DATA_IDX;
  }
  else if (NvM_ErrorCheck_IsDetConditionTrue(NvM_IsPartitionContextValid(blockDescriptorLookupTableId) == FALSE))       /* PRQA S 2996 */ /* MD_NvM_SinglePartitionDefault */ /* COV_NVM_SINGLEPARTITION_DEFAULT */
  {
    detError = NVM_E_PARAM_BLOCK_ID;
  }
  else
  {
    NvM_BlockDescriptorPtrType blockDescriptor = NvM_GetAddrBlockDescriptor(blockDescriptorLookupTableId);
    NvM_BlockManagementInformationPtrType blockManagementInfo =
      NvM_GlobalUtilityLib_GetBlockManagementInfo(BlockId, blockDescriptorLookupTableId, partitionId);

    if (blockDescriptor->BlockManagementType == NVM_BLOCK_MANAGEMENT_TYPE_DATASET)
    {
      blockManagementInfo->DataIndex = DataIndex;
      retVal = E_OK;
    }
  }

  NvM_ErrorCheck_ReportDetErrorConditionally(NVM_SID_SETDATAINDEX, detError);

  return retVal;
}


/**********************************************************************************************************************
 * NvM_SetBlockProtection
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
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, NVM_PUBLIC_CODE) NvM_SetBlockProtection(                                                           /* PRQA S 6080 */ /* MD_MSR_STMIF */
  NvM_BlockIdType BlockId,
  boolean ProtectionEnabled)
{
  Std_ReturnType retVal = E_NOT_OK;
  NvM_DetErrorIdType detError = NVM_E_NO_ERROR;

  NvM_BlockDescriptorLookupTableIdType blockDescriptorLookupTableId = 0u;
  const boolean isBlockValid =
    NvM_GlobalUtilityLib_FindBlockDescriptorLookupTableId(BlockId, &blockDescriptorLookupTableId);

  const NvM_PartitionIdType partitionId = NvM_GetPartitionIdViaBlockId(blockDescriptorLookupTableId);                   /* PRQA S 3205 */ /* MD_NvM_CslMacroNotUsingPartitionId */

  if (NvM_ErrorCheck_IsDetConditionTrue(NvM_IsModuleInitialized == FALSE))
  {
    detError = NVM_E_UNINIT;
  }
  else if (NvM_ErrorCheck_IsDetConditionTrue(!isBlockValid))
  {
    detError = NVM_E_PARAM_BLOCK_ID;
  }
  else if (NvM_ErrorCheck_IsDetConditionTrue(NvM_IsBlockPending(BlockId, blockDescriptorLookupTableId, partitionId) == TRUE))
  {
    detError = NVM_E_BLOCK_PENDING;
  }
  else if (NvM_ErrorCheck_IsDetConditionTrue(NvM_IsPartitionContextValid(blockDescriptorLookupTableId) == FALSE))       /* PRQA S 2996 */ /* MD_NvM_SinglePartitionDefault */ /* COV_NVM_SINGLEPARTITION_DEFAULT */
  {
    detError = NVM_E_PARAM_BLOCK_ID;
  }
  else
  {
    if (NvM_IsWriteBlockOnceEnabled(blockDescriptorLookupTableId) == FALSE)
    {
      NvM_GlobalUtilityLib_EnterCriticalSection();
      {
        NvM_BlockManagementInformationPtrType blockManagementInfo =
          NvM_GlobalUtilityLib_GetBlockManagementInfo(BlockId, blockDescriptorLookupTableId, partitionId);

        blockManagementInfo->WriteProtection = ProtectionEnabled;
        retVal = E_OK;
      }
      NvM_GlobalUtilityLib_ExitCriticalSection();
    }
    else
    {
#if (NVM_DEV_ERROR_DETECT == STD_ON)
      detError = NVM_E_BLOCK_CONFIG;
#endif
    }
  }

  NvM_ErrorCheck_ReportDetErrorConditionally(NVM_SID_SETBLOCKPROTECTION, detError);

  return retVal;
}

/**********************************************************************************************************************
 * NvM_SetBlockLockStatus
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
 *
 *
 */
FUNC(void, NVM_PUBLIC_CODE) NvM_SetBlockLockStatus(                                                                     /* PRQA S 6080 */ /* MD_MSR_STMIF */
  NvM_BlockIdType BlockId,
  boolean BlockLocked)
{
  NvM_DetErrorIdType detError = NVM_E_NO_ERROR;

  NvM_BlockDescriptorLookupTableIdType blockDescriptorLookupTableId = 0u;
  const boolean isBlockValid =
    NvM_GlobalUtilityLib_FindBlockDescriptorLookupTableId(BlockId, &blockDescriptorLookupTableId);

  const NvM_PartitionIdType partitionId = NvM_GetPartitionIdViaBlockId(blockDescriptorLookupTableId);                   /* PRQA S 3205 */ /* MD_NvM_CslMacroNotUsingPartitionId */

  if (NvM_ErrorCheck_IsDetConditionTrue(NvM_IsModuleInitialized == FALSE))
  {
    detError = NVM_E_UNINIT;
  }
  else if (NvM_ErrorCheck_IsDetConditionTrue(!isBlockValid))
  {
    detError = NVM_E_PARAM_BLOCK_ID;
  }
  else if (NvM_ErrorCheck_IsDetConditionTrue(
    NvM_IsBlockPending(BlockId, blockDescriptorLookupTableId, partitionId) == TRUE))
  {
    detError = NVM_E_BLOCK_PENDING;
  }
  else if (NvM_ErrorCheck_IsDetConditionTrue(NvM_IsPartitionContextValid(blockDescriptorLookupTableId) == FALSE))       /* PRQA S 2996 */ /* MD_NvM_SinglePartitionDefault */ /* COV_NVM_SINGLEPARTITION_DEFAULT */
  {
    detError = NVM_E_PARAM_BLOCK_ID;
  }
  else
  {
    NvM_GlobalUtilityLib_EnterCriticalSection();
    {
      if (NvM_CheckAddress(blockDescriptorLookupTableId, NULL_PTR))
      {
        NvM_BlockDescriptorPtrType blockDescriptor = NvM_GetAddrBlockDescriptor(blockDescriptorLookupTableId);
        blockDescriptor->BlockManagementInfo->BlockLocked = BlockLocked;
      }
    }
    NvM_GlobalUtilityLib_ExitCriticalSection();
  }

  NvM_ErrorCheck_ReportDetErrorConditionally(NVM_SID_SETBLOCKLOCKSTATUS, detError);
}

/**********************************************************************************************************************
 * NvM_CancelJobs
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
 */
FUNC(Std_ReturnType, NVM_PUBLIC_CODE) NvM_CancelJobs(
  NvM_BlockIdType BlockId)
{
  Std_ReturnType retVal = E_NOT_OK;
  NvM_DetErrorIdType detError = NVM_E_NO_ERROR;
  NvM_BlockDescriptorLookupTableIdType blockDescriptorLookupTableId = 0u;
  const boolean isBlockValid =
    NvM_GlobalUtilityLib_FindBlockDescriptorLookupTableId(BlockId, &blockDescriptorLookupTableId);

  if (NvM_ErrorCheck_IsDetConditionTrue(NvM_IsModuleInitialized == FALSE))
  {
    detError = NVM_E_UNINIT;
  }
  else if (NvM_ErrorCheck_IsDetConditionTrue(!isBlockValid))
  {
    detError = NVM_E_PARAM_BLOCK_ID;
  }
  else if (NvM_ErrorCheck_IsDetConditionTrue(NvM_IsPartitionContextValid(blockDescriptorLookupTableId) == FALSE))       /* PRQA S 2996 */ /* MD_NvM_SinglePartitionDefault */ /* COV_NVM_SINGLEPARTITION_DEFAULT */
  {
    detError = NVM_E_PARAM_BLOCK_ID;
  }
  else
  {
    NvM_GlobalUtilityLib_EnterCriticalSection();
    {
      const NvM_PartitionIdType partitionId = NvM_GetPartitionIdViaBlockId(blockDescriptorLookupTableId);
      NvM_Queue_InstancePtrType queueInstance = NvM_GetAddrQueue_Instance(partitionId);

      retVal = NvM_Queue_CancelJobs(queueInstance, partitionId, BlockId);
    }
    NvM_GlobalUtilityLib_ExitCriticalSection();
  }

  NvM_ErrorCheck_ReportDetErrorConditionally(NVM_SID_CANCELJOBS, detError);
  return retVal;
}


/**********************************************************************************************************************
 *  NvM_GetVersionInfo
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 * \spec
 *    requires Versioninfo != 0;
 * \endspec
 */
FUNC(void, NVM_PUBLIC_CODE) NvM_GetVersionInfo(
  P2VAR(Std_VersionInfoType, AUTOMATIC, NVM_APPL_DATA) Versioninfo)
{
  NvM_DetErrorIdType detError = NVM_E_NO_ERROR;

  if (NvM_ErrorCheck_IsDetConditionTrue(Versioninfo == NULL_PTR))
  {
    detError = NVM_E_PARAM_POINTER;
  }
  else
  {
    Versioninfo->vendorID = (NVM_VENDOR_ID);
    Versioninfo->moduleID = (NVM_MODULE_ID);
    Versioninfo->sw_major_version = (NVM_SW_MAJOR_VERSION);
    Versioninfo->sw_minor_version = (NVM_SW_MINOR_VERSION);
    Versioninfo->sw_patch_version = (NVM_SW_PATCH_VERSION);
  }

  NvM_ErrorCheck_ReportDetErrorConditionally(NVM_SID_GETVERSIONINFO, detError);
}


/**********************************************************************************************************************
 * NvM_ReadBlock
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
 *
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, NVM_PUBLIC_CODE) NvM_ReadBlock(                                                                    /* PRQA S 6080 */ /* MD_MSR_STMIF */
  NvM_BlockIdType BlockId,
  P2VAR(void, AUTOMATIC, NVM_APPL_DATA) NvM_DstPtr)
{
  Std_ReturnType retVal = E_NOT_OK;
  NvM_DetErrorIdType detError = NVM_E_NO_ERROR;

  NvM_BlockDescriptorLookupTableIdType blockDescriptorLookupTableId = 0u;
  const boolean isBlockValid =
    NvM_GlobalUtilityLib_FindBlockDescriptorLookupTableId(BlockId, &blockDescriptorLookupTableId);

  const NvM_PartitionIdType partitionId = NvM_GetPartitionIdViaBlockId(blockDescriptorLookupTableId);                   /* PRQA S 3205 */ /* MD_NvM_CslMacroNotUsingPartitionId */

  /* Note: NULL pointer indicates that the API shall behave as defined in NvM_ReadPRAMBlock */
  if (NvM_ErrorCheck_IsDetConditionTrue(NvM_IsModuleInitialized == FALSE))
  {
    detError = NVM_E_UNINIT;
  }
  else if (NvM_ErrorCheck_IsDetConditionTrue(!isBlockValid))
  {
    detError = NVM_E_PARAM_BLOCK_ID;
  }
  else if (NvM_ErrorCheck_IsDetConditionTrue(
    NvM_IsBlockPending(BlockId, blockDescriptorLookupTableId, partitionId) == TRUE))
  {
    detError = NVM_E_BLOCK_PENDING;
  }
  else if (NvM_ErrorCheck_IsDetConditionTrue(NvM_CheckAddress(blockDescriptorLookupTableId, NvM_DstPtr) == FALSE))
  {
    detError = NVM_E_PARAM_ADDRESS;
  }
  else if (NvM_ErrorCheck_IsDetConditionTrue(NvM_IsPartitionContextValid(blockDescriptorLookupTableId) == FALSE))       /* PRQA S 2996 */ /* MD_NvM_SinglePartitionDefault */ /* COV_NVM_SINGLEPARTITION_DEFAULT */
  {
    detError = NVM_E_PARAM_BLOCK_ID;
  }
  else
  {
    const NvM_Queue_JobType queueJob = {
      (NvM_DataPtrType)NvM_DstPtr,                                                                                      /* PRQA S 0316 */ /* MD_PointerTypeCast_VoidToDataPtr */
      BlockId,
      blockDescriptorLookupTableId,
      NVM_SINGLEBLOCKJOBTYPE_READ_BLOCK
    };

    NvM_GlobalUtilityLib_EnterCriticalSection();
    {
      NvM_BlockManagementInformationPtrType blockManagementInfo =
        NvM_GlobalUtilityLib_GetBlockManagementInfo(BlockId, blockDescriptorLookupTableId, partitionId);

      NvM_Queue_InstancePtrType queueInstance = NvM_GetAddrQueue_Instance(partitionId);
      retVal = NvM_Queue_Push(queueInstance, &queueJob, NVM_SID_READBLOCK);

      if (retVal == E_OK)
      {
        blockManagementInfo->ErrorStatus = NVM_REQ_PENDING;
        blockManagementInfo->RamBlockState = NVM_RAMBLOCKSTATE_INVALID_UNCHANGED;
      }

      /*
       * The parameter partitionId is not used within this function in single partition use case.
       * To avoid compiler warnings the following dummy statement is added.
       */
      NVM_DUMMY_STATEMENT_CONST(partitionId);                                                                           /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
    }
    NvM_GlobalUtilityLib_ExitCriticalSection();
  }

  NvM_ErrorCheck_ReportDetErrorConditionally(NVM_SID_READBLOCK, detError);

  return retVal;
}


/**********************************************************************************************************************
 * NvM_ReadPRAMBlock
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, NVM_PUBLIC_CODE) NvM_ReadPRAMBlock(
  NvM_BlockIdType BlockId)
{
  return NvM_ReadBlock(BlockId, NULL_PTR);
}


/**********************************************************************************************************************
 * NvM_WriteBlock
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
 *
 *
 */
FUNC(Std_ReturnType, NVM_PUBLIC_CODE) NvM_WriteBlock(                                                                   /* PRQA S 6080 */ /* MD_MSR_STMIF */
  NvM_BlockIdType BlockId,
  P2CONST(void, AUTOMATIC, NVM_APPL_DATA) SrcPtr)
{
  Std_ReturnType retVal = E_NOT_OK;
  NvM_DetErrorIdType detError = NVM_E_NO_ERROR;

  NvM_BlockDescriptorLookupTableIdType blockDescriptorLookupTableId = 0u;
  const boolean isBlockValid =
    NvM_GlobalUtilityLib_FindBlockDescriptorLookupTableId(BlockId, &blockDescriptorLookupTableId);

  const NvM_PartitionIdType partitionId = NvM_GetPartitionIdViaBlockId(blockDescriptorLookupTableId);                   /* PRQA S 3205 */ /* MD_NvM_CslMacroNotUsingPartitionId */

  /* Note: NULL pointer indicates that the API shall behave as defined in NvM_WritePRAMBlock */
  if (NvM_ErrorCheck_IsDetConditionTrue(NvM_IsModuleInitialized == FALSE))
  {
    detError = NVM_E_UNINIT;
  }
  else if (NvM_ErrorCheck_IsDetConditionTrue(!isBlockValid))
  {
    detError = NVM_E_PARAM_BLOCK_ID;
  }
  else if (NvM_ErrorCheck_IsDetConditionTrue(
    NvM_IsBlockPending(BlockId, blockDescriptorLookupTableId, partitionId) == TRUE))
  {
    detError = NVM_E_BLOCK_PENDING;
  }
  else if (NvM_ErrorCheck_IsDetConditionTrue(NvM_CheckAddress(blockDescriptorLookupTableId, SrcPtr) == FALSE))
  {
    detError = NVM_E_PARAM_ADDRESS;
  }
  else if (NvM_ErrorCheck_IsDetConditionTrue(NvM_IsPartitionContextValid(blockDescriptorLookupTableId) == FALSE))       /* PRQA S 2996 */ /* MD_NvM_SinglePartitionDefault */ /* COV_NVM_SINGLEPARTITION_DEFAULT */
  {
    detError = NVM_E_PARAM_BLOCK_ID;
  }
  else
  {
    const NvM_Queue_JobType queueJob = {
      (NvM_DataPtrType)SrcPtr,                                                                                          /* PRQA S 0316, 0311 */ /* MD_PointerTypeCast_VoidToDataPtr, MD_PointerTypeCast_LossOfQualification */
      BlockId,
      blockDescriptorLookupTableId,
      NVM_SINGLEBLOCKJOBTYPE_WRITE_BLOCK
    };

    NvM_GlobalUtilityLib_EnterCriticalSection();
    {
      NvM_BlockManagementInformationPtrType blockManagementInfo =
        NvM_GlobalUtilityLib_GetBlockManagementInfo(BlockId, blockDescriptorLookupTableId, partitionId);

      if (blockManagementInfo->WriteProtection == TRUE)
      {
#if (NVM_DEV_ERROR_DETECT == STD_ON)
        detError = NVM_E_WRITE_PROTECTED;
#endif /* NVM_DEV_ERROR_DETECT == STD_ON */
      }
      else if (NvM_CheckBlockLockedStatus(blockManagementInfo, partitionId) == FALSE)
      {
        NvM_Queue_InstancePtrType queueInstance = NvM_GetAddrQueue_Instance(partitionId);

#if (NVM_JOB_PRIORITIZATION == STD_ON)
        NvM_BlockDescriptorPtrType requestedBlockPtr = NvM_GetAddrBlockDescriptor(blockDescriptorLookupTableId);

        if (requestedBlockPtr->Priority == NVM_IMMEDIATE_JOB_PRIORITY)
        {
          queueInstance = NvM_GetAddrImmediateQueue_Instance(partitionId);
        }
#endif /* NVM_JOB_PRIORITIZATION == STD_ON */

        retVal = NvM_Queue_Push(queueInstance, &queueJob, NVM_SID_WRITEBLOCK);

        if (retVal == E_OK)
        {
          blockManagementInfo->ErrorStatus = NVM_REQ_PENDING;
          blockManagementInfo->RamBlockState = NVM_RAMBLOCKSTATE_VALID_CHANGED;
        }
      }
      else
      {
        /*
         * MISRA case. Do nothing.
         * This default case is empty due to the fact that the executed checks
         * are sufficient in this case.
         */
      }

      /* CSL optimization of single partition configurations lead to unused variable warning. */
      NVM_DUMMY_STATEMENT_CONST(partitionId);                                                                           /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
    }
    NvM_GlobalUtilityLib_ExitCriticalSection();
  }

  NvM_ErrorCheck_ReportDetErrorConditionally(NVM_SID_WRITEBLOCK, detError);

  return retVal;
}


/**********************************************************************************************************************
 * NvM_WritePRAMBlock
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, NVM_PUBLIC_CODE) NvM_WritePRAMBlock(
  NvM_BlockIdType BlockId)
{
  return NvM_WriteBlock(BlockId, NULL_PTR);
}


/**********************************************************************************************************************
 * NvM_RestoreBlockDefaults
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
 *
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, NVM_PUBLIC_CODE) NvM_RestoreBlockDefaults(                                                         /* PRQA S 6080 */ /* MD_MSR_STMIF */
  NvM_BlockIdType BlockId,
  P2VAR(void, AUTOMATIC, NVM_APPL_DATA) NvM_DstPtr)                                                                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
{
  Std_ReturnType retVal = E_NOT_OK;
  NvM_DetErrorIdType detError = NVM_E_NO_ERROR;

  NvM_BlockDescriptorLookupTableIdType blockDescriptorLookupTableId = 0u;
  const boolean isBlockValid =
    NvM_GlobalUtilityLib_FindBlockDescriptorLookupTableId(BlockId, &blockDescriptorLookupTableId);

  const NvM_PartitionIdType partitionId = NvM_GetPartitionIdViaBlockId(blockDescriptorLookupTableId);                   /* PRQA S 3205 */ /* MD_NvM_CslMacroNotUsingPartitionId */

  const boolean isDefaultDataConfigured = NvM_IsDefaultDataConfigured(blockDescriptorLookupTableId);

  if (NvM_ErrorCheck_IsDetConditionTrue(NvM_IsModuleInitialized == FALSE))
  {
    detError = NVM_E_UNINIT;
  }
  else if (NvM_ErrorCheck_IsDetConditionTrue(!isBlockValid))
  {
    detError = NVM_E_PARAM_BLOCK_ID;
  }
  else if (NvM_ErrorCheck_IsDetConditionTrue(
    NvM_IsBlockPending(BlockId, blockDescriptorLookupTableId, partitionId) == TRUE))
  {
    detError = NVM_E_BLOCK_PENDING;
  }
  else if (NvM_ErrorCheck_IsDetConditionTrue(NvM_CheckAddress(blockDescriptorLookupTableId, NvM_DstPtr) == FALSE))
  {
    detError = NVM_E_PARAM_ADDRESS;
  }
  else if (NvM_ErrorCheck_IsDetConditionTrue(isDefaultDataConfigured == FALSE))
  {
    detError = NVM_E_BLOCK_WITHOUT_DEFAULTS;
  }
  else if (NvM_ErrorCheck_IsDetConditionTrue(NvM_IsPartitionContextValid(blockDescriptorLookupTableId) == FALSE))       /* PRQA S 2996 */ /* MD_NvM_SinglePartitionDefault */ /* COV_NVM_SINGLEPARTITION_DEFAULT */
  {
    detError = NVM_E_PARAM_BLOCK_ID;
  }
  else if(isDefaultDataConfigured)
  {
    const NvM_Queue_JobType queueJob = {
      (NvM_DataPtrType)NvM_DstPtr,                                                                                      /* PRQA S 0316 */ /* MD_PointerTypeCast_VoidToDataPtr */
      BlockId,
      blockDescriptorLookupTableId,
      NVM_SINGLEBLOCKJOBTYPE_RESTORE_BLOCK_DEFAULTS
    };

    NvM_GlobalUtilityLib_EnterCriticalSection();
    {
      NvM_BlockManagementInformationPtrType blockManagementInfo =
        NvM_GlobalUtilityLib_GetBlockManagementInfo(BlockId, blockDescriptorLookupTableId, partitionId);

      NvM_Queue_InstancePtrType queueInstance = NvM_GetAddrQueue_Instance(partitionId);
      retVal = NvM_Queue_Push(queueInstance, &queueJob, NVM_SID_RESTOREBLOCKDEFAULTS);

      if (retVal == E_OK)
      {
        blockManagementInfo->ErrorStatus = NVM_REQ_PENDING;
        blockManagementInfo->RamBlockState = NVM_RAMBLOCKSTATE_INVALID_UNCHANGED;
      }

      /*
       * The parameter partitionId is not used within this function in single partition use case.
       * To avoid compiler warnings the following dummy statement is added.
       */
      NVM_DUMMY_STATEMENT_CONST(partitionId);                                                                                 /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
    }
    NvM_GlobalUtilityLib_ExitCriticalSection();
  }
  else
  {
    /*
     * MISRA case. Do nothing.
     * This default case is empty, because if no default data is configured
     * it is not possible to restore it. The last else if path is only necessary as per
     * AUTOSAR specification this check also needs to be done if DET is disabled.
     */
  }

  NvM_ErrorCheck_ReportDetErrorConditionally(NVM_SID_RESTOREBLOCKDEFAULTS, detError);

  return retVal;
}


/**********************************************************************************************************************
 * NvM_RestorePRAMBlockDefaults
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, NVM_PUBLIC_CODE) NvM_RestorePRAMBlockDefaults(
  NvM_BlockIdType BlockId)
{
  return NvM_RestoreBlockDefaults(BlockId, NULL_PTR);
}


/**********************************************************************************************************************
 * NvM_InvalidateNvBlock
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
FUNC(Std_ReturnType, NVM_PUBLIC_CODE) NvM_InvalidateNvBlock(                                                            /* PRQA S 6080 */ /* MD_MSR_STMIF */
  NvM_BlockIdType BlockId)
{
  Std_ReturnType retVal = E_NOT_OK;
  NvM_DetErrorIdType detError = NVM_E_NO_ERROR;

  NvM_BlockDescriptorLookupTableIdType blockDescriptorLookupTableId = 0u;
  const boolean isBlockValid =
    NvM_GlobalUtilityLib_FindBlockDescriptorLookupTableId(BlockId, &blockDescriptorLookupTableId);

  const NvM_PartitionIdType partitionId = NvM_GetPartitionIdViaBlockId(blockDescriptorLookupTableId);                   /* PRQA S 3205 */ /* MD_NvM_CslMacroNotUsingPartitionId */

  if (NvM_ErrorCheck_IsDetConditionTrue(NvM_IsModuleInitialized == FALSE))
  {
    detError = NVM_E_UNINIT;
  }
  else if (NvM_ErrorCheck_IsDetConditionTrue(!isBlockValid))
  {
    detError = NVM_E_PARAM_BLOCK_ID;
  }
  else if (NvM_ErrorCheck_IsDetConditionTrue(
    NvM_IsBlockPending(BlockId, blockDescriptorLookupTableId, partitionId) == TRUE))
  {
    detError = NVM_E_BLOCK_PENDING;
  }
  else if (NvM_ErrorCheck_IsDetConditionTrue(NvM_IsPartitionContextValid(blockDescriptorLookupTableId) == FALSE))       /* PRQA S 2996 */ /* MD_NvM_SinglePartitionDefault */ /* COV_NVM_SINGLEPARTITION_DEFAULT */
  {
    detError = NVM_E_PARAM_BLOCK_ID;
  }
  else
  {
    const NvM_Queue_JobType queueJob = {
      NULL_PTR,
      BlockId,
      blockDescriptorLookupTableId,
      NVM_SINGLEBLOCKJOBTYPE_INVALIDATE_NV_BLOCK
    };

    NvM_GlobalUtilityLib_EnterCriticalSection();
    {
      NvM_BlockManagementInformationPtrType blockManagementInfo =
        NvM_GlobalUtilityLib_GetBlockManagementInfo(BlockId, blockDescriptorLookupTableId, partitionId);

      if (blockManagementInfo->WriteProtection == TRUE)
      {
#if (NVM_DEV_ERROR_DETECT == STD_ON)
        detError = NVM_E_WRITE_PROTECTED;
#endif /* NVM_DEV_ERROR_DETECT == STD_ON */
      }
      else if (NvM_CheckBlockLockedStatus(blockManagementInfo, partitionId) == FALSE)
      {
        NvM_Queue_InstancePtrType queueInstance = NvM_GetAddrQueue_Instance(partitionId);
        retVal = NvM_Queue_Push(queueInstance, &queueJob, NVM_SID_INVALIDATENVBLOCK);

        if (retVal == E_OK)
        {
          blockManagementInfo->ErrorStatus = NVM_REQ_PENDING;
        }
      }
      else
      {
        /*
         * MISRA case. Do nothing.
         * This default case is empty due to the fact that the executed checks
         * are sufficient in this case.
         */
      }

      /*
      * The parameter partitionId is not used within this function in single partition use case.
      * To avoid compiler warnings the following dummy statement is added.
      */
      NVM_DUMMY_STATEMENT_CONST(partitionId);                                                                           /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
    }
    NvM_GlobalUtilityLib_ExitCriticalSection();
  }

  NvM_ErrorCheck_ReportDetErrorConditionally(NVM_SID_INVALIDATENVBLOCK, detError);

  return retVal;
}


/**********************************************************************************************************************
 * NvM_EraseNvBlock
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
 *
 */
FUNC(Std_ReturnType, NVM_PUBLIC_CODE) NvM_EraseNvBlock(NvM_BlockIdType BlockId)                                         /* PRQA S 6080 */ /* MD_MSR_STMIF */
{
  Std_ReturnType retVal = E_NOT_OK;
  NvM_DetErrorIdType detError = NVM_E_NO_ERROR;

  NvM_BlockDescriptorLookupTableIdType blockDescriptorLookupTableId = 0u;
  const boolean isBlockValid =
    NvM_GlobalUtilityLib_FindBlockDescriptorLookupTableId(BlockId, &blockDescriptorLookupTableId);

  const NvM_PartitionIdType partitionId = NvM_GetPartitionIdViaBlockId(blockDescriptorLookupTableId);                   /* PRQA S 3205 */ /* MD_NvM_CslMacroNotUsingPartitionId */

  if (NvM_ErrorCheck_IsDetConditionTrue(NvM_IsModuleInitialized == FALSE))
  {
    detError = NVM_E_UNINIT;
  }
  else if (NvM_ErrorCheck_IsDetConditionTrue(!isBlockValid))
  {
    detError = NVM_E_PARAM_BLOCK_ID;
  }
  else if (NvM_ErrorCheck_IsDetConditionTrue(NvM_IsBlockWithImmediatePriority(blockDescriptorLookupTableId) == FALSE))
  {
    detError = NVM_E_BLOCK_CONFIG;
  }
  else if (NvM_ErrorCheck_IsDetConditionTrue(
    NvM_IsBlockPending(BlockId, blockDescriptorLookupTableId, partitionId) == TRUE))
  {
    detError = NVM_E_BLOCK_PENDING;
  }
  else if (NvM_ErrorCheck_IsDetConditionTrue(NvM_IsPartitionContextValid(blockDescriptorLookupTableId) == FALSE))       /* PRQA S 2996 */ /* MD_NvM_SinglePartitionDefault */ /* COV_NVM_SINGLEPARTITION_DEFAULT */
  {
    detError = NVM_E_PARAM_BLOCK_ID;
  }
  else
  {
    const NvM_Queue_JobType queueJob = {
      NULL_PTR,
      BlockId,
      blockDescriptorLookupTableId,
      NVM_SINGLEBLOCKJOBTYPE_ERASE_NV_BLOCK
    };

    NvM_GlobalUtilityLib_EnterCriticalSection();
    {
      NvM_BlockManagementInformationPtrType blockManagementInfo =
        NvM_GlobalUtilityLib_GetBlockManagementInfo(BlockId, blockDescriptorLookupTableId, partitionId);

      if (blockManagementInfo->WriteProtection == TRUE)
      {
#if (NVM_DEV_ERROR_DETECT == STD_ON)
        detError = NVM_E_WRITE_PROTECTED;
#endif /* NVM_DEV_ERROR_DETECT == STD_ON */
      }
      else if (NvM_CheckBlockLockedStatus(blockManagementInfo, partitionId) == FALSE)
      {
        NvM_Queue_InstancePtrType queueInstance = NvM_GetAddrQueue_Instance(partitionId);
        retVal = NvM_Queue_Push(queueInstance, &queueJob, NVM_SID_ERASENVBLOCK);

        if (retVal == E_OK)
        {
          blockManagementInfo->ErrorStatus = NVM_REQ_PENDING;
        }
      }
      else
      {
        /*
         * MISRA case. Do nothing.
         * This default case is empty due to the fact that the executed checks
         * are sufficient in this case.
         */
      }

      /*
      * The parameter partitionId is not used within this function in single partition use case.
      * To avoid compiler warnings the following dummy statement is added.
      */
      NVM_DUMMY_STATEMENT_CONST(partitionId);                                                                           /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
    }
    NvM_GlobalUtilityLib_ExitCriticalSection();
  }

  NvM_ErrorCheck_ReportDetErrorConditionally(NVM_SID_ERASENVBLOCK, detError);

  return retVal;
}


/**********************************************************************************************************************
 * NvM_ReadAll
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
 *
 */
FUNC(void, NVM_PUBLIC_CODE) NvM_ReadAll(void)
{
  NvM_DetErrorIdType detError = NVM_E_NO_ERROR;

  if (NvM_ErrorCheck_IsDetConditionTrue(NvM_IsModuleInitialized == FALSE))
  {
    detError = NVM_E_UNINIT;
  }
  else
  {
    NvM_GlobalUtilityLib_EnterCriticalSection();
    {
      NvM_MultiBlockJobInformationPtrType multiBlockJobInfo =
        NvM_GetAddrMultiBlockJobInformation(NVM_PARTITION_ID_MASTER);

      if (NvM_GlobalUtilityLib_IsAnyMultiBlockJobRequested(multiBlockJobInfo->JobStatusFlag) == FALSE)
      {
        multiBlockJobInfo->JobStatusFlag = NvM_GlobalUtilityLib_SetFlag(multiBlockJobInfo->JobStatusFlag,
                                                          NVM_MULTIBLOCK_FLAG_READALL_REQUESTED);

        multiBlockJobInfo->ErrorStatus = NVM_REQ_PENDING;

        NvM_Notification_ProcessMultiBlockNotification(NVM_MULTIBLOCKJOBTYPE_READ_ALL, multiBlockJobInfo->ErrorStatus);
      }
    }
    NvM_GlobalUtilityLib_ExitCriticalSection();
  }

  NvM_ErrorCheck_ReportDetErrorConditionally(NVM_SID_READALL, detError);
}


/**********************************************************************************************************************
 * NvM_WriteAll
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
 *
 */
FUNC(void, NVM_PUBLIC_CODE) NvM_WriteAll(void)
{
  NvM_DetErrorIdType detError = NVM_E_NO_ERROR;

  if (NvM_ErrorCheck_IsDetConditionTrue(NvM_IsModuleInitialized == FALSE))
  {
    detError = NVM_E_UNINIT;
  }
  else
  {
    NvM_GlobalUtilityLib_EnterCriticalSection();
    {
      NvM_MultiBlockJobInformationPtrType multiBlockJobInfo =
        NvM_GetAddrMultiBlockJobInformation(NVM_PARTITION_ID_MASTER);

      if (NvM_GlobalUtilityLib_IsAnyMultiBlockJobRequested(multiBlockJobInfo->JobStatusFlag) == FALSE)
      {
        multiBlockJobInfo->JobStatusFlag = NvM_GlobalUtilityLib_SetFlag(multiBlockJobInfo->JobStatusFlag,
                                                          NVM_MULTIBLOCK_FLAG_WRITEALL_REQUESTED);

        multiBlockJobInfo->ErrorStatus = NVM_REQ_PENDING;

        NvM_Notification_ProcessMultiBlockNotification(NVM_MULTIBLOCKJOBTYPE_WRITE_ALL, multiBlockJobInfo->ErrorStatus);
      }
    }
    NvM_GlobalUtilityLib_ExitCriticalSection();
  }

  NvM_ErrorCheck_ReportDetErrorConditionally(NVM_SID_WRITEALL, detError);
}


/**********************************************************************************************************************
 * NvM_CancelWriteAll
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
 *
 *
 *
 */
FUNC(void, NVM_PUBLIC_CODE) NvM_CancelWriteAll(void)
{
  NvM_DetErrorIdType detError = NVM_E_NO_ERROR;

  if (NvM_ErrorCheck_IsDetConditionTrue(NvM_IsModuleInitialized == FALSE))
  {
    detError = NVM_E_UNINIT;
  }
  else
  {
    NvM_GlobalUtilityLib_EnterCriticalSection();
    {
      NvM_MultiBlockJobInformationPtrType multiBlockJobInfo =
        NvM_GetAddrMultiBlockJobInformation(NVM_PARTITION_ID_MASTER);

      /* The sequence of checking the active flag first must be followed
      because the requested and active flag can be set simultaneously */
      if (NvM_GlobalUtilityLib_IsFlagSet(multiBlockJobInfo->JobStatusFlag, NVM_MULTIBLOCK_FLAG_WRITEALL_ACTIVE))
      {
        multiBlockJobInfo->JobStatusFlag = NvM_GlobalUtilityLib_SetFlag(multiBlockJobInfo->JobStatusFlag,
          NVM_MULTIBLOCK_FLAG_WRITEALL_CANCEL_REQUESTED);
      }
      else if (NvM_GlobalUtilityLib_IsFlagSet(multiBlockJobInfo->JobStatusFlag, NVM_MULTIBLOCK_FLAG_WRITEALL_REQUESTED))
      {
        multiBlockJobInfo->ErrorStatus = NVM_REQ_CANCELED;

        NvM_Notification_ProcessMultiBlockNotification(
          NVM_MULTIBLOCKJOBTYPE_CANCEL_WRITE_ALL,
          multiBlockJobInfo->ErrorStatus);

        /* Clear all multiblock job flags. Only possible since
        no more than one multiblock job can be requested at a time */
        multiBlockJobInfo->JobStatusFlag = 0u;
      }
      else
      {
        /*
         * MISRA case. Do nothing.
         * This default case is empty due to the fact that only the queried flags
         * are relevant for the determination of the cancel request.
         */
      }
    }
    NvM_GlobalUtilityLib_ExitCriticalSection();
  }

  NvM_ErrorCheck_ReportDetErrorConditionally(NVM_SID_CANCELWRITEALL, detError);
}


/**********************************************************************************************************************
 * NvM_KillWriteAll
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
 *
 */
FUNC(void, NVM_PUBLIC_CODE) NvM_KillWriteAll(void)
{
  NvM_DetErrorIdType detError = NVM_E_NO_ERROR;

  if (NvM_ErrorCheck_IsDetConditionTrue(NvM_IsModuleInitialized == FALSE))
  {
    detError = NVM_E_UNINIT;
  }
  else
  {
    NvM_GlobalUtilityLib_EnterCriticalSection();
    {
      NvM_MultiBlockJobInformationPtrType multiBlockJobInfo =
        NvM_GetAddrMultiBlockJobInformation(NVM_PARTITION_ID_MASTER);

      /* The sequence of checking the active flag first must be followed
      because the requested and active flag can be set simultaneously */
      if (NvM_GlobalUtilityLib_IsFlagSet(multiBlockJobInfo->JobStatusFlag, NVM_MULTIBLOCK_FLAG_WRITEALL_ACTIVE))
      {
        NvM_BlockDescriptorLookupTableIdType lastProcessedBlockId =
          NvM_WriteAllFsm_GetCurrentProcessedBlockDescriptorLookupTableId(NVM_PARTITION_ID_MASTER);

        /* Check if valid block ID is retrieved */
        if (lastProcessedBlockId < NvM_GetSizeOfBlockDescriptor())
        {
          NvM_CancelMemIfConditionally(lastProcessedBlockId);
        }
        else
        {
          lastProcessedBlockId = NvM_GetSizeOfBlockDescriptor() - 1u;
        }

        for (NvM_BlockDescriptorLookupTableIdType i = NVM_FIRST_INTERNAL_BLOCK_ID; i <= lastProcessedBlockId; i++)      /* FETA_NVM_KillWriteAll_CancelUnprocessedBlocks */
        {
          NvM_BlockDescriptorPtrType blockDescriptor = NvM_GetAddrBlockDescriptor(i);
          blockDescriptor->BlockManagementInfo->ErrorStatus = NVM_REQ_CANCELED;
        }

        NvM_FinishMultiBlockJobTermination(multiBlockJobInfo, NVM_MULTIBLOCKJOBTYPE_WRITE_ALL);

        NvM_ResetAllSinglePartitionProcessingStacks(NVM_PARTITION_ID_MASTER);
      }
      else if (NvM_GlobalUtilityLib_IsFlagSet(multiBlockJobInfo->JobStatusFlag, NVM_MULTIBLOCK_FLAG_WRITEALL_REQUESTED))
      {
        NvM_FinishMultiBlockJobTermination(multiBlockJobInfo, NVM_MULTIBLOCKJOBTYPE_WRITE_ALL);
      }
      else
      {
        /*
         * MISRA case. Do nothing.
         * This default case is empty due to the fact that only the queried flags
         * are relevant for the determination of the kill request.
         */
      }
    }
    NvM_GlobalUtilityLib_ExitCriticalSection();
  }

  NvM_ErrorCheck_ReportDetErrorConditionally(NVM_SID_KILLWRITEALL, detError);
}


/**********************************************************************************************************************
 * NvM_KillReadAll
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
FUNC(void, NVM_PUBLIC_CODE) NvM_KillReadAll(void)
{
  NvM_DetErrorIdType detError = NVM_E_NO_ERROR;

  if (NvM_ErrorCheck_IsDetConditionTrue(NvM_IsModuleInitialized == FALSE))
  {
    detError = NVM_E_UNINIT;
  }
  else
  {
    NvM_GlobalUtilityLib_EnterCriticalSection();
    {
      NvM_MultiBlockJobInformationPtrType multiBlockJobInfo =
        NvM_GetAddrMultiBlockJobInformation(NVM_PARTITION_ID_MASTER);

      /* The sequence of checking the active flag first must be followed
      because the requested and active flag can be set simultaneously */
      if (NvM_GlobalUtilityLib_IsFlagSet(multiBlockJobInfo->JobStatusFlag, NVM_MULTIBLOCK_FLAG_READALL_ACTIVE))
      {
        NvM_BlockDescriptorLookupTableIdType lastProcessedBlockId =
          NvM_ReadAllFsm_GetCurrentProcessedBlockDescriptorLookupTableId(NVM_PARTITION_ID_MASTER);
        const uint16 blockCount = NvM_GetSizeOfBlockDescriptor();

        if (lastProcessedBlockId < blockCount)
        {
          NvM_CancelMemIfConditionally(lastProcessedBlockId);

          for (NvM_BlockDescriptorLookupTableIdType i = lastProcessedBlockId; i < blockCount; i++)                      /* FETA_NVM_CSL_SizeOfIterableGenDataObject */
          {
            NvM_BlockDescriptorPtrType blockDescriptor = NvM_GetAddrBlockDescriptor(i);
            blockDescriptor->BlockManagementInfo->ErrorStatus = NVM_REQ_BLOCK_SKIPPED;
          }

          NvM_FinishMultiBlockJobTermination(multiBlockJobInfo, NVM_MULTIBLOCKJOBTYPE_READ_ALL);

          NvM_ResetAllSinglePartitionProcessingStacks(NVM_PARTITION_ID_MASTER);
        }
      }
      else if (NvM_GlobalUtilityLib_IsFlagSet(multiBlockJobInfo->JobStatusFlag, NVM_MULTIBLOCK_FLAG_READALL_REQUESTED))
      {
        NvM_FinishMultiBlockJobTermination(multiBlockJobInfo, NVM_MULTIBLOCKJOBTYPE_READ_ALL);
      }
      else
      {
        /*
         * MISRA case. Do nothing.
         * This default case is empty due to the fact that only the queried flags
         * are relevant for the determination of the kill request.
         */
      }
    }
    NvM_GlobalUtilityLib_ExitCriticalSection();
  }

  NvM_ErrorCheck_ReportDetErrorConditionally(NVM_SID_KILLREADALL, detError);
}

/**********************************************************************************************************************
 * NvM_ValidateAll
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
 *
 *
 */
FUNC(void, NVM_PUBLIC_CODE) NvM_ValidateAll(void)
{
  NvM_DetErrorIdType detError = NVM_E_NO_ERROR;

  if (NvM_ErrorCheck_IsDetConditionTrue(NvM_IsModuleInitialized == FALSE))
  {
    detError = NVM_E_UNINIT;
  }
  else
  {
    NvM_GlobalUtilityLib_EnterCriticalSection();
    {
      NvM_MultiBlockJobInformationPtrType multiBlockJobInfo =
        NvM_GetAddrMultiBlockJobInformation(NVM_PARTITION_ID_MASTER);

      if (NvM_GlobalUtilityLib_IsAnyMultiBlockJobRequested(multiBlockJobInfo->JobStatusFlag) == FALSE)
      {
        multiBlockJobInfo->JobStatusFlag = NvM_GlobalUtilityLib_SetFlag(multiBlockJobInfo->JobStatusFlag,
                                                          NVM_MULTIBLOCK_FLAG_VALIDATEALL_REQUESTED);

        multiBlockJobInfo->ErrorStatus = NVM_REQ_PENDING;

        NvM_Notification_ProcessMultiBlockNotification(NVM_MULTIBLOCKJOBTYPE_VALIDATE_ALL, multiBlockJobInfo->ErrorStatus);
      }
    }
    NvM_GlobalUtilityLib_ExitCriticalSection();
  }

  NvM_ErrorCheck_ReportDetErrorConditionally(NVM_SID_VALIDATEALL, detError);
}

#if (NVM_MULTIPARTITION_USAGE_SCENARIO == STD_ON)

/**********************************************************************************************************************
 *  NvM_GetActiveMultiBlockPartitionId
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
  * \spec
  *    requires ApplicationId != 0;
  * \endspec
  */
FUNC(Std_ReturnType, NVM_PUBLIC_CODE) NvM_GetActiveMultiBlockApplicationId(ApplicationType* ApplicationId)
{
    Std_ReturnType status = E_NOT_OK;
    NvM_DetErrorIdType detError = NVM_E_NO_ERROR;

    if (NvM_ErrorCheck_IsDetConditionTrue(ApplicationId == NULL_PTR))
    {
      detError = NVM_E_PARAM_POINTER;
    }
    else if (NvM_ErrorCheck_IsDetConditionTrue(NvM_IsModuleInitialized == FALSE))
    {
      detError = NVM_E_UNINIT;
    }
    else
    {
      NvM_GlobalUtilityLib_EnterCriticalSection();
      NvM_MultiBlockJobInformationType multiBlockJobInfo = NvM_GetMultiBlockJobInformation(NVM_PARTITION_ID_MASTER);
      NvM_GlobalUtilityLib_ExitCriticalSection();

      if ((NvM_GlobalUtilityLib_IsFlagSet(multiBlockJobInfo.JobStatusFlag, NVM_MULTIBLOCK_FLAG_VALIDATEALL_REQUESTED) == FALSE)
          && (multiBlockJobInfo.ErrorStatus == NVM_REQ_PENDING))
      {
        const NvM_PartitionIdType partition = NvM_MultiBlockProcessorFsm_GetActivePartitionId();

        status = NvM_GlobalUtilityLib_FindOsApplicationId(ApplicationId, partition);
      }
    }

    NvM_ErrorCheck_ReportDetErrorConditionally(NVM_SID_GETACTIVEMULTIBLOCKAPPLICATIONID, detError);

    return status;
}

#endif /* NVM_MULTIPARTITION_USAGE_SCENARIO */

# define NVM_STOP_SEC_CODE
# include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  MISRA JUSTIFICATIONS
 **********************************************************************************************************************/

/* Justification for module-specific MISRA deviations:

MD_NvMFsmLib_StackIndexSignedInteger: rule 10.4
  Reason:     CurrentProcessingStackIndex is a signed integer and gets compared to unsigned integer.
              Using this signed technique helps to ease the handling of the processing stack.
  Risk:       Comparison could possibly be done with an unexpectedly high integer because of the sint to uint cast and
              therefore lead to unexpected code flow.
  Prevention: A code review shall ensure that there is no side effect of the invoked function.

MD_Fsm_StateDefinitionStaticUsedOnlyInSingleFunction: rule 8.9
  Reason:     State definition must be globally defined for a FSM as it's pointer is forwarded to the
              FSM lib handling. It must be valid over multiple main function cycles, potentially.
  Risk:       None.
  Prevention: A code review shall ensure that there is no side effect.

MD_PointerTypeCast_VoidToDataPtr: rule 11.5
  Reason:     Lower layers of NvM require a data buffer type based in uint8.
              To normalize the handling internally, the data pointer gets castet without further interpretation.
  Risk:       None.
  Prevention: A code review shall ensure that there is no side effect.

MD_PointerTypeCast_LossOfQualification: rule 11.8
  Reason:     AUTOSAR API definition requires a const pointer to be presented.
              To unify handling for reading and writing directions the same target pointer is used and the const
              qualification is stripped away.
              This makes reading and maintaining the internal code easier.
  Risk:       None.
  Prevention: A code review shall ensure that there is no side effect.

MD_NvM_QACReportsFalsePositive2983:
  Reason:     This is no violation against MISRA but a false positive from the QAC tooling.
              The ticket CSENT-1759 was created to track the process.
  Risk:       None.
  Prevention: A code review shall ensure that there is no side effect.

MD_NvM_CslMacroNotUsingPartitionId:
  Reason:     The CSL is not using this parameter for the single partition use-case.
              To keep the API intact it requires this parameter to be added, which then raises this MISRA warning.
  Risk:       None.
  Prevention: A code review shall ensure that there is no side effect.

MD_NvM_SinglePartitionDefault
  Reason:     The partition context is always valid in single partition usage scenario. Therefore the DET Error check is
              always false.
  Risk:       None.
  Prevention: A code review shall ensure that there is no side effect.

*/
/* COV_JUSTIFICATION_BEGIN

Code coverage:

  \ID COV_NVM_MISRA_BRANCH
    \ACCEPT TX
    \ACCEPT XX
    \REASON COV_MSR_MISRA

  \ID COV_NVM_SINGLEPARTITION_DEFAULT
    \ACCEPT XF
    \REASON The decision is always true due to single partition usage scenario.

Variant coverage:

  \ID COV_NVM_COMPATIBILITY
   \ACCEPT TX
   \REASON COV_MSR_COMPATIBILITY

  \ID COV_NVM_VCA
   \ACCEPT TX
   \ACCEPT XF
   \REASON VCA needs some code parts enabled or disabled to analyze the module in a meaningful way.

  \ID COV_NVM_USEBLOCKIDCHECK
   \ACCEPT TX
   \REASON UseBlockIdCheck needs to be enabled for a configuration to be safe.

COV_JUSTIFICATION_END */

/***********************************************************************************************************************
 *  VCA JUSTIFICATIONS
 **********************************************************************************************************************/
/* VCA_JUSTIFICATION_BEGIN

\ID VCA_NVM_DataIntegrityRecordBuffer
  \DESCRIPTION The data integrity record buffer can be assigned to the internal buffer
               or to an external buffer which is defined by the integrator.
               It must be ensured that the buffer has at least the size 2 for CRC16 and 4 for CRC32.
               In order to analyze the NvM in a meaningful way, some parts of the code are deactivated
               during the VCA analysis, as it would lead to false-positive errors in other parts of the module.

  \COUNTERMEASURE \M A MSSV check is implemented to verfiy that the internal buffer is large enough
                     to hold the maximum configured payload and the largest configured data integrity setting.
                  \S If an external buffer is used, the integrator must ensure
                     that the specified buffer is large enough. See SMI-NvM-PassedBuffer.

\ID VCA_NVM_VStdLibMemCpyCalls
  \DESCRIPTION The external function VStdLib_MemCpy is used to copy data from the internally used buffer
               to the buffer provided (RamBlockDataAddress, Temporary Ram Block or Explicit Sync Mechnism)
               by the user or vice versa.
               Also internal copying of data from satellite to master buffer or vice versa is done.
               It has to be ensured that the destination buffer is large enough to hold the provided data.


  \COUNTERMEASURE \M A MSSV check is implemented to verfiy that the internal buffer is large enough
                     to hold the maximum configured payload and the largest configured data integrity setting.
                  \S If an external buffer is used, the integrator must ensure
                     that the specified buffer is large enough. See SMI-NvM-PassedBuffer.

VCA_JUSTIFICATION_END */

/***********************************************************************************************************************
 *  FETA JUSTIFICATIONS
 **********************************************************************************************************************/
/* FETA_JUSTIFICATION_BEGIN

\ID FETA_NVM_ConstantProcessingStackSize_Callee
\DESCRIPTION Loop does [processingStackSize] iterations to initialize processing stack entries.
\COUNTERMEASURE \N Caller ensures correctness of [processingStackSize].

\ID FETA_NVM_ConstantProcessingStackSize_Caller
\DESCRIPTION Initializes the processing stack with generated constant size parameters.
\COUNTERMEASURE \N Used parameter values are generated ROM values.
                   The loop will always terminate in finite time.

\ID FETA_NVM_CSL_SizeOfIterableGenDataObject
\DESCRIPTION Loop over static number of elements.
\COUNTERMEASURE \N The loop has a static upper limit determined by a ROM value retrieved via CSL's SizeOf macro [CSL01].
                   The loop will always terminate in finite time.

\ID FETA_NVM_StaticQueueUpperBoundQueueSize
\DESCRIPTION Loop over static number of queue elements.
\COUNTERMEASURE \R The loop has a static upper limit given by the queue size, which is either given
                   by the generated macro NVM_SIZE_STANDARD_JOB_QUEUE or NVM_SIZE_IMMEDIATE_JOB_QUEUE.
                   The loop will always terminate in finite time.

\ID FETA_NVM_ConstantQueueListSize_Callee
\DESCRIPTION Loop does [queueListSize] iterations to initialize queue list entries.
\COUNTERMEASURE \N Caller ensures correctness of [queueListSize].

\ID FETA_NVM_ConstantQueueListSize_Caller
\DESCRIPTION Initializes the queue list with generated constant size parameter.
\COUNTERMEASURE \N Used parameter value is a generated ROM value.
                   The loop will always terminate in finite time.

\ID FETA_NVM_KillWriteAll_CancelUnprocessedBlocks
\DESCRIPTION Loop over limited number of elements.
\COUNTERMEASURE \R The loop has at maximum [NvM_GetSizeOfBlockDescriptor()] iterations. Which is a static upper limit
                   determined by a ROM value retrieved via CSL's SizeOf macro [CSL01]. In the loops termination criteria
                   [lastProcessedBlockId] is used as an upper boundary, which is checked to be smaller than
                   [NvM_GetSizeOfBlockDescriptor()]. Otherwise it is set to the last element by
                   NvM_GetSizeOfBlockDescriptor() - 1u. This can't lead to an underflow because a valid configuration
                   always has at least two block descriptors.
                   The loop will always terminate in finite time.

\ID FETA_NVM_FsmLib_StackClearing
\DESCRIPTION NvM FsmLib iterates over all currently active stack elements and clears them.
\COUNTERMEASURE \R The loop has at maximum [instance->StackSize] iterations. [NvM_FsmLib_SpawnFsm()] is the only place
                   that increments [instance->CurrentProcessingStackIndex] while doing a boundary check.
                   [instance->CurrentProcessingStackIndex] is only decremented inside of the loop which converges to the
                   lower limit of [NVM_FSMLIB_PROCESSING_STACK_INDEX_NONE] which is a generated ROM value.
                   The loop will always terminate in finite time.

\ID FETA_NVM_FsmLib_StackProcessing
\DESCRIPTION NvM_FsmLibs internal stack processing.
\COUNTERMEASURE \R The loops termination is ensured via a runtime check using a local processing counter variable whose
                   upper limit is set to a generated ROM value.
                   The loop will always terminate in finite time.

\ID FETA_NVM_WriteAllFsm_CancelUnprocessedBlocks
\DESCRIPTION Loop over limited number of elements.
\COUNTERMEASURE \R The CurrentBlockDescriptorLookupTableId is always in range of [NVM_FIRST_INTERNAL_BLOCK_ID] and
                   [NvM_GetSizeOfBlockDescriptor()]. This is ensured by how the state machine processes the blocks.
                   The loop will always terminate in finite time.

FETA_JUSTIFICATION_END */

/**********************************************************************************************************************
 *  END OF FILE: NvM.c
 *********************************************************************************************************************/
