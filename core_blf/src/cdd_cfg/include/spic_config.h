/******************************************************************************/
/*@F_NAME:           spic_config.h                                            */
/*@F_PURPOSE:        Configuration file for spic module                       */
/*@F_CREATED_BY:     Olivier DIETLIN                                          */
/*@F_CREATION_DATE:  01/04/2004                                               */
/*@F_MPROC_TYPE:     independent                                              */
/************************************** (C) Copyright 2010 Magneti Marelli ****/

#ifndef SPIC_CONFIG_H
#define SPIC_CONFIG_H


/*______ I N C L U D E - F I L E S ___________________________________________*/

#include "syst.h"
#include "scb_config_tv2.h"


/*_____ G L O B A L - D E F I N E ____________________________________________*/

/***************************************************************/
/* Channels declaration                                        */
/***************************************************************/

#define Spic_CH_Xxxx           Y             /* - Channel number: define here the number of the channel           */
                                             /*   (physical or virtual) you want to use.                          */
                                             /*   Corresponding physical channel must be activated in SPID config.*/
#define Spic_TYPE_Xxxx         PHYS          /* - Choose channel type:                                                                          */
                                             /*   PHYS:      physical channel uses the internal SPI driver (for up to 8 bits data length)       */
                                             /*   PHYS_WORD: physical channel uses the internal SPI driver (for higher than 8 bits data length) */
                                             /*   VIRT:      virtual channel is simulated with IO                                               */
#define Spic_CPOL_VIRT_CH_Y    Spic_CPOL_LOW /* - If your channel is VIRT, define here the polarity     */
                                             /*   of the simulated SPI: Spic_CPOL_LOW or Spic_CPOL_HIGH */

/* BARGRAPH led driver on the internal Channel 0        */
/*#define Spic_CH_Iodc_SPI_CHANNEL       0*/
/*#define Spic_TYPE_Iodc_SPI_CHANNEL     PHYS*/

/* Eepc_SPI on the internal Channel 1        */
/*#define Spic_CH_SHIFTER_SCI_CHANNEL        1*/
/*#define Spic_TYPE_SHIFTER_SCI_CHANNEL      PHYS*/

/* Shift Register on the internal Channel 2 */
/*
#define Spic_CH_Eepc_SPI_CHANNEL     *CSIH2
#define Spic_TYPE_Eepc_SPI_CHANNEL   PHYS
*/

#define Spic_CH_Sound_SPI_CHANNEL    4
#define Spic_TYPE_Eepc_SPI_CHANNEL   PHYS

/*
#define Spic_CH_Test_SPI_CHANNEL     0
#define Spic_TYPE_Test_SPI_CHANNEL   PHYS
*/

/******************************************************************/
/* Use following configurations to embed or not some functions                         */
/* Value allowed: SCB_SPI_FUNCTION_USED or SCB_FUNCTION_NOT_USED   */
/******************************************************************/

/* define channels and functions used */

/* RX functions for physical channels */
#define SPIC_RX_FRAME_CH_0_PHYS        SCB_FUNCTION_USED_CHANNEL0
#define SPIC_RX_FRAME_CH_0_PHYS_WORD   _NOT_USED_
#define SPIC_RX_FRAME_CH_1_PHYS        SCB_FUNCTION_USED_CHANNEL1
#define SPIC_RX_FRAME_CH_1_PHYS_WORD   _NOT_USED_
#define SPIC_RX_FRAME_CH_2_PHYS        SCB_FUNCTION_USED_CHANNEL2
#define SPIC_RX_FRAME_CH_2_PHYS_WORD   _NOT_USED_
#define SPIC_RX_FRAME_CH_3_PHYS        SCB_FUNCTION_USED_CHANNEL3
#define SPIC_RX_FRAME_CH_3_PHYS_WORD   _NOT_USED_
#define SPIC_RX_FRAME_CH_4_PHYS        SCB_FUNCTION_USED_CHANNEL4
#define SPIC_RX_FRAME_CH_4_PHYS_WORD   _NOT_USED_
#define SPIC_RX_FRAME_CH_5_PHYS        SCB_FUNCTION_USED_CHANNEL5
#define SPIC_RX_FRAME_CH_5_PHYS_WORD   _NOT_USED_
#define SPIC_RX_FRAME_CH_6_PHYS        SCB_FUNCTION_USED_CHANNEL6
#define SPIC_RX_FRAME_CH_6_PHYS_WORD   _NOT_USED_
#define SPIC_RX_FRAME_CH_7_PHYS        SCB_FUNCTION_USED_CHANNEL7
#define SPIC_RX_FRAME_CH_7_PHYS_WORD   _NOT_USED_

