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
/*!        \file  MemAcc_MemAb.c
 *        \brief  MemAcc_MemAb source file
 *      \details  -
 *         \unit  MemAb
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#define MEMACC_MEMAB_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "MemAcc_MemAb.h"

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/
#if !defined (MEMACC_LOCAL)
# define MEMACC_LOCAL                                                    static
#endif

#if !defined (MEMACC_LOCAL_INLINE)
# define MEMACC_LOCAL_INLINE                                             LOCAL_INLINE
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
# define MEMACC_START_SEC_CODE
# include "MemAcc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * MemAcc_MemAb_GetMemBinaryHeader()
 *********************************************************************************************************************/
/*! \brief       Returns the MemBinaryHeader for the given lower layer index.
 *  \details     Returns the static MemBinaryHeader. If it is NULL_PTR, the indirect dynamic header is returned instead.
 *  \param[in]   lowerLayerIndex - Index of the lower layer entry.
 *  \return      Pointer to the MemBinaryHeader, or NULL_PTR if neither static nor dynamic header is available.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
MEMACC_LOCAL_INLINE const MemAcc_MemBinaryHeaderType* MemAcc_MemAb_GetMemBinaryHeader(
  const MemAcc_LowerLayerIndexType lowerLayerIndex);

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * MemAcc_MemAb_GetMemBinaryHeader()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
MEMACC_LOCAL_INLINE const MemAcc_MemBinaryHeaderType* MemAcc_MemAb_GetMemBinaryHeader(
  const MemAcc_LowerLayerIndexType lowerLayerIndex)
{
  /*!
   * INDIRECT_STATIC: The MemBinaryHeader is provided by the Mem Driver.
   * DIRECT_STATIC: The MemBinaryHeader is generated in the Lcfg and links all relevant function pointers
   * of the Mem Driver.
   * INDIRECT_DYNAMIC: The MemBinaryHeader is provided by the User on demand via MemAcc_ActivateMem.
   *
   * If StaticMemBinaryHeader is NULL_PTR, the LowerLayer entry is therefore INDIRECT_DYNAMIC.
   */
  const MemAcc_MemBinaryHeaderType* memBinaryHeader = MemAcc_GetStaticMemBinaryHeaderOfLowerLayer(lowerLayerIndex);

  if (memBinaryHeader == NULL_PTR)
  {
    memBinaryHeader = MemAcc_GetIndirectDynamicMemBinaryHeaderOfLowerLayer(lowerLayerIndex);
  }

  return memBinaryHeader;
}

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * MemAcc_MemAb_Init()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
void MemAcc_MemAb_Init(void)
{
  for (MemAcc_LowerLayerIndexType llIdx = 0; llIdx < MemAcc_GetSizeOfLowerLayer(); llIdx++)
  {
    MemAcc_MemAb_InvokeInit(llIdx, NULL_PTR);
  }
}

/**********************************************************************************************************************
 * MemAcc_MemAb_DeInit()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
void MemAcc_MemAb_DeInit(void)
{
  for (MemAcc_LowerLayerIndexType llIdx = 0; llIdx < MemAcc_GetSizeOfLowerLayer(); llIdx++)
  {
    MemAcc_MemAb_InvokeDeInit(llIdx);
  }
}

/**********************************************************************************************************************
 * MemAcc_MemAb_InvokeInit()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
void MemAcc_MemAb_InvokeInit(
  const MemAcc_LowerLayerIndexType lowerLayerIndex,
  const MemAcc_MemConfigType* configPtr)
{
  const MemAcc_MemBinaryHeaderType* binaryHeader = MemAcc_MemAb_GetMemBinaryHeader(lowerLayerIndex);

  if ((binaryHeader != NULL_PTR) && (binaryHeader->InitFunc != NULL_PTR))
  {
#if !defined(MEMACC_VCA_SILENT) /* COV_MEMACC_VCA */
    /* VCA Disable SLC-10, SLC-22 : VCA_MemAcc_MemDrvServiceInvocation */
    binaryHeader->InitFunc(configPtr);
    /* VCA Enable : VCA_MemAcc_MemDrvServiceInvocation */
