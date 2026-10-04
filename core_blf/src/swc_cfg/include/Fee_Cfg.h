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
 *            Module: Fee
 *           Program: MSR_Vector_SLP4
 *          Customer: Marelli Automotive Electronics (Guangzhou) Co., Ltd.
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: CYT2B94CACQ0AZEGS
 *    License Scope : The usage is restricted to CBD2200361_D00
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Fee_Cfg.h
 *   Generation Time: 2026-03-15 14:05:47
 *           Project: DaVinci_Zeekr_Display - Version 1.0
 *          Delivery: CBD2200361_D00
 *      Tool Version: DaVinci Configurator Classic (beta) 5.25.31 SP1
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
 *  PUBLIC SECTION
 *********************************************************************************************************************/
#if !defined (FEE_CFG_H_PUBLIC)
# define FEE_CFG_H_PUBLIC

  /********************************************************************************************************************
   *  GLOBAL CONSTANT MACROS
   *******************************************************************************************************************/
  /****************************************************************************
   * VERSION IDENTIFICATION
   ***************************************************************************/
# define FEE_CFG_MAJOR_VERSION                    (10u)
# define FEE_CFG_MINOR_VERSION                    (0u)
# define FEE_CFG_PATCH_VERSION                    (0u)

  /****************************************************************************
   * API CONFIGURATION
   ***************************************************************************/
# define FEE_VERSION_INFO_API                     (STD_OFF)
# define FEE_GET_ERASE_CYCLE_API                  (STD_OFF)
# define FEE_GET_WRITE_CYCLE_API                  (STD_OFF)
# define FEE_FORCE_SECTOR_SWITCH_API              (STD_OFF)
# define FEE_FSS_CONTROL_API                      (STD_OFF)
# define FEE_DATA_CONVERSION_API                  (STD_OFF)

  /****************************************************************************
   * BEHAVIOR CONFIGURATION
   ***************************************************************************/
# define FEE_LOOKUPTABLE_MODE                     (STD_OFF)
# define FEE_EXTENDED_SECTOR_HEADER_CHECK         (STD_ON)
# define FEE_USE_RELIABLE_ERASE_PROCEDURE		  (STD_ON)

  /****************************************************************************
   * DEVELOPMENT CONFIGURATION
   ***************************************************************************/
# define FEE_DEV_ERROR_DETECT                     (STD_ON)
# define FEE_DEBUG_REPORTING                      (STD_ON)

  /****************************************************************************
   * GENERAL CONFIGURATION PARAMETER
   ***************************************************************************/

#define FeeConf_FeeBlockConfiguration_FeeDemAdminDataBlock (576u) 
#define FeeConf_FeeBlockConfiguration_FeeWDFC_ID_BOOT_PARA (560u) 
#define FeeConf_FeeBlockConfiguration_FeeWDFC_ID_ECUID_RDI_PROGRAMMING_INFO (544u) 
#define FeeConf_FeeBlockConfiguration_FeeWDFC_ID_EOL_INFO (528u) 
#define FeeConf_FeeBlockConfiguration_FeeWDFC_ID_IDOPTION_SECURITY (512u) 
#define FeeConf_FeeBlockConfiguration_FeeWDFC_ID_PART_NUMBER_GEELY (496u) 
#define FeeConf_FeeBlockConfiguration_FeeWDFC_ID_EOL_PASSWORD (480u) 
#define FeeConf_FeeBlockConfiguration_FeeWDFC_ID_EOL_SWNUMBER (464u) 
#define FeeConf_FeeBlockConfiguration_FeeWDFC_ID_EOL_HW_VERSION (448u) 
#define FeeConf_FeeBlockConfiguration_FeeConfigBlock (432u) 
#define FeeConf_FeeBlockConfiguration_FeeWDFC_ID_IDENT_BANK (416u) 
#define FeeConf_FeeBlockConfiguration_FeeWDFC_ID_CCP (400u) 
#define FeeConf_FeeBlockConfiguration_FeeWDFC_ID_WL_INFO (384u) 
#define FeeConf_FeeBlockConfiguration_FeeWDFC_ID_WLC_AP_LEARN (368u) 
#define FeeConf_FeeBlockConfiguration_FeeWDFC_ID_DLC (352u) 
#define FeeConf_FeeBlockConfiguration_FeeWDFC_ID_AP_CONNEX (336u) 
#define FeeConf_FeeBlockConfiguration_FeeWDFC_ID_HANDLE_CFG (320u) 
#define FeeConf_FeeBlockConfiguration_FeeWDFC_ID_MIRROR_CFG (304u) 
#define FeeConf_FeeBlockConfiguration_FeeWDFC_ID_PMM (288u) 
#define FeeConf_FeeBlockConfiguration_FeeWDFC_ID_SWP1 (272u) 
#define FeeConf_FeeBlockConfiguration_FeeWDFC_ID_VOL_POWER_MODE_CFG (256u) 
#define FeeConf_FeeBlockConfiguration_FeeWDFC_ID_AP_PARA (240u) 
#define FeeConf_FeeBlockConfiguration_FeeWDFC_ID_MIRROR_ST (224u) 
#define FeeConf_FeeBlockConfiguration_FeeWDFC_ID_SR_PROFILE (208u) 
#define FeeConf_FeeBlockConfiguration_FeeWDFC_ID_THPA (192u) 
#define FeeConf_FeeBlockConfiguration_FeeWDFC_ID_VEH_CFG (176u) 
#define FeeConf_FeeBlockConfiguration_FeeWDFC_ID_WL_LOG (160u) 
#define FeeConf_FeeBlockConfiguration_FeeWDFC_ID_FAULT_CODE (144u) 
#define FeeConf_FeeBlockConfiguration_FeeWDFC_ID_MAX_FDC (128u) 
#define FeeConf_FeeBlockConfiguration_FeeWDFC_ID_DTCTime (112u) 
#define FeeConf_FeeBlockConfiguration_FeeWDFC_ID_LAST_FDC (96u) 
#define FeeConf_FeeBlockConfiguration_FeeWDFC_ID_DEBUG_DATA (80u) 
#define FeeConf_FeeBlockConfiguration_FeeWDFC_ID_MIRROR_OTHER_1 (64u) 
#define FeeConf_FeeBlockConfiguration_FeeWDFC_ID_MIRROR_POS_REC (48u) 
#define FeeConf_FeeBlockConfiguration_FeeWDFC_ID_SECURITY_ACCESS (32u) 
#define FeeConf_FeeBlockConfiguration_FeeWDFC_ID_QCM_FAULT_DATA (16u) 


#define FeePartitionConfiguration4_DTC  (0u) 
#define FeePartitionConfiguration3_EOL  (1u) 
#define FeePartitionConfiguration1_BOOT (2u) 
#define FeePartitionConfiguration2_APP  (3u) 


#define FEE_NUMBER_OF_PARTITIONS (4)

#endif /* FEE_CFG_H_PUBLIC */

/**********************************************************************************************************************
 *  END OF FILE: Fee_Cfg.h
 *********************************************************************************************************************/
 

