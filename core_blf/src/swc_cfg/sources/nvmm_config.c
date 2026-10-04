/******************************************************************************/
/* @F_NAME :          nvmm_config.c                                           */
/* @F_PURPOSE :       Ram block data                                          */
/* @F_CREATED_BY :    name of the file creator                                */
/* @F_CREATION_DATE : 2022/01/19                                              */
/* @F_LANGUAGE :      C                                                       */
/* @F_MPROC_TYPE :    target independent                                      */
/*************************************** (C) Copyright 2022 Marelli ***********/
/*______ I N C L U D E - F I L E S ___________________________________________*/
#include"nvmm_config.h"
#include "vers.h"
/*______ L O C A L - D E F I N E S ___________________________________________*/

/*______ L O C A L - T Y P E S _______________________________________________*/

/*______ G L O B A L - D A T A _______________________________________________*/

/*----------------Ram Block Data------------------------*/


/*----------------Rom Block Data------------------------*/

/*______ P R I V A T E - D A T A _____________________________________________*/
boolean NVMM_ReadAllFlag = FALSE;
/*______ L O C A L - D A T A _________________________________________________*/

/*______ L O C A L - M A C R O S _____________________________________________*/

/*______ I M P O R T - F U N C T I O N S - P R O T O T Y P E S _______________*/

/*______ L O C A L - F U N C T I O N S - P R O T O T Y P E S _________________*/

/*______ G L O B A L - F U N C T I O N S _____________________________________*/

/******************************************************************************/
/** 
* \brief      NVMM_Get_ReadAllFlag
* 
* \param      N/A 
* \retval     N/A 
* \note       N/A
*/
/******************************************************************************/
boolean NVMM_Get_ReadAllFlag(void)
{
	return NVMM_ReadAllFlag;
}

/******************************************************************************/
/** 
* \brief      NVMM_Set_ReadAllFlag
* 
* \param      N/A 
* \retval     N/A 
* \note       N/A
*/
/******************************************************************************/
void NVMM_Set_ReadAllFlag(boolean flag)
{
	NVMM_ReadAllFlag = flag;
}

/*______ P R I V A T E - F U N C T I O N S ___________________________________*/

/*______ L O C A L - F U N C T I O N S _______________________________________*/

/*______ E N D _____ (nvmm_config.c) _________________________________________*/
