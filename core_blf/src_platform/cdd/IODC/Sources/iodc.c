/******************************************************************************/
/*@F_NAME:              iodc.c                                                */
/*@F_PURPOSE:           iodc module                                           */
/*@F_CREATED_BY:        M. Sergent                                            */
/*@F_CREATION_DATE:     25/08/2000                                            */
/*@F_MPROC_TYPE:        NEC_V850 Fx3/Dx3, MC9S12xx, MC9S08xx                  */
/*                      Renesas RL78 D1A, RL78 F12,IMX53x,IMX6x               */
/************************************** (C) Copyright 2013 Magneti Marelli ****/

/*______ I N C L U D E - F I L E S ___________________________________________*/

#include "syst.h"
#include "iodc_config.h"
#include "iodc_priv.h"
#include "iodc.h"
#include "iodd.h"

#ifndef __BOOT_LINK__
/* #include "sysm_appl.h" */  /*TODO: need to implement */
/* #include "safm.h" */   /* TODO: need to implement*/
#endif

#ifdef IODC_LED_MATRIX_USED

#ifdef IODC_SHIFT_REGISTER_ACCESS_USED
#include "spic.h"
#endif /* IODC_SHIFT_REGISTER_ACCESS_USED */

#if IODC_LED_MATRIX_REFRESH == IODC_LED_MATRIX_ISR_REFRESH
#include "timc.h"
#endif /* IODC_LED_MATRIX_REFRESH == IODC_LED_MATRIX_ISR_REFRESH */

#endif /* IODC_LED_MATRIX_USED */

#if defined IODC_LED_MATRIX_TASK_REFRESH_USED || \
    defined IODC_PORT_SETUP_PERIODIC_REFRESH
#include "wkss.h"
#endif /* defined IODC_LED_MATRIX_TASK_REFRESH_USED || \
          defined IODC_PORT_SETUP_PERIODIC_REFRESH */


#ifdef IODC_INPUT_MATRIX_USED
#if IODC_INPUT_MATRIX_SCAN_REFRESH == IODC_INPUT_MATRIX_ISR_REFRESH
#include "timc.h"
#endif /* IODC_INPUT_MATRIX_SCAN_REFRESH == IODC_INPUT_MATRIX_ISR_REFRESH */
#endif /* IODC_INPUT_MATRIX_USED */


/*______ L O C A L - D E F I N E _____________________________________________*/

#ifdef IODC_DIRECT_ACCESS_USED

#if (IODC_NUMBER_OF_LINE_PIN > 8)

#define Iodc_MASK_BIT1  (ushort)0x01
#define Iodc_MASK_BIT2  (ushort)0x02
#define Iodc_MASK_BIT3  (ushort)0x04
#define Iodc_MASK_BIT4  (ushort)0x08
#define Iodc_MASK_BIT5  (ushort)0x10
#define Iodc_MASK_BIT6  (ushort)0x20
#define Iodc_MASK_BIT7  (ushort)0x40
#define Iodc_MASK_BIT8  (ushort)0x80

#define Iodc_MASK_BIT9  (ushort)0x0100
#define Iodc_MASK_BIT10 (ushort)0x0200
#define Iodc_MASK_BIT11 (ushort)0x0400
#define Iodc_MASK_BIT12 (ushort)0x0800
#define Iodc_MASK_BIT13 (ushort)0x1000
#define Iodc_MASK_BIT14 (ushort)0x2000
#define Iodc_MASK_BIT15 (ushort)0x4000
#define Iodc_MASK_BIT16 (ushort)0x8000

#else

#define Iodc_MASK_BIT1  (ubyte)0x01
#define Iodc_MASK_BIT2  (ubyte)0x02
#define Iodc_MASK_BIT3  (ubyte)0x04
#define Iodc_MASK_BIT4  (ubyte)0x08
#define Iodc_MASK_BIT5  (ubyte)0x10
#define Iodc_MASK_BIT6  (ubyte)0x20
#define Iodc_MASK_BIT7  (ubyte)0x40
#define Iodc_MASK_BIT8  (ubyte)0x80

#endif /* IODC_NUMBER_OF_LINE_PIN > 8 */

#endif /* IODC_DIRECT_ACCESS_USED */

#ifdef IODC_LED_MATRIX_USED
#ifdef IODC_LED_MATRIX_RELAX_TIME_USED
#define Iodc_RELAX_COLUMN    255
#endif /* IODC_LED_MATRIX_RELAX_TIME_USED */
#endif /* IODC_LED_MATRIX_USED */


/*______ L O C A L - T Y P E S________________________________________________*/


/*______ G L O B A L - D A T A _______________________________________________*/

#ifdef IODC_LED_MATRIX_USED
/*  IODC_TabStateLed, state of led                                  */
/*  Memory representation :                                         */
/*       line (each bit with 1 = led on and 0= led off)             */
/* line                                                             */
/*     13 _ _ _ _ _ _ _ _ _ _ _ _ _ 0                               */
/*       |_|_|_|_|_|_|_|_|_|_|_|_|_| column 1                       */
/*       |_|_|_|_|_|_|_|_|_|_|_|_|_| column 2                       */
/*       |_|_|_|_|_|_|_|_|_|_|_|_|_| column 3                       */
/*       |_|_|_|_|_|_|_|_|_|_|_|_|_| column 4                       */

  IODC_TabStateLed_t IODC_TabStateLed[IODC_NUMBER_OF_COLUMN_PIN];

  #ifdef IODC_LED_MATRIX_RELAX_TIME_USED
  ushort IODC_RelaxTimeTick;
  #endif /* IODC_LED_MATRIX_RELAX_TIME_USED */

#endif /* IODC_LED_MATRIX_USED */


#ifdef IODC_INPUT_MATRIX_USED

#if (IODC_NUMBER_OF_INPUT_MATRIX > 0)
         bitfield_byte_t IODC_TabStateInputMatrix1[IODC_MUXIN_NB_SAMPLE];
volatile bitfield_byte_t IODC_TabStateButtonMatrix1[IODC_NB_COLUMN_INMUX_1];

ubyte IODC_IndexMatrix;
ubyte IODC_LastNoRotaryIndex1;
ubyte IODC_LastNoRotaryColumn1;
#endif /* (IODC_NUMBER_OF_INPUT_MATRIX > 0) */

#if (IODC_NUMBER_OF_INPUT_MATRIX > 1)
         bitfield_byte_t IODC_TabStateInputMatrix2[IODC_MUXIN_NB_SAMPLE];
volatile bitfield_byte_t IODC_TabStateButtonMatrix2[IODC_NB_COLUMN_INMUX_2];

ubyte IODC_IndexMatrix2;
ubyte IODC_LastNoRotaryIndex2;
ubyte IODC_LastNoRotaryColumn2;
#endif /* (IODC_NUMBER_OF_INPUT_MATRIX > 1) */

#endif /* IODC_INPUT_MATRIX_USED */


/*______ L O C A L - D A T A _________________________________________________*/

#ifdef IODC_LED_MATRIX_USED

/* current column refreshed */
#if (IODC_NUMBER_OF_COLUMN_PIN > 1)
static ubyte Iodc_CurrentColumn;
#else
/* case : shift register alone (no column) */
#define Iodc_CurrentColumn  0
#endif /* (IODC_NUMBER_OF_COLUMN_PIN > 1) */

#endif /* IODC_LED_MATRIX_USED */


#ifdef IODC_INPUT_MATRIX_USED

#if (IODC_NUMBER_OF_INPUT_MATRIX > 0)
#if (IODC_NB_COLUMN_INMUX_1 > 1)
/* Current column to active for the first matrix */
static ubyte Iodc_CurrentColumn_InMux_1;
#else
#define Iodc_CurrentColumn_InMux_1  ((ubyte)0)
#endif /* (IODC_NB_COLUMN_INMUX_1 > 1) */

#if (IODC_NUMBER_OF_INPUT_MATRIX > 1)
#if (IODC_NB_COLUMN_INMUX_2 > 1)
/* Current column to active for the secondary matrix */
static ubyte Iodc_CurrentColumn_InMux_2;
#else
#define Iodc_CurrentColumn_InMux_2  ((ubyte)0)
#endif /* (IODC_NB_COLUMN_INMUX_2 > 1) */

#endif /* (IODC_NUMBER_OF_INPUT_MATRIX > 1) */
#endif /* (IODC_NUMBER_OF_INPUT_MATRIX > 0) */
#endif /* IODC_INPUT_MATRIX_USED */


/* table of applicative call-back function for irq interrupts */
#ifdef IODC_IRQ_USED

#if defined(__MC9S12xx__)
#if IODC_IT_IRQ0 == _USED_
extern void IODC_IT_IRQ0_CALLBACK(void);
#endif /* IODC_IT_IRQ0 == _USED_ */

#if IODC_IT_IRQ1  == _USED_
extern void IODC_IT_IRQ1_CALLBACK(void);
#endif /* IODC_IT_IRQ1 == _USED_ */

#if IODC_IT_IRQ2  == _USED_
extern void IODC_IT_IRQ2_CALLBACK(void);
#endif /* IODC_IT_IRQ2 == _USED_ */

#if defined(__MC9S12xx__)
#if IODC_IT_IRQ3  == _USED_
extern void IODC_IT_IRQ3_CALLBACK(void);
#endif /* IODC_IT_IRQ3 == _USED_ */

#if IODC_IT_IRQ4  == _USED_
extern void IODC_IT_IRQ4_CALLBACK(void);
#endif /* IODC_IT_IRQ4 == _USED_ */

#if IODC_IT_IRQ5  == _USED_
extern void IODC_IT_IRQ5_CALLBACK(void);
#endif /* IODC_IT_IRQ5 == _USED_ */
#endif /* defined(__MC9S12xx__) */

#if defined(__MC9S12xx__)
#if IODC_IT_IRQ6  == _USED_
extern void IODC_IT_IRQ6_CALLBACK(void);
#endif /* IODC_IT_IRQ6 == _USED_ */

#if IODC_IT_IRQ7  == _USED_
extern void IODC_IT_IRQ7_CALLBACK(void);
#endif /* IODC_IT_IRQ7 == _USED_ */

#if IODC_IT_IRQ8  == _USED_
extern void IODC_IT_IRQ8_CALLBACK(void);
#endif /* IODC_IT_IRQ8 == _USED_ */

/* MC9S12-H variant */
#if defined(__MC9S12H__)
#if IODC_IT_IRQ9  == _USED_
extern void IODC_IT_IRQ9_CALLBACK(void);
#endif /* IODC_IT_IRQ9 == _USED_ */

#if IODC_IT_IRQ10  == _USED_
extern void IODC_IT_IRQ10_CALLBACK(void);
#endif /* IODC_IT_IRQ10 == _USED_ */

#if IODC_IT_IRQ11  == _USED_
extern void IODC_IT_IRQ11_CALLBACK(void);
#endif /* IODC_IT_IRQ11 == _USED_ */

#if IODC_IT_IRQ12  == _USED_
extern void IODC_IT_IRQ12_CALLBACK(void);
#endif /* IODC_IT_IRQ12 == _USED_ */
#endif /* defined(__MC9S12H__) */
#endif /* defined(__MC9S12xx__) */
#endif /* defined(__MC9S12xx__) */

#ifdef __MC9S08xx__
/* Unique IRQ pin               */
#if (IODC_IT_IRQPIN  == _USED_)
extern void IODC_IT_IRQPIN_CALLBACK(void);
#endif /* IODC_IT_IRQ == _USED_ */

/* 8 KBI pins                   */
#if (IODC_IT_IRQ0  == _USED_)
extern void IODC_IT_IRQ0_CALLBACK(void);
#endif /* IODC_IT_IRQ0 == _USED_ */

#if (IODC_IT_IRQ1  == _USED_)
extern void IODC_IT_IRQ1_CALLBACK(void);
#endif /* IODC_IT_IRQ1 == _USED_ */

#if (IODC_IT_IRQ2  == _USED_)
extern void IODC_IT_IRQ2_CALLBACK(void);
#endif /* IODC_IT_IRQ2 == _USED_ */

#if (IODC_IT_IRQ3  == _USED_)
extern void IODC_IT_IRQ3_CALLBACK(void);
#endif /* IODC_IT_IRQ3 == _USED_ */

#if (IODC_IT_IRQ4  == _USED_)
extern void IODC_IT_IRQ4_CALLBACK(void);
#endif /* IODC_IT_IRQ4 == _USED_ */

#if (IODC_IT_IRQ5  == _USED_)
extern void IODC_IT_IRQ5_CALLBACK(void);
#endif /* IODC_IT_IRQ5 == _USED_ */

#if (IODC_IT_IRQ6  == _USED_)
extern void IODC_IT_IRQ6_CALLBACK(void);
#endif /* IODC_IT_IRQ6 == _USED_ */

#if (IODC_IT_IRQ7  == _USED_)
extern void IODC_IT_IRQ7_CALLBACK(void);
#endif /* IODC_IT_IRQ7 == _USED_ */

#endif /* __MC9S08xx__ */

#ifdef __TX49__
#if IODC_IT_IRQ00 == _USED_
extern void IODC_IT_IRQ00_CALLBACK(void);
#endif /* IODC_IT_IRQ00 == _USED_ */

#if IODC_IT_IRQ01  == _USED_
extern void IODC_IT_IRQ01_CALLBACK(void);
#endif /* IODC_IT_IRQ01 == _USED_ */

#if IODC_IT_IRQ02  == _USED_
extern void IODC_IT_IRQ02_CALLBACK(void);
#endif /* IODC_IT_IRQ02 == _USED_ */

#if IODC_IT_IRQ03  == _USED_
extern void IODC_IT_IRQ03_CALLBACK(void);
#endif /* IODC_IT_IRQ03 == _USED_ */
#endif /* __TX49__ */

#ifdef __NEC_V850__
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

#if defined(__FSL_IMX53x__) || defined(__FSL_IMX6x__)
#if IODC_IT_IRQ0 == _USED_
extern void IODC_IT_IRQ0_CALLBACK(void);
#endif /* IODC_IT_IRQ0 == _USED_ */

#if IODC_IT_IRQ1 == _USED_
extern void IODC_IT_IRQ1_CALLBACK(void);
#endif /* IODC_IT_IRQ1 == _USED_ */

#if IODC_IT_IRQ2 == _USED_
extern void IODC_IT_IRQ2_CALLBACK(void);
#endif /* IODC_IT_IRQ2 == _USED_ */

#if IODC_IT_IRQ3 == _USED_
extern void IODC_IT_IRQ3_CALLBACK(void);
#endif /* IODC_IT_IRQ3 == _USED_ */

#if IODC_IT_IRQ4 == _USED_
extern void IODC_IT_IRQ4_CALLBACK(void);
#endif /* IODC_IT_IRQ4 == _USED_ */

#if IODC_IT_IRQ5 == _USED_
extern void IODC_IT_IRQ5_CALLBACK(void);
#endif /* IODC_IT_IRQ5 == _USED_ */

#if IODC_IT_IRQ6 == _USED_
extern void IODC_IT_IRQ6_CALLBACK(void);
#endif /* IODC_IT_IRQ6 == _USED_ */

#if IODC_IT_IRQ7 == _USED_
extern void IODC_IT_IRQ7_CALLBACK(void);
#endif /* IODC_IT_IRQ7 == _USED_ */

#if IODC_IT_IRQ8 == _USED_
extern void IODC_IT_IRQ8_CALLBACK(void);
#endif /* IODC_IT_IRQ8 == _USED_ */

#if IODC_IT_IRQ9 == _USED_
extern void IODC_IT_IRQ9_CALLBACK(void);
#endif /* IODC_IT_IRQ9 == _USED_ */

#if IODC_IT_IRQ10 == _USED_
extern void IODC_IT_IRQ10_CALLBACK(void);
#endif /* IODC_IT_IRQ10 == _USED_ */

#if IODC_IT_IRQ11 == _USED_
extern void IODC_IT_IRQ11_CALLBACK(void);
#endif /* IODC_IT_IRQ11 == _USED_ */

#if IODC_IT_IRQ12 == _USED_
extern void IODC_IT_IRQ12_CALLBACK(void);
#endif /* IODC_IT_IRQ12 == _USED_ */

#if IODC_IT_IRQ13 == _USED_
extern void IODC_IT_IRQ13_CALLBACK(void);
#endif /* IODC_IT_IRQ13 == _USED_ */

#if IODC_IT_IRQ14 == _USED_
extern void IODC_IT_IRQ14_CALLBACK(void);
#endif /* IODC_IT_IRQ14 == _USED_ */

#if IODC_IT_IRQ15 == _USED_
extern void IODC_IT_IRQ15_CALLBACK(void);
#endif /* IODC_IT_IRQ15 == _USED_ */

#if IODC_IT_IRQ16 == _USED_
extern void IODC_IT_IRQ16_CALLBACK(void);
#endif /* IODC_IT_IRQ16 == _USED_ */

#if IODC_IT_IRQ17 == _USED_
extern void IODC_IT_IRQ17_CALLBACK(void);
#endif /* IODC_IT_IRQ17 == _USED_ */

#if IODC_IT_IRQ18 == _USED_
extern void IODC_IT_IRQ18_CALLBACK(void);
#endif /* IODC_IT_IRQ18 == _USED_ */

#if IODC_IT_IRQ19 == _USED_
extern void IODC_IT_IRQ19_CALLBACK(void);
#endif /* IODC_IT_IRQ19 == _USED_ */

#if IODC_IT_IRQ20 == _USED_
extern void IODC_IT_IRQ20_CALLBACK(void);
#endif /* IODC_IT_IRQ20 == _USED_ */

#if IODC_IT_IRQ21 == _USED_
extern void IODC_IT_IRQ21_CALLBACK(void);
#endif /* IODC_IT_IRQ21 == _USED_ */

#if IODC_IT_IRQ22 == _USED_
extern void IODC_IT_IRQ22_CALLBACK(void);
#endif /* IODC_IT_IRQ22 == _USED_ */

#if IODC_IT_IRQ23 == _USED_
extern void IODC_IT_IRQ23_CALLBACK(void);
#endif /* IODC_IT_IRQ23 == _USED_ */

#if IODC_IT_IRQ24 == _USED_
extern void IODC_IT_IRQ24_CALLBACK(void);
#endif /* IODC_IT_IRQ24 == _USED_ */

#if IODC_IT_IRQ25 == _USED_
extern void IODC_IT_IRQ25_CALLBACK(void);
#endif /* IODC_IT_IRQ25 == _USED_ */

#if IODC_IT_IRQ26 == _USED_
extern void IODC_IT_IRQ26_CALLBACK(void);
#endif /* IODC_IT_IRQ26 == _USED_ */

#if IODC_IT_IRQ27 == _USED_
extern void IODC_IT_IRQ27_CALLBACK(void);
#endif /* IODC_IT_IRQ27 == _USED_ */

#if IODC_IT_IRQ28 == _USED_
extern void IODC_IT_IRQ28_CALLBACK(void);
#endif /* IODC_IT_IRQ28 == _USED_ */

#if IODC_IT_IRQ29 == _USED_
extern void IODC_IT_IRQ29_CALLBACK(void);
#endif /* IODC_IT_IRQ29 == _USED_ */

#if IODC_IT_IRQ30 == _USED_
extern void IODC_IT_IRQ30_CALLBACK(void);
#endif /* IODC_IT_IRQ30 == _USED_ */

#if IODC_IT_IRQ31 == _USED_
extern void IODC_IT_IRQ31_CALLBACK(void);
#endif /* IODC_IT_IRQ31 == _USED_ */

#if IODC_IT_IRQ32 == _USED_
extern void IODC_IT_IRQ32_CALLBACK(void);
#endif /* IODC_IT_IRQ32 == _USED_ */

#if IODC_IT_IRQ33 == _USED_
extern void IODC_IT_IRQ33_CALLBACK(void);
#endif /* IODC_IT_IRQ33 == _USED_ */

#if IODC_IT_IRQ34 == _USED_
extern void IODC_IT_IRQ34_CALLBACK(void);
#endif /* IODC_IT_IRQ34 == _USED_ */

#if IODC_IT_IRQ35 == _USED_
extern void IODC_IT_IRQ35_CALLBACK(void);
#endif /* IODC_IT_IRQ35 == _USED_ */

#if IODC_IT_IRQ36 == _USED_
extern void IODC_IT_IRQ36_CALLBACK(void);
#endif /* IODC_IT_IRQ36 == _USED_ */

#if IODC_IT_IRQ37 == _USED_
extern void IODC_IT_IRQ37_CALLBACK(void);
#endif /* IODC_IT_IRQ37 == _USED_ */

#if IODC_IT_IRQ38 == _USED_
extern void IODC_IT_IRQ38_CALLBACK(void);
#endif /* IODC_IT_IRQ38 == _USED_ */

#if IODC_IT_IRQ39 == _USED_
extern void IODC_IT_IRQ39_CALLBACK(void);
#endif /* IODC_IT_IRQ39 == _USED_ */

#if IODC_IT_IRQ40 == _USED_
extern void IODC_IT_IRQ40_CALLBACK(void);
#endif /* IODC_IT_IRQ40 == _USED_ */

#if IODC_IT_IRQ41 == _USED_
extern void IODC_IT_IRQ41_CALLBACK(void);
#endif /* IODC_IT_IRQ41 == _USED_ */

