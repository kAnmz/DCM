/******************************************************************************/
/* @F_NAME :          vers.h                                                  */
/* @F_PURPOSE :       manage reprogramming for MCU                            */
/* @F_CREATED_BY :     			                                              */
/* @F_CREATION_DATE :                                                         */
/* @F_LANGUAGE :      ANSI C                                                  */
/* @F_MPROC_TYPE :    target independent           						      */
/*************************************** (C) Copyright 2021 Marelli ***********/
#ifndef VERS_MAIN_H
#define VERS_MAIN_H
/*______ I N C L U D E - F I L E S ___________________________________________*/
#include "Platform_Types.h"
#include "vers_dynamic.h"
/*______ G L O B A L - D E F I N E S _________________________________________*/
#define WDFC_MAX_ID                 (96U)

typedef enum
{
  VERS_TI_CSOT  = 0x0u,
  VERS_MAX_CSOT = 0x1u,
  VERS_TI_JDI   = 0x2u,
  VERS_MAX_JDI  = 0x3u
} VERS_HwVersion_t;

typedef struct {
	uint8  VERS_ProjectName[10];
	uint8  VERS_SystemName[8];
	uint8  VERS_SoftwareVersion[7];
} VERS_SystemMessage_t;

/*______ G L O B A L - T Y P E S _____________________________________________*/

/* Information from boot */
typedef struct
{
  uint8 Year;      /* F184 - year */
  uint8 Month;     /* F184 - month */
  uint8 Day;       /* F184 - Day */
  uint8 TesterSerialNumber[6];  /* F184 - TesterSerialNumber */
  uint8 ProgrammingCounter;         /* DID 170F - 172F - 174F - 176F */
  uint8 ProgrammingAttempCounter;   /* DID 170F - 172F - 174F - 176F */

  uint8 SAFailedAccessCounter_L1;
  uint8 SAFailedAccessCounter_L3;
  //uint8 Spare[8];
} VERS_BootInfo_t;

/************************************/
/* Boot cofiguration data           */
/************************************/
typedef struct
{
  uint8  AplPresent;                                 /* AplPresent */
  uint8  FixedByte[16];                               /* FixedByte for 27 Service */
  uint8  Reserved[5];
  uint16 Checksum; 
} VERS_BootDataCfg_t;

typedef struct PublicKeyData
{
  uint8  PublicKeyModulus[256];
  uint8  PublicKeyExponent[4];
  uint8  PublicKeyCheckSum[32];
  uint8  PublicKeyProgramFlag;
  uint8  Spare[10];
} VERS_PublicKeyData_t;

/************************************/
/* Boot Para            */
/************************************/
typedef struct
{
  VERS_BootInfo_t BootSwFingerprint;
  VERS_BootDataCfg_t BootDataConfig;
  VERS_PublicKeyData_t PublicKeyData;
  uint16 Checksum;
}VERS_Boot_Para_t;

/* RDI 7209 */
typedef struct
{
  uint32 ProgrammingStatus;                          /* RDI $2010 */
  uint8  NumOfFlashRewritings;                       /* RDI $2003 */
  uint8  spare[5];                                      /* spare     */
  uint16 ReprogrammingAttemptCounter;                /* RDI $0216 */
  uint16 ReprogrammingCounter;                       /* RDI $0217 */
  uint16 Checksum;
} VERS_RDIProgInfo_t;

/* EEPROM identifier */
typedef struct
{
  uint16 EepromIdent;
  uint16 Reserved[2];
} VERS_EepromIdent_t;

typedef struct
{
  uint8 VersionBank[WDFC_MAX_ID];
  uint16 Spare[1];
} VERS_VersionBank_t;

typedef struct
{
  VERS_EepromIdent_t flashID;
  VERS_VersionBank_t BlockIdBank;
  uint16 Checksum;
} VERS_IdentBank_t;

typedef struct
{
  uint8 Reserved[64];
  uint8 Spare[2];
  uint16 Checksum;
}VERS_Boot_Ext1_t;

/* Identification option + VIN */
typedef struct
{
  /* for LOTUS DCU project */
  uint8   ECUSoftwarePartNumber[17];           /* 0xF1AE */
  uint8   ECUSerialNumber[4];                  /* DID 0xF18C */
  uint8   ECUManufactDate[3];                  /* DID 0xF18B */
} VERS_IdOptionData_t;

/* Security Access failure counter */
typedef struct {
  uint8   SecurityConstant[5];                 /*DID 0xF104*/
  uint8   SecurityConstantFlag;
  uint8   SecurityAccessAtt;
  uint8   SecurityAccessAtt_EOL;
  uint8   Reserved[4];
} VERS_SecurityAccessConfig_t;

/* Identification option and Security Access failure counter */
typedef struct {
  VERS_IdOptionData_t IdOptionData;
  uint16 Checksum;
} VERS_IDOptionSecurity_t;

/* VIN and SAF information */
typedef struct
{
  uint8  spare[6];
  uint16 Checksum;
} VERS_VinSafInfo_t;


/* EOL data file 160 bytes */
typedef struct
{
  uint16 KcData[44];
  uint8 Spare[70];
} VERS_EolDataFile_t; /* this data structure must have 160 bytes compliant to EOL Specification */

typedef struct
{
  uint8 Reserved[128];
  uint8 Spare[2];
}VERS_EolExt1_t;

typedef struct
{
  uint8 Reserved[64];
  uint8 Spare[2];
}VERS_EolExt2_t;

/* Magneti Marelli information */
typedef struct/*total length must less than 100 bytes*/
{
  uint8 EolDoneBcm;
  uint8 Spare[5];
} VERS_MmSe_t;

