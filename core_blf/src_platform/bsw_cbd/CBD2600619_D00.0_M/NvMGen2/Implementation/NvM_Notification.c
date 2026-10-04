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
/*!        \file  NvM_Notification.c
 *        \brief  NvM_Notification source file
 *      \details  Implementation of the notification unit of the NvM.
 *         \unit  NvM_Notification
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#define NVM_NOTIFICATION_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "NvM_Notification.h"
#include "NvM_GlobalUtilityLib.h"
#include "NvM_PrivateCfg.h"
#include "NvM_CfgDefines.h"

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

 #ifdef NvM_InvokeMultiBlockCallback
 #define NVM_MULTIBLOCK_NOTIFICATION_ENABLED STD_ON
 #elif defined(NvM_InvokeCurrentJobMode)
 #define NVM_MULTIBLOCK_NOTIFICATION_ENABLED STD_ON
 #else
 #define NVM_MULTIBLOCK_NOTIFICATION_ENABLED STD_OFF
 #endif

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

#if (NVM_USE_ASR440_CALLBACK_INTERFACE == STD_ON)

/**********************************************************************************************************************
 * NvM_Notification_ConvertSingleBlockJobTypeToBlockRequest()
 *********************************************************************************************************************/
/*! \brief       Convert single block job type to block request.
 *  \details     -
 *  \param[in]   jobType Job type to be converted.
 *  \return      Block Request.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
NVM_LOCAL_INLINE FUNC(NvM_BlockRequestType, NVM_PRIVATE_CODE) NvM_Notification_ConvertSingleBlockJobTypeToBlockRequest(
  const NvM_SingleBlockJobType jobType);

#  if (NVM_MULTIBLOCK_NOTIFICATION_ENABLED == STD_ON)
/**********************************************************************************************************************
 *  NvM_Notification_ConvertMultiBlockJobTypeToMultiBlockRequest
 *********************************************************************************************************************/
/*! \brief       Convert multiblock job type to multiblock request.
 *  \details     -
 *  \param[in]   jobType MultiBlock Job Type.
 *  \return      MultiBlock Request.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
NVM_LOCAL_INLINE FUNC(NvM_MultiBlockRequestType, NVM_PRIVATE_CODE)
  NvM_Notification_ConvertMultiBlockJobTypeToMultiBlockRequest(
    const NvM_MultiBlockJobType jobType);
#  endif /* NvM_InvokeMultiBlockCallback */

#else /* NVM_USE_ASR440_CALLBACK_INTERFACE == STD_OFF */

/**********************************************************************************************************************
 * NvM_Notification_ConvertSingleBlockJobTypeToServiceId()
 *********************************************************************************************************************/
/*! \brief       Convert single block job type to service id.
 *  \details     -
 *  \param[in]   jobType Job type to be converted.
 *  \return      Service ID.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
NVM_LOCAL_INLINE FUNC(NvM_ServiceIdType, NVM_PRIVATE_CODE) NvM_Notification_ConvertSingleBlockJobTypeToServiceId(
  const NvM_SingleBlockJobType jobType);

#if (NVM_MULTIBLOCK_NOTIFICATION_ENABLED == STD_ON)
/**********************************************************************************************************************
 *  NvM_Notification_ConvertMultiBlockJobTypeToServiceId
 *********************************************************************************************************************/
/*! \brief       Convert multiblock job type to service id.
 *  \details     -
 *  \param[in]   jobType MultiBlock Job Type.
 *  \return      Service ID.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
NVM_LOCAL_INLINE FUNC(NvM_ServiceIdType, NVM_PRIVATE_CODE) NvM_Notification_ConvertMultiBlockJobTypeToServiceId(
  const NvM_MultiBlockJobType jobType);
#endif /* NvM_InvokeMultiBlockCallback */

#endif /* NVM_USE_ASR440_CALLBACK_INTERFACE */

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

#if (NVM_USE_ASR440_CALLBACK_INTERFACE)

