/******************************************************************************/
/*@F_NAME:           iodc_config.h                                            */
/*@F_PURPOSE:        Configuration file for iodc module                       */
/*@F_CREATED_BY:     M. Sergent                                               */
/*@F_CREATION_DATE:  13/09/2000                                               */
/*@F_MPROC_TYPE:     NEC V850 Fx3/Dx3/Dx4, Freescale HCS12xx, HCS08xx,        */
/*                   IMX53,IMX6x, TX49                                        */
/*                   Renesas RL78 D1A, RL78 F12                               */
/************************************** (C) Copyright 2013 Magneti Marelli ****/

#ifndef IODC_CONFIG_H
#define IODC_CONFIG_H

/*

 NOTE : When it is written processor dependent, please see iodd.h

*/


/*______ I N C L U D E - F I L E S ___________________________________________*/

#include "syst.h"
#include "iodd.h"

/* to include in case of LED matrix */
/*
#include "timc.h"  to include if IODC_LED_MATRIX_REFRESH == IODC_LED_MATRIX_ISR_REFRESH
#include "spic.h"  to include if IODC_SHIFT_REGISTER_ACCESS_USED defined
*/


/*______ G L O B A L - D E F I N E ___________________________________________*/

/*----------------------------------------------------------------------------*/
/* Irq interrupts definition                                                  */
/*----------------------------------------------------------------------------*/

/* Note for Motorola HCS12 :                          */
/* IRQ pin : IODC_IT_IRQ0                             */
/* Key wake-up port H : IODC_IT_IRQ1 .. IODC_IT_IRQ8  */
/* Key wake-up port J : IODC_IT_IRQ9 .. IODC_IT_IRQ12 */


/* declare IRQ interrupts to use */

#if defined(__MC9S08xx__)
#define IODC_IT_IRQPIN  _NOT_USED_ /* _USED_, _NOT_USED_ */

/* SPECIAL CONFIGURATION FOR MC9S08 IRQ INPUT */
/* ONLY IRQ USE                               */
/* TWO CONFIGURATIONS:                        */
/* IODD_IT_HIGH_LEVEL  RISING EDGE            */
/* IODD_IT_LOW_LEVEL   FALLING EDGE           */

/* CAN_WAKE_UP */
#define IODC_DirectIn_Port_CAN_WAKE_UP       IRQ
#define IODC_DirectIn_Irq_CAN_WAKE_UP        IODD_IT_HIGH_LEVEL
#define IODC_DirectIn_PullUp_CAN_WAKE_UP     IODD_NO_PULL_UP

#define IODC_DirectIn_Bit_CAN_WAKE_UP        _NOT_USED_
#define IODC_DirectIn_Logic_CAN_WAKE_UP      _NOT_USED_
#define IODC_DirectIn_Ref_CAN_WAKE_UP        _NOT_USED_

#endif /* defined(__MC9S08xx__ */


#if defined(__MC9S12xx__) || defined(__MC9S08xx__)
#define IODC_IT_IRQ0  _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ1  _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ2  _NOT_USED_ /* _USED_, _NOT_USED_ */
#endif /* defined(__MC9S12xx__)) || defined(__MC9S08xx__) */

#if (defined(__MC9S12xx__) || defined(__MC9S08xx__))
#define IODC_IT_IRQ3  _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ4  _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ5  _NOT_USED_ /* _USED_, _NOT_USED_ */
#endif /* (defined(__MC9S12xx__) || defined(__MC9S08xx__))  */

#if defined(__MC9S08xx__)
#define IODC_IT_IRQ6  _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ7  _NOT_USED_ /* _USED_, _NOT_USED_ */
#endif /* defined(__MC9S08xx__)  */

#if (defined(__MC9S12xx__))
#define IODC_IT_IRQ9   _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ10  _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ11  _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ12  _NOT_USED_ /* _USED_, _NOT_USED_ */
#endif /* (defined(__MC9S12xx__)) */

#if (defined(__NEC_V850__))
#define IODC_IT_IRQ0    _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ1    _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ2    _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ3    _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ4    _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ5    _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ6    _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ7    _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ8    _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ9    _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ10   _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ11   _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ12   _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ13   _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ14   _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ15   _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ_NMI _NOT_USED_ /* _USED_, _NOT_USED_ */
#endif /* (defined(__NEC_V850__)) */

#ifdef __REL_RL78__
#ifdef __REL_RL78_D1x__
#ifdef __REL_RL78_D1A__
#define IODC_IT_IRQ0  _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ1  _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ2  _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ3  _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ4  _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ5  _NOT_USED_ /* _USED_, _NOT_USED_ */
#endif /* __REL_RL78_D1A__ */
#endif /* __REL_RL78_D1x__ */

#ifdef __REL_RL78_F1x__
#ifdef __REL_RL78_F12__
#define IODC_IT_IRQ0  _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ1  _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ2  _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ3  _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ4  _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ5  _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ6  _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ7  _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ8  _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ9  _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ10  _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ11  _NOT_USED_ /* _USED_, _NOT_USED_ */
#endif /* __REL_RL78_F12__ */
#endif /* __REL_RL78_F1x__ */
#endif /* __REL_RL78__ */

/* install call-back functions */
#if defined(__MC9S08xx__)
#define IODC_IT_IRQ0_CALLBACK  NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ1_CALLBACK  NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ2_CALLBACK  NULL /* applicative function to call or NULL */
#endif /* defined(__MC9S08xx__) */

#if (defined(__MC9S12xx__) || defined(__MC9S08xx__))
#define IODC_IT_IRQ3_CALLBACK  NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ4_CALLBACK  NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ5_CALLBACK  NULL /* applicative function to call or NULL */
#endif /* defined(__MC9S12xx__) || defined(__MC9S08xx__) */

#if (defined(__MC9S12xx__) || defined(__MC9S08xx__))
#define IODC_IT_IRQ6_CALLBACK   NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ7_CALLBACK   NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ8_CALLBACK   NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ9_CALLBACK   NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ10_CALLBACK  NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ11_CALLBACK  NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ12_CALLBACK  NULL /* applicative function to call or NULL */
#endif /* defined(__MC9S12xx__) || defined(__MC9S08xx__) */

#if (defined(__NEC_V850__))
#define IODC_IT_IRQ0_CALLBACK     NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ1_CALLBACK     NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ2_CALLBACK     NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ3_CALLBACK     NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ4_CALLBACK     NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ5_CALLBACK     NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ6_CALLBACK     NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ7_CALLBACK     NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ8_CALLBACK     NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ9_CALLBACK     NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ10_CALLBACK    NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ11_CALLBACK    NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ12_CALLBACK    NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ13_CALLBACK    NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ14_CALLBACK    NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ15_CALLBACK    NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ_NMI_CALLBACK  NULL /* applicative function to call or NULL */
#endif /* (defined(__NEC_V850__)) */

#ifdef __TX49__
/* declare IRQ interrupts to use */
#define IODC_IT_IRQ0  _USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ1  _USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ2  _USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ3  _USED_ /* _USED_, _NOT_USED_ */

/* install call-back functions */
#define IODC_IT_IRQ0_CALLBACK  NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ1_CALLBACK  NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ2_CALLBACK  NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ3_CALLBACK  NULL /* applicative function to call or NULL */
#endif /* __TX49__ */

#if defined(__FSL_IMX53x__) || defined(__FSL_IMX6x__)
/* declare IRQ interrupts to use */
#define IODC_IT_IRQ0   _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ1   _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ2   _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ3   _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ4   _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ5   _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ6   _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ7   _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ8   _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ9   _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ10  _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ11  _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ12  _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ13  _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ14  _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ15  _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ16  _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ17  _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ18  _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ19  _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ20  _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ21  _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ22  _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ23  _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ24  _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ25  _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ26  _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ27  _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ28  _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ29  _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ30  _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ31  _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ32  _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ33  _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ34  _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ35  _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ36  _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ37  _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ38  _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ39  _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ40  _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ41  _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ42  _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ43  _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ44  _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ45  _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ46  _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ47  _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ48  _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ49  _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ50  _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ51  _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ52  _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ53  _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ54  _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ55  _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ56  _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ57  _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ58  _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ59  _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ60  _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ61  _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ62  _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ63  _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ64  _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ65  _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ66  _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ67  _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ68  _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ69  _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ70  _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ71  _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ72  _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ73  _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ74  _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ75  _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ76  _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ77  _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ78  _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ79  _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ80  _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ81  _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ82  _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ83  _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ84  _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ85  _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ86  _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ87  _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ88  _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ89  _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ90  _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ91  _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ92  _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ93  _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ94  _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ95  _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ96  _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ97  _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ98  _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ99  _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ100 _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ101 _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ102 _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ103 _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ104 _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ105 _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ106 _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ107 _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ108 _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ109 _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ110 _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ111 _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ112 _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ113 _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ114 _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ115 _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ116 _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ117 _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ118 _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ119 _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ120 _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ121 _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ122 _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ123 _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ124 _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ125 _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ126 _NOT_USED_ /* _USED_, _NOT_USED_ */
#define IODC_IT_IRQ127 _NOT_USED_ /* _USED_, _NOT_USED_ */

/* install call-back functions */
#define IODC_IT_IRQ0_CALLBACK    NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ1_CALLBACK    NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ2_CALLBACK    NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ3_CALLBACK    NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ4_CALLBACK    NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ5_CALLBACK    NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ6_CALLBACK    NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ7_CALLBACK    NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ8_CALLBACK    NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ9_CALLBACK    NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ10_CALLBACK   NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ11_CALLBACK   NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ12_CALLBACK   NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ13_CALLBACK   NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ14_CALLBACK   NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ15_CALLBACK   NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ16_CALLBACK   NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ17_CALLBACK   NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ18_CALLBACK   NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ19_CALLBACK   NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ20_CALLBACK   NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ21_CALLBACK   NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ22_CALLBACK   NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ23_CALLBACK   NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ24_CALLBACK   NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ25_CALLBACK   NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ26_CALLBACK   NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ27_CALLBACK   NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ28_CALLBACK   NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ29_CALLBACK   NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ30_CALLBACK   NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ31_CALLBACK   NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ32_CALLBACK   NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ33_CALLBACK   NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ34_CALLBACK   NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ35_CALLBACK   NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ36_CALLBACK   NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ37_CALLBACK   NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ38_CALLBACK   NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ39_CALLBACK   NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ40_CALLBACK   NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ41_CALLBACK   NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ42_CALLBACK   NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ43_CALLBACK   NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ44_CALLBACK   NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ45_CALLBACK   NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ46_CALLBACK   NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ47_CALLBACK   NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ48_CALLBACK   NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ49_CALLBACK   NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ50_CALLBACK   NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ51_CALLBACK   NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ52_CALLBACK   NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ53_CALLBACK   NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ54_CALLBACK   NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ55_CALLBACK   NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ56_CALLBACK   NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ57_CALLBACK   NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ58_CALLBACK   NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ59_CALLBACK   NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ60_CALLBACK   NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ61_CALLBACK   NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ62_CALLBACK   NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ63_CALLBACK   NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ64_CALLBACK   NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ65_CALLBACK   NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ66_CALLBACK   NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ67_CALLBACK   NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ68_CALLBACK   NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ69_CALLBACK   NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ70_CALLBACK   NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ71_CALLBACK   NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ72_CALLBACK   NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ73_CALLBACK   NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ74_CALLBACK   NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ75_CALLBACK   NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ76_CALLBACK   NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ77_CALLBACK   NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ78_CALLBACK   NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ79_CALLBACK   NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ80_CALLBACK   NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ81_CALLBACK   NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ82_CALLBACK   NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ83_CALLBACK   NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ84_CALLBACK   NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ85_CALLBACK   NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ86_CALLBACK   NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ87_CALLBACK   NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ88_CALLBACK   NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ89_CALLBACK   NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ90_CALLBACK   NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ91_CALLBACK   NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ92_CALLBACK   NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ93_CALLBACK   NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ94_CALLBACK   NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ95_CALLBACK   NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ96_CALLBACK   NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ97_CALLBACK   NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ98_CALLBACK   NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ99_CALLBACK   NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ100_CALLBACK  NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ101_CALLBACK  NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ102_CALLBACK  NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ103_CALLBACK  NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ104_CALLBACK  NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ105_CALLBACK  NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ106_CALLBACK  NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ107_CALLBACK  NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ108_CALLBACK  NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ109_CALLBACK  NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ110_CALLBACK  NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ111_CALLBACK  NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ112_CALLBACK  NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ113_CALLBACK  NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ114_CALLBACK  NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ115_CALLBACK  NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ116_CALLBACK  NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ117_CALLBACK  NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ118_CALLBACK  NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ119_CALLBACK  NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ120_CALLBACK  NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ121_CALLBACK  NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ122_CALLBACK  NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ123_CALLBACK  NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ124_CALLBACK  NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ125_CALLBACK  NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ126_CALLBACK  NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ127_CALLBACK  NULL /* applicative function to call or NULL */
#endif /* __FSL_IMX53x__ , __FSL_IMX6x__*/

#ifdef __REL_RL78__
#ifdef __REL_RL78_D1x__
#ifdef __REL_RL78_D1A__
#define IODC_IT_IRQ0_CALLBACK  NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ1_CALLBACK  NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ2_CALLBACK  NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ3_CALLBACK  NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ4_CALLBACK  NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ5_CALLBACK  NULL /* applicative function to call or NULL */
#endif /* __REL_RL78_D1A__ */
#endif /* __REL_RL78_D1x__ */

#ifdef __REL_RL78_F1x__
#ifdef __REL_RL78_F12__
#define IODC_IT_IRQ0_CALLBACK  NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ1_CALLBACK  NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ2_CALLBACK  NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ3_CALLBACK  NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ4_CALLBACK  NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ5_CALLBACK  NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ6_CALLBACK  NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ7_CALLBACK  NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ8_CALLBACK  NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ9_CALLBACK  NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ10_CALLBACK  NULL /* applicative function to call or NULL */
#define IODC_IT_IRQ11_CALLBACK  NULL /* applicative function to call or NULL */
#endif /* __REL_RL78_F12__ */
#endif /* __REL_RL78_F1x__ */
#endif /* __REL_RL78__ */

