/******************************************************************************/
/*@F_NAME:           spid_tv2.c                                                                                                                       */
/*@F_PURPOSE:        SPI Driver Module                                                                                                    */
/*@F_CREATED_BY:     Wei Liang                                                                                                                  */
/*@F_CREATION_DATE:  2020/10/26                                                                                                        */
/*@F_LANGUAGE :      ANSI C                                                                                                                        */
/*@F_MPROC_TYPE:     Cypress Traveo II series                                                                                     */
/********************************************** (C) Copyright 2020 Marelli *********/


/*______ I N C L U D E - F I L E S ___________________________________________*/
#include "syst.h"
#include "cy_scb_spi.h"
#include "spid_tv2.h"
#include "scb_config_tv2.h"
#include "spid_config_tv2.h"
#include "cy_sysint.h"
#include "cy_sysclk.h"
#include "Platform_Types.h"
#include "cy_device_headers.h"
/*______ L O C A L - D E F I N E S ___________________________________________*/
#define SCB_SPI_BAUDRATE 500000ul  /* Please set baudrate value of SPI you want */
#define SCB_SPI_OVERSAMPLING 16ul   /* Please set oversampling of SPI you want */
#define SCB_SPI_CLOCK_FREQ (SCB_SPI_BAUDRATE * SCB_SPI_OVERSAMPLING)
#define SOURCE_CLOCK_FRQ 80000000ul

void SetPeripheFracDiv24_5(uint64_t targetFreq, uint64_t sourceFreq, uint8_t divNum)
{
    uint64_t temp = ((uint64_t)sourceFreq << 5ull);
    uint32_t divSetting;

    divSetting = (uint32_t)(temp / targetFreq);
    Cy_SysClk_PeriphSetFracDivider(CY_SYSCLK_DIV_24_5_BIT, divNum,
                                   (((divSetting >> 5u) & 0x00000FFF) - 1u),
                                   (divSetting & 0x0000001F));
}

/*______ L O C A L - T Y P E S _______________________________________________*/


/*______ G L O B A L - D A T A _______________________________________________*/
#if (SPID_PHYS_CHANNEL0  == _USED_)
extern cy_stc_gpio_pin_config_t Spid_PortPinCfgScb0;
#endif

#if (SPID_PHYS_CHANNEL1  == _USED_)
extern cy_stc_gpio_pin_config_t Spid_PortPinCfgScb1;
#endif

#if (SPID_PHYS_CHANNEL2  == _USED_)
extern cy_stc_gpio_pin_config_t Spid_PortPinCfgScb2;
#endif

#if (SPID_PHYS_CHANNEL3  == _USED_)
extern cy_stc_gpio_pin_config_t Spid_PortPinCfgScb3;
#endif

#if (SPID_PHYS_CHANNEL4  == _USED_)
extern cy_stc_gpio_pin_config_t Spid_PortPinCfgScb4;
#endif

#if (SPID_PHYS_CHANNEL5  == _USED_)
extern cy_stc_gpio_pin_config_t Spid_PortPinCfgScb5;
#endif

#if (SPID_PHYS_CHANNEL6  == _USED_)
extern cy_stc_gpio_pin_config_t Spid_PortPinCfgScb6;
#endif

#if (SPID_PHYS_CHANNEL7  == _USED_)
extern cy_stc_gpio_pin_config_t Spid_PortPinCfgScb7;
#endif

/*______ P R I V A T E - D A T A _____________________________________________*/


/*______ L O C A L - D A T A _________________________________________________*/
#if (SPID_PHYS_CHANNEL0  == _USED_)
 cy_stc_scb_spi_context_t Spid_contextSCB0 = {0};
#endif

#if (SPID_PHYS_CHANNEL1  == _USED_)
 cy_stc_scb_spi_context_t Spid_contextSCB1 = {0};
#endif

#if (SPID_PHYS_CHANNEL2  == _USED_)
 cy_stc_scb_spi_context_t Spid_contextSCB2 = {0};
#endif

#if (SPID_PHYS_CHANNEL3  == _USED_)
 cy_stc_scb_spi_context_t Spid_contextSCB3 = {0};
#endif

#if (SPID_PHYS_CHANNEL4  == _USED_)
 cy_stc_scb_spi_context_t Spid_contextSCB4 = {0};
#endif

#if (SPID_PHYS_CHANNEL5  == _USED_)
 cy_stc_scb_spi_context_t Spid_contextSCB5 = {0};
#endif

#if (SPID_PHYS_CHANNEL6  == _USED_)
 cy_stc_scb_spi_context_t Spid_contextSCB6 = {0};
#endif

#if (SPID_PHYS_CHANNEL7  == _USED_)
 cy_stc_scb_spi_context_t Spid_contextSCB7 = {0};
#endif

#if (SPID_PHYS_CHANNEL0  == _USED_)
 SPID_TransmitState_t   SPID_TransmitState_Scb0 = SPID_TransmitNone;
#endif

#if (SPID_PHYS_CHANNEL1  == _USED_)
 SPID_TransmitState_t   SPID_TransmitState_Scb1 = SPID_TransmitNone;
#endif

#if (SPID_PHYS_CHANNEL2  == _USED_)
 SPID_TransmitState_t   SPID_TransmitState_Scb2 = SPID_TransmitNone;
#endif

#if (SPID_PHYS_CHANNEL3  == _USED_)
 SPID_TransmitState_t   SPID_TransmitState_Scb3 = SPID_TransmitNone;
#endif

#if (SPID_PHYS_CHANNEL4  == _USED_)
 SPID_TransmitState_t   SPID_TransmitState_Scb4 = SPID_TransmitNone;
#endif

#if (SPID_PHYS_CHANNEL5  == _USED_)
 SPID_TransmitState_t   SPID_TransmitState_Scb5 = SPID_TransmitNone;
#endif

#if (SPID_PHYS_CHANNEL6  == _USED_)
 SPID_TransmitState_t   SPID_TransmitState_Scb6 = SPID_TransmitNone;
#endif

#if (SPID_PHYS_CHANNEL7  == _USED_)
 SPID_TransmitState_t   SPID_TransmitState_Scb7 = SPID_TransmitNone;
#endif
/*______ L O C A L - M A C R O S _____________________________________________*/


/*______ I M P O R T - F U N C T I O N S - P R O T O T Y P E S _______________*/


/*______ L O C A L - F U N C T I O N S - P R O T O T Y P E S _________________*/
#if (SPID_PHYS_CHANNEL0  == _USED_)
 void Spid_SpiEventChannel0(uint32 locEvents);
#endif
#if (SPID_PHYS_CHANNEL1  == _USED_)
 void Spid_SpiEventChannel1(uint32 locEvents);
#endif
#if (SPID_PHYS_CHANNEL2  == _USED_)
 void Spid_SpiEventChannel2(uint32 locEvents);
#endif
#if (SPID_PHYS_CHANNEL3  == _USED_)
 void Spid_SpiEventChannel3(uint32 locEvents);
#endif
#if (SPID_PHYS_CHANNEL4  == _USED_)
 void Spid_SpiEventChannel4(uint32 locEvents);
#endif
#if (SPID_PHYS_CHANNEL5  == _USED_)
 void Spid_SpiEventChannel5(uint32 locEvents);
#endif
#if (SPID_PHYS_CHANNEL6  == _USED_)
 void Spid_SpiEventChannel6(uint32 locEvents);
#endif
#if (SPID_PHYS_CHANNEL7  == _USED_)
 void Spid_SpiEventChannel7(uint32 locEvents);
#endif

#if (SPID_PHYS_CHANNEL0  == _USED_)
 void Spid_IrqSCBChannel0(void);
#endif
#if (SPID_PHYS_CHANNEL1  == _USED_)
 void Spid_IrqSCBChannel1(void);
#endif
#if (SPID_PHYS_CHANNEL2  == _USED_)
 void Spid_IrqSCBChannel2(void);
