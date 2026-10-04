/******************************************************************************/
/*@F_NAME:             spic.h                                                 */
/*@F_PURPOSE:          Serial Synchronous Peripheral Interface Control public */
/*                     header                                                 */
/*@F_CREATED_BY:       Olivier DIETLIN                                        */
/*@F_CREATION_DATE:    05/04/2004                                             */
/*@F_MPROC_TYPE:       independent                                            */
/************************************** (C) Copyright 2014 Magneti Marelli ****/

#ifndef SPIC_H
#define SPIC_H

#include "syst.h"
#include "spic_config.h"

/* Use an internal SPI driver */
#if (SPIC_RX_FRAME_CH_0_PHYS  == _USED_) \
 || (SPIC_RX_FRAME_CH_1_PHYS  == _USED_) \
 || (SPIC_RX_FRAME_CH_2_PHYS  == _USED_) \
 || (SPIC_RX_FRAME_CH_3_PHYS  == _USED_) \
 || (SPIC_RX_FRAME_CH_4_PHYS  == _USED_) \
 || (SPIC_RX_FRAME_CH_5_PHYS  == _USED_) \
 || (SPIC_RX_FRAME_CH_6_PHYS  == _USED_) \
 || (SPIC_RX_FRAME_CH_7_PHYS  == _USED_) \
 || (SPIC_RX_FRAME_CH_8_PHYS  == _USED_) \
 || (SPIC_RX_FRAME_CH_9_PHYS  == _USED_) \
 || (SPIC_RX_FRAME_CH_10_PHYS == _USED_) \
 || (SPIC_RX_FRAME_CH_11_PHYS == _USED_) \
 || (SPIC_RX_FRAME_CH_12_PHYS == _USED_) \
 || (SPIC_RX_FRAME_CH_13_PHYS == _USED_) \
 || (SPIC_RX_FRAME_CH_14_PHYS == _USED_) \
 || (SPIC_RX_FRAME_CH_15_PHYS == _USED_) \
 || (SPIC_TX_FRAME_CH_0_PHYS  == _USED_) \
 || (SPIC_TX_FRAME_CH_1_PHYS  == _USED_) \
 || (SPIC_TX_FRAME_CH_2_PHYS  == _USED_) \
 || (SPIC_TX_FRAME_CH_3_PHYS  == _USED_) \
 || (SPIC_TX_FRAME_CH_4_PHYS  == _USED_) \
 || (SPIC_TX_FRAME_CH_5_PHYS  == _USED_) \
 || (SPIC_TX_FRAME_CH_6_PHYS  == _USED_) \
 || (SPIC_TX_FRAME_CH_7_PHYS  == _USED_) \
 || (SPIC_TX_FRAME_CH_8_PHYS  == _USED_) \
 || (SPIC_TX_FRAME_CH_9_PHYS  == _USED_) \
 || (SPIC_TX_FRAME_CH_10_PHYS == _USED_) \
 || (SPIC_TX_FRAME_CH_11_PHYS == _USED_) \
 || (SPIC_TX_FRAME_CH_12_PHYS == _USED_) \
 || (SPIC_TX_FRAME_CH_13_PHYS == _USED_) \
 || (SPIC_TX_FRAME_CH_14_PHYS == _USED_) \
 || (SPIC_TX_FRAME_CH_15_PHYS == _USED_) \
 || (SPIC_RX_FRAME_CH_0_PHYS_WORD  == _USED_) \
 || (SPIC_RX_FRAME_CH_1_PHYS_WORD  == _USED_) \
 || (SPIC_RX_FRAME_CH_2_PHYS_WORD  == _USED_) \
 || (SPIC_RX_FRAME_CH_3_PHYS_WORD  == _USED_) \
 || (SPIC_RX_FRAME_CH_4_PHYS_WORD  == _USED_) \
 || (SPIC_RX_FRAME_CH_5_PHYS_WORD  == _USED_) \
 || (SPIC_RX_FRAME_CH_6_PHYS_WORD  == _USED_) \
 || (SPIC_RX_FRAME_CH_7_PHYS_WORD  == _USED_) \
 || (SPIC_RX_FRAME_CH_8_PHYS_WORD  == _USED_) \
 || (SPIC_RX_FRAME_CH_9_PHYS_WORD  == _USED_) \
 || (SPIC_RX_FRAME_CH_10_PHYS_WORD == _USED_) \
 || (SPIC_RX_FRAME_CH_11_PHYS_WORD == _USED_) \
 || (SPIC_RX_FRAME_CH_12_PHYS_WORD == _USED_) \
 || (SPIC_RX_FRAME_CH_13_PHYS_WORD == _USED_) \
 || (SPIC_RX_FRAME_CH_14_PHYS_WORD == _USED_) \
 || (SPIC_RX_FRAME_CH_15_PHYS_WORD == _USED_) \
 || (SPIC_TX_FRAME_CH_0_PHYS_WORD  == _USED_) \
 || (SPIC_TX_FRAME_CH_1_PHYS_WORD  == _USED_) \
 || (SPIC_TX_FRAME_CH_2_PHYS_WORD  == _USED_) \
 || (SPIC_TX_FRAME_CH_3_PHYS_WORD  == _USED_) \
 || (SPIC_TX_FRAME_CH_4_PHYS_WORD  == _USED_) \
 || (SPIC_TX_FRAME_CH_5_PHYS_WORD  == _USED_) \
 || (SPIC_TX_FRAME_CH_6_PHYS_WORD  == _USED_) \
 || (SPIC_TX_FRAME_CH_7_PHYS_WORD  == _USED_) \
 || (SPIC_TX_FRAME_CH_8_PHYS_WORD  == _USED_) \
 || (SPIC_TX_FRAME_CH_9_PHYS_WORD  == _USED_) \
 || (SPIC_TX_FRAME_CH_10_PHYS_WORD == _USED_) \
 || (SPIC_TX_FRAME_CH_11_PHYS_WORD == _USED_) \
 || (SPIC_TX_FRAME_CH_12_PHYS_WORD == _USED_) \
 || (SPIC_TX_FRAME_CH_13_PHYS_WORD == _USED_) \
 || (SPIC_TX_FRAME_CH_14_PHYS_WORD == _USED_) \
 || (SPIC_TX_FRAME_CH_15_PHYS_WORD == _USED_) 
 
 #define Spic_PHYS_CHANNEL         _USED_