#if (defined(__CY_TV2__))

/* declare IRQ interrupts to use */
#define IODC_IT_IRQ0   _NOT_USED_ /* PORT0  interrupt _USED_, _NOT_USED_ */
#define IODC_IT_IRQ1   _NOT_USED_ /* PORT1  interrupt _USED_, _NOT_USED_ */
#define IODC_IT_IRQ2   _NOT_USED_ /* PORT2  interrupt _USED_, _NOT_USED_ */
#define IODC_IT_IRQ3   _NOT_USED_ /* PORT3  interrupt _USED_, _NOT_USED_ */
#define IODC_IT_IRQ4   _NOT_USED_ /* PORT4  interrupt _USED_, _NOT_USED_ */
#define IODC_IT_IRQ5   _NOT_USED_ /* PORT5  interrupt _USED_, _NOT_USED_ */
#define IODC_IT_IRQ6   _NOT_USED_ /* PORT6  interrupt _USED_, _NOT_USED_ */
#define IODC_IT_IRQ7   _NOT_USED_ /* PORT7  interrupt _USED_, _NOT_USED_   For Bootloader IMC*/
#define IODC_IT_IRQ8   _NOT_USED_ /* PORT8  interrupt _USED_, _NOT_USED_ */
#define IODC_IT_IRQ9   _NOT_USED_ /* PORT9  interrupt _USED_, _NOT_USED_ */
#define IODC_IT_IRQ10  _NOT_USED_ /* PORT10 interrupt _USED_, _NOT_USED_ */
#define IODC_IT_IRQ11  _NOT_USED_ /* PORT11 interrupt _USED_, _NOT_USED_ */
#define IODC_IT_IRQ12  _NOT_USED_ /* PORT12 interrupt _USED_, _NOT_USED_ */
#define IODC_IT_IRQ13  _NOT_USED_ /* PORT13 interrupt _USED_, _NOT_USED_ */
#define IODC_IT_IRQ14  _NOT_USED_ /* PORT14 interrupt _USED_, _NOT_USED_ */
#define IODC_IT_IRQ15  _NOT_USED_ /* PORT15 interrupt _USED_, _NOT_USED_ */
#define IODC_IT_IRQ16  _NOT_USED_ /* PORT16 interrupt _USED_, _NOT_USED_ */
#define IODC_IT_IRQ17  _NOT_USED_ /* PORT17 interrupt _USED_, _NOT_USED_ */
#define IODC_IT_IRQ18  _NOT_USED_ /* PORT18 interrupt _USED_, _NOT_USED_ */
#define IODC_IT_IRQ19  _NOT_USED_ /* PORT19 interrupt _USED_, _NOT_USED_ */
#define IODC_IT_IRQ20  _NOT_USED_ /* PORT20 interrupt _USED_, _NOT_USED_ */
#define IODC_IT_IRQ21  _NOT_USED_ /* PORT21 interrupt _USED_, _NOT_USED_ */
#define IODC_IT_IRQ22  _NOT_USED_ /* PORT22 interrupt _USED_, _NOT_USED_ */
#define IODC_IT_IRQ23  _NOT_USED_ /* PORT23 interrupt _USED_, _NOT_USED_ */
#define IODC_IT_IRQ24  _NOT_USED_ /* PORT24 interrupt _USED_, _NOT_USED_ */
#define IODC_IT_IRQ25  _NOT_USED_ /* PORT25 interrupt _USED_, _NOT_USED_ */
#define IODC_IT_IRQ26  _NOT_USED_ /* PORT26 interrupt _USED_, _NOT_USED_ */
#define IODC_IT_IRQ27  _NOT_USED_ /* PORT27 interrupt _USED_, _NOT_USED_ */
#define IODC_IT_IRQ28  _NOT_USED_ /* PORT28 interrupt _USED_, _NOT_USED_ */

#define IODC_IT_IRQ0_CALLBACK     NULL                   /* PORT0  applicative function to call or NULL */
#define IODC_IT_IRQ1_CALLBACK     NULL                   /* PORT1  applicative function to call or NULL */
#define IODC_IT_IRQ2_CALLBACK     NULL                   /*ButtonIntHandler For Bootloader IMC   */  /* PORT2  applicative function to call or NULL */
#define IODC_IT_IRQ3_CALLBACK     NULL                   /* PORT3  applicative function to call or NULL */
#define IODC_IT_IRQ4_CALLBACK     NULL                   /* PORT4  applicative function to call or NULL */
#define IODC_IT_IRQ5_CALLBACK     NULL                   /* PORT5  applicative function to call or NULL */
#define IODC_IT_IRQ6_CALLBACK     NULL                   /* PORT6  applicative function to call or NULL */
#define IODC_IT_IRQ7_CALLBACK     NULL                   /* IODC_PortIntHandler For Bootloader IMC *//* PORT7  applicative function to call or NULL */
#define IODC_IT_IRQ8_CALLBACK     NULL                   /* PORT8  applicative function to call or NULL */
#define IODC_IT_IRQ9_CALLBACK     NULL                   /* PORT9  applicative function to call or NULL */
#define IODC_IT_IRQ10_CALLBACK    NULL                   /* PORT10 applicative function to call or NULL */
#define IODC_IT_IRQ11_CALLBACK    NULL                   /* PORT11 applicative function to call or NULL */
#define IODC_IT_IRQ12_CALLBACK    NULL                   /* PORT12 applicative function to call or NULL */
#define IODC_IT_IRQ13_CALLBACK    NULL                   /* PORT13 applicative function to call or NULL */
#define IODC_IT_IRQ14_CALLBACK    NULL                   /* PORT14 applicative function to call or NULL */
#define IODC_IT_IRQ15_CALLBACK    NULL                   /* PORT15 applicative function to call or NULL */
#define IODC_IT_IRQ16_CALLBACK    NULL                   /* PORT16 applicative function to call or NULL */
#define IODC_IT_IRQ17_CALLBACK    NULL                   /* PORT17 applicative function to call or NULL */
#define IODC_IT_IRQ18_CALLBACK    NULL                   /* PORT18 applicative function to call or NULL */
#define IODC_IT_IRQ19_CALLBACK    NULL                   /* PORT19 applicative function to call or NULL */
#define IODC_IT_IRQ20_CALLBACK    NULL                   /* PORT20 applicative function to call or NULL */
#define IODC_IT_IRQ21_CALLBACK    NULL                   /* PORT21 applicative function to call or NULL */
#define IODC_IT_IRQ22_CALLBACK    NULL                   /* PORT22 applicative function to call or NULL */
#define IODC_IT_IRQ23_CALLBACK    NULL                   /* PORT23 applicative function to call or NULL */
#define IODC_IT_IRQ24_CALLBACK    NULL                   /* PORT24 applicative function to call or NULL */
#define IODC_IT_IRQ25_CALLBACK    NULL                   /* PORT25 applicative function to call or NULL */
#define IODC_IT_IRQ26_CALLBACK    NULL                   /* PORT26 applicative function to call or NULL */
#define IODC_IT_IRQ27_CALLBACK    NULL                   /* PORT27 applicative function to call or NULL */
#define IODC_IT_IRQ28_CALLBACK    NULL                   /* PORT28 applicative function to call or NULL */

#endif /* (defined(__CY_TV2__)) */


/*----------------------------------------------------------------------------*/
/* Input matrix                                                               */
/*----------------------------------------------------------------------------*/

/* Uncomment if input matrix is used */
/*#define IODC_INPUT_MATRIX_USED _USED_*/

#if defined(IODC_INPUT_MATRIX_USED)

  /*** Input matrix access paramaters ***/

  /* Must be defined here to avoid warning: used here after and in iodc.c */
  #define IODC_INPUT_MATRIX_ISR_REFRESH       (_NOT_USED_ + 1)
  #define IODC_INPUT_MATRIX_POOLING_REFRESH   (_NOT_USED_ + 2)

  /* select type of LED matrix refresh */
  #define IODC_INPUT_MATRIX_SCAN_REFRESH     IODC_INPUT_MATRIX_ISR_REFRESH
                                          /* IODC_INPUT_MATRIX_POOLING_REFRESH */


  /*** Input matrix : timer configuration for mux input sampling ***/

  #define IODC_TIMER_CHANNEL_INMUX  TIMC_CmChannel_CM6   /* TIMC_CHANNEL_x */

  /* period in tick : */
  /*  - due the timer constraints, the value is processor-dependent, check */
  /*    TIMD / TIMC to know the allowed values */

  /* application mode frequency scan. Period defined in tick */
  #define IODC_TIMER_PERIOD_INMUX       ((ulong) 250)

#endif /* IODC_INPUT_MATRIX_USED */


/*----------------------------------------------------------------------------*/
/* Leds matrix                                                                */
/*----------------------------------------------------------------------------*/

/*** Leds matrix access paramaters ***/

/********************************** Define if used ****************************/
/*  #define IODC_LED_MATRIX_USED */

#define IODC_LED_MATRIX_TYPE  _NOT_USED_
                              /* _NOT_USED_                  */
                              /* IODC_LINE_BY_PORT,          */
                              /* IODC_LINE_BY_SHIFT_REGISTER */

#if (IODC_LED_MATRIX_TYPE != _NOT_USED_)

  /* select type of LED matrix refresh */
  #define IODC_LED_MATRIX_REFRESH  IODC_LED_MATRIX_DIRECT_REFRESH
                                   /* IODC_LED_MATRIX_DIRECT_REFRESH */
                                   /* IODC_LED_MATRIX_TASK_REFRESH   */
                                   /* IODC_LED_MATRIX_ISR_REFRESH    */


  /*** Led matrix : blanking time (transistors response time) ***/

  /* Waiting time between desactivation of current column and activation of */
  /* next column. Time is a nop loop counter.                               */
  #define IODC_BLANKING_TIME_LOOP       ((ubyte) 30)


  #if (IODC_LED_MATRIX_REFRESH == IODC_LED_MATRIX_ISR_REFRESH)

    /*** Led matrix : timer configuration for Leds Sweeping paramaters ***/
    #define IODC_TIMER_CHANNEL  TIMC_TICK_LED_MATRIX   /* TIMC_CHANNEL_x */


    /* period in tick : */
    /*  - due the timer constraints, the value is processor-dependent, check */
    /*    TIMD / TIMC to know the allowed values                             */
    /* application mode frequency scan. Period defined in tick               */
    /* Duration time of column 0 */
    #define IODC_COLUMN_0_TIME_TICK                                         \
      (((ushort)(TIMC_ConvTime2Tick( 4000/*in us*/ ,                        \
                                     TIMC_GetPrescaler(IODC_TIMER_CHANNEL))))-1)

    /* Duration time of column 1 */
    #define IODC_COLUMN_1_TIME_TICK                                         \
      (((ushort)(TIMC_ConvTime2Tick( 4000/*in us*/ ,                        \
                                     TIMC_GetPrescaler(IODC_TIMER_CHANNEL))))-1)
    /* Duration time of column 2 */
    #define IODC_COLUMN_2_TIME_TICK                                         \
      (((ushort)(TIMC_ConvTime2Tick( 4000/*in us*/ ,                        \
                                     TIMC_GetPrescaler(IODC_TIMER_CHANNEL))))-1)
    /* Duration time of column 3 */
    #define IODC_COLUMN_3_TIME_TICK                                         \
      (((ushort)(TIMC_ConvTime2Tick( 4000/*in us*/ ,                        \
                                     TIMC_GetPrescaler(IODC_TIMER_CHANNEL))))-1)

  #endif /* IODC_LED_MATRIX_REFRESH == IODC_LED_MATRIX_ISR_REFRESH */


  /*** Led matrix : relax time configuration     ***/
  /*** (insertion of a vitual column not drived) ***/
  /* Define if used. Calcul done in IODC_UpdateRelaxTimeLedMatrix function. */
  #define IODC_LED_MATRIX_RELAX_TIME_USED _USED_

#endif /* IODC_LED_MATRIX_TYPE != _NOT_USED_ */


/*----------------------------------------------------------------------------*/
/* EOL : pin logical to enable or not                                         */
/*----------------------------------------------------------------------------*/

#ifdef __EOL_ENABLE__
/* EOL output mode: used or not logic configuration */
#define IODC_EOL_OUTPUT_LOGIC       _USED_ /* _USED_ , _NOT_USED_ */
/* EOL input mode: used or not logic configuration */
#define IODC_EOL_INPUT_LOGIC        _USED_ /* _USED_ , _NOT_USED_ */
#endif /* __EOL_ENABLE__ */


/*---------------------------------------------------------------------------------*/
/* Periodical refresh of I/O setup                                                 */
/* If activated, Iodc_SetupIoRefresh() is called periodically by IODC_Task         */
/*---------------------------------------------------------------------------------*/
/*#define IODC_PORT_SETUP_PERIODIC_REFRESH */  /*TODO: check refresh function after porting done */

