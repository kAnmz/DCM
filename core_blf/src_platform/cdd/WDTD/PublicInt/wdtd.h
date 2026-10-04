/******************************************************************************/
/* @F_NAME:          wdtd.h                                                   */
/* @F_PURPOSE:       Public interface for watchdog timer                      */
/* @F_CREATED_BY:    D. KOCH                                                  */
/* @F_CREATION_DATE: 23/05/01                                                 */
/* @F_LANGUAGE :     ANSI C                                                   */
/* @F_MPROC_TYPE:    NEC_V850 Fx3/Dx3/Dx4, MC9S12xx, MC9S08xx, TX49, IMX534,  */
/*                   IMX6x, REL RL78_D1A, REL RL78_F12                        */
/************************************** (C) Copyright 2013 Magneti Marelli ****/

#ifndef WDTD_H
#define WDTD_H

/* _____ I N C L U D E - F I L E S ___________________________________________*/

#include "syst.h"
#include "wdtd_config.h"


/******************************************************************************/
/*  NEC V850 CODE                                                             */
/******************************************************************************/
#ifdef __NEC_V850__

/* _____ G L O B A L - D E F I N E S _________________________________________*/

#ifdef __NEC_V850_Dx3__
#define Wdt_WDTMode_Is_RESWDT         (ubyte)(WDG_MSK_WDTMODE  )
#define Wdt_WDTMode_Is_RESWDT_And_Run (ubyte)(WDG_MSK_WDTMODE+WDG_MSK_RUN)
#define Wdt_RefreshWdg                (ubyte)(WDG_MSK_WDTMODE+WDG_MSK_RUN)
#endif /*__NEC_V850_Dx3__*/
#if defined (__NEC_V850_Fx3__) || defined (__REL_V850_Dx4__)
#define Wdt_RefreshWdg                (ubyte)(0xAC)
#endif /* __NEC_V850_Fx3__ || __REL_V850_Dx4__ */

#ifdef __NEC_V850_Dx3__
/* Watchdog time-out definition                                               */
/* WARNING:                                                                   */
/* The following values are available when internal oscillator (240 kHz) is   */
/* the Watchdog input clock with a divider of 1/1. (WCC default configuration)*/
/* These values are not available if main oscillator or sub oscillator is the */
/* watchdog input clock                                                       */
#define WDTD_TIME_OUT_34_MS     ((ubyte)(0x00))
#define WDTD_TIME_OUT_68_MS     ((ubyte)(0x01))
#define WDTD_TIME_OUT_136_MS    ((ubyte)(0x02))
#define WDTD_TIME_OUT_273_MS    ((ubyte)(0x03))
#define WDTD_TIME_OUT_546_MS    ((ubyte)(0x04))
#define WDTD_TIME_OUT_1092_MS   ((ubyte)(0x05))
#define WDTD_TIME_OUT_2184_MS   ((ubyte)(0x06))
#define WDTD_TIME_OUT_4369_MS   ((ubyte)(0x07))

/* WARNING:                                                                   */
/* The following values are available when main osc is Watchdog input clock   */
/* with a divider of 1/16 specified in WCC( WCC.WPS2=1 WCC.WPS1=0 WCC.WPS0=0  */
/* These values are not available if internal oscillator or sub oscillator is */
/* the watchdog input clock                                                   */
#define WDTD_TIME_OUT_32_MS     ((ubyte)(0x00))
#define WDTD_TIME_OUT_65_MS     ((ubyte)(0x01))
#define WDTD_TIME_OUT_131_MS    ((ubyte)(0x02))
#define WDTD_TIME_OUT_262_MS    ((ubyte)(0x03))
#define WDTD_TIME_OUT_524_MS    ((ubyte)(0x04))
#define WDTD_TIME_OUT_1048_MS   ((ubyte)(0x05))
#define WDTD_TIME_OUT_2097_MS   ((ubyte)(0x06))
#define WDTD_TIME_OUT_4194_MS   ((ubyte)(0x07))

/* WARNING:                                                                   */
/* The following values are available when sub oscillator (32 kHz) is the     */
/* Watchdog input clock with a divider of 1/1. (WCC default configuration)    */
/* These values are not available if ring oscillator is watchdog input clock  */
#define WDTD_TIME_OUT_256_MS    ((ubyte)(0x00))
#define WDTD_TIME_OUT_512_MS    ((ubyte)(0x01))
#define WDTD_TIME_OUT_1024_MS   ((ubyte)(0x02))
#define WDTD_TIME_OUT_2048_MS   ((ubyte)(0x03))
#define WDTD_TIME_OUT_4096_MS   ((ubyte)(0x04))
#define WDTD_TIME_OUT_8192_MS   ((ubyte)(0x05))
#define WDTD_TIME_OUT_16384_MS  ((ubyte)(0x06))
#define WDTD_TIME_OUT_32768_MS  ((ubyte)(0x07))

#ifdef WDTD_INTERNAL_OSCILLATOR
#define Wdtd_WCC_CONFIGURATION (CLO_MSK_SOSTP | CLO_MSK_WDTSEL1)
#else
#ifdef WDTD_MAIN_OSCILLATOR
#define Wdtd_WCC_CONFIGURATION (CLO_MSK_SOSTP | CLO_MSK_WPS2 | CLO_MSK_ROSTP | CLO_MSK_WDTSEL1 | CLO_MSK_WDTSEL0)
#else
#ifdef WDTD_SUB_OSCILLATOR
#define Wdtd_WCC_CONFIGURATION (CLO_MSK_ROSTP | CLO_MSK_SOSCW | CLO_MSK_WDTSEL1)
#else
#error "You have to choose clock oscillator"
#endif /* Wdtd_SUB_OSCILLATOR */
#endif /* Wdtd_MAIN_OSCILLATOR */
#endif /* WDTD_INTERNAL_OSCILLATOR */
#endif /*__NEC_V850_Dx3__*/

#ifdef __REL_V850_Dx4__
/* Watchdog time-out definition (WDTAnMD.WDTAnOVF = WDTATCKI / 2^9 to 2^16) */

