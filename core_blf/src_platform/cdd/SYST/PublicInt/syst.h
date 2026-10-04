/******************************************************************************/
/* @F_NAME:           syst.h                                                  */
/* @F_PURPOSE:        System standard keywords                                */
/* @F_CREATED_BY:     Vincent RIOUAL                                          */
/* @F_CREATION_DATE:  22/12/2000                                              */
/* @F_LANGUAGE :      C language                                              */
/* @F_MPROC_TYPE:     NEC_V850, MC9S12xx, MC9S08xx, TX49, FSL_IMX53           */
/*                    REL_RL78_D1A, REL_RL78_F12, FSL_IMX6x                   */
/************************************** (C) Copyright 2015 Magneti Marelli ****/

#ifndef SYST_H
#define SYST_H

/*_____ I N C L U D E - F I L E S ____________________________________________*/

/* Definition of NULL macro */
/* (To avoid #include <std lib file> before syst.h in C source file) */
#include <string.h>
#ifdef __NO_OS__
#ifdef __RTOS__
#undef __RTOS__
#endif /* __RTOS__ */

#ifdef __OSEK__
#undef __OSEK__
#endif /* __OSEK__ */

#ifdef __GHOS__
#undef __GHOS__
#endif /* __GHOS__ */
#endif /* __NO_OS__ */

#ifdef __RTOS__
  #include "rtos.h"
#endif /* __RTOS__ */
#ifdef __OSEK__
  #include "osek.h"
#endif /* __OSEK__ */
#ifdef __GHOS__
  #include "ghos.h"
#endif /* __GHOS__ */

#include "type.h"
#if !defined(__PC_SIMULATION__)
#include "targ.h"
#endif

#ifdef __CY_TV2__
#include "syst_TVII.h"
#else

/*_____ G L O B A L - D E F I N E ____________________________________________*/

#define __RH850_F1K__
#ifdef __RH850_F1K__

#define SYST_WUF0  STBC_WUF0WUF0
#define SYST_WUFC0   STBC_WUF0WUFC0
#define SYST_WUFMSK0 STBC_WUF0WUFMSK0

#define SYST_WUF20  STBC_WUF20WUF20
#define SYST_WUFC20 STBC_WUF20WUFC20
#define SYST_WUFMSK20 STBC_WUF20WUFMSK20

#define SYST_WUF_ISO0  STBC_WUFISOWUF_ISO0
#define SYST_WUFC_ISO0 STBC_WUFISOWUFC_ISO0
#define SYST_WUFMSK_ISO0 STBC_WUFISOWUFMSK_ISO0

#endif/*__RH850_F1K__*/


/* Event spy max counter value */
#define SYST_EVT_SPY_MAX_CNT            ((ubyte)0xFCU)
/* Event spy invalid values meanning */
#define SYST_EVT_SPY_GET_INVALID_0      ((ubyte)0xFDU)
#define SYST_EVT_SPY_GET_INVALID_HIGH_0 ((ubyte)0xFEU)
#define SYST_EVT_SPY_SET_INVALID        ((ubyte)0xFFU)

/* ubyte masks */
#define SYST_MSK_BIT0                   ((ubyte)0x01U)
#define SYST_MSK_BIT1                   ((ubyte)0x02U)
#define SYST_MSK_BIT2                   ((ubyte)0x04U)
#define SYST_MSK_BIT3                   ((ubyte)0x08U)
#define SYST_MSK_BIT4                   ((ubyte)0x10U)
#define SYST_MSK_BIT5                   ((ubyte)0x20U)
#define SYST_MSK_BIT6                   ((ubyte)0x40U)
#define SYST_MSK_BIT7                   ((ubyte)0x80U)
#define SYST_MSK_BIT8                   ((ushort)0x100U)
#define SYST_MSK_BIT9                   ((ushort)0x200U)
#define SYST_MSK_BIT10                  ((ushort)0x400U)

#ifdef __PC_SIMULATION__
#define __NOP__
#define asm(x)
#endif /* __PC_SIMULATION__ */

#ifdef C_COMP_IAR_RL78
#define __NOP__  __no_operation()
#endif /* C_COMP_IAR_RL78 */

#if defined (C_COMP_GHS_V850) || defined (C_COMP_GHS_RH850)
#define __NOP__ asm("nop");
#endif /*C_COMP_GHS_V850 || C_COMP_GHS_RH850*/

#ifdef C_COMP_GHS_TX49
#define __NOP__  asm(" nop");
#endif /* C_COMP_GHS_TX49 */

#ifdef C_COMP_COSMIC_MC9S12
#define __NOP__  _asm(" nop");
#endif /* C_COMP_COSMIC_MC9S12 */

#ifdef C_COMP_COSMIC_MC9S08
#define __NOP__  _asm(" nop");
#endif /* C_COMP_COSMIC_MC9S12 */

#ifdef C_COMP_GHS_ARM
#define __NOP__  asm(" nop");
#endif /* C_COMP_GHS_ARM */

#if ! (defined __RTOS__ || defined __OSEK__ || defined __GHOS__)
#define ISR(x) __INTERRUPT__ void x(void)
#endif


#ifdef __TX49__
/* #define SYST_CODE_JMP    to define */
#endif /* __TX49__ */

#ifdef __MC9S12xx__
#define SYST_CODE_JMP   0x06
#endif /* __MC9S12xx__ */

#ifdef __MC9S08xx__
#define SYST_CODE_JMP   0xCC
#endif /* __MC9S08xx__ */

#if defined(__FSL_IMX53x__) || defined(__FSL_IMX6x__)
/* #define SYST_CODE_JMP    to define */
#endif /* __FSL_IMX53x__,__FSL_IMX6x__ */

#ifdef __REL_RL78__
#define SYST_CODE_JMP   0xED
#define SYST_CODE_JMP_LONG   0xECL
#endif /* __REL_RL78__ */

/* compute SW date (BCD -> binaire) */
#define SYST_SW_YEAR   ( (ubyte)( (((Vers_YEAR  >> 4) & 0x0F) * 10) + (Vers_YEAR  & 0x0F) ) )
#define SYST_SW_MONTH  ( (ubyte)( (((Vers_MONTH >> 4) & 0x0F) * 10) + (Vers_MONTH & 0x0F) ) )
#define SYST_SW_DAY    ( (ubyte)( (((Vers_DAY   >> 4) & 0x0F) * 10) + (Vers_DAY   & 0x0F) ) )

/* internal macros to generate week number as defined in ISO-8601 */
/* Julian day in Gregorian calendar                               */
/* see www.tondering.dk/claus/cal/calendar26.html                 */
#define Syst_Week_A   ((14 - SYST_SW_MONTH) / 12)
#define Syst_Week_Y   (SYST_SW_YEAR + 4800 - Syst_Week_A)
#define Syst_Week_M   (SYST_SW_MONTH + (12*Syst_Week_A) - 3)
#define Syst_Week_J   (SYST_SW_DAY + (((153*Syst_Week_M)+2)/5) + ((ulong)365*Syst_Week_Y) + (Syst_Week_Y/4) - (Syst_Week_Y/100) + (Syst_Week_Y/400) - 32045)

#define Syst_Week_D4  ((((Syst_Week_J + 31741 - (Syst_Week_J % 7)) % 146097) % 36524) % 1461)
#define Syst_Week_L   (Syst_Week_D4 / 1460)
#define Syst_Week_D1  (((Syst_Week_D4 - Syst_Week_L) % 365) + Syst_Week_L)

#define SYST_SW_WEEK  ( (ubyte)((Syst_Week_D1 / 7) + 1) )

#define SYST_CCITT_CONSTANT_INV (ushort)0xF0B8


/* Possible values for parameter SwPartIndex of SYST_GetSwPartIdent service */
#define SYST_BL_SW_ID_INDEX        0
#define SYST_FLASHER_SW_ID_INDEX   1
#define SYST_CLIENT_SW_ID_INDEX    2
#define SYST_EOL_SW_ID_INDEX       3


/*_____ G L O B A L - T Y P E S ______________________________________________*/

/* Date */
typedef struct
{
  ubyte   Day;
  ubyte   Month;
  ubyte   Year;
} SYST_Date_t;

/* Factory Lock / Unlock cluster */
typedef enum
{
  SYST_FACTORY_LOCK   = 0x01,
  SYST_FACTORY_UNLOCK = 0xFF
} SYST_FactoryLock_t;

typedef enum
{
  #if defined(__FSL_IMX53x__) || defined(__FSL_IMX6x__)
  SYST_RESET_ALREADY_CONSUMMED,
  #endif /*__FSL_IMX53x__,__FSL_IMX6x__*/
  SYST_POWER_ON = 0,
  SYST_SW_RESET,
  SYST_RESET_WDG,
  #if defined( __MC9S08xx__)  || defined(__NEC_V850__) || defined(__RH850__) || defined(__REL_RL78__)
  SYST_RESET_CLOCK,
  SYST_RESET_LOW_VOLT,
  #endif /* __MC9S08xx__ || __NEC_V850__ || __RH850__|| __REL_RL78__*/
  SYST_RESET_EXT_OR_POWER,
  #if defined( __MC9S08xx__) || defined(__REL_RL78__)
  SYST_RESET_ILLEGAL_OP,
  #endif /* __MC9S08xx__ || __REL_RL78__*/
  #ifdef __REL_RL78__
  SYST_RESET_RAM_PARITY_ERROR,
  SYST_RESET_ILLEGAL_MEMORY_ACCESS,
  #endif /*__REL_RL78__*/
  SYST_WAKE_UP,
  SYST_SYS_RESET,
  SYST_ISO_POWER_FAIL,
  SYST_DEEPSTOP_RESET,
  SYST_RESET_UNKNOW
} SYST_ResetType_t;

#if (defined(__TX49__) || defined(__MC9S12xx__) || defined(__NEC_V850__) || defined(__RH850__) || defined(__FSL_IMX53x__)|| defined(__FSL_IMX6x__) || defined(__REL_RL78__))
typedef ulong SYST_AddressWidth_t;
#endif /* __TX49__ || __MC9S12xx__ || __NEC_V850__ || __RH850__ || __FSL_IMX53x__ ||__REL_RL78__||__FSL_IMX6x_*/

#ifdef __MC9S08xx__
typedef ushort SYST_AddressWidth_t;
#endif /* __MC9S08xx__ */

#ifdef __PC_SIMULATION__
typedef ulong SYST_AddressWidth_t;
#endif

typedef ulong SYST_BootKey_t;
#define  SYST_EOL               ((SYST_BootKey_t) 0x5678U)
#define  SYST_FLASHER           ((SYST_BootKey_t) 0x1234U)
#define  SYST_CLIENT            ((SYST_BootKey_t) 0x9ABCU)
#define  SYST_EOL_COMP          ((SYST_BootKey_t) ~SYST_EOL)
#define  SYST_FLASHER_COMP      ((SYST_BootKey_t) ~SYST_FLASHER)
#define  SYST_CLIENT_COMP       ((SYST_BootKey_t) ~SYST_CLIENT)
#define  SYST_KEY_DEFAULT_VALUE ((SYST_BootKey_t) 0xFFFFU)


#if !defined(__BOOT_LOADER_LINK__)
typedef enum
{
  SYST_IN_PROGRESS = 0,
  SYST_COMPLETE,
  SYST_ERROR
} SYST_Status_t;
#endif /* !__BOOT_LOADER_LINK__ */


typedef ulong SYST_BkpKey_t;
#define SYST_BKP_KEY_VALID      ((SYST_SleepKey_t) 0x1111U)
#define SYST_BKP_KEY_UNVALID    ((SYST_SleepKey_t) 0x1000U)

typedef enum
{
  SYST_BKP_SEC_BOOT = 0,
  SYST_BKP_SEC_BEFORE_INIT,
  SYST_BKP_SEC_SLEEP_BEFORE_INIT,  
  SYST_BKP_SEC_SLEEP_AFTER_INIT,
  SYST_BKP_SEC_NB
} SYST_BkpSecType_t;

typedef enum
{
  SYST_BKP_STORE = 0,
  SYST_BKP_RESTORE
} SYST_BkpAction_t;

typedef struct
{
  ulong* Start;
  ulong* End;
  ulong* Backup;
} Syst_BkpSec_t;

typedef SYST_BkpKey_t SYST_SleepKey_t;
#define SYST_SLEEP              SYST_BKP_KEY_VALID
#define SYST_NO_SLEEP           SYST_BKP_KEY_UNVALID



/* ATTENTION, Do not change : Must be included here because syst_config.h     */
/* requires type definition done above in this file                           */
#include "syst_config.h"
#include "syst_config_eep.h"



/*_____ G L O B A L - D A T A ________________________________________________*/
/* SW identifier : Do not change because section defined in link file */
/* example (due to naming rules for project version) :

 freezed state : version tupi_2.0.3

 Project name = xx  xx  xx  xx  xx xx xx xx xx
                't' 'u' 'p' 'i' 00 FF FF FF FF
 Version      = xx  xx  xx  xx  xx  xx xx xx xx
                '2' '.' '0' '.' '3' 00 FF FF FF

 Type         = xx  xx  xx
                'E' 'U' 00

 working : version ownervir_tupi_2.0

 Project name = xx  xx  xx  xx  xx  xx  xx  xx  xx
                'o' 'w' 'n' 'e' 'r' 'v' 'i' 'r' 00
 Version      = xx  xx  xx  xx  xx xx xx xx xx
                't' 'u' 'p' 'i' 00 FF FF FF FF

note :
  - end string = 0x00
  - missing fields are set to 0xFF due to erasing operation.
*/
#pragma pack(1)
typedef struct
{
  void (*Start)(void);
  ulong AppEndAddress;
  ubyte       ProjectName[8+1]; /* ASCII, string */
  ubyte       Version[8+1];     /* ASCII, string */
  ubyte       Type[2+1];        /* ASCII, string */
  SYST_Date_t Date;             /* BCD           */
  ubyte       Year;             /* Hex           */
  ubyte       Week;             /* Hex           */
#if defined ( DIAG_SERVICE_22F189 )
  ubyte		ECUSWVerNum[3]; /* ASCII, string,Store Diagnosis Service $22 $F1 $89,--VehicleManufacturerECUSoftwareVersionNumber*/
#endif
} SYST_SwIdentifier_t;
#pragma pack()

#if !defined(__GHOS__)

/* --- Boot key RAM statement --- */

#if defined(C_COMP_GHS_TX49) || defined(C_COMP_GHS_V850) || defined(C_COMP_GHS_ARM)
#pragma ghs startdata
#pragma ghs section bss=".BootKeyZone"
/* WARNING : Authors VIR, ALC                                                     */
/*           This .bss or .sbss section will not be cleared by the startup code,  */
/*           in the mapping description section attribute is set to NOCLEAR       */
#endif /* C_COMP_GHS_TX49 || C_COMP_GHS_V850 || C_COMP_GHS_ARM */

#if defined(C_COMP_COSMIC_MC9S12) || defined(C_COMP_COSMIC_MC9S08)
#pragma section [BootKeyZone]
#endif /* C_COMP_COSMIC_MC9S12 || C_COMP_COSMIC_MC9S08 */

#if defined(C_COMP_IAR_RL78)
#pragma dataseg=BootKeyZone
#endif/*C_COMP_IAR_RL78*/

extern SYST_BootKey_t SYST_BOOT_KEY_RAM;
extern SYST_BootKey_t SYST_BOOT_KEY_RAM_COMP;

#if defined(C_COMP_IAR_RL78)
#pragma dataseg=default
#endif/*C_COMP_IAR_RL78*/

#if defined(C_COMP_GHS_TX49) || defined(C_COMP_GHS_V850) || defined(C_COMP_GHS_ARM)
#pragma ghs section bss=default
#pragma ghs enddata
#endif /* C_COMP_GHS_TX49 || C_COMP_GHS_V850 || C_COMP_GHS_ARM */

#if defined(C_COMP_COSMIC_MC9S12) || defined(C_COMP_COSMIC_MC9S08)
#pragma section []
#endif /* C_COMP_COSMIC_MC9S12 || C_COMP_COSMIC_MC9S08 */

#endif /* !__GHOS__ */


/* --- Sleep key statement --- */

#ifdef SYST_DX4_DEEPSTOP_USED
#if defined(C_COMP_GHS_V850) && !defined(__GHOS__)
#pragma ghs startdata
#pragma ghs section bss=".SleepKey"
#endif /* C_COMP_GHS_V850 && !__GHOS__ */

extern SYST_SleepKey_t SYST_SLEEP_KEY_RAM;

#if defined(C_COMP_GHS_V850) && !defined(__GHOS__)
#pragma ghs section bss=default
#pragma ghs enddata
#endif /* C_COMP_GHS_V850 && !__GHOS__ */
#endif /* SYST_DX4_DEEPSTOP_USED */


/* --- SW identifier statement ---*/
#if !defined(__FBL_UPDATER__)
#if defined(C_COMP_GHS_TX49) || defined(C_COMP_GHS_V850) || defined(C_COMP_GHS_ARM)
#pragma ghs startdata
#pragma ghs section rodata=".CONST_SW_ID"
#endif /* C_COMP_GHS_TX49 || C_COMP_GHS_V850 || C_COMP_GHS_ARM */

#if defined(C_COMP_COSMIC_MC9S12) || defined(C_COMP_COSMIC_MC9S08)
#pragma section const {CONST_SW_ID}
#endif /* C_COMP_COSMIC_MC9S12 || C_COMP_COSMIC_MC9S08 */

#if defined(C_COMP_IAR_RL78)
#pragma constseg=CONST_SW_ID
#endif /*C_COMP_IAR_RL78*/

extern const SYST_SwIdentifier_t SYST_SwIdentifier;

#if defined(C_COMP_IAR_RL78)
#pragma constseg=default
#endif /*C_COMP_IAR_RL78*/
#if defined(C_COMP_GHS_TX49) || defined(C_COMP_GHS_V850) || defined(C_COMP_GHS_ARM)
#pragma ghs section rodata=default
#pragma ghs enddata
#endif /* C_COMP_GHS_TX49 || C_COMP_GHS_V850 || C_COMP_GHS_ARM */
#endif/*__FBL_UPDATER__*/

#if defined(C_COMP_COSMIC_MC9S12) || defined(C_COMP_COSMIC_MC9S08)
#pragma section const {}
#endif /* C_COMP_COSMIC_MC9S12 || C_COMP_COSMIC_MC9S08 */


#if !defined(__GHOS__)

/* --- All SW part Ident table statement ---*/

#if defined(C_COMP_GHS_ARM)
#pragma ghs startdata
#pragma ghs section bss=".SwIdentArea"
#endif /* C_COMP_GHS_ARM */

extern SYST_SwIdentifier_t SYST_SwIdentTable[4];

#if defined(C_COMP_GHS_ARM)
#pragma ghs section bss=default
#pragma ghs enddata
#endif /* C_COMP_GHS_ARM */

#endif /* !__GHOS__ */


/*_____ I N C L U D E - F I L E - F O R - S Y S T E M - D E F I N I T I O N __*/

#ifdef __REL_V850_Dx4__

#ifdef SYST_WAKEUP_EVENT_NMI
#define SYST_WAKEUP_EVENT_NMI_MASK         ((ulong)0x00000001)
#else
#define SYST_WAKEUP_EVENT_NMI_MASK         ((ulong)0x00000000)
#endif

#ifdef SYST_WAKEUP_EVENT_INTWDTA0
#define SYST_WAKEUP_EVENT_INTWDTA0_MASK    ((ulong)0x00000002)
#else
#define SYST_WAKEUP_EVENT_INTWDTA0_MASK    ((ulong)0x00000000)
#endif

#ifdef SYST_WAKEUP_EVENT_INTLVI
#define SYST_WAKEUP_EVENT_INTLVI_MASK      ((ulong)0x00000004)
#else
#define SYST_WAKEUP_EVENT_INTLVI_MASK      ((ulong)0x00000000)
#endif

#ifdef SYST_WAKEUP_EVENT_INTRTCA0AL
#define SYST_WAKEUP_EVENT_INTRTCA0AL_MASK  ((ulong)0x00000010)
#else
#define SYST_WAKEUP_EVENT_INTRTCA0AL_MASK  ((ulong)0x00000000)
#endif

#ifdef SYST_WAKEUP_EVENT_INTRTCA0R
#define SYST_WAKEUP_EVENT_INTRTCA0R_MASK   ((ulong)0x00000020)
#else
#define SYST_WAKEUP_EVENT_INTRTCA0R_MASK   ((ulong)0x00000000)
#endif

#ifdef SYST_WAKEUP_EVENT_INTRTCA01S
#define SYST_WAKEUP_EVENT_INTRTCA01S_MASK  ((ulong)0x00000040)
#else
#define SYST_WAKEUP_EVENT_INTRTCA01S_MASK  ((ulong)0x00000000)
#endif

#ifdef SYST_WAKEUP_EVENT_INTP0
#define SYST_WAKEUP_EVENT_INTP0_MASK       ((ulong)0x00000080)
#else
#define SYST_WAKEUP_EVENT_INTP0_MASK       ((ulong)0x00000000)
#endif

#ifdef SYST_WAKEUP_EVENT_INTP1
#define SYST_WAKEUP_EVENT_INTP1_MASK       ((ulong)0x00000100)
#else
#define SYST_WAKEUP_EVENT_INTP1_MASK       ((ulong)0x00000000)
#endif

#ifdef SYST_WAKEUP_EVENT_INTP2
#define SYST_WAKEUP_EVENT_INTP2_MASK       ((ulong)0x00000200)
#else
#define SYST_WAKEUP_EVENT_INTP2_MASK       ((ulong)0x00000000)
#endif

#ifdef SYST_WAKEUP_EVENT_INTP3
#define SYST_WAKEUP_EVENT_INTP3_MASK       ((ulong)0x00000400)
#else
#define SYST_WAKEUP_EVENT_INTP3_MASK       ((ulong)0x00000000)
#endif

#ifdef SYST_WAKEUP_EVENT_INTP4
#define SYST_WAKEUP_EVENT_INTP4_MASK       ((ulong)0x00000800)
#else
#define SYST_WAKEUP_EVENT_INTP4_MASK       ((ulong)0x00000000)
#endif

#ifdef SYST_WAKEUP_EVENT_INTP5
#define SYST_WAKEUP_EVENT_INTP5_MASK       ((ulong)0x00001000)
#else
#define SYST_WAKEUP_EVENT_INTP5_MASK       ((ulong)0x00000000)
#endif

#ifdef SYST_WAKEUP_EVENT_INTP6
#define SYST_WAKEUP_EVENT_INTP6_MASK       ((ulong)0x00002000)
#else
#define SYST_WAKEUP_EVENT_INTP6_MASK       ((ulong)0x00000000)
#endif

#ifdef SYST_WAKEUP_EVENT_INTP7
#define SYST_WAKEUP_EVENT_INTP7_MASK       ((ulong)0x00004000)
#else
#define SYST_WAKEUP_EVENT_INTP7_MASK       ((ulong)0x00000000)
#endif

#ifdef SYST_WAKEUP_EVENT_INTP8
#define SYST_WAKEUP_EVENT_INTP8_MASK       ((ulong)0x00008000)
#else
#define SYST_WAKEUP_EVENT_INTP8_MASK       ((ulong)0x00000000)
#endif

#ifdef SYST_WAKEUP_EVENT_INTP9
#define SYST_WAKEUP_EVENT_INTP9_MASK       ((ulong)0x00010000)
#else
#define SYST_WAKEUP_EVENT_INTP9_MASK       ((ulong)0x00000000)
#endif

#ifdef SYST_WAKEUP_EVENT_INTP10
#define SYST_WAKEUP_EVENT_INTP10_MASK      ((ulong)0x00020000)
#else
#define SYST_WAKEUP_EVENT_INTP10_MASK      ((ulong)0x00000000)
#endif

#ifdef SYST_WAKEUP_EVENT_FCN0RX
#define SYST_WAKEUP_EVENT_FCN0RX_MASK      ((ulong)0x00800000)
#else
#define SYST_WAKEUP_EVENT_FCN0RX_MASK      ((ulong)0x00000000)
#endif

#ifdef SYST_WAKEUP_EVENT_FCN1RX
#define SYST_WAKEUP_EVENT_FCN1RX_MASK      ((ulong)0x01000000)
#else
#define SYST_WAKEUP_EVENT_FCN1RX_MASK      ((ulong)0x00000000)
#endif

#ifdef SYST_WAKEUP_EVENT_FCN2RX
#define SYST_WAKEUP_EVENT_FCN2RX_MASK      ((ulong)0x02000000)
#else
#define SYST_WAKEUP_EVENT_FCN2RX_MASK      ((ulong)0x00000000)
#endif

#ifdef SYST_WAKEUP_EVENT_INTCLMA0
#define SYST_WAKEUP_EVENT_INTCLMA0_MASK    ((ulong)0x20000000)
#else
#define SYST_WAKEUP_EVENT_INTCLMA0_MASK    ((ulong)0x00000000)
#endif

#ifdef SYST_WAKEUP_EVENT_INTCLMA1
#define SYST_WAKEUP_EVENT_INTCLMA1_MASK    ((ulong)0x40000000)
#else
#define SYST_WAKEUP_EVENT_INTCLMA1_MASK    ((ulong)0x00000000)
#endif

#ifdef SYST_WAKEUP_EVENT_INTCLMA2
#define SYST_WAKEUP_EVENT_INTCLMA2_MASK    ((ulong)0x80000000)
#else
#define SYST_WAKEUP_EVENT_INTCLMA2_MASK    ((ulong)0x00000000)
#endif

#define SYST_WUFL ~((ulong)0x00000000 |\
                    SYST_WAKEUP_EVENT_INTLVI_MASK |\
                    SYST_WAKEUP_EVENT_INTRTCA0AL_MASK |\
                    SYST_WAKEUP_EVENT_INTRTCA0R_MASK |\
                    SYST_WAKEUP_EVENT_INTRTCA01S_MASK |\
                    SYST_WAKEUP_EVENT_INTP0_MASK |\
                    SYST_WAKEUP_EVENT_INTP1_MASK |\
                    SYST_WAKEUP_EVENT_INTP2_MASK |\
                    SYST_WAKEUP_EVENT_INTP3_MASK |\
                    SYST_WAKEUP_EVENT_INTP4_MASK |\
                    SYST_WAKEUP_EVENT_INTP5_MASK |\
                    SYST_WAKEUP_EVENT_INTP6_MASK |\
                    SYST_WAKEUP_EVENT_INTP7_MASK |\
                    SYST_WAKEUP_EVENT_INTP8_MASK |\
                    SYST_WAKEUP_EVENT_INTP9_MASK |\
                    SYST_WAKEUP_EVENT_INTP10_MASK |\
                    SYST_WAKEUP_EVENT_FCN0RX_MASK |\
                    SYST_WAKEUP_EVENT_FCN1RX_MASK |\
                    SYST_WAKEUP_EVENT_FCN2RX_MASK |\
                    SYST_WAKEUP_EVENT_INTCLMA0_MASK |\
                    SYST_WAKEUP_EVENT_INTCLMA1_MASK |\
                    SYST_WAKEUP_EVENT_INTCLMA2_MASK )

#ifdef SYST_WAKEUP_EVENT_INTVCPC0
#define SYST_WAKEUP_EVENT_INTVCPC0_MASK    ((ulong)0x00000001)
#else
#define SYST_WAKEUP_EVENT_INTVCPC0_MASK    ((ulong)0x00000000)
#endif