/*---------------------------------------------------------------------------------*/
/* Calling period for Task used to refresh shift register and/or refresh I/O setup */
/* IODC_LED_MATRIX_REFRESH has to be set to  IODC_LED_MATRIX_TASK_REFRESH          */
/* or IODC_PORT_SETUP_PERIODIC_REFRESH has to be defined                           */
/*---------------------------------------------------------------------------------*/
#define IODC_TASK_CALLING_PERIOD  DELAY_10MS /* in ms */
#define IODC_TASK_CALLING_DELAY   DELAY_20MS /* in ms */

/*************** Define it for LED Diagnostic Purpose ******************************/
/* #define IODC_LED_MATRIX_DIAG            */


#ifdef IODC_LED_MATRIX_DIAG
#define IODC_ApplCheckLed(x)
#endif


/*----------------------------------------------------------------------------*/
/* TIMERS : Selection pins for the timers and their channels                  */
/*----------------------------------------------------------------------------*/

/* Timer 0, channel 1 */
/* #define IODC_INPUT_TP01_IS_P61 */
/* #define IODC_INPUT_TP01_IS_P101 */

/* Timer 2, channel 1 */
/* #define IODC_INPUT_TP21_IS_P66 */
/* #define IODC_INPUT_TP21_IS_P103 */

/*----------------------------------------------------------------------------*/
/* Direct input configuration                                                 */
/*----------------------------------------------------------------------------*/

/*******************************************************************/
/* Template, replace x by the application pin name or by a number  */
/*******************************************************************/
#define IODC_DirectIn_Port_x           /* port name (see IODD)          */
#define IODC_DirectIn_Bit_x            /* bit number (see IODD)         */
#define IODC_DirectIn_Logic_x          /* IODC_POSITIVE, IODC_NEGATIVE  */
#define IODC_DirectIn_Irq_x            /* processor dependent :         */
                                       /*                               */
                                       /* NEC V850 Fx3 :                */
                                       /* IODD_STANDARD                 */
                                       /* IODD_IT_RISING_EDGE           */
                                       /* IODD_IT_FALLING_EDGE          */
                                       /* IODD_IT_BOTH_EDGE             */
                                       /*                               */
                                       /* Motorola STAR12 :             */
                                       /* IODD_STANDARD                 */
                                       /* IODD_IT_RISING_EDGE           */
                                       /* IODD_IT_FALLING_EDGE          */
                                       /*                               */
                                       /* Motorola S08 :                */
                                       /* IODD_STANDARD                 */
                                       /* IODD_IT_RISING_EDGE           */
                                       /* IODD_IT_FALLING_EDGE          */
                                       /* IODD_IT_LOW_LEVEL             */
                                       /* IODD_IT_HIGH_LEVEL            */
                                       /*                               */
                                       /* NEC V850 Dx3, REL V850 Dx4 :  */
                                       /* IODD_STANDARD                 */
                                       /* IODD_IT_RISING_EDGE           */
                                       /* IODD_IT_FALLING_EDGE          */
                                       /* IODD_IT_BOTH_EDGE             */
                                       /* IODD_IT_LOW_LEVEL             */
                                       /* IODD_IT_HIGH_LEVEL            */
                                       /*                               */
                                       /* Toshiba TX49 :                */
                                       /* IODD_STANDARD                 */
                                       /* IODD_IT_RISING_EDGE           */
                                       /* IODD_IT_FALLING_EDGE          */
                                       /* IODD_IT_HIGH_EDGE             */
                                       /* IODD_IT_LOW_LEVEL             */
                                       /*                               */
                                       /* Freescale IMX 53 :            */
                                       /* IODD_STANDARD                 */
                                       /* IODD_IT_RISING_EDGE           */
                                       /* IODD_IT_FALLING_EDGE          */
                                       /* IODD_IT_BOTH_EDGE             */
                                       /* IODD_IT_LOW_LEVEL             */
                                       /* IODD_IT_HIGH_LEVEL            */
                                       /*                               */
                                       /* CY TV2 :                      */
                                       /* IODD_IT_DISABLE               */
                                       /* IODD_IT_RISING_EDGE           */
                                       /* IODD_IT_FALLING_EDGE          */
                                       /* IODD_IT_BOTH_EDGE             */

#define IODC_DirectIn_PullUp_x         /* processor dependent :         */
                                       /*                               */
                                       /* NEC V850 Fx3, REL V850 Dx4 :  */
                                       /* IODD_NO_PULL_UP,              */
                                       /* IODD_PULL_UP                  */
                                       /*                               */
                                       /* Motorola STAR12 :             */
                                       /* IODD_NO_PULL_UP,              */
                                       /* IODD_PULL_UP,                 */
                                       /* IODD_PULL_DOWN                */
                                       /*                               */
                                       /* NEC V850 Dx3 :                */
                                       /* IODD_NO_PULL_UP               */
                                       /* IODD_SCHMITT_03_07Vdd,        */
                                       /* IODD_SCHMITT_04_08Vdd,        */
                                       /* IODD_CMOS_03_07Vdd,           */
                                       /* IODD_CMOS_04_08Vdd            */
                                       /*                               */
                                       /* NEC V850 Dx3 :                */
                                       /* IODD_NO_PULL_UP,              */
                                       /* IODD_SCHMITT_03_07Vdd,        */
                                       /* IODD_SCHMITT_04_08Vdd,        */
                                       /* IODD_CMOS_03_07Vdd,           */
                                       /* IODD_CMOS_04_08Vdd            */
                                       /*                               */
                                       /* TX49 : _NOT_USED_             */
                                       /*                               */
                                       /* IMX 53 : _NOT_USED_           */
                                       /*                               */
                                       /* CY TV2 :                             */
                                       /* IODD_PULL_UP,                        */
                                       /* IODD_NO_PULL_UP                      */
                                       /* IODD_PULL_DOWN,                      */
                                       /* IODD_PULL_UP_DOWN                    */
                                       /* IODD_PULL_UP_WITH_INPUT_BUFFER,      */
                                       /* IODD_PULL_DOWN_WITH_INPUT_BUFFER,    */
                                       /* IODD_PULL_UP_DOWN_WITH_INPUT_BUFFER  */

#define IODC_DirectIn_Ref_x            /* number from 0 to ..., used in */
                                       /* to identify pin in frame      */
                                       /* set only checked pin in EOL   */
#ifdef __DEVM_TEST__ /* TVII-C-2D-6M-500-BGA-CPU-BOARD TEST*/
#define IODC_DirectIn_Port_BUTTON_UP         2
#define IODC_DirectIn_Bit_BUTTON_UP          1
#define IODC_DirectIn_Logic_BUTTON_UP        IODC_NEGATIVE
#define IODC_DirectIn_Irq_BUTTON_UP          IODD_IT_FALLING_EDGE
#define IODC_DirectIn_PullUp_BUTTON_UP       IODD_NO_PULL_UP
#define IODC_DirectIn_Ref_BUTTON_UP

#define IODC_DirectIn_Port_BUTTON_DOWN       2
#define IODC_DirectIn_Bit_BUTTON_DOWN        2
#define IODC_DirectIn_Logic_BUTTON_DOWN      IODC_NEGATIVE
#define IODC_DirectIn_Irq_BUTTON_DOWN        IODD_IT_FALLING_EDGE
#define IODC_DirectIn_PullUp_BUTTON_DOWN     IODD_NO_PULL_UP
#define IODC_DirectIn_Ref_BUTTON_DOWN

#define IODC_DirectIn_Port_BUTTON_LEFT       15
#define IODC_DirectIn_Bit_BUTTON_LEFT        3
#define IODC_DirectIn_Logic_BUTTON_LEFT      IODC_NEGATIVE
#define IODC_DirectIn_Irq_BUTTON_LEFT        IODD_IT_FALLING_EDGE
#define IODC_DirectIn_PullUp_BUTTON_LEFT     IODD_NO_PULL_UP
#define IODC_DirectIn_Ref_BUTTON_LEFT

#define IODC_DirectIn_Port_BUTTON_RIGHT      15
#define IODC_DirectIn_Bit_BUTTON_RIGHT       4
#define IODC_DirectIn_Logic_BUTTON_RIGHT     IODC_NEGATIVE
#define IODC_DirectIn_Irq_BUTTON_RIGHT       IODD_IT_FALLING_EDGE
#define IODC_DirectIn_PullUp_BUTTON_RIGHT    IODD_NO_PULL_UP
#define IODC_DirectIn_Ref_BUTTON_RIGHT

#endif /*__DEVM_TEST__*/

/*----------------------------------------------------------------------------*/
/* Direct input without setup, only to read port register                     */
/*----------------------------------------------------------------------------*/
#define IODC_DirectIn_Port_x           /* see Direct input configuration      */
#define IODC_DirectIn_Bit_x            /* see Direct input configuration      */
#define IODC_DirectIn_Logic_x          /* see Direct input configuration      */
#define IODC_DirectIn_Irq_x            /* see Direct input configuration      */
#define IODC_DirectIn_PullUp_x         /* see Direct input configuration      */
#define IODC_DirectIn_Ref_x            /* not useful */

#ifdef __NEC_V850__
#define IODC_DirectIn_Port_EOL_TEST_PIN                       0
#define IODC_DirectIn_Bit_EOL_TEST_PIN                        3
#define IODC_DirectIn_Logic_EOL_TEST_PIN                      IODC_POSITIVE
#define IODC_DirectIn_Irq_EOL_TEST_PIN                        IODD_IT_RISING_EDGE
#define IODC_DirectIn_PullUp_EOL_TEST_PIN                     IODD_PULL_UP
#define IODC_DirectIn_Ref_EOL_TEST_PIN                        /* not useful */
#endif /*  #ifdef __NEC_V850__ */


/*----------------------------------------------------------------------------*/
/* Direct input use to set pin for sleep current reducing                     */
/* (in running can be used in an other mode)                                  */
/*----------------------------------------------------------------------------*/
#define IODC_DirectIn_Port_x           /* see Direct input configuration      */
#define IODC_DirectIn_Bit_x            /* see Direct input configuration      */
#define IODC_DirectIn_Logic_x          /* see Direct input configuration      */
#define IODC_DirectIn_Irq_x            /* not set as an input, only to read port register */
#define IODC_DirectIn_PullUp_x         /* not set as an input, only to read port register */
#define IODC_DirectIn_Ref_x            /* not set as an input, only to read port register */


/*----------------------------------------------------------------------------*/
/* Direct output configuration                                                */
/*----------------------------------------------------------------------------*/
/*PORT 0 */
/*P0.0				*/
/*P0.1				*/
/*P0.2	CAN0_1_TX	OUT	CAN1_TX	CAN_TX intput for CAN trancever */
/*P0.3	CAN0_1_RX	IN	CAN1_RX	CAN_RX output for CAN trancever */

/*PORT 1 */
#define IODC_Out_Type_CAN2_STB                  IODC_NORMAL
#define IODC_Out_Port_CAN2_STB                  1
#define IODC_Out_Bit_CAN2_STB                   0
#define IODC_Out_Logic_CAN2_STB                 IODC_POSITIVE
#define IODC_Out_Drain_CAN2_STB                 IODD_STRONG_DRIVE_OUTPUT
#define IODC_Out_PinRef_CAN2_STB

/*P1.1	PWM_11	OUT	AUDIO_DAC_PWM	PWM input for DAC analog channel for function safty */

/*PORT 2 */
/*P2.0	JTAG		SWD_JTAG_TRST	JTAG INTERFACE*/
/*P2.1	GPIO	OUT		*/
/*P2.2	GPIO	OUT		*/
/*P2.3	GPIO	OUT		*/

#define IODC_Out_Type_SPK_DIAG_EN               IODC_NORMAL
#define IODC_Out_Port_SPK_DIAG_EN               2
#define IODC_Out_Bit_SPK_DIAG_EN                4
#define IODC_Out_Logic_SPK_DIAG_EN              IODC_POSITIVE
#define IODC_Out_Drain_SPK_DIAG_EN              IODD_STRONG_DRIVE_OUTPUT
#define IODC_Out_PinRef_SPK_DIAG_EN

/*PORT 3 */
#define IODC_DirectIn_Port_SPEAKER_DIAG_IN      3
#define IODC_DirectIn_Bit_SPEAKER_DIAG_IN       0
#define IODC_DirectIn_Logic_SPEAKER_DIAG_IN     IODC_POSITIVE
#define IODC_DirectIn_Irq_SPEAKER_DIAG_IN       IODD_IT_DISABLE
#define IODC_DirectIn_PullUp_SPEAKER_DIAG_IN    IODD_NO_PULL_UP
#define IODC_DirectIn_Ref_SPEAKER_DIAG_IN

#define IODC_DirectIn_Port_LCD_CON_FAIL         3
#define IODC_DirectIn_Bit_LCD_CON_FAIL          1
#define IODC_DirectIn_Logic_LCD_CON_FAIL        IODC_POSITIVE
#define IODC_DirectIn_Irq_LCD_CON_FAIL          IODD_IT_DISABLE
#define IODC_DirectIn_PullUp_LCD_CON_FAIL       IODD_NO_PULL_UP
#define IODC_DirectIn_Ref_LCD_CON_FAIL

/*P3.2	TC_0_TR1	IN	"BK_CON_FAIL"	"Backlight control signal fail detect
PWM counter trriger input for MCU"*/

