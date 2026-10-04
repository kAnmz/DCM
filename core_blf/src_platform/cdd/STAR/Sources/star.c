/******************************************************************************/
/*@F_NAME:          star.c                                                    */
/*@F_PURPOSE:       Select application to launch                              */
/*@F_CREATED_BY:    Laura Tarini                                              */
/*@F_CREATION_DATE: 29/03/2002                                                */
/*@F_LANGUAGE :     ANSI C / Compiler-dependent                               */
/*@F_MPROC_TYPE:    MC9S12xx, NEC_V850, MC9S08xx, TX49,FSL IMX53,RENESAS RL78 */
/*                  IMX6x                                                     */
/************************************** (C) Copyright 2015 Magneti Marelli ****/


/* _____ I N C L U D E - F I L E S ___________________________________________*/

#include "syst.h"
#include "star.h"

#if defined(__TX49__)
#include "rgtx49_int.h"
#endif

#if defined(__RH850__)
#include "cpus.h"
#endif

#ifdef __CY_TV2__
#include "devm.h"
#endif
/* _____ G L O B A L - D E F I N E ___________________________________________*/


/* _____ L O C A L - D E F I N E _____________________________________________*/


/* _____ G L O B A L - T Y P E S _____________________________________________*/


/* _____ L O C A L - T Y P E S _______________________________________________*/


/* _____ G L O B A L - D A T A _______________________________________________*/


/* _____ P R I V A T E -  D A T A ____________________________________________*/


/* _____ L O C A L - D A T A _________________________________________________*/


/* _____ G L O B A L - M A C R O S ___________________________________________*/


/* _____ L O C A L - M A C R O S _____________________________________________*/


/* _____ P R I V A T E - F U N C T I O N S - P R O T O T Y P E S _____________*/

#if defined(C_COMP_GHS_ARM)
/* Suppress remark 1816: external declaration should be in header file. */
#pragma ghs nowarning 1816
#endif

#if defined(__CLIENT_EOL_LINK__) || defined(__BOOT_CLIENT_EOL_LINK__) || defined(__EOL_LINK__)
extern void Star_StartUpHookEol(void);
#endif /* defined(__CLIENT_EOL_LINK__) || defined(__BOOT_CLIENT_EOL_LINK__)  || defined(__EOL_LINK__) */

#if defined(__CLIENT_EOL_LINK__) || defined(__BOOT_CLIENT_EOL_LINK__) || defined(__CLIENT_LINK__)
extern void Star_StartUpHookClient(void);
#endif /* defined(__CLIENT_EOL_LINK__) || defined(__BOOT_CLIENT_EOL_LINK__)  || defined(__CLIENT_LINK__) */

#if defined(__BOOT_LOADER_FLASHER_LINK__) || defined(__FLASHER_LINK__)
extern void Star_StartUpHookFlasher(void);
#endif /* defined(__BOOT_LOADER_FLASHER_LINK__) || defined(__FLASHER_LINK__) */


#if !defined(__GHOS__)

#if defined(__CLIENT_LINK__) || defined(__EOL_LINK__) || defined(__CLIENT_EOL_LINK__)
  #ifdef __NEC_V850__
  extern void RGV850_Start(void);
  #endif /*__NEC_V850__ */

  #ifdef __MC9S12xx__
  extern __NON_BANKED__ void RG12_Start(void);
  #endif /*__MC9S12xx__ */

  #ifdef __MC9S08xx__
  extern __NON_BANKED__ void RG08_Start(void);
  #endif /*__MC9S08xx__ */

  #ifdef __TX49__
  extern void RGTX49_Start(void);
  #endif /* __TX49__ */

  #if defined(__FSL_IMX53x__)
  extern __INLINE__ void RGIMX53_Start(void);
  #endif /* __FSL_IMX53x__ */

  #if defined(__FSL_IMX6x__)
  extern __INLINE__ void RGIMX6_Start(void);
  #endif /* __FSL_IMX6x__*/

  #ifdef __REL_RL78__
  extern void RGRL78_Start(void);
  #endif /* __REL_RL78__ */

#endif /* defined(__CLIENT_LINK__) || defined(__EOL_LINK__) || defined(__CLIENT_EOL_LINK__) */

#endif /* !__GHOS__ */

