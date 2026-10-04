/******************************************************************************/
/*@F_NAME:           iodd_priv.h                                              */
/*@F_PURPOSE:        Private interface for IODD module                        */
/*@F_CREATED_BY:     Yanbin SHEN                                              */
/*@F_CREATION_DATE:  Jun/22/2020                                              */
/*@F_LANGUAGE :      ANSI C                                                   */
/*@F_MPROC_TYPE:     Cypress Traveo II series                                 */
/********************************************** (C) Copyright 2020 Marelli ****/

#ifndef IODD_PRIV_H
#define IODD_PRIV_H

/*______ I N C L U D E - F I L E S ___________________________________________*/

#if defined(__CY_TV2__)

/*port / bit mask name definition*/
#include "gpio/cy_gpio.h"

/*______ P R I V A T E - D E F I N E S _______________________________________*/


/*______ P R I V A T E - T Y P E S ___________________________________________*/


/*______ P R I V A T E - D A T A _____________________________________________*/


/*______ P R I V A T E - M A C R O S _________________________________________*/

/**
* \addtogroup group_gpio_functions_init
* \{
*/
#define Iodd_Pin_Init          Cy_GPIO_Pin_Init
#define Iodd_Port_Init         Cy_GPIO_Port_Init
#define Iodd_Pin_FastInit      Cy_GPIO_Pin_FastInit
#define Iodd_Port_Deinit       Cy_GPIO_Port_Deinit
#define Iodd_SetHSIOM          Cy_GPIO_SetHSIOM
#define Iodd_GetHSIOM          Cy_GPIO_GetHSIOM
#define Iodd_PortToAddr        Cy_GPIO_PortToAddr
/** \} group_gpio_functions_init */


/**
* \addtogroup group_gpio_functions_gpio
* \{
*/
#define Iodd_Read              Cy_GPIO_Read
#define Iodd_Write             Cy_GPIO_Write
#define Iodd_ReadOut           Cy_GPIO_ReadOut
#define Iodd_Set               Cy_GPIO_Set
#define Iodd_Clr               Cy_GPIO_Clr
#define Iodd_Inv               Cy_GPIO_Inv
#define Iodd_SetDrivemode      Cy_GPIO_SetDrivemode
#define Iodd_GetDrivemode      Cy_GPIO_GetDrivemode
#define Iodd_SetVtrip          Cy_GPIO_SetVtrip
#define Iodd_GetVtrip          Cy_GPIO_GetVtrip
#define Iodd_SetVtripAuto      GPIO_SetVtripAuto
#define Iodd_GetVtripAuto      GPIO_GetVtripAuto
#define Iodd_SetSlewRate       Cy_GPIO_SetSlewRate
#define Iodd_GetSlewRate       Cy_GPIO_GetSlewRate
#define Iodd_SetDriveSel       Cy_GPIO_SetDriveSel 
#define Iodd_GetDriveSel       Cy_GPIO_GetDriveSel
/** \} group_gpio_functions_gpio */

/**
* \addtogroup group_gpio_functions_interrupt
* \{
*/
#define Iodd_GetInterruptStatus        Cy_GPIO_GetInterruptStatus
#define Iodd_ClearInterrupt            Cy_GPIO_ClearInterrupt
#define Iodd_SetInterruptMask          Cy_GPIO_SetInterruptMask
#define Iodd_GetInterruptMask          Cy_GPIO_GetInterruptMask
#define Iodd_GetInterruptStatusMasked  Cy_GPIO_GetInterruptStatusMasked
#define Iodd_SetSwInterrupt            Cy_GPIO_SetSwInterrupt
#define Iodd_SetInterruptEdge          Cy_GPIO_SetInterruptEdge
#define Iodd_GetInterruptEdge          Cy_GPIO_GetInterruptEdge
#define Iodd_SetFilter                 Cy_GPIO_SetFilter
#define Iodd_GetFilter                 Cy_GPIO_GetFilter
/** \} group_gpio_functions_interrupt */

/*______ P R I V A T E - F U N C T I O N S - P R O T O T Y P E S _____________*/

#endif /* __CY_TV2__ */
#endif /* IODD_PRIV_H */


/*______ E N D _____ (iodd_priv.h) ___________________________________________*/

