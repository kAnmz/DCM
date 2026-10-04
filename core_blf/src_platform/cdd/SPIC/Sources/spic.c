/******************************************************************************/
/*@F_NAME:             spic.c                                                 */
/*@F_PURPOSE:          Serial Synchronous Peripheral Interface Control        */
/*@F_CREATED_BY:       Olivier DIETLIN                                        */
/*@F_CREATION_DATE:    05/04/2004                                             */
/*@F_MPROC_TYPE:       independent                                            */
/************************************** (C) Copyright 2010 Magneti Marelli ****/


/* _____ I N C L U D E - F I L E S ___________________________________________*/

#include "syst.h"
#include "spic.h"
#include "spic_config.h"

#if (Spic_PHYS_CHANNEL == _USED_)
#include "spid.h"
#endif /* Spic_PHYS_CHANNEL == _USED_ */

#if (Spic_VIRT_CHANNEL == _USED_)
#include "iodc.h"
#endif /* Spic_VIRT_CHANNEL == _USED_ */


/*______ L O C A L - D E F I N E S ___________________________________________*/


/*______ L O C A L - T Y P E S _______________________________________________*/


/*______ G L O B A L - D A T A _______________________________________________*/


/*______ P R I V A T E - D A T A _____________________________________________*/


/*______ L O C A L - D A T A _________________________________________________*/

#if (Spic_VIRT_CHANNEL == _USED_)
static ubyte Spic_BitNbData;
static ubyte Spic_DataBit;
#endif /* Spic_VIRT_CHANNEL == _USED_ */


/*______ L O C A L - M A C R O S _____________________________________________*/

#if (Spic_VIRT_CHANNEL == _USED_)

/******************************************************************************/
/* Get I/O pins name used to simulate SPI                                     */
/******************************************************************************/
#define Spic_OutPinName(Channel)   DATAOUT_SPI_ ## Channel
#define Spic_InPinName(Channel)    DATAIN_SPI_ ## Channel
#define Spic_ClockPinName(Channel) CLOCK_SPI_ ## Channel


/******************************************************************************/
/* Name: Spic_DataOut                                                         */
/******************************************************************************/
#define Spic_DataOut(Channel, State) \
        IODC_SetOutputData(Spic_OutPinName(Channel), State)


/******************************************************************************/
/* Name: Spic_DataIn                                                          */
/******************************************************************************/
#define Spic_DataIn(Channel)    \
        Spic_GetDataIn(Spic_InPinName(Channel))

/* another macro due to IODC macro definition */
#define Spic_GetDataIn(Channel) \
        IODC_GetInputDataDirect(Channel)


/******************************************************************************/
/* Name: Spic_Clock                                                           */
/******************************************************************************/
#define Spic_Clock(Channel) \
        Spic_CPOL_VIRT_CH_ ## Channel(Channel)

/* Clock polarity Active-high */
#define Spic_CPOL_HIGH(Channel)                                      \
        SYST_Wait(SYST_250nS);                                       \
        IODC_SetOutputData(Spic_ClockPinName(Channel), IODC_ACTIVE); \
        SYST_Wait(SYST_250nS);                                       \
        IODC_SetOutputData(Spic_ClockPinName(Channel), IODC_INACTIVE)

/* Clock polarity Active-low */
#define Spic_CPOL_LOW(Channel)                                         \
        IODC_SetOutputData(Spic_ClockPinName(Channel), IODC_INACTIVE); \
        SYST_Wait(SYST_250nS);                                         \
        IODC_SetOutputData(Spic_ClockPinName(Channel), IODC_ACTIVE);   \
        SYST_Wait(SYST_250nS)


/******************************************************************************/
/* Name: Spic_IdleState                                                        */
/******************************************************************************/
#define Spic_IdleState(Channel) \
        Spic_SetIdleSate(Spic_GetPolarity(Channel), Channel)

#define Spic_GetPolarity(Channel) \
        Spic_CPOL_VIRT_CH_ ## Channel

#define Spic_SetIdleSate(Polarity, Channel) \
        Spic_SelectIdleSate(Polarity, Channel)

#define Spic_SelectIdleSate(Polarity, Channel) \
        Polarity ## _IDLE(Channel)

/* idle state for Clock polarity Active-high */
#define Spic_CPOL_HIGH_IDLE(Channel)                                   \
        IODC_SetOutputData(Spic_ClockPinName(Channel), IODC_INACTIVE); \
        IODC_SetOutputData(Spic_OutPinName(Channel), IODC_ACTIVE)

/* idle state for Clock polarity Active-low */
#define Spic_CPOL_LOW_IDLE(Channel)                                  \
        IODC_SetOutputData(Spic_ClockPinName(Channel), IODC_ACTIVE); \
        IODC_SetOutputData(Spic_OutPinName(Channel), IODC_ACTIVE)


/******************************************************************************/
/* Name: Spic_IoTransmitData                                                  */
/******************************************************************************/
#define Spic_IoTransmitData(Channel, Data) \
        { \
          Spic_BitNbData = 8; \
          do \
          { \
            Spic_BitNbData--; \
            Spic_DataBit = (ubyte)((Data >> Spic_BitNbData) & 0x01); \
            \
            Spic_DataOut(Channel, Spic_DataBit); \
            Spic_Clock(Channel); \
          } while (Spic_BitNbData > 0); \
        }


/******************************************************************************/
/* Name: Spic_IoTransmitFrame                                                 */
/* Role: Simulate SPI to transmit data on a serial line                       */
/* Interface: ubyte          Channel  IN  Communication channel number        */
/*            ubyte          *Data    IN  Pointer to data                     */
/*            ubyte          Length   IN  Length of data                      */
/* Pre-condition: none                                                        */
/* Constraints: - Not reentrant function for same channel                     */
/*                Protection must be taken if used at interrupt level         */
/*                (disable interrupt before call at task level)               */
/*              - Support Master mode only                                    */
/*              - Support edge-on-half-cycle clock phase only                 */
/*              - Baud rate : processor dependent                             */
/*               (S12H = ~220KHz with clock = 16 KHz)                         */
/* Behavior:                                                                  */
/*   DO                                                                       */
/*    [ Drive data-out and clock pins to transmit data ]                      */
/*   OD                                                                       */
/******************************************************************************/
#define Spic_IoTransmitFrame(Channel, PtrData, Length) \
        { \
          Spic_IdleState(Channel); \
          do \
          { \
            Spic_IoTransmitData(Channel, (*PtrData)); \
            PtrData++; \
            Length--; \
            \
          } while (Length > 0); \
          \
          Spic_IdleState(Channel); \
        }


/******************************************************************************/
/* Name: Spic_IoTransmitOneByte                                               */
/* Role: Simulate SPI to transmit data on a serial line                       */
/* Interface: ubyte          Channel  IN  Communication channel number        */
/*            ubyte          Data     IN  data                                */
/* Pre-condition: none                                                        */
/* Constraints: - Not reentrant function for same channel                     */
/*                Protection must be taken if used at interrupt level         */
/*                (disable inetrrupt before call at task level)               */
/*              - Support Master mode only                                    */
/*              - Support edge-on-half-cycle clock phase only                 */
/*              - Baud rate : processor dependent                             */
/*               (S12H = ~220KHz with clock = 16 KHz)                         */
/* Behavior:                                                                  */
/*   DO                                                                       */
/*    [ Drive data-out and clock pins to transmit data ]                      */
/*   OD                                                                       */
/******************************************************************************/
#define Spic_IoTransmitOneByte(Channel, Data) \
        { \
          Spic_IdleState(Channel); \
          Spic_IoTransmitData(Channel, Data); \
          Spic_IdleState(Channel); \
        }

/******************************************************************************/
/* Name: Spic_IoReceiveData                                                   */
/******************************************************************************/
#define Spic_IoReceiveData(Channel, PtrData) \
        { \
          Spic_BitNbData = 8; \
          Spic_DataBit   = 0x00; \
          *PtrData    = 0x00; \
          do \
          { \
            Spic_BitNbData--; \
            Spic_Clock(Channel); \
            Spic_DataBit = Spic_DataIn(Channel); \
            *PtrData |= (ubyte)(Spic_DataBit << Spic_BitNbData); \
          } while (Spic_BitNbData > 0); \
        }

