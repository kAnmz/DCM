/******************************************************************************/
/*@F_NAME:          cpus.h                                                    */
/*@F_PURPOSE:       Public interface for processor core set-up                */
/*@F_CREATED_BY:    Vincent RIOUAL                                            */
/*@F_CREATION_DATE: 07/07/2003                                                */
/*@F_MPROC_TYPE:    V850 Fx3/Dx3/Dx4, MC9S12xx, MC9S08xx, TX49, IMX534,       */
/*                  Renesas RL78 D1A, RL78 F12,IMX6x                          */
/************************************** (C) Copyright 2015 Magneti Marelli ****/

#ifndef CPUS_H
#define CPUS_H

/*______ I N C L U D E - F I L E S ___________________________________________*/

#include "syst.h"

/*
 * if cpus module is for RH850 mcu, it will include special header for RH850
 * shubin liang
 * */
#if defined(__RH850__)
#include "cpus_rh850.h"
#include "wdtd.h"
#endif

#if defined(__MC9S12xx__) || defined(__MC9S08xx__) || defined (__NEC_V850__) || defined(__FSL_IMX53x__) || defined(__REL_RL78__)|| defined(__FSL_IMX6x__)
#include "wdtd.h"
#endif /* __MC9S12xx__ || __MC9S08xx__ || __NEC_V850__ || __FSL_IMX53x__ || __REL_RL78__||  __FSL_IMX6x__ */

#if defined (__NEC_V850__)
/* enumeration of clock path */
#define Cpus_PLL         1
#define Cpus_SSCG        2
#define Cpus_OSC         3
#define Cpus_SSCG_FXMPLL 4
#endif /* __NEC_V850__ */

#if defined (__NEC_V850__)
#include "rgv850.h"
#include "cpus_config.h"
#include "wkss.h"
#endif /* __NEC_V850__ */

#if defined(__MC9S08xx__)
#include "cpus_config.h"
#endif /* __MC9S08xx__ */

#if defined(__MC9S12xx__)
#if defined(__MC9S12XHZ__)
#include "cpus_config.h"
#endif /* __MC9S12XHZ__ */
#endif /* __MC9S12xx__ */

#if defined(__TX49__)
#include "cpus_config.h"
#endif /* __TX49__ */

#if defined(__FSL_IMX53x__)|| defined(__FSL_IMX6x__)
#if !defined (__GHOS__)
#include "cpus_config.h"
#endif /* !defined (__GHOS__) */
#endif /* __FSL_IMX53x__,__FSL_IMX6x__) */

#if defined(C_COMP_GHS_TX49)    \
    || defined(C_COMP_GHS_V850) \
    || defined(C_COMP_GHS_ARM)
/* Suppress remark 1846: object or function defined in header file
   (which is what we want for an inline function).
   This warning must not be supressed globally by compilation option because we
   want to know if a variable or an array are defined in header. Indeed if an
   object is defined in a header, this object take RAM each time the header is
   included.
   This pragma take end whith pragma endnowarning. */
#pragma ghs nowarning 1846
#endif /* C_COMP_GHS_TX49 || C_COMP_GHS_V850 || C_COMP_GHS_ARM */

#if defined(__REL_RL78__)
#include "cpus_config.h"
#endif

/*______ G L O B A L - D E F I N E S _________________________________________*/

#ifdef __NEC_V850_Fx3__
#define Prescaler3CompareValue  (ubyte)(78)
#define Cpus_Reg_SFC0 (ubyte)(Cpus_Reg_SFC0_FPFD|Cpus_Reg_SFC0_FPFD_RANGE)
#define Cpus_Reg_SFC1 (ubyte)(Cpus_Reg_SFC17|Cpus_Reg_SFC1_FMRC|Cpus_Reg_SFC1_FMFC)
#endif /* __NEC_V850_Fx3__ */


#ifdef __NEC_V850_Dx3__
  #if (SYST_FX_CLOCK >= 64)
  #define Cpus_Reg_VSWC  0x14  /* SUWL = 1 , VSWL = 3 + 1 (SSCG and/or Clock precision) */
  #else
  #if (SYST_FX_CLOCK >= 48)
  #define Cpus_Reg_VSWC  0x13  /* SUWL = 1 , VSWL = 2 + 1 (SSCG and/or Clock precision) */
  #else
  #if (SYST_FX_CLOCK >= 32)
  #define Cpus_Reg_VSWC  0x12  /* SUWL = 1 , VSWL = 1 + 1 (SSCG and/or Clock precision) */
  #else
  #if (SYST_FX_CLOCK >= 24)
  #define Cpus_Reg_VSWC  0x11  /* SUWL = 1 , VSWL = 0 + 1 (SSCG and/or Clock precision) */
  #else
  #if (SYST_FX_CLOCK >= 16)
  #define Cpus_Reg_VSWC  0x01  /* SUWL = 0 , VSWL = 0 + 1 (SSCG and/or Clock precision) */
  #else
  #define Cpus_Reg_VSWC  0x00  /* SUWL = 0 , VSWL = 0 */
  #endif /* SYST_FX_CLOCK >= 16 */
  #endif /* SYST_FX_CLOCK >= 24 */
  #endif /* SYST_FX_CLOCK >= 32 */
  #endif /* SYST_FX_CLOCK >= 48 */
  #endif /* SYST_FX_CLOCK >= 64 */

  #if (Cpus_ClockGenerator == Cpus_SSCG)

    #if Cpus_PCLK0_1_SOURCE_CLK == Cpus_OSC
      #define Cpus_CKC_PCLK0_1_FLAGS (CLO_MSK_PLLEN | CLO_MSK_SCEN | CLO_MSK_DEN)
    #endif

    #if Cpus_PCLK0_1_SOURCE_CLK == Cpus_PLL
      #define Cpus_CKC_PCLK0_1_FLAGS (CLO_MSK_PLLEN | CLO_MSK_SCEN | CLO_MSK_DEN | CLO_MSK_PERIC)
    #endif

  #else

    #if Cpus_PCLK0_1_SOURCE_CLK == Cpus_OSC
      #define Cpus_CKC_PCLK0_1_FLAGS (CLO_MSK_PLLEN)
    #endif

    #if Cpus_PCLK0_1_SOURCE_CLK == Cpus_PLL
      #define Cpus_CKC_PCLK0_1_FLAGS (CLO_MSK_PLLEN | CLO_MSK_PERIC)
    #endif

  #endif /* Cpus_ClockGenerator == Cpus_SSCG */

  #if ((Cpus_PCLK0_1_SOURCE_CLK != Cpus_OSC) && (Cpus_PCLK0_1_SOURCE_CLK != Cpus_PLL))
    #error <PCLK0_1_SOURCE must be Cpus_OSC or Cpus_PLL !>
  #endif

  /* Select configuration for PLL multiplier */
  #if (SYST_FX_CLOCK >= 32)
  /* Configuration PLL to 8 x main oscillator) */
  #define Cpus_CLO_MSK (CLO_MSK_CKS1 | CLO_MSK_CKS0)
  #else
  /* Configuration PLL to 4 x main oscillator) */
  #define Cpus_CLO_MSK (CLO_MSK_CKS1               )
  #endif /* SYST_FX_CLOCK >= 32 */

  /* PCC Register Flags Settings */
  #if ( Cpus_ClockGenerator == Cpus_SSCG )
    #ifdef Cpus_DISCONNECT_SUB_OSC_RESISTOR
      #define Cpus_PCC_FLAGS (CLO_MSK_FRC | CLO_MSK_CKS0)
    #else
      #define Cpus_PCC_FLAGS (CLO_MSK_CKS0)
    #endif /* Cpus_DISCONNECT_SUB_OSC_RESISTOR */
  #else
    #ifdef Cpus_DISCONNECT_SUB_OSC_RESISTOR
      #define Cpus_PCC_FLAGS (CLO_MSK_FRC | Cpus_CLO_MSK)
    #else
      #define Cpus_PCC_FLAGS (Cpus_CLO_MSK)
    #endif /* Cpus_DISCONNECT_SUB_OSC_RESISTOR */
  #endif /* Cpus_ClockGenerator == Cpus_SSCG */

#endif /* __NEC_V850_Dx3__ */

#ifdef __REL_RL78__
#if defined(__REL_RL78_D1x__) || defined(__REL_RL78_F1x__)
#if defined(__REL_RL78_D1A__) || defined(__REL_RL78_F12__)

#ifdef __REL_RL78_D1A__
#define CPUS_MP_DIV_BY_1               0x00
#define CPUS_MP_DIV_BY_2               0x01
#define CPUS_MP_DIV_BY_4               0x02
#define CPUS_MP_DIV_BY_8               0x03
#define CPUS_MP_DIV_BY_16              0x04
#define CPUS_MP_DIV_BY_32              0x05
#endif /* __REL_RL78_D1A__ */

#define CPUS_OSC_STAB_FX_256           0x00
#define CPUS_OSC_STAB_FX_512           0x01
#define CPUS_OSC_STAB_FX_1024          0x02
#define CPUS_OSC_STAB_FX_2048          0x03
#define CPUS_OSC_STAB_FX_8192          0x04
#define CPUS_OSC_STAB_FX_32768         0x05
#define CPUS_OSC_STAB_FX_131072        0x06
#define CPUS_OSC_STAB_FX_262144        0x07

#define CPUS_OSC_STAB_FX_256_CHECK     0x80
#define CPUS_OSC_STAB_FX_512_CHECK     0xC0
#define CPUS_OSC_STAB_FX_1024_CHECK    0xE0
#define CPUS_OSC_STAB_FX_2048_CHECK    0xF0
#define CPUS_OSC_STAB_FX_8192_CHECK    0xF8
#define CPUS_OSC_STAB_FX_32768_CHECK   0xFC
#define CPUS_OSC_STAB_FX_131072_CHECK  0xFE
#define CPUS_OSC_STAB_FX_262144_CHECK  0xFF


#if (CPUS_OSCILATOR_STAB_TIME==CPUS_OSC_STAB_FX_256)
#define CPUS_OSCILATOR_STAB_TIME_CHECK  CPUS_OSC_STAB_FX_256_CHECK
#elif (CPUS_OSCILATOR_STAB_TIME==CPUS_OSC_STAB_FX_512)
#define CPUS_OSCILATOR_STAB_TIME_CHECK  CPUS_OSC_STAB_FX_512_CHECK
#elif (CPUS_OSCILATOR_STAB_TIME==CPUS_OSC_STAB_FX_1024)
#define CPUS_OSCILATOR_STAB_TIME_CHECK  CPUS_OSC_STAB_FX_1024_CHECK
#elif (CPUS_OSCILATOR_STAB_TIME==CPUS_OSC_STAB_FX_2048)
#define CPUS_OSCILATOR_STAB_TIME_CHECK  CPUS_OSC_STAB_FX_2048_CHECK
#elif (CPUS_OSCILATOR_STAB_TIME==CPUS_OSC_STAB_FX_8192)
#define CPUS_OSCILATOR_STAB_TIME_CHECK  CPUS_OSC_STAB_FX_8192_CHECK
#elif (CPUS_OSCILATOR_STAB_TIME==CPUS_OSC_STAB_FX_32768)
#define CPUS_OSCILATOR_STAB_TIME_CHECK  CPUS_OSC_STAB_FX_32768_CHECK
#elif (CPUS_OSCILATOR_STAB_TIME==CPUS_OSC_STAB_FX_131072)
#define CPUS_OSCILATOR_STAB_TIME_CHECK  CPUS_OSC_STAB_FX_131072_CHECK
#elif (CPUS_OSCILATOR_STAB_TIME==CPUS_OSC_STAB_FX_262144)
#define CPUS_OSCILATOR_STAB_TIME_CHECK  CPUS_OSC_STAB_FX_262144_CHECK
#endif

#endif /* __REL_RL78_D1A__ || __REL_RL78_F12__ */
#endif /* __REL_RL78_D1x__ || __REL_RL78_F1x__*/
#endif /*__REL_RL78__*/

/*______ G L O B A L - T Y P E S _____________________________________________*/

#ifdef __debug__
#ifdef __NEC_V850_Dx3__
/* Corresponding pin according to Fout configuration : */
/* |---------------------*/
/* | Micro | Port -> Pin */
/* |-------|-------------*/
/* | DG3   | P85  ->  65 */
/* |       | P50  ->  28 */
/* |-------|-------------*/
/* | DJ3   | P85  ->  98 */
/* |       | P50  ->  47 */
/* |-------|-------------*/
/* | DL3   | P85  -> 180 */
/* |       | P50  -> 132 */
/* |---------------------*/
typedef enum
{
  /* P85 corresponds to Port 8 bit 5 for V850 Dx3 versions */
  CPUS_FOUT_P85=0,
  /* P50 corresponds to Port 8 bit 5 for V850 Dx3 versions */
  CPUS_FOUT_P50
} CPUS_FoutPin_t;
#endif /* __NEC_V850_Dx3__ */
#endif /*__debug__*/


/*______ G L O B A L - D A T A _______________________________________________*/


/*______ G L O B A L - M A C R O S ___________________________________________*/

#ifdef __TX49__

/*----------------------------------------------------------------------------*/
/* Name : CPUS_SetCpu                                                         */
/* Role : none for TX49                                                       */
/* Interface : -                                                              */
/* Pre-condition : -                                                          */
/* Constraints : -                                                            */
/* Behavior :                                                                 */
/*  DO                                                                        */
/*       [Initialisation of the stack pointer]                                */
/*       [Initialisation of the global pointer]                               */
/*       [Point gp 32K past SDA start]                                        */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
__INLINE__ void CPUS_SetCpu(void)
{
  /*
  TX49 used in bi-processor system, we do not use internal watchgog
  watchgog base on inter micro communication superving
  each micro supervises other one
  WDTD_Init();
  WDTD_Start();
  */

#pragma asm

; # Initialisation of the stack pointer
   lui   $sp, %hi(__ghsend_stack)
   addiu $sp, $sp, %lo(__ghsend_stack)

; # Initialisation of the global pointer
   lui   $gp, %hi(__ghsbegin_sdabase)
   addiu $gp, $gp, %lo(__ghsbegin_sdabase)

; # Point gp 32K past SDA start
   addiu   $gp, $gp, 0x4000
   addiu   $gp, $gp, 0x4000

#pragma endasm

  CPUS_ConfigIomux();
}


/*----------------------------------------------------------------------------*/
/* Name : CPUS_StartPll                                                       */
/* Role : none for TX49                                                       */
/* Interface : -                                                              */
/* Pre-condition : -                                                          */
/* Constraints : -                                                            */
/* Behavior : -                                                               */
/*----------------------------------------------------------------------------*/
#define CPUS_StartPll()


/*----------------------------------------------------------------------------*/
/* Name : CPUS_StopPll                                                        */
/* Role : none for TX49                                                       */
/* Interface : -                                                              */
/* Pre-condition : -                                                          */
/* Constraints : -                                                            */
/* Behavior : -                                                               */
/*----------------------------------------------------------------------------*/
#define CPUS_StopPll()

#endif /* __TX49__ */

/*----------------------------------------------------------------------------*/


#ifdef __MC9S12xx__

/*----------------------------------------------------------------------------*/
/* Name : CPUS_StopPll                                                        */
/* Role : none for MC9S12                                                     */
/* Interface : -                                                              */
/* Pre-condition : -                                                          */
/* Constraints : -                                                            */
/* Behavior : -                                                               */
/*----------------------------------------------------------------------------*/
#define CPUS_StopPll()


/*----------------------------------------------------------------------------*/
/* Name : CPUS_StartPll                                                       */
/* Role : Startup the PLL                                                     */
/* Interface : -                                                              */
/* Pre-condition : -                                                          */
/* Constraints :                                                              */
/*               Must be a macro and not a function because stack pointer is  */
/*               not set when this service is used not.                       */
/*               For Cosmic __INLINE__ is same that macro definition.         */
/* Behavior :                                                                 */
/*  DO                                                                        */
/*    [Set PLL value]                                                         */
/*    [wait for external oscillator is available]                             */
/*    [wait for locked PLL]                                                   */
/*    [Set PLL behaviour]                                                     */
/*    [Set clock to be derived from PLL clock]                                */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
__INLINE__ void CPUS_StartPll(void)
{
/* MC9S12-H and MC9S12-HZ Variant */
#if defined(__MC9S12H__) || defined(__MC9S12HZ__)

  /* PLL clock 32 MHz / Bus clock 16 MHz */
  TARG_WriteByte(REFDV, 0x04);
  TARG_WriteByte(SYNR, 0x0F);

#endif /* defined(__MC9S12H__) || defined(__MC9S12HZ__) */

/* MC9S12-XHZ Variant */
#if defined(__MC9S12XHZ__)

  /* PLL clock = 2 * (OSCCLK / (Cpus_REFDV + 1)) * (Cpus_SYNR + 1) */
  /* Bus clock = PLL clock / 2 */
  TARG_WriteByte(REFDV, Cpus_REFDV);
  TARG_WriteByte(SYNR, Cpus_SYNR);

#endif /* __MC9S12XHZ__ */

  /* wait for external oscillator, if never OK , reset by watchdog */
  while ( TARG_ReadBit(CRGFLG, CRG_BIT_SCM) == TRUE );

  /* wait for locked PLL, if never OK , reset by watchdog */
  while ( TARG_ReadBit(CRGFLG, CRG_BIT_LOCK) == FALSE );

/* MC9S12-H and MC9S12-HZ Variant */
#if defined(__MC9S12H__) || defined(__MC9S12HZ__)

  /* PLL behaviour setup :  */
  /* CRG_BIT_CME   -> TRUE, Clock monitor is enabled. Slow or stopped clocks will */
  /*                        cause a clock monitor reset sequence                  */
  /* CRG_BIT_SCME  -> FALSE, Detection of crystal clock failure causes clock monitor reset */
  /* CRG_BIT_PLLON -> TRUE  */
  /* CRG_BIT_AUTO  -> TRUE  */
  /* CRG_BIT_ACQ   -> TRUE  */
  /* CRG_BIT_PRE   -> TRUE, RTI is running during pseudo-stop mode                */
  /* CRG_BIT_PCE   -> TRUE, COP (internal WDT) is running during pseudo-stop mode */
  TARG_WriteByte(PLLCTL, ( CRG_MSK_CME   |
                           CRG_MSK_PLLON |
                           CRG_MSK_AUTO  |
                           CRG_MSK_ACQ   |
                           CRG_MSK_PRE   |
                           CRG_MSK_PCE ) );

  /* set PLL source :        */
  /* CRG_BIT_PLLSEL -> TRUE  System clocks are derived from pllclk */
  /* CRG_BIT_PSTP   -> TRUE  */
  /* CRG_BIT_SYSWAI -> TRUE  */
  /* CRG_BIT_ROAWAI -> TRUE  */
  /* CRG_BIT_PLLWAI -> TRUE  */
  /* CRG_BIT_CWAI   -> TRUE  */
  /* CRG_BIT_RTIWAI -> TRUE  */
  /* CRG_BIT_COPWAI -> TRUE  */
  TARG_WriteByte(CLKSEL, ( CRG_MSK_PLLSEL |
                           CRG_MSK_PSTP   |
                           CRG_MSK_SYSWAI |
                           CRG_MSK_ROAWAI |
                           CRG_MSK_PLLWAI |
                           CRG_MSK_CWAI   |
                           CRG_MSK_RTIWAI |
                           CRG_MSK_COPWAI ) );

#endif /* defined(__MC9S12H__) || defined(__MC9S12HZ__) */


/* MC9S12-XHZ Variant */
#if defined(__MC9S12XHZ__)

  /* PLL behaviour setup :  */
  /* CRG_BIT_CME    -> TRUE, Clock monitor is enabled. Slow or stopped clocks will */
  /*                         cause a clock monitor reset sequence                  */
  /* CRG_BIT_PLLON  -> TRUE  */
  /* CRG_BIT_AUTO   -> TRUE  */
  /* CRG_BIT_ACQ    -> TRUE  */
  /* CRG_BIT_FSTWKP -> FALSE, Fast wake-up from full stop mode disabled */
  /* CRG_BIT_PRE    -> TRUE, RTI is running during pseudo-stop mode                */
  /* CRG_BIT_PCE    -> TRUE, COP (internal WDT) is running during pseudo-stop mode */
  /* CRG_BIT_SCME   -> FALSE, Detection of crystal clock failure causes clock monitor reset */
  TARG_WriteByte(PLLCTL, ( CRG_MSK_CME   |
                           CRG_MSK_PLLON |
                           CRG_MSK_AUTO  |
                           CRG_MSK_ACQ   |
                           CRG_MSK_PRE   |
                           CRG_MSK_PCE ) );

  /* set PLL source :        */
  /* CRG_BIT_PLLSEL -> TRUE  System clocks are derived from pllclk */
  /* CRG_BIT_PSTP   -> TRUE  */
  /* CRG_BIT_PLLWAI -> TRUE  */
  /* CRG_BIT_RTIWAI -> TRUE  */
  /* CRG_BIT_COPWAI -> TRUE  */
  TARG_WriteByte(CLKSEL, ( CRG_MSK_PLLSEL |
                           CRG_MSK_PSTP   |
                           CRG_MSK_PLLWAI |
                           CRG_MSK_RTIWAI |
                           CRG_MSK_COPWAI ) );

#endif /* __MC9S12XHZ__ */
}


