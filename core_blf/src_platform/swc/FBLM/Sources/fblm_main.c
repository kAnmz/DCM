/******************************************************************************/
/* @F_NAME :          fblm_main.c                                             */
/* @F_PURPOSE :       manage reprogramming for MCU                            */
/* @F_CREATED_BY :    Jianhua.Wu  			                                  */
/* @F_CREATION_DATE : 2021.07.14                                              */
/* @F_LANGUAGE :      ANSI C                                                  */
/* @F_MPROC_TYPE :    target independent           						      */
/*************************************** (C) Copyright 2021 Marelli ***********/

/*______ I N C L U D E - F I L E S ___________________________________________*/
#include "fblm_diag.h"
#include "fblm_main.h"
#include "fblm_priv.h"
#include "tpmc.h"
#if defined(EEPC_FUN_ENABLE)
#include "eepc.h"
#include "eeps_config.h"
#endif
#include "MemAcc.h"
#include "Fee_30_FlexNor.h"
#include "NvM.h"
#include "NvM_Cfg.h"
#include "nvmm_config.h"
#include "cy_flash.h"
#include "cy_mw_flash.h"
#include "SbcM.h"
#include "wdfs_config_dynamic.h"
//#include "rsam.h"
/*______ L O C A L - D E F I N E S ___________________________________________*/
/* Macros for jumps */
#define APPL_SEG             M0AppHeader.Start
#define FBLM_10MS_PERIOD     10
#define FBLM_5MS_PERIOD      5
#define FBLM_1MS_PERIOD      1
#define FBLM_2MS_PERIOD      2

#define MCUHW_SWRESET_TRIGGERT_MASK  (0x00000010ul)
#define MCU_RESET_REASON             (*((volatile uint32 *)(0x40261800ul)))

#define BootCommand  (*((uint32*)0x0801F200)) /*in RRAM*/
#define FBLM_Command_ToAPP  ((uint32) 0x00000000)
#define FBLM_Command_ToBoot  ((uint32) 0xA5A5A5A5)

#define DEMCR      (*(volatile uint32_t *)0xE000EDFC)
#define DWT_CTRL   (*(volatile uint32_t *)0xE0001000)
#define DWT_CYCCNT (*(volatile uint32_t *)0xE0001004)
#define DWT_LAR    (*(volatile uint32_t *)0xE0001FB0)
/*______ L O C A L - T Y P E S _______________________________________________*/

/*______ G L O B A L - D A T A _______________________________________________*/
ubyte fblMode = 0x00u;		/*Mode for staying in Bootloader*/
FBLM_UpdateMode_t Fblm_UpdateMode = UPDATE_MODE_CAN;
ubyte WDInitFlag = 0u;     /* Watchdog initialized flag */
SYST_ResetType_t mcuResetType = SYST_RESET_UNKNOW;
ubyte Fblm_TaskPeriodCnt = 0;
ubyte Fblm_20MsTaskPeriodCnt = 0;
ubyte Fblm_TimerCouter = 0;
ubyte Fblm_BootMangerRunningSts = FALSE;
ubyte Fblm_BmNeedToJumpApp = TRUE;
uint8 FBLM_TimeoutResetCount = 0;          /* Timeout reset flag */
boolean FblInitDone = FALSE;
extern ushort DiagResetTimerCounter;
extern uint8 _SBCMDRV_RAM_data_START[];
extern uint8 _SBCMDRV_RAM_data_LIMIT[];
extern uint8 _SBCMDRV_data_ROM_START[];
extern uint8 _SBCMDRV_data_ROM_LIMIT[];
/*______ P R I V A T E - D A T A _____________________________________________*/

/*______ L O C A L - D A T A _________________________________________________*/
static ubyte Diag_RunCounter = 0u;
static ubyte Fblm_ReponseDoneFlag = FALSE;
static ulong Fblm_BootMangerRunningTimer = 0u;
static ulong Fblm_BootMangerRunning2msTimer = 0u;


#if defined(IMC_FUN_ENABLE)
static ubyte IMC_RunCounter = 0u;
#endif
/*______ L O C A L - M A C R O S _____________________________________________*/

/*______ I M P O R T - F U N C T I O N S - P R O T O T Y P E S _______________*/
void Fblm_ReponseDiagnosticSessionControlFromApp(void);
void Fblm_InitTesterTimeoutFromApp(void);
void Fblm_BootManger(void);
void Fblm_SBCMDRV_Init(void);
void DWT_Init(void);
extern boolean Sbcc_WatchdogMonitorFLASH(void);
/*______ L O C A L - F U N C T I O N S - P R O T O T Y P E S _________________*/