#ifdef Star_START_OS_MEASUREMENT
extern void Star_StartOsBeginIndication(void);
extern void Star_StartOsEndIndication(void);
#endif

#if defined(C_COMP_GHS_ARM)
#pragma ghs endnowarning
#endif


/* _____ L O C A L - F U N C T I O N S - P R O T O T Y P E S _________________*/

#if defined(C_COMP_GHS_ARM)
/* Suppress remark 1816: external declaration should be in header file. */
#pragma ghs nowarning 1816
#endif

#if !defined(__GHOS__)

#if defined(__CLIENT_LINK__) || defined(__EOL_LINK__) || defined(__CLIENT_EOL_LINK__) || defined(__FLASHER_LINK__)
static __NEAR_FUNC__ void Star_PowerON_Reset(void);
#endif /* defined(__CLIENT_LINK__) || defined(__EOL_LINK__) || defined(__CLIENT_EOL_LINK__) || defined(__FLASHER_LINK__) */


/* there are no static functions because there are used from jumps and with   */
/* "static" and no call from source code, there are no code generation        */
/* => compiler optimisation                                                   */
__NON_BANKED__ void Star_EntryPointEol(void);
__NON_BANKED__ void Star_EntryPointClient(void);
__NON_BANKED__ void Star_EntryPointFlasher(void);

#endif /* !__GHOS__ */

#if defined(C_COMP_GHS_ARM)
#pragma ghs endnowarning
#endif


/* _____ G L O B A L - F U N C T I O N S _____________________________________*/

/******************************************************************************/
/* Name : StartupHook                                                         */
/* Role : Start Up application                                                */
/* Interface : -                                                              */
/* Pre-condition : -                                                          */
/* Constraints : hook service called by Init OSEK OS                          */
/* Behaviour :                                                                */
/*  DO                                                                        */
/*     [Get Ram Boot Key]                                                     */
/*     [Call StartUpHook_Client]                                              */
/*  OD                                                                        */
/******************************************************************************/
void StartupHook(void)
{
  #if defined (__REL_V850_Dx4__) || defined (__RH850_F1x__)

  #ifdef SYST_DATA_SAVE_IN_RESET
  SYST_BackupRam(SYST_BKP_RESTORE, SYST_BKP_SEC_BEFORE_INIT);
  #endif /* SYST_DATA_SAVE_IN_RESET */

  #ifdef SYST_DATA_SAVE_IN_DEEPSTOP
  SYST_BackupRam(SYST_BKP_RESTORE, SYST_BKP_SEC_SLEEP_BEFORE_INIT);
  #endif /* SYST_DATA_SAVE_IN_DEEPSTOP */

  #endif /* __REL_V850_Dx4__ */

#ifndef __CY_TV2__
  SYST_Init();  /* To be able to use SYST_GetBootKey / SYST_SetBootKey */


  #if defined(__CLIENT_EOL_LINK__) || defined(__BOOT_CLIENT_EOL_LINK__)
  switch (SYST_GetBootKey())
  {
  case SYST_EOL :
    /*SYST_SetBootKey(SYST_KEY_DEFAULT_VALUE, FALSE);*/
#ifdef SYST_UseEMMCRecoverLogic
    /*The values in backram are clear in eol mode*/
    SYST_SetSWResetCounter(0);
    SYST_SetEmmcRecoveryStrategyFlag(FALSE);
#endif
#ifdef SAFM_LimitSystemResetTimeLogic
    SYST_SetSWResetCounterTotal(0);
#endif
    Star_StartUpHookEol();
    break;

  case SYST_CLIENT:
    /*SYST_SetBootKey(SYST_KEY_DEFAULT_VALUE, FALSE);*/
    Star_StartUpHookClient();
    break;

  default:
    /*SYST_SetBootKey(SYST_KEY_DEFAULT_VALUE, FALSE);*/
    /* wait reset if whatchdog is activated */
    /*SYST_Reset();*/
    Star_StartUpHookClient();

    #if defined(__POLYSPACE__)     || \
        defined(__PC_SIMULATION__) || \
        defined(SYST_SPECIAL_RESET)
    break;
    #endif
  }
  #endif /* __CLIENT_EOL_LINK__ || __BOOT_CLIENT_EOL_LINK__*/

#else
#ifndef __CORE_CM0P__
  // Star_StartUpHookClient();
#endif /*__CORE_CM0P__*/
#endif /*__CY_TV2__*/
  #ifdef __CLIENT_LINK__
  (void)SYST_SetBootKey(SYST_KEY_DEFAULT_VALUE, FALSE);
  Star_StartUpHookClient();
  #endif /* _CLIENT_LINK__ */

  #ifdef __EOL_LINK__
  SYST_SetBootKey(SYST_KEY_DEFAULT_VALUE, FALSE);
  Star_StartUpHookEol();
  #endif /* __EOL_LINK__ */

  #if defined(__BOOT_LOADER_FLASHER_LINK__) || defined(__FLASHER_LINK__)
  SYST_SetBootKey(SYST_KEY_DEFAULT_VALUE, FALSE);
  Star_StartUpHookFlasher();
  #endif /* defined(__BOOT_LOADER_FLASHER_LINK__) || defined(__FLASHER_LINK__) */

  #if (defined(__REL_V850_Dx4__) || defined(__RH850_F1x__)) && defined(SYST_DATA_SAVE_IN_DEEPSTOP)
  SYST_BackupRam(SYST_BKP_RESTORE, SYST_BKP_SEC_SLEEP_AFTER_INIT);
  #endif /* __REL_V850_DX4__ && SYST_DATA_SAVE_IN_DEEPSTOP */

  #if defined(SYST_DX4_DEEPSTOP_USED)
  SYST_SLEEP_KEY_RAM = SYST_NO_SLEEP;
  #endif /* SYST_DX4_DEEPSTOP_USED */
}


