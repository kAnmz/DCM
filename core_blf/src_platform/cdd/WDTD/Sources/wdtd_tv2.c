/******************************************************************************/
/*@F_NAME:           xxxx.c                                                   */
/*@F_PURPOSE:        XXXX - Module description                                */
/*@F_CREATED_BY:     Yanbin SHEN                                              */
/*@F_CREATION_DATE:  Jun/22/2020                                              */
/*@F_LANGUAGE :      ANSI C                                                   */
/*@F_MPROC_TYPE:     Cypress Traveo II series                                 */
/********************************************** (C) Copyright 2020 Marelli ****/


/*______ I N C L U D E - F I L E S ___________________________________________*/
#include "cy_device_headers.h"
#include "cy_syswdt.h"
#include "wdgc_config.h"
#include "dlt.h"
#include "dlt_config.h"
#include "devm.h"

/*______ L O C A L - D E F I N E S ___________________________________________*/


/*______ L O C A L - T Y P E S _______________________________________________*/


/*______ G L O B A L - D A T A _______________________________________________*/


/*______ P R I V A T E - D A T A _____________________________________________*/


/*______ L O C A L - D A T A _________________________________________________*/


/*______ L O C A L - M A C R O S _____________________________________________*/


/*______ I M P O R T - F U N C T I O N S - P R O T O T Y P E S _______________*/


/*______ L O C A L - F U N C T I O N S - P R O T O T Y P E S _________________*/


/*______ G L O B A L - F U N C T I O N S _____________________________________*/
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
void WDGD_Init(void)
{
	 /* Configuration for WDT */
	 Cy_WDT_Disable();
	 Cy_WDT_Unlock();
	 Cy_WDT_SetLowerLimit(0);
	 Cy_WDT_SetUpperLimit(Wdgc_TimeoutValue);
	 Cy_WDT_SetWarnLimit(0);
	 Cy_WDT_SetLowerAction(CY_WDT_LOW_UPP_ACTION_NONE);
	 Cy_WDT_SetUpperAction(CY_WDT_LOW_UPP_ACTION_RESET);
	 Cy_WDT_SetWarnAction (CY_WDT_WARN_ACTION_NONE);
	 Cy_WDT_SetDebugRun(CY_WDT_DISABLE);
	 Cy_WDT_Lock();
	 Cy_WDT_Enable();
}



/*______ P R I V A T E - F U N C T I O N S ___________________________________*/


/*______ L O C A L - F U N C T I O N S _______________________________________*/


/*______ E N D _____ (xxxx.c) ________________________________________________*/

