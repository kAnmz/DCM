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
 *            Module: NvM
 *           Program: MSR_Geely_SLP2
 *          Customer: Marelli Automotive Electronics (Guangzhou) Co., Ltd
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: CYT2B75BA
 *    License Scope : The usage is restricted to CBD2600619_D00
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: NvM_Cfg.h
 *   Generation Time: 2026-06-11 12:02:22
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


/**********************************************************************************************************************
 * PROTECTION AGAINST MULTIPLE INCLUSION
 *********************************************************************************************************************/
#if (!defined NVM_CFG_H_PUBLIC)
#define NVM_CFG_H_PUBLIC

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Compiler.h"
#include "NvM_InternalTypes.h"

/**********************************************************************************************************************
 * VERSION IDENTIFICATION
 *********************************************************************************************************************/
 /* This is not the sub-package version but a compatibility version, which will only be updated if a change in the
   generator (i.e. generated files) affects the implementation sub-package */
#define NVM_CFG_MAJOR_VERSION    (3u)
#define NVM_CFG_MINOR_VERSION    (6u)
#define NVM_CFG_PATCH_VERSION    (2u)

/* Identification for NvMGen2 to differenciate vs. legacy configuration */
#define NVM_GENERATION_VERSION   (2u)

/**********************************************************************************************************************
  GLOBAL CONSTANT MACROS
**********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: SIZEOF DATA TYPES
**********************************************************************************************************************/
/** 
  \defgroup  NvMPCSizeOfTypes  NvM SizeOf Types (PRE_COMPILE)
  \brief  These type definitions are used for the SizeOf information.
  \{
*/ 
/**   \brief  value based type definition for NvM_SizeOfBackgroundCrcRecalcFsmLib_ProcessingStackElement */
typedef uint8 NvM_SizeOfBackgroundCrcRecalcFsmLib_ProcessingStackElementType;

/**   \brief  value based type definition for NvM_SizeOfBlockDescriptor */
typedef uint8 NvM_SizeOfBlockDescriptorType;

/**   \brief  value based type definition for NvM_SizeOfCrcCompMechanismBuffer_DemAdminDataBlock */
typedef uint8 NvM_SizeOfCrcCompMechanismBuffer_DemAdminDataBlockType;

/**   \brief  value based type definition for NvM_SizeOfCrcCompMechanismBuffer_DemStatusDataBlock */
typedef uint8 NvM_SizeOfCrcCompMechanismBuffer_DemStatusDataBlockType;

/**   \brief  value based type definition for NvM_SizeOfCrcCompMechanismBuffer_NvMConfigBlock */
typedef uint8 NvM_SizeOfCrcCompMechanismBuffer_NvMConfigBlockType;

/**   \brief  value based type definition for NvM_SizeOfCrcCompMechanismBuffer_WDFC_ID_AP_CONNEX */
typedef uint8 NvM_SizeOfCrcCompMechanismBuffer_WDFC_ID_AP_CONNEXType;

/**   \brief  value based type definition for NvM_SizeOfCrcCompMechanismBuffer_WDFC_ID_AP_PARA */
typedef uint8 NvM_SizeOfCrcCompMechanismBuffer_WDFC_ID_AP_PARAType;

/**   \brief  value based type definition for NvM_SizeOfCrcCompMechanismBuffer_WDFC_ID_BOOT_PARA */
typedef uint8 NvM_SizeOfCrcCompMechanismBuffer_WDFC_ID_BOOT_PARAType;

/**   \brief  value based type definition for NvM_SizeOfCrcCompMechanismBuffer_WDFC_ID_CCP */
typedef uint8 NvM_SizeOfCrcCompMechanismBuffer_WDFC_ID_CCPType;

/**   \brief  value based type definition for NvM_SizeOfCrcCompMechanismBuffer_WDFC_ID_DEBUG_DATA */
typedef uint8 NvM_SizeOfCrcCompMechanismBuffer_WDFC_ID_DEBUG_DATAType;

/**   \brief  value based type definition for NvM_SizeOfCrcCompMechanismBuffer_WDFC_ID_DLC */
typedef uint8 NvM_SizeOfCrcCompMechanismBuffer_WDFC_ID_DLCType;

/**   \brief  value based type definition for NvM_SizeOfCrcCompMechanismBuffer_WDFC_ID_DTCTime */
typedef uint8 NvM_SizeOfCrcCompMechanismBuffer_WDFC_ID_DTCTimeType;

/**   \brief  value based type definition for NvM_SizeOfCrcCompMechanismBuffer_WDFC_ID_ECUID_RDI_PROGRAMMING_INFO */
typedef uint8 NvM_SizeOfCrcCompMechanismBuffer_WDFC_ID_ECUID_RDI_PROGRAMMING_INFOType;

/**   \brief  value based type definition for NvM_SizeOfCrcCompMechanismBuffer_WDFC_ID_EOL_HW_VERSION */
typedef uint8 NvM_SizeOfCrcCompMechanismBuffer_WDFC_ID_EOL_HW_VERSIONType;

/**   \brief  value based type definition for NvM_SizeOfCrcCompMechanismBuffer_WDFC_ID_EOL_INFO */
typedef uint8 NvM_SizeOfCrcCompMechanismBuffer_WDFC_ID_EOL_INFOType;

/**   \brief  value based type definition for NvM_SizeOfCrcCompMechanismBuffer_WDFC_ID_EOL_PASSWORD */
typedef uint8 NvM_SizeOfCrcCompMechanismBuffer_WDFC_ID_EOL_PASSWORDType;

/**   \brief  value based type definition for NvM_SizeOfCrcCompMechanismBuffer_WDFC_ID_EOL_SWNUMBER */
typedef uint8 NvM_SizeOfCrcCompMechanismBuffer_WDFC_ID_EOL_SWNUMBERType;

/**   \brief  value based type definition for NvM_SizeOfCrcCompMechanismBuffer_WDFC_ID_FAULT_CODE */
typedef uint8 NvM_SizeOfCrcCompMechanismBuffer_WDFC_ID_FAULT_CODEType;

/**   \brief  value based type definition for NvM_SizeOfCrcCompMechanismBuffer_WDFC_ID_HANDLE_CFG */
typedef uint8 NvM_SizeOfCrcCompMechanismBuffer_WDFC_ID_HANDLE_CFGType;

/**   \brief  value based type definition for NvM_SizeOfCrcCompMechanismBuffer_WDFC_ID_IDENT_BANK */
typedef uint8 NvM_SizeOfCrcCompMechanismBuffer_WDFC_ID_IDENT_BANKType;

/**   \brief  value based type definition for NvM_SizeOfCrcCompMechanismBuffer_WDFC_ID_IDOPTION_SECURITY */
typedef uint8 NvM_SizeOfCrcCompMechanismBuffer_WDFC_ID_IDOPTION_SECURITYType;

/**   \brief  value based type definition for NvM_SizeOfCrcCompMechanismBuffer_WDFC_ID_LAST_FDC */
typedef uint8 NvM_SizeOfCrcCompMechanismBuffer_WDFC_ID_LAST_FDCType;

/**   \brief  value based type definition for NvM_SizeOfCrcCompMechanismBuffer_WDFC_ID_MAX_FDC */
typedef uint8 NvM_SizeOfCrcCompMechanismBuffer_WDFC_ID_MAX_FDCType;

/**   \brief  value based type definition for NvM_SizeOfCrcCompMechanismBuffer_WDFC_ID_MIRROR_CFG */
typedef uint8 NvM_SizeOfCrcCompMechanismBuffer_WDFC_ID_MIRROR_CFGType;

/**   \brief  value based type definition for NvM_SizeOfCrcCompMechanismBuffer_WDFC_ID_MIRROR_OTHER_1 */
typedef uint8 NvM_SizeOfCrcCompMechanismBuffer_WDFC_ID_MIRROR_OTHER_1Type;

/**   \brief  value based type definition for NvM_SizeOfCrcCompMechanismBuffer_WDFC_ID_MIRROR_POS_REC */
typedef uint8 NvM_SizeOfCrcCompMechanismBuffer_WDFC_ID_MIRROR_POS_RECType;

/**   \brief  value based type definition for NvM_SizeOfCrcCompMechanismBuffer_WDFC_ID_MIRROR_ST */
typedef uint8 NvM_SizeOfCrcCompMechanismBuffer_WDFC_ID_MIRROR_STType;

/**   \brief  value based type definition for NvM_SizeOfCrcCompMechanismBuffer_WDFC_ID_PART_NUMBER_GEELY */
typedef uint8 NvM_SizeOfCrcCompMechanismBuffer_WDFC_ID_PART_NUMBER_GEELYType;

/**   \brief  value based type definition for NvM_SizeOfCrcCompMechanismBuffer_WDFC_ID_PMM */
typedef uint8 NvM_SizeOfCrcCompMechanismBuffer_WDFC_ID_PMMType;

/**   \brief  value based type definition for NvM_SizeOfCrcCompMechanismBuffer_WDFC_ID_QCM_FAULT_DATA */
typedef uint8 NvM_SizeOfCrcCompMechanismBuffer_WDFC_ID_QCM_FAULT_DATAType;

/**   \brief  value based type definition for NvM_SizeOfCrcCompMechanismBuffer_WDFC_ID_SECURITY_ACCESS */
typedef uint8 NvM_SizeOfCrcCompMechanismBuffer_WDFC_ID_SECURITY_ACCESSType;

/**   \brief  value based type definition for NvM_SizeOfCrcCompMechanismBuffer_WDFC_ID_SR_PROFILE */
typedef uint8 NvM_SizeOfCrcCompMechanismBuffer_WDFC_ID_SR_PROFILEType;

/**   \brief  value based type definition for NvM_SizeOfCrcCompMechanismBuffer_WDFC_ID_SWP1 */
typedef uint8 NvM_SizeOfCrcCompMechanismBuffer_WDFC_ID_SWP1Type;

/**   \brief  value based type definition for NvM_SizeOfCrcCompMechanismBuffer_WDFC_ID_THPA */
typedef uint8 NvM_SizeOfCrcCompMechanismBuffer_WDFC_ID_THPAType;

/**   \brief  value based type definition for NvM_SizeOfCrcCompMechanismBuffer_WDFC_ID_VEH_CFG */
typedef uint8 NvM_SizeOfCrcCompMechanismBuffer_WDFC_ID_VEH_CFGType;

/**   \brief  value based type definition for NvM_SizeOfCrcCompMechanismBuffer_WDFC_ID_VOL_POWER_MODE_CFG */
typedef uint8 NvM_SizeOfCrcCompMechanismBuffer_WDFC_ID_VOL_POWER_MODE_CFGType;

/**   \brief  value based type definition for NvM_SizeOfCrcCompMechanismBuffer_WDFC_ID_WLC_AP_LEARN */
typedef uint8 NvM_SizeOfCrcCompMechanismBuffer_WDFC_ID_WLC_AP_LEARNType;

/**   \brief  value based type definition for NvM_SizeOfCrcCompMechanismBuffer_WDFC_ID_WL_INFO */
typedef uint8 NvM_SizeOfCrcCompMechanismBuffer_WDFC_ID_WL_INFOType;

/**   \brief  value based type definition for NvM_SizeOfCrcCompMechanismBuffer_WDFC_ID_WL_LOG */
typedef uint8 NvM_SizeOfCrcCompMechanismBuffer_WDFC_ID_WL_LOGType;

/**   \brief  value based type definition for NvM_SizeOfDataIntegrityIntBuffer_DemAdminDataBlock */
typedef uint8 NvM_SizeOfDataIntegrityIntBuffer_DemAdminDataBlockType;

/**   \brief  value based type definition for NvM_SizeOfDataIntegrityIntBuffer_DemStatusDataBlock */
typedef uint8 NvM_SizeOfDataIntegrityIntBuffer_DemStatusDataBlockType;

/**   \brief  value based type definition for NvM_SizeOfDataIntegrityIntBuffer_WDFC_ID_AP_CONNEX */
typedef uint8 NvM_SizeOfDataIntegrityIntBuffer_WDFC_ID_AP_CONNEXType;

/**   \brief  value based type definition for NvM_SizeOfDataIntegrityIntBuffer_WDFC_ID_AP_PARA */
typedef uint8 NvM_SizeOfDataIntegrityIntBuffer_WDFC_ID_AP_PARAType;

/**   \brief  value based type definition for NvM_SizeOfDataIntegrityIntBuffer_WDFC_ID_BOOT_PARA */
typedef uint8 NvM_SizeOfDataIntegrityIntBuffer_WDFC_ID_BOOT_PARAType;

/**   \brief  value based type definition for NvM_SizeOfDataIntegrityIntBuffer_WDFC_ID_CCP */
typedef uint8 NvM_SizeOfDataIntegrityIntBuffer_WDFC_ID_CCPType;

/**   \brief  value based type definition for NvM_SizeOfDataIntegrityIntBuffer_WDFC_ID_DEBUG_DATA */
typedef uint8 NvM_SizeOfDataIntegrityIntBuffer_WDFC_ID_DEBUG_DATAType;

/**   \brief  value based type definition for NvM_SizeOfDataIntegrityIntBuffer_WDFC_ID_DLC */
typedef uint8 NvM_SizeOfDataIntegrityIntBuffer_WDFC_ID_DLCType;

/**   \brief  value based type definition for NvM_SizeOfDataIntegrityIntBuffer_WDFC_ID_DTCTime */
typedef uint8 NvM_SizeOfDataIntegrityIntBuffer_WDFC_ID_DTCTimeType;

/**   \brief  value based type definition for NvM_SizeOfDataIntegrityIntBuffer_WDFC_ID_ECUID_RDI_PROGRAMMING_INFO */
typedef uint8 NvM_SizeOfDataIntegrityIntBuffer_WDFC_ID_ECUID_RDI_PROGRAMMING_INFOType;

/**   \brief  value based type definition for NvM_SizeOfDataIntegrityIntBuffer_WDFC_ID_EOL_HW_VERSION */
typedef uint8 NvM_SizeOfDataIntegrityIntBuffer_WDFC_ID_EOL_HW_VERSIONType;

/**   \brief  value based type definition for NvM_SizeOfDataIntegrityIntBuffer_WDFC_ID_EOL_INFO */
typedef uint8 NvM_SizeOfDataIntegrityIntBuffer_WDFC_ID_EOL_INFOType;

/**   \brief  value based type definition for NvM_SizeOfDataIntegrityIntBuffer_WDFC_ID_EOL_PASSWORD */
typedef uint8 NvM_SizeOfDataIntegrityIntBuffer_WDFC_ID_EOL_PASSWORDType;

/**   \brief  value based type definition for NvM_SizeOfDataIntegrityIntBuffer_WDFC_ID_EOL_SWNUMBER */
typedef uint8 NvM_SizeOfDataIntegrityIntBuffer_WDFC_ID_EOL_SWNUMBERType;