/**********************************************************************************************************************
* NvM_Notification_ConvertSingleBlockJobTypeToBlockRequest
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
NVM_LOCAL_INLINE FUNC(NvM_BlockRequestType, NVM_PRIVATE_CODE) NvM_Notification_ConvertSingleBlockJobTypeToBlockRequest(
  const NvM_SingleBlockJobType jobType)
{
  NvM_BlockRequestType blockRequest = NVM_WRITE_BLOCK;

  switch(jobType)
  {
    case NVM_SINGLEBLOCKJOBTYPE_READ_BLOCK:
      blockRequest = NVM_READ_BLOCK;
      break;
    case NVM_SINGLEBLOCKJOBTYPE_READ_ALL_BLOCK:
      blockRequest = NVM_READ_ALL_BLOCK;
      break;
    case NVM_SINGLEBLOCKJOBTYPE_INVALIDATE_NV_BLOCK:
      blockRequest = NVM_INVALIDATE_NV_BLOCK;
      break;
    case NVM_SINGLEBLOCKJOBTYPE_ERASE_NV_BLOCK:
      blockRequest = NVM_ERASE_NV_BLOCK;
      break;

    default:
      blockRequest = NVM_WRITE_BLOCK;
      break;
  }

  return blockRequest;
}

#  if (NVM_MULTIBLOCK_NOTIFICATION_ENABLED == STD_ON)

/**********************************************************************************************************************
*  NvM_Notification_ConvertMultiBlockJobTypeToMultiBlockRequest
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
NVM_LOCAL_INLINE FUNC(NvM_MultiBlockRequestType, NVM_PRIVATE_CODE) NvM_Notification_ConvertMultiBlockJobTypeToMultiBlockRequest(
  const NvM_MultiBlockJobType jobType)
{
  NvM_MultiBlockRequestType multiBlockRequest = NVM_WRITE_ALL;

  switch(jobType)
  {
    case NVM_MULTIBLOCKJOBTYPE_READ_ALL:
      multiBlockRequest = NVM_READ_ALL;
      break;
    case NVM_MULTIBLOCKJOBTYPE_VALIDATE_ALL:
      multiBlockRequest = NVM_VALIDATE_ALL;
      break;
    case NVM_MULTIBLOCKJOBTYPE_CANCEL_WRITE_ALL:
      multiBlockRequest = NVM_CANCEL_WRITE_ALL;
      break;
    case NVM_MULTIBLOCKJOBTYPE_KILL_WRITE_ALL:
      multiBlockRequest = NVM_KILL_WRITE_ALL;
      break;
    case NVM_MULTIBLOCKJOBTYPE_KILL_READ_ALL:
      multiBlockRequest = NVM_KILL_READ_ALL;
      break;

    default:
      multiBlockRequest = NVM_WRITE_ALL;
      break;
  }

  return multiBlockRequest;
}

#  endif /* NvM_InvokeMultiBlockCallback */

#else /* NVM_USE_ASR440_CALLBACK_INTERFACE == STD_OFF */

/**********************************************************************************************************************
* NvM_Notification_ConvertSingleBlockJobTypeToServiceId
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
NVM_LOCAL_INLINE FUNC(NvM_ServiceIdType, NVM_PRIVATE_CODE) NvM_Notification_ConvertSingleBlockJobTypeToServiceId(
  const NvM_SingleBlockJobType jobType)
{
  NvM_ServiceIdType serviceId = NVM_SID_WRITEBLOCK;

  switch(jobType)
  {
    case NVM_SINGLEBLOCKJOBTYPE_READ_BLOCK:
      serviceId = NVM_SID_READBLOCK;
      break;
    case NVM_SINGLEBLOCKJOBTYPE_READ_ALL_BLOCK:
      serviceId = NVM_SID_READALL;
      break;
    case NVM_SINGLEBLOCKJOBTYPE_INVALIDATE_NV_BLOCK:
      serviceId = NVM_SID_INVALIDATENVBLOCK;
      break;
    case NVM_SINGLEBLOCKJOBTYPE_ERASE_NV_BLOCK:
      serviceId = NVM_SID_ERASENVBLOCK;
      break;

    default:
      serviceId = NVM_SID_WRITEBLOCK;
      break;
  }

  return serviceId;
}

#  if (NVM_MULTIBLOCK_NOTIFICATION_ENABLED == STD_ON)

/**********************************************************************************************************************
*  NvM_Notification_ConvertMultiBlockJobTypeToServiceId
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
NVM_LOCAL_INLINE FUNC(NvM_ServiceIdType, NVM_PRIVATE_CODE) NvM_Notification_ConvertMultiBlockJobTypeToServiceId(
  const NvM_MultiBlockJobType jobType)
{
  NvM_ServiceIdType serviceId = NVM_SID_WRITEALL;

  switch(jobType)
  {
    case NVM_MULTIBLOCKJOBTYPE_READ_ALL:
      serviceId = NVM_SID_READALL;
      break;
    case NVM_MULTIBLOCKJOBTYPE_VALIDATE_ALL:
      serviceId = NVM_SID_VALIDATEALL;
      break;
    case NVM_MULTIBLOCKJOBTYPE_CANCEL_WRITE_ALL:
      serviceId = NVM_SID_CANCELWRITEALL;
      break;
    case NVM_MULTIBLOCKJOBTYPE_KILL_WRITE_ALL:
      serviceId = NVM_SID_KILLWRITEALL;
      break;
    case NVM_MULTIBLOCKJOBTYPE_KILL_READ_ALL:
      serviceId = NVM_SID_KILLREADALL;
      break;

    default:
      serviceId = NVM_SID_WRITEALL;
      break;
  }

  return serviceId;
}

#  endif /* NvM_InvokeMultiBlockCallback */

