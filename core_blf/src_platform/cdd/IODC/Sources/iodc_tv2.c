/******************************************************************************/
/*@F_NAME:              iodc_tv2.c                                            */
/*@F_PURPOSE:           iodc module                                           */
/*@F_CREATED_BY:        Yanbin SHEN                                           */
/*@F_CREATION_DATE:     2020.09.09                                            */
/*@F_MPROC_TYPE:        cypress traveo II series                              */
/**************************************** (C) Copyright 2020  Marelli Inc. ****/

/*______ I N C L U D E - F I L E S ___________________________________________*/

#include "syst.h"
#include "iodc_config.h"
#include "iodc_priv.h"
#include "iodc.h"
#include "iodd.h"

#ifdef __CY_TV2__

/*______ L O C A L - D E F I N E _____________________________________________*/


#if ((IODC_IT_IRQ0    == _USED_) || \
     (IODC_IT_IRQ1    == _USED_) || \
     (IODC_IT_IRQ2    == _USED_) || \
     (IODC_IT_IRQ3    == _USED_) || \
     (IODC_IT_IRQ4    == _USED_) || \
     (IODC_IT_IRQ5    == _USED_) || \
     (IODC_IT_IRQ6    == _USED_) || \
     (IODC_IT_IRQ7    == _USED_) || \
     (IODC_IT_IRQ8    == _USED_) || \
     (IODC_IT_IRQ9    == _USED_) || \
     (IODC_IT_IRQ10   == _USED_) || \
     (IODC_IT_IRQ11   == _USED_) || \
     (IODC_IT_IRQ12   == _USED_) || \
     (IODC_IT_IRQ13   == _USED_) || \
     (IODC_IT_IRQ14   == _USED_) || \
     (IODC_IT_IRQ26   == _USED_) || \
     (IODC_IT_IRQ16   == _USED_) || \
     (IODC_IT_IRQ17   == _USED_) || \
     (IODC_IT_IRQ18   == _USED_) || \
     (IODC_IT_IRQ19   == _USED_) || \
     (IODC_IT_IRQ20   == _USED_) || \
     (IODC_IT_IRQ21   == _USED_) || \
     (IODC_IT_IRQ22   == _USED_) || \
     (IODC_IT_IRQ23   == _USED_) || \
     (IODC_IT_IRQ24   == _USED_) || \
     (IODC_IT_IRQ25   == _USED_) || \
     (IODC_IT_IRQ26   == _USED_) || \
     (IODC_IT_IRQ27   == _USED_) || \
     (IODC_IT_IRQ28 == _USED_))
#define IODC_IRQ_USED
#endif /* at least one Irq used */

/*______ L O C A L - T Y P E S________________________________________________*/

#ifdef IODC_IRQ_USED
typedef enum{
#if IODC_IT_IRQ0 == _USED_
	IODC_IT_IRQ0_ID,
#endif /* IODC_IT_IRQ00 == _USED_ */

#if IODC_IT_IRQ1  == _USED_
	IODC_IT_IRQ1_ID,
#endif /* IODC_IT_IRQ01 == _USED_ */

#if IODC_IT_IRQ2  == _USED_
	IODC_IT_IRQ2_ID,
#endif /* IODC_IT_IRQ02 == _USED_ */

#if IODC_IT_IRQ3  == _USED_
	IODC_IT_IRQ3_ID,
#endif /* IODC_IT_IRQ03 == _USED_ */

#if IODC_IT_IRQ4  == _USED_
	IODC_IT_IRQ4_ID,
#endif /* IODC_IT_IRQ04 == _USED_ */

#if IODC_IT_IRQ5  == _USED_
	IODC_IT_IRQ5_ID,
#endif /* IODC_IT_IRQ05 == _USED_ */

#if IODC_IT_IRQ6 == _USED_
	IODC_IT_IRQ6_ID,
#endif /* IODC_IT_IRQ06 == _USED_ */

#if IODC_IT_IRQ7  == _USED_
	IODC_IT_IRQ7_ID,
#endif /* IODC_IT_IRQ07 == _USED_ */

#if IODC_IT_IRQ8  == _USED_
	IODC_IT_IRQ8_ID,
#endif /* IODC_IT_IRQ08 == _USED_ */

#if IODC_IT_IRQ9  == _USED_
	IODC_IT_IRQ9_ID,
#endif /* IODC_IT_IRQ09 == _USED_ */

#if IODC_IT_IRQ10 == _USED_
	IODC_IT_IRQ10_ID,
#endif /* IODC_IT_IRQ10 == _USED_ */

#if IODC_IT_IRQ11  == _USED_
	IODC_IT_IRQ11_ID,
#endif /* IODC_IT_IRQ11 == _USED_ */

#if IODC_IT_IRQ12  == _USED_
	IODC_IT_IRQ12_ID,
#endif /* IODC_IT_IRQ12 == _USED_ */

#if IODC_IT_IRQ13  == _USED_
	IODC_IT_IRQ13_ID,
#endif /* IODC_IT_IRQ13 == _USED_ */

#if IODC_IT_IRQ14  == _USED_
	IODC_IT_IRQ14_ID,
#endif /* IODC_IT_IRQ14 == _USED_ */

#if IODC_IT_IRQ15  == _USED_
	IODC_IT_IRQ15_ID,
#endif /* IODC_IT_IRQ15 == _USED_ */

#if IODC_IT_IRQ16  == _USED_
	IODC_IT_IRQ16_ID,
#endif /* IODC_IT_IRQ16 == _USED_ */

#if IODC_IT_IRQ17  == _USED_
	IODC_IT_IRQ17_ID,
#endif /* IODC_IT_IRQ17 == _USED_ */

#if IODC_IT_IRQ18  == _USED_
	IODC_IT_IRQ18_ID,
#endif /* IODC_IT_IRQ18 == _USED_ */

#if IODC_IT_IRQ19  == _USED_
	IODC_IT_IRQ19_ID,
#endif /* IODC_IT_IRQ19 == _USED_ */

#if IODC_IT_IRQ20  == _USED_
	IODC_IT_IRQ20_ID,
#endif /* IODC_IT_IRQ20 == _USED_ */

#if IODC_IT_IRQ21  == _USED_
	IODC_IT_IRQ21_ID,
#endif /* IODC_IT_IRQ21 == _USED_ */

#if IODC_IT_IRQ22  == _USED_
	IODC_IT_IRQ22_ID,
#endif /* IODC_IT_IRQ22 == _USED_ */

#if IODC_IT_IRQ23  == _USED_
	IODC_IT_IRQ23_ID,
#endif /* IODC_IT_IRQ23 == _USED_ */

#if IODC_IT_IRQ24  == _USED_
	IODC_IT_IRQ24_ID,
#endif /* IODC_IT_IRQ24 == _USED_ */

#if IODC_IT_IRQ25  == _USED_
	IODC_IT_IRQ25_ID,
#endif /* IODC_IT_IRQ25 == _USED_ */

#if IODC_IT_IRQ26  == _USED_
	IODC_IT_IRQ26_ID,
#endif /* IODC_IT_IRQ26 == _USED_ */

#if IODC_IT_IRQ27  == _USED_
	IODC_IT_IRQ27_ID,
#endif /* IODC_IT_IRQ27 == _USED_ */

#if IODC_IT_IRQ28  == _USED_
	IODC_IT_IRQ28_ID,
#endif /* IODC_IT_IRQ28 == _USED_ */
	IODC_IRQ_FCT_NUM,
} IODC_IrqID_t;
#endif /* IODC_IRQ_USED */