#else
  #define Spic_PHYS_CHANNEL         _NOT_USED_
#endif

/* Use a simulated SPI (with IO)  */
#if (SPIC_RX_FRAME_CH_0_VIRT  == _USED_) \
 || (SPIC_RX_FRAME_CH_1_VIRT  == _USED_) \
 || (SPIC_RX_FRAME_CH_2_VIRT  == _USED_) \
 || (SPIC_RX_FRAME_CH_3_VIRT  == _USED_) \
 || (SPIC_RX_FRAME_CH_4_VIRT  == _USED_) \
 || (SPIC_RX_FRAME_CH_5_VIRT  == _USED_) \
 || (SPIC_RX_FRAME_CH_6_VIRT  == _USED_) \
 || (SPIC_RX_FRAME_CH_7_VIRT  == _USED_) \
 || (SPIC_RX_FRAME_CH_8_VIRT  == _USED_) \
 || (SPIC_RX_FRAME_CH_9_VIRT  == _USED_) \
 || (SPIC_RX_FRAME_CH_10_VIRT == _USED_) \
 || (SPIC_RX_FRAME_CH_11_VIRT == _USED_) \
 || (SPIC_RX_FRAME_CH_12_VIRT == _USED_) \
 || (SPIC_RX_FRAME_CH_13_VIRT == _USED_) \
 || (SPIC_RX_FRAME_CH_14_VIRT == _USED_) \
 || (SPIC_RX_FRAME_CH_15_VIRT == _USED_) \
 || (SPIC_TX_FRAME_CH_0_VIRT  == _USED_) \
 || (SPIC_TX_FRAME_CH_1_VIRT  == _USED_) \
 || (SPIC_TX_FRAME_CH_2_VIRT  == _USED_) \
 || (SPIC_TX_FRAME_CH_3_VIRT  == _USED_) \
 || (SPIC_TX_FRAME_CH_4_VIRT  == _USED_) \
 || (SPIC_TX_FRAME_CH_5_VIRT  == _USED_) \
 || (SPIC_TX_FRAME_CH_6_VIRT  == _USED_) \
 || (SPIC_TX_FRAME_CH_7_VIRT  == _USED_) \
 || (SPIC_TX_FRAME_CH_8_VIRT  == _USED_) \
 || (SPIC_TX_FRAME_CH_9_VIRT  == _USED_) \
 || (SPIC_TX_FRAME_CH_10_VIRT == _USED_) \
 || (SPIC_TX_FRAME_CH_11_VIRT == _USED_) \
 || (SPIC_TX_FRAME_CH_12_VIRT == _USED_) \
 || (SPIC_TX_FRAME_CH_13_VIRT == _USED_) \
 || (SPIC_TX_FRAME_CH_14_VIRT == _USED_) \
 || (SPIC_TX_FRAME_CH_15_VIRT == _USED_) 
 
  #define Spic_VIRT_CHANNEL         _USED_
#else
  #define Spic_VIRT_CHANNEL         _NOT_USED_
#endif

