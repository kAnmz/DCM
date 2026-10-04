/******************************************************************************/
/*@F_NAME:           spid_config_tv2.c                                                                                                        */
/*@F_PURPOSE:        SPI Driver Module                                                                                                    */
/*@F_CREATED_BY:     Wei Liang                                                                                                                  */
/*@F_CREATION_DATE:  2020/10/26                                                                                                        */
/*@F_LANGUAGE :      ANSI C                                                                                                                        */
/*@F_MPROC_TYPE:     Cypress Traveo II series                                                                                     */
/********************************************** (C) Copyright 2020 Marelli *********/


/*______ I N C L U D E - F I L E S ___________________________________________*/
#include"cy_scb_spi.h"
#include"spid_config_tv2.h"
/*______ L O C A L - D E F I N E S ___________________________________________*/


/*______ L O C A L - T Y P E S _______________________________________________*/


/*______ G L O B A L - D A T A _______________________________________________*/
#if (SPID_PHYS_CHANNEL0  == _USED_)
 const cy_stc_scb_spi_config_t Spid_SpiCfgScb0 =
 {
     .spiMode                    = CY_SCB_SPI_MASTER,      /*** Specifies the mode of operation    ***/
     .subMode                    = CY_SCB_SPI_MOTOROLA,    /*** Specifies the submode of SPI operation    ***/
     .sclkMode                   = CY_SCB_SPI_CPHA1_CPOL1, /**< Clock is active low, data is changed on second edge  */
     .oversample                 = 8,   						/*** SPI_CLOCK divided by SCB_SPI_OVERSAMPLING shoud be baudrate  ***/
     .rxDataWidth                = 8,                     /*** The width of RX data (valid range 4-16). It must be the same as \ref txDataWidth except in National sub-mode. ***/
     .txDataWidth                = 8,                     /*** The width of TX data (valid range 4-16). It must be the same as \ref rxDataWidth except in National sub-mode. ***/
     .enableMsbFirst             = true,                   /*** Enables the hardware to shift out the data element MSB first, otherwise, LSB first ***/
     .enableFreeRunSclk          = false,                  /*** Enables the master to generate a continuous SCLK regardless of whether there is data to send  ***/
     .enableInputFilter          = false,                  /*** Enables a digital 3-tap median filter to be applied to the input of the RX FIFO to filter glitches on the line. ***/
     .enableMisoLateSample       = false,                   /*** Enables the master to sample MISO line one half clock later to allow better timings. ***/
     .enableTransferSeperation   = true,                   /*** Enables the master to transmit each data element separated by a de-assertion of the slave select line (only applicable for the master mode) ***/
     .ssPolarity0                = 0,                      /*** SS0: active low ***/
     .ssPolarity1                = 0,                      /*** SS1: active low ***/
     .ssPolarity2                = 0,                      /*** SS2: active low ***/
     .ssPolarity3                = 0,                      /*** SS3: active low ***/
     .enableWakeFromSleep        = 0,                      /*** When set, the slave will wake the device when the slave select line becomes active. Note that not all SCBs support this mode. Consult the device datasheet to determine which SCBs support wake from deep sleep. ***/
     .txFifoTriggerLevel         = 0,                      /*** When there are fewer entries in the TX FIFO, then at this level the TX trigger output goes high. This output can be connected to a DMA channel through a trigger mux. Also, it controls the \ref CY_SCB_SPI_TX_TRIGGER interrupt source. ***/
     .rxFifoTriggerLevel         = 0,                    /*** When there are more entries in the RX FIFO, then at this level the RX trigger output goes high. This output can be connected to a DMA channel through a trigger mux. Also, it controls the \ref CY_SCB_SPI_RX_TRIGGER interrupt source.  ***/
     .rxFifoIntEnableMask        = 0,                      /*** Bits set in this mask will allow events to cause an interrupt  ***/
     .txFifoIntEnableMask        = 0,                      /*** Bits set in this mask allow events to cause an interrupt  ***/
     .masterSlaveIntEnableMask   = 0,                      /*** Bits set in this mask allow events to cause an interrupt  ***/
     .enableSpiDoneInterrupt     = true,
     .enableSpiBusErrorInterrupt = 0,
 };
