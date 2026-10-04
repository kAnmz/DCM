/******************************************************************************/
/*@F_NAME:              iodc_rh850.c                                          */
/*@F_PURPOSE:           iodc module                                           */
/*@F_CREATED_BY:        shubin liang                                          */
/*@F_CREATION_DATE:     2017.03.17                                            */
/*@F_MPROC_TYPE:        rh850 f1x                                             */
/************************************** (C) Copyright 2013 Magneti Marelli ****/

/*______ I N C L U D E - F I L E S ___________________________________________*/

#include "syst.h"
#include "iodc_config.h"
#include "iodc_priv.h"
#include "iodc.h"
#include "iodd.h"

#ifdef __RH850__

/*______ L O C A L - D E F I N E _____________________________________________*/
#define IODC_IRQ_FCT_NUM 17

/*______ L O C A L - T Y P E S________________________________________________*/


/*______ G L O B A L - D A T A _______________________________________________*/


/*______ L O C A L - D A T A _________________________________________________*/

/* table of applicative call-back function for irq interrupts */
#ifdef IODC_IRQ_USED

#ifdef __RH850__
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
extern void IODC_IT_IRQ08_CALLBACK(void);
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

#if IODC_IT_IRQ_NMI  == _USED_
extern void IODC_IT_IRQ_NMI_CALLBACK(void);
#endif /* IODC_IT_IRQ_NMI == _USED_ */
#endif /*__NEC_V850__*/

/* it is mandatory a table with constant-size whatever the IRQs installed */
static void (*const Iodc_IrqCallBackFctTable[IODC_IRQ_FCT_NUM])(void) =
{

#ifdef __RH850__
  IODC_IT_IRQ0_CALLBACK,
  IODC_IT_IRQ1_CALLBACK,
  IODC_IT_IRQ2_CALLBACK,
  IODC_IT_IRQ3_CALLBACK,
  IODC_IT_IRQ4_CALLBACK,
  IODC_IT_IRQ5_CALLBACK,
  IODC_IT_IRQ6_CALLBACK,
  IODC_IT_IRQ7_CALLBACK,
  IODC_IT_IRQ8_CALLBACK,
  IODC_IT_IRQ9_CALLBACK,
  IODC_IT_IRQ10_CALLBACK,
  IODC_IT_IRQ11_CALLBACK,
  IODC_IT_IRQ12_CALLBACK,
  IODC_IT_IRQ13_CALLBACK,
  IODC_IT_IRQ14_CALLBACK,
  IODC_IT_IRQ15_CALLBACK,
  IODC_IT_IRQ_NMI_CALLBACK
#endif /*__NEC_V850__*/

};

#endif /* IODC_IRQ_USED */


/*______ L O C A L - M A C R O S _____________________________________________*/


/*______ I M P O R T - F U N C T I O N S - P R O T O T Y P E S _______________*/


/*______ L O C A L - F U N C T I O N S - P R O T O T Y P E S _________________*/

#ifdef IODC_IRQ_USED
static __NEAR_FUNC__ void Iodc_CallBackIrq(ubyte IrqNumber);
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
#ifdef __RH850__
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

  Iodc_CallBackIrq(IODC_IRQ0);

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

  Iodc_CallBackIrq(IODC_IRQ1);

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

  Iodc_CallBackIrq(IODC_IRQ2);

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

  Iodc_CallBackIrq(IODC_IRQ3);

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

  Iodc_CallBackIrq(IODC_IRQ4);

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

  Iodc_CallBackIrq(IODC_IRQ5);

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

  Iodc_CallBackIrq(IODC_IRQ6);

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

  Iodc_CallBackIrq(IODC_IRQ7);

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

  Iodc_CallBackIrq(IODC_IRQ8);

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

  Iodc_CallBackIrq(IODC_IRQ9);

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

  Iodc_CallBackIrq(IODC_IRQ10);

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

  Iodc_CallBackIrq(IODC_IRQ11);

  #ifdef __IT_DURATION_MEASUREMENT__
  RTOS_LeaveItDurationMeasurement(RTOS_MEAS_IT_IODC_IRQ11);
  #endif /* __IT_DURATION_MEASUREMENT__ */
}
#endif /* IODC_IT_IRQ11 == _USED_ */
#if 0
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

  Iodc_CallBackIrq(IODC_IRQ12);

  #ifdef __IT_DURATION_MEASUREMENT__
  RTOS_LeaveItDurationMeasurement(RTOS_MEAS_IT_IODC_IRQ12);
  #endif /* __IT_DURATION_MEASUREMENT__ */
}
#endif /* IODC_IT_IRQ12 == _USED_ */
#endif

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

  Iodc_CallBackIrq(IODC_IRQ13);

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

  Iodc_CallBackIrq(IODC_IRQ14);

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

  Iodc_CallBackIrq(IODC_IRQ15);

  #ifdef __IT_DURATION_MEASUREMENT__
  RTOS_LeaveItDurationMeasurement(RTOS_MEAS_IT_IODC_IRQ15);
  #endif /* __IT_DURATION_MEASUREMENT__ */
}
#endif /* IODC_IT_IRQ15 == _USED_ */

#if IODC_IT_IRQ_NMI == _USED_
ISR(IODC_IrqNMI_it)
{
  #ifdef __IT_DURATION_MEASUREMENT__
  RTOS_EnterItDurationMeasurement(RTOS_MEAS_IT_IODC_IRQNMI);
  #endif /* __IT_DURATION_MEASUREMENT__ */

  Iodc_CallBackIrq(IODC_IRQ_NMI);

  #ifdef __IT_DURATION_MEASUREMENT__
  RTOS_LeaveItDurationMeasurement(RTOS_MEAS_IT_IODC_IRQNMI);
  #endif /* __IT_DURATION_MEASUREMENT__ */
}
#endif /* IODC_IT_IRQ_NMI == _USED_ */
#endif  /* __RH850__ */


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
static __NEAR_FUNC__ void Iodc_CallBackIrq(ubyte IrqNumber)
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
#endif /*__RH850__*/
/*_____ E N D _____ (iodc_rh850.c) _________________________________________________*/

