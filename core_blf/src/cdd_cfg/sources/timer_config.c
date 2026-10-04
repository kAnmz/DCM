/******************************************************************************/
/* @F_NAME :          timer_config.c                                          */
/* @F_PURPOSE :       Setup a timer for FBL                                   */
/* @F_CREATED_BY :    Jianhua                               				  */
/* @F_CREATION_DATE : 6/26/2021                                       		  */
/* @F_LANGUAGE :      C                                      				  */
/* @F_MPROC_TYPE :    Traveo II               								  */
/*************************************** (C) Copyright 2021  Marelli **********/

/*______ I N C L U D E - F I L E S ___________________________________________*/
#include "cy_project.h"
#include "cy_device_headers.h"
#include "timer_config.h"
/*______ L O C A L - D E F I N E S ___________________________________________*/

#define TCPWM0_GRPx_CNTx_COUNTER                TCPWM0_GRP0_CNT0

#define PCLK_TCPWM0_CLOCKSx_COUNTER             PCLK_TCPWM0_CLOCKS0
#define TCPWM_PERI_CLK_DIVIDER_NO_COUNTER       0u

#define TCPWM0_GRPx_CNT1_COUNTER                TCPWM0_GRP2_CNT0

#define PCLK_TCPWM0_CLOCKS1_COUNTER             PCLK_TCPWM0_CLOCKS512
/*______ L O C A L - T Y P E S _______________________________________________*/

/*______ G L O B A L - D A T A _______________________________________________*/

/*______ P R I V A T E - D A T A _____________________________________________*/
cy_stc_tcpwm_counter_config_t const MyCounter_config =
{
    .period             = 1000u - 1u,                             //1ms//100us
    .clockPrescaler     = CY_TCPWM_COUNTER_PRESCALER_DIVBY_2,  // 20MHz / 2 = 10MHz
    .runMode            = CY_TCPWM_PWM_CONTINUOUS,
    .countDirection     = CY_TCPWM_COUNTER_COUNT_UP,
    .debug_pause        = 0uL,
    .CompareOrCapture   = CY_TCPWM_COUNTER_MODE_COMPARE,
    .compare0           = 0,
    .compare0_buff      = 0,
    .compare1           = 0,
    .compare1_buff      = 0,
    .enableCompare0Swap = false,
    .enableCompare1Swap = false,
    .interruptSources   = 0uL,
    .capture0InputMode  = 3uL,
    .capture0Input      = 0uL,
    .reloadInputMode    = 3uL,
    .reloadInput        = 0uL,
    .startInputMode     = 3uL,
    .startInput         = 0uL,
    .stopInputMode      = 3uL,
    .stopInput          = 0uL,
    .capture1InputMode  = 3uL,
    .capture1Input      = 0uL,
    .countInputMode     = 3uL,
    .countInput         = 1uL,
    .trigger1           = CY_TCPWM_COUNTER_OVERFLOW,
};

cy_stc_tcpwm_counter_config_t const MyCounter1_config =
{
    .period             = 0xFFFFFFFFu - 1u,                             //1ms//100us
    .clockPrescaler     = CY_TCPWM_COUNTER_PRESCALER_DIVBY_2,  // 20MHz / 2 = 10MHz
    .runMode            = CY_TCPWM_PWM_CONTINUOUS,
    .countDirection     = CY_TCPWM_COUNTER_COUNT_UP,
    .debug_pause        = 0uL,
    .CompareOrCapture   = CY_TCPWM_COUNTER_MODE_COMPARE,
    .compare0           = 0,
    .compare0_buff      = 0,
    .compare1           = 0,
    .compare1_buff      = 0,
    .enableCompare0Swap = false,
    .enableCompare1Swap = false,
    .interruptSources   = 0uL,
    .capture0InputMode  = 3uL,
    .capture0Input      = 0uL,
    .reloadInputMode    = 3uL,
    .reloadInput        = 0uL,
    .startInputMode     = 3uL,
    .startInput         = 0uL,
    .stopInputMode      = 3uL,
    .stopInput          = 0uL,
    .capture1InputMode  = 3uL,
    .capture1Input      = 0uL,
    .countInputMode     = 3uL,
    .countInput         = 1uL,
    .trigger1           = CY_TCPWM_COUNTER_OVERFLOW,
};