#endif
#if (SPID_PHYS_CHANNEL3  == _USED_)
 void Spid_IrqSCBChannel3(void);
#endif
#if (SPID_PHYS_CHANNEL4  == _USED_)
 void Spid_IrqSCBChannel4(void);
#endif
#if (SPID_PHYS_CHANNEL5  == _USED_)
 void Spid_IrqSCBChannel5(void);
#endif
#if (SPID_PHYS_CHANNEL6  == _USED_)
 void Spid_IrqSCBChannel6(void);
#endif
#if (SPID_PHYS_CHANNEL7  == _USED_)
 void Spid_IrqSCBChannel7(void);
#endif


/*______ G L O B A L - F U N C T I O N S _____________________________________*/
 /******************************************************************************/
 /* Name: SPID_Init                                                            */
 /* Role: Initialise the module                                                */
 /* Interface: none                                                            */
 /* Pre-condition: none                                                        */
 /* Constraints: none                                                          */
 /* Behaviour:                                                                 */
 /* DO                                                                         */
 /*   [ Initialize hardware according to configuration ]                       */
 /* OD                                                                         */
 /******************************************************************************/
 void SPID_Init (void)
 {
#if (SPID_PHYS_CHANNEL0  == _USED_)
	 SPID_InitChannel(SCB_CHANNEL0);
#endif
#if (SPID_PHYS_CHANNEL1  == _USED_)
	 SPID_InitChannel(SCB_CHANNEL1);
#endif
#if (SPID_PHYS_CHANNEL2  == _USED_)
	 SPID_InitChannel(SCB_CHANNEL2);
#endif
#if (SPID_PHYS_CHANNEL3  == _USED_)
	 SPID_InitChannel(SCB_CHANNEL3);
#endif
#if (SPID_PHYS_CHANNEL4  == _USED_)
	 SPID_InitChannel(SCB_CHANNEL4);
#endif
#if (SPID_PHYS_CHANNEL5  == _USED_)
	 SPID_InitChannel(SCB_CHANNEL5);
#endif
#if (SPID_PHYS_CHANNEL6  == _USED_)
	 SPID_InitChannel(SCB_CHANNEL6);
#endif
#if (SPID_PHYS_CHANNEL7  == _USED_)
	 SPID_InitChannel(SCB_CHANNEL7);
#endif
 }

 /******************************************************************************/
 /* Name : SPID_Sleep                                                          */
 /* Role : Provide the mean to put to sleep the hardware of activated channels */
 /* Interface : -                                                              */
 /* Pre-condition : -                                                          */
 /* Constraints : This is the funcion called by STAR_HardwareSleep             */
 /* Behaviour :                                                                */
 /*  DO                                                                        */
 /*     [Disable SPI Mode]                                                     */
 /*  OD                                                                        */
 /******************************************************************************/
 void SPID_Sleep(void)
 {
#if (SPID_PHYS_CHANNEL0  == _USED_)
	 Cy_SCB_SPI_DeInit(SCB0);
#endif
#if (SPID_PHYS_CHANNEL1  == _USED_)
	 Cy_SCB_SPI_DeInit(SCB1);
#endif
#if (SPID_PHYS_CHANNEL2  == _USED_)
	 Cy_SCB_SPI_DeInit(SCB2);
#endif
#if (SPID_PHYS_CHANNEL3  == _USED_)
	 Cy_SCB_SPI_DeInit(SCB3);
#endif
#if (SPID_PHYS_CHANNEL4  == _USED_)
	 Cy_SCB_SPI_DeInit(SCB4);
#endif
#if (SPID_PHYS_CHANNEL5  == _USED_)
	 Cy_SCB_SPI_DeInit(SCB5);
#endif
#if (SPID_PHYS_CHANNEL6  == _USED_)
	 Cy_SCB_SPI_DeInit(SCB6);
#endif
#if (SPID_PHYS_CHANNEL7  == _USED_)
	 Cy_SCB_SPI_DeInit(SCB7);
#endif
 }

 /******************************************************************************/
 /* Name: SPID_InitChannel                                                     																		*/
 /* Role: Initialise the module                                                																			*/
 /* Interface: none                                                            																					*/
 /* Pre-condition: none                                                        																			*/
 /* Constraints: none                                                          																				*/
 /* Behaviour:                                                                 																						*/
 /* DO                                                                         																							*/
 /*   [ Initialize hardware according to configuration ]                       														*/
 /* OD                                                                         																							*/
 /******************************************************************************/
 void SPID_InitChannel(uint8 SpidChannel )
 {
    cy_stc_sysint_irq_t  Spi_irq_cfg ;

    switch(SpidChannel)
    {
#if (SPID_PHYS_CHANNEL0  == _USED_)
		case SCB_CHANNEL0:
		    /******* Culculate divider setting for the SCB ****************/
		    Cy_SysClk_PeriphAssignDivider(PCLK_SCB0_CLOCK, SCB_SYSCLK_DIV_TYPE_CHANNEL0, SCB_CLOCK_CTL_DIV_SEL_CHANNEL0);
		    Cy_SysClk_PeriphSetFracDivider(SCB_SYSCLK_DIV_TYPE_CHANNEL0, SCB_PERI_CLOCK_DIV_CHANNEL0, SCB_INT_DIV_CHANNEL0, SCB_FRAC_DIV_CHANNEL0);
		    Cy_SysClk_PeriphEnableDivider(SCB_SYSCLK_DIV_TYPE_CHANNEL0, SCB_DIV_CMD_DIV_SEL_CHANNEL0);

		    /*********** Deinitialization for peripherals*****************/
		    Cy_SCB_SPI_DeInit(SCB0);

		    /*********** Port Setting for SPI communication *************/
		    Spid_PortPinCfgScb0.driveMode = SPID_GPIO_MISO_DM_CHANNEL0;
		    Spid_PortPinCfgScb0.hsiom = SPID_MISO_PORT_MUX_CHANNEL0;
		    Cy_GPIO_Pin_Init(SPID_SCB_MISO_PORT_CHANNEL0, SPID_SCB_MISO_PORT_PIN_CHANNEL0, &Spid_PortPinCfgScb0);

		    Spid_PortPinCfgScb0.driveMode = SPID_GPIO_MOSI_DM_CHANNEL0;
		    Spid_PortPinCfgScb0.hsiom = SPID_MOSI_PORT_MUX_CHANNEL0;
		    Cy_GPIO_Pin_Init(SPID_SCB_MOSI_PORT_CHANNEL0, SPID_SCB_MOSI_PORT_PIN_CHANNEL0, &Spid_PortPinCfgScb0);

		    Spid_PortPinCfgScb0.driveMode = SPID_GPIO_CLK_DM_CHANNEL0;
		    Spid_PortPinCfgScb0.hsiom = SPID_CLK_PORT_MUX_CHANNEL0;
		    Cy_GPIO_Pin_Init(SPID_SCB_CLK_PORT_CHANNEL0,SPID_SCB_CLK_PORT_PIN_CHANNEL0, &Spid_PortPinCfgScb0);

		    /******* SCB initialization for SPI communication ************/
		    Cy_SCB_SPI_Init(SCB0, &Spid_SpiCfgScb0, &Spid_contextSCB0);
		    Cy_SCB_SPI_RegisterCallback(SCB0, (scb_spi_handle_events_t)Spid_SpiEventChannel0, &Spid_contextSCB0);
		    Cy_SCB_SPI_SetActiveSlaveSelect(SCB0, SPID_SLAVE_SELECT_CHANNEL0);
		    Cy_SCB_SPI_Enable(SCB0);

		    /****** Interrupt setting for SPI communication *************/
		    Spi_irq_cfg.intIdx = SCB_INT_ID_CHANNEL0;
		    Spi_irq_cfg.sysIntSrc = SCB_INT_SRC_CHANNEL0;
		    Spi_irq_cfg.isEnabled = TRUE;
		    Cy_SysInt_InitIRQ(&Spi_irq_cfg);
		    Cy_SysInt_SetSystemIrqVector(Spi_irq_cfg.sysIntSrc, Spid_IrqSCBChannel0);
		    NVIC_SetPriority(Spi_irq_cfg.intIdx, SCB_IRQ_PRORITY_CHANNEL0);
		    NVIC_EnableIRQ(Spi_irq_cfg.intIdx);
			break;
#endif

#if (SPID_PHYS_CHANNEL1  == _USED_)
		case SCB_CHANNEL1:
		    /******* Culculate divider setting for the SCB ****************/
		    Cy_SysClk_PeriphAssignDivider(PCLK_SCB1_CLOCK, SCB_SYSCLK_DIV_TYPE_CHANNEL1, SCB_CLOCK_CTL_DIV_SEL_CHANNEL1);
		    Cy_SysClk_PeriphSetFracDivider(SCB_SYSCLK_DIV_TYPE_CHANNEL1, SCB_PERI_CLOCK_DIV_CHANNEL1, SCB_INT_DIV_CHANNEL1, SCB_FRAC_DIV_CHANNEL1);
		    Cy_SysClk_PeriphEnableDivider(SCB_SYSCLK_DIV_TYPE_CHANNEL1, SCB_DIV_CMD_DIV_SEL_CHANNEL1);

		    /*********** Deinitialization for peripherals*****************/
		    Cy_SCB_SPI_DeInit(SCB1);

		    /*********** Port Setting for SPI communication *************/
		    Spid_PortPinCfgScb1.driveMode = SPID_GPIO_MISO_DM_CHANNEL1;
		    Spid_PortPinCfgScb1.hsiom = SPID_MISO_PORT_MUX_CHANNEL1;
		    Cy_GPIO_Pin_Init(SPID_SCB_MISO_PORT_CHANNEL1, SPID_SCB_MISO_PORT_PIN_CHANNEL1, &Spid_PortPinCfgScb1);

		    Spid_PortPinCfgScb1.driveMode = SPID_GPIO_MOSI_DM_CHANNEL1;
		    Spid_PortPinCfgScb1.hsiom = SPID_MOSI_PORT_MUX_CHANNEL1;
		    Cy_GPIO_Pin_Init(SPID_SCB_MOSI_PORT_CHANNEL1, SPID_SCB_MOSI_PORT_PIN_CHANNEL1, &Spid_PortPinCfgScb1);

		    Spid_PortPinCfgScb1.driveMode = SPID_GPIO_CLK_DM_CHANNEL1;
		    Spid_PortPinCfgScb1.hsiom = SPID_CLK_PORT_MUX_CHANNEL1;
		    Cy_GPIO_Pin_Init(SPID_SCB_CLK_PORT_CHANNEL1,SPID_SCB_CLK_PORT_PIN_CHANNEL1, &Spid_PortPinCfgScb1);

		    /******* SCB initialization for SPI communication ************/
		    Cy_SCB_SPI_Init(SCB1, &Spid_SpiCfgScb1, &Spid_contextSCB1);
		    Cy_SCB_SPI_RegisterCallback(SCB1, (scb_spi_handle_events_t)Spid_SpiEventChannel1, &Spid_contextSCB1);
		    Cy_SCB_SPI_SetActiveSlaveSelect(SCB1, SPID_SLAVE_SELECT_CHANNEL1);
		    Cy_SCB_SPI_Enable(SCB1);

		    /****** Interrupt setting for SPI communication *************/
		    Spi_irq_cfg.intIdx = SCB_INT_ID_CHANNEL1;
		    Spi_irq_cfg.sysIntSrc = SCB_INT_SRC_CHANNEL1;
		    Spi_irq_cfg.isEnabled = TRUE;
		    Cy_SysInt_InitIRQ(&Spi_irq_cfg);
		    Cy_SysInt_SetSystemIrqVector(Spi_irq_cfg.sysIntSrc, Spid_IrqSCBChannel1);
		    NVIC_SetPriority(Spi_irq_cfg.intIdx, SCB_IRQ_PRORITY_CHANNEL1);
		    NVIC_EnableIRQ(Spi_irq_cfg.intIdx);
			break;
#endif

#if (SPID_PHYS_CHANNEL2  == _USED_)
		case SCB_CHANNEL2:
		    /******* Culculate divider setting for the SCB ****************/
		    Cy_SysClk_PeriphAssignDivider(PCLK_SCB2_CLOCK, SCB_SYSCLK_DIV_TYPE_CHANNEL2, SCB_CLOCK_CTL_DIV_SEL_CHANNEL2);
		    //Cy_SysClk_PeriphSetFracDivider(SCB_SYSCLK_DIV_TYPE_CHANNEL2, SCB_PERI_CLOCK_DIV_CHANNEL2, SCB_INT_DIV_CHANNEL2, SCB_FRAC_DIV_CHANNEL2);

		    SetPeripheFracDiv24_5(SCB_SPI_CLOCK_FREQ, SOURCE_CLOCK_FRQ, SCB_CLOCK_CTL_DIV_SEL_CHANNEL2);
		    Cy_SysClk_PeriphEnableDivider(SCB_SYSCLK_DIV_TYPE_CHANNEL2, SCB_DIV_CMD_DIV_SEL_CHANNEL2);

		    /*********** Deinitialization for peripherals*****************/
		    Cy_SCB_SPI_DeInit(SCB2);

		    /*********** Port Setting for SPI communication *************/
		    Spid_PortPinCfgScb2.driveMode = SPID_GPIO_MISO_DM_CHANNEL2;
		    Spid_PortPinCfgScb2.hsiom = SPID_MISO_PORT_MUX_CHANNEL2;
		    Cy_GPIO_Pin_Init(SPID_SCB_MISO_PORT_CHANNEL2, SPID_SCB_MISO_PORT_PIN_CHANNEL2, &Spid_PortPinCfgScb2);

		    Spid_PortPinCfgScb2.driveMode = SPID_GPIO_MOSI_DM_CHANNEL2;
		    Spid_PortPinCfgScb2.hsiom = SPID_MOSI_PORT_MUX_CHANNEL2;
		    Cy_GPIO_Pin_Init(SPID_SCB_MOSI_PORT_CHANNEL2, SPID_SCB_MOSI_PORT_PIN_CHANNEL2, &Spid_PortPinCfgScb2);

		    Spid_PortPinCfgScb2.driveMode = SPID_GPIO_CLK_DM_CHANNEL2;
		    Spid_PortPinCfgScb2.hsiom = SPID_CLK_PORT_MUX_CHANNEL2;
		    Cy_GPIO_Pin_Init(SPID_SCB_CLK_PORT_CHANNEL2,SPID_SCB_CLK_PORT_PIN_CHANNEL2, &Spid_PortPinCfgScb2);

		    /******* SCB initialization for SPI communication ************/
		    Cy_SCB_SPI_Init(SCB2, &Spid_SpiCfgScb2, &Spid_contextSCB2);
		    Cy_SCB_SPI_RegisterCallback(SCB2, (scb_spi_handle_events_t)Spid_SpiEventChannel2, &Spid_contextSCB2);
		    Cy_SCB_SPI_SetActiveSlaveSelect(SCB2, SPID_SLAVE_SELECT_CHANNEL2);
		    Cy_SCB_SPI_Enable(SCB2);

#if !defined(__BOOT_LINK__)
		    /****** Interrupt setting for SPI communication *************/
		    Spi_irq_cfg.intIdx = SCB_INT_ID_CHANNEL2;
		    Spi_irq_cfg.sysIntSrc = SCB_INT_SRC_CHANNEL2;
		    Spi_irq_cfg.isEnabled = TRUE;
		    Cy_SysInt_InitIRQ(&Spi_irq_cfg);
		    Cy_SysInt_SetSystemIrqVector(Spi_irq_cfg.sysIntSrc, Spid_IrqSCBChannel2);
		    NVIC_SetPriority(Spi_irq_cfg.intIdx, SCB_IRQ_PRORITY_CHANNEL2);
		    NVIC_EnableIRQ(Spi_irq_cfg.intIdx);
#endif
			break;
#endif

#if (SPID_PHYS_CHANNEL3  == _USED_)
		case SCB_CHANNEL3:
		    /******* Culculate divider setting for the SCB ****************/
		    Cy_SysClk_PeriphAssignDivider(PCLK_SCB3_CLOCK, SCB_SYSCLK_DIV_TYPE_CHANNEL3, SCB_CLOCK_CTL_DIV_SEL_CHANNEL3);
		    Cy_SysClk_PeriphSetFracDivider(SCB_SYSCLK_DIV_TYPE_CHANNEL3, SCB_PERI_CLOCK_DIV_CHANNEL3, SCB_INT_DIV_CHANNEL3, SCB_FRAC_DIV_CHANNEL3);
		    Cy_SysClk_PeriphEnableDivider(SCB_SYSCLK_DIV_TYPE_CHANNEL3, SCB_DIV_CMD_DIV_SEL_CHANNEL3);

		    /*********** Deinitialization for peripherals*****************/
		    Cy_SCB_SPI_DeInit(SCB3);

		    /*********** Port Setting for SPI communication *************/
		    Spid_PortPinCfgScb3.driveMode = SPID_GPIO_MISO_DM_CHANNEL3;
		    Spid_PortPinCfgScb3.hsiom = SPID_MISO_PORT_MUX_CHANNEL3;
		    Cy_GPIO_Pin_Init(SPID_SCB_MISO_PORT_CHANNEL3, SPID_SCB_MISO_PORT_PIN_CHANNEL3, &Spid_PortPinCfgScb3);

		    Spid_PortPinCfgScb3.driveMode = SPID_GPIO_MOSI_DM_CHANNEL3;
		    Spid_PortPinCfgScb3.hsiom = SPID_MOSI_PORT_MUX_CHANNEL3;
		    Cy_GPIO_Pin_Init(SPID_SCB_MOSI_PORT_CHANNEL3, SPID_SCB_MOSI_PORT_PIN_CHANNEL3, &Spid_PortPinCfgScb3);

		    Spid_PortPinCfgScb3.driveMode = SPID_GPIO_CLK_DM_CHANNEL3;
		    Spid_PortPinCfgScb3.hsiom = SPID_CLK_PORT_MUX_CHANNEL3;
		    Cy_GPIO_Pin_Init(SPID_SCB_CLK_PORT_CHANNEL3,SPID_SCB_CLK_PORT_PIN_CHANNEL3, &Spid_PortPinCfgScb3);

		    /******* SCB initialization for SPI communication ************/
		    Cy_SCB_SPI_Init(SCB3, &Spid_SpiCfgScb3, &Spid_contextSCB3);
		    Cy_SCB_SPI_RegisterCallback(SCB3, (scb_spi_handle_events_t)Spid_SpiEventChannel3, &Spid_contextSCB3);
		    Cy_SCB_SPI_SetActiveSlaveSelect(SCB3, SPID_SLAVE_SELECT_CHANNEL3);
		    Cy_SCB_SPI_Enable(SCB3);

		    /****** Interrupt setting for SPI communication *************/
		    Spi_irq_cfg.intIdx = SCB_INT_ID_CHANNEL3;
		    Spi_irq_cfg.sysIntSrc = SCB_INT_SRC_CHANNEL3;
		    Spi_irq_cfg.isEnabled = TRUE;
		    Cy_SysInt_InitIRQ(&Spi_irq_cfg);
		    Cy_SysInt_SetSystemIrqVector(Spi_irq_cfg.sysIntSrc, Spid_IrqSCBChannel3);
		    NVIC_SetPriority(Spi_irq_cfg.intIdx, SCB_IRQ_PRORITY_CHANNEL3);
		    NVIC_EnableIRQ(Spi_irq_cfg.intIdx);
			break;
#endif

#if (SPID_PHYS_CHANNEL4  == _USED_)
		case SCB_CHANNEL4:
		    /******* Culculate divider setting for the SCB ****************/
		    Cy_SysClk_PeriphAssignDivider(PCLK_SCB4_CLOCK, SCB_SYSCLK_DIV_TYPE_CHANNEL4, SCB_CLOCK_CTL_DIV_SEL_CHANNEL4);
		    Cy_SysClk_PeriphSetFracDivider(SCB_SYSCLK_DIV_TYPE_CHANNEL4, SCB_PERI_CLOCK_DIV_CHANNEL4, SCB_INT_DIV_CHANNEL4, SCB_FRAC_DIV_CHANNEL4);
		    Cy_SysClk_PeriphEnableDivider(SCB_SYSCLK_DIV_TYPE_CHANNEL4, SCB_DIV_CMD_DIV_SEL_CHANNEL4);

		    /*********** Deinitialization for peripherals*****************/
		    Cy_SCB_SPI_DeInit(SCB4);

		    /*********** Port Setting for SPI communication *************/
		    Spid_PortPinCfgScb4.driveMode = SPID_GPIO_MISO_DM_CHANNEL4;
		    Spid_PortPinCfgScb4.hsiom = SPID_MISO_PORT_MUX_CHANNEL4;
		    Cy_GPIO_Pin_Init(SPID_SCB_MISO_PORT_CHANNEL4, SPID_SCB_MISO_PORT_PIN_CHANNEL4, &Spid_PortPinCfgScb4);

		    Spid_PortPinCfgScb4.driveMode = SPID_GPIO_MOSI_DM_CHANNEL4;
		    Spid_PortPinCfgScb4.hsiom = SPID_MOSI_PORT_MUX_CHANNEL4;
		    Cy_GPIO_Pin_Init(SPID_SCB_MOSI_PORT_CHANNEL4, SPID_SCB_MOSI_PORT_PIN_CHANNEL4, &Spid_PortPinCfgScb4);

		    Spid_PortPinCfgScb4.driveMode = SPID_GPIO_CLK_DM_CHANNEL4;
		    Spid_PortPinCfgScb4.hsiom = SPID_CLK_PORT_MUX_CHANNEL4;
		    Cy_GPIO_Pin_Init(SPID_SCB_CLK_PORT_CHANNEL4,SPID_SCB_CLK_PORT_PIN_CHANNEL4, &Spid_PortPinCfgScb4);

		    /******* SCB initialization for SPI communication ************/
		    Cy_SCB_SPI_Init(SCB4, &Spid_SpiCfgScb4, &Spid_contextSCB4);
		    Cy_SCB_SPI_RegisterCallback(SCB4, (scb_spi_handle_events_t)Spid_SpiEventChannel4, &Spid_contextSCB4);
		    Cy_SCB_SPI_SetActiveSlaveSelect(SCB4, SPID_SLAVE_SELECT_CHANNEL4);
		    Cy_SCB_SPI_Enable(SCB4);

		    /****** Interrupt setting for SPI communication *************/
		    Spi_irq_cfg.intIdx = SCB_INT_ID_CHANNEL4;
		    Spi_irq_cfg.sysIntSrc = SCB_INT_SRC_CHANNEL4;
		    Spi_irq_cfg.isEnabled = TRUE;
		    Cy_SysInt_InitIRQ(&Spi_irq_cfg);
		    Cy_SysInt_SetSystemIrqVector(Spi_irq_cfg.sysIntSrc, Spid_IrqSCBChannel4);
		    NVIC_SetPriority(Spi_irq_cfg.intIdx, SCB_IRQ_PRORITY_CHANNEL4);
		    NVIC_EnableIRQ(Spi_irq_cfg.intIdx);
			break;
#endif

#if (SPID_PHYS_CHANNEL5  == _USED_)
		case SCB_CHANNEL5:
		    /******* Culculate divider setting for the SCB ****************/
		    Cy_SysClk_PeriphAssignDivider(PCLK_SCB5_CLOCK, SCB_SYSCLK_DIV_TYPE_CHANNEL5, SCB_CLOCK_CTL_DIV_SEL_CHANNEL5);
		    Cy_SysClk_PeriphSetFracDivider(SCB_SYSCLK_DIV_TYPE_CHANNEL5, SCB_PERI_CLOCK_DIV_CHANNEL5, SCB_INT_DIV_CHANNEL5, SCB_FRAC_DIV_CHANNEL5);
		    Cy_SysClk_PeriphEnableDivider(SCB_SYSCLK_DIV_TYPE_CHANNEL5, SCB_DIV_CMD_DIV_SEL_CHANNEL5);

		    /*********** Deinitialization for peripherals*****************/
		    Cy_SCB_SPI_DeInit(SCB5);

		    /*********** Port Setting for SPI communication *************/
		    Spid_PortPinCfgScb5.driveMode = SPID_GPIO_MISO_DM_CHANNEL5;
		    Spid_PortPinCfgScb5.hsiom = SPID_MISO_PORT_MUX_CHANNEL5;
		    Cy_GPIO_Pin_Init(SPID_SCB_MISO_PORT_CHANNEL5, SPID_SCB_MISO_PORT_PIN_CHANNEL5, &Spid_PortPinCfgScb5);

		    Spid_PortPinCfgScb5.driveMode = SPID_GPIO_MOSI_DM_CHANNEL5;
		    Spid_PortPinCfgScb5.hsiom = SPID_MOSI_PORT_MUX_CHANNEL5;
		    Cy_GPIO_Pin_Init(SPID_SCB_MOSI_PORT_CHANNEL5, SPID_SCB_MOSI_PORT_PIN_CHANNEL5, &Spid_PortPinCfgScb5);

		    Spid_PortPinCfgScb5.driveMode = SPID_GPIO_CLK_DM_CHANNEL5;
		    Spid_PortPinCfgScb5.hsiom = SPID_CLK_PORT_MUX_CHANNEL5;
		    Cy_GPIO_Pin_Init(SPID_SCB_CLK_PORT_CHANNEL5,SPID_SCB_CLK_PORT_PIN_CHANNEL5, &Spid_PortPinCfgScb5);

		    /******* SCB initialization for SPI communication ************/
		    Cy_SCB_SPI_Init(SCB5, &Spid_SpiCfgScb5, &Spid_contextSCB5);
		    Cy_SCB_SPI_RegisterCallback(SCB5, (scb_spi_handle_events_t)Spid_SpiEventChannel5, &Spid_contextSCB5);
		    Cy_SCB_SPI_SetActiveSlaveSelect(SCB5, SPID_SLAVE_SELECT_CHANNEL5);
		    Cy_SCB_SPI_Enable(SCB5);
#if !defined(__BOOT_LINK__)
		    /****** Interrupt setting for SPI communication *************/
		    Spi_irq_cfg.intIdx = SCB_INT_ID_CHANNEL5;
		    Spi_irq_cfg.sysIntSrc = SCB_INT_SRC_CHANNEL5;
		    Spi_irq_cfg.isEnabled = TRUE;
		    Cy_SysInt_InitIRQ(&Spi_irq_cfg);
		    Cy_SysInt_SetSystemIrqVector(Spi_irq_cfg.sysIntSrc, Spid_IrqSCBChannel5);
		    NVIC_SetPriority(Spi_irq_cfg.intIdx, SCB_IRQ_PRORITY_CHANNEL5);
		    NVIC_EnableIRQ(Spi_irq_cfg.intIdx);
#endif
			break;
#endif

#if (SPID_PHYS_CHANNEL6  == _USED_)
		case SCB_CHANNEL6:
		    /******* Culculate divider setting for the SCB ****************/
		    Cy_SysClk_PeriphAssignDivider(PCLK_SCB6_CLOCK, SCB_SYSCLK_DIV_TYPE_CHANNEL6, SCB_CLOCK_CTL_DIV_SEL_CHANNEL6);
		    Cy_SysClk_PeriphSetFracDivider(SCB_SYSCLK_DIV_TYPE_CHANNEL6, SCB_PERI_CLOCK_DIV_CHANNEL6, SCB_INT_DIV_CHANNEL6, SCB_FRAC_DIV_CHANNEL6);
		    Cy_SysClk_PeriphEnableDivider(SCB_SYSCLK_DIV_TYPE_CHANNEL6, SCB_DIV_CMD_DIV_SEL_CHANNEL6);

		    /*********** Deinitialization for peripherals*****************/
		    Cy_SCB_SPI_DeInit(SCB6);

		    /*********** Port Setting for SPI communication *************/
		    Spid_PortPinCfgScb6.driveMode = SPID_GPIO_MISO_DM_CHANNEL6;
		    Spid_PortPinCfgScb6.hsiom = SPID_MISO_PORT_MUX_CHANNEL6;
		    Cy_GPIO_Pin_Init(SPID_SCB_MISO_PORT_CHANNEL6, SPID_SCB_MISO_PORT_PIN_CHANNEL6, &Spid_PortPinCfgScb6);

		    Spid_PortPinCfgScb6.driveMode = SPID_GPIO_MOSI_DM_CHANNEL6;
		    Spid_PortPinCfgScb6.hsiom = SPID_MOSI_PORT_MUX_CHANNEL6;
		    Cy_GPIO_Pin_Init(SPID_SCB_MOSI_PORT_CHANNEL6, SPID_SCB_MOSI_PORT_PIN_CHANNEL6, &Spid_PortPinCfgScb6);

		    Spid_PortPinCfgScb6.driveMode = SPID_GPIO_CLK_DM_CHANNEL6;
		    Spid_PortPinCfgScb6.hsiom = SPID_CLK_PORT_MUX_CHANNEL6;
		    Cy_GPIO_Pin_Init(SPID_SCB_CLK_PORT_CHANNEL6,SPID_SCB_CLK_PORT_PIN_CHANNEL6, &Spid_PortPinCfgScb6);

		    /******* SCB initialization for SPI communication ************/
		    Cy_SCB_SPI_Init(SCB6, &Spid_SpiCfgScb6, &Spid_contextSCB6);
		    Cy_SCB_SPI_RegisterCallback(SCB6, (scb_spi_handle_events_t)Spid_SpiEventChannel6, &Spid_contextSCB6);
		    Cy_SCB_SPI_SetActiveSlaveSelect(SCB6, SPID_SLAVE_SELECT_CHANNEL6);
		    Cy_SCB_SPI_Enable(SCB6);

		    /****** Interrupt setting for SPI communication *************/
		    Spi_irq_cfg.intIdx = SCB_INT_ID_CHANNEL6;
		    Spi_irq_cfg.sysIntSrc = SCB_INT_SRC_CHANNEL6;
		    Spi_irq_cfg.isEnabled = TRUE;
		    Cy_SysInt_InitIRQ(&Spi_irq_cfg);
		    Cy_SysInt_SetSystemIrqVector(Spi_irq_cfg.sysIntSrc, Spid_IrqSCBChannel6);
		    NVIC_SetPriority(Spi_irq_cfg.intIdx, SCB_IRQ_PRORITY_CHANNEL6);
		    NVIC_EnableIRQ(Spi_irq_cfg.intIdx);
			break;
#endif


#if (SPID_PHYS_CHANNEL7  == _USED_)
		case SCB_CHANNEL7:
		    /******* Culculate divider setting for the SCB ****************/
		    Cy_SysClk_PeriphAssignDivider(PCLK_SCB7_CLOCK, SCB_SYSCLK_DIV_TYPE_CHANNEL7, SCB_CLOCK_CTL_DIV_SEL_CHANNEL7);
		    Cy_SysClk_PeriphSetFracDivider(SCB_SYSCLK_DIV_TYPE_CHANNEL7, SCB_PERI_CLOCK_DIV_CHANNEL7, SCB_INT_DIV_CHANNEL7, SCB_FRAC_DIV_CHANNEL7);
		    Cy_SysClk_PeriphEnableDivider(SCB_SYSCLK_DIV_TYPE_CHANNEL7, SCB_DIV_CMD_DIV_SEL_CHANNEL7);

		    /*********** Deinitialization for peripherals*****************/
		    Cy_SCB_SPI_DeInit(SCB7);

		    /*********** Port Setting for SPI communication *************/
		    Spid_PortPinCfgScb7.driveMode = SPID_GPIO_MISO_DM_CHANNEL7;
		    Spid_PortPinCfgScb7.hsiom = SPID_MISO_PORT_MUX_CHANNEL7;
		    Cy_GPIO_Pin_Init(SPID_SCB_MISO_PORT_CHANNEL7, SPID_SCB_MISO_PORT_PIN_CHANNEL7, &Spid_PortPinCfgScb7);

		    Spid_PortPinCfgScb7.driveMode = SPID_GPIO_MOSI_DM_CHANNEL7;
		    Spid_PortPinCfgScb7.hsiom = SPID_MOSI_PORT_MUX_CHANNEL7;
		    Cy_GPIO_Pin_Init(SPID_SCB_MOSI_PORT_CHANNEL7, SPID_SCB_MOSI_PORT_PIN_CHANNEL7, &Spid_PortPinCfgScb7);

		    Spid_PortPinCfgScb7.driveMode = SPID_GPIO_CLK_DM_CHANNEL7;
		    Spid_PortPinCfgScb7.hsiom = SPID_CLK_PORT_MUX_CHANNEL7;
		    Cy_GPIO_Pin_Init(SPID_SCB_CLK_PORT_CHANNEL7,SPID_SCB_CLK_PORT_PIN_CHANNEL7, &Spid_PortPinCfgScb7);

		    /******* SCB initialization for SPI communication ************/
		    Cy_SCB_SPI_Init(SCB7, &Spid_SpiCfgScb7, &Spid_contextSCB7);
		    Cy_SCB_SPI_RegisterCallback(SCB7, (scb_spi_handle_events_t)Spid_SpiEventChannel7, &Spid_contextSCB7);
		    Cy_SCB_SPI_SetActiveSlaveSelect(SCB7, SPID_SLAVE_SELECT_CHANNEL7);
		    Cy_SCB_SPI_Enable(SCB7);

		    /****** Interrupt setting for SPI communication *************/
		    Spi_irq_cfg.intIdx = SCB_INT_ID_CHANNEL7;
		    Spi_irq_cfg.sysIntSrc = SCB_INT_SRC_CHANNEL7;
		    Spi_irq_cfg.isEnabled = TRUE;
		    Cy_SysInt_InitIRQ(&Spi_irq_cfg);
		    Cy_SysInt_SetSystemIrqVector(Spi_irq_cfg.sysIntSrc, Spid_IrqSCBChannel7);
		    NVIC_SetPriority(Spi_irq_cfg.intIdx, SCB_IRQ_PRORITY_CHANNEL7);
		    NVIC_EnableIRQ(Spi_irq_cfg.intIdx);
			break;
#endif

		default:
		   break;
    }

 }