#ifdef WDTD_INTERNAL_OSCILLATOR_DIV_1
#define Wdtd_WCC_CONFIGURATION CLO_CKS_LRNG_1
/* WARNING:                                                                 */
/* The following values are available when (Low Speed IntOsc [240 kHz] / 1) */
/* is the Window Watchdog Timer A input clock (WDTACKI).                    */
#define WDTD_TIME_OUT_2_MS      ((ubyte)(0x00))
#define WDTD_TIME_OUT_4_MS      ((ubyte)(0x10))
#define WDTD_TIME_OUT_9_MS      ((ubyte)(0x20))
#define WDTD_TIME_OUT_17_MS     ((ubyte)(0x30))
#define WDTD_TIME_OUT_34_MS     ((ubyte)(0x40))
#define WDTD_TIME_OUT_68_MS     ((ubyte)(0x50))
#define WDTD_TIME_OUT_137_MS    ((ubyte)(0x60))
#define WDTD_TIME_OUT_273_MS    ((ubyte)(0x70))
#else
#ifdef WDTD_INTERNAL_OSCILLATOR_DIV_4
#define Wdtd_WCC_CONFIGURATION CLO_CKS_LRNG_4

#ifdef SYST_DX4_DEEPSTOP_USED
#define Wdtd_WCC_CONFIGURATION_A0 CLO_CKS_LRNG_512
#endif /*SYST_DX4_DEEPSTOP_USED*/
/* WARNING:                                                                 */
/* The following values are available when (Low Speed IntOsc [240 kHz] / 4) */
/* is the Window Watchdog Timer A input clock (WDTACKI).                    */
#define WDTD_TIME_OUT_9_MS      ((ubyte)(0x00))
#define WDTD_TIME_OUT_17_MS     ((ubyte)(0x10))
#define WDTD_TIME_OUT_34_MS     ((ubyte)(0x20))
#define WDTD_TIME_OUT_68_MS     ((ubyte)(0x30))
#define WDTD_TIME_OUT_137_MS    ((ubyte)(0x40))
#define WDTD_TIME_OUT_273_MS    ((ubyte)(0x50))
#define WDTD_TIME_OUT_546_MS    ((ubyte)(0x60))
#define WDTD_TIME_OUT_1092_MS   ((ubyte)(0x70))
#ifdef SYST_DX4_DEEPSTOP_USED
#define WDTD_TIME_OUT_69905_MS  ((ubyte)(0x60))   /* for WDTA0 in Deepstop */
#endif /* SYST_DX4_DEEPSTOP_USED */
#else
#ifdef WDTD_INTERNAL_OSCILLATOR_DIV_512
#define Wdtd_WCC_CONFIGURATION CLO_CKS_LRNG_512
/* WARNING:                                                                   */
/* The following values are available when (Low Speed IntOsc [240 kHz] / 512) */
/* is the Window Watchdog Timer A input clock (WDTACKI) - WDTA0 only.         */
#define WDTD_TIME_OUT_1092_MS   ((ubyte)(0x00))
#define WDTD_TIME_OUT_2185_MS   ((ubyte)(0x10))
#define WDTD_TIME_OUT_4369_MS   ((ubyte)(0x20))
#define WDTD_TIME_OUT_8738_MS   ((ubyte)(0x30))
#define WDTD_TIME_OUT_17476_MS  ((ubyte)(0x40))
#define WDTD_TIME_OUT_34953_MS  ((ubyte)(0x50))
#define WDTD_TIME_OUT_69905_MS  ((ubyte)(0x60))
#define WDTD_TIME_OUT_139810_MS ((ubyte)(0x70))
#else
#error "You have to choose clock oscillator"
#endif /* WDTD_INTERNAL_OSCILLATOR_DIV_512 */
#endif /* WDTD_INTERNAL_OSCILLATOR_DIV_4 */
#endif /* WDTD_INTERNAL_OSCILLATOR_DIV_1 */

/* Available settings for open window size - WDTAnMD.WDTAnWS[1:0] bits */
#ifdef WDTD_WINDOW_FUNCTION_ON
#define WDTD_WINDOW_SIZE_25   ((ubyte)0x00)
#define WDTD_WINDOW_SIZE_50   ((ubyte)0x01)
#define WDTD_WINDOW_SIZE_75   ((ubyte)0x02)
#define WDTD_WINDOW_SIZE_100  ((ubyte)0x03)
#endif /* WDTD_INTERNAL_OSCILLATOR_DIV_1 */
#endif /*__REL_V850_Dx4__*/

#ifdef __NEC_V850_Fx3__
/* WARNING:                                                                   */
/* values from 0x00 to 0x07: WDT clock is 240 kHz internal ring oscillator    */
/* values from 0x08 to 0x0F: WDT clock is MainOSC frequency (external crystal */
/* value changes selectable WDT time out)                                     */
/* Exemple when Fx = 5 MHz (Crystal main oscillator)                          */
/* 0x09 => clock period = 2^17/Fx = 2^17/(5.10^6) = 26.2144 ms                */
/* Exemple when Fx = 4 MHz (Crystal main oscillator)                          */
/* 0x09 => clock period = 2^17/Fx = 2^17/(4.10^6) = 32.8 ms                   */
/* Following definition is based on 5 MHz Main oscillator, in case of other   */
/* value, you will have to redefine enum from 0x08 to 0x0F                    */
#define WDTD_TIME_OUT_17_MS     ((ubyte)(0x00))
#define WDTD_TIME_OUT_34_MS     ((ubyte)(0x01))
#define WDTD_TIME_OUT_68_MS     ((ubyte)(0x02))
#define WDTD_TIME_OUT_136_MS    ((ubyte)(0x03))
#define WDTD_TIME_OUT_273_MS    ((ubyte)(0x04))
#define WDTD_TIME_OUT_546_MS    ((ubyte)(0x05))
#define WDTD_TIME_OUT_1092_MS   ((ubyte)(0x06))
#define WDTD_TIME_OUT_2184_MS   ((ubyte)(0x07))
#define WDTD_TIME_OUT_13_MS     ((ubyte)(0x08))
#define WDTD_TIME_OUT_26_MS     ((ubyte)(0x09))
#define WDTD_TIME_OUT_52_MS     ((ubyte)(0x0A))
#define WDTD_TIME_OUT_104_MS    ((ubyte)(0x0B))
#define WDTD_TIME_OUT_209_MS    ((ubyte)(0x0C))
#define WDTD_TIME_OUT_419_MS    ((ubyte)(0x0D))
#define WDTD_TIME_OUT_838_MS    ((ubyte)(0x0E))
#define WDTD_TIME_OUT_1677_MS   ((ubyte)(0x0F))
#endif /*__NEC_V850_Fx3__*/