#endif

#if (SPID_PHYS_CHANNEL1  == _USED_)
 const cy_stc_scb_spi_config_t Spid_SpiCfgScb1 =
 {
     .spiMode                    = CY_SCB_SPI_MASTER,      /*** Specifies the mode of operation    ***/
     .subMode                    = CY_SCB_SPI_MOTOROLA,    /*** Specifies the submode of SPI operation    ***/
     .sclkMode                   = CY_SCB_SPI_CPHA1_CPOL1, /**< Clock is active low, data is changed on second edge  */
     .oversample                 = 8,   						/*** SPI_CLOCK divided by SCB_SPI_OVERSAMPLING shoud be baudrate  ***/
     .rxDataWidth                = 8,                     /*** The width of RX data (valid range 4-16). It must be the same as \ref txDataWidth except in National sub-mode. ***/
     .txDataWidth                = 8,                     /*** The width of TX data (valid range 4-16). It must be the same as \ref rxDataWidth except in National sub-mode. ***/
     .enableMsbFirst             = true,                   /*** Enables the hardware to shift out the data element MSB first, otherwise, LSB first ***/
     .enableFreeRunSclk          = false,                  /*** Enables the master to generate a continuous SCLK regardless of whether there is data to send  ***/
     .enableInputFilter          = false,                  /*** Enables a digital 3-tap median filter to be applied to the input of the RX FIFO to filter glitches on the line. ***/
     .enableMisoLateSample       = false,                   /*** Enables the master to sample MISO line one half clock later to allow better timings. ***/
     .enableTransferSeperation   = true,                   /*** Enables the master to transmit each data element separated by a de-assertion of the slave select line (only applicable for the master mode) ***/
     .ssPolarity0                = 0,                      /*** SS0: active low ***/
     .ssPolarity1                = 0,                      /*** SS1: active low ***/
     .ssPolarity2                = 0,                      /*** SS2: active low ***/
     .ssPolarity3                = 0,                      /*** SS3: active low ***/
     .enableWakeFromSleep        = 0,                      /*** When set, the slave will wake the device when the slave select line becomes active. Note that not all SCBs support this mode. Consult the device datasheet to determine which SCBs support wake from deep sleep. ***/
     .txFifoTriggerLevel         = 0,                      /*** When there are fewer entries in the TX FIFO, then at this level the TX trigger output goes high. This output can be connected to a DMA channel through a trigger mux. Also, it controls the \ref CY_SCB_SPI_TX_TRIGGER interrupt source. ***/
     .rxFifoTriggerLevel         = 0,                    /*** When there are more entries in the RX FIFO, then at this level the RX trigger output goes high. This output can be connected to a DMA channel through a trigger mux. Also, it controls the \ref CY_SCB_SPI_RX_TRIGGER interrupt source.  ***/
     .rxFifoIntEnableMask        = 0,                      /*** Bits set in this mask will allow events to cause an interrupt  ***/
     .txFifoIntEnableMask        = 0,                      /*** Bits set in this mask allow events to cause an interrupt  ***/
     .masterSlaveIntEnableMask   = 0,                      /*** Bits set in this mask allow events to cause an interrupt  ***/
     .enableSpiDoneInterrupt     = true,
     .enableSpiBusErrorInterrupt = 0,
 };
#endif

