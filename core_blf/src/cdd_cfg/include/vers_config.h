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
/* DID F1A1 */
#define Diag_PBLDiagDatabasePN_Len 5u
#define Diag_PBLDiagDatabaseVer_Len 3u
#define Diag_PBLDiagDatabaseVer "  A"
#define Diag_PBLDiagDatabaseTotal_Len (Diag_PBLDiagDatabasePN_Len + Diag_PBLDiagDatabaseVer_Len)
/* DID F1A5 */
#define Diag_PBLSoftDiagDatabasePN_Len 5u
#define Diag_PBLSoftDiagDatabaseVer_Len 3u
#define Diag_PBLSoftDiagDatabaseVer "  A"
#define Diag_PBLSoftDiagDatabaseTotal_Len (Diag_PBLSoftDiagDatabasePN_Len + Diag_PBLSoftDiagDatabaseVer_Len)
/* DID F1AA */
#define Diag_ECUCoreAsmPN_Len 5u
#define Diag_ECUCoreAsmVer_Len 3u
#define Diag_ECUCoreAsmVer "  A"
#define Diag_ECUCoreAsmTotal_Len (Diag_ECUCoreAsmPN_Len + Diag_ECUCoreAsmVer_Len)
/* DID F1AB */
#define Diag_ECUDeliAsmPN_Len 5u
#define Diag_ECUDeliAsmVer_Len 3u
#define Diag_ECUDeliAsmVer "  A"
#define Diag_ECUDeliAsmTotal_Len (Diag_ECUDeliAsmPN_Len + Diag_ECUDeliAsmVer_Len)

/******************************************************************************/
/******************** BJEV FL DCU DID definition  *****************************/
#if defined(DCU_FL)
/* DID F1A2 */
#define  SBL_DIAG_DB_PART_NUMBER          0x66, 0x08, 0x68, 0x35, 0x86, 0x20, 0x20, 0x41  /* '  A' */

/* DID F124 */
#define  SBL_SW_VERSION_NUMBER          0x66, 0x08, 0x11, 0x54, 0x13, 0x00, 0x00

/* DID F1A1 */
#define Diag_PBLDiagDatabasePN 0x66u, 0x08u, 0x68u, 0x35u, 0x88u
/* DID F1A5 */
#define Diag_PBLSoftDiagDatabasePN 0x66u, 0x08u, 0x68u, 0x35u, 0x68u
/* DID F1AA */
#define Diag_ECUCoreAsmPN 0x66u, 0x08u, 0x50u, 0x77u, 0x54u
/* DID F1AB */
#define Diag_ECUDeliAsmPN 0x66u, 0x08u, 0x58u, 0x02u, 0x60u
/******************************************************************************/
/******************** BJEV FR DCU DID definition  *****************************/
#elif defined(DCU_FR)
/* DID F1A2 */
#define  SBL_DIAG_DB_PART_NUMBER          0x66, 0x08, 0x68, 0x35, 0x79, 0x20, 0x20, 0x41  /* '  A' */

/* DID F124 */
#define  SBL_SW_VERSION_NUMBER          0x66, 0x08, 0x11, 0x54, 0x09, 0x00, 0x00

/* DID F1A1 */
#define Diag_PBLDiagDatabasePN 0x66u, 0x08u, 0x68u, 0x52u, 0x55u
/* DID F1A5 */
#define Diag_PBLSoftDiagDatabasePN 0x66u, 0x08u, 0x68u, 0x35u, 0x82u
/* DID F1AA */
#define Diag_ECUCoreAsmPN 0x66u, 0x08u, 0x50u, 0x77u, 0x53u
/* DID F1AB */
#define Diag_ECUDeliAsmPN 0x66u, 0x08u, 0x58u, 0x02u, 0x59u
/******************************************************************************/
/******************** BJEV RL DCU DID definition  *****************************/
#elif defined(DCU_RL)
/* DID F1A2 */
#define  SBL_DIAG_DB_PART_NUMBER          0x66, 0x08, 0x68, 0x35, 0x72, 0x20, 0x20, 0x41  /* '  A' */

/* DID F124 */
#define  SBL_SW_VERSION_NUMBER          0x66, 0x08, 0x11, 0x54, 0x02, 0x00, 0x00

/* DID F1A1 */
#define Diag_PBLDiagDatabasePN 0x66u, 0x08u, 0x68u, 0x35u, 0x74u
/* DID F1A5 */
#define Diag_PBLSoftDiagDatabasePN 0x66u, 0x08u, 0x68u, 0x35u, 0x75u
/* DID F1AA */
#define Diag_ECUCoreAsmPN 0x66u, 0x08u, 0x50u, 0x77u, 0x52u
/* DID F1AB */
#define Diag_ECUDeliAsmPN 0x66u, 0x08u, 0x58u, 0x02u, 0x58u
/******************************************************************************/
/******************** BJEV RR DCU DID definition  *****************************/
#elif defined(DCU_RR)
/* DID F1A2 */
#define  SBL_DIAG_DB_PART_NUMBER          0x66, 0x08, 0x68, 0x35, 0x64, 0x20, 0x20, 0x41  /* '  A' */

/* DID F124 */
#define  SBL_SW_VERSION_NUMBER          0x66, 0x08, 0x11, 0x54, 0x01, 0x00, 0x00

/* DID F1A1 */
#define Diag_PBLDiagDatabasePN 0x66u, 0x08u, 0x68u, 0x35u, 0x66u
/* DID F1A5 */
#define Diag_PBLSoftDiagDatabasePN 0x66u, 0x08u, 0x68u, 0x35u, 0x67u
/* DID F1AA */
#define Diag_ECUCoreAsmPN 0x66u, 0x08u, 0x50u, 0x77u, 0x51u
/* DID F1AB */
#define Diag_ECUDeliAsmPN 0x66u, 0x08u, 0x58u, 0x02u, 0x57u
#endif

/*______ G L O B A L - T Y P E S _____________________________________________*/


/*______ G L O B A L - D A T A _______________________________________________*/
extern volatile const ubyte VERS_BootInfo[];

/*______ G L O B A L - M A C R O S ___________________________________________*/


/*______ G L O B A L - F U N C T I O N S - P R O T O T Y P E S _______________*/

extern void VERS_InitPhysicalHardwareVersion(void);

extern VERS_HardwareVersion_t VERS_GetPhysicalHardwareVersion(void);

#endif /* VERS_CONFIG_H */

/*______ E N D _____ (vers_config.h) _________________________________________*/