#define IODC_DirectIn_Port_BK_CON_FAIL          3
#define IODC_DirectIn_Bit_BK_CON_FAIL           3
#define IODC_DirectIn_Logic_BK_CON_FAIL         IODC_POSITIVE
#define IODC_DirectIn_Irq_BK_CON_FAIL           IODD_IT_DISABLE
#define IODC_DirectIn_PullUp_BK_CON_FAIL        IODD_NO_PULL_UP
#define IODC_DirectIn_Ref_BK_CON_FAIL

/*P3.4	GPIO	OUT		*/

/*PORT 4 */
/*P4.0	GPIO	OUT		*/
/*P4.1	GPIO	OUT		*/

/*PORT 5 */
/*
#define IODC_DirectIn_Port_GPU_5V_PWRGD         5
#define IODC_DirectIn_Bit_GPU_5V_PWRGD          0
#define IODC_DirectIn_Logic_GPU_5V_PWRGD        IODC_POSITIVE
#define IODC_DirectIn_Irq_GPU_5V_PWRGD          IODD_IT_DISABLE
#define IODC_DirectIn_PullUp_GPU_5V_PWRGD       IODD_NO_PULL_UP
#define IODC_DirectIn_Ref_GPU_5V_PWRGD
*/
/*PORT5.0*/

#define IODC_DirectIn_Port_GPU_3V3_PWRGD        5
#define IODC_DirectIn_Bit_GPU_3V3_PWRGD         1
#define IODC_DirectIn_Logic_GPU_3V3_PWRGD       IODC_POSITIVE
#define IODC_DirectIn_Irq_GPU_3V3_PWRGD         IODD_IT_DISABLE
#define IODC_DirectIn_PullUp_GPU_3V3_PWRGD      IODD_NO_PULL_UP
#define IODC_DirectIn_Ref_GPU_3V3_PWRGD

#define IODC_DirectIn_Port_GPU_PMIC_PWRGD       5
#define IODC_DirectIn_Bit_GPU_PMIC_PWRGD        2
#define IODC_DirectIn_Logic_GPU_PMIC_PWRGD      IODC_POSITIVE
#define IODC_DirectIn_Irq_GPU_PMIC_PWRGD        IODD_IT_DISABLE
#define IODC_DirectIn_PullUp_GPU_PMIC_PWRGD     IODD_NO_PULL_UP
#define IODC_DirectIn_Ref_GPU_PMIC_PWRGD

/*
#define IODC_DirectIn_Port_VTT_PWRGD       5
#define IODC_DirectIn_Bit_VTT_PWRGD        3
#define IODC_DirectIn_Logic_VTT_PWRGD      IODC_POSITIVE
#define IODC_DirectIn_Irq_VTT_PWRGD        IODD_IT_DISABLE
#define IODC_DirectIn_PullUp_VTT_PWRGD     IODD_NO_PULL_UP
#define IODC_DirectIn_Ref_VTT_PWRGD
*/

#define IODC_Out_Type_WDG_SET1             IODC_NORMAL
#define IODC_Out_Port_WDG_SET1             5
#define IODC_Out_Bit_WDG_SET1              4
#define IODC_Out_Logic_WDG_SET1            IODC_POSITIVE
#define IODC_Out_Drain_WDG_SET1            IODD_STRONG_DRIVE_OUTPUT
#define IODC_Out_PinRef_WDG_SET1

/*PORT 6*/
/*P6.0	SCB4_MISO	IN	MCU_ADUIO_SPI_IN	SPI MISO for AUDIO driver*/
/*P6.1	SCB4_MOSI	OUT	MCU_ADUIO_SPI_OUT	SPI MOSI for AUDIO driver*/
/*P6.2	SCB4_CLK	OUT	MCU_ADUIO_SPI_CLK	SPI CLK for AUDIO driver*/

#define IODC_Out_Type_MCU_AUDIO_SPI_CS          IODC_NORMAL
#define IODC_Out_Port_MCU_AUDIO_SPI_CS          6
#define IODC_Out_Bit_MCU_AUDIO_SPI_CS           3
#define IODC_Out_Logic_MCU_AUDIO_SPI_CS         IODC_NEGATIVE
#define IODC_Out_Drain_MCU_AUDIO_SPI_CS         IODD_STRONG_DRIVE_OUTPUT
#define IODC_Out_PinRef_MCU_AUDIO_SPI_CS

#define IODC_DirectIn_Port_MCU_SAFE_INT1        6
#define IODC_DirectIn_Bit_MCU_SAFE_INT1         4
#define IODC_DirectIn_Logic_MCU_SAFE_INT1       IODC_POSITIVE
#define IODC_DirectIn_Irq_MCU_SAFE_INT1         IODD_IT_DISABLE
#define IODC_DirectIn_PullUp_MCU_SAFE_INT1      IODD_NO_PULL_UP
#define IODC_DirectIn_Ref_MCU_SAFE_INT1

#define IODC_DirectIn_Port_RESERVED_SAFE_INT0        6
#define IODC_DirectIn_Bit_RESERVED_SAFE_INT0         5
#define IODC_DirectIn_Logic_RESERVED_SAFE_INT0       IODC_POSITIVE
#define IODC_DirectIn_Irq_RESERVED_SAFE_INT0         IODD_IT_DISABLE
#define IODC_DirectIn_PullUp_RESERVED_SAFE_INT0      IODD_NO_PULL_UP
#define IODC_DirectIn_Ref_RESERVED_SAFE_INT0

#define IODC_DirectIn_Port_RESERVED_SAFE_INT1        6
#define IODC_DirectIn_Bit_RESERVED_SAFE_INT1         6
#define IODC_DirectIn_Logic_RESERVED_SAFE_INT1       IODC_POSITIVE
#define IODC_DirectIn_Irq_RESERVED_SAFE_INT1         IODD_IT_DISABLE
#define IODC_DirectIn_PullUp_RESERVED_SAFE_INT1      IODD_NO_PULL_UP
#define IODC_DirectIn_Ref_RESERVED_SAFE_INT1

#define IODC_DirectIn_Port_MCU_SAFE_INT0        6
#define IODC_DirectIn_Bit_MCU_SAFE_INT0         7
#define IODC_DirectIn_Logic_MCU_SAFE_INT0       IODC_POSITIVE
#define IODC_DirectIn_Irq_MCU_SAFE_INT0         IODD_IT_DISABLE
#define IODC_DirectIn_PullUp_MCU_SAFE_INT0      IODD_NO_PULL_UP
#define IODC_DirectIn_Ref_MCU_SAFE_INT0

/*PORT 7*/
/*P7.0	SCB5_MISO	IN	MCU_IMC_MISO	IMC link MISO*/
/*P7.1	SCB5_MOSI	OUT	MCU_IMC_MOSI	IMC link MOSI*/
/*P7.2	SCB5_CLK	OUT	MCU_IMC_CLK	IMC link CLK*/

/*MCU_IMC_RDY*/
#define IODC_DirectIn_Port_MCU_IMC_RDY            7
#define IODC_DirectIn_Bit_MCU_IMC_RDY             3
#define IODC_DirectIn_Logic_MCU_IMC_RDY           IODC_POSITIVE
#define IODC_DirectIn_Irq_MCU_IMC_RDY             IODD_IT_RISING_EDGE
#define IODC_DirectIn_PullUp_MCU_IMC_RDY          IODD_NO_PULL_UP
#define IODC_DirectIn_Ref_MCU_IMC_RDY

/*P7.4	GPIO	IN	MCU_IMC_SYNC	IMC link SYNC*/

#define IODC_DirectIn_Port_MCU_IMC_D0           7
#define IODC_DirectIn_Bit_MCU_IMC_D0            5
#define IODC_DirectIn_Logic_MCU_IMC_D0          IODC_POSITIVE
#define IODC_DirectIn_Irq_MCU_IMC_D0            IODD_IT_DISABLE
#define IODC_DirectIn_PullUp_MCU_IMC_D0         IODD_NO_PULL_UP
#define IODC_DirectIn_Ref_MCU_IMC_D0

#define IODC_DirectIn_Port_MCU_IMC_D1           7
#define IODC_DirectIn_Bit_MCU_IMC_D1            6
#define IODC_DirectIn_Logic_MCU_IMC_D1          IODC_POSITIVE
#define IODC_DirectIn_Irq_MCU_IMC_D1            IODD_IT_DISABLE
#define IODC_DirectIn_PullUp_MCU_IMC_D1         IODD_NO_PULL_UP
#define IODC_DirectIn_Ref_MCU_IMC_D1

#define IODC_DirectIn_Port_MCU_IMC_D2           7
#define IODC_DirectIn_Bit_MCU_IMC_D2            7
#define IODC_DirectIn_Logic_MCU_IMC_D2          IODC_POSITIVE
#define IODC_DirectIn_Irq_MCU_IMC_D2            IODD_IT_DISABLE
#define IODC_DirectIn_PullUp_MCU_IMC_D2         IODD_NO_PULL_UP
#define IODC_DirectIn_Ref_MCU_IMC_D2

/*PORT 8 */
#define IODC_Out_Type_MCU_AUDIO_DAC_RST         IODC_NORMAL
#define IODC_Out_Port_MCU_AUDIO_DAC_RST         8
#define IODC_Out_Bit_MCU_AUDIO_DAC_RST          0
#define IODC_Out_Logic_MCU_AUDIO_DAC_RST        IODC_POSITIVE
#define IODC_Out_Drain_MCU_AUDIO_DAC_RST        IODD_STRONG_DRIVE_OUTPUT
#define IODC_Out_PinRef_MCU_AUDIO_DAC_RST

#define IODC_Out_Type_MCU_TO_GPU_RST            IODC_NORMAL
#define IODC_Out_Port_MCU_TO_GPU_RST            8
#define IODC_Out_Bit_MCU_TO_GPU_RST             1
#define IODC_Out_Logic_MCU_TO_GPU_RST           IODC_NEGATIVE
#define IODC_Out_Drain_MCU_TO_GPU_RST           IODD_STRONG_DRIVE_OUTPUT
#define IODC_Out_PinRef_MCU_TO_GPU_RST

#define IODC_DirectIn_Port_FAIL_T               8
#define IODC_DirectIn_Bit_FAIL_T                2
#define IODC_DirectIn_Logic_FAIL_T              IODC_POSITIVE
#define IODC_DirectIn_Irq_FAIL_T                IODD_IT_DISABLE
#define IODC_DirectIn_PullUp_FAIL_T             IODD_NO_PULL_UP
#define IODC_DirectIn_Ref_FAIL_T

/*PORT 12*/
#define IODC_Out_Type_FUEL_MES_CMD              IODC_NORMAL
#define IODC_Out_Port_FUEL_MES_CMD              12
#define IODC_Out_Bit_FUEL_MES_CMD               0
#define IODC_Out_Logic_FUEL_MES_CMD             IODC_NEGATIVE
#define IODC_Out_Drain_FUEL_MES_CMD             IODD_STRONG_DRIVE_OUTPUT
#define IODC_Out_PinRef_FUEL_MES_CMD

/*P12.1	ADC[1]_5	IN	MAIN_FUEL_IN	MAIN FUEL analog input*/
/*P12.2	ADC[1]_6	IN	SUB_FUEL_IN	SUB FUEL analog input*/
/*P12.3	ADC[1]_7	IN	SWITCH_ANA_IN	"wheel switch1 analog input
Theoretical ADC VALUE Vadc=Rswitch/(Rswitch+500ohm)*1024
The relationship between Rswitch and Button position detail see system requirement file"*/
/*P12.4	ADC[1]_8	IN	TFT_TEMP	TFT BL  NTC  temp detect inpuot*/
/*P12.5	ADC[1]_9	IN	BAT_ADC	Battery voltage ADC input*/

/*PORT 13*/
/*P13.0	SCB3_RX	IN	UART1_RX	UART1DEBUG INTERFACE RX*/
/*P13.1	SCB3_TX	OUT	UART1_TX	UART1DEBUG INTERFACE TX*/
/*P13.2	ADC[1]_14	IN	PCB_TEMP_IN	PCB NTC  temp detect inpuot*/
/*P13.3	ADC[1]_15	IN	SPEAKER_A2D	DAC driver output to  ADC port  detect*/

#define IODC_DirectIn_Port_MCU_HW2              13
#define IODC_DirectIn_Bit_MCU_HW2               4
#define IODC_DirectIn_Logic_MCU_HW2             IODC_POSITIVE
#define IODC_DirectIn_Irq_MCU_HW2               IODD_IT_DISABLE
#define IODC_DirectIn_PullUp_MCU_HW2            IODD_NO_PULL_UP
#define IODC_DirectIn_Ref_MCU_HW2

#define IODC_DirectIn_Port_MCU_HW0              13
#define IODC_DirectIn_Bit_MCU_HW0               5
#define IODC_DirectIn_Logic_MCU_HW0             IODC_POSITIVE
#define IODC_DirectIn_Irq_MCU_HW0               IODD_IT_DISABLE
#define IODC_DirectIn_PullUp_MCU_HW0            IODD_NO_PULL_UP
#define IODC_DirectIn_Ref_MCU_HW0

