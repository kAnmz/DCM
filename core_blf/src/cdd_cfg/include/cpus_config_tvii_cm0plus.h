/******************************************************************************/
/*@F_NAME:           cpus_config_tviibe2m_cm0plus.h                                      									   */
/*@F_PURPOSE:        Configuration File for CPUS Module - TEMPLATE            								   */
/*@F_CREATED_BY:     WeiLiang                                                      															   */
/*@F_CREATION_DATE:  20/08/2020                                              														   */
/*@F_LANGUAGE :      C                                                        																		   */
/*@F_MPROC_TYPE:    Cypress TraveoII                                                                                                    */
/******************************* (C) Copyright 2020 Magneti Marelli ****************/
#ifndef CPUS_CONFIG_TVIIBE2M_CM0PLUS_H
#define CPUS_CONFIG_TVIIBE2M_CM0PLUS_H


/*______ I N C L U D E - F I L E S ___________________________________________*/
#include "cy_device_headers.h"
#include "math.h"

/*_____G L O B A L - D E F I N E _____________________________________________*/
#define CPUS_SYSTEM_USE_CLOCK                     CPUS_SYSTEM_USE_ECO
/* Macro to select the Clock Source*/
#define CPUS_SYSTEM_USE_IMO                       0
#define CPUS_SYSTEM_USE_EXT                        1
#define CPUS_SYSTEM_USE_ECO                       2

#if (CY_USE_PSVP == 1)
    #define CPUS_INITIAL_TARGET_FAST_FREQ        			 (24000000UL)
    #define CPUS_INITIAL_TARGET_PERI_FREQ         			 (24000000UL)
    #define CPUS_INITIAL_TARGET_SLOW_FREQ         		     (24000000UL)
    #define CPUS_CLK_ECO_FREQ_HZ                  					 (10000000UL)
    #define CPUS_CLK_IMO_FREQ_HZ                  					 (24000000UL)
    /** WCO frequency in Hz */
    #define CPUS_CLK_WCO_FREQ_HZ                  				 (32900UL)
#else
    #define CPUS_INITIAL_TARGET_FAST_FREQ         			(160000000UL)
    #define CPUS_INITIAL_TARGET_PERI_FREQ         			(80000000UL)
    #define CPUS_INITIAL_TARGET_SLOW_FREQ         		    (80000000UL)
    #define CPUS_CLK_ECO_FREQ_HZ                  				    	(16000000UL)
    #define CPUS_CLK_IMO_FREQ_HZ                  					( 8000000UL)
    /** WCO frequency in Hz */
    #define CPUS_CLK_WCO_FREQ_HZ                  				(32768UL)
#endif
/** HVILO0 frequency in Hz */
#define CPUS_CLK_HVILO0_FREQ_HZ                   				(32768UL)
/** HVILO1 frequency in Hz */
#define CPUS_CLK_HVILO1_FREQ_HZ                  				(32768UL)
#define CPUS_CLK_EXT_FREQ_HZ                          				(16000000UL)



#if CPUS_SYSTEM_USE_CLOCK == CPUS_SYSTEM_USE_ECO
    #define CPUS_SYSTEM_PLL_INPUT_SOURCE       CY_SYSCLK_CLKPATH_IN_ECO
     /*Reference divider value:  2
     Feed back divider value: 40
     Out put divider value  :  2
     PLL_OUT = 16,000,000(Feco) / 2 * 40 / 2 = 160,000,000Hz
     Restriction: 300,000,000 < Fvco < 400,000,000
     This time, Fvco = 16,000,000 *40 /2 = 320,000,000.*/
    #define CPUS_SYSTEM_PLL_CONFIG_REFDIV      (2UL)
    #define CPUS_SYSTEM_PLL_CONFIG_OUTDIV      (2UL)

    #define CPUS_SYSTEM_FAST_INT_DIV               (0U)
    #define CPUS_SYSTEM_PERI_INT_DIV                (1U)
    #define CPUS_SYSTEM_LOW_INT_DIV               (0U)
    #define CPUS_SYSTEM_ROOT_DIV                       (0U)

    #define CPUS_SYSTEM_PLL_CONFIG_FEEDBACKDIV     \
                   ( (CPUS_INITIAL_TARGET_FAST_FREQ * CPUS_SYSTEM_PLL_CONFIG_REFDIV * CPUS_SYSTEM_PLL_CONFIG_OUTDIV * \
                      (1+CPUS_SYSTEM_FAST_INT_DIV) * (pow(2,CPUS_SYSTEM_ROOT_DIV)) ) / CPUS_CLK_ECO_FREQ_HZ)

