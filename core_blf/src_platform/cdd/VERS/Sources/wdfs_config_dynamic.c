/******************************************************************************/
/*!
* \file        wdfs_config_dynamic.c
* \brief       Declaration of global variables used for RAM mirror of 
*              variables stored in EEPROM 
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
#include "vers.h"
#include "dcu_version.h"

#ifndef  DCM_ZEEKR_SWP1
/* Msg(0686) Array has fewer initializers than its declared size. 
Evaluate: design purpose, no risk.*/
/*PRQA S 0686 ++*/

/* Msg(0694) Array initializer is missing the optional {. 
Evaluate: design purpose, no risk.*/
/*PRQA S 0694 ++*/

/*___________ R A M - D A T A _______________________________________________*/

/* Phase 1:Before first frame */
VERS_IdentBank_t              WDFS_RamIdentBank;
VERS_CCP_t                    WDFS_RamCCP;
VERS_WL_INFO_t                WDFS_RamWL_INFO;
VERS_WLC_APLearn_t            WDFS_RamWLC_APLearn;
VERS_DLC_t                    WDFS_RamDLC;
VERS_APConnex_t               WDFS_RamAPConnex;
//VERS_HandleCfg_t              WDFS_RamHandleCfg; // in OS_START_SEC_OsApplication_NonTrusted_VAR_ZERO_INIT
VERS_MirrorCfg_t              WDFS_RamMirrorCfg;
VERS_PMM_t                    WDFS_RamPMM;
VERS_SWP1_t                   WDFS_RamSWP1;
VERS_VolPowerModeCfg_t        WDFS_RamVolPowerModeCfg;
VERS_RDIProgInfo_t            WDFS_RamRDIProgInfo;

/* Phase 2:APP running */
VERS_AP_Para_t                WDFS_RamAP_Para;
VERS_MirrorSt_t               WDFS_RamMirrorSt;
VERS_SR_PROFILE_t             WDFS_RamSR_PROFILE;
VERS_Other_1                  WDFS_RamOther_1;
VERS_MIRR_POS_REC_t           WDFS_RamMIRR_POS_REC;
VERS_THPA_t                   WDFS_RamTHPA;
VERS_VehCfg_t                 WDFS_RamVehCfg;
VERS_WL_Log_t                 WDFS_RamWL_Log;
VERS_DebugData_t              WDFS_RamDebugData;
//uint8 WDFS_RamFaultcode[64]; // in OS_START_SEC_OsApplication_NonTrusted_VAR_ZERO_INIT

/* Phase 3:DTC, Log */
VERS_Boot_Para_t              WDFS_RamBootPara;
VERS_EOL_INFO_t               WDFS_RamEOL_INFO;
VERS_IDOptionSecurity_t       WDFS_RamIDOptionSecurity;
VERS_PartNumberGeelyInfo_t    WDFS_RamPart_Number_Geely;
//uint8 WDFS_RamMaxFdc[DEM_CFG_GLOBAL_PRIMARY_SIZE + 1]; // in OS_START_SEC_OsApplication_NonTrusted_VAR_ZERO_INIT


VERS_Debug_Msg_t WDFS_Debug_Msg = {0};
VERS_HandleCfg_t WDFS_RamHandleCfg;
uint8 WDFS_RamFaultcode[64] = {0};
uint8 WDFS_RamSafmFaultcode1[64] = {0};
uint8 WDFS_RamLastFdc[1]; 
uint8 WDFS_RamDTCTime[1]; 
uint8 WDFS_RamMaxFdc[DEM_CFG_GLOBAL_PRIMARY_SIZE + 1];
VERS_SecurityAccessConfig_t   WDFS_RamSecurityAccessConfig;
VERS_QCM_FAULT_DATA_t         WDFS_RamQCM_FAULT_DATA;

uint8                         WDFS_RamEOL_PASSWORD[1];
VERS_EOL_SWNumber_t           WDFS_RamEOL_SWNumber;
uint8                         WDFS_RamEOL_HW_VERSION[1];

/*___________ R O M - D A T A _______________________________________________*/

/* Phase 1:Before first frame */
const VERS_DebugData_t WDFS_RomDebugData = {0};

const VERS_CCP_t WDFS_RomCCP =
{
  {
    #if defined(DCU_FL)
    {0xB5,0x01,/*0x03,*/0x01,0x02,/*0x02,0x03,*/0x04,/*0x06,*/0x02,0x80,0x03,0x80,0x01,/*0x80,*/0x80,0x03,0x02,0x02,0x01,0x02,0x01,0x05,0x02,0x02,0x02,0x02,0x01,0x02,0x03,0x01,0x02,0x07,0x02,0x02,0x02,},0x0000,
    #elif defined(DCU_FR)
    {0xB5,0x01,/*0x03,*/0x01,0x02,/*0x02,*/0x4,0x02,0x80,0x03,0x80,0x01,/*0x80,*/0x80,0x03,0x02,0x02,0x01,0x02,0x01,0x05,0x02,0x02,0x02,0x02,0x01,0x02,0x03,0x01,0x02,0x07,0x02,0x02,0x02,},0x0000,
    #elif defined(DCU_RL)
    {0xB5,0x01,/*0x03,*/0x01,0x02,/*0x02,*/0x80,0x01,0x80,0x03,0x03,0x01,0x02,0x01,0x05,0x02,0x02,0x02,0x02,0x02,0x03,0x01,0x02,0x07,0x02,0x02,0x02,},0x0000,
    #elif defined(DCU_RR)
    {0xB5,0x01,/*0x03,*/0x01,0x02,/*0x02,*/0x80,0x01,0x80,0x03,0x03,0x01,0x02,0x01,0x05,0x02,0x02,0x02,0x02,0x02,0x03,0x01,0x02,0x07,0x02,0x02,0x02,},0x0000,
    #endif
  },

  {
      0x00
  },
  0x0000
};

