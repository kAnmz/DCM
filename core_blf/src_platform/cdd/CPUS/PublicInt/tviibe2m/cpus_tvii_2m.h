/******************************************************************************/
/*@F_NAME:           cpus_tvii_2m.h                                      								                                     	   */
/*@F_PURPOSE:        Configuration File for CPUS Module - TEMPLATE            								   */
/*@F_CREATED_BY:     WeiLiang                                                      															   */
/*@F_CREATION_DATE:  26/08/2020                                              														   */
/*@F_LANGUAGE :      C                                                        																		   */
/*@F_MPROC_TYPE:    Cypress TraveoII                                                                                                    */
/******************************* (C) Copyright 2020 Magneti Marelli ****************/

#ifndef CPUS_TVII_2M_H
#define CPUS_TVII_2M_H

/*______ I N C L U D E - F I L E S ___________________________________________*/
#include "stdint.h"
#include "cpus_config_tvii_cm0plus.h"

/*______  L O C A L  - D E F I N E S _________________________________________*/
    /*Definition of this macro disables the WDT (Enabled in SROM)*/
    #define CPUS_SYSTEM_WDT_DISABLE

/*______  G L O B A L  - D E F I N E S _________________________________________*/
#define CPUS_ROM_CTL_SLOW_WS_0     0U    /*CPUSS_ROM_CTL.SLOW_WS = ‘0’ up to 100 MHz of CLK_HF*/
#define CPUS_ROM_CTL_SLOW_WS_1     1U   /*CPUSS_ROM_CTL.SLOW_WS = ‘1’ from 100 MHz to 160 MHz CLK_HF*/
#define CPUS_ROM_CTL_FAST_WS0          0U   /*CPUSS_ROM_CTL.FAST_WS = ‘0’ up to 160 MHz of CLK_HF*/
#define CPUS_RAMx_CTL0_SLOW_WS0    0U  /*CPUSS_RAMx_CTL0.SLOW_WS = '0' up to 100MHz of clk_hf*/
#define CPUS_RAMx_CTL0_SLOW_WS1    1U  /*CPUSS_RAMx_CTL0.SLOW_WS = '1' from 100MHz to 160 MHz of clk_hf.*/
#define CPUS_RAMx_CTL0_FAST_WS0       0U /*CPUSS_RAMx_CTL0.FAST_WS = '0' up to 160MHz of clk_hf.*/
#define CPUS_FLASHC_FLASH_CTL_MAIN_WS0     0U /*FLASHC_FLASH_CTL.MAIN_WS = 0 for CLK_HF0 <= 100 MH*/
#define CPUS_FLASHC_FLASH_CTL_MAIN_WS1     1U /*FLASHC_FLASH_CTL.MAIN_WS = 1 for 100 MHz <CLK_HF0 <= Fhf_max*/

#define CPUS_WATCHDOG_TRIM_50MV			    0u
#define CPUS_WATCHDOG_TRIM_75mv			    1u
#define CPUS_WATCHDOG_TRIM_100mv			2u
#define CPUS_WATCHDOG_TRIM_125mv			3u
#define CPUS_WATCHDOG_TRIM_150mv			4u
#define CPUS_WATCHDOG_TRIM_175mv			5u
#define CPUS_WATCHDOG_TRIM_200mv			6u
#define CPUS_WATCHDOG_TRIM_225mv			7u

#define CPUS_AMPLITITUDE_TRIM_150MV			0x00u
#define CPUS_AMPLITITUDE_TRIM_175MV			0x01u
#define CPUS_AMPLITITUDE_TRIM_200MV			0x02u
#define CPUS_AMPLITITUDE_TRIM_225MV			0x03u
#define CPUS_AMPLITITUDE_TRIM_250MV			0x04u
#define CPUS_AMPLITITUDE_TRIM_275MV			0x05u
#define CPUS_AMPLITITUDE_TRIM_300MV			0x06u
#define CPUS_AMPLITITUDE_TRIM_325MV			0x07u
#define CPUS_AMPLITITUDE_TRIM_350MV			0x08u
#define CPUS_AMPLITITUDE_TRIM_375MV			0x09u
#define CPUS_AMPLITITUDE_TRIM_400MV			0x0Au
#define CPUS_AMPLITITUDE_TRIM_425MV			0x0Bu
#define CPUS_AMPLITITUDE_TRIM_450MV			0x0Cu
#define CPUS_AMPLITITUDE_TRIM_475MV			0x0Du
#define CPUS_AMPLITITUDE_TRIM_500MV			0x0Eu
#define CPUS_AMPLITITUDE_TRIM_525MV			0x0Fu


#define CPUS_FILTER_TRIM0			0x00u
#define CPUS_FILTER_TRIM1			0x01u
#define CPUS_FILTER_TRIM2			0x02u
#define CPUS_FILTER_TRIM3			0x03u

#define CPUS_FEEDBACK_RES_TRIM0  0x00u    /*28.6MHz < f*/
#define CPUS_FEEDBACK_RES_TRIM1  0x01u    /*23.33MHz < f ≤ 28.6MHz*/
#define CPUS_FEEDBACK_RES_TRIM2  0x02u    /*16.5MHz < f ≤ 23.33MHz*/
#define CPUS_FEEDBACK_RES_TRIM3  0x03u    /*f ≤ 16.5MHz*/

