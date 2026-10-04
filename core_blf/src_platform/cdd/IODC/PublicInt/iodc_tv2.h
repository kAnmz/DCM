/******************************************************************************/
/*@F_NAME:               iodc_tv2.h                                           */
/*@F_PURPOSE:            Public interface of iodc module                      */
/*@F_CREATED_BY:         Yanbin SHEN                                          */
/*@F_CREATION_DATE:      2020 09 08                                           */
/*@F_MPROC_TYPE:         CYPRESS Traveo II series                             */
/***************************************** (C) Copyright 2020 Marelli Inc. ****/

#ifndef IODC_TV2_H
#define IODC_TV2_H

#ifdef __CY_TV2__

/*______ I N C L U D E - F I L E S ___________________________________________*/

#include "iodd.h"
#include "syst.h"

/*______ G L O B A L - D E F I N E ___________________________________________*/

/*
#define   IODC_ACTIVE           IODD_HIGH
#define   IODC_INACTIVE         IODD_LOW
 no redefine of IODD due to problem with COSMIC compiler
*/
#ifndef IODC_ACTIVE
#define   IODC_ACTIVE           1
#endif /*IODC_ACTIVE*/

#ifndef IODC_INACTIVE
#define   IODC_INACTIVE         0
#endif /*IODC_INACTIVE*/

#ifndef IODC_POSITIVE
#define   IODC_POSITIVE         IODC_ACTIVE
#endif /*IODC_POSITIVE*/

#ifndef IODC_NEGATIVE
#define   IODC_NEGATIVE         IODC_INACTIVE
#endif /*IODC_NEGATIVE*/

#ifndef IODC_NO_EVENT
#define   IODC_NO_EVENT         ((ubyte)  0)
#endif /*IODC_NO_EVENT*/

#ifndef IODC_LED_TURN_ON
#define   IODC_LED_TURN_ON      IODC_ACTIVE
#endif /*IODC_LED_TURN_ON*/

#ifndef IODC_LED_TURN_OFF
#define   IODC_LED_TURN_OFF     IODC_INACTIVE
#endif /*IODC_LED_TURN_OFF*/


/*______ G L O B A L - D I R E C T I V E _____________________________________*/


/*______ G L O B A L - M A C R O S ___________________________________________*/

