/******************************************************************************/
/*@F_NAME:             spid_rh850.h                                           */
/*@F_PURPOSE:          Serial Synchronous Peripheral Interface Driver public  */
/*                     header                                                 */
/*@F_CREATED_BY:       shubin liang                                           */
/*@F_CREATION_DATE:    2017 03 18                                             */
/*@F_MPROC_TYPE:       rh850 f1x                                              */
/************************************** (C) Copyright 2017 Magneti Marelli ****/

#ifndef SPID_RH850_H
#define SPID_RH850_H


/*_____ I N C L U D E - F I L E S ____________________________________________*/

#include "syst.h"
#include "spid_config.h"
#include "type.h"
#include "targ.h"

/*______G L O B A L - D E F I N E S __________________________________________*/


#ifdef __RH850__

#ifdef __RH850_F1x__

#define SPID_CSIG0_TX0 CSIG0TX0H
#define SPID_CSIG1_TX0 CSIG0TX0H

#define SPID_CSIH0_TX0 CSIH0TX0H
#define SPID_CSIH1_TX0 CSIH1TX0H
#define SPID_CSIH2_TX0 CSIH2TX0H
#define SPID_CSIH3_TX0 CSIH3TX0H

#define SPID_CSIG0_RX0 CSIG0RX0
#define SPID_CSIG1_RX0 CSIG1RX0

#define SPID_CSIH0_RX0 CSIH0RX0W
#define SPID_CSIH1_RX0 CSIH1RX0W
#define SPID_CSIH2_RX0 CSIH2RX0W
#define SPID_CSIH3_RX0 CSIH3RX0W

#define SPID_CSIH0_RX0H CSIH0RX0H
#define SPID_CSIH1_RX0H CSIH1RX0H
#define SPID_CSIH2_RX0H CSIH2RX0H
#define SPID_CSIH3_RX0H CSIH3RX0H


/*_____ G L O B A L - T Y P E S ______________________________________________*/


typedef enum
{
    SPID_COMMUNICATION_TYPE_1,
    SPID_COMMUNICATION_TYPE_2,
    SPID_COMMUNICATION_TYPE_3,
    SPID_COMMUNICATION_TYPE_4
}SPID_DataPhase_enum;

typedef enum
{
  SPID_MSB_FIRST,
  SPID_LSB_FIRST
} SPID_DataDirection_enum;

typedef enum
{
  SPID_NO_DEALY_HALF_CLOCK_INTERRUPT,
  SPID_DEALY_HALF_CLOCK_INTERRUPT /*half clock dealy for all interrupt*/
} SPID_InteruptType_enum;
/* clock enum of SPID*/
typedef enum
{
  CKSCLK_ICSI_80MHz,
}SPID_CKSCLK_ICSI_enum;

typedef enum
{
#if SPID_CKSCLK_ICSI == CKSCLK_ICSI_80MHz
    CSIG_CLK_80MHz   = 0x00,
    CSIG_CLK_40MHz   = 0x01,
    CSIG_CLK_20MHz   = 0x02,
    CSIG_CLK_10MHz   = 0x03,
    CSIG_CLK_2500KHz = 0x04,
    CSIG_CLK_1250KHz = 0x05,
#endif
    CSIG_CLK_SLAVE
}SPID_CSIG_CLK_enum;

typedef enum
{
    SPID_BAUD_10MHZ  = ((ushort)10000),
    SPID_BAUD_8MHZ   = ((ushort)8000),
    SPID_BAUD_6_6MHZ   = ((ushort)6660),
    SPID_BAUD_5MHZ   = ((ushort)5000),
    SPID_BAUD_4MHZ   = ((ushort)4000),
    SPID_BAUD_3MHZ   = ((ushort)3076),
    SPID_BAUD_2_5MHZ   = ((ushort)2500),
    SPID_BAUD_2MHZ   = ((ushort)2000),
    SPID_BAUD_1MHZ   = ((ushort)1000),
    SPID_BAUD_500KHZ = ((ushort)500),
    SPID_BAUD_250KHZ = ((ushort)250),
}SPID_BAUDRATE_enum;

