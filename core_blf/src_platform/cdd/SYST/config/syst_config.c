/******************************************************************************/
/*@F_NAME:           syst_config.c                                            */
/*@F_PURPOSE:        configuration file                                       */
/*@F_CREATED_BY:     P. MORIN                                                 */
/*@F_CREATION_DATE:  07/10/2002                                               */
/*@F_MPROC_TYPE:     MC9S12 ,REL_RL78_D1A ,REL_RL78_F12                       */
/************************************** (C) Copyright 2013 Magneti Marelli ****/

/*______ I N C L U D E - F I L E S ___________________________________________*/

#include "syst.h"
#include "wdtd.h"
#include "syst_config.h"
#include "cpus_config.h"
#include "iodc.h"

/*_____ L O C A L - D E F I N E ______________________________________________*/

/* Define applications entry point, MUST be a ROM address */
#pragma ghs startdata
#pragma ghs section rodata=".cliententrytext"
extern ubyte __ghsbegin_cliententrytext[];
#pragma ghs section rodata=default
#pragma ghs enddata

#define Boot_START_CLIENT                     ((SYST_AddressWidth_t) 0x00000000)
#define SYST_REBOOT() ( ( __NEAR__ void(*)(void))Boot_START_CLIENT )()


#pragma ghs startdata
#pragma ghs section rodata=".eolentrytext"
extern ubyte __ghsbegin_eolentrytext[];
#pragma ghs section rodata=default
#pragma ghs enddata


/*_____ L O C A L - T Y P E S ________________________________________________*/


/*_____ G L O B A L - D A T A ________________________________________________*/

#ifdef __NEC_V850__


#if defined(__CLIENT_LINK__)                      \
  || defined(__CLIENT_EOL_LINK__)                 \
  || ( ! defined(SYST_FLASH_BLOCK_DEF_IN_EEPROM))
/* Block definition:
   When a block is not used, put SYST_BDEF_NOT_USED in both _BlockType and
   _MemType. */
SYST_BlockDefinition_t const SYST_FlashBlockDefinition[SYST_FLASH_NB_OF_APPLI_BLOCK] =
{
  { SYST_BDEF_BLOCK_BLF    , SYST_BDEF_MEM_FLASH     },
  { SYST_BDEF_BLOCK_APPLI  , SYST_BDEF_MEM_FLASH     },
  { SYST_BDEF_BLOCK_DATASET, SYST_BDEF_MEM_EEPROM    },
  { SYST_BDEF_NOT_USED     , SYST_BDEF_NOT_USED      },
  { SYST_BDEF_NOT_USED     , SYST_BDEF_NOT_USED      },
  { SYST_BDEF_NOT_USED     , SYST_BDEF_NOT_USED      },
  { SYST_BDEF_NOT_USED     , SYST_BDEF_NOT_USED      },
  { SYST_BDEF_NOT_USED     , SYST_BDEF_NOT_USED      },
  { SYST_BDEF_NOT_USED     , SYST_BDEF_NOT_USED      }
};
#endif /* __CLIENT_LINK__
          || __CLIENT_EOL_LINK__
          || ! SYST_FLASH_BLOCK_DEF_IN_EEPROM */


#if ( ( ! defined(SYST_FLASH_BLOCK_DEF_IN_EEPROM))  \
      &&( defined(__BOOT_LOADER_FLASHER_LINK__)     \
          ||defined(__BOOT_CLIENT_EOL_LINK__) ) )   \
  || ( defined(SYST_FLASH_BLOCK_DEF_IN_EEPROM)      \
       &&( defined(__CLIENT_LINK__)                 \
           ||defined(__CLIENT_EOL_LINK__) ) )
/* Fulfill the table accroding to your micro-processor */
SYST_AddressWidth_t const SYST_FlashBlockAddress[SYST_FLASH_NB_OF_APPLI_BLOCK][2] =
{
  { SYST_BLF_START_ADDRESS,    SYST_BLF_END_ADDRESS},
  { SYST_APPLI_START_ADDRESS,  SYST_APPLI_END_ADDRESS},
  { SYST_EEPROM_START_ADDRESS, SYST_EEPROM_END_ADDRESS},
  { 0xFFFFFFFF,                0xFFFFFFFF},
  { 0xFFFFFFFF,                0xFFFFFFFF},
  { 0xFFFFFFFF,                0xFFFFFFFF},
  { 0xFFFFFFFF,                0xFFFFFFFF},
  { 0xFFFFFFFF,                0xFFFFFFFF},
  { 0xFFFFFFFF,                0xFFFFFFFF}
};