/******************************************************************************/
/* Name: Spic_IoReceiveFrame                                                  */
/* Role: Simulate SPI to receive data on a serial line                        */
/* Interface: ubyte          Channel  IN  Communication channel number        */
/*            ubyte          *Data    IN  Pointer to data                     */
/*            ubyte          Length   IN  Length of data                      */
/* Pre-condition: none                                                        */
/* Constraints: - Not reentrant function for same channel                     */
/*                Protection must be taken if used at interrupt level         */
/*                (disable interrupt before call at task level)               */
/*              - Support Master mode only                                    */
/*              - Support edge-on-half-cycle clock phase only                 */
/*              - Baud rate : processor dependent                             */
/*               (S12H = ~220KHz with clock = 16 KHz)                         */
/* Behavior:                                                                  */
/*   DO                                                                       */
/*    [ Drive data-out and clock pins to transmit data ]                      */
/*   OD                                                                       */
/******************************************************************************/
#define Spic_IoReceiveFrame(Channel, PtrData, Length) \
        { \
          Spic_IdleState(Channel); \
          do \
          { \
            Spic_IoReceiveData(Channel, PtrData); \
            PtrData++; \
            Length--; \
          } while (Length > 0); \
          \
          Spic_IdleState(Channel); \
        }

/******************************************************************************/
/* Name: Spic_IoReceiveOneByte                                                */
/* Role: Simulate SPI to receive data on a serial line                        */
/* Interface: ubyte          Channel  IN  Communication channel number        */
/*            ubyte          *Data    IN  Pointer to data                     */
/*            ubyte          Length   IN  Length of data                      */
/* Pre-condition: none                                                        */
/* Constraints: - Not reentrant function for same channel                     */
/*                Protection must be taken if used at interrupt level         */
/*                (disable interrupt before call at task level)               */
/*              - Support Master mode only                                    */
/*              - Support edge-on-half-cycle clock phase only                 */
/*              - Baud rate : processor dependent                             */
/*               (S12H = ~220KHz with clock = 16 KHz)                         */
/* Behavior:                                                                  */
/*   DO                                                                       */
/*    [ Drive data-out and clock pins to transmit data ]                      */
/*   OD                                                                       */
/******************************************************************************/
#define Spic_IoReceiveOneByte(Channel, PtrData) \
        { \
          Spic_IdleState(Channel); \
          Spic_IoReceiveData(Channel, PtrData); \
          Spic_IdleState(Channel); \
        }

#endif /* Spic_VIRT_CHANNEL == _USED_ */


/*______ L O C A L - F U N C T I O N S _______________________________________*/

#if (Spic_PHYS_CHANNEL == _USED_)
#if (Spic_INLINE_FUNCTION == _NOT_USED_)

#if (Spic_TX_FRAME == _USED_)
/******************************************************************************/
/* Name: Spic_TransmitFrame                                                   */
/* Role: Transmit datas on a serial line                                      */
/* Interface: ubyte          Channel  IN  Communication channel number        */
/*            ubyte          *Data    IN  Pointer to data                     */
/*            ubyte          Length   IN  Length of data                      */
/* Pre-condition: none                                                        */
/* Constraints: Not reentrant function for same channel                       */
/*              Protection must be taken if used at interrupt level (disable  */
/*              interrupt before call at task level)                          */
/* Behavior:                                                                  */
/*   DO                                                                       */
/*    [ Transfer data with serial peripheral driver ]                         */
/*   OD                                                                       */
/******************************************************************************/
#ifdef  __CY_TV2__
void Spic_TransmitFrame(ubyte Channel, ubyte *TxBuff, ubyte *RxBuff,ubyte Length)
#else
void Spic_TransmitFrame(ubyte Channel, ubyte *Data, ubyte Length)
#endif
{
  switch (Channel)
  {
#ifndef  __CY_TV2__
#ifdef __RH850__
#ifdef __RH850_F1x__
    #if (SPIC_TX_FRAME_CH_0_PHYS == _USED_)
    case 0:
      do
      {
        SPID_TransmitByte(0, *Data);
        Data++;
        Length--;
        while (!SPID_OperationDone(0)) __NOP__;
        (void)SPID_NextOperation(0);
      } while (Length > 0);
    break;
    #endif

    #if (SPIC_TX_FRAME_CH_1_PHYS == _USED_)
    case 1:
      do
      {
        SPID_TransmitByte(1, *Data);
        Data++;
        Length--;
        while (!SPID_OperationDone(1)) __NOP__;
        SPID_NextOperation(1);
      } while (Length > 0);
    break;
    #endif

    #if (SPIC_TX_FRAME_CH_2_PHYS == _USED_)
    case 2:
      do
      {
        SPID_TransmitByte(2, *Data);
        Data++;
        Length--;
        while (!SPID_OperationDone(2)) __NOP__;
        SPID_NextOperation(2);
      } while (Length > 0);
    break;
    #endif

    #if (SPIC_TX_FRAME_CH_3_PHYS == _USED_)
    case 3:
      do
      {
        SPID_TransmitByte(3, *Data);
        Data++;
        Length--;
        while (!SPID_OperationDone(3)) __NOP__;
        SPID_NextOperation(3);
      } while (Length > 0);
    break;
    #endif

    #if (SPIC_TX_FRAME_CH_4_PHYS == _USED_)
    case 4:
      do
      {
        SPID_TransmitByte(4, *Data);
        Data++;
        Length--;
        while (!SPID_OperationDone(4)) __NOP__;
        (void)SPID_NextOperation(4);
      } while (Length > 0);
    break;
    #endif

    #if (SPIC_TX_FRAME_CH_5_PHYS == _USED_)
    case 5:
      do
      {
        SPID_TransmitByte(5, *Data);
        Data++;
        Length--;
        while (!SPID_OperationDone(5)) __NOP__;
        (void)SPID_NextOperation(5);
      } while (Length > 0);
    break;
    #endif
    default:
      break;

#endif	/*__RH850_F1x__*/
#else

    #if (SPIC_TX_FRAME_CH_0_PHYS == _USED_)
    case 0:
      SPID_SelectOutDirection(0);
      do
      {
        SPID_TransmitByte(0, *Data);
        Data++;
        Length--;
        while (!SPID_OperationDone(0)) __NOP__;
        SPID_NextOperation(0);
      } while (Length > 0);
      break;
    #endif

    #if (SPIC_TX_FRAME_CH_1_PHYS == _USED_)
    case 1:
      SPID_SelectOutDirection(1);
      do
      {
        SPID_TransmitByte(1, *Data);
        Data++;
        Length--;
        while (!SPID_OperationDone(1)) __NOP__;
        SPID_NextOperation(1);
      } while (Length > 0);
      break;
    #endif

    #if (SPIC_TX_FRAME_CH_2_PHYS == _USED_)
    case 2:
      SPID_SelectOutDirection(2);
      do
      {
        SPID_TransmitByte(2, *Data);
        Data++;
        Length--;
        while (!SPID_OperationDone(2)) __NOP__;
        SPID_NextOperation(2);
      } while (Length > 0);
      break;
    #endif

    #if (SPIC_TX_FRAME_CH_3_PHYS == _USED_)
    case 3:
      SPID_SelectOutDirection(3);
      do
      {
        SPID_TransmitByte(3, *Data);
        Data++;
        Length--;
        while (!SPID_OperationDone(3)) __NOP__;
        SPID_NextOperation(3);
      } while (Length > 0);
      break;
    #endif

    #if (SPIC_TX_FRAME_CH_4_PHYS == _USED_)
    case 4:
      SPID_SelectOutDirection(4);
      do
      {
        SPID_TransmitByte(4, *Data);
        Data++;
        Length--;
        while (!SPID_OperationDone(4)) __NOP__;
        SPID_NextOperation(4);
      } while (Length > 0);
      break;
    #endif

    #if (SPIC_TX_FRAME_CH_5_PHYS == _USED_)
    case 5:
      SPID_SelectOutDirection(5);
      do
      {
        SPID_TransmitByte(5, *Data);
        Data++;
        Length--;
        while (!SPID_OperationDone(5)) __NOP__;
        SPID_NextOperation(5);
      } while (Length > 0);
      break;
    #endif

    #if (SPIC_TX_FRAME_CH_6_PHYS == _USED_)
    case 6:
      SPID_SelectOutDirection(6);
      do
      {
        SPID_TransmitByte(6, *Data);
        Data++;
        Length--;
        while (!SPID_OperationDone(6)) __NOP__;
        SPID_NextOperation(6);
      } while (Length > 0);
      break;
    #endif

    #if (SPIC_TX_FRAME_CH_7_PHYS == _USED_)
    case 7:
      SPID_SelectOutDirection(7);
      do
      {
        SPID_TransmitByte(7, *Data);
        Data++;
        Length--;
        while (!SPID_OperationDone(7)) __NOP__;
        SPID_NextOperation(7);
      } while (Length > 0);
      break;
    #endif

    #if (SPIC_TX_FRAME_CH_8_PHYS == _USED_)
    case 8:
      SPID_SelectOutDirection(8);
      do
      {
        SPID_TransmitByte(8, *Data);
        Data++;
        Length--;
        while (!SPID_OperationDone(8)) __NOP__;
        SPID_NextOperation(8);
      } while (Length > 0);
      break;
    #endif

    #if (SPIC_TX_FRAME_CH_9_PHYS == _USED_)
    case 9:
      SPID_SelectOutDirection(9);
      do
      {
        SPID_TransmitByte(9, *Data);
        Data++;
        Length--;
        while (!SPID_OperationDone(9)) __NOP__;
        SPID_NextOperation(9);
      } while (Length > 0);
      break;
    #endif

    #if (SPIC_TX_FRAME_CH_10_PHYS == _USED_)
    case 10:
      SPID_SelectOutDirection(10);
      do
      {
        SPID_TransmitByte(10, *Data);
        Data++;
        Length--;
        while (!SPID_OperationDone(10)) __NOP__;
        SPID_NextOperation(10);
      } while (Length > 0);
      break;
    #endif

    #if (SPIC_TX_FRAME_CH_11_PHYS == _USED_)
    case 11:
      SPID_SelectOutDirection(11);
      do
      {
        SPID_TransmitByte(11, *Data);
        Data++;
        Length--;
        while (!SPID_OperationDone(11)) __NOP__;
        SPID_NextOperation(11);
      } while (Length > 0);
      break;
    #endif
	
	  #if (SPIC_TX_FRAME_CH_12_PHYS == _USED_)
    case 12:
      SPID_SelectOutDirection(12);
      do
      {
        SPID_TransmitByte(12, *Data);
        Data++;
        Length--;
        while (!SPID_OperationDone(12)) __NOP__;
        SPID_NextOperation(12);
      } while (Length > 0);
      break;
    #endif

    #if (SPIC_TX_FRAME_CH_13_PHYS == _USED_)
    case 13:
      SPID_SelectOutDirection(13);
      do
      {
        SPID_TransmitByte(13, *Data);
        Data++;
        Length--;
        while (!SPID_OperationDone(13)) __NOP__;
        SPID_NextOperation(13);
      } while (Length > 0);
      break;
    #endif

    #if (SPIC_TX_FRAME_CH_14_PHYS == _USED_)
    case 14:
      SPID_SelectOutDirection(14);
      do
      {
        SPID_TransmitByte(14, *Data);
        Data++;
        Length--;
        while (!SPID_OperationDone(14)) __NOP__;
        SPID_NextOperation(14);
      } while (Length > 0);
      break;
    #endif

    #if (SPIC_TX_FRAME_CH_15_PHYS == _USED_)
    case 15:
      SPID_SelectOutDirection(15);
      do
      {
        SPID_TransmitByte(15, *Data);
        Data++;
        Length--;
        while (!SPID_OperationDone(15)) __NOP__;
        SPID_NextOperation(15);
      } while (Length > 0);
      break;
    #endif
	
   
    default:
      break;
#endif
#endif/*__CY_TV2__*/

#ifdef __CY_TV2__
#if (SPIC_TX_FRAME_CH_0_PHYS == SCB_SPI_FUNCTION_USED)
case 0:
    SPID_TransmitData(0,TxBuff,RxBuff,Length);
    while (SPID_TransmitComplete != SPID_OperationDone(0)) __NOP__;
break;
#endif

#if (SPIC_TX_FRAME_CH_1_PHYS == SCB_SPI_FUNCTION_USED)
case 1:
	SPID_TransmitData(1,TxBuff,RxBuff,Length);
    while (SPID_TransmitComplete != SPID_OperationDone(1)) __NOP__;
break;
#endif

#if (SPIC_TX_FRAME_CH_2_PHYS == SCB_SPI_FUNCTION_USED)
case 2:
	SPID_TransmitData(2,TxBuff,RxBuff,Length);
    while (SPID_TransmitComplete != SPID_OperationDone(2)) __NOP__;
break;
#endif

#if (SPIC_TX_FRAME_CH_3_PHYS == SCB_SPI_FUNCTION_USED)
case 3:
	SPID_TransmitData(3,TxBuff,RxBuff,Length);
    while (SPID_TransmitComplete != SPID_OperationDone(3)) __NOP__;
break;
#endif

#if (SPIC_TX_FRAME_CH_4_PHYS == SCB_SPI_FUNCTION_USED)
case 4:
	SPID_TransmitData(4,TxBuff,RxBuff,Length);
    while (SPID_TransmitComplete != SPID_OperationDone(4)) __NOP__;
break;
#endif

#if (SPIC_TX_FRAME_CH_5_PHYS == SCB_SPI_FUNCTION_USED)
case 5:
	SPID_TransmitData(5,TxBuff,RxBuff,Length);
    while (SPID_TransmitComplete != SPID_OperationDone(5)) __NOP__;
break;
#endif

#if (SPIC_TX_FRAME_CH_6_PHYS == SCB_SPI_FUNCTION_USED)
case 6:
	SPID_TransmitData(6,TxBuff,RxBuff,Length);
    while (SPID_TransmitComplete != SPID_OperationDone(6)) __NOP__;
break;
#endif

#if (SPIC_TX_FRAME_CH_7_PHYS == SCB_SPI_FUNCTION_USED)
case 7:
	SPID_TransmitData(7,TxBuff,RxBuff,Length);
    while (SPID_TransmitComplete != SPID_OperationDone(7)) __NOP__;
break;
#endif

    default:
      break;
#endif

  }
}