#if IODC_IT_IRQ42 == _USED_
extern void IODC_IT_IRQ42_CALLBACK(void);
#endif /* IODC_IT_IRQ42 == _USED_ */

#if IODC_IT_IRQ43 == _USED_
extern void IODC_IT_IRQ43_CALLBACK(void);
#endif /* IODC_IT_IRQ43 == _USED_ */

#if IODC_IT_IRQ44 == _USED_
extern void IODC_IT_IRQ44_CALLBACK(void);
#endif /* IODC_IT_IRQ44 == _USED_ */

#if IODC_IT_IRQ45 == _USED_
extern void IODC_IT_IRQ45_CALLBACK(void);
#endif /* IODC_IT_IRQ45 == _USED_ */

#if IODC_IT_IRQ46 == _USED_
extern void IODC_IT_IRQ46_CALLBACK(void);
#endif /* IODC_IT_IRQ46 == _USED_ */

#if IODC_IT_IRQ47 == _USED_
extern void IODC_IT_IRQ47_CALLBACK(void);
#endif /* IODC_IT_IRQ47 == _USED_ */

#if IODC_IT_IRQ48 == _USED_
extern void IODC_IT_IRQ48_CALLBACK(void);
#endif /* IODC_IT_IRQ48 == _USED_ */

#if IODC_IT_IRQ49 == _USED_
extern void IODC_IT_IRQ49_CALLBACK(void);
#endif /* IODC_IT_IRQ49 == _USED_ */

#if IODC_IT_IRQ50 == _USED_
extern void IODC_IT_IRQ50_CALLBACK(void);
#endif /* IODC_IT_IRQ50 == _USED_ */

#if IODC_IT_IRQ51 == _USED_
extern void IODC_IT_IRQ51_CALLBACK(void);
#endif /* IODC_IT_IRQ51 == _USED_ */

#if IODC_IT_IRQ52 == _USED_
extern void IODC_IT_IRQ52_CALLBACK(void);
#endif /* IODC_IT_IRQ52 == _USED_ */

#if IODC_IT_IRQ53 == _USED_
extern void IODC_IT_IRQ53_CALLBACK(void);
#endif /* IODC_IT_IRQ53 == _USED_ */

#if IODC_IT_IRQ54 == _USED_
extern void IODC_IT_IRQ54_CALLBACK(void);
#endif /* IODC_IT_IRQ54 == _USED_ */

#if IODC_IT_IRQ55 == _USED_
extern void IODC_IT_IRQ55_CALLBACK(void);
#endif /* IODC_IT_IRQ55 == _USED_ */

#if IODC_IT_IRQ56 == _USED_
extern void IODC_IT_IRQ56_CALLBACK(void);
#endif /* IODC_IT_IRQ56 == _USED_ */

#if IODC_IT_IRQ57 == _USED_
extern void IODC_IT_IRQ57_CALLBACK(void);
#endif /* IODC_IT_IRQ57 == _USED_ */

#if IODC_IT_IRQ58 == _USED_
extern void IODC_IT_IRQ58_CALLBACK(void);
#endif /* IODC_IT_IRQ58 == _USED_ */

#if IODC_IT_IRQ59 == _USED_
extern void IODC_IT_IRQ59_CALLBACK(void);
#endif /* IODC_IT_IRQ59 == _USED_ */

#if IODC_IT_IRQ60 == _USED_
extern void IODC_IT_IRQ60_CALLBACK(void);
#endif /* IODC_IT_IRQ60 == _USED_ */

#if IODC_IT_IRQ61 == _USED_
extern void IODC_IT_IRQ61_CALLBACK(void);
#endif /* IODC_IT_IRQ61 == _USED_ */

#if IODC_IT_IRQ62 == _USED_
extern void IODC_IT_IRQ62_CALLBACK(void);
#endif /* IODC_IT_IRQ62 == _USED_ */

#if IODC_IT_IRQ63 == _USED_
extern void IODC_IT_IRQ63_CALLBACK(void);
#endif /* IODC_IT_IRQ63 == _USED_ */

#if IODC_IT_IRQ64 == _USED_
extern void IODC_IT_IRQ64_CALLBACK(void);
#endif /* IODC_IT_IRQ64 == _USED_ */

#if IODC_IT_IRQ65 == _USED_
extern void IODC_IT_IRQ65_CALLBACK(void);
#endif /* IODC_IT_IRQ65 == _USED_ */

#if IODC_IT_IRQ66 == _USED_
extern void IODC_IT_IRQ66_CALLBACK(void);
#endif /* IODC_IT_IRQ66 == _USED_ */

#if IODC_IT_IRQ67 == _USED_
extern void IODC_IT_IRQ67_CALLBACK(void);
#endif /* IODC_IT_IRQ67 == _USED_ */

#if IODC_IT_IRQ68 == _USED_
extern void IODC_IT_IRQ68_CALLBACK(void);
#endif /* IODC_IT_IRQ68 == _USED_ */

#if IODC_IT_IRQ69 == _USED_
extern void IODC_IT_IRQ69_CALLBACK(void);
#endif /* IODC_IT_IRQ9 == _USED_ */

#if IODC_IT_IRQ70 == _USED_
extern void IODC_IT_IRQ70_CALLBACK(void);
#endif /* IODC_IT_IRQ70 == _USED_ */

#if IODC_IT_IRQ71 == _USED_
extern void IODC_IT_IRQ71_CALLBACK(void);
#endif /* IODC_IT_IRQ71 == _USED_ */

#if IODC_IT_IRQ72 == _USED_
extern void IODC_IT_IRQ72_CALLBACK(void);
#endif /* IODC_IT_IRQ72 == _USED_ */

#if IODC_IT_IRQ73 == _USED_
extern void IODC_IT_IRQ73_CALLBACK(void);
#endif /* IODC_IT_IRQ73 == _USED_ */

#if IODC_IT_IRQ74 == _USED_
extern void IODC_IT_IRQ74_CALLBACK(void);
#endif /* IODC_IT_IRQ74 == _USED_ */

#if IODC_IT_IRQ75 == _USED_
extern void IODC_IT_IRQ75_CALLBACK(void);
#endif /* IODC_IT_IRQ75 == _USED_ */

#if IODC_IT_IRQ76 == _USED_
extern void IODC_IT_IRQ76_CALLBACK(void);
#endif /* IODC_IT_IRQ76 == _USED_ */

#if IODC_IT_IRQ77 == _USED_
extern void IODC_IT_IRQ77_CALLBACK(void);
#endif /* IODC_IT_IRQ77 == _USED_ */

#if IODC_IT_IRQ78 == _USED_
extern void IODC_IT_IRQ78_CALLBACK(void);
#endif /* IODC_IT_IRQ78 == _USED_ */

#if IODC_IT_IRQ79 == _USED_
extern void IODC_IT_IRQ79_CALLBACK(void);
#endif /* IODC_IT_IRQ79 == _USED_ */

#if IODC_IT_IRQ80 == _USED_
extern void IODC_IT_IRQ80_CALLBACK(void);
#endif /* IODC_IT_IRQ80 == _USED_ */

#if IODC_IT_IRQ81 == _USED_
extern void IODC_IT_IRQ81_CALLBACK(void);
#endif /* IODC_IT_IRQ81 == _USED_ */

#if IODC_IT_IRQ82 == _USED_
extern void IODC_IT_IRQ82_CALLBACK(void);
#endif /* IODC_IT_IRQ82 == _USED_ */

#if IODC_IT_IRQ83 == _USED_
extern void IODC_IT_IRQ83_CALLBACK(void);
#endif /* IODC_IT_IRQ83 == _USED_ */

#if IODC_IT_IRQ84 == _USED_
extern void IODC_IT_IRQ84_CALLBACK(void);
#endif /* IODC_IT_IRQ84 == _USED_ */

#if IODC_IT_IRQ85 == _USED_
extern void IODC_IT_IRQ85_CALLBACK(void);
#endif /* IODC_IT_IRQ85 == _USED_ */

#if IODC_IT_IRQ86 == _USED_
extern void IODC_IT_IRQ86_CALLBACK(void);
#endif /* IODC_IT_IRQ86 == _USED_ */

#if IODC_IT_IRQ87 == _USED_
extern void IODC_IT_IRQ87_CALLBACK(void);
#endif /* IODC_IT_IRQ87 == _USED_ */

#if IODC_IT_IRQ88 == _USED_
extern void IODC_IT_IRQ88_CALLBACK(void);
#endif /* IODC_IT_IRQ88 == _USED_ */

#if IODC_IT_IRQ89 == _USED_
extern void IODC_IT_IRQ89_CALLBACK(void);
#endif /* IODC_IT_IRQ89 == _USED_ */

#if IODC_IT_IRQ90 == _USED_
extern void IODC_IT_IRQ90_CALLBACK(void);
#endif /* IODC_IT_IRQ90 == _USED_ */

#if IODC_IT_IRQ91 == _USED_
extern void IODC_IT_IRQ91_CALLBACK(void);
#endif /* IODC_IT_IRQ91 == _USED_ */

#if IODC_IT_IRQ92 == _USED_
extern void IODC_IT_IRQ92_CALLBACK(void);
#endif /* IODC_IT_IRQ92 == _USED_ */

#if IODC_IT_IRQ93 == _USED_
extern void IODC_IT_IRQ93_CALLBACK(void);
#endif /* IODC_IT_IRQ93 == _USED_ */

#if IODC_IT_IRQ94 == _USED_
extern void IODC_IT_IRQ94_CALLBACK(void);
#endif /* IODC_IT_IRQ94 == _USED_ */

#if IODC_IT_IRQ95 == _USED_
extern void IODC_IT_IRQ95_CALLBACK(void);
#endif /* IODC_IT_IRQ95 == _USED_ */

#if IODC_IT_IRQ96 == _USED_
extern void IODC_IT_IRQ96_CALLBACK(void);
#endif /* IODC_IT_IRQ96 == _USED_ */

#if IODC_IT_IRQ97 == _USED_
extern void IODC_IT_IRQ97_CALLBACK(void);
#endif /* IODC_IT_IRQ97 == _USED_ */

#if IODC_IT_IRQ98 == _USED_
extern void IODC_IT_IRQ98_CALLBACK(void);
#endif /* IODC_IT_IRQ98 == _USED_ */

#if IODC_IT_IRQ99 == _USED_
extern void IODC_IT_IRQ99_CALLBACK(void);
#endif /* IODC_IT_IRQ99 == _USED_ */

#if IODC_IT_IRQ100 == _USED_
extern void IODC_IT_IRQ100_CALLBACK(void);
#endif /* IODC_IT_IRQ100 == _USED_ */

#if IODC_IT_IRQ101 == _USED_
extern void IODC_IT_IRQ101_CALLBACK(void);
#endif /* IODC_IT_IRQ101 == _USED_ */

#if IODC_IT_IRQ102 == _USED_
extern void IODC_IT_IRQ102_CALLBACK(void);
#endif /* IODC_IT_IRQ102 == _USED_ */

#if IODC_IT_IRQ103 == _USED_
extern void IODC_IT_IRQ103_CALLBACK(void);
#endif /* IODC_IT_IRQ103 == _USED_ */

#if IODC_IT_IRQ104 == _USED_
extern void IODC_IT_IRQ104_CALLBACK(void);
#endif /* IODC_IT_IRQ104 == _USED_ */

#if IODC_IT_IRQ105 == _USED_
extern void IODC_IT_IRQ105_CALLBACK(void);
#endif /* IODC_IT_IRQ105 == _USED_ */

#if IODC_IT_IRQ106 == _USED_
extern void IODC_IT_IRQ106_CALLBACK(void);
#endif /* IODC_IT_IRQ106 == _USED_ */

#if IODC_IT_IRQ107 == _USED_
extern void IODC_IT_IRQ107_CALLBACK(void);
#endif /* IODC_IT_IRQ107 == _USED_ */

#if IODC_IT_IRQ108 == _USED_
extern void IODC_IT_IRQ108_CALLBACK(void);
#endif /* IODC_IT_IRQ108 == _USED_ */

#if IODC_IT_IRQ109 == _USED_
extern void IODC_IT_IRQ109_CALLBACK(void);
#endif /* IODC_IT_IRQ109 == _USED_ */

#if IODC_IT_IRQ110 == _USED_
extern void IODC_IT_IRQ110_CALLBACK(void);
#endif /* IODC_IT_IRQ110 == _USED_ */

#if IODC_IT_IRQ111 == _USED_
extern void IODC_IT_IRQ111_CALLBACK(void);
#endif /* IODC_IT_IRQ111 == _USED_ */

#if IODC_IT_IRQ112 == _USED_
extern void IODC_IT_IRQ112_CALLBACK(void);
#endif /* IODC_IT_IRQ112 == _USED_ */

#if IODC_IT_IRQ113 == _USED_
extern void IODC_IT_IRQ113_CALLBACK(void);
#endif /* IODC_IT_IRQ113 == _USED_ */

#if IODC_IT_IRQ114 == _USED_
extern void IODC_IT_IRQ114_CALLBACK(void);
#endif /* IODC_IT_IRQ114 == _USED_ */

#if IODC_IT_IRQ115 == _USED_
extern void IODC_IT_IRQ115_CALLBACK(void);
#endif /* IODC_IT_IRQ115 == _USED_ */

#if IODC_IT_IRQ116 == _USED_
extern void IODC_IT_IRQ116_CALLBACK(void);
#endif /* IODC_IT_IRQ116 == _USED_ */

#if IODC_IT_IRQ117 == _USED_
extern void IODC_IT_IRQ117_CALLBACK(void);
#endif /* IODC_IT_IRQ117 == _USED_ */

#if IODC_IT_IRQ118 == _USED_
extern void IODC_IT_IRQ118_CALLBACK(void);
#endif /* IODC_IT_IRQ118 == _USED_ */

#if IODC_IT_IRQ119 == _USED_
extern void IODC_IT_IRQ119_CALLBACK(void);
#endif /* IODC_IT_IRQ119 == _USED_ */

#if IODC_IT_IRQ120 == _USED_
extern void IODC_IT_IRQ120_CALLBACK(void);
#endif /* IODC_IT_IRQ120 == _USED_ */

#if IODC_IT_IRQ121 == _USED_
extern void IODC_IT_IRQ121_CALLBACK(void);
#endif /* IODC_IT_IRQ121 == _USED_ */

#if IODC_IT_IRQ122 == _USED_
extern void IODC_IT_IRQ122_CALLBACK(void);
#endif /* IODC_IT_IRQ122 == _USED_ */

#if IODC_IT_IRQ123 == _USED_
extern void IODC_IT_IRQ123_CALLBACK(void);
#endif /* IODC_IT_IRQ123 == _USED_ */

#if IODC_IT_IRQ124 == _USED_
extern void IODC_IT_IRQ124_CALLBACK(void);
#endif /* IODC_IT_IRQ124 == _USED_ */

#if IODC_IT_IRQ125 == _USED_
extern void IODC_IT_IRQ125_CALLBACK(void);
#endif /* IODC_IT_IRQ125 == _USED_ */

#if IODC_IT_IRQ126 == _USED_
extern void IODC_IT_IRQ126_CALLBACK(void);
#endif /* IODC_IT_IRQ126 == _USED_ */

#if IODC_IT_IRQ127 == _USED_
extern void IODC_IT_IRQ127_CALLBACK(void);
#endif /* IODC_IT_IRQ127 == _USED_ */
#endif /* __FSL_IMX53x__ , __FSL_IMX6x__*/

#ifdef __REL_RL78__
#ifdef __REL_RL78_D1x__
#ifdef __REL_RL78_D1A__
#if IODC_IT_IRQ0  == _USED_
extern void IODC_IT_IRQ0_CALLBACK(void);
#endif /* IODC_IT_IRQ0 == _USED_ */

#if IODC_IT_IRQ1  == _USED_
extern void IODC_IT_IRQ1_CALLBACK(void);
#endif /* IODC_IT_IRQ1 == _USED_ */

#if IODC_IT_IRQ2  == _USED_
extern void IODC_IT_IRQ2_CALLBACK(void);
#endif /* IODC_IT_IRQ2 == _USED_ */

#if IODC_IT_IRQ3  == _USED_
extern void IODC_IT_IRQ3_CALLBACK(void);
#endif /* IODC_IT_IRQ3 == _USED_ */

#if IODC_IT_IRQ4  == _USED_
extern void IODC_IT_IRQ4_CALLBACK(void);
#endif /* IODC_IT_IRQ4 == _USED_ */

#if IODC_IT_IRQ5  == _USED_
extern void IODC_IT_IRQ5_CALLBACK(void);
#endif /* IODC_IT_IRQ5 == _USED_ */
#endif /* __REL_RL78_D1A__ */
#endif /* __REL_RL78_D1x__ */

#ifdef __REL_RL78_F1x__
#ifdef __REL_RL78_F12__
#if IODC_IT_IRQ0  == _USED_
extern void IODC_IT_IRQ0_CALLBACK(void);
#endif /* IODC_IT_IRQ0 == _USED_ */

#if IODC_IT_IRQ1  == _USED_
extern void IODC_IT_IRQ1_CALLBACK(void);
#endif /* IODC_IT_IRQ1 == _USED_ */

#if IODC_IT_IRQ2  == _USED_
extern void IODC_IT_IRQ2_CALLBACK(void);
#endif /* IODC_IT_IRQ2 == _USED_ */

#if IODC_IT_IRQ3  == _USED_
extern void IODC_IT_IRQ3_CALLBACK(void);
#endif /* IODC_IT_IRQ3 == _USED_ */

#if IODC_IT_IRQ4  == _USED_
extern void IODC_IT_IRQ4_CALLBACK(void);
#endif /* IODC_IT_IRQ4 == _USED_ */

#if IODC_IT_IRQ5  == _USED_
extern void IODC_IT_IRQ5_CALLBACK(void);
#endif /* IODC_IT_IRQ5 == _USED_ */
#if IODC_IT_IRQ6  == _USED_
extern void IODC_IT_IRQ6_CALLBACK(void);
#endif /* IODC_IT_IRQ6 == _USED_ */

#if IODC_IT_IRQ7  == _USED_
extern void IODC_IT_IRQ7_CALLBACK(void);
#endif /* IODC_IT_IRQ7 == _USED_ */

#if IODC_IT_IRQ8  == _USED_
extern void IODC_IT_IRQ8_CALLBACK(void);
#endif /* IODC_IT_IRQ8 == _USED_ */

#if IODC_IT_IRQ9  == _USED_
extern void IODC_IT_IRQ9_CALLBACK(void);
#endif /* IODC_IT_IRQ9 == _USED_ */

#if IODC_IT_IRQ10  == _USED_
extern void IODC_IT_IRQ10_CALLBACK(void);
#endif /* IODC_IT_IRQ10 == _USED_ */

#if IODC_IT_IRQ11  == _USED_
extern void IODC_IT_IRQ11_CALLBACK(void);
#endif /* IODC_IT_IRQ11 == _USED_ */
#endif /* __REL_RL78_F12__ */
#endif /* __REL_RL78_F1x__ */
#endif /* __REL_RL78__ */