/* _____ G L O B A L - T Y P E S _____________________________________________*/


/* _____ G L O B A L - D A T A _______________________________________________*/


/* _____ G L O B A L - M A C R O S ___________________________________________*/

/*----------------------------------------------------------------------------*/
/* Name : WDTD_Init                                                           */
/* Role : Configure the watchdog timer clock prescaler                        */
/* Interface : TimePrescaler   IN  Value of the prescaler                     */
/*                                 [0 to 7]                                   */
/* Pre-condition :                                                            */
/* The WDG is always clocked by the ring oscillator (240KHz typ.)             */
/* to safety reasons and so the watch is always active even when the main     */
/* clock is stop                                                              */
/* For Dx3, WCC=0xCB (register can be set only once after any reset)          */
/*    -SubOSC stop in STOP mode  (bit SOTP)                                   */
/*    -WDT clock divider = 1/16 (bits WPS2 WPS1 WPS0)                         */
/*    -RingOsc Stop if WATCH, Sub WATCH or STOP mode(bit ROSTP)               */
/*    -Watchdog timer clock is main osc (bits SOSCW WDTSEL1)                  */
/*    -For DG3: WDTCLK operates as long as the selected clock source operates */
/*     configured by WDTDSEL1 available for DG3 uC, need to be set to "1" for */
/*     DL3,DJ3 uC                                                             */
/* Moreover, thh WDG generates always on reset (no configuration for NMI)     */
/* Constraints : None                                                         */
/* Behavior :                                                                 */
/*   DO                                                                       */
/*     [Configure the counter]                                                */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/
#ifdef __NEC_V850_Fx3__
#define WDTD_Init()     \
        TARG_WriteByte(WDTM2, WDTD_TIME_OUT + TIM_MSK_WDM21)
#endif /*__NEC_V850_Fx3__*/

#ifdef __NEC_V850_Dx3__
#define WDTD_Init()                                             \
        TARG_WriteByte(PHCMD, Wdtd_WCC_CONFIGURATION);          \
        TARG_WriteByte(WCC  , Wdtd_WCC_CONFIGURATION);          \
        TARG_WriteByte(WCMD , Wdt_WDTMode_Is_RESWDT);           \
        TARG_WriteByte(WDTM , Wdt_WDTMode_Is_RESWDT);           \
        TARG_WriteByte(WCMD , WDTD_TIME_OUT);                   \
        TARG_WriteByte(WDCS , WDTD_TIME_OUT)
#endif /*__NEC_V850_Dx3__*/

#ifdef __REL_V850_Dx4__
/* WDTA0 configuration - WDTA0MD register                        */
/* . Selects the count clock and thus the overflow interval time */
/* . 75% interrupt request INTWDTn disabled                      */
/* . Error mode set to Reset mode                                */
/* . Open window size set to 100% if window function defined on  */
#ifndef SYST_DX4_DEEPSTOP_USED
#ifdef WDTD_WINDOW_FUNCTION_ON
#define WDTD_Init() \
        TARG_WriteByte(WDTA0MD , (WDTD_TIME_OUT | WDG_MSK_WDTAnERM \
                                                | WDTD_WINDOW_SIZE))
#else
#define WDTD_Init() \
        TARG_WriteByte(WDTA0MD , (WDTD_TIME_OUT | WDG_MSK_WDTAnERM \
                                                | WDG_MSK_WDTAnWS))
#endif /* WDTD_WINDOW_FUNCTION_ON */
#endif /* !SYST_DX4_DEEPSTOP_USED */

#ifdef SYST_DX4_DEEPSTOP_USED
/* WDTA0 configuration - WDTA0MD register                        */
/* . Selects the count clock and thus the overflow interval time */
/* . 75% interrupt request INTWDTn disabled                      */
/* . Error mode set to Reset mode                                */
/* . Open window size set to 100% if window function defined on  */
/*in deepstop: only WDTA0 active                                 */
/*in normal operation: both WDTA0 & WDTA1 active with different  */
/*                     configurations                            */
#ifdef WDTD_WINDOW_FUNCTION_ON
#define WDTD_Init() \
        TARG_WriteByte(WDTA0MD , (WDTD_TIME_OUT_A0 | WDG_MSK_WDTAnERM \
                                                   | WDTD_WINDOW_SIZE));\
	    TARG_WriteByte(WDTA1MD , (WDTD_TIME_OUT | WDG_MSK_WDTAnERM \
                                                | WDTD_WINDOW_SIZE))
#else
#define WDTD_Init() \
        TARG_WriteByte(WDTA0MD , (WDTD_TIME_OUT_A0 | WDG_MSK_WDTAnERM \
                                                   | WDG_MSK_WDTAnWS));\
		TARG_WriteByte(WDTA1MD , (WDTD_TIME_OUT | WDG_MSK_WDTAnERM \
                                                | WDG_MSK_WDTAnWS))
												
#endif /* WDTD_WINDOW_FUNCTION_ON */
#endif /* SYST_DX4_DEEPSTOP_USED */
#endif /*__REL_V850_Dx4__*/

