/***********************************************************************************************************************
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
/*!        \file  Mem_30_LegacyAdapter.c
 *        \brief  Mem_30_LegacyAdapter source file
 *      \details  The Memory driver provides basic services for accessing different kinds of memory devices.
 *         \unit  General
 **********************************************************************************************************************/

#define MEM_30_LEGACYADAPTER_SOURCE

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
#include "Mem_30_LegacyAdapter.h"
#include "Mem_30_LegacyAdapter_LLAdapter.h"
#include "Mem_30_LegacyAdapter_ErrorChecks_Int.h"

/***********************************************************************************************************************
 *  VERSION CHECK
 **********************************************************************************************************************/
/* A component internal version check is not necessary. */

/* Check the version of the configuration header file to ensure that the generated files match the static files. */
#if (  (MEM_30_LEGACYADAPTER_CFG_MAJOR_VERSION != (2u)) \
    || (MEM_30_LEGACYADAPTER_CFG_MINOR_VERSION != (0u)) )
# error "Version numbers of Mem_30_LegacyAdapter.c and Mem_30_LegacyAdapter_Cfg.h are inconsistent!"
#endif

/***********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 **********************************************************************************************************************/
#define MEM_30_LEGACYADAPTER_ABI_VERSION 0x0001uL

/*! Unique identifier of the Mem based on the below identifiers.
 * MEM_30_LEGACYADAPTER_ABI_VERSION -> ABI version as specified by AUTOSAR.
 * MEM_30_LEGACYADAPTER_VENDOR_ID -> Vendor ID of Vector Informatik GmbH
 * MEM_30_LEGACYADAPTER_DRIVER_ID -> Unique generated Mem driver identifier.
 */
#define MEM_30_LEGACYADAPTER_UNIQUEID    (((uint64)MEM_30_LEGACYADAPTER_DRIVER_ID << 32u) |\
                                          ((uint64)MEM_30_LEGACYADAPTER_VENDOR_ID << 16u) |\
                                          (MEM_30_LEGACYADAPTER_ABI_VERSION))

/*! Mem driver is not relocatable and there are no vendor specific flags, therefore flags shall be 0.*/
#define MEM_30_LEGACYADAPTER_FLAGS 0u

/***********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 **********************************************************************************************************************/
#if !defined (MEM_30_LEGACYADAPTER_LOCAL_INLINE)
# define MEM_30_LEGACYADAPTER_LOCAL_INLINE                            LOCAL_INLINE
#endif

#if !defined (MEM_30_LEGACYADAPTER_HEADERADDRESS) /* COV_MEM_30_LEGACYADAPTER_FUNCTIONPOINTERTABLE */
/* The header address is only relevant for Mem driver which shall be dynamically activated.
 * By default the value is set to 0 (Mem driver is statically available).
 * The value shall be overwritten with the actual value if the Mem driver will be dynamically activated */
# define MEM_30_LEGACYADAPTER_HEADERADDRESS    0uL
#endif /* MEM_30_LEGACYADAPTER_HEADERADDRESS */

#if !defined (MEM_30_LEGACYADAPTER_DELIMITERADDRESS) /* COV_MEM_30_LEGACYADAPTER_FUNCTIONPOINTERTABLE */
/* The delimiter address is only relevant for Mem driver which shall be dynamically activated.
 * By default the value is set to 0 (Mem driver is statically available).
 * The value shall be overwritten with the actual value if the Mem driver will be dynamically activated */
# define MEM_30_LEGACYADAPTER_DELIMITERADDRESS    0uL
#endif /* MEM_30_LEGACYADAPTER_DELIMITERADDRESS */

/***********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 **********************************************************************************************************************/

#define MEM_30_LEGACYADAPTER_START_SEC_CONST_DELIMITER_ASIL_D_64
#include "Mem_30_LegacyAdapter_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! The delimiter is only relevant for Mem driver which shall be dynamically activated.
 *  The Mem delimiter will be placed at the end of the Mem driver binary image.
 *  It is the complement of the unique identifier. */
/* PRQA S 3207 1 */ /* MD_Mem_30_LegacyAdapter_FunctionPointerTableDelimiter */
MEM_30_LEGACYADAPTER_LOCAL CONST(uint64, MEM_30_LEGACYADAPTER_CONST) Mem_30_LegacyAdapter_Delimiter = ~MEM_30_LEGACYADAPTER_UNIQUEID;

