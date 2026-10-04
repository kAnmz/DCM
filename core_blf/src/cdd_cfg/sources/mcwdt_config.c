/******************************************************************************/
/* @F_NAME :          mcwdt_config.c                                          */
/* @F_PURPOSE :       manage watch dog                                        */
/* @F_CREATED_BY :    Jianhua.Wu  			                                  */
/* @F_CREATION_DATE : 2021.07.14                                              */
/* @F_LANGUAGE :      ANSI C                                                  */
/* @F_MPROC_TYPE :    target independent           						      */
/*************************************** (C) Copyright 2021 Marelli ***********/

/*______ I N C L U D E - F I L E S ___________________________________________*/
#include "cy_project.h"
#include "cy_device_headers.h"
#include "fbl_cfg.h"
#include "mcwdt_config.h"
/*______ L O C A L - D E F I N E S ___________________________________________*/

/*______ L O C A L - T Y P E S _______________________________________________*/

/*______ G L O B A L - D A T A _______________________________________________*/

/*______ P R I V A T E - D A T A _____________________________________________*/
cy_stc_mcwdt_config_t const My_mcwdtConfig =
{
/************************Counter 0*********************************/
	.c0LowerLimit     = 0,
	.c0UpperLimit     = 100, /* 1sec when clk_lf = 32KHz */
	.c0WarnLimit      = 0,
	.c0LowerAction    = CY_MCWDT_ACTION_NONE,
	.c0UpperAction    = CY_MCWDT_ACTION_NONE, /* Note */
	.c0WarnAction     = CY_MCWDT_WARN_ACTION_NONE,
	.c0AutoService    = CY_MCWDT_DISABLE,
	.c0SleepDeepPause = CY_MCWDT_ENABLE,
	.c0DebugRun       = CY_MCWDT_ENABLE,
/************************Counter 1*********************************/
	.c1LowerLimit     = 0,			/*see in AN219944*/
	.c1UpperLimit     = 60000,      /*2sec when clk_lf = 32.768 KHz*/
	.c1WarnLimit      = 0,
	.c1LowerAction    = CY_MCWDT_ACTION_NONE,
	.c1UpperAction    = CY_MCWDT_ACTION_FAULT_THEN_RESET,
	.c1WarnAction     = CY_MCWDT_WARN_ACTION_NONE,
	.c1AutoService    = CY_MCWDT_DISABLE,
	.c1SleepDeepPause = CY_MCWDT_ENABLE,
	.c1DebugRun       = CY_MCWDT_ENABLE,
/************************Counter 2*********************************/
	.c2ToggleBit      = CY_MCWDT_CNT2_MONITORED_BIT15,
	.c2Action         = CY_MCWDT_CNT2_ACTION_NONE,
	.c2SleepDeepPause = CY_MCWDT_ENABLE,
	.c2DebugRun       = CY_MCWDT_ENABLE,
/************************core select*********************************/
	.coreSelect       = CY_MCWDT_PAUSED_BY_DPSLP_CM0,
};
/*______ L O C A L - D A T A _________________________________________________*/

/*______ L O C A L - M A C R O S _____________________________________________*/

/*______ I M P O R T - F U N C T I O N S - P R O T O T Y P E S _______________*/

/*______ L O C A L - F U N C T I O N S - P R O T O T Y P E S _________________*/

/*______ G L O B A L - F U N C T I O N S _____________________________________*/
/*----------------------------------------------------------------------------*/
/*Name : Fblm_WDInit    			                                          */
/*Role : Initialize watch dog					 						      */
/*Interface :                                                                 */
/*  - IN  : none	                                                          */
/*  - OUT : none  							                                  */
/*Pre-condition : none			                                              */
/*Constraints   : none             			                                  */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [initialize parameters and main loop]                                   */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
void Fblm_WDInit(void)
{
#if defined( FBL_WATCHDOG_ON )
	Cy_MCWDT_DeInit(MCWDT0);
	Cy_MCWDT_Init(MCWDT0, &My_mcwdtConfig);
	Cy_MCWDT_Unlock(MCWDT0);
    Cy_MCWDT_Enable(MCWDT0,CY_MCWDT_CTR_Msk,0);
	Cy_MCWDT_Lock(MCWDT0);
	Fblm_WDRefresh();
#endif
}

/*----------------------------------------------------------------------------*/
/*Name : Fblm_WDRefresh    			                                          */
/*Role : Refresh watch dog					 		     				      */
/*Interface :                                                                 */
/*  - IN  : none	                                                          */
/*  - OUT : none  							                                  */
/*Pre-condition : none			                                              */
/*Constraints   : none             			                                  */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [initialize parameters and main loop]                                   */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
void Fblm_WDRefresh(void)
{
#if defined( FBL_WATCHDOG_ON )
	  Cy_MCWDT_ClearWatchdog(MCWDT0, CY_MCWDT_COUNTER1);
	  Cy_MCWDT_WaitForCounterReset(MCWDT0, CY_MCWDT_COUNTER1);
#endif
}

/*----------------------------------------------------------------------------*/
/*Name : Fblm_WDDisable    			                                          */
/*Role : Disable watch dog					 		     				      */
/*Interface :                                                                 */
/*  - IN  : none	                                                          */
/*  - OUT : none  							                                  */
/*Pre-condition : none			                                              */
/*Constraints   : none             			                                  */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [initialize parameters and main loop]                                   */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
void Fblm_WDDisable(void)
{
#if defined( FBL_WATCHDOG_ON )
	Cy_MCWDT_Unlock(MCWDT0);
	Cy_MCWDT_Disable(MCWDT0,CY_MCWDT_CTR_Msk,0);
	Cy_MCWDT_Lock(MCWDT0);
	Cy_MCWDT_DeInit(MCWDT0);
#endif
}

/*______ P R I V A T E - F U N C T I O N S ___________________________________*/

/*______ L O C A L - F U N C T I O N S _______________________________________*/

/*______ E N D _____ (FileName.c) ____________________________________________*/
