/**************************************************************************//**
 * @file     system_tviic2d6m_cm0plus.c
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
#include "cy_sysclk.h"
#include "cy_power.h"
#include "cy_syswdt.h"
#include "cpus_tviic_6m.h"
#include "cpus_config_tviic_cm0plus.h"
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


#if ((CY_USE_PSVP == 0u) && (CY_SYS_VCCD_SOURCE == CY_SYS_VCCD_PMIC))
#define TIMING_MONZA_PMIC_ENABLE            (4)  // 0: Enable fastest timing, 8:Enable latest timing
#define WAIT_CYCLE_WHILE_DISTRIBUTING_CLOCK (50)
#endif

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
    CPUSS->unROM_CTL.stcField.u2FAST_WS = CPUS_ROM_CTL_FAST_WS_0;

    /*********** Setting wait state for RAM **********/
    CPUSS->unRAM0_CTL0.stcField.u2SLOW_WS = CPUS_RAM0_CTL0_SLOW_WS_1;
    CPUSS->unRAM0_CTL0.stcField.u2FAST_WS = CPUS_RAM0_CTL0_FAST_WS_0;

    #if defined (CPUSS_RAMC1_PRESENT) && (CPUSS_RAMC1_PRESENT == 1UL)
    CPUSS->unRAM1_CTL0.stcField.u2SLOW_WS = CPUS_RAM1_CTL0_SLOW_WS_1;
    CPUSS->unRAM1_CTL0.stcField.u2FAST_WS = CPUS_RAM1_CTL0_FAST_WS_0;
    #endif /* defined (CPUSS_RAMC1_PRESENT) && (CPUSS_RAMC1_PRESENT == 1UL) */

    #if defined (CPUSS_RAMC2_PRESENT) && (CPUSS_RAMC2_PRESENT == 1UL)
    CPUSS->unRAM2_CTL0.stcField.u2SLOW_WS = CPUS_RAM2_CTL0_SLOW_WS_1;
    CPUSS->unRAM2_CTL0.stcField.u2FAST_WS = CPUS_RAM2_CTL0_FAST_WS_0;
    #endif /* defined (CPUSS_RAMC2_PRESENT) && (CPUSS_RAMC2_PRESENT == 1UL) */

    /*********** Setting wait state for FLASH **********/
    FLASHC->unFLASH_CTL.stcField.u4WS = CPUS_FLASHC_FLASH_CTL_WS_1;

    /***    Set clock LF source        ***/
    SRSS->unCLK_SELECT.stcField.u3LFCLK_SEL = CY_SYSCLK_LFCLK_IN_ILO0;

#if CY_SYSTEM_USE_CLOCK == CY_SYSTEM_USE_ECO

    /***    ECO port settings        ***/
    /* Default settings should be OK. */

    /***    ECO setting and enabling        ***/
    // These values need to be confirmed
    SRSS->unCLK_ECO_CONFIG2.stcField.u3WDTRIM = CPUS_SRSS_CLK_ECO_CONFIG2_WDTRIM_150MV;
    SRSS->unCLK_ECO_CONFIG2.stcField.u4ATRIM  = CPUS_SRSS_CLK_ECO_CONFIG2_ATRIM_450MV;
    SRSS->unCLK_ECO_CONFIG2.stcField.u2FTRIM  = CPUS_SRSS_CLK_ECO_CONFIG2_FTRIM_3;
    SRSS->unCLK_ECO_CONFIG2.stcField.u2RTRIM  = CPUS_SRSS_CLK_ECO_CONFIG2_RTRIM_3;
    SRSS->unCLK_ECO_CONFIG2.stcField.u3GTRIM  = CPUS_SRSS_CLK_ECO_CONFIG2_GTRIM_1;
    SRSS->unCLK_ECO_CONFIG.stcField.u1ECO_EN = CPUS_SRSS_CLK_ECO_CONFIG_ECO_EN_ENABLE;
    while(SRSS->unCLK_ECO_STATUS.stcField.u1ECO_OK == 0ul);
    while(SRSS->unCLK_ECO_STATUS.stcField.u1ECO_READY == 0ul);