/* Use Transmit only function */
#if (SPIC_TX_FRAME_CH_0_PHYS  == _USED_) \
 || (SPIC_TX_FRAME_CH_1_PHYS  == _USED_) \
 || (SPIC_TX_FRAME_CH_2_PHYS  == _USED_) \
 || (SPIC_TX_FRAME_CH_3_PHYS  == _USED_) \
 || (SPIC_TX_FRAME_CH_4_PHYS  == _USED_) \
 || (SPIC_TX_FRAME_CH_5_PHYS  == _USED_) \
 || (SPIC_TX_FRAME_CH_6_PHYS  == _USED_) \
 || (SPIC_TX_FRAME_CH_7_PHYS  == _USED_) \
 || (SPIC_TX_FRAME_CH_8_PHYS  == _USED_) \
 || (SPIC_TX_FRAME_CH_9_PHYS  == _USED_) \
 || (SPIC_TX_FRAME_CH_10_PHYS == _USED_) \
 || (SPIC_TX_FRAME_CH_11_PHYS == _USED_) \
 || (SPIC_TX_FRAME_CH_12_PHYS == _USED_) \
 || (SPIC_TX_FRAME_CH_13_PHYS == _USED_) \
 || (SPIC_TX_FRAME_CH_14_PHYS == _USED_) \
 || (SPIC_TX_FRAME_CH_15_PHYS == _USED_) \
 || (SPIC_TX_FRAME_CH_0_VIRT  == _USED_) \
 || (SPIC_TX_FRAME_CH_1_VIRT  == _USED_) \
 || (SPIC_TX_FRAME_CH_2_VIRT  == _USED_) \
 || (SPIC_TX_FRAME_CH_3_VIRT  == _USED_) \
 || (SPIC_TX_FRAME_CH_4_VIRT  == _USED_) \
 || (SPIC_TX_FRAME_CH_5_VIRT  == _USED_) \
 || (SPIC_TX_FRAME_CH_6_VIRT  == _USED_) \
 || (SPIC_TX_FRAME_CH_7_VIRT  == _USED_) \
 || (SPIC_TX_FRAME_CH_8_VIRT  == _USED_) \
 || (SPIC_TX_FRAME_CH_9_VIRT  == _USED_) \
 || (SPIC_TX_FRAME_CH_10_VIRT == _USED_) \
 || (SPIC_TX_FRAME_CH_11_VIRT == _USED_) \
 || (SPIC_TX_FRAME_CH_12_VIRT == _USED_) \
 || (SPIC_TX_FRAME_CH_13_VIRT == _USED_) \
 || (SPIC_TX_FRAME_CH_14_VIRT == _USED_) \
 || (SPIC_TX_FRAME_CH_15_VIRT == _USED_) \
 || (SPIC_TX_FRAME_CH_0_PHYS_WORD  == _USED_) \
 || (SPIC_TX_FRAME_CH_1_PHYS_WORD  == _USED_) \
 || (SPIC_TX_FRAME_CH_2_PHYS_WORD  == _USED_) \
 || (SPIC_TX_FRAME_CH_3_PHYS_WORD  == _USED_) \
 || (SPIC_TX_FRAME_CH_4_PHYS_WORD  == _USED_) \
 || (SPIC_TX_FRAME_CH_5_PHYS_WORD  == _USED_) \
 || (SPIC_TX_FRAME_CH_6_PHYS_WORD  == _USED_) \
 || (SPIC_TX_FRAME_CH_7_PHYS_WORD  == _USED_) \
 || (SPIC_TX_FRAME_CH_8_PHYS_WORD  == _USED_) \
 || (SPIC_TX_FRAME_CH_9_PHYS_WORD  == _USED_) \
 || (SPIC_TX_FRAME_CH_10_PHYS_WORD == _USED_) \
 || (SPIC_TX_FRAME_CH_11_PHYS_WORD == _USED_) \
 || (SPIC_TX_FRAME_CH_12_PHYS_WORD == _USED_) \
 || (SPIC_TX_FRAME_CH_13_PHYS_WORD == _USED_) \
 || (SPIC_TX_FRAME_CH_14_PHYS_WORD == _USED_) \
 || (SPIC_TX_FRAME_CH_15_PHYS_WORD == _USED_) 

  #define Spic_TX_FRAME             _USED_
#else
  #define Spic_TX_FRAME             _NOT_USED_
#endif

