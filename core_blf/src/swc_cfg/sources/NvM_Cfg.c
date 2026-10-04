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
 *              File: NvM_Cfg.c
 *   Generation Time: 2026-06-12 19:21:15
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


#define NVM_CFG_SOURCE

#define RTE_MICROSAR_PIM_EXPORT /* Required for RTE ROM block definitions */

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "NvM_Cfg.h"
#include "NvM_PrivateCfg.h"
#include "MemIf.h" /* Required for MemIfDeviceIndex */





/***********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 **********************************************************************************************************************/


/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/
 

/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/
#define NVM_START_SEC_VAR_CLEARED_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
static VAR(uint8, NVM_PRIVATE_DATA) NvMConfigBlock_RamBlock[4u];
#define NVM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
uint8 Dem_Cfg_AdminData;
uint8 Dem_Cfg_StatusData;
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
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
  NvM_BlockDescriptor
**********************************************************************************************************************/
#define NVM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(NvM_BlockDescriptorType, NVM_CONST) NvM_BlockDescriptor[37] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     BlockDescriptor                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      */
  /*     0 */     { /*  NvMConfigBlock  */ 
      (NvM_RamAddressType)&NvMConfigBlock_RamBlock /*  RamBlockDataAddress  */ , 
      NULL_PTR /*  RomBlockDataAddress  */ , 
      NULL_PTR /*  InitBlockCallback  */ , 
      NULL_PTR /*  ExtendedInitBlockCallback  */ , 
      NULL_PTR /*  SingleBlockCallback  */ , 
      NULL_PTR /*  ExtendedSingleBlockCallback  */ , 
      NULL_PTR /*  BackgroundCrcRecalcCallback  */ , 
      NULL_PTR /*  WriteRamBlockToNvCallback  */ , 
      NULL_PTR /*  ReadRamBlockFromNvCallback  */ , 
      &NvM_BlockManagementInfo_NvMConfigBlock /*  BlockManagementInfo  */ , 
      NULL_PTR /*  DataIntegrityIntBuffer  */ , 
      (NvM_DataPtrType)&NvM_CrcCompMechanismBuffer_NvMConfigBlock /*  CrcCompMechanismBuffer  */ , 
              {
          NVM_SELECT_BLOCK_FOR_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_WRITE_BLOCK_ONCE_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_USE_AUTO_VALIDATION_OFF
        } /*  Flags  */ , 
      0u /*  MacGenerationJobId  */ , 
      0u /*  MacVerificationJobId  */ , 
      1u /*  NvramBlockIdentifier  */ , 
      NVM_CONFIG_BLOCK_PAYLOAD_LENGTH /*  NvBlockLength  */ , 
      0x0010u /*  HwAbsBlockNumber  */ , 
      0u /*  MacSize  */ , 
      2u /*  NvBlockNumber  */ , 
      127u /*  Priority  */ , 
      NVM_PARTITION_ID_MASTER /*  PartitionIndex  */ , 
      MEMIF_Fee_30_FlexNor /*  MemIfDeviceIndex  */ , 
      NVM_BLOCK_DATA_INTEGRITY_CRC_16 /*  DataIntegrityType  */ , 
      NVM_BLOCK_MANAGEMENT_TYPE_REDUNDANT /*  BlockManagementType  */ 
    }                                                                                                                                    ,
  /*     1 */     { /*  DemAdminDataBlock  */ 
      (NvM_RamAddressType)&Dem_Cfg_AdminData /*  RamBlockDataAddress  */ , 
      NULL_PTR /*  RomBlockDataAddress  */ , 
      NULL_PTR /*  InitBlockCallback  */ , 
      NULL_PTR /*  ExtendedInitBlockCallback  */ , 
      NULL_PTR /*  SingleBlockCallback  */ , 
      NULL_PTR /*  ExtendedSingleBlockCallback  */ , 
      NULL_PTR /*  BackgroundCrcRecalcCallback  */ , 
      NULL_PTR /*  WriteRamBlockToNvCallback  */ , 
      NULL_PTR /*  ReadRamBlockFromNvCallback  */ , 
      &NvM_BlockManagementInfo_DemAdminDataBlock /*  BlockManagementInfo  */ , 
      (NvM_DataPtrType)&NvM_DataIntegrityIntBuffer_DemAdminDataBlock /*  DataIntegrityIntBuffer  */ , 
      (NvM_DataPtrType)&NvM_CrcCompMechanismBuffer_DemAdminDataBlock /*  CrcCompMechanismBuffer  */ , 
              {
          NVM_SELECT_BLOCK_FOR_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_WRITE_BLOCK_ONCE_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_USE_AUTO_VALIDATION_OFF
        } /*  Flags  */ , 
      0u /*  MacGenerationJobId  */ , 
      0u /*  MacVerificationJobId  */ , 
      2u /*  NvramBlockIdentifier  */ , 
      12u /*  NvBlockLength  */ , 
      0x0020u /*  HwAbsBlockNumber  */ , 
      0u /*  MacSize  */ , 
      1u /*  NvBlockNumber  */ , 
      127u /*  Priority  */ , 
      NVM_PARTITION_ID_MASTER /*  PartitionIndex  */ , 
      MEMIF_Fee_30_FlexNor /*  MemIfDeviceIndex  */ , 
      NVM_BLOCK_DATA_INTEGRITY_CRC_16 /*  DataIntegrityType  */ , 
      NVM_BLOCK_MANAGEMENT_TYPE_NATIVE /*  BlockManagementType  */ 
    }                                                                                  ,
  /*     2 */     { /*  DemStatusDataBlock  */ 
      (NvM_RamAddressType)&Dem_Cfg_StatusData /*  RamBlockDataAddress  */ , 
      NULL_PTR /*  RomBlockDataAddress  */ , 
      NULL_PTR /*  InitBlockCallback  */ , 
      NULL_PTR /*  ExtendedInitBlockCallback  */ , 
      NULL_PTR /*  SingleBlockCallback  */ , 
      NULL_PTR /*  ExtendedSingleBlockCallback  */ , 
      NULL_PTR /*  BackgroundCrcRecalcCallback  */ , 
      NULL_PTR /*  WriteRamBlockToNvCallback  */ , 
      NULL_PTR /*  ReadRamBlockFromNvCallback  */ , 
      &NvM_BlockManagementInfo_DemStatusDataBlock /*  BlockManagementInfo  */ , 
      (NvM_DataPtrType)&NvM_DataIntegrityIntBuffer_DemStatusDataBlock /*  DataIntegrityIntBuffer  */ , 
      (NvM_DataPtrType)&NvM_CrcCompMechanismBuffer_DemStatusDataBlock /*  CrcCompMechanismBuffer  */ , 
              {
          NVM_SELECT_BLOCK_FOR_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_WRITE_BLOCK_ONCE_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_USE_AUTO_VALIDATION_OFF
        } /*  Flags  */ , 
      0u /*  MacGenerationJobId  */ , 
      0u /*  MacVerificationJobId  */ , 
      3u /*  NvramBlockIdentifier  */ , 
      134u /*  NvBlockLength  */ , 
      0x0030u /*  HwAbsBlockNumber  */ , 
      0u /*  MacSize  */ , 
      1u /*  NvBlockNumber  */ , 
      127u /*  Priority  */ , 
      NVM_PARTITION_ID_MASTER /*  PartitionIndex  */ , 
      MEMIF_Fee_30_FlexNor /*  MemIfDeviceIndex  */ , 
      NVM_BLOCK_DATA_INTEGRITY_CRC_16 /*  DataIntegrityType  */ , 
      NVM_BLOCK_MANAGEMENT_TYPE_NATIVE /*  BlockManagementType  */ 
    }                                                                           ,
  /*     3 */     { /*  WDFC_ID_IDENT_BANK  */ 
      (NvM_RamAddressType)&WDFS_RamIdentBank /*  RamBlockDataAddress  */ , 
      (NvM_RomAddressType)&WDFS_RomIdentBank /*  RomBlockDataAddress  */ , 
      NULL_PTR /*  InitBlockCallback  */ , 
      NULL_PTR /*  ExtendedInitBlockCallback  */ , 
      NULL_PTR /*  SingleBlockCallback  */ , 
      NULL_PTR /*  ExtendedSingleBlockCallback  */ , 
      NULL_PTR /*  BackgroundCrcRecalcCallback  */ , 
      NULL_PTR /*  WriteRamBlockToNvCallback  */ , 
      NULL_PTR /*  ReadRamBlockFromNvCallback  */ , 
      &NvM_BlockManagementInfo_WDFC_ID_IDENT_BANK /*  BlockManagementInfo  */ , 
      (NvM_DataPtrType)&NvM_DataIntegrityIntBuffer_WDFC_ID_IDENT_BANK /*  DataIntegrityIntBuffer  */ , 
      (NvM_DataPtrType)&NvM_CrcCompMechanismBuffer_WDFC_ID_IDENT_BANK /*  CrcCompMechanismBuffer  */ , 
              {
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_WRITE_BLOCK_ONCE_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_USE_AUTO_VALIDATION_OFF
        } /*  Flags  */ , 
      0u /*  MacGenerationJobId  */ , 
      0u /*  MacVerificationJobId  */ , 
      31u /*  NvramBlockIdentifier  */ , 
      108u /*  NvBlockLength  */ , 
      0x0160u /*  HwAbsBlockNumber  */ , 
      0u /*  MacSize  */ , 
      1u /*  NvBlockNumber  */ , 
      127u /*  Priority  */ , 
      NVM_PARTITION_ID_MASTER /*  PartitionIndex  */ , 
      MEMIF_Fee_30_FlexNor /*  MemIfDeviceIndex  */ , 
      NVM_BLOCK_DATA_INTEGRITY_CRC_16 /*  DataIntegrityType  */ , 
      NVM_BLOCK_MANAGEMENT_TYPE_NATIVE /*  BlockManagementType  */ 
    }                                                                    ,
  /*     4 */     { /*  WDFC_ID_CCP  */ 
      (NvM_RamAddressType)&WDFS_RamCCP /*  RamBlockDataAddress  */ , 
      (NvM_RomAddressType)&WDFS_RomCCP /*  RomBlockDataAddress  */ , 
      NULL_PTR /*  InitBlockCallback  */ , 
      NULL_PTR /*  ExtendedInitBlockCallback  */ , 
      NULL_PTR /*  SingleBlockCallback  */ , 
      NULL_PTR /*  ExtendedSingleBlockCallback  */ , 
      NULL_PTR /*  BackgroundCrcRecalcCallback  */ , 
      NULL_PTR /*  WriteRamBlockToNvCallback  */ , 
      NULL_PTR /*  ReadRamBlockFromNvCallback  */ , 
      &NvM_BlockManagementInfo_WDFC_ID_CCP /*  BlockManagementInfo  */ , 
      (NvM_DataPtrType)&NvM_DataIntegrityIntBuffer_WDFC_ID_CCP /*  DataIntegrityIntBuffer  */ , 
      (NvM_DataPtrType)&NvM_CrcCompMechanismBuffer_WDFC_ID_CCP /*  CrcCompMechanismBuffer  */ , 
              {
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_WRITE_BLOCK_ONCE_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_USE_AUTO_VALIDATION_OFF
        } /*  Flags  */ , 
      0u /*  MacGenerationJobId  */ , 
      0u /*  MacVerificationJobId  */ , 
      32u /*  NvramBlockIdentifier  */ , 
      144u /*  NvBlockLength  */ , 
      0x00B0u /*  HwAbsBlockNumber  */ , 
      0u /*  MacSize  */ , 
      1u /*  NvBlockNumber  */ , 
      127u /*  Priority  */ , 
      NVM_PARTITION_ID_MASTER /*  PartitionIndex  */ , 
      MEMIF_Fee_30_FlexNor /*  MemIfDeviceIndex  */ , 
      NVM_BLOCK_DATA_INTEGRITY_CRC_16 /*  DataIntegrityType  */ , 
      NVM_BLOCK_MANAGEMENT_TYPE_NATIVE /*  BlockManagementType  */ 
    }                                                                                                              ,
  /*     5 */     { /*  WDFC_ID_WL_INFO  */ 
      (NvM_RamAddressType)&WDFS_RamWL_INFO /*  RamBlockDataAddress  */ , 
      (NvM_RomAddressType)&WDFS_RomWL_INFO /*  RomBlockDataAddress  */ , 
      NULL_PTR /*  InitBlockCallback  */ , 
      NULL_PTR /*  ExtendedInitBlockCallback  */ , 
      NULL_PTR /*  SingleBlockCallback  */ , 
      NULL_PTR /*  ExtendedSingleBlockCallback  */ , 
      NULL_PTR /*  BackgroundCrcRecalcCallback  */ , 
      NULL_PTR /*  WriteRamBlockToNvCallback  */ , 
      NULL_PTR /*  ReadRamBlockFromNvCallback  */ , 
      &NvM_BlockManagementInfo_WDFC_ID_WL_INFO /*  BlockManagementInfo  */ , 
      (NvM_DataPtrType)&NvM_DataIntegrityIntBuffer_WDFC_ID_WL_INFO /*  DataIntegrityIntBuffer  */ , 
      (NvM_DataPtrType)&NvM_CrcCompMechanismBuffer_WDFC_ID_WL_INFO /*  CrcCompMechanismBuffer  */ , 
              {
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_WRITE_BLOCK_ONCE_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_USE_AUTO_VALIDATION_OFF
        } /*  Flags  */ , 
      0u /*  MacGenerationJobId  */ , 
      0u /*  MacVerificationJobId  */ , 
      33u /*  NvramBlockIdentifier  */ , 
      100u /*  NvBlockLength  */ , 
      0x0280u /*  HwAbsBlockNumber  */ , 
      0u /*  MacSize  */ , 
      1u /*  NvBlockNumber  */ , 
      127u /*  Priority  */ , 
      NVM_PARTITION_ID_MASTER /*  PartitionIndex  */ , 
      MEMIF_Fee_30_FlexNor /*  MemIfDeviceIndex  */ , 
      NVM_BLOCK_DATA_INTEGRITY_CRC_16 /*  DataIntegrityType  */ , 
      NVM_BLOCK_MANAGEMENT_TYPE_NATIVE /*  BlockManagementType  */ 
    }                                                                                      ,
  /*     6 */     { /*  WDFC_ID_WLC_AP_LEARN  */ 
      (NvM_RamAddressType)&WDFS_RamWLC_APLearn /*  RamBlockDataAddress  */ , 
      (NvM_RomAddressType)&WDFS_RomWLC_APLearn /*  RomBlockDataAddress  */ , 
      NULL_PTR /*  InitBlockCallback  */ , 
      NULL_PTR /*  ExtendedInitBlockCallback  */ , 
      NULL_PTR /*  SingleBlockCallback  */ , 
      NULL_PTR /*  ExtendedSingleBlockCallback  */ , 
      NULL_PTR /*  BackgroundCrcRecalcCallback  */ , 
      NULL_PTR /*  WriteRamBlockToNvCallback  */ , 
      NULL_PTR /*  ReadRamBlockFromNvCallback  */ , 
      &NvM_BlockManagementInfo_WDFC_ID_WLC_AP_LEARN /*  BlockManagementInfo  */ , 
      (NvM_DataPtrType)&NvM_DataIntegrityIntBuffer_WDFC_ID_WLC_AP_LEARN /*  DataIntegrityIntBuffer  */ , 
      (NvM_DataPtrType)&NvM_CrcCompMechanismBuffer_WDFC_ID_WLC_AP_LEARN /*  CrcCompMechanismBuffer  */ , 
              {
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_WRITE_BLOCK_ONCE_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_USE_AUTO_VALIDATION_OFF
        } /*  Flags  */ , 
      0u /*  MacGenerationJobId  */ , 
      0u /*  MacVerificationJobId  */ , 
      34u /*  NvramBlockIdentifier  */ , 
      1092u /*  NvBlockLength  */ , 
      0x0270u /*  HwAbsBlockNumber  */ , 
      0u /*  MacSize  */ , 
      2u /*  NvBlockNumber  */ , 
      127u /*  Priority  */ , 
      NVM_PARTITION_ID_MASTER /*  PartitionIndex  */ , 
      MEMIF_Fee_30_FlexNor /*  MemIfDeviceIndex  */ , 
      NVM_BLOCK_DATA_INTEGRITY_CRC_16 /*  DataIntegrityType  */ , 
      NVM_BLOCK_MANAGEMENT_TYPE_REDUNDANT /*  BlockManagementType  */ 
    }                                                    ,
  /*     7 */     { /*  WDFC_ID_DLC  */ 
      (NvM_RamAddressType)&WDFS_RamDLC /*  RamBlockDataAddress  */ , 
      (NvM_RomAddressType)&WDFS_RomDLC /*  RomBlockDataAddress  */ , 
      NULL_PTR /*  InitBlockCallback  */ , 
      NULL_PTR /*  ExtendedInitBlockCallback  */ , 
      NULL_PTR /*  SingleBlockCallback  */ , 
      NULL_PTR /*  ExtendedSingleBlockCallback  */ , 
      NULL_PTR /*  BackgroundCrcRecalcCallback  */ , 
      NULL_PTR /*  WriteRamBlockToNvCallback  */ , 
      NULL_PTR /*  ReadRamBlockFromNvCallback  */ , 
      &NvM_BlockManagementInfo_WDFC_ID_DLC /*  BlockManagementInfo  */ , 
      (NvM_DataPtrType)&NvM_DataIntegrityIntBuffer_WDFC_ID_DLC /*  DataIntegrityIntBuffer  */ , 
      (NvM_DataPtrType)&NvM_CrcCompMechanismBuffer_WDFC_ID_DLC /*  CrcCompMechanismBuffer  */ , 
              {
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_WRITE_BLOCK_ONCE_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_USE_AUTO_VALIDATION_OFF
        } /*  Flags  */ , 
      0u /*  MacGenerationJobId  */ , 
      0u /*  MacVerificationJobId  */ , 
      35u /*  NvramBlockIdentifier  */ , 
      36u /*  NvBlockLength  */ , 
      0x00D0u /*  HwAbsBlockNumber  */ , 
      0u /*  MacSize  */ , 
      2u /*  NvBlockNumber  */ , 
      127u /*  Priority  */ , 
      NVM_PARTITION_ID_MASTER /*  PartitionIndex  */ , 
      MEMIF_Fee_30_FlexNor /*  MemIfDeviceIndex  */ , 
      NVM_BLOCK_DATA_INTEGRITY_CRC_16 /*  DataIntegrityType  */ , 
      NVM_BLOCK_MANAGEMENT_TYPE_REDUNDANT /*  BlockManagementType  */ 
    }                                                                                                            ,
  /*     8 */     { /*  WDFC_ID_AP_CONNEX  */ 
      (NvM_RamAddressType)&WDFS_RamAPConnex /*  RamBlockDataAddress  */ , 
      (NvM_RomAddressType)&WDFS_RomAPConnex /*  RomBlockDataAddress  */ , 
      NULL_PTR /*  InitBlockCallback  */ , 
      NULL_PTR /*  ExtendedInitBlockCallback  */ , 
      NULL_PTR /*  SingleBlockCallback  */ , 
      NULL_PTR /*  ExtendedSingleBlockCallback  */ , 
      NULL_PTR /*  BackgroundCrcRecalcCallback  */ , 
      NULL_PTR /*  WriteRamBlockToNvCallback  */ , 
      NULL_PTR /*  ReadRamBlockFromNvCallback  */ , 
      &NvM_BlockManagementInfo_WDFC_ID_AP_CONNEX /*  BlockManagementInfo  */ , 
      (NvM_DataPtrType)&NvM_DataIntegrityIntBuffer_WDFC_ID_AP_CONNEX /*  DataIntegrityIntBuffer  */ , 
      (NvM_DataPtrType)&NvM_CrcCompMechanismBuffer_WDFC_ID_AP_CONNEX /*  CrcCompMechanismBuffer  */ , 
              {
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_WRITE_BLOCK_ONCE_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_USE_AUTO_VALIDATION_OFF
        } /*  Flags  */ , 
      0u /*  MacGenerationJobId  */ , 
      0u /*  MacVerificationJobId  */ , 
      36u /*  NvramBlockIdentifier  */ , 
      36u /*  NvBlockLength  */ , 
      0x0080u /*  HwAbsBlockNumber  */ , 
      0u /*  MacSize  */ , 
      1u /*  NvBlockNumber  */ , 
      127u /*  Priority  */ , 
      NVM_PARTITION_ID_MASTER /*  PartitionIndex  */ , 
      MEMIF_Fee_30_FlexNor /*  MemIfDeviceIndex  */ , 
      NVM_BLOCK_DATA_INTEGRITY_CRC_16 /*  DataIntegrityType  */ , 
      NVM_BLOCK_MANAGEMENT_TYPE_NATIVE /*  BlockManagementType  */ 
    }                                                                             ,
  /*     9 */     { /*  WDFC_ID_HANDLE_CFG  */ 
      (NvM_RamAddressType)&WDFS_RamHandleCfg /*  RamBlockDataAddress  */ , 
      (NvM_RomAddressType)&WDFS_RomHandleCfg /*  RomBlockDataAddress  */ , 
      NULL_PTR /*  InitBlockCallback  */ , 
      NULL_PTR /*  ExtendedInitBlockCallback  */ , 
      NULL_PTR /*  SingleBlockCallback  */ , 
      NULL_PTR /*  ExtendedSingleBlockCallback  */ , 
      NULL_PTR /*  BackgroundCrcRecalcCallback  */ , 
      NULL_PTR /*  WriteRamBlockToNvCallback  */ , 
      NULL_PTR /*  ReadRamBlockFromNvCallback  */ , 
      &NvM_BlockManagementInfo_WDFC_ID_HANDLE_CFG /*  BlockManagementInfo  */ , 
      (NvM_DataPtrType)&NvM_DataIntegrityIntBuffer_WDFC_ID_HANDLE_CFG /*  DataIntegrityIntBuffer  */ , 
      (NvM_DataPtrType)&NvM_CrcCompMechanismBuffer_WDFC_ID_HANDLE_CFG /*  CrcCompMechanismBuffer  */ , 
              {
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_WRITE_BLOCK_ONCE_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_USE_AUTO_VALIDATION_OFF
        } /*  Flags  */ , 
      0u /*  MacGenerationJobId  */ , 
      0u /*  MacVerificationJobId  */ , 
      37u /*  NvramBlockIdentifier  */ , 
      16u /*  NvBlockLength  */ , 
      0x0150u /*  HwAbsBlockNumber  */ , 
      0u /*  MacSize  */ , 
      1u /*  NvBlockNumber  */ , 
      127u /*  Priority  */ , 
      NVM_PARTITION_ID_MASTER /*  PartitionIndex  */ , 
      MEMIF_Fee_30_FlexNor /*  MemIfDeviceIndex  */ , 
      NVM_BLOCK_DATA_INTEGRITY_CRC_16 /*  DataIntegrityType  */ , 
      NVM_BLOCK_MANAGEMENT_TYPE_NATIVE /*  BlockManagementType  */ 
    }                                                                       ,
  /*    10 */     { /*  WDFC_ID_MIRROR_CFG  */ 
      (NvM_RamAddressType)&WDFS_RamMirrorCfg /*  RamBlockDataAddress  */ , 
      (NvM_RomAddressType)&WDFS_RomMirrorCfg /*  RomBlockDataAddress  */ , 
      NULL_PTR /*  InitBlockCallback  */ , 
      NULL_PTR /*  ExtendedInitBlockCallback  */ , 
      NULL_PTR /*  SingleBlockCallback  */ , 
      NULL_PTR /*  ExtendedSingleBlockCallback  */ , 
      NULL_PTR /*  BackgroundCrcRecalcCallback  */ , 
      NULL_PTR /*  WriteRamBlockToNvCallback  */ , 
      NULL_PTR /*  ReadRamBlockFromNvCallback  */ , 
      &NvM_BlockManagementInfo_WDFC_ID_MIRROR_CFG /*  BlockManagementInfo  */ , 
      (NvM_DataPtrType)&NvM_DataIntegrityIntBuffer_WDFC_ID_MIRROR_CFG /*  DataIntegrityIntBuffer  */ , 
      (NvM_DataPtrType)&NvM_CrcCompMechanismBuffer_WDFC_ID_MIRROR_CFG /*  CrcCompMechanismBuffer  */ , 
              {
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_WRITE_BLOCK_ONCE_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_USE_AUTO_VALIDATION_OFF
        } /*  Flags  */ , 
      0u /*  MacGenerationJobId  */ , 
      0u /*  MacVerificationJobId  */ , 
      38u /*  NvramBlockIdentifier  */ , 
      16u /*  NvBlockLength  */ , 
      0x01A0u /*  HwAbsBlockNumber  */ , 
      0u /*  MacSize  */ , 
      1u /*  NvBlockNumber  */ , 
      127u /*  Priority  */ , 
      NVM_PARTITION_ID_MASTER /*  PartitionIndex  */ , 
      MEMIF_Fee_30_FlexNor /*  MemIfDeviceIndex  */ , 
      NVM_BLOCK_DATA_INTEGRITY_CRC_16 /*  DataIntegrityType  */ , 
      NVM_BLOCK_MANAGEMENT_TYPE_NATIVE /*  BlockManagementType  */ 
    }                                                                     ,
  /*    11 */     { /*  WDFC_ID_PMM  */ 
      (NvM_RamAddressType)&WDFS_RamPMM /*  RamBlockDataAddress  */ , 
      (NvM_RomAddressType)&WDFS_RomPMM /*  RomBlockDataAddress  */ , 
      NULL_PTR /*  InitBlockCallback  */ , 
      NULL_PTR /*  ExtendedInitBlockCallback  */ , 
      NULL_PTR /*  SingleBlockCallback  */ , 
      NULL_PTR /*  ExtendedSingleBlockCallback  */ , 
      NULL_PTR /*  BackgroundCrcRecalcCallback  */ , 
      NULL_PTR /*  WriteRamBlockToNvCallback  */ , 
      NULL_PTR /*  ReadRamBlockFromNvCallback  */ , 
      &NvM_BlockManagementInfo_WDFC_ID_PMM /*  BlockManagementInfo  */ , 
      (NvM_DataPtrType)&NvM_DataIntegrityIntBuffer_WDFC_ID_PMM /*  DataIntegrityIntBuffer  */ , 
      (NvM_DataPtrType)&NvM_CrcCompMechanismBuffer_WDFC_ID_PMM /*  CrcCompMechanismBuffer  */ , 
              {
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_WRITE_BLOCK_ONCE_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_USE_AUTO_VALIDATION_OFF
        } /*  Flags  */ , 
      0u /*  MacGenerationJobId  */ , 
      0u /*  MacVerificationJobId  */ , 
      39u /*  NvramBlockIdentifier  */ , 
      76u /*  NvBlockLength  */ , 
      0x01F0u /*  HwAbsBlockNumber  */ , 
      0u /*  MacSize  */ , 
      1u /*  NvBlockNumber  */ , 
      127u /*  Priority  */ , 
      NVM_PARTITION_ID_MASTER /*  PartitionIndex  */ , 
      MEMIF_Fee_30_FlexNor /*  MemIfDeviceIndex  */ , 
      NVM_BLOCK_DATA_INTEGRITY_CRC_16 /*  DataIntegrityType  */ , 
      NVM_BLOCK_MANAGEMENT_TYPE_NATIVE /*  BlockManagementType  */ 
    }                                                                                                             ,
  /*    12 */     { /*  WDFC_ID_SWP1  */ 
      (NvM_RamAddressType)&WDFS_RamSWP1 /*  RamBlockDataAddress  */ , 
      (NvM_RomAddressType)&WDFS_RomSWP1 /*  RomBlockDataAddress  */ , 
      NULL_PTR /*  InitBlockCallback  */ , 
      NULL_PTR /*  ExtendedInitBlockCallback  */ , 
      NULL_PTR /*  SingleBlockCallback  */ , 
      NULL_PTR /*  ExtendedSingleBlockCallback  */ , 
      NULL_PTR /*  BackgroundCrcRecalcCallback  */ , 
      NULL_PTR /*  WriteRamBlockToNvCallback  */ , 
      NULL_PTR /*  ReadRamBlockFromNvCallback  */ , 
      &NvM_BlockManagementInfo_WDFC_ID_SWP1 /*  BlockManagementInfo  */ , 
      (NvM_DataPtrType)&NvM_DataIntegrityIntBuffer_WDFC_ID_SWP1 /*  DataIntegrityIntBuffer  */ , 
      (NvM_DataPtrType)&NvM_CrcCompMechanismBuffer_WDFC_ID_SWP1 /*  CrcCompMechanismBuffer  */ , 
              {
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_WRITE_BLOCK_ONCE_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_USE_AUTO_VALIDATION_OFF
        } /*  Flags  */ , 
      0u /*  MacGenerationJobId  */ , 
      0u /*  MacVerificationJobId  */ , 
      40u /*  NvramBlockIdentifier  */ , 
      1024u /*  NvBlockLength  */ , 
      0x0230u /*  HwAbsBlockNumber  */ , 
      0u /*  MacSize  */ , 
      1u /*  NvBlockNumber  */ , 
      127u /*  Priority  */ , 
      NVM_PARTITION_ID_MASTER /*  PartitionIndex  */ , 
      MEMIF_Fee_30_FlexNor /*  MemIfDeviceIndex  */ , 
      NVM_BLOCK_DATA_INTEGRITY_CRC_16 /*  DataIntegrityType  */ , 
      NVM_BLOCK_MANAGEMENT_TYPE_NATIVE /*  BlockManagementType  */ 
    }                                                                                                     ,
  /*    13 */     { /*  WDFC_ID_VOL_POWER_MODE_CFG  */ 
      (NvM_RamAddressType)&WDFS_RamVolPowerModeCfg /*  RamBlockDataAddress  */ , 
      (NvM_RomAddressType)&WDFS_RomVolPowerModeCfg /*  RomBlockDataAddress  */ , 
      NULL_PTR /*  InitBlockCallback  */ , 
      NULL_PTR /*  ExtendedInitBlockCallback  */ , 
      NULL_PTR /*  SingleBlockCallback  */ , 
      NULL_PTR /*  ExtendedSingleBlockCallback  */ , 
      NULL_PTR /*  BackgroundCrcRecalcCallback  */ , 
      NULL_PTR /*  WriteRamBlockToNvCallback  */ , 
      NULL_PTR /*  ReadRamBlockFromNvCallback  */ , 
      &NvM_BlockManagementInfo_WDFC_ID_VOL_POWER_MODE_CFG /*  BlockManagementInfo  */ , 
      (NvM_DataPtrType)&NvM_DataIntegrityIntBuffer_WDFC_ID_VOL_POWER_MODE_CFG /*  DataIntegrityIntBuffer  */ , 
      (NvM_DataPtrType)&NvM_CrcCompMechanismBuffer_WDFC_ID_VOL_POWER_MODE_CFG /*  CrcCompMechanismBuffer  */ , 
              {
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_WRITE_BLOCK_ONCE_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_USE_AUTO_VALIDATION_OFF
        } /*  Flags  */ , 
      0u /*  MacGenerationJobId  */ , 
      0u /*  MacVerificationJobId  */ , 
      41u /*  NvramBlockIdentifier  */ , 
      16u /*  NvBlockLength  */ , 
      0x0260u /*  HwAbsBlockNumber  */ , 
      0u /*  MacSize  */ , 
      1u /*  NvBlockNumber  */ , 
      127u /*  Priority  */ , 
      NVM_PARTITION_ID_MASTER /*  PartitionIndex  */ , 
      MEMIF_Fee_30_FlexNor /*  MemIfDeviceIndex  */ , 
      NVM_BLOCK_DATA_INTEGRITY_CRC_16 /*  DataIntegrityType  */ , 
      NVM_BLOCK_MANAGEMENT_TYPE_NATIVE /*  BlockManagementType  */ 
    }                         ,
  /*    14 */     { /*  WDFC_ID_ECUID_RDI_PROGRAMMING_INFO  */ 
      (NvM_RamAddressType)&WDFS_RamRDIProgInfo /*  RamBlockDataAddress  */ , 
      (NvM_RomAddressType)&WDFS_RomRDIProgInfo /*  RomBlockDataAddress  */ , 
      NULL_PTR /*  InitBlockCallback  */ , 
      NULL_PTR /*  ExtendedInitBlockCallback  */ , 
      NULL_PTR /*  SingleBlockCallback  */ , 
      NULL_PTR /*  ExtendedSingleBlockCallback  */ , 
      NULL_PTR /*  BackgroundCrcRecalcCallback  */ , 
      NULL_PTR /*  WriteRamBlockToNvCallback  */ , 
      NULL_PTR /*  ReadRamBlockFromNvCallback  */ , 
      &NvM_BlockManagementInfo_WDFC_ID_ECUID_RDI_PROGRAMMING_INFO /*  BlockManagementInfo  */ , 
      (NvM_DataPtrType)&NvM_DataIntegrityIntBuffer_WDFC_ID_ECUID_RDI_PROGRAMMING_INFO /*  DataIntegrityIntBuffer  */ , 
      (NvM_DataPtrType)&NvM_CrcCompMechanismBuffer_WDFC_ID_ECUID_RDI_PROGRAMMING_INFO /*  CrcCompMechanismBuffer  */ , 
              {
          NVM_SELECT_BLOCK_FOR_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_WRITE_BLOCK_ONCE_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_USE_AUTO_VALIDATION_OFF
        } /*  Flags  */ , 
      0u /*  MacGenerationJobId  */ , 
      0u /*  MacVerificationJobId  */ , 
      42u /*  NvramBlockIdentifier  */ , 
      16u /*  NvBlockLength  */ , 
      0x00F0u /*  HwAbsBlockNumber  */ , 
      0u /*  MacSize  */ , 
      1u /*  NvBlockNumber  */ , 
      127u /*  Priority  */ , 
      NVM_PARTITION_ID_MASTER /*  PartitionIndex  */ , 
      MEMIF_Fee_30_FlexNor /*  MemIfDeviceIndex  */ , 
      NVM_BLOCK_DATA_INTEGRITY_CRC_16 /*  DataIntegrityType  */ , 
      NVM_BLOCK_MANAGEMENT_TYPE_NATIVE /*  BlockManagementType  */ 
    } ,
  /*    15 */     { /*  WDFC_ID_AP_PARA  */ 
      (NvM_RamAddressType)&WDFS_RamAP_Para /*  RamBlockDataAddress  */ , 
      (NvM_RomAddressType)&WDFS_RomAP_Para /*  RomBlockDataAddress  */ , 
      NULL_PTR /*  InitBlockCallback  */ , 
      NULL_PTR /*  ExtendedInitBlockCallback  */ , 
      NULL_PTR /*  SingleBlockCallback  */ , 
      NULL_PTR /*  ExtendedSingleBlockCallback  */ , 
      NULL_PTR /*  BackgroundCrcRecalcCallback  */ , 
      NULL_PTR /*  WriteRamBlockToNvCallback  */ , 
      NULL_PTR /*  ReadRamBlockFromNvCallback  */ , 
      &NvM_BlockManagementInfo_WDFC_ID_AP_PARA /*  BlockManagementInfo  */ , 
      (NvM_DataPtrType)&NvM_DataIntegrityIntBuffer_WDFC_ID_AP_PARA /*  DataIntegrityIntBuffer  */ , 
      (NvM_DataPtrType)&NvM_CrcCompMechanismBuffer_WDFC_ID_AP_PARA /*  CrcCompMechanismBuffer  */ , 
              {
          NVM_SELECT_BLOCK_FOR_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_WRITE_BLOCK_ONCE_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_USE_AUTO_VALIDATION_OFF
        } /*  Flags  */ , 
      0u /*  MacGenerationJobId  */ , 
      0u /*  MacVerificationJobId  */ , 
      43u /*  NvramBlockIdentifier  */ , 
      96u /*  NvBlockLength  */ , 
      0x0090u /*  HwAbsBlockNumber  */ , 
      0u /*  MacSize  */ , 
      1u /*  NvBlockNumber  */ , 
      127u /*  Priority  */ , 
      NVM_PARTITION_ID_MASTER /*  PartitionIndex  */ , 
      MEMIF_Fee_30_FlexNor /*  MemIfDeviceIndex  */ , 
      NVM_BLOCK_DATA_INTEGRITY_CRC_16 /*  DataIntegrityType  */ , 
      NVM_BLOCK_MANAGEMENT_TYPE_NATIVE /*  BlockManagementType  */ 
    }                                                                                      ,
  /*    16 */     { /*  WDFC_ID_MIRROR_ST  */ 
      (NvM_RamAddressType)&WDFS_RamMirrorSt /*  RamBlockDataAddress  */ , 
      (NvM_RomAddressType)&WDFS_RomMirrorSt /*  RomBlockDataAddress  */ , 
      NULL_PTR /*  InitBlockCallback  */ , 
      NULL_PTR /*  ExtendedInitBlockCallback  */ , 
      NULL_PTR /*  SingleBlockCallback  */ , 
      NULL_PTR /*  ExtendedSingleBlockCallback  */ , 
      NULL_PTR /*  BackgroundCrcRecalcCallback  */ , 
      NULL_PTR /*  WriteRamBlockToNvCallback  */ , 
      NULL_PTR /*  ReadRamBlockFromNvCallback  */ , 
      &NvM_BlockManagementInfo_WDFC_ID_MIRROR_ST /*  BlockManagementInfo  */ , 
      (NvM_DataPtrType)&NvM_DataIntegrityIntBuffer_WDFC_ID_MIRROR_ST /*  DataIntegrityIntBuffer  */ , 
      (NvM_DataPtrType)&NvM_CrcCompMechanismBuffer_WDFC_ID_MIRROR_ST /*  CrcCompMechanismBuffer  */ , 
              {
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_WRITE_BLOCK_ONCE_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_USE_AUTO_VALIDATION_OFF
        } /*  Flags  */ , 
      0u /*  MacGenerationJobId  */ , 
      0u /*  MacVerificationJobId  */ , 
      44u /*  NvramBlockIdentifier  */ , 
      24u /*  NvBlockLength  */ , 
      0x01D0u /*  HwAbsBlockNumber  */ , 
      0u /*  MacSize  */ , 
      1u /*  NvBlockNumber  */ , 
      127u /*  Priority  */ , 
      NVM_PARTITION_ID_MASTER /*  PartitionIndex  */ , 
      MEMIF_Fee_30_FlexNor /*  MemIfDeviceIndex  */ , 
      NVM_BLOCK_DATA_INTEGRITY_CRC_16 /*  DataIntegrityType  */ , 
      NVM_BLOCK_MANAGEMENT_TYPE_NATIVE /*  BlockManagementType  */ 
    }                                                                           ,
  /*    17 */     { /*  WDFC_ID_SR_PROFILE  */ 
      (NvM_RamAddressType)&WDFS_RamSR_PROFILE /*  RamBlockDataAddress  */ , 
      (NvM_RomAddressType)&WDFS_RomSR_PROFILE /*  RomBlockDataAddress  */ , 
      NULL_PTR /*  InitBlockCallback  */ , 
      NULL_PTR /*  ExtendedInitBlockCallback  */ , 
      NULL_PTR /*  SingleBlockCallback  */ , 
      NULL_PTR /*  ExtendedSingleBlockCallback  */ , 
      NULL_PTR /*  BackgroundCrcRecalcCallback  */ , 
      NULL_PTR /*  WriteRamBlockToNvCallback  */ , 
      NULL_PTR /*  ReadRamBlockFromNvCallback  */ , 
      &NvM_BlockManagementInfo_WDFC_ID_SR_PROFILE /*  BlockManagementInfo  */ , 
      (NvM_DataPtrType)&NvM_DataIntegrityIntBuffer_WDFC_ID_SR_PROFILE /*  DataIntegrityIntBuffer  */ , 
      (NvM_DataPtrType)&NvM_CrcCompMechanismBuffer_WDFC_ID_SR_PROFILE /*  CrcCompMechanismBuffer  */ , 
              {
          NVM_SELECT_BLOCK_FOR_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_WRITE_BLOCK_ONCE_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_USE_AUTO_VALIDATION_OFF
        } /*  Flags  */ , 
      0u /*  MacGenerationJobId  */ , 
      0u /*  MacVerificationJobId  */ , 
      45u /*  NvramBlockIdentifier  */ , 
      376u /*  NvBlockLength  */ , 
      0x0220u /*  HwAbsBlockNumber  */ , 
      0u /*  MacSize  */ , 
      1u /*  NvBlockNumber  */ , 
      127u /*  Priority  */ , 
      NVM_PARTITION_ID_MASTER /*  PartitionIndex  */ , 
      MEMIF_Fee_30_FlexNor /*  MemIfDeviceIndex  */ , 
      NVM_BLOCK_DATA_INTEGRITY_CRC_16 /*  DataIntegrityType  */ , 
      NVM_BLOCK_MANAGEMENT_TYPE_NATIVE /*  BlockManagementType  */ 
    }                                                                   ,
  /*    18 */     { /*  WDFC_ID_THPA  */ 
      (NvM_RamAddressType)&WDFS_RamTHPA /*  RamBlockDataAddress  */ , 
      (NvM_RomAddressType)&WDFS_RomTHPA /*  RomBlockDataAddress  */ , 
      NULL_PTR /*  InitBlockCallback  */ , 
      NULL_PTR /*  ExtendedInitBlockCallback  */ , 
      NULL_PTR /*  SingleBlockCallback  */ , 
      NULL_PTR /*  ExtendedSingleBlockCallback  */ , 
      NULL_PTR /*  BackgroundCrcRecalcCallback  */ , 
      NULL_PTR /*  WriteRamBlockToNvCallback  */ , 
      NULL_PTR /*  ReadRamBlockFromNvCallback  */ , 
      &NvM_BlockManagementInfo_WDFC_ID_THPA /*  BlockManagementInfo  */ , 
      (NvM_DataPtrType)&NvM_DataIntegrityIntBuffer_WDFC_ID_THPA /*  DataIntegrityIntBuffer  */ , 
      (NvM_DataPtrType)&NvM_CrcCompMechanismBuffer_WDFC_ID_THPA /*  CrcCompMechanismBuffer  */ , 
              {
          NVM_SELECT_BLOCK_FOR_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_WRITE_BLOCK_ONCE_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_USE_AUTO_VALIDATION_OFF
        } /*  Flags  */ , 
      0u /*  MacGenerationJobId  */ , 
      0u /*  MacVerificationJobId  */ , 
      46u /*  NvramBlockIdentifier  */ , 
      44u /*  NvBlockLength  */ , 
      0x0240u /*  HwAbsBlockNumber  */ , 
      0u /*  MacSize  */ , 
      1u /*  NvBlockNumber  */ , 
      127u /*  Priority  */ , 
      NVM_PARTITION_ID_MASTER /*  PartitionIndex  */ , 
      MEMIF_Fee_30_FlexNor /*  MemIfDeviceIndex  */ , 
      NVM_BLOCK_DATA_INTEGRITY_CRC_16 /*  DataIntegrityType  */ , 
      NVM_BLOCK_MANAGEMENT_TYPE_NATIVE /*  BlockManagementType  */ 
    }                                                                                                        ,
  /*    19 */     { /*  WDFC_ID_VEH_CFG  */ 
      (NvM_RamAddressType)&WDFS_RamVehCfg /*  RamBlockDataAddress  */ , 
      (NvM_RomAddressType)&WDFS_RomVehCfg /*  RomBlockDataAddress  */ , 
      NULL_PTR /*  InitBlockCallback  */ , 
      NULL_PTR /*  ExtendedInitBlockCallback  */ , 
      NULL_PTR /*  SingleBlockCallback  */ , 
      NULL_PTR /*  ExtendedSingleBlockCallback  */ , 
      NULL_PTR /*  BackgroundCrcRecalcCallback  */ , 
      NULL_PTR /*  WriteRamBlockToNvCallback  */ , 
      NULL_PTR /*  ReadRamBlockFromNvCallback  */ , 
      &NvM_BlockManagementInfo_WDFC_ID_VEH_CFG /*  BlockManagementInfo  */ , 
      (NvM_DataPtrType)&NvM_DataIntegrityIntBuffer_WDFC_ID_VEH_CFG /*  DataIntegrityIntBuffer  */ , 
      (NvM_DataPtrType)&NvM_CrcCompMechanismBuffer_WDFC_ID_VEH_CFG /*  CrcCompMechanismBuffer  */ , 
              {
          NVM_SELECT_BLOCK_FOR_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_WRITE_BLOCK_ONCE_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_USE_AUTO_VALIDATION_OFF
        } /*  Flags  */ , 
      0u /*  MacGenerationJobId  */ , 
      0u /*  MacVerificationJobId  */ , 
      47u /*  NvramBlockIdentifier  */ , 
      8u /*  NvBlockLength  */ , 
      0x0250u /*  HwAbsBlockNumber  */ , 
      0u /*  MacSize  */ , 
      1u /*  NvBlockNumber  */ , 
      127u /*  Priority  */ , 
      NVM_PARTITION_ID_MASTER /*  PartitionIndex  */ , 
      MEMIF_Fee_30_FlexNor /*  MemIfDeviceIndex  */ , 
      NVM_BLOCK_DATA_INTEGRITY_CRC_16 /*  DataIntegrityType  */ , 
      NVM_BLOCK_MANAGEMENT_TYPE_NATIVE /*  BlockManagementType  */ 
    }                                                                                         ,
  /*    20 */     { /*  WDFC_ID_WL_LOG  */ 
      (NvM_RamAddressType)&WDFS_RamWL_Log /*  RamBlockDataAddress  */ , 
      (NvM_RomAddressType)&WDFS_RomWL_Log /*  RomBlockDataAddress  */ , 
      NULL_PTR /*  InitBlockCallback  */ , 
      NULL_PTR /*  ExtendedInitBlockCallback  */ , 
      NULL_PTR /*  SingleBlockCallback  */ , 
      NULL_PTR /*  ExtendedSingleBlockCallback  */ , 
      NULL_PTR /*  BackgroundCrcRecalcCallback  */ , 
      NULL_PTR /*  WriteRamBlockToNvCallback  */ , 
      NULL_PTR /*  ReadRamBlockFromNvCallback  */ , 
      &NvM_BlockManagementInfo_WDFC_ID_WL_LOG /*  BlockManagementInfo  */ , 
      (NvM_DataPtrType)&NvM_DataIntegrityIntBuffer_WDFC_ID_WL_LOG /*  DataIntegrityIntBuffer  */ , 
      (NvM_DataPtrType)&NvM_CrcCompMechanismBuffer_WDFC_ID_WL_LOG /*  CrcCompMechanismBuffer  */ , 
              {
          NVM_SELECT_BLOCK_FOR_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_WRITE_BLOCK_ONCE_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_USE_AUTO_VALIDATION_OFF
        } /*  Flags  */ , 
      0u /*  MacGenerationJobId  */ , 
      0u /*  MacVerificationJobId  */ , 
      48u /*  NvramBlockIdentifier  */ , 
      524u /*  NvBlockLength  */ , 
      0x0290u /*  HwAbsBlockNumber  */ , 
      0u /*  MacSize  */ , 
      1u /*  NvBlockNumber  */ , 
      127u /*  Priority  */ , 
      NVM_PARTITION_ID_MASTER /*  PartitionIndex  */ , 
      MEMIF_Fee_30_FlexNor /*  MemIfDeviceIndex  */ , 
      NVM_BLOCK_DATA_INTEGRITY_CRC_16 /*  DataIntegrityType  */ , 
      NVM_BLOCK_MANAGEMENT_TYPE_NATIVE /*  BlockManagementType  */ 
    }                                                                                           ,
  /*    21 */     { /*  WDFC_ID_FAULT_CODE  */ 
      (NvM_RamAddressType)&WDFS_RamFaultcode[0] /*  RamBlockDataAddress  */ , 
      (NvM_RomAddressType)&WDFS_RomFaultcode[0] /*  RomBlockDataAddress  */ , 
      NULL_PTR /*  InitBlockCallback  */ , 
      NULL_PTR /*  ExtendedInitBlockCallback  */ , 
      NULL_PTR /*  SingleBlockCallback  */ , 
      NULL_PTR /*  ExtendedSingleBlockCallback  */ , 
      NULL_PTR /*  BackgroundCrcRecalcCallback  */ , 
      NULL_PTR /*  WriteRamBlockToNvCallback  */ , 
      NULL_PTR /*  ReadRamBlockFromNvCallback  */ , 
      &NvM_BlockManagementInfo_WDFC_ID_FAULT_CODE /*  BlockManagementInfo  */ , 
      (NvM_DataPtrType)&NvM_DataIntegrityIntBuffer_WDFC_ID_FAULT_CODE /*  DataIntegrityIntBuffer  */ , 
      (NvM_DataPtrType)&NvM_CrcCompMechanismBuffer_WDFC_ID_FAULT_CODE /*  CrcCompMechanismBuffer  */ , 
              {
          NVM_SELECT_BLOCK_FOR_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_WRITE_BLOCK_ONCE_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_USE_AUTO_VALIDATION_OFF
        } /*  Flags  */ , 
      0u /*  MacGenerationJobId  */ , 
      0u /*  MacVerificationJobId  */ , 
      49u /*  NvramBlockIdentifier  */ , 
      64u /*  NvBlockLength  */ , 
      0x0140u /*  HwAbsBlockNumber  */ , 
      0u /*  MacSize  */ , 
      1u /*  NvBlockNumber  */ , 
      127u /*  Priority  */ , 
      NVM_PARTITION_ID_MASTER /*  PartitionIndex  */ , 
      MEMIF_Fee_30_FlexNor /*  MemIfDeviceIndex  */ , 
      NVM_BLOCK_DATA_INTEGRITY_CRC_16 /*  DataIntegrityType  */ , 
      NVM_BLOCK_MANAGEMENT_TYPE_NATIVE /*  BlockManagementType  */ 
    }                                                                ,
  /*    22 */     { /*  WDFC_ID_BOOT_PARA  */ 
      (NvM_RamAddressType)&WDFS_RamBootPara /*  RamBlockDataAddress  */ , 
      (NvM_RomAddressType)&WDFS_RomBootPara /*  RomBlockDataAddress  */ , 
      NULL_PTR /*  InitBlockCallback  */ , 
      NULL_PTR /*  ExtendedInitBlockCallback  */ , 
      NULL_PTR /*  SingleBlockCallback  */ , 
      NULL_PTR /*  ExtendedSingleBlockCallback  */ , 
      NULL_PTR /*  BackgroundCrcRecalcCallback  */ , 
      NULL_PTR /*  WriteRamBlockToNvCallback  */ , 
      NULL_PTR /*  ReadRamBlockFromNvCallback  */ , 
      &NvM_BlockManagementInfo_WDFC_ID_BOOT_PARA /*  BlockManagementInfo  */ , 
      (NvM_DataPtrType)&NvM_DataIntegrityIntBuffer_WDFC_ID_BOOT_PARA /*  DataIntegrityIntBuffer  */ , 
      (NvM_DataPtrType)&NvM_CrcCompMechanismBuffer_WDFC_ID_BOOT_PARA /*  CrcCompMechanismBuffer  */ , 
              {
          NVM_SELECT_BLOCK_FOR_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_WRITE_BLOCK_ONCE_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_USE_AUTO_VALIDATION_OFF
        } /*  Flags  */ , 
      0u /*  MacGenerationJobId  */ , 
      0u /*  MacVerificationJobId  */ , 
      50u /*  NvramBlockIdentifier  */ , 
      344u /*  NvBlockLength  */ , 
      0x00A0u /*  HwAbsBlockNumber  */ , 
      0u /*  MacSize  */ , 
      1u /*  NvBlockNumber  */ , 
      127u /*  Priority  */ , 
      NVM_PARTITION_ID_MASTER /*  PartitionIndex  */ , 
      MEMIF_Fee_30_FlexNor /*  MemIfDeviceIndex  */ , 
      NVM_BLOCK_DATA_INTEGRITY_CRC_16 /*  DataIntegrityType  */ , 
      NVM_BLOCK_MANAGEMENT_TYPE_NATIVE /*  BlockManagementType  */ 
    }                                                                           ,
  /*    23 */     { /*  WDFC_ID_EOL_INFO  */ 
      (NvM_RamAddressType)&WDFS_RamEOL_INFO /*  RamBlockDataAddress  */ , 
      (NvM_RomAddressType)&WDFS_RomEOL_INFO /*  RomBlockDataAddress  */ , 
      NULL_PTR /*  InitBlockCallback  */ , 
      NULL_PTR /*  ExtendedInitBlockCallback  */ , 
      NULL_PTR /*  SingleBlockCallback  */ , 
      NULL_PTR /*  ExtendedSingleBlockCallback  */ , 
      NULL_PTR /*  BackgroundCrcRecalcCallback  */ , 
      NULL_PTR /*  WriteRamBlockToNvCallback  */ , 
      NULL_PTR /*  ReadRamBlockFromNvCallback  */ , 
      &NvM_BlockManagementInfo_WDFC_ID_EOL_INFO /*  BlockManagementInfo  */ , 
      (NvM_DataPtrType)&NvM_DataIntegrityIntBuffer_WDFC_ID_EOL_INFO /*  DataIntegrityIntBuffer  */ , 
      (NvM_DataPtrType)&NvM_CrcCompMechanismBuffer_WDFC_ID_EOL_INFO /*  CrcCompMechanismBuffer  */ , 
              {
          NVM_SELECT_BLOCK_FOR_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_WRITE_BLOCK_ONCE_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_USE_AUTO_VALIDATION_OFF
        } /*  Flags  */ , 
      0u /*  MacGenerationJobId  */ , 
      0u /*  MacVerificationJobId  */ , 
      51u /*  NvramBlockIdentifier  */ , 
      368u /*  NvBlockLength  */ , 
      0x0110u /*  HwAbsBlockNumber  */ , 
      0u /*  MacSize  */ , 
      1u /*  NvBlockNumber  */ , 
      127u /*  Priority  */ , 
      NVM_PARTITION_ID_MASTER /*  PartitionIndex  */ , 
      MEMIF_Fee_30_FlexNor /*  MemIfDeviceIndex  */ , 
      NVM_BLOCK_DATA_INTEGRITY_CRC_16 /*  DataIntegrityType  */ , 
      NVM_BLOCK_MANAGEMENT_TYPE_NATIVE /*  BlockManagementType  */ 
    }                                                                              ,
  /*    24 */     { /*  WDFC_ID_IDOPTION_SECURITY  */ 
      (NvM_RamAddressType)&WDFS_RamIDOptionSecurity /*  RamBlockDataAddress  */ , 
      (NvM_RomAddressType)&WDFS_RomIDOptionSecurity /*  RomBlockDataAddress  */ , 
      NULL_PTR /*  InitBlockCallback  */ , 
      NULL_PTR /*  ExtendedInitBlockCallback  */ , 
      NULL_PTR /*  SingleBlockCallback  */ , 
      NULL_PTR /*  ExtendedSingleBlockCallback  */ , 
      NULL_PTR /*  BackgroundCrcRecalcCallback  */ , 
      NULL_PTR /*  WriteRamBlockToNvCallback  */ , 
      NULL_PTR /*  ReadRamBlockFromNvCallback  */ , 
      &NvM_BlockManagementInfo_WDFC_ID_IDOPTION_SECURITY /*  BlockManagementInfo  */ , 
      (NvM_DataPtrType)&NvM_DataIntegrityIntBuffer_WDFC_ID_IDOPTION_SECURITY /*  DataIntegrityIntBuffer  */ , 
      (NvM_DataPtrType)&NvM_CrcCompMechanismBuffer_WDFC_ID_IDOPTION_SECURITY /*  CrcCompMechanismBuffer  */ , 
              {
          NVM_SELECT_BLOCK_FOR_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_WRITE_BLOCK_ONCE_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_USE_AUTO_VALIDATION_OFF
        } /*  Flags  */ , 
      0u /*  MacGenerationJobId  */ , 
      0u /*  MacVerificationJobId  */ , 
      52u /*  NvramBlockIdentifier  */ , 
      26u /*  NvBlockLength  */ , 
      0x0170u /*  HwAbsBlockNumber  */ , 
      0u /*  MacSize  */ , 
      1u /*  NvBlockNumber  */ , 
      127u /*  Priority  */ , 
      NVM_PARTITION_ID_MASTER /*  PartitionIndex  */ , 
      MEMIF_Fee_30_FlexNor /*  MemIfDeviceIndex  */ , 
      NVM_BLOCK_DATA_INTEGRITY_CRC_16 /*  DataIntegrityType  */ , 
      NVM_BLOCK_MANAGEMENT_TYPE_NATIVE /*  BlockManagementType  */ 
    }                           ,
  /*    25 */     { /*  WDFC_ID_MAX_FDC  */ 
      (NvM_RamAddressType)&WDFS_RamMaxFdc /*  RamBlockDataAddress  */ , 
      (NvM_RomAddressType)&WDFS_RomMaxFdc /*  RomBlockDataAddress  */ , 
      NULL_PTR /*  InitBlockCallback  */ , 
      NULL_PTR /*  ExtendedInitBlockCallback  */ , 
      NULL_PTR /*  SingleBlockCallback  */ , 
      NULL_PTR /*  ExtendedSingleBlockCallback  */ , 
      NULL_PTR /*  BackgroundCrcRecalcCallback  */ , 
      NULL_PTR /*  WriteRamBlockToNvCallback  */ , 
      NULL_PTR /*  ReadRamBlockFromNvCallback  */ , 
      &NvM_BlockManagementInfo_WDFC_ID_MAX_FDC /*  BlockManagementInfo  */ , 
      (NvM_DataPtrType)&NvM_DataIntegrityIntBuffer_WDFC_ID_MAX_FDC /*  DataIntegrityIntBuffer  */ , 
      (NvM_DataPtrType)&NvM_CrcCompMechanismBuffer_WDFC_ID_MAX_FDC /*  CrcCompMechanismBuffer  */ , 
              {
          NVM_SELECT_BLOCK_FOR_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_WRITE_BLOCK_ONCE_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_USE_AUTO_VALIDATION_OFF
        } /*  Flags  */ , 
      0u /*  MacGenerationJobId  */ , 
      0u /*  MacVerificationJobId  */ , 
      53u /*  NvramBlockIdentifier  */ , 
      108u /*  NvBlockLength  */ , 
      0x0190u /*  HwAbsBlockNumber  */ , 
      0u /*  MacSize  */ , 
      1u /*  NvBlockNumber  */ , 
      127u /*  Priority  */ , 
      NVM_PARTITION_ID_MASTER /*  PartitionIndex  */ , 
      MEMIF_Fee_30_FlexNor /*  MemIfDeviceIndex  */ , 
      NVM_BLOCK_DATA_INTEGRITY_CRC_16 /*  DataIntegrityType  */ , 
      NVM_BLOCK_MANAGEMENT_TYPE_NATIVE /*  BlockManagementType  */ 
    }                                                                                       ,
  /*    26 */     { /*  WDFC_ID_DTCTime  */ 
      (NvM_RamAddressType)&WDFS_RamDTCTime /*  RamBlockDataAddress  */ , 
      (NvM_RomAddressType)&WDFS_RomDTCTime /*  RomBlockDataAddress  */ , 
      NULL_PTR /*  InitBlockCallback  */ , 
      NULL_PTR /*  ExtendedInitBlockCallback  */ , 
      NULL_PTR /*  SingleBlockCallback  */ , 
      NULL_PTR /*  ExtendedSingleBlockCallback  */ , 
      NULL_PTR /*  BackgroundCrcRecalcCallback  */ , 
      NULL_PTR /*  WriteRamBlockToNvCallback  */ , 
      NULL_PTR /*  ReadRamBlockFromNvCallback  */ , 
      &NvM_BlockManagementInfo_WDFC_ID_DTCTime /*  BlockManagementInfo  */ , 
      (NvM_DataPtrType)&NvM_DataIntegrityIntBuffer_WDFC_ID_DTCTime /*  DataIntegrityIntBuffer  */ , 
      (NvM_DataPtrType)&NvM_CrcCompMechanismBuffer_WDFC_ID_DTCTime /*  CrcCompMechanismBuffer  */ , 
              {
          NVM_SELECT_BLOCK_FOR_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_WRITE_BLOCK_ONCE_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_USE_AUTO_VALIDATION_OFF
        } /*  Flags  */ , 
      0u /*  MacGenerationJobId  */ , 
      0u /*  MacVerificationJobId  */ , 
      88u /*  NvramBlockIdentifier  */ , 
      108u /*  NvBlockLength  */ , 
      0x00E0u /*  HwAbsBlockNumber  */ , 
      0u /*  MacSize  */ , 
      1u /*  NvBlockNumber  */ , 
      127u /*  Priority  */ , 
      NVM_PARTITION_ID_MASTER /*  PartitionIndex  */ , 
      MEMIF_Fee_30_FlexNor /*  MemIfDeviceIndex  */ , 
      NVM_BLOCK_DATA_INTEGRITY_CRC_16 /*  DataIntegrityType  */ , 
      NVM_BLOCK_MANAGEMENT_TYPE_NATIVE /*  BlockManagementType  */ 
    }                                                                                    ,
  /*    27 */     { /*  WDFC_ID_PART_NUMBER_GEELY  */ 
      (NvM_RamAddressType)&WDFS_RamPart_Number_Geely /*  RamBlockDataAddress  */ , 
      (NvM_RomAddressType)&WDFS_RomPart_Number_Geely /*  RomBlockDataAddress  */ , 
      NULL_PTR /*  InitBlockCallback  */ , 
      NULL_PTR /*  ExtendedInitBlockCallback  */ , 
      NULL_PTR /*  SingleBlockCallback  */ , 
      NULL_PTR /*  ExtendedSingleBlockCallback  */ , 
      NULL_PTR /*  BackgroundCrcRecalcCallback  */ , 
      NULL_PTR /*  WriteRamBlockToNvCallback  */ , 
      NULL_PTR /*  ReadRamBlockFromNvCallback  */ , 
      &NvM_BlockManagementInfo_WDFC_ID_PART_NUMBER_GEELY /*  BlockManagementInfo  */ , 
      (NvM_DataPtrType)&NvM_DataIntegrityIntBuffer_WDFC_ID_PART_NUMBER_GEELY /*  DataIntegrityIntBuffer  */ , 
      (NvM_DataPtrType)&NvM_CrcCompMechanismBuffer_WDFC_ID_PART_NUMBER_GEELY /*  CrcCompMechanismBuffer  */ , 
              {
          NVM_SELECT_BLOCK_FOR_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_WRITE_BLOCK_ONCE_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_USE_AUTO_VALIDATION_OFF
        } /*  Flags  */ , 
      0u /*  MacGenerationJobId  */ , 
      0u /*  MacVerificationJobId  */ , 
      89u /*  NvramBlockIdentifier  */ , 
      32u /*  NvBlockLength  */ , 
      0x01E0u /*  HwAbsBlockNumber  */ , 
      0u /*  MacSize  */ , 
      1u /*  NvBlockNumber  */ , 
      127u /*  Priority  */ , 
      NVM_PARTITION_ID_MASTER /*  PartitionIndex  */ , 
      MEMIF_Fee_30_FlexNor /*  MemIfDeviceIndex  */ , 
      NVM_BLOCK_DATA_INTEGRITY_CRC_16 /*  DataIntegrityType  */ , 
      NVM_BLOCK_MANAGEMENT_TYPE_NATIVE /*  BlockManagementType  */ 
    }                        ,
  /*    28 */     { /*  WDFC_ID_EOL_PASSWORD  */ 
      (NvM_RamAddressType)&WDFS_RamEOL_PASSWORD /*  RamBlockDataAddress  */ , 
      (NvM_RomAddressType)&WDFS_RomEOL_PASSWORD /*  RomBlockDataAddress  */ , 
      NULL_PTR /*  InitBlockCallback  */ , 
      NULL_PTR /*  ExtendedInitBlockCallback  */ , 
      NULL_PTR /*  SingleBlockCallback  */ , 
      NULL_PTR /*  ExtendedSingleBlockCallback  */ , 
      NULL_PTR /*  BackgroundCrcRecalcCallback  */ , 
      NULL_PTR /*  WriteRamBlockToNvCallback  */ , 
      NULL_PTR /*  ReadRamBlockFromNvCallback  */ , 
      &NvM_BlockManagementInfo_WDFC_ID_EOL_PASSWORD /*  BlockManagementInfo  */ , 
      (NvM_DataPtrType)&NvM_DataIntegrityIntBuffer_WDFC_ID_EOL_PASSWORD /*  DataIntegrityIntBuffer  */ , 
      (NvM_DataPtrType)&NvM_CrcCompMechanismBuffer_WDFC_ID_EOL_PASSWORD /*  CrcCompMechanismBuffer  */ , 
              {
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_WRITE_BLOCK_ONCE_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_USE_AUTO_VALIDATION_OFF
        } /*  Flags  */ , 
      0u /*  MacGenerationJobId  */ , 
      0u /*  MacVerificationJobId  */ , 
      90u /*  NvramBlockIdentifier  */ , 
      128u /*  NvBlockLength  */ , 
      0x0120u /*  HwAbsBlockNumber  */ , 
      0u /*  MacSize  */ , 
      1u /*  NvBlockNumber  */ , 
      127u /*  Priority  */ , 
      NVM_PARTITION_ID_MASTER /*  PartitionIndex  */ , 
      MEMIF_Fee_30_FlexNor /*  MemIfDeviceIndex  */ , 
      NVM_BLOCK_DATA_INTEGRITY_CRC_16 /*  DataIntegrityType  */ , 
      NVM_BLOCK_MANAGEMENT_TYPE_NATIVE /*  BlockManagementType  */ 
    }                                                     ,
  /*    29 */     { /*  WDFC_ID_LAST_FDC  */ 
      (NvM_RamAddressType)&WDFS_RamLastFdc /*  RamBlockDataAddress  */ , 
      (NvM_RomAddressType)&WDFS_RomLastFdc /*  RomBlockDataAddress  */ , 
      NULL_PTR /*  InitBlockCallback  */ , 
      NULL_PTR /*  ExtendedInitBlockCallback  */ , 
      NULL_PTR /*  SingleBlockCallback  */ , 
      NULL_PTR /*  ExtendedSingleBlockCallback  */ , 
      NULL_PTR /*  BackgroundCrcRecalcCallback  */ , 
      NULL_PTR /*  WriteRamBlockToNvCallback  */ , 
      NULL_PTR /*  ReadRamBlockFromNvCallback  */ , 
      &NvM_BlockManagementInfo_WDFC_ID_LAST_FDC /*  BlockManagementInfo  */ , 
      (NvM_DataPtrType)&NvM_DataIntegrityIntBuffer_WDFC_ID_LAST_FDC /*  DataIntegrityIntBuffer  */ , 
      (NvM_DataPtrType)&NvM_CrcCompMechanismBuffer_WDFC_ID_LAST_FDC /*  CrcCompMechanismBuffer  */ , 
              {
          NVM_SELECT_BLOCK_FOR_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_WRITE_BLOCK_ONCE_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_USE_AUTO_VALIDATION_OFF
        } /*  Flags  */ , 
      0u /*  MacGenerationJobId  */ , 
      0u /*  MacVerificationJobId  */ , 
      91u /*  NvramBlockIdentifier  */ , 
      108u /*  NvBlockLength  */ , 
      0x0180u /*  HwAbsBlockNumber  */ , 
      0u /*  MacSize  */ , 
      1u /*  NvBlockNumber  */ , 
      127u /*  Priority  */ , 
      NVM_PARTITION_ID_MASTER /*  PartitionIndex  */ , 
      MEMIF_Fee_30_FlexNor /*  MemIfDeviceIndex  */ , 
      NVM_BLOCK_DATA_INTEGRITY_CRC_16 /*  DataIntegrityType  */ , 
      NVM_BLOCK_MANAGEMENT_TYPE_NATIVE /*  BlockManagementType  */ 
    }                                                                               ,
  /*    30 */     { /*  WDFC_ID_DEBUG_DATA  */ 
      (NvM_RamAddressType)&WDFS_RamDebugData /*  RamBlockDataAddress  */ , 
      (NvM_RomAddressType)&WDFS_RomDebugData /*  RomBlockDataAddress  */ , 
      NULL_PTR /*  InitBlockCallback  */ , 
      NULL_PTR /*  ExtendedInitBlockCallback  */ , 
      NULL_PTR /*  SingleBlockCallback  */ , 
      NULL_PTR /*  ExtendedSingleBlockCallback  */ , 
      NULL_PTR /*  BackgroundCrcRecalcCallback  */ , 
      NULL_PTR /*  WriteRamBlockToNvCallback  */ , 
      NULL_PTR /*  ReadRamBlockFromNvCallback  */ , 
      &NvM_BlockManagementInfo_WDFC_ID_DEBUG_DATA /*  BlockManagementInfo  */ , 
      (NvM_DataPtrType)&NvM_DataIntegrityIntBuffer_WDFC_ID_DEBUG_DATA /*  DataIntegrityIntBuffer  */ , 
      (NvM_DataPtrType)&NvM_CrcCompMechanismBuffer_WDFC_ID_DEBUG_DATA /*  CrcCompMechanismBuffer  */ , 
              {
          NVM_SELECT_BLOCK_FOR_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_WRITE_BLOCK_ONCE_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_USE_AUTO_VALIDATION_OFF
        } /*  Flags  */ , 
      0u /*  MacGenerationJobId  */ , 
      0u /*  MacVerificationJobId  */ , 
      92u /*  NvramBlockIdentifier  */ , 
      176u /*  NvBlockLength  */ , 
      0x00C0u /*  HwAbsBlockNumber  */ , 
      0u /*  MacSize  */ , 
      1u /*  NvBlockNumber  */ , 
      127u /*  Priority  */ , 
      NVM_PARTITION_ID_MASTER /*  PartitionIndex  */ , 
      MEMIF_Fee_30_FlexNor /*  MemIfDeviceIndex  */ , 
      NVM_BLOCK_DATA_INTEGRITY_CRC_16 /*  DataIntegrityType  */ , 
      NVM_BLOCK_MANAGEMENT_TYPE_NATIVE /*  BlockManagementType  */ 
    }                                                                    ,
  /*    31 */     { /*  WDFC_ID_MIRROR_OTHER_1  */ 
      (NvM_RamAddressType)&WDFS_RamOther_1 /*  RamBlockDataAddress  */ , 
      (NvM_RomAddressType)&WDFS_RomOther_1 /*  RomBlockDataAddress  */ , 
      NULL_PTR /*  InitBlockCallback  */ , 
      NULL_PTR /*  ExtendedInitBlockCallback  */ , 
      NULL_PTR /*  SingleBlockCallback  */ , 
      NULL_PTR /*  ExtendedSingleBlockCallback  */ , 
      NULL_PTR /*  BackgroundCrcRecalcCallback  */ , 
      NULL_PTR /*  WriteRamBlockToNvCallback  */ , 
      NULL_PTR /*  ReadRamBlockFromNvCallback  */ , 
      &NvM_BlockManagementInfo_WDFC_ID_MIRROR_OTHER_1 /*  BlockManagementInfo  */ , 
      (NvM_DataPtrType)&NvM_DataIntegrityIntBuffer_WDFC_ID_MIRROR_OTHER_1 /*  DataIntegrityIntBuffer  */ , 
      (NvM_DataPtrType)&NvM_CrcCompMechanismBuffer_WDFC_ID_MIRROR_OTHER_1 /*  CrcCompMechanismBuffer  */ , 
              {
          NVM_SELECT_BLOCK_FOR_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_WRITE_BLOCK_ONCE_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_USE_AUTO_VALIDATION_OFF
        } /*  Flags  */ , 
      0u /*  MacGenerationJobId  */ , 
      0u /*  MacVerificationJobId  */ , 
      93u /*  NvramBlockIdentifier  */ , 
      8u /*  NvBlockLength  */ , 
      0x01B0u /*  HwAbsBlockNumber  */ , 
      0u /*  MacSize  */ , 
      1u /*  NvBlockNumber  */ , 
      127u /*  Priority  */ , 
      NVM_PARTITION_ID_MASTER /*  PartitionIndex  */ , 
      MEMIF_Fee_30_FlexNor /*  MemIfDeviceIndex  */ , 
      NVM_BLOCK_DATA_INTEGRITY_CRC_16 /*  DataIntegrityType  */ , 
      NVM_BLOCK_MANAGEMENT_TYPE_NATIVE /*  BlockManagementType  */ 
    }                                                           ,
  /*    32 */     { /*  WDFC_ID_MIRROR_POS_REC  */ 
      (NvM_RamAddressType)&WDFS_RamMIRR_POS_REC /*  RamBlockDataAddress  */ , 
      (NvM_RomAddressType)&WDFS_RomMIRR_POS_REC /*  RomBlockDataAddress  */ , 
      NULL_PTR /*  InitBlockCallback  */ , 
      NULL_PTR /*  ExtendedInitBlockCallback  */ , 
      NULL_PTR /*  SingleBlockCallback  */ , 
      NULL_PTR /*  ExtendedSingleBlockCallback  */ , 
      NULL_PTR /*  BackgroundCrcRecalcCallback  */ , 
      NULL_PTR /*  WriteRamBlockToNvCallback  */ , 
      NULL_PTR /*  ReadRamBlockFromNvCallback  */ , 
      &NvM_BlockManagementInfo_WDFC_ID_MIRROR_POS_REC /*  BlockManagementInfo  */ , 
      (NvM_DataPtrType)&NvM_DataIntegrityIntBuffer_WDFC_ID_MIRROR_POS_REC /*  DataIntegrityIntBuffer  */ , 
      (NvM_DataPtrType)&NvM_CrcCompMechanismBuffer_WDFC_ID_MIRROR_POS_REC /*  CrcCompMechanismBuffer  */ , 
              {
          NVM_SELECT_BLOCK_FOR_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_WRITE_BLOCK_ONCE_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_USE_AUTO_VALIDATION_OFF
        } /*  Flags  */ , 
      0u /*  MacGenerationJobId  */ , 
      0u /*  MacVerificationJobId  */ , 
      94u /*  NvramBlockIdentifier  */ , 
      20u /*  NvBlockLength  */ , 
      0x01C0u /*  HwAbsBlockNumber  */ , 
      0u /*  MacSize  */ , 
      1u /*  NvBlockNumber  */ , 
      127u /*  Priority  */ , 
      NVM_PARTITION_ID_MASTER /*  PartitionIndex  */ , 
      MEMIF_Fee_30_FlexNor /*  MemIfDeviceIndex  */ , 
      NVM_BLOCK_DATA_INTEGRITY_CRC_16 /*  DataIntegrityType  */ , 
      NVM_BLOCK_MANAGEMENT_TYPE_NATIVE /*  BlockManagementType  */ 
    }                                                ,
  /*    33 */     { /*  WDFC_ID_EOL_SWNUMBER  */ 
      (NvM_RamAddressType)&WDFS_RamEOL_SWNumber /*  RamBlockDataAddress  */ , 
      (NvM_RomAddressType)&WDFS_RomEOL_SWNumber /*  RomBlockDataAddress  */ , 
      NULL_PTR /*  InitBlockCallback  */ , 
      NULL_PTR /*  ExtendedInitBlockCallback  */ , 
      NULL_PTR /*  SingleBlockCallback  */ , 
      NULL_PTR /*  ExtendedSingleBlockCallback  */ , 
      NULL_PTR /*  BackgroundCrcRecalcCallback  */ , 
      NULL_PTR /*  WriteRamBlockToNvCallback  */ , 
      NULL_PTR /*  ReadRamBlockFromNvCallback  */ , 
      &NvM_BlockManagementInfo_WDFC_ID_EOL_SWNUMBER /*  BlockManagementInfo  */ , 
      (NvM_DataPtrType)&NvM_DataIntegrityIntBuffer_WDFC_ID_EOL_SWNUMBER /*  DataIntegrityIntBuffer  */ , 
      (NvM_DataPtrType)&NvM_CrcCompMechanismBuffer_WDFC_ID_EOL_SWNUMBER /*  CrcCompMechanismBuffer  */ , 
              {
          NVM_SELECT_BLOCK_FOR_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_WRITE_BLOCK_ONCE_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_USE_AUTO_VALIDATION_OFF
        } /*  Flags  */ , 
      0u /*  MacGenerationJobId  */ , 
      0u /*  MacVerificationJobId  */ , 
      95u /*  NvramBlockIdentifier  */ , 
      32u /*  NvBlockLength  */ , 
      0x0130u /*  HwAbsBlockNumber  */ , 
      0u /*  MacSize  */ , 
      1u /*  NvBlockNumber  */ , 
      127u /*  Priority  */ , 
      NVM_PARTITION_ID_MASTER /*  PartitionIndex  */ , 
      MEMIF_Fee_30_FlexNor /*  MemIfDeviceIndex  */ , 
      NVM_BLOCK_DATA_INTEGRITY_CRC_16 /*  DataIntegrityType  */ , 
      NVM_BLOCK_MANAGEMENT_TYPE_NATIVE /*  BlockManagementType  */ 
    }                                                      ,
  /*    34 */     { /*  WDFC_ID_EOL_HW_VERSION  */ 
      (NvM_RamAddressType)&WDFS_RamEOL_HW_VERSION /*  RamBlockDataAddress  */ , 
      (NvM_RomAddressType)&WDFS_RomEOL_HW_VERSION /*  RomBlockDataAddress  */ , 
      NULL_PTR /*  InitBlockCallback  */ , 
      NULL_PTR /*  ExtendedInitBlockCallback  */ , 
      NULL_PTR /*  SingleBlockCallback  */ , 
      NULL_PTR /*  ExtendedSingleBlockCallback  */ , 
      NULL_PTR /*  BackgroundCrcRecalcCallback  */ , 
      NULL_PTR /*  WriteRamBlockToNvCallback  */ , 
      NULL_PTR /*  ReadRamBlockFromNvCallback  */ , 
      &NvM_BlockManagementInfo_WDFC_ID_EOL_HW_VERSION /*  BlockManagementInfo  */ , 
      (NvM_DataPtrType)&NvM_DataIntegrityIntBuffer_WDFC_ID_EOL_HW_VERSION /*  DataIntegrityIntBuffer  */ , 
      (NvM_DataPtrType)&NvM_CrcCompMechanismBuffer_WDFC_ID_EOL_HW_VERSION /*  CrcCompMechanismBuffer  */ , 
              {
          NVM_SELECT_BLOCK_FOR_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_WRITE_BLOCK_ONCE_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_USE_AUTO_VALIDATION_OFF
        } /*  Flags  */ , 
      0u /*  MacGenerationJobId  */ , 
      0u /*  MacVerificationJobId  */ , 
      96u /*  NvramBlockIdentifier  */ , 
      10u /*  NvBlockLength  */ , 
      0x0100u /*  HwAbsBlockNumber  */ , 
      0u /*  MacSize  */ , 
      1u /*  NvBlockNumber  */ , 
      127u /*  Priority  */ , 
      NVM_PARTITION_ID_MASTER /*  PartitionIndex  */ , 
      MEMIF_Fee_30_FlexNor /*  MemIfDeviceIndex  */ , 
      NVM_BLOCK_DATA_INTEGRITY_CRC_16 /*  DataIntegrityType  */ , 
      NVM_BLOCK_MANAGEMENT_TYPE_NATIVE /*  BlockManagementType  */ 
    }                                          ,
  /*    35 */     { /*  WDFC_ID_SECURITY_ACCESS  */ 
      (NvM_RamAddressType)&WDFS_RamSecurityAccessConfig /*  RamBlockDataAddress  */ , 
      (NvM_RomAddressType)&WDFS_RomSecurityAccessConfig /*  RomBlockDataAddress  */ , 
      NULL_PTR /*  InitBlockCallback  */ , 
      NULL_PTR /*  ExtendedInitBlockCallback  */ , 
      NULL_PTR /*  SingleBlockCallback  */ , 
      NULL_PTR /*  ExtendedSingleBlockCallback  */ , 
      NULL_PTR /*  BackgroundCrcRecalcCallback  */ , 
      NULL_PTR /*  WriteRamBlockToNvCallback  */ , 
      NULL_PTR /*  ReadRamBlockFromNvCallback  */ , 
      &NvM_BlockManagementInfo_WDFC_ID_SECURITY_ACCESS /*  BlockManagementInfo  */ , 
      (NvM_DataPtrType)&NvM_DataIntegrityIntBuffer_WDFC_ID_SECURITY_ACCESS /*  DataIntegrityIntBuffer  */ , 
      (NvM_DataPtrType)&NvM_CrcCompMechanismBuffer_WDFC_ID_SECURITY_ACCESS /*  CrcCompMechanismBuffer  */ , 
              {
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_WRITE_BLOCK_ONCE_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_USE_AUTO_VALIDATION_OFF
        } /*  Flags  */ , 
      0u /*  MacGenerationJobId  */ , 
      0u /*  MacVerificationJobId  */ , 
      97u /*  NvramBlockIdentifier  */ , 
      20u /*  NvBlockLength  */ , 
      0x0210u /*  HwAbsBlockNumber  */ , 
      0u /*  MacSize  */ , 
      1u /*  NvBlockNumber  */ , 
      127u /*  Priority  */ , 
      NVM_PARTITION_ID_MASTER /*  PartitionIndex  */ , 
      MEMIF_Fee_30_FlexNor /*  MemIfDeviceIndex  */ , 
      NVM_BLOCK_DATA_INTEGRITY_CRC_16 /*  DataIntegrityType  */ , 
      NVM_BLOCK_MANAGEMENT_TYPE_NATIVE /*  BlockManagementType  */ 
    }                            ,
  /*    36 */     { /*  WDFC_ID_QCM_FAULT_DATA  */ 
      (NvM_RamAddressType)&WDFS_RamQCM_FAULT_DATA /*  RamBlockDataAddress  */ , 
      (NvM_RomAddressType)&WDFS_RomQCM_FAULT_DATA /*  RomBlockDataAddress  */ , 
      NULL_PTR /*  InitBlockCallback  */ , 
      NULL_PTR /*  ExtendedInitBlockCallback  */ , 
      NULL_PTR /*  SingleBlockCallback  */ , 
      NULL_PTR /*  ExtendedSingleBlockCallback  */ , 
      NULL_PTR /*  BackgroundCrcRecalcCallback  */ , 
      NULL_PTR /*  WriteRamBlockToNvCallback  */ , 
      NULL_PTR /*  ReadRamBlockFromNvCallback  */ , 
      &NvM_BlockManagementInfo_WDFC_ID_QCM_FAULT_DATA /*  BlockManagementInfo  */ , 
      (NvM_DataPtrType)&NvM_DataIntegrityIntBuffer_WDFC_ID_QCM_FAULT_DATA /*  DataIntegrityIntBuffer  */ , 
      (NvM_DataPtrType)&NvM_CrcCompMechanismBuffer_WDFC_ID_QCM_FAULT_DATA /*  CrcCompMechanismBuffer  */ , 
              {
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_WRITE_BLOCK_ONCE_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_USE_AUTO_VALIDATION_OFF
        } /*  Flags  */ , 
      0u /*  MacGenerationJobId  */ , 
      0u /*  MacVerificationJobId  */ , 
      98u /*  NvramBlockIdentifier  */ , 
      84u /*  NvBlockLength  */ , 
      0x0200u /*  HwAbsBlockNumber  */ , 
      0u /*  MacSize  */ , 
      1u /*  NvBlockNumber  */ , 
      127u /*  Priority  */ , 
      NVM_PARTITION_ID_MASTER /*  PartitionIndex  */ , 
      MEMIF_Fee_30_FlexNor /*  MemIfDeviceIndex  */ , 
      NVM_BLOCK_DATA_INTEGRITY_CRC_16 /*  DataIntegrityType  */ , 
      NVM_BLOCK_MANAGEMENT_TYPE_NATIVE /*  BlockManagementType  */ 
    }                                          
};
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
CONST(NvM_PartitionIdentifiersType, NVM_CONST) NvM_PartitionIdentifiers[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    PartitionSNV      PCPartitionConfigIdx                         */
  { /*     0 */ DefaultPartition,                   0u  /* DefaultPartition */ }
};
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
VAR(NvM_FsmLib_InstanceType, NVM_VAR_NO_INIT) NvM_BackgroundCrcRecalcFsmLib_Instance;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_FsmLib_ProcessingStackElementType, NVM_VAR_NO_INIT) NvM_BackgroundCrcRecalcFsmLib_ProcessingStackElement[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_BackgroundCrcRecalcFsm_ContextType, NVM_VAR_NO_INIT) NvM_BackgroundCrcRecalcFsm_Context;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_FsmType, NVM_VAR_NO_INIT) NvM_BackgroundCrcRecalcFsm_Instance;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_DataIntegrityService_InstanceType, NVM_VAR_NO_INIT) NvM_BackgroundDataIntegrityService_Instance;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_BlockManagementInformationType, NVM_VAR_NO_INIT) NvM_BlockManagementInfo_DemAdminDataBlock;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_BlockManagementInformationType, NVM_VAR_NO_INIT) NvM_BlockManagementInfo_DemStatusDataBlock;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_BlockManagementInformationType, NVM_VAR_NO_INIT) NvM_BlockManagementInfo_NvMConfigBlock;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_BlockManagementInformationType, NVM_VAR_NO_INIT) NvM_BlockManagementInfo_NvMMultiBlock;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_BlockManagementInformationType, NVM_VAR_NO_INIT) NvM_BlockManagementInfo_WDFC_ID_AP_CONNEX;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_BlockManagementInformationType, NVM_VAR_NO_INIT) NvM_BlockManagementInfo_WDFC_ID_AP_PARA;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_BlockManagementInformationType, NVM_VAR_NO_INIT) NvM_BlockManagementInfo_WDFC_ID_BOOT_PARA;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_BlockManagementInformationType, NVM_VAR_NO_INIT) NvM_BlockManagementInfo_WDFC_ID_CCP;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_BlockManagementInformationType, NVM_VAR_NO_INIT) NvM_BlockManagementInfo_WDFC_ID_DEBUG_DATA;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_BlockManagementInformationType, NVM_VAR_NO_INIT) NvM_BlockManagementInfo_WDFC_ID_DLC;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_BlockManagementInformationType, NVM_VAR_NO_INIT) NvM_BlockManagementInfo_WDFC_ID_DTCTime;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_BlockManagementInformationType, NVM_VAR_NO_INIT) NvM_BlockManagementInfo_WDFC_ID_ECUID_RDI_PROGRAMMING_INFO;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_BlockManagementInformationType, NVM_VAR_NO_INIT) NvM_BlockManagementInfo_WDFC_ID_EOL_HW_VERSION;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_BlockManagementInformationType, NVM_VAR_NO_INIT) NvM_BlockManagementInfo_WDFC_ID_EOL_INFO;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_BlockManagementInformationType, NVM_VAR_NO_INIT) NvM_BlockManagementInfo_WDFC_ID_EOL_PASSWORD;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_BlockManagementInformationType, NVM_VAR_NO_INIT) NvM_BlockManagementInfo_WDFC_ID_EOL_SWNUMBER;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_BlockManagementInformationType, NVM_VAR_NO_INIT) NvM_BlockManagementInfo_WDFC_ID_FAULT_CODE;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_BlockManagementInformationType, NVM_VAR_NO_INIT) NvM_BlockManagementInfo_WDFC_ID_HANDLE_CFG;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_BlockManagementInformationType, NVM_VAR_NO_INIT) NvM_BlockManagementInfo_WDFC_ID_IDENT_BANK;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_BlockManagementInformationType, NVM_VAR_NO_INIT) NvM_BlockManagementInfo_WDFC_ID_IDOPTION_SECURITY;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_BlockManagementInformationType, NVM_VAR_NO_INIT) NvM_BlockManagementInfo_WDFC_ID_LAST_FDC;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_BlockManagementInformationType, NVM_VAR_NO_INIT) NvM_BlockManagementInfo_WDFC_ID_MAX_FDC;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_BlockManagementInformationType, NVM_VAR_NO_INIT) NvM_BlockManagementInfo_WDFC_ID_MIRROR_CFG;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_BlockManagementInformationType, NVM_VAR_NO_INIT) NvM_BlockManagementInfo_WDFC_ID_MIRROR_OTHER_1;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_BlockManagementInformationType, NVM_VAR_NO_INIT) NvM_BlockManagementInfo_WDFC_ID_MIRROR_POS_REC;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_BlockManagementInformationType, NVM_VAR_NO_INIT) NvM_BlockManagementInfo_WDFC_ID_MIRROR_ST;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_BlockManagementInformationType, NVM_VAR_NO_INIT) NvM_BlockManagementInfo_WDFC_ID_PART_NUMBER_GEELY;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_BlockManagementInformationType, NVM_VAR_NO_INIT) NvM_BlockManagementInfo_WDFC_ID_PMM;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_BlockManagementInformationType, NVM_VAR_NO_INIT) NvM_BlockManagementInfo_WDFC_ID_QCM_FAULT_DATA;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_BlockManagementInformationType, NVM_VAR_NO_INIT) NvM_BlockManagementInfo_WDFC_ID_SECURITY_ACCESS;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_BlockManagementInformationType, NVM_VAR_NO_INIT) NvM_BlockManagementInfo_WDFC_ID_SR_PROFILE;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_BlockManagementInformationType, NVM_VAR_NO_INIT) NvM_BlockManagementInfo_WDFC_ID_SWP1;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_BlockManagementInformationType, NVM_VAR_NO_INIT) NvM_BlockManagementInfo_WDFC_ID_THPA;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_BlockManagementInformationType, NVM_VAR_NO_INIT) NvM_BlockManagementInfo_WDFC_ID_VEH_CFG;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_BlockManagementInformationType, NVM_VAR_NO_INIT) NvM_BlockManagementInfo_WDFC_ID_VOL_POWER_MODE_CFG;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_BlockManagementInformationType, NVM_VAR_NO_INIT) NvM_BlockManagementInfo_WDFC_ID_WLC_AP_LEARN;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_BlockManagementInformationType, NVM_VAR_NO_INIT) NvM_BlockManagementInfo_WDFC_ID_WL_INFO;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_BlockManagementInformationType, NVM_VAR_NO_INIT) NvM_BlockManagementInfo_WDFC_ID_WL_LOG;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_CrcCompMechanismBuffer_DemAdminDataBlock[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_CrcCompMechanismBuffer_DemStatusDataBlock[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_CrcCompMechanismBuffer_NvMConfigBlock[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_CrcCompMechanismBuffer_WDFC_ID_AP_CONNEX[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_CrcCompMechanismBuffer_WDFC_ID_AP_PARA[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_CrcCompMechanismBuffer_WDFC_ID_BOOT_PARA[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_CrcCompMechanismBuffer_WDFC_ID_CCP[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_CrcCompMechanismBuffer_WDFC_ID_DEBUG_DATA[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_CrcCompMechanismBuffer_WDFC_ID_DLC[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_CrcCompMechanismBuffer_WDFC_ID_DTCTime[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_CrcCompMechanismBuffer_WDFC_ID_ECUID_RDI_PROGRAMMING_INFO[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_CrcCompMechanismBuffer_WDFC_ID_EOL_HW_VERSION[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_CrcCompMechanismBuffer_WDFC_ID_EOL_INFO[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_CrcCompMechanismBuffer_WDFC_ID_EOL_PASSWORD[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_CrcCompMechanismBuffer_WDFC_ID_EOL_SWNUMBER[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_CrcCompMechanismBuffer_WDFC_ID_FAULT_CODE[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_CrcCompMechanismBuffer_WDFC_ID_HANDLE_CFG[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_CrcCompMechanismBuffer_WDFC_ID_IDENT_BANK[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_CrcCompMechanismBuffer_WDFC_ID_IDOPTION_SECURITY[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_CrcCompMechanismBuffer_WDFC_ID_LAST_FDC[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_CrcCompMechanismBuffer_WDFC_ID_MAX_FDC[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_CrcCompMechanismBuffer_WDFC_ID_MIRROR_CFG[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_CrcCompMechanismBuffer_WDFC_ID_MIRROR_OTHER_1[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_CrcCompMechanismBuffer_WDFC_ID_MIRROR_POS_REC[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_CrcCompMechanismBuffer_WDFC_ID_MIRROR_ST[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_CrcCompMechanismBuffer_WDFC_ID_PART_NUMBER_GEELY[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_CrcCompMechanismBuffer_WDFC_ID_PMM[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_CrcCompMechanismBuffer_WDFC_ID_QCM_FAULT_DATA[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_CrcCompMechanismBuffer_WDFC_ID_SECURITY_ACCESS[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_CrcCompMechanismBuffer_WDFC_ID_SR_PROFILE[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_CrcCompMechanismBuffer_WDFC_ID_SWP1[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_CrcCompMechanismBuffer_WDFC_ID_THPA[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_CrcCompMechanismBuffer_WDFC_ID_VEH_CFG[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_CrcCompMechanismBuffer_WDFC_ID_VOL_POWER_MODE_CFG[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_CrcCompMechanismBuffer_WDFC_ID_WLC_AP_LEARN[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_CrcCompMechanismBuffer_WDFC_ID_WL_INFO[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_CrcCompMechanismBuffer_WDFC_ID_WL_LOG[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_FsmType, NVM_VAR_NO_INIT) NvM_DataIntegrityFsm_Instance;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_DataIntegrityIntBuffer_DemAdminDataBlock[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_DataIntegrityIntBuffer_DemStatusDataBlock[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_DataIntegrityIntBuffer_WDFC_ID_AP_CONNEX[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_DataIntegrityIntBuffer_WDFC_ID_AP_PARA[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_DataIntegrityIntBuffer_WDFC_ID_BOOT_PARA[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_DataIntegrityIntBuffer_WDFC_ID_CCP[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_DataIntegrityIntBuffer_WDFC_ID_DEBUG_DATA[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_DataIntegrityIntBuffer_WDFC_ID_DLC[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_DataIntegrityIntBuffer_WDFC_ID_DTCTime[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_DataIntegrityIntBuffer_WDFC_ID_ECUID_RDI_PROGRAMMING_INFO[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_DataIntegrityIntBuffer_WDFC_ID_EOL_HW_VERSION[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_DataIntegrityIntBuffer_WDFC_ID_EOL_INFO[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_DataIntegrityIntBuffer_WDFC_ID_EOL_PASSWORD[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_DataIntegrityIntBuffer_WDFC_ID_EOL_SWNUMBER[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_DataIntegrityIntBuffer_WDFC_ID_FAULT_CODE[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_DataIntegrityIntBuffer_WDFC_ID_HANDLE_CFG[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_DataIntegrityIntBuffer_WDFC_ID_IDENT_BANK[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_DataIntegrityIntBuffer_WDFC_ID_IDOPTION_SECURITY[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_DataIntegrityIntBuffer_WDFC_ID_LAST_FDC[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_DataIntegrityIntBuffer_WDFC_ID_MAX_FDC[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_DataIntegrityIntBuffer_WDFC_ID_MIRROR_CFG[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_DataIntegrityIntBuffer_WDFC_ID_MIRROR_OTHER_1[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_DataIntegrityIntBuffer_WDFC_ID_MIRROR_POS_REC[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_DataIntegrityIntBuffer_WDFC_ID_MIRROR_ST[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_DataIntegrityIntBuffer_WDFC_ID_PART_NUMBER_GEELY[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_DataIntegrityIntBuffer_WDFC_ID_PMM[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_DataIntegrityIntBuffer_WDFC_ID_QCM_FAULT_DATA[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_DataIntegrityIntBuffer_WDFC_ID_SECURITY_ACCESS[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_DataIntegrityIntBuffer_WDFC_ID_SR_PROFILE[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_DataIntegrityIntBuffer_WDFC_ID_SWP1[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_DataIntegrityIntBuffer_WDFC_ID_THPA[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_DataIntegrityIntBuffer_WDFC_ID_VEH_CFG[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_DataIntegrityIntBuffer_WDFC_ID_VOL_POWER_MODE_CFG[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_DataIntegrityIntBuffer_WDFC_ID_WLC_AP_LEARN[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_DataIntegrityIntBuffer_WDFC_ID_WL_INFO[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_DataIntegrityIntBuffer_WDFC_ID_WL_LOG[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_DataIntegrityRecalcQueue_InstanceType, NVM_VAR_NO_INIT) NvM_DataIntegrityRecalcQueue_Instance;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_BlockManagementInformationType, NVM_VAR_NO_INIT) NvM_DcmBlockManagementInfo;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_DataIntegrityService_InstanceType, NVM_VAR_NO_INIT) NvM_ForegroundDataIntegrityService_Instance;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_DataType, NVM_VAR_NO_INIT) NvM_InternalBuffer[1094];  /* PRQA S 1514, 1533, 0612, 0613 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_BigStructure, MD_CSL_BigStructure */
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
VAR(NvM_FsmLib_ProcessingStackElementType, NVM_VAR_NO_INIT) NvM_MultiBlockFsmLib_ProcessingStackElement[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_MultiBlockJobType, NVM_VAR_NO_INIT) NvM_MultiBlockJob;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_MultiBlockJobFsm_ContextType, NVM_VAR_NO_INIT) NvM_MultiBlockJobFsm_Context;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_FsmType, NVM_VAR_NO_INIT) NvM_MultiBlockJobFsm_Instance;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_MultiBlockJobInformationType, NVM_VAR_NO_INIT) NvM_MultiBlockJobInformation;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_FsmLib_InstanceType, NVM_VAR_NO_INIT) NvM_MultiBlockProcessorFsmLib_Instance;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_FsmLib_ProcessingStackElementType, NVM_VAR_NO_INIT) NvM_MultiBlockProcessorFsmLib_ProcessingStackElement[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_FsmLib_InstanceType, NVM_VAR_NO_INIT) NvM_MultiBlockServiceFsmLib_Instance;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_NvJobContextType, NVM_VAR_NO_INIT) NvM_NvJobContext;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_FsmType, NVM_VAR_NO_INIT) NvM_NvJobFsm_Instance;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_FsmLib_InstanceType, NVM_VAR_NO_INIT) NvM_NvServiceFsmLib_Instance;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_FsmLib_ProcessingStackElementType, NVM_VAR_NO_INIT) NvM_NvServiceFsmLib_ProcessingStackElement[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_FsmLib_InstanceType, NVM_VAR_NO_INIT) NvM_NvServiceProcessorFsmLib_Instance;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_FsmLib_ProcessingStackElementType, NVM_VAR_NO_INIT) NvM_NvServiceProcessorFsmLib_ProcessingStackElement[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_Queue_ListElement, NVM_VAR_NO_INIT) NvM_QueueList[25];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_Queue_InstanceType, NVM_VAR_NO_INIT) NvM_Queue_Instance;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_ReadAllFsm_ContextType, NVM_VAR_NO_INIT) NvM_ReadAllFsm_Context;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_FsmType, NVM_VAR_NO_INIT) NvM_ReadAllFsm_Instance;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_ReadBlockFsm_ContextType, NVM_VAR_NO_INIT) NvM_ReadBlockFsm_Context;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_FsmType, NVM_VAR_NO_INIT) NvM_ReadBlockFsm_Instance;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_FsmLib_InstanceType, NVM_VAR_NO_INIT) NvM_ServiceProcessorFsmLib_Instance;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_FsmLib_ProcessingStackElementType, NVM_VAR_NO_INIT) NvM_ServiceProcessorFsmLib_ProcessingStackElement[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_ServiceProcessorFsm_ContextType, NVM_VAR_NO_INIT) NvM_ServiceProcessorFsm_Context;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_FsmType, NVM_VAR_NO_INIT) NvM_ServiceProcessorFsm_Instance;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_FsmLib_ProcessingStackElementType, NVM_VAR_NO_INIT) NvM_SingleBlockFsmLib_ProcessingStackElement[4];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_SingleBlockJobContextType, NVM_VAR_NO_INIT) NvM_SingleBlockJobContext;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_FsmType, NVM_VAR_NO_INIT) NvM_SingleBlockJobFsm_Instance;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_FsmLib_InstanceType, NVM_VAR_NO_INIT) NvM_SingleBlockServiceFsmLib_Instance;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_FsmType, NVM_VAR_NO_INIT) NvM_ValidateAllFsm_Instance;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_MultiBlockFsm_ContextType, NVM_VAR_NO_INIT) NvM_WriteAllFsm_Context;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_FsmType, NVM_VAR_NO_INIT) NvM_WriteAllFsm_Instance;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_WriteBlockFsm_ContextType, NVM_VAR_NO_INIT) NvM_WriteBlockFsm_Context;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_FsmType, NVM_VAR_NO_INIT) NvM_WriteBlockFsm_Instance;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(NvM_WriteNvBlockFsm_ContextType, NVM_VAR_NO_INIT) NvM_WriteNvBlockFsm_Context;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "NvM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */




/**********************************************************************************************************************
  LOCAL FUNCTIONS
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL FUNCTIONS
**********************************************************************************************************************/


/**********************************************************************************************************************
 *  END OF FILE: NvM_Cfg.c
 *********************************************************************************************************************/