#define MEM_30_LEGACYADAPTER_STOP_SEC_CONST_DELIMITER_ASIL_D_64
#include "Mem_30_LegacyAdapter_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define MEM_30_LEGACYADAPTER_START_SEC_VAR_INIT_ASIL_D_8
#include "Mem_30_LegacyAdapter_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Initialization state of the module */
MEM_30_LEGACYADAPTER_LOCAL VAR(uint8, MEM_30_LEGACYADAPTER_VAR_INIT) Mem_30_LegacyAdapter_ModuleInitialized = MEM_30_LEGACYADAPTER_UNINIT;

#define MEM_30_LEGACYADAPTER_STOP_SEC_VAR_INIT_ASIL_D_8
#include "Mem_30_LegacyAdapter_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  GLOBAL DATA
 **********************************************************************************************************************/
#define MEM_30_LEGACYADAPTER_START_SEC_CONST_HEADER_ASIL_D_UNSPECIFIED
#include "Mem_30_LegacyAdapter_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */

/* PRQA S 1502 1 */ /* MD_Mem_30_LegacyAdapter_FunctionPointerTableDelimiter */
CONST(MemAcc_MemBinaryHeaderType, AUTOMATIC) Mem_30_LegacyAdapter_FunctionPointerTable = {
  MEM_30_LEGACYADAPTER_UNIQUEID,           /*!< Unique ID. */
  MEM_30_LEGACYADAPTER_FLAGS,              /*!< Header flags. */
  MEM_30_LEGACYADAPTER_HEADERADDRESS,      /*!< Header address */
  MEM_30_LEGACYADAPTER_DELIMITERADDRESS,   /*!< Delimiter address */
  &Mem_30_LegacyAdapter_Init,
  &Mem_30_LegacyAdapter_DeInit,
  &Mem_30_LegacyAdapter_MainFunction,
  &Mem_30_LegacyAdapter_GetJobResult,
  &Mem_30_LegacyAdapter_Read,
  &Mem_30_LegacyAdapter_Write,
  &Mem_30_LegacyAdapter_Erase,
  &Mem_30_LegacyAdapter_PropagateError,
  &Mem_30_LegacyAdapter_BlankCheck,
  &Mem_30_LegacyAdapter_Suspend,
  &Mem_30_LegacyAdapter_Resume,
  &Mem_30_LegacyAdapter_HwSpecificService
};

#define MEM_30_LEGACYADAPTER_STOP_SEC_CONST_HEADER_ASIL_D_UNSPECIFIED
#include "Mem_30_LegacyAdapter_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/
#define MEM_30_LEGACYADAPTER_START_SEC_CODE_ASIL_D
#include "Mem_30_LegacyAdapter_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  Mem_30_LegacyAdapter_Init()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, MEM_30_LEGACYADAPTER_CODE) Mem_30_LegacyAdapter_Init(Mem_30_LegacyAdapter_ConfigPtrType configPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = MEM_30_LEGACYADAPTER_E_NO_ERROR;
  MEM_30_LEGACYADAPTER_DUMMY_STATEMENT(configPtr); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  /* ----- Development Error Checks ------------------------------------- */
  if (Mem_30_LegacyAdapter_ErrorChecks_IsDetConditionTrue(  /* PRQA S 2992 */ /* MD_MSR_ConstantCondition */
    Mem_30_LegacyAdapter_ModuleInitialized == (uint8)MEM_30_LEGACYADAPTER_INIT))
  {
    /* Check if Driver is already initialized */
    errorId = MEM_30_LEGACYADAPTER_E_ALREADY_INITIALIZED;
  }
  else
  {
    /* ----- Implementation ----------------------------------------------- */
    /* Call low level initialization routine. */
    Mem_30_LegacyAdapter_LLAdapter_Init();
    Mem_30_LegacyAdapter_ModuleInitialized = (uint8)MEM_30_LEGACYADAPTER_INIT;
  }

  /* ----- Development Error Report --------------------------------------- */
  Mem_30_LegacyAdapter_ErrorChecks_ReportDetError(MEM_30_LEGACYADAPTER_SID_INIT, errorId);
}

