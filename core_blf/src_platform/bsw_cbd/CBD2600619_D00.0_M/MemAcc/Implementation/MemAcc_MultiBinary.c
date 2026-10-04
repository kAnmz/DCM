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
/*!        \file  MemAcc_MultiBinary.c
 *        \brief  MemAcc_MultiBinary source file
 *      \details  -
 *         \unit  MultiBinary
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#define MEMACC_MULTIBINARY_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "MemAcc_MultiBinary.h"
#include "vstdlib.h"
#include "MemAcc_MemAb.h"
#include "MemAcc_ErrorCheck.h"
#include "MemAcc_Callout.h"

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/
#if !defined(MEMACC_LOCAL)
# define MEMACC_LOCAL static
#endif

#if !defined(MEMACC_LOCAL_INLINE)
# define MEMACC_LOCAL_INLINE LOCAL_INLINE
#endif

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
#define MEMACC_START_SEC_CODE
#include "MemAcc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if (MEMACC_MULTIBINARY_ISMULTIBINARYUSECASE == STD_ON) /* COV_MSR_UT_OPTIONAL_UNIT */

/**********************************************************************************************************************
 * MemAcc_MultiBinary_GetActiveBinary()
 *********************************************************************************************************************/
/*! \brief       Gets the currently active binary ID from the synchronization token.
 *  \details     -
 *  \return      The binary ID.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
MEMACC_LOCAL MemAcc_MultiBinary_IdType MemAcc_MultiBinary_GetActiveBinary(void);

/**********************************************************************************************************************
 * MemAcc_MultiBinary_IsStopFlagSet()
 *********************************************************************************************************************/
/*! \brief       Checks if the stop flag is set in the synchronization token.
 *  \details     -
 *  \return      TRUE if the stop flag is set, otherwise FALSE.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
MEMACC_LOCAL boolean MemAcc_MultiBinary_IsStopFlagSet(void);

# if (MEMACC_MULTIBINARY_ISMASTERBINARY == STD_ON)

/**********************************************************************************************************************
 * MemAcc_MultiBinary_HasDirectRequest()
 *********************************************************************************************************************/
/*! \brief       Checks if the given access request is a direct request.
 *  \details     -
 *  \param[in]   accessRequest access request to check.
 *  \return      TRUE if it is a direct request, otherwise FALSE.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
MEMACC_LOCAL boolean MemAcc_MultiBinary_HasDirectRequest(const MemAcc_MultiBinary_AccessRequestType* accessRequest);

/**********************************************************************************************************************
 * MemAcc_MultiBinary_HasRedirectRequest()
 *********************************************************************************************************************/
/*! \brief       Checks if the given access request is a redirect request.
 *  \details     -
 *  \param[in]   accessRequest access request to check.
 *  \return      TRUE if it is a redirect request, otherwise FALSE.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
MEMACC_LOCAL boolean MemAcc_MultiBinary_HasRedirectRequest(const MemAcc_MultiBinary_AccessRequestType* accessRequest);

/**********************************************************************************************************************
 * MemAcc_MultiBinary_SetSynchronizationToken()
 *********************************************************************************************************************/
/*! \brief       Uses the given parameters to create and set the synchronization token.
 *  \details     -
 *  \param[in]   binaryId The binary ID that should have access.
 *  \param[in]   stopFlag The stop flag which defines if the binary should stop processing.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
MEMACC_LOCAL void MemAcc_MultiBinary_SetSynchronizationToken(MemAcc_MultiBinary_IdType binaryId, boolean stopFlag);

/**********************************************************************************************************************
 * MemAcc_MultiBinary_GetNextJob()
 *********************************************************************************************************************/
/*! \brief       Gets the highest priority access request to process.
 *  \details     -
 *  \return      The selected access request. If there is none it returns NULL_PTR.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
MEMACC_LOCAL MemAcc_MultiBinary_AccessRequestType* MemAcc_MultiBinary_GetNextJob(void);

#  if (MEMACC_MULTIBINARY_HASREDIRECTREQUESTS == STD_ON)

/**********************************************************************************************************************
 * MemAcc_MultiBinary_IsRedirectJobStepInfoValid()
 *********************************************************************************************************************/
/*! \brief       Checks if the redirect job step information is valid.
 *  \details     This check is performed by master before the job step is forwarded to the mem. This is performed to
 *               ensure correct configuration of memory between two binaries with redirect jobs.
 *  \param[in]   binaryId BinaryId the request belongs to
 *  \param[in]   redirectJobStepInfoPtr Request that should be validated
 *  \return      TRUE if the redirect job step info is valid
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
MEMACC_LOCAL boolean MemAcc_MultiBinary_IsRedirectJobStepInfoValid(
  MemAcc_MultiBinary_IdType binaryId,
  const MemAcc_MultiBinary_RedirectJobStepInfoType* const redirectJobStepInfoPtr);

/**********************************************************************************************************************
 * MemAcc_MultiBinary_IsRedirectJobStepInfoValidForIndex()
 *********************************************************************************************************************/
/*! \brief       Checks if the redirect job step information is valid for the given redirect sector batch.
 *  \details     -
 *  \param[in]   binaryId BinaryId the request belongs to
 *  \param[in]   redirectJobStepInfoPtr Request that should be validated
 *  \param[in]   index Numeric identifier of the mem redirect sector batch
 *  \return      TRUE if the redirect job step info is valid
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
MEMACC_LOCAL boolean MemAcc_MultiBinary_IsRedirectJobStepInfoValidForIndex(
  MemAcc_MultiBinary_IdType binaryId,
  const MemAcc_MultiBinary_RedirectJobStepInfoType* const redirectJobStepInfoPtr,
  MemAcc_RedirectSectorBatchIterType index);

/**********************************************************************************************************************
 * MemAcc_MultiBinary_IsRedirectAddressLengthValid()
 *********************************************************************************************************************/