/******************************************************************************/
/* Name : ShutdownHook                                                        */
/* Role : shut down OS                                                        */
/* Interface : -                                                              */
/* Pre-condition : -                                                          */
/* Constraints : hook service called by OSEK OS                               */
/* Behaviour :                                                                */
/*  DO                                                                        */
/*     [ ]                                                                    */
/*  OD                                                                        */
/******************************************************************************/
void ShutdownHook(StatusType error)
{
  /* NEVER USE, because we do not shutdow the OS but we freeze the system in */
  /* the WKSP task                                                           */

  error = error; /* to avoid warning*/
}


#if (!defined(__RTOS__)) && (!defined(__GHOS__))
/******************************************************************************/
/* Name : ErrorHook                                                           */
/* Role : shut down OS                                                        */
/* Interface : -                                                              */
/* Pre-condition : -                                                          */
/* Constraints : hook service called by OSEK OS                               */
/* Behaviour :                                                                */
/*  DO                                                                        */
/*     [ ]                                                                    */
/*  OD                                                                        */
/******************************************************************************/
#if 0
#if (STATUS_LEVEL == EXTENDED_STATUS) && !defined(osdSuppressFilenames)
void osqFunc ErrorHook (StatusType Error, uint16 uiError, char *pModule, int uiLine)
#else
void osqFunc ErrorHook (StatusType Error, uint16 uiError)
#endif /* (STATUS_LEVEL == EXTENDED_STATUS) && !defined(osdSuppressFilenames) */
{
  /* To avoid compiler warning */
  uiError = uiError;

  #if (STATUS_LEVEL == EXTENDED_STATUS) && !defined(osdSuppressFilenames)
  pModule = pModule;
  uiLine = uiLine;
  #endif /* (STATUS_LEVEL == EXTENDED_STATUS) && !defined(osdSuppressFilenames) */

  if (Error == E_OS_NOFUNC) ;
} /* END OF ErrorHook */
#else
#ifndef __BOOT_LINK__
#ifndef __CY_TV2__
void osqFunc1 ErrorHook (StatusType Error)
{
  /* To avoid compiler warning */
    Error = Error;

} /* END OF ErrorHook */
#endif
#endif
#endif
#endif /* !__RTOS__ && !__GHOS__ */