/***********************************************************************************************************************
 *  Mem_30_LegacyAdapter_InitMemory()
 **********************************************************************************************************************/
 /*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, MEM_30_LEGACYADAPTER_CODE) Mem_30_LegacyAdapter_InitMemory(void)
{
  /* ----- Implementation ----------------------------------------------- */
  Mem_30_LegacyAdapter_ModuleInitialized = MEM_30_LEGACYADAPTER_UNINIT;
}

/***********************************************************************************************************************
 *  Mem_30_LegacyAdapter_DeInit()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, MEM_30_LEGACYADAPTER_CODE) Mem_30_LegacyAdapter_DeInit(void)
{
}

/***********************************************************************************************************************
 *  Mem_30_LegacyAdapter_MainFunction()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, MEM_30_LEGACYADAPTER_CODE) Mem_30_LegacyAdapter_MainFunction(void)
{
  /* ----- Local Variables ---------------------------------------------- */

  /* ----- Implementation ------------------------------------- */
  if (Mem_30_LegacyAdapter_ModuleInitialized == MEM_30_LEGACYADAPTER_INIT)
  {
    /* Call low level processing. */
    Mem_30_LegacyAdapter_LLAdapter_Processing();
  }
}

/***********************************************************************************************************************
 *  Mem_30_LegacyAdapter_GetJobResult()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Mem_30_LegacyAdapter_JobResultType, MEM_30_LEGACYADAPTER_CODE) Mem_30_LegacyAdapter_GetJobResult(
  Mem_30_LegacyAdapter_InstanceIdType instanceId)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = MEM_30_LEGACYADAPTER_E_NO_ERROR;
  Mem_30_LegacyAdapter_JobResultType jobResult = MEM_JOB_FAILED; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  /* ----- Development Error Checks ------------------------------------- */
  if (Mem_30_LegacyAdapter_ErrorChecks_IsDetConditionTrue(  /* PRQA S 2992 */ /* MD_MSR_ConstantCondition */
    Mem_30_LegacyAdapter_ModuleInitialized != (uint8)MEM_30_LEGACYADAPTER_INIT))
  {
    errorId = MEM_30_LEGACYADAPTER_E_UNINIT;
  }
  else if (Mem_30_LegacyAdapter_ErrorChecks_IsDetConditionTrue(  /* PRQA S 2992 */ /* MD_MSR_ConstantCondition */
    instanceId >= Mem_30_LegacyAdapter_GetSizeOfMemInstanceIdMapping()))
  {
    errorId = MEM_30_LEGACYADAPTER_E_PARAM_INSTANCE_ID;
  }
  else
  {
    /* ----- Implementation ----------------------------------------------- */
    jobResult = Mem_30_LegacyAdapter_LLAdapter_GetJobResult(instanceId);
  }

  /* ----- Development Error Report --------------------------------------- */
  Mem_30_LegacyAdapter_ErrorChecks_ReportDetError(MEM_30_LEGACYADAPTER_SID_GETJOBRESULT, errorId);

  return jobResult;
}

/**********************************************************************************************************************
 *  Mem_30_LegacyAdapter_Read()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6080 5 */ /* MD_MSR_STMIF */