#ifdef SYST_WAKEUP_EVENT_INTVCPC1
#define SYST_WAKEUP_EVENT_INTVCPC1_MASK    ((ulong)0x00000002)
#else
#define SYST_WAKEUP_EVENT_INTVCPC1_MASK    ((ulong)0x00000000)
#endif

#ifdef SYST_WAKEUP_EVENT_INTTAUJ0I0
#define SYST_WAKEUP_EVENT_INTTAUJ0I0_MASK  ((ulong)0x00000004)
#else
#define SYST_WAKEUP_EVENT_INTTAUJ0I0_MASK  ((ulong)0x00000000)
#endif

#ifdef SYST_WAKEUP_EVENT_INTTAUJ0I1
#define SYST_WAKEUP_EVENT_INTTAUJ0I1_MASK  ((ulong)0x00000008)
#else
#define SYST_WAKEUP_EVENT_INTTAUJ0I1_MASK  ((ulong)0x00000000)
#endif

#ifdef SYST_WAKEUP_EVENT_INTTAUJ0I2
#define SYST_WAKEUP_EVENT_INTTAUJ0I2_MASK  ((ulong)0x00000010)
#else
#define SYST_WAKEUP_EVENT_INTTAUJ0I2_MASK  ((ulong)0x00000000)
#endif

#ifdef SYST_WAKEUP_EVENT_INTTAUJ0I3
#define SYST_WAKEUP_EVENT_INTTAUJ0I3_MASK  ((ulong)0x00000020)
#else
#define SYST_WAKEUP_EVENT_INTTAUJ0I3_MASK  ((ulong)0x00000000)
#endif

#ifdef SYST_WAKEUP_EVENT_INTTAUJ1I0
#define SYST_WAKEUP_EVENT_INTTAUJ1I0_MASK  ((ulong)0x00000040)
#else
#define SYST_WAKEUP_EVENT_INTTAUJ1I0_MASK  ((ulong)0x00000000)
#endif

#ifdef SYST_WAKEUP_EVENT_INTTAUJ1I1
#define SYST_WAKEUP_EVENT_INTTAUJ1I1_MASK  ((ulong)0x00000080)
#else
#define SYST_WAKEUP_EVENT_INTTAUJ1I1_MASK  ((ulong)0x00000000)
#endif

#ifdef SYST_WAKEUP_EVENT_INTTAUJ1I2
#define SYST_WAKEUP_EVENT_INTTAUJ1I2_MASK  ((ulong)0x00000100)
#else
#define SYST_WAKEUP_EVENT_INTTAUJ1I2_MASK  ((ulong)0x00000000)
#endif

#ifdef SYST_WAKEUP_EVENT_INTTAUJ1I3
#define SYST_WAKEUP_EVENT_INTTAUJ1I3_MASK  ((ulong)0x00000200)
#else
#define SYST_WAKEUP_EVENT_INTTAUJ1I3_MASK  ((ulong)0x00000000)
#endif

#ifdef SYST_WAKEUP_EVENT_INTADCA0ERR
#define SYST_WAKEUP_EVENT_INTADCA0ERR_MASK ((ulong)0x00000400)
#else
#define SYST_WAKEUP_EVENT_INTADCA0ERR_MASK ((ulong)0x00000000)
#endif

#ifdef SYST_WAKEUP_EVENT_INTADCA0I0
#define SYST_WAKEUP_EVENT_INTADCA0I0_MASK  ((ulong)0x00000800)
#else
#define SYST_WAKEUP_EVENT_INTADCA0I0_MASK  ((ulong)0x00000000)
#endif

#ifdef SYST_WAKEUP_EVENT_INTADCA0I1
#define SYST_WAKEUP_EVENT_INTADCA0I1_MASK  ((ulong)0x00001000)
#else
#define SYST_WAKEUP_EVENT_INTADCA0I1_MASK  ((ulong)0x00000000)
#endif

#ifdef SYST_WAKEUP_EVENT_INTADcA0I2
#define SYST_WAKEUP_EVENT_INTADcA0I2_MASK  ((ulong)0x00002000)
#else
#define SYST_WAKEUP_EVENT_INTADcA0I2_MASK  ((ulong)0x00000000)
#endif

#ifdef SYST_WAKEUP_EVENT_INTADCA0LLT
#define SYST_WAKEUP_EVENT_INTADCA0LLT_MASK ((ulong)0x00004000)
#else
#define SYST_WAKEUP_EVENT_INTADCA0LLT_MASK ((ulong)0x00000000)
#endif

#ifdef SYST_WAKEUP_EVENT_INTWDTA1
#define SYST_WAKEUP_EVENT_INTWDTA1_MASK    ((ulong)0x00008000)
#else
#define SYST_WAKEUP_EVENT_INTWDTA1_MASK    ((ulong)0x00000000)
#endif

#ifdef SYST_WAKEUP_EVENT_INTCLMA3
#define SYST_WAKEUP_EVENT_INTCLMA3_MASK    ((ulong)0x00010000)
#else
#define SYST_WAKEUP_EVENT_INTCLMA3_MASK    ((ulong)0x00000000)
#endif

#ifdef SYST_WAKEUP_EVENT_INTTAUA0I0
#define SYST_WAKEUP_EVENT_INTTAUA0I0_MASK  ((ulong)0x20000000)
#else
#define SYST_WAKEUP_EVENT_INTTAUA0I0_MASK  ((ulong)0x00000000)
#endif

#ifdef SYST_WAKEUP_EVENT_INTTAUA0I1
#define SYST_WAKEUP_EVENT_INTTAUA0I1_MASK  ((ulong)0x40000000)
#else
#define SYST_WAKEUP_EVENT_INTTAUA0I1_MASK  ((ulong)0x00000000)
#endif

#ifdef SYST_WAKEUP_EVENT_INTTAUA0I2
#define SYST_WAKEUP_EVENT_INTTAUA0I2_MASK  ((ulong)0x80000000)
#else
#define SYST_WAKEUP_EVENT_INTTAUA0I2_MASK  ((ulong)0x00000000)
#endif

#define SYST_WUFM ~((ulong)0x00000000 |\
                    SYST_WAKEUP_EVENT_INTVCPC0_MASK |\
                    SYST_WAKEUP_EVENT_INTVCPC1_MASK |\
                    SYST_WAKEUP_EVENT_INTTAUJ0I0_MASK |\
                    SYST_WAKEUP_EVENT_INTTAUJ0I1_MASK |\
                    SYST_WAKEUP_EVENT_INTTAUJ0I2_MASK |\
                    SYST_WAKEUP_EVENT_INTTAUJ0I3_MASK |\
                    SYST_WAKEUP_EVENT_INTTAUJ1I0_MASK |\
                    SYST_WAKEUP_EVENT_INTTAUJ1I1_MASK |\
                    SYST_WAKEUP_EVENT_INTTAUJ1I2_MASK |\
                    SYST_WAKEUP_EVENT_INTTAUJ1I3_MASK |\
                    SYST_WAKEUP_EVENT_INTADCA0ERR_MASK |\
                    SYST_WAKEUP_EVENT_INTADCA0I0_MASK |\
                    SYST_WAKEUP_EVENT_INTADCA0I1_MASK |\
                    SYST_WAKEUP_EVENT_INTADcA0I2_MASK |\
                    SYST_WAKEUP_EVENT_INTADCA0LLT_MASK |\
                    SYST_WAKEUP_EVENT_INTWDTA1_MASK |\
                    SYST_WAKEUP_EVENT_INTCLMA3_MASK |\
                    SYST_WAKEUP_EVENT_INTTAUA0I0_MASK |\
                    SYST_WAKEUP_EVENT_INTTAUA0I1_MASK |\
                    SYST_WAKEUP_EVENT_INTTAUA0I2_MASK)

#ifdef SYST_WAKEUP_EVENT_INTTAUA0I3
#define SYST_WAKEUP_EVENT_INTTAUA0I3_MASK  ((ulong)0x00000001)
#else
#define SYST_WAKEUP_EVENT_INTTAUA0I3_MASK  ((ulong)0x00000000)
#endif

#ifdef SYST_WAKEUP_EVENT_INTTAUA0I4
#define SYST_WAKEUP_EVENT_INTTAUA0I4_MASK  ((ulong)0x00000002)
#else
#define SYST_WAKEUP_EVENT_INTTAUA0I4_MASK  ((ulong)0x00000000)
#endif

#ifdef SYST_WAKEUP_EVENT_INTTAUA0I5
#define SYST_WAKEUP_EVENT_INTTAUA0I5_MASK  ((ulong)0x00000004)
#else
#define SYST_WAKEUP_EVENT_INTTAUA0I5_MASK  ((ulong)0x00000000)
#endif

#ifdef SYST_WAKEUP_EVENT_INTTAUA0I6
#define SYST_WAKEUP_EVENT_INTTAUA0I6_MASK  ((ulong)0x00000008)
#else
#define SYST_WAKEUP_EVENT_INTTAUA0I6_MASK  ((ulong)0x00000000)
#endif

#ifdef SYST_WAKEUP_EVENT_INTTAUA0I7
#define SYST_WAKEUP_EVENT_INTTAUA0I7_MASK  ((ulong)0x00000010)
#else
#define SYST_WAKEUP_EVENT_INTTAUA0I7_MASK  ((ulong)0x00000000)
#endif

#ifdef SYST_WAKEUP_EVENT_INTTAUA0I8
#define SYST_WAKEUP_EVENT_INTTAUA0I8_MASK  ((ulong)0x00000020)
#else
#define SYST_WAKEUP_EVENT_INTTAUA0I8_MASK  ((ulong)0x00000000)
#endif

#ifdef SYST_WAKEUP_EVENT_INTTAUA0I9
#define SYST_WAKEUP_EVENT_INTTAUA0I9_MASK  ((ulong)0x00000040)
#else
#define SYST_WAKEUP_EVENT_INTTAUA0I9_MASK  ((ulong)0x00000000)
#endif

#ifdef SYST_WAKEUP_EVENT_INTTAUA0I10
#define SYST_WAKEUP_EVENT_INTTAUA0I10_MASK ((ulong)0x00000080)
#else
#define SYST_WAKEUP_EVENT_INTTAUA0I10_MASK ((ulong)0x00000000)
#endif

#ifdef SYST_WAKEUP_EVENT_INTTAUA0I11
#define SYST_WAKEUP_EVENT_INTTAUA0I11_MASK ((ulong)0x00000100)
#else
#define SYST_WAKEUP_EVENT_INTTAUA0I11_MASK ((ulong)0x00000000)
#endif

#ifdef SYST_WAKEUP_EVENT_INTTAUA0I12
#define SYST_WAKEUP_EVENT_INTTAUA0I12_MASK ((ulong)0x00000200)
#else
#define SYST_WAKEUP_EVENT_INTTAUA0I12_MASK ((ulong)0x00000000)
#endif

#ifdef SYST_WAKEUP_EVENT_INTTAUA0I13
#define SYST_WAKEUP_EVENT_INTTAUA0I13_MASK ((ulong)0x00000400)
#else
#define SYST_WAKEUP_EVENT_INTTAUA0I13_MASK ((ulong)0x00000000)
#endif

#ifdef SYST_WAKEUP_EVENT_INTTAUA0I14
#define SYST_WAKEUP_EVENT_INTTAUA0I14_MASK ((ulong)0x00000800)
#else
#define SYST_WAKEUP_EVENT_INTTAUA0I14_MASK ((ulong)0x00000000)
#endif

#ifdef SYST_WAKEUP_EVENT_INTTAUA0I15
#define SYST_WAKEUP_EVENT_INTTAUA0I15_MASK ((ulong)0x00001000)
#else
#define SYST_WAKEUP_EVENT_INTTAUA0I15_MASK ((ulong)0x00000000)
#endif

#ifdef SYST_WAKEUP_EVENT_WDTA0NMI
#define SYST_WAKEUP_EVENT_WDTA0NMI_MASK    ((ulong)0x00002000)
#else
#define SYST_WAKEUP_EVENT_WDTA0NMI_MASK    ((ulong)0x00000000)
#endif

#ifdef SYST_WAKEUP_EVENT_WDTA1NMI
#define SYST_WAKEUP_EVENT_WDTA1NMI_MASK    ((ulong)0x00004000)
#else
#define SYST_WAKEUP_EVENT_WDTA1NMI_MASK    ((ulong)0x00000000)
#endif

#ifdef SYST_WAKEUP_EVENT_OCDSTPRQ
#define SYST_WAKEUP_EVENT_OCDSTPRQ_MASK    ((ulong)0x00008000)
#else
#define SYST_WAKEUP_EVENT_OCDSTPRQ_MASK    ((ulong)0x00000000)
#endif

#define SYST_WUFH ~((ulong)0x00000000 |\
                    SYST_WAKEUP_EVENT_INTTAUA0I3_MASK |\
                    SYST_WAKEUP_EVENT_INTTAUA0I4_MASK |\
                    SYST_WAKEUP_EVENT_INTTAUA0I5_MASK |\
                    SYST_WAKEUP_EVENT_INTTAUA0I6_MASK |\
                    SYST_WAKEUP_EVENT_INTTAUA0I7_MASK |\
                    SYST_WAKEUP_EVENT_INTTAUA0I8_MASK |\
                    SYST_WAKEUP_EVENT_INTTAUA0I9_MASK |\
                    SYST_WAKEUP_EVENT_INTTAUA0I10_MASK |\
                    SYST_WAKEUP_EVENT_INTTAUA0I11_MASK |\
                    SYST_WAKEUP_EVENT_INTTAUA0I12_MASK |\
                    SYST_WAKEUP_EVENT_INTTAUA0I13_MASK |\
                    SYST_WAKEUP_EVENT_INTTAUA0I14_MASK |\
                    SYST_WAKEUP_EVENT_INTTAUA0I15_MASK |\
                    SYST_WAKEUP_EVENT_WDTA0NMI_MASK |\
                    SYST_WAKEUP_EVENT_WDTA1NMI_MASK |\
                    SYST_WAKEUP_EVENT_OCDSTPRQ_MASK)
#endif /* __REL_V850_Dx4__*/



#ifdef __RH850_F1x__
#ifdef __RH850_F1K__

#ifdef SYST_WAKEUP_EVENT_NMI
#define SYST_WAKEUP_EVENT_NMI_MASK_F1K         ((ulong)0x00000001)
#else
#define SYST_WAKEUP_EVENT_NMI_MASK_F1K         ((ulong)0x00000000)
#endif

#ifdef SYST_WAKEUP_EVENT_WDTA0NMI
#define SYST_WAKEUP_EVENT_WDTA0NMI_MASK_F1K    ((ulong)0x00000002)
#else
#define SYST_WAKEUP_EVENT_WDTA0NMI_MASK_F1K    ((ulong)0x00000000)
#endif

#ifdef SYST_WAKEUP_EVENT_INTLVIL
#define SYST_WAKEUP_EVENT_INTLVIL_MASK_F1K      ((ulong)0x00000004)
#else
#define SYST_WAKEUP_EVENT_INTLVIL_MASK_F1K      ((ulong)0x00000000)
#endif

#ifdef SYST_WAKEUP_EVENT_INTP0
#define SYST_WAKEUP_EVENT_INTP0_MASK_F1K       ((ulong)0x00000020)
#else
#define SYST_WAKEUP_EVENT_INTP0_MASK_F1K      ((ulong)0x00000000)
#endif

#ifdef SYST_WAKEUP_EVENT_INTP1
#define SYST_WAKEUP_EVENT_INTP1_MASK_F1K       ((ulong)0x00000040)
#else
#define SYST_WAKEUP_EVENT_INTP1_MASK_F1K       ((ulong)0x00000000)
#endif

#ifdef SYST_WAKEUP_EVENT_INTP2
#define SYST_WAKEUP_EVENT_INTP2_MASK_F1K       ((ulong)0x00000080)
#else
#define SYST_WAKEUP_EVENT_INTP2_MASK_F1K       ((ulong)0x00000000)
#endif

#ifdef SYST_WAKEUP_EVENT_INTWDTA0
#define SYST_WAKEUP_EVENT_INTWDTA0_MASK_F1K       ((ulong)0x00000100)
#else
#define SYST_WAKEUP_EVENT_INTWDTA0_MASK_F1K       ((ulong)0x00000000)
#endif

#ifdef SYST_WAKEUP_EVENT_INTP3
#define SYST_WAKEUP_EVENT_INTP3_MASK_F1K       ((ulong)0x00000200)
#else
#define SYST_WAKEUP_EVENT_INTP3_MASK_F1K       ((ulong)0x00000000)
#endif

#ifdef SYST_WAKEUP_EVENT_INTP4
#define SYST_WAKEUP_EVENT_INTP4_MASK_F1K       ((ulong)0x00000400)
#else
#define SYST_WAKEUP_EVENT_INTP4_MASK_F1K       ((ulong)0x00000000)
#endif

#ifdef SYST_WAKEUP_EVENT_INTP5
#define SYST_WAKEUP_EVENT_INTP5_MASK_F1K       ((ulong)0x0000800)
#else
#define SYST_WAKEUP_EVENT_INTP5_MASK_F1K       ((ulong)0x00000000)
#endif

#ifdef SYST_WAKEUP_EVENT_INTP10
#define SYST_WAKEUP_EVENT_INTP10_MASK_F1K       ((ulong)0x00001000)
#else
#define SYST_WAKEUP_EVENT_INTP10_MASK_F1K       ((ulong)0x00000000)
#endif

#ifdef SYST_WAKEUP_EVENT_INTP11
#define SYST_WAKEUP_EVENT_INTP11_MASK_F1K       ((ulong)0x00002000)
#else
#define SYST_WAKEUP_EVENT_INTP11_MASK_F1K       ((ulong)0x00000000)
#endif

#ifdef SYST_WAKEUP_EVENT_WUTRG1
#define SYST_WAKEUP_EVENT_WUTRG1_MASK_F1K       ((ulong)0x00004000)
#else
#define SYST_WAKEUP_EVENT_WUTRG1_MASK_F1K       ((ulong)0x00000000)
#endif

#ifdef SYST_WAKEUP_EVENT_INTTAUJ0I0
#define SYST_WAKEUP_EVENT_INTTAUJ0I0_MASK_F1K       ((ulong)0x00008000)
#else
#define SYST_WAKEUP_EVENT_INTTAUJ0I0_MASK_F1K       ((ulong)0x00000000)
#endif

#ifdef SYST_WAKEUP_EVENT_INTTAUJ0I1
#define SYST_WAKEUP_EVENT_INTTAUJ0I1_MASK_F1K       ((ulong)0x00010000)
#else
#define SYST_WAKEUP_EVENT_INTTAUJ0I1_MASK_F1K       ((ulong)0x00000000)
#endif

#ifdef SYST_WAKEUP_EVENT_INTTAUJ0I2
#define SYST_WAKEUP_EVENT_INTTAUJ0I2_MASK_F1K       ((ulong)0x00020000)
#else
#define SYST_WAKEUP_EVENT_INTTAUJ0I2_MASK_F1K       ((ulong)0x00000000)
#endif

#ifdef SYST_WAKEUP_EVENT_INTTAUJ0I3
#define SYST_WAKEUP_EVENT_INTTAUJ0I3_MASK_F1K       ((ulong)0x00040000)
#else
#define SYST_WAKEUP_EVENT_INTTAUJ0I3_MASK_F1K       ((ulong)0x00000000)
#endif

#ifdef SYST_WAKEUP_EVENT_WUTRG0
#define SYST_WAKEUP_EVENT_WUTRG0_MASK_F1K       ((ulong)0x00080000)
#else
#define SYST_WAKEUP_EVENT_WUTRG0_MASK_F1K       ((ulong)0x00000000)
#endif

#ifdef SYST_WAKEUP_EVENT_INTP6
#define SYST_WAKEUP_EVENT_INTP6_MASK_F1K       ((ulong)0x00100000)
#else
#define SYST_WAKEUP_EVENT_INTP6_MASK_F1K       ((ulong)0x00000000)
#endif

#ifdef SYST_WAKEUP_EVENT_INTP7
#define SYST_WAKEUP_EVENT_INTP7_MASK_F1K       ((ulong)0x00200000)
#else
#define SYST_WAKEUP_EVENT_INTP7_MASK_F1K       ((ulong)0x00000000)
#endif

#ifdef SYST_WAKEUP_EVENT_INTP8
#define SYST_WAKEUP_EVENT_INTP8_MASK_F1K       ((ulong)0x00400000)
#else
#define SYST_WAKEUP_EVENT_INTP8_MASK_F1K       ((ulong)0x00000000)
#endif

#ifdef SYST_WAKEUP_EVENT_INTP12
#define SYST_WAKEUP_EVENT_INTP12_MASK_F1K      ((ulong)0x00800000)
#else
#define SYST_WAKEUP_EVENT_INTP12_MASK_F1K      ((ulong)0x00000000)
#endif

#ifdef SYST_WAKEUP_EVENT_INTP9
#define SYST_WAKEUP_EVENT_INTP9_MASK_F1K       ((ulong)0x01000000)
#else
#define SYST_WAKEUP_EVENT_INTP9_MASK_F1K       ((ulong)0x00000000)
#endif

#ifdef SYST_WAKEUP_EVENT_INTP13
#define SYST_WAKEUP_EVENT_INTP13_MASK_F1K      ((ulong)0x02000000)
#else
#define SYST_WAKEUP_EVENT_INTP13_MASK_F1K      ((ulong)0x00000000)
#endif

#ifdef SYST_WAKEUP_EVENT_INTP14
#define SYST_WAKEUP_EVENT_INTP14_MASK_F1K      ((ulong)0x04000000)
#else
#define SYST_WAKEUP_EVENT_INTP14_MASK_F1K      ((ulong)0x00000000)
#endif

#ifdef SYST_WAKEUP_EVENT_INTP15
#define SYST_WAKEUP_EVENT_INTP15_MASK_F1K      ((ulong)0x08000000)
#else
#define SYST_WAKEUP_EVENT_INTP15_MASK_F1K      ((ulong)0x00000000)
#endif

#ifdef SYST_WAKEUP_EVENT_INTRTCA01S
#define SYST_WAKEUP_EVENT_INTRTCA01S_MASK_F1K      ((ulong)0x10000000)
#else
#define SYST_WAKEUP_EVENT_INTRTCA01S_MASK_F1K      ((ulong)0x00000000)
#endif

#ifdef SYST_WAKEUP_EVENT_INTRTCA0AL
#define SYST_WAKEUP_EVENT_INTRTCA0AL_MASK_F1K      ((ulong)0x20000000)
#else
#define SYST_WAKEUP_EVENT_INTRTCA0AL_MASK_F1K      ((ulong)0x00000000)
#endif

#ifdef SYST_WAKEUP_EVENT_INTRTCA0R
#define SYST_WAKEUP_EVENT_INTRTCA0R_MASK_F1K      ((ulong)0x40000000)
#else
#define SYST_WAKEUP_EVENT_INTRTCA0R_MASK_F1K      ((ulong)0x00000000)
#endif

#ifdef SYST_WAKEUP_EVENT_INTDCUTDI
#define SYST_WAKEUP_EVENT_INTDCUTDI_MASK_F1K      ((ulong)0x80000000)
#else
#define SYST_WAKEUP_EVENT_INTDCUTDI_MASK_F1K      ((ulong)0x00000000)
#endif

#define SYST_WUF0_FACTOR_1   ~((ulong)0x00000000 |\
                    SYST_WAKEUP_EVENT_NMI_MASK_F1K |\
                    SYST_WAKEUP_EVENT_WDTA0NMI_MASK_F1K |\
                    SYST_WAKEUP_EVENT_INTLVIL_MASK_F1K |\
                    SYST_WAKEUP_EVENT_INTP0_MASK_F1K |\
                    SYST_WAKEUP_EVENT_INTP1_MASK_F1K |\
                    SYST_WAKEUP_EVENT_INTP2_MASK_F1K |\
                    SYST_WAKEUP_EVENT_INTWDTA0_MASK_F1K |\
                    SYST_WAKEUP_EVENT_INTP3_MASK_F1K  |\
                    SYST_WAKEUP_EVENT_INTP4_MASK_F1K  |\
                    SYST_WAKEUP_EVENT_INTP5_MASK_F1K  |\
                    SYST_WAKEUP_EVENT_INTP10_MASK_F1K |\
                    SYST_WAKEUP_EVENT_INTP11_MASK_F1K |\
                    SYST_WAKEUP_EVENT_WUTRG1_MASK_F1K |\
                    SYST_WAKEUP_EVENT_INTTAUJ0I0_MASK_F1K |\
                    SYST_WAKEUP_EVENT_INTTAUJ0I1_MASK_F1K |\
                    SYST_WAKEUP_EVENT_INTTAUJ0I2_MASK_F1K |\
                    SYST_WAKEUP_EVENT_INTTAUJ0I3_MASK_F1K |\
                    SYST_WAKEUP_EVENT_WUTRG0_MASK_F1K |\
                    SYST_WAKEUP_EVENT_INTP6_MASK_F1K |\
                    SYST_WAKEUP_EVENT_INTP7_MASK_F1K |\
                    SYST_WAKEUP_EVENT_INTP8_MASK_F1K |\
                    SYST_WAKEUP_EVENT_INTP12_MASK_F1K |\
                    SYST_WAKEUP_EVENT_INTP9_MASK_F1K |\
                    SYST_WAKEUP_EVENT_INTP13_MASK_F1K |\
                    SYST_WAKEUP_EVENT_INTP14_MASK_F1K |\
                    SYST_WAKEUP_EVENT_INTP15_MASK_F1K |\
                    SYST_WAKEUP_EVENT_INTRTCA01S_MASK_F1K |\
                    SYST_WAKEUP_EVENT_INTRTCA0AL_MASK_F1K |\
                    SYST_WAKEUP_EVENT_INTRTCA0R_MASK_F1K |\
                    SYST_WAKEUP_EVENT_INTDCUTDI_MASK_F1K )

#ifdef SYST_WAKEUP_EVENT_INTKR0
#define SYST_WAKEUP_EVENT_INTKR0_MASK_F1K_ISO    ((ulong)0x00000002)
#else
#define SYST_WAKEUP_EVENT_INTKR0_MASK_F1K_ISO    ((ulong)0x00000000)
#endif

#ifdef SYST_WAKEUP_EVENT_INTRCANGRECC0
#define SYST_WAKEUP_EVENT_INTRCANGRECC0_MASK_F1K_ISO    ((ulong)0x00000004)
#else
#define SYST_WAKEUP_EVENT_INTRCANGRECC0_MASK_F1K_ISO    ((ulong)0x00000000)
#endif

#ifdef SYST_WAKEUP_EVENT_INTRCAN0REC
#define SYST_WAKEUP_EVENT_INTRCAN0REC_MASK_F1K_ISO  ((ulong)0x00000008)
#else
#define SYST_WAKEUP_EVENT_INTRCAN0REC_MASK_F1K_ISO  ((ulong)0x00000000)
#endif

#ifdef SYST_WAKEUP_EVENT_INTRCAN1REC
#define SYST_WAKEUP_EVENT_INTRCAN1REC_MASK_F1K_ISO  ((ulong)0x00000010)
#else
#define SYST_WAKEUP_EVENT_INTRCAN1REC_MASK_F1K_ISO  ((ulong)0x00000000)
#endif

