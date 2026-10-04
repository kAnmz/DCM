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
 *              File: Fee_30_FlexNor_Lcfg.c
 *   Generation Time: 2026-08-07 09:54:24
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



#define FEE_30_FLEXNOR_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Fee_30_FlexNor_Cfg.h"

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
 
#define FeeConf_FeePartitionConfiguration_FeePartitionConfiguration4_DTC_LookupTableSize   (4u) 
#define FeeConf_FeePartitionConfiguration_FeePartitionConfiguration3_EOL_LookupTableSize   (8u) 
#define FeeConf_FeePartitionConfiguration_FeePartitionConfiguration1_BOOT_LookupTableSize  (4u) 
#define FeeConf_FeePartitionConfiguration_FeePartitionConfiguration2_APP_LookupTableSize   (32u) 

#define FeeConf_FeePartitionConfiguration_FeePartitionConfiguration4_DTC_LookupTableFlagsSize   (1u) 
#define FeeConf_FeePartitionConfiguration_FeePartitionConfiguration3_EOL_LookupTableFlagsSize   (1u) 
#define FeeConf_FeePartitionConfiguration_FeePartitionConfiguration1_BOOT_LookupTableFlagsSize  (1u) 
#define FeeConf_FeePartitionConfiguration_FeePartitionConfiguration2_APP_LookupTableFlagsSize   (4u) 


/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/
#if !defined (FEE_30_FLEXNOR_LOCAL) /* COV_FEE_30_FLEXNOR_COMPATIBILITY */
# define FEE_30_FLEXNOR_LOCAL static
#endif

#if !defined (FEE_30_FLEXNOR_LOCAL_INLINE) /* COV_FEE_30_FLEXNOR_COMPATIBILITY */
# define FEE_30_FLEXNOR_LOCAL_INLINE LOCAL_INLINE
#endif

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

#define FEE_30_FLEXNOR_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FEE_30_FLEXNOR_LOCAL VAR(Fee_30_FlexNor_ChunkLocationType, AUTOMATIC) FeeConf_FeePartitionConfiguration_FeePartitionConfiguration4_DTC_LookupTable[FeeConf_FeePartitionConfiguration_FeePartitionConfiguration4_DTC_LookupTableSize];

FEE_30_FLEXNOR_LOCAL VAR(Fee_30_FlexNor_FlagContainerType, AUTOMATIC) FeeConf_FeePartitionConfiguration_FeePartitionConfiguration4_DTC_ChunkReallocationFlags[FeeConf_FeePartitionConfiguration_FeePartitionConfiguration4_DTC_LookupTableFlagsSize];

FEE_30_FLEXNOR_LOCAL VAR(Fee_30_FlexNor_ChunkLocationType, AUTOMATIC) FeeConf_FeePartitionConfiguration_FeePartitionConfiguration3_EOL_LookupTable[FeeConf_FeePartitionConfiguration_FeePartitionConfiguration3_EOL_LookupTableSize];

FEE_30_FLEXNOR_LOCAL VAR(Fee_30_FlexNor_FlagContainerType, AUTOMATIC) FeeConf_FeePartitionConfiguration_FeePartitionConfiguration3_EOL_ChunkReallocationFlags[FeeConf_FeePartitionConfiguration_FeePartitionConfiguration3_EOL_LookupTableFlagsSize];

FEE_30_FLEXNOR_LOCAL VAR(Fee_30_FlexNor_ChunkLocationType, AUTOMATIC) FeeConf_FeePartitionConfiguration_FeePartitionConfiguration1_BOOT_LookupTable[FeeConf_FeePartitionConfiguration_FeePartitionConfiguration1_BOOT_LookupTableSize];

FEE_30_FLEXNOR_LOCAL VAR(Fee_30_FlexNor_FlagContainerType, AUTOMATIC) FeeConf_FeePartitionConfiguration_FeePartitionConfiguration1_BOOT_ChunkReallocationFlags[FeeConf_FeePartitionConfiguration_FeePartitionConfiguration1_BOOT_LookupTableFlagsSize];

FEE_30_FLEXNOR_LOCAL VAR(Fee_30_FlexNor_ChunkLocationType, AUTOMATIC) FeeConf_FeePartitionConfiguration_FeePartitionConfiguration2_APP_LookupTable[FeeConf_FeePartitionConfiguration_FeePartitionConfiguration2_APP_LookupTableSize];

