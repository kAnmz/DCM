/******************************************************************************/
/*@F_NAME:           xxxx.c                                                   */
/*@F_PURPOSE:        XXXX - Module description                                */
/*@F_CREATED_BY:     Yanbin SHEN                                              */
/*@F_CREATION_DATE:  Jun/22/2020                                              */
/*@F_LANGUAGE :      ANSI C or ASM-CompilerName (to choose)                   */
/*@F_MPROC_TYPE:     Target Name or Processor independent (to choose)         */
/************************************** (C) Copyright 2020 Magneti Marelli ****/


/*______ I N C L U D E - F I L E S ___________________________________________*/


#ifdef __CORE_CM0P__
#include "syst_crypto_config_server.h"
#include "type.h"
#ifdef __TVII_FBL__
#include "fblm_main.h"
#endif

#if defined(__CYT4DN__)
#include "cpus_tviic_6m.h"
#include "iodc.h"
#include "iodc_config.h"
#include "cy_systick.h"
#include "cy_sysint.h"
  
#elif defined(__CYT2B9__)
  #include "cpus_tvii_2m.h"
  #include "cy_gpio.h"
  #include "mcwdt/cy_mcwdt.h"
  #include "iodc.h"
  #include "syst.h"
  #include "cy_syspm.h"
  #include "cy_sysint.h"
  #include "cy_scb_uart.h"

  #elif defined(__CYT2B7__)
  #include "cpus_tvii_1m.h"
  #include "cy_gpio.h"
  #include "mcwdt/cy_mcwdt.h"

#else
  #error Please select cypress traveo chip type.
#endif /*system_cytxxx.h*/

#else /* __CORE_CM4__ */

#ifdef __TVII_FBL__
#include "fblm_main.h"
#endif

#include "cy_project.h"
#include "cy_device_headers.h"

#include "star.h"
#include "type.h"
#include "syst.h"
#include "star_config.h"
#if defined(CY_CORE_CM7_0)  || defined(CY_CORE_CM7_1)
#include "cpus_tviic_6m.h"
#endif

#if defined(__CYT2B7__)
#include "cpus_tvii_1m.h"
#include "cy_gpio.h"
#include "mcwdt/cy_mcwdt.h"
#else
  #error Please select cypress traveo chip type.
#endif /*system_cytxxx.h*/

#include "cy_gpio.h"
#ifdef CY_CORE_CM4
#include "bb_bsp_tviibe2m_revc.h"
#include "imcp_config.h"
#endif
#endif // __CORE_CM0P__
/*______ L O C A L - D E F I N E S ___________________________________________*/
#ifdef __CORE_CM0P__
#if defined(__CYT4DN__)

#ifdef __DEVM_TEST__
#define USER_BUTTON_PORT        GPIO_PRT2
#define USER_BUTTON_PIN         1
#define USER_BUTTON_PIN_MUX     P2_0_GPIO
#define USER_BUTTON_IRQ         ioss_interrupts_gpio_dpslp_2_IRQn
#endif
  
#elif defined(__CYT2B9__)

#define CY_CB_LED_PORT                 	GPIO_PRT8
#define CY_CB_LED_PIN                   2
#define CY_CB_LED_PIN_MUX               P8_2_GPIO

#define USER_LED_PORT           CY_CB_LED_PORT
#define USER_LED_PIN            CY_CB_LED_PIN
#define USER_LED_PIN_MUX        CY_CB_LED_PIN_MUX
  
#elif defined(__CYT2B7__)

#define CY_CB_LED_PORT                 	GPIO_PRT8
#define CY_CB_LED_PIN                   2
#define CY_CB_LED_PIN_MUX               P8_2_GPIO

#define USER_LED_PORT           CY_CB_LED_PORT
#define USER_LED_PIN            CY_CB_LED_PIN
#define USER_LED_PIN_MUX        CY_CB_LED_PIN_MUX

#else
  #error Please select cypress traveo chip type.