/*______ G L O B A L - D A T A _______________________________________________*/


/*______ L O C A L - D A T A _________________________________________________*/


/* table of applicative call-back function for irq interrupts */
#ifdef IODC_IRQ_USED

#ifdef __CY_TV2__
#if IODC_IT_IRQ0 == _USED_
extern void IODC_IT_IRQ0_CALLBACK(void);
#endif /* IODC_IT_IRQ00 == _USED_ */

#if IODC_IT_IRQ1  == _USED_
extern void IODC_IT_IRQ1_CALLBACK(void);
#endif /* IODC_IT_IRQ01 == _USED_ */

#if IODC_IT_IRQ2  == _USED_
extern void IODC_IT_IRQ2_CALLBACK(void);
#endif /* IODC_IT_IRQ02 == _USED_ */

#if IODC_IT_IRQ3  == _USED_
extern void IODC_IT_IRQ3_CALLBACK(void);
#endif /* IODC_IT_IRQ03 == _USED_ */

#if IODC_IT_IRQ4  == _USED_
extern void IODC_IT_IRQ4_CALLBACK(void);
#endif /* IODC_IT_IRQ04 == _USED_ */

#if IODC_IT_IRQ5  == _USED_
extern void IODC_IT_IRQ5_CALLBACK(void);
#endif /* IODC_IT_IRQ05 == _USED_ */

#if IODC_IT_IRQ6 == _USED_
extern void IODC_IT_IRQ6_CALLBACK(void);
#endif /* IODC_IT_IRQ06 == _USED_ */

#if IODC_IT_IRQ7  == _USED_
extern void IODC_IT_IRQ7_CALLBACK(void);
#endif /* IODC_IT_IRQ07 == _USED_ */

#if IODC_IT_IRQ8  == _USED_
extern void IODC_IT_IRQ8_CALLBACK(void);
#endif /* IODC_IT_IRQ08 == _USED_ */

#if IODC_IT_IRQ9  == _USED_
extern void IODC_IT_IRQ9_CALLBACK(void);
#endif /* IODC_IT_IRQ09 == _USED_ */

#if IODC_IT_IRQ10 == _USED_
extern void IODC_IT_IRQ10_CALLBACK(void);
#endif /* IODC_IT_IRQ10 == _USED_ */

#if IODC_IT_IRQ11  == _USED_
extern void IODC_IT_IRQ11_CALLBACK(void);
#endif /* IODC_IT_IRQ11 == _USED_ */

#if IODC_IT_IRQ12  == _USED_
extern void IODC_IT_IRQ12_CALLBACK(void);
#endif /* IODC_IT_IRQ12 == _USED_ */

#if IODC_IT_IRQ13  == _USED_
extern void IODC_IT_IRQ13_CALLBACK(void);
#endif /* IODC_IT_IRQ13 == _USED_ */

#if IODC_IT_IRQ14  == _USED_
extern void IODC_IT_IRQ14_CALLBACK(void);
#endif /* IODC_IT_IRQ14 == _USED_ */

#if IODC_IT_IRQ15  == _USED_
extern void IODC_IT_IRQ15_CALLBACK(void);
#endif /* IODC_IT_IRQ15 == _USED_ */

#if IODC_IT_IRQ16  == _USED_
extern void IODC_IT_IRQ16_CALLBACK(void);
#endif /* IODC_IT_IRQ16 == _USED_ */

#if IODC_IT_IRQ17  == _USED_
extern void IODC_IT_IRQ17_CALLBACK(void);
#endif /* IODC_IT_IRQ17 == _USED_ */

#if IODC_IT_IRQ18  == _USED_
extern void IODC_IT_IRQ18_CALLBACK(void);
#endif /* IODC_IT_IRQ18 == _USED_ */

#if IODC_IT_IRQ19  == _USED_
extern void IODC_IT_IRQ19_CALLBACK(void);
#endif /* IODC_IT_IRQ19 == _USED_ */

#if IODC_IT_IRQ20  == _USED_
extern void IODC_IT_IRQ20_CALLBACK(void);
#endif /* IODC_IT_IRQ20 == _USED_ */

#if IODC_IT_IRQ21  == _USED_
extern void IODC_IT_IRQ21_CALLBACK(void);
#endif /* IODC_IT_IRQ21 == _USED_ */

