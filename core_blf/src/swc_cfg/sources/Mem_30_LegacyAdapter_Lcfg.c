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
 *            Module: Mem_30_LegacyAdapter
 *           Program: MSR_Geely_SLP2
 *          Customer: Marelli Automotive Electronics (Guangzhou) Co., Ltd
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: CYT2B75BA
 *    License Scope : The usage is restricted to CBD2600619_D00
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Mem_30_LegacyAdapter_Lcfg.c
 *   Generation Time: 2026-07-14 11:05:46
 *           Project: DaVinci_Zeekr_Display - Version 1.0
 *          Delivery: CBD2600619_D00
 *      Tool Version: DaVinci Configurator Classic (beta) 5.31.60 SP6
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

#define MEM_30_LEGACYADAPTER_LCFG_SOURCE

/**********************************************************************************************************************
 * MISRA JUSTIFICATION
 *********************************************************************************************************************/
/* PRQA S 0857 EOF */ /* MD_MSR_1.1_857 */
/* PRQA S 0779 EOF */ /* MD_CSL_0779 */

/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/
#include "Mem_30_LegacyAdapter_Cfg.h"

/**********************************************************************************************************************
  GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  LOCAL FUNCTION PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  LOCAL CONSTANT MACROS
**********************************************************************************************************************/
#if !defined (MEM_30_LEGACYADAPTER_LOCAL)
# define MEM_30_LEGACYADAPTER_LOCAL                            static
#endif
/**********************************************************************************************************************
  LOCAL FUNCTION MACROS
**********************************************************************************************************************/

/**********************************************************************************************************************
  LOCAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/

/**********************************************************************************************************************
  LOCAL API WRAPPER FUNCTIONS
**********************************************************************************************************************/
#define MEM_30_LEGACYADAPTER_START_SEC_CODE_ASIL_D
#include "Mem_30_LegacyAdapter_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern FUNC(Mem_30_LegacyAdapter_JobResultType, MEM_30_LEGACYADAPTER_CODE) Mem_30_LegacyAdapter_LLAdapter_MapVMemJobResult(const vMemAccM_vMemJobResultType jobResult); 

/* Function declarations for vMem_30_Traveo2Cyp01 module. */ 
MEM_30_LEGACYADAPTER_LOCAL FUNC(void, MEM_30_LEGACYADAPTER_CODE) vMem_30_Traveo2Cyp01_InitWrapper(Mem_30_LegacyAdapter_ConfigPtrType configPtr); 
MEM_30_LEGACYADAPTER_LOCAL FUNC(void, MEM_30_LEGACYADAPTER_CODE) vMem_30_Traveo2Cyp01_MainFunctionWrapper(void); 
MEM_30_LEGACYADAPTER_LOCAL FUNC(Std_ReturnType, MEM_30_LEGACYADAPTER_CODE) vMem_30_Traveo2Cyp01_ReadWrapper(const Mem_30_LegacyAdapter_InstanceIdType instanceId, const Mem_30_LegacyAdapter_AddressType sourceAddress, Mem_30_LegacyAdapter_DataPtrType destinationDataPtr, const Mem_30_LegacyAdapter_LengthType length); 
MEM_30_LEGACYADAPTER_LOCAL FUNC(Std_ReturnType, MEM_30_LEGACYADAPTER_CODE) vMem_30_Traveo2Cyp01_WriteWrapper(const Mem_30_LegacyAdapter_InstanceIdType instanceId, const Mem_30_LegacyAdapter_AddressType targetAddress, Mem_30_LegacyAdapter_ConstDataPtrType sourceDataPtr, const Mem_30_LegacyAdapter_LengthType length); 
MEM_30_LEGACYADAPTER_LOCAL FUNC(Std_ReturnType, MEM_30_LEGACYADAPTER_CODE) vMem_30_Traveo2Cyp01_EraseWrapper(const Mem_30_LegacyAdapter_InstanceIdType instanceId, const Mem_30_LegacyAdapter_AddressType targetAddress, const Mem_30_LegacyAdapter_LengthType length); 
MEM_30_LEGACYADAPTER_LOCAL FUNC(Std_ReturnType, MEM_30_LEGACYADAPTER_CODE) vMem_30_Traveo2Cyp01_IsBlankWrapper(const Mem_30_LegacyAdapter_InstanceIdType instanceId, const Mem_30_LegacyAdapter_AddressType targetAddress, const Mem_30_LegacyAdapter_LengthType length); 
MEM_30_LEGACYADAPTER_LOCAL FUNC(Mem_30_LegacyAdapter_JobResultType, MEM_30_LEGACYADAPTER_CODE) vMem_30_Traveo2Cyp01_GetJobResultWrapper(const Mem_30_LegacyAdapter_InstanceIdType instanceId); 

