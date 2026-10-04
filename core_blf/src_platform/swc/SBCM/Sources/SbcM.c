/******************************************************************************/
/**
* \file       BrsHwSbc.c
* \brief
* \details
*
* \author     X.Ken
* \date       12/29/2020
* \par        History:
*
\verbatim
  Version     Author                    Date            Desc
  1.0         X.Ken                     12/29/2020
\endverbatim
*
*/
/**************** (C) Copyright 2018 Magneti Marelli Guangzhou ****************/

/* _____ I N C L U D E - F I L E S ___________________________________________*/
#include "Platform_Types.h"
#include "SbcM.h"
#include "spic.h"
#include "spid.h"
#include "spid_tv2.h"
#include "iodc.h"
#include "can_config.h"
#include "fblm_priv.h"
#include "fblm_config.h"
/* _____ L O C A L - D E F I N E _____________________________________________*/
#define SBCC_MAX_INDEX_NUM                      20U
#define Sbcc_SPI_E_ResendNum                    (5U) /*if SPI error, then resend 5 times*/

#define Sbcc_INFO_NO1_ADDR                      0x02000000U

#define WDTRIGGER_START_SEC_CODE
#define SBCC_EXT_WD_ENABLE

#define SBCM_BRsHwSbcInitStepZero       0
#define SBCM_BRsHwSbcInitStepOne        1
#define SBCM_BRsHwSbcInitStepTwo        2
#define SBCM_BRsHwSbcInitStepThree      3
#define SBCM_BRsHwSbcInitStepFour       4
#define SBCM_BRsHwSbcInitStepFive       5
#define SBCM_BRsHwSbcWDRefreshValue     180

#define SBCC_GET_OUTPUT_TABLE(Index) (Sbcc_TxList[Index])
#define SBCC_SET_OUTPUT_TABLE(Index, data) \
do \
{  \
     Sbcc_TxList[Index] = (uint32)(data); \
} while (0)

#define SBCC_GET_INPUT_TABLE(Index)  (Sbcc_RxList[Index] )

#define WDMsg  (*((WD_WdgMsg_t*)0x0801F208))

#define DWT_CYCCNT           (*((volatile uint32 *)(0xE0001004ul)))

#define WDCheckDebounceTime 3
#define WD_GPT_StartTicks                 (0XFFFFFFFFU) 
#define WatchDogGptFreq                   (160000000U)  // 10M
#define WatchDogGptFreqDiv                (1U)
#define WatchDogGptFreqSplit              (WatchDogGptFreq/1/1000) //Split frequency and convert milliseconds
#define WatchDogRefreshTimeLONG            (300*WatchDogGptFreqSplit )
#define WatchDogRefreshTime               (40*WatchDogGptFreqSplit )  //Conversion millisecond 180ms   100ns ticks
#define WatchDogRefreshTimeONE            (6*WatchDogGptFreqSplit )
#define WD_JMP_FROM_APP_BIAS_TIMER        (25U) /*Unit: ms*/
#define WD_RESET_AFTER_FEED_TIMER_1       (160*WatchDogGptFreqSplit) /*unit: ms*/
/* _____ L O C A L - T Y P E S _______________________________________________*/
typedef enum
{
  Sbcc_CMDID_WR_CR1 = 0,
  Sbcc_CMDID_WR_CR17,
  Sbcc_CMDID_WR_CR18,
  Sbcc_CMDID_RD_SR1,
  Sbcc_CMDID_RD_SR2,
  Sbcc_CMDID_RD_SR3,
  Sbcc_CMDID_RD_SR4,
  Sbcc_CMDID_RD_SR5,
  Sbcc_CMDID_RD_SR6,
  Sbcc_CMDID_RD_SR7,
  Sbcc_CMDID_RD_SR8,
  Sbcc_CMDID_RD_CLEAR_SR7, 
  Sbcc_CMDID_RD_CLEAR_SR8, 
  Sbcc_CMDID_NUM
} Sbcc_CmdId_t;

