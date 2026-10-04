/******************************************************************************/
/*@F_NAME:            iodc_config.c                                           */
/*@F_PURPOSE:         Configuration file iodc module                          */
/*@F_CREATED_BY:      M. Sergent                                              */
/*@F_CREATION_DATE:  25/05/2000                                               */
/*@F_MPROC_TYPE:     Processor independent                                    */
/************************************** (C) Copyright 2000 Magneti Marelli ****/

/*______ I N C L U D E - F I L E S ___________________________________________*/

#include "vers_config.h"
#include "syst.h"
#include "iodc_priv.h"
#include "iodc_config.h"
#include "iodc.h"
/*#include "imc_config.h"*/
#ifdef __WATCHDOG_MEASUREMENT__
#include "wdgc.h"
#endif /*__WATCHDOG_MEASUREMENT__ */
/*#include "netc.h"*/ /*note,IMC for Bootloader*/
/*______ L O C A L - D E F I N E _____________________________________________*/


/*______ L O C A L - T Y P E S________________________________________________*/


/*______ G L O B A L - D A T A _______________________________________________*/

#if defined(IODC_LED_MATRIX_USED) && defined(IODC_LED_MATRIX_RELAX_TIME_USED)
extern ushort IODC_RelaxTimeTick;
#endif /* IODC_LED_MATRIX_USED && IODC_LED_MATRIX_RELAX_TIME_USED */


/*______ L O C A L - D A T A _________________________________________________*/


/*______ L O C A L - M A C R O S _____________________________________________*/


/*______ P R I V A T E - F U N C T I O N S - P R O T O T Y P E S _____________*/


/*______ L O C A L - F U N C T I O N S - P R O T O T Y P E S _________________*/
static void Iodc_CreateDirection(void);
static void Iodc_CreatePhyHwVersionDirection(void);
/*______ P R I V A T E - F U N C T I O N S ___________________________________*/

#ifdef __EOL_ENABLE__
/*----------------------------------------------------------------------------*/
/*Name : Iodc_InitEolDigitalInPin                                             */
/*Role : configure the pin of micro according to define of pin used           */
/*          this function is called by EOL module.                            */
/*          So, the configuration of each EOL pin must be write here.         */
/*Interface : none                                                            */
/*Pre-condition : none                                                        */
/*Constraints : none                                                          */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [create the hardware configuration for EOL module]                      */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
void Iodc_InitEolDigitalInPin(void)
{
  /* -- initialize direct input -- */
  /*TODO:Iodc_CreateDirectInput(EOL_TEST_PIN);*/
}
#endif /* __EOL_ENABLE__ */


/*______ G L O B A L - F U N C T I O N S _____________________________________*/

/*----------------------------------------------------------------------------*/
/*Name : IODC_InitSystem                                                      */
/*Role : setup minimal processor I/O to be able to perform EEPC initialization*/
/*       and other premier modules                                            */
/*                                                                            */
/*       all modules initialization (including IODC) are EEPROM-dependent     */
/*       Therefore EEPC and VERS initialization are done first                */
/*       but in case of external EEPROM and external watchdog some I/O have   */
/*       to set before                                                        */
/*       it is the purpose of IODC_InitSystem                                 */
/*Interface : -                                                               */
/*Pre-condition : -                                                           */
/*Constraints :                                                               */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [ setup minimal processor I/O for premier modules ]                     */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
void IODC_InitSystem(void)
{


#ifdef __WATCHDOG_MEASUREMENT__
  WDGC_InitRefreshTimeTest();
  WDGC_InitTimeoutTest();
#endif /*__WATCHDOG_MEASUREMENT__ */
}

