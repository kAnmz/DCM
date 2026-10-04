/******************************************************************************/
/*!
* \file        wdfc_config_dynamic.c
* \brief       Configuration file for Work Data Flash controler
* \author      Ken XU
* \since       
* \version     1.0
* \copyright   Magneti Marelli - Guangzhou
*
* \note        This file is generated dynamically, please don't edit!!!
*
* <br>
*/
/******************************************************************************/

/*______ I N C L U D E - F I L E S ___________________________________________*/

#include "wdfs_config_dynamic.h"
#include "wdfc_config_dynamic.h"
#include "NvM_cfg.h"


/*______ G L O B A L - D A T A _______________________________________________*/

WDFC_GroupConfigMapping_t const WDFC_GroupConfigMappingROM[WDFC_NUM_ID] =
{
  {NvMConf_NvMBlockDescriptor_WDFC_ID_IDENT_BANK,                  	      WDFC_SIZE_IDENT_BANK}
 ,{NvMConf_NvMBlockDescriptor_WDFC_ID_CCP,                                WDFC_SIZE_CCP}
 ,{NvMConf_NvMBlockDescriptor_WDFC_ID_WL_INFO,                            WDFC_SIZE_WL_INFO}
 ,{NvMConf_NvMBlockDescriptor_WDFC_ID_WLC_AP_LEARN,                       WDFC_SIZE_WLC_AP_LEARN}
 ,{NvMConf_NvMBlockDescriptor_WDFC_ID_DLC,                                WDFC_SIZE_DLC}
 ,{NvMConf_NvMBlockDescriptor_WDFC_ID_AP_CONNEX,                          WDFC_SIZE_AP_CONNEX}
 ,{NvMConf_NvMBlockDescriptor_WDFC_ID_HANDLE_CFG,                         WDFC_SIZE_HANDLE_CFG}
 ,{NvMConf_NvMBlockDescriptor_WDFC_ID_MIRROR_CFG,                         WDFC_SIZE_MIRROR_CFG}
 ,{NvMConf_NvMBlockDescriptor_WDFC_ID_PMM,                                WDFC_SIZE_PMM}
 ,{NvMConf_NvMBlockDescriptor_WDFC_ID_SWP1,                               WDFC_SIZE_SWP1}
 ,{NvMConf_NvMBlockDescriptor_WDFC_ID_VOL_POWER_MODE_CFG,                 WDFC_SIZE_VOL_POWER_MODE_CFG}
 ,{NvMConf_NvMBlockDescriptor_WDFC_ID_ECUID_RDI_PROGRAMMING_INFO,         WDFC_SIZE_ECUSIZE_RDI_PROGRAMMING_INFO}
 ,{NvMConf_NvMBlockDescriptor_WDFC_ID_AP_PARA,                            WDFC_SIZE_AP_PARA}
 ,{NvMConf_NvMBlockDescriptor_WDFC_ID_MIRROR_ST,                          WDFC_SIZE_MIRROR_ST}
 ,{NvMConf_NvMBlockDescriptor_WDFC_ID_SR_PROFILE,                         WDFC_SIZE_SR_PROFILE}
 ,{NvMConf_NvMBlockDescriptor_WDFC_ID_THPA,                               WDFC_SIZE_THPA}
 ,{NvMConf_NvMBlockDescriptor_WDFC_ID_VEH_CFG,                            WDFC_SIZE_VEH_CFG}
 ,{NvMConf_NvMBlockDescriptor_WDFC_ID_WL_LOG,                             WDFC_SIZE_WL_LOG}
 ,{NvMConf_NvMBlockDescriptor_WDFC_ID_BOOT_PARA,                          WDFC_SIZE_BOOT_PARA}
 ,{NvMConf_NvMBlockDescriptor_WDFC_ID_EOL_INFO,                           WDFC_SIZE_EOL_INFO}
 ,{NvMConf_NvMBlockDescriptor_WDFC_ID_IDOPTION_SECURITY,                  WDFC_SIZE_IDOPTION_SECURITY}
};