/* end of clock enum of SPID */
typedef enum
{
  SPID_16_BITS_DATA_LENGHT = ((ubyte)0x00),
  SPID_1_BITS_DATA_LENGHT  = ((ubyte)0x01),
  SPID_2_BITS_DATA_LENGHT  = ((ubyte)0x02),
  SPID_3_BITS_DATA_LENGHT  = ((ubyte)0x03),
  SPID_4_BITS_DATA_LENGHT  = ((ubyte)0x04),
  SPID_5_BITS_DATA_LENGHT  = ((ubyte)0x05),
  SPID_6_BITS_DATA_LENGHT  = ((ubyte)0x06),
  SPID_7_BITS_DATA_LENGHT  = ((ubyte)0x07),
  SPID_8_BITS_DATA_LENGHT  = ((ubyte)0x08),
  SPID_9_BITS_DATA_LENGHT  = ((ubyte)0x09),
  SPID_10_BITS_DATA_LENGHT = ((ubyte)0x0a),
  SPID_11_BITS_DATA_LENGHT = ((ubyte)0x0b),
  SPID_12_BITS_DATA_LENGHT = ((ubyte)0x0c),
  SPID_13_BITS_DATA_LENGHT = ((ubyte)0x0d),
  SPID_14_BITS_DATA_LENGHT = ((ubyte)0x0e),
  SPID_15_BITS_DATA_LENGHT = ((ubyte)0x0f)
} SPID_REGISTER_DATA_LENGHT_t;

typedef enum
{
  SPID_NO_PARITY        = ((ubyte) 0x00),
  SPID_ADD_PARITY_BIT   = ((ubyte) 0x01),
  SPID_ADD_ODD_PARITY   = ((ubyte) 0x02),
  SPID_ADD_EVEN_PARITY  = ((ubyte) 0x03)
} SPID_PARITY_t;
typedef enum
{
  SPID_CSIH_CHANNEKL_0   = ((ubyte) 0x00),
  SPID_CSIH_CHANNEKL_1   = ((ubyte) 0x01),
  SPID_CSIH_CHANNEKL_2   = ((ubyte) 0x02),
  SPID_CSIH_CHANNEKL_3   = ((ubyte) 0x03)
} SPID_CSIH_Channel_t;
typedef enum
{
  SPID_CSIG_CHANNEKL_0   = ((ubyte) 0x00),
  SPID_CSIG_CHANNEKL_1   = ((ubyte) 0x01),
} SPID_CSIG_Channel_t;

typedef enum
{
  SPID_CHANNEKL_00   = ((ubyte) 0x00),
  SPID_CHANNEKL_01   = ((ubyte) 0x01),
  SPID_CHANNEKL_02   = ((ubyte) 0x02),
  SPID_CHANNEKL_03   = ((ubyte) 0x03),
  SPID_CHANNEKL_04   = ((ubyte) 0x04),
  SPID_CHANNEKL_05   = ((ubyte) 0x05)
} SPID_AllChannel_t;

typedef struct
{
    SPID_CSIG_CLK_enum CLK;
    SPID_BAUDRATE_enum BaudRate;
    SPID_REGISTER_DATA_LENGHT_t DataLenght;
    SPID_DataDirection_enum DataDiret;
    SPID_DataPhase_enum Mode;
    SPID_InteruptType_enum InteruptType;
}SPID_Ch_Config_t;
/*_____ G L O B A L - M A C R O ______________________________________________*/