#if IODC_IT_IRQ22  == _USED_
extern void IODC_IT_IRQ22_CALLBACK(void);
#endif /* IODC_IT_IRQ22 == _USED_ */

#if IODC_IT_IRQ23  == _USED_
extern void IODC_IT_IRQ23_CALLBACK(void);
#endif /* IODC_IT_IRQ23 == _USED_ */

#if IODC_IT_IRQ24  == _USED_
extern void IODC_IT_IRQ24_CALLBACK(void);
#endif /* IODC_IT_IRQ24 == _USED_ */

#if IODC_IT_IRQ25  == _USED_
extern void IODC_IT_IRQ25_CALLBACK(void);
#endif /* IODC_IT_IRQ25 == _USED_ */

#if IODC_IT_IRQ26  == _USED_
extern void IODC_IT_IRQ26_CALLBACK(void);
#endif /* IODC_IT_IRQ26 == _USED_ */

#if IODC_IT_IRQ27  == _USED_
extern void IODC_IT_IRQ27_CALLBACK(void);
#endif /* IODC_IT_IRQ27 == _USED_ */

#if IODC_IT_IRQ28  == _USED_
extern void IODC_IT_IRQ28_CALLBACK(void);
#endif /* IODC_IT_IRQ28 == _USED_ */

#endif /*__CY_TV2__*/


/* it is mandatory a table with constant-size whatever the IRQs installed */
static void (*const Iodc_IrqCallBackFctTable[IODC_IRQ_FCT_NUM])(void) =
{

#ifdef __CY_TV2__
#if IODC_IT_IRQ0 == _USED_
	IODC_IT_IRQ0_CALLBACK,
#endif /* IODC_IT_IRQ00 == _USED_ */

#if IODC_IT_IRQ1  == _USED_
	IODC_IT_IRQ1_CALLBACK,
#endif /* IODC_IT_IRQ01 == _USED_ */

#if IODC_IT_IRQ2  == _USED_
	IODC_IT_IRQ2_CALLBACK,
#endif /* IODC_IT_IRQ02 == _USED_ */

#if IODC_IT_IRQ3  == _USED_
	IODC_IT_IRQ3_CALLBACK,
#endif /* IODC_IT_IRQ03 == _USED_ */

#if IODC_IT_IRQ4  == _USED_
	IODC_IT_IRQ4_CALLBACK,
#endif /* IODC_IT_IRQ04 == _USED_ */

#if IODC_IT_IRQ5  == _USED_
	IODC_IT_IRQ5_CALLBACK,
#endif /* IODC_IT_IRQ05 == _USED_ */

#if IODC_IT_IRQ6 == _USED_
	IODC_IT_IRQ6_CALLBACK,
#endif /* IODC_IT_IRQ06 == _USED_ */

#if IODC_IT_IRQ7  == _USED_
	IODC_IT_IRQ7_CALLBACK,
#endif /* IODC_IT_IRQ07 == _USED_ */

#if IODC_IT_IRQ8  == _USED_
	IODC_IT_IRQ8_CALLBACK,
#endif /* IODC_IT_IRQ08 == _USED_ */

#if IODC_IT_IRQ9  == _USED_
	IODC_IT_IRQ9_CALLBACK,
#endif /* IODC_IT_IRQ09 == _USED_ */

#if IODC_IT_IRQ10 == _USED_
	IODC_IT_IRQ10_CALLBACK,
#endif /* IODC_IT_IRQ10 == _USED_ */

#if IODC_IT_IRQ11  == _USED_
	IODC_IT_IRQ11_CALLBACK,
#endif /* IODC_IT_IRQ11 == _USED_ */

#if IODC_IT_IRQ12  == _USED_
	IODC_IT_IRQ12_CALLBACK,
#endif /* IODC_IT_IRQ12 == _USED_ */

#if IODC_IT_IRQ13  == _USED_
	IODC_IT_IRQ13_CALLBACK,
#endif /* IODC_IT_IRQ13 == _USED_ */

#if IODC_IT_IRQ14  == _USED_
	IODC_IT_IRQ14_CALLBACK,
#endif /* IODC_IT_IRQ14 == _USED_ */

#if IODC_IT_IRQ15  == _USED_
	IODC_IT_IRQ15_CALLBACK,
#endif /* IODC_IT_IRQ15 == _USED_ */

#if IODC_IT_IRQ16  == _USED_
	IODC_IT_IRQ16_CALLBACK,
#endif /* IODC_IT_IRQ16 == _USED_ */

#if IODC_IT_IRQ17  == _USED_
	IODC_IT_IRQ17_CALLBACK,
#endif /* IODC_IT_IRQ17 == _USED_ */

#if IODC_IT_IRQ18  == _USED_
	IODC_IT_IRQ18_CALLBACK,
#endif /* IODC_IT_IRQ18 == _USED_ */

#if IODC_IT_IRQ19  == _USED_
	IODC_IT_IRQ19_CALLBACK,
#endif /* IODC_IT_IRQ19 == _USED_ */

#if IODC_IT_IRQ20  == _USED_
	IODC_IT_IRQ20_CALLBACK,
#endif /* IODC_IT_IRQ20 == _USED_ */

#if IODC_IT_IRQ21  == _USED_
	IODC_IT_IRQ21_CALLBACK,
#endif /* IODC_IT_IRQ21 == _USED_ */

#if IODC_IT_IRQ22  == _USED_
	IODC_IT_IRQ22_CALLBACK,
#endif /* IODC_IT_IRQ22 == _USED_ */

#if IODC_IT_IRQ23  == _USED_
	IODC_IT_IRQ23_CALLBACK,
#endif /* IODC_IT_IRQ23 == _USED_ */

#if IODC_IT_IRQ24  == _USED_
	IODC_IT_IRQ24_CALLBACK,
#endif /* IODC_IT_IRQ24 == _USED_ */

#if IODC_IT_IRQ25  == _USED_
	IODC_IT_IRQ25_CALLBACK,
#endif /* IODC_IT_IRQ25 == _USED_ */

#if IODC_IT_IRQ26  == _USED_
	IODC_IT_IRQ26_CALLBACK,
#endif /* IODC_IT_IRQ26 == _USED_ */

#if IODC_IT_IRQ27  == _USED_
	IODC_IT_IRQ27_CALLBACK,
#endif /* IODC_IT_IRQ27 == _USED_ */

#if IODC_IT_IRQ28  == _USED_
	IODC_IT_IRQ28_CALLBACK,
#endif /* IODC_IT_IRQ28 == _USED_ */

#endif /*__CY_TV2__*/

};