/*----------------------------------------------------------------------------*/
/*Name : IODC_ConfigureHw                                                     */
/*Role : configure the pin of micro according to define of pin used           */
/*          this function is called by IODC_SystemInit function. So,          */
/*          the configuration of each pin must be write here.                 */
/*Interface :                                                                 */
/*Pre-condition : -                                                           */
/*Constraints :                                                               */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [create the hardware configuration ]                                    */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
/*PROC IODC_ConfigureHw()                                                     */
/*DATA                                                                        */
/*ATAD                                                                        */
/*                                                                            */
/*DO                                                                          */
/*  [create the hardware configuration ] =                                    */
/*  DO                                                                        */
/*  [ call IODC_CreateDirectInput macro for each virtual direct pin ]         */
/*  [ call IODC_CreateFilteredInput macro for each virtual filtered pin ]     */
/*  [ call IODC_CreateOutput macro for each virtual output pin ]              */
/*  [ call IODC_CreateColumOutput macro for each column ]                     */
/*  IFDEF IODC_DIRECT_ACCESS_USED                                             */
/*  THEN                                                                      */
/*  [ call IODC_CreateLineOutput macro for each line ]                        */
/*  FEDFI                                                                     */
/*  OD                                                                        */
/*OD                                                                          */
/*----------------------------------------------------------------------------*/
void IODC_ConfigureHw(void)
{
  /* Add here each necessary IODC_Create_... macro to initialize the I/O */
  /* acoording to the layout                                             */

  /* 1.initialize pins' direction________________________*/
  /*Step 1.A: Iodc_CreatePhyHwVersionDirection */
  Iodc_CreatePhyHwVersionDirection();
  /*Step 1.B: VERS_InitPhysicalHardwareVersion */
  VERS_InitPhysicalHardwareVersion();
  /*Step 1.C: Iodc_CreateDirection */
  Iodc_CreateDirection();
#ifdef __DEVM_TEST__ /* TVII-C-2D-6M-500-BGA-CPU-BOARD TEST*/

#ifdef CY_CPU_CORTEX_M0P
  Iodc_CreateOutput(USER_LED_1);
  Iodc_CreateDirectInput(BUTTON_UP);

#endif

#ifdef CY_CORE_CM7_0
  Iodc_CreateOutput(USER_LED_2);
#endif /*CY_CORE_CM7_0*/

#ifdef CY_CORE_CM7_1
  Iodc_CreateOutput(USER_LED_3);
#endif /*CY_CORE_CM7_1*/

#endif /* __DEVM_TEST__ */


/*   Iodc_CreateOutput(NEC_OUTPUT_1); */
/*   Iodc_CreateOutput(CLOCK_SPI_4); */
/*   Iodc_CreateOutput(DATAOUT_SPI_4); */
/*   Iodc_CreateOutput(SCK_I2C); */


  /* -- initialize direct LED output -- */


  /* initialize direct output (not the leds matrix pins) */
  /*Iodc_CreateOutput(MATC_READ);
  Iodc_CreateOutput(MATC_CONTROL);
  Iodc_CreateOutput(MATRIX_HARDWARE_RESET_PIN);
  Iodc_CreateOutput(CS_EEPROM);
  Iodc_CreateOutput(CS_PILAM);
  Iodc_CreateOutput(TX_LCD);
  Iodc_CreateOutput(CLK_LCD);
  Iodc_CreateOutput(M1_PIN);
  */

#if (defined(__TASK_DURATION_MEASUREMENT__) || \
     defined(__IT_DURATION_MEASUREMENT__) || \
     defined(__TASK_SCHEDULING_MEASUREMENT__) \
    )
/*   Iodc_CreateOutput(OUT_RTOS_MEASUREMENT_1); */
/*   IODC_SetOutputData(OUT_RTOS_MEASUREMENT_1, IODC_INACTIVE); */
#endif /* __TASK_DURATION_MEASUREMENT__   || \
          __IT_DURATION_MEASUREMENT__     || \
          __TASK_SCHEDULING_MEASUREMENT__ */

  /* -- initialize LED drived in direct or by shift register -- */


  /* -- initialize column pin for led matrix -- */
  /*Iodc_CreateColumnOutput(0);
  Iodc_CreateColumnOutput(1);
  Iodc_CreateColumnOutput(2);
  */


  /*  -- initialize line pin for led matrix -- */
  /*Iodc_CreateLineOutput(0);
  Iodc_CreateLineOutput(1);
  Iodc_CreateLineOutput(2);
  Iodc_CreateLineOutput(3);
  Iodc_CreateLineOutput(4);
  Iodc_CreateLineOutput(5);
  Iodc_CreateLineOutput(6);
  Iodc_CreateLineOutput(7);
  */


  /* -- shift register strobe, init level -- */
  /* -- do not change this section        -- */