cy_stc_sysint_irq_t timeerirq_cfg =
{
    .sysIntSrc  = tcpwm_0_interrupts_0_IRQn,
    .intIdx     = CPUIntIdx3_IRQn,
    .isEnabled  = true,
};
/*______ L O C A L - D A T A _________________________________________________*/
ushort Timer_counter = 0u;
bool_t Timer1ms_Flag = FALSE;
/*______ L O C A L - M A C R O S _____________________________________________*/

/*______ I M P O R T - F U N C T I O N S - P R O T O T Y P E S _______________*/

/*______ L O C A L - F U N C T I O N S - P R O T O T Y P E S _________________*/
static void TIMD_TimerSet(void);
/*______ G L O B A L - F U N C T I O N S _____________________________________*/

/*----------------------------------------------------------------------------*/
/*Name : Timer_Handler                                                        */
/*Role : timer interrupt entry function                                       */
/*Interface :                                                                 */
/*  - IN  : none                                                   			  */
/*  - OUT : none                                         					  */
/*Pre-condition : none                                        			      */
/*Constraints   : none                                             			  */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [operation to carry out]                                                */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
void Timer_Handler(void)
{
    if(Cy_Tcpwm_Counter_GetTC_IntrMasked(TCPWM0_GRPx_CNTx_COUNTER))/*1ms*/
    {
    	TIMD_TimerSet();

    	if (Timer_counter<1000)
    	{
    		Timer_counter ++;
    		if(Timer_counter==1000)/*1S*/
    		{
    			Timer_counter = 0;
    		}
    	}
    	else
    	{
    		Timer_counter = 0;
    	}
        Cy_Tcpwm_Counter_ClearTC_Intr(TCPWM0_GRPx_CNTx_COUNTER);
    }
}
/*----------------------------------------------------------------------------*/
/*Name : TIMD_TimerInit                                                       */
/*Role : Init a 1ms timer for Bootloader                                      */
/*Interface :                                                                 */
/*  - IN  : none                                                   			  */
/*  - OUT : none                                         					  */
/*Pre-condition : none                                        			      */
/*Constraints   : none                                             			  */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [operation to carry out]                                                */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
void TIMD_TimerInit(void)
{
    /* Assign a programmable divider for TCPWM0_GRP0_CNT0 */
    Cy_SysClk_PeriphAssignDivider(PCLK_TCPWM0_CLOCKSx_COUNTER, (cy_en_divider_types_t)CY_SYSCLK_DIV_16_BIT, TCPWM_PERI_CLK_DIVIDER_NO_COUNTER);
    /* Sets the 16-bit divider */
  #if (CY_USE_PSVP == 1u)
    Cy_SysClk_PeriphSetDivider((cy_en_divider_types_t)CY_SYSCLK_DIV_16_BIT, TCPWM_PERI_CLK_DIVIDER_NO_COUNTER, 11u); // Divider 11 --> 24MHz / (11+1) = 2MHz
  #else
    Cy_SysClk_PeriphSetDivider((cy_en_divider_types_t)CY_SYSCLK_DIV_16_BIT, TCPWM_PERI_CLK_DIVIDER_NO_COUNTER, 3u); // Divider 3 --> 80MHz / (3+1) = 20MHz
  #endif
    Cy_SysClk_PeriphEnableDivider((cy_en_divider_types_t)CY_SYSCLK_DIV_16_BIT, TCPWM_PERI_CLK_DIVIDER_NO_COUNTER);
#if 0 /*For Bootloader IMC */
    Cy_SysInt_InitIRQ(&timeerirq_cfg);
    Cy_SysInt_SetSystemIrqVector(timeerirq_cfg.sysIntSrc, Timer_Handler);
    /* Set the Interrupt Priority & Enable the Interrupt */
    NVIC_SetPriority(CPUIntIdx3_IRQn, 3u);
    NVIC_ClearPendingIRQ(CPUIntIdx3_IRQn);
    NVIC_EnableIRQ(CPUIntIdx3_IRQn);
#endif
    /* Initialize TCPWM0_GPR0_CNT0 as Timer/Counter & Enable */
    Cy_Tcpwm_Counter_Init(TCPWM0_GRPx_CNTx_COUNTER, &MyCounter_config);
    Cy_Tcpwm_Counter_Enable(TCPWM0_GRPx_CNTx_COUNTER);
    Cy_Tcpwm_TriggerStart(TCPWM0_GRPx_CNTx_COUNTER);
    /* Enable Interrupt */
    Cy_Tcpwm_Counter_SetTC_IntrMask(TCPWM0_GRPx_CNTx_COUNTER);

}

