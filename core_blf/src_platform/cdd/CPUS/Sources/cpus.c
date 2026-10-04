/******************************************************************************/
/* @F_NAME :          cpus.c                                                  */
/* @F_PURPOSE :       Processor core set up                                   */
/* @F_CREATED_BY :    S.BOUGUYON                                              */
/* @F_CREATION_DATE : 31/03/2004                                              */
/* @F_LANGUAGE :      C                                                       */
/* @F_MPROC_TYPE:     MC9S08xx , V850 Dx3, Renesas RL78                       */
/*************************************** (C) Copyright 2013 Magneti Marelli ***/

/* _____ I N C L U D E - F I L E S ___________________________________________*/

#include "syst.h"
#include "cpus.h"
#if defined(__MC9S08xx__)
#include "wdtd.h"
#endif

/* _____ L O C A L - D E F I N E _____________________________________________*/


/* _____ L O C A L - T Y P E S _______________________________________________*/


/* _____ G L O B A L - D A T A _______________________________________________*/


/* _____ L O C A L - D A T A _________________________________________________*/


/* _____ L O C A L - M A C R O S _____________________________________________*/


/* _____ L O C A L - F U N C T I O N S - P R O T O T Y P E S _________________*/


/* _____ G L O B A L - F U N C T I O N S _____________________________________*/

#if defined(__MC9S08xx__)
#if defined(__MC9S08AWxx__)
/******************************************************************************/
/* Name : CPUS_Icg_it                                                         */
/* Role : Manage the ICG interrupt                                            */
/* Interface : -                                                              */
/* Pre-condition : -                                                          */
/* Constraints : -                                                            */
/* Behavior:                                                                  */
/*   DO                                                                       */
/*    [ Acknowledge the interrupt ]                                           */
/*   OD                                                                       */
/******************************************************************************/
ISR(CPUS_Icg_it)
{
  static ubyte IcgS1Register;

  #ifdef __TASK_DURATION_MEASUREMENT_WITH_TIMER__
  ubyte OldMeasuredTask;

  RTOS_DisableAllInterrupts();
  OldMeasuredTask = RTOS_MeasuredTask;
  RTOS_TaskMeasurementEnterIt(OldMeasuredTask);
  RTOS_EnableAllInterrupts();
  #endif /* __TASK_DURATION_MEASUREMENT_WITH_TIMER__ */

  IcgS1Register = TARG_ReadByte(ICGS1);
  TARG_WriteByte(ICGS1,ICGS1_MSK_ICGIF);

  #ifdef __TASK_DURATION_MEASUREMENT_WITH_TIMER__
  RTOS_DisableAllInterrupts();
  RTOS_TaskMeasurementLeaveIt(OldMeasuredTask);
  RTOS_EnableAllInterrupts();
  #endif /* __TASK_DURATION_MEASUREMENT_WITH_TIMER__ */

}
#endif /* (__MC9S08AWxx__) */
#endif /* (__MC9S08xx__) */


