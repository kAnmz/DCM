/******************************************************************************/
/* @F_NAME :          fblm_main.h                                             */
/* @F_PURPOSE :       manage reprogramming for MCU                            */
/* @F_CREATED_BY :    Jianhua.Wu  			                                  */
/* @F_CREATION_DATE : 2021.07.14                                              */
/* @F_LANGUAGE :      ANSI C                                                  */
/* @F_MPROC_TYPE :    target independent           						      */
/*************************************** (C) Copyright 2021 Marelli ***********/

#ifndef _FBL_MAIN_H_
#define _FBL_MAIN_H_

/*______ I N C L U D E - F I L E S ___________________________________________*/
#include "fblm_config.h"
/*______ G L O B A L - D E F I N E S _________________________________________*/

/*______ G L O B A L - T Y P E S _____________________________________________*/

/*______ G L O B A L - D A T A _______________________________________________*/
extern uint8 FBLM_TimeoutResetCount;  /* Timeout reset flag */
/*______ G L O B A L - M A C R O S ___________________________________________*/

/*______ G L O B A L - F U N C T I O N S - P R O T O T Y P E S _______________*/
extern void FBLM_Main(void);

#endif /* _FBL_MAIN_H_ */
