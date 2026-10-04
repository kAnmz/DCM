/***********************************************************************************************************************
 *  COPYRIGHT
 *  ------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2025 by Vector Informatik GmbH. All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  ------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/*!        \file  vMem_30_Traveo2Cyp01_Types.h
 *        \brief  vMem_30_Traveo2Cyp01 types header file
 *
 *      \details  Defines vMem_30_Traveo2Cyp01 types and symbols used for parameter checks.
 *         \unit  vMem__core
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#if !defined (VMEM_30_TRAVEO2CYP01_TYPES_H)
# define VMEM_30_TRAVEO2CYP01_TYPES_H

# include "Std_Types.h"
# include "vMemAccM_vMemApi.h"

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef vMemAccM_vMemConstDataPtrType     vMem_30_Traveo2Cyp01_ConstDataPtrType;
typedef vMemAccM_vMemDataPtrType          vMem_30_Traveo2Cyp01_DataPtrType;
typedef vMemAccM_vMemJobResultType        vMem_30_Traveo2Cyp01_JobResultType;

typedef vMemAccM_vMemInstanceIdType       vMem_30_Traveo2Cyp01_InstanceIdType;

/* Used as address offset from the configured nv memory base address to access a certain NV memory memory area */
typedef vMemAccM_vMemAddressType          vMem_30_Traveo2Cyp01_AddressType;

/* Specifies the number of bytes to read/write/erase/compare */
typedef vMemAccM_vMemLengthType           vMem_30_Traveo2Cyp01_LengthType;

/* Specifies the config pointer type for the init service. */
typedef vMemAccM_vMemConfigPtrType        vMem_30_Traveo2Cyp01_ConfigPtrType;


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/* Vendor and module identification */
# define VMEM_30_TRAVEO2CYP01_VENDOR_ID                 (30u)
# define VMEM_30_TRAVEO2CYP01_MODULE_ID                 (0xFFu)
# define VMEM_30_TRAVEO2CYP01_SOLUTION_ID               (0x56u)  /*!< vMem_30_Traveo2Cyp01 solution identifier. Same for all vMems. */

# define VMEM_30_TRAVEO2CYP01_INSTANCE_ID_DET           (0x00u)

# define VMEM_30_TRAVEO2CYP01_SID_INIT                  (0x00u)  /*!< Service ID: vMem_30_Traveo2Cyp01_Init() */
# define VMEM_30_TRAVEO2CYP01_SID_INIT_MEMORY           (0x01u)  /*!< Service ID: vMem_30_Traveo2Cyp01_InitMemory() */
# define VMEM_30_TRAVEO2CYP01_SID_READ                  (0x02u)  /*!< Service ID: vMem_30_Traveo2Cyp01_Read() */
# define VMEM_30_TRAVEO2CYP01_SID_WRITE                 (0x03u)  /*!< Service ID: vMem_30_Traveo2Cyp01_Write() */
# define VMEM_30_TRAVEO2CYP01_SID_ERASE                 (0x04u)  /*!< Service ID: vMem_30_Traveo2Cyp01_Erase() */
# define VMEM_30_TRAVEO2CYP01_SID_MAIN_FUNCTION         (0x05u)  /*!< Service ID: vMem_30_Traveo2Cyp01_MainFunction() */
# define VMEM_30_TRAVEO2CYP01_SID_IS_BLANK              (0x06u)  /*!< Service ID: vMem_30_Traveo2Cyp01_IsBlank() */
# define VMEM_30_TRAVEO2CYP01_SID_GET_JOB_RESULT        (0x0Au)  /*!< Service ID: vMem_30_Traveo2Cyp01_Get_Job_Result() */
# define VMEM_30_TRAVEO2CYP01_SID_GET_VERSION_INFO      (0x10u)  /*!< Service ID: vMem_30_Traveo2Cyp01_GetVersionInfo() */
# define VMEM_30_TRAVEO2CYP01_SID_SETDUALBANKMODE       (0x11u)  /*!< Service ID: vMem_30_Traveo2Cyp01_SetDualBankMode() */
# define VMEM_30_TRAVEO2CYP01_SID_PERFORMMEMORYSWAP     (0x11u)  /*!< Service ID: vMem_30_Traveo2Cyp01_PerformMemorySwap() */

/* ----- Error codes ----- */
# define VMEM_30_TRAVEO2CYP01_E_NO_ERROR                (0x00u)  /*!< used to check if no error occurred - use a value unequal to any error code. */
# define VMEM_30_TRAVEO2CYP01_E_PARAM_CONFIG            (0x0Au)  /*!< Error code: API service called with wrong config parameter. */
# define VMEM_30_TRAVEO2CYP01_E_PARAM_POINTER           (0x0Bu)  /*!< Error code: API service used with invalid pointer parameter (NULL). */
# define VMEM_30_TRAVEO2CYP01_E_PARAM_ADDRESS           (0x0Cu)  /*!< Error code: API service used with invalid address parameter. */
# define VMEM_30_TRAVEO2CYP01_E_PARAM_LENGTH            (0x0Du)  /*!< Error code: API service used with invalid length parameter. */
# define VMEM_30_TRAVEO2CYP01_E_PARAM_BUFFER_ALIGNMENT  (0x0Eu)  /*!< Error code: API service used with invalid buffer parameter. */
# define VMEM_30_TRAVEO2CYP01_E_UNINIT                  (0x10u)  /*!< Error code: API service used without module initialization. */
# define VMEM_30_TRAVEO2CYP01_E_INITIALIZATION_FAILED   (0x11u)  /*!< Error code: No or invalid communication towards the hardware during (re-)initialization.  */
# define VMEM_30_TRAVEO2CYP01_E_PARAM_INSTANCE_ID       (0x12u)  /*!< Error code: API service used with invalid instance identifier parameter. */
# define VMEM_30_TRAVEO2CYP01_E_PENDING                 (0x13u)  /*!< Error code: The requested instance is already pending. */
# define VMEM_30_TRAVEO2CYP01_E_PARAM_FLASH_TYPE        (0x14u)  /*!< Error code: API service used with invalid flash type as requirement specific data.  */

#endif /* VMEM_30_TRAVEO2CYP01_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: vMem_30_Traveo2Cyp01_Types.h
 *********************************************************************************************************************/