/*______ G L O B A L - F U N C T I O N S _____________________________________*/

/*----------------------------------------------------------------------------*/
/*Name : FBLM_Main 			                                                  */
/*Role : manage main logic of flash bootloader                                */
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
void FBLM_Main(void)
{

	/*SROM API needs interrupt*/
	EnableAllInterrupts();
#if defined SYST_RESET_INFO
	mcuResetType = SYST_GetResetType();
#endif
    /*Clear watchdog initialized flag*/
    ClrWDInit();

    Fblm_SBCMDRV_Init();
    DWT_Init(); 
    /*Init fblMode*/
    ResetFblMode();
    /*Treat as from reset*/
    SetFblMode(START_FROM_RESET);
    if(!(MCU_RESET_REASON & MCUHW_SWRESET_TRIGGERT_MASK))
    {
      SBCM_initWDMsg();
    }
    /*Preinitialization step,for example,whatever stay in bootloader or jump to app,must provide flash access right*/
    Fblm_PreInit();
    Fblm_OtherModuleInit();/*Init CAN IODC NVM DIAG Module*/
    Fblm_BootManger();
    Fblm_ReadNvMIdBeforeJump();

    if ((BootCommand != FBLM_Command_ToBoot) && \
    	(Fblm_AllProgramStatusVaild == Fblm_GetProgramStatusInfo())
    	&& (TRUE == Fblm_BmNeedToJumpApp))
    {
       /*Firstly need to judge whether NVM ID ProgramStatusInfo is vaild or not.
        *aim to prevent from being fail to read */
      if((FblApplValid == Fblm_IsApplicationValid()))
      {
        /*Jump to APP,will not run the code after here*/
        /* -- Start application code -- */
        /*swith cpu clock to emclk ?*/
        DisableAllInterrupts();
        CAND_DeInit();/*DeInit CAN driver before jumping to APP*/
#if defined( FBL_WATCHDOG_ON )
    	Fblm_WDDisable();
#endif
        JUMP_TO_APPLICATION();
      }
      else
      {
        /*check that the Endflag is inValid , should enter bootloader*/
      }
    }
    else
    {
      if(BootCommand == FBLM_Command_ToBoot)
      {
        BootCommand = FBLM_Command_ToAPP;
        SetFblMode(START_FROM_APPL);
      }
    }

    // Fblm_SysEnableApplCore();
    /*Execute FBL function after here*/
	  Fblm_ReadAll();
    Fblm_Init();
    Fblm_ASyncWriteQueueInit();

    while(1)
    {
    	if (FBLM_TM_TRIGGERED == Fblm_LookForWatchdog())
    	{
          /*100 us*/
          TpTask();/*Receive UDS cmd from CAN*/

    	  if (Fblm_TimerCouter < Fblm_TriggerCounterFactor)
    	  {
    	    Fblm_TimerCouter ++;
    	  }
    	  else
    	  {

    	  }
    	  if(Fblm_TriggerCounterFactor == Fblm_TimerCouter)  /*1ms*/
    	  {
    	    Fblm_TimerCouter = 0;
#if defined(IMC_FUN_ENABLE)
        if (IMC_RunCounter < FBLM_IMCTASK_PERIOD)
        {
          IMC_RunCounter ++;
        }
        else
        {
          /*Do nothing*/
        }
        if(UPDATE_MODE_OTA == Fblm_GetUpdateMode())
        {
            if (IMC_RunCounter >= FBLM_IMCTASK_PERIOD)
            {
            //if (TRUE == Fblm_IsIMCTaskNextRun())
            {
              IMC_RunCounter = 0u;
            /*  IMC_DLA_TaskRun();*/
            }
            }
            else
            {
              /*do nothing*/
            }
        }
#endif
        Fblm_20MsTaskPeriodCnt++;
        if((TRUE == SBCM_InitSbcFlag) && (FALSE == Fblm_ReponseDoneFlag))
        {
          /*Waiting for SBC CAN Enable */
          /*Fblm_ReponseDiagnosticSessionControlFromApp();*/ /* response $50 02 on App mode */
          Fblm_ReponseDoneFlag = TRUE;
        }
        if(FBLM_1MS_PERIOD == Fblm_20MsTaskPeriodCnt)
        {
          SBCM_BRsHwSbcInit();/*enable Sbc*/
          Fblm_20MsTaskPeriodCnt = 0;
        }

       if (Diag_RunCounter < FBLM_DIAGTASK_PERIOD)
       {
        Diag_RunCounter ++;
        if (FBLM_DIAGTASK_PERIOD == Diag_RunCounter)
        {
          Diag_RunCounter = 0u;
#if defined(IMC_FUN_ENABLE)
          if(UPDATE_MODE_OTA == Fblm_GetUpdateMode())
          {
            /*Fblm_IMCRxTask();*//*Receive UDS cmd from OTA*/
          }
          else
#endif
          {
           // TpTask();/*Receive UDS cmd from CAN*/
          }
          /*Call diagnosis layer cyclic function*/
          Fblm_DiagTask();
        }
       }
       else
       {
         Diag_RunCounter = 0u;
       }

#if defined(IMC_FUN_ENABLE)
       /*Active reset when OTA*/
     /*1ms run one time*/
     if (DiagResetTimerCounter > 0u)
     {
       DiagResetTimerCounter --;
       if (0u == DiagResetTimerCounter)
       {
       /* Stop timer to avoid a timer interrupt after application start */
       Fblm_TimerStop();
       /* Call reset application call-back */
       Fblm_Reset();
       }
     }
#endif
     Fblm_TaskPeriodCnt++;
     switch(Fblm_TaskPeriodCnt)
     {
       case FBLM_5MS_PERIOD:
         /* GEFDCM-180 After receiving the reset flag, time is counted. */
         if(TRUE == Fblm_GetRequestForReset())
         {
          FBLM_TimeoutResetCount ++;
         }
         if((TRUE == Fblm_SyncReqForRunningNvmFeeFlsTask) || (TRUE == Fblm_AsyncReqForRunningNvmFeeFlsTask)) /*to quickly wirte done in 5ms*/
         {
      	  /*When it not have write/read request,we  close nvm fee fls task to have
      	  * full time to receive data and advoid fls module.*/
           MemAcc_MainFunction();
           Fee_30_FlexNor_MainFunction();
           NvM_MainFunction();
         }
         Fblm_TaskPeriodCnt = 0;
         break;
       case FBLM_10MS_PERIOD:

         break;
     }

    	  }

    	}/*end of 1ms*/
    	Fblm_ManageResetAction();
#if defined(IMC_FUN_ENABLE)
    	if(UPDATE_MODE_OTA == Fblm_GetUpdateMode())
    	{
        	Fblm_SPIRunnable();
    	}
    	else
#endif
    	{
    	  /* Fblm_SPIRunnable(); */ /*Used to control Sbc*/
          Fblm_CANRunnable();
    	}


    }/*end of while(1)*/

}/*end of FBLM_Main*/