const VERS_IdentBank_t WDFS_RomIdentBank =
{
    {
      WDFC_FLASH_IDENTIFIER,
    },
    {
      VERS_THING,              /* WDFC_ID_IDENT_BANK */
      VERS_THING,              /* WDFC_ID_CCP */
      VERS_NOTHING,            /* WDFC_ID_WL_INFO */
      VERS_NOTHING,            /* WDFC_ID_WLC_AP_LEARN */
      VERS_THING2,             /* WDFC_ID_DLC */
      VERS_NOTHING,            /* WDFC_ID_AP_CONNEX */
      VERS_THING,              /* WDFC_ID_HANDLE_CFG */
      VERS_NOTHING,            /* WDFC_ID_MIRROR_CFG */
      VERS_NOTHING,            /* WDFC_ID_PMM */
      VERS_NOTHING,            /* WDFC_ID_SWP1 */
      VERS_NOTHING,            /* WDFC_ID_VOL_POWER_MODE_CFG */
      VERS_NOTHING,            /* WDFC_ID_ECUID_RDI_PROGRAMMING_INFO */
      VERS_NOTHING,            /* WDFC_ID_AP_PARA */
      VERS_NOTHING,            /* WDFC_ID_MIRROR_ST */
      VERS_NOTHING,            /* WDFC_ID_SR_PROFILE */
#if defined(DCU_FL) || defined(DCU_FR)
      VERS_NOTHING,            /* WDFC_ID_MIRROR_OTHER_1 */
      VERS_NOTHING,            /* WDFC_ID_MIRROR_POS_REC */
#endif
      VERS_NOTHING,            /* WDFC_ID_THPA */
      VERS_NOTHING,            /* WDFC_ID_VEH_CFG */
      VERS_NOTHING,            /* WDFC_ID_WL_LOG */
      VERS_NOTHING,            /* WDFC_ID_SECURITY_ACCESS */
      VERS_NOTHING,            /* WDFC_ID_BOOT_PARA */
      VERS_NOTHING,            /* WDFC_ID_EOL_INFO */
      VERS_NOTHING,            /* WDFC_ID_IDOPTION_SECURITY */
      VERS_NOTHING,            /* WDFC_ID_QCM_FAULT_DATA */
      VERS_NOTHING,            /* WDFC_ID_MAX_FDC */
      VERS_NOTHING,            /* WDFC_ID_DTCTime */
      VERS_NOTHING,            /* WDFC_ID_LAST_FDC */
    },
    0x0000
};

const VERS_WL_INFO_t WDFS_RomWL_INFO =
{
  {
    {0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{181,181},{0,0},{0,0},0x00,{0,0},{0,0},{0},0x0000
  },
  {
    0x0000,0x00,0x00,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,{0x00}
  },
  {
  #if defined(DCU_FL)
  1,0,100,0,1,70,1,1,1,70,1,1,{0},560,0x0000,
  #elif defined(DCU_FR)
  1,0,100,0,1,70,1,1,1,70,1,1,{0},560,0x0000,
  #elif defined(DCU_RL)
  1,0,100,0,1,70,1,1,1,70,1,1,{0},550,0x0000,
  #elif defined(DCU_RR)
  1,0,100,0,1,70,1,1,1,70,1,1,{0},550,0x0000,
  #endif
  },
  0x0000
};

const VERS_WLC_APLearn_t WDFS_RomWLC_APLearn =
{
  {
    41000,43000,0x00,0x00,0x00,0x00,{0,10,20,30},14,14,14,14,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},0x00,0x00,0x00,0x00,0x00,0x00,0x0000,0x0000,0x0000,{0x00}
  },

  {
    0,20,20,10,10,0,{{0,0,0,0,0,0,0,0,0,0,40,25,20,30,30,30,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,13,22,30,11,19,35,27,26,25,20,19,14,12,18,13,22,28,17,44,18,25,20,28,16,23,21,19,18,32,16,12,16,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11,21,36,41,61,72,88,92,93,101,127,123,127,111,127,92,70,49,49,30,20,12,0,20,15,15,30,21,25,31,20,48,36,38,40,29,45,38,47,38,48,39,38,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},},{50,50,50,50},{100,100,100,100},{0x00}
  },
    0x0000
};

const VERS_DLC_t WDFS_RomDLC =
{
  0x02,0x02,0x02,0x02,0x02,0x02,FALSE,FALSE,FALSE,FALSE,0x01,0x01,0x01,FALSE,0x01,0x02,FALSE,FALSE,FALSE,FALSE,0x00,0x0000,
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
  0x0000
};

const VERS_APConnex_t WDFS_RomAPConnex = {
95,95,0,0,0,0,0,0,1900,{5400,3700},800,{140,150},0,{0x00},0,
};

const VERS_HandleCfg_t WDFS_RomHandleCfg = {
0x02,0x01,0x00,0x1E,0x06,0x0000,0x00,FALSE,0x00,0x00,0x0000
};

const VERS_MirrorCfg_t WDFS_RomMirrorCfg = {
0x0A,0x0A,0x02,0x01,0x00,{0x00,0x00,0x00,0x00},0x0000
};

const VERS_PMM_t WDFS_RomPMM = {
10,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,{{0x0}},0x00,{0x00,0x00},0x0000
};