/*----------------------------------------------------------------------------*/
/* Name : WDTD_Stop                                                           */
/* Role : Stop the watchdog timer                                             */
/* Interface : None                                                           */
/* Pre-condition : For Fx3, Must be permitted by flash mask options           */
/* Constraints : None                                                         */
/* Behavior :                                                                 */
/*   DO                                                                       */
/*     [Stop the Watchdog timer]                                              */
/*     [Nothing for DX3, the WDG is cannot be stopped                         */
/*     [Nothing for FX3, the WDG is cannot be stopped because, WDTM2 register */
/*     [can be written only 1 time and this register is at init               */
/*     [Nothing for Dx4, WDTA can not be stopped once it was started]         */
/*     [WDTAnWDTE.WDTAnRUN bit can only be cleared by a reset]                */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/
#ifdef __NEC_V850_Fx3__
#define WDTD_Stop()
#endif /*__NEC_V850_Fx3__*/

#ifdef __NEC_V850_Dx3__
#define WDTD_Stop()
#endif /*__NEC_V850_Dx3__*/

#ifdef __REL_V850_Dx4__
#define WDTD_Stop()
#endif /*__REL_V850_Dx4__*/

/*----------------------------------------------------------------------------*/
/* Name : WDTD_Start                                                          */
/* Role : Start the watchdog timer                                            */
/* Interface : None                                                           */
/* Pre-condition : None                                                       */
/* Constraints : None                                                         */
/* Behavior :                                                                 */
/*   DO                                                                       */
/*     [Nothing for FX3, by default the WDG is started and can not be         */
/*                  restarted if the WDG is stopped]                          */
/*     [Only WDTA0 is started for Dx4 - in non-Varying Activation Code mode]  */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/
#ifdef __NEC_V850_Fx3__
#define WDTD_Start()
#endif /*__NEC_V850_Fx3__*/

#ifdef __NEC_V850_Dx3__
/*#define WDTD_Start()*/
#define WDTD_Start()                                            \
        TARG_WriteByte(WCMD, Wdt_WDTMode_Is_RESWDT_And_Run);    \
        TARG_WriteByte(WDTM, Wdt_WDTMode_Is_RESWDT_And_Run)
#endif /*__NEC_V850_Dx3__*/

#ifdef __REL_V850_Dx4__
#ifndef SYST_DX4_DEEPSTOP_USED
#define WDTD_Start() \
        TARG_WriteByte(WDTA0WDTE, Wdt_RefreshWdg)
#endif /* SYST_DX4_DEEPSTOP_USED */

#ifdef SYST_DX4_DEEPSTOP_USED		
#define WDTD_Start() \
        TARG_WriteByte(WDTA0WDTE, Wdt_RefreshWdg);\
		TARG_WriteByte(WDTA1WDTE, Wdt_RefreshWdg)
#endif /* SYST_DX4_DEEPSTOP_USED */
#endif /*__REL_V850_Dx4__*/

/*----------------------------------------------------------------------------*/
/* Name : WDTD_Refresh                                                        */
/* Role : Clear the timer to prevent overflow (RESET)                         */
/* Interface : None                                                           */
/* Pre-condition : None                                                       */
/* Constraints : None                                                         */
/* Behavior :                                                                 */
/*   DO                                                                       */
/*   For Fx3, write 0xAC into WDTE => WDG counter is cleared and couting      */
/*                                      couting restarted                     */
/*   For Dx3, write one byte to the WCMD regsiter (the value is ignored)      */
/*            immediately after that, write one byte to WDTM regsiter (the    */
/*           is ignored                                                       */
/*   For Dx4, Only WDTA0 is refreshed - in non-Varying Activation Code mode   */
/*            Writing ACH to register WDTA0WDTE restarts the counter          */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/
#ifdef __NEC_V850_Fx3__
#define WDTD_Refresh() \
        TARG_WriteByte(WDTE, Wdt_RefreshWdg)
#endif /*__NEC_V850_Fx3__*/

#ifdef __NEC_V850_Dx3__
/*#define WDTD_Refresh()*/
#define WDTD_Refresh()                          \
        do                                      \
        {                                       \
          TARG_WriteByte(WPHS, 0);              \
          TARG_WriteByte(WCMD, Wdt_RefreshWdg); \
          TARG_WriteByte(WDTM, Wdt_RefreshWdg); \
        } while (TARG_ReadByte(WPHS) != 0)
#endif /*__NEC_V850_Dx3__*/

#ifdef __REL_V850_Dx4__
#ifndef SYST_DX4_DEEPSTOP_USED
#define WDTD_Refresh() \
        TARG_WriteByte(WDTA0WDTE, Wdt_RefreshWdg)
#endif /* SYST_DX4_DEEPSTOP_USED */

#ifdef SYST_DX4_DEEPSTOP_USED		
#define WDTD_Refresh() \
        TARG_WriteByte(WDTA0WDTE, Wdt_RefreshWdg);\
		TARG_WriteByte(WDTA1WDTE, Wdt_RefreshWdg)
#endif /* SYST_DX4_DEEPSTOP_USED */

#endif /*__REL_V850_Dx4__*/


/* _____ G L O B A L -  F U N C T I O N S - P R O T O T Y P E S ______________*/

#endif /* __NEC_V850__ */


/******************************************************************************/
/*  MOTOROLA STAR12 CODE                                                      */
/******************************************************************************/
#ifdef __MC9S12xx__

/*______ G L O B A L - D E F I N E S _________________________________________*/


/*______ G L O B A L - T Y P E S _____________________________________________*/


/*______ G L O B A L - D A T A _______________________________________________*/


/*______ G L O B A L - M A C R O S ___________________________________________*/

/*----------------------------------------------------------------------------*/
/* Name : WDTD_Init                                                           */
/* Role : interface compatibility                                             */
/* Interface : None                                                           */
/* Pre-condition : None                                                       */
/* Constraints : None                                                         */
/* Behavior : None                                                            */
/*----------------------------------------------------------------------------*/
#define WDTD_Init()