/*______ P R I V A T E - F U N C T I O N S ___________________________________*/
/*----------------------------------------------------------------------------*/
/*Name : Fblm_BootManger       			                                      */
/*Role : BootManger 				                                          */
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
void Fblm_BmInit(void)
{
  Fblm_BootMangerRunningSts = TRUE;
  Fblm_BmNeedToJumpApp = TRUE;
  Fblm_TimerCouter = 0;
}

void Fblm_SBCMDRV_Init(void)
{
  volatile uint32 *memPtr;
	volatile uint32 *romPtr; 
	volatile uint32 *memEndPtr;
	uint32 Fblm_SBCMDRVRamStartAddress = (uint32)_SBCMDRV_RAM_data_START;
	uint32 Fblm_SBCMDRVRamEndAddress = (uint32)_SBCMDRV_RAM_data_LIMIT;
	uint32 Fblm_SBCMDRVRomStartAddress = (uint32)_SBCMDRV_data_ROM_START;
	if(((Fblm_SBCMDRVRamEndAddress - Fblm_SBCMDRVRamStartAddress) > 0))
	{
		memPtr = (volatile uint32*)Fblm_SBCMDRVRamStartAddress;
		romPtr = (volatile uint32*)Fblm_SBCMDRVRomStartAddress;
		memEndPtr = (volatile uint32*)Fblm_SBCMDRVRamEndAddress;
		while ((uint32)memPtr < (uint32)memEndPtr)
		{
			*memPtr = *romPtr; 
			memPtr++;
			romPtr++;
		}
	}
}