#endif

    /***  Set CPUSS dividers as required        ***/
    /* CLK_MEM */
    CPUSS->unMEM_CLOCK_CTL.stcField.u8INT_DIV     = CPUS_MEM_CLOCK_CTL_INT_DIV; /* no division */
    /* CLK_SLOW */
    CPUSS->unSLOW_CLOCK_CTL.stcField.u8INT_DIV    = CPUS_SLOW_CLOCK_CTL_INT_DIV; /* divided by 2 */
    /* CLK_PERI */
    CPUSS->unPERI_CLOCK_CTL.stcField.u8INT_DIV    = CPUS_PERI_CLOCK_CTL_INT_DIV; /* divided by 2 */
    /* CLK_TRC_DBG */
    CPUSS->unTRC_DBG_CLOCK_CTL.stcField.u8INT_DIV = CPUS_TRC_DBG_CLOCK_CTL_INT_DIV; /* no division*/
    // No setting for CLK_GRx requred. Initial values (no division) should be ok.
    /***     PLL setting and enabling        ***/
    /* Settings for PLL400M #0 (CLK_PATH1) */
    SRSS->unCLK_PATH_SELECT[1/*PLL400M #0*/].stcField.u3PATH_MUX = CPUS_PLL_INPUT_SOURCE;
    SRSS->CLK_PLL400M[0].unCONFIG2.stcField.u1FRAC_EN      = CPUS_SRSS_CLK_PLL400M_CONFIG2_FRAC_EN_DISABLE;     /* Disabled */
    SRSS->CLK_PLL400M[0].unCONFIG3.stcField.u10SSCG_DEPTH  = CPUS_SRSS_CLK_PLL400M_CONFIG3_SSCG_DEPTH_05; /* -0.5% (down-spread) */
    SRSS->CLK_PLL400M[0].unCONFIG3.stcField.u3SSCG_RATE    = CPUS_SRSS_CLK_PLL400M_CONFIG3_SSCG_RATE0;     /* Modulation rate = fPFD/4096 */
    SRSS->CLK_PLL400M[0].unCONFIG3.stcField.u1SSCG_DITHER_EN = CPUS_SRSS_CLK_PLL400M_CONFIG3_SSCG_DITHER_ENABLE;   /* Enabled */
    SRSS->CLK_PLL400M[0].unCONFIG3.stcField.u1SSCG_MODE    = CPUS_SRSS_CLK_PLL400M_CONFIG3_SSCG_MODE;     /* Write "0" always */
    SRSS->CLK_PLL400M[0].unCONFIG3.stcField.u1SSCG_EN      = CPUS_SRSS_CLK_PLL400M_CONFIG3_SSCG_ENABLE;

    SRSS->CLK_PLL400M[0].unCONFIG.stcField.u5REFERENCE_DIV = CPUS_PLL0_CONFIG_REFDIV;
    SRSS->CLK_PLL400M[0].unCONFIG.stcField.u8FEEDBACK_DIV  = CPUS_PLL0_CONFIG_FEEDBACKDIV;
    SRSS->CLK_PLL400M[0].unCONFIG.stcField.u5OUTPUT_DIV    = CPUS_PLL0_CONFIG_OUTDIV;
    SRSS->CLK_PLL400M[0].unCONFIG.stcField.u2LOCK_DELAY    = CPUS_SRSS_CLK_PLL400M_CONFIG_LOCK_DELAY;     /* Fractional division or spreading */
    SRSS->CLK_PLL400M[0].unCONFIG.stcField.u2BYPASS_SEL    = CPUS_SRSS_CLK_PLL400M_CONFIG_BYPASS_SEL;     /* Auto */
    SRSS->CLK_PLL400M[0].unCONFIG.stcField.u1ENABLE        = CPUS_SRSS_CLK_PLL400M_CONFIG_ENABLE;

    /* Settings for PLL400M #1 (CLK_PATH2) */
    SRSS->unCLK_PATH_SELECT[2/*PLL400M #1*/].stcField.u3PATH_MUX = CPUS_PLL_INPUT_SOURCE;

    SRSS->CLK_PLL400M[1].unCONFIG2.stcField.u24FRAC_DIV    = CPUS_PLL1_CONFIG_FB_FRAC;
    SRSS->CLK_PLL400M[1].unCONFIG2.stcField.u3FRAC_DITHER_EN  = CPUS_SRSS_CLK_PLL400M_CONFIG2_FRAC_DITHER_ENABLE; /* Enabled */
    SRSS->CLK_PLL400M[1].unCONFIG2.stcField.u1FRAC_EN      = CPUS_SRSS_CLK_PLL400M_CONFIG2_FRAC_ENABLE;    /* Enabled */
    SRSS->CLK_PLL400M[1].unCONFIG3.stcField.u1SSCG_EN      = CPUS_SRSS_CLK_PLL400M_CONFIG3_SSCG_DISABLE;    /* Disabled */

    SRSS->CLK_PLL400M[1].unCONFIG.stcField.u5REFERENCE_DIV = CPUS_PLL1_CONFIG_REFDIV;
    SRSS->CLK_PLL400M[1].unCONFIG.stcField.u8FEEDBACK_DIV  = CPUS_PLL1_CONFIG_FB_INT;
    SRSS->CLK_PLL400M[1].unCONFIG.stcField.u5OUTPUT_DIV    = CPUS_PLL1_CONFIG_OUTDIV;
    SRSS->CLK_PLL400M[1].unCONFIG.stcField.u2LOCK_DELAY    = CPUS_SRSS_CLK_PLL400M_CONFIG_LOCK_DELAY1;    /* Fractional division or spreading */
    SRSS->CLK_PLL400M[1].unCONFIG.stcField.u2BYPASS_SEL    = CPUS_SRSS_CLK_PLL400M_CONFIG_BYPASS_SEL0;    /* Auto */
    SRSS->CLK_PLL400M[1].unCONFIG.stcField.u1ENABLE        = CPUS_SRSS_LK_PLL400M_CONFIG_ENABLE;

    /* Settings for PLL400M #2 (CLK_PATH3) */
    SRSS->unCLK_PATH_SELECT[3/*PLL400M #2*/].stcField.u3PATH_MUX = CPUS_PLL_INPUT_SOURCE;

    SRSS->CLK_PLL400M[2].unCONFIG2.stcField.u1FRAC_EN      = CPUS_SRSS_CLK_PLL400M_CONFIG2_FRAC_DISABLE;     /* Disabled */
    SRSS->CLK_PLL400M[2].unCONFIG3.stcField.u10SSCG_DEPTH  = CPUS_SRSS_CLK_PLL400M_CONFIG3_SSCG_DEPTH_05; /* -0.5% (down-spread) */
    SRSS->CLK_PLL400M[2].unCONFIG3.stcField.u3SSCG_RATE    = CPUS_SRSS_CLK_PLL400M_CONFIG3_SSCG_RATE0;     /* Modulation rate = fPFD/4096 */
    SRSS->CLK_PLL400M[2].unCONFIG3.stcField.u1SSCG_DITHER_EN = CPUS_SRSS_CLK_PLL400M_CONFIG3_SSCG_DITHER_ENABLE;   /* Enabled */
    SRSS->CLK_PLL400M[2].unCONFIG3.stcField.u1SSCG_MODE    = CPUS_SRSS_CLK_PLL400M_CONFIG3_SSCG_MODE;     /* Write "0" always */
    SRSS->CLK_PLL400M[2].unCONFIG3.stcField.u1SSCG_EN      = CPUS_SRSS_CLK_PLL400M_CONFIG3_SSCG_ENABLE;

    SRSS->CLK_PLL400M[2].unCONFIG.stcField.u5REFERENCE_DIV = CPUS_PLL2_CONFIG_REFDIV;
    SRSS->CLK_PLL400M[2].unCONFIG.stcField.u8FEEDBACK_DIV  = CPUS_PLL2_CONFIG_FEEDBACKDIV;
    SRSS->CLK_PLL400M[2].unCONFIG.stcField.u5OUTPUT_DIV    = CPUS_PLL2_CONFIG_OUTDIV;
    SRSS->CLK_PLL400M[2].unCONFIG.stcField.u2LOCK_DELAY    = CPUS_SRSS_CLK_PLL400M_CONFIG_LOCK_DELAY1;     /* Fractional division or spreading */
    SRSS->CLK_PLL400M[2].unCONFIG.stcField.u2BYPASS_SEL    = CPUS_SRSS_CLK_PLL400M_CONFIG_BYPASS_SEL0;     /* Auto */
    SRSS->CLK_PLL400M[2].unCONFIG.stcField.u1ENABLE        = CPUS_SRSS_LK_PLL400M_CONFIG_ENABLE;

    /* Settings for PLL400M #3 (CLK_PATH4) */
    SRSS->unCLK_PATH_SELECT[4/*PLL400M #3*/].stcField.u3PATH_MUX = CPUS_PLL_INPUT_SOURCE;

    SRSS->CLK_PLL400M[3].unCONFIG2.stcField.u1FRAC_EN      =CPUS_SRSS_CLK_PLL400M_CONFIG2_FRAC_DISABLE;     /* Disabled */
    SRSS->CLK_PLL400M[3].unCONFIG3.stcField.u10SSCG_DEPTH  = CPUS_SRSS_CLK_PLL400M_CONFIG3_SSCG_DEPTH_05; /* -0.5% (down-spread) */
    SRSS->CLK_PLL400M[3].unCONFIG3.stcField.u3SSCG_RATE    = CPUS_SRSS_CLK_PLL400M_CONFIG3_SSCG_RATE0;     /* Modulation rate = fPFD/4096 */
    SRSS->CLK_PLL400M[3].unCONFIG3.stcField.u1SSCG_DITHER_EN = CPUS_SRSS_CLK_PLL400M_CONFIG3_SSCG_DITHER_ENABLE;   /* Enabled */
    SRSS->CLK_PLL400M[3].unCONFIG3.stcField.u1SSCG_MODE    = CPUS_SRSS_CLK_PLL400M_CONFIG3_SSCG_MODE;     /* Write "0" always */
    SRSS->CLK_PLL400M[3].unCONFIG3.stcField.u1SSCG_EN      = CPUS_SRSS_CLK_PLL400M_CONFIG3_SSCG_ENABLE;

    SRSS->CLK_PLL400M[3].unCONFIG.stcField.u5REFERENCE_DIV = CPUS_PLL3_CONFIG_REFDIV;
    SRSS->CLK_PLL400M[3].unCONFIG.stcField.u8FEEDBACK_DIV  = CPUS_PLL3_CONFIG_FEEDBACKDIV;
    SRSS->CLK_PLL400M[3].unCONFIG.stcField.u5OUTPUT_DIV    = CPUS_PLL3_CONFIG_OUTDIV;
    SRSS->CLK_PLL400M[3].unCONFIG.stcField.u2LOCK_DELAY    = CPUS_SRSS_CLK_PLL400M_CONFIG_LOCK_DELAY1;     /* Fractional division or spreading */
    SRSS->CLK_PLL400M[3].unCONFIG.stcField.u2BYPASS_SEL    = CPUS_SRSS_CLK_PLL400M_CONFIG_BYPASS_SEL0;     /* Auto */
    SRSS->CLK_PLL400M[3].unCONFIG.stcField.u1ENABLE        = CPUS_SRSS_LK_PLL400M_CONFIG_ENABLE;

    /* Settings for PLL400M #4 (CLK_PATH5) */
    SRSS->unCLK_PATH_SELECT[5/*PLL400M #4*/].stcField.u3PATH_MUX = CPUS_PLL_INPUT_SOURCE;

    SRSS->CLK_PLL400M[4].unCONFIG2.stcField.u1FRAC_EN      = CPUS_SRSS_CLK_PLL400M_CONFIG2_FRAC_DISABLE;     /* Disabled */
    SRSS->CLK_PLL400M[4].unCONFIG3.stcField.u10SSCG_DEPTH  = CPUS_SRSS_CLK_PLL400M_CONFIG3_SSCG_DEPTH_05; /* -0.5% (down-spread) */
    SRSS->CLK_PLL400M[4].unCONFIG3.stcField.u3SSCG_RATE    = CPUS_SRSS_CLK_PLL400M_CONFIG3_SSCG_RATE0;     /* Modulation rate = fPFD/4096 */
    SRSS->CLK_PLL400M[4].unCONFIG3.stcField.u1SSCG_DITHER_EN = CPUS_SRSS_CLK_PLL400M_CONFIG3_SSCG_DITHER_ENABLE;   /* Enabled */
    SRSS->CLK_PLL400M[4].unCONFIG3.stcField.u1SSCG_MODE    = CPUS_SRSS_CLK_PLL400M_CONFIG3_SSCG_MODE;     /* Write "0" always */
    SRSS->CLK_PLL400M[4].unCONFIG3.stcField.u1SSCG_EN      = CPUS_SRSS_CLK_PLL400M_CONFIG3_SSCG_ENABLE;

    SRSS->CLK_PLL400M[4].unCONFIG.stcField.u5REFERENCE_DIV = CPUS_PLL4_CONFIG_REFDIV;
    SRSS->CLK_PLL400M[4].unCONFIG.stcField.u8FEEDBACK_DIV  = CPUS_PLL4_CONFIG_FEEDBACKDIV;
    SRSS->CLK_PLL400M[4].unCONFIG.stcField.u5OUTPUT_DIV    = CPUS_PLL4_CONFIG_OUTDIV;
    SRSS->CLK_PLL400M[4].unCONFIG.stcField.u2LOCK_DELAY    = CPUS_SRSS_CLK_PLL400M_CONFIG_LOCK_DELAY1;     /* Fractional division or spreading */
    SRSS->CLK_PLL400M[4].unCONFIG.stcField.u2BYPASS_SEL    = CPUS_SRSS_CLK_PLL400M_CONFIG_BYPASS_SEL0;     /* Auto */
    SRSS->CLK_PLL400M[4].unCONFIG.stcField.u1ENABLE        = CPUS_SRSS_LK_PLL400M_CONFIG_ENABLE;


    /* Settings for PLL200 #0 (CLK_PATH6) */
    SRSS->unCLK_PATH_SELECT[6/*PLL200 #0*/].stcField.u3PATH_MUX = CPUS_PLL_INPUT_SOURCE;

    SRSS->unCLK_PLL_CONFIG[0].stcField.u7FEEDBACK_DIV      = CPUS_PLL5_CONFIG_FEEDBACKDIV;
    SRSS->unCLK_PLL_CONFIG[0].stcField.u5REFERENCE_DIV     = CPUS_PLL5_CONFIG_REFDIV;
    SRSS->unCLK_PLL_CONFIG[0].stcField.u5OUTPUT_DIV        = CPUS_PLL5_CONFIG_OUTDIV;
    SRSS->unCLK_PLL_CONFIG[0].stcField.u2LOCK_DELAY        = CPUS_SRSS_CLK_PLL_CONFIG_LOCK_DELAY0;    /* Normal operation */
    SRSS->unCLK_PLL_CONFIG[0].stcField.u1PLL_LF_MODE       = CPUS_SRSS_CLK_PLL_CONFIG_PLL_LF_MODE0;    /* VCO frequency is [200MHz, 400MHz] Fvco = 400,000,000[Hz] */
    SRSS->unCLK_PLL_CONFIG[0].stcField.u2BYPASS_SEL        = CPUS_SRSS_CLK_PLL_CONFIG_BYPASS_SEL0;    /* Auto */
    SRSS->unCLK_PLL_CONFIG[0].stcField.u1ENABLE            = CPUS_SRSS_CLK_PLL_CONFIG_ENABLE;

    /* Settings for PLL200 #1 (CLK_PATH7) */
    SRSS->unCLK_PATH_SELECT[7/*PLL200 #1*/].stcField.u3PATH_MUX = CPUS_PLL_INPUT_SOURCE;

    SRSS->unCLK_PLL_CONFIG[1].stcField.u7FEEDBACK_DIV      = CPUS_PLL6_CONFIG_FEEDBACKDIV;
    SRSS->unCLK_PLL_CONFIG[1].stcField.u5REFERENCE_DIV     = CPUS_PLL6_CONFIG_REFDIV;
    SRSS->unCLK_PLL_CONFIG[1].stcField.u5OUTPUT_DIV        = CPUS_PLL6_CONFIG_OUTDIV;
    SRSS->unCLK_PLL_CONFIG[1].stcField.u2LOCK_DELAY        = CPUS_SRSS_CLK_PLL_CONFIG_LOCK_DELAY0;    /* Normal operation */
    SRSS->unCLK_PLL_CONFIG[1].stcField.u1PLL_LF_MODE       = CPUS_SRSS_CLK_PLL_CONFIG_PLL_LF_MODE0;    /* VCO frequency is [200MHz, 400MHz] Fvco = 240,000,000[Hz] */
    SRSS->unCLK_PLL_CONFIG[1].stcField.u2BYPASS_SEL        = CPUS_SRSS_CLK_PLL_CONFIG_BYPASS_SEL0;    /* Auto */
    SRSS->unCLK_PLL_CONFIG[1].stcField.u1ENABLE            = CPUS_SRSS_CLK_PLL_CONFIG_ENABLE;

    /* Settings for PLL200 #2 (CLK_PATH8) */
    SRSS->unCLK_PATH_SELECT[8/*PLL200 #2*/].stcField.u3PATH_MUX = CPUS_PLL_INPUT_SOURCE;

    SRSS->unCLK_PLL_CONFIG[2].stcField.u7FEEDBACK_DIV      = CPUS_PLL7_CONFIG_FEEDBACKDIV;
    SRSS->unCLK_PLL_CONFIG[2].stcField.u5REFERENCE_DIV     = CPUS_PLL7_CONFIG_REFDIV;
    SRSS->unCLK_PLL_CONFIG[2].stcField.u5OUTPUT_DIV        = CPUS_PLL7_CONFIG_OUTDIV;
    SRSS->unCLK_PLL_CONFIG[2].stcField.u2LOCK_DELAY        = CPUS_SRSS_CLK_PLL_CONFIG_LOCK_DELAY0;    /* Normal operation */
    SRSS->unCLK_PLL_CONFIG[2].stcField.u1PLL_LF_MODE       = CPUS_SRSS_CLK_PLL_CONFIG_PLL_LF_MODE0;    /* VCO frequency is [200MHz, 400MHz] Fvco = 240,000,000[Hz] */
    SRSS->unCLK_PLL_CONFIG[2].stcField.u2BYPASS_SEL        = CPUS_SRSS_CLK_PLL_CONFIG_BYPASS_SEL0;    /* Auto */
    SRSS->unCLK_PLL_CONFIG[2].stcField.u1ENABLE            = CPUS_SRSS_CLK_PLL_CONFIG_ENABLE;

    /* Waiting for all PLLs being locked */
    while(SRSS->CLK_PLL400M[0].unSTATUS.stcField.u1LOCKED == 0ul);
    while(SRSS->CLK_PLL400M[1].unSTATUS.stcField.u1LOCKED == 0ul);
    while(SRSS->CLK_PLL400M[2].unSTATUS.stcField.u1LOCKED == 0ul);
    while(SRSS->CLK_PLL400M[3].unSTATUS.stcField.u1LOCKED == 0ul);
    while(SRSS->CLK_PLL400M[4].unSTATUS.stcField.u1LOCKED == 0ul);
    while(SRSS->unCLK_PLL_STATUS[0].stcField.u1LOCKED == 0ul);
    while(SRSS->unCLK_PLL_STATUS[1].stcField.u1LOCKED == 0ul);
    while(SRSS->unCLK_PLL_STATUS[2].stcField.u1LOCKED == 0ul);

    /***   Setting  PATH9  source        ***/
    SRSS->unCLK_PATH_SELECT[9].stcField.u3PATH_MUX = CY_SYSCLK_CLKPATH_IN_IMO;