/* vMem function definitions for vMem_30_Traveo2Cyp01 module. */ 
MEM_30_LEGACYADAPTER_LOCAL FUNC(void, MEM_30_LEGACYADAPTER_CODE) vMem_30_Traveo2Cyp01_InitWrapper(Mem_30_LegacyAdapter_ConfigPtrType configPtr) 
{ 
  /* VCA Line+1 SLC-10, SLC-22 : VCA_Mem_30_LegacyAdapter_vMemDrvServiceInvocation */ 
  vMem_30_Traveo2Cyp01_FunctionPointerTable.Init(configPtr); 
} 
MEM_30_LEGACYADAPTER_LOCAL FUNC(void, MEM_30_LEGACYADAPTER_CODE) vMem_30_Traveo2Cyp01_MainFunctionWrapper(void) 
{ 
  /* VCA Line+1 SLC-10, SLC-22 : VCA_Mem_30_LegacyAdapter_vMemDrvServiceInvocation */ 
  vMem_30_Traveo2Cyp01_FunctionPointerTable.MainFunction(); 
} 
MEM_30_LEGACYADAPTER_LOCAL FUNC(Std_ReturnType, MEM_30_LEGACYADAPTER_CODE) vMem_30_Traveo2Cyp01_ReadWrapper(const Mem_30_LegacyAdapter_InstanceIdType instanceId, const Mem_30_LegacyAdapter_AddressType sourceAddress, Mem_30_LegacyAdapter_DataPtrType destinationDataPtr, const Mem_30_LegacyAdapter_LengthType length) 
{ 
  /* VCA Line+1 SLC-10, SLC-22 : VCA_Mem_30_LegacyAdapter_vMemDrvServiceInvocation */ 
  return vMem_30_Traveo2Cyp01_FunctionPointerTable.Read((vMemAccM_vMemInstanceIdType) instanceId, (vMemAccM_vMemAddressType) sourceAddress, (vMemAccM_vMemDataPtrType) destinationDataPtr, (vMemAccM_vMemLengthType) length); 
} 
MEM_30_LEGACYADAPTER_LOCAL FUNC(Std_ReturnType, MEM_30_LEGACYADAPTER_CODE) vMem_30_Traveo2Cyp01_WriteWrapper(const Mem_30_LegacyAdapter_InstanceIdType instanceId, const Mem_30_LegacyAdapter_AddressType targetAddress, Mem_30_LegacyAdapter_ConstDataPtrType sourceDataPtr, const Mem_30_LegacyAdapter_LengthType length) 
{ 
  /* VCA Line+1 SLC-10, SLC-22 : VCA_Mem_30_LegacyAdapter_vMemDrvServiceInvocation */ 
  return vMem_30_Traveo2Cyp01_FunctionPointerTable.Write((vMemAccM_vMemInstanceIdType) instanceId, (vMemAccM_vMemAddressType) targetAddress, (vMemAccM_vMemConstDataPtrType) sourceDataPtr, (vMemAccM_vMemLengthType) length); 
} 
MEM_30_LEGACYADAPTER_LOCAL FUNC(Std_ReturnType, MEM_30_LEGACYADAPTER_CODE) vMem_30_Traveo2Cyp01_EraseWrapper(const Mem_30_LegacyAdapter_InstanceIdType instanceId, const Mem_30_LegacyAdapter_AddressType targetAddress, const Mem_30_LegacyAdapter_LengthType length) 
{ 
  /* VCA Line+1 SLC-10, SLC-22 : VCA_Mem_30_LegacyAdapter_vMemDrvServiceInvocation */ 
  return vMem_30_Traveo2Cyp01_FunctionPointerTable.Erase((vMemAccM_vMemInstanceIdType) instanceId, (vMemAccM_vMemAddressType) targetAddress, (vMemAccM_vMemLengthType) length); 
} 
MEM_30_LEGACYADAPTER_LOCAL FUNC(Std_ReturnType, MEM_30_LEGACYADAPTER_CODE) vMem_30_Traveo2Cyp01_IsBlankWrapper(const Mem_30_LegacyAdapter_InstanceIdType instanceId, const Mem_30_LegacyAdapter_AddressType targetAddress, const Mem_30_LegacyAdapter_LengthType length) 
{ 
  /* VCA Line+1 SLC-10, SLC-22 : VCA_Mem_30_LegacyAdapter_vMemDrvServiceInvocation */ 
  return vMem_30_Traveo2Cyp01_FunctionPointerTable.IsBlank((vMemAccM_vMemInstanceIdType) instanceId, (vMemAccM_vMemAddressType) targetAddress, (vMemAccM_vMemLengthType) length); 
} 
MEM_30_LEGACYADAPTER_LOCAL FUNC(Mem_30_LegacyAdapter_JobResultType, MEM_30_LEGACYADAPTER_CODE) vMem_30_Traveo2Cyp01_GetJobResultWrapper(const Mem_30_LegacyAdapter_InstanceIdType instanceId) 
{ 
  /* VCA Line+1 SLC-10, SLC-22 : VCA_Mem_30_LegacyAdapter_vMemDrvServiceInvocation */ 
  return Mem_30_LegacyAdapter_LLAdapter_MapVMemJobResult(vMem_30_Traveo2Cyp01_FunctionPointerTable.GetJobResult((vMemAccM_vMemInstanceIdType) instanceId)); 
} 