#if (SPID_PHYS_CHANNEL2  == _USED_)
 const cy_stc_scb_spi_config_t Spid_SpiCfgScb2 =
 {
     .spiMode                    = CY_SCB_SPI_MASTER,      /*** Specifies the mode of operation    ***/
     .subMode                    = CY_SCB_SPI_MOTOROLA,    /*** Specifies the submode of SPI operation    ***/
     .sclkMode                   = CY_SCB_SPI_CPHA0_CPOL0, /**< Clock is active low, data is changed on second edge  */
     .oversample                 = 16,/*8,*/   						/*** SPI_CLOCK divided by SCB_SPI_OVERSAMPLING shoud be baudrate  ***/
     .rxDataWidth                = 16,/*8,*/                     /*** The width of RX data (valid range 4-16). It must be the same as \ref txDataWidth except in National sub-mode. ***/
     .txDataWidth                = 16,/*8, */                    /*** The width of TX data (valid range 4-16). It must be the same as \ref rxDataWidth except in National sub-mode. ***/
     .enableMsbFirst             = true,                   /*** Enables the hardware to shift out the data element MSB first, otherwise, LSB first ***/
     .enableFreeRunSclk          = false,                  /*** Enables the master to generate a continuous SCLK regardless of whether there is data to send  ***/
     .enableInputFilter          = false,                 /*** Enables a digital 3-tap median filter to be applied to the input of the RX FIFO to filter glitches on the line. ***/
     .enableMisoLateSample       = true,/*false,   */         /*** Enables the master to sample MISO line one half clock later to allow better timings. ***/
     .enableTransferSeperation   = true,                   /*** Enables the master to transmit each data element separated by a de-assertion of the slave select line (only applicable for the master mode) ***/
     .ssPolarity0                = 0,                      /*** SS0: active low ***/
     .ssPolarity1                = 0,                      /*** SS1: active low ***/
     .ssPolarity2                = 0,                      /*** SS2: active low ***/
     .ssPolarity3                = 0,                      /*** SS3: active low ***/
     .enableWakeFromSleep        = 0,                      /*** When set, the slave will wake the device when the slave select line becomes active. Note that not all SCBs support this mode. Consult the device datasheet to determine which SCBs support wake from deep sleep. ***/
     .txFifoTriggerLevel         = 0,                      /*** When there are fewer entries in the TX FIFO, then at this level the TX trigger output goes high. This output can be connected to a DMA channel through a trigger mux. Also, it controls the \ref CY_SCB_SPI_TX_TRIGGER interrupt source. ***/
     .rxFifoTriggerLevel         = 0,                    /*** When there are more entries in the RX FIFO, then at this level the RX trigger output goes high. This output can be connected to a DMA channel through a trigger mux. Also, it controls the \ref CY_SCB_SPI_RX_TRIGGER interrupt source.  ***/
     .rxFifoIntEnableMask        = 0,                      /*** Bits set in this mask will allow events to cause an interrupt  ***/
     .txFifoIntEnableMask        = 0,                      /*** Bits set in this mask allow events to cause an interrupt  ***/
     .masterSlaveIntEnableMask   = 0,                      /*** Bits set in this mask allow events to cause an interrupt  ***/
     .enableSpiDoneInterrupt     = true,
     .enableSpiBusErrorInterrupt = 0,
 };
#endif