#if (CY_SYS_VCCD_SOURCE == CY_SYS_VCCD_PMIC)
    /* Restriction 1. Enabling MONZA PMIC when the current comsumption is from 20 [mA] to 300 [mA]
                    Please adjust "TIMING_MONZA_PMIC_ENABLE" defined above.
     Restriction 2. The current rising time has to be more than 10 [us]
                   Please adjust "WAIT_CYCLE_WHILE_DISTRIBUTING_CLOCK" defined above.*/
    for(int8_t i_clkHfNo = 0ul; i_clkHfNo < SRSS_NUM_HFROOT; i_clkHfNo++)
    {
        if(i_clkHfNo == TIMING_MONZA_PMIC_ENABLE)
        {
            /***   Enabling MONZA PMIC     ***/
            Cy_Power_SwitchToPmic(CY_SYSPMIC_VADJ_1V150, CY_POWER_PMIC_ENABLE_HIGH, CY_POWER_PMIC_STATUS_ABNORMAL_LOW, 0u, false);
        }
        SRSS->unCLK_ROOT_SELECT[i_clkHfNo].stcField.u4ROOT_MUX   = Cpus_ClkHfSetting[i_clkHfNo].source;
        SRSS->unCLK_ROOT_SELECT[i_clkHfNo].stcField.u2ROOT_DIV   = CPUS_SRSS_CLK_ROOT_SELECT_ROOT_DIV; /* divide by 8 */
        SRSS->unCLK_ROOT_SELECT[i_clkHfNo].stcField.u1DIRECT_MUX = CPUS_SRSS_CLK_ROOT_SELECT_DIRECT_MUX1; /* Select ROOT_MUX */
        SRSS->unCLK_ROOT_SELECT[i_clkHfNo].stcField.u1ENABLE     = CPUS_SRSS_CLK_ROOT_SELECT_ENABLE; /*enable*/
        for(int8_t i_divRegValue = 2; i_divRegValue >= Cpus_ClkHfSetting[i_clkHfNo].targetDivRegVal; i_divRegValue--)
        {
            Cy_SysTick_DelayCoreCycle(WAIT_CYCLE_WHILE_DISTRIBUTING_CLOCK);
            SRSS->unCLK_ROOT_SELECT[i_clkHfNo].stcField.u2ROOT_DIV = i_divRegValue;
        }
        Cy_SysTick_DelayCoreCycle(WAIT_CYCLE_WHILE_DISTRIBUTING_CLOCK);
    }
