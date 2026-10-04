/******************************************************************************/
/*@F_NAME:           cpus_tviic_2m.h                                      								                                      */
/*@F_PURPOSE:        Configuration File for CPUS Module - TEMPLATE            								   */
/*@F_CREATED_BY:     WeiLiang                                                      															   */
/*@F_CREATION_DATE:  26/08/2020                                              														   */
/*@F_LANGUAGE :      C                                                        																		   */
/*@F_MPROC_TYPE:    Cypress TraveoII                                                                                                    */
/******************************* (C) Copyright 2020 Magneti Marelli ****************/

#ifndef SYSTEM_TVIIC2D6M_H
#define SYSTEM_TVIIC2D6M_H
/*______ I N C L U D E - F I L E S ___________________________________________*/

/*______  L O C A L  - D E F I N E S _________________________________________*/

/*______  G L O B A L  - D E F I N E S _______________________________________*/
#define CPUS_ROM_CTL_SLOW_WS_0            0U
#define CPUS_ROM_CTL_SLOW_WS_1            1U
#define CPUS_ROM_CTL_FAST_WS_0              0U
#define CPUS_ROM_CTL_FAST_WS_1              1U
#define CPUS_RAM0_CTL0_SLOW_WS_0       0U/*RAMx_CTL.SLOW_WS = '0' up to 100 MHz ofclk_hf.*/
#define CPUS_RAM0_CTL0_SLOW_WS_1       1U/*RAMx_CTL.SLOW_WS = '1' from 100 MHz to 200MHz of clk_hf.*/
#define CPUS_RAM0_CTL0_FAST_WS_0          0U/*RAMx_CTL.FAST_WS = '0' up to 200 MHz of clk_hf.*/
#define CPUS_RAM0_CTL0_FAST_WS_1          1U
#define CPUS_RAM1_CTL0_SLOW_WS_0        0U/*RAMx_CTL.SLOW_WS = '0' up to 100 MHz ofclk_hf.*/
#define CPUS_RAM1_CTL0_SLOW_WS_1        1U/*RAMx_CTL.SLOW_WS = '1' from 100 MHz to 200MHz of clk_hf.*/
#define CPUS_RAM1_CTL0_FAST_WS_0          0U/*RAMx_CTL.FAST_WS = '0' up to 200 MHz of clk_hf.*/
#define CPUS_RAM1_CTL0_FAST_WS_1          1U
#define CPUS_RAM2_CTL0_SLOW_WS_0        0U/*RAMx_CTL.SLOW_WS = '0' up to 100 MHz ofclk_hf.*/
#define CPUS_RAM2_CTL0_SLOW_WS_1        1U/*RAMx_CTL.SLOW_WS = '1' from 100 MHz to 200MHz of clk_hf.*/
#define CPUS_RAM2_CTL0_FAST_WS_0          0U/*RAMx_CTL.FAST_WS = '0' up to 200 MHz of clk_hf.*/
#define CPUS_RAM2_CTL0_FAST_WS_1          1U
#define CPUS_FLASHC_FLASH_CTL_WS_0       0U/*FLASHC_FLASH_CTL.MAIN_WS = 0 for clk_hf <= 100MH*/
#define CPUS_FLASHC_FLASH_CTL_WS_1       1U/*FLASHC_FLASH_CTL.MAIN_WS = 1 for 100 MHz <clk_hf<=Fhf_max*/
/*Watch Dog Trim - Delta voltage below steady state level
0x0 - 50mV
0x1 - 75mV
0x2 - 100mV
0x3 - 125mV
0x4 -150mV
 0x5 - 175mV
 0x6 - 200mV
 0x7 - 225mV*/