/*----------------------------------------------------------------------------*/
/* Name : WDTD_Start                                                          */
/* Role : Configure and start the watchdog timer                              */
/* Interface : None                                                           */
/* Pre-condition : call once only in the life of product (in BLF)             */
/* Constraints :                                                              */
/*              For Star12, COP set-up can be done only once, and we have     */
/*              chossen to do it in SYST_SetCpu( ) for robustness.            */
/*              Must be a macro and not a function because stack pointer is   */
/*              not set when this service is used not.                        */
/*              It is the first processor instruction, therefore register are */
/*              not mapped -> use reset address for copctl register           */
/* Behavior :                                                                 */
/*   DO                                                                       */
/*     [Configure the time-out period ]                                       */
/*     [Launch the counter]                                                   */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/
#define WDTD_Start() \
        TARG_WriteByte(COPCTL_BASE, (WDTD_MODE | WDTD_STATE_IN_BDM | WDTD_CLCK_PRESCALE) );\
        TARG_WriteByte(ARMCOP_BASE, 0x55);\
        /* begin Motorola work-around*/\
        __NOP__;\
        __NOP__;\
        __NOP__;\
        __NOP__;\
        __NOP__;\
        __NOP__;\
        __NOP__;\
        __NOP__;\
        __NOP__;\
        __NOP__;\
        /* end Motorola work-around*/\
        TARG_WriteByte(ARMCOP_BASE, 0xAA)

/*----------------------------------------------------------------------------*/
/* Name : WDTD_Refresh                                                        */
/* Role : Refresh the timer to prevent overflow (RESET)                       */
/* Interface : void                                                           */
/* Pre-condition : void                                                       */
/* Constraints : None                                                         */
/* Behavior :                                                                 */
/*   DO                                                                       */
/*     [reset the counter]                                                    */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/
#define WDTD_Refresh()\
        TARG_WriteByte(ARMCOP, 0x55);\
        /* begin Motorola work-around*/\
        __NOP__;\
        __NOP__;\
        __NOP__;\
        __NOP__;\
        __NOP__;\
        __NOP__;\
        __NOP__;\
        __NOP__;\
        __NOP__;\
        __NOP__;\
        /* end Motorola work-around*/\
        TARG_WriteByte(ARMCOP, 0xAA)


/*______ G L O B A L - F U N C T I O N S - P R O T O T Y P E S _______________*/


#endif /* __MC9S12xx__ */


/******************************************************************************/
/*  Freescale S08 Code                                                        */
/******************************************************************************/
#ifdef __MC9S08xx__

/*______ G L O B A L - D E F I N E S _________________________________________*/


/*______ G L O B A L - T Y P E S _____________________________________________*/


/*______ G L O B A L - D A T A _______________________________________________*/


/*______ G L O B A L - M A C R O S ___________________________________________*/

/*----------------------------------------------------------------------------*/
/* Name : WDTD_Init                                                           */
/* Role : Configure the watchdog mode and timeout period                      */
/* Interface : None                                                           */
/* Pre-condition : None                                                       */
/* Constraints :                                                              */
/*              For S08AW, Watchdog is active at Reset                        */
/*                                                                            */
/*   DO                                                                       */
/*     [Configure the time-out period and WAIT mode ]                         */
/*     [Reset the counter]                                                    */
/*   OD                                                                       */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#define WDTD_Init()\
        TARG_WriteByte(SOPT, (WDTD_DEFAULT_MODE |\
                              WDTD_MODE | \
                              WDTD_CLCK_TIMEOUT |\
                              WDTD_STOPMODE));\
        TARG_WriteByte(SRS, 0xFF)                      /* Reset Watchdog      */

/*----------------------------------------------------------------------------*/
/* Name : WDTD_Start                                                          */
/* Role : None                                                                */
/* Interface : None                                                           */
/* Pre-condition : None                                                       */
/* Constraints : None                                                         */
/*----------------------------------------------------------------------------*/
#define WDTD_Start()

/*----------------------------------------------------------------------------*/
/* Name : WDTD_Refresh                                                        */
/* Role : Refresh the timer to prevent overflow (RESET)                       */
/* Interface : void                                                           */
/* Pre-condition : void                                                       */
/* Constraints : None                                                         */
/* Behavior :                                                                 */
/*   DO                                                                       */
/*     [reset the counter]                                                    */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/
#define WDTD_Refresh()\
        TARG_WriteByte(SRS, 0xFF);\


/*______ G L O B A L - F U N C T I O N S - P R O T O T Y P E S _______________*/


#endif /* __MC9S08xx__ */


/******************************************************************************/
/*  TOSHIBA TX49 CODE                                                         */
/*                                                                            */
/******************************************************************************/
#ifdef __TX49__

/*______ G L O B A L - D E F I N E S _________________________________________*/

#define Wdtd_MskStartTimer  ((ulong)0x04)
#define Wdtd_RefeshValue    ((ubyte)0x4E)


/*______ G L O B A L - T Y P E S _____________________________________________*/


/*______ G L O B A L - D A T A _______________________________________________*/


/*______ G L O B A L - M A C R O S ___________________________________________*/

/*----------------------------------------------------------------------------*/
/* Name : WDTD_Init                                                           */
/* Role : interface compatibility                                             */
/* Interface : None                                                           */
/* Pre-condition : None                                                       */
/* Constraints : gate                                                         */
/* Behavior :                                                                 */
/*   DO                                                                       */
/*     [Gates the clock of watchdog timer]                                    */
/*     [Write default value and clock prescaler value into WDMOD register]    */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/
#define WDTD_Init() \
        TARG_WriteBit(CCRCRCR, SYS_BIT_WDTG, 1); \
        TARG_WriteLong(WDMOD, WDTD_WDMOD_DEFAULT_VALUE | WDTD_CLCK_PRESCALE)

/*----------------------------------------------------------------------------*/
/* Name : WDTD_Start                                                          */
/* Role : Configure and start the watchdog timer                              */
/* Interface : None                                                           */
/* Pre-condition : call once only in the life of product (in BLF)             */
/* Constraints : none                                                         */
/* Behavior :                                                                 */
/*   DO                                                                       */
/*     [enable watchdog timer ]                                               */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/
#define WDTD_Start() \
        TARG_SetBits(WDMOD, Wdtd_MskStartTimer)

/*----------------------------------------------------------------------------*/
/* Name : WDTD_Refresh                                                        */
/* Role : Refresh the timer to prevent overflow (RESET)                       */
/* Interface : void                                                           */
/* Pre-condition : void                                                       */
/* Constraints : None                                                         */
/* Behavior :                                                                 */
/*   DO                                                                       */
/*     [reset the counter]                                                    */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/
#define WDTD_Refresh()\
        TARG_WriteByte(WDCR, Wdtd_RefeshValue)