#if (Spic_WORD_TX_FRAME == _USED_)
/******************************************************************************/
/* Name: Spic_TransmitWordFrame                                               */
/* Role: Transmit datas on a serial line                                      */
/* Interface: ubyte          Channel  IN  Communication channel number        */
/*            ushort         *Data    IN  Pointer to data                     */
/*            ubyte          Length   IN  Length of data                      */
/* Pre-condition: none                                                        */
/* Constraints: Not reentrant function for same channel                       */
/*              Protection must be taken if used at interrupt level (disable  */
/*              interrupt before call at task level)                          */
/* Behavior:                                                                  */
/*   DO                                                                       */
/*    [ Transfer data with serial peripheral driver ]                         */
/*   OD                                                                       */
/******************************************************************************/
void Spic_TransmitWordFrame(ubyte Channel, ushort *Data, ubyte Length)
{
  switch (Channel)
  {
  #if (SPIC_TX_FRAME_CH_0_PHYS_WORD == _USED_)
    case 0:
      SPID_SelectOutDirection(0);
      do
      {
        SPID_TransmitWord(0, *Data);
        Data++;
        Length--;
        while (!SPID_OperationDone(0)) __NOP__;
        SPID_NextOperation(0);
      } while (Length > 0);
      break;
    #endif

    #if (SPIC_TX_FRAME_CH_1_PHYS_WORD == _USED_)
    case 1:
      SPID_SelectOutDirection(1);
      do
      {
        SPID_TransmitWord(1, *Data);
        Data++;
        Length--;
        while (!SPID_OperationDone(1)) __NOP__;
        SPID_NextOperation(1);
      } while (Length > 0);
      break;
    #endif

    #if (SPIC_TX_FRAME_CH_2_PHYS_WORD == _USED_)
    case 2:
      SPID_SelectOutDirection(2);
      do
      {
        SPID_TransmitWord(2, *Data);
        Data++;
        Length--;
        while (!SPID_OperationDone(2)) __NOP__;
        SPID_NextOperation(2);
      } while (Length > 0);
      break;
    #endif

    #if (SPIC_TX_FRAME_CH_3_PHYS_WORD == _USED_)
    case 3:
      SPID_SelectOutDirection(3);
      do
      {
        SPID_TransmitWord(3, *Data);
        Data++;
        Length--;
        while (!SPID_OperationDone(3)) __NOP__;
        SPID_NextOperation(3);
      } while (Length > 0);
      break;
    #endif

    #if (SPIC_TX_FRAME_CH_4_PHYS_WORD == _USED_)
    case 4:
      SPID_SelectOutDirection(4);
      do
      {
        SPID_TransmitWord(4, *Data);
        Data++;
        Length--;
        while (!SPID_OperationDone(4)) __NOP__;
        SPID_NextOperation(4);
      } while (Length > 0);
      break;
    #endif

    #if (SPIC_TX_FRAME_CH_5_PHYS_WORD == _USED_)
    case 5:
      SPID_SelectOutDirection(5);
      do
      {
        SPID_TransmitWord(5, *Data);
        Data++;
        Length--;
        while (!SPID_OperationDone(5)) __NOP__;
        SPID_NextOperation(5);
      } while (Length > 0);
      break;
    #endif

    #if (SPIC_TX_FRAME_CH_6_PHYS_WORD == _USED_)
    case 6:
      SPID_SelectOutDirection(6);
      do
      {
        SPID_TransmitWord(6, *Data);
        Data++;
        Length--;
        while (!SPID_OperationDone(6)) __NOP__;
        SPID_NextOperation(6);
      } while (Length > 0);
      break;
    #endif

    #if (SPIC_TX_FRAME_CH_7_PHYS_WORD == _USED_)
    case 7:
      SPID_SelectOutDirection(7);
      do
      {
        SPID_TransmitWord(7, *Data);
        Data++;
        Length--;
        while (!SPID_OperationDone(7)) __NOP__;
        SPID_NextOperation(7);
      } while (Length > 0);
      break;
    #endif

    #if (SPIC_TX_FRAME_CH_8_PHYS_WORD == _USED_)
    case 8:
      SPID_SelectOutDirection(8);
      do
      {
        SPID_TransmitWord(8, *Data);
        Data++;
        Length--;
        while (!SPID_OperationDone(8)) __NOP__;
        SPID_NextOperation(8);
      } while (Length > 0);
      break;
    #endif

    #if (SPIC_TX_FRAME_CH_9_PHYS_WORD == _USED_)
    case 9:
      SPID_SelectOutDirection(9);
      do
      {
        SPID_TransmitWord(9, *Data);
        Data++;
        Length--;
        while (!SPID_OperationDone(9)) __NOP__;
        SPID_NextOperation(9);
      } while (Length > 0);
      break;
    #endif

    #if (SPIC_TX_FRAME_CH_10_PHYS_WORD == _USED_)
    case 10:
      SPID_SelectOutDirection(10);
      do
      {
        SPID_TransmitWord(10, *Data);
        Data++;
        Length--;
        while (!SPID_OperationDone(10)) __NOP__;
        SPID_NextOperation(10);
      } while (Length > 0);
      break;
    #endif

    #if (SPIC_TX_FRAME_CH_11_PHYS_WORD == _USED_)
    case 11:
      SPID_SelectOutDirection(11);
      do
      {
        SPID_TransmitWord(11, *Data);
        Data++;
        Length--;
        while (!SPID_OperationDone(11)) __NOP__;
        SPID_NextOperation(11);
      } while (Length > 0);
      break;
    #endif
	
	#if (SPIC_TX_FRAME_CH_12_PHYS_WORD == _USED_)
    case 12:
      SPID_SelectOutDirection(12);
      do
      {
        SPID_TransmitWord(12, *Data);
        Data++;
        Length--;
        while (!SPID_OperationDone(12)) __NOP__;
        SPID_NextOperation(12);
      } while (Length > 0);
      break;
    #endif

    #if (SPIC_TX_FRAME_CH_13_PHYS_WORD == _USED_)
    case 13:
      SPID_SelectOutDirection(13);
      do
      {
        SPID_TransmitWord(13, *Data);
        Data++;
        Length--;
        while (!SPID_OperationDone(13)) __NOP__;
        SPID_NextOperation(13);
      } while (Length > 0);
      break;
    #endif

    #if (SPIC_TX_FRAME_CH_14_PHYS_WORD == _USED_)
    case 14:
      SPID_SelectOutDirection(14);
      do
      {
        SPID_TransmitWord(14, *Data);
        Data++;
        Length--;
        while (!SPID_OperationDone(14)) __NOP__;
        SPID_NextOperation(14);
      } while (Length > 0);
      break;
    #endif

    #if (SPIC_TX_FRAME_CH_15_PHYS_WORD == _USED_)
    case 15:
      SPID_SelectOutDirection(15);
      do
      {
        SPID_TransmitWord(15, *Data);
        Data++;
        Length--;
        while (!SPID_OperationDone(15)) __NOP__;
        SPID_NextOperation(15);
      } while (Length > 0);
      break;
    #endif

    default:
      break;
  }
}
#endif /* Spic_WORD_TX_FRAME == _USED_ */
#endif /* Spic_TX_FRAME == _USED_ */