typedef struct
{
 uint8  dummy[4];
 uint8  spare;
} VERS_SupplierEOL_t;

typedef struct
{
  VERS_EolDataFile_t EolDataFile;
  VERS_EolExt1_t EolExt1;
  VERS_EolExt2_t EolExt2;
  VERS_MmSe_t MmSe;
  VERS_SupplierEOL_t SupplierEOL;
  uint16  CheckSum;
} VERS_EOL_INFO_t;

typedef struct
{
  uint16 ChksumApl;
  uint16 ECU_SWVersion;
  uint8  ECU_SWNumber[15];                           /* DID 0xF194 */
  uint8  ECU_PartNumberVersionID[6];                 /* DID 0xF103 */
  uint8  ECU_ODXFileNumberVersion[7];                /* DID 0xF19E */
} VERS_EOL_SWNumber_t;

typedef struct VERS_DtcID_s
{
  uint16                    ID; /* ID, type == DTCP_ID_t                         */
  uint8                     Symptom; /* Sintomi: DTCFailureTypeByte  */
  uint8                     Priority;
}VERS_DtcID_t;


typedef struct {
  uint16  Inhibit_State;
  uint16  CheckSum;
} VERS_INHIBIT_t;

typedef struct
{
  union
  {
    struct
    {
      uint8  SWP1Version[10];
      uint8  SWP1Partnumber[8];
      uint16 ThallsensorStall;
      uint16 TafterrunClosedDoor;
      uint16 TafterrunOpendDoor;
      uint16 Tcrankrec;
      uint16 Tmaxactivation;
      uint16 TVFCafterrun;
      uint16 TglobalDelayDDM;
      uint16 TglobalDelayPDM;
      uint16 TglobalDelayRLDM;
      uint16 TglobalDelayRRDM;
      uint16 TwinSwitchDelay;
      uint16 TmultiplePinch;
      uint16 Vmaxopen;
      uint16 NshorDropDist;
      uint16 BshorDropDist;
      uint16 TpinchOverride;
      uint16 NswitchOverride;
      uint16 TswitchOverride;
      uint16 VentOpenValue;
      uint16 Tmtrshrtcircuit;
      uint16 AutCmdTmr;
      uint16 PnchInhbtCntr;
      uint16 x_1;
      uint16 x_2;
      uint16 x_3;
      uint16 x_4;
      uint16 HndlTimLotToDply;
      uint16 HndlTimLotToRetr;
      uint16 MotBlockHndlLot;
      uint16 IceBreaktmrLot;
      uint16 TmsIceBearkLot;
      uint16 CoolDownTimIceBrk;
      uint16 OutVltRngeTmr;
      uint16 SafeOpeVel;
      uint16 RecHndlMov;
      uint16 ActivationTimeSafe;
      uint16 TargetForDeploy;
      uint16 TargetForRetract;
      uint16 DHBlockRangeBegin;
      uint16 DHBlockRangeEnd;
      uint16 DHIceBreakRangeBegin;
      uint16 DHIceBreakRangeEnd;
      uint16 SafeOpeVelPwm;
      uint16 DeployStartPwmDuty;
      uint16 DeployStablePwmDuty;
      uint16 DeployStartLinearTime;
      uint16 DeployEndPwmDuty;
      uint16 DeployStopLinearTime;
      uint16 DeployOutDelayTime;
      uint16 RetractStartPwmDuty;
      uint16 RetractStablePwmDuty;
      uint16 RetractStartLinearTime;
      uint16 RetractEndPwmDuty;
      uint16 RetractStopLinearTime;
      uint16 RetractOutDelayTime;
      uint16 ExtractRetractTranDelay;
      uint16 BlockCurThdOfDH;
      uint16 DHActivationtimes;
      uint16 DHAntiPlayTimeSpan;
      uint16 DHAntiPlayInhibitTime;
      uint16 DeployActtnInhibitTime;
      uint16 HndlInitHallCnt;
      uint16 HazardSleepMaxAgeTi;
      uint16 SideIndcrTiOut;
      uint16 StepTimeDimUpDoorhandleLight;
      uint16 StepTimeDimDownDoorhandleLight;
      uint16 DimUpStep1;
      uint16 DimUpStep2;
      uint16 DimUpStep3;
      uint16 DimUpStep4;
      uint16 DimDownStep1;
      uint16 DimDownStep2;
      uint16 DimDownStep3;
      uint16 DimDownStep4;
      uint16 DoorHandleLightDelay;
      uint16 DoorHandleLightAndPuddleLightTime;
      uint16 PWMBLISDNight;
      uint16 PWMBLISDDay;
      uint16 t_save_battery;
      uint16 t_total_dim;
      uint16 t_dim_slow;
      uint16 t_dim_fast;
      uint16 t_door_delay;
      uint16 t_deviation;
      uint16 WelcomeLiWaitTime;
      uint16 WelcomeLiBreathCycNum;
      uint16 WelcomeLiActTime;
      uint16 SideTurnIndicator;
      uint16 DoorLockActtnTi;
      uint16 DoorLockDelayTi;
      uint16 DoorLockActtnSecTi;
      uint16 DoorLockActtnDTCTi;
      uint16 NumberOfCrashUnlcks;
      uint16 LockActtnInhibitTime;
      uint16 CrashUnlockRetryTi;
      uint16 VFCTimeoutDelay;
      uint16 LockgDecodeEvalDelayCrashTi;
      uint16 DoorCrashUnlockActtnTi;
      uint16 CinchMotWaitTime;
      uint16 CinchMotCurLim;
      uint16 TimCinchActv;
      uint16 TmrCinchOper;
      uint16 TmrCinchRst;
      uint16 DoorCrashUnlockBreakonActtnTi;
      uint16 PowerReleaseMaxActtnTi;
      uint16 ConvDoorRlsRstMotTmr;
      uint16 TmrToReachAjar;
      uint16 RelsStrtTmr;
      uint16 ConvOpenSwtTmr;
      uint16 SigChgTiForShtDrp;
      uint16 RelsBrakeTi;
      uint16 IceBreakTim;
      uint16 TMirrManSleep;
      uint16 TMirrPosMotJam;
      uint16 VMirrUntilt;
      uint16 TMirrUntiltCom;
      uint16 LMirrStep;
      uint16 TMirrFoldDbnc;
      uint16 TMirrCrankTimeout;
      uint16 MirrorTiltFlashInterval;
      uint16 TMirrConvTimeout;
      uint16 TMirrInactiveTimeout;
      uint16 TMirrTiltAtRevDly;
      uint16 TMirrUntiltRevDly;
      uint16 T_VFCAdjDrvCtrl;
      uint16 T_MemBtnPsd;
      uint16 EEP_Tmax_MirrorFoldUnfold;
      uint16 EEP_LU_SwitchOffDelayT;
      uint16 EEP_HU_SwitchOffDelayT;
      uint16 EEP_LULT_SwitchOffCurThd;
      uint16 EEP_HULT_SwitchOffCurThd;
      uint16 EEP_LUHT_SwitchOffCurThd;
      uint16 EEP_HUHT_SwitchOffCurThd;
      uint16 EEP_InrushCurDetT;
      uint16 EEP_SwitchOffDelayDecT;
      uint16 EEP_SwitchOffCurThdDec;
      uint16 DefDrvProfPosX;
      uint16 DefDrvProfPosY;
      uint16 MirrorSelectBtnType;
      uint16 DelayTimeForAutoFold;
      uint16 MRPOSDeviation;
      uint16 XPosMidADC;
      uint16 YPosMidADC;
      uint16 DeltaPosXLeft;
      uint16 DeltaPosYLeft;
      uint16 MRPOSThresholdOfBlock;
      uint16 TMirrorMotorBlock;
      uint16 PosMaxBlockCnt;
      uint16 CFG_SEAT_SWITCH_STUCK_TMR;
      uint16 CFG_SEAT_SWITCH_UNSTUCK_TMR;
      uint16 TMR_BOSS_BTN_STUCK;
      uint16 TMR_BOSS_BTN_STUCK_UN ;
      uint16 EEP_VolModeConfirmTime;
      uint16 EEP_GoToSleepTime;
      uint16 MinHallNumOfATrip;
      uint16 ADPerDegree;
      uint16 DeltaPosXRight;
      uint16 DeltaPosYRight;
      uint16 TMirrMotoActv;
      uint16 CHActivationtimes;
      uint16 CHAntiPlayTimeSpan;
      uint16 CHAntiPlayInhibitTime;
      uint16 RelsKeepTi1;
      uint16 RelsKeepTi2;
      uint16 RelsKeepTi3;
      uint16 t_dlyShoDrpUnlockWait;
     } Field;
    uint8 Buffer[1020];
  } DataFile;
  uint16 MagicNum;
  uint16 Checksum;
} VERS_SWP1_t;

