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
/*!        \file  Mem_30_LegacyAdapter_LLAdapter.c
 *        \brief  Mem LLAdapter source file
 *
 *      \details  See Mem_30_LegacyAdapter_LLAdapter.h
 *         \unit  LLAdapter
 *********************************************************************************************************************/

#define MEM_30_LEGACYADAPTER_LLADAPTER_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Mem_30_LegacyAdapter_LLAdapter.h"

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

#if !defined (MEM_30_LEGACYADAPTER_LOCAL)
# define MEM_30_LEGACYADAPTER_LOCAL                            static
#endif
/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

#define MEM_30_LEGACYADAPTER_START_SEC_VAR_CLEARED_ASIL_D_8
#include "Mem_30_LegacyAdapter_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Indicates wether PropagateError was called for a mem instance id. */
MEM_30_LEGACYADAPTER_LOCAL VAR(boolean, MEM_30_LEGACYADAPTER_VAR_CLEARED)
  Mem_30_LegacyAdapter_ErrorPropagated[Mem_30_LegacyAdapter_GetSizeOfMemInstanceIdMappingOfPCConfig()];

#define MEM_30_LEGACYADAPTER_STOP_SEC_VAR_CLEARED_ASIL_D_8
#include "Mem_30_LegacyAdapter_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#define MEM_30_LEGACYADAPTER_START_SEC_CODE_ASIL_D
#include "Mem_30_LegacyAdapter_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# if (MEM_30_LEGACYADAPTER_MEMIFTYPESENABLED == STD_ON)

/**********************************************************************************************************************
 * Mem_30_LegacyAdapter_LLAdapter_MapMemIfJobResult()
 *********************************************************************************************************************/
/*! \brief       Maps a MemIf_JobResultType to a Mem_30_LegacyAdapter_JobResultType.
 *  \details     -
 *  \param[in]   jobResult           The job result to be mapped.
 *  \return      Mapped job result.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Mem_30_LegacyAdapter_JobResultType, MEM_30_LEGACYADAPTER_CODE)
Mem_30_LegacyAdapter_LLAdapter_MapMemIfJobResult(const MemIf_JobResultType jobResult);

# endif /* (MEM_30_LEGACYADAPTER_MEMIFTYPESENABLED == STD_ON) */

# if (MEM_30_LEGACYADAPTER_VMEMTYPESENABLED == STD_ON)

/**********************************************************************************************************************
 * Mem_30_LegacyAdapter_LLAdapter_MapVMemJobResult()
 *********************************************************************************************************************/
/*! \brief       Maps a vMemAccM_vMemJobResultType to a Mem_30_LegacyAdapter_JobResultType.
 *  \details     -
 *  \param[in]   jobResult           The job result to be mapped.
 *  \return      Mapped job result.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Mem_30_LegacyAdapter_JobResultType, MEM_30_LEGACYADAPTER_CODE)
Mem_30_LegacyAdapter_LLAdapter_MapVMemJobResult(const vMemAccM_vMemJobResultType jobResult);

# endif /* (MEM_30_LEGACYADAPTER_VMEMTYPESENABLED == STD_ON) */

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  Mem_30_LegacyAdapter_LLAdapter_Init()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, MEM_30_LEGACYADAPTER_CODE) Mem_30_LegacyAdapter_LLAdapter_Init(void)
{
  for (Mem_30_LegacyAdapter_MemInstanceIdMappingIterType instanceId = 0u;
      instanceId < Mem_30_LegacyAdapter_GetSizeOfMemInstanceIdMappingOfPCConfig();
      instanceId++)
  {
    Mem_30_LegacyAdapter_ErrorPropagated[instanceId] = FALSE;
  }

  for (Mem_30_LegacyAdapter_LLApiIterType llApi = 0u;
      llApi < Mem_30_LegacyAdapter_GetSizeOfLLApi();
      llApi++)
  {
    /* The passed cfgPtr is always NULL_PTR. A specific cfgPtr would only be needed in very special use
     * case of reloadable external underlying driver, which is not supported, as the underlying vMem driver also
     * don't support it and Fls_Init/Eep_Init is not called by adapter.
     */
    Mem_30_LegacyAdapter_GetInitOfLLApi(llApi)(NULL_PTR);
  }
}