/* Fulfill the table according to your application for write access operation */
SYST_BlockStatus_t const SYST_FlashBlockStatus[SYST_FLASH_NB_OF_APPLI_BLOCK] = 
{
  SYST_BLOCK_PROTECTED,
  SYST_BLOCK_UNPROTECTED,
  SYST_BLOCK_UNPROTECTED,
  SYST_BLOCK_UNPROTECTED,
  SYST_BLOCK_UNPROTECTED,
  SYST_BLOCK_UNPROTECTED,
  SYST_BLOCK_UNPROTECTED,
  SYST_BLOCK_UNPROTECTED,
  SYST_BLOCK_UNPROTECTED
};
#endif /* ( ! SYST_FLASH_BLOCK_DEF_IN_EEPROM
            &&( __BOOT_LOADER_FLASHER_LINK__ || __BOOT_CLIENT_EOL_LINK__) )
          || ( SYST_FLASH_BLOCK_DEF_IN_EEPROM
               &&( __CLIENT_LINK__ || __CLIENT_EOL_LINK__) ) */

#if defined(__REL_V850_Dx4__) && (defined(SYST_DATA_SAVE_IN_RESET) || defined(SYST_DATA_SAVE_IN_DEEPSTOP))
#if defined(SYST_DATA_SAVE_IN_RESET)
/* Configure sections that are shared between BLF and CLIENT. These sections are restored after cpu
 * initialization. Put NULL at each address if not used. */
extern ubyte __ghsbegin_SharedSaveStart[], __ghsbegin_SharedSaveEnd[], __ghsbegin_SharedBackup[];
Syst_BkpSec_t const Syst_BkpSectBoot[Syst_BKP_SEC_NB_BOOT] =
{
  {(ulong*)__ghsbegin_SharedSaveStart, (ulong*)__ghsbegin_SharedSaveEnd, (ulong*)__ghsbegin_SharedBackup}
};

/* Configure sections that must be maintained between 2 reset. These sections are restored just before
 * CLIENT initialization. Put NULL at each address if not used. */
extern ubyte __ghsbegin_ResetSaveStart[], __ghsbegin_ResetSaveEnd[], __ghsbegin_ResetBackup[];
Syst_BkpSec_t const Syst_BkpSecBeforeInit[Syst_BKP_SEC_NB_BEFORE_INIT] =
{
  {(ulong*)__ghsbegin_ResetSaveStart, (ulong*)__ghsbegin_ResetSaveEnd, (ulong*)__ghsbegin_ResetBackup}
};
#endif /* SYST_DATA_SAVE_IN_RESET */


#if defined(SYST_DATA_SAVE_IN_DEEPSTOP)
extern ubyte __ghsbegin_SleepBeforeInitSaveStart[], __ghsbegin_SleepBeforeInitSaveEnd[], __ghsbegin_EepromBackup[];
Syst_BkpSec_t const Syst_BkpSecSleepBeforeInit[Syst_BKP_SEC_NB_SLEEP_BEFORE_INIT] =
{
  {(ulong*)__ghsbegin_SleepBeforeInitSaveStart, (ulong*)__ghsbegin_SleepBeforeInitSaveEnd, (ulong*)__ghsbegin_EepromBackup}
};
/* Configure sections that must be maintained at sleep. These sections are restored just after
 * CLIENT initialization. Put NULL at each address if not used. */