#endif
  }
}

/**********************************************************************************************************************
 * MemAcc_MemAb_InvokeDeInit()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
void MemAcc_MemAb_InvokeDeInit(const MemAcc_LowerLayerIndexType lowerLayerIndex)
{
  const MemAcc_MemBinaryHeaderType* binaryHeader = MemAcc_MemAb_GetMemBinaryHeader(lowerLayerIndex);

  if ((binaryHeader != NULL_PTR) && (binaryHeader->DeinitFunc != NULL_PTR))
  {
#if !defined(MEMACC_VCA_SILENT) /* COV_MEMACC_VCA */
    /* VCA Disable SLC-10, SLC-22 : VCA_MemAcc_MemDrvServiceInvocation */
    binaryHeader->DeinitFunc();
    /* VCA Enable : VCA_MemAcc_MemDrvServiceInvocation */
#endif
  }
}

/**********************************************************************************************************************
 * MemAcc_MemAb_InvokeRead()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
Std_ReturnType MemAcc_MemAb_InvokeRead(
  const MemAcc_LowerLayerIndexType lowerLayerIndex,
  const MemAcc_MemInstanceIdType memInstanceId,
  const MemAcc_AddressType sourceAddress,
  MemAcc_DataType* destinationDataPtr,
  const MemAcc_LengthType length)
{
  Std_ReturnType memJobReturnValue = E_NOT_OK;
  const MemAcc_MemBinaryHeaderType* binaryHeader = MemAcc_MemAb_GetMemBinaryHeader(lowerLayerIndex);

  if ((binaryHeader != NULL_PTR) && (binaryHeader->ReadFunc != NULL_PTR))
  {
#if !defined(MEMACC_VCA_SILENT) /* COV_MEMACC_VCA */
    /* VCA Disable SLC-10, SLC-22 : VCA_MemAcc_MemDrvServiceInvocation */
    memJobReturnValue = binaryHeader->ReadFunc(memInstanceId, sourceAddress, destinationDataPtr, length);
    /* VCA Enable : VCA_MemAcc_MemDrvServiceInvocation */
#endif
  }

  return memJobReturnValue;
}

/**********************************************************************************************************************
 * MemAcc_MemAb_InvokeWrite()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
Std_ReturnType MemAcc_MemAb_InvokeWrite(
  const MemAcc_LowerLayerIndexType lowerLayerIndex,
  const MemAcc_MemInstanceIdType memInstanceId,
  const MemAcc_AddressType targetAddress,
  const MemAcc_DataType* sourceDataPtr,
  const MemAcc_LengthType length)
{
  Std_ReturnType memJobReturnValue = E_NOT_OK;
  const MemAcc_MemBinaryHeaderType* binaryHeader = MemAcc_MemAb_GetMemBinaryHeader(lowerLayerIndex);

  if ((binaryHeader != NULL_PTR) && (binaryHeader->WriteFunc != NULL_PTR))
  {
#if !defined(MEMACC_VCA_SILENT) /* COV_MEMACC_VCA */
    /* VCA Disable SLC-10, SLC-22 : VCA_MemAcc_MemDrvServiceInvocation */
    memJobReturnValue = binaryHeader->WriteFunc(memInstanceId, targetAddress, sourceDataPtr, length);
    /* VCA Enable : VCA_MemAcc_MemDrvServiceInvocation */
#endif
  }

  return memJobReturnValue;
}

