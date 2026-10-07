/******************************************************************************/
/*@F_NAME:           vers_config.h                                            */
/*@F_PURPOSE:        Configuration File for VERS Module - NEXTEV ES8 project  */
/*@F_CREATED_BY:     Yifeng Yao                                               */
/*@F_CREATION_DATE:  09/05/2016                                               */
/*@F_LANGUAGE :      C                                                        */
/*@F_MPROC_TYPE:     independent                                              */
/************************************** (C) Copyright 2007 Magneti Marelli ****/

#ifndef VERS_CONFIG_H
#include "type.h"
#define VERS_CONFIG_H

/*______ I N C L U D E - F I L E S ___________________________________________*/

/*______ P R I V A T E - D E F I N E S _______________________________________*/

typedef enum
{
  VERS_HW_VER_PTB = 0x00,
  VERS_HW_VER_PTC_1 = 0x01,/*ROM_2MB*/
  VERS_HW_VER_PTC_1_ROM_1MB = 0x02,/*PTC_1_ROM_1MB/ PRS_1*/
  VERS_HW_VER_PRS_2 = 0x03/*reserved*/
}VERS_HardwareVersion_t;


/*______ P R I V A T E - T Y P E S ___________________________________________*/


/*______ P R I V A T E - D A T A _____________________________________________*/


/*______ P R I V A T E - M A C R O S _________________________________________*/


/*______ P R I V A T E - F U N C T I O N S - P R O T O T Y P E S _____________*/


/*______ G L O B A L - D E F I N E S _________________________________________*/
/*
 * The per-variant diagnostic identifiers that used to be defined here
 * (SBL_DIAG_DB_PART_NUMBER, SBL_SW_VERSION_NUMBER, Diag_PBLDiagDatabasePN,
 *  Diag_PBLSoftDiagDatabasePN, Diag_ECUCoreAsmPN, Diag_ECUDeliAsmPN) have
 * moved to Variant_Data, see variant_config.c / variant_config.h.
 */

/*______ G L O B A L - T Y P E S _____________________________________________*/


/*______ G L O B A L - D A T A _______________________________________________*/
/* VERS_BootInfo moved to Variant_Data[VARIANT_DATA_BOOT_VESRION], see variant_config.h */

/*______ G L O B A L - M A C R O S ___________________________________________*/


/*______ G L O B A L - F U N C T I O N S - P R O T O T Y P E S _______________*/

extern void VERS_InitPhysicalHardwareVersion(void);

extern VERS_HardwareVersion_t VERS_GetPhysicalHardwareVersion(void);

#endif /* VERS_CONFIG_H */

/*______ E N D _____ (vers_config.h) _________________________________________*/
