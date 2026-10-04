/******************************************************************************/
/*@F_NAME:          iodd.c                                                    */
/*@F_PURPOSE:       iodd module                                               */
/*@F_CREATED_BY:    Olivier DIETLIN                                           */
/*@F_CREATION_DATE: 31/01/2001                                                */
/*@F_MPROC_TYPE:    IMX53 ,IMX6x, REL_RL78, NEC_V850                          */
/************************************** (C) Copyright 2014 Magneti Marelli ****/

#if defined(__FSL_IMX53x__) || defined(__FSL_IMX6x__)

/*______ I N C L U D E - F I L E S ___________________________________________*/

#ifdef __GHOS__
#include <INTEGRITY.h>
#endif /* __GHOS__ */

#include "iodd.h"


/*______ L O C A L - D E F I N E _____________________________________________*/


/*______ L O C A L - T Y P E S________________________________________________*/


/*______ G L O B A L - D A T A _______________________________________________*/

ulong IODD_MASK[IODD_MAX_PIN_NUMBER] =
{
  0xFFFFFFFCUL, 0xFFFFFFF3UL, 0xFFFFFFCFUL, 0xFFFFFF3FUL, 0xFFFFFCFFUL, 0xFFFFF3FFUL, 0xFFFFCFFFUL, 0xFFFF3FFFUL,
  0xFFFCFFFFUL, 0xFFF3FFFFUL, 0xFFCFFFFFUL, 0xFF3FFFFFUL, 0xFCFFFFFFUL, 0xF3FFFFFFUL, 0xCFFFFFFFUL, 0x3FFFFFFFUL,
  0xFFFFFFFCUL, 0xFFFFFFF3UL, 0xFFFFFFCFUL, 0xFFFFFF3FUL, 0xFFFFFCFFUL, 0xFFFFF3FFUL, 0xFFFFCFFFUL, 0xFFFF3FFFUL,
  0xFFFCFFFFUL, 0xFFF3FFFFUL, 0xFFCFFFFFUL, 0xFF3FFFFFUL, 0xFCFFFFFFUL, 0xF3FFFFFFUL, 0xCFFFFFFFUL, 0x3FFFFFFFUL
};

#ifdef __GHOS__
MemoryRegion IODD_MemoryRegion;
MemoryRegion IODD_VirtualMemoryRegion;
#endif /* __GHOS__ */


/*______ L O C A L - D A T A _________________________________________________*/


/*______ L O C A L - M A C R O S _____________________________________________*/


/*______ L O C A L - F U N C T I O N S - P R O T O T Y P E S _________________*/


/*______ G L O B A L - F U N C T I O N S _____________________________________*/

/******************************************************************************/
/*Name : IODD_Init                                                            */
/*Role : this function initialises the I/O Port driver                        */
/*Interface :     void                                                        */
/*Pre-condition : none                                                        */
/*Constraints :   none                                                        */
/*Behaviour :                                                                 */
/*  DO                                                                        */
/*  OD                                                                        */
/******************************************************************************/
void IODD_Init(void)
{
  #ifdef __GHOS__

  Value Attr;
  Address Start;
  Address Last;

  /* Map in GPIO registers */
  CheckSuccess(RequestResource((Object*)&IODD_MemoryRegion, "IODD_MemoryArea", "!systempassword"));
  CheckSuccess(GetMemoryRegionAddresses(IODD_MemoryRegion, &Start, &Last));
  /* Request a virtual memory region at the same address as the physical one */
  CheckSuccess(AllocateMemoryRegion(__ghs_VirtualMemoryRegionPool, GPIO1_BASE_ADDR_ASM, GPIO1_BASE_ADDR_ASM + Last - Start, &IODD_VirtualMemoryRegion));
  CheckSuccess(GetMemoryRegionAttributes(IODD_MemoryRegion, &Attr));
  CheckSuccess(SetMemoryRegionAttributes(IODD_VirtualMemoryRegion, Attr));
  CheckSuccess(MapMemoryRegion(IODD_VirtualMemoryRegion, IODD_MemoryRegion));
  CheckSuccess(GetMemoryRegionAddresses(IODD_VirtualMemoryRegion, &Start, &Last));

  #endif /* __GHOS__ */
}

