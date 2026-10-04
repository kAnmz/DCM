/******************************************************************************/
/*@F_NAME:             spid.h                                                 */
/*@F_PURPOSE:          Serial Synchronous Peripheral Interface Driver public  */
/*                     header                                                 */
/*@F_CREATED_BY:       Olivier DIETLIN                                        */
/*@F_CREATION_DATE:    05/04/2004                                             */
/*@F_MPROC_TYPE:       NEC_V850 Fx3/Dx3/Dx4, MC9S12xx, MC9S08xx, TX49, IMX53  */
/*                     ,IMX6x, Renesas RL78 D1A, RL78 F12                     */
/************************************** (C) Copyright 2014 Magneti Marelli ****/

#ifndef SPID_H
#define SPID_H


/*_____ I N C L U D E - F I L E S ____________________________________________*/

#include "syst.h"
#ifndef  __CY_TV2__
#include "spid_config.h"
#endif
#if defined(__FSL_IMX53x__) || defined(__FSL_IMX6x__)
#include "spid_priv.h"
#endif /* __FSL_IMX53x__, __FSL_IMX6x__ */

#ifdef __RH850__
#include "spid_rh850.h"
#endif

#ifdef  __CY_TV2__
#include "spid_tv2.h"
#endif

/*______G L O B A L - D E F I N E S __________________________________________*/

#ifdef __REL_RL78__
#ifdef __REL_RL78_D1x__
#ifdef __REL_RL78_D1A__

#define SPID_RX0 SDR00L
#define SPID_RX1 SDR01L
#define SPID_RX2 SDR10L

#define SPID_WORD_RX0 SDR00
#define SPID_WORD_RX1 SDR01
#define SPID_WORD_RX2 SDR10

#define SPID_FLAG_REG0 IF0H
#define SPID_FLAG_REG1 IF0H
#define SPID_FLAG_REG2 IF1H

#define SPID_WORD_FLAG_REG0 IF0H
#define SPID_WORD_FLAG_REG1 IF0H
#define SPID_WORD_FLAG_REG2 IF1H

#define SPID_FLAG0 SPI_BIT_CSIIF00
#define SPID_FLAG1 SPI_BIT_CSIIF01
#define SPID_FLAG2 SPI_BIT_CSIIF10

#define SPID_EN_REG0 SS0L
#define SPID_EN_REG1 SS0L
#define SPID_EN_REG2 SS1L

#define SPID_EN_FLAG0 SPI_BIT_SS00
#define SPID_EN_FLAG1 SPI_BIT_SS01
#define SPID_EN_FLAG2 SPI_BIT_SS10

#define SPID_DIS_REG0 ST0L
#define SPID_DIS_REG1 ST0L
#define SPID_DIS_REG2 ST1L

#define SPID_DIS_FLAG0 SPI_BIT_ST00
#define SPID_DIS_FLAG1 SPI_BIT_ST01
#define SPID_DIS_FLAG2 SPI_BIT_ST10

#define SPID_WORD_FLAG0 SPI_BIT_CSIIF00
#define SPID_WORD_FLAG1 SPI_BIT_CSIIF01
#define SPID_WORD_FLAG2 SPI_BIT_CSIIF10

#define SPID_TX0 SDR00L
#define SPID_TX1 SDR01L
#define SPID_TX2 SDR10L

#define SPID_WORD_TX0 SDR00
#define SPID_WORD_TX1 SDR01
#define SPID_WORD_TX2 SDR10

#endif /* __REL_RL78_D1A__ */
#endif /* __REL_RL78_D1x__ */

#ifdef __REL_RL78_F1x__
#ifdef __REL_RL78_F12__

#define SPID_RX0 SDR00L
#define SPID_RX1 SDR01L
#define SPID_RX2 SDR02L
#define SPID_RX3 SDR03L
#define SPID_RX4 SDR10L
#define SPID_RX5 SDR11L
#define SPID_RX6 SDRS0L
#define SPID_RX7 SDRS1L

#define SPID_TX0 SDR00L
#define SPID_TX1 SDR01L
#define SPID_TX2 SDR02L
#define SPID_TX3 SDR03L
#define SPID_TX4 SDR10L
#define SPID_TX5 SDR11L
#define SPID_TX6 SDRS0L
#define SPID_TX7 SDRS1L

#define SPID_FLAG_REG0 IF0H
#define SPID_FLAG_REG1 IF0H
#define SPID_FLAG_REG2 IF1L
#define SPID_FLAG_REG3 IF1L
#define SPID_FLAG_REG4 IF0H
#define SPID_FLAG_REG5 IF0H
#define SPID_FLAG_REG6 IF1H
#define SPID_FLAG_REG7 IF1H

#define SPID_FLAG0 SPI_BIT_CSIIF00
#define SPID_FLAG1 SPI_BIT_CSIIF01
#define SPID_FLAG2 SPI_BIT_CSIIF10
#define SPID_FLAG3 SPI_BIT_CSIIF11
#define SPID_FLAG4 SPI_BIT_CSIIF20
#define SPID_FLAG5 SPI_BIT_CSIIF21
#define SPID_FLAG6 SPI_BIT_CSIIFS0
#define SPID_FLAG7 SPI_BIT_CSIIFS1

#define SPID_EN_REG0 SS0L
#define SPID_EN_REG1 SS0L
#define SPID_EN_REG2 SS0L
#define SPID_EN_REG3 SS0L
#define SPID_EN_REG4 SS1L
#define SPID_EN_REG5 SS1L
#define SPID_EN_REG6 SSSL
#define SPID_EN_REG7 SSSL

#define SPID_EN_FLAG0 SPI_BIT_SS00
#define SPID_EN_FLAG1 SPI_BIT_SS01
#define SPID_EN_FLAG2 SPI_BIT_SS02
#define SPID_EN_FLAG3 SPI_BIT_SS03
#define SPID_EN_FLAG4 SPI_BIT_SS10
#define SPID_EN_FLAG5 SPI_BIT_SS11
#define SPID_EN_FLAG6 SPI_BIT_SSS0
#define SPID_EN_FLAG7 SPI_BIT_SSS1