#ifndef __RH850__
/* it is mandatory a table with constant-size whatever the IRQs installed */
static void (*const Iodc_IrqCallBackFctTable[])(void) =
{
#if defined(__MC9S12xx__)
   IODC_IT_IRQ0_CALLBACK
  ,IODC_IT_IRQ1_CALLBACK
  ,IODC_IT_IRQ2_CALLBACK
#if defined(__MC9S12xx__)
  ,IODC_IT_IRQ3_CALLBACK
  ,IODC_IT_IRQ4_CALLBACK
  ,IODC_IT_IRQ5_CALLBACK
#endif  /* defined(__MC9S12xx__) */

#if defined(__MC9S12xx__)
  ,IODC_IT_IRQ6_CALLBACK
  ,IODC_IT_IRQ7_CALLBACK
  ,IODC_IT_IRQ8_CALLBACK
/* MC9S12-H variant */
#if defined(__MC9S12H__)
  ,IODC_IT_IRQ9_CALLBACK
  ,IODC_IT_IRQ10_CALLBACK
  ,IODC_IT_IRQ11_CALLBACK
  ,IODC_IT_IRQ12_CALLBACK
#endif /* defined(__MC9S12H__) */
#endif /* defined(__MC9S12xx__) */
#endif /* defined(__MC9S12xx__) */

#ifdef __MC9S08xx__
  IODC_IT_IRQ0_CALLBACK,
  IODC_IT_IRQ1_CALLBACK,
  IODC_IT_IRQ2_CALLBACK,
  IODC_IT_IRQ3_CALLBACK,
  IODC_IT_IRQ4_CALLBACK,
  IODC_IT_IRQ5_CALLBACK,
  IODC_IT_IRQ6_CALLBACK,
  IODC_IT_IRQ7_CALLBACK,
  IODC_IT_IRQPIN_CALLBACK
#endif /*__MC9S08xx__*/

#ifdef __TX49__
  IODC_IT_IRQ0_CALLBACK,
  IODC_IT_IRQ1_CALLBACK,
  IODC_IT_IRQ2_CALLBACK,
  IODC_IT_IRQ3_CALLBACK
#endif /* __TX49__ */

#ifdef __NEC_V850__
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

#if defined(__FSL_IMX53x__) || defined(__FSL_IMX6x__)
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
  IODC_IT_IRQ16_CALLBACK,
  IODC_IT_IRQ17_CALLBACK,
  IODC_IT_IRQ18_CALLBACK,
  IODC_IT_IRQ19_CALLBACK,
  IODC_IT_IRQ20_CALLBACK,
  IODC_IT_IRQ21_CALLBACK,
  IODC_IT_IRQ22_CALLBACK,
  IODC_IT_IRQ23_CALLBACK,
  IODC_IT_IRQ24_CALLBACK,
  IODC_IT_IRQ25_CALLBACK,
  IODC_IT_IRQ26_CALLBACK,
  IODC_IT_IRQ27_CALLBACK,
  IODC_IT_IRQ28_CALLBACK,
  IODC_IT_IRQ29_CALLBACK,
  IODC_IT_IRQ30_CALLBACK,
  IODC_IT_IRQ31_CALLBACK,
  IODC_IT_IRQ32_CALLBACK,
  IODC_IT_IRQ33_CALLBACK,
  IODC_IT_IRQ34_CALLBACK,
  IODC_IT_IRQ35_CALLBACK,
  IODC_IT_IRQ36_CALLBACK,
  IODC_IT_IRQ37_CALLBACK,
  IODC_IT_IRQ38_CALLBACK,
  IODC_IT_IRQ39_CALLBACK,
  IODC_IT_IRQ40_CALLBACK,
  IODC_IT_IRQ41_CALLBACK,
  IODC_IT_IRQ42_CALLBACK,
  IODC_IT_IRQ43_CALLBACK,
  IODC_IT_IRQ44_CALLBACK,
  IODC_IT_IRQ45_CALLBACK,
  IODC_IT_IRQ46_CALLBACK,
  IODC_IT_IRQ47_CALLBACK,
  IODC_IT_IRQ48_CALLBACK,
  IODC_IT_IRQ49_CALLBACK,
  IODC_IT_IRQ50_CALLBACK,
  IODC_IT_IRQ51_CALLBACK,
  IODC_IT_IRQ52_CALLBACK,
  IODC_IT_IRQ53_CALLBACK,
  IODC_IT_IRQ54_CALLBACK,
  IODC_IT_IRQ55_CALLBACK,
  IODC_IT_IRQ56_CALLBACK,
  IODC_IT_IRQ57_CALLBACK,
  IODC_IT_IRQ58_CALLBACK,
  IODC_IT_IRQ59_CALLBACK,
  IODC_IT_IRQ60_CALLBACK,
  IODC_IT_IRQ61_CALLBACK,
  IODC_IT_IRQ62_CALLBACK,
  IODC_IT_IRQ63_CALLBACK,
  IODC_IT_IRQ64_CALLBACK,
  IODC_IT_IRQ65_CALLBACK,
  IODC_IT_IRQ66_CALLBACK,
  IODC_IT_IRQ67_CALLBACK,
  IODC_IT_IRQ68_CALLBACK,
  IODC_IT_IRQ69_CALLBACK,
  IODC_IT_IRQ70_CALLBACK,
  IODC_IT_IRQ71_CALLBACK,
  IODC_IT_IRQ72_CALLBACK,
  IODC_IT_IRQ73_CALLBACK,
  IODC_IT_IRQ74_CALLBACK,
  IODC_IT_IRQ75_CALLBACK,
  IODC_IT_IRQ76_CALLBACK,
  IODC_IT_IRQ77_CALLBACK,
  IODC_IT_IRQ78_CALLBACK,
  IODC_IT_IRQ79_CALLBACK,
  IODC_IT_IRQ80_CALLBACK,
  IODC_IT_IRQ81_CALLBACK,
  IODC_IT_IRQ82_CALLBACK,
  IODC_IT_IRQ83_CALLBACK,
  IODC_IT_IRQ84_CALLBACK,
  IODC_IT_IRQ85_CALLBACK,
  IODC_IT_IRQ86_CALLBACK,
  IODC_IT_IRQ87_CALLBACK,
  IODC_IT_IRQ88_CALLBACK,
  IODC_IT_IRQ89_CALLBACK,
  IODC_IT_IRQ90_CALLBACK,
  IODC_IT_IRQ91_CALLBACK,
  IODC_IT_IRQ92_CALLBACK,
  IODC_IT_IRQ93_CALLBACK,
  IODC_IT_IRQ94_CALLBACK,
  IODC_IT_IRQ95_CALLBACK,
  IODC_IT_IRQ96_CALLBACK,
  IODC_IT_IRQ97_CALLBACK,
  IODC_IT_IRQ98_CALLBACK,
  IODC_IT_IRQ99_CALLBACK,
  IODC_IT_IRQ100_CALLBACK,
  IODC_IT_IRQ101_CALLBACK,
  IODC_IT_IRQ102_CALLBACK,
  IODC_IT_IRQ103_CALLBACK,
  IODC_IT_IRQ104_CALLBACK,
  IODC_IT_IRQ105_CALLBACK,
  IODC_IT_IRQ106_CALLBACK,
  IODC_IT_IRQ107_CALLBACK,
  IODC_IT_IRQ108_CALLBACK,
  IODC_IT_IRQ109_CALLBACK,
  IODC_IT_IRQ110_CALLBACK,
  IODC_IT_IRQ111_CALLBACK,
  IODC_IT_IRQ112_CALLBACK,
  IODC_IT_IRQ113_CALLBACK,
  IODC_IT_IRQ114_CALLBACK,
  IODC_IT_IRQ115_CALLBACK,
  IODC_IT_IRQ116_CALLBACK,
  IODC_IT_IRQ117_CALLBACK,
  IODC_IT_IRQ118_CALLBACK,
  IODC_IT_IRQ119_CALLBACK,
  IODC_IT_IRQ120_CALLBACK,
  IODC_IT_IRQ121_CALLBACK,
  IODC_IT_IRQ122_CALLBACK,
  IODC_IT_IRQ123_CALLBACK,
  IODC_IT_IRQ124_CALLBACK,
  IODC_IT_IRQ125_CALLBACK,
  IODC_IT_IRQ126_CALLBACK,
  IODC_IT_IRQ127_CALLBACK
#endif /* __FSL_IMX53x__ , __FSL_IMX6x__*/

#ifdef __REL_RL78__
#ifdef __REL_RL78_D1x__
#ifdef __REL_RL78_D1A__
 IODC_IT_IRQ0_CALLBACK
,IODC_IT_IRQ1_CALLBACK
,IODC_IT_IRQ2_CALLBACK
,IODC_IT_IRQ3_CALLBACK
,IODC_IT_IRQ4_CALLBACK
,IODC_IT_IRQ5_CALLBACK
#endif /* __REL_RL78_D1A__ */
#endif /* __REL_RL78_D1x__ */

#ifdef __REL_RL78_F1x__
#ifdef __REL_RL78_F12__
 IODC_IT_IRQ0_CALLBACK
,IODC_IT_IRQ1_CALLBACK
,IODC_IT_IRQ2_CALLBACK
,IODC_IT_IRQ3_CALLBACK
,IODC_IT_IRQ4_CALLBACK
,IODC_IT_IRQ5_CALLBACK
,IODC_IT_IRQ6_CALLBACK
,IODC_IT_IRQ7_CALLBACK
,IODC_IT_IRQ8_CALLBACK
,IODC_IT_IRQ9_CALLBACK
,IODC_IT_IRQ10_CALLBACK
,IODC_IT_IRQ11_CALLBACK
#endif /*__REL_RL78_F12__ */
#endif /*__REL_RL78_F1x__ */
#endif /* __REL_RL78__ */
};
#endif
#endif /* IODC_IRQ_USED */


/*______ L O C A L - M A C R O S _____________________________________________*/


/*______ I M P O R T - F U N C T I O N S - P R O T O T Y P E S _______________*/


/*______ L O C A L - F U N C T I O N S - P R O T O T Y P E S _________________*/

#ifdef IODC_IRQ_USED
static __NEAR_FUNC__ void Iodc_CallBackIrq(ubyte IrqNumber);
#endif /* IODC_IRQ_USED */

#ifdef IODC_INPUT_MATRIX_USED
#if (IODC_NUMBER_OF_INPUT_MATRIX >0)
static void IODC_ScanInputMatrix1(void);
#endif /* (IODC_NUMBER_OF_INPUT_MATRIX >0) */

#if (IODC_NUMBER_OF_INPUT_MATRIX >1)
static void IODC_ScanInputMatrix2(void);
#endif /* (IODC_NUMBER_OF_INPUT_MATRIX >1) */
#endif /* IODC_INPUT_MATRIX_USED */


/*______ G L O B A L - F U N C T I O N S _____________________________________*/

/*----------------------------------------------------------------------------*/
/*Name : IODC_Init                                                            */
/*Role : Initialise the hardware by using the base layer                      */
/*Interface : -                                                               */
/*Pre-condition : -                                                           */
/*Constraints :                                                               */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [initialise the port direction]                                         */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
/*PROC IODC_Init()                                                            */
/*                                                                            */
/*DATA                                                                        */
/*ATAD                                                                        */
/*                                                                            */
/*DO                                                                          */
/*  [initialise the port direction] =                                         */
/*  DO                                                                        */
/*    [launch the IODC_InitialiseHW function, according to configuration data]*/
/*  OD                                                                        */
/*  [initialise SCI frame if neccessary]                                      */
/*OD                                                                          */
/*----------------------------------------------------------------------------*/
void IODC_Init(void)
{
#if defined (IODC_LED_MATRIX_USED)
  #if (IODC_NUMBER_OF_COLUMN_PIN > 1)
  Iodc_CurrentColumn = 0;
  #endif /* (IODC_NUMBER_OF_COLUMN_PIN > 1) */

  {
    ubyte Column;

    for (Column = 0; Column < IODC_NUMBER_OF_COLUMN_PIN; Column++)
    {
      IODC_TabStateLed[Column] = ((IODC_TabStateLed_t)(0));
    }
  }
#endif /* (IODC_LED_MATRIX_USED) */

#ifdef IODC_INPUT_MATRIX_USED

 #if (IODC_NUMBER_OF_INPUT_MATRIX > 0)
  IODC_IndexMatrix         = 0;
  IODC_LastNoRotaryIndex1  = 0;
  IODC_LastNoRotaryColumn1 = 0;

  #if (IODC_NB_COLUMN_INMUX_1 > 1)
  Iodc_CurrentColumn_InMux_1 = 0;
  #endif /* (IODC_NB_COLUMN_INMUX_1 > 1) */
 #endif /* (IODC_NUMBER_OF_INPUT_MATRIX > 0) */

 #if (IODC_NUMBER_OF_INPUT_MATRIX > 1)
  IODC_IndexMatrix2        = 0;
  IODC_LastNoRotaryIndex2  = 0;
  IODC_LastNoRotaryColumn2 = 0;

  #if (IODC_NB_COLUMN_INMUX_2 > 1)
  Iodc_CurrentColumn_InMux_2 = 0;
  #endif /* (IODC_NB_COLUMN_INMUX_2 > 1) */
 #endif /* (IODC_NUMBER_OF_INPUT_MATRIX > 1) */

#endif /* IODC_INPUT_MATRIX_USED */

  IODC_ConfigureHw();
}

#ifdef __EOL_ENABLE__
/*----------------------------------------------------------------------------*/
/*Name : IODC_InitEol                                                         */
/*Role : Initialise the hardware by using the base layer for test EOL         */
/*Interface : -                                                               */
/*Pre-condition : -                                                           */
/*Constraints :                                                               */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [Call general init and call specific EOL init]                          */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
void IODC_InitEol(void)
{
  IODC_Init();
  Iodc_InitEolDigitalInPin();

  IODC_EolpConfigureLcdPin();
}
#endif /*__EOL_ENABLE__*/

/*----------------------------------------------------------------------------*/
/*Name : IODC_WakeUp                                                          */
/*Role : Start of TIMC timer and start the task                               */
/*Interface : -                                                               */
/*Pre-condition : -                                                           */
/*Constraints : must be called at system wake up                              */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [Start of TIMC timer and start the task]                                */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
/*PROC IODC_WakeUp()                                                          */
/*                                                                            */
/*DATA                                                                        */
/*ATAD                                                                        */
/*                                                                            */
/*DO                                                                          */
/*  [Start of TIMC timer and start the task] =                                */
/*  DO                                                                        */
/*    [Start of TIMC timer]                                                   */
/*    [Start of IODC task]                                                    */
/*  OD                                                                        */
/*OD                                                                          */
/*----------------------------------------------------------------------------*/
void IODC_WakeUp(void)
{
#if defined(IODC_LED_MATRIX_USED) && \
    (IODC_LED_MATRIX_REFRESH == IODC_LED_MATRIX_ISR_REFRESH)
  #ifdef IODC_LED_MATRIX_RELAX_TIME_USED
  IODC_RelaxTimeTick = 1;
  #endif /* IODC_LED_MATRIX_RELAX_TIME_USED */
  TIMC_TimerCmSetPeriod(IODC_TIMER_CHANNEL,
                        IODC_COLUMN_0_TIME_TICK);
  TIMC_TimerStartChannel(IODC_TIMER_CHANNEL);
#endif /* defined(IODC_LED_MATRIX_USED) && \
          (IODC_LED_MATRIX_REFRESH == IODC_LED_MATRIX_ISR_REFRESH) */

#if defined(IODC_INPUT_MATRIX_USED) && \
    (IODC_INPUT_MATRIX_SCAN_REFRESH == IODC_INPUT_MATRIX_ISR_REFRESH)
  TIMC_TimerCmSetPeriod(IODC_TIMER_CHANNEL_INMUX,
                        IODC_TIMER_PERIOD_INMUX);
  TIMC_TimerStartChannel(IODC_TIMER_CHANNEL_INMUX);
#endif /* defined(IODC_INPUT_MATRIX_USED) && \
          (IODC_INPUT_MATRIX_SCAN_REFRESH == IODC_INPUT_MATRIX_ISR_REFRESH) */

#ifdef __MONITOR_SW_WDG__
#ifndef IODC_NOT_A_TASK
  SAFM_StartTaskWatchdog(IODC_Task_ts,IODC_TASK_CALLING_PERIOD);
#endif
#endif /*__MONITOR_SW_WDG__*/

#if defined IODC_LED_MATRIX_TASK_REFRESH_USED || \
    defined IODC_PORT_SETUP_PERIODIC_REFRESH
  /* Set task active to be sure it will executed at least once */
  WKSS_TaskState(IODC_Task_ts, WKSS_ACTIVE_TASK);
  (void)SetRelAlarm (IODC_Task_al,IODC_TASK_CALLING_DELAY, IODC_TASK_CALLING_PERIOD);
#endif /* defined IODC_LED_MATRIX_TASK_REFRESH_USED || \
          defined IODC_PORT_SETUP_PERIODIC_REFRESH */
}

/*----------------------------------------------------------------------------*/
/*Name : IODC_Sleep                                                           */
/*Role : Stop of TIMC timer and stop the task                                 */
/*Interface : -                                                               */
/*Pre-condition : -                                                           */
/*Constraints : must be called at system sleep                                */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [Stop of TIMC timer and stop the task]                                  */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
/*PROC IODC_Sleep()                                                           */
/*                                                                            */
/*DATA                                                                        */
/*ATAD                                                                        */
/*                                                                            */
/*DO                                                                          */
/*  [Stop of TIMC timer and stop the task] =                                  */
/*  DO                                                                        */
/*    [Stop of TIMC timer]                                                    */
/*    [Stop of IODC task]                                                     */
/*  OD                                                                        */
/*OD                                                                          */
/*----------------------------------------------------------------------------*/
void IODC_Sleep(void)
{
#if defined(IODC_LED_MATRIX_USED) && \
    (IODC_LED_MATRIX_REFRESH == IODC_LED_MATRIX_ISR_REFRESH)
  TIMC_TimerStopChannel(IODC_TIMER_CHANNEL);
#endif /* definded(IODC_LED_MATRIX_USED) && \
         (IODC_LED_MATRIX_REFRESH == IODC_LED_MATRIX_ISR_REFRESH) */

#if defined(IODC_INPUT_MATRIX_USED) && \
           (IODC_INPUT_MATRIX_SCAN_REFRESH == IODC_INPUT_MATRIX_ISR_REFRESH)
  TIMC_TimerStopChannel(IODC_TIMER_CHANNEL_INMUX);
#endif /* defined(IODC_INPUT_MATRIX_USED) && \
          (IODC_INPUT_MATRIX_SCAN_REFRESH == IODC_INPUT_MATRIX_ISR_REFRESH) */

#if defined IODC_LED_MATRIX_TASK_REFRESH_USED || \
    defined IODC_PORT_SETUP_PERIODIC_REFRESH
  CancelAlarm(IODC_Task_al);
#endif /* defined IODC_LED_MATRIX_TASK_REFRESH_USED || \
          defined IODC_PORT_SETUP_PERIODIC_REFRESH */
}

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
#ifdef __MC9S12xx__
#if IODC_IT_IRQ0 == _USED_
ISR(IODC_Irq_it)
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

#if ((IODC_IT_IRQ1 == _USED_) || \
     (IODC_IT_IRQ2 == _USED_) || \
     (IODC_IT_IRQ3 == _USED_) || \
     (IODC_IT_IRQ4 == _USED_) || \
     (IODC_IT_IRQ5 == _USED_) || \
     (IODC_IT_IRQ6 == _USED_) || \
     (IODC_IT_IRQ7 == _USED_) || \
     (IODC_IT_IRQ8 == _USED_))

/* --- MC9S12-H variant --- */
#if defined(__MC9S12H__)
ISR(IODC_IrqH_it)
#endif /* defined(__MC9S12H__) */

/* --- MC9S12-HZ and MC9S12XHZ variant --- */
#if (defined(__MC9S12HZ__) || defined(__MC9S12XHZ__))
ISR(IODC_IrqAD_it)
#endif /* (defined(__MC9S12HZ__) || defined(__MC9S12XHZ__)) */
{
  #ifdef __TASK_DURATION_MEASUREMENT_WITH_TIMER__
  ubyte OldMeasuredTask;

  RTOS_DisableAllInterrupts();
  OldMeasuredTask = RTOS_MeasuredTask;
  RTOS_TaskMeasurementEnterIt(OldMeasuredTask);
  RTOS_EnableAllInterrupts();
  #endif /* __TASK_DURATION_MEASUREMENT_WITH_TIMER__ */

  #ifdef __IT_DURATION_MEASUREMENT__
  RTOS_EnterItDurationMeasurement(RTOS_MEAS_IT_IODC_IRQAD);
  #endif /* __IT_DURATION_MEASUREMENT__ */

  #if IODC_IT_IRQ1 == _USED_
  if (IODD_ReadStatusIrq(IODD_IRQ1) == IODC_ACTIVE)
  {
    IODD_ClearStatusIrq(IODD_IRQ1);
    Iodc_CallBackIrq(IODC_IRQ1);
  }
  #endif /* IODC_IT_IRQ1 == _USED_ */

  #if IODC_IT_IRQ2 == _USED_
  if (IODD_ReadStatusIrq(IODD_IRQ2) == IODC_ACTIVE)
  {
    IODD_ClearStatusIrq(IODD_IRQ2);
    Iodc_CallBackIrq(IODC_IRQ2);
  }
  #endif /* IODC_IT_IRQ2 == _USED_ */

  #if IODC_IT_IRQ3 == _USED_
  if (IODD_ReadStatusIrq(IODD_IRQ3) == IODC_ACTIVE)
  {
    IODD_ClearStatusIrq(IODD_IRQ3);
    Iodc_CallBackIrq(IODC_IRQ3);
  }
  #endif /* IODC_IT_IRQ3 == _USED_ */

  #if IODC_IT_IRQ4 == _USED_
  if (IODD_ReadStatusIrq(IODD_IRQ4) == IODC_ACTIVE)
  {
    IODD_ClearStatusIrq(IODD_IRQ4);
    Iodc_CallBackIrq(IODC_IRQ4);
  }
  #endif /* IODC_IT_IRQ4 == _USED_ */

  #if IODC_IT_IRQ5 == _USED_
  if (IODD_ReadStatusIrq(IODD_IRQ5) == IODC_ACTIVE)
  {
    IODD_ClearStatusIrq(IODD_IRQ5);
    Iodc_CallBackIrq(IODC_IRQ5);
  }
  #endif /* IODC_IT_IRQ5 == _USED_ */

  #if IODC_IT_IRQ6 == _USED_
  if (IODD_ReadStatusIrq(IODD_IRQ6) == IODC_ACTIVE)
  {
    IODD_ClearStatusIrq(IODD_IRQ6);
    Iodc_CallBackIrq(IODC_IRQ6);
  }
  #endif /* IODC_IT_IRQ6 == _USED_ */

  #if IODC_IT_IRQ7 == _USED_
  if (IODD_ReadStatusIrq(IODD_IRQ7) == IODC_ACTIVE)
  {
    IODD_ClearStatusIrq(IODD_IRQ7);
    Iodc_CallBackIrq(IODC_IRQ7);
  }
  #endif /* IODC_IT_IRQ7 == _USED_ */

  #if IODC_IT_IRQ8 == _USED_
  if (IODD_ReadStatusIrq(IODD_IRQ8) == IODC_ACTIVE)
  {
    IODD_ClearStatusIrq(IODD_IRQ8);
    Iodc_CallBackIrq(IODC_IRQ8);
  }
  #endif /* IODC_IT_IRQ8 == _USED_ */

  #ifdef __IT_DURATION_MEASUREMENT__
  RTOS_LeaveItDurationMeasurement(RTOS_MEAS_IT_IODC_IRQAD);
  #endif /* __IT_DURATION_MEASUREMENT__ */

  #ifdef __TASK_DURATION_MEASUREMENT_WITH_TIMER__
  RTOS_DisableAllInterrupts();
  RTOS_TaskMeasurementLeaveIt(OldMeasuredTask);
  RTOS_EnableAllInterrupts();
  #endif /* __TASK_DURATION_MEASUREMENT_WITH_TIMER__ */
}
#endif /* at least one Irq used on port H  (MC9S12-H ) */
       /* or                    on port AD (MC9S12-H, MC9S12XHZ)  */