FEE_30_FLEXNOR_LOCAL VAR(Fee_30_FlexNor_FlagContainerType, AUTOMATIC) FeeConf_FeePartitionConfiguration_FeePartitionConfiguration2_APP_ChunkReallocationFlags[FeeConf_FeePartitionConfiguration_FeePartitionConfiguration2_APP_LookupTableFlagsSize];

#define FEE_30_FLEXNOR_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define FEE_30_FLEXNOR_START_SEC_CONST_UNSPECIFIED
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FEE_30_FLEXNOR_LOCAL CONST(Fee_30_FlexNor_BlockConfigType, AUTOMATIC) FeeConf_FeePartitionConfiguration_FeePartitionConfiguration4_DTC_Blocks[3u] = {
  { /*  FeeLookupTableBlock_FeePartitionConfiguration4_DTC  */ 
    0x0001u /*  Id  */ , 
    0x0070u /*  Number  */ , 
    0x0010u /*  Length  */ , 
    FALSE /*  HasImmediateData  */ 
  }, 
  { /*  FeeDemAdminDataBlock  */ 
    0x0002u /*  Id  */ , 
    0x0020u /*  Number  */ , 
    0x000Eu /*  Length  */ , 
    FALSE /*  HasImmediateData  */ 
  }, 
  { /*  FeeDemStatusDataBlock  */ 
    0x0003u /*  Id  */ , 
    0x0030u /*  Number  */ , 
    0x0088u /*  Length  */ , 
    FALSE /*  HasImmediateData  */ 
  }
};

FEE_30_FLEXNOR_LOCAL CONST(Fee_30_FlexNor_BlockConfigType, AUTOMATIC) FeeConf_FeePartitionConfiguration_FeePartitionConfiguration3_EOL_Blocks[7u] = {
  { /*  FeeLookupTableBlock_FeePartitionConfiguration3_EOL  */ 
    0x0001u /*  Id  */ , 
    0x0060u /*  Number  */ , 
    0x0020u /*  Length  */ , 
    FALSE /*  HasImmediateData  */ 
  }, 
  { /*  FeeWDFC_ID_EOL_INFO  */ 
    0x0002u /*  Id  */ , 
    0x0110u /*  Number  */ , 
    0x0172u /*  Length  */ , 
    FALSE /*  HasImmediateData  */ 
  }, 
  { /*  FeeWDFC_ID_IDOPTION_SECURITY  */ 
    0x0003u /*  Id  */ , 
    0x0170u /*  Number  */ , 
    0x001Cu /*  Length  */ , 
    FALSE /*  HasImmediateData  */ 
  }, 
  { /*  FeeWDFC_ID_PART_NUMBER_GEELY  */ 
    0x0004u /*  Id  */ , 
    0x01E0u /*  Number  */ , 
    0x0022u /*  Length  */ , 
    FALSE /*  HasImmediateData  */ 
  }, 
  { /*  FeeWDFC_ID_EOL_PASSWORD  */ 
    0x0005u /*  Id  */ , 
    0x0120u /*  Number  */ , 
    0x0082u /*  Length  */ , 
    FALSE /*  HasImmediateData  */ 
  }, 
  { /*  FeeWDFC_ID_EOL_SWNUMBER  */ 
    0x0006u /*  Id  */ , 
    0x0130u /*  Number  */ , 
    0x0022u /*  Length  */ , 
    FALSE /*  HasImmediateData  */ 
  }, 
  { /*  FeeWDFC_ID_EOL_HW_VERSION  */ 
    0x0007u /*  Id  */ , 
    0x0100u /*  Number  */ , 
    0x000Cu /*  Length  */ , 
    FALSE /*  HasImmediateData  */ 
  }
};

FEE_30_FLEXNOR_LOCAL CONST(Fee_30_FlexNor_BlockConfigType, AUTOMATIC) FeeConf_FeePartitionConfiguration_FeePartitionConfiguration1_BOOT_Blocks[3u] = {
  { /*  FeeLookupTableBlock_FeePartitionConfiguration1_BOOT  */ 
    0x0001u /*  Id  */ , 
    0x0040u /*  Number  */ , 
    0x0010u /*  Length  */ , 
    FALSE /*  HasImmediateData  */ 
  }, 
  { /*  FeeWDFC_ID_BOOT_PARA  */ 
    0x0002u /*  Id  */ , 
    0x00A0u /*  Number  */ , 
    0x015Au /*  Length  */ , 
    FALSE /*  HasImmediateData  */ 
  }, 
  { /*  FeeWDFC_ID_ECUID_RDI_PROGRAMMING_INFO  */ 
    0x0003u /*  Id  */ , 
    0x00F0u /*  Number  */ , 
    0x0012u /*  Length  */ , 
    FALSE /*  HasImmediateData  */ 
  }
};

