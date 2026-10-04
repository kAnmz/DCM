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
/*!        \file  MemAcc_MemAb.h
 *        \brief  MemAcc_MemAb header file
 *      \details  -
 *         \unit  MemAb
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#if !defined (MEMACC_MEMAB_H)
# define MEMACC_MEMAB_H

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
 * MemAcc_MemAb_Init
 *********************************************************************************************************************/
/*! \brief       Initializes all Mems depending on configured Mem Invocation.
 *  \details     -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
void MemAcc_MemAb_Init(void);

/**********************************************************************************************************************
 * MemAcc_MemAb_DeInit
 *********************************************************************************************************************/
/*! \brief       Deinitializes all Mems depending on configured Mem Invocation.
 *  \details     -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
void MemAcc_MemAb_DeInit(void);

/**********************************************************************************************************************
 * MemAcc_MemAb_InvokeInit
 *********************************************************************************************************************/
/*! \brief       Initialize a Mem depending on configured Mem Invocation.
 *  \details     -
 *  \param[in]   lowerLayerIndex Index of Mem in LowerLayerTable.
 *  \param[in]   configPtr ID of the related memory driver instance.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
void MemAcc_MemAb_InvokeInit(
  const MemAcc_LowerLayerIndexType lowerLayerIndex,
  const MemAcc_MemConfigType* configPtr);

/**********************************************************************************************************************
 * MemAcc_MemAb_InvokeDeInit
 *********************************************************************************************************************/
/*! \brief       Deinitialize a Mem depending on configured Mem Invocation.
 *  \details     -
 *  \param[in]   lowerLayerIndex Index of Mem in LowerLayerTable.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
void MemAcc_MemAb_InvokeDeInit(const MemAcc_LowerLayerIndexType lowerLayerIndex);

/**********************************************************************************************************************
 * MemAcc_MemAb_InvokeRead
 *********************************************************************************************************************/
/*! \brief       Invoke a Read job depending on configured Mem Invocation.
 *  \details     -
 *  \param[in]   lowerLayerIndex Index of Mem in LowerLayerTable.
 *  \param[in]   memInstanceId ID of the related memory driver instance.
 *  \param[in]   sourceAddress Physical address to read data from.
 *  \param[out]  destinationDataPtr Destination memory pointer to store the read data.
 *  \param[in]   length Read length in bytes.
 *  \return      E_OK if the invocation has been accepted, otherwise
 *               E_NOT_OK.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
Std_ReturnType MemAcc_MemAb_InvokeRead(
  const MemAcc_LowerLayerIndexType lowerLayerIndex,
  const MemAcc_MemInstanceIdType memInstanceId,
  const MemAcc_AddressType sourceAddress,
  MemAcc_DataType* destinationDataPtr,
  const MemAcc_LengthType length);

/**********************************************************************************************************************
 * MemAcc_MemAb_InvokeWrite
 *********************************************************************************************************************/
/*! \brief       Invoke a Write job depending on configured Mem Invocation.
 *  \details     -
 *  \param[in]   lowerLayerIndex Index of Mem in LowerLayerTable.
 *  \param[in]   memInstanceId ID of the related memory driver instance.
 *  \param[in]   targetAddress Physical address to write data at.
 *  \param[in]   sourceDataPtr Source data pointer.
 *  \param[in]   length Write length in bytes.
 *  \return      E_OK if the invocation has been accepted, otherwise
 *               E_NOT_OK.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
Std_ReturnType MemAcc_MemAb_InvokeWrite(
  const MemAcc_LowerLayerIndexType lowerLayerIndex,
  const MemAcc_MemInstanceIdType memInstanceId,
  const MemAcc_AddressType targetAddress,
  const MemAcc_DataType* sourceDataPtr,
  const MemAcc_LengthType length);

/**********************************************************************************************************************
 * MemAcc_MemAb_InvokeErase
 *********************************************************************************************************************/
/*! \brief       Invoke an Erase job depending on configured Mem Invocation.
 *  \details     -
 *  \param[in]   lowerLayerIndex Index of Mem in LowerLayerTable.
 *  \param[in]   memInstanceId ID of the related memory driver instance.
 *  \param[in]   targetAddress Physical erase address.
 *  \param[in]   length Erase length in bytes.
 *  \return      E_OK if the invocation has been accepted, otherwise
 *               E_NOT_OK.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
Std_ReturnType MemAcc_MemAb_InvokeErase(
  const MemAcc_LowerLayerIndexType lowerLayerIndex,
  const MemAcc_MemInstanceIdType memInstanceId,
  const MemAcc_AddressType targetAddress,
  const MemAcc_LengthType length);

/**********************************************************************************************************************
 * MemAcc_MemAb_InvokeBlankCheck
 *********************************************************************************************************************/
/*! \brief       Invoke a BlankCheck job depending on configured Mem Invocation.
 *  \details     -
 *  \param[in]   lowerLayerIndex Index of Mem in LowerLayerTable.
 *  \param[in]   memInstanceId ID of the related memory driver instance.
 *  \param[in]   targetAddress Physical blank check address.
 *  \param[in]   length Blank check length in bytes.
 *  \return      E_OK if the invocation has been accepted, otherwise
 *               E_NOT_OK.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
Std_ReturnType MemAcc_MemAb_InvokeBlankCheck(
  const MemAcc_LowerLayerIndexType lowerLayerIndex,
  const MemAcc_MemInstanceIdType memInstanceId,
  const MemAcc_AddressType targetAddress,
  const MemAcc_LengthType length);

/**********************************************************************************************************************
 * MemAcc_MemAb_InvokeHwSpecificService
 *********************************************************************************************************************/