/* --- MC9S12-H variant --- */
#if defined(__MC9S12H__)
#if ((IODC_IT_IRQ9  == _USED_) || \
     (IODC_IT_IRQ10 == _USED_) || \
     (IODC_IT_IRQ11 == _USED_) || \
     (IODC_IT_IRQ12 == _USED_))
ISR(IODC_IrqJ_it)
{
  #ifdef __TASK_DURATION_MEASUREMENT_WITH_TIMER__
  ubyte OldMeasuredTask;

  RTOS_DisableAllInterrupts();
  OldMeasuredTask = RTOS_MeasuredTask;
  RTOS_TaskMeasurementEnterIt(OldMeasuredTask);
  RTOS_EnableAllInterrupts();
  #endif /* __TASK_DURATION_MEASUREMENT_WITH_TIMER__ */

  #ifdef __IT_DURATION_MEASUREMENT__
  RTOS_EnterItDurationMeasurement(RTOS_MEAS_IT_IODC_IRQJ);
  #endif /* __IT_DURATION_MEASUREMENT__ */

  #if IODC_IT_IRQ9 == _USED_
  if (IODD_ReadStatusIrq(IODD_IRQ9) == IODC_ACTIVE)
  {
    IODD_ClearStatusIrq(IODD_IRQ9);
    Iodc_CallBackIrq(IODC_IRQ9);
  }
  #endif /* IODC_IT_IRQ9 == _USED_ */

  #if IODC_IT_IRQ10 == _USED_
  if (IODD_ReadStatusIrq(IODD_IRQ10) == IODC_ACTIVE)
  {
    IODD_ClearStatusIrq(IODD_IRQ10);
    Iodc_CallBackIrq(IODC_IRQ10);
  }
  #endif /* IODC_IT_IRQ10 == _USED_ */

  #if IODC_IT_IRQ11 == _USED_
  if (IODD_ReadStatusIrq(IODD_IRQ11) == IODC_ACTIVE)
  {
    IODD_ClearStatusIrq(IODD_IRQ11);
    Iodc_CallBackIrq(IODC_IRQ11);
  }
  #endif /* IODC_IT_IRQ11 == _USED_ */

  #if IODC_IT_IRQ12 == _USED_
  if (IODD_ReadStatusIrq(IODD_IRQ12) == IODC_ACTIVE)
  {
    IODD_ClearStatusIrq(IODD_IRQ12);
    Iodc_CallBackIrq(IODC_IRQ12);
  }
  #endif /* IODC_IT_IRQ12 == _USED_ */

  #ifdef __IT_DURATION_MEASUREMENT__
  RTOS_LeaveItDurationMeasurement(RTOS_MEAS_IT_IODC_IRQJ);
  #endif /* __IT_DURATION_MEASUREMENT__ */

  #ifdef __TASK_DURATION_MEASUREMENT_WITH_TIMER__
  RTOS_DisableAllInterrupts();
  RTOS_TaskMeasurementLeaveIt(OldMeasuredTask);
  RTOS_EnableAllInterrupts();
  #endif /* __TASK_DURATION_MEASUREMENT_WITH_TIMER__ */
}
#endif /* at least one Irq used on port J */

#endif /* defined(__MC9S12H__) */

#endif  /* __MC9S12xx__ */

#ifdef __MC9S08xx__

#if IODC_IT_IRQPIN == _USED_
ISR(IODC_Irq_it)
{
  #ifdef __TASK_DURATION_MEASUREMENT_WITH_TIMER__
  ubyte OldMeasuredTask;

  RTOS_DisableAllInterrupts();
  OldMeasuredTask = RTOS_MeasuredTask;
  RTOS_TaskMeasurementEnterIt(OldMeasuredTask);
  RTOS_EnableAllInterrupts();
  #endif /* __TASK_DURATION_MEASUREMENT_WITH_TIMER__ */

  IODD_ClearStatusIrq(IODD_IRQPIN);
  Iodc_CallBackIrq(IODC_IRQPIN);

  #ifdef __TASK_DURATION_MEASUREMENT_WITH_TIMER__
  RTOS_DisableAllInterrupts();
  RTOS_TaskMeasurementLeaveIt(OldMeasuredTask);
  RTOS_EnableAllInterrupts();
  #endif /* __TASK_DURATION_MEASUREMENT_WITH_TIMER__ */
}
#endif /* IODC_IT_IRQPIN == _USED_ */

#if ((IODC_IT_IRQ0 == _USED_) || \
     (IODC_IT_IRQ1 == _USED_) || \
     (IODC_IT_IRQ2 == _USED_) || \
     (IODC_IT_IRQ3 == _USED_) || \
     (IODC_IT_IRQ4 == _USED_) || \
     (IODC_IT_IRQ5 == _USED_) || \
     (IODC_IT_IRQ6 == _USED_) || \
     (IODC_IT_IRQ7 == _USED_))

ISR(IODC_IrqKbi_it)
{
  #ifdef __TASK_DURATION_MEASUREMENT_WITH_TIMER__
  ubyte OldMeasuredTask;

  RTOS_DisableAllInterrupts();
  OldMeasuredTask = RTOS_MeasuredTask;
  RTOS_TaskMeasurementEnterIt(OldMeasuredTask);
  RTOS_EnableAllInterrupts();
  #endif /* __TASK_DURATION_MEASUREMENT_WITH_TIMER__ */

  /* Restricted Implementation feature for KW ISR */
  /* ONLY one ISR enabled at the same time     */

  #if ((IODC_IT_IRQ0 + \
        IODC_IT_IRQ1 + \
        IODC_IT_IRQ2 + \
        IODC_IT_IRQ3 + \
        IODC_IT_IRQ4 + \
        IODC_IT_IRQ5 + \
        IODC_IT_IRQ6 + \
        IODC_IT_IRQ7)>1 )
    #error ONLY one ISR allowed at the same time, Restricted Implementation feature !
  #endif

  #if (IODC_IT_IRQ7 == _USED_)
  if (IODD_ReadStatusIrq(IODD_IRQ7) == IODC_ACTIVE)
  {
    IODD_ClearStatusIrq(IODD_IRQKBI);
    Iodc_CallBackIrq(IODC_IRQ7);
  }
  #endif /* IODC_IT_IRQ7 == _USED_ */

  #if IODC_IT_IRQ6 == _USED_
  if (IODD_ReadStatusIrq(IODD_IRQ6) == IODC_ACTIVE)
  {
    IODD_ClearStatusIrq(IODD_IRQKBI);
    Iodc_CallBackIrq(IODC_IRQ6);
  }
  #endif /* IODC_IT_IRQ6 == _USED_ */

  #if IODC_IT_IRQ5 == _USED_
  if ((IODD_ReadStatusIrq(IODD_IRQ5) == IODC_ACTIVE))
  {
    IODD_ClearStatusIrq(IODD_IRQKBI);
    Iodc_CallBackIrq(IODC_IRQ5);
  }
  #endif /* IODC_IT_IRQ5 == _USED_ */

  #if IODC_IT_IRQ4 == _USED_
  if ((IODD_ReadStatusIrq(IODD_IRQ4) == IODC_ACTIVE))
  {
    IODD_ClearStatusIrq(IODD_IRQKBI);
    Iodc_CallBackIrq(IODC_IRQ4);
  }
  #endif /* IODC_IT_IRQ4 == _USED_ */

  #if IODC_IT_IRQ3 == _USED_
  if ((IODD_ReadStatusIrq(IODD_IRQ3) == IODC_ACTIVE))
  {
    IODD_ClearStatusIrq(IODD_IRQKBI);
    Iodc_CallBackIrq(IODC_IRQ3);
  }
  #endif /* IODC_IT_IRQ3 == _USED_ */

  #if IODC_IT_IRQ2 == _USED_
  if ((IODD_ReadStatusIrq(IODD_IRQ2) == IODC_ACTIVE))
  {
    IODD_ClearStatusIrq(IODD_IRQKBI);
    Iodc_CallBackIrq(IODC_IRQ2);
  }
  #endif /* IODC_IT_IRQ2 == _USED_ */

  #if IODC_IT_IRQ1 == _USED_
  if ((IODD_ReadStatusIrq(IODD_IRQ1) == IODC_ACTIVE))
  {
    IODD_ClearStatusIrq(IODD_IRQKBI);
    Iodc_CallBackIrq(IODC_IRQ1);
  }
  #endif /* IODC_IT_IRQ1 == _USED_ */

  /* BEEFIN */
  #if IODC_IT_IRQ0 == _USED_
  if ((IODD_ReadStatusIrq(IODD_IRQ0) == IODC_ACTIVE))
  {
    IODD_ClearStatusIrq(IODD_IRQKBI);
    Iodc_CallBackIrq(IODC_IRQ0);
  }
  #endif /* IODC_IT_IRQ0 == _USED_ */

  #ifdef __TASK_DURATION_MEASUREMENT_WITH_TIMER__
  RTOS_DisableAllInterrupts();
  RTOS_TaskMeasurementLeaveIt(OldMeasuredTask);
  RTOS_EnableAllInterrupts();
  #endif /* __TASK_DURATION_MEASUREMENT_WITH_TIMER__ */
}
#endif /* ((IODC_IT_IRQ0 == _USED_) || (IODC_IT_IRQ1 == _USED_) || */
       /*  (IODC_IT_IRQ2 == _USED_) || (IODC_IT_IRQ3 == _USED_) || */
       /*  (IODC_IT_IRQ4 == _USED_) || (IODC_IT_IRQ5 == _USED_) || */
       /*  (IODC_IT_IRQ6 == _USED_) || (IODC_IT_IRQ7 == _USED_))   */

#endif  /* __MC9S08xx__ */

#ifdef __TX49__
#if IODC_IT_IRQ0 == _USED_
ISR(IODC_Irq0_it)
{
  IODD_SetPinData(NULL, GPIO_PIN_DSU_DCLK, IODD_HIGH);
  IODD_SetPinData(NULL, GPIO_PIN_DSU_DCLK, IODD_LOW);
  Iodc_CallBackIrq(IODC_IRQ0);
}
#endif /* IODC_IT_IRQ0 == _USED_ */

#if IODC_IT_IRQ1 == _USED_
ISR(IODC_Irq1_it)
{
  IODD_SetPinData(NULL, GPIO_PIN_DSU_TPC1, IODD_HIGH);
  IODD_SetPinData(NULL, GPIO_PIN_DSU_TPC1, IODD_LOW);
  Iodc_CallBackIrq(IODC_IRQ1);
}
#endif /* IODC_IT_IRQ1 == _USED_ */

#if IODC_IT_IRQ2 == _USED_
ISR(IODC_Irq2_it)
{
  IODD_SetPinData(NULL, GPIO_PIN_DSU_TPC2, IODD_HIGH);
  IODD_SetPinData(NULL, GPIO_PIN_DSU_TPC2, IODD_LOW);
  Iodc_CallBackIrq(IODC_IRQ2);
}
#endif /* IODC_IT_IRQ1 == _USED_ */

#if IODC_IT_IRQ3 == _USED_
ISR(IODC_Irq3_it)
{
  IODD_SetPinData(NULL, GPIO_PIN_DSU_TPC3, IODD_HIGH);
  IODD_SetPinData(NULL, GPIO_PIN_DSU_TPC3, IODD_LOW);
  Iodc_CallBackIrq(IODC_IRQ3);
}
#endif /* IODC_IT_IRQ1 == _USED_ */

#endif /* __TX49__ */

#ifdef __NEC_V850__
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
#endif  /* __NEC_V850__ */

#if defined(__FSL_IMX53x__) || defined(__FSL_IMX6x__)
#if IODC_IT_IRQ0 == _USED_
ISR(IODC_Irq0_it)
{
  Iodc_CallBackIrq(IODC_IRQ0);
}
#endif /* IODC_IT_IRQ0 == _USED_ */

#if IODC_IT_IRQ1 == _USED_
ISR(IODC_Irq1_it)
{
  Iodc_CallBackIrq(IODC_IRQ1);
}
#endif /* IODC_IT_IRQ1 == _USED_ */

#if IODC_IT_IRQ2 == _USED_
ISR(IODC_Irq2_it)
{
  Iodc_CallBackIrq(IODC_IRQ2);
}
#endif /* IODC_IT_IRQ2 == _USED_ */

#if IODC_IT_IRQ3 == _USED_
ISR(IODC_Irq3_it)
{
  Iodc_CallBackIrq(IODC_IRQ3);
}
#endif /* IODC_IT_IRQ3 == _USED_ */

#if IODC_IT_IRQ4 == _USED_
ISR(IODC_Irq4_it)
{
  Iodc_CallBackIrq(IODC_IRQ4);
}
#endif /* IODC_IT_IRQ4 == _USED_ */

#if IODC_IT_IRQ5 == _USED_
ISR(IODC_Irq5_it)
{
  Iodc_CallBackIrq(IODC_IRQ5);
}
#endif /* IODC_IT_IRQ5 == _USED_ */

#if IODC_IT_IRQ6 == _USED_
ISR(IODC_Irq6_it)
{
  Iodc_CallBackIrq(IODC_IRQ6);
}
#endif /* IODC_IT_IRQ6 == _USED_ */

#if IODC_IT_IRQ7 == _USED_
ISR(IODC_Irq7_it)
{
  Iodc_CallBackIrq(IODC_IRQ7);
}
#endif /* IODC_IT_IRQ7 == _USED_ */

#if IODC_IT_IRQ8 == _USED_
ISR(IODC_Irq8_it)
{
  Iodc_CallBackIrq(IODC_IRQ8);
}
#endif /* IODC_IT_IRQ8 == _USED_ */

#if IODC_IT_IRQ9 == _USED_
ISR(IODC_Irq9_it)
{
  Iodc_CallBackIrq(IODC_IRQ9);
}
#endif /* IODC_IT_IRQ9 == _USED_ */

#if IODC_IT_IRQ10 == _USED_
ISR(IODC_Irq10_it)
{
  Iodc_CallBackIrq(IODC_IRQ10);
}
#endif /* IODC_IT_IRQ10 == _USED_ */

#if IODC_IT_IRQ11 == _USED_
ISR(IODC_Irq11_it)
{
  Iodc_CallBackIrq(IODC_IRQ11);
}
#endif /* IODC_IT_IRQ11 == _USED_ */

#if IODC_IT_IRQ12 == _USED_
ISR(IODC_Irq12_it)
{
  Iodc_CallBackIrq(IODC_IRQ12);
}
#endif /* IODC_IT_IRQ12 == _USED_ */

#if IODC_IT_IRQ13 == _USED_
ISR(IODC_Irq13_it)
{
  Iodc_CallBackIrq(IODC_IRQ13);
}
#endif /* IODC_IT_IRQ13 == _USED_ */

#if IODC_IT_IRQ14 == _USED_
ISR(IODC_Irq14_it)
{
  Iodc_CallBackIrq(IODC_IRQ14);
}
#endif /* IODC_IT_IRQ14 == _USED_ */

#if IODC_IT_IRQ15 == _USED_
ISR(IODC_Irq15_it)
{
  Iodc_CallBackIrq(IODC_IRQ15);
}
#endif /* IODC_IT_IRQ15 == _USED_ */

#if IODC_IT_IRQ16 == _USED_
ISR(IODC_Irq16_it)
{
  Iodc_CallBackIrq(IODC_IRQ16);
}
#endif /* IODC_IT_IRQ16 == _USED_ */

#if IODC_IT_IRQ17 == _USED_
ISR(IODC_Irq17_it)
{
  Iodc_CallBackIrq(IODC_IRQ17);
}
#endif /* IODC_IT_IRQ17 == _USED_ */

#if IODC_IT_IRQ18 == _USED_
ISR(IODC_Irq18_it)
{
  Iodc_CallBackIrq(IODC_IRQ18);
}
#endif /* IODC_IT_IRQ18 == _USED_ */

#if IODC_IT_IRQ19 == _USED_
ISR(IODC_Irq19_it)
{
  Iodc_CallBackIrq(IODC_IRQ19);
}
#endif /* IODC_IT_IRQ19 == _USED_ */

#if IODC_IT_IRQ20 == _USED_
ISR(IODC_Irq20_it)
{
  Iodc_CallBackIrq(IODC_IRQ20);
}
#endif /* IODC_IT_IRQ20 == _USED_ */

#if IODC_IT_IRQ21 == _USED_
ISR(IODC_Irq21_it)
{
  Iodc_CallBackIrq(IODC_IRQ21);
}
#endif /* IODC_IT_IRQ21 == _USED_ */

#if IODC_IT_IRQ22 == _USED_
ISR(IODC_Irq22_it)
{
  Iodc_CallBackIrq(IODC_IRQ22);
}
#endif /* IODC_IT_IRQ22 == _USED_ */

#if IODC_IT_IRQ23 == _USED_
ISR(IODC_Irq23_it)
{
  Iodc_CallBackIrq(IODC_IRQ23);
}
#endif /* IODC_IT_IRQ23 == _USED_ */

#if IODC_IT_IRQ24 == _USED_
ISR(IODC_Irq24_it)
{
  Iodc_CallBackIrq(IODC_IRQ24);
}
#endif /* IODC_IT_IRQ24 == _USED_ */

#if IODC_IT_IRQ25 == _USED_
ISR(IODC_Irq25_it)
{
  Iodc_CallBackIrq(IODC_IRQ25);
}
#endif /* IODC_IT_IRQ25 == _USED_ */

#if IODC_IT_IRQ26 == _USED_
ISR(IODC_Irq26_it)
{
  Iodc_CallBackIrq(IODC_IRQ26);
}
#endif /* IODC_IT_IRQ26 == _USED_ */

#if IODC_IT_IRQ27 == _USED_
ISR(IODC_Irq27_it)
{
  Iodc_CallBackIrq(IODC_IRQ27);
}
#endif /* IODC_IT_IRQ27 == _USED_ */

#if IODC_IT_IRQ28 == _USED_
ISR(IODC_Irq28_it)
{
  Iodc_CallBackIrq(IODC_IRQ28);
}
#endif /* IODC_IT_IRQ28 == _USED_ */

#if IODC_IT_IRQ29 == _USED_
ISR(IODC_Irq29_it)
{
  Iodc_CallBackIrq(IODC_IRQ29);
}
#endif /* IODC_IT_IRQ29 == _USED_ */

#if IODC_IT_IRQ30 == _USED_
ISR(IODC_Irq30_it)
{
  Iodc_CallBackIrq(IODC_IRQ30);
}
#endif /* IODC_IT_IRQ30 == _USED_ */

#if IODC_IT_IRQ31 == _USED_
ISR(IODC_Irq31_it)
{
  Iodc_CallBackIrq(IODC_IRQ31);
}
#endif /* IODC_IT_IRQ31 == _USED_ */

#if IODC_IT_IRQ32 == _USED_
ISR(IODC_Irq32_it)
{
  Iodc_CallBackIrq(IODC_IRQ32);
}
#endif /* IODC_IT_IRQ32 == _USED_ */

#if IODC_IT_IRQ33 == _USED_
ISR(IODC_Irq33_it)
{
  Iodc_CallBackIrq(IODC_IRQ33);
}
#endif /* IODC_IT_IRQ33 == _USED_ */

#if IODC_IT_IRQ34 == _USED_
ISR(IODC_Irq34_it)
{
  Iodc_CallBackIrq(IODC_IRQ34);
}
#endif /* IODC_IT_IRQ34 == _USED_ */

#if IODC_IT_IRQ35 == _USED_
ISR(IODC_Irq35_it)
{
  Iodc_CallBackIrq(IODC_IRQ35);
}
#endif /* IODC_IT_IRQ35 == _USED_ */

#if IODC_IT_IRQ36 == _USED_
ISR(IODC_Irq36_it)
{
  Iodc_CallBackIrq(IODC_IRQ36);
}
#endif /* IODC_IT_IRQ36 == _USED_ */

#if IODC_IT_IRQ37 == _USED_
ISR(IODC_Irq37_it)
{
  Iodc_CallBackIrq(IODC_IRQ37);
}
#endif /* IODC_IT_IRQ37 == _USED_ */

#if IODC_IT_IRQ38 == _USED_
ISR(IODC_Irq38_it)
{
  Iodc_CallBackIrq(IODC_IRQ38);
}
#endif /* IODC_IT_IRQ38 == _USED_ */

