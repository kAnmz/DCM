/******************************************************************************/
/*@F_NAME:           spid_priv.h                                              */
/*@F_PURPOSE:        local header file of spi module                          */
/*@F_CREATED_BY:     H. LE DORTZ                                              */
/*@F_CREATION_DATE:  02/08/2010                                               */
/*@F_MPROC_TYPE:     target independent                                       */
/************************************** (C) Copyright 2010 Magneti Marelli ****/

#ifndef SPID_PRIV_H
#define SPID_PRIV_H


/*______ I N C L U D E - F I L E S ___________________________________________*/


/*______ L O C A L - D E F I N E _____________________________________________*/


/*______ L O C A L - T Y P E S________________________________________________*/


/*______ L O C A L - D A T A _________________________________________________*/

#ifdef __FSL_IMX53x__
/* As the SPI has an internal RX FIFO, we must read the RXDATA FIFO each time we send one octet.
   Like this we simulate one receive buffer with the last data received. */
extern ulong Spid_BufferRxData;
extern ulong Spid_BufferRxDataE1;
extern ulong Spid_BufferRxDataE2;

#endif /* __FSL_IMX53x__ */
#ifdef __FSL_IMX6x__
/* As the SPI has an internal RX FIFO, we must read the RXDATA FIFO each time we send one octet.
   Like this we simulate one receive buffer with the last data received. */
extern ulong Spid_BufferRxDataE1;
extern ulong Spid_BufferRxDataE2;
extern ulong Spid_BufferRxDataE3;
extern ulong Spid_BufferRxDataE4;
#endif /* __FSL_IMX6x__ */

/*______ L O C A L - M A C R O S _____________________________________________*/


/*______ L O C A L - F U N C T I O N S - P R O T O T Y P E S _________________*/


#endif /* SPID_PRIV_H */

/*_____END _____ (spid_priv.h) _______________________________________________*/