#else
    for(int8_t i_clkHfNo = 0ul; i_clkHfNo < SRSS_NUM_HFROOT; i_clkHfNo++)
    {
        SRSS->unCLK_ROOT_SELECT[i_clkHfNo].stcField.u4ROOT_MUX   = Cpus_ClkHfSetting[i_clkHfNo].source;
        SRSS->unCLK_ROOT_SELECT[i_clkHfNo].stcField.u2ROOT_DIV   = Cpus_ClkHfSetting[i_clkHfNo].targetDivRegVal; /* divide by 8 */
        SRSS->unCLK_ROOT_SELECT[i_clkHfNo].stcField.u1DIRECT_MUX = CPUS_SRSS_CLK_ROOT_SELECT_DIRECT_MUX1; /* Select ROOT_MUX */
        SRSS->unCLK_ROOT_SELECT[i_clkHfNo].stcField.u1ENABLE     = CPUS_SRSS_CLK_ROOT_SELECT_ENABLE; /* 1 = enable */
    }
#endif
    /* CLK_FAST_0 */
    CPUSS->unFAST_0_CLOCK_CTL.stcField.u8INT_DIV  = CPUS_FAST_0_CLOCK_CTL_INT_DIV; /* no division */
    CPUSS->unFAST_0_CLOCK_CTL.stcField.u5FRAC_DIV = CPUS_FAST_0_CLOCK_CTL_FRAC_DIV; /* no division */
    /* CLK_FAST_1 */
    CPUSS->unFAST_1_CLOCK_CTL.stcField.u8INT_DIV  = CPUS_FAST_1_CLOCK_CTL_INT_DIV; /* no division */
    CPUSS->unFAST_1_CLOCK_CTL.stcField.u5FRAC_DIV = CPUS_FAST_1_CLOCK_CTL_FRAC_DIV; /* no division */
    /***     FLL  disabling        ***/
    /* Disable Fll */
    SRSS->unCLK_FLL_CONFIG.stcField.u1FLL_ENABLE = CPUS_SRSS_CLK_FLL_CONFIG_FLL_DISABLE;     /* 0 = disable */
    SRSS->unCLK_FLL_CONFIG4.stcField.u1CCO_ENABLE = CPUS_SRSS_CLK_FLL_CONFIG4_CCO_DISABLE;    /* 0 = disable */
    /***     Enabling ILO0        ***/
    Cy_WDT_Unlock();
    SRSS->unCLK_ILO0_CONFIG.stcField.u1ENABLE = CPUS_SRSS_CLK_ILO0_CONFIG_ENABLE;        /* 1 = enable */
    SRSS->unCLK_ILO0_CONFIG.stcField.u1ILO0_BACKUP = CPUS_SRSS_CLK_ILO0_CONFIG_ILO0_BACKUP1; /* Ilo HibernateOn */
    Cy_WDT_Lock();