#endif
#else


#ifdef CY_CORE_CM4
#if 0
#define USER_LED_PORT           GPIO_PRT5
#define USER_LED_PIN            3
#define USER_LED_PIN_MUX        CY_LED0_PIN_MUX
#endif
#endif  // CY_CORE_CM4
#endif // __CORE_CM0P__
/*______ L O C A L - T Y P E S _______________________________________________*/


/*______ G L O B A L - D A T A _______________________________________________*/


/*______ P R I V A T E - D A T A _____________________________________________*/


/*______ L O C A L - D A T A _________________________________________________*/
/*DLT_DECLARE_CONTEXT(Devm_dlt_context);*/

#ifdef __CORE_CM0P__
#if defined(__CYT4DN__)
#ifdef __DEVM_TEST__
extern ISR(IODC_Irq2_it);

/* Setup GPIO for BUTTON1 interrupt */
const cy_stc_sysint_irq_t irq_cfg =
{
    .sysIntSrc  = USER_BUTTON_IRQ,
    .intIdx     = CPUIntIdx3_IRQn,
    .isEnabled  = TRUE,
};
#endif

#elif defined(__CYT2B7__)
cy_stc_gpio_pin_config_t user_led_port_pin_cfg =
{
    .outVal = 0x00,
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,
    .hsiom = USER_LED_PIN_MUX,
    .intEdge = 0,
    .intMask = 0,
    .vtrip = 0,
    .slewRate = 0,
    .driveSel = 0,
    .vregEn = 0,
    .ibufMode = 0,
    .vtripSel = 0,
    .vrefSel = 0,
    .vohSel = 0,
};

#elif defined(__CYT2B9__)
cy_stc_gpio_pin_config_t user_led_port_pin_cfg =
{
    .outVal = 0x00,
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,
    .hsiom = USER_LED_PIN_MUX,
    .intEdge = 0,
    .intMask = 0,
    .vtrip = 0,
    .slewRate = 0,
    .driveSel = 0,
    .vregEn = 0,
    .ibufMode = 0,
    .vtripSel = 0,
    .vrefSel = 0,
    .vohSel = 0,
};

/* if CAN Wakeup set ture */
static bool_t Wkss_CanWakeupState;
/* CYT2B97 wakeup pin interrupt config */
const cy_stc_sysint_irq_t Devm_WakeupIntCfg =
{
    .sysIntSrc  = ioss_interrupts_gpio_18_IRQn,
    .intIdx     = CPUIntIdx2_IRQn,
    .isEnabled  = true,
};
/* CYT2B97 KL15 pin config */
const cy_stc_gpio_pin_config_t Devm_KL15PortPinCfg =
{
    .outVal    = 0x00,
    .driveMode = CY_GPIO_DM_HIGHZ,
    .hsiom     = P18_5_GPIO,
    .intEdge   = CY_GPIO_INTR_RISING,
    .intMask   = 1,
    .vtrip     = 0,
    .slewRate  = 0,
    .driveSel  = 0,
    .vregEn    = 0,
    .ibufMode  = 0,
    .vtripSel  = 0,
    .vrefSel   = 0,
    .vohSel    = 0,
};
/* CYT2B97 CAN pin config */
const cy_stc_gpio_pin_config_t Devm_HSCANRXPortPinCfg =
{
    .outVal    = 0x00,
    .driveMode = CY_GPIO_DM_HIGHZ,
    .hsiom     = P18_7_GPIO,
    .intEdge   = CY_GPIO_INTR_FALLING,
    .intMask   = 1,
    .vtrip     = 0,
    .slewRate  = 0,
    .driveSel  = 0,
    .vregEn    = 0,
    .ibufMode  = 0,
    .vtripSel  = 0,
    .vrefSel   = 0,
    .vohSel    = 0,
};
#else
  #error Please select cypress traveo chip type.