typedef cy_en_flashdrv_status_t (* tFlashGetDrvStatus)(cy_un_flash_context_t *context);
typedef bool (* tFlashGetCompleted)(void);
/* _____ G L O B A L - D A T A _______________________________________________*/
uint8 SBCM_InitSbcFlag = FALSE;
uint32 Sbcc_SendCmdData = 0;
// volatile WD_WdgMsg_t WDMsg = {0};

extern cy_stc_scb_spi_context_t Spid_contextSCB2;
/* _____ L O C A L - D A T A _________________________________________________*/

static uint32 Sbcc_TxList[Sbcc_CMDID_NUM] = {
  (Sbcc_BTS_WRITE | Sbcc_CR1_Addr_DZ300 | Sbcc_CR1_LIN_TXD_TOUT_DZ300 ),/* 0 */
  (Sbcc_BTS_WRITE | Sbcc_CR17_Addr_DZ300), /* 1 */
  (Sbcc_BTS_WRITE | Sbcc_CR18_Addr_DZ300 | Sbcc_CR18_CAN_ACT_DZ300 | Sbcc_CR18_EI1_EN_DZ300 | SBcc_CR18_LIN_WU_EN_DZ300 | SBcc_CR18_CAN_WU_EN_DZ300), /* 2 */
  (Sbcc_BTS_READ  | Sbcc_SR1_Addr_DZ300),
  (Sbcc_BTS_READ  | Sbcc_SR2_Addr_DZ300),
  (Sbcc_BTS_READ  | Sbcc_SR3_Addr_DZ300),
  (Sbcc_BTS_READ  | Sbcc_SR4_Addr_DZ300),
  (Sbcc_BTS_READ  | Sbcc_SR5_Addr_DZ300),
  (Sbcc_BTS_READ  | Sbcc_SR6_Addr_DZ300),
  (Sbcc_BTS_READ  | Sbcc_SR7_Addr_DZ300),
  (Sbcc_BTS_READ  | Sbcc_SR8_Addr_DZ300),
  (Sbcc_BTS_READ_CLR  | Sbcc_SR7_Addr_DZ300 | Sbcc_SR7_VS_OV_DZ300 | Sbcc_SR7_VS_UV_DZ300 | Sbcc_SR7_VSREG_OV_DZ300 | Sbcc_SR7_VSREG_UV_DZ300 | Sbcc_SR7_CP_LOW_DZ300),
  (Sbcc_BTS_READ_CLR  | Sbcc_SR8_Addr_DZ300 | Sbcc_SR8_TSD1_DZ300),
};

static uint32 Sbcc_RxList[Sbcc_CMDID_NUM];
static Sbcc_AllStatusRegister_DZ300_t Sbcc_AllStatusRegister = {0};
static uint8 Sbcc_WDFailFlag = FALSE;
static uint8 Sbcc_Gsb_Value = 0;
static ubyte SBCM_BRsHwSbcInitStep = SBCM_BRsHwSbcInitStepOne;
static ubyte SBCM_MainBRsHwSbcInitStep = SBCM_BRsHwSbcInitStepZero;
/* static ubyte SBCM_BRsHwSbcWDRefreshCnt = 0; */
static ubyte Sbcc_InitWatchDogCfgStep = 0;
static ubyte Sbcc_CanDriverInitFlag = FALSE;
static ubyte Sbcc_CheckWDModeCnt = 0;
static ubyte Sbcc_CheckWDFlagCnt = 0;
static boolean Sbcc_WDFlag = FALSE;
static uint32 Sbcc_StartWDRefreshTimerTicks = 0;
static uint32 Sbcc_WDRefreshTimerTicks = 0;

volatile static uint32 Sbcc_WDRefreshTimer = WatchDogRefreshTime;
/* _____ L O C A L - M A C R O S _____________________________________________*/