#elif CPUS_SYSTEM_USE_CLOCK == CPUS_SYSTEM_USE_IMO
    #define CPUS_SYSTEM_PLL_INPUT_SOURCE CY_SYSCLK_CLKPATH_IN_IMO

    // Reference divider value:  1
    // Feed back divider value: 40
    // Out put divider value  :  2
    // PLL_OUT = 8,000,000(Fimo) / 1 * 40 / 2 = 160,000,000Hz

    // Restriction: 300,000,000 < Fvco < 400,000,000
    // This time, Fvco = 8,000,000 * 40 / 1 = 320,000,000.
    #define CPUS_SYSTEM_PLL_CONFIG_REFDIV      (1UL)
    #define CPUS_SYSTEM_PLL_CONFIG_OUTDIV      (2UL)

    #define CPUS_SYSTEM_FAST_INT_DIV               (0U)
    #define CPUS_SYSTEM_PERI_INT_DIV               (1U)
    #define CPUS_SYSTEM_LOW_INT_DIV               (0U)
    #define CPUS_SYSTEM_ROOT_DIV                       (0U)

    #define CPUS_SYSTEM_PLL_CONFIG_FEEDBACKDIV     \
                   ( (CPUS_INITIAL_TARGET_FAST_FREQ * CPUS_SYSTEM_PLL_CONFIG_REFDIV * CPUS_SYSTEM_PLL_CONFIG_OUTDIV * \
                      (1+CPUS_SYSTEM_FAST_INT_DIV) * (pow(2,CPUS_SYSTEM_ROOT_DIV)) ) / CPUS_CLK_ECO_FREQ_HZ)

#elif CPUS_SYSTEM_USE_CLOCK == CPUS_SYSTEM_USE_EXT

    #warning "Not implemented yet!!"

#endif

#if 0
#define CPUS_PERI_CLOCK_CTL_DIV_SEL_SCB0                          0U /*No divider*/
#define CPUS_PERI_CLOCK_CTL_DIV_SEL_SCB1                          0U /*No divider*/
#define CPUS_PERI_CLOCK_CTL_DIV_SEL_SCB2                          0U /*No divider*/
#define CPUS_PERI_CLOCK_CTL_DIV_SEL_SCB3                          0U /*No divider*/
#define CPUS_PERI_CLOCK_CTL_DIV_SEL_SCB4                          0U /*No divider*/
#define CPUS_PERI_CLOCK_CTL_DIV_SEL_SCB5                          0U /*No divider*/
#define CPUS_PERI_CLOCK_CTL_DIV_SEL_SCB6                          0U /*No divider*/
#define CPUS_PERI_CLOCK_CTL_DIV_SEL_SCB7                          0U /*No divider*/

#define CPUS_PERI_CLOCK_CTL_DIV_SEL_PASS0_SAR0            0U /*No divider*/
#define CPUS_PERI_CLOCK_CTL_DIV_SEL_PASS0_SAR1            0U /*No divider*/
#define CPUS_PERI_CLOCK_CTL_DIV_SEL_PASS0_SAR2            0U /*No divider*/