#endif /* __FSL_IMX53x__ || ,__FSL_IMX6x__ */




#ifdef __REL_RL78__

/*______ I N C L U D E - F I L E S ___________________________________________*/

#include "iodd.h"


/*______ L O C A L - D E F I N E _____________________________________________*/


/*______ L O C A L - T Y P E S________________________________________________*/


/*______ G L O B A L - D A T A _______________________________________________*/


/*______ L O C A L - D A T A _________________________________________________*/


/*______ L O C A L - M A C R O S _____________________________________________*/


/*______ L O C A L - F U N C T I O N S - P R O T O T Y P E S _________________*/


/*______ G L O B A L - F U N C T I O N S _____________________________________*/

/******************************************************************************/
/*Name : IODD_Init                                                            */
/*Role : this function initialises the I/O Port with standard parameters      */
/*Interface :     none                                                        */
/*Pre-condition : none                                                        */
/*Constraints :   none                                                        */
/*Behaviour :                                                                 */
/*  DO                                                                        */
/*    [ configuring channel in order to preprocesseur directives ]            */
/*  OD                                                                        */
/******************************************************************************/
void IODD_Init(void)
{
  #ifdef IODD_NO_ANALOG_INPUT_USED
  /* Set all analog ports to digital IO */
  TARG_WriteByte(ADPC, 0x01);
  #endif
}


#endif /* __REL_RL78__ */



#ifdef __NEC_V850__

/*______ I N C L U D E - F I L E S ___________________________________________*/

#include "iodd.h"


/*______ L O C A L - D E F I N E _____________________________________________*/


/*______ L O C A L - T Y P E S________________________________________________*/


/*______ G L O B A L - D A T A _______________________________________________*/


/*______ L O C A L - D A T A _________________________________________________*/

#if defined(__NEC_V850_DL3) || defined(__NEC_V850_DJ3)
static volatile ubyte * const portDR[] =
{
  &(P0),
  &(P1),
  &(P2),
  &(P3),
  &(P4),
  &(P5),
  &(P6),
  &(P7L),
  &(P8),
  &(P9),
  &(P10),
  &(P11),
  &(P12),
  &(P13),
#ifdef __NEC_V850_DL3__
  &(P14)
#endif /* __NEC_V850_DL3__ */
};
#endif /* defined(__NEC_V850_DL3) || defined(__NEC_V850_DJ3) */

#ifdef __REL_V850_Dx4__
static volatile ushort vport = 0;
static volatile ushort * const portDR[] =
{
  &(P0),
  &(P1),
  &(P2),
  &(P3),
  &(P4),
  &(vport),
  &(vport),
  &(vport),
  &(vport),
  &(vport),
  &(P10),
  &(vport),
  &(vport),
  &(vport),
  &(vport),
  &(vport),
  &(P16),
  &(P17),
#ifndef __REL_V850_DJ4__
#ifndef __REL_V850_DK4H__
  &(vport),
  &(vport),
  &(vport),
  &(vport),  /* no port functionality */
  &(vport),  /* no port functionality */
  &(vport),  /* no port functionality */
  &(vport),  /* no port functionality */
  &(vport),
  &(vport),  /* no port functionality */
  &(P27),
  &(P28),
  &(P29),
  &(P30),
  &(vport),
  &(vport),
  &(vport),
  &(vport),
  &(vport),
  &(vport),
  &(vport),
  &(vport),
  &(vport),
  &(P40),
  &(P41),
#endif /* __REL_V850_DK4H__ */
#endif /* __REL_V850_DJ4__ */
};
#endif /* __REL_V850_Dx4__ */


/*______ L O C A L - M A C R O S _____________________________________________*/


/*______ L O C A L - F U N C T I O N S - P R O T O T Y P E S _________________*/


/*______ G L O B A L - F U N C T I O N S _____________________________________*/

