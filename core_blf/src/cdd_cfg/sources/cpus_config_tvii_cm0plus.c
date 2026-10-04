/******************************************************************************/
/* @F_NAME :          cpus_config_tviibe2m_cm0plus.c                                            							   */
/* @F_PURPOSE :       MCU clock configuration                             													       */
/* @F_CREATED_BY :   Wei Liang                                              																	   */
/* @F_CREATION_DATE : 2020.08.24                                              														   */
/* @F_LANGUAGE :      ANSI C                                                  																	   */
/* @F_MPROC_TYPE :    target independent                                      													   */
/*************************************** (C) Copyright 2020 Magneti Marelli ********/
/*______ I N C L U D E - F I L E S ___________________________________________*/
#include <stdint.h>
#include <stdbool.h>
#include "cy_device_headers.h"
#include "cy_syswdt.h"
#include "cy_sysclk.h"
#include "cpus_config_tvii.h"
#include "bb_bsp_tviibe1m.h"

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
/* Name : CPUS_InitPerpheralClockConfig                                      */
/* Role : Initial Peripheral Clock  Configuration                              */
/* Interface : -                                                             								 */
/* Pre-condition : -                                                          						 */
/* Constraints :                                                              							 */
/* Behavior :                                                                						 	 */
/*  DO                                                                        								 */
/*    [...to be edited...]                                                   						 */
/*  OD                                                                       									*/
/*----------------------------------------------------------------------------*/
void CPUS_InitPeripheralClockConfig (void)
{
#if 0
	/*SCB Clock configuration*/

	/*SCB0: Clock Configuration*/
    /* Assign a programmable divider */
    Cy_SysClk_PeriphAssignDivider(PCLK_SCB0_CLOCK, CY_SYSCLK_DIV_24_5_BIT, CPUS_PERI_CLOCK_CTL_DIV_SEL_SCB0);
    Cy_SysClk_PeriphSetFracDivider(CY_SYSCLK_DIV_24_5_BIT, CPUS_PERI_CLOCK_DIV_24_5_CHANNEL0, CPUS_PERI_DIV_16_5_CTL_INT16_DIV_SCB0, CPUS_PERI_DIV_16_5_CTL_FRAC5_DIV_SCB0); // Divider 10MHz --> 80MHz / 8  = 10MHz
    /* Enable peripheral divider */
    Cy_SysClk_PeriphEnableDivider(CY_SYSCLK_DIV_24_5_BIT, CPUS_PERI_DIV_CMD_DIV_SEL_SCB0);

	/*SCB1: Clock Configuration*/
    /* Assign a programmable divider */
    Cy_SysClk_PeriphAssignDivider(PCLK_SCB1_CLOCK, CY_SYSCLK_DIV_24_5_BIT, CPUS_PERI_CLOCK_CTL_DIV_SEL_SCB1);
    Cy_SysClk_PeriphSetFracDivider(CY_SYSCLK_DIV_24_5_BIT, CPUS_PERI_CLOCK_DIV_24_5_CHANNEL1, CPUS_PERI_DIV_16_5_CTL_INT16_DIV_SCB1, CPUS_PERI_DIV_16_5_CTL_FRAC5_DIV_SCB1); // Divider 10MHz --> 80MHz / 8  = 10MHz
    /* Enable peripheral divider */
    Cy_SysClk_PeriphEnableDivider(CY_SYSCLK_DIV_24_5_BIT, CPUS_PERI_DIV_CMD_DIV_SEL_SCB1);

	/*SCB2: Clock Configuration*/
    /* Assign a programmable divider */
    Cy_SysClk_PeriphAssignDivider(PCLK_SCB2_CLOCK, CY_SYSCLK_DIV_24_5_BIT, CPUS_PERI_CLOCK_CTL_DIV_SEL_SCB2);
    Cy_SysClk_PeriphSetFracDivider(CY_SYSCLK_DIV_24_5_BIT, CPUS_PERI_CLOCK_DIV_24_5_CHANNEL2, CPUS_PERI_DIV_16_5_CTL_INT16_DIV_SCB2, CPUS_PERI_DIV_16_5_CTL_FRAC5_DIV_SCB2); // Divider 10MHz --> 80MHz / 8  = 10MHz
    /* Enable peripheral divider */
    Cy_SysClk_PeriphEnableDivider(CY_SYSCLK_DIV_24_5_BIT, CPUS_PERI_DIV_CMD_DIV_SEL_SCB2);

    /*SCB3: Clock Configuration*/
    /* Assign a programmable divider */
    Cy_SysClk_PeriphAssignDivider(PCLK_SCB3_CLOCK, CY_SYSCLK_DIV_24_5_BIT, CPUS_PERI_CLOCK_CTL_DIV_SEL_SCB3);
    Cy_SysClk_PeriphSetFracDivider(CY_SYSCLK_DIV_24_5_BIT, CPUS_PERI_CLOCK_DIV_24_5_CHANNEL3, CPUS_PERI_DIV_16_5_CTL_INT16_DIV_SCB3, CPUS_PERI_DIV_16_5_CTL_FRAC5_DIV_SCB3); // Divider 86.8125 --> 80MHz / 86.8125 / 8 (oversampling) = 115190 Hz
    /* Enable peripheral divider */
    Cy_SysClk_PeriphEnableDivider(CY_SYSCLK_DIV_24_5_BIT, CPUS_PERI_DIV_CMD_DIV_SEL_SCB3);

	/*SCB4: Clock Configuration*/
    /* Assign a programmable divider */
    Cy_SysClk_PeriphAssignDivider(PCLK_SCB4_CLOCK, CY_SYSCLK_DIV_24_5_BIT, CPUS_PERI_CLOCK_CTL_DIV_SEL_SCB4);
    Cy_SysClk_PeriphSetFracDivider(CY_SYSCLK_DIV_24_5_BIT, CPUS_PERI_CLOCK_DIV_24_5_CHANNEL4, CPUS_PERI_DIV_16_5_CTL_INT16_DIV_SCB4, CPUS_PERI_DIV_16_5_CTL_FRAC5_DIV_SCB4); // Divider 10MHz --> 80MHz / 8  = 10MHz
    /* Enable peripheral divider */
    Cy_SysClk_PeriphEnableDivider(CY_SYSCLK_DIV_24_5_BIT, CPUS_PERI_DIV_CMD_DIV_SEL_SCB4);

	/*SCB5: Clock Configuration*/
    /* Assign a programmable divider */
    Cy_SysClk_PeriphAssignDivider(PCLK_SCB5_CLOCK, CY_SYSCLK_DIV_24_5_BIT, CPUS_PERI_CLOCK_CTL_DIV_SEL_SCB5);
    Cy_SysClk_PeriphSetFracDivider(CY_SYSCLK_DIV_24_5_BIT, CPUS_PERI_CLOCK_DIV_24_5_CHANNEL5, CPUS_PERI_DIV_16_5_CTL_INT16_DIV_SCB5, CPUS_PERI_DIV_16_5_CTL_FRAC5_DIV_SCB5); // Divider 10MHz --> 80MHz / 8  = 10MHz
    /* Enable peripheral divider */
    Cy_SysClk_PeriphEnableDivider(CY_SYSCLK_DIV_24_5_BIT, CPUS_PERI_DIV_CMD_DIV_SEL_SCB5);

	/*SCB6: Clock Configuration*/
    /* Assign a programmable divider */
    Cy_SysClk_PeriphAssignDivider(PCLK_SCB6_CLOCK, CY_SYSCLK_DIV_24_5_BIT, CPUS_PERI_CLOCK_CTL_DIV_SEL_SCB6);
    Cy_SysClk_PeriphSetFracDivider(CY_SYSCLK_DIV_24_5_BIT, CPUS_PERI_CLOCK_DIV_24_5_CHANNEL6, CPUS_PERI_DIV_16_5_CTL_INT16_DIV_SCB6, CPUS_PERI_DIV_16_5_CTL_FRAC5_DIV_SCB6); // Divider 10MHz --> 80MHz / 8  = 10MHz
    /* Enable peripheral divider */
    Cy_SysClk_PeriphEnableDivider(CY_SYSCLK_DIV_24_5_BIT, CPUS_PERI_DIV_CMD_DIV_SEL_SCB6);

    /*SCB7: Clock Configuration*/
    /* Assign a programmable divider */
    Cy_SysClk_PeriphAssignDivider(PCLK_SCB7_CLOCK, CY_SYSCLK_DIV_24_5_BIT, CPUS_PERI_CLOCK_CTL_DIV_SEL_SCB7);
    Cy_SysClk_PeriphSetFracDivider(CY_SYSCLK_DIV_24_5_BIT, CPUS_PERI_CLOCK_DIV_24_5_CHANNEL7, CPUS_PERI_DIV_16_5_CTL_INT16_DIV_SCB7, CPUS_PERI_DIV_16_5_CTL_FRAC5_DIV_SCB7); // Divider 10MHz --> 80MHz / 8  = 10MHz
    /* Enable peripheral divider */
    Cy_SysClk_PeriphEnableDivider(CY_SYSCLK_DIV_24_5_BIT, CPUS_PERI_DIV_CMD_DIV_SEL_SCB7);


    /*ADC  Clock configuration*/
    /*PCLK_PASS0_CLOCK_SAR0*/
    Cy_SysClk_PeriphAssignDivider(PCLK_PASS0_CLOCK_SAR0, CY_SYSCLK_DIV_16_BIT, CPUS_PERI_CLOCK_CTL_DIV_SEL_PASS0_SAR0);
    Cy_SysClk_PeriphSetDivider(CY_SYSCLK_DIV_16_BIT, CPUS_PERI_CLOCK_DIV_16_CHANNEL0, CPUS_PERIDIV_16_CTL_INT16_DIV_PASS0_SAR0);
    Cy_SysClk_PeriphEnableDivider(CY_SYSCLK_DIV_16_BIT, CPUS_PERI_DIV_CMD_DIV_SEL_PASS0_SAR0);

    /*PCLK_PASS0_CLOCK_SAR1*/
    Cy_SysClk_PeriphAssignDivider(PCLK_PASS0_CLOCK_SAR1, CY_SYSCLK_DIV_16_BIT, CPUS_PERI_CLOCK_CTL_DIV_SEL_PASS0_SAR1);
    Cy_SysClk_PeriphSetDivider(CY_SYSCLK_DIV_16_BIT, CPUS_PERI_CLOCK_DIV_16_CHANNEL1, CPUS_PERIDIV_16_CTL_INT16_DIV_PASS0_SAR1);
    Cy_SysClk_PeriphEnableDivider(CY_SYSCLK_DIV_16_BIT, CPUS_PERI_DIV_CMD_DIV_SEL_PASS0_SAR1);

    /*PCLK_PASS0_CLOCK_SAR2*/
    Cy_SysClk_PeriphAssignDivider(PCLK_PASS0_CLOCK_SAR2, CY_SYSCLK_DIV_16_BIT, CPUS_PERI_CLOCK_CTL_DIV_SEL_PASS0_SAR2);
    Cy_SysClk_PeriphSetDivider(CY_SYSCLK_DIV_16_BIT, CPUS_PERI_CLOCK_DIV_16_CHANNEL2, CPUS_PERIDIV_16_CTL_INT16_DIV_PASS0_SAR2);
    Cy_SysClk_PeriphEnableDivider(CY_SYSCLK_DIV_16_BIT, CPUS_PERI_DIV_CMD_DIV_SEL_PASS0_SAR2);
#endif

}



/*______ E N D _____ (cpus_config_tviibe2m_cm0plus.c) __________________________________________*/