extern ubyte __ghsbegin_SleepSaveStart[], __ghsbegin_SleepSaveEnd[], __ghsbegin_SleepBackup[];
extern ubyte __ghsbegin_DsaSleepSaveStart[], __ghsbegin_DsaSleepSaveEnd[], __ghsbegin_DsaSleepBackup[];
Syst_BkpSec_t const Syst_BkpSecSleepAfterInit[Syst_BKP_SEC_NB_SLEEP_AFTER_INIT] =
{
  {(ulong*)__ghsbegin_SleepSaveStart, (ulong*)__ghsbegin_SleepSaveEnd, (ulong*)__ghsbegin_SleepBackup},
  {(ulong*)__ghsbegin_DsaSleepSaveStart, (ulong*)__ghsbegin_DsaSleepSaveEnd, (ulong*)__ghsbegin_DsaSleepBackup}
};
#endif /* SYST_DATA_SAVE_IN_DEEPSTOP */
#endif /* __REL_V850_DX4__ && (SYST_DATA_SAVE_IN_RESET || SYST_DATA_SAVE_IN_DEEPSTOP)*/
#endif /* __NEC_V850__ */


/* --- Marelli 07284 FBL package command section --- */

#if defined(C_COMP_GHS_TX49) || defined(C_COMP_GHS_V850) || defined(C_COMP_GHS_ARM)
#pragma ghs startdata
#pragma ghs section bss=".BootCmdZone"
#endif /* C_COMP_GHS_TX49 || C_COMP_GHS_V850 || C_COMP_GHS_ARM */

__NO_INIT__ SYST_FBLCommandDefinition_t SYST_FBLCommand;

#if defined(C_COMP_GHS_TX49) || defined(C_COMP_GHS_V850) || defined(C_COMP_GHS_ARM)
#pragma ghs section bss=default
#pragma ghs enddata
#endif /* C_COMP_GHS_TX49 || C_COMP_GHS_V850 || C_COMP_GHS_ARM */


/* Store Wakeup debug variable in a BACKUP RAM variable */
#pragma ghs startdata
#pragma ghs section bss=".DataBackup"
#pragma alignvar(4)
ulong   SYST_WUFLWakeup;
#pragma ghs section bss=default
#pragma ghs enddata


/*_____ L O C A L - D A T A __________________________________________________*/

#if (defined (Syst_CRC16_DATA_USED) && defined(Syst_COMPUTE_CRC16_USING_TABLE))
const ushort Syst_InvCrcTable[] =
{
 0x0000, 0x1189, 0x2312, 0x329b, 0x4624, 0x57ad, 0x6536, 0x74bf,
 0x8c48, 0x9dc1, 0xaf5a, 0xbed3, 0xca6c, 0xdbe5, 0xe97e, 0xf8f7,
 0x1081, 0x0108, 0x3393, 0x221a, 0x56a5, 0x472c, 0x75b7, 0x643e,
 0x9cc9, 0x8d40, 0xbfdb, 0xae52, 0xdaed, 0xcb64, 0xf9ff, 0xe876,
 0x2102, 0x308b, 0x0210, 0x1399, 0x6726, 0x76af, 0x4434, 0x55bd,
 0xad4a, 0xbcc3, 0x8e58, 0x9fd1, 0xeb6e, 0xfae7, 0xc87c, 0xd9f5,
 0x3183, 0x200a, 0x1291, 0x0318, 0x77a7, 0x662e, 0x54b5, 0x453c,
 0xbdcb, 0xac42, 0x9ed9, 0x8f50, 0xfbef, 0xea66, 0xd8fd, 0xc974,
 0x4204, 0x538d, 0x6116, 0x709f, 0x0420, 0x15a9, 0x2732, 0x36bb,
 0xce4c, 0xdfc5, 0xed5e, 0xfcd7, 0x8868, 0x99e1, 0xab7a, 0xbaf3,
 0x5285, 0x430c, 0x7197, 0x601e, 0x14a1, 0x0528, 0x37b3, 0x263a,
 0xdecd, 0xcf44, 0xfddf, 0xec56, 0x98e9, 0x8960, 0xbbfb, 0xaa72,
 0x6306, 0x728f, 0x4014, 0x519d, 0x2522, 0x34ab, 0x0630, 0x17b9,
 0xef4e, 0xfec7, 0xcc5c, 0xddd5, 0xa96a, 0xb8e3, 0x8a78, 0x9bf1,
 0x7387, 0x620e, 0x5095, 0x411c, 0x35a3, 0x242a, 0x16b1, 0x0738,
 0xffcf, 0xee46, 0xdcdd, 0xcd54, 0xb9eb, 0xa862, 0x9af9, 0x8b70,
 0x8408, 0x9581, 0xa71a, 0xb693, 0xc22c, 0xd3a5, 0xe13e, 0xf0b7,
 0x0840, 0x19c9, 0x2b52, 0x3adb, 0x4e64, 0x5fed, 0x6d76, 0x7cff,
 0x9489, 0x8500, 0xb79b, 0xa612, 0xd2ad, 0xc324, 0xf1bf, 0xe036,
 0x18c1, 0x0948, 0x3bd3, 0x2a5a, 0x5ee5, 0x4f6c, 0x7df7, 0x6c7e,
 0xa50a, 0xb483, 0x8618, 0x9791, 0xe32e, 0xf2a7, 0xc03c, 0xd1b5,
 0x2942, 0x38cb, 0x0a50, 0x1bd9, 0x6f66, 0x7eef, 0x4c74, 0x5dfd,
 0xb58b, 0xa402, 0x9699, 0x8710, 0xf3af, 0xe226, 0xd0bd, 0xc134,
 0x39c3, 0x284a, 0x1ad1, 0x0b58, 0x7fe7, 0x6e6e, 0x5cf5, 0x4d7c,
 0xc60c, 0xd785, 0xe51e, 0xf497, 0x8028, 0x91a1, 0xa33a, 0xb2b3,
 0x4a44, 0x5bcd, 0x6956, 0x78df, 0x0c60, 0x1de9, 0x2f72, 0x3efb,
 0xd68d, 0xc704, 0xf59f, 0xe416, 0x90a9, 0x8120, 0xb3bb, 0xa232,
 0x5ac5, 0x4b4c, 0x79d7, 0x685e, 0x1ce1, 0x0d68, 0x3ff3, 0x2e7a,
 0xe70e, 0xf687, 0xc41c, 0xd595, 0xa12a, 0xb0a3, 0x8238, 0x93b1,
 0x6b46, 0x7acf, 0x4854, 0x59dd, 0x2d62, 0x3ceb, 0x0e70, 0x1ff9,
 0xf78f, 0xe606, 0xd49d, 0xc514, 0xb1ab, 0xa022, 0x92b9, 0x8330,
 0x7bc7, 0x6a4e, 0x58d5, 0x495c, 0x3de3, 0x2c6a, 0x1ef1, 0x0f78
};
#endif