/*! \brief       Checks if the redirect job step address and length are valid for the given redirect sector batch.
 *  \details     -
 *  \param[in]   redirectJobStepInfoPtr Request that should be validated
 *  \param[in]   index Numeric identifier of the mem redirect sector batch
 *  \return      TRUE if the redirect job step address and length are valid
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
MEMACC_LOCAL boolean MemAcc_MultiBinary_IsRedirectAddressLengthValid(
  const MemAcc_MultiBinary_RedirectJobStepInfoType* const redirectJobStepInfoPtr,
  MemAcc_RedirectSectorBatchIterType index);

/**********************************************************************************************************************
 * MemAcc_MultiBinary_GetLowerLayerIndexOfMemDriverIndex()
 *********************************************************************************************************************/
/*! \brief       Determines the index of the lower layer table given the configured Mem Driver Index
 *  \details     -
 *  \param[in]   memDriverIndex Numeric identifier of the mem driver
 *  \return      MemAcc_LowerLayerIndexType
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
MEMACC_LOCAL MemAcc_LowerLayerIndexType MemAcc_MultiBinary_GetLowerLayerIndexOfMemDriverIndex(
  MemAcc_MemDriverIndexType memDriverIndex);

/**********************************************************************************************************************
 * MemAcc_MultiBinary_DispatchMultiBinaryJobStepToMem()
 *********************************************************************************************************************/
/*! \brief       Dispatches the given redirect request to the mem driver.
 *  \details     -
 *  \param[in]   redirectJobStepInfoPtr Detailed information about the redirect job step.
 *  \param[in]   redirectJobStepDataBufferPtr Contains data buffer for a redirect request.
 *  \return      E_OK if job was dispatched, E_NOT_OK otherwise.
 *  \pre         Redirect request which was not processed yet.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
MEMACC_LOCAL Std_ReturnType MemAcc_MultiBinary_DispatchMultiBinaryJobStepToMem(
  const MemAcc_MultiBinary_RedirectJobStepInfoType* const redirectJobStepInfoPtr,
  MemAcc_DataType* const redirectJobStepDataBufferPtr);

/**********************************************************************************************************************
 * MemAcc_MultiBinary_HandleNewRedirectRequest()
 *********************************************************************************************************************/
/*! \brief       Handles a new redirect request, therefore checks its validity and forwards the request to the Mem
                 driver.
 *  \details     -
 *  \param[in]   binaryId The binary ID of the redirect request.
 *  \param[in]   redirectJobStepInfoPtr Detailed information about the redirect job step.
 *  \param[in]   redirectJobStepResultPtr Contains job result for a redirect request.
 *  \param[in]   redirectJobStepDataBufferPtr Contains data buffer for a redirect request.
 *  \pre         Redirect request which was not processed yet.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
MEMACC_LOCAL void MemAcc_MultiBinary_HandleNewRedirectRequest(
  const MemAcc_MultiBinary_IdType binaryId,
  const MemAcc_MultiBinary_RedirectJobStepInfoType* const redirectJobStepInfoPtr,
  MemAcc_MultiBinary_RedirectJobStepResultType* const redirectJobStepResultPtr,
  MemAcc_DataType* const redirectJobStepDataBufferPtr);

/**********************************************************************************************************************
 * MemAcc_MultiBinary_ProcessActiveRedirectRequest()
 *********************************************************************************************************************/
/*! \brief       Processes a redirect request, therefore checks if it is already finished by the Mem driver and set
                 job result respectively.
 *  \details     -
 *  \param[in]   redirectJobStepInfoPtr Detailed information about the redirect job step.
 *  \param[in]   redirectJobStepResultPtr Contains job result for a redirect request.
 *  \pre         Redirect request was already forwarded to the Mem driver.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
MEMACC_LOCAL void MemAcc_MultiBinary_ProcessActiveRedirectRequest(
  const MemAcc_MultiBinary_RedirectJobStepInfoType* const redirectJobStepInfoPtr,
  MemAcc_MultiBinary_RedirectJobStepResultType* const redirectJobStepResultPtr);

#  endif /* MEMACC_MULTIBINARY_HASREDIRECTREQUESTS */
# endif /* MEMACC_MULTIBINARY_ISMASTERBINARY */

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * MemAcc_MultiBinary_GetActiveBinary()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
MEMACC_LOCAL MemAcc_MultiBinary_IdType MemAcc_MultiBinary_GetActiveBinary(void)
{
  return (*MemAcc_MultiBinary_SynchronizationTokenPtr) & MEMACC_MULTIBINARY_TOKEN_BINARYID_MASK;
}