#if (SPID_PHYS_CHANNEL0  == _USED_)
 /******************************************************************************
 * Name         :  Spid_SpiEventChannel0
 * Called by    :
 * Preconditions:
 * Parameters   :  None
 * Return code  :  None
 * Description  : This function is called for register callback spi
 ******************************************************************************/
 void Spid_SpiEventChannel0(uint32 locEvents)
 {
	    switch (locEvents) {

	        case CY_SCB_SPI_TRANSFER_IN_FIFO_EVENT:
	            break;

	        case CY_SCB_SPI_TRANSFER_CMPLT_EVENT:
	        	SPID_TransmitState_Scb0 = SPID_TransmitComplete;
#ifdef SPIC_TRANSFER_COMPLETE_CBK_CH0
	        	SPID_TransferCompleteCbkCh0();
#endif
	            break;

	        case CY_SCB_SPI_TRANSFER_ERR_EVENT:
	        	SPID_TransmitState_Scb0 = SPID_TransmitError;
#ifdef SPIC_TRANSFER_ERR_CBK_CH0
	        	SPID_TransferErrCbkCh0();
#endif
	            break;

	        default:
	            break;
	    }
 }
#endif

#if (SPID_PHYS_CHANNEL1  == _USED_)
 /******************************************************************************
 * Name         :  Spid_SpiEventChannel1
 * Called by    :
 * Preconditions:
 * Parameters   :  None
 * Return code  :  None
 * Description  : This function is called for register callback spi
 ******************************************************************************/
 void Spid_SpiEventChannel1(uint32 locEvents)
 {
	    switch (locEvents) {

	        case CY_SCB_SPI_TRANSFER_IN_FIFO_EVENT:
	            break;

	        case CY_SCB_SPI_TRANSFER_CMPLT_EVENT:
	        	SPID_TransmitState_Scb1 = SPID_TransmitComplete;
#ifdef SPIC_TRANSFER_COMPLETE_CBK_CH1
	        	SPID_TransferCompleteCbkCh1();
#endif
	            break;

	        case CY_SCB_SPI_TRANSFER_ERR_EVENT:
	        	SPID_TransmitState_Scb1 = SPID_TransmitError;
#ifdef SPIC_TRANSFER_ERR_CBK_CH1
	        	SPID_TransferErrCbkCh1();
#endif
	            break;

	        default:
	            break;
	    }
 }