#if IODC_IT_IRQ39 == _USED_
ISR(IODC_Irq39_it)
{
  Iodc_CallBackIrq(IODC_IRQ39);
}
#endif /* IODC_IT_IRQ39 == _USED_ */

#if IODC_IT_IRQ40 == _USED_
ISR(IODC_Irq40_it)
{
  Iodc_CallBackIrq(IODC_IRQ40);
}
#endif /* IODC_IT_IRQ40 == _USED_ */

#if IODC_IT_IRQ41 == _USED_
ISR(IODC_Irq41_it)
{
  Iodc_CallBackIrq(IODC_IRQ41);
}
#endif /* IODC_IT_IRQ41 == _USED_ */

#if IODC_IT_IRQ42 == _USED_
ISR(IODC_Irq42_it)
{
  Iodc_CallBackIrq(IODC_IRQ42);
}
#endif /* IODC_IT_IRQ42 == _USED_ */

#if IODC_IT_IRQ43 == _USED_
ISR(IODC_Irq43_it)
{
  Iodc_CallBackIrq(IODC_IRQ43);
}
#endif /* IODC_IT_IRQ43 == _USED_ */

#if IODC_IT_IRQ44 == _USED_
ISR(IODC_Irq44_it)
{
  Iodc_CallBackIrq(IODC_IRQ44);
}
#endif /* IODC_IT_IRQ44 == _USED_ */

#if IODC_IT_IRQ45 == _USED_
ISR(IODC_Irq45_it)
{
  Iodc_CallBackIrq(IODC_IRQ45);
}
#endif /* IODC_IT_IRQ45 == _USED_ */

#if IODC_IT_IRQ46 == _USED_
ISR(IODC_Irq46_it)
{
  Iodc_CallBackIrq(IODC_IRQ46);
}
#endif /* IODC_IT_IRQ46 == _USED_ */

#if IODC_IT_IRQ47 == _USED_
ISR(IODC_Irq47_it)
{
  Iodc_CallBackIrq(IODC_IRQ47);
}
#endif /* IODC_IT_IRQ47 == _USED_ */

#if IODC_IT_IRQ48 == _USED_
ISR(IODC_Irq48_it)
{
  Iodc_CallBackIrq(IODC_IRQ48);
}
#endif /* IODC_IT_IRQ48 == _USED_ */

#if IODC_IT_IRQ49 == _USED_
ISR(IODC_Irq49_it)
{
  Iodc_CallBackIrq(IODC_IRQ49);
}
#endif /* IODC_IT_IRQ49 == _USED_ */

#if IODC_IT_IRQ50 == _USED_
ISR(IODC_Irq50_it)
{
  Iodc_CallBackIrq(IODC_IRQ50);
}
#endif /* IODC_IT_IRQ50 == _USED_ */

#if IODC_IT_IRQ51 == _USED_
ISR(IODC_Irq51_it)
{
  Iodc_CallBackIrq(IODC_IRQ51);
}
#endif /* IODC_IT_IRQ51 == _USED_ */

#if IODC_IT_IRQ52 == _USED_
ISR(IODC_Irq52_it)
{
  Iodc_CallBackIrq(IODC_IRQ52);
}
#endif /* IODC_IT_IRQ52 == _USED_ */

#if IODC_IT_IRQ53 == _USED_
ISR(IODC_Irq53_it)
{
  Iodc_CallBackIrq(IODC_IRQ53);
}
#endif /* IODC_IT_IRQ53 == _USED_ */

#if IODC_IT_IRQ54 == _USED_
ISR(IODC_Irq54_it)
{
  Iodc_CallBackIrq(IODC_IRQ54);
}
#endif /* IODC_IT_IRQ54 == _USED_ */

#if IODC_IT_IRQ55 == _USED_
ISR(IODC_Irq55_it)
{
  Iodc_CallBackIrq(IODC_IRQ55);
}
#endif /* IODC_IT_IRQ55 == _USED_ */

#if IODC_IT_IRQ56 == _USED_
ISR(IODC_Irq56_it)
{
  Iodc_CallBackIrq(IODC_IRQ56);
}
#endif /* IODC_IT_IRQ56 == _USED_ */

#if IODC_IT_IRQ57 == _USED_
ISR(IODC_Irq57_it)
{
  Iodc_CallBackIrq(IODC_IRQ57);
}
#endif /* IODC_IT_IRQ57 == _USED_ */

#if IODC_IT_IRQ58 == _USED_
ISR(IODC_Irq58_it)
{
  Iodc_CallBackIrq(IODC_IRQ58);
}
#endif /* IODC_IT_IRQ58 == _USED_ */

#if IODC_IT_IRQ59 == _USED_
ISR(IODC_Irq59_it)
{
  Iodc_CallBackIrq(IODC_IRQ59);
}
#endif /* IODC_IT_IRQ59 == _USED_ */

#if IODC_IT_IRQ60 == _USED_
ISR(IODC_Irq60_it)
{
  Iodc_CallBackIrq(IODC_IRQ60);
}
#endif /* IODC_IT_IRQ60 == _USED_ */

#if IODC_IT_IRQ61 == _USED_
ISR(IODC_Irq61_it)
{
  Iodc_CallBackIrq(IODC_IRQ61);
}
#endif /* IODC_IT_IRQ61 == _USED_ */

#if IODC_IT_IRQ62 == _USED_
ISR(IODC_Irq62_it)
{
  Iodc_CallBackIrq(IODC_IRQ62);
}
#endif /* IODC_IT_IRQ62 == _USED_ */

#if IODC_IT_IRQ63 == _USED_
ISR(IODC_Irq63_it)
{
  Iodc_CallBackIrq(IODC_IRQ63);
}
#endif /* IODC_IT_IRQ63 == _USED_ */

#if IODC_IT_IRQ64 == _USED_
ISR(IODC_Irq64_it)
{
  Iodc_CallBackIrq(IODC_IRQ64);
}
#endif /* IODC_IT_IRQ64 == _USED_ */

#if IODC_IT_IRQ65 == _USED_
ISR(IODC_Irq65_it)
{
  Iodc_CallBackIrq(IODC_IRQ65);
}
#endif /* IODC_IT_IRQ65 == _USED_ */

#if IODC_IT_IRQ66 == _USED_
ISR(IODC_Irq66_it)
{
  Iodc_CallBackIrq(IODC_IRQ66);
}
#endif /* IODC_IT_IRQ66 == _USED_ */

#if IODC_IT_IRQ67 == _USED_
ISR(IODC_Irq67_it)
{
  Iodc_CallBackIrq(IODC_IRQ67);
}
#endif /* IODC_IT_IRQ67 == _USED_ */

#if IODC_IT_IRQ68 == _USED_
ISR(IODC_Irq68_it)
{
  Iodc_CallBackIrq(IODC_IRQ68);
}
#endif /* IODC_IT_IRQ68 == _USED_ */

#if IODC_IT_IRQ69 == _USED_
ISR(IODC_Irq69_it)
{
  Iodc_CallBackIrq(IODC_IRQ69);
}
#endif /* IODC_IT_IRQ69 == _USED_ */

#if IODC_IT_IRQ70 == _USED_
ISR(IODC_Irq70_it)
{
  Iodc_CallBackIrq(IODC_IRQ70);
}
#endif /* IODC_IT_IRQ70 == _USED_ */

#if IODC_IT_IRQ71 == _USED_
ISR(IODC_Irq71_it)
{
  Iodc_CallBackIrq(IODC_IRQ71);
}
#endif /* IODC_IT_IRQ71 == _USED_ */

#if IODC_IT_IRQ72 == _USED_
ISR(IODC_Irq72_it)
{
  Iodc_CallBackIrq(IODC_IRQ72);
}
#endif /* IODC_IT_IRQ72 == _USED_ */

#if IODC_IT_IRQ73 == _USED_
ISR(IODC_Irq73_it)
{
  Iodc_CallBackIrq(IODC_IRQ73);
}
#endif /* IODC_IT_IRQ73 == _USED_ */

#if IODC_IT_IRQ74 == _USED_
ISR(IODC_Irq74_it)
{
  Iodc_CallBackIrq(IODC_IRQ74);
}
#endif /* IODC_IT_IRQ74 == _USED_ */

#if IODC_IT_IRQ75 == _USED_
ISR(IODC_Irq75_it)
{
  Iodc_CallBackIrq(IODC_IRQ75);
}
#endif /* IODC_IT_IRQ75 == _USED_ */

#if IODC_IT_IRQ76 == _USED_
ISR(IODC_Irq76_it)
{
  Iodc_CallBackIrq(IODC_IRQ76);
}
#endif /* IODC_IT_IRQ76 == _USED_ */

#if IODC_IT_IRQ77 == _USED_
ISR(IODC_Irq77_it)
{
  Iodc_CallBackIrq(IODC_IRQ77);
}
#endif /* IODC_IT_IRQ77 == _USED_ */

#if IODC_IT_IRQ78 == _USED_
ISR(IODC_Irq78_it)
{
  Iodc_CallBackIrq(IODC_IRQ78);
}
#endif /* IODC_IT_IRQ78 == _USED_ */

#if IODC_IT_IRQ79 == _USED_
ISR(IODC_Irq79_it)
{
  Iodc_CallBackIrq(IODC_IRQ79);
}
#endif /* IODC_IT_IRQ79 == _USED_ */

#if IODC_IT_IRQ80 == _USED_
ISR(IODC_Irq80_it)
{
  Iodc_CallBackIrq(IODC_IRQ80);
}
#endif /* IODC_IT_IRQ80 == _USED_ */

#if IODC_IT_IRQ81 == _USED_
ISR(IODC_Irq81_it)
{
  Iodc_CallBackIrq(IODC_IRQ81);
}
#endif /* IODC_IT_IRQ81 == _USED_ */

#if IODC_IT_IRQ82 == _USED_
ISR(IODC_Irq82_it)
{
  Iodc_CallBackIrq(IODC_IRQ82);
}
#endif /* IODC_IT_IRQ82 == _USED_ */

#if IODC_IT_IRQ83 == _USED_
ISR(IODC_Irq83_it)
{
  Iodc_CallBackIrq(IODC_IRQ83);
}
#endif /* IODC_IT_IRQ83 == _USED_ */

#if IODC_IT_IRQ84 == _USED_
ISR(IODC_Irq84_it)
{
  Iodc_CallBackIrq(IODC_IRQ84);
}
#endif /* IODC_IT_IRQ84 == _USED_ */

#if IODC_IT_IRQ85 == _USED_
ISR(IODC_Irq85_it)
{
  Iodc_CallBackIrq(IODC_IRQ85);
}
#endif /* IODC_IT_IRQ85 == _USED_ */

#if IODC_IT_IRQ86 == _USED_
ISR(IODC_Irq86_it)
{
  Iodc_CallBackIrq(IODC_IRQ86);
}
#endif /* IODC_IT_IRQ86 == _USED_ */

#if IODC_IT_IRQ87 == _USED_
ISR(IODC_Irq87_it)
{
  Iodc_CallBackIrq(IODC_IRQ87);
}
#endif /* IODC_IT_IRQ87 == _USED_ */

#if IODC_IT_IRQ88 == _USED_
ISR(IODC_Irq88_it)
{
  Iodc_CallBackIrq(IODC_IRQ88);
}
#endif /* IODC_IT_IRQ88 == _USED_ */

#if IODC_IT_IRQ89 == _USED_
ISR(IODC_Irq89_it)
{
  Iodc_CallBackIrq(IODC_IRQ89);
}
#endif /* IODC_IT_IRQ89 == _USED_ */

#if IODC_IT_IRQ90 == _USED_
ISR(IODC_Irq90_it)
{
  Iodc_CallBackIrq(IODC_IRQ90);
}
#endif /* IODC_IT_IRQ90 == _USED_ */

#if IODC_IT_IRQ91 == _USED_
ISR(IODC_Irq91_it)
{
  Iodc_CallBackIrq(IODC_IRQ91);
}
#endif /* IODC_IT_IRQ91 == _USED_ */

#if IODC_IT_IRQ92 == _USED_
ISR(IODC_Irq92_it)
{
  Iodc_CallBackIrq(IODC_IRQ92);
}
#endif /* IODC_IT_IRQ92 == _USED_ */

#if IODC_IT_IRQ93 == _USED_
ISR(IODC_Irq93_it)
{
  Iodc_CallBackIrq(IODC_IRQ93);
}
#endif /* IODC_IT_IRQ93 == _USED_ */

#if IODC_IT_IRQ94 == _USED_
ISR(IODC_Irq94_it)
{
  Iodc_CallBackIrq(IODC_IRQ94);
}
#endif /* IODC_IT_IRQ94 == _USED_ */

#if IODC_IT_IRQ95 == _USED_
ISR(IODC_Irq95_it)
{
  Iodc_CallBackIrq(IODC_IRQ95);
}
#endif /* IODC_IT_IRQ95 == _USED_ */

#if IODC_IT_IRQ96 == _USED_
ISR(IODC_Irq96_it)
{
  Iodc_CallBackIrq(IODC_IRQ96);
}
#endif /* IODC_IT_IRQ96 == _USED_ */

#if IODC_IT_IRQ97 == _USED_
ISR(IODC_Irq97_it)
{
  Iodc_CallBackIrq(IODC_IRQ97);
}
#endif /* IODC_IT_IRQ97 == _USED_ */

#if IODC_IT_IRQ98 == _USED_
ISR(IODC_Irq98_it)
{
  Iodc_CallBackIrq(IODC_IRQ98);
}
#endif /* IODC_IT_IRQ98 == _USED_ */

#if IODC_IT_IRQ99 == _USED_
ISR(IODC_Irq99_it)
{
  Iodc_CallBackIrq(IODC_IRQ99);
}
#endif /* IODC_IT_IRQ99 == _USED_ */

#if IODC_IT_IRQ100 == _USED_
ISR(IODC_Irq100_it)
{
  Iodc_CallBackIrq(IODC_IRQ100);
}
#endif /* IODC_IT_IRQ100 == _USED_ */

#if IODC_IT_IRQ101 == _USED_
ISR(IODC_Irq101_it)
{
  Iodc_CallBackIrq(IODC_IRQ101);
}
#endif /* IODC_IT_IRQ101 == _USED_ */

#if IODC_IT_IRQ102 == _USED_
ISR(IODC_Irq102_it)
{
  Iodc_CallBackIrq(IODC_IRQ102);
}
#endif /* IODC_IT_IRQ102 == _USED_ */

#if IODC_IT_IRQ103 == _USED_
ISR(IODC_Irq103_it)
{
  Iodc_CallBackIrq(IODC_IRQ103);
}
#endif /* IODC_IT_IRQ103 == _USED_ */

#if IODC_IT_IRQ104 == _USED_
ISR(IODC_Irq104_it)
{
  Iodc_CallBackIrq(IODC_IRQ104);
}
#endif /* IODC_IT_IRQ104 == _USED_ */

#if IODC_IT_IRQ105 == _USED_
ISR(IODC_Irq105_it)
{
  Iodc_CallBackIrq(IODC_IRQ105);
}
#endif /* IODC_IT_IRQ105 == _USED_ */

#if IODC_IT_IRQ106 == _USED_
ISR(IODC_Irq106_it)
{
  Iodc_CallBackIrq(IODC_IRQ106);
}
#endif /* IODC_IT_IRQ106 == _USED_ */

#if IODC_IT_IRQ107 == _USED_
ISR(IODC_Irq107_it)
{
  Iodc_CallBackIrq(IODC_IRQ107);
}
#endif /* IODC_IT_IRQ107 == _USED_ */

#if IODC_IT_IRQ108 == _USED_
ISR(IODC_Irq108_it)
{
  Iodc_CallBackIrq(IODC_IRQ108);
}
#endif /* IODC_IT_IRQ108 == _USED_ */

#if IODC_IT_IRQ109 == _USED_
ISR(IODC_Irq109_it)
{
  Iodc_CallBackIrq(IODC_IRQ109);
}
#endif /* IODC_IT_IRQ109 == _USED_ */

#if IODC_IT_IRQ110 == _USED_
ISR(IODC_Irq110_it)
{
  Iodc_CallBackIrq(IODC_IRQ110);
}
#endif /* IODC_IT_IRQ110 == _USED_ */

#if IODC_IT_IRQ111 == _USED_
ISR(IODC_Irq111_it)
{
  Iodc_CallBackIrq(IODC_IRQ111);
}
#endif /* IODC_IT_IRQ111 == _USED_ */

#if IODC_IT_IRQ112 == _USED_
ISR(IODC_Irq112_it)
{
  Iodc_CallBackIrq(IODC_IRQ112);
}
#endif /* IODC_IT_IRQ112 == _USED_ */

#if IODC_IT_IRQ113 == _USED_
ISR(IODC_Irq113_it)
{
  Iodc_CallBackIrq(IODC_IRQ113);
}
#endif /* IODC_IT_IRQ113 == _USED_ */

#if IODC_IT_IRQ114 == _USED_
ISR(IODC_Irq114_it)
{
  Iodc_CallBackIrq(IODC_IRQ114);
}
#endif /* IODC_IT_IRQ114 == _USED_ */

#if IODC_IT_IRQ115 == _USED_
ISR(IODC_Irq115_it)
{
  Iodc_CallBackIrq(IODC_IRQ115);
}
#endif /* IODC_IT_IRQ115 == _USED_ */

#if IODC_IT_IRQ116 == _USED_
ISR(IODC_Irq116_it)
{
  Iodc_CallBackIrq(IODC_IRQ116);
}
#endif /* IODC_IT_IRQ116 == _USED_ */

#if IODC_IT_IRQ117 == _USED_
ISR(IODC_Irq117_it)
{
  Iodc_CallBackIrq(IODC_IRQ117);
}
#endif /* IODC_IT_IRQ117 == _USED_ */

#if IODC_IT_IRQ118 == _USED_
ISR(IODC_Irq118_it)
{
  Iodc_CallBackIrq(IODC_IRQ118);
}
#endif /* IODC_IT_IRQ118 == _USED_ */

#if IODC_IT_IRQ119 == _USED_
ISR(IODC_Irq119_it)
{
  Iodc_CallBackIrq(IODC_IRQ119);
}
#endif /* IODC_IT_IRQ119 == _USED_ */

#if IODC_IT_IRQ120 == _USED_
ISR(IODC_Irq120_it)
{
  Iodc_CallBackIrq(IODC_IRQ120);
}
#endif /* IODC_IT_IRQ120 == _USED_ */

#if IODC_IT_IRQ121 == _USED_
ISR(IODC_Irq121_it)
{
  Iodc_CallBackIrq(IODC_IRQ121);
}
#endif /* IODC_IT_IRQ121 == _USED_ */

#if IODC_IT_IRQ122 == _USED_
ISR(IODC_Irq122_it)
{
  Iodc_CallBackIrq(IODC_IRQ122);
}
#endif /* IODC_IT_IRQ122 == _USED_ */

#if IODC_IT_IRQ123 == _USED_
ISR(IODC_Irq123_it)
{
  Iodc_CallBackIrq(IODC_IRQ123);
}
#endif /* IODC_IT_IRQ123 == _USED_ */

#if IODC_IT_IRQ124 == _USED_
ISR(IODC_Irq124_it)
{
  Iodc_CallBackIrq(IODC_IRQ124);
}
#endif /* IODC_IT_IRQ124 == _USED_ */

#if IODC_IT_IRQ125 == _USED_
ISR(IODC_Irq125_it)
{
  Iodc_CallBackIrq(IODC_IRQ125);
}
#endif /* IODC_IT_IRQ125 == _USED_ */

#if IODC_IT_IRQ126 == _USED_
ISR(IODC_Irq126_it)
{
  Iodc_CallBackIrq(IODC_IRQ126);
}
#endif /* IODC_IT_IRQ126 == _USED_ */

#if IODC_IT_IRQ127 == _USED_
ISR(IODC_Irq127_it)
{
  Iodc_CallBackIrq(IODC_IRQ127);
}
#endif /* IODC_IT_IRQ127 == _USED_ */

#endif /* __FSL_IMX53x__ ,__FSL_IMX6x__ */

#ifdef __REL_RL78__
#ifdef __REL_RL78_D1x__
#ifdef __REL_RL78_D1A__
#if IODC_IT_IRQ0 == _USED_
ISR(IODC_Irq0_it)
{
  Iodc_CallBackIrq(IODC_IRQ0);
}
#endif /* IODC_IT_IRQ0 == _USED_ */

#if IODC_IT_IRQ1 == _USED_
ISR(IODC_Irq1_it)
{
  Iodc_CallBackIrq(IODC_IRQ1);
}
#endif /* IODC_IT_IRQ1 == _USED_ */

#if IODC_IT_IRQ2 == _USED_
ISR(IODC_Irq2_it)
{
  Iodc_CallBackIrq(IODC_IRQ2);
}
#endif /* IODC_IT_IRQ2 == _USED_ */

#if IODC_IT_IRQ3 == _USED_
ISR(IODC_Irq3_it)
{
  Iodc_CallBackIrq(IODC_IRQ3);
}
#endif /* IODC_IT_IRQ3 == _USED_ */

#if IODC_IT_IRQ4 == _USED_
ISR(IODC_Irq4_it)
{
  Iodc_CallBackIrq(IODC_IRQ4);
}
#endif /* IODC_IT_IRQ4 == _USED_ */