/* Part_Number_Geely */
typedef struct
{
  uint8  PN_F1A1[8];                                      /* DID F1A1     */
  uint8  PN_F1A5[8];                                      /* DID F1A5     */
  uint8  PN_F1AA[8];                                      /* DID F1AA     */
  uint8  PN_F1AB[8];                                      /* DID F1AB     */
} VERS_PartNumberGeelyInfo_t;

/*______ G L O B A L - D A T A _______________________________________________*/


/*______ P R I V A T E - T Y P E S ___________________________________________*/


/*______ G L O B A L - M A C R O S ___________________________________________*/

/*______ G L O B A L - F U N C T I O N S - P R O T O T Y P E S _______________*/
extern void Vers_runnable(void);
extern void Vers_init(void);

/******************************************************************************/
/* Name: VERS_Init                                                            */
/* Role: Read the FIAT Factory configuration and update all internal data     */
/*       depending                                                            */
/* Interface: none                                                            */
/* Pre-condition: EEPC_Init have to be done first                             */
/* Constraints: none                                                          */
/* Behavior:                                                                  */
/*   DO                                                                       */
/*     [  ]                                                                   */
/*   OD                                                                       */
/******************************************************************************/
extern void VERS_SetIdOptionDataAppDiagDatabasePartNumber(const uint8 *buf, uint16 len);
extern void VERS_GetIdOptionDataAppDiagDatabasePartNumber(uint8 *buf, uint16 len);

extern void VERS_SetIdOptionDataECUCoreAssemPartNumber(const uint8 *buf, uint16 len);
extern void VERS_GetIdOptionDataECUCoreAssemPartNumber(uint8 *buf, uint16 len);

extern void VERS_SetIdOptionDataECUDeliveryAssemPartNumber(const uint8 *buf, uint16 len);
extern void VERS_GetIdOptionDataECUDeliveryAssemPartNumber(uint8 *buf, uint16 len);

extern void VERS_SetIdOptionDataECUSoftwarePartNumber(const uint8 *buf, uint16 len);
extern void VERS_GetIdOptionDataECUSoftwarePartNumber(uint8 *buf, uint16 len);
extern void VERS_SetIdOptionDataECUSerialNumber(const uint8 *buf, uint16 len);
extern void VERS_GetIdOptionDataECUSerialNumber(uint8 *buf, uint16 len);



extern void VERS_SetBootInfoYear(uint8 val);
extern uint8 VERS_GetBootInfoYear(void);