void DWT_Init(void)
{
    DEMCR |= (1UL << 24);
    DWT_LAR = 0xC5ACCE55;
    DWT_CYCCNT = 0;
    DWT_CTRL |= 1UL;
}
/*----------------------------------------------------------------------------*/
/*Name : Fblm_BootManger       			                                      */
/*Role : BootManger 				                                          */
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
void Fblm_BootManger(void)
{
  Fblm_DiagInit(); /*Init diag function*/
  Fblm_BmInit();

  while(1)
  {
    if (FBLM_TM_TRIGGERED == Fblm_LookForWatchdog())
    {
      /*100 us*/
      TpTask();/*Receive UDS cmd from CAN*/

      if (Fblm_TimerCouter < Fblm_TriggerCounterFactor)
      {
        Fblm_TimerCouter ++;
      }
      else
      {

      }
      if(Fblm_TriggerCounterFactor == Fblm_TimerCouter)  /*1ms*/
      {
        Fblm_TimerCouter = 0;
        Fblm_BootMangerRunningTimer++;
        Fblm_BootMangerRunning2msTimer++;
        Fblm_DiagTask();/*1ms*/
      }
      if(FBLM_2MS_PERIOD == Fblm_BootMangerRunning2msTimer)
      {
    	Fblm_BootMangerRunning2msTimer = 0;
    	SBCM_BMInitBRsHwSbc();/*enable Sbc*/
      }
      if(Fblm_BootMangerRunningTimer == FBLM_10MS_PERIOD) /*Stay on BM function during watch time :10ms*/
      {
        Fblm_BootMangerRunningSts = FALSE;
        break;
      }
    }
    Fblm_CANRunnable();
   /* Fblm_SPIRunnable(); */
  }
}

/*----------------------------------------------------------------------------*/
/*Name : Fblm_ReponseDiagnosticSessionControlFromApp       			              */
/*Role : Initialize parameters and hardware/application module				        */
/*Interface :                                                                 */
/*  - IN  : none	                                                            */
/*  - OUT : none  							                                              */
/*Pre-condition : none			                                                  */
/*Constraints   : none             			                                      */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [initialize parameters and main loop]                                   */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
void Fblm_ReponseDiagnosticSessionControlFromApp(void)
{
  if (UPDATE_MODE_CAN == Fblm_GetUpdateMode())
  {
  	if (START_FROM_APPL ==  GetFblMode())
  	{
  	      /* FBL started from application */
  	      /* Prepare diagnostic buffer and states to response $10 $02*/
  	      FblDiagInitStartFromAppl();

  	      /* Handle diagnostic service request */
  	      Fblm_DiagDiagnosticSessionControl();

  	      /* Check for NRC */
  	      if (DiagGetError() != kDiagErrorNone)
  	      {
  	         DiagResponseProcessor(0);
  	      }
  	}
  }
}

/*----------------------------------------------------------------------------*/
/*Name : Fblm_InitTesterTimeoutFromApp                    			              */
/*Role : Initialize Tester present timer                      				        */
/*Interface :                                                                 */
/*  - IN  : none	                                                            */
/*  - OUT : none  							                                              */
/*Pre-condition : none			                                                  */
/*Constraints   : none             			                                      */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [initialize parameters and main loop]                                   */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
void Fblm_InitTesterTimeoutFromApp(void)
{
  if (UPDATE_MODE_CAN == Fblm_GetUpdateMode())
  {
  	if (START_FROM_APPL == GetFblMode())
  	{
      ResetTesterTimeout();
  	}
  }
}

/*----------------------------------------------------------------------------*/
/*Name : Fblm_Init       			                                          */
/*Role : Initialize parameters and hardware/application module				  */
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
void Fblm_Init(void)
{
  Fblm_TimerCouter = 0u;
  Diag_RunCounter = 0u;
  Fblm_SyncReqForRunningNvmFeeFlsTask = FALSE;
  Fblm_AsyncReqForRunningNvmFeeFlsTask = FALSE;
#if defined(IMC_FUN_ENABLE)
	IMC_RunCounter = 0u;
#endif
  Fblm_InitTesterTimeoutFromApp(); 
  /* GEFDCM-379	Set flag bit after boot initialization. */
  Fblm_SetBootInitDone(); 
}
/*______ L O C A L - F U N C T I O N S _______________________________________*/

/*______ E N D _____ (FileName.c) ____________________________________________*/
