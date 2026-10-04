/******************************************************************************/
/*@F_NAME:           spid_config_tv2.h                                                                                                        */
/*@F_PURPOSE:        SPI Driver Module                                                                                                    */
/*@F_CREATED_BY:     Wei Liang                                                                                                                  */
/*@F_CREATION_DATE:  2020/10/26                                                                                                        */
/*@F_LANGUAGE :      ANSI C                                                                                                                        */
/*@F_MPROC_TYPE:     Cypress Traveo II series                                                                                     */
/********************************************** (C) Copyright 2020 Marelli *********/
#ifndef SPID_CONFIG_TV2_H
#define SPID_CONFIG_TV2_H


/*______ I N C L U D E - F I L E S ___________________________________________*/
#include "spic_config.h"
#include "cy_scb_spi.h"
#include "SbcM.h"
/*______ G L O B A L - D E F I N E S _________________________________________*/


/*______ G L O B A L - T Y P E S _____________________________________________*/
#define    SPID_PHYS_CHANNEL0        SPIC_PHYS_CHANNEL0
#define    SPID_PHYS_CHANNEL1        SPIC_PHYS_CHANNEL1
#define    SPID_PHYS_CHANNEL2        SPIC_PHYS_CHANNEL2
#define    SPID_PHYS_CHANNEL3        SPIC_PHYS_CHANNEL3
#define    SPID_PHYS_CHANNEL4        SPIC_PHYS_CHANNEL4
#define    SPID_PHYS_CHANNEL5        SPIC_PHYS_CHANNEL5
#define    SPID_PHYS_CHANNEL6        SPIC_PHYS_CHANNEL6
#define    SPID_PHYS_CHANNEL7        SPIC_PHYS_CHANNEL7



/*______ G L O B A L - D A T A _______________________________________________*/
#if (SPID_PHYS_CHANNEL0  == _USED_)
extern const cy_stc_scb_spi_config_t Spid_SpiCfgScb0;
#endif
#if (SPID_PHYS_CHANNEL1  == _USED_)
extern const cy_stc_scb_spi_config_t Spid_SpiCfgScb1;
#endif
#if (SPID_PHYS_CHANNEL2  == _USED_)
extern const cy_stc_scb_spi_config_t Spid_SpiCfgScb2;
#endif
#if (SPID_PHYS_CHANNEL3  == _USED_)
extern const cy_stc_scb_spi_config_t Spid_SpiCfgScb3;
#endif
#if (SPID_PHYS_CHANNEL4  == _USED_)
extern const cy_stc_scb_spi_config_t Spid_SpiCfgScb4;
#endif
#if (SPID_PHYS_CHANNEL5  == _USED_)
extern const cy_stc_scb_spi_config_t Spid_SpiCfgScb5;
#endif
#if (SPID_PHYS_CHANNEL6  == _USED_)
extern const cy_stc_scb_spi_config_t Spid_SpiCfgScb6;
#endif
#if (SPID_PHYS_CHANNEL7  == _USED_)
extern const cy_stc_scb_spi_config_t Spid_SpiCfgScb7;
#endif

/*______ G L O B A L - M A C R O S ___________________________________________*/
/*#define SPIC_TRANSFER_COMPLETE_CBK_CH0*/
/*#define SPIC_TRANSFER_ERR_CBK_CH0*/
/*#define SPID_TransferCompleteCbkCh0*/
/*#define SPID_TransferErrCbkCh0*/

/*#define SPIC_TRANSFER_COMPLETE_CBK_CH1*/
/*#define SPIC_TRANSFER_ERR_CBK_CH1*/
/*#define SPID_TransferCompleteCbkCh1*/
/*#define SPID_TransferErrCbkCh1*/

/*#define SPIC_TRANSFER_COMPLETE_CBK_CH2*/
/*#define SPIC_TRANSFER_ERR_CBK_CH2*/
/*#define SPID_TransferCompleteCbkCh2*/
/*#define SPID_TransferErrCbkCh2*/

/*#define SPIC_TRANSFER_COMPLETE_CBK_CH3*/
/*#define SPIC_TRANSFER_ERR_CBK_CH3*/
/*#define SPID_TransferCompleteCbkCh3*/
/*#define SPID_TransferErrCbkCh3*/

