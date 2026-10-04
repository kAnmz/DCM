/******************************************************************************/
/*@F_NAME:           spid_config_tv2.h                                                                                                        */
/*@F_PURPOSE:        SPI Driver Module                                                                                                    */
/*@F_CREATED_BY:     Wei Liang                                                                                                                  */
/*@F_CREATION_DATE:  2020/10/26                                                                                                        */
/*@F_LANGUAGE :      ANSI C                                                                                                                        */
/*@F_MPROC_TYPE:     Cypress Traveo II series                                                                                     */
/********************************************** (C) Copyright 2020 Marelli *********/
#ifndef SCB_CONFIG_TV2_H
#define SCB_CONFIG_TV2_H


/*______ I N C L U D E - F I L E S ___________________________________________*/
#include "syst.h"
#include "cy_sysclk.h"
#include "cy_gpio.h"
#include "cpus_config_tvii.h"

/*______ G L O B A L - D E F I N E S _________________________________________*/
/*Because SPI/UART/I2C function was integrated in SCB module, Only one of the protocols is
supported by an SCB at any given time. So any SCB channel should be configured before used*/
#define    SCB_FUNCTION_NOT_USED            0
#define    SCB_SPI_FUNCTION_USED            1
#define    SCB_UART_FUNCTION_USED           2
#define    SCB_I2C_FUNCTION_USED            3

/*Because SPI/UART/I2C function was integrated in SCB module, Only one of the protocols is
supported by an SCB at any given time. So any SCB channel should be configured before used*/
#define    SCB_FUNCTION_USED_CHANNEL0      SCB_FUNCTION_NOT_USED
#define    SCB_FUNCTION_USED_CHANNEL1      SCB_FUNCTION_NOT_USED
#define    SCB_FUNCTION_USED_CHANNEL2      SCB_SPI_FUNCTION_USED
#define    SCB_FUNCTION_USED_CHANNEL3      SCB_UART_FUNCTION_USED
#define    SCB_FUNCTION_USED_CHANNEL4      SCB_SPI_FUNCTION_USED
#define    SCB_FUNCTION_USED_CHANNEL5      SCB_FUNCTION_NOT_USED
#define    SCB_FUNCTION_USED_CHANNEL6      SCB_FUNCTION_NOT_USED
#define    SCB_FUNCTION_USED_CHANNEL7      SCB_UART_FUNCTION_USED

/*SCB0 Clock configuration macro*/
#define   SCB_SYSCLK_DIV_TYPE_CHANNEL0         CY_SYSCLK_DIV_24_5_BIT
#define   SCB_CLOCK_CTL_DIV_SEL_CHANNEL0       (0u)
#define   SCB_PERI_CLOCK_DIV_CHANNEL0          CPUS_PERI_CLOCK_DIV_24_5_CHANNEL0
#define   SCB_INT_DIV_CHANNEL0                 (4u)
#define   SCB_DIV_CMD_DIV_SEL_CHANNEL0         (0u)
#define   SCB_FRAC_DIV_CHANNEL0                (0u)

/*SCB1 Clock configuration macro*/
#define   SCB_SYSCLK_DIV_TYPE_CHANNEL1         CY_SYSCLK_DIV_24_5_BIT
#define   SCB_CLOCK_CTL_DIV_SEL_CHANNEL1       (1u)
#define   SCB_PERI_CLOCK_DIV_CHANNEL1          CPUS_PERI_CLOCK_DIV_24_5_CHANNEL1
#define    SCB_INT_DIV_CHANNEL1                (4u)
#define   SCB_DIV_CMD_DIV_SEL_CHANNEL1         (1u)
#define   SCB_FRAC_DIV_CHANNEL1                (0u)

/*SCB2 Clock configuration macro*/
#define   SCB_SYSCLK_DIV_TYPE_CHANNEL2         CY_SYSCLK_DIV_24_5_BIT
#define   SCB_CLOCK_CTL_DIV_SEL_CHANNEL2       (1u)
#define   SCB_PERI_CLOCK_DIV_CHANNEL2          CPUS_PERI_CLOCK_DIV_24_5_CHANNEL2
#define    SCB_INT_DIV_CHANNEL2                (4u)//(4u)
#define   SCB_DIV_CMD_DIV_SEL_CHANNEL2         (1u)
#define   SCB_FRAC_DIV_CHANNEL2                (0u)//(0u)

/*SCB3 Clock configuration macro*/
#define   SCB_SYSCLK_DIV_TYPE_CHANNEL3         CY_SYSCLK_DIV_24_5_BIT
#define   SCB_CLOCK_CTL_DIV_SEL_CHANNEL3       (1u)
#define   SCB_PERI_CLOCK_DIV_CHANNEL3          CPUS_PERI_CLOCK_DIV_24_5_CHANNEL3
#define   SCB_INT_DIV_CHANNEL3                 (4u)
#define   SCB_DIV_CMD_DIV_SEL_CHANNEL3         (1u)
#define   SCB_FRAC_DIV_CHANNEL3                (0u)

/*SCB4 Clock configuration macro*/
#define   SCB_SYSCLK_DIV_TYPE_CHANNEL4         CY_SYSCLK_DIV_24_5_BIT
#define   SCB_CLOCK_CTL_DIV_SEL_CHANNEL4       (1u)
#define   SCB_PERI_CLOCK_DIV_CHANNEL4          CPUS_PERI_CLOCK_DIV_24_5_CHANNEL4
#define   SCB_INT_DIV_CHANNEL4                 (4u)
#define   SCB_DIV_CMD_DIV_SEL_CHANNEL4         (1u)
#define   SCB_FRAC_DIV_CHANNEL4                (0u)