#endif /* IODC_IRQ_USED */


/*______ L O C A L - M A C R O S _____________________________________________*/


/*______ I M P O R T - F U N C T I O N S - P R O T O T Y P E S _______________*/


/*______ L O C A L - F U N C T I O N S - P R O T O T Y P E S _________________*/

#ifdef IODC_IRQ_USED
static  void Iodc_CallBackIrq(IODC_IrqID_t IrqNumber);
#endif /* IODC_IRQ_USED */

/*______ G L O B A L - F U N C T I O N S _____________________________________*/

/*----------------------------------------------------------------------------*/
/*Name : IODC_IrqX                                                            */
/*Role : Edge detection on Irq pin                                            */
/*Interface : -                                                               */
/*Pre-condition : -                                                           */
/*Constraints :  -                                                            */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [Call an applicative function]                                          */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/

#if IODC_IT_IRQ0 == _USED_
#if defined(__OSEK__)
__INTERRUPT__ ISR(IODC_Irq0_it)
#else  /* defined(__OSEK__) */
ISR(IODC_Irq0_it)
#endif /* defined(__OSEK__)  */
{
  #ifdef __IT_DURATION_MEASUREMENT__
  RTOS_EnterItDurationMeasurement(RTOS_MEAS_IT_IODC_IRQ0);
  #endif /* __IT_DURATION_MEASUREMENT__ */

  Iodc_CallBackIrq(IODC_IT_IRQ0_ID);

  #ifdef __IT_DURATION_MEASUREMENT__
  RTOS_LeaveItDurationMeasurement(RTOS_MEAS_IT_IODC_IRQ0);
  #endif /* __IT_DURATION_MEASUREMENT__ */
}
#endif /* IODC_IT_IRQ0 == _USED_ */

#if IODC_IT_IRQ1 == _USED_
#if defined(__OSEK__)
__INTERRUPT__ ISR(IODC_Irq1_it)
#else  /* defined(__OSEK__) */
ISR(IODC_Irq1_it)
#endif /* defined(__OSEK__)  */
{
  #ifdef __IT_DURATION_MEASUREMENT__
  RTOS_EnterItDurationMeasurement(RTOS_MEAS_IT_IODC_IRQ1);
  #endif /* __IT_DURATION_MEASUREMENT__ */

  Iodc_CallBackIrq(IODC_IT_IRQ1_ID);

  #ifdef __IT_DURATION_MEASUREMENT__
  RTOS_LeaveItDurationMeasurement(RTOS_MEAS_IT_IODC_IRQ1);
  #endif /* __IT_DURATION_MEASUREMENT__ */
}
#endif /* IODC_IT_IRQ1 == _USED_ */

#if IODC_IT_IRQ2 == _USED_
#if defined(__OSEK__)
__INTERRUPT__ ISR(IODC_Irq2_it)
#else  /* defined(__OSEK__) */
ISR(IODC_Irq2_it)
#endif /* defined(__OSEK__)  */
{
  #ifdef __IT_DURATION_MEASUREMENT__
  RTOS_EnterItDurationMeasurement(RTOS_MEAS_IT_IODC_IRQ2);
  #endif /* __IT_DURATION_MEASUREMENT__ */

  Iodc_CallBackIrq(IODC_IT_IRQ2_ID);

  #ifdef __IT_DURATION_MEASUREMENT__
  RTOS_LeaveItDurationMeasurement(RTOS_MEAS_IT_IODC_IRQ2);
  #endif /* __IT_DURATION_MEASUREMENT__ */
}
#endif /* IODC_IT_IRQ2 == _USED_ */

#if IODC_IT_IRQ3 == _USED_
#if defined(__OSEK__)
__INTERRUPT__ ISR(IODC_Irq3_it)
#else  /* defined(__OSEK__) */
ISR(IODC_Irq3_it)
#endif /* defined(__OSEK__)  */
{
  #ifdef __IT_DURATION_MEASUREMENT__
  RTOS_EnterItDurationMeasurement(RTOS_MEAS_IT_IODC_IRQ3);
  #endif /* __IT_DURATION_MEASUREMENT__ */

  Iodc_CallBackIrq(IODC_IT_IRQ3_ID);

  #ifdef __IT_DURATION_MEASUREMENT__
  RTOS_LeaveItDurationMeasurement(RTOS_MEAS_IT_IODC_IRQ3);
  #endif /* __IT_DURATION_MEASUREMENT__ */
}
#endif /* IODC_IT_IRQ3 == _USED_ */

#if IODC_IT_IRQ4 == _USED_
#if defined(__OSEK__)
__INTERRUPT__ ISR(IODC_Irq4_it)
#else  /* defined(__OSEK__) */
ISR(IODC_Irq4_it)
#endif /* defined(__OSEK__)  */
{
  #ifdef __IT_DURATION_MEASUREMENT__
  RTOS_EnterItDurationMeasurement(RTOS_MEAS_IT_IODC_IRQ4);
  #endif /* __IT_DURATION_MEASUREMENT__ */

  Iodc_CallBackIrq(IODC_IT_IRQ4_ID);

  #ifdef __IT_DURATION_MEASUREMENT__
  RTOS_LeaveItDurationMeasurement(RTOS_MEAS_IT_IODC_IRQ4);
  #endif /* __IT_DURATION_MEASUREMENT__ */
}
#endif /* IODC_IT_IRQ4 == _USED_ */