#ifdef SYST_WAKEUP_EVENT_INTRCAN2REC
#define SYST_WAKEUP_EVENT_INTRCAN2REC_MASK_F1K_ISO  ((ulong)0x00000020)
#else
#define SYST_WAKEUP_EVENT_INTRCAN2REC_MASK_F1K_ISO  ((ulong)0x00000000)
#endif

#ifdef SYST_WAKEUP_EVENT_INTRCAN3REC
#define SYST_WAKEUP_EVENT_INTRCAN3REC_MASK_F1K_ISO  ((ulong)0x00000040)
#else
#define SYST_WAKEUP_EVENT_INTRCAN3REC_MASK_F1K_ISO  ((ulong)0x00000000)
#endif

#ifdef SYST_WAKEUP_EVENT_INTRCAN4REC
#define SYST_WAKEUP_EVENT_INTRCAN4REC_MASK_F1K_ISO  ((ulong)0x00000080)
#else
#define SYST_WAKEUP_EVENT_INTRCAN4REC_MASK_F1K_ISO  ((ulong)0x00000000)
#endif

#ifdef SYST_WAKEUP_EVENT_INTRCAN5REC
#define SYST_WAKEUP_EVENT_INTRCAN5REC_MASK_F1K_ISO  ((ulong)0x00000100)
#else
#define SYST_WAKEUP_EVENT_INTRCAN5REC_MASK_F1K_ISO  ((ulong)0x00000000)
#endif

#ifdef SYST_WAKEUP_EVENT_INTRCANGRECC1
#define SYST_WAKEUP_EVENT_INTRCANGRECC1_MASK_F1K_ISO  ((ulong)0x00000200)
#else
#define SYST_WAKEUP_EVENT_INTRCANGRECC1_MASK_F1K_ISO  ((ulong)0x00000000)
#endif

#ifdef SYST_WAKEUP_EVENT_INTRCAN6REC
#define SYST_WAKEUP_EVENT_INTRCAN6REC_MASK_F1K_ISO  ((ulong)0x00000400)
#else
#define SYST_WAKEUP_EVENT_INTRCAN6REC_MASK_F1K_ISO  ((ulong)0x00000000)
#endif

#define SYST_WUFISO0_FACTOR_1 ~((ulong)0x00000000 |\
					SYST_WAKEUP_EVENT_INTKR0_MASK_F1K_ISO |\
					SYST_WAKEUP_EVENT_INTRCANGRECC0_MASK_F1K_ISO |\
					SYST_WAKEUP_EVENT_INTRCAN0REC_MASK_F1K_ISO |\
					SYST_WAKEUP_EVENT_INTRCAN1REC_MASK_F1K_ISO |\
					SYST_WAKEUP_EVENT_INTRCAN2REC_MASK_F1K_ISO |\
					SYST_WAKEUP_EVENT_INTRCAN3REC_MASK_F1K_ISO |\
					SYST_WAKEUP_EVENT_INTRCAN4REC_MASK_F1K_ISO |\
					SYST_WAKEUP_EVENT_INTRCAN5REC_MASK_F1K_ISO |\
					SYST_WAKEUP_EVENT_INTRCANGRECC1_MASK_F1K_ISO |\
					SYST_WAKEUP_EVENT_INTRCAN6REC_MASK_F1K_ISO )

#ifdef SYST_WAKEUP_EVENT_INTADCA0I0
#define SYST_WAKEUP_EVENT_INTADCA0I0_MASK_F1K_F2  ((ulong)0x00000001)
#else
#define SYST_WAKEUP_EVENT_INTADCA0I0_MASK_F1K_F2  ((ulong)0x00000000)
#endif

#ifdef SYST_WAKEUP_EVENT_INTADCA0I1
#define SYST_WAKEUP_EVENT_INTADCA0I1_MASK_F1K_F2  ((ulong)0x00000002)
#else
#define SYST_WAKEUP_EVENT_INTADCA0I1_MASK_F1K_F2  ((ulong)0x00000000)
#endif

#ifdef SYST_WAKEUP_EVENT_INTADCA0I2
#define SYST_WAKEUP_EVENT_INTADCA0I2_MASK_F1K_F2  ((ulong)0x00000004)
#else
#define SYST_WAKEUP_EVENT_INTADCA0I2_MASK_F1K_F2  ((ulong)0x00000000)
#endif

#ifdef SYST_WAKEUP_EVENT_INTRLIN30
#define SYST_WAKEUP_EVENT_INTRLIN30_MASK_F1K_F2  ((ulong)0x00000008)
#else
#define SYST_WAKEUP_EVENT_INTRLIN30_MASK_F1K_F2  ((ulong)0x00000000)
#endif

#ifdef SYST_WAKEUP_EVENT_INTTAUJ0I0
#define SYST_WAKEUP_EVENT_INTTAUJ0I0_MASK_F1K_F2  ((ulong)0x00000010)
#else
#define SYST_WAKEUP_EVENT_INTTAUJ0I0_MASK_F1K_F2  ((ulong)0x00000000)
#endif

#ifdef SYST_WAKEUP_EVENT_INTTAUJ0I1
#define SYST_WAKEUP_EVENT_INTTAUJ0I1_MASK_F1K_F2  ((ulong)0x00000020)
#else
#define SYST_WAKEUP_EVENT_INTTAUJ0I1_MASK_F1K_F2  ((ulong)0x00000000)
#endif

#ifdef SYST_WAKEUP_EVENT_INTTAUJ0I2
#define SYST_WAKEUP_EVENT_INTTAUJ0I2_MASK_F1K_F2  ((ulong)0x00000040)
#else
#define SYST_WAKEUP_EVENT_INTTAUJ0I2_MASK_F1K_F2  ((ulong)0x00000000)
#endif

#ifdef SYST_WAKEUP_EVENT_INTTAUJ0I3
#define SYST_WAKEUP_EVENT_INTTAUJ0I3_MASK_F1K_F2  ((ulong)0x00000080)
#else
#define SYST_WAKEUP_EVENT_INTTAUJ0I3_MASK_F1K_F2  ((ulong)0x00000000)
#endif

#ifdef SYST_WAKEUP_EVENT_INTRLIN31
#define SYST_WAKEUP_EVENT_INTRLIN31_MASK_F1K_F2  ((ulong)0x00000100)
#else
#define SYST_WAKEUP_EVENT_INTRLIN31_MASK_F1K_F2  ((ulong)0x00000000)
#endif

#ifdef SYST_WAKEUP_EVENT_INTRLIN32
#define SYST_WAKEUP_EVENT_INTRLIN32_MASK_F1K_F2  ((ulong)0x00000200)
#else
#define SYST_WAKEUP_EVENT_INTRLIN32_MASK_F1K_F2  ((ulong)0x00000000)
#endif

#ifdef SYST_WAKEUP_EVENT_INTRTCA01S
#define SYST_WAKEUP_EVENT_INTRTCA01S_MASK_F1K_F2  ((ulong)0x00000400)
#else
#define SYST_WAKEUP_EVENT_INTRTCA01S_MASK_F1K_F2  ((ulong)0x00000000)
#endif

#ifdef SYST_WAKEUP_EVENT_INTRTCA0AL
#define SYST_WAKEUP_EVENT_INTRTCA0AL_MASK_F1K_F2  ((ulong)0x00000800)
#else
#define SYST_WAKEUP_EVENT_INTRTCA0AL_MASK_F1K_F2  ((ulong)0x00000000)
#endif

#ifdef SYST_WAKEUP_EVENT_INTRTCA0R
#define SYST_WAKEUP_EVENT_INTRTCA0R_MASK_F1K_F2  ((ulong)0x00001000)
#else
#define SYST_WAKEUP_EVENT_INTRTCA0R_MASK_F1K_F2  ((ulong)0x00000000)
#endif

#ifdef SYST_WAKEUP_EVENT_INTRLIN33
#define SYST_WAKEUP_EVENT_INTRLIN33_MASK_F1K_F2  ((ulong)0x00002000)
#else
#define SYST_WAKEUP_EVENT_INTRLIN33_MASK_F1K_F2  ((ulong)0x00000000)
#endif

#ifdef SYST_WAKEUP_EVENT_INTRLIN34
#define SYST_WAKEUP_EVENT_INTRLIN34_MASK_F1K_F2  ((ulong)0x00004000)
#else
#define SYST_WAKEUP_EVENT_INTRLIN34_MASK_F1K_F2  ((ulong)0x00000000)
#endif

#ifdef SYST_WAKEUP_EVENT_INTRLIN35
#define SYST_WAKEUP_EVENT_INTRLIN35_MASK_F1K_F2  ((ulong)0x00008000)
#else
#define SYST_WAKEUP_EVENT_INTRLIN35_MASK_F1K_F2  ((ulong)0x00000000)
#endif

#define SYST_WUF20_FACTOR_2 ~((ulong)0x00000000 |\
		            SYST_WAKEUP_EVENT_INTADCA0I0_MASK_F1K_F2 |\
		            SYST_WAKEUP_EVENT_INTADCA0I1_MASK_F1K_F2 |\
		            SYST_WAKEUP_EVENT_INTADCA0I2_MASK_F1K_F2 |\
					SYST_WAKEUP_EVENT_INTRLIN30_MASK_F1K_F2  |\
					SYST_WAKEUP_EVENT_INTTAUJ0I0_MASK_F1K_F2 |\
					SYST_WAKEUP_EVENT_INTTAUJ0I1_MASK_F1K_F2 |\
					SYST_WAKEUP_EVENT_INTTAUJ0I2_MASK_F1K_F2 |\
					SYST_WAKEUP_EVENT_INTTAUJ0I3_MASK_F1K_F2 |\
					SYST_WAKEUP_EVENT_INTRLIN31_MASK_F1K_F2  |\
					SYST_WAKEUP_EVENT_INTRLIN32_MASK_F1K_F2  |\
					SYST_WAKEUP_EVENT_INTRTCA01S_MASK_F1K_F2 |\
					SYST_WAKEUP_EVENT_INTRTCA0AL_MASK_F1K_F2 |\
					SYST_WAKEUP_EVENT_INTRTCA0R_MASK_F1K_F2  |\
					SYST_WAKEUP_EVENT_INTRLIN33_MASK_F1K_F2  |\
					SYST_WAKEUP_EVENT_INTRLIN34_MASK_F1K_F2  |\
					SYST_WAKEUP_EVENT_INTRLIN35_MASK_F1K_F2  )

#define RESCTL_RESF (*(volatile long *)0xFFF80760) /* RESCTL */
#endif/*__RH850_F1K__*/
#endif/*__RH850_F1x__*/




/*_____ G L O B A L - M A C R O S ____________________________________________*/

/*----------------------------------------------------------------------------*/
/* Name : SYST_Reset()                                                        */
/* Role : Reset the system                                                    */
/* Interface : -                                                              */
/* Pre-condition : -                                                          */
/* Constraints : -                                                            */
/* Behavior :                                                                 */
/*   DO                                                                       */
/*     [Enter an endless loop]                                                */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/
#ifdef __POLYSPACE__

  #define SYST_Reset()

#else

  #if !defined(SYST_SPECIAL_RESET) && ! defined(SYST_DEBUG_RESET)

    #if defined(C_COMP_COSMIC_MC9S12)
      /* Generate an immediate internal watchdog reset */
      #define SYST_Reset()              \
        TARG_WriteByte(ARMCOP, 0xFFU);  \
        while(1)

    #else

    #ifdef C_COMP_GHS_V850

      #ifdef __NEC_V850_Fx3__
        /* Generate an immediate internal watchdog reset */
        #define SYST_Reset()            \
          TARG_WriteByte(WDTE, 0xFFU);  \
          while(1)
      #endif /* __NEC_V850_Fx3__ */

      #ifdef __NEC_V850_Dx3__
        /* Generate an immediate internal software reset */
        #define SYST_Reset()             \
          TARG_WriteByte(RESCMD, 0x00U); \
          TARG_WriteByte(RESSWT, 0x00U); \
          while(1)
      #endif /* __NEC_V850_Dx3__ */

      #ifdef __REL_V850_Dx4__
        /* Generate an immediate internal softw are reset */

        #define Syst_Reset() \
          TARG_ProtWriteLong(PROTCMD2, SWRESA, RES_MSK_SWRESA); \
          while(1)

        #if defined(SYST_DATA_SAVE_IN_RESET)

        #define SYST_ResetNoBkp() \
          SYST_BackupRam(SYST_BKP_STORE, SYST_BKP_SEC_BOOT); \
          Syst_Reset()

        #define SYST_Reset() \
          SYST_BackupRam(SYST_BKP_STORE, SYST_BKP_SEC_BEFORE_INIT); \
          SYST_ResetNoBkp()

        #else

        #define SYST_Reset() Syst_Reset()

        #endif /* SYST_DATA_SAVE_IN_RESET */
      #endif /* __REL_V850_Dx4__ */
    #else

    #ifdef C_COMP_IAR_RL78

      #ifdef __REL_RL78__
      #if((defined(__REL_RL78_D1x__)) || (defined(__REL_RL78_F1x__)))
      #if((defined(__REL_RL78_D1A__)) || (defined(__REL_RL78_F12__)))
      /* Generate an immediate internal watchdog reset */
        #define SYST_Reset()          \
          TARG_WriteByte(WDTE, 0xFF); \
          while(1)
      #endif /*__REL_RL78_D1A__ || __REL_RL78_F12__*/
      #endif /*__REL_RL78_D1x__ || __REL_RL78_F1x__*/
      #endif /*__REL_RL78__*/

    #else

    #if defined(__FSL_IMX53x__) || defined(__FSL_IMX6x__)
    extern void SYST_Reset(void);

    #elif defined(__RH850_F1x__) && !defined(__BOOT_LINK__)
    #if defined(__RH850_F1K__) || defined(__RH850_F1L__)
    #define SYST_Reset() while(1)\
                     {\
                        TARG_ProtWriteLong_Port(WPROTRPROTCMD0,PORTPPROTS0,RESCTLSWRESA,RES_MSK_SWRESA);\
                     }
    #endif /*defined(__RH850_F1K__) || defined(__RH850_F1L__)*/

    #else
      /* All other targets */
    #define SYST_Reset() while(1)\
                   {\
                      TARG_ProtWriteLong_Port(WPROTRPROTCMD0,PORTPPROTS0,RESCTLSWRESA,RES_MSK_SWRESA);\
                   }

    #endif /* __FSL_IMX53x__,__FSL_IMX6x__ */
    #endif /* C_COMP_IAR_RL78 */
    #endif /* C_COMP_GHS_V850 */
    #endif /* C_COMP_COSMIC_MC9S12 */
  #else
    #ifdef SYST_DEBUG_RESET
    /* Hook debug function to be able to simply catch by breakpoint a Reset request */
    #define SYST_Reset() SYST_DebugReset()
    #else
    /* Defined in coms.h */
    #endif
  #endif /* !defined(SYST_SPECIAL_RESET) && ! defined(SYST_DEBUG_RESET) */

#endif /* __POLYSPACE__ */


/*----------------------------------------------------------------------------*/
/* Defines for OS tick control                                                */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Name : SYST_StartOsTick()                                                  */
/* Role : Start the OS tick                                                   */
/* Interface : -                                                              */
/* Pre-condition : -                                                          */
/* Constraints :                                                              */
/* Behavior :                                                                 */
/*   DO                                                                       */
/*     [enable the OS timer interrupt]                                        */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/
#ifdef __RTOS__
#define SYST_StartOsTick() RTOS_Tick_Run()
#endif /* __RTOS__ */

#ifdef __GHOS__
#define SYST_StartOsTick()
#endif /* __GHOS__ */

#ifdef __OSEK__
#ifdef __TX49__
#define SYST_StartOsTick() /* TBD */
#endif /* __TX49__ */
#ifdef __MC9S12xx__
#define SYST_StartOsTick() /* TBD */
#endif /* __MC9S12xx__ */
#if defined (__NEC_V850__) || defined(__RH850__)
#define SYST_StartOsTick() SYST_ConfigStartOsTick()
#endif
#endif /* __OSEK__ */

/*----------------------------------------------------------------------------*/
/* Name : SYST_StopOsTick()                                                   */
/* Role : Stop the OS tick                                                    */
/* Interface : -                                                              */
/* Pre-condition : -                                                          */
/* Constraints :                                                              */
/* Behavior :                                                                 */
/*   DO                                                                       */
/*     [disable the OS timer interrupt]                                       */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/
#ifdef __RTOS__
#define SYST_StopOsTick()  RTOS_Tick_Stop()
#endif /* __RTOS__ */

#ifdef __GHOS__
#define SYST_StopOsTick()
#endif /* __GHOS__ */

#ifdef __OSEK__
#ifdef __TX49__
#define SYST_StopOsTick()  /* TBD */
#endif /* __TX49__ */
#ifdef __MC9S12xx__
#define SYST_StopOsTick()  /* TBD */
#endif /* __MC9S12xx__ */
#if defined (__NEC_V850__) || defined(__RH850__)
#define SYST_StopOsTick() SYST_ConfigStopOsTick()/* TBD */
#endif
#endif /* __OSEK__ */

/*----------------------------------------------------------------------------*/
/* Defines and Macros for Power Modes management                              */
/*----------------------------------------------------------------------------*/
#ifdef __REL_RL78__
#if((defined(__REL_RL78_D1x__)) || (defined(__REL_RL78_F1x__)))
#if((defined(__REL_RL78_D1A__)) || (defined(__REL_RL78_F12__)))
/*----------------------------------------------------------------------------*/
/* Name : SYST_GoIntoHaltMode()                                               */
/* Role : Put the NEC_RL78 in halt mode                                       */
/* Interface : -                                                              */
/* Pre-condition : -                                                          */
/* Constraints : -                                                            */
/* Behavior :                                                                 */
/*   DO                                                                       */
/*     [request the halt mode]                                                */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/
#define SYST_GoIntoHaltMode()   __halt();                   \
                                __NOP__;                    \
                                __NOP__

/*----------------------------------------------------------------------------*/
/* Name : SYST_GoIntoStopMode()                                               */
/* Role : Put the NEC_RL78 stop mode                                          */
/* Interface : -                                                              */
/* Pre-condition : -                                                          */
/* Constraints : -                                                            */
/* Behavior :                                                                 */
/*   DO                                                                       */
/*     [request the normal mode]                                              */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/
#define SYST_GoIntoStopMode()   __stop();              \
                                __NOP__;               \
                                __NOP__
#endif /*__REL_RL78_D1A__ || __REL_RL78_F12__*/
#endif /*__REL_RL78_D1x__ || __REL_RL78_F1x__*/
#endif /*__REL_RL78__*/

#ifdef __MC9S12xx__

/*----------------------------------------------------------------------------*/
/* Name : SYST_GoIntoWaitMode()                                               */
/* Role : Put the MC9S12xx in wait for interrupt mode                         */
/* Interface : -                                                              */
/* Pre-condition : -                                                          */
/* Constraints : -                                                            */
/* Behavior :                                                                 */
/*   DO                                                                       */
/*     [request the wait mode]                                                */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/
#define SYST_GoIntoWaitMode()  _asm(" WAI")


/*----------------------------------------------------------------------------*/
/* Name : SYST_GoIntoStopMode()                                               */
/* Role : Put the MC9S12xx stop mode                                          */
/* Interface : -                                                              */
/* Pre-condition : -                                                          */
/* Constraints : -                                                            */
/* Behavior :                                                                 */
/*   DO                                                                       */
/*     [request stop mode]                                                    */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/
#define SYST_GoIntoStopMode()  _asm(" STOP")


/*----------------------------------------------------------------------------*/
/* Name : SYST_EnableStopMode()                                               */
/* Role : Put the MC9S12xx stop mode                                          */
/* Interface : -                                                              */
/* Pre-condition : -                                                          */
/* Constraints : -                                                            */
/* Behavior :                                                                 */
/*   DO                                                                       */
/*     [Enable STOP operation by clearing S-bit in CCR register               */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/
#define SYST_EnableStopMode()  _asm(" ANDCC #0x7F")


/*----------------------------------------------------------------------------*/
/* Name : SYST_DisableStopMode()                                              */
/* Role : Put the MC9S12xx stop mode                                          */
/* Interface : -                                                              */
/* Pre-condition : -                                                          */
/* Constraints : -                                                            */
/* Behavior :                                                                 */
/*   DO                                                                       */
/*     [Disable STOP operation by setting S-bit in CCR register               */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/
#define SYST_DisableStopMode()  _asm(" ORCC #0x80")

#endif /* __MC9S12xx__ */


#ifdef __MC9S08xx__

/*----------------------------------------------------------------------------*/
/* Name : SYST_GoIntoWaitMode()                                               */
/* Role : Put the MC9S08xx in wait for interrupt mode                         */
/* Interface : -                                                              */
/* Pre-condition : -                                                          */
/* Constraints : -                                                            */
/* Behavior :                                                                 */
/*   DO                                                                       */
/*     [request the wait mode]                                                */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/
#define SYST_GoIntoWaitMode()  _asm(" WAIT")


/*----------------------------------------------------------------------------*/
/* Name : SYST_GoIntoStopMode()                                               */
/* Role : Put the MC9S12xx stop mode                                          */
/* Interface : -                                                              */
/* Pre-condition : -                                                          */
/* Constraints : -                                                            */
/* Behavior :                                                                 */
/*   DO                                                                       */
/*     [request stop mode]                                                    */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/
#define SYST_GoIntoStopMode()  _asm(" STOP")

#endif /* __MC9S08xx__ */


#ifdef __NEC_V850_Fx3__

/*----------------------------------------------------------------------------*/
/* Name : SYST_GoIntoHaltMode()                                               */
/* Role : Put the NEC V850ES/Fx3 in halt mode                                 */
/* Interface : -                                                              */
/* Pre-condition :                                                            */
/*     - All interrupts have to be disabled                                   */
/* Constraints : -                                                            */
/*     - All interrupts have to be enabled after this service call            */
/* Behavior :                                                                 */
/*   DO                                                                       */
/*     [request the halt mode]                                                */
/*     [5 nop instructions have to be include after (flush pipeline)]         */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/
#define SYST_GoIntoHaltMode()                                   \
            asm("halt");                                        \
            asm("nop");                                         \
            asm("nop");                                         \
            asm("nop");                                         \
            asm("nop");                                         \
            asm("nop")


/*----------------------------------------------------------------------------*/
/* Name : SYST_GoIntoStopMode()                                               */
/* Role : Put the NEC V850ES/Fx3 in STOP mode                                 */
/* Interface : -                                                              */
/* Pre-condition :                                                            */
/*     - All interrupts have to be disabled                                   */
/* Constraints : -                                                            */
/*     - All interrupts have to be enabled after this service call            */
/* Behavior :                                                                 */
/*   DO                                                                       */
/*     [Start 8Mhz internal RingOSC]                                          */
/*     [Wait until 8Mhz internal oscillator is operating]                     */
/*     [Select clock Through-mode (with mainOSC)]                             */
/*     [Switch to clock-through mode with 8Mhz internal RingOSC]              */
/*     [Wait until Fxx is operating on 8MHz internal RingOSC]                 */
/*     [Stop of the PLL]                                                      */
/*     [Stop of the mainOSC]                                                  */
/*     [Select STOP mode as power save mode]                                  */
/*     [CPU needs five nop to flush pipeline,CPU go into IDLE2 in at the nop5]*/
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/
#define SYST_GoIntoStopMode()                                   \
            TARG_WriteBit(RCM, CLO_BIT_HRSTOP, 0);              \
            while(TARG_ReadBit(RCM, CLO_BIT_RSTS) != 1);        \
            TARG_WriteBit(PLLCTL, CLO_BIT_SELPLL, 0);           \
            TARG_WriteByte(PRCMD, 0x00);                        \
            TARG_WriteByte(MCM, 0x00);                          \
            while(TARG_ReadBit(MCM, CLO_BIT_MCS) != 0);         \
            TARG_WriteBit(PLLCTL, CLO_BIT_PLLON, 0);            \
            TARG_WriteByte(PRCMD, CLO_MSK_MCK);                 \
            TARG_WriteByte(PCC, CLO_MSK_MCK);                   \
            TARG_WriteByte(PSMR, CLO_MSK_PSM0 + CLO_MSK_PSM1);  \
            TARG_WriteByte(PRCMD, CLO_MSK_STP);                 \
            TARG_WriteByte(PSC, CLO_MSK_STP);                   \
            asm("nop");                                         \
            asm("nop");                                         \
            asm("nop");                                         \
            asm("nop");                                         \
            asm("nop")


/*----------------------------------------------------------------------------*/
/* Name : SYST_GoIntoIdle2Mode()                                              */
/* Role : Put the NEC V850ES/Fx3 in IDLE2 mode                                */
/* Interface : -                                                              */
/* Pre-condition :                                                            */
/*     - All interrupts have to be disabled                                   */
/* Constraints : -                                                            */
/*     - All interrupts have to be enabled after this service call            */
/*     - Clock issues must be taking into account.                            */
/*       when entering IDLE2 mode, mainOSC is operating while PLL is stopped  */
/*       When a source that releases the IDLE2 mode occurs, an internal       */
/*       dedicated timer starts counting in accordance with the setting       */
/*       of the OSTS register. When this counter overflows, the normal        */
/*       operation is restored                                                */
/* Behavior :                                                                 */
/*   DO                                                                       */
/*     [Select IDLE2 mode as power save mode]                                 */
/*     [Go into power save mode selected]                                     */
/*     [CPU needs five nop to flush pipeline,CPU go into IDLE2 in at the nop5]*/
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/
#define SYST_GoIntoIdle2Mode()                                  \
            TARG_WriteByte(PSMR, 0x02);                         \
            TARG_WriteByte(PRCMD, CLO_MSK_STP);                 \
            TARG_WriteByte(PSC, CLO_MSK_STP);                   \
            asm("nop");                                         \
            asm("nop");                                         \
            asm("nop");                                         \
            asm("nop");                                         \
            asm("nop")

#endif /* __NEC_V850_Fx3__ */


#ifdef __NEC_V850_Dx3__

/*----------------------------------------------------------------------------*/
/* Name : SYST_GoIntoHaltMode()                                               */
/* Role : Put the NEC V850E/Dx3 in halt mode                                  */
/* Interface : -                                                              */
/* Pre-condition :                                                            */
/*     - All interrupts have to be disabled                                   */
/* Constraints : -                                                            */
/*     - All interrupts have to be enabled after this service call            */
/* Behavior :                                                                 */
/*   DO                                                                       */
/*     [Select the halt mode]                                                 */
/*     [Go into power save mode selected]                                     */
/*     [CPU needs five nop to flush pipeline,CPU go into WATCH mode at nop 5] */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/
#define SYST_GoIntoHaltMode()                                   \
            asm("halt");                                        \
            asm("nop");                                         \
            asm("nop");                                         \
            asm("nop");                                         \
            asm("nop");                                         \
            asm("nop")