#define CPUS_SRSS_CLK_ECO_CONFIG2_WDTRIM_50MV     0U
#define CPUS_SRSS_CLK_ECO_CONFIG2_WDTRIM_75MV     1U
#define CPUS_SRSS_CLK_ECO_CONFIG2_WDTRIM_100MV   2U
#define CPUS_SRSS_CLK_ECO_CONFIG2_WDTRIM_125MV   3U
#define CPUS_SRSS_CLK_ECO_CONFIG2_WDTRIM_150MV   4U
#define CPUS_SRSS_CLK_ECO_CONFIG2_WDTRIM_175MV   5U
#define CPUS_SRSS_CLK_ECO_CONFIG2_WDTRIM_200MV   6U
#define CPUS_SRSS_CLK_ECO_CONFIG2_WDTRIM_225MV   7U
/*Amplitude trim to set the crystal drive level when
ECO_CONFIG.AGC_EN=1. WARNING: use care when
setting this field because driving a crystal beyond its rated
limit can permanently damage the crystal.
0x0 - 150mV
0x1 - 175mV
0x2 - 200mV
0x3 - 225mV
0x4 - 250mV
0x5 -275mV
0x6 - 300mV
0x7 - 325mV
0x8 - 350mV
 0x9 - 375mV
0xA - 400mV
0xB - 425mV
0xC - 450mV
0xD - 475mV
0xE- 500mV
0xF - 525mV*/
#define CPUS_SRSS_CLK_ECO_CONFIG2_ATRIM_150MV     0x00U
#define CPUS_SRSS_CLK_ECO_CONFIG2_ATRIM_175MV     0x01U
#define CPUS_SRSS_CLK_ECO_CONFIG2_ATRIM_200MV     0x02U
#define CPUS_SRSS_CLK_ECO_CONFIG2_ATRIM_225MV     0x03U
#define CPUS_SRSS_CLK_ECO_CONFIG2_ATRIM_250MV     0x04U
#define CPUS_SRSS_CLK_ECO_CONFIG2_ATRIM_275MV     0x05U
#define CPUS_SRSS_CLK_ECO_CONFIG2_ATRIM_300MV     0x06U
#define CPUS_SRSS_CLK_ECO_CONFIG2_ATRIM_325MV     0x07U
#define CPUS_SRSS_CLK_ECO_CONFIG2_ATRIM_350MV     0x08U
#define CPUS_SRSS_CLK_ECO_CONFIG2_ATRIM_375MV     0x09U
#define CPUS_SRSS_CLK_ECO_CONFIG2_ATRIM_400MV     0x0AU
#define CPUS_SRSS_CLK_ECO_CONFIG2_ATRIM_425MV     0x0BU
#define CPUS_SRSS_CLK_ECO_CONFIG2_ATRIM_450MV     0x0CU
#define CPUS_SRSS_CLK_ECO_CONFIG2_ATRIM_475MV     0x0DU
#define CPUS_SRSS_CLK_ECO_CONFIG2_ATRIM_500MV     0x0EU
#define CPUS_SRSS_CLK_ECO_CONFIG2_ATRIM_525MV     0x0FU

/*Filter Trim - 3rd harmonic oscillation*/
#define CPUS_SRSS_CLK_ECO_CONFIG2_FTRIM_0     0x00U
#define CPUS_SRSS_CLK_ECO_CONFIG2_FTRIM_1     0x01U
#define CPUS_SRSS_CLK_ECO_CONFIG2_FTRIM_2     0x02U
#define CPUS_SRSS_CLK_ECO_CONFIG2_FTRIM_3     0x03U

/*Feedback resistor Trim*/
#define CPUS_SRSS_CLK_ECO_CONFIG2_RTRIM_0     0x00U/*28.6 < f*/
#define CPUS_SRSS_CLK_ECO_CONFIG2_RTRIM_1     0x01U/*23.33 < f ≤ 28.6*/
#define CPUS_SRSS_CLK_ECO_CONFIG2_RTRIM_2     0x02U/*16.5 < f ≤ 23.33*/
#define CPUS_SRSS_CLK_ECO_CONFIG2_RTRIM_3     0x03U/*f ≤ 16.5*/