#if IODC_IT_IRQ5 == _USED_
#if defined(__OSEK__)
__INTERRUPT__ ISR(IODC_Irq5_it)
#else  /* defined(__OSEK__) */
ISR(IODC_Irq5_it)
#endif /* defined(__OSEK__)  */
{
  #ifdef __IT_DURATION_MEASUREMENT__
  RTOS_EnterItDurationMeasurement(RTOS_MEAS_IT_IODC_IRQ5);
  #endif /* __IT_DURATION_MEASUREMENT__ */

  Iodc_CallBackIrq(IODC_IT_IRQ5_ID);

  #ifdef __IT_DURATION_MEASUREMENT__
  RTOS_LeaveItDurationMeasurement(RTOS_MEAS_IT_IODC_IRQ5);
  #endif /* __IT_DURATION_MEASUREMENT__ */
}
#endif /* IODC_IT_IRQ5 == _USED_ */

#if IODC_IT_IRQ6 == _USED_
#if defined(__OSEK__)
__INTERRUPT__ ISR(IODC_Irq6_it)
#else  /* defined(__OSEK__) */
ISR(IODC_Irq6_it)
#endif /* defined(__OSEK__)  */
{
  #ifdef __IT_DURATION_MEASUREMENT__
  RTOS_EnterItDurationMeasurement(RTOS_MEAS_IT_IODC_IRQ6);
  #endif /* __IT_DURATION_MEASUREMENT__ */

  Iodc_CallBackIrq(IODC_IT_IRQ6_ID);

  #ifdef __IT_DURATION_MEASUREMENT__
  RTOS_LeaveItDurationMeasurement(RTOS_MEAS_IT_IODC_IRQ6);
  #endif /* __IT_DURATION_MEASUREMENT__ */
}
#endif /* IODC_IT_IRQ6 == _USED_ */

#if IODC_IT_IRQ7 == _USED_
#if defined(__OSEK__)
__INTERRUPT__ ISR(IODC_Irq7_it)
#else  /* defined(__OSEK__) */
ISR(IODC_Irq7_it)
#endif /* defined(__OSEK__)  */
{
  #ifdef __IT_DURATION_MEASUREMENT__
  RTOS_EnterItDurationMeasurement(RTOS_MEAS_IT_IODC_IRQ7);
  #endif /* __IT_DURATION_MEASUREMENT__ */

  Iodc_CallBackIrq(IODC_IT_IRQ7_ID);

  #ifdef __IT_DURATION_MEASUREMENT__
  RTOS_LeaveItDurationMeasurement(RTOS_MEAS_IT_IODC_IRQ7);
  #endif /* __IT_DURATION_MEASUREMENT__ */
}
#endif /* IODC_IT_IRQ7 == _USED_ */

#if IODC_IT_IRQ8 == _USED_
#if defined(__OSEK__)
__INTERRUPT__ ISR(IODC_Irq8_it)
#else  /* defined(__OSEK__) */
ISR(IODC_Irq8_it)
#endif /* defined(__OSEK__)  */
{
  #ifdef __IT_DURATION_MEASUREMENT__
  RTOS_EnterItDurationMeasurement(RTOS_MEAS_IT_IODC_IRQ8);
  #endif /* __IT_DURATION_MEASUREMENT__ */

  Iodc_CallBackIrq(IODC_IT_IRQ8_ID);

  #ifdef __IT_DURATION_MEASUREMENT__
  RTOS_LeaveItDurationMeasurement(RTOS_MEAS_IT_IODC_IRQ8);
  #endif /* __IT_DURATION_MEASUREMENT__ */
}
#endif /* IODC_IT_IRQ8 == _USED_ */

#if IODC_IT_IRQ9 == _USED_
#if defined(__OSEK__)
__INTERRUPT__ ISR(IODC_Irq9_it)
#else  /* defined(__OSEK__) */
ISR(IODC_Irq9_it)
#endif /* defined(__OSEK__)  */
{
  #ifdef __IT_DURATION_MEASUREMENT__
  RTOS_EnterItDurationMeasurement(RTOS_MEAS_IT_IODC_IRQ9);
  #endif /* __IT_DURATION_MEASUREMENT__ */

  Iodc_CallBackIrq(IODC_IT_IRQ9_ID);

  #ifdef __IT_DURATION_MEASUREMENT__
  RTOS_LeaveItDurationMeasurement(RTOS_MEAS_IT_IODC_IRQ9);
  #endif /* __IT_DURATION_MEASUREMENT__ */
}
#endif /* IODC_IT_IRQ9 == _USED_ */

#if IODC_IT_IRQ10 == _USED_
#if defined(__OSEK__)
__INTERRUPT__ ISR(IODC_Irq10_it)
#else  /* defined(__OSEK__) */
ISR(IODC_Irq10_it)
#endif /* defined(__OSEK__)  */
{
  #ifdef __IT_DURATION_MEASUREMENT__
  RTOS_EnterItDurationMeasurement(RTOS_MEAS_IT_IODC_IRQ10);
  #endif /* __IT_DURATION_MEASUREMENT__ */

  Iodc_CallBackIrq(IODC_IT_IRQ10_ID);

  #ifdef __IT_DURATION_MEASUREMENT__
  RTOS_LeaveItDurationMeasurement(RTOS_MEAS_IT_IODC_IRQ10);
  #endif /* __IT_DURATION_MEASUREMENT__ */
}
#endif /* IODC_IT_IRQ10 == _USED_ */