/* _____ L O C A L - F U N C T I O N S - P R O T O T Y P E S _________________*/
static void Sbcc_SendCmd(Sbcc_CmdId_t id);
static boolean Sbcc_InitWatchDogCfg(void);
static void Sbcc_ClearBitsOfSR(uint8 RegInedx,  uint32 valueToWrite);
void SBCC_ClearResetFlag(void);
void SBCC_RefreshWD(void);
static uint32 Sbcc_SyncTrigBitWithWD(uint32 value);
static boolean CheckWD_Mode(void);
static void SetSbcc_WDFlag(boolean value);
static uint32 SBCC_GptGetStatisticsTimerCnt(void);
static void Sbcc_SetWDHrtTickInterval(void);
static uint32 WD_GetRefreshWDTimer(void);
static void SBCC_ToggleWD(boolean * Value);
static void WD_SetRefreshWDTimer(uint32 counter);
static void SBCM_SPIRunnable(void);
static void SBCM_GoToV1StandbyMode(void);
boolean Sbcc_WatchdogMonitorFLASH(void);

extern void Spid_IrqSCBChannel2(void);
/* _____ G L O B A L - F U N C T I O N S _____________________________________*/

void SBCM_initWDMsg(void)
{
  WDMsg.WD_WDToggleValue = 0;
  WDMsg.WDRefreshTimer = 0;
}

void SBCM_BRsHwSbcInit(void)
{
  switch(SBCM_MainBRsHwSbcInitStep)
  {
    case SBCM_BRsHwSbcInitStepZero:
      if(TRUE == CheckWD_Mode())
      {
        SBCM_MainBRsHwSbcInitStep = SBCM_BRsHwSbcInitStepOne;
      }
    	break;

    case SBCM_BRsHwSbcInitStepOne:
      if(TRUE == GetSbcc_WDFlag())
      {
        if(TRUE == Sbcc_InitWatchDogCfg())
        {
          SBCM_MainBRsHwSbcInitStep = SBCM_BRsHwSbcInitStepTwo;
          SBCM_InitSbcFlag = TRUE;
        }
      }
      else
      {
        SBCM_MainBRsHwSbcInitStep = SBCM_BRsHwSbcInitStepTwo;
        SBCM_InitSbcFlag = TRUE;
      }
    	break;
    default:
      break;
  }
}

void SBCM_BMInitBRsHwSbc(void)
{
  uint32 temp = 0;
  switch(SBCM_BRsHwSbcInitStep)
  {
    case SBCM_BRsHwSbcInitStepOne:
      Sbcc_WDRefreshTimerTicks = SBCC_GptGetStatisticsTimerCnt(); 
      temp = SBCC_GET_OUTPUT_TABLE(Sbcc_CMDID_WR_CR18);
      temp = Sbcc_SyncTrigBitWithWD(temp);
      SBCC_SET_OUTPUT_TABLE(Sbcc_CMDID_WR_CR18, temp); 
      Sbcc_SendCmd(Sbcc_CMDID_WR_CR18);
      SBCM_BRsHwSbcInitStep = SBCM_BRsHwSbcInitStepTwo;
    	break;
    case SBCM_BRsHwSbcInitStepTwo:
      /* Sbcc_SendCmd(Sbcc_CMDID_RD_INFO_NO1);  */
      SBCM_BRsHwSbcInitStep = SBCM_BRsHwSbcInitStepFive; /* just enable the CAN controller,do not need the Step Three and four,
                                                            this can reduce to Startup time*/
    	break;
    case SBCM_BRsHwSbcInitStepThree:
      Sbcc_SendCmd(Sbcc_CMDID_RD_SR1);/*Need the reset flag*/
      SBCM_BRsHwSbcInitStep = SBCM_BRsHwSbcInitStepFour;
    	break;
    case SBCM_BRsHwSbcInitStepFour:
      /* Sbcc_InitWatchDogCfg(); */
      SBCM_BRsHwSbcInitStep = SBCM_BRsHwSbcInitStepFive;
      break;
  }
  if((SBCM_BRsHwSbcInitStepFive == SBCM_BRsHwSbcInitStep) && \
		  (FALSE == Sbcc_CanDriverInitFlag))
  {
    CAND_Init();
    Sbcc_CanDriverInitFlag = TRUE;
  }
}