/**********************************************************************************************************************
 * MemAcc_MemAb_InvokeErase()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
Std_ReturnType MemAcc_MemAb_InvokeErase(
  const MemAcc_LowerLayerIndexType lowerLayerIndex,
  const MemAcc_MemInstanceIdType memInstanceId,
  const MemAcc_AddressType targetAddress,
  const MemAcc_LengthType length)
{
  Std_ReturnType memJobReturnValue = E_NOT_OK;
  const MemAcc_MemBinaryHeaderType* binaryHeader = MemAcc_MemAb_GetMemBinaryHeader(lowerLayerIndex);

  if ((binaryHeader != NULL_PTR) && (binaryHeader->EraseFunc != NULL_PTR))
  {
#if !defined(MEMACC_VCA_SILENT) /* COV_MEMACC_VCA */
    /* VCA Disable SLC-10, SLC-22 : VCA_MemAcc_MemDrvServiceInvocation */
    memJobReturnValue = binaryHeader->EraseFunc(memInstanceId, targetAddress, length);
    /* VCA Enable : VCA_MemAcc_MemDrvServiceInvocation */
#endif
  }

  return memJobReturnValue;
}

/**********************************************************************************************************************
 * MemAcc_MemAb_InvokeBlankCheck()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
Std_ReturnType MemAcc_MemAb_InvokeBlankCheck(
  const MemAcc_LowerLayerIndexType lowerLayerIndex,
  const MemAcc_MemInstanceIdType memInstanceId,
  const MemAcc_AddressType targetAddress,
  const MemAcc_LengthType length)
{
  Std_ReturnType memJobReturnValue = E_NOT_OK;
  const MemAcc_MemBinaryHeaderType* binaryHeader = MemAcc_MemAb_GetMemBinaryHeader(lowerLayerIndex);

  if ((binaryHeader != NULL_PTR) && (binaryHeader->BlankCheckFunc != NULL_PTR))
  {
#if !defined(MEMACC_VCA_SILENT) /* COV_MEMACC_VCA */
    /* VCA Disable SLC-10, SLC-22 : VCA_MemAcc_MemDrvServiceInvocation */
    memJobReturnValue = binaryHeader->BlankCheckFunc(memInstanceId, targetAddress, length);
    /* VCA Enable : VCA_MemAcc_MemDrvServiceInvocation */
#endif
  }

  return memJobReturnValue;
}

/**********************************************************************************************************************
 * MemAcc_MemAb_InvokeHwSpecificService()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
Std_ReturnType MemAcc_MemAb_InvokeHwSpecificService(
  const MemAcc_LowerLayerIndexType lowerLayerIndex,
  const MemAcc_MemInstanceIdType memInstanceId,
  const MemAcc_MemHwServiceIdType hwServiceId,
  MemAcc_DataType* dataPtr,
  MemAcc_LengthType* lengthPtr)
{
  Std_ReturnType memJobReturnValue = E_NOT_OK;
  const MemAcc_MemBinaryHeaderType* binaryHeader = MemAcc_MemAb_GetMemBinaryHeader(lowerLayerIndex);

  if ((binaryHeader != NULL_PTR) && (binaryHeader->HwSpecificServiceFunc != NULL_PTR))
  {
#if !defined(MEMACC_VCA_SILENT) /* COV_MEMACC_VCA */
    /* VCA Disable SLC-10, SLC-22 : VCA_MemAcc_MemDrvServiceInvocation */
    memJobReturnValue = binaryHeader->HwSpecificServiceFunc(memInstanceId, hwServiceId, dataPtr, lengthPtr);
    /* VCA Enable : VCA_MemAcc_MemDrvServiceInvocation */
#endif
  }

  return memJobReturnValue;
}