#define CPUS_PERI_DIV_16_5_CTL_INT16_DIV_SCB0              7U/*Integer division by (1+INT16_DIV) = 8 */
#define CPUS_PERI_DIV_16_5_CTL_INT16_DIV_SCB1              7U/*Integer division by (1+INT16_DIV) = 8 */
#define CPUS_PERI_DIV_16_5_CTL_INT16_DIV_SCB2              7U/*Integer division by (1+INT16_DIV) = 8 */
#define CPUS_PERI_DIV_16_5_CTL_INT16_DIV_SCB3              85U/*Integer division by (1+INT16_DIV) = 86 */
#define CPUS_PERI_DIV_16_5_CTL_INT16_DIV_SCB4              7U/*Integer division by (1+INT16_DIV) = 8 */
#define CPUS_PERI_DIV_16_5_CTL_INT16_DIV_SCB5              7U/*Integer division by (1+INT16_DIV) = 8 */
#define CPUS_PERI_DIV_16_5_CTL_INT16_DIV_SCB6              7U/*Integer division by (1+INT16_DIV) = 8 */
#define CPUS_PERI_DIV_16_5_CTL_INT16_DIV_SCB7              7U/*Integer division by (1+INT16_DIV) = 8 */

#define CPUS_PERI_DIV_16_5_CTL_FRAC5_DIV_SCB0             0U/*Fractional division by (FRAC5_DIV/32) = 0/32 = 0*/
#define CPUS_PERI_DIV_16_5_CTL_FRAC5_DIV_SCB1             0U/*Fractional division by (FRAC5_DIV/32) = 0/32 = 0*/
#define CPUS_PERI_DIV_16_5_CTL_FRAC5_DIV_SCB2             0U/*Fractional division by (FRAC5_DIV/32) = 0/32 = 0*/
#define CPUS_PERI_DIV_16_5_CTL_FRAC5_DIV_SCB3             26U/*Fractional division by (FRAC5_DIV/32) = 26/32 = 0.8125*/
#define CPUS_PERI_DIV_16_5_CTL_FRAC5_DIV_SCB4             0U/*Fractional division by (FRAC5_DIV/32) = 0/32 = 0*/
#define CPUS_PERI_DIV_16_5_CTL_FRAC5_DIV_SCB5             0U/*Fractional division by (FRAC5_DIV/32) = 0/32 = 0*/
#define CPUS_PERI_DIV_16_5_CTL_FRAC5_DIV_SCB6             0U/*Fractional division by (FRAC5_DIV/32) = 0/32 = 0*/
#define CPUS_PERI_DIV_16_5_CTL_FRAC5_DIV_SCB7             0U/*Fractional division by (FRAC5_DIV/32) = 0/32 = 0*/

#define CPUS_PERI_DIV_CMD_DIV_SEL_SCB0                             0U /*No divider*/
#define CPUS_PERI_DIV_CMD_DIV_SEL_SCB1                             0U /*No divider*/
#define CPUS_PERI_DIV_CMD_DIV_SEL_SCB2                             0U /*No divider*/
#define CPUS_PERI_DIV_CMD_DIV_SEL_SCB3                             0U /*No divider*/
#define CPUS_PERI_DIV_CMD_DIV_SEL_SCB4                             0U /*No divider*/
#define CPUS_PERI_DIV_CMD_DIV_SEL_SCB5                             0U /*No divider*/
#define CPUS_PERI_DIV_CMD_DIV_SEL_SCB6                             0U /*No divider*/
#define CPUS_PERI_DIV_CMD_DIV_SEL_SCB7                             0U /*No divider*/


#define  CPUS_PERIDIV_16_CTL_INT16_DIV_PASS0_SAR0       7U/*Integer division by (1+INT16_DIV) = 8 */
#define  CPUS_PERIDIV_16_CTL_INT16_DIV_PASS0_SAR1       7U/*Integer division by (1+INT16_DIV) = 8 */
#define  CPUS_PERIDIV_16_CTL_INT16_DIV_PASS0_SAR2       7U/*Integer division by (1+INT16_DIV) = 8 */

#define CPUS_PERI_DIV_CMD_DIV_SEL_PASS0_SAR0                0U /*No divider*/
#define CPUS_PERI_DIV_CMD_DIV_SEL_PASS0_SAR1                0U /*No divider*/
#define CPUS_PERI_DIV_CMD_DIV_SEL_PASS0_SAR2                0U /*No divider*/
#endif
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
extern void CPUS_InitPeripheralClockConfig (void);


#endif /* CPUS_CONFIG_TVIIBE2M_CM0PLUS_H */