void SBCC_ClearResetFlag(void)
{
  uint32 temp;
#ifdef SBCC_EXT_WD_ENABLE
  temp = SBCC_GET_OUTPUT_TABLE(Sbcc_CMDID_RD_CLEAR_SR8);
  if((SBCC_GET_INPUT_TABLE(Sbcc_CMDID_RD_SR8) & Sbcc_SR8_VPOR_DZ300) != 0x00)
  {
    temp |= Sbcc_SR8_VPOR_DZ300;
  }
  SBCC_SET_OUTPUT_TABLE(Sbcc_CMDID_RD_CLEAR_SR8, temp);
  Sbcc_SendCmd(Sbcc_CMDID_RD_CLEAR_SR8);
#endif
}

void SBCC_RefreshWD(void)
{
  SBCC_ToggleWD((boolean *)&WDMsg.WD_WDToggleValue);
  Sbcc_SendCmd(Sbcc_CMDID_WR_CR1);
}

static void SBCC_ToggleWD(boolean * Value)
{
#ifdef SBCC_EXT_WD_ENABLE
  uint32 temp = SBCC_GET_OUTPUT_TABLE(Sbcc_CMDID_WR_CR1);

  if((*Value) == TRUE)
  {
    temp &= ~((uint32)Sbcc_CR1_TRIG_DZ300);
    (*Value) = FALSE;
  }
  else
  {
    temp |= (Sbcc_CR1_TRIG_DZ300);
    (*Value) = TRUE;
  }
  SBCC_SET_OUTPUT_TABLE(Sbcc_CMDID_WR_CR1, temp);
#endif
}

boolean SBCC_GetWDFailFlag(void)
{
  return Sbcc_WDFailFlag;
}

/* _____ L O C A L - F U N C T I O N S _______________________________________*/
static void Sbcc_SendCmd(Sbcc_CmdId_t id)
{
  if (id < Sbcc_CMDID_NUM) {
	  IODC_SetOutputData(SPI_CS, IODC_INACTIVE);
	  Sbcc_SendCmdData = (((Sbcc_TxList[id] >> 16) & 0xFFFF) + ((Sbcc_TxList[id] << 16) & 0xFFFF0000));
	  SPID_TransmitData(2, (uint8 *)&Sbcc_SendCmdData,(uint8 *)&Sbcc_RxList[id], 2);
    SBCM_SPIRunnable();
  }
}