/*______ G L O B A L - F U N C T I O N S - P R O T O T Y P E S _______________*/


#endif /* __TX49__ */


/******************************************************************************/
/*  FREESCALE IMX53 CODE                                                      */
/******************************************************************************/
#if defined(__FSL_IMX53x__) || defined(__FSL_IMX6x__)

/*______ G L O B A L - D E F I N E S _________________________________________*/

#define WDOG_WCR_CONFIG  ((0x09 << 8) | WDOG_MSK_WCR_WDBG | WDOG_MSK_WCR_WDA | WDOG_MSK_WCR_SRS)


/*______ G L O B A L - T Y P E S _____________________________________________*/


/*______ G L O B A L - D A T A _______________________________________________*/


/*______ G L O B A L - M A C R O S ___________________________________________*/

/*----------------------------------------------------------------------------*/
/*@F_Name : WDTD_Init                                                         */
/*@F_Role : Configure the watchdog behaviour and timeout period (500ms).      */
/*@F_Interface :                                                              */
/*  @F_IN :  -                                                                */
/*  @F_OUT : -                                                                */
/*@F_Precondition : -                                                         */
/*@F_Constraints : Call once only in the life of product (in BLF).            */
/*@F_Behavior :                                                               */
/*  DO                                                                        */
/*    [ ]                                                                     */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#ifdef __GHOS__
extern void WDTD_Init(void);
#else
#define WDTD_Init()                                                 \
  TARG_WriteShort(WDOG1_WMCR, 0x0000);                              \
  TARG_WriteShort(WDOG1_WCR,  WDOG_WCR_CONFIG);                     \
  TARG_WriteShort(WDOG1_WICR, WDOG_MSK_WICR_WTIS);                  \
  TARG_WriteLong(SRC_SCR,    (TARG_ReadLong(SRC_SCR)     |          \
                              SRC_MSK_SRC_MASK_WDOG_RST1 |          \
                              SRC_MSK_SRC_MASK_WDOG_RST3  ) )
#endif /* __GHOS__ */


/*----------------------------------------------------------------------------*/
/*@F_Name : WDTD_Start                                                        */
/*@F_Role :  Start the watchdog timer.                                        */
/*@F_Interface :                                                              */
/*  @F_IN :  -                                                                */
/*  @F_OUT : -                                                                */
/*@F_Precondition : WDTD_Init() must have been called before.                 */
/*@F_Constraints : -                                                          */
/*@F_Behavior :                                                               */
/*  DO                                                                        */
/*    [ ]                                                                     */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#define WDTD_Start()                                                    \
  TARG_WriteShort(WDOG1_WCR, TARG_ReadShort(WDOG1_WCR) | WDOG_MSK_WCR_WDE)


/*----------------------------------------------------------------------------*/
/*@F_Name : WDTD_Refresh                                                      */
/*@F_Role : Refresh the timer to prevent overflow (RESET).                    */
/*@F_Interface :                                                              */
/*  @F_IN  : -                                                                */
/*  @F_OUT : -                                                                */
/*@F_Precondition : WDTD_Start() must have been called before.                */
/*@F_Constraints : This function must be called periodically.                 */
/*                 The between two call must be lower than 500ms.             */
/*@F_Behavior :                                                               */
/*  DO                                                                        */
/*    [ ]                                                                     */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#define WDTD_Refresh()                            \
  TARG_WriteShort(WDOG1_WSR, 0x5555);             \
  TARG_WriteShort(WDOG1_WSR, 0xAAAA)


/*______ G L O B A L - F U N C T I O N S - P R O T O T Y P E S _______________*/


#endif /* __FSL_IMX53x__ , __FSL_IMX6x__*/

/******************************************************************************/
/*  Renesas RL78 CODE                                                         */
/*                                                                            */
/******************************************************************************/
#ifdef __REL_RL78__

#if defined(__REL_RL78_D1x__) || \
	defined(__REL_RL78_F1x__)

#if defined(__REL_RL78_D1A__) || \
	defined(__REL_RL78_F12__)

/* _____ G L O B A L - D E F I N E S _________________________________________*/

/* _____ G L O B A L - T Y P E S _____________________________________________*/

/* _____ G L O B A L - D A T A _______________________________________________*/

/* _____ G L O B A L - M A C R O S ___________________________________________*/

/*----------------------------------------------------------------------------*/
/* Name : WDTD_Init                                                           */
/* Role : Configure the watchdog overflow mode and timer clock prescaler      */
/* Interface : TimePrescaler   IN  Value of the prescaler                     */
/*                                 [0 to 7]                                   */
/* Pre-condition : None                                                       */
/* Constraints : Must be called before WDTD_Start                             */
/* Behavior :                                                                 */
/*   DO                                                                       */
/*     [Configure the counter]                                                */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/
/* PROC WDTD_Init                                                             */
/* DATA                                                                       */
/* ATAD                                                                       */
/*                                                                            */
/* DO                                                                         */
/*   [Configure the counter] =                                                */
/*   DO                                                                       */
/*     [Set the time prescaler with the defined value, set WDCS2-0 bits       */
/*      in WDCS according to the defined value]                               */
/*     [Set the RESET mode, set WDTM3 bit in WDTM to 1]                       */
/*     [Set the WATCHDOG mode, set WDTM4 bit in WDTM to 1]                    */
/*   OD                                                                       */
/* OD                                                                         */
/*----------------------------------------------------------------------------*/
#define WDTD_Init()

/*----------------------------------------------------------------------------*/
/* Name : WDTD_Start                                                          */
/* Role : Start the watchdog timer                                            */
/* Interface : None                                                           */
/* Pre-condition : Must be called after WDTD_Init                             */
/* Constraints : None                                                         */
/* Behavior :                                                                 */
/*   DO                                                                       */
/*     [Start the counter]                                                    */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/
/* PROC WDTD_Start                                                            */
/* DATA                                                                       */
/* ATAD                                                                       */
/*                                                                            */
/* DO                                                                         */
/*   [Start the counter] =                                                    */
/*   DO                                                                       */
/*     [Set the Start bit, set the RUN bit in WDTM to 1]                      */
/*   OD                                                                       */
/* OD                                                                         */
/*----------------------------------------------------------------------------*/
#define WDTD_Start() \
        TARG_WriteByte(WDTE, 0xAC)

