/******************************************************************************/
/*@F_NAME:           xxxx.h                                                   */
/*@F_PURPOSE:        Public interface for XXXX module                         */
/*@F_CREATED_BY:     Yanbin SHEN                                              */
/*@F_CREATION_DATE:  Jun/22/2020                                              */
/*@F_LANGUAGE :      ANSI C                                                   */
/*@F_MPROC_TYPE:     Cypress Traveo II series                                 */
/********************************************** (C) Copyright 2020 Marelli ****/
#ifndef __WDTD_TV2_H__
#define __WDTD_TV2_H__

/*______ I N C L U D E - F I L E S ___________________________________________*/
#include "cy_syswdt.h"

/*______ G L O B A L - D E F I N E S _________________________________________*/


/*______ G L O B A L - T Y P E S _____________________________________________*/


/*______ G L O B A L - M A C R O S ___________________________________________*/


/*______ G L O B A L - F U N C T I O N S - P R O T O T Y P E S _______________*/
/*----------------------------------------------------------------------------*/
/* Name : WDGD_Init                                                           */
/* Role : Basic watchdog initialization                                       */
/* Interface : -                                                              */
/* Pre-condition : -                                                          */
/* Constraints : -                                                            */
/* Behavior :                                                                 */
/*   DO                                                                       */
/*     [Initializes watchdog]                                                 */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/
extern void WDGD_Init(void);

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
#define WDTD_Refresh() \
		Cy_WDT_ClearWatchdog()

#endif /* __WDTD_TV2_H__ */

/*______ E N D _____ (xxxx.h) ________________________________________________*/