extern void VERS_SetBootInfoMonth(uint8 val);
extern uint8 VERS_GetBootInfoMonth(void);

extern void VERS_SetBootInfoDay(uint8 val);
extern uint8 VERS_GetBootInfoDay(void);

extern void VERS_SetBootInfoTesterSerialNumber(const uint8 *buf, uint16 len);
extern void VERS_SetBootInfoTesterSerialNumberByIdx(uint16 idx, uint8 val);
extern void VERS_GetBootInfoTesterSerialNumber(uint8 *buf, uint16 len);
extern uint8 *VERS_GetBootInfoTesterSerialNumberAddr(void);
extern uint8 VERS_GetBootInfoTesterSerialNumberByIdx(uint16 idx);

extern void VERS_SetBootInfoProgrammingCounter(uint8 val);
extern uint8 VERS_GetBootInfoProgrammingCounter(void);

extern void VERS_SetBootInfoProgrammingAttempCounter(uint8 val);
extern uint8 VERS_GetBootInfoProgrammingAttempCounter(void);


extern void VERS_SetPublicKeyDataPublicKeyModulus(const uint8 *buf, uint16 len);
extern void VERS_GetPublicKeyDataPublicKeyModulus(uint8 *buf, uint16 len);
extern void VERS_SetPublicKeyDataPublicKeyExponent(const uint8 *buf, uint16 len);
extern void VERS_GetPublicKeyDataPublicKeyExponent(uint8 *buf, uint16 len);
extern void VERS_SetPublicKeyDataPublicKeyCheckSum(const uint8 *buf, uint16 len);
extern void VERS_GetPublicKeyDataPublicKeyCheckSum(uint8 *buf, uint16 len);
extern uint8 *VERS_GetPublicKeyDataPublicKeyCheckSumPtr(void);
extern void VERS_SetPublicKeyDataPublicKeyProgramFlag(uint8 flag);
extern uint8 VERS_GetPublicKeyDataPublicKeyProgramFlag(void);
extern void VERS_SetBootDataConfigProgramFlag(uint16 flag);
extern uint16 VERS_GetBootDataConfigProgramFlag(void);

extern void VERS_SetBootDataConfigFixedByte(const uint8 *buf, uint8 len);
extern void VERS_GetBootDataConfigFixedByte(uint8 *buf, uint8 len);

extern void VERS_SetSWP1Version(uint8 *buf, uint16 len);
extern void VERS_GetSWP1Version(uint8 *buf, uint16 len);

extern void VERS_SetSWP1Partnumber(uint8 *buf, uint16 len);
extern void VERS_GetSWP1Partnumber(uint8 *buf, uint16 len);


extern void VERS_SetSWP1ThallsensorStall(uint16 val);
extern uint16 VERS_GetSWP1ThallsensorStall(void);

extern void VERS_SetSWP1TafterrunClosedDoor(uint16 val);
extern uint16 VERS_GetSWP1TafterrunClosedDoor(void);

extern void VERS_SetSWP1TafterrunOpendDoor(uint16 val);
extern uint16 VERS_GetSWP1TafterrunOpendDoor(void);

extern void VERS_SetSWP1Tcrankrec(uint16 val);
extern uint16 VERS_GetSWP1Tcrankrec(void);

extern void VERS_SetSWP1Tmaxactivation(uint16 val);
extern uint16 VERS_GetSWP1Tmaxactivation(void);

extern void VERS_SetSWP1TVFCafterrun(uint16 val);
extern uint16 VERS_GetSWP1TVFCafterrun(void);

extern void VERS_SetSWP1TglobalDelayDDM(uint16 val);
extern uint16 VERS_GetSWP1TglobalDelayDDM(void);

extern void VERS_SetSWP1TglobalDelayPDM(uint16 val);
extern uint16 VERS_GetSWP1TglobalDelayPDM(void);

extern void VERS_SetSWP1TglobalDelayRLDM(uint16 val);
extern uint16 VERS_GetSWP1TglobalDelayRLDM(void);

extern void VERS_SetSWP1TglobalDelayRRDM(uint16 val);
extern uint16 VERS_GetSWP1TglobalDelayRRDM(void);

extern void VERS_SetSWP1TwinSwitchDelay(uint16 val);
extern uint16 VERS_GetSWP1TwinSwitchDelay(void);

extern void VERS_SetSWP1TmultiplePinch(uint16 val);
extern uint16 VERS_GetSWP1TmultiplePinch(void);

extern void VERS_SetSWP1Vmaxopen(uint16 val);
extern uint16 VERS_GetSWP1Vmaxopen(void);

extern void VERS_SetSWP1NshorDropDist(uint16 val);
extern uint16 VERS_GetSWP1NshorDropDist(void);

extern void VERS_SetSWP1BshorDropDist(uint16 val);
extern uint16 VERS_GetSWP1BshorDropDist(void);

extern void VERS_SetSWP1TpinchOverride(uint16 val);
extern uint16 VERS_GetSWP1TpinchOverride(void);

extern void VERS_SetSWP1NswitchOverride(uint16 val);
extern uint16 VERS_GetSWP1NswitchOverride(void);

extern void VERS_SetSWP1TswitchOverride(uint16 val);
extern uint16 VERS_GetSWP1TswitchOverride(void);

extern void VERS_SetSWP1VentOpenValue(uint16 val);
extern uint16 VERS_GetSWP1VentOpenValue(void);

extern void VERS_SetSWP1Tmtrshrtcircuit(uint16 val);
extern uint16 VERS_GetSWP1Tmtrshrtcircuit(void);

extern void VERS_SetSWP1AutCmdTmr(uint16 val);
extern uint16 VERS_GetSWP1AutCmdTmr(void);