FEE_30_FLEXNOR_LOCAL CONST(Fee_30_FlexNor_BlockConfigType, AUTOMATIC) FeeConf_FeePartitionConfiguration_FeePartitionConfiguration2_APP_Blocks[31u] = {
  { /*  FeeLookupTableBlock_FeePartitionConfiguration2_APP  */ 
    0x0001u /*  Id  */ , 
    0x0050u /*  Number  */ , 
    0x0080u /*  Length  */ , 
    FALSE /*  HasImmediateData  */ 
  }, 
  { /*  FeeConfigBlock  */ 
    0x0002u /*  Id  */ , 
    0x0010u /*  Number  */ , 
    0x0004u /*  Length  */ , 
    FALSE /*  HasImmediateData  */ 
  }, 
  { /*  FeeConfigBlock_01  */ 
    0x0003u /*  Id  */ , 
    0x0011u /*  Number  */ , 
    0x0004u /*  Length  */ , 
    FALSE /*  HasImmediateData  */ 
  }, 
  { /*  FeeWDFC_ID_IDENT_BANK  */ 
    0x0004u /*  Id  */ , 
    0x0160u /*  Number  */ , 
    0x006Eu /*  Length  */ , 
    FALSE /*  HasImmediateData  */ 
  }, 
  { /*  FeeWDFC_ID_CCP  */ 
    0x0005u /*  Id  */ , 
    0x00B0u /*  Number  */ , 
    0x0092u /*  Length  */ , 
    FALSE /*  HasImmediateData  */ 
  }, 
  { /*  FeeWDFC_ID_WL_INFO  */ 
    0x0006u /*  Id  */ , 
    0x0280u /*  Number  */ , 
    0x0066u /*  Length  */ , 
    FALSE /*  HasImmediateData  */ 
  }, 
  { /*  FeeWDFC_ID_WLC_AP_LEARN  */ 
    0x0007u /*  Id  */ , 
    0x0270u /*  Number  */ , 
    0x0446u /*  Length  */ , 
    FALSE /*  HasImmediateData  */ 
  }, 
  { /*  FeeWDFC_ID_WLC_AP_LEARN_01  */ 
    0x0008u /*  Id  */ , 
    0x0271u /*  Number  */ , 
    0x0446u /*  Length  */ , 
    FALSE /*  HasImmediateData  */ 
  }, 
  { /*  FeeWDFC_ID_DLC  */ 
    0x0009u /*  Id  */ , 
    0x00D0u /*  Number  */ , 
    0x0026u /*  Length  */ , 
    FALSE /*  HasImmediateData  */ 
  }, 
  { /*  FeeWDFC_ID_DLC_01  */ 
    0x000Au /*  Id  */ , 
    0x00D1u /*  Number  */ , 
    0x0026u /*  Length  */ , 
    FALSE /*  HasImmediateData  */ 
  }, 
  { /*  FeeWDFC_ID_AP_CONNEX  */ 
    0x000Bu /*  Id  */ , 
    0x0080u /*  Number  */ , 
    0x0026u /*  Length  */ , 
    FALSE /*  HasImmediateData  */ 
  }, 
  { /*  FeeWDFC_ID_HANDLE_CFG  */ 
    0x000Cu /*  Id  */ , 
    0x0150u /*  Number  */ , 
    0x0012u /*  Length  */ , 
    FALSE /*  HasImmediateData  */ 
  }, 
  { /*  FeeWDFC_ID_MIRROR_CFG  */ 
    0x000Du /*  Id  */ , 
    0x01A0u /*  Number  */ , 
    0x0012u /*  Length  */ , 
    FALSE /*  HasImmediateData  */ 
  }, 
  { /*  FeeWDFC_ID_PMM  */ 
    0x000Eu /*  Id  */ , 
    0x01F0u /*  Number  */ , 
    0x004Eu /*  Length  */ , 
    FALSE /*  HasImmediateData  */ 
  }, 
  { /*  FeeWDFC_ID_SWP1  */ 
    0x000Fu /*  Id  */ , 
    0x0230u /*  Number  */ , 
    0x0402u /*  Length  */ , 
    FALSE /*  HasImmediateData  */ 
  }, 
  { /*  FeeWDFC_ID_VOL_POWER_MODE_CFG  */ 
    0x0010u /*  Id  */ , 
    0x0260u /*  Number  */ , 
    0x0012u /*  Length  */ , 
    FALSE /*  HasImmediateData  */ 
  }, 
  { /*  FeeWDFC_ID_AP_PARA  */ 
    0x0011u /*  Id  */ , 
    0x0090u /*  Number  */ , 
    0x0062u /*  Length  */ , 
    FALSE /*  HasImmediateData  */ 
  }, 
  { /*  FeeWDFC_ID_MIRROR_ST  */ 
    0x0012u /*  Id  */ , 
    0x01D0u /*  Number  */ , 
    0x001Au /*  Length  */ , 
    FALSE /*  HasImmediateData  */ 
  }, 
  { /*  FeeWDFC_ID_SR_PROFILE  */ 
    0x0013u /*  Id  */ , 
    0x0220u /*  Number  */ , 
    0x017Au /*  Length  */ , 
    FALSE /*  HasImmediateData  */ 
  }, 
  { /*  FeeWDFC_ID_THPA  */ 
    0x0014u /*  Id  */ , 
    0x0240u /*  Number  */ , 
    0x002Eu /*  Length  */ , 
    FALSE /*  HasImmediateData  */ 
  }, 
  { /*  FeeWDFC_ID_VEH_CFG  */ 
    0x0015u /*  Id  */ , 
    0x0250u /*  Number  */ , 
    0x000Au /*  Length  */ , 
    FALSE /*  HasImmediateData  */ 
  }, 
  { /*  FeeWDFC_ID_WL_LOG  */ 
    0x0016u /*  Id  */ , 
    0x0290u /*  Number  */ , 
    0x020Eu /*  Length  */ , 
    FALSE /*  HasImmediateData  */ 
  }, 
  { /*  FeeWDFC_ID_FAULT_CODE  */ 
    0x0017u /*  Id  */ , 
    0x0140u /*  Number  */ , 
    0x0042u /*  Length  */ , 
    FALSE /*  HasImmediateData  */ 
  }, 
  { /*  FeeWDFC_ID_MAX_FDC  */ 
    0x0018u /*  Id  */ , 
    0x0190u /*  Number  */ , 
    0x006Eu /*  Length  */ , 
    FALSE /*  HasImmediateData  */ 
  }, 
  { /*  FeeWDFC_ID_DTCTime  */ 
    0x0019u /*  Id  */ , 
    0x00E0u /*  Number  */ , 
    0x006Eu /*  Length  */ , 
    FALSE /*  HasImmediateData  */ 
  }, 
  { /*  FeeWDFC_ID_LAST_FDC  */ 
    0x001Au /*  Id  */ , 
    0x0180u /*  Number  */ , 
    0x006Eu /*  Length  */ , 
    FALSE /*  HasImmediateData  */ 
  }, 
  { /*  FeeWDFC_ID_DEBUG_DATA  */ 
    0x001Bu /*  Id  */ , 
    0x00C0u /*  Number  */ , 
    0x00B2u /*  Length  */ , 
    FALSE /*  HasImmediateData  */ 
  }, 
  { /*  FeeWDFC_ID_MIRROR_OTHER_1  */ 
    0x001Cu /*  Id  */ , 
    0x01B0u /*  Number  */ , 
    0x000Au /*  Length  */ , 
    FALSE /*  HasImmediateData  */ 
  }, 
  { /*  FeeWDFC_ID_MIRROR_POS_REC  */ 
    0x001Du /*  Id  */ , 
    0x01C0u /*  Number  */ , 
    0x0016u /*  Length  */ , 
    FALSE /*  HasImmediateData  */ 
  }, 
  { /*  FeeWDFC_ID_SECURITY_ACCESS  */ 
    0x001Eu /*  Id  */ , 
    0x0210u /*  Number  */ , 
    0x0016u /*  Length  */ , 
    FALSE /*  HasImmediateData  */ 
  }, 
  { /*  FeeWDFC_ID_QCM_FAULT_DATA  */ 
    0x001Fu /*  Id  */ , 
    0x0200u /*  Number  */ , 
    0x0056u /*  Length  */ , 
    FALSE /*  HasImmediateData  */ 
  }
};