#if IODC_IT_IRQ5 == _USED_
ISR(IODC_Irq5_it)
{
  Iodc_CallBackIrq(IODC_IRQ5);
}
#endif /* IODC_IT_IRQ5 == _USED_ */

#endif /* __REL_RL78_D1A__ */
#endif /* __REL_RL78_D1x__ */

#ifdef __REL_RL78_F1x__
#ifdef __REL_RL78_F12__
#if IODC_IT_IRQ0 == _USED_
ISR(IODC_Irq0_it)
{
  Iodc_CallBackIrq(IODC_IRQ0);
}
#endif /* IODC_IT_IRQ0 == _USED_ */

#if IODC_IT_IRQ1 == _USED_
ISR(IODC_Irq1_it)
{
  Iodc_CallBackIrq(IODC_IRQ1);
}
#endif /* IODC_IT_IRQ1 == _USED_ */

#if IODC_IT_IRQ2 == _USED_
ISR(IODC_Irq2_it)
{
  Iodc_CallBackIrq(IODC_IRQ2);
}
#endif /* IODC_IT_IRQ2 == _USED_ */

#if IODC_IT_IRQ3 == _USED_
ISR(IODC_Irq3_it)
{
  Iodc_CallBackIrq(IODC_IRQ3);
}
#endif /* IODC_IT_IRQ3 == _USED_ */

#if IODC_IT_IRQ4 == _USED_
ISR(IODC_Irq4_it)
{
  Iodc_CallBackIrq(IODC_IRQ4);
}
#endif /* IODC_IT_IRQ4 == _USED_ */

#if IODC_IT_IRQ5 == _USED_
ISR(IODC_Irq5_it)
{
  Iodc_CallBackIrq(IODC_IRQ5);
}
#endif /* IODC_IT_IRQ5 == _USED_ */

#if IODC_IT_IRQ6 == _USED_
ISR(IODC_Irq6_it)
{
  Iodc_CallBackIrq(IODC_IRQ6);
}
#endif /* IODC_IT_IRQ6 == _USED_ */

#if IODC_IT_IRQ7 == _USED_
ISR(IODC_Irq7_it)
{
  Iodc_CallBackIrq(IODC_IRQ7);
}
#endif /* IODC_IT_IRQ7 == _USED_ */

#if IODC_IT_IRQ8 == _USED_
ISR(IODC_Irq8_it)
{
  Iodc_CallBackIrq(IODC_IRQ8);
}
#endif /* IODC_IT_IRQ8 == _USED_ */

#if IODC_IT_IRQ9 == _USED_
ISR(IODC_Irq9_it)
{
  Iodc_CallBackIrq(IODC_IRQ9);
}
#endif /* IODC_IT_IRQ9 == _USED_ */

#if IODC_IT_IRQ10 == _USED_
ISR(IODC_Irq10_it)
{
  Iodc_CallBackIrq(IODC_IRQ10);
}
#endif /* IODC_IT_IRQ10 == _USED_ */

#if IODC_IT_IRQ11 == _USED_
ISR(IODC_Irq11_it)
{
  Iodc_CallBackIrq(IODC_IRQ11);
}
#endif /* IODC_IT_IRQ11 == _USED_ */

#endif /* __REL_RL78_F12__ */
#endif /* __REL_RL78_F1x__ */
#endif /* __REL_RL78__ */

/*----------------------------------------------------------------------------*/
/*Name : IODC_Task_ts                                                         */
/*Role : This task refresh periodically:                                      */
/*       - shift register to drive LED                                        */
/*       - I/O setup                                                          */
/*Interface : -                                                               */
/*Pre-condition : -                                                           */
/*Constraints : This task have to call periodically by the OS                 */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [refresh shift register]                                                */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#if defined IODC_LED_MATRIX_TASK_REFRESH_USED || \
    defined IODC_PORT_SETUP_PERIODIC_REFRESH
TASK(IODC_Task_ts)
{
#ifndef __PC_SIMULATION__
  SYSM_INIT_MEASUREMENT();

  SYSM_START_TASK_MEASUREMENT(IODC);
#endif
  #ifdef IODC_LED_MATRIX_TASK_REFRESH_USED
  IODC_RefreshLedMatrix();
  #endif /* IODC_LED_MATRIX_TASK_REFRESH_USED */

  #ifdef IODC_PORT_SETUP_PERIODIC_REFRESH
  Iodc_SetupIoRefresh();
  #endif /* IODC_PORT_SETUP_PERIODIC_REFRESH */

  WKSS_TaskState(IODC_Task_ts, WKSS_INACTIVE_TASK);

#ifndef  __PC_SIMULATION__
  #ifdef __MONITOR_SW_WDG__
#ifndef IODC_NOT_A_TASK	
  SAFM_RefreshTaskWatchdog(IODC_Task_ts);
#endif
  #endif /*__MONITOR_SW_WDG__*/

  SYSM_END_TASK_MEASUREMENT(IODC);
  TerminateTask();
#endif
}
#endif /* defined IODC_LED_MATRIX_TASK_REFRESH_USED || \
          defined IODC_PORT_SETUP_PERIODIC_REFRESH */


/*----------------------------------------------------------------------------*/
/*Name : IODC_RefreshLedMatrix                                                */
/*Role : Sweep the matrix of leds to drive the leds                           */
/*Interface :                                                                 */
/*  - IN : Column where the led is connected                                  */
/*Pre-condition :                                                             */
/*  - The loading procedure of the line is choosen by a preprocessor directive*/
/*  - possible loading procedure : shift register or direct pin access        */
/*Constraints :                                                               */
/*  - This function have to call periodically under timer interruption        */
/*  - In case of shift register use, the SCI channel must be only used by the */
/*    shift register (no other device connected on it !).                     */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [switch off LEDs the current column]                                    */
/*    [manage the columns command]                                            */
/*    [Load the state of the line of leds for the new current column]         */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
/*                                                                            */
/*PROC IODC_RefreshLedMatrix()                                                */
/*                                                                            */
/*DATA                                                                        */
/*  Iodc_CurrentColumn                                                        */
/*  StateLedCurrentColumn (UBYTE or USHORT if (IODC_NUMBER_OF_LINE_PIN > 8)   */
/*ATAD                                                                        */
/*                                                                            */
/*  DO                                                                        */
/*    [switch off LEDs the current column] =                                  */
/*    IFDEF IODC_SHIFT_REGISTER_ACCESS_USED                                   */
/*    THEN                                                                    */
/*     [load shift register  with the state of line off]                      */
/*     [Drive the strobe pin to latch shift register data]                    */
/*    FEDFI IODC_SHIFT_REGISTER_ACCESS_USED                                   */
/*                                                                            */
/*    IFDEF IODC_DIRECT_ACCESS_USED                                           */
/*    THEN                                                                    */
/*     [inactive all lines]                                                   */
/*    FEDFI IODC_DIRECT_ACCESS_USED                                           */
/*                                                                            */
/*    [manage the the columns command] =                                      */
/*    DO                                                                      */
/*      [compute the next column to drive]                                    */
/*      [Wait]                                                                */
/*      [Disable the command of the current column]                           */
/*      [Enable the command of the next column]                               */
/*    OD                                                                      */
/*                                                                            */
/*    [Load the state of the line of leds for the new current column] =       */
/*    IFDEF IODC_DIRECT_ACCESS_USED                                           */
/*    THEN                                                                    */
/*     [active the lines to provide the requested LEDs state]                 */
/*    FEDFI IODC_DIRECT_ACCESS_USED                                           */
/*                                                                            */
/*    IFDEF IODC_SHIFT_REGISTER_ACCESS_USED                                   */
/*    THEN                                                                    */
/*     [load shift register  with the state of LEDs]                          */
/*     [Drive the strobe pin to latch shift register data]                    */
/*    FEDFI IODC_SHIFT_REGISTER_ACCESS_USED                                   */
/*                                                                            */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#ifdef IODC_LED_MATRIX_USED
#if IODC_LED_MATRIX_REFRESH == IODC_LED_MATRIX_ISR_REFRESH
ISR(IODC_RefreshLedMatrix)
#else /* for IODC_LED_MATRIX_DIRECT_REFRESH or IODC_LED_MATRIX_TASK_REFRESH */
void IODC_RefreshLedMatrix(void)
#endif /* IODC_LED_MATRIX_REFRESH == IODC_LED_MATRIX_ISR_REFRESH */
{

  #if IODC_LED_MATRIX_REFRESH == IODC_LED_MATRIX_ISR_REFRESH
  #ifdef __TASK_DURATION_MEASUREMENT_WITH_TIMER__
  ubyte OldMeasuredTask;

  RTOS_DisableAllInterrupts();
  OldMeasuredTask = RTOS_MeasuredTask;
  RTOS_TaskMeasurementEnterIt(OldMeasuredTask);
  RTOS_EnableAllInterrupts();
  #endif /* __TASK_DURATION_MEASUREMENT_WITH_TIMER__ */
  #endif /* IODC_LED_MATRIX_REFRESH == IODC_LED_MATRIX_ISR_REFRESH */

  #ifdef IODC_DIRECT_ACCESS_USED
   #if (IODC_NUMBER_OF_LINE_PIN > 8)
   ushort StateLedCurrentColumn;
   #else
    ubyte StateLedCurrentColumn;
   #endif /* IODC_NUMBER_OF_LINE_PIN > 8 */
  #endif /* IODC_DIRECT_ACCESS_USED  */

  #ifdef IODC_BLANKING_TIME_LOOP
    ubyte i;
  #endif /* IODC_BLANKING_TIME_LOOP */


    #if IODC_LED_MATRIX_REFRESH == IODC_LED_MATRIX_ISR_REFRESH
    RTOS_ENTER_IT(RTOS_MEAS_IT_LED_MTX);

    TIMC_StopChannel(IODC_TIMER_CHANNEL);
    #endif /* IODC_LED_MATRIX_REFRESH == IODC_LED_MATRIX_ISR_REFRESH */


  /*************************************/
  /* swicth off leds on current column */
  /*************************************/

#ifdef IODC_SHIFT_REGISTER_ACCESS_USED

 #if IODC_LED_MATRIX_REFRESH == IODC_LED_MATRIX_ISR_REFRESH
  /* switch off only if refresh by ISR and matrix             */
  /* not used for shift register output without matrix        */
  /* load shift register to switch off line of current column */

  #if (IODC_NUMBER_OF_LINE_PIN > 16)
  #error <LED matrix by shift register acces can not have more than 16 lines>
  #endif /* IODC_NUMBER_OF_LINE_PIN > 16 */

  #if (IODC_NUMBER_OF_LINE_PIN > 8)
  SPIC_TransmitOneByte(IODC_SHIFTER_SCI_CHANNEL, 0);
  #endif /* (IODC_NUMBER_OF_LINE_PIN > 0) */

  #if (IODC_NUMBER_OF_LINE_PIN > 0)
  SPIC_TransmitOneByte(IODC_SHIFTER_SCI_CHANNEL, 0);
  /* latch the shift register */
  IODC_SetOutputData(SHIFTER,IODC_ACTIVE);
  IODC_SetOutputData(SHIFTER,IODC_INACTIVE);
  #endif /* (IODC_NUMBER_OF_LINE_PIN > 8) */

 #endif /* IODC_LED_MATRIX_REFRESH == IODC_LED_MATRIX_ISR_REFRESH */

#endif /* IODC_SHIFT_REGISTER_ACCESS_USED */


#ifdef IODC_DIRECT_ACCESS_USED

  #if (IODC_NUMBER_OF_LINE_PIN > 0)
  Iodc_InactiveLine(0);
  #endif /* IODC_NUMBER_OF_LINE_PIN > 0 */

  #if (IODC_NUMBER_OF_LINE_PIN > 1)
  Iodc_InactiveLine(1);
  #endif /* IODC_NUMBER_OF_LINE_PIN > 1 */

  #if (IODC_NUMBER_OF_LINE_PIN > 2)
  Iodc_InactiveLine(2);
  #endif /* IODC_NUMBER_OF_LINE_PIN > 2 */

  #if (IODC_NUMBER_OF_LINE_PIN > 3)
  Iodc_InactiveLine(3);
  #endif /* IODC_NUMBER_OF_LINE_PIN > 3 */

  #if (IODC_NUMBER_OF_LINE_PIN > 4)
  Iodc_InactiveLine(4);
  #endif /* IODC_NUMBER_OF_LINE_PIN > 4 */

  #if (IODC_NUMBER_OF_LINE_PIN > 5)
  Iodc_InactiveLine(5);
  #endif /* IODC_NUMBER_OF_LINE_PIN > 5 */

  #if (IODC_NUMBER_OF_LINE_PIN > 6)
  Iodc_InactiveLine(6);
  #endif /* IODC_NUMBER_OF_LINE_PIN > 6 */

  #if (IODC_NUMBER_OF_LINE_PIN > 7)
  Iodc_InactiveLine(7);
  #endif /* IODC_NUMBER_OF_LINE_PIN > 7 */

  #if (IODC_NUMBER_OF_LINE_PIN > 8)
  Iodc_InactiveLine(8);
  #endif /* IODC_NUMBER_OF_LINE_PIN > 8 */

  #if (IODC_NUMBER_OF_LINE_PIN > 9)
  Iodc_InactiveLine(9);
  #endif /* IODC_NUMBER_OF_LINE_PIN > 9 */

  #if (IODC_NUMBER_OF_LINE_PIN > 10)
  Iodc_InactiveLine(10);
  #endif /* IODC_NUMBER_OF_LINE_PIN > 10 */

  #if (IODC_NUMBER_OF_LINE_PIN > 11)
  Iodc_InactiveLine(11);
  #endif /* IODC_NUMBER_OF_LINE_PIN > 11 */

  #if (IODC_NUMBER_OF_LINE_PIN > 12)
  Iodc_InactiveLine(12);
  #endif /* IODC_NUMBER_OF_LINE_PIN > 12 */

  #if (IODC_NUMBER_OF_LINE_PIN > 13)
  Iodc_InactiveLine(13);
  #endif /* IODC_NUMBER_OF_LINE_PIN > 13 */

#endif /* IODC_DIRECT_ACCESS_USED  */


  /********************************/
  /* Manage the command of column */
  /********************************/
#if (IODC_NUMBER_OF_COLUMN_PIN > 1)
  switch (Iodc_CurrentColumn)
  {
    case 0: /*________________________________________________________________*/
      Iodc_InactiveColumn(0);

      #ifdef IODC_BLANKING_TIME_LOOP
      for (i=0;i<IODC_BLANKING_TIME_LOOP;i++) __NOP__;
      #endif /* IODC_BLANKING_TIME_LOOP */
      Iodc_CurrentColumn = 1;

      #if IODC_LED_MATRIX_REFRESH == IODC_LED_MATRIX_ISR_REFRESH
      TIMC_SetPeriodicEventIndication(IODC_TIMER_CHANNEL,
                                      IODC_COLUMN_1_TIME_TICK);
      TIMC_TimerStartChannel(IODC_TIMER_CHANNEL);
      #endif /* IODC_LED_MATRIX_REFRESH == IODC_LED_MATRIX_ISR_REFRESH */

      Iodc_ActiveColumn(1);
      break;

  #if (IODC_NUMBER_OF_COLUMN_PIN > 1)
    case 1: /*________________________________________________________________*/
      Iodc_InactiveColumn(1);

      #ifdef IODC_BLANKING_TIME_LOOP
      for (i=0;i<IODC_BLANKING_TIME_LOOP;i++) __NOP__;
      #endif /* IODC_BLANKING_TIME_LOOP */

    #if (IODC_NUMBER_OF_COLUMN_PIN > 2)
      Iodc_CurrentColumn = 2;
      #if IODC_LED_MATRIX_REFRESH == IODC_LED_MATRIX_ISR_REFRESH
      TIMC_SetPeriodicEventIndication(IODC_TIMER_CHANNEL,
                                      IODC_COLUMN_2_TIME_TICK);
      TIMC_TimerStartChannel(IODC_TIMER_CHANNEL);
      #endif /* IODC_LED_MATRIX_REFRESH == IODC_LED_MATRIX_ISR_REFRESH */

      Iodc_ActiveColumn(2);
    #else
     #ifndef IODC_LED_MATRIX_RELAX_TIME_USED
      Iodc_CurrentColumn = 0;

      #if IODC_LED_MATRIX_REFRESH == IODC_LED_MATRIX_ISR_REFRESH
      TIMC_SetPeriodicEventIndication(IODC_TIMER_CHANNEL,
                                      IODC_COLUMN_0_TIME_TICK);
      TIMC_TimerStartChannel(IODC_TIMER_CHANNEL);
      #endif /* IODC_LED_MATRIX_REFRESH == IODC_LED_MATRIX_ISR_REFRESH */

      Iodc_ActiveColumn(0);
     #else
      Iodc_CurrentColumn = Iodc_RELAX_COLUMN;

      #if IODC_LED_MATRIX_REFRESH == IODC_LED_MATRIX_ISR_REFRESH
      TIMC_SetPeriodicEventIndication(IODC_TIMER_CHANNEL,
                                      IODC_RelaxTimeTick);
      TIMC_TimerStartChannel(IODC_TIMER_CHANNEL);
      #endif /* IODC_LED_MATRIX_REFRESH == IODC_LED_MATRIX_ISR_REFRESH */
     #endif /* IODC_LED_MATRIX_RELAX_TIME_USED */
   #endif /* IODC_NUMBER_OF_COLUMN_PIN > 2 */
      break;
  #endif /* IODC_NUMBER_OF_COLUMN_PIN > 1 */

  #if (IODC_NUMBER_OF_COLUMN_PIN > 2)
    case 2: /*________________________________________________________________*/
      Iodc_InactiveColumn(2);

      #ifdef IODC_BLANKING_TIME_LOOP
      for (i=0;i<IODC_BLANKING_TIME_LOOP;i++) __NOP__;
      #endif /* IODC_BLANKING_TIME_LOOP */

    #if (IODC_NUMBER_OF_COLUMN_PIN > 3)
      Iodc_CurrentColumn = 3;

      #if IODC_LED_MATRIX_REFRESH == IODC_LED_MATRIX_ISR_REFRESH
      TIMC_SetPeriodicEventIndication(IODC_TIMER_CHANNEL,
                                      IODC_COLUMN_3_TIME_TICK);
      TIMC_TimerStartChannel(IODC_TIMER_CHANNEL);
      #endif /* IODC_LED_MATRIX_REFRESH == IODC_LED_MATRIX_ISR_REFRESH */
      Iodc_ActiveColumn(3);
    #else
     #ifndef IODC_LED_MATRIX_RELAX_TIME_USED
      Iodc_CurrentColumn = 0;

      #if IODC_LED_MATRIX_REFRESH == IODC_LED_MATRIX_ISR_REFRESH
      TIMC_SetPeriodicEventIndication(IODC_TIMER_CHANNEL,
                                      IODC_COLUMN_0_TIME_TICK);
      TIMC_TimerStartChannel(IODC_TIMER_CHANNEL);
      #endif /* IODC_LED_MATRIX_REFRESH == IODC_LED_MATRIX_ISR_REFRESH */

      Iodc_ActiveColumn(0);
     #else
      Iodc_CurrentColumn = Iodc_RELAX_COLUMN;

      #if IODC_LED_MATRIX_REFRESH == IODC_LED_MATRIX_ISR_REFRESH
      TIMC_SetPeriodicEventIndication(IODC_TIMER_CHANNEL,
                                      IODC_RelaxTimeTick);
      TIMC_TimerStartChannel(IODC_TIMER_CHANNEL);
      #endif /* IODC_LED_MATRIX_REFRESH == IODC_LED_MATRIX_ISR_REFRESH */
     #endif /* IODC_LED_MATRIX_RELAX_TIME_USED */
    #endif /* IODC_NUMBER_OF_COLUMN_PIN > 3 */
      break;
  #endif /* IODC_NUMBER_OF_COLUMN_PIN > 2 */


  #if (IODC_NUMBER_OF_COLUMN_PIN > 3)
    case 3: /*________________________________________________________________*/
      Iodc_InactiveColumn(3);

      #ifdef IODC_BLANKING_TIME_LOOP
      for (i=0;i<IODC_BLANKING_TIME_LOOP;i++) __NOP__;
      #endif /* IODC_BLANKING_TIME_LOOP */

    #ifndef IODC_LED_MATRIX_RELAX_TIME_USED
      Iodc_CurrentColumn = 0;

      #if IODC_LED_MATRIX_REFRESH == IODC_LED_MATRIX_ISR_REFRESH
      TIMC_SetPeriodicEventIndication(IODC_TIMER_CHANNEL,
                                      IODC_COLUMN_0_TIME_TICK);
      TIMC_TimerStartChannel(IODC_TIMER_CHANNEL);
      #endif /* IODC_LED_MATRIX_REFRESH == IODC_LED_MATRIX_ISR_REFRESH */

      Iodc_ActiveColumn(0);
    #else
      Iodc_CurrentColumn = Iodc_RELAX_COLUMN;

      #if IODC_LED_MATRIX_REFRESH == IODC_LED_MATRIX_ISR_REFRESH
      TIMC_SetPeriodicEventIndication(IODC_TIMER_CHANNEL,
                                      IODC_RelaxTimeTick);
      TIMC_TimerStartChannel(IODC_TIMER_CHANNEL);
      #endif /* IODC_LED_MATRIX_REFRESH == IODC_LED_MATRIX_ISR_REFRESH */
    #endif /* IODC_LED_MATRIX_RELAX_TIME_USED */
      break;
  #endif /* IODC_NUMBER_OF_COLUMN_PIN > 3 */

  #ifdef IODC_LED_MATRIX_RELAX_TIME_USED
    case Iodc_RELAX_COLUMN: /*________________________________________________*/
      Iodc_CurrentColumn = 0;

      #if IODC_LED_MATRIX_REFRESH == IODC_LED_MATRIX_ISR_REFRESH
      TIMC_SetPeriodicEventIndication(IODC_TIMER_CHANNEL,
                                      IODC_COLUMN_0_TIME_TICK);
      TIMC_TimerStartChannel(IODC_TIMER_CHANNEL);
      #endif /* IODC_LED_MATRIX_REFRESH == IODC_LED_MATRIX_ISR_REFRESH */

      Iodc_ActiveColumn(0);
      break;
  #endif /* IODC_LED_MATRIX_RELAX_TIME_USED */

    default: /*_______________________________________________________________*/
      break;
  }
#endif /* IODC_NUMBER_OF_COLUMN_PIN > 1 */


  /**************************/
  /* Load the state of LEDs */
  /**************************/

#ifdef IODC_LED_MATRIX_RELAX_TIME_USED
  if (Iodc_CurrentColumn != Iodc_RELAX_COLUMN)
#endif /* IODC_LED_MATRIX_RELAX_TIME_USED */
  {

#ifdef IODC_DIRECT_ACCESS_USED
    StateLedCurrentColumn = IODC_TabStateLed[Iodc_CurrentColumn];

    /* drive the line of led matrix */
    #if (IODC_NUMBER_OF_LINE_PIN > 0)
    if ((StateLedCurrentColumn & Iodc_MASK_BIT1) == Iodc_MASK_BIT1)
    {
      Iodc_ActiveLine(0);
    }
    #endif /* IODC_NUMBER_OF_LINE_PIN > 0 */

    #if (IODC_NUMBER_OF_LINE_PIN > 1)
    if ((StateLedCurrentColumn & Iodc_MASK_BIT2) == Iodc_MASK_BIT2)
    {
      Iodc_ActiveLine(1);
    }
    #endif /* IODC_NUMBER_OF_LINE_PIN > 1 */

    #if (IODC_NUMBER_OF_LINE_PIN > 2)
    if ((StateLedCurrentColumn & Iodc_MASK_BIT3) == Iodc_MASK_BIT3)
    {
      Iodc_ActiveLine(2);
    }
    #endif /* IODC_NUMBER_OF_LINE_PIN > 2 */

    #if (IODC_NUMBER_OF_LINE_PIN > 3)
    if ((StateLedCurrentColumn & Iodc_MASK_BIT4) == Iodc_MASK_BIT4)
    {
      Iodc_ActiveLine(3);
    }
    #endif /* IODC_NUMBER_OF_LINE_PIN > 3 */

    #if (IODC_NUMBER_OF_LINE_PIN > 4)
    if ((StateLedCurrentColumn & Iodc_MASK_BIT5) == Iodc_MASK_BIT5)
    {
      Iodc_ActiveLine(4);
    }
    #endif /* IODC_NUMBER_OF_LINE_PIN > 4 */

    #if (IODC_NUMBER_OF_LINE_PIN > 5)
    if ((StateLedCurrentColumn & Iodc_MASK_BIT6) == Iodc_MASK_BIT6)
    {
      Iodc_ActiveLine(5);
    }
    #endif /* IODC_NUMBER_OF_LINE_PIN > 5 */

    #if (IODC_NUMBER_OF_LINE_PIN > 6)
    if ((StateLedCurrentColumn & Iodc_MASK_BIT7) == Iodc_MASK_BIT7)
    {
      Iodc_ActiveLine(6);
    }
    #endif /* IODC_NUMBER_OF_LINE_PIN > 6 */

    #if (IODC_NUMBER_OF_LINE_PIN > 7)
    if ((StateLedCurrentColumn & Iodc_MASK_BIT8) == Iodc_MASK_BIT8)
    {
      Iodc_ActiveLine(7);
    }
    #endif /* IODC_NUMBER_OF_LINE_PIN > 7 */

    #if (IODC_NUMBER_OF_LINE_PIN > 8)
    if ((StateLedCurrentColumn & Iodc_MASK_BIT9) == Iodc_MASK_BIT9)
    {
      Iodc_ActiveLine(8);
    }
    #endif /* IODC_NUMBER_OF_LINE_PIN > 8 */

    #if (IODC_NUMBER_OF_LINE_PIN > 9)
    if ((StateLedCurrentColumn & Iodc_MASK_BIT10) == Iodc_MASK_BIT10)
    {
      Iodc_ActiveLine(9);
    }
    #endif /* IODC_NUMBER_OF_LINE_PIN > 9 */

    #if (IODC_NUMBER_OF_LINE_PIN > 10)
    if ((StateLedCurrentColumn & Iodc_MASK_BIT11) == Iodc_MASK_BIT11)
    {
      Iodc_ActiveLine(10);
    }
    #endif /* IODC_NUMBER_OF_LINE_PIN > 10 */

    #if (IODC_NUMBER_OF_LINE_PIN > 11)
    if ((StateLedCurrentColumn & Iodc_MASK_BIT12) == Iodc_MASK_BIT12)
    {
      Iodc_ActiveLine(11);
    }
    #endif /* IODC_NUMBER_OF_LINE_PIN > 11 */

    #if (IODC_NUMBER_OF_LINE_PIN > 12)
    if ((StateLedCurrentColumn & Iodc_MASK_BIT13) == Iodc_MASK_BIT13)
    {
      Iodc_ActiveLine(12);
    }
    #endif /* IODC_NUMBER_OF_LINE_PIN > 12 */

    #if (IODC_NUMBER_OF_LINE_PIN > 13)
    if ((StateLedCurrentColumn & Iodc_MASK_BIT14) == Iodc_MASK_BIT14)
    {
      Iodc_ActiveLine(13);
    }
    #endif /* IODC_NUMBER_OF_LINE_PIN > 13 */
#endif /* IODC_DIRECT_ACCESS_USED */

#ifdef IODC_LED_MATRIX_DIAG
    IODC_ApplCheckLed(Iodc_CurrentColumn);
#endif

#ifdef IODC_SHIFT_REGISTER_ACCESS_USED
    /* load shift register with new leds state on the current column */

    #if ( (IODC_NUMBER_OF_LINE_PIN > 0) && (IODC_NUMBER_OF_LINE_PIN <=8) )
    /* 1 shift register to drive */
    SPIC_TransmitOneByte(IODC_SHIFTER_SCI_CHANNEL,
                         IODC_TabStateLed[Iodc_CurrentColumn]);
    /* latch the shift register */
    IODC_SetOutputData(SHIFTER,IODC_ACTIVE);
    IODC_SetOutputData(SHIFTER,IODC_INACTIVE);
    #endif /* (IODC_NUMBER_OF_LINE_PIN > 0) && (IODC_NUMBER_OF_LINE_PIN <=8) */

    #if ( (IODC_NUMBER_OF_LINE_PIN > 8) && (IODC_NUMBER_OF_LINE_PIN <=16) )
    /* 2 shift registers to drive (cascading) */
    {
      ubyte ByteToTransmit;

      ByteToTransmit = ( *(bitfield_short_t *)&(IODC_TabStateLed[Iodc_CurrentColumn]) )._byte.high;
      SPIC_TransmitOneByte(IODC_SHIFTER_SCI_CHANNEL, ByteToTransmit );

      ByteToTransmit = ( *(bitfield_short_t *)&(IODC_TabStateLed[Iodc_CurrentColumn]) )._byte.low;
      SPIC_TransmitOneByte(IODC_SHIFTER_SCI_CHANNEL, ByteToTransmit);

      /* latch the shift register */
      IODC_SetOutputData(SHIFTER,IODC_ACTIVE);
      IODC_SetOutputData(SHIFTER,IODC_INACTIVE);
    }
    #endif /* (IODC_NUMBER_OF_LINE_PIN > 8) && (IODC_NUMBER_OF_LINE_PIN <=16) */

    #if ( (IODC_NUMBER_OF_LINE_PIN > 16) && (IODC_NUMBER_OF_LINE_PIN <=24) )
    /* 3 shift registers to drive (cascading) */
    {
      ubyte ByteToTransmit;

      ByteToTransmit = ( *(bitfield_long_t *)&(IODC_TabStateLed[Iodc_CurrentColumn]) )._byte.low_m;
      SPIC_TransmitOneByte(IODC_SHIFTER_SCI_CHANNEL, ByteToTransmit );

      ByteToTransmit = ( *(bitfield_long_t *)&(IODC_TabStateLed[Iodc_CurrentColumn]) )._byte.high_l;
      SPIC_TransmitOneByte(IODC_SHIFTER_SCI_CHANNEL, ByteToTransmit );

      ByteToTransmit = ( *(bitfield_long_t *)&(IODC_TabStateLed[Iodc_CurrentColumn]) )._byte.low_l;
      SPIC_TransmitOneByte(IODC_SHIFTER_SCI_CHANNEL, ByteToTransmit );

      /* latch the shift register */
      IODC_SetOutputData(SHIFTER,IODC_ACTIVE);
      IODC_SetOutputData(SHIFTER,IODC_INACTIVE);
    }
    #endif /* (IODC_NUMBER_OF_LINE_PIN > 16) && (IODC_NUMBER_OF_LINE_PIN <=24) */

    #if ( (IODC_NUMBER_OF_LINE_PIN > 24) && (IODC_NUMBER_OF_LINE_PIN <=32) )
    /* 4 shift registers to drive (cascading) */
    {
      ubyte ByteToTransmit;

      ByteToTransmit = ( *(bitfield_long_t *)&(IODC_TabStateLed[Iodc_CurrentColumn]) )._byte.high_m;
      SPIC_TransmitOneByte(IODC_SHIFTER_SCI_CHANNEL, ByteToTransmit );

      ByteToTransmit = ( *(bitfield_long_t *)&(IODC_TabStateLed[Iodc_CurrentColumn]) )._byte.low_m;
      SPIC_TransmitOneByte(IODC_SHIFTER_SCI_CHANNEL, ByteToTransmit );

      ByteToTransmit = ( *(bitfield_long_t *)&(IODC_TabStateLed[Iodc_CurrentColumn]) )._byte.high_l;
      SPIC_TransmitOneByte(IODC_SHIFTER_SCI_CHANNEL, ByteToTransmit );

      ByteToTransmit = ( *(bitfield_long_t *)&(IODC_TabStateLed[Iodc_CurrentColumn]) )._byte.low_l;
      SPIC_TransmitOneByte(IODC_SHIFTER_SCI_CHANNEL, ByteToTransmit );

      /* latch the shift register */
      IODC_SetOutputData(SHIFTER,IODC_ACTIVE);
      IODC_SetOutputData(SHIFTER,IODC_INACTIVE);
    }
    #endif /* (IODC_NUMBER_OF_LINE_PIN > 24) && (IODC_NUMBER_OF_LINE_PIN <=32) */


    #if (IODC_NUMBER_OF_LINE_PIN > 32)
      #error <LED matrix by shift register acces can not have more than 32 lines>
    #endif /* IODC_NUMBER_OF_LINE_PIN > 32 */

#endif /* IODC_SHIFT_REGISTER_ACCESS_USED */
  }

  #if IODC_LED_MATRIX_REFRESH == IODC_LED_MATRIX_ISR_REFRESH
  RTOS_LEAVE_IT(RTOS_MEAS_IT_LED_MTX);
  #endif /* IODC_LED_MATRIX_REFRESH == IODC_LED_MATRIX_ISR_REFRESH */

  #if IODC_LED_MATRIX_REFRESH == IODC_LED_MATRIX_ISR_REFRESH
  #ifdef __TASK_DURATION_MEASUREMENT_WITH_TIMER__
  RTOS_DisableAllInterrupts();
  RTOS_TaskMeasurementLeaveIt(OldMeasuredTask);
  RTOS_EnableAllInterrupts();
  #endif /* __TASK_DURATION_MEASUREMENT_WITH_TIMER__ */
  #endif /* IODC_LED_MATRIX_REFRESH == IODC_LED_MATRIX_ISR_REFRESH */

}
#endif /* IODC_LED_MATRIX_USED */