#endif
#else
#ifdef CY_CORE_CM4
#if 0
cy_stc_gpio_pin_config_t user_led_port_pin_cfg =
{
    .outVal = 0x00,
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,
    .hsiom = USER_LED_PIN_MUX,
    .intEdge = 0,
    .intMask = 0,
    .vtrip = 0,
    .slewRate = 0,
    .driveSel = 0,
    .vregEn = 0,
    .ibufMode = 0,
    .vtripSel = 0,
    .vrefSel = 0,
    .vohSel = 0,
};
#endif
#endif  //CY_CORE_CM4
#endif // __CORE_CM0P__
/*______ L O C A L - M A C R O S _____________________________________________*/


/*______ I M P O R T - F U N C T I O N S - P R O T O T Y P E S _______________*/


/*______ L O C A L - F U N C T I O N S - P R O T O T Y P E S _________________*/

#ifdef __CORE_CM0P__

static int Devm_StartM0(void);
static void Devm_MCWDTInit(void);
static void Devm_ClearMCWDT(void);
static void Devm_CyM0PWakeupIntHandler(void);
static void Devm_CyM0PWakeupPinSetting(void);
static void Devm_CyM0PWakeupAndSleep(void);

#else
static int Devm_StartMx(void);
#endif
/******************************************************************************
* Name         :  Devm_Init
* Called by    :  DEVM_TASK_ts()
* Preconditions:  None
* Parameters   :  None
* Return code  :  None
* Description  :  This function is called for DEVM  initiation
******************************************************************************/
void Devm_Init(void)
{
/*  DLT_REGISTER_APP( "Devm", "DLT trace" );
  DLT_REGISTER_CONTEXT( Devm_dlt_context, "Devm", "Initiation","..." );*/
}
/******************************************************************************
* Name         :  DEVM_main
* Called by    :
* Preconditions:  None
* Parameters   :  None
* Return code  :  None
* Description  :  This function is called for main function
******************************************************************************/
int DEVM_main(void)
{
#ifdef __CORE_CM0P__
  Devm_StartM0();
#else
  Devm_StartMx();
#endif

  return 0;   /* Fix for Polyspace check*/
}


#ifdef __CORE_CM0P__
#if 0
/******************************************************************************/
/* Name : Devm_CyM0PWakeupIntHandler                                          */
/* Role : CYT2B97 chip the Interrupt processing to wakeup from deepsleep mode.*/
/* Input Parameters : None                                                    */
/* Output Parameters: None                                                    */
/* Preconditions : None                                                       */
/******************************************************************************/
static void Devm_CyM0PWakeupIntHandler(void)
{
  ulong intStatus = 0;

  /* If KL15 RISING edge detected */
  intStatus = Cy_GPIO_GetInterruptStatusMasked(GPIO_PRT18, 5);
  if (intStatus != 0uL)
  {
    Cy_GPIO_ClearInterrupt(GPIO_PRT18, 5);
  }

  /* If HSCAN_RX falling edge detected */
  intStatus = Cy_GPIO_GetInterruptStatusMasked(GPIO_PRT18, 7);
  if (intStatus != 0uL)
  {
    Cy_GPIO_ClearInterrupt(GPIO_PRT18, 7);
  }
}

/******************************************************************************/
/* Name : Devm_CyM0PWakeupPinSetting                                          */
/* Role : CYT2B97 chip setting the pin to wakeup from deepsleep mode.         */
/* Input Parameters : None                                                    */
/* Output Parameters: None                                                    */
/* Preconditions : None                                                       */
/******************************************************************************/
static void Devm_CyM0PWakeupPinSetting(void)
{
  /* KL15 */
  Cy_GPIO_Pin_Init(GPIO_PRT18, 5, &Devm_KL15PortPinCfg);
  /* HSCAN_RX */
  Cy_GPIO_Pin_Init(GPIO_PRT18, 7, &Devm_HSCANRXPortPinCfg);

  Cy_SysInt_InitIRQ(&Devm_WakeupIntCfg);
  Cy_SysInt_SetSystemIrqVector(Devm_WakeupIntCfg.sysIntSrc, Devm_CyM0PWakeupIntHandler);
  NVIC_SetPriority(Devm_WakeupIntCfg.intIdx, 3);
  NVIC_ClearPendingIRQ(Devm_WakeupIntCfg.intIdx);
  NVIC_EnableIRQ(Devm_WakeupIntCfg.intIdx);
}