#else
    /* Settings for PLL400M #0 (CLK_PATH1) */
    SRSS->CLK_PLL400M[0].unCONFIG.stcField.u1ENABLE = 1ul;      /* For PSVP, PLL#0 should be enabled to switch from 8MHz(IMO) to 24MHz */
    
    /* Configure all CLK_HFx to use the 24 MHz from this PLL */
    for(int8_t i_clkHfNo = 0ul; i_clkHfNo < SRSS_NUM_HFROOT; i_clkHfNo++)
    {
        SRSS->unCLK_ROOT_SELECT[i_clkHfNo].stcField.u4ROOT_MUX   = CY_SYSCLK_HFCLK_IN_CLKPATH1 /* PLL0: PLL400#0 */;
        SRSS->unCLK_ROOT_SELECT[i_clkHfNo].stcField.u2ROOT_DIV   = 0u;                         /* divide by 1 */
        SRSS->unCLK_ROOT_SELECT[i_clkHfNo].stcField.u1DIRECT_MUX = CPUS_SRSS_CLK_ROOT_SELECT_DIRECT_MUX1;                         /* Select ROOT_MUX */
        SRSS->unCLK_ROOT_SELECT[i_clkHfNo].stcField.u1ENABLE     = CPUS_SRSS_CLK_ROOT_SELECT_ENABLE;                         /* 1 = enable */
    }
    