#if (Spic_RX_FRAME == _USED_)
/******************************************************************************/
/* Name: Spic_ReceiveFrame                                                    */
/* Role: Receive data from a serial line                                      */
/* Interface: ubyte          Channel  IN  Communication channel number        */
/*            ubyte          *Data    IN  Pointer to received data            */
/*            ubyte          Length   IN  Length of data to receive           */
/* Pre-condition: none                                                        */
/* Constraints: Not reentrant function for same channel                       */
/*              Protection must be taken if used at interrupt level (disable  */
/*              interrupt before call at task level)                          */
/* Behavior:                                                                  */
/*   DO                                                                       */
/*    [ Receive data with serial peripheral driver ]                          */
/*   OD                                                                       */
/******************************************************************************/
#ifdef  __CY_TV2__
void Spic_ReceiveFrame (ubyte Channel, ubyte *TxBuff, ubyte *RxBuff,ubyte Length)
#else
void Spic_ReceiveFrame (ubyte Channel, ubyte *Data, ubyte Length)
#endif
{
  switch (Channel)
  {
#ifndef  __CY_TV2__
#ifdef __RH850__
#ifdef __RH850_F1x__
    #if (SPIC_RX_FRAME_CH_0_PHYS == _USED_)
    case 0:
      do
      {
        SPID_TransmitByte(0, 0);
        Length--;
        while (!SPID_OperationDone(0)) __NOP__;
        (void)SPID_NextOperation(0);
        *Data = SPID_ReceiveByte(0);
        Data++;
      } while (Length > 0);
      break;
    #endif

    #if (SPIC_RX_FRAME_CH_1_PHYS == _USED_)
    case 1:
      do
      {
        SPID_TransmitByte(1, 0);
        Length--;
        while (!SPID_OperationDone(1)) __NOP__;
        SPID_NextOperation(1);
        *Data = SPID_ReceiveByte(1);
        Data++;
      } while (Length > 0);
      break;
    #endif
	
    #if (SPIC_RX_FRAME_CH_2_PHYS == _USED_)
    case 2:
      do
      {
        SPID_TransmitByte(2, 0);
        Length--;
        while (!SPID_OperationDone(2)) __NOP__;
        SPID_NextOperation(2);
        *Data = SPID_ReceiveByte(2);
        Data++;
      } while (Length > 0);
      break;
    #endif
	
    #if (SPIC_RX_FRAME_CH_3_PHYS == _USED_)
    case 3:
      do
      {
        SPID_TransmitByte(3, 0);
        Length--;
        while (!SPID_OperationDone(3)) __NOP__;
        SPID_NextOperation(3);
        *Data = SPID_ReceiveByte(3);
        Data++;
      } while (Length > 0);
      break;
    #endif
	
    #if (SPIC_RX_FRAME_CH_4_PHYS == _USED_)
    case 4:
      do
      {
        SPID_TransmitByte(4, 0);
        Length--;
        while (!SPID_OperationDone(4)) __NOP__;
        (void)SPID_NextOperation(4);
        *Data = SPID_ReceiveByte(4);
        Data++;
      } while (Length > 0);
      break;
    #endif
	
    #if (SPIC_RX_FRAME_CH_5_PHYS == _USED_)
    case 5:
      do
      {
        SPID_TransmitByte(5, 0);
        Length--;
        while (!SPID_OperationDone(5)) __NOP__;
        (void)SPID_NextOperation(5);
        *Data = SPID_ReceiveByte(5);
        Data++;
      } while (Length > 0);
      break;
    #endif	
    default:
      break;
	
#endif	/*__RH850_F1x__*/

#else
    #if (SPIC_RX_FRAME_CH_0_PHYS == _USED_)
    case 0:
      SPID_SelectInDirection(0);
      do
      {
        SPID_TransmitByte(0, 0);
        Length--;
        while (!SPID_OperationDone(0)) __NOP__;
        SPID_NextOperation(0);
        *Data = SPID_ReceiveByte(0);
        Data++;
      } while (Length > 0);
      break;
    #endif

    #if (SPIC_RX_FRAME_CH_1_PHYS == _USED_)
    case 1:
      SPID_SelectInDirection(1);
      do
      {
        SPID_TransmitByte(1, 0);
        Length--;
        while (!SPID_OperationDone(1)) __NOP__;
        SPID_NextOperation(1);
        *Data = SPID_ReceiveByte(1);
        Data++;
      } while (Length > 0);
      break;
    #endif

    #if (SPIC_RX_FRAME_CH_2_PHYS == _USED_)
    case 2:
      SPID_SelectInDirection(2);
      do
      {
        SPID_TransmitByte(2, 0);
        Length--;
        while (!SPID_OperationDone(2)) __NOP__;
        SPID_NextOperation(2);
        *Data = SPID_ReceiveByte(2);
        Data++;
      } while (Length > 0);
      break;
    #endif

    #if (SPIC_RX_FRAME_CH_3_PHYS == _USED_)
    case 3:
      SPID_SelectInDirection(3);
      do
      {
        SPID_TransmitByte(3, 0);
        Length--;
        while (!SPID_OperationDone(3)) __NOP__;
        SPID_NextOperation(3);
        *Data = SPID_ReceiveByte(3);
        Data++;
      } while (Length > 0);
      break;
    #endif

    #if (SPIC_RX_FRAME_CH_4_PHYS == _USED_)
    case 4:
      SPID_SelectInDirection(4);
      do
      {
        SPID_TransmitByte(4, 0);
        Length--;
        while (!SPID_OperationDone(4)) __NOP__;
        SPID_NextOperation(4);
        *Data = SPID_ReceiveByte(4);
        Data++;
      } while (Length > 0);
      break;
    #endif

    #if (SPIC_RX_FRAME_CH_5_PHYS == _USED_)
    case 5:
      SPID_SelectInDirection(5);
      do
      {
        SPID_TransmitByte(5, 0);
        Length--;
        while (!SPID_OperationDone(5)) __NOP__;
        SPID_NextOperation(5);
        *Data = SPID_ReceiveByte(5);
        Data++;
      } while (Length > 0);
      break;
    #endif

    #if (SPIC_RX_FRAME_CH_6_PHYS == _USED_)
    case 6:
      SPID_SelectInDirection(6);
      do
      {
        SPID_TransmitByte(6, 0);
        Length--;
        while (!SPID_OperationDone(6)) __NOP__;
        SPID_NextOperation(6);
        *Data = SPID_ReceiveByte(6);
        Data++;
      } while (Length > 0);
      break;
    #endif

    #if (SPIC_RX_FRAME_CH_7_PHYS == _USED_)
    case 7:
      SPID_SelectInDirection(7);
      do
      {
        SPID_TransmitByte(7, 0);
        Length--;
        while (!SPID_OperationDone(7)) __NOP__;
        SPID_NextOperation(7);
        *Data = SPID_ReceiveByte(7);
        Data++;
      } while (Length > 0);
      break;
    #endif

    #if (SPIC_RX_FRAME_CH_8_PHYS == _USED_)
    case 8:
      SPID_SelectInDirection(8);
      do
      {
        SPID_TransmitByte(8, 0);
        Length--;
        while (!SPID_OperationDone(8)) __NOP__;
        SPID_NextOperation(8);
        *Data = SPID_ReceiveByte(8);
        Data++;
      } while (Length > 0);
      break;
    #endif

    #if (SPIC_RX_FRAME_CH_9_PHYS == _USED_)
    case 9:
      SPID_SelectInDirection(9);
      do
      {
        SPID_TransmitByte(9, 0);
        Length--;
        while (!SPID_OperationDone(9)) __NOP__;
        SPID_NextOperation(9);
        *Data = SPID_ReceiveByte(9);
        Data++;
      } while (Length > 0);
      break;
    #endif

    #if (SPIC_RX_FRAME_CH_10_PHYS == _USED_)
    case 10:
      SPID_SelectInDirection(10);
      do
      {
        SPID_TransmitByte(10, 0);
        Length--;
        while (!SPID_OperationDone(10)) __NOP__;
        SPID_NextOperation(10);
        *Data = SPID_ReceiveByte(10);
        Data++;
      } while (Length > 0);
      break;
    #endif

    #if (SPIC_RX_FRAME_CH_11_PHYS == _USED_)
    case 11:
      SPID_SelectInDirection(11);
      do
      {
        SPID_TransmitByte(11, 0);
        Length--;
        while (!SPID_OperationDone(11)) __NOP__;
        SPID_NextOperation(11);
        *Data = SPID_ReceiveByte(11);
        Data++;
      } while (Length > 0);
      break;
    #endif
	
	#if (SPIC_RX_FRAME_CH_12_PHYS == _USED_)
    case 12:
      SPID_SelectInDirection(12);
      do
      {
        SPID_TransmitByte(12, 0);
        Length--;
        while (!SPID_OperationDone(12)) __NOP__;
        SPID_NextOperation(12);
        *Data = SPID_ReceiveByte(12);
        Data++;
      } while (Length > 0);
      break;
    #endif

    #if (SPIC_RX_FRAME_CH_13_PHYS == _USED_)
    case 13:
      SPID_SelectInDirection(13);
      do
      {
        SPID_TransmitByte(13, 0);
        Length--;
        while (!SPID_OperationDone(13)) __NOP__;
        SPID_NextOperation(13);
        *Data = SPID_ReceiveByte(13);
        Data++;
      } while (Length > 0);
      break;
    #endif

    #if (SPIC_RX_FRAME_CH_14_PHYS == _USED_)
    case 14:
      SPID_SelectInDirection(14);
      do
      {
        SPID_TransmitByte(14, 0);
        Length--;
        while (!SPID_OperationDone(14)) __NOP__;
        SPID_NextOperation(14);
        *Data = SPID_ReceiveByte(14);
        Data++;
      } while (Length > 0);
      break;
    #endif

    #if (SPIC_RX_FRAME_CH_15_PHYS == _USED_)
    case 15:
      SPID_SelectInDirection(15);
      do
      {
        SPID_TransmitByte(15, 0);
        Length--;
        while (!SPID_OperationDone(15)) __NOP__;
        SPID_NextOperation(15);
        *Data = SPID_ReceiveByte(15);
        Data++;
      } while (Length > 0);
      break;
    #endif

   

    default:
      break;
#endif	  
#endif/* __CY_TV2__*/

#ifdef  __CY_TV2__
#if (SPIC_RX_FRAME_CH_0_PHYS == _USED_)
case 0:
	SPID_TransmitData(0,TxBuff,RxBuff,Length);
    while (SPID_TransmitComplete != SPID_OperationDone(0)) __NOP__;
  break;
#endif

#if (SPIC_RX_FRAME_CH_1_PHYS == _USED_)
case 1:
	SPID_TransmitData(1,TxBuff,RxBuff,Length);
    while (SPID_TransmitComplete != SPID_OperationDone(1)) __NOP__;
  break;
#endif

#if (SPIC_RX_FRAME_CH_2_PHYS == _USED_)
case 2:
	SPID_TransmitData(2,TxBuff,RxBuff,Length);
    while (SPID_TransmitComplete != SPID_OperationDone(2)) __NOP__;
  break;
#endif

#if (SPIC_RX_FRAME_CH_3_PHYS == _USED_)
case 3:
	SPID_TransmitData(3,TxBuff,RxBuff,Length);
    while (SPID_TransmitComplete != SPID_OperationDone(3)) __NOP__;
  break;
#endif

#if (SPIC_RX_FRAME_CH_4_PHYS == _USED_)
case 4:
	SPID_TransmitData(4,TxBuff,RxBuff,Length);
    while (SPID_TransmitComplete != SPID_OperationDone(4)) __NOP__;
  break;
#endif

#if (SPIC_RX_FRAME_CH_5_PHYS == _USED_)
case 5:
	SPID_TransmitData(5,TxBuff,RxBuff,Length);
    while (SPID_TransmitComplete != SPID_OperationDone(5)) __NOP__;
  break;
#endif

#if (SPIC_RX_FRAME_CH_6_PHYS == _USED_)
case 6:
	SPID_TransmitData(6,TxBuff,RxBuff,Length);
    while (SPID_TransmitComplete != SPID_OperationDone(6)) __NOP__;
  break;
#endif

#if (SPIC_RX_FRAME_CH_7_PHYS == _USED_)
case 7:
	SPID_TransmitData(7,TxBuff,RxBuff,Length);
    while (SPID_TransmitComplete != SPID_OperationDone(7)) __NOP__;
  break;
#endif
#endif/* __CY_TV2__*/
  }
}