#define CPUS_GAIN_TRIM0  0x00u      /*0mA/V ≤ gm < 2.2mA/V*/
#define CPUS_GAIN_TRIM1  0x01u      /*2.2mA/V ≤ gm < 4.4mA/V*/
#define CPUS_GAIN_TRIM2  0x02u      /*4.4mA/V ≤ gm < 6.6mA/V*/
#define CPUS_GAIN_TRIM3  0x03u      /*6.6mA/V ≤ gm < 8.8mA/V*/
#define CPUS_GAIN_TRIM4  0x04u      /*8.8mA/V ≤ gm < 11mA/V*/
#define CPUS_GAIN_TRIM5  0x05u      /*11mA/V ≤ gm < 13.2mA/V*/
#define CPUS_GAIN_TRIM6  0x06u      /*13.2mA/V ≤ gm < 15.4mA/V*/
#define CPUS_GAIN_TRIM7  0x07u      /*15.4mA/V ≤ gm ≤ 17.6mA/V*/

#define CPUS_CLK_ECO_DISABLE   0U   /*Enabled  ECO*/
#define CPUS_CLK_ECO_ENABLE    1U   /*Disabled  ECO*/


#define CPUS_CLK_PLL_DISABLE    0U  /*Disabled  PLL*/
#define CPUS_CLK_PLL_ENABLE     1U  /*Enabled  PLL*/

#define CPUS_CLK_FLL_DISABLE    0U  /*Disabled  FLL*/
#define CPUS_CLK_FLL_ENABLE     1U  /*Enabled  FLL*/

#define CPUS_CLK_CCO_DISABLE    0U  /*Disabled  CCO*/
#define CPUS_CLK_CCO_ENABLE     1U  /*Enabled  CCO*/

#define CPUS_CLK_IO0_DISABLE    0U  /*Disabled  IO0*/
#define CPUS_CLK_IO0_ENABLE     1U  /*Enabled  IO0*/

#define CPUS_CLK_ILO0_BACKUP_DISABLE   0U /*ILO0 turns off during XRES, HIBERNATE, and power-related resets. ILO0 configuration and trims are reset by these events*/
#define CPUS_CLK_ILO0_BACKUP_ENABLE    1U /*ILO0 stays enabled, as described above. ILO0 configuration and trims are not reset by these events.*/

#define CPUS_CLK_ROOT_SELECT_DISABLE    0U  /*Disabled clock root*/
#define CPUS_CLK_ROOT_SELECT_ENABLE     1U  /*Enabled clock root*/


/******************************************Follow definition is from cypress*******************************************/
/**
* \addtogroup group_system_cfg_macros
* \{
*/
#define CPUS_SYS_CM_STATUS_OFF                    (0u)    /**< The Cortex-M core is off. */
#define CPUS_SYS_CM_STATUS_RESET                  (1u)    /**< The Cortex-M core is in reset. */
#define CPUS_SYS_CM_STATUS_RETAINED               (2u)    /**< The Cortex-M core is retained. */
#define CPUS_SYS_CM_STATUS_ENABLED                (3u)    /**< The Cortex-M core is enabled */

/* Do not use these definitions directly in your application */
#define CPUS_DELAY_MS_OVERFLOW_THRESHOLD          (0x8000u)
#define CPUS_DELAY_1K_THRESHOLD                   (1000u)
#define CPUS_DELAY_1K_MINUS_1_THRESHOLD           (CPUS_DELAY_1K_THRESHOLD - 1u)
#define CPUS_DELAY_1M_THRESHOLD                   (1000000u)
#define CPUS_DELAY_1M_MINUS_1_THRESHOLD           (CPUS_DELAY_1M_THRESHOLD - 1u)

/**  Start address of the Cortex-M4 application */
#ifndef CPUS_CORTEX_M4_APPL_ADDR
    // This symbol is defined in the linker script
    extern char *  __cm4_vector_base_linker_symbol;
    #define CPUS_CORTEX_M4_APPL_ADDR      ((uint32_t) &__cm4_vector_base_linker_symbol)
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


/*______  L O C A L  - T Y P E S _____________________________________________*/

/*______ G L O B A L - T Y P E S _____________________________________________*/

/*______  L O C A L  - M A C R O S ___________________________________________*/

/*______ G L O B A L - M A C R O S ___________________________________________*/

/*______  L O C A L  - D A T A _______________________________________________*/

/*______ G L O B A L - D A T A _______________________________________________*/
extern uint32_t SystemCoreClock;
extern uint32_t CPUS_delayFreqHz;
extern uint32_t cy_delayFreqKhz;
extern uint8_t  cy_delayFreqMhz;
extern uint32_t cy_delay32kMs;
/*______  L O C A L  - F U N C T I O N S - P R O T O T Y P E S _______________*/


/*______ G L O B A L - F U N C T I O N S - P R O T O T Y P E S _______________*/
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

extern uint32_t CPUS_SysGetApplCoreStatus(void);
extern void     CPUS_SysEnableApplCore(uint32_t vectorTableOffset);
extern void     CPUS_SysDisableApplCore(void);
extern void     CPUS_SysRetainApplCore(void);
extern void     CPUS_SysResetApplCore(void);


#endif /* CPUS_TVII_2M_H */

