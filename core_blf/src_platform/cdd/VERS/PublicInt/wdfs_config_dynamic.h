/******************************************************************************/
/*!
* \file        wdfs_config_dynamic.h
* \brief       Definition of global variables used for RAM mirror of 
*              variables stored in FLASH 
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

#ifndef WDFS_CONFIG_DYNAMIC_H
#define WDFS_CONFIG_DYNAMIC_H

/*______ I N C L U D E - F I L E S ___________________________________________*/

#include "Platform_Types.h"
#include "vers.h"
#include "vers_dynamic.h"

/* _____ L O C A L - T Y P E S _______________________________________________*/
typedef struct {
  uint16 min;
  uint16 max;
} WDFS_SWP1Range_t;
/*______ G L O B A L - D E F I N E S _________________________________________*/

#define WDFC_SIZE_IDENT_BANK                      ((uint16) sizeof(WDFS_RamIdentBank))
#define WDFC_SIZE_CCP                             ((uint16) sizeof(WDFS_RamCCP))
#define WDFC_SIZE_WL_INFO                         ((uint16) sizeof(WDFS_RamWL_INFO))
#define WDFC_SIZE_WLC_AP_LEARN                    ((uint16) sizeof(WDFS_RamWLC_APLearn))
#define WDFC_SIZE_DLC                             ((uint16) sizeof(WDFS_RamDLC))
#define WDFC_SIZE_AP_CONNEX                       ((uint16) sizeof(WDFS_RamAPConnex))
#define WDFC_SIZE_HANDLE_CFG                      ((uint16) sizeof(WDFS_RamHandleCfg))
#define WDFC_SIZE_MIRROR_CFG                      ((uint16) sizeof(WDFS_RamMirrorCfg))
#define WDFC_SIZE_PMM                             ((uint16) sizeof(WDFS_RamPMM))
#define WDFC_SIZE_SWP1                            ((uint16) sizeof(WDFS_RamSWP1))
#define WDFC_SIZE_VOL_POWER_MODE_CFG              ((uint16) sizeof(WDFS_RamVolPowerModeCfg))
#define WDFC_SIZE_ECUSIZE_RDI_PROGRAMMING_INFO    ((uint16) sizeof(WDFS_RamRDIProgInfo))
#define WDFC_SIZE_AP_PARA                         ((uint16) sizeof(WDFS_RamAP_Para))
#define WDFC_SIZE_MIRROR_ST                       ((uint16) sizeof(WDFS_RamMirrorSt))
#define WDFC_SIZE_SR_PROFILE                      ((uint16) sizeof(WDFS_RamSR_PROFILE))
#define WDFC_SIZE_MIRROR_OTHER_1                  ((uint16) sizeof(WDFS_RamOther_1))
#define WDFC_SIZE_MIRROR_POS_REC                  ((uint16) sizeof(WDFS_RamMIRR_POS_REC))
#define WDFC_SIZE_THPA                            ((uint16) sizeof(WDFS_RamTHPA))
#define WDFC_SIZE_VEH_CFG                         ((uint16) sizeof(WDFS_RamVehCfg))
#define WDFC_SIZE_WL_LOG                          ((uint16) sizeof(WDFS_RamWL_Log))
#define WDFC_SIZE_SECURITY_ACCESS_CFG             ((uint16) sizeof(WDFS_RamSecurityAccessConfig))
#define WDFC_SIZE_QCM_FAULT_DATA                  ((uint16) sizeof(WDFS_RamQCM_FAULT_DATA))
#define WDFC_SIZE_BOOT_PARA                       ((uint16) sizeof(WDFS_RamBootPara))
#define WDFC_SIZE_EOL_INFO                        ((uint16) sizeof(WDFS_RamEOL_INFO))
#define WDFC_SIZE_IDOPTION_SECURITY               ((uint16) sizeof(WDFS_RamIDOptionSecurity))
#define WDFC_SIZE_MAX_FDC                         ((uint16) sizeof(WDFS_RamMaxFdc))
#define WDFC_SIZE_DTCTIME                         ((uint16) sizeof(WDFS_RamDTCTime))
#define WDFC_SIZE_LAST_FDC                        ((uint16) sizeof(WDFS_RamLastFdc))

#if defined(DCU_FL)
	#define DEM_CFG_GLOBAL_PRIMARY_SIZE           95u
#elif defined(DCU_FR)
	#define DEM_CFG_GLOBAL_PRIMARY_SIZE           86u
#elif defined(DCU_RL)
	#define DEM_CFG_GLOBAL_PRIMARY_SIZE           71u
#elif defined(DCU_RR)
	#define DEM_CFG_GLOBAL_PRIMARY_SIZE           71u
#endif

/*___________ R A M - D A T A _______________________________________________*/
/* Phase 1:Before first frame */
extern VERS_IdentBank_t              WDFS_RamIdentBank;
extern VERS_CCP_t                    WDFS_RamCCP;
extern VERS_WL_INFO_t                WDFS_RamWL_INFO;
extern VERS_WLC_APLearn_t            WDFS_RamWLC_APLearn;
extern VERS_DLC_t                    WDFS_RamDLC;
extern VERS_APConnex_t               WDFS_RamAPConnex;
extern VERS_HandleCfg_t              WDFS_RamHandleCfg;
extern VERS_MirrorCfg_t              WDFS_RamMirrorCfg;
extern VERS_PMM_t                    WDFS_RamPMM;
extern VERS_SWP1_t                   WDFS_RamSWP1;
extern VERS_VolPowerModeCfg_t        WDFS_RamVolPowerModeCfg;
extern VERS_RDIProgInfo_t            WDFS_RamRDIProgInfo;

