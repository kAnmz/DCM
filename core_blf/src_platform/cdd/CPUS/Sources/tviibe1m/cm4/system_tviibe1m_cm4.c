/**************************************************************************//**
 * @file     system_tviibe1m_cm4.c
 * @brief    CMSIS Cortex-M4 Device Peripheral Access Layer Source File for
 *           Device <Device>
 * @version  V5.00
 * @date     28. September 2016
 ******************************************************************************/
/*
 * Copyright (c) 2009-2016 ARM Limited. All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <stdint.h>
#include <stdbool.h>
#include "cy_device_headers.h"
#include "cpus_tvii_1m.h"
#include "cy_device_headers.h"
#include "cy_syswdt.h"
#include "cy_sysclk.h"

/* SCB->CPACR */
#define SCB_CPACR_CP10_CP11_ENABLE      (0xFUL << 20u)

/** Holds the FastClk system core clock, which is the system clock frequency supplied to the SysTick timer and the
* processor core clock. This variable can be used by debuggers to query the frequency of the debug timer or to configure
* the trace clock speed.
*
* \attention Compilers must be configured to avoid removing this variable in case the application program is not using
* it. Debugging systems require the variable to be physically present in memory so that it can be examined to configure
* the debugger. */
uint32_t SystemCoreClock  = 0UL;

uint32_t cy_delayFreqHz   = 0UL;

uint32_t cy_delayFreqKhz  = 0UL;

uint8_t cy_delayFreqMhz   = 0UL;

uint32_t cy_delay32kMs    = 0UL;

uint32_t CPUS_delayFreqHz = 0UL;

/*******************************************************************************
* Function Name: SystemInit
****************************************************************************//**
*
* Initializes the system
*
*******************************************************************************/
void SystemInit (void)
{
    SystemCoreClockUpdate();
}

/*******************************************************************************
* Function Name: SystemCoreClockUpdate
****************************************************************************//**
*
* Updates variables with current clock settings
*
*******************************************************************************/
void SystemCoreClockUpdate (void)
{
    cy_stc_base_clk_freq_t freqInfo = 
    {
        .clk_imo_freq  = CY_CLK_IMO_FREQ_HZ,
        .clk_ext_freq  = CY_CLK_EXT_FREQ_HZ,
        .clk_eco_freq  = CY_CLK_ECO_FREQ_HZ,
        .clk_ilo0_freq = CY_CLK_HVILO0_FREQ_HZ,
        .clk_ilo1_freq = CY_CLK_HVILO1_FREQ_HZ,
        .clk_wco_freq  = CY_CLK_WCO_FREQ_HZ,
    };

    CY_ASSERT(Cy_SysClk_InitGetFreqParams(&freqInfo) == CY_SYSCLK_SUCCESS);
    CY_ASSERT(Cy_SysClk_GetCoreFrequency(&SystemCoreClock) == CY_SYSCLK_SUCCESS);
	
    cy_delayFreqHz   = SystemCoreClock;
    cy_delayFreqMhz  = (uint8_t)((cy_delayFreqHz + CY_DELAY_1M_MINUS_1_THRESHOLD) / CY_DELAY_1M_THRESHOLD);
    cy_delayFreqKhz  = (cy_delayFreqHz + CY_DELAY_1K_MINUS_1_THRESHOLD) / CY_DELAY_1K_THRESHOLD;
    cy_delay32kMs    = CY_DELAY_MS_OVERFLOW_THRESHOLD * cy_delayFreqKhz;
}

/*******************************************************************************
* Function Name: Cy_SystemInitFpuEnable
****************************************************************************//**
*
* Enables the FPU if it is used. The function is called from the startup file.
*
*******************************************************************************/
void Cy_SystemInitFpuEnable(void)
{
    #if defined (__FPU_USED) && (__FPU_USED == 1U)
        uint32_t  interruptState;
        interruptState = Cy_SaveIRQ();
        SCB->CPACR |= SCB_CPACR_CP10_CP11_ENABLE;
        __DSB();
        __ISB();
        Cy_RestoreIRQ(interruptState);
    #endif /* (__FPU_USED) && (__FPU_USED == 1U) */
}