#endif /* NVM_USE_ASR440_CALLBACK_INTERFACE */

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
*  NvM_Notification_ProcessSingleBlockCallback
**********************************************************************************************************************/
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
FUNC(void, NVM_PRIVATE_CODE) NvM_Notification_ProcessSingleBlockCallback(
    NvM_SingleBlockJobContextPtrToConstType singleBlockJobContext,
    NvM_PartitionIdType partitionId)
{
  NvM_BlockDescriptorPtrType blockDescriptor =
    NvM_GetAddrBlockDescriptor(singleBlockJobContext->BlockDescriptorLookupTableId);

  if ((blockDescriptor->SingleBlockCallback != NULL_PTR) || (blockDescriptor->ExtendedSingleBlockCallback != NULL_PTR))
  {
    boolean allowCallbackInvocation = TRUE;

    if (((singleBlockJobContext->SingleBlockJobType == NVM_SINGLEBLOCKJOBTYPE_READ_ALL_BLOCK)
      && (blockDescriptor->Flags.CallbackInvocationForReadAllEnabled == NVM_INVOKE_CALLBACKS_FOR_READALL_OFF))
      || (singleBlockJobContext->SingleBlockJobType == NVM_SINGLEBLOCKJOBTYPE_RESTORE_BLOCK_DEFAULTS))
    {
      allowCallbackInvocation = FALSE;
    }

    if (allowCallbackInvocation)
    {
#if (NVM_USE_ASR440_CALLBACK_INTERFACE == STD_ON)
      NvM_BlockRequestType request =
        NvM_Notification_ConvertSingleBlockJobTypeToBlockRequest(singleBlockJobContext->SingleBlockJobType);
#else
      NvM_ServiceIdType request =
        NvM_Notification_ConvertSingleBlockJobTypeToServiceId(singleBlockJobContext->SingleBlockJobType);
#endif /* NVM_USE_ASR440_CALLBACK_INTERFACE */
      NvM_BlockManagementInformationPtrToConstType blockManagementInfo = NvM_GlobalUtilityLib_GetBlockManagementInfo(
        singleBlockJobContext->BlockId,
        singleBlockJobContext->BlockDescriptorLookupTableId,
        partitionId);

      if (blockDescriptor->SingleBlockCallback != NULL_PTR)
      {
        (void)blockDescriptor->SingleBlockCallback(request, blockManagementInfo->ErrorStatus);
      }
      if (blockDescriptor->ExtendedSingleBlockCallback != NULL_PTR)
      {
        (void)(blockDescriptor->ExtendedSingleBlockCallback(singleBlockJobContext->BlockId, request, 
          blockManagementInfo->ErrorStatus));
      }
    }
  }
}

/**********************************************************************************************************************
*  NvM_Notification_ProcessMultiBlockNotification
**********************************************************************************************************************/
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
FUNC(void, NVM_PRIVATE_CODE) NvM_Notification_ProcessMultiBlockNotification(
    const NvM_MultiBlockJobType multiBlockJobType,
    const NvM_RequestResultType requestResult)
{

#if (NVM_MULTIBLOCK_NOTIFICATION_ENABLED == STD_ON)

# if (NVM_USE_ASR440_CALLBACK_INTERFACE == STD_ON)
  NvM_MultiBlockRequestType request =
    NvM_Notification_ConvertMultiBlockJobTypeToMultiBlockRequest(multiBlockJobType);
# else
  NvM_ServiceIdType request =
    NvM_Notification_ConvertMultiBlockJobTypeToServiceId(multiBlockJobType);
# endif /* NVM_USE_ASR440_CALLBACK_INTERFACE */

# ifdef NvM_InvokeCurrentJobMode

  /* NvM_InvokeCurrentJobMode is only called in the case of asynchronous multiblockjobs excluding cancel */
  if((multiBlockJobType == NVM_MULTIBLOCKJOBTYPE_READ_ALL)
    || (multiBlockJobType == NVM_MULTIBLOCKJOBTYPE_WRITE_ALL)
    || (multiBlockJobType == NVM_MULTIBLOCKJOBTYPE_VALIDATE_ALL))
  {
    /* (void)NvM_InvokeCurrentJobMode(request, requestResult); */
  }

# else

  /* NvM_InvokeMultiBlockCallback is only called in the case of a termination of a multiblock job. */
  if(requestResult != NVM_REQ_PENDING)
  {
    (void)NvM_InvokeMultiBlockCallback(request, requestResult);
  }

# endif /* NvM_InvokeCurrentJobMode */
#else

  NVM_DUMMY_STATEMENT_CONST(multiBlockJobType);                                                                         /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  NVM_DUMMY_STATEMENT_CONST(requestResult);                                                                             /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

#endif /* NVM_MULTIBLOCK_NOTIFICATION_ENABLED */
}

/**********************************************************************************************************************
*  NvM_Notification_ProcessBackgroundCrcRecalcNotification
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, NVM_PRIVATE_CODE) NvM_Notification_ProcessBackgroundCrcRecalcNotification(
  const NvM_BlockDescriptorLookupTableIdType blockDescriptorLookupTableId,
  const NvM_RequestResultType requestResult)
{
  NvM_BlockDescriptorPtrType blockDescriptor =
    NvM_GetAddrBlockDescriptor(blockDescriptorLookupTableId);
  
  if (blockDescriptor->BackgroundCrcRecalcCallback != NULL_PTR)
  {
    blockDescriptor->BackgroundCrcRecalcCallback(requestResult);
  }
}

#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: NvM_Notification.c
 *********************************************************************************************************************/
