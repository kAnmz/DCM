/******************************************************************************/
/* @F_NAME :          vers_config.c                                           */
/* @F_PURPOSE :       Version management configuration file                   */
/* @F_CREATED_BY :    Yifeng Yao                                           */
/* @F_CREATION_DATE : 9/5/2016                                              */
/* @F_LANGUAGE :      ANSI - C                                                */
/* @F_MPROC_TYPE :    target independent                                      */
/*************************************** (C) Copyright 2009 Magneti Marelli ***/

/*______ I N C L U D E - F I L E S ___________________________________________*/
#include "vers_config.h"
#include "iodc.h"
/*______ L O C A L - D E F I N E S ___________________________________________*/

/*______ L O C A L - T Y P E S _______________________________________________*/


/*______ G L O B A L - D A T A _______________________________________________*/
/* VERS_BootInfo moved to Variant_Data[VARIANT_DATA_BOOT_VESRION] (variant_config.c) */

/*______ P R I V A T E - D A T A _____________________________________________*/


/*______ L O C A L - D A T A _________________________________________________*/


/*______ L O C A L - M A C R O S _____________________________________________*/


/*______ I M P O R T - F U N C T I O N S - P R O T O T Y P E S _______________*/


/*______ L O C A L - F U N C T I O N S - P R O T O T Y P E S _________________*/


/*______ G L O B A L - F U N C T I O N S _____________________________________*/


/******************************************************************************/
/* Name: VERS_GetPhysicalHardwareVersion                                  */
/* Role: Return the Hardware Version                                          */
/* Interface:                                                                 */
/*                                                                            */
/* Pre-condition:     hardware resistor support version configuration         */
/* Constraints: Must call VERS_InitPhysicalHardwareVersion first          */
/* Behavior:                                                                  */
/*   DO                                                                       */
/*   OD                                                                       */
/******************************************************************************/
VERS_HardwareVersion_t VERS_GetPhysicalHardwareVersion(void)
{
	return 0;
}

/******************************************************************************/
/* Name: VERS_ReadHardwareVersionFromResistor                                 */
/* Role: Return the Hardware Version                                          */
/* Interface:                                                                 */
/*                                                                            */
/* Pre-condition:     hardware resistor support version configuration         */
/* Constraints: none                                                          */
/* Behavior:                                                                  */
/*   DO                                                                       */
/*   OD                                                                       */
/******************************************************************************/
VERS_HardwareVersion_t VERS_ReadHardwareVersionFromResistor(void)
{
  VERS_HardwareVersion_t HwVersion = VERS_HW_VER_PTB;
  return HwVersion;
}

/******************************************************************************/
/* Name: VERS_InitPhysicalHardwareVersion                                     */
/* Role: Init Hardware Version From Resistor                                  */
/* Interface:                                                                 */
/*                                                                            */
/* Pre-condition:     hardware resistor support version configuration         */
/* Constraints: must call after IODC_Init                                     */
/* Behavior:                                                                  */
/*   DO                                                                       */
/*   OD                                                                       */
/******************************************************************************/
void VERS_InitPhysicalHardwareVersion(void)
{

}

/*______ L O C A L - F U N C T I O N S _______________________________________*/


/*______ E N D _____ (vers_config.c) _________________________________________*/