#if (SPID_PHYS_CHANNEL3  == _USED_)
 const cy_stc_scb_spi_config_t Spid_SpiCfgScb3 =
 {
     .spiMode                    = CY_SCB_SPI_MASTER,      /*** Specifies the mode of operation    ***/
     .subMode                    = CY_SCB_SPI_MOTOROLA,    /*** Specifies the submode of SPI operation    ***/
     .sclkMode                   = CY_SCB_SPI_CPHA1_CPOL1, /**< Clock is active low, data is changed on second edge  */
     .oversample                 = 8,   						/*** SPI_CLOCK divided by SCB_SPI_OVERSAMPLING shoud be baudrate  ***/
     .rxDataWidth                = 8,                     /*** The width of RX data (valid range 4-16). It must be the same as \ref txDataWidth except in National sub-mode. ***/
     .txDataWidth                = 8,                     /*** The width of TX data (valid range 4-16). It must be the same as \ref rxDataWidth except in National sub-mode. ***/
     .enableMsbFirst             = true,                   /*** Enables the hardware to shift out the data element MSB first, otherwise, LSB first ***/
     .enableFreeRunSclk          = false,                  /*** Enables the master to generate a continuous SCLK regardless of whether there is data to send  ***/
     .enableInputFilter          = false,                  /*** Enables a digital 3-tap median filter to be applied to the input of the RX FIFO to filter glitches on the line. ***/
     .enableMisoLateSample       = false,                   /*** Enables the master to sample MISO line one half clock later to allow better timings. ***/
     .enableTransferSeperation   = true,                   /*** Enables the master to transmit each data element separated by a de-assertion of the slave select line (only applicable for the master mode) ***/
     .ssPolarity0                = 0,                      /*** SS0: active low ***/
     .ssPolarity1                = 0,                      /*** SS1: active low ***/
     .ssPolarity2                = 0,                      /*** SS2: active low ***/
     .ssPolarity3                = 0,                      /*** SS3: active low ***/
     .enableWakeFromSleep        = 0,                      /*** When set, the slave will wake the device when the slave select line becomes active. Note that not all SCBs support this mode. Consult the device datasheet to determine which SCBs support wake from deep sleep. ***/
     .txFifoTriggerLevel         = 0,                      /*** When there are fewer entries in the TX FIFO, then at this level the TX trigger output goes high. This output can be connected to a DMA channel through a trigger mux. Also, it controls the \ref CY_SCB_SPI_TX_TRIGGER interrupt source. ***/
     .rxFifoTriggerLevel         = 0,                    /*** When there are more entries in the RX FIFO, then at this level the RX trigger output goes high. This output can be connected to a DMA channel through a trigger mux. Also, it controls the \ref CY_SCB_SPI_RX_TRIGGER interrupt source.  ***/
     .rxFifoIntEnableMask        = 0,                      /*** Bits set in this mask will allow events to cause an interrupt  ***/
     .txFifoIntEnableMask        = 0,                      /*** Bits set in this mask allow events to cause an interrupt  ***/
     .masterSlaveIntEnableMask   = 0,                      /*** Bits set in this mask allow events to cause an interrupt  ***/
     .enableSpiDoneInterrupt     = true,
     .enableSpiBusErrorInterrupt = 0,
 };
#endif

#if (SPID_PHYS_CHANNEL4  == _USED_)
 const cy_stc_scb_spi_config_t Spid_SpiCfgScb4 =
 {
     .spiMode                    = CY_SCB_SPI_MASTER,      /*** Specifies the mode of operation    ***/
     .subMode                    = CY_SCB_SPI_MOTOROLA,    /*** Specifies the submode of SPI operation    ***/
     .sclkMode                   = CY_SCB_SPI_CPHA1_CPOL1, /**< Clock is active low, data is changed on second edge  */
     .oversample                 = 8,   						/*** SPI_CLOCK divided by SCB_SPI_OVERSAMPLING shoud be baudrate  ***/
     .rxDataWidth                = 8,                     /*** The width of RX data (valid range 4-16). It must be the same as \ref txDataWidth except in National sub-mode. ***/
     .txDataWidth                = 8,                     /*** The width of TX data (valid range 4-16). It must be the same as \ref rxDataWidth except in National sub-mode. ***/
     .enableMsbFirst             = true,                   /*** Enables the hardware to shift out the data element MSB first, otherwise, LSB first ***/
     .enableFreeRunSclk          = false,                  /*** Enables the master to generate a continuous SCLK regardless of whether there is data to send  ***/
     .enableInputFilter          = false,                  /*** Enables a digital 3-tap median filter to be applied to the input of the RX FIFO to filter glitches on the line. ***/
     .enableMisoLateSample       = false,                   /*** Enables the master to sample MISO line one half clock later to allow better timings. ***/
     .enableTransferSeperation   = true,                   /*** Enables the master to transmit each data element separated by a de-assertion of the slave select line (only applicable for the master mode) ***/
     .ssPolarity0                = 0,                      /*** SS0: active low ***/
     .ssPolarity1                = 0,                      /*** SS1: active low ***/
     .ssPolarity2                = 0,                      /*** SS2: active low ***/
     .ssPolarity3                = 0,                      /*** SS3: active low ***/
     .enableWakeFromSleep        = 0,                      /*** When set, the slave will wake the device when the slave select line becomes active. Note that not all SCBs support this mode. Consult the device datasheet to determine which SCBs support wake from deep sleep. ***/
     .txFifoTriggerLevel         = 0,                      /*** When there are fewer entries in the TX FIFO, then at this level the TX trigger output goes high. This output can be connected to a DMA channel through a trigger mux. Also, it controls the \ref CY_SCB_SPI_TX_TRIGGER interrupt source. ***/
     .rxFifoTriggerLevel         = 0,                    /*** When there are more entries in the RX FIFO, then at this level the RX trigger output goes high. This output can be connected to a DMA channel through a trigger mux. Also, it controls the \ref CY_SCB_SPI_RX_TRIGGER interrupt source.  ***/
     .rxFifoIntEnableMask        = 0,                      /*** Bits set in this mask will allow events to cause an interrupt  ***/
     .txFifoIntEnableMask        = 0,                      /*** Bits set in this mask allow events to cause an interrupt  ***/
     .masterSlaveIntEnableMask   = 0,                      /*** Bits set in this mask allow events to cause an interrupt  ***/
     .enableSpiDoneInterrupt     = true,
     .enableSpiBusErrorInterrupt = 0,
 };