/*----------------------------------------------------------------------------*/
/* Name : SYST_GoIntoStopMode()                                               */
/* Role : Put the NEC V850E/Dx3 stop mode                                     */
/* Interface : -                                                              */
/* Pre-condition :                                                            */
/*     - All interrupts have to be disabled                                   */
/* Constraints : -                                                            */
/*     - All interrupts have to be enabled after this service call            */
/* Behavior :                                                                 */
/*   DO                                                                       */
/*     [Select the stop mode]                                                 */
/*     [Go into power save mode selected]                                     */
/*     [CPU needs five nop to flush pipeline,CPU go into WATCH mode at nop 5] */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/
#define SYST_GoIntoStopMode()                                   \
            TARG_WriteBit(PSM, CLO_BIT_PSM1, 0);                \
            TARG_WriteBit(PSM, CLO_BIT_PSM0, 1);                \
            TARG_WriteByte(PRCMD, CLO_MSK_STP);                 \
            TARG_WriteByte(PSC, CLO_MSK_STP);                   \
            asm("nop");                                         \
            asm("nop");                                         \
            asm("nop");                                         \
            asm("nop");                                         \
            asm("nop")


/*----------------------------------------------------------------------------*/
/* Name : SYST_GoIntoWatchMode()                                              */
/* Role :  Put the NEC V850E/Dx3 in Watch mode                                */
/* Interface : -                                                              */
/* Pre-condition :                                                            */
/*     - All interrupts have to be disabled                                   */
/* Constraints : -                                                            */
/*     - All interrupts have to be enabled after this service call            */
/* Behavior :                                                                 */
/*   DO                                                                       */
/*     [select the Watch mode]                                                */
/*     [enter stop mode]                                                      */
/*     [CPU needs five nop to flush pipeline,CPU go into WATCH mode at nop 5] */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/
#define SYST_GoIntoWatchMode()                                  \
            TARG_WriteBit(PSM, CLO_BIT_PSM1, 1);                \
            TARG_WriteBit(PSM, CLO_BIT_PSM0, 0);                \
            TARG_WriteByte(PRCMD, CLO_MSK_STP);                 \
            TARG_WriteByte(PSC, CLO_MSK_STP);                   \
            asm("nop");                                         \
            asm("nop");                                         \
            asm("nop");                                         \
            asm("nop");                                         \
            asm("nop")

#define SYST_EnableStopMode()
#define SYST_DisableStopMode()
#endif /* __NEC_V850_Dx3__ */


#ifdef __REL_V850_Dx4__

/*----------------------------------------------------------------------------*/
/* Name : SYST_GoIntoHaltMode()                                               */
/* Role : Put the REL V850E2/Dx4 in HALT mode                                 */
/* Interface : -                                                              */
/* Pre-condition :                                                            */
/*     - All interrupts have to be disabled                                   */
/* Constraints : -                                                            */
/*     - All interrupts have to be enabled after this service call            */
/*     - if an exception is acknowledged while the system is in HALT state,   */
/*       the return PC of that exception is the PC of the instruction that    */
/*       follows the HALT instruction.                                        */
/* Behavior :                                                                 */
/*   DO                                                                       */
/*     [Enter the halt command to go into the power save mode selected]       */
/*     [Seven nop are inserted to clear the pipeline]                         */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/
#define SYST_GoIntoHaltMode()                                   \
            asm("halt");                                        \
            asm("nop");                                         \
            asm("nop");                                         \
            asm("nop");                                         \
            asm("nop");                                         \
            asm("nop");                                         \
            asm("nop");                                         \
            asm("nop")


/*----------------------------------------------------------------------------*/
/* Name : SYST_GoIntoStopMode()                                               */
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
#if defined(__REL_V850_DJ4_HE__) || defined(__REL_V850_DN4H__)
extern void SYST_GoIntoStopMode(void);
#endif /* !defined(__REL_V850_DK4H__) */

#if defined(__REL_V850_DK4H__)
#define SYST_GoIntoStopMode()                                                \
            TARG_WriteLong(WUFCL0, 0xFFFFFFFFU);                             \
            TARG_WriteLong(WUFMSKL0, 0x00000000U);                           \
            TARG_ClearBitsInLong(OSCWUFMSK, WUC_MSK_OSCWUFMSK00);            \
            do                                                               \
            {                                                                \
              TARG_ProtWriteLong(PROTCMD2, PSC0,                             \
                                 (SBC_MSK_PSCnSTP + SBC_MSK_PSCnPOF));       \
            } while(TARG_ReadLong(PROTS2));                                  \
            asm("nop");                                                      \
            asm("nop");                                                      \
            asm("nop");                                                      \
            asm("nop");                                                      \
            asm("nop");                                                      \
            asm("nop");                                                      \
            asm("nop")
#endif   /* __REL_V850_DK4H__ */


/*----------------------------------------------------------------------------*/
/* Name : SYST_Config_SoftResetCheck()                                        */
/* Role : software reset check before going into Deep Sleep mode              */
/* Interface : -                                                              */
/* Pre-condition :                                                            */
/*     - All interrupts have to be disabled                                   */
/* Constraints : -                                                            */
/* Behavior :                                                                 */
/*----------------------------------------------------------------------------*/
#define SYST_Config_SoftResetCheck()


/*----------------------------------------------------------------------------*/
/* Name : SYST_EnableStopMode()                                               */
/* Role : Enable stop mode operation                                          */
/* Interface : -                                                              */
/* Pre-condition : -                                                          */
/* Constraints : -                                                            */
/* Behavior :                                                                 */
/*   DO                                                                       */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/
#define SYST_EnableStopMode()


/*----------------------------------------------------------------------------*/
/* Name : SYST_DisableStopMode()                                              */
/* Role : Disable stop mode operation                                         */
/* Interface : -                                                              */
/* Pre-condition : -                                                          */
/* Constraints : -                                                            */
/* Behavior :                                                                 */
/*   DO                                                                       */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/
#define SYST_DisableStopMode()


/*----------------------------------------------------------------------------*/
/* Name : SYST_GoIntoWatchMode()                                              */
/* Role : Put the REL V850E2/Dx4 in STOP mode                                 */
/* Interface : -                                                              */
/* Pre-condition :                                                            */
/*     - All interrupts have to be disabled                                   */
/* Constraints : -                                                            */
/*     - All interrupts have to be enabled after this service call            */
/*     - After occurrence of a wake-up event the next instructions shall      */
/*       evaluate the PWS0.PWS1PSS bit to become 0, which indicates the       */
/*       termination of the STOP mode.                                        */
/*       The microcontroller resumes operation in this loop and exits it,     */
/*       when wake-up is completed (indicated by PWS0.PWS1PSS = 0).           */
/* Behavior :                                                                 */
/*   DO                                                                       */
/*     [Set Wakeup mask]                                                      */
/*     [Enter ISO1 STOP]                                                      */
/*     [Enter ISO0 STOP to go into power save mode selected]                  */
/*     [Seven nop are inserted to clear the pipeline]                         */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/
#if !defined(__REL_V850_DK4H__)
#define SYST_GoIntoWatchMode()                                                  \
           TARG_WriteLong(WUFCL0, 0xFFFFFFFFU);                                 \
           TARG_WriteLong(WUFCL1, 0xFFFFFFFFU);                                 \
           TARG_WriteLong(WUFCM0, 0xFFFFFFFFU);                                 \
           TARG_WriteLong(WUFCM1, 0xFFFFFFFFU);                                 \
           TARG_WriteLong(WUFCH0, 0xFFFFFFFFU);                                 \
           TARG_WriteLong(WUFCH1, 0xFFFFFFFFU);                                 \
           TARG_WriteLong(WUFMSKL0, SYST_WUFL);                                 \
           TARG_WriteLong(WUFMSKL1, 0xFF7FBF88U);                               \
           TARG_WriteLong(WUFMSKM0, SYST_WUFM);                                 \
           TARG_WriteLong(WUFMSKM1, 0xFFFFFFFFU);                               \
           TARG_WriteLong(WUFMSKH0, SYST_WUFH);                                 \
           TARG_WriteLong(WUFMSKH1, 0xDFFFFFFFU);                               \
           do                                                                   \
           {                                                                    \
             TARG_ProtWriteLong(PROTCMD2, PSC1, SBC_MSK_PSCnSTP);               \
           } while(TARG_ReadLong(PROTS2));                                      \
           do                                                                   \
           {                                                                    \
             TARG_ProtWriteLong(PROTCMD2, PSC0, SBC_MSK_PSCnSTP);               \
           } while(TARG_ReadLong(PROTS2));                                      \
           asm("nop");                                                          \
           asm("nop");                                                          \
           asm("nop");                                                          \
           asm("nop");                                                          \
           asm("nop");                                                          \
           asm("nop");                                                          \
           asm("nop");
#endif

#if defined(__REL_V850_DK4H__)
#define SYST_GoIntoWatchMode()                                              \
           TARG_WriteLong(WUFCL0,   0xFFFFFFFFU);                           \
           TARG_WriteLong(WUFMSKL0, 0x00000000U);                           \
           TARG_ClearBitsInLong(OSCWUFMSK, WUC_MSK_OSCWUFMSK00);            \
           do                                                               \
           {                                                                \
             TARG_ProtWriteLong(PROTCMD2, PSC2, SBC_MSK_PSCnSTP);           \
           } while(TARG_ReadLong(PROTS2));                                  \
                                                                            \
           while(!(TARG_ReadLong(PWS2) & SBC_MSK_PWSnPSS))                  \
           {                                                                \
             asm("nop");                                                    \
           }                                                                \
                                                                            \
           do                                                               \
           {                                                                \
             TARG_ProtWriteLong(PROTCMD2, PSC0, SBC_MSK_PSCnSTP);           \
           } while(TARG_ReadLong(PROTS2));                                  \
           asm("nop");                                                      \
           asm("nop");                                                      \
           asm("nop");                                                      \
           asm("nop");                                                      \
           asm("nop");                                                      \
           asm("nop");                                                      \
           asm("nop")
#endif /*__REL_V850_DK4H__*/
#endif /* __REL_V850_Dx4__ */


#if defined(__FSL_IMX53x__) || defined(__FSL_IMX6x__)

/* LOW POWER MODES: To be defined */

#endif /* __FSL_IMX53x__,__FSL_IMX6x_ */


/*----------------------------------------------------------------------------*/
/* Name : SYST_Assert                                                         */
/* Role : Platform service for assertion.                                     */
/* Interface :     IN : Logical expression to test                            */
/* Pre-condition : -                                                          */
/* Constraints : -                                                            */
/* Behavior :                                                                 */
/*   DO                                                                       */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/
#if defined(__POLYSPACE__)
  /* Polyspace automatically includes <assert.h> .               */
  /* Assertions are always checked by Polyspace,                 */
  /* even if SYST_ASSERT_ENABLED is not defined in configuration */
  #define SYST_Assert(e) assert(e)
#else
  #ifdef SYST_ASSERT_ENABLED
    #define SYST_Assert(Expression) Syst_Assert(Expression)

    #if defined(__PC_SIMULATION__) || defined(C_COMP_GHS_ARM)
      #include <stdio.h>
      #define Syst_Assert(e)((void) ((e) ? 0 : Syst_AssertExp(#e, __FILE__, __LINE__)))
      #define Syst_AssertExp(e, file, line) ((void)printf("%s:%u: failed assertion `%s'\n", file, line, e), SYST_Reset(), 0)
    #else
      /* Default implementation of assert */
      #define Syst_Assert(Expression)
    #endif /* defined(__PC_SIMULATION__) || defined(C_COMP_GHS_ARM) */
  #else
    #define SYST_Assert(Expression)
  #endif /* SYST_ASSERT_ENABLED */
#endif /* defined(__POLYSPACE__) */

/*----------------------------------------------------------------------------*/
/* Name : SYST_DEBUG                                                          */
/* Role : Platform debug macro action. Action can be print messages on stdout */
/*        etc.                                                                */
/* Interface :                                                                */
/*              IN : Condition : Condition to send the debug message          */
/*              IN : Action : Action to do when condition is fullfiled        */
/* Pre-condition : -                                                          */
/* Constraints : -                                                            */
/* Behavior :                                                                 */
/*   DO                                                                       */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/
#ifdef SYST_DEBUG_ENABLED
  #define SYST_DEBUG(Condition, Action) if(Condition) {Action;}

  #if defined(__PC_SIMULATION__) || defined(C_COMP_GHS_ARM)
  #include <stdio.h>
  #define SYST_Printf(fmt, ...) printf(fmt, ##__VA_ARGS__); fflush(stdout)
  #endif /* __PC_SIMULATION__ || C_COMP_GHS_ARM */
#else
  #define SYST_DEBUG(Condition, Action)
#endif /* SYST_DEBUG_ENABLED */


/*_____ G L O B A L - F U N C T I O N S - P R O T O T Y P E S ________________*/

/*----------------------------------------------------------------------------*/
/*Name : SYST_Init                                                            */
/*Role : Init this module                                                     */
/*Interface : void                                                            */
/*Pre-condition : -                                                           */
/*Constraints : Call one time at reset                                        */
/*----------------------------------------------------------------------------*/
extern void SYST_Init(void);

#if defined(__BOOT_LINK__) && (!defined(__FBL_UPDATER__))
/*----------------------------------------------------------------------------*/
/*Name : _start                                                               */
/*Role : Start and jump to dr7f701030_startup.850                             */
/*Interface : void                                                            */
/*Pre-condition : -                                                           */
/*Constraints : Call one time at reset                                        */
/*----------------------------------------------------------------------------*/
extern void _start(void);
#endif


#ifdef Syst_VOID_ISR_SERVICE
/*----------------------------------------------------------------------------*/
/*Name : SYST_VoidInterruptHandler_it                                         */
/*Role : create an empty interrupt handler                                    */
/*Interface : -                                                               */
/*Pre-condition : -                                                           */
/*Constraints :  -                                                            */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [no operation]                                                          */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
extern ISR(SYST_VoidInterruptHandler_it);
#endif  /* Syst_VOID_ISR_SERVICE */


#ifdef Syst_UNHANDLED_ISR_SERVICE
/*----------------------------------------------------------------------------*/
/*Name : SYST_UnhandledException_it                                           */
/*Role : Endless-loop is called when unused interrupt vector is fetched       */
/*Interface : -                                                               */
/*Pre-condition : -                                                           */
/*Constraints :  -                                                            */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [endless-loop]                                                          */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
extern ISR(SYST_UnhandledException_it);
#endif /* Syst_UNHANDLED_ISR_SERVICE */


/*----------------------------------------------------------------------------*/
/*Name : SYST_Wait                                                            */
/*Role : System polling timing                                                */
/*Interface : Delay value                                                     */
/*               SYST_250nS                                                   */
/*               SYST_500nS                                                   */
/*               SYST_2_5uS                                                   */
/*               SYST_3uS                                                     */
/*               SYST_4uS                                                     */
/*               SYST_4_7uS                                                   */
/*               SYST_5uS                                                     */
/*               SYST_20uS                                                    */
/*               SYST_25uS                                                    */
/*               SYST_50uS                                                    */
/*               SYST_100uS                                                   */
/*               SYST_200uS                                                   */
/*                                                                            */
/*Pre-condition : -                                                           */
/*Constraints :                                                               */
/*   - This function is able to lengthen if interrupts function appear.       */
/*     Protect it against ISR if necessary.                                   */
/*   - time is different for each processor (different machine cycle)         */
/*     see syst.c for details                                                 */
/*   - timing is independent of compiler options or optimizer configuration   */
/*Behaviour :                                                                 */
/*DO                                                                          */
/*  [Wait the specified delay]                                                */
/*OD                                                                          */
/*----------------------------------------------------------------------------*/
#define SYST_Wait(delay) \
        SYST_Wait_##delay()


/*----------------------------------------------------------------------------*/
/* Internal sub-macro for SYST_Wait(x) - DO NOT USE !!! */

#ifdef Syst_WAIT_SERVICE
#ifndef __PC_SIMULATION__
extern void SYST_WaitLoop(ushort Syst_delay);
#else
#define SYST_WaitLoop(Syst_delay)
#endif /* !__PC_SIMULATION__ */
#endif /* Syst_WAIT_SERVICE */

/* Syst_Wait:__REL_RL78__*/
#ifdef __REL_RL78__
#if defined(__REL_RL78_D1x__)
#if defined(__REL_RL78_D1A__)
#if SYST_FX_CLOCK == 8
/* CPU Clock = 8Mhz => NOP = 125 ns */
#define  SYST_Wait_500nS()      \
    __NOP__;                    \
    __NOP__;                    \
    __NOP__;                    \
    __NOP__

#elif SYST_FX_CLOCK == 16
/* CPU Clock = 16Mhz => NOP = 62.5 ns */
#define  SYST_Wait_500nS()      \
    __NOP__;                    \
    __NOP__;                    \
    __NOP__;                    \
    __NOP__;                    \
  __NOP__;                    \
    __NOP__;                    \
    __NOP__;                    \
    __NOP__

#elif SYST_FX_CLOCK == 20
/* CPU Clock = 20Mhz => NOP = 50 ns */
#define  SYST_Wait_500nS()      \
    __NOP__;                    \
    __NOP__;                    \
    __NOP__;                    \
    __NOP__;                    \
  __NOP__;                    \
    __NOP__;                    \
    __NOP__;                    \
    __NOP__;                    \
    __NOP__;                    \
    __NOP__

#elif SYST_FX_CLOCK == 32
/* CPU Clock = 32Mhz => NOP = 31.25 ns */
#define  SYST_Wait_500nS()      \
    __NOP__;                    \
    __NOP__;                    \
    __NOP__;                    \
    __NOP__;                    \
  __NOP__;                    \
    __NOP__;                    \
    __NOP__;                    \
    __NOP__;                    \
    __NOP__;                    \
    __NOP__;                    \
  __NOP__;                    \
    __NOP__;                    \
    __NOP__;                    \
    __NOP__;                    \
    __NOP__;                    \
  __NOP__

#else
#error please define a correct SYST_FX_CLOCK for RL78_D1A !!!
#endif

#endif /* __REL_RL78_D1A__*/
#endif /* __REL_RL78_D1x__*/

#if defined(__REL_RL78_F1x__)
#if defined(__REL_RL78_F12__)

#if SYST_FX_CLOCK == 1
/* CPU Clock = 1Mhz => NOP = 1000 ns
Minimum delay Posiible for 1Mhz is 1000ns*/
#define  SYST_Wait_500nS()  \
__NOP__

#elif SYST_FX_CLOCK == 4
/* CPU Clock = 4Mhz => NOP = 250 ns */
#define  SYST_Wait_500nS()      \
    __NOP__;                    \
  __NOP__

#elif SYST_FX_CLOCK == 8
/* CPU Clock = 8Mhz => NOP = 125 ns */
#define  SYST_Wait_500nS()      \
    __NOP__;                    \
    __NOP__;                    \
    __NOP__;                    \
    __NOP__

#elif SYST_FX_CLOCK == 12
/* CPU Clock = 12Mhz => NOP = 83.4 ns */
#define  SYST_Wait_500nS()      \
    __NOP__;                    \
    __NOP__;                    \
  __NOP__;                    \
    __NOP__;                    \
    __NOP__;                    \
  __NOP__

#elif SYST_FX_CLOCK == 16
/* CPU Clock = 16Mhz => NOP = 62.5 ns */
#define  SYST_Wait_500nS()      \
    __NOP__;                    \
    __NOP__;                    \
    __NOP__;                    \
    __NOP__;                    \
  __NOP__;                    \
    __NOP__;                    \
    __NOP__;                    \
    __NOP__

#elif SYST_FX_CLOCK == 20
/* CPU Clock = 20Mhz => NOP = 50 ns */
#define  SYST_Wait_500nS()      \
    __NOP__;                    \
    __NOP__;                    \
    __NOP__;                    \
    __NOP__;                    \
  __NOP__;                    \
    __NOP__;                    \
    __NOP__;                    \
    __NOP__;                    \
    __NOP__;                    \
    __NOP__

#elif SYST_FX_CLOCK == 24
/* CPU Clock = 24Mhz => NOP = 41.67 ns */
#define  SYST_Wait_500nS()      \
    __NOP__;                    \
    __NOP__;                    \
    __NOP__;                    \
    __NOP__;                    \
  __NOP__;                    \
    __NOP__;                    \
    __NOP__;                    \
    __NOP__;                    \
  __NOP__;                    \
    __NOP__;                    \
    __NOP__;                    \
  __NOP__

#elif SYST_FX_CLOCK == 32
/* CPU Clock = 32Mhz => NOP = 31.25 ns */
#define  SYST_Wait_500nS()      \
    __NOP__;                    \
    __NOP__;                    \
    __NOP__;                    \
    __NOP__;                    \
  __NOP__;                    \
    __NOP__;                    \
    __NOP__;                    \
    __NOP__;                    \
    __NOP__;                    \
    __NOP__;                    \
  __NOP__;                    \
    __NOP__;                    \
    __NOP__;                    \
    __NOP__;                    \
    __NOP__;                    \
  __NOP__
#else
#error please define a correct SYST_FX_CLOCK for RL78_F12!!!
#endif

#endif /* __REL_RL78_F12__*/
#endif /* __REL_RL78_F1x__*/

#if((defined(__REL_RL78_D1x__)) || (defined(__REL_RL78_F1x__)))
#if((defined(__REL_RL78_D1A__)) || (defined(__REL_RL78_F12__)))
#if SYST_FX_CLOCK == 1
/*CPU Clock = 1Mhz => NOP = 1 us ,Real time = 1 * 10 us = 10us */
#define SYST_Wait_SYST_10uS()   \
        __NOP__;                     \
        __NOP__;                     \
        __NOP__;                     \
        __NOP__;                     \
        __NOP__;                     \
        __NOP__;                     \
        __NOP__;                     \
        __NOP__;                     \
        __NOP__;                     \
    __NOP__
/*SYST_WaitLoop cycles = ((5x6)+16)= 46 , NOP cycles = 4,Total cycles = ( 46 + 4 )= 50
CPU Clock = 1Mhz => NOP = 1 us ,Real time = 50 x 1 us = 50us */
#define SYST_Wait_SYST_50uS()   \
  SYST_WaitLoop(5);             \
   __NOP__;                     \
   __NOP__;                     \
   __NOP__;                     \
   __NOP__

 /*SYST_WaitLoop cycles = (30x6)+16)= 196 , NOP cycles = 4,Total cycles = ( 196 + 4 )= 200
CPU Clock = 1Mhz => NOP = 1 us ,Real time = 200 x 1 us = 200us */
#define SYST_Wait_SYST_200uS()   \
  SYST_WaitLoop(30);             \
   __NOP__;                     \
   __NOP__;                     \
   __NOP__;                     \
   __NOP__

#elif SYST_FX_CLOCK == 4
/*Real time = 2.5us */
#define SYST_Wait_SYST_2_5uS()   \
  SYST_Wait_500nS();              \
  SYST_Wait_500nS();              \
  SYST_Wait_500nS();              \
  SYST_Wait_500nS();              \
  SYST_Wait_500nS()

/*SYST_WaitLoop cycles = (4x6)+16)= 40,
CPU Clock = 4Mhz => NOP = 250 ns ,Real time = 40 x 250ns = 10us */
#define SYST_Wait_SYST_10uS()   \
  SYST_WaitLoop(4)

/*SYST_WaitLoop cycles = (30x6)+16)= 196 , NOP cycles = 4,Total cycles = ( 196 + 4 )= 200
CPU Clock = 4Mhz => NOP = 250 ns ,Real time = 200 x 250ns = 50us */
#define SYST_Wait_SYST_50uS()   \
  SYST_WaitLoop(30);             \
   __NOP__;                     \
   __NOP__;                     \
   __NOP__;                     \
   __NOP__

 /*SYST_WaitLoop cycles = (130x6)+16)= 796 , NOP cycles = 4,Total cycles = ( 796 + 4 )= 800
CPU Clock = 4Mhz => NOP = 250 ns ,Real time = 800 x 250ns = 200us */
#define SYST_Wait_SYST_200uS()   \
  SYST_WaitLoop(130);             \
   __NOP__;                     \
   __NOP__;                     \
   __NOP__;                     \
   __NOP__

#elif SYST_FX_CLOCK == 8
/*Real time = 2.5us */
#define SYST_Wait_SYST_2_5uS()   \
  SYST_Wait_500nS();              \
  SYST_Wait_500nS();              \
  SYST_Wait_500nS();              \
  SYST_Wait_500nS();              \
  SYST_Wait_500nS()

/*SYST_WaitLoop cycles = (10x6)+16)= 76 , NOP cycles = 4,Total cycles = ( 76 + 4 )= 80
CPU Clock = 8Mhz => NOP = 125 ns ,Real time = 80 * 125ns = 10us */
#define SYST_Wait_SYST_10uS()   \
  SYST_WaitLoop(10);             \
   __NOP__;                     \
   __NOP__;                     \
   __NOP__;                     \
   __NOP__

/*SYST_WaitLoop cycles = (64x6)+16)= 400 ,
CPU Clock = 8Mhz => NOP = 125 ns ,Real time = 400 * 125ns = 50us */
#define SYST_Wait_SYST_50uS()   \
  SYST_WaitLoop(64)

/*SYST_WaitLoop cycles = (264x6)+16)= 1600 ,
CPU Clock = 8Mhz => NOP = 125 ns ,Real time = 1600 * 125ns = 200us */
#define SYST_Wait_SYST_200uS()   \
  SYST_WaitLoop(264)

#elif SYST_FX_CLOCK == 12
/*SYST_WaitLoop cycles = (2x6)+16)= 28 , NOP cycles = 2,Total cycles = ( 28 + 2 )= 30
CPU Clock = 12Mhz => NOP = 83.33 ns ,Real time = 30 * 83.33ns = 2.5us */
#define SYST_Wait_SYST_2_5uS()   \
  SYST_WaitLoop(2);               \
  __NOP__;                       \
  __NOP__

/*SYST_WaitLoop cycles = (17x6)+16)= 118 , NOP cycles = 2,Total cycles = ( 118 + 2 )= 120
CPU Clock = 12Mhz => NOP = 83.33 ns ,Real time = 120 * 83.33ns = 10us */
#define SYST_Wait_SYST_10uS()   \
  SYST_WaitLoop(17);             \
  __NOP__;                      \
  __NOP__

/*SYST_WaitLoop cycles = (97x6)+16)= 598 , NOP cycles = 2,Total cycles = ( 598 + 2 )=600
CPU Clock = 12Mhz => NOP = 83.33 ns ,Real time = 600 * 83.33ns = 50us */
#define SYST_Wait_SYST_50uS()   \
  SYST_WaitLoop(97);             \
  __NOP__;                      \
  __NOP__

/*SYST_WaitLoop cycles = (397x6)+16)= 2398 , NOP cycles = 2,Total cycles = ( 2398 + 2 )= 2400
CPU Clock = 12Mhz => NOP = 83.33 ns ,Real time = 2400 * 83.33ns = 200us */
#define SYST_Wait_SYST_200uS()   \
  SYST_WaitLoop(397);             \
  __NOP__;                      \
  __NOP__

#elif SYST_FX_CLOCK == 16
/*SYST_WaitLoop cycles = (4x6)+16)= 40 ,
CPU Clock = 16Mhz => NOP = 62.5ns ,Real time = 40 * 62.5ns = 2.5us */
#define SYST_Wait_SYST_2_5uS()   \
  SYST_WaitLoop(4)

/*SYST_WaitLoop cycles = (24x6)+16)= 160
CPU Clock = 16Mhz => NOP = 62.5 ns ,Real time = 160 * 62.5ns = 10us */
#define SYST_Wait_SYST_10uS()   \
  SYST_WaitLoop(24)

