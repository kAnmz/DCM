/******************************************************************************/
/**
* \file       dcu_version.h
* \brief      
* \details    
*             
* \author     H.Huisheng
* \date       6/29/2020
* \par        History:
* 
\verbatim
  Version     Author                    Date            Desc   
  1.0         H.Huisheng                6/29/2020
\endverbatim  
*
*/
/**************** (C) Copyright 2018 Magneti Marelli Guangzhou ****************/

#ifndef DCU_VERSION_H_
#define DCU_VERSION_H_


/******************************************************************************/
/******************** LOTUS Common DID definition  *****************************/
/******************************************************************************/
/* DID D900 */
#define  SupplierECUSoftwareVersionNumber  "B0A09000  "
/* DID D901 */
#define  SupplierParameterSoftwareVersion  "P0303000  "

#define EOL_SW_VER                     0x0100

/* DID F18B */
#define  ECU_MANUFACTURING_DATE        {0xFF ,0xFF ,0xFF}

/* DID F18C */
#define  ECU_SERIAL_NUMBER             {0 ,0 ,0 ,0}

/* DID F13C */
#define  ECU_DDS_SERIAL_NUMBER         {0 ,0 ,0 ,0, 0 ,0 ,0 ,0}





/******************************************************************************/
/******************** LOTUS FL DCU DID definition  *****************************/
#if defined(DCU_FL)
/* DID F1A0 */
#define  APP_DIAG_DB_PART_NUMBER         {88,91,73,21,44,32,32,72} /* '  H' */
/* DID F1AE */
#define  ECU_SOFTWARE_PART_NUMBER        {2,\
                              /* SWLM */  88,96,70,33,82,32,32,68, /*'  D'*/ \
                              /* SWP1 */  88,96,70,33,86,32,32,68} 
/* DID F1AE */
#define  ECU_SWP1_PART_NUMBER /* SWP1 */ {88,96,70,33,86,32,32,68}  /*'  D'*/

/******************************************************************************/
/******************** LOTUS FR DCU DID definition  *****************************/
#elif defined(DCU_FR)
/* DID F1A0 */
#define  APP_DIAG_DB_PART_NUMBER         {88,91,73,36,48,32,32,72} /* '  H' */
/* DID F1AE */
#define  ECU_SOFTWARE_PART_NUMBER        {2,\
                              /* SWLM */  88,96,70,33,83,32,32,68, /*'  D'*/ \
                                          88,96,70,33,87,32,32,68} 
/* DID F1AE */
#define  ECU_SWP1_PART_NUMBER  /* SWP1 */  {88,96,70,33,87,32,32,68} /*'  D'*/                   
/******************************************************************************/
/******************** LOTUS RL DCU DID definition  *****************************/
#elif defined(DCU_RL)
/* DID F1A0 */
#define  APP_DIAG_DB_PART_NUMBER         {88,91,73,36,51,32,32,72} /* '  H' */
/* DID F1AE */
#define  ECU_SOFTWARE_PART_NUMBER        {2,\
                              /* SWLM */  88,96,70,33,84,32,32,68, /*'  D'*/ \
                                          88,96,70,33,88,32,32,68} 
/* DID F1AE */
#define  ECU_SWP1_PART_NUMBER /* SWP1 */ {88,96,70,33,88,32,32,68}  /*'  D'*/                   
/******************************************************************************/
/******************** LOTUS RR DCU DID definition  *****************************/           
#elif defined(DCU_RR)
/* DID F1A0 */
#define  APP_DIAG_DB_PART_NUMBER         {88,91,73,36,54,32,32,72} /* '  H' */
/* DID F1AE */
#define  ECU_SOFTWARE_PART_NUMBER        {2,\
                              /* SWLM */  88,96,70,33,85,32,32,68, /*'  D'*/ \
                                          88,96,70,33,89,32,32,68} 
/* DID F1AE  */
#define  ECU_SWP1_PART_NUMBER /* SWP1 */ {88,96,70,33,89,32,32,68}/*'  D'*/                             
#endif

#endif

