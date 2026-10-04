/******************************************************************************/
/*@F_NAME:           syst.h                                                   */
/*@F_PURPOSE:        syst - Module description                                */
/*@F_CREATED_BY:     Yanbin SHEN                                              */
/*@F_CREATION_DATE:  Jun/22/2020                                              */
/*@F_LANGUAGE :      ANSI C                                                   */
/*@F_MPROC_TYPE:     Processor independent                                    */
/************************************** (C) Copyright 2020 Magneti Marelli ****/
#ifndef SYST_TVII_H
#define SYST_TVII_H

/*_____ I N C L U D E - F I L E S ____________________________________________*/

/* Definition of NULL macro */
/* (To avoid #include <std lib file> before syst.h in C source file) */
#include <string.h>

#include "type.h"
#include "targ.h"
#include "cy_device_headers.h"
#include "Platform_Types.h"
#include "syst_config.h"
#if defined(__RTOS__)
/* FreeRTOS Interface */
#include "rtos.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
#include "timers.h"
#include "cmsis_ghs.h"
#endif /*__RTOS__*/
#include "tcb.h"
#include "cy_syspm.h"
/*______ G L O B A L - D E F I N E S _________________________________________*/
#define SYST_WUF0
#define SYST_WUFC0
#define SYST_WUFMSK0

#define SYST_WUF20
#define SYST_WUFC20
#define SYST_WUFMSK20

#define SYST_WUF_ISO0
#define SYST_WUFC_ISO0
#define SYST_WUFMSK_ISO0

typedef ulong SYST_BootKey_t;
#define  SYST_EOL               ((SYST_BootKey_t) 0x5678U)
#define  SYST_FLASHER           ((SYST_BootKey_t) 0x1234U)
#define  SYST_CLIENT            ((SYST_BootKey_t) 0x9ABCU)
#define  SYST_EOL_COMP          ((SYST_BootKey_t) ~SYST_EOL)
#define  SYST_FLASHER_COMP      ((SYST_BootKey_t) ~SYST_FLASHER)
#define  SYST_CLIENT_COMP       ((SYST_BootKey_t) ~SYST_CLIENT)
#define  SYST_KEY_DEFAULT_VALUE ((SYST_BootKey_t) 0xFFFFU)


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

typedef enum
{
  SYST_WAIT_WAKEUP = 0,
  SYST_FROM_SLEEP_TO_WAKEUP,
  SYST_FROM_DEEPSLEEP_TO_WAKEUP,
  SYST_FROM_HIBERNATE_TO_WAKEUP,
}SYST_SleepMode_t;

typedef struct
{
  ulong* Start;
  ulong* End;
  ulong* Backup;
} Syst_BkpSec_t;

typedef SYST_BkpKey_t SYST_SleepKey_t;
#define SYST_SLEEP              SYST_BKP_KEY_VALID
#define SYST_NO_SLEEP           SYST_BKP_KEY_UNVALID

typedef struct
{
  ubyte   Day;
  ubyte   Month;
  ubyte   Year;
} SYST_Date_t;

/* ATTENTION, Do not change : Must be included here because syst_config.h     */
/* requires type definition done above in this file                           */
#include "syst_config.h"

#if 0   /* disable for compiling */
#include "syst_config_eep.h"
#endif



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
extern SYST_BootKey_t SYST_BOOT_KEY_RAM;
extern SYST_BootKey_t SYST_BOOT_KEY_RAM_COMP;

extern SYST_SleepKey_t SYST_SLEEP_KEY_RAM;

extern const SYST_SwIdentifier_t SYST_SwIdentifier;

extern SYST_SleepMode_t SYST_SleepMode;