/******************************************************************************
* Name         :  Devm_M0MCWDTInit
* Called by    :
* Preconditions:  None
* Parameters   :  None
* Return code  :  None
* Description  :  This function is called for  init MCWDT
******************************************************************************/
static void Devm_MCWDTInit(void)
{
  /*          Configuration for MCWDT               */
  Cy_MCWDT_SetLowerAction(MCWDT0, CY_MCWDT_COUNTER0, CY_MCWDT_ACTION_NONE);
  Cy_MCWDT_SetUpperAction(MCWDT0, CY_MCWDT_COUNTER0, CY_MCWDT_ACTION_NONE);
  Cy_MCWDT_SetWarnAction(MCWDT0, CY_MCWDT_COUNTER0, CY_MCWDT_WARN_ACTION_NONE);
  Cy_MCWDT_SetLowerAction(MCWDT0, CY_MCWDT_COUNTER1, CY_MCWDT_ACTION_NONE);
  Cy_MCWDT_SetUpperAction(MCWDT0, CY_MCWDT_COUNTER1, CY_MCWDT_ACTION_FAULT_THEN_RESET);
  Cy_MCWDT_SetWarnAction(MCWDT0, CY_MCWDT_COUNTER1, CY_MCWDT_WARN_ACTION_NONE);
  Cy_MCWDT_SetSubCounter2Action(MCWDT0, CY_MCWDT_CNT2_ACTION_NONE);
  /*  Set limit values     */
  Cy_MCWDT_SetLowerLimit(MCWDT0, CY_MCWDT_COUNTER0, 0, 0);
  Cy_MCWDT_SetWarnLimit(MCWDT0, CY_MCWDT_COUNTER0, 0, 0);
  Cy_MCWDT_SetUpperLimit(MCWDT0, CY_MCWDT_COUNTER0, 0, 0);
  Cy_MCWDT_SetLowerLimit(MCWDT0, CY_MCWDT_COUNTER1, 0, 0);
  Cy_MCWDT_SetWarnLimit(MCWDT0, CY_MCWDT_COUNTER1, 0, 0);
  Cy_MCWDT_SetUpperLimit(MCWDT0, CY_MCWDT_COUNTER1, 8736, 0);  /* 0.273 sec when clk_lf = 8736Hz */
  Cy_MCWDT_SetToggleBit(MCWDT0, CY_MCWDT_CNT2_MONITORED_BIT15);
  /*Set options */
  Cy_MCWDT_SetAutoService(MCWDT0, CY_MCWDT_COUNTER0, 0u);
  Cy_MCWDT_SetAutoService(MCWDT0, CY_MCWDT_COUNTER1, 0u);
  Cy_MCWDT_SetSleepDeepPause(MCWDT0, CY_MCWDT_COUNTER0, 0u);
  Cy_MCWDT_SetSleepDeepPause(MCWDT0, CY_MCWDT_COUNTER1, 0u);
  Cy_MCWDT_SetSleepDeepPause(MCWDT0, CY_MCWDT_COUNTER2, 0u);
  Cy_MCWDT_SetDebugRun(MCWDT0, CY_MCWDT_COUNTER0, 1u);
  Cy_MCWDT_SetDebugRun(MCWDT0, CY_MCWDT_COUNTER1, 1u);
  Cy_MCWDT_SetDebugRun(MCWDT0, CY_MCWDT_COUNTER2, 1u);

  Cy_MCWDT_Enable(MCWDT0, CY_MCWDT_CTR_Msk, 0u);
}

