/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2025 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!        \file  NvM_DataIntegrityMac.c
 *        \brief  NvM_DataIntegrityMac source file
 *      \details  Implementation of the data integrity service unit of the NvM.
 *         \unit  NvM_DataIntegrityMac
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#define NVM_DATAINTEGRITYMAC_SOURCE

 /**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "NvM_DataIntegrityMac.h"

#if (NVM_MAC_ENABLED == STD_ON) /* COV_MSR_UT_OPTIONAL_UNIT */
#include "Csm.h"

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
 *  NvM_DataIntegrityMac_PerformCsmGenerateJobAttempt
 *********************************************************************************************************************/
/*!
 * \brief           Execute a Csm generate job attempt and check for success
 * \details         Exports API result via CsmResultPtr
 * \param[in]       Instance      Pointer to MAC job structure
 * \param[in,out]   CsmResultPtr  Pointer holding Csm API call result
 * \return          TRUE if job was accepted and resulting MAC length is as expected; FALSE otherwise
 * \pre             -
 * \config          -
 * \context         TASK
 * \reentrant       FALSE
 * \synchronous     TRUE
 */
NVM_LOCAL_INLINE FUNC(boolean, NVM_PRIVATE_CODE) NvM_DataIntegrityMac_PerformCsmGenerateJobAttempt(
    NvM_DataIntegrityService_InstancePtrToConstType Instance,
    Std_ReturnType *CsmResultPtr);

/**********************************************************************************************************************
 *  NvM_DataIntegrityMac_PerformCsmVerifyJobAttempt
 *********************************************************************************************************************/
/*!
 * \brief           Execute a Csm verify job attempt and check for success
 * \details         Exports API result via CsmResultPtr
 * \param[in]       Instance      Pointer to MAC job structure
 * \param[in,out]   CsmResultPtr  Pointer holding Csm API call result
 * \return          TRUE if job was accepted and resulting verification result is OK; FALSE otherwise
 * \pre             -
 * \config          -
 * \context         TASK
 * \reentrant       FALSE
 * \synchronous     TRUE
 */
NVM_LOCAL_INLINE FUNC(boolean, NVM_PRIVATE_CODE) NvM_DataIntegrityMac_PerformCsmVerifyJobAttempt(
    NvM_DataIntegrityService_InstancePtrToConstType Instance,
    Std_ReturnType *CsmResultPtr);


/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  NvM_DataIntegrityMac_PerformCsmGenerateJobAttempt
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
NVM_LOCAL_INLINE FUNC(boolean, NVM_PRIVATE_CODE) NvM_DataIntegrityMac_PerformCsmGenerateJobAttempt(
    NvM_DataIntegrityService_InstancePtrToConstType Instance,
    Std_ReturnType* CsmResultPtr)
{
  /* API precondition of MacGenerate(): expected MAC block length must be injected and will be checked by CSM */
  uint32 macResultLength = Instance->MacContext.BlockMacLength;
  boolean attemptSuccess = FALSE;

  *CsmResultPtr = Csm_MacGenerate(
      Instance->MacContext.CsmJobId,
      CRYPTO_OPERATIONMODE_SINGLECALL,
      Instance->BlockDataPtr,
      Instance->BlockDataLength,
      Instance->DataIntegrityRecordPtr,
      &macResultLength);

  if ((*CsmResultPtr == E_OK) && (macResultLength == Instance->MacContext.BlockMacLength))
  {
    attemptSuccess = TRUE;
  }

  return attemptSuccess;
}

/**********************************************************************************************************************
 *  NvM_DataIntegrityMac_PerformCsmVerifyJobAttempt
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
NVM_LOCAL_INLINE FUNC(boolean, NVM_PRIVATE_CODE) NvM_DataIntegrityMac_PerformCsmVerifyJobAttempt(
    NvM_DataIntegrityService_InstancePtrToConstType Instance,
    Std_ReturnType* CsmResultPtr)
{
  Crypto_VerifyResultType verifyResult = CRYPTO_E_VER_NOT_OK;
  boolean attemptSuccess = FALSE;

  /* API precondition: length must be presented as BIT-length */
  uint32 macLengthInBits = (uint32) Instance->MacContext.BlockMacLength * 8u;

  *CsmResultPtr = Csm_MacVerify(
      Instance->MacContext.CsmJobId,
      CRYPTO_OPERATIONMODE_SINGLECALL,
      Instance->BlockDataPtr,
      Instance->BlockDataLength,
      Instance->DataIntegrityRecordPtr,
      macLengthInBits,
      &verifyResult);

  if ((*CsmResultPtr == E_OK) && (verifyResult == CRYPTO_E_VER_OK))
  {
    attemptSuccess = TRUE;
  }

  return attemptSuccess;
}

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  NvM_DataIntegrityMac_Init
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, NVM_PRIVATE_CODE) NvM_DataIntegrityMac_Init(
  NvM_DataIntegrityService_InstancePtrType Instance,
  NvM_CsmJobIdType CsmJobId,
  uint16 BlockMacLength
)
{
  Instance->JobStatus = NVM_DATAINTEGRITYSERVICE_STATUS_PENDING;

  Instance->MacContext.CsmJobId = CsmJobId;
  Instance->MacContext.BlockMacLength = BlockMacLength;
  Instance->MacContext.CsmJobAttemptCounter = 0u;
}

/**********************************************************************************************************************
 *  NvM_DataIntegrityMac_Process
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
FUNC(void, NVM_PRIVATE_CODE) NvM_DataIntegrityMac_Process(
  NvM_DataIntegrityService_InstancePtrType Instance
)
{
  if (Instance->JobStatus == NVM_DATAINTEGRITYSERVICE_STATUS_PENDING)
  {
    Std_ReturnType csmResult = E_NOT_OK;
    boolean attemptSuccess = FALSE;

    /* Perform CSM job processing */
    if (Instance->JobType == NVM_DATAINTEGRITYSERVICE_JOB_GENERATE)
    {
      /* Call CSM MAC generation service */
      attemptSuccess = NvM_DataIntegrityMac_PerformCsmGenerateJobAttempt(Instance, &csmResult);
    }
    else /* NVM_DATAINTEGRITYMAC_JOB_VERIFY */
    {
      /* Call CSM MAC verification service */
      attemptSuccess = NvM_DataIntegrityMac_PerformCsmVerifyJobAttempt(Instance, &csmResult);
    }

    /* Increment attempt counter */
    Instance->MacContext.CsmJobAttemptCounter++;

    /* Handle result and update jobStatus */
    if (attemptSuccess == TRUE)
    {
      Instance->JobStatus = NVM_DATAINTEGRITYSERVICE_STATUS_FINISHED_SUCCESSFUL;
    }
    else if ((csmResult == CRYPTO_E_BUSY) || (csmResult == CRYPTO_E_QUEUE_FULL)) 
    {
      /* From CSM developers, only in these cases the crypto stack is busy and a retry makes sense*/

#if (NVM_CSM_RETRY_COUNT != 0u)
      if (Instance->MacContext.CsmJobAttemptCounter > NVM_CSM_RETRY_COUNT)
#endif
      {
        /* Check if max attempts reached */
        Instance->JobStatus = NVM_DATAINTEGRITYSERVICE_STATUS_FINISHED_UNSUCCESSFUL;
      }
    }
    else
    {
      /* Other CSM error */
      Instance->JobStatus = NVM_DATAINTEGRITYSERVICE_STATUS_FINISHED_UNSUCCESSFUL;
    }
  }
}

#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* (NVM_MAC_ENABLED == STD_ON) */