extern void VERS_SetSWP1PnchInhbtCntr(uint16 val);
extern uint16 VERS_GetSWP1PnchInhbtCntr(void);

extern void VERS_SetSWP1x_1(uint16 val);
extern uint16 VERS_GetSWP1x_1(void);

extern void VERS_SetSWP1x_2(uint16 val);
extern uint16 VERS_GetSWP1x_2(void);

extern void VERS_SetSWP1x_3(uint16 val);
extern uint16 VERS_GetSWP1x_3(void);

extern void VERS_SetSWP1x_4(uint16 val);
extern uint16 VERS_GetSWP1Px_4(void);


extern void VERS_SetSWP1HndlTimLotToDply(uint16 val);
extern uint16 VERS_GetSWP1HndlTimLotToDply(void);

extern void VERS_SetSWP1HndlTimLotToRetr(uint16 val);
extern uint16 VERS_GetSWP1HndlTimLotToRetr(void);

extern void VERS_SetSWP1MotBlockHndlLot(uint16 val);
extern uint16 VERS_GetSWP1MotBlockHndlLot(void);

extern void VERS_SetSWP1IceBreaktmrLot(uint16 val);
extern uint16 VERS_GetSWP1IceBreaktmrLot(void);

extern void VERS_SetSWP1TmsIceBearkLot(uint16 val);
extern uint16 VERS_GetSWP1TmsIceBearkLot(void);

extern void VERS_SetSWP1CoolDownTimIceBrk(uint16 val);
extern uint16 VERS_GetSWP1CoolDownTimIceBrk(void);

extern void VERS_SetSWP1OutVltRngeTmr(uint16 val);
extern uint16 VERS_GetSWP1OutVltRngeTmr(void);

extern void VERS_SetSWP1SafeOpeVel(uint16 val);
extern uint16 VERS_GetSWP1SafeOpeVel(void);
extern void VERS_SetSWP1RecHndlMov(uint16 val);
extern uint16 VERS_GetSWP1RecHndlMov(void);

extern void VERS_SetSWP1ActivationTimeSafe(uint16 val);
extern uint16 VERS_GetSWP1ActivationTimeSafe(void);

extern void VERS_SetSWP1TargetForDeploy(uint16 val);
extern uint16 VERS_GetSWP1TargetForDeploy(void);

extern void VERS_SetSWP1TargetForRetract(uint16 val);
extern uint16 VERS_GetSWP1TargetForRetract(void);

extern void VERS_SetSWP1DHBlockRangeBegin(uint16 val);
extern uint16 VERS_GetSWP1DHBlockRangeBegin(void);

extern void VERS_SetSWP1DHBlockRangeEnd(uint16 val);
extern uint16 VERS_GetSWP1DHBlockRangeEnd(void);

extern void VERS_SetSWP1DHIceBreakRangeBegin(uint16 val);
extern uint16 VERS_GetSWP1DHIceBreakRangeBegin(void);

extern void VERS_SetSWP1DHIceBreakRangeEnd(uint16 val);
extern uint16 VERS_GetSWP1DHIceBreakRangeEnd(void);

extern void VERS_SetSWP1SafeOpeVelPwm(uint16 val);
extern uint16 VERS_GetSWP1SafeOpeVelPwm(void);

extern void VERS_SetSWP1DeployStartPwmDuty(uint16 val);
extern uint16 VERS_GetSWP1DeployStartPwmDuty(void);

extern void VERS_SetSWP1DeployStablePwmDuty(uint16 val);
extern uint16 VERS_GetSWP1DeployStablePwmDuty(void);

extern void VERS_SetSWP1DeployStartLinearTime(uint16 val);
extern uint16 VERS_GetSWP1DeployStartLinearTime(void);

extern void VERS_SetSWP1DeployEndPwmDuty(uint16 val);
extern uint16 VERS_GetSWP1DeployEndPwmDuty(void);

extern void VERS_SetSWP1DeployStopLinearTime(uint16 val);
extern uint16 VERS_GetSWP1DeployStopLinearTime(void);

extern void VERS_SetSWP1DeployOutDelayTime(uint16 val);
extern uint16 VERS_GetSWP1DeployOutDelayTime(void);

extern void VERS_SetSWP1RetractStartPwmDuty(uint16 val);
extern uint16 VERS_GetSWP1RetractStartPwmDuty(void);

extern void VERS_SetSWP1RetractStablePwmDuty(uint16 val);
extern uint16 VERS_GetSWP1RetractStablePwmDuty(void);

extern void VERS_SetSWP1RetractStartLinearTime(uint16 val);
extern uint16 VERS_GetSWP1RetractStartLinearTime(void);

extern void VERS_SetSWP1RetractEndPwmDuty(uint16 val);
extern uint16 VERS_GetSWP1RetractEndPwmDuty(void);

extern void VERS_SetSWP1RetractStopLinearTime(uint16 val);
extern uint16 VERS_GetSWP1RetractStopLinearTime(void);

extern void VERS_SetSWP1RetractOutDelayTime(uint16 val);
extern uint16 VERS_GetSWP1RetractOutDelayTime(void);

extern void VERS_SetSWP1ExtractRetractTranDelay(uint16 val);
extern uint16 VERS_GetSWP1ExtractRetractTranDelay(void);

extern void VERS_SetSWP1BlockCurThdOfDH(uint16 val);
extern uint16 VERS_GetSWP1BlockCurThdOfDH(void);

extern void VERS_SetSWP1DHActivationtimes(uint16 val);
extern uint16 VERS_GetSWP1DHActivationtimes(void);