/*#define SPIC_TRANSFER_COMPLETE_CBK_CH4*/
/*#define SPIC_TRANSFER_ERR_CBK_CH4*/
/*#define SPID_TransferCompleteCbkCh4*/
/*#define SPID_TransferErrCbkCh4*/

#define SPIC_TRANSFER_COMPLETE_CBK_CH2
#define SPIC_TRANSFER_ERR_CBK_CH2
#define SPID_TransferCompleteCbkCh2     SbcM_SpiTransferCompleteCallback
#define SPID_TransferErrCbkCh2          SbcM_SpiTransferErrorCallback

/*#define SPIC_TRANSFER_COMPLETE_CBK_CH6*/
/*#define SPIC_TRANSFER_ERR_CBK_CH6*/
/*#define SPID_TransferCompleteCbkCh6*/
/*#define SPID_TransferErrCbkCh6*/

/*#define SPIC_TRANSFER_COMPLETE_CBK_CH7*/
/*#define SPIC_TRANSFER_ERR_CBK_CH7*/
/*#define SPID_TransferCompleteCbkCh7*/
/*#define SPID_TransferErrCbkCh7*/

/*SCB0 Port pin configuration*/
#define   SPID_MISO_PORT_MUX_CHANNEL0         P0_0_SCB0_SPI_MISO
#define   SPID_MOSI_PORT_MUX_CHANNEL0         P0_1_SCB0_SPI_MOSI
#define   SPID_CLK_PORT_MUX_CHANNEL0          P0_2_SCB0_SPI_CLK
#define   SPID_SCB_MISO_PORT_CHANNEL0         GPIO_PRT0
#define   SPID_SCB_MISO_PORT_PIN_CHANNEL0     (0)
#define   SPID_SCB_MOSI_PORT_CHANNEL0         GPIO_PRT0
#define   SPID_SCB_MOSI_PORT_PIN_CHANNEL0     (1)
#define   SPID_SCB_CLK_PORT_CHANNEL0          GPIO_PRT0
#define   SPID_SCB_CLK_PORT_PIN_CHANNEL0      (2)
#define   SPID_GPIO_MISO_DM_CHANNEL0          CY_GPIO_DM_HIGHZ
#define   SPID_GPIO_MOSI_DM_CHANNEL0          CY_GPIO_DM_STRONG_IN_OFF
#define   SPID_GPIO_CLK_DM_CHANNEL0           CY_GPIO_DM_STRONG_IN_OFF

/*SCB1 Port pin configuration*/
#define   SPID_MISO_PORT_MUX_CHANNEL1         P18_0_SCB1_SPI_MISO
#define   SPID_MOSI_PORT_MUX_CHANNEL1         P18_1_SCB1_SPI_MOSI
#define   SPID_CLK_PORT_MUX_CHANNEL1          P18_2_SCB1_SPI_CLK
#define   SPID_SCB_MISO_PORT_CHANNEL1         GPIO_PRT18
#define   SPID_SCB_MISO_PORT_PIN_CHANNEL1     (0)
#define   SPID_SCB_MOSI_PORT_CHANNEL1         GPIO_PRT18
#define   SPID_SCB_MOSI_PORT_PIN_CHANNEL1     (1)
#define   SPID_SCB_CLK_PORT_CHANNEL1          GPIO_PRT18
#define   SPID_SCB_CLK_PORT_PIN_CHANNEL1      (2)
#define   SPID_GPIO_MISO_DM_CHANNEL1          CY_GPIO_DM_HIGHZ
#define   SPID_GPIO_MOSI_DM_CHANNEL1          CY_GPIO_DM_STRONG_IN_OFF
#define   SPID_GPIO_CLK_DM_CHANNEL1           CY_GPIO_DM_STRONG_IN_OFF