#ifdef IODC_SHIFT_REGISTER_ACCESS_USED
/*   Iodc_CreateOutput(SHIFTER); */
/*   IODC_SetOutputData(SHIFTER,IODC_INACTIVE); */
#endif /* IODC_SHIFT_REGISTER_ACCESS_USED */

  IODC_SetOutputData(CAN2_STB, IODC_INACTIVE);                /*P1_0*/
  IODC_SetOutputData(SPK_DIAG_EN, IODC_INACTIVE);             /*P2_4*/
  IODC_SetOutputData(WDG_SET1, IODC_ACTIVE);                  /*P5_4*/
  IODC_SetOutputData(MCU_AUDIO_SPI_CS, IODC_ACTIVE);          /*P6_3*/
  IODC_SetOutputData(MCU_AUDIO_DAC_RST, IODC_INACTIVE);       /*P8_0*/
  IODC_SetOutputData(MCU_3V3_EN,IODC_ACTIVE);                 /*P9_2*/
  IODC_SetOutputData(FUEL_MES_CMD, IODC_ACTIVE);              /*P12_0*/
  IODC_SetOutputData(NSHUTDOWN, IODC_INACTIVE);               /*P14_4*/
  IODC_SetOutputData(KL30_CMD, IODC_ACTIVE);                  /*P14_5*/
  IODC_SetOutputData(EEPROM_CS, IODC_ACTIVE);                 /*P18_3*/
  IODC_SetOutputData(TESTPIN, IODC_ACTIVE);                 /*P18_3*/
  IODC_SetOutputData(HSCAN_STB, IODC_INACTIVE);               /*P19_0*/
  IODC_SetOutputData(SPI_CS, IODC_ACTIVE);                  /*P19_3*/
  IODC_SetOutputData(BAT_MEAS, IODC_ACTIVE);                  /*P22_4*/
  IODC_SetOutputData(WHEEL_SWITCH_MES_CMD, IODC_ACTIVE);      /*P22_5*/
  IODC_SetOutputData(TEMP_MES_CMD, IODC_ACTIVE);              /*P22_6*/

}


/*----------------------------------------------------------------------------*/
/*Name : Iodc_SetupIoRefresh                                                  */
/*Role : Refresh configuration of each pin                                    */
/*       this function is called by IODC_Task function.                       */
/*Interface :                                                                 */
/*Pre-condition : -                                                           */
/*Constraints :                                                               */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [Refresh the hardware configuration ]                                   */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
void Iodc_SetupIoRefresh(void)
{
  /* Add here each necessary IODC_Create_... macro to initialize the I/O */
  /* acoording to the layout to be refreshed periodically                */
  Iodc_CreatePhyHwVersionDirection();
  Iodc_CreateDirection();
}

/*----------------------------------------------------------------------------*/
/*Name : IODC_SetupWakeUpIntPn                                                */
/*Role :  Configure the deep stop mode wake-up factor                         */
/*Interface :                                                                 */
/*Pre-condition : -                                                           */
/*Constraints :                                                               */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [Configure the deep stop mode wake-up factor ]                          */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
void IODC_SetupWakeUpIntPn(void)
{
}