const VERS_SWP1_t WDFS_RomSWP1 = 
{
  {
    SupplierECUSoftwareVersionNumber, // SWP1Version
    ECU_SWP1_PART_NUMBER,  //SWP1 PART NUMBER
      200,       // ThallsensorStall, ms
      12000,     // TafterrunClosedDoor, ms
      3000,      // TafterrunOpendDoor, ms
      200,       // Tcrankrec, ms
      20000,      // Tmaxactivation, ms
      2,         // TVFCafterrun, s
      0,         // TglobalDelayDDM, ms
      5,         // TglobalDelayPDM, ms
      10,        // TglobalDelayRLDM, ms
      15,        // TglobalDelayRRDM, ms
      250,       // TwinSwitchDelay, ms
      500,       // TmultiplePinch, ms
      180,       // Vmaxopen, Km/h
      26,        // NshorDropDist, mm
      45,        // BshorDropDist, mm
      500,       // TpinchOverride, ms 
      3,         // NswitchOverride, times
      500,       // TswitchOverride, ms
      16,        // VentOpenValue, %
      30,        // Tmtrshrtcircuit, ms
      3,         // AutCmdTmr, ms 
      50,        // PnchInhbtCntr, times
      40,        // x_1, %
      50,        // x_2, ms
      30,        // x_3, ms 
      1,         // x_4, times
      6,        // HndlTimLotToDply, ms
      13,        // HndlTimLotToRetr, ms
      20,         // MotBlockHndlLot, ms
      5,         // IceBreaktmrLot, ms
      4,         // TmsIceBearkLot, times
      3,         // CoolDownTimIceBrk, ms
      3,         // OutVltRngeTmr, ms
      1,         // SafeOpeVel, mm/s
      20,        // RecHndlMov, ms
      200,        // ActivationTimeSafe, 10ms
      320,       // TargetForDeploy, hall numbers
      15,         // TargetForRetract, hall numbers
      60,        // DHBlockRangeBegin, hall numbers
      300,       // DHBlockRangeEnd, hall numbers
      13,         // DHIceBreakRangeBegin, hall numbers
      60,        // DHIceBreakRangeEnd, hall numbers
      75,        // SafeOpeVelPwm, %
      30,        // DeployStartPwmDuty, %
      75,        // DeployStablePwmDuty, %
      10,        // DeployStartLinearTime, ms
      40,        // DeployEndPwmDuty, %
      10,        // DeployStopLinearTime, ms
      10,        // DeployOutDelayTime, ms
      30,        // RetractStartPwmDuty, %
      40,        // RetractStablePwmDuty, %
      10,        // RetractStartLinearTime, ms
      10,        // RetractEndPwmDuty, %
      10,        // RetractStopLinearTime, ms
      10,        // RetractOutDelayTime, ms
      20,        // ExtractRetractTranDelay, ms
      70,        // BlockCurThdOfDH, %
      20,        // DHActivationtimes, Times
      60,        // DHAntiPlayTimeSpan, s
      180,       // DHAntiPlayInhibitTime, s
      2,         // DeployActtnInhibitTime, ms
      67,        // HndlInitHallCnt  turn
      60,        // HazardSleepMaxAgeTi, S
      100,       // SideIndcrTiOut, ms
      80,        // StepTimeDimUpDoorhandleLight, ms
      250,       // StepTimeDimDownDoorhandleLight, ms
      4,         // DimUpStep1, %
      15,        // DimUpStep2, %
      52,        // DimUpStep3, %
      200,       // DimUpStep4, %
      200,       // DimDownStep1, %
      52,        // DimDownStep2, %
      15,        // DimDownStep3, %
      4,         // DimDownStep4, %
      0,         // DoorHandleLightDelay, ms
      22,        // DoorHandleLightAndPuddleLightTime, min
      100,       // PWMBLISDNight, %
      200,       // PWMBLISDDay, %
      4,         // t_save_battery, s
      24,        // t_total_dim, ms
      8,         // t_dim_slow, ms
      8,         // t_dim_fast, ms
      5,         // t_door_delay, ms
      15,        // t_deviation, ms
      0,         // SideTurnIndicator 
//      200,       // WelcomeLiWaitTime, ms
//      2,         // WelcomeLiBreathCycNum, Cycles 
//      4450,      // WelcomeLiActTime, ms
      20,        // DoorLockActtnTi, ms
      20,        // DoorLockDelayTi, ms
      5,          // DoorLockActtnSecTi, ms
      50,          // DoorLockActtnDTCTi, ms
      10,          // NumberOfCrashUnlcks, times
      40,          // LockActtnInhibitTime, ms
      10,          // CrashUnlockRetryTi, ms
      3,          // VFCTimeoutDelay, s
      20,          // LockgDecodeEvalDelayCrashTi, ms
      20,          // DoorCrashUnlockActtnTi, ms
      20,          // CinchMotWaitTime, ms
      15,          // CinchMotCurLim, A
      30,          // TimCinchActv, ms
      25,          // TmrCinchOper, ms
      25,          // TmrCinchRst, ms
      40,          // DoorCrashUnlockBreakonActtnTi, ms
      60,          // PowerReleaseMaxActtnTi, ms
      6,          // ConvDoorRlsRstMotTmr, ms
      20,          // TmrToReachAjar, ms
      30,          // RelsStrtTmr, ms
      35,          // ConvOpenSwtTmr, ms
      50,          // SigChgTiForShtDrp, ms
      4,          // RelsBrakeTi, ms
      15,          // IceBreakTim, ms
      4,          // TMirrManSleep, s
      30,          // TMirrPosMotJam, s
      10,          // VMirrUntilt, kph
      10,          // TMirrUntiltCom, s
      4,          // LMirrStep, units
      0,          // TMirrFoldDbnc, ms
      20,          // TMirrCrankTimeout, ms
      50,          // MirrorTiltFlashInterval, ms
      120,          // TMirrConvTimeout, s
      120,          // TMirrInactiveTimeout, s
      10,          // TMirrTiltAtRevDly, s
      10,          // TMirrUntiltRevDly, s
      30,          // T_VFCAdjDrvCtrl, s
      6,          // T_MemBtnPsd, s
      25,          // EEP_Tmax_MirrorFoldUnfold, s
      1000,          // EEP_LU_SwitchOffDelayT, ms
      300,          // EEP_HU_SwitchOffDelayT, ms
      80,          // EEP_LULT_SwitchOffCurThd, %
      80,          // EEP_HULT_SwitchOffCurThd, %
      80,          // EEP_LUHT_SwitchOffCurThd, %
      80,          // EEP_HUHT_SwitchOffCurThd, %
      150,          // EEP_InrushCurDetT, ms
      0,          // EEP_SwitchOffDelayDecT, ms
      72,          // EEP_SwitchOffCurThdDec, %
      900,          // DefDrvProfPosX, Degree
      900,          // DefDrvProfPosY, Degree
      1,          // MirrorSelectBtnType, -
      20,          // DelayTimeForAutoFold, ms
      32,          // MRPOSDeviation, ADC unit
      2048,          // XPosMidADC, ADC unit
      2048,          // YPosMidADC, ADC unit
      70,          // DeltaPosXLeft, ADC unit
      770,          // DeltaPosYLeft, ADC unit
      32,          // MRPOSThresholdOfBlock, ADC unit
      50,          // TMirrorMotorBlock, ms
      4,          // PosMaxBlockCnt, Count
      300,          // CFG_SEAT_SWITCH_STUCK_TMR, ms
      8,          // CFG_SEAT_SWITCH_UNSTUCK_TMR, ms
      300,          // TMR_BOSS_BTN_STUCK, ms
      8,          // TMR_BOSS_BTN_STUCK_UN , ms
      10,          // EEP_VolModeConfirmTime, ms
      1,          // EEP_GoToSleepTime, S
      319,          // MinHallNumOfATrip, hall numbers
      140,          // ADPerDegree, ADC unit
      40,          // DeltaPosXRight, ADC unit
      1200,          // DeltaPosYRight, ADC unit
      6,            //TMirrMotoActv
      10,        // CHActivationtimes, Times
      60,        // CHAntiPlayTimeSpan, s
      120,       // CHAntiPlayInhibitTime, s
      7,        // RelsKeepTi1
      40,        // RelsKeepTi2
      50,       // RelsKeepTi3
  },
  0x0000,
  0x0000,
};
#endif /*DCM_ZEEKR_SWP1*/