#if (Spic_WORD_RX_FRAME == _USED_)
/******************************************************************************/
/* Name: Spic_ReceiveWordFrame                                                */
/* Role: Receive data from a serial line                                      */
/* Interface: ubyte          Channel  IN  Communication channel number        */
/*            ushort         *Data    IN  Pointer to received data           */
/*            ubyte          Length   IN  Length of data to receive           */
/* Pre-condition: none                                                        */
/* Constraints: Not reentrant function for same channel                       */
/*              Protection must be taken if used at interrupt level (disable  */
/*              interrupt before call at task level)                          */
/* Behavior:                                                                  */
/*   DO                                                                       */
/*    [ Receive data with serial peripheral driver ]                          */
/*   OD                                                                       */
/******************************************************************************/
void Spic_ReceiveWordFrame (ubyte Channel, ushort *Data, ubyte Length)
{
  switch (Channel)
  {
    #if (SPIC_RX_FRAME_CH_0_PHYS_WORD == _USED_)
    case 0:
      SPID_SelectInDirection(0);
      do
      {
        SPID_TransmitWord(0, 0);
        Length--;
        while (!SPID_OperationDone(0)) __NOP__;
        SPID_NextOperation(0);
        *Data = SPID_ReceiveWord(0);
        Data++;
      } while (Length > 0);
      break;
    #endif

    #if (SPIC_RX_FRAME_CH_1_PHYS_WORD == _USED_)
    case 1:
      SPID_SelectInDirection(1);
      do
      {
        SPID_TransmitWord(1, 0);
        Length--;
        while (!SPID_OperationDone(1)) __NOP__;
        SPID_NextOperation(1);
        *Data = SPID_ReceiveWord(1);
        Data++;
      } while (Length > 0);
      break;
    #endif

    #if (SPIC_RX_FRAME_CH_2_PHYS_WORD == _USED_)
    case 2:
      SPID_SelectInDirection(2);
      do
      {
        SPID_TransmitWord(2, 0);
        Length--;
        while (!SPID_OperationDone(2)) __NOP__;
        SPID_NextOperation(2);
        *Data = SPID_ReceiveWord(2);
        Data++;
      } while (Length > 0);
      break;
    #endif

    #if (SPIC_RX_FRAME_CH_3_PHYS_WORD == _USED_)
    case 3:
      SPID_SelectInDirection(3);
      do
      {
        SPID_TransmitWord(3, 0);
        Length--;
        while (!SPID_OperationDone(3)) __NOP__;
        SPID_NextOperation(3);
        *Data = SPID_ReceiveWord(3);
        Data++;
      } while (Length > 0);
      break;
    #endif

    #if (SPIC_RX_FRAME_CH_4_PHYS_WORD == _USED_)
    case 4:
      SPID_SelectInDirection(4);
      do
      {
        SPID_TransmitWord(4, 0);
        Length--;
        while (!SPID_OperationDone(4)) __NOP__;
        SPID_NextOperation(4);
        *Data = SPID_ReceiveWord(4);
        Data++;
      } while (Length > 0);
      break;
    #endif

    #if (SPIC_RX_FRAME_CH_5_PHYS_WORD == _USED_)
    case 5:
      SPID_SelectInDirection(5);
      do
      {
        SPID_TransmitWord(5, 0);
        Length--;
        while (!SPID_OperationDone(5)) __NOP__;
        SPID_NextOperation(5);
        *Data = SPID_ReceiveWord(5);
        Data++;
      } while (Length > 0);
      break;
    #endif

    #if (SPIC_RX_FRAME_CH_6_PHYS_WORD == _USED_)
    case 6:
      SPID_SelectInDirection(6);
      do
      {
        SPID_TransmitWord(6, 0);
        Length--;
        while (!SPID_OperationDone(6)) __NOP__;
        SPID_NextOperation(6);
        *Data = SPID_ReceiveWord(6);
        Data++;
      } while (Length > 0);
      break;
    #endif

    #if (SPIC_RX_FRAME_CH_7_PHYS_WORD == _USED_)
    case 7:
      SPID_SelectInDirection(7);
      do
      {
        SPID_TransmitWord(7, 0);
        Length--;
        while (!SPID_OperationDone(7)) __NOP__;
        SPID_NextOperation(7);
        *Data = SPID_ReceiveWord(7);
        Data++;
      } while (Length > 0);
      break;
    #endif

    #if (SPIC_RX_FRAME_CH_8_PHYS_WORD == _USED_)
    case 8:
      SPID_SelectInDirection(8);
      do
      {
        SPID_TransmitWord(8, 0);
        Length--;
        while (!SPID_OperationDone(8)) __NOP__;
        SPID_NextOperation(8);
        *Data = SPID_ReceiveWord(8);
        Data++;
      } while (Length > 0);
      break;
    #endif

    #if (SPIC_RX_FRAME_CH_9_PHYS_WORD == _USED_)
    case 9:
      SPID_SelectInDirection(9);
      do
      {
        SPID_TransmitWord(9, 0);
        Length--;
        while (!SPID_OperationDone(9)) __NOP__;
        SPID_NextOperation(9);
        *Data = SPID_ReceiveWord(9);
        Data++;
      } while (Length > 0);
      break;
    #endif

    #if (SPIC_RX_FRAME_CH_10_PHYS_WORD == _USED_)
    case 10:
      SPID_SelectInDirection(10);
      do
      {
        SPID_TransmitWord(10, 0);
        Length--;
        while (!SPID_OperationDone(10)) __NOP__;
        SPID_NextOperation(10);
        *Data = SPID_ReceiveWord(10);
        Data++;
      } while (Length > 0);
      break;
    #endif

    #if (SPIC_RX_FRAME_CH_11_PHYS_WORD == _USED_)
    case 11:
      SPID_SelectInDirection(11);
      do
      {
        SPID_TransmitWord(11, 0);
        Length--;
        while (!SPID_OperationDone(11)) __NOP__;
        SPID_NextOperation(11);
        *Data = SPID_ReceiveWord(11);
        Data++;
      } while (Length > 0);
      break;
    #endif
	
	 #if (SPIC_RX_FRAME_CH_12_PHYS_WORD == _USED_)
    case 12:
      SPID_SelectInDirection(12);
      do
      {
        SPID_TransmitWord(12, 0);
        Length--;
        while (!SPID_OperationDone(12)) __NOP__;
        SPID_NextOperation(12);
        *Data = SPID_ReceiveWord(12);
        Data++;
      } while (Length > 0);
      break;
    #endif

    #if (SPIC_RX_FRAME_CH_13_PHYS_WORD == _USED_)
    case 13:
      SPID_SelectInDirection(13);
      do
      {
        SPID_TransmitWord(13, 0);
        Length--;
        while (!SPID_OperationDone(13)) __NOP__;
        SPID_NextOperation(13);
        *Data = SPID_ReceiveWord(13);
        Data++;
      } while (Length > 0);
      break;
    #endif

    #if (SPIC_RX_FRAME_CH_14_PHYS_WORD == _USED_)
    case 14:
      SPID_SelectInDirection(14);
      do
      {
        SPID_TransmitWord(14, 0);
        Length--;
        while (!SPID_OperationDone(14)) __NOP__;
        SPID_NextOperation(14);
        *Data = SPID_ReceiveWord(14);
        Data++;
      } while (Length > 0);
      break;
    #endif

    #if (SPIC_RX_FRAME_CH_15_PHYS_WORD == _USED_)
    case 15:
      SPID_SelectInDirection(15);
      do
      {
        SPID_TransmitWord(15, 0);
        Length--;
        while (!SPID_OperationDone(15)) __NOP__;
        SPID_NextOperation(15);
        *Data = SPID_ReceiveWord(15);
        Data++;
      } while (Length > 0);
      break;
    #endif

   

    default:
      break;
  }
}
#endif /* Spic_WORD_RX_FRAME == _USED_ */
#endif /* Spic_RX_FRAME == _USED_ */