/******************************************************************************/
/* Name: SPID_Enable                                                          */
/* Role: Provide the mean to enable activity of selected channel              */
/* Interface: Channel       IN   Communication channel number                 */
/* Pre-condition: none                                                        */
/* Constraints: none                                                          */
/******************************************************************************/
#define SPID_Enable(Channel) \
            TARG_WriteBit(CSI##Channel ## CTL0, CSI_BIT_CSI## Channel ## PWR, 1)


/******************************************************************************/
/* Name: SPID_Disable                                                         */
/* Role: Provide the mean to disable activity of selected channel             */
/* Interface: Channel       IN   Communication channel number                 */
/* Pre-condition: none                                                        */
/* Constraints: none                                                          */
/******************************************************************************/
#define SPID_Disable(Channel) \
            TARG_WriteBit(CSI##Channel ## CTL0, CSI_BIT_CSI## Channel ## PWR, 0)


/******************************************************************************/
/* Name: SPID_ReceiveByte                                                     */
/* Role: Provide the mean to read received byte on selected channel           */
/* Interface: Channel       IN   Communication channel number                 */
/*            ReceivedByte  OUT  Byte received from serial communication      */
/* Pre-condition: The receive data register for the channel must be full      */
/* Constraints: none                                                          */
/******************************************************************************/
ubyte SPID_ReceiveByte(ubyte Channel);

#ifdef SPID_CHANNEL_CSIG0_ACTIVE
extern ubyte Spid_ReceiveByteCSIG0(void);
#endif /*SPID_CHANNEL_CSIG0_ACTIVE*/
#ifdef SPID_CHANNEL_CSIG1_ACTIVE
extern ubyte Spid_ReceiveByteCSIG1(void);
#endif /*SPID_CHANNEL_CSIG1_ACTIVE*/

#ifdef SPID_CHANNEL_CSIH1_ACTIVE
extern ubyte Spid_ReceiveByteCSIH0(void);
#endif /*SPID_CHANNEL_CSIH1_ACTIVE*/
#ifdef SPID_CHANNEL_CSIH1_ACTIVE
extern ubyte Spid_ReceiveByteCSIH1(void);
#endif /*SPID_CHANNEL_CSIH1_ACTIVE*/
#ifdef SPID_CHANNEL_CSIH2_ACTIVE
extern ubyte Spid_ReceiveByteCSIH2(void);
#endif /*SPID_CHANNEL_CSIH2_ACTIVE*/
#ifdef SPID_CHANNEL_CSIH3_ACTIVE
extern ubyte Spid_ReceiveByteCSIH3(void);
#endif /*SPID_CHANNEL_CSIH3_ACTIVE*/



/******************************************************************************/
/* Name: SPID_TransmitByte                                                    */
/* Role: Provide the mean to start transmit of a byte on selected channel     */
/* Interface: Channel          IN  Communication channel number               */
/*             ByteToTransmit  IN  Byte to transmit on serial communication   */
/* Pre-condition: The transmit data register for the channel must be empty    */
/* Constraints: none                                                          */
/******************************************************************************/
extern void SPID_TransmitByte(ubyte Channel, ubyte DataByte);

/******************************************************************************/
/* Name: SPID_TransmitShort                                                   */
/* Role: Provide the mean to start transmit of a byte on selected channel     */
/* Interface: Channel          IN  Communication channel number               */
/*             ByteToTransmit  IN  Byte to transmit on serial communication   */
/* Pre-condition: The transmit data register for the channel must be empty    */
/* Constraints: none                                                          */
/******************************************************************************/
extern void SPID_TransmitShort(ubyte Channel, ushort DataShort);
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
extern ubyte SPID_OperationDone(ubyte Channel);


/******************************************************************************/
/* Name: SPID_SelectOutDirection                                              */
/* Role: Provide the mean to select line Out direction on selected channel    */
/*       for Bidirectional mode                                               */
/* Interface: Channel       IN   Communication channel number                 */
/* Pre-condition: none                                                        */
/* Constraints: To be used for Bidirectional mode only                        */
/******************************************************************************/
#define SPID_SelectOutDirection(Channel)


/******************************************************************************/
/* Name: SPID_SelectInDirection                                               */
/* Role: Provide the mean to select line In direction on selected channel     */
/*       for Bidirectional mode                                               */
/* Interface: Channel       IN   Communication channel number                 */
/* Pre-condition: none                                                        */
/* Constraints: To be used for Bidirectional mode only                        */
/******************************************************************************/
#define SPID_SelectInDirection(Channel)


/******************************************************************************/
/* Name: SPID_NextOperation                                                   */
/* Role: Provide the mean to clear the TC bit and to flush Rx buffer          */
/* Interface: Channel  IN   Communication channel number                      */
/* Pre-condition: none                                                        */
/* Constraints: none                                                          */
/******************************************************************************/
#define SPID_NextOperation(channel)  SPID_ReceiveByte(channel)


/******************************************************************************/
/* Name: SPID_EnableSerialInput                                               */
/* Role: Provide the mean to enable serial input of selected channel          */
/*       -> The pin port is associated to SPI                                 */
/* Interface: Channel        IN   Communication channel number                */
/* Pre-condition: none                                                        */
/* Constraints: Only for rh850                                              */
/******************************************************************************/
#define SPID_EnableSerialInput(Channel)                 \
           Spid_EnableSerialInputCSI##Channel()

#ifdef SPID_CHANNEL_CSIG0_ACTIVE
extern void Spid_EnableSerialInputCSIG0(void);
#endif /* SPID_CHANNEL_CSIG0_ACTIVE */
#ifdef SPID_CHANNEL_CSIG1_ACTIVE
extern void Spid_EnableSerialInputCSIG1(void);
#endif /* SPID_CHANNEL_CSIG1_ACTIVE */

#ifdef SPID_CHANNEL_CSIH0_ACTIVE
extern void Spid_EnableSerialInputCSIH0(void);
#endif /* SPID_CHANNEL_CSIH0_ACTIVE */
#ifdef SPID_CHANNEL_CSIH1_ACTIVE
extern void Spid_EnableSerialInputCSIH1(void);
#endif /* SPID_CHANNEL_CSIH1_ACTIVE */
#ifdef SPID_CHANNEL_CSIH2_ACTIVE
extern void Spid_EnableSerialInputCSIH2(void);
#endif /* SPID_CHANNEL_CSIH2_ACTIVE */
#ifdef SPID_CHANNEL_CSIH3_ACTIVE
extern void Spid_EnableSerialInputCSIH3(void);
#endif /* SPID_CHANNEL_CSIH3_ACTIVE */


/******************************************************************************/
/* Name: SPID_DisableSerialInput                                              */
/* Role: Provide the mean to disable serial input of selected channel         */
/*       -> The pin port is used as I/O                                       */
/* Interface: Channel        IN   Communication channel number                */
/* Pre-condition: none                                                        */
/* Constraints: Only for V850 Dx3                                             */
/******************************************************************************/
#define SPID_DisableSerialInput(Channel) \
           Spid_DisableSerialInputCSI##Channel()

#ifdef SPID_CHANNEL_CSIG0_ACTIVE
extern void Spid_DisableSerialInputCSIG0(void);
#endif /* SPID_CHANNEL_CSIG0_ACTIVE */
#ifdef SPID_CHANNEL_CSIG1_ACTIVE
extern void Spid_DisableSerialInputCSIG1(void);
#endif /* SPID_CHANNEL_CSIG1_ACTIVE */

#ifdef SPID_CHANNEL_CSIH0_ACTIVE
extern void Spid_DisableSerialInputCSIH0(void);
#endif /* SPID_CHANNEL_CSIH0_ACTIVE */
#ifdef SPID_CHANNEL_CSIH1_ACTIVE
extern void Spid_DisableSerialInputCSIH1(void);
#endif /* SPID_CSIH_CHANNEL_1_ACTIVE */
#ifdef SPID_CSIH_CHANNEL_2_ACTIVE
extern void Spid_DisableSerialInputCSIH2(void);
#endif /* SPID_CSIH_CHANNEL_2_ACTIVE */
#ifdef SPID_CHANNEL_CSIH3_ACTIVE
extern void Spid_DisableSerialInputCSIH3(void);
#endif /* SPID_CHANNEL_CSIH3_ACTIVE */


/******************************************************************************/
/* Name: SPID_ReceiveInterruptEnable                                          */
/* Role: Provide the mean to enable receive interrupt of selected channel     */
/* Interface: Channel       IN   Communication channel number                 */
/* Pre-condition: none                                                        */
/* Constraints: none                                                          */
/******************************************************************************/
#define SPID_ReceiveInterruptEnable(Channel) \
           TARG_WriteBitInShort(ICCSI## Channel ## IR, INT_BIT_EIMKn, 0);        \


/******************************************************************************/
/* Name: SPID_ReceiveInterruptDisable                                         */
/* Role: Provide the mean to disable receive interrupt of selected channel    */
/* Interface: Channel       IN   Communication channel number                 */
/* Pre-condition: none                                                        */
/* Constraints: none                                                          */
/******************************************************************************/
#define SPID_ReceiveInterruptDisable(Channel) \
           TARG_WriteBitInShort(ICCSI## Channel ## IR, INT_BIT_EIMKn, 1);        \


/*_____ G L O B A L - F U N C T I O N S ______________________________________*/

/******************************************************************************/
/* Name: SPID_InitChannel                                                     */
/* Role: Initialise the module                                                */
/* Interface: none                                                            */
/* Pre-condition: none                                                        */
/* Constraints: none                                                          */
/******************************************************************************/

extern void SPID_InitChannel(ubyte SpidChannel );

/******************************************************************************/
/* Name: SPID_Init                                                            */
/* Role: Initialise the module                                                */
/* Interface: none                                                            */
/* Pre-condition: none                                                        */
/* Constraints: none                                                          */
/******************************************************************************/
extern void SPID_Init (void);

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
/*Name: SPID_UserReceiveInterrupt_Channel_CSIG0_it                                */
/*Role: Service routine of receive/transmit interrupt generated by SPI 0      */
/*Interface: void                                                             */
/*Pre-condition: none                                                         */
/*Constraints: none                                                           */
/*----------------------------------------------------------------------------*/
#ifdef SPID_UserReceiveInterrupt_Channel_CSIG0
extern ISR(SPID_UserReceiveInterrupt_Channel_CSIG0_it);
#endif /* SPID_UserReceiveInterrupt_Channel_CSIG0 */

/*----------------------------------------------------------------------------*/
/*Name: SPID_UserReceiveInterrupt_Channel_CSIG1_it                                */
/*Role: Service routine of receive/transmit interrupt generated by SPI 1      */
/*Interface: void                                                             */
/*Pre-condition: none                                                         */
/*Constraints: none                                                           */
/*----------------------------------------------------------------------------*/
#ifdef SPID_UserReceiveInterrupt_Channel_CSIG1
extern ISR(SPID_UserReceiveInterrupt_Channel_CSIG1_it);
#endif /* SPID_UserReceiveInterrupt_Channel_CSIG1 */


/*----------------------------------------------------------------------------*/
/*Name: SPID_UserReceiveInterrupt_Channel_CSIH0_it                                */
/*Role: Service routine of receive/transmit interrupt generated by SPI 0      */
/*Interface: void                                                             */
/*Pre-condition: none                                                         */
/*Constraints: none                                                           */
/*----------------------------------------------------------------------------*/
#ifdef SPID_UserReceiveInterrupt_Channel_CSIH0
extern ISR(SPID_UserReceiveInterrupt_Channel_CSIH0_it);
#endif /* SPID_UserReceiveInterrupt_Channel_CSIH0 */

/*----------------------------------------------------------------------------*/
/*Name: SPID_UserReceiveInterrupt_Channel_CSIH1_it                                */
/*Role: Service routine of receive/transmit interrupt generated by SPI 1      */
/*Interface: void                                                             */
/*Pre-condition: none                                                         */
/*Constraints: none                                                           */
/*----------------------------------------------------------------------------*/
#ifdef SPID_UserReceiveInterrupt_Channel_CSIH1
extern ISR(SPID_UserReceiveInterrupt_Channel_CSIH1_it);
#endif /* SPID_UserReceiveInterrupt_Channel_1 */

/*----------------------------------------------------------------------------*/
/*Name: SPID_UserReceiveInterrupt_Channel_CSIH2_it                                */
/*Role: Service routine of receive/transmit interrupt generated by SPI 0      */
/*Interface: void                                                             */
/*Pre-condition: none                                                         */
/*Constraints: none                                                           */
/*----------------------------------------------------------------------------*/
#ifdef SPID_UserReceiveInterrupt_Channel_CSIH2
extern ISR(SPID_UserReceiveInterrupt_Channel_CSIH2_it);
#endif /* SPID_UserReceiveInterrupt_Channel_CSIH2 */

/*----------------------------------------------------------------------------*/
/*Name: SPID_UserReceiveInterrupt_Channel_CSIH3_it                                */
/*Role: Service routine of receive/transmit interrupt generated by SPI 1      */
/*Interface: void                                                             */
/*Pre-condition: none                                                         */
/*Constraints: none                                                           */
/*----------------------------------------------------------------------------*/
#ifdef SPID_UserReceiveInterrupt_Channel_CSIH3
extern ISR(SPID_UserReceiveInterrupt_Channel_CSIH3_it);
#endif /* SPID_UserReceiveInterrupt_Channel_CSIH3 */

#endif    /*__RH850_F1x__*/
#endif    /*__RH850__*/

void SPID_CsigInitialize( volatile SPID_CSIG_Channel_t CsigChannel,
                                   const SPID_Ch_Config_t *  const Channel);

#endif /* SPID_RH850_H */


/*_____ E N D _____ (spid_rh850.h) _________________________________________________*/