#ifdef  DCM_ZEEKR_SWP1/*Used to Generate Hex*/
const VERS_SWP1_t WDFS_RomSWP1Hex =
{
    {
      SupplierECUSoftwareVersionNumber, // SWP1Version
      ECU_SWP1_PART_NUMBER,  //SWP1 PART NUMBER
        200,       // ThallsensorStall, ms
        12000,     // TafterrunClosedDoor, ms
        3000,      // TafterrunOpendDoor, ms
        200,       // Tcrankrec, ms
        2000,       // Tmaxactivation, ms
        2,         // TVFCafterrun, s
        0,         // TglobalDelayDDM, ms
        5,         // TglobalDelayPDM, ms
        10,        // TglobalDelayRLDM, ms
        15,        // TglobalDelayRRDM, ms
        250,       // TwinSwitchDelay, ms
        500,       // TmultiplePinch, ms
        180,       // Vmaxopen, Km/h
        26,        // NshorDropDist, mm
        45,        // BshorDropDist, mm
        500,       // TpinchOverride, ms
        3,         // NswitchOverride, times
        500,       // TswitchOverride, ms
        16,        // VentOpenValue, %
        30,        // Tmtrshrtcircuit, ms
        3,         // AutCmdTmr, ms
        50,        // PnchInhbtCntr, times
        40,        // x_1, %
        50,        // x_2, ms
        30,        // x_3, ms
        1,         // x_4, times
        6,       // HndlTimLotToDply, ms
        13,        // HndlTimLotToRetr, ms
        2,          // MotBlockHndlLot, ms
        5,         // IceBreaktmrLot, ms
        4,         // TmsIceBearkLot, times
        3,         // CoolDownTimIceBrk, ms
        3,         // OutVltRngeTmr, ms
        1,         // SafeOpeVel, mm/s
        20,        // RecHndlMov, ms
        20,         // ActivationTimeSafe, 100ms
        320,       // TargetForDeploy, hall numbers
        15,          // TargetForRetract, hall numbers
        60,        // DHBlockRangeBegin, hall numbers
        300,       // DHBlockRangeEnd, hall numbers
        13,          // DHIceBreakRangeBegin, hall numbers
        60,        // DHIceBreakRangeEnd, hall numbers
        75,        // SafeOpeVelPwm, %
        30,        // DeployStartPwmDuty, %
        75,        // DeployStablePwmDuty, %
        10,        // DeployStartLinearTime, ms
        40,        // DeployEndPwmDuty, %
        10,        // DeployStopLinearTime, ms
        10,        // DeployOutDelayTime, ms
        30,        // RetractStartPwmDuty, %
        40,        // RetractStablePwmDuty, %
        10,        // RetractStartLinearTime, ms
        10,        // RetractEndPwmDuty, %
        10,        // RetractStopLinearTime, ms
        10,        // RetractOutDelayTime, ms
        20,        // ExtractRetractTranDelay, ms
        70,        // BlockCurThdOfDH, %
        20,        // DHActivationtimes, Times
        60,        // DHAntiPlayTimeSpan, s
        180,       // DHAntiPlayInhibitTime, s
        2,         // DeployActtnInhibitTime, ms
        67,        // HndlInitHallCnt  turn
        60,        // HazardSleepMaxAgeTi, S
        10,        // SideIndcrTiOut, ms
        80,        // StepTimeDimUpDoorhandleLight, ms
        250,       // StepTimeDimDownDoorhandleLight, ms
        4,         // DimUpStep1, %
        15,        // DimUpStep2, %
        52,        // DimUpStep3, %
        200,       // DimUpStep4, %
        200,       // DimDownStep1, %
        52,        // DimDownStep2, %
        15,        // DimDownStep3, %
        4,         // DimDownStep4, %
        0,         // DoorHandleLightDelay, ms
        22,        // DoorHandleLightAndPuddleLightTime, min
        100,       // PWMBLISDNight, %
        200,       // PWMBLISDDay, %
        4,         // t_save_battery, s
        24,        // t_total_dim, ms
        8,         // t_dim_slow, ms
        8,         // t_dim_fast, ms
        5,         // t_door_delay, ms
        15,        // t_deviation, ms
        200,       // WelcomeLiWaitTime, ms
        2,         // WelcomeLiBreathCycNum, Cycles
        4450,      // WelcomeLiActTime, ms
        1,         // SideTurnIndicator
        20,        // DoorLockActtnTi, ms
        20,        // DoorLockDelayTi, ms
        5,          // DoorLockActtnSecTi, ms
        50,          // DoorLockActtnDTCTi, ms
        10,          // NumberOfCrashUnlcks, times
        40,          // LockActtnInhibitTime, ms
        30,          // CrashUnlockRetryTi, ms
        3,          // VFCTimeoutDelay, s
        20,          // LockgDecodeEvalDelayCrashTi, ms
        20,          // DoorCrashUnlockActtnTi, ms
        15,          // CinchMotWaitTime, ms
        15,          // CinchMotCurLim, A
        5,           // TimCinchActv, ms
        25,          // TmrCinchOper, ms
        25,          // TmrCinchRst, ms
        40,          // DoorCrashUnlockBreakonActtnTi, ms
        60,          // PowerReleaseMaxActtnTi, ms
        30,         // ConvDoorRlsRstMotTmr, ms /* RelsReturnTi */
        20,          // TmrToReachAjar, ms
        30,          // RelsStrtTmr, ms
        35,          // ConvOpenSwtTmr, ms
        50,          // SigChgTiForShtDrp, ms
        4,          // RelsBrakeTi, ms
        15,          // IceBreakTim, ms
        4,          // TMirrManSleep, s
        30,          // TMirrPosMotJam, s
        10,          // VMirrUntilt, kph
        10,          // TMirrUntiltCom, s
        4,          // LMirrStep, units
        0,          // TMirrFoldDbnc, ms
        20,          // TMirrCrankTimeout, ms
        50,          // MirrorTiltFlashInterval, ms
        120,          // TMirrConvTimeout, s
        120,          // TMirrInactiveTimeout, s
        10,          // TMirrTiltAtRevDly, s
        10,          // TMirrUntiltRevDly, s
        30,          // T_VFCAdjDrvCtrl, s
        6,          // T_MemBtnPsd, s
        25,          // EEP_Tmax_MirrorFoldUnfold, s
        100,           // EEP_LU_SwitchOffDelayT, ms
        30,           // EEP_HU_SwitchOffDelayT, ms
        80,          // EEP_LULT_SwitchOffCurThd, %
        80,          // EEP_HULT_SwitchOffCurThd, %
        80,          // EEP_LUHT_SwitchOffCurThd, %
        80,          // EEP_HUHT_SwitchOffCurThd, %
        15,           // EEP_InrushCurDetT, ms
        5,          // EEP_SwitchOffDelayDecT, ms
        72,          // EEP_SwitchOffCurThdDec, %
        900,          // DefDrvProfPosX, Degree
        900,          // DefDrvProfPosY, Degree
        1,          // MirrorSelectBtnType, -
        20,          // DelayTimeForAutoFold, ms
        32,          // MRPOSDeviation, ADC unit
        2048,          // XPosMidADC, ADC unit
        2048,          // YPosMidADC, ADC unit
        70,          // DeltaPosXLeft, ADC unit
        770,          // DeltaPosYLeft, ADC unit
        32,          // MRPOSThresholdOfBlock, ADC unit
        50,          // TMirrorMotorBlock, ms
        4,          // PosMaxBlockCnt, Count
        300,          // CFG_SEAT_SWITCH_STUCK_TMR, ms
        8,          // CFG_SEAT_SWITCH_UNSTUCK_TMR, ms
        300,          // TMR_BOSS_BTN_STUCK, ms
        8,          // TMR_BOSS_BTN_STUCK_UN , ms
        10,          // EEP_VolModeConfirmTime, ms
        1,          // EEP_GoToSleepTime, S
        319,          // MinHallNumOfATrip, hall numbers
        140,          // ADPerDegree, ADC unit
        40,          // DeltaPosXRight, ADC unit
        1200,          // DeltaPosYRight, ADC unit
        6,            //TMirrMotoActv
        10,        // CHActivationtimes, Times
        60,        // CHAntiPlayTimeSpan, s
        120,       // CHAntiPlayInhibitTime, s
        7,        // RelsKeepTi1
        40,        // RelsKeepTi2
        50,       // RelsKeepTi3
        18,       // t_dlyShoDrpUnlockWait
    },
    0x0000,
    0x0000,
};