#endif

#if (SPID_PHYS_CHANNEL5  == _USED_)
 const cy_stc_scb_spi_config_t Spid_SpiCfgScb5 =
 {
     .spiMode                    = CY_SCB_SPI_MASTER,      /*** Specifies the mode of operation    ***/
     .subMode                    = CY_SCB_SPI_MOTOROLA,    /*** Specifies the submode of SPI operation    ***/
     .sclkMode                   = CY_SCB_SPI_CPHA1_CPOL1, /**< Clock is active low, data is changed on second edge  */
     .oversample                 = 8,   						/*** SPI_CLOCK divided by SCB_SPI_OVERSAMPLING shoud be baudrate  ***/
     .rxDataWidth                = 8,                     /*** The width of RX data (valid range 4-16). It must be the same as \ref txDataWidth except in National sub-mode. ***/
     .txDataWidth                = 8,                     /*** The width of TX data (valid range 4-16). It must be the same as \ref rxDataWidth except in National sub-mode. ***/
     .enableMsbFirst             = true,                   /*** Enables the hardware to shift out the data element MSB first, otherwise, LSB first ***/
     .enableFreeRunSclk          = false,                  /*** Enables the master to generate a continuous SCLK regardless of whether there is data to send  ***/
     .enableInputFilter          = true,                  /*** Enables a digital 3-tap median filter to be applied to the input of the RX FIFO to filter glitches on the line. ***/
     .enableMisoLateSample       = true,                   /*** Enables the master to sample MISO line one half clock later to allow better timings. ***/
     .enableTransferSeperation   = true,                   /*** Enables the master to transmit each data element separated by a de-assertion of the slave select line (only applicable for the master mode) ***/
     .ssPolarity0                = 0,                      /*** SS0: active low ***/
     .ssPolarity1                = 0,                      /*** SS1: active low ***/
     .ssPolarity2                = 0,                      /*** SS2: active low ***/
     .ssPolarity3                = 0,                      /*** SS3: active low ***/
     .enableWakeFromSleep        = 0,                      /*** When set, the slave will wake the device when the slave select line becomes active. Note that not all SCBs support this mode. Consult the device datasheet to determine which SCBs support wake from deep sleep. ***/
     .txFifoTriggerLevel         = 0,                      /*** When there are fewer entries in the TX FIFO, then at this level the TX trigger output goes high. This output can be connected to a DMA channel through a trigger mux. Also, it controls the \ref CY_SCB_SPI_TX_TRIGGER interrupt source. ***/
     .rxFifoTriggerLevel         = 0,                    /*** When there are more entries in the RX FIFO, then at this level the RX trigger output goes high. This output can be connected to a DMA channel through a trigger mux. Also, it controls the \ref CY_SCB_SPI_RX_TRIGGER interrupt source.  ***/
     .rxFifoIntEnableMask        = 0,                      /*** Bits set in this mask will allow events to cause an interrupt  ***/
     .txFifoIntEnableMask        = 0,                      /*** Bits set in this mask allow events to cause an interrupt  ***/
     .masterSlaveIntEnableMask   = 0,                      /*** Bits set in this mask allow events to cause an interrupt  ***/
     .enableSpiDoneInterrupt     = true,
     .enableSpiBusErrorInterrupt = 0,
 };