/* Use Receive only function */
#if (SPIC_RX_FRAME_CH_0_PHYS  == _USED_) \
 || (SPIC_RX_FRAME_CH_1_PHYS  == _USED_) \
 || (SPIC_RX_FRAME_CH_2_PHYS  == _USED_) \
 || (SPIC_RX_FRAME_CH_3_PHYS  == _USED_) \
 || (SPIC_RX_FRAME_CH_4_PHYS  == _USED_) \
 || (SPIC_RX_FRAME_CH_5_PHYS  == _USED_) \
 || (SPIC_RX_FRAME_CH_6_PHYS  == _USED_) \
 || (SPIC_RX_FRAME_CH_7_PHYS  == _USED_) \
 || (SPIC_RX_FRAME_CH_8_PHYS  == _USED_) \
 || (SPIC_RX_FRAME_CH_9_PHYS  == _USED_) \
 || (SPIC_RX_FRAME_CH_10_PHYS == _USED_) \
 || (SPIC_RX_FRAME_CH_11_PHYS == _USED_) \
 || (SPIC_RX_FRAME_CH_12_PHYS == _USED_) \
 || (SPIC_RX_FRAME_CH_13_PHYS == _USED_) \
 || (SPIC_RX_FRAME_CH_14_PHYS == _USED_) \
 || (SPIC_RX_FRAME_CH_15_PHYS == _USED_) \
 || (SPIC_RX_FRAME_CH_0_VIRT  == _USED_) \
 || (SPIC_RX_FRAME_CH_1_VIRT  == _USED_) \
 || (SPIC_RX_FRAME_CH_2_VIRT  == _USED_) \
 || (SPIC_RX_FRAME_CH_3_VIRT  == _USED_) \
 || (SPIC_RX_FRAME_CH_4_VIRT  == _USED_) \
 || (SPIC_RX_FRAME_CH_5_VIRT  == _USED_) \
 || (SPIC_RX_FRAME_CH_6_VIRT  == _USED_) \
 || (SPIC_RX_FRAME_CH_7_VIRT  == _USED_) \
 || (SPIC_RX_FRAME_CH_8_VIRT  == _USED_) \
 || (SPIC_RX_FRAME_CH_9_VIRT  == _USED_) \
 || (SPIC_RX_FRAME_CH_10_VIRT == _USED_) \
 || (SPIC_RX_FRAME_CH_11_VIRT == _USED_) \
 || (SPIC_RX_FRAME_CH_12_VIRT == _USED_) \
 || (SPIC_RX_FRAME_CH_13_VIRT == _USED_) \
 || (SPIC_RX_FRAME_CH_14_VIRT == _USED_) \
 || (SPIC_RX_FRAME_CH_15_VIRT == _USED_) \
 || (SPIC_RX_FRAME_CH_0_PHYS_WORD  == _USED_) \
 || (SPIC_RX_FRAME_CH_1_PHYS_WORD  == _USED_) \
 || (SPIC_RX_FRAME_CH_2_PHYS_WORD  == _USED_) \
 || (SPIC_RX_FRAME_CH_3_PHYS_WORD  == _USED_) \
 || (SPIC_RX_FRAME_CH_4_PHYS_WORD  == _USED_) \
 || (SPIC_RX_FRAME_CH_5_PHYS_WORD  == _USED_) \
 || (SPIC_RX_FRAME_CH_6_PHYS_WORD  == _USED_) \
 || (SPIC_RX_FRAME_CH_7_PHYS_WORD  == _USED_) \
 || (SPIC_RX_FRAME_CH_8_PHYS_WORD  == _USED_) \
 || (SPIC_RX_FRAME_CH_9_PHYS_WORD  == _USED_) \
 || (SPIC_RX_FRAME_CH_10_PHYS_WORD == _USED_) \
 || (SPIC_RX_FRAME_CH_11_PHYS_WORD == _USED_) \
 || (SPIC_RX_FRAME_CH_12_PHYS_WORD == _USED_) \
 || (SPIC_RX_FRAME_CH_13_PHYS_WORD == _USED_) \
 || (SPIC_RX_FRAME_CH_14_PHYS_WORD == _USED_) \
 || (SPIC_RX_FRAME_CH_15_PHYS_WORD == _USED_) 

  #define Spic_RX_FRAME             _USED_
#else
  #define Spic_RX_FRAME             _NOT_USED_
#endif

/* Use Word Rx function */
#if (SPIC_RX_FRAME_CH_0_PHYS_WORD  == _USED_) \
 || (SPIC_RX_FRAME_CH_1_PHYS_WORD  == _USED_) \
 || (SPIC_RX_FRAME_CH_2_PHYS_WORD  == _USED_) \
 || (SPIC_RX_FRAME_CH_3_PHYS_WORD  == _USED_) \
 || (SPIC_RX_FRAME_CH_4_PHYS_WORD  == _USED_) \
 || (SPIC_RX_FRAME_CH_5_PHYS_WORD  == _USED_) \
 || (SPIC_RX_FRAME_CH_6_PHYS_WORD  == _USED_) \
 || (SPIC_RX_FRAME_CH_7_PHYS_WORD  == _USED_) \
 || (SPIC_RX_FRAME_CH_8_PHYS_WORD  == _USED_) \
 || (SPIC_RX_FRAME_CH_9_PHYS_WORD  == _USED_) \
 || (SPIC_RX_FRAME_CH_10_PHYS_WORD == _USED_) \
 || (SPIC_RX_FRAME_CH_11_PHYS_WORD == _USED_) \
 || (SPIC_RX_FRAME_CH_12_PHYS_WORD == _USED_) \
 || (SPIC_RX_FRAME_CH_13_PHYS_WORD == _USED_) \
 || (SPIC_RX_FRAME_CH_14_PHYS_WORD == _USED_) \
 || (SPIC_RX_FRAME_CH_15_PHYS_WORD == _USED_) 
 
 #define Spic_WORD_RX_FRAME         _USED_
#else
 #define Spic_WORD_RX_FRAME         _NOT_USED_
#endif