#define IODC_DirectIn_Port_MCU_HW1              13
#define IODC_DirectIn_Bit_MCU_HW1               6
#define IODC_DirectIn_Logic_MCU_HW1             IODC_POSITIVE
#define IODC_DirectIn_Irq_MCU_HW1               IODD_IT_DISABLE
#define IODC_DirectIn_PullUp_MCU_HW1            IODD_NO_PULL_UP
#define IODC_DirectIn_Ref_MCU_HW1

/*P13.7	ADC[1]_19	IN	MCU_3V3	Analog input for MCU3V3 power supply*/

/*PORT 14*/
/*P14.0	GPIO	OUT		*/
/*P14.1	GPIO	OUT		*/

#define IODC_Out_Type_HSCAN_EN             IODC_NORMAL
#define IODC_Out_Port_HSCAN_EN             14
#define IODC_Out_Bit_HSCAN_EN              2
#define IODC_Out_Logic_HSCAN_EN            IODC_POSITIVE
#define IODC_Out_Drain_HSCAN_EN            IODD_STRONG_DRIVE_OUTPUT
#define IODC_Out_PinRef_HSCAN_EN

/*P14.3	CAN_STB"*/
#define IODC_Out_Type_HSCAN_STB                 IODC_NORMAL
#define IODC_Out_Port_HSCAN_STB                 14
#define IODC_Out_Bit_HSCAN_STB                  3
#define IODC_Out_Logic_HSCAN_STB                IODC_POSITIVE
#define IODC_Out_Drain_HSCAN_STB                IODD_STRONG_DRIVE_OUTPUT
#define IODC_Out_PinRef_HSCAN_STB


#define IODC_Out_Type_NSHUTDOWN                  IODC_NORMAL
#define IODC_Out_Port_NSHUTDOWN                  14
#define IODC_Out_Bit_NSHUTDOWN                   4
#define IODC_Out_Logic_NSHUTDOWN                 IODC_POSITIVE
#define IODC_Out_Drain_NSHUTDOWN                 IODD_STRONG_DRIVE_OUTPUT
#define IODC_Out_PinRef_NSHUTDOWN

#define IODC_Out_Type_KL30_CMD                  IODC_NORMAL
#define IODC_Out_Port_KL30_CMD                  14
#define IODC_Out_Bit_KL30_CMD                   5
#define IODC_Out_Logic_KL30_CMD                 IODC_POSITIVE
#define IODC_Out_Drain_KL30_CMD                 IODD_STRONG_DRIVE_OUTPUT
#define IODC_Out_PinRef_KL30_CMD

/*PORT 15*/
#define IODC_Out_Type_GPU_5V_EN                 IODC_NORMAL
#define IODC_Out_Port_GPU_5V_EN                 15
#define IODC_Out_Bit_GPU_5V_EN                  0
#define IODC_Out_Logic_GPU_5V_EN                IODC_POSITIVE
#define IODC_Out_Drain_GPU_5V_EN                IODD_STRONG_DRIVE_OUTPUT
#define IODC_Out_PinRef_GPU_5V_EN

#define IODC_Out_Type_GPU_3V3_EN                IODC_NORMAL
#define IODC_Out_Port_GPU_3V3_EN                15
#define IODC_Out_Bit_GPU_3V3_EN                 1
#define IODC_Out_Logic_GPU_3V3_EN               IODC_POSITIVE
#define IODC_Out_Drain_GPU_3V3_EN               IODD_STRONG_DRIVE_OUTPUT
#define IODC_Out_PinRef_GPU_3V3_EN

#define IODC_Out_Type_PMIC_ON2                  IODC_NORMAL
#define IODC_Out_Port_PMIC_ON2                  15
#define IODC_Out_Bit_PMIC_ON2                   2
#define IODC_Out_Logic_PMIC_ON2                 IODC_POSITIVE
#define IODC_Out_Drain_PMIC_ON2                 IODD_STRONG_DRIVE_OUTPUT
#define IODC_Out_PinRef_PMIC_ON2

#define IODC_Out_Type_MCU_3V3_EN                IODC_NORMAL
#define IODC_Out_Port_MCU_3V3_EN                15
#define IODC_Out_Bit_MCU_3V3_EN                 3
#define IODC_Out_Logic_MCU_3V3_EN               IODC_POSITIVE
#define IODC_Out_Drain_MCU_3V3_EN               IODD_STRONG_DRIVE_OUTPUT
#define IODC_Out_PinRef_MCU_3V3_EN

/*PORT 16*/
#define IODC_DirectIn_Port_LOW_PRESSURE_IN      16
#define IODC_DirectIn_Bit_LOW_PRESSURE_IN       0
#define IODC_DirectIn_Logic_LOW_PRESSURE_IN     IODC_NEGATIVE
#define IODC_DirectIn_Irq_LOW_PRESSURE_IN       IODD_IT_DISABLE
#define IODC_DirectIn_PullUp_LOW_PRESSURE_IN    IODD_NO_PULL_UP
#define IODC_DirectIn_Ref_LOW_PRESSURE_IN

#define IODC_DirectIn_Port_BT_CHARGE_IN         16
#define IODC_DirectIn_Bit_BT_CHARGE_IN          1
#define IODC_DirectIn_Logic_BT_CHARGE_IN        IODC_NEGATIVE
#define IODC_DirectIn_Irq_BT_CHARGE_IN          IODD_IT_DISABLE
#define IODC_DirectIn_PullUp_BT_CHARGE_IN       IODD_NO_PULL_UP
#define IODC_DirectIn_Ref_BT_CHARGE_IN

#define IODC_DirectIn_Port_MCU_ANTI_THEFT       16
#define IODC_DirectIn_Bit_MCU_ANTI_THEFT        2
#define IODC_DirectIn_Logic_MCU_ANTI_THEFT      IODC_NEGATIVE
#define IODC_DirectIn_Irq_MCU_ANTI_THEFT        IODD_IT_DISABLE
#define IODC_DirectIn_PullUp_MCU_ANTI_THEFT     IODD_NO_PULL_UP
#define IODC_DirectIn_Ref_MCU_ANTI_THEFT

/*PORT 17*/
#define IODC_DirectIn_Port_BRAKE_F_IN           17
#define IODC_DirectIn_Bit_BRAKE_F_IN            0
#define IODC_DirectIn_Logic_BRAKE_F_IN          IODC_NEGATIVE
#define IODC_DirectIn_Irq_BRAKE_F_IN            IODD_IT_DISABLE
#define IODC_DirectIn_PullUp_BRAKE_F_IN         IODD_NO_PULL_UP
#define IODC_DirectIn_Ref_BRAKE_F_IN

#define IODC_DirectIn_Port_DIGITAL1_IN          17
#define IODC_DirectIn_Bit_DIGITAL1_IN           1
#define IODC_DirectIn_Logic_DIGITAL1_IN         IODC_NEGATIVE
#define IODC_DirectIn_Irq_DIGITAL1_IN           IODD_IT_DISABLE
#define IODC_DirectIn_PullUp_DIGITAL1_IN        IODD_NO_PULL_UP
#define IODC_DirectIn_Ref_DIGITAL1_IN

#define IODC_DirectIn_Port_DIGITAL2_IN          17
#define IODC_DirectIn_Bit_DIGITAL2_IN           2
#define IODC_DirectIn_Logic_DIGITAL2_IN         IODC_NEGATIVE
#define IODC_DirectIn_Irq_DIGITAL2_IN           IODD_IT_DISABLE
#define IODC_DirectIn_PullUp_DIGITAL2_IN        IODD_NO_PULL_UP
#define IODC_DirectIn_Ref_DIGITAL2_IN

#define IODC_DirectIn_Port_DIGITAL3_IN          17
#define IODC_DirectIn_Bit_DIGITAL3_IN           3
#define IODC_DirectIn_Logic_DIGITAL3_IN         IODC_NEGATIVE
#define IODC_DirectIn_Irq_DIGITAL3_IN           IODD_IT_DISABLE
#define IODC_DirectIn_PullUp_DIGITAL3_IN        IODD_NO_PULL_UP
#define IODC_DirectIn_Ref_DIGITAL3_IN

#define IODC_DirectIn_Port_DIGITAL4_IN          17
#define IODC_DirectIn_Bit_DIGITAL4_IN           4
#define IODC_DirectIn_Logic_DIGITAL4_IN         IODC_NEGATIVE
#define IODC_DirectIn_Irq_DIGITAL4_IN           IODD_IT_DISABLE
#define IODC_DirectIn_PullUp_DIGITAL4_IN        IODD_NO_PULL_UP
#define IODC_DirectIn_Ref_DIGITAL4_IN

/*PORT 18 */
/*P18.0	SCB1_MISO	IN	EEPROM_MISO	SPI_OUT for EEPROM*/
/*P18.1	SCB1_MOSI	OUT	EEPROM_MOSI	SPI_IN for EEPROM*/
/*P18.2	SCB1_CLK	OUT	EEPROM_CLK	SPI_CLK for EEPROM*/

#define IODC_Out_Type_EEPROM_CS                 IODC_NORMAL
#define IODC_Out_Port_EEPROM_CS                 18
#define IODC_Out_Bit_EEPROM_CS                  3
#define IODC_Out_Logic_EEPROM_CS                IODC_NEGATIVE
#define IODC_Out_Drain_EEPROM_CS                IODD_STRONG_DRIVE_OUTPUT
#define IODC_Out_PinRef_EEPROM_CS

/*P18.4	GPIO	OUT	*/
#define IODC_Out_Type_TESTPIN                 IODC_NORMAL
#define IODC_Out_Port_TESTPIN                 18
#define IODC_Out_Bit_TESTPIN                  4
#define IODC_Out_Logic_TESTPIN                IODC_POSITIVE
#define IODC_Out_Drain_TESTPIN                IODD_STRONG_DRIVE_OUTPUT
#define IODC_Out_PinRef_TESTPIN

#define IODC_DirectIn_Port_KL15_IN              18
#define IODC_DirectIn_Bit_KL15_IN               5
#define IODC_DirectIn_Logic_KL15_IN             IODC_POSITIVE
#define IODC_DirectIn_Irq_KL15_IN               IODD_IT_DISABLE
#define IODC_DirectIn_PullUp_KL15_IN            IODD_NO_PULL_UP
#define IODC_DirectIn_Ref_KL15_IN

/*P18.6	CAN1_2_TX	OUT	HSCAN_TX	CAN_TX*/
/*P18.7	CAN1_2_RX	IN	HSCAN_RX	CAN_RX*/


/*PORT19*/

/*
P19.1	SCB2_SDA	IN&OUT	RTC_SDA	I2C interface for External hw RTC
P19.2	SCB2_SCL	OUT	RTC_SCL	I2C interface for External hw RTC
P19.3	GPIO	OUT
/*P14.3	CAN_STB"*/
#define IODC_Out_Type_SPI_CS                 IODC_NORMAL
#define IODC_Out_Port_SPI_CS                 19
#define IODC_Out_Bit_SPI_CS                  3
#define IODC_Out_Logic_SPI_CS                IODC_POSITIVE
#define IODC_Out_Drain_SPI_CS                IODD_STRONG_DRIVE_OUTPUT
#define IODC_Out_PinRef_SPI_CS
/*P19.4	GPIO	OUT
*/


/*PORT20*/
/*
P20.0	GPIO	OUT
P20.1	GPIO	OUT
P20.2	GPIO	OUT
P20.3	GPIO	OUT
*/

/*PORT 21*/
/*
P21.0				WCO IN
P21.1				WCOUUT
P21.2				ECO IN
P21.3				ECOOUT
P21.5	GPIO	OUT
P21.6	GPIO	OUT
*/

/*PORT 22*/
/*
P22.0	GPIO	OUT
P22.1	GPIO	OUT
P22.2	GPIO	OUT
P22.3	GPIO	OUT
*/

#define IODC_Out_Type_BAT_MEAS                  IODC_NORMAL
#define IODC_Out_Port_BAT_MEAS                  22
#define IODC_Out_Bit_BAT_MEAS                   4
#define IODC_Out_Logic_BAT_MEAS                 IODC_POSITIVE
#define IODC_Out_Drain_BAT_MEAS                 IODD_STRONG_DRIVE_OUTPUT
#define IODC_Out_PinRef_BAT_MEAS

#define IODC_Out_Type_WHEEL_SWITCH_MES_CMD      IODC_NORMAL
#define IODC_Out_Port_WHEEL_SWITCH_MES_CMD      22
#define IODC_Out_Bit_WHEEL_SWITCH_MES_CMD       5
#define IODC_Out_Logic_WHEEL_SWITCH_MES_CMD     IODC_NEGATIVE
#define IODC_Out_Drain_WHEEL_SWITCH_MES_CMD     IODD_STRONG_DRIVE_OUTPUT
#define IODC_Out_PinRef_WHEEL_SWITCH_MES_CMD

#define IODC_Out_Type_TEMP_MES_CMD              IODC_NORMAL
#define IODC_Out_Port_TEMP_MES_CMD              22
#define IODC_Out_Bit_TEMP_MES_CMD               6
#define IODC_Out_Logic_TEMP_MES_CMD             IODC_NEGATIVE
#define IODC_Out_Drain_TEMP_MES_CMD             IODD_STRONG_DRIVE_OUTPUT
#define IODC_Out_PinRef_TEMP_MES_CMD