/**********************************************************************************************************************
 * MemAcc_MultiBinary_IsStopFlagSet()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
MEMACC_LOCAL boolean MemAcc_MultiBinary_IsStopFlagSet(void)
{
  return (*MemAcc_MultiBinary_SynchronizationTokenPtr & MEMACC_MULTIBINARY_TOKEN_STOP_MASK) != 0u;
}

# if (MEMACC_MULTIBINARY_ISMASTERBINARY == STD_ON)

/**********************************************************************************************************************
 * MemAcc_MultiBinary_HasDirectRequest()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
MEMACC_LOCAL boolean MemAcc_MultiBinary_HasDirectRequest(const MemAcc_MultiBinary_AccessRequestType* accessRequest)
{
  return accessRequest->PublishedRequestType == (MemAcc_MultiBinary_AtomicPublishedRequestType)MEMACC_MULTIBINARY_DIRECT;
}

/**********************************************************************************************************************
 * MemAcc_MultiBinary_HasRedirectRequest()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
MEMACC_LOCAL boolean MemAcc_MultiBinary_HasRedirectRequest(const MemAcc_MultiBinary_AccessRequestType* accessRequest)
{
  return accessRequest->PublishedRequestType == (MemAcc_MultiBinary_AtomicPublishedRequestType)MEMACC_MULTIBINARY_REDIRECT;
}

/**********************************************************************************************************************
 * MemAcc_MultiBinary_SetSynchronizationToken()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
MEMACC_LOCAL void MemAcc_MultiBinary_SetSynchronizationToken(MemAcc_MultiBinary_IdType binaryId, boolean stopFlag)
{
  MemAcc_MultiBinary_SynchronizationTokenType token = MEMACC_MULTIBINARY_TOKEN_BINARYID_MASK & binaryId;

  if (stopFlag == TRUE)
  {
    token |= MEMACC_MULTIBINARY_TOKEN_STOP_MASK;
  }

  *MemAcc_MultiBinary_SynchronizationTokenPtr = token;
}

/**********************************************************************************************************************
 * MemAcc_MultiBinary_GetNextJob()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
MEMACC_LOCAL MemAcc_MultiBinary_AccessRequestType* MemAcc_MultiBinary_GetNextJob(void)
{
  MemAcc_MultiBinary_AccessRequestType *result = NULL_PTR;

  for (MemAcc_MultiBinary_IdType i = 0; i < MEMACC_MULTIBINARY_NR_Of_BINARIES; i++)
  {
    boolean hasRedirectRequest = MemAcc_MultiBinary_HasRedirectRequest(MemAcc_MultiBinary_AccessRequests[i]);
    boolean hasDirectRequest = MemAcc_MultiBinary_HasDirectRequest(MemAcc_MultiBinary_AccessRequests[i]);
    /* Variable for one priority to not have more then one volatile read access in a single sequence point. */
    MemAcc_PriorityOfAddressAreaType loopPriority = MemAcc_MultiBinary_AccessRequests[i]->Priority;

    if (((hasRedirectRequest == TRUE) || (hasDirectRequest == TRUE)) &&
        ((result == NULL_PTR) || (result->Priority < loopPriority)))
    {
      result = MemAcc_MultiBinary_AccessRequests[i];
    }
  }

  return result;
}

#  if (MEMACC_MULTIBINARY_HASREDIRECTREQUESTS == STD_ON)

/**********************************************************************************************************************
 * MemAcc_MultiBinary_IsRedirectJobStepInfoValid()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 * \spec
 *   requires redirectJobStepInfoPtr != NULL_PTR;
 * \endspec
 */