/**********************************************************************************************************************
 * Mem_30_LegacyAdapter_LLAdapter_GetJobResult
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Mem_30_LegacyAdapter_JobResultType, MEM_30_LEGACYADAPTER_CODE) Mem_30_LegacyAdapter_LLAdapter_GetJobResult(
  const Mem_30_LegacyAdapter_InstanceIdType instanceId)
{
  Mem_30_LegacyAdapter_JobResultType jobResult = Mem_30_LegacyAdapter_GetGetJobResultOfLLApi(
    Mem_30_LegacyAdapter_GetLLApiIdxOfMemInstanceIdMapping(instanceId))(
      Mem_30_LegacyAdapter_GetLLInstanceIdOfMemInstanceIdMapping(instanceId));

  if ((jobResult != MEM_JOB_PENDING) && Mem_30_LegacyAdapter_ErrorPropagated[instanceId])
  {
    jobResult = MEM_ECC_UNCORRECTED;
  }

  return jobResult;
}

/**********************************************************************************************************************
 *  Mem_30_LegacyAdapter_LLAdapter_Read
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Std_ReturnType, MEM_30_LEGACYADAPTER_CODE) Mem_30_LegacyAdapter_LLAdapter_Read(
  const Mem_30_LegacyAdapter_InstanceIdType instanceId,
  const Mem_30_LegacyAdapter_AddressType sourceAddress,
  Mem_30_LegacyAdapter_DataPtrType destinationDataPtr,
  const Mem_30_LegacyAdapter_LengthType length)
{
  Mem_30_LegacyAdapter_ErrorPropagated[instanceId] = FALSE;

  return Mem_30_LegacyAdapter_GetReadOfLLApi(Mem_30_LegacyAdapter_GetLLApiIdxOfMemInstanceIdMapping(instanceId))(
    Mem_30_LegacyAdapter_GetLLInstanceIdOfMemInstanceIdMapping(instanceId),
    sourceAddress,
    destinationDataPtr,
    length);
}

/**********************************************************************************************************************
 *  Mem_30_LegacyAdapter_LLAdapter_Write
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Std_ReturnType, MEM_30_LEGACYADAPTER_CODE) Mem_30_LegacyAdapter_LLAdapter_Write(
  const Mem_30_LegacyAdapter_InstanceIdType instanceId,
  const Mem_30_LegacyAdapter_AddressType targetAddress,
  Mem_30_LegacyAdapter_ConstDataPtrType sourceDataPtr,
  const Mem_30_LegacyAdapter_LengthType length)
{
  Mem_30_LegacyAdapter_ErrorPropagated[instanceId] = FALSE;

  return Mem_30_LegacyAdapter_GetWriteOfLLApi(Mem_30_LegacyAdapter_GetLLApiIdxOfMemInstanceIdMapping(instanceId))(
    Mem_30_LegacyAdapter_GetLLInstanceIdOfMemInstanceIdMapping(instanceId),
    targetAddress,
    sourceDataPtr,
    length);
}

/**********************************************************************************************************************
 *  Mem_30_LegacyAdapter_LLAdapter_Erase
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Std_ReturnType, MEM_30_LEGACYADAPTER_CODE) Mem_30_LegacyAdapter_LLAdapter_Erase(
  const Mem_30_LegacyAdapter_InstanceIdType instanceId,
  const Mem_30_LegacyAdapter_AddressType targetAddress,
  const Mem_30_LegacyAdapter_LengthType length)
{
  Mem_30_LegacyAdapter_ErrorPropagated[instanceId] = FALSE;

  return Mem_30_LegacyAdapter_GetEraseOfLLApi(Mem_30_LegacyAdapter_GetLLApiIdxOfMemInstanceIdMapping(instanceId))(
    Mem_30_LegacyAdapter_GetLLInstanceIdOfMemInstanceIdMapping(instanceId),
    targetAddress,
    length);
}

/**********************************************************************************************************************
 *  Mem_30_LegacyAdapter_LLAdapter_BlankCheck
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Std_ReturnType, MEM_30_LEGACYADAPTER_CODE) Mem_30_LegacyAdapter_LLAdapter_BlankCheck(
  const Mem_30_LegacyAdapter_InstanceIdType instanceId,
  const Mem_30_LegacyAdapter_AddressType targetAddress,
  const Mem_30_LegacyAdapter_LengthType length)
{
  Mem_30_LegacyAdapter_ErrorPropagated[instanceId] = FALSE;

  return Mem_30_LegacyAdapter_GetIsBlankOfLLApi(Mem_30_LegacyAdapter_GetLLApiIdxOfMemInstanceIdMapping(instanceId))(
    Mem_30_LegacyAdapter_GetLLInstanceIdOfMemInstanceIdMapping(instanceId),
    targetAddress,
    length);
}

/***********************************************************************************************************************
 *  Mem_30_LegacyAdapter_LLAdapter_HwSpecificService()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, MEM_30_LEGACYADAPTER_CODE) Mem_30_LegacyAdapter_LLAdapter_HwSpecificService(
  const Mem_30_LegacyAdapter_InstanceIdType instanceId,
  const Mem_30_LegacyAdapter_HwServiceIdType hwServiceId,
  Mem_30_LegacyAdapter_DataType* dataPtr, /* PRQA S 3673 */ /* MD_Mem_30_LegacyAdapter_CouldBePointerToConst */
  const Mem_30_LegacyAdapter_LengthType* lengthPtr)
{
  Std_ReturnType result = E_NOT_OK;

# if (MEM_30_LEGACYADAPTER_VMEMTYPESENABLED == STD_ON)
  Mem_30_LegacyAdapter_vMemHwSpecificFunctionsPtrType hwFunctions = Mem_30_LegacyAdapter_GetHwFunctionsOfLLApi(
    Mem_30_LegacyAdapter_GetLLApiIdxOfMemInstanceIdMapping(instanceId));
  Mem_30_LegacyAdapter_ErrorPropagated[instanceId] = FALSE;

  if (hwFunctions != NULL_PTR)
  {
    /* VCA Line+1 SLC-10, SLC-11, SLC-22 : VCA_Mem_30_LegacyAdapter_vMemDrvHwFunctionTable */
    result = hwFunctions->Table[hwServiceId](
      Mem_30_LegacyAdapter_GetLLInstanceIdOfMemInstanceIdMapping(instanceId),
      dataPtr,
      *lengthPtr);
  }

# endif /* (MEM_30_LEGACYADAPTER_VMEMTYPESENABLED == STD_ON) */
  MEM_30_LEGACYADAPTER_DUMMY_STATEMENT_CONST(instanceId);
  MEM_30_LEGACYADAPTER_DUMMY_STATEMENT_CONST(hwServiceId);
  MEM_30_LEGACYADAPTER_DUMMY_STATEMENT(dataPtr); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  MEM_30_LEGACYADAPTER_DUMMY_STATEMENT_CONST(lengthPtr);
  return result;
}

