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
/*!        \file  NvM_DataSync.c
 *        \brief  NvM_DataSync source file
 *      \details  Implementation of the data synchronization unit of the NvM.
 *         \unit  NvM_DataSync
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#define NVM_DATASYNC_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "NvM_DataSync.h"
#include "vstdlib.h"
#include "NvM_Cfg.h"
#include "NvM_GlobalUtilityLib.h"
#include <string.h>

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
 * NvM_DataSync_ProcessDataRecoveryViaCallback()
 *********************************************************************************************************************/
/*! \brief       Process Default Data Callbacks (ExtendedInitBlockCallback / InitBlockCallback)
 *  \details     In case of explicit synchronization, a synchronization is performed after the callback invocation.
 *  \param[in]   blockDescriptor     Pointer to the block descriptor
 *  \param[in]   jobType             Type of the current job
 *  \param[in]   targetBuffer        Target buffer for the extended init callback
 *  \pre         -
 *  \return      E_OK if callback is called successfully, E_NOT_OK otherwise
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
NVM_LOCAL FUNC(Std_ReturnType, NVM_PRIVATE_CODE) NvM_DataSync_ProcessDataRecoveryViaCallback(
  NvM_BlockDescriptorPtrType blockDescriptor,
  const NvM_SingleBlockJobType jobType,
  NvM_DataPtrType targetBuffer);

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * NvM_DataSync_ProcessDataRecoveryViaCallback()
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
 */
NVM_LOCAL FUNC(Std_ReturnType, NVM_PRIVATE_CODE) NvM_DataSync_ProcessDataRecoveryViaCallback(
    NvM_BlockDescriptorPtrType blockDescriptor,
    const NvM_SingleBlockJobType jobType,
    NvM_DataPtrType targetBuffer)
{
  Std_ReturnType ret = E_NOT_OK;
  boolean isExplicitSyncRequired = FALSE;

  boolean isCallbackInvocationAllowed = (jobType != NVM_SINGLEBLOCKJOBTYPE_READ_ALL_BLOCK)
          || (blockDescriptor->Flags.CallbackInvocationForReadAllEnabled != NVM_INVOKE_CALLBACKS_FOR_READALL_OFF);

  if ((blockDescriptor->ExtendedInitBlockCallback != NULL_PTR) && isCallbackInvocationAllowed)
  {
    NvM_DataPtrType syncBuffer = NULL_PTR;

    if (targetBuffer != NULL_PTR)
    {
      syncBuffer = targetBuffer;
    }
    else if (blockDescriptor->ReadRamBlockFromNvCallback != NULL_PTR)
    {
      syncBuffer = (NvM_DataPtrType)NvM_GetAddrInternalBuffer(0u, blockDescriptor->PartitionId);
      isExplicitSyncRequired = TRUE;
    }
    else
    {
      syncBuffer = (NvM_DataPtrType)blockDescriptor->RamBlockDataAddress;
    }

    ret = blockDescriptor->ExtendedInitBlockCallback(blockDescriptor->NvramBlockIdentifier, syncBuffer,                 /* VCA_NVM_ExtendedInitBlockCallback */
      blockDescriptor->NvBlockLength);

    if ((isExplicitSyncRequired == TRUE) && (ret == E_OK))
    {    
      ret = blockDescriptor->ReadRamBlockFromNvCallback(syncBuffer);                                                    /* VCA_NVM_NullptrCheckByFlag */
    }
  }
  else if ((blockDescriptor->InitBlockCallback != NULL_PTR) && isCallbackInvocationAllowed)
  {
    ret = blockDescriptor->InitBlockCallback();
  }
  else
  {
    /* Intentionally left empty */
  }

  return ret;
}

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * NvM_DataSync_RequestData()
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
FUNC(Std_ReturnType, NVM_PRIVATE_CODE) NvM_DataSync_RequestData(
    const NvM_BlockDescriptorLookupTableIdType blockDescriptorLookupTableId,
    NvM_DataPtrType targetBuffer,
    NvM_DataPtrToConstType srcBuffer)
{
  Std_ReturnType ret = E_OK;
  NvM_BlockDescriptorPtrType blockDescriptor = NvM_GetAddrBlockDescriptor(blockDescriptorLookupTableId);

  if (srcBuffer != NULL_PTR)
  {
    memcpy(targetBuffer, srcBuffer, blockDescriptor->NvBlockLength);                                            /* VCA_NVM_VStdLibMemCpyCalls */
  }
  else if (blockDescriptor->WriteRamBlockToNvCallback != NULL_PTR)
  {
    ret = blockDescriptor->WriteRamBlockToNvCallback(targetBuffer);                                                     /* VCA_NVM_WriteRamBlockToNvCallback */
  }
  else
  {
    memcpy(targetBuffer, blockDescriptor->RamBlockDataAddress, blockDescriptor->NvBlockLength);                 /* VCA_NVM_VStdLibMemCpyCalls */
  }

  return ret;
}