/* Use Word Tx function */
#if (SPIC_TX_FRAME_CH_0_PHYS_WORD  == _USED_) \
 || (SPIC_TX_FRAME_CH_1_PHYS_WORD  == _USED_) \
 || (SPIC_TX_FRAME_CH_2_PHYS_WORD  == _USED_) \
 || (SPIC_TX_FRAME_CH_3_PHYS_WORD  == _USED_) \
 || (SPIC_TX_FRAME_CH_4_PHYS_WORD  == _USED_) \
 || (SPIC_TX_FRAME_CH_5_PHYS_WORD  == _USED_) \
 || (SPIC_TX_FRAME_CH_6_PHYS_WORD  == _USED_) \
 || (SPIC_TX_FRAME_CH_7_PHYS_WORD  == _USED_) \
 || (SPIC_TX_FRAME_CH_8_PHYS_WORD  == _USED_) \
 || (SPIC_TX_FRAME_CH_9_PHYS_WORD  == _USED_) \
 || (SPIC_TX_FRAME_CH_10_PHYS_WORD == _USED_) \
 || (SPIC_TX_FRAME_CH_11_PHYS_WORD == _USED_) \
 || (SPIC_TX_FRAME_CH_12_PHYS_WORD == _USED_) \
 || (SPIC_TX_FRAME_CH_13_PHYS_WORD == _USED_) \
 || (SPIC_TX_FRAME_CH_14_PHYS_WORD == _USED_) \
 || (SPIC_TX_FRAME_CH_15_PHYS_WORD == _USED_) 
 
 #define Spic_WORD_TX_FRAME         _USED_
#else
 #define Spic_WORD_TX_FRAME         _NOT_USED_
#endif


/*_____ I N C L U D E - F I L E S ____________________________________________*/

#if (Spic_PHYS_CHANNEL == _USED_)
#include "spid.h"
#endif


/*_____ G L O B A L - D E F I N E ____________________________________________*/


/*_____ G L O B A L - T Y P E S ______________________________________________*/


/*_____ G L O B A L - M A C R O S ____________________________________________*/

/******************************************************************************/
/* Name: SPIC_BootInit                                                        */
/* Role: Init communication for boot only                                     */
/* Interface: none                                                            */
/* Pre-condition: none                                                        */
/* Constraints: none                                                          */
/******************************************************************************/
#if (Spic_PHYS_CHANNEL == _USED_)
#define SPIC_BootInit() \
        SPID_Init();    \
        SPID_WakeUp()
#else
#define SPIC_BootInit()
#endif


/******************************************************************************/
/* Name: SPIC_Init                                                            */
/* Role: Initialize the module                                                */
/* Interface: none                                                            */
/* Pre-condition: none                                                        */
/* Constraints: none                                                          */
/******************************************************************************/
#define SPIC_Init()