extern void VERS_SetSWP1DHAntiPlayTimeSpan(uint16 val);
extern uint16 VERS_GetSWP1DHAntiPlayTimeSpan(void);

extern void VERS_SetSWP1DHAntiPlayInhibitTime(uint16 val);
extern uint16 VERS_GetSWP1DHAntiPlayInhibitTime(void);

extern void VERS_SetSWP1CHActivationtimes(uint16 val);
extern uint16 VERS_GetSWP1CHActivationtimes(void);

extern void VERS_SetSWP1CHAntiPlayTimeSpan(uint16 val);
extern uint16 VERS_GetSWP1CHAntiPlayTimeSpan(void);

extern void VERS_SetSWP1CHAntiPlayInhibitTime(uint16 val);
extern uint16 VERS_GetSWP1CHAntiPlayInhibitTime(void);

extern void VERS_SetSWP1DeployActtnInhibitTime(uint16 val);
extern uint16 VERS_GetSWP1DeployActtnInhibitTime(void);

extern void VERS_SetSWP1HndlInitHallCnt(uint16 val);
extern uint16 VERS_GetSWP1HndlInitHallCnt(void);

extern void VERS_SetSWP1HazardSleepMaxAgeTi(uint16 val);
extern uint16 VERS_GetSWP1HazardSleepMaxAgeTi(void);

extern void VERS_SetSWP1SideIndcrTiOut(uint16 val);
extern uint16 VERS_GetSWP1SideIndcrTiOut(void);

extern void VERS_SetSWP1StepTimeDimUpDoorhandleLight(uint16 val);
extern uint16 VERS_GetSWP1StepTimeDimUpDoorhandleLight(void);

extern void VERS_SetSWP1StepTimeDimDownDoorhandleLight(uint16 val);
extern uint16 VERS_GetSWP1StepTimeDimDownDoorhandleLight(void);

extern void VERS_SetSWP1DimUpStep1(uint16 val);
extern uint16 VERS_GetSWP1DimUpStep1(void);

extern void VERS_SetSWP1DimUpStep2(uint16 val);
extern uint16 VERS_GetSWP1DimUpStep2(void);

extern void VERS_SetSWP1DimUpStep3(uint16 val);
extern uint16 VERS_GetSWP1DimUpStep3(void);

extern void VERS_SetSWP1DimUpStep4(uint16 val);
extern uint16 VERS_GetSWP1DimUpStep4(void);

extern void VERS_SetSWP1DimDownStep1(uint16 val);
extern uint16 VERS_GetSWP1DimDownStep1(void);

extern void VERS_SetSWP1DimDownStep2(uint16 val);
extern uint16 VERS_GetSWP1DimDownStep2(void);

extern void VERS_SetSWP1DimDownStep3(uint16 val);
extern uint16 VERS_GetSWP1DimDownStep3(void);

extern void VERS_SetSWP1DimDownStep4(uint16 val);
extern uint16 VERS_GetSWP1DimDownStep4(void);

extern void VERS_SetSWP1DoorHandleLightDelay(uint16 val);
extern uint16 VERS_GetSWP1DoorHandleLightDelay(void);

extern void VERS_SetSWP1DoorHandleLightAndPuddleLightTime(uint16 val);
extern uint16 VERS_GetSWP1DoorHandleLightAndPuddleLightTime(void);

extern void VERS_SetSWP1PWMBLISDNight(uint16 val);
extern uint16 VERS_GetSWP1PWMBLISDNight(void);

extern void VERS_SetSWP1PWMBLISDDay(uint16 val);
extern uint16 VERS_GetSWP1PWMBLISDDay(void);

extern void VERS_SetSWP1t_save_battery(uint16 val);
extern uint16 VERS_GetSWP1t_save_battery(void);

extern void VERS_SetSWP1t_total_dim(uint16 val);
extern uint16 VERS_GetSWP1t_total_dim(void);

extern void VERS_SetSWP1t_dim_slow(uint16 val);
extern uint16 VERS_GetSWP1t_dim_slow(void);

extern void VERS_SetSWP1t_dim_fast(uint16 val);
extern uint16 VERS_GetSWP1t_dim_fast(void);

extern void VERS_SetSWP1t_door_delay(uint16 val);
extern uint16 VERS_GetSWP1t_door_delay(void);

extern void VERS_SetSWP1t_deviation(uint16 val);
extern uint16 VERS_GetSWP1t_deviation(void);

extern void VERS_SetSWP1SideTurnIndicator(uint16 val);
extern uint16 VERS_GetSWP1SideTurnIndicator(void);

extern void VERS_SetSWP1WelcomeLiWaitTime(uint16 val);
extern uint16 VERS_GetSWP1WelcomeLiWaitTime(void);

extern void VERS_SetSWP1WelcomeLiBreathCycNum(uint16 val);
extern uint16 VERS_GetSWP1WelcomeLiBreathCycNum(void);

extern void VERS_SetSWP1WelcomeLiActTime(uint16 val);
extern uint16 VERS_GetSWP1WelcomeLiActTime(void);

extern void VERS_SetSWP1DoorLockActtnTi(uint16 val);
extern uint16 VERS_GetSWP1DoorLockActtnTi(void);

extern void VERS_SetSWP1DoorLockDelayTi(uint16 val);
extern uint16 VERS_GetSWP1DoorLockDelayTi(void);

extern void VERS_SetSWP1DoorLockActtnSecTi(uint16 val);
extern uint16 VERS_GetSWP1DoorLockActtnSecTi(void);

extern void VERS_SetSWP1DoorLockActtnDTCTi(uint16 val);
extern uint16 VERS_GetSWP1DoorLockActtnDTCTi(void);