/******************************************************************************/
/* Name : STAR_main                                                           */
/* Role : Start OSEK operating system to start application                    */
/* Interface : -                                                              */
/* Pre-condition : -                                                          */
/* Constraints : In case of use of GHS Integrity, this routine must be set as */
/*               main original task in the integrate configuration file       */
/* Behaviour :                                                                */
/*  DO                                                                        */
/*     [StartOS]                                                              */
/*     [loop infinite (or Exit if GHS Integrity is used]                      */
/*  OD                                                                        */
/******************************************************************************/
__NON_BANKED__ void STAR_main(void)
{
#ifndef __CY_TV2__
  #ifdef Star_START_OS_MEASUREMENT
  /* Begin of Start OS indication for measurement */
  Star_StartOsBeginIndication();
  #endif

  #if !defined(__GHOS__)

  #if defined(__TX49__) && defined(C_COMP_GHS_TX49)
  RGTX49_InitInterrupt();
  #endif /* defined(__TX49__) && defined(C_COMP_GHS_TX49) */

  #if defined(__FSL_IMX53x__)
  RGIMX53_InitExceptionHandler();
  RGIMX53_InitMMU();
  RGIMX53_InitVFP();
  #endif /* __FSL_IMX53x__ */

  #if defined(__NEC_V850__) && defined(__REL_V850_Dx4__) && defined(C_COMP_GHS_V850)
	#ifdef osdVectorMicrosarISRTable
     RGV850_InitInterrupt();
	#endif
#endif

  #if defined(__FSL_IMX6x__)
  RGIMX6_InitExceptionHandler();
  RGIMX6_InitMMU();
  RGIMX6_InitVFP();
  #endif /* __FSL_IMX6x__ */

  #endif /* !__GHOS__ */

  /* Start OSEK OS */
   #ifndef FIAT_AUTOSAR_STACK
	#ifdef __OSEK__
      StartOS(OSDEFAULTAPPMODE);
	#else
      #ifdef __RTOS__
        StartOS(0);
      #endif
	#endif

    #ifdef VECTOR_FBL_PACKAGE
     /*FBL_main();*/
     Star_StartUpHookClient();
    #endif /* VECTOR_FBL_PACKAGE */

  #else
    #ifdef VECTOR_FBL_PACKAGE
     /*FBL_main();*/
     Star_StartUpHookClient();
    #else
     /* For Fiat Autosar architectures, StartOs() is invoked by FAS module EcuM */
     EcuM_Init();
    #endif /* VECTOR_FBL_PACKAGE */
  #endif

  #ifdef Star_START_OS_MEASUREMENT
  /* End of Start OS indication for measurement */
  Star_StartOsEndIndication();
  #endif

  #if !defined(__GHOS__)

  #ifndef __POLYSPACE__
  /* Wait until watchdog occurs */
  while(1);
  #endif /* __POLYSPACE__ */

  #else

  /* Main task (with higher priority) must be exited to let other tasks be executed */
  Exit(0);

  #endif /* !__GHOS__ */
#else  /*__CY_TV2__*/
  DEVM_main();
#endif /*__CY_TV2__*/
}


#if !defined(__GHOS__)

#if defined(C_COMP_GHS_TX49) || defined(C_COMP_GHS_ARM)
#pragma ghs section text=".startuptext"
#pragma ghs inlineprologue
#endif /* defined(C_COMP_GHS_TX49) || defined(C_COMP_GHS_ARM) */
/******************************************************************************/
/* Name : STAR_StartUpSystem                                                  */
/* Role : application entry point                                             */
/* Interface : -                                                              */
/* Pre-condition : -                                                          */
/* Constraints : This is the funcion called by Boot Code to start application */
/*               use boot stack                                               */
/* Behaviour :                                                                */
/*  DO                                                                        */
/*     [if Boot application, Call application main because                    */
/*      start-up initialisation already done in boot]                         */
/*     [if CLIENT or EOL application and not linked with Boot,                */
/*      call start-up routine]                                                */
/*  OD                                                                        */
/******************************************************************************/
__ROOT__ __NON_BANKED__ void STAR_StartUpSystem(void)
{
#if (defined(__BOOT_LOADER_FLASHER_LINK__) || defined(__BOOT_LOADER_LINK__) || defined(__BOOT_CLIENT_EOL_LINK__))
  STAR_main();
#else
  Star_PowerON_Reset();
#endif /* __BOOT_LOADER_FLASHER_LINK__ || __BOOT_LOADER_LINK__ || __BOOT_CLIENT_EOL_LINK__ */

  #ifdef __PC_SIMULATION__
  STAR_main();
  #endif /* __PC_SIMULATION__ */
}