#endif

#if (SPID_PHYS_CHANNEL6  == _USED_)
 const cy_stc_scb_spi_config_t Spid_SpiCfgScb6 =
 {
     .spiMode                    = CY_SCB_SPI_MASTER,      /*** Specifies the mode of operation    ***/
     .subMode                    = CY_SCB_SPI_MOTOROLA,    /*** Specifies the submode of SPI operation    ***/
     .sclkMode                   = CY_SCB_SPI_CPHA1_CPOL1, /**< Clock is active low, data is changed on second edge  */
     .oversample                 = 8,   						/*** SPI_CLOCK divided by SCB_SPI_OVERSAMPLING shoud be baudrate  ***/
     .rxDataWidth                = 8,                     /*** The width of RX data (valid range 4-16). It must be the same as \ref txDataWidth except in National sub-mode. ***/
     .txDataWidth                = 8,                     /*** The width of TX data (valid range 4-16). It must be the same as \ref rxDataWidth except in National sub-mode. ***/
     .enableMsbFirst             = true,                   /*** Enables the hardware to shift out the data element MSB first, otherwise, LSB first ***/
     .enableFreeRunSclk          = false,                  /*** Enables the master to generate a continuous SCLK regardless of whether there is data to send  ***/
     .enableInputFilter          = false,                  /*** Enables a digital 3-tap median filter to be applied to the input of the RX FIFO to filter glitches on the line. ***/
     .enableMisoLateSample       = false,                   /*** Enables the master to sample MISO line one half clock later to allow better timings. ***/
     .enableTransferSeperation   = true,                   /*** Enables the master to transmit each data element separated by a de-assertion of the slave select line (only applicable for the master mode) ***/
     .ssPolarity0                = 0,                      /*** SS0: active low ***/
     .ssPolarity1                = 0,                      /*** SS1: active low ***/
     .ssPolarity2                = 0,                      /*** SS2: active low ***/
     .ssPolarity3                = 0,                      /*** SS3: active low ***/
     .enableWakeFromSleep        = 0,                      /*** When set, the slave will wake the device when the slave select line becomes active. Note that not all SCBs support this mode. Consult the device datasheet to determine which SCBs support wake from deep sleep. ***/
     .txFifoTriggerLevel         = 0,                      /*** When there are fewer entries in the TX FIFO, then at this level the TX trigger output goes high. This output can be connected to a DMA channel through a trigger mux. Also, it controls the \ref CY_SCB_SPI_TX_TRIGGER interrupt source. ***/
     .rxFifoTriggerLevel         = 0,                    /*** When there are more entries in the RX FIFO, then at this level the RX trigger output goes high. This output can be connected to a DMA channel through a trigger mux. Also, it controls the \ref CY_SCB_SPI_RX_TRIGGER interrupt source.  ***/
     .rxFifoIntEnableMask        = 0,                      /*** Bits set in this mask will allow events to cause an interrupt  ***/
     .txFifoIntEnableMask        = 0,                      /*** Bits set in this mask allow events to cause an interrupt  ***/
     .masterSlaveIntEnableMask   = 0,                      /*** Bits set in this mask allow events to cause an interrupt  ***/
     .enableSpiDoneInterrupt     = true,
     .enableSpiBusErrorInterrupt = 0,
 };