/* TX functions for physical channels */
#define SPIC_TX_FRAME_CH_0_PHYS        SCB_FUNCTION_USED_CHANNEL0
#define SPIC_TX_FRAME_CH_0_PHYS_WORD   _NOT_USED_
#define SPIC_TX_FRAME_CH_1_PHYS        SCB_FUNCTION_USED_CHANNEL1
#define SPIC_TX_FRAME_CH_1_PHYS_WORD   _NOT_USED_
#define SPIC_TX_FRAME_CH_2_PHYS        SCB_FUNCTION_USED_CHANNEL2
#define SPIC_TX_FRAME_CH_2_PHYS_WORD   _NOT_USED_
#define SPIC_TX_FRAME_CH_3_PHYS        SCB_FUNCTION_USED_CHANNEL3
#define SPIC_TX_FRAME_CH_3_PHYS_WORD   _NOT_USED_
#define SPIC_TX_FRAME_CH_4_PHYS        SCB_FUNCTION_USED_CHANNEL4
#define SPIC_TX_FRAME_CH_4_PHYS_WORD   _NOT_USED_
#define SPIC_TX_FRAME_CH_5_PHYS        SCB_FUNCTION_USED_CHANNEL5
#define SPIC_TX_FRAME_CH_5_PHYS_WORD   _NOT_USED_
#define SPIC_TX_FRAME_CH_6_PHYS        SCB_FUNCTION_USED_CHANNEL6
#define SPIC_TX_FRAME_CH_6_PHYS_WORD   _NOT_USED_
#define SPIC_TX_FRAME_CH_7_PHYS        SCB_FUNCTION_USED_CHANNEL7
#define SPIC_TX_FRAME_CH_7_PHYS_WORD   _NOT_USED_

/* RX functions for virtual channels */
#define SPIC_RX_FRAME_CH_0_VIRT   _NOT_USED_
#define SPIC_RX_FRAME_CH_1_VIRT   _NOT_USED_
#define SPIC_RX_FRAME_CH_2_VIRT   _NOT_USED_
#define SPIC_RX_FRAME_CH_3_VIRT   _NOT_USED_
#define SPIC_RX_FRAME_CH_4_VIRT   _NOT_USED_
#define SPIC_RX_FRAME_CH_5_VIRT   _NOT_USED_
#define SPIC_RX_FRAME_CH_6_VIRT   _NOT_USED_
#define SPIC_RX_FRAME_CH_7_VIRT   _NOT_USED_
#define SPIC_RX_FRAME_CH_8_VIRT   _NOT_USED_
#define SPIC_RX_FRAME_CH_9_VIRT   _NOT_USED_
#define SPIC_RX_FRAME_CH_10_VIRT  _NOT_USED_
#define SPIC_RX_FRAME_CH_11_VIRT  _NOT_USED_
#define SPIC_RX_FRAME_CH_12_VIRT  _NOT_USED_
#define SPIC_RX_FRAME_CH_13_VIRT  _NOT_USED_
#define SPIC_RX_FRAME_CH_14_VIRT  _NOT_USED_
#define SPIC_RX_FRAME_CH_15_VIRT  _NOT_USED_

/* TX functions for virtual channels */
#define SPIC_TX_FRAME_CH_0_VIRT   _NOT_USED_
#define SPIC_TX_FRAME_CH_1_VIRT   _NOT_USED_
#define SPIC_TX_FRAME_CH_2_VIRT   _NOT_USED_
#define SPIC_TX_FRAME_CH_3_VIRT   _NOT_USED_
#define SPIC_TX_FRAME_CH_4_VIRT   _NOT_USED_
#define SPIC_TX_FRAME_CH_5_VIRT   _NOT_USED_
#define SPIC_TX_FRAME_CH_6_VIRT   _NOT_USED_
#define SPIC_TX_FRAME_CH_7_VIRT   _NOT_USED_
#define SPIC_TX_FRAME_CH_8_VIRT   _NOT_USED_
#define SPIC_TX_FRAME_CH_9_VIRT   _NOT_USED_
#define SPIC_TX_FRAME_CH_10_VIRT  _NOT_USED_
#define SPIC_TX_FRAME_CH_11_VIRT  _NOT_USED_
#define SPIC_TX_FRAME_CH_12_VIRT  _NOT_USED_
#define SPIC_TX_FRAME_CH_13_VIRT  _NOT_USED_
#define SPIC_TX_FRAME_CH_14_VIRT  _NOT_USED_
#define SPIC_TX_FRAME_CH_15_VIRT  _NOT_USED_