/*Gain Trim - Startup time.*/
#define CPUS_SRSS_CLK_ECO_CONFIG2_GTRIM_0     0x00U/*0 ≤ gm < 2.2*/
#define CPUS_SRSS_CLK_ECO_CONFIG2_GTRIM_1     0x01U/*2.2 ≤ gm < 4.4*/
#define CPUS_SRSS_CLK_ECO_CONFIG2_GTRIM_2     0x02U/*4.4 ≤ gm < 6.6*/
#define CPUS_SRSS_CLK_ECO_CONFIG2_GTRIM_3     0x03U/*6.6 ≤ gm < 8.8*/
#define CPUS_SRSS_CLK_ECO_CONFIG2_GTRIM_4     0x04U/*8.8 ≤ gm < 11*/
#define CPUS_SRSS_CLK_ECO_CONFIG2_GTRIM_5     0x05U/*11 ≤ gm < 13.2*/
#define CPUS_SRSS_CLK_ECO_CONFIG2_GTRIM_6     0x06U/*13.2 ≤ gm < 15.4*/
#define CPUS_SRSS_CLK_ECO_CONFIG2_GTRIM_7     0x07U/*15.4 ≤ gm ≤ 17.6*/

/*Master enable for ECO oscillator. Configure the settings in
CLK_ECO_CONFIG2 to work with the selected crystal,
before enabling ECO.*/
#define CPUS_SRSS_CLK_ECO_CONFIG_ECO_EN_DISABLE          0U
#define CPUS_SRSS_CLK_ECO_CONFIG_ECO_EN_ENABLE           1U

#define CPUS_SRSS_CLK_PLL400M_CONFIG2_FRAC_EN_DISABLE     0U  /* Disabled Frac*/
#define CPUS_SRSS_CLK_PLL400M_CONFIG2_FRAC_EN_ENABLE      1U  /* Enabled Frac*/

#define CPUS_SRSS_CLK_PLL400M_CONFIG_DISABLE              0ul;
#define CPUS_SRSS_CLK_PLL400M_CONFIG_ENABLE               1ul;

#define CPUS_SRSS_CLK_PLL400M_CONFIG3_SSCG_DEPTH_05   0x029ul; /* -0.5% (down-spread) */
#define CPUS_SRSS_CLK_PLL400M_CONFIG3_SSCG_DEPTH_1     0x052ul; /*-1% (down-spread)*/
#define CPUS_SRSS_CLK_PLL400M_CONFIG3_SSCG_DEPTH_2     0x0A4ul; /*-2% (downspread)*/
#define CPUS_SRSS_CLK_PLL400M_CONFIG3_SSCG_DEPTH_3     0x0F6ul; /*-3% (down-spread)*/

#define CPUS_SRSS_CLK_PLL400M_CONFIG3_SSCG_RATE0       0U/*Modulation rate = fPFD/4096*/
#define CPUS_SRSS_CLK_PLL400M_CONFIG3_SSCG_RATE1       1U/*Modulation rate = fPFD/2048*/
#define CPUS_SRSS_CLK_PLL400M_CONFIG3_SSCG_RATE2       2U/*Modulation rate = fPFD/1024*/
#define CPUS_SRSS_CLK_PLL400M_CONFIG3_SSCG_RATE3       3U/*Modulation rate = fPFD/512*/
#define CPUS_SRSS_CLK_PLL400M_CONFIG3_SSCG_RATE4       4U/*Modulation rate = fPFD/256*/

#define CPUS_SRSS_CLK_PLL400M_CONFIG3_SSCG_DITHER_DISABLE   0U/*Disabled*/
#define CPUS_SRSS_CLK_PLL400M_CONFIG3_SSCG_DITHER_ENABLE    1U/*Enabled*/