#define SPID_DIS_REG0 ST0L
#define SPID_DIS_REG1 ST0L
#define SPID_DIS_REG2 ST0L
#define SPID_DIS_REG3 ST0L
#define SPID_DIS_REG4 ST1L
#define SPID_DIS_REG5 ST1L
#define SPID_DIS_REG6 STSL
#define SPID_DIS_REG7 STSL

#define SPID_DIS_FLAG0 SPI_BIT_ST00
#define SPID_DIS_FLAG1 SPI_BIT_ST01
#define SPID_DIS_FLAG2 SPI_BIT_ST02
#define SPID_DIS_FLAG3 SPI_BIT_ST03
#define SPID_DIS_FLAG4 SPI_BIT_ST10
#define SPID_DIS_FLAG5 SPI_BIT_ST11
#define SPID_DIS_FLAG6 SPI_BIT_STS0
#define SPID_DIS_FLAG7 SPI_BIT_STS1

/* Word transfer works only on channel no. 6 & 7 */
#define SPID_WORD_TX6 SDRS0
#define SPID_WORD_TX7 SDRS1

#define SPID_WORD_RX6 SDRS0
#define SPID_WORD_RX7 SDRS1

#define SPID_WORD_FLAG_REG6 IF1H
#define SPID_WORD_FLAG_REG7 IF1H

#define SPID_WORD_FLAG6 SPI_BIT_CSIIFS0
#define SPID_WORD_FLAG7 SPI_BIT_CSIIFS1

#endif  /*__REL_RL78_F12__ */
#endif /* __REL_RL78_F1x__ */

#endif /* __REL_RL78__ */

#ifdef __NEC_V850__

#ifdef __NEC_V850_Fx3__
#define SPID_TX0 CB0TXL
#define SPID_TX1 CB1TXL
#define SPID_TX2 CB2TXL
#define SPID_TX3 CB3TXL

#define SPID_RX0 CB0RXL
#define SPID_RX1 CB1RXL
#define SPID_RX2 CB2RXL
#define SPID_RX3 CB3RXL
#endif /* __NEC_V850_Fx3__ */

#ifdef __NEC_V850_Dx3__
#define SPID_TX0 CB0TX0L
#define SPID_TX1 CB1TX0L

#define SPID_RX0 CB0RX0L
#define SPID_RX1 CB1RX0L

#if defined (__NEC_V850_DJ3_HE__) || \
    defined (__NEC_V850_DL3__)
#define SPID_TX2 CB2TX0L
#define SPID_RX2 CB2RX0L
#endif /* defined (__NEC_V850_DJ3_HE__) || \
          defined (__NEC_V850_DL3__) */
#endif /* __NEC_V850_Dx3__ */

#ifdef __REL_V850_Dx4__
#define SPID_TX0 CSIG0TX0H
#define SPID_TX1 CSIG1TX0H

#define SPID_RX0 CSIG0RX0
#define SPID_RX1 CSIG1RX0

#if !defined (__REL_V850_DK4H__)
#define SPID_TX2 CSIG2TX0H
#define SPID_RX2 CSIG2RX0
#endif /* !defined (__REL_V850_DK4H__) */
#endif /* __REL_V850_Dx4__ */

#endif /* NEC_V850__ */


/*_____ G L O B A L - T Y P E S ______________________________________________*/


/*_____ G L O B A L - M A C R O ______________________________________________*/

/******************************************************************************/
/* Name: SPID_Enable                                                          */
/* Role: Provide the mean to enable activity of selected channel              */
/* Interface: Channel       IN   Communication channel number                 */
/* Pre-condition: none                                                        */
/* Constraints: none                                                          */
/******************************************************************************/
#ifdef __MC9S12xx__
#define SPID_Enable(Channel) \
        TARG_WriteBit(SPICR1, SPI_BIT_SPE, 1)
#endif /* __MC9S12xx__ */

#ifdef __MC9S08AWxx__
#define SPID_Enable(Channel) \
        TARG_WriteBit(SPI1C1, SPI_BIT_SPE, 1)
#endif /* __MC9S08AWxx__ */