#if IODC_IT_IRQ11 == _USED_
#if defined(__OSEK__)
__INTERRUPT__ ISR(IODC_Irq11_it)
#else  /* defined(__OSEK__) */
ISR(IODC_Irq11_it)
#endif /* defined(__OSEK__)  */
{
  #ifdef __IT_DURATION_MEASUREMENT__
  RTOS_EnterItDurationMeasurement(RTOS_MEAS_IT_IODC_IRQ11);
  #endif /* __IT_DURATION_MEASUREMENT__ */

  Iodc_CallBackIrq(IODC_IT_IRQ11_ID);

  #ifdef __IT_DURATION_MEASUREMENT__
  RTOS_LeaveItDurationMeasurement(RTOS_MEAS_IT_IODC_IRQ11);
  #endif /* __IT_DURATION_MEASUREMENT__ */
}
#endif /* IODC_IT_IRQ11 == _USED_ */

#if IODC_IT_IRQ12 == _USED_
#if defined(__OSEK__)
__INTERRUPT__ ISR(IODC_Irq12_it)
#else  /* defined(__OSEK__) */
ISR(IODC_Irq12_it)
#endif /* defined(__OSEK__)  */
{
  #ifdef __IT_DURATION_MEASUREMENT__
  RTOS_EnterItDurationMeasurement(RTOS_MEAS_IT_IODC_IRQ12);
  #endif /* __IT_DURATION_MEASUREMENT__ */

  Iodc_CallBackIrq(IODC_IT_IRQ12_ID);

  #ifdef __IT_DURATION_MEASUREMENT__
  RTOS_LeaveItDurationMeasurement(RTOS_MEAS_IT_IODC_IRQ12);
  #endif /* __IT_DURATION_MEASUREMENT__ */
}
#endif /* IODC_IT_IRQ12 == _USED_ */


#if IODC_IT_IRQ13 == _USED_
#if defined(__OSEK__)
__INTERRUPT__ ISR(IODC_Irq13_it)
#else  /* defined(__OSEK__) */
ISR(IODC_Irq13_it)
#endif /* defined(__OSEK__)  */
{
  #ifdef __IT_DURATION_MEASUREMENT__
  RTOS_EnterItDurationMeasurement(RTOS_MEAS_IT_IODC_IRQ13);
  #endif /* __IT_DURATION_MEASUREMENT__ */

  Iodc_CallBackIrq(IODC_IT_IRQ13_ID);

  #ifdef __IT_DURATION_MEASUREMENT__
  RTOS_LeaveItDurationMeasurement(RTOS_MEAS_IT_IODC_IRQ13);
  #endif /* __IT_DURATION_MEASUREMENT__ */
}
#endif /* IODC_IT_IRQ13 == _USED_ */

#if IODC_IT_IRQ14 == _USED_
#if defined(__OSEK__)
__INTERRUPT__ ISR(IODC_Irq14_it)
#else  /* defined(__OSEK__) */
ISR(IODC_Irq14_it)
#endif /* defined(__OSEK__)  */
{
  #ifdef __IT_DURATION_MEASUREMENT__
  RTOS_EnterItDurationMeasurement(RTOS_MEAS_IT_IODC_IRQ14);
  #endif /* __IT_DURATION_MEASUREMENT__ */

  Iodc_CallBackIrq(IODC_IT_IRQ14_ID);

  #ifdef __IT_DURATION_MEASUREMENT__
  RTOS_LeaveItDurationMeasurement(RTOS_MEAS_IT_IODC_IRQ14);
  #endif /* __IT_DURATION_MEASUREMENT__ */
}
#endif /* IODC_IT_IRQ14 == _USED_ */

#if IODC_IT_IRQ15 == _USED_
#if defined(__OSEK__)
__INTERRUPT__ ISR(IODC_Irq15_it)
#else  /* defined(__OSEK__) */
ISR(IODC_Irq15_it)
#endif /* defined(__OSEK__)  */
{
  #ifdef __IT_DURATION_MEASUREMENT__
  RTOS_EnterItDurationMeasurement(RTOS_MEAS_IT_IODC_IRQ15);
  #endif /* __IT_DURATION_MEASUREMENT__ */

  Iodc_CallBackIrq(IODC_IT_IRQ15_ID);

  #ifdef __IT_DURATION_MEASUREMENT__
  RTOS_LeaveItDurationMeasurement(RTOS_MEAS_IT_IODC_IRQ15);
  #endif /* __IT_DURATION_MEASUREMENT__ */
}
#endif /* IODC_IT_IRQ15 == _USED_ */


#if IODC_IT_IRQ16 == _USED_
#if defined(__OSEK__)
__INTERRUPT__ ISR(IODC_Irq16_it)
#else  /* defined(__OSEK__) */
ISR(IODC_Irq16_it)
#endif /* defined(__OSEK__)  */
{
  #ifdef __IT_DURATION_MEASUREMENT__
  RTOS_EnterItDurationMeasurement(RTOS_MEAS_IT_IODC_IRQ16);
  #endif /* __IT_DURATION_MEASUREMENT__ */

  Iodc_CallBackIrq(IODC_IT_IRQ16_ID);

  #ifdef __IT_DURATION_MEASUREMENT__
  RTOS_LeaveItDurationMeasurement(RTOS_MEAS_IT_IODC_IRQ16);
  #endif /* __IT_DURATION_MEASUREMENT__ */
}
#endif /* IODC_IT_IRQ16 == _USED_ */

#if IODC_IT_IRQ17 == _USED_
#if defined(__OSEK__)
__INTERRUPT__ ISR(IODC_Irq17_it)
#else  /* defined(__OSEK__) */
ISR(IODC_Irq17_it)
#endif /* defined(__OSEK__)  */
{
  #ifdef __IT_DURATION_MEASUREMENT__
  RTOS_EnterItDurationMeasurement(RTOS_MEAS_IT_IODC_IRQ17);
  #endif /* __IT_DURATION_MEASUREMENT__ */

  Iodc_CallBackIrq(IODC_IT_IRQ17_ID);

  #ifdef __IT_DURATION_MEASUREMENT__
  RTOS_LeaveItDurationMeasurement(RTOS_MEAS_IT_IODC_IRQ17);
  #endif /* __IT_DURATION_MEASUREMENT__ */
}
#endif /* IODC_IT_IRQ17 == _USED_ */