/*PORT 23*/
/*
P23.0	SCB7_RX	IN	UART2_RX	UART DEBUG INTERFACE RX
P23.1	SCB7_TX		UART2_TX	UART DEBUG INTERFACE TX
P23.3	FAULT_OUT_3		FAULT_OUT	MCU internal failure output detect
P23.4	SWJ_SWO_TDO		SWD_JTAG_TDO	JTAG INTERFACE
P23.5	SWJ_SWCLK_TCLK		SWD_JTAG_TCLK	JTAG INTERFACE
P23.6	SWJ_SWDIO_TMS		SWD_JTAG_TMS	JTAG INTERFACE
P23.7	SWJ_SWDOE_TDI		SWD_JTAG_TDI	JTAG INTERFACE
*/

void IODC_ConfigureHw(void);

/*---------------------------------------------------------*/
/* I/Os for virtual SPI channels                            */
/* DATAOUT_SPI_x                                            */
/* DATAIN_SPI_x                                             */
/* CLOCK_SPI_x                                              */
/*  with x = Channel number                                 */
/* Spic_CPOL_HIGH = Active-high / Idle-low                  */
/* Spic_CPOL_LOW  = Active-low  / Idle-high                 */
/*----------------------------------------------------------*/

#define IODC_Out_Type_DATAOUT_SPI_4   IODC_NORMAL
#define IODC_Out_Port_DATAOUT_SPI_4   0
#define IODC_Out_Bit_DATAOUT_SPI_4    0
#define IODC_Out_Logic_DATAOUT_SPI_4  IODC_POSITIVE
#define IODC_Out_Drain_DATAOUT_SPI_4  IODD_NO_HIGH_Z
#define IODC_Out_PinRef_DATAOUT_SPI_4 1

#define IODC_Out_Type_DATAOUT_SPI_5   IODC_NORMAL
#define IODC_Out_Port_DATAOUT_SPI_5   0
#define IODC_Out_Bit_DATAOUT_SPI_5    0
#define IODC_Out_Logic_DATAOUT_SPI_5  IODC_POSITIVE
#define IODC_Out_Drain_DATAOUT_SPI_5  IODD_NO_HIGH_Z
#define IODC_Out_PinRef_DATAOUT_SPI_5 2

#define IODC_Out_Type_DATAOUT_SPI_6   IODC_NORMAL
#define IODC_Out_Port_DATAOUT_SPI_6   0
#define IODC_Out_Bit_DATAOUT_SPI_6    0
#define IODC_Out_Logic_DATAOUT_SPI_6  IODC_POSITIVE
#define IODC_Out_Drain_DATAOUT_SPI_6  IODD_NO_HIGH_Z
#define IODC_Out_PinRef_DATAOUT_SPI_6 3

#define IODC_Out_Type_CLOCK_SPI_4     IODC_NORMAL
#define IODC_Out_Port_CLOCK_SPI_4     0
#define IODC_Out_Bit_CLOCK_SPI_4      0
#define IODC_Out_Logic_CLOCK_SPI_4    IODC_POSITIVE
#define IODC_Out_Drain_CLOCK_SPI_4    IODD_NO_HIGH_Z
#define IODC_Out_PinRef_CLOCK_SPI_4   4

#define IODC_Out_Type_CLOCK_SPI_5     IODC_NORMAL
#define IODC_Out_Port_CLOCK_SPI_5     0
#define IODC_Out_Bit_CLOCK_SPI_5      0
#define IODC_Out_Logic_CLOCK_SPI_5    IODC_POSITIVE
#define IODC_Out_Drain_CLOCK_SPI_5    IODD_NO_HIGH_Z
#define IODC_Out_PinRef_CLOCK_SPI_5   5

#define IODC_Out_Type_CLOCK_SPI_6     IODC_NORMAL
#define IODC_Out_Port_CLOCK_SPI_6     0
#define IODC_Out_Bit_CLOCK_SPI_6      0
#define IODC_Out_Logic_CLOCK_SPI_6    IODC_POSITIVE
#define IODC_Out_Drain_CLOCK_SPI_6    IODD_NO_HIGH_Z
#define IODC_Out_PinRef_CLOCK_SPI_6   6

#define IODC_Out_Type_SCK_I2C         IODC_NORMAL
#define IODC_Out_Port_SCK_I2C         0
#define IODC_Out_Bit_SCK_I2C          0
#define IODC_Out_Logic_SCK_I2C        IODC_POSITIVE
#define IODC_Out_Drain_SCK_I2C        IODD_NO_HIGH_Z
#define IODC_Out_PinRef_SCK_I2C       7

/*
#define IODC_Out_Type_CAN0_S   			IODC_NORMAL
#define IODC_Out_Port_CAN0_S   			19
#define IODC_Out_Bit_CAN0_S    			2
#define IODC_Out_Logic_CAN0_S  			IODC_POSITIVE
#define IODC_Out_Drain_CAN0_S  		    IODD_STRONG_DRIVE_OUTPUT
#define IODC_Out_PinRef_CAN0_S 		    0
*/
/* --- DIRECT LED --- */
/* start pin ref. for LED                                                */
/* CAUTION !!!! PinRef continues in LED (Dynamic or Multiplexed) section */


/* pins used in PLATFORM modules to define if used */

#define IODC_Out_Type_MATC_WRITE                   x
#define IODC_Out_Port_MATC_WRITE                   x
#define IODC_Out_Bit_MATC_WRITE                    x
#define IODC_Out_Logic_MATC_WRITE                  x
#define IODC_Out_Drain_MATC_WRITE                  x
#define IODC_Out_PinRef_MATC_WRITE                 x

#define IODC_Out_Type_MATC_READ                    x
#define IODC_Out_Port_MATC_READ                    x
#define IODC_Out_Bit_MATC_READ                     x
#define IODC_Out_Logic_MATC_READ                   x
#define IODC_Out_Drain_MATC_READ                   x
#define IODC_Out_PinRef_MATC_READ                  x

#define IODC_Out_Type_MATC_CONTROL                 x
#define IODC_Out_Port_MATC_CONTROL                 x
#define IODC_Out_Bit_MATC_CONTROL                  x
#define IODC_Out_Logic_MATC_CONTROL                x
#define IODC_Out_Drain_MATC_CONTROL                x
#define IODC_Out_PinRef_MATC_CONTROL               x

#define IODC_Out_Type_MATRIX_HARDWARE_RESET_PIN    x
#define IODC_Out_Port_MATRIX_HARDWARE_RESET_PIN    x
#define IODC_Out_Bit_MATRIX_HARDWARE_RESET_PIN     x
#define IODC_Out_Logic_MATRIX_HARDWARE_RESET_PIN   x
#define IODC_Out_Drain_MATRIX_HARDWARE_RESET_PIN   x
#define IODC_Out_PinRef_MATRIX_HARDWARE_RESET_PIN  x

#define IODC_Out_Type_CS_EEPROM                    x
#define IODC_Out_Port_CS_EEPROM                    x
#define IODC_Out_Bit_CS_EEPROM                     x
#define IODC_Out_Logic_CS_EEPROM                   x
#define IODC_Out_Drain_CS_EEPROM                   x
#define IODC_Out_PinRef_CS_EEPROM                  x

#define IODC_Out_Type_CS_PILAM                     x
#define IODC_Out_Port_CS_PILAM                     x
#define IODC_Out_Bit_CS_PILAM                      x
#define IODC_Out_Logic_CS_PILAM                    x
#define IODC_Out_Drain_CS_PILAM                    x
#define IODC_Out_PinRef_CS_PILAM                   x

#define IODC_Out_Type_TX_LCD                       x
#define IODC_Out_Port_TX_LCD                       x
#define IODC_Out_Bit_TX_LCD                        x
#define IODC_Out_Logic_TX_LCD                      x
#define IODC_Out_Drain_TX_LCD                      x
#define IODC_Out_PinRef_TX_LCD                     x

#define IODC_Out_Type_CLK_LCD                      x
#define IODC_Out_Port_CLK_LCD                      x
#define IODC_Out_Bit_CLK_LCD                       x
#define IODC_Out_Logic_CLK_LCD                     x
#define IODC_Out_Drain_CLK_LCD                     x
#define IODC_Out_PinRef_CLK_LCD                    x

#define IODC_Out_Type_M1_PIN                       x
#define IODC_Out_Port_M1_PIN                       x
#define IODC_Out_Bit_M1_PIN                        x
#define IODC_Out_Logic_M1_PIN                      x
#define IODC_Out_Drain_M1_PIN                      x
#define IODC_Out_PinRef_M1_PIN                     x


/*----------------------------------------------------------------------------*/
/* Direct output use to set pin for sleep current reducing                    */
/* (in running can be used in an other mode)                                  */
/*----------------------------------------------------------------------------*/
/* to define here */


/*----------------------------------------------------------*/
/* Direct output configuration for shift register strobe    */
/* use always the name SHIFTER                              */
/* - SCI channel to use                                     */
/* !!! WARNING !!! the SCI channel must be only used by the */
/*    shift register (no other device connected on it !).   */
/* - pin setup                                              */
/*----------------------------------------------------------*/

#define IODC_SHIFTER_SCI_CHANNEL  /* for spi managed in SPIC : */
                                  /* for all new processors    */
                                  /* see SPIC channel          */
                                  /* for spi managed in SCIC : */
                                  /* SCIC_0, SCIC_1, SCIC_0    */
                                  /* see SCIC channel          */

#define IODC_Out_Type_SHIFTER    x
#define IODC_Out_Port_SHIFTER    x
#define IODC_Out_Bit_SHIFTER     x
#define IODC_Out_Logic_SHIFTER   x
#define IODC_Out_Drain_SHIFTER   x
#define IODC_Out_PinRef_SHIFTER  x

/*----------------------------------------------------------------------------*/
/* Direct Output selectable, option-depending                                 */
/*----------------------------------------------------------------------------*/
/* change is taken into account after power-on reset */

/********************************************************************/
/* Template, remplace xx by the application pin name or by a number */
/********************************************************************/
/*#define IODC_Out_Type_xx    IODC_SEL_NORMAL                       */
/*#define IODC_Out_Option_xx  name of function to call to           */
/*                            enable /disable output                */
/*                            Must return :                         */
/*                              TRUE  : option enabled              */
/*                              FALSE : option disabled             */
/* Direct output configuration section                              */
/*#define IODC_Out_Port_xx    port name (see IODD)                  */
/*#define IODC_Out_Bit_xx     bit number (see IODD)                 */
/*#define IODC_Out_Logic_xx   IODC_POSITIVE, IODC_NEGATIVE          */
/*#define IODC_Out_Drain_xx   processor dependent :                 */
/*                            same option as direct output          */
/* common section                                                   */
/*#define IODC_Out_PinRef_xx  PROGRESSIVE OUTPUT NUMBER for all     */
/*                            direct output                         */
/*                            or                                    */
/*                            PROGRESSIVE LED NUMBER for all LED    */


/*----------------------------------------------------------------------------*/
/* ---- Led matrix ----                                                       */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Led matrix : Output with dynamic setup : Direct or Multiplexed             */
/*              dual command mechanism embedded                               */
/*----------------------------------------------------------------------------*/
/* change is taken into account after power-on reset */

/********************************************************************/
/* Template, remplace xx by the application pin name or by a number */
/********************************************************************/
/* common section */
/*#define IODC_Out_Type_xx    IODC_DYNAMIC                          */
/*#define IODC_Out_Logic_xx   IODC_POSITIVE, IODC_NEGATIVE          */
/*#define IODC_Out_Option_xx  name of function to call to           */
/*                            enable /disable output                */
/*                            Must return :                         */
/*                              TRUE  : option enabled              */
/*                              FALSE : option disabled             */
/*#define IODC_Out_Select_xx  name of function to call to select    */
/*                            HW output type                        */
/*                            Must return :                         */
/*                              TRUE  : Multiplexed output          */
/*                              FALSE : direct output               */
/*#define IODC_Out_Select_xx  name of function to call to select Hw */
/*                            output : Direct or Multiplexed        */
/*                            Must return :                         */
/*                              TRUE  : Multiplexed                 */
/*                              FALSE : Direct                      */
/* Direct output configuration section                              */
/*#define IODC_Out_Port_xx    port name (see IODD)                  */
/*#define IODC_Out_Bit_xx     bit number (see IODD)                 */
/*#define IODC_Out_Drain_xx   processor dependent :                 */
/* same option as direct output                                     */
/* Multiplexed output configuration section                         */
/*#define IODC_Out_Line_xx    line number where the led is located  */
/*#define IODC_Out_Column_xx  column number where the led is located*/
/*                            multiplexed output led                */
/* common section                                                   */
/*#define IODC_Out_PinRef_xx  PROGRESSIVE LED NUMBER for all LED    */
/*                            number from 0 to ..., used in         */
/*                            to identify pin in frame              */
/*                            set only checked pin in EOL           */

/* CAUTION !!!! PinRef starts in DIRECT LED section */


/*----------------------------------------------------------------------------*/
/* Led matrix : Selectable Output Multiplexed, option-depending               */
/*----------------------------------------------------------------------------*/
/* change is taken into account after power-on reset */