#if defined(__NEC_V850_DL3) || defined(__NEC_V850_DJ3)
/*----------------------------------------------------------------------------*/
/*Name : IODD_SetPortOutputPinData                                            */
/*Role : Set a state on the pin of a port in uotput mode                      */
/*Interface :                                                                 */
/*  - PortNumber IN, Number of port for :                                     */
/*                                    NEC V850 Dx3                            */
/*                                    [0,1,2,3,4,5,6,8,9,10,11,12,13,14]      */
/*                                                                            */
/*  - PinNumber IN, number of the selected pin [0..7]                         */
/*  - State     IN, requested output state of the pin [0, 1]                  */
/*Pre-condition : -                                                           */
/*Constraints :  -                                                            */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [set the requested state on the pin]                                    */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
void IODD_SetPortOutputPinData(ubyte PortNumber, ubyte PinNumber, ubyte State)
{
  if(PortNumber < (sizeof(portDR)/sizeof(ubyte *)))
  {
    if (State)
    {
      *portDR[PortNumber] |= (0x01 << PinNumber);
    }
    else
    {
      *portDR[PortNumber] &= (~(0x01 << PinNumber));
    }
  }
}


/*----------------------------------------------------------------------------*/
/*Name : IODD_GetPortOutputPinData                                            */
/*Role : Get the state of a pin of a port in uotput mode                      */
/*Interface :                                                                 */
/*  - PortNumber IN, Number of port for :                                     */
/*                                    NEC V850 Dx3                            */
/*                                    [0,1,2,3,4,5,6,8,9,10,11,12,13,14]      */
/*                                                                            */
/*  - PinNumber IN, number of the selected pin [0..7]                         */
/*  - State     OUT, state of the pin (0, 1)                                  */
/*Pre-condition : -                                                           */
/*Constraints :  -                                                            */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [return state on the pin]                                               */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
bool_t IODD_GetPortOutputPinData(ubyte PortNumber,ubyte PinNumber)
{
  return ( ( (*portDR[PortNumber]) >> PinNumber) & 0x01);
}
#endif /* defined(__NEC_V850_DL3) || defined(__NEC_V850_DJ3) */

#ifdef __REL_V850_Dx4__
/*----------------------------------------------------------------------------*/
/*Name : IODD_SetPortOutputPinData                                            */
/*Role : Set a state on the pin of a port in uotput mode                      */
/*Interface :                                                                 */
/*  - PortNumber IN, Number of port for :                                     */
/*                                    NEC V850 Dx4                            */
/*                                    [0,1,2,3,4,10,16,17]                    */
/*                                                                            */
/*  - PinNumber IN, number of the selected pin [0..15]                        */
/*  - State     IN, requested output state of the pin [0, 1]                  */
/*Pre-condition : -                                                           */
/*Constraints :  -                                                            */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [set the requested state on the pin]                                    */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
void IODD_SetPortOutputPinData(ubyte PortNumber, ushort PinNumber, ubyte State)
{
  if(PortNumber < (sizeof(portDR)/sizeof(ushort *)))
  {
    if ( ( __GETSR() & PSW_ID_BIT_MASK ) == 0 ) 
    { 
      DisableAllInterrupts();  
      if (State)
      {
        *portDR[PortNumber] |= (0x01 << PinNumber);
      }
      else
      {
        *portDR[PortNumber] &= (~(0x01 << PinNumber));
      }
      EnableAllInterrupts(); 
    }
    else
    {
      if (State)
      {
        *portDR[PortNumber] |= (0x01 << PinNumber);
      }
      else
      {
        *portDR[PortNumber] &= (~(0x01 << PinNumber));
      }
    }
  }
}


/*----------------------------------------------------------------------------*/
/*Name : IODD_GetPortOutputPinData                                            */
/*Role : Get the state of a pin of a port in uotput mode                      */
/*Interface :                                                                 */
/*  - PortNumber IN, Number of port for :                                     */
/*                                    NEC V850 Dx4                            */
/*                                    [0,1,2,3,4,10,16,17]                    */
/*                                                                            */
/*  - PinNumber IN, number of the selected pin [0..7]                         */
/*  - State     OUT, state of the pin (0, 1)                                  */
/*Pre-condition : -                                                           */
/*Constraints :  -                                                            */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [return state on the pin]                                               */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
bool_t IODD_GetPortOutputPinData(ubyte PortNumber,ubyte PinNumber)
{
  return ( ( (*portDR[PortNumber]) >> PinNumber) & 0x01);
}
#endif /* __REL_V850_Dx4__ */

/*______ L O C A L - F U N C T I O N S _______________________________________*/

#endif /* __NEC_V850__ */


/*_____E N D _____ (iodd.c) __________________________________________________*/