#if IODC_IT_IRQ18 == _USED_
#if defined(__OSEK__)
__INTERRUPT__ ISR(IODC_Irq18_it)
#else  /* defined(__OSEK__) */
ISR(IODC_Irq18_it)
#endif /* defined(__OSEK__)  */
{
  #ifdef __IT_DURATION_MEASUREMENT__
  RTOS_EnterItDurationMeasurement(RTOS_MEAS_IT_IODC_IRQ18);
  #endif /* __IT_DURATION_MEASUREMENT__ */

  Iodc_CallBackIrq(IODC_IT_IRQ18_ID);

  #ifdef __IT_DURATION_MEASUREMENT__
  RTOS_LeaveItDurationMeasurement(RTOS_MEAS_IT_IODC_IRQ18);
  #endif /* __IT_DURATION_MEASUREMENT__ */
}
#endif /* IODC_IT_IRQ18 == _USED_ */

#if IODC_IT_IRQ19 == _USED_
#if defined(__OSEK__)
__INTERRUPT__ ISR(IODC_Irq19_it)
#else  /* defined(__OSEK__) */
ISR(IODC_Irq19_it)
#endif /* defined(__OSEK__)  */
{
  #ifdef __IT_DURATION_MEASUREMENT__
  RTOS_EnterItDurationMeasurement(RTOS_MEAS_IT_IODC_IRQ19);
  #endif /* __IT_DURATION_MEASUREMENT__ */

  Iodc_CallBackIrq(IODC_IT_IRQ19_ID);

  #ifdef __IT_DURATION_MEASUREMENT__
  RTOS_LeaveItDurationMeasurement(RTOS_MEAS_IT_IODC_IRQ19);
  #endif /* __IT_DURATION_MEASUREMENT__ */
}
#endif /* IODC_IT_IRQ19 == _USED_ */

#if IODC_IT_IRQ20 == _USED_
#if defined(__OSEK__)
__INTERRUPT__ ISR(IODC_Irq20_it)
#else  /* defined(__OSEK__) */
ISR(IODC_Irq20_it)
#endif /* defined(__OSEK__)  */
{
  #ifdef __IT_DURATION_MEASUREMENT__
  RTOS_EnterItDurationMeasurement(RTOS_MEAS_IT_IODC_IRQ20);
  #endif /* __IT_DURATION_MEASUREMENT__ */

  Iodc_CallBackIrq(IODC_IT_IRQ20_ID);

  #ifdef __IT_DURATION_MEASUREMENT__
  RTOS_LeaveItDurationMeasurement(RTOS_MEAS_IT_IODC_IRQ20);
  #endif /* __IT_DURATION_MEASUREMENT__ */
}
#endif /* IODC_IT_IRQ20 == _USED_ */

#if IODC_IT_IRQ21 == _USED_
#if defined(__OSEK__)
__INTERRUPT__ ISR(IODC_Irq21_it)
#else  /* defined(__OSEK__) */
ISR(IODC_Irq21_it)
#endif /* defined(__OSEK__)  */
{
  #ifdef __IT_DURATION_MEASUREMENT__
  RTOS_EnterItDurationMeasurement(RTOS_MEAS_IT_IODC_IRQ21);
  #endif /* __IT_DURATION_MEASUREMENT__ */

  Iodc_CallBackIrq(IODC_IT_IRQ21_ID);

  #ifdef __IT_DURATION_MEASUREMENT__
  RTOS_LeaveItDurationMeasurement(RTOS_MEAS_IT_IODC_IRQ21);
  #endif /* __IT_DURATION_MEASUREMENT__ */
}
#endif /* IODC_IT_IRQ21 == _USED_ */

#if IODC_IT_IRQ22 == _USED_
#if defined(__OSEK__)
__INTERRUPT__ ISR(IODC_Irq22_it)
#else  /* defined(__OSEK__) */
ISR(IODC_Irq22_it)
#endif /* defined(__OSEK__)  */
{
  #ifdef __IT_DURATION_MEASUREMENT__
  RTOS_EnterItDurationMeasurement(RTOS_MEAS_IT_IODC_IRQ22);
  #endif /* __IT_DURATION_MEASUREMENT__ */

  Iodc_CallBackIrq(IODC_IT_IRQ22_ID);

  #ifdef __IT_DURATION_MEASUREMENT__
  RTOS_LeaveItDurationMeasurement(RTOS_MEAS_IT_IODC_IRQ22);
  #endif /* __IT_DURATION_MEASUREMENT__ */
}
#endif /* IODC_IT_IRQ22 == _USED_ */

#if IODC_IT_IRQ23 == _USED_
#if defined(__OSEK__)
__INTERRUPT__ ISR(IODC_Irq23_it)
#else  /* defined(__OSEK__) */
ISR(IODC_Irq23_it)
#endif /* defined(__OSEK__)  */
{
  #ifdef __IT_DURATION_MEASUREMENT__
  RTOS_EnterItDurationMeasurement(RTOS_MEAS_IT_IODC_IRQ23);
  #endif /* __IT_DURATION_MEASUREMENT__ */

  Iodc_CallBackIrq(IODC_IT_IRQ23_ID);

  #ifdef __IT_DURATION_MEASUREMENT__
  RTOS_LeaveItDurationMeasurement(RTOS_MEAS_IT_IODC_IRQ23);
  #endif /* __IT_DURATION_MEASUREMENT__ */
}
#endif /* IODC_IT_IRQ23 == _USED_ */

