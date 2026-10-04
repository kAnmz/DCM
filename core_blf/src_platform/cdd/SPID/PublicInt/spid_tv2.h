/******************************************************************************/
/*@F_NAME:           spid_tv2.h                                                                                                                      */
/*@F_PURPOSE:        SPI Driver Module                                                                                                    */
/*@F_CREATED_BY:     Wei Liang                                                                                                                  */
/*@F_CREATION_DATE:  2020/10/26                                                                                                        */
/*@F_LANGUAGE :      ANSI C                                                                                                                        */
/*@F_MPROC_TYPE:     Cypress Traveo II series                                                                                     */
/********************************************** (C) Copyright 2020 Marelli *********/
#ifndef SPID_TV2_H
#define SPID_TV2_H

#ifdef __CY_TV2__
/*______ I N C L U D E - F I L E S ___________________________________________*/
#include"syst.h"
#include"spid_config_tv2.h"
#include"cy_scb_spi.h"
/*______ G L O B A L - D E F I N E S _________________________________________*/


/*______ G L O B A L - T Y P E S _____________________________________________*/
typedef enum
{
	SPID_TransmitNone,
	SPID_TransmitComplete,
	SPID_TransmitBusy,
	SPID_TransmitError,
} SPID_TransmitState_t;



/*______ G L O B A L - M A C R O S ___________________________________________*/


/*______ G L O B A L - F U N C T I O N S - P R O T O T Y P E S _______________*/
/******************************************************************************/
/* Name: SPID_Init                                                            																				*/
/* Role: Initialise the module                                                																			*/
/* Interface: none                                                            																					*/
/* Pre-condition: none                                                       																				 */
/* Constraints: none                                                          																				*/
/* Behaviour:                                                                 																						*/
/* DO                                                                         																							*/
/*   [ Initialize hardware according to configuration ]                       														*/
/* OD                                                                         																							*/
/******************************************************************************/
extern void SPID_Init (void);

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
extern void SPID_InitChannel(uint8 SpidChannel );

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
extern SPID_TransmitState_t  SPID_OperationDone(uint8 Channel);

/*******************************************************************************/
/* Name: SPID_TransmitData                                                    																	   	*/
/* Role: Provide the mean to start transmit data on selected channel    											 */
/* Interface: Channel          IN  Communication channel number               											*/
/*                     Data                IN  Byte to transmit on serial communication  										*/
/*                     Length            Send Data length																								*/
/* Pre-condition: The transmit data register for the channel must be empty    								*/
/* Constraints: none                                                          																				*/
/******************************************************************************/
extern cy_en_scb_spi_status_t SPID_TransmitData(uint8 Channel, uint8 *TxData,uint8 *RxData, uint32 Length);
#endif /* SPID_TV2_H */
#endif /* __CY_TV2__ */

/*______ E N D _____ (spid_tv2.h) ____________________________________________*/