static boolean Sbcc_InitWatchDogCfg(void)
{
  uint32 temp = 0;
  boolean ret = FALSE;
#ifdef SBCC_EXT_WD_ENABLE
  if(0 == Sbcc_InitWatchDogCfgStep)
  {
    temp = SBCC_GET_INPUT_TABLE(Sbcc_CMDID_RD_SR8);
    temp <<= 16;
    temp |= (SBCC_GET_INPUT_TABLE(Sbcc_CMDID_RD_SR8) >> 16) & 0x0000FFFF;
    if(((temp & Sbcc_SR8_WDFAIL_DZ300) != 0x00)  
      || (WDMsg.WDRefreshTimer == 0)) //WD Failsafe or power on
    {
      WDMsg.WD_WDToggleValue = FALSE;
      SBCC_RefreshWD(); //Exit long open windows
      Sbcc_InitWatchDogCfgStep = 1;
      Sbcc_WDRefreshTimer = WatchDogRefreshTimeONE;
    }
    else
    {
      SBCC_RefreshWD(); // feed dog
      WD_SetRefreshWDTimer(0);
      Sbcc_StartWDRefreshTimerTicks =0;
      Sbcc_WDRefreshTimerTicks = SBCC_GptGetStatisticsTimerCnt();
      ret = TRUE;
    }
  }
  else if(1 == Sbcc_InitWatchDogCfgStep)
  {
    temp = SBCC_GET_INPUT_TABLE(Sbcc_CMDID_RD_SR8);
    temp <<= 16;
    temp |= (SBCC_GET_INPUT_TABLE(Sbcc_CMDID_RD_SR8) >> 16) & 0x0000FFFF;
    Sbcc_ClearBitsOfSR(Sbcc_CMDID_RD_CLEAR_SR8,temp & 0x00ffffffU); // Clear all SR1 Error
    Sbcc_InitWatchDogCfgStep = 2;
  }
  else if(2 == Sbcc_InitWatchDogCfgStep)
  {
    temp = SBCC_GET_INPUT_TABLE(Sbcc_CMDID_RD_SR7);
    temp <<= 16;
    temp |= (SBCC_GET_INPUT_TABLE(Sbcc_CMDID_RD_SR7) >> 16) & 0x0000FFFF;
    Sbcc_ClearBitsOfSR(Sbcc_CMDID_RD_CLEAR_SR7,temp & 0x00ffffffU); // Clear all SR1 Error
    Sbcc_InitWatchDogCfgStep = 3;
  }
  else if(3 == Sbcc_InitWatchDogCfgStep)
  {
    temp = SBCC_GET_OUTPUT_TABLE(Sbcc_CMDID_WR_CR1);
    // temp |= Sbcc_CFGR_TSD_CONFIG; /* Selective shut down of power stage cluster */
    temp |= Sbcc_CR1_WD_CONFIG_EN_DZ300;  /* Watchdog configuration Enable */
    temp = Sbcc_SyncTrigBitWithWD(temp); //Sync Trig bit with WD feed value
    SBCC_SET_OUTPUT_TABLE(Sbcc_CMDID_WR_CR1, temp);
    Sbcc_SendCmd(Sbcc_CMDID_WR_CR1);
    Sbcc_InitWatchDogCfgStep = 4;
  }
  else if(4 == Sbcc_InitWatchDogCfgStep)
  {
    temp = SBCC_GET_OUTPUT_TABLE(Sbcc_CMDID_WR_CR17);
    temp |= (Sbcc_CR17_V1_RESET_1_DZ300|Sbcc_CR17_V1_RESET_0_DZ300); /* Set Reset threshold of V1 under 3.5V */
    temp |= (Sbcc_CR17_WD_TIME_DZ300); /* Set Watchdog Trigger Time to TSW4(from 150ms to 240ms) */
    SBCC_SET_OUTPUT_TABLE(Sbcc_CMDID_WR_CR17, temp);
    Sbcc_SendCmd(Sbcc_CMDID_WR_CR17);
    Sbcc_StartWDRefreshTimerTicks =0;
    Sbcc_InitWatchDogCfgStep = 0;
    WD_SetRefreshWDTimer(SBCC_GptGetStatisticsTimerCnt());
    Sbcc_WDRefreshTimerTicks = WD_GetRefreshWDTimer();
    ret = TRUE;
  }
#endif
  return ret;
}

/******************************************************************************/
/**
* \brief      Sbcc_ClearBitsOfSR
*
* \author     H.Huisheng
* \param      RegInedx(uint8)      : register index, refer to sbcc_priv.h
* \param      valueToWrite(uint32) : value to be wrote to register
* \retval     N/A
* \note       N/A
*/
/******************************************************************************/
static void Sbcc_ClearBitsOfSR(uint8 RegInedx,  uint32 valueToWrite)
{
  uint32 temp = SBCC_GET_OUTPUT_TABLE(RegInedx);

  temp |= valueToWrite;
  SBCC_SET_OUTPUT_TABLE(RegInedx, temp);
  (void)Sbcc_SendCmd((Sbcc_CmdId_t)RegInedx);
}