/* MC9S12-XHZ Variant */
#if defined(__MC9S12XHZ__)
/*----------------------------------------------------------------------------*/
/* Name : Cpus_SetIntPriorityLevel                                            */
/* Role : Set inetrrupt priority level of a group of 8 inetrrupt              */
/* Interface : Int_Addr   IN  Base Index of 8 interrupt vector group          */
/*             Int_Level  IN  Requested priority level                        */
/* Pre-condition : -                                                          */
/* Constraints :                                                              */
/* Behaviour :                                                                */
/*  DO                                                                        */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#define Cpus_SetIntPriorityLevel(Int_Addr, Int_Level) \
{                                                     \
  TARG_WriteByte(INT_CFADDR, Int_Addr);               \
  TARG_WriteByte(INT_CFDATA0, Int_Level);             \
  TARG_WriteByte(INT_CFDATA1, Int_Level);             \
  TARG_WriteByte(INT_CFDATA2, Int_Level);             \
  TARG_WriteByte(INT_CFDATA3, Int_Level);             \
  TARG_WriteByte(INT_CFDATA4, Int_Level);             \
  TARG_WriteByte(INT_CFDATA5, Int_Level);             \
  TARG_WriteByte(INT_CFDATA6, Int_Level);             \
  TARG_WriteByte(INT_CFDATA7, Int_Level);             \
}
#endif /* __MC9S12XHZ__ */


/*----------------------------------------------------------------------------*/
/* Name : CPUS_SetCpu                                                         */
/* Role : Initialise CPU                                                      */
/* Interface : -                                                              */
/* Pre-condition : -                                                          */
/* Constraints :                                                              */
/*               Must be a macro and not a function because :                 */
/*                 - Internal watchdog starting MUST BE FIRST PROCESSOR       */
/*                   INSTRUCTION AFTER RESET                                  */
/*                 - stack pointer is not set when this service is used       */
/*               For Cosmic __INLINE__ is same that macro definition.         */
/* Behaviour :                                                                */
/*  DO                                                                        */
/*       [Map registers]                                                      */
/*       [Start internal watchdog]                                            */
/*       [Set CPU in normal single chip]                                      */
/*       [Port E assignement, no external E-clock]                            */
/*       [Start PLL]                                                          */
/*       [Map RAM and EEPROM memory]                                          */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
__INLINE__ void CPUS_SetCpu(void)
{
  /* Start internal watchdog */
  /* MUST BE FIRST PROCESSOR INSTRUCTION AFTER RESET */
  WDTD_Start();


/* MC9S12-H and MC9S12-HZ Variant */
#if defined(__MC9S12H__) || defined(__MC9S12HZ__)

  /* Map Register, can be write once only */
  TARG_WriteByteIndexed(INITRG, (-__BASE_ADR_CPU_REG), (__BASE_ADR_CPU_REG >> 8));

#endif /* defined(__MC9S12H__) || defined(__MC9S12HZ__) */

/* MC9S12-XHZ Variant */
#if defined(__MC9S12XHZ__)

  /* Registers fixed on 0x0000 */

#endif /* __MC9S12XHZ__ */


  /*  CPU mode : */
/* MC9S12-H and MC9S12-HZ Variant */
#if defined(__MC9S12H__) || defined(__MC9S12HZ__)

  TARG_WriteByte(MODE, 0x90); /* Normal Single Chip */
  TARG_WriteByte(PEAR, 0x10); /* Port E assignement: no external E-clock */

#endif /* defined(__MC9S12H__) || defined(__MC9S12HZ__) */

/* MC9S12-XHZ Variant */
#if defined(__MC9S12XHZ__)

  TARG_WriteByte(MODE, 0x80); /* Normal Single Chip */

#endif /* __MC9S12XHZ__ */


  /* Start PLL */
  CPUS_StartPll();


/* MC9S12-H and MC9S12-HZ Variant */
#if defined(__MC9S12H__) || defined(__MC9S12HZ__)

  /* Map RAM, start from 0x0000, can be write once only */
  TARG_WriteByte(INITRM, 0x00);
  /* Map EEPROM and activate it, can be write once only */
  TARG_WriteByte(INITEE, ( (__BASE_ADR_EEP >> 8) | 0x01 ) );

#endif /* defined(__MC9S12H__) || defined(__MC9S12HZ__) */

/* MC9S12-XHZ Variant */
#if defined(__MC9S12XHZ__)

  /* Set RAM Direct addressing area to 0x3E00 to 0x3EFF */
  TARG_WriteByte(DIRECT, 0x3E);

  /* Set 4K RAM page 0xFD visible at local memory address 0x1000 to 0x1FFF            */
  /* Pages 0xFE and 0xFF are allways visible at local memory address 0x2000 to 0x3FFF */
  TARG_WriteByte(RPAGE, 0xFD);

  /* Set 1K EEPROM page 0xFE visible at local memory address 0x0800 to 0x0BFF */
  /* Page 0xFF is allways visible at local memory address 0x0C00 to 0x0FFF    */
  TARG_WriteByte(EPAGE, 0xFE);

  /* Set first 64K of Flash accessible by global instruction for global constants */
  TARG_WriteByte(GPAGE, 0x78);

  /* At start, we activate page 0xFE (so that pages 0xFD(not banked), 0xFE(banked)
     and 0xFF(not banked) are accessible in NEAR memory model) */
  TARG_WriteByte(PPAGE, 0xFE);

#endif /* __MC9S12XHZ__ */


/* MC9S12-XHZ Variant */
#if defined(__MC9S12XHZ__)

  /* Set all IT level to higher priority (7) */
  Cpus_SetIntPriorityLevel(0x60, 0x07);
  Cpus_SetIntPriorityLevel(0x70, 0x07);
  Cpus_SetIntPriorityLevel(0x80, 0x07);
  Cpus_SetIntPriorityLevel(0x90, 0x07);
  Cpus_SetIntPriorityLevel(0xA0, 0x07);
  Cpus_SetIntPriorityLevel(0xB0, 0x07);
  Cpus_SetIntPriorityLevel(0xC0, 0x07);
  Cpus_SetIntPriorityLevel(0xD0, 0x07);
  Cpus_SetIntPriorityLevel(0xE0, 0x07);
  Cpus_SetIntPriorityLevel(0xF0, 0x07);

#endif /* __MC9S12XHZ__ */


  /* Set stack pointer */
#ifdef C_COMP_COSMIC_MC9S12
#pragma asm
  xref  __EndOfStack
  lds   #__EndOfStack    ; initialize stack pointer
#pragma endasm
#endif /* C_COMP_COSMIC_MC9S12 */
}
#endif /* __MC9S12xx__ */

/*----------------------------------------------------------------------------*/


#ifdef __MC9S08xx__

/*----------------------------------------------------------------------------*/
/* Name : CPUS_StopPll                                                        */
/* Role : none for MC9S08                                                     */
/* Interface : -                                                              */
/* Pre-condition : -                                                          */
/* Constraints : -                                                            */
/* Behavior : -                                                               */
/*----------------------------------------------------------------------------*/
#define CPUS_StopPll()


/*----------------------------------------------------------------------------*/
/* Name : CPUS_StartPll                                                       */
/* Role : Startup the PLL                                                     */
/* Interface : -                                                              */
/* Pre-condition : -                                                          */
/* Constraints :                                                              */
/*               Must be a macro and not a function because stack pointer is  */
/*               not set when this service is used not.                       */
/*               For Cosmic __INLINE__ is same that macro definition.         */
/* Behavior :                                                                 */
/*  DO                                                                        */
/*    [Set PLL value]                                                         */
/*    [wait for external oscillator is available]                             */
/*    [wait for locked PLL]                                                   */
/*    [Set PLL behaviour]                                                     */
/*    [Set clock to be derived from PLL clock]                                */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
__INLINE__ void CPUS_StartPll(void)
{
  /*********  ICGCx Initialisation Values  *********/

  /* ICGC1: HGO=0,RANGE=0,REFS=0,CLKS1=0,CLKS0=0,OSCSTEN=0,LOCD=0 */
  #define Cpus_ICGC1_DEFAULT_VALUE   0

  /* ICGC2: LOLRE=0,MFD2=0,MFD1=0,MFD0=0,LOCRE=0,RFD2=0,RFD1=0,RFD0=0 */
  #define Cpus_ICGC2_DEFAULT_VALUE   0



  /*********  FLL Configuration  *********/

  /* Values available to configure Cpus_EXTERNAL_FREQ */
  #define Cpus_RESONATOR_32kHz    32
  #define Cpus_XTAL_8MHz        8000

  /* Values available to configure Cpus_ICGOUT_FREQ   */
  #define Cpus_ICGOUT_16MHz    16000

  /* FLL configuration for an external frequency of 32kHz and an output frequency of 16MHz */
  /* fext x P x N / R = 32768 x 64 x 8 / 1 = 16777216 = fICGout                            */
  #if ((Cpus_EXTERNAL_FREQ == Cpus_RESONATOR_32kHz) && (Cpus_ICGOUT_FREQ == Cpus_ICGOUT_16MHz))
    /* P = 64 */
    #define Cpus_ICGC1_RANGE 0
    /* N = 8  */
    #define Cpus_ICGC2_MFD2  0
    #define Cpus_ICGC2_MFD1  ICGC2_MSK_MFD1
    #define Cpus_ICGC2_MFD0  0
    /* R = 1  */
    #define Cpus_ICGC2_RFD2  0
    #define Cpus_ICGC2_RFD1  0
    #define Cpus_ICGC2_RFD0  0
  #endif

  /* FLL configuration for an external frequency of 8MHz and an output frequency of 16MHz  */
  /* fext x P x N / R = 8000000 x 1 x 4 / 2 = 16000000 = fICGout                           */
  #if ((Cpus_EXTERNAL_FREQ == Cpus_XTAL_8MHz) && (Cpus_ICGOUT_FREQ == Cpus_ICGOUT_16MHz))
    /* P = 1  */
    #define Cpus_ICGC1_RANGE ICGC1_MSK_RANGE
    /* N = 4  */
    #define Cpus_ICGC2_MFD2  0
    #define Cpus_ICGC2_MFD1  0
    #define Cpus_ICGC2_MFD0  0
    /* R = 2  */
    #define Cpus_ICGC2_RFD2  0
    #define Cpus_ICGC2_RFD1  0
    #define Cpus_ICGC2_RFD0  ICGC2_MSK_RFD0
  #endif



  /*********  Loss of lock reset  *********/

  #ifdef Cpus_LOLR_DISABLE
    #define Cpus_ICGC2_LOLR  0
  #else
    #define Cpus_ICGC2_LOLR  ICGC2_MSK_LOLRE
  #endif


  /*********  Loss of Clock reset  *********/

  #ifdef Cpus_LOCR_DISABLE
    #define Cpus_ICGC2_LOCR  0
  #else
    #define Cpus_ICGC2_LOCR  ICGC2_MSK_LOCRE
  #endif


  /*********  System clock initialization  **********/

  /* ICGC1: HGO=0, RANGE=Config, REFS=1, CLKS1=1, CLKS0=1, OSCSTEN=1, LOCD=0 */
  TARG_WriteByte(ICGC1, ( Cpus_ICGC1_DEFAULT_VALUE |
                          Cpus_ICGC1_RANGE         |
                          ICGC1_MSK_REFS           |
                          ICGC1_MSK_CLKS1          |
                          ICGC1_MSK_CLKS0          |
                          ICGC1_MSK_OSCSTEN     ) );

  /* ICGC2: LOLRE=Config, MFD2=Config, MFD1=Config, MFD0=Config, LOCRE=0, RFD2=Config, RFD1=Config, RFD0=Config */
  TARG_WriteByte(ICGC2, ( Cpus_ICGC2_DEFAULT_VALUE |
                          Cpus_ICGC2_LOLR          |
                          Cpus_ICGC2_MFD2          |
                          Cpus_ICGC2_MFD1          |
                          Cpus_ICGC2_MFD0          |
                          Cpus_ICGC2_LOCR          |
                          Cpus_ICGC2_RFD2          |
                          Cpus_ICGC2_RFD1          |
                          Cpus_ICGC2_RFD0       ) );

#pragma asm
  clrx
  clrh
#pragma endasm

  /* wait for external oscillator, if never OK , reset by watchdog */
  while ( (TARG_ReadByte(ICGS1) & (ICGS1_MSK_CLKSTBITS)) == FALSE )
  {
    /* Let enough time for oscillator start */
    /* counter in h:x register              */
    /* Reset WD if less than 65535          */
    SYST_Wait(SYST_500nS);
    SYST_Wait(SYST_500nS);
    SYST_Wait(SYST_500nS);
    SYST_Wait(SYST_500nS);
    SYST_Wait(SYST_500nS);
    SYST_Wait(SYST_500nS);
    SYST_Wait(SYST_500nS);
    SYST_Wait(SYST_500nS);
    SYST_Wait(SYST_500nS);
    SYST_Wait(SYST_500nS);
#pragma asm
    cphx  #65535
    beq LOscStatus
    aix #1         ; increment counter
    lda #255
    sta 6144       ; reset watchdog
    LOscStatus:
#pragma endasm
  }

  /* wait for locked PLL, if never OK , reset by watchdog */
  while ( TARG_ReadBit(ICGS1, ICGS1_BIT_LOCK) == FALSE );
}


/*----------------------------------------------------------------------------*/
/* Name : CPUS_SetCpu                                                         */
/* Role : Initialise CPU                                                      */
/* Interface : -                                                              */
/* Pre-condition : -                                                          */
/* Constraints :                                                              */
/*               Must be a macro and not a function because :                 */
/*                 - Internal watchdog starting MUST BE FIRST PROCESSOR       */
/*                   INSTRUCTION AFTER RESET                                  */
/*                 - stack pointer is not set when this service is used       */
/*               For Cosmic __INLINE__ is same that macro definition.         */
/* Behaviour :                                                                */
/*  DO                                                                        */
/*       [Map registers]                                                      */
/*       [Start internal watchdog]                                            */
/*       [Set CPU in normal single chip]                                      */
/*       [Port E assignement, no external E-clock]                            */
/*       [Start PLL]                                                          */
/*       [Map RAM and EEPROM memory]                                          */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
__INLINE__ void CPUS_SetCpu(void)
{
  /*********  SPMSCx and SMCLK Initialisation Values  *********/

  /* Low Voltage Detection Disabled                                               */
  /* SPMSC1: LVDF=0, LVDACK=0, LVDIE=0, LVDRE=0, LVDSE=0, LVDE=0, empty=0, BGBE=0 */
  #define Cpus_SPMSC1_DEFAULT  0

  /* Low Voltage Warning Disabled                                                */
  /* SPMSC2: LVWF=0, LVWACK=0, LVDV=0, LVWV=0, PPDF=0, PPDACK=0, empty=0, PPDC=0 */
  #define Cpus_SPMSC2_DEFAULT  0

  /* SMCLK: MCLK output not enabled on PTC2 pin. */
  /* SMCLK: MPE=0, MCSEL=0                       */
  #define Cpus_SMCLK_DEFAULT  0



  /*********  Low Voltage Detection configuration  *********/

  /* Options available to configure LVD module */
  #define Cpus_LVD_OFF        1 /* LVD is disabled. */
  #define Cpus_LVD_PULLING    2 /* LVD is ON, check LVDF. WARNING: Flag acknowledge must be implemented. */
  #define Cpus_LVD_INTERRUPT  3 /* LVD is ON, IT is generated. WARNING: IT and Flag acknowledge must be implemented. */
  #define Cpus_LVD_RESET      4 /* LVD is ON, Reset occured. */

  /* Options available to configure the LVD trip point level */
  #define Cpus_LVD_DETECT_L_WARNING_L  1 /* Detection 2.6V, Warning 2.6V */
  #define Cpus_LVD_DETECT_L_WARNING_H  2 /* Detection 2.6V, Warning 4.3V */
  #define Cpus_LVD_DETECT_H_WARNING_H  3 /* Detection 4.3V, Warning 4.3V */

  /* LVD is disabled. */
  #if (Cpus_LVD_MODE == Cpus_LVD_OFF)
    #define Cpus_SPMSC1_LVDIE 0
    #define Cpus_SPMSC1_LVDRE 0
    #define Cpus_SPMSC1_LVDE  0
  #endif /* Cpus_LVD_MODE == Cpus_LVD_OFF */

  /* LVD is ON, check LVDF. */
  /* Flag management is not implemented. */
  #if (Cpus_LVD_MODE == Cpus_LVD_PULLING)
    #define Cpus_SPMSC1_LVDIE 0
    #define Cpus_SPMSC1_LVDRE 0
    #define Cpus_SPMSC1_LVDE  SPMSC1_MSK_LVDE
  #endif /* Cpus_LVD_MODE == Cpus_LVD_PULLING */

  /* LVD is ON, IT is generated. */
  /* Interrupt Management is not implemented. */
  #if (Cpus_LVD_MODE == Cpus_LVD_INTERRUPT)
    #define Cpus_SPMSC1_LVDIE SPMSC1_MSK_LVDIE
    #define Cpus_SPMSC1_LVDRE 0
    #define Cpus_SPMSC1_LVDE  SPMSC1_MSK_LVDE
  #endif /* Cpus_LVD_MODE == Cpus_LVD_PULLING */

  /* LVD is ON, Reset occured. */
  #if (Cpus_LVD_MODE == Cpus_LVD_RESET)
    #define Cpus_SPMSC1_LVDIE 0
    #define Cpus_SPMSC1_LVDRE SPMSC1_MSK_LVDRE
    #define Cpus_SPMSC1_LVDE  SPMSC1_MSK_LVDE
  #endif /* Cpus_LVD_MODE == Cpus_LVD_PULLING */

  /* Detection 2.6V, Warning 2.6V */
  #if (Cpus_LVD_LEVEL == Cpus_LVD_DETECT_L_WARNING_L)
    #define Cpus_SPMSC2_LVDV  0
    #define Cpus_SPMSC2_LVWV  0
  #endif /* Cpus_LVD_LEVEL == Cpus_LVD_DETECT_L_WARNING_L */

  /* Detection 2.6V, Warning 4.3V */
  #if (Cpus_LVD_LEVEL == Cpus_LVD_DETECT_L_WARNING_H)
    #define Cpus_SPMSC2_LVDV  0
    #define Cpus_SPMSC2_LVWV  SPMSC2_MSK_LVWV
  #endif /* Cpus_LVD_LEVEL == Cpus_LVD_DETECT_L_WARNING_H */

  /* Detection 4.3V, Warning 4.3V */
  #if (Cpus_LVD_LEVEL == Cpus_LVD_DETECT_H_WARNING_H)
    #define Cpus_SPMSC2_LVDV  SPMSC2_MSK_LVDV
    #define Cpus_SPMSC2_LVWV  SPMSC2_MSK_LVWV
  #endif /* Cpus_LVD_LEVEL == Cpus_LVD_DETECT_H_WARNING_H */

  WDTD_Init();

  /* Low Voltage Detection Disabled */
  /* SPMSC1: LVDF=0, LVDACK=0, LVDIE=Config, LVDRE=Config, LVDSE=0, LVDE=Config, empty=0, BGBE=0 */
  TARG_WriteByte(SPMSC1, ( Cpus_SPMSC1_DEFAULT |
                           Cpus_SPMSC1_LVDIE   |
                           Cpus_SPMSC1_LVDRE   |
                           Cpus_SPMSC1_LVDE ) );

  /* Low Voltage Warning Disabled, Stop3 mode enable,  */
  /* SPMSC2: LVWF=0, LVWACK=0, LVDV=Config, LVWV=Config, PPDF=0, PPDACK=0, empty=0, PPDC=0 */
  TARG_WriteByte(SPMSC2, ( Cpus_SPMSC2_DEFAULT |
                           Cpus_SPMSC2_LVDV    |
                           Cpus_SPMSC2_LVWV ) );

  /* SMCLK: MCLK output not enabled on PTC2 pin. */
  /* SMCLK: MPE=0,MCSEL=0 */
  TARG_WriteByte (SMCLK, Cpus_SMCLK_DEFAULT);

  /* SMCLK: MCLK/2 output enabled on PTC2 pin. */
  /* SMCLK: MPE=1,MCSEL=1 */
  /*
  TARG_WriteByte(SMCLK, ( Cpus_SMCLK_DEFAULT |
                          SPMSC1_MSK_MPE     |
                          SPMSC1_MSK_MCSEL0 ) );
  */

  /* Start PLL */
  CPUS_StartPll();

  /* Set stack pointer */
#ifdef C_COMP_COSMIC_MC9S08
#pragma asm
  xref  __EndOfStack
  ldhx   #__EndOfStack    ; load value of stack pointer into hx
  txs                     ; save and init stack pointer
#pragma endasm
#endif /* C_COMP_COSMIC_MC9S08 */
}
#endif /* __MC9S08xx__ */