#endif

#if (SPID_PHYS_CHANNEL7  == _USED_)
 const cy_stc_scb_spi_config_t Spid_SpiCfgScb7 =
 {
     .spiMode                    = CY_SCB_SPI_MASTER,      /*** Specifies the mode of operation    ***/
     .subMode                    = CY_SCB_SPI_MOTOROLA,    /*** Specifies the submode of SPI operation    ***/
     .sclkMode                   = CY_SCB_SPI_CPHA1_CPOL1, /**< Clock is active low, data is changed on second edge  */
     .oversample                 = 8,   						/*** SPI_CLOCK divided by SCB_SPI_OVERSAMPLING shoud be baudrate  ***/
     .rxDataWidth                = 8,                     /*** The width of RX data (valid range 4-16). It must be the same as \ref txDataWidth except in National sub-mode. ***/
     .txDataWidth                = 8,                     /*** The width of TX data (valid range 4-16). It must be the same as \ref rxDataWidth except in National sub-mode. ***/
     .enableMsbFirst             = true,                   /*** Enables the hardware to shift out the data element MSB first, otherwise, LSB first ***/
     .enableFreeRunSclk          = false,                  /*** Enables the master to generate a continuous SCLK regardless of whether there is data to send  ***/
     .enableInputFilter          = false,                  /*** Enables a digital 3-tap median filter to be applied to the input of the RX FIFO to filter glitches on the line. ***/
     .enableMisoLateSample       = false,                   /*** Enables the master to sample MISO line one half clock later to allow better timings. ***/
     .enableTransferSeperation   = true,                   /*** Enables the master to transmit each data element separated by a de-assertion of the slave select line (only applicable for the master mode) ***/
     .ssPolarity0                = 0,                      /*** SS0: active low ***/
     .ssPolarity1                = 0,                      /*** SS1: active low ***/
     .ssPolarity2                = 0,                      /*** SS2: active low ***/
     .ssPolarity3                = 0,                      /*** SS3: active low ***/
     .enableWakeFromSleep        = 0,                      /*** When set, the slave will wake the device when the slave select line becomes active. Note that not all SCBs support this mode. Consult the device datasheet to determine which SCBs support wake from deep sleep. ***/
     .txFifoTriggerLevel         = 0,                      /*** When there are fewer entries in the TX FIFO, then at this level the TX trigger output goes high. This output can be connected to a DMA channel through a trigger mux. Also, it controls the \ref CY_SCB_SPI_TX_TRIGGER interrupt source. ***/
     .rxFifoTriggerLevel         = 0,                    /*** When there are more entries in the RX FIFO, then at this level the RX trigger output goes high. This output can be connected to a DMA channel through a trigger mux. Also, it controls the \ref CY_SCB_SPI_RX_TRIGGER interrupt source.  ***/
     .rxFifoIntEnableMask        = 0,                      /*** Bits set in this mask will allow events to cause an interrupt  ***/
     .txFifoIntEnableMask        = 0,                      /*** Bits set in this mask allow events to cause an interrupt  ***/
     .masterSlaveIntEnableMask   = 0,                      /*** Bits set in this mask allow events to cause an interrupt  ***/
     .enableSpiDoneInterrupt     = true,
     .enableSpiBusErrorInterrupt = 0,
 };
#endif


#if (SPID_PHYS_CHANNEL0  == _USED_)
cy_stc_gpio_pin_config_t Spid_PortPinCfgScb0 =
{
    .outVal   = 0x00,
    .intEdge  = 0,
    .intMask  = 0,
    .vtrip    = 0,
    .slewRate = 0,
    .driveSel = 0,
    .vregEn   = 0,
    .ibufMode = 0,
    .vtripSel = 0,
    .vrefSel  = 0,
    .vohSel   = 0,
};
#endif

