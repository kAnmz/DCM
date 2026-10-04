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
 *              File: NvM_CfgDefines.h
 *   Generation Time: 2026-06-14 21:00:09
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
#if (!defined NVM_CFGDEFINES_H_PUBLIC)
#define NVM_CFGDEFINES_H_PUBLIC

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
 #include "Std_Types.h"

/**********************************************************************************************************************
  GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/* General public defines */
#define NVM_DEV_ERROR_DETECT STD_OFF
#define NVM_DEV_ERROR_REPORT STD_OFF
#define NVM_DEM_ERROR_REPORT STD_OFF
#define NVM_VERSION_INFO_API STD_OFF

#ifndef NVM_USE_DUMMY_STATEMENT
#define NVM_USE_DUMMY_STATEMENT STD_ON /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef NVM_DUMMY_STATEMENT
#define NVM_DUMMY_STATEMENT(v) (v)=(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef NVM_DUMMY_STATEMENT_CONST
#define NVM_DUMMY_STATEMENT_CONST(v) (void)(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef NVM_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define NVM_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef NVM_ATOMIC_VARIABLE_ACCESS
#define NVM_ATOMIC_VARIABLE_ACCESS 32u /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef NVM_PROCESSOR_CYT2B75BXX
#define NVM_PROCESSOR_CYT2B75BXX
#endif
#ifndef NVM_COMP_GREENHILLS
#define NVM_COMP_GREENHILLS
#endif
#ifndef NVM_GEN_GENERATOR_MSR
#define NVM_GEN_GENERATOR_MSR
#endif
#ifndef NVM_CPUTYPE_BITORDER_LSB2MSB
#define NVM_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/vSet/vSetPlatform/vSetBitOrder */
#endif
#ifndef NVM_CONFIGURATION_VARIANT_PRECOMPILE
#define NVM_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef NVM_CONFIGURATION_VARIANT_LINKTIME
#define NVM_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef NVM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define NVM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef NVM_CONFIGURATION_VARIANT
#define NVM_CONFIGURATION_VARIANT NVM_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef NVM_POSTBUILD_VARIANT_SUPPORT
#define NVM_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif


/* BlockIds:
 * Note: The numbers of the following list must meet the configured blocks in the NvM_BlockDescriptor
 *
 * Alignment of the handles of all blocks
 * Id 0 is reserved for multiblock calls
 * Id 1 is reserved for config ID
 */
#define NvMConf_NvMBlockDescriptor_NvMMultiBlock 0u
#define NvMConf_NvMBlockDescriptor_NvMConfigBlock 1u
#define NvMConf_NvMBlockDescriptor_DemAdminDataBlock 2u
#define NvMConf_NvMBlockDescriptor_DemStatusDataBlock 3u
#define NvMConf_NvMBlockDescriptor_WDFC_ID_IDENT_BANK 31u
#define NvMConf_NvMBlockDescriptor_WDFC_ID_CCP 32u
#define NvMConf_NvMBlockDescriptor_WDFC_ID_WL_INFO 33u
#define NvMConf_NvMBlockDescriptor_WDFC_ID_WLC_AP_LEARN 34u
#define NvMConf_NvMBlockDescriptor_WDFC_ID_DLC 35u
#define NvMConf_NvMBlockDescriptor_WDFC_ID_AP_CONNEX 36u
#define NvMConf_NvMBlockDescriptor_WDFC_ID_HANDLE_CFG 37u
#define NvMConf_NvMBlockDescriptor_WDFC_ID_MIRROR_CFG 38u
#define NvMConf_NvMBlockDescriptor_WDFC_ID_PMM 39u
#define NvMConf_NvMBlockDescriptor_WDFC_ID_SWP1 40u
#define NvMConf_NvMBlockDescriptor_WDFC_ID_VOL_POWER_MODE_CFG 41u
#define NvMConf_NvMBlockDescriptor_WDFC_ID_ECUID_RDI_PROGRAMMING_INFO 42u
#define NvMConf_NvMBlockDescriptor_WDFC_ID_AP_PARA 43u
#define NvMConf_NvMBlockDescriptor_WDFC_ID_MIRROR_ST 44u
#define NvMConf_NvMBlockDescriptor_WDFC_ID_SR_PROFILE 45u
#define NvMConf_NvMBlockDescriptor_WDFC_ID_THPA 46u
#define NvMConf_NvMBlockDescriptor_WDFC_ID_VEH_CFG 47u
#define NvMConf_NvMBlockDescriptor_WDFC_ID_WL_LOG 48u
#define NvMConf_NvMBlockDescriptor_WDFC_ID_FAULT_CODE 49u
#define NvMConf_NvMBlockDescriptor_WDFC_ID_BOOT_PARA 50u
#define NvMConf_NvMBlockDescriptor_WDFC_ID_EOL_INFO 51u
#define NvMConf_NvMBlockDescriptor_WDFC_ID_IDOPTION_SECURITY 52u
#define NvMConf_NvMBlockDescriptor_WDFC_ID_MAX_FDC 53u
#define NvMConf_NvMBlockDescriptor_WDFC_ID_DTCTime 88u
#define NvMConf_NvMBlockDescriptor_WDFC_ID_PART_NUMBER_GEELY 89u
#define NvMConf_NvMBlockDescriptor_WDFC_ID_EOL_PASSWORD 90u
#define NvMConf_NvMBlockDescriptor_WDFC_ID_LAST_FDC 91u
#define NvMConf_NvMBlockDescriptor_WDFC_ID_DEBUG_DATA 92u
#define NvMConf_NvMBlockDescriptor_WDFC_ID_MIRROR_OTHER_1 93u
#define NvMConf_NvMBlockDescriptor_WDFC_ID_MIRROR_POS_REC 94u
#define NvMConf_NvMBlockDescriptor_WDFC_ID_EOL_SWNUMBER 95u
#define NvMConf_NvMBlockDescriptor_WDFC_ID_EOL_HW_VERSION 96u
#define NvMConf_NvMBlockDescriptor_WDFC_ID_SECURITY_ACCESS 97u
#define NvMConf_NvMBlockDescriptor_WDFC_ID_QCM_FAULT_DATA 98u


/* General NvM internal defines */
#define NVM_CRC_NUM_OF_BYTES_PER_CYCLE 512u
#define NVM_SIZE_STANDARD_JOB_QUEUE 25u
#define NVM_NUM_OF_BLOCKDESCRIPTORS 37u
#define NVM_SINGLEBLOCK_FSMLIB_PROCESSING_STACK_SIZE 4u
#define NVM_MULTIBLOCK_FSMLIB_PROCESSING_STACK_SIZE 2u
#define NVM_NVSERVICE_FSMLIB_PROCESSING_STACK_SIZE 2u
#define NVM_SERVICE_PROCESSOR_FSMLIB_PROCESSING_STACK_SIZE 1u
#define NVM_BACKGROUNDCRCRECALC_FSMLIB_PROCESSING_STACK_SIZE 1u
#define NVM_FSMLIB_PROCESSING_STACK_INDEX_NONE -1
#define NVM_FSMLIB_PROCESSING_MAX_STEPS 50u
#define NVM_MULTIPARTITION_USAGE_SCENARIO STD_OFF
#define NVM_USE_BLOCK_ID_CHECK STD_OFF
#define NVM_DYNAMIC_CONFIGURATION STD_ON
#define NVM_USE_CONFIG_ID_CALLBACK STD_OFF
#define NVM_COMPILED_CONFIG_ID 13u
#define NVM_CONFIG_BLOCK_PAYLOAD_LENGTH 2u
#define NVM_USE_ASR440_CALLBACK_INTERFACE STD_OFF
#define NVM_USE_DATA_INTEGRITY_INT_BUFFER STD_ON
#define NVM_JOB_PRIORITIZATION  STD_OFF
#define NVM_MAC_ENABLED STD_OFF
#define NVM_CSM_RETRY_COUNT  0u
#define NVM_MAX_NO_OF_WRITE_RETRIES 1u


/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  NvMPCDataSwitches  NvM Data Switches  (PRE_COMPILE)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define NVM_BACKGROUNDCRCRECALCFSMLIB_INSTANCE                                                      STD_ON
#define NVM_BACKGROUNDCRCRECALCFSMLIB_PROCESSINGSTACKELEMENT                                        STD_ON
#define NVM_BACKGROUNDCRCRECALCFSM_CONTEXT                                                          STD_ON
#define NVM_BACKGROUNDCRCRECALCFSM_INSTANCE                                                         STD_ON
#define NVM_BACKGROUNDDATAINTEGRITYSERVICE_INSTANCE                                                 STD_ON
#define NVM_BLOCKDESCRIPTOR                                                                         STD_ON
#define NVM_BLOCKMANAGEMENTINFO_DEMADMINDATABLOCK                                                   STD_ON
#define NVM_BLOCKMANAGEMENTINFO_DEMSTATUSDATABLOCK                                                  STD_ON
#define NVM_BLOCKMANAGEMENTINFO_NVMCONFIGBLOCK                                                      STD_ON
#define NVM_BLOCKMANAGEMENTINFO_NVMMULTIBLOCK                                                       STD_ON
#define NVM_BLOCKMANAGEMENTINFO_WDFC_ID_AP_CONNEX                                                   STD_ON
#define NVM_BLOCKMANAGEMENTINFO_WDFC_ID_AP_PARA                                                     STD_ON
#define NVM_BLOCKMANAGEMENTINFO_WDFC_ID_BOOT_PARA                                                   STD_ON
#define NVM_BLOCKMANAGEMENTINFO_WDFC_ID_CCP                                                         STD_ON
#define NVM_BLOCKMANAGEMENTINFO_WDFC_ID_DEBUG_DATA                                                  STD_ON
#define NVM_BLOCKMANAGEMENTINFO_WDFC_ID_DLC                                                         STD_ON
#define NVM_BLOCKMANAGEMENTINFO_WDFC_ID_DTCTIME                                                     STD_ON
#define NVM_BLOCKMANAGEMENTINFO_WDFC_ID_ECUID_RDI_PROGRAMMING_INFO                                  STD_ON
#define NVM_BLOCKMANAGEMENTINFO_WDFC_ID_EOL_HW_VERSION                                              STD_ON
#define NVM_BLOCKMANAGEMENTINFO_WDFC_ID_EOL_INFO                                                    STD_ON
#define NVM_BLOCKMANAGEMENTINFO_WDFC_ID_EOL_PASSWORD                                                STD_ON
#define NVM_BLOCKMANAGEMENTINFO_WDFC_ID_EOL_SWNUMBER                                                STD_ON
#define NVM_BLOCKMANAGEMENTINFO_WDFC_ID_FAULT_CODE                                                  STD_ON
#define NVM_BLOCKMANAGEMENTINFO_WDFC_ID_HANDLE_CFG                                                  STD_ON
#define NVM_BLOCKMANAGEMENTINFO_WDFC_ID_IDENT_BANK                                                  STD_ON
#define NVM_BLOCKMANAGEMENTINFO_WDFC_ID_IDOPTION_SECURITY                                           STD_ON
#define NVM_BLOCKMANAGEMENTINFO_WDFC_ID_LAST_FDC                                                    STD_ON
#define NVM_BLOCKMANAGEMENTINFO_WDFC_ID_MAX_FDC                                                     STD_ON
#define NVM_BLOCKMANAGEMENTINFO_WDFC_ID_MIRROR_CFG                                                  STD_ON
#define NVM_BLOCKMANAGEMENTINFO_WDFC_ID_MIRROR_OTHER_1                                              STD_ON
#define NVM_BLOCKMANAGEMENTINFO_WDFC_ID_MIRROR_POS_REC                                              STD_ON
#define NVM_BLOCKMANAGEMENTINFO_WDFC_ID_MIRROR_ST                                                   STD_ON
#define NVM_BLOCKMANAGEMENTINFO_WDFC_ID_PART_NUMBER_GEELY                                           STD_ON
#define NVM_BLOCKMANAGEMENTINFO_WDFC_ID_PMM                                                         STD_ON
#define NVM_BLOCKMANAGEMENTINFO_WDFC_ID_QCM_FAULT_DATA                                              STD_ON
#define NVM_BLOCKMANAGEMENTINFO_WDFC_ID_SECURITY_ACCESS                                             STD_ON
#define NVM_BLOCKMANAGEMENTINFO_WDFC_ID_SR_PROFILE                                                  STD_ON
#define NVM_BLOCKMANAGEMENTINFO_WDFC_ID_SWP1                                                        STD_ON
#define NVM_BLOCKMANAGEMENTINFO_WDFC_ID_THPA                                                        STD_ON
#define NVM_BLOCKMANAGEMENTINFO_WDFC_ID_VEH_CFG                                                     STD_ON
#define NVM_BLOCKMANAGEMENTINFO_WDFC_ID_VOL_POWER_MODE_CFG                                          STD_ON
#define NVM_BLOCKMANAGEMENTINFO_WDFC_ID_WLC_AP_LEARN                                                STD_ON
#define NVM_BLOCKMANAGEMENTINFO_WDFC_ID_WL_INFO                                                     STD_ON
#define NVM_BLOCKMANAGEMENTINFO_WDFC_ID_WL_LOG                                                      STD_ON
#define NVM_CRCCOMPMECHANISMBUFFER_DEMADMINDATABLOCK                                                STD_ON
#define NVM_CRCCOMPMECHANISMBUFFER_DEMSTATUSDATABLOCK                                               STD_ON
#define NVM_CRCCOMPMECHANISMBUFFER_NVMCONFIGBLOCK                                                   STD_ON
#define NVM_CRCCOMPMECHANISMBUFFER_WDFC_ID_AP_CONNEX                                                STD_ON
#define NVM_CRCCOMPMECHANISMBUFFER_WDFC_ID_AP_PARA                                                  STD_ON
#define NVM_CRCCOMPMECHANISMBUFFER_WDFC_ID_BOOT_PARA                                                STD_ON
#define NVM_CRCCOMPMECHANISMBUFFER_WDFC_ID_CCP                                                      STD_ON
#define NVM_CRCCOMPMECHANISMBUFFER_WDFC_ID_DEBUG_DATA                                               STD_ON
#define NVM_CRCCOMPMECHANISMBUFFER_WDFC_ID_DLC                                                      STD_ON
#define NVM_CRCCOMPMECHANISMBUFFER_WDFC_ID_DTCTIME                                                  STD_ON
#define NVM_CRCCOMPMECHANISMBUFFER_WDFC_ID_ECUID_RDI_PROGRAMMING_INFO                               STD_ON
#define NVM_CRCCOMPMECHANISMBUFFER_WDFC_ID_EOL_HW_VERSION                                           STD_ON
#define NVM_CRCCOMPMECHANISMBUFFER_WDFC_ID_EOL_INFO                                                 STD_ON
#define NVM_CRCCOMPMECHANISMBUFFER_WDFC_ID_EOL_PASSWORD                                             STD_ON
#define NVM_CRCCOMPMECHANISMBUFFER_WDFC_ID_EOL_SWNUMBER                                             STD_ON
#define NVM_CRCCOMPMECHANISMBUFFER_WDFC_ID_FAULT_CODE                                               STD_ON
#define NVM_CRCCOMPMECHANISMBUFFER_WDFC_ID_HANDLE_CFG                                               STD_ON
#define NVM_CRCCOMPMECHANISMBUFFER_WDFC_ID_IDENT_BANK                                               STD_ON
#define NVM_CRCCOMPMECHANISMBUFFER_WDFC_ID_IDOPTION_SECURITY                                        STD_ON
#define NVM_CRCCOMPMECHANISMBUFFER_WDFC_ID_LAST_FDC                                                 STD_ON
#define NVM_CRCCOMPMECHANISMBUFFER_WDFC_ID_MAX_FDC                                                  STD_ON
#define NVM_CRCCOMPMECHANISMBUFFER_WDFC_ID_MIRROR_CFG                                               STD_ON
#define NVM_CRCCOMPMECHANISMBUFFER_WDFC_ID_MIRROR_OTHER_1                                           STD_ON
#define NVM_CRCCOMPMECHANISMBUFFER_WDFC_ID_MIRROR_POS_REC                                           STD_ON
#define NVM_CRCCOMPMECHANISMBUFFER_WDFC_ID_MIRROR_ST                                                STD_ON
#define NVM_CRCCOMPMECHANISMBUFFER_WDFC_ID_PART_NUMBER_GEELY                                        STD_ON
#define NVM_CRCCOMPMECHANISMBUFFER_WDFC_ID_PMM                                                      STD_ON
#define NVM_CRCCOMPMECHANISMBUFFER_WDFC_ID_QCM_FAULT_DATA                                           STD_ON
#define NVM_CRCCOMPMECHANISMBUFFER_WDFC_ID_SECURITY_ACCESS                                          STD_ON
#define NVM_CRCCOMPMECHANISMBUFFER_WDFC_ID_SR_PROFILE                                               STD_ON
#define NVM_CRCCOMPMECHANISMBUFFER_WDFC_ID_SWP1                                                     STD_ON
#define NVM_CRCCOMPMECHANISMBUFFER_WDFC_ID_THPA                                                     STD_ON
#define NVM_CRCCOMPMECHANISMBUFFER_WDFC_ID_VEH_CFG                                                  STD_ON
#define NVM_CRCCOMPMECHANISMBUFFER_WDFC_ID_VOL_POWER_MODE_CFG                                       STD_ON
#define NVM_CRCCOMPMECHANISMBUFFER_WDFC_ID_WLC_AP_LEARN                                             STD_ON
#define NVM_CRCCOMPMECHANISMBUFFER_WDFC_ID_WL_INFO                                                  STD_ON
#define NVM_CRCCOMPMECHANISMBUFFER_WDFC_ID_WL_LOG                                                   STD_ON
#define NVM_CRCINTERNALEXPLICITSYNCBUFFER                                                           STD_OFF  /**< Deactivateable: 'NvM_CrcInternalExplicitSyncBuffer' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define NVM_DATAINTEGRITYFSM_INSTANCE                                                               STD_ON
#define NVM_DATAINTEGRITYINTBUFFER_DEMADMINDATABLOCK                                                STD_ON
#define NVM_DATAINTEGRITYINTBUFFER_DEMSTATUSDATABLOCK                                               STD_ON
#define NVM_DATAINTEGRITYINTBUFFER_WDFC_ID_AP_CONNEX                                                STD_ON
#define NVM_DATAINTEGRITYINTBUFFER_WDFC_ID_AP_PARA                                                  STD_ON
#define NVM_DATAINTEGRITYINTBUFFER_WDFC_ID_BOOT_PARA                                                STD_ON
#define NVM_DATAINTEGRITYINTBUFFER_WDFC_ID_CCP                                                      STD_ON
#define NVM_DATAINTEGRITYINTBUFFER_WDFC_ID_DEBUG_DATA                                               STD_ON
#define NVM_DATAINTEGRITYINTBUFFER_WDFC_ID_DLC                                                      STD_ON
#define NVM_DATAINTEGRITYINTBUFFER_WDFC_ID_DTCTIME                                                  STD_ON
#define NVM_DATAINTEGRITYINTBUFFER_WDFC_ID_ECUID_RDI_PROGRAMMING_INFO                               STD_ON
#define NVM_DATAINTEGRITYINTBUFFER_WDFC_ID_EOL_HW_VERSION                                           STD_ON
#define NVM_DATAINTEGRITYINTBUFFER_WDFC_ID_EOL_INFO                                                 STD_ON
#define NVM_DATAINTEGRITYINTBUFFER_WDFC_ID_EOL_PASSWORD                                             STD_ON
#define NVM_DATAINTEGRITYINTBUFFER_WDFC_ID_EOL_SWNUMBER                                             STD_ON
#define NVM_DATAINTEGRITYINTBUFFER_WDFC_ID_FAULT_CODE                                               STD_ON
#define NVM_DATAINTEGRITYINTBUFFER_WDFC_ID_HANDLE_CFG                                               STD_ON
#define NVM_DATAINTEGRITYINTBUFFER_WDFC_ID_IDENT_BANK                                               STD_ON
#define NVM_DATAINTEGRITYINTBUFFER_WDFC_ID_IDOPTION_SECURITY                                        STD_ON
#define NVM_DATAINTEGRITYINTBUFFER_WDFC_ID_LAST_FDC                                                 STD_ON
#define NVM_DATAINTEGRITYINTBUFFER_WDFC_ID_MAX_FDC                                                  STD_ON
#define NVM_DATAINTEGRITYINTBUFFER_WDFC_ID_MIRROR_CFG                                               STD_ON
#define NVM_DATAINTEGRITYINTBUFFER_WDFC_ID_MIRROR_OTHER_1                                           STD_ON
#define NVM_DATAINTEGRITYINTBUFFER_WDFC_ID_MIRROR_POS_REC                                           STD_ON
#define NVM_DATAINTEGRITYINTBUFFER_WDFC_ID_MIRROR_ST                                                STD_ON
#define NVM_DATAINTEGRITYINTBUFFER_WDFC_ID_PART_NUMBER_GEELY                                        STD_ON
#define NVM_DATAINTEGRITYINTBUFFER_WDFC_ID_PMM                                                      STD_ON
#define NVM_DATAINTEGRITYINTBUFFER_WDFC_ID_QCM_FAULT_DATA                                           STD_ON
#define NVM_DATAINTEGRITYINTBUFFER_WDFC_ID_SECURITY_ACCESS                                          STD_ON
#define NVM_DATAINTEGRITYINTBUFFER_WDFC_ID_SR_PROFILE                                               STD_ON
#define NVM_DATAINTEGRITYINTBUFFER_WDFC_ID_SWP1                                                     STD_ON
#define NVM_DATAINTEGRITYINTBUFFER_WDFC_ID_THPA                                                     STD_ON
#define NVM_DATAINTEGRITYINTBUFFER_WDFC_ID_VEH_CFG                                                  STD_ON
#define NVM_DATAINTEGRITYINTBUFFER_WDFC_ID_VOL_POWER_MODE_CFG                                       STD_ON
#define NVM_DATAINTEGRITYINTBUFFER_WDFC_ID_WLC_AP_LEARN                                             STD_ON
#define NVM_DATAINTEGRITYINTBUFFER_WDFC_ID_WL_INFO                                                  STD_ON
#define NVM_DATAINTEGRITYINTBUFFER_WDFC_ID_WL_LOG                                                   STD_ON
#define NVM_DATAINTEGRITYRECALCQUEUE_INSTANCE                                                       STD_ON
#define NVM_DCMBLOCKMANAGEMENTINFO                                                                  STD_ON
#define NVM_FINALMAGICNUMBER                                                                        STD_OFF  /**< Deactivateable: 'NvM_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define NVM_FOREGROUNDDATAINTEGRITYSERVICE_INSTANCE                                                 STD_ON
#define NVM_INITDATAHASHCODE                                                                        STD_OFF  /**< Deactivateable: 'NvM_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define NVM_INTERNALBUFFER                                                                          STD_ON
#define NVM_MULTIBLOCKFSMLIB_PROCESSINGSTACKELEMENT                                                 STD_ON
#define NVM_MULTIBLOCKJOB                                                                           STD_ON
#define NVM_MULTIBLOCKJOBFSM_CONTEXT                                                                STD_ON
#define NVM_MULTIBLOCKJOBFSM_INSTANCE                                                               STD_ON
#define NVM_MULTIBLOCKJOBINFORMATION                                                                STD_ON
#define NVM_MULTIBLOCKPROCESSORFSMLIB_INSTANCE                                                      STD_ON
#define NVM_MULTIBLOCKPROCESSORFSMLIB_PROCESSINGSTACKELEMENT                                        STD_ON
#define NVM_MULTIBLOCKSERVICEFSMLIB_INSTANCE                                                        STD_ON
#define NVM_NVJOBCONTEXT                                                                            STD_ON
#define NVM_NVJOBFSM_INSTANCE                                                                       STD_ON
#define NVM_NVSERVICEFSMLIB_INSTANCE                                                                STD_ON
#define NVM_NVSERVICEFSMLIB_PROCESSINGSTACKELEMENT                                                  STD_ON
#define NVM_NVSERVICEPROCESSORFSMLIB_INSTANCE                                                       STD_ON
#define NVM_NVSERVICEPROCESSORFSMLIB_PROCESSINGSTACKELEMENT                                         STD_ON
#define NVM_PARTITIONIDENTIFIERS                                                                    STD_ON
#define NVM_PCPARTITIONCONFIGIDXOFPARTITIONIDENTIFIERS                                              STD_ON
#define NVM_PARTITIONSNVOFPARTITIONIDENTIFIERS                                                      STD_ON
#define NVM_QUEUELIST                                                                               STD_ON
#define NVM_QUEUE_INSTANCE                                                                          STD_ON
#define NVM_READALLFSM_CONTEXT                                                                      STD_ON
#define NVM_READALLFSM_INSTANCE                                                                     STD_ON
#define NVM_READBLOCKFSM_CONTEXT                                                                    STD_ON
#define NVM_READBLOCKFSM_INSTANCE                                                                   STD_ON
#define NVM_SERVICEPROCESSORFSMLIB_INSTANCE                                                         STD_ON
#define NVM_SERVICEPROCESSORFSMLIB_PROCESSINGSTACKELEMENT                                           STD_ON
#define NVM_SERVICEPROCESSORFSM_CONTEXT                                                             STD_ON
#define NVM_SERVICEPROCESSORFSM_INSTANCE                                                            STD_ON
#define NVM_SINGLEBLOCKFSMLIB_PROCESSINGSTACKELEMENT                                                STD_ON
#define NVM_SINGLEBLOCKJOBCONTEXT                                                                   STD_ON
#define NVM_SINGLEBLOCKJOBFSM_INSTANCE                                                              STD_ON
#define NVM_SINGLEBLOCKSERVICEFSMLIB_INSTANCE                                                       STD_ON
#define NVM_SIZEOFBACKGROUNDCRCRECALCFSMLIB_PROCESSINGSTACKELEMENT                                  STD_ON
#define NVM_SIZEOFBLOCKDESCRIPTOR                                                                   STD_ON
#define NVM_SIZEOFCRCCOMPMECHANISMBUFFER_DEMADMINDATABLOCK                                          STD_ON
#define NVM_SIZEOFCRCCOMPMECHANISMBUFFER_DEMSTATUSDATABLOCK                                         STD_ON
#define NVM_SIZEOFCRCCOMPMECHANISMBUFFER_NVMCONFIGBLOCK                                             STD_ON
#define NVM_SIZEOFCRCCOMPMECHANISMBUFFER_WDFC_ID_AP_CONNEX                                          STD_ON
#define NVM_SIZEOFCRCCOMPMECHANISMBUFFER_WDFC_ID_AP_PARA                                            STD_ON
#define NVM_SIZEOFCRCCOMPMECHANISMBUFFER_WDFC_ID_BOOT_PARA                                          STD_ON
#define NVM_SIZEOFCRCCOMPMECHANISMBUFFER_WDFC_ID_CCP                                                STD_ON
#define NVM_SIZEOFCRCCOMPMECHANISMBUFFER_WDFC_ID_DEBUG_DATA                                         STD_ON
#define NVM_SIZEOFCRCCOMPMECHANISMBUFFER_WDFC_ID_DLC                                                STD_ON
#define NVM_SIZEOFCRCCOMPMECHANISMBUFFER_WDFC_ID_DTCTIME                                            STD_ON
#define NVM_SIZEOFCRCCOMPMECHANISMBUFFER_WDFC_ID_ECUID_RDI_PROGRAMMING_INFO                         STD_ON
#define NVM_SIZEOFCRCCOMPMECHANISMBUFFER_WDFC_ID_EOL_HW_VERSION                                     STD_ON
#define NVM_SIZEOFCRCCOMPMECHANISMBUFFER_WDFC_ID_EOL_INFO                                           STD_ON
#define NVM_SIZEOFCRCCOMPMECHANISMBUFFER_WDFC_ID_EOL_PASSWORD                                       STD_ON
#define NVM_SIZEOFCRCCOMPMECHANISMBUFFER_WDFC_ID_EOL_SWNUMBER                                       STD_ON
#define NVM_SIZEOFCRCCOMPMECHANISMBUFFER_WDFC_ID_FAULT_CODE                                         STD_ON
#define NVM_SIZEOFCRCCOMPMECHANISMBUFFER_WDFC_ID_HANDLE_CFG                                         STD_ON
#define NVM_SIZEOFCRCCOMPMECHANISMBUFFER_WDFC_ID_IDENT_BANK                                         STD_ON
#define NVM_SIZEOFCRCCOMPMECHANISMBUFFER_WDFC_ID_IDOPTION_SECURITY                                  STD_ON
#define NVM_SIZEOFCRCCOMPMECHANISMBUFFER_WDFC_ID_LAST_FDC                                           STD_ON
#define NVM_SIZEOFCRCCOMPMECHANISMBUFFER_WDFC_ID_MAX_FDC                                            STD_ON
#define NVM_SIZEOFCRCCOMPMECHANISMBUFFER_WDFC_ID_MIRROR_CFG                                         STD_ON
#define NVM_SIZEOFCRCCOMPMECHANISMBUFFER_WDFC_ID_MIRROR_OTHER_1                                     STD_ON
#define NVM_SIZEOFCRCCOMPMECHANISMBUFFER_WDFC_ID_MIRROR_POS_REC                                     STD_ON
#define NVM_SIZEOFCRCCOMPMECHANISMBUFFER_WDFC_ID_MIRROR_ST                                          STD_ON
#define NVM_SIZEOFCRCCOMPMECHANISMBUFFER_WDFC_ID_PART_NUMBER_GEELY                                  STD_ON
#define NVM_SIZEOFCRCCOMPMECHANISMBUFFER_WDFC_ID_PMM                                                STD_ON
#define NVM_SIZEOFCRCCOMPMECHANISMBUFFER_WDFC_ID_QCM_FAULT_DATA                                     STD_ON
#define NVM_SIZEOFCRCCOMPMECHANISMBUFFER_WDFC_ID_SECURITY_ACCESS                                    STD_ON
#define NVM_SIZEOFCRCCOMPMECHANISMBUFFER_WDFC_ID_SR_PROFILE                                         STD_ON
#define NVM_SIZEOFCRCCOMPMECHANISMBUFFER_WDFC_ID_SWP1                                               STD_ON
#define NVM_SIZEOFCRCCOMPMECHANISMBUFFER_WDFC_ID_THPA                                               STD_ON
#define NVM_SIZEOFCRCCOMPMECHANISMBUFFER_WDFC_ID_VEH_CFG                                            STD_ON
#define NVM_SIZEOFCRCCOMPMECHANISMBUFFER_WDFC_ID_VOL_POWER_MODE_CFG                                 STD_ON
#define NVM_SIZEOFCRCCOMPMECHANISMBUFFER_WDFC_ID_WLC_AP_LEARN                                       STD_ON
#define NVM_SIZEOFCRCCOMPMECHANISMBUFFER_WDFC_ID_WL_INFO                                            STD_ON
#define NVM_SIZEOFCRCCOMPMECHANISMBUFFER_WDFC_ID_WL_LOG                                             STD_ON
#define NVM_SIZEOFCRCINTERNALEXPLICITSYNCBUFFER                                                     STD_OFF  /**< Deactivateable: 'NvM_SizeOfCrcInternalExplicitSyncBuffer' Reason: 'Deactivateable: 'CrcInternalExplicitSyncBuffer' Reason: 'Deactivateable: 'NvM_CrcInternalExplicitSyncBuffer' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE''' */
#define NVM_SIZEOFDATAINTEGRITYINTBUFFER_DEMADMINDATABLOCK                                          STD_ON
#define NVM_SIZEOFDATAINTEGRITYINTBUFFER_DEMSTATUSDATABLOCK                                         STD_ON
#define NVM_SIZEOFDATAINTEGRITYINTBUFFER_WDFC_ID_AP_CONNEX                                          STD_ON
#define NVM_SIZEOFDATAINTEGRITYINTBUFFER_WDFC_ID_AP_PARA                                            STD_ON
#define NVM_SIZEOFDATAINTEGRITYINTBUFFER_WDFC_ID_BOOT_PARA                                          STD_ON
#define NVM_SIZEOFDATAINTEGRITYINTBUFFER_WDFC_ID_CCP                                                STD_ON
#define NVM_SIZEOFDATAINTEGRITYINTBUFFER_WDFC_ID_DEBUG_DATA                                         STD_ON
#define NVM_SIZEOFDATAINTEGRITYINTBUFFER_WDFC_ID_DLC                                                STD_ON
#define NVM_SIZEOFDATAINTEGRITYINTBUFFER_WDFC_ID_DTCTIME                                            STD_ON
#define NVM_SIZEOFDATAINTEGRITYINTBUFFER_WDFC_ID_ECUID_RDI_PROGRAMMING_INFO                         STD_ON
#define NVM_SIZEOFDATAINTEGRITYINTBUFFER_WDFC_ID_EOL_HW_VERSION                                     STD_ON
#define NVM_SIZEOFDATAINTEGRITYINTBUFFER_WDFC_ID_EOL_INFO                                           STD_ON
#define NVM_SIZEOFDATAINTEGRITYINTBUFFER_WDFC_ID_EOL_PASSWORD                                       STD_ON
#define NVM_SIZEOFDATAINTEGRITYINTBUFFER_WDFC_ID_EOL_SWNUMBER                                       STD_ON
#define NVM_SIZEOFDATAINTEGRITYINTBUFFER_WDFC_ID_FAULT_CODE                                         STD_ON
#define NVM_SIZEOFDATAINTEGRITYINTBUFFER_WDFC_ID_HANDLE_CFG                                         STD_ON
#define NVM_SIZEOFDATAINTEGRITYINTBUFFER_WDFC_ID_IDENT_BANK                                         STD_ON
#define NVM_SIZEOFDATAINTEGRITYINTBUFFER_WDFC_ID_IDOPTION_SECURITY                                  STD_ON
#define NVM_SIZEOFDATAINTEGRITYINTBUFFER_WDFC_ID_LAST_FDC                                           STD_ON
#define NVM_SIZEOFDATAINTEGRITYINTBUFFER_WDFC_ID_MAX_FDC                                            STD_ON
#define NVM_SIZEOFDATAINTEGRITYINTBUFFER_WDFC_ID_MIRROR_CFG                                         STD_ON
#define NVM_SIZEOFDATAINTEGRITYINTBUFFER_WDFC_ID_MIRROR_OTHER_1                                     STD_ON
#define NVM_SIZEOFDATAINTEGRITYINTBUFFER_WDFC_ID_MIRROR_POS_REC                                     STD_ON
#define NVM_SIZEOFDATAINTEGRITYINTBUFFER_WDFC_ID_MIRROR_ST                                          STD_ON
#define NVM_SIZEOFDATAINTEGRITYINTBUFFER_WDFC_ID_PART_NUMBER_GEELY                                  STD_ON
#define NVM_SIZEOFDATAINTEGRITYINTBUFFER_WDFC_ID_PMM                                                STD_ON
#define NVM_SIZEOFDATAINTEGRITYINTBUFFER_WDFC_ID_QCM_FAULT_DATA                                     STD_ON
#define NVM_SIZEOFDATAINTEGRITYINTBUFFER_WDFC_ID_SECURITY_ACCESS                                    STD_ON
#define NVM_SIZEOFDATAINTEGRITYINTBUFFER_WDFC_ID_SR_PROFILE                                         STD_ON
#define NVM_SIZEOFDATAINTEGRITYINTBUFFER_WDFC_ID_SWP1                                               STD_ON
#define NVM_SIZEOFDATAINTEGRITYINTBUFFER_WDFC_ID_THPA                                               STD_ON
#define NVM_SIZEOFDATAINTEGRITYINTBUFFER_WDFC_ID_VEH_CFG                                            STD_ON
#define NVM_SIZEOFDATAINTEGRITYINTBUFFER_WDFC_ID_VOL_POWER_MODE_CFG                                 STD_ON
#define NVM_SIZEOFDATAINTEGRITYINTBUFFER_WDFC_ID_WLC_AP_LEARN                                       STD_ON
#define NVM_SIZEOFDATAINTEGRITYINTBUFFER_WDFC_ID_WL_INFO                                            STD_ON
#define NVM_SIZEOFDATAINTEGRITYINTBUFFER_WDFC_ID_WL_LOG                                             STD_ON
#define NVM_SIZEOFINTERNALBUFFER                                                                    STD_ON
#define NVM_SIZEOFMULTIBLOCKFSMLIB_PROCESSINGSTACKELEMENT                                           STD_ON
#define NVM_SIZEOFMULTIBLOCKPROCESSORFSMLIB_PROCESSINGSTACKELEMENT                                  STD_ON
#define NVM_SIZEOFNVSERVICEFSMLIB_PROCESSINGSTACKELEMENT                                            STD_ON
#define NVM_SIZEOFNVSERVICEPROCESSORFSMLIB_PROCESSINGSTACKELEMENT                                   STD_ON
#define NVM_SIZEOFPARTITIONIDENTIFIERS                                                              STD_ON
#define NVM_SIZEOFQUEUELIST                                                                         STD_ON
#define NVM_SIZEOFSERVICEPROCESSORFSMLIB_PROCESSINGSTACKELEMENT                                     STD_ON
#define NVM_SIZEOFSINGLEBLOCKFSMLIB_PROCESSINGSTACKELEMENT                                          STD_ON
#define NVM_VALIDATEALLFSM_INSTANCE                                                                 STD_ON
#define NVM_WRITEALLFSM_CONTEXT                                                                     STD_ON
#define NVM_WRITEALLFSM_INSTANCE                                                                    STD_ON
#define NVM_WRITEBLOCKFSM_CONTEXT                                                                   STD_ON
#define NVM_WRITEBLOCKFSM_INSTANCE                                                                  STD_ON
#define NVM_WRITENVBLOCKFSM_CONTEXT                                                                 STD_ON
#define NVM_PCCONFIG                                                                                STD_ON
#define NVM_FINALMAGICNUMBEROFPCCONFIG                                                              STD_OFF  /**< Deactivateable: 'NvM_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define NVM_INITDATAHASHCODEOFPCCONFIG                                                              STD_OFF  /**< Deactivateable: 'NvM_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define NVM_PCPARTITIONCONFIGOFPCCONFIG                                                             STD_ON
#define NVM_PARTITIONIDENTIFIERSOFPCCONFIG                                                          STD_ON
#define NVM_SIZEOFPARTITIONIDENTIFIERSOFPCCONFIG                                                    STD_ON
#define NVM_PCPARTITIONCONFIG                                                                       STD_ON
#define NVM_BACKGROUNDCRCRECALCFSMLIB_INSTANCEOFPCPARTITIONCONFIG                                   STD_ON
#define NVM_BACKGROUNDCRCRECALCFSMLIB_PROCESSINGSTACKELEMENTOFPCPARTITIONCONFIG                     STD_ON
#define NVM_BACKGROUNDCRCRECALCFSM_CONTEXTOFPCPARTITIONCONFIG                                       STD_ON
#define NVM_BACKGROUNDCRCRECALCFSM_INSTANCEOFPCPARTITIONCONFIG                                      STD_ON
#define NVM_BACKGROUNDDATAINTEGRITYSERVICE_INSTANCEOFPCPARTITIONCONFIG                              STD_ON
#define NVM_BLOCKDESCRIPTOROFPCPARTITIONCONFIG                                                      STD_ON
#define NVM_BLOCKMANAGEMENTINFO_DEMADMINDATABLOCKOFPCPARTITIONCONFIG                                STD_ON
#define NVM_BLOCKMANAGEMENTINFO_DEMSTATUSDATABLOCKOFPCPARTITIONCONFIG                               STD_ON
#define NVM_BLOCKMANAGEMENTINFO_NVMCONFIGBLOCKOFPCPARTITIONCONFIG                                   STD_ON
#define NVM_BLOCKMANAGEMENTINFO_NVMMULTIBLOCKOFPCPARTITIONCONFIG                                    STD_ON
#define NVM_BLOCKMANAGEMENTINFO_WDFC_ID_AP_CONNEXOFPCPARTITIONCONFIG                                STD_ON
#define NVM_BLOCKMANAGEMENTINFO_WDFC_ID_AP_PARAOFPCPARTITIONCONFIG                                  STD_ON
#define NVM_BLOCKMANAGEMENTINFO_WDFC_ID_BOOT_PARAOFPCPARTITIONCONFIG                                STD_ON
#define NVM_BLOCKMANAGEMENTINFO_WDFC_ID_CCPOFPCPARTITIONCONFIG                                      STD_ON
#define NVM_BLOCKMANAGEMENTINFO_WDFC_ID_DEBUG_DATAOFPCPARTITIONCONFIG                               STD_ON
#define NVM_BLOCKMANAGEMENTINFO_WDFC_ID_DLCOFPCPARTITIONCONFIG                                      STD_ON
#define NVM_BLOCKMANAGEMENTINFO_WDFC_ID_DTCTIMEOFPCPARTITIONCONFIG                                  STD_ON
#define NVM_BLOCKMANAGEMENTINFO_WDFC_ID_ECUID_RDI_PROGRAMMING_INFOOFPCPARTITIONCONFIG               STD_ON
#define NVM_BLOCKMANAGEMENTINFO_WDFC_ID_EOL_HW_VERSIONOFPCPARTITIONCONFIG                           STD_ON
#define NVM_BLOCKMANAGEMENTINFO_WDFC_ID_EOL_INFOOFPCPARTITIONCONFIG                                 STD_ON
#define NVM_BLOCKMANAGEMENTINFO_WDFC_ID_EOL_PASSWORDOFPCPARTITIONCONFIG                             STD_ON
#define NVM_BLOCKMANAGEMENTINFO_WDFC_ID_EOL_SWNUMBEROFPCPARTITIONCONFIG                             STD_ON
#define NVM_BLOCKMANAGEMENTINFO_WDFC_ID_FAULT_CODEOFPCPARTITIONCONFIG                               STD_ON
#define NVM_BLOCKMANAGEMENTINFO_WDFC_ID_HANDLE_CFGOFPCPARTITIONCONFIG                               STD_ON
#define NVM_BLOCKMANAGEMENTINFO_WDFC_ID_IDENT_BANKOFPCPARTITIONCONFIG                               STD_ON
#define NVM_BLOCKMANAGEMENTINFO_WDFC_ID_IDOPTION_SECURITYOFPCPARTITIONCONFIG                        STD_ON
#define NVM_BLOCKMANAGEMENTINFO_WDFC_ID_LAST_FDCOFPCPARTITIONCONFIG                                 STD_ON
#define NVM_BLOCKMANAGEMENTINFO_WDFC_ID_MAX_FDCOFPCPARTITIONCONFIG                                  STD_ON
#define NVM_BLOCKMANAGEMENTINFO_WDFC_ID_MIRROR_CFGOFPCPARTITIONCONFIG                               STD_ON
#define NVM_BLOCKMANAGEMENTINFO_WDFC_ID_MIRROR_OTHER_1OFPCPARTITIONCONFIG                           STD_ON
#define NVM_BLOCKMANAGEMENTINFO_WDFC_ID_MIRROR_POS_RECOFPCPARTITIONCONFIG                           STD_ON
#define NVM_BLOCKMANAGEMENTINFO_WDFC_ID_MIRROR_STOFPCPARTITIONCONFIG                                STD_ON
#define NVM_BLOCKMANAGEMENTINFO_WDFC_ID_PART_NUMBER_GEELYOFPCPARTITIONCONFIG                        STD_ON
#define NVM_BLOCKMANAGEMENTINFO_WDFC_ID_PMMOFPCPARTITIONCONFIG                                      STD_ON
#define NVM_BLOCKMANAGEMENTINFO_WDFC_ID_QCM_FAULT_DATAOFPCPARTITIONCONFIG                           STD_ON
#define NVM_BLOCKMANAGEMENTINFO_WDFC_ID_SECURITY_ACCESSOFPCPARTITIONCONFIG                          STD_ON
#define NVM_BLOCKMANAGEMENTINFO_WDFC_ID_SR_PROFILEOFPCPARTITIONCONFIG                               STD_ON
#define NVM_BLOCKMANAGEMENTINFO_WDFC_ID_SWP1OFPCPARTITIONCONFIG                                     STD_ON
#define NVM_BLOCKMANAGEMENTINFO_WDFC_ID_THPAOFPCPARTITIONCONFIG                                     STD_ON
#define NVM_BLOCKMANAGEMENTINFO_WDFC_ID_VEH_CFGOFPCPARTITIONCONFIG                                  STD_ON
#define NVM_BLOCKMANAGEMENTINFO_WDFC_ID_VOL_POWER_MODE_CFGOFPCPARTITIONCONFIG                       STD_ON
#define NVM_BLOCKMANAGEMENTINFO_WDFC_ID_WLC_AP_LEARNOFPCPARTITIONCONFIG                             STD_ON
#define NVM_BLOCKMANAGEMENTINFO_WDFC_ID_WL_INFOOFPCPARTITIONCONFIG                                  STD_ON
#define NVM_BLOCKMANAGEMENTINFO_WDFC_ID_WL_LOGOFPCPARTITIONCONFIG                                   STD_ON
#define NVM_CRCCOMPMECHANISMBUFFER_DEMADMINDATABLOCKOFPCPARTITIONCONFIG                             STD_ON
#define NVM_CRCCOMPMECHANISMBUFFER_DEMSTATUSDATABLOCKOFPCPARTITIONCONFIG                            STD_ON
#define NVM_CRCCOMPMECHANISMBUFFER_NVMCONFIGBLOCKOFPCPARTITIONCONFIG                                STD_ON
#define NVM_CRCCOMPMECHANISMBUFFER_WDFC_ID_AP_CONNEXOFPCPARTITIONCONFIG                             STD_ON
#define NVM_CRCCOMPMECHANISMBUFFER_WDFC_ID_AP_PARAOFPCPARTITIONCONFIG                               STD_ON
#define NVM_CRCCOMPMECHANISMBUFFER_WDFC_ID_BOOT_PARAOFPCPARTITIONCONFIG                             STD_ON
#define NVM_CRCCOMPMECHANISMBUFFER_WDFC_ID_CCPOFPCPARTITIONCONFIG                                   STD_ON
#define NVM_CRCCOMPMECHANISMBUFFER_WDFC_ID_DEBUG_DATAOFPCPARTITIONCONFIG                            STD_ON
#define NVM_CRCCOMPMECHANISMBUFFER_WDFC_ID_DLCOFPCPARTITIONCONFIG                                   STD_ON
#define NVM_CRCCOMPMECHANISMBUFFER_WDFC_ID_DTCTIMEOFPCPARTITIONCONFIG                               STD_ON
#define NVM_CRCCOMPMECHANISMBUFFER_WDFC_ID_ECUID_RDI_PROGRAMMING_INFOOFPCPARTITIONCONFIG            STD_ON
#define NVM_CRCCOMPMECHANISMBUFFER_WDFC_ID_EOL_HW_VERSIONOFPCPARTITIONCONFIG                        STD_ON
#define NVM_CRCCOMPMECHANISMBUFFER_WDFC_ID_EOL_INFOOFPCPARTITIONCONFIG                              STD_ON
#define NVM_CRCCOMPMECHANISMBUFFER_WDFC_ID_EOL_PASSWORDOFPCPARTITIONCONFIG                          STD_ON
#define NVM_CRCCOMPMECHANISMBUFFER_WDFC_ID_EOL_SWNUMBEROFPCPARTITIONCONFIG                          STD_ON
#define NVM_CRCCOMPMECHANISMBUFFER_WDFC_ID_FAULT_CODEOFPCPARTITIONCONFIG                            STD_ON
#define NVM_CRCCOMPMECHANISMBUFFER_WDFC_ID_HANDLE_CFGOFPCPARTITIONCONFIG                            STD_ON
#define NVM_CRCCOMPMECHANISMBUFFER_WDFC_ID_IDENT_BANKOFPCPARTITIONCONFIG                            STD_ON
#define NVM_CRCCOMPMECHANISMBUFFER_WDFC_ID_IDOPTION_SECURITYOFPCPARTITIONCONFIG                     STD_ON
#define NVM_CRCCOMPMECHANISMBUFFER_WDFC_ID_LAST_FDCOFPCPARTITIONCONFIG                              STD_ON
#define NVM_CRCCOMPMECHANISMBUFFER_WDFC_ID_MAX_FDCOFPCPARTITIONCONFIG                               STD_ON
#define NVM_CRCCOMPMECHANISMBUFFER_WDFC_ID_MIRROR_CFGOFPCPARTITIONCONFIG                            STD_ON
#define NVM_CRCCOMPMECHANISMBUFFER_WDFC_ID_MIRROR_OTHER_1OFPCPARTITIONCONFIG                        STD_ON
#define NVM_CRCCOMPMECHANISMBUFFER_WDFC_ID_MIRROR_POS_RECOFPCPARTITIONCONFIG                        STD_ON
#define NVM_CRCCOMPMECHANISMBUFFER_WDFC_ID_MIRROR_STOFPCPARTITIONCONFIG                             STD_ON
#define NVM_CRCCOMPMECHANISMBUFFER_WDFC_ID_PART_NUMBER_GEELYOFPCPARTITIONCONFIG                     STD_ON
#define NVM_CRCCOMPMECHANISMBUFFER_WDFC_ID_PMMOFPCPARTITIONCONFIG                                   STD_ON
#define NVM_CRCCOMPMECHANISMBUFFER_WDFC_ID_QCM_FAULT_DATAOFPCPARTITIONCONFIG                        STD_ON
#define NVM_CRCCOMPMECHANISMBUFFER_WDFC_ID_SECURITY_ACCESSOFPCPARTITIONCONFIG                       STD_ON
#define NVM_CRCCOMPMECHANISMBUFFER_WDFC_ID_SR_PROFILEOFPCPARTITIONCONFIG                            STD_ON
#define NVM_CRCCOMPMECHANISMBUFFER_WDFC_ID_SWP1OFPCPARTITIONCONFIG                                  STD_ON
#define NVM_CRCCOMPMECHANISMBUFFER_WDFC_ID_THPAOFPCPARTITIONCONFIG                                  STD_ON
#define NVM_CRCCOMPMECHANISMBUFFER_WDFC_ID_VEH_CFGOFPCPARTITIONCONFIG                               STD_ON
#define NVM_CRCCOMPMECHANISMBUFFER_WDFC_ID_VOL_POWER_MODE_CFGOFPCPARTITIONCONFIG                    STD_ON
#define NVM_CRCCOMPMECHANISMBUFFER_WDFC_ID_WLC_AP_LEARNOFPCPARTITIONCONFIG                          STD_ON
#define NVM_CRCCOMPMECHANISMBUFFER_WDFC_ID_WL_INFOOFPCPARTITIONCONFIG                               STD_ON
#define NVM_CRCCOMPMECHANISMBUFFER_WDFC_ID_WL_LOGOFPCPARTITIONCONFIG                                STD_ON
#define NVM_DATAINTEGRITYFSM_INSTANCEOFPCPARTITIONCONFIG                                            STD_ON
#define NVM_DATAINTEGRITYINTBUFFER_DEMADMINDATABLOCKOFPCPARTITIONCONFIG                             STD_ON
#define NVM_DATAINTEGRITYINTBUFFER_DEMSTATUSDATABLOCKOFPCPARTITIONCONFIG                            STD_ON
#define NVM_DATAINTEGRITYINTBUFFER_WDFC_ID_AP_CONNEXOFPCPARTITIONCONFIG                             STD_ON
#define NVM_DATAINTEGRITYINTBUFFER_WDFC_ID_AP_PARAOFPCPARTITIONCONFIG                               STD_ON
#define NVM_DATAINTEGRITYINTBUFFER_WDFC_ID_BOOT_PARAOFPCPARTITIONCONFIG                             STD_ON
#define NVM_DATAINTEGRITYINTBUFFER_WDFC_ID_CCPOFPCPARTITIONCONFIG                                   STD_ON
#define NVM_DATAINTEGRITYINTBUFFER_WDFC_ID_DEBUG_DATAOFPCPARTITIONCONFIG                            STD_ON
#define NVM_DATAINTEGRITYINTBUFFER_WDFC_ID_DLCOFPCPARTITIONCONFIG                                   STD_ON
#define NVM_DATAINTEGRITYINTBUFFER_WDFC_ID_DTCTIMEOFPCPARTITIONCONFIG                               STD_ON
#define NVM_DATAINTEGRITYINTBUFFER_WDFC_ID_ECUID_RDI_PROGRAMMING_INFOOFPCPARTITIONCONFIG            STD_ON
#define NVM_DATAINTEGRITYINTBUFFER_WDFC_ID_EOL_HW_VERSIONOFPCPARTITIONCONFIG                        STD_ON
#define NVM_DATAINTEGRITYINTBUFFER_WDFC_ID_EOL_INFOOFPCPARTITIONCONFIG                              STD_ON
#define NVM_DATAINTEGRITYINTBUFFER_WDFC_ID_EOL_PASSWORDOFPCPARTITIONCONFIG                          STD_ON
#define NVM_DATAINTEGRITYINTBUFFER_WDFC_ID_EOL_SWNUMBEROFPCPARTITIONCONFIG                          STD_ON
#define NVM_DATAINTEGRITYINTBUFFER_WDFC_ID_FAULT_CODEOFPCPARTITIONCONFIG                            STD_ON
#define NVM_DATAINTEGRITYINTBUFFER_WDFC_ID_HANDLE_CFGOFPCPARTITIONCONFIG                            STD_ON
#define NVM_DATAINTEGRITYINTBUFFER_WDFC_ID_IDENT_BANKOFPCPARTITIONCONFIG                            STD_ON
#define NVM_DATAINTEGRITYINTBUFFER_WDFC_ID_IDOPTION_SECURITYOFPCPARTITIONCONFIG                     STD_ON
#define NVM_DATAINTEGRITYINTBUFFER_WDFC_ID_LAST_FDCOFPCPARTITIONCONFIG                              STD_ON
#define NVM_DATAINTEGRITYINTBUFFER_WDFC_ID_MAX_FDCOFPCPARTITIONCONFIG                               STD_ON
#define NVM_DATAINTEGRITYINTBUFFER_WDFC_ID_MIRROR_CFGOFPCPARTITIONCONFIG                            STD_ON
#define NVM_DATAINTEGRITYINTBUFFER_WDFC_ID_MIRROR_OTHER_1OFPCPARTITIONCONFIG                        STD_ON
#define NVM_DATAINTEGRITYINTBUFFER_WDFC_ID_MIRROR_POS_RECOFPCPARTITIONCONFIG                        STD_ON
#define NVM_DATAINTEGRITYINTBUFFER_WDFC_ID_MIRROR_STOFPCPARTITIONCONFIG                             STD_ON
#define NVM_DATAINTEGRITYINTBUFFER_WDFC_ID_PART_NUMBER_GEELYOFPCPARTITIONCONFIG                     STD_ON
#define NVM_DATAINTEGRITYINTBUFFER_WDFC_ID_PMMOFPCPARTITIONCONFIG                                   STD_ON
#define NVM_DATAINTEGRITYINTBUFFER_WDFC_ID_QCM_FAULT_DATAOFPCPARTITIONCONFIG                        STD_ON
#define NVM_DATAINTEGRITYINTBUFFER_WDFC_ID_SECURITY_ACCESSOFPCPARTITIONCONFIG                       STD_ON
#define NVM_DATAINTEGRITYINTBUFFER_WDFC_ID_SR_PROFILEOFPCPARTITIONCONFIG                            STD_ON
#define NVM_DATAINTEGRITYINTBUFFER_WDFC_ID_SWP1OFPCPARTITIONCONFIG                                  STD_ON
#define NVM_DATAINTEGRITYINTBUFFER_WDFC_ID_THPAOFPCPARTITIONCONFIG                                  STD_ON
#define NVM_DATAINTEGRITYINTBUFFER_WDFC_ID_VEH_CFGOFPCPARTITIONCONFIG                               STD_ON
#define NVM_DATAINTEGRITYINTBUFFER_WDFC_ID_VOL_POWER_MODE_CFGOFPCPARTITIONCONFIG                    STD_ON
#define NVM_DATAINTEGRITYINTBUFFER_WDFC_ID_WLC_AP_LEARNOFPCPARTITIONCONFIG                          STD_ON
#define NVM_DATAINTEGRITYINTBUFFER_WDFC_ID_WL_INFOOFPCPARTITIONCONFIG                               STD_ON
#define NVM_DATAINTEGRITYINTBUFFER_WDFC_ID_WL_LOGOFPCPARTITIONCONFIG                                STD_ON
#define NVM_DATAINTEGRITYRECALCQUEUE_INSTANCEOFPCPARTITIONCONFIG                                    STD_ON
#define NVM_DCMBLOCKMANAGEMENTINFOOFPCPARTITIONCONFIG                                               STD_ON
#define NVM_FOREGROUNDDATAINTEGRITYSERVICE_INSTANCEOFPCPARTITIONCONFIG                              STD_ON
#define NVM_INTERNALBUFFEROFPCPARTITIONCONFIG                                                       STD_ON
#define NVM_MULTIBLOCKFSMLIB_PROCESSINGSTACKELEMENTOFPCPARTITIONCONFIG                              STD_ON
#define NVM_MULTIBLOCKJOBFSM_CONTEXTOFPCPARTITIONCONFIG                                             STD_ON
#define NVM_MULTIBLOCKJOBFSM_INSTANCEOFPCPARTITIONCONFIG                                            STD_ON
#define NVM_MULTIBLOCKJOBINFORMATIONOFPCPARTITIONCONFIG                                             STD_ON
#define NVM_MULTIBLOCKJOBOFPCPARTITIONCONFIG                                                        STD_ON
#define NVM_MULTIBLOCKPROCESSORFSMLIB_INSTANCEOFPCPARTITIONCONFIG                                   STD_ON
#define NVM_MULTIBLOCKPROCESSORFSMLIB_PROCESSINGSTACKELEMENTOFPCPARTITIONCONFIG                     STD_ON
#define NVM_MULTIBLOCKSERVICEFSMLIB_INSTANCEOFPCPARTITIONCONFIG                                     STD_ON
#define NVM_NVJOBCONTEXTOFPCPARTITIONCONFIG                                                         STD_ON
#define NVM_NVJOBFSM_INSTANCEOFPCPARTITIONCONFIG                                                    STD_ON
#define NVM_NVSERVICEFSMLIB_INSTANCEOFPCPARTITIONCONFIG                                             STD_ON
#define NVM_NVSERVICEFSMLIB_PROCESSINGSTACKELEMENTOFPCPARTITIONCONFIG                               STD_ON
#define NVM_NVSERVICEPROCESSORFSMLIB_INSTANCEOFPCPARTITIONCONFIG                                    STD_ON
#define NVM_NVSERVICEPROCESSORFSMLIB_PROCESSINGSTACKELEMENTOFPCPARTITIONCONFIG                      STD_ON
#define NVM_QUEUELISTOFPCPARTITIONCONFIG                                                            STD_ON
#define NVM_QUEUE_INSTANCEOFPCPARTITIONCONFIG                                                       STD_ON
#define NVM_READALLFSM_CONTEXTOFPCPARTITIONCONFIG                                                   STD_ON
#define NVM_READALLFSM_INSTANCEOFPCPARTITIONCONFIG                                                  STD_ON
#define NVM_READBLOCKFSM_CONTEXTOFPCPARTITIONCONFIG                                                 STD_ON
#define NVM_READBLOCKFSM_INSTANCEOFPCPARTITIONCONFIG                                                STD_ON
#define NVM_SERVICEPROCESSORFSMLIB_INSTANCEOFPCPARTITIONCONFIG                                      STD_ON
#define NVM_SERVICEPROCESSORFSMLIB_PROCESSINGSTACKELEMENTOFPCPARTITIONCONFIG                        STD_ON
#define NVM_SERVICEPROCESSORFSM_CONTEXTOFPCPARTITIONCONFIG                                          STD_ON
#define NVM_SERVICEPROCESSORFSM_INSTANCEOFPCPARTITIONCONFIG                                         STD_ON
#define NVM_SINGLEBLOCKFSMLIB_PROCESSINGSTACKELEMENTOFPCPARTITIONCONFIG                             STD_ON
#define NVM_SINGLEBLOCKJOBCONTEXTOFPCPARTITIONCONFIG                                                STD_ON
#define NVM_SINGLEBLOCKJOBFSM_INSTANCEOFPCPARTITIONCONFIG                                           STD_ON
#define NVM_SINGLEBLOCKSERVICEFSMLIB_INSTANCEOFPCPARTITIONCONFIG                                    STD_ON
#define NVM_SIZEOFBACKGROUNDCRCRECALCFSMLIB_PROCESSINGSTACKELEMENTOFPCPARTITIONCONFIG               STD_ON
#define NVM_SIZEOFBLOCKDESCRIPTOROFPCPARTITIONCONFIG                                                STD_ON
#define NVM_SIZEOFCRCCOMPMECHANISMBUFFER_DEMADMINDATABLOCKOFPCPARTITIONCONFIG                       STD_ON
#define NVM_SIZEOFCRCCOMPMECHANISMBUFFER_DEMSTATUSDATABLOCKOFPCPARTITIONCONFIG                      STD_ON
#define NVM_SIZEOFCRCCOMPMECHANISMBUFFER_NVMCONFIGBLOCKOFPCPARTITIONCONFIG                          STD_ON
#define NVM_SIZEOFCRCCOMPMECHANISMBUFFER_WDFC_ID_AP_CONNEXOFPCPARTITIONCONFIG                       STD_ON
#define NVM_SIZEOFCRCCOMPMECHANISMBUFFER_WDFC_ID_AP_PARAOFPCPARTITIONCONFIG                         STD_ON
#define NVM_SIZEOFCRCCOMPMECHANISMBUFFER_WDFC_ID_BOOT_PARAOFPCPARTITIONCONFIG                       STD_ON
#define NVM_SIZEOFCRCCOMPMECHANISMBUFFER_WDFC_ID_CCPOFPCPARTITIONCONFIG                             STD_ON
#define NVM_SIZEOFCRCCOMPMECHANISMBUFFER_WDFC_ID_DEBUG_DATAOFPCPARTITIONCONFIG                      STD_ON
#define NVM_SIZEOFCRCCOMPMECHANISMBUFFER_WDFC_ID_DLCOFPCPARTITIONCONFIG                             STD_ON
#define NVM_SIZEOFCRCCOMPMECHANISMBUFFER_WDFC_ID_DTCTIMEOFPCPARTITIONCONFIG                         STD_ON
#define NVM_SIZEOFCRCCOMPMECHANISMBUFFER_WDFC_ID_ECUID_RDI_PROGRAMMING_INFOOFPCPARTITIONCONFIG      STD_ON
#define NVM_SIZEOFCRCCOMPMECHANISMBUFFER_WDFC_ID_EOL_HW_VERSIONOFPCPARTITIONCONFIG                  STD_ON
#define NVM_SIZEOFCRCCOMPMECHANISMBUFFER_WDFC_ID_EOL_INFOOFPCPARTITIONCONFIG                        STD_ON
#define NVM_SIZEOFCRCCOMPMECHANISMBUFFER_WDFC_ID_EOL_PASSWORDOFPCPARTITIONCONFIG                    STD_ON
#define NVM_SIZEOFCRCCOMPMECHANISMBUFFER_WDFC_ID_EOL_SWNUMBEROFPCPARTITIONCONFIG                    STD_ON
#define NVM_SIZEOFCRCCOMPMECHANISMBUFFER_WDFC_ID_FAULT_CODEOFPCPARTITIONCONFIG                      STD_ON
#define NVM_SIZEOFCRCCOMPMECHANISMBUFFER_WDFC_ID_HANDLE_CFGOFPCPARTITIONCONFIG                      STD_ON
#define NVM_SIZEOFCRCCOMPMECHANISMBUFFER_WDFC_ID_IDENT_BANKOFPCPARTITIONCONFIG                      STD_ON
#define NVM_SIZEOFCRCCOMPMECHANISMBUFFER_WDFC_ID_IDOPTION_SECURITYOFPCPARTITIONCONFIG               STD_ON
#define NVM_SIZEOFCRCCOMPMECHANISMBUFFER_WDFC_ID_LAST_FDCOFPCPARTITIONCONFIG                        STD_ON
#define NVM_SIZEOFCRCCOMPMECHANISMBUFFER_WDFC_ID_MAX_FDCOFPCPARTITIONCONFIG                         STD_ON
#define NVM_SIZEOFCRCCOMPMECHANISMBUFFER_WDFC_ID_MIRROR_CFGOFPCPARTITIONCONFIG                      STD_ON
#define NVM_SIZEOFCRCCOMPMECHANISMBUFFER_WDFC_ID_MIRROR_OTHER_1OFPCPARTITIONCONFIG                  STD_ON
#define NVM_SIZEOFCRCCOMPMECHANISMBUFFER_WDFC_ID_MIRROR_POS_RECOFPCPARTITIONCONFIG                  STD_ON
#define NVM_SIZEOFCRCCOMPMECHANISMBUFFER_WDFC_ID_MIRROR_STOFPCPARTITIONCONFIG                       STD_ON
#define NVM_SIZEOFCRCCOMPMECHANISMBUFFER_WDFC_ID_PART_NUMBER_GEELYOFPCPARTITIONCONFIG               STD_ON
#define NVM_SIZEOFCRCCOMPMECHANISMBUFFER_WDFC_ID_PMMOFPCPARTITIONCONFIG                             STD_ON
#define NVM_SIZEOFCRCCOMPMECHANISMBUFFER_WDFC_ID_QCM_FAULT_DATAOFPCPARTITIONCONFIG                  STD_ON
#define NVM_SIZEOFCRCCOMPMECHANISMBUFFER_WDFC_ID_SECURITY_ACCESSOFPCPARTITIONCONFIG                 STD_ON
#define NVM_SIZEOFCRCCOMPMECHANISMBUFFER_WDFC_ID_SR_PROFILEOFPCPARTITIONCONFIG                      STD_ON
#define NVM_SIZEOFCRCCOMPMECHANISMBUFFER_WDFC_ID_SWP1OFPCPARTITIONCONFIG                            STD_ON
#define NVM_SIZEOFCRCCOMPMECHANISMBUFFER_WDFC_ID_THPAOFPCPARTITIONCONFIG                            STD_ON
#define NVM_SIZEOFCRCCOMPMECHANISMBUFFER_WDFC_ID_VEH_CFGOFPCPARTITIONCONFIG                         STD_ON
#define NVM_SIZEOFCRCCOMPMECHANISMBUFFER_WDFC_ID_VOL_POWER_MODE_CFGOFPCPARTITIONCONFIG              STD_ON
#define NVM_SIZEOFCRCCOMPMECHANISMBUFFER_WDFC_ID_WLC_AP_LEARNOFPCPARTITIONCONFIG                    STD_ON
#define NVM_SIZEOFCRCCOMPMECHANISMBUFFER_WDFC_ID_WL_INFOOFPCPARTITIONCONFIG                         STD_ON
#define NVM_SIZEOFCRCCOMPMECHANISMBUFFER_WDFC_ID_WL_LOGOFPCPARTITIONCONFIG                          STD_ON
#define NVM_SIZEOFCRCINTERNALEXPLICITSYNCBUFFEROFPCPARTITIONCONFIG                                  STD_OFF  /**< Deactivateable: 'NvM_PCPartitionConfig.SizeOfCrcInternalExplicitSyncBuffer' Reason: 'Deactivateable: 'CrcInternalExplicitSyncBuffer' Reason: 'Deactivateable: 'NvM_CrcInternalExplicitSyncBuffer' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE''' */
#define NVM_SIZEOFDATAINTEGRITYINTBUFFER_DEMADMINDATABLOCKOFPCPARTITIONCONFIG                       STD_ON
#define NVM_SIZEOFDATAINTEGRITYINTBUFFER_DEMSTATUSDATABLOCKOFPCPARTITIONCONFIG                      STD_ON
#define NVM_SIZEOFDATAINTEGRITYINTBUFFER_WDFC_ID_AP_CONNEXOFPCPARTITIONCONFIG                       STD_ON
#define NVM_SIZEOFDATAINTEGRITYINTBUFFER_WDFC_ID_AP_PARAOFPCPARTITIONCONFIG                         STD_ON
#define NVM_SIZEOFDATAINTEGRITYINTBUFFER_WDFC_ID_BOOT_PARAOFPCPARTITIONCONFIG                       STD_ON
#define NVM_SIZEOFDATAINTEGRITYINTBUFFER_WDFC_ID_CCPOFPCPARTITIONCONFIG                             STD_ON
#define NVM_SIZEOFDATAINTEGRITYINTBUFFER_WDFC_ID_DEBUG_DATAOFPCPARTITIONCONFIG                      STD_ON
#define NVM_SIZEOFDATAINTEGRITYINTBUFFER_WDFC_ID_DLCOFPCPARTITIONCONFIG                             STD_ON
#define NVM_SIZEOFDATAINTEGRITYINTBUFFER_WDFC_ID_DTCTIMEOFPCPARTITIONCONFIG                         STD_ON
#define NVM_SIZEOFDATAINTEGRITYINTBUFFER_WDFC_ID_ECUID_RDI_PROGRAMMING_INFOOFPCPARTITIONCONFIG      STD_ON
#define NVM_SIZEOFDATAINTEGRITYINTBUFFER_WDFC_ID_EOL_HW_VERSIONOFPCPARTITIONCONFIG                  STD_ON
#define NVM_SIZEOFDATAINTEGRITYINTBUFFER_WDFC_ID_EOL_INFOOFPCPARTITIONCONFIG                        STD_ON
#define NVM_SIZEOFDATAINTEGRITYINTBUFFER_WDFC_ID_EOL_PASSWORDOFPCPARTITIONCONFIG                    STD_ON
#define NVM_SIZEOFDATAINTEGRITYINTBUFFER_WDFC_ID_EOL_SWNUMBEROFPCPARTITIONCONFIG                    STD_ON
#define NVM_SIZEOFDATAINTEGRITYINTBUFFER_WDFC_ID_FAULT_CODEOFPCPARTITIONCONFIG                      STD_ON
#define NVM_SIZEOFDATAINTEGRITYINTBUFFER_WDFC_ID_HANDLE_CFGOFPCPARTITIONCONFIG                      STD_ON
#define NVM_SIZEOFDATAINTEGRITYINTBUFFER_WDFC_ID_IDENT_BANKOFPCPARTITIONCONFIG                      STD_ON
#define NVM_SIZEOFDATAINTEGRITYINTBUFFER_WDFC_ID_IDOPTION_SECURITYOFPCPARTITIONCONFIG               STD_ON
#define NVM_SIZEOFDATAINTEGRITYINTBUFFER_WDFC_ID_LAST_FDCOFPCPARTITIONCONFIG                        STD_ON
#define NVM_SIZEOFDATAINTEGRITYINTBUFFER_WDFC_ID_MAX_FDCOFPCPARTITIONCONFIG                         STD_ON
#define NVM_SIZEOFDATAINTEGRITYINTBUFFER_WDFC_ID_MIRROR_CFGOFPCPARTITIONCONFIG                      STD_ON
#define NVM_SIZEOFDATAINTEGRITYINTBUFFER_WDFC_ID_MIRROR_OTHER_1OFPCPARTITIONCONFIG                  STD_ON
#define NVM_SIZEOFDATAINTEGRITYINTBUFFER_WDFC_ID_MIRROR_POS_RECOFPCPARTITIONCONFIG                  STD_ON
#define NVM_SIZEOFDATAINTEGRITYINTBUFFER_WDFC_ID_MIRROR_STOFPCPARTITIONCONFIG                       STD_ON
#define NVM_SIZEOFDATAINTEGRITYINTBUFFER_WDFC_ID_PART_NUMBER_GEELYOFPCPARTITIONCONFIG               STD_ON
#define NVM_SIZEOFDATAINTEGRITYINTBUFFER_WDFC_ID_PMMOFPCPARTITIONCONFIG                             STD_ON
#define NVM_SIZEOFDATAINTEGRITYINTBUFFER_WDFC_ID_QCM_FAULT_DATAOFPCPARTITIONCONFIG                  STD_ON
#define NVM_SIZEOFDATAINTEGRITYINTBUFFER_WDFC_ID_SECURITY_ACCESSOFPCPARTITIONCONFIG                 STD_ON
#define NVM_SIZEOFDATAINTEGRITYINTBUFFER_WDFC_ID_SR_PROFILEOFPCPARTITIONCONFIG                      STD_ON
#define NVM_SIZEOFDATAINTEGRITYINTBUFFER_WDFC_ID_SWP1OFPCPARTITIONCONFIG                            STD_ON
#define NVM_SIZEOFDATAINTEGRITYINTBUFFER_WDFC_ID_THPAOFPCPARTITIONCONFIG                            STD_ON
#define NVM_SIZEOFDATAINTEGRITYINTBUFFER_WDFC_ID_VEH_CFGOFPCPARTITIONCONFIG                         STD_ON
#define NVM_SIZEOFDATAINTEGRITYINTBUFFER_WDFC_ID_VOL_POWER_MODE_CFGOFPCPARTITIONCONFIG              STD_ON
#define NVM_SIZEOFDATAINTEGRITYINTBUFFER_WDFC_ID_WLC_AP_LEARNOFPCPARTITIONCONFIG                    STD_ON
#define NVM_SIZEOFDATAINTEGRITYINTBUFFER_WDFC_ID_WL_INFOOFPCPARTITIONCONFIG                         STD_ON
#define NVM_SIZEOFDATAINTEGRITYINTBUFFER_WDFC_ID_WL_LOGOFPCPARTITIONCONFIG                          STD_ON
#define NVM_SIZEOFINTERNALBUFFEROFPCPARTITIONCONFIG                                                 STD_ON
#define NVM_SIZEOFMULTIBLOCKFSMLIB_PROCESSINGSTACKELEMENTOFPCPARTITIONCONFIG                        STD_ON
#define NVM_SIZEOFMULTIBLOCKPROCESSORFSMLIB_PROCESSINGSTACKELEMENTOFPCPARTITIONCONFIG               STD_ON
#define NVM_SIZEOFNVSERVICEFSMLIB_PROCESSINGSTACKELEMENTOFPCPARTITIONCONFIG                         STD_ON
#define NVM_SIZEOFNVSERVICEPROCESSORFSMLIB_PROCESSINGSTACKELEMENTOFPCPARTITIONCONFIG                STD_ON
#define NVM_SIZEOFQUEUELISTOFPCPARTITIONCONFIG                                                      STD_ON
#define NVM_SIZEOFSERVICEPROCESSORFSMLIB_PROCESSINGSTACKELEMENTOFPCPARTITIONCONFIG                  STD_ON
#define NVM_SIZEOFSINGLEBLOCKFSMLIB_PROCESSINGSTACKELEMENTOFPCPARTITIONCONFIG                       STD_ON
#define NVM_VALIDATEALLFSM_INSTANCEOFPCPARTITIONCONFIG                                              STD_ON
#define NVM_WRITEALLFSM_CONTEXTOFPCPARTITIONCONFIG                                                  STD_ON
#define NVM_WRITEALLFSM_INSTANCEOFPCPARTITIONCONFIG                                                 STD_ON
#define NVM_WRITEBLOCKFSM_CONTEXTOFPCPARTITIONCONFIG                                                STD_ON
#define NVM_WRITEBLOCKFSM_INSTANCEOFPCPARTITIONCONFIG                                               STD_ON
#define NVM_WRITENVBLOCKFSM_CONTEXTOFPCPARTITIONCONFIG                                              STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  NvMPCIsReducedToDefineDefines  NvM Is Reduced To Define Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define is STD_ON else STD_OFF.
  \{
*/ 
#define NVM_ISDEF_BLOCKDESCRIPTOR                                                                   STD_OFF
#define NVM_ISDEF_PCPARTITIONCONFIGIDXOFPARTITIONIDENTIFIERS                                        STD_OFF
#define NVM_ISDEF_PARTITIONSNVOFPARTITIONIDENTIFIERS                                                STD_OFF
#define NVM_ISDEF_PCPARTITIONCONFIGOFPCCONFIG                                                       STD_ON
#define NVM_ISDEF_PARTITIONIDENTIFIERSOFPCCONFIG                                                    STD_ON
#define NVM_ISDEF_BACKGROUNDCRCRECALCFSMLIB_INSTANCEOFPCPARTITIONCONFIG                             STD_ON
#define NVM_ISDEF_BACKGROUNDCRCRECALCFSMLIB_PROCESSINGSTACKELEMENTOFPCPARTITIONCONFIG               STD_ON
#define NVM_ISDEF_BACKGROUNDCRCRECALCFSM_CONTEXTOFPCPARTITIONCONFIG                                 STD_ON
#define NVM_ISDEF_BACKGROUNDCRCRECALCFSM_INSTANCEOFPCPARTITIONCONFIG                                STD_ON
#define NVM_ISDEF_BACKGROUNDDATAINTEGRITYSERVICE_INSTANCEOFPCPARTITIONCONFIG                        STD_ON
#define NVM_ISDEF_BLOCKDESCRIPTOROFPCPARTITIONCONFIG                                                STD_ON
#define NVM_ISDEF_BLOCKMANAGEMENTINFO_DEMADMINDATABLOCKOFPCPARTITIONCONFIG                          STD_ON
#define NVM_ISDEF_BLOCKMANAGEMENTINFO_DEMSTATUSDATABLOCKOFPCPARTITIONCONFIG                         STD_ON
#define NVM_ISDEF_BLOCKMANAGEMENTINFO_NVMCONFIGBLOCKOFPCPARTITIONCONFIG                             STD_ON
#define NVM_ISDEF_BLOCKMANAGEMENTINFO_NVMMULTIBLOCKOFPCPARTITIONCONFIG                              STD_ON
#define NVM_ISDEF_BLOCKMANAGEMENTINFO_WDFC_ID_AP_CONNEXOFPCPARTITIONCONFIG                          STD_ON
#define NVM_ISDEF_BLOCKMANAGEMENTINFO_WDFC_ID_AP_PARAOFPCPARTITIONCONFIG                            STD_ON
#define NVM_ISDEF_BLOCKMANAGEMENTINFO_WDFC_ID_BOOT_PARAOFPCPARTITIONCONFIG                          STD_ON
#define NVM_ISDEF_BLOCKMANAGEMENTINFO_WDFC_ID_CCPOFPCPARTITIONCONFIG                                STD_ON
#define NVM_ISDEF_BLOCKMANAGEMENTINFO_WDFC_ID_DEBUG_DATAOFPCPARTITIONCONFIG                         STD_ON
#define NVM_ISDEF_BLOCKMANAGEMENTINFO_WDFC_ID_DLCOFPCPARTITIONCONFIG                                STD_ON
#define NVM_ISDEF_BLOCKMANAGEMENTINFO_WDFC_ID_DTCTIMEOFPCPARTITIONCONFIG                            STD_ON
#define NVM_ISDEF_BLOCKMANAGEMENTINFO_WDFC_ID_ECUID_RDI_PROGRAMMING_INFOOFPCPARTITIONCONFIG         STD_ON
#define NVM_ISDEF_BLOCKMANAGEMENTINFO_WDFC_ID_EOL_HW_VERSIONOFPCPARTITIONCONFIG                     STD_ON
#define NVM_ISDEF_BLOCKMANAGEMENTINFO_WDFC_ID_EOL_INFOOFPCPARTITIONCONFIG                           STD_ON
#define NVM_ISDEF_BLOCKMANAGEMENTINFO_WDFC_ID_EOL_PASSWORDOFPCPARTITIONCONFIG                       STD_ON
#define NVM_ISDEF_BLOCKMANAGEMENTINFO_WDFC_ID_EOL_SWNUMBEROFPCPARTITIONCONFIG                       STD_ON
#define NVM_ISDEF_BLOCKMANAGEMENTINFO_WDFC_ID_FAULT_CODEOFPCPARTITIONCONFIG                         STD_ON
#define NVM_ISDEF_BLOCKMANAGEMENTINFO_WDFC_ID_HANDLE_CFGOFPCPARTITIONCONFIG                         STD_ON
#define NVM_ISDEF_BLOCKMANAGEMENTINFO_WDFC_ID_IDENT_BANKOFPCPARTITIONCONFIG                         STD_ON
#define NVM_ISDEF_BLOCKMANAGEMENTINFO_WDFC_ID_IDOPTION_SECURITYOFPCPARTITIONCONFIG                  STD_ON
#define NVM_ISDEF_BLOCKMANAGEMENTINFO_WDFC_ID_LAST_FDCOFPCPARTITIONCONFIG                           STD_ON
#define NVM_ISDEF_BLOCKMANAGEMENTINFO_WDFC_ID_MAX_FDCOFPCPARTITIONCONFIG                            STD_ON
#define NVM_ISDEF_BLOCKMANAGEMENTINFO_WDFC_ID_MIRROR_CFGOFPCPARTITIONCONFIG                         STD_ON
#define NVM_ISDEF_BLOCKMANAGEMENTINFO_WDFC_ID_MIRROR_OTHER_1OFPCPARTITIONCONFIG                     STD_ON
#define NVM_ISDEF_BLOCKMANAGEMENTINFO_WDFC_ID_MIRROR_POS_RECOFPCPARTITIONCONFIG                     STD_ON
#define NVM_ISDEF_BLOCKMANAGEMENTINFO_WDFC_ID_MIRROR_STOFPCPARTITIONCONFIG                          STD_ON
#define NVM_ISDEF_BLOCKMANAGEMENTINFO_WDFC_ID_PART_NUMBER_GEELYOFPCPARTITIONCONFIG                  STD_ON
#define NVM_ISDEF_BLOCKMANAGEMENTINFO_WDFC_ID_PMMOFPCPARTITIONCONFIG                                STD_ON
#define NVM_ISDEF_BLOCKMANAGEMENTINFO_WDFC_ID_QCM_FAULT_DATAOFPCPARTITIONCONFIG                     STD_ON
#define NVM_ISDEF_BLOCKMANAGEMENTINFO_WDFC_ID_SECURITY_ACCESSOFPCPARTITIONCONFIG                    STD_ON
#define NVM_ISDEF_BLOCKMANAGEMENTINFO_WDFC_ID_SR_PROFILEOFPCPARTITIONCONFIG                         STD_ON
#define NVM_ISDEF_BLOCKMANAGEMENTINFO_WDFC_ID_SWP1OFPCPARTITIONCONFIG                               STD_ON
#define NVM_ISDEF_BLOCKMANAGEMENTINFO_WDFC_ID_THPAOFPCPARTITIONCONFIG                               STD_ON
#define NVM_ISDEF_BLOCKMANAGEMENTINFO_WDFC_ID_VEH_CFGOFPCPARTITIONCONFIG                            STD_ON
#define NVM_ISDEF_BLOCKMANAGEMENTINFO_WDFC_ID_VOL_POWER_MODE_CFGOFPCPARTITIONCONFIG                 STD_ON
#define NVM_ISDEF_BLOCKMANAGEMENTINFO_WDFC_ID_WLC_AP_LEARNOFPCPARTITIONCONFIG                       STD_ON
#define NVM_ISDEF_BLOCKMANAGEMENTINFO_WDFC_ID_WL_INFOOFPCPARTITIONCONFIG                            STD_ON
#define NVM_ISDEF_BLOCKMANAGEMENTINFO_WDFC_ID_WL_LOGOFPCPARTITIONCONFIG                             STD_ON
#define NVM_ISDEF_CRCCOMPMECHANISMBUFFER_DEMADMINDATABLOCKOFPCPARTITIONCONFIG                       STD_ON
#define NVM_ISDEF_CRCCOMPMECHANISMBUFFER_DEMSTATUSDATABLOCKOFPCPARTITIONCONFIG                      STD_ON
#define NVM_ISDEF_CRCCOMPMECHANISMBUFFER_NVMCONFIGBLOCKOFPCPARTITIONCONFIG                          STD_ON
#define NVM_ISDEF_CRCCOMPMECHANISMBUFFER_WDFC_ID_AP_CONNEXOFPCPARTITIONCONFIG                       STD_ON
#define NVM_ISDEF_CRCCOMPMECHANISMBUFFER_WDFC_ID_AP_PARAOFPCPARTITIONCONFIG                         STD_ON
#define NVM_ISDEF_CRCCOMPMECHANISMBUFFER_WDFC_ID_BOOT_PARAOFPCPARTITIONCONFIG                       STD_ON
#define NVM_ISDEF_CRCCOMPMECHANISMBUFFER_WDFC_ID_CCPOFPCPARTITIONCONFIG                             STD_ON
#define NVM_ISDEF_CRCCOMPMECHANISMBUFFER_WDFC_ID_DEBUG_DATAOFPCPARTITIONCONFIG                      STD_ON
#define NVM_ISDEF_CRCCOMPMECHANISMBUFFER_WDFC_ID_DLCOFPCPARTITIONCONFIG                             STD_ON
#define NVM_ISDEF_CRCCOMPMECHANISMBUFFER_WDFC_ID_DTCTIMEOFPCPARTITIONCONFIG                         STD_ON
#define NVM_ISDEF_CRCCOMPMECHANISMBUFFER_WDFC_ID_ECUID_RDI_PROGRAMMING_INFOOFPCPARTITIONCONFIG      STD_ON
#define NVM_ISDEF_CRCCOMPMECHANISMBUFFER_WDFC_ID_EOL_HW_VERSIONOFPCPARTITIONCONFIG                  STD_ON
#define NVM_ISDEF_CRCCOMPMECHANISMBUFFER_WDFC_ID_EOL_INFOOFPCPARTITIONCONFIG                        STD_ON
#define NVM_ISDEF_CRCCOMPMECHANISMBUFFER_WDFC_ID_EOL_PASSWORDOFPCPARTITIONCONFIG                    STD_ON
#define NVM_ISDEF_CRCCOMPMECHANISMBUFFER_WDFC_ID_EOL_SWNUMBEROFPCPARTITIONCONFIG                    STD_ON
#define NVM_ISDEF_CRCCOMPMECHANISMBUFFER_WDFC_ID_FAULT_CODEOFPCPARTITIONCONFIG                      STD_ON
#define NVM_ISDEF_CRCCOMPMECHANISMBUFFER_WDFC_ID_HANDLE_CFGOFPCPARTITIONCONFIG                      STD_ON
#define NVM_ISDEF_CRCCOMPMECHANISMBUFFER_WDFC_ID_IDENT_BANKOFPCPARTITIONCONFIG                      STD_ON
#define NVM_ISDEF_CRCCOMPMECHANISMBUFFER_WDFC_ID_IDOPTION_SECURITYOFPCPARTITIONCONFIG               STD_ON
#define NVM_ISDEF_CRCCOMPMECHANISMBUFFER_WDFC_ID_LAST_FDCOFPCPARTITIONCONFIG                        STD_ON
#define NVM_ISDEF_CRCCOMPMECHANISMBUFFER_WDFC_ID_MAX_FDCOFPCPARTITIONCONFIG                         STD_ON
#define NVM_ISDEF_CRCCOMPMECHANISMBUFFER_WDFC_ID_MIRROR_CFGOFPCPARTITIONCONFIG                      STD_ON
#define NVM_ISDEF_CRCCOMPMECHANISMBUFFER_WDFC_ID_MIRROR_OTHER_1OFPCPARTITIONCONFIG                  STD_ON
#define NVM_ISDEF_CRCCOMPMECHANISMBUFFER_WDFC_ID_MIRROR_POS_RECOFPCPARTITIONCONFIG                  STD_ON
#define NVM_ISDEF_CRCCOMPMECHANISMBUFFER_WDFC_ID_MIRROR_STOFPCPARTITIONCONFIG                       STD_ON
#define NVM_ISDEF_CRCCOMPMECHANISMBUFFER_WDFC_ID_PART_NUMBER_GEELYOFPCPARTITIONCONFIG               STD_ON
#define NVM_ISDEF_CRCCOMPMECHANISMBUFFER_WDFC_ID_PMMOFPCPARTITIONCONFIG                             STD_ON
#define NVM_ISDEF_CRCCOMPMECHANISMBUFFER_WDFC_ID_QCM_FAULT_DATAOFPCPARTITIONCONFIG                  STD_ON
#define NVM_ISDEF_CRCCOMPMECHANISMBUFFER_WDFC_ID_SECURITY_ACCESSOFPCPARTITIONCONFIG                 STD_ON
#define NVM_ISDEF_CRCCOMPMECHANISMBUFFER_WDFC_ID_SR_PROFILEOFPCPARTITIONCONFIG                      STD_ON
#define NVM_ISDEF_CRCCOMPMECHANISMBUFFER_WDFC_ID_SWP1OFPCPARTITIONCONFIG                            STD_ON
#define NVM_ISDEF_CRCCOMPMECHANISMBUFFER_WDFC_ID_THPAOFPCPARTITIONCONFIG                            STD_ON
#define NVM_ISDEF_CRCCOMPMECHANISMBUFFER_WDFC_ID_VEH_CFGOFPCPARTITIONCONFIG                         STD_ON
#define NVM_ISDEF_CRCCOMPMECHANISMBUFFER_WDFC_ID_VOL_POWER_MODE_CFGOFPCPARTITIONCONFIG              STD_ON
#define NVM_ISDEF_CRCCOMPMECHANISMBUFFER_WDFC_ID_WLC_AP_LEARNOFPCPARTITIONCONFIG                    STD_ON
#define NVM_ISDEF_CRCCOMPMECHANISMBUFFER_WDFC_ID_WL_INFOOFPCPARTITIONCONFIG                         STD_ON
#define NVM_ISDEF_CRCCOMPMECHANISMBUFFER_WDFC_ID_WL_LOGOFPCPARTITIONCONFIG                          STD_ON
#define NVM_ISDEF_DATAINTEGRITYFSM_INSTANCEOFPCPARTITIONCONFIG                                      STD_ON
#define NVM_ISDEF_DATAINTEGRITYINTBUFFER_DEMADMINDATABLOCKOFPCPARTITIONCONFIG                       STD_ON
#define NVM_ISDEF_DATAINTEGRITYINTBUFFER_DEMSTATUSDATABLOCKOFPCPARTITIONCONFIG                      STD_ON
#define NVM_ISDEF_DATAINTEGRITYINTBUFFER_WDFC_ID_AP_CONNEXOFPCPARTITIONCONFIG                       STD_ON
#define NVM_ISDEF_DATAINTEGRITYINTBUFFER_WDFC_ID_AP_PARAOFPCPARTITIONCONFIG                         STD_ON
#define NVM_ISDEF_DATAINTEGRITYINTBUFFER_WDFC_ID_BOOT_PARAOFPCPARTITIONCONFIG                       STD_ON
#define NVM_ISDEF_DATAINTEGRITYINTBUFFER_WDFC_ID_CCPOFPCPARTITIONCONFIG                             STD_ON
#define NVM_ISDEF_DATAINTEGRITYINTBUFFER_WDFC_ID_DEBUG_DATAOFPCPARTITIONCONFIG                      STD_ON
#define NVM_ISDEF_DATAINTEGRITYINTBUFFER_WDFC_ID_DLCOFPCPARTITIONCONFIG                             STD_ON
#define NVM_ISDEF_DATAINTEGRITYINTBUFFER_WDFC_ID_DTCTIMEOFPCPARTITIONCONFIG                         STD_ON
#define NVM_ISDEF_DATAINTEGRITYINTBUFFER_WDFC_ID_ECUID_RDI_PROGRAMMING_INFOOFPCPARTITIONCONFIG      STD_ON
#define NVM_ISDEF_DATAINTEGRITYINTBUFFER_WDFC_ID_EOL_HW_VERSIONOFPCPARTITIONCONFIG                  STD_ON
#define NVM_ISDEF_DATAINTEGRITYINTBUFFER_WDFC_ID_EOL_INFOOFPCPARTITIONCONFIG                        STD_ON
#define NVM_ISDEF_DATAINTEGRITYINTBUFFER_WDFC_ID_EOL_PASSWORDOFPCPARTITIONCONFIG                    STD_ON
#define NVM_ISDEF_DATAINTEGRITYINTBUFFER_WDFC_ID_EOL_SWNUMBEROFPCPARTITIONCONFIG                    STD_ON
#define NVM_ISDEF_DATAINTEGRITYINTBUFFER_WDFC_ID_FAULT_CODEOFPCPARTITIONCONFIG                      STD_ON
#define NVM_ISDEF_DATAINTEGRITYINTBUFFER_WDFC_ID_HANDLE_CFGOFPCPARTITIONCONFIG                      STD_ON
#define NVM_ISDEF_DATAINTEGRITYINTBUFFER_WDFC_ID_IDENT_BANKOFPCPARTITIONCONFIG                      STD_ON
#define NVM_ISDEF_DATAINTEGRITYINTBUFFER_WDFC_ID_IDOPTION_SECURITYOFPCPARTITIONCONFIG               STD_ON
#define NVM_ISDEF_DATAINTEGRITYINTBUFFER_WDFC_ID_LAST_FDCOFPCPARTITIONCONFIG                        STD_ON
#define NVM_ISDEF_DATAINTEGRITYINTBUFFER_WDFC_ID_MAX_FDCOFPCPARTITIONCONFIG                         STD_ON
#define NVM_ISDEF_DATAINTEGRITYINTBUFFER_WDFC_ID_MIRROR_CFGOFPCPARTITIONCONFIG                      STD_ON
#define NVM_ISDEF_DATAINTEGRITYINTBUFFER_WDFC_ID_MIRROR_OTHER_1OFPCPARTITIONCONFIG                  STD_ON
#define NVM_ISDEF_DATAINTEGRITYINTBUFFER_WDFC_ID_MIRROR_POS_RECOFPCPARTITIONCONFIG                  STD_ON
#define NVM_ISDEF_DATAINTEGRITYINTBUFFER_WDFC_ID_MIRROR_STOFPCPARTITIONCONFIG                       STD_ON
#define NVM_ISDEF_DATAINTEGRITYINTBUFFER_WDFC_ID_PART_NUMBER_GEELYOFPCPARTITIONCONFIG               STD_ON
#define NVM_ISDEF_DATAINTEGRITYINTBUFFER_WDFC_ID_PMMOFPCPARTITIONCONFIG                             STD_ON
#define NVM_ISDEF_DATAINTEGRITYINTBUFFER_WDFC_ID_QCM_FAULT_DATAOFPCPARTITIONCONFIG                  STD_ON
#define NVM_ISDEF_DATAINTEGRITYINTBUFFER_WDFC_ID_SECURITY_ACCESSOFPCPARTITIONCONFIG                 STD_ON
#define NVM_ISDEF_DATAINTEGRITYINTBUFFER_WDFC_ID_SR_PROFILEOFPCPARTITIONCONFIG                      STD_ON
#define NVM_ISDEF_DATAINTEGRITYINTBUFFER_WDFC_ID_SWP1OFPCPARTITIONCONFIG                            STD_ON
#define NVM_ISDEF_DATAINTEGRITYINTBUFFER_WDFC_ID_THPAOFPCPARTITIONCONFIG                            STD_ON
#define NVM_ISDEF_DATAINTEGRITYINTBUFFER_WDFC_ID_VEH_CFGOFPCPARTITIONCONFIG                         STD_ON
#define NVM_ISDEF_DATAINTEGRITYINTBUFFER_WDFC_ID_VOL_POWER_MODE_CFGOFPCPARTITIONCONFIG              STD_ON
#define NVM_ISDEF_DATAINTEGRITYINTBUFFER_WDFC_ID_WLC_AP_LEARNOFPCPARTITIONCONFIG                    STD_ON
#define NVM_ISDEF_DATAINTEGRITYINTBUFFER_WDFC_ID_WL_INFOOFPCPARTITIONCONFIG                         STD_ON
#define NVM_ISDEF_DATAINTEGRITYINTBUFFER_WDFC_ID_WL_LOGOFPCPARTITIONCONFIG                          STD_ON
#define NVM_ISDEF_DATAINTEGRITYRECALCQUEUE_INSTANCEOFPCPARTITIONCONFIG                              STD_ON
#define NVM_ISDEF_DCMBLOCKMANAGEMENTINFOOFPCPARTITIONCONFIG                                         STD_ON
#define NVM_ISDEF_FOREGROUNDDATAINTEGRITYSERVICE_INSTANCEOFPCPARTITIONCONFIG                        STD_ON
#define NVM_ISDEF_INTERNALBUFFEROFPCPARTITIONCONFIG                                                 STD_ON
#define NVM_ISDEF_MULTIBLOCKFSMLIB_PROCESSINGSTACKELEMENTOFPCPARTITIONCONFIG                        STD_ON
#define NVM_ISDEF_MULTIBLOCKJOBFSM_CONTEXTOFPCPARTITIONCONFIG                                       STD_ON
#define NVM_ISDEF_MULTIBLOCKJOBFSM_INSTANCEOFPCPARTITIONCONFIG                                      STD_ON
#define NVM_ISDEF_MULTIBLOCKJOBINFORMATIONOFPCPARTITIONCONFIG                                       STD_ON
#define NVM_ISDEF_MULTIBLOCKJOBOFPCPARTITIONCONFIG                                                  STD_ON
#define NVM_ISDEF_MULTIBLOCKPROCESSORFSMLIB_INSTANCEOFPCPARTITIONCONFIG                             STD_ON
#define NVM_ISDEF_MULTIBLOCKPROCESSORFSMLIB_PROCESSINGSTACKELEMENTOFPCPARTITIONCONFIG               STD_ON
#define NVM_ISDEF_MULTIBLOCKSERVICEFSMLIB_INSTANCEOFPCPARTITIONCONFIG                               STD_ON
#define NVM_ISDEF_NVJOBCONTEXTOFPCPARTITIONCONFIG                                                   STD_ON
#define NVM_ISDEF_NVJOBFSM_INSTANCEOFPCPARTITIONCONFIG                                              STD_ON
#define NVM_ISDEF_NVSERVICEFSMLIB_INSTANCEOFPCPARTITIONCONFIG                                       STD_ON
#define NVM_ISDEF_NVSERVICEFSMLIB_PROCESSINGSTACKELEMENTOFPCPARTITIONCONFIG                         STD_ON
#define NVM_ISDEF_NVSERVICEPROCESSORFSMLIB_INSTANCEOFPCPARTITIONCONFIG                              STD_ON
#define NVM_ISDEF_NVSERVICEPROCESSORFSMLIB_PROCESSINGSTACKELEMENTOFPCPARTITIONCONFIG                STD_ON
#define NVM_ISDEF_QUEUELISTOFPCPARTITIONCONFIG                                                      STD_ON
#define NVM_ISDEF_QUEUE_INSTANCEOFPCPARTITIONCONFIG                                                 STD_ON
#define NVM_ISDEF_READALLFSM_CONTEXTOFPCPARTITIONCONFIG                                             STD_ON
#define NVM_ISDEF_READALLFSM_INSTANCEOFPCPARTITIONCONFIG                                            STD_ON
#define NVM_ISDEF_READBLOCKFSM_CONTEXTOFPCPARTITIONCONFIG                                           STD_ON
#define NVM_ISDEF_READBLOCKFSM_INSTANCEOFPCPARTITIONCONFIG                                          STD_ON
#define NVM_ISDEF_SERVICEPROCESSORFSMLIB_INSTANCEOFPCPARTITIONCONFIG                                STD_ON
#define NVM_ISDEF_SERVICEPROCESSORFSMLIB_PROCESSINGSTACKELEMENTOFPCPARTITIONCONFIG                  STD_ON
#define NVM_ISDEF_SERVICEPROCESSORFSM_CONTEXTOFPCPARTITIONCONFIG                                    STD_ON
#define NVM_ISDEF_SERVICEPROCESSORFSM_INSTANCEOFPCPARTITIONCONFIG                                   STD_ON
#define NVM_ISDEF_SINGLEBLOCKFSMLIB_PROCESSINGSTACKELEMENTOFPCPARTITIONCONFIG                       STD_ON
#define NVM_ISDEF_SINGLEBLOCKJOBCONTEXTOFPCPARTITIONCONFIG                                          STD_ON
#define NVM_ISDEF_SINGLEBLOCKJOBFSM_INSTANCEOFPCPARTITIONCONFIG                                     STD_ON
#define NVM_ISDEF_SINGLEBLOCKSERVICEFSMLIB_INSTANCEOFPCPARTITIONCONFIG                              STD_ON
#define NVM_ISDEF_VALIDATEALLFSM_INSTANCEOFPCPARTITIONCONFIG                                        STD_ON
#define NVM_ISDEF_WRITEALLFSM_CONTEXTOFPCPARTITIONCONFIG                                            STD_ON
#define NVM_ISDEF_WRITEALLFSM_INSTANCEOFPCPARTITIONCONFIG                                           STD_ON
#define NVM_ISDEF_WRITEBLOCKFSM_CONTEXTOFPCPARTITIONCONFIG                                          STD_ON
#define NVM_ISDEF_WRITEBLOCKFSM_INSTANCEOFPCPARTITIONCONFIG                                         STD_ON
#define NVM_ISDEF_WRITENVBLOCKFSM_CONTEXTOFPCPARTITIONCONFIG                                        STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  NvMPCEqualsAlwaysToDefines  NvM Equals Always To Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define contains the always equals value.
  \{
*/ 
#define NVM_EQ2_BLOCKDESCRIPTOR                                                                     
#define NVM_EQ2_PCPARTITIONCONFIGIDXOFPARTITIONIDENTIFIERS                                          
#define NVM_EQ2_PARTITIONSNVOFPARTITIONIDENTIFIERS                                                  
#define NVM_EQ2_PCPARTITIONCONFIGOFPCCONFIG                                                         NvM_PCPartitionConfig
#define NVM_EQ2_PARTITIONIDENTIFIERSOFPCCONFIG                                                      NvM_PartitionIdentifiers
#define NVM_EQ2_BACKGROUNDCRCRECALCFSMLIB_INSTANCEOFPCPARTITIONCONFIG                               (&(NvM_BackgroundCrcRecalcFsmLib_Instance))
#define NVM_EQ2_BACKGROUNDCRCRECALCFSMLIB_PROCESSINGSTACKELEMENTOFPCPARTITIONCONFIG                 NvM_BackgroundCrcRecalcFsmLib_ProcessingStackElement
#define NVM_EQ2_BACKGROUNDCRCRECALCFSM_CONTEXTOFPCPARTITIONCONFIG                                   (&(NvM_BackgroundCrcRecalcFsm_Context))
#define NVM_EQ2_BACKGROUNDCRCRECALCFSM_INSTANCEOFPCPARTITIONCONFIG                                  (&(NvM_BackgroundCrcRecalcFsm_Instance))
#define NVM_EQ2_BACKGROUNDDATAINTEGRITYSERVICE_INSTANCEOFPCPARTITIONCONFIG                          (&(NvM_BackgroundDataIntegrityService_Instance))
#define NVM_EQ2_BLOCKDESCRIPTOROFPCPARTITIONCONFIG                                                  NvM_BlockDescriptor
#define NVM_EQ2_BLOCKMANAGEMENTINFO_DEMADMINDATABLOCKOFPCPARTITIONCONFIG                            (&(NvM_BlockManagementInfo_DemAdminDataBlock))
#define NVM_EQ2_BLOCKMANAGEMENTINFO_DEMSTATUSDATABLOCKOFPCPARTITIONCONFIG                           (&(NvM_BlockManagementInfo_DemStatusDataBlock))
#define NVM_EQ2_BLOCKMANAGEMENTINFO_NVMCONFIGBLOCKOFPCPARTITIONCONFIG                               (&(NvM_BlockManagementInfo_NvMConfigBlock))
#define NVM_EQ2_BLOCKMANAGEMENTINFO_NVMMULTIBLOCKOFPCPARTITIONCONFIG                                (&(NvM_BlockManagementInfo_NvMMultiBlock))
#define NVM_EQ2_BLOCKMANAGEMENTINFO_WDFC_ID_AP_CONNEXOFPCPARTITIONCONFIG                            (&(NvM_BlockManagementInfo_WDFC_ID_AP_CONNEX))
#define NVM_EQ2_BLOCKMANAGEMENTINFO_WDFC_ID_AP_PARAOFPCPARTITIONCONFIG                              (&(NvM_BlockManagementInfo_WDFC_ID_AP_PARA))
#define NVM_EQ2_BLOCKMANAGEMENTINFO_WDFC_ID_BOOT_PARAOFPCPARTITIONCONFIG                            (&(NvM_BlockManagementInfo_WDFC_ID_BOOT_PARA))
#define NVM_EQ2_BLOCKMANAGEMENTINFO_WDFC_ID_CCPOFPCPARTITIONCONFIG                                  (&(NvM_BlockManagementInfo_WDFC_ID_CCP))
#define NVM_EQ2_BLOCKMANAGEMENTINFO_WDFC_ID_DEBUG_DATAOFPCPARTITIONCONFIG                           (&(NvM_BlockManagementInfo_WDFC_ID_DEBUG_DATA))
#define NVM_EQ2_BLOCKMANAGEMENTINFO_WDFC_ID_DLCOFPCPARTITIONCONFIG                                  (&(NvM_BlockManagementInfo_WDFC_ID_DLC))
#define NVM_EQ2_BLOCKMANAGEMENTINFO_WDFC_ID_DTCTIMEOFPCPARTITIONCONFIG                              (&(NvM_BlockManagementInfo_WDFC_ID_DTCTime))
#define NVM_EQ2_BLOCKMANAGEMENTINFO_WDFC_ID_ECUID_RDI_PROGRAMMING_INFOOFPCPARTITIONCONFIG           (&(NvM_BlockManagementInfo_WDFC_ID_ECUID_RDI_PROGRAMMING_INFO))
#define NVM_EQ2_BLOCKMANAGEMENTINFO_WDFC_ID_EOL_HW_VERSIONOFPCPARTITIONCONFIG                       (&(NvM_BlockManagementInfo_WDFC_ID_EOL_HW_VERSION))
#define NVM_EQ2_BLOCKMANAGEMENTINFO_WDFC_ID_EOL_INFOOFPCPARTITIONCONFIG                             (&(NvM_BlockManagementInfo_WDFC_ID_EOL_INFO))
#define NVM_EQ2_BLOCKMANAGEMENTINFO_WDFC_ID_EOL_PASSWORDOFPCPARTITIONCONFIG                         (&(NvM_BlockManagementInfo_WDFC_ID_EOL_PASSWORD))
#define NVM_EQ2_BLOCKMANAGEMENTINFO_WDFC_ID_EOL_SWNUMBEROFPCPARTITIONCONFIG                         (&(NvM_BlockManagementInfo_WDFC_ID_EOL_SWNUMBER))
#define NVM_EQ2_BLOCKMANAGEMENTINFO_WDFC_ID_FAULT_CODEOFPCPARTITIONCONFIG                           (&(NvM_BlockManagementInfo_WDFC_ID_FAULT_CODE))
#define NVM_EQ2_BLOCKMANAGEMENTINFO_WDFC_ID_HANDLE_CFGOFPCPARTITIONCONFIG                           (&(NvM_BlockManagementInfo_WDFC_ID_HANDLE_CFG))
#define NVM_EQ2_BLOCKMANAGEMENTINFO_WDFC_ID_IDENT_BANKOFPCPARTITIONCONFIG                           (&(NvM_BlockManagementInfo_WDFC_ID_IDENT_BANK))
#define NVM_EQ2_BLOCKMANAGEMENTINFO_WDFC_ID_IDOPTION_SECURITYOFPCPARTITIONCONFIG                    (&(NvM_BlockManagementInfo_WDFC_ID_IDOPTION_SECURITY))
#define NVM_EQ2_BLOCKMANAGEMENTINFO_WDFC_ID_LAST_FDCOFPCPARTITIONCONFIG                             (&(NvM_BlockManagementInfo_WDFC_ID_LAST_FDC))
#define NVM_EQ2_BLOCKMANAGEMENTINFO_WDFC_ID_MAX_FDCOFPCPARTITIONCONFIG                              (&(NvM_BlockManagementInfo_WDFC_ID_MAX_FDC))
#define NVM_EQ2_BLOCKMANAGEMENTINFO_WDFC_ID_MIRROR_CFGOFPCPARTITIONCONFIG                           (&(NvM_BlockManagementInfo_WDFC_ID_MIRROR_CFG))
#define NVM_EQ2_BLOCKMANAGEMENTINFO_WDFC_ID_MIRROR_OTHER_1OFPCPARTITIONCONFIG                       (&(NvM_BlockManagementInfo_WDFC_ID_MIRROR_OTHER_1))
#define NVM_EQ2_BLOCKMANAGEMENTINFO_WDFC_ID_MIRROR_POS_RECOFPCPARTITIONCONFIG                       (&(NvM_BlockManagementInfo_WDFC_ID_MIRROR_POS_REC))
#define NVM_EQ2_BLOCKMANAGEMENTINFO_WDFC_ID_MIRROR_STOFPCPARTITIONCONFIG                            (&(NvM_BlockManagementInfo_WDFC_ID_MIRROR_ST))
#define NVM_EQ2_BLOCKMANAGEMENTINFO_WDFC_ID_PART_NUMBER_GEELYOFPCPARTITIONCONFIG                    (&(NvM_BlockManagementInfo_WDFC_ID_PART_NUMBER_GEELY))
#define NVM_EQ2_BLOCKMANAGEMENTINFO_WDFC_ID_PMMOFPCPARTITIONCONFIG                                  (&(NvM_BlockManagementInfo_WDFC_ID_PMM))
#define NVM_EQ2_BLOCKMANAGEMENTINFO_WDFC_ID_QCM_FAULT_DATAOFPCPARTITIONCONFIG                       (&(NvM_BlockManagementInfo_WDFC_ID_QCM_FAULT_DATA))
#define NVM_EQ2_BLOCKMANAGEMENTINFO_WDFC_ID_SECURITY_ACCESSOFPCPARTITIONCONFIG                      (&(NvM_BlockManagementInfo_WDFC_ID_SECURITY_ACCESS))
#define NVM_EQ2_BLOCKMANAGEMENTINFO_WDFC_ID_SR_PROFILEOFPCPARTITIONCONFIG                           (&(NvM_BlockManagementInfo_WDFC_ID_SR_PROFILE))
#define NVM_EQ2_BLOCKMANAGEMENTINFO_WDFC_ID_SWP1OFPCPARTITIONCONFIG                                 (&(NvM_BlockManagementInfo_WDFC_ID_SWP1))
#define NVM_EQ2_BLOCKMANAGEMENTINFO_WDFC_ID_THPAOFPCPARTITIONCONFIG                                 (&(NvM_BlockManagementInfo_WDFC_ID_THPA))
#define NVM_EQ2_BLOCKMANAGEMENTINFO_WDFC_ID_VEH_CFGOFPCPARTITIONCONFIG                              (&(NvM_BlockManagementInfo_WDFC_ID_VEH_CFG))
#define NVM_EQ2_BLOCKMANAGEMENTINFO_WDFC_ID_VOL_POWER_MODE_CFGOFPCPARTITIONCONFIG                   (&(NvM_BlockManagementInfo_WDFC_ID_VOL_POWER_MODE_CFG))
#define NVM_EQ2_BLOCKMANAGEMENTINFO_WDFC_ID_WLC_AP_LEARNOFPCPARTITIONCONFIG                         (&(NvM_BlockManagementInfo_WDFC_ID_WLC_AP_LEARN))
#define NVM_EQ2_BLOCKMANAGEMENTINFO_WDFC_ID_WL_INFOOFPCPARTITIONCONFIG                              (&(NvM_BlockManagementInfo_WDFC_ID_WL_INFO))
#define NVM_EQ2_BLOCKMANAGEMENTINFO_WDFC_ID_WL_LOGOFPCPARTITIONCONFIG                               (&(NvM_BlockManagementInfo_WDFC_ID_WL_LOG))
#define NVM_EQ2_CRCCOMPMECHANISMBUFFER_DEMADMINDATABLOCKOFPCPARTITIONCONFIG                         NvM_CrcCompMechanismBuffer_DemAdminDataBlock
#define NVM_EQ2_CRCCOMPMECHANISMBUFFER_DEMSTATUSDATABLOCKOFPCPARTITIONCONFIG                        NvM_CrcCompMechanismBuffer_DemStatusDataBlock
#define NVM_EQ2_CRCCOMPMECHANISMBUFFER_NVMCONFIGBLOCKOFPCPARTITIONCONFIG                            NvM_CrcCompMechanismBuffer_NvMConfigBlock
#define NVM_EQ2_CRCCOMPMECHANISMBUFFER_WDFC_ID_AP_CONNEXOFPCPARTITIONCONFIG                         NvM_CrcCompMechanismBuffer_WDFC_ID_AP_CONNEX
#define NVM_EQ2_CRCCOMPMECHANISMBUFFER_WDFC_ID_AP_PARAOFPCPARTITIONCONFIG                           NvM_CrcCompMechanismBuffer_WDFC_ID_AP_PARA
#define NVM_EQ2_CRCCOMPMECHANISMBUFFER_WDFC_ID_BOOT_PARAOFPCPARTITIONCONFIG                         NvM_CrcCompMechanismBuffer_WDFC_ID_BOOT_PARA
#define NVM_EQ2_CRCCOMPMECHANISMBUFFER_WDFC_ID_CCPOFPCPARTITIONCONFIG                               NvM_CrcCompMechanismBuffer_WDFC_ID_CCP
#define NVM_EQ2_CRCCOMPMECHANISMBUFFER_WDFC_ID_DEBUG_DATAOFPCPARTITIONCONFIG                        NvM_CrcCompMechanismBuffer_WDFC_ID_DEBUG_DATA
#define NVM_EQ2_CRCCOMPMECHANISMBUFFER_WDFC_ID_DLCOFPCPARTITIONCONFIG                               NvM_CrcCompMechanismBuffer_WDFC_ID_DLC
#define NVM_EQ2_CRCCOMPMECHANISMBUFFER_WDFC_ID_DTCTIMEOFPCPARTITIONCONFIG                           NvM_CrcCompMechanismBuffer_WDFC_ID_DTCTime
#define NVM_EQ2_CRCCOMPMECHANISMBUFFER_WDFC_ID_ECUID_RDI_PROGRAMMING_INFOOFPCPARTITIONCONFIG        NvM_CrcCompMechanismBuffer_WDFC_ID_ECUID_RDI_PROGRAMMING_INFO
#define NVM_EQ2_CRCCOMPMECHANISMBUFFER_WDFC_ID_EOL_HW_VERSIONOFPCPARTITIONCONFIG                    NvM_CrcCompMechanismBuffer_WDFC_ID_EOL_HW_VERSION
#define NVM_EQ2_CRCCOMPMECHANISMBUFFER_WDFC_ID_EOL_INFOOFPCPARTITIONCONFIG                          NvM_CrcCompMechanismBuffer_WDFC_ID_EOL_INFO
#define NVM_EQ2_CRCCOMPMECHANISMBUFFER_WDFC_ID_EOL_PASSWORDOFPCPARTITIONCONFIG                      NvM_CrcCompMechanismBuffer_WDFC_ID_EOL_PASSWORD
#define NVM_EQ2_CRCCOMPMECHANISMBUFFER_WDFC_ID_EOL_SWNUMBEROFPCPARTITIONCONFIG                      NvM_CrcCompMechanismBuffer_WDFC_ID_EOL_SWNUMBER
#define NVM_EQ2_CRCCOMPMECHANISMBUFFER_WDFC_ID_FAULT_CODEOFPCPARTITIONCONFIG                        NvM_CrcCompMechanismBuffer_WDFC_ID_FAULT_CODE
#define NVM_EQ2_CRCCOMPMECHANISMBUFFER_WDFC_ID_HANDLE_CFGOFPCPARTITIONCONFIG                        NvM_CrcCompMechanismBuffer_WDFC_ID_HANDLE_CFG
#define NVM_EQ2_CRCCOMPMECHANISMBUFFER_WDFC_ID_IDENT_BANKOFPCPARTITIONCONFIG                        NvM_CrcCompMechanismBuffer_WDFC_ID_IDENT_BANK
#define NVM_EQ2_CRCCOMPMECHANISMBUFFER_WDFC_ID_IDOPTION_SECURITYOFPCPARTITIONCONFIG                 NvM_CrcCompMechanismBuffer_WDFC_ID_IDOPTION_SECURITY
#define NVM_EQ2_CRCCOMPMECHANISMBUFFER_WDFC_ID_LAST_FDCOFPCPARTITIONCONFIG                          NvM_CrcCompMechanismBuffer_WDFC_ID_LAST_FDC
#define NVM_EQ2_CRCCOMPMECHANISMBUFFER_WDFC_ID_MAX_FDCOFPCPARTITIONCONFIG                           NvM_CrcCompMechanismBuffer_WDFC_ID_MAX_FDC
#define NVM_EQ2_CRCCOMPMECHANISMBUFFER_WDFC_ID_MIRROR_CFGOFPCPARTITIONCONFIG                        NvM_CrcCompMechanismBuffer_WDFC_ID_MIRROR_CFG
#define NVM_EQ2_CRCCOMPMECHANISMBUFFER_WDFC_ID_MIRROR_OTHER_1OFPCPARTITIONCONFIG                    NvM_CrcCompMechanismBuffer_WDFC_ID_MIRROR_OTHER_1
#define NVM_EQ2_CRCCOMPMECHANISMBUFFER_WDFC_ID_MIRROR_POS_RECOFPCPARTITIONCONFIG                    NvM_CrcCompMechanismBuffer_WDFC_ID_MIRROR_POS_REC
#define NVM_EQ2_CRCCOMPMECHANISMBUFFER_WDFC_ID_MIRROR_STOFPCPARTITIONCONFIG                         NvM_CrcCompMechanismBuffer_WDFC_ID_MIRROR_ST
#define NVM_EQ2_CRCCOMPMECHANISMBUFFER_WDFC_ID_PART_NUMBER_GEELYOFPCPARTITIONCONFIG                 NvM_CrcCompMechanismBuffer_WDFC_ID_PART_NUMBER_GEELY
#define NVM_EQ2_CRCCOMPMECHANISMBUFFER_WDFC_ID_PMMOFPCPARTITIONCONFIG                               NvM_CrcCompMechanismBuffer_WDFC_ID_PMM
#define NVM_EQ2_CRCCOMPMECHANISMBUFFER_WDFC_ID_QCM_FAULT_DATAOFPCPARTITIONCONFIG                    NvM_CrcCompMechanismBuffer_WDFC_ID_QCM_FAULT_DATA
#define NVM_EQ2_CRCCOMPMECHANISMBUFFER_WDFC_ID_SECURITY_ACCESSOFPCPARTITIONCONFIG                   NvM_CrcCompMechanismBuffer_WDFC_ID_SECURITY_ACCESS
#define NVM_EQ2_CRCCOMPMECHANISMBUFFER_WDFC_ID_SR_PROFILEOFPCPARTITIONCONFIG                        NvM_CrcCompMechanismBuffer_WDFC_ID_SR_PROFILE
#define NVM_EQ2_CRCCOMPMECHANISMBUFFER_WDFC_ID_SWP1OFPCPARTITIONCONFIG                              NvM_CrcCompMechanismBuffer_WDFC_ID_SWP1
#define NVM_EQ2_CRCCOMPMECHANISMBUFFER_WDFC_ID_THPAOFPCPARTITIONCONFIG                              NvM_CrcCompMechanismBuffer_WDFC_ID_THPA
#define NVM_EQ2_CRCCOMPMECHANISMBUFFER_WDFC_ID_VEH_CFGOFPCPARTITIONCONFIG                           NvM_CrcCompMechanismBuffer_WDFC_ID_VEH_CFG
#define NVM_EQ2_CRCCOMPMECHANISMBUFFER_WDFC_ID_VOL_POWER_MODE_CFGOFPCPARTITIONCONFIG                NvM_CrcCompMechanismBuffer_WDFC_ID_VOL_POWER_MODE_CFG
#define NVM_EQ2_CRCCOMPMECHANISMBUFFER_WDFC_ID_WLC_AP_LEARNOFPCPARTITIONCONFIG                      NvM_CrcCompMechanismBuffer_WDFC_ID_WLC_AP_LEARN
#define NVM_EQ2_CRCCOMPMECHANISMBUFFER_WDFC_ID_WL_INFOOFPCPARTITIONCONFIG                           NvM_CrcCompMechanismBuffer_WDFC_ID_WL_INFO
#define NVM_EQ2_CRCCOMPMECHANISMBUFFER_WDFC_ID_WL_LOGOFPCPARTITIONCONFIG                            NvM_CrcCompMechanismBuffer_WDFC_ID_WL_LOG
#define NVM_EQ2_DATAINTEGRITYFSM_INSTANCEOFPCPARTITIONCONFIG                                        (&(NvM_DataIntegrityFsm_Instance))
#define NVM_EQ2_DATAINTEGRITYINTBUFFER_DEMADMINDATABLOCKOFPCPARTITIONCONFIG                         NvM_DataIntegrityIntBuffer_DemAdminDataBlock
#define NVM_EQ2_DATAINTEGRITYINTBUFFER_DEMSTATUSDATABLOCKOFPCPARTITIONCONFIG                        NvM_DataIntegrityIntBuffer_DemStatusDataBlock
#define NVM_EQ2_DATAINTEGRITYINTBUFFER_WDFC_ID_AP_CONNEXOFPCPARTITIONCONFIG                         NvM_DataIntegrityIntBuffer_WDFC_ID_AP_CONNEX
#define NVM_EQ2_DATAINTEGRITYINTBUFFER_WDFC_ID_AP_PARAOFPCPARTITIONCONFIG                           NvM_DataIntegrityIntBuffer_WDFC_ID_AP_PARA
#define NVM_EQ2_DATAINTEGRITYINTBUFFER_WDFC_ID_BOOT_PARAOFPCPARTITIONCONFIG                         NvM_DataIntegrityIntBuffer_WDFC_ID_BOOT_PARA
#define NVM_EQ2_DATAINTEGRITYINTBUFFER_WDFC_ID_CCPOFPCPARTITIONCONFIG                               NvM_DataIntegrityIntBuffer_WDFC_ID_CCP
#define NVM_EQ2_DATAINTEGRITYINTBUFFER_WDFC_ID_DEBUG_DATAOFPCPARTITIONCONFIG                        NvM_DataIntegrityIntBuffer_WDFC_ID_DEBUG_DATA
#define NVM_EQ2_DATAINTEGRITYINTBUFFER_WDFC_ID_DLCOFPCPARTITIONCONFIG                               NvM_DataIntegrityIntBuffer_WDFC_ID_DLC
#define NVM_EQ2_DATAINTEGRITYINTBUFFER_WDFC_ID_DTCTIMEOFPCPARTITIONCONFIG                           NvM_DataIntegrityIntBuffer_WDFC_ID_DTCTime
#define NVM_EQ2_DATAINTEGRITYINTBUFFER_WDFC_ID_ECUID_RDI_PROGRAMMING_INFOOFPCPARTITIONCONFIG        NvM_DataIntegrityIntBuffer_WDFC_ID_ECUID_RDI_PROGRAMMING_INFO
#define NVM_EQ2_DATAINTEGRITYINTBUFFER_WDFC_ID_EOL_HW_VERSIONOFPCPARTITIONCONFIG                    NvM_DataIntegrityIntBuffer_WDFC_ID_EOL_HW_VERSION
#define NVM_EQ2_DATAINTEGRITYINTBUFFER_WDFC_ID_EOL_INFOOFPCPARTITIONCONFIG                          NvM_DataIntegrityIntBuffer_WDFC_ID_EOL_INFO
#define NVM_EQ2_DATAINTEGRITYINTBUFFER_WDFC_ID_EOL_PASSWORDOFPCPARTITIONCONFIG                      NvM_DataIntegrityIntBuffer_WDFC_ID_EOL_PASSWORD
#define NVM_EQ2_DATAINTEGRITYINTBUFFER_WDFC_ID_EOL_SWNUMBEROFPCPARTITIONCONFIG                      NvM_DataIntegrityIntBuffer_WDFC_ID_EOL_SWNUMBER
#define NVM_EQ2_DATAINTEGRITYINTBUFFER_WDFC_ID_FAULT_CODEOFPCPARTITIONCONFIG                        NvM_DataIntegrityIntBuffer_WDFC_ID_FAULT_CODE
#define NVM_EQ2_DATAINTEGRITYINTBUFFER_WDFC_ID_HANDLE_CFGOFPCPARTITIONCONFIG                        NvM_DataIntegrityIntBuffer_WDFC_ID_HANDLE_CFG
#define NVM_EQ2_DATAINTEGRITYINTBUFFER_WDFC_ID_IDENT_BANKOFPCPARTITIONCONFIG                        NvM_DataIntegrityIntBuffer_WDFC_ID_IDENT_BANK
#define NVM_EQ2_DATAINTEGRITYINTBUFFER_WDFC_ID_IDOPTION_SECURITYOFPCPARTITIONCONFIG                 NvM_DataIntegrityIntBuffer_WDFC_ID_IDOPTION_SECURITY
#define NVM_EQ2_DATAINTEGRITYINTBUFFER_WDFC_ID_LAST_FDCOFPCPARTITIONCONFIG                          NvM_DataIntegrityIntBuffer_WDFC_ID_LAST_FDC
#define NVM_EQ2_DATAINTEGRITYINTBUFFER_WDFC_ID_MAX_FDCOFPCPARTITIONCONFIG                           NvM_DataIntegrityIntBuffer_WDFC_ID_MAX_FDC
#define NVM_EQ2_DATAINTEGRITYINTBUFFER_WDFC_ID_MIRROR_CFGOFPCPARTITIONCONFIG                        NvM_DataIntegrityIntBuffer_WDFC_ID_MIRROR_CFG
#define NVM_EQ2_DATAINTEGRITYINTBUFFER_WDFC_ID_MIRROR_OTHER_1OFPCPARTITIONCONFIG                    NvM_DataIntegrityIntBuffer_WDFC_ID_MIRROR_OTHER_1
#define NVM_EQ2_DATAINTEGRITYINTBUFFER_WDFC_ID_MIRROR_POS_RECOFPCPARTITIONCONFIG                    NvM_DataIntegrityIntBuffer_WDFC_ID_MIRROR_POS_REC
#define NVM_EQ2_DATAINTEGRITYINTBUFFER_WDFC_ID_MIRROR_STOFPCPARTITIONCONFIG                         NvM_DataIntegrityIntBuffer_WDFC_ID_MIRROR_ST
#define NVM_EQ2_DATAINTEGRITYINTBUFFER_WDFC_ID_PART_NUMBER_GEELYOFPCPARTITIONCONFIG                 NvM_DataIntegrityIntBuffer_WDFC_ID_PART_NUMBER_GEELY
#define NVM_EQ2_DATAINTEGRITYINTBUFFER_WDFC_ID_PMMOFPCPARTITIONCONFIG                               NvM_DataIntegrityIntBuffer_WDFC_ID_PMM
#define NVM_EQ2_DATAINTEGRITYINTBUFFER_WDFC_ID_QCM_FAULT_DATAOFPCPARTITIONCONFIG                    NvM_DataIntegrityIntBuffer_WDFC_ID_QCM_FAULT_DATA
#define NVM_EQ2_DATAINTEGRITYINTBUFFER_WDFC_ID_SECURITY_ACCESSOFPCPARTITIONCONFIG                   NvM_DataIntegrityIntBuffer_WDFC_ID_SECURITY_ACCESS
#define NVM_EQ2_DATAINTEGRITYINTBUFFER_WDFC_ID_SR_PROFILEOFPCPARTITIONCONFIG                        NvM_DataIntegrityIntBuffer_WDFC_ID_SR_PROFILE
#define NVM_EQ2_DATAINTEGRITYINTBUFFER_WDFC_ID_SWP1OFPCPARTITIONCONFIG                              NvM_DataIntegrityIntBuffer_WDFC_ID_SWP1
#define NVM_EQ2_DATAINTEGRITYINTBUFFER_WDFC_ID_THPAOFPCPARTITIONCONFIG                              NvM_DataIntegrityIntBuffer_WDFC_ID_THPA
#define NVM_EQ2_DATAINTEGRITYINTBUFFER_WDFC_ID_VEH_CFGOFPCPARTITIONCONFIG                           NvM_DataIntegrityIntBuffer_WDFC_ID_VEH_CFG
#define NVM_EQ2_DATAINTEGRITYINTBUFFER_WDFC_ID_VOL_POWER_MODE_CFGOFPCPARTITIONCONFIG                NvM_DataIntegrityIntBuffer_WDFC_ID_VOL_POWER_MODE_CFG
#define NVM_EQ2_DATAINTEGRITYINTBUFFER_WDFC_ID_WLC_AP_LEARNOFPCPARTITIONCONFIG                      NvM_DataIntegrityIntBuffer_WDFC_ID_WLC_AP_LEARN
#define NVM_EQ2_DATAINTEGRITYINTBUFFER_WDFC_ID_WL_INFOOFPCPARTITIONCONFIG                           NvM_DataIntegrityIntBuffer_WDFC_ID_WL_INFO
#define NVM_EQ2_DATAINTEGRITYINTBUFFER_WDFC_ID_WL_LOGOFPCPARTITIONCONFIG                            NvM_DataIntegrityIntBuffer_WDFC_ID_WL_LOG
#define NVM_EQ2_DATAINTEGRITYRECALCQUEUE_INSTANCEOFPCPARTITIONCONFIG                                (&(NvM_DataIntegrityRecalcQueue_Instance))
#define NVM_EQ2_DCMBLOCKMANAGEMENTINFOOFPCPARTITIONCONFIG                                           (&(NvM_DcmBlockManagementInfo))
#define NVM_EQ2_FOREGROUNDDATAINTEGRITYSERVICE_INSTANCEOFPCPARTITIONCONFIG                          (&(NvM_ForegroundDataIntegrityService_Instance))
#define NVM_EQ2_INTERNALBUFFEROFPCPARTITIONCONFIG                                                   NvM_InternalBuffer
#define NVM_EQ2_MULTIBLOCKFSMLIB_PROCESSINGSTACKELEMENTOFPCPARTITIONCONFIG                          NvM_MultiBlockFsmLib_ProcessingStackElement
#define NVM_EQ2_MULTIBLOCKJOBFSM_CONTEXTOFPCPARTITIONCONFIG                                         (&(NvM_MultiBlockJobFsm_Context))
#define NVM_EQ2_MULTIBLOCKJOBFSM_INSTANCEOFPCPARTITIONCONFIG                                        (&(NvM_MultiBlockJobFsm_Instance))
#define NVM_EQ2_MULTIBLOCKJOBINFORMATIONOFPCPARTITIONCONFIG                                         (&(NvM_MultiBlockJobInformation))
#define NVM_EQ2_MULTIBLOCKJOBOFPCPARTITIONCONFIG                                                    (&(NvM_MultiBlockJob))
#define NVM_EQ2_MULTIBLOCKPROCESSORFSMLIB_INSTANCEOFPCPARTITIONCONFIG                               (&(NvM_MultiBlockProcessorFsmLib_Instance))
#define NVM_EQ2_MULTIBLOCKPROCESSORFSMLIB_PROCESSINGSTACKELEMENTOFPCPARTITIONCONFIG                 NvM_MultiBlockProcessorFsmLib_ProcessingStackElement
#define NVM_EQ2_MULTIBLOCKSERVICEFSMLIB_INSTANCEOFPCPARTITIONCONFIG                                 (&(NvM_MultiBlockServiceFsmLib_Instance))
#define NVM_EQ2_NVJOBCONTEXTOFPCPARTITIONCONFIG                                                     (&(NvM_NvJobContext))
#define NVM_EQ2_NVJOBFSM_INSTANCEOFPCPARTITIONCONFIG                                                (&(NvM_NvJobFsm_Instance))
#define NVM_EQ2_NVSERVICEFSMLIB_INSTANCEOFPCPARTITIONCONFIG                                         (&(NvM_NvServiceFsmLib_Instance))
#define NVM_EQ2_NVSERVICEFSMLIB_PROCESSINGSTACKELEMENTOFPCPARTITIONCONFIG                           NvM_NvServiceFsmLib_ProcessingStackElement
#define NVM_EQ2_NVSERVICEPROCESSORFSMLIB_INSTANCEOFPCPARTITIONCONFIG                                (&(NvM_NvServiceProcessorFsmLib_Instance))
#define NVM_EQ2_NVSERVICEPROCESSORFSMLIB_PROCESSINGSTACKELEMENTOFPCPARTITIONCONFIG                  NvM_NvServiceProcessorFsmLib_ProcessingStackElement
#define NVM_EQ2_QUEUELISTOFPCPARTITIONCONFIG                                                        NvM_QueueList
#define NVM_EQ2_QUEUE_INSTANCEOFPCPARTITIONCONFIG                                                   (&(NvM_Queue_Instance))
#define NVM_EQ2_READALLFSM_CONTEXTOFPCPARTITIONCONFIG                                               (&(NvM_ReadAllFsm_Context))
#define NVM_EQ2_READALLFSM_INSTANCEOFPCPARTITIONCONFIG                                              (&(NvM_ReadAllFsm_Instance))
#define NVM_EQ2_READBLOCKFSM_CONTEXTOFPCPARTITIONCONFIG                                             (&(NvM_ReadBlockFsm_Context))
#define NVM_EQ2_READBLOCKFSM_INSTANCEOFPCPARTITIONCONFIG                                            (&(NvM_ReadBlockFsm_Instance))
#define NVM_EQ2_SERVICEPROCESSORFSMLIB_INSTANCEOFPCPARTITIONCONFIG                                  (&(NvM_ServiceProcessorFsmLib_Instance))
#define NVM_EQ2_SERVICEPROCESSORFSMLIB_PROCESSINGSTACKELEMENTOFPCPARTITIONCONFIG                    NvM_ServiceProcessorFsmLib_ProcessingStackElement
#define NVM_EQ2_SERVICEPROCESSORFSM_CONTEXTOFPCPARTITIONCONFIG                                      (&(NvM_ServiceProcessorFsm_Context))
#define NVM_EQ2_SERVICEPROCESSORFSM_INSTANCEOFPCPARTITIONCONFIG                                     (&(NvM_ServiceProcessorFsm_Instance))
#define NVM_EQ2_SINGLEBLOCKFSMLIB_PROCESSINGSTACKELEMENTOFPCPARTITIONCONFIG                         NvM_SingleBlockFsmLib_ProcessingStackElement
#define NVM_EQ2_SINGLEBLOCKJOBCONTEXTOFPCPARTITIONCONFIG                                            (&(NvM_SingleBlockJobContext))
#define NVM_EQ2_SINGLEBLOCKJOBFSM_INSTANCEOFPCPARTITIONCONFIG                                       (&(NvM_SingleBlockJobFsm_Instance))
#define NVM_EQ2_SINGLEBLOCKSERVICEFSMLIB_INSTANCEOFPCPARTITIONCONFIG                                (&(NvM_SingleBlockServiceFsmLib_Instance))
#define NVM_EQ2_VALIDATEALLFSM_INSTANCEOFPCPARTITIONCONFIG                                          (&(NvM_ValidateAllFsm_Instance))
#define NVM_EQ2_WRITEALLFSM_CONTEXTOFPCPARTITIONCONFIG                                              (&(NvM_WriteAllFsm_Context))
#define NVM_EQ2_WRITEALLFSM_INSTANCEOFPCPARTITIONCONFIG                                             (&(NvM_WriteAllFsm_Instance))
#define NVM_EQ2_WRITEBLOCKFSM_CONTEXTOFPCPARTITIONCONFIG                                            (&(NvM_WriteBlockFsm_Context))
#define NVM_EQ2_WRITEBLOCKFSM_INSTANCEOFPCPARTITIONCONFIG                                           (&(NvM_WriteBlockFsm_Instance))
#define NVM_EQ2_WRITENVBLOCKFSM_CONTEXTOFPCPARTITIONCONFIG                                          (&(NvM_WriteNvBlockFsm_Context))
/** 
  \}
*/ 

/** 
  \defgroup  NvMPCSymbolicInitializationPointers  NvM Symbolic Initialization Pointers (PRE_COMPILE)
  \brief  Symbolic initialization pointers to be used in the call of a preinit or init function.
  \{
*/ 
#define NvM_Config_Ptr                                                                              NULL_PTR  /**< symbolic identifier which shall be used to initialize 'NvM' */
/** 
  \}
*/ 

/** 
  \defgroup  NvMPCInitializationSymbols  NvM Initialization Symbols (PRE_COMPILE)
  \brief  Symbolic initialization pointers which may be used in the call of a preinit or init function. Please note, that the defined value can be a 'NULL_PTR' and the address operator is not usable.
  \{
*/ 
#define NvM_Config                                                                                  NULL_PTR  /**< symbolic identifier which could be used to initialize 'NvM */
/** 
  \}
*/ 

/** 
  \defgroup  NvMPCGeneral  NvM General (PRE_COMPILE)
  \brief  General constant defines not associated with a group of defines.
  \{
*/ 
#define NVM_CHECK_INIT_POINTER                                                                      STD_OFF  /**< STD_ON if the init pointer shall not be used as NULL_PTR and a check shall validate this. */
#define NVM_FINAL_MAGIC_NUMBER                                                                      0x141Eu  /**< the precompile constant to validate the size of the initialization structure at initialization time of NvM */
#define NVM_INDIVIDUAL_POSTBUILD                                                                    STD_OFF  /**< the precompile constant to check, that the module is individual postbuildable. The module 'NvM' is not configured to be postbuild capable. */
#define NVM_INIT_DATA                                                                               NVM_CONST  /**< CompilerMemClassDefine for the initialization data. */
#define NVM_INIT_DATA_HASH_CODE                                                                     607586653  /**< the precompile constant to validate the initialization structure at initialization time of NvM with a hashcode. The seed value is '0x141Eu' */
#define NVM_USE_ECUM_BSW_ERROR_HOOK                                                                 STD_OFF  /**< STD_ON if the EcuM_BswErrorHook shall be called in the ConfigPtr check. */
#define NVM_USE_INIT_POINTER                                                                        STD_OFF  /**< STD_ON if the init pointer NvM shall be used. */
#define NvM_PartitionIndexOfCSLForDefaultPartition                                                  0u  /**< internal partition index of the ComStackLib for the partition DefaultPartition */
/** 
  \}
*/ 



/* Partition Identifiers */
#define NVM_PARTITION_ID_MASTER NvM_PartitionIndexOfCSLForDefaultPartition


#define DefaultPartition 0u

/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/

/** 
  \defgroup  DataAccessMacros  Data Access Macros
  \brief  generated data access macros to abstract the generated data from the code to read and write CONST or VAR data.
  \{
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTION MACROS
**********************************************************************************************************************/
/** 
  \defgroup  NvMPCGetConstantDuplicatedRootDataMacros  NvM Get Constant Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated by constance root data elements.
  \{
*/ 
#define NvM_GetPartitionIdentifiersOfPCConfig()                                                     NvM_PartitionIdentifiers  /**< the pointer to NvM_PartitionIdentifiers */
#define NvM_GetSizeOfPartitionIdentifiersOfPCConfig()                                               1u  /**< the number of accomplishable value elements in NvM_PartitionIdentifiers */
#define NvM_GetBackgroundCrcRecalcFsmLib_InstanceOfPCPartitionConfig(partitionIndex)                (&(NvM_BackgroundCrcRecalcFsmLib_Instance))  /**< the pointer to NvM_BackgroundCrcRecalcFsmLib_Instance */
#define NvM_GetBackgroundCrcRecalcFsmLib_ProcessingStackElementOfPCPartitionConfig(partitionIndex)  NvM_BackgroundCrcRecalcFsmLib_ProcessingStackElement  /**< the pointer to NvM_BackgroundCrcRecalcFsmLib_ProcessingStackElement */
#define NvM_GetBackgroundCrcRecalcFsm_ContextOfPCPartitionConfig(partitionIndex)                    (&(NvM_BackgroundCrcRecalcFsm_Context))  /**< the pointer to NvM_BackgroundCrcRecalcFsm_Context */
#define NvM_GetBackgroundCrcRecalcFsm_InstanceOfPCPartitionConfig(partitionIndex)                   (&(NvM_BackgroundCrcRecalcFsm_Instance))  /**< the pointer to NvM_BackgroundCrcRecalcFsm_Instance */
#define NvM_GetBackgroundDataIntegrityService_InstanceOfPCPartitionConfig(partitionIndex)           (&(NvM_BackgroundDataIntegrityService_Instance))  /**< the pointer to NvM_BackgroundDataIntegrityService_Instance */
#define NvM_GetBlockDescriptorOfPCPartitionConfig()                                                 NvM_BlockDescriptor  /**< the pointer to NvM_BlockDescriptor */
#define NvM_GetBlockManagementInfo_DemAdminDataBlockOfPCPartitionConfig(partitionIndex)             (&(NvM_BlockManagementInfo_DemAdminDataBlock))  /**< the pointer to NvM_BlockManagementInfo_DemAdminDataBlock */
#define NvM_GetBlockManagementInfo_DemStatusDataBlockOfPCPartitionConfig(partitionIndex)            (&(NvM_BlockManagementInfo_DemStatusDataBlock))  /**< the pointer to NvM_BlockManagementInfo_DemStatusDataBlock */
#define NvM_GetBlockManagementInfo_NvMConfigBlockOfPCPartitionConfig(partitionIndex)                (&(NvM_BlockManagementInfo_NvMConfigBlock))  /**< the pointer to NvM_BlockManagementInfo_NvMConfigBlock */
#define NvM_GetBlockManagementInfo_NvMMultiBlockOfPCPartitionConfig(partitionIndex)                 (&(NvM_BlockManagementInfo_NvMMultiBlock))  /**< the pointer to NvM_BlockManagementInfo_NvMMultiBlock */
#define NvM_GetBlockManagementInfo_WDFC_ID_AP_CONNEXOfPCPartitionConfig(partitionIndex)             (&(NvM_BlockManagementInfo_WDFC_ID_AP_CONNEX))  /**< the pointer to NvM_BlockManagementInfo_WDFC_ID_AP_CONNEX */
#define NvM_GetBlockManagementInfo_WDFC_ID_AP_PARAOfPCPartitionConfig(partitionIndex)               (&(NvM_BlockManagementInfo_WDFC_ID_AP_PARA))  /**< the pointer to NvM_BlockManagementInfo_WDFC_ID_AP_PARA */
#define NvM_GetBlockManagementInfo_WDFC_ID_BOOT_PARAOfPCPartitionConfig(partitionIndex)             (&(NvM_BlockManagementInfo_WDFC_ID_BOOT_PARA))  /**< the pointer to NvM_BlockManagementInfo_WDFC_ID_BOOT_PARA */
#define NvM_GetBlockManagementInfo_WDFC_ID_CCPOfPCPartitionConfig(partitionIndex)                   (&(NvM_BlockManagementInfo_WDFC_ID_CCP))  /**< the pointer to NvM_BlockManagementInfo_WDFC_ID_CCP */
#define NvM_GetBlockManagementInfo_WDFC_ID_DEBUG_DATAOfPCPartitionConfig(partitionIndex)            (&(NvM_BlockManagementInfo_WDFC_ID_DEBUG_DATA))  /**< the pointer to NvM_BlockManagementInfo_WDFC_ID_DEBUG_DATA */
#define NvM_GetBlockManagementInfo_WDFC_ID_DLCOfPCPartitionConfig(partitionIndex)                   (&(NvM_BlockManagementInfo_WDFC_ID_DLC))  /**< the pointer to NvM_BlockManagementInfo_WDFC_ID_DLC */
#define NvM_GetBlockManagementInfo_WDFC_ID_DTCTimeOfPCPartitionConfig(partitionIndex)               (&(NvM_BlockManagementInfo_WDFC_ID_DTCTime))  /**< the pointer to NvM_BlockManagementInfo_WDFC_ID_DTCTime */
#define NvM_GetBlockManagementInfo_WDFC_ID_ECUID_RDI_PROGRAMMING_INFOOfPCPartitionConfig(partitionIndex) (&(NvM_BlockManagementInfo_WDFC_ID_ECUID_RDI_PROGRAMMING_INFO))  /**< the pointer to NvM_BlockManagementInfo_WDFC_ID_ECUID_RDI_PROGRAMMING_INFO */
#define NvM_GetBlockManagementInfo_WDFC_ID_EOL_HW_VERSIONOfPCPartitionConfig(partitionIndex)        (&(NvM_BlockManagementInfo_WDFC_ID_EOL_HW_VERSION))  /**< the pointer to NvM_BlockManagementInfo_WDFC_ID_EOL_HW_VERSION */
#define NvM_GetBlockManagementInfo_WDFC_ID_EOL_INFOOfPCPartitionConfig(partitionIndex)              (&(NvM_BlockManagementInfo_WDFC_ID_EOL_INFO))  /**< the pointer to NvM_BlockManagementInfo_WDFC_ID_EOL_INFO */
#define NvM_GetBlockManagementInfo_WDFC_ID_EOL_PASSWORDOfPCPartitionConfig(partitionIndex)          (&(NvM_BlockManagementInfo_WDFC_ID_EOL_PASSWORD))  /**< the pointer to NvM_BlockManagementInfo_WDFC_ID_EOL_PASSWORD */
#define NvM_GetBlockManagementInfo_WDFC_ID_EOL_SWNUMBEROfPCPartitionConfig(partitionIndex)          (&(NvM_BlockManagementInfo_WDFC_ID_EOL_SWNUMBER))  /**< the pointer to NvM_BlockManagementInfo_WDFC_ID_EOL_SWNUMBER */
#define NvM_GetBlockManagementInfo_WDFC_ID_FAULT_CODEOfPCPartitionConfig(partitionIndex)            (&(NvM_BlockManagementInfo_WDFC_ID_FAULT_CODE))  /**< the pointer to NvM_BlockManagementInfo_WDFC_ID_FAULT_CODE */
#define NvM_GetBlockManagementInfo_WDFC_ID_HANDLE_CFGOfPCPartitionConfig(partitionIndex)            (&(NvM_BlockManagementInfo_WDFC_ID_HANDLE_CFG))  /**< the pointer to NvM_BlockManagementInfo_WDFC_ID_HANDLE_CFG */
#define NvM_GetBlockManagementInfo_WDFC_ID_IDENT_BANKOfPCPartitionConfig(partitionIndex)            (&(NvM_BlockManagementInfo_WDFC_ID_IDENT_BANK))  /**< the pointer to NvM_BlockManagementInfo_WDFC_ID_IDENT_BANK */
#define NvM_GetBlockManagementInfo_WDFC_ID_IDOPTION_SECURITYOfPCPartitionConfig(partitionIndex)     (&(NvM_BlockManagementInfo_WDFC_ID_IDOPTION_SECURITY))  /**< the pointer to NvM_BlockManagementInfo_WDFC_ID_IDOPTION_SECURITY */
#define NvM_GetBlockManagementInfo_WDFC_ID_LAST_FDCOfPCPartitionConfig(partitionIndex)              (&(NvM_BlockManagementInfo_WDFC_ID_LAST_FDC))  /**< the pointer to NvM_BlockManagementInfo_WDFC_ID_LAST_FDC */
#define NvM_GetBlockManagementInfo_WDFC_ID_MAX_FDCOfPCPartitionConfig(partitionIndex)               (&(NvM_BlockManagementInfo_WDFC_ID_MAX_FDC))  /**< the pointer to NvM_BlockManagementInfo_WDFC_ID_MAX_FDC */
#define NvM_GetBlockManagementInfo_WDFC_ID_MIRROR_CFGOfPCPartitionConfig(partitionIndex)            (&(NvM_BlockManagementInfo_WDFC_ID_MIRROR_CFG))  /**< the pointer to NvM_BlockManagementInfo_WDFC_ID_MIRROR_CFG */
#define NvM_GetBlockManagementInfo_WDFC_ID_MIRROR_OTHER_1OfPCPartitionConfig(partitionIndex)        (&(NvM_BlockManagementInfo_WDFC_ID_MIRROR_OTHER_1))  /**< the pointer to NvM_BlockManagementInfo_WDFC_ID_MIRROR_OTHER_1 */
#define NvM_GetBlockManagementInfo_WDFC_ID_MIRROR_POS_RECOfPCPartitionConfig(partitionIndex)        (&(NvM_BlockManagementInfo_WDFC_ID_MIRROR_POS_REC))  /**< the pointer to NvM_BlockManagementInfo_WDFC_ID_MIRROR_POS_REC */
#define NvM_GetBlockManagementInfo_WDFC_ID_MIRROR_STOfPCPartitionConfig(partitionIndex)             (&(NvM_BlockManagementInfo_WDFC_ID_MIRROR_ST))  /**< the pointer to NvM_BlockManagementInfo_WDFC_ID_MIRROR_ST */
#define NvM_GetBlockManagementInfo_WDFC_ID_PART_NUMBER_GEELYOfPCPartitionConfig(partitionIndex)     (&(NvM_BlockManagementInfo_WDFC_ID_PART_NUMBER_GEELY))  /**< the pointer to NvM_BlockManagementInfo_WDFC_ID_PART_NUMBER_GEELY */
#define NvM_GetBlockManagementInfo_WDFC_ID_PMMOfPCPartitionConfig(partitionIndex)                   (&(NvM_BlockManagementInfo_WDFC_ID_PMM))  /**< the pointer to NvM_BlockManagementInfo_WDFC_ID_PMM */
#define NvM_GetBlockManagementInfo_WDFC_ID_QCM_FAULT_DATAOfPCPartitionConfig(partitionIndex)        (&(NvM_BlockManagementInfo_WDFC_ID_QCM_FAULT_DATA))  /**< the pointer to NvM_BlockManagementInfo_WDFC_ID_QCM_FAULT_DATA */
#define NvM_GetBlockManagementInfo_WDFC_ID_SECURITY_ACCESSOfPCPartitionConfig(partitionIndex)       (&(NvM_BlockManagementInfo_WDFC_ID_SECURITY_ACCESS))  /**< the pointer to NvM_BlockManagementInfo_WDFC_ID_SECURITY_ACCESS */
#define NvM_GetBlockManagementInfo_WDFC_ID_SR_PROFILEOfPCPartitionConfig(partitionIndex)            (&(NvM_BlockManagementInfo_WDFC_ID_SR_PROFILE))  /**< the pointer to NvM_BlockManagementInfo_WDFC_ID_SR_PROFILE */
#define NvM_GetBlockManagementInfo_WDFC_ID_SWP1OfPCPartitionConfig(partitionIndex)                  (&(NvM_BlockManagementInfo_WDFC_ID_SWP1))  /**< the pointer to NvM_BlockManagementInfo_WDFC_ID_SWP1 */
#define NvM_GetBlockManagementInfo_WDFC_ID_THPAOfPCPartitionConfig(partitionIndex)                  (&(NvM_BlockManagementInfo_WDFC_ID_THPA))  /**< the pointer to NvM_BlockManagementInfo_WDFC_ID_THPA */
#define NvM_GetBlockManagementInfo_WDFC_ID_VEH_CFGOfPCPartitionConfig(partitionIndex)               (&(NvM_BlockManagementInfo_WDFC_ID_VEH_CFG))  /**< the pointer to NvM_BlockManagementInfo_WDFC_ID_VEH_CFG */
#define NvM_GetBlockManagementInfo_WDFC_ID_VOL_POWER_MODE_CFGOfPCPartitionConfig(partitionIndex)    (&(NvM_BlockManagementInfo_WDFC_ID_VOL_POWER_MODE_CFG))  /**< the pointer to NvM_BlockManagementInfo_WDFC_ID_VOL_POWER_MODE_CFG */
#define NvM_GetBlockManagementInfo_WDFC_ID_WLC_AP_LEARNOfPCPartitionConfig(partitionIndex)          (&(NvM_BlockManagementInfo_WDFC_ID_WLC_AP_LEARN))  /**< the pointer to NvM_BlockManagementInfo_WDFC_ID_WLC_AP_LEARN */
#define NvM_GetBlockManagementInfo_WDFC_ID_WL_INFOOfPCPartitionConfig(partitionIndex)               (&(NvM_BlockManagementInfo_WDFC_ID_WL_INFO))  /**< the pointer to NvM_BlockManagementInfo_WDFC_ID_WL_INFO */
#define NvM_GetBlockManagementInfo_WDFC_ID_WL_LOGOfPCPartitionConfig(partitionIndex)                (&(NvM_BlockManagementInfo_WDFC_ID_WL_LOG))  /**< the pointer to NvM_BlockManagementInfo_WDFC_ID_WL_LOG */
#define NvM_GetCrcCompMechanismBuffer_DemAdminDataBlockOfPCPartitionConfig(partitionIndex)          NvM_CrcCompMechanismBuffer_DemAdminDataBlock  /**< the pointer to NvM_CrcCompMechanismBuffer_DemAdminDataBlock */
#define NvM_GetCrcCompMechanismBuffer_DemStatusDataBlockOfPCPartitionConfig(partitionIndex)         NvM_CrcCompMechanismBuffer_DemStatusDataBlock  /**< the pointer to NvM_CrcCompMechanismBuffer_DemStatusDataBlock */
#define NvM_GetCrcCompMechanismBuffer_NvMConfigBlockOfPCPartitionConfig(partitionIndex)             NvM_CrcCompMechanismBuffer_NvMConfigBlock  /**< the pointer to NvM_CrcCompMechanismBuffer_NvMConfigBlock */
#define NvM_GetCrcCompMechanismBuffer_WDFC_ID_AP_CONNEXOfPCPartitionConfig(partitionIndex)          NvM_CrcCompMechanismBuffer_WDFC_ID_AP_CONNEX  /**< the pointer to NvM_CrcCompMechanismBuffer_WDFC_ID_AP_CONNEX */
#define NvM_GetCrcCompMechanismBuffer_WDFC_ID_AP_PARAOfPCPartitionConfig(partitionIndex)            NvM_CrcCompMechanismBuffer_WDFC_ID_AP_PARA  /**< the pointer to NvM_CrcCompMechanismBuffer_WDFC_ID_AP_PARA */
#define NvM_GetCrcCompMechanismBuffer_WDFC_ID_BOOT_PARAOfPCPartitionConfig(partitionIndex)          NvM_CrcCompMechanismBuffer_WDFC_ID_BOOT_PARA  /**< the pointer to NvM_CrcCompMechanismBuffer_WDFC_ID_BOOT_PARA */
#define NvM_GetCrcCompMechanismBuffer_WDFC_ID_CCPOfPCPartitionConfig(partitionIndex)                NvM_CrcCompMechanismBuffer_WDFC_ID_CCP  /**< the pointer to NvM_CrcCompMechanismBuffer_WDFC_ID_CCP */
#define NvM_GetCrcCompMechanismBuffer_WDFC_ID_DEBUG_DATAOfPCPartitionConfig(partitionIndex)         NvM_CrcCompMechanismBuffer_WDFC_ID_DEBUG_DATA  /**< the pointer to NvM_CrcCompMechanismBuffer_WDFC_ID_DEBUG_DATA */
#define NvM_GetCrcCompMechanismBuffer_WDFC_ID_DLCOfPCPartitionConfig(partitionIndex)                NvM_CrcCompMechanismBuffer_WDFC_ID_DLC  /**< the pointer to NvM_CrcCompMechanismBuffer_WDFC_ID_DLC */
#define NvM_GetCrcCompMechanismBuffer_WDFC_ID_DTCTimeOfPCPartitionConfig(partitionIndex)            NvM_CrcCompMechanismBuffer_WDFC_ID_DTCTime  /**< the pointer to NvM_CrcCompMechanismBuffer_WDFC_ID_DTCTime */
#define NvM_GetCrcCompMechanismBuffer_WDFC_ID_ECUID_RDI_PROGRAMMING_INFOOfPCPartitionConfig(partitionIndex) NvM_CrcCompMechanismBuffer_WDFC_ID_ECUID_RDI_PROGRAMMING_INFO  /**< the pointer to NvM_CrcCompMechanismBuffer_WDFC_ID_ECUID_RDI_PROGRAMMING_INFO */
#define NvM_GetCrcCompMechanismBuffer_WDFC_ID_EOL_HW_VERSIONOfPCPartitionConfig(partitionIndex)     NvM_CrcCompMechanismBuffer_WDFC_ID_EOL_HW_VERSION  /**< the pointer to NvM_CrcCompMechanismBuffer_WDFC_ID_EOL_HW_VERSION */
#define NvM_GetCrcCompMechanismBuffer_WDFC_ID_EOL_INFOOfPCPartitionConfig(partitionIndex)           NvM_CrcCompMechanismBuffer_WDFC_ID_EOL_INFO  /**< the pointer to NvM_CrcCompMechanismBuffer_WDFC_ID_EOL_INFO */
#define NvM_GetCrcCompMechanismBuffer_WDFC_ID_EOL_PASSWORDOfPCPartitionConfig(partitionIndex)       NvM_CrcCompMechanismBuffer_WDFC_ID_EOL_PASSWORD  /**< the pointer to NvM_CrcCompMechanismBuffer_WDFC_ID_EOL_PASSWORD */
#define NvM_GetCrcCompMechanismBuffer_WDFC_ID_EOL_SWNUMBEROfPCPartitionConfig(partitionIndex)       NvM_CrcCompMechanismBuffer_WDFC_ID_EOL_SWNUMBER  /**< the pointer to NvM_CrcCompMechanismBuffer_WDFC_ID_EOL_SWNUMBER */
#define NvM_GetCrcCompMechanismBuffer_WDFC_ID_FAULT_CODEOfPCPartitionConfig(partitionIndex)         NvM_CrcCompMechanismBuffer_WDFC_ID_FAULT_CODE  /**< the pointer to NvM_CrcCompMechanismBuffer_WDFC_ID_FAULT_CODE */
#define NvM_GetCrcCompMechanismBuffer_WDFC_ID_HANDLE_CFGOfPCPartitionConfig(partitionIndex)         NvM_CrcCompMechanismBuffer_WDFC_ID_HANDLE_CFG  /**< the pointer to NvM_CrcCompMechanismBuffer_WDFC_ID_HANDLE_CFG */
#define NvM_GetCrcCompMechanismBuffer_WDFC_ID_IDENT_BANKOfPCPartitionConfig(partitionIndex)         NvM_CrcCompMechanismBuffer_WDFC_ID_IDENT_BANK  /**< the pointer to NvM_CrcCompMechanismBuffer_WDFC_ID_IDENT_BANK */
#define NvM_GetCrcCompMechanismBuffer_WDFC_ID_IDOPTION_SECURITYOfPCPartitionConfig(partitionIndex)  NvM_CrcCompMechanismBuffer_WDFC_ID_IDOPTION_SECURITY  /**< the pointer to NvM_CrcCompMechanismBuffer_WDFC_ID_IDOPTION_SECURITY */
#define NvM_GetCrcCompMechanismBuffer_WDFC_ID_LAST_FDCOfPCPartitionConfig(partitionIndex)           NvM_CrcCompMechanismBuffer_WDFC_ID_LAST_FDC  /**< the pointer to NvM_CrcCompMechanismBuffer_WDFC_ID_LAST_FDC */
#define NvM_GetCrcCompMechanismBuffer_WDFC_ID_MAX_FDCOfPCPartitionConfig(partitionIndex)            NvM_CrcCompMechanismBuffer_WDFC_ID_MAX_FDC  /**< the pointer to NvM_CrcCompMechanismBuffer_WDFC_ID_MAX_FDC */
#define NvM_GetCrcCompMechanismBuffer_WDFC_ID_MIRROR_CFGOfPCPartitionConfig(partitionIndex)         NvM_CrcCompMechanismBuffer_WDFC_ID_MIRROR_CFG  /**< the pointer to NvM_CrcCompMechanismBuffer_WDFC_ID_MIRROR_CFG */
#define NvM_GetCrcCompMechanismBuffer_WDFC_ID_MIRROR_OTHER_1OfPCPartitionConfig(partitionIndex)     NvM_CrcCompMechanismBuffer_WDFC_ID_MIRROR_OTHER_1  /**< the pointer to NvM_CrcCompMechanismBuffer_WDFC_ID_MIRROR_OTHER_1 */
#define NvM_GetCrcCompMechanismBuffer_WDFC_ID_MIRROR_POS_RECOfPCPartitionConfig(partitionIndex)     NvM_CrcCompMechanismBuffer_WDFC_ID_MIRROR_POS_REC  /**< the pointer to NvM_CrcCompMechanismBuffer_WDFC_ID_MIRROR_POS_REC */
#define NvM_GetCrcCompMechanismBuffer_WDFC_ID_MIRROR_STOfPCPartitionConfig(partitionIndex)          NvM_CrcCompMechanismBuffer_WDFC_ID_MIRROR_ST  /**< the pointer to NvM_CrcCompMechanismBuffer_WDFC_ID_MIRROR_ST */
#define NvM_GetCrcCompMechanismBuffer_WDFC_ID_PART_NUMBER_GEELYOfPCPartitionConfig(partitionIndex)  NvM_CrcCompMechanismBuffer_WDFC_ID_PART_NUMBER_GEELY  /**< the pointer to NvM_CrcCompMechanismBuffer_WDFC_ID_PART_NUMBER_GEELY */
#define NvM_GetCrcCompMechanismBuffer_WDFC_ID_PMMOfPCPartitionConfig(partitionIndex)                NvM_CrcCompMechanismBuffer_WDFC_ID_PMM  /**< the pointer to NvM_CrcCompMechanismBuffer_WDFC_ID_PMM */
#define NvM_GetCrcCompMechanismBuffer_WDFC_ID_QCM_FAULT_DATAOfPCPartitionConfig(partitionIndex)     NvM_CrcCompMechanismBuffer_WDFC_ID_QCM_FAULT_DATA  /**< the pointer to NvM_CrcCompMechanismBuffer_WDFC_ID_QCM_FAULT_DATA */
#define NvM_GetCrcCompMechanismBuffer_WDFC_ID_SECURITY_ACCESSOfPCPartitionConfig(partitionIndex)    NvM_CrcCompMechanismBuffer_WDFC_ID_SECURITY_ACCESS  /**< the pointer to NvM_CrcCompMechanismBuffer_WDFC_ID_SECURITY_ACCESS */
#define NvM_GetCrcCompMechanismBuffer_WDFC_ID_SR_PROFILEOfPCPartitionConfig(partitionIndex)         NvM_CrcCompMechanismBuffer_WDFC_ID_SR_PROFILE  /**< the pointer to NvM_CrcCompMechanismBuffer_WDFC_ID_SR_PROFILE */
#define NvM_GetCrcCompMechanismBuffer_WDFC_ID_SWP1OfPCPartitionConfig(partitionIndex)               NvM_CrcCompMechanismBuffer_WDFC_ID_SWP1  /**< the pointer to NvM_CrcCompMechanismBuffer_WDFC_ID_SWP1 */
#define NvM_GetCrcCompMechanismBuffer_WDFC_ID_THPAOfPCPartitionConfig(partitionIndex)               NvM_CrcCompMechanismBuffer_WDFC_ID_THPA  /**< the pointer to NvM_CrcCompMechanismBuffer_WDFC_ID_THPA */
#define NvM_GetCrcCompMechanismBuffer_WDFC_ID_VEH_CFGOfPCPartitionConfig(partitionIndex)            NvM_CrcCompMechanismBuffer_WDFC_ID_VEH_CFG  /**< the pointer to NvM_CrcCompMechanismBuffer_WDFC_ID_VEH_CFG */
#define NvM_GetCrcCompMechanismBuffer_WDFC_ID_VOL_POWER_MODE_CFGOfPCPartitionConfig(partitionIndex) NvM_CrcCompMechanismBuffer_WDFC_ID_VOL_POWER_MODE_CFG  /**< the pointer to NvM_CrcCompMechanismBuffer_WDFC_ID_VOL_POWER_MODE_CFG */
#define NvM_GetCrcCompMechanismBuffer_WDFC_ID_WLC_AP_LEARNOfPCPartitionConfig(partitionIndex)       NvM_CrcCompMechanismBuffer_WDFC_ID_WLC_AP_LEARN  /**< the pointer to NvM_CrcCompMechanismBuffer_WDFC_ID_WLC_AP_LEARN */
#define NvM_GetCrcCompMechanismBuffer_WDFC_ID_WL_INFOOfPCPartitionConfig(partitionIndex)            NvM_CrcCompMechanismBuffer_WDFC_ID_WL_INFO  /**< the pointer to NvM_CrcCompMechanismBuffer_WDFC_ID_WL_INFO */
#define NvM_GetCrcCompMechanismBuffer_WDFC_ID_WL_LOGOfPCPartitionConfig(partitionIndex)             NvM_CrcCompMechanismBuffer_WDFC_ID_WL_LOG  /**< the pointer to NvM_CrcCompMechanismBuffer_WDFC_ID_WL_LOG */
#define NvM_GetDataIntegrityFsm_InstanceOfPCPartitionConfig(partitionIndex)                         (&(NvM_DataIntegrityFsm_Instance))  /**< the pointer to NvM_DataIntegrityFsm_Instance */
#define NvM_GetDataIntegrityIntBuffer_DemAdminDataBlockOfPCPartitionConfig(partitionIndex)          NvM_DataIntegrityIntBuffer_DemAdminDataBlock  /**< the pointer to NvM_DataIntegrityIntBuffer_DemAdminDataBlock */
#define NvM_GetDataIntegrityIntBuffer_DemStatusDataBlockOfPCPartitionConfig(partitionIndex)         NvM_DataIntegrityIntBuffer_DemStatusDataBlock  /**< the pointer to NvM_DataIntegrityIntBuffer_DemStatusDataBlock */
#define NvM_GetDataIntegrityIntBuffer_WDFC_ID_AP_CONNEXOfPCPartitionConfig(partitionIndex)          NvM_DataIntegrityIntBuffer_WDFC_ID_AP_CONNEX  /**< the pointer to NvM_DataIntegrityIntBuffer_WDFC_ID_AP_CONNEX */
#define NvM_GetDataIntegrityIntBuffer_WDFC_ID_AP_PARAOfPCPartitionConfig(partitionIndex)            NvM_DataIntegrityIntBuffer_WDFC_ID_AP_PARA  /**< the pointer to NvM_DataIntegrityIntBuffer_WDFC_ID_AP_PARA */
#define NvM_GetDataIntegrityIntBuffer_WDFC_ID_BOOT_PARAOfPCPartitionConfig(partitionIndex)          NvM_DataIntegrityIntBuffer_WDFC_ID_BOOT_PARA  /**< the pointer to NvM_DataIntegrityIntBuffer_WDFC_ID_BOOT_PARA */
#define NvM_GetDataIntegrityIntBuffer_WDFC_ID_CCPOfPCPartitionConfig(partitionIndex)                NvM_DataIntegrityIntBuffer_WDFC_ID_CCP  /**< the pointer to NvM_DataIntegrityIntBuffer_WDFC_ID_CCP */
#define NvM_GetDataIntegrityIntBuffer_WDFC_ID_DEBUG_DATAOfPCPartitionConfig(partitionIndex)         NvM_DataIntegrityIntBuffer_WDFC_ID_DEBUG_DATA  /**< the pointer to NvM_DataIntegrityIntBuffer_WDFC_ID_DEBUG_DATA */
#define NvM_GetDataIntegrityIntBuffer_WDFC_ID_DLCOfPCPartitionConfig(partitionIndex)                NvM_DataIntegrityIntBuffer_WDFC_ID_DLC  /**< the pointer to NvM_DataIntegrityIntBuffer_WDFC_ID_DLC */
#define NvM_GetDataIntegrityIntBuffer_WDFC_ID_DTCTimeOfPCPartitionConfig(partitionIndex)            NvM_DataIntegrityIntBuffer_WDFC_ID_DTCTime  /**< the pointer to NvM_DataIntegrityIntBuffer_WDFC_ID_DTCTime */
#define NvM_GetDataIntegrityIntBuffer_WDFC_ID_ECUID_RDI_PROGRAMMING_INFOOfPCPartitionConfig(partitionIndex) NvM_DataIntegrityIntBuffer_WDFC_ID_ECUID_RDI_PROGRAMMING_INFO  /**< the pointer to NvM_DataIntegrityIntBuffer_WDFC_ID_ECUID_RDI_PROGRAMMING_INFO */
#define NvM_GetDataIntegrityIntBuffer_WDFC_ID_EOL_HW_VERSIONOfPCPartitionConfig(partitionIndex)     NvM_DataIntegrityIntBuffer_WDFC_ID_EOL_HW_VERSION  /**< the pointer to NvM_DataIntegrityIntBuffer_WDFC_ID_EOL_HW_VERSION */
#define NvM_GetDataIntegrityIntBuffer_WDFC_ID_EOL_INFOOfPCPartitionConfig(partitionIndex)           NvM_DataIntegrityIntBuffer_WDFC_ID_EOL_INFO  /**< the pointer to NvM_DataIntegrityIntBuffer_WDFC_ID_EOL_INFO */
#define NvM_GetDataIntegrityIntBuffer_WDFC_ID_EOL_PASSWORDOfPCPartitionConfig(partitionIndex)       NvM_DataIntegrityIntBuffer_WDFC_ID_EOL_PASSWORD  /**< the pointer to NvM_DataIntegrityIntBuffer_WDFC_ID_EOL_PASSWORD */
#define NvM_GetDataIntegrityIntBuffer_WDFC_ID_EOL_SWNUMBEROfPCPartitionConfig(partitionIndex)       NvM_DataIntegrityIntBuffer_WDFC_ID_EOL_SWNUMBER  /**< the pointer to NvM_DataIntegrityIntBuffer_WDFC_ID_EOL_SWNUMBER */
#define NvM_GetDataIntegrityIntBuffer_WDFC_ID_FAULT_CODEOfPCPartitionConfig(partitionIndex)         NvM_DataIntegrityIntBuffer_WDFC_ID_FAULT_CODE  /**< the pointer to NvM_DataIntegrityIntBuffer_WDFC_ID_FAULT_CODE */
#define NvM_GetDataIntegrityIntBuffer_WDFC_ID_HANDLE_CFGOfPCPartitionConfig(partitionIndex)         NvM_DataIntegrityIntBuffer_WDFC_ID_HANDLE_CFG  /**< the pointer to NvM_DataIntegrityIntBuffer_WDFC_ID_HANDLE_CFG */
#define NvM_GetDataIntegrityIntBuffer_WDFC_ID_IDENT_BANKOfPCPartitionConfig(partitionIndex)         NvM_DataIntegrityIntBuffer_WDFC_ID_IDENT_BANK  /**< the pointer to NvM_DataIntegrityIntBuffer_WDFC_ID_IDENT_BANK */
#define NvM_GetDataIntegrityIntBuffer_WDFC_ID_IDOPTION_SECURITYOfPCPartitionConfig(partitionIndex)  NvM_DataIntegrityIntBuffer_WDFC_ID_IDOPTION_SECURITY  /**< the pointer to NvM_DataIntegrityIntBuffer_WDFC_ID_IDOPTION_SECURITY */
#define NvM_GetDataIntegrityIntBuffer_WDFC_ID_LAST_FDCOfPCPartitionConfig(partitionIndex)           NvM_DataIntegrityIntBuffer_WDFC_ID_LAST_FDC  /**< the pointer to NvM_DataIntegrityIntBuffer_WDFC_ID_LAST_FDC */
#define NvM_GetDataIntegrityIntBuffer_WDFC_ID_MAX_FDCOfPCPartitionConfig(partitionIndex)            NvM_DataIntegrityIntBuffer_WDFC_ID_MAX_FDC  /**< the pointer to NvM_DataIntegrityIntBuffer_WDFC_ID_MAX_FDC */
#define NvM_GetDataIntegrityIntBuffer_WDFC_ID_MIRROR_CFGOfPCPartitionConfig(partitionIndex)         NvM_DataIntegrityIntBuffer_WDFC_ID_MIRROR_CFG  /**< the pointer to NvM_DataIntegrityIntBuffer_WDFC_ID_MIRROR_CFG */
#define NvM_GetDataIntegrityIntBuffer_WDFC_ID_MIRROR_OTHER_1OfPCPartitionConfig(partitionIndex)     NvM_DataIntegrityIntBuffer_WDFC_ID_MIRROR_OTHER_1  /**< the pointer to NvM_DataIntegrityIntBuffer_WDFC_ID_MIRROR_OTHER_1 */
#define NvM_GetDataIntegrityIntBuffer_WDFC_ID_MIRROR_POS_RECOfPCPartitionConfig(partitionIndex)     NvM_DataIntegrityIntBuffer_WDFC_ID_MIRROR_POS_REC  /**< the pointer to NvM_DataIntegrityIntBuffer_WDFC_ID_MIRROR_POS_REC */
#define NvM_GetDataIntegrityIntBuffer_WDFC_ID_MIRROR_STOfPCPartitionConfig(partitionIndex)          NvM_DataIntegrityIntBuffer_WDFC_ID_MIRROR_ST  /**< the pointer to NvM_DataIntegrityIntBuffer_WDFC_ID_MIRROR_ST */
#define NvM_GetDataIntegrityIntBuffer_WDFC_ID_PART_NUMBER_GEELYOfPCPartitionConfig(partitionIndex)  NvM_DataIntegrityIntBuffer_WDFC_ID_PART_NUMBER_GEELY  /**< the pointer to NvM_DataIntegrityIntBuffer_WDFC_ID_PART_NUMBER_GEELY */
#define NvM_GetDataIntegrityIntBuffer_WDFC_ID_PMMOfPCPartitionConfig(partitionIndex)                NvM_DataIntegrityIntBuffer_WDFC_ID_PMM  /**< the pointer to NvM_DataIntegrityIntBuffer_WDFC_ID_PMM */
#define NvM_GetDataIntegrityIntBuffer_WDFC_ID_QCM_FAULT_DATAOfPCPartitionConfig(partitionIndex)     NvM_DataIntegrityIntBuffer_WDFC_ID_QCM_FAULT_DATA  /**< the pointer to NvM_DataIntegrityIntBuffer_WDFC_ID_QCM_FAULT_DATA */
#define NvM_GetDataIntegrityIntBuffer_WDFC_ID_SECURITY_ACCESSOfPCPartitionConfig(partitionIndex)    NvM_DataIntegrityIntBuffer_WDFC_ID_SECURITY_ACCESS  /**< the pointer to NvM_DataIntegrityIntBuffer_WDFC_ID_SECURITY_ACCESS */
#define NvM_GetDataIntegrityIntBuffer_WDFC_ID_SR_PROFILEOfPCPartitionConfig(partitionIndex)         NvM_DataIntegrityIntBuffer_WDFC_ID_SR_PROFILE  /**< the pointer to NvM_DataIntegrityIntBuffer_WDFC_ID_SR_PROFILE */
#define NvM_GetDataIntegrityIntBuffer_WDFC_ID_SWP1OfPCPartitionConfig(partitionIndex)               NvM_DataIntegrityIntBuffer_WDFC_ID_SWP1  /**< the pointer to NvM_DataIntegrityIntBuffer_WDFC_ID_SWP1 */
#define NvM_GetDataIntegrityIntBuffer_WDFC_ID_THPAOfPCPartitionConfig(partitionIndex)               NvM_DataIntegrityIntBuffer_WDFC_ID_THPA  /**< the pointer to NvM_DataIntegrityIntBuffer_WDFC_ID_THPA */
#define NvM_GetDataIntegrityIntBuffer_WDFC_ID_VEH_CFGOfPCPartitionConfig(partitionIndex)            NvM_DataIntegrityIntBuffer_WDFC_ID_VEH_CFG  /**< the pointer to NvM_DataIntegrityIntBuffer_WDFC_ID_VEH_CFG */
#define NvM_GetDataIntegrityIntBuffer_WDFC_ID_VOL_POWER_MODE_CFGOfPCPartitionConfig(partitionIndex) NvM_DataIntegrityIntBuffer_WDFC_ID_VOL_POWER_MODE_CFG  /**< the pointer to NvM_DataIntegrityIntBuffer_WDFC_ID_VOL_POWER_MODE_CFG */
#define NvM_GetDataIntegrityIntBuffer_WDFC_ID_WLC_AP_LEARNOfPCPartitionConfig(partitionIndex)       NvM_DataIntegrityIntBuffer_WDFC_ID_WLC_AP_LEARN  /**< the pointer to NvM_DataIntegrityIntBuffer_WDFC_ID_WLC_AP_LEARN */
#define NvM_GetDataIntegrityIntBuffer_WDFC_ID_WL_INFOOfPCPartitionConfig(partitionIndex)            NvM_DataIntegrityIntBuffer_WDFC_ID_WL_INFO  /**< the pointer to NvM_DataIntegrityIntBuffer_WDFC_ID_WL_INFO */
#define NvM_GetDataIntegrityIntBuffer_WDFC_ID_WL_LOGOfPCPartitionConfig(partitionIndex)             NvM_DataIntegrityIntBuffer_WDFC_ID_WL_LOG  /**< the pointer to NvM_DataIntegrityIntBuffer_WDFC_ID_WL_LOG */
#define NvM_GetDataIntegrityRecalcQueue_InstanceOfPCPartitionConfig(partitionIndex)                 (&(NvM_DataIntegrityRecalcQueue_Instance))  /**< the pointer to NvM_DataIntegrityRecalcQueue_Instance */
#define NvM_GetDcmBlockManagementInfoOfPCPartitionConfig(partitionIndex)                            (&(NvM_DcmBlockManagementInfo))  /**< the pointer to NvM_DcmBlockManagementInfo */
#define NvM_GetForegroundDataIntegrityService_InstanceOfPCPartitionConfig(partitionIndex)           (&(NvM_ForegroundDataIntegrityService_Instance))  /**< the pointer to NvM_ForegroundDataIntegrityService_Instance */
#define NvM_GetInternalBufferOfPCPartitionConfig(partitionIndex)                                    NvM_InternalBuffer  /**< the pointer to NvM_InternalBuffer */
#define NvM_GetMultiBlockFsmLib_ProcessingStackElementOfPCPartitionConfig(partitionIndex)           NvM_MultiBlockFsmLib_ProcessingStackElement  /**< the pointer to NvM_MultiBlockFsmLib_ProcessingStackElement */
#define NvM_GetMultiBlockJobFsm_ContextOfPCPartitionConfig(partitionIndex)                          (&(NvM_MultiBlockJobFsm_Context))  /**< the pointer to NvM_MultiBlockJobFsm_Context */
#define NvM_GetMultiBlockJobFsm_InstanceOfPCPartitionConfig(partitionIndex)                         (&(NvM_MultiBlockJobFsm_Instance))  /**< the pointer to NvM_MultiBlockJobFsm_Instance */
#define NvM_GetMultiBlockJobInformationOfPCPartitionConfig(partitionIndex)                          (&(NvM_MultiBlockJobInformation))  /**< the pointer to NvM_MultiBlockJobInformation */
#define NvM_GetMultiBlockJobOfPCPartitionConfig(partitionIndex)                                     (&(NvM_MultiBlockJob))  /**< the pointer to NvM_MultiBlockJob */
#define NvM_GetMultiBlockProcessorFsmLib_InstanceOfPCPartitionConfig(partitionIndex)                (&(NvM_MultiBlockProcessorFsmLib_Instance))  /**< the pointer to NvM_MultiBlockProcessorFsmLib_Instance */
#define NvM_GetMultiBlockProcessorFsmLib_ProcessingStackElementOfPCPartitionConfig(partitionIndex)  NvM_MultiBlockProcessorFsmLib_ProcessingStackElement  /**< the pointer to NvM_MultiBlockProcessorFsmLib_ProcessingStackElement */
#define NvM_GetMultiBlockServiceFsmLib_InstanceOfPCPartitionConfig(partitionIndex)                  (&(NvM_MultiBlockServiceFsmLib_Instance))  /**< the pointer to NvM_MultiBlockServiceFsmLib_Instance */
#define NvM_GetNvJobContextOfPCPartitionConfig(partitionIndex)                                      (&(NvM_NvJobContext))  /**< the pointer to NvM_NvJobContext */
#define NvM_GetNvJobFsm_InstanceOfPCPartitionConfig(partitionIndex)                                 (&(NvM_NvJobFsm_Instance))  /**< the pointer to NvM_NvJobFsm_Instance */
#define NvM_GetNvServiceFsmLib_InstanceOfPCPartitionConfig(partitionIndex)                          (&(NvM_NvServiceFsmLib_Instance))  /**< the pointer to NvM_NvServiceFsmLib_Instance */
#define NvM_GetNvServiceFsmLib_ProcessingStackElementOfPCPartitionConfig(partitionIndex)            NvM_NvServiceFsmLib_ProcessingStackElement  /**< the pointer to NvM_NvServiceFsmLib_ProcessingStackElement */
#define NvM_GetNvServiceProcessorFsmLib_InstanceOfPCPartitionConfig(partitionIndex)                 (&(NvM_NvServiceProcessorFsmLib_Instance))  /**< the pointer to NvM_NvServiceProcessorFsmLib_Instance */
#define NvM_GetNvServiceProcessorFsmLib_ProcessingStackElementOfPCPartitionConfig(partitionIndex)   NvM_NvServiceProcessorFsmLib_ProcessingStackElement  /**< the pointer to NvM_NvServiceProcessorFsmLib_ProcessingStackElement */
#define NvM_GetQueueListOfPCPartitionConfig(partitionIndex)                                         NvM_QueueList  /**< the pointer to NvM_QueueList */
#define NvM_GetQueue_InstanceOfPCPartitionConfig(partitionIndex)                                    (&(NvM_Queue_Instance))  /**< the pointer to NvM_Queue_Instance */
#define NvM_GetReadAllFsm_ContextOfPCPartitionConfig(partitionIndex)                                (&(NvM_ReadAllFsm_Context))  /**< the pointer to NvM_ReadAllFsm_Context */
#define NvM_GetReadAllFsm_InstanceOfPCPartitionConfig(partitionIndex)                               (&(NvM_ReadAllFsm_Instance))  /**< the pointer to NvM_ReadAllFsm_Instance */
#define NvM_GetReadBlockFsm_ContextOfPCPartitionConfig(partitionIndex)                              (&(NvM_ReadBlockFsm_Context))  /**< the pointer to NvM_ReadBlockFsm_Context */
#define NvM_GetReadBlockFsm_InstanceOfPCPartitionConfig(partitionIndex)                             (&(NvM_ReadBlockFsm_Instance))  /**< the pointer to NvM_ReadBlockFsm_Instance */
#define NvM_GetServiceProcessorFsmLib_InstanceOfPCPartitionConfig(partitionIndex)                   (&(NvM_ServiceProcessorFsmLib_Instance))  /**< the pointer to NvM_ServiceProcessorFsmLib_Instance */
#define NvM_GetServiceProcessorFsmLib_ProcessingStackElementOfPCPartitionConfig(partitionIndex)     NvM_ServiceProcessorFsmLib_ProcessingStackElement  /**< the pointer to NvM_ServiceProcessorFsmLib_ProcessingStackElement */
#define NvM_GetServiceProcessorFsm_ContextOfPCPartitionConfig(partitionIndex)                       (&(NvM_ServiceProcessorFsm_Context))  /**< the pointer to NvM_ServiceProcessorFsm_Context */
#define NvM_GetServiceProcessorFsm_InstanceOfPCPartitionConfig(partitionIndex)                      (&(NvM_ServiceProcessorFsm_Instance))  /**< the pointer to NvM_ServiceProcessorFsm_Instance */
#define NvM_GetSingleBlockFsmLib_ProcessingStackElementOfPCPartitionConfig(partitionIndex)          NvM_SingleBlockFsmLib_ProcessingStackElement  /**< the pointer to NvM_SingleBlockFsmLib_ProcessingStackElement */
#define NvM_GetSingleBlockJobContextOfPCPartitionConfig(partitionIndex)                             (&(NvM_SingleBlockJobContext))  /**< the pointer to NvM_SingleBlockJobContext */
#define NvM_GetSingleBlockJobFsm_InstanceOfPCPartitionConfig(partitionIndex)                        (&(NvM_SingleBlockJobFsm_Instance))  /**< the pointer to NvM_SingleBlockJobFsm_Instance */
#define NvM_GetSingleBlockServiceFsmLib_InstanceOfPCPartitionConfig(partitionIndex)                 (&(NvM_SingleBlockServiceFsmLib_Instance))  /**< the pointer to NvM_SingleBlockServiceFsmLib_Instance */
#define NvM_GetSizeOfBackgroundCrcRecalcFsmLib_ProcessingStackElementOfPCPartitionConfig(partitionIndex) 1u  /**< the number of accomplishable value elements in NvM_BackgroundCrcRecalcFsmLib_ProcessingStackElement */
#define NvM_GetSizeOfBlockDescriptorOfPCPartitionConfig()                                           37u  /**< the number of accomplishable value elements in NvM_BlockDescriptor */
#define NvM_GetSizeOfCrcCompMechanismBuffer_DemAdminDataBlockOfPCPartitionConfig(partitionIndex)    2u  /**< the number of accomplishable value elements in NvM_CrcCompMechanismBuffer_DemAdminDataBlock */
#define NvM_GetSizeOfCrcCompMechanismBuffer_DemStatusDataBlockOfPCPartitionConfig(partitionIndex)   2u  /**< the number of accomplishable value elements in NvM_CrcCompMechanismBuffer_DemStatusDataBlock */
#define NvM_GetSizeOfCrcCompMechanismBuffer_NvMConfigBlockOfPCPartitionConfig(partitionIndex)       2u  /**< the number of accomplishable value elements in NvM_CrcCompMechanismBuffer_NvMConfigBlock */
#define NvM_GetSizeOfCrcCompMechanismBuffer_WDFC_ID_AP_CONNEXOfPCPartitionConfig(partitionIndex)    2u  /**< the number of accomplishable value elements in NvM_CrcCompMechanismBuffer_WDFC_ID_AP_CONNEX */
#define NvM_GetSizeOfCrcCompMechanismBuffer_WDFC_ID_AP_PARAOfPCPartitionConfig(partitionIndex)      2u  /**< the number of accomplishable value elements in NvM_CrcCompMechanismBuffer_WDFC_ID_AP_PARA */
#define NvM_GetSizeOfCrcCompMechanismBuffer_WDFC_ID_BOOT_PARAOfPCPartitionConfig(partitionIndex)    2u  /**< the number of accomplishable value elements in NvM_CrcCompMechanismBuffer_WDFC_ID_BOOT_PARA */
#define NvM_GetSizeOfCrcCompMechanismBuffer_WDFC_ID_CCPOfPCPartitionConfig(partitionIndex)          2u  /**< the number of accomplishable value elements in NvM_CrcCompMechanismBuffer_WDFC_ID_CCP */
#define NvM_GetSizeOfCrcCompMechanismBuffer_WDFC_ID_DEBUG_DATAOfPCPartitionConfig(partitionIndex)   2u  /**< the number of accomplishable value elements in NvM_CrcCompMechanismBuffer_WDFC_ID_DEBUG_DATA */
#define NvM_GetSizeOfCrcCompMechanismBuffer_WDFC_ID_DLCOfPCPartitionConfig(partitionIndex)          2u  /**< the number of accomplishable value elements in NvM_CrcCompMechanismBuffer_WDFC_ID_DLC */
#define NvM_GetSizeOfCrcCompMechanismBuffer_WDFC_ID_DTCTimeOfPCPartitionConfig(partitionIndex)      2u  /**< the number of accomplishable value elements in NvM_CrcCompMechanismBuffer_WDFC_ID_DTCTime */
#define NvM_GetSizeOfCrcCompMechanismBuffer_WDFC_ID_ECUID_RDI_PROGRAMMING_INFOOfPCPartitionConfig(partitionIndex) 2u  /**< the number of accomplishable value elements in NvM_CrcCompMechanismBuffer_WDFC_ID_ECUID_RDI_PROGRAMMING_INFO */
#define NvM_GetSizeOfCrcCompMechanismBuffer_WDFC_ID_EOL_HW_VERSIONOfPCPartitionConfig(partitionIndex) 2u  /**< the number of accomplishable value elements in NvM_CrcCompMechanismBuffer_WDFC_ID_EOL_HW_VERSION */
#define NvM_GetSizeOfCrcCompMechanismBuffer_WDFC_ID_EOL_INFOOfPCPartitionConfig(partitionIndex)     2u  /**< the number of accomplishable value elements in NvM_CrcCompMechanismBuffer_WDFC_ID_EOL_INFO */
#define NvM_GetSizeOfCrcCompMechanismBuffer_WDFC_ID_EOL_PASSWORDOfPCPartitionConfig(partitionIndex) 2u  /**< the number of accomplishable value elements in NvM_CrcCompMechanismBuffer_WDFC_ID_EOL_PASSWORD */
#define NvM_GetSizeOfCrcCompMechanismBuffer_WDFC_ID_EOL_SWNUMBEROfPCPartitionConfig(partitionIndex) 2u  /**< the number of accomplishable value elements in NvM_CrcCompMechanismBuffer_WDFC_ID_EOL_SWNUMBER */
#define NvM_GetSizeOfCrcCompMechanismBuffer_WDFC_ID_FAULT_CODEOfPCPartitionConfig(partitionIndex)   2u  /**< the number of accomplishable value elements in NvM_CrcCompMechanismBuffer_WDFC_ID_FAULT_CODE */
#define NvM_GetSizeOfCrcCompMechanismBuffer_WDFC_ID_HANDLE_CFGOfPCPartitionConfig(partitionIndex)   2u  /**< the number of accomplishable value elements in NvM_CrcCompMechanismBuffer_WDFC_ID_HANDLE_CFG */
#define NvM_GetSizeOfCrcCompMechanismBuffer_WDFC_ID_IDENT_BANKOfPCPartitionConfig(partitionIndex)   2u  /**< the number of accomplishable value elements in NvM_CrcCompMechanismBuffer_WDFC_ID_IDENT_BANK */
#define NvM_GetSizeOfCrcCompMechanismBuffer_WDFC_ID_IDOPTION_SECURITYOfPCPartitionConfig(partitionIndex) 2u  /**< the number of accomplishable value elements in NvM_CrcCompMechanismBuffer_WDFC_ID_IDOPTION_SECURITY */
#define NvM_GetSizeOfCrcCompMechanismBuffer_WDFC_ID_LAST_FDCOfPCPartitionConfig(partitionIndex)     2u  /**< the number of accomplishable value elements in NvM_CrcCompMechanismBuffer_WDFC_ID_LAST_FDC */
#define NvM_GetSizeOfCrcCompMechanismBuffer_WDFC_ID_MAX_FDCOfPCPartitionConfig(partitionIndex)      2u  /**< the number of accomplishable value elements in NvM_CrcCompMechanismBuffer_WDFC_ID_MAX_FDC */
#define NvM_GetSizeOfCrcCompMechanismBuffer_WDFC_ID_MIRROR_CFGOfPCPartitionConfig(partitionIndex)   2u  /**< the number of accomplishable value elements in NvM_CrcCompMechanismBuffer_WDFC_ID_MIRROR_CFG */
#define NvM_GetSizeOfCrcCompMechanismBuffer_WDFC_ID_MIRROR_OTHER_1OfPCPartitionConfig(partitionIndex) 2u  /**< the number of accomplishable value elements in NvM_CrcCompMechanismBuffer_WDFC_ID_MIRROR_OTHER_1 */
#define NvM_GetSizeOfCrcCompMechanismBuffer_WDFC_ID_MIRROR_POS_RECOfPCPartitionConfig(partitionIndex) 2u  /**< the number of accomplishable value elements in NvM_CrcCompMechanismBuffer_WDFC_ID_MIRROR_POS_REC */
#define NvM_GetSizeOfCrcCompMechanismBuffer_WDFC_ID_MIRROR_STOfPCPartitionConfig(partitionIndex)    2u  /**< the number of accomplishable value elements in NvM_CrcCompMechanismBuffer_WDFC_ID_MIRROR_ST */
#define NvM_GetSizeOfCrcCompMechanismBuffer_WDFC_ID_PART_NUMBER_GEELYOfPCPartitionConfig(partitionIndex) 2u  /**< the number of accomplishable value elements in NvM_CrcCompMechanismBuffer_WDFC_ID_PART_NUMBER_GEELY */
#define NvM_GetSizeOfCrcCompMechanismBuffer_WDFC_ID_PMMOfPCPartitionConfig(partitionIndex)          2u  /**< the number of accomplishable value elements in NvM_CrcCompMechanismBuffer_WDFC_ID_PMM */
#define NvM_GetSizeOfCrcCompMechanismBuffer_WDFC_ID_QCM_FAULT_DATAOfPCPartitionConfig(partitionIndex) 2u  /**< the number of accomplishable value elements in NvM_CrcCompMechanismBuffer_WDFC_ID_QCM_FAULT_DATA */
#define NvM_GetSizeOfCrcCompMechanismBuffer_WDFC_ID_SECURITY_ACCESSOfPCPartitionConfig(partitionIndex) 2u  /**< the number of accomplishable value elements in NvM_CrcCompMechanismBuffer_WDFC_ID_SECURITY_ACCESS */
#define NvM_GetSizeOfCrcCompMechanismBuffer_WDFC_ID_SR_PROFILEOfPCPartitionConfig(partitionIndex)   2u  /**< the number of accomplishable value elements in NvM_CrcCompMechanismBuffer_WDFC_ID_SR_PROFILE */
#define NvM_GetSizeOfCrcCompMechanismBuffer_WDFC_ID_SWP1OfPCPartitionConfig(partitionIndex)         2u  /**< the number of accomplishable value elements in NvM_CrcCompMechanismBuffer_WDFC_ID_SWP1 */
#define NvM_GetSizeOfCrcCompMechanismBuffer_WDFC_ID_THPAOfPCPartitionConfig(partitionIndex)         2u  /**< the number of accomplishable value elements in NvM_CrcCompMechanismBuffer_WDFC_ID_THPA */
#define NvM_GetSizeOfCrcCompMechanismBuffer_WDFC_ID_VEH_CFGOfPCPartitionConfig(partitionIndex)      2u  /**< the number of accomplishable value elements in NvM_CrcCompMechanismBuffer_WDFC_ID_VEH_CFG */
#define NvM_GetSizeOfCrcCompMechanismBuffer_WDFC_ID_VOL_POWER_MODE_CFGOfPCPartitionConfig(partitionIndex) 2u  /**< the number of accomplishable value elements in NvM_CrcCompMechanismBuffer_WDFC_ID_VOL_POWER_MODE_CFG */
#define NvM_GetSizeOfCrcCompMechanismBuffer_WDFC_ID_WLC_AP_LEARNOfPCPartitionConfig(partitionIndex) 2u  /**< the number of accomplishable value elements in NvM_CrcCompMechanismBuffer_WDFC_ID_WLC_AP_LEARN */
#define NvM_GetSizeOfCrcCompMechanismBuffer_WDFC_ID_WL_INFOOfPCPartitionConfig(partitionIndex)      2u  /**< the number of accomplishable value elements in NvM_CrcCompMechanismBuffer_WDFC_ID_WL_INFO */
#define NvM_GetSizeOfCrcCompMechanismBuffer_WDFC_ID_WL_LOGOfPCPartitionConfig(partitionIndex)       2u  /**< the number of accomplishable value elements in NvM_CrcCompMechanismBuffer_WDFC_ID_WL_LOG */
#define NvM_GetSizeOfDataIntegrityIntBuffer_DemAdminDataBlockOfPCPartitionConfig(partitionIndex)    2u  /**< the number of accomplishable value elements in NvM_DataIntegrityIntBuffer_DemAdminDataBlock */
#define NvM_GetSizeOfDataIntegrityIntBuffer_DemStatusDataBlockOfPCPartitionConfig(partitionIndex)   2u  /**< the number of accomplishable value elements in NvM_DataIntegrityIntBuffer_DemStatusDataBlock */
#define NvM_GetSizeOfDataIntegrityIntBuffer_WDFC_ID_AP_CONNEXOfPCPartitionConfig(partitionIndex)    2u  /**< the number of accomplishable value elements in NvM_DataIntegrityIntBuffer_WDFC_ID_AP_CONNEX */
#define NvM_GetSizeOfDataIntegrityIntBuffer_WDFC_ID_AP_PARAOfPCPartitionConfig(partitionIndex)      2u  /**< the number of accomplishable value elements in NvM_DataIntegrityIntBuffer_WDFC_ID_AP_PARA */
#define NvM_GetSizeOfDataIntegrityIntBuffer_WDFC_ID_BOOT_PARAOfPCPartitionConfig(partitionIndex)    2u  /**< the number of accomplishable value elements in NvM_DataIntegrityIntBuffer_WDFC_ID_BOOT_PARA */
#define NvM_GetSizeOfDataIntegrityIntBuffer_WDFC_ID_CCPOfPCPartitionConfig(partitionIndex)          2u  /**< the number of accomplishable value elements in NvM_DataIntegrityIntBuffer_WDFC_ID_CCP */
#define NvM_GetSizeOfDataIntegrityIntBuffer_WDFC_ID_DEBUG_DATAOfPCPartitionConfig(partitionIndex)   2u  /**< the number of accomplishable value elements in NvM_DataIntegrityIntBuffer_WDFC_ID_DEBUG_DATA */
#define NvM_GetSizeOfDataIntegrityIntBuffer_WDFC_ID_DLCOfPCPartitionConfig(partitionIndex)          2u  /**< the number of accomplishable value elements in NvM_DataIntegrityIntBuffer_WDFC_ID_DLC */
#define NvM_GetSizeOfDataIntegrityIntBuffer_WDFC_ID_DTCTimeOfPCPartitionConfig(partitionIndex)      2u  /**< the number of accomplishable value elements in NvM_DataIntegrityIntBuffer_WDFC_ID_DTCTime */
#define NvM_GetSizeOfDataIntegrityIntBuffer_WDFC_ID_ECUID_RDI_PROGRAMMING_INFOOfPCPartitionConfig(partitionIndex) 2u  /**< the number of accomplishable value elements in NvM_DataIntegrityIntBuffer_WDFC_ID_ECUID_RDI_PROGRAMMING_INFO */
#define NvM_GetSizeOfDataIntegrityIntBuffer_WDFC_ID_EOL_HW_VERSIONOfPCPartitionConfig(partitionIndex) 2u  /**< the number of accomplishable value elements in NvM_DataIntegrityIntBuffer_WDFC_ID_EOL_HW_VERSION */
#define NvM_GetSizeOfDataIntegrityIntBuffer_WDFC_ID_EOL_INFOOfPCPartitionConfig(partitionIndex)     2u  /**< the number of accomplishable value elements in NvM_DataIntegrityIntBuffer_WDFC_ID_EOL_INFO */
#define NvM_GetSizeOfDataIntegrityIntBuffer_WDFC_ID_EOL_PASSWORDOfPCPartitionConfig(partitionIndex) 2u  /**< the number of accomplishable value elements in NvM_DataIntegrityIntBuffer_WDFC_ID_EOL_PASSWORD */
#define NvM_GetSizeOfDataIntegrityIntBuffer_WDFC_ID_EOL_SWNUMBEROfPCPartitionConfig(partitionIndex) 2u  /**< the number of accomplishable value elements in NvM_DataIntegrityIntBuffer_WDFC_ID_EOL_SWNUMBER */
#define NvM_GetSizeOfDataIntegrityIntBuffer_WDFC_ID_FAULT_CODEOfPCPartitionConfig(partitionIndex)   2u  /**< the number of accomplishable value elements in NvM_DataIntegrityIntBuffer_WDFC_ID_FAULT_CODE */
#define NvM_GetSizeOfDataIntegrityIntBuffer_WDFC_ID_HANDLE_CFGOfPCPartitionConfig(partitionIndex)   2u  /**< the number of accomplishable value elements in NvM_DataIntegrityIntBuffer_WDFC_ID_HANDLE_CFG */
#define NvM_GetSizeOfDataIntegrityIntBuffer_WDFC_ID_IDENT_BANKOfPCPartitionConfig(partitionIndex)   2u  /**< the number of accomplishable value elements in NvM_DataIntegrityIntBuffer_WDFC_ID_IDENT_BANK */
#define NvM_GetSizeOfDataIntegrityIntBuffer_WDFC_ID_IDOPTION_SECURITYOfPCPartitionConfig(partitionIndex) 2u  /**< the number of accomplishable value elements in NvM_DataIntegrityIntBuffer_WDFC_ID_IDOPTION_SECURITY */
#define NvM_GetSizeOfDataIntegrityIntBuffer_WDFC_ID_LAST_FDCOfPCPartitionConfig(partitionIndex)     2u  /**< the number of accomplishable value elements in NvM_DataIntegrityIntBuffer_WDFC_ID_LAST_FDC */
#define NvM_GetSizeOfDataIntegrityIntBuffer_WDFC_ID_MAX_FDCOfPCPartitionConfig(partitionIndex)      2u  /**< the number of accomplishable value elements in NvM_DataIntegrityIntBuffer_WDFC_ID_MAX_FDC */
#define NvM_GetSizeOfDataIntegrityIntBuffer_WDFC_ID_MIRROR_CFGOfPCPartitionConfig(partitionIndex)   2u  /**< the number of accomplishable value elements in NvM_DataIntegrityIntBuffer_WDFC_ID_MIRROR_CFG */
#define NvM_GetSizeOfDataIntegrityIntBuffer_WDFC_ID_MIRROR_OTHER_1OfPCPartitionConfig(partitionIndex) 2u  /**< the number of accomplishable value elements in NvM_DataIntegrityIntBuffer_WDFC_ID_MIRROR_OTHER_1 */
#define NvM_GetSizeOfDataIntegrityIntBuffer_WDFC_ID_MIRROR_POS_RECOfPCPartitionConfig(partitionIndex) 2u  /**< the number of accomplishable value elements in NvM_DataIntegrityIntBuffer_WDFC_ID_MIRROR_POS_REC */
#define NvM_GetSizeOfDataIntegrityIntBuffer_WDFC_ID_MIRROR_STOfPCPartitionConfig(partitionIndex)    2u  /**< the number of accomplishable value elements in NvM_DataIntegrityIntBuffer_WDFC_ID_MIRROR_ST */
#define NvM_GetSizeOfDataIntegrityIntBuffer_WDFC_ID_PART_NUMBER_GEELYOfPCPartitionConfig(partitionIndex) 2u  /**< the number of accomplishable value elements in NvM_DataIntegrityIntBuffer_WDFC_ID_PART_NUMBER_GEELY */
#define NvM_GetSizeOfDataIntegrityIntBuffer_WDFC_ID_PMMOfPCPartitionConfig(partitionIndex)          2u  /**< the number of accomplishable value elements in NvM_DataIntegrityIntBuffer_WDFC_ID_PMM */
#define NvM_GetSizeOfDataIntegrityIntBuffer_WDFC_ID_QCM_FAULT_DATAOfPCPartitionConfig(partitionIndex) 2u  /**< the number of accomplishable value elements in NvM_DataIntegrityIntBuffer_WDFC_ID_QCM_FAULT_DATA */
#define NvM_GetSizeOfDataIntegrityIntBuffer_WDFC_ID_SECURITY_ACCESSOfPCPartitionConfig(partitionIndex) 2u  /**< the number of accomplishable value elements in NvM_DataIntegrityIntBuffer_WDFC_ID_SECURITY_ACCESS */
#define NvM_GetSizeOfDataIntegrityIntBuffer_WDFC_ID_SR_PROFILEOfPCPartitionConfig(partitionIndex)   2u  /**< the number of accomplishable value elements in NvM_DataIntegrityIntBuffer_WDFC_ID_SR_PROFILE */
#define NvM_GetSizeOfDataIntegrityIntBuffer_WDFC_ID_SWP1OfPCPartitionConfig(partitionIndex)         2u  /**< the number of accomplishable value elements in NvM_DataIntegrityIntBuffer_WDFC_ID_SWP1 */
#define NvM_GetSizeOfDataIntegrityIntBuffer_WDFC_ID_THPAOfPCPartitionConfig(partitionIndex)         2u  /**< the number of accomplishable value elements in NvM_DataIntegrityIntBuffer_WDFC_ID_THPA */
#define NvM_GetSizeOfDataIntegrityIntBuffer_WDFC_ID_VEH_CFGOfPCPartitionConfig(partitionIndex)      2u  /**< the number of accomplishable value elements in NvM_DataIntegrityIntBuffer_WDFC_ID_VEH_CFG */
#define NvM_GetSizeOfDataIntegrityIntBuffer_WDFC_ID_VOL_POWER_MODE_CFGOfPCPartitionConfig(partitionIndex) 2u  /**< the number of accomplishable value elements in NvM_DataIntegrityIntBuffer_WDFC_ID_VOL_POWER_MODE_CFG */
#define NvM_GetSizeOfDataIntegrityIntBuffer_WDFC_ID_WLC_AP_LEARNOfPCPartitionConfig(partitionIndex) 2u  /**< the number of accomplishable value elements in NvM_DataIntegrityIntBuffer_WDFC_ID_WLC_AP_LEARN */
#define NvM_GetSizeOfDataIntegrityIntBuffer_WDFC_ID_WL_INFOOfPCPartitionConfig(partitionIndex)      2u  /**< the number of accomplishable value elements in NvM_DataIntegrityIntBuffer_WDFC_ID_WL_INFO */
#define NvM_GetSizeOfDataIntegrityIntBuffer_WDFC_ID_WL_LOGOfPCPartitionConfig(partitionIndex)       2u  /**< the number of accomplishable value elements in NvM_DataIntegrityIntBuffer_WDFC_ID_WL_LOG */
#define NvM_GetSizeOfInternalBufferOfPCPartitionConfig(partitionIndex)                              1094u  /**< the number of accomplishable value elements in NvM_InternalBuffer */
#define NvM_GetSizeOfMultiBlockFsmLib_ProcessingStackElementOfPCPartitionConfig(partitionIndex)     2u  /**< the number of accomplishable value elements in NvM_MultiBlockFsmLib_ProcessingStackElement */
#define NvM_GetSizeOfMultiBlockProcessorFsmLib_ProcessingStackElementOfPCPartitionConfig(partitionIndex) 1u  /**< the number of accomplishable value elements in NvM_MultiBlockProcessorFsmLib_ProcessingStackElement */
#define NvM_GetSizeOfNvServiceFsmLib_ProcessingStackElementOfPCPartitionConfig(partitionIndex)      2u  /**< the number of accomplishable value elements in NvM_NvServiceFsmLib_ProcessingStackElement */
#define NvM_GetSizeOfNvServiceProcessorFsmLib_ProcessingStackElementOfPCPartitionConfig(partitionIndex) 1u  /**< the number of accomplishable value elements in NvM_NvServiceProcessorFsmLib_ProcessingStackElement */
#define NvM_GetSizeOfQueueListOfPCPartitionConfig(partitionIndex)                                   25u  /**< the number of accomplishable value elements in NvM_QueueList */
#define NvM_GetSizeOfServiceProcessorFsmLib_ProcessingStackElementOfPCPartitionConfig(partitionIndex) 1u  /**< the number of accomplishable value elements in NvM_ServiceProcessorFsmLib_ProcessingStackElement */
#define NvM_GetSizeOfSingleBlockFsmLib_ProcessingStackElementOfPCPartitionConfig(partitionIndex)    4u  /**< the number of accomplishable value elements in NvM_SingleBlockFsmLib_ProcessingStackElement */
#define NvM_GetValidateAllFsm_InstanceOfPCPartitionConfig(partitionIndex)                           (&(NvM_ValidateAllFsm_Instance))  /**< the pointer to NvM_ValidateAllFsm_Instance */
#define NvM_GetWriteAllFsm_ContextOfPCPartitionConfig(partitionIndex)                               (&(NvM_WriteAllFsm_Context))  /**< the pointer to NvM_WriteAllFsm_Context */
#define NvM_GetWriteAllFsm_InstanceOfPCPartitionConfig(partitionIndex)                              (&(NvM_WriteAllFsm_Instance))  /**< the pointer to NvM_WriteAllFsm_Instance */
#define NvM_GetWriteBlockFsm_ContextOfPCPartitionConfig(partitionIndex)                             (&(NvM_WriteBlockFsm_Context))  /**< the pointer to NvM_WriteBlockFsm_Context */
#define NvM_GetWriteBlockFsm_InstanceOfPCPartitionConfig(partitionIndex)                            (&(NvM_WriteBlockFsm_Instance))  /**< the pointer to NvM_WriteBlockFsm_Instance */
#define NvM_GetWriteNvBlockFsm_ContextOfPCPartitionConfig(partitionIndex)                           (&(NvM_WriteNvBlockFsm_Context))  /**< the pointer to NvM_WriteNvBlockFsm_Context */
/** 
  \}
*/ 

/** 
  \defgroup  NvMPCGetDataMacros  NvM Get Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read CONST and VAR data.
  \{
*/ 
#define NvM_GetBackgroundCrcRecalcFsmLib_Instance(partitionIndex)                                   ((*(NvM_GetBackgroundCrcRecalcFsmLib_InstanceOfPCPartitionConfig(partitionIndex))))
#define NvM_GetBackgroundCrcRecalcFsmLib_ProcessingStackElement(Index, partitionIndex)              (NvM_GetBackgroundCrcRecalcFsmLib_ProcessingStackElementOfPCPartitionConfig(partitionIndex)[(Index)])
#define NvM_GetBackgroundCrcRecalcFsm_Context(partitionIndex)                                       ((*(NvM_GetBackgroundCrcRecalcFsm_ContextOfPCPartitionConfig(partitionIndex))))
#define NvM_GetBackgroundCrcRecalcFsm_Instance(partitionIndex)                                      ((*(NvM_GetBackgroundCrcRecalcFsm_InstanceOfPCPartitionConfig(partitionIndex))))
#define NvM_GetBackgroundDataIntegrityService_Instance(partitionIndex)                              ((*(NvM_GetBackgroundDataIntegrityService_InstanceOfPCPartitionConfig(partitionIndex))))
#define NvM_GetBlockDescriptor(Index)                                                               (NvM_GetBlockDescriptorOfPCPartitionConfig()[(Index)])
#define NvM_GetBlockManagementInfo_DemAdminDataBlock(partitionIndex)                                ((*(NvM_GetBlockManagementInfo_DemAdminDataBlockOfPCPartitionConfig(partitionIndex))))
#define NvM_GetBlockManagementInfo_DemStatusDataBlock(partitionIndex)                               ((*(NvM_GetBlockManagementInfo_DemStatusDataBlockOfPCPartitionConfig(partitionIndex))))
#define NvM_GetBlockManagementInfo_NvMConfigBlock(partitionIndex)                                   ((*(NvM_GetBlockManagementInfo_NvMConfigBlockOfPCPartitionConfig(partitionIndex))))
#define NvM_GetBlockManagementInfo_NvMMultiBlock(partitionIndex)                                    ((*(NvM_GetBlockManagementInfo_NvMMultiBlockOfPCPartitionConfig(partitionIndex))))
#define NvM_GetBlockManagementInfo_WDFC_ID_AP_CONNEX(partitionIndex)                                ((*(NvM_GetBlockManagementInfo_WDFC_ID_AP_CONNEXOfPCPartitionConfig(partitionIndex))))
#define NvM_GetBlockManagementInfo_WDFC_ID_AP_PARA(partitionIndex)                                  ((*(NvM_GetBlockManagementInfo_WDFC_ID_AP_PARAOfPCPartitionConfig(partitionIndex))))
#define NvM_GetBlockManagementInfo_WDFC_ID_BOOT_PARA(partitionIndex)                                ((*(NvM_GetBlockManagementInfo_WDFC_ID_BOOT_PARAOfPCPartitionConfig(partitionIndex))))
#define NvM_GetBlockManagementInfo_WDFC_ID_CCP(partitionIndex)                                      ((*(NvM_GetBlockManagementInfo_WDFC_ID_CCPOfPCPartitionConfig(partitionIndex))))
#define NvM_GetBlockManagementInfo_WDFC_ID_DEBUG_DATA(partitionIndex)                               ((*(NvM_GetBlockManagementInfo_WDFC_ID_DEBUG_DATAOfPCPartitionConfig(partitionIndex))))
#define NvM_GetBlockManagementInfo_WDFC_ID_DLC(partitionIndex)                                      ((*(NvM_GetBlockManagementInfo_WDFC_ID_DLCOfPCPartitionConfig(partitionIndex))))
#define NvM_GetBlockManagementInfo_WDFC_ID_DTCTime(partitionIndex)                                  ((*(NvM_GetBlockManagementInfo_WDFC_ID_DTCTimeOfPCPartitionConfig(partitionIndex))))
#define NvM_GetBlockManagementInfo_WDFC_ID_ECUID_RDI_PROGRAMMING_INFO(partitionIndex)               ((*(NvM_GetBlockManagementInfo_WDFC_ID_ECUID_RDI_PROGRAMMING_INFOOfPCPartitionConfig(partitionIndex))))
#define NvM_GetBlockManagementInfo_WDFC_ID_EOL_HW_VERSION(partitionIndex)                           ((*(NvM_GetBlockManagementInfo_WDFC_ID_EOL_HW_VERSIONOfPCPartitionConfig(partitionIndex))))
#define NvM_GetBlockManagementInfo_WDFC_ID_EOL_INFO(partitionIndex)                                 ((*(NvM_GetBlockManagementInfo_WDFC_ID_EOL_INFOOfPCPartitionConfig(partitionIndex))))
#define NvM_GetBlockManagementInfo_WDFC_ID_EOL_PASSWORD(partitionIndex)                             ((*(NvM_GetBlockManagementInfo_WDFC_ID_EOL_PASSWORDOfPCPartitionConfig(partitionIndex))))
#define NvM_GetBlockManagementInfo_WDFC_ID_EOL_SWNUMBER(partitionIndex)                             ((*(NvM_GetBlockManagementInfo_WDFC_ID_EOL_SWNUMBEROfPCPartitionConfig(partitionIndex))))
#define NvM_GetBlockManagementInfo_WDFC_ID_FAULT_CODE(partitionIndex)                               ((*(NvM_GetBlockManagementInfo_WDFC_ID_FAULT_CODEOfPCPartitionConfig(partitionIndex))))
#define NvM_GetBlockManagementInfo_WDFC_ID_HANDLE_CFG(partitionIndex)                               ((*(NvM_GetBlockManagementInfo_WDFC_ID_HANDLE_CFGOfPCPartitionConfig(partitionIndex))))
#define NvM_GetBlockManagementInfo_WDFC_ID_IDENT_BANK(partitionIndex)                               ((*(NvM_GetBlockManagementInfo_WDFC_ID_IDENT_BANKOfPCPartitionConfig(partitionIndex))))
#define NvM_GetBlockManagementInfo_WDFC_ID_IDOPTION_SECURITY(partitionIndex)                        ((*(NvM_GetBlockManagementInfo_WDFC_ID_IDOPTION_SECURITYOfPCPartitionConfig(partitionIndex))))
#define NvM_GetBlockManagementInfo_WDFC_ID_LAST_FDC(partitionIndex)                                 ((*(NvM_GetBlockManagementInfo_WDFC_ID_LAST_FDCOfPCPartitionConfig(partitionIndex))))
#define NvM_GetBlockManagementInfo_WDFC_ID_MAX_FDC(partitionIndex)                                  ((*(NvM_GetBlockManagementInfo_WDFC_ID_MAX_FDCOfPCPartitionConfig(partitionIndex))))
#define NvM_GetBlockManagementInfo_WDFC_ID_MIRROR_CFG(partitionIndex)                               ((*(NvM_GetBlockManagementInfo_WDFC_ID_MIRROR_CFGOfPCPartitionConfig(partitionIndex))))
#define NvM_GetBlockManagementInfo_WDFC_ID_MIRROR_OTHER_1(partitionIndex)                           ((*(NvM_GetBlockManagementInfo_WDFC_ID_MIRROR_OTHER_1OfPCPartitionConfig(partitionIndex))))
#define NvM_GetBlockManagementInfo_WDFC_ID_MIRROR_POS_REC(partitionIndex)                           ((*(NvM_GetBlockManagementInfo_WDFC_ID_MIRROR_POS_RECOfPCPartitionConfig(partitionIndex))))
#define NvM_GetBlockManagementInfo_WDFC_ID_MIRROR_ST(partitionIndex)                                ((*(NvM_GetBlockManagementInfo_WDFC_ID_MIRROR_STOfPCPartitionConfig(partitionIndex))))
#define NvM_GetBlockManagementInfo_WDFC_ID_PART_NUMBER_GEELY(partitionIndex)                        ((*(NvM_GetBlockManagementInfo_WDFC_ID_PART_NUMBER_GEELYOfPCPartitionConfig(partitionIndex))))
#define NvM_GetBlockManagementInfo_WDFC_ID_PMM(partitionIndex)                                      ((*(NvM_GetBlockManagementInfo_WDFC_ID_PMMOfPCPartitionConfig(partitionIndex))))
#define NvM_GetBlockManagementInfo_WDFC_ID_QCM_FAULT_DATA(partitionIndex)                           ((*(NvM_GetBlockManagementInfo_WDFC_ID_QCM_FAULT_DATAOfPCPartitionConfig(partitionIndex))))
#define NvM_GetBlockManagementInfo_WDFC_ID_SECURITY_ACCESS(partitionIndex)                          ((*(NvM_GetBlockManagementInfo_WDFC_ID_SECURITY_ACCESSOfPCPartitionConfig(partitionIndex))))
#define NvM_GetBlockManagementInfo_WDFC_ID_SR_PROFILE(partitionIndex)                               ((*(NvM_GetBlockManagementInfo_WDFC_ID_SR_PROFILEOfPCPartitionConfig(partitionIndex))))
#define NvM_GetBlockManagementInfo_WDFC_ID_SWP1(partitionIndex)                                     ((*(NvM_GetBlockManagementInfo_WDFC_ID_SWP1OfPCPartitionConfig(partitionIndex))))
#define NvM_GetBlockManagementInfo_WDFC_ID_THPA(partitionIndex)                                     ((*(NvM_GetBlockManagementInfo_WDFC_ID_THPAOfPCPartitionConfig(partitionIndex))))
#define NvM_GetBlockManagementInfo_WDFC_ID_VEH_CFG(partitionIndex)                                  ((*(NvM_GetBlockManagementInfo_WDFC_ID_VEH_CFGOfPCPartitionConfig(partitionIndex))))
#define NvM_GetBlockManagementInfo_WDFC_ID_VOL_POWER_MODE_CFG(partitionIndex)                       ((*(NvM_GetBlockManagementInfo_WDFC_ID_VOL_POWER_MODE_CFGOfPCPartitionConfig(partitionIndex))))
#define NvM_GetBlockManagementInfo_WDFC_ID_WLC_AP_LEARN(partitionIndex)                             ((*(NvM_GetBlockManagementInfo_WDFC_ID_WLC_AP_LEARNOfPCPartitionConfig(partitionIndex))))
#define NvM_GetBlockManagementInfo_WDFC_ID_WL_INFO(partitionIndex)                                  ((*(NvM_GetBlockManagementInfo_WDFC_ID_WL_INFOOfPCPartitionConfig(partitionIndex))))
#define NvM_GetBlockManagementInfo_WDFC_ID_WL_LOG(partitionIndex)                                   ((*(NvM_GetBlockManagementInfo_WDFC_ID_WL_LOGOfPCPartitionConfig(partitionIndex))))
#define NvM_GetCrcCompMechanismBuffer_DemAdminDataBlock(Index, partitionIndex)                      (NvM_GetCrcCompMechanismBuffer_DemAdminDataBlockOfPCPartitionConfig(partitionIndex)[(Index)])
#define NvM_GetCrcCompMechanismBuffer_DemStatusDataBlock(Index, partitionIndex)                     (NvM_GetCrcCompMechanismBuffer_DemStatusDataBlockOfPCPartitionConfig(partitionIndex)[(Index)])
#define NvM_GetCrcCompMechanismBuffer_NvMConfigBlock(Index, partitionIndex)                         (NvM_GetCrcCompMechanismBuffer_NvMConfigBlockOfPCPartitionConfig(partitionIndex)[(Index)])
#define NvM_GetCrcCompMechanismBuffer_WDFC_ID_AP_CONNEX(Index, partitionIndex)                      (NvM_GetCrcCompMechanismBuffer_WDFC_ID_AP_CONNEXOfPCPartitionConfig(partitionIndex)[(Index)])
#define NvM_GetCrcCompMechanismBuffer_WDFC_ID_AP_PARA(Index, partitionIndex)                        (NvM_GetCrcCompMechanismBuffer_WDFC_ID_AP_PARAOfPCPartitionConfig(partitionIndex)[(Index)])
#define NvM_GetCrcCompMechanismBuffer_WDFC_ID_BOOT_PARA(Index, partitionIndex)                      (NvM_GetCrcCompMechanismBuffer_WDFC_ID_BOOT_PARAOfPCPartitionConfig(partitionIndex)[(Index)])
#define NvM_GetCrcCompMechanismBuffer_WDFC_ID_CCP(Index, partitionIndex)                            (NvM_GetCrcCompMechanismBuffer_WDFC_ID_CCPOfPCPartitionConfig(partitionIndex)[(Index)])
#define NvM_GetCrcCompMechanismBuffer_WDFC_ID_DEBUG_DATA(Index, partitionIndex)                     (NvM_GetCrcCompMechanismBuffer_WDFC_ID_DEBUG_DATAOfPCPartitionConfig(partitionIndex)[(Index)])
#define NvM_GetCrcCompMechanismBuffer_WDFC_ID_DLC(Index, partitionIndex)                            (NvM_GetCrcCompMechanismBuffer_WDFC_ID_DLCOfPCPartitionConfig(partitionIndex)[(Index)])
#define NvM_GetCrcCompMechanismBuffer_WDFC_ID_DTCTime(Index, partitionIndex)                        (NvM_GetCrcCompMechanismBuffer_WDFC_ID_DTCTimeOfPCPartitionConfig(partitionIndex)[(Index)])
#define NvM_GetCrcCompMechanismBuffer_WDFC_ID_ECUID_RDI_PROGRAMMING_INFO(Index, partitionIndex)     (NvM_GetCrcCompMechanismBuffer_WDFC_ID_ECUID_RDI_PROGRAMMING_INFOOfPCPartitionConfig(partitionIndex)[(Index)])
#define NvM_GetCrcCompMechanismBuffer_WDFC_ID_EOL_HW_VERSION(Index, partitionIndex)                 (NvM_GetCrcCompMechanismBuffer_WDFC_ID_EOL_HW_VERSIONOfPCPartitionConfig(partitionIndex)[(Index)])
#define NvM_GetCrcCompMechanismBuffer_WDFC_ID_EOL_INFO(Index, partitionIndex)                       (NvM_GetCrcCompMechanismBuffer_WDFC_ID_EOL_INFOOfPCPartitionConfig(partitionIndex)[(Index)])
#define NvM_GetCrcCompMechanismBuffer_WDFC_ID_EOL_PASSWORD(Index, partitionIndex)                   (NvM_GetCrcCompMechanismBuffer_WDFC_ID_EOL_PASSWORDOfPCPartitionConfig(partitionIndex)[(Index)])
#define NvM_GetCrcCompMechanismBuffer_WDFC_ID_EOL_SWNUMBER(Index, partitionIndex)                   (NvM_GetCrcCompMechanismBuffer_WDFC_ID_EOL_SWNUMBEROfPCPartitionConfig(partitionIndex)[(Index)])
#define NvM_GetCrcCompMechanismBuffer_WDFC_ID_FAULT_CODE(Index, partitionIndex)                     (NvM_GetCrcCompMechanismBuffer_WDFC_ID_FAULT_CODEOfPCPartitionConfig(partitionIndex)[(Index)])
#define NvM_GetCrcCompMechanismBuffer_WDFC_ID_HANDLE_CFG(Index, partitionIndex)                     (NvM_GetCrcCompMechanismBuffer_WDFC_ID_HANDLE_CFGOfPCPartitionConfig(partitionIndex)[(Index)])
#define NvM_GetCrcCompMechanismBuffer_WDFC_ID_IDENT_BANK(Index, partitionIndex)                     (NvM_GetCrcCompMechanismBuffer_WDFC_ID_IDENT_BANKOfPCPartitionConfig(partitionIndex)[(Index)])
#define NvM_GetCrcCompMechanismBuffer_WDFC_ID_IDOPTION_SECURITY(Index, partitionIndex)              (NvM_GetCrcCompMechanismBuffer_WDFC_ID_IDOPTION_SECURITYOfPCPartitionConfig(partitionIndex)[(Index)])
#define NvM_GetCrcCompMechanismBuffer_WDFC_ID_LAST_FDC(Index, partitionIndex)                       (NvM_GetCrcCompMechanismBuffer_WDFC_ID_LAST_FDCOfPCPartitionConfig(partitionIndex)[(Index)])
#define NvM_GetCrcCompMechanismBuffer_WDFC_ID_MAX_FDC(Index, partitionIndex)                        (NvM_GetCrcCompMechanismBuffer_WDFC_ID_MAX_FDCOfPCPartitionConfig(partitionIndex)[(Index)])
#define NvM_GetCrcCompMechanismBuffer_WDFC_ID_MIRROR_CFG(Index, partitionIndex)                     (NvM_GetCrcCompMechanismBuffer_WDFC_ID_MIRROR_CFGOfPCPartitionConfig(partitionIndex)[(Index)])
#define NvM_GetCrcCompMechanismBuffer_WDFC_ID_MIRROR_OTHER_1(Index, partitionIndex)                 (NvM_GetCrcCompMechanismBuffer_WDFC_ID_MIRROR_OTHER_1OfPCPartitionConfig(partitionIndex)[(Index)])
#define NvM_GetCrcCompMechanismBuffer_WDFC_ID_MIRROR_POS_REC(Index, partitionIndex)                 (NvM_GetCrcCompMechanismBuffer_WDFC_ID_MIRROR_POS_RECOfPCPartitionConfig(partitionIndex)[(Index)])
#define NvM_GetCrcCompMechanismBuffer_WDFC_ID_MIRROR_ST(Index, partitionIndex)                      (NvM_GetCrcCompMechanismBuffer_WDFC_ID_MIRROR_STOfPCPartitionConfig(partitionIndex)[(Index)])
#define NvM_GetCrcCompMechanismBuffer_WDFC_ID_PART_NUMBER_GEELY(Index, partitionIndex)              (NvM_GetCrcCompMechanismBuffer_WDFC_ID_PART_NUMBER_GEELYOfPCPartitionConfig(partitionIndex)[(Index)])
#define NvM_GetCrcCompMechanismBuffer_WDFC_ID_PMM(Index, partitionIndex)                            (NvM_GetCrcCompMechanismBuffer_WDFC_ID_PMMOfPCPartitionConfig(partitionIndex)[(Index)])
#define NvM_GetCrcCompMechanismBuffer_WDFC_ID_QCM_FAULT_DATA(Index, partitionIndex)                 (NvM_GetCrcCompMechanismBuffer_WDFC_ID_QCM_FAULT_DATAOfPCPartitionConfig(partitionIndex)[(Index)])
#define NvM_GetCrcCompMechanismBuffer_WDFC_ID_SECURITY_ACCESS(Index, partitionIndex)                (NvM_GetCrcCompMechanismBuffer_WDFC_ID_SECURITY_ACCESSOfPCPartitionConfig(partitionIndex)[(Index)])
#define NvM_GetCrcCompMechanismBuffer_WDFC_ID_SR_PROFILE(Index, partitionIndex)                     (NvM_GetCrcCompMechanismBuffer_WDFC_ID_SR_PROFILEOfPCPartitionConfig(partitionIndex)[(Index)])
#define NvM_GetCrcCompMechanismBuffer_WDFC_ID_SWP1(Index, partitionIndex)                           (NvM_GetCrcCompMechanismBuffer_WDFC_ID_SWP1OfPCPartitionConfig(partitionIndex)[(Index)])
#define NvM_GetCrcCompMechanismBuffer_WDFC_ID_THPA(Index, partitionIndex)                           (NvM_GetCrcCompMechanismBuffer_WDFC_ID_THPAOfPCPartitionConfig(partitionIndex)[(Index)])
#define NvM_GetCrcCompMechanismBuffer_WDFC_ID_VEH_CFG(Index, partitionIndex)                        (NvM_GetCrcCompMechanismBuffer_WDFC_ID_VEH_CFGOfPCPartitionConfig(partitionIndex)[(Index)])
#define NvM_GetCrcCompMechanismBuffer_WDFC_ID_VOL_POWER_MODE_CFG(Index, partitionIndex)             (NvM_GetCrcCompMechanismBuffer_WDFC_ID_VOL_POWER_MODE_CFGOfPCPartitionConfig(partitionIndex)[(Index)])
#define NvM_GetCrcCompMechanismBuffer_WDFC_ID_WLC_AP_LEARN(Index, partitionIndex)                   (NvM_GetCrcCompMechanismBuffer_WDFC_ID_WLC_AP_LEARNOfPCPartitionConfig(partitionIndex)[(Index)])
#define NvM_GetCrcCompMechanismBuffer_WDFC_ID_WL_INFO(Index, partitionIndex)                        (NvM_GetCrcCompMechanismBuffer_WDFC_ID_WL_INFOOfPCPartitionConfig(partitionIndex)[(Index)])
#define NvM_GetCrcCompMechanismBuffer_WDFC_ID_WL_LOG(Index, partitionIndex)                         (NvM_GetCrcCompMechanismBuffer_WDFC_ID_WL_LOGOfPCPartitionConfig(partitionIndex)[(Index)])
#define NvM_GetDataIntegrityFsm_Instance(partitionIndex)                                            ((*(NvM_GetDataIntegrityFsm_InstanceOfPCPartitionConfig(partitionIndex))))
#define NvM_GetDataIntegrityIntBuffer_DemAdminDataBlock(Index, partitionIndex)                      (NvM_GetDataIntegrityIntBuffer_DemAdminDataBlockOfPCPartitionConfig(partitionIndex)[(Index)])
#define NvM_GetDataIntegrityIntBuffer_DemStatusDataBlock(Index, partitionIndex)                     (NvM_GetDataIntegrityIntBuffer_DemStatusDataBlockOfPCPartitionConfig(partitionIndex)[(Index)])
#define NvM_GetDataIntegrityIntBuffer_WDFC_ID_AP_CONNEX(Index, partitionIndex)                      (NvM_GetDataIntegrityIntBuffer_WDFC_ID_AP_CONNEXOfPCPartitionConfig(partitionIndex)[(Index)])
#define NvM_GetDataIntegrityIntBuffer_WDFC_ID_AP_PARA(Index, partitionIndex)                        (NvM_GetDataIntegrityIntBuffer_WDFC_ID_AP_PARAOfPCPartitionConfig(partitionIndex)[(Index)])
#define NvM_GetDataIntegrityIntBuffer_WDFC_ID_BOOT_PARA(Index, partitionIndex)                      (NvM_GetDataIntegrityIntBuffer_WDFC_ID_BOOT_PARAOfPCPartitionConfig(partitionIndex)[(Index)])
#define NvM_GetDataIntegrityIntBuffer_WDFC_ID_CCP(Index, partitionIndex)                            (NvM_GetDataIntegrityIntBuffer_WDFC_ID_CCPOfPCPartitionConfig(partitionIndex)[(Index)])
#define NvM_GetDataIntegrityIntBuffer_WDFC_ID_DEBUG_DATA(Index, partitionIndex)                     (NvM_GetDataIntegrityIntBuffer_WDFC_ID_DEBUG_DATAOfPCPartitionConfig(partitionIndex)[(Index)])
#define NvM_GetDataIntegrityIntBuffer_WDFC_ID_DLC(Index, partitionIndex)                            (NvM_GetDataIntegrityIntBuffer_WDFC_ID_DLCOfPCPartitionConfig(partitionIndex)[(Index)])
#define NvM_GetDataIntegrityIntBuffer_WDFC_ID_DTCTime(Index, partitionIndex)                        (NvM_GetDataIntegrityIntBuffer_WDFC_ID_DTCTimeOfPCPartitionConfig(partitionIndex)[(Index)])
#define NvM_GetDataIntegrityIntBuffer_WDFC_ID_ECUID_RDI_PROGRAMMING_INFO(Index, partitionIndex)     (NvM_GetDataIntegrityIntBuffer_WDFC_ID_ECUID_RDI_PROGRAMMING_INFOOfPCPartitionConfig(partitionIndex)[(Index)])
#define NvM_GetDataIntegrityIntBuffer_WDFC_ID_EOL_HW_VERSION(Index, partitionIndex)                 (NvM_GetDataIntegrityIntBuffer_WDFC_ID_EOL_HW_VERSIONOfPCPartitionConfig(partitionIndex)[(Index)])
#define NvM_GetDataIntegrityIntBuffer_WDFC_ID_EOL_INFO(Index, partitionIndex)                       (NvM_GetDataIntegrityIntBuffer_WDFC_ID_EOL_INFOOfPCPartitionConfig(partitionIndex)[(Index)])
#define NvM_GetDataIntegrityIntBuffer_WDFC_ID_EOL_PASSWORD(Index, partitionIndex)                   (NvM_GetDataIntegrityIntBuffer_WDFC_ID_EOL_PASSWORDOfPCPartitionConfig(partitionIndex)[(Index)])
#define NvM_GetDataIntegrityIntBuffer_WDFC_ID_EOL_SWNUMBER(Index, partitionIndex)                   (NvM_GetDataIntegrityIntBuffer_WDFC_ID_EOL_SWNUMBEROfPCPartitionConfig(partitionIndex)[(Index)])
#define NvM_GetDataIntegrityIntBuffer_WDFC_ID_FAULT_CODE(Index, partitionIndex)                     (NvM_GetDataIntegrityIntBuffer_WDFC_ID_FAULT_CODEOfPCPartitionConfig(partitionIndex)[(Index)])
#define NvM_GetDataIntegrityIntBuffer_WDFC_ID_HANDLE_CFG(Index, partitionIndex)                     (NvM_GetDataIntegrityIntBuffer_WDFC_ID_HANDLE_CFGOfPCPartitionConfig(partitionIndex)[(Index)])
#define NvM_GetDataIntegrityIntBuffer_WDFC_ID_IDENT_BANK(Index, partitionIndex)                     (NvM_GetDataIntegrityIntBuffer_WDFC_ID_IDENT_BANKOfPCPartitionConfig(partitionIndex)[(Index)])
#define NvM_GetDataIntegrityIntBuffer_WDFC_ID_IDOPTION_SECURITY(Index, partitionIndex)              (NvM_GetDataIntegrityIntBuffer_WDFC_ID_IDOPTION_SECURITYOfPCPartitionConfig(partitionIndex)[(Index)])
#define NvM_GetDataIntegrityIntBuffer_WDFC_ID_LAST_FDC(Index, partitionIndex)                       (NvM_GetDataIntegrityIntBuffer_WDFC_ID_LAST_FDCOfPCPartitionConfig(partitionIndex)[(Index)])
#define NvM_GetDataIntegrityIntBuffer_WDFC_ID_MAX_FDC(Index, partitionIndex)                        (NvM_GetDataIntegrityIntBuffer_WDFC_ID_MAX_FDCOfPCPartitionConfig(partitionIndex)[(Index)])
#define NvM_GetDataIntegrityIntBuffer_WDFC_ID_MIRROR_CFG(Index, partitionIndex)                     (NvM_GetDataIntegrityIntBuffer_WDFC_ID_MIRROR_CFGOfPCPartitionConfig(partitionIndex)[(Index)])
#define NvM_GetDataIntegrityIntBuffer_WDFC_ID_MIRROR_OTHER_1(Index, partitionIndex)                 (NvM_GetDataIntegrityIntBuffer_WDFC_ID_MIRROR_OTHER_1OfPCPartitionConfig(partitionIndex)[(Index)])
#define NvM_GetDataIntegrityIntBuffer_WDFC_ID_MIRROR_POS_REC(Index, partitionIndex)                 (NvM_GetDataIntegrityIntBuffer_WDFC_ID_MIRROR_POS_RECOfPCPartitionConfig(partitionIndex)[(Index)])
#define NvM_GetDataIntegrityIntBuffer_WDFC_ID_MIRROR_ST(Index, partitionIndex)                      (NvM_GetDataIntegrityIntBuffer_WDFC_ID_MIRROR_STOfPCPartitionConfig(partitionIndex)[(Index)])
#define NvM_GetDataIntegrityIntBuffer_WDFC_ID_PART_NUMBER_GEELY(Index, partitionIndex)              (NvM_GetDataIntegrityIntBuffer_WDFC_ID_PART_NUMBER_GEELYOfPCPartitionConfig(partitionIndex)[(Index)])
#define NvM_GetDataIntegrityIntBuffer_WDFC_ID_PMM(Index, partitionIndex)                            (NvM_GetDataIntegrityIntBuffer_WDFC_ID_PMMOfPCPartitionConfig(partitionIndex)[(Index)])
#define NvM_GetDataIntegrityIntBuffer_WDFC_ID_QCM_FAULT_DATA(Index, partitionIndex)                 (NvM_GetDataIntegrityIntBuffer_WDFC_ID_QCM_FAULT_DATAOfPCPartitionConfig(partitionIndex)[(Index)])
#define NvM_GetDataIntegrityIntBuffer_WDFC_ID_SECURITY_ACCESS(Index, partitionIndex)                (NvM_GetDataIntegrityIntBuffer_WDFC_ID_SECURITY_ACCESSOfPCPartitionConfig(partitionIndex)[(Index)])
#define NvM_GetDataIntegrityIntBuffer_WDFC_ID_SR_PROFILE(Index, partitionIndex)                     (NvM_GetDataIntegrityIntBuffer_WDFC_ID_SR_PROFILEOfPCPartitionConfig(partitionIndex)[(Index)])
#define NvM_GetDataIntegrityIntBuffer_WDFC_ID_SWP1(Index, partitionIndex)                           (NvM_GetDataIntegrityIntBuffer_WDFC_ID_SWP1OfPCPartitionConfig(partitionIndex)[(Index)])
#define NvM_GetDataIntegrityIntBuffer_WDFC_ID_THPA(Index, partitionIndex)                           (NvM_GetDataIntegrityIntBuffer_WDFC_ID_THPAOfPCPartitionConfig(partitionIndex)[(Index)])
#define NvM_GetDataIntegrityIntBuffer_WDFC_ID_VEH_CFG(Index, partitionIndex)                        (NvM_GetDataIntegrityIntBuffer_WDFC_ID_VEH_CFGOfPCPartitionConfig(partitionIndex)[(Index)])
#define NvM_GetDataIntegrityIntBuffer_WDFC_ID_VOL_POWER_MODE_CFG(Index, partitionIndex)             (NvM_GetDataIntegrityIntBuffer_WDFC_ID_VOL_POWER_MODE_CFGOfPCPartitionConfig(partitionIndex)[(Index)])
#define NvM_GetDataIntegrityIntBuffer_WDFC_ID_WLC_AP_LEARN(Index, partitionIndex)                   (NvM_GetDataIntegrityIntBuffer_WDFC_ID_WLC_AP_LEARNOfPCPartitionConfig(partitionIndex)[(Index)])
#define NvM_GetDataIntegrityIntBuffer_WDFC_ID_WL_INFO(Index, partitionIndex)                        (NvM_GetDataIntegrityIntBuffer_WDFC_ID_WL_INFOOfPCPartitionConfig(partitionIndex)[(Index)])
#define NvM_GetDataIntegrityIntBuffer_WDFC_ID_WL_LOG(Index, partitionIndex)                         (NvM_GetDataIntegrityIntBuffer_WDFC_ID_WL_LOGOfPCPartitionConfig(partitionIndex)[(Index)])
#define NvM_GetDataIntegrityRecalcQueue_Instance(partitionIndex)                                    ((*(NvM_GetDataIntegrityRecalcQueue_InstanceOfPCPartitionConfig(partitionIndex))))
#define NvM_GetDcmBlockManagementInfo(partitionIndex)                                               ((*(NvM_GetDcmBlockManagementInfoOfPCPartitionConfig(partitionIndex))))
#define NvM_GetForegroundDataIntegrityService_Instance(partitionIndex)                              ((*(NvM_GetForegroundDataIntegrityService_InstanceOfPCPartitionConfig(partitionIndex))))
#define NvM_GetInternalBuffer(Index, partitionIndex)                                                (NvM_GetInternalBufferOfPCPartitionConfig(partitionIndex)[(Index)])
#define NvM_GetMultiBlockFsmLib_ProcessingStackElement(Index, partitionIndex)                       (NvM_GetMultiBlockFsmLib_ProcessingStackElementOfPCPartitionConfig(partitionIndex)[(Index)])
#define NvM_GetMultiBlockJob(partitionIndex)                                                        ((*(NvM_GetMultiBlockJobOfPCPartitionConfig(partitionIndex))))
#define NvM_GetMultiBlockJobFsm_Context(partitionIndex)                                             ((*(NvM_GetMultiBlockJobFsm_ContextOfPCPartitionConfig(partitionIndex))))
#define NvM_GetMultiBlockJobFsm_Instance(partitionIndex)                                            ((*(NvM_GetMultiBlockJobFsm_InstanceOfPCPartitionConfig(partitionIndex))))
#define NvM_GetMultiBlockJobInformation(partitionIndex)                                             ((*(NvM_GetMultiBlockJobInformationOfPCPartitionConfig(partitionIndex))))
#define NvM_GetMultiBlockProcessorFsmLib_Instance(partitionIndex)                                   ((*(NvM_GetMultiBlockProcessorFsmLib_InstanceOfPCPartitionConfig(partitionIndex))))
#define NvM_GetMultiBlockProcessorFsmLib_ProcessingStackElement(Index, partitionIndex)              (NvM_GetMultiBlockProcessorFsmLib_ProcessingStackElementOfPCPartitionConfig(partitionIndex)[(Index)])
#define NvM_GetMultiBlockServiceFsmLib_Instance(partitionIndex)                                     ((*(NvM_GetMultiBlockServiceFsmLib_InstanceOfPCPartitionConfig(partitionIndex))))
#define NvM_GetNvJobContext(partitionIndex)                                                         ((*(NvM_GetNvJobContextOfPCPartitionConfig(partitionIndex))))
#define NvM_GetNvJobFsm_Instance(partitionIndex)                                                    ((*(NvM_GetNvJobFsm_InstanceOfPCPartitionConfig(partitionIndex))))
#define NvM_GetNvServiceFsmLib_Instance(partitionIndex)                                             ((*(NvM_GetNvServiceFsmLib_InstanceOfPCPartitionConfig(partitionIndex))))
#define NvM_GetNvServiceFsmLib_ProcessingStackElement(Index, partitionIndex)                        (NvM_GetNvServiceFsmLib_ProcessingStackElementOfPCPartitionConfig(partitionIndex)[(Index)])
#define NvM_GetNvServiceProcessorFsmLib_Instance(partitionIndex)                                    ((*(NvM_GetNvServiceProcessorFsmLib_InstanceOfPCPartitionConfig(partitionIndex))))
#define NvM_GetNvServiceProcessorFsmLib_ProcessingStackElement(Index, partitionIndex)               (NvM_GetNvServiceProcessorFsmLib_ProcessingStackElementOfPCPartitionConfig(partitionIndex)[(Index)])
#define NvM_GetPCPartitionConfigIdxOfPartitionIdentifiers(Index)                                    (NvM_GetPartitionIdentifiersOfPCConfig()[(Index)].PCPartitionConfigIdxOfPartitionIdentifiers)
#define NvM_GetPartitionSNVOfPartitionIdentifiers(Index)                                            (NvM_GetPartitionIdentifiersOfPCConfig()[(Index)].PartitionSNVOfPartitionIdentifiers)
#define NvM_GetQueueList(Index, partitionIndex)                                                     (NvM_GetQueueListOfPCPartitionConfig(partitionIndex)[(Index)])
#define NvM_GetQueue_Instance(partitionIndex)                                                       ((*(NvM_GetQueue_InstanceOfPCPartitionConfig(partitionIndex))))
#define NvM_GetReadAllFsm_Context(partitionIndex)                                                   ((*(NvM_GetReadAllFsm_ContextOfPCPartitionConfig(partitionIndex))))
#define NvM_GetReadAllFsm_Instance(partitionIndex)                                                  ((*(NvM_GetReadAllFsm_InstanceOfPCPartitionConfig(partitionIndex))))
#define NvM_GetReadBlockFsm_Context(partitionIndex)                                                 ((*(NvM_GetReadBlockFsm_ContextOfPCPartitionConfig(partitionIndex))))
#define NvM_GetReadBlockFsm_Instance(partitionIndex)                                                ((*(NvM_GetReadBlockFsm_InstanceOfPCPartitionConfig(partitionIndex))))
#define NvM_GetServiceProcessorFsmLib_Instance(partitionIndex)                                      ((*(NvM_GetServiceProcessorFsmLib_InstanceOfPCPartitionConfig(partitionIndex))))
#define NvM_GetServiceProcessorFsmLib_ProcessingStackElement(Index, partitionIndex)                 (NvM_GetServiceProcessorFsmLib_ProcessingStackElementOfPCPartitionConfig(partitionIndex)[(Index)])
#define NvM_GetServiceProcessorFsm_Context(partitionIndex)                                          ((*(NvM_GetServiceProcessorFsm_ContextOfPCPartitionConfig(partitionIndex))))
#define NvM_GetServiceProcessorFsm_Instance(partitionIndex)                                         ((*(NvM_GetServiceProcessorFsm_InstanceOfPCPartitionConfig(partitionIndex))))
#define NvM_GetSingleBlockFsmLib_ProcessingStackElement(Index, partitionIndex)                      (NvM_GetSingleBlockFsmLib_ProcessingStackElementOfPCPartitionConfig(partitionIndex)[(Index)])
#define NvM_GetSingleBlockJobContext(partitionIndex)                                                ((*(NvM_GetSingleBlockJobContextOfPCPartitionConfig(partitionIndex))))
#define NvM_GetSingleBlockJobFsm_Instance(partitionIndex)                                           ((*(NvM_GetSingleBlockJobFsm_InstanceOfPCPartitionConfig(partitionIndex))))
#define NvM_GetSingleBlockServiceFsmLib_Instance(partitionIndex)                                    ((*(NvM_GetSingleBlockServiceFsmLib_InstanceOfPCPartitionConfig(partitionIndex))))
#define NvM_GetValidateAllFsm_Instance(partitionIndex)                                              ((*(NvM_GetValidateAllFsm_InstanceOfPCPartitionConfig(partitionIndex))))
#define NvM_GetWriteAllFsm_Context(partitionIndex)                                                  ((*(NvM_GetWriteAllFsm_ContextOfPCPartitionConfig(partitionIndex))))
#define NvM_GetWriteAllFsm_Instance(partitionIndex)                                                 ((*(NvM_GetWriteAllFsm_InstanceOfPCPartitionConfig(partitionIndex))))
#define NvM_GetWriteBlockFsm_Context(partitionIndex)                                                ((*(NvM_GetWriteBlockFsm_ContextOfPCPartitionConfig(partitionIndex))))
#define NvM_GetWriteBlockFsm_Instance(partitionIndex)                                               ((*(NvM_GetWriteBlockFsm_InstanceOfPCPartitionConfig(partitionIndex))))
#define NvM_GetWriteNvBlockFsm_Context(partitionIndex)                                              ((*(NvM_GetWriteNvBlockFsm_ContextOfPCPartitionConfig(partitionIndex))))
/** 
  \}
*/ 

/** 
  \defgroup  NvMPCGetDeduplicatedDataMacros  NvM Get Deduplicated Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated data elements.
  \{
*/ 
#define NvM_GetSizeOfBackgroundCrcRecalcFsmLib_ProcessingStackElement(partitionIndex)               NvM_GetSizeOfBackgroundCrcRecalcFsmLib_ProcessingStackElementOfPCPartitionConfig(partitionIndex)
#define NvM_GetSizeOfBlockDescriptor()                                                              NvM_GetSizeOfBlockDescriptorOfPCPartitionConfig()
#define NvM_GetSizeOfCrcCompMechanismBuffer_DemAdminDataBlock(partitionIndex)                       NvM_GetSizeOfCrcCompMechanismBuffer_DemAdminDataBlockOfPCPartitionConfig(partitionIndex)
#define NvM_GetSizeOfCrcCompMechanismBuffer_DemStatusDataBlock(partitionIndex)                      NvM_GetSizeOfCrcCompMechanismBuffer_DemStatusDataBlockOfPCPartitionConfig(partitionIndex)
#define NvM_GetSizeOfCrcCompMechanismBuffer_NvMConfigBlock(partitionIndex)                          NvM_GetSizeOfCrcCompMechanismBuffer_NvMConfigBlockOfPCPartitionConfig(partitionIndex)
#define NvM_GetSizeOfCrcCompMechanismBuffer_WDFC_ID_AP_CONNEX(partitionIndex)                       NvM_GetSizeOfCrcCompMechanismBuffer_WDFC_ID_AP_CONNEXOfPCPartitionConfig(partitionIndex)
#define NvM_GetSizeOfCrcCompMechanismBuffer_WDFC_ID_AP_PARA(partitionIndex)                         NvM_GetSizeOfCrcCompMechanismBuffer_WDFC_ID_AP_PARAOfPCPartitionConfig(partitionIndex)
#define NvM_GetSizeOfCrcCompMechanismBuffer_WDFC_ID_BOOT_PARA(partitionIndex)                       NvM_GetSizeOfCrcCompMechanismBuffer_WDFC_ID_BOOT_PARAOfPCPartitionConfig(partitionIndex)
#define NvM_GetSizeOfCrcCompMechanismBuffer_WDFC_ID_CCP(partitionIndex)                             NvM_GetSizeOfCrcCompMechanismBuffer_WDFC_ID_CCPOfPCPartitionConfig(partitionIndex)
#define NvM_GetSizeOfCrcCompMechanismBuffer_WDFC_ID_DEBUG_DATA(partitionIndex)                      NvM_GetSizeOfCrcCompMechanismBuffer_WDFC_ID_DEBUG_DATAOfPCPartitionConfig(partitionIndex)
#define NvM_GetSizeOfCrcCompMechanismBuffer_WDFC_ID_DLC(partitionIndex)                             NvM_GetSizeOfCrcCompMechanismBuffer_WDFC_ID_DLCOfPCPartitionConfig(partitionIndex)
#define NvM_GetSizeOfCrcCompMechanismBuffer_WDFC_ID_DTCTime(partitionIndex)                         NvM_GetSizeOfCrcCompMechanismBuffer_WDFC_ID_DTCTimeOfPCPartitionConfig(partitionIndex)
#define NvM_GetSizeOfCrcCompMechanismBuffer_WDFC_ID_ECUID_RDI_PROGRAMMING_INFO(partitionIndex)      NvM_GetSizeOfCrcCompMechanismBuffer_WDFC_ID_ECUID_RDI_PROGRAMMING_INFOOfPCPartitionConfig(partitionIndex)
#define NvM_GetSizeOfCrcCompMechanismBuffer_WDFC_ID_EOL_HW_VERSION(partitionIndex)                  NvM_GetSizeOfCrcCompMechanismBuffer_WDFC_ID_EOL_HW_VERSIONOfPCPartitionConfig(partitionIndex)
#define NvM_GetSizeOfCrcCompMechanismBuffer_WDFC_ID_EOL_INFO(partitionIndex)                        NvM_GetSizeOfCrcCompMechanismBuffer_WDFC_ID_EOL_INFOOfPCPartitionConfig(partitionIndex)
#define NvM_GetSizeOfCrcCompMechanismBuffer_WDFC_ID_EOL_PASSWORD(partitionIndex)                    NvM_GetSizeOfCrcCompMechanismBuffer_WDFC_ID_EOL_PASSWORDOfPCPartitionConfig(partitionIndex)
#define NvM_GetSizeOfCrcCompMechanismBuffer_WDFC_ID_EOL_SWNUMBER(partitionIndex)                    NvM_GetSizeOfCrcCompMechanismBuffer_WDFC_ID_EOL_SWNUMBEROfPCPartitionConfig(partitionIndex)
#define NvM_GetSizeOfCrcCompMechanismBuffer_WDFC_ID_FAULT_CODE(partitionIndex)                      NvM_GetSizeOfCrcCompMechanismBuffer_WDFC_ID_FAULT_CODEOfPCPartitionConfig(partitionIndex)
#define NvM_GetSizeOfCrcCompMechanismBuffer_WDFC_ID_HANDLE_CFG(partitionIndex)                      NvM_GetSizeOfCrcCompMechanismBuffer_WDFC_ID_HANDLE_CFGOfPCPartitionConfig(partitionIndex)
#define NvM_GetSizeOfCrcCompMechanismBuffer_WDFC_ID_IDENT_BANK(partitionIndex)                      NvM_GetSizeOfCrcCompMechanismBuffer_WDFC_ID_IDENT_BANKOfPCPartitionConfig(partitionIndex)
#define NvM_GetSizeOfCrcCompMechanismBuffer_WDFC_ID_IDOPTION_SECURITY(partitionIndex)               NvM_GetSizeOfCrcCompMechanismBuffer_WDFC_ID_IDOPTION_SECURITYOfPCPartitionConfig(partitionIndex)
#define NvM_GetSizeOfCrcCompMechanismBuffer_WDFC_ID_LAST_FDC(partitionIndex)                        NvM_GetSizeOfCrcCompMechanismBuffer_WDFC_ID_LAST_FDCOfPCPartitionConfig(partitionIndex)
#define NvM_GetSizeOfCrcCompMechanismBuffer_WDFC_ID_MAX_FDC(partitionIndex)                         NvM_GetSizeOfCrcCompMechanismBuffer_WDFC_ID_MAX_FDCOfPCPartitionConfig(partitionIndex)
#define NvM_GetSizeOfCrcCompMechanismBuffer_WDFC_ID_MIRROR_CFG(partitionIndex)                      NvM_GetSizeOfCrcCompMechanismBuffer_WDFC_ID_MIRROR_CFGOfPCPartitionConfig(partitionIndex)
#define NvM_GetSizeOfCrcCompMechanismBuffer_WDFC_ID_MIRROR_OTHER_1(partitionIndex)                  NvM_GetSizeOfCrcCompMechanismBuffer_WDFC_ID_MIRROR_OTHER_1OfPCPartitionConfig(partitionIndex)
#define NvM_GetSizeOfCrcCompMechanismBuffer_WDFC_ID_MIRROR_POS_REC(partitionIndex)                  NvM_GetSizeOfCrcCompMechanismBuffer_WDFC_ID_MIRROR_POS_RECOfPCPartitionConfig(partitionIndex)
#define NvM_GetSizeOfCrcCompMechanismBuffer_WDFC_ID_MIRROR_ST(partitionIndex)                       NvM_GetSizeOfCrcCompMechanismBuffer_WDFC_ID_MIRROR_STOfPCPartitionConfig(partitionIndex)
#define NvM_GetSizeOfCrcCompMechanismBuffer_WDFC_ID_PART_NUMBER_GEELY(partitionIndex)               NvM_GetSizeOfCrcCompMechanismBuffer_WDFC_ID_PART_NUMBER_GEELYOfPCPartitionConfig(partitionIndex)
#define NvM_GetSizeOfCrcCompMechanismBuffer_WDFC_ID_PMM(partitionIndex)                             NvM_GetSizeOfCrcCompMechanismBuffer_WDFC_ID_PMMOfPCPartitionConfig(partitionIndex)
#define NvM_GetSizeOfCrcCompMechanismBuffer_WDFC_ID_QCM_FAULT_DATA(partitionIndex)                  NvM_GetSizeOfCrcCompMechanismBuffer_WDFC_ID_QCM_FAULT_DATAOfPCPartitionConfig(partitionIndex)
#define NvM_GetSizeOfCrcCompMechanismBuffer_WDFC_ID_SECURITY_ACCESS(partitionIndex)                 NvM_GetSizeOfCrcCompMechanismBuffer_WDFC_ID_SECURITY_ACCESSOfPCPartitionConfig(partitionIndex)
#define NvM_GetSizeOfCrcCompMechanismBuffer_WDFC_ID_SR_PROFILE(partitionIndex)                      NvM_GetSizeOfCrcCompMechanismBuffer_WDFC_ID_SR_PROFILEOfPCPartitionConfig(partitionIndex)
#define NvM_GetSizeOfCrcCompMechanismBuffer_WDFC_ID_SWP1(partitionIndex)                            NvM_GetSizeOfCrcCompMechanismBuffer_WDFC_ID_SWP1OfPCPartitionConfig(partitionIndex)
#define NvM_GetSizeOfCrcCompMechanismBuffer_WDFC_ID_THPA(partitionIndex)                            NvM_GetSizeOfCrcCompMechanismBuffer_WDFC_ID_THPAOfPCPartitionConfig(partitionIndex)
#define NvM_GetSizeOfCrcCompMechanismBuffer_WDFC_ID_VEH_CFG(partitionIndex)                         NvM_GetSizeOfCrcCompMechanismBuffer_WDFC_ID_VEH_CFGOfPCPartitionConfig(partitionIndex)
#define NvM_GetSizeOfCrcCompMechanismBuffer_WDFC_ID_VOL_POWER_MODE_CFG(partitionIndex)              NvM_GetSizeOfCrcCompMechanismBuffer_WDFC_ID_VOL_POWER_MODE_CFGOfPCPartitionConfig(partitionIndex)
#define NvM_GetSizeOfCrcCompMechanismBuffer_WDFC_ID_WLC_AP_LEARN(partitionIndex)                    NvM_GetSizeOfCrcCompMechanismBuffer_WDFC_ID_WLC_AP_LEARNOfPCPartitionConfig(partitionIndex)
#define NvM_GetSizeOfCrcCompMechanismBuffer_WDFC_ID_WL_INFO(partitionIndex)                         NvM_GetSizeOfCrcCompMechanismBuffer_WDFC_ID_WL_INFOOfPCPartitionConfig(partitionIndex)
#define NvM_GetSizeOfCrcCompMechanismBuffer_WDFC_ID_WL_LOG(partitionIndex)                          NvM_GetSizeOfCrcCompMechanismBuffer_WDFC_ID_WL_LOGOfPCPartitionConfig(partitionIndex)
#define NvM_GetSizeOfDataIntegrityIntBuffer_DemAdminDataBlock(partitionIndex)                       NvM_GetSizeOfDataIntegrityIntBuffer_DemAdminDataBlockOfPCPartitionConfig(partitionIndex)
#define NvM_GetSizeOfDataIntegrityIntBuffer_DemStatusDataBlock(partitionIndex)                      NvM_GetSizeOfDataIntegrityIntBuffer_DemStatusDataBlockOfPCPartitionConfig(partitionIndex)
#define NvM_GetSizeOfDataIntegrityIntBuffer_WDFC_ID_AP_CONNEX(partitionIndex)                       NvM_GetSizeOfDataIntegrityIntBuffer_WDFC_ID_AP_CONNEXOfPCPartitionConfig(partitionIndex)
#define NvM_GetSizeOfDataIntegrityIntBuffer_WDFC_ID_AP_PARA(partitionIndex)                         NvM_GetSizeOfDataIntegrityIntBuffer_WDFC_ID_AP_PARAOfPCPartitionConfig(partitionIndex)
#define NvM_GetSizeOfDataIntegrityIntBuffer_WDFC_ID_BOOT_PARA(partitionIndex)                       NvM_GetSizeOfDataIntegrityIntBuffer_WDFC_ID_BOOT_PARAOfPCPartitionConfig(partitionIndex)
#define NvM_GetSizeOfDataIntegrityIntBuffer_WDFC_ID_CCP(partitionIndex)                             NvM_GetSizeOfDataIntegrityIntBuffer_WDFC_ID_CCPOfPCPartitionConfig(partitionIndex)
#define NvM_GetSizeOfDataIntegrityIntBuffer_WDFC_ID_DEBUG_DATA(partitionIndex)                      NvM_GetSizeOfDataIntegrityIntBuffer_WDFC_ID_DEBUG_DATAOfPCPartitionConfig(partitionIndex)
#define NvM_GetSizeOfDataIntegrityIntBuffer_WDFC_ID_DLC(partitionIndex)                             NvM_GetSizeOfDataIntegrityIntBuffer_WDFC_ID_DLCOfPCPartitionConfig(partitionIndex)
#define NvM_GetSizeOfDataIntegrityIntBuffer_WDFC_ID_DTCTime(partitionIndex)                         NvM_GetSizeOfDataIntegrityIntBuffer_WDFC_ID_DTCTimeOfPCPartitionConfig(partitionIndex)
#define NvM_GetSizeOfDataIntegrityIntBuffer_WDFC_ID_ECUID_RDI_PROGRAMMING_INFO(partitionIndex)      NvM_GetSizeOfDataIntegrityIntBuffer_WDFC_ID_ECUID_RDI_PROGRAMMING_INFOOfPCPartitionConfig(partitionIndex)
#define NvM_GetSizeOfDataIntegrityIntBuffer_WDFC_ID_EOL_HW_VERSION(partitionIndex)                  NvM_GetSizeOfDataIntegrityIntBuffer_WDFC_ID_EOL_HW_VERSIONOfPCPartitionConfig(partitionIndex)
#define NvM_GetSizeOfDataIntegrityIntBuffer_WDFC_ID_EOL_INFO(partitionIndex)                        NvM_GetSizeOfDataIntegrityIntBuffer_WDFC_ID_EOL_INFOOfPCPartitionConfig(partitionIndex)
#define NvM_GetSizeOfDataIntegrityIntBuffer_WDFC_ID_EOL_PASSWORD(partitionIndex)                    NvM_GetSizeOfDataIntegrityIntBuffer_WDFC_ID_EOL_PASSWORDOfPCPartitionConfig(partitionIndex)
#define NvM_GetSizeOfDataIntegrityIntBuffer_WDFC_ID_EOL_SWNUMBER(partitionIndex)                    NvM_GetSizeOfDataIntegrityIntBuffer_WDFC_ID_EOL_SWNUMBEROfPCPartitionConfig(partitionIndex)
#define NvM_GetSizeOfDataIntegrityIntBuffer_WDFC_ID_FAULT_CODE(partitionIndex)                      NvM_GetSizeOfDataIntegrityIntBuffer_WDFC_ID_FAULT_CODEOfPCPartitionConfig(partitionIndex)
#define NvM_GetSizeOfDataIntegrityIntBuffer_WDFC_ID_HANDLE_CFG(partitionIndex)                      NvM_GetSizeOfDataIntegrityIntBuffer_WDFC_ID_HANDLE_CFGOfPCPartitionConfig(partitionIndex)
#define NvM_GetSizeOfDataIntegrityIntBuffer_WDFC_ID_IDENT_BANK(partitionIndex)                      NvM_GetSizeOfDataIntegrityIntBuffer_WDFC_ID_IDENT_BANKOfPCPartitionConfig(partitionIndex)
#define NvM_GetSizeOfDataIntegrityIntBuffer_WDFC_ID_IDOPTION_SECURITY(partitionIndex)               NvM_GetSizeOfDataIntegrityIntBuffer_WDFC_ID_IDOPTION_SECURITYOfPCPartitionConfig(partitionIndex)
#define NvM_GetSizeOfDataIntegrityIntBuffer_WDFC_ID_LAST_FDC(partitionIndex)                        NvM_GetSizeOfDataIntegrityIntBuffer_WDFC_ID_LAST_FDCOfPCPartitionConfig(partitionIndex)
#define NvM_GetSizeOfDataIntegrityIntBuffer_WDFC_ID_MAX_FDC(partitionIndex)                         NvM_GetSizeOfDataIntegrityIntBuffer_WDFC_ID_MAX_FDCOfPCPartitionConfig(partitionIndex)
#define NvM_GetSizeOfDataIntegrityIntBuffer_WDFC_ID_MIRROR_CFG(partitionIndex)                      NvM_GetSizeOfDataIntegrityIntBuffer_WDFC_ID_MIRROR_CFGOfPCPartitionConfig(partitionIndex)
#define NvM_GetSizeOfDataIntegrityIntBuffer_WDFC_ID_MIRROR_OTHER_1(partitionIndex)                  NvM_GetSizeOfDataIntegrityIntBuffer_WDFC_ID_MIRROR_OTHER_1OfPCPartitionConfig(partitionIndex)
#define NvM_GetSizeOfDataIntegrityIntBuffer_WDFC_ID_MIRROR_POS_REC(partitionIndex)                  NvM_GetSizeOfDataIntegrityIntBuffer_WDFC_ID_MIRROR_POS_RECOfPCPartitionConfig(partitionIndex)
#define NvM_GetSizeOfDataIntegrityIntBuffer_WDFC_ID_MIRROR_ST(partitionIndex)                       NvM_GetSizeOfDataIntegrityIntBuffer_WDFC_ID_MIRROR_STOfPCPartitionConfig(partitionIndex)
#define NvM_GetSizeOfDataIntegrityIntBuffer_WDFC_ID_PART_NUMBER_GEELY(partitionIndex)               NvM_GetSizeOfDataIntegrityIntBuffer_WDFC_ID_PART_NUMBER_GEELYOfPCPartitionConfig(partitionIndex)
#define NvM_GetSizeOfDataIntegrityIntBuffer_WDFC_ID_PMM(partitionIndex)                             NvM_GetSizeOfDataIntegrityIntBuffer_WDFC_ID_PMMOfPCPartitionConfig(partitionIndex)
#define NvM_GetSizeOfDataIntegrityIntBuffer_WDFC_ID_QCM_FAULT_DATA(partitionIndex)                  NvM_GetSizeOfDataIntegrityIntBuffer_WDFC_ID_QCM_FAULT_DATAOfPCPartitionConfig(partitionIndex)
#define NvM_GetSizeOfDataIntegrityIntBuffer_WDFC_ID_SECURITY_ACCESS(partitionIndex)                 NvM_GetSizeOfDataIntegrityIntBuffer_WDFC_ID_SECURITY_ACCESSOfPCPartitionConfig(partitionIndex)
#define NvM_GetSizeOfDataIntegrityIntBuffer_WDFC_ID_SR_PROFILE(partitionIndex)                      NvM_GetSizeOfDataIntegrityIntBuffer_WDFC_ID_SR_PROFILEOfPCPartitionConfig(partitionIndex)
#define NvM_GetSizeOfDataIntegrityIntBuffer_WDFC_ID_SWP1(partitionIndex)                            NvM_GetSizeOfDataIntegrityIntBuffer_WDFC_ID_SWP1OfPCPartitionConfig(partitionIndex)
#define NvM_GetSizeOfDataIntegrityIntBuffer_WDFC_ID_THPA(partitionIndex)                            NvM_GetSizeOfDataIntegrityIntBuffer_WDFC_ID_THPAOfPCPartitionConfig(partitionIndex)
#define NvM_GetSizeOfDataIntegrityIntBuffer_WDFC_ID_VEH_CFG(partitionIndex)                         NvM_GetSizeOfDataIntegrityIntBuffer_WDFC_ID_VEH_CFGOfPCPartitionConfig(partitionIndex)
#define NvM_GetSizeOfDataIntegrityIntBuffer_WDFC_ID_VOL_POWER_MODE_CFG(partitionIndex)              NvM_GetSizeOfDataIntegrityIntBuffer_WDFC_ID_VOL_POWER_MODE_CFGOfPCPartitionConfig(partitionIndex)
#define NvM_GetSizeOfDataIntegrityIntBuffer_WDFC_ID_WLC_AP_LEARN(partitionIndex)                    NvM_GetSizeOfDataIntegrityIntBuffer_WDFC_ID_WLC_AP_LEARNOfPCPartitionConfig(partitionIndex)
#define NvM_GetSizeOfDataIntegrityIntBuffer_WDFC_ID_WL_INFO(partitionIndex)                         NvM_GetSizeOfDataIntegrityIntBuffer_WDFC_ID_WL_INFOOfPCPartitionConfig(partitionIndex)
#define NvM_GetSizeOfDataIntegrityIntBuffer_WDFC_ID_WL_LOG(partitionIndex)                          NvM_GetSizeOfDataIntegrityIntBuffer_WDFC_ID_WL_LOGOfPCPartitionConfig(partitionIndex)
#define NvM_GetSizeOfInternalBuffer(partitionIndex)                                                 NvM_GetSizeOfInternalBufferOfPCPartitionConfig(partitionIndex)
#define NvM_GetSizeOfMultiBlockFsmLib_ProcessingStackElement(partitionIndex)                        NvM_GetSizeOfMultiBlockFsmLib_ProcessingStackElementOfPCPartitionConfig(partitionIndex)
#define NvM_GetSizeOfMultiBlockProcessorFsmLib_ProcessingStackElement(partitionIndex)               NvM_GetSizeOfMultiBlockProcessorFsmLib_ProcessingStackElementOfPCPartitionConfig(partitionIndex)
#define NvM_GetSizeOfNvServiceFsmLib_ProcessingStackElement(partitionIndex)                         NvM_GetSizeOfNvServiceFsmLib_ProcessingStackElementOfPCPartitionConfig(partitionIndex)
#define NvM_GetSizeOfNvServiceProcessorFsmLib_ProcessingStackElement(partitionIndex)                NvM_GetSizeOfNvServiceProcessorFsmLib_ProcessingStackElementOfPCPartitionConfig(partitionIndex)
#define NvM_GetSizeOfPartitionIdentifiers()                                                         NvM_GetSizeOfPartitionIdentifiersOfPCConfig()
#define NvM_GetSizeOfQueueList(partitionIndex)                                                      NvM_GetSizeOfQueueListOfPCPartitionConfig(partitionIndex)
#define NvM_GetSizeOfServiceProcessorFsmLib_ProcessingStackElement(partitionIndex)                  NvM_GetSizeOfServiceProcessorFsmLib_ProcessingStackElementOfPCPartitionConfig(partitionIndex)
#define NvM_GetSizeOfSingleBlockFsmLib_ProcessingStackElement(partitionIndex)                       NvM_GetSizeOfSingleBlockFsmLib_ProcessingStackElementOfPCPartitionConfig(partitionIndex)
/** 
  \}
*/ 

/** 
  \defgroup  NvMPCSetDataMacros  NvM Set Data Macros (PRE_COMPILE)
  \brief  These macros can be used to write data.
  \{
*/ 
#define NvM_SetBackgroundCrcRecalcFsmLib_Instance(Value, partitionIndex)                            (*(NvM_GetBackgroundCrcRecalcFsmLib_InstanceOfPCPartitionConfig(partitionIndex))) = (Value)
#define NvM_SetBackgroundCrcRecalcFsmLib_ProcessingStackElement(Index, Value, partitionIndex)       NvM_GetBackgroundCrcRecalcFsmLib_ProcessingStackElementOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define NvM_SetBackgroundCrcRecalcFsm_Context(Value, partitionIndex)                                (*(NvM_GetBackgroundCrcRecalcFsm_ContextOfPCPartitionConfig(partitionIndex))) = (Value)
#define NvM_SetBackgroundCrcRecalcFsm_Instance(Value, partitionIndex)                               (*(NvM_GetBackgroundCrcRecalcFsm_InstanceOfPCPartitionConfig(partitionIndex))) = (Value)
#define NvM_SetBackgroundDataIntegrityService_Instance(Value, partitionIndex)                       (*(NvM_GetBackgroundDataIntegrityService_InstanceOfPCPartitionConfig(partitionIndex))) = (Value)
#define NvM_SetBlockManagementInfo_DemAdminDataBlock(Value, partitionIndex)                         (*(NvM_GetBlockManagementInfo_DemAdminDataBlockOfPCPartitionConfig(partitionIndex))) = (Value)
#define NvM_SetBlockManagementInfo_DemStatusDataBlock(Value, partitionIndex)                        (*(NvM_GetBlockManagementInfo_DemStatusDataBlockOfPCPartitionConfig(partitionIndex))) = (Value)
#define NvM_SetBlockManagementInfo_NvMConfigBlock(Value, partitionIndex)                            (*(NvM_GetBlockManagementInfo_NvMConfigBlockOfPCPartitionConfig(partitionIndex))) = (Value)
#define NvM_SetBlockManagementInfo_NvMMultiBlock(Value, partitionIndex)                             (*(NvM_GetBlockManagementInfo_NvMMultiBlockOfPCPartitionConfig(partitionIndex))) = (Value)
#define NvM_SetBlockManagementInfo_WDFC_ID_AP_CONNEX(Value, partitionIndex)                         (*(NvM_GetBlockManagementInfo_WDFC_ID_AP_CONNEXOfPCPartitionConfig(partitionIndex))) = (Value)
#define NvM_SetBlockManagementInfo_WDFC_ID_AP_PARA(Value, partitionIndex)                           (*(NvM_GetBlockManagementInfo_WDFC_ID_AP_PARAOfPCPartitionConfig(partitionIndex))) = (Value)
#define NvM_SetBlockManagementInfo_WDFC_ID_BOOT_PARA(Value, partitionIndex)                         (*(NvM_GetBlockManagementInfo_WDFC_ID_BOOT_PARAOfPCPartitionConfig(partitionIndex))) = (Value)
#define NvM_SetBlockManagementInfo_WDFC_ID_CCP(Value, partitionIndex)                               (*(NvM_GetBlockManagementInfo_WDFC_ID_CCPOfPCPartitionConfig(partitionIndex))) = (Value)
#define NvM_SetBlockManagementInfo_WDFC_ID_DEBUG_DATA(Value, partitionIndex)                        (*(NvM_GetBlockManagementInfo_WDFC_ID_DEBUG_DATAOfPCPartitionConfig(partitionIndex))) = (Value)
#define NvM_SetBlockManagementInfo_WDFC_ID_DLC(Value, partitionIndex)                               (*(NvM_GetBlockManagementInfo_WDFC_ID_DLCOfPCPartitionConfig(partitionIndex))) = (Value)
#define NvM_SetBlockManagementInfo_WDFC_ID_DTCTime(Value, partitionIndex)                           (*(NvM_GetBlockManagementInfo_WDFC_ID_DTCTimeOfPCPartitionConfig(partitionIndex))) = (Value)
#define NvM_SetBlockManagementInfo_WDFC_ID_ECUID_RDI_PROGRAMMING_INFO(Value, partitionIndex)        (*(NvM_GetBlockManagementInfo_WDFC_ID_ECUID_RDI_PROGRAMMING_INFOOfPCPartitionConfig(partitionIndex))) = (Value)
#define NvM_SetBlockManagementInfo_WDFC_ID_EOL_HW_VERSION(Value, partitionIndex)                    (*(NvM_GetBlockManagementInfo_WDFC_ID_EOL_HW_VERSIONOfPCPartitionConfig(partitionIndex))) = (Value)
#define NvM_SetBlockManagementInfo_WDFC_ID_EOL_INFO(Value, partitionIndex)                          (*(NvM_GetBlockManagementInfo_WDFC_ID_EOL_INFOOfPCPartitionConfig(partitionIndex))) = (Value)
#define NvM_SetBlockManagementInfo_WDFC_ID_EOL_PASSWORD(Value, partitionIndex)                      (*(NvM_GetBlockManagementInfo_WDFC_ID_EOL_PASSWORDOfPCPartitionConfig(partitionIndex))) = (Value)
#define NvM_SetBlockManagementInfo_WDFC_ID_EOL_SWNUMBER(Value, partitionIndex)                      (*(NvM_GetBlockManagementInfo_WDFC_ID_EOL_SWNUMBEROfPCPartitionConfig(partitionIndex))) = (Value)
#define NvM_SetBlockManagementInfo_WDFC_ID_FAULT_CODE(Value, partitionIndex)                        (*(NvM_GetBlockManagementInfo_WDFC_ID_FAULT_CODEOfPCPartitionConfig(partitionIndex))) = (Value)
#define NvM_SetBlockManagementInfo_WDFC_ID_HANDLE_CFG(Value, partitionIndex)                        (*(NvM_GetBlockManagementInfo_WDFC_ID_HANDLE_CFGOfPCPartitionConfig(partitionIndex))) = (Value)
#define NvM_SetBlockManagementInfo_WDFC_ID_IDENT_BANK(Value, partitionIndex)                        (*(NvM_GetBlockManagementInfo_WDFC_ID_IDENT_BANKOfPCPartitionConfig(partitionIndex))) = (Value)
#define NvM_SetBlockManagementInfo_WDFC_ID_IDOPTION_SECURITY(Value, partitionIndex)                 (*(NvM_GetBlockManagementInfo_WDFC_ID_IDOPTION_SECURITYOfPCPartitionConfig(partitionIndex))) = (Value)
#define NvM_SetBlockManagementInfo_WDFC_ID_LAST_FDC(Value, partitionIndex)                          (*(NvM_GetBlockManagementInfo_WDFC_ID_LAST_FDCOfPCPartitionConfig(partitionIndex))) = (Value)
#define NvM_SetBlockManagementInfo_WDFC_ID_MAX_FDC(Value, partitionIndex)                           (*(NvM_GetBlockManagementInfo_WDFC_ID_MAX_FDCOfPCPartitionConfig(partitionIndex))) = (Value)
#define NvM_SetBlockManagementInfo_WDFC_ID_MIRROR_CFG(Value, partitionIndex)                        (*(NvM_GetBlockManagementInfo_WDFC_ID_MIRROR_CFGOfPCPartitionConfig(partitionIndex))) = (Value)
#define NvM_SetBlockManagementInfo_WDFC_ID_MIRROR_OTHER_1(Value, partitionIndex)                    (*(NvM_GetBlockManagementInfo_WDFC_ID_MIRROR_OTHER_1OfPCPartitionConfig(partitionIndex))) = (Value)
#define NvM_SetBlockManagementInfo_WDFC_ID_MIRROR_POS_REC(Value, partitionIndex)                    (*(NvM_GetBlockManagementInfo_WDFC_ID_MIRROR_POS_RECOfPCPartitionConfig(partitionIndex))) = (Value)
#define NvM_SetBlockManagementInfo_WDFC_ID_MIRROR_ST(Value, partitionIndex)                         (*(NvM_GetBlockManagementInfo_WDFC_ID_MIRROR_STOfPCPartitionConfig(partitionIndex))) = (Value)
#define NvM_SetBlockManagementInfo_WDFC_ID_PART_NUMBER_GEELY(Value, partitionIndex)                 (*(NvM_GetBlockManagementInfo_WDFC_ID_PART_NUMBER_GEELYOfPCPartitionConfig(partitionIndex))) = (Value)
#define NvM_SetBlockManagementInfo_WDFC_ID_PMM(Value, partitionIndex)                               (*(NvM_GetBlockManagementInfo_WDFC_ID_PMMOfPCPartitionConfig(partitionIndex))) = (Value)
#define NvM_SetBlockManagementInfo_WDFC_ID_QCM_FAULT_DATA(Value, partitionIndex)                    (*(NvM_GetBlockManagementInfo_WDFC_ID_QCM_FAULT_DATAOfPCPartitionConfig(partitionIndex))) = (Value)
#define NvM_SetBlockManagementInfo_WDFC_ID_SECURITY_ACCESS(Value, partitionIndex)                   (*(NvM_GetBlockManagementInfo_WDFC_ID_SECURITY_ACCESSOfPCPartitionConfig(partitionIndex))) = (Value)
#define NvM_SetBlockManagementInfo_WDFC_ID_SR_PROFILE(Value, partitionIndex)                        (*(NvM_GetBlockManagementInfo_WDFC_ID_SR_PROFILEOfPCPartitionConfig(partitionIndex))) = (Value)
#define NvM_SetBlockManagementInfo_WDFC_ID_SWP1(Value, partitionIndex)                              (*(NvM_GetBlockManagementInfo_WDFC_ID_SWP1OfPCPartitionConfig(partitionIndex))) = (Value)
#define NvM_SetBlockManagementInfo_WDFC_ID_THPA(Value, partitionIndex)                              (*(NvM_GetBlockManagementInfo_WDFC_ID_THPAOfPCPartitionConfig(partitionIndex))) = (Value)
#define NvM_SetBlockManagementInfo_WDFC_ID_VEH_CFG(Value, partitionIndex)                           (*(NvM_GetBlockManagementInfo_WDFC_ID_VEH_CFGOfPCPartitionConfig(partitionIndex))) = (Value)
#define NvM_SetBlockManagementInfo_WDFC_ID_VOL_POWER_MODE_CFG(Value, partitionIndex)                (*(NvM_GetBlockManagementInfo_WDFC_ID_VOL_POWER_MODE_CFGOfPCPartitionConfig(partitionIndex))) = (Value)
#define NvM_SetBlockManagementInfo_WDFC_ID_WLC_AP_LEARN(Value, partitionIndex)                      (*(NvM_GetBlockManagementInfo_WDFC_ID_WLC_AP_LEARNOfPCPartitionConfig(partitionIndex))) = (Value)
#define NvM_SetBlockManagementInfo_WDFC_ID_WL_INFO(Value, partitionIndex)                           (*(NvM_GetBlockManagementInfo_WDFC_ID_WL_INFOOfPCPartitionConfig(partitionIndex))) = (Value)
#define NvM_SetBlockManagementInfo_WDFC_ID_WL_LOG(Value, partitionIndex)                            (*(NvM_GetBlockManagementInfo_WDFC_ID_WL_LOGOfPCPartitionConfig(partitionIndex))) = (Value)
#define NvM_SetCrcCompMechanismBuffer_DemAdminDataBlock(Index, Value, partitionIndex)               NvM_GetCrcCompMechanismBuffer_DemAdminDataBlockOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define NvM_SetCrcCompMechanismBuffer_DemStatusDataBlock(Index, Value, partitionIndex)              NvM_GetCrcCompMechanismBuffer_DemStatusDataBlockOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define NvM_SetCrcCompMechanismBuffer_NvMConfigBlock(Index, Value, partitionIndex)                  NvM_GetCrcCompMechanismBuffer_NvMConfigBlockOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define NvM_SetCrcCompMechanismBuffer_WDFC_ID_AP_CONNEX(Index, Value, partitionIndex)               NvM_GetCrcCompMechanismBuffer_WDFC_ID_AP_CONNEXOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define NvM_SetCrcCompMechanismBuffer_WDFC_ID_AP_PARA(Index, Value, partitionIndex)                 NvM_GetCrcCompMechanismBuffer_WDFC_ID_AP_PARAOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define NvM_SetCrcCompMechanismBuffer_WDFC_ID_BOOT_PARA(Index, Value, partitionIndex)               NvM_GetCrcCompMechanismBuffer_WDFC_ID_BOOT_PARAOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define NvM_SetCrcCompMechanismBuffer_WDFC_ID_CCP(Index, Value, partitionIndex)                     NvM_GetCrcCompMechanismBuffer_WDFC_ID_CCPOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define NvM_SetCrcCompMechanismBuffer_WDFC_ID_DEBUG_DATA(Index, Value, partitionIndex)              NvM_GetCrcCompMechanismBuffer_WDFC_ID_DEBUG_DATAOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define NvM_SetCrcCompMechanismBuffer_WDFC_ID_DLC(Index, Value, partitionIndex)                     NvM_GetCrcCompMechanismBuffer_WDFC_ID_DLCOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define NvM_SetCrcCompMechanismBuffer_WDFC_ID_DTCTime(Index, Value, partitionIndex)                 NvM_GetCrcCompMechanismBuffer_WDFC_ID_DTCTimeOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define NvM_SetCrcCompMechanismBuffer_WDFC_ID_ECUID_RDI_PROGRAMMING_INFO(Index, Value, partitionIndex) NvM_GetCrcCompMechanismBuffer_WDFC_ID_ECUID_RDI_PROGRAMMING_INFOOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define NvM_SetCrcCompMechanismBuffer_WDFC_ID_EOL_HW_VERSION(Index, Value, partitionIndex)          NvM_GetCrcCompMechanismBuffer_WDFC_ID_EOL_HW_VERSIONOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define NvM_SetCrcCompMechanismBuffer_WDFC_ID_EOL_INFO(Index, Value, partitionIndex)                NvM_GetCrcCompMechanismBuffer_WDFC_ID_EOL_INFOOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define NvM_SetCrcCompMechanismBuffer_WDFC_ID_EOL_PASSWORD(Index, Value, partitionIndex)            NvM_GetCrcCompMechanismBuffer_WDFC_ID_EOL_PASSWORDOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define NvM_SetCrcCompMechanismBuffer_WDFC_ID_EOL_SWNUMBER(Index, Value, partitionIndex)            NvM_GetCrcCompMechanismBuffer_WDFC_ID_EOL_SWNUMBEROfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define NvM_SetCrcCompMechanismBuffer_WDFC_ID_FAULT_CODE(Index, Value, partitionIndex)              NvM_GetCrcCompMechanismBuffer_WDFC_ID_FAULT_CODEOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define NvM_SetCrcCompMechanismBuffer_WDFC_ID_HANDLE_CFG(Index, Value, partitionIndex)              NvM_GetCrcCompMechanismBuffer_WDFC_ID_HANDLE_CFGOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define NvM_SetCrcCompMechanismBuffer_WDFC_ID_IDENT_BANK(Index, Value, partitionIndex)              NvM_GetCrcCompMechanismBuffer_WDFC_ID_IDENT_BANKOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define NvM_SetCrcCompMechanismBuffer_WDFC_ID_IDOPTION_SECURITY(Index, Value, partitionIndex)       NvM_GetCrcCompMechanismBuffer_WDFC_ID_IDOPTION_SECURITYOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define NvM_SetCrcCompMechanismBuffer_WDFC_ID_LAST_FDC(Index, Value, partitionIndex)                NvM_GetCrcCompMechanismBuffer_WDFC_ID_LAST_FDCOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define NvM_SetCrcCompMechanismBuffer_WDFC_ID_MAX_FDC(Index, Value, partitionIndex)                 NvM_GetCrcCompMechanismBuffer_WDFC_ID_MAX_FDCOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define NvM_SetCrcCompMechanismBuffer_WDFC_ID_MIRROR_CFG(Index, Value, partitionIndex)              NvM_GetCrcCompMechanismBuffer_WDFC_ID_MIRROR_CFGOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define NvM_SetCrcCompMechanismBuffer_WDFC_ID_MIRROR_OTHER_1(Index, Value, partitionIndex)          NvM_GetCrcCompMechanismBuffer_WDFC_ID_MIRROR_OTHER_1OfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define NvM_SetCrcCompMechanismBuffer_WDFC_ID_MIRROR_POS_REC(Index, Value, partitionIndex)          NvM_GetCrcCompMechanismBuffer_WDFC_ID_MIRROR_POS_RECOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define NvM_SetCrcCompMechanismBuffer_WDFC_ID_MIRROR_ST(Index, Value, partitionIndex)               NvM_GetCrcCompMechanismBuffer_WDFC_ID_MIRROR_STOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define NvM_SetCrcCompMechanismBuffer_WDFC_ID_PART_NUMBER_GEELY(Index, Value, partitionIndex)       NvM_GetCrcCompMechanismBuffer_WDFC_ID_PART_NUMBER_GEELYOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define NvM_SetCrcCompMechanismBuffer_WDFC_ID_PMM(Index, Value, partitionIndex)                     NvM_GetCrcCompMechanismBuffer_WDFC_ID_PMMOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define NvM_SetCrcCompMechanismBuffer_WDFC_ID_QCM_FAULT_DATA(Index, Value, partitionIndex)          NvM_GetCrcCompMechanismBuffer_WDFC_ID_QCM_FAULT_DATAOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define NvM_SetCrcCompMechanismBuffer_WDFC_ID_SECURITY_ACCESS(Index, Value, partitionIndex)         NvM_GetCrcCompMechanismBuffer_WDFC_ID_SECURITY_ACCESSOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define NvM_SetCrcCompMechanismBuffer_WDFC_ID_SR_PROFILE(Index, Value, partitionIndex)              NvM_GetCrcCompMechanismBuffer_WDFC_ID_SR_PROFILEOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define NvM_SetCrcCompMechanismBuffer_WDFC_ID_SWP1(Index, Value, partitionIndex)                    NvM_GetCrcCompMechanismBuffer_WDFC_ID_SWP1OfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define NvM_SetCrcCompMechanismBuffer_WDFC_ID_THPA(Index, Value, partitionIndex)                    NvM_GetCrcCompMechanismBuffer_WDFC_ID_THPAOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define NvM_SetCrcCompMechanismBuffer_WDFC_ID_VEH_CFG(Index, Value, partitionIndex)                 NvM_GetCrcCompMechanismBuffer_WDFC_ID_VEH_CFGOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define NvM_SetCrcCompMechanismBuffer_WDFC_ID_VOL_POWER_MODE_CFG(Index, Value, partitionIndex)      NvM_GetCrcCompMechanismBuffer_WDFC_ID_VOL_POWER_MODE_CFGOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define NvM_SetCrcCompMechanismBuffer_WDFC_ID_WLC_AP_LEARN(Index, Value, partitionIndex)            NvM_GetCrcCompMechanismBuffer_WDFC_ID_WLC_AP_LEARNOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define NvM_SetCrcCompMechanismBuffer_WDFC_ID_WL_INFO(Index, Value, partitionIndex)                 NvM_GetCrcCompMechanismBuffer_WDFC_ID_WL_INFOOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define NvM_SetCrcCompMechanismBuffer_WDFC_ID_WL_LOG(Index, Value, partitionIndex)                  NvM_GetCrcCompMechanismBuffer_WDFC_ID_WL_LOGOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define NvM_SetDataIntegrityFsm_Instance(Value, partitionIndex)                                     (*(NvM_GetDataIntegrityFsm_InstanceOfPCPartitionConfig(partitionIndex))) = (Value)
#define NvM_SetDataIntegrityIntBuffer_DemAdminDataBlock(Index, Value, partitionIndex)               NvM_GetDataIntegrityIntBuffer_DemAdminDataBlockOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define NvM_SetDataIntegrityIntBuffer_DemStatusDataBlock(Index, Value, partitionIndex)              NvM_GetDataIntegrityIntBuffer_DemStatusDataBlockOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define NvM_SetDataIntegrityIntBuffer_WDFC_ID_AP_CONNEX(Index, Value, partitionIndex)               NvM_GetDataIntegrityIntBuffer_WDFC_ID_AP_CONNEXOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define NvM_SetDataIntegrityIntBuffer_WDFC_ID_AP_PARA(Index, Value, partitionIndex)                 NvM_GetDataIntegrityIntBuffer_WDFC_ID_AP_PARAOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define NvM_SetDataIntegrityIntBuffer_WDFC_ID_BOOT_PARA(Index, Value, partitionIndex)               NvM_GetDataIntegrityIntBuffer_WDFC_ID_BOOT_PARAOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define NvM_SetDataIntegrityIntBuffer_WDFC_ID_CCP(Index, Value, partitionIndex)                     NvM_GetDataIntegrityIntBuffer_WDFC_ID_CCPOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define NvM_SetDataIntegrityIntBuffer_WDFC_ID_DEBUG_DATA(Index, Value, partitionIndex)              NvM_GetDataIntegrityIntBuffer_WDFC_ID_DEBUG_DATAOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define NvM_SetDataIntegrityIntBuffer_WDFC_ID_DLC(Index, Value, partitionIndex)                     NvM_GetDataIntegrityIntBuffer_WDFC_ID_DLCOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define NvM_SetDataIntegrityIntBuffer_WDFC_ID_DTCTime(Index, Value, partitionIndex)                 NvM_GetDataIntegrityIntBuffer_WDFC_ID_DTCTimeOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define NvM_SetDataIntegrityIntBuffer_WDFC_ID_ECUID_RDI_PROGRAMMING_INFO(Index, Value, partitionIndex) NvM_GetDataIntegrityIntBuffer_WDFC_ID_ECUID_RDI_PROGRAMMING_INFOOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define NvM_SetDataIntegrityIntBuffer_WDFC_ID_EOL_HW_VERSION(Index, Value, partitionIndex)          NvM_GetDataIntegrityIntBuffer_WDFC_ID_EOL_HW_VERSIONOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define NvM_SetDataIntegrityIntBuffer_WDFC_ID_EOL_INFO(Index, Value, partitionIndex)                NvM_GetDataIntegrityIntBuffer_WDFC_ID_EOL_INFOOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define NvM_SetDataIntegrityIntBuffer_WDFC_ID_EOL_PASSWORD(Index, Value, partitionIndex)            NvM_GetDataIntegrityIntBuffer_WDFC_ID_EOL_PASSWORDOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define NvM_SetDataIntegrityIntBuffer_WDFC_ID_EOL_SWNUMBER(Index, Value, partitionIndex)            NvM_GetDataIntegrityIntBuffer_WDFC_ID_EOL_SWNUMBEROfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define NvM_SetDataIntegrityIntBuffer_WDFC_ID_FAULT_CODE(Index, Value, partitionIndex)              NvM_GetDataIntegrityIntBuffer_WDFC_ID_FAULT_CODEOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define NvM_SetDataIntegrityIntBuffer_WDFC_ID_HANDLE_CFG(Index, Value, partitionIndex)              NvM_GetDataIntegrityIntBuffer_WDFC_ID_HANDLE_CFGOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define NvM_SetDataIntegrityIntBuffer_WDFC_ID_IDENT_BANK(Index, Value, partitionIndex)              NvM_GetDataIntegrityIntBuffer_WDFC_ID_IDENT_BANKOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define NvM_SetDataIntegrityIntBuffer_WDFC_ID_IDOPTION_SECURITY(Index, Value, partitionIndex)       NvM_GetDataIntegrityIntBuffer_WDFC_ID_IDOPTION_SECURITYOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define NvM_SetDataIntegrityIntBuffer_WDFC_ID_LAST_FDC(Index, Value, partitionIndex)                NvM_GetDataIntegrityIntBuffer_WDFC_ID_LAST_FDCOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define NvM_SetDataIntegrityIntBuffer_WDFC_ID_MAX_FDC(Index, Value, partitionIndex)                 NvM_GetDataIntegrityIntBuffer_WDFC_ID_MAX_FDCOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define NvM_SetDataIntegrityIntBuffer_WDFC_ID_MIRROR_CFG(Index, Value, partitionIndex)              NvM_GetDataIntegrityIntBuffer_WDFC_ID_MIRROR_CFGOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define NvM_SetDataIntegrityIntBuffer_WDFC_ID_MIRROR_OTHER_1(Index, Value, partitionIndex)          NvM_GetDataIntegrityIntBuffer_WDFC_ID_MIRROR_OTHER_1OfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define NvM_SetDataIntegrityIntBuffer_WDFC_ID_MIRROR_POS_REC(Index, Value, partitionIndex)          NvM_GetDataIntegrityIntBuffer_WDFC_ID_MIRROR_POS_RECOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define NvM_SetDataIntegrityIntBuffer_WDFC_ID_MIRROR_ST(Index, Value, partitionIndex)               NvM_GetDataIntegrityIntBuffer_WDFC_ID_MIRROR_STOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define NvM_SetDataIntegrityIntBuffer_WDFC_ID_PART_NUMBER_GEELY(Index, Value, partitionIndex)       NvM_GetDataIntegrityIntBuffer_WDFC_ID_PART_NUMBER_GEELYOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define NvM_SetDataIntegrityIntBuffer_WDFC_ID_PMM(Index, Value, partitionIndex)                     NvM_GetDataIntegrityIntBuffer_WDFC_ID_PMMOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define NvM_SetDataIntegrityIntBuffer_WDFC_ID_QCM_FAULT_DATA(Index, Value, partitionIndex)          NvM_GetDataIntegrityIntBuffer_WDFC_ID_QCM_FAULT_DATAOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define NvM_SetDataIntegrityIntBuffer_WDFC_ID_SECURITY_ACCESS(Index, Value, partitionIndex)         NvM_GetDataIntegrityIntBuffer_WDFC_ID_SECURITY_ACCESSOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define NvM_SetDataIntegrityIntBuffer_WDFC_ID_SR_PROFILE(Index, Value, partitionIndex)              NvM_GetDataIntegrityIntBuffer_WDFC_ID_SR_PROFILEOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define NvM_SetDataIntegrityIntBuffer_WDFC_ID_SWP1(Index, Value, partitionIndex)                    NvM_GetDataIntegrityIntBuffer_WDFC_ID_SWP1OfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define NvM_SetDataIntegrityIntBuffer_WDFC_ID_THPA(Index, Value, partitionIndex)                    NvM_GetDataIntegrityIntBuffer_WDFC_ID_THPAOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define NvM_SetDataIntegrityIntBuffer_WDFC_ID_VEH_CFG(Index, Value, partitionIndex)                 NvM_GetDataIntegrityIntBuffer_WDFC_ID_VEH_CFGOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define NvM_SetDataIntegrityIntBuffer_WDFC_ID_VOL_POWER_MODE_CFG(Index, Value, partitionIndex)      NvM_GetDataIntegrityIntBuffer_WDFC_ID_VOL_POWER_MODE_CFGOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define NvM_SetDataIntegrityIntBuffer_WDFC_ID_WLC_AP_LEARN(Index, Value, partitionIndex)            NvM_GetDataIntegrityIntBuffer_WDFC_ID_WLC_AP_LEARNOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define NvM_SetDataIntegrityIntBuffer_WDFC_ID_WL_INFO(Index, Value, partitionIndex)                 NvM_GetDataIntegrityIntBuffer_WDFC_ID_WL_INFOOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define NvM_SetDataIntegrityIntBuffer_WDFC_ID_WL_LOG(Index, Value, partitionIndex)                  NvM_GetDataIntegrityIntBuffer_WDFC_ID_WL_LOGOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define NvM_SetDataIntegrityRecalcQueue_Instance(Value, partitionIndex)                             (*(NvM_GetDataIntegrityRecalcQueue_InstanceOfPCPartitionConfig(partitionIndex))) = (Value)
#define NvM_SetDcmBlockManagementInfo(Value, partitionIndex)                                        (*(NvM_GetDcmBlockManagementInfoOfPCPartitionConfig(partitionIndex))) = (Value)
#define NvM_SetForegroundDataIntegrityService_Instance(Value, partitionIndex)                       (*(NvM_GetForegroundDataIntegrityService_InstanceOfPCPartitionConfig(partitionIndex))) = (Value)
#define NvM_SetInternalBuffer(Index, Value, partitionIndex)                                         NvM_GetInternalBufferOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define NvM_SetMultiBlockFsmLib_ProcessingStackElement(Index, Value, partitionIndex)                NvM_GetMultiBlockFsmLib_ProcessingStackElementOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define NvM_SetMultiBlockJob(Value, partitionIndex)                                                 (*(NvM_GetMultiBlockJobOfPCPartitionConfig(partitionIndex))) = (Value)
#define NvM_SetMultiBlockJobFsm_Context(Value, partitionIndex)                                      (*(NvM_GetMultiBlockJobFsm_ContextOfPCPartitionConfig(partitionIndex))) = (Value)
#define NvM_SetMultiBlockJobFsm_Instance(Value, partitionIndex)                                     (*(NvM_GetMultiBlockJobFsm_InstanceOfPCPartitionConfig(partitionIndex))) = (Value)
#define NvM_SetMultiBlockJobInformation(Value, partitionIndex)                                      (*(NvM_GetMultiBlockJobInformationOfPCPartitionConfig(partitionIndex))) = (Value)
#define NvM_SetMultiBlockProcessorFsmLib_Instance(Value, partitionIndex)                            (*(NvM_GetMultiBlockProcessorFsmLib_InstanceOfPCPartitionConfig(partitionIndex))) = (Value)
#define NvM_SetMultiBlockProcessorFsmLib_ProcessingStackElement(Index, Value, partitionIndex)       NvM_GetMultiBlockProcessorFsmLib_ProcessingStackElementOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define NvM_SetMultiBlockServiceFsmLib_Instance(Value, partitionIndex)                              (*(NvM_GetMultiBlockServiceFsmLib_InstanceOfPCPartitionConfig(partitionIndex))) = (Value)
#define NvM_SetNvJobContext(Value, partitionIndex)                                                  (*(NvM_GetNvJobContextOfPCPartitionConfig(partitionIndex))) = (Value)
#define NvM_SetNvJobFsm_Instance(Value, partitionIndex)                                             (*(NvM_GetNvJobFsm_InstanceOfPCPartitionConfig(partitionIndex))) = (Value)
#define NvM_SetNvServiceFsmLib_Instance(Value, partitionIndex)                                      (*(NvM_GetNvServiceFsmLib_InstanceOfPCPartitionConfig(partitionIndex))) = (Value)
#define NvM_SetNvServiceFsmLib_ProcessingStackElement(Index, Value, partitionIndex)                 NvM_GetNvServiceFsmLib_ProcessingStackElementOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define NvM_SetNvServiceProcessorFsmLib_Instance(Value, partitionIndex)                             (*(NvM_GetNvServiceProcessorFsmLib_InstanceOfPCPartitionConfig(partitionIndex))) = (Value)
#define NvM_SetNvServiceProcessorFsmLib_ProcessingStackElement(Index, Value, partitionIndex)        NvM_GetNvServiceProcessorFsmLib_ProcessingStackElementOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define NvM_SetQueueList(Index, Value, partitionIndex)                                              NvM_GetQueueListOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define NvM_SetQueue_Instance(Value, partitionIndex)                                                (*(NvM_GetQueue_InstanceOfPCPartitionConfig(partitionIndex))) = (Value)
#define NvM_SetReadAllFsm_Context(Value, partitionIndex)                                            (*(NvM_GetReadAllFsm_ContextOfPCPartitionConfig(partitionIndex))) = (Value)
#define NvM_SetReadAllFsm_Instance(Value, partitionIndex)                                           (*(NvM_GetReadAllFsm_InstanceOfPCPartitionConfig(partitionIndex))) = (Value)
#define NvM_SetReadBlockFsm_Context(Value, partitionIndex)                                          (*(NvM_GetReadBlockFsm_ContextOfPCPartitionConfig(partitionIndex))) = (Value)
#define NvM_SetReadBlockFsm_Instance(Value, partitionIndex)                                         (*(NvM_GetReadBlockFsm_InstanceOfPCPartitionConfig(partitionIndex))) = (Value)
#define NvM_SetServiceProcessorFsmLib_Instance(Value, partitionIndex)                               (*(NvM_GetServiceProcessorFsmLib_InstanceOfPCPartitionConfig(partitionIndex))) = (Value)
#define NvM_SetServiceProcessorFsmLib_ProcessingStackElement(Index, Value, partitionIndex)          NvM_GetServiceProcessorFsmLib_ProcessingStackElementOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define NvM_SetServiceProcessorFsm_Context(Value, partitionIndex)                                   (*(NvM_GetServiceProcessorFsm_ContextOfPCPartitionConfig(partitionIndex))) = (Value)
#define NvM_SetServiceProcessorFsm_Instance(Value, partitionIndex)                                  (*(NvM_GetServiceProcessorFsm_InstanceOfPCPartitionConfig(partitionIndex))) = (Value)
#define NvM_SetSingleBlockFsmLib_ProcessingStackElement(Index, Value, partitionIndex)               NvM_GetSingleBlockFsmLib_ProcessingStackElementOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define NvM_SetSingleBlockJobContext(Value, partitionIndex)                                         (*(NvM_GetSingleBlockJobContextOfPCPartitionConfig(partitionIndex))) = (Value)
#define NvM_SetSingleBlockJobFsm_Instance(Value, partitionIndex)                                    (*(NvM_GetSingleBlockJobFsm_InstanceOfPCPartitionConfig(partitionIndex))) = (Value)
#define NvM_SetSingleBlockServiceFsmLib_Instance(Value, partitionIndex)                             (*(NvM_GetSingleBlockServiceFsmLib_InstanceOfPCPartitionConfig(partitionIndex))) = (Value)
#define NvM_SetValidateAllFsm_Instance(Value, partitionIndex)                                       (*(NvM_GetValidateAllFsm_InstanceOfPCPartitionConfig(partitionIndex))) = (Value)
#define NvM_SetWriteAllFsm_Context(Value, partitionIndex)                                           (*(NvM_GetWriteAllFsm_ContextOfPCPartitionConfig(partitionIndex))) = (Value)
#define NvM_SetWriteAllFsm_Instance(Value, partitionIndex)                                          (*(NvM_GetWriteAllFsm_InstanceOfPCPartitionConfig(partitionIndex))) = (Value)
#define NvM_SetWriteBlockFsm_Context(Value, partitionIndex)                                         (*(NvM_GetWriteBlockFsm_ContextOfPCPartitionConfig(partitionIndex))) = (Value)
#define NvM_SetWriteBlockFsm_Instance(Value, partitionIndex)                                        (*(NvM_GetWriteBlockFsm_InstanceOfPCPartitionConfig(partitionIndex))) = (Value)
#define NvM_SetWriteNvBlockFsm_Context(Value, partitionIndex)                                       (*(NvM_GetWriteNvBlockFsm_ContextOfPCPartitionConfig(partitionIndex))) = (Value)
/** 
  \}
*/ 

/** 
  \defgroup  NvMPCGetAddressOfDataMacros  NvM Get Address Of Data Macros (PRE_COMPILE)
  \brief  These macros can be used to get the data by the address operator.
  \{
*/ 
#define NvM_GetAddrBackgroundCrcRecalcFsmLib_Instance(partitionIndex)                               (&NvM_GetBackgroundCrcRecalcFsmLib_Instance(partitionIndex))
#define NvM_GetAddrBackgroundCrcRecalcFsmLib_ProcessingStackElement(Index, partitionIndex)          (&NvM_GetBackgroundCrcRecalcFsmLib_ProcessingStackElement(((Index)), (partitionIndex)))
#define NvM_GetAddrBackgroundCrcRecalcFsm_Context(partitionIndex)                                   (&NvM_GetBackgroundCrcRecalcFsm_Context(partitionIndex))
#define NvM_GetAddrBackgroundCrcRecalcFsm_Instance(partitionIndex)                                  (&NvM_GetBackgroundCrcRecalcFsm_Instance(partitionIndex))
#define NvM_GetAddrBackgroundDataIntegrityService_Instance(partitionIndex)                          (&NvM_GetBackgroundDataIntegrityService_Instance(partitionIndex))
#define NvM_GetAddrBlockDescriptor(Index)                                                           (&NvM_GetBlockDescriptor(Index))
#define NvM_GetAddrDataIntegrityFsm_Instance(partitionIndex)                                        (&NvM_GetDataIntegrityFsm_Instance(partitionIndex))
#define NvM_GetAddrDataIntegrityRecalcQueue_Instance(partitionIndex)                                (&NvM_GetDataIntegrityRecalcQueue_Instance(partitionIndex))
#define NvM_GetAddrDcmBlockManagementInfo(partitionIndex)                                           (&NvM_GetDcmBlockManagementInfo(partitionIndex))
#define NvM_GetAddrForegroundDataIntegrityService_Instance(partitionIndex)                          (&NvM_GetForegroundDataIntegrityService_Instance(partitionIndex))
#define NvM_GetAddrInternalBuffer(Index, partitionIndex)                                            (&NvM_GetInternalBuffer(((Index)), (partitionIndex)))
#define NvM_GetAddrMultiBlockFsmLib_ProcessingStackElement(Index, partitionIndex)                   (&NvM_GetMultiBlockFsmLib_ProcessingStackElement(((Index)), (partitionIndex)))
#define NvM_GetAddrMultiBlockJob(partitionIndex)                                                    (&NvM_GetMultiBlockJob(partitionIndex))
#define NvM_GetAddrMultiBlockJobFsm_Context(partitionIndex)                                         (&NvM_GetMultiBlockJobFsm_Context(partitionIndex))
#define NvM_GetAddrMultiBlockJobFsm_Instance(partitionIndex)                                        (&NvM_GetMultiBlockJobFsm_Instance(partitionIndex))
#define NvM_GetAddrMultiBlockJobInformation(partitionIndex)                                         (&NvM_GetMultiBlockJobInformation(partitionIndex))
#define NvM_GetAddrMultiBlockProcessorFsmLib_Instance(partitionIndex)                               (&NvM_GetMultiBlockProcessorFsmLib_Instance(partitionIndex))
#define NvM_GetAddrMultiBlockProcessorFsmLib_ProcessingStackElement(Index, partitionIndex)          (&NvM_GetMultiBlockProcessorFsmLib_ProcessingStackElement(((Index)), (partitionIndex)))
#define NvM_GetAddrMultiBlockServiceFsmLib_Instance(partitionIndex)                                 (&NvM_GetMultiBlockServiceFsmLib_Instance(partitionIndex))
#define NvM_GetAddrNvJobContext(partitionIndex)                                                     (&NvM_GetNvJobContext(partitionIndex))
#define NvM_GetAddrNvJobFsm_Instance(partitionIndex)                                                (&NvM_GetNvJobFsm_Instance(partitionIndex))
#define NvM_GetAddrNvServiceFsmLib_Instance(partitionIndex)                                         (&NvM_GetNvServiceFsmLib_Instance(partitionIndex))
#define NvM_GetAddrNvServiceFsmLib_ProcessingStackElement(Index, partitionIndex)                    (&NvM_GetNvServiceFsmLib_ProcessingStackElement(((Index)), (partitionIndex)))
#define NvM_GetAddrNvServiceProcessorFsmLib_Instance(partitionIndex)                                (&NvM_GetNvServiceProcessorFsmLib_Instance(partitionIndex))
#define NvM_GetAddrNvServiceProcessorFsmLib_ProcessingStackElement(Index, partitionIndex)           (&NvM_GetNvServiceProcessorFsmLib_ProcessingStackElement(((Index)), (partitionIndex)))
#define NvM_GetAddrQueueList(Index, partitionIndex)                                                 (&NvM_GetQueueList(((Index)), (partitionIndex)))
#define NvM_GetAddrQueue_Instance(partitionIndex)                                                   (&NvM_GetQueue_Instance(partitionIndex))
#define NvM_GetAddrReadAllFsm_Context(partitionIndex)                                               (&NvM_GetReadAllFsm_Context(partitionIndex))
#define NvM_GetAddrReadAllFsm_Instance(partitionIndex)                                              (&NvM_GetReadAllFsm_Instance(partitionIndex))
#define NvM_GetAddrReadBlockFsm_Context(partitionIndex)                                             (&NvM_GetReadBlockFsm_Context(partitionIndex))
#define NvM_GetAddrReadBlockFsm_Instance(partitionIndex)                                            (&NvM_GetReadBlockFsm_Instance(partitionIndex))
#define NvM_GetAddrServiceProcessorFsmLib_Instance(partitionIndex)                                  (&NvM_GetServiceProcessorFsmLib_Instance(partitionIndex))
#define NvM_GetAddrServiceProcessorFsmLib_ProcessingStackElement(Index, partitionIndex)             (&NvM_GetServiceProcessorFsmLib_ProcessingStackElement(((Index)), (partitionIndex)))
#define NvM_GetAddrServiceProcessorFsm_Context(partitionIndex)                                      (&NvM_GetServiceProcessorFsm_Context(partitionIndex))
#define NvM_GetAddrServiceProcessorFsm_Instance(partitionIndex)                                     (&NvM_GetServiceProcessorFsm_Instance(partitionIndex))
#define NvM_GetAddrSingleBlockFsmLib_ProcessingStackElement(Index, partitionIndex)                  (&NvM_GetSingleBlockFsmLib_ProcessingStackElement(((Index)), (partitionIndex)))
#define NvM_GetAddrSingleBlockJobContext(partitionIndex)                                            (&NvM_GetSingleBlockJobContext(partitionIndex))
#define NvM_GetAddrSingleBlockJobFsm_Instance(partitionIndex)                                       (&NvM_GetSingleBlockJobFsm_Instance(partitionIndex))
#define NvM_GetAddrSingleBlockServiceFsmLib_Instance(partitionIndex)                                (&NvM_GetSingleBlockServiceFsmLib_Instance(partitionIndex))
#define NvM_GetAddrValidateAllFsm_Instance(partitionIndex)                                          (&NvM_GetValidateAllFsm_Instance(partitionIndex))
#define NvM_GetAddrWriteAllFsm_Context(partitionIndex)                                              (&NvM_GetWriteAllFsm_Context(partitionIndex))
#define NvM_GetAddrWriteAllFsm_Instance(partitionIndex)                                             (&NvM_GetWriteAllFsm_Instance(partitionIndex))
#define NvM_GetAddrWriteBlockFsm_Context(partitionIndex)                                            (&NvM_GetWriteBlockFsm_Context(partitionIndex))
#define NvM_GetAddrWriteBlockFsm_Instance(partitionIndex)                                           (&NvM_GetWriteBlockFsm_Instance(partitionIndex))
#define NvM_GetAddrWriteNvBlockFsm_Context(partitionIndex)                                          (&NvM_GetWriteNvBlockFsm_Context(partitionIndex))
/** 
  \}
*/ 

/** 
  \defgroup  NvMPCHasMacros  NvM Has Macros (PRE_COMPILE)
  \brief  These macros can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
#define NvM_HasBackgroundCrcRecalcFsmLib_Instance(partitionIndex)                                   (TRUE != FALSE)
#define NvM_HasBackgroundCrcRecalcFsmLib_ProcessingStackElement(partitionIndex)                     (TRUE != FALSE)
#define NvM_HasBackgroundCrcRecalcFsm_Context(partitionIndex)                                       (TRUE != FALSE)
#define NvM_HasBackgroundCrcRecalcFsm_Instance(partitionIndex)                                      (TRUE != FALSE)
#define NvM_HasBackgroundDataIntegrityService_Instance(partitionIndex)                              (TRUE != FALSE)
#define NvM_HasBlockDescriptor()                                                                    (TRUE != FALSE)
#define NvM_HasBlockManagementInfo_DemAdminDataBlock(partitionIndex)                                (TRUE != FALSE)
#define NvM_HasBlockManagementInfo_DemStatusDataBlock(partitionIndex)                               (TRUE != FALSE)
#define NvM_HasBlockManagementInfo_NvMConfigBlock(partitionIndex)                                   (TRUE != FALSE)
#define NvM_HasBlockManagementInfo_NvMMultiBlock(partitionIndex)                                    (TRUE != FALSE)
#define NvM_HasBlockManagementInfo_WDFC_ID_AP_CONNEX(partitionIndex)                                (TRUE != FALSE)
#define NvM_HasBlockManagementInfo_WDFC_ID_AP_PARA(partitionIndex)                                  (TRUE != FALSE)
#define NvM_HasBlockManagementInfo_WDFC_ID_BOOT_PARA(partitionIndex)                                (TRUE != FALSE)
#define NvM_HasBlockManagementInfo_WDFC_ID_CCP(partitionIndex)                                      (TRUE != FALSE)
#define NvM_HasBlockManagementInfo_WDFC_ID_DEBUG_DATA(partitionIndex)                               (TRUE != FALSE)
#define NvM_HasBlockManagementInfo_WDFC_ID_DLC(partitionIndex)                                      (TRUE != FALSE)
#define NvM_HasBlockManagementInfo_WDFC_ID_DTCTime(partitionIndex)                                  (TRUE != FALSE)
#define NvM_HasBlockManagementInfo_WDFC_ID_ECUID_RDI_PROGRAMMING_INFO(partitionIndex)               (TRUE != FALSE)
#define NvM_HasBlockManagementInfo_WDFC_ID_EOL_HW_VERSION(partitionIndex)                           (TRUE != FALSE)
#define NvM_HasBlockManagementInfo_WDFC_ID_EOL_INFO(partitionIndex)                                 (TRUE != FALSE)
#define NvM_HasBlockManagementInfo_WDFC_ID_EOL_PASSWORD(partitionIndex)                             (TRUE != FALSE)
#define NvM_HasBlockManagementInfo_WDFC_ID_EOL_SWNUMBER(partitionIndex)                             (TRUE != FALSE)
#define NvM_HasBlockManagementInfo_WDFC_ID_FAULT_CODE(partitionIndex)                               (TRUE != FALSE)
#define NvM_HasBlockManagementInfo_WDFC_ID_HANDLE_CFG(partitionIndex)                               (TRUE != FALSE)
#define NvM_HasBlockManagementInfo_WDFC_ID_IDENT_BANK(partitionIndex)                               (TRUE != FALSE)
#define NvM_HasBlockManagementInfo_WDFC_ID_IDOPTION_SECURITY(partitionIndex)                        (TRUE != FALSE)
#define NvM_HasBlockManagementInfo_WDFC_ID_LAST_FDC(partitionIndex)                                 (TRUE != FALSE)
#define NvM_HasBlockManagementInfo_WDFC_ID_MAX_FDC(partitionIndex)                                  (TRUE != FALSE)
#define NvM_HasBlockManagementInfo_WDFC_ID_MIRROR_CFG(partitionIndex)                               (TRUE != FALSE)
#define NvM_HasBlockManagementInfo_WDFC_ID_MIRROR_OTHER_1(partitionIndex)                           (TRUE != FALSE)
#define NvM_HasBlockManagementInfo_WDFC_ID_MIRROR_POS_REC(partitionIndex)                           (TRUE != FALSE)
#define NvM_HasBlockManagementInfo_WDFC_ID_MIRROR_ST(partitionIndex)                                (TRUE != FALSE)
#define NvM_HasBlockManagementInfo_WDFC_ID_PART_NUMBER_GEELY(partitionIndex)                        (TRUE != FALSE)
#define NvM_HasBlockManagementInfo_WDFC_ID_PMM(partitionIndex)                                      (TRUE != FALSE)
#define NvM_HasBlockManagementInfo_WDFC_ID_QCM_FAULT_DATA(partitionIndex)                           (TRUE != FALSE)
#define NvM_HasBlockManagementInfo_WDFC_ID_SECURITY_ACCESS(partitionIndex)                          (TRUE != FALSE)
#define NvM_HasBlockManagementInfo_WDFC_ID_SR_PROFILE(partitionIndex)                               (TRUE != FALSE)
#define NvM_HasBlockManagementInfo_WDFC_ID_SWP1(partitionIndex)                                     (TRUE != FALSE)
#define NvM_HasBlockManagementInfo_WDFC_ID_THPA(partitionIndex)                                     (TRUE != FALSE)
#define NvM_HasBlockManagementInfo_WDFC_ID_VEH_CFG(partitionIndex)                                  (TRUE != FALSE)
#define NvM_HasBlockManagementInfo_WDFC_ID_VOL_POWER_MODE_CFG(partitionIndex)                       (TRUE != FALSE)
#define NvM_HasBlockManagementInfo_WDFC_ID_WLC_AP_LEARN(partitionIndex)                             (TRUE != FALSE)
#define NvM_HasBlockManagementInfo_WDFC_ID_WL_INFO(partitionIndex)                                  (TRUE != FALSE)
#define NvM_HasBlockManagementInfo_WDFC_ID_WL_LOG(partitionIndex)                                   (TRUE != FALSE)
#define NvM_HasCrcCompMechanismBuffer_DemAdminDataBlock(partitionIndex)                             (TRUE != FALSE)
#define NvM_HasCrcCompMechanismBuffer_DemStatusDataBlock(partitionIndex)                            (TRUE != FALSE)
#define NvM_HasCrcCompMechanismBuffer_NvMConfigBlock(partitionIndex)                                (TRUE != FALSE)
#define NvM_HasCrcCompMechanismBuffer_WDFC_ID_AP_CONNEX(partitionIndex)                             (TRUE != FALSE)
#define NvM_HasCrcCompMechanismBuffer_WDFC_ID_AP_PARA(partitionIndex)                               (TRUE != FALSE)
#define NvM_HasCrcCompMechanismBuffer_WDFC_ID_BOOT_PARA(partitionIndex)                             (TRUE != FALSE)
#define NvM_HasCrcCompMechanismBuffer_WDFC_ID_CCP(partitionIndex)                                   (TRUE != FALSE)
#define NvM_HasCrcCompMechanismBuffer_WDFC_ID_DEBUG_DATA(partitionIndex)                            (TRUE != FALSE)
#define NvM_HasCrcCompMechanismBuffer_WDFC_ID_DLC(partitionIndex)                                   (TRUE != FALSE)
#define NvM_HasCrcCompMechanismBuffer_WDFC_ID_DTCTime(partitionIndex)                               (TRUE != FALSE)
#define NvM_HasCrcCompMechanismBuffer_WDFC_ID_ECUID_RDI_PROGRAMMING_INFO(partitionIndex)            (TRUE != FALSE)
#define NvM_HasCrcCompMechanismBuffer_WDFC_ID_EOL_HW_VERSION(partitionIndex)                        (TRUE != FALSE)
#define NvM_HasCrcCompMechanismBuffer_WDFC_ID_EOL_INFO(partitionIndex)                              (TRUE != FALSE)
#define NvM_HasCrcCompMechanismBuffer_WDFC_ID_EOL_PASSWORD(partitionIndex)                          (TRUE != FALSE)
#define NvM_HasCrcCompMechanismBuffer_WDFC_ID_EOL_SWNUMBER(partitionIndex)                          (TRUE != FALSE)
#define NvM_HasCrcCompMechanismBuffer_WDFC_ID_FAULT_CODE(partitionIndex)                            (TRUE != FALSE)
#define NvM_HasCrcCompMechanismBuffer_WDFC_ID_HANDLE_CFG(partitionIndex)                            (TRUE != FALSE)
#define NvM_HasCrcCompMechanismBuffer_WDFC_ID_IDENT_BANK(partitionIndex)                            (TRUE != FALSE)
#define NvM_HasCrcCompMechanismBuffer_WDFC_ID_IDOPTION_SECURITY(partitionIndex)                     (TRUE != FALSE)
#define NvM_HasCrcCompMechanismBuffer_WDFC_ID_LAST_FDC(partitionIndex)                              (TRUE != FALSE)
#define NvM_HasCrcCompMechanismBuffer_WDFC_ID_MAX_FDC(partitionIndex)                               (TRUE != FALSE)
#define NvM_HasCrcCompMechanismBuffer_WDFC_ID_MIRROR_CFG(partitionIndex)                            (TRUE != FALSE)
#define NvM_HasCrcCompMechanismBuffer_WDFC_ID_MIRROR_OTHER_1(partitionIndex)                        (TRUE != FALSE)
#define NvM_HasCrcCompMechanismBuffer_WDFC_ID_MIRROR_POS_REC(partitionIndex)                        (TRUE != FALSE)
#define NvM_HasCrcCompMechanismBuffer_WDFC_ID_MIRROR_ST(partitionIndex)                             (TRUE != FALSE)
#define NvM_HasCrcCompMechanismBuffer_WDFC_ID_PART_NUMBER_GEELY(partitionIndex)                     (TRUE != FALSE)
#define NvM_HasCrcCompMechanismBuffer_WDFC_ID_PMM(partitionIndex)                                   (TRUE != FALSE)
#define NvM_HasCrcCompMechanismBuffer_WDFC_ID_QCM_FAULT_DATA(partitionIndex)                        (TRUE != FALSE)
#define NvM_HasCrcCompMechanismBuffer_WDFC_ID_SECURITY_ACCESS(partitionIndex)                       (TRUE != FALSE)
#define NvM_HasCrcCompMechanismBuffer_WDFC_ID_SR_PROFILE(partitionIndex)                            (TRUE != FALSE)
#define NvM_HasCrcCompMechanismBuffer_WDFC_ID_SWP1(partitionIndex)                                  (TRUE != FALSE)
#define NvM_HasCrcCompMechanismBuffer_WDFC_ID_THPA(partitionIndex)                                  (TRUE != FALSE)
#define NvM_HasCrcCompMechanismBuffer_WDFC_ID_VEH_CFG(partitionIndex)                               (TRUE != FALSE)
#define NvM_HasCrcCompMechanismBuffer_WDFC_ID_VOL_POWER_MODE_CFG(partitionIndex)                    (TRUE != FALSE)
#define NvM_HasCrcCompMechanismBuffer_WDFC_ID_WLC_AP_LEARN(partitionIndex)                          (TRUE != FALSE)
#define NvM_HasCrcCompMechanismBuffer_WDFC_ID_WL_INFO(partitionIndex)                               (TRUE != FALSE)
#define NvM_HasCrcCompMechanismBuffer_WDFC_ID_WL_LOG(partitionIndex)                                (TRUE != FALSE)
#define NvM_HasDataIntegrityFsm_Instance(partitionIndex)                                            (TRUE != FALSE)
#define NvM_HasDataIntegrityIntBuffer_DemAdminDataBlock(partitionIndex)                             (TRUE != FALSE)
#define NvM_HasDataIntegrityIntBuffer_DemStatusDataBlock(partitionIndex)                            (TRUE != FALSE)
#define NvM_HasDataIntegrityIntBuffer_WDFC_ID_AP_CONNEX(partitionIndex)                             (TRUE != FALSE)
#define NvM_HasDataIntegrityIntBuffer_WDFC_ID_AP_PARA(partitionIndex)                               (TRUE != FALSE)
#define NvM_HasDataIntegrityIntBuffer_WDFC_ID_BOOT_PARA(partitionIndex)                             (TRUE != FALSE)
#define NvM_HasDataIntegrityIntBuffer_WDFC_ID_CCP(partitionIndex)                                   (TRUE != FALSE)
#define NvM_HasDataIntegrityIntBuffer_WDFC_ID_DEBUG_DATA(partitionIndex)                            (TRUE != FALSE)
#define NvM_HasDataIntegrityIntBuffer_WDFC_ID_DLC(partitionIndex)                                   (TRUE != FALSE)
#define NvM_HasDataIntegrityIntBuffer_WDFC_ID_DTCTime(partitionIndex)                               (TRUE != FALSE)
#define NvM_HasDataIntegrityIntBuffer_WDFC_ID_ECUID_RDI_PROGRAMMING_INFO(partitionIndex)            (TRUE != FALSE)
#define NvM_HasDataIntegrityIntBuffer_WDFC_ID_EOL_HW_VERSION(partitionIndex)                        (TRUE != FALSE)
#define NvM_HasDataIntegrityIntBuffer_WDFC_ID_EOL_INFO(partitionIndex)                              (TRUE != FALSE)
#define NvM_HasDataIntegrityIntBuffer_WDFC_ID_EOL_PASSWORD(partitionIndex)                          (TRUE != FALSE)
#define NvM_HasDataIntegrityIntBuffer_WDFC_ID_EOL_SWNUMBER(partitionIndex)                          (TRUE != FALSE)
#define NvM_HasDataIntegrityIntBuffer_WDFC_ID_FAULT_CODE(partitionIndex)                            (TRUE != FALSE)
#define NvM_HasDataIntegrityIntBuffer_WDFC_ID_HANDLE_CFG(partitionIndex)                            (TRUE != FALSE)
#define NvM_HasDataIntegrityIntBuffer_WDFC_ID_IDENT_BANK(partitionIndex)                            (TRUE != FALSE)
#define NvM_HasDataIntegrityIntBuffer_WDFC_ID_IDOPTION_SECURITY(partitionIndex)                     (TRUE != FALSE)
#define NvM_HasDataIntegrityIntBuffer_WDFC_ID_LAST_FDC(partitionIndex)                              (TRUE != FALSE)
#define NvM_HasDataIntegrityIntBuffer_WDFC_ID_MAX_FDC(partitionIndex)                               (TRUE != FALSE)
#define NvM_HasDataIntegrityIntBuffer_WDFC_ID_MIRROR_CFG(partitionIndex)                            (TRUE != FALSE)
#define NvM_HasDataIntegrityIntBuffer_WDFC_ID_MIRROR_OTHER_1(partitionIndex)                        (TRUE != FALSE)
#define NvM_HasDataIntegrityIntBuffer_WDFC_ID_MIRROR_POS_REC(partitionIndex)                        (TRUE != FALSE)
#define NvM_HasDataIntegrityIntBuffer_WDFC_ID_MIRROR_ST(partitionIndex)                             (TRUE != FALSE)
#define NvM_HasDataIntegrityIntBuffer_WDFC_ID_PART_NUMBER_GEELY(partitionIndex)                     (TRUE != FALSE)
#define NvM_HasDataIntegrityIntBuffer_WDFC_ID_PMM(partitionIndex)                                   (TRUE != FALSE)
#define NvM_HasDataIntegrityIntBuffer_WDFC_ID_QCM_FAULT_DATA(partitionIndex)                        (TRUE != FALSE)
#define NvM_HasDataIntegrityIntBuffer_WDFC_ID_SECURITY_ACCESS(partitionIndex)                       (TRUE != FALSE)
#define NvM_HasDataIntegrityIntBuffer_WDFC_ID_SR_PROFILE(partitionIndex)                            (TRUE != FALSE)
#define NvM_HasDataIntegrityIntBuffer_WDFC_ID_SWP1(partitionIndex)                                  (TRUE != FALSE)
#define NvM_HasDataIntegrityIntBuffer_WDFC_ID_THPA(partitionIndex)                                  (TRUE != FALSE)
#define NvM_HasDataIntegrityIntBuffer_WDFC_ID_VEH_CFG(partitionIndex)                               (TRUE != FALSE)
#define NvM_HasDataIntegrityIntBuffer_WDFC_ID_VOL_POWER_MODE_CFG(partitionIndex)                    (TRUE != FALSE)
#define NvM_HasDataIntegrityIntBuffer_WDFC_ID_WLC_AP_LEARN(partitionIndex)                          (TRUE != FALSE)
#define NvM_HasDataIntegrityIntBuffer_WDFC_ID_WL_INFO(partitionIndex)                               (TRUE != FALSE)
#define NvM_HasDataIntegrityIntBuffer_WDFC_ID_WL_LOG(partitionIndex)                                (TRUE != FALSE)
#define NvM_HasDataIntegrityRecalcQueue_Instance(partitionIndex)                                    (TRUE != FALSE)
#define NvM_HasDcmBlockManagementInfo(partitionIndex)                                               (TRUE != FALSE)
#define NvM_HasForegroundDataIntegrityService_Instance(partitionIndex)                              (TRUE != FALSE)
#define NvM_HasInternalBuffer(partitionIndex)                                                       (TRUE != FALSE)
#define NvM_HasMultiBlockFsmLib_ProcessingStackElement(partitionIndex)                              (TRUE != FALSE)
#define NvM_HasMultiBlockJob(partitionIndex)                                                        (TRUE != FALSE)
#define NvM_HasMultiBlockJobFsm_Context(partitionIndex)                                             (TRUE != FALSE)
#define NvM_HasMultiBlockJobFsm_Instance(partitionIndex)                                            (TRUE != FALSE)
#define NvM_HasMultiBlockJobInformation(partitionIndex)                                             (TRUE != FALSE)
#define NvM_HasMultiBlockProcessorFsmLib_Instance(partitionIndex)                                   (TRUE != FALSE)
#define NvM_HasMultiBlockProcessorFsmLib_ProcessingStackElement(partitionIndex)                     (TRUE != FALSE)
#define NvM_HasMultiBlockServiceFsmLib_Instance(partitionIndex)                                     (TRUE != FALSE)
#define NvM_HasNvJobContext(partitionIndex)                                                         (TRUE != FALSE)
#define NvM_HasNvJobFsm_Instance(partitionIndex)                                                    (TRUE != FALSE)
#define NvM_HasNvServiceFsmLib_Instance(partitionIndex)                                             (TRUE != FALSE)
#define NvM_HasNvServiceFsmLib_ProcessingStackElement(partitionIndex)                               (TRUE != FALSE)
#define NvM_HasNvServiceProcessorFsmLib_Instance(partitionIndex)                                    (TRUE != FALSE)
#define NvM_HasNvServiceProcessorFsmLib_ProcessingStackElement(partitionIndex)                      (TRUE != FALSE)
#define NvM_HasPartitionIdentifiers()                                                               (TRUE != FALSE)
#define NvM_HasPCPartitionConfigIdxOfPartitionIdentifiers()                                         (TRUE != FALSE)
#define NvM_HasPartitionSNVOfPartitionIdentifiers()                                                 (TRUE != FALSE)
#define NvM_HasQueueList(partitionIndex)                                                            (TRUE != FALSE)
#define NvM_HasQueue_Instance(partitionIndex)                                                       (TRUE != FALSE)
#define NvM_HasReadAllFsm_Context(partitionIndex)                                                   (TRUE != FALSE)
#define NvM_HasReadAllFsm_Instance(partitionIndex)                                                  (TRUE != FALSE)
#define NvM_HasReadBlockFsm_Context(partitionIndex)                                                 (TRUE != FALSE)
#define NvM_HasReadBlockFsm_Instance(partitionIndex)                                                (TRUE != FALSE)
#define NvM_HasServiceProcessorFsmLib_Instance(partitionIndex)                                      (TRUE != FALSE)
#define NvM_HasServiceProcessorFsmLib_ProcessingStackElement(partitionIndex)                        (TRUE != FALSE)
#define NvM_HasServiceProcessorFsm_Context(partitionIndex)                                          (TRUE != FALSE)
#define NvM_HasServiceProcessorFsm_Instance(partitionIndex)                                         (TRUE != FALSE)
#define NvM_HasSingleBlockFsmLib_ProcessingStackElement(partitionIndex)                             (TRUE != FALSE)
#define NvM_HasSingleBlockJobContext(partitionIndex)                                                (TRUE != FALSE)
#define NvM_HasSingleBlockJobFsm_Instance(partitionIndex)                                           (TRUE != FALSE)
#define NvM_HasSingleBlockServiceFsmLib_Instance(partitionIndex)                                    (TRUE != FALSE)
#define NvM_HasSizeOfBackgroundCrcRecalcFsmLib_ProcessingStackElement(partitionIndex)               (TRUE != FALSE)
#define NvM_HasSizeOfBlockDescriptor()                                                              (TRUE != FALSE)
#define NvM_HasSizeOfCrcCompMechanismBuffer_DemAdminDataBlock(partitionIndex)                       (TRUE != FALSE)
#define NvM_HasSizeOfCrcCompMechanismBuffer_DemStatusDataBlock(partitionIndex)                      (TRUE != FALSE)
#define NvM_HasSizeOfCrcCompMechanismBuffer_NvMConfigBlock(partitionIndex)                          (TRUE != FALSE)
#define NvM_HasSizeOfCrcCompMechanismBuffer_WDFC_ID_AP_CONNEX(partitionIndex)                       (TRUE != FALSE)
#define NvM_HasSizeOfCrcCompMechanismBuffer_WDFC_ID_AP_PARA(partitionIndex)                         (TRUE != FALSE)
#define NvM_HasSizeOfCrcCompMechanismBuffer_WDFC_ID_BOOT_PARA(partitionIndex)                       (TRUE != FALSE)
#define NvM_HasSizeOfCrcCompMechanismBuffer_WDFC_ID_CCP(partitionIndex)                             (TRUE != FALSE)
#define NvM_HasSizeOfCrcCompMechanismBuffer_WDFC_ID_DEBUG_DATA(partitionIndex)                      (TRUE != FALSE)
#define NvM_HasSizeOfCrcCompMechanismBuffer_WDFC_ID_DLC(partitionIndex)                             (TRUE != FALSE)
#define NvM_HasSizeOfCrcCompMechanismBuffer_WDFC_ID_DTCTime(partitionIndex)                         (TRUE != FALSE)
#define NvM_HasSizeOfCrcCompMechanismBuffer_WDFC_ID_ECUID_RDI_PROGRAMMING_INFO(partitionIndex)      (TRUE != FALSE)
#define NvM_HasSizeOfCrcCompMechanismBuffer_WDFC_ID_EOL_HW_VERSION(partitionIndex)                  (TRUE != FALSE)
#define NvM_HasSizeOfCrcCompMechanismBuffer_WDFC_ID_EOL_INFO(partitionIndex)                        (TRUE != FALSE)
#define NvM_HasSizeOfCrcCompMechanismBuffer_WDFC_ID_EOL_PASSWORD(partitionIndex)                    (TRUE != FALSE)
#define NvM_HasSizeOfCrcCompMechanismBuffer_WDFC_ID_EOL_SWNUMBER(partitionIndex)                    (TRUE != FALSE)
#define NvM_HasSizeOfCrcCompMechanismBuffer_WDFC_ID_FAULT_CODE(partitionIndex)                      (TRUE != FALSE)
#define NvM_HasSizeOfCrcCompMechanismBuffer_WDFC_ID_HANDLE_CFG(partitionIndex)                      (TRUE != FALSE)
#define NvM_HasSizeOfCrcCompMechanismBuffer_WDFC_ID_IDENT_BANK(partitionIndex)                      (TRUE != FALSE)
#define NvM_HasSizeOfCrcCompMechanismBuffer_WDFC_ID_IDOPTION_SECURITY(partitionIndex)               (TRUE != FALSE)
#define NvM_HasSizeOfCrcCompMechanismBuffer_WDFC_ID_LAST_FDC(partitionIndex)                        (TRUE != FALSE)
#define NvM_HasSizeOfCrcCompMechanismBuffer_WDFC_ID_MAX_FDC(partitionIndex)                         (TRUE != FALSE)
#define NvM_HasSizeOfCrcCompMechanismBuffer_WDFC_ID_MIRROR_CFG(partitionIndex)                      (TRUE != FALSE)
#define NvM_HasSizeOfCrcCompMechanismBuffer_WDFC_ID_MIRROR_OTHER_1(partitionIndex)                  (TRUE != FALSE)
#define NvM_HasSizeOfCrcCompMechanismBuffer_WDFC_ID_MIRROR_POS_REC(partitionIndex)                  (TRUE != FALSE)
#define NvM_HasSizeOfCrcCompMechanismBuffer_WDFC_ID_MIRROR_ST(partitionIndex)                       (TRUE != FALSE)
#define NvM_HasSizeOfCrcCompMechanismBuffer_WDFC_ID_PART_NUMBER_GEELY(partitionIndex)               (TRUE != FALSE)
#define NvM_HasSizeOfCrcCompMechanismBuffer_WDFC_ID_PMM(partitionIndex)                             (TRUE != FALSE)
#define NvM_HasSizeOfCrcCompMechanismBuffer_WDFC_ID_QCM_FAULT_DATA(partitionIndex)                  (TRUE != FALSE)
#define NvM_HasSizeOfCrcCompMechanismBuffer_WDFC_ID_SECURITY_ACCESS(partitionIndex)                 (TRUE != FALSE)
#define NvM_HasSizeOfCrcCompMechanismBuffer_WDFC_ID_SR_PROFILE(partitionIndex)                      (TRUE != FALSE)
#define NvM_HasSizeOfCrcCompMechanismBuffer_WDFC_ID_SWP1(partitionIndex)                            (TRUE != FALSE)
#define NvM_HasSizeOfCrcCompMechanismBuffer_WDFC_ID_THPA(partitionIndex)                            (TRUE != FALSE)
#define NvM_HasSizeOfCrcCompMechanismBuffer_WDFC_ID_VEH_CFG(partitionIndex)                         (TRUE != FALSE)
#define NvM_HasSizeOfCrcCompMechanismBuffer_WDFC_ID_VOL_POWER_MODE_CFG(partitionIndex)              (TRUE != FALSE)
#define NvM_HasSizeOfCrcCompMechanismBuffer_WDFC_ID_WLC_AP_LEARN(partitionIndex)                    (TRUE != FALSE)
#define NvM_HasSizeOfCrcCompMechanismBuffer_WDFC_ID_WL_INFO(partitionIndex)                         (TRUE != FALSE)
#define NvM_HasSizeOfCrcCompMechanismBuffer_WDFC_ID_WL_LOG(partitionIndex)                          (TRUE != FALSE)
#define NvM_HasSizeOfDataIntegrityIntBuffer_DemAdminDataBlock(partitionIndex)                       (TRUE != FALSE)
#define NvM_HasSizeOfDataIntegrityIntBuffer_DemStatusDataBlock(partitionIndex)                      (TRUE != FALSE)
#define NvM_HasSizeOfDataIntegrityIntBuffer_WDFC_ID_AP_CONNEX(partitionIndex)                       (TRUE != FALSE)
#define NvM_HasSizeOfDataIntegrityIntBuffer_WDFC_ID_AP_PARA(partitionIndex)                         (TRUE != FALSE)
#define NvM_HasSizeOfDataIntegrityIntBuffer_WDFC_ID_BOOT_PARA(partitionIndex)                       (TRUE != FALSE)
#define NvM_HasSizeOfDataIntegrityIntBuffer_WDFC_ID_CCP(partitionIndex)                             (TRUE != FALSE)
#define NvM_HasSizeOfDataIntegrityIntBuffer_WDFC_ID_DEBUG_DATA(partitionIndex)                      (TRUE != FALSE)
#define NvM_HasSizeOfDataIntegrityIntBuffer_WDFC_ID_DLC(partitionIndex)                             (TRUE != FALSE)
#define NvM_HasSizeOfDataIntegrityIntBuffer_WDFC_ID_DTCTime(partitionIndex)                         (TRUE != FALSE)
#define NvM_HasSizeOfDataIntegrityIntBuffer_WDFC_ID_ECUID_RDI_PROGRAMMING_INFO(partitionIndex)      (TRUE != FALSE)
#define NvM_HasSizeOfDataIntegrityIntBuffer_WDFC_ID_EOL_HW_VERSION(partitionIndex)                  (TRUE != FALSE)
#define NvM_HasSizeOfDataIntegrityIntBuffer_WDFC_ID_EOL_INFO(partitionIndex)                        (TRUE != FALSE)
#define NvM_HasSizeOfDataIntegrityIntBuffer_WDFC_ID_EOL_PASSWORD(partitionIndex)                    (TRUE != FALSE)
#define NvM_HasSizeOfDataIntegrityIntBuffer_WDFC_ID_EOL_SWNUMBER(partitionIndex)                    (TRUE != FALSE)
#define NvM_HasSizeOfDataIntegrityIntBuffer_WDFC_ID_FAULT_CODE(partitionIndex)                      (TRUE != FALSE)
#define NvM_HasSizeOfDataIntegrityIntBuffer_WDFC_ID_HANDLE_CFG(partitionIndex)                      (TRUE != FALSE)
#define NvM_HasSizeOfDataIntegrityIntBuffer_WDFC_ID_IDENT_BANK(partitionIndex)                      (TRUE != FALSE)
#define NvM_HasSizeOfDataIntegrityIntBuffer_WDFC_ID_IDOPTION_SECURITY(partitionIndex)               (TRUE != FALSE)
#define NvM_HasSizeOfDataIntegrityIntBuffer_WDFC_ID_LAST_FDC(partitionIndex)                        (TRUE != FALSE)
#define NvM_HasSizeOfDataIntegrityIntBuffer_WDFC_ID_MAX_FDC(partitionIndex)                         (TRUE != FALSE)
#define NvM_HasSizeOfDataIntegrityIntBuffer_WDFC_ID_MIRROR_CFG(partitionIndex)                      (TRUE != FALSE)
#define NvM_HasSizeOfDataIntegrityIntBuffer_WDFC_ID_MIRROR_OTHER_1(partitionIndex)                  (TRUE != FALSE)
#define NvM_HasSizeOfDataIntegrityIntBuffer_WDFC_ID_MIRROR_POS_REC(partitionIndex)                  (TRUE != FALSE)
#define NvM_HasSizeOfDataIntegrityIntBuffer_WDFC_ID_MIRROR_ST(partitionIndex)                       (TRUE != FALSE)
#define NvM_HasSizeOfDataIntegrityIntBuffer_WDFC_ID_PART_NUMBER_GEELY(partitionIndex)               (TRUE != FALSE)
#define NvM_HasSizeOfDataIntegrityIntBuffer_WDFC_ID_PMM(partitionIndex)                             (TRUE != FALSE)
#define NvM_HasSizeOfDataIntegrityIntBuffer_WDFC_ID_QCM_FAULT_DATA(partitionIndex)                  (TRUE != FALSE)
#define NvM_HasSizeOfDataIntegrityIntBuffer_WDFC_ID_SECURITY_ACCESS(partitionIndex)                 (TRUE != FALSE)
#define NvM_HasSizeOfDataIntegrityIntBuffer_WDFC_ID_SR_PROFILE(partitionIndex)                      (TRUE != FALSE)
#define NvM_HasSizeOfDataIntegrityIntBuffer_WDFC_ID_SWP1(partitionIndex)                            (TRUE != FALSE)
#define NvM_HasSizeOfDataIntegrityIntBuffer_WDFC_ID_THPA(partitionIndex)                            (TRUE != FALSE)
#define NvM_HasSizeOfDataIntegrityIntBuffer_WDFC_ID_VEH_CFG(partitionIndex)                         (TRUE != FALSE)
#define NvM_HasSizeOfDataIntegrityIntBuffer_WDFC_ID_VOL_POWER_MODE_CFG(partitionIndex)              (TRUE != FALSE)
#define NvM_HasSizeOfDataIntegrityIntBuffer_WDFC_ID_WLC_AP_LEARN(partitionIndex)                    (TRUE != FALSE)
#define NvM_HasSizeOfDataIntegrityIntBuffer_WDFC_ID_WL_INFO(partitionIndex)                         (TRUE != FALSE)
#define NvM_HasSizeOfDataIntegrityIntBuffer_WDFC_ID_WL_LOG(partitionIndex)                          (TRUE != FALSE)
#define NvM_HasSizeOfInternalBuffer(partitionIndex)                                                 (TRUE != FALSE)
#define NvM_HasSizeOfMultiBlockFsmLib_ProcessingStackElement(partitionIndex)                        (TRUE != FALSE)
#define NvM_HasSizeOfMultiBlockProcessorFsmLib_ProcessingStackElement(partitionIndex)               (TRUE != FALSE)
#define NvM_HasSizeOfNvServiceFsmLib_ProcessingStackElement(partitionIndex)                         (TRUE != FALSE)
#define NvM_HasSizeOfNvServiceProcessorFsmLib_ProcessingStackElement(partitionIndex)                (TRUE != FALSE)
#define NvM_HasSizeOfPartitionIdentifiers()                                                         (TRUE != FALSE)
#define NvM_HasSizeOfQueueList(partitionIndex)                                                      (TRUE != FALSE)
#define NvM_HasSizeOfServiceProcessorFsmLib_ProcessingStackElement(partitionIndex)                  (TRUE != FALSE)
#define NvM_HasSizeOfSingleBlockFsmLib_ProcessingStackElement(partitionIndex)                       (TRUE != FALSE)
#define NvM_HasValidateAllFsm_Instance(partitionIndex)                                              (TRUE != FALSE)
#define NvM_HasWriteAllFsm_Context(partitionIndex)                                                  (TRUE != FALSE)
#define NvM_HasWriteAllFsm_Instance(partitionIndex)                                                 (TRUE != FALSE)
#define NvM_HasWriteBlockFsm_Context(partitionIndex)                                                (TRUE != FALSE)
#define NvM_HasWriteBlockFsm_Instance(partitionIndex)                                               (TRUE != FALSE)
#define NvM_HasWriteNvBlockFsm_Context(partitionIndex)                                              (TRUE != FALSE)
#define NvM_HasPCConfig()                                                                           (TRUE != FALSE)
#define NvM_HasPCPartitionConfigOfPCConfig()                                                        (TRUE != FALSE)
#define NvM_HasPartitionIdentifiersOfPCConfig()                                                     (TRUE != FALSE)
#define NvM_HasSizeOfPartitionIdentifiersOfPCConfig()                                               (TRUE != FALSE)
#define NvM_HasPCPartitionConfig()                                                                  (TRUE != FALSE)
#define NvM_HasBackgroundCrcRecalcFsmLib_InstanceOfPCPartitionConfig(partitionIndex)                (TRUE != FALSE)
#define NvM_HasBackgroundCrcRecalcFsmLib_ProcessingStackElementOfPCPartitionConfig(partitionIndex)  (TRUE != FALSE)
#define NvM_HasBackgroundCrcRecalcFsm_ContextOfPCPartitionConfig(partitionIndex)                    (TRUE != FALSE)
#define NvM_HasBackgroundCrcRecalcFsm_InstanceOfPCPartitionConfig(partitionIndex)                   (TRUE != FALSE)
#define NvM_HasBackgroundDataIntegrityService_InstanceOfPCPartitionConfig(partitionIndex)           (TRUE != FALSE)
#define NvM_HasBlockDescriptorOfPCPartitionConfig()                                                 (TRUE != FALSE)
#define NvM_HasBlockManagementInfo_DemAdminDataBlockOfPCPartitionConfig(partitionIndex)             (TRUE != FALSE)
#define NvM_HasBlockManagementInfo_DemStatusDataBlockOfPCPartitionConfig(partitionIndex)            (TRUE != FALSE)
#define NvM_HasBlockManagementInfo_NvMConfigBlockOfPCPartitionConfig(partitionIndex)                (TRUE != FALSE)
#define NvM_HasBlockManagementInfo_NvMMultiBlockOfPCPartitionConfig(partitionIndex)                 (TRUE != FALSE)
#define NvM_HasBlockManagementInfo_WDFC_ID_AP_CONNEXOfPCPartitionConfig(partitionIndex)             (TRUE != FALSE)
#define NvM_HasBlockManagementInfo_WDFC_ID_AP_PARAOfPCPartitionConfig(partitionIndex)               (TRUE != FALSE)
#define NvM_HasBlockManagementInfo_WDFC_ID_BOOT_PARAOfPCPartitionConfig(partitionIndex)             (TRUE != FALSE)
#define NvM_HasBlockManagementInfo_WDFC_ID_CCPOfPCPartitionConfig(partitionIndex)                   (TRUE != FALSE)
#define NvM_HasBlockManagementInfo_WDFC_ID_DEBUG_DATAOfPCPartitionConfig(partitionIndex)            (TRUE != FALSE)
#define NvM_HasBlockManagementInfo_WDFC_ID_DLCOfPCPartitionConfig(partitionIndex)                   (TRUE != FALSE)
#define NvM_HasBlockManagementInfo_WDFC_ID_DTCTimeOfPCPartitionConfig(partitionIndex)               (TRUE != FALSE)
#define NvM_HasBlockManagementInfo_WDFC_ID_ECUID_RDI_PROGRAMMING_INFOOfPCPartitionConfig(partitionIndex) (TRUE != FALSE)
#define NvM_HasBlockManagementInfo_WDFC_ID_EOL_HW_VERSIONOfPCPartitionConfig(partitionIndex)        (TRUE != FALSE)
#define NvM_HasBlockManagementInfo_WDFC_ID_EOL_INFOOfPCPartitionConfig(partitionIndex)              (TRUE != FALSE)
#define NvM_HasBlockManagementInfo_WDFC_ID_EOL_PASSWORDOfPCPartitionConfig(partitionIndex)          (TRUE != FALSE)
#define NvM_HasBlockManagementInfo_WDFC_ID_EOL_SWNUMBEROfPCPartitionConfig(partitionIndex)          (TRUE != FALSE)
#define NvM_HasBlockManagementInfo_WDFC_ID_FAULT_CODEOfPCPartitionConfig(partitionIndex)            (TRUE != FALSE)
#define NvM_HasBlockManagementInfo_WDFC_ID_HANDLE_CFGOfPCPartitionConfig(partitionIndex)            (TRUE != FALSE)
#define NvM_HasBlockManagementInfo_WDFC_ID_IDENT_BANKOfPCPartitionConfig(partitionIndex)            (TRUE != FALSE)
#define NvM_HasBlockManagementInfo_WDFC_ID_IDOPTION_SECURITYOfPCPartitionConfig(partitionIndex)     (TRUE != FALSE)
#define NvM_HasBlockManagementInfo_WDFC_ID_LAST_FDCOfPCPartitionConfig(partitionIndex)              (TRUE != FALSE)
#define NvM_HasBlockManagementInfo_WDFC_ID_MAX_FDCOfPCPartitionConfig(partitionIndex)               (TRUE != FALSE)
#define NvM_HasBlockManagementInfo_WDFC_ID_MIRROR_CFGOfPCPartitionConfig(partitionIndex)            (TRUE != FALSE)
#define NvM_HasBlockManagementInfo_WDFC_ID_MIRROR_OTHER_1OfPCPartitionConfig(partitionIndex)        (TRUE != FALSE)
#define NvM_HasBlockManagementInfo_WDFC_ID_MIRROR_POS_RECOfPCPartitionConfig(partitionIndex)        (TRUE != FALSE)
#define NvM_HasBlockManagementInfo_WDFC_ID_MIRROR_STOfPCPartitionConfig(partitionIndex)             (TRUE != FALSE)
#define NvM_HasBlockManagementInfo_WDFC_ID_PART_NUMBER_GEELYOfPCPartitionConfig(partitionIndex)     (TRUE != FALSE)
#define NvM_HasBlockManagementInfo_WDFC_ID_PMMOfPCPartitionConfig(partitionIndex)                   (TRUE != FALSE)
#define NvM_HasBlockManagementInfo_WDFC_ID_QCM_FAULT_DATAOfPCPartitionConfig(partitionIndex)        (TRUE != FALSE)
#define NvM_HasBlockManagementInfo_WDFC_ID_SECURITY_ACCESSOfPCPartitionConfig(partitionIndex)       (TRUE != FALSE)
#define NvM_HasBlockManagementInfo_WDFC_ID_SR_PROFILEOfPCPartitionConfig(partitionIndex)            (TRUE != FALSE)
#define NvM_HasBlockManagementInfo_WDFC_ID_SWP1OfPCPartitionConfig(partitionIndex)                  (TRUE != FALSE)
#define NvM_HasBlockManagementInfo_WDFC_ID_THPAOfPCPartitionConfig(partitionIndex)                  (TRUE != FALSE)
#define NvM_HasBlockManagementInfo_WDFC_ID_VEH_CFGOfPCPartitionConfig(partitionIndex)               (TRUE != FALSE)
#define NvM_HasBlockManagementInfo_WDFC_ID_VOL_POWER_MODE_CFGOfPCPartitionConfig(partitionIndex)    (TRUE != FALSE)
#define NvM_HasBlockManagementInfo_WDFC_ID_WLC_AP_LEARNOfPCPartitionConfig(partitionIndex)          (TRUE != FALSE)
#define NvM_HasBlockManagementInfo_WDFC_ID_WL_INFOOfPCPartitionConfig(partitionIndex)               (TRUE != FALSE)
#define NvM_HasBlockManagementInfo_WDFC_ID_WL_LOGOfPCPartitionConfig(partitionIndex)                (TRUE != FALSE)
#define NvM_HasCrcCompMechanismBuffer_DemAdminDataBlockOfPCPartitionConfig(partitionIndex)          (TRUE != FALSE)
#define NvM_HasCrcCompMechanismBuffer_DemStatusDataBlockOfPCPartitionConfig(partitionIndex)         (TRUE != FALSE)
#define NvM_HasCrcCompMechanismBuffer_NvMConfigBlockOfPCPartitionConfig(partitionIndex)             (TRUE != FALSE)
#define NvM_HasCrcCompMechanismBuffer_WDFC_ID_AP_CONNEXOfPCPartitionConfig(partitionIndex)          (TRUE != FALSE)
#define NvM_HasCrcCompMechanismBuffer_WDFC_ID_AP_PARAOfPCPartitionConfig(partitionIndex)            (TRUE != FALSE)
#define NvM_HasCrcCompMechanismBuffer_WDFC_ID_BOOT_PARAOfPCPartitionConfig(partitionIndex)          (TRUE != FALSE)
#define NvM_HasCrcCompMechanismBuffer_WDFC_ID_CCPOfPCPartitionConfig(partitionIndex)                (TRUE != FALSE)
#define NvM_HasCrcCompMechanismBuffer_WDFC_ID_DEBUG_DATAOfPCPartitionConfig(partitionIndex)         (TRUE != FALSE)
#define NvM_HasCrcCompMechanismBuffer_WDFC_ID_DLCOfPCPartitionConfig(partitionIndex)                (TRUE != FALSE)
#define NvM_HasCrcCompMechanismBuffer_WDFC_ID_DTCTimeOfPCPartitionConfig(partitionIndex)            (TRUE != FALSE)
#define NvM_HasCrcCompMechanismBuffer_WDFC_ID_ECUID_RDI_PROGRAMMING_INFOOfPCPartitionConfig(partitionIndex) (TRUE != FALSE)
#define NvM_HasCrcCompMechanismBuffer_WDFC_ID_EOL_HW_VERSIONOfPCPartitionConfig(partitionIndex)     (TRUE != FALSE)
#define NvM_HasCrcCompMechanismBuffer_WDFC_ID_EOL_INFOOfPCPartitionConfig(partitionIndex)           (TRUE != FALSE)
#define NvM_HasCrcCompMechanismBuffer_WDFC_ID_EOL_PASSWORDOfPCPartitionConfig(partitionIndex)       (TRUE != FALSE)
#define NvM_HasCrcCompMechanismBuffer_WDFC_ID_EOL_SWNUMBEROfPCPartitionConfig(partitionIndex)       (TRUE != FALSE)
#define NvM_HasCrcCompMechanismBuffer_WDFC_ID_FAULT_CODEOfPCPartitionConfig(partitionIndex)         (TRUE != FALSE)
#define NvM_HasCrcCompMechanismBuffer_WDFC_ID_HANDLE_CFGOfPCPartitionConfig(partitionIndex)         (TRUE != FALSE)
#define NvM_HasCrcCompMechanismBuffer_WDFC_ID_IDENT_BANKOfPCPartitionConfig(partitionIndex)         (TRUE != FALSE)
#define NvM_HasCrcCompMechanismBuffer_WDFC_ID_IDOPTION_SECURITYOfPCPartitionConfig(partitionIndex)  (TRUE != FALSE)
#define NvM_HasCrcCompMechanismBuffer_WDFC_ID_LAST_FDCOfPCPartitionConfig(partitionIndex)           (TRUE != FALSE)
#define NvM_HasCrcCompMechanismBuffer_WDFC_ID_MAX_FDCOfPCPartitionConfig(partitionIndex)            (TRUE != FALSE)
#define NvM_HasCrcCompMechanismBuffer_WDFC_ID_MIRROR_CFGOfPCPartitionConfig(partitionIndex)         (TRUE != FALSE)
#define NvM_HasCrcCompMechanismBuffer_WDFC_ID_MIRROR_OTHER_1OfPCPartitionConfig(partitionIndex)     (TRUE != FALSE)
#define NvM_HasCrcCompMechanismBuffer_WDFC_ID_MIRROR_POS_RECOfPCPartitionConfig(partitionIndex)     (TRUE != FALSE)
#define NvM_HasCrcCompMechanismBuffer_WDFC_ID_MIRROR_STOfPCPartitionConfig(partitionIndex)          (TRUE != FALSE)
#define NvM_HasCrcCompMechanismBuffer_WDFC_ID_PART_NUMBER_GEELYOfPCPartitionConfig(partitionIndex)  (TRUE != FALSE)
#define NvM_HasCrcCompMechanismBuffer_WDFC_ID_PMMOfPCPartitionConfig(partitionIndex)                (TRUE != FALSE)
#define NvM_HasCrcCompMechanismBuffer_WDFC_ID_QCM_FAULT_DATAOfPCPartitionConfig(partitionIndex)     (TRUE != FALSE)
#define NvM_HasCrcCompMechanismBuffer_WDFC_ID_SECURITY_ACCESSOfPCPartitionConfig(partitionIndex)    (TRUE != FALSE)
#define NvM_HasCrcCompMechanismBuffer_WDFC_ID_SR_PROFILEOfPCPartitionConfig(partitionIndex)         (TRUE != FALSE)
#define NvM_HasCrcCompMechanismBuffer_WDFC_ID_SWP1OfPCPartitionConfig(partitionIndex)               (TRUE != FALSE)
#define NvM_HasCrcCompMechanismBuffer_WDFC_ID_THPAOfPCPartitionConfig(partitionIndex)               (TRUE != FALSE)
#define NvM_HasCrcCompMechanismBuffer_WDFC_ID_VEH_CFGOfPCPartitionConfig(partitionIndex)            (TRUE != FALSE)
#define NvM_HasCrcCompMechanismBuffer_WDFC_ID_VOL_POWER_MODE_CFGOfPCPartitionConfig(partitionIndex) (TRUE != FALSE)
#define NvM_HasCrcCompMechanismBuffer_WDFC_ID_WLC_AP_LEARNOfPCPartitionConfig(partitionIndex)       (TRUE != FALSE)
#define NvM_HasCrcCompMechanismBuffer_WDFC_ID_WL_INFOOfPCPartitionConfig(partitionIndex)            (TRUE != FALSE)
#define NvM_HasCrcCompMechanismBuffer_WDFC_ID_WL_LOGOfPCPartitionConfig(partitionIndex)             (TRUE != FALSE)
#define NvM_HasDataIntegrityFsm_InstanceOfPCPartitionConfig(partitionIndex)                         (TRUE != FALSE)
#define NvM_HasDataIntegrityIntBuffer_DemAdminDataBlockOfPCPartitionConfig(partitionIndex)          (TRUE != FALSE)
#define NvM_HasDataIntegrityIntBuffer_DemStatusDataBlockOfPCPartitionConfig(partitionIndex)         (TRUE != FALSE)
#define NvM_HasDataIntegrityIntBuffer_WDFC_ID_AP_CONNEXOfPCPartitionConfig(partitionIndex)          (TRUE != FALSE)
#define NvM_HasDataIntegrityIntBuffer_WDFC_ID_AP_PARAOfPCPartitionConfig(partitionIndex)            (TRUE != FALSE)
#define NvM_HasDataIntegrityIntBuffer_WDFC_ID_BOOT_PARAOfPCPartitionConfig(partitionIndex)          (TRUE != FALSE)
#define NvM_HasDataIntegrityIntBuffer_WDFC_ID_CCPOfPCPartitionConfig(partitionIndex)                (TRUE != FALSE)
#define NvM_HasDataIntegrityIntBuffer_WDFC_ID_DEBUG_DATAOfPCPartitionConfig(partitionIndex)         (TRUE != FALSE)
#define NvM_HasDataIntegrityIntBuffer_WDFC_ID_DLCOfPCPartitionConfig(partitionIndex)                (TRUE != FALSE)
#define NvM_HasDataIntegrityIntBuffer_WDFC_ID_DTCTimeOfPCPartitionConfig(partitionIndex)            (TRUE != FALSE)
#define NvM_HasDataIntegrityIntBuffer_WDFC_ID_ECUID_RDI_PROGRAMMING_INFOOfPCPartitionConfig(partitionIndex) (TRUE != FALSE)
#define NvM_HasDataIntegrityIntBuffer_WDFC_ID_EOL_HW_VERSIONOfPCPartitionConfig(partitionIndex)     (TRUE != FALSE)
#define NvM_HasDataIntegrityIntBuffer_WDFC_ID_EOL_INFOOfPCPartitionConfig(partitionIndex)           (TRUE != FALSE)
#define NvM_HasDataIntegrityIntBuffer_WDFC_ID_EOL_PASSWORDOfPCPartitionConfig(partitionIndex)       (TRUE != FALSE)
#define NvM_HasDataIntegrityIntBuffer_WDFC_ID_EOL_SWNUMBEROfPCPartitionConfig(partitionIndex)       (TRUE != FALSE)
#define NvM_HasDataIntegrityIntBuffer_WDFC_ID_FAULT_CODEOfPCPartitionConfig(partitionIndex)         (TRUE != FALSE)
#define NvM_HasDataIntegrityIntBuffer_WDFC_ID_HANDLE_CFGOfPCPartitionConfig(partitionIndex)         (TRUE != FALSE)
#define NvM_HasDataIntegrityIntBuffer_WDFC_ID_IDENT_BANKOfPCPartitionConfig(partitionIndex)         (TRUE != FALSE)
#define NvM_HasDataIntegrityIntBuffer_WDFC_ID_IDOPTION_SECURITYOfPCPartitionConfig(partitionIndex)  (TRUE != FALSE)
#define NvM_HasDataIntegrityIntBuffer_WDFC_ID_LAST_FDCOfPCPartitionConfig(partitionIndex)           (TRUE != FALSE)
#define NvM_HasDataIntegrityIntBuffer_WDFC_ID_MAX_FDCOfPCPartitionConfig(partitionIndex)            (TRUE != FALSE)
#define NvM_HasDataIntegrityIntBuffer_WDFC_ID_MIRROR_CFGOfPCPartitionConfig(partitionIndex)         (TRUE != FALSE)
#define NvM_HasDataIntegrityIntBuffer_WDFC_ID_MIRROR_OTHER_1OfPCPartitionConfig(partitionIndex)     (TRUE != FALSE)
#define NvM_HasDataIntegrityIntBuffer_WDFC_ID_MIRROR_POS_RECOfPCPartitionConfig(partitionIndex)     (TRUE != FALSE)
#define NvM_HasDataIntegrityIntBuffer_WDFC_ID_MIRROR_STOfPCPartitionConfig(partitionIndex)          (TRUE != FALSE)
#define NvM_HasDataIntegrityIntBuffer_WDFC_ID_PART_NUMBER_GEELYOfPCPartitionConfig(partitionIndex)  (TRUE != FALSE)
#define NvM_HasDataIntegrityIntBuffer_WDFC_ID_PMMOfPCPartitionConfig(partitionIndex)                (TRUE != FALSE)
#define NvM_HasDataIntegrityIntBuffer_WDFC_ID_QCM_FAULT_DATAOfPCPartitionConfig(partitionIndex)     (TRUE != FALSE)
#define NvM_HasDataIntegrityIntBuffer_WDFC_ID_SECURITY_ACCESSOfPCPartitionConfig(partitionIndex)    (TRUE != FALSE)
#define NvM_HasDataIntegrityIntBuffer_WDFC_ID_SR_PROFILEOfPCPartitionConfig(partitionIndex)         (TRUE != FALSE)
#define NvM_HasDataIntegrityIntBuffer_WDFC_ID_SWP1OfPCPartitionConfig(partitionIndex)               (TRUE != FALSE)
#define NvM_HasDataIntegrityIntBuffer_WDFC_ID_THPAOfPCPartitionConfig(partitionIndex)               (TRUE != FALSE)
#define NvM_HasDataIntegrityIntBuffer_WDFC_ID_VEH_CFGOfPCPartitionConfig(partitionIndex)            (TRUE != FALSE)
#define NvM_HasDataIntegrityIntBuffer_WDFC_ID_VOL_POWER_MODE_CFGOfPCPartitionConfig(partitionIndex) (TRUE != FALSE)
#define NvM_HasDataIntegrityIntBuffer_WDFC_ID_WLC_AP_LEARNOfPCPartitionConfig(partitionIndex)       (TRUE != FALSE)
#define NvM_HasDataIntegrityIntBuffer_WDFC_ID_WL_INFOOfPCPartitionConfig(partitionIndex)            (TRUE != FALSE)
#define NvM_HasDataIntegrityIntBuffer_WDFC_ID_WL_LOGOfPCPartitionConfig(partitionIndex)             (TRUE != FALSE)
#define NvM_HasDataIntegrityRecalcQueue_InstanceOfPCPartitionConfig(partitionIndex)                 (TRUE != FALSE)
#define NvM_HasDcmBlockManagementInfoOfPCPartitionConfig(partitionIndex)                            (TRUE != FALSE)
#define NvM_HasForegroundDataIntegrityService_InstanceOfPCPartitionConfig(partitionIndex)           (TRUE != FALSE)
#define NvM_HasInternalBufferOfPCPartitionConfig(partitionIndex)                                    (TRUE != FALSE)
#define NvM_HasMultiBlockFsmLib_ProcessingStackElementOfPCPartitionConfig(partitionIndex)           (TRUE != FALSE)
#define NvM_HasMultiBlockJobFsm_ContextOfPCPartitionConfig(partitionIndex)                          (TRUE != FALSE)
#define NvM_HasMultiBlockJobFsm_InstanceOfPCPartitionConfig(partitionIndex)                         (TRUE != FALSE)
#define NvM_HasMultiBlockJobInformationOfPCPartitionConfig(partitionIndex)                          (TRUE != FALSE)
#define NvM_HasMultiBlockJobOfPCPartitionConfig(partitionIndex)                                     (TRUE != FALSE)
#define NvM_HasMultiBlockProcessorFsmLib_InstanceOfPCPartitionConfig(partitionIndex)                (TRUE != FALSE)
#define NvM_HasMultiBlockProcessorFsmLib_ProcessingStackElementOfPCPartitionConfig(partitionIndex)  (TRUE != FALSE)
#define NvM_HasMultiBlockServiceFsmLib_InstanceOfPCPartitionConfig(partitionIndex)                  (TRUE != FALSE)
#define NvM_HasNvJobContextOfPCPartitionConfig(partitionIndex)                                      (TRUE != FALSE)
#define NvM_HasNvJobFsm_InstanceOfPCPartitionConfig(partitionIndex)                                 (TRUE != FALSE)
#define NvM_HasNvServiceFsmLib_InstanceOfPCPartitionConfig(partitionIndex)                          (TRUE != FALSE)
#define NvM_HasNvServiceFsmLib_ProcessingStackElementOfPCPartitionConfig(partitionIndex)            (TRUE != FALSE)
#define NvM_HasNvServiceProcessorFsmLib_InstanceOfPCPartitionConfig(partitionIndex)                 (TRUE != FALSE)
#define NvM_HasNvServiceProcessorFsmLib_ProcessingStackElementOfPCPartitionConfig(partitionIndex)   (TRUE != FALSE)
#define NvM_HasQueueListOfPCPartitionConfig(partitionIndex)                                         (TRUE != FALSE)
#define NvM_HasQueue_InstanceOfPCPartitionConfig(partitionIndex)                                    (TRUE != FALSE)
#define NvM_HasReadAllFsm_ContextOfPCPartitionConfig(partitionIndex)                                (TRUE != FALSE)
#define NvM_HasReadAllFsm_InstanceOfPCPartitionConfig(partitionIndex)                               (TRUE != FALSE)
#define NvM_HasReadBlockFsm_ContextOfPCPartitionConfig(partitionIndex)                              (TRUE != FALSE)
#define NvM_HasReadBlockFsm_InstanceOfPCPartitionConfig(partitionIndex)                             (TRUE != FALSE)
#define NvM_HasServiceProcessorFsmLib_InstanceOfPCPartitionConfig(partitionIndex)                   (TRUE != FALSE)
#define NvM_HasServiceProcessorFsmLib_ProcessingStackElementOfPCPartitionConfig(partitionIndex)     (TRUE != FALSE)
#define NvM_HasServiceProcessorFsm_ContextOfPCPartitionConfig(partitionIndex)                       (TRUE != FALSE)
#define NvM_HasServiceProcessorFsm_InstanceOfPCPartitionConfig(partitionIndex)                      (TRUE != FALSE)
#define NvM_HasSingleBlockFsmLib_ProcessingStackElementOfPCPartitionConfig(partitionIndex)          (TRUE != FALSE)
#define NvM_HasSingleBlockJobContextOfPCPartitionConfig(partitionIndex)                             (TRUE != FALSE)
#define NvM_HasSingleBlockJobFsm_InstanceOfPCPartitionConfig(partitionIndex)                        (TRUE != FALSE)
#define NvM_HasSingleBlockServiceFsmLib_InstanceOfPCPartitionConfig(partitionIndex)                 (TRUE != FALSE)
#define NvM_HasSizeOfBackgroundCrcRecalcFsmLib_ProcessingStackElementOfPCPartitionConfig(partitionIndex) (TRUE != FALSE)
#define NvM_HasSizeOfBlockDescriptorOfPCPartitionConfig()                                           (TRUE != FALSE)
#define NvM_HasSizeOfCrcCompMechanismBuffer_DemAdminDataBlockOfPCPartitionConfig(partitionIndex)    (TRUE != FALSE)
#define NvM_HasSizeOfCrcCompMechanismBuffer_DemStatusDataBlockOfPCPartitionConfig(partitionIndex)   (TRUE != FALSE)
#define NvM_HasSizeOfCrcCompMechanismBuffer_NvMConfigBlockOfPCPartitionConfig(partitionIndex)       (TRUE != FALSE)
#define NvM_HasSizeOfCrcCompMechanismBuffer_WDFC_ID_AP_CONNEXOfPCPartitionConfig(partitionIndex)    (TRUE != FALSE)
#define NvM_HasSizeOfCrcCompMechanismBuffer_WDFC_ID_AP_PARAOfPCPartitionConfig(partitionIndex)      (TRUE != FALSE)
#define NvM_HasSizeOfCrcCompMechanismBuffer_WDFC_ID_BOOT_PARAOfPCPartitionConfig(partitionIndex)    (TRUE != FALSE)
#define NvM_HasSizeOfCrcCompMechanismBuffer_WDFC_ID_CCPOfPCPartitionConfig(partitionIndex)          (TRUE != FALSE)
#define NvM_HasSizeOfCrcCompMechanismBuffer_WDFC_ID_DEBUG_DATAOfPCPartitionConfig(partitionIndex)   (TRUE != FALSE)
#define NvM_HasSizeOfCrcCompMechanismBuffer_WDFC_ID_DLCOfPCPartitionConfig(partitionIndex)          (TRUE != FALSE)
#define NvM_HasSizeOfCrcCompMechanismBuffer_WDFC_ID_DTCTimeOfPCPartitionConfig(partitionIndex)      (TRUE != FALSE)
#define NvM_HasSizeOfCrcCompMechanismBuffer_WDFC_ID_ECUID_RDI_PROGRAMMING_INFOOfPCPartitionConfig(partitionIndex) (TRUE != FALSE)
#define NvM_HasSizeOfCrcCompMechanismBuffer_WDFC_ID_EOL_HW_VERSIONOfPCPartitionConfig(partitionIndex) (TRUE != FALSE)
#define NvM_HasSizeOfCrcCompMechanismBuffer_WDFC_ID_EOL_INFOOfPCPartitionConfig(partitionIndex)     (TRUE != FALSE)
#define NvM_HasSizeOfCrcCompMechanismBuffer_WDFC_ID_EOL_PASSWORDOfPCPartitionConfig(partitionIndex) (TRUE != FALSE)
#define NvM_HasSizeOfCrcCompMechanismBuffer_WDFC_ID_EOL_SWNUMBEROfPCPartitionConfig(partitionIndex) (TRUE != FALSE)
#define NvM_HasSizeOfCrcCompMechanismBuffer_WDFC_ID_FAULT_CODEOfPCPartitionConfig(partitionIndex)   (TRUE != FALSE)
#define NvM_HasSizeOfCrcCompMechanismBuffer_WDFC_ID_HANDLE_CFGOfPCPartitionConfig(partitionIndex)   (TRUE != FALSE)
#define NvM_HasSizeOfCrcCompMechanismBuffer_WDFC_ID_IDENT_BANKOfPCPartitionConfig(partitionIndex)   (TRUE != FALSE)
#define NvM_HasSizeOfCrcCompMechanismBuffer_WDFC_ID_IDOPTION_SECURITYOfPCPartitionConfig(partitionIndex) (TRUE != FALSE)
#define NvM_HasSizeOfCrcCompMechanismBuffer_WDFC_ID_LAST_FDCOfPCPartitionConfig(partitionIndex)     (TRUE != FALSE)
#define NvM_HasSizeOfCrcCompMechanismBuffer_WDFC_ID_MAX_FDCOfPCPartitionConfig(partitionIndex)      (TRUE != FALSE)
#define NvM_HasSizeOfCrcCompMechanismBuffer_WDFC_ID_MIRROR_CFGOfPCPartitionConfig(partitionIndex)   (TRUE != FALSE)
#define NvM_HasSizeOfCrcCompMechanismBuffer_WDFC_ID_MIRROR_OTHER_1OfPCPartitionConfig(partitionIndex) (TRUE != FALSE)
#define NvM_HasSizeOfCrcCompMechanismBuffer_WDFC_ID_MIRROR_POS_RECOfPCPartitionConfig(partitionIndex) (TRUE != FALSE)
#define NvM_HasSizeOfCrcCompMechanismBuffer_WDFC_ID_MIRROR_STOfPCPartitionConfig(partitionIndex)    (TRUE != FALSE)
#define NvM_HasSizeOfCrcCompMechanismBuffer_WDFC_ID_PART_NUMBER_GEELYOfPCPartitionConfig(partitionIndex) (TRUE != FALSE)
#define NvM_HasSizeOfCrcCompMechanismBuffer_WDFC_ID_PMMOfPCPartitionConfig(partitionIndex)          (TRUE != FALSE)
#define NvM_HasSizeOfCrcCompMechanismBuffer_WDFC_ID_QCM_FAULT_DATAOfPCPartitionConfig(partitionIndex) (TRUE != FALSE)
#define NvM_HasSizeOfCrcCompMechanismBuffer_WDFC_ID_SECURITY_ACCESSOfPCPartitionConfig(partitionIndex) (TRUE != FALSE)
#define NvM_HasSizeOfCrcCompMechanismBuffer_WDFC_ID_SR_PROFILEOfPCPartitionConfig(partitionIndex)   (TRUE != FALSE)
#define NvM_HasSizeOfCrcCompMechanismBuffer_WDFC_ID_SWP1OfPCPartitionConfig(partitionIndex)         (TRUE != FALSE)
#define NvM_HasSizeOfCrcCompMechanismBuffer_WDFC_ID_THPAOfPCPartitionConfig(partitionIndex)         (TRUE != FALSE)
#define NvM_HasSizeOfCrcCompMechanismBuffer_WDFC_ID_VEH_CFGOfPCPartitionConfig(partitionIndex)      (TRUE != FALSE)
#define NvM_HasSizeOfCrcCompMechanismBuffer_WDFC_ID_VOL_POWER_MODE_CFGOfPCPartitionConfig(partitionIndex) (TRUE != FALSE)
#define NvM_HasSizeOfCrcCompMechanismBuffer_WDFC_ID_WLC_AP_LEARNOfPCPartitionConfig(partitionIndex) (TRUE != FALSE)
#define NvM_HasSizeOfCrcCompMechanismBuffer_WDFC_ID_WL_INFOOfPCPartitionConfig(partitionIndex)      (TRUE != FALSE)
#define NvM_HasSizeOfCrcCompMechanismBuffer_WDFC_ID_WL_LOGOfPCPartitionConfig(partitionIndex)       (TRUE != FALSE)
#define NvM_HasSizeOfDataIntegrityIntBuffer_DemAdminDataBlockOfPCPartitionConfig(partitionIndex)    (TRUE != FALSE)
#define NvM_HasSizeOfDataIntegrityIntBuffer_DemStatusDataBlockOfPCPartitionConfig(partitionIndex)   (TRUE != FALSE)
#define NvM_HasSizeOfDataIntegrityIntBuffer_WDFC_ID_AP_CONNEXOfPCPartitionConfig(partitionIndex)    (TRUE != FALSE)
#define NvM_HasSizeOfDataIntegrityIntBuffer_WDFC_ID_AP_PARAOfPCPartitionConfig(partitionIndex)      (TRUE != FALSE)
#define NvM_HasSizeOfDataIntegrityIntBuffer_WDFC_ID_BOOT_PARAOfPCPartitionConfig(partitionIndex)    (TRUE != FALSE)
#define NvM_HasSizeOfDataIntegrityIntBuffer_WDFC_ID_CCPOfPCPartitionConfig(partitionIndex)          (TRUE != FALSE)
#define NvM_HasSizeOfDataIntegrityIntBuffer_WDFC_ID_DEBUG_DATAOfPCPartitionConfig(partitionIndex)   (TRUE != FALSE)
#define NvM_HasSizeOfDataIntegrityIntBuffer_WDFC_ID_DLCOfPCPartitionConfig(partitionIndex)          (TRUE != FALSE)
#define NvM_HasSizeOfDataIntegrityIntBuffer_WDFC_ID_DTCTimeOfPCPartitionConfig(partitionIndex)      (TRUE != FALSE)
#define NvM_HasSizeOfDataIntegrityIntBuffer_WDFC_ID_ECUID_RDI_PROGRAMMING_INFOOfPCPartitionConfig(partitionIndex) (TRUE != FALSE)
#define NvM_HasSizeOfDataIntegrityIntBuffer_WDFC_ID_EOL_HW_VERSIONOfPCPartitionConfig(partitionIndex) (TRUE != FALSE)
#define NvM_HasSizeOfDataIntegrityIntBuffer_WDFC_ID_EOL_INFOOfPCPartitionConfig(partitionIndex)     (TRUE != FALSE)
#define NvM_HasSizeOfDataIntegrityIntBuffer_WDFC_ID_EOL_PASSWORDOfPCPartitionConfig(partitionIndex) (TRUE != FALSE)
#define NvM_HasSizeOfDataIntegrityIntBuffer_WDFC_ID_EOL_SWNUMBEROfPCPartitionConfig(partitionIndex) (TRUE != FALSE)
#define NvM_HasSizeOfDataIntegrityIntBuffer_WDFC_ID_FAULT_CODEOfPCPartitionConfig(partitionIndex)   (TRUE != FALSE)
#define NvM_HasSizeOfDataIntegrityIntBuffer_WDFC_ID_HANDLE_CFGOfPCPartitionConfig(partitionIndex)   (TRUE != FALSE)
#define NvM_HasSizeOfDataIntegrityIntBuffer_WDFC_ID_IDENT_BANKOfPCPartitionConfig(partitionIndex)   (TRUE != FALSE)
#define NvM_HasSizeOfDataIntegrityIntBuffer_WDFC_ID_IDOPTION_SECURITYOfPCPartitionConfig(partitionIndex) (TRUE != FALSE)
#define NvM_HasSizeOfDataIntegrityIntBuffer_WDFC_ID_LAST_FDCOfPCPartitionConfig(partitionIndex)     (TRUE != FALSE)
#define NvM_HasSizeOfDataIntegrityIntBuffer_WDFC_ID_MAX_FDCOfPCPartitionConfig(partitionIndex)      (TRUE != FALSE)
#define NvM_HasSizeOfDataIntegrityIntBuffer_WDFC_ID_MIRROR_CFGOfPCPartitionConfig(partitionIndex)   (TRUE != FALSE)
#define NvM_HasSizeOfDataIntegrityIntBuffer_WDFC_ID_MIRROR_OTHER_1OfPCPartitionConfig(partitionIndex) (TRUE != FALSE)
#define NvM_HasSizeOfDataIntegrityIntBuffer_WDFC_ID_MIRROR_POS_RECOfPCPartitionConfig(partitionIndex) (TRUE != FALSE)
#define NvM_HasSizeOfDataIntegrityIntBuffer_WDFC_ID_MIRROR_STOfPCPartitionConfig(partitionIndex)    (TRUE != FALSE)
#define NvM_HasSizeOfDataIntegrityIntBuffer_WDFC_ID_PART_NUMBER_GEELYOfPCPartitionConfig(partitionIndex) (TRUE != FALSE)
#define NvM_HasSizeOfDataIntegrityIntBuffer_WDFC_ID_PMMOfPCPartitionConfig(partitionIndex)          (TRUE != FALSE)
#define NvM_HasSizeOfDataIntegrityIntBuffer_WDFC_ID_QCM_FAULT_DATAOfPCPartitionConfig(partitionIndex) (TRUE != FALSE)
#define NvM_HasSizeOfDataIntegrityIntBuffer_WDFC_ID_SECURITY_ACCESSOfPCPartitionConfig(partitionIndex) (TRUE != FALSE)
#define NvM_HasSizeOfDataIntegrityIntBuffer_WDFC_ID_SR_PROFILEOfPCPartitionConfig(partitionIndex)   (TRUE != FALSE)
#define NvM_HasSizeOfDataIntegrityIntBuffer_WDFC_ID_SWP1OfPCPartitionConfig(partitionIndex)         (TRUE != FALSE)
#define NvM_HasSizeOfDataIntegrityIntBuffer_WDFC_ID_THPAOfPCPartitionConfig(partitionIndex)         (TRUE != FALSE)
#define NvM_HasSizeOfDataIntegrityIntBuffer_WDFC_ID_VEH_CFGOfPCPartitionConfig(partitionIndex)      (TRUE != FALSE)
#define NvM_HasSizeOfDataIntegrityIntBuffer_WDFC_ID_VOL_POWER_MODE_CFGOfPCPartitionConfig(partitionIndex) (TRUE != FALSE)
#define NvM_HasSizeOfDataIntegrityIntBuffer_WDFC_ID_WLC_AP_LEARNOfPCPartitionConfig(partitionIndex) (TRUE != FALSE)
#define NvM_HasSizeOfDataIntegrityIntBuffer_WDFC_ID_WL_INFOOfPCPartitionConfig(partitionIndex)      (TRUE != FALSE)
#define NvM_HasSizeOfDataIntegrityIntBuffer_WDFC_ID_WL_LOGOfPCPartitionConfig(partitionIndex)       (TRUE != FALSE)
#define NvM_HasSizeOfInternalBufferOfPCPartitionConfig(partitionIndex)                              (TRUE != FALSE)
#define NvM_HasSizeOfMultiBlockFsmLib_ProcessingStackElementOfPCPartitionConfig(partitionIndex)     (TRUE != FALSE)
#define NvM_HasSizeOfMultiBlockProcessorFsmLib_ProcessingStackElementOfPCPartitionConfig(partitionIndex) (TRUE != FALSE)
#define NvM_HasSizeOfNvServiceFsmLib_ProcessingStackElementOfPCPartitionConfig(partitionIndex)      (TRUE != FALSE)
#define NvM_HasSizeOfNvServiceProcessorFsmLib_ProcessingStackElementOfPCPartitionConfig(partitionIndex) (TRUE != FALSE)
#define NvM_HasSizeOfQueueListOfPCPartitionConfig(partitionIndex)                                   (TRUE != FALSE)
#define NvM_HasSizeOfServiceProcessorFsmLib_ProcessingStackElementOfPCPartitionConfig(partitionIndex) (TRUE != FALSE)
#define NvM_HasSizeOfSingleBlockFsmLib_ProcessingStackElementOfPCPartitionConfig(partitionIndex)    (TRUE != FALSE)
#define NvM_HasValidateAllFsm_InstanceOfPCPartitionConfig(partitionIndex)                           (TRUE != FALSE)
#define NvM_HasWriteAllFsm_ContextOfPCPartitionConfig(partitionIndex)                               (TRUE != FALSE)
#define NvM_HasWriteAllFsm_InstanceOfPCPartitionConfig(partitionIndex)                              (TRUE != FALSE)
#define NvM_HasWriteBlockFsm_ContextOfPCPartitionConfig(partitionIndex)                             (TRUE != FALSE)
#define NvM_HasWriteBlockFsm_InstanceOfPCPartitionConfig(partitionIndex)                            (TRUE != FALSE)
#define NvM_HasWriteNvBlockFsm_ContextOfPCPartitionConfig(partitionIndex)                           (TRUE != FALSE)
/** 
  \}
*/ 


/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL ACCESS FUNCTION MACROS
**********************************************************************************************************************/


#endif /* NVM_CFGDEFINES_H_PUBLIC */

/**********************************************************************************************************************
 *  END OF FILE: NvM_CfgDefines.h
 *********************************************************************************************************************/