#ifdef IODC_LED_MATRIX_USED
/*----------------------------------------------------------------------------*/
/*Name : IODC_SetLedMatrixActiveLed                                           */
/*Role : Set a state on a led which is driven by a matrix                     */
/*Interface :                                                                 */
/*  - IN : Column where the led is connected                                  */
/*  - IN : Line where the led is connected                                    */
/*  - IN : State of the led                                                   */
/*Pre-condition : -                                                           */
/*Constraints : -                                                             */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [set requested state on the requested led]                              */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
void IODC_SetLedMatrixActiveLed(ubyte Column, ubyte Line, ubyte StateLed)
{
  ushort LineOfLed;

  LineOfLed = 1<<Line;

  if(Column < IODC_NUMBER_OF_COLUMN_PIN)
  {
		if (StateLed != IODC_LED_TURN_OFF)
		{
			IODC_TabStateLed[Column] |= LineOfLed;
		}
		else
		{
			IODC_TabStateLed[Column] &= ~(LineOfLed);
		}
  }
}

/*----------------------------------------------------------------------------*/
/*Name : IODC_GetLedMatrixActiveLed                                           */
/*Role : return TRUE if the led at the matrix coordinates  specified is       */
/*       enabled when the function is called                                  */
/*Interface :                                                                 */
/*----------------------------------------------------------------------------*/
bool_t IODC_GetLedMatrixActiveLed(ushort Column, ushort Row)
{
  bool_t ret=FALSE;
  ushort LineOfLed;

  LineOfLed = 1<<Row;

  if(Column == Iodc_CurrentColumn)
  {
    if((IODC_TabStateLed[Column] & LineOfLed)!= 0)
    {
      ret =  TRUE;
    }
  }
  return(ret);
}

#endif /* IODC_LED_MATRIX_USED */


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
#ifndef __RH850__
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
#endif
#endif /* IODC_IRQ_USED */

/*----------------------------------------------------------------------------*/
/*Name : IODC_ScanInputMatrix1                                                */
/*Role : Read the state of the input located in the matrix                    */
/*Interface :                                                                 */
/*Pre-condition :                                                             */
/*  - The loading procedure of the line is choosen by a preprocessor directive*/
/*Constraints :                                                               */
/*  - This function have to call periodically under timer interruption        */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [manage the columns command]                                            */
/*    [Read the state of the input for the new current column]                */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
/*                                                                            */
/*PROC IODC_ScanInputMatrix1()                                                */
/*                                                                            */
/*DATA                                                                        */
/*  Iodc_CurrentColumn (UBYTE)                                                */
/*  StateLedCurrentColumn (UBYTE)                                             */
/*ATAD                                                                        */
/*                                                                            */
/*  DO                                                                        */
/*                                                                            */
/*    [manage the the columns command] =                                      */
/*    DO                                                                      */
/*      [compute the next column to drive]                                    */
/*      [Enable the command of the next column]                               */
/*      [Disable the command of the current column]                           */
/*    OD                                                                      */
/*                                                                            */
/*    [Load the state of the line of leds for the new current column] =       */
/*    IFDEF IODC_DIRECT_ACCESS_USED                                           */
/*    THEN                                                                    */
/*     [active the lines to provide the requested LEDs state]                 */
/*    FEDFI IODC_DIRECT_ACCESS_USED                                           */
/*                                                                            */
/*    IFDEF IODC_SHIFT_REGISTER_ACCESS_USED                                   */
/*    THEN                                                                    */
/*     [load shift register  with the state of LEDs]                          */
/*     [Drive the strobe pin to latch shift register data]                    */
/*    FEDFI IODC_SHIFT_REGISTER_ACCESS_USED                                   */
/*                                                                            */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#ifdef IODC_INPUT_MATRIX_USED
#if (IODC_NUMBER_OF_INPUT_MATRIX >0)
void IODC_ScanInputMatrix1(void)
{
  #if (IODC_ROTARY_SWITCH_1 != _NOT_USED_)
  static ubyte CurrentSwitchColumn=0;
  #endif

  /* Last Index per column save */
  if (Iodc_CurrentColumn_InMux_1 != IODC_COL_NB_ROTARY_SW_1)
  {
    IODC_LastNoRotaryIndex1 = IODC_IndexMatrix;
    IODC_LastNoRotaryColumn1 = Iodc_CurrentColumn_InMux_1;
  }

  #if (IODC_NB_LINE_INMUX_1 >0)
  /* Save state in this tab only for rotary switch */
  IODC_TabStateInputMatrix1[IODC_IndexMatrix]._bit.BIT0 =
    Iodc_MatrixLine_acquisition(1,1);

  /* Save state in this tab only for button */
  IODC_TabStateButtonMatrix1[Iodc_CurrentColumn_InMux_1]._bit.BIT0 |=
    Iodc_MatrixLine_acquisition(1,1);
  #endif

  #if (IODC_NB_LINE_INMUX_1 >1)
  /* Save state in this tab only for rotary switch */
  IODC_TabStateInputMatrix1[IODC_IndexMatrix]._bit.BIT1 =
    Iodc_MatrixLine_acquisition(2,1);

  /* Save state in this tab only for button */
  IODC_TabStateButtonMatrix1[Iodc_CurrentColumn_InMux_1]._bit.BIT1 |=
    Iodc_MatrixLine_acquisition(2,1);
  #endif

  #if (IODC_NB_LINE_INMUX_1 >2)
  /* Save state in this tab only for rotary switch */
  IODC_TabStateInputMatrix1[IODC_IndexMatrix]._bit.BIT2 =
    Iodc_MatrixLine_acquisition(3,1);

  /* Save state in this tab only for button */
  IODC_TabStateButtonMatrix1[Iodc_CurrentColumn_InMux_1]._bit.BIT2 |=
    Iodc_MatrixLine_acquisition(3,1);
  #endif

  #if (IODC_NB_LINE_INMUX_1 >3)
  /* Save state in this tab only for rotary switch */
  IODC_TabStateInputMatrix1[IODC_IndexMatrix]._bit.BIT3 =
    Iodc_MatrixLine_acquisition(4,1);

  /* Save state in this tab only for button */
  IODC_TabStateButtonMatrix1[Iodc_CurrentColumn_InMux_1]._bit.BIT3 |=
    Iodc_MatrixLine_acquisition(4,1);
  #endif

  #if (IODC_NB_LINE_INMUX_1 >4)
  /* Save state in this tab only for rotary switch */
  IODC_TabStateInputMatrix1[IODC_IndexMatrix]._bit.BIT4 =
    Iodc_MatrixLine_acquisition(5,1);

  /* Save state in this tab only for button */
  IODC_TabStateButtonMatrix1[Iodc_CurrentColumn_InMux_1]._bit.BIT4 |=
    Iodc_MatrixLine_acquisition(5,1);
  #endif


#if (IODC_NB_COLUMN_INMUX_1 > 1)
  switch (Iodc_CurrentColumn_InMux_1)
  {
   #if (IODC_ROTARY_SWITCH_1 != _NOT_USED_)
   #if (IODC_COL_NB_ROTARY_SW_1 != 0)
    case 0:
      #if (IODC_ROTARY_SWITCH_1 != _NOT_USED_)
      /*-------------ROTARY SWITCH------------------*/
      Iodc_ActiveColumn_InMux(IODC_COL_NB_ROTARY_SW_1, 1);
      Iodc_InactiveColumn_InMux(0,1);
      Iodc_CurrentColumn_InMux_1 = IODC_COL_NB_ROTARY_SW_1;

      #if (IODC_NB_COLUMN_INMUX_1 >1)
        #if (IODC_COL_NB_ROTARY_SW_1 == 1)
          #if (IODC_NB_COLUMN_INMUX_1 >2)
          CurrentSwitchColumn = 2;
          #else
          CurrentSwitchColumn = 0;
          #endif /* (IODC_NB_COLUMN_INMUX_1 >2) */
        #else
        CurrentSwitchColumn = 1;
        #endif /* (IODC_COL_NB_ROTARY_SW_1 == 1) */
      #else
      CurrentSwitchColumn = 0;
      #endif /* (IODC_NB_COLUMN_INMUX_1 >1) */
      /*--------------------------------------------*/
      #else
      /*-------------SIMPLE SWITCH------------------*/
      Iodc_ActiveColumn_InMux(1,1);
      Iodc_InactiveColumn_InMux(0,1);
      Iodc_CurrentColumn_InMux_1 = 1;
      /*--------------------------------------------*/
      #endif /* IODC_ROTARY_SWITCH_USED_1 */
    break;
   #endif /* (IODC_COL_NB_ROTARY_SW_1 != 0) */
   #endif /* (IODC_ROTARY_SWITCH_1 != _NOT_USED_) */



  #if (IODC_ROTARY_SWITCH_1 != _NOT_USED_)
  /*-------------ROTARY SWITCH------------------*/
  #if (IODC_COL_NB_ROTARY_SW_1 != 1)
     case 1:
      Iodc_ActiveColumn_InMux(IODC_COL_NB_ROTARY_SW_1, 1);
      Iodc_InactiveColumn_InMux(1,1);
      Iodc_CurrentColumn_InMux_1 = IODC_COL_NB_ROTARY_SW_1;

      #if (IODC_NB_COLUMN_INMUX_1 >2)
        #if (IODC_COL_NB_ROTARY_SW_1 == 2)
          #if (IODC_NB_COLUMN_INMUX_1 >3)
          CurrentSwitchColumn = 3;
          #else
          CurrentSwitchColumn = 0;
          #endif
        #else
        CurrentSwitchColumn = 2;
        #endif
      #else
        #if (IODC_COL_NB_ROTARY_SW_1 == 0)
        CurrentSwitchColumn = 1;
        #else
        CurrentSwitchColumn = 0;
        #endif
      #endif
    break;
  #endif /* (IODC_COL_NB_ROTARY_SW_1 != 1) */
  /*--------------------------------------------*/
  #else
  /*-------------SIMPLE SWITCH------------------*/
  #if (IODC_NB_COLUMN_INMUX_1 > 1)
    case 1:
  #if (IODC_NB_COLUMN_INMUX_1 > 2)
      Iodc_CurrentColumn_InMux_1 = 2;
      Iodc_ActiveColumn_InMux(2,1);
  #else
      Iodc_CurrentColumn_InMux_1 = 0;
      Iodc_ActiveColumn_InMux(0,1);
  #endif /* IODC_NB_COLUMN_INMUX_1 > 2 */
      Iodc_InactiveColumn_InMux(1,1);
    break;
  #endif /* IODC_NB_COLUMN_INMUX_1 > 1 */
  /*--------------------------------------------*/
  #endif /* IODC_ROTARY_SWITCH_1 != _NOT_USED_ */



  #if (IODC_ROTARY_SWITCH_1 != _NOT_USED_)
  /*-------------ROTARY SWITCH------------------*/
  #if (IODC_COL_NB_ROTARY_SW_1 != 2)
     case 2:
      Iodc_ActiveColumn_InMux(IODC_COL_NB_ROTARY_SW_1, 1);
      Iodc_InactiveColumn_InMux(2,1);
      Iodc_CurrentColumn_InMux_1 = IODC_COL_NB_ROTARY_SW_1;

      #if (IODC_NB_COLUMN_INMUX_1 >3)
        #if (IODC_COL_NB_ROTARY_SW_1 == 3)
           CurrentSwitchColumn = 0;
        #else
           CurrentSwitchColumn = 3;
        #endif
      #else
        #if (IODC_COL_NB_ROTARY_SW_1 == 0)
        CurrentSwitchColumn = 1;
        #else
        CurrentSwitchColumn = 0;
        #endif
      #endif
    break;
  #endif /* (IODC_COL_NB_ROTARY_SW_1 != 2) */
  /*--------------------------------------------*/
  #else
  /*-------------SIMPLE SWITCH------------------*/
  #if (IODC_NB_COLUMN_INMUX_1 > 2)
    case 2:
  #if (IODC_NB_COLUMN_INMUX_1 > 3)
      Iodc_CurrentColumn_InMux_1 = 3;
      Iodc_ActiveColumn_InMux(3,1);
  #else
      Iodc_CurrentColumn_InMux_1 = 0;
      Iodc_ActiveColumn_InMux(0,1);
  #endif /* IODC_NB_COLUMN_INMUX_1 > 3 */
      Iodc_InactiveColumn_InMux(2,1);
    break;
  #endif /* IODC_NB_COLUMN_INMUX_1 > 2 */
  /*--------------------------------------------*/
  #endif /* IODC_ROTARY_SWITCH_1 != _NOT_USED_ */



  #if (IODC_ROTARY_SWITCH_1 != _NOT_USED_)
  /*-------------ROTARY SWITCH------------------*/
  #if (IODC_COL_NB_ROTARY_SW_1 != 3)
     case 3:
      Iodc_ActiveColumn_InMux(IODC_COL_NB_ROTARY_SW_1, 1);
      Iodc_InactiveColumn_InMux(3,1);
      Iodc_CurrentColumn_InMux_1 = IODC_COL_NB_ROTARY_SW_1;

      #if (IODC_COL_NB_ROTARY_SW_1 == 0)
      CurrentSwitchColumn = 1;
      #else
      CurrentSwitchColumn = 0;
      #endif
    break;
  #endif /* (IODC_COL_NB_ROTARY_SW_1 != 3) */
  /*--------------------------------------------*/
  #else
  /*-------------SIMPLE SWITCH------------------*/
  #if (IODC_NB_COLUMN_INMUX_1 > 3)
    case 3:
      Iodc_ActiveColumn_InMux(0,1);
      Iodc_InactiveColumn_InMux(3,1);
      Iodc_CurrentColumn_InMux_1 = 0;
      break;
  #endif /* IODC_NB_COLUMN_INMUX_1 > 3 */
  /*--------------------------------------------*/
  #endif /* IODC_ROTARY_SWITCH_1 != _NOT_USED_ */



  #if (IODC_ROTARY_SWITCH_1 != _NOT_USED_)
  /*-------------ROTARY SWITCH------------------*/
    case IODC_COL_NB_ROTARY_SW_1 :

      switch(CurrentSwitchColumn)
      {
        case 0:
          Iodc_ActiveColumn_InMux(0,1);
          break;

      #if (IODC_NB_COLUMN_INMUX_1 > 1)
        case 1:
          Iodc_ActiveColumn_InMux(1,1);
          break;
      #endif

      #if (IODC_NB_COLUMN_INMUX_1 > 2)
        case 2:
          Iodc_ActiveColumn_InMux(2,1);
          break;
      #endif

      #if (IODC_NB_COLUMN_INMUX_1 > 3)
        case 3:
          Iodc_ActiveColumn_InMux(3,1);
          break;
      #endif

        default:
          break;
      }
      Iodc_InactiveColumn_InMux(IODC_COL_NB_ROTARY_SW_1,1);
      Iodc_CurrentColumn_InMux_1 = CurrentSwitchColumn;
    break;
  /*--------------------------------------------*/
  #endif /* IODC_ROTARY_SWITCH_1 != _NOT_USED_ */
  } /* switch (Iodc_CurrentColumn_InMux_1) */

#endif /*#if (IODC_NB_COLUMN_INMUX_1 > 1)*/
}
#endif /* (IODC_NUMBER_OF_INPUT_MATRIX >0) */