/*_____ L O C A L - M A C R O S ______________________________________________*/


/*_____ L O C A L - F U N C T I O N S - P R O T O T Y P E S __________________*/
#ifdef SYST_SOFTRESETCHECK_BEFORE_DEEPSTOP
/*----------------------------------------------------------------------------*/
/* Name : SYST_Config_SoftResetCheck()                                        */
/* Role : Check if the WAKEUP condition are already active before standby mode*/
/*        is started                                                          */
/* Interface : -                                                              */
/* Pre-condition :                                                            */
/* Constraints : -                                                            */
/* Behavior :                                                                 */
/*   DO                                                                       */
/*     [IF ANY wakeup condition is already active, save the wakeup FLAG status*/
/*     in internal BURAM and force reset]                                     */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/
void SYST_Config_SoftResetCheck(void);
#endif

/*_____ G L O B A L - F U N C T I O N S ______________________________________*/
#ifdef __NEC_V850__
/******************************************************************************/
/* Name: SYST_ConfigStartOsTick                                               */
/* Role: Restart Os system tick after sleep                                   */
/* Interface:                                                                 */
/* Preconditions: None                                                        */
/* Constraints: None                                                          */
/******************************************************************************/
void SYST_ConfigStartOsTick(void)
{
  ubyte reg;
  OSTM0TT  = 1; /* stop the timer */
  OSTM0CTL = 0; /* set interval mode w/o initial IRQ */
  OSTM0CMP = osdTimerCompareRegVal;      /* set the reload value */
  OSTM0TS  = 1;                          /* start the timer */

  reg = TARG_ReadByte(ICOSTM0L);
  TARG_WriteByte( ICOSTM0L       , reg & (~INT_MSK_EIMKn));
}