/**********************************************************************************************************************
 *  Mem_30_LegacyAdapter_LLAdapter_Processing
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, MEM_30_LEGACYADAPTER_CODE) Mem_30_LegacyAdapter_LLAdapter_Processing(void)
{
  for (Mem_30_LegacyAdapter_LLApiIterType llApi = 0u;
    llApi < Mem_30_LegacyAdapter_GetSizeOfLLApi();
    llApi++)
  {
    Mem_30_LegacyAdapter_GetMainFunctionOfLLApi(llApi)();
  }
}


/**********************************************************************************************************************
 *  Mem_30_LegacyAdapter_LLAdapter_PropagateError
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, MEM_30_LEGACYADAPTER_CODE) Mem_30_LegacyAdapter_LLAdapter_PropagateError(
  const Mem_30_LegacyAdapter_InstanceIdType instanceId)
{
  Mem_30_LegacyAdapter_ErrorPropagated[instanceId] = TRUE;
}

/***********************************************************************************************************************
 * LOCAL FUNCTIONS
 **********************************************************************************************************************/

# if (MEM_30_LEGACYADAPTER_MEMIFTYPESENABLED == STD_ON)

 /**********************************************************************************************************************
 * Mem_30_LegacyAdapter_LLAdapter_MapMemIfJobResult()
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
FUNC(Mem_30_LegacyAdapter_JobResultType, MEM_30_LEGACYADAPTER_CODE)
Mem_30_LegacyAdapter_LLAdapter_MapMemIfJobResult(const MemIf_JobResultType jobResult)
{
  Mem_30_LegacyAdapter_JobResultType parsedJobResult = MEM_JOB_FAILED;

  switch (jobResult)
  {
    case MEMIF_JOB_OK:
      parsedJobResult = MEM_JOB_OK;
      break;
    case MEMIF_JOB_PENDING:
      parsedJobResult = MEM_JOB_PENDING;
      break;
    case MEMIF_BLOCK_INCONSISTENT:
      parsedJobResult = MEM_INCONSISTENT;
      break;
    case MEMIF_JOB_FAILED:
    case MEMIF_JOB_CANCELED:
    case MEMIF_BLOCK_INVALID:
    default:
      parsedJobResult = MEM_JOB_FAILED;
      break;
  }

  return parsedJobResult;
}

# endif /* (MEM_30_LEGACYADAPTER_MEMIFTYPESENABLED == STD_ON) */