FEE_30_FLEXNOR_LOCAL CONST(Fee_30_FlexNor_SectorConfigType, AUTOMATIC) FeeConf_FeePartitionConfiguration_FeePartitionConfiguration4_DTC_Sectors[4u] = {
  { /*  FeeSectorConfiguration  */ 
    0x00008000u /*  StartAddress  */  /* PRQA S 1257 */ /* MD_Fee_30_FlexNor_IntegerSuffixedWithLOrLL */, 
    0x00002000u /*  Length  */        /* PRQA S 1257 */ /* MD_Fee_30_FlexNor_IntegerSuffixedWithLOrLL */
  }, 
  { /*  FeeSectorConfiguration_1  */ 
    0x0000A000u /*  StartAddress  */  /* PRQA S 1257 */ /* MD_Fee_30_FlexNor_IntegerSuffixedWithLOrLL */, 
    0x00002000u /*  Length  */        /* PRQA S 1257 */ /* MD_Fee_30_FlexNor_IntegerSuffixedWithLOrLL */
  }, 
  { /*  FeeSectorConfiguration_2  */ 
    0x0000C000u /*  StartAddress  */  /* PRQA S 1257 */ /* MD_Fee_30_FlexNor_IntegerSuffixedWithLOrLL */, 
    0x00002000u /*  Length  */        /* PRQA S 1257 */ /* MD_Fee_30_FlexNor_IntegerSuffixedWithLOrLL */
  }, 
  { /*  FeeSectorConfiguration_3  */ 
    0x0000E000u /*  StartAddress  */  /* PRQA S 1257 */ /* MD_Fee_30_FlexNor_IntegerSuffixedWithLOrLL */, 
    0x00002000u /*  Length  */        /* PRQA S 1257 */ /* MD_Fee_30_FlexNor_IntegerSuffixedWithLOrLL */
  }
};