#ifdef __NEC_V850__
#if (defined(__NEC_V850_Fx3__) || defined(__NEC_V850_Dx3__))
#define SPID_Enable(Channel) \
        TARG_WriteBit(CB ## Channel ## CTL0, CSI_BIT_CB ## Channel ## PWR, 1)
#endif /* defined(__NEC_V850_Fx3__) || defined(__NEC_V850_Dx3__) */

#if defined(__REL_V850_Dx4__)
#define SPID_Enable(Channel) \
        TARG_WriteBit(CSIG ## Channel ## CTL0, CSI_BIT_CSIG ## Channel ## PWR, 1)
#endif /* defined(__REL_V850_Dx4__) */
#endif /* __NEC_V850__ */

#ifdef __TX49__
#define SPID_Enable(Channel) \
        TARG_WriteBit(SEMCR_##Channel, SPI_BIT_SESTP, 1)
#endif /* __TX49__ */

#ifdef __FSL_IMX53x__
#define SPID_Enable(Channel)                             \
        if(Channel < 4)                                  \
        {                                                \
          TARG_WriteBit(CSPI_CONREG, SPI_BIT_EN, 1);     \
        }                                                \
        else if (Channel < 8)                            \
        {                                                \
          TARG_WriteBit(ECSPI1_CONREG, SPI_E_BIT_EN, 1); \
        }                                                \
        else if (Channel < 12)                           \
        {                                                \
          TARG_WriteBit(ECSPI2_CONREG, SPI_E_BIT_EN, 1); \
        }
#endif /* __FSL_IMX53x__ */

#ifdef __FSL_IMX6x__
#define SPID_Enable(Channel)                             \
        if(Channel < 4)                                  \
        {                                                \
          TARG_WriteBit(ECSPI1_CONREG, SPI_BIT_EN, 1);     \
        }                                                \
        else if (Channel < 8)                            \
        {                                                \
          TARG_WriteBit(ECSPI2_CONREG, SPI_E_BIT_EN, 1); \
        }                                                \
        else if (Channel < 12)                           \
        {                                                \
          TARG_WriteBit(ECSPI3_CONREG, SPI_E_BIT_EN, 1); \
        }                           \
    else if (Channel < 16)                           \
        {                                                \
          TARG_WriteBit(ECSPI4_CONREG, SPI_E_BIT_EN, 1); \
        }

#endif /*__FSL_IMX6x__*/



#ifdef __REL_RL78__

#if (defined(__REL_RL78_D1A__) || defined(__REL_RL78_F12__))

#define SPID_Enable(Channel) \
  TARG_WriteBit(SPID_EN_REG ## Channel, SPID_EN_FLAG ## Channel, 1 );

#endif /* (defined(__REL_RL78_D1A__) || defined(__REL_RL78_F12__)) */

#endif /* __REL_RL78__ */


/******************************************************************************/
/* Name: SPID_Disable                                                         */
/* Role: Provide the mean to disable activity of selected channel             */
/* Interface: Channel       IN   Communication channel number                 */
/* Pre-condition: none                                                        */
/* Constraints: none                                                          */
/******************************************************************************/
#ifdef __MC9S12xx__
#define SPID_Disable(Channel) \
        TARG_WriteBit(SPICR1, SPI_BIT_SPE, 0)
#endif /* __MC9S12xx__ */

#ifdef __MC9S08xx__
#define SPID_Disable(Channel) \
        TARG_WriteBit(SPI1C1, SPI_BIT_SPE, 0)
#endif /* __MC9S08xx__ */

#ifdef __NEC_V850__
#if (defined(__NEC_V850_Fx3__) || defined(__NEC_V850_Dx3__))
#define SPID_Disable(Channel) \
        TARG_WriteBit(CB ## Channel ## CTL0, CSI_BIT_CB ## Channel ## PWR, 0)
#endif /* defined(__NEC_V850_Fx3__) || defined(__NEC_V850_Dx3__) */

#if defined(__REL_V850_Dx4__)
#define SPID_Disable(Channel) \
        TARG_WriteBit(CSIG ## Channel ## CTL0, CSI_BIT_CSIG ## Channel ## PWR, 0)
#endif /* defined(__REL_V850_Dx4__) */
#endif /* __NEC_V850__ */

#ifdef __TX49__
#define SPID_Disable(Channel) \
        TARG_WriteBit(SEMCR_##Channel, SPI_BIT_SESTP, 0)
#endif /* __TX49__ */

#ifdef __FSL_IMX53x__
#define SPID_Disable(Channel)                            \
        if(Channel < 4)                                  \
        {                                                \
          TARG_WriteBit(CSPI_CONREG, SPI_BIT_EN, 0);     \
        }                                                \
        else if (Channel < 8)                            \
        {                                                \
          TARG_WriteBit(ECSPI1_CONREG, SPI_E_BIT_EN, 0); \
        }                                                \
        else if (Channel < 12)                           \
        {                                                \
          TARG_WriteBit(ECSPI2_CONREG, SPI_E_BIT_EN, 0); \
        }
#endif /* __FSL_IMX53x__ */

#ifdef __FSL_IMX6x__
#define SPID_Disable(Channel)                             \
     if(Channel < 4)                                  \
        {                                                \
          TARG_WriteBit(ECSPI1_CONREG, SPI_BIT_EN, 0);     \
        }                                                \
        else if (Channel < 8)                            \
        {                                                \
          TARG_WriteBit(ECSPI2_CONREG, SPI_E_BIT_EN, 0); \
        }                                                \
        else if (Channel < 12)                           \
        {                                                \
          TARG_WriteBit(ECSPI3_CONREG, SPI_E_BIT_EN, 0); \
        }                                                 \
     else if (Channel < 16)                            \
        {                                                \
          TARG_WriteBit(ECSPI4_CONREG, SPI_E_BIT_EN, 0); \
        }

#endif /*  __FSL_IMX6x__*/

#ifdef __REL_RL78__

#if (defined(__REL_RL78_D1A__) || defined(__REL_RL78_F12__))

#define SPID_Disable(Channel) \
  TARG_WriteBit(SPID_DIS_REG ## Channel, SPID_DIS_FLAG ## Channel, 1 );

#endif /* (defined(__REL_RL78_D1A__) || defined(__REL_RL78_F12__)) */

#endif /* __REL_RL78__ */

/******************************************************************************/
/* Name: SPID_ReceiveByte                                                     */
/* Role: Provide the mean to read received byte on selected channel           */
/* Interface: Channel       IN   Communication channel number                 */
/*            ReceivedByte  OUT  Byte received from serial communication      */
/* Pre-condition: The receive data register for the channel must be full      */
/* Constraints: none                                                          */
/******************************************************************************/
#ifdef __MC9S12xx__
#define SPID_ReceiveByte(Channel) \
        TARG_ReadByte(SPIDR)
#endif /* __MC9S12xx__ */

#ifdef __MC9S08xx__
#define SPID_ReceiveByte(Channel) \
        TARG_ReadByte(SPI1D)
#endif /* __MC9S08xx__ */

#ifdef __NEC_V850__
#define SPID_ReceiveByte(Channel) \
        Spid_ReceiveByte##Channel()

#ifdef SPID_CHANNEL_0_ACTIVE
extern ubyte Spid_ReceiveByte0(void);
#endif /*SPID_CHANNEL_0_ACTIVE*/
#ifdef SPID_CHANNEL_1_ACTIVE
extern ubyte Spid_ReceiveByte1(void);
#endif /*SPID_CHANNEL_1_ACTIVE*/
#ifdef SPID_CHANNEL_2_ACTIVE
extern ubyte Spid_ReceiveByte2(void);
#endif /*SPID_CHANNEL_2_ACTIVE*/
#ifdef SPID_CHANNEL_3_ACTIVE
extern ubyte Spid_ReceiveByte3(void);
#endif /*SPID_CHANNEL_3_ACTIVE*/
#endif /* __NEC_V850__ */

#ifdef __TX49__
#define SPID_ReceiveByte(Channel) \
        Spid_ReceiveByteReg(Channel)
#define Spid_ReceiveByteReg(Channel) \
        TARG_ReadShort(SEDR_##Channel)
#endif /* __TX49__ */

#ifdef __REL_RL78__
#if defined(__REL_RL78_D1A__) || defined(__REL_RL78_F12__)
#define SPID_ReceiveByte(Channel) \
        TARG_ReadByte(SPID_RX ## Channel)
#endif /* defined(__REL_RL78_D1A__) || (__REL_RL78_F12__) */
#endif /* __REL_RL78__ */

/******************************************************************************/
/* Name: SPID_ReceiveWord                                                     */
/* Role: Provide the mean to read received Word on selected channel           */
/* Interface: Channel       IN   Communication channel number                 */
/*            ReceiveWord  OUT  Word received from serial communication       */
/* Pre-condition: The receive data register for the channel must be full      */
/* Constraints: none                                                          */
/******************************************************************************/
#ifdef __REL_RL78__
#if defined(__REL_RL78_D1A__) || defined(__REL_RL78_F12__)
#define SPID_ReceiveWord(Channel) \
        TARG_ReadShort(SPID_WORD_RX ## Channel)
#endif /* defined(__REL_RL78_D1A__) || (__REL_RL78_F12__) */
#endif /* __REL_RL78__ */

/******************************************************************************/
/* Name: SPID_TransmitByte                                                    */
/* Role: Provide the mean to start transmit of a byte on selected channel     */
/* Interface: Channel          IN  Communication channel number               */
/*             ByteToTransmit  IN  Byte to transmit on serial communication   */
/* Pre-condition: The transmit data register for the channel must be empty    */
/* Constraints: none                                                          */
/******************************************************************************/
#ifdef __MC9S12xx__
#define SPID_TransmitByte(Channel, DataByte) \
        TARG_ReadByte(SPISR); \
        TARG_ReadByte(SPIDR); \
        TARG_WriteByte(SPIDR, DataByte)
#endif /* __MC9S12xx__ */

#ifdef __MC9S08xx__
#define SPID_TransmitByte(Channel, DataByte) \
        TARG_ReadBit(SPI1S, SPI_BIT_SPRF); \
        TARG_ReadByte(SPI1D); \
        TARG_WriteByte(SPI1D, DataByte)
#endif /* __MC9S08xx__ */

#ifdef __NEC_V850__
#define SPID_TransmitByte(Channel, DataByte) \
        TARG_WriteByte(SPID_TX ## Channel, DataByte)
#endif /* __NEC_V850__ */

#ifdef __TX49__
#define SPID_TransmitByte(Channel, DataByte) \
        Spid_TransmitByteReg(Channel, DataByte)

#define Spid_TransmitByteReg(Channel, DataByte) \
        TARG_WriteShort(SEDR_##Channel, DataByte)
#endif /* __TX49__ */

#ifdef __REL_RL78__
#if defined(__REL_RL78_D1A__) || defined(__REL_RL78_F12__)
#define SPID_TransmitByte(Channel, DataByte) \
        TARG_WriteBit(SPID_FLAG_REG ## Channel, SPID_FLAG ## Channel, 0); \
        TARG_WriteByte(SPID_TX ## Channel, DataByte)
#endif /* defined(__REL_RL78_D1A__) || (__REL_RL78_F12__) */
#endif /* __REL_RL78__ */

/******************************************************************************/
/* Name: SPID_TransmitWord                                                    */
/* Role: Provide the mean to start transmit of a Word on selected channel     */
/* Interface: Channel          IN  Communication channel number               */
/*             WordToTransmit  IN  Word to transmit on serial communication   */
/* Pre-condition: The transmit data register for the channel must be empty    */
/* Constraints: none                                                          */
/******************************************************************************/

#ifdef __REL_RL78__
#if    (defined(__REL_RL78_D1A__) || defined(__REL_RL78_F12__))
#define SPID_TransmitWord(Channel, DataWord) \
        TARG_WriteBit(SPID_WORD_FLAG_REG ## Channel, SPID_WORD_FLAG ## Channel, 0); \
        TARG_WriteShort(SPID_WORD_TX ## Channel, DataWord)
#endif /* defined(__REL_RL78_D1A__) ||defined(__REL_RL78_F12__) */
#endif /* __REL_RL78__ */

/******************************************************************************/
/* Name: SPID_OperationDone                                                   */
/* Role: Provide the mean to get the status of operation on selected channel  */
/* Interface: Channel  IN   Communication channel number                      */
/*            Status   OUT  Status according to previous request:             */
/*                          != 0  -> Operation terminated                     */
/*                          = 0   -> Operation in progress                    */
/* Pre-condition: none                                                        */
/* Constraints: none                                                          */
/******************************************************************************/
#ifdef __MC9S12xx__
#define SPID_OperationDone(Channel) \
        TARG_ReadBit(SPISR, SPI_BIT_SPIF)
#endif /* __MC9S12xx__ */

#ifdef __MC9S08xx__
#define SPID_OperationDone(Channel) \
        TARG_ReadBit(SPI1S, SPI_BIT_SPRF)
#endif /* __MC9S08xx__ */

#ifdef __NEC_V850__
#if (defined(__NEC_V850_Fx3__) || defined(__NEC_V850_Dx3__))
#define SPID_OperationDone(Channel) \
        (!TARG_ReadBit(CB ## Channel ## STR, CSI_BIT_CB ## Channel ## TSF))
#endif /* defined(__NEC_V850_Fx3__) || defined(__NEC_V850_Dx3__) */

#if defined(__REL_V850_Dx4__)
#define SPID_OperationDone(Channel) \
        (!TARG_ReadBitInLong(CSIG ## Channel ## STR0, CSI_BIT_CSIGnTSF))
#endif /* defined(__REL_V850_Dx4__) */
#endif /* __NEC_V850__ */

#ifdef __TX49__
#define SPID_OperationDone(Channel) \
        Spid_OperationDoneReg(Channel)
#define Spid_OperationDoneReg(Channel) \
        TARG_ReadBit(SESR_##Channel, SPI_BIT_SIDLE)
#endif /* __TX49__ */

#ifdef __REL_RL78__
#if defined(__REL_RL78_D1A__) || defined(__REL_RL78_F12__)
#define SPID_OperationDone(Channel) \
        TARG_ReadBit(SPID_FLAG_REG ## Channel, SPID_FLAG ## Channel)
#endif /* defined(__REL_RL78_D1A__) || (__REL_RL78_F12__) */
#endif /* __REL_RL78__ */

/******************************************************************************/
/* Name: SPID_NextOperation                                                   */
/* Role: Provide the mean to clear the TC bit and to flush Rx buffer          */
/* Interface: Channel  IN   Communication channel number                      */
/* Pre-condition: none                                                        */
/* Constraints: none                                                          */
/******************************************************************************/
#if !defined(__FSL_IMX53x__) && !defined(__FSL_IMX6x__)
#if defined(__REL_V850_Dx4__) || defined(__RH850__)
#define SPID_NextOperation(channel)  SPID_ReceiveByte(channel)
#else
#define SPID_NextOperation(channel)
#endif /* __REL_V850_Dx4__ */
#endif /* __FSL_IMX53x__,__FSL_IMX6x__ */





/******************************************************************************/
/* Name: SPID_IsReceiveNotEmpty                                               */
/* Role: Provide the mean to get the status of received buffer                */
/* Interface: Channel  IN   Communication channel number                      */
/*            Status   OUT  Status according to previous request:             */
/*                          != 0  -> Received register ready                  */
/*                          = 0   -> Received register not empty              */
/* Pre-condition: none                                                        */
/* Constraints: none                                                          */
/******************************************************************************/
#ifdef __FSL_IMX53x__
#define SPID_IsReceiveNotEmpty(Channel)                                  \
        TARG_ReadBit(CSPI_STATREG, SPI_BIT_RR)
#endif /* __FSL_IMX53x__ */

#ifdef __FSL_IMX6x__
#define SPID_IsReceiveNotEmpty(Channel)                   \
     if(Channel < 4)                                      \
        {                                                 \
          TARG_ReadBit(ECSPI1_STATREG, SPI_E_BIT_RR)      \
        }                                                 \
        else if (Channel < 8)                             \
        {                                                 \
          TARG_ReadBit(ECSPI2_STATREG, SPI_E_BIT_RR)      \
        }                                                 \
        else if (Channel < 12)                            \
        {                                                 \
          TARG_ReadBit(ECSPI3_STATREG, SPI_E_BIT_RR)      \
        }                                                 \
        else if (Channel < 16)                            \
        {                                                 \
          TARG_ReadBit(ECSPI4_STATREG, SPI_E_BIT_RR)      \
        }
        
#endif /* __FSL_IMX6x__ */


/******************************************************************************/
/* Name: SPID_SetChipSelectPolarity                                           */
/* Role: Provide the mean to select the channel which is been used to the     */
/*       next communication                                                   */
/* Interface: Channel       IN   Channel used to SPI communication            */
/* Pre-condition: None                                                        */
/* Constraints: None                                                          */
/******************************************************************************/
#ifdef __FSL_IMX53x__
#define SPID_SetChipSelectPolarity(Channel, Mode)                        \
        SPID_ActiveChipSelect(Channel);                                  \
        Spid_SetChipSelectPolarity ## Mode()

#define Spid_SetChipSelectPolarityNormal()                               \
        TARG_WriteBit(CSPI_CONREG, SPI_BIT_SSPOL, SPI_SSPOL)

#define Spid_SetChipSelectPolarityInverse()                              \
        TARG_WriteBit(CSPI_CONREG, SPI_BIT_SSPOL, SPI_SSPOL_INV)
#endif /* __FSL_IMX53x__ */

#ifdef __FSL_IMX6x__
#define SPID_SetChipSelectPolarity(Channel, Mode)                        \
        SPID_ActiveChipSelect(Channel);                                  \
        Spid_SetChipSelectPolarity ## Mode()

#define Spid_SetChipSelectPolarityNormal()                               \
     if(Channel < 4)                                                     \
        {                                                                \
          TARG_WriteBit(ECSPI1_CONFIGREG, SPI_E_SSPOL_FSBIT, SPI_SSPOL)  \
        }                                                                \
        else if (Channel < 8)                                            \
        {                                                                \
          TARG_WriteBit(ECSPI2_CONFIGREG, SPI_E_SSPOL_FSBIT, SPI_SSPOL)  \
        }                                                                \
        else if (Channel < 12)                                           \
        {                                                                \
          TARG_WriteBit(ECSPI3_CONFIGREG, SPI_E_SSPOL_FSBIT, SPI_SSPOL)  \
        }                                                                \
        else if (Channel < 16)                                           \
        {                                                                \
          TARG_WriteBit(ECSPI4_CONFIGREG, SPI_E_SSPOL_FSBIT, SPI_SSPOL)  \
        }

#define Spid_SetChipSelectPolarityInverse()                              \
     if(Channel < 4)                                                     \
        {                                                                \
          TARG_WriteBit(ECSPI1_CONFIGREG, SPI_E_SSPOL_FSBIT, SPI_SSPOL_INV)  \
        }                                                                \
        else if (Channel < 8)                                            \
        {                                                                \
          TARG_WriteBit(ECSPI2_CONFIGREG, SPI_E_SSPOL_FSBIT, SPI_SSPOL_INV)  \
        }                                                                \
        else if (Channel < 12)                                           \
        {                                                                \
          TARG_WriteBit(ECSPI3_CONFIGREG, SPI_E_SSPOL_FSBIT, SPI_SSPOL_INV)  \
        }                                                                \
        else if (Channel < 16)                                           \
        {                                                                \
          TARG_WriteBit(ECSPI4_CONFIGREG, SPI_E_SSPOL_FSBIT, SPI_SSPOL_INV)  \
        }
        
#endif /* __FSL_IMX6x__*/


/******************************************************************************/
/* Name: SPID_ActiveChipSelect                                                */
/* Role: Provide the mean to select the channel which is been used to the     */
/*       next communication                                                   */
/* Interface: Channel       IN   Channel used to SPI communication            */
/* Pre-condition: None                                                        */
/* Constraints: None                                                          */
/******************************************************************************/
#if defined(__FSL_IMX53x__) || defined(__FSL_IMX6x__)
#define SPID_ActiveChipSelect(Channel)
#define SPID_InactiveChipSelect(Channel)
#endif /* __FSL_IMX53x__ , __FSL_IMX6x__*/


/******************************************************************************/
/* Name: SPID_SelectOutDirection                                              */
/* Role: Provide the mean to select line Out direction on selected channel    */
/*       for Bidirectional mode                                               */
/* Interface: Channel       IN   Communication channel number                 */
/* Pre-condition: none                                                        */
/* Constraints: To be used for Bidirectional mode only                        */
/******************************************************************************/
#ifdef __MC9S12xx__
#ifdef SPID_BIDIR_MODE_USED
#define SPID_SelectOutDirection(Channel) \
        TARG_WriteBit(SPICR2, SPI_BIT_BIDIROE, 1)
#else
#define SPID_SelectOutDirection(Channel)
#endif
#endif /* __MC9S12xx__ */

#ifdef __MC9S08xx__
#ifdef SPID_BIDIR_MODE_USED
#define SPID_SelectOutDirection(Channel) \
        TARG_WriteBit(SPI1C2, SPI_BIT_BIDIROE, 1)
#else
#define SPID_SelectOutDirection(Channel)
#endif
#endif /* __MC9S08xx__ */

#ifdef __NEC_V850__
#define SPID_SelectOutDirection(Channel)
#endif /* __NEC_V850__ */

#ifdef __TX49__
#define SPID_SelectOutDirection(Channel)
#endif /* __TX49__ */

#if defined(__FSL_IMX53x__) || defined(__FSL_IMX6x__)
#define SPID_SelectOutDirection(Channel)
#endif /* __FSL_IMX53x__ ,__FSL_IMX6x__ */

#ifdef __REL_RL78__
#if defined(__REL_RL78_D1A__) || defined(__REL_RL78_F12__)
#define SPID_SelectOutDirection(Channel)
#endif /* defined(__REL_RL78_D1A__) || defined(__REL_RL78_F12__) */
#endif /* __REL_RL78__ */

/******************************************************************************/
/* Name: SPID_SelectInDirection                                               */
/* Role: Provide the mean to select line In direction on selected channel     */
/*       for Bidirectional mode                                               */
/* Interface: Channel       IN   Communication channel number                 */
/* Pre-condition: none                                                        */
/* Constraints: To be used for Bidirectional mode only                        */
/******************************************************************************/
#ifdef __MC9S12xx__
#ifdef SPID_BIDIR_MODE_USED
#define SPID_SelectInDirection(Channel) \
        TARG_WriteBit(SPICR2, SPI_BIT_BIDIROE, 0)
#else
#define SPID_SelectInDirection(Channel)
#endif
#endif /* __MC9S12xx__ */

#ifdef __MC9S08xx__
#ifdef SPID_BIDIR_MODE_USED
#define SPID_SelectInDirection(Channel) \
        TARG_WriteBit(SPI1C2, SPI_BIT_BIDIROE, 0)
#else
#define SPID_SelectInDirection(Channel)
#endif
#endif /* __MC9S08xx__ */

#ifdef __NEC_V850__
#define SPID_SelectInDirection(Channel)
#endif /* __NEC_V850__ */

#ifdef __TX49__
#define SPID_SelectInDirection(Channel)
#endif /* __TX49__ */

#if defined(__FSL_IMX53x__) || defined(__FSL_IMX6x__)
#define SPID_SelectInDirection(Channel)
#endif /* __FSL_IMX53x__ ,__FSL_IMX6x__ */

#ifdef __REL_RL78__
#if defined(__REL_RL78_D1A__) || defined(__REL_RL78_F12__)
#define SPID_SelectInDirection(Channel)
#endif /* defined(__REL_RL78_D1A__) || defined(__REL_RL78_F12__) */
#endif /* __REL_RL78__ */


/******************************************************************************/
/* Name: SPID_EnableSerialInput                                               */
/* Role: Provide the mean to enable serial input of selected channel          */
/*       -> The pin port is associated to SPI                                 */
/* Interface: Channel        IN   Communication channel number                */
/* Pre-condition: none                                                        */
/* Constraints: Only for V850 Dx3                                             */
/******************************************************************************/
#ifdef __MC9S12xx__
#define SPID_EnableSerialInput(Channel)
#endif /* __MC9S12xx__ */

#ifdef __MC9S08AWxx__
#define SPID_EnableSerialInput(Channel)
#endif /* __MC9S08AWxx__ */

#ifdef __NEC_V850__
#define SPID_EnableSerialInput(Channel) \
        Spid_EnableSerialInput##Channel()

#ifdef SPID_CHANNEL_0_ACTIVE
extern void Spid_EnableSerialInput0(void);
#endif /* SPID_CHANNEL_0_ACTIVE */
#ifdef SPID_CHANNEL_1_ACTIVE
extern void Spid_EnableSerialInput1(void);
#endif /* SPID_CHANNEL_1_ACTIVE */
#ifdef SPID_CHANNEL_2_ACTIVE
extern void Spid_EnableSerialInput2(void);
#endif /* SPID_CHANNEL_2_ACTIVE */
#endif /* __NEC_V850__ */

#ifdef __TX49__
#define SPID_EnableSerialInput(Channel)
#endif /* __TX49__ */

#if defined(__FSL_IMX53x__) || defined(__FSL_IMX6x__)
#define SPID_EnableSerialInput(Channel)
#endif /* __FSL_IMX53x__ , __FSL_IMX6x__*/

#ifdef __REL_RL78__
#if defined(__REL_RL78_D1A__) || defined(__REL_RL78_F12)
#define SPID_EnableSerialInput(Channel)
#endif /* defined(__REL_RL78_D1A__) || defined(__REL_RL78_F12) */
#endif /* __REL_RL78__ */

/******************************************************************************/
/* Name: SPID_DisableSerialInput                                              */
/* Role: Provide the mean to disable serial input of selected channel         */
/*       -> The pin port is used as I/O                                       */
/* Interface: Channel        IN   Communication channel number                */
/* Pre-condition: none                                                        */
/* Constraints: Only for V850 Dx3                                             */
/******************************************************************************/
#ifdef __MC9S12xx__
#define SPID_DisableSerialInput(Channel)
#endif /* __MC9S12xx__ */

#ifdef __MC9S08AWxx__
#define SPID_DisableSerialInput(Channel)
#endif /* __MC9S08AWxx__ */

#ifdef __NEC_V850__
#define SPID_DisableSerialInput(Channel) \
        Spid_DisableSerialInput##Channel()

#ifdef SPID_CHANNEL_0_ACTIVE
extern void Spid_DisableSerialInput0(void);
#endif /* SPID_CHANNEL_0_ACTIVE */
#ifdef SPID_CHANNEL_1_ACTIVE
extern void Spid_DisableSerialInput1(void);
#endif /* SPID_CHANNEL_1_ACTIVE */
#ifdef SPID_CHANNEL_2_ACTIVE
extern void Spid_DisableSerialInput2(void);
#endif /* SPID_CHANNEL_2_ACTIVE */
#endif /* __NEC_V850__ */

#ifdef __TX49__
#define SPID_DisableSerialInput(Channel)
#endif /* __TX49__ */

#if defined(__FSL_IMX53x__) || defined(__FSL_IMX6x__)
#define SPID_DisableSerialInput(Channel)
#endif /* __FSL_IMX53x__, __FSL_IMX6x__ */

#ifdef __REL_RL78__
#if defined(__REL_RL78_D1A__) || defined(__REL_RL78_F12)
#define SPID_DisableSerialInput(Channel)
#endif /* defined(__REL_RL78_D1A__) || defined(__REL_RL78_F12) */
#endif /* __REL_RL78__ */


/******************************************************************************/
/* Name: SPID_ReceiveInterruptEnable                                          */
/* Role: Provide the mean to enable receive interrupt of selected channel     */
/* Interface: Channel       IN   Communication channel number                 */
/* Pre-condition: none                                                        */
/* Constraints: none                                                          */
/******************************************************************************/
#ifdef __MC9S12xx__
#define SPID_ReceiveInterruptEnable(Channel) \
        TARG_WriteBit(SPICR1, SPI_BIT_SPIE, 1)
#endif /* __MC9S12xx__ */

#ifdef __MC9S08xx__
#define SPID_ReceiveInterruptEnable(Channel) \
        TARG_WriteBit(SPI1C1, SPI_BIT_SPIE, 1)
#endif /* __MC9S08xx__ */

#ifdef __NEC_V850__
#if (defined(__NEC_V850_Dx3__) || defined(__REL_V850_Fx3__))
#define SPID_ReceiveInterruptEnable(Channel) \
        TARG_WriteBit(CB ## Channel ## RIC, INT_BIT_xxMKn, 0)
#endif /* defined(__NEC_V850_Dx3__) || defined(__REL_V850_Fx3__) */

#if defined(__REL_V850_Dx4__)
#define SPID_ReceiveInterruptEnable(Channel) \
        TARG_WriteBitInShort(ICCSIG ## Channel ## IR, INT_BIT_EIMKn, 0)
#endif /* defined(__REL_V850_Dx4__) */
#endif /* __NEC_V850__ */

#ifdef __TX49__
#define SPID_ReceiveInterruptEnable(Channel) \
        Spid_ReceiveInterruptEnableReg(Channel)

#define Spid_ReceiveInterruptEnableReg(Channel) \
        Spid_ReceiveInterruptEnableChannel_ ## Channel

#define Spid_ReceiveInterruptEnableChannel_0 TARG_SetBits(IMR45, SPID_IT_PRIORITY_LEVEL_CHANNEL_0)
#define Spid_ReceiveInterruptEnableChannel_1 TARG_SetBits(IMR48, SPID_IT_PRIORITY_LEVEL_CHANNEL_1)
#endif /* __TX49__ */

#ifdef __FSL_IMX53x__
#define SPID_ReceiveInterruptEnable(Channel)        \
        TARG_WriteBit(CSPI_INTREG, SPI_BIT_RREN, 1)
#endif /* __FSL_IMX53x__ */

#ifdef __FSL_IMX6x__
#define SPID_ReceiveInterruptEnable(Channel)           \
     if(Channel < 4)                                   \
        {                                              \
          TARG_WriteBit(ECSPI1_INTREG, SPI_E_BIT_RREN, 1)  \
        }                                              \
        else if (Channel < 8)                          \
        {                                              \
          TARG_WriteBit(ECSPI2_INTREG, SPI_E_BIT_RREN, 1)  \
        }                                              \
        else if (Channel < 12)                         \
        {                                              \
          TARG_WriteBit(ECSPI3_INTREG, SPI_E_BIT_RREN, 1)  \
        }                                              \
        else if (Channel < 16)                         \
        {                                              \
          TARG_WriteBit(ECSPI4_INTREG, SPI_E_BIT_RREN, 1)  \
        }
        
#endif /* __FSL_IMX6x__ */

#ifdef __REL_RL78__
#if defined(__REL_RL78_D1A__) || defined(__REL_RL78_F12)
#define SPID_ReceiveInterruptEnable(Channel)
#endif /* defined(__REL_RL78_D1A__) || defined(__REL_RL78_F12) */
#endif /* __REL_RL78__ */


/******************************************************************************/
/* Name: SPID_ReceiveInterruptDisable                                         */
/* Role: Provide the mean to disable receive interrupt of selected channel    */
/* Interface: Channel       IN   Communication channel number                 */
/* Pre-condition: none                                                        */
/* Constraints: none                                                          */
/******************************************************************************/
#ifdef __MC9S12xx__
#define SPID_ReceiveInterruptDisable(Channel) \
        TARG_WriteBit(SPICR1, SPI_BIT_SPIE, 0)
#endif /* __MC9S12xx__ */

#ifdef __MC9S08xx__
#define SPID_ReceiveInterruptDisable(Channel) \
        TARG_WriteBit(SPI1C1, SPI_BIT_SPIE, 0)
#endif /* __MC9S08xx__ */

#ifdef __NEC_V850__
#if (defined(__NEC_V850_Dx3__) || defined(__REL_V850_Fx3__))
#define SPID_ReceiveInterruptDisable(Channel) \
        TARG_WriteBit(CB ## Channel ## RIC, INT_BIT_xxMKn, 1)
#endif /* defined(__NEC_V850_Dx3__) || defined(__REL_V850_Fx3__) */

#if defined(__REL_V850_Dx4__)
#define SPID_ReceiveInterruptDisable(Channel) \
        TARG_WriteBitInShort(ICCSIG ## Channel ## IR, INT_BIT_EIMKn, 1)
#endif /* defined(__REL_V850_Dx4__) */
#endif /* __NEC_V850__ */

#ifdef __TX49__
#define SPID_ReceiveInterruptDisable(Channel) \
        Spid_ReceiveInterruptDisableReg(Channel)

#define Spid_ReceiveInterruptDisableReg(Channel) \
        Spid_ReceiveInterruptDisableChannel_ ## Channel

#define Spid_ReceiveInterruptDisableChannel_0 TARG_ClearBits(IMR45, INT_MSK_EXT_PRIORITY)
#define Spid_ReceiveInterruptDisableChannel_1 TARG_ClearBits(IMR48, INT_MSK_EXT_PRIORITY)
#endif /* __TX49__ */

#if defined(__FSL_IMX53x__)
#define SPID_ReceiveInterruptDisable(Channel)        \
        TARG_WriteBit(CSPI_INTREG, SPI_BIT_RREN, 0)
#endif /* __FSL_IMX53x__ */

#ifdef __FSL_IMX6x__
#define SPID_ReceiveInterruptDisable(Channel)           \
     if(Channel < 4)                                   \
        {                                              \
          TARG_WriteBit(ECSPI1_INTREG, SPI_E_BIT_RREN, 0)  \
        }                                              \
        else if (Channel < 8)                          \
        {                                              \
          TARG_WriteBit(ECSPI2_INTREG, SPI_E_BIT_RREN, 0)  \
        }                                              \
        else if (Channel < 12)                         \
        {                                              \
          TARG_WriteBit(ECSPI3_INTREG, SPI_E_BIT_RREN, 0)  \
        }                                              \
        else if (Channel < 16)                         \
        {                                              \
          TARG_WriteBit(ECSPI4_INTREG, SPI_E_BIT_RREN, 0)  \
        }
#endif /* __FSL_IMX6x__ */
        
#ifdef __REL_RL78__
#if defined(__REL_RL78_D1A__) || defined(__REL_RL78_F12)
#define SPID_ReceiveInterruptDisable(Channel)
#endif /* defined(__REL_RL78_D1A__) || defined(__REL_RL78_F12) */
#endif /* __REL_RL78__ */


/*_____ G L O B A L - F U N C T I O N S ______________________________________*/

#if defined(__FSL_IMX53x__) || defined(__FSL_IMX6x__)

/******************************************************************************/
/* Name: SPID_ReceiveByte                                                     */
/* Role: Provide the mean to read received byte on selected channel           */
/* Interface: Channel       IN   Communication channel number                 */
/*            ReceivedByte  OUT  Byte received from serial communication      */
/* Pre-condition: The receive data register for the channel must be full      */
/* Constraints: none                                                          */
/******************************************************************************/
extern ubyte SPID_ReceiveByte(ubyte);

/******************************************************************************/
/* Name: SPID_TransmitByte                                                    */
/* Role: Provide the mean to start transmit of a byte on selected channel     */
/* Interface: Channel          IN  Communication channel number               */
/*             ByteToTransmit  IN  Byte to transmit on serial communication   */
/* Pre-condition: The transmit data register for the channel must be empty    */
/* Constraints: none                                                          */
/******************************************************************************/
extern void SPID_TransmitByte(ubyte, ubyte);

/******************************************************************************/
/* Name: SPID_NextOperation                                                   */
/* Role: Provide the mean to clear the TC bit and to flush Rx buffer          */
/* Interface: Channel  IN   Communication channel number                      */
/* Pre-condition: none                                                        */
/* Constraints: none                                                          */
/******************************************************************************/
extern void SPID_NextOperation(ubyte);

/******************************************************************************/
/* Name: SPID_OperationDone                                                   */
/* Role: Service routine to test end of transfer operation                    */
/* Interface: bool_t                                                          */
/* Pre-condition: none                                                        */
/* Constraints: none                                                          */
/******************************************************************************/
extern bool_t SPID_OperationDone(ubyte);
#endif /* __FSL_IMX53x__, __FSL_IMX6x__ */

/******************************************************************************/
/* Name: SPID_Init                                                            */
/* Role: Initialise the module                                                */
/* Interface: none                                                            */
/* Pre-condition: none                                                        */
/* Constraints: none                                                          */
/******************************************************************************/
extern void SPID_Init (void);

extern void SPID_Refresh (void);

/******************************************************************************/
/* Name: SPID_WakeUp                                                          */
/* Role: Provide the mean to wake up the hardware of activated channels       */
/* Interface: none                                                            */
/* Pre-condition: none                                                        */
/* Constraints: none                                                          */
/******************************************************************************/
extern void SPID_WakeUp (void);

/******************************************************************************/
/* Name: SPID_Sleep                                                           */
/* Role: Provide the mean to put to sleep the hardware of activated channels  */
/* Interface: none                                                            */
/* Pre-condition: none                                                        */
/* Constraints: none                                                          */
/******************************************************************************/
extern void SPID_Sleep (void);

/*----------------------------------------------------------------------------*/
/*Name: SPID_UserReceiveInterrupt_Channel_0_it                                */
/*Role: Service routine of receive/transmit interrupt generated by SPI 0      */
/*Interface: void                                                             */
/*Pre-condition: none                                                         */
/*Constraints: none                                                           */
/*----------------------------------------------------------------------------*/
#ifdef SPID_UserReceiveInterrupt_Channel_0_
extern ISR(SPID_UserReceiveInterrupt_Channel_0_it);
#endif /* SPID_UserReceiveInterrupt_Channel_0 */

/*----------------------------------------------------------------------------*/
/*Name: SPID_UserReceiveInterrupt_Channel_1_it                                */
/*Role: Service routine of receive/transmit interrupt generated by SPI 1      */
/*Interface: void                                                             */
/*Pre-condition: none                                                         */
/*Constraints: none                                                           */
/*----------------------------------------------------------------------------*/
#ifdef SPID_UserReceiveInterrupt_Channel_1
extern ISR(SPID_UserReceiveInterrupt_Channel_1_it);
#endif /* SPID_UserReceiveInterrupt_Channel_1 */


#endif /* SPID_H */


/*_____ E N D _____ (spid.h) _________________________________________________*/