/*_____ I N C L U D E - F I L E - F O R - S Y S T E M - D E F I N I T I O N __*/

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
    #else
    #ifdef C_COMP_GHS_V850
      #ifdef __NEC_V850_Fx3__
      #endif /* __NEC_V850_Fx3__ */

      #ifdef __NEC_V850_Dx3__
      #endif /* __NEC_V850_Dx3__ */

      #ifdef __REL_V850_Dx4__
        /* Generate an immediate internal softw are reset */

        #if defined(SYST_DATA_SAVE_IN_RESET)
        #else


        #endif /* SYST_DATA_SAVE_IN_RESET */
      #endif /* __REL_V850_Dx4__ */
    #else

    #ifdef C_COMP_IAR_RL78	

      #ifdef __REL_RL78__
      #if((defined(__REL_RL78_D1x__)) || (defined(__REL_RL78_F1x__)))
      #if((defined(__REL_RL78_D1A__)) || (defined(__REL_RL78_F12__)))
      /* Generate an immediate internal watchdog reset */
      #endif /*__REL_RL78_D1A__ || __REL_RL78_F12__*/
      #endif /*__REL_RL78_D1x__ || __REL_RL78_F1x__*/
      #endif /*__REL_RL78__*/

    #else

    #if defined(__FSL_IMX53x__) || defined(__FSL_IMX6x__)

    #elif defined(__RH850_F1x__) && !defined(__BOOT_LINK__)
    #if defined(__RH850_F1K__) || defined(__RH850_F1L__)
    #endif /*defined(__RH850_F1K__) || defined(__RH850_F1L__)*/

    #else

    #endif /* __FSL_IMX53x__,__FSL_IMX6x__ */
    #endif /* C_COMP_IAR_RL78 */
    #endif /* C_COMP_GHS_V850 */
    #endif /* C_COMP_COSMIC_MC9S12 */
  #else
    #ifdef SYST_DEBUG_RESET
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
#define SYST_StopOsTick()


/*----------------------------------------------------------------------------*/
/* Defines and Macros for Power Modes management                              */
/*----------------------------------------------------------------------------*/
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


/*_____ G L O B A L - F U N C T I O N S - P R O T O T Y P E S ________________*/

/*----------------------------------------------------------------------------*/
/*Name : SYST_Init                                                            */
/*Role : Init this module                                                     */
/*Interface : void                                                            */
/*Pre-condition : -                                                           */
/*Constraints : Call one time at reset                                        */
/*----------------------------------------------------------------------------*/
extern void SYST_Init(void);

/*----------------------------------------------------------------------------*/
/*Name : _start                                                               */
/*Role : Start and jump to dr7f701030_startup.850                             */
/*Interface : void                                                            */
/*Pre-condition : -                                                           */
/*Constraints : Call one time at reset                                        */
/*----------------------------------------------------------------------------*/
extern void _start(void);



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


/*----------------------------------------------------------------------------*/
/* Internal sub-macro for SYST_Wait(x) - DO NOT USE !!! */

#ifdef Syst_WAIT_SERVICE
#ifndef __PC_SIMULATION__
extern void SYST_WaitLoop(ushort Syst_delay);
#else
#define SYST_WaitLoop(Syst_delay)
#endif /* !__PC_SIMULATION__ */
#endif /* Syst_WAIT_SERVICE */







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



#endif /* Syst_READ_ROM_SERVICE */




/* Factory Lock / Unlock cluster */
typedef enum
{
  SYST_FACTORY_LOCK   = 0x01,
  SYST_FACTORY_UNLOCK = 0xFF
} SYST_FactoryLock_t;

typedef enum
{
  SYST_POWER_ON = 0,
  SYST_SW_RESET,
  SYST_RESET_WDG,
  SYST_RESET_CLOCK,
  SYST_RESET_EXT_OR_POWER,
  SYST_WAKE_UP,
  SYST_DEEPSTOP_RESET,
  SYST_RESET_ACT_FAULT,
  SYST_RESET_BODVXXX,
  SYST_RESET_OVDVXXX,
  SYST_RESET_OCDXXX,
  SYST_RESET_PMIC,
  SYST_RESET_PXRES,
  SYST_RESET_STRUCT_XRES,
  SYST_RESET_TC_DBGRESET,
  SYST_RESET_UNKNOW
} SYST_ResetType_t;

typedef ulong SYST_AddressWidth_t;

/* Perform a software reset if early wake-up occurs */


#define __NOP__   __asm("NOP")// asm("nop");

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

/******************************************************************************/
/* Name : ISR                                                                 */
/* Role : Interrupt service routine declaration macro                         */
/* Interface : OSEK compliant                                                 */
/* Pre-condition : none                                                       */
/* Constraints : Must be used to declare all user ISR                         */
/******************************************************************************/
#define ISR(x)  void (x)(void)


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

#define SYST_Reset() while(1)\
                 {\
                NVIC_SystemReset();\
                 }

#endif /*SYST_TVII_H*/