/**************************************************************/
/* It's the 'same' function to manage the secondary matrix    */
/**************************************************************/

/*----------------------------------------------------------------------------*/
/*Name : IODC_ScanInputMatrix2                                                */
/*Role : Scan the matrix to read the state of the input                       */
/*Interface :                                                                 */
/*  - IN : Column where the switch is connected - Max number of column is 4   */
/*Pre-condition :                                                             */
/*  - The loading procedure of the line is choosen by a preprocessor directive*/
/*Constraints :                                                               */
/*  - This function have to call periodically under timer interruption        */
/*----------------------------------------------------------------------------*/
#if (IODC_NUMBER_OF_INPUT_MATRIX >1)
void IODC_ScanInputMatrix2(void)
{
  /* Last Index per column save */
  if (Iodc_CurrentColumn_InMux_2 != IODC_COL_NB_ROTARY_SW_2)
  {
    IODC_LastNoRotaryIndex2 = IODC_IndexMatrix2;
    IODC_LastNoRotaryColumn2 = Iodc_CurrentColumn_InMux_2;
  }

  #if (IODC_NB_LINE_INMUX_2 >0)
  /* Save state in this tab only for rotary switch */
  IODC_TabStateInputMatrix2[IODC_IndexMatrix2]._bit.BIT0 =
    Iodc_MatrixLine_acquisition(1,2);

  /* Save state in this tab only for button */
  IODC_TabStateButtonMatrix2[Iodc_CurrentColumn_InMux_2]._bit.BIT0 |=
    Iodc_MatrixLine_acquisition(1,2);
  #endif

  #if (IODC_NB_LINE_INMUX_2 >1)
  /* Save state in this tab only for rotary switch */
  IODC_TabStateInputMatrix2[IODC_IndexMatrix2]._bit.BIT1 =
    Iodc_MatrixLine_acquisition(2,2);

  /* Save state in this tab only for button */
  IODC_TabStateButtonMatrix2[Iodc_CurrentColumn_InMux_2]._bit.BIT1 |=
    Iodc_MatrixLine_acquisition(2,2);
  #endif

  #if (IODC_NB_LINE_INMUX_2 >2)
  /* Save state in this tab only for rotary switch */
  IODC_TabStateInputMatrix2[IODC_IndexMatrix2]._bit.BIT2 =
    Iodc_MatrixLine_acquisition(3,2);

  /* Save state in this tab only for button */
  IODC_TabStateButtonMatrix2[Iodc_CurrentColumn_InMux_2]._bit.BIT2 |=
    Iodc_MatrixLine_acquisition(3,2);
  #endif

  #if (IODC_NB_LINE_INMUX_2 >3)
  /* Save state in this tab only for rotary switch */
  IODC_TabStateInputMatrix2[IODC_IndexMatrix2]._bit.BIT3 =
    Iodc_MatrixLine_acquisition(4,2);

  /* Save state in this tab only for button */
  IODC_TabStateButtonMatrix2[Iodc_CurrentColumn_InMux_2]._bit.BIT3 |=
    Iodc_MatrixLine_acquisition(4,2);
  #endif

  #if (IODC_NB_LINE_INMUX_2 >4)
  /* Save state in this tab only for rotary switch */
  IODC_TabStateInputMatrix2[IODC_IndexMatrix2]._bit.BIT4 =
    Iodc_MatrixLine_acquisition(5,2);

  /* Save state in this tab only for button */
  IODC_TabStateButtonMatrix2[Iodc_CurrentColumn_InMux_2]._bit.BIT4 |=
    Iodc_MatrixLine_acquisition(5,2);
  #endif


#if (IODC_NB_COLUMN_INMUX_2 > 1)
  switch (Iodc_CurrentColumn_InMux_2)
  {
    #if (IODC_ROTARY_SWITCH_2 != _NOT_USED_)
  /*-------------ROTARY SWITCH------------------*/
    #if (IODC_COL_NB_ROTARY_SW_2 != 0)
    case 0:
      Iodc_ActiveColumn_InMux(IODC_COL_NB_ROTARY_SW_2,2);
      Iodc_InactiveColumn_InMux(0,2);
      Iodc_CurrentColumn_InMux_2 = IODC_COL_NB_ROTARY_SW_2;

      #if (IODC_NB_COLUMN_INMUX_2 >1)
        #if (IODC_COL_NB_ROTARY_SW_2 == 1)
          #if (IODC_NB_COLUMN_INMUX_2 >2)
          CurrentSwitchColumn = 2;
          #else
          CurrentSwitchColumn = 0;
          #endif /* (IODC_NB_COLUMN_INMUX_2 >2) */
        #else
        CurrentSwitchColumn = 1;
        #endif /* (IODC_COL_NB_ROTARY_SW_2 == 1) */
      #else
      CurrentSwitchColumn = 0;
      #endif /* (IODC_NB_COLUMN_INMUX_2 >1) */
    break;
    #endif /* (IODC_COL_NB_ROTARY_SW_2 != 0) */
    /*--------------------------------------------*/
  #else
    /*-------------SIMPLE SWITCH------------------*/
    case 0:
    Iodc_ActiveColumn_InMux(1,2);
      Iodc_InactiveColumn_InMux(0,2);
      Iodc_CurrentColumn_InMux_2 = 1;
    break;
      /*--------------------------------------------*/
    #endif /* (IODC_ROTARY_SWITCH_2 != _NOT_USED_) */



  #if (IODC_ROTARY_SWITCH_2 != _NOT_USED_)
  /*-------------ROTARY SWITCH------------------*/
  #if (IODC_COL_NB_ROTARY_SW_2 != 1)
     case 1:
      Iodc_ActiveColumn_InMux(IODC_COL_NB_ROTARY_SW_2,2);
      Iodc_InactiveColumn_InMux(1,2);
      Iodc_CurrentColumn_InMux_2 = IODC_COL_NB_ROTARY_SW_2;

      #if (IODC_NB_COLUMN_INMUX_2 >2)
        #if (IODC_COL_NB_ROTARY_SW_2 == 2)
          #if (IODC_NB_COLUMN_INMUX_2 >3)
          CurrentSwitchColumn = 3;
          #else
          CurrentSwitchColumn = 0;
          #endif
        #else
        CurrentSwitchColumn = 2;
        #endif
      #else
        #if (IODC_COL_NB_ROTARY_SW_2 == 0)
        CurrentSwitchColumn = 1;
        #else
        CurrentSwitchColumn = 0;
        #endif
      #endif
    break;
  #endif /* (IODC_COL_NB_ROTARY_SW_2 != 1) */
  /*--------------------------------------------*/
  #else
  /*-------------SIMPLE SWITCH------------------*/
  #if (IODC_NB_COLUMN_INMUX_2 > 1)
    case 1:
  #if (IODC_NB_COLUMN_INMUX_2 > 2)
      Iodc_CurrentColumn_InMux_2 = 2;
      Iodc_ActiveColumn_InMux(2,2);
  #else
      Iodc_CurrentColumn_InMux_2 = 0;
      Iodc_ActiveColumn_InMux(0,2);
  #endif /* IODC_NB_COLUMN_INMUX_2 > 2 */
      Iodc_InactiveColumn_InMux(1,2);
    break;
  #endif /* IODC_NB_COLUMN_INMUX_2 > 1 */
  /*--------------------------------------------*/
  #endif /* IODC_ROTARY_SWITCH_2 != _NOT_USED_ */



  #if (IODC_ROTARY_SWITCH_2 != _NOT_USED_)
  /*-------------ROTARY SWITCH------------------*/
  #if (IODC_COL_NB_ROTARY_SW_2 != 2)
     case 2:
      Iodc_ActiveColumn_InMux(IODC_COL_NB_ROTARY_SW_2,2);
      Iodc_InactiveColumn_InMux(2,2);
      Iodc_CurrentColumn_InMux_2 = IODC_COL_NB_ROTARY_SW_2;

      #if (IODC_NB_COLUMN_INMUX_2 >3)
        #if (IODC_COL_NB_ROTARY_SW_2 == 3)
           CurrentSwitchColumn = 0;
        #else
           CurrentSwitchColumn = 3;
        #endif
      #else
        #if (IODC_COL_NB_ROTARY_SW_2 == 0)
        CurrentSwitchColumn = 1;
        #else
        CurrentSwitchColumn = 0;
        #endif
      #endif
    break;
  #endif /* (IODC_COL_NB_ROTARY_SW_2 != 2) */
  /*--------------------------------------------*/
  #else
  /*-------------SIMPLE SWITCH------------------*/
  #if (IODC_NB_COLUMN_INMUX_2 > 2)
    case 2:
  #if (IODC_NB_COLUMN_INMUX_2 > 3)
      Iodc_CurrentColumn_InMux_2 = 3;
      Iodc_ActiveColumn_InMux(3,2);
  #else
      Iodc_CurrentColumn_InMux_2 = 0;
      Iodc_ActiveColumn_InMux(0,2);
  #endif /* IODC_NB_COLUMN_INMUX_2 > 3 */
      Iodc_InactiveColumn_InMux(2,2);
    break;
  #endif /* IODC_NB_COLUMN_INMUX_2 > 2 */
  /*--------------------------------------------*/
  #endif /* IODC_ROTARY_SWITCH_2 != _NOT_USED_ */



  #if (IODC_ROTARY_SWITCH_2 != _NOT_USED_)
  /*-------------ROTARY SWITCH------------------*/
  #if (IODC_COL_NB_ROTARY_SW_2 != 3)
     case 3:
      Iodc_ActiveColumn_InMux(IODC_COL_NB_ROTARY_SW_2, 2);
      Iodc_InactiveColumn_InMux(3,2);
      Iodc_CurrentColumn_InMux_2 = IODC_COL_NB_ROTARY_SW_2;

      #if (IODC_COL_NB_ROTARY_SW_2 == 0)
      CurrentSwitchColumn = 1;
      #else
      CurrentSwitchColumn = 0;
      #endif
    break;
  #endif /* (IODC_COL_NB_ROTARY_SW_2 != 3) */
  /*--------------------------------------------*/
  #else
  /*-------------SIMPLE SWITCH------------------*/
  #if (IODC_NB_COLUMN_INMUX_2 > 3)
    case 3:
      Iodc_ActiveColumn_InMux(0,2);
      Iodc_InactiveColumn_InMux(3,2);
      Iodc_CurrentColumn_InMux_2 = 0;
      break;
  #endif /* IODC_NB_COLUMN_INMUX_2 > 3 */
  /*--------------------------------------------*/
  #endif /* IODC_ROTARY_SWITCH_2 != _NOT_USED_ */



  #if (IODC_ROTARY_SWITCH_2 != _NOT_USED_)
  /*-------------ROTARY SWITCH------------------*/
    case IODC_COL_NB_ROTARY_SW_2 :

      switch(CurrentSwitchColumn)
      {
        case 0:
          Iodc_ActiveColumn_InMux(0,2);
          break;

      #if (IODC_NB_COLUMN_INMUX_2 > 1)
        case 1:
          Iodc_ActiveColumn_InMux(1,2);
          break;
      #endif

      #if (IODC_NB_COLUMN_INMUX_2 > 2)
        case 2:
          Iodc_ActiveColumn_InMux(2,2);
          break;
      #endif

      #if (IODC_NB_COLUMN_INMUX_2 > 3)
        case 3:
          Iodc_ActiveColumn_InMux(3,2);
          break;
      #endif

        default:
          break;
      }
      Iodc_InactiveColumn_InMux(IODC_COL_NB_ROTARY_SW_2,2);
      Iodc_CurrentColumn_InMux_2 = CurrentSwitchColumn;
    break;
  /*--------------------------------------------*/
  #endif /* IODC_ROTARY_SWITCH_2 != _NOT_USED_ */
  } /* switch (Iodc_CurrentColumn_InMux_2) */

#endif /* #if (IODC_NB_COLUMN_INMUX_2 > 1) */

}
#endif /* (IODC_NUMBER_OF_INPUT_MATRIX >1) */
#endif /*IODC_INPUT_MATRIX_USED*/

/*----------------------------------------------------------------------------*/
/*Name : IODC_InputMatrixSample                                               */
/*Role : Function used on IRQ to call the matrix sample functions             */
/*Interface :                                                                 */
/*Pre-condition :                                                             */
/*  - The loading procedure of the line is choosen by a preprocessor directive*/
/*Constraints :                                                               */
/*  - This function have to call periodically under timer interruption        */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [Call sampling function of the matrix]                                  */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#ifdef IODC_INPUT_MATRIX_USED

#if (IODC_IRQ_READING_MATRIX_1 == _USED_) || \
    (IODC_IRQ_READING_MATRIX_2 == _USED_)
void IODC_InputMatrixSample(void)
{
#if (IODC_IRQ_READING_MATRIX_1 == _USED_)
  IODC_ScanInputMatrix1();

  #if (IODC_INPUT_MATRIX_SCAN_REFRESH == IODC_INPUT_MATRIX_POOLING_REFRESH)
  IODC_ROTATION_DETECT_FCT_1();
  #endif /* (IODC_INPUT_MATRIX_SCAN_REFRESH == IODC_INPUT_MATRIX_POOLING_REFRESH) */
#endif /* (IODC_IRQ_READING_MATRIX_1 == _USED_) */

#if (IODC_IRQ_READING_MATRIX_2 == _USED_)
  IODC_ScanInputMatrix2();

  #if (IODC_INPUT_MATRIX_SCAN_REFRESH == IODC_INPUT_MATRIX_POOLING_REFRESH)
  IODC_ROTATION_DETECT_FCT_2();
  #endif /* (IODC_INPUT_MATRIX_SCAN_REFRESH == IODC_INPUT_MATRIX_POOLING_REFRESH) */
#endif /* (IODC_IRQ_READING_MATRIX_2 == _USED_) */

#if (IODC_INPUT_MATRIX_SCAN_REFRESH == IODC_INPUT_MATRIX_ISR_REFRESH)
  if (IODC_IndexMatrix < (IODC_MUXIN_NB_SAMPLE - 1) )
  {
    IODC_IndexMatrix++;
  }
  else
  {
    IODC_IndexMatrix = 0;
  }

  #if (IODC_ROTARY_SWITCH_2 != _NOT_USED_)
  if (IODC_IndexMatrix2 < (IODC_MUXIN_NB_SAMPLE - 1) )
  {
    IODC_IndexMatrix2++;
  }
  else
  {
    IODC_IndexMatrix2 = 0;
  }
  #endif /* (IODC_ROTARY_SWITCH_2 != _NOT_USED_) */

#endif /* (IODC_INPUT_MATRIX_SCAN_REFRESH == IODC_INPUT_MATRIX_ISR_REFRESH) */

}
#endif /* (IODC_IRQ_READING_MATRIX_1 == _USED_) ||\
          (IODC_IRQ_READING_MATRIX_2 == _USED_) */
#endif /* IODC_INPUT_MATRIX_USED */


/*_____ E N D _____ (iodc.c) _________________________________________________*/