FUNC(Std_ReturnType, MEM_30_LEGACYADAPTER_CODE) Mem_30_LegacyAdapter_Read(
  Mem_30_LegacyAdapter_InstanceIdType instanceId,
  Mem_30_LegacyAdapter_AddressType sourceAddress,
  Mem_30_LegacyAdapter_DataPtrType destinationDataPtr,
  Mem_30_LegacyAdapter_LengthType length
  )
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = MEM_30_LEGACYADAPTER_E_NO_ERROR;
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  /* ----- Development Error Checks ------------------------------------- */
  if (Mem_30_LegacyAdapter_ErrorChecks_IsDetConditionTrue(  /* PRQA S 2992 */ /* MD_MSR_ConstantCondition */
    Mem_30_LegacyAdapter_ModuleInitialized != (uint8)MEM_30_LEGACYADAPTER_INIT))
  {
    errorId = MEM_30_LEGACYADAPTER_E_UNINIT;
  }
  else if (Mem_30_LegacyAdapter_ErrorChecks_IsDetConditionTrue(  /* PRQA S 2992 */ /* MD_MSR_ConstantCondition */
    instanceId >= Mem_30_LegacyAdapter_GetSizeOfMemInstanceIdMapping()))
  {
    errorId = MEM_30_LEGACYADAPTER_E_PARAM_INSTANCE_ID;
  }
  else if (Mem_30_LegacyAdapter_ErrorChecks_IsDetConditionTrue(  /* PRQA S 2992 */ /* MD_MSR_ConstantCondition */
    destinationDataPtr == NULL_PTR))
  {
    errorId = MEM_30_LEGACYADAPTER_E_PARAM_POINTER;
  }
  else
  {
    /* ----- Implementation ----------------------------------------------- */
    retVal = Mem_30_LegacyAdapter_LLAdapter_Read(instanceId, sourceAddress, destinationDataPtr, length); /* SBSW_Mem_30_LegacyAdapter_UserPointer */
  }

  /* ----- Development Error Report --------------------------------------- */
  Mem_30_LegacyAdapter_ErrorChecks_ReportDetError(MEM_30_LEGACYADAPTER_SID_READ, errorId);
  return retVal;
}

/**********************************************************************************************************************
 *  Mem_30_LegacyAdapter_Write()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6080 5 */ /* MD_MSR_STMIF */
FUNC(Std_ReturnType, MEM_30_LEGACYADAPTER_CODE) Mem_30_LegacyAdapter_Write(
  Mem_30_LegacyAdapter_InstanceIdType instanceId,
  Mem_30_LegacyAdapter_AddressType targetAddress,
  Mem_30_LegacyAdapter_ConstDataPtrType sourceDataPtr,
  Mem_30_LegacyAdapter_LengthType length
  )
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = MEM_30_LEGACYADAPTER_E_NO_ERROR;
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  /* ----- Development Error Checks ------------------------------------- */
  if (Mem_30_LegacyAdapter_ErrorChecks_IsDetConditionTrue(  /* PRQA S 2992 */ /* MD_MSR_ConstantCondition */
    Mem_30_LegacyAdapter_ModuleInitialized != (uint8)MEM_30_LEGACYADAPTER_INIT))
  {
    errorId = MEM_30_LEGACYADAPTER_E_UNINIT;
  }
  else if (Mem_30_LegacyAdapter_ErrorChecks_IsDetConditionTrue(  /* PRQA S 2992 */ /* MD_MSR_ConstantCondition */
    instanceId >= Mem_30_LegacyAdapter_GetSizeOfMemInstanceIdMapping()))
  {
    errorId = MEM_30_LEGACYADAPTER_E_PARAM_INSTANCE_ID;
  }
  else if (Mem_30_LegacyAdapter_ErrorChecks_IsDetConditionTrue(  /* PRQA S 2992 */ /* MD_MSR_ConstantCondition */
    sourceDataPtr == NULL_PTR))
  {
    errorId = MEM_30_LEGACYADAPTER_E_PARAM_POINTER;
  }
  else
  {
    /* ----- Implementation ----------------------------------------------- */
    retVal = Mem_30_LegacyAdapter_LLAdapter_Write(instanceId, targetAddress, sourceDataPtr, length); /* SBSW_Mem_30_LegacyAdapter_UserPointer */
  }

  /* ----- Development Error Report --------------------------------------- */
  Mem_30_LegacyAdapter_ErrorChecks_ReportDetError(MEM_30_LEGACYADAPTER_SID_WRITE, errorId);

  return retVal;
}