/**   \brief  value based type definition for NvM_SizeOfDataIntegrityIntBuffer_WDFC_ID_FAULT_CODE */
typedef uint8 NvM_SizeOfDataIntegrityIntBuffer_WDFC_ID_FAULT_CODEType;

/**   \brief  value based type definition for NvM_SizeOfDataIntegrityIntBuffer_WDFC_ID_HANDLE_CFG */
typedef uint8 NvM_SizeOfDataIntegrityIntBuffer_WDFC_ID_HANDLE_CFGType;

/**   \brief  value based type definition for NvM_SizeOfDataIntegrityIntBuffer_WDFC_ID_IDENT_BANK */
typedef uint8 NvM_SizeOfDataIntegrityIntBuffer_WDFC_ID_IDENT_BANKType;

/**   \brief  value based type definition for NvM_SizeOfDataIntegrityIntBuffer_WDFC_ID_IDOPTION_SECURITY */
typedef uint8 NvM_SizeOfDataIntegrityIntBuffer_WDFC_ID_IDOPTION_SECURITYType;

/**   \brief  value based type definition for NvM_SizeOfDataIntegrityIntBuffer_WDFC_ID_LAST_FDC */
typedef uint8 NvM_SizeOfDataIntegrityIntBuffer_WDFC_ID_LAST_FDCType;

/**   \brief  value based type definition for NvM_SizeOfDataIntegrityIntBuffer_WDFC_ID_MAX_FDC */
typedef uint8 NvM_SizeOfDataIntegrityIntBuffer_WDFC_ID_MAX_FDCType;

/**   \brief  value based type definition for NvM_SizeOfDataIntegrityIntBuffer_WDFC_ID_MIRROR_CFG */
typedef uint8 NvM_SizeOfDataIntegrityIntBuffer_WDFC_ID_MIRROR_CFGType;

/**   \brief  value based type definition for NvM_SizeOfDataIntegrityIntBuffer_WDFC_ID_MIRROR_OTHER_1 */
typedef uint8 NvM_SizeOfDataIntegrityIntBuffer_WDFC_ID_MIRROR_OTHER_1Type;

/**   \brief  value based type definition for NvM_SizeOfDataIntegrityIntBuffer_WDFC_ID_MIRROR_POS_REC */
typedef uint8 NvM_SizeOfDataIntegrityIntBuffer_WDFC_ID_MIRROR_POS_RECType;

/**   \brief  value based type definition for NvM_SizeOfDataIntegrityIntBuffer_WDFC_ID_MIRROR_ST */
typedef uint8 NvM_SizeOfDataIntegrityIntBuffer_WDFC_ID_MIRROR_STType;

/**   \brief  value based type definition for NvM_SizeOfDataIntegrityIntBuffer_WDFC_ID_PART_NUMBER_GEELY */
typedef uint8 NvM_SizeOfDataIntegrityIntBuffer_WDFC_ID_PART_NUMBER_GEELYType;

/**   \brief  value based type definition for NvM_SizeOfDataIntegrityIntBuffer_WDFC_ID_PMM */
typedef uint8 NvM_SizeOfDataIntegrityIntBuffer_WDFC_ID_PMMType;

/**   \brief  value based type definition for NvM_SizeOfDataIntegrityIntBuffer_WDFC_ID_QCM_FAULT_DATA */
typedef uint8 NvM_SizeOfDataIntegrityIntBuffer_WDFC_ID_QCM_FAULT_DATAType;

/**   \brief  value based type definition for NvM_SizeOfDataIntegrityIntBuffer_WDFC_ID_SECURITY_ACCESS */
typedef uint8 NvM_SizeOfDataIntegrityIntBuffer_WDFC_ID_SECURITY_ACCESSType;

/**   \brief  value based type definition for NvM_SizeOfDataIntegrityIntBuffer_WDFC_ID_SR_PROFILE */
typedef uint8 NvM_SizeOfDataIntegrityIntBuffer_WDFC_ID_SR_PROFILEType;

/**   \brief  value based type definition for NvM_SizeOfDataIntegrityIntBuffer_WDFC_ID_SWP1 */
typedef uint8 NvM_SizeOfDataIntegrityIntBuffer_WDFC_ID_SWP1Type;

/**   \brief  value based type definition for NvM_SizeOfDataIntegrityIntBuffer_WDFC_ID_THPA */
typedef uint8 NvM_SizeOfDataIntegrityIntBuffer_WDFC_ID_THPAType;

/**   \brief  value based type definition for NvM_SizeOfDataIntegrityIntBuffer_WDFC_ID_VEH_CFG */
typedef uint8 NvM_SizeOfDataIntegrityIntBuffer_WDFC_ID_VEH_CFGType;

/**   \brief  value based type definition for NvM_SizeOfDataIntegrityIntBuffer_WDFC_ID_VOL_POWER_MODE_CFG */
typedef uint8 NvM_SizeOfDataIntegrityIntBuffer_WDFC_ID_VOL_POWER_MODE_CFGType;

/**   \brief  value based type definition for NvM_SizeOfDataIntegrityIntBuffer_WDFC_ID_WLC_AP_LEARN */
typedef uint8 NvM_SizeOfDataIntegrityIntBuffer_WDFC_ID_WLC_AP_LEARNType;

/**   \brief  value based type definition for NvM_SizeOfDataIntegrityIntBuffer_WDFC_ID_WL_INFO */
typedef uint8 NvM_SizeOfDataIntegrityIntBuffer_WDFC_ID_WL_INFOType;

/**   \brief  value based type definition for NvM_SizeOfDataIntegrityIntBuffer_WDFC_ID_WL_LOG */
typedef uint8 NvM_SizeOfDataIntegrityIntBuffer_WDFC_ID_WL_LOGType;

/**   \brief  value based type definition for NvM_SizeOfInternalBuffer */
typedef uint16 NvM_SizeOfInternalBufferType;

/**   \brief  value based type definition for NvM_SizeOfMultiBlockFsmLib_ProcessingStackElement */
typedef uint8 NvM_SizeOfMultiBlockFsmLib_ProcessingStackElementType;

/**   \brief  value based type definition for NvM_SizeOfMultiBlockProcessorFsmLib_ProcessingStackElement */
typedef uint8 NvM_SizeOfMultiBlockProcessorFsmLib_ProcessingStackElementType;

/**   \brief  value based type definition for NvM_SizeOfNvServiceFsmLib_ProcessingStackElement */
typedef uint8 NvM_SizeOfNvServiceFsmLib_ProcessingStackElementType;

/**   \brief  value based type definition for NvM_SizeOfNvServiceProcessorFsmLib_ProcessingStackElement */
typedef uint8 NvM_SizeOfNvServiceProcessorFsmLib_ProcessingStackElementType;

/**   \brief  value based type definition for NvM_SizeOfPartitionIdentifiers */
typedef uint8 NvM_SizeOfPartitionIdentifiersType;

/**   \brief  value based type definition for NvM_SizeOfQueueList */
typedef uint8 NvM_SizeOfQueueListType;

/**   \brief  value based type definition for NvM_SizeOfServiceProcessorFsmLib_ProcessingStackElement */
typedef uint8 NvM_SizeOfServiceProcessorFsmLib_ProcessingStackElementType;

/**   \brief  value based type definition for NvM_SizeOfSingleBlockFsmLib_ProcessingStackElement */
typedef uint8 NvM_SizeOfSingleBlockFsmLib_ProcessingStackElementType;

