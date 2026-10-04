/******************************************************************************/
/*@F_NAME:           wdgp.h                                                   */
/*@F_PURPOSE:        Public interface                                         */
/*@F_CREATED_BY:     MORIN Pascal                                             */
/*@F_CREATION_DATE:  02/05/2002                                               */
/*@F_MPROC_TYPE:     up Independent                                           */
/************************************** (C) Copyright 2002 Magneti Marelli ****/

#ifndef WDGP_H
#define WDGP_H

/*______ I N C L U D E - F I L E S ___________________________________________*/

#include "syst.h"
#include "wdgc.h"
#include "wdtd.h"

/*______ G L O B A L - D E F I N E S _________________________________________*/


/*______ G L O B A L - T Y P E S _____________________________________________*/


/*______ G L O B A L - D A T A _______________________________________________*/


/*______ G L O B A L - M A C R O S ___________________________________________*/

/******************************************************************************/
/*Name : WDGP_RefreshWatchdog                                                 */
/*Role : Manage the watchdog functionality depending on the watchdog          */
/*       characteristic                                                       */
/*Interface :                                                                 */
/*Pre-condition : -                                                           */
/*Constraints : -                                                             */
/*Behaviour : -                                                               */
/* DO                                                                         */
/*  [ Call the specific Control routine that manage the watchdog ]            */
/* OD                                                                         */
/******************************************************************************/
#define WDGP_RefreshWatchdog()  WDTD_Refresh()


#ifdef __EOL_ENABLE__
/******************************************************************************/
/*Name : WDGP_StopExternalWatchdog                                            */
/*Role : Stop the refresh of External Watchdog only. Even if we call the      */
/*       Watchdog refresh routine.                                            */
/*Interface :                                                                 */
/*Pre-condition : -                                                           */
/*Constraints : THIS ROUTINE COULD BE USED BY EOL SW ONLY                     */
/*Behaviour : -                                                               */
/* DO                                                                         */
/* OD                                                                         */
/******************************************************************************/
#define WDGP_StopExternalWatchdog()   WDGC_StopExternalWatchdog()
#endif /* __EOL_ENABLE__ */


/*______ G L O B A L - F U N C T I O N S - P R O T O T Y P E S _______________*/


#endif /* WDGP_H */

/*_____ E N D _____ (wdgp.h) _________________________________________________*/