/******************************************************************************
* Name         :  Devm_ClearMCWDT
* Called by    :
* Preconditions:  None
* Parameters   :  None
* Return code  :  None
* Description  :  This function is called for Clear MCWDT
******************************************************************************/
static void Devm_ClearMCWDT(void)
{
  Cy_MCWDT_ClearWatchdog(MCWDT0, CY_MCWDT_COUNTER1);
  Cy_MCWDT_WaitForCounterReset(MCWDT0, CY_MCWDT_COUNTER1);
}

/*----------------------------------------------------------------------------*/
/* Name : WKSS_CyM0PWakeupAndSleep                                            */
/* Role : CYT2B97 Chip set the M0P Core sleep and Wakeup.                     */
/* Interface : -                                                              */
/* Pre-condition : -                                                          */
/* Constraints : -                                                            */
/* Behavior :                                                                 */
/*   DO                                                                       */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/
static void Devm_CyM0PWakeupAndSleep(void)
{
  /*if M4 into Deepsleep mode,M0P sync into Deepsleep*/
  if((0u != _FLD2VAL(CPUSS_CM4_STATUS_SLEEPING, CPUSS->unCM4_STATUS.u32Register)) &&
  (0u != _FLD2VAL(CPUSS_CM4_STATUS_SLEEPDEEP, CPUSS->unCM4_STATUS.u32Register)))
  {
	/* Close all interrupt */
	__disable_irq();

    /* Disable MCWDT */
    Cy_MCWDT_DeInit(MCWDT0);
    /* Must disable,have use 15mA in deepsleep mode */
    Cy_SCB_UART_DeInit(DLT_SCB_CHANNEL);
    /* Set wakeup pin */
    Devm_CyM0PWakeupPinSetting();

    __enable_irq();

    Cy_SysPm_DeepSleep(CY_SYSPM_WAIT_FOR_INTERRUPT);

    /* Close Wakeup interrupt */
    NVIC_DisableIRQ(Devm_WakeupIntCfg.intIdx);
    /* Init MCWDT */
    Devm_MCWDTInit();
    /* init the Debug uart */
    DLT_UartInit();
    dlt_driver_init();
  }
}
#endif

#endif