#if IODC_IT_IRQ24 == _USED_
#if defined(__OSEK__)
__INTERRUPT__ ISR(IODC_Irq24_it)
#else  /* defined(__OSEK__) */
ISR(IODC_Irq24_it)
#endif /* defined(__OSEK__)  */
{
  #ifdef __IT_DURATION_MEASUREMENT__
  RTOS_EnterItDurationMeasurement(RTOS_MEAS_IT_IODC_IRQ24);
  #endif /* __IT_DURATION_MEASUREMENT__ */

  Iodc_CallBackIrq(IODC_IT_IRQ24_ID);

  #ifdef __IT_DURATION_MEASUREMENT__
  RTOS_LeaveItDurationMeasurement(RTOS_MEAS_IT_IODC_IRQ24);
  #endif /* __IT_DURATION_MEASUREMENT__ */
}
#endif /* IODC_IT_IRQ24 == _USED_ */

#if IODC_IT_IRQ25 == _USED_
#if defined(__OSEK__)
__INTERRUPT__ ISR(IODC_Irq25_it)
#else  /* defined(__OSEK__) */
ISR(IODC_Irq25_it)
#endif /* defined(__OSEK__)  */
{
  #ifdef __IT_DURATION_MEASUREMENT__
  RTOS_EnterItDurationMeasurement(RTOS_MEAS_IT_IODC_IRQ25);
  #endif /* __IT_DURATION_MEASUREMENT__ */

  Iodc_CallBackIrq(IODC_IT_IRQ25_ID);

  #ifdef __IT_DURATION_MEASUREMENT__
  RTOS_LeaveItDurationMeasurement(RTOS_MEAS_IT_IODC_IRQ25);
  #endif /* __IT_DURATION_MEASUREMENT__ */
}
#endif /* IODC_IT_IRQ25 == _USED_ */

#if IODC_IT_IRQ26 == _USED_
#if defined(__OSEK__)
__INTERRUPT__ ISR(IODC_Irq26_it)
#else  /* defined(__OSEK__) */
ISR(IODC_Irq26_it)
#endif /* defined(__OSEK__)  */
{
  #ifdef __IT_DURATION_MEASUREMENT__
  RTOS_EnterItDurationMeasurement(RTOS_MEAS_IT_IODC_IRQ26);
  #endif /* __IT_DURATION_MEASUREMENT__ */

  Iodc_CallBackIrq(IODC_IT_IRQ26_ID);

  #ifdef __IT_DURATION_MEASUREMENT__
  RTOS_LeaveItDurationMeasurement(RTOS_MEAS_IT_IODC_IRQ26);
  #endif /* __IT_DURATION_MEASUREMENT__ */
}
#endif /* IODC_IT_IRQ26 == _USED_ */

#if IODC_IT_IRQ27 == _USED_
#if defined(__OSEK__)
__INTERRUPT__ ISR(IODC_Irq27_it)
#else  /* defined(__OSEK__) */
ISR(IODC_Irq27_it)
#endif /* defined(__OSEK__)  */
{
  #ifdef __IT_DURATION_MEASUREMENT__
  RTOS_EnterItDurationMeasurement(RTOS_MEAS_IT_IODC_IRQ27);
  #endif /* __IT_DURATION_MEASUREMENT__ */

  Iodc_CallBackIrq(IODC_IT_IRQ27_ID);

  #ifdef __IT_DURATION_MEASUREMENT__
  RTOS_LeaveItDurationMeasurement(RTOS_MEAS_IT_IODC_IRQ27);
  #endif /* __IT_DURATION_MEASUREMENT__ */
}
#endif /* IODC_IT_IRQ27 == _USED_ */

#if IODC_IT_IRQ28 == _USED_
#if defined(__OSEK__)
__INTERRUPT__ ISR(IODC_Irq28_it)
#else  /* defined(__OSEK__) */
ISR(IODC_Irq28_it)
#endif /* defined(__OSEK__)  */
{
  #ifdef __IT_DURATION_MEASUREMENT__
  RTOS_EnterItDurationMeasurement(RTOS_MEAS_IT_IODC_IRQ28);
  #endif /* __IT_DURATION_MEASUREMENT__ */

  Iodc_CallBackIrq(IODC_IT_IRQ28_ID);

  #ifdef __IT_DURATION_MEASUREMENT__
  RTOS_LeaveItDurationMeasurement(RTOS_MEAS_IT_IODC_IRQ28);
  #endif /* __IT_DURATION_MEASUREMENT__ */
}
#endif /* IODC_IT_IRQ28 == _USED_ */


/*______ L O C A L - F U N C T I O N S _______________________________________*/

/*----------------------------------------------------------------------------*/
/*Name : Iodc_CallBackIrq                                                     */
/*Role : Call an applicative irq call-back fuction                            */
/*Interface :                                                                 */
/*  - IrqNumber : Irq interrupt number                                        */
/*Pre-condition : -                                                           */
/*Constraints :  -                                                            */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [If the Irq is subscribed, call the applicative function]               */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#ifdef IODC_IRQ_USED
static void Iodc_CallBackIrq(IODC_IrqID_t IrqNumber)
{
  #ifdef __TASK_DURATION_MEASUREMENT_WITH_TIMER__
  ubyte OldMeasuredTask;

  RTOS_DisableAllInterrupts();
  OldMeasuredTask = RTOS_MeasuredTask;
  RTOS_TaskMeasurementEnterIt(OldMeasuredTask);
  RTOS_EnableAllInterrupts();
  #endif /* __TASK_DURATION_MEASUREMENT_WITH_TIMER__ */

  if (Iodc_IrqCallBackFctTable[IrqNumber]!= NULL)
  {
    Iodc_IrqCallBackFctTable[IrqNumber]();
  }

  #ifdef __TASK_DURATION_MEASUREMENT_WITH_TIMER__
  RTOS_DisableAllInterrupts();
  RTOS_TaskMeasurementLeaveIt(OldMeasuredTask);
  RTOS_EnableAllInterrupts();
  #endif /* __TASK_DURATION_MEASUREMENT_WITH_TIMER__ */
}
#endif /* IODC_IRQ_USED */

#endif /*__CY_TV2__*/
/*_____ E N D _____ (iodc_tv2.c) _____________________________________________*/