/*----------------------------------------------------------------------------*/
/* Name : WDTD_Refresh                                                        */
/* Role : Clear the timer to prevent overflow (RESET)                         */
/* Interface : None                                                           */
/* Pre-condition : None                                                       */
/* Constraints : None                                                         */
/* Behavior :                                                                 */
/*   DO                                                                       */
/*     [Clear the counter]                                                    */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/
/* PROC WDTD_Refresh                                                          */
/* DATA                                                                       */
/* ATAD                                                                       */
/*                                                                            */
/* DO                                                                         */
/*   [Clear the counter] =                                                    */
/*   DO                                                                       */
/*     [Restart the counter, set the RUN bit in WDTM to 1]                    */
/*   OD                                                                       */
/* OD                                                                         */
/*----------------------------------------------------------------------------*/
#define WDTD_Refresh() \
        TARG_WriteByte(WDTE, 0xAC)

/* _____ G L O B A L -  F U N C T I O N S - P R O T O T Y P E S ______________*/
#endif /*__REL_RL78_D1A__ || __REL_RL78_F12__*/
#endif /*__REL_RL78_D1x__ || __REL_RL78_F1x__*/

#endif /* __REL_RL78__ */

/******************************************************************************/
/*  Renesas RH850 CODE                                                        */
/*                                                                            */
/******************************************************************************/
#ifdef __RH850__

#if defined(__RH850_F1x__)

#if defined(__RH850_F1L__) || defined(__RH850_F1K__)

/* _____ G L O B A L - D E F I N E S _________________________________________*/

#ifdef WDTD_INTERNAL_OSCILLATOR_DIV_1
#define Wdtd_WCC_CONFIGURATION WDTA_CKS_LRING_1
/* WARNING:                                                                 */
/* The following values are available when (Low Speed IntOsc [240 kHz] / 1) */
/* is the Window Watchdog Timer A input clock (WDTACKI).                    */
#define WDTD_TIME_OUT_2_MS      ((ubyte)(0x00))
#define WDTD_TIME_OUT_4_MS      ((ubyte)(0x10))
#define WDTD_TIME_OUT_9_MS      ((ubyte)(0x20))
#define WDTD_TIME_OUT_17_MS     ((ubyte)(0x30))
#define WDTD_TIME_OUT_34_MS     ((ubyte)(0x40))
#define WDTD_TIME_OUT_68_MS     ((ubyte)(0x50))
#define WDTD_TIME_OUT_137_MS    ((ubyte)(0x60))
#define WDTD_TIME_OUT_273_MS    ((ubyte)(0x70))
#else
#ifdef WDTD_INTERNAL_OSCILLATOR_DIV_128
#define Wdtd_WCC_CONFIGURATION WDTA_CKS_LRING_128
/* WARNING:                                                                   */
/* The following values are available when (Low Speed IntOsc [240 kHz] / 128) */
/* is the Window Watchdog Timer A input clock (WDTACKI) - WDTA0 only.         */
#define WDTD_TIME_OUT_273_MS    ((ubyte)(0x00))
#define WDTD_TIME_OUT_546_MS    ((ubyte)(0x10))
#define WDTD_TIME_OUT_1092_MS   ((ubyte)(0x20))
#define WDTD_TIME_OUT_2184_MS   ((ubyte)(0x30))
#define WDTD_TIME_OUT_4369_MS   ((ubyte)(0x40))
#define WDTD_TIME_OUT_8738_MS   ((ubyte)(0x50))
#define WDTD_TIME_OUT_17476_MS  ((ubyte)(0x60))
#define WDTD_TIME_OUT_34952_MS  ((ubyte)(0x70))
#else
#error "You have to choose clock oscillator"
#endif /* WDTD_INTERNAL_OSCILLATOR_DIV_128 */
#endif /* WDTD_INTERNAL_OSCILLATOR_DIV_1 */


#if defined (WDTD_Use_WDTA1_ACT) || defined (WDTD_Use_TWO_WDTA_ACT)
/* WARNING:                                                                 */
/* The following values are available when (Low Speed IntOsc [240 kHz] )    */
/* is the Window Watchdog Timer A input clock (WDTACKI).                    */
#define WDTD_WDTA1_TIME_OUT_2_MS      ((ubyte)(0x00))
#define WDTD_WDTA1_TIME_OUT_4_MS      ((ubyte)(0x10))
#define WDTD_WDTA1_TIME_OUT_9_MS      ((ubyte)(0x20))
#define WDTD_WDTA1_TIME_OUT_17_MS     ((ubyte)(0x30))
#define WDTD_WDTA1_TIME_OUT_34_MS     ((ubyte)(0x40))
#define WDTD_WDTA1_TIME_OUT_68_MS     ((ubyte)(0x50))
#define WDTD_WDTA1_TIME_OUT_137_MS    ((ubyte)(0x60))
#define WDTD_WDTA1_TIME_OUT_273_MS    ((ubyte)(0x70))
#endif   /*WDTD_WDTA1_ACT */

/* Available settings for open window size - WDTAnMD.WDTAnWS[1:0] bits */
#ifdef WDTD_WINDOW_FUNCTION_ON
#define WDTD_WINDOW_SIZE_25   ((ubyte)0x00)
#define WDTD_WINDOW_SIZE_50   ((ubyte)0x01)
#define WDTD_WINDOW_SIZE_75   ((ubyte)0x02)
#define WDTD_WINDOW_SIZE_100  ((ubyte)0x03)
#endif /* WDTD_INTERNAL_OSCILLATOR_DIV_1 */

/* _____ G L O B A L - T Y P E S _____________________________________________*/

/* _____ G L O B A L - D A T A _______________________________________________*/