/*----------------------------------------------------------------------------*/
/*Name : IODC_SetIoDown                                                       */
/*Role : Set I/O state to reduce board sleeping-current                       */
/*Interface :                                                                 */
/*Pre-condition : -                                                           */
/*Constraints :                                                               */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [Set properly I/O state depending HW]                                   */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
void IODC_SetIoDown(void)
{
  /* Add here each necessary IODC_Create_... macro to initialize the I/O */
  VERS_HardwareVersion_t PhyHwVersion = VERS_GetPhysicalHardwareVersion();
  /* --- I/O to set in input --- */

  /* --- I/O to set in output / output state --- */
  IODC_SetOutputData(BAT_MEAS, IODC_INACTIVE);                /*P1_0*/
  IODC_SetOutputData(KL30_CMD, IODC_INACTIVE);                /*P1_1*/
  IODC_SetOutputData(WHEEL_SWITCH_MES_CMD, IODC_INACTIVE);    /*P1_2*/
  IODC_SetOutputData(MCU_AUDIO_DAC_RST, IODC_INACTIVE);       /*P8_0*/
  IODC_SetOutputData(SPK_DIAG_EN, IODC_INACTIVE);             /*P8_1*/
  IODC_SetOutputData(TEMP_MES_CMD, IODC_INACTIVE);            /*P8_2*/
  IODC_SetOutputData(FUEL_MES_CMD, IODC_INACTIVE);            /*P8_3*/
  IODC_SetOutputData(MCU_AUDIO_SPI_CS, IODC_ACTIVE);          /*P8_7*/
  IODC_SetOutputData(PMIC_ON2, IODC_INACTIVE);                /*P11_13*/
  IODC_SetOutputData(EEPROM_CS, IODC_INACTIVE);               /*P11_15*/
  IODC_SetOutputData(HSCAN_STB, IODC_ACTIVE);                 /*P12_0*/
  IODC_SetOutputData(CAN2_STB, IODC_ACTIVE);                  /*P12_1*/
  IODC_SetOutputData(GPU_5V_EN,IODC_INACTIVE);                /*P9_3*/
  IODC_SetOutputData(GPU_3V3_EN,IODC_INACTIVE);               /*P9_2*/
  IODC_SetOutputData(MCU_TO_GPU_RST,IODC_ACTIVE);             /*P11_14*/
}


/*----------------------------------------------------------------------------*/
/*Name : IODC_SetIoUp                                                         */
/*Role : Set I/O in applicative state                                         */
/*Interface :                                                                 */
/*Pre-condition : -                                                           */
/*Constraints :                                                               */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [Set properly I/O state depending HW]                                   */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
void IODC_SetIoUp(void)
{
  IODC_ConfigureHw();
}


#ifdef __EOL_ENABLE__
/******************************************************************************/
/*Name : IODC_EolpConfigureLcdPin                                             */
/*Role : this function realise activation of the ouput pins to drive the EOL  */
/*       test in case of static mode test                                     */
/*Interface : none                                                            */
/*Pre-condition : none                                                        */
/*Constraints : none                                                          */
/*DO                                                                          */
/*  [Create the output with all pins to drive directly the LCD]               */
/*OD                                                                          */
/******************************************************************************/
void IODC_EolpConfigureLcdPin(void)
{
        /*TODO:
  Iodc_CreateOutput(EOLP_LCD_S0);
  Iodc_CreateOutput(EOLP_LCD_S1);
  Iodc_CreateOutput(EOLP_LCD_S2);
  Iodc_CreateOutput(EOLP_LCD_S3);
  Iodc_CreateOutput(EOLP_LCD_S4);
  Iodc_CreateOutput(EOLP_LCD_S5);
  Iodc_CreateOutput(EOLP_LCD_S6);
  Iodc_CreateOutput(EOLP_LCD_S7);
  Iodc_CreateOutput(EOLP_LCD_S8);
  Iodc_CreateOutput(EOLP_LCD_S9);
  Iodc_CreateOutput(EOLP_LCD_S10);
  Iodc_CreateOutput(EOLP_LCD_S11);
  Iodc_CreateOutput(EOLP_LCD_S12);
  Iodc_CreateOutput(EOLP_LCD_S13);
  Iodc_CreateOutput(EOLP_LCD_S14);
  Iodc_CreateOutput(EOLP_LCD_S15);
  Iodc_CreateOutput(EOLP_LCD_S16);
  Iodc_CreateOutput(EOLP_LCD_S17);
  Iodc_CreateOutput(EOLP_LCD_S18);
  Iodc_CreateOutput(EOLP_LCD_S19);
  Iodc_CreateOutput(EOLP_LCD_S20);
  Iodc_CreateOutput(EOLP_LCD_S21);
  Iodc_CreateOutput(EOLP_LCD_S22);
  Iodc_CreateOutput(EOLP_LCD_S23);
  Iodc_CreateOutput(EOLP_LCD_S24);
  Iodc_CreateOutput(EOLP_LCD_S25);
  Iodc_CreateOutput(EOLP_LCD_S26);
  Iodc_CreateOutput(EOLP_LCD_S27);
  */
}

