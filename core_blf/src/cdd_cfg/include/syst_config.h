
/******************************************************************************/
/* @F_NAME:           syst_config.h                                           */
/* @F_PURPOSE:        export for syst config module                           */
/* @F_CREATED_BY:     MORIN Pascal                                            */
/* @F_CREATION_DATE:  29/01/2003                                              */
/* @F_MPROC_TYPE:     RH850                                                */
/************************************** (C) Copyright 2015 Magneti Marelli ****/

#ifndef SYST_CONFIG_H
#define SYST_CONFIG_H

/*_____ I N C L U D E - F I L E S ____________________________________________*/

#define SYST_CONFIG_PROJECT_VERSION_DEFINED
#define SYST_CONFIG_PROJECT_NAME_DEFINED
/*#define SYST_SOFTRESETCHECK_BEFORE_DEEPSTOP*/

#define SYST_FBL_RESTART_FROM_BOOT                  ((SYST_BootKey_t) 0xA7A6A5A4)

/* syst_config.h IS included only by "syst.h"                                 */

/* EEPS module must be included if SYST_FLASH_BLOCK_DEF_IN_EEPROM is used. See
   below. */
/*#include "eeps.h"*/
#include "Platform_types.h"
#include "cy_flash.h"
/*_____ G L O B A L - D E F I N E ____________________________________________*/

/* Define if you want enable reset info */
//#define SYST_RESET_INFO

/* Project type use 2 bytes */
/* i.e. : LL, ML, HL, EUrope ...                          */
/* XX if only one SW for Marelli cluster for this vehicle */
#define Syst_VERSION_TYPE    "MI"

#ifdef SYST_F1x_DEEPSTOP_USED
/* Define if you want to activate backup of RAM appli data in BURAM
 * (=maintained at sleep) */
/*#define SYST_DATA_SAVE_IN_DEEPSTOP*/
#endif
/* Define if you want to activate backup of RAM shared and reset data in BURAM
 * (=maintained at reset) */
/*#define SYST_DATA_SAVE_IN_RESET*/
/* Define here table size of Syst_BkpSectBoot, Syst_BkpSecBeforeInit,
 * Syst_BkpSecAfterInit. */
#define Syst_BKP_SEC_NB_BOOT        1
#define Syst_BKP_SEC_NB_BEFORE_INIT  1
#define Syst_BKP_SEC_NB_SLEEP_BEFORE_INIT  1
#define Syst_BKP_SEC_NB_SLEEP_AFTER_INIT  2

/* ---------------- END DEEPSTOP CONFIGURATION ----------------------------- */
#define USEC(x)  (((((uint32)(x))) + ( 1000UL  / 2 )) / 1000UL )/*	valid range for x: 0..4294966795	*/
#define MSEC(x)  ((uint32)(x)) /*	valid range for x: 0..2147483647	*/
#define SEC(x)   (((uint32)(x)) * 1000UL ) /*	valid range for x: 0..2147483	*/


/* define Scss task period */
#define SYST_SSCS_TASK_PERIOD MSEC(85)

/* define Wkss task period */
#define SYST_WKSS_TASK_PERIOD MSEC(100)

/* define Wkss task delay */
#define SYST_WKSS_TASK_DELAY USEC(2500)

/* define Sscs task delay */
#define SYST_SSCS_TASK_DELAY USEC(2500)

#define NO_PERIOD            (0)
#define NO_DELAY             USEC(2500)
#define DELAY_2_5MS          USEC(2500)
#define DELAY_5MS            USEC(5000)
#define DELAY_7_5MS          USEC(7500)
#define DELAY_17_5MS         USEC(17500)

#define DELAY_10MS           MSEC(10)
#define DELAY_100MS          MSEC(100)
#define DELAY_500MS          MSEC(500)
#define DELAY_3000MS         MSEC(3000)

#define PERIOD_2_5MS         USEC(2500)
#define PERIOD_5MS           USEC(5000)
#define PERIOD_10MS          USEC(10000)
#define PERIOD_20MS          USEC(20000)
#define PERIOD_15MS          USEC(15000)
#define PERIOD_25MS          USEC(25000)
#define PERIOD_12_5MS        USEC(12500)
#define PERIOD_50MS          USEC(50000)
#define PERIOD_95MS          USEC(95000)
#define PERIOD_90MS          USEC(90000)
#define PERIOD_100MS         USEC(100000)
#define PERIOD_125MS         USEC(125000)
#define PERIOD_200MS         USEC(200000)
#define PERIOD_250MS         USEC(250000)
/******************************************************************************/
/* Name : Poly_DisableAllInterrupts                                           */
/* Role : Disable all maskable interrupts of the system                       */
/* Interface : OSEK compliant                                                 */
/* Pre-condition : none                                                       */
/* Constraints : - Do not call this service in an interrupt function          */
/*               - Must be called instead of DisableAllInterrupts() when      */
/*                 critical section does not end in the same block.           */
/*                 Poly_EnableAllInterrupts() must end this critical section. */
/******************************************************************************/
#ifndef __POLYSPACE__
#define Poly_DisableAllInterrupts()  DisableAllInterrupts()
#else
extern void Poly_DisableAllInterrupts(void);
#endif /* !__POLYSPACE__ */

/******************************************************************************/
/* Name : Poly_EnableAllInterrupts                                            */
/* Role : Enable all maskable interrupts of the system                        */
/* Interface : OSEK compliant                                                 */
/* Pre-condition : none                                                       */
/* Constraints : - Do not call this service in an interrupt function          */
/*               - Must be called instead of EnableAllInterrupts() when       */
/*                 critical section starts whith Poly_DisableAllInterrupts(). */
/******************************************************************************/
#ifndef __POLYSPACE__
#define Poly_EnableAllInterrupts()  EnableAllInterrupts()
#else
extern void Poly_EnableAllInterrupts(void);
#endif /* !__POLYSPACE__ */
#define Syst_CRC16_INV_CCITT

#endif  /* SYST_CONFIG_H */

/*_____ E N D _____ (syst_config.h) __________________________________________*/