#if (SPID_PHYS_CHANNEL1  == _USED_)
cy_stc_gpio_pin_config_t Spid_PortPinCfgScb1 =
{
    .outVal   = 0x00,
    .intEdge  = 0,
    .intMask  = 0,
    .vtrip    = 0,
    .slewRate = 0,
    .driveSel = 0,
    .vregEn   = 0,
    .ibufMode = 0,
    .vtripSel = 0,
    .vrefSel  = 0,
    .vohSel   = 0,
};
#endif

#if (SPID_PHYS_CHANNEL2  == _USED_)
cy_stc_gpio_pin_config_t Spid_PortPinCfgScb2 =
{
    .outVal   = 0x00,
    .intEdge  = 0,
    .intMask  = 0,
    .vtrip    = 0,
    .slewRate = 0,
    .driveSel = 0,
    .vregEn   = 0,
    .ibufMode = 0,
    .vtripSel = 0,
    .vrefSel  = 0,
    .vohSel   = 0,
};
#endif

#if (SPID_PHYS_CHANNEL3  == _USED_)
cy_stc_gpio_pin_config_t Spid_PortPinCfgScb3 =
{
    .outVal   = 0x00,
    .intEdge  = 0,
    .intMask  = 0,
    .vtrip    = 0,
    .slewRate = 0,
    .driveSel = 0,
    .vregEn   = 0,
    .ibufMode = 0,
    .vtripSel = 0,
    .vrefSel  = 0,
    .vohSel   = 0,
};
#endif

#if (SPID_PHYS_CHANNEL4  == _USED_)
cy_stc_gpio_pin_config_t Spid_PortPinCfgScb4 =
{
    .outVal   = 0x00,
    .intEdge  = 0,
    .intMask  = 0,
    .vtrip    = 0,
    .slewRate = 0,
    .driveSel = 0,
    .vregEn   = 0,
    .ibufMode = 0,
    .vtripSel = 0,
    .vrefSel  = 0,
    .vohSel   = 0,
};
#endif

#if (SPID_PHYS_CHANNEL5  == _USED_)
cy_stc_gpio_pin_config_t Spid_PortPinCfgScb5 =
{
    .outVal   = 0x00,
    .intEdge  = 0,
    .intMask  = 0,
    .vtrip    = 0,
    .slewRate = 0,
    .driveSel = 0,
    .vregEn   = 0,
    .ibufMode = 0,
    .vtripSel = 0,
    .vrefSel  = 0,
    .vohSel   = 0,
};
#endif

#if (SPID_PHYS_CHANNEL6  == _USED_)
cy_stc_gpio_pin_config_t Spid_PortPinCfgScb6 =
{
    .outVal   = 0x00,
    .intEdge  = 0,
    .intMask  = 0,
    .vtrip    = 0,
    .slewRate = 0,
    .driveSel = 0,
    .vregEn   = 0,
    .ibufMode = 0,
    .vtripSel = 0,
    .vrefSel  = 0,
    .vohSel   = 0,
};
#endif

#if (SPID_PHYS_CHANNEL7  == _USED_)
cy_stc_gpio_pin_config_t Spid_PortPinCfgScb7 =
{
    .outVal   = 0x00,
    .intEdge  = 0,
    .intMask  = 0,
    .vtrip    = 0,
    .slewRate = 0,
    .driveSel = 0,
    .vregEn   = 0,
    .ibufMode = 0,
    .vtripSel = 0,
    .vrefSel  = 0,
    .vohSel   = 0,
};
#endif
/*______ P R I V A T E - D A T A _____________________________________________*/


/*______ L O C A L - D A T A _________________________________________________*/


/*______ L O C A L - M A C R O S _____________________________________________*/


/*______ I M P O R T - F U N C T I O N S - P R O T O T Y P E S _______________*/


/*______ L O C A L - F U N C T I O N S - P R O T O T Y P E S _________________*/


/*______ G L O B A L - F U N C T I O N S _____________________________________*/


/*______ P R I V A T E - F U N C T I O N S ___________________________________*/


/*______ L O C A L - F U N C T I O N S _______________________________________*/


/*______ E N D _____ (xxxx_config.c) _________________________________________*/