#endif /*__EOL_ENABLE__*/

#if defined(IODC_LED_MATRIX_USED) && defined(IODC_LED_MATRIX_RELAX_TIME_USED)
/*----------------------------------------------------------------------------*/
/*Name : IODC_UpdateRelaxTimeLedMatrix                                        */
/*Role : Update the relax time of LED matrix                                  */
/*Interface :                                                                 */
/*  - IN : Depending on your application (Battery ?)                          */
/*  - IN : TRUE if Relax time according battery is needed                     */
/*  - OUT : Relax time updated                                                */
/*Pre-condition : -                                                           */
/*Constraints : -                                                             */
/*----------------------------------------------------------------------------*/
void IODC_UpdateRelaxTimeLedMatrix(ushort battery, bool_t RelaxTimeNeed);
{
  /* -- Add here the relax time calcul -- */
  IODC_RelaxTimeTick = 1/* Battery * a + b */;
}
#endif /* IODC_LED_MATRIX_USED && IODC_LED_MATRIX_RELAX_TIME_USED */


/*______ L O C A L - F U N C T I O N S _______________________________________*/

/*----------------------------------------------------------------------------*/
/*Name : ButtonIntHandler                                                     */
/*Role : Button interrupt callback function                                   */
/*Pre-condition : -                                                           */
/*Constraints : -                                                             */
/*----------------------------------------------------------------------------*/
void ButtonIntHandler(void)
{
#ifdef __DEVM_TEST__ /* TVII-C-2D-6M-500-BGA-CPU-BOARD TEST*/
#ifdef CY_CPU_CORTEX_M0P
    ulong intStatus;

    /* If falling edge detected */
    intStatus = IODC_ReadStatusIrq(BUTTON_UP);
    if (intStatus != 0ul)
    {
    	IODC_ClearStatusIrq(BUTTON_UP);

        /* Toggle LED */
        IODC_SetOutputInverse(USER_LED_1);
    }
#endif /*CY_CPU_CORTEX_M0P*/

#ifdef CY_CORE_CM7_0

#endif /*CY_CORE_CM7_0*/

#ifdef CY_CORE_CM7_1

#endif /*CY_CORE_CM7_1*/
#endif /* __DEVM_TEST__ */

}

#if (defined(__BOOT_LOADER_FLASHER_LINK__) || defined(__BOOT_CLIENT_EOL_LINK__) || defined(__BOOT_LOADER_LINK__))
/*----------------------------------------------------------------------------*/
/*Name : IODC_ConfigureHwBootKeyPin                                           */
/*Role : Configure pins used to be read to test hardware boot key.            */
/*       This function is usefull when a HW bootkey is used.                  */
/*Interface : -                                                               */
/*Pre-condition : -                                                           */
/*Constraints : This configuration is necessary to read pins.                 */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [Create all pins as input]                                              */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
void IODC_ConfigureHwBootKeyPin(void)
{
/*   Iodc_CreateDirectInput(SDA_I2C);
  Iodc_CreateDirectInput(SCK_I2C);
  Iodc_CreateDirectInput(CAP_START);
  Iodc_CreateDirectInput(FLASH_RESET);
  Iodc_CreateDirectInput(CAP_RESET);
  Iodc_CreateDirectInput(CAP_MLC); */
}

