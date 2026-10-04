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
/*!        \file  vMem_30_Traveo2Cyp01_Extended_Func.h
 *        \brief  vMem_30_Traveo2Cyp01 public header file containing types and declarations of the hardware specific
 *                functionality.
 *
 *      \details  This file contains the types and declarations of the hardware specific functionality of
 *                vMem_30_Traveo2Cyp01. It should be included by every user, that wants to call a hardware specific API.
 *         \unit  vMem_LL
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#if !defined (VMEM_30_TRAVEO2CYP01_EXTENDED_FUNC_H)
# define VMEM_30_TRAVEO2CYP01_EXTENDED_FUNC_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/*! Enum type for hardware specific service IDs */
typedef enum
{
  VMEM_30_TRAVEO2CYP01_SETDUALBANKMODE   = 0,  /*!< Id for vMem_30_Traveo2Cyp01_SetDualBankMode. */
  VMEM_30_TRAVEO2CYP01_PERFORMMEMORYSWAP = 1   /*!< Id for vMem_30_Traveo2Cyp01_PerformMemorySwap.  */
} vMem_30_Traveo2Cyp01_HWSpecificFuncID;       /*!< Numeric identifier for HW specific functionality:
                                                 index in function pointer table. */

/*! Enum type for the diferent types of flash areas */
typedef enum
{
  VMEM_30_TRAVEO2CYP01_FLASH_TYPE_CODE = 0u,
  VMEM_30_TRAVEO2CYP01_FLASH_TYPE_WORK = 1u
} vMem_30_Traveo2Cyp01_FlashTypeType;

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

# define VMEM_30_TRAVEO2CYP01_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
# include "vMem_30_Traveo2Cyp01_Types.h"

/**********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_SetDualBankMode()
 *********************************************************************************************************************/
/*!
 * \brief          Sets the dual bank mode.
 * \details        Sets the BANK_MODE bit field of the FLASHC_FLASH_CTL register to '1' and therefor sets the 
 *                 dual bank mode for the requested flash type active. 
 * \param[in]      InstanceId          ID of the related vMem instance.
 * \param[in]      ReqSpecificData     Pointer to a variable of type vMem_30_Traveo2Cyp01_FlashTypeType.
 *                                     Contains the information if main flash or work flash shall be set to dual bank 
 *                                     mode.
 * \param[in]      SizeOfData          Unused parameter. This parameter is predefined by the vMemAccM but is not used 
 *                                     by this hardware specific function.
 * \return         E_OK       Dual bank mode successfully enabled, 
 *                 E_NOT_OK   Otherwise.
 * \pre            -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous FALSE
 * \trace       CREQ-vMem-SetDualBankMode
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_SetDualBankMode(
    vMem_30_Traveo2Cyp01_InstanceIdType InstanceId,
    vMem_30_Traveo2Cyp01_DataPtrType ReqSpecificData,
    vMem_30_Traveo2Cyp01_LengthType SizeOfData
    );

/**********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_PerformMemorySwap()
 *********************************************************************************************************************/
/*!
 * \brief          Performs a memory swap.
 * \details        Swaps the MAP bit of the FLASHC_FLASH_CTL register from 'Mapping A' to 'Mapping B' or reversed for 
 *                 the requested flash type.
 * 
 * \param[in]      InstanceId          ID of the related vMem instance.
 * \param[in]      ReqSpecificData     Pointer to a variable of type vMem_30_Traveo2Cyp01_FlashTypeType.
 *                                     Contains the information if main flash or work flash shall be swapped.
 * \param[in]      SizeOfData          Unused parameter. This parameter is predefined by the vMemAccM but is not used 
 *                                     by this hardware specific function.
 * \return         E_OK       Mapping mode successfully swapped, 
 *                 E_NOT_OK   Otherwise.
 * \pre            -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous FALSE
 * \trace       CREQ-vMem-PerformMemorySwap
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_PerformMemorySwap(
    vMem_30_Traveo2Cyp01_InstanceIdType InstanceId,
    vMem_30_Traveo2Cyp01_DataPtrType ReqSpecificData,
    vMem_30_Traveo2Cyp01_LengthType SizeOfData
    );

# define VMEM_30_TRAVEO2CYP01_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */  /* MD_MSR_MemMap */

#endif /* VMEM_30_TRAVEO2CYP01_EXTENDED_FUNC_H */

/**********************************************************************************************************************
 *  END OF FILE: vMem_30_Traveo2Cyp01_Extended_Func.h
 *********************************************************************************************************************/