#ifdef __CORE_CM0P__
/******************************************************************************
* Name         :  Devm_StartM0
* Called by    :
* Preconditions:  None
* Parameters   :  None
* Return code  :  None
* Description  :  This function is called for main function
******************************************************************************/
#if 1
static uint16 Devm_TaskCounter = 0;
#endif
int Devm_StartM0(void)
{

#if defined(__CYT4DN__)
  CPUS_StartClockTree();

#ifdef __DEVM_TEST__
  IODC_Init();

  IODC_EnableIrq(BUTTON_UP);
  
  Cy_SysInt_InitIRQ(&irq_cfg);
  
  Cy_SysInt_SetSystemIrqVector(irq_cfg.sysIntSrc, IODC_Irq2_it);

  NVIC_SetPriority(irq_cfg.intIdx, 3ul);
  NVIC_EnableIRQ(irq_cfg.intIdx);
#endif

  EnableAllInterrupts();
  SYST_CryptoServerCongfig();
  /* Enable CM7_0/1. CY_CORTEX_M7_APPL_ADDR is calculated in linker script, check it in case of problems. */
  CPUS_SysEnableApplCore(CORE_CM7_0, CPUS_CORTEX_M7_0_APPL_ADDR);
  CPUS_SysEnableApplCore(CORE_CM7_1, CPUS_CORTEX_M7_1_APPL_ADDR);

  DLT_UartInit();
  dlt_driver_init();
  Devm_Init();
  
  for(;;)
  {
     Cy_SysTick_DelayInMs(1000); /*1000MS*/

     /*Dlt main function*/
     dlt_MainFunction();
#ifdef __DEVM_TEST__
	 IODC_SetSoftwareInterruptTrigger(BUTTON_UP);
#endif

#if 1
     if(Devm_TaskCounter < 10000)
     {
       Devm_TaskCounter++;
     }
     else
     {
       Devm_TaskCounter = 0;
     }
     if(Devm_TaskCounter%100 == 0)
     {
       DLT_LOG_ID2( Devm_dlt_context, DLT_LOG_INFO, Devm, DLT_CSTRING("Cortex M0Plus Devm  Runing"),DLT_UINT16(Devm_TaskCounter));
     }
#endif
  }
#elif defined(__CYT2B7__)

  CPUS_StartClockTree();
  EnableAllInterrupts();
#if 0
  /* Check the IO status. If current status is frozen, unfreeze the system. */
  if(Cy_SysPm_GetIoFreezeStatus())
  {
      /* Unfreeze the system */
      Cy_SysPm_IoUnfreeze();
  }
  else
  {
      /* Do nothing */
  }
#endif
  SYST_CryptoServerCongfig();
#if !defined(__TVII_FBL__)
  /* Enable CM4.  CPUS_CORTEX_M4_APPL_ADDR must be updated if CM4 memory layout is changed. */
  CPUS_SysEnableApplCore(CPUS_CORTEX_M4_APPL_ADDR);
  Cy_GPIO_Pin_Init(USER_LED_PORT, USER_LED_PIN, &user_led_port_pin_cfg);

  DLT_UartInit();
  dlt_driver_init();
  Devm_Init();

  Devm_MCWDTInit();

  for(;;)
  {
    Devm_ClearMCWDT();
    //The core frequency is 80MHz. 800000 / 80MHz = 0.01[s]
	//DELAY_CORE_CYCLE(800000);
    /*Dlt main function*/
    dlt_MainFunction();
#if 0
	if(Devm_TaskCounter < 10000)
	{
	  Devm_TaskCounter++;
	}
	else
	{
	  Devm_TaskCounter = 0;
	}

    if(Devm_TaskCounter%50 == 0)
    {
      Cy_GPIO_Inv(USER_LED_PORT, USER_LED_PIN);
    }

    if(Devm_TaskCounter%100 == 0)
    {
      DLT_LOG_ID2( Devm_dlt_context, DLT_LOG_INFO, Devm, DLT_CSTRING("Cortex M0Plus Devm  Runing"),DLT_UINT16(Devm_TaskCounter));
    }
#endif

    Devm_CyM0PWakeupAndSleep();
  }
#else        /*defined(__TVII_FBL__)*/
  FBLM_Main();
#endif
#else
  #error Please select cypress traveo chip type.
#endif

  return 0;  /* Fix for Polyspace check*/
}
#else