Wdfc_VarRomRamTab_t WDFC_VarRomRamTable[WDFC_NUM_ID][WDFC_NUM_TYPE_MEM]=
{
  {(uint8 *)&WDFS_RomIdentBank,                    (uint8 *)&WDFS_RamIdentBank,        }, /* WDFC_ID_IDENT_BANK */
  {(uint8 *)&WDFS_RomCCP,                          (uint8 *)&WDFS_RamCCP,              }, /* WDFC_ID_CCP */
  {(uint8 *)&WDFS_RomWL_INFO,                      (uint8 *)&WDFS_RamWL_INFO,          }, /* WDFC_ID_WL_INFO */
  {(uint8 *)&WDFS_RomWLC_APLearn,                  (uint8 *)&WDFS_RamWLC_APLearn,      }, /* WDFC_ID_WLC_AP_LEARN */
  {(uint8 *)&WDFS_RomDLC,                          (uint8 *)&WDFS_RamDLC,              }, /* WDFC_ID_DLC */
  {(uint8 *)&WDFS_RomAPConnex,                     (uint8 *)&WDFS_RamAPConnex,         }, /* WDFC_ID_AP_CONNEX */
  {(uint8 *)&WDFS_RomHandleCfg,                    (uint8 *)&WDFS_RamHandleCfg,        }, /* WDFC_ID_HANDLE_CFG */
  {(uint8 *)&WDFS_RomMirrorCfg,                    (uint8 *)&WDFS_RamMirrorCfg,        }, /* WDFC_ID_MIRROR_CFG */
  {(uint8 *)&WDFS_RomPMM,                          (uint8 *)&WDFS_RamPMM,              }, /* WDFC_ID_PMM */
  {(uint8 *)&WDFS_RomSWP1,                         (uint8 *)&WDFS_RamSWP1,             }, /* WDFC_ID_SWP1 */
  {(uint8 *)&WDFS_RomVolPowerModeCfg,              (uint8 *)&WDFS_RamVolPowerModeCfg,  }, /* WDFC_ID_VOL_POWER_MODE_CFG */
  {(uint8 *)&WDFS_RomRDIProgInfo,                  (uint8 *)&WDFS_RamRDIProgInfo,      }, /* WDFC_ID_ECUID_RDI_PROGRAMMING_INFO */
  {(uint8 *)&WDFS_RomAP_Para,                      (uint8 *)&WDFS_RamAP_Para,          }, /* WDFC_ID_AP_PARA */
  {(uint8 *)&WDFS_RomMirrorSt,                     (uint8 *)&WDFS_RamMirrorSt,         }, /* WDFC_ID_MIRROR_ST */
  {(uint8 *)&WDFS_RomSR_PROFILE,                   (uint8 *)&WDFS_RamSR_PROFILE,       }, /* WDFC_ID_SR_PROFILE */
  {(uint8 *)&WDFS_RomTHPA,                         (uint8 *)&WDFS_RamTHPA,             }, /* WDFC_ID_THPA */
  {(uint8 *)&WDFS_RomVehCfg,                       (uint8 *)&WDFS_RamVehCfg,           }, /* WDFC_ID_VEH_CFG */
  {(uint8 *)&WDFS_RomWL_Log,                       (uint8 *)&WDFS_RamWL_Log,           }, /* WDFC_ID_WL_LOG */
  {(uint8 *)&WDFS_RomBootPara,                     (uint8 *)&WDFS_RamBootPara,         }, /* WDFC_ID_BOOT_PARA */
  {(uint8 *)&WDFS_RomEOL_INFO,                     (uint8 *)&WDFS_RamEOL_INFO,         }, /* WDFC_ID_EOL_INFO */
  {(uint8 *)&WDFS_RomIDOptionSecurity,             (uint8 *)&WDFS_RamIDOptionSecurity, }, /* WDFC_ID_IDOPTION_SECURITY */
};