FEE_30_FLEXNOR_LOCAL CONST(Fee_30_FlexNor_SectorConfigType, AUTOMATIC) FeeConf_FeePartitionConfiguration_FeePartitionConfiguration3_EOL_Sectors[2u] = {
  { /*  FeeSectorConfiguration  */ 
    0x00007000u /*  StartAddress  */  /* PRQA S 1257 */ /* MD_Fee_30_FlexNor_IntegerSuffixedWithLOrLL */, 
    0x00000800u /*  Length  */        /* PRQA S 1257 */ /* MD_Fee_30_FlexNor_IntegerSuffixedWithLOrLL */
  }, 
  { /*  FeeSectorConfiguration_1  */ 
    0x00007800u /*  StartAddress  */  /* PRQA S 1257 */ /* MD_Fee_30_FlexNor_IntegerSuffixedWithLOrLL */, 
    0x00000800u /*  Length  */        /* PRQA S 1257 */ /* MD_Fee_30_FlexNor_IntegerSuffixedWithLOrLL */
  }
};

FEE_30_FLEXNOR_LOCAL CONST(Fee_30_FlexNor_SectorConfigType, AUTOMATIC) FeeConf_FeePartitionConfiguration_FeePartitionConfiguration1_BOOT_Sectors[2u] = {
  { /*  FeeSectorConfiguration  */ 
    0x00000000u /*  StartAddress  */  /* PRQA S 1257 */ /* MD_Fee_30_FlexNor_IntegerSuffixedWithLOrLL */, 
    0x00000800u /*  Length  */        /* PRQA S 1257 */ /* MD_Fee_30_FlexNor_IntegerSuffixedWithLOrLL */
  }, 
  { /*  FeeSectorConfiguration_1  */ 
    0x00000800u /*  StartAddress  */  /* PRQA S 1257 */ /* MD_Fee_30_FlexNor_IntegerSuffixedWithLOrLL */, 
    0x00000800u /*  Length  */        /* PRQA S 1257 */ /* MD_Fee_30_FlexNor_IntegerSuffixedWithLOrLL */
  }
};