#ifdef __CY_TV2__
/*----------------------------------------------------------------------------*/
/*Name : System main function Entry point                                     */
/*Role :                                                                      */
/*Interface :                                                                 */
/*  - IN  : none                                                              */
/*  - OUT : none                                                              */
/*Pre-condition :none                                                         */
/*Constraints   :none                                                         */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [Configure and wakeup system ]                                          */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
int main()
{
  STAR_StartUpSystem();
  return 0;  /* Fix for Polyspace check*/
}
#endif  /*__CY_TV2__*/
/*----------------------------------------------------------------------------*/
/* Function Name : void STAR_WakeUpFromDeepSleep( void )                             */
/* Description   : This function shifts to DEEPSTOP mode.                     */
/* Argument      : none                                                       */
/* Return Value  : none                                                       */
/*----------------------------------------------------------------------------*/
void STAR_WakeUpFromDeepSleep( void )
{
#ifdef __BOOT_LINK__
#if !defined(__CY_TV2__)
  /* Check RTC Alarm wake up flag */
  if ((TARG_ReadBitInLong(STBC_WUF0WUF0, BIT29)) || (TARG_ReadBitInLong(STBC_WUF0WUF0, BIT17)))
  {
#ifdef  SYST_DEEPSTOP_USED
    WKSS_CheckGotoSleep();
#endif

    /* if go to sleep, never run to this line, otherwise CL15 or body CAN
     * wake up happened. So we clear ALL other wake up factor flags and start.*/
    TARG_WriteLong(STBC_WUF0WUFC0, STAR_WUFCx_CLEARED);
  }
  else
  {
    /* Do Nothing */
  }
#endif
#endif
}

#if defined(C_COMP_GHS_TX49) || defined(C_COMP_GHS_ARM)
#pragma ghs section text=default
#pragma ghs noinlineprologue
#endif /* defined(C_COMP_GHS_TX49) || defined(C_COMP_GHS_ARM) */

#endif /* !__GHOS__ */


/* _____ L O C A L - F U N C T I O N S _______________________________________*/

#if !defined(__GHOS__)

#if defined(C_COMP_GHS_TX49) || defined(C_COMP_GHS_ARM)
/* all functions after this pragma use inline prologue to do not call library */
#pragma ghs inlineprologue
#endif /* defined(C_COMP_GHS_TX49) || defined(C_COMP_GHS_ARM) */


#if defined(__CLIENT_LINK__) || defined(__EOL_LINK__) || defined(__CLIENT_EOL_LINK__) || defined(__FLASHER_LINK__)

#if defined(C_COMP_GHS_TX49) || defined(C_COMP_GHS_ARM)
#pragma ghs section text=".startuptext"
#endif /* defined(C_COMP_GHS_TX49) || defined(C_COMP_GHS_ARM) */
/******************************************************************************/
/* Name : Star_PowerON_Reset                                                  */
/* Role : initialise sections                                                 */
/* Interface : -                                                              */
/* Pre-condition : -                                                          */
/* Constraints : use boot stack                                               */
/* Behaviour :                                                                */
/*  DO                                                                        */
/*     [according the processor, call the section initialisation routine)     */
/*     [switch to application stack pointer]                                  */
/*  OD                                                                        */
/******************************************************************************/
static __ROOT__ __NEAR_FUNC__ void Star_PowerON_Reset(void)
{
#ifndef __CY_TV2__
#ifdef __NEC_V850__
  /* re-set stack, initialize sections */
  #ifdef Star_CLEAR_STACK_VALUE
  /* reset stack */
  /* memset must not use stack for it own use */
  memset(STAR_Stack, Star_CLEAR_STACK_VALUE, STAR_STACK_SIZE);
  #endif /* #ifdef Star_CLEAR_STACK_VALUE */
  RGV850_Start();
#endif /* __NEC_V850__ */

#ifdef __RH850__
  RGRH850_Start();
#endif /* __NEC_V850__ */

#ifdef __TX49__
  RGTX49_Start();
#endif /* __TX49__ */

#ifdef __MC9S12xx__
  #ifdef __RTOS__
  /* re-set stack, initialize sections */
  RG12_Start();
  #else
  #error check if your OS provide section initialization
  #endif /* __RTOS__  */
#endif /* __MC9S12xx__ */

#ifdef __MC9S08xx__
  /* re-set stack, initialize sections */
  RG08_Start();
#endif /* __MC9S08xx__ */

#if defined(__FSL_IMX53x__)
  RGIMX53_Start();
#endif /* __FSL_IMX53x__ */

#if defined(__FSL_IMX6x__)
  RGIMX6_Start();
#endif /* __FSL_IMX6x__ */

#ifdef __REL_RL78__
  RGRL78_Start();
#endif /* __REL_RL78__ */

#else  /*__CY_TV2__*/

#if defined(__CLIENT_LINK__) || defined(__EOL_LINK__) || defined(__CLIENT_EOL_LINK__)
  /* application entry */
  STAR_main();
#endif /* defined(__CLIENT_LINK__) || defined(__EOL_LINK__) || defined(__CLIENT_EOL_LINK__) */
#endif  /*__CY_TV2__*/

}
#if defined(C_COMP_GHS_TX49) || defined(C_COMP_GHS_ARM)
#pragma ghs section text=default
#endif /* defined(C_COMP_GHS_TX49) || defined(C_COMP_GHS_ARM) */