/*----------------------------------------------------------------------------*/
/*Name : IODC_RestoreHwBootKeyPin                                             */
/*Role : Restore pins used to be read to test hardware boot key.              */
/*       This function is usefull when a HW bootkey is used.                  */
/*Interface : -                                                               */
/*Pre-condition : -                                                           */
/*Constraints : This configuration is necessary to program mainly CAP_START   */
/*              pin (used to power on EEPROM circuit with CAP A hardware)     */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [Create all pins as same direction pin as initialization]               */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
void IODC_RestoreHwBootKeyPin(void)
{
/*   Iodc_CreateDirectInput(SDA_I2C);
  Iodc_CreateOutput(SCK_I2C);
  Iodc_CreateOutput(CAP_START);
  Iodc_CreateOutput(FLASH_RESET);
  Iodc_CreateOutput(CAP_RESET);
  Iodc_CreateDirectInput(CAP_MLC); */
}
#endif /* __BOOT_LOADER_FLASHER_LINK__ || __BOOT_CLIENT_EOL_LINK__ || __BOOT_LOADER_LINK__ */

/*----------------------------------------------------------------------------*/
/*Name : IODC_CreatePhyHwVersionDirection                                     */
/*Role : Create I/O Direction                                                 */
/*Interface :                                                                 */
/*Pre-condition : -                                                           */
/*Constraints :                                                               */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [Create properly I/O state depending HW]                                */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
void IODC_CreatePhyHwVersionDirection(void)
{
  Iodc_CreatePhyHwVersionDirection();
}