/******************************************************************************/
/* Name: SYST_ConfigStopOsTick                                                */
/* Role: Stop Os system tick before sleep                                     */
/* Interface:                                                                 */
/* Preconditions: None                                                        */
/* Constraints: None                                                          */
/******************************************************************************/
void SYST_ConfigStopOsTick(void)
{
  ubyte reg;
  reg = TARG_ReadByte(ICOSTM0L);
  TARG_WriteByte( ICOSTM0L       , INT_MSK_EIMKn | reg);
  OSTM0TT  = 1; /* stop the timer */
}


/*----------------------------------------------------------------------------*/
/* Name : SYST_ConfigGoIntoStopMode()                                               */
/* Role : Put the REL V850E2/Dx4 in DEEPSTOP mode                             */
/* Interface : -                                                              */
/* Pre-condition :                                                            */
/*     - All interrupts have to be disabled                                   */
/* Constraints : -                                                            */
/*     - All interrupts have to be enabled after this service call            */
/*     - After occurrence of a wake-up event the microcontroller starts       */
/*       with its reset procedure                                             */
/* Behavior :                                                                 */
/*   DO                                                                       */
/*     [Enter ISO1 DEEPSTOP]                                                  */
/*     [Enter ISO0 DEEPSTOP to go into power save mode selected]              */
/*     [Seven nop are inserted to clear the pipeline]                         */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/
#if defined(__REL_V850_DJ4_HE__) || \
    defined(__REL_V850_DK4__) || \
    defined(__REL_V850_DN4H__)