/*----------------------------------------------------------------------------*/


#ifdef __NEC_V850__

#ifdef __NEC_V850_Dx3__

/*----------------------------------------------------------------------------*/
/* Name : CPUS_StartPll                                                       */
/* Role : Startup the PLL                                                     */
/* Interface : -                                                              */
/* Pre-condition : -                                                          */
/* Constraints : -                                                            */
/*----------------------------------------------------------------------------*/
#define CPUS_StartPll() CPUS_StartClockTree(Cpus_STABILIZATION_WITH_4MHZ)


/*----------------------------------------------------------------------------*/
/* Name : CPUS_StartClockTree                                                 */
/* Role : Startup the Clock Tree                                              */
/* Interface: ushort  Cpus_PllStabilizationTime : Time (number of loops) used */
/*                    to guaranty stabilization                               */
/* Pre-condition : -                                                          */
/* Constraints :                                                              */
/* Behavior :                                                                 */
/*  DO                                                                        */
/*    [Wait for stabilization of main clock]                                  */
/*    [Wait for PLL output stabilization]                                     */
/*    [if used, Wait for SSCG output stabilization]                           */
/*    [Select PLL (8) or SSCG (if used) output as CPU System clock VBCLK]     */
/*    [Select PLL (x4) output for peripheral clocks PCLK0, PCLK1]             */
/*    [Select clock source: SPCLK0=PLL/2, SPCLK1=PLL/4, SPCLK2=Main Osc]      */
/*    [Select IIC clock source: PLL output]                                   */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
__INLINE__ void CPUS_StartClockTree(ushort Cpus_PllStabilizationTime)
{
  /* Step  1 : Stabilization of main clock */
  /*           Current clock : Int OSC , 200 KHz */
  TARG_ClearBits(PSM, CLO_MSK_OSCDIS);  /* Start Main Osc. */
  /* Ensure that the main oscillator is stabilized*/
  while(TARG_ReadBit(CGSTAT, CLO_BIT_OSCSTAT) != 1);

  /* Step  3 : Enable PLL */
  do
  {
    TARG_WriteByte(PHS, 0);
    /* Write access to security register first */
    TARG_WriteByte(PHCMD, CLO_MSK_PLLEN);
    /* enable the PLL */
    TARG_WriteByte(CKC, CLO_MSK_PLLEN);
  } while (TARG_ReadByte(PHS) != 0);

  /* Step  4 : Wait for PLL stabilization (delay 1.2 ms min ) */
  SYST_WaitLoop(Cpus_PllStabilizationTime);

  #if (Cpus_ClockGenerator == Cpus_SSCG)
  /* Step  4.1 : Program SSCG registers before enable SSCG */
  /* Select multiplication and division factors for SSCG */
  TARG_WriteByte(SCFC0, Cpus_Reg_SCFC0);
  TARG_WriteByte(SCFC1, Cpus_Reg_SCFC1);
  /* Select prescaler value for core frequency used (via SSCG) */
  TARG_WriteByte(SCPS, Cpus_Reg_SCPS);
  /* Select frequency modulation parameters for SSCG */
  TARG_WriteByte(SCFMC, Cpus_Reg_SCFMC);

  /* Step  4.2.1 : Enable dithering mode of SSCG */
  do
  {
    TARG_WriteByte(PHS, 0);
    /* Write access to security register first */
    TARG_WriteByte(PHCMD, CLO_MSK_PLLEN | CLO_MSK_DEN);
    /* Enable the dithering mode of SSCG */
    TARG_WriteByte(CKC, CLO_MSK_PLLEN | CLO_MSK_DEN);

  } while (TARG_ReadByte(PHS) != 0);

  /* Step  4.2.2 : Enable SSCG */
  do
  {
    TARG_WriteByte(PHS, 0);
    /* Write access to security register first */
    TARG_WriteByte(PHCMD, CLO_MSK_PLLEN | CLO_MSK_SCEN | CLO_MSK_DEN);
    /* Enable the SSCG */
    TARG_WriteByte(CKC, CLO_MSK_PLLEN | CLO_MSK_SCEN | CLO_MSK_DEN);
  } while (TARG_ReadByte(PHS) != 0);

  /* Step  4.3 : Wait for SSCG stabilization (delay 1.2 ms min ) */
  SYST_WaitLoop(Cpus_PllStabilizationTime);
  #endif /* Cpus_ClockGenerator == Cpus_SSCG */

  /* Step  4.4 : Setup peripheral clock */
  do
  {
    TARG_WriteByte(PHS, 0);
    /* Write access to security register first */
    TARG_WriteByte(PHCMD, Cpus_CKC_PCLK0_1_FLAGS);

    /* Select PLL Clock as peripheral clock source */
    TARG_WriteByte(CKC, Cpus_CKC_PCLK0_1_FLAGS);
  } while (TARG_ReadByte(PHS) != 0);

  /* Step  5 : Route PLL or SSCG to CPU clock */
  do
  {
    TARG_WriteByte(PHS, 0);
    /* Write access to security register first */
    TARG_WriteByte(PHCMD, Cpus_PCC_FLAGS);
    /* DG3 - SSCLK = 48 Mhz <-> PCC.CKSx=01 - F_CPU = 16Mhz     OR */
    /* DG3 - PLLCLK/2 = 16 Mhz <-> PCC.CKSx=10 - F_CPU = 16Mhz     */
    TARG_WriteByte(PCC, Cpus_PCC_FLAGS);
  } while (TARG_ReadByte(PHS) != 0);

  /* Step  6 : Setup the clock sources for the peripherals  */
  #ifdef Cpus_SSCG_for_SCC
  do
  {
    TARG_WriteByte(PHS, 0);
    /* Write access to security register first */
    TARG_WriteByte(PHCMD, CLO_MSK_SPSEL1 | CLO_MSK_SPSEL0);
    /* SPCLK0 = SSCGps ; SPCLK1 = SSCGps/2 ; SPCLK2 = SSCGps/4; SPCLK3=(SSCGps/4)/(2^1)*/
    /* SPCLK4=(SSCGps/4)/(2^2) ... SPCLK15=(SSCGps/4)/(2^13)                           */
    /* SSCGps = SSCG / SPSPS (post scaler) */
    TARG_WriteByte(SCC, CLO_MSK_SPSEL1 | CLO_MSK_SPSEL0);
  } while (TARG_ReadByte(PHS) != 0);
  #else
  do
  {
    TARG_WriteByte(PHS, 0);
    /* Write access to security register first */
    TARG_WriteByte(PHCMD, CLO_MSK_SPSEL0);
    /* SPCLK0 = PLL/2 ; SPCLK1 = PLL/4 ; SPCLK2 = MainOsc; SPCLK3=MainOsc/(2^1)*/
    /* SPCLK4=MainOsc/(2^2) ... SPCLK15=MainOsc/(2^13)                         */
    TARG_WriteByte(SCC, CLO_MSK_SPSEL0);
  } while (TARG_ReadByte(PHS) != 0);
  #endif /* Cpus_SSCG_for_SCC */

  do
  {
    TARG_WriteByte(PHS, 0);
    /* Write access to security register first */
    TARG_WriteByte(PHCMD, CLO_MSK_IICSEL1);
    /* IIC CLK = 32Mhz (DJ3/DL3) or 16MHz (DG3) */
    TARG_WriteByte(ICC, CLO_MSK_IICSEL1);
  } while (TARG_ReadByte(PHS) != 0);
}


/*----------------------------------------------------------------------------*/
/* Name : CPUS_StopPll                                                        */
/* Role : Stop Pll                                                            */
/* Interface : -                                                              */
/* Pre-condition : -                                                          */
/* Constraints : - WATCH, Sub-WATCH, STOP mode must be entered after or       */
/*                 bit SDC.SDCR must be set to 1                              */
/* Behavior :                                                                 */
/*  DO                                                                        */
/*    [Nothing to do: PLL is automatically stopped when entering WATCH, ]     */
/*    [Sub-WATCH or STOP mode, or if bit SDC.SDCR is set to 1]                */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#define CPUS_StopPll()


/*----------------------------------------------------------------------------*/
/* Name : CPUS_StopRingOsc240KHz                                              */
/* Role : Stop 240 KHz internal ring oscillator                               */
/* Interface : -                                                              */
/* Pre-condition : -                                                          */
/* Constraints : Clock must not be used by any module                         */
/*  DO                                                                        */
/*      [Nothing to do: No way to stop by software 240 kHz]                   */
/*      [WCC.ROSTP bit specify if ring oscillator stops if WATCH, Sub-WATCH, ]*/
/*      [or STOP mode entered. (See WCC config set in wdtd.h)]                */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#define CPUS_StopRingOsc240KHz()

#endif /* __NEC_V850_Dx3__ */

#ifdef __REL_V850_Dx4__

#if defined(__REL_V850_Dx4H__) || defined(__REL_V850_DP4H__) || defined(__REL_V850_DK4H__)
/*----------------------------------------------------------------------------*/
/* Name : CPUS_SetHBUS                                                        */
/* Role : Set CPU HBUS bridge                                                 */
/* Interface : -                                                              */
/* Pre-condition : -                                                          */
/* Constraints :                                                              */
/*----------------------------------------------------------------------------*/
__INLINE__ void CPUS_SetHBUS()
{
  /* Dx4-H HBus-Bridge setup
  + HBus master access: allowed to CPU-Subsystem
  + no wait limit
  */
  TARG_WriteShort(ETACFG,0x100);
  TARG_WriteShort(ETAWRL,0x0);/* disable wait limit for HBus access through HBus-Bridge */

#if defined(__REL_V850_Dx4H__) || defined(__REL_V850_DP4H__)
  /* clear error registers */
  TARG_WriteLong(ETAEREA,0);
  TARG_WriteLong(ETAWLEA,0);
#endif

  TARG_WriteShort(ETARCFG0,HBUS_AREA0_MODE);
  TARG_WriteLong(ETARADRS0,HBUS_AREA0_BASEADDR);
  TARG_WriteLong(ETARMASK0,HBUS_AREA0_MASK);

  TARG_WriteShort(ETARCFG1,HBUS_AREA1_MODE);
  TARG_WriteLong(ETARADRS1,HBUS_AREA1_BASEADDR);
  TARG_WriteLong(ETARMASK1,HBUS_AREA1_MASK);

  TARG_WriteShort(ETARCFG2,HBUS_AREA2_MODE);
  TARG_WriteLong(ETARADRS2,HBUS_AREA2_BASEADDR);
  TARG_WriteLong(ETARMASK2,HBUS_AREA2_MASK);

  TARG_WriteShort(ETARCFG3,HBUS_AREA3_MODE);
  TARG_WriteLong(ETARADRS3,HBUS_AREA3_BASEADDR);
  TARG_WriteLong(ETARMASK3,HBUS_AREA3_MASK);

  TARG_WriteShort(ATEAPMI,0x2); /* allow access of HBus masters (e.g. DRW engine) to CPU Subsystem*/
}
#endif /* defined(__REL_V850_Dx4H__) || defined(__REL_V850_DP4H__) || defined(__REL_V850_DK4H__) */


/*----------------------------------------------------------------------------*/
/* Name : CPUS_StartPll                                                       */
/* Role : Startup the PLL                                                     */
/* Interface : -                                                              */
/* Pre-condition : -                                                          */
/* Constraints : -                                                            */
/*----------------------------------------------------------------------------*/
#define CPUS_StartPll() CPUS_StartClockTreeFromSleep()

