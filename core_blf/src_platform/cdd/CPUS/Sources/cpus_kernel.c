/******************************************************************************/
/* @F_NAME:          cpus_kernel.c                                            */
/* @F_PURPOSE:       CPUS kernel part for Green Hills Integrity OS            */
/* @F_CREATED_BY:    Olivier DIETLIN                                          */
/* @F_CREATION_DATE: 05/11/2015                                               */
/* @F_LANGUAGE:      C                                                        */
/* @F_MPROC_TYPE:    imx6                                                     */
/************************************** (C) Copyright 2015 Magneti Marelli ****/

#ifdef __GHOS__

/*_____ I N C L U D E - F I L E S ____________________________________________*/

#include <INTEGRITY.h>
#include <stdlib.h>
#include <stdio.h>
#include "modules/ghs/bspsrc/support/buildmemtable.h"
#include "modules/ghs/bspsrc/driver/soc/imx61/imx6-memmap.h"
#include "boottable.h"

#include "rgimx6.h"

#define TARG_WriteLong(Reg,Value)                     \
  (*(volatile bitfield_long_t*)((volatile uint8_t *)(&Reg) + (IMX6_IOMAP_BASE)))._long = Value

#include "cpus_config.h"


/*_____ L O C A L - D E F I N E ______________________________________________*/


/*_____ L O C A L - T Y P E S ________________________________________________*/


/*_____ L O C A L - M A C R O S ______________________________________________*/


/*_____ P R I V A T E - D A T A ______________________________________________*/


/*_____ L O C A L - D A T A __________________________________________________*/


/*_____ L O C A L - F U N C T I O N S - P R O T O T Y P E S __________________*/


/*_____ G L O B A L - D A T A ________________________________________________*/

void (*__ghsentry_bspuserinit_iomux)(void) = CPUS_ConfigIomux;
void (*__ghsentry_bspuserinit_clock)(void) = CPUS_StartPll;


/*_____ I M P O R T - F U N C T I O N S - P R O T O T Y P E S ________________*/


/*_____ G L O B A L - F U N C T I O N S ______________________________________*/


/*_____ P R I V A T E - F U N C T I O N S ____________________________________*/


/*_____ L O C A L - F U N C T I O N S ________________________________________*/


#endif /* __GHOS__ */


/*_____ E N D  O F  F I L E ___ (cpus_kernel.c) ______________________________*/