/*SYST_WaitLoop cycles = (130x6)+16)= 796, NOP cycles = 4,Total cycles = ( 796 + 4)= 800
CPU Clock = 16Mhz => NOP = 62.5ns ,Real time = 800 * 62.5ns = 50us */
#define SYST_Wait_SYST_50uS()   \
  SYST_WaitLoop(130);            \
  __NOP__;                      \
  __NOP__;                      \
  __NOP__;                      \
  __NOP__

/*SYST_WaitLoop cycles = (530x6)+16)= 3196, NOP cycles = 4,Total cycles = ( 3196 + 4)= 3200
CPU Clock = 16Mhz => NOP = 62.5ns ,Real time = 3200 * 62.5ns = 200us */
#define SYST_Wait_SYST_200uS()   \
  SYST_WaitLoop(530);            \
  __NOP__;                      \
  __NOP__;                      \
  __NOP__;                      \
  __NOP__

#elif SYST_FX_CLOCK == 20
/*SYST_WaitLoop cycles = (5x6)+16)= 46, NOP cycles = 4,Total cycles = ( 46 + 4)= 50
CPU Clock = 20hz => NOP = 50ns ,Real time = 50 * 50ns = 2.5us */
#define SYST_Wait_SYST_2_5uS()   \
  SYST_WaitLoop(5);              \
  __NOP__;                      \
  __NOP__;                      \
  __NOP__;                      \
  __NOP__

/*SYST_WaitLoop cycles = (30x6)+16)= 196, NOP cycles = 4,Total cycles = ( 196 + 4)= 200
CPU Clock = 20hz => NOP = 50ns ,Real time = 200 * 50ns = 10us */
#define SYST_Wait_SYST_10uS()   \
  SYST_WaitLoop(30);             \
  __NOP__;                      \
  __NOP__;                      \
  __NOP__;                      \
  __NOP__

/*SYST_WaitLoop cycles = (164x6)+16)=1000,
CPU Clock = 20hz => NOP = 50ns ,Real time = 1000 * 50ns = 50us */
#define SYST_Wait_SYST_50uS()   \
  SYST_WaitLoop(164)

/*SYST_WaitLoop cycles = (664x6)+16)=4000,
CPU Clock = 20hz => NOP = 50ns ,Real time = 4000 * 50ns = 200us */
#define SYST_Wait_SYST_200uS()   \
  SYST_WaitLoop(664)

#elif SYST_FX_CLOCK == 24
/*SYST_WaitLoop cycles = (7x6)+16)= 58, NOP cycles = 2,Total cycles = ( 58 + 2)= 60
CPU Clock = 24hz => NOP = 41.67ns ,Real time = 60* 41.66ns = 2.5us */
#define SYST_Wait_SYST_2_5uS()   \
  SYST_WaitLoop(7);               \
  __NOP__;                       \
  __NOP__

/*SYST_WaitLoop cycles = (37x6)+16)= 238, NOP cycles = 2,Total cycles = ( 238+ 2)= 240
CPU Clock = 24hz => NOP = 41.67ns ,Real time = 240* 41.66ns = 10us */
#define SYST_Wait_SYST_10uS()   \
  SYST_WaitLoop(37);             \
  __NOP__;                      \
  __NOP__

/*SYST_WaitLoop cycles = (197x6)+16)= 1198, NOP cycles = 2,Total cycles = ( 1198 + 2)= 1200
CPU Clock = 24hz => NOP = 41.67ns ,Real time = 1200* 41.66ns = 50us */
#define SYST_Wait_SYST_50uS()   \
  SYST_WaitLoop(197);            \
  __NOP__;                      \
  __NOP__

/*SYST_WaitLoop cycles = (797x6)+16)= 4798, NOP cycles = 2,Total cycles = ( 4798 + 2)= 4800
CPU Clock = 24hz => NOP = 41.67ns ,Real time = 4800 * 41.66ns = 200us */
#define SYST_Wait_SYST_200uS()   \
  SYST_WaitLoop(797);             \
  __NOP__;                       \
  __NOP__

#elif SYST_FX_CLOCK == 32
/*SYST_WaitLoop cycles = (10x6)+16)= 76, NOP cycles = 4,Total cycles = ( 76 + 4)= 80
CPU Clock = 32hz => NOP = 31.25ns ,Real time = 80* 41.66ns = 2.5us */
#define SYST_Wait_SYST_2_5uS()   \
  SYST_WaitLoop(10);              \
  __NOP__;                       \
  __NOP__;                       \
  __NOP__;                       \
  __NOP__

/*SYST_WaitLoop cycles = (50x6)+16)= 316, NOP cycles = 4,Total cycles = ( 316 + 4)= 320
CPU Clock = 32hz => NOP = 31.25ns ,Real time = 320* 41.66ns = 10us */
#define SYST_Wait_SYST_10uS()   \
  SYST_WaitLoop(50);             \
  __NOP__;                      \
  __NOP__;                      \
  __NOP__;                      \
  __NOP__

/*SYST_WaitLoop cycles = (264x6)+16)= 1600,
CPU Clock = 32hz => NOP = 31.25ns ,Real time = 1600 * 41.66ns = 50us */
#define SYST_Wait_SYST_50uS()   \
  SYST_WaitLoop(264)

/*SYST_WaitLoop cycles = (1064x6)+16)= 6400,
CPU Clock = 32hz => NOP = 31.25ns ,Real time = 6400 * 41.66ns = 200us */
#define SYST_Wait_SYST_200uS()  \
  SYST_WaitLoop(1064)
#else
#error please define a correct SYST_FX_CLOCK for RL78!!!
#endif

#endif /*__REL_RL78_D1A__ || __REL_RL78_F12__*/
#endif /*__REL_RL78_D1x__ || __REL_RL78_F1x__*/
#endif  /* __REL_RL8__ */

/* Syst_Wait: MC9S12H, MC9S12HZ */
#if defined(__MC9S12H__)  || \
    defined(__MC9S12HZ__)
/* 16 MHz -> 62.5ns */

#define  SYST_Wait_SYST_250nS() \
         {                      \
           _asm("  nop");       \
           _asm("  nop");       \
           _asm("  nop");       \
           _asm("  nop");       \
         }
/* 4 nop */

#define  SYST_Wait_SYST_500nS() \
         SYST_Wait_SYST_250nS();\
         SYST_Wait_SYST_250nS()
/* 8 nop */

#define  SYST_Wait_SYST_2_5uS() \
         SYST_Wait_SYST_500nS();\
         SYST_Wait_SYST_500nS();\
         SYST_Wait_SYST_500nS();\
         SYST_Wait_SYST_500nS();\
         SYST_Wait_SYST_500nS()
/* 40 nop */

/* for time > 2.5us use function instead of nop to save ROM size */

#define  SYST_Wait_SYST_3uS() \
         SYST_WaitLoop(2)

#define  SYST_Wait_SYST_4uS() \
         SYST_WaitLoop(4)

#define  SYST_Wait_SYST_4_7uS() \
         SYST_WaitLoop(5);      \
         SYST_Wait_SYST_250nS()

#define  SYST_Wait_SYST_5uS() \
         SYST_WaitLoop(6)

#define  SYST_Wait_SYST_20uS() \
         SYST_WaitLoop(36)

#define  SYST_Wait_SYST_25uS() \
         SYST_WaitLoop(46)

#define  SYST_Wait_SYST_50uS() \
         SYST_WaitLoop(96)

#define  SYST_Wait_SYST_100uS() \
         SYST_WaitLoop(196)

#define  SYST_Wait_SYST_200uS() \
         SYST_WaitLoop(396)

#endif /* __MC9S12H__  || __MC9S12HZ__ */

/* Syst_Wait: MC9S12XHZ */
#ifdef __MC9S12XHZ__
/* 32 MHz -> 31.25ns */

#define  SYST_Wait_SYST_250nS() \
         {                      \
           _asm("  nop");       \
           _asm("  nop");       \
           _asm("  nop");       \
           _asm("  nop");       \
           _asm("  nop");       \
           _asm("  nop");       \
           _asm("  nop");       \
           _asm("  nop");       \
         }
/* 8 nop */

#define  SYST_Wait_SYST_500nS() \
         SYST_Wait_SYST_250nS();\
         SYST_Wait_SYST_250nS()
/* 16 nop */

#define  SYST_Wait_SYST_2_5uS() \
         SYST_Wait_SYST_500nS();\
         SYST_Wait_SYST_500nS();\
         SYST_Wait_SYST_500nS();\
         SYST_Wait_SYST_500nS();\
         SYST_Wait_SYST_500nS()
/* 80 nop */

/* for time > 2.5us use function instead of nop to save ROM size */

#define  SYST_Wait_SYST_3uS() \
         SYST_WaitLoop(4);    \
         SYST_Wait_SYST_250nS()

#define  SYST_Wait_SYST_4uS() \
         SYST_WaitLoop(7)

#define  SYST_Wait_SYST_4_7uS() \
         SYST_WaitLoop(8);      \
         SYST_Wait_SYST_250nS()

#define  SYST_Wait_SYST_5uS() \
         SYST_WaitLoop(9)

#define  SYST_Wait_SYST_20uS() \
         SYST_WaitLoop(43);    \
         {                     \
           _asm("  nop");      \
           _asm("  nop");      \
           _asm("  nop");      \
           _asm("  nop");      \
           _asm("  nop");      \
           _asm("  nop");      \
         }

#define  SYST_Wait_SYST_25uS() \
         SYST_WaitLoop(55)

#define  SYST_Wait_SYST_50uS() \
         SYST_WaitLoop(112)

#define  SYST_Wait_SYST_100uS() \
         SYST_WaitLoop(226);    \
         {                      \
           _asm("  nop");       \
           _asm("  nop");       \
           _asm("  nop");       \
           _asm("  nop");       \
         }

#define  SYST_Wait_SYST_200uS() \
         SYST_WaitLoop(455)

#endif /* __MC9S12XHZ__ */

/* Syst_Wait: MC9S08xx */
#ifdef __MC9S08xx__
/* Max ?? MHz, set to 8388608 Hz */
/* CPU Clock = 8388608 Hz => NOP = 119.209 ns*/

/* Caution if you change CPU Clock, All delay have to be recomputed !!!! */

/* real = 238ns */
/* Caution if you change CPU Clock, All delay have to be recomputed !!!! */
#define  SYST_Wait_SYST_250nS() \
         {                      \
           _asm("  nop");       \
           _asm("  nop");       \
         }
/* real = 477ns */
#define  SYST_Wait_SYST_500nS() \
         SYST_Wait_SYST_250nS();\
         SYST_Wait_SYST_250nS()
/* 4 nop */

#define  SYST_Wait_SYST_2_5uS() \
         SYST_Wait_SYST_500nS();\
         SYST_Wait_SYST_500nS();\
         SYST_Wait_SYST_500nS();\
         SYST_Wait_SYST_500nS();\
         SYST_Wait_SYST_500nS();\
         _asm("  nop")
/* 21 nop */

#define  SYST_Wait_SYST_3uS()   \
         SYST_Wait_SYST_2_5uS();\
         SYST_Wait_SYST_500nS();\
         _asm("  nop")
/* 26 nop */

#define  SYST_Wait_SYST_4uS()   \
         SYST_Wait_SYST_3uS();  \
         SYST_Wait_SYST_500nS();\
         SYST_Wait_SYST_500nS()
/* 34 nop */

#define  SYST_Wait_SYST_4_7uS() \
         SYST_Wait_SYST_4uS();  \
         SYST_Wait_SYST_500nS();\
         SYST_Wait_SYST_250nS()
/* 40 nop */

#define  SYST_Wait_SYST_5uS()   \
         SYST_Wait_SYST_4uS();  \
         SYST_Wait_SYST_500nS();\
         SYST_Wait_SYST_500nS()
/* 42 nop */

/* for time > 5us use function instead of nop to save ROM size */

/* Real time =    20,027 us */
#define  SYST_Wait_SYST_20uS() \
         SYST_WaitLoop(5);     \
         _asm("  nop")

/* Real time =    25,630 us */
#define  SYST_Wait_SYST_25uS() \
         SYST_WaitLoop(7)

/* Real time =    49,949 us */
#define  SYST_Wait_SYST_50uS()  \
         SYST_WaitLoop(15);     \
         SYST_Wait_SYST_500nS();\
         SYST_Wait_SYST_500nS();\
         SYST_Wait_SYST_500nS()

/* Real time =   100,02 us */
#define  SYST_Wait_SYST_100uS() \
         SYST_WaitLoop(33)

/* Real time =   200,15 us */
#define  SYST_Wait_SYST_200uS() \
         SYST_WaitLoop(68)

/* Real time =  5000,95 us */
#define  SYST_Wait_SYST_5mS() \
         SYST_WaitLoop(1746)

#endif /* __MC9S08xx__ */

/* Syst_Wait: TX4962 */
#ifdef __TX4962__
/* 120 MHz -> 8.3ns */

#define  SYST_Wait_SYST_8_3nS() \
         {                      \
           __NOP__;             \
         }
/* 1 nop */

#define  SYST_Wait_SYST_25nS()     \
         {                         \
           SYST_Wait_SYST_8_3nS(); \
           SYST_Wait_SYST_8_3nS(); \
           SYST_Wait_SYST_8_3nS(); \
         }
/* 3 nop */

#define  SYST_Wait_SYST_50nS()    \
         {                        \
           SYST_Wait_SYST_25nS(); \
           SYST_Wait_SYST_25nS(); \
         }
/* 6 nop */

#define  SYST_Wait_SYST_100nS()   \
         {                        \
           SYST_Wait_SYST_50nS(); \
           SYST_Wait_SYST_50nS(); \
         }
/* 12 nop */

#define  SYST_Wait_SYST_250nS()    \
         {                         \
           SYST_Wait_SYST_100nS(); \
           SYST_Wait_SYST_100nS(); \
           SYST_Wait_SYST_50nS();  \
         }
/* 30 nop */

#define  SYST_Wait_SYST_300nS()    \
         {                         \
           SYST_Wait_SYST_100nS(); \
           SYST_Wait_SYST_100nS(); \
           SYST_Wait_SYST_100nS(); \
         }
/* 36 nop */

#define  SYST_Wait_SYST_500nS()    \
         {                         \
           SYST_Wait_SYST_250nS(); \
           SYST_Wait_SYST_250nS(); \
         }
/* 60 nop */

/* for time > 500ns use function instead of nop to save ROM size */

#define  SYST_Wait_SYST_1500nS() \
         SYST_WaitLoop(19)

#define  SYST_Wait_SYST_2_5uS() \
         SYST_WaitLoop(49)

#define  SYST_Wait_SYST_3uS() \
         SYST_WaitLoop(64)

#define  SYST_Wait_SYST_4uS() \
         SYST_WaitLoop(94)

#define  SYST_Wait_SYST_4_7uS() \
         SYST_WaitLoop(115)

#define  SYST_Wait_SYST_5uS() \
         SYST_WaitLoop(125)

#define  SYST_Wait_SYST_6uS() \
         SYST_WaitLoop(155)

#define  SYST_Wait_SYST_20uS() \
         SYST_WaitLoop(576)

#define  SYST_Wait_SYST_25uS() \
         SYST_WaitLoop(727)

#define  SYST_Wait_SYST_50uS() \
         SYST_WaitLoop(1480)

#define  SYST_Wait_SYST_100uS() \
         SYST_WaitLoop(2986)

#define  SYST_Wait_SYST_200uS() \
         SYST_WaitLoop(5598)

#endif /* __TX4962__ */

/* Syst_Wait: TX4964 */
#ifdef __TX4964__
/* 60 MHz -> 16.7ns */

#define  SYST_Wait_SYST_50nS()     \
         {                         \
           SYST_Wait_SYST_8_3nS(); \
           SYST_Wait_SYST_8_3nS(); \
           SYST_Wait_SYST_8_3nS(); \
         }
/* 3 nop */

#define  SYST_Wait_SYST_100nS()   \
         {                        \
           SYST_Wait_SYST_50nS(); \
           SYST_Wait_SYST_50nS(); \
         }
/* 6 nop */

#define  SYST_Wait_SYST_250nS()    \
         {                         \
           SYST_Wait_SYST_100nS(); \
           SYST_Wait_SYST_100nS(); \
           SYST_Wait_SYST_50nS();  \
         }
/* 15 nop */

#define  SYST_Wait_SYST_300nS()    \
         {                         \
           SYST_Wait_SYST_100nS(); \
           SYST_Wait_SYST_100nS(); \
           SYST_Wait_SYST_100nS(); \
         }
/* 18 nop */

#define  SYST_Wait_SYST_500nS()    \
         {                         \
           SYST_Wait_SYST_250nS(); \
           SYST_Wait_SYST_250nS(); \
         }
/* 30 nop */

#define  SYST_Wait_SYST_1500nS()   \
         {                         \
           SYST_Wait_SYST_500nS(); \
           SYST_Wait_SYST_500nS(); \
           SYST_Wait_SYST_500nS(); \
         }
/* 150 nop */

#define  SYST_Wait_SYST_2_5uS() \
         SYST_WaitLoop(11)

#define  SYST_Wait_SYST_3uS() \
         SYST_WaitLoop(19)

#define  SYST_Wait_SYST_4uS() \
         SYST_WaitLoop(34)

#define  SYST_Wait_SYST_4_7uS() \
         SYST_WaitLoop(44)

#define  SYST_Wait_SYST_5uS() \
         SYST_WaitLoop(49)

#define  SYST_Wait_SYST_6uS() \
         SYST_WaitLoop(64)

#define  SYST_Wait_SYST_20uS() \
         SYST_WaitLoop(274)

#define  SYST_Wait_SYST_25uS() \
         SYST_WaitLoop(349)

#define  SYST_Wait_SYST_50uS() \
         SYST_WaitLoop(724)

#define  SYST_Wait_SYST_100uS() \
         SYST_WaitLoop(1474)

#define  SYST_Wait_SYST_200uS() \
         SYST_WaitLoop(2974)

#endif /* __TX4964__ */

#if (defined __NEC_V850__)
#ifdef C_COMP_GHS_V850E2V3
#if SYST_FX_CLOCK == 40
/* CPU Clock = 40 MHz => NOP = 25 ns */

#define  SYST_Wait_SYST_25nS()   \
         {                       \
           asm("nop");           \
         }

#define  SYST_Wait_SYST_50nS()   \
         {                       \
           asm("nop");           \
           asm("nop");           \
         }

#define  SYST_Wait_SYST_75nS()   \
         {                       \
           asm("nop");           \
           asm("nop");           \
           asm("nop");           \
         }

#define  SYST_Wait_SYST_100nS()  \
         SYST_Wait_SYST_50nS();  \
         SYST_Wait_SYST_50nS()

#define  SYST_Wait_SYST_200nS()  \
         SYST_Wait_SYST_100nS(); \
         SYST_Wait_SYST_100nS()

#define  SYST_Wait_SYST_250nS()  \
         SYST_Wait_SYST_200nS(); \
         SYST_Wait_SYST_50nS()
/* 10 nop instructions */

#define  SYST_Wait_SYST_500nS()  \
         SYST_Wait_SYST_250nS(); \
         SYST_Wait_SYST_250nS()

#define  SYST_Wait_SYST_2_5uS()  \
         SYST_WaitLoop(16);      \
         SYST_Wait_SYST_100nS()

#define  SYST_Wait_SYST_3uS()    \
         SYST_WaitLoop(20);      \
         SYST_Wait_SYST_100nS()

#define  SYST_Wait_SYST_4uS()    \
         SYST_WaitLoop(28);      \
         SYST_Wait_SYST_100nS()

#define  SYST_Wait_SYST_4_7uS()  \
         SYST_WaitLoop(34);      \
         SYST_Wait_SYST_50nS()

#define  SYST_Wait_SYST_5uS()    \
         SYST_WaitLoop(36);      \
         SYST_Wait_SYST_100nS()

#define  SYST_Wait_SYST_20uS()   \
         SYST_WaitLoop(156);     \
         SYST_Wait_SYST_100nS()

#define  SYST_Wait_SYST_25uS()   \
         SYST_WaitLoop(196);     \
         SYST_Wait_SYST_100nS()

#define  SYST_Wait_SYST_50uS()   \
         SYST_WaitLoop(396);     \
         SYST_Wait_SYST_100nS()

#define  SYST_Wait_SYST_100uS()  \
         SYST_WaitLoop(796);     \
         SYST_Wait_SYST_100nS()

#define  SYST_Wait_SYST_200uS()  \
         SYST_WaitLoop(1596);    \
         SYST_Wait_SYST_100nS()

#elif SYST_FX_CLOCK == 48
/* CPU Clock = 48 MHz => NOP = 20.83 ns */

/* Only define for other delays */
#define  SYST_Wait_SYST_20_8nS() \
         {                       \
           asm("  nop");         \
         }
/* 1 nop */

/* Only define for other delays */
#define  SYST_Wait_SYST_41_7nS() \
         {                       \
           asm("  nop");         \
           asm("  nop");         \
         }
/* 2 nop */

/* Only define for other delays */
#define  SYST_Wait_SYST_62_5nS() \
         {                       \
           asm("  nop");         \
           asm("  nop");         \
           asm("  nop");         \
         }
/* 3 nop */

/* Only define for other delays */
#define  SYST_Wait_SYST_83_3nS() \
         SYST_Wait_SYST_41_7nS();\
         SYST_Wait_SYST_41_7nS()
/* 4 nop */

/* Only define for other delays */
#define  SYST_Wait_SYST_125nS()  \
         SYST_Wait_SYST_62_5nS();\
         SYST_Wait_SYST_62_5nS()
/* 6 nop */

#define  SYST_Wait_SYST_250nS()  \
         SYST_Wait_SYST_125nS(); \
         SYST_Wait_SYST_125nS()
/* 12 nop */

#define  SYST_Wait_SYST_500nS()  \
         SYST_Wait_SYST_250nS(); \
         SYST_Wait_SYST_250nS()
/* 24 nop */

/* for time >= 2.5us use function instead of nop to save ROM size */
/* Use function because too many nops */
#define  SYST_Wait_SYST_2_5uS()  \
         SYST_WaitLoop(13);      \
         {                       \
           asm("  nop");         \
           asm("  nop");         \
         }

#define  SYST_Wait_SYST_3uS()    \
         SYST_WaitLoop(16);      \
         {                       \
           asm("  nop");         \
         }

#define  SYST_Wait_SYST_4uS()    \
         SYST_WaitLoop(22);      \
         {                       \
           asm("  nop");         \
         }

#define  SYST_Wait_SYST_4_7uS()  \
         SYST_WaitLoop(26);      \
         {                       \
           asm("  nop");         \
           asm("  nop");         \
         }

#define  SYST_Wait_SYST_5uS()    \
         SYST_WaitLoop(28);      \
         {                       \
           asm("  nop");         \
         }

#define  SYST_Wait_SYST_20uS()   \
         SYST_WaitLoop(118);     \
         {                       \
           asm("  nop");         \
           asm("  nop");         \
         }

#define  SYST_Wait_SYST_25uS()   \
         SYST_WaitLoop(150);     \
         {                       \
           asm("  nop");         \
           asm("  nop");         \
         }

#define  SYST_Wait_SYST_50uS()   \
         SYST_WaitLoop(300);     \
         {                       \
           asm("  nop");         \
           asm("  nop");         \
           asm("  nop");         \
           asm("  nop");         \
         }

#define  SYST_Wait_SYST_100uS()  \
         SYST_WaitLoop(600);     \
         {                       \
           asm("  nop");         \
           asm("  nop");         \
           asm("  nop");         \
           asm("  nop");         \
           asm("  nop");         \
         }

#define  SYST_Wait_SYST_200uS()  \
         SYST_WaitLoop(1202);    \
         {                       \
           asm("  nop");         \
         }


#elif SYST_FX_CLOCK == 80
/* CPU Clock = 80 MHz => NOP = 12.5 ns */

#define  SYST_Wait_SYST_25nS()   \
         {                       \
           asm("nop");           \
           asm("nop");           \
         }

#define  SYST_Wait_SYST_50nS()   \
         {                       \
           asm("nop");           \
           asm("nop");           \
           asm("nop");           \
           asm("nop");           \
         }

#define  SYST_Wait_SYST_75nS()   \
         {                       \
           asm("nop");           \
           asm("nop");           \
           asm("nop");           \
           asm("nop");           \
           asm("nop");           \
           asm("nop");           \
         }

#define  SYST_Wait_SYST_100nS()  \
         SYST_Wait_SYST_50nS();  \
         SYST_Wait_SYST_50nS();

#define  SYST_Wait_SYST_200nS()  \
         SYST_Wait_SYST_100nS(); \
         SYST_Wait_SYST_100nS();

#define  SYST_Wait_SYST_250nS()  \
         SYST_Wait_SYST_200nS(); \
         SYST_Wait_SYST_50nS();
/* 10 nop instructions */


#define  SYST_Wait_SYST_500nS()  \
         SYST_Wait_SYST_250nS(); \
         SYST_Wait_SYST_250nS();

#define  SYST_Wait_SYST_2_5uS()  \
         SYST_WaitLoop(23);

#define  SYST_Wait_SYST_3uS()    \
         SYST_WaitLoop(29);

#define  SYST_Wait_SYST_4uS()    \
         SYST_WaitLoop(39);

#define  SYST_Wait_SYST_4_7uS()  \
         SYST_WaitLoop(45);

#define  SYST_Wait_SYST_5uS()    \
         SYST_WaitLoop(52);

#define  SYST_Wait_SYST_20uS()   \
         SYST_WaitLoop(208);

#define  SYST_Wait_SYST_25uS()   \
         SYST_WaitLoop(260);

#define  SYST_Wait_SYST_50uS()   \
         SYST_WaitLoop(520);

#define  SYST_Wait_SYST_100uS()  \
         SYST_WaitLoop(1040);

#define  SYST_Wait_SYST_200uS()  \
         SYST_WaitLoop(2080);

#elif SYST_FX_CLOCK == 120
/* CPU Clock = 120 MHz => NOP = 8.4 ns */

#define  SYST_Wait_SYST_25nS()   \
         {                       \
           asm("nop");           \
           asm("nop");           \
           asm("nop");           \
         }

#define  SYST_Wait_SYST_50nS()   \
         {                       \
           asm("nop");           \
           asm("nop");           \
           asm("nop");           \
           asm("nop");           \
           asm("nop");           \
           asm("nop");           \
         }

#define  SYST_Wait_SYST_75nS()   \
         {                       \
           asm("nop");           \
           asm("nop");           \
           asm("nop");           \
           asm("nop");           \
           asm("nop");           \
           asm("nop");           \
           asm("nop");           \
           asm("nop");           \
           asm("nop");           \
         }

#define  SYST_Wait_SYST_100nS()  \
         SYST_Wait_SYST_50nS();  \
         SYST_Wait_SYST_50nS();

#define  SYST_Wait_SYST_200nS()  \
         SYST_Wait_SYST_100nS(); \
         SYST_Wait_SYST_100nS();

#define  SYST_Wait_SYST_250nS()  \
         SYST_Wait_SYST_200nS(); \
         SYST_Wait_SYST_50nS();


#define  SYST_Wait_SYST_500nS()  \
         SYST_Wait_SYST_250nS(); \
         SYST_Wait_SYST_250nS();