#endif

#if (SPID_PHYS_CHANNEL2  == _USED_)
 /******************************************************************************
 * Name         :  Spid_SpiEventChannel2
 * Called by    :
 * Preconditions:
 * Parameters   :  None
 * Return code  :  None
 * Description  : This function is called for register callback spi
 ******************************************************************************/
 void Spid_SpiEventChannel2(uint32 locEvents)
 {
	    switch (locEvents) {

	        case CY_SCB_SPI_TRANSFER_IN_FIFO_EVENT:
	            break;

	        case CY_SCB_SPI_TRANSFER_CMPLT_EVENT:
	        	SPID_TransmitState_Scb2 = SPID_TransmitComplete;
#ifdef SPIC_TRANSFER_COMPLETE_CBK_CH2
	        	SPID_TransferCompleteCbkCh2();
#endif
	            break;

	        case CY_SCB_SPI_TRANSFER_ERR_EVENT:
	        	SPID_TransmitState_Scb2 = SPID_TransmitError;
#ifdef SPIC_TRANSFER_ERR_CBK_CH2
	        	SPID_TransferErrCbkCh2();
#endif
	            break;

	        default:
	            break;
	    }
 }
#endif

#if (SPID_PHYS_CHANNEL3  == _USED_)
 /******************************************************************************
 * Name         :  Spid_SpiEventChannel3
 * Called by    :
 * Preconditions:
 * Parameters   :  None
 * Return code  :  None
 * Description  : This function is called for register callback spi
 ******************************************************************************/
 void Spid_SpiEventChannel3(uint32 locEvents)
 {
	    switch (locEvents) {

	        case CY_SCB_SPI_TRANSFER_IN_FIFO_EVENT:
	            break;

	        case CY_SCB_SPI_TRANSFER_CMPLT_EVENT:
	        	SPID_TransmitState_Scb3 = SPID_TransmitComplete;
#ifdef SPIC_TRANSFER_COMPLETE_CBK_CH3
	        	SPID_TransferCompleteCbkCh3();
#endif
	            break;

	        case CY_SCB_SPI_TRANSFER_ERR_EVENT:
	        	SPID_TransmitState_Scb3 = SPID_TransmitError;
#ifdef SPIC_TRANSFER_ERR_CBK_CH3
	        	SPID_TransferErrCbkCh3();
#endif
	            break;

	        default:
	            break;
	    }
 }