extern void VERS_SetSWP1NumberOfCrashUnlcks(uint16 val);
extern uint16 VERS_GetSWP1NumberOfCrashUnlcks(void);

extern void VERS_SetSWP1LockActtnInhibitTime(uint16 val);
extern uint16 VERS_GetSWP1LockActtnInhibitTime(void);

extern void VERS_SetSWP1CrashUnlockRetryTi(uint16 val);
extern uint16 VERS_GetSWP1CrashUnlockRetryTi(void);

extern void VERS_SetSWP1VFCTimeoutDelay(uint16 val);
extern uint16 VERS_GetSWP1VFCTimeoutDelay(void);

extern void VERS_SetSWP1LockgDecodeEvalDelayCrashTi(uint16 val);
extern uint16 VERS_GetSWP1LockgDecodeEvalDelayCrashTi(void);

extern void VERS_SetSWP1DoorCrashUnlockActtnTi(uint16 val);
extern uint16 VERS_GetSWP1DoorCrashUnlockActtnTi(void);

extern void VERS_SetSWP1CinchMotWaitTime(uint16 val);
extern uint16 VERS_GetSWP1CinchMotWaitTime(void);

extern void VERS_SetSWP1CinchMotCurLim(uint16 val);
extern uint16 VERS_GetSWP1CinchMotCurLim(void);

extern void VERS_SetSWP1TimCinchActv(uint16 val);
extern uint16 VERS_GetSWP1TimCinchActv(void);

extern void VERS_SetSWP1TmrCinchOper(uint16 val);
extern uint16 VERS_GetSWP1TmrCinchOper(void);

extern void VERS_SetSWP1TmrCinchRst(uint16 val);
extern uint16 VERS_GetSWP1TmrCinchRst(void);

extern void VERS_SetSWP1DoorCrashUnlockBreakonActtnTi(uint16 val);
extern uint16 VERS_GetSWP1DoorCrashUnlockBreakonActtnTi(void);

extern void VERS_SetSWP1PowerReleaseMaxActtnTi(uint16 val);
extern uint16 VERS_GetSWP1PowerReleaseMaxActtnTi(void);

extern void VERS_SetSWP1ConvDoorRlsRstMotTmr(uint16 val);
extern uint16 VERS_GetSWP1ConvDoorRlsRstMotTmr(void);

extern void VERS_SetSWP1TmrToReachAjar(uint16 val);
extern uint16 VERS_GetSWP1TmrToReachAjar(void);

extern void VERS_SetSWP1RelsStrtTmr(uint16 val);
extern uint16 VERS_GetSWP1RelsStrtTmr(void);

extern void VERS_SetSWP1ConvOpenSwtTmr(uint16 val);
extern uint16 VERS_GetSWP1ConvOpenSwtTmr(void);

extern void VERS_SetSWP1SigChgTiForShtDrp(uint16 val);
extern uint16 VERS_GetSWP1SigChgTiForShtDrp(void);

extern void VERS_SetSWP1RelsBrakeTi(uint16 val);
extern uint16 VERS_GetSWP1RelsBrakeTi(void);

extern void VERS_SetSWP1IceBreakTim(uint16 val);
extern uint16 VERS_GetSWP1IceBreakTim(void);

extern void VERS_SetSWP1TMirrManSleep(uint16 val);
extern uint16 VERS_GetSWP1TMirrManSleep(void);

extern void VERS_SetSWP1TMirrPosMotJam(uint16 val);
extern uint16 VERS_GetSWP1TMirrPosMotJam(void);

extern void VERS_SetSWP1VMirrUntilt(uint16 val);
extern uint16 VERS_GetSWP1VMirrUntilt(void);

extern void VERS_SetSWP1TMirrUntiltCom(uint16 val);
extern uint16 VERS_GetSWP1TMirrUntiltCom(void);

extern void VERS_SetSWP1LMirrStep(uint16 val);
extern uint16 VERS_GetSWP1LMirrStep(void);

extern void VERS_SetSWP1TMirrFoldDbnc(uint16 val);
extern uint16 VERS_GetSWP1TMirrFoldDbnc(void);

extern void VERS_SetSWP1TMirrCrankTimeout(uint16 val);
extern uint16 VERS_GetSWP1TMirrCrankTimeout(void);

extern void VERS_SetSWP1MirrorTiltFlashInterval(uint16 val);
extern uint16 VERS_GetSWP1MirrorTiltFlashInterval(void);

extern void VERS_SetSWP1TMirrConvTimeout(uint16 val);
extern uint16 VERS_GetSWP1TMirrConvTimeout(void);

extern void VERS_SetSWP1TMirrInactiveTimeout(uint16 val);
extern uint16 VERS_GetSWP1TMirrInactiveTimeout(void);

extern void VERS_SetSWP1TMirrTiltAtRevDly(uint16 val);
extern uint16 VERS_GetSWP1TMirrTiltAtRevDly(void);

extern void VERS_SetSWP1TMirrUntiltRevDly(uint16 val);
extern uint16 VERS_GetSWP1TMirrUntiltRevDly(void);

extern void VERS_SetSWP1T_VFCAdjDrvCtrl(uint16 val);
extern uint16 VERS_GetSWP1T_VFCAdjDrvCtrl(void);

extern void VERS_SetSWP1T_MemBtnPsd(uint16 val);
extern uint16 VERS_GetSWP1T_MemBtnPsd(void);

extern void VERS_SetSWP1EEP_Tmax_MirrorFoldUnfold(uint16 val);
extern uint16 VERS_GetSWP1EEP_Tmax_MirrorFoldUnfold(void);

extern void VERS_SetSWP1EEP_LU_SwitchOffDelayT(uint16 val);
extern uint16 VERS_GetSWP1EEP_LU_SwitchOffDelayT(void);