/******************************************************************************/
/* Name: SPIC_TransmitOneByte                                                 */
/* Role: Transmit one byte on a serial line                                   */
/* Interface: ubyte          Channel  IN  Communication channel number        */
/*            ubyte          Data     IN  Data label or value to transmit     */
/* Pre-condition: none                                                        */
/* Constraints: Not reentrant function for same channel                       */
/*              Protection must be taken if used at interrupt level (disable  */
/*              interrupt before call at task level)                          */
/******************************************************************************/
#define SPIC_TransmitOneByte(Channel, Data)              \
        Spic_SelectTransmitByte(Spic_TYPE_ ## Channel, Spic_CH_ ## Channel, Data)

#define Spic_SelectTransmitByte(Type, Channel, Data)     \
        Spic_TransmitByteType(Type, Channel, Data)

#define Spic_TransmitByteType(Type, Channel, Data)       \
        Spic_TYPE_TX_BYTE_CHANNEL_ ## Type(Channel, Data)


/* Use internal SPI driver */
#if (Spic_PHYS_CHANNEL == _USED_)
#define Spic_TYPE_TX_BYTE_CHANNEL_PHYS(Channel, Data)    \
{                                                        \
  SPID_SelectOutDirection(Channel);                      \
  SPID_TransmitByte(Channel, Data);                      \
  while (!SPID_OperationDone(Channel));                  \
  SPID_NextOperation(Channel);                           \
}
#endif /* Spic_PHYS_CHANNEL == _USED_ */


/* Simulated SPI */
#if (Spic_VIRT_CHANNEL == _USED_)
extern void Spic_SimulTransmitOneByte(ubyte Channel, ubyte Data);

#define Spic_TYPE_TX_BYTE_CHANNEL_VIRT(Channel, Data)    \
        Spic_SimulTransmitOneByte(Channel, Data)
#endif /* Spic_VIRT_CHANNEL == _USED_ */


/******************************************************************************/
/* Name: SPIC_ReceiveOneByte                                                  */
/* Role: Receive one byte from a serial line                                  */
/* Interface: ubyte          Channel  IN  Communication channel number        */
/*            ubyte          *Data    IN  Pointer to data                     */
/* Pre-condition: none                                                        */
/* Constraints: Not reentrant function for same channel                       */
/*              Protection must be taken if used at interrupt level (disable  */
/*              inetrrupt before call at task level)                          */
/******************************************************************************/
#define SPIC_ReceiveOneByte(Channel, PtrData)            \
        Spic_SelectReceiveByte(Spic_TYPE_ ## Channel, Spic_CH_ ## Channel, PtrData)

#define Spic_SelectReceiveByte(Type, Channel, PtrData)   \
        Spic_ReceiveByteType(Type, Channel, PtrData)

#define Spic_ReceiveByteType(Type, Channel, PtrData)     \
        Spic_TYPE_RX_BYTE_CHANNEL_ ## Type(Channel, PtrData)


/* Use internal SPI driver */
#if (Spic_PHYS_CHANNEL == _USED_)
#define Spic_TYPE_RX_BYTE_CHANNEL_PHYS(Channel, PtrData) \
{                                                        \
  SPID_SelectInDirection(Channel);                       \
  SPID_TransmitByte(Channel, 0);                         \
  while (!SPID_OperationDone(Channel));                  \
  SPID_NextOperation(Channel);                           \
  *(PtrData) = SPID_ReceiveByte(Channel);                \
}
#endif /* Spic_PHYS_CHANNEL == _USED_ */

/* Simulated SPI */
#if (Spic_VIRT_CHANNEL == _USED_)
extern void SPIC_SimulReceiveOneByte(ubyte Channel, ubyte *Data);

#define Spic_TYPE_RX_BYTE_CHANNEL_VIRT(Channel, PtrData) \
        SPIC_SimulReceiveOneByte(Channel, PtrData)
#endif /* Spic_VIRT_CHANNEL == _USED_ */

#if (Spic_INLINE_FUNCTION == _USED_)
/******************************************************************************/
/* Name: SPIC_TRANSMIT_DATA                                                   */
/* Role: Transmit data on a serial line                                       */
/*       function which takes a lot of time (about 100 microseconds).         */
/* Interface: ubyte          Channel  IN  Communication channel number        */
/*            ubyte          *Data    IN  Pointer to data                     */
/*            ubyte          Length   IN  Length of data                      */
/* Pre-condition: none                                                        */
/* Constraints: Not reentrant function for same channel                       */
/*              Protection must be taken if used at interrupt level (disable  */
/*              inetrrupt before call at task level)                          */
/******************************************************************************/
#define SPIC_TRANSMIT_DATA(channel, dataPtr, length) \
{                                                    \
  ubyte Lgth = length;                               \
  ubyte *addr = dataPtr;                             \
  SPID_SelectOutDirection(channel);                  \
  do                                                 \
  {                                                  \
    SPID_TransmitByte(channel, *addr);               \
    addr++;                                          \
    Lgth--;                                          \
    while (!SPID_OperationDone(channel));            \
    SPID_NextOperation(channel);                     \
  } while (Lgth > 0);                                \
}


/******************************************************************************/
/* Name: SPIC_RECEIVE_DATA                                                    */
/* Role: Receive data from a serial line                                      */
/*       function which takes a lot of time (about 100 microseconds).         */
/* Interface: ubyte          Channel  IN  Communication channel number        */
/*            ubyte          *Data    IN  Pointer to received data            */
/*            ubyte          Length   IN  Length of data to receive           */
/* Pre-condition: none                                                        */
/* Constraints: Not reentrant function for same channel                       */
/*              Protection must be taken if used at interrupt level (disable  */
/*              inetrrupt before call at task level)                          */
/******************************************************************************/
#define SPIC_RECEIVE_DATA(channel, dataPtr, length) \
{                                                   \
  ubyte Lgth = length;                              \
  ubyte *addr = dataPtr;                            \
  SPID_SelectInDirection(channel);                  \
  do                                                \
  {                                                 \
    SPID_TransmitByte(channel, 0);                  \
    Lgth--;                                         \
    while (!SPID_OperationDone(channel));           \
    SPID_NextOperation(channel);                    \
    *addr = SPID_ReceiveByte(channel);              \
    addr++;                                         \
  } while (Lgth > 0);                               \
}
#endif /* Spic_INLINE_FUNCTION == _USED_ */

/******************************************************************************/
/* Name: SPIC_TransmitOneWord                                                 */
/* Role: Transmit one word on a serial line                                   */
/* Interface: ushort          Channel  IN  Communication channel number       */
/*            ushort          Data     IN  Data label or value to transmit    */
/* Pre-condition: none                                                        */
/* Constraints: Not reentrant function for same channel                       */
/*              Protection must be taken if used at interrupt level (disable  */
/*              interrupt before call at task level)                          */
/******************************************************************************/
#define SPIC_TransmitOneWord(Channel, Data)              \
        Spic_SelectTransmitWord(Spic_TYPE_ ## Channel, Spic_CH_ ## Channel, Data)

#define Spic_SelectTransmitWord(Type, Channel, Data)     \
        Spic_TransmitWordType(Type, Channel, Data)

#define Spic_TransmitWordType(Type, Channel, Data)       \
        Spic_TYPE_TX_WORD_CHANNEL_ ## Type(Channel, Data)

/* Use internal SPI driver */
#if (Spic_PHYS_CHANNEL == _USED_)
#define Spic_TYPE_TX_WORD_CHANNEL_PHYS_WORD(Channel, Data)    \
{                                                             \
  SPID_SelectOutDirection(Channel);                           \
  SPID_TransmitWord(Channel, Data);                           \
  while (!SPID_OperationDone(Channel));                       \
  SPID_NextOperation(Channel);                                \
}
#endif /* Spic_PHYS_CHANNEL == _USED_ */


/******************************************************************************/
/* Name: SPIC_ReceiveOneWord                                                  */
/* Role: Receive one word from a serial line                                  */
/* Interface: ushort          Channel  IN  Communication channel number       */
/*            ushort          *Data    IN  Pointer to data                    */
/* Pre-condition: none                                                        */
/* Constraints: Not reentrant function for same channel                       */
/*              Protection must be taken if used at interrupt level (disable  */
/*              inetrrupt before call at task level)                          */
/******************************************************************************/
#define SPIC_ReceiveOneWord(Channel, PtrData)            \
        Spic_SelectReceiveWord(Spic_TYPE_ ## Channel, Spic_CH_ ## Channel, PtrData)

#define Spic_SelectReceiveWord(Type, Channel, PtrData)   \
        Spic_ReceiveWordType(Type, Channel, PtrData)

#define Spic_ReceiveWordType(Type, Channel, PtrData)     \
        Spic_TYPE_RX_WORD_CHANNEL_ ## Type(Channel, PtrData)


/* Use internal SPI driver */
#if (Spic_PHYS_CHANNEL == _USED_)
#define Spic_TYPE_RX_WORD_CHANNEL_PHYS_WORD(Channel, PtrData) \
{                                                             \
  SPID_SelectInDirection(Channel);                            \
  SPID_TransmitWord(Channel, 0);                              \
  while (!SPID_OperationDone(Channel));                       \
  SPID_NextOperation(Channel);                                \
  *(PtrData) = SPID_ReceiveWord(Channel);                     \
}
#endif /* Spic_PHYS_CHANNEL == _USED_ */


/******************************************************************************/
/* Name: SPIC_EnableSerialInput                                               */
/* Role: Provide the mean to enable serial input of selected channel          */
/*       -> The pin port is associated to SPI                                 */
/* Interface: Channel        IN   Communication channel number                */
/* Pre-condition: none                                                        */
/* Constraints: none                                                          */
/******************************************************************************/
#define SPIC_EnableSerialInput(Channel)  \
        Spic_EnableSerialInput(Spic_CH_ ## Channel)

#define Spic_EnableSerialInput(Channel)  \
        SPID_EnableSerialInput(Channel)


/******************************************************************************/
/* Name: SPIC_DisableSerialInput                                              */
/* Role: Provide the mean to disable serial input of selected channel         */
/*       -> The pin port is used as I/O                                       */
/* Interface: Channel        IN   Communication channel number                */
/* Pre-condition: none                                                        */
/* Constraints: none                                                          */
/******************************************************************************/
#define SPIC_DisableSerialInput(Channel)  \
        Spic_DisableSerialInput(Spic_CH_ ## Channel)

#define Spic_DisableSerialInput(Channel)  \
        SPID_DisableSerialInput(Channel)


/******************************************************************************/
/* Name: SPIC_Transmit                                                        */
/* Role: Transmit data on a serial line                                       */
/* Interface: ubyte          Channel  IN  Communication channel number        */
/*            ubyte          *Data    IN  Pointer to data                     */
/*            ubyte          Length   IN  Length of data                      */
/* Pre-condition: none                                                        */
/* Constraints: Not reentrant function for same channel                       */
/*              Protection must be taken if used at interrupt level (disable  */
/*              inetrrupt before call at task level)                          */
/******************************************************************************/
#define SPIC_Transmit(Channel, DataPtr, Length)          \
        Spic_TxFrame(Spic_TYPE_ ## Channel, Spic_CH_ ## Channel, DataPtr, Length)

#define Spic_TxFrame(Type, Channel, DataPtr, Length)     \
        Spic_TxFrameType(Type, Channel, DataPtr, Length)

#define Spic_TxFrameType(Type, Channel, DataPtr, Length) \
        Spic_TxFrame_ ## Type(Channel, DataPtr, Length)


/* Use internal SPI driver */
#if (Spic_PHYS_CHANNEL == _USED_)
#if (Spic_INLINE_FUNCTION == _USED_)
  #define Spic_TxFrame_PHYS(Channel, DataPtr, Length)    \
          SPIC_TRANSMIT_DATA(Channel, DataPtr,Length)
#else
#ifdef  __CY_TV2__
extern void Spic_TransmitFrame(ubyte Channel, ubyte *TxBuff, ubyte *RxBuff,ubyte Length);
#else
  extern void Spic_TransmitFrame(ubyte Channel, ubyte *Data, ubyte Length);
#endif/*__CY_TV2__*/
  extern void Spic_TransmitWordFrame(ubyte Channel, ushort *Data, ubyte Length);
  #define Spic_TxFrame_PHYS(Channel, DataPtr, Length)    \
          Spic_TransmitFrame(Channel, DataPtr, (ubyte)Length)

  #define Spic_TxFrame_PHYS_WORD(Channel, DataPtr, Length)    \
          Spic_TransmitWordFrame(Channel, DataPtr, (ubyte)Length)
#endif /* Spic_INLINE_FUNCTION == _USED_ */
#endif /* Spic_PHYS_CHANNEL == _USED_ */

/* Simulated SPI */
#if (Spic_VIRT_CHANNEL == _USED_)
extern void Spic_SimulTransmitFrame(ubyte Channel, ubyte *TxData, ubyte Length);

#define Spic_TxFrame_VIRT(Channel, DataPtr, Length)      \
        Spic_SimulTransmitFrame(Channel, DataPtr, (ubyte)Length)
#endif /* Spic_VIRT_CHANNEL == _USED_) */


/******************************************************************************/
/* Name: SPIC_Receive                                                         */
/* Role: Receive data from a serial line                                      */
/* Interface: ubyte          Channel  IN  Communication channel number        */
/*            ubyte          *Data    IN  Pointer to received data            */
/*            ubyte          Length   IN  Length of data to receive           */
/* Pre-condition: none                                                        */
/* Constraints: Not reentrant function for same channel                       */
/*              Protection must be taken if used at interrupt level (disable  */
/*              inetrrupt before call at task level)                          */
/******************************************************************************/
#define SPIC_Receive(Channel, DataPtr, Length)           \
        Spic_RxFrame(Spic_TYPE_ ## Channel, Spic_CH_ ## Channel, DataPtr, Length)

#define Spic_RxFrame(Type, Channel, DataPtr, Length)     \
        Spic_RxFrameType(Type, Channel, DataPtr, Length)

#define Spic_RxFrameType(Type, Channel, DataPtr, Length) \
        Spic_RxFrame_ ## Type(Channel, DataPtr, Length)


/* Use internal SPI driver */
#if (Spic_PHYS_CHANNEL == _USED_)
#if (Spic_INLINE_FUNCTION == _USED_)
  #define Spic_RxFrame_PHYS(Channel, DataPtr, Length)    \
          SPIC_RECEIVE_DATA(Channel, DataPtr, Length)
#else
#ifdef  __CY_TV2__
extern void Spic_ReceiveFrame (ubyte Channel, ubyte *TxBuff, ubyte *RxBuff,ubyte Length);
#else
  extern void Spic_ReceiveFrame (ubyte Channel, ubyte *Data, ubyte Length);
#endif/*__CY_TV2__*/
  extern void Spic_ReceiveWordFrame (ubyte Channel, ushort *Data, ubyte Length);
  #define Spic_RxFrame_PHYS(Channel, DataPtr, Length)    \
          Spic_ReceiveFrame(Channel, DataPtr, (ubyte)Length)

  #define Spic_RxFrame_PHYS_WORD(Channel, DataPtr, Length)    \
          Spic_ReceiveWordFrame(Channel, DataPtr, (ubyte)Length)
#endif /* Spic_INLINE_FUNCTION == _USED_ */
#endif /* Spic_PHYS_CHANNEL == _USED_ */

/* Simulated SPI */
#if (Spic_VIRT_CHANNEL == _USED_)
extern void Spic_SimulReceiveFrame(ubyte Channel, ubyte *RxData , ubyte Length);

#define Spic_RxFrame_VIRT(Channel, DataPtr, Length)      \
        Spic_SimulReceiveFrame(Channel, DataPtr, (ubyte)Length)
#endif /* Spic_VIRT_CHANNEL == _USED_) */


/******************************************************************************/
/* Name: SPIC_TransmitAndReceiveFrame                                         */
/* Role: Transmit and receive data from a serial line                         */
/* Interface: ubyte          Channel  IN   Communication channel number       */
/*            ubyte          *TxData  IN   Pointer to transmitted data        */
/*            ubyte          Length   IN   Length of data to receive          */
/*            ubyte          *RxData  OUT  Pointer to received data           */
/* Pre-condition: none                                                        */
/* Constraints: Verify only one user during execution                         */
/******************************************************************************/
#define SPIC_TransmitAndReceiveFrame(Channel, TxData, RxData, Length) \
        Spic_TxRxFrame(Spic_TYPE_ ## Channel, Spic_CH_ ## Channel, TxData, RxData, Length)

#define Spic_TxRxFrame(Type, Channel, TxData, RxData, Length)         \
        Spic_TxRxFrameType(Type, Channel, TxData, RxData, Length)

#define Spic_TxRxFrameType(Type, Channel, TxData, RxData, Length)     \
        Spic_TxRxFrame_ ## Type (Channel, TxData, RxData, Length)


/* Use internal SPI driver */
#if (Spic_PHYS_CHANNEL == _USED_)
#if (Spic_INLINE_FUNCTION == _USED_)
  /* Not yet implemented */
  #define Spic_TxRxFrame_PHYS(Channel, TxData, RxData, Length)
#else
  extern void Spic_TransmitAndReceiveFrame(ubyte Channel, ubyte *TxData, ubyte *RxData , ubyte Length);

  #define Spic_TxRxFrame_PHYS(Channel, TxData, RxData, Length)        \
          Spic_TransmitAndReceiveFrame(Channel, TxData, RxData, (ubyte)Length)

  #define Spic_TxRxFrame_PHYS_WORD(Channel, TxData, RxData, Length)        \
          Spic_TransmitAndReceiveWordFrame(Channel, TxData, RxData, (ubyte)Length)
#endif /* Spic_INLINE_FUNCTION == _USED_ */
#endif /* Spic_PHYS_CHANNEL == _USED_ */

/* Simulated SPI */
#if (Spic_VIRT_CHANNEL == _USED_)
/* Not yet implemented */
#define Spic_TxRxFrame_VIRT(Channel, TxData, RxData, Length)
#endif /* Spic_VIRT_CHANNEL == _USED_) */


#endif /* SPIC_H */

/*_____ E N D _____ (spic.h) _________________________________________________*/