#endif  // CY_USE_PSVP == 0u

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
uint32_t CPUS_SysGetApplCoreStatus(uint8_t core)
{
    uint32_t regValue;
    
    CY_ASSERT(core < CORE_MAX);

    if(core == CORE_CM7_0)
    {
        /* Get current power mode */
        regValue = CPUSS->unCM7_0_PWR_CTL.u32Register;
        regValue = (regValue >> CPUSS_CM7_0_PWR_CTL_PWR_MODE_Pos) & CPUSS_CM7_0_PWR_CTL_PWR_MODE_Msk;
    }
    else if(core == CORE_CM7_1)
    {
        /* Get current power mode */
        regValue = CPUSS->unCM7_1_PWR_CTL.u32Register;
        regValue = (regValue >> CPUSS_CM7_1_PWR_CTL_PWR_MODE_Pos) & CPUSS_CM7_1_PWR_CTL_PWR_MODE_Msk;
    }

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
void CPUS_SysEnableApplCore(uint8_t core, uint32_t vectorTableOffset)
{
    uint32_t cmStatus;
    uint32_t interruptState;
    un_CPUSS_CM7_0_PWR_CTL_t tPwrCtl0;
    un_CPUSS_CM7_1_PWR_CTL_t tPwrCtl1; 
    
    CY_ASSERT(core < CORE_MAX);

    interruptState = Cy_SaveIRQ();
    
    cmStatus = CPUS_SysGetApplCoreStatus(core);
    if(cmStatus == CPUS_SYS_CM_STATUS_ENABLED)
    {
        // Set core into reset first, so that new settings can get effective
        // This branch is e.g. entered if a debugger is connected that would power-up the CM7,
        // but let it run in ROM boot or pause its execution by keeping CPU_WAIT bit set.
    	CPUS_SysResetApplCore(core);
    }
    
    // CLK_HF1, by default is disabled for use by CM7_0/1, hence enable
    SRSS->unCLK_ROOT_SELECT[1].stcField.u1ENABLE = 1;
        
    if(core == CORE_CM7_0)
    {           
        // Adjust the vector address
        CPUSS->unCM7_0_VECTOR_TABLE_BASE.u32Register = vectorTableOffset;
        
        // Enable the Power Control Key
        tPwrCtl0.stcField.u16VECTKEYSTAT = CPUS_SYS_PWR_CTL_KEY_OPEN;
        tPwrCtl0.stcField.u2PWR_MODE = CPUS_SYS_CM_STATUS_ENABLED;
        CPUSS->unCM7_0_PWR_CTL.u32Register = tPwrCtl0.u32Register;
        
        CPUSS->unCM7_0_CTL.stcField.u1CPU_WAIT = 0;
    } 
    else if(core == CORE_CM7_1)
    {            
        // Adjust the vector address
        CPUSS->unCM7_1_VECTOR_TABLE_BASE.u32Register = vectorTableOffset;
        
        // Enable the Power Control Key
        tPwrCtl1.stcField.u16VECTKEYSTAT = CPUS_SYS_PWR_CTL_KEY_OPEN;
        tPwrCtl1.stcField.u2PWR_MODE = CPUS_SYS_CM_STATUS_ENABLED;
        CPUSS->unCM7_1_PWR_CTL.u32Register = tPwrCtl1.u32Register;
        
        CPUSS->unCM7_1_CTL.stcField.u1CPU_WAIT = 0;
    }
    
    Cy_RestoreIRQ(interruptState);
}


/*******************************************************************************
* Function Name: CPUS_SysDisableApplCore
****************************************************************************//**
*
* Disables the Cortex-M4/M7 core.
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
void CPUS_SysDisableApplCore(uint8_t core)
{
    un_CPUSS_CM7_0_PWR_CTL_t tPwrCtl0;
    un_CPUSS_CM7_1_PWR_CTL_t tPwrCtl1; 

    CY_ASSERT(core < CORE_MAX);

    if(core == CORE_CM7_0)
    {
        tPwrCtl0.stcField.u16VECTKEYSTAT = CPUS_SYS_PWR_CTL_KEY_OPEN;
        tPwrCtl0.stcField.u2PWR_MODE = CPUS_SYS_CM_STATUS_OFF;
        CPUSS->unCM7_0_PWR_CTL.u32Register = tPwrCtl0.u32Register; 
    }
    else if(core == CORE_CM7_1)
    {
        tPwrCtl1.stcField.u16VECTKEYSTAT = CPUS_SYS_PWR_CTL_KEY_OPEN;
        tPwrCtl1.stcField.u2PWR_MODE = CPUS_SYS_CM_STATUS_OFF;
        CPUSS->unCM7_1_PWR_CTL.u32Register = tPwrCtl1.u32Register; 
    }
}


/*******************************************************************************
* Function Name: CPUS_SysRetainApplCore
****************************************************************************//**
*
* Retains the Cortex-M4/M7 core.
*
* \warning Do not call the function while the Cortex-M4 is executing because
* such a call may corrupt/abort a pending bus-transaction by the CPU and cause
* unexpected behavior in the system including a deadlock. Call the function
* while the Cortex-M4 core is in the Sleep or Deep Sleep low-power mode. Use
* the \ref group_syspm Power Management (syspm) API to put the CPU into the
* low-power modes. Use the \ref Cy_SysPm_ReadStatus() to get a status of the CPU.
*
*******************************************************************************/
void CPUS_SysRetainApplCore(uint8_t core)
{
    uint32_t cmStatus;
    uint32_t  interruptState;
    un_CPUSS_CM7_0_PWR_CTL_t tPwrCtl0;
    un_CPUSS_CM7_1_PWR_CTL_t tPwrCtl1; 

    interruptState = Cy_SaveIRQ();
    
    cmStatus = CPUS_SysGetApplCoreStatus(core);
    if(cmStatus == CPUS_SYS_CM_STATUS_ENABLED)
    {
        if(core == CORE_CM7_0)
        {
            tPwrCtl0.stcField.u16VECTKEYSTAT = CPUS_SYS_PWR_CTL_KEY_OPEN;
            tPwrCtl0.stcField.u2PWR_MODE = CPUS_SYS_CM_STATUS_RETAINED;
            CPUSS->unCM7_0_PWR_CTL.u32Register = tPwrCtl0.u32Register;
        }
        else if(core == CORE_CM7_1)
        {
            tPwrCtl1.stcField.u16VECTKEYSTAT = CPUS_SYS_PWR_CTL_KEY_OPEN;
            tPwrCtl1.stcField.u2PWR_MODE = CPUS_SYS_CM_STATUS_RETAINED;
            CPUSS->unCM7_1_PWR_CTL.u32Register = tPwrCtl1.u32Register;
        }
    }
    
    Cy_RestoreIRQ(interruptState);
}


/*******************************************************************************
* Function Name: CPUS_SysResetApplCore
****************************************************************************//**
*
* Resets the Cortex-M4/M7 core.
*
* \warning Do not call the function while the Cortex-M4 is executing because
* such a call may corrupt/abort a pending bus-transaction by the CPU and cause
* unexpected behavior in the system including a deadlock. Call the function
* while the Cortex-M4 core is in the Sleep or Deep Sleep low-power mode. Use
* the \ref group_syspm Power Management (syspm) API to put the CPU into the
* low-power modes. Use the \ref Cy_SysPm_ReadStatus() to get a status of the CPU.
*
*******************************************************************************/
void CPUS_SysResetApplCore(uint8_t core)
{
    un_CPUSS_CM7_0_PWR_CTL_t tPwrCtl0;
    un_CPUSS_CM7_1_PWR_CTL_t tPwrCtl1; 
    
    CY_ASSERT(core < CORE_MAX);

    if(core == CORE_CM7_0)
    {
        tPwrCtl0.stcField.u16VECTKEYSTAT = CPUS_SYS_PWR_CTL_KEY_OPEN;
        tPwrCtl0.stcField.u2PWR_MODE = CPUS_SYS_CM_STATUS_RESET;
        CPUSS->unCM7_0_PWR_CTL.u32Register = tPwrCtl0.u32Register; 
    }
    else if(core == CORE_CM7_1)
    {
        tPwrCtl1.stcField.u16VECTKEYSTAT = CPUS_SYS_PWR_CTL_KEY_OPEN;
        tPwrCtl1.stcField.u2PWR_MODE = CPUS_SYS_CM_STATUS_RESET;
        CPUSS->unCM7_1_PWR_CTL.u32Register = tPwrCtl1.u32Register; 
    }
}