#define CPUS_SRSS_CLK_PLL400M_CONFIG3_SSCG_MODE   0U/*Reserved. Write zero always.*/
#define CPUS_SRSS_CLK_PLL400M_CONFIG3_SSCG_DISABLE    0U/*Disabled*/
#define CPUS_SRSS_CLK_PLL400M_CONFIG3_SSCG_ENABLE     1U/*Enabled*/

#define CPUS_SRSS_CLK_PLL400M_CONFIG2_FRAC_DITHER_DISABLE    0U
#define CPUS_SRSS_CLK_PLL400M_CONFIG2_FRAC_DITHER_ENABLE     1U
#define CPUS_SRSS_CLK_PLL400M_CONFIG2_FRAC_DISABLE      0U
#define CPUS_SRSS_CLK_PLL400M_CONFIG2_FRAC_ENABLE       1U
#define CPUS_SRSS_CLK_PLL400M_CONFIG3_SSCG_DISABLE       0U
#define CPUS_SRSS_CLK_PLL400M_CONFIG3_SSCG_ENABLE        1U

/*Configures the sensitivity of the lock detection logic, according
to the intended operating mode:*/
#define CPUS_SRSS_CLK_PLL400M_CONFIG_LOCK_DELAY0       0U /*0: Integer divider without spreading*/
#define CPUS_SRSS_CLK_PLL400M_CONFIG_LOCK_DELAY1    1U/*1: Fractional division or spreading*/
/*Wait until the PLL is locked before using the output. By
default, the PLL output is bypassed to its reference clock
and will automatically switch to the PLL output when it is
locked*/
#define CPUS_SRSS_CLK_PLL400M_CONFIG_BYPASS_SEL0    0U/*Auto*/

#define CPUS_SRSS_LK_PLL400M_CONFIG_DISABLE              0U
#define CPUS_SRSS_LK_PLL400M_CONFIG_ENABLE               1U
/*fOUT = (FEEDBACK_DIV + FRAC_EN*FRAC_DIV/2ˆ24) * (fREF / REFERENCE_DIV) / (OUTPUT_DIV)*/
#define CPUS_SRSS_CLK_PLL400M_CONFIG2_FRAC_DISABLE       0U /*FRAC_EN =  0U*/
#define CPUS_SRSS_CLK_PLL400M_CONFIG2_FRAC_ENABLE        1U /*FRAC_EN =  1U*/
/*Configures the sensitivity of the lock detection logic*/
#define CPUS_SRSS_CLK_PLL_CONFIG_LOCK_DELAY0        0ul;    /* Normal operation */
#define CPUS_SRSS_CLK_PLL_CONFIG_LOCK_DELAY1        1ul;    /* reduced sensitivity to allow tracking a modulating reference clock.*/

#define CPUS_SRSS_CLK_PLL_CONFIG_PLL_LF_MODE0     0U/*VCO frequency is [200MHz, 400MHz]*/
#define CPUS_SRSS_CLK_PLL_CONFIG_PLL_LF_MODE1     1U/*VCO frequency is [170MHz, 200MHz)*/
/*Wait until the PLL is locked before using the output. By
default, the PLL output is bypassed to its reference clock
and will automatically switch to the PLL output when it is
locked*/
#define CPUS_SRSS_CLK_PLL_CONFIG_BYPASS_SEL0        0U /*Auto*/
#define CPUS_SRSS_CLK_PLL_CONFIG_DISABLE                 0U
#define CPUS_SRSS_CLK_PLL_CONFIG_ENABLE                  1U
#define CPUS_SRSS_CLK_ROOT_SELECT_DISABLE               1U
#define CPUS_SRSS_CLK_ROOT_SELECT_ENABLE                1U
#define CPUS_SRSS_CLK_ROOT_SELECT_DIRECT_MUX0   0U
#define CPUS_SRSS_CLK_ROOT_SELECT_DIRECT_MUX1   1U /* Select ROOT_MUX */