#define MEM_30_LEGACYADAPTER_STOP_SEC_CODE_ASIL_D
#include "Mem_30_LegacyAdapter_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
/**********************************************************************************************************************
  LOCAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: LOCAL DATA PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  LOCAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: LOCAL DATA
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  Mem_30_LegacyAdapter_LLApi
**********************************************************************************************************************/
/** 
  \var    Mem_30_LegacyAdapter_LLApi
  \details
  Element         Description
  Erase       
  GetJobResult
  Init        
  IsBlank     
  MainFunction
  Read        
  Write       
  HwFunctions 
*/ 
#define MEM_30_LEGACYADAPTER_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Mem_30_LegacyAdapter_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Mem_30_LegacyAdapter_LLApiType, MEM_30_LEGACYADAPTER_CONST) Mem_30_LegacyAdapter_LLApi[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Erase                               GetJobResult                               Init                               IsBlank                               MainFunction                               Read                               Write                               HwFunctions                                                   Referable Keys */
  { /*     0 */ &vMem_30_Traveo2Cyp01_EraseWrapper, &vMem_30_Traveo2Cyp01_GetJobResultWrapper, &vMem_30_Traveo2Cyp01_InitWrapper, &vMem_30_Traveo2Cyp01_IsBlankWrapper, &vMem_30_Traveo2Cyp01_MainFunctionWrapper, &vMem_30_Traveo2Cyp01_ReadWrapper, &vMem_30_Traveo2Cyp01_WriteWrapper, &vMem_30_Traveo2Cyp01_FunctionPointerTable.HwFunctions }   /* [vMem_30_Traveo2Cyp01] */
};
#define MEM_30_LEGACYADAPTER_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Mem_30_LegacyAdapter_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL DATA
**********************************************************************************************************************/

/**********************************************************************************************************************
  LOCAL FUNCTIONS
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL FUNCTIONS
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL FUNCTIONS
**********************************************************************************************************************/

/**********************************************************************************************************************
  END OF FILE: Mem_30_LegacyAdapter_Lcfg.c
**********************************************************************************************************************/