#endif

#if (SPID_PHYS_CHANNEL4  == _USED_)
 /******************************************************************************
 * Name         :  Spid_SpiEventChannel4
 * Called by    :
 * Preconditions:
 * Parameters   :  None
 * Return code  :  None
 * Description  : This function is called for register callback spi
 ******************************************************************************/
 void Spid_SpiEventChannel4(uint32 locEvents)
 {
	    switch (locEvents) {

	        case CY_SCB_SPI_TRANSFER_IN_FIFO_EVENT:
	            break;

	        case CY_SCB_SPI_TRANSFER_CMPLT_EVENT:
	        	SPID_TransmitState_Scb4 = SPID_TransmitComplete;
#ifdef SPIC_TRANSFER_COMPLETE_CBK_CH4
	        	SPID_TransferCompleteCbkCh4();
#endif
	            break;

	        case CY_SCB_SPI_TRANSFER_ERR_EVENT:
	        	SPID_TransmitState_Scb4 = SPID_TransmitError;
#ifdef SPIC_TRANSFER_ERR_CBK_CH4
	        	SPID_TransferErrCbkCh4();
#endif
	            break;

	        default:
	            break;
	    }
 }
#endif

#if (SPID_PHYS_CHANNEL5  == _USED_)
 /******************************************************************************
 * Name         :  Spid_SpiEventChannel5
 * Called by    :
 * Preconditions:
 * Parameters   :  None
 * Return code  :  None
 * Description  : This function is called for register callback spi
 ******************************************************************************/
 void Spid_SpiEventChannel5(uint32 locEvents)
 {
	    switch (locEvents) {

	        case CY_SCB_SPI_TRANSFER_IN_FIFO_EVENT:
	            break;

	        case CY_SCB_SPI_TRANSFER_CMPLT_EVENT:
	        	SPID_TransmitState_Scb5 = SPID_TransmitComplete;
#ifdef SPIC_TRANSFER_COMPLETE_CBK_CH5
	        	SPID_TransferCompleteCbkCh5();
#endif
	            break;

	        case CY_SCB_SPI_TRANSFER_ERR_EVENT:
	        	SPID_TransmitState_Scb5 = SPID_TransmitError;
#ifdef SPIC_TRANSFER_ERR_CBK_CH5
	        	SPID_TransferErrCbkCh5();
#endif
	            break;

	        default:
	            break;
	    }
 }