#define CPUS_SRSS_CLK_FLL_CONFIG_FLL_DISABLE              0U
#define CPUS_SRSS_CLK_FLL_CONFIG_FLL_ENABLE               1U

#define CPUS_SRSS_CLK_FLL_CONFIG4_CCO_DISABLE           0U
#define CPUS_SRSS_CLK_FLL_CONFIG4_CCO_ENABLE            1U

#define CPUS_SRSS_CLK_ILO0_CONFIG_DISABLE                    0U
#define CPUS_SRSS_CLK_ILO0_CONFIG_ENABLE                     1U

/*This register indicates that ILO0 should stay enabled during
XRES and HIBERNATE modes. If backup voltage domain
is implemented on the product, this bit also indicates
if ILO0 should stay enabled through power-related resets
on other supplies, e.g.. BOD on VDDD/VCCD. Writes
to this field are ignored unless the WDT is unlocked using
WDT_LOCK register. This register is reset when the
backup logic resets. 0: ILO0 turns off during XRES, HIBERNATE,
and power-related resets. ILO0 configuration
and trims are reset by these events. 1: ILO0 stays enabled,
as described above. ILO0 configuration and trims are not
reset by these events.*/
 #define CPUS_SRSS_CLK_ILO0_CONFIG_ILO0_BACKUP0         0ul
 #define CPUS_SRSS_CLK_ILO0_CONFIG_ILO0_BACKUP1         1ul
/*______ G L O B A L - T Y P E S _____________________________________________*/

/*______  L O C A L  - M A C R O S ___________________________________________*/

/*______ G L O B A L - M A C R O S ___________________________________________*/

/*______  L O C A L  - D A T A _______________________________________________*/

/*______ G L O B A L - D A T A _______________________________________________*/


/*______  L O C A L  - F U N C T I O N S - P R O T O T Y P E S _______________*/


/*______ G L O B A L - F U N C T I O N S - P R O T O T Y P E S _______________*/


#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

/**  Start address of the Cortex-M7_0 application */
#ifndef CPUS_CORTEX_M7_0_APPL_ADDR
    // This symbol is defined in the linker script
    extern char *  __cm7_0_vector_base_linker_symbol;
    #define CPUS_CORTEX_M7_0_APPL_ADDR      ((uint32_t) &__cm7_0_vector_base_linker_symbol)
#endif

/**  Start address of the Cortex-M7_1 application */
#ifndef CPUS_CORTEX_M7_1_APPL_ADDR
    // This symbol is defined in the linker script
    extern char *  __cm7_1_vector_base_linker_symbol;
    #define CPUS_CORTEX_M7_1_APPL_ADDR      ((uint32_t) &__cm7_1_vector_base_linker_symbol)
#endif
    

// Macro to provide a delay option
#define DELAY(loop_till)     do { for( volatile uint32_t loop_cnt = 0; loop_cnt < loop_till; loop_cnt++); } while(0)

// This cycle value should be less than 16777216 (0x01000000, 24bits)
#define DELAY_CORE_CYCLE(cycle) {\
    SysTick->CTRL = 0;\
    SysTick->LOAD = cycle;\
    SysTick->VAL  = 0;\
    SysTick->CTRL = 5;\
    while((SysTick->CTRL & 0x00010000) == 0);\
    SysTick->CTRL = 0;\
}\


/**
* \addtogroup group_system_cfg_macros
* \{
*/
#define CPUS_SYS_CM_STATUS_OFF                      (0u)    /**< The Cortex-M core is off. */
#define CPUS_SYS_CM_STATUS_RESET                  (1u)    /**< The Cortex-M core is in reset. */
#define CPUS_SYS_CM_STATUS_RETAINED          (2u)    /**< The Cortex-M core is retained. */
#define CPUS_SYS_CM_STATUS_ENABLED                (3u)    /**< The Cortex-M core is enabled */


/*******************************************************************************
* VCCD selection
*******************************************************************************/
#define CY_SYS_VCCD_INTERNAL                    (0u)
#define CY_SYS_VCCD_PMIC                        (1u)