#if (Spic_TX_RX_FRAME == _USED_)
/******************************************************************************/
/* Name: Spic_TransmitAndReceiveFrame                                         */
/* Role: Transmit and receive data from a serial line                         */
/* Interface: ubyte          Channel  IN   Communication channel number       */
/*            ubyte          *TxData  IN   Pointer to transmitted data        */
/*            ubyte          Length   IN   Length of data to receive          */
/*            ubyte          *RxData  OUT  Pointer to received data           */
/* Pre-condition: none                                                        */
/* Constraints: Verify only one user during execution                         */
/* Behavior:                                                                  */
/*   DO                                                                       */
/*    [ FOR all data ]                                                        */
/*      [ Transfer data with serial peripheral driver ]                       */
/*      [ Receive data with serial peripheral driver ]                        */
/*    [ ROF ]                                                                 */
/*   OD                                                                       */
/******************************************************************************/
void Spic_TransmitAndReceiveFrame(ubyte Channel, ubyte *TxData, ubyte *RxData , ubyte Length)
{
  /* For 'Length' data, transmit and receive data */
  do
  {
    /* Fill the TXDATA with data */
    SPID_TransmitByte(Channel, *TxData);
    TxData++;
    Length--;
    /* Wait for end of transmission */
    while (!SPID_OperationDone(Channel)) __NOP__;
    SPID_NextOperation(Channel);
    *RxData = SPID_ReceiveByte(Channel);
    RxData++;
  } while (Length > 0);
}

