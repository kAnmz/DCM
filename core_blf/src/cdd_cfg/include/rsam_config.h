/******************************************************************************/
/*@F_NAME:           rsam_config.h                                            */
/*@F_PURPOSE:        RSAM - Module configuration implementation               */
/*@F_CREATED_BY:     Weng dejian                                              */
/*@F_CREATION_DATE:  2022/10/18                                               */
/*@F_LANGUAGE :      ANSI C                                                   */
/*@F_MPROC_TYPE:     Processor independent                                    */
/************************************** (C) Copyright 2011 Magneti Marelli ****/

#ifndef RSAM_CONFIG_H
#define RSAM_CONFIG_H


/*______ I N C L U D E - F I L E S ___________________________________________*/

/*______ G L O B A L - D E F I N E S _________________________________________*/
#define RSAM_PK_MODULUS_LEN          (256u)
#define RSAM_PK_EXPONENT_LEN         (4u)
#define RSAM_PK_CHECKSUM_LEN		 (32u)
#define RSAM_PUBLICKEY_LEN           (RSAM_PK_MODULUS_LEN + RSAM_PK_EXPONENT_LEN)
/*______ G L O B A L - T Y P E S _____________________________________________*/

/*______ G L O B A L - D A T A _______________________________________________*/

/*______ G L O B A L - M A C R O S ___________________________________________*/

/*______ G L O B A L - F U N C T I O N S - P R O T O T Y P E S _______________*/
extern void Rsam_GetPublicKey(void);
extern sint8 Rsam_Memcmp(const void* buf1, const void* buf2, uint16 len);
extern uint32 Rsam_GetApplAddress(uint32 address);
extern void DIAG_RSAPublicKey_RD(uint8* Data);
#endif /* RSAM_CONFIG_H */


/*______ E N D _____ (lifm_config.h) _________________________________________*/
