/******************************************************************************/
/* @F_NAME :          timer_config.h                                          */
/* @F_PURPOSE :       Setup a timer for FBL                                   */
/* @F_CREATED_BY :    Jianhua                               				  */
/* @F_CREATION_DATE : 6/26/2021                                       		  */
/* @F_LANGUAGE :      C                                      				  */
/* @F_MPROC_TYPE :    Traveo II               								  */
/*************************************** (C) Copyright 2021  Marelli **********/

#ifndef TIMER_CONFIG_H_
#define TIMER_CONFIG_H_

/*______ I N C L U D E - F I L E S ___________________________________________*/
#include "type.h"
/*______ G L O B A L - D E F I N E S _________________________________________*/

/*______ G L O B A L - T Y P E S _____________________________________________*/

/*______ G L O B A L - D A T A _______________________________________________*/

/*______ G L O B A L - M A C R O S ___________________________________________*/

/*______ G L O B A L - F U N C T I O N S - P R O T O T Y P E S _______________*/
extern void TIMD_TimerInit(void);
extern void TIMD_Timer1Init(void);
extern bool_t TIMD_TimerGet(void);
#endif /* TIMER_CONFIG_H_ */