/*SCB5 Clock configuration macro*/
#define   SCB_SYSCLK_DIV_TYPE_CHANNEL5         CY_SYSCLK_DIV_24_5_BIT
#define   SCB_CLOCK_CTL_DIV_SEL_CHANNEL5       (5u)
#define   SCB_PERI_CLOCK_DIV_CHANNEL5          CPUS_PERI_CLOCK_DIV_24_5_CHANNEL5
#define   SCB_INT_DIV_CHANNEL5                 (4u)
#define   SCB_DIV_CMD_DIV_SEL_CHANNEL5         (5u)
#define   SCB_FRAC_DIV_CHANNEL5                (0u)

/*SCB6 Clock configuration macro*/
#define   SCB_SYSCLK_DIV_TYPE_CHANNEL6           CY_SYSCLK_DIV_24_5_BIT
#define   SCB_CLOCK_CTL_DIV_SEL_CHANNEL6         (1u)
#define   SCB_PERI_CLOCK_DIV_CHANNEL6            CPUS_PERI_CLOCK_DIV_24_5_CHANNEL6
#define   SCB_INT_DIV_CHANNEL6                   (4u)
#define   SCB_DIV_CMD_DIV_SEL_CHANNEL6           (1u)
#define   SCB_FRAC_DIV_CHANNEL6                  (0u)

/*SCB7 Clock configuration macro*/
#define   SCB_SYSCLK_DIV_TYPE_CHANNEL7          CY_SYSCLK_DIV_24_5_BIT
#define   SCB_CLOCK_CTL_DIV_SEL_CHANNEL7        (1u)
#define   SCB_PERI_CLOCK_DIV_CHANNEL7           CPUS_PERI_CLOCK_DIV_24_5_CHANNEL7
#define   SCB_INT_DIV_CHANNEL7                  (4u)
#define   SCB_DIV_CMD_DIV_SEL_CHANNEL7          (1u)
#define   SCB_FRAC_DIV_CHANNEL7                 (0u)

/*SCB0 interrupt configuration*/
#define   SCB_INT_ID_CHANNEL0               CPUIntIdx0_IRQn
#define   SCB_INT_SRC_CHANNEL0              scb_0_interrupt_IRQn
#define   SCB_IRQ_PRORITY_CHANNEL0          4U

/*SCB1 interrupt configuration*/
#define   SCB_INT_ID_CHANNEL1               CPUIntIdx1_IRQn
#define   SCB_INT_SRC_CHANNEL1              scb_1_interrupt_IRQn
#define   SCB_IRQ_PRORITY_CHANNEL1          4U

/*SCB2 interrupt configuration*/
#define   SCB_INT_ID_CHANNEL2               CPUIntIdx2_IRQn
#define   SCB_INT_SRC_CHANNEL2              scb_2_interrupt_IRQn
#define   SCB_IRQ_PRORITY_CHANNEL2          4U

/*SCB3 interrupt configuration*/
#define   SCB_INT_ID_CHANNEL3               CPUIntIdx3_IRQn
#define   SCB_INT_SRC_CHANNEL3              scb_3_interrupt_IRQn
#define   SCB_IRQ_PRORITY_CHANNEL3          4U

/*SCB4 interrupt configuration*/
#define   SCB_INT_ID_CHANNEL4               CPUIntIdx4_IRQn
#define   SCB_INT_SRC_CHANNEL4              scb_4_interrupt_IRQn
#define   SCB_IRQ_PRORITY_CHANNEL4          4U

/*SCB5 interrupt configuration*/
#define   SCB_INT_ID_CHANNEL5               CPUIntIdx5_IRQn
#define   SCB_INT_SRC_CHANNEL5              scb_5_interrupt_IRQn
#define   SCB_IRQ_PRORITY_CHANNEL5          4U

/*SCB6 interrupt configuration*/
#define   SCB_INT_ID_CHANNEL6               CPUIntIdx6_IRQn
#define   SCB_INT_SRC_CHANNEL6              scb_6_interrupt_IRQn
#define   SCB_IRQ_PRORITY_CHANNEL6          4U

/*SCB7 interrupt configuration*/
#define   SCB_INT_ID_CHANNEL7               CPUIntIdx7_IRQn
#define   SCB_INT_SRC_CHANNEL7              scb_7_interrupt_IRQn
#define   SCB_IRQ_PRORITY_CHANNEL7          4U

/*SCB channel macro*/
#define   SCB_CHANNEL0        0U
#define   SCB_CHANNEL1        1U
#define   SCB_CHANNEL2        2U
#define   SCB_CHANNEL3        3U
#define   SCB_CHANNEL4        4U
#define   SCB_CHANNEL5        5U
#define   SCB_CHANNEL6        6U
#define   SCB_CHANNEL7        7U
/*______ G L O B A L - T Y P E S _____________________________________________*/

/*______ G L O B A L - D A T A _______________________________________________*/

/*______ G L O B A L - M A C R O S ___________________________________________*/


/*______ G L O B A L - F U N C T I O N S - P R O T O T Y P E S _______________*/


#endif /* SCB_CONFIG_TV2_H */


/*______ E N D _____ (xxxx_config.h) _________________________________________*/