/**********************************************************************************************************************
 *  Mem_30_LegacyAdapter_Erase()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, MEM_30_LEGACYADAPTER_CODE) Mem_30_LegacyAdapter_Erase(
  Mem_30_LegacyAdapter_InstanceIdType instanceId,
  Mem_30_LegacyAdapter_AddressType targetAddress,
  Mem_30_LegacyAdapter_LengthType length
  )
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = MEM_30_LEGACYADAPTER_E_NO_ERROR;
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  /* ----- Development Error Checks ------------------------------------- */
  if (Mem_30_LegacyAdapter_ErrorChecks_IsDetConditionTrue(  /* PRQA S 2992 */ /* MD_MSR_ConstantCondition */
    Mem_30_LegacyAdapter_ModuleInitialized != (uint8)MEM_30_LEGACYADAPTER_INIT))
  {
    errorId = MEM_30_LEGACYADAPTER_E_UNINIT;
  }
  else if (Mem_30_LegacyAdapter_ErrorChecks_IsDetConditionTrue(  /* PRQA S 2992 */ /* MD_MSR_ConstantCondition */
    instanceId >= Mem_30_LegacyAdapter_GetSizeOfMemInstanceIdMapping()))
  {
    errorId = MEM_30_LEGACYADAPTER_E_PARAM_INSTANCE_ID;
  }
  else
  {
    /* ----- Implementation ----------------------------------------------- */
    retVal = Mem_30_LegacyAdapter_LLAdapter_Erase(instanceId, targetAddress, length);
  }

  /* ----- Development Error Report --------------------------------------- */
  Mem_30_LegacyAdapter_ErrorChecks_ReportDetError(MEM_30_LEGACYADAPTER_SID_ERASE, errorId);

  return retVal;
}

/**********************************************************************************************************************
 *  Mem_30_LegacyAdapter_BlankCheck()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, MEM_30_LEGACYADAPTER_CODE) Mem_30_LegacyAdapter_BlankCheck(
  Mem_30_LegacyAdapter_InstanceIdType instanceId,
  Mem_30_LegacyAdapter_AddressType targetAddress,
  Mem_30_LegacyAdapter_LengthType length)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = MEM_30_LEGACYADAPTER_E_NO_ERROR;
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  /* ----- Development Error Checks ------------------------------------- */
  if (Mem_30_LegacyAdapter_ErrorChecks_IsDetConditionTrue(  /* PRQA S 2992 */ /* MD_MSR_ConstantCondition */
    Mem_30_LegacyAdapter_ModuleInitialized != (uint8)MEM_30_LEGACYADAPTER_INIT))
  {
    errorId = MEM_30_LEGACYADAPTER_E_UNINIT;
  }
  else if (Mem_30_LegacyAdapter_ErrorChecks_IsDetConditionTrue(  /* PRQA S 2992 */ /* MD_MSR_ConstantCondition */
    instanceId >= Mem_30_LegacyAdapter_GetSizeOfMemInstanceIdMapping()))
  {
    errorId = MEM_30_LEGACYADAPTER_E_PARAM_INSTANCE_ID;
  }
  else
  {
    /* ----- Implementation ----------------------------------------------- */
    retVal = Mem_30_LegacyAdapter_LLAdapter_BlankCheck(instanceId, targetAddress, length);
  }

  /* ----- Development Error Report --------------------------------------- */
  Mem_30_LegacyAdapter_ErrorChecks_ReportDetError(MEM_30_LEGACYADAPTER_SID_BLANKCHECK, errorId);

  return retVal;
}

/***********************************************************************************************************************
 *  Mem_30_LegacyAdapter_PropagateError()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, MEM_30_LEGACYADAPTER_CODE) Mem_30_LegacyAdapter_PropagateError(Mem_30_LegacyAdapter_InstanceIdType instanceId)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = MEM_30_LEGACYADAPTER_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
  if (Mem_30_LegacyAdapter_ErrorChecks_IsDetConditionTrue(  /* PRQA S 2992 */ /* MD_MSR_ConstantCondition */
    Mem_30_LegacyAdapter_ModuleInitialized != (uint8)MEM_30_LEGACYADAPTER_INIT))
  {
    errorId = MEM_30_LEGACYADAPTER_E_UNINIT;
  }
  else if (Mem_30_LegacyAdapter_ErrorChecks_IsDetConditionTrue(  /* PRQA S 2992 */ /* MD_MSR_ConstantCondition */
    instanceId >= Mem_30_LegacyAdapter_GetSizeOfMemInstanceIdMapping()))
  {
    errorId = MEM_30_LEGACYADAPTER_E_PARAM_INSTANCE_ID;
  }
  else
  {
  /* ----- Implementation ----------------------------------------------- */
    Mem_30_LegacyAdapter_LLAdapter_PropagateError(instanceId);
  }

  /* ----- Development Error Report --------------------------------------- */
  Mem_30_LegacyAdapter_ErrorChecks_ReportDetError(MEM_30_LEGACYADAPTER_SID_PROPAGATEERROR, errorId);
}