void CPUS_SystemCoreClockUpdate (void)
{
    cy_stc_base_clk_freq_t freqInfo = 
    {
        .clk_imo_freq  = CPUS_CLK_IMO_FREQ_HZ,
        .clk_ext_freq  = CPUS_CLK_EXT_FREQ_HZ,
        .clk_eco_freq  = CPUS_CLK_ECO_FREQ_HZ,
        .clk_ilo0_freq = CPUS_CLK_HVILO0_FREQ_HZ,
        .clk_ilo1_freq = CPUS_CLK_HVILO1_FREQ_HZ,
        .clk_wco_freq  = CPUS_CLK_WCO_FREQ_HZ,
    };

    CY_ASSERT(Cy_SysClk_InitGetFreqParams(&freqInfo) == CY_SYSCLK_SUCCESS);
    CY_ASSERT(Cy_SysClk_GetCoreFrequency(&SystemCoreClock) == CY_SYSCLK_SUCCESS);
	
    CPUS_delayFreqHz   = SystemCoreClock;
    cy_delayFreqMhz  = (uint8_t)((CPUS_delayFreqHz + CPUS_DELAY_1M_MINUS_1_THRESHOLD) / CPUS_DELAY_1M_THRESHOLD);
    cy_delayFreqKhz  = (CPUS_delayFreqHz + CPUS_DELAY_1K_MINUS_1_THRESHOLD) / CPUS_DELAY_1K_THRESHOLD;
    cy_delay32kMs    = CPUS_DELAY_MS_OVERFLOW_THRESHOLD * cy_delayFreqKhz;
}


