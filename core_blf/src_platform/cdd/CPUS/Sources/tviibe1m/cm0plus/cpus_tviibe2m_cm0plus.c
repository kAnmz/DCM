/**************************************************************************//**
 * @file     system_tviibe2m_cm0plus.c
 * @brief    CMSIS Cortex-M0+ Device Peripheral Access Layer Source File for
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
#include "cy_syswdt.h"
#include "cy_sysclk.h"
#include "cpus_config_tvii.h"
#include "bb_bsp_tviibe1m.h"
#include "cpus_tvii_1m.h"

#define CPUS_SYS_PWR_CTL_KEY_OPEN  (0x05FAUL)
#define CPUS_SYS_PWR_CTL_KEY_CLOSE (0xFA05UL)


/** Holds the SlowClk system core clock, which is the system clock frequency supplied to the SysTick timer and the
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

    CPUS_InitPeripheralClockConfig();

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
* Function Name: CPUS_SysGetApplCoreStatus
****************************************************************************//**
*
* Gets the Cortex-M4/M7 core power mode.
*
* \return \ref group_system_config_cm_status_macro
*
*******************************************************************************/
uint32_t CPUS_SysGetApplCoreStatus(void)
{
    uint32_t regValue;
    
    /* Get current power mode */
    regValue = CPUSS->unCM4_PWR_CTL.u32Register;
    regValue = (regValue >> CPUSS_CM4_PWR_CTL_PWR_MODE_Pos) & CPUSS_CM4_PWR_CTL_PWR_MODE_Msk;

    return (regValue);
}

/*******************************************************************************
* Function Name: CPUS_SysEnableApplCore
****************************************************************************//**
*
* Enables the Cortex-M4/M7 core. The CPU is enabled once if it was in the disabled
* or retained mode. 
*
* \param vectorTableOffset The offset of the vector table base address from
* memory address 0x00000000. The offset should be multiple to 1024 bytes.
*
*******************************************************************************/
void CPUS_SysEnableApplCore(uint32_t vectorTableOffset)
{
    uint32_t cmStatus;
    uint32_t interruptState;
    un_CPUSS_CM4_PWR_CTL_t tPwrCtl;

    interruptState = Cy_SaveIRQ();
    
    cmStatus = CPUS_SysGetApplCoreStatus();
    if(cmStatus == CPUS_SYS_CM_STATUS_ENABLED)
    {
        // do nothing
    }
    else
    {
        CPUSS->unCM4_VECTOR_TABLE_BASE.u32Register = vectorTableOffset;
    
        tPwrCtl.stcField.u16VECTKEYSTAT = CPUS_SYS_PWR_CTL_KEY_OPEN;
        tPwrCtl.stcField.u2PWR_MODE = CPUS_SYS_CM_STATUS_ENABLED;
        CPUSS->unCM4_PWR_CTL.u32Register = tPwrCtl.u32Register;
    }
    
    Cy_RestoreIRQ(interruptState);
}


/*******************************************************************************
* Function Name: CPUS_SysDisableApplCore
****************************************************************************//**
*
* Disables the Cortex-M4 core.
*
* \warning Do not call the function while the Cortex-M4 is executing because
* such a call may corrupt/abort a pending bus-transaction by the CPU and cause
* unexpected behavior in the system including a deadlock. Call the function
* while the Cortex-M4 core is in the Sleep or Deep Sleep low-power mode. Use
* the \ref group_syspm Power Management (syspm) API to put the CPU into the
* low-power modes. Use the \ref Cy_SysPm_ReadStatus() to get a status of the
* CPU.
*
*******************************************************************************/
void CPUS_SysDisableApplCore(void)
{
    un_CPUSS_CM4_PWR_CTL_t tPwrCtl;

    tPwrCtl.stcField.u16VECTKEYSTAT = CPUS_SYS_PWR_CTL_KEY_OPEN;
    tPwrCtl.stcField.u2PWR_MODE = CPUS_SYS_CM_STATUS_OFF;
    CPUSS->unCM4_PWR_CTL.u32Register = tPwrCtl.u32Register;  
}


/*******************************************************************************
* Function Name: CPUS_SysRetainApplCore
****************************************************************************//**
*
* Retains the Cortex-M4 core.
*
* \warning Do not call the function while the Cortex-M4 is executing because
* such a call may corrupt/abort a pending bus-transaction by the CPU and cause
* unexpected behavior in the system including a deadlock. Call the function
* while the Cortex-M4 core is in the Sleep or Deep Sleep low-power mode. Use
* the \ref group_syspm Power Management (syspm) API to put the CPU into the
* low-power modes. Use the \ref Cy_SysPm_ReadStatus() to get a status of the CPU.
*
*******************************************************************************/
void CPUS_SysRetainApplCore(void)
{
    uint32_t cmStatus;
    uint32_t  interruptState;
    un_CPUSS_CM4_PWR_CTL_t tPwrCtl;

    interruptState = Cy_SaveIRQ();
	
    cmStatus = CPUS_SysGetApplCoreStatus();
    if(cmStatus == CPUS_SYS_CM_STATUS_ENABLED)
    {
        tPwrCtl.stcField.u16VECTKEYSTAT = CPUS_SYS_PWR_CTL_KEY_OPEN;
        tPwrCtl.stcField.u2PWR_MODE = CPUS_SYS_CM_STATUS_RETAINED;
        CPUSS->unCM4_PWR_CTL.u32Register = tPwrCtl.u32Register;
    }
	
    Cy_RestoreIRQ(interruptState);
}


/*******************************************************************************
* Function Name: CPUS_SysResetApplCore
****************************************************************************//**
*
* Resets the Cortex-M4 core.
*
* \warning Do not call the function while the Cortex-M4 is executing because
* such a call may corrupt/abort a pending bus-transaction by the CPU and cause
* unexpected behavior in the system including a deadlock. Call the function
* while the Cortex-M4 core is in the Sleep or Deep Sleep low-power mode. Use
* the \ref group_syspm Power Management (syspm) API to put the CPU into the
* low-power modes. Use the \ref Cy_SysPm_ReadStatus() to get a status of the CPU.
*
*******************************************************************************/
void CPUS_SysResetApplCore(void)
{
    un_CPUSS_CM4_PWR_CTL_t tPwrCtl;

    tPwrCtl.stcField.u16VECTKEYSTAT = CPUS_SYS_PWR_CTL_KEY_OPEN;
    tPwrCtl.stcField.u2PWR_MODE = CPUS_SYS_CM_STATUS_RESET;
    CPUSS->unCM4_PWR_CTL.u32Register = tPwrCtl.u32Register;  
}