#endif /* defined(__CLIENT_LINK__) || defined(__EOL_LINK__) || defined(__CLIENT_EOL_LINK__) || defined(__FLASHER_LINK__) */


#if defined(__CLIENT_EOL_LINK__) || defined(__EOL_LINK__)

#if defined(C_COMP_GHS_TX49) || defined(C_COMP_GHS_V850) || defined(C_COMP_GHS_ARM)
#pragma ghs section text=".eolentrytext"
#endif /* defined(C_COMP_GHS_TX49) || defined(C_COMP_GHS_V850) || defined(C_COMP_GHS_ARM) */

#if defined(C_COMP_COSMIC_MC9S12) || defined(C_COMP_COSMIC_MC9S08)
#pragma section @near (EOL_ENTRY)
#endif /* C_COMP_COSMIC_MC9S12 || C_COMP_COSMIC_MC9S08 */

#if defined(C_COMP_IAR_RL78)
#pragma location="eolentrytext"
#endif  /* C_COMP_IAR_RL78 */

/******************************************************************************/
/* Name : Star_EntryPointEol                                                  */
/* Role : fixed entry point of EOL application                                */
/* Interface : -                                                              */
/* Pre-condition : -                                                          */
/* Constraints : use boot stack                                               */
/* Behaviour :                                                                */
/*  DO                                                                        */
/*     [Call STAR_StartUpSystem]                                              */
/*  OD                                                                        */
/* CAUTION :                                                                  */
/* there are no static functions because there are used from jumps and with   */
/* "static" and no call from source code, there are no code generation        */
/* => compiler optimisation                                                   */
/******************************************************************************/
__ROOT__ __NON_BANKED__ void Star_EntryPointEol(void)
{
  STAR_StartUpSystem();
}

#if defined(C_COMP_GHS_TX49) || defined(C_COMP_GHS_V850) || defined(C_COMP_GHS_ARM)
#pragma ghs section text=default
#endif /* defined(C_COMP_GHS_TX49) || defined(C_COMP_GHS_V850) || defined(C_COMP_GHS_ARM) */

#if defined(C_COMP_COSMIC_MC9S12) || defined(C_COMP_COSMIC_MC9S08)
#pragma section ()
#endif /* C_COMP_COSMIC_MC9S12 || C_COMP_COSMIC_MC9S08 */

#endif /* defined(__CLIENT_EOL_LINK__) || defined(__EOL_LINK__) */


#if defined(__CLIENT_EOL_LINK__) || defined(__CLIENT_LINK__)

#if defined(C_COMP_GHS_TX49) || defined(C_COMP_GHS_V850) || defined(C_COMP_GHS_ARM)
#pragma ghs section text=".cliententrytext"
#endif /* defined(C_COMP_GHS_TX49) || defined(C_COMP_GHS_V850) || defined(C_COMP_GHS_ARM) */