#define  SYST_Wait_SYST_2_5uS()  \
         SYST_WaitLoop(35);

#define  SYST_Wait_SYST_3uS()    \
         SYST_WaitLoop(43);

#define  SYST_Wait_SYST_4uS()    \
         SYST_WaitLoop(59);

#define  SYST_Wait_SYST_4_7uS()  \
         SYST_WaitLoop(68);

#define  SYST_Wait_SYST_5uS()    \
         SYST_WaitLoop(78);

#define  SYST_Wait_SYST_20uS()   \
         SYST_WaitLoop(312);

#define  SYST_Wait_SYST_25uS()   \
         SYST_WaitLoop(390);

#define  SYST_Wait_SYST_50uS()   \
         SYST_WaitLoop(780);

#define  SYST_Wait_SYST_100uS()  \
         SYST_WaitLoop(1560);

#define  SYST_Wait_SYST_200uS()  \
         SYST_WaitLoop(3120);

#elif SYST_FX_CLOCK == 160
/* CPU Clock = 160 MHz => NOP = 6.25 ns */

#define  SYST_Wait_SYST_25nS()   \
         {                       \
           asm("nop");           \
           asm("nop");           \
           asm("nop");           \
           asm("nop");           \
         }

#define  SYST_Wait_SYST_50nS()   \
         {                       \
           asm("nop");           \
           asm("nop");           \
           asm("nop");           \
           asm("nop");           \
           asm("nop");           \
           asm("nop");           \
           asm("nop");           \
           asm("nop");           \
         }

#define  SYST_Wait_SYST_75nS()   \
         {                       \
           asm("nop");           \
           asm("nop");           \
           asm("nop");           \
           asm("nop");           \
           asm("nop");           \
           asm("nop");           \
           asm("nop");           \
           asm("nop");           \
           asm("nop");           \
           asm("nop");           \
           asm("nop");           \
           asm("nop");           \
         }

#define  SYST_Wait_SYST_100nS()  \
         SYST_Wait_SYST_50nS();  \
         SYST_Wait_SYST_50nS();

#define  SYST_Wait_SYST_200nS()  \
         SYST_Wait_SYST_100nS(); \
         SYST_Wait_SYST_100nS();

#define  SYST_Wait_SYST_250nS()  \
         SYST_Wait_SYST_200nS(); \
         SYST_Wait_SYST_50nS();

#define  SYST_Wait_SYST_500nS()  \
         SYST_Wait_SYST_250nS(); \
         SYST_Wait_SYST_250nS();

#define  SYST_Wait_SYST_2_5uS()  \
         SYST_WaitLoop(46);

#define  SYST_Wait_SYST_3uS()    \
         SYST_WaitLoop(58);

#define  SYST_Wait_SYST_4uS()    \
         SYST_WaitLoop(78);

#define  SYST_Wait_SYST_4_7uS()  \
         SYST_WaitLoop(90);

#define  SYST_Wait_SYST_5uS()    \
         SYST_WaitLoop(104);

#define  SYST_Wait_SYST_20uS()   \
         SYST_WaitLoop(408);

#define  SYST_Wait_SYST_25uS()   \
         SYST_WaitLoop(520);

#define  SYST_Wait_SYST_50uS()   \
         SYST_WaitLoop(1040);

#define  SYST_Wait_SYST_100uS()  \
         SYST_WaitLoop(2080);

#define  SYST_Wait_SYST_200uS()  \
         SYST_WaitLoop(4160);


#else
#error please define a correct SYST_FX_CLOCK for V850 !!!
#endif /* SYST_FX_CLOCK == 40 */

#else

#if (defined(C_COMP_GHS_V850E1) || defined(C_COMP_GHS_V850ES))

#if SYST_FX_CLOCK == 16
/* CPU Clock = 16 MHz => NOP = 62.5 ns */

#define  SYST_Wait_SYST_250nS() \
         {                      \
           asm("  nop");        \
           asm("  nop");        \
           asm("  nop");        \
           asm("  nop");        \
         }
/* 4 nop */

#define  SYST_Wait_SYST_500nS() \
         SYST_Wait_SYST_250nS();\
         SYST_Wait_SYST_250nS()
/* 8 nop */

#define  SYST_Wait_SYST_2_5uS() \
         SYST_Wait_SYST_500nS();\
         SYST_Wait_SYST_500nS();\
         SYST_Wait_SYST_500nS();\
         SYST_Wait_SYST_500nS();\
         SYST_Wait_SYST_500nS()
/* 40 nop */

/* for time > 2.5us use function instead of nop to save ROM size */

#define  SYST_Wait_SYST_3uS()   \
         SYST_WaitLoop(7);      \
         Syst_AddForLoop()

#define  SYST_Wait_SYST_4uS()   \
         SYST_WaitLoop(10);     \
         {                      \
           asm("  nop");        \
         }

#define  SYST_Wait_SYST_4_7uS() \
         SYST_WaitLoop(12);     \
         {                      \
           asm("  nop");        \
           asm("  nop");        \
         }

#define  SYST_Wait_SYST_5uS()   \
         SYST_WaitLoop(13);     \
         {                      \
           asm("  nop");        \
           asm("  nop");        \
         }

#define  SYST_Wait_SYST_20uS()  \
         SYST_WaitLoop(61);     \
         {                      \
           asm("  nop");        \
           asm("  nop");        \
         }

#define  SYST_Wait_SYST_25uS()  \
         SYST_WaitLoop(77);     \
         {                      \
           asm("  nop");        \
           asm("  nop");        \
         }

#define  SYST_Wait_SYST_50uS()  \
         SYST_WaitLoop(157);    \
         {                      \
           asm("  nop");        \
           asm("  nop");        \
         }

#define  SYST_Wait_SYST_100uS() \
         SYST_WaitLoop(317);    \
         {                      \
           asm("  nop");        \
           asm("  nop");        \
         }

#define  SYST_Wait_SYST_200uS() \
         SYST_WaitLoop(637);    \
         {                      \
           asm("  nop");        \
           asm("  nop");        \
         }

#else

#if SYST_FX_CLOCK == 20
/* CPU Clock = 20 MHz => NOP = 50 ns*/

#define  SYST_Wait_SYST_250nS() \
         {                      \
           asm("  nop");        \
           asm("  nop");        \
           asm("  nop");        \
           asm("  nop");        \
           asm("  nop");        \
         }
/* 5 nop */

#define  SYST_Wait_SYST_500nS() \
         SYST_Wait_SYST_250nS();\
         SYST_Wait_SYST_250nS()
/* 10 nop */

#define  SYST_Wait_SYST_2_5uS() \
         SYST_Wait_SYST_500nS();\
         SYST_Wait_SYST_500nS();\
         SYST_Wait_SYST_500nS();\
         SYST_Wait_SYST_500nS();\
         SYST_Wait_SYST_500nS()
/* 50 nop */

/* for time > 2.5us use function instead of nop to save ROM size */

#define  SYST_Wait_SYST_3uS() \
         SYST_WaitLoop(9);    \
         {                    \
           asm("  nop");      \
           asm("  nop");      \
         }

#define  SYST_Wait_SYST_4uS() \
         SYST_WaitLoop(13);   \
         {                    \
           asm("  nop");      \
           asm("  nop");      \
         }

#define  SYST_Wait_SYST_4_7uS() \
         SYST_WaitLoop(16);     \
         {                      \
           asm("  nop");        \
         }

#define  SYST_Wait_SYST_5uS() \
         SYST_WaitLoop(17);   \
         {                    \
           asm("  nop");      \
           asm("  nop");      \
         }

#define  SYST_Wait_SYST_20uS() \
         SYST_WaitLoop(77);    \
         {                     \
           asm("  nop");       \
           asm("  nop");       \
         }

#define  SYST_Wait_SYST_25uS() \
         SYST_WaitLoop(97);    \
         {                     \
           asm("  nop");       \
           asm("  nop");       \
         }

#define  SYST_Wait_SYST_50uS() \
         SYST_WaitLoop(197);   \
         {                     \
           asm("  nop");       \
           asm("  nop");       \
         }

#define  SYST_Wait_SYST_100uS() \
         SYST_WaitLoop(397);    \
         {                     \
           asm("  nop");       \
           asm("  nop");       \
         }

#define  SYST_Wait_SYST_200uS() \
         SYST_WaitLoop(797);   \
         {                     \
           asm("  nop");       \
           asm("  nop");       \
         }

#else

#if SYST_FX_CLOCK == 32
/* CPU Clock = 32 MHz => NOP = 31.25 ns */

#define  SYST_Wait_SYST_250nS() \
         {                      \
           asm("  nop");        \
           asm("  nop");        \
           asm("  nop");        \
           asm("  nop");        \
           asm("  nop");        \
           asm("  nop");        \
           asm("  nop");        \
           asm("  nop");        \
         }
/* 8 nop */

#define  SYST_Wait_SYST_500nS() \
         SYST_Wait_SYST_250nS();\
         SYST_Wait_SYST_250nS()
/* 16 nop */

/* for time >= 2.5us use function instead of nop to save ROM size */

#define  SYST_Wait_SYST_2_5uS()\
         SYST_WaitLoop(13);    \
         {                     \
           asm("  nop");       \
           asm("  nop");       \
         }

#define  SYST_Wait_SYST_3uS()  \
         SYST_WaitLoop(16);    \
         {                     \
           asm("  nop");       \
           asm("  nop");       \
           asm("  nop");       \
         }

#define  SYST_Wait_SYST_4uS()  \
         SYST_WaitLoop(23);

#define  SYST_Wait_SYST_4_7uS()\
         SYST_WaitLoop(27);    \
         {                     \
           asm("  nop");       \
           asm("  nop");       \
         }

#define  SYST_Wait_SYST_5uS()  \
         SYST_WaitLoop(29);    \
         {                     \
           asm("  nop");       \
           asm("  nop");       \
         }

#define  SYST_Wait_SYST_20uS() \
         SYST_WaitLoop(125);   \
         {                     \
           asm("  nop");       \
           asm("  nop");       \
         }

#define  SYST_Wait_SYST_25uS() \
         SYST_WaitLoop(157);   \
         {                     \
           asm("  nop");       \
           asm("  nop");       \
         }

#define  SYST_Wait_SYST_50uS() \
         SYST_WaitLoop(317);   \
         {                     \
           asm("  nop");       \
           asm("  nop");       \
         }

#define  SYST_Wait_SYST_100uS() \
         SYST_WaitLoop(637);    \
         {                      \
           asm("  nop");        \
           asm("  nop");        \
         }

#define  SYST_Wait_SYST_200uS() \
         SYST_WaitLoop(1277);   \
         {                      \
           asm("  nop");        \
           asm("  nop");        \
         }

#else

#if SYST_FX_CLOCK == 40
/* CPU Clock = 40 Mhz => NOP = 25 ns */

#define  SYST_Wait_SYST_25nS()   \
         {                       \
           asm("nop");           \
         }

#define  SYST_Wait_SYST_50nS()   \
         {                       \
           asm("nop");           \
           asm("nop");           \
         }

#define  SYST_Wait_SYST_75nS()   \
         {                       \
           asm("nop");           \
           asm("nop");           \
           asm("nop");           \
         }

#define  SYST_Wait_SYST_100nS()  \
         SYST_Wait_SYST_50nS();  \
         SYST_Wait_SYST_50nS()

#define  SYST_Wait_SYST_200nS()  \
         SYST_Wait_SYST_100nS(); \
         SYST_Wait_SYST_100nS()

#define  SYST_Wait_SYST_250nS()  \
         SYST_Wait_SYST_200nS(); \
         SYST_Wait_SYST_50nS()
/* 10 nop instructions */

#define  SYST_Wait_SYST_500nS()  \
         SYST_Wait_SYST_250nS(); \
         SYST_Wait_SYST_250nS()

#define  SYST_Wait_SYST_2_5uS()  \
         SYST_WaitLoop(17);      \
         SYST_Wait_SYST_50nS()

#define  SYST_Wait_SYST_3uS()    \
         SYST_WaitLoop(21);      \
         SYST_Wait_SYST_50nS()

#define  SYST_Wait_SYST_4uS()    \
         SYST_WaitLoop(29);      \
         SYST_Wait_SYST_50nS()

#define  SYST_Wait_SYST_4_7uS()  \
         SYST_WaitLoop(35)

#define  SYST_Wait_SYST_5uS()    \
         SYST_WaitLoop(37);      \
         SYST_Wait_SYST_50nS()

#define  SYST_Wait_SYST_20uS()   \
         SYST_WaitLoop(157);     \
         SYST_Wait_SYST_50nS()

#define  SYST_Wait_SYST_25uS()   \
         SYST_WaitLoop(197);     \
         SYST_Wait_SYST_50nS()

#define  SYST_Wait_SYST_50uS()   \
         SYST_WaitLoop(397);     \
         SYST_Wait_SYST_50nS()

#define  SYST_Wait_SYST_100uS()  \
         SYST_WaitLoop(797);     \
         SYST_Wait_SYST_50nS()

#define  SYST_Wait_SYST_200uS()  \
         SYST_WaitLoop(1597);    \
         SYST_Wait_SYST_50nS()

#else

#if SYST_FX_CLOCK == 48
/* CPU Clock = 48 MHz => NOP = 20.83 ns */

/* Only define for other delays */
#define  SYST_Wait_SYST_20_8nS() \
         {                       \
           asm("  nop");         \
         }
/* 1 nop */

/* Only define for other delays */
#define  SYST_Wait_SYST_41_7nS() \
         {                       \
           asm("  nop");         \
           asm("  nop");         \
         }
/* 2 nop */

/* Only define for other delays */
#define  SYST_Wait_SYST_62_5nS() \
         {                       \
           asm("  nop");         \
           asm("  nop");         \
           asm("  nop");         \
         }
/* 3 nop */

/* Only define for other delays */
#define  SYST_Wait_SYST_83_3nS() \
         SYST_Wait_SYST_41_7nS();\
         SYST_Wait_SYST_41_7nS()
/* 4 nop */

/* Only define for other delays */
#define  SYST_Wait_SYST_125nS()  \
         SYST_Wait_SYST_62_5nS();\
         SYST_Wait_SYST_62_5nS()
/* 6 nop */

#define  SYST_Wait_SYST_250nS()  \
         SYST_Wait_SYST_125nS(); \
         SYST_Wait_SYST_125nS()
/* 12 nop */

#define  SYST_Wait_SYST_500nS()  \
         SYST_Wait_SYST_250nS(); \
         SYST_Wait_SYST_250nS()
/* 24 nop */

/* for time >= 2.5us use function instead of nop to save ROM size */
/* Use function because too many nops */
#define  SYST_Wait_SYST_2_5uS()  \
         SYST_WaitLoop(21);      \
         {                       \
           asm("  nop");         \
           asm("  nop");         \
         }

#define  SYST_Wait_SYST_3uS()    \
         SYST_WaitLoop(26);      \
         {                       \
           asm("  nop");         \
         }

#define  SYST_Wait_SYST_4uS()    \
         SYST_WaitLoop(35);      \
         {                       \
           asm("  nop");         \
           asm("  nop");         \
           asm("  nop");         \
           asm("  nop");         \
         }

#define  SYST_Wait_SYST_4_7uS()  \
         SYST_WaitLoop(42);      \
         {                       \
           asm("  nop");         \
           asm("  nop");         \
           asm("  nop");         \
         }

#define  SYST_Wait_SYST_5uS()    \
         SYST_WaitLoop(45);      \
         {                       \
           asm("  nop");         \
           asm("  nop");         \
         }

#define  SYST_Wait_SYST_20uS()   \
         SYST_WaitLoop(189);     \
         {                       \
           asm("  nop");         \
           asm("  nop");         \
         }

#define  SYST_Wait_SYST_25uS()   \
         SYST_WaitLoop(237);     \
         {                       \
           asm("  nop");         \
           asm("  nop");         \
         }

#define  SYST_Wait_SYST_50uS()   \
         SYST_WaitLoop(477);     \
         {                       \
           asm("  nop");         \
           asm("  nop");         \
         }

#define  SYST_Wait_SYST_100uS()  \
         SYST_WaitLoop(957);     \
         {                       \
           asm("  nop");         \
           asm("  nop");         \
         }

#define  SYST_Wait_SYST_200uS()  \
         SYST_WaitLoop(1917);    \
         {                       \
           asm("  nop");         \
           asm("  nop");         \
         }

#else
#error please define a correct SYST_FX_CLOCK for V850 !!!
#endif /* SYST_FX_CLOCK == 48 */
#endif /* SYST_FX_CLOCK == 40 */
#endif /* SYST_FX_CLOCK == 32 */
#endif /* SYST_FX_CLOCK == 20 */
#endif /* SYST_FX_CLOCK == 16 */
#else
#error Your V850 core is not supported !!!
#endif /* C_COMP_GHS_V850E1 || C_COMP_GHS_V850ES */
#endif /* C_COMP_GHS_V850E2V3 */

#endif /* __NEC_V850__ */


#if (defined __RH850__)
#ifdef C_COMP_GHS_RH850
#if SYST_FX_CLOCK == 40
/* CPU Clock = 40 MHz => NOP = 25 ns */

#define  SYST_Wait_SYST_25nS()   \
         {                       \
           asm("nop");           \
         }

#define  SYST_Wait_SYST_50nS()   \
         {                       \
           asm("nop");           \
           asm("nop");           \
         }

#define  SYST_Wait_SYST_75nS()   \
         {                       \
           asm("nop");           \
           asm("nop");           \
           asm("nop");           \
         }

#define  SYST_Wait_SYST_100nS()  \
         SYST_Wait_SYST_50nS();  \
         SYST_Wait_SYST_50nS()

#define  SYST_Wait_SYST_200nS()  \
         SYST_Wait_SYST_100nS(); \
         SYST_Wait_SYST_100nS()

#define  SYST_Wait_SYST_250nS()  \
         SYST_Wait_SYST_200nS(); \
         SYST_Wait_SYST_50nS()
/* 10 nop instructions */

#define  SYST_Wait_SYST_500nS()  \
         SYST_Wait_SYST_250nS(); \
         SYST_Wait_SYST_250nS()

#define  SYST_Wait_SYST_2_5uS()  \
         SYST_WaitLoop(16);      \
         SYST_Wait_SYST_100nS()

#define  SYST_Wait_SYST_3uS()    \
         SYST_WaitLoop(20);      \
         SYST_Wait_SYST_100nS()

#define  SYST_Wait_SYST_4uS()    \
         SYST_WaitLoop(28);      \
         SYST_Wait_SYST_100nS()

#define  SYST_Wait_SYST_4_7uS()  \
         SYST_WaitLoop(34);      \
         SYST_Wait_SYST_50nS()

#define  SYST_Wait_SYST_5uS()    \
         SYST_WaitLoop(36);      \
         SYST_Wait_SYST_100nS()

#define  SYST_Wait_SYST_20uS()   \
         SYST_WaitLoop(156);     \
         SYST_Wait_SYST_100nS()

#define  SYST_Wait_SYST_25uS()   \
         SYST_WaitLoop(196);     \
         SYST_Wait_SYST_100nS()

#define  SYST_Wait_SYST_50uS()   \
         SYST_WaitLoop(396);     \
         SYST_Wait_SYST_100nS()

#define  SYST_Wait_SYST_100uS()  \
         SYST_WaitLoop(796);     \
         SYST_Wait_SYST_100nS()

#define  SYST_Wait_SYST_200uS()  \
         SYST_WaitLoop(1596);    \
         SYST_Wait_SYST_100nS()

#elif SYST_FX_CLOCK == 48
/* CPU Clock = 48 MHz => NOP = 20.83 ns */

/* Only define for other delays */
#define  SYST_Wait_SYST_20_8nS() \
         {                       \
           asm("  nop");         \
         }
/* 1 nop */

/* Only define for other delays */
#define  SYST_Wait_SYST_41_7nS() \
         {                       \
           asm("  nop");         \
           asm("  nop");         \
         }
/* 2 nop */

/* Only define for other delays */
#define  SYST_Wait_SYST_62_5nS() \
         {                       \
           asm("  nop");         \
           asm("  nop");         \
           asm("  nop");         \
         }
/* 3 nop */

/* Only define for other delays */
#define  SYST_Wait_SYST_83_3nS() \
         SYST_Wait_SYST_41_7nS();\
         SYST_Wait_SYST_41_7nS()
/* 4 nop */

/* Only define for other delays */
#define  SYST_Wait_SYST_125nS()  \
         SYST_Wait_SYST_62_5nS();\
         SYST_Wait_SYST_62_5nS()
/* 6 nop */

#define  SYST_Wait_SYST_250nS()  \
         SYST_Wait_SYST_125nS(); \
         SYST_Wait_SYST_125nS()
/* 12 nop */

#define  SYST_Wait_SYST_500nS()  \
         SYST_Wait_SYST_250nS(); \
         SYST_Wait_SYST_250nS()
/* 24 nop */

/* for time >= 2.5us use function instead of nop to save ROM size */
/* Use function because too many nops */
#define  SYST_Wait_SYST_2_5uS()  \
         SYST_WaitLoop(13);      \
         {                       \
           asm("  nop");         \
           asm("  nop");         \
         }

#define  SYST_Wait_SYST_3uS()    \
         SYST_WaitLoop(16);      \
         {                       \
           asm("  nop");         \
         }

#define  SYST_Wait_SYST_4uS()    \
         SYST_WaitLoop(22);      \
         {                       \
           asm("  nop");         \
         }

#define  SYST_Wait_SYST_4_7uS()  \
         SYST_WaitLoop(26);      \
         {                       \
           asm("  nop");         \
           asm("  nop");         \
         }

#define  SYST_Wait_SYST_5uS()    \
         SYST_WaitLoop(28);      \
         {                       \
           asm("  nop");         \
         }

#define  SYST_Wait_SYST_20uS()   \
         SYST_WaitLoop(118);     \
         {                       \
           asm("  nop");         \
           asm("  nop");         \
         }

#define  SYST_Wait_SYST_25uS()   \
         SYST_WaitLoop(150);     \
         {                       \
           asm("  nop");         \
           asm("  nop");         \
         }

#define  SYST_Wait_SYST_50uS()   \
         SYST_WaitLoop(300);     \
         {                       \
           asm("  nop");         \
           asm("  nop");         \
           asm("  nop");         \
           asm("  nop");         \
         }

#define  SYST_Wait_SYST_100uS()  \
         SYST_WaitLoop(600);     \
         {                       \
           asm("  nop");         \
           asm("  nop");         \
           asm("  nop");         \
           asm("  nop");         \
           asm("  nop");         \
         }

#define  SYST_Wait_SYST_200uS()  \
         SYST_WaitLoop(1202);    \
         {                       \
           asm("  nop");         \
         }


#elif SYST_FX_CLOCK == 80
/* CPU Clock = 80 MHz => NOP = 12.5 ns */

#define  SYST_Wait_SYST_25nS()   \
         {                       \
           asm("nop");           \
           asm("nop");           \
         }

#define  SYST_Wait_SYST_50nS()   \
         {                       \
           asm("nop");           \
           asm("nop");           \
           asm("nop");           \
           asm("nop");           \
         }

#define  SYST_Wait_SYST_75nS()   \
         {                       \
           asm("nop");           \
           asm("nop");           \
           asm("nop");           \
           asm("nop");           \
           asm("nop");           \
           asm("nop");           \
         }

#define  SYST_Wait_SYST_100nS()  \
         SYST_Wait_SYST_50nS();  \
         SYST_Wait_SYST_50nS();

#define  SYST_Wait_SYST_200nS()  \
         SYST_Wait_SYST_100nS(); \
         SYST_Wait_SYST_100nS();

#define  SYST_Wait_SYST_250nS()  \
         SYST_Wait_SYST_200nS(); \
         SYST_Wait_SYST_50nS();
/* 10 nop instructions */


#define  SYST_Wait_SYST_500nS()  \
         SYST_Wait_SYST_250nS(); \
         SYST_Wait_SYST_250nS();

#define  SYST_Wait_SYST_2_5uS()  \
         SYST_WaitLoop(23);

#define  SYST_Wait_SYST_3uS()    \
         SYST_WaitLoop(29);

#define  SYST_Wait_SYST_4uS()    \
         SYST_WaitLoop(39);

#define  SYST_Wait_SYST_4_7uS()  \
         SYST_WaitLoop(45);

#define  SYST_Wait_SYST_5uS()    \
         SYST_WaitLoop(52);

#define  SYST_Wait_SYST_20uS()   \
         SYST_WaitLoop(208);

#define  SYST_Wait_SYST_25uS()   \
         SYST_WaitLoop(260);

#define  SYST_Wait_SYST_50uS()   \
         SYST_WaitLoop(520);

#define  SYST_Wait_SYST_100uS()  \
         SYST_WaitLoop(1040);

#define  SYST_Wait_SYST_200uS()  \
         SYST_WaitLoop(2080);


#define  SYST_Wait_SYST_3_4MS()\
         SYST_WaitLoop(27000);\
         SYST_WaitLoop(27000);

#define  SYST_Wait_SYST_7_MS()\
         SYST_Wait_SYST_3_4MS();\
         SYST_Wait_SYST_3_4MS();

#define  SYST_Wait_SYST_17_MS()\
         SYST_Wait_SYST_7_MS();\
         SYST_Wait_SYST_7_MS();\
         SYST_Wait_SYST_3_4MS();

#define  SYST_Wait_SYST_50_MS()\
         SYST_Wait_SYST_17_MS();\
         SYST_Wait_SYST_17_MS();\
         SYST_Wait_SYST_7_MS();\
         SYST_Wait_SYST_7_MS();\
         SYST_WaitLoop(39000);

#elif SYST_FX_CLOCK == 120
/* CPU Clock = 120 MHz => NOP = 8.4 ns */

#define  SYST_Wait_SYST_25nS()   \
         {                       \
           asm("nop");           \
           asm("nop");           \
           asm("nop");           \
         }

#define  SYST_Wait_SYST_50nS()   \
         {                       \
           asm("nop");           \
           asm("nop");           \
           asm("nop");           \
           asm("nop");           \
           asm("nop");           \
           asm("nop");           \
         }

#define  SYST_Wait_SYST_75nS()   \
         {                       \
           asm("nop");           \
           asm("nop");           \
           asm("nop");           \
           asm("nop");           \
           asm("nop");           \
           asm("nop");           \
           asm("nop");           \
           asm("nop");           \
           asm("nop");           \
         }

#define  SYST_Wait_SYST_100nS()  \
         SYST_Wait_SYST_50nS();  \
         SYST_Wait_SYST_50nS();

#define  SYST_Wait_SYST_200nS()  \
         SYST_Wait_SYST_100nS(); \
         SYST_Wait_SYST_100nS();

#define  SYST_Wait_SYST_250nS()  \
         SYST_Wait_SYST_200nS(); \
         SYST_Wait_SYST_50nS();


#define  SYST_Wait_SYST_500nS()  \
         SYST_Wait_SYST_250nS(); \
         SYST_Wait_SYST_250nS();

#define  SYST_Wait_SYST_2_5uS()  \
         SYST_WaitLoop(35);

#define  SYST_Wait_SYST_3uS()    \
         SYST_WaitLoop(43);

#define  SYST_Wait_SYST_4uS()    \
         SYST_WaitLoop(59);

