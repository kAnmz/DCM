/******************************************************************************/
/* @F_NAME:          spid_kernel.c                                            */
/* @F_PURPOSE:       SPI kernel part for Green Hills Integrity OS             */
/* @F_CREATED_BY:    Olivier DIETLIN                                          */
/* @F_CREATION_DATE: 05/06/2014                                               */
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

/* Memory reservation to access ECSPI modules from a VAS. */
static const MemoryReservation SPID_MemoryArea =
{
  MEMORY_READ | MEMORY_WRITE | MEMORY_VOLATILE | MEMORY_ARM_STRONGLY_ORDERED,
  0,
  IMX6_ECSPI1_BASE, IMX6_ECSPI1_BASE + 0x13fff /* IMX6_ECSPI5_AREA_LAST */,
  Other_MemoryType,
  true, 0xfffff000, 0xfffff000, "SPID_MemoryArea"
};


/*_____ L O C A L - F U N C T I O N S - P R O T O T Y P E S __________________*/

static void SPID_BspUserInit(void);


/*_____ G L O B A L - D A T A ________________________________________________*/

void (*__ghsentry_bspuserinit_ecspi)(void) = SPID_BspUserInit;


/*_____ I M P O R T - F U N C T I O N S - P R O T O T Y P E S ________________*/


/*_____ G L O B A L - F U N C T I O N S ______________________________________*/


/*_____ P R I V A T E - F U N C T I O N S ____________________________________*/


/*_____ L O C A L - F U N C T I O N S ________________________________________*/

/******************************************************************************/
/* Name: SPID_BspUserInit                                                     */
/* Role: ECSPI Bsp initialization                                             */
/* Interface: void                                                            */
/* Pre-condition: none                                                        */
/* Constraints: none                                                          */
/******************************************************************************/
static void SPID_BspUserInit(void)
{
  ExtendedAddress Addr;

  /* Add reservation to access ECSPI from a VAS */
  CheckSuccess(BMT_AllocateFromAnonymousMemoryReservation(&SPID_MemoryArea, &Addr));
}


#endif /* __GHOS__ */

/*_____ E N D _____ (spid_kernel.c) __________________________________________*/