void SYST_ConfigGoIntoStopMode(void)
{
  ulong regValueA02;  /* Clock selector register for A02 domain */
  ulong regValueA07;  /* Clock selector register for A07 domain */
  ulong regValueA09;  /* Clock selector register for A09 domain */
  ulong regValue000;  /* Clock selector register for 000 domain (CPU) */
  volatile ulong regValue;

  WDTD_Refresh();

  /*----------------------*/
  /* DEEPSTOP Preparation */
  /*----------------------*/
  /* STEP 1: Stop interrupt activities and clear interrupt flags */
  __DI();  //DisableAllInterrupts();
  // mask INTP1 (PowerGood signal) external isr
  TARG_WriteByte( ICP6L, TARG_ReadByte(ICP6L) | INT_MSK_EIMKn );
  TARG_WriteByte( ICP6H, 0x00 );
  // mask INTP2 (NERRB signal) external isr
  TARG_WriteByte( ICP2L, TARG_ReadByte(ICP2L) | INT_MSK_EIMKn );
  TARG_WriteByte( ICP2H, 0x00);
  // mask INTP3 (NERRC signal) external isr
  TARG_WriteByte( ICP3L, TARG_ReadByte(ICP3L) | INT_MSK_EIMKn );
  TARG_WriteByte( ICP3H, 0x00);
  /* mask RTC 1sec isr */
/*  TARG_WriteByte( ICRTCA01SL, TARG_ReadByte(ICRTCA01SL) | INT_MSK_EIMKn );
  TARG_WriteByte( ICRTCA01SH, 0x00 );*/

  /* STEP 2: Prepare Iso0 and AWO clocks */

  CPUS_ClockSelectorConfigSleep();

  /* STEP 3: Prepare clock generators */


#ifdef SYST_SOFTRESETCHECK_BEFORE_DEEPSTOP
  /* First Check before turn OFF unessential clock, if some input signal is not on ISO0 CLK*/
  SYST_Config_SoftResetCheck();
#endif
  /* check KL15 before DEEP STOP for ISO1 is started */
  if(IODC_GetInputDataDirect(KL15)  == IODC_ACTIVE) {
    SYST_REBOOT();
    TARG_ProtWriteLong(PROTCMD2, SWRESA, RES_MSK_SWRESA);
  }


  /* STEP 4: Configure wake-up factor */
  TARG_WriteLong(WUFCL0, 0xFFFFFFFF);
  TARG_WriteLong(WUFCM0, 0xFFFFFFFF);
  TARG_WriteLong(WUFCH0, 0xFFFFFFFF);
  TARG_WriteLong(WUFMSKL0, SYST_WUFL);
  TARG_WriteLong(WUFMSKM0, SYST_WUFM);
  TARG_WriteLong(WUFMSKH0, SYST_WUFH);

#if !defined(__REL_V850_DK4__)
  TARG_WriteLong(WUFCL1, 0xFFFFFFFF);
  TARG_WriteLong(WUFCM1, 0xFFFFFFFF);
  TARG_WriteLong(WUFCH1, 0xFFFFFFFF);
  TARG_WriteLong(WUFMSKL1, 0xFFFFFFFF);
  TARG_WriteLong(WUFMSKM1, 0xFFFFFFFF);
  TARG_WriteLong(WUFMSKH1, 0xFFFFFFFF);
#endif

#ifdef RTCC_INTERNAL_RTC
  /* Enable RTCATCKI clock in STOP mode */
  /* TODO: controllare il data sheet per capire se serve */
  regValueA09 = TARG_ReadLong(CKSC_A09);
  if(!(regValueA09 & 0x00000001))
  { /* if STPMK_mn flag not set */
    regValueA09 |= 0x00000001;
    do
    {
      TARG_ProtWriteLong(PROTCMD2, CKSC_A09, regValueA09);
    } while(TARG_ReadLong(PROTS2));
  }
  /* Enable clock for RTCA and WDG when STOP mode is entered */
  /* Change CKSC_Axx register only when STPMK_mn flag is not set */
  regValueA02 = TARG_ReadLong(CKSC_A02);
  if(!(regValueA02 & 0x00000001))
  { /* if STPMK_mn flag not set */
    regValueA02 |= 0x00000001;
    do
    {
      TARG_ProtWriteLong(PROTCMD2, CKSC_A02, regValueA02);
    } while(TARG_ReadLong(PROTS2));
  }
#endif

  /*-----------------------------------*/
  /* DEEPSTOP execution with wait time */
  /*-----------------------------------*/
  /* STEP 5: Set Iso1 DEEPSTOP */
#if !defined(__REL_V850_DK4__)
  TARG_ProtWriteLong(PROTCMD2, PSC0, SBC_MSK_PSCnREGSTP | SBC_MSK_PSCnIOHLDMSK);
  while(!((TARG_ReadLong(PWS1) & SBC_MSK_PWSnPSS) && (TARG_ReadLong(PWS1) & SBC_MSK_PWSnISO)))
  {
    regValue = TARG_ReadLong(PSC1);
    do
    {
      TARG_ProtWriteLong(PROTCMD2, PSC1, (regValue &(~SBC_MSK_PSCnIOHLDMSK)) | (SBC_MSK_PSCnSTP | SBC_MSK_PSCnPOF | SBC_MSK_PSCnREGSTP |SBC_MSK_PSCnIOHLDSET/*| SBC_MSK_PSCnIOHLDMSK*/));
    } while(TARG_ReadLong(PROTS2));
  }
#else
  TARG_ProtWriteLong(PROTCMD1, PSC2, SBC_MSK_PSCnREGSTP | SBC_MSK_PSCnIOHLDMSK);
  while(!((TARG_ReadLong(PWS2) & SBC_MSK_PWSnPSS)))
  {
    regValue = TARG_ReadLong(PSC2);
    do
    {
      TARG_ProtWriteLong(PROTCMD1, PSC2, regValue | (SBC_MSK_PSCnSTP | SBC_MSK_PSCnPOF | SBC_MSK_PSCnREGSTP | SBC_MSK_PSCnIOHLDMSK));
    } while(TARG_ReadLong(PROTS1));
  }

#endif


  /* STEP 6: Stop PLLk */
  /* Make sure that the PLL0 is stopped */
  if (TARG_ReadBitInLong(PLLS0,CLO_BIT_nCLKEN))
  {
    /* Wait for PLL0 enable status bit */
    do {
      regValue = TARG_ReadLong(PLLE0) | CLO_MSK_nDISTRG;
      TARG_ProtWriteLong(PROTCMD2, PLLE0, regValue);
    } while (TARG_ReadBitInLong(PLLS0,CLO_BIT_nCLKEN));
  }
  /* Make sure that the PLL1 is stopped */
  if (TARG_ReadBitInLong(PLLS1,CLO_BIT_nCLKEN))
  {
    /* Wait for PLL1 enable status bit */
    do {
      regValue = TARG_ReadLong(PLLE1) | CLO_MSK_nDISTRG;
      TARG_ProtWriteLong(PROTCMD2, PLLE1, regValue);
    } while (TARG_ReadBitInLong(PLLS1,CLO_BIT_nCLKEN));
  }
#if !defined(__REL_V850_DK4__)
  /* Make sure that the PLL2 is stopped */
  if (TARG_ReadBitInLong(PLLS2,CLO_BIT_nCLKEN))
  {
    /* Wait for PLL2 enable status bit */
    do {
      regValue = TARG_ReadLong(PLLE2) | CLO_MSK_nDISTRG;
      TARG_ProtWriteLong(PROTCMD2, PLLE2, regValue);
    } while (TARG_ReadBitInLong(PLLS2,CLO_BIT_nCLKEN));
  }
#endif
  /* STEP 7: Set Iso0 DEEPSTOP */
  if(WUFL0 == 0
    && WUFM0 == 0
    && WUFH0 == 0 )
  {
    TARG_ProtWriteLong(PROTCMD2, PSC0, SBC_MSK_PSCnSTP | SBC_MSK_PSCnPOF | SBC_MSK_PSCnREGSTP | SBC_MSK_PSCnIOHLDMSK);
    /* wait wakeup event */
    /* Evaluate Stop mode end */
    while (!(TARG_ReadLong(PWS0) & SBC_MSK_PWSnPSS))
    {
      #ifdef SYST_SOFTRESETCHECK_BEFORE_DEEPSTOP
      SYST_Config_SoftResetCheck();
      #endif
      if(!((WUFL0 == 0) && (WUFM0 == 0) && (WUFH0 == 0))) {
        // Wakeup factors detected, force RESET.
        SYST_REBOOT();
        TARG_ProtWriteLong(PROTCMD2, SWRESA, RES_MSK_SWRESA);
      }
      continue;
    }

    // Perform a software reset if early wake-up occurs
    SYST_REBOOT();
    TARG_ProtWriteLong(PROTCMD2, SWRESA, RES_MSK_SWRESA);
  }
  // Wakeup factors detected, force RESET.
  SYST_REBOOT();
  TARG_ProtWriteLong(PROTCMD2, SWRESA, RES_MSK_SWRESA);
}