/***********************************************************************************************************************
 *  Mem_30_LegacyAdapter_Suspend()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, MEM_30_LEGACYADAPTER_CODE) Mem_30_LegacyAdapter_Suspend(
  Mem_30_LegacyAdapter_InstanceIdType instanceId)
{
  MEM_30_LEGACYADAPTER_DUMMY_STATEMENT(instanceId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_MEM_SERVICE_NOT_AVAIL;
}

/***********************************************************************************************************************
 *  Mem_30_LegacyAdapter_Resume()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, MEM_30_LEGACYADAPTER_CODE) Mem_30_LegacyAdapter_Resume(
  Mem_30_LegacyAdapter_InstanceIdType instanceId)
{
  MEM_30_LEGACYADAPTER_DUMMY_STATEMENT(instanceId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_MEM_SERVICE_NOT_AVAIL;
}

/***********************************************************************************************************************
 *  Mem_30_LegacyAdapter_HwSpecificService()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, MEM_30_LEGACYADAPTER_CODE) Mem_30_LegacyAdapter_HwSpecificService(
  Mem_30_LegacyAdapter_InstanceIdType instanceId,
  Mem_30_LegacyAdapter_HwServiceIdType hwServiceId,
  Mem_30_LegacyAdapter_DataType* dataPtr,
  Mem_30_LegacyAdapter_LengthType* lengthPtr) /* PRQA S 3673 */ /* MD_Mem_30_LegacyAdapter_CouldBePointerToConst */
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = MEM_30_LEGACYADAPTER_E_NO_ERROR;
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  /* ----- Development Error Checks ------------------------------------- */
  if (Mem_30_LegacyAdapter_ErrorChecks_IsDetConditionTrue(  /* PRQA S 2992 */ /* MD_MSR_ConstantCondition */
    Mem_30_LegacyAdapter_ModuleInitialized != (uint8)MEM_30_LEGACYADAPTER_INIT))
  {
    errorId = MEM_30_LEGACYADAPTER_E_UNINIT;
  }
  else if (Mem_30_LegacyAdapter_ErrorChecks_IsDetConditionTrue(  /* PRQA S 2992 */ /* MD_MSR_ConstantCondition */
    instanceId >= Mem_30_LegacyAdapter_GetSizeOfMemInstanceIdMapping()))
  {
    errorId = MEM_30_LEGACYADAPTER_E_PARAM_INSTANCE_ID;
  }
  else if (Mem_30_LegacyAdapter_ErrorChecks_IsDetConditionTrue(  /* PRQA S 2992 */ /* MD_MSR_ConstantCondition */
    (dataPtr == NULL_PTR) || (lengthPtr == NULL_PTR)))
  {
    errorId = MEM_30_LEGACYADAPTER_E_PARAM_POINTER;
  }
      /* PRQA S 2991, 2995 2 */ /* MD_Mem_30_LegacyAdapter_DetCheckHwServiceId */
  else if (Mem_30_LegacyAdapter_ErrorChecks_IsDetConditionTrue(  /* PRQA S 2992 */ /* MD_MSR_ConstantCondition */
    Mem_30_LegacyAdapter_LLAdapter_IsHwServiceIdValid(instanceId, hwServiceId) == FALSE))
  {
    errorId = MEM_30_LEGACYADAPTER_E_PARAM_HWSID;
  }
  else
  {
    /* ----- Implementation ----------------------------------------------- */
    retVal = Mem_30_LegacyAdapter_LLAdapter_HwSpecificService(instanceId, hwServiceId, dataPtr, lengthPtr);
  }
  /* ----- Development Error Report --------------------------------------- */
  Mem_30_LegacyAdapter_ErrorChecks_ReportDetError(MEM_30_LEGACYADAPTER_SID_HWSPECIFICSERVICE, errorId);

  return retVal;
}

