/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                 This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                 Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                 All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  LICENSE
 *  -------------------------------------------------------------------------------------------------------------------
 *            Module: Fee_30_FlexNor
 *           Program: MSR_Geely_SLP2
 *          Customer: Marelli Automotive Electronics (Guangzhou) Co., Ltd
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: CYT2B75BA
 *    License Scope : The usage is restricted to CBD2600619_D00
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Fee_30_FlexNor_MemoryInterface.h
 *   Generation Time: 2026-06-11 12:02:20
 *           Project: DaVinci_Zeekr_Display - Version 1.0
 *          Delivery: CBD2600619_D00
 *      Tool Version: DaVinci Configurator Classic (beta) 5.31.55 SP5
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 ! BETA VERSION                                                                                                       !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 ! This version of DaVinci Configurator Classic and/or the related Basic Software Package is BETA software.               !
 ! BETA Software is basically operable, but not sufficiently tested, verified and/or qualified for use in series      !
 ! production and/or in vehicles operating on public or non-public roads.                                             !
 ! In particular, without limitation, BETA Software may cause unpredictable ECU behavior, may not provide all         !
 ! functions necessary for use in series production and/or may not comply with quality requirements which are         !
 ! necessary according to the state of the art. BETA Software must not be used in series production.                  !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
**********************************************************************************************************************/


#if !defined (FEE_30_FLEXNOR_MEMORYINTERFACE_H)
# define FEE_30_FLEXNOR_MEMORYINTERFACE_H

# include "MemAcc.h"

# define FEE_30_FLEXNOR_MEMACC_ADDRESSAREAID 0


#define FEE_30_FLEXNOR_MEMORY_GETSTATUS() MemAcc_GetJobStatus(FEE_30_FLEXNOR_MEMACC_ADDRESSAREAID) 
#define FEE_30_FLEXNOR_MEMORY_GETJOBRESULT() MemAcc_GetJobResult(FEE_30_FLEXNOR_MEMACC_ADDRESSAREAID) 
#define FEE_30_FLEXNOR_MEMORY_READ(address, dataPtr, length) MemAcc_Read(FEE_30_FLEXNOR_MEMACC_ADDRESSAREAID, address, dataPtr, length) 
#define FEE_30_FLEXNOR_MEMORY_BLANKCHECK(address, length) MemAcc_BlankCheck(FEE_30_FLEXNOR_MEMACC_ADDRESSAREAID, address, length) 
#define FEE_30_FLEXNOR_MEMORY_WRITE(address, dataPtr, length) MemAcc_Write(FEE_30_FLEXNOR_MEMACC_ADDRESSAREAID, address, dataPtr, length) 
#define FEE_30_FLEXNOR_MEMORY_ERASE(address, length) MemAcc_Erase(FEE_30_FLEXNOR_MEMACC_ADDRESSAREAID, address, length) 
#define FEE_30_FLEXNOR_MEMORY_CANCEL() MemAcc_Cancel(FEE_30_FLEXNOR_MEMACC_ADDRESSAREAID) 
#define FEE_30_FLEXNOR_MEMORY_ADDRESS_TYPE MemAcc_AddressType 
#define FEE_30_FLEXNOR_MEMORY_LENGTH_TYPE MemAcc_LengthType 
 

#endif  /* FEE_30_FLEXNOR_MEMORYINTERFACE_H */
/**********************************************************************************************************************
  END OF FILE: Fee_30_FlexNor_MemoryInterface.h
**********************************************************************************************************************/