#ifdef SYST_SOFTRESETCHECK_BEFORE_DEEPSTOP
/*----------------------------------------------------------------------------*/
/* Name : SYST_Config_SoftResetCheck()                                        */
/* Role : Check if the WAKEUP condition are already active before standby mode*/
/*        is started                                                          */
/* Interface : -                                                              */
/* Pre-condition :                                                            */
/* Constraints : -                                                            */
/* Behavior :                                                                 */
/*   DO                                                                       */
/*     [IF ANY wakeup condition is already active, save the wakeup FLAG status*/
/*     in internal BURAM and force reset]                                     */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/
void SYST_Config_SoftResetCheck(void)
{
  volatile ubyte syst_nerrb = IODC_GetInputDataDirect(NERRB);
  volatile ubyte syst_nerrc = IODC_GetInputDataDirect(NERRC);
  volatile ubyte syst_kl15 = IODC_GetInputDataDirect(KL15);
  SYST_WUFLWakeup = 0;

  if( (syst_nerrb  == IODC_INACTIVE)
      || (syst_nerrc == IODC_INACTIVE)
      || (syst_kl15  == IODC_ACTIVE)
  )
  {
    if(syst_nerrb == IODC_INACTIVE)
    {
      SYST_WUFLWakeup |= SYST_WAKEUP_EVENT_INTP2_MASK;
    }
    if(syst_nerrc  == IODC_INACTIVE)
    {
      SYST_WUFLWakeup |= SYST_WAKEUP_EVENT_INTP3_MASK;
    }
    if(syst_kl15 == IODC_ACTIVE)
    {
      SYST_WUFLWakeup |= SYST_WAKEUP_EVENT_INTP8_MASK;
    }
	    /* jump to the APPLI routine */
    SYST_REBOOT();
    TARG_ProtWriteLong(PROTCMD2, SWRESA, RES_MSK_SWRESA);
  }
}
#endif


#endif /* defined(__REL_V850_DJ4_HE__) || \
          defined(__REL_V850_DN4H__) */

#endif /* __NEC_V850__ */

/*_____ L O C A L - F U N C T I O N S ________________________________________*/


/*_____ E N D _____ (syst_config.c) __________________________________________*/