#ifdef __debug__
#ifdef __NEC_V850_Dx3__
/*----------------------------------------------------------------------------*/
/* Name : CPUS_TestClockGenerator                                             */
/* Role : Output the OSC, SSCG or PLL clock to a pin to test it.              */
/*        (Output frequency is divided by 16)                                 */
/* Interface :  IN  : ubyte clock : OSC, SSCG, PLL                            */
/*              IN :  CPUS_FoutPin_t foutPin : P85 or P50                     */
/* Pre-condition : -                                                          */
/* Constraints : -                                                            */
/* Behavior:                                                                  */
/*   DO                                                                       */
/*     IF [ Pin == P85 ]                                                      */
/*       [ Configure Port 8 Bit 5 for Fout ]                                  */
/*     ELSE                                                                   */
/*       [ Configure Port 5 Bit 0 for Fout ]                                  */
/*     FI                                                                     */
/*                                                                            */
/*     [ Configure FCC (Fout clock) ]                                         */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/
void CPUS_TestClockGenerator( ubyte clock, CPUS_FoutPin_t foutPin )
{
  ubyte Mask;

  if (foutPin == CPUS_FOUT_P85)
  {
    /* Use Port 8.5 to be connected to FOUT */
    TARG_WriteBit(PMC8, BIT5, 1);
    TARG_WriteBit(PM8, BIT5, 0);
    TARG_WriteBit(PFC8, BIT5, 0);
  }
  else
  {
    /* Use Port 5.0 to be connected to FOUT */
    TARG_WriteBit(PMC5, BIT0, 1);
    TARG_WriteBit(PM5, BIT0, 0);
    TARG_WriteBit(PFC5, BIT0, 0);
  }

  Mask = TARG_ReadByte(FCC);

  /* Divide by 16 the frequence (FOCS2) and select the clock to be output */
  switch (clock)
  {
    case Cpus_OSC : /*_______________________________________________________*/
      Mask = CLO_MSK_FOEN | CLO_MSK_FOCS2;
      break;

    case Cpus_SSCG : /*______________________________________________________*/
      Mask = CLO_MSK_FOEN | CLO_MSK_FOCS2 | CLO_MSK_FOCKS0;
      break;

    case Cpus_PLL : /*_______________________________________________________*/
      Mask = CLO_MSK_FOEN | CLO_MSK_FOCS2 | CLO_MSK_FOCKS1;
      break;

    default :
      break;
  }

  if (TARG_ReadByte(FCC) != Mask)
  {
    do
    {
      TARG_WriteByte(PHS, 0);
      /* Write access to security register first */
      TARG_WriteByte(PHCMD, CLO_MSK_FOEN | CLO_MSK_FOCS2 | CLO_MSK_FOCKS0 | CLO_MSK_FOCKS1);

      TARG_WriteByte(FCC, Mask);
    } while (TARG_ReadByte(PHS) != 0);
  }
}
#endif /*__NEC_V850_Dx3__ */
#endif /*__debug__*/

/******************************************************************************/
/***************************** RENESAS RL78 CODE ******************************/
/******************************************************************************/

#ifdef __REL_RL78__

#ifdef __REL_RL78_D1x__
#ifdef __REL_RL78_D1A__

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
void CPUS_SelectSubOscillator(void)
{
TARG_SetBits(CKC, CKS_MSK_CSS);
}

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
void CPUS_SelectHighSpeedOscillator(void)
{
/* Check whether main system clock is selected or not */
if (TARG_ReadBit(CKC, CKS_BIT_CSS) != 1) 
  TARG_ClearBits(CKC, CKS_MSK_MCM0);
}

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
void CPUS_StopHighSpeedOscillator(void)
{
/* Check whether peripheral hardware clocks operate with a clock other than   */
/* the high-speed on-chip oscillator clock                                    */

if (((CKS_MSK_CLS | CKS_MSK_MCS) & (TARG_ReadByte(CKC))) != 0) 
  TARG_SetBits(CSC, CKS_MSK_HIOSTOP);
}

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
void CPUS_StartHighSpeedOscillator(void)
{
  TARG_ClearBits(CSC, CKS_MSK_HIOSTOP);
}


#endif /* __REL_RL78_D1A__ */
#endif /* __REL_RL78_D1x__ */

#ifdef __REL_RL78_F1x__
#ifdef __REL_RL78_F12__

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
void CPUS_SelectSubOscillator(void)
{
TARG_SetBits(CKC, CKS_MSK_CSS);
}

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
void CPUS_SelectHighSpeedOscillator(void)
{
/* Check whether main system clock is selected or not */
if (TARG_ReadBit(CKC, CKS_BIT_CSS) != 1) 
  TARG_ClearBits(CKC, CKS_MSK_MCM0);
}

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
void CPUS_StopHighSpeedOscillator(void)
{
/* Check whether peripheral hardware clocks operate with a clock other than   */
/* the high-speed on-chip oscillator clock                                    */

if (((CKS_MSK_CLS | CKS_MSK_MCS) & (TARG_ReadByte(CKC))) != 0) 
TARG_SetBits(CSC, CKS_MSK_HIOSTOP);
}

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
void CPUS_StartHighSpeedOscillator(void)
{
  TARG_ClearBits(CSC, CKS_MSK_HIOSTOP);
}


#endif /* __REL_RL78_F1A__ */
#endif /* __REL_RL78_F12__ */

#endif /* __REL_RL78__ */
/* _____ L O C A L - F U N C T I O N S _______________________________________*/


/*______ E N D _____ (cpus.c) ________________________________________________*/