/**********************************************************************************************************************
 * MemAcc_MemAb_InvokeGetJobResult()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
MemAcc_MemJobResultType MemAcc_MemAb_InvokeGetJobResult(
  const MemAcc_LowerLayerIndexType lowerLayerIndex,
  const MemAcc_MemInstanceIdType memInstanceId)
{
  MemAcc_MemJobResultType memJobReturnValue = MEM_JOB_FAILED;
  const MemAcc_MemBinaryHeaderType* binaryHeader = MemAcc_MemAb_GetMemBinaryHeader(lowerLayerIndex);

  if ((binaryHeader != NULL_PTR) && (binaryHeader->GetJobResultFunc != NULL_PTR))
  {
#if !defined(MEMACC_VCA_SILENT) /* COV_MEMACC_VCA */
    /* VCA Disable SLC-10, SLC-22 : VCA_MemAcc_MemDrvServiceInvocation */
    memJobReturnValue = binaryHeader->GetJobResultFunc(memInstanceId);
    /* VCA Enable : VCA_MemAcc_MemDrvServiceInvocation */
#endif
  }

  return memJobReturnValue;
}

#if (MEMACC_BBM_ENABLED == STD_ON)

/**********************************************************************************************************************
 * MemAcc_MemAb_InvokeReadErrorState()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 * \spec
 *   requires data != NULL_PTR;
 * \endspec
 */
Std_ReturnType MemAcc_MemAb_InvokeReadErrorState(
  const MemAcc_LowerLayerIndexType lowerLayerIndex,
  const MemAcc_MemInstanceIdType memInstanceId,
  MemAcc_MemLastErrorJobDataType* data)
{
  MemAcc_LengthType length = sizeof(MemAcc_MemLastErrorJobDataType);

  data->LastErrorSectorAddress = 0u;
  data->LastErrorType = MEMACC_MEMERRORTYPE_NONE;

  return MemAcc_MemAb_InvokeHwSpecificService(
    lowerLayerIndex,
    memInstanceId,
    MEMACC_MEMHWSID_GETLASTERROR,
    (MemAcc_DataType*)data,
    &length);
}

#endif /* (MEMACC_BBM_ENABLED == STD_ON) */

/**********************************************************************************************************************
 * MemAcc_MemAb_InvokeMainFunction()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
void MemAcc_MemAb_InvokeMainFunction(const MemAcc_LowerLayerIndexType lowerLayerIndex)
{
  const MemAcc_MemBinaryHeaderType* binaryHeader = MemAcc_MemAb_GetMemBinaryHeader(lowerLayerIndex);

  if ((binaryHeader != NULL_PTR) && (binaryHeader->MainFunc != NULL_PTR))
  {
#if !defined(MEMACC_VCA_SILENT) /* COV_MEMACC_VCA */
    /* VCA Disable SLC-10, SLC-22 : VCA_MemAcc_MemDrvServiceInvocation */
    binaryHeader->MainFunc();
    /* VCA Enable : VCA_MemAcc_MemDrvServiceInvocation */
#endif
  }
}

#if (MEMACC_SUSPENDRESUME_ENABLED == STD_ON)

/**********************************************************************************************************************
 * MemAcc_MemAb_InvokeSuspend()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
Std_ReturnType MemAcc_MemAb_InvokeSuspend(
  const MemAcc_LowerLayerIndexType lowerLayerIndex,
  const MemAcc_MemInstanceIdType memInstanceId)
{
  Std_ReturnType memJobReturnValue = E_NOT_OK;
  const MemAcc_MemBinaryHeaderType* binaryHeader = MemAcc_MemAb_GetMemBinaryHeader(lowerLayerIndex);

  if ((binaryHeader != NULL_PTR) && (binaryHeader->SuspendFunc != NULL_PTR))
  {
#if !defined(MEMACC_VCA_SILENT) /* COV_MEMACC_VCA */
    /* VCA Disable SLC-10, SLC-22 : VCA_MemAcc_MemDrvServiceInvocation */
    memJobReturnValue = binaryHeader->SuspendFunc(memInstanceId);
    /* VCA Enable : VCA_MemAcc_MemDrvServiceInvocation */
#endif
  }

  return memJobReturnValue;
}