/***********************************************************************************************************************
 *  Mem_30_LegacyAdapter_GetVersionInfo()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, MEM_30_LEGACYADAPTER_CODE) Mem_30_LegacyAdapter_GetVersionInfo(
  P2VAR(Std_VersionInfoType, AUTOMATIC, MEM_30_LEGACYADAPTER_APPL_VAR) versioninfo)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = MEM_30_LEGACYADAPTER_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
  if (Mem_30_LegacyAdapter_ErrorChecks_IsDetConditionTrue(  /* PRQA S 2992 */ /* MD_MSR_ConstantCondition */
    versioninfo == NULL_PTR))
  {
    errorId = MEM_30_LEGACYADAPTER_E_PARAM_POINTER;
  }
  else
  {
    /* ----- Implementation ----------------------------------------------- */
    versioninfo->vendorID = (MEM_30_LEGACYADAPTER_VENDOR_ID);
    versioninfo->moduleID = (MEM_30_LEGACYADAPTER_MODULE_ID);
    versioninfo->sw_major_version = (MEM_30_LEGACYADAPTER_SW_MAJOR_VERSION);
    versioninfo->sw_minor_version = (MEM_30_LEGACYADAPTER_SW_MINOR_VERSION);
    versioninfo->sw_patch_version = (MEM_30_LEGACYADAPTER_SW_PATCH_VERSION);
  }

  /* ----- Development Error Report --------------------------------------- */
  Mem_30_LegacyAdapter_ErrorChecks_ReportDetError(MEM_30_LEGACYADAPTER_SID_GETVERSIONINFO, errorId);
}

#define MEM_30_LEGACYADAPTER_STOP_SEC_CODE_ASIL_D
#include "Mem_30_LegacyAdapter_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  MISRA JUSTIFICATIONS
 **********************************************************************************************************************/
/* Justification for module-specific MISRA deviations:
MD_Mem_30_LegacyAdapter_InlineFunction
    Reason:     The function annotated with this justification is inlined and implemented in the header file. The
                function is not used by all implementation files which include this header file.
    Risk:       The function is redundant and therefore dead code, which shall be avoided.
    Prevention: Code Inspection and coverage measurement during testing -> The function is at least used in one
                translation unit that includes the header file.

MD_Mem_30_LegacyAdapter_DetCheckHwServiceId
    Reason:     In case MEM_30_LEGACYADAPTER_VMEMTYPESENABLED is STD_OFF and the check for Det check for the HwServiceIf
                within Mem_30_LegacyAdapter_LLAdapter_IsHwServiceIdValid always returns false, because there is no
                Hardware specific service if there is no underlying vMem Driver. Hence, if also
                MEM_30_LEGACYADAPTER_DEV_ERROR_DETECT is STD_ON, the if condition is always true and an error is thrown.
    Risk:       The if statement is redundant, which shall be avoided.
    Prevention: Code Inspection and coverage measurement during testing -> There is at least one configuration there
                the if statement is tested.

MD_Mem_30_LegacyAdapter_FunctionPointerTableDelimiter
    Reason:     The function pointer table and the delimiter address must be defined within the component to
                allow dynamic activation of the Mem driver. They are used by the calling module (MemAcc) and
                therefore, they are not referenced within the component itself.
    Risk:       No functional risk.
    Prevention: No prevention necessary.

MD_Mem_30_LegacyAdapter_CouldBePointerToConst
    Reason:     The pointer could be a pointer to const, but is not defined as such to keep the interface of the
                Mem driver consistent with other memory drivers.
    Risk:       No functional risk.
    Prevention: No prevention necessary.
*/

/***********************************************************************************************************************
 *  SILENTBSW JUSTIFICATIONS
 **********************************************************************************************************************/
/* VCA_JUSTIFICATION_BEGIN
VCA_JUSTIFICATION_END
*/

/***********************************************************************************************************************
 *  COVERAGE JUSTIFICATIONS
 **********************************************************************************************************************/
/* START_COVERAGE_JUSTIFICATION

Variant coverage:

\ID COV_MEM_30_LEGACYADAPTER_FUNCTIONPOINTERTABLE
   \ACCEPT TX
   \REASON Header and Delimiter address must be defined outside the component.
           Part of integration for dynamically activated Mem driver.
           Can not be tested on component level.

END_COVERAGE_JUSTIFICATION
*/

/***********************************************************************************************************************
 *  END OF FILE: Mem_30_LegacyAdapter.c
 **********************************************************************************************************************/
