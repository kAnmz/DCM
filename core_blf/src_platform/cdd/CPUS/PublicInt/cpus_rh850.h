/******************************************************************************/
/*@F_NAME:          cpus_rh850.h                                              */
/*@F_PURPOSE:       Public interface for processor core set-up                */
/*@F_CREATED_BY:    shubin liang                                              */
/*@F_CREATION_DATE: 03/08/2017                                                */
/*@F_MPROC_TYPE:    RH850 f1x                                                 */
/************************************** (C) Copyright 2017 Magneti Marelli ****/

#ifndef CPUS_RH850_H
#define CPUS_RH850_H

/*______ I N C L U D E - F I L E S ___________________________________________*/

#include "syst.h"

#ifdef __RH850__
#include "cpus_config_rh850.h"
#endif

/*______ G L O B A L - D E F I N E S _________________________________________*/
#ifdef __BOOT_LINK__
#define  CPUS_SOBOSC_USED      FALSE
#else
#ifndef  CPUS_SOBOSC_NOT_USED
#define  CPUS_SOBOSC_USED    VERS_StartUsedSosc()
#else
#define  CPUS_SOBOSC_USED    FALSE
#endif
#endif
/*______ G L O B A L - T Y P E S _____________________________________________*/


/*______ G L O B A L - D A T A _______________________________________________*/


/*______ G L O B A L - M A C R O S ___________________________________________*/


/*______ G L O B A L - F U N C T I O N S - P R O T O T Y P E S _______________*/

#ifdef __RH850__
#ifdef __RH850_F1x__

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
#define Cpus_SetClockDivider(ProtReg, ClockDomain, Value)        \
  TARG_ProtWriteLong(ProtReg, CKSC_##ClockDomain##D_CTL, (Value));  \
  while ( TARG_ReadLong(CKSC_##ClockDomain##D_ACT) != (Value))       \
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
    TARG_ProtWriteLong(ProtReg, CKSC_##ClockDomain##S_CTL, (Value));  \
    while (TARG_ReadLong(CKSC_##ClockDomain##S_ACT) != (Value))   \
    {                   \
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
extern void CPUS_StartClockTree(void);

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
extern void CPUS_StartClockTreeFromSleep(void);

/*----------------------------------------------------------------------------*/
/* Name : CPUS_ClockSelectorConfig                                            */
/* Role : Set clocks selector for each supported clock domain                 */
/* Interface : -                                                              */
/* Pre-condition : -                                                          */
/* Constraints :                                                              */
/*----------------------------------------------------------------------------*/
extern void CPUS_ClockSelectorConfig(void);

/*----------------------------------------------------------------------------*/
/* Name : CPUS_ClockSelectorConfigFromSleep                                   */
/* Role : Set clocks selector for each supported clock domain                 */
/*        coming from sleep                                                   */
/* Interface : -                                                              */
/* Pre-condition : -                                                          */
/* Constraints :                                                              */
/*----------------------------------------------------------------------------*/
extern void CPUS_ClockSelectorConfigFromSleep(void);

/*----------------------------------------------------------------------------*/
/* Name : CPUS_PrepareClockSelectorBeforeSleep                                */
/* Role : prepare the Clock tree before enter sleep mode                      */
/* Interface : -                                                              */
/* Pre-condition : INT disabled                                               */
/* Constraints :                                                              */
/* Behavior :                                                                 */
/*  DO                                                                        */
/*    [set clock for the module need to work before re-init whole clock tree] */
/*    [set PLLs ]                                                             */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
extern void CPUS_PrepareClockSelectorBeforeSleep(void);

/*----------------------------------------------------------------------------*/
/* Name : CPUS_StopPll                                                       */
/* Role : to stop PLL                                                        */
/* Interface : -                                                              */
/* Pre-condition : PLL is enabled                                            */
/* Constraints :                                                              */
/* Behavior :                                                                 */
/*  DO                                                                        */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
extern void CPUS_StopPll(void);

/*----------------------------------------------------------------------------*/
/* Name : CPUS_CpuClkSwitchToEmclk                                            */
/* Role : Switch CPU clk to Emclk                                             */
/* Interface : -                                                              */
/* Pre-condition : PLL is enabled                                             */
/* Constraints :                                                              */
/* Behavior :                                                                 */
/*  DO                                                                        */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
extern void CPUS_CpuClkSwitchToEmclk(void);

extern bool_t CPUS_GetEnSubOscTimeoutFlag(void);
#endif /*__RH850_F1x__*/
#endif /*__RH850__*/

#endif /* CPUS_RH850_H */


/*______ E N D _____ (cpus_rh850.h) ________________________________________________*/