# define WDTRIGGER_STOP_SEC_CODE

/******************************************************************************
* Name         :  Imcd_SpiTransferCompleteCallback
* Called by    :  Spid_SpiEventChannel5()
* Preconditions:  None
* Parameters   :  None
* Return code  :  None
* Description  :  This function is called for Spi Transfer Complete Callout
******************************************************************************/
void SbcM_SpiTransferCompleteCallback(void)
{
	 //IMCD_ISR_SPI_EOQ();
  /*Clear FIFO*/
	 Cy_SCB_SPI_ClearTxFifo(SCB2);
	 Cy_SCB_SPI_ClearRxFifo(SCB2);
	 IODC_SetOutputData(SPI_CS, IODC_ACTIVE);
}

/******************************************************************************
* Name         :  Imcd_SpiTransferErrorCallback
* Called by    :  Spid_SpiEventChannel5()
* Preconditions:  None
* Parameters   :  None
* Return code  :  None
* Description  :  This function is called for Spi Transfer error callout
******************************************************************************/
void SbcM_SpiTransferErrorCallback(void)
{
	 //IMCD_ISR_SPI_EOQ();
  /*Clear FIFO*/
	 Cy_SCB_SPI_ClearTxFifo(SCB2);
	 Cy_SCB_SPI_ClearRxFifo(SCB2);
}

boolean WD_GetWDToggleValue(void)
{
  return WDMsg.WD_WDToggleValue;
}

static uint32 Sbcc_SyncTrigBitWithWD(uint32 value)
{
  uint32 ret_val = value;

#ifdef SBCC_EXT_WD_ENABLE
   if(WD_GetWDToggleValue() == TRUE)
   {
     ret_val |= Sbcc_CR1_TRIG_DZ300;
   }
   else
   {
     ret_val &= (uint32)~((uint32)Sbcc_CR1_TRIG_DZ300);
   }
#endif
  return ret_val;
}

static boolean CheckWD_Mode(void)
{
  boolean ret = FALSE;
  uint32 registerValue =0;

  Sbcc_SendCmd(Sbcc_CMDID_RD_SR8);
  if(Sbcc_CheckWDModeCnt > 0)
  {
    registerValue = SBCC_GET_INPUT_TABLE(Sbcc_CMDID_RD_SR8);
    registerValue <<= 16;
    registerValue |= (SBCC_GET_INPUT_TABLE(Sbcc_CMDID_RD_SR8) >> 16) & 0x0000FFFF;
    if((registerValue & Sbcc_SR8_DEBUG_ACTIVE_DZ300) == 0x00U)//In Normal Mode, WD will  be triggered
    {
      Sbcc_CheckWDFlagCnt++;
    }

    if(Sbcc_CheckWDFlagCnt>=(WDCheckDebounceTime-1))
    {
      SetSbcc_WDFlag(TRUE); //In Normal Mode, WD will  be triggered
    }
    else
    {
      SetSbcc_WDFlag(FALSE); //In Debug Mode, WD will not be triggered
    }

    if(Sbcc_CheckWDModeCnt >=3)
    {
      ret = TRUE;
    }
  }
  Sbcc_CheckWDModeCnt++;

  return ret;
}

boolean GetSbcc_WDFlag(void)
{
  return Sbcc_WDFlag;
}

static void SetSbcc_WDFlag(boolean value)
{
  Sbcc_WDFlag = value ;
}

static uint32 WD_GetRefreshWDTimer(void)
{
  return WDMsg.WDRefreshTimer;
}

static void WD_SetRefreshWDTimer(uint32 counter)
{
  if(counter ==0)
  {
    WDMsg.WDRefreshTimer = 1;
  }
  else
  {
    WDMsg.WDRefreshTimer = counter;
  }
  
}