extern void VERS_SetSWP1EEP_HU_SwitchOffDelayT(uint16 val);
extern uint16 VERS_GetSWP1EEP_HU_SwitchOffDelayT(void);

extern void VERS_SetSWP1EEP_LULT_SwitchOffCurThd(uint16 val);
extern uint16 VERS_GetSWP1EEP_LULT_SwitchOffCurThd(void);

extern void VERS_SetSWP1EEP_HULT_SwitchOffCurThd(uint16 val);
extern uint16 VERS_GetSWP1EEP_HULT_SwitchOffCurThd(void);

extern void VERS_SetSWP1EEP_LUHT_SwitchOffCurThd(uint16 val);
extern uint16 VERS_GetSWP1EEP_LUHT_SwitchOffCurThd(void);

extern void VERS_SetSWP1EEP_HUHT_SwitchOffCurThd(uint16 val);
extern uint16 VERS_GetSWP1EEP_HUHT_SwitchOffCurThd(void);

extern void VERS_SetSWP1EEP_InrushCurDetT(uint16 val);
extern uint16 VERS_GetSWP1EEP_InrushCurDetT(void);

extern void VERS_SetSWP1EEP_SwitchOffDelayDecT(uint16 val);
extern uint16 VERS_GetSWP1EEP_SwitchOffDelayDecT(void);

extern void VERS_SetSWP1EEP_SwitchOffCurThdDec(uint16 val);
extern uint16 VERS_GetSWP1EEP_SwitchOffCurThdDec(void);

extern void VERS_SetSWP1DefDrvProfPosX(uint16 val);
extern uint16 VERS_GetSWP1DefDrvProfPosX(void);

extern void VERS_SetSWP1DefDrvProfPosY(uint16 val);
extern uint16 VERS_GetSWP1DefDrvProfPosY(void);

extern void VERS_SetSWP1MirrorSelectBtnType(uint16 val);
extern uint16 VERS_GetSWP1MirrorSelectBtnType(void);

extern void VERS_SetSWP1DelayTimeForAutoFold(uint16 val);
extern uint16 VERS_GetSWP1DelayTimeForAutoFold(void);

extern void VERS_SetSWP1MRPOSDeviation(uint16 val);
extern uint16 VERS_GetSWP1MRPOSDeviation(void);

extern void VERS_SetSWP1XPosMidADC(uint16 val);
extern uint16 VERS_GetSWP1XPosMidADC(void);

extern void VERS_SetSWP1YPosMidADC(uint16 val);
extern uint16 VERS_GetSWP1YPosMidADC(void);

extern void VERS_SetSWP1DeltaPosXLeft(uint16 val);
extern uint16 VERS_GetSWP1DeltaPosXLeft(void);

extern void VERS_SetSWP1DeltaPosYLeft(uint16 val);
extern uint16 VERS_GetSWP1DeltaPosYLeft(void);

extern void VERS_SetSWP1MRPOSThresholdOfBlock(uint16 val);
extern uint16 VERS_GetSWP1MRPOSThresholdOfBlock(void);

extern void VERS_SetSWP1TMirrorMotorBlock(uint16 val);
extern uint16 VERS_GetSWP1TMirrorMotorBlock(void);

extern void VERS_SetSWP1PosMaxBlockCnt(uint16 val);
extern uint16 VERS_GetSWP1PosMaxBlockCnt(void);

extern void VERS_SetSWP1CFG_SEAT_SWITCH_STUCK_TMR(uint16 val);
extern uint16 VERS_GetSWP1CFG_SEAT_SWITCH_STUCK_TMR(void);

extern void VERS_SetSWP1CFG_SEAT_SWITCH_UNSTUCK_TMR(uint16 val);
extern uint16 VERS_GetSWP1CFG_SEAT_SWITCH_UNSTUCK_TMR(void);

extern void VERS_SetSWP1TMR_BOSS_BTN_STUCK(uint16 val);
extern uint16 VERS_GetSWP1TMR_BOSS_BTN_STUCK(void);

extern void VERS_SetSWP1TMR_BOSS_BTN_STUCK_UN(uint16 val);
extern uint16 VERS_GetSWP1TMR_BOSS_BTN_STUCK_UN(void);

extern void VERS_SetSWP1EEP_VolModeConfirmTime(uint16 val);
extern uint16 VERS_GetSWP1EEP_VolModeConfirmTime(void);

extern void VERS_SetSWP1EEP_GoToSleepTime(uint16 val);
extern uint16 VERS_GetSWP1EEP_GoToSleepTime(void);

extern void VERS_SetSWP1MinHallNumOfATrip(uint16 val);
extern uint16 VERS_GetSWP1MinHallNumOfATrip(void);

extern void VERS_SetSWP1ADPerDegree(uint16 val);
extern uint16 VERS_GetSWP1ADPerDegree(void);

extern void VERS_SetSWP1DeltaPosXRight(uint16 val);
extern uint16 VERS_GetSWP1DeltaPosXRight(void);

extern void VERS_SetSWP1DeltaPosYRight(uint16 val);
extern uint16 VERS_GetSWP1DeltaPosYRight(void);

extern void VERS_SetSWP1TMirrMotoActv(uint16 val);
extern uint8 VERS_GetSWP1TMirrMotoActv(void);

extern void VERS_SetSWP1MagicNum(uint16 val);
extern uint16 VERS_GetSWP1MagicNum(void);


extern void VERS_SetIdOptionDataECUManufactDate(const uint8 *buf, uint16 len);
extern void VERS_GetIdOptionDataECUManufactDate(uint8 *buf, uint16 len);

#endif