/*SCB2 Port pin configuration*/
#define   SPID_MISO_PORT_MUX_CHANNEL2         P19_0_SCB2_SPI_MISO
#define   SPID_MOSI_PORT_MUX_CHANNEL2         P19_1_SCB2_SPI_MOSI
#define   SPID_CLK_PORT_MUX_CHANNEL2          P19_2_SCB2_SPI_CLK
#define   SPID_SCB_MISO_PORT_CHANNEL2         GPIO_PRT19
#define   SPID_SCB_MISO_PORT_PIN_CHANNEL2     (0)
#define   SPID_SCB_MOSI_PORT_CHANNEL2         GPIO_PRT19
#define   SPID_SCB_MOSI_PORT_PIN_CHANNEL2     (1)
#define   SPID_SCB_CLK_PORT_CHANNEL2          GPIO_PRT19
#define   SPID_SCB_CLK_PORT_PIN_CHANNEL2      (2)
#define   SPID_GPIO_MISO_DM_CHANNEL2          CY_GPIO_DM_HIGHZ
#define   SPID_GPIO_MOSI_DM_CHANNEL2          CY_GPIO_DM_STRONG_IN_OFF
#define   SPID_GPIO_CLK_DM_CHANNEL2           CY_GPIO_DM_STRONG_IN_OFF

/*SCB3 Port pin configuration*/
#define   SPID_MISO_PORT_MUX_CHANNEL3         P13_0_SCB3_SPI_MISO
#define   SPID_MOSI_PORT_MUX_CHANNEL3         P13_1_SCB3_SPI_MOSI
#define   SPID_CLK_PORT_MUX_CHANNEL3          P13_2_SCB3_SPI_CLK
#define   SPID_SCB_MISO_PORT_CHANNEL3         GPIO_PRT13
#define   SPID_SCB_MISO_PORT_PIN_CHANNEL3     (0)
#define   SPID_SCB_MOSI_PORT_CHANNEL3         GPIO_PRT13
#define   SPID_SCB_MOSI_PORT_PIN_CHANNEL3     (1)
#define   SPID_SCB_CLK_PORT_CHANNEL3          GPIO_PRT13
#define   SPID_SCB_CLK_PORT_PIN_CHANNEL3      (2)
#define   SPID_GPIO_MISO_DM_CHANNEL3          CY_GPIO_DM_HIGHZ
#define   SPID_GPIO_MOSI_DM_CHANNEL3          CY_GPIO_DM_STRONG_IN_OFF
#define   SPID_GPIO_CLK_DM_CHANNEL3           CY_GPIO_DM_STRONG_IN_OFF

/*SCB4 Port pin configuration*/
#define   SPID_MISO_PORT_MUX_CHANNEL4         P6_0_SCB4_SPI_MISO
#define   SPID_MOSI_PORT_MUX_CHANNEL4         P6_1_SCB4_SPI_MOSI
#define   SPID_CLK_PORT_MUX_CHANNEL4          P6_2_SCB4_SPI_CLK
#define   SPID_SCB_MISO_PORT_CHANNEL4         GPIO_PRT6
#define   SPID_SCB_MISO_PORT_PIN_CHANNEL4     (0)
#define   SPID_SCB_MOSI_PORT_CHANNEL4         GPIO_PRT6
#define   SPID_SCB_MOSI_PORT_PIN_CHANNEL4     (1)
#define   SPID_SCB_CLK_PORT_CHANNEL4          GPIO_PRT6
#define   SPID_SCB_CLK_PORT_PIN_CHANNEL4      (2)
#define   SPID_GPIO_MISO_DM_CHANNEL4          CY_GPIO_DM_HIGHZ
#define   SPID_GPIO_MOSI_DM_CHANNEL4          CY_GPIO_DM_STRONG_IN_OFF
#define   SPID_GPIO_CLK_DM_CHANNEL4           CY_GPIO_DM_STRONG_IN_OFF