/*! \brief          Invoke Hw Specific Service depending on configured Mem Invocation.
 *  \details        -
 *  \param[in]      lowerLayerIndex Index of Mem in LowerLayerTable.
 *  \param[in]      memInstanceId ID of the related memory driver instance.
 *  \param[in]      hwServiceId Hardware specific service request identifier for dispatching the request.
 *  \param[in,out]  dataPtr Request specific data pointer.
 *  \param[in]      lengthPtr Size pointer of the passed data.
 *  \return         E_OK if the invocation has been accepted, otherwise
 *                  E_NOT_OK.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
Std_ReturnType MemAcc_MemAb_InvokeHwSpecificService(
  const MemAcc_LowerLayerIndexType lowerLayerIndex,
  const MemAcc_MemInstanceIdType memInstanceId,
  const MemAcc_MemHwServiceIdType hwServiceId,
  MemAcc_DataType* dataPtr,
  MemAcc_LengthType* lengthPtr);

/**********************************************************************************************************************
 * MemAcc_MemAb_InvokeGetJobResult
 *********************************************************************************************************************/
/*! \brief          Invoke GetJobResult Service depending on configured Mem Invocation.
 *  \details        -
 *  \param[in]      lowerLayerIndex Index of Mem in LowerLayerTable.
 *  \param[in]      memInstanceId Memory driver instance ID type.
 *  \return         MEM_JOB_OK          The last job has been finished successfully
 *                  MEM_JOB_PENDING     A job is currently being processed
 *                  MEM_JOB_FAILED      Job failed for some unspecific reason
 *                  MEM_INCONSISTENT    The checked page is not blank
 *                  MEM_ECC_UNCORRECTED Uncorrectable ECC errors occurred during memory access
 *                  MEM_ECC_CORRECTED   Correctable ECC errors occurred during memory access
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
MemAcc_MemJobResultType MemAcc_MemAb_InvokeGetJobResult(
  const MemAcc_LowerLayerIndexType lowerLayerIndex,
  const MemAcc_MemInstanceIdType memInstanceId);

#if (MEMACC_BBM_ENABLED == STD_ON)

/**********************************************************************************************************************
 * MemAcc_MemAb_InvokeReadErrorState
 *********************************************************************************************************************/
/*! \brief          Reads the current Mem error state into the data pointer.
 *  \details        -
 *  \param[in]      lowerLayerIndex Index of Mem in LowerLayerTable.
 *  \param[in]      memInstanceId ID of the related memory driver instance.
 *  \param[in,out]  data Request specific data pointer.
 *  \return         E_OK if the invocation has been accepted, otherwise
 *                  E_NOT_OK.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
Std_ReturnType MemAcc_MemAb_InvokeReadErrorState(
  const MemAcc_LowerLayerIndexType lowerLayerIndex,
  const MemAcc_MemInstanceIdType memInstanceId,
  MemAcc_MemLastErrorJobDataType* data);

#endif /* (MEMACC_BBM_ENABLED == STD_ON) */

/**********************************************************************************************************************
 * MemAcc_MemAb_InvokeMainFunction
 *********************************************************************************************************************/
/*! \brief          Invokes the Mem Main Function in case it is not configured as DIRECT.
 *  \details        -
 *  \param[in]      lowerLayerIndex Index of Mem in LowerLayerTable.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
void MemAcc_MemAb_InvokeMainFunction(const MemAcc_LowerLayerIndexType lowerLayerIndex);

#if (MEMACC_SUSPENDRESUME_ENABLED == STD_ON)

/**********************************************************************************************************************
 * MemAcc_MemAb_InvokeSuspend
 *********************************************************************************************************************/
/*! \brief       Invoke a Suspend job depending on configured Mem Invocation.
 *  \details     -
 *  \param[in]   lowerLayerIndex Index of Mem in LowerLayerTable.
 *  \param[in]   memInstanceId Instance ID of the MemInstance to suspend
 *  \return      E_OK if the invocation has been accepted
 *               E_NOT_OK if the invocation has not been accepted
 *               E_MEM_SERVICE_NOT_AVAIL if the service is not supported by the Mem
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
Std_ReturnType MemAcc_MemAb_InvokeSuspend(
  const MemAcc_LowerLayerIndexType lowerLayerIndex,
  const MemAcc_MemInstanceIdType memInstanceId);

/**********************************************************************************************************************
 * MemAcc_MemAb_InvokeResume
 *********************************************************************************************************************/
/*! \brief       Invoke a Resume job depending on configured Mem Invocation.
 *  \details     -
 *  \param[in]   lowerLayerIndex Index of Mem in LowerLayerTable.
 *  \param[in]   memInstanceId Instance ID of the MemInstance to resume
 *  \return      E_OK if the invocation has been accepted
 *               E_NOT_OK if the invocation has not been accepted
 *               E_MEM_SERVICE_NOT_AVAIL if the service is not supported by the Mem
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
Std_ReturnType MemAcc_MemAb_InvokeResume(
  const MemAcc_LowerLayerIndexType lowerLayerIndex,
  const MemAcc_MemInstanceIdType memInstanceId);

#endif /* (MEMACC_SUSPENDRESUME_ENABLED == STD_ON) */

#define MEMACC_STOP_SEC_CODE
#include "MemAcc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* MEMACC_MEMAB_H */

/**********************************************************************************************************************
 *  END OF FILE: MemAcc_MemAb.h
 *********************************************************************************************************************/