/* _____ G L O B A L - M A C R O S ___________________________________________*/

/*----------------------------------------------------------------------------*/
/* Name : WDTD_Init                                                           */
/* Role : Configure the watchdog overflow mode and timer clock prescaler      */
/* Interface : TimePrescaler   IN  Value of the prescaler                     */
/*                                 [0 to 7]                                   */
/* Pre-condition : None                                                       */
/* Constraints : Must be called before WDTD_Start                             */
/* Behavior :                                                                 */
/*   DO                                                                       */
/*     [Configure the counter]                                                */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/
/* PROC WDTD_Init                                                             */
/* DATA                                                                       */
/* ATAD                                                                       */
/*                                                                            */
/* DO                                                                         */
/*   [Configure the counter] =                                                */
/*   DO                                                                       */
/*     [Set the time prescaler with the defined value, set WDCS2-0 bits       */
/*      in WDCS according to the defined value]                               */
/*     [Set the RESET mode, set WDTM3 bit in WDTM to 1]                       */
/*     [Set the WATCHDOG mode, set WDTM4 bit in WDTM to 1]                    */
/*   OD                                                                       */
/* OD                                                                         */
/*----------------------------------------------------------------------------*/
/*Fix avoid watchdog_0  running on deepstop mode */
#ifdef WDTD_Use_WDTA0_ACT
#define WDTD_Init()\
       TARG_WriteByte(WDTA0MD , (WDTD_TIME_OUT_A0 | WDG_MSK_WDTAnERM \
                                           | WDG_MSK_WDTAnWS))
#endif										   
#ifdef WDTD_Use_WDTA1_ACT
#define WDTD_Init()\
      TARG_WriteByte(WDTA1MD , (WDTD_TIME_OUT_A1 | WDG_MSK_WDTAnERM \
                                        | WDG_MSK_WDTAnWS))
#endif

#ifdef WDTD_Use_TWO_WDTA_ACT
#define WDTD_Init()\
       {            \
       TARG_WriteByte(WDTA0MD , (WDTD_TIME_OUT_A0 | WDG_MSK_WDTAnERM \
                                           | WDG_MSK_WDTAnWS));      \
       TARG_WriteByte(WDTA1MD , (WDTD_TIME_OUT_A1 | WDG_MSK_WDTAnERM \
                                    | WDG_MSK_WDTAnWS));\
       TARG_WriteByte(WDTA1WDTE, 0xAC);\
       TARG_WriteByte(WDTA0WDTE, 0xAC);\
       }
#endif
/*----------------------------------------------------------------------------*/
/* Name : WDTD_Start                                                          */
/* Role : Start the watchdog timer                                            */
/* Interface : None                                                           */
/* Pre-condition : Must be called after WDTD_Init                             */
/* Constraints : None                                                         */
/* Behavior :                                                                 */
/*   DO                                                                       */
/*     [Start the counter]                                                    */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/
/* PROC WDTD_Start                                                            */
/* DATA                                                                       */
/* ATAD                                                                       */
/*                                                                            */
/* DO                                                                         */
/*   [Start the counter] =                                                    */
/*   DO                                                                       */
/*     [Set the Start bit, set the RUN bit in WDTM to 1]                      */
/*   OD                                                                       */
/* OD                                                                         */
/*----------------------------------------------------------------------------*/
/*Fix avoid watchdog_0  running on deepstop mode */
#ifdef WDTD_Use_WDTA0_ACT
#define WDTD_Start() \
        TARG_WriteByte(WDTA0WDTE, 0xAC)
#endif										   
#ifdef WDTD_Use_WDTA1_ACT
#define WDTD_Start() \
		TARG_WriteByte(WDTA1WDTE, 0xAC)
#endif

#ifdef WDTD_Use_TWO_WDTA_ACT
#define WDTD_Start()\
       {            \
	    TARG_WriteByte(WDTA0WDTE, 0xAC);\
        TARG_WriteByte(WDTA1WDTE, 0xAC);\
       }
#endif
/*----------------------------------------------------------------------------*/
/* Name : WDTD_Stop                                                           */
/* Role : Stop watchdog                                                       */
/* Interface : None                                                           */
/* Pre-condition : None                                                       */
/* Constraints : None                                                         */
/* Behavior :                                                                 */
/*----------------------------------------------------------------------------*/

#define WDTD_Stop() \


/*----------------------------------------------------------------------------*/
/* Name : WDTD_Refresh                                                        */
/* Role : Clear the timer to prevent overflow (RESET)                         */
/* Interface : None                                                           */
/* Pre-condition : None                                                       */
/* Constraints : None                                                         */
/* Behavior :                                                                 */
/*   DO                                                                       */
/*     [Clear the counter]                                                    */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/
/* PROC WDTD_Refresh                                                          */
/* DATA                                                                       */
/* ATAD                                                                       */
/*                                                                            */
/* DO                                                                         */
/*   [Clear the counter] =                                                    */
/*   DO                                                                       */
/*     [Restart the counter, set the RUN bit in WDTM to 1]                    */
/*   OD                                                                       */
/* OD                                                                         */
/*----------------------------------------------------------------------------*/
/*Fix avoid watchdog_0  running on deepstop mode */
#ifdef WDTD_Use_WDTA0_ACT
#define WDTD_Refresh() \
        TARG_WriteByte(WDTA0WDTE, 0xAC)
#endif
#ifdef WDTD_Use_WDTA1_ACT
#define WDTD_Refresh() \
        TARG_WriteByte(WDTA1WDTE, 0xAC)
#endif

#ifdef WDTD_Use_TWO_WDTA_ACT
#define WDTD_Refresh() \
        {\
          TARG_WriteByte(WDTA1WDTE, 0xAC);\
          TARG_WriteByte(WDTA0WDTE, 0xAC);\
        }
#endif

/* _____ G L O B A L -  F U N C T I O N S - P R O T O T Y P E S ______________*/
#endif /*__RH850_F1L__*/
#endif /*__RH850_F1x__*/

#endif /* __RH850__ */

#endif /* WDTD_H */

/* _____ E N D _____ (wdtd.h) ________________________________________________*/