#endif


#if (SPID_PHYS_CHANNEL6  == _USED_)
 /******************************************************************************
 * Name         :  Spid_SpiEventChannel6
 * Called by    :
 * Preconditions:
 * Parameters   :  None
 * Return code  :  None
 * Description  : This function is called for register callback spi
 ******************************************************************************/
 void Spid_SpiEventChannel6(uint32 locEvents)
 {
	    switch (locEvents) {

	        case CY_SCB_SPI_TRANSFER_IN_FIFO_EVENT:
	            break;

	        case CY_SCB_SPI_TRANSFER_CMPLT_EVENT:
	        	SPID_TransmitState_Scb6 = SPID_TransmitComplete;
#ifdef SPIC_TRANSFER_COMPLETE_CBK_CH6
	        	SPID_TransferCompleteCbkCh6();
#endif
	            break;

	        case CY_SCB_SPI_TRANSFER_ERR_EVENT:
	        	SPID_TransmitState_Scb6 = SPID_TransmitError;
#ifdef SPIC_TRANSFER_ERR_CBK_CH6
	        	SPID_TransferErrCbkCh6();
#endif
	            break;

	        default:
	            break;
	    }
 }
#endif

#if (SPID_PHYS_CHANNEL7  == _USED_)
 /******************************************************************************
 * Name         :  Spid_SpiEventChannel7
 * Called by    :
 * Preconditions:
 * Parameters   :  None
 * Return code  :  None
 * Description  : This function is called for register callback spi
 ******************************************************************************/
 void Spid_SpiEventChannel7(uint32 locEvents)
 {
	    switch (locEvents) {

	        case CY_SCB_SPI_TRANSFER_IN_FIFO_EVENT:
	            break;

	        case CY_SCB_SPI_TRANSFER_CMPLT_EVENT:
	        	SPID_TransmitState_Scb7 = SPID_TransmitComplete;
#ifdef SPIC_TRANSFER_COMPLETE_CBK_CH7
	        	SPID_TransferCompleteCbkCh7();
#endif
	            break;

	        case CY_SCB_SPI_TRANSFER_ERR_EVENT:
	        	SPID_TransmitState_Scb7 = SPID_TransmitError;
#ifdef SPIC_TRANSFER_ERR_CBK_CH7
	        	SPID_TransferErrCbkCh7();
#endif
	            break;

	        default:
	            break;
	    }
 }