FEE_30_FLEXNOR_LOCAL CONST(Fee_30_FlexNor_SectorConfigType, AUTOMATIC) FeeConf_FeePartitionConfiguration_FeePartitionConfiguration2_APP_Sectors[4u] = {
  { /*  FeeSectorConfiguration  */ 
    0x00001000u /*  StartAddress  */  /* PRQA S 1257 */ /* MD_Fee_30_FlexNor_IntegerSuffixedWithLOrLL */, 
    0x00001800u /*  Length  */        /* PRQA S 1257 */ /* MD_Fee_30_FlexNor_IntegerSuffixedWithLOrLL */
  }, 
  { /*  FeeSectorConfiguration_1  */ 
    0x00002800u /*  StartAddress  */  /* PRQA S 1257 */ /* MD_Fee_30_FlexNor_IntegerSuffixedWithLOrLL */, 
    0x00001800u /*  Length  */        /* PRQA S 1257 */ /* MD_Fee_30_FlexNor_IntegerSuffixedWithLOrLL */
  }, 
  { /*  FeeSectorConfiguration_2  */ 
    0x00004000u /*  StartAddress  */  /* PRQA S 1257 */ /* MD_Fee_30_FlexNor_IntegerSuffixedWithLOrLL */, 
    0x00001800u /*  Length  */        /* PRQA S 1257 */ /* MD_Fee_30_FlexNor_IntegerSuffixedWithLOrLL */
  }, 
  { /*  FeeSectorConfiguration_3  */ 
    0x00005800u /*  StartAddress  */  /* PRQA S 1257 */ /* MD_Fee_30_FlexNor_IntegerSuffixedWithLOrLL */, 
    0x00001800u /*  Length  */        /* PRQA S 1257 */ /* MD_Fee_30_FlexNor_IntegerSuffixedWithLOrLL */
  }
};