/*----------------------------------------------------------------------------*/
/*Name : Iodc_CreatePhyHwVersionDirection                                     */
/*Role : Create I/O Direction                                                 */
/*Interface :                                                                 */
/*Pre-condition : -                                                           */
/*Constraints :                                                               */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [Create properly I/O state depending HW]                                */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
static void Iodc_CreatePhyHwVersionDirection(void)
{
#ifndef __POLYSPACE__
  Iodc_CreateDirectInput(MCU_HW0);/*P13_5*/
  Iodc_CreateDirectInput(MCU_HW1);/*P13_6*/
  Iodc_CreateDirectInput(MCU_HW2);/*P13_4*/
#endif
}
/*----------------------------------------------------------------------------*/
/*Name : Iodc_CreateDirection                                                 */
/*Role : Create I/O Direction                                                 */
/*Interface :                                                                 */
/*Pre-condition : -                                                           */
/*Constraints :                                                               */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [Create properly I/O state depending HW]                                */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
static void Iodc_CreateDirection(void)
{
#ifndef __POLYSPACE__
  Iodc_CreateOutput(CAN2_STB);                  /*P1_0*/

  Iodc_CreateOutput(SPK_DIAG_EN);               /*P2_4*/

  Iodc_CreateDirectInput(SPEAKER_DIAG_IN);      /*P3_0*/
  Iodc_CreateDirectInput(LCD_CON_FAIL);         /*P3_1*/
  Iodc_CreateDirectInput(BK_CON_FAIL);          /*P3_3*/

 // Iodc_CreateDirectInput(GPU_5V_PWRGD);         /*P5_0*/
  Iodc_CreateDirectInput(GPU_3V3_PWRGD);        /*P5_1*/
  Iodc_CreateDirectInput(GPU_PMIC_PWRGD);       /*P5_2*/
  // Iodc_CreateDirectInput(VTT_PWRGD);            /*P5_3*/
  Iodc_CreateOutput(WDG_SET1);                  /*P5_4*/

  Iodc_CreateOutput(MCU_AUDIO_SPI_CS);          /*P6_3*/
  Iodc_CreateDirectInput(MCU_SAFE_INT1);        /*P6_4*/
  Iodc_CreateDirectInput(MCU_SAFE_INT0);        /*P6_5*/
  Iodc_CreateDirectInput(MCU_SAFE_INT1);        /*P6_6*/
  Iodc_CreateDirectInput(MCU_SAFE_INT0);        /*P6_7*/

  Iodc_CreateDirectInput(MCU_IMC_RDY);          /*P7_3*/
//  IODD_ALTER2_FUNC(7,3);
  Iodc_CreateDirectInput(MCU_IMC_D0);           /*P7_5*/
  Iodc_CreateDirectInput(MCU_IMC_D1);           /*P7_6*/
  Iodc_CreateDirectInput(MCU_IMC_D2);           /*P7_7*/

  Iodc_CreateOutput(MCU_AUDIO_DAC_RST);         /*P8_0*/
  Iodc_CreateOutput(MCU_TO_GPU_RST);            /*P8_1*/
  Iodc_CreateDirectInput(FAIL_T);               /*P8_2*/

  Iodc_CreateOutput(FUEL_MES_CMD);              /*P12_0*/

  Iodc_CreateOutput(HSCAN_EN);                  /*P14_2*/
  Iodc_CreateOutput(HSCAN_STB);                 /*P14_3*/
  Iodc_CreateOutput(NSHUTDOWN);                 /*P14_4*/
  Iodc_CreateOutput(KL30_CMD);                  /*P14_5*/

  Iodc_CreateOutput(GPU_5V_EN);                 /*P15_0*/
  Iodc_CreateOutput(GPU_3V3_EN);                /*P15_1*/
  Iodc_CreateOutput(PMIC_ON2);                  /*P15_2*/
  Iodc_CreateOutput(MCU_3V3_EN);                /*P15_3*/

  Iodc_CreateDirectInput(LOW_PRESSURE_IN);      /*P16_0*/
  Iodc_CreateDirectInput(BT_CHARGE_IN);         /*P16_1*/
  Iodc_CreateDirectInput(MCU_ANTI_THEFT);       /*P16_2*/

  Iodc_CreateDirectInput(BRAKE_F_IN);           /*P17_0*/
  Iodc_CreateDirectInput(DIGITAL1_IN);          /*P17_1*/
  Iodc_CreateDirectInput(DIGITAL2_IN);          /*P17_2*/
  Iodc_CreateDirectInput(DIGITAL3_IN);          /*P17_3*/
  Iodc_CreateDirectInput(DIGITAL4_IN);          /*P17_4*/

  Iodc_CreateOutput(EEPROM_CS);                 /*P18_3*/
  Iodc_CreateOutput(TESTPIN);                   /*P18_4*/
  Iodc_CreateDirectInput(KL15_IN);              /*P18_5*/

  Iodc_CreateOutput(SPI_CS);                    /*P19_3*/

  Iodc_CreateOutput(BAT_MEAS);                  /*P22_4*/
  Iodc_CreateOutput(WHEEL_SWITCH_MES_CMD);      /*P22_5*/
  Iodc_CreateOutput(TEMP_MES_CMD);              /*P22_6*/

#endif
}
#if 0 /*For Bootloader IMC */
/*----------------------------------------------------------------------------*/
/*Name : IODC_PortIntHandler                                                  */
/*Role : Port interrupt callback function                                     */
/*Pre-condition : -                                                           */
/*Constraints : -                                                             */
/*----------------------------------------------------------------------------*/
void IODC_PortIntHandler(void)
{
    ulong intStatus;

    /* If falling edge detected */
    intStatus = IODC_ReadStatusIrq(MCU_IMC_RDY);
    if (intStatus != 0ul)
    {
    	IODC_ClearStatusIrq(MCU_IMC_RDY);
    	IMC_ReadyIntHandler();
    }
}
#endif
/*_____ E N D _____ (iodc_config.c) __________________________________________*/
