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
/*!        \file  NvM_DataIntegrityService.c
 *        \brief  NvM_DataIntegrityService source file
 *      \details  Implementation of the data integrity service unit of the NvM.
 *         \unit  NvM_DataIntegrityService
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#define NVM_DATAINTEGRITYSERVICE_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "NvM_DataIntegrityService.h"
#include "NvM_DataIntegrityCrc.h"
#include "NvM_DataIntegrityMac.h"

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
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

#define NVM_START_SEC_CODE
#include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * NvM_DataIntegrityService_Init()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, NVM_PRIVATE_CODE) NvM_DataIntegrityService_Init(
  NvM_DataIntegrityService_InstancePtrType dataIntegrityServiceInstance,
  NvM_DataIntegrityJobContextConstPtrType dataIntegrityJobContext)
{
  NvM_BlockDescriptorPtrType blockDescriptor =
    NvM_GetAddrBlockDescriptor(dataIntegrityJobContext->BlockDescriptorLookupTableId);

  dataIntegrityServiceInstance->BlockId = dataIntegrityJobContext->ExternalBlockId;
  dataIntegrityServiceInstance->DataIndex = dataIntegrityJobContext->DataIndex;
  dataIntegrityServiceInstance->BlockDataLength = blockDescriptor->NvBlockLength;
  dataIntegrityServiceInstance->BlockDataPtr = dataIntegrityJobContext->DataBuffer;

  dataIntegrityServiceInstance->DataIntegrityRecordPtr = dataIntegrityJobContext->DataIntegrityRecordPtr;

  /* the JobStatus will be initialized by the CRC/MAC specific units */

  dataIntegrityServiceInstance->JobType = dataIntegrityJobContext->JobType;
  dataIntegrityServiceInstance->DataIntegrityType = blockDescriptor->DataIntegritySettings;

#if (NVM_MAC_ENABLED == STD_ON)
  if(dataIntegrityServiceInstance->DataIntegrityType == NVM_BLOCK_DATA_INTEGRITY_MAC)
  {
    NvM_CsmJobIdType macJobId;

    macJobId = (dataIntegrityServiceInstance->JobType == NVM_DATAINTEGRITYSERVICE_JOB_GENERATE)
      ? blockDescriptor->MacGenerationJobId
      : blockDescriptor->MacVerificationJobId;

    NvM_DataIntegrityMac_Init(dataIntegrityServiceInstance, macJobId, blockDescriptor->MacLength);
  }
  else
#endif /* NVM_MAC_ENABLED == STD_ON */
  {
    /* Default case is CRC (NVM_BLOCK_DATA_INTEGRITY_CRC_16 or NVM_BLOCK_DATA_INTEGRITY_CRC_32).
      In case of NVM_BLOCK_DATA_INTEGRITY_OFF, the DataIntegrityService won't be called in the first place */
    NvM_DataIntegrityCrc_Init(dataIntegrityServiceInstance);
  }
}


/**********************************************************************************************************************
 * NvM_DataIntegrityService_Process()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, NVM_PRIVATE_CODE) NvM_DataIntegrityService_Process(
  NvM_DataIntegrityService_InstancePtrType dataIntegrityServiceInstance)
{
#if (NVM_MAC_ENABLED == STD_ON)
  if(dataIntegrityServiceInstance->DataIntegrityType == NVM_BLOCK_DATA_INTEGRITY_MAC)
  {
    NvM_DataIntegrityMac_Process(dataIntegrityServiceInstance);
  }
  else
#endif /* NVM_MAC_ENABLED == STD_ON */
  {
    /* Default case is CRC (NVM_BLOCK_DATA_INTEGRITY_CRC_16 or NVM_BLOCK_DATA_INTEGRITY_CRC_32).
      In case of NVM_BLOCK_DATA_INTEGRITY_OFF, the DataIntegrityService won't be called in the first place */
    NvM_DataIntegrityCrc_Process(dataIntegrityServiceInstance);
  }
}

/**********************************************************************************************************************
 * NvM_DataIntegrityService_IsPending()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(NvM_DataIntegrityService_Status, NVM_PRIVATE_CODE) NvM_DataIntegrityService_GetStatus(
  NvM_DataIntegrityService_InstancePtrToConstType dataIntegrityServiceInstance)
{
  return dataIntegrityServiceInstance->JobStatus;
}


#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: NvM_DataIntegrityService.c
 *********************************************************************************************************************/