#endif

#if (SPID_PHYS_CHANNEL0  == _USED_)
 /******************************************************************************
 * Name         :  Spid_IrqSCBChannel0
 * Called by    :
 * Preconditions:
 * Parameters   :  None
 * Return code  :  None
 * Description  :  This function is called for scb interrupt
 ******************************************************************************/
 void Spid_IrqSCBChannel0(void)
 {
     Cy_SCB_SPI_Interrupt(SCB0, &Spid_contextSCB0);
 }
#endif

#if (SPID_PHYS_CHANNEL1  == _USED_)
 /******************************************************************************
 * Name         :  Spid_IrqSCBChannel1
 * Called by    :
 * Preconditions:
 * Parameters   :  None
 * Return code  :  None
 * Description  :  This function is called for scb interrupt
 ******************************************************************************/
 void Spid_IrqSCBChannel1(void)
 {
     Cy_SCB_SPI_Interrupt(SCB1, &Spid_contextSCB1);
 }
#endif

#if (SPID_PHYS_CHANNEL2  == _USED_)
 /******************************************************************************
 * Name         :  Spid_IrqSCBChannel2
 * Called by    :
 * Preconditions:
 * Parameters   :  None
 * Return code  :  None
 * Description  :  This function is called for scb interrupt
 ******************************************************************************/
 void Spid_IrqSCBChannel2(void)
 {
     Cy_SCB_SPI_Interrupt(SCB2, &Spid_contextSCB2);
 }
#endif

#if (SPID_PHYS_CHANNEL3  == _USED_)
 /******************************************************************************
 * Name         :  Spid_IrqSCBChannel3
 * Called by    :
 * Preconditions:
 * Parameters   :  None
 * Return code  :  None
 * Description  :  This function is called for scb interrupt
 ******************************************************************************/
 void Spid_IrqSCBChannel3(void)
 {
     Cy_SCB_SPI_Interrupt(SCB3, &Spid_contextSCB3);
 }
#endif

#if (SPID_PHYS_CHANNEL4  == _USED_)
 /******************************************************************************
 * Name         :  Spid_IrqSCBChannel4
 * Called by    :
 * Preconditions:
 * Parameters   :  None
 * Return code  :  None
 * Description  :  This function is called for scb interrupt
 ******************************************************************************/
 void Spid_IrqSCBChannel4(void)
 {
     Cy_SCB_SPI_Interrupt(SCB4, &Spid_contextSCB4);
 }
#endif

#if (SPID_PHYS_CHANNEL5  == _USED_)
 /******************************************************************************
 * Name         :  Spid_IrqSCBChannel5
 * Called by    :
 * Preconditions:
 * Parameters   :  None
 * Return code  :  None
 * Description  :  This function is called for scb interrupt
 ******************************************************************************/
 void Spid_IrqSCBChannel5(void)
 {
     Cy_SCB_SPI_Interrupt(SCB5, &Spid_contextSCB5);
 }
#endif

#if (SPID_PHYS_CHANNEL6  == _USED_)
 /******************************************************************************
 * Name         :  Spid_IrqSCBChannel6
 * Called by    :
 * Preconditions:
 * Parameters   :  None
 * Return code  :  None
 * Description  :  This function is called for scb interrupt
 ******************************************************************************/
 void Spid_IrqSCBChannel6(void)
 {
     Cy_SCB_SPI_Interrupt(SCB6, &Spid_contextSCB6);
 }
