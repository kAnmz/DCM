/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2025 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!        \file  Mem_30_LegacyAdapter_Types.h
 *        \brief  Mem_30_LegacyAdapter types header file
 *         \unit  *
 **********************************************************************************************************************/

#if !defined (MEM_30_LEGACYADAPTER_TYPES_H)
# define MEM_30_LEGACYADAPTER_TYPES_H

/***********************************************************************************************************************
 * INCLUDES
 **********************************************************************************************************************/
# include "Std_Types.h"
# include "MemAcc_MemApi.h"
# include "vMemAccM_vMemApi.h"

/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/
/* Vendor and module identification */
# define MEM_30_LEGACYADAPTER_VENDOR_ID                           (30u)
# define MEM_30_LEGACYADAPTER_MODULE_ID                           (91u)

/* AUTOSAR Software specification version information */
# define MEM_30_LEGACYADAPTER_AR_RELEASE_MAJOR_VERSION            (4u)
# define MEM_30_LEGACYADAPTER_AR_RELEASE_MINOR_VERSION            (8u)
# define MEM_30_LEGACYADAPTER_AR_RELEASE_REVISION_VERSION         (0u)


# define MEM_30_LEGACYADAPTER_INSTANCE_ID_DET                     (0x00u)

/* ----- Modes ----- */
# define MEM_30_LEGACYADAPTER_UNINIT                              (0x00u)
# define MEM_30_LEGACYADAPTER_INIT                                (0x01u)

/* ----- API service IDs ----- */
/*!< Service ID: Mem_30_LegacyAdapter_Init() */
# define MEM_30_LEGACYADAPTER_SID_INIT                            (0x01u)
/*!< Service ID: Mem_30_LegacyAdapter_DeInit() */
# define MEM_30_LEGACYADAPTER_SID_DEINIT                          (0x0bu)
/*!< Service ID: Mem_30_LegacyAdapter_GetVersionInfo() */
# define MEM_30_LEGACYADAPTER_SID_GETVERSIONINFO                  (0x02u)
/*!< Service ID: Mem_30_LegacyAdapter_MainFunction() */
# define MEM_30_LEGACYADAPTER_SID_MAINFUNCTION                    (0x03u)
/*!< Service ID: Mem_30_LegacyAdapter_GetJobResult() */
# define MEM_30_LEGACYADAPTER_SID_GETJOBRESULT                    (0x04u)
/*!< Service ID: Mem_30_LegacyAdapter_Suspend() */
# define MEM_30_LEGACYADAPTER_SID_SUSPEND                         (0x0cu)
/*!< Service ID: Mem_30_LegacyAdapter_Resume() */
# define MEM_30_LEGACYADAPTER_SID_RESUME                          (0x0du)
/*!< Service ID: Mem_30_LegacyAdapter_PropagateError() */
# define MEM_30_LEGACYADAPTER_SID_PROPAGATEERROR                  (0x08u)
/*!< Service ID: Mem_30_LegacyAdapter_Read() */
# define MEM_30_LEGACYADAPTER_SID_READ                            (0x05u)
/*!< Service ID: Mem_30_LegacyAdapter_Write() */
# define MEM_30_LEGACYADAPTER_SID_WRITE                           (0x06u)
/*!< Service ID: Mem_30_LegacyAdapter_Erase() */
# define MEM_30_LEGACYADAPTER_SID_ERASE                           (0x07u)
/*!< Service ID: Mem_30_LegacyAdapter_BlankCheck() */
# define MEM_30_LEGACYADAPTER_SID_BLANKCHECK                      (0x09u)
/*!< Service ID: Mem_30_LegacyAdapter_HwSpecificService() */
# define MEM_30_LEGACYADAPTER_SID_HWSPECIFICSERVICE               (0x0au)
/*!< Service ID: Mem_30_LegacyAdapter_InitMemory() */
# define MEM_30_LEGACYADAPTER_SID_INIT_MEMORY                     (0x10u)     

/* ----- Error codes ----- */
# define MEM_30_LEGACYADAPTER_E_NO_ERROR                          (0x00u)
/*!< used to check if no error occurred - use a value unequal to any error code */
# define MEM_30_LEGACYADAPTER_E_UNINIT                            (0x01u)
/*!< Error code: API service used without module initialization. */
# define MEM_30_LEGACYADAPTER_E_PARAM_POINTER                     (0x02u)
/*!< Error code: API service used with invalid pointer parameter (NULL). */
# define MEM_30_LEGACYADAPTER_E_PARAM_ADDRESS                     (0x03u)
/*!< Error code: API service used with invalid address parameter. */
# define MEM_30_LEGACYADAPTER_E_PARAM_LENGTH                      (0x04u)
/*!< Error code: API service used with invalid length parameter. */
# define MEM_30_LEGACYADAPTER_E_PARAM_INSTANCE_ID                 (0x05u)
/*!< Error code: API service used with invalid instance identifier parameter. */
# define MEM_30_LEGACYADAPTER_E_PENDING                           (0x06u)
/*!< Error code: The requested instance is already pending. */
# define MEM_30_LEGACYADAPTER_E_ALREADY_INITIALIZED               (0x11u)
/*!< Error code: The service Mem_30_LegacyAdapter_Init() is called while the module is already initialized  */
# define MEM_30_LEGACYADAPTER_E_PARAM_CONFIG                      (0x0Au)
/*!< Error code: API service called with wrong config parameter. */
# define MEM_30_LEGACYADAPTER_E_PARAM_BUFFER_ALIGNMENT            (0x0Eu)
/*!< Error code: API service used with invalid buffer parameter. */
# define MEM_30_LEGACYADAPTER_E_PARAM_HWSID                       (0x14u)
/*!< Error code: The requested hardware specific service ID is invalid. */