/*----------------------------------------------------------------------------*/
/* Name : CPUS_StartClockTree                                                 		 */
/* Role : Startup the Clock Tree                                                           */
/* Interface : -                                                             								 */
/* Pre-condition : -                                                          						 */
/* Constraints :                                                              							 */
/* Behavior :                                                                						 	 */
/*  DO                                                                        								 */
/*    [...to be edited...]                                                   						 */
/*  OD                                                                       									*/
/*----------------------------------------------------------------------------*/
void CPUS_StartClockTree (void)
{
#if defined(CPUS_SYSTEM_WDT_DISABLE)
    /* disable WDT */
    Cy_WDT_Disable();
#endif /* CPUS_SYSTEM_WDT_DISABLE */
    
#if (CY_USE_PSVP == 0u)
      
    /*********** Setting wait state for ROM **********/
    CPUSS->unROM_CTL.stcField.u2SLOW_WS = CPUS_ROM_CTL_SLOW_WS_1;
    CPUSS->unROM_CTL.stcField.u2FAST_WS = CPUS_ROM_CTL_FAST_WS0;

    /*********** Setting wait state for RAM **********/
    CPUSS->unRAM0_CTL0.stcField.u2SLOW_WS = CPUS_RAMx_CTL0_SLOW_WS1;
    CPUSS->unRAM0_CTL0.stcField.u2FAST_WS = CPUS_RAMx_CTL0_FAST_WS0;

    #if defined (CPUSS_RAMC1_PRESENT) && (CPUSS_RAMC1_PRESENT == 1UL)
    CPUSS->unRAM1_CTL0.stcField.u2SLOW_WS = CPUS_RAMx_CTL0_SLOW_WS1;
    CPUSS->unRAM1_CTL0.stcField.u2FAST_WS = CPUS_RAMx_CTL0_FAST_WS0;
    #endif /* defined (CPUSS_RAMC1_PRESENT) && (CPUSS_RAMC1_PRESENT == 1UL) */

    #if defined (CPUSS_RAMC2_PRESENT) && (CPUSS_RAMC2_PRESENT == 1UL)
    CPUSS->unRAM2_CTL0.stcField.u2SLOW_WS = CPUSS_RAMx_CTL0_SLOW_WS1;
    CPUSS->unRAM2_CTL0.stcField.u2FAST_WS = CPUS_RAMx_CTL0_FAST_WS0;
    #endif /* defined (CPUSS_RAMC2_PRESENT) && (CPUSS_RAMC2_PRESENT == 1UL) */

    /*********** Setting wait state for FLASH **********/
    FLASHC->unFLASH_CTL.stcField.u4MAIN_WS = CPUS_FLASHC_FLASH_CTL_MAIN_WS1;

    /***    Set clock LF source        ***/
    SRSS->unCLK_SELECT.stcField.u3LFCLK_SEL = CY_SYSCLK_LFCLK_IN_ILO0;

#if CPUS_SYSTEM_USE_CLOCK == CPUS_SYSTEM_USE_ECO

    /***    ECO port settings        ***/
    /* Default settings should be OK. */

    /***    ECO setting and enabling        ***/
    // These values need to be confirmed
    SRSS->unCLK_ECO_CONFIG2.stcField.u3WDTRIM = CPUS_WATCHDOG_TRIM_150mv;
    SRSS->unCLK_ECO_CONFIG2.stcField.u4ATRIM  = CPUS_AMPLITITUDE_TRIM_450MV;
    SRSS->unCLK_ECO_CONFIG2.stcField.u2FTRIM  = CPUS_FILTER_TRIM3;
    SRSS->unCLK_ECO_CONFIG2.stcField.u2RTRIM  = CPUS_FEEDBACK_RES_TRIM3;
    SRSS->unCLK_ECO_CONFIG2.stcField.u3GTRIM  = CPUS_GAIN_TRIM1;


    SRSS->unCLK_ECO_CONFIG.stcField.u1ECO_EN = CPUS_CLK_ECO_ENABLE;
    while(SRSS->unCLK_ECO_STATUS.stcField.u1ECO_OK == 0ul);
    while(SRSS->unCLK_ECO_STATUS.stcField.u1ECO_READY == 0ul);
#endif

    /***  Set CPUSS dividers as required        ***/
    // FAST = 160,000,000; PERI and SLOW = FAST / 2;
    CPUSS->unCM4_CLOCK_CTL.stcField.u8FAST_INT_DIV = CPUS_SYSTEM_FAST_INT_DIV; // no division
    CPUSS->unCM0_CLOCK_CTL.stcField.u8PERI_INT_DIV = CPUS_SYSTEM_PERI_INT_DIV; // divided by 2
    CPUSS->unCM0_CLOCK_CTL.stcField.u8SLOW_INT_DIV = CPUS_SYSTEM_LOW_INT_DIV; // no division

    /***     PLL setting and enabling        ***/
    SRSS->unCLK_PATH_SELECT[1/*PLL0*/].stcField.u3PATH_MUX = CPUS_SYSTEM_PLL_INPUT_SOURCE;
    SRSS->unCLK_PLL_CONFIG[0].stcField.u5REFERENCE_DIV     = CPUS_SYSTEM_PLL_CONFIG_REFDIV;
    SRSS->unCLK_PLL_CONFIG[0].stcField.u7FEEDBACK_DIV      = CPUS_SYSTEM_PLL_CONFIG_FEEDBACKDIV;
    SRSS->unCLK_PLL_CONFIG[0].stcField.u5OUTPUT_DIV        = CPUS_SYSTEM_PLL_CONFIG_OUTDIV;
    SRSS->unCLK_PLL_CONFIG[0].stcField.u1ENABLE            = CPUS_CLK_PLL_ENABLE;
    while(SRSS->unCLK_PLL_STATUS[0].stcField.u1LOCKED == 0ul);
    
    /***  Assign  PLL0 as source of clk_hf0        ***/
    /* Select source of clk_hf0 */
    /***  Set HF source, divider, enable   ***/
    SRSS->unCLK_ROOT_SELECT[0/*clk_hf0*/].stcField.u4ROOT_MUX = CY_SYSCLK_HFCLK_IN_CLKPATH1;
    SRSS->unCLK_ROOT_SELECT[0].stcField.u2ROOT_DIV = CPUS_SYSTEM_ROOT_DIV; /* no div */
    SRSS->unCLK_ROOT_SELECT[0].stcField.u1ENABLE   = CPUS_CLK_ROOT_SELECT_ENABLE; /* 1 = enable */

    /***   Setting  PATH2  source        ***/
    SRSS->unCLK_PATH_SELECT[2].stcField.u3PATH_MUX = CY_SYSCLK_CLKPATH_IN_IMO;

    /***     FLL  disabling        ***/
    /* Disable Fll */
    SRSS->unCLK_FLL_CONFIG.stcField.u1FLL_ENABLE = CPUS_CLK_FLL_DISABLE;     /* 0 = disable */
    SRSS->unCLK_FLL_CONFIG4.stcField.u1CCO_ENABLE = CPUS_CLK_CCO_DISABLE;    /* 0 = disable */

    /***     Enabling ILO0        ***/
    Cy_WDT_Unlock();
    SRSS->unCLK_ILO0_CONFIG.stcField.u1ENABLE = CPUS_CLK_IO0_ENABLE;        /* 1 = enable */
    SRSS->unCLK_ILO0_CONFIG.stcField.u1ILO0_BACKUP = CPUS_CLK_ILO0_BACKUP_ENABLE; /* Ilo HibernateOn */
    Cy_WDT_Lock();

#endif  // CY_USE_PSVP == 0u

    // CPUS_InitPeripheralClockConfig();

    CPUS_SystemCoreClockUpdate();
}
