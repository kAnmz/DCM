/**************************************************************************//**
 * @file     system_tviic2d6m_cm7.c
 * @brief    CMSIS Cortex-M7 Device Peripheral Access Layer Source File for
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
#include "sysclk/cy_sysclk.h"
#include "syslib/cy_syslib.h"
#include "cpus_config_tviic.h"

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

uint32_t CPUS_delayFreqHz   = 0UL;

uint32_t cy_delayFreqKhz  = 0UL;

uint8_t cy_delayFreqMhz   = 0UL;

uint32_t cy_delay32kMs    = 0UL;


/*******************************************************************************
* Function Name: CPUS_SystemInit
****************************************************************************//**
*
* Initializes the system
*
*******************************************************************************/
void CPUS_SystemInit (void)
{
    // Ensure cache coherency (e.g. in case ROM-to-RAM copy of code sections happened during startup)
    SCB_CleanInvalidateDCache();
    SCB_InvalidateICache();
    
    CPUS_SystemCoreClockUpdate();
}

/*******************************************************************************
* Function Name: CPUS_SystemCoreClockUpdate
****************************************************************************//**
*
* Updates variables with current clock settings
*
*******************************************************************************/
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

/*******************************************************************************
* Function Name: CPUS_SystemInitFpuEnable
****************************************************************************//**
*
* Enables the FPU if it is used. The function is called from the startup file.
*
*******************************************************************************/
void CPUS_SystemInitFpuEnable(void)
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

