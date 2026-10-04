/******************************************************************************/
/* @F_NAME:          wdtd_kernel.c                                            */
/* @F_PURPOSE:       WDOG kernel part for Green Hills Integrity OS            */
/* @F_CREATED_BY:    Olivier DIETLIN                                          */
/* @F_CREATION_DATE: 16/06/2014                                               */
/* @F_LANGUAGE:      C                                                        */
/* @F_MPROC_TYPE:    imx6                                                     */
/************************************** (C) Copyright 2014 Magneti Marelli ****/

#ifdef __GHOS__

/*_____ I N C L U D E - F I L E S ____________________________________________*/

#include <INTEGRITY.h>
#include <stdlib.h>
#include <stdio.h>
#include "modules/ghs/bspsrc/support/buildmemtable.h"
#include "modules/ghs/bspsrc/driver/soc/imx61/imx6-memmap.h"


/*_____ L O C A L - D E F I N E ______________________________________________*/


/*_____ L O C A L - T Y P E S ________________________________________________*/


/*_____ L O C A L - M A C R O S ______________________________________________*/


/*_____ P R I V A T E - D A T A ______________________________________________*/


/*_____ L O C A L - D A T A __________________________________________________*/

/* Memory reservation to access WDOG1 module from a VAS */
static const MemoryReservation WDTD_MemoryArea =
{
  MEMORY_READ | MEMORY_WRITE | MEMORY_VOLATILE | MEMORY_ARM_STRONGLY_ORDERED,
  0,
  IMX6_WDOG1_BASE, IMX6_WDOG1_BASE + 0x3fff /* IMX6_WDOG1_AREA_LAST */,
  Other_MemoryType,
  true, 0xfffff000, 0xfffff000, "WDTD_MemoryArea"
};

/* Memory reservation to access SRC module from a VAS */
static const MemoryReservation WDTD_SrcMemoryArea =
{
  MEMORY_READ | MEMORY_WRITE | MEMORY_VOLATILE | MEMORY_ARM_STRONGLY_ORDERED,
  0,
  IMX6_SRC_BASE, IMX6_SRC_BASE + 0x3fff /* IMX6_SRC_AREA_LAST */,
  Other_MemoryType,
  true, 0xfffff000, 0xfffff000, "WDTD_SrcMemoryArea"
};


/*_____ L O C A L - F U N C T I O N S - P R O T O T Y P E S __________________*/

static void WDTD_BspUserInit(void);


/*_____ G L O B A L - D A T A ________________________________________________*/

void (*__ghsentry_bspuserinit_wdog)(void) = WDTD_BspUserInit;


/*_____ I M P O R T - F U N C T I O N S - P R O T O T Y P E S ________________*/


/*_____ G L O B A L - F U N C T I O N S ______________________________________*/


/*_____ P R I V A T E - F U N C T I O N S ____________________________________*/


/*_____ L O C A L - F U N C T I O N S ________________________________________*/

/******************************************************************************/
/* Name: WDTD_BspUserInit                                                     */
/* Role: WDOG Bsp initialization                                              */
/* Interface: void                                                            */
/* Pre-condition: none                                                        */
/* Constraints: none                                                          */
/******************************************************************************/
static void WDTD_BspUserInit(void)
{
  ExtendedAddress Addr;

  /* Add reservation to access WDOG1 and SRC from a VAS */
  CheckSuccess(BMT_AllocateFromAnonymousMemoryReservation(&WDTD_MemoryArea, &Addr));
  CheckSuccess(BMT_AllocateFromAnonymousMemoryReservation(&WDTD_SrcMemoryArea, &Addr));
}


#endif /* __GHOS__ */

/*_____ E N D _____ (wdtd_kernel.c) __________________________________________*/