# if (MEM_30_LEGACYADAPTER_VMEMTYPESENABLED == STD_ON)

/**********************************************************************************************************************
 * Mem_30_LegacyAdapter_LLAdapter_MapVMemJobResult()
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
FUNC(Mem_30_LegacyAdapter_JobResultType, MEM_30_LEGACYADAPTER_CODE)
Mem_30_LegacyAdapter_LLAdapter_MapVMemJobResult(const vMemAccM_vMemJobResultType jobResult)
{
  Mem_30_LegacyAdapter_JobResultType parsedJobResult = MEM_JOB_FAILED;

  switch (jobResult)
  {
    case VMEM_JOB_OK:
      parsedJobResult = MEM_JOB_OK;
      break;
    case VMEM_JOB_PENDING:
      parsedJobResult = MEM_JOB_PENDING;
      break;
    case VMEM_MEM_NOT_BLANK:
      parsedJobResult = MEM_INCONSISTENT;
      break;
    case VMEM_READ_UNCORRECTABLE_ERRORS:
      parsedJobResult = MEM_ECC_UNCORRECTED;
      break;
    case VMEM_READ_CORRECTED_ERRORS:
      parsedJobResult = MEM_ECC_CORRECTED;
      break;
    case VMEM_JOB_FAILED:
    default:
      parsedJobResult = MEM_JOB_FAILED;
      break;
  }

  return parsedJobResult;
}

# endif /* (MEM_30_LEGACYADAPTER_VMEMTYPESENABLED == STD_ON) */

#define MEM_30_LEGACYADAPTER_STOP_SEC_CODE_ASIL_D
#include "Mem_30_LegacyAdapter_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  VCA JUSTIFICATIONS
 **********************************************************************************************************************/
/* VCA_JUSTIFICATION_BEGIN

\ID VCA_Mem_30_LegacyAdapter_vMemDrvServiceInvocation
  \DESCRIPTION The vMem Driver public services are invoked via a function pointer table provided by the vMem driver
               itself. Therefore, within the generated const data structure the Mem_30_LegacyAdapter holds the reference
               to the function pointer table provided by the vMem driver. Valid functions must be referenced.
               As for read, write and hardware specific services also pointer parameters are forwarded and their
               validity is ensured by MemAcc. The Mem_30_LegacyAdapter only passes the pointer forward.
               The function pointer table is not defined within the analyzed sources (included via extern), so VCA is
               unable to determine the actual behavior of the functions. Therefore, some code parts where the vMem
               driver services are invoked via function pointer table are disabled during VCA analysis.

  \COUNTERMEASURE \N Reference to the vMem drivers function pointer table is retrieved by array access over the
                     vMemDriverMappingIdx index. This index is retrieved by an indirection from the InstanceIdMapping.
                     The validity of the used instanceId is ensured by a runtime check. The access via the indirection
                     is guaranteed by the ComStackLib use case CSL03.
                     Wrong function pointer table would be detected immediately within integration test
                     as the connection to the underlying vMem driver is basic integration.
                     The forwarded pointer parameters are provided by the caller (MemAcc), who must ensure their
                     validity. However, a NULL_PTR check is performed as part of the API pattern.

\ID VCA_Mem_30_LegacyAdapter_vMemDrvHwFunctionTable
  \DESCRIPTION The vMem driver supports hardware-specific functions and provides them in another function pointer table.
               The size of the table is defined by the vMem Driver. It is the responsibility of the vMem driver to ensure
               that the size of the table is correct and that valid functions are referenced. The parameters dataPtr
               and lengthPtr are just forwarded to vMem driver.

  \COUNTERMEASURE \N The index of the hardware-specific function pointer table is checked against the size given by the
                     vMem driver. The vMem driver is responsible for ensuring that the size of the table is correct.
                     For the passed parameters dataPtr and lengthPtr a NULL_PTR check is performed.

\ID VCA_Mem_30_LegacyAdapter_CALL_EXTERNAL_FUNCTION_VAR_POINTER_ARGUMENT
  \DESCRIPTION A function (Read of underlying Fls/Eep driver) with pointer parameters is directly called, but the function
               is not defined within the analyzed sources. VCA is unable to determine the behavior of the function.
  \COUNTERMEASURE \N Arguments that contain var pointer are checked by review: Pointer type corresponds to function
                    parameter type.

VCA_JUSTIFICATION_END */

/**********************************************************************************************************************
 *  END OF FILE: Mem_30_LegacyAdapter_LLAdapter.c
 *********************************************************************************************************************/