/**********************************************************************************************************************
 * NvM_DataSync_ProvideData()
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
FUNC(Std_ReturnType, NVM_PRIVATE_CODE) NvM_DataSync_ProvideData(
    const NvM_BlockDescriptorLookupTableIdType blockDescriptorLookupTableId,
    NvM_DataPtrToConstType srcBuffer,
    NvM_DataPtrType targetBuffer)
{
  Std_ReturnType ret = E_OK;
  NvM_BlockDescriptorPtrType blockDescriptor = NvM_GetAddrBlockDescriptor(blockDescriptorLookupTableId);

  if (targetBuffer != NULL_PTR)
  {
    memcpy(targetBuffer, srcBuffer, blockDescriptor->NvBlockLength);                                            /* VCA_NVM_VStdLibMemCpyCalls */
  }
  else if (blockDescriptor->ReadRamBlockFromNvCallback != NULL_PTR)
  {
    ret = blockDescriptor->ReadRamBlockFromNvCallback(srcBuffer);
  }
  else
  {
    memcpy(blockDescriptor->RamBlockDataAddress, srcBuffer, blockDescriptor->NvBlockLength);                    /* VCA_NVM_VStdLibMemCpyCalls */
  }

  return ret;
}

/**********************************************************************************************************************
 * NvM_DataSync_RestoreDefaultData()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, NVM_PRIVATE_CODE) NvM_DataSync_RestoreDefaultData(
    const NvM_BlockDescriptorLookupTableIdType blockDescriptorLookupTableId,
    const NvM_SingleBlockJobType jobType,
    NvM_DataPtrType targetBuffer)
{
  Std_ReturnType ret = E_NOT_OK;
  NvM_BlockDescriptorPtrType blockDescriptor = NvM_GetAddrBlockDescriptor(blockDescriptorLookupTableId);

  if (blockDescriptor->RomBlockDataAddress != NULL_PTR)
  {
    ret = NvM_DataSync_ProvideData(blockDescriptorLookupTableId, blockDescriptor->RomBlockDataAddress, targetBuffer);
  }
  else
  {
    ret = NvM_DataSync_ProcessDataRecoveryViaCallback(blockDescriptor, jobType, targetBuffer);
  }

  return ret;
}

#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  VCA JUSTIFICATIONS
 **********************************************************************************************************************/
/* VCA_JUSTIFICATION_BEGIN  

\ID VCA_NVM_WriteRamBlockToNvCallback
   \DESCRIPTION A function with pointer parameters is directly called, but the function is not
                defined within the analyzed sources. VCA is unable to determine the
                behavior of the function.

   \COUNTERMEASURE \N Arguments that contain var pointer are checked by review: 
                      Pointer type corresponds to function parameter type

\ID VCA_NVM_ExtendedInitBlockCallback
   \DESCRIPTION A function with pointer parameters is directly called, but the function is not
                defined within the analyzed sources. VCA is unable to determine the
                behavior of the function.

   \COUNTERMEASURE \N Arguments that contain var pointer are checked by review: 
                      Pointer type corresponds to function parameter type

\ID VCA_NVM_NullptrCheckByFlag
   \DESCRIPTION A function is called via a function pointer. Precondition for the call is a set flag. One condition for
                setting the flag is a null pointer check. This check is not considered by VCA but de facto the
                function pointer is checked not to be a null pointer.

   \COUNTERMEASURE \N The function pointer is checked not to be a null pointer by review.
                      A null pointer check is performed, which ensures that the pointer is valid if called.
                   \T Component tests for RestoreBlockDefaults

VCA_JUSTIFICATION_END */

/**********************************************************************************************************************
 *  END OF FILE: NvM_DataSync.c
 *********************************************************************************************************************/