/*----------------------------------------------------------------------------*/
/* Name : IODC_EnableIrq                                                      */
/* Role : Enable interrupt request                                            */
/* Interface :                                                                */
/*   - VirtualId IN, name of Irq for TRAVEO II                                */
/*                                 [Virtual HSI name]                         */
/* Pre-condition : -                                                          */
/* Constraints : -                                                            */
/* Behavior :                                                                 */
/*   DO                                                                       */
/*     [enable interrupt requested]                                           */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/
#define IODC_EnableIrq(VirtualId)\
        IODD_EnableIrq(IODC_DirectIn_Port_ ## VirtualId,\
        		       IODC_DirectIn_Bit_ ## VirtualId)

/*----------------------------------------------------------------------------*/
/* Name : IODC_DisableIrq                                                     */
/* Role : Disable interrupt request                                           */
/* Interface :                                                                */
/*   - VirtualId IN, name of Irq for TRAVEO II                                */
/*                                 [Virtual HSI name]                         */
/* Pre-condition : -                                                          */
/* Constraints : -                                                            */
/* Behavior :                                                                 */
/*   DO                                                                       */
/*     [disable interrupt requested]                                          */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/
#define IODC_DisableIrq(VirtualId) \
	    IODD_DisableIrq(IODC_DirectIn_Port_ ## VirtualId,\
        		        IODC_DirectIn_Bit_ ## VirtualId)


/*----------------------------------------------------------------------------*/
/* Name : IODC_ClearStatusIrq                                                 */
/* Role : Clear interrupt request flag                                        */
/* Interface :                                                                */
/*   - VirtualId IN, name of Irq for TRAVEO II                                */
/*                                 [Virtual HSI name]                         */
/* Pre-condition : -                                                          */
/* Constraints : -                                                            */
/* Behavior :                                                                 */
/*   DO                                                                       */
/*     [Clear the interrupt status]                                           */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/
#define IODC_ClearStatusIrq(VirtualId) \
        IODD_ClearStatusIrq(IODC_DirectIn_Port_ ## VirtualId,\
        		            IODC_DirectIn_Bit_ ## VirtualId)

/*----------------------------------------------------------------------------*/
/* Name : IODC_ReadStatusIrq                                                  */
/* Role : Read interrupt request flag                                         */
/* Interface :                                                                */
/*   - VirtualId IN, name of Irq for TRAVEO II                                */
/*                                 [Virtual HSI name]                         */
/* Pre-condition : -                                                          */
/* Constraints : -                                                            */
/* Behavior :                                                                 */
/*   DO                                                                       */
/*     [read the interrupt status]                                            */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/
#define IODC_ReadStatusIrq(VirtualId) \
	    IODD_ReadStatusIrq(IODC_DirectIn_Port_ ## VirtualId,\
        		           IODC_DirectIn_Bit_ ## VirtualId)

/*----------------------------------------------------------------------------*/
/* Name : IODC_GetInterruptStatusMasked                                       */
/* Role : Get Pin Interrupt status masked                                     */
/*Interface :                                                                 */
/*   - VirtualId IN, name of Irq for TRAVEO II                                */
/*                                 [Virtual HSI name]                         */
/*  - Mask      OUT /TURE or FALSE                                            */
/* 0 = Pin interrupt not detected or not forwarded to CPU interrupt controller*/
/* 1 = Pin interrupt detected and forwarded to CPU interrupt controller       */
/* Behavior :                                                                 */
/*   DO                                                                       */
/*     [Return the pin's current interrupt state after being masked.]         */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/
#define IODC_GetInterruptStatusMasked(VirtualId)\
	    IODD_GetInterruptStatusMasked(IODC_DirectIn_Port_ ## VirtualId,\
        		                      IODC_DirectIn_Bit_ ## VirtualId)

/*----------------------------------------------------------------------------*/
/*Name : IODC_PinAlternaeMode                                                 */
/*Role : Configures the HSIOM connection to the pin                           */
/*Interface :                                                                 */
/*  - VirtualId IN, pin network name :                                        */
/*  - AlternatePin IN, en_hsiom_sel_t type pin definition                     */
/*                                                                            */
/*Pre-condition : -                                                           */
/*Constraints :This function modifies a port register in a rbead-modify-write */
/*            operation. It is not thread safe as the resource is shared among*/
/*            multiple pins on a port.                                        */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [ Connects the specified High speed Input Ouput Multiplexer(HSIOM)      */

/*      selection to the pin.]                                                */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#define IODC_PinAlternaeMode(VirtualId, AlternateMode)\
        IODD_ALTER_FUNC(IODC_DirectIn_Port_ ## VirtualId,\
        		         IODC_DirectIn_Bit_ ## VirtualId,\
				         AlternateMode)

/*----------------------------------------------------------------------------*/
/* Name : IODC_SetGlitchFilterIrq                                             */
/* Role : Configures which pin on the port connects to the port filter.       */
/*Interface :                                                                 */
/*  - PortName  IN, name of port for :                                        */
/*                                    Cypress Traveo II                       */
/*                                    [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,...]*/
/*  - PinNumber IN, pin number of pin :                                       */
/*                                    Cypress Traveo II                       */
/*                                    [0,1,2,3,4,5,6,7]                       */
/* Pre-condition : -                                                          */
/* Constraints : Only one Pin of Port can be set glitch filter to Interrupt   */
/* Behavior :                                                                 */
/*   DO                                                                       */
/*     [Clear the interrupt status]                                           */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/
#define IODC_SetGlitchFilterIrq(VirtualId)\
	    IODD_SetGlitchFilterIrq(IODC_DirectIn_Port_ ## VirtualId,\
        		                IODC_DirectIn_Bit_ ## VirtualId)

/*----------------------------------------------------------------------------*/
/* Name : IODC_SetSoftwareInterruptTrigger                                    */
/* Role : setting a Pin to generate trigger interrupt request                 */
/*Interface :                                                                 */
/*  - PortName  IN, name of port for :                                        */
/*                                    Cypress Traveo II                       */
/*                                    [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,...]*/
/*  - PinNumber IN, pin number of pin :                                       */
/*                                    Cypress Traveo II                       */
/*                                    [0,1,2,3,4,5,6,7]                       */
/* Behavior :                                                                 */
/*   DO                                                                       */
/*     [Force a pin interrupt to trigger.]                                    */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/
#define IODC_SetSoftwareInterruptTrigger(VirtualId)\
	    IODD_SetSoftwareInterruptTrigger(IODC_DirectIn_Port_ ## VirtualId,\
        		                         IODC_DirectIn_Bit_ ## VirtualId)

/*----------------------------------------------------------------------------*/
/*Name : IODC_GetAlternateMode                                                */
/*Role : Configures the HSIOM connection to the pin                           */
/*Interface :                                                                 */
/*  - PortName  IN, name of port for :                                        */
/*                                    Cypress Traveo II                       */
/*                                    [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,...]*/
/*  - PinNumber IN, pin number of pin :                                       */
/*                                    Cypress Traveo II                       */
/*                                    [0,1,2,3,4,5,6,7]                       */
/*  - AlternateMode OUT, en_hsiom_sel_t type pin definition                   */
/*                                                                            */
/*Constraints : This function modifies a port register in a read-modify-write */
/*            operation. It is not thread safe as the resource is shared among*/
/*            multiple pins on a port.                                        */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [ get Connects the specified High speed Input Ouput Multiplexer(HSIOM)  */
/*      selection to the pin.]                                                */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#define IODC_GetAlternateMode(VirtualId)\
        IODD_GetAlternateMode(IODC_Out_Port_ ## VirtualId,\
        	               	  IODC_Out_Bit_ ## VirtualId)

/*----------------------------------------------------------------------------*/
/*Name : IODC_SetOuputInverse                                                 */
/*Role : Set a inverse state on a virtual output                              */
/*Interface :                                                                 */
/*  - IN : number of output                                                   */
/*Pre-condition : -                                                           */
/*Constraints : -                                                             */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [set inverse state on the requested output pin]                         */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#define IODC_SetOutputInverse(VirtualId) \
        IODD_SetPinStatusInverse(IODC_Out_Port_ ## VirtualId,\
                                 IODC_Out_Bit_ ## VirtualId)

#endif /*__CY_TV2__*/

#endif /*IODC_TV2_H*/

/*_____END _____ (iodc_tv2.h) ________________________________________________*/