#endif

#if (SPID_PHYS_CHANNEL7  == _USED_)
 /******************************************************************************
 * Name         :  Spid_IrqSCBChannel7
 * Called by    :
 * Preconditions:
 * Parameters   :  None
 * Return code  :  None
 * Description  :  This function is called for scb interrupt
 ******************************************************************************/
 void Spid_IrqSCBChannel7(void)
 {
     Cy_SCB_SPI_Interrupt(SCB7, &Spid_contextSCB7);
 }
#endif

 /******************************************************************************/
 /* Name: SPID_GetScbBaseAddr                                                    															 	*/
 /* Role: Get SCB channel base address													   	    											*/
 /* Interface: Channel          IN  Communication channel number               											*/
 /* Pre-condition: 																													   						     */
 /* Constraints: none                                                          																				*/
 /******************************************************************************/
 volatile  stc_SCB_t*  SPID_GetScbBaseAddr(uint8 Channel)
 {
	 volatile stc_SCB_t *base;
     switch(Channel)
     {
#if (SPID_PHYS_CHANNEL0  == _USED_)
     	 case SCB_CHANNEL0:
     		base = SCB0;
		 break;
#endif

#if (SPID_PHYS_CHANNEL1  == _USED_)
     	 case SCB_CHANNEL1:
     		base = SCB1;
		 break;
#endif

#if (SPID_PHYS_CHANNEL2  == _USED_)
     	 case SCB_CHANNEL2:
     		base = SCB2;
		 break;
#endif

#if (SPID_PHYS_CHANNEL3  == _USED_)
     	 case SCB_CHANNEL3:
     		base = SCB3;
		 break;
#endif

#if (SPID_PHYS_CHANNEL4  == _USED_)
     	 case SCB_CHANNEL4:
     		base = SCB4;
		 break;
#endif

#if (SPID_PHYS_CHANNEL5  == _USED_)
     	 case SCB_CHANNEL5:
     		base = SCB5;
		 break;
#endif

#if (SPID_PHYS_CHANNEL6  == _USED_)
     	 case SCB_CHANNEL6:
     		base = SCB6;
		 break;
#endif

#if (SPID_PHYS_CHANNEL7  == _USED_)
     	 case SCB_CHANNEL7:
     		base = SCB7;
		 break;
#endif

     	 default:
		 break;
     }

    return base;
 }

 /******************************************************************************/
  /* Name: SPID_GetScbContextAddr                                                    													   */
  /* Role: Get SCB channel Context address													   	    									*/
  /* Interface: Channel          IN  Communication channel number               									    */
  /* Pre-condition: 																													   						     */
  /* Constraints: none                                                          																				*/
  /******************************************************************************/
 cy_stc_scb_spi_context_t*  SPID_GetScbContextAddr(uint8 Channel)
  {
	 cy_stc_scb_spi_context_t *ContextAddr;
      switch(Channel)
      {
#if (SPID_PHYS_CHANNEL0  == _USED_)
      	 case SCB_CHANNEL0:
      		ContextAddr = &Spid_contextSCB0;
 		 break;
#endif

#if (SPID_PHYS_CHANNEL1  == _USED_)
      	 case SCB_CHANNEL1:
      		ContextAddr = &Spid_contextSCB1;
 		 break;
#endif

#if (SPID_PHYS_CHANNEL2  == _USED_)
      	 case SCB_CHANNEL2:
      		ContextAddr = &Spid_contextSCB2;
 		 break;
#endif

#if (SPID_PHYS_CHANNEL3  == _USED_)
      	 case SCB_CHANNEL3:
      		ContextAddr = &Spid_contextSCB3;
 		 break;
#endif

#if (SPID_PHYS_CHANNEL4  == _USED_)
      	 case SCB_CHANNEL4:
      		ContextAddr = &Spid_contextSCB4;
 		 break;
#endif

#if (SPID_PHYS_CHANNEL5  == _USED_)
      	 case SCB_CHANNEL5:
      		ContextAddr = &Spid_contextSCB5;
 		 break;
#endif

#if (SPID_PHYS_CHANNEL6  == _USED_)
      	 case SCB_CHANNEL6:
      		ContextAddr = &Spid_contextSCB6;
 		 break;
#endif

#if (SPID_PHYS_CHANNEL7  == _USED_)
      	 case SCB_CHANNEL7:
      		ContextAddr = &Spid_contextSCB7;
 		 break;
#endif
      	 default:
 		 break;
      }

     return ContextAddr;
  }

/*******************************************************************************/
/* Name: SPID_TransmitData                                                    																	   	*/
/* Role: Provide the mean to start transmit data on selected channel    											 */
/* Interface: Channel          IN  Communication channel number               											*/
/*                     Data                IN  Byte to transmit on serial communication  										*/
/*                     Length            Send Data length																								*/
/* Pre-condition: The transmit data register for the channel must be empty    								*/
/* Constraints: none                                                          																				*/
/******************************************************************************/
cy_en_scb_spi_status_t SPID_TransmitData(uint8 Channel, uint8 *TxData,uint8 *RxData, uint32 Length)
{
	  cy_en_scb_spi_status_t  l_status = CY_SCB_SPI_SUCCESS;
	  cy_stc_scb_spi_context_t* ContextAddr;
	  volatile stc_SCB_t *base;
	  base = SPID_GetScbBaseAddr(Channel);
	  ContextAddr = SPID_GetScbContextAddr(Channel);
	  l_status = Cy_SCB_SPI_Transfer(base,TxData,RxData,Length,ContextAddr);
	  return l_status;
}

/******************************************************************************/
/* Name: SPID_OperationDone                                                                                                                   */
/* Role: Provide the mean to get the status of operation on selected channel                              */
/* Interface: Channel  IN   Communication channel number                                                               */
/*            Status   OUT  Status according to previous request:                                                              */
/*                          != 0  -> Operation terminated                                                                                         */
/*                          = 0   -> Operation in progress                                                                                          */
/* Pre-condition: none                                                                                                                                   */
/* Constraints: none                                                                                                                                        */
/******************************************************************************/
SPID_TransmitState_t  SPID_OperationDone(uint8 Channel)
{
	SPID_TransmitState_t Ret;
    switch(Channel)
    {
#if (SPID_PHYS_CHANNEL0  == _USED_)
    	case SCB_CHANNEL0:
    	Ret = SPID_TransmitState_Scb0;
        break;
#endif

#if (SPID_PHYS_CHANNEL1  == _USED_)
    	case SCB_CHANNEL1:
    	Ret = SPID_TransmitState_Scb1;
        break;
#endif

#if (SPID_PHYS_CHANNEL2  == _USED_)
    	case SCB_CHANNEL2:
    	Ret = SPID_TransmitState_Scb2;
        break;
#endif

#if (SPID_PHYS_CHANNEL3  == _USED_)
    	case SCB_CHANNEL3:
    	Ret = SPID_TransmitState_Scb3;
        break;
#endif

#if (SPID_PHYS_CHANNEL4  == _USED_)
    	case SCB_CHANNEL4:
    	Ret = SPID_TransmitState_Scb4;
        break;
#endif

#if (SPID_PHYS_CHANNEL5  == _USED_)
    	case SCB_CHANNEL5:
    	Ret = SPID_TransmitState_Scb5;
        break;
#endif

#if (SPID_PHYS_CHANNEL6  == _USED_)
    	case SCB_CHANNEL6:
    	Ret = SPID_TransmitState_Scb6;
        break;
#endif

#if (SPID_PHYS_CHANNEL7  == _USED_)
    	case SCB_CHANNEL7:
    	Ret = SPID_TransmitState_Scb7;
        break;
#endif

    	default:
    	break;
    }

    return Ret;
}


/*______ P R I V A T E - F U N C T I O N S ___________________________________*/


/*______ L O C A L - F U N C T I O N S _______________________________________*/


/*______ E N D _____ (xxxx.c) ________________________________________________*/

