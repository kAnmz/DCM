/******************************************************************************/
/*@F_NAME:           syst_priv.h                                              */
/*@F_PURPOSE:        SYST - Private header                                    */
/*@F_CREATED_BY:     Olivier DIETLIN                                          */
/*@F_CREATION_DATE:  27/10/2014                                               */
/*@F_LANGUAGE :      ANSI C                                                   */
/*@F_MPROC_TYPE:     Processor independent                                    */
/************************************** (C) Copyright 2014 Magneti Marelli ****/

#ifndef SYST_PRIV_H
#define SYST_PRIV_H

#ifdef __GHOS__


/*______ I N C L U D E - F I L E S ___________________________________________*/


/*______ P R I V A T E - D E F I N E S _______________________________________*/

/* Possible RegisterNb parameter values for ReadIODeviceRegister and WriteIODeviceRegister services */
#define Syst_PHYSICAL_ADDRESS  0
#define Syst_BOOT_KEY_RAM      1
#define Syst_SET_RAM_ADDRESS   2
#define Syst_READ_RAM          3
#define Syst_WRITE_RAM         4
#define Syst_PRINT_CLOCKS      5

/* Possible StatusNumber values for ReadIODeviceStatus and WriteIODeviceStatus services */
#define Syst_BL_SW_ID_INDEX        1
#define Syst_FLASHER_SW_ID_INDEX   2
#define Syst_CLIENT_SW_ID_INDEX    3
#define Syst_EOL_SW_ID_INDEX       4

#endif /* __GHOS__ */

#endif /* SYST_PRIV_H */

/*______ E N D _____ (syst_priv.h) ___________________________________________*/
