/******************************************************************************/
/* @F_NAME :          rsam.h                                                  */
/* @F_PURPOSE :       RSA management                                          */
/* @F_CREATED_BY :    Weng dejian                                             */
/* @F_CREATION_DATE : 2022/09/22                                             */
/* @F_LANGUAGE :      ANSI C                                                  */
/* @F_MPROC_TYPE :    target independent           	                          */
/*************************************** (C) Copyright 2021 Marelli ***********/
#ifndef RSAM_H
#define RSAM_H
/*______ I N C L U D E - F I L E S ___________________________________________*/
#include "Std_Types.h"
#include "rsa.h"

/*______ G L O B A L - D E F I N E S _________________________________________*/



/*______ G L O B A L - T Y P E S _____________________________________________*/


#define RSAM_IDLE               0u
#define RSAM_START_RSA          MBEDTLS_RSA_START
#define RSAM_RSA_SUCCESS        MBEDTLS_RSA_SUCCESS
#define RSAM_RSA_FAIL           MBEDTLS_RSA_FAIL
#define RSAM_RSA_ONGOING        MBEDTLS_RSA_ONGOING

#define RSAM_RSA_OTHER_FAIL        0u
#define RSAM_RSA_APPHASH_FAIL      1u

/*______ G L O B A L - D A T A _______________________________________________*/


/*______ P R I V A T E - T Y P E S ___________________________________________*/


/*______ G L O B A L - M A C R O S ___________________________________________*/

/*______ G L O B A L - F U N C T I O N S - P R O T O T Y P E S _______________*/
/******************************************************************************/
/*Name : RSAM_Init                                                            */
/*Role:                                                                       */
/*Interface :                                                                 */
/*Pre-condition :                                                             */
/*Constraints: -                                                              */
/*Behaviour:                                                                  */
/******************************************************************************/
extern void RSAM_Init(void);

extern void RSAM_Runnable(void);
extern uint8 RSAM_StartSignVerify(uint8 *Signature, uint8 * vbtPtr, uint32 vbtLength, uint32 vbtAddr);
extern uint8 RSAM_GetRsaState(void);
extern uint8 RSAM_GetDetailErrType(void);
extern uint8 RSAM_CheckVBTFormat(uint8 *vbtPtr, uint32 vbtLength, uint32 FileStartAddress, uint32 FileTotalLength);
extern boolean RSAM_CheckPublicKeyIntegrity(void);
extern boolean RSAM_CheckMemoryHash256(uint8 *HashCalPtr, uint8 *HashCompPtr ,uint32 HashLen);
#endif /*RSAM_H*/