/********************************************************************/
/* Template, remplace xx by the application pin name or by a number */
/********************************************************************/
/* common section */
/*#define IODC_Out_Type_xx    IODC_SEL_BYMATRIX                     */
/*#define IODC_Out_Logic_xx   IODC_POSITIVE, IODC_NEGATIVE          */
/*#define IODC_Out_Option_xx  name of function to call to           */
/*                            enable /disable output                */
/*                            Must return :                         */
/*                              TRUE  : option enabled              */
/*                              FALSE : option disabled             */
/* Multiplexed output configuration section                         */
/*#define IODC_Out_Line_xx   line number where the led is located   */
/*#define IODC_Out_Column_xx column number where the led is located */
/* common section                                                   */
/*#define IODC_Out_PinRef_xx PROGRESSIVE LED NUMBER for all LED     */

/* CAUTION !!!! PinRef starts in DIRECT LED section */


/*----------------------------------------------------------------------------*/
/* Led matrix : Output with static setup : Multiplexed output configuration   */
/*----------------------------------------------------------------------------*/

/*******************************************************/
/* Template, remplace x by the led name or by a number */
/*******************************************************/
#define IODC_Out_Type_x    IODC_BYMATRIX
#define IODC_Out_Line_x    /* line number where the led is located   */
#define IODC_Out_Column_x  /* column number where the led is located */
#define IODC_Out_Logic_x   /* IODC_POSITIVE, IODC_NEGATIVE           */
#define IODC_Out_PinRef_x  /* PROGRESSIVE LED NUMBER for all LED     */
                           /* number from 0 to ..., used in         */
                           /* to identify pin in frame              */
                           /* set only checked pin in EOL           */

/* CAUTION !!!! PinRef starts in DIRECT LED section */


/*----------------------------------------------------------------------------*/
/* The following configuration is imposed when you used Leds BarGraph         */
/*----------------------------------------------------------------------------*/

/******************************************************************************/
/* Template for bargraph usage, replace x by the bargraph number              */
/*                              replace y by the led number                   */
/******************************************************************************/
#define IODC_Out_Type_BAR_GRAPH_x_y   IODC_BYMATRIX
#define IODC_Out_Line_BAR_GRAPH_x_y   /* line number where led is located     */
#define IODC_Out_Column_BAR_GRAPH_x_y /* column number where  led is located  */
#define IODC_Out_Logic_BAR_GRAPH_x_y  /* IODC_POSITIVE, IODC_NEGATIVE         */
#define IODC_Out_PinRef_BAR_GRAPH_x_y /* PROGRESSIVE LED NUMBER for all LED   */
                                      /* number from 0 to ..., used in        */
                                      /* to identify pin in frame             */
                                      /* set only checked pin in EOL          */


/* first bargraph example with 4 leds */
#define IODC_Out_Type_BAR_GRAPH_0_0         IODC_BYMATRIX
#define IODC_Out_Line_BAR_GRAPH_0_0         0
#define IODC_Out_Column_BAR_GRAPH_0_0       0
#define IODC_Out_Logic_BAR_GRAPH_0_0        IODC_POSITIVE
#define IODC_Out_PinRef_BAR_GRAPH_0_0       2

#define IODC_Out_Type_BAR_GRAPH_0_1         IODC_BYMATRIX
#define IODC_Out_Line_BAR_GRAPH_0_1         1
#define IODC_Out_Column_BAR_GRAPH_0_1       0
#define IODC_Out_Logic_BAR_GRAPH_0_1        IODC_POSITIVE
#define IODC_Out_PinRef_BAR_GRAPH_0_1       3

#define IODC_Out_Type_BAR_GRAPH_0_2         IODC_BYMATRIX
#define IODC_Out_Line_BAR_GRAPH_0_2         2
#define IODC_Out_Column_BAR_GRAPH_0_2       0
#define IODC_Out_Logic_BAR_GRAPH_0_2        IODC_POSITIVE
#define IODC_Out_PinRef_BAR_GRAPH_0_2       4

#define IODC_Out_Type_BAR_GRAPH_0_3         IODC_BYMATRIX
#define IODC_Out_Line_BAR_GRAPH_0_3         3
#define IODC_Out_Column_BAR_GRAPH_0_3       0
#define IODC_Out_Logic_BAR_GRAPH_0_3        IODC_POSITIVE
#define IODC_Out_PinRef_BAR_GRAPH_0_3       5

/* second bargraph example with 4 leds */
#define IODC_Out_Type_BAR_GRAPH_1_0         IODC_BYMATRIX
#define IODC_Out_Line_BAR_GRAPH_1_0         0
#define IODC_Out_Column_BAR_GRAPH_1_0       1
#define IODC_Out_Logic_BAR_GRAPH_1_0        IODC_POSITIVE
#define IODC_Out_PinRef_BAR_GRAPH_1_0       6

#define IODC_Out_Type_BAR_GRAPH_1_1         IODC_BYMATRIX
#define IODC_Out_Line_BAR_GRAPH_1_1         1
#define IODC_Out_Column_BAR_GRAPH_1_1       1
#define IODC_Out_Logic_BAR_GRAPH_1_1        IODC_POSITIVE
#define IODC_Out_PinRef_BAR_GRAPH_1_1       7

#define IODC_Out_Type_BAR_GRAPH_1_2         IODC_BYMATRIX
#define IODC_Out_Line_BAR_GRAPH_1_2         2
#define IODC_Out_Column_BAR_GRAPH_1_2       1
#define IODC_Out_Logic_BAR_GRAPH_1_2        IODC_POSITIVE
#define IODC_Out_PinRef_BAR_GRAPH_1_2       8

#define IODC_Out_Type_BAR_GRAPH_1_3         IODC_BYMATRIX
#define IODC_Out_Line_BAR_GRAPH_1_3         3
#define IODC_Out_Column_BAR_GRAPH_1_3       1
#define IODC_Out_Logic_BAR_GRAPH_1_3        IODC_POSITIVE
#define IODC_Out_PinRef_BAR_GRAPH_1_3       9

/* third bargraph example with 4 leds */
#define IODC_Out_Type_BAR_GRAPH_2_0         IODC_BYMATRIX
#define IODC_Out_Line_BAR_GRAPH_2_0         0
#define IODC_Out_Column_BAR_GRAPH_2_0       2
#define IODC_Out_Logic_BAR_GRAPH_2_0        IODC_POSITIVE
#define IODC_Out_PinRef_BAR_GRAPH_2_0       10

#define IODC_Out_Type_BAR_GRAPH_2_1         IODC_BYMATRIX
#define IODC_Out_Line_BAR_GRAPH_2_1         1
#define IODC_Out_Column_BAR_GRAPH_2_1       2
#define IODC_Out_Logic_BAR_GRAPH_2_1        IODC_POSITIVE
#define IODC_Out_PinRef_BAR_GRAPH_2_1       11

#define IODC_Out_Type_BAR_GRAPH_2_2         IODC_BYMATRIX
#define IODC_Out_Line_BAR_GRAPH_2_2         2
#define IODC_Out_Column_BAR_GRAPH_2_2       2
#define IODC_Out_Logic_BAR_GRAPH_2_2        IODC_POSITIVE
#define IODC_Out_PinRef_BAR_GRAPH_2_2       12

#define IODC_Out_Type_BAR_GRAPH_2_3         IODC_BYMATRIX
#define IODC_Out_Line_BAR_GRAPH_2_3         3
#define IODC_Out_Column_BAR_GRAPH_2_3       2
#define IODC_Out_Logic_BAR_GRAPH_2_3        IODC_POSITIVE
#define IODC_Out_PinRef_BAR_GRAPH_2_3       13

/* fourth bargraph example with 4 leds */
#define IODC_Out_Type_BAR_GRAPH_3_0         IODC_BYMATRIX
#define IODC_Out_Line_BAR_GRAPH_3_0         0
#define IODC_Out_Column_BAR_GRAPH_3_0       3
#define IODC_Out_Logic_BAR_GRAPH_3_0        IODC_POSITIVE
#define IODC_Out_PinRef_BAR_GRAPH_3_0       14

#define IODC_Out_Type_BAR_GRAPH_3_1         IODC_BYMATRIX
#define IODC_Out_Line_BAR_GRAPH_3_1         1
#define IODC_Out_Column_BAR_GRAPH_3_1       3
#define IODC_Out_Logic_BAR_GRAPH_3_1        IODC_POSITIVE
#define IODC_Out_PinRef_BAR_GRAPH_3_1       15

#define IODC_Out_Type_BAR_GRAPH_3_2         IODC_BYMATRIX
#define IODC_Out_Line_BAR_GRAPH_3_2         2
#define IODC_Out_Column_BAR_GRAPH_3_2       3
#define IODC_Out_Logic_BAR_GRAPH_3_2        IODC_POSITIVE
#define IODC_Out_PinRef_BAR_GRAPH_3_2       16

#define IODC_Out_Type_BAR_GRAPH_3_3         IODC_BYMATRIX
#define IODC_Out_Line_BAR_GRAPH_3_3         3
#define IODC_Out_Column_BAR_GRAPH_3_3       3
#define IODC_Out_Logic_BAR_GRAPH_3_3        IODC_POSITIVE
#define IODC_Out_PinRef_BAR_GRAPH_3_3       17


/*----------------------------------------------------------------------------*/
/* Led matrix : column pin configuration                                      */
/*----------------------------------------------------------------------------*/

#define IODC_NUMBER_OF_COLUMN_PIN /* 1, 2, 3, 4 */
                                  /* 1 = virtual column if shift register */
                                  /* alone, but necessary                 */

/*************************************************************************/
/* Template, remplace x by a number                                      */
/*************************************************************************/
#define IODC_ColumnOut_Port_x   /* port name (see IODD)                  */
#define IODC_ColumnOut_Bit_x    /* bit number (see IODD)                 */
#define IODC_ColumnOut_Logic_x  /* IODC_POSITIVE, IODC_NEGATIVE          */
#define IODC_ColumnOut_Drain_x  /* processor dependent :                 */
                                /* same option as direct output          */
#define IODC_ColumnOut_Port_0    x
#define IODC_ColumnOut_Bit_0     x
#define IODC_ColumnOut_Logic_0   x
#define IODC_ColumnOut_Drain_0   x

#define IODC_ColumnOut_Port_1    x
#define IODC_ColumnOut_Bit_1     x
#define IODC_ColumnOut_Logic_1   x
#define IODC_ColumnOut_Drain_1   x

#define IODC_ColumnOut_Port_2    x
#define IODC_ColumnOut_Bit_2     x
#define IODC_ColumnOut_Logic_2   x
#define IODC_ColumnOut_Drain_2   x


/*----------------------------------------------------------------------------*/
/* Led matrix : line pin configuration in case of direct access OR line       */
/*              drive by Shift Register                                       */
/*----------------------------------------------------------------------------*/

#define IODC_NUMBER_OF_LINE_PIN  8


/*----------------------------------------------------------------------------*/
/* Led matrix : line pin configuration ONLY in case of direct access          */
/*----------------------------------------------------------------------------*/

/*************************************************************************/
/* Template, remplace x by a number                                      */
/*************************************************************************/
#define IODC_LineOut_Port_x     /* port name (see IODD)                  */
#define IODC_LineOut_Bit_x      /* bit number (see IODD)                 */
#define IODC_LineOut_Logic_x    /* IODC_POSITIVE, IODC_NEGATIVE          */
#define IODC_LineOut_Drain_x    /* processor dependent :                 */
                                /* same option as direct output          */
#define IODC_LineOut_Port_0   x
#define IODC_LineOut_Bit_0    x
#define IODC_LineOut_Logic_0  x
#define IODC_LineOut_Drain_0  x

#define IODC_LineOut_Port_1   x
#define IODC_LineOut_Bit_1    x
#define IODC_LineOut_Logic_1  x
#define IODC_LineOut_Drain_1  x

#define IODC_LineOut_Port_2   x
#define IODC_LineOut_Bit_2    x
#define IODC_LineOut_Logic_2  x
#define IODC_LineOut_Drain_2  x

#define IODC_LineOut_Port_3   x
#define IODC_LineOut_Bit_3    x
#define IODC_LineOut_Logic_3  x
#define IODC_LineOut_Drain_3  x

#define IODC_LineOut_Port_4   x
#define IODC_LineOut_Bit_4    x
#define IODC_LineOut_Logic_4  x
#define IODC_LineOut_Drain_4  x

#define IODC_LineOut_Port_5   x
#define IODC_LineOut_Bit_5    x
#define IODC_LineOut_Logic_5  x
#define IODC_LineOut_Drain_5  x

#define IODC_LineOut_Port_6   x
#define IODC_LineOut_Bit_6    x
#define IODC_LineOut_Logic_6  x
#define IODC_LineOut_Drain_6  x

#define IODC_LineOut_Port_7   x
#define IODC_LineOut_Bit_7    x
#define IODC_LineOut_Logic_7  x
#define IODC_LineOut_Drain_7  x

/*----------------------------------------------------------------------------*/
/*                                                                            */
/* INPUT MATRIX (Multiplexed inputs) : number of input matrix                 */
/*                                                                            */
/*----------------------------------------------------------------------------*/

/* number of input matrix exist, maximum 2 */

#define IODC_NUMBER_OF_INPUT_MATRIX       x /* 0,1 or 2 */