/* Use Transmit & Receive function */
#define Spic_TX_RX_FRAME          _NOT_USED_

/* Use inlined functions instead of function call */
#define Spic_INLINE_FUNCTION      _NOT_USED_




/***************************************************************/
/* Automatically defined                                       */
/***************************************************************/
/* Use an internal SPI driver */
#if (SPIC_RX_FRAME_CH_0_PHYS  == SCB_SPI_FUNCTION_USED) \
 || (SPIC_RX_FRAME_CH_1_PHYS  == SCB_SPI_FUNCTION_USED) \
 || (SPIC_RX_FRAME_CH_2_PHYS  == SCB_SPI_FUNCTION_USED) \
 || (SPIC_RX_FRAME_CH_3_PHYS  == SCB_SPI_FUNCTION_USED) \
 || (SPIC_RX_FRAME_CH_4_PHYS  == SCB_SPI_FUNCTION_USED) \
 || (SPIC_RX_FRAME_CH_5_PHYS  == SCB_SPI_FUNCTION_USED) \
 || (SPIC_RX_FRAME_CH_6_PHYS  == SCB_SPI_FUNCTION_USED) \
 || (SPIC_RX_FRAME_CH_7_PHYS  == SCB_SPI_FUNCTION_USED) \
 || (SPIC_TX_FRAME_CH_0_PHYS  == SCB_SPI_FUNCTION_USED) \
 || (SPIC_TX_FRAME_CH_1_PHYS  == SCB_SPI_FUNCTION_USED) \
 || (SPIC_TX_FRAME_CH_2_PHYS  == SCB_SPI_FUNCTION_USED) \
 || (SPIC_TX_FRAME_CH_3_PHYS  == SCB_SPI_FUNCTION_USED) \
 || (SPIC_TX_FRAME_CH_4_PHYS  == SCB_SPI_FUNCTION_USED) \
 || (SPIC_TX_FRAME_CH_5_PHYS  == SCB_SPI_FUNCTION_USED) \
 || (SPIC_TX_FRAME_CH_6_PHYS  == SCB_SPI_FUNCTION_USED) \
 || (SPIC_TX_FRAME_CH_7_PHYS  == SCB_SPI_FUNCTION_USED)
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
 || (SPIC_TX_FRAME_CH_11_VIRT == _USED_)
  #define Spic_VIRT_CHANNEL         _USED_
#else
  #define Spic_VIRT_CHANNEL         _NOT_USED_
#endif

/* Use Transmit only function */
#if (SPIC_TX_FRAME_CH_0_PHYS  == SCB_SPI_FUNCTION_USED) \
 || (SPIC_TX_FRAME_CH_1_PHYS  == SCB_SPI_FUNCTION_USED) \
 || (SPIC_TX_FRAME_CH_2_PHYS  == SCB_SPI_FUNCTION_USED) \
 || (SPIC_TX_FRAME_CH_3_PHYS  == SCB_SPI_FUNCTION_USED) \
 || (SPIC_TX_FRAME_CH_4_PHYS  == SCB_SPI_FUNCTION_USED) \
 || (SPIC_TX_FRAME_CH_5_PHYS  == SCB_SPI_FUNCTION_USED) \
 || (SPIC_TX_FRAME_CH_6_PHYS  == SCB_SPI_FUNCTION_USED) \
 || (SPIC_TX_FRAME_CH_7_PHYS  == SCB_SPI_FUNCTION_USED) \
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
 || (SPIC_TX_FRAME_CH_11_VIRT == _USED_)
  #define Spic_TX_FRAME             _USED_
#else
  #define Spic_TX_FRAME             _NOT_USED_
#endif