/******************************************************************************
* Name         :  Devm_StartMx
* Called by    :
* Preconditions:  None
* Parameters   :  None
* Return code  :  None
* Description  :  This function is called for main function
******************************************************************************/
int Devm_StartMx(void)
{
#if defined(__CYT4DN__)
  CPUS_StartClockTree();

#ifdef __DEVM_TEST__
  IODC_Init();

  IODC_EnableIrq(BUTTON_UP);
  
  Cy_SysInt_InitIRQ(&irq_cfg);
  
  Cy_SysInt_SetSystemIrqVector(irq_cfg.sysIntSrc, IODC_Irq2_it);

  NVIC_SetPriority(irq_cfg.intIdx, 3ul);
  NVIC_EnableIRQ(irq_cfg.intIdx);
#endif

  EnableAllInterrupts();
  SYST_CryptoServerCongfig();
  /* Enable CM7_0/1. CY_CORTEX_M7_APPL_ADDR is calculated in linker script, check it in case of problems. */
  CPUS_SysEnableApplCore(CORE_CM7_0, CPUS_CORTEX_M7_0_APPL_ADDR);
  CPUS_SysEnableApplCore(CORE_CM7_1, CPUS_CORTEX_M7_1_APPL_ADDR);

  DLT_UartInit();
  dlt_driver_init();
  Devm_Init();
  
  for(;;)
  {
     Cy_SysTick_DelayInMs(1000); /*1000MS*/

     /*Dlt main function*/
     dlt_MainFunction();
#ifdef __DEVM_TEST__
	 IODC_SetSoftwareInterruptTrigger(BUTTON_UP);
#endif

#if 1
     if(Devm_TaskCounter < 10000)
     {
       Devm_TaskCounter++;
     }
     else
     {
       Devm_TaskCounter = 0;
     }
     if(Devm_TaskCounter%100 == 0)
     {
       DLT_LOG_ID2( Devm_dlt_context, DLT_LOG_INFO, Devm, DLT_CSTRING("Cortex M0Plus Devm  Runing"),DLT_UINT16(Devm_TaskCounter));
     }
#endif
  }
#elif defined(__CYT2B7__)

  CPUS_StartClockTree();
  EnableAllInterrupts();
#if 0
  /* Check the IO status. If current status is frozen, unfreeze the system. */
  if(Cy_SysPm_GetIoFreezeStatus())
  {
      /* Unfreeze the system */
      Cy_SysPm_IoUnfreeze();
  }
  else
  {
      /* Do nothing */
  }
#endif
  // SYST_CryptoServerCongfig();
#if !defined(__TVII_FBL__)
  /* Enable CM4.  CPUS_CORTEX_M4_APPL_ADDR must be updated if CM4 memory layout is changed. */
  CPUS_SysEnableApplCore(CPUS_CORTEX_M4_APPL_ADDR);
  Cy_GPIO_Pin_Init(USER_LED_PORT, USER_LED_PIN, &user_led_port_pin_cfg);

  DLT_UartInit();
  dlt_driver_init();
  Devm_Init();

  Devm_MCWDTInit();

  for(;;)
  {
    Devm_ClearMCWDT();
    //The core frequency is 80MHz. 800000 / 80MHz = 0.01[s]
	//DELAY_CORE_CYCLE(800000);
    /*Dlt main function*/
    dlt_MainFunction();
#if 0
	if(Devm_TaskCounter < 10000)
	{
	  Devm_TaskCounter++;
	}
	else
	{
	  Devm_TaskCounter = 0;
	}

    if(Devm_TaskCounter%50 == 0)
    {
      Cy_GPIO_Inv(USER_LED_PORT, USER_LED_PIN);
    }

    if(Devm_TaskCounter%100 == 0)
    {
      DLT_LOG_ID2( Devm_dlt_context, DLT_LOG_INFO, Devm, DLT_CSTRING("Cortex M0Plus Devm  Runing"),DLT_UINT16(Devm_TaskCounter));
    }
#endif

    Devm_CyM0PWakeupAndSleep();
  }
#else        /*defined(__TVII_FBL__)*/
  FBLM_Main();
#endif
#else
  #error Please select cypress traveo chip type.
#endif

  return 0;  /* Fix for Polyspace check*/
}
/******************************************************************************
* Name         :  DEVM_TASK_ts
* Called by    :  Os
* Preconditions:  None
* Parameters   :  None
* Return code  :  None
* Description  :  This function is called for DEVM  initiation
******************************************************************************/
#if defined(CY_CORE_CM7_0)  || defined(CY_CORE_CM7_1)
#if 1
static uint16 Devm_TaskCounter = 0;
#endif
#endif
#ifdef CY_CORE_CM4
#if 0
static uint16 Devm_TaskCounter = 0;
static PA_VehicleSpeed_t PA_VehicleSpeed = {0};
static CB_VehSpdFuncSetting_t CB_VehSpdFuncSetting = {0};
#endif
#endif


#endif // __CORE_CM0P__
/*______ G L O B A L - F U N C T I O N S _____________________________________*/


/*______ P R I V A T E - F U N C T I O N S ___________________________________*/


/*______ L O C A L - F U N C T I O N S _______________________________________*/


/*______ E N D _____ (xxxx.c) ________________________________________________*/