/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

typedef MemAcc_MemAddressType                                     Mem_30_LegacyAdapter_AddressType;
typedef MemAcc_MemJobResultType                                   Mem_30_LegacyAdapter_JobResultType;
typedef MemAcc_MemInstanceIdType                                  Mem_30_LegacyAdapter_InstanceIdType;
typedef MemAcc_MemLengthType                                      Mem_30_LegacyAdapter_LengthType;
typedef MemAcc_MemDataType                                        Mem_30_LegacyAdapter_DataType;
typedef MemAcc_MemHwServiceIdType                                 Mem_30_LegacyAdapter_HwServiceIdType;
typedef const MemAcc_MemConfigType*                               Mem_30_LegacyAdapter_ConfigPtrType;

typedef Mem_30_LegacyAdapter_LengthType*                          Mem_30_LegacyAdapter_LengthPtrType;
typedef Mem_30_LegacyAdapter_DataType*                            Mem_30_LegacyAdapter_DataPtrType;
typedef const Mem_30_LegacyAdapter_DataType*                      Mem_30_LegacyAdapter_ConstDataPtrType;
typedef const vMemAccM_vMemHwSpecificFunctionsType*               Mem_30_LegacyAdapter_vMemHwSpecificFunctionsPtrType;

typedef P2FUNC(void, MEM_30_LEGACYADAPTER_VMEM_CODE, Mem_30_LegacyAdapter_LLInitFuncPtr)(Mem_30_LegacyAdapter_ConfigPtrType configPtr);
typedef P2FUNC(void, MEM_30_LEGACYADAPTER_VMEM_CODE, Mem_30_LegacyAdapter_LLMainFunctionFuncPtr)(void);
typedef P2FUNC(Std_ReturnType, MEM_30_LEGACYADAPTER_VMEM_CODE, Mem_30_LegacyAdapter_LLReadFuncPtr)
  (const Mem_30_LegacyAdapter_InstanceIdType instanceId, const Mem_30_LegacyAdapter_AddressType sourceAddress, Mem_30_LegacyAdapter_DataPtrType destinationDataPtr, const Mem_30_LegacyAdapter_LengthType length);
typedef P2FUNC(Std_ReturnType, MEM_30_LEGACYADAPTER_VMEM_CODE, Mem_30_LegacyAdapter_LLWriteFuncPtr)
  (const Mem_30_LegacyAdapter_InstanceIdType instanceId, const Mem_30_LegacyAdapter_AddressType targetAddress, Mem_30_LegacyAdapter_ConstDataPtrType sourceDataPtr, const Mem_30_LegacyAdapter_LengthType length);
typedef P2FUNC(Std_ReturnType, MEM_30_LEGACYADAPTER_VMEM_CODE, Mem_30_LegacyAdapter_LLEraseFuncPtr)
  (const Mem_30_LegacyAdapter_InstanceIdType instanceId, const Mem_30_LegacyAdapter_AddressType targetAddress, const Mem_30_LegacyAdapter_LengthType length);
typedef P2FUNC(Std_ReturnType, MEM_30_LEGACYADAPTER_VMEM_CODE, Mem_30_LegacyAdapter_LLIsBlankFuncPtr)
  (const Mem_30_LegacyAdapter_InstanceIdType instanceId, const Mem_30_LegacyAdapter_AddressType targetAddress, const Mem_30_LegacyAdapter_LengthType length);
typedef P2FUNC(Mem_30_LegacyAdapter_JobResultType, MEM_30_LEGACYADAPTER_VMEM_CODE, Mem_30_LegacyAdapter_LLGetJobResultFuncPtr)
  (const Mem_30_LegacyAdapter_InstanceIdType instanceId);

/* Value is returned by an API if the service function is not implemented. 
Note: This macro is an extension of Std_ReturnType */

# ifndef E_MEM_SERVICE_NOT_AVAIL  /* COV_MEM_30_LEGACYADAPTER_ENUM_DEFINITION */
#  define E_MEM_SERVICE_NOT_AVAIL (0x02u)
# endif

/***********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

/* COV_JUSTIFICATION_BEGIN

Code coverage:
  - none

Variant coverage:

\ID COV_MEM_30_LEGACYADAPTER_ENUM_DEFINITION
   \ACCEPT TX
   \REASON This preprocessor switch guards an enum definition that extends Std_ReturnType.
           

COV_JUSTIFICATION_END */


#endif /* MEM_30_LEGACYADAPTER_TYPES_H */

/***********************************************************************************************************************
 *  END OF FILE: Mem_30_LegacyAdapter_Types.h
 **********************************************************************************************************************/
