/******************************************************************************/
/* @F_NAME :          mcwdt_config.h                                          */
/* @F_PURPOSE :       manage watch dog                                        */
/* @F_CREATED_BY :    Jianhua.Wu  			                                  */
/* @F_CREATION_DATE : 2021.07.14                                              */
/* @F_LANGUAGE :      ANSI C                                                  */
/* @F_MPROC_TYPE :    target independent           						      */
/*************************************** (C) Copyright 2021 Marelli ***********/

#ifndef _MCWDT_CONFIG_H_
#define _MCWDT_CONFIG_H_

/*______ I N C L U D E - F I L E S ___________________________________________*/

/*______ G L O B A L - D E F I N E S _________________________________________*/

/*______ G L O B A L - T Y P E S _____________________________________________*/

/*______ G L O B A L - D A T A _______________________________________________*/

/*______ G L O B A L - M A C R O S ___________________________________________*/

/*______ G L O B A L - F U N C T I O N S - P R O T O T Y P E S _______________*/
extern void Fblm_WDInit(void);
extern void Fblm_WDRefresh(void);
extern void Fblm_WDDisable(void);
#endif /* _MCWDT_CONFIG_H_*/