FEE_30_FLEXNOR_LOCAL CONST(Fee_30_FlexNor_PartitionConfigType, AUTOMATIC) Fee_30_FlexNor_PartitionConfig[FEE_30_FLEXNOR_CONFIGURED_PARTITIONS] = 
{
  { /*  FeePartitionConfiguration4_DTC  */ 
    0u /*  PartitionId  */ , 
    FEE_30_FLEXNOR_SECURELAYOUT /*  Layout  */ , 
    TRUE /*  BlankCheckRequired  */ , 
    4u /*  PageAlignment  */ , 
    1u /*  ReadAlignment  */ , 
    4u /*  InterferenceFreeAlignment  */ , 
    0xFFu /*  ErasedValue  */ , 
    FeeConf_FeePartitionConfiguration_FeePartitionConfiguration4_DTC_Sectors /*  Sectors  */ , 
    4u /*  SectorCount  */ , 
    FeeConf_FeePartitionConfiguration_FeePartitionConfiguration4_DTC_Blocks /*  Blocks  */ , 
    3u /*  BlockCount  */ , 
    FeeConf_FeePartitionConfiguration_FeePartitionConfiguration4_DTC_LookupTable /*  LookupTable  */ , 
    FeeConf_FeePartitionConfiguration_FeePartitionConfiguration4_DTC_ChunkReallocationFlags /*  ChunkReallocationFlags  */ , 
    FeeConf_FeePartitionConfiguration_FeePartitionConfiguration4_DTC_LookupTableSize /*  LookupTableSize  */ , 
    0x000000A6u /*  TotalConfiguredPayloadSize  */ , 
    0x0003D090u /*  MaximalEraseCycles  */ 
  }, 
  { /*  FeePartitionConfiguration3_EOL  */ 
    1u /*  PartitionId  */ , 
    FEE_30_FLEXNOR_SECURELAYOUT /*  Layout  */ , 
    TRUE /*  BlankCheckRequired  */ , 
    4u /*  PageAlignment  */ , 
    1u /*  ReadAlignment  */ , 
    4u /*  InterferenceFreeAlignment  */ , 
    0xFFu /*  ErasedValue  */ , 
    FeeConf_FeePartitionConfiguration_FeePartitionConfiguration3_EOL_Sectors /*  Sectors  */ , 
    2u /*  SectorCount  */ , 
    FeeConf_FeePartitionConfiguration_FeePartitionConfiguration3_EOL_Blocks /*  Blocks  */ , 
    7u /*  BlockCount  */ , 
    FeeConf_FeePartitionConfiguration_FeePartitionConfiguration3_EOL_LookupTable /*  LookupTable  */ , 
    FeeConf_FeePartitionConfiguration_FeePartitionConfiguration3_EOL_ChunkReallocationFlags /*  ChunkReallocationFlags  */ , 
    FeeConf_FeePartitionConfiguration_FeePartitionConfiguration3_EOL_LookupTableSize /*  LookupTableSize  */ , 
    0x00000280u /*  TotalConfiguredPayloadSize  */ , 
    0x0003D090u /*  MaximalEraseCycles  */ 
  }, 
  { /*  FeePartitionConfiguration1_BOOT  */ 
    2u /*  PartitionId  */ , 
    FEE_30_FLEXNOR_SECURELAYOUT /*  Layout  */ , 
    TRUE /*  BlankCheckRequired  */ , 
    4u /*  PageAlignment  */ , 
    1u /*  ReadAlignment  */ , 
    4u /*  InterferenceFreeAlignment  */ , 
    0xFFu /*  ErasedValue  */ , 
    FeeConf_FeePartitionConfiguration_FeePartitionConfiguration1_BOOT_Sectors /*  Sectors  */ , 
    2u /*  SectorCount  */ , 
    FeeConf_FeePartitionConfiguration_FeePartitionConfiguration1_BOOT_Blocks /*  Blocks  */ , 
    3u /*  BlockCount  */ , 
    FeeConf_FeePartitionConfiguration_FeePartitionConfiguration1_BOOT_LookupTable /*  LookupTable  */ , 
    FeeConf_FeePartitionConfiguration_FeePartitionConfiguration1_BOOT_ChunkReallocationFlags /*  ChunkReallocationFlags  */ , 
    FeeConf_FeePartitionConfiguration_FeePartitionConfiguration1_BOOT_LookupTableSize /*  LookupTableSize  */ , 
    0x0000017Cu /*  TotalConfiguredPayloadSize  */ , 
    0x0003D090u /*  MaximalEraseCycles  */ 
  }, 
  { /*  FeePartitionConfiguration2_APP  */ 
    3u /*  PartitionId  */ , 
    FEE_30_FLEXNOR_SECURELAYOUT /*  Layout  */ , 
    TRUE /*  BlankCheckRequired  */ , 
    4u /*  PageAlignment  */ , 
    1u /*  ReadAlignment  */ , 
    4u /*  InterferenceFreeAlignment  */ , 
    0xFFu /*  ErasedValue  */ , 
    FeeConf_FeePartitionConfiguration_FeePartitionConfiguration2_APP_Sectors /*  Sectors  */ , 
    4u /*  SectorCount  */ , 
    FeeConf_FeePartitionConfiguration_FeePartitionConfiguration2_APP_Blocks /*  Blocks  */ , 
    31u /*  BlockCount  */ , 
    FeeConf_FeePartitionConfiguration_FeePartitionConfiguration2_APP_LookupTable /*  LookupTable  */ , 
    FeeConf_FeePartitionConfiguration_FeePartitionConfiguration2_APP_ChunkReallocationFlags /*  ChunkReallocationFlags  */ , 
    FeeConf_FeePartitionConfiguration_FeePartitionConfiguration2_APP_LookupTableSize /*  LookupTableSize  */ , 
    0x00001678u /*  TotalConfiguredPayloadSize  */ , 
    0x0003D090u /*  MaximalEraseCycles  */ 
  }
};

#define FEE_30_FLEXNOR_STOP_SEC_CONST_UNSPECIFIED
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

#define FEE_30_FLEXNOR_START_SEC_CONST_UNSPECIFIED
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

CONST(Fee_30_FlexNor_ConfigType, AUTOMATIC) Fee_30_FlexNor_Config = {
    FALSE, /*  BootloaderModeEnabled  */
    Fee_30_FlexNor_PartitionConfig,
    FEE_30_FLEXNOR_CONFIGURED_PARTITIONS
};

#define FEE_30_FLEXNOR_STOP_SEC_CONST_UNSPECIFIED
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define FEE_30_FLEXNOR_START_SEC_VAR_NO_INIT_8
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#pragma alignvar(4)
Fee_30_FlexNor_DataType Fee_30_FlexNor_InternalBuffer[FEE_30_FLEXNOR_INTERNALBUFFER_SIZE];

#define FEE_30_FLEXNOR_STOP_SEC_VAR_NO_INIT_8
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define FEE_30_FLEXNOR_START_SEC_CODE
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

#define FEE_30_FLEXNOR_STOP_SEC_CODE
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
  END OF FILE: Fee_30_FlexNor_Lcfg.c
**********************************************************************************************************************/


 