MEMACC_LOCAL boolean MemAcc_MultiBinary_IsRedirectJobStepInfoValid(
  MemAcc_MultiBinary_IdType binaryId,
  const MemAcc_MultiBinary_RedirectJobStepInfoType* const redirectJobStepInfoPtr)
{
  boolean retVal = FALSE;

  if((redirectJobStepInfoPtr->JobStepType == MEMACC_WRITE_JOB) ||
     (redirectJobStepInfoPtr->JobStepType == MEMACC_READ_JOB) ||
     (redirectJobStepInfoPtr->JobStepType == MEMACC_COMPARE_JOB) ||
     (redirectJobStepInfoPtr->JobStepType == MEMACC_ERASE_JOB) ||
     (redirectJobStepInfoPtr->JobStepType == MEMACC_BLANKCHECK_JOB))
  {
    if(MemAcc_MultiBinary_GetLowerLayerIndexOfMemDriverIndex(redirectJobStepInfoPtr->MemDriverIndex) < MemAcc_GetSizeOfLowerLayer())
    {
      for(MemAcc_RedirectSectorBatchIterType index = 0u; index < MemAcc_GetSizeOfRedirectSectorBatch(); index++)
      {
        if(MemAcc_MultiBinary_IsRedirectJobStepInfoValidForIndex(binaryId, redirectJobStepInfoPtr, index) == TRUE)
        {
          retVal = TRUE;
          break;
        }
      }
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 * MemAcc_MultiBinary_IsRedirectJobStepInfoValidForIndex()
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
MEMACC_LOCAL boolean MemAcc_MultiBinary_IsRedirectJobStepInfoValidForIndex(
  MemAcc_MultiBinary_IdType binaryId,
  const MemAcc_MultiBinary_RedirectJobStepInfoType* const redirectJobStepInfoPtr,
  MemAcc_RedirectSectorBatchIterType index)
{
  boolean retVal = FALSE;

  if(MemAcc_GetSatelliteIdOfRedirectSectorBatch(index) == binaryId)
  {
    if(MemAcc_GetMemDriverIndexOfRedirectSectorBatch(index) == redirectJobStepInfoPtr->MemDriverIndex)
    {
      if(MemAcc_GetInstanceIdOfRedirectSectorBatch(index) == redirectJobStepInfoPtr->MemInstanceId)
      {
        if(MemAcc_MultiBinary_IsRedirectAddressLengthValid(redirectJobStepInfoPtr, index) == TRUE)
        {
          retVal = TRUE;
        }
      }
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 * MemAcc_MultiBinary_IsRedirectAddressLengthValid()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 * \spec
 *   requires redirectJobStepInfoPtr != NULL_PTR;
 * \endspec
 */
MEMACC_LOCAL boolean MemAcc_MultiBinary_IsRedirectAddressLengthValid(
  const MemAcc_MultiBinary_RedirectJobStepInfoType* const redirectJobStepInfoPtr,
  MemAcc_RedirectSectorBatchIterType index)
{
  MemAcc_AddressType jobStartAddress = redirectJobStepInfoPtr->PhysicalAddress;
  MemAcc_AddressType jobEndAdress = jobStartAddress + redirectJobStepInfoPtr->Length;
  MemAcc_AddressType sectorStartAddress = MemAcc_GetPhysicalStartAddressOfRedirectSectorBatch(index);
  MemAcc_AddressType sectorEndAddress = sectorStartAddress + MemAcc_GetLengthOfRedirectSectorBatch(index);

  return ((jobStartAddress >= sectorStartAddress) && (jobEndAdress <= sectorEndAddress));
}

/**********************************************************************************************************************
 * MemAcc_MultiBinary_GetLowerLayerIndexOfMemDriverIndex()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
MEMACC_LOCAL MemAcc_LowerLayerIndexType MemAcc_MultiBinary_GetLowerLayerIndexOfMemDriverIndex(MemAcc_MemDriverIndexType memDriverIndex)
{
  MemAcc_LowerLayerIndexType lowerLayerIndex = 0u;

  for (; lowerLayerIndex < MemAcc_GetSizeOfLowerLayer(); lowerLayerIndex++)
  {
    if(MemAcc_GetMemDriverIndexOfLowerLayer(lowerLayerIndex) == memDriverIndex)
    {
      break;
    }
  }

  return lowerLayerIndex;
}

/**********************************************************************************************************************
 * MemAcc_MultiBinary_DispatchMultiBinaryJobStepToMem()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 * \spec
 *   requires redirectJobStepInfoPtr != NULL_PTR;
 *   requires redirectJobStepDataBufferPtr != NULL_PTR;
 * \endspec
 */
MEMACC_LOCAL Std_ReturnType MemAcc_MultiBinary_DispatchMultiBinaryJobStepToMem(
  const MemAcc_MultiBinary_RedirectJobStepInfoType* const redirectJobStepInfoPtr,
  MemAcc_DataType* const redirectJobStepDataBufferPtr)
{
  Std_ReturnType memJobReturnValue = E_NOT_OK;

  const MemAcc_LowerLayerIndexType lowerLayerIndex = MemAcc_MultiBinary_GetLowerLayerIndexOfMemDriverIndex(redirectJobStepInfoPtr->MemDriverIndex);
  /*@ assert lowerLayerIndex < MemAcc_GetSizeOfLowerLayer(); */ /* VCA_MemAcc_MultiBinaryRedirectTableIndex */
  const MemAcc_MemInstanceIdType memInstanceId = redirectJobStepInfoPtr->MemInstanceId;
  const MemAcc_AddressType physicalAddress = redirectJobStepInfoPtr->PhysicalAddress;
  const MemAcc_LengthType length = redirectJobStepInfoPtr->Length;

  /*!
   * MEMACC_DEBUG_BREAKPOINT:
   * This breakpoint can be used to debug the interaction with the Mem Driver for multi-binary redirect access 
   * job steps. It is hit right before the job step is dispatched to the Mem Driver.
   * To verify the return value of the Mem Driver, the breakpoint can be set after the switch case.
   */

  switch(redirectJobStepInfoPtr->JobStepType)
  {
    case MEMACC_READ_JOB:
    case MEMACC_COMPARE_JOB:
      memJobReturnValue = MemAcc_MemAb_InvokeRead(lowerLayerIndex, memInstanceId, physicalAddress, redirectJobStepDataBufferPtr, length);
      break;
    case MEMACC_WRITE_JOB:
      memJobReturnValue = MemAcc_MemAb_InvokeWrite(lowerLayerIndex, memInstanceId, physicalAddress, redirectJobStepDataBufferPtr, length);
      break;
    case MEMACC_ERASE_JOB:
      memJobReturnValue = MemAcc_MemAb_InvokeErase(lowerLayerIndex, memInstanceId, physicalAddress, length);
      break;
    case MEMACC_BLANKCHECK_JOB:
      memJobReturnValue = MemAcc_MemAb_InvokeBlankCheck(lowerLayerIndex, memInstanceId, physicalAddress, length);
      break;
    case MEMACC_MEMHWSPECIFIC_JOB: /* COV_MemAcc_MultiBinary_MISRA */
    case MEMACC_NO_JOB:            /* COV_MemAcc_MultiBinary_MISRA */
    case MEMACC_REQUESTLOCK_JOB:   /* COV_MemAcc_MultiBinary_MISRA */
    default:                       /* COV_MemAcc_MultiBinary_MISRA */
      break;
  }

  return memJobReturnValue;
}

/**********************************************************************************************************************
 * MemAcc_MultiBinary_HandleNewRedirectRequest()
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
 *   requires redirectJobStepInfoPtr != NULL_PTR;
 *   requires redirectJobStepResultPtr != NULL_PTR;
 *   requires redirectJobStepDataBufferPtr != NULL_PTR;
 * \endspec
 */
MEMACC_LOCAL void MemAcc_MultiBinary_HandleNewRedirectRequest(
  const MemAcc_MultiBinary_IdType binaryId,
  const MemAcc_MultiBinary_RedirectJobStepInfoType* const redirectJobStepInfoPtr,
  MemAcc_MultiBinary_RedirectJobStepResultType* const redirectJobStepResultPtr,
  MemAcc_DataType* const redirectJobStepDataBufferPtr)
{
  if (MemAcc_MultiBinary_IsRedirectJobStepInfoValid(binaryId, redirectJobStepInfoPtr) == TRUE)
  {
    if (MemAcc_MultiBinary_DispatchMultiBinaryJobStepToMem(redirectJobStepInfoPtr, redirectJobStepDataBufferPtr) != E_OK)
    {
#if !defined(MEMACC_VCA_SILENT) /* COV_MEMACC_VCA */
      /* VCA Disable SLC-22, SLC-24 : VCA_MemAcc_MasterRedirectJobPointerAccess */
      redirectJobStepResultPtr->JobStepResult = MEM_JOB_FAILED;
      MemAcc_Callout_DataMemoryBarrier();
      redirectJobStepResultPtr->JobStepResultCounter = redirectJobStepInfoPtr->JobStepRequestCounter;
      /* VCA Enable : VCA_MemAcc_MasterRedirectJobPointerAccess */
#endif
    }
    else
    {
#if !defined(MEMACC_VCA_SILENT) /* COV_MEMACC_VCA */
      /* VCA Disable SLC-22, SLC-24 : VCA_MemAcc_MasterRedirectJobPointerAccess */
      redirectJobStepResultPtr->JobStepResult = MEM_JOB_PENDING;
      /* VCA Enable : VCA_MemAcc_MasterRedirectJobPointerAccess */
#endif
    }
  }
  else
  {
    MemAcc_ErrorCheck_ReportMultiBinaryDetError();
#if !defined(MEMACC_VCA_SILENT) /* COV_MEMACC_VCA */
  /* VCA Disable SLC-22, SLC-24 : VCA_MemAcc_MasterRedirectJobPointerAccess */
    redirectJobStepResultPtr->JobStepResult = MEM_JOB_FAILED;
    MemAcc_Callout_DataMemoryBarrier();
    redirectJobStepResultPtr->JobStepResultCounter = redirectJobStepInfoPtr->JobStepRequestCounter;
  /* VCA Enable : VCA_MemAcc_MasterRedirectJobPointerAccess */
#endif
  }
}

/**********************************************************************************************************************
 * MemAcc_MultiBinary_ProcessActiveRedirectRequest()
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
 *   requires redirectJobStepInfoPtr != NULL_PTR;
 *   requires redirectJobStepResultPtr != NULL_PTR;
 * \endspec
 */
MEMACC_LOCAL void MemAcc_MultiBinary_ProcessActiveRedirectRequest(
  const MemAcc_MultiBinary_RedirectJobStepInfoType* const redirectJobStepInfoPtr,
  MemAcc_MultiBinary_RedirectJobStepResultType* const redirectJobStepResultPtr)
{
  MemAcc_MemJobResultType jobResult = MEM_JOB_FAILED;
  MemAcc_LowerLayerIndexType lowerLayerIndex = MemAcc_MultiBinary_GetLowerLayerIndexOfMemDriverIndex(redirectJobStepInfoPtr->MemDriverIndex);
  /*@ assert lowerLayerIndex < MemAcc_GetSizeOfLowerLayer(); */  /* VCA_MemAcc_MultiBinaryRedirectTableIndex */
  jobResult = MemAcc_MemAb_InvokeGetJobResult(lowerLayerIndex, redirectJobStepInfoPtr->MemInstanceId);
  if (jobResult != MEM_JOB_PENDING)
  {
#if !defined(MEMACC_VCA_SILENT) /* COV_MEMACC_VCA */
  /* VCA Disable SLC-22, SLC-24 : VCA_MemAcc_MasterRedirectJobPointerAccess */
    redirectJobStepResultPtr->JobStepResult = jobResult;
    MemAcc_Callout_DataMemoryBarrier();
    redirectJobStepResultPtr->JobStepResultCounter = redirectJobStepInfoPtr->JobStepRequestCounter;
  /* VCA Enable : VCA_MemAcc_MasterRedirectJobPointerAccess */
#endif
  }
}

#  endif /* MEMACC_MULTIBINARY_HASREDIRECTREQUESTS */
# endif /* MEMACC_MULTIBINARY_ISMASTERBINARY */

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * MemAcc_MultiBinary_IsDirectRequest()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
boolean MemAcc_MultiBinary_IsDirectRequest(void)
{
  return MemAcc_MultiBinary_AccessRequestPtr->PublishedRequestType == (MemAcc_MultiBinary_AtomicPublishedRequestType)MEMACC_MULTIBINARY_DIRECT;
}

/**********************************************************************************************************************
 * MemAcc_MultiBinary_IsRedirectRequest()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
boolean MemAcc_MultiBinary_IsRedirectRequest(void)
{
  return MemAcc_MultiBinary_AccessRequestPtr->PublishedRequestType == (MemAcc_MultiBinary_AtomicPublishedRequestType)MEMACC_MULTIBINARY_REDIRECT;
}

/**********************************************************************************************************************
 * MemAcc_MultiBinary_CanDispatchAccessRequest()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
boolean MemAcc_MultiBinary_CanDispatchAccessRequest(void)
{
  boolean isActiveBinary = MemAcc_MultiBinary_IsActiveBinary();
  boolean isStopFlagSet = MemAcc_MultiBinary_IsStopFlagSet();

  return (isActiveBinary == FALSE) || (isStopFlagSet == FALSE);
}

/**********************************************************************************************************************
 * MemAcc_MultiBinary_DispatchNoAccessRequest()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
void MemAcc_MultiBinary_DispatchNoAccessRequest(void)
{
  MemAcc_MultiBinary_AccessRequestPtr->PublishedRequestType = (MemAcc_MultiBinary_AtomicPublishedRequestType)MEMACC_MULTIBINARY_NO_REQUEST;
}

/**********************************************************************************************************************
 * MemAcc_MultiBinary_IsActiveBinary()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
boolean MemAcc_MultiBinary_IsActiveBinary(void)
{
  return MemAcc_MultiBinary_GetActiveBinary() == MEMACC_MULTIBINARY_BINARY_ID;
}

/**********************************************************************************************************************
 * MemAcc_MultiBinary_DispatchDirectJobStepToSharedMemory()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 * \spec
 *   requires job != NULL_PTR;
 * \endspec
 */
void MemAcc_Callout_DataMemoryBarrier(void)
{
  ;//todo
}
void MemAcc_MultiBinary_DispatchDirectJobStepToSharedMemory(const MemAcc_JobContextType* job)
{
  MemAcc_MultiBinary_AccessRequestPtr->Priority = MemAcc_GetPriorityOfAddressArea(job->JobArea.AddressAreaIndex);

  MemAcc_Callout_DataMemoryBarrier();

  /* It is important to set the published request type property after all other properties */
  MemAcc_MultiBinary_AccessRequestPtr->PublishedRequestType = (MemAcc_MultiBinary_AtomicPublishedRequestType)MEMACC_MULTIBINARY_DIRECT;
}

# if (MEMACC_MULTIBINARY_ISMASTERBINARY == STD_ON)

/**********************************************************************************************************************
 * MemAcc_MultiBinary_UpdateSynchronizationToken()
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
void MemAcc_MultiBinary_UpdateSynchronizationToken(void)
{
  MemAcc_MultiBinary_IdType activeBinaryId = MemAcc_MultiBinary_GetActiveBinary();

  MemAcc_MultiBinary_AccessRequestType const* upcomingRequest = MemAcc_MultiBinary_GetNextJob();
  MemAcc_MultiBinary_IdType nextBinaryId;
  /* No new request at all: BinaryId should stay the same... */
  if(upcomingRequest == NULL_PTR)
  {
    nextBinaryId = activeBinaryId;
  }
  /* ...otherwise: Next binary Id should be the hightest priority job */
  else
  {
    nextBinaryId = upcomingRequest->BinaryId;
  }

  /* If there is a new job with higher priority... */
  if(activeBinaryId != nextBinaryId)
  {
    /*... and the current active binary finished its job step: Set the token to the next binary */
    if(MemAcc_MultiBinary_AccessRequests[activeBinaryId]->PublishedRequestType == (MemAcc_MultiBinary_AtomicPublishedRequestType)MEMACC_MULTIBINARY_NO_REQUEST)
    {
      MemAcc_MultiBinary_SetSynchronizationToken(nextBinaryId, FALSE);
    }
    else
    /*... and the current active binary is still busy: Set the stop flag for this binary */
    {
      if (MemAcc_MultiBinary_IsStopFlagSet() == FALSE)
      {
        MemAcc_MultiBinary_SetSynchronizationToken(activeBinaryId, TRUE);
      }
    }
  }
}

#  if (MEMACC_MULTIBINARY_HASREDIRECTREQUESTS == STD_ON)

/**********************************************************************************************************************
 * MemAcc_MultiBinary_ProcessRedirectRequest()
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
void MemAcc_MultiBinary_ProcessRedirectRequest(void)
{
  MemAcc_MultiBinary_IdType activeId = MemAcc_MultiBinary_GetActiveBinary();

  /*@ assert activeId < MEMACC_MULTIBINARY_NR_Of_BINARIES; */ /* VCA_MemAcc_ActiveIdValidity */
  if (MemAcc_MultiBinary_HasRedirectRequest(MemAcc_MultiBinary_AccessRequests[activeId]) == TRUE)
  {
    const MemAcc_MultiBinary_RedirectJobStepInfoType* const redirectJobStepInfoPtr = MemAcc_MultiBinary_AccessRequests[activeId]->RedirectJobStepInfoPtr;
    MemAcc_MultiBinary_RedirectJobStepResultType* const redirectJobStepResultPtr = MemAcc_MultiBinary_AccessRequests[activeId]->RedirectJobStepResultPtr;
    MemAcc_DataType* const redirectJobStepDataBufferPtr = MemAcc_MultiBinary_AccessRequests[activeId]->RedirectJobStepDataBufferPtr;

    /*@ assert redirectJobStepInfoPtr != NULL_PTR; */ /* VCA_MemAcc_MasterRedirectJobPointerAccess */
    /*@ assert redirectJobStepResultPtr != NULL_PTR; */ /* VCA_MemAcc_MasterRedirectJobPointerAccess */
    /*@ assert redirectJobStepDataBufferPtr != NULL_PTR; */ /* VCA_MemAcc_MasterRedirectJobPointerAccess */

    /* Variable for one counter to not have more then one volatile read access in a single sequence point. */
    MemAcc_MultiBinary_CounterType resultCounter = redirectJobStepResultPtr->JobStepResultCounter;

    /*
     * The counter is not equal if the job has not been processed yet.
     * If the counter are equal the master has already processed this job but the satellite did not process the job result yet.
     */
    if (resultCounter != redirectJobStepInfoPtr->JobStepRequestCounter)
    {
      if (redirectJobStepResultPtr->JobStepResult != MEM_JOB_PENDING)
      {
        MemAcc_MultiBinary_HandleNewRedirectRequest(activeId, redirectJobStepInfoPtr, redirectJobStepResultPtr, redirectJobStepDataBufferPtr);
      }

      if (redirectJobStepResultPtr->JobStepResult == MEM_JOB_PENDING)
      {
        MemAcc_MultiBinary_ProcessActiveRedirectRequest(redirectJobStepInfoPtr, redirectJobStepResultPtr);
      }
    }
  }
}

#  endif /* MEMACC_MULTIBINARY_HASREDIRECTREQUESTS */
# endif /* MEMACC_MULTIBINARY_ISMASTERBINARY */

# if (MEMACC_MULTIBINARY_ISSATELLITEBINARY == STD_ON)
#  if (MEMACC_MULTIBINARY_HASREDIRECTREQUESTS == STD_ON)

/**********************************************************************************************************************
 * MemAcc_MultiBinary_DispatchRedirectJobStepToSharedMemory()
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
 * \spec
 *   requires job != NULL_PTR;
 * \endspec
 */
void MemAcc_MultiBinary_DispatchRedirectJobStepToSharedMemory(const MemAcc_JobContextType* job)
{
  /*@ assert $external(MemAcc_MultiBinary_AccessRequestPtr->RedirectJobStepInfoPtr); */                               /* VCA_MemAcc_SatelliteSharedMemoryPointerAccess */
  /*@ assert $external(MemAcc_MultiBinary_AccessRequestPtr->RedirectJobStepResultPtr); */                             /* VCA_MemAcc_SatelliteSharedMemoryPointerAccess */
  /*@ assert $external(MemAcc_MultiBinary_AccessRequestPtr->RedirectJobStepDataBufferPtr); */                         /* VCA_MemAcc_SatelliteSharedMemoryPointerAccess */

  MemAcc_MultiBinary_AccessRequestType redirectAccessRequest = *MemAcc_MultiBinary_AccessRequestPtr;

  redirectAccessRequest.RedirectJobStepInfoPtr->JobStepType = (MemAcc_JobType)(job->JobArea.JobType); /* PRQA S 4342 */ /* MD_MemAcc_JobTypeEnumCasting */
  redirectAccessRequest.RedirectJobStepInfoPtr->MemDriverIndex =
    MemAcc_GetMemDriverIndexOfLowerLayer(MemAcc_GetLowerLayerIdxOfSubAddressArea(job->MngmtArea.JobStep.SubAddrAreaIdx));
  redirectAccessRequest.RedirectJobStepInfoPtr->MemInstanceId =
    MemAcc_GetInstanceIdOfMemInstance(MemAcc_GetMemInstanceIdxOfSubAddressArea(job->MngmtArea.JobStep.SubAddrAreaIdx));
  redirectAccessRequest.RedirectJobStepInfoPtr->PhysicalAddress = job->MngmtArea.JobStep.PhysicalAddress;
  redirectAccessRequest.RedirectJobStepInfoPtr->Length = job->MngmtArea.JobStep.Length;

  if(redirectAccessRequest.RedirectJobStepInfoPtr->JobStepType == MEMACC_WRITE_JOB)
  {
    VStdLib_MemCpy(                                                                                                   /* VCA_MemAcc_VStdLibMemCpyCalls */
      MemAcc_MultiBinary_AccessRequestPtr->RedirectJobStepDataBufferPtr,
      &(job->JobArea.ConstDataBuffer[job->MngmtArea.Offset]),
      redirectAccessRequest.RedirectJobStepInfoPtr->Length);
  }

  MemAcc_MultiBinary_AccessRequestPtr->Priority = MemAcc_GetPriorityOfAddressArea(job->JobArea.AddressAreaIndex);

  redirectAccessRequest.RedirectJobStepInfoPtr->JobStepRequestCounter = redirectAccessRequest.RedirectJobStepResultPtr->JobStepResultCounter + (MemAcc_MultiBinary_CounterType) 1u;

  MemAcc_Callout_DataMemoryBarrier();

  /* It is important to set the published request type property after all other properties */
  MemAcc_MultiBinary_AccessRequestPtr->PublishedRequestType = (MemAcc_MultiBinary_AtomicPublishedRequestType)MEMACC_MULTIBINARY_REDIRECT;
}

/**********************************************************************************************************************
 * MemAcc_MultiBinary_GetRedirectJobStepResultAndUpdateJobContext()
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
 * \spec
 *   requires job != NULL_PTR;
 * \endspec
 */
MemAcc_MemJobResultType MemAcc_MultiBinary_GetRedirectJobStepResultAndUpdateJobContext(
  const MemAcc_JobContextType* job,
  const MemAcc_LengthType      srcBufferOffset)
{
  /*@ assert $external(MemAcc_MultiBinary_AccessRequestPtr->RedirectJobStepInfoPtr); */                                 /* VCA_MemAcc_SatelliteSharedMemoryPointerAccess */
  /*@ assert $external(MemAcc_MultiBinary_AccessRequestPtr->RedirectJobStepResultPtr); */                               /* VCA_MemAcc_SatelliteSharedMemoryPointerAccess */
  /*@ assert $external(MemAcc_MultiBinary_AccessRequestPtr->RedirectJobStepDataBufferPtr); */                           /* VCA_MemAcc_SatelliteSharedMemoryPointerAccess */

  MemAcc_MemJobResultType jobResult = MEM_JOB_PENDING;
  MemAcc_MultiBinary_AccessRequestType redirectAccessRequest = *MemAcc_MultiBinary_AccessRequestPtr;

  /* Variable for one counter to not have more then one volatile read access in a single sequence point. */
  MemAcc_MultiBinary_CounterType resultCounter = redirectAccessRequest.RedirectJobStepResultPtr->JobStepResultCounter;

  if(redirectAccessRequest.RedirectJobStepInfoPtr->JobStepRequestCounter == resultCounter)
  {
    /* If counter are equal, the job has finished. In case something was read from the memory copy it to the JobArea.DataBuffer.*/
    if((redirectAccessRequest.RedirectJobStepInfoPtr->JobStepType == MEMACC_READ_JOB) ||
      (redirectAccessRequest.RedirectJobStepInfoPtr->JobStepType == MEMACC_COMPARE_JOB))
    {
      VStdLib_MemCpy(&(job->JobArea.DataBuffer[job->MngmtArea.Offset]),                       /* VCA_MemAcc_VStdLibMemCpyCalls */
        &(redirectAccessRequest.RedirectJobStepDataBufferPtr[srcBufferOffset]),
        job->MngmtArea.JobStep.Length);
    }

    jobResult = redirectAccessRequest.RedirectJobStepResultPtr->JobStepResult;
  }

  return jobResult;
}

#  endif /* MEMACC_MULTIBINARY_HASREDIRECTREQUESTS */
# endif /* MEMACC_MULTIBINARY_ISSATELLITEBINARY */
#endif /* MEMACC_MULTIBINARY_ISMULTIBINARYUSECASE */

#define MEMACC_STOP_SEC_CODE
#include "MemAcc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  VCA JUSTIFICATIONS
 **********************************************************************************************************************/
/* VCA_JUSTIFICATION_BEGIN

\ID VCA_MemAcc_SatelliteSharedMemoryPointerAccess
  \DESCRIPTION The MemAcc_MultiBinary_AccessRequest and the struct members RedirectJobStepInfo,
               RedirectJobStepResult and RedirectJobStepDataBuffer are located in shared memory.
               The data is generated by the master configuration and will be accessed over MemAcc_MultiBinary_AccessRequestPtr.
               MemAcc_MultiBinary_AccessRequestPtr itself equals the value of the symbol MemAcc_MultiBinary_AccessRequestSatellite_Id[X]
               provided and set by the integrator.

  \COUNTERMEASURE \S It must be ensured that all satellites refer to the correct structure within shared memory provided by the master.
                     MemAcc_MultiBinary_AccessRequestSatellite_Id[X] must be therefore set by the integrator holding the
                     correct address.
                     Satellites redirecting requests to the master needs also the members RedirectJobStepInfoPtr, RedirectJobStepResultPtr
                     and RedirectJobStepDataBufferPtr to be not NULL_PTR, but to be valid references to existing structures.
                     See SMI_MemAcc-SharedMemoryReferences.

\ID VCA_MemAcc_VStdLibMemCpyCalls
  \DESCRIPTION The external function VStdLib_MemCpy is used by satellites to copy data from one buffer to another.
               It has to be ensured that the destination buffer is large enough to hold the provided data.
               In case it copies data into the user buffer for a read job:
                 The provided user buffer needs to be big enough for the whole requested job.
               In case it copies data into the shared memory buffer for a write job:
                 The provided data buffer by the master needs to be big enough for the maximum satellite write job step size.

  \COUNTERMEASURE \S It must be ensured by the user that provided buffer for read requests are large enough according to the forwarded length.
                     This applies especially if application is using directly the MemAcc. See SMI-MemAcc-UserBuffer.
                  \T It must be ensured that the expected shared memory buffer size provided by the master
                     is big enough for the job steps which can be requested by the satellites.
                     This means the maximum satellite write job step size (satellite writes into shared memory)
                     as well as maximum satellite read job step size (master writes into shared memory, actually done by the mem driver below)
                     needs to be considered. TCASE-CheckRedirectJobSharedMemoryBufferSize.
                  \S Furthermore, it must be ensured that the actual shared memory buffer size provided by the master
                     is the same as the expected shared memory buffer size used by the satellites. See SMI-MemAcc-SharedMemoryBuffer.

\ID VCA_MemAcc_MultiBinaryRedirectTableIndex
  \DESCRIPTION The TableIndex will be derived from the MemDriverIndex provided by the redirect job filled by the satellite.
               The MemDriverIndex must therefore be correct, to have a valid access to the generated LowerLayer structure at the master side.

  \COUNTERMEASURE \R Validity of MemDriverIndex will be ensured within MemAcc_MultiBinary_IsRedirectJobStepInfoValid()
                     before a redirect job is actually handled.

\ID VCA_MemAcc_MasterRedirectJobPointerAccess
  \DESCRIPTION For processing a redirect job the master will access structures containing JobStepInfo, JobStepResult and JobStepDataBuffer.
               They will be provided over pointer within the access request structures of the satellites which are capable of forwarding redirect jobs.
               The pointer must correctly refer valid structures.
               The pointer needs only be set if satellites are using redirect job. VCA can currently not cope with this variation.
               Therefore, some code parts, where write accesses at this pointer references are done, are disabled during VCA analysis.

  \COUNTERMEASURE \S If a satellite has redirect requests configured (can be checked if SatelliteId within generated MemAcc_RedirectSectorBatch is mentioned)
                     the referenced AccessRequests structure for this satellite must have valid references to JobStepInfo, JobStepResult and JobStepDataBuffer
                     structures exclusively provided for this satellite. See SMI_MemAcc-SharedMemoryReferences.

\ID VCA_MemAcc_ActiveIdValidity
  \DESCRIPTION The activeId will be retrieved by the Token in Shared Memory. The token will only be written by the master
               by following a specific routine implemented in MemAcc_MultiBinary_UpdateSynchronizationToken().
               The routine specifies that the activeId from the token will be always updated with the const BinaryId value
               of the highest priority request job.

  \COUNTERMEASURE \R The highest priority request job will be determined within MemAcc_MultiBinary_GetNextJob() where only valid
                     AccessRequest will be considered.
                  \S The BinaryId of all AccessRequest structures must be smaller than MEMACC_MULTIBINARY_NR_Of_BINARIES. See SMI_MemAcc-SharedMemoryReferences.

VCA_JUSTIFICATION_END */

/***********************************************************************************************************************
 *  COV JUSTIFICATION
 **********************************************************************************************************************/
/* COV_JUSTIFICATION_BEGIN

\ID COV_MemAcc_MultiBinary_MISRA
\ACCEPT XX
\REASON [COV_MSR_MISRA]

\ID COV_MEMACC_VCA
\ACCEPT TX
\ACCEPT XF
\REASON VCA needs additional functions to analyze to code in a meaningful way. Therefore, this code part is not enabled when using VCA.

COV_JUSTIFICATION_END */

/**********************************************************************************************************************
 *  END OF FILE: MemAcc_MultiBinary.c
 *********************************************************************************************************************/