#ifdef __REL_RL78__
/******************************************************************************/
/* Name: Spic_TransmitAndReceiveWordFrame                                     */
/* Role: Transmit and receive data from a serial line                         */
/* Interface: ubyte          Channel  IN   Communication channel number       */
/*            ushort         *TxData  IN   Pointer to transmitted data        */
/*            ubyte          Length   IN   Length of data to receive          */
/*            ushort         *RxData  OUT  Pointer to received data           */
/* Pre-condition: none                                                        */
/* Constraints: Verify only one user during execution                         */
/* Behavior:                                                                  */
/*   DO                                                                       */
/*    [ FOR all data ]                                                        */
/*      [ Transfer data with serial peripheral driver ]                       */
/*      [ Receive data with serial peripheral driver ]                        */
/*    [ ROF ]                                                                 */
/*   OD                                                                       */
/******************************************************************************/
void Spic_TransmitAndReceiveWordFrame(ubyte Channel, ushort *TxData, ushort *RxData , ubyte Length)
{
  /* For 'Length' data, transmit and receive data */
  do
  {
    /* Fill the TXDATA with data */
    SPID_TransmitWord(Channel, *TxData);
    TxData++;
    Length--;
    /* Wait for end of transmission */
    while (!SPID_OperationDone(Channel)) __NOP__;
    SPID_NextOperation(Channel);
    *RxData = SPID_ReceiveWord(Channel);
    RxData++;
  } while (Length > 0);
}

#endif /* Spic_TX_RX_FRAME == _USED_ */

#endif /* Spic_INLINE_FUNCTION == _NOT_USED_ */
#endif /* Spic_PHYS_CHANNEL == _USED_ */
#endif /* __REL_RL78__ */

#if (Spic_VIRT_CHANNEL == _USED_)

#if (Spic_TX_FRAME == _USED_)
/******************************************************************************/
/* Name: Spic_SimulTransmitOneByte                                            */
/* Role: Transmit one byte on a simulated serial line                         */
/* Interface: ubyte          Channel  IN  Communication channel number        */
/*            ubyte          Data     IN  Data label or value to transmit     */
/* Pre-condition: none                                                        */
/* Constraints: - Not reentrant function for same channel                     */
/*                Protection must be taken if used at interrupt level         */
/*                (disable interrupt before call at task level)               */
/*              - Support Master mode only                                    */
/*              - Support edge-on-half-cycle clock phase only                 */
/******************************************************************************/
void Spic_SimulTransmitOneByte(ubyte Channel, ubyte Data)
{
  switch (Channel)
  {
    #ifdef SPIC_TX_FRAME_CH_0_VIRT
    case 0:
      Spic_IoTransmitOneByte(0, Data);
      break;
    #endif

    #ifdef SPIC_TX_FRAME_CH_1_VIRT
    case 1:
      Spic_IoTransmitOneByte(1, Data);
      break;
    #endif

    #ifdef SPIC_TX_FRAME_CH_2_VIRT
    case 2:
      Spic_IoTransmitOneByte(2, Data);
      break;
    #endif

    #ifdef SPIC_TX_FRAME_CH_3_VIRT
    case 3:
      Spic_IoTransmitOneByte(3, Data);
      break;
    #endif

    #ifdef SPIC_TX_FRAME_CH_4_VIRT
    case 4:
      Spic_IoTransmitOneByte(4, Data);
      break;
    #endif

    #ifdef SPIC_TX_FRAME_CH_5_VIRT
    case 5:
      Spic_IoTransmitOneByte(5, Data);
      break;
    #endif

    #ifdef SPIC_TX_FRAME_CH_6_VIRT
    case 6:
      Spic_IoTransmitOneByte(6, Data);
      break;
    #endif

    #ifdef SPIC_TX_FRAME_CH_7_VIRT
    case 7:
      Spic_IoTransmitOneByte(7, Data);
      break;
    #endif

    #ifdef SPIC_TX_FRAME_CH_8_VIRT
    case 8:
      Spic_IoTransmitOneByte(8, Data);
      break;
    #endif

    #ifdef SPIC_TX_FRAME_CH_9_VIRT
    case 9:
      Spic_IoTransmitOneByte(9, Data);
      break;
    #endif

    #ifdef SPIC_TX_FRAME_CH_10_VIRT
    case 10:
      Spic_IoTransmitOneByte(10, Data);
      break;
    #endif

    #ifdef SPIC_TX_FRAME_CH_11_VIRT
    case 11:
      Spic_IoTransmitOneByte(11, Data);
      break;
    #endif
	
	  #ifdef SPIC_TX_FRAME_CH_12_VIRT
    case 12:
      Spic_IoTransmitOneByte(12, Data);
      break;
    #endif

    #ifdef SPIC_TX_FRAME_CH_13_VIRT
    case 13:
      Spic_IoTransmitOneByte(13, Data);
      break;
    #endif

    #ifdef SPIC_TX_FRAME_CH_14_VIRT
    case 14:
      Spic_IoTransmitOneByte(14, Data);
      break;
    #endif

    #ifdef SPIC_TX_FRAME_CH_15_VIRT
    case 15:
      Spic_IoTransmitOneByte(15, Data);
      break;
    #endif

   

    default:
      break;
  }
}
#endif /* Spic_TX_FRAME == _USED_ */


#if (Spic_RX_FRAME == _USED_)
/******************************************************************************/
/* Name: SPIC_SimulReceiveOneByte                                             */
/* Role: Receive one byte on a simulated serial line                          */
/* Interface: ubyte          Channel  IN  Communication channel number        */
/*            ubyte          Data     IN  Data label or value to transmit     */
/* Pre-condition: none                                                        */
/* Constraints: - Not reentrant function for same channel                     */
/*                Protection must be taken if used at interrupt level         */
/*                (disable interrupt before call at task level)               */
/*              - Support Master mode only                                    */
/*              - Support edge-on-half-cycle clock phase only                 */
/******************************************************************************/
void SPIC_SimulReceiveOneByte(ubyte Channel, ubyte *Data)
{
  switch (Channel)
  {
    #ifdef SPIC_RX_FRAME_CH_0_VIRT
    case 0:
      Spic_IoReceiveOneByte(0, Data);
      break;
    #endif

    #ifdef SPIC_RX_FRAME_CH_1_VIRT
    case 1:
      Spic_IoReceiveOneByte(1, Data);
      break;
    #endif

    #ifdef SPIC_RX_FRAME_CH_2_VIRT
    case 2:
      Spic_IoReceiveOneByte(2, Data);
      break;
    #endif

    #ifdef SPIC_RX_FRAME_CH_3_VIRT
    case 3:
      Spic_IoReceiveOneByte(3, Data);
      break;
    #endif

    #ifdef SPIC_RX_FRAME_CH_4_VIRT
    case 4:
      Spic_IoReceiveOneByte(4, Data);
      break;
    #endif

    #ifdef SPIC_RX_FRAME_CH_5_VIRT
    case 5:
      Spic_IoReceiveOneByte(5, Data);
      break;
    #endif

    #ifdef SPIC_RX_FRAME_CH_6_VIRT
    case 6:
      Spic_IoReceiveOneByte(6, Data);
      break;
    #endif

    #ifdef SPIC_RX_FRAME_CH_7_VIRT
    case 7:
      Spic_IoReceiveOneByte(7, Data);
      break;
    #endif

    #ifdef SPIC_RX_FRAME_CH_8_VIRT
    case 8:
      Spic_IoReceiveOneByte(8, Data);
      break;
    #endif

    #ifdef SPIC_RX_FRAME_CH_9_VIRT
    case 9:
      Spic_IoReceiveOneByte(9, Data);
      break;
    #endif

    #ifdef SPIC_RX_FRAME_CH_10_VIRT
    case 10:
      Spic_IoReceiveOneByte(10, Data);
      break;
    #endif

    #ifdef SPIC_RX_FRAME_CH_11_VIRT
    case 11:
      Spic_IoReceiveOneByte(11, Data);
      break;
    #endif
	
	  #ifdef SPIC_RX_FRAME_CH_12_VIRT
    case 12:
      Spic_IoReceiveOneByte(12, Data);
      break;
    #endif

    #ifdef SPIC_RX_FRAME_CH_13_VIRT
    case 13:
      Spic_IoReceiveOneByte(13, Data);
      break;
    #endif

    #ifdef SPIC_RX_FRAME_CH_14_VIRT
    case 14:
      Spic_IoReceiveOneByte(14, Data);
      break;
    #endif

    #ifdef SPIC_RX_FRAME_CH_15_VIRT
    case 15:
      Spic_IoReceiveOneByte(15, Data);
      break;
    #endif

   

    default:
      break;
  }
}
#endif /* Spic_RX_FRAME == _USED_ */