/* Phase 2:APP running */
extern VERS_AP_Para_t                WDFS_RamAP_Para;
extern VERS_MirrorSt_t               WDFS_RamMirrorSt;
extern VERS_SR_PROFILE_t             WDFS_RamSR_PROFILE;
extern VERS_Other_1                  WDFS_RamOther_1;
extern VERS_MIRR_POS_REC_t           WDFS_RamMIRR_POS_REC;
extern VERS_THPA_t                   WDFS_RamTHPA;
extern VERS_VehCfg_t                 WDFS_RamVehCfg;
extern VERS_WL_Log_t                 WDFS_RamWL_Log;
extern VERS_DebugData_t              WDFS_RamDebugData;

extern uint8 WDFS_RamFaultcode[64];
extern uint8 WDFS_RamSafmFaultcode1[64];
extern uint8 WDFS_RamLastFdc[1];
extern uint8 WDFS_RamMaxFdc[DEM_CFG_GLOBAL_PRIMARY_SIZE + 1];
extern uint8 WDFS_RamDTCTime[1]; 

/* Phase 3:DTC, Log */
extern VERS_Boot_Para_t              WDFS_RamBootPara;
extern VERS_EOL_INFO_t               WDFS_RamEOL_INFO;
extern VERS_IDOptionSecurity_t       WDFS_RamIDOptionSecurity;
extern VERS_PartNumberGeelyInfo_t    WDFS_RamPart_Number_Geely;
extern uint8                         WDFS_RamEOL_PASSWORD[1];
extern VERS_EOL_SWNumber_t           WDFS_RamEOL_SWNumber;
extern uint8                         WDFS_RamEOL_HW_VERSION[1];

extern VERS_SecurityAccessConfig_t   WDFS_RamSecurityAccessConfig;
extern VERS_QCM_FAULT_DATA_t         WDFS_RamQCM_FAULT_DATA;
/* debug msg */
extern VERS_Debug_Msg_t WDFS_Debug_Msg;


/*___________ R O M - D A T A _______________________________________________*/
extern const VERS_IdentBank_t              WDFS_RomIdentBank;
extern const VERS_CCP_t                    WDFS_RomCCP;
extern const VERS_WL_INFO_t                WDFS_RomWL_INFO;
extern const VERS_WLC_APLearn_t            WDFS_RomWLC_APLearn;
extern const VERS_DLC_t                    WDFS_RomDLC;
extern const VERS_APConnex_t               WDFS_RomAPConnex;
extern const VERS_HandleCfg_t              WDFS_RomHandleCfg;
extern const VERS_MirrorCfg_t              WDFS_RomMirrorCfg;
extern const VERS_PMM_t                    WDFS_RomPMM;
extern const VERS_SWP1_t                   WDFS_RomSWP1;
extern const VERS_VolPowerModeCfg_t        WDFS_RomVolPowerModeCfg;
extern const VERS_RDIProgInfo_t            WDFS_RomRDIProgInfo;

/* Phase 2:APP running */
extern const VERS_AP_Para_t                WDFS_RomAP_Para;
extern const VERS_MirrorSt_t               WDFS_RomMirrorSt;
extern const VERS_SR_PROFILE_t             WDFS_RomSR_PROFILE;
extern const VERS_Other_1                  WDFS_RomOther_1;
extern const VERS_MIRR_POS_REC_t           WDFS_RomMIRR_POS_REC;
extern const VERS_THPA_t                   WDFS_RomTHPA;
extern const VERS_VehCfg_t                 WDFS_RomVehCfg;
extern const VERS_WL_Log_t                 WDFS_RomWL_Log;
extern const VERS_DebugData_t              WDFS_RomDebugData;

extern const uint8 WDFS_RomFaultcode[64];
extern const uint8 WDFS_RomSafmFaultcode1[64];
extern const uint8 WDFS_RomLastFdc[1];
extern const uint8 WDFS_RomMaxFdc[DEM_CFG_GLOBAL_PRIMARY_SIZE + 1];
extern const uint8 WDFS_RomDTCTime[1];

/* Phase 3:DTC, Log */
extern const VERS_Boot_Para_t              WDFS_RomBootPara;
extern const VERS_EOL_INFO_t               WDFS_RomEOL_INFO;
extern const VERS_IDOptionSecurity_t       WDFS_RomIDOptionSecurity;
extern const VERS_PartNumberGeelyInfo_t    WDFS_RomPart_Number_Geely;
extern const uint8                         WDFS_RomEOL_PASSWORD[1];
extern const VERS_EOL_SWNumber_t           WDFS_RomEOL_SWNumber;
extern const uint8                         WDFS_RomEOL_HW_VERSION[10];

extern const VERS_SecurityAccessConfig_t   WDFS_RomSecurityAccessConfig;
extern const VERS_QCM_FAULT_DATA_t         WDFS_RomQCM_FAULT_DATA;

extern const WDFS_SWP1Range_t WDFS_Swp1_Range[sizeof(WDFS_RomSWP1.DataFile.Field)/sizeof(uint16)];

#endif

/*______ E N D _____ (wdfs_config_dynamic.h) _________________________________*/