#endif  /*DCM_ZEEKR_SWP1*/

#ifndef  DCM_ZEEKR_SWP1
const VERS_VolPowerModeCfg_t WDFS_RomVolPowerModeCfg = {
0x0A,0x00,0x0A,0x00,{0x00,0x00},0x0000
};


const VERS_RDIProgInfo_t WDFS_RomRDIProgInfo =
{
  0xA5A5A5A5,                                   /* programming status         */
  0x00,                                         /* number of Flash rewritings */
  {0x00, 0x00, 0x00, 0x00,0x00},                /* spare                      */
  0x00,                                         /* RDI $0216 */
  0x00,                                         /* RDI $0217 */  
  0x0000                                        /* 16-bit checksum            */
};

/* Phase 2:APP running */
const VERS_AP_Para_t WDFS_RomAP_Para =
{
  {
    {130,130},{115,115},{100,100},{90,90},0,1,50,25,50,6,0,50,50,0,-25,0,600,0x0000,{0x00}
  },
  {
    #if defined(DCU_FL)
    128,128,70,70,70,20,30,30,15,15,15,25,180,180,128,250,0,{0x00}
    #elif defined(DCU_FR)
    128,128,70,70,70,20,30,30,15,15,15,25,180,180,128,250,0,{0x00}
    #elif defined(DCU_RL)
    128,128,70,70,70,20,30,30,15,15,15,25,180,180,180,250,0,{0x00}
    #elif defined(DCU_RR)
    128,128,70,70,70,20,30,30,15,15,15,25,180,180,180,250,0,{0x00}
    #endif
  },
  {
    #if defined(DCU_FL)
    60,50,40,40,{2900,3000},20,132,132,0,0,{0x00},0
    #elif defined(DCU_FR)
    60,50,40,40,{2900,3000},20,132,132,0,0,{0x00},0
    #elif defined(DCU_RL)
    60,50,40,40,{2900,3000},20,132,132,0,0,{0x00},0
    #elif defined(DCU_RR)
    60,50,40,40,{2900,3000},20,132,132,0,0,{0x00},0
    #endif
  },
  {
    0xE,0xE,0x258,0xF0,0x14,0x13,0x96,0x32,0x05,0x9,0x0A,0x00,0x00,0x00,{0x00}
  },
  0x0000
};

const VERS_MirrorSt_t WDFS_RomMirrorSt = {
0,12,15,2,0,0,0,0xffff,0xffff,0x0,{0x00},0x0000
};

const VERS_SR_PROFILE_t WDFS_RomSR_PROFILE = {
{{900,900},{900,900},{900,900},{900,900},{900,900},{900,900},{900,900},{900,900},{900,900},{900,900},{900,900},{900,900},{900,900}},{{900,900},{900,900},{900,900},{900,900},{900,900},{900,900},{900,900},{900,900},{900,900},{900,900},{900,900},{900,900},{900,900}},{{900,900},{900,900},{900,900},{900,900},{900,900},{900,900},{900,900},{900,900},{900,900},{900,900},{900,900},{900,900},{900,900}},{0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0},{0x00},0x0000
};

const VERS_Other_1 WDFS_RomOther_1 = {0};

const VERS_MIRR_POS_REC_t WDFS_RomMIRR_POS_REC = {0};

const VERS_THPA_t WDFS_RomTHPA = {
#if defined(DCU_FL) || defined(DCU_FR)
{0x0,0x0},{0x0,0x0},{0x0,0x0},{0x0,0x0},0x1,0x00,0x32,{0x00,0x00},{0x00,0x00},0x0000,0x0000,0x0190,0x0000,0x0000,0x0032,{0x00},0x0000
#else
{0x0,0x0},{0x0,0x0},{0x0,0x0},{0x0,0x0},0x1,0x00,0x32,{0x00,0x00},{0x00,0x00},0x0000,0x0000,0x0190,0x0000,0x0000,0x0032,{0x00},0x0000
#endif
};

const VERS_VehCfg_t WDFS_RomVehCfg = {
0x01,{0x00,0x00,0x00,0x00,0x00},0x0000,
};
const VERS_WL_Log_t WDFS_RomWL_Log =
{
  {
    {0x01,0x01},{0x00,0x00},{0x00,0x00},{0x00,0x00},{0x00,0x00},{0x00,0x00},{0x00,0x00},{0x00,0x00},{0x01,0x01},{0x00,0x00},{0x00,0x00},{0x00,0x00},{0x00,0x00},{0x00,0x00},{0x00,0x00},{0x00,0x00},{0x00}
  },
  {
    0
  },
  {
    0
  },
  0x0000
};