#if (Spic_TX_FRAME == _USED_)
/******************************************************************************/
/* Name: Spic_SimulTransmitFrame                                               */
/* Role: Simulate SPI to transmit data on a serial line                       */
/* Interface: ubyte          Channel  IN  Communication channel number        */
/*            ubyte          *Data    IN  Pointer to data                     */
/*            ubyte          Length   IN  Length of data                      */
/* Pre-condition: none                                                        */
/* Constraints: - Not reentrant function for same channel                     */
/*                Protection must be taken if used at interrupt level         */
/*                (disable interrupt before call at task level)               */
/*              - Support Master mode only                                    */
/*              - Support edge-on-half-cycle clock phase only                 */
/*              - Baud rate : processor dependent                             */
/*               (S12H = ~220KHz with clock = 16 KHz)                         */
/* Behavior:                                                                  */
/*   DO                                                                       */
/*    [ Drive data-out and clock pins to transmit data ]                      */
/*   OD                                                                       */
/******************************************************************************/
void Spic_SimulTransmitFrame(ubyte Channel, ubyte *TxData, ubyte Length)
{
  switch (Channel)
  {
    #ifdef SPIC_TX_FRAME_CH_0_VIRT
    case 0:
      Spic_IoTransmitFrame(0, TxData, Length);
      break;
    #endif

    #ifdef SPIC_TX_FRAME_CH_1_VIRT
    case 1:
      Spic_IoTransmitFrame(1, TxData, Length);
      break;
    #endif

    #ifdef SPIC_TX_FRAME_CH_2_VIRT
    case 2:
      Spic_IoTransmitFrame(2, TxData, Length);
      break;
    #endif

    #ifdef SPIC_TX_FRAME_CH_3_VIRT
    case 3:
      Spic_IoTransmitFrame(3, TxData, Length);
      break;
    #endif

    #ifdef SPIC_TX_FRAME_CH_4_VIRT
    case 4:
      Spic_IoTransmitFrame(4, TxData, Length);
      break;
    #endif

    #ifdef SPIC_TX_FRAME_CH_5_VIRT
    case 5:
      Spic_IoTransmitFrame(5, TxData, Length);
      break;
    #endif

    #ifdef SPIC_TX_FRAME_CH_6_VIRT
    case 6:
      Spic_IoTransmitFrame(6, TxData, Length);
      break;
    #endif

    #ifdef SPIC_TX_FRAME_CH_7_VIRT
    case 7:
      Spic_IoTransmitFrame(7, TxData, Length);
      break;
    #endif

    #ifdef SPIC_TX_FRAME_CH_8_VIRT
    case 8:
      Spic_IoTransmitFrame(8, TxData, Length);
      break;
    #endif

    #ifdef SPIC_TX_FRAME_CH_9_VIRT
    case 9:
      Spic_IoTransmitFrame(9, TxData, Length);
      break;
    #endif

    #ifdef SPIC_TX_FRAME_CH_10_VIRT
    case 10:
      Spic_IoTransmitFrame(10, TxData, Length);
      break;
    #endif

    #ifdef SPIC_TX_FRAME_CH_11_VIRT
    case 11:
      Spic_IoTransmitFrame(11, TxData, Length);
      break;
    #endif
	
	#ifdef SPIC_TX_FRAME_CH_12_VIRT
    case 12:
      Spic_IoTransmitFrame(12, TxData, Length);
      break;
    #endif

    #ifdef SPIC_TX_FRAME_CH_13_VIRT
    case 13:
      Spic_IoTransmitFrame(13, TxData, Length);
      break;
    #endif

    #ifdef SPIC_TX_FRAME_CH_14_VIRT
    case 14:
      Spic_IoTransmitFrame(14, TxData, Length);
      break;
    #endif

    #ifdef SPIC_TX_FRAME_CH_15_VIRT
    case 15:
      Spic_IoTransmitFrame(15, TxData, Length);
      break;
    #endif

  

    default:
      break;
  }
}
#endif /* Spic_TX_FRAME == _USED_ */


#if (Spic_RX_FRAME == _USED_)
/******************************************************************************/
/* Name: Spic_SimulReceiveFrame                                               */
/* Role: Simulate SPI to transmit data on a serial line                       */
/* Interface: ubyte          Channel  IN  Communication channel number        */
/*            ubyte          *Data    IN  Pointer to data                     */
/*            ubyte          Length   IN  Length of data                      */
/* Pre-condition: none                                                        */
/* Constraints: - Not reentrant function for same channel                     */
/*                Protection must be taken if used at interrupt level         */
/*                (disable interrupt before call at task level)               */
/*              - Support Master mode only                                    */
/*              - Support edge-on-half-cycle clock phase only                 */
/*              - Baud rate : processor dependent                             */
/*               (S12H = ~220KHz with clock = 16 KHz)                         */
/* Behavior:                                                                  */
/*   DO                                                                       */
/*    [ Drive data-out and clock pins to transmit data ]                      */
/*   OD                                                                       */
/******************************************************************************/
void Spic_SimulReceiveFrame(ubyte Channel, ubyte *TxData, ubyte Length)
{
  switch (Channel)
  {
    #ifdef SPIC_RX_FRAME_CH_0_VIRT
    case 0:
      Spic_IoReceiveFrame(0, TxData, Length);
      break;
    #endif

    #ifdef SPIC_RX_FRAME_CH_1_VIRT
    case 1:
      Spic_IoReceiveFrame(1, TxData, Length);
      break;
    #endif

    #ifdef SPIC_RX_FRAME_CH_2_VIRT
    case 2:
      Spic_IoReceiveFrame(2, TxData, Length);
      break;
    #endif

    #ifdef SPIC_RX_FRAME_CH_3_VIRT
    case 3:
      Spic_IoReceiveFrame(3, TxData, Length);
      break;
    #endif

    #ifdef SPIC_RX_FRAME_CH_4_VIRT
    case 4:
      Spic_IoReceiveFrame(4, TxData, Length);
      break;
    #endif

    #ifdef SPIC_RX_FRAME_CH_5_VIRT
    case 5:
      Spic_IoReceiveFrame(5, TxData, Length);
      break;
    #endif

    #ifdef SPIC_RX_FRAME_CH_6_VIRT
    case 6:
      Spic_IoReceiveFrame(6, TxData, Length);
      break;
    #endif

    #ifdef SPIC_RX_FRAME_CH_7_VIRT
    case 7:
      Spic_IoReceiveFrame(7, TxData, Length);
      break;
    #endif

    #ifdef SPIC_RX_FRAME_CH_8_VIRT
    case 8:
      Spic_IoReceiveFrame(8, TxData, Length);
      break;
    #endif

    #ifdef SPIC_RX_FRAME_CH_9_VIRT
    case 9:
      Spic_IoReceiveFrame(9, TxData, Length);
      break;
    #endif

    #ifdef SPIC_RX_FRAME_CH_10_VIRT
    case 10:
      Spic_IoReceiveFrame(10, TxData, Length);
      break;
    #endif

    #ifdef SPIC_RX_FRAME_CH_11_VIRT
    case 11:
      Spic_IoReceiveFrame(11, TxData, Length);
      break;
    #endif
	
	 #ifdef SPIC_RX_FRAME_CH_12_VIRT
    case 12:
      Spic_IoReceiveFrame(12, TxData, Length);
      break;
    #endif

    #ifdef SPIC_RX_FRAME_CH_13_VIRT
    case 13:
      Spic_IoReceiveFrame(13, TxData, Length);
      break;
    #endif

    #ifdef SPIC_RX_FRAME_CH_14_VIRT
    case 14:
      Spic_IoReceiveFrame(14, TxData, Length);
      break;
    #endif

    #ifdef SPIC_RX_FRAME_CH_15_VIRT
    case 15:
      Spic_IoReceiveFrame(15, TxData, Length);
      break;
    #endif

   
    default:
      break;
  }
}
#endif /* Spic_RX_FRAME == _USED_ */

#endif /* Spic_VIRT_CHANNEL == _USED_ */


/*_____ L O C A L - F U N C T I O N S_________________________________________*/


/*_____ E N D _____ (spic.c) _________________________________________________*/