/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  NvMPCIterableTypes  NvM Iterable Types (PRE_COMPILE)
  \brief  These type definitions are used to iterate over an array with least processor cycles for variable access as possible.
  \{
*/ 
/**   \brief  type used to iterate NvM_BackgroundCrcRecalcFsmLib_ProcessingStackElement */
typedef uint8_least NvM_BackgroundCrcRecalcFsmLib_ProcessingStackElementIterType;

/**   \brief  type used to iterate NvM_BlockDescriptor */
typedef uint8_least NvM_BlockDescriptorIterType;

/**   \brief  type used to iterate NvM_CrcCompMechanismBuffer_DemAdminDataBlock */
typedef uint8_least NvM_CrcCompMechanismBuffer_DemAdminDataBlockIterType;

/**   \brief  type used to iterate NvM_CrcCompMechanismBuffer_DemStatusDataBlock */
typedef uint8_least NvM_CrcCompMechanismBuffer_DemStatusDataBlockIterType;

/**   \brief  type used to iterate NvM_CrcCompMechanismBuffer_NvMConfigBlock */
typedef uint8_least NvM_CrcCompMechanismBuffer_NvMConfigBlockIterType;

/**   \brief  type used to iterate NvM_CrcCompMechanismBuffer_WDFC_ID_AP_CONNEX */
typedef uint8_least NvM_CrcCompMechanismBuffer_WDFC_ID_AP_CONNEXIterType;

/**   \brief  type used to iterate NvM_CrcCompMechanismBuffer_WDFC_ID_AP_PARA */
typedef uint8_least NvM_CrcCompMechanismBuffer_WDFC_ID_AP_PARAIterType;

/**   \brief  type used to iterate NvM_CrcCompMechanismBuffer_WDFC_ID_BOOT_PARA */
typedef uint8_least NvM_CrcCompMechanismBuffer_WDFC_ID_BOOT_PARAIterType;

/**   \brief  type used to iterate NvM_CrcCompMechanismBuffer_WDFC_ID_CCP */
typedef uint8_least NvM_CrcCompMechanismBuffer_WDFC_ID_CCPIterType;

/**   \brief  type used to iterate NvM_CrcCompMechanismBuffer_WDFC_ID_DEBUG_DATA */
typedef uint8_least NvM_CrcCompMechanismBuffer_WDFC_ID_DEBUG_DATAIterType;

/**   \brief  type used to iterate NvM_CrcCompMechanismBuffer_WDFC_ID_DLC */
typedef uint8_least NvM_CrcCompMechanismBuffer_WDFC_ID_DLCIterType;

/**   \brief  type used to iterate NvM_CrcCompMechanismBuffer_WDFC_ID_DTCTime */
typedef uint8_least NvM_CrcCompMechanismBuffer_WDFC_ID_DTCTimeIterType;

/**   \brief  type used to iterate NvM_CrcCompMechanismBuffer_WDFC_ID_ECUID_RDI_PROGRAMMING_INFO */
typedef uint8_least NvM_CrcCompMechanismBuffer_WDFC_ID_ECUID_RDI_PROGRAMMING_INFOIterType;

/**   \brief  type used to iterate NvM_CrcCompMechanismBuffer_WDFC_ID_EOL_HW_VERSION */
typedef uint8_least NvM_CrcCompMechanismBuffer_WDFC_ID_EOL_HW_VERSIONIterType;

/**   \brief  type used to iterate NvM_CrcCompMechanismBuffer_WDFC_ID_EOL_INFO */
typedef uint8_least NvM_CrcCompMechanismBuffer_WDFC_ID_EOL_INFOIterType;

/**   \brief  type used to iterate NvM_CrcCompMechanismBuffer_WDFC_ID_EOL_PASSWORD */
typedef uint8_least NvM_CrcCompMechanismBuffer_WDFC_ID_EOL_PASSWORDIterType;

/**   \brief  type used to iterate NvM_CrcCompMechanismBuffer_WDFC_ID_EOL_SWNUMBER */
typedef uint8_least NvM_CrcCompMechanismBuffer_WDFC_ID_EOL_SWNUMBERIterType;

/**   \brief  type used to iterate NvM_CrcCompMechanismBuffer_WDFC_ID_FAULT_CODE */
typedef uint8_least NvM_CrcCompMechanismBuffer_WDFC_ID_FAULT_CODEIterType;

/**   \brief  type used to iterate NvM_CrcCompMechanismBuffer_WDFC_ID_HANDLE_CFG */
typedef uint8_least NvM_CrcCompMechanismBuffer_WDFC_ID_HANDLE_CFGIterType;

/**   \brief  type used to iterate NvM_CrcCompMechanismBuffer_WDFC_ID_IDENT_BANK */
typedef uint8_least NvM_CrcCompMechanismBuffer_WDFC_ID_IDENT_BANKIterType;

/**   \brief  type used to iterate NvM_CrcCompMechanismBuffer_WDFC_ID_IDOPTION_SECURITY */
typedef uint8_least NvM_CrcCompMechanismBuffer_WDFC_ID_IDOPTION_SECURITYIterType;

/**   \brief  type used to iterate NvM_CrcCompMechanismBuffer_WDFC_ID_LAST_FDC */
typedef uint8_least NvM_CrcCompMechanismBuffer_WDFC_ID_LAST_FDCIterType;

/**   \brief  type used to iterate NvM_CrcCompMechanismBuffer_WDFC_ID_MAX_FDC */
typedef uint8_least NvM_CrcCompMechanismBuffer_WDFC_ID_MAX_FDCIterType;

/**   \brief  type used to iterate NvM_CrcCompMechanismBuffer_WDFC_ID_MIRROR_CFG */
typedef uint8_least NvM_CrcCompMechanismBuffer_WDFC_ID_MIRROR_CFGIterType;

/**   \brief  type used to iterate NvM_CrcCompMechanismBuffer_WDFC_ID_MIRROR_OTHER_1 */
typedef uint8_least NvM_CrcCompMechanismBuffer_WDFC_ID_MIRROR_OTHER_1IterType;

/**   \brief  type used to iterate NvM_CrcCompMechanismBuffer_WDFC_ID_MIRROR_POS_REC */
typedef uint8_least NvM_CrcCompMechanismBuffer_WDFC_ID_MIRROR_POS_RECIterType;

/**   \brief  type used to iterate NvM_CrcCompMechanismBuffer_WDFC_ID_MIRROR_ST */
typedef uint8_least NvM_CrcCompMechanismBuffer_WDFC_ID_MIRROR_STIterType;

/**   \brief  type used to iterate NvM_CrcCompMechanismBuffer_WDFC_ID_PART_NUMBER_GEELY */
typedef uint8_least NvM_CrcCompMechanismBuffer_WDFC_ID_PART_NUMBER_GEELYIterType;

/**   \brief  type used to iterate NvM_CrcCompMechanismBuffer_WDFC_ID_PMM */
typedef uint8_least NvM_CrcCompMechanismBuffer_WDFC_ID_PMMIterType;

/**   \brief  type used to iterate NvM_CrcCompMechanismBuffer_WDFC_ID_QCM_FAULT_DATA */
typedef uint8_least NvM_CrcCompMechanismBuffer_WDFC_ID_QCM_FAULT_DATAIterType;

/**   \brief  type used to iterate NvM_CrcCompMechanismBuffer_WDFC_ID_SECURITY_ACCESS */
typedef uint8_least NvM_CrcCompMechanismBuffer_WDFC_ID_SECURITY_ACCESSIterType;

/**   \brief  type used to iterate NvM_CrcCompMechanismBuffer_WDFC_ID_SR_PROFILE */
typedef uint8_least NvM_CrcCompMechanismBuffer_WDFC_ID_SR_PROFILEIterType;

/**   \brief  type used to iterate NvM_CrcCompMechanismBuffer_WDFC_ID_SWP1 */
typedef uint8_least NvM_CrcCompMechanismBuffer_WDFC_ID_SWP1IterType;

/**   \brief  type used to iterate NvM_CrcCompMechanismBuffer_WDFC_ID_THPA */
typedef uint8_least NvM_CrcCompMechanismBuffer_WDFC_ID_THPAIterType;

/**   \brief  type used to iterate NvM_CrcCompMechanismBuffer_WDFC_ID_VEH_CFG */
typedef uint8_least NvM_CrcCompMechanismBuffer_WDFC_ID_VEH_CFGIterType;

/**   \brief  type used to iterate NvM_CrcCompMechanismBuffer_WDFC_ID_VOL_POWER_MODE_CFG */
typedef uint8_least NvM_CrcCompMechanismBuffer_WDFC_ID_VOL_POWER_MODE_CFGIterType;

/**   \brief  type used to iterate NvM_CrcCompMechanismBuffer_WDFC_ID_WLC_AP_LEARN */
typedef uint8_least NvM_CrcCompMechanismBuffer_WDFC_ID_WLC_AP_LEARNIterType;

/**   \brief  type used to iterate NvM_CrcCompMechanismBuffer_WDFC_ID_WL_INFO */
typedef uint8_least NvM_CrcCompMechanismBuffer_WDFC_ID_WL_INFOIterType;

/**   \brief  type used to iterate NvM_CrcCompMechanismBuffer_WDFC_ID_WL_LOG */
typedef uint8_least NvM_CrcCompMechanismBuffer_WDFC_ID_WL_LOGIterType;

/**   \brief  type used to iterate NvM_DataIntegrityIntBuffer_DemAdminDataBlock */
typedef uint8_least NvM_DataIntegrityIntBuffer_DemAdminDataBlockIterType;

/**   \brief  type used to iterate NvM_DataIntegrityIntBuffer_DemStatusDataBlock */
typedef uint8_least NvM_DataIntegrityIntBuffer_DemStatusDataBlockIterType;

/**   \brief  type used to iterate NvM_DataIntegrityIntBuffer_WDFC_ID_AP_CONNEX */
typedef uint8_least NvM_DataIntegrityIntBuffer_WDFC_ID_AP_CONNEXIterType;

/**   \brief  type used to iterate NvM_DataIntegrityIntBuffer_WDFC_ID_AP_PARA */
typedef uint8_least NvM_DataIntegrityIntBuffer_WDFC_ID_AP_PARAIterType;

/**   \brief  type used to iterate NvM_DataIntegrityIntBuffer_WDFC_ID_BOOT_PARA */
typedef uint8_least NvM_DataIntegrityIntBuffer_WDFC_ID_BOOT_PARAIterType;

/**   \brief  type used to iterate NvM_DataIntegrityIntBuffer_WDFC_ID_CCP */
typedef uint8_least NvM_DataIntegrityIntBuffer_WDFC_ID_CCPIterType;

/**   \brief  type used to iterate NvM_DataIntegrityIntBuffer_WDFC_ID_DEBUG_DATA */
typedef uint8_least NvM_DataIntegrityIntBuffer_WDFC_ID_DEBUG_DATAIterType;

/**   \brief  type used to iterate NvM_DataIntegrityIntBuffer_WDFC_ID_DLC */
typedef uint8_least NvM_DataIntegrityIntBuffer_WDFC_ID_DLCIterType;

/**   \brief  type used to iterate NvM_DataIntegrityIntBuffer_WDFC_ID_DTCTime */
typedef uint8_least NvM_DataIntegrityIntBuffer_WDFC_ID_DTCTimeIterType;

/**   \brief  type used to iterate NvM_DataIntegrityIntBuffer_WDFC_ID_ECUID_RDI_PROGRAMMING_INFO */
typedef uint8_least NvM_DataIntegrityIntBuffer_WDFC_ID_ECUID_RDI_PROGRAMMING_INFOIterType;

/**   \brief  type used to iterate NvM_DataIntegrityIntBuffer_WDFC_ID_EOL_HW_VERSION */
typedef uint8_least NvM_DataIntegrityIntBuffer_WDFC_ID_EOL_HW_VERSIONIterType;

/**   \brief  type used to iterate NvM_DataIntegrityIntBuffer_WDFC_ID_EOL_INFO */
typedef uint8_least NvM_DataIntegrityIntBuffer_WDFC_ID_EOL_INFOIterType;

/**   \brief  type used to iterate NvM_DataIntegrityIntBuffer_WDFC_ID_EOL_PASSWORD */
typedef uint8_least NvM_DataIntegrityIntBuffer_WDFC_ID_EOL_PASSWORDIterType;

/**   \brief  type used to iterate NvM_DataIntegrityIntBuffer_WDFC_ID_EOL_SWNUMBER */
typedef uint8_least NvM_DataIntegrityIntBuffer_WDFC_ID_EOL_SWNUMBERIterType;

/**   \brief  type used to iterate NvM_DataIntegrityIntBuffer_WDFC_ID_FAULT_CODE */
typedef uint8_least NvM_DataIntegrityIntBuffer_WDFC_ID_FAULT_CODEIterType;

/**   \brief  type used to iterate NvM_DataIntegrityIntBuffer_WDFC_ID_HANDLE_CFG */
typedef uint8_least NvM_DataIntegrityIntBuffer_WDFC_ID_HANDLE_CFGIterType;

/**   \brief  type used to iterate NvM_DataIntegrityIntBuffer_WDFC_ID_IDENT_BANK */
typedef uint8_least NvM_DataIntegrityIntBuffer_WDFC_ID_IDENT_BANKIterType;

/**   \brief  type used to iterate NvM_DataIntegrityIntBuffer_WDFC_ID_IDOPTION_SECURITY */
typedef uint8_least NvM_DataIntegrityIntBuffer_WDFC_ID_IDOPTION_SECURITYIterType;

/**   \brief  type used to iterate NvM_DataIntegrityIntBuffer_WDFC_ID_LAST_FDC */
typedef uint8_least NvM_DataIntegrityIntBuffer_WDFC_ID_LAST_FDCIterType;

/**   \brief  type used to iterate NvM_DataIntegrityIntBuffer_WDFC_ID_MAX_FDC */
typedef uint8_least NvM_DataIntegrityIntBuffer_WDFC_ID_MAX_FDCIterType;

/**   \brief  type used to iterate NvM_DataIntegrityIntBuffer_WDFC_ID_MIRROR_CFG */
typedef uint8_least NvM_DataIntegrityIntBuffer_WDFC_ID_MIRROR_CFGIterType;

/**   \brief  type used to iterate NvM_DataIntegrityIntBuffer_WDFC_ID_MIRROR_OTHER_1 */
typedef uint8_least NvM_DataIntegrityIntBuffer_WDFC_ID_MIRROR_OTHER_1IterType;

/**   \brief  type used to iterate NvM_DataIntegrityIntBuffer_WDFC_ID_MIRROR_POS_REC */
typedef uint8_least NvM_DataIntegrityIntBuffer_WDFC_ID_MIRROR_POS_RECIterType;

/**   \brief  type used to iterate NvM_DataIntegrityIntBuffer_WDFC_ID_MIRROR_ST */
typedef uint8_least NvM_DataIntegrityIntBuffer_WDFC_ID_MIRROR_STIterType;

/**   \brief  type used to iterate NvM_DataIntegrityIntBuffer_WDFC_ID_PART_NUMBER_GEELY */
typedef uint8_least NvM_DataIntegrityIntBuffer_WDFC_ID_PART_NUMBER_GEELYIterType;

/**   \brief  type used to iterate NvM_DataIntegrityIntBuffer_WDFC_ID_PMM */
typedef uint8_least NvM_DataIntegrityIntBuffer_WDFC_ID_PMMIterType;

/**   \brief  type used to iterate NvM_DataIntegrityIntBuffer_WDFC_ID_QCM_FAULT_DATA */
typedef uint8_least NvM_DataIntegrityIntBuffer_WDFC_ID_QCM_FAULT_DATAIterType;

/**   \brief  type used to iterate NvM_DataIntegrityIntBuffer_WDFC_ID_SECURITY_ACCESS */
typedef uint8_least NvM_DataIntegrityIntBuffer_WDFC_ID_SECURITY_ACCESSIterType;

/**   \brief  type used to iterate NvM_DataIntegrityIntBuffer_WDFC_ID_SR_PROFILE */
typedef uint8_least NvM_DataIntegrityIntBuffer_WDFC_ID_SR_PROFILEIterType;

/**   \brief  type used to iterate NvM_DataIntegrityIntBuffer_WDFC_ID_SWP1 */
typedef uint8_least NvM_DataIntegrityIntBuffer_WDFC_ID_SWP1IterType;

/**   \brief  type used to iterate NvM_DataIntegrityIntBuffer_WDFC_ID_THPA */
typedef uint8_least NvM_DataIntegrityIntBuffer_WDFC_ID_THPAIterType;

/**   \brief  type used to iterate NvM_DataIntegrityIntBuffer_WDFC_ID_VEH_CFG */
typedef uint8_least NvM_DataIntegrityIntBuffer_WDFC_ID_VEH_CFGIterType;

/**   \brief  type used to iterate NvM_DataIntegrityIntBuffer_WDFC_ID_VOL_POWER_MODE_CFG */
typedef uint8_least NvM_DataIntegrityIntBuffer_WDFC_ID_VOL_POWER_MODE_CFGIterType;

/**   \brief  type used to iterate NvM_DataIntegrityIntBuffer_WDFC_ID_WLC_AP_LEARN */
typedef uint8_least NvM_DataIntegrityIntBuffer_WDFC_ID_WLC_AP_LEARNIterType;

/**   \brief  type used to iterate NvM_DataIntegrityIntBuffer_WDFC_ID_WL_INFO */
typedef uint8_least NvM_DataIntegrityIntBuffer_WDFC_ID_WL_INFOIterType;

/**   \brief  type used to iterate NvM_DataIntegrityIntBuffer_WDFC_ID_WL_LOG */
typedef uint8_least NvM_DataIntegrityIntBuffer_WDFC_ID_WL_LOGIterType;

/**   \brief  type used to iterate NvM_InternalBuffer */
typedef uint16_least NvM_InternalBufferIterType;

/**   \brief  type used to iterate NvM_MultiBlockFsmLib_ProcessingStackElement */
typedef uint8_least NvM_MultiBlockFsmLib_ProcessingStackElementIterType;

/**   \brief  type used to iterate NvM_MultiBlockProcessorFsmLib_ProcessingStackElement */
typedef uint8_least NvM_MultiBlockProcessorFsmLib_ProcessingStackElementIterType;

/**   \brief  type used to iterate NvM_NvServiceFsmLib_ProcessingStackElement */
typedef uint8_least NvM_NvServiceFsmLib_ProcessingStackElementIterType;

/**   \brief  type used to iterate NvM_NvServiceProcessorFsmLib_ProcessingStackElement */
typedef uint8_least NvM_NvServiceProcessorFsmLib_ProcessingStackElementIterType;

/**   \brief  type used to iterate NvM_PartitionIdentifiers */
typedef uint8_least NvM_PartitionIdentifiersIterType;

/**   \brief  type used to iterate NvM_QueueList */
typedef uint8_least NvM_QueueListIterType;

/**   \brief  type used to iterate NvM_ServiceProcessorFsmLib_ProcessingStackElement */
typedef uint8_least NvM_ServiceProcessorFsmLib_ProcessingStackElementIterType;

/**   \brief  type used to iterate NvM_SingleBlockFsmLib_ProcessingStackElement */
typedef uint8_least NvM_SingleBlockFsmLib_ProcessingStackElementIterType;

/**   \brief  type used to iterate NvM_PCPartitionConfig */
typedef uint8_least NvM_PCPartitionConfigIterType;

/** 
  \}
*/ 

/** 
  \defgroup  NvMPCValueTypes  NvM Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value based data representations.
  \{
*/ 
/**   \brief  value based type definition for NvM_PCPartitionConfigIdxOfPartitionIdentifiers */
typedef uint8 NvM_PCPartitionConfigIdxOfPartitionIdentifiersType;

/**   \brief  value based type definition for NvM_PartitionSNVOfPartitionIdentifiers */
typedef uint32 NvM_PartitionSNVOfPartitionIdentifiersType;

/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  NvMPCStructTypes  NvM Struct Types (PRE_COMPILE)
  \brief  These type definitions are used for structured data representations.
  \{
*/ 
/**   \brief  type used in NvM_PartitionIdentifiers */
typedef struct sNvM_PartitionIdentifiersType
{
  NvM_PartitionSNVOfPartitionIdentifiersType PartitionSNVOfPartitionIdentifiers;
  NvM_PCPartitionConfigIdxOfPartitionIdentifiersType PCPartitionConfigIdxOfPartitionIdentifiers;  /**< the index of the 1:1 relation pointing to NvM_PCPartitionConfig */
} NvM_PartitionIdentifiersType;

/** 
  \}
*/ 

/** 
  \defgroup  NvMPCRootPointerTypes  NvM Root Pointer Types (PRE_COMPILE)
  \brief  These type definitions are used to point from the config root to symbol instances.
  \{
*/ 
/**   \brief  type used to point to NvM_BackgroundCrcRecalcFsmLib_Instance */
typedef P2VAR(NvM_FsmLib_InstanceType, TYPEDEF, NVM_VAR_NO_INIT) NvM_BackgroundCrcRecalcFsmLib_InstancePtrType;

/**   \brief  type used to point to NvM_BackgroundCrcRecalcFsmLib_ProcessingStackElement */
typedef P2VAR(NvM_FsmLib_ProcessingStackElementType, TYPEDEF, NVM_VAR_NO_INIT) NvM_BackgroundCrcRecalcFsmLib_ProcessingStackElementPtrType;

/**   \brief  type used to point to NvM_BackgroundCrcRecalcFsm_Context */
typedef P2VAR(NvM_BackgroundCrcRecalcFsm_ContextType, TYPEDEF, NVM_VAR_NO_INIT) NvM_BackgroundCrcRecalcFsm_ContextPtrType;

/**   \brief  type used to point to NvM_BackgroundCrcRecalcFsm_Instance */
typedef P2VAR(NvM_FsmType, TYPEDEF, NVM_VAR_NO_INIT) NvM_BackgroundCrcRecalcFsm_InstancePtrType;

/**   \brief  type used to point to NvM_BackgroundDataIntegrityService_Instance */
typedef P2VAR(NvM_DataIntegrityService_InstanceType, TYPEDEF, NVM_VAR_NO_INIT) NvM_BackgroundDataIntegrityService_InstancePtrType;

/**   \brief  type used to point to NvM_BlockDescriptor */
typedef P2CONST(NvM_BlockDescriptorType, TYPEDEF, NVM_CONST) NvM_BlockDescriptorPtrType;

/**   \brief  type used to point to NvM_BlockManagementInfo_DemAdminDataBlock */
typedef P2VAR(NvM_BlockManagementInformationType, TYPEDEF, NVM_VAR_NO_INIT) NvM_BlockManagementInfo_DemAdminDataBlockPtrType;

/**   \brief  type used to point to NvM_BlockManagementInfo_DemStatusDataBlock */
typedef P2VAR(NvM_BlockManagementInformationType, TYPEDEF, NVM_VAR_NO_INIT) NvM_BlockManagementInfo_DemStatusDataBlockPtrType;

/**   \brief  type used to point to NvM_BlockManagementInfo_NvMConfigBlock */
typedef P2VAR(NvM_BlockManagementInformationType, TYPEDEF, NVM_VAR_NO_INIT) NvM_BlockManagementInfo_NvMConfigBlockPtrType;

/**   \brief  type used to point to NvM_BlockManagementInfo_NvMMultiBlock */
typedef P2VAR(NvM_BlockManagementInformationType, TYPEDEF, NVM_VAR_NO_INIT) NvM_BlockManagementInfo_NvMMultiBlockPtrType;

/**   \brief  type used to point to NvM_BlockManagementInfo_WDFC_ID_AP_CONNEX */
typedef P2VAR(NvM_BlockManagementInformationType, TYPEDEF, NVM_VAR_NO_INIT) NvM_BlockManagementInfo_WDFC_ID_AP_CONNEXPtrType;

/**   \brief  type used to point to NvM_BlockManagementInfo_WDFC_ID_AP_PARA */
typedef P2VAR(NvM_BlockManagementInformationType, TYPEDEF, NVM_VAR_NO_INIT) NvM_BlockManagementInfo_WDFC_ID_AP_PARAPtrType;

/**   \brief  type used to point to NvM_BlockManagementInfo_WDFC_ID_BOOT_PARA */
typedef P2VAR(NvM_BlockManagementInformationType, TYPEDEF, NVM_VAR_NO_INIT) NvM_BlockManagementInfo_WDFC_ID_BOOT_PARAPtrType;

/**   \brief  type used to point to NvM_BlockManagementInfo_WDFC_ID_CCP */
typedef P2VAR(NvM_BlockManagementInformationType, TYPEDEF, NVM_VAR_NO_INIT) NvM_BlockManagementInfo_WDFC_ID_CCPPtrType;

/**   \brief  type used to point to NvM_BlockManagementInfo_WDFC_ID_DEBUG_DATA */
typedef P2VAR(NvM_BlockManagementInformationType, TYPEDEF, NVM_VAR_NO_INIT) NvM_BlockManagementInfo_WDFC_ID_DEBUG_DATAPtrType;

/**   \brief  type used to point to NvM_BlockManagementInfo_WDFC_ID_DLC */
typedef P2VAR(NvM_BlockManagementInformationType, TYPEDEF, NVM_VAR_NO_INIT) NvM_BlockManagementInfo_WDFC_ID_DLCPtrType;

/**   \brief  type used to point to NvM_BlockManagementInfo_WDFC_ID_DTCTime */
typedef P2VAR(NvM_BlockManagementInformationType, TYPEDEF, NVM_VAR_NO_INIT) NvM_BlockManagementInfo_WDFC_ID_DTCTimePtrType;

/**   \brief  type used to point to NvM_BlockManagementInfo_WDFC_ID_ECUID_RDI_PROGRAMMING_INFO */
typedef P2VAR(NvM_BlockManagementInformationType, TYPEDEF, NVM_VAR_NO_INIT) NvM_BlockManagementInfo_WDFC_ID_ECUID_RDI_PROGRAMMING_INFOPtrType;

/**   \brief  type used to point to NvM_BlockManagementInfo_WDFC_ID_EOL_HW_VERSION */
typedef P2VAR(NvM_BlockManagementInformationType, TYPEDEF, NVM_VAR_NO_INIT) NvM_BlockManagementInfo_WDFC_ID_EOL_HW_VERSIONPtrType;

/**   \brief  type used to point to NvM_BlockManagementInfo_WDFC_ID_EOL_INFO */
typedef P2VAR(NvM_BlockManagementInformationType, TYPEDEF, NVM_VAR_NO_INIT) NvM_BlockManagementInfo_WDFC_ID_EOL_INFOPtrType;

/**   \brief  type used to point to NvM_BlockManagementInfo_WDFC_ID_EOL_PASSWORD */
typedef P2VAR(NvM_BlockManagementInformationType, TYPEDEF, NVM_VAR_NO_INIT) NvM_BlockManagementInfo_WDFC_ID_EOL_PASSWORDPtrType;

/**   \brief  type used to point to NvM_BlockManagementInfo_WDFC_ID_EOL_SWNUMBER */
typedef P2VAR(NvM_BlockManagementInformationType, TYPEDEF, NVM_VAR_NO_INIT) NvM_BlockManagementInfo_WDFC_ID_EOL_SWNUMBERPtrType;

/**   \brief  type used to point to NvM_BlockManagementInfo_WDFC_ID_FAULT_CODE */
typedef P2VAR(NvM_BlockManagementInformationType, TYPEDEF, NVM_VAR_NO_INIT) NvM_BlockManagementInfo_WDFC_ID_FAULT_CODEPtrType;

/**   \brief  type used to point to NvM_BlockManagementInfo_WDFC_ID_HANDLE_CFG */
typedef P2VAR(NvM_BlockManagementInformationType, TYPEDEF, NVM_VAR_NO_INIT) NvM_BlockManagementInfo_WDFC_ID_HANDLE_CFGPtrType;

/**   \brief  type used to point to NvM_BlockManagementInfo_WDFC_ID_IDENT_BANK */
typedef P2VAR(NvM_BlockManagementInformationType, TYPEDEF, NVM_VAR_NO_INIT) NvM_BlockManagementInfo_WDFC_ID_IDENT_BANKPtrType;

/**   \brief  type used to point to NvM_BlockManagementInfo_WDFC_ID_IDOPTION_SECURITY */
typedef P2VAR(NvM_BlockManagementInformationType, TYPEDEF, NVM_VAR_NO_INIT) NvM_BlockManagementInfo_WDFC_ID_IDOPTION_SECURITYPtrType;

/**   \brief  type used to point to NvM_BlockManagementInfo_WDFC_ID_LAST_FDC */
typedef P2VAR(NvM_BlockManagementInformationType, TYPEDEF, NVM_VAR_NO_INIT) NvM_BlockManagementInfo_WDFC_ID_LAST_FDCPtrType;

/**   \brief  type used to point to NvM_BlockManagementInfo_WDFC_ID_MAX_FDC */
typedef P2VAR(NvM_BlockManagementInformationType, TYPEDEF, NVM_VAR_NO_INIT) NvM_BlockManagementInfo_WDFC_ID_MAX_FDCPtrType;

/**   \brief  type used to point to NvM_BlockManagementInfo_WDFC_ID_MIRROR_CFG */
typedef P2VAR(NvM_BlockManagementInformationType, TYPEDEF, NVM_VAR_NO_INIT) NvM_BlockManagementInfo_WDFC_ID_MIRROR_CFGPtrType;

/**   \brief  type used to point to NvM_BlockManagementInfo_WDFC_ID_MIRROR_OTHER_1 */
typedef P2VAR(NvM_BlockManagementInformationType, TYPEDEF, NVM_VAR_NO_INIT) NvM_BlockManagementInfo_WDFC_ID_MIRROR_OTHER_1PtrType;

/**   \brief  type used to point to NvM_BlockManagementInfo_WDFC_ID_MIRROR_POS_REC */
typedef P2VAR(NvM_BlockManagementInformationType, TYPEDEF, NVM_VAR_NO_INIT) NvM_BlockManagementInfo_WDFC_ID_MIRROR_POS_RECPtrType;

/**   \brief  type used to point to NvM_BlockManagementInfo_WDFC_ID_MIRROR_ST */
typedef P2VAR(NvM_BlockManagementInformationType, TYPEDEF, NVM_VAR_NO_INIT) NvM_BlockManagementInfo_WDFC_ID_MIRROR_STPtrType;

/**   \brief  type used to point to NvM_BlockManagementInfo_WDFC_ID_PART_NUMBER_GEELY */
typedef P2VAR(NvM_BlockManagementInformationType, TYPEDEF, NVM_VAR_NO_INIT) NvM_BlockManagementInfo_WDFC_ID_PART_NUMBER_GEELYPtrType;

/**   \brief  type used to point to NvM_BlockManagementInfo_WDFC_ID_PMM */
typedef P2VAR(NvM_BlockManagementInformationType, TYPEDEF, NVM_VAR_NO_INIT) NvM_BlockManagementInfo_WDFC_ID_PMMPtrType;

/**   \brief  type used to point to NvM_BlockManagementInfo_WDFC_ID_QCM_FAULT_DATA */
typedef P2VAR(NvM_BlockManagementInformationType, TYPEDEF, NVM_VAR_NO_INIT) NvM_BlockManagementInfo_WDFC_ID_QCM_FAULT_DATAPtrType;

/**   \brief  type used to point to NvM_BlockManagementInfo_WDFC_ID_SECURITY_ACCESS */
typedef P2VAR(NvM_BlockManagementInformationType, TYPEDEF, NVM_VAR_NO_INIT) NvM_BlockManagementInfo_WDFC_ID_SECURITY_ACCESSPtrType;

/**   \brief  type used to point to NvM_BlockManagementInfo_WDFC_ID_SR_PROFILE */
typedef P2VAR(NvM_BlockManagementInformationType, TYPEDEF, NVM_VAR_NO_INIT) NvM_BlockManagementInfo_WDFC_ID_SR_PROFILEPtrType;

/**   \brief  type used to point to NvM_BlockManagementInfo_WDFC_ID_SWP1 */
typedef P2VAR(NvM_BlockManagementInformationType, TYPEDEF, NVM_VAR_NO_INIT) NvM_BlockManagementInfo_WDFC_ID_SWP1PtrType;

/**   \brief  type used to point to NvM_BlockManagementInfo_WDFC_ID_THPA */
typedef P2VAR(NvM_BlockManagementInformationType, TYPEDEF, NVM_VAR_NO_INIT) NvM_BlockManagementInfo_WDFC_ID_THPAPtrType;

/**   \brief  type used to point to NvM_BlockManagementInfo_WDFC_ID_VEH_CFG */
typedef P2VAR(NvM_BlockManagementInformationType, TYPEDEF, NVM_VAR_NO_INIT) NvM_BlockManagementInfo_WDFC_ID_VEH_CFGPtrType;

/**   \brief  type used to point to NvM_BlockManagementInfo_WDFC_ID_VOL_POWER_MODE_CFG */
typedef P2VAR(NvM_BlockManagementInformationType, TYPEDEF, NVM_VAR_NO_INIT) NvM_BlockManagementInfo_WDFC_ID_VOL_POWER_MODE_CFGPtrType;

/**   \brief  type used to point to NvM_BlockManagementInfo_WDFC_ID_WLC_AP_LEARN */
typedef P2VAR(NvM_BlockManagementInformationType, TYPEDEF, NVM_VAR_NO_INIT) NvM_BlockManagementInfo_WDFC_ID_WLC_AP_LEARNPtrType;

/**   \brief  type used to point to NvM_BlockManagementInfo_WDFC_ID_WL_INFO */
typedef P2VAR(NvM_BlockManagementInformationType, TYPEDEF, NVM_VAR_NO_INIT) NvM_BlockManagementInfo_WDFC_ID_WL_INFOPtrType;

/**   \brief  type used to point to NvM_BlockManagementInfo_WDFC_ID_WL_LOG */
typedef P2VAR(NvM_BlockManagementInformationType, TYPEDEF, NVM_VAR_NO_INIT) NvM_BlockManagementInfo_WDFC_ID_WL_LOGPtrType;

/**   \brief  type used to point to NvM_CrcCompMechanismBuffer_DemAdminDataBlock */
typedef P2VAR(NvM_DataType, TYPEDEF, NVM_VAR_NO_INIT) NvM_CrcCompMechanismBuffer_DemAdminDataBlockPtrType;

/**   \brief  type used to point to NvM_CrcCompMechanismBuffer_DemStatusDataBlock */
typedef P2VAR(NvM_DataType, TYPEDEF, NVM_VAR_NO_INIT) NvM_CrcCompMechanismBuffer_DemStatusDataBlockPtrType;

/**   \brief  type used to point to NvM_CrcCompMechanismBuffer_NvMConfigBlock */
typedef P2VAR(NvM_DataType, TYPEDEF, NVM_VAR_NO_INIT) NvM_CrcCompMechanismBuffer_NvMConfigBlockPtrType;

/**   \brief  type used to point to NvM_CrcCompMechanismBuffer_WDFC_ID_AP_CONNEX */
typedef P2VAR(NvM_DataType, TYPEDEF, NVM_VAR_NO_INIT) NvM_CrcCompMechanismBuffer_WDFC_ID_AP_CONNEXPtrType;

/**   \brief  type used to point to NvM_CrcCompMechanismBuffer_WDFC_ID_AP_PARA */
typedef P2VAR(NvM_DataType, TYPEDEF, NVM_VAR_NO_INIT) NvM_CrcCompMechanismBuffer_WDFC_ID_AP_PARAPtrType;

/**   \brief  type used to point to NvM_CrcCompMechanismBuffer_WDFC_ID_BOOT_PARA */
typedef P2VAR(NvM_DataType, TYPEDEF, NVM_VAR_NO_INIT) NvM_CrcCompMechanismBuffer_WDFC_ID_BOOT_PARAPtrType;

/**   \brief  type used to point to NvM_CrcCompMechanismBuffer_WDFC_ID_CCP */
typedef P2VAR(NvM_DataType, TYPEDEF, NVM_VAR_NO_INIT) NvM_CrcCompMechanismBuffer_WDFC_ID_CCPPtrType;

/**   \brief  type used to point to NvM_CrcCompMechanismBuffer_WDFC_ID_DEBUG_DATA */
typedef P2VAR(NvM_DataType, TYPEDEF, NVM_VAR_NO_INIT) NvM_CrcCompMechanismBuffer_WDFC_ID_DEBUG_DATAPtrType;

/**   \brief  type used to point to NvM_CrcCompMechanismBuffer_WDFC_ID_DLC */
typedef P2VAR(NvM_DataType, TYPEDEF, NVM_VAR_NO_INIT) NvM_CrcCompMechanismBuffer_WDFC_ID_DLCPtrType;

/**   \brief  type used to point to NvM_CrcCompMechanismBuffer_WDFC_ID_DTCTime */
typedef P2VAR(NvM_DataType, TYPEDEF, NVM_VAR_NO_INIT) NvM_CrcCompMechanismBuffer_WDFC_ID_DTCTimePtrType;

/**   \brief  type used to point to NvM_CrcCompMechanismBuffer_WDFC_ID_ECUID_RDI_PROGRAMMING_INFO */
typedef P2VAR(NvM_DataType, TYPEDEF, NVM_VAR_NO_INIT) NvM_CrcCompMechanismBuffer_WDFC_ID_ECUID_RDI_PROGRAMMING_INFOPtrType;

/**   \brief  type used to point to NvM_CrcCompMechanismBuffer_WDFC_ID_EOL_HW_VERSION */
typedef P2VAR(NvM_DataType, TYPEDEF, NVM_VAR_NO_INIT) NvM_CrcCompMechanismBuffer_WDFC_ID_EOL_HW_VERSIONPtrType;

/**   \brief  type used to point to NvM_CrcCompMechanismBuffer_WDFC_ID_EOL_INFO */
typedef P2VAR(NvM_DataType, TYPEDEF, NVM_VAR_NO_INIT) NvM_CrcCompMechanismBuffer_WDFC_ID_EOL_INFOPtrType;

/**   \brief  type used to point to NvM_CrcCompMechanismBuffer_WDFC_ID_EOL_PASSWORD */
typedef P2VAR(NvM_DataType, TYPEDEF, NVM_VAR_NO_INIT) NvM_CrcCompMechanismBuffer_WDFC_ID_EOL_PASSWORDPtrType;

/**   \brief  type used to point to NvM_CrcCompMechanismBuffer_WDFC_ID_EOL_SWNUMBER */
typedef P2VAR(NvM_DataType, TYPEDEF, NVM_VAR_NO_INIT) NvM_CrcCompMechanismBuffer_WDFC_ID_EOL_SWNUMBERPtrType;

/**   \brief  type used to point to NvM_CrcCompMechanismBuffer_WDFC_ID_FAULT_CODE */
typedef P2VAR(NvM_DataType, TYPEDEF, NVM_VAR_NO_INIT) NvM_CrcCompMechanismBuffer_WDFC_ID_FAULT_CODEPtrType;

/**   \brief  type used to point to NvM_CrcCompMechanismBuffer_WDFC_ID_HANDLE_CFG */
typedef P2VAR(NvM_DataType, TYPEDEF, NVM_VAR_NO_INIT) NvM_CrcCompMechanismBuffer_WDFC_ID_HANDLE_CFGPtrType;

/**   \brief  type used to point to NvM_CrcCompMechanismBuffer_WDFC_ID_IDENT_BANK */
typedef P2VAR(NvM_DataType, TYPEDEF, NVM_VAR_NO_INIT) NvM_CrcCompMechanismBuffer_WDFC_ID_IDENT_BANKPtrType;

/**   \brief  type used to point to NvM_CrcCompMechanismBuffer_WDFC_ID_IDOPTION_SECURITY */
typedef P2VAR(NvM_DataType, TYPEDEF, NVM_VAR_NO_INIT) NvM_CrcCompMechanismBuffer_WDFC_ID_IDOPTION_SECURITYPtrType;

/**   \brief  type used to point to NvM_CrcCompMechanismBuffer_WDFC_ID_LAST_FDC */
typedef P2VAR(NvM_DataType, TYPEDEF, NVM_VAR_NO_INIT) NvM_CrcCompMechanismBuffer_WDFC_ID_LAST_FDCPtrType;

/**   \brief  type used to point to NvM_CrcCompMechanismBuffer_WDFC_ID_MAX_FDC */
typedef P2VAR(NvM_DataType, TYPEDEF, NVM_VAR_NO_INIT) NvM_CrcCompMechanismBuffer_WDFC_ID_MAX_FDCPtrType;

/**   \brief  type used to point to NvM_CrcCompMechanismBuffer_WDFC_ID_MIRROR_CFG */
typedef P2VAR(NvM_DataType, TYPEDEF, NVM_VAR_NO_INIT) NvM_CrcCompMechanismBuffer_WDFC_ID_MIRROR_CFGPtrType;

/**   \brief  type used to point to NvM_CrcCompMechanismBuffer_WDFC_ID_MIRROR_OTHER_1 */
typedef P2VAR(NvM_DataType, TYPEDEF, NVM_VAR_NO_INIT) NvM_CrcCompMechanismBuffer_WDFC_ID_MIRROR_OTHER_1PtrType;

/**   \brief  type used to point to NvM_CrcCompMechanismBuffer_WDFC_ID_MIRROR_POS_REC */
typedef P2VAR(NvM_DataType, TYPEDEF, NVM_VAR_NO_INIT) NvM_CrcCompMechanismBuffer_WDFC_ID_MIRROR_POS_RECPtrType;

/**   \brief  type used to point to NvM_CrcCompMechanismBuffer_WDFC_ID_MIRROR_ST */
typedef P2VAR(NvM_DataType, TYPEDEF, NVM_VAR_NO_INIT) NvM_CrcCompMechanismBuffer_WDFC_ID_MIRROR_STPtrType;

/**   \brief  type used to point to NvM_CrcCompMechanismBuffer_WDFC_ID_PART_NUMBER_GEELY */
typedef P2VAR(NvM_DataType, TYPEDEF, NVM_VAR_NO_INIT) NvM_CrcCompMechanismBuffer_WDFC_ID_PART_NUMBER_GEELYPtrType;

/**   \brief  type used to point to NvM_CrcCompMechanismBuffer_WDFC_ID_PMM */
typedef P2VAR(NvM_DataType, TYPEDEF, NVM_VAR_NO_INIT) NvM_CrcCompMechanismBuffer_WDFC_ID_PMMPtrType;

/**   \brief  type used to point to NvM_CrcCompMechanismBuffer_WDFC_ID_QCM_FAULT_DATA */
typedef P2VAR(NvM_DataType, TYPEDEF, NVM_VAR_NO_INIT) NvM_CrcCompMechanismBuffer_WDFC_ID_QCM_FAULT_DATAPtrType;

/**   \brief  type used to point to NvM_CrcCompMechanismBuffer_WDFC_ID_SECURITY_ACCESS */
typedef P2VAR(NvM_DataType, TYPEDEF, NVM_VAR_NO_INIT) NvM_CrcCompMechanismBuffer_WDFC_ID_SECURITY_ACCESSPtrType;

/**   \brief  type used to point to NvM_CrcCompMechanismBuffer_WDFC_ID_SR_PROFILE */
typedef P2VAR(NvM_DataType, TYPEDEF, NVM_VAR_NO_INIT) NvM_CrcCompMechanismBuffer_WDFC_ID_SR_PROFILEPtrType;

/**   \brief  type used to point to NvM_CrcCompMechanismBuffer_WDFC_ID_SWP1 */
typedef P2VAR(NvM_DataType, TYPEDEF, NVM_VAR_NO_INIT) NvM_CrcCompMechanismBuffer_WDFC_ID_SWP1PtrType;

/**   \brief  type used to point to NvM_CrcCompMechanismBuffer_WDFC_ID_THPA */
typedef P2VAR(NvM_DataType, TYPEDEF, NVM_VAR_NO_INIT) NvM_CrcCompMechanismBuffer_WDFC_ID_THPAPtrType;

/**   \brief  type used to point to NvM_CrcCompMechanismBuffer_WDFC_ID_VEH_CFG */
typedef P2VAR(NvM_DataType, TYPEDEF, NVM_VAR_NO_INIT) NvM_CrcCompMechanismBuffer_WDFC_ID_VEH_CFGPtrType;

/**   \brief  type used to point to NvM_CrcCompMechanismBuffer_WDFC_ID_VOL_POWER_MODE_CFG */
typedef P2VAR(NvM_DataType, TYPEDEF, NVM_VAR_NO_INIT) NvM_CrcCompMechanismBuffer_WDFC_ID_VOL_POWER_MODE_CFGPtrType;

/**   \brief  type used to point to NvM_CrcCompMechanismBuffer_WDFC_ID_WLC_AP_LEARN */
typedef P2VAR(NvM_DataType, TYPEDEF, NVM_VAR_NO_INIT) NvM_CrcCompMechanismBuffer_WDFC_ID_WLC_AP_LEARNPtrType;

/**   \brief  type used to point to NvM_CrcCompMechanismBuffer_WDFC_ID_WL_INFO */
typedef P2VAR(NvM_DataType, TYPEDEF, NVM_VAR_NO_INIT) NvM_CrcCompMechanismBuffer_WDFC_ID_WL_INFOPtrType;

/**   \brief  type used to point to NvM_CrcCompMechanismBuffer_WDFC_ID_WL_LOG */
typedef P2VAR(NvM_DataType, TYPEDEF, NVM_VAR_NO_INIT) NvM_CrcCompMechanismBuffer_WDFC_ID_WL_LOGPtrType;

/**   \brief  type used to point to NvM_DataIntegrityFsm_Instance */
typedef P2VAR(NvM_FsmType, TYPEDEF, NVM_VAR_NO_INIT) NvM_DataIntegrityFsm_InstancePtrType;

/**   \brief  type used to point to NvM_DataIntegrityIntBuffer_DemAdminDataBlock */
typedef P2VAR(NvM_DataType, TYPEDEF, NVM_VAR_NO_INIT) NvM_DataIntegrityIntBuffer_DemAdminDataBlockPtrType;

/**   \brief  type used to point to NvM_DataIntegrityIntBuffer_DemStatusDataBlock */
typedef P2VAR(NvM_DataType, TYPEDEF, NVM_VAR_NO_INIT) NvM_DataIntegrityIntBuffer_DemStatusDataBlockPtrType;

/**   \brief  type used to point to NvM_DataIntegrityIntBuffer_WDFC_ID_AP_CONNEX */
typedef P2VAR(NvM_DataType, TYPEDEF, NVM_VAR_NO_INIT) NvM_DataIntegrityIntBuffer_WDFC_ID_AP_CONNEXPtrType;

/**   \brief  type used to point to NvM_DataIntegrityIntBuffer_WDFC_ID_AP_PARA */
typedef P2VAR(NvM_DataType, TYPEDEF, NVM_VAR_NO_INIT) NvM_DataIntegrityIntBuffer_WDFC_ID_AP_PARAPtrType;

/**   \brief  type used to point to NvM_DataIntegrityIntBuffer_WDFC_ID_BOOT_PARA */
typedef P2VAR(NvM_DataType, TYPEDEF, NVM_VAR_NO_INIT) NvM_DataIntegrityIntBuffer_WDFC_ID_BOOT_PARAPtrType;

/**   \brief  type used to point to NvM_DataIntegrityIntBuffer_WDFC_ID_CCP */
typedef P2VAR(NvM_DataType, TYPEDEF, NVM_VAR_NO_INIT) NvM_DataIntegrityIntBuffer_WDFC_ID_CCPPtrType;

/**   \brief  type used to point to NvM_DataIntegrityIntBuffer_WDFC_ID_DEBUG_DATA */
typedef P2VAR(NvM_DataType, TYPEDEF, NVM_VAR_NO_INIT) NvM_DataIntegrityIntBuffer_WDFC_ID_DEBUG_DATAPtrType;

/**   \brief  type used to point to NvM_DataIntegrityIntBuffer_WDFC_ID_DLC */
typedef P2VAR(NvM_DataType, TYPEDEF, NVM_VAR_NO_INIT) NvM_DataIntegrityIntBuffer_WDFC_ID_DLCPtrType;

/**   \brief  type used to point to NvM_DataIntegrityIntBuffer_WDFC_ID_DTCTime */
typedef P2VAR(NvM_DataType, TYPEDEF, NVM_VAR_NO_INIT) NvM_DataIntegrityIntBuffer_WDFC_ID_DTCTimePtrType;

/**   \brief  type used to point to NvM_DataIntegrityIntBuffer_WDFC_ID_ECUID_RDI_PROGRAMMING_INFO */
typedef P2VAR(NvM_DataType, TYPEDEF, NVM_VAR_NO_INIT) NvM_DataIntegrityIntBuffer_WDFC_ID_ECUID_RDI_PROGRAMMING_INFOPtrType;

/**   \brief  type used to point to NvM_DataIntegrityIntBuffer_WDFC_ID_EOL_HW_VERSION */
typedef P2VAR(NvM_DataType, TYPEDEF, NVM_VAR_NO_INIT) NvM_DataIntegrityIntBuffer_WDFC_ID_EOL_HW_VERSIONPtrType;

/**   \brief  type used to point to NvM_DataIntegrityIntBuffer_WDFC_ID_EOL_INFO */
typedef P2VAR(NvM_DataType, TYPEDEF, NVM_VAR_NO_INIT) NvM_DataIntegrityIntBuffer_WDFC_ID_EOL_INFOPtrType;

/**   \brief  type used to point to NvM_DataIntegrityIntBuffer_WDFC_ID_EOL_PASSWORD */
typedef P2VAR(NvM_DataType, TYPEDEF, NVM_VAR_NO_INIT) NvM_DataIntegrityIntBuffer_WDFC_ID_EOL_PASSWORDPtrType;

/**   \brief  type used to point to NvM_DataIntegrityIntBuffer_WDFC_ID_EOL_SWNUMBER */
typedef P2VAR(NvM_DataType, TYPEDEF, NVM_VAR_NO_INIT) NvM_DataIntegrityIntBuffer_WDFC_ID_EOL_SWNUMBERPtrType;

/**   \brief  type used to point to NvM_DataIntegrityIntBuffer_WDFC_ID_FAULT_CODE */
typedef P2VAR(NvM_DataType, TYPEDEF, NVM_VAR_NO_INIT) NvM_DataIntegrityIntBuffer_WDFC_ID_FAULT_CODEPtrType;

/**   \brief  type used to point to NvM_DataIntegrityIntBuffer_WDFC_ID_HANDLE_CFG */
typedef P2VAR(NvM_DataType, TYPEDEF, NVM_VAR_NO_INIT) NvM_DataIntegrityIntBuffer_WDFC_ID_HANDLE_CFGPtrType;

/**   \brief  type used to point to NvM_DataIntegrityIntBuffer_WDFC_ID_IDENT_BANK */
typedef P2VAR(NvM_DataType, TYPEDEF, NVM_VAR_NO_INIT) NvM_DataIntegrityIntBuffer_WDFC_ID_IDENT_BANKPtrType;

/**   \brief  type used to point to NvM_DataIntegrityIntBuffer_WDFC_ID_IDOPTION_SECURITY */
typedef P2VAR(NvM_DataType, TYPEDEF, NVM_VAR_NO_INIT) NvM_DataIntegrityIntBuffer_WDFC_ID_IDOPTION_SECURITYPtrType;

/**   \brief  type used to point to NvM_DataIntegrityIntBuffer_WDFC_ID_LAST_FDC */
typedef P2VAR(NvM_DataType, TYPEDEF, NVM_VAR_NO_INIT) NvM_DataIntegrityIntBuffer_WDFC_ID_LAST_FDCPtrType;

/**   \brief  type used to point to NvM_DataIntegrityIntBuffer_WDFC_ID_MAX_FDC */
typedef P2VAR(NvM_DataType, TYPEDEF, NVM_VAR_NO_INIT) NvM_DataIntegrityIntBuffer_WDFC_ID_MAX_FDCPtrType;

/**   \brief  type used to point to NvM_DataIntegrityIntBuffer_WDFC_ID_MIRROR_CFG */
typedef P2VAR(NvM_DataType, TYPEDEF, NVM_VAR_NO_INIT) NvM_DataIntegrityIntBuffer_WDFC_ID_MIRROR_CFGPtrType;

/**   \brief  type used to point to NvM_DataIntegrityIntBuffer_WDFC_ID_MIRROR_OTHER_1 */
typedef P2VAR(NvM_DataType, TYPEDEF, NVM_VAR_NO_INIT) NvM_DataIntegrityIntBuffer_WDFC_ID_MIRROR_OTHER_1PtrType;

/**   \brief  type used to point to NvM_DataIntegrityIntBuffer_WDFC_ID_MIRROR_POS_REC */
typedef P2VAR(NvM_DataType, TYPEDEF, NVM_VAR_NO_INIT) NvM_DataIntegrityIntBuffer_WDFC_ID_MIRROR_POS_RECPtrType;

/**   \brief  type used to point to NvM_DataIntegrityIntBuffer_WDFC_ID_MIRROR_ST */
typedef P2VAR(NvM_DataType, TYPEDEF, NVM_VAR_NO_INIT) NvM_DataIntegrityIntBuffer_WDFC_ID_MIRROR_STPtrType;

/**   \brief  type used to point to NvM_DataIntegrityIntBuffer_WDFC_ID_PART_NUMBER_GEELY */
typedef P2VAR(NvM_DataType, TYPEDEF, NVM_VAR_NO_INIT) NvM_DataIntegrityIntBuffer_WDFC_ID_PART_NUMBER_GEELYPtrType;

/**   \brief  type used to point to NvM_DataIntegrityIntBuffer_WDFC_ID_PMM */
typedef P2VAR(NvM_DataType, TYPEDEF, NVM_VAR_NO_INIT) NvM_DataIntegrityIntBuffer_WDFC_ID_PMMPtrType;

/**   \brief  type used to point to NvM_DataIntegrityIntBuffer_WDFC_ID_QCM_FAULT_DATA */
typedef P2VAR(NvM_DataType, TYPEDEF, NVM_VAR_NO_INIT) NvM_DataIntegrityIntBuffer_WDFC_ID_QCM_FAULT_DATAPtrType;

/**   \brief  type used to point to NvM_DataIntegrityIntBuffer_WDFC_ID_SECURITY_ACCESS */
typedef P2VAR(NvM_DataType, TYPEDEF, NVM_VAR_NO_INIT) NvM_DataIntegrityIntBuffer_WDFC_ID_SECURITY_ACCESSPtrType;

/**   \brief  type used to point to NvM_DataIntegrityIntBuffer_WDFC_ID_SR_PROFILE */
typedef P2VAR(NvM_DataType, TYPEDEF, NVM_VAR_NO_INIT) NvM_DataIntegrityIntBuffer_WDFC_ID_SR_PROFILEPtrType;

/**   \brief  type used to point to NvM_DataIntegrityIntBuffer_WDFC_ID_SWP1 */
typedef P2VAR(NvM_DataType, TYPEDEF, NVM_VAR_NO_INIT) NvM_DataIntegrityIntBuffer_WDFC_ID_SWP1PtrType;

/**   \brief  type used to point to NvM_DataIntegrityIntBuffer_WDFC_ID_THPA */
typedef P2VAR(NvM_DataType, TYPEDEF, NVM_VAR_NO_INIT) NvM_DataIntegrityIntBuffer_WDFC_ID_THPAPtrType;

/**   \brief  type used to point to NvM_DataIntegrityIntBuffer_WDFC_ID_VEH_CFG */
typedef P2VAR(NvM_DataType, TYPEDEF, NVM_VAR_NO_INIT) NvM_DataIntegrityIntBuffer_WDFC_ID_VEH_CFGPtrType;

/**   \brief  type used to point to NvM_DataIntegrityIntBuffer_WDFC_ID_VOL_POWER_MODE_CFG */
typedef P2VAR(NvM_DataType, TYPEDEF, NVM_VAR_NO_INIT) NvM_DataIntegrityIntBuffer_WDFC_ID_VOL_POWER_MODE_CFGPtrType;

/**   \brief  type used to point to NvM_DataIntegrityIntBuffer_WDFC_ID_WLC_AP_LEARN */
typedef P2VAR(NvM_DataType, TYPEDEF, NVM_VAR_NO_INIT) NvM_DataIntegrityIntBuffer_WDFC_ID_WLC_AP_LEARNPtrType;

/**   \brief  type used to point to NvM_DataIntegrityIntBuffer_WDFC_ID_WL_INFO */
typedef P2VAR(NvM_DataType, TYPEDEF, NVM_VAR_NO_INIT) NvM_DataIntegrityIntBuffer_WDFC_ID_WL_INFOPtrType;

/**   \brief  type used to point to NvM_DataIntegrityIntBuffer_WDFC_ID_WL_LOG */
typedef P2VAR(NvM_DataType, TYPEDEF, NVM_VAR_NO_INIT) NvM_DataIntegrityIntBuffer_WDFC_ID_WL_LOGPtrType;

/**   \brief  type used to point to NvM_DataIntegrityRecalcQueue_Instance */
typedef P2VAR(NvM_DataIntegrityRecalcQueue_InstanceType, TYPEDEF, NVM_VAR_NO_INIT) NvM_DataIntegrityRecalcQueue_InstancePtrType;

/**   \brief  type used to point to NvM_DcmBlockManagementInfo */
typedef P2VAR(NvM_BlockManagementInformationType, TYPEDEF, NVM_VAR_NO_INIT) NvM_DcmBlockManagementInfoPtrType;

/**   \brief  type used to point to NvM_ForegroundDataIntegrityService_Instance */
typedef P2VAR(NvM_DataIntegrityService_InstanceType, TYPEDEF, NVM_VAR_NO_INIT) NvM_ForegroundDataIntegrityService_InstancePtrType;

/**   \brief  type used to point to NvM_InternalBuffer */
typedef P2VAR(NvM_DataType, TYPEDEF, NVM_VAR_NO_INIT) NvM_InternalBufferPtrType;

/**   \brief  type used to point to NvM_MultiBlockFsmLib_ProcessingStackElement */
typedef P2VAR(NvM_FsmLib_ProcessingStackElementType, TYPEDEF, NVM_VAR_NO_INIT) NvM_MultiBlockFsmLib_ProcessingStackElementPtrType;

/**   \brief  type used to point to NvM_MultiBlockJob */
typedef P2VAR(NvM_MultiBlockJobType, TYPEDEF, NVM_VAR_NO_INIT) NvM_MultiBlockJobPtrType;

/**   \brief  type used to point to NvM_MultiBlockJobFsm_Context */
typedef P2VAR(NvM_MultiBlockJobFsm_ContextType, TYPEDEF, NVM_VAR_NO_INIT) NvM_MultiBlockJobFsm_ContextPtrType;

/**   \brief  type used to point to NvM_MultiBlockJobFsm_Instance */
typedef P2VAR(NvM_FsmType, TYPEDEF, NVM_VAR_NO_INIT) NvM_MultiBlockJobFsm_InstancePtrType;

/**   \brief  type used to point to NvM_MultiBlockJobInformation */
typedef P2VAR(NvM_MultiBlockJobInformationType, TYPEDEF, NVM_VAR_NO_INIT) NvM_MultiBlockJobInformationPtrType;

/**   \brief  type used to point to NvM_MultiBlockProcessorFsmLib_Instance */
typedef P2VAR(NvM_FsmLib_InstanceType, TYPEDEF, NVM_VAR_NO_INIT) NvM_MultiBlockProcessorFsmLib_InstancePtrType;

/**   \brief  type used to point to NvM_MultiBlockProcessorFsmLib_ProcessingStackElement */
typedef P2VAR(NvM_FsmLib_ProcessingStackElementType, TYPEDEF, NVM_VAR_NO_INIT) NvM_MultiBlockProcessorFsmLib_ProcessingStackElementPtrType;

/**   \brief  type used to point to NvM_MultiBlockServiceFsmLib_Instance */
typedef P2VAR(NvM_FsmLib_InstanceType, TYPEDEF, NVM_VAR_NO_INIT) NvM_MultiBlockServiceFsmLib_InstancePtrType;

/**   \brief  type used to point to NvM_NvJobContext */
typedef P2VAR(NvM_NvJobContextType, TYPEDEF, NVM_VAR_NO_INIT) NvM_NvJobContextPtrType;

/**   \brief  type used to point to NvM_NvJobFsm_Instance */
typedef P2VAR(NvM_FsmType, TYPEDEF, NVM_VAR_NO_INIT) NvM_NvJobFsm_InstancePtrType;

/**   \brief  type used to point to NvM_NvServiceFsmLib_Instance */
typedef P2VAR(NvM_FsmLib_InstanceType, TYPEDEF, NVM_VAR_NO_INIT) NvM_NvServiceFsmLib_InstancePtrType;

/**   \brief  type used to point to NvM_NvServiceFsmLib_ProcessingStackElement */
typedef P2VAR(NvM_FsmLib_ProcessingStackElementType, TYPEDEF, NVM_VAR_NO_INIT) NvM_NvServiceFsmLib_ProcessingStackElementPtrType;

/**   \brief  type used to point to NvM_NvServiceProcessorFsmLib_Instance */
typedef P2VAR(NvM_FsmLib_InstanceType, TYPEDEF, NVM_VAR_NO_INIT) NvM_NvServiceProcessorFsmLib_InstancePtrType;

/**   \brief  type used to point to NvM_NvServiceProcessorFsmLib_ProcessingStackElement */
typedef P2VAR(NvM_FsmLib_ProcessingStackElementType, TYPEDEF, NVM_VAR_NO_INIT) NvM_NvServiceProcessorFsmLib_ProcessingStackElementPtrType;

/**   \brief  type used to point to NvM_PartitionIdentifiers */
typedef P2CONST(NvM_PartitionIdentifiersType, TYPEDEF, NVM_CONST) NvM_PartitionIdentifiersPtrType;

/**   \brief  type used to point to NvM_QueueList */
typedef P2VAR(NvM_Queue_ListElement, TYPEDEF, NVM_VAR_NO_INIT) NvM_QueueListPtrType;

/**   \brief  type used to point to NvM_Queue_Instance */
typedef P2VAR(NvM_Queue_InstanceType, TYPEDEF, NVM_VAR_NO_INIT) NvM_Queue_InstancePtrType;

/**   \brief  type used to point to NvM_ReadAllFsm_Context */
typedef P2VAR(NvM_ReadAllFsm_ContextType, TYPEDEF, NVM_VAR_NO_INIT) NvM_ReadAllFsm_ContextPtrType;

/**   \brief  type used to point to NvM_ReadAllFsm_Instance */
typedef P2VAR(NvM_FsmType, TYPEDEF, NVM_VAR_NO_INIT) NvM_ReadAllFsm_InstancePtrType;

/**   \brief  type used to point to NvM_ReadBlockFsm_Context */
typedef P2VAR(NvM_ReadBlockFsm_ContextType, TYPEDEF, NVM_VAR_NO_INIT) NvM_ReadBlockFsm_ContextPtrType;

/**   \brief  type used to point to NvM_ReadBlockFsm_Instance */
typedef P2VAR(NvM_FsmType, TYPEDEF, NVM_VAR_NO_INIT) NvM_ReadBlockFsm_InstancePtrType;

/**   \brief  type used to point to NvM_ServiceProcessorFsmLib_Instance */
typedef P2VAR(NvM_FsmLib_InstanceType, TYPEDEF, NVM_VAR_NO_INIT) NvM_ServiceProcessorFsmLib_InstancePtrType;

/**   \brief  type used to point to NvM_ServiceProcessorFsmLib_ProcessingStackElement */
typedef P2VAR(NvM_FsmLib_ProcessingStackElementType, TYPEDEF, NVM_VAR_NO_INIT) NvM_ServiceProcessorFsmLib_ProcessingStackElementPtrType;

/**   \brief  type used to point to NvM_ServiceProcessorFsm_Context */
typedef P2VAR(NvM_ServiceProcessorFsm_ContextType, TYPEDEF, NVM_VAR_NO_INIT) NvM_ServiceProcessorFsm_ContextPtrType;

/**   \brief  type used to point to NvM_ServiceProcessorFsm_Instance */
typedef P2VAR(NvM_FsmType, TYPEDEF, NVM_VAR_NO_INIT) NvM_ServiceProcessorFsm_InstancePtrType;

/**   \brief  type used to point to NvM_SingleBlockFsmLib_ProcessingStackElement */
typedef P2VAR(NvM_FsmLib_ProcessingStackElementType, TYPEDEF, NVM_VAR_NO_INIT) NvM_SingleBlockFsmLib_ProcessingStackElementPtrType;

/**   \brief  type used to point to NvM_SingleBlockJobContext */
typedef P2VAR(NvM_SingleBlockJobContextType, TYPEDEF, NVM_VAR_NO_INIT) NvM_SingleBlockJobContextPtrType;

/**   \brief  type used to point to NvM_SingleBlockJobFsm_Instance */
typedef P2VAR(NvM_FsmType, TYPEDEF, NVM_VAR_NO_INIT) NvM_SingleBlockJobFsm_InstancePtrType;

/**   \brief  type used to point to NvM_SingleBlockServiceFsmLib_Instance */
typedef P2VAR(NvM_FsmLib_InstanceType, TYPEDEF, NVM_VAR_NO_INIT) NvM_SingleBlockServiceFsmLib_InstancePtrType;

/**   \brief  type used to point to NvM_ValidateAllFsm_Instance */
typedef P2VAR(NvM_FsmType, TYPEDEF, NVM_VAR_NO_INIT) NvM_ValidateAllFsm_InstancePtrType;

/**   \brief  type used to point to NvM_WriteAllFsm_Context */
typedef P2VAR(NvM_MultiBlockFsm_ContextType, TYPEDEF, NVM_VAR_NO_INIT) NvM_WriteAllFsm_ContextPtrType;

/**   \brief  type used to point to NvM_WriteAllFsm_Instance */
typedef P2VAR(NvM_FsmType, TYPEDEF, NVM_VAR_NO_INIT) NvM_WriteAllFsm_InstancePtrType;

/**   \brief  type used to point to NvM_WriteBlockFsm_Context */
typedef P2VAR(NvM_WriteBlockFsm_ContextType, TYPEDEF, NVM_VAR_NO_INIT) NvM_WriteBlockFsm_ContextPtrType;

/**   \brief  type used to point to NvM_WriteBlockFsm_Instance */
typedef P2VAR(NvM_FsmType, TYPEDEF, NVM_VAR_NO_INIT) NvM_WriteBlockFsm_InstancePtrType;

/**   \brief  type used to point to NvM_WriteNvBlockFsm_Context */
typedef P2VAR(NvM_WriteNvBlockFsm_ContextType, TYPEDEF, NVM_VAR_NO_INIT) NvM_WriteNvBlockFsm_ContextPtrType;

/** 
  \}
*/ 

/** 
  \defgroup  NvMPCPartitionRootPointer  NvM Partition Root Pointer (PRE_COMPILE)
  \brief  This type definitions are used for partition specific instance.
  \{
*/ 
/**   \brief  type used in NvM_PCPartitionConfig */
typedef struct sNvM_PCPartitionConfigType
{
  uint8 NvM_PCPartitionConfigNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} NvM_PCPartitionConfigType;

/**   \brief  type used to point to NvM_PCPartitionConfig */
typedef P2CONST(NvM_PCPartitionConfigType, TYPEDEF, NVM_CONST) NvM_PCPartitionConfigPtrType;

/** 
  \}
*/ 

/** 
  \defgroup  NvMPCRootValueTypes  NvM Root Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value representations in root arrays.
  \{
*/ 
/**   \brief  type used in NvM_PCConfig */
typedef struct sNvM_PCConfigType
{
  uint8 NvM_PCConfigNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} NvM_PCConfigType;

typedef NvM_PCConfigType NvM_ConfigType;  /**< A structure type is present for data in each configuration class. This typedef redefines the probably different name to the specified one. */

/** 
  \}
*/ 



/***********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 **********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  NvM_BlockDescriptor
**********************************************************************************************************************/
#define NVM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(NvM_BlockDescriptorType, NVM_CONST) NvM_BlockDescriptor[37];
#define NVM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_PartitionIdentifiers
**********************************************************************************************************************/
/** 
  \var    NvM_PartitionIdentifiers
  \brief  the partition context in Config
  \details
  Element                 Description
  PartitionSNV        
  PCPartitionConfigIdx    the index of the 1:1 relation pointing to NvM_PCPartitionConfig
*/ 
#define NVM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(NvM_PartitionIdentifiersType, NVM_CONST) NvM_PartitionIdentifiers[1];
#define NVM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_BackgroundCrcRecalcFsmLib_Instance
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_FsmLib_InstanceType, NVM_VAR_NO_INIT) NvM_BackgroundCrcRecalcFsmLib_Instance;  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_BackgroundCrcRecalcFsmLib_ProcessingStackElement
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_FsmLib_ProcessingStackElementType, NVM_VAR_NO_INIT) NvM_BackgroundCrcRecalcFsmLib_ProcessingStackElement[1];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_BackgroundCrcRecalcFsm_Context
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_BackgroundCrcRecalcFsm_ContextType, NVM_VAR_NO_INIT) NvM_BackgroundCrcRecalcFsm_Context;  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_BackgroundCrcRecalcFsm_Instance
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_FsmType, NVM_VAR_NO_INIT) NvM_BackgroundCrcRecalcFsm_Instance;  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_BackgroundDataIntegrityService_Instance
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_DataIntegrityService_InstanceType, NVM_VAR_NO_INIT) NvM_BackgroundDataIntegrityService_Instance;  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_BlockManagementInfo_DemAdminDataBlock
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_BlockManagementInformationType, NVM_VAR_NO_INIT) NvM_BlockManagementInfo_DemAdminDataBlock;  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_BlockManagementInfo_DemStatusDataBlock
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_BlockManagementInformationType, NVM_VAR_NO_INIT) NvM_BlockManagementInfo_DemStatusDataBlock;  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_BlockManagementInfo_NvMConfigBlock
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_BlockManagementInformationType, NVM_VAR_NO_INIT) NvM_BlockManagementInfo_NvMConfigBlock;  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_BlockManagementInfo_NvMMultiBlock
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_BlockManagementInformationType, NVM_VAR_NO_INIT) NvM_BlockManagementInfo_NvMMultiBlock;  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_BlockManagementInfo_WDFC_ID_AP_CONNEX
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_BlockManagementInformationType, NVM_VAR_NO_INIT) NvM_BlockManagementInfo_WDFC_ID_AP_CONNEX;  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_BlockManagementInfo_WDFC_ID_AP_PARA
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_BlockManagementInformationType, NVM_VAR_NO_INIT) NvM_BlockManagementInfo_WDFC_ID_AP_PARA;  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_BlockManagementInfo_WDFC_ID_BOOT_PARA
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_BlockManagementInformationType, NVM_VAR_NO_INIT) NvM_BlockManagementInfo_WDFC_ID_BOOT_PARA;  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_BlockManagementInfo_WDFC_ID_CCP
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_BlockManagementInformationType, NVM_VAR_NO_INIT) NvM_BlockManagementInfo_WDFC_ID_CCP;  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_BlockManagementInfo_WDFC_ID_DEBUG_DATA
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_BlockManagementInformationType, NVM_VAR_NO_INIT) NvM_BlockManagementInfo_WDFC_ID_DEBUG_DATA;  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_BlockManagementInfo_WDFC_ID_DLC
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_BlockManagementInformationType, NVM_VAR_NO_INIT) NvM_BlockManagementInfo_WDFC_ID_DLC;  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_BlockManagementInfo_WDFC_ID_DTCTime
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_BlockManagementInformationType, NVM_VAR_NO_INIT) NvM_BlockManagementInfo_WDFC_ID_DTCTime;  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_BlockManagementInfo_WDFC_ID_ECUID_RDI_PROGRAMMING_INFO
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_BlockManagementInformationType, NVM_VAR_NO_INIT) NvM_BlockManagementInfo_WDFC_ID_ECUID_RDI_PROGRAMMING_INFO;  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_BlockManagementInfo_WDFC_ID_EOL_HW_VERSION
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_BlockManagementInformationType, NVM_VAR_NO_INIT) NvM_BlockManagementInfo_WDFC_ID_EOL_HW_VERSION;  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_BlockManagementInfo_WDFC_ID_EOL_INFO
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_BlockManagementInformationType, NVM_VAR_NO_INIT) NvM_BlockManagementInfo_WDFC_ID_EOL_INFO;  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_BlockManagementInfo_WDFC_ID_EOL_PASSWORD
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_BlockManagementInformationType, NVM_VAR_NO_INIT) NvM_BlockManagementInfo_WDFC_ID_EOL_PASSWORD;  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_BlockManagementInfo_WDFC_ID_EOL_SWNUMBER
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_BlockManagementInformationType, NVM_VAR_NO_INIT) NvM_BlockManagementInfo_WDFC_ID_EOL_SWNUMBER;  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_BlockManagementInfo_WDFC_ID_FAULT_CODE
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_BlockManagementInformationType, NVM_VAR_NO_INIT) NvM_BlockManagementInfo_WDFC_ID_FAULT_CODE;  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_BlockManagementInfo_WDFC_ID_HANDLE_CFG
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_BlockManagementInformationType, NVM_VAR_NO_INIT) NvM_BlockManagementInfo_WDFC_ID_HANDLE_CFG;  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_BlockManagementInfo_WDFC_ID_IDENT_BANK
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_BlockManagementInformationType, NVM_VAR_NO_INIT) NvM_BlockManagementInfo_WDFC_ID_IDENT_BANK;  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_BlockManagementInfo_WDFC_ID_IDOPTION_SECURITY
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_BlockManagementInformationType, NVM_VAR_NO_INIT) NvM_BlockManagementInfo_WDFC_ID_IDOPTION_SECURITY;  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_BlockManagementInfo_WDFC_ID_LAST_FDC
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_BlockManagementInformationType, NVM_VAR_NO_INIT) NvM_BlockManagementInfo_WDFC_ID_LAST_FDC;  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_BlockManagementInfo_WDFC_ID_MAX_FDC
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_BlockManagementInformationType, NVM_VAR_NO_INIT) NvM_BlockManagementInfo_WDFC_ID_MAX_FDC;  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_BlockManagementInfo_WDFC_ID_MIRROR_CFG
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_BlockManagementInformationType, NVM_VAR_NO_INIT) NvM_BlockManagementInfo_WDFC_ID_MIRROR_CFG;  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_BlockManagementInfo_WDFC_ID_MIRROR_OTHER_1
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_BlockManagementInformationType, NVM_VAR_NO_INIT) NvM_BlockManagementInfo_WDFC_ID_MIRROR_OTHER_1;  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_BlockManagementInfo_WDFC_ID_MIRROR_POS_REC
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_BlockManagementInformationType, NVM_VAR_NO_INIT) NvM_BlockManagementInfo_WDFC_ID_MIRROR_POS_REC;  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_BlockManagementInfo_WDFC_ID_MIRROR_ST
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_BlockManagementInformationType, NVM_VAR_NO_INIT) NvM_BlockManagementInfo_WDFC_ID_MIRROR_ST;  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_BlockManagementInfo_WDFC_ID_PART_NUMBER_GEELY
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_BlockManagementInformationType, NVM_VAR_NO_INIT) NvM_BlockManagementInfo_WDFC_ID_PART_NUMBER_GEELY;  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_BlockManagementInfo_WDFC_ID_PMM
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_BlockManagementInformationType, NVM_VAR_NO_INIT) NvM_BlockManagementInfo_WDFC_ID_PMM;  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_BlockManagementInfo_WDFC_ID_QCM_FAULT_DATA
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_BlockManagementInformationType, NVM_VAR_NO_INIT) NvM_BlockManagementInfo_WDFC_ID_QCM_FAULT_DATA;  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_BlockManagementInfo_WDFC_ID_SECURITY_ACCESS
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_BlockManagementInformationType, NVM_VAR_NO_INIT) NvM_BlockManagementInfo_WDFC_ID_SECURITY_ACCESS;  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_BlockManagementInfo_WDFC_ID_SR_PROFILE
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_BlockManagementInformationType, NVM_VAR_NO_INIT) NvM_BlockManagementInfo_WDFC_ID_SR_PROFILE;  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_BlockManagementInfo_WDFC_ID_SWP1
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_BlockManagementInformationType, NVM_VAR_NO_INIT) NvM_BlockManagementInfo_WDFC_ID_SWP1;  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_BlockManagementInfo_WDFC_ID_THPA
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_BlockManagementInformationType, NVM_VAR_NO_INIT) NvM_BlockManagementInfo_WDFC_ID_THPA;  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_BlockManagementInfo_WDFC_ID_VEH_CFG
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_BlockManagementInformationType, NVM_VAR_NO_INIT) NvM_BlockManagementInfo_WDFC_ID_VEH_CFG;  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_BlockManagementInfo_WDFC_ID_VOL_POWER_MODE_CFG
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_BlockManagementInformationType, NVM_VAR_NO_INIT) NvM_BlockManagementInfo_WDFC_ID_VOL_POWER_MODE_CFG;  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_BlockManagementInfo_WDFC_ID_WLC_AP_LEARN
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_BlockManagementInformationType, NVM_VAR_NO_INIT) NvM_BlockManagementInfo_WDFC_ID_WLC_AP_LEARN;  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_BlockManagementInfo_WDFC_ID_WL_INFO
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_BlockManagementInformationType, NVM_VAR_NO_INIT) NvM_BlockManagementInfo_WDFC_ID_WL_INFO;  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_BlockManagementInfo_WDFC_ID_WL_LOG
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_BlockManagementInformationType, NVM_VAR_NO_INIT) NvM_BlockManagementInfo_WDFC_ID_WL_LOG;  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_CrcCompMechanismBuffer_DemAdminDataBlock
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_CrcCompMechanismBuffer_DemAdminDataBlock[2];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_CrcCompMechanismBuffer_DemStatusDataBlock
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_CrcCompMechanismBuffer_DemStatusDataBlock[2];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_CrcCompMechanismBuffer_NvMConfigBlock
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_CrcCompMechanismBuffer_NvMConfigBlock[2];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_CrcCompMechanismBuffer_WDFC_ID_AP_CONNEX
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_CrcCompMechanismBuffer_WDFC_ID_AP_CONNEX[2];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_CrcCompMechanismBuffer_WDFC_ID_AP_PARA
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_CrcCompMechanismBuffer_WDFC_ID_AP_PARA[2];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_CrcCompMechanismBuffer_WDFC_ID_BOOT_PARA
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_CrcCompMechanismBuffer_WDFC_ID_BOOT_PARA[2];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_CrcCompMechanismBuffer_WDFC_ID_CCP
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_CrcCompMechanismBuffer_WDFC_ID_CCP[2];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_CrcCompMechanismBuffer_WDFC_ID_DEBUG_DATA
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_CrcCompMechanismBuffer_WDFC_ID_DEBUG_DATA[2];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_CrcCompMechanismBuffer_WDFC_ID_DLC
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_CrcCompMechanismBuffer_WDFC_ID_DLC[2];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_CrcCompMechanismBuffer_WDFC_ID_DTCTime
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_CrcCompMechanismBuffer_WDFC_ID_DTCTime[2];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_CrcCompMechanismBuffer_WDFC_ID_ECUID_RDI_PROGRAMMING_INFO
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_CrcCompMechanismBuffer_WDFC_ID_ECUID_RDI_PROGRAMMING_INFO[2];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_CrcCompMechanismBuffer_WDFC_ID_EOL_HW_VERSION
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_CrcCompMechanismBuffer_WDFC_ID_EOL_HW_VERSION[2];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_CrcCompMechanismBuffer_WDFC_ID_EOL_INFO
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_CrcCompMechanismBuffer_WDFC_ID_EOL_INFO[2];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_CrcCompMechanismBuffer_WDFC_ID_EOL_PASSWORD
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_CrcCompMechanismBuffer_WDFC_ID_EOL_PASSWORD[2];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_CrcCompMechanismBuffer_WDFC_ID_EOL_SWNUMBER
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_CrcCompMechanismBuffer_WDFC_ID_EOL_SWNUMBER[2];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_CrcCompMechanismBuffer_WDFC_ID_FAULT_CODE
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_CrcCompMechanismBuffer_WDFC_ID_FAULT_CODE[2];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_CrcCompMechanismBuffer_WDFC_ID_HANDLE_CFG
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_CrcCompMechanismBuffer_WDFC_ID_HANDLE_CFG[2];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_CrcCompMechanismBuffer_WDFC_ID_IDENT_BANK
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_CrcCompMechanismBuffer_WDFC_ID_IDENT_BANK[2];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_CrcCompMechanismBuffer_WDFC_ID_IDOPTION_SECURITY
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_CrcCompMechanismBuffer_WDFC_ID_IDOPTION_SECURITY[2];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_CrcCompMechanismBuffer_WDFC_ID_LAST_FDC
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_CrcCompMechanismBuffer_WDFC_ID_LAST_FDC[2];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_CrcCompMechanismBuffer_WDFC_ID_MAX_FDC
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_CrcCompMechanismBuffer_WDFC_ID_MAX_FDC[2];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_CrcCompMechanismBuffer_WDFC_ID_MIRROR_CFG
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_CrcCompMechanismBuffer_WDFC_ID_MIRROR_CFG[2];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_CrcCompMechanismBuffer_WDFC_ID_MIRROR_OTHER_1
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_CrcCompMechanismBuffer_WDFC_ID_MIRROR_OTHER_1[2];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_CrcCompMechanismBuffer_WDFC_ID_MIRROR_POS_REC
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_CrcCompMechanismBuffer_WDFC_ID_MIRROR_POS_REC[2];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_CrcCompMechanismBuffer_WDFC_ID_MIRROR_ST
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_CrcCompMechanismBuffer_WDFC_ID_MIRROR_ST[2];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_CrcCompMechanismBuffer_WDFC_ID_PART_NUMBER_GEELY
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_CrcCompMechanismBuffer_WDFC_ID_PART_NUMBER_GEELY[2];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_CrcCompMechanismBuffer_WDFC_ID_PMM
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_CrcCompMechanismBuffer_WDFC_ID_PMM[2];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_CrcCompMechanismBuffer_WDFC_ID_QCM_FAULT_DATA
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_CrcCompMechanismBuffer_WDFC_ID_QCM_FAULT_DATA[2];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_CrcCompMechanismBuffer_WDFC_ID_SECURITY_ACCESS
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_CrcCompMechanismBuffer_WDFC_ID_SECURITY_ACCESS[2];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_CrcCompMechanismBuffer_WDFC_ID_SR_PROFILE
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_CrcCompMechanismBuffer_WDFC_ID_SR_PROFILE[2];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_CrcCompMechanismBuffer_WDFC_ID_SWP1
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_CrcCompMechanismBuffer_WDFC_ID_SWP1[2];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_CrcCompMechanismBuffer_WDFC_ID_THPA
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_CrcCompMechanismBuffer_WDFC_ID_THPA[2];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_CrcCompMechanismBuffer_WDFC_ID_VEH_CFG
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_CrcCompMechanismBuffer_WDFC_ID_VEH_CFG[2];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_CrcCompMechanismBuffer_WDFC_ID_VOL_POWER_MODE_CFG
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_CrcCompMechanismBuffer_WDFC_ID_VOL_POWER_MODE_CFG[2];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_CrcCompMechanismBuffer_WDFC_ID_WLC_AP_LEARN
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_CrcCompMechanismBuffer_WDFC_ID_WLC_AP_LEARN[2];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_CrcCompMechanismBuffer_WDFC_ID_WL_INFO
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_CrcCompMechanismBuffer_WDFC_ID_WL_INFO[2];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_CrcCompMechanismBuffer_WDFC_ID_WL_LOG
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_CrcCompMechanismBuffer_WDFC_ID_WL_LOG[2];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_DataIntegrityFsm_Instance
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_FsmType, NVM_VAR_NO_INIT) NvM_DataIntegrityFsm_Instance;
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_DataIntegrityIntBuffer_DemAdminDataBlock
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_DataIntegrityIntBuffer_DemAdminDataBlock[2];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_DataIntegrityIntBuffer_DemStatusDataBlock
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_DataIntegrityIntBuffer_DemStatusDataBlock[2];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_DataIntegrityIntBuffer_WDFC_ID_AP_CONNEX
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_DataIntegrityIntBuffer_WDFC_ID_AP_CONNEX[2];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_DataIntegrityIntBuffer_WDFC_ID_AP_PARA
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_DataIntegrityIntBuffer_WDFC_ID_AP_PARA[2];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_DataIntegrityIntBuffer_WDFC_ID_BOOT_PARA
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_DataIntegrityIntBuffer_WDFC_ID_BOOT_PARA[2];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_DataIntegrityIntBuffer_WDFC_ID_CCP
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_DataIntegrityIntBuffer_WDFC_ID_CCP[2];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_DataIntegrityIntBuffer_WDFC_ID_DEBUG_DATA
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_DataIntegrityIntBuffer_WDFC_ID_DEBUG_DATA[2];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_DataIntegrityIntBuffer_WDFC_ID_DLC
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_DataIntegrityIntBuffer_WDFC_ID_DLC[2];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_DataIntegrityIntBuffer_WDFC_ID_DTCTime
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_DataIntegrityIntBuffer_WDFC_ID_DTCTime[2];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_DataIntegrityIntBuffer_WDFC_ID_ECUID_RDI_PROGRAMMING_INFO
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_DataIntegrityIntBuffer_WDFC_ID_ECUID_RDI_PROGRAMMING_INFO[2];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_DataIntegrityIntBuffer_WDFC_ID_EOL_HW_VERSION
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_DataIntegrityIntBuffer_WDFC_ID_EOL_HW_VERSION[2];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_DataIntegrityIntBuffer_WDFC_ID_EOL_INFO
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_DataIntegrityIntBuffer_WDFC_ID_EOL_INFO[2];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_DataIntegrityIntBuffer_WDFC_ID_EOL_PASSWORD
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_DataIntegrityIntBuffer_WDFC_ID_EOL_PASSWORD[2];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_DataIntegrityIntBuffer_WDFC_ID_EOL_SWNUMBER
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_DataIntegrityIntBuffer_WDFC_ID_EOL_SWNUMBER[2];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_DataIntegrityIntBuffer_WDFC_ID_FAULT_CODE
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_DataIntegrityIntBuffer_WDFC_ID_FAULT_CODE[2];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_DataIntegrityIntBuffer_WDFC_ID_HANDLE_CFG
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_DataIntegrityIntBuffer_WDFC_ID_HANDLE_CFG[2];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_DataIntegrityIntBuffer_WDFC_ID_IDENT_BANK
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_DataIntegrityIntBuffer_WDFC_ID_IDENT_BANK[2];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_DataIntegrityIntBuffer_WDFC_ID_IDOPTION_SECURITY
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_DataIntegrityIntBuffer_WDFC_ID_IDOPTION_SECURITY[2];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_DataIntegrityIntBuffer_WDFC_ID_LAST_FDC
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_DataIntegrityIntBuffer_WDFC_ID_LAST_FDC[2];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_DataIntegrityIntBuffer_WDFC_ID_MAX_FDC
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_DataIntegrityIntBuffer_WDFC_ID_MAX_FDC[2];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_DataIntegrityIntBuffer_WDFC_ID_MIRROR_CFG
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_DataIntegrityIntBuffer_WDFC_ID_MIRROR_CFG[2];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_DataIntegrityIntBuffer_WDFC_ID_MIRROR_OTHER_1
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_DataIntegrityIntBuffer_WDFC_ID_MIRROR_OTHER_1[2];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_DataIntegrityIntBuffer_WDFC_ID_MIRROR_POS_REC
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_DataIntegrityIntBuffer_WDFC_ID_MIRROR_POS_REC[2];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_DataIntegrityIntBuffer_WDFC_ID_MIRROR_ST
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_DataIntegrityIntBuffer_WDFC_ID_MIRROR_ST[2];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_DataIntegrityIntBuffer_WDFC_ID_PART_NUMBER_GEELY
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_DataIntegrityIntBuffer_WDFC_ID_PART_NUMBER_GEELY[2];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_DataIntegrityIntBuffer_WDFC_ID_PMM
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_DataIntegrityIntBuffer_WDFC_ID_PMM[2];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_DataIntegrityIntBuffer_WDFC_ID_QCM_FAULT_DATA
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_DataIntegrityIntBuffer_WDFC_ID_QCM_FAULT_DATA[2];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_DataIntegrityIntBuffer_WDFC_ID_SECURITY_ACCESS
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_DataIntegrityIntBuffer_WDFC_ID_SECURITY_ACCESS[2];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_DataIntegrityIntBuffer_WDFC_ID_SR_PROFILE
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_DataIntegrityIntBuffer_WDFC_ID_SR_PROFILE[2];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_DataIntegrityIntBuffer_WDFC_ID_SWP1
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_DataIntegrityIntBuffer_WDFC_ID_SWP1[2];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_DataIntegrityIntBuffer_WDFC_ID_THPA
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_DataIntegrityIntBuffer_WDFC_ID_THPA[2];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_DataIntegrityIntBuffer_WDFC_ID_VEH_CFG
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_DataIntegrityIntBuffer_WDFC_ID_VEH_CFG[2];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_DataIntegrityIntBuffer_WDFC_ID_VOL_POWER_MODE_CFG
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_DataIntegrityIntBuffer_WDFC_ID_VOL_POWER_MODE_CFG[2];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_DataIntegrityIntBuffer_WDFC_ID_WLC_AP_LEARN
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_DataIntegrityIntBuffer_WDFC_ID_WLC_AP_LEARN[2];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_DataIntegrityIntBuffer_WDFC_ID_WL_INFO
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_DataIntegrityIntBuffer_WDFC_ID_WL_INFO[2];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_DataIntegrityIntBuffer_WDFC_ID_WL_LOG
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_DataIntegrityIntBuffer_WDFC_ID_WL_LOG[2];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_DataIntegrityRecalcQueue_Instance
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_DataIntegrityRecalcQueue_InstanceType, NVM_VAR_NO_INIT) NvM_DataIntegrityRecalcQueue_Instance;  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_DcmBlockManagementInfo
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_BlockManagementInformationType, NVM_VAR_NO_INIT) NvM_DcmBlockManagementInfo;
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_ForegroundDataIntegrityService_Instance
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_DataIntegrityService_InstanceType, NVM_VAR_NO_INIT) NvM_ForegroundDataIntegrityService_Instance;  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_InternalBuffer
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_InternalBuffer[1094];
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_MultiBlockFsmLib_ProcessingStackElement
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_FsmLib_ProcessingStackElementType, NVM_VAR_NO_INIT) NvM_MultiBlockFsmLib_ProcessingStackElement[2];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_MultiBlockJob
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_MultiBlockJobType, NVM_VAR_NO_INIT) NvM_MultiBlockJob;
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_MultiBlockJobFsm_Context
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_MultiBlockJobFsm_ContextType, NVM_VAR_NO_INIT) NvM_MultiBlockJobFsm_Context;
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_MultiBlockJobFsm_Instance
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_FsmType, NVM_VAR_NO_INIT) NvM_MultiBlockJobFsm_Instance;
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_MultiBlockJobInformation
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_MultiBlockJobInformationType, NVM_VAR_NO_INIT) NvM_MultiBlockJobInformation;
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_MultiBlockProcessorFsmLib_Instance
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_FsmLib_InstanceType, NVM_VAR_NO_INIT) NvM_MultiBlockProcessorFsmLib_Instance;  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_MultiBlockProcessorFsmLib_ProcessingStackElement
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_FsmLib_ProcessingStackElementType, NVM_VAR_NO_INIT) NvM_MultiBlockProcessorFsmLib_ProcessingStackElement[1];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_MultiBlockServiceFsmLib_Instance
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_FsmLib_InstanceType, NVM_VAR_NO_INIT) NvM_MultiBlockServiceFsmLib_Instance;  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_NvJobContext
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_NvJobContextType, NVM_VAR_NO_INIT) NvM_NvJobContext;
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_NvJobFsm_Instance
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_FsmType, NVM_VAR_NO_INIT) NvM_NvJobFsm_Instance;
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_NvServiceFsmLib_Instance
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_FsmLib_InstanceType, NVM_VAR_NO_INIT) NvM_NvServiceFsmLib_Instance;
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_NvServiceFsmLib_ProcessingStackElement
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_FsmLib_ProcessingStackElementType, NVM_VAR_NO_INIT) NvM_NvServiceFsmLib_ProcessingStackElement[2];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_NvServiceProcessorFsmLib_Instance
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_FsmLib_InstanceType, NVM_VAR_NO_INIT) NvM_NvServiceProcessorFsmLib_Instance;  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_NvServiceProcessorFsmLib_ProcessingStackElement
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_FsmLib_ProcessingStackElementType, NVM_VAR_NO_INIT) NvM_NvServiceProcessorFsmLib_ProcessingStackElement[1];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_QueueList
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_Queue_ListElement, NVM_VAR_NO_INIT) NvM_QueueList[25];
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_Queue_Instance
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_Queue_InstanceType, NVM_VAR_NO_INIT) NvM_Queue_Instance;
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_ReadAllFsm_Context
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_ReadAllFsm_ContextType, NVM_VAR_NO_INIT) NvM_ReadAllFsm_Context;
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_ReadAllFsm_Instance
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_FsmType, NVM_VAR_NO_INIT) NvM_ReadAllFsm_Instance;
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_ReadBlockFsm_Context
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_ReadBlockFsm_ContextType, NVM_VAR_NO_INIT) NvM_ReadBlockFsm_Context;
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_ReadBlockFsm_Instance
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_FsmType, NVM_VAR_NO_INIT) NvM_ReadBlockFsm_Instance;
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_ServiceProcessorFsmLib_Instance
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_FsmLib_InstanceType, NVM_VAR_NO_INIT) NvM_ServiceProcessorFsmLib_Instance;  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_ServiceProcessorFsmLib_ProcessingStackElement
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_FsmLib_ProcessingStackElementType, NVM_VAR_NO_INIT) NvM_ServiceProcessorFsmLib_ProcessingStackElement[1];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_ServiceProcessorFsm_Context
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_ServiceProcessorFsm_ContextType, NVM_VAR_NO_INIT) NvM_ServiceProcessorFsm_Context;
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_ServiceProcessorFsm_Instance
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_FsmType, NVM_VAR_NO_INIT) NvM_ServiceProcessorFsm_Instance;  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_SingleBlockFsmLib_ProcessingStackElement
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_FsmLib_ProcessingStackElementType, NVM_VAR_NO_INIT) NvM_SingleBlockFsmLib_ProcessingStackElement[4];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_SingleBlockJobContext
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_SingleBlockJobContextType, NVM_VAR_NO_INIT) NvM_SingleBlockJobContext;
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_SingleBlockJobFsm_Instance
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_FsmType, NVM_VAR_NO_INIT) NvM_SingleBlockJobFsm_Instance;
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_SingleBlockServiceFsmLib_Instance
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_FsmLib_InstanceType, NVM_VAR_NO_INIT) NvM_SingleBlockServiceFsmLib_Instance;  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_ValidateAllFsm_Instance
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_FsmType, NVM_VAR_NO_INIT) NvM_ValidateAllFsm_Instance;
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_WriteAllFsm_Context
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_MultiBlockFsm_ContextType, NVM_VAR_NO_INIT) NvM_WriteAllFsm_Context;
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_WriteAllFsm_Instance
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_FsmType, NVM_VAR_NO_INIT) NvM_WriteAllFsm_Instance;
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_WriteBlockFsm_Context
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_WriteBlockFsm_ContextType, NVM_VAR_NO_INIT) NvM_WriteBlockFsm_Context;
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_WriteBlockFsm_Instance
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_FsmType, NVM_VAR_NO_INIT) NvM_WriteBlockFsm_Instance;
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  NvM_WriteNvBlockFsm_Context
**********************************************************************************************************************/
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(NvM_WriteNvBlockFsm_ContextType, NVM_VAR_NO_INIT) NvM_WriteNvBlockFsm_Context;
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */



/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/


/* ---- end public configuration section ---------------------------------- */
#endif /* NVM_CFG_H_PUBLIC */

/**********************************************************************************************************************
 *  END OF FILE: NvM_Cfg.h
 *********************************************************************************************************************/