/* Phase 3:DTC, Log */
const VERS_Boot_Para_t WDFS_RomBootPara =
{
    {
      0x00,         /* F184 - year */
      0x00,         /* F184 - month */
      0x00,         /* F184 - Day */
      {0x20, 0x20, 0x20, 0x20, 0x20, 0x20},  /* F184 - TesterSerialNumber */
      0x00,         /* 170F - ProgrammingCounter */
      0x00,         /* 170F - ProgrammingAttempCounter */

      0x00,          /* SAFailedAccessCounter_L1*/
      0x00,          /* SAFailedAccessCounter_L3*/
      //0x00,          /* spare */
    },
    {
      0x00,                                       /* AplPresent             */
      0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,0xFF,               /*  FixedByte for 27 Service */
    },
    {
      {
        0xB7,0xE9,0x74,0x4B,0x45,0xFA,0xA6,0x20,0xD3,0x1C,
        0x30,0xE9,0x63,0x86,0xE9,0xCD,0x5F,0xB9,0x93,0xDE,
        0xCA,0x45,0xC9,0xD6,0x08,0x94,0xF7,0x7D,0xB9,0xEE,
        0xA9,0xD0,0x78,0x45,0x76,0x94,0x80,0x9D,0xF7,0x05,
        0x24,0xD7,0x30,0xE2,0xC0,0x0F,0x04,0x6E,0x60,0x53,
        0x23,0xBD,0x50,0x03,0xBF,0x2C,0xA9,0xBB,0xB4,0x5C,
        0xC5,0x11,0x5A,0x1D,0xCE,0x25,0x7D,0x42,0x03,0x4F,
        0x7E,0x1C,0x7A,0x3E,0x1A,0x68,0xE8,0x9A,0x00,0x10,
        0x8D,0x18,0x28,0xAC,0x26,0xBD,0x71,0xAE,0x4A,0xC9,
        0xB9,0x23,0x0B,0x9B,0xC1,0x01,0x67,0x46,0xA9,0x01,
        0x5E,0x70,0xF1,0xD9,0xBD,0x7F,0x56,0x4B,0x97,0x61,
        0x64,0xFF,0xC1,0xD9,0x6E,0x93,0xAB,0x40,0x66,0xD5,
        0xCB,0xF4,0x02,0xF5,0xFC,0x53,0x11,0x51,0xA9,0x80,
        0x5C,0x07,0x16,0xAB,0xCB,0x98,0x25,0xFE,0x02,0xF3,
        0x89,0x7E,0x57,0x91,0x7A,0x64,0xCC,0x2C,0x7A,0x71,
        0xE8,0x83,0x33,0x59,0x0A,0xA9,0x59,0x23,0xCF,0x4A,
        0x6B,0xE4,0x24,0x1A,0xF7,0x8C,0xA9,0x04,0x5D,0x65,
        0xB6,0x74,0x87,0x19,0x42,0x49,0xE3,0x69,0x03,0xDD,
        0xA4,0xC9,0x75,0xFE,0xA7,0x3C,0x07,0xC1,0x91,0x67,
        0x54,0x45,0xFE,0x5F,0xCF,0x45,0x72,0xF8,0xBD,0x47,
        0x95,0xBA,0x81,0xA7,0x54,0x50,0x55,0x29,0x92,0x2F,
        0x81,0x82,0x71,0x9B,0x43,0x1C,0xEB,0x27,0x16,0xCA,
        0x87,0xE2,0xBA,0x83,0xA0,0x1E,0x85,0xEF,0x75,0xE4,
        0x63,0x88,0x2D,0x0B,0x53,0x76,0xB6,0xB3,0xD6,0x68,
        0x19,0xE2,0x6C,0x2B,0x67,0x4F,0x0A,0x9D,0xDE,0xFE,
        0x93,0x42,0x43,0xCE,0x87,0xAD
      },
      {0x00,0x01,0x00,0x01},
      {
        0x31,0xDD,0xD9,0xEC,0x24,0x20,0x1A,0x6A,0x82,0x5D,
        0x84,0x02,0x18,0x60,0x9A,0xAB,0x65,0xB0,0x4E,0xFA,
        0x44,0xA0,0x4A,0x99,0x12,0xF4,0xBA,0xE8,0xE6,0x91,
        0xBB,0x9C
      }
      ,0x00
      ,0x00
    },
    0x0000
};

const VERS_EOL_INFO_t WDFS_RomEOL_INFO =
{
    {
      {
        2416, /*  0 COURTESY */
        4564, /*  1 POS_RIGHT */
        2392, /*  2 PWR_HALL_SENS */
        6237, /*  3 BKG */
        6264, /*  4 AMBIENT */
        4564, /*  5 POS_LEFT */
        1879, /*  6 REAR_FOG */
        2129, /*  7 REVERSE */
        575,    /*  8 TURN_LEFT BULB*/
        446,  /*  9 C_HS_BAT_SAVER */
        493,    /* 10 FRONT_FOG_LEFT BULB*/
        493,    /* 11 FRONT_FOG_RIGHT BULB*/
        635,  /* 12 LEFT_DRL */
        635,  /* 13 RIGHT_DRL */
        1266, /* 14 POS_REAR_LEFT*/
        1266, /* 15 POS_REAR_RIGHT*/
        1123, /* 16 BRAKE */
        575,   /* 17 TURN_RIGHT BULB*/
        575, /* 18 TURN_LEFT LED */
        575, /* 19 TURN_RIGHT LED */
        493, /* 20 FRONT_FOG_LEFT LED */
        493, /* 21 FRONT_FOG_RIGHT LED */
		0, /* 22 Free */
		0, /* 23 Free */
		0, /* 24 Free */
		0, /* 25 Free */
		0, /* 26 Free */
		0, /* 27 Free */
		0, /* 28 Free */
		0, /* 29 Free */
		0, /* 30 Free */
		0, /* 31 Free */
		0, /* 32 Free */
		0, /* 33 Free */
		0, /* 34 Free */
		0, /* 35 Free */
		0, /* 36 Free */
		0, /* 37 Free */
		0, /* 38 Free */
		0, /* 39 Free */
		0, /* 40 Free */
		0, /* 41 Free */
		0, /* 42 Free */
		0, /* 43 Free */
      },
      {
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
      },  /*Reserved*/
    },
    {
      {0x00},
      {0x00},
    },

    {
      {0x00},
      {0x00},
    },
    {
      0x00,/* EolDoneBcm*/
      {0x00, 0x00, 0x00, 0x00, 0x00},    /*ProductionDate*/
    },
    {
      {0x00, 0x00, 0x00, 0x00},
      0x00
    },
    0x0000
};

const uint8 WDFS_RomEOL_PASSWORD[1] = { 0x00 };

const VERS_IDOptionSecurity_t WDFS_RomIDOptionSecurity =
{
    {
      ECU_SOFTWARE_PART_NUMBER,         /* 0xF1AE */
      ECU_SERIAL_NUMBER,                /* 0xF18C */
      ECU_MANUFACTURING_DATE,           /* 0xF18B */
    },
    0x0000
};