/**********************************************************************************************************************
 * MemAcc_MemAb_InvokeResume()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
Std_ReturnType MemAcc_MemAb_InvokeResume(
  const MemAcc_LowerLayerIndexType lowerLayerIndex,
  const MemAcc_MemInstanceIdType memInstanceId)
{
  Std_ReturnType memJobReturnValue = E_NOT_OK;
  const MemAcc_MemBinaryHeaderType* binaryHeader = MemAcc_MemAb_GetMemBinaryHeader(lowerLayerIndex);

  if ((binaryHeader != NULL_PTR) && (binaryHeader->ResumeFunc != NULL_PTR))
  {
#if !defined(MEMACC_VCA_SILENT) /* COV_MEMACC_VCA */
    /* VCA Disable SLC-10, SLC-22 : VCA_MemAcc_MemDrvServiceInvocation */
    memJobReturnValue = binaryHeader->ResumeFunc(memInstanceId);
    /* VCA Enable : VCA_MemAcc_MemDrvServiceInvocation */
#endif
  }

  return memJobReturnValue;
}

#endif /* (MEMACC_SUSPENDRESUME_ENABLED == STD_ON) */

#define MEMACC_STOP_SEC_CODE
#include "MemAcc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  VCA JUSTIFICATIONS
 **********************************************************************************************************************/
/* VCA_JUSTIFICATION_BEGIN

\ID VCA_MemAcc_MemDrvServiceInvocation
  \DESCRIPTION The Mem Driver public services are invoked via a MemBinaryHeader function pointer table.
               Each MemAcc_CLowerLayer entry holds a static reference to a MemBinaryHeader (ROM constant for
               both DIRECT_STATIC and INDIRECT_STATIC drivers). For INDIRECT_DYNAMIC entries the
               static reference is NULL_PTR and the header is resolved at runtime from MemAcc_VLowerLayer.
               In all cases valid functions must be referenced. As for read, write and hardware specific services also
               pointer parameters are forwarded their validity must be ensured by MemAcc.
               It has to be ensured that the provided buffer and the provided length fit together (especially for read use cases).
               The function pointer table is not defined within the analyzed sources (included via extern), so VCA is unable to determine the actual behavior
               of the functions. Therefore, some code parts where the Mem Driver Services are invoked via function pointer table
               are disabled during VCA analysis.

  \COUNTERMEASURE \R Reference of MemAcc_LowerLayer is retrieved by array access over the lowerLayerIndex index.
                     The lowerLayerIndex is calculated within the job processing unit over the
                     LowerLayerIdxOfSubAddressArea parameter.
                     The Validity of LowerLayerIdxOfSubAddressArea parameter within generated SubAddressArea structure is
                     ensured by ComStackLib (1:1 relation between MemAcc_SubAddressArea and MemAcc_LowerLayer).
                     The selection of a valid SubAddressArea itself is ensured via a runtime check within
                     the job processing unit.
                  \T Wrong function pointer table would be detected immediately within integration test
                     as the connection to the underlying Mem driver is basic integration.
                     Validity of forwarded const pointer are ensured by compiler.
                     Validity of forwarded var pointer are ensured by review: Pointer type corresponds to function
                     parameter type.
                  \T A Test is implemented to verify that the internal buffer used by compare functionality
                     is large enough to hold the maximum payload. TCASE-CheckInternalCompareBufferSize.

VCA_JUSTIFICATION_END */

/***********************************************************************************************************************
 *  COV JUSTIFICATION
 **********************************************************************************************************************/
/* COV_JUSTIFICATION_BEGIN

\ID COV_MEMACC_VCA
\ACCEPT TX
\ACCEPT XF
\REASON VCA needs additional functions to analyze to code in a meaningful way. Therefore, this code part is not enabled when using VCA.

COV_JUSTIFICATION_END */

/**********************************************************************************************************************
 *  END OF FILE: MemAcc_MemAb.c
 *********************************************************************************************************************/