#if defined(C_COMP_COSMIC_MC9S12) || defined(C_COMP_COSMIC_MC9S08)
#pragma section @near (CLIENT_ENTRY)
#endif /* C_COMP_COSMIC_MC9S12 || C_COMP_COSMIC_MC9S08 */

#if defined(C_COMP_IAR_RL78)
#pragma location="cliententrytext"
#endif  /* C_COMP_IAR_RL78 */

/******************************************************************************/
/* Name : Star_EntryPointClient                                               */
/* Role : fixed entry point of CLIENT application                             */
/* Interface : -                                                              */
/* Pre-condition : -                                                          */
/* Constraints : use boot stack                                               */
/* Behaviour :                                                                */
/*  DO                                                                        */
/*     [Call STAR_StartUpSystem]                                              */
/*  OD                                                                        */
/* CAUTION :                                                                  */
/* there are no static functions because there are used from jumps and with   */
/* "static" and no call from source code, there are no code generation        */
/* => compiler optimisation                                                   */
/******************************************************************************/
__ROOT__ __NON_BANKED__ void Star_EntryPointClient(void)
{
  STAR_StartUpSystem();
}

#if defined(C_COMP_GHS_TX49) || defined(C_COMP_GHS_V850) || defined(C_COMP_GHS_ARM)
#pragma ghs section text=default
#endif /* defined(C_COMP_GHS_TX49) || defined(C_COMP_GHS_V850) || defined(C_COMP_GHS_ARM) */

#if defined(C_COMP_COSMIC_MC9S12) || defined(C_COMP_COSMIC_MC9S08)
#pragma section ()
#endif /* C_COMP_COSMIC_MC9S12 || C_COMP_COSMIC_MC9S08 */

#endif /* defined(__CLIENT_EOL_LINK__) defined(__CLIENT_LINK__) */


#if defined(__FLASHER_LINK__)

#if defined(C_COMP_GHS_TX49) || defined(C_COMP_GHS_V850) || defined(C_COMP_GHS_ARM)
#pragma ghs section text=".flasherentrytext"
#endif /* defined(C_COMP_GHS_TX49) || defined(C_COMP_GHS_V850) || defined(C_COMP_GHS_ARM) */

#if defined(C_COMP_COSMIC_MC9S12) || defined(C_COMP_COSMIC_MC9S08)
#pragma section @near (FLASHER_ENTRY)
#endif /* C_COMP_COSMIC_MC9S12 || C_COMP_COSMIC_MC9S08 */

#if defined(C_COMP_IAR_RL78)
#pragma location="flasherentrytext"
#endif  /* C_COMP_IAR_RL78 */

/******************************************************************************/
/* Name : Star_EntryPointFlasher                                              */
/* Role : fixed entry point of FLASHER application                            */
/* Interface : -                                                              */
/* Pre-condition : -                                                          */
/* Constraints : use boot stack                                               */
/* Behaviour :                                                                */
/*  DO                                                                        */
/*     [Call STAR_StartUpSystem]                                              */
/*  OD                                                                        */
/* CAUTION :                                                                  */
/* there are no static functions because there are used from jumps and with   */
/* "static" and no call from source code, there are no code generation        */
/* => compiler optimisation                                                   */
/******************************************************************************/
__ROOT__ __NON_BANKED__ void Star_EntryPointFlasher(void)
{
  STAR_StartUpSystem();
}

#if defined(C_COMP_GHS_TX49) || defined(C_COMP_GHS_V850) || defined(C_COMP_GHS_ARM)
#pragma ghs section text=default
#endif /* defined(C_COMP_GHS_TX49) || defined(C_COMP_GHS_V850) || defined(C_COMP_GHS_ARM) */

#if defined(C_COMP_COSMIC_MC9S12) || defined(C_COMP_COSMIC_MC9S08)
#pragma section ()
#endif /* C_COMP_COSMIC_MC9S12 || C_COMP_COSMIC_MC9S08 */

#endif /* __FLASHER_LINK__ */

#if defined(C_COMP_GHS_TX49) || defined(C_COMP_GHS_ARM)
#pragma ghs noinlineprologue
#endif /* defined(C_COMP_GHS_TX49) || defined(C_COMP_GHS_ARM) */

#endif /* !__GHOS__ */


/* _____ E N D _____ (star.c) ________________________________________________*/
