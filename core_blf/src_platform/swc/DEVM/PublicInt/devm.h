/******************************************************************************/
/*@F_NAME:           xxxx.h                                                   */
/*@F_PURPOSE:        Public interface for XXXX module                         */
/*@F_CREATED_BY:     Yanbin SHEN                                              */
/*@F_CREATION_DATE:  Jun/22/2020                                              */
/*@F_LANGUAGE :      ANSI C or ASM-CompilerName (to choose)                   */
/*@F_MPROC_TYPE:     Target Name or Processor independent (to choose)         */
/************************************** (C) Copyright 2020 Magneti Marelli ****/
#ifndef __DEVM_H__
#define __DEVM_H__

/*______ I N C L U D E - F I L E S ___________________________________________*/
#ifndef __CORE_CM0P__
#include "syst.h"
#endif
/*______ G L O B A L - D E F I N E S _________________________________________*/


/*______ G L O B A L - T Y P E S _____________________________________________*/


/*______ G L O B A L - M A C R O S ___________________________________________*/


/*______ G L O B A L - F U N C T I O N S - P R O T O T Y P E S _______________*/

#ifdef __CORE_CM0P__
extern int DEVM_main(void);
#else
extern int DEVM_main(void);
#endif

/******************************************************************************
* Name         :  Devm_Init
* Called by    :  DEVM_TASK_ts()
* Preconditions:  None
* Parameters   :  None
* Return code  :  None
* Description  :  This function is called for DEVM  initiation
******************************************************************************/
extern void Devm_Init(void);

#endif /* __DEVM_H__ */

/*______ E N D _____ (xxxx.h) ________________________________________________*/