/******************************************************************************/
/* Input Matrix descriptor                                                    */
/* You must create it for each matrix, it describe the                        */
/* number of line, of column and if a rotary switch exist                     */
/* where it is located (the number of the column)                             */
/******************************************************************************/
/* Template, replace x by the number of the matrix                            */
/* y = 1->2                                                                   */
/******************************************************************************/
#define IODC_NB_LINE_INMUX_y      x    /* nb of line in the matrix 2, 1->5    */
#define IODC_NB_COLUMN_INMUX_y    x    /* nb of column in the matrix 2, 1->4  */
#define IODC_COL_NB_ROTARY_SW_y   x    /* if exist column number where the    */
                                       /* rotary switch is located, 1->4      */
#define IODC_ROTARY_SWITCH_y      x    /* indicate if a rotary switch is      */
                                       /* present in this matrix              */
                                       /* _USED_ or _NOT_USED_ if not present */
#define IODC_IRQ_READING_MATRIX_y x    /* The matrix reading function is call */
                                       /* under interrupt _USED_ or           */
                                       /* _NOT_USED_ if pooling method is     */
                                       /* used                                */
#define IODC_ROTATION_DETECT_FCT_y x   /* Function which is called to detect  */
                                       /* a rotation after have sampling the  */
                                       /* switches of the button              */


/* Descriptor of the input matrix 1 */
/* WARNING : this driver is build in order to acquire value on the line and   */
/* supply voltage on the column. IN J95, remote control electronic circuit    */
/* is powered by line and the value acquired by column. So in this setting    */
/* the line are the column on the electronic and vice versa */
#define IODC_NB_LINE_INMUX_1                 3
#define IODC_NB_COLUMN_INMUX_1               4
/* Be carreful IODC_COL_NB_ROTARY_SW_1 start to 0 and not to 1, if IODC_NB_COLUMN_INMUX_1
   is equal to 4 and rotary is located on the fourth column IODC_COL_NB_ROTARY_SW_1 equal 3 */
#define IODC_COL_NB_ROTARY_SW_1              2
#define IODC_ROTARY_SWITCH_1                 _USED_

#define IODC_IRQ_READING_MATRIX_1            _USED_
#define IODC_ROTATION_DETECT_FCT_1           RTWP_DetectRotationRtr1

#if defined(IODC_INPUT_MATRIX_USED)
#if (IODC_INPUT_MATRIX_SCAN_REFRESH == IODC_INPUT_MATRIX_ISR_REFRESH)

/* Have regard for RTWP_Task period and IODC_InputMatrixSample ISR call frequency to size this
   index. Index is normaly equal to RTWP_Task period / IODC ISR Call frequency. ISR scan the
   matrix and store value in the array and RTWP_Task use this value and clear the array.
   RTWP_Task period = 20ms and ISR call frequency = 500us so index = 100 + x for secure */
  #define IODC_MUXIN_NB_SAMPLE   50
#endif /* IODC_INPUT_MATRIX_SCAN_REFRESH == IODC_INPUT_MATRIX_ISR_REFRESH */
#endif /* IODC_INPUT_MATRIX_USED */


/* Descriptor of the input matrix 2 */
#define IODC_NB_LINE_INMUX_2                 0
#define IODC_NB_COLUMN_INMUX_2               0
#define IODC_COL_NB_ROTARY_SW_2              0
#define IODC_ROTARY_SWITCH_2                 _NOT_USED_

#define IODC_IRQ_READING_MATRIX_2            _NOT_USED_
/* #define IODC_ROTATION_DETECT_FCT_2 */

/******************************************************************************/
/* Descriptor of the column 'y' used by the matrix number 'x'                 */
/* For each column existing in the matrix 'x', create this                    */
/* descriptor ; y = 0->3 ; x = 1->2                                           */
/******************************************************************************/
/* Template, replace x by the number of the matrix                            */
/******************************************************************************/
#define IODC_InMux_Column_Port_y_x   /* port name (see IODD)                  */
#define IODC_InMux_Column_Bit_y_x    /* bit number                            */
#define IODC_InMux_Column_Logic_y_x  /* IODC_POSITIVE, IODC_NEGATIVE          */
#define IODC_InMux_Column_Drain_y_x  /* processor dependent :                 */
                                     /* same option as direct output          */

/* Descriptor of column for matrix 1 */

#define IODC_InMux_Column_Port_0_1      x
#define IODC_InMux_Column_Bit_0_1       x
#define IODC_InMux_Column_Logic_0_1     x
#define IODC_InMux_Column_Drain_0_1     x

#define IODC_InMux_Column_Port_1_1      x
#define IODC_InMux_Column_Bit_1_1       x
#define IODC_InMux_Column_Logic_1_1     x
#define IODC_InMux_Column_Drain_1_1     x

#define IODC_InMux_Column_Port_2_1      x
#define IODC_InMux_Column_Bit_2_1       x
#define IODC_InMux_Column_Logic_2_1     x
#define IODC_InMux_Column_Drain_2_1     x

#define IODC_InMux_Column_Port_3_1      x
#define IODC_InMux_Column_Bit_3_1       x
#define IODC_InMux_Column_Logic_3_1     x
#define IODC_InMux_Column_Drain_3_1     x

/* Descriptor of column for matrix 2 */

#define IODC_InMux_Column_Port_0_2      x
#define IODC_InMux_Column_Bit_0_2       x
#define IODC_InMux_Column_Logic_0_2     x
#define IODC_InMux_Column_Drain_0_2     x

#define IODC_InMux_Column_Port_1_2      x
#define IODC_InMux_Column_Bit_1_2       x
#define IODC_InMux_Column_Logic_1_2     x
#define IODC_InMux_Column_Drain_1_2     x

#define IODC_InMux_Column_Port_2_2      x
#define IODC_InMux_Column_Bit_2_2       x
#define IODC_InMux_Column_Logic_2_2     x
#define IODC_InMux_Column_Drain_2_2     x

#define IODC_InMux_Column_Port_3_2      x
#define IODC_InMux_Column_Bit_3_2       x
#define IODC_InMux_Column_Logic_3_2     x
#define IODC_InMux_Column_Drain_3_2     x


/******************************************************************************/
/* Descriptor of the line 'y' used by the matrix number 'x'                   */
/* For each line existing in the matrix 'x', create this                      */
/* descriptor ; y = 1->4 ; x = 1->2                                           */
/******************************************************************************/
/* Template, replace x by the number of the matrix                            */
/******************************************************************************/
#define IODC_InMux_Line_Port_y_x     /* port name (see IODD)                  */
#define IODC_InMux_Line_Bit_y_x      /* bit number                            */
#define IODC_InMux_Line_Logic_y_x    /* IODC_POSITIVE, IODC_NEGATIVE          */
#define IODC_InMux_Line_Drain_y_x    /* processor dependent :                 */
                                     /* same option as direct output          */

/* Descriptor of line for matrix 1 */

#define IODC_InMux_Line_Port_1_1       x
#define IODC_InMux_Line_Bit_1_1        x
#define IODC_InMux_Line_Logic_1_1      x
#define IODC_InMux_Line_Drain_1_1      x

#define IODC_InMux_Line_Port_2_1       x
#define IODC_InMux_Line_Bit_2_1        x
#define IODC_InMux_Line_Logic_2_1      x
#define IODC_InMux_Line_Drain_2_1      x

#define IODC_InMux_Line_Port_3_1       x
#define IODC_InMux_Line_Bit_3_1        x
#define IODC_InMux_Line_Logic_3_1      x
#define IODC_InMux_Line_Drain_3_1      x

#define IODC_InMux_Line_Port_4_1       x
#define IODC_InMux_Line_Bit_4_1        x
#define IODC_InMux_Line_Logic_4_1      x

#define IODC_InMux_Line_Port_5_1       x
#define IODC_InMux_Line_Bit_5_1        x
#define IODC_InMux_Line_Logic_5_1      x

/* Descriptor of line for matrix 2 */

#define IODC_InMux_Line_Port_1_2       x
#define IODC_InMux_Line_Bit_1_2        x
#define IODC_InMux_Line_Logic_1_2      x

#define IODC_InMux_Line_Port_2_2       x
#define IODC_InMux_Line_Bit_2_2        x
#define IODC_InMux_Line_Logic_2_2      x

#define IODC_InMux_Line_Port_3_2       x
#define IODC_InMux_Line_Bit_3_2        x
#define IODC_InMux_Line_Logic_3_2      x

#define IODC_InMux_Line_Port_4_2       x
#define IODC_InMux_Line_Bit_4_2        x
#define IODC_InMux_Line_Logic_4_2      x

#define IODC_InMux_Line_Port_5_2       x
#define IODC_InMux_Line_Bit_5_2        x
#define IODC_InMux_Line_Logic_5_2      x

/**********************************************************/
/* Switch input descriptor                                */
/* For each switch located in a matrix, create this       */
/* Template, replace x by the switch name or by a number  */
/**********************************************************/

#define IODC_MuxIn_Nb_Matrix_  /* matrix number where the switch is located */
#define IODC_MuxIn_Line_       /* line number where the switch is located   */
#define IODC_MuxIn_Column_     /* column number where the switch is located */
#define IODC_MuxIn_Irq_        /* IODD_IT_DISABLE,                            */
                               /*   IODD_IT_RISING_EDGE,                    */
                               /*   IODD_IT_FALLING_EDGE,                   */
#define IODC_MuxIn_PullUp_     /* IODD_NO_PULL_UP,                          */
                               /*   IODD_PULL_UP                            */
                               /*   IODD_PULL_DOWN,                         */


/* CAUTION : This switch are reserved for rotary button 1 */
#define IODC_MuxIn_Nb_Matrix_swa1
#define IODC_MuxIn_Line_swa1
#define IODC_MuxIn_Column_swa1
#define IODC_MuxIn_Logic_swa1
#define IODC_MuxIn_Irq_swa1
#define IODC_MuxIn_PullUp_swa1

#define IODC_MuxIn_Nb_Matrix_swb1
#define IODC_MuxIn_Line_swb1
#define IODC_MuxIn_Column_swb1
#define IODC_MuxIn_Logic_swb1
#define IODC_MuxIn_Irq_swb1
#define IODC_MuxIn_PullUp_swb1

#define IODC_MuxIn_Nb_Matrix_swc1
#define IODC_MuxIn_Line_swc1
#define IODC_MuxIn_Column_swc1
#define IODC_MuxIn_Logic_swc1
#define IODC_MuxIn_Irq_swc1
#define IODC_MuxIn_PullUp_swc1

#define IODC_MuxIn_Nb_Matrix_swd1
#define IODC_MuxIn_Line_swd1
#define IODC_MuxIn_Column_swd1
#define IODC_MuxIn_Logic_swd1
#define IODC_MuxIn_Irq_swd1
#define IODC_MuxIn_PullUp_swd1

/* CAUTION : This switch are reserved for rotary button 2 */
#define IODC_MuxIn_Nb_Matrix_swa2
#define IODC_MuxIn_Line_swa2
#define IODC_MuxIn_Column_swa2
#define IODC_MuxIn_Logic_swa2
#define IODC_MuxIn_Irq_swa2
#define IODC_MuxIn_PullUp_swa2

#define IODC_MuxIn_Nb_Matrix_swb2
#define IODC_MuxIn_Line_swb2
#define IODC_MuxIn_Column_swb2
#define IODC_MuxIn_Logic_swb2
#define IODC_MuxIn_Irq_swb2
#define IODC_MuxIn_PullUp_swb2

#define IODC_MuxIn_Nb_Matrix_swc2
#define IODC_MuxIn_Line_swc2
#define IODC_MuxIn_Column_swc2
#define IODC_MuxIn_Logic_swc2
#define IODC_MuxIn_Irq_swc2
#define IODC_MuxIn_PullUp_swc2

#define IODC_MuxIn_Nb_Matrix_swd2
#define IODC_MuxIn_Line_swd2
#define IODC_MuxIn_Column_swd2
#define IODC_MuxIn_Logic_swd2
#define IODC_MuxIn_Irq_swd2
#define IODC_MuxIn_PullUp_swd2

/* Define here other multiplexed switch */
#define IODC_MuxIn_Nb_Matrix_
#define IODC_MuxIn_Line_
#define IODC_MuxIn_Column_
#define IODC_MuxIn_Logic_
#define IODC_MuxIn_Irq_
#define IODC_MuxIn_PullUp_


/*______ G L O B A L  - F U N C T I O N S - P R O T O T Y P E S ______________*/

#if (defined(__BOOT_LOADER_FLASHER_LINK__) || defined(__BOOT_CLIENT_EOL_LINK__) || (defined(__BOOT_LOADER_LINK__)))
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
extern void IODC_ConfigureHwBootKeyPin(void);


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
extern void IODC_RestoreHwBootKeyPin(void);

#endif /* __BOOT_LOADER_FLASHER_LINK__ || __BOOT_CLIENT_EOL_LINK__ || __BOOT_LOADER_LINK__ */

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
extern void IODC_SetupWakeUpIntPn(void);

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
extern void IODC_CreatePhyHwVersionDirection(void);
#endif /* IODC_CONFIG_H */


/*_____END _____ (iodc_config.h) _____________________________________________*/