/*----------------------------------------------------------------------------*/
/* Name : Cpus_SetClockSourceID                                               */
/* Role : Configure the clock source ID for a given clock domain              */
/* Interface : -                                                              */
/* Pre-condition : -                                                          */
/* Constraints :                                                              */
/* Behavior :                                                                 */
/*  DO                                                                        */
/*    [Write register CKSC_mn with 1-bit shift for STPMK_mn]                  */
/*    [Check CKSCLK_mn activity by reading register CSCSTAT_mn]               */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#define Cpus_SetClockSourceID(ProtReg, ClockDomain, Value)        \
  TARG_ProtWriteLong(ProtReg, CKSC_ ## ClockDomain, (Value<<1));  \
  while ( TARG_ReadLong(CSCSTAT_ ## ClockDomain) !=               \
        ((Value<<1) | CLO_MSK_CLKACT_mn)          )               \
  {                                                               \
    asm("nop");                                                   \
  }

/*----------------------------------------------------------------------------*/
/* Name : Cpus_SetClockSelector                                               */
/* Role : Configure the clock source ID and stop mask bit for a clock domain  */
/* Interface : -                                                              */
/* Pre-condition : -                                                          */
/* Constraints :                                                              */
/* Behavior :                                                                 */
/*  DO                                                                        */
/*    [Write register CKSC_mn with 1-bit STPMK_mn]                            */
/*    [Check CKSCLK_mn activity by reading register CSCSTAT_mn]               */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#define Cpus_SetClockSelector(ProtReg, ClockDomain, Value)       \
    TARG_ProtWriteLong(ProtReg, CKSC_ ## ClockDomain, (Value));  \
    while (TARG_ReadLong(CSCSTAT_ ## ClockDomain)                \
           != ((Value) | CLO_MSK_CLKACT_mn)) {                   \
        asm("nop");                                              \
    }

/*----------------------------------------------------------------------------*/
/* Name : CPUS_StartClockTree                                                 */
/* Role : Startup the Clock Tree                                              */
/* Interface : -                                                              */
/* Pre-condition : -                                                          */
/* Constraints :                                                              */
/* Behavior :                                                                 */
/*  DO                                                                        */
/*    [...to be edited...]                                                    */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
__INLINE__ void CPUS_StartClockTree()
{
  ulong _RegValue;

  /* Wait for High Speed IntOsc to be stable */
  while (!TARG_ReadBitInLong(ROSCS,CLO_BIT_nCLKSTAB))
  {
    asm("nop");
  }

 /* Main oscillator not stop after wakeup to prevent RTC precision loss */
 #if defined(SYST_DX4_DEEPSTOP_USED)
  if ((TARG_ReadLong(MOSCS) != (CLO_MSK_nCLKEN | CLO_MSK_nCLKACT | CLO_MSK_nCLKSTAB))
  || (TARG_ReadLong(MOSCST) != (CLO_MSK_MOST & CLO_STAB_MOSC_4MS))
  || (TARG_ReadLong(MOSCC)  != (CLO_MSK_MOSCCAMPSEL & CLO_AMPSEL_REDUCED)))
#endif /* defined(SYST_DX4_DEEPSTOP_USED) */
  {
  /* Make sure that the MainOsc is stopped */
  if (TARG_ReadBitInLong(MOSCS,CLO_BIT_nCLKEN))
  {
      /* Wait for MainOsc enable status bit */
      do {
        _RegValue = TARG_ReadLong(MOSCE) | CLO_MSK_nDISTRG;
        TARG_ProtWriteLong(PROTCMD2, MOSCE, _RegValue);
      } while (TARG_ReadBitInLong(MOSCS, CLO_BIT_nCLKEN));
  }

  /* Set MainOsc stabilization time */
  if (!TARG_ReadBitInLong(MOSCC,CLO_BIT_MOSCCSHTSTBY))
  {
    TARG_WriteLong(MOSCST,(CLO_MSK_MOST & CLO_STAB_MOSC_4MS));
  }
  else
  {
    TARG_WriteLong(MOSCST,(CLO_MSK_MOST & CLO_STAB_MOSC_2MS));
  }

  /* Set amplification gain depending on MainOsc frequency */
#ifdef CLO_MOSC_AMPSEL
  TARG_WriteLong(MOSCC,(CLO_MSK_MOSCCAMPSEL & CLO_MOSC_AMPSEL));
#else
  TARG_WriteLong(MOSCC,(CLO_MSK_MOSCCAMPSEL & CLO_AMPSEL_REDUCED));
#endif

  /* Enable MainOsc */
  /* Unmask stop request - MainOsc is stopped in STOP mode */
  /* and is re-started upon wake-up from stand-by mode.    */
  _RegValue = TARG_ReadLong(MOSCE) | CLO_MSK_nENTRG;
  _RegValue &= ~CLO_MSK_nSTPMK;
  TARG_ProtWriteLong(PROTCMD2, MOSCE, _RegValue);

#ifdef CPUS_MASK_MOSC_SLEEP_MODE
  /* Mask stop request - MainOsc is NOT stopped in STOP mode */
  do {
    _RegValue = TARG_ReadLong(MOSCE) | CLO_MSK_nSTPMK;
    TARG_ProtWriteLong(PROTCMD2, MOSCE, _RegValue);
  } while(TARG_ReadLong(PROTS2));
#endif /* CPUS_MASK_MOSC_SLEEP_MODE */

  /* Wait for MainOsc enable, stabilization and active status bit */
  while (TARG_ReadLong(MOSCS) != (CLO_MSK_nCLKEN | CLO_MSK_nCLKACT | CLO_MSK_nCLKSTAB))
  {
    asm("nop");
  }
}

  /* Sub Oscillator (32 kHz) configuration                         */
  /* WARNING:                                                      */
  /* The define below must be declared in cpus_conifg.h if SubOsc  */
  /* is not mounted on the board.                                  */

  #ifndef CPUS_SOBOSC_NOT_USED
  /* Set SubOsc stabilization time */
  TARG_WriteLong(SOSCST,(CLO_MSK_SOST & CLO_STAB_SOSC_1S));

  /* Enable SubOsc */
  _RegValue = TARG_ReadLong(SOSCE) | CLO_MSK_nENTRG;

  /* mask stop request - SubOsc is NOT stopped in STOP mode */
  _RegValue |= CLO_MSK_nSTPMK;
  TARG_ProtWriteLong(PROTCMD2, SOSCE, _RegValue);

  /* Wait for SubOsc enable status bit */
  while (!TARG_ReadBitInLong(SOSCS,CLO_BIT_nCLKEN))
  {
    asm("nop");
  }

  /* Wait for SubOsc stabilization status bit */
  while (!TARG_ReadBitInLong(SOSCS,CLO_BIT_nCLKSTAB))
  {
    asm("nop");
  }
  #endif /* CPUS_SOBOSC_NOT_USED */

#ifndef CPUS_MASK_HRNG_SLEEP_MODE
  /*High speed IntOsc configuration*/
  /* Unmask stop request - High Speed IntOsc is stopped in STOP mode */
  /* and is re-started upon wake-up from stand-by mode.              */
  _RegValue = TARG_ReadLong(ROSCE) & ~CLO_MSK_nSTPMK;
  TARG_ProtWriteLong(PROTCMD2, ROSCE, _RegValue);
#endif

  /* PLL0 configuration */

  /* Make sure that the PLL0 is stopped */
  if (TARG_ReadBitInLong(PLLS0,CLO_BIT_nCLKEN))
  {
    /* Wait for PLL0 enable status bit */
    do {
      _RegValue = TARG_ReadLong(PLLE0) | CLO_MSK_nDISTRG;
      TARG_ProtWriteLong(PROTCMD2, PLLE0, _RegValue);
    } while (TARG_ReadBitInLong(PLLS0,CLO_BIT_nCLKEN));
  }

#if defined(CLO_PLL0_SSCG)
  /* Set SSCG mode for PLL0                                   */
  /* Set Mr, Pr and Nr divider values,                        */
  /* mode, frequency and modulation dithering and VCO input freq*/
  TARG_WriteLong(PLLC0, CLO_PLL0_MSK_MR +
                        CLO_PLL0_MSK_NR + CLO_PLL0_MSK_PR +
                        CLO_PLL0_MSK_PC + CLO_PLL0_MSK_ADJ + CLO_PLL0_MSK_MDL +
                        CLO_PLL0_MSK_S);
  /* Set PLL0 stabilization time */
  TARG_WriteLong(PLLST0,(CLO_MSK_PLLSTk & CLO_STAB_PLLk_2MS));
#else /* PLL MODE */
  /* Set PLL mode for PLL0 (SSCG parameters are cleared)      */
  /* Set Mr, Pr and Nr divider values                         */
  TARG_WriteLong(PLLC0, CLO_MSK_PLLCkMS + CLO_PLL0_MSK_MR +
                        CLO_PLL0_MSK_NR + CLO_PLL0_MSK_PR);
  /* Set PLL0 stabilization time */
  TARG_WriteLong(PLLST0,(CLO_MSK_PLLSTk & CLO_STAB_PLLk_1MS));
#endif

  /* Unmask stop request - PLL0 is stopped in Isolated-Area-0 STOP mode */
  /* and is re-started upon wake-up from stand-by mode.                 */

  /* PLL1 configuration */

  /* Make sure that the PLL1 is stopped */
  if (TARG_ReadBitInLong(PLLS1,CLO_BIT_nCLKEN))
  {
    /* Wait for PLL1 enable status bit */
    do {
      _RegValue = TARG_ReadLong(PLLE1) | CLO_MSK_nDISTRG;
      TARG_ProtWriteLong(PROTCMD2, PLLE1, _RegValue);
    } while (TARG_ReadBitInLong(PLLS1,CLO_BIT_nCLKEN));
  }

  /* Set PLL mode for PLL1 (SSCG parameters are cleared)      */
  /* Set Mr, Pr and Nr divider values                         */
  TARG_WriteLong(PLLC1, CLO_MSK_PLLCkMS + CLO_PLL1_MSK_MR +
                        CLO_PLL1_MSK_NR + CLO_PLL1_MSK_PR);

  /* Set PLL1 stabilization time */
  TARG_WriteLong(PLLST1,(CLO_MSK_PLLSTk & CLO_STAB_PLLk_2MS));

  /* Unmask stop request - PLL1 is stopped in Isolated-Area-0 STOP mode */
  /* and is re-started upon wake-up from stand-by mode.                 */

  #ifndef __REL_V850_DK4H__
  /* PLL2 configuration */

  /* Make sure that the PLL2 is stopped */
  if (TARG_ReadBitInLong(PLLS2,CLO_BIT_nCLKEN))
  {
    /* Wait for PLL2 enable status bit */
    do {
      _RegValue = TARG_ReadLong(PLLE2) | CLO_MSK_nDISTRG;
      TARG_ProtWriteLong(PROTCMD2, PLLE2, _RegValue);
    } while (TARG_ReadBitInLong(PLLS2,CLO_BIT_nCLKEN));
  }

#if defined(CLO_PLL2_SSCG)
  /* Set SSCG mode for PLL2                                   */
  /* Set Mr, Pr and Nr divider values,                        */
  /* mode, frequency and modulation dithering and VCO input freq*/
  TARG_WriteLong(PLLC2, CLO_PLL2_MSK_MR +
                        CLO_PLL2_MSK_NR + CLO_PLL2_MSK_PR +
                        CLO_PLL2_MSK_PC + CLO_PLL2_MSK_ADJ + CLO_PLL2_MSK_MDL +
                        CLO_PLL2_MSK_S);
  /* Set PLL2 stabilization time */
  TARG_WriteLong(PLLST2,(CLO_MSK_PLLSTk & CLO_STAB_PLLk_2MS));
#else /* PLL MODE */
  /* Set PLL mode for PLL2 (SSCG parameters are cleared)      */
  /* Set Mr, Pr and Nr divider values                         */
  TARG_WriteLong(PLLC2, CLO_MSK_PLLCkMS + CLO_PLL2_MSK_MR +
                        CLO_PLL2_MSK_NR + CLO_PLL2_MSK_PR);
  /* Set PLL2 stabilization time */
  TARG_WriteLong(PLLST2,(CLO_MSK_PLLSTk & CLO_STAB_PLLk_1MS));
#endif

  /* Unmask stop request - PLL2 is stopped in Isolated-Area-0 STOP mode */
  /* and is re-started upon wake-up from stand-by mode.                 */
  #endif /* !__REL_V850_DK4H__ */

  /* Enable PLL0 */
  _RegValue = TARG_ReadLong(PLLE0) | CLO_MSK_nENTRG;
  _RegValue &= ~CLO_MSK_nSTPMK;
  TARG_ProtWriteLong(PROTCMD2, PLLE0, _RegValue);

  /* Wait for PLL0 enable status bit */
  while (!TARG_ReadBitInLong(PLLS0,CLO_BIT_nCLKEN))
  {
    asm("nop");
  }

  /* Wait for PLL0 stabilization status bit */
  while (!TARG_ReadBitInLong(PLLS0,CLO_BIT_nCLKSTAB))
  {
    asm("nop");
  }

  /* Enable PLL1 */
  _RegValue = TARG_ReadLong(PLLE1) | CLO_MSK_nENTRG;
  _RegValue &= ~CLO_MSK_nSTPMK;
  TARG_ProtWriteLong(PROTCMD2, PLLE1, _RegValue);

  /* Wait for PLL1 enable status bit */
  while (!TARG_ReadBitInLong(PLLS1,CLO_BIT_nCLKEN))
  {
    asm("nop");
  }

  /* Wait for PLL1 stabilization status bit */
  while (!TARG_ReadBitInLong(PLLS1,CLO_BIT_nCLKSTAB))
  {
    asm("nop");
  }

  #ifndef __REL_V850_DK4H__
  /* Enable PLL2 */
  _RegValue = TARG_ReadLong(PLLE2) | CLO_MSK_nENTRG;
  _RegValue &= ~CLO_MSK_nSTPMK;
  TARG_ProtWriteLong(PROTCMD2, PLLE2, _RegValue);

  /* Wait for PLL2 enable status bit */
  while (!TARG_ReadBitInLong(PLLS2,CLO_BIT_nCLKEN))
  {
    asm("nop");
  }

  /* Wait for PLL2 stabilization status bit */
  while (!TARG_ReadBitInLong(PLLS2,CLO_BIT_nCLKSTAB))
  {
    asm("nop");
  }
  #endif /* !__REL_V850_DK4H__ */

  /* Enable write to Back-up RAM */
  TARG_WriteByte(BURC,MEM_MSK_BURWE);

  #ifdef USE_HBUS
  #if defined(__REL_V850_DN4H__) || defined(__REL_V850_DK4H__) || defined(__REL_V850_DP4H__)
  CPUS_SetHBUS();
  #endif /* defined(__REL_V850_DN4H__) || defined(__REL_V850_DK4H__) || defined(__REL_V850_DP4H__) */
  #endif /* USE_HBUS */

  Cpus_SetClockSourceID(PROTCMD0, 000, CLO_CKS_000);

#ifdef SYST_DX4_DEEPSTOP_USED
  if(!TARG_ReadBitInLong(PWS1, SBC_BIT_PWSnISO))
  {
    Wkss_ISO_1_WakeUp();
  }
#endif

  #ifndef CPU_USE_CUSTOM_CLOCK_CONFIG
  /* Clock source selection for all macros in AWO power domain */
  Cpus_SetClockSourceID(PROTCMD2, A02, CLO_CKS_PLL1_2); /* RTCA0, WDTA0, CLM0-2, VCPC0-1, LCCT0 */
  Cpus_SetClockSourceID(PROTCMD2, A03, CLO_CKS_PLL1_2); /* TAUJ0 */
  #ifdef __REL_V850_DJ4__
  Cpus_SetClockSourceID(PROTCMD2, A04, CLO_CKS_PLL1_2); /* TAUJ1 */
  #endif /* __REL_V850_DJ4__ */

  Cpus_SetClockSourceID(PROTCMD2, A05, CLO_CKS_PLL1_4); /* BURAM */
  Cpus_SetClockSourceID(PROTCMD2, A06, CLO_CKS_PLL0_1); /* FOUT */
  Cpus_SetClockSourceID(PROTCMD2, A07, Wdtd_WCC_CONFIGURATION_A0); /* WDTA0_WDTACKI *///sumit

  #ifdef __REL_V850_DJ4__
  Cpus_SetClockSourceID(PROTCMD2, A08, CLO_CKS_MOSC_1); /* LCCT0_MCLK */
  #endif /* __REL_V850_DJ4__ */

  #ifdef RTCD_USE_MAIN_CLK
  Cpus_SetClockSourceID(PROTCMD2, A09, CLO_CKS_MOSC_1); /* RTCA0_RTCATCKI */
  #else
  Cpus_SetClockSourceID(PROTCMD2, A09, CLO_CKS_SOSC);   /* RTCA0_RTCATCKI */
  #endif /* RTCD_USE_MAIN_CLK */

  /* Clock source selection for the CPU and all macros in ISO0 power domain */
  /*Cpus_SetClockSourceID(PROTCMD0, 000, CLO_CKS_PLL0_1);*/ /* CPU */
  Cpus_SetClockSourceID(PROTCMD0, 005, CLO_CKS_PLL0_2); /* WDTA1, CLM3 */
  Cpus_SetClockSourceID(PROTCMD0, 006, CLO_CKS_PLL1_2); /* TAUA0 */
  Cpus_SetClockSourceID(PROTCMD0, 007, CLO_CKS_LRNG_4); /* WDTA1_WDTACKI */

  #ifdef __REL_V850_DJ4_LE__                              /* PLL1 @40 MHz is considered */
  Cpus_SetClockSourceID(PROTCMD0, 012, CLO_CKS_PLL1_1); /* ADCA0 */
  #endif /* __REL_V850_DJ4_LE__ */

  #if defined(__REL_V850_DJ4_HE__) || defined(__REL_V850_DK4H__) /* PLL1 @80 MHz is considered */
  Cpus_SetClockSourceID(PROTCMD0, 012, CLO_CKS_PLL1_1); /* ADCA0 */
  #endif /* defined(__REL_V850_DJ4_HE__) || defined(__REL_V850_DK4H__) */

  #if defined(__REL_V850_DN4H__) || defined(__REL_V850_DP4H__) /* PLL1 @120 MHz is considered */
  Cpus_SetClockSourceID(PROTCMD0, 012, CLO_CKS_PLL1_3); /* ADCA0 */
  #endif /* defined(__REL_V850_DN4H__) || defined(__REL_V850_DP4H__) */

  Cpus_SetClockSourceID(PROTCMD0, 016, CLO_CKS_PLL1_2); /* Port filters */

  /* Clock source selection for all macros in ISO1 power domain */
  #ifdef __REL_V850_DJ4__
  Cpus_SetClockSourceID(PROTCMD1, 101, CLO_CKS_PLL0_2); /* ISO1 port control and filters */

  Cpus_SetClockSourceID(PROTCMD1, 102, CLO_CKS_PLL0_2); /* FLX0 (eray_bclk) */
  Cpus_SetClockSourceID(PROTCMD1, 103, CLO_CKS_PLL0_2); /* FLX0 (eray_sclk) */
  #endif /* __REL_V850_DJ4__ */
  Cpus_SetClockSourceID(PROTCMD1, 104, CLO_CKS_PLL1_2); /* TAUA1 */
  #if defined (__REL_V850_DJ4__) || defined(__REL_V850_Dx4H__)
  Cpus_SetClockSourceID(PROTCMD1, 105, CLO_CKS_PLL1_2); /* TAUJ2, TAUA4 */
  Cpus_SetClockSourceID(PROTCMD1, 106, CLO_CKS_PLL1_2); /* TAUA3 */
  #endif /* __REL_V850_DJ4__ */
  Cpus_SetClockSourceID(PROTCMD1, 107, CLO_CKS_PLL1_2); /* CSIG1-2 20MHz*/

  Cpus_SetClockSourceID(PROTCMD1, 108, CLO_CKS_HRNG_1); /* CSIG0, ISM0, LCDBI0, IICB0-1 */
  Cpus_SetClockSourceID(PROTCMD1, 109, CLO_CKS_PLL1_2); /* IISA0, PCMP0 */

  #if defined(__REL_V850_DN4H__) || defined(__REL_V850_DP4H__)
  Cpus_SetClockSourceID(PROTCMD1, 110, CLO_CKS_PLL1_2); /* IISA0_IISATSCK */
  #endif /* defined(__REL_V850_DN4H__) || defined (__REL_V850_DP4H__) */

  Cpus_SetClockSourceID(PROTCMD1, 111, CLO_CKS_PLL1_2); /* TAUA2 */
  Cpus_SetClockSourceID(PROTCMD1, 112, CLO_CKS_PLL1_2); /* URTE0, URTE1, SGEN0, OSTM0 */
  Cpus_SetClockSourceID(PROTCMD1, 113, CLO_CKS_PLL1_2); /* FCN0-2 */

  #if defined(__REL_V850_DN4H__) || defined(__REL_V850_DP4H__)
  Cpus_SetClockSourceID(PROTCMD1, 114, CLO_CKS_PLL1_2); /* URTE2-3 */
  #endif /* defined(__REL_V850_DN4H__) || defined (__REL_V850_DP4H__) */

  #ifdef __REL_V850_DJ4__
  Cpus_SetClockSourceID(PROTCMD1, 118, CLO_CKS_PLL0_1); /* GFX0, TCON0-1 */
  #endif /* __REL_V850_DJ4__ */
  Cpus_SetClockSourceID(PROTCMD1, 128, CLO_CKS_PLL1_2); /* Port filters */

  #if defined(__REL_V850_DN4H__) || defined(__REL_V850_DP4H__)
  Cpus_SetClockSourceID(PROTCMD1, 129, CLO_CKS_PLL1_1); /* HSFI0 */
  #endif /* defined(__REL_V850_DN4H__) || defined (__REL_V850_DP4H__) */

  #ifdef __REL_V850_DJ4__
  Cpus_SetClockSourceID(PROTCMD1, 130, CLO_CKS_PLL1_1); /* HSFI1 */
  #endif /* __REL_V850_DJ4__ */

  #if defined(__REL_V850_DN4H__) || defined(__REL_V850_DP4H__)
  Cpus_SetClockSourceID(PROTCMD1, 131, CLO_CKS_PLL1_1); /* MVO0_MVO0CLKDIV */
  Cpus_SetClockSourceID(PROTCMD1, 132, CLO_CKS_PLL1_1); /* SVO0_SVO0CLKDIV */
  #endif /* defined(__REL_V850_DN4H__) || defined(__REL_V850_DP4H__) */
  #else /* CPU_USE_CUSTOM_CLOCK_CONFIG */
  CPUS_ClockSelectorConfig();
  #endif /* CPU_USE_CUSTOM_CLOCK_CONFIG */


  #ifdef USE_HBUS
  #if defined(__REL_V850_DN4H__) || defined(__REL_V850_DP4H__)
  CPUS_EnableEMC0();
  #endif  /* defined(__REL_V850_DN4H__) || defined(__REL_V850_DP4H__) */
  #endif  /* USE_HBUS */

}


/*----------------------------------------------------------------------------*/
/* Name : CPUS_StartClockTreeFromSleep                                        */
/* Role : Start the Clock tree from sleep mode                                */
/* Interface : -                                                              */
/* Pre-condition : -                                                          */
/*     - lock-time has to be correctly set before service call.(PLLS reg)     */
/* Constraints :                                                              */
/*     - The service has to called upon wake-up from sleep mode               */
/*     - Main osc must be operating before service call                       */
/* Behavior :                                                                 */
/*  DO                                                                        */
/*    [Start PLL and wait for stabilization]                                  */
/*    [Select PLL output for Fcpu]                                            */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
__INLINE__ void CPUS_StartClockTreeFromSleep(void)
{
  /* Start the clock tree */
  ulong _RegValue;

  /* PLL0 configuration */
  /* Make sure that the PLL0 is stopped */
  if (TARG_ReadBitInLong(PLLS0,CLO_BIT_nCLKEN))
  {
    /* Wait for PLL0 enable status bit */
    do {
      _RegValue = TARG_ReadLong(PLLE0) | CLO_MSK_nDISTRG;
      TARG_ProtWriteLong(PROTCMD2, PLLE0, _RegValue);
    } while (TARG_ReadBitInLong(PLLS0,CLO_BIT_nCLKEN));
  }

#if defined(CLO_PLL0_SSCG)
  /* Set SSCG mode for PLL0                                   */
  /* Set Mr, Pr and Nr divider values,                        */
  /* mode, frequency and modulation dithering and VCO input freq*/
  TARG_WriteLong(PLLC0, CLO_PLL0_MSK_MR +
                        CLO_PLL0_MSK_NR + CLO_PLL0_MSK_PR +
                        CLO_PLL0_MSK_PC + CLO_PLL0_MSK_ADJ + CLO_PLL0_MSK_MDL +
                        CLO_PLL0_MSK_S);
  /* Set PLL0 stabilization time */
  TARG_WriteLong(PLLST0,(CLO_MSK_PLLSTk & CLO_STAB_PLLk_2MS));
#else /* PLL MODE */
  /* Set PLL mode for PLL0 (SSCG parameters are cleared)      */
  /* Set Mr, Pr and Nr divider values                         */
  TARG_WriteLong(PLLC0, CLO_MSK_PLLCkMS + CLO_PLL0_MSK_MR +
                        CLO_PLL0_MSK_NR + CLO_PLL0_MSK_PR);
  /* Set PLL0 stabilization time */
  TARG_WriteLong(PLLST0,(CLO_MSK_PLLSTk & CLO_STAB_PLLk_1MS));
#endif

  /* Unmask stop request - PLL0 is stopped in Isolated-Area-0 STOP mode */
  /* and is re-started upon wake-up from stand-by mode.                 */

  /* PLL1 configuration */
  /* Make sure that the PLL1 is stopped */
  if (TARG_ReadBitInLong(PLLS1,CLO_BIT_nCLKEN)) {
    /* Wait for PLL1 enable status bit */
    do {
      _RegValue = TARG_ReadLong(PLLE1) | CLO_MSK_nDISTRG;
      TARG_ProtWriteLong(PROTCMD2, PLLE1, _RegValue);
    } while (TARG_ReadBitInLong(PLLS1,CLO_BIT_nCLKEN));
  }

  /* Set PLL mode for PLL1 (SSCG parameters are cleared)      */
  /* Set Mr, Pr and Nr divider values                         */
  TARG_WriteLong(PLLC1, CLO_MSK_PLLCkMS + CLO_PLL1_MSK_MR +
                        CLO_PLL1_MSK_NR + CLO_PLL1_MSK_PR);

  /* Set PLL1 stabilization time */
  TARG_WriteLong(PLLST1,(CLO_MSK_PLLSTk & CLO_STAB_PLLk_2MS));

  /* Unmask stop request - PLL1 is stopped in Isolated-Area-0 STOP mode */
  /* and is re-started upon wake-up from stand-by mode.                 */

#ifndef __REL_V850_DK4__
  /* PLL2 configuration */
  /* Make sure that the PLL2 is stopped */
  if (TARG_ReadBitInLong(PLLS2,CLO_BIT_nCLKEN))
  {
    /* Wait for PLL2 enable status bit */
    do {
      _RegValue = TARG_ReadLong(PLLE2) | CLO_MSK_nDISTRG;
      TARG_ProtWriteLong(PROTCMD2, PLLE2, _RegValue);
    } while (TARG_ReadBitInLong(PLLS2,CLO_BIT_nCLKEN));
  }

  #if defined(CLO_PLL2_SSCG)
  /* Set SSCG mode for PLL2                                   */
  /* Set Mr, Pr and Nr divider values,                        */
  /* mode, frequency and modulation dithering and VCO input freq*/
  TARG_WriteLong(PLLC2, CLO_PLL2_MSK_MR +
                        CLO_PLL2_MSK_NR + CLO_PLL2_MSK_PR +
                        CLO_PLL2_MSK_PC + CLO_PLL2_MSK_ADJ + CLO_PLL2_MSK_MDL +
                        CLO_PLL2_MSK_S);
  /* Set PLL2 stabilization time */
  TARG_WriteLong(PLLST2,(CLO_MSK_PLLSTk & CLO_STAB_PLLk_2MS));
  #else /* PLL MODE */
  /* Set PLL mode for PLL2 (SSCG parameters are cleared)      */
  /* Set Mr, Pr and Nr divider values                         */
  TARG_WriteLong(PLLC2, CLO_MSK_PLLCkMS + CLO_PLL2_MSK_MR +
                        CLO_PLL2_MSK_NR + CLO_PLL2_MSK_PR);
  /* Set PLL2 stabilization time */
  TARG_WriteLong(PLLST2,(CLO_MSK_PLLSTk & CLO_STAB_PLLk_1MS));
  #endif /* CLO_PLL2_SSCG */

  /* Unmask stop request - PLL2 is stopped in Isolated-Area-0 STOP mode */
  /* and is re-started upon wake-up from stand-by mode.                 */
#endif /* !__REL_V850_DK4__ */

  /* Enable PLL0 */
  _RegValue = TARG_ReadLong(PLLE0) | CLO_MSK_nENTRG;
  _RegValue &= ~CLO_MSK_nSTPMK;
  TARG_ProtWriteLong(PROTCMD2, PLLE0, _RegValue);

  /* Wait for PLL0 enable status bit */
  while (!TARG_ReadBitInLong(PLLS0,CLO_BIT_nCLKEN)) {
      asm("nop");
  }

  /* Wait for PLL0 stabilization status bit */
  while (!TARG_ReadBitInLong(PLLS0,CLO_BIT_nCLKSTAB)) {
      asm("nop");
  }

  /* Wait for PLL0 active status bit */
  while (!TARG_ReadBitInLong(PLLS0,CLO_BIT_nCLKACT)) {
      asm("nop");
  }

  /* Enable PLL1 */
  _RegValue = TARG_ReadLong(PLLE1) | CLO_MSK_nENTRG;
  _RegValue &= ~CLO_MSK_nSTPMK;
  TARG_ProtWriteLong(PROTCMD2, PLLE1, _RegValue);

  /* Wait for PLL1 enable status bit */
  while (!TARG_ReadBitInLong(PLLS1,CLO_BIT_nCLKEN)) {
      asm("nop");
  }

  /* Wait for PLL1 stabilization status bit */
  while (!TARG_ReadBitInLong(PLLS1,CLO_BIT_nCLKSTAB)) {
      asm("nop");
  }

  /* Wait for PLL1 active status bit */
  while (!TARG_ReadBitInLong(PLLS1,CLO_BIT_nCLKACT)) {
      asm("nop");
  }

#ifndef __REL_V850_DK4__
  /* Enable PLL2 */
  _RegValue = TARG_ReadLong(PLLE2) | CLO_MSK_nENTRG;
  _RegValue &= ~CLO_MSK_nSTPMK;
  TARG_ProtWriteLong(PROTCMD2, PLLE2, _RegValue);

  /* Wait for PLL2 enable status bit */
  while (!TARG_ReadBitInLong(PLLS2,CLO_BIT_nCLKEN)) {
      asm("nop");
  }

  /* Wait for PLL2 stabilization status bit */
  while (!TARG_ReadBitInLong(PLLS2,CLO_BIT_nCLKSTAB)) {
      asm("nop");
  }

  /* Wait for PLL2 active status bit */
  while (!TARG_ReadBitInLong(PLLS2,CLO_BIT_nCLKACT)) {
      asm("nop");
  }
#endif /* !__REL_V850_DK4__ */

  /* Enable write to Back-up RAM */
  TARG_WriteByte(BURC,MEM_MSK_BURWE);
  #ifndef CPU_USE_CUSTOM_CLOCK_CONFIG
  #if defined(__REL_V850_DJ4__)
  /* Clock source selection for all macros in ISO1 power domain */
  Cpus_SetClockSourceID(PROTCMD1, 101, CLO_CKS_PLL0_2); /* ISO1 port control and filters */
  Cpus_SetClockSourceID(PROTCMD1, 102, CLO_CKS_PLL0_2); /* FLX0 (eray_bclk) */
  Cpus_SetClockSourceID(PROTCMD1, 103, CLO_CKS_PLL0_2); /* FLX0 (eray_sclk) */
  #endif /* __REL_V850_DJ4__ */
  Cpus_SetClockSourceID(PROTCMD1, 104, CLO_CKS_PLL1_2); /* TAUA1 */
  #if defined(__REL_V850_DJ4__)
  Cpus_SetClockSourceID(PROTCMD1, 105, CLO_CKS_PLL1_2); /* TAUJ2, TAUA4 */
  Cpus_SetClockSourceID(PROTCMD1, 106, CLO_CKS_PLL1_2); /* TAUA3 */
  #endif /* __REL_V850_DJ4__ */
  Cpus_SetClockSourceID(PROTCMD1, 107, CLO_CKS_PLL1_2); /* CSIG1-2 20MHz*/
  Cpus_SetClockSourceID(PROTCMD1, 108, CLO_CKS_HRNG_1); /* CSIG0, ISM0, LCDBI0, IICB0-1 */
  Cpus_SetClockSourceID(PROTCMD1, 109, CLO_CKS_PLL1_2); /* IISA0, PCMP0 */

  #if defined(__REL_V850_DN4H__) || defined(__REL_V850_DP4H__)
  Cpus_SetClockSourceID(PROTCMD1, 110, CLO_CKS_PLL1_2); /* IISA0_IISATSCK */
  #endif /* defined(__REL_V850_DN4H__) || defined (__REL_V850_DP4H__) */

  Cpus_SetClockSourceID(PROTCMD1, 111, CLO_CKS_PLL1_2); /* TAUA2 */
  Cpus_SetClockSourceID(PROTCMD1, 112, CLO_CKS_PLL1_2); /* URTE0, URTE1, SGEN0, OSTM0 */
  Cpus_SetClockSourceID(PROTCMD1, 113, CLO_CKS_PLL1_2); /* FCN0-2 */

  #if defined(__REL_V850_DN4H__) || defined(__REL_V850_DP4H__)
  Cpus_SetClockSourceID(PROTCMD1, 114, CLO_CKS_PLL1_2); /* URTE2-3 */
  #endif /* defined(__REL_V850_DN4H__) || defined (__REL_V850_DP4H__) */

  #if defined(__REL_V850_DJ4__)
  Cpus_SetClockSourceID(PROTCMD1, 118, CLO_CKS_PLL0_1); /* GFX0, TCON0-1 */
  #endif /* __REL_V850_DJ4__ */

  Cpus_SetClockSourceID(PROTCMD1, 128, CLO_CKS_PLL1_2); /* Port filters */

  #if defined(__REL_V850_DN4H__) || defined(__REL_V850_DP4H__)
  Cpus_SetClockSourceID(PROTCMD1, 129, CLO_CKS_PLL1_1); /* HSFI0 */
  #endif /* defined(__REL_V850_DN4H__) || defined (__REL_V850_DP4H__) */

  #if defined(__REL_V850_DJ4__)
  Cpus_SetClockSourceID(PROTCMD1, 130, CLO_CKS_PLL1_1); /* HSFI1 */
  #endif /* __REL_V850_DJ4__ */

  #if defined(__REL_V850_DN4H__) || defined(__REL_V850_DP4H__)
  Cpus_SetClockSourceID(PROTCMD1, 131, CLO_CKS_PLL1_1); /* MVO0_MVO0CLKDIV */
  Cpus_SetClockSourceID(PROTCMD1, 132, CLO_CKS_PLL1_1); /* SVO0_SVO0CLKDIV */
  #endif /* defined(__REL_V850_DN4H__) || defined(__REL_V850_DP4H__) */
  #else /* CPU_USE_CUSTOM_CLOCK_CONFIG */
  CPUS_ClockSelectorConfigFromSleep();
  #endif /* CPU_USE_CUSTOM_CLOCK_CONFIG */
}

/*----------------------------------------------------------------------------*/
/* Name : CPUS_StopPll                                                        */
/* Role : Stop Pll                                                            */
/* Interface : -                                                              */
/* Pre-condition : -                                                          */
/* Constraints : - WATCH, Sub-WATCH, STOP mode must be entered after or       */
/*                 bit SDC.SDCR must be set to 1                              */
/* Behavior :                                                                 */
/*  DO                                                                        */
/*    [Nothing to do: PLL is automatically stopped when entering WATCH, ]     */
/*    [Sub-WATCH or STOP mode, or if bit SDC.SDCR is set to 1]                */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#define CPUS_StopPll()


/*----------------------------------------------------------------------------*/
/* Name : CPUS_StopRingOsc240KHz                                              */
/* Role : Stop 240 KHz internal ring oscillator                               */
/* Interface : -                                                              */
/* Pre-condition : -                                                          */
/* Constraints : Clock must not be used by any module                         */
/*  DO                                                                        */
/*      [Nothing to do: No way to stop by software 240 kHz]                   */
/*      [WCC.ROSTP bit specify if ring oscillator stops if WATCH, Sub-WATCH, ]*/
/*      [or STOP mode entered. (See WCC config set in wdtd.h)]                */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#define CPUS_StopRingOsc240KHz()

#endif /* __REL_V850_Dx4__ */

#ifdef __NEC_V850_Fx3__

/*----------------------------------------------------------------------------*/
/* Name : CPUS_StopRingOsc8MHz                                                */
/* Role : Stop 8 MHz internal ring oscillator                                 */
/* Interface : -                                                              */
/* Pre-condition : -                                                          */
/* Constraints : Clock must not be used by any module                         */
/*  DO                                                                        */
/*      [Stop 8 MHz internal ring OSC]                                        */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#define CPUS_StopRingOsc8MHz() TARG_SetBits(RCM, CLO_MSK_HRSTOP)


/*----------------------------------------------------------------------------*/
/* Name : CPUS_StopRingOsc240KHz                                              */
/* Role : Stop 240 KHz internal ring oscillator                               */
/* Interface : -                                                              */
/* Pre-condition : -                                                          */
/* Constraints : Clock must not be used by any module                         */
/*  DO                                                                        */
/*      [Stop 240 kHz internal ring OSC]                                      */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#define CPUS_StopRingOsc240KHz() TARG_SetBits(RCM, CLO_MSK_RSTOP)


/*----------------------------------------------------------------------------*/
/* Name : CPUS_StartClockTree                                                 */
/* Role : Startup the Clock Tree                                              */
/* Interface : -                                                              */
/* Pre-condition : -                                                          */
/* Constraints :                                                              */
/* Behavior :                                                                 */
/*  DO                                                                        */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#define CPUS_StartClockTree() CPUS_StartClockTreeFromReset()


/*----------------------------------------------------------------------------*/
/* Name : CPUS_StartPll                                                       */
/* Role : Startup the PLL                                                     */
/* Interface : -                                                              */
/* Pre-condition : -                                                          */
/* Constraints :                                                              */
/*               - BOOT application setup system and needs to start the PLL   */
/*                 from reset configuration.                                  */
/*               - CLIENT application doesn't setup system and needs only     */
/*                 to start the PLL upon return of Sleep mode.                */
/*----------------------------------------------------------------------------*/
#if defined(__BOOT_LOADER_FLASHER_LINK__) || \
    defined(__BOOT_CLIENT_EOL_LINK__)     || \
    defined(__BOOT_LOADER_LINK__)
#define CPUS_StartPll() CPUS_StartClockTreeFromReset()
#endif /* __BOOT_LOADER_FLASHER_LINK__ || __BOOT_CLIENT_EOL_LINK__ */

#if defined(__CLIENT_LINK__)              || \
    defined(__EOL_LINK__)                 || \
    defined(__CLIENT_EOL_LINK__)          || \
    defined(__FLASHER_LINK__)
#define CPUS_StartPll() CPUS_StartClockTreeFromSleep()
#endif /* __CLIENT_LINK__) || __EOL_LINK__ || __CLIENT_EOL_LINK__ */


/*----------------------------------------------------------------------------*/
/* Name : CPUS_StartClockTreeFromReset                                        */
/* Role : Startup the Clock Tree from reset configuration to PLL operating    */
/*        mode.                                                               */
/*        Clock configuration after reset:                                    */
/*         - Fcpu                           : 8 MHz internal ring osc         */
/*         - Main OSC state                 : OFF                             */
/*         - PLL state                      : OFF                             */
/*        Clock configuration after service call:                             */
/*         - Fcpu                           : PLL output                      */
/*         - Main OSC state                 : ON                              */
/*         - PLL state                      : ON                              */
/* Interface : -                                                              */
/* Pre-condition : -                                                          */
/* Constraints : -                                                            */
/* Behavior :                                                                 */
/*  DO                                                                        */
/*    [Select input clock for modules]                                        */
/*    [Start the main oscillator and wait for stabilization]                  */
/*    [Change Fcpu input clock from 8 Mhz internal to main OSC output]        */
/*    [Start PLL and wait for stabilization]                                  */
/*    [Select PLL output for Fcpu]                                            */
/*  OD                                                                        */
/* History :                                                                  */
/*  11/05/2011 18:42 add friendly configurable clock path behaviors for       */
/*                   system/core clock and peripheral clocks                  */
/*  (see the description of the clock generator inside the user's manuel)     */
/*                                                                            */
/*  after service call                                                        */
/*    - MainOsc                  : Started                                    */
/*    - clkout, peripheral clock :                                            */
/*        Cpus_ClockGenerator is used to have a friendly configurable clock   */
/*        path.                                                               */
/*                          +-------+--------+---------                       */
/*      Cpus_ClockGenerator | fxx   | fxp1   | ISEL40                         */
/*      --------------------+-------+--------+---------                       */
/*      Cpus_OSC            | fx    | fx     | 0                              */
/*      Cpus_PLL            | fpll  | fxx    | 0                              */
/*      Cpus_SSCG           | fpll  | fxx    | 0                              */
/*      Cpus_SSCG_FXMPLL (*)| fpll  | fxmpll | managed                        */
/*                                                                            */
/*      (*) used in order to switch "pll without sscg" toward peripheral clk  */
/*                                                                            */
/*----------------------------------------------------------------------------*/
__INLINE__ void CPUS_StartClockTreeFromReset(void)
{
    /* Make selectable Frh/8 as TMM input clock */
    TARG_WriteByte(SELCNT0, 0x80);

    /* Selection of Fxp1 input clock for UARTD1, UARTD0, TAA0-TAA4 */
    TARG_WriteByte(SELCNT2, 0x00);

    /* Set Oscillation stabilization time in accordance with MainOSC */
    /* Osc stabilization time = 2^12/fxx = 819 Us */
    TARG_WriteByte(OSTS, 0x02);

  #if (Cpus_ClockGenerator == Cpus_OSC) || (Cpus_ClockGenerator == Cpus_PLL)
    /* Write security register first */
    TARG_WriteByte(PRCMD, 0x00);

    /* Start main oscillator */
    TARG_WriteByte(PCC, 0x00);

    /* Ensure that the main oscillator is stabilized */
    while(TARG_ReadByte(OSTC)==0);

    /* Write security register first */
    TARG_WriteByte(PRCMD, CLO_MSK_MCM0);

    /* Select main oscillator = Main Osc or PLL output */
    TARG_WriteByte(MCM, CLO_MSK_MCM0);
  #endif /* (Cpus_ClockGenerator == Cpus_OSC) || (Cpus_ClockGenerator == Cpus_PLL) */

  #if (Cpus_ClockGenerator == Cpus_PLL)
    /* Start the PLL with lockup time = 2^13/fx */
    TARG_SetBits(PLLCTL, CLO_MSK_PLLON);

    /* Ensure that the PLL is locked */
    while(TARG_ReadBit(LOCKR,CLO_BIT_LOCK) !=0);

    /* Main system clock = Fpll */
    TARG_SetBits(PLLCTL, CLO_MSK_SELPLL);
  #endif /* (Cpus_ClockGenerator == Cpus_PLL) */

  #if (Cpus_ClockGenerator == Cpus_SSCG) || (Cpus_ClockGenerator == Cpus_SSCG_FXMPLL)

    /* ====================================================================== */
    /* (a)  Configuration of SFC0 and of SFC1                                 */
    /* (a') delay of 1 us in order to safe the start                          */
    /* (b)  SSCGCTL.SSCGON = 1                                                */

    /* caution secure a setup time for at least 1 us via software after the   */
    /* SFC0 and SFC1 registers are set and until the SSCGON bit is changed    */
    /* from 0 to 1.                                                           */

    /* SSCG control register SFC0 */
    TARG_WriteByte(PRCMD, Cpus_Reg_SFC0);
    TARG_WriteByte(SFC0,  Cpus_Reg_SFC0);

    /* delay is 1us multiply by (expected frequency/actual frequency)         */
    /* for instance : expected is 20MHz, actual is 5Mhz => delay is 1 x 4=4us */
    SYST_Wait_SYST_500nS();
    SYST_Wait_SYST_500nS();

    /* SSCG control register SFC1 */
    TARG_WriteByte(PRCMD, Cpus_Reg_SFC1);
    TARG_WriteByte(SFC1,  Cpus_Reg_SFC1);

    /* delay is 1us multiply by (expected frequency/actual frequency)         */
    /* for instance : expected is 20MHz, actual is 5Mhz => delay is 1 x 4=4us */
    SYST_Wait_SYST_500nS();
    SYST_Wait_SYST_500nS();

    /* SSCGCTL.SSCGON = 1 */
    TARG_SetBits(SSCGCTL, CLO_MSK_SSCGON);

    /* ====================================================================== */
    /* (c) Configuration of PLLS                                              */
    /* (d) SSCGCTL.SELSSCG = 1                                                */

    /* Specify the settling time of the PLL                                   */
    /* For instance datasheet of 3370 is PLL  lock-time max  = 800us          */
    /* For instance datasheet of 3370 is SSCG lock-time max = 1000us          */
    /* For instance 5MHz for external oscillator                              */
    /* Pll lock-time = 2^12/Fx = 819.2 us                                     */
    /* Pll lock-time = 2^13/Fx = 1638.4 us                                    */
    TARG_WriteByte(PLLS, 0x03); /* 1638.4 us */

    /* Write the required PLL and SSCG lock-up time to the PLLS register and  */
    /* set the PLLCLTL.PLLON = 1 after setting SSCGCTL.SSCGON = 1.            */
    /* The SSCG output clock can only be selected (SELSSCG = 1), if the SSCG  */
    /* is enabled (SSCGON = 1).                                               */

    /* SSCGCTL.SELSSCG = 1 */
    TARG_SetBits(SSCGCTL, CLO_MSK_SELSSCG);

    /* ====================================================================== */
    /* (e-1) Test : OSTC.MSTS = 1 ?                                           */
    /* [Test on the stability of the main clock]                              */
    /* (e-2) if not, go to (i-1)                                              */
    /* (e-3) if yes, PLLCTL.PLLON = 1 and go to (f-1)                         */
    /* [start of behaviors of the PLL and SSCG]                               */
    if ( TARG_ReadBit(OSTC, CLO_BIT_MSTS) == 0 )
    {
      /* MainOSC stopped or waiting for oscillation stabilization.            */
      /* (e-2) Si non, suite a (i-1)                                          */

      /* ==================================================================== */
      /* (i-1) Test : PCC.MCK = 0 ?                                           */
      /* [Test of oscillation of the main clock]                              */
      /* (i-2) Si oui, suite a (l-1)                                          */
      /* (i-3) Si non, suite a (j)                                            */

      /* Operation of MainOSC: 0: Oscillation enabled. 1: Oscillation stopped */
      if ( TARG_ReadBit(PCC,CLO_BIT_MCK) == 0 )
      {
        /* Oscillation enabled */

        /* ================================================================== */
        /* (l-1) Test : OSTC.MSTS = 1 ?                                       */
        /* [Oscillation but waiting for stability]                            */
        /* (l-2) if yes, goto a (l-1)                                         */
        /* (l-3) if not, PLLCTL.PLLON = 1 and goto (f-1)                      */

        /* MSTS = 1: MainOSC oscillation stabilization ended.                 */
        while ( TARG_ReadBit(OSTC,CLO_BIT_MSTS) != 1 );

        /* (l-3) Si oui, PLLCTL.PLLON = 1 et suite a (f-1)                    */
        TARG_SetBits(PLLCTL, CLO_MSK_PLLON);
      }
      else
      {
        /* Oscillation stopped */

        /* ================================================================== */
        /* (j) PLLCTL.PLLON = 1                                               */
        /* (k) PCC.MCK = 0 et suite a (f-1)                                   */
        /* [start of the PLL and SSCG]                                        */

        /* (j) PLLCTL.PLLON = 1                                               */
        TARG_SetBits(PLLCTL, CLO_MSK_PLLON);

        /* (k) Write security register first */
        TARG_WriteByte(PRCMD, 0x00);

        /* Start main oscillator on fx                                        */
        /*   - Feedback resistor(s) connected. (main and sub)                 */
        /*   - Oscillation enabled                                            */
        /*   - Main system clock fXX operation                                */
        /*   - Clock selection = fXX                                          */
        TARG_WriteByte(PCC, 0x00);

        /* Ensure that the main oscillator is stabilized */
         while ( TARG_ReadBit(OSTC,CLO_BIT_MSTS) != 1 );
      }
    }
    else
    {
      /* MainOSC oscillation stabilization ended. */
      /* Start the PLL with lockup time = 2^13/fx */

      /* (e-3) if yes, PLLCTL.PLLON = 1 and goto (f-1) */
      TARG_SetBits(PLLCTL, CLO_MSK_PLLON);
    }

    /* ====================================================================== */
    /* (f-1) Test : LOCKR.LOCK = 0 ?                                          */
    /* [Test on the lock of the PLL and SSCG]                                 */
    /* (f-2) if no,  goto (f-1)                                               */
    /* (f-3) if yes, goto (g-1)                                               */

    /* Ensure that the PLL is locked                                          */
    while(TARG_ReadBit(LOCKR,CLO_BIT_LOCK) !=0);

    /* ====================================================================== */
    /* (g-1) Test : MCM.MCS = 1 ?                                             */
    /* (g-2) if yes, MCM.MCM0 = 1 and goto (g-1)                              */
    /* (g-3) if no, goto (h)                                                  */
    while ( TARG_ReadBit(MCM,CLO_BIT_MCS) != 1 )
    {
      /* Write security register first */
      TARG_WriteByte(PRCMD, CLO_MSK_MCM0);

      /* Select main oscillator = Main Osc or PLL output */
      TARG_WriteByte(MCM, CLO_MSK_MCM0);
    }

    /* ====================================================================== */
    /* (h) PLLCTL.SELPLL = 1                                                  */
    /* [start of the CPU and the SSCG]                                        */

    /* main system clock = Fpll */
    TARG_SetBits(PLLCTL, CLO_MSK_SELPLL);

    #if (Cpus_ClockGenerator == Cpus_SSCG_FXMPLL)
    /* when sscg is used the spread spectrum is not applied to clock periph.  */
    /* Peripheral clock = fxmpll */
    TARG_SetBits(SELCNT4, CLO_MSK_ISEL40);
    #endif /* (Cpus_ClockGenerator == Cpus_SSCG_FXMPLL) */

  #endif /* (Cpus_ClockGenerator == Cpus_SSCG) || (Cpus_ClockGenerator == Cpus_SSCG_FXMPLL) */


  #ifndef CPUS_DO_NOT_ACTIVATE_PRESCALER3
    /* Prescaler3 control register                      */
    /*  => fBRG = fX / (2^m * N * 2) (avec m=0 et n 78) */
    /*  => fBRG = 32.051 kHz                            */
    TARG_WriteByte(PRSCM0, Prescaler3CompareValue);
    TARG_SetBits(PRSM0, CLO_MSK_BGCE0);
  #endif /* CPUS_DO_NOT_ACTIVATE_PRESCALER3 */

    /* Specify the settling time of the PLL */
    /* Datasheet: PLL lock-time max = 800us */
    /* Pll lock-time = 2^12/Fx = 819.2 us */
    TARG_WriteByte(PLLS, 0x02);

    /* Set OSTS register in order to prepare wake-up from IDLE2 mode */
    /* When IDLE2 mode is released, set the stabilization time to the */
    /* flash set up time requirement (clock-Though mode selected in IDLE2 mode*/
    /* Datasheet: "MINIMUM" time required to stabilize flash = 54us */
    /* Osc stabilization time = 2^11/fx = 409.6 us (7X Minimum stabilization) */
    TARG_WriteByte(OSTS, 0x19);
}


/*----------------------------------------------------------------------------*/
/* Name : CPUS_StartClockTreeFromSleep                                        */
/* Role : Start the Clock tree from sleep mode                                */
/* Interface : -                                                              */
/* Pre-condition : -                                                          */
/*     - lock-time has to be correctly set before service call.(PLLS reg)     */
/* Constraints :                                                              */
/*     - The service has to called upon wake-up from sleep mode               */
/*     - Main osc must be operating before service call                       */
/* Behavior :                                                                 */
/*  DO                                                                        */
/*    [Start PLL and wait for stabilization]                                  */
/*    [Select PLL output for Fcpu]                                            */
/*  OD                                                                        */
/* History : 18/05/2011 18:09  add SSCG behaviors and MainOSC behviors        */
/* Constraints :                                                              */
/*     - The service has to called upon wake-up from sleep mode               */
/*     - Main osc may be not operating before service call                    */
/*                                                                            */
/*         SYST_GoIntoStopMode + CPUS_StartClockTreeFromSleep = allowed       */
/*         GoIntoIdle2Mode     + CPUS_StartClockTreeFromSleep = allowed       */
/*----------------------------------------------------------------------------*/
__INLINE__ void CPUS_StartClockTreeFromSleep(void)
{
#if (Cpus_ClockGenerator == Cpus_OSC)
  /* test if MainOSC stopped or waiting for oscillation stabilization */
  if ( TARG_ReadBit(OSTC, CLO_BIT_MSTS) == 0 )
  {
    /* test if MainOSC enabled */
    if ( TARG_ReadBit(PCC,CLO_BIT_MCK) == 0 )
    {
      /* waiting for oscillation stabilization */
      while ( TARG_ReadBit(OSTC,CLO_BIT_MSTS) != 1 );
    }
    else
    {
      /* enable oscillation  */
      TARG_WriteByte(PRCMD, 0x00);
      TARG_WriteByte(PCC,   0x00);
      /* waiting for oscillation stabilization */
      while ( TARG_ReadBit(OSTC,CLO_BIT_MSTS) != 1 );
    }
  }

  /* Operating on MainOSC clock fX */
  while ( TARG_ReadBit(MCM,CLO_BIT_MCS) != 1 )
  {
    TARG_WriteByte(PRCMD, CLO_MSK_MCM0);
    TARG_WriteByte(MCM,   CLO_MSK_MCM0);
  }
#endif /* (Cpus_ClockGenerator == Cpus_OSC) */

#if (Cpus_ClockGenerator == Cpus_PLL)
  /* Start the PLL with lockup time = 2^13/fx */
  TARG_WriteBit(PLLCTL, CLO_BIT_PLLON, 1);

  /* Ensure that the PLL is locked */
  /* Wait for internal counter time-out based on PLLS specification */
  while(TARG_ReadBit(LOCKR,CLO_BIT_LOCK) !=0);

  /* Main system clock = Fpll */
  TARG_WriteBit(PLLCTL, CLO_BIT_SELPLL, 1);
#endif /* (Cpus_ClockGenerator == Cpus_PLL) */

#if (Cpus_ClockGenerator == Cpus_SSCG) || (Cpus_ClockGenerator == Cpus_SSCG_FXMPLL)
  /* ======================================================================== */
  /* (b) SSCGCTL.SSCGON  = 1                                                  */
  /* (d) SSCGCTL.SELSSCG = 1                                                  */
  TARG_SetBits(SSCGCTL, CLO_MSK_SSCGON);  /* SSCGCTL.SSCGON  = 1 */
  TARG_SetBits(SSCGCTL, CLO_MSK_SELSSCG); /* SSCGCTL.SELSSCG = 1 */

  /* ======================================================================== */
  /* (e-1) Test : OSTC.MSTS = 1 ?                                             */
  /* (e-2) if no, goto (i-1)                                                  */
  /* (e-3) if yes, PLLCTL.PLLON = 1 and goto (f-1) */
  if ( TARG_ReadBit(OSTC, CLO_BIT_MSTS) == 0 )
  {
    /* ====================================================================== */
    /* (i-1) Test : PCC.MCK = 0 ?                                             */
    /* (i-2) if yes, goto (l-1)                                               */
    /* (i-3) if no, goto (j)                                                  */

    /* Operation of MainOSC: 0: Oscillation enabled. 1: Oscillation stopped */
    if ( TARG_ReadBit(PCC,CLO_BIT_MCK) == 0 )
    {
      /* ==================================================================== */
      /* (l-1) Test : OSTC.MSTS = 1 ?                                         */
      /* (l-2) if no, goto (l-1)                                              */
      /* (l-3) if yes, PLLCTL.PLLON = 1 and goto (f-1)                        */
      while ( TARG_ReadBit(OSTC,CLO_BIT_MSTS) != 1 );
      TARG_SetBits(PLLCTL, CLO_MSK_PLLON);
    }
    else
    {
      /* =================================================================== */
      /* (j) PLLCTL.PLLON = 1                                                */
      /* (k) PCC.MCK = 0 et suite a (f-1)                                    */
      TARG_SetBits(PLLCTL, CLO_MSK_PLLON);
      TARG_WriteByte(PRCMD, 0x00);
      TARG_WriteByte(PCC,   0x00);
      /* Ensure that the main oscillator is stabilized */
      while ( TARG_ReadBit(OSTC,CLO_BIT_MSTS) != 1 );
    }
  }
  else
  {
    TARG_SetBits(PLLCTL, CLO_MSK_PLLON);
  }

  /* ======================================================================== */
  /* (f-1) Test : LOCKR.LOCK = 0 ?                                            */
  /* [Test sur le verrouillage des PLL et SSCG]                               */
  /* (f-2) Si non, retour a (f-1)                                             */
  /* (f-3) Si oui, suite a (g-1)                                              */

  /* Ensure that the PLL is locked                                            */
  while(TARG_ReadBit(LOCKR,CLO_BIT_LOCK) !=0);

  /* ======================================================================== */
  /* (g-1) Test : MCM.MCS = 1 ?                                               */
  /* (g-2) Si non, MCM.MCM0 = 1 et retour a (g-1)                             */
  /* (g-3) Si oui, suite a (h)                                                */
  while ( TARG_ReadBit(MCM,CLO_BIT_MCS) != 1 )
  {
    TARG_WriteByte(PRCMD, CLO_MSK_MCM0);
    TARG_WriteByte(MCM, CLO_MSK_MCM0);
  }

  /* ======================================================================== */
  /* (h) PLLCTL.SELPLL = 1                                                    */
  TARG_SetBits(PLLCTL, CLO_MSK_SELPLL);

  #if (Cpus_ClockGenerator == Cpus_SSCG_FXMPLL)
  /* when sscg is used the spread spectrum is not applied to clock periph.  */
  /* Peripheral clock = fxmpll */
  TARG_SetBits(SELCNT4, CLO_MSK_ISEL40);
  #endif /* (Cpus_ClockGenerator == Cpus_SSCG_FXMPLL) */

#endif /* (Cpus_ClockGenerator == Cpus_SSCG) || (Cpus_ClockGenerator == Cpus_SSCG_FXMPLL) */
}


/*----------------------------------------------------------------------------*/
/* Name : CPUS_StopPll                                                        */
/* Role : Stop Pll, set micro in clock-through mode                           */
/* Interface : -                                                              */
/* Pre-condition : -                                                          */
/* Constraints :                                                              */
/* Behavior :                                                                 */
/*  DO                                                                        */
/*    [Select clock-Through mode(operating on mainOSC directly)]              */
/*    [Wait for 8 clocks or more (hardware constraint)]                       */
/*    [Stop of the PLL]                                                       */
/*  OD                                                                        */
/* History : 19/05/2011 14:37 Add ISEL40 to 0 before stopping the PLL         */
/* to take into acount the note 1 and because new behaviors allow             */
/* fxp1 = fxmpll and "Be sure to set ISEL40 to 0 before stopping the PLL"     */
/*----------------------------------------------------------------------------*/
#if (Cpus_ClockGenerator != Cpus_SSCG_FXMPLL)
#define CPUS_StopPll()                              \
     TARG_WriteBit(PLLCTL, CLO_BIT_SELPLL, 0);      \
     __NOP__;                                       \
     __NOP__;                                       \
     __NOP__;                                       \
     __NOP__;                                       \
     __NOP__;                                       \
     __NOP__;                                       \
     __NOP__;                                       \
     __NOP__;                                       \
     TARG_WriteBit(PLLCTL, CLO_BIT_PLLON, 0)
#endif /* (Cpus_ClockGenerator != Cpus_SSCG_FXMPLL) */

#if (Cpus_ClockGenerator == Cpus_SSCG_FXMPLL)
#define CPUS_StopPll()                              \
     TARG_ClearBits(SELCNT4, CLO_MSK_ISEL40);       \
     TARG_WriteBit(PLLCTL, CLO_BIT_SELPLL, 0);      \
     __NOP__;                                       \
     __NOP__;                                       \
     __NOP__;                                       \
     __NOP__;                                       \
     __NOP__;                                       \
     __NOP__;                                       \
     __NOP__;                                       \
     __NOP__;                                       \
     TARG_WriteBit(PLLCTL, CLO_BIT_PLLON, 0)
#endif /* (Cpus_ClockGenerator == Cpus_SSCG_FXMPLL) */

#endif /*__NEC_V850_Fx3__*/


/*----------------------------------------------------------------------------*/
/* Name : CPUS_SetCpu                                                         */
/* Role : Initialise CPU                                                      */
/* Interface : -                                                              */
/* Pre-condition : -                                                          */
/* Constraints :                                                              */
/*                 - stack pointer is not set when this service is used       */
/* Behaviour :                                                                */
/*  DO                                                                        */
/*       [Initialisation of the global pointer]                               */
/*       [Initialisation of the text pointer]                                 */
/*       [Initialisation of the stack pointer]                                */
/*       [Initialisation of NPB wait states]                                  */
/*       [Initialisation of programmable peripheral I/O area]                 */
/*       [Enable on-chip debug capability after reset]                        */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
__INLINE__ void CPUS_SetCpu(void)
{
#ifdef __debug_project__
  #pragma asm
  -- Initialisation of the global pointer
  movhi  hi(___ghsbegin_sdabase),zero,gp
  movea  lo(___ghsbegin_sdabase),gp,gp

  -- Point gp 32K past SDA start
  addi    0x4000,gp,gp
  addi    0x4000,gp,gp

  -- Initialisation of the text pointer
  movhi  hi(___ghsbegin_robase),zero,tp
  movea  lo(___ghsbegin_robase),tp,tp

  -- Initialisation of the stack pointer
  movhi  hi(___ghsend_stack-4),zero,sp
  movea  lo(___ghsend_stack-4),sp,sp
  #pragma endasm
#endif
  /* =======================================================================*/
  /* == Initialisation of NPB wait states                              =====*/
  /* =======================================================================*/
  #ifdef __NEC_V850_Fx3__
  /* F_CPU = 20 Mhz (5 x 8 / 2) => SUWL = 0 & VSWL = 1 => VSWC = 0x01 */
  /* (see page 334 of U17793EE1V1UM00)*/
  TARG_WriteByte(VSWC, 0x01);
  #endif /*__NEC_V850_Fx3__*/

  #ifdef __NEC_V850_Dx3__
  TARG_WriteByte(VSWC, Cpus_Reg_VSWC);
  #endif /* __NEC_V850_Dx3__ */


  /* =======================================================================*/
  /* == Initialisation of clocks and start of Watchdog                 =====*/
  /* =======================================================================*/
  /* Note : For Fx3, the WDG is started by default with 240 KHz ring OSC */
  /* Defautlt time-out: 2^19/Frl = 2.1845s */
  /* For Dx3: WDG must be started */
  #if defined(__NEC_V850_Dx3__)
  CPUS_StartClockTree(Cpus_STABILIZATION_WITH_240KHZ);
  #else
  CPUS_StartClockTree();
  #endif /* defined(__NEC_V850_Dx3__) */

  #ifdef  __REL_V850_Dx4__
  #ifndef VECTOR_FBL_PACKAGE
   WDTD_Init();
   WDTD_Start();
   WDTD_Refresh();
  #endif
  #endif

  #ifndef  __REL_V850_Dx4__
  WDTD_Init();
  WDTD_Start();
  #endif

  #if (defined (__NEC_V850_Fx3__) && !defined (CPUS_DISABLE_LVI))
  /* Configure the lvi function (low voltage detection) to generate */
  /* a reset if microcontroleur power supply go below 3.7V          */
  TARG_WriteByte(LVIS, 0x01); /* set threshold to 3.7V */
  TARG_WriteByte(PRCMD, 0x82);/* write to a write protected register */
  TARG_WriteByte(LVIM, 0x82); /* select reset as action and activate function */
  #endif /* __NEC_V850_Fx3__ && !CPUS_DISABLE_LVI */

  #ifdef __NEC_V850_Fx3__
  CPUS_StopRingOsc8MHz();
  #endif /* __NEC_V850_Fx3__ */

  #ifndef Cpus_DO_NOT_STOP_240KHZ_OSC
  CPUS_StopRingOsc240KHz();
  #endif /* #ifndef Cpus_DO_NOT_STOP_240KHZ_OSC */

  #ifdef Cpus_ACTIVATE_CLOCK_MONITORING
  #ifdef __NEC_V850_Fx3__
  TARG_WriteByte(PRCMD, 1);
  TARG_WriteBit(CLM, CLO_BIT_CLME, 1)  ;
  #endif /* __NEC_V850_Fx3__ */
  #ifdef __NEC_V850_Dx3__
  TARG_WriteByte(PRCMDCMM, 1);
  TARG_WriteBit(CLMM, CLO_BIT_CLMEM, 1)  ;
  #endif /* __NEC_V850_Dx3__ */
  #endif /* Cpus_ACTIVATE_CLOCK_MONITORING */

  /* =======================================================================*/
  /* == Initialisation of programmable peripheral I/O area             =====*/
  /* =======================================================================*/

  /* BPC (peripheral I/O area) */
  /* Peripheral I/O area  BPC  */
  /* V850ES (fixed)     0x8FFB */

  #ifndef __REL_V850_Dx4__
  TARG_WriteShort(BPC, 0x8FFB);
  #endif /* !__REL_V850_Dx4__ */

  /* =======================================================================*/
  /* == Initialisation of On-Chip Debug                               ======*/
  /* =======================================================================*/

  /*------------------------------------------------------------------------*/
  /* Enable/disable on-chip debug capability after reset                    */
  /*                                                                        */
  /* 0x 0 0 0 0 0 0 0 OCDM0                                                 */
  /*                                                                        */
  /* OCDM0 :0 normal operation mode                                         */
  /* OCDM0 :1 normal operation mode/on-chip debug                           */
  /*          /DRST low  -> normal operation mode                           */
  /*          /DRST high -> on-chip debug mode                              */
  /*                                                                        */
  /*------------------------------------------------------------------------*/

  #if defined(__NEC_V850_DJ3__) || defined(__NEC_V850_DL3__)
  /* To be commented out when emulating */
  /*    TARG_WriteByte(OCDM, 0x01); */ /* No OCD on DG3 */
  #endif /* defined(__NEC_V850_DJ3__) || defined(__NEC_V850_DL3__) */

  #ifdef __NEC_V850_Dx3__
  /* Mask all IT                                                  */
  /* Initialise all interrupt level at 3 (middle level)           */
  /* All specific needs will be manage in the init of each module */
  /* NEC V850 DX3 variant */
  #if !defined(__NEC_V850_DG3__)
  TARG_WriteByte(    VC0IC       , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(    VC1IC       , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  #endif /* !defined(__NEC_V850_DG3__) */

  TARG_WriteByte(    WT0UVIC     , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(    WT1UVIC     , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);

  TARG_WriteByte(    TM01IC      , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);

  TARG_WriteByte(    P0IC        , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(    P1IC        , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(    P2IC        , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(    P3IC        , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);

  /* NEC V850 DX3 variant */
  #if !defined(__NEC_V850_DG3__)
  TARG_WriteByte(    P4IC        , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(    P5IC        , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(    P6IC        , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  #endif /* !defined(__NEC_V850_DG3__) */

  TARG_WriteByte(    TZ0UVIC     , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(    TZ1UVIC     , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(    TZ2UVIC     , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(    TZ3UVIC     , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(    TZ4UVIC     , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(    TZ5UVIC     , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);

  TARG_WriteByte(    TP0OVIC     , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(    TP0CCIC0    , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(    TP0CCIC1    , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);

  /* NEC V850 DX3 variant */
  #if !defined(__NEC_V850_DG3__)
  TARG_WriteByte(    TP1OVIC     , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(    TP1CCIC0    , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(    TP1CCIC1    , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(    TP2OVIC     , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(    TP2CCIC0    , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(    TP2CCIC1    , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(    TP3OVIC     , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(    TP3CCIC0    , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(    TP3CCIC1    , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  #endif /* !defined(__NEC_V850_DG3__) */

  TARG_WriteByte(    TG0OV0IC    , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(    TG0OV1IC    , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(    TG0CC0IC    , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(    TG0CC1IC    , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(    TG0CC2IC    , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(    TG0CC3IC    , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(    TG0CC4IC    , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(    TG0CC5IC    , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(    TG1OV0IC    , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(    TG1OV1IC    , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(    TG1CC0IC    , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(    TG1CC1IC    , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(    TG1CC2IC    , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(    TG1CC3IC    , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(    TG1CC4IC    , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(    TG1CC5IC    , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);

  TARG_WriteByte(    ADIC        , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);

  #ifdef Cpus_CanErrItPriority
  TARG_WriteByte(    C0ERRIC     , INT_MSK_xxMKn + Cpus_CanErrItPriority);
  #else
  TARG_WriteByte(    C0ERRIC     , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  #endif
  #ifdef Cpus_CanWakeUpItPriority
  TARG_WriteByte(    C0WUPIC     , INT_MSK_xxMKn + Cpus_CanWakeUpItPriority);
  #else
  TARG_WriteByte(    C0WUPIC     , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  #endif
  #ifdef Cpus_CanRxItPriority
  TARG_WriteByte(    C0RECIC     , INT_MSK_xxMKn + Cpus_CanRxItPriority);
  #else
  TARG_WriteByte(    C0RECIC     , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  #endif
  #ifdef Cpus_CanTxItPriority
  TARG_WriteByte(    C0TRXIC     , INT_MSK_xxMKn + Cpus_CanTxItPriority);
  #else
  TARG_WriteByte(    C0TRXIC     , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  #endif

  TARG_WriteByte(    CB0REIC     , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(    CB0RIC      , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(    CB0TIC      , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);

  TARG_WriteByte(    UA0REIC     , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(    UA0RIC      , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(    UA0TIC      , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(    UA1REIC     , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(    UA1RIC      , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(    UA1TIC      , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);

  TARG_WriteByte(    IIC0IC      , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);

  /* NEC V850 DX3 variant */
  #if !defined(__NEC_V850_DG3__)
  TARG_WriteByte(    IIC1IC      , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  #endif /* !defined(__NEC_V850_DG3__) */

  #ifdef Cpus_SgItPriority
  TARG_WriteByte(    SG0IC       , INT_MSK_xxMKn + Cpus_SgItPriority);
  #else
  TARG_WriteByte(    SG0IC       , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  #endif

  /* NEC V850 DX3 variant */
  #if !defined(__NEC_V850_DG3__)
  TARG_WriteByte(    DMA0IC      , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(    DMA1IC      , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(    DMA2IC      , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(    DMA3IC      , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  #endif /* !defined(__NEC_V850_DG3__) */

  TARG_WriteByte(    INT70IC     , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(    INT71IC     , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);

  /* NEC V850 DX3 variant */
  #if defined(__NEC_V850_DJ3_HE__) || \
      defined(__NEC_V850_DL3__)
  TARG_WriteByte(    P7IC        , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  #endif /* defined(__NEC_V850_DJ3_HE__) ||
            defined(__NEC_V850_DL3__) */

  /* NEC V850 DX3 variant */
  #if !defined(__NEC_V850_DG3__)
  TARG_WriteByte(    C1ERRIC     , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(    C1WUPIC     , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(    C1RECIC     , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(    C1TRXIC     , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  #endif /* !defined(__NEC_V850_DG3__) */

  /* NEC V850 DX3 variant */
  #if defined(__NEC_V850_DJ3_HE__) || \
      defined(__NEC_V850_DL3__)
  TARG_WriteByte(    TZ6UVIC     , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(    TZ7UVIC     , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(    TZ8UVIC     , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(    TZ9UVIC     , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  #endif /* defined(__NEC_V850_DJ3_HE__) ||
            defined(__NEC_V850_DL3__) */

  /* NEC V850 DX3 variant */
  #if !defined(__NEC_V850_DG3__)
  TARG_WriteByte(    TG2OV0IC    , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(    TG2OV1IC    , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(    TG2CC0IC    , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(    TG2CC1IC    , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(    TG2CC2IC    , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(    TG2CC3IC    , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(    TG2CC4IC    , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(   TG2CC5IC     , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  #endif /* !defined(__NEC_V850_DG3__) */

  TARG_WriteByte(    CB1REIC     , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(    CB1RIC      , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(    CB1TIC      , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);

  /* NEC V850 DX3 variant */
  #if defined(__NEC_V850_DJ3_HE__) || \
      defined(__NEC_V850_DL3__)
  TARG_WriteByte(    CB2REIC     , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(    CB2RIC      , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(    CB2TIC      , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  #endif /* defined(__NEC_V850_DJ3_HE__) ||
            defined(__NEC_V850_DL3__) */

  /* NEC V850 DX3 variant */
  #if !defined(__NEC_V850_DG3__)
  TARG_WriteByte(    LCDIC       , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  #endif /* !defined(__NEC_V850_DG3__) */

  #endif /* __NEC_V850_Dx3__    */

  #ifdef __REL_V850_Dx4__
  #ifndef CPU_USE_CUSTOM_ISR_PRIORITY_LEVELS
  /* Mask all IT                                                  */
  /* Initialise all interrupt level at 3 (middle level)           */
  /* All specific needs will be manage in the init of each module */

  TARG_WriteByte( ICWDTA0L       , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICWDTA1L       , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICLVIL         , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICCLMA0L       , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICVCPC0L       , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  #ifdef __REL_V850_DJ4__
  TARG_WriteByte( ICVCPC1L       , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  #endif /* __REL_V850_DJ4__ */
  TARG_WriteByte( ICRTCA01SL     , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICRTCA0ALL     , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICRTCA0RL      , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICP0L          , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICP1L          , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICP2L          , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICP3L          , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICP4L          , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICP5L          , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICP6L          , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICP7L          , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  #ifdef __REL_V850_DJ4__
  TARG_WriteByte( ICP8L          , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICP9L          , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICP10L         , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICTAUA0I0L     , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICTAUA0I1L     , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICTAUA0I2L     , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICTAUA0I3L     , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICTAUA0I4L     , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICTAUA0I5L     , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICTAUA0I6L     , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICTAUA0I7L     , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICTAUA0I8L     , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICTAUA0I9L     , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICTAUA0I10L    , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICTAUA0I11L    , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICTAUA0I12L    , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICTAUA0I13L    , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICTAUA0I14L    , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICTAUA0I15L    , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICTAUA1I0L     , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICTAUA1I1L     , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICTAUA1I2L     , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICTAUA1I3L     , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICTAUA1I4L     , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICTAUA1I5L     , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICTAUA1I6L     , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICTAUA1I7L     , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICTAUA1I8L     , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICTAUA1I9L     , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICTAUA1I10L    , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICTAUA1I11L    , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICTAUA1I12L    , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICTAUA1I13L    , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICTAUA1I14L    , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICTAUA1I15L    , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICTAUA2I0L     , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICTAUA2I1L     , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICTAUA2I2L     , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICTAUA2I3L     , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICTAUA2I4L     , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICTAUA2I5L     , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICTAUA2I6L     , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICTAUA2I7L     , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICTAUA2I8L     , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICTAUA2I9L     , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICTAUA2I10L    , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICTAUA2I11L    , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICTAUA2I12L    , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICTAUA2I13L    , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICTAUA2I14L    , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICTAUA2I15L    , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICTAUA3I0L     , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICTAUA3I1L     , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICTAUA3I2L     , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICTAUA3I3L     , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICTAUA3I4L     , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICTAUA3I5L     , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICTAUA3I6L     , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICTAUA3I7L     , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICTAUA3I8L     , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICTAUA3I9L     , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICTAUA3I10L    , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICTAUA3I11L    , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICTAUA3I12L    , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICTAUA3I13L    , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICTAUA3I14L    , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICTAUA3I15L    , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICTAUA4I0L     , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICTAUA4I1L     , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICTAUA4I2L     , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICTAUA4I3L     , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICTAUA4I4L     , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICTAUA4I5L     , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICTAUA4I6L     , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICTAUA4I7L     , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICTAUA4I8L     , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICTAUA4I9L     , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICTAUA4I10L    , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICTAUA4I11L    , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICTAUA4I12L    , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICTAUA4I13L    , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICTAUA4I14L    , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICTAUA4I15L    , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  #endif /* __REL_V850_DJ4__ */
  TARG_WriteByte( ICADCA0ERRL    , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICADCA0I0L     , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICADCA0I1L     , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICADCA0I2L     , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICADCA0LLTL    , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);

  #ifdef Cpus_CanWakeUpItPriority
  TARG_WriteByte( ICFCNWUPL      , INT_MSK_EIMKn + Cpus_CanWakeUpItPriority);
  #else
  TARG_WriteByte( ICFCNWUPL      , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  #endif

  #ifdef Cpus_CanErrItPriority
  TARG_WriteByte( ICFCN0ERRL     , INT_MSK_EIMKn + Cpus_CanErrItPriority);
  #else
  TARG_WriteByte( ICFCN0ERRL     , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  #endif

  #ifdef Cpus_CanRxItPriority
  TARG_WriteByte( ICFCN0RECL     , INT_MSK_EIMKn + Cpus_CanRxItPriority);
  #else
  TARG_WriteByte( ICFCN0RECL     , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  #endif

  #ifdef Cpus_CanTxItPriority
  TARG_WriteByte( ICFCN0TRXL     , INT_MSK_EIMKn + Cpus_CanTxItPriority);
  #else
  TARG_WriteByte( ICFCN0TRXL     , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  #endif

  TARG_WriteByte( ICCSIG0IREL    , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICCSIG0IRL     , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICCSIG0ICL     , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICUAE0ISL      , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICUAE0IRL      , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICUAE0ITL      , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICUAE1ISL      , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICUAE1IRL      , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICUAE1ITL      , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);

  #ifdef Cpus_SgItPriority
  TARG_WriteByte( ICSG0L         , INT_MSK_EIMKn + Cpus_SgItPriority);
  #else
  TARG_WriteByte( ICSG0L         , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  #endif

  TARG_WriteByte( ICDMA0L        , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICDMA1L        , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICDMA2L        , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICDMA3L        , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICDMA4L        , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICDMA5L        , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICDMA6L        , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICDMA7L        , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICIICB0ISL     , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICIICB0IAL     , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICIICB1ISL     , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICIICB1IAL     , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICFCN1ERRL     , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICFCN1RECL     , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICFCN1TRXL     , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICTAUJ0I0L     , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICTAUJ0I1L     , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICTAUJ0I2L     , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICTAUJ0I3L     , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  #ifdef __REL_V850_DJ4__
  TARG_WriteByte( ICTAUJ1I0L     , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICTAUJ1I1L     , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICTAUJ1I2L     , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICTAUJ1I3L     , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICTAUJ2I0L     , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICTAUJ2I1L     , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICTAUJ2I2L     , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICTAUJ2I3L     , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  #endif /* __REL_V850_DJ4__ */
  TARG_WriteByte( ICOSTM0L       , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICCSIG1IREL    , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICCSIG1IRL     , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICCSIG1ICL     , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  #ifdef __REL_V850_DJ4__
  TARG_WriteByte( ICCSIG2IREL    , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICCSIG2IRL     , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICCSIG2ICL     , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICLCBI0RDYL    , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICLCBI0EMPTL   , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICLCBI0QTRL    , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICLCBI0HALFL   , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICLCBI03QTRL   , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICLCBI0FULLL   , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  #endif /* __REL_V850_DJ4__ */
  TARG_WriteByte( ICFCN2ERRL     , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICFCN2RECL     , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICFCN2TRXL     , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICPCMP0FFILL   , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICPCMP0FERRL   , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICISM0REACHEDL , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICISM0DONEL    , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICISM0ZPDADL   , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICISM0ZPDL     , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICSW0L         , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  #ifndef __REL_V850_DJ4_LE__
  TARG_WriteByte( ICIISA0IAL     , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICIISA0ITXUL   , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICIISA0ITXTL   , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICIISA0IRXOL   , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICIISA0IRXTL   , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICIISA0IFERRL  , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  #endif /* __REL_V850_DJ4_LE__ */
  #ifdef __REL_V850_Dx4H__
  TARG_WriteByte( ICFLX0I0L      , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICFLX0I1L      , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICFLX0I2L      , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICFLX0I3L      , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICHSFI0ERRL    , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICHSFI0TXCL    , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICHSFI0RXCL    , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  #endif /* __REL_V850_Dx4H__ */

  #ifdef __REL_V850_DJ4__
  TARG_WriteByte( ICHSFI1ERRL    , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICHSFI1TXCL    , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICHSFI1RXCL    , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  #endif /* __REL_V850_DJ4__ */

  #ifdef __REL_V850_Dx4H__
  TARG_WriteByte( ICDRW0L        , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICMVO0CH0L     , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICMVO0CH1L     , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICMVO0CH2L     , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICTCON0SYNPO7L , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICTCON0SYNPO11L, INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICVOMN0L       , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICUAE2ISL      , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICUAE2IRL      , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICUAE2ITL      , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICUAE3ISL      , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICUAE3IRL      , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICUAE3ITL      , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICTCON1SYNPO7L , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICTCON1SYNPO11L, INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICVOMN1L       , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICSVO0FUFL     , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICSVO0NBAL     , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICSVO0VCPL     , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICVI0SCLL      , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte( ICVI0FFOL      , INT_MSK_EIMKn + INT_PRIO_LEVEL_3);
  #endif /* __REL_V850_Dx4H__ */
  #endif /* CPU_USE_CUSTOM_ISR_PRIORITY_LEVELS */
  #endif /* __REL_V850_Dx4__ */

  #ifdef __NEC_V850_Fx3__
  TARG_WriteByte(PRCMD, 0x01);
  TARG_WriteByte(OCDM, 0x01);

  /* Mask all IT                                                  */
  /* Initialise all interrupt level at 3 (middle level)           */
  /* All specific needs will be manage in the init of each module */

  TARG_WriteByte(  LVILIC    , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(  LVIHIC    , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(  PIC0      , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(  PIC1      , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(  PIC2      , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(  PIC3      , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(  PIC4      , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(  PIC5      , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(  PIC6      , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(  PIC7      , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(  TAB0OVIC  , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(  TAB0CCIC0 , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(  TAB0CCIC1 , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(  TAB0CCIC2 , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(  TAB0CCIC3 , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(  TAA0OVIC  , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(  TAA0CCIC0 , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(  TAA0CCIC1 , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(  TAA1OVIC  , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(  TAA1CCIC0 , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(  TAA1CCIC1 , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(  TAA2OVIC  , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(  TAA2CCIC0 , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(  TAA2CCIC1 , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(  TAA3OVIC  , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(  TAA3CCIC0 , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(  TAA3CCIC1 , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(  TAA4OVIC  , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(  TAA4CCIC0 , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(  TAA4CCIC1 , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(  TM0EQIC0  , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(  CB0RIC    , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(  CB0TIC    , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(  CB1RIC    , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(  CB1TIC    , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(  UD0SIC    , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(  UD0RIC    , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(  UD0TIC    , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(  UD1SIC    , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(  UD1RIC    , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(  UD1TIC    , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(  IIC0IC    , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(  ADIC      , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  #ifdef Cpus_CanErrItPriority
  TARG_WriteByte(  C0ERRIC   , INT_MSK_xxMKn + Cpus_CanErrItPriority);
  #else
  TARG_WriteByte(  C0ERRIC   , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  #endif
  #ifdef Cpus_CanWakeUpItPriority
  TARG_WriteByte(  C0WUPIC   , INT_MSK_xxMKn + Cpus_CanWakeUpItPriority);
  #else
  TARG_WriteByte(  C0WUPIC   , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  #endif
  #ifdef Cpus_CanRxItPriority
  TARG_WriteByte(  C0RECIC   , INT_MSK_xxMKn + Cpus_CanRxItPriority);
  #else
  TARG_WriteByte(  C0RECIC   , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  #endif
  #ifdef Cpus_CanTxItPriority
  TARG_WriteByte(  C0TRXIC   , INT_MSK_xxMKn + Cpus_CanTxItPriority);
  #else
  TARG_WriteByte(  C0TRXIC   , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  #endif
  TARG_WriteByte(  DMAIC0    , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(  DMAIC1    , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(  DMAIC2    , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(  DMAIC3    , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(  KRIC      , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(  WTIIC     , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(  WTIC      , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(  ECCDIC    , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(  FLIC      , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);

  #if defined(__NEC_V850_FG3__) || \
      defined(__NEC_V850_FJ3__) || \
      defined(__NEC_V850_FK3__)
  TARG_WriteByte(  PIC8      , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(  PIC9      , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(  PIC10     , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(  TAB1OVIC  , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(  TAB1CCIC0 , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(  TAB1CCIC1 , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(  TAB1CCIC2 , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(  TAB1CCIC3 , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(  UD2SIC    , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(  UD2RIC    , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(  UD2TIC    , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(  C1ERRIC   , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(  C1WUPIC   , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(  C1RECIC   , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(  C1TRXIC   , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  #endif /* defined(__NEC_V850_FG3__) || \
            defined(__NEC_V850_FJ3__) || \
            defined(__NEC_V850_FK3__) */

  #if (defined(__NEC_V850_FG3__) &&  defined(__NEC_V850_FG3_F3376__)) || \
      (defined(__NEC_V850_FG3__) &&  defined(__NEC_V850_FG3_F3377__)) || \
      (defined(__NEC_V850_FJ3__) && !defined(__NEC_V850_FJ3_F3378__)) || \
       defined(__NEC_V850_FK3__)
  TARG_WriteByte(  PIC14     , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  #endif /* defined(__NEC_V850_FG3_F3376__) || \
            defined(__NEC_V850_FG3_F3377__) || \
            defined(__NEC_V850_FK3__)           */

  #if (defined(__NEC_V850_FJ3__) || defined(__NEC_V850_FK3__))
  TARG_WriteByte(  PIC11     , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(  PIC12     , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(  PIC13     , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(  TAB2OVIC  , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(  TAB2CCIC0 , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(  TAB2CCIC1 , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(  TAB2CCIC2 , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(  TAB2CCIC3 , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(  CB2RIC    , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(  CB2TIC    , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(  C2ERRIC   , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(  C2WUPIC   , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(  C2RECIC   , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(  C2TRXIC   , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  #endif /* defined(__NEC_V850_FJ3__) &&
            defined(__NEC_V850_FK3__) */

  #if defined(__NEC_V850_FG3_F3376__) || \
      defined(__NEC_V850_FG3_F3377__) || \
     (defined(__NEC_V850_FJ3__) && !defined(__NEC_V850_FJ3_F3378__)) || \
      defined(__NEC_V850_FK3__)
  TARG_WriteByte(  UD3SIC    , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(  UD3RIC    , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(  UD3TIC    , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(  UD4RIC    , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(  UD4TIC    , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(  UD4SIC    , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  #endif /* defined(__NEC_V850_FG3_F3376__) || \
            defined(__NEC_V850_FG3_F3377__) || \
           (defined(__NEC_V850_FJ3__) && !defined(__NEC_V850_FJ3_F3378__)) || \
            defined(__NEC_V850_FK3_F3380__) */

  #if (defined(__NEC_V850_FJ3__) && !defined(__NEC_V850_FJ3_F3378__)) || \
       defined(__NEC_V850_FK3__)
  TARG_WriteByte(  UD5SIC    , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(  UD5RIC    , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(  UD5TIC    , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(  C3ERRIC   , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(  C3WUPIC   , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(  C3RECIC   , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(  C3TRXIC   , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  #endif /* (defined(__NEC_V850_FJ3__) && !defined(__NEC_V850_FJ3_F3378__)) || \
            defined(__NEC_V850_FK3_F3380__) */

  #if defined(__NEC_V850_FJ3_F3381__) || \
      defined(__NEC_V850_FJ3_F3382__) || \
      defined(__NEC_V850_FK3__)
  TARG_WriteByte(  CB3RIC    , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  TARG_WriteByte(  CB3TIC    , INT_MSK_xxMKn + INT_PRIO_LEVEL_3);
  #endif /* defined(__NEC_V850_FJ3_F3381__) || \
            defined(__NEC_V850_FJ3_F3382__) || \
            defined(__NEC_V850_FK3__) */

#endif /*__NEC_V850_Fx3__*/

  __NOP__;
  __NOP__;
  __NOP__;
  __NOP__;
  __NOP__;

  /* NEC V850 DX3 variant */
  #if defined(__NEC_V850_Dx3__)
  /* Enable standby function of voltage regulators for power reduction      */
  /* during power save modes                                                */
  /* voltage regulators: VDD50, VDD51, VDD52 see power supply scheme        */
  /* If dedicated uC does not include the voltage regulators, the status of */
  /* control bit STBYMD and STBYCD has no function                          */
  /**************************************************************************/
  TARG_WriteByte(STBCTLP, CLO_MSK_STBYMD + CLO_MSK_STBYCD);
  TARG_WriteByte(STBCTL, CLO_MSK_STBYMD + CLO_MSK_STBYCD);
  #endif /* __NEC_V850_Dx3__    */
}
#endif /*  __NEC_V850__ */

/*----------------------------------------------------------------------------*/


#if defined(__FSL_IMX53x__) || defined(__FSL_IMX6x__)

#if !defined(__GHOS__)

#ifdef Cpus_DEBUG_CLOCKS_AND_PLLS
/*----------------------------------------------------------------------------*/
/* Name : CPUS_DebugPLLs                                                      */
/* Role : Function used during debug to check PLLs and clocks configuration.  */
/* Interface : -                                                              */
/* Pre-condition : Dividers and clocks to output on clko1 and clko2 must have */
/*                 been configured in cpus_config.h                           */
/* Constraints : PLLs and clocks must be initialised by DCD in the IVT.       */
/* Behavior :                                                                 */
/*  DO                                                                        */
/*    [Enable and configured clko1 and clko2]                                 */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
__INLINE__ void CPUS_DebugPLLs(void)
{
  /* Select the clock to be generated on CKO1 and CKO2 */
  TARG_WriteField(CCM_CCOSR, CCM_FIELD_CKO1_SEL, Cpus_CKO1_SEL);
  TARG_WriteField(CCM_CCOSR, CCM_FIELD_CKO2_SEL, Cpus_CKO2_SEL);

  /* Setting the divider of CKO1 and CKO2 */
  TARG_WriteField(CCM_CCOSR, CCM_FIELD_CKO1_DIV, Cpus_CKO1_DIV);
  TARG_WriteField(CCM_CCOSR, CCM_FIELD_CKO2_DIV, Cpus_CKO2_DIV);

  /* Enable CKO1 and CKO2 */
  TARG_WriteBit(CCM_CCOSR, CCM_BIT_CKO1_EN, 1);
  TARG_WriteBit(CCM_CCOSR, CCM_BIT_CKO2_EN, 1);
}
#endif /* Cpus_DEBUG_CLOCKS_AND_PLLS */


/*----------------------------------------------------------------------------*/
/* Name : CPUS_StopPll                                                        */
/* Role :                                                                     */
/* Interface : -                                                              */
/* Pre-condition : -                                                          */
/* Constraints : -                                                            */
/* Behavior : -                                                               */
/*----------------------------------------------------------------------------*/
#define CPUS_StopPll()


/*----------------------------------------------------------------------------*/
/* Name : CPUS_SetCpu                                                         */
/* Role : Initialise CPU                                                      */
/* Interface : -                                                              */
/* Pre-condition : -                                                          */
/* Constraints : -                                                            */
/* Behavior :                                                                 */
/*  DO                                                                        */
/*       [Start Watchdog]                                                     */
/*       [Configure IOMUX]                                                    */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
__INLINE__ void CPUS_SetCpu(void)
{
  #ifdef Cpus_DEBUG_CLOCKS_AND_PLLS
  CPUS_DebugPLLs();
  #endif /* Cpus_DEBUG_CLOCKS_AND_PLLS */

  CPUS_StartPll();

  /* Watchdog must be started after PLLs */
  WDTD_Init();
  WDTD_Start();

  CPUS_ConfigIomux();
}

#endif /* !defined(__GHOS__) */

#endif /* __FSL_IMX53x__ __FSL_IMX6x__, */

/*----------------------------------------------------------------------------*/

#if defined(C_COMP_GHS_TX49)    \
    || defined(C_COMP_GHS_V850) \
    || defined(C_COMP_GHS_ARM)
#pragma ghs endnowarning
#endif /* C_COMP_GHS_TX49 || C_COMP_GHS_V850 || C_COMP_GHS_ARM */




#ifdef __REL_RL78__

#ifdef __REL_RL78_D1x__
#ifdef __REL_RL78_D1A__
/*----------------------------------------------------------------------------*/
/* Name : CPUS_StopPll                                                        */
/* Role : Stop the PLL                                                        */
/* Interface : -                                                              */
/* Pre-condition : -                                                          */
/* Constraints : -                                                            */
/* Behavior : -                                                               */
/*----------------------------------------------------------------------------*/
#define CPUS_StopPll()


/*----------------------------------------------------------------------------*/
/* Name : CPUS_StartPll                                                       */
/* Role : Start the PLL                                                       */
/* Interface : -                                                              */
/* Pre-condition : -                                                          */
/* Constraints : Must be a macro and not a function because stack pointer is  */
/*               not set when this service is used.                           */
/* Behavior :                                                                 */
/*  DO                                                                        */
/*    [Set PLL On]                                                            */
/*    [wait for stabilization]                                                */
/*    [Set clock to be derived from PLL clock]                                */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#ifdef CPUS_USE_PLL_FUNCTION
#ifndef __POLYSPACE__
#pragma inline=forced
void CPUS_StartPll(void)
#else
inline void CPUS_StartPll(void)
#endif /* __POLYSPACE__ */
{
  /* enable PLL */
  TARG_WriteByte(PLLCTL,0x91);

  /* Wait for stabilisation time to continue */
  while(TARG_ReadByte(PLLSTS) != 0x80);

  /* select PLL mode */
  TARG_WriteByte(PLLCTL,0x95);

  /* wait select PLL mode OK */
  while(TARG_ReadByte(PLLSTS) != 0x88);

  /* set main clock, which is divided by PLL output(32MHz) */
  TARG_WriteByte(MDIV,CPUS_CPU_CLOCK);
}
#else
#define CPUS_StartPll()
#endif /* CPUS_USE_PLL_FUNCTION */


/*----------------------------------------------------------------------------*/
/*Name : CPUS_SetCpu                                                          */
/*Role : Initialize CPU                                                       */
/*Interface : -                                                               */
/*Pre-condition : -                                                           */
/*Constraints : -                                                             */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [set map registers]                                                     */
/*    [set clock registers]                                                   */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#ifndef __POLYSPACE__
#pragma inline=forced
void CPUS_SetCpu(void)
#else
inline void CPUS_SetCpu(void)
#endif /* __POLYSPACE__ */
{
  /* disable RAM Parity Error resets */
  RPECTL |= 0x80;

  /*At start, we must wait for oscilator stabilisation. */
  TARG_WriteByte(OSTS,CPUS_OSCILATOR_STAB_TIME);
  #ifdef CPUS_SUB_OSC_USED
  TARG_WriteByte(CMC, 0x50); /* Set X1&X2 to OSC mode, XT1&XT2 to SUB OSC mode */
  TARG_WriteByte(CSC, 0x00); /* Enable X1 and SUB OSC, internal high-speed OSC default enable */
  #else
  TARG_WriteByte(CMC, 0x40); /* Set X1&X2 to OSC mode, XT1&XT2 to INPUT mode */
  TARG_WriteByte(CSC, 0x40); /* Enable X1, Disable SUB OSC, internal high-speed OSC default enable */
  #endif /* CPUS_SUB_OSC_USED */

  /* wait for stabilisation time to continue */
  while(TARG_ReadByte(OSTC) < CPUS_OSCILATOR_STAB_TIME_CHECK);

  /* init internal watchdog */
  WDTD_Init();
  /* start internal watchdog */
  WDTD_Start();

  /* switch from ring oscilator to external oscilator */
  TARG_WriteByte(CKC,0x10);
  while(TARG_ReadByte(CKC) != 0x30);

#ifdef CPUS_USE_PLL_FUNCTION
  CPUS_StartPll();
#endif /* CPUS_USE_PLL_FUNCTION */

  #if defined(CPUS_RING_OSC_CAN_BE_STOPPED)
  /* stop Ring oscilator */
  TARG_WriteBit(CSC,CKS_BIT_HIOSTOP,1);
  #endif /* CPUS_RING_OSC_CAN_BE_STOPPED */

  #if defined(CPUS_CAN_MODULE_NEED_TO_BE_STOPPED)
  /*SET CAN MODULE TO STOP MODE*/
  TARG_WriteShort(C0CTRL,0x0810);
  while (0 == (TARG_ReadShort(C0CTRL)& 0x0008));
  TARG_WriteShort(C0CTRL,0x1800);
  while (0x0018 != (TARG_ReadShort(C0CTRL)& 0x0018));
  #endif /* CPUS_CAN_MODULE_NEED_TO_BE_STOPPED */
}

/*----------------------------------------------------------------------------*/
/*Name : CPUS_SelectSubOscillator                                             */
/*Role : Selecting the subsystem clock                                        */
/*Interface : -                                                               */
/*Pre-condition : -                                                           */
/*Constraints : -                                                             */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [Select subsystem clock]                                                */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
extern void CPUS_SelectSubOscillator(void);

/*----------------------------------------------------------------------------*/
/*Name : CPUS_SelectHighSpeedOscillator                                       */
/*Role : Selects the high-speed on-chip oscillator clock                      */
/*       as the main system clock                                             */
/*Interface : -                                                               */
/*Pre-condition : -                                                           */
/*Constraints : -                                                             */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [Select the high-speed on-chip oscillator clock]                        */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
extern void CPUS_SelectHighSpeedOscillator(void);

/*----------------------------------------------------------------------------*/
/*Name : CPUS_StopHighSpeedOscillator                                         */
/*Role : Stops the operation of the high-speed on-chip oscillator clock       */
/*Interface : -                                                               */
/*Pre-condition : -                                                           */
/*Constraints : -                                                             */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [Stop the high-speed on-chip oscillator clock]                          */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
extern void CPUS_StopHighSpeedOscillator(void);

/*----------------------------------------------------------------------------*/
/*Name : CPUS_StartHighSpeedOscillator                                        */
/*Role : Starts the operation of the high-speed on-chip oscillator clock      */
/*Interface : -                                                               */
/*Pre-condition : -                                                           */
/*Constraints : -                                                             */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [Start the high-speed on-chip oscillator clock]                         */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
extern void CPUS_StartHighSpeedOscillator(void);


#endif /* __REL_RL78_D1A__ */
#endif /* __REL_RL78_D1x__ */


#ifdef __REL_RL78_F1x__
#ifdef __REL_RL78_F12__
/*----------------------------------------------------------------------------*/
/* Name : CPUS_StopPll                                                        */
/* Role : Stop the PLL                                                        */
/* Interface : -                                                              */
/* Pre-condition : -                                                          */
/* Constraints : -                                                            */
/* Behavior : -                                                               */
/*----------------------------------------------------------------------------*/
#define CPUS_StopPll()


/*----------------------------------------------------------------------------*/
/* Name : CPUS_StartPll                                                       */
/* Role : Start the PLL                                                       */
/* Interface : -                                                              */
/* Pre-condition : -                                                          */
/* Constraints : -                                                            */
/* Behavior : -                                                               */
/*----------------------------------------------------------------------------*/
#define CPUS_StartPll()


/*----------------------------------------------------------------------------*/
/*Name : CPUS_SetCpu                                                          */
/*Role : Initialize CPU                                                       */
/*Interface : -                                                               */
/*Pre-condition : -                                                           */
/*Constraints : -                                                             */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [set map registers]                                                     */
/*    [set clock registers]                                                   */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#ifndef __POLYSPACE__
#pragma inline=forced
void CPUS_SetCpu(void)
#else
inline void CPUS_SetCpu(void)
#endif /* __POLYSPACE__ */
{
  /* disable RAM Parity Error resets */
  TARG_WriteByte(RPECTL,TARG_ReadByte(RPECTL)|0x80);

  #ifndef CPUS_RING_OSC_USED
  /*At start, we must wait for oscilator stabilisation. */
  TARG_WriteByte(OSTS,CPUS_OSCILATOR_STAB_TIME);

  #ifdef CPUS_SUB_OSC_USED
  #ifdef EXT_OSC_0_TO_10_MHZ
  TARG_WriteByte(CMC, 0x50); /* Set X1&X2 to OSC mode, XT1&XT2 to SUB OSC mode */
  #else
  TARG_WriteByte(CMC, 0x51); /* Set X1&X2 to OSC mode, XT1&XT2 to SUB OSC mode */
  #endif /* EXT_OSC_0_TO_10_MHZ */
  TARG_WriteByte(CSC, 0x00); /* Enable X1 and SUB OSC, internal high-speed OSC default enable */
  #else
  #ifdef EXT_OSC_0_TO_10_MHZ
  TARG_WriteByte(CMC, 0x40); /* Set X1&X2 to OSC mode, XT1&XT2 to INPUT mode */
  #else
  TARG_WriteByte(CMC, 0x41); /* Set X1&X2 to OSC mode, XT1&XT2 to INPUT mode */
  #endif /* EXT_OSC_0_TO_10_MHZ */
  TARG_WriteByte(CSC, 0x40); /* Enable X1, Disable SUB OSC, internal high-speed OSC default enable */
  #endif /* CPUS_SUB_OSC_USED */

  /* wait for stabilisation time to continue */
  while(TARG_ReadByte(OSTC) < CPUS_OSCILATOR_STAB_TIME_CHECK);
  #endif /* CPUS_RING_OSC_USED */

  /* init internal watchdog */
  WDTD_Init();
  /* start internal watchdog */
  WDTD_Start();

  #ifndef CPUS_RING_OSC_USED
  /* switch from ring oscilator to external oscilator */
  TARG_WriteByte(CKC,0x10);
  while(TARG_ReadByte(CKC) != 0x30);
  #endif /* CPUS_RING_OSC_USED */

  #ifndef CPUS_RING_OSC_USED
  #if defined(CPUS_RING_OSC_CAN_BE_STOPPED)
  /* stop Ring oscilator */
  TARG_WriteBit(CSC,CKS_BIT_HIOSTOP,1);
  #endif /* CPUS_RING_OSC_CAN_BE_STOPPED */
  #endif /* CPUS_RING_OSC_USED */
}

 /*----------------------------------------------------------------------------*/
/*Name : CPUS_SelectSubOscillator                                             */
/*Role : Selecting the subsystem clock                                        */
/*Interface : -                                                               */
/*Pre-condition : -                                                           */
/*Constraints : -                                                             */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [Select subsystem clock]                                                */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
 extern void CPUS_SelectSubOscillator(void);

/*----------------------------------------------------------------------------*/
/*Name : CPUS_SelectHighSpeedOscillator                                       */
/*Role : Selects the high-speed on-chip oscillator clock                      */
/*       as the main system clock                                             */
/*Interface : -                                                               */
/*Pre-condition : -                                                           */
/*Constraints : -                                                             */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [Select the high-speed on-chip oscillator clock]                        */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
 extern void CPUS_SelectHighSpeedOscillator(void);

/*----------------------------------------------------------------------------*/
/*Name : CPUS_StopHighSpeedOscillator                                         */
/*Role : Stops the operation of the high-speed on-chip oscillator clock       */
/*Interface : -                                                               */
/*Pre-condition : -                                                           */
/*Constraints : -                                                             */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [Stop the high-speed on-chip oscillator clock]                          */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
 extern void CPUS_StopHighSpeedOscillator(void);

/*----------------------------------------------------------------------------*/
/*Name : CPUS_StartHighSpeedOscillator                                        */
/*Role : Starts the operation of the high-speed on-chip oscillator clock      */
/*Interface : -                                                               */
/*Pre-condition : -                                                           */
/*Constraints : -                                                             */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [Start the high-speed on-chip oscillator clock]                         */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
 extern void CPUS_StartHighSpeedOscillator(void);

#endif /* __REL_RL78_F12__ */
#endif /* __REL_RL78_F1x__ */

#endif /*__REL_RL78__*/

/*----------------------------------------------------------------------------*/

/*______ G L O B A L - F U N C T I O N S - P R O T O T Y P E S _______________*/

#if defined(__MC9S08xx__)
#if defined(__MC9S08AWxx__)
/*----------------------------------------------------------------------------*/
/* Name : CPUS_Icg_it                                                         */
/* Role : Manage the ICG interrupt                                            */
/* Interface : -                                                              */
/* Pre-condition : -                                                          */
/* Constraints : -                                                            */
/* Behavior:                                                                  */
/*   DO                                                                       */
/*    [ Acknowledge the interrupt ]                                           */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/
ISR(CPUS_Icg_it);
#endif /* (__MC9S08AWxx__) */
#endif /* (__MC9S08xx__) */

#ifdef __debug__
#ifdef __NEC_V850_Dx3__
/*----------------------------------------------------------------------------*/
/* Name : CPUS_TestClockGenerator                                             */
/* Role : Output the OSC, SSCG or PLL clock to a pin to test it.              */
/*        (Output frequency is divided by 16)                                 */
/* Interface :  IN  : ubyte clock : OSC, SSCG, PLL                            */
/*              IN :  CPUS_FoutPin_t foutPin : PIN65 or PIN28                 */
/* Pre-condition : -                                                          */
/* Constraints : -                                                            */
/* Behavior:                                                                  */
/*   DO                                                                       */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/
extern void CPUS_TestClockGenerator( ubyte clock, CPUS_FoutPin_t foutPin );
#endif /* __NEC_V850_Dx3__ */
#endif /*__debug__*/

#endif /* CPUS_H */


/*______ E N D _____ (cpus.h) ________________________________________________*/