const VERS_PartNumberGeelyInfo_t WDFS_RomPart_Number_Geely =
{
  #if defined(DCU_FL)
  {0x66u, 0x08u, 0x68u, 0x35u, 0x88u, 0x20u, 0x20u, 0x41u}, //DID F1A1
  {0x66u, 0x08u, 0x68u, 0x35u, 0x68u, 0x20u, 0x20u, 0x41u}, //DID F1A5
  {0x66u, 0x08u, 0x50u, 0x77u, 0x54u, 0x20u, 0x20u, 0x41u}, //DID F1AA
  {0x66u, 0x08u, 0x58u, 0x02u, 0x60u, 0x20u, 0x20u, 0x41u}, //DID F1AB
  #elif defined(DCU_FR)
  {0x66u, 0x08u, 0x68u, 0x52u, 0x55u, 0x20u, 0x20u, 0x41u}, //DID F1A1
  {0x66u, 0x08u, 0x68u, 0x35u, 0x82u, 0x20u, 0x20u, 0x41u}, //DID F1A5
  {0x66u, 0x08u, 0x50u, 0x77u, 0x53u, 0x20u, 0x20u, 0x41u}, //DID F1AA
  {0x66u, 0x08u, 0x58u, 0x02u, 0x59u, 0x20u, 0x20u, 0x41u}, //DID F1AB
  #elif defined(DCU_RL)
  {0x66u, 0x08u, 0x68u, 0x35u, 0x74u, 0x20u, 0x20u, 0x41u}, //DID F1A1
  {0x66u, 0x08u, 0x68u, 0x35u, 0x75u, 0x20u, 0x20u, 0x41u}, //DID F1A5
  {0x66u, 0x08u, 0x50u, 0x77u, 0x52u, 0x20u, 0x20u, 0x41u}, //DID F1AA
  {0x66u, 0x08u, 0x58u, 0x02u, 0x58u, 0x20u, 0x20u, 0x41u}, //DID F1AB
  #elif defined(DCU_RR)
  {0x66u, 0x08u, 0x68u, 0x35u, 0x66u, 0x20u, 0x20u, 0x41u}, //DID F1A1
  {0x66u, 0x08u, 0x68u, 0x35u, 0x67u, 0x20u, 0x20u, 0x41u}, //DID F1A5
  {0x66u, 0x08u, 0x50u, 0x77u, 0x51u, 0x20u, 0x20u, 0x41u}, //DID F1AA
  {0x66u, 0x08u, 0x58u, 0x02u, 0x57u, 0x20u, 0x20u, 0x41u}, //DID F1AB
  #endif
};

const VERS_SecurityAccessConfig_t   WDFS_RomSecurityAccessConfig = 
{
  {0xFF, 0xFF, 0xFF, 0xFF, 0xFF}, /* SecurityConstant */
  {0x00},                         /* SecurityConstantFlag */
  {0x00},                         /* SecurityAccessAtt */
  {0x00},                         /* SecurityAccessAtt_EOL */
  {0x00, 0x00, 0x00, 0x00}          /* Reserved */
};

const VERS_QCM_FAULT_DATA_t         WDFS_RomQCM_FAULT_DATA = {0x00};

const VERS_EOL_SWNumber_t WDFS_RomEOL_SWNumber = 
{
  {0x0000},           /* ChksumApl              */
  {0x0000},           /* ECU_SWVersion          */
  {"           "},    /* ECU_SWNumber[11]       */
  {"      "},         /* ECU_PartNumberVersionID[6]  */
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}   /* ECU_ODXFileNumberVersion[7]   */
};

const uint8 WDFS_RomEOL_HW_VERSION[10] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};