static uint32 SBCC_GptGetStatisticsTimerCnt(void)
{
  return DWT_CYCCNT;
} 

static uint32 SBCC_GptGetElapsedTime(uint32 StartTime, uint32 EndTime)
{
  uint32 ElapsedTime;

  if (EndTime > StartTime)
  {
      ElapsedTime = EndTime - StartTime;
  }
  else
  {
      ElapsedTime = (WD_GPT_StartTicks) - StartTime + EndTime;
  }
  
  return ElapsedTime;
}

static void Sbcc_SetWDHrtTickInterval(void)
{  
  WD_SetRefreshWDTimer(Sbcc_StartWDRefreshTimerTicks + SBCC_GptGetElapsedTime(Sbcc_WDRefreshTimerTicks,SBCC_GptGetStatisticsTimerCnt()));
}

boolean Sbcc_WatchdogMonitor(void)
{
  boolean retValue = FBLM_NO_TRIGGER;
#ifdef SBCC_EXT_WD_ENABLE
  if(TRUE == GetSbcc_WDFlag())
  {
    if(TRUE == SBCM_InitSbcFlag)
    {
      Sbcc_SetWDHrtTickInterval();
      if(WD_GetRefreshWDTimer() >= Sbcc_WDRefreshTimer)
      {
        SBCC_RefreshWD();
        WD_SetRefreshWDTimer(0);
        Sbcc_WDRefreshTimerTicks = SBCC_GptGetStatisticsTimerCnt();  
        Sbcc_StartWDRefreshTimerTicks =0;
        Sbcc_WDRefreshTimer = WatchDogRefreshTime;
        retValue = FBLM_TM_TRIGGERED;
      }
    }
  }
#else
  retValue = FBLM_TM_TRIGGERED;
#endif
  return retValue;
}

boolean Sbcc_WatchdogMonitorFLASH(void)
{
  cy_un_flash_context_t context;
  do
  {
    Sbcc_SetWDHrtTickInterval();
    if(WD_GetRefreshWDTimer() >= WatchDogRefreshTime)
    {
      SBCC_RefreshWD();
      WD_SetRefreshWDTimer(0);
      Sbcc_WDRefreshTimerTicks = SBCC_GptGetStatisticsTimerCnt();  
      Sbcc_StartWDRefreshTimerTicks =0;
    }
  }while(FLASH_DRIVER_GETDRVSTATUS(&context));
}

void Sbcc_Reset(void)
{
  if(GetSbcc_WDFlag() == TRUE)//In Normal Mode, WD will  be triggered
  {
    //Before restarting, check whether the dog needs to be fed in advance
    if(WD_GetRefreshWDTimer() >= WD_RESET_AFTER_FEED_TIMER_1)
    {
      SBCC_RefreshWD();
      WD_SetRefreshWDTimer(0);
    }
  }
}

static void SBCM_SPIRunnable(void)
{
  while (CY_SCB_SPI_TRANSFER_ACTIVE == (Spid_contextSCB2.status & CY_SCB_SPI_TRANSFER_ACTIVE))
  {
    Spid_IrqSCBChannel2();
  }
}

static void SBCM_GoToV1StandbyMode(void)
{
  uint32 temp = 0;
  temp = SBCC_GET_OUTPUT_TABLE(Sbcc_CMDID_WR_CR17);
  temp |= (Sbcc_CR17_STBY_SEL_DZ300|Sbcc_CR17_GO_STBY_DZ300); /* Go To V1_Standby Mode */
  SBCC_SET_OUTPUT_TABLE(Sbcc_CMDID_WR_CR17, temp);
  Sbcc_SendCmd(Sbcc_CMDID_WR_CR17);
  Sbcc_WDRefreshTimer = WatchDogRefreshTimeLONG;
}
/* _____E N D _____ (BrsHwSbc.c) _____________________________________________*/