#define  SYST_Wait_SYST_4_7uS()  \
         SYST_WaitLoop(68);

#define  SYST_Wait_SYST_5uS()    \
         SYST_WaitLoop(78);

#define  SYST_Wait_SYST_20uS()   \
         SYST_WaitLoop(312);

#define  SYST_Wait_SYST_25uS()   \
         SYST_WaitLoop(390);

#define  SYST_Wait_SYST_50uS()   \
         SYST_WaitLoop(780);

#define  SYST_Wait_SYST_100uS()  \
         SYST_WaitLoop(1560);

#define  SYST_Wait_SYST_200uS()  \
         SYST_WaitLoop(3120);

#elif SYST_FX_CLOCK == 160
/* CPU Clock = 160 MHz => NOP = 6.25 ns */

#define  SYST_Wait_SYST_25nS()   \
         {                       \
           asm("nop");           \
           asm("nop");           \
           asm("nop");           \
           asm("nop");           \
         }

#define  SYST_Wait_SYST_50nS()   \
         {                       \
           asm("nop");           \
           asm("nop");           \
           asm("nop");           \
           asm("nop");           \
           asm("nop");           \
           asm("nop");           \
           asm("nop");           \
           asm("nop");           \
         }

#define  SYST_Wait_SYST_75nS()   \
         {                       \
           asm("nop");           \
           asm("nop");           \
           asm("nop");           \
           asm("nop");           \
           asm("nop");           \
           asm("nop");           \
           asm("nop");           \
           asm("nop");           \
           asm("nop");           \
           asm("nop");           \
           asm("nop");           \
           asm("nop");           \
         }

#define  SYST_Wait_SYST_100nS()  \
         SYST_Wait_SYST_50nS();  \
         SYST_Wait_SYST_50nS();

#define  SYST_Wait_SYST_200nS()  \
         SYST_Wait_SYST_100nS(); \
         SYST_Wait_SYST_100nS();

#define  SYST_Wait_SYST_250nS()  \
         SYST_Wait_SYST_200nS(); \
         SYST_Wait_SYST_50nS();

#define  SYST_Wait_SYST_500nS()  \
         SYST_Wait_SYST_250nS(); \
         SYST_Wait_SYST_250nS();

#define  SYST_Wait_SYST_2_5uS()  \
         SYST_WaitLoop(46);

#define  SYST_Wait_SYST_3uS()    \
         SYST_WaitLoop(58);

#define  SYST_Wait_SYST_4uS()    \
         SYST_WaitLoop(78);

#define  SYST_Wait_SYST_4_7uS()  \
         SYST_WaitLoop(90);

#define  SYST_Wait_SYST_5uS()    \
         SYST_WaitLoop(104);

#define  SYST_Wait_SYST_20uS()   \
         SYST_WaitLoop(408);

#define  SYST_Wait_SYST_25uS()   \
         SYST_WaitLoop(520);

#define  SYST_Wait_SYST_50uS()   \
         SYST_WaitLoop(1040);

#define  SYST_Wait_SYST_100uS()  \
         SYST_WaitLoop(2080);

#define  SYST_Wait_SYST_200uS()  \
         SYST_WaitLoop(4160);


#else
#error please define a correct SYST_FX_CLOCK for rh850 !!!
#endif /* SYST_FX_CLOCK == 40 */

#endif /* C_COMP_GHS_RH850 */

#endif /* __RH850__ */

/* Syst_Wait: FRESCALE IMX53 */
#if defined(__FSL_IMX53x__) || defined(__FSL_IMX6x__)

/* For compilation only: must be calculated and mesured */
#define  SYST_Wait_SYST_250nS() \
         SYST_WaitLoop(64)

#define  SYST_Wait_SYST_500nS() \
         SYST_WaitLoop(131)

#define  SYST_Wait_SYST_2_5uS() \
         SYST_WaitLoop(664)

#define  SYST_Wait_SYST_3uS()   \
         SYST_WaitLoop(797)

#define  SYST_Wait_SYST_4uS()   \
         SYST_WaitLoop(1064)

#define  SYST_Wait_SYST_4_7uS() \
         SYST_WaitLoop(1251)

#define  SYST_Wait_SYST_5uS()   \
         SYST_WaitLoop(1331)

#define  SYST_Wait_SYST_20uS()  \
         SYST_WaitLoop(5331)

#define  SYST_Wait_SYST_25uS()  \
         SYST_WaitLoop(6664)

#define  SYST_Wait_SYST_50uS()  \
         SYST_WaitLoop(13331)

#define  SYST_Wait_SYST_100uS() \
         SYST_WaitLoop(26664)

#define  SYST_Wait_SYST_200uS() \
         SYST_WaitLoop(53331)

#endif /* __FSL_IMX53x__,__FSL_IMX6x_ */

#ifdef __PC_SIMULATION__
#ifndef SYST_Wait_SYST_6uS
#define  SYST_Wait_SYST_6uS()
#endif
#ifndef SYST_Wait_SYST_1500nS
#define  SYST_Wait_SYST_1500nS()
#endif
#ifndef SYST_Wait_SYST_300nS
#define  SYST_Wait_SYST_300nS()
#endif
#ifndef SYST_Wait_SYST_100nS
#define  SYST_Wait_SYST_100nS()
#endif
#ifndef SYST_Wait_SYST_50nS
#define  SYST_Wait_SYST_50nS()
#endif
#ifndef SYST_Wait_SYST_25nS
#define  SYST_Wait_SYST_25nS()
#endif
#ifndef SYST_Wait_SYST_8_3nS
#define  SYST_Wait_SYST_8_3nS()
#endif
#ifndef SYST_Wait_SYST_250nS
#define  SYST_Wait_SYST_250nS()
#endif
#ifndef SYST_Wait_SYST_500nS
#define  SYST_Wait_SYST_500nS()
#endif
#ifndef SYST_Wait_SYST_2_5uS
#define  SYST_Wait_SYST_2_5uS()
#endif
#ifndef SYST_Wait_SYST_3uS
#define  SYST_Wait_SYST_3uS()
#endif
#ifndef SYST_Wait_SYST_4uS
#define  SYST_Wait_SYST_4uS()
#endif
#ifndef SYST_Wait_SYST_4_7uS
#define  SYST_Wait_SYST_4_7uS()
#endif
#ifndef SYST_Wait_SYST_5uS
#define  SYST_Wait_SYST_5uS()
#endif
#ifndef SYST_Wait_SYST_20uS
#define  SYST_Wait_SYST_20uS()
#endif
#ifndef SYST_Wait_SYST_25uS
#define  SYST_Wait_SYST_25uS()
#endif
#ifndef SYST_Wait_SYST_50uS
#define  SYST_Wait_SYST_50uS()
#endif
#ifndef SYST_Wait_SYST_100uS
#define  SYST_Wait_SYST_100uS()
#endif
#ifndef SYST_Wait_SYST_200uS
#define  SYST_Wait_SYST_200uS()
#endif
#ifndef SYST_Wait_SYST_2_5uS
#define  SYST_Wait_SYST_2_5uS()
#endif
#endif /* __PC_SIMULATION__            */






#ifdef Syst_ROM_CHECKSUM_SERVICE
/*----------------------------------------------------------------------------*/
/*Name : SYST_RomChecksum                                                     */
/*Role : Make a FLASH/ROM memory checksum byte per byte into an ushort format */
/*Interface :                                                                 */
/*   StartAdd (ulong) INPUT  The Start address to sum up according to s19 file*/
/*                           This address is included                         */
/*   EndAdd   (ulong) INPUT  The End address to sum up according to s19 file  */
/*                           This address is ALSO included                    */
/*           (ushort) OUTPUT The checksum value                               */
/*Pre-condition :                                                             */
/*   The FLASH/ROM memory init should be done                                 */
/*   The memory have to be in readable state                                  */
/*Constraints :                                                               */
/*   The time execution could be long, depending of the area size to make the */
/*   checksum. For example :                                                  */
/*      - Star12 micro, 108 msec for 16 kbytes   (16Mhz bus Clock)            */
/*                                                                            */
/*   FOR START12 MICRO, THIS ROUTINE HAVE TO BE PUT INTO A NON-BANKED PAGE    */
/*   By default,to save place in not-banked page, __FAR__ routines of         */
/*   NON-BANKED page are placed in a banked page                              */
/*   Add __NEAR__ on this routine to force map in the NON-banked page         */
/*                                                                            */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [Over run the checksum value according to the zone ]                    */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
extern __NON_BANKED__ ushort SYST_RomChecksum(SYST_AddressWidth_t StartLinearAddr,
                                              SYST_AddressWidth_t EndLinearAddr);
#endif /* Syst_ROM_CHECKSUM */

#ifdef Syst_RAM_CHECKSUM_SERVICE
/*----------------------------------------------------------------------------*/
/*Name : SYST_RamChecksum                                                     */
/*Role : Make a RAM memory checksum byte per byte into an ushort format       */
/*Interface :                                                                 */
/*   StartLinearAddr (ulong) INPUT  The Start address to sum up               */
/*                           This address is included                         */
/*   EndLinearAddr   (ulong) INPUT  The End address to sum up                 */
/*                           This address is ALSO included                    */
/*           (ushort) OUTPUT The checksum value                               */
/*Pre-condition :                                                             */
/*Constraints :                                                               */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [Over run the checksum value according to the zone ]                    */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
extern ushort SYST_RamChecksum(SYST_AddressWidth_t StartLinearAddr,
                               SYST_AddressWidth_t EndLinearAddr);

#endif /* Syst_RAM_CHECKSUM_SERVICE */


#ifdef Syst_READ_ROM_SERVICE
/*----------------------------------------------------------------------------*/
/*Name : SYST_ReadRom                                                         */
/*Role : Copy Rom in a buffer                                                 */
/*Interface :                                                                 */
/*   StartAdd         INPUT  The Start address to read according to s19 file  */
/*                           This address is included                         */
/*   EndAdd           INPUT  The End address to read according to s19 file    */
/*                           This address is ALSO included                    */
/*   ReadTable(ubyte*)INPUT  return buffer address                            */
/*Pre-condition :                                                             */
/*   The FLASH/ROM memory init should be done                                 */
/*   The memory have to be in readable state                                  */
/*Constraints :                                                               */
/*   The time execution could be long, depending of the area size             */
/*    For example :                                                           */
/*      - Star12 micro, 1.7 msec for 255 bytes   (16Mhz bus Clock)            */
/*                                                                            */
/*   FOR START12 MICRO, THIS ROUTINE HAVE TO BE PUT INTO A NON-BANKED PAGE    */
/*   By default,to save place in not-banked page, __FAR__ routines of         */
/*   NON-BANKED page are placed in a banked page                              */
/*   Add __NEAR__ on this routine to force map in the NON-banked page         */
/*                                                                            */
/*   FOR START12 MICRO, only use this service for small area                  */
/*                                                                            */
/*   When read in external FLASH/ROM, DON'T read more than 65535 bytes        */
/*                                                                            */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [copy Rom byte in buffer ]                                              */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
extern __NON_BANKED__ void SYST_ReadRom(SYST_AddressWidth_t StartLinearAddr,
                                        SYST_AddressWidth_t EndLinearAddr,
                                        __GCONST__ ubyte*   ReadTable);


#endif /* Syst_READ_ROM_SERVICE */


/*----------------------------------------------------------------------------*/
/*Name : SYST_ReadRam                                                         */
/*Role : Copy Ram in a buffer                                                 */
/*Interface :                                                                 */
/*   StartAdd        INPUT  The Start address to read                         */
/*                          For GHOS, the address is relative to start of RAM */
/*                          This address is included                          */
/*   EndAdd          INPUT  The End address to read                           */
/*                          For GHOS, the address is relative to start of RAM */
/*                          This address is ALSO included                     */
/*   ReadTable       INPUT  return buffer address                             */
/*Pre-condition : -                                                           */
/*Constraints : -                                                             */
/*----------------------------------------------------------------------------*/
extern __NEAR_FUNC__ void SYST_ReadRam(SYST_AddressWidth_t StartLinearAddr,
                                       SYST_AddressWidth_t EndLinearAddr,
                                       __GCONST__ ubyte*   ReadTable);


#ifdef __GHOS__
/*----------------------------------------------------------------------------*/
/*Name : SYST_WriteRam                                                        */
/*Role : Copy Buffer in Ram                                                   */
/*Interface :                                                                 */
/*   StartLinearAddr  INPUT  The Start address to write                       */
/*                           The address is relative to start of RAM          */
/*                           This address is included                         */
/*   EndLinearAddr    INPUT  The End address to write                         */
/*                           The address is relative to start of RAM          */
/*                           This address is ALSO included                    */
/*   WriteTable       INPUT  Data to write buffer address                     */
/*Pre-condition : -                                                           */
/*Constraints : -                                                             */
/*----------------------------------------------------------------------------*/
extern void SYST_WriteRam(SYST_AddressWidth_t StartLinearAddr,
                          SYST_AddressWidth_t EndLinearAddr,
                          ubyte*              WriteTable);
#endif /* __GHOS__ */


#ifdef Syst_READ_EXTERNAL_SPI_FLASH_SERVICE
/*----------------------------------------------------------------------------*/
/* Name: SYST_ReadExternalFlash                                               */
/* Role: Read data from external Flash                                        */
/* Interface: FlashAddr      IN   Address of data in Flash                    */
/*            Buffer         IN   Destination buffer                          */
/*            DataSize       IN   Size of data to read                        */
/* Pre-condition: none                                                        */
/* Constraints:   none                                                        */
/*----------------------------------------------------------------------------*/
extern void SYST_ReadExternalFlash(SYST_AddressWidth_t  FlashAddr,
                                   __GCONST__ ubyte*    Buffer,
                                   ushort               DataSize);


#ifdef Syst_READ_EXTERNAL_SPI_FLASH_UNTIL_BYTE_SERVICE
/*----------------------------------------------------------------------------*/
/* Name: SYST_ReadExternalFlashUntilByte                                      */
/* Role: Read data from external Flash until byte value found                 */
/* Interface: FlashAddr      IN   Address of data in Flash                    */
/*            Buffer         IN   Destination buffer                          */
/*            DataValue      IN   Value of data to found                      */
/*            Size          OUT   Number of data read from flash              */
/* Pre-condition: none                                                        */
/* Constraints:   none                                                        */
/*----------------------------------------------------------------------------*/
extern ushort SYST_ReadExternalFlashUntilByte(SYST_AddressWidth_t  FlashAddr,
                                              __GCONST__ ubyte*    Buffer,
                                              ubyte                DataValue);
#endif /* Syst_READ_EXTERNAL_SPI_FLASH_UNTIL_BYTE_SERVICE */


#ifdef Syst_READ_EXTERNAL_SPI_FLASH_UNTIL_SHORT_SERVICE
/*----------------------------------------------------------------------------*/
/* Name: SYST_ReadExternalFlashUntilShort                                     */
/* Role: Read data from external Flash until short value found                */
/* Interface: FlashAddr      IN   Address of data in Flash                    */
/*            Buffer         IN   Destination buffer                          */
/*            DataValue      IN   Value of data to found                      */
/*            Size          OUT   Number of data read from flash              */
/* Pre-condition: none                                                        */
/* Constraints:   none                                                        */
/*----------------------------------------------------------------------------*/
extern ushort SYST_ReadExternalFlashUntilShort(SYST_AddressWidth_t  FlashAddr,
                                               __GCONST__ ushort*   Buffer,
                                               ushort               DataValue);
#endif /* Syst_READ_EXTERNAL_SPI_FLASH_UNTIL_SHORT_SERVICE */


#ifdef Syst_READ_EXTERNAL_SPI_FLASH_ID_SERVICE
/*----------------------------------------------------------------------------*/
/* Name: SYST_ReadExternalFlashId                                             */
/* Role: Read 24bits Id of external Flash                                     */
/* Interface: Buffer        IN   Destination buffer                           */
/* Pre-condition: none                                                        */
/* Constraints:   none                                                        */
/*----------------------------------------------------------------------------*/
extern void SYST_ReadExternalFlashId(ubyte* Buffer);
#endif /* Syst_READ_EXTERNAL_SPI_FLASH_ID_SERVICE */


#ifdef Syst_ROM_CHECKSUM_SERVICE
/*----------------------------------------------------------------------------*/
/* Name: SYST_ExternalFlashChecksum                                           */
/* Role: Make the external flash checksum byte per byte into an ushort format */
/* Interface: StartFlashAddr   IN   Start address of data in external Flash   */
/*            EndFlashAddr     IN   End address of data in external Flash     */
/*            (ushort)         OUT  The checksum value                        */
/* Pre-condition: none                                                        */
/* Constraints:   none                                                        */
/*----------------------------------------------------------------------------*/
extern ushort SYST_ExternalFlashChecksum(SYST_AddressWidth_t  StartFlashAddr,
                                         SYST_AddressWidth_t  EndFlashAddr);
#endif /* Syst_ROM_CHECKSUM_SERVICE */
#endif /* Syst_READ_EXTERNAL_SPI_FLASH_SERVICE */


/*----------------------------------------------------------------------------*/
/*Name : SYST_Memcpy                                                          */
/*Role : memcpy platform standard function                                    */
/*Interface :                                                                 */
/*   IN : void* destination : Pointer to the destination array where the      */
/*                            content is to be copied.                        */
/*   IN : const void* source : Pointer to the source of data to be copied.    */
/*   IN : size_t num : Number of bytes to copy.                               */
/*  OUT : void* out : destination is returned.                                */
/*Pre-condition : -                                                           */
/*Constraints :   -                                                           */
/*Behavior:       -                                                           */
/*----------------------------------------------------------------------------*/
#define SYST_Memcpy(destination, source, num) memcpy((void *)(destination), (const void *)(source), num)


/*----------------------------------------------------------------------------*/
/*Name : SYST_Memcmp                                                          */
/*Role : memcmp platform standard function                                    */
/*Interface :                                                                 */
/*   IN : const void* ptr1 : Pointer to block of memory.                      */
/*   IN : const void* ptr2 : Pointer to block of memory.                      */
/*   IN : size_t num : Number of bytes to compare.                            */
/*  OUT : int result :                                                        */
/*   Returns an integral value indicating the relationship between the        */
/*   content of the memory blocks :                                           */
/*   A zero value indicates that the contents of both memory blocks are equal.*/
/*   A value greater than zero indicates that the first byte that does not    */
/*   match in both memory blocks has a greater value in ptr1 than in ptr2 as  */
/*   if evaluated as unsigned char values; And a value less than zero         */
/*   indicates the opposite.                                                  */
/*Pre-condition : -                                                           */
/*Constraints :   -                                                           */
/*Behavior:       -                                                           */
/*----------------------------------------------------------------------------*/
#define SYST_Memcmp(ptr1, ptr2, num) memcmp((const void *)(ptr1), (const void *)(ptr2), num)


/*----------------------------------------------------------------------------*/
/*Name : SYST_Memset                                                          */
/*Role : memcpy like function for near data depends on micro                  */
/*Interface :                                                                 */
/*   IN : void* ptr : Pointer to the block of memory to fill.                 */
/*   IN : int value : Value to be set. The value is passed as an int,         */
/*                    but the function fills the block of memory using the    */
/*                    unsigned char conversion of this value.                 */
/*   IN : size_t num : Number of bytes to be set to the value.                */
/*  OUT : void* out : ptr is returned.                                        */
/*Pre-condition : -                                                           */
/*Constraints :   -                                                           */
/*Behavior:       -                                                           */
/*----------------------------------------------------------------------------*/
#define SYST_Memset(ptr, value, num) memset((void *) (ptr), value, num)


/*----------------------------------------------------------------------------*/
/*Name : SYST_NearMemcpy                                                      */
/*Role : memcpy like function for near data depends on micro                  */
/*Interface :                                                                 */
/*   IN : void* destination : Pointer to the destination array where the      */
/*                            content is to be copied.                        */
/*   IN : const void* source : Pointer to the source of data to be copied.    */
/*   IN : size_t num    : Number of bytes to copy.                            */
/*  OUT : void* out : destination is returned.                                */
/*Pre-condition : -                                                           */
/*Constraints :   -                                                           */
/*Behavior:       -                                                           */
/*----------------------------------------------------------------------------*/
#define SYST_NearMemcpy(destination, source, num) SYST_Memcpy(destination, source, num)


/*----------------------------------------------------------------------------*/
/*Name : SYST_NearMemcmp                                                      */
/*Role : memcmp like function for near data depends on micro                  */
/*Interface :                                                                 */
/*   IN : const void* ptr1 : Pointer to block of memory.                      */
/*   IN : const void* ptr2 : Pointer to block of memory.                      */
/*   IN : size_t num : Number of bytes to compare.                            */
/*  OUT : int result :                                                        */
/*   Returns an integral value indicating the relationship between the        */
/*   content of the memory blocks:                                            */
/*   A zero value indicates that the contents of both memory blocks are equal.*/
/*   A value greater than zero indicates that the first byte that does not    */
/*   match in both memory blocks has a greater value in ptr1 than in ptr2 as  */
/*   if evaluated as unsigned char values; And a value less than zero         */
/*   indicates the opposite.                                                  */
/*Pre-condition : -                                                           */
/*Constraints :   -                                                           */
/*Behavior:       -                                                           */
/*----------------------------------------------------------------------------*/
#define SYST_NearMemcmp(ptr1, ptr2, num) SYST_Memcmp(ptr1, ptr2, num)


/*----------------------------------------------------------------------------*/
/*Name : SYST_NearMemset                                                      */
/*Role : memcpy like function for near data depends on micro                  */
/*Interface :                                                                 */
/*   IN : void* ptr : Pointer to the block of memory to fill.                 */
/*   IN : int value : Value to be set. The value is passed as an int,         */
/*                    but the function fills the block of memory using the    */
/*                    unsigned char conversion of this value.                 */
/*   IN : size_t num : Number of bytes to be set to the value.                */
/*  OUT : void* out : ptr is returned.                                        */
/*Pre-condition : -                                                           */
/*Constraints :   -                                                           */
/*Behavior:       -                                                           */
/*----------------------------------------------------------------------------*/
#define SYST_NearMemset(ptr, value, num) SYST_Memset(ptr, value, num)


/*----------------------------------------------------------------------------*/
/*Name : SYST_FarMemcpy                                                       */
/*Role : memcpy like function for far data depends on micro                   */
/*Interface :                                                                 */
/*   IN : __GCONST__ void* destination OR                                     */
/*        __FDA__    void* destination OR                                     */
/*                   void* destination : Pointer to the destination array     */
/*        where  the content is to be copied.                                 */
/*   IN : __GCONST__ const void* source OR                                    */
/*        __FDA__    const void* source OR                                    */
/*                   const void* source : Pointer to the source of data to be */
/*        copied.                                                             */
/*   IN : size_t num              : Number of bytes to copy.                  */
/*  OUT : __GCONST__ void* out    : destination is returned.                  */
/*Pre-condition : -                                                           */
/*Constraints :   -                                                           */
/*Behavior:       -                                                           */
/*----------------------------------------------------------------------------*/
#if defined(__MC9S12XHZ__)
#define SYST_FarMemcpy(destination, source, num) gmemcpy(destination, source, num)
#else
/*For all other targets*/
#define SYST_FarMemcpy(destination, source, num) SYST_Memcpy(destination, source, num)
#endif /* defined(__MC9S12XHZ__) */


/*----------------------------------------------------------------------------*/
/*Name : SYST_FarMemcmp                                                       */
/*Role : memcmp like function for far data depends on micro                   */
/*Interface :                                                                 */
/*   IN : __GCONST__ const void* ptr1 OR                                      */
/*        __FDA__    const void* ptr1 OR                                      */
/*                   const void* ptr1 : Pointer to block of memory.           */
/*   IN : __GCONST__ const void* ptr2 OR                                      */
/*        __FDA__    const void* ptr2 OR                                      */
/*                   const void* ptr2 : Pointer to block of memory.           */
/*   IN : size_t num : Number of bytes to compare.                            */
/*  OUT : int result :                                                        */
/*   Returns an integral value indicating the relationship between the        */
/*   content of the memory blocks:                                            */
/*   A zero value indicates that the contents of both memory blocks are equal.*/
/*   A value greater than zero indicates that the first byte that does not    */
/*   match in both memory blocks has a greater value in ptr1 than in ptr2 as  */
/*   if evaluated as unsigned char values; And a value less than zero         */
/*   indicates the opposite.                                                  */
/*Pre-condition : -                                                           */
/*Constraints :   -                                                           */
/*Behavior:       -                                                           */
/*----------------------------------------------------------------------------*/
#if defined(__MC9S12XHZ__)
#define SYST_FarMemcmp(ptr1, ptr2, num) gmemcmp(ptr1, ptr2, num)
#else
/*For all other targets*/
#define SYST_FarMemcmp(ptr1, ptr2, num) SYST_Memcmp(ptr1, ptr2, num)
#endif /* defined(__MC9S12XHZ__) */


/*----------------------------------------------------------------------------*/
/*Name : SYST_FarMemset                                                       */
/*Role : memset like function for far data depends on micro                   */
/*Interface :                                                                 */
/*   IN : __GCONST__ void* ptr OR                                             */
/*        __FDA__    void* ptr OR                                             */
/*                   void* ptr : Pointer to the block of memory to fill.      */
/*   IN : int value : Value to be set. The value is passed as an int,         */
/*                    but the function fills the block of memory using the    */
/*                    unsigned char conversion of this value.                 */
/*   IN : size_t num : Number of bytes to be set to the value.                */
/*  OUT : __GCONST__ void* out : ptr is returned.                             */
/*Pre-condition : -                                                           */
/*Constraints :   -                                                           */
/*Behavior:       -                                                           */
/*----------------------------------------------------------------------------*/
#if defined(__MC9S12XHZ__)
#define SYST_FarMemset(ptr, value, num) gmemset(ptr, value, num)
#else
/*For all other targets*/
#define SYST_FarMemset(ptr, value, num) SYST_Memset(ptr, value, num)
#endif /* defined(__MC9S12XHZ__) */


#if defined(__FSL_IMX53x__) || defined(__FSL_IMX6x__)
/*----------------------------------------------------------------------------*/
/*Name : SYST_Memset32BitsOptim                                               */
/*Role : Memset 32bits optimized for ARM cortex A8.                           */
/*Interface :                                                                 */
/*   IN : void * dst  : Destination address                                   */
/*   IN : ulong value : Value to be set                                       */
/*   IN : ulong size  : Size to be set (in 32bits words)                      */
/*  OUT : -                                                                   */
/*Pre-condition : -                                                           */
/*Constraints :   -                                                           */
/*Behavior:       -                                                           */
/*----------------------------------------------------------------------------*/
extern void SYST_Memset32BitsOptim(void* dst, ulong value, ulong size);


/*----------------------------------------------------------------------------*/
/*Name : SYST_MemcpyOptim                                                     */
/*Role : Memcpy optimized for ARM cortex A8. It used VFP-NEON load and store  */
/*       instructions, and Preload instruction.                               */
/*Interface :                                                                 */
/*   IN : void * dst    : Destination address                                 */
/*   IN : void*  src    : Source address                                      */
/*   IN : ulong  size   : Size to be copied (in bytes)                        */
/*  OUT : -                                                                   */
/*Pre-condition : -                                                           */
/*Constraints :   For small sizes < 64, performance is better with memcpy     */
/*Behavior:       -                                                           */
/*----------------------------------------------------------------------------*/
extern void SYST_MemcpyOptim(void* dst, const void* src, ulong size);
#endif /* __FSL_IMX53x__,__FSL_IMX6x_ */