void TIMD_Timer1Init(void)
{
#if 1
    /* Assign a programmable divider for TCPWM0_GRP0_CNT0 */
    Cy_SysClk_PeriphAssignDivider(PCLK_TCPWM0_CLOCKS1_COUNTER, (cy_en_divider_types_t)CY_SYSCLK_DIV_16_BIT, TCPWM_PERI_CLK_DIVIDER_NO_COUNTER);
    /* Sets the 16-bit divider */
  #if (CY_USE_PSVP == 1u)
    Cy_SysClk_PeriphSetDivider((cy_en_divider_types_t)CY_SYSCLK_DIV_16_BIT, TCPWM_PERI_CLK_DIVIDER_NO_COUNTER, 11u); // Divider 11 --> 24MHz / (11+1) = 2MHz
  #else
    Cy_SysClk_PeriphSetDivider((cy_en_divider_types_t)CY_SYSCLK_DIV_16_BIT, TCPWM_PERI_CLK_DIVIDER_NO_COUNTER, 3u); // Divider 3 --> 80MHz / (3+1) = 20MHz
  #endif
    Cy_SysClk_PeriphEnableDivider((cy_en_divider_types_t)CY_SYSCLK_DIV_16_BIT, TCPWM_PERI_CLK_DIVIDER_NO_COUNTER);
#if 0 /*For Bootloader IMC */
    Cy_SysInt_InitIRQ(&timeerirq_cfg);
    Cy_SysInt_SetSystemIrqVector(timeerirq_cfg.sysIntSrc, Timer_Handler);
    /* Set the Interrupt Priority & Enable the Interrupt */
    NVIC_SetPriority(CPUIntIdx3_IRQn, 3u);
    NVIC_ClearPendingIRQ(CPUIntIdx3_IRQn);
    NVIC_EnableIRQ(CPUIntIdx3_IRQn);
#endif
    /* Initialize TCPWM0_GPR0_CNT0 as Timer/Counter & Enable */
    Cy_Tcpwm_Counter_Init(TCPWM0_GRPx_CNT1_COUNTER, &MyCounter1_config);
    Cy_Tcpwm_Counter_Enable(TCPWM0_GRPx_CNT1_COUNTER);
    Cy_Tcpwm_TriggerStart(TCPWM0_GRPx_CNT1_COUNTER);
    /* Enable Interrupt */
    /* Cy_Tcpwm_Counter_SetTC_IntrMask(TCPWM0_GRPx_CNT1_COUNTER); */
#endif
}

bool_t TIMD_TimerGet(void)
{
#if 1
	if(Cy_Tcpwm_Counter_GetTC_IntrMasked(TCPWM0_GRPx_CNTx_COUNTER))/*1ms*/
    {
        Cy_Tcpwm_Counter_ClearTC_Intr(TCPWM0_GRPx_CNTx_COUNTER);
    	return TRUE;
    }
    else
    {
    	return FALSE;
    }
#endif
	//return Timer1ms_Flag;
}
/*______ P R I V A T E - F U N C T I O N S ___________________________________*/

/*______ L O C A L - F U N C T I O N S _______________________________________*/
static void TIMD_TimerSet(void)
{
	Timer1ms_Flag = TRUE;
}
/*______ E N D _____ (FileName.c) ____________________________________________*/