const WDFS_SWP1Range_t WDFS_Swp1_Range[sizeof(WDFS_RomSWP1.DataFile.Field)/sizeof(uint16)] = {
  {0,	     1000  }, // ThallsensorStall, ms
  {0,	     65000 }, // TafterrunClosedDoor, ms
  {0,	     65000 }, // TafterrunOpendDoor, ms
  {0,	     15000 }, // Tcrankrec, ms
  {0,	     3000  }, // Tmaxactivation, ms
  {0,	     30    }, // TVFCafterrun, s
  {0,	     26   }, // TglobalDelayDDM, ms,0-255ms
  {0,	     26   }, // TglobalDelayPDM, ms
  {0,	     26   }, // TglobalDelayRLDM, ms
  {0,	     26   }, // TglobalDelayRRDM, ms
  {0,	     65000 }, // TwinSwitchDelay, ms
  {0,	     1000  }, // TmultiplePinch, ms
  {0,	     250   }, // Vmaxopen, Km/h
  {0,	     500   }, // NshorDropDist, mm
  {0,	     500   }, // BshorDropDist, mm
  {0,	     650   }, // TpinchOverride, ms
  {0,	     10    }, // NswitchOverride, times
  {0,	     2000  }, // TswitchOverride, ms
  {0,	     100   }, // VentOpenValue, %
  {0,	     100   }, // Tmtrshrtcircuit, ms
  {0,	     10    }, // AutCmdTmr, ms
  {0,	     100   }, // PnchInhbtCntr, times
  {0,	     400   }, // x_1, %
  {0,        400   }, // x_2, ms
  {0,	     400   }, // x_3, ms
  {0,        20    }, // x_4, times
  {3,	     60    }, // HndlTimLotToDply, ms
  {3,	     60    }, // HndlTimLotToRetr, ms
  {1,	     60     }, // MotBlockHndlLot, ms
  {3,	     10    }, // IceBreaktmrLot, ms
  {1,	     8     }, // TmsIceBearkLot, times
  {1,	     8     }, // CoolDownTimIceBrk, ms
  {1,	     8     }, // OutVltRngeTmr, ms
  {0,	     10    }, // SafeOpeVel, mm/s
  {0,        200   }, // RecHndlMov, ms
  {0,	     250   }, // ActivationTimeSafe, 10ms
  {30,       512   }, // TargetForDeploy, hall numbers
  {0,	     20    },  // TargetForRetract, hall numbers
  {0,	     255   }, // DHBlockRangeBegin, hall numbers
  {0,	     512   }, // DHBlockRangeEnd, hall numbers
  {0,	     255   }, // DHIceBreakRangeBegin, hall numbers
  {0,	     255   }, // DHIceBreakRangeEnd, hall numbers
  {0,	     100   }, // SafeOpeVelPwm, %
  {0,	     100   }, // DeployStartPwmDuty, %
  {0,	     100   }, // DeployStablePwmDuty, %
  {0,	     100   }, // DeployStartLinearTime, ms
  {0,	     100   }, // DeployEndPwmDuty, %
  {0,	     100   }, // DeployStopLinearTime, ms
  {0,	     100   }, // DeployOutDelayTime, ms
  {0,	     100   }, // RetractStartPwmDuty, %
  {0,	     100   }, // RetractStablePwmDuty, %
  {0,	     100   }, // RetractStartLinearTime, ms
  {0,	     100   }, // RetractEndPwmDuty, %
  {0,	     100   }, // RetractStopLinearTime, ms
  {0,	     100   }, // RetractOutDelayTime, ms
  {0,	     100   }, // ExtractRetractTranDelay, ms
  {40,       100   }, // BlockCurThdOfDH, %
  {1,	     255   }, // DHActivationtimes, Times
  {1,	     255   }, // DHAntiPlayTimeSpan, s
  {1,	     720   }, // DHAntiPlayInhibitTime, s
  {0,	     5     }, // DeployActtnInhibitTime, ms
  {0,       512  }, // HndlInitHallCnt  turn
  {0,	     255   }, // HazardSleepMaxAgeTi, S
  {0,	     255   }, // SideIndcrTiOut, ms
  {0,	     2550  }, // StepTimeDimUpDoorhandleLight, ms
  {0,	     2550  }, // StepTimeDimDownDoorhandleLight, ms
  {0,	     200   }, // DimUpStep1, %
  {0,	     200   }, // DimUpStep2, %
  {0,	     200   }, // DimUpStep3, %
  {0,	     200   }, // DimUpStep4, %
  {0,	     200   }, // DimDownStep1, %
  {0,	     200   }, // DimDownStep2, %
  {0,	     200   }, // DimDownStep3, %
  {0,	     200   }, // DimDownStep4, %
  {0,	     255   }, // DoorHandleLightDelay, ms
  {1,	     30    }, // DoorHandleLightAndPuddleLightTime, mi
  {0,	     200   }, // PWMBLISDNight, %
  {0,	     200   }, // PWMBLISDDay, %
  {2,	     6     }, // t_save_battery, s
  {12,     36    },   // t_total_dim, ms
  {4,	     12    }, // t_dim_slow, ms
  {6,	     12    }, // t_dim_fast, ms
  {2,	     15    }, // t_door_delay, ms
  {0,	     255   }, // t_deviation, ms
  {0,	     1     }, // SideTurnIndicator
//  {0,	     300   },   // WelcomeLiWaitTime, ms
//  {1,	     5     },   // WelcomeLiBreathCycNum, Cycles
 // {0,	     6000  },   // WelcomeLiActTime, ms
  {0,	     255   }, // DoorLockActtnTi, ms
  {0,	     255   }, // DoorLockDelayTi, ms
  {0,	     255   },  // DoorLockActtnSecTi, ms
  {0,	     255   },   // DoorLockActtnDTCTi, ms
  {0,	     255   },   // NumberOfCrashUnlcks, times
  {0,	     255   },   // LockActtnInhibitTime, ms
  {0,	     255   },   // CrashUnlockRetryTi, ms
  {0,	     255   },  // VFCTimeoutDelay, s
  {0,	     255   },   // LockgDecodeEvalDelayCrashTi, ms
  {0,	     255   },   // DoorCrashUnlockActtnTi, ms
  {0,	     255   },   // CinchMotWaitTime, ms
  {0,	     40    },   // CinchMotCurLim, A
  {0,	     255   },   // TimCinchActv, ms
  {0,	     255   },   // TmrCinchOper, ms
  {0,	     255   },   // TmrCinchRst, ms
  {0,	     255   },   // DoorCrashUnlockBreakonActtnTi, ms
  {0,	     255   },   // PowerReleaseMaxActtnTi, ms
  {0,	     255   },    // ConvDoorRlsRstMotTmr, ms
  {10,	   40    },     // TmrToReachAjar, ms
  {0,	     255   },   // RelsStrtTmr, ms
  {0,	     255   },   // ConvOpenSwtTmr, ms
  {0,	     255   },   // SigChgTiForShtDrp, ms
  {0,	     20    },  // RelsBrakeTi, ms
  {0,	     30    },   // IceBreakTim, ms
  {0,	     10    },  // TMirrManSleep, s
  {20,     40    },     // TMirrPosMotJam, s
  {1,	     64    },   // VMirrUntilt, kph
  {1,	     64    },   // TMirrUntiltCom, s
  {1,	     64    },  // LMirrStep, units
  {0,	     10    },  // TMirrFoldDbnc, ms
  {0,	     150   },   // TMirrCrankTimeout, ms
  {0,	     255   },   // MirrorTiltFlashInterval, ms
  {0,	     1200  },    // TMirrConvTimeout, s
  {0,	     1200  },    // TMirrInactiveTimeout, s
  {0,	     1200  },   // TMirrTiltAtRevDly, s
  {0,	     1200  },   // TMirrUntiltRevDly, s
  {0,	     60    },   // T_VFCAdjDrvCtrl, s
  {0,	     40    },  // T_MemBtnPsd, s
  {0,	     30    },   // EEP_Tmax_MirrorFoldUnfold, s
  {0,	     2500  },    // EEP_LU_SwitchOffDelayT, ms
  {0,	     2500  },   // EEP_HU_SwitchOffDelayT, ms
  {0,	     100   },   // EEP_LULT_SwitchOffCurThd, %
  {0,	     100   },   // EEP_HULT_SwitchOffCurThd, %
  {0,	     100   },   // EEP_LUHT_SwitchOffCurThd, %
  {0,	     100   },   // EEP_HUHT_SwitchOffCurThd, %
  {0,	     2000  },   // EEP_InrushCurDetT, ms
  {0,	     2000  },  // EEP_SwitchOffDelayDecT, ms
  {0,	     100   },   // EEP_SwitchOffCurThdDec, %
  {0,	     1800  },    // DefDrvProfPosX, Degree
  {0,	     1800  },    // DefDrvProfPosY, Degree
  {0,	     3     },  // MirrorSelectBtnType, -
  {0,	     100   },   // DelayTimeForAutoFold, ms
  {0,	     255   },   // MRPOSDeviation, ADC unit
  {0,	     4095  },     // XPosMidADC, ADC unit
  {0,	     4095  },     // YPosMidADC, ADC unit
  {0,	     4095  },   // DeltaPosXLeft, ADC unit
  {0,	     4095  },    // DeltaPosYLeft, ADC unit
  {0,	     255   },   // MRPOSThresholdOfBlock, ADC unit
  {0,	     255   },   // TMirrorMotorBlock, ms
  {0,	     10    },  // PosMaxBlockCnt, Count
  {0,	     1275  },    // CFG_SEAT_SWITCH_STUCK_TMR, ms
  {0,	     255   },  // CFG_SEAT_SWITCH_UNSTUCK_TMR, ms
  {0,	     1275  },    // TMR_BOSS_BTN_STUCK, ms
  {0,	     255   },  // TMR_BOSS_BTN_STUCK_UN , ms
  {0,	     255   },   // EEP_VolModeConfirmTime, ms
  {0,	     255   },  // EEP_GoToSleepTime, S
  {1,	     512   },    // MinHallNumOfATrip, hall numbers
  {0,	     255   },    // ADPerDegree, ADC unit
  {0,	     4095  },   // DeltaPosXRight, ADC unit
  {0,	     4095  },   // DeltaPosYRight, ADC unit
  {0,	     255   },  // TMirrMotoActv
  {1,      255   }, // CHActivationtimes, Times
  {1,      255   }, // CHAntiPlayTimeSpan, s
  {1,      720   }, // CHAntiPlayInhibitTime, s
};


const uint8 WDFS_RomFaultcode[64] = {0};
const uint8 WDFS_RomSafmFaultcode1[64] = {0};
const uint8 WDFS_RomLastFdc[1] = {0};
const uint8 WDFS_RomMaxFdc[DEM_CFG_GLOBAL_PRIMARY_SIZE + 1] = {0};
const uint8 WDFS_RomDTCTime[1] = {0};
#endif
/*PRQA S 0686 --*/
/*PRQA S 0694 --*/