/*SCB5 Port pin configuration*/
#define   SPID_MISO_PORT_MUX_CHANNEL5         P7_0_SCB5_SPI_MISO
#define   SPID_MOSI_PORT_MUX_CHANNEL5         P7_1_SCB5_SPI_MOSI
#define   SPID_CLK_PORT_MUX_CHANNEL5          P7_2_SCB5_SPI_CLK
#define   SPID_SCB_MISO_PORT_CHANNEL5         GPIO_PRT7
#define   SPID_SCB_MISO_PORT_PIN_CHANNEL5     (0)
#define   SPID_SCB_MOSI_PORT_CHANNEL5         GPIO_PRT7
#define   SPID_SCB_MOSI_PORT_PIN_CHANNEL5     (1)
#define   SPID_SCB_CLK_PORT_CHANNEL5          GPIO_PRT7
#define   SPID_SCB_CLK_PORT_PIN_CHANNEL5      (2)
#define   SPID_GPIO_MISO_DM_CHANNEL5          CY_GPIO_DM_HIGHZ
#define   SPID_GPIO_MOSI_DM_CHANNEL5          CY_GPIO_DM_STRONG_IN_OFF
#define   SPID_GPIO_CLK_DM_CHANNEL5           CY_GPIO_DM_STRONG_IN_OFF

/*SCB6 Port pin configuration*/
#define   SPID_MISO_PORT_MUX_CHANNEL6         P22_0_SCB6_SPI_MISO
#define   SPID_MOSI_PORT_MUX_CHANNEL6         P22_1_SCB6_SPI_MOSI
#define   SPID_CLK_PORT_MUX_CHANNEL6          P22_2_SCB6_SPI_CLK
#define   SPID_SCB_MISO_PORT_CHANNEL6         GPIO_PRT22
#define   SPID_SCB_MISO_PORT_PIN_CHANNEL6     (0)
#define   SPID_SCB_MOSI_PORT_CHANNEL6         GPIO_PRT22
#define   SPID_SCB_MOSI_PORT_PIN_CHANNEL6     (1)
#define   SPID_SCB_CLK_PORT_CHANNEL6          GPIO_PRT22
#define   SPID_SCB_CLK_PORT_PIN_CHANNEL6      (2)
#define   SPID_GPIO_MISO_DM_CHANNEL6          CY_GPIO_DM_HIGHZ
#define   SPID_GPIO_MOSI_DM_CHANNEL6          CY_GPIO_DM_STRONG_IN_OFF
#define   SPID_GPIO_CLK_DM_CHANNEL6           CY_GPIO_DM_STRONG_IN_OFF

/*SCB7 Port pin configuration*/
#define   SPID_MISO_PORT_MUX_CHANNEL7         P2_0_SCB7_SPI_MISO
#define   SPID_MOSI_PORT_MUX_CHANNEL7         P2_1_SCB7_SPI_MOSI
#define   SPID_CLK_PORT_MUX_CHANNEL7          P2_2_SCB7_SPI_CLK
#define   SPID_SCB_MISO_PORT_CHANNEL7         GPIO_PRT2
#define   SPID_SCB_MISO_PORT_PIN_CHANNEL7     (0)
#define   SPID_SCB_MOSI_PORT_CHANNEL7         GPIO_PRT2
#define   SPID_SCB_MOSI_PORT_PIN_CHANNEL7     (1)
#define   SPID_SCB_CLK_PORT_CHANNEL7          GPIO_PRT2
#define   SPID_SCB_CLK_PORT_PIN_CHANNEL7      (2)
#define   SPID_GPIO_MISO_DM_CHANNEL7          CY_GPIO_DM_HIGHZ
#define   SPID_GPIO_MOSI_DM_CHANNEL7          CY_GPIO_DM_STRONG_IN_OFF
#define   SPID_GPIO_CLK_DM_CHANNEL7           CY_GPIO_DM_STRONG_IN_OFF

/*SPI Slave select*/
#define   SPID_SLAVE_SELECT_CHANNEL0               0U
#define   SPID_SLAVE_SELECT_CHANNEL1               0U
#define   SPID_SLAVE_SELECT_CHANNEL2               0U
#define   SPID_SLAVE_SELECT_CHANNEL3               0U
#define   SPID_SLAVE_SELECT_CHANNEL4               0U
#define   SPID_SLAVE_SELECT_CHANNEL5               0U
#define   SPID_SLAVE_SELECT_CHANNEL6               0U
#define   SPID_SLAVE_SELECT_CHANNEL7               0U

/*______ G L O B A L - F U N C T I O N S - P R O T O T Y P E S _______________*/


#endif /* SPID_CONFIG_TV2_H */


/*______ E N D _____ (xxxx_config.h) _________________________________________*/

