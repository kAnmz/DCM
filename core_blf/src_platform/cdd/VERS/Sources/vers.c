/******************************************************************************/
/* @F_NAME :          vers.c                                                  */
/* @F_PURPOSE :       manage reprogramming for MCU                            */
/* @F_CREATED_BY :      			                                          */
/* @F_CREATION_DATE :                                                         */
/* @F_LANGUAGE :      ANSI C                                                  */
/* @F_MPROC_TYPE :    target independent           						      */
/*************************************** (C) Copyright 2021 Marelli ***********/
/*______ I N C L U D E - F I L E S ___________________________________________*/
#include "Platform_Types.h"
#include "vers.h"
#include "vers_config_swid.h"
#include "string.h"
#include "wdfs_config_dynamic.h"

/*______ L O C A L - D E F I N E S ___________________________________________*/


/*______ G L O B A L - D A T A _______________________________________________*/

//VERS_HwVersion_t Vers_HwVersion = VERS_TI_CSOT;

#if 0
#pragma ghs startdata
#pragma ghs section text = default
#pragma ghs section rodata=".PROJECT_MESSAGE_CONST"
static const VERS_SystemMessage_t  VERS_SystemMessage = {
		Vers_PROJECT_NAME,
		Vers_SYSTEM_NAME,
		Vers_VERSION
};
#pragma ghs section rodata=default
#pragma ghs enddata
#endif

/*______ L O C A L - D A T A _________________________________________________*/


/*______ L O C A L - F U N C T I O N S - P R O T O T Y P E S _________________*/


/*______ G L O B A L - F U N C T I O N S _____________________________________*/
/*----------------------------------------------------------------------------*/
/*Name : Vers_init 			                                                  */
/*Role : Vers init                                                            */
/*Interface :                                                                 */
/*  - IN  : none	                                                          */
/*  - OUT : none					                                          */
/*Pre-condition : none			                                              */
/*Constraints   : none             			                                  */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [initialize parameters and main loop]                                   */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
void Vers_init(void)
{

}

/*______ G L O B A L - F U N C T I O N S _____________________________________*/
/*----------------------------------------------------------------------------*/
/*Name : Vers_runnable 			                                              */
/*Role : manage main logic of version                                         */
/*Interface :                                                                 */
/*  - IN  : none	                                                          */
/*  - OUT : none					                                          */
/*Pre-condition : none			                                              */
/*Constraints   : none             			                                  */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [initialize parameters and main loop]                                   */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
void Vers_runnable(void)
{

}/*end of Runnable_VERS*/

/*----------------------------------------------------------------------------*/
/*Name : Vers_runnable 			                                              */
/*Role : manage main logic of version                                         */
/*Interface :                                                                 */
/*  - IN  : none	                                                          */
/*  - OUT : none					                                          */
/*Pre-condition : none			                                              */
/*Constraints   : none             			                                  */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [initialize parameters and main loop]                                   */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
void VERS_SetPublicKeyDataPublicKeyProgramFlag(uint8 flag)
{
	WDFS_RamBootPara.PublicKeyData.PublicKeyProgramFlag = flag ;
}

/*----------------------------------------------------------------------------*/
/*Name : Vers_runnable 			                                              */
/*Role : manage main logic of version                                         */
/*Interface :                                                                 */
/*  - IN  : none	                                                          */
/*  - OUT : none					                                          */
/*Pre-condition : none			                                              */
/*Constraints   : none             			                                  */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [initialize parameters and main loop]                                   */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
uint8 VERS_GetPublicKeyDataPublicKeyProgramFlag(void)
{
  return (WDFS_RamBootPara.PublicKeyData.PublicKeyProgramFlag);
}

/*----------------------------------------------------------------------------*/
/*Name : VERS_GetPublicKeyDataPublicKeyCheckSum 			                  */
/*Role : manage main logic of version                                         */
/*Interface :                                                                 */
/*  - IN  : none	                                                          */
/*  - OUT : none					                                          */
/*Pre-condition : none			                                              */
/*Constraints   : none             			                                  */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [initialize parameters and main loop]                                   */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
void VERS_GetPublicKeyDataPublicKeyCheckSum(uint8 *buf, uint16 len)
{
  (void)memcpy(buf, WDFS_RamBootPara.PublicKeyData.PublicKeyCheckSum, len);
}

/*----------------------------------------------------------------------------*/
/*Name : VERS_GetPublicKeyDataPublicKeyCheckSumPtr 			                  */
/*Role : manage main logic of version                                         */
/*Interface :                                                                 */
/*  - IN  : none	                                                          */
/*  - OUT : none					                                          */
/*Pre-condition : none			                                              */
/*Constraints   : none             			                                  */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [initialize parameters and main loop]                                   */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
uint8 *VERS_GetPublicKeyDataPublicKeyCheckSumPtr(void)
{
	return (uint8 *)&WDFS_RamBootPara.PublicKeyData.PublicKeyCheckSum[0];
}

/*----------------------------------------------------------------------------*/
/*Name : VERS_SetBootDataConfigProgramFlag                                 */
/*Role : This Checksum member are not use in APP,and can not add a new byte   */
/*       for this NVM ID,so use this for Program flas                         */
/*Interface :                                                                 */
/*  - IN  : none                                                              */
/*  - OUT : none                                                              */
/*Pre-condition : none                                                        */
/*Constraints   : none                                                        */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
void VERS_SetBootDataConfigProgramFlag(uint16 flag)
{
	WDFS_RamBootPara.BootDataConfig.Checksum = flag;
}

/*----------------------------------------------------------------------------*/
/*Name : VERS_GetBootDataConfigProgramFlag                                 */
/*Role : This Checksum member are not use in APP,and can not add a new byte   */
/*       for this NVM ID,so use this for Program flas                         */
/*Interface :                                                                 */
/*  - IN  : none                                                              */
/*  - OUT : none                                                              */
/*Pre-condition : none                                                        */
/*Constraints   : none                                                        */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
uint16 VERS_GetBootDataConfigProgramFlag(void)
{
  return (WDFS_RamBootPara.BootDataConfig.Checksum);
}


/*______ L O C A L - F U N C T I O N S _______________________________________*/