#define CY_SYS_VCCD_SOURCE                      CY_SYS_VCCD_PMIC

/*******************************************************************************
* PLL400#0 leading to CM7 cores output frequency selection
*******************************************************************************/
#define CPUS_SYS_PLL400M_0_160MHz                 (160000000UL)
#define CPUS_SYS_PLL400M_0_250MHz                 (250000000UL)
#define CPUS_SYS_PLL400M_0_320MHz                 (320000000UL)

#define CPUS_SYS_PLL400M_0_FREQ                   CPUS_SYS_PLL400M_0_320MHz

#if (CY_SYS_VCCD_SOURCE == CY_SYS_VCCD_INTERNAL) && (CPUS_SYS_PLL400M_0_FREQ != CPUS_SYS_PLL400M_0_160MHz)
  #error "The Core 7 frequency is too high to fulfill spec for internal VCCD."
#endif

/* Do not use these definitions directly in your application */
#define CPUS_DELAY_MS_OVERFLOW_THRESHOLD          (0x8000u)
#define CPUS_DELAY_1K_THRESHOLD                   (1000u)
#define CPUS_DELAY_1K_MINUS_1_THRESHOLD           (CPUS_DELAY_1K_THRESHOLD - 1u)
#define CPUS_DELAY_1M_THRESHOLD                   (1000000u)
#define CPUS_DELAY_1M_MINUS_1_THRESHOLD           (CPUS_DELAY_1M_THRESHOLD - 1u)

#define CORE_CM7_0			                    0 // Cortex-M7 core 0
#define CORE_CM7_1			                    1 // Cortex-M7 core 1 
#define CORE_MAX			                    2 // Error Selection
    
/************************User Configurable Macro Definitions*******************/

// Macro to select the Clock Source
#define CY_SYSTEM_USE_IMO                       0
#define CY_SYSTEM_USE_EXT                       1
#define CY_SYSTEM_USE_ECO                       2

#define CY_SYSTEM_USE_CLOCK                     CY_SYSTEM_USE_ECO

// Definition of this macro disables the WDT (Enabled in SROM)
#define CPUS_SYSTEM_WDT_DISABLE

/** \} group_system_cfg_macros */

/**************************Definition of global variables**********************/

/** \addtogroup group_system_cfg_data_structures
* \{
*/
  
extern uint32_t SystemCoreClock;
extern uint32_t CPUS_delayFreqHz;
extern uint32_t cy_delayFreqKhz;
extern uint8_t  cy_delayFreqMhz;
extern uint32_t cy_delay32kMs;

/** \} group_system_cfg_data_structures */

/******************************Definition of global functions******************/

/**
* \addtogroup group_system_cfg_functions
* \{
*/

/**
  \brief Setup the microcontroller system.

   Initialize the System and update the SystemCoreClock variable.
 */
extern void     CPUS_SystemInit (void);
extern void     CPUS_StartClockTree (void);

extern uint32_t Cy_SaveIRQ(void);
extern void     Cy_RestoreIRQ(uint32_t saved);

/**
  \brief  Update SystemCoreClock variable.

   Updates the SystemCoreClock with current core Clock retrieved from cpu registers.
 */
extern void CPUS_SystemCoreClockUpdate (void);

extern void CPUS_SystemInitFpuEnable(void);

extern uint32_t CPUS_SysGetApplCoreStatus(uint8_t core);
extern void     CPUS_SysEnableApplCore(uint8_t core, uint32_t vectorTableOffset);
extern void     CPUS_SysDisableApplCore(uint8_t core);
extern void     CPUS_SysRetainApplCore(uint8_t core);
extern void     CPUS_SysResetApplCore(uint8_t core);

/** \} group_system_cfg_functions */

#ifdef __cplusplus
}
#endif

#endif /* SYSTEM_TVIIC2D6M_H */