/* Use Receive only function */
#if (SPIC_RX_FRAME_CH_0_PHYS  == SCB_SPI_FUNCTION_USED) \
 || (SPIC_RX_FRAME_CH_1_PHYS  == SCB_SPI_FUNCTION_USED) \
 || (SPIC_RX_FRAME_CH_2_PHYS  == SCB_SPI_FUNCTION_USED) \
 || (SPIC_RX_FRAME_CH_3_PHYS  == SCB_SPI_FUNCTION_USED) \
 || (SPIC_RX_FRAME_CH_4_PHYS  == SCB_SPI_FUNCTION_USED) \
 || (SPIC_RX_FRAME_CH_5_PHYS  == SCB_SPI_FUNCTION_USED) \
 || (SPIC_RX_FRAME_CH_6_PHYS  == SCB_SPI_FUNCTION_USED) \
 || (SPIC_RX_FRAME_CH_7_PHYS  == SCB_SPI_FUNCTION_USED) \
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
 || (SPIC_RX_FRAME_CH_11_VIRT == _USED_)
  #define Spic_RX_FRAME             _USED_
#else
  #define Spic_RX_FRAME             _NOT_USED_
#endif


#if (SPIC_TX_FRAME_CH_0_PHYS  == SCB_SPI_FUNCTION_USED) \
 || (SPIC_RX_FRAME_CH_0_PHYS  == SCB_SPI_FUNCTION_USED)
  #define SPIC_PHYS_CHANNEL0             _USED_
#else
  #define SPIC_PHYS_CHANNEL0             _NOT_USED_
#endif

#if (SPIC_TX_FRAME_CH_1_PHYS  == SCB_SPI_FUNCTION_USED) \
 || (SPIC_RX_FRAME_CH_1_PHYS  == SCB_SPI_FUNCTION_USED)
  #define SPIC_PHYS_CHANNEL1             _USED_
#else
  #define SPIC_PHYS_CHANNEL1             _NOT_USED_
#endif

#if (SPIC_TX_FRAME_CH_2_PHYS  == SCB_SPI_FUNCTION_USED) \
 || (SPIC_RX_FRAME_CH_2_PHYS  == SCB_SPI_FUNCTION_USED)
  #define SPIC_PHYS_CHANNEL2             _USED_
#else
  #define SPIC_PHYS_CHANNEL2             _USED_
#endif

#if (SPIC_TX_FRAME_CH_3_PHYS  == SCB_SPI_FUNCTION_USED) \
 || (SPIC_RX_FRAME_CH_3_PHYS  == SCB_SPI_FUNCTION_USED)
  #define SPIC_PHYS_CHANNEL3             _USED_
#else
  #define SPIC_PHYS_CHANNEL3             _NOT_USED_
#endif

#if (SPIC_TX_FRAME_CH_4_PHYS  == SCB_SPI_FUNCTION_USED) \
 || (SPIC_RX_FRAME_CH_4_PHYS  == SCB_SPI_FUNCTION_USED)
  #define SPIC_PHYS_CHANNEL4             _NOT_USED_
#else
  #define SPIC_PHYS_CHANNEL4             _NOT_USED_
#endif

#if (SPIC_TX_FRAME_CH_5_PHYS  == SCB_SPI_FUNCTION_USED) \
 || (SPIC_RX_FRAME_CH_5_PHYS  == SCB_SPI_FUNCTION_USED)
  #define SPIC_PHYS_CHANNEL5             _NOT_USED_
#else
  #define SPIC_PHYS_CHANNEL5             _NOT_USED_
#endif

#if (SPIC_TX_FRAME_CH_6_PHYS  == SCB_SPI_FUNCTION_USED) \
 || (SPIC_RX_FRAME_CH_6_PHYS  == SCB_SPI_FUNCTION_USED)
  #define SPIC_PHYS_CHANNEL6             _USED_
#else
  #define SPIC_PHYS_CHANNEL6             _NOT_USED_
#endif

#if (SPIC_TX_FRAME_CH_7_PHYS  == SCB_SPI_FUNCTION_USED) \
 || (SPIC_RX_FRAME_CH_7_PHYS  == SCB_SPI_FUNCTION_USED)
  #define SPIC_PHYS_CHANNEL7             _USED_
#else
  #define SPIC_PHYS_CHANNEL7             _NOT_USED_
#endif

#endif/*SPIC_CONFIG_H*/
/*_____ E N D _____ (spic_config.h) __________________________________________*/