#ifdef SYST_DEBUG_ALLOC
/*----------------------------------------------------------------------------*/
/* Name : SYST_DebugMalloc                                                    */
/* Role : Allocates memory with debug information                             */
/* Interface      :                                                           */
/*   - IN  : (size_t) : Required allocation size                              */
/*   - IN  : (ulong)  : ID of the module where the allocation is done         */
/*   - IN  : (ulong)  : ID of the file where the allocation is done           */
/*   - IN  : (ulong)  : line of the malloc call                               */
/*   - OUT : (void*)  : allocated mem                                         */
/* Pre-condition: none                                                        */
/* Constraints:   none                                                        */
/*----------------------------------------------------------------------------*/
extern void* SYST_DebugMalloc(size_t Size, ulong Module,
                              ulong FileId, ulong LineNb);

/*----------------------------------------------------------------------------*/
/* Name : SYST_DebugCalloc                                                    */
/* Role : Allocates and clears memory with debug information                  */
/* Interface      :                                                           */
/*   - IN  : (ulong)  : Number of elements to allocate                        */
/*   - IN  : (size_t) : Size of an element                                    */
/*   - IN  : (ulong)  : ID of the module where the allocation is done         */
/*   - IN  : (ulong)  : ID of the file where the allocation is done           */
/*   - IN  : (ulong)  : line of the malloc call                               */
/*   - OUT : (void*)  : allocated mem                                         */
/* Pre-condition: none                                                        */
/* Constraints:   none                                                        */
/*----------------------------------------------------------------------------*/
extern void* SYST_DebugCalloc(ulong Nb, size_t ElementSize,
                              ulong Module, ulong FileId, ulong LineNb);


/*----------------------------------------------------------------------------*/
/* Name : SYST_DebugFree                                                      */
/* Role : Frees allocated memory                                              */
/* Interface      :                                                           */
/*   - IN  : (void*)  : memory to free                                        */
/*   - IN  : (ulong)  : ID of the module where the allocation is done         */
/* Pre-condition: none                                                        */
/* Constraints:   none                                                        */
/*----------------------------------------------------------------------------*/
extern void SYST_DebugFree(void* Pointer, ulong Module);
#endif /* SYST_DEBUG_ALLOC */

#if defined(Syst_CRC16_INV_CCITT)
/*----------------------------------------------------------------------------*/
/* Name: SYST_ComputeCRC16Inverted                                            */
/* Role: Compute the CRC of a data (Inverted Crc16 ccitt)                     */
/* Interface: Address IN address of data                                      */
/*            size    IN datas size                                           */
/*            Result  OUT the CRC                                             */
/* Pre-condition: none                                                        */
/* Constraints:   none                                                        */
/* Behavior:                                                                  */
/*   DO                                                                       */
/*    [ compute ]                                                             */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/
extern ushort SYST_ComputeCRC16Inverted(__GCONST__ ubyte *address, ushort size);
#endif /* defined (Syst_CRC16_INV_CCITT) */

#if defined(Syst_CRC16_INV_CCITT)
/*----------------------------------------------------------------------------*/
/* Name: SYST_ComputeCRC16                                                    */
/* Role: Compute the CRC of a data (Inverted Crc16 ccitt)                     */
/* Interface: Address IN address of data                                      */
/*            size    IN datas size                                           */
/*            Result  OUT the CRC                                             */
/* Pre-condition: none                                                        */
/* Constraints:   none                                                        */
/* Behavior:                                                                  */
/*   DO                                                                       */
/*    [ compute ]                                                             */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/
extern ushort SYST_ComputeCRC16(__GCONST__ ubyte *address, ubyte size);
#endif /* defined (Syst_CRC16_INV_CCITT) */


#if defined(Syst_CRC16_INV_CCITT) || defined(Syst_UPDATE_CRC16_INV_CCITT)
/*----------------------------------------------------------------------------*/
/*Name : SYST_UpdateInvCrc16Ccitt                                             */
/*Role : calculates a new inverted CRC16-CCITT value  based  on the previous  */
/*       value of the CRC and the next byte of the data to be checked.        */
/*Interface :                                                                 */
/*    IN InputData  : previous crc value                                      */
/*    IN InputData  : next byte of the data to be checked                     */
/*    OUT return value : new INV_CRC16_CCITT value                            */
/*Pre-condition : none                                                        */
/*Constraints : none                                                          */
/*Behaviour :                                                                 */
/*DO                                                                          */
/*  [ Update CRC with incoming data flow  ]                                   */
/*OD                                                                          */
/*----------------------------------------------------------------------------*/
extern ushort SYST_UpdateInvCrc16Ccitt(ushort crc, ubyte data);
#endif /* Syst_CRC16_INV_CCITT || Syst_UPDATE_CRC16_INV_CCITT */


#if defined(Syst_CRC16_CCITT)
/*----------------------------------------------------------------------------*/
/* Name: SYST_ComputeCRC16NonInverted                                         */
/* Role: Compute the CRC of a data (Crc16 ccitt)                              */
/* Interface: Address IN address of data                                      */
/*            size    IN datas size                                           */
/*            Result  OUT the CRC                                             */
/* Pre-condition: none                                                        */
/* Constraints:   none                                                        */
/* Behavior:                                                                  */
/*   DO                                                                       */
/*    [ compute ]                                                             */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/
extern ushort SYST_ComputeCRC16NonInverted(__GCONST__ ubyte *address, ubyte size);


/*----------------------------------------------------------------------------*/
/*Name : SYST_UpdateCrc16Ccitt                                                */
/*Role : calculates a new CRC16-CCITT value  based  on the previous           */
/*       value of the CRC and the next byte of the data to be checked.        */
/*Interface :                                                                 */
/*    IN InputData  : previous crc value                                      */
/*    IN InputData  : next byte of the data to be checked                     */
/*    OUT return value : new CRC16_CCITT value                                */
/*Pre-condition : none                                                        */
/*Constraints : none                                                          */
/*Behaviour :                                                                 */
/*DO                                                                          */
/*  [ Update CRC with incoming data flow  ]                                   */
/*OD                                                                          */
/*----------------------------------------------------------------------------*/
extern ushort SYST_UpdateCrc16Ccitt(ushort crc, ubyte data);
#endif /* defined (Syst_CRC16_CCITT) */


#ifdef Syst_CHKSUM16_DATA_USED
/*----------------------------------------------------------------------------*/
/* Name: SYST_ComputeCHKSUM16                                                 */
/* Role: Compute the Chksum of a table data                                   */
/* Interface: Address IN address of data                                      */
/*            size    IN datas size                                           */
/*            Result  OUT the CRC                                             */
/* Pre-condition: none                                                        */
/* Constraints:   none                                                        */
/* Behavior:                                                                  */
/*   DO                                                                       */
/*    [ compute ]                                                             */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/
extern ushort SYST_ComputeCHKSUM16(__GCONST__ ubyte *address, ubyte size);
#endif /* Syst_CHKSUM16_DATA_USED */


#ifdef Syst_CRC32
/*----------------------------------------------------------------------------*/
/* Name: SYST_ComputeCrc32                                                    */
/* Role:  Compute the CRC32 of a given data                                   */
/* Interface: Address IN address of data                                      */
/*            nBytes  IN datas size                                           */
/*            Result  OUT the CRC                                             */
/* Pre-condition: none                                                        */
/* Constraints:   none                                                        */
/* Behavior:                                                                  */
/*   DO                                                                       */
/*    [ compute CRC32 ]                                                       */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/
extern ulong SYST_ComputeCrc32( ubyte *address, ubyte nBytes );
#endif /* Syst_CRC32 */


#ifdef SYST_RESET_INFO
/*----------------------------------------------------------------------------*/
/*Name : SYST_GetResetType                                                    */
/*Role : Give the reset type                                                  */
/*Interface :                                                                 */
/*   IN : -                                                                   */
/*  OUT : -ResetType                                                          */
/*Pre-condition : -                                                           */
/*Constraints : -                                                             */
/* Behavior:                                                                  */
/*   DO                                                                       */
/*    [ return the cause of reset ]                                           */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/
extern SYST_ResetType_t SYST_GetResetType(void);
#endif /* SYST_RESET_INFO */


#ifdef Syst_BYTE_SEQ_BIG_ENDIAN_TO_ULONG
/*----------------------------------------------------------------------------*/
/*Name : SYST_ByteSeqBigEndianToUlong                                         */
/*Role : Convert a big endian byte sequence into ulong (32 bits).             */
/*Interface :                                                                 */
/*   IN : const ubyte* ByteSeq                                                */
/*  OUT : ulong Value                                                         */
/*Pre-condition : -                                                           */
/*Constraints :   -                                                           */
/*Behavior:       -                                                           */
/*----------------------------------------------------------------------------*/
extern ulong SYST_ByteSeqBigEndianToUlong(const ubyte* ByteSeq);
#endif /*Syst_BYTE_SEQ_BIG_ENDIAN_TO_ULONG*/


#ifdef Syst_BYTE_SEQ_LITTLE_ENDIAN_TO_ULONG
/*----------------------------------------------------------------------------*/
/*Name : SYST_ByteSeqLittleEndianToUlong                                      */
/*Role : Convert a little endian byte sequence into ulong (32 bits).          */
/*Interface :                                                                 */
/*   IN : const ubyte* ByteSeq                                                */
/*  OUT : ulong Value                                                         */
/*Pre-condition : -                                                           */
/*Constraints :   -                                                           */
/*Behavior:       -                                                           */
/*----------------------------------------------------------------------------*/
extern ulong SYST_ByteSeqLittleEndianToUlong(const ubyte* ByteSeq);
#endif /*Syst_BYTE_SEQ_LITTLE_ENDIAN_TO_ULONG*/


#ifdef Syst_BYTE_SEQ_BIG_ENDIAN_TO_USHORT
/*----------------------------------------------------------------------------*/
/*Name : SYST_ByteSeqBigEndianToUshort                                        */
/*Role : Convert a big endian byte sequence into ushort (16 bits).            */
/*Interface :                                                                 */
/*   IN : const ubyte* ByteSeq                                                */
/*  OUT : ulong Value                                                         */
/*Pre-condition : -                                                           */
/*Constraints :   -                                                           */
/*Behavior:       -                                                           */
/*----------------------------------------------------------------------------*/
extern ushort SYST_ByteSeqBigEndianToUshort(const ubyte* ByteSeq);
#endif /*Syst_BYTE_SEQ_BIG_ENDIAN_TO_USHORT*/


#ifdef Syst_BYTE_SEQ_LITTLE_ENDIAN_TO_USHORT
/*----------------------------------------------------------------------------*/
/*Name : SYST_ByteSeqLittleEndianToUshort                                     */
/*Role : Convert a little endian byte sequence into ushort (16 bits).         */
/*Interface :                                                                 */
/*   IN : const ubyte* ByteSeq                                                */
/*  OUT : ulong Value                                                         */
/*Pre-condition : -                                                           */
/*Constraints :   -                                                           */
/*Behavior:       -                                                           */
/*----------------------------------------------------------------------------*/
extern ushort SYST_ByteSeqLittleEndianToUshort(const ubyte* ByteSeq);
#endif /*Syst_BYTE_SEQ_LITTLE_ENDIAN_TO_USHORT*/

#ifdef SYST_DEBUG_RESET
/*----------------------------------------------------------------------------*/
/*Name : SYST_DebugReset                                                      */
/*Role : Hook for SYST_Reset to facilitate debug on emulator                  */
/*Interface :                                                                 */
/*   IN : -                                                                   */
/*  OUT : -                                                                   */
/*Pre-condition : -                                                           */
/*Constraints :   -                                                           */
/*Behavior:       -                                                           */
/*----------------------------------------------------------------------------*/
extern void SYST_DebugReset(void);
#endif /* SYST_DEBUG_RESET */


/*----------------------------------------------------------------------------*/
/* Name: SYST_ComputeChecksumXOR                                              */
/* Role: Compute the XOR checksum of a table data                             */
/* Interface:                                                                 */
/*   IN : Address  : data pointer                                             */
/*   IN : Size     : data size                                                */
/*  OUT : Checksum : computed checksum                                        */
/* Pre-condition: none                                                        */
/* Constraints: none                                                          */
/*----------------------------------------------------------------------------*/
extern ubyte SYST_ComputeChecksumXOR(ubyte *Address, ubyte Size);

#if defined(__REL_V850_Dx4__) && (defined(SYST_DATA_SAVE_IN_RESET) || defined(SYST_DATA_SAVE_IN_DEEPSTOP))
/*----------------------------------------------------------------------------*/
/* Name: SYST_BackupRam                                                       */
/* Role: Backup/retore data to BURAM (in 32bits access)                       */
/* Interface:                                                                 */
/*   IN : Action : SYST_BKP_STORE: Copy data to Backup RAM (BURAM)            */
/*                 SYST_BKP_RESTORE: Restore data from Backup RAM             */
/*   IN : BkpSecType : The section group to perform:                          */
/*                       - the shared data (SYST_BKP_SEC_BOOT)                */
/*                       - the reset data, data that must be maintained       */
/*                         between 2 reset (SYST_BKP_SEC_BEFORE_INIT)         */
/*                       - the sleep data, data that must be maintained       */
/*                         between 2 sleep (SYST_BKP_SEC_AFTER_INIT)          */
/* Pre-condition: -                                                           */
/* Constraints: -                                                             */
/*----------------------------------------------------------------------------*/
extern void SYST_BackupRam(SYST_BkpAction_t Action, SYST_BkpSecType_t BkpSecType);
/*----------------------------------------------------------------------------*/
/* Name : SYST_UnprotectBackupRam                                             */
/* Role : Enable to write in backup Ram                                       */
/* Interface : -                                                              */
/* Pre-condition :                                                            */
/* Constraints : -                                                            */
/*----------------------------------------------------------------------------*/
extern void SYST_UnprotectBackupRam(void);

/*----------------------------------------------------------------------------*/
/* Name : SYST_ProtectBackupRam                                               */
/* Role : Disable write in backup Ram                                         */
/* Interface : -                                                              */
/* Pre-condition :                                                            */
/* Constraints : -                                                            */
/*----------------------------------------------------------------------------*/
extern void SYST_ProtectBackupRam(void);

#endif /* __REL_V850_DX4__ && (SYST_DATA_SAVE_IN_RESET || SYST_DATA_SAVE_IN_DEEPSTOP) */


#if (defined(SYST_F1x_DEEPSTOP_USED))||(defined(__REL_V850_Dx4__) && (defined(SYST_DATA_SAVE_IN_RESET) || defined(SYST_DATA_SAVE_IN_DEEPSTOP))) 
/*----------------------------------------------------------------------------*/
/* Name : SYST_ClearWakeUpEventInterrupt                                      */
/* Role :                                                                     */
/* Interface : -                                                              */
/* Pre-condition :                                                            */
/* Constraints : -                                                            */
/*----------------------------------------------------------------------------*/
extern void SYST_ClearWakeUpEventInterrupt(void);

/*----------------------------------------------------------------------------*/
/* Name : SYST_ConfigureWakeUpFactors                                         */
/* Role :                                                                     */
/* Interface : -                                                              */
/* Pre-condition :                                                            */
/* Constraints : -                                                            */
/*----------------------------------------------------------------------------*/
extern void SYST_ConfigureWakeUpFactors(void);

#endif /* (defined(SYST_F1x_DEEPSTOP_USED))||(defined(__REL_V850_Dx4__) && (defined(SYST_DATA_SAVE_IN_RESET) || defined(SYST_DATA_SAVE_IN_DEEPSTOP)))  */


#ifdef __GHOS__
/*----------------------------------------------------------------------------*/
/* Name : SYST_GetPhysicalAddress                                             */
/* Role : Get physical address of a data                                      */
/*        With GHS INtegrity, translate virtual address into physical address */
/*        Without GHS INtegrity, do nothing                                   */
/* Interface :                                                                */
/*    IN:  - Pointer to the data                                              */
/*    OUT: - Physical address                                                 */
/* Pre-condition : none                                                       */
/* Constraints : none                                                         */
/*----------------------------------------------------------------------------*/
extern ulong SYST_GetPhysicalAddress(void *DataPtr);
#else
#define SYST_GetPhysicalAddress(x) (x)
#endif /* __GHOS__ */

#ifdef __GHOS__
/*----------------------------------------------------------------------------*/
/* Name : SYST_PrintCpuClocks                                                 */
/* Role : Print System On Chip clocks                                         */
/*        Use INtegrity IO device to print the clocks                         */
/* Interface :                                                                */
/*    IN:  -                                                                  */
/*    OUT: -                                                                  */
/* Pre-condition : none                                                       */
/* Constraints : none                                                         */
/*----------------------------------------------------------------------------*/
extern void SYST_PrintSocClocks(void);
#else
#define SYST_PrintSocClocks()
#endif /* __GHOS__ */


#if !defined(__BOOT_LOADER_LINK__)
/*----------------------------------------------------------------------------*/
/* Name : SYST_GetBootKey                                                     */
/* Role : Get BootKey value in Ram                                            */
/* Interface :                                                                */
/*    IN:  -                                                                  */
/*    OUT: - Boot Key value                                                   */
/* Pre-condition : none                                                       */
/* Constraints : none                                                         */
/*----------------------------------------------------------------------------*/
extern SYST_BootKey_t SYST_GetBootKey(void);

/*----------------------------------------------------------------------------*/
/* Name : SYST_SetBootKey                                                     */
/* Role : Write a BootKey value in Eeprom or Ram                              */
/* Interface :                                                                */
/*    IN:  - Boot Key value                                                   */
/*    IN:  - TRUE to store value in Eeprom, FALSE to store in Ram             */
/*    OUT: - Operation status:                                                */
/*           SYST_IN_PROGRESS if operation in progress                        */
/*           SYST_COMPLETE when operation is completed                        */
/* Pre-condition : none                                                       */
/* Constraints : If Store value in eeprom is requested, must be called until  */
/*               return SYST_COMPLETE                                         */
/*----------------------------------------------------------------------------*/
extern SYST_Status_t SYST_SetBootKey(SYST_BootKey_t BootKey,
                                     bool_t         StoreInEep);
#endif /* !__BOOT_LOADER_LINK__ */


#ifdef __GHOS__
#ifdef SYST_SW_IDENT_TABLE_USED

/*----------------------------------------------------------------------------*/
/* Name : SYST_GetSwPartIdent                                                 */
/* Role : Get Idenitifaction of a Sw Part of the system.                      */
/*        These identifications have been got from Nand Flash memory at       */
/*        system boot time by Boot Loader.                                    */
/* Interface :                                                                */
/*    IN:  - Pointer where to store SW Part Ident                             */
/*         - Sw Part Ident Index:                                             */
/*             SYST_BL_SW_ID_INDEX                                            */
/*             SYST_FLASHER_SW_ID_INDEX                                       */
/*             SYST_CLIENT_SW_ID_INDEX                                        */
/*             SYST_EOL_SW_ID_INDEX                                           */
/*    OUT: - Ident of the requested Sw Part                                   */
/* Pre-condition : none                                                       */
/* Constraints : none                                                         */
/*----------------------------------------------------------------------------*/
extern void SYST_GetSwPartIdent(ubyte *SwIdentPtr, ubyte SwPartIndex);

#ifdef __FLASHER_LINK__
/*----------------------------------------------------------------------------*/
/* Name : SYST_UpdateClientSwIdentFromFlash                                   */
/* Role : Read Idenitifaction of CLIENT Sw Part from Nand Flash memory and    */
/*        update Client SW Part identification information returned by .      */
/*        SYST_GetSwPartIdent service.                                        */
/*        Typically used after a CLIENT Sw Update by FLASHER application.     */
/* Interface :                                                                */
/*    IN:  -                                                                  */
/*    OUT: - Operation status:                                                */
/*           SYST_IN_PROGRESS if operation in progress                        */
/*           SYST_ERROR if operation fails                                    */
/*           SYST_COMPLETE when operation is completed                        */
/* Pre-condition : none                                                       */
/* Constraints : Must be called while returns SYST_IN_PROGRESS                */
/*----------------------------------------------------------------------------*/
extern SYST_Status_t SYST_UpdateClientSwIdentFromFlash(void);
#endif /* __FLASHER_LINK__ */

#endif /* SYST_SW_IDENT_TABLE_USED */
#endif /* __GHOS__ */


/*----------------------------------------------------------------------------*/
/* Function Name : void SYSTShiftDeepStop( void )                             */
/* Description   : This function shifts to DEEPSTOP mode.                     */
/* Argument      : none                                                       */
/* Return Value  : none                                                       */
/*----------------------------------------------------------------------------*/
extern void SYST_ShiftDeepStop( void );

#ifndef __BOOT_LINK__
/*----------------------------------------------------------------------------*/
/* Name           : SYST_ComputeHWCRC16Ccitt                                  */
/* Role           :                                                           */
/* Interface      :                                                           */
/* Returns:       : none                                                      */
/* Pre-condition  :                                                           */
/* Constraints    :                                                           */
/*----------------------------------------------------------------------------*/
extern ushort SYST_ComputeHWCRC16Ccitt(ubyte *crc16_address, ushort crc16_size);

/*----------------------------------------------------------------------------*/
/* Name           : SYST_ComputeHWCRC32                                       */
/* Role           :                                                           */
/* Interface      :                                                           */
/* Returns:       : none                                                      */
/* Pre-condition  :                                                           */
/* Constraints    :                                                           */
/*----------------------------------------------------------------------------*/
extern ulong SYST_ComputeHWCRC32(ubyte *crc32_address, ushort crc32_size);

/*----------------------------------------------------------------------------*/
/* Name           : SYST_GetChipProductName                                   */
/* Role           :                                                           */
/* Interface      :                                                           */
/* Returns:       : none                                                      */
/* Pre-condition  :                                                           */
/* Constraints    :                                                           */
/*----------------------------------------------------------------------------*/

extern void SYST_GetChipProductName(sbyte* product_name);

/*----------------------------------------------------------------------------*/
/*Name : SYST_SetResetCounterAndSetFlag                                       */
/*Role : Give the reset type                                                  */
/*Interface :                                                                 */
/*   IN : -                                                                   */
/*  OUT : -ResetType                                                          */
/*Pre-condition : -                                                           */
/*Constraints : -                                                             */
/* Behavior:                                                                  */
/*   DO                                                                       */
/*    [ return the cause of reset ]                                           */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/
void SYST_SetResetCounterAndSetFlag(void);
#ifdef SYST_UseEMMCRecoverLogic
/*----------------------------------------------------------------------------*/
/* Name           : SYST_GetKL30OffOnFlag                                     */
/* Role           :                                                           */
/* Interface      :                                                           */
/* Returns:       : none                                                      */
/* Pre-condition  :                                                           */
/* Constraints    :                                                           */
/*----------------------------------------------------------------------------*/
extern bool_t SYST_GetKL30OffOnFlag(void);

/*----------------------------------------------------------------------------*/
/* Name           : SYST_SetKL30OffOnFlag                                     */
/* Role           :                                                           */
/* Interface      :                                                           */
/* Returns:       : none                                                      */
/* Pre-condition  :                                                           */
/* Constraints    :                                                           */
/*----------------------------------------------------------------------------*/
extern void SYST_SetKL30OffOnFlag( bool_t value);

/*----------------------------------------------------------------------------*/
/* Name           : SYST_GetSWResetCounter                                    */
/* Role           :                                                           */
/* Interface      :                                                           */
/* Returns:       : none                                                      */
/* Pre-condition  :                                                           */
/* Constraints    :                                                           */
/*----------------------------------------------------------------------------*/
extern ubyte SYST_GetSWResetCounter(void);

/*----------------------------------------------------------------------------*/
/* Name           : SYST_SetSWResetCounter                                    */
/* Role           :                                                           */
/* Interface      :                                                           */
/* Returns:       : none                                                      */
/* Pre-condition  :                                                           */
/* Constraints    :                                                           */
/*----------------------------------------------------------------------------*/
extern void SYST_SetSWResetCounter( ubyte value);

/*----------------------------------------------------------------------------*/
/* Name           : SYST_GetEmmcRecoveryStrategyFlag                          */
/* Role           :                                                           */
/* Interface      :                                                           */
/* Returns:       : none                                                      */
/* Pre-condition  :                                                           */
/* Constraints    :                                                           */
/*----------------------------------------------------------------------------*/
bool_t SYST_GetEmmcRecoveryStrategyFlag(void);

/*----------------------------------------------------------------------------*/
/* Name           : SYST_SetEmmcRecoveryStrategyFlag                          */
/* Role           :                                                           */
/* Interface      :                                                           */
/* Returns:       : none                                                      */
/* Pre-condition  :                                                           */
/* Constraints    :                                                           */
/*----------------------------------------------------------------------------*/
extern  void SYST_SetEmmcRecoveryStrategyFlag( bool_t value);
#endif  /*SYST_UseEMMCRecoverLogic*/

#ifdef SYST_UseLowVolBlockingLogic
/*----------------------------------------------------------------------------*/
/* Name           : SYST_GetKL30OffOnOrExternResetFlag                        */
/* Role           :                                                           */
/* Interface      :                                                           */
/* Returns:       : none                                                      */
/* Pre-condition  :                                                           */
/* Constraints    :                                                           */
/*----------------------------------------------------------------------------*/
extern bool_t SYST_GetKL30OffOnOrExternResetFlag(void);

/*----------------------------------------------------------------------------*/
/* Name           : SYST_SetKL30OffOnOrExternResetFlag                        */
/* Role           :                                                           */
/* Interface      :                                                           */
/* Returns:       : none                                                      */
/* Pre-condition  :                                                           */
/* Constraints    :                                                           */
/*----------------------------------------------------------------------------*/
extern void SYST_SetKL30OffOnOrExternResetFlag( bool_t value);
#endif /*SYST_UseLowVolBlockingLogic*/

/*----------------------------------------------------------------------------*/
/* Name           : SYST_GetSWResetCounterTotal                               */
/* Role           :                                                           */
/* Interface      :                                                           */
/* Returns:       : none                                                      */
/* Pre-condition  :                                                           */
/* Constraints    :                                                           */
/*----------------------------------------------------------------------------*/
extern  ubyte SYST_GetSWResetCounterTotal(void);

/*----------------------------------------------------------------------------*/
/* Name           : SYST_SetSWResetCounterTotal                               */
/* Role           :                                                           */
/* Interface      :                                                           */
/* Returns:       : none                                                      */
/* Pre-condition  :                                                           */
/* Constraints    :                                                           */
/*----------------------------------------------------------------------------*/
extern  void SYST_SetSWResetCounterTotal( ubyte value);

/*----------------------------------------------------------------------------*/
/* Name           : SYST_GetPowerOnFlag                                       */
/* Role           :                                                           */
/* Interface      :                                                           */
/* Returns:       : none                                                      */
/* Pre-condition  :                                                           */
/* Constraints    :                                                           */
/*----------------------------------------------------------------------------*/
extern  int SYST_GetPowerOnFlag(void );
#endif /* __BOOT_LINK__ */
#endif /* SYST_H */
#endif //#ifdef __CY_TV2__
/*_____ E N D _____ (syst.h) _________________________________________________*/
