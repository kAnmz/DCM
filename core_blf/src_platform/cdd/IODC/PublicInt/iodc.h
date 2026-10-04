/******************************************************************************/
/*@F_NAME:               iodc.h                                               */
/*@F_PURPOSE:            Public interface of iodc module                      */
/*@F_CREATED_BY:         M. Sergent                                           */
/*@F_CREATION_DATE:      25/08/2000                                           */
/*@F_MPROC_TYPE:         NEC_V850 Fx3/Dx3, MC9S12xx, MC9S08xx                 */
/*                       Renesas RL78_D1A, RL78_F12,IMX53x,IMX6x              */
/************************************** (C) Copyright 2013 Magneti Marelli ****/

#ifndef IODC_H
#define IODC_H

/*______ I N C L U D E - F I L E S ___________________________________________*/

#include "syst.h"
#include "iodd.h"
#include "iodc_config.h"

#ifdef __CY_TV2__
#include "iodc_tv2.h"
#endif /* __CY_TV2__ */

#ifdef __RH850__
#include "iodc_rh850.h"
#endif
/*______ G L O B A L - D E F I N E ___________________________________________*/

/*
#define   IODC_ACTIVE           IODD_HIGH
#define   IODC_INACTIVE         IODD_LOW
 no redefine of IODD due to problem with COSMIC compiler
*/
#ifndef IODC_ACTIVE
#define   IODC_ACTIVE           1
#endif /*IODC_ACTIVE*/

#ifndef IODC_INACTIVE
#define   IODC_INACTIVE         0
#endif /*IODC_INACTIVE*/

#ifndef IODC_POSITIVE
#define   IODC_POSITIVE         IODC_ACTIVE
#endif /*IODC_POSITIVE*/

#ifndef IODC_NEGATIVE
#define   IODC_NEGATIVE         IODC_INACTIVE
#endif /*IODC_NEGATIVE*/

#ifndef IODC_NO_EVENT
#define   IODC_NO_EVENT         ((ubyte)  0)
#endif /*IODC_NO_EVENT*/

#ifndef IODC_IT_RISING_EDGE
#define   IODC_IT_RISING_EDGE   ((ubyte)  1)
#endif /*IODC_IT_RISING_EDGE*/

#ifndef IODC_IT_FALLING_EDGE
#define   IODC_IT_FALLING_EDGE  ((ubyte)  2)
#endif /*IODC_IT_FALLING_EDGE*/

#ifndef IODC_IT_HIGH_LEVEL
#define   IODC_IT_HIGH_LEVEL    ((ubyte)  3)
#endif /*IODC_IT_HIGH_LEVEL*/

#ifndef IODC_IT_LOW_LEVEL
#define   IODC_IT_LOW_LEVEL     ((ubyte)  4)
#endif/*IODC_IT_LOW_LEVEL*/

#ifndef IODC_IT_TOGGLE
#define   IODC_IT_TOGGLE        ((ubyte)  5)
#endif /*IODC_IT_TOGGLE*/

#ifndef IODC_LED_TURN_ON
#define   IODC_LED_TURN_ON      IODC_ACTIVE
#endif /*IODC_LED_TURN_ON*/

#ifndef IODC_LED_TURN_OFF
#define   IODC_LED_TURN_OFF     IODC_INACTIVE
#endif /*IODC_LED_TURN_OFF*/

#ifdef __REL_RL78__
#ifdef __REL_RL78_D1x__
#ifdef __REL_RL78_D1A__
#define   IODC_IRQ0              ((ubyte)  0)
#define   IODC_IRQ1              ((ubyte)  1)
#define   IODC_IRQ2              ((ubyte)  2)
#define   IODC_IRQ3              ((ubyte)  3)
#define   IODC_IRQ4              ((ubyte)  4)
#define   IODC_IRQ5              ((ubyte)  5)
#endif /* __REL_RL78_D1A__ */
#endif /* __REL_RL78_D1x__ */

#ifdef __REL_RL78_F1x__
#ifdef __REL_RL78_F12__
#define   IODC_IRQ0              ((ubyte)  0)
#define   IODC_IRQ1              ((ubyte)  1)
#define   IODC_IRQ2              ((ubyte)  2)
#define   IODC_IRQ3              ((ubyte)  3)
#define   IODC_IRQ4              ((ubyte)  4)
#define   IODC_IRQ5              ((ubyte)  5)
#define   IODC_IRQ6              ((ubyte)  6)
#define   IODC_IRQ7              ((ubyte)  7)
#define   IODC_IRQ8              ((ubyte)  8)
#define   IODC_IRQ9              ((ubyte)  9)
#define   IODC_IRQ10             ((ubyte)  10)
#define   IODC_IRQ11             ((ubyte)  11)
#endif /* __REL_RL78_F12__ */
#endif /* __REL_RL78_F1x__ */
#endif /* __REL_RL78__ */

#ifdef __MC9S12xx__
#define   IODC_IRQ0              ((ubyte)  0)
#define   IODC_IRQ1              ((ubyte)  1)
#define   IODC_IRQ2              ((ubyte)  2)
#define   IODC_IRQ3              ((ubyte)  3)
#define   IODC_IRQ4              ((ubyte)  4)
#define   IODC_IRQ5              ((ubyte)  5)
#define   IODC_IRQ6              ((ubyte)  6)
#define   IODC_IRQ7              ((ubyte)  7)
#define   IODC_IRQ8              ((ubyte)  8)
/* MC9S12-H variant */
#if defined(__MC9S12H__)
#define   IODC_IRQ9              ((ubyte)  9)
#define   IODC_IRQ10             ((ubyte) 10)
#define   IODC_IRQ11             ((ubyte) 11)
#define   IODC_IRQ12             ((ubyte) 12)
#endif /* defined(__MC9S12H__) */
#endif /* __MC9S12xx__ */

#ifdef __TX49__
#define   IODC_IRQ0             ((ubyte)  0)
#define   IODC_IRQ1             ((ubyte)  1)
#define   IODC_IRQ2             ((ubyte)  2)
#define   IODC_IRQ3             ((ubyte)  3)
#endif /* __TX49__ */


#ifdef __NEC_V850__
#define   IODC_IRQ0              ((ubyte)  0)
#define   IODC_IRQ1              ((ubyte)  1)
#define   IODC_IRQ2              ((ubyte)  2)
#define   IODC_IRQ3              ((ubyte)  3)
#define   IODC_IRQ4              ((ubyte)  4)
#define   IODC_IRQ5              ((ubyte)  5)
#define   IODC_IRQ6              ((ubyte)  6)
#define   IODC_IRQ7              ((ubyte)  7)
#define   IODC_IRQ8              ((ubyte)  8)
#define   IODC_IRQ9              ((ubyte)  9)
#define   IODC_IRQ10             ((ubyte) 10)
#define   IODC_IRQ11             ((ubyte) 11)
#define   IODC_IRQ12             ((ubyte) 12)
#define   IODC_IRQ13             ((ubyte) 13)
#define   IODC_IRQ14             ((ubyte) 14)
#define   IODC_IRQ15             ((ubyte) 15)
#define   IODC_IRQ_NMI           ((ubyte) 16)
#endif /* __NEC_V850__ */

#if defined(__FSL_IMX53x__) || defined(__FSL_IMX6x__)
#define   IODC_IRQ0              ((ubyte)  0)
#define   IODC_IRQ1              ((ubyte)  1)
#define   IODC_IRQ2              ((ubyte)  2)
#define   IODC_IRQ3              ((ubyte)  3)
#define   IODC_IRQ4              ((ubyte)  4)
#define   IODC_IRQ5              ((ubyte)  5)
#define   IODC_IRQ6              ((ubyte)  6)
#define   IODC_IRQ7              ((ubyte)  7)
#define   IODC_IRQ8              ((ubyte)  8)
#define   IODC_IRQ9              ((ubyte)  9)
#define   IODC_IRQ10             ((ubyte) 10)
#define   IODC_IRQ11             ((ubyte) 11)
#define   IODC_IRQ12             ((ubyte) 12)
#define   IODC_IRQ13             ((ubyte) 13)
#define   IODC_IRQ14             ((ubyte) 14)
#define   IODC_IRQ15             ((ubyte) 15)
#define   IODC_IRQ16             ((ubyte) 16)
#define   IODC_IRQ17             ((ubyte) 17)
#define   IODC_IRQ18             ((ubyte) 18)
#define   IODC_IRQ19             ((ubyte) 19)
#define   IODC_IRQ20             ((ubyte) 20)
#define   IODC_IRQ21             ((ubyte) 21)
#define   IODC_IRQ22             ((ubyte) 22)
#define   IODC_IRQ23             ((ubyte) 23)
#define   IODC_IRQ24             ((ubyte) 24)
#define   IODC_IRQ25             ((ubyte) 25)
#define   IODC_IRQ26             ((ubyte) 26)
#define   IODC_IRQ27             ((ubyte) 27)
#define   IODC_IRQ28             ((ubyte) 28)
#define   IODC_IRQ29             ((ubyte) 29)
#define   IODC_IRQ30             ((ubyte) 30)
#define   IODC_IRQ31             ((ubyte) 31)
#define   IODC_IRQ32             ((ubyte) 32)
#define   IODC_IRQ33             ((ubyte) 33)
#define   IODC_IRQ34             ((ubyte) 34)
#define   IODC_IRQ35             ((ubyte) 35)
#define   IODC_IRQ36             ((ubyte) 36)
#define   IODC_IRQ37             ((ubyte) 37)
#define   IODC_IRQ38             ((ubyte) 38)
#define   IODC_IRQ39             ((ubyte) 39)
#define   IODC_IRQ40             ((ubyte) 40)
#define   IODC_IRQ41             ((ubyte) 41)
#define   IODC_IRQ42             ((ubyte) 42)
#define   IODC_IRQ43             ((ubyte) 43)
#define   IODC_IRQ44             ((ubyte) 44)
#define   IODC_IRQ45             ((ubyte) 45)
#define   IODC_IRQ46             ((ubyte) 46)
#define   IODC_IRQ47             ((ubyte) 47)
#define   IODC_IRQ48             ((ubyte) 48)
#define   IODC_IRQ49             ((ubyte) 49)
#define   IODC_IRQ50             ((ubyte) 50)
#define   IODC_IRQ51             ((ubyte) 51)
#define   IODC_IRQ52             ((ubyte) 52)
#define   IODC_IRQ53             ((ubyte) 53)
#define   IODC_IRQ54             ((ubyte) 54)
#define   IODC_IRQ55             ((ubyte) 55)
#define   IODC_IRQ56             ((ubyte) 56)
#define   IODC_IRQ57             ((ubyte) 57)
#define   IODC_IRQ58             ((ubyte) 58)
#define   IODC_IRQ59             ((ubyte) 59)
#define   IODC_IRQ60             ((ubyte) 60)
#define   IODC_IRQ61             ((ubyte) 61)
#define   IODC_IRQ62             ((ubyte) 62)
#define   IODC_IRQ63             ((ubyte) 63)
#define   IODC_IRQ64             ((ubyte) 64)
#define   IODC_IRQ65             ((ubyte) 65)
#define   IODC_IRQ66             ((ubyte) 66)
#define   IODC_IRQ67             ((ubyte) 67)
#define   IODC_IRQ68             ((ubyte) 68)
#define   IODC_IRQ69             ((ubyte) 69)
#define   IODC_IRQ70             ((ubyte) 70)
#define   IODC_IRQ71             ((ubyte) 71)
#define   IODC_IRQ72             ((ubyte) 72)
#define   IODC_IRQ73             ((ubyte) 73)
#define   IODC_IRQ74             ((ubyte) 74)
#define   IODC_IRQ75             ((ubyte) 75)
#define   IODC_IRQ76             ((ubyte) 76)
#define   IODC_IRQ77             ((ubyte) 77)
#define   IODC_IRQ78             ((ubyte) 78)
#define   IODC_IRQ79             ((ubyte) 79)
#define   IODC_IRQ80             ((ubyte) 80)
#define   IODC_IRQ81             ((ubyte) 81)
#define   IODC_IRQ82             ((ubyte) 82)
#define   IODC_IRQ83             ((ubyte) 83)
#define   IODC_IRQ84             ((ubyte) 84)
#define   IODC_IRQ85             ((ubyte) 85)
#define   IODC_IRQ86             ((ubyte) 86)
#define   IODC_IRQ87             ((ubyte) 87)
#define   IODC_IRQ88             ((ubyte) 88)
#define   IODC_IRQ89             ((ubyte) 89)
#define   IODC_IRQ90             ((ubyte) 90)
#define   IODC_IRQ91             ((ubyte) 91)
#define   IODC_IRQ92             ((ubyte) 92)
#define   IODC_IRQ93             ((ubyte) 93)
#define   IODC_IRQ94             ((ubyte) 94)
#define   IODC_IRQ95             ((ubyte) 95)
#define   IODC_IRQ96             ((ubyte) 96)
#define   IODC_IRQ97             ((ubyte) 97)
#define   IODC_IRQ98             ((ubyte) 98)
#define   IODC_IRQ99             ((ubyte) 99)
#define   IODC_IRQ100            ((ubyte) 100)
#define   IODC_IRQ101            ((ubyte) 101)
#define   IODC_IRQ102            ((ubyte) 102)
#define   IODC_IRQ103            ((ubyte) 103)
#define   IODC_IRQ104            ((ubyte) 104)
#define   IODC_IRQ105            ((ubyte) 105)
#define   IODC_IRQ106            ((ubyte) 106)
#define   IODC_IRQ107            ((ubyte) 107)
#define   IODC_IRQ108            ((ubyte) 108)
#define   IODC_IRQ109            ((ubyte) 109)
#define   IODC_IRQ110            ((ubyte) 110)
#define   IODC_IRQ111            ((ubyte) 111)
#define   IODC_IRQ112            ((ubyte) 112)
#define   IODC_IRQ113            ((ubyte) 113)
#define   IODC_IRQ114            ((ubyte) 114)
#define   IODC_IRQ115            ((ubyte) 115)
#define   IODC_IRQ116            ((ubyte) 116)
#define   IODC_IRQ117            ((ubyte) 117)
#define   IODC_IRQ118            ((ubyte) 118)
#define   IODC_IRQ119            ((ubyte) 119)
#define   IODC_IRQ120            ((ubyte) 120)
#define   IODC_IRQ121            ((ubyte) 121)
#define   IODC_IRQ122            ((ubyte) 122)
#define   IODC_IRQ123            ((ubyte) 123)
#define   IODC_IRQ124            ((ubyte) 124)
#define   IODC_IRQ125            ((ubyte) 125)
#define   IODC_IRQ126            ((ubyte) 126)
#define   IODC_IRQ127            ((ubyte) 127)
#endif /* __FSL_IMX53x__ ,__FSL_IMX6x__ */


/* Macros to access timer pins state */
#if (defined(__MC9S12xx__))
#define IODC_DirectIn_Port_TIMER_0    T
#define IODC_DirectIn_Bit_TIMER_0     0
#define IODC_DirectIn_Logic_TIMER_0   IODC_POSITIVE
#define IODC_DirectIn_Port_TIMER_1    T
#define IODC_DirectIn_Bit_TIMER_1     1
#define IODC_DirectIn_Logic_TIMER_1   IODC_POSITIVE
#define IODC_DirectIn_Port_TIMER_2    T
#define IODC_DirectIn_Bit_TIMER_2     2
#define IODC_DirectIn_Logic_TIMER_2   IODC_POSITIVE
#define IODC_DirectIn_Port_TIMER_3    T
#define IODC_DirectIn_Bit_TIMER_3     3
#define IODC_DirectIn_Logic_TIMER_3   IODC_POSITIVE
#define IODC_DirectIn_Port_TIMER_4    T
#define IODC_DirectIn_Bit_TIMER_4     4
#define IODC_DirectIn_Logic_TIMER_4   IODC_POSITIVE
#define IODC_DirectIn_Port_TIMER_5    T
#define IODC_DirectIn_Bit_TIMER_5     5
#define IODC_DirectIn_Logic_TIMER_5   IODC_POSITIVE
#define IODC_DirectIn_Port_TIMER_6    T
#define IODC_DirectIn_Bit_TIMER_6     6
#define IODC_DirectIn_Logic_TIMER_6   IODC_POSITIVE
#define IODC_DirectIn_Port_TIMER_7    T
#define IODC_DirectIn_Bit_TIMER_7     7
#define IODC_DirectIn_Logic_TIMER_7   IODC_POSITIVE
#endif /* (defined(__MC9S12xx__) */

/* Macros to access timer pins state */
#if (defined(__MC9S08xx__))

#define   IODC_IRQ0              ((ubyte)  0)
#define   IODC_IRQ1              ((ubyte)  1)
#define   IODC_IRQ2              ((ubyte)  2)
#define   IODC_IRQ3              ((ubyte)  3)
#define   IODC_IRQ4              ((ubyte)  4)
#define   IODC_IRQ5              ((ubyte)  5)
#define   IODC_IRQ6              ((ubyte)  6)
#define   IODC_IRQ7              ((ubyte)  7)

#define   IODC_IRQPIN            ((ubyte)  8)

#define IODC_DirectIn_Port_TIMER_10    E
#define IODC_DirectIn_Bit_TIMER_10     2
#define IODC_DirectIn_Logic_TIMER_10   IODC_POSITIVE
#define IODC_DirectIn_Port_TIMER_11    E
#define IODC_DirectIn_Bit_TIMER_11     3
#define IODC_DirectIn_Logic_TIMER_11   IODC_POSITIVE
#define IODC_DirectIn_Port_TIMER_12    F
#define IODC_DirectIn_Bit_TIMER_12     0
#define IODC_DirectIn_Logic_TIMER_12   IODC_POSITIVE
#define IODC_DirectIn_Port_TIMER_13    F
#define IODC_DirectIn_Bit_TIMER_13     1
#define IODC_DirectIn_Logic_TIMER_13   IODC_POSITIVE
#define IODC_DirectIn_Port_TIMER_14    F
#define IODC_DirectIn_Bit_TIMER_14     2
#define IODC_DirectIn_Logic_TIMER_14   IODC_POSITIVE
#define IODC_DirectIn_Port_TIMER_15    F
#define IODC_DirectIn_Bit_TIMER_15     3
#define IODC_DirectIn_Logic_TIMER_15   IODC_POSITIVE
#define IODC_DirectIn_Port_TIMER_20    F
#define IODC_DirectIn_Bit_TIMER_20     4
#define IODC_DirectIn_Logic_TIMER_20   IODC_POSITIVE
#define IODC_DirectIn_Port_TIMER_21    F
#define IODC_DirectIn_Bit_TIMER_21     5
#define IODC_DirectIn_Logic_TIMER_21   IODC_POSITIVE
#endif /* (defined(__MC9S08xx__) */

#if (defined(__NEC_V850_Fx3__))
#define IODC_DirectIn_Port_TIMER_0    3
#define IODC_DirectIn_Bit_TIMER_0     2
#define IODC_DirectIn_Logic_TIMER_0   IODC_POSITIVE
#define IODC_DirectIn_Port_TIMER_1    3
#define IODC_DirectIn_Bit_TIMER_1     3
#define IODC_DirectIn_Logic_TIMER_1   IODC_POSITIVE
#define IODC_DirectIn_Port_TIMER_2    3
#define IODC_DirectIn_Bit_TIMER_2     4
#define IODC_DirectIn_Logic_TIMER_2   IODC_POSITIVE
#define IODC_DirectIn_Port_TIMER_3    3
#define IODC_DirectIn_Bit_TIMER_3     5
#define IODC_DirectIn_Logic_TIMER_3   IODC_POSITIVE
#define IODC_DirectIn_Port_TIMER_4    9
#define IODC_DirectIn_Bit_TIMER_4     7
#define IODC_DirectIn_Logic_TIMER_4   IODC_POSITIVE
#define IODC_DirectIn_Port_TIMER_5    9
#define IODC_DirectIn_Bit_TIMER_5     6
#define IODC_DirectIn_Logic_TIMER_5   IODC_POSITIVE
#define IODC_DirectIn_Port_TIMER_6    0
#define IODC_DirectIn_Bit_TIMER_6     1
#define IODC_DirectIn_Logic_TIMER_6   IODC_POSITIVE
#define IODC_DirectIn_Port_TIMER_7    0
#define IODC_DirectIn_Bit_TIMER_7     0
#define IODC_DirectIn_Logic_TIMER_7   IODC_POSITIVE
#define IODC_DirectIn_Port_TIMER_8    0
#define IODC_DirectIn_Bit_TIMER_8     2
#define IODC_DirectIn_Logic_TIMER_8   IODC_POSITIVE
#define IODC_DirectIn_Port_TIMER_9    0
#define IODC_DirectIn_Bit_TIMER_9     3
#define IODC_DirectIn_Logic_TIMER_9   IODC_POSITIVE
#endif /* (defined(__NEC_V850_Fx3__) */


#if (defined(__NEC_V850_Dx3__))
#define IODC_DirectIn_Port_TIMER_0    10
#define IODC_DirectIn_Bit_TIMER_0     0
#define IODC_DirectIn_Logic_TIMER_0   IODC_POSITIVE

#ifdef IODC_INPUT_TP01_IS_P61
#define IODC_DirectIn_Port_TIMER_1    6
#define IODC_DirectIn_Bit_TIMER_1     1
#define IODC_DirectIn_Logic_TIMER_1   IODC_POSITIVE
#endif /* IODC_INPUT_TP01_IS_P61 */

#ifdef IODC_INPUT_TP01_IS_P101
#define IODC_DirectIn_Port_TIMER_1    10
#define IODC_DirectIn_Bit_TIMER_1     1
#define IODC_DirectIn_Logic_TIMER_1   IODC_POSITIVE
#endif /* IODC_INPUT_TP01_IS_P101 */

#define IODC_DirectIn_Port_TIMER_2    6
#define IODC_DirectIn_Bit_TIMER_2     2
#define IODC_DirectIn_Logic_TIMER_2   IODC_POSITIVE

#define IODC_DirectIn_Port_TIMER_3    6
#define IODC_DirectIn_Bit_TIMER_3     3
#define IODC_DirectIn_Logic_TIMER_3   IODC_POSITIVE

#define IODC_DirectIn_Port_TIMER_4    6
#define IODC_DirectIn_Bit_TIMER_4     4
#define IODC_DirectIn_Logic_TIMER_4   IODC_POSITIVE

#ifdef IODC_INPUT_TP21_IS_P66
#define IODC_DirectIn_Port_TIMER_5    6
#define IODC_DirectIn_Bit_TIMER_5     6
#define IODC_DirectIn_Logic_TIMER_5   IODC_POSITIVE
#endif /* IODC_INPUT_TP21_IS_P66 */

#ifdef IODC_INPUT_TP21_IS_P103
#define IODC_DirectIn_Port_TIMER_5    10
#define IODC_DirectIn_Bit_TIMER_5     3
#define IODC_DirectIn_Logic_TIMER_5   IODC_POSITIVE
#endif /* IODC_INPUT_TP21_IS_P103 */

#define IODC_DirectIn_Port_TIMER_6    6
#define IODC_DirectIn_Bit_TIMER_6     5
#define IODC_DirectIn_Logic_TIMER_6   IODC_POSITIVE

#define IODC_DirectIn_Port_TIMER_7    6
#define IODC_DirectIn_Bit_TIMER_7     7
#define IODC_DirectIn_Logic_TIMER_7   IODC_POSITIVE

#endif /* (defined(__NEC_V850_Dx3__) */

#if (defined(__REL_V850_Dx4__))

#ifndef __REL_V850_DK4H__
#ifdef IODC_INPUT_TAUA000_IS_P300
#define IODC_DirectIn_Port_TIMER_0    3
#define IODC_DirectIn_Bit_TIMER_0     0
#define IODC_DirectIn_Logic_TIMER_0   IODC_POSITIVE
#endif /* IODC_INPUT_TAUA000_IS_P300 */

#ifdef IODC_INPUT_TAUA001_IS_P301
#define IODC_DirectIn_Port_TIMER_1    3
#define IODC_DirectIn_Bit_TIMER_1     1
#define IODC_DirectIn_Logic_TIMER_1   IODC_POSITIVE
#endif /* IODC_INPUT_TAUA001_IS_P301 */

#ifdef IODC_INPUT_TAUA002_IS_P302
#define IODC_DirectIn_Port_TIMER_2    3
#define IODC_DirectIn_Bit_TIMER_2     2
#define IODC_DirectIn_Logic_TIMER_2   IODC_POSITIVE
#endif /* IODC_INPUT_TAUA002_IS_P302 */

#ifdef IODC_INPUT_TAUA003_IS_P303
#define IODC_DirectIn_Port_TIMER_3    3
#define IODC_DirectIn_Bit_TIMER_3     3
#define IODC_DirectIn_Logic_TIMER_3   IODC_POSITIVE
#endif /* IODC_INPUT_TAUA003_IS_P303 */

#ifdef IODC_INPUT_TAUA004_IS_P304
#define IODC_DirectIn_Port_TIMER_4    3
#define IODC_DirectIn_Bit_TIMER_4     4
#define IODC_DirectIn_Logic_TIMER_4   IODC_POSITIVE
#endif /* IODC_INPUT_TAUA004_IS_P304 */

#ifdef IODC_INPUT_TAUA005_IS_P305
#define IODC_DirectIn_Port_TIMER_5    3
#define IODC_DirectIn_Bit_TIMER_5     5
#define IODC_DirectIn_Logic_TIMER_5   IODC_POSITIVE
#endif /* IODC_INPUT_TAUA005_IS_P305 */

#ifdef IODC_INPUT_TAUA006_IS_P306
#define IODC_DirectIn_Port_TIMER_6    3
#define IODC_DirectIn_Bit_TIMER_6     6
#define IODC_DirectIn_Logic_TIMER_6   IODC_POSITIVE
#endif /* IODC_INPUT_TAUA006_IS_P306 */

#ifdef IODC_INPUT_TAUA007_IS_P307
#define IODC_DirectIn_Port_TIMER_7    3
#define IODC_DirectIn_Bit_TIMER_7     7
#define IODC_DirectIn_Logic_TIMER_7   IODC_POSITIVE
#endif /* IODC_INPUT_TAUA007_IS_P307 */

#ifdef IODC_INPUT_TAUA008_IS_P308
#define IODC_DirectIn_Port_TIMER_8    3
#define IODC_DirectIn_Bit_TIMER_8     8
#define IODC_DirectIn_Logic_TIMER_8   IODC_POSITIVE
#endif /* IODC_INPUT_TAUA008_IS_P308 */

#ifdef IODC_INPUT_TAUA009_IS_P309
#define IODC_DirectIn_Port_TIMER_9    3
#define IODC_DirectIn_Bit_TIMER_9     9
#define IODC_DirectIn_Logic_TIMER_9   IODC_POSITIVE
#endif /* IODC_INPUT_TAUA009_IS_P309 */

#ifdef IODC_INPUT_TAUA010_IS_P310
#define IODC_DirectIn_Port_TIMER_10    3
#define IODC_DirectIn_Bit_TIMER_10     10
#define IODC_DirectIn_Logic_TIMER_10   IODC_POSITIVE
#endif /* IODC_INPUT_TAUA010_IS_P310 */

#ifdef IODC_INPUT_TAUA011_IS_P311
#define IODC_DirectIn_Port_TIMER_11    3
#define IODC_DirectIn_Bit_TIMER_11     11
#define IODC_DirectIn_Logic_TIMER_11   IODC_POSITIVE
#endif /* IODC_INPUT_TAUA011_IS_P311 */

#ifdef IODC_INPUT_TAUA012_IS_P312
#define IODC_DirectIn_Port_TIMER_12    3
#define IODC_DirectIn_Bit_TIMER_12     12
#define IODC_DirectIn_Logic_TIMER_12   IODC_POSITIVE
#endif /* IODC_INPUT_TAUA012_IS_P312 */

#ifdef IODC_INPUT_TAUA013_IS_P400
#define IODC_DirectIn_Port_TIMER_13    4
#define IODC_DirectIn_Bit_TIMER_13     0
#define IODC_DirectIn_Logic_TIMER_13   IODC_POSITIVE
#endif /* IODC_INPUT_TAUA013_IS_P400 */

#ifdef IODC_INPUT_TAUA014_IS_P401
#define IODC_DirectIn_Port_TIMER_14    4
#define IODC_DirectIn_Bit_TIMER_14     1
#define IODC_DirectIn_Logic_TIMER_14   IODC_POSITIVE
#endif /* IODC_INPUT_TAUA014_IS_P401 */

#ifdef IODC_INPUT_TAUA015_IS_P402
#define IODC_DirectIn_Port_TIMER_15    4
#define IODC_DirectIn_Bit_TIMER_15     2
#define IODC_DirectIn_Logic_TIMER_15   IODC_POSITIVE
#endif /* IODC_INPUT_TAUA015_IS_P402 */

#ifdef IODC_INPUT_TAUA101_IS_P400
#define IODC_DirectIn_Port_TIMER_17    4
#define IODC_DirectIn_Bit_TIMER_17     0
#define IODC_DirectIn_Logic_TIMER_17   IODC_POSITIVE
#endif /* IODC_INPUT_TAUA101_IS_P400 */

#ifdef IODC_INPUT_TAUA102_IS_P401
#define IODC_DirectIn_Port_TIMER_18    4
#define IODC_DirectIn_Bit_TIMER_18     1
#define IODC_DirectIn_Logic_TIMER_18   IODC_POSITIVE
#endif /* IODC_INPUT_TAUA102_IS_P401 */

#ifdef IODC_INPUT_TAUA103_IS_P402
#define IODC_DirectIn_Port_TIMER_19    4
#define IODC_DirectIn_Bit_TIMER_19     2
#define IODC_DirectIn_Logic_TIMER_19   IODC_POSITIVE
#endif /* IODC_INPUT_TAUA103_IS_P402 */

#ifdef IODC_INPUT_TAUA105_IS_P403
#define IODC_DirectIn_Port_TIMER_21    4
#define IODC_DirectIn_Bit_TIMER_21     3
#define IODC_DirectIn_Logic_TIMER_21   IODC_POSITIVE
#endif /* IODC_INPUT_TAUA105_IS_P403 */

#ifdef IODC_INPUT_TAUA107_IS_P405
#define IODC_DirectIn_Port_TIMER_23    4
#define IODC_DirectIn_Bit_TIMER_23     5
#define IODC_DirectIn_Logic_TIMER_23   IODC_POSITIVE
#endif /* IODC_INPUT_TAUA107_IS_P405 */

#ifdef IODC_INPUT_TAUA109_IS_P406
#define IODC_DirectIn_Port_TIMER_25    4
#define IODC_DirectIn_Bit_TIMER_25     6
#define IODC_DirectIn_Logic_TIMER_25   IODC_POSITIVE
#endif /* IODC_INPUT_TAUA109_IS_P406 */

#ifdef IODC_INPUT_TAUA111_IS_P408
#define IODC_DirectIn_Port_TIMER_27    4
#define IODC_DirectIn_Bit_TIMER_27     8
#define IODC_DirectIn_Logic_TIMER_27   IODC_POSITIVE
#endif /* IODC_INPUT_TAUA111_IS_P408 */

#ifdef IODC_INPUT_TAUA113_IS_P409
#define IODC_DirectIn_Port_TIMER_29    4
#define IODC_DirectIn_Bit_TIMER_29     9
#define IODC_DirectIn_Logic_TIMER_29   IODC_POSITIVE
#endif /* IODC_INPUT_TAUA113_IS_P409 */

#ifdef IODC_INPUT_TAUA114_IS_P410
#define IODC_DirectIn_Port_TIMER_30    4
#define IODC_DirectIn_Bit_TIMER_30     10
#define IODC_DirectIn_Logic_TIMER_30   IODC_POSITIVE
#endif /* IODC_INPUT_TAUA114_IS_P410 */

#ifdef IODC_INPUT_TAUA115_IS_P411
#define IODC_DirectIn_Port_TIMER_31    4
#define IODC_DirectIn_Bit_TIMER_31     11
#define IODC_DirectIn_Logic_TIMER_31   IODC_POSITIVE
#endif /* IODC_INPUT_TAUA115_IS_P411 */

#ifdef IODC_INPUT_TAUA101_IS_P1600
#define IODC_DirectIn_Port_TIMER_17    16
#define IODC_DirectIn_Bit_TIMER_17     0
#define IODC_DirectIn_Logic_TIMER_17   IODC_POSITIVE
#endif /* IODC_INPUT_TAUA101_IS_P1600 */

#ifdef IODC_INPUT_TAUA102_IS_P1601
#define IODC_DirectIn_Port_TIMER_18    16
#define IODC_DirectIn_Bit_TIMER_18     1
#define IODC_DirectIn_Logic_TIMER_18   IODC_POSITIVE
#endif /* IODC_INPUT_TAUA102_IS_P1601 */

#ifdef IODC_INPUT_TAUA103_IS_P1602
#define IODC_DirectIn_Port_TIMER_19    16
#define IODC_DirectIn_Bit_TIMER_19     2
#define IODC_DirectIn_Logic_TIMER_19   IODC_POSITIVE
#endif /* IODC_INPUT_TAUA103_IS_P1602 */

#ifdef IODC_INPUT_TAUA105_IS_P1603
#define IODC_DirectIn_Port_TIMER_21    16
#define IODC_DirectIn_Bit_TIMER_21     3
#define IODC_DirectIn_Logic_TIMER_21   IODC_POSITIVE
#endif /* IODC_INPUT_TAUA105_IS_P1603 */

#ifdef IODC_INPUT_TAUA106_IS_P1604
#define IODC_DirectIn_Port_TIMER_22    16
#define IODC_DirectIn_Bit_TIMER_22     4
#define IODC_DirectIn_Logic_TIMER_22   IODC_POSITIVE
#endif /* IODC_INPUT_TAUA106_IS_P1604 */

#ifdef IODC_INPUT_TAUA107_IS_P1605
#define IODC_DirectIn_Port_TIMER_23    16
#define IODC_DirectIn_Bit_TIMER_23     5
#define IODC_DirectIn_Logic_TIMER_23   IODC_POSITIVE
#endif /* IODC_INPUT_TAUA107_IS_P1605 */

#ifdef IODC_INPUT_TAUA109_IS_P1606
#define IODC_DirectIn_Port_TIMER_25    16
#define IODC_DirectIn_Bit_TIMER_25     6
#define IODC_DirectIn_Logic_TIMER_25   IODC_POSITIVE
#endif /* IODC_INPUT_TAUA109_IS_P1606 */

#ifdef IODC_INPUT_TAUA110_IS_P1607
#define IODC_DirectIn_Port_TIMER_26    16
#define IODC_DirectIn_Bit_TIMER_26     7
#define IODC_DirectIn_Logic_TIMER_26   IODC_POSITIVE
#endif /* IODC_INPUT_TAUA110_IS_P1607 */

#ifdef IODC_INPUT_TAUA111_IS_P1608
#define IODC_DirectIn_Port_TIMER_27    16
#define IODC_DirectIn_Bit_TIMER_27     8
#define IODC_DirectIn_Logic_TIMER_27   IODC_POSITIVE
#endif /* IODC_INPUT_TAUA111_IS_P1608 */

#ifdef IODC_INPUT_TAUA113_IS_P1609
#define IODC_DirectIn_Port_TIMER_29    16
#define IODC_DirectIn_Bit_TIMER_29     9
#define IODC_DirectIn_Logic_TIMER_29   IODC_POSITIVE
#endif /* IODC_INPUT_TAUA113_IS_P1609 */

#ifdef IODC_INPUT_TAUA114_IS_P1610
#define IODC_DirectIn_Port_TIMER_30    16
#define IODC_DirectIn_Bit_TIMER_30     10
#define IODC_DirectIn_Logic_TIMER_30   IODC_POSITIVE
#endif /* IODC_INPUT_TAUA114_IS_P1610 */

#ifdef IODC_INPUT_TAUA115_IS_P1611
#define IODC_DirectIn_Port_TIMER_31    16
#define IODC_DirectIn_Bit_TIMER_31     11
#define IODC_DirectIn_Logic_TIMER_31   IODC_POSITIVE
#endif /* IODC_INPUT_TAUA115_IS_P1611 */

#ifdef IODC_INPUT_TAUA201_IS_P301
#define IODC_DirectIn_Port_TIMER_33    3
#define IODC_DirectIn_Bit_TIMER_33     1
#define IODC_DirectIn_Logic_TIMER_33   IODC_POSITIVE
#endif /* IODC_INPUT_TAUA201_IS_P301 */

#ifdef IODC_INPUT_TAUA202_IS_P302
#define IODC_DirectIn_Port_TIMER_34    3
#define IODC_DirectIn_Bit_TIMER_34     2
#define IODC_DirectIn_Logic_TIMER_34   IODC_POSITIVE
#endif /* IODC_INPUT_TAUA202_IS_P302 */

#ifdef IODC_INPUT_TAUA203_IS_P303
#define IODC_DirectIn_Port_TIMER_35    3
#define IODC_DirectIn_Bit_TIMER_35     3
#define IODC_DirectIn_Logic_TIMER_35   IODC_POSITIVE
#endif /* IODC_INPUT_TAUA203_IS_P303 */

#ifdef IODC_INPUT_TAUA205_IS_P304
#define IODC_DirectIn_Port_TIMER_37    3
#define IODC_DirectIn_Bit_TIMER_37     4
#define IODC_DirectIn_Logic_TIMER_37   IODC_POSITIVE
#endif /* IODC_INPUT_TAUA205_IS_P304 */

#ifdef IODC_INPUT_TAUA206_IS_P305
#define IODC_DirectIn_Port_TIMER_38    3
#define IODC_DirectIn_Bit_TIMER_38     5
#define IODC_DirectIn_Logic_TIMER_38   IODC_POSITIVE
#endif /* IODC_INPUT_TAUA206_IS_P305 */

#ifdef IODC_INPUT_TAUA207_IS_P306
#define IODC_DirectIn_Port_TIMER_39    3
#define IODC_DirectIn_Bit_TIMER_39     6
#define IODC_DirectIn_Logic_TIMER_39   IODC_POSITIVE
#endif /* IODC_INPUT_TAUA207_IS_P306 */

#ifdef IODC_INPUT_TAUA209_IS_P307
#define IODC_DirectIn_Port_TIMER_41    3
#define IODC_DirectIn_Bit_TIMER_41     7
#define IODC_DirectIn_Logic_TIMER_41   IODC_POSITIVE
#endif /* IODC_INPUT_TAUA209_IS_P307 */

#ifdef IODC_INPUT_TAUA210_IS_P308
#define IODC_DirectIn_Port_TIMER_42    3
#define IODC_DirectIn_Bit_TIMER_42     8
#define IODC_DirectIn_Logic_TIMER_42   IODC_POSITIVE
#endif /* IODC_INPUT_TAUA210_IS_P308 */

#ifdef IODC_INPUT_TAUA211_IS_P309
#define IODC_DirectIn_Port_TIMER_43    3
#define IODC_DirectIn_Bit_TIMER_43     9
#define IODC_DirectIn_Logic_TIMER_43   IODC_POSITIVE
#endif /* IODC_INPUT_TAUA211_IS_P309 */

#ifdef IODC_INPUT_TAUA213_IS_P310
#define IODC_DirectIn_Port_TIMER_45    3
#define IODC_DirectIn_Bit_TIMER_45     10
#define IODC_DirectIn_Logic_TIMER_45   IODC_POSITIVE
#endif /* IODC_INPUT_TAUA213_IS_P310 */

#ifdef IODC_INPUT_TAUA214_IS_P311
#define IODC_DirectIn_Port_TIMER_46    3
#define IODC_DirectIn_Bit_TIMER_46     11
#define IODC_DirectIn_Logic_TIMER_46   IODC_POSITIVE
#endif /* IODC_INPUT_TAUA214_IS_P311 */

#ifdef IODC_INPUT_TAUA215_IS_P312
#define IODC_DirectIn_Port_TIMER_47    3
#define IODC_DirectIn_Bit_TIMER_47     12
#define IODC_DirectIn_Logic_TIMER_47   IODC_POSITIVE
#endif /* IODC_INPUT_TAUA215_IS_P312 */

#ifdef IODC_INPUT_TAUA201_IS_P1700
#define IODC_DirectIn_Port_TIMER_33    17
#define IODC_DirectIn_Bit_TIMER_33     0
#define IODC_DirectIn_Logic_TIMER_33   IODC_POSITIVE
#endif /* IODC_INPUT_TAUA201_IS_P1700 */

#ifdef IODC_INPUT_TAUA202_IS_P1701
#define IODC_DirectIn_Port_TIMER_34    17
#define IODC_DirectIn_Bit_TIMER_34     1
#define IODC_DirectIn_Logic_TIMER_34   IODC_POSITIVE
#endif /* IODC_INPUT_TAUA202_IS_P1701 */

#ifdef IODC_INPUT_TAUA203_IS_P1702
#define IODC_DirectIn_Port_TIMER_35    17
#define IODC_DirectIn_Bit_TIMER_35     2
#define IODC_DirectIn_Logic_TIMER_35   IODC_POSITIVE
#endif /* IODC_INPUT_TAUA203_IS_P1702 */

#ifdef IODC_INPUT_TAUA205_IS_P1703
#define IODC_DirectIn_Port_TIMER_37    17
#define IODC_DirectIn_Bit_TIMER_37     3
#define IODC_DirectIn_Logic_TIMER_37   IODC_POSITIVE
#endif /* IODC_INPUT_TAUA205_IS_P1703 */

#ifdef IODC_INPUT_TAUA206_IS_P1704
#define IODC_DirectIn_Port_TIMER_38    17
#define IODC_DirectIn_Bit_TIMER_38     4
#define IODC_DirectIn_Logic_TIMER_38   IODC_POSITIVE
#endif /* IODC_INPUT_TAUA206_IS_P1704 */

#ifdef IODC_INPUT_TAUA207_IS_P1705
#define IODC_DirectIn_Port_TIMER_39    17
#define IODC_DirectIn_Bit_TIMER_39     5
#define IODC_DirectIn_Logic_TIMER_39   IODC_POSITIVE
#endif /* IODC_INPUT_TAUA207_IS_P1705 */

#ifdef IODC_INPUT_TAUA209_IS_P1706
#define IODC_DirectIn_Port_TIMER_41    17
#define IODC_DirectIn_Bit_TIMER_41     6
#define IODC_DirectIn_Logic_TIMER_41   IODC_POSITIVE
#endif /* IODC_INPUT_TAUA209_IS_P1706 */

#ifdef IODC_INPUT_TAUA210_IS_P1707
#define IODC_DirectIn_Port_TIMER_42    17
#define IODC_DirectIn_Bit_TIMER_42     7
#define IODC_DirectIn_Logic_TIMER_42   IODC_POSITIVE
#endif /* IODC_INPUT_TAUA210_IS_P1707 */

#ifdef IODC_INPUT_TAUA211_IS_P1708
#define IODC_DirectIn_Port_TIMER_43    17
#define IODC_DirectIn_Bit_TIMER_43     8
#define IODC_DirectIn_Logic_TIMER_43   IODC_POSITIVE
#endif /* IODC_INPUT_TAUA211_IS_P1708 */

#ifdef IODC_INPUT_TAUA213_IS_P1709
#define IODC_DirectIn_Port_TIMER_45    17
#define IODC_DirectIn_Bit_TIMER_45     9
#define IODC_DirectIn_Logic_TIMER_45   IODC_POSITIVE
#endif /* IODC_INPUT_TAUA213_IS_P1709 */

#ifdef IODC_INPUT_TAUA214_IS_P1710
#define IODC_DirectIn_Port_TIMER_46    17
#define IODC_DirectIn_Bit_TIMER_46     10
#define IODC_DirectIn_Logic_TIMER_46   IODC_POSITIVE
#endif /* IODC_INPUT_TAUA214_IS_P1710 */

#ifdef IODC_INPUT_TAUA215_IS_P1711
#define IODC_DirectIn_Port_TIMER_47    17
#define IODC_DirectIn_Bit_TIMER_47     11
#define IODC_DirectIn_Logic_TIMER_47   IODC_POSITIVE
#endif /* IODC_INPUT_TAUA215_IS_P1711 */

#ifdef IODC_INPUT_TAUA301_IS_P101
#define IODC_DirectIn_Port_TIMER_49    1
#define IODC_DirectIn_Bit_TIMER_49     1
#define IODC_DirectIn_Logic_TIMER_49   IODC_POSITIVE
#endif /* IODC_INPUT_TAUA301_IS_P101 */

#ifdef IODC_INPUT_TAUA302_IS_P102
#define IODC_DirectIn_Port_TIMER_50    1
#define IODC_DirectIn_Bit_TIMER_50     2
#define IODC_DirectIn_Logic_TIMER_50   IODC_POSITIVE
#endif /* IODC_INPUT_TAUA302_IS_P102 */

#ifdef IODC_INPUT_TAUA303_IS_P103
#define IODC_DirectIn_Port_TIMER_51    1
#define IODC_DirectIn_Bit_TIMER_51     3
#define IODC_DirectIn_Logic_TIMER_51   IODC_POSITIVE
#endif /* IODC_INPUT_TAUA303_IS_P103 */

#ifdef IODC_INPUT_TAUA304_IS_P104
#define IODC_DirectIn_Port_TIMER_52    1
#define IODC_DirectIn_Bit_TIMER_52     4
#define IODC_DirectIn_Logic_TIMER_52   IODC_POSITIVE
#endif /* IODC_INPUT_TAUA304_IS_P104 */

#ifdef IODC_INPUT_TAUA305_IS_P105
#define IODC_DirectIn_Port_TIMER_53    1
#define IODC_DirectIn_Bit_TIMER_53     5
#define IODC_DirectIn_Logic_TIMER_53   IODC_POSITIVE
#endif /* IODC_INPUT_TAUA305_IS_P105 */

#ifdef IODC_INPUT_TAUA306_IS_P106
#define IODC_DirectIn_Port_TIMER_54    1
#define IODC_DirectIn_Bit_TIMER_54     6
#define IODC_DirectIn_Logic_TIMER_54   IODC_POSITIVE
#endif /* IODC_INPUT_TAUA306_IS_P106 */

#ifdef IODC_INPUT_TAUA307_IS_P107
#define IODC_DirectIn_Port_TIMER_55    1
#define IODC_DirectIn_Bit_TIMER_55     7
#define IODC_DirectIn_Logic_TIMER_55   IODC_POSITIVE
#endif /* IODC_INPUT_TAUA307_IS_P107 */

#ifdef IODC_INPUT_TAUA308_IS_P108
#define IODC_DirectIn_Port_TIMER_56    1
#define IODC_DirectIn_Bit_TIMER_56     8
#define IODC_DirectIn_Logic_TIMER_56   IODC_POSITIVE
#endif /* IODC_INPUT_TAUA308_IS_P108 */

#ifdef IODC_INPUT_TAUA309_IS_P109
#define IODC_DirectIn_Port_TIMER_57    1
#define IODC_DirectIn_Bit_TIMER_57     9
#define IODC_DirectIn_Logic_TIMER_57   IODC_POSITIVE
#endif /* IODC_INPUT_TAUA309_IS_P109 */

#ifdef IODC_INPUT_TAUA310_IS_P110
#define IODC_DirectIn_Port_TIMER_58    1
#define IODC_DirectIn_Bit_TIMER_58     10
#define IODC_DirectIn_Logic_TIMER_58   IODC_POSITIVE
#endif /* IODC_INPUT_TAUA310_IS_P110 */

#ifdef IODC_INPUT_TAUA311_IS_P111
#define IODC_DirectIn_Port_TIMER_59    1
#define IODC_DirectIn_Bit_TIMER_59     11
#define IODC_DirectIn_Logic_TIMER_59   IODC_POSITIVE
#endif /* IODC_INPUT_TAUA311_IS_P111 */

#ifdef IODC_INPUT_TAUA312_IS_P112
#define IODC_DirectIn_Port_TIMER_60    1
#define IODC_DirectIn_Bit_TIMER_60     12
#define IODC_DirectIn_Logic_TIMER_60   IODC_POSITIVE
#endif /* IODC_INPUT_TAUA312_IS_P112 */

#ifdef IODC_INPUT_TAUA313_IS_P113
#define IODC_DirectIn_Port_TIMER_61    1
#define IODC_DirectIn_Bit_TIMER_61     13
#define IODC_DirectIn_Logic_TIMER_61   IODC_POSITIVE
#endif /* IODC_INPUT_TAUA313_IS_P113 */

#ifdef IODC_INPUT_TAUA314_IS_P114
#define IODC_DirectIn_Port_TIMER_62    1
#define IODC_DirectIn_Bit_TIMER_62     14
#define IODC_DirectIn_Logic_TIMER_62   IODC_POSITIVE
#endif /* IODC_INPUT_TAUA314_IS_P114 */

#ifdef IODC_INPUT_TAUA315_IS_P115
#define IODC_DirectIn_Port_TIMER_63    1
#define IODC_DirectIn_Bit_TIMER_63     15
#define IODC_DirectIn_Logic_TIMER_63   IODC_POSITIVE
#endif /* IODC_INPUT_TAUA315_IS_P115 */

#ifdef IODC_INPUT_TAUA301_IS_P1700
#define IODC_DirectIn_Port_TIMER_49    17
#define IODC_DirectIn_Bit_TIMER_49     0
#define IODC_DirectIn_Logic_TIMER_49   IODC_POSITIVE
#endif /* IODC_INPUT_TAUA301_IS_P1700 */

#ifdef IODC_INPUT_TAUA302_IS_P1701
#define IODC_DirectIn_Port_TIMER_50    17
#define IODC_DirectIn_Bit_TIMER_50     1
#define IODC_DirectIn_Logic_TIMER_50   IODC_POSITIVE
#endif /* IODC_INPUT_TAUA302_IS_P1701 */

#ifdef IODC_INPUT_TAUA303_IS_P1702
#define IODC_DirectIn_Port_TIMER_51    17
#define IODC_DirectIn_Bit_TIMER_51     2
#define IODC_DirectIn_Logic_TIMER_51   IODC_POSITIVE
#endif /* IODC_INPUT_TAUA303_IS_P1702 */

#ifdef IODC_INPUT_TAUA305_IS_P1703
#define IODC_DirectIn_Port_TIMER_53    17
#define IODC_DirectIn_Bit_TIMER_53     3
#define IODC_DirectIn_Logic_TIMER_53   IODC_POSITIVE
#endif /* IODC_INPUT_TAUA305_IS_P1703 */

#ifdef IODC_INPUT_TAUA306_IS_P1704
#define IODC_DirectIn_Port_TIMER_54    17
#define IODC_DirectIn_Bit_TIMER_54     4
#define IODC_DirectIn_Logic_TIMER_54   IODC_POSITIVE
#endif /* IODC_INPUT_TAUA306_IS_P1704 */

#ifdef IODC_INPUT_TAUA307_IS_P1705
#define IODC_DirectIn_Port_TIMER_55    17
#define IODC_DirectIn_Bit_TIMER_55     5
#define IODC_DirectIn_Logic_TIMER_55   IODC_POSITIVE
#endif /* IODC_INPUT_TAUA307_IS_P1705 */

#ifdef IODC_INPUT_TAUA309_IS_P1706
#define IODC_DirectIn_Port_TIMER_57    17
#define IODC_DirectIn_Bit_TIMER_57     6
#define IODC_DirectIn_Logic_TIMER_57   IODC_POSITIVE
#endif /* IODC_INPUT_TAUA309_IS_P1706 */

#ifdef IODC_INPUT_TAUA310_IS_P1707
#define IODC_DirectIn_Port_TIMER_58    17
#define IODC_DirectIn_Bit_TIMER_58     7
#define IODC_DirectIn_Logic_TIMER_58   IODC_POSITIVE
#endif /* IODC_INPUT_TAUA310_IS_P1707 */

#ifdef IODC_INPUT_TAUA311_IS_P1708
#define IODC_DirectIn_Port_TIMER_59    17
#define IODC_DirectIn_Bit_TIMER_59     8
#define IODC_DirectIn_Logic_TIMER_59   IODC_POSITIVE
#endif /* IODC_INPUT_TAUA311_IS_P1708 */

#ifdef IODC_INPUT_TAUA313_IS_P1709
#define IODC_DirectIn_Port_TIMER_61    17
#define IODC_DirectIn_Bit_TIMER_61     9
#define IODC_DirectIn_Logic_TIMER_61   IODC_POSITIVE
#endif /* IODC_INPUT_TAUA313_IS_P1709 */

#ifdef IODC_INPUT_TAUA314_IS_P1710
#define IODC_DirectIn_Port_TIMER_62     17
#define IODC_DirectIn_Bit_TIMER_62      10
#define IODC_DirectIn_Logic_TIMER_62    IODC_POSITIVE
#endif /* IODC_INPUT_TAUA314_IS_P1710 */

#ifdef IODC_INPUT_TAUA315_IS_P1711
#define IODC_DirectIn_Port_TIMER_63    17
#define IODC_DirectIn_Bit_TIMER_63     11
#define IODC_DirectIn_Logic_TIMER_63   IODC_POSITIVE
#endif /* IODC_INPUT_TAUA315_IS_P1711 */

#ifdef IODC_INPUT_TAUA400_IS_P101
#define IODC_DirectIn_Port_TIMER_64    1
#define IODC_DirectIn_Bit_TIMER_64     1
#define IODC_DirectIn_Logic_TIMER_64   IODC_POSITIVE
#endif /* IODC_INPUT_TAUA400_IS_P101 */

#ifdef IODC_INPUT_TAUA402_IS_P102
#define IODC_DirectIn_Port_TIMER_66    1
#define IODC_DirectIn_Bit_TIMER_66     2
#define IODC_DirectIn_Logic_TIMER_66   IODC_POSITIVE
#endif /* IODC_INPUT_TAUA402_IS_P102 */

#ifdef IODC_INPUT_TAUA404_IS_P103
#define IODC_DirectIn_Port_TIMER_68    1
#define IODC_DirectIn_Bit_TIMER_68     3
#define IODC_DirectIn_Logic_TIMER_68   IODC_POSITIVE
#endif /* IODC_INPUT_TAUA404_IS_P103 */

#ifdef IODC_INPUT_TAUA406_IS_P104
#define IODC_DirectIn_Port_TIMER_70    1
#define IODC_DirectIn_Bit_TIMER_70     4
#define IODC_DirectIn_Logic_TIMER_70   IODC_POSITIVE
#endif /* IODC_INPUT_TAUA406_IS_P104 */

#ifdef IODC_INPUT_TAUA408_IS_P105
#define IODC_DirectIn_Port_TIMER_72    1
#define IODC_DirectIn_Bit_TIMER_72     5
#define IODC_DirectIn_Logic_TIMER_72   IODC_POSITIVE
#endif /* IODC_INPUT_TAUA408_IS_P105 */

#ifdef IODC_INPUT_TAUA410_IS_P106
#define IODC_DirectIn_Port_TIMER_74    1
#define IODC_DirectIn_Bit_TIMER_74     6
#define IODC_DirectIn_Logic_TIMER_74   IODC_POSITIVE
#endif /* IODC_INPUT_TAUA410_IS_P106 */

#ifdef IODC_INPUT_TAUA412_IS_P108
#define IODC_DirectIn_Port_TIMER_76    1
#define IODC_DirectIn_Bit_TIMER_76     7
#define IODC_DirectIn_Logic_TIMER_76   IODC_POSITIVE
#endif /* IODC_INPUT_TAUA412_IS_P107 */

#ifdef IODC_INPUT_TAUA414_IS_P108
#define IODC_DirectIn_Port_TIMER_78    1
#define IODC_DirectIn_Bit_TIMER_78     8
#define IODC_DirectIn_Logic_TIMER_78   IODC_POSITIVE
#endif /* IODC_INPUT_TAUA414_IS_P108 */

#ifdef IODC_INPUT_TAUA400_IS_P308
#define IODC_DirectIn_Port_TIMER_64    3
#define IODC_DirectIn_Bit_TIMER_64     8
#define IODC_DirectIn_Logic_TIMER_64   IODC_POSITIVE
#endif /* IODC_INPUT_TAUA400_IS_P308 */

#ifdef IODC_INPUT_TAUA402_IS_P309
#define IODC_DirectIn_Port_TIMER_66    3
#define IODC_DirectIn_Bit_TIMER_66     9
#define IODC_DirectIn_Logic_TIMER_66   IODC_POSITIVE
#endif /* IODC_INPUT_TAUA402_IS_P309 */

#ifdef IODC_INPUT_TAUA404_IS_P310
#define IODC_DirectIn_Port_TIMER_68    3
#define IODC_DirectIn_Bit_TIMER_68     10
#define IODC_DirectIn_Logic_TIMER_68   IODC_POSITIVE
#endif /* IODC_INPUT_TAUA404_IS_P310 */

#ifdef IODC_INPUT_TAUA406_IS_P311
#define IODC_DirectIn_Port_TIMER_70    3
#define IODC_DirectIn_Bit_TIMER_70     11
#define IODC_DirectIn_Logic_TIMER_70   IODC_POSITIVE
#endif /* IODC_INPUT_TAUA406_IS_P311 */

#ifdef IODC_INPUT_TAUA408_IS_P312
#define IODC_DirectIn_Port_TIMER_72    3
#define IODC_DirectIn_Bit_TIMER_72     12
#define IODC_DirectIn_Logic_TIMER_72   IODC_POSITIVE
#endif /* IODC_INPUT_TAUA408_IS_P312 */

#ifdef IODC_INPUT_TAUA410_IS_P400
#define IODC_DirectIn_Port_TIMER_74    4
#define IODC_DirectIn_Bit_TIMER_74     0
#define IODC_DirectIn_Logic_TIMER_74   IODC_POSITIVE
#endif /* IODC_INPUT_TAUA410_IS_P400 */

#ifdef IODC_INPUT_TAUA412_IS_P401
#define IODC_DirectIn_Port_TIMER_76    4
#define IODC_DirectIn_Bit_TIMER_76     1
#define IODC_DirectIn_Logic_TIMER_76   IODC_POSITIVE
#endif /* IODC_INPUT_TAUA412_IS_P401 */

#ifdef IODC_INPUT_TAUA414_IS_P402
#define IODC_DirectIn_Port_TIMER_78    4
#define IODC_DirectIn_Bit_TIMER_78     2
#define IODC_DirectIn_Logic_TIMER_78   IODC_POSITIVE
#endif /* IODC_INPUT_TAUA414_IS_P402 */

#endif /* !__REL_V850_DK4H__ */

#endif /* (defined(__REL_V850_Dx4__)) */

/*______ G L O B A L - D I R E C T I V E _____________________________________*/

#ifdef __REL_RL78__
#ifdef __REL_RL78_D1x__
#ifdef __REL_RL78_D1A__
#if ((IODC_IT_IRQ0 == _USED_) || \
     (IODC_IT_IRQ1 == _USED_) || \
     (IODC_IT_IRQ2 == _USED_) || \
     (IODC_IT_IRQ3 == _USED_) || \
     (IODC_IT_IRQ4 == _USED_) || \
     (IODC_IT_IRQ5 == _USED_))
#define IODC_IRQ_USED
#endif /* at least one Irq used */
#endif /* __REL_RL78_D1A__ */
#endif /* __REL_RL78_D1x__ */

#ifdef __REL_RL78_F1x__
#ifdef __REL_RL78_F12__
#if ((IODC_IT_IRQ0 == _USED_) || \
     (IODC_IT_IRQ1 == _USED_) || \
     (IODC_IT_IRQ2 == _USED_) || \
     (IODC_IT_IRQ3 == _USED_) || \
     (IODC_IT_IRQ4 == _USED_) || \
     (IODC_IT_IRQ5 == _USED_) || \
	 (IODC_IT_IRQ6 == _USED_) || \
     (IODC_IT_IRQ7 == _USED_) || \
     (IODC_IT_IRQ8 == _USED_) || \
     (IODC_IT_IRQ9 == _USED_) || \
     (IODC_IT_IRQ10 == _USED_) || \
     (IODC_IT_IRQ11 == _USED_))
#define IODC_IRQ_USED
#endif /* at least one Irq used */
#endif /* __REL_RL78_F12__ */
#endif /* __REL_RL78_F1x__ */
#endif /* __REL_RL78__ */

#ifdef __MC9S12xx__
#if ((IODC_IT_IRQ0  == _USED_) || \
     (IODC_IT_IRQ1  == _USED_) || \
     (IODC_IT_IRQ2  == _USED_) || \
     (IODC_IT_IRQ3  == _USED_) || \
     (IODC_IT_IRQ4  == _USED_) || \
     (IODC_IT_IRQ5  == _USED_) || \
     (IODC_IT_IRQ6  == _USED_) || \
     (IODC_IT_IRQ7  == _USED_) || \
     (IODC_IT_IRQ8  == _USED_) || \
     (IODC_IT_IRQ9  == _USED_) || \
     (IODC_IT_IRQ10 == _USED_) || \
     (IODC_IT_IRQ11 == _USED_) || \
     (IODC_IT_IRQ12 == _USED_))
#define IODC_IRQ_USED
#endif /* at least one Irq used */
#endif /* __MC9S12xx__ */

#ifdef __TX49__
#if ( (IODC_IT_IRQ0 == _USED_) || \
      (IODC_IT_IRQ1 == _USED_) || \
      (IODC_IT_IRQ2 == _USED_) || \
      (IODC_IT_IRQ3 == _USED_) )
#define IODC_IRQ_USED
#endif /* at least one Irq used */
#endif /*__TX49__*/

#ifdef __MC9S08xx__
#if ((IODC_IT_IRQ0  == _USED_) || \
     (IODC_IT_IRQ1  == _USED_) || \
     (IODC_IT_IRQ2  == _USED_) || \
     (IODC_IT_IRQ3  == _USED_) || \
     (IODC_IT_IRQ4  == _USED_) || \
     (IODC_IT_IRQ5  == _USED_) || \
     (IODC_IT_IRQ6  == _USED_) || \
     (IODC_IT_IRQ7  == _USED_) || \
     (IODC_IT_IRQPIN  == _USED_))
#define IODC_IRQ_USED
#endif /* at least one Irq used */
#endif /* __MC9S08xx__ */

#ifdef __NEC_V850_Fx3__
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
     (IODC_IT_IRQ15   == _USED_) || \
     (IODC_IT_IRQ_NMI == _USED_))
#define IODC_IRQ_USED
#endif /* at least one Irq used */
#endif /*__NEC_V850_Fx3__*/

#ifdef __NEC_V850_Dx3__
#if ((IODC_IT_IRQ0    == _USED_) || \
     (IODC_IT_IRQ1    == _USED_) || \
     (IODC_IT_IRQ2    == _USED_) || \
     (IODC_IT_IRQ3    == _USED_) || \
     (IODC_IT_IRQ4    == _USED_) || \
     (IODC_IT_IRQ5    == _USED_) || \
     (IODC_IT_IRQ6    == _USED_) || \
     (IODC_IT_IRQ7    == _USED_) || \
     (IODC_IT_IRQ_NMI == _USED_))
#define IODC_IRQ_USED
#endif /* at least one Irq used */
#endif /*__NEC_V850_Dx3__*/

#ifdef __REL_V850_Dx4__
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
     (IODC_IT_IRQ_NMI == _USED_))
#define IODC_IRQ_USED
#endif /* at least one Irq used */
#endif /*__REL_V850_Dx4__*/


#if defined(__FSL_IMX53x__) || defined(__FSL_IMX6x__)
#if ((IODC_IT_IRQ0   == _USED_) || \
     (IODC_IT_IRQ1   == _USED_) || \
     (IODC_IT_IRQ2   == _USED_) || \
     (IODC_IT_IRQ3   == _USED_) || \
     (IODC_IT_IRQ4   == _USED_) || \
     (IODC_IT_IRQ5   == _USED_) || \
     (IODC_IT_IRQ6   == _USED_) || \
     (IODC_IT_IRQ7   == _USED_) || \
     (IODC_IT_IRQ8   == _USED_) || \
     (IODC_IT_IRQ9   == _USED_) || \
     (IODC_IT_IRQ10  == _USED_) || \
     (IODC_IT_IRQ11  == _USED_) || \
     (IODC_IT_IRQ12  == _USED_) || \
     (IODC_IT_IRQ13  == _USED_) || \
     (IODC_IT_IRQ14  == _USED_) || \
     (IODC_IT_IRQ15  == _USED_) || \
     (IODC_IT_IRQ16  == _USED_) || \
     (IODC_IT_IRQ17  == _USED_) || \
     (IODC_IT_IRQ18  == _USED_) || \
     (IODC_IT_IRQ19  == _USED_) || \
     (IODC_IT_IRQ20  == _USED_) || \
     (IODC_IT_IRQ21  == _USED_) || \
     (IODC_IT_IRQ22  == _USED_) || \
     (IODC_IT_IRQ23  == _USED_) || \
     (IODC_IT_IRQ24  == _USED_) || \
     (IODC_IT_IRQ25  == _USED_) || \
     (IODC_IT_IRQ26  == _USED_) || \
     (IODC_IT_IRQ27  == _USED_) || \
     (IODC_IT_IRQ28  == _USED_) || \
     (IODC_IT_IRQ29  == _USED_) || \
     (IODC_IT_IRQ30  == _USED_) || \
     (IODC_IT_IRQ31  == _USED_) || \
     (IODC_IT_IRQ32  == _USED_) || \
     (IODC_IT_IRQ33  == _USED_) || \
     (IODC_IT_IRQ34  == _USED_) || \
     (IODC_IT_IRQ35  == _USED_) || \
     (IODC_IT_IRQ36  == _USED_) || \
     (IODC_IT_IRQ37  == _USED_) || \
     (IODC_IT_IRQ38  == _USED_) || \
     (IODC_IT_IRQ39  == _USED_) || \
     (IODC_IT_IRQ40  == _USED_) || \
     (IODC_IT_IRQ41  == _USED_) || \
     (IODC_IT_IRQ42  == _USED_) || \
     (IODC_IT_IRQ43  == _USED_) || \
     (IODC_IT_IRQ44  == _USED_) || \
     (IODC_IT_IRQ45  == _USED_) || \
     (IODC_IT_IRQ46  == _USED_) || \
     (IODC_IT_IRQ47  == _USED_) || \
     (IODC_IT_IRQ48  == _USED_) || \
     (IODC_IT_IRQ49  == _USED_) || \
     (IODC_IT_IRQ50  == _USED_) || \
     (IODC_IT_IRQ51  == _USED_) || \
     (IODC_IT_IRQ52  == _USED_) || \
     (IODC_IT_IRQ53  == _USED_) || \
     (IODC_IT_IRQ54  == _USED_) || \
     (IODC_IT_IRQ55  == _USED_) || \
     (IODC_IT_IRQ56  == _USED_) || \
     (IODC_IT_IRQ57  == _USED_) || \
     (IODC_IT_IRQ58  == _USED_) || \
     (IODC_IT_IRQ59  == _USED_) || \
     (IODC_IT_IRQ60  == _USED_) || \
     (IODC_IT_IRQ61  == _USED_) || \
     (IODC_IT_IRQ62  == _USED_) || \
     (IODC_IT_IRQ63  == _USED_) || \
     (IODC_IT_IRQ64  == _USED_) || \
     (IODC_IT_IRQ65  == _USED_) || \
     (IODC_IT_IRQ66  == _USED_) || \
     (IODC_IT_IRQ67  == _USED_) || \
     (IODC_IT_IRQ68  == _USED_) || \
     (IODC_IT_IRQ69  == _USED_) || \
     (IODC_IT_IRQ70  == _USED_) || \
     (IODC_IT_IRQ71  == _USED_) || \
     (IODC_IT_IRQ72  == _USED_) || \
     (IODC_IT_IRQ73  == _USED_) || \
     (IODC_IT_IRQ74  == _USED_) || \
     (IODC_IT_IRQ75  == _USED_) || \
     (IODC_IT_IRQ76  == _USED_) || \
     (IODC_IT_IRQ77  == _USED_) || \
     (IODC_IT_IRQ78  == _USED_) || \
     (IODC_IT_IRQ79  == _USED_) || \
     (IODC_IT_IRQ80  == _USED_) || \
     (IODC_IT_IRQ81  == _USED_) || \
     (IODC_IT_IRQ82  == _USED_) || \
     (IODC_IT_IRQ83  == _USED_) || \
     (IODC_IT_IRQ84  == _USED_) || \
     (IODC_IT_IRQ85  == _USED_) || \
     (IODC_IT_IRQ86  == _USED_) || \
     (IODC_IT_IRQ87  == _USED_) || \
     (IODC_IT_IRQ88  == _USED_) || \
     (IODC_IT_IRQ89  == _USED_) || \
     (IODC_IT_IRQ90  == _USED_) || \
     (IODC_IT_IRQ91  == _USED_) || \
     (IODC_IT_IRQ92  == _USED_) || \
     (IODC_IT_IRQ93  == _USED_) || \
     (IODC_IT_IRQ94  == _USED_) || \
     (IODC_IT_IRQ95  == _USED_) || \
     (IODC_IT_IRQ96  == _USED_) || \
     (IODC_IT_IRQ97  == _USED_) || \
     (IODC_IT_IRQ98  == _USED_) || \
     (IODC_IT_IRQ99  == _USED_) || \
     (IODC_IT_IRQ100 == _USED_) || \
     (IODC_IT_IRQ101 == _USED_) || \
     (IODC_IT_IRQ102 == _USED_) || \
     (IODC_IT_IRQ103 == _USED_) || \
     (IODC_IT_IRQ104 == _USED_) || \
     (IODC_IT_IRQ105 == _USED_) || \
     (IODC_IT_IRQ106 == _USED_) || \
     (IODC_IT_IRQ107 == _USED_) || \
     (IODC_IT_IRQ108 == _USED_) || \
     (IODC_IT_IRQ109 == _USED_) || \
     (IODC_IT_IRQ110 == _USED_) || \
     (IODC_IT_IRQ111 == _USED_) || \
     (IODC_IT_IRQ112 == _USED_) || \
     (IODC_IT_IRQ113 == _USED_) || \
     (IODC_IT_IRQ114 == _USED_) || \
     (IODC_IT_IRQ115 == _USED_) || \
     (IODC_IT_IRQ116 == _USED_) || \
     (IODC_IT_IRQ117 == _USED_) || \
     (IODC_IT_IRQ118 == _USED_) || \
     (IODC_IT_IRQ119 == _USED_) || \
     (IODC_IT_IRQ120 == _USED_) || \
     (IODC_IT_IRQ121 == _USED_) || \
     (IODC_IT_IRQ122 == _USED_) || \
     (IODC_IT_IRQ123 == _USED_) || \
     (IODC_IT_IRQ124 == _USED_) || \
     (IODC_IT_IRQ125 == _USED_) || \
     (IODC_IT_IRQ126 == _USED_) || \
     (IODC_IT_IRQ127 == _USED_))
#define IODC_IRQ_USED _USED_
#endif /* at least one Irq used */
#endif /* __FSL_IMX53x__ , __FSL_IMX6x__*/

#define IODC_LINE_BY_PORT               (_NOT_USED_ + 1)
#define IODC_LINE_BY_SHIFT_REGISTER     (_NOT_USED_ + 2)
#define IODC_LED_MATRIX_DIRECT_REFRESH  (_NOT_USED_ + 3)
#define IODC_LED_MATRIX_ISR_REFRESH     (_NOT_USED_ + 4)
#define IODC_LED_MATRIX_TASK_REFRESH    (_NOT_USED_ + 5)

#define IODC_INPUT_MATRIX_ISR_REFRESH       (_NOT_USED_ + 1)
#define IODC_INPUT_MATRIX_POOLING_REFRESH   (_NOT_USED_ + 2)


#if IODC_LED_MATRIX_TYPE != _NOT_USED_

#define IODC_LED_MATRIX_USED _USED_

#if IODC_LED_MATRIX_TYPE == IODC_LINE_BY_PORT
#define IODC_DIRECT_ACCESS_USED
#else
#define IODC_SHIFT_REGISTER_ACCESS_USED
#if IODC_LED_MATRIX_REFRESH == IODC_LED_MATRIX_TASK_REFRESH || \
    IODC_LED_MATRIX_REFRESH == IODC_LED_MATRIX_DIRECT_REFRESH
#define IODC_LED_MATRIX_TASK_REFRESH_USED
#endif /* IODC_LED_MATRIX_REFRESH == IODC_LED_MATRIX_TASK_REFRESH ||
          IODC_LED_MATRIX_REFRESH == IODC_LED_MATRIX_DIRECT_REFRESH */
#endif /* IODC_LED_MATRIX_TYPE == IODC_LINE_BY_PORT */

#endif /* IODC_LED_MATRIX_TYPE != _NOT_USED_ */


/*______ G L O B A L - M A C R O S ___________________________________________*/

/*----------------------------------------------------------------------------*/
/*Name : IODC_GetPinStatus                                                    */
/*Role : Read the pin status                                                  */
/*Interface :                                                                 */
/*  - IN  : number of input                                                   */
/*  - OUT : state of the input (TRUE, FALSE)                                  */
/*Pre-condition : -                                                           */
/*Constraints : -                                                             */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [read the real pin state (not its IN/OUT buffer content) of the         */
/*     requested input]                                                       */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#define IODC_GetPinStatus(VirtualId) \
        ((ubyte)\
         ( IODD_GetPinStatus(IODC_DirectIn_Port_ ## VirtualId, \
                           IODC_DirectIn_Bit_ ## VirtualId) == \
           IODC_DirectIn_Logic_ ## VirtualId ))

/*----------------------------------------------------------------------------*/
/*Name : IODC_GetInputDataDirect                                              */
/*Role : Read the not filtered state of a virtual input                       */
/*Interface :                                                                 */
/*  - IN  : number of input                                                   */
/*  - OUT : state of the input (TRUE, FALSE)                                  */
/*Pre-condition : -                                                           */
/*Constraints : -                                                             */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [read the not filtered state of the requested input]                    */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
/*PROC IODC_GetInputDataDirect                                                */
/*  (                                                                         */
/*  IN : VirtualPinId (UBYTE)                                                 */
/*  OUT : StateOfPin (IODC_ACTIVE, IODC_INACTIVE)                             */
/*  )                                                                         */
/*                                                                            */
/*DATA                                                                        */
/*ATAD                                                                        */
/*                                                                            */
/*DO                                                                          */
/*   [read the not filtered state of the requested input] =                   */
/*   DO                                                                       */
/*     StateOfPin := [ read with IODD_GetPinData service ]                    */
/*     [ return StateOfPin = [ type of logic of VirtualPinId ] ]              */
/*   OD                                                                       */
/*OD                                                                          */
/*----------------------------------------------------------------------------*/
#define IODC_GetInputDataDirect(VirtualId) \
        ((ubyte)\
         ( IODD_GetPinData(IODC_DirectIn_Port_ ## VirtualId, \
                           IODC_DirectIn_Bit_ ## VirtualId) == \
           IODC_DirectIn_Logic_ ## VirtualId ))

/*----------------------------------------------------------------------------*/
/*Name : IODC_GetInputDataMultiplex                                           */
/*Role : Read the state of a switch input located in a matrix                 */
/*Interface :                                                                 */
/*  - IN  : name of the switch                                                */
/*  - OUT : state of the input (TRUE, FALSE)                                  */
/*Pre-condition : -                                                           */
/*Constraints : state in cleared after reading                                */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [read the state of the requested input]                                 */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
/*PROC IODC_GetInputDataMultiplex                                             */
/*  (                                                                         */
/*  IN : VirtualSwitchId (UBYTE)                                              */
/*  OUT : StateOfPin (IODC_ACTIVE, IODC_INACTIVE)                             */
/*  )                                                                         */
/*                                                                            */
/*DATA                                                                        */
/*ATAD                                                                        */
/*                                                                            */
/*DO                                                                          */
/*   [read the state of the requested switch] =                               */
/*   DO                                                                       */
/*     IF (switch state (tab of matrix scanned) is off)                       */
/*     THEN                                                                   */
/*       [clear switch state in tab AND return FALSE]                         */
/*     ELSE                                                                   */
/*       [clear switch state in tab AND return TRUE]                          */
/*   OD                                                                       */
/*OD                                                                          */
/*----------------------------------------------------------------------------*/
#define IODC_GetInputDataMultiplex(VirtualId, MatrixNb) \
        IODC_GetInputDataMux ## MatrixNb (VirtualId)

#define IODC_GetInputDataMux1(VirtualId) \
        ((bool_t)( ( ( IODC_TabStateButtonMatrix1[IODC_MuxIn_Column_ ## VirtualId]._byte &  ((ubyte)(  0x01 << IODC_MuxIn_Line_ ## VirtualId))  ) == FALSE ) ? \
                   ( ( IODC_TabStateButtonMatrix1[IODC_MuxIn_Column_ ## VirtualId]._byte &= ((ubyte)(~(0x01 << IODC_MuxIn_Line_ ## VirtualId))) ) ,  FALSE ) : \
                   ( ( IODC_TabStateButtonMatrix1[IODC_MuxIn_Column_ ## VirtualId]._byte &= ((ubyte)(~(0x01 << IODC_MuxIn_Line_ ## VirtualId))) ) ,  TRUE  ) ))

#define IODC_GetInputDataMux2(VirtualId) \
        ((bool_t)( ( ( IODC_TabStateButtonMatrix2[IODC_MuxIn_Column_ ## VirtualId]._byte &  ((ubyte)(  0x01 << IODC_MuxIn_Line_ ## VirtualId))  ) == FALSE ) ? \
                   ( ( IODC_TabStateButtonMatrix2[IODC_MuxIn_Column_ ## VirtualId]._byte &= ((ubyte)(~(0x01 << IODC_MuxIn_Line_ ## VirtualId))) ) ,  FALSE ) : \
                   ( ( IODC_TabStateButtonMatrix2[IODC_MuxIn_Column_ ## VirtualId]._byte &= ((ubyte)(~(0x01 << IODC_MuxIn_Line_ ## VirtualId))) ) ,  TRUE  ) ))

/*----------------------------------------------------------------------------*/
/*Name : IODC_GetRotarySwitchData                                             */
/*Role : Read the state of a switch wich composed a rotary button located in  */
/*       a matrix                                                             */
/*Interface :                                                                 */
/*  - IN  : name of the switch                                                */
/*  - IN  : number of the matrix where the switch is                          */
/*  - OUT : state of the input (TRUE, FALSE)                                  */
/*Pre-condition : -                                                           */
/*Constraints : -                                                             */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [read the state of the requested input]                                 */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
/*PROC IODC_GetRotarySwitchData                                               */
/*  (                                                                         */
/*  IN : VirtualSwitchId (UBYTE)                                              */
/*  OUT : StateOfPin (IODC_ACTIVE, IODC_INACTIVE)                             */
/*  )                                                                         */
/*                                                                            */
/*DATA                                                                        */
/*ATAD                                                                        */
/*                                                                            */
/*DO                                                                          */
/*   [read the state of the requested switch] =                               */
/*   DO                                                                       */
/*     Return the state of the swich which was store in the tab at the        */
/*     matrix scan                                                            */
/*   OD                                                                       */
/*OD                                                                          */
/*----------------------------------------------------------------------------*/
#define IODC_GetRotarySwitchData(VirtualId,RtrIndex) \
        IODC_GetRotarySwitch_ ## VirtualId(VirtualId,RtrIndex)


#define IODC_GetRotarySwitch_swa1(VirtualId,RtrIndex) \
        ((ubyte)\
        ( (IODC_TabStateInputMatrix1 [(RtrIndex)]._byte) &\
                                     ((0x01) << ( IODC_MuxIn_Line_ ## VirtualId )) )\
        )

#define IODC_GetRotarySwitch_swb1(VirtualId,RtrIndex) \
        ((ubyte)\
        ( (IODC_TabStateInputMatrix1 [(RtrIndex)]._byte) &\
                                     ((0x01) << ( IODC_MuxIn_Line_ ## VirtualId )) )\
        )

#define IODC_GetRotarySwitch_swc1(VirtualId,RtrIndex) \
        ((ubyte)\
        ( (IODC_TabStateInputMatrix1 [(RtrIndex)]._byte ) &\
                                     ((0x01) << ( IODC_MuxIn_Line_ ## VirtualId )) )\
        )

#define IODC_GetRotarySwitch_swd1(VirtualId,RtrIndex) \
        ((ubyte)\
        ( (IODC_TabStateInputMatrix1 [(RtrIndex)]._byte ) &\
                                     ((0x01) << ( IODC_MuxIn_Line_ ## VirtualId )) )\
        )

#define IODC_GetRotarySwitch_swa2(VirtualId,RtrIndex) \
        ((ubyte)\
        ( (IODC_TabStateInputMatrix2 [(RtrIndex)]._byte ) &\
                                     ((0x01) << ( IODC_MuxIn_Line_ ## VirtualId )) )\
        )

#define IODC_GetRotarySwitch_swb2(VirtualId,RtrIndex) \
        ((ubyte)\
        ( (IODC_TabStateInputMatrix2 [(RtrIndex)]._byte ) &\
                                     ((0x01) << ( IODC_MuxIn_Line_ ## VirtualId )) )\
        )

#define IODC_GetRotarySwitch_swc2(VirtualId,RtrIndex) \
        ((ubyte)\
        ( (IODC_TabStateInputMatrix2 [(RtrIndex)]._byte ) &\
                                     ((0x01) << ( IODC_MuxIn_Line_ ## VirtualId )) )\
        )

#define IODC_GetRotarySwitch_swd2(VirtualId,RtrIndex) \
        ((ubyte)\
        ( (IODC_TabStateInputMatrix2 [(RtrIndex)]._byte ) &\
                                     ((0x01) << ( IODC_MuxIn_Line_ ## VirtualId )) )\
        )

/*----------------------------------------------------------------------------*/
/*Name : IODC_GetMatrixIndex                                                  */
/*Role : Return the last position in the matrix buffer                        */
/*Interface :                                                                 */
/*  - IN  :                                                                   */
/*  - OUT : Number of the index                                               */
/*Pre-condition : -                                                           */
/*Constraints : -                                                             */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#define IODC_GetMatrixIndex()\
        ((ubyte) (IODC_IndexMatrix))

/*----------------------------------------------------------------------------*/
/*Name : IODC_ResetMatrixIndex                                                */
/*Role : Return the last position in the matrix buffer                        */
/*Interface :                                                                 */
/*  - IN  :                                                                   */
/*  - OUT : Number of the index                                               */
/*Pre-condition : -                                                           */
/*Constraints : -                                                             */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#define IODC_ResetMatrixIndex()\
        (IODC_IndexMatrix = 0)

/*----------------------------------------------------------------------------*/
/*Name : IODC_GetLastNoRotaryIndex                                            */
/*Role : Return the last index where it scan a button column                  */
/*Interface :                                                                 */
/*  - IN  :                                                                   */
/*  - OUT : Number of the index                                               */
/*Pre-condition : -                                                           */
/*Constraints : -                                                             */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#define IODC_GetLastNoRotaryIndex()\
        ((ubyte) (IODC_LastNoRotaryIndex1))

/*----------------------------------------------------------------------------*/
/*Name : IODC_GetLastNoRotaryIndex                                            */
/*Role : Return the last index where it scan a button column                  */
/*Interface :                                                                 */
/*  - IN  :                                                                   */
/*  - OUT : Number of the column of button wich was scan for the last time    */
/*Pre-condition : -                                                           */
/*Constraints : -                                                             */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#define IODC_GetTheLastButtonColumnScanned()\
        ((ubyte) (IODC_LastNoRotaryColumn1))

/*----------------------------------------------------------------------------*/
/*Name : IODC_SetOuputData                                                    */
/*Role : Set a state on a virtual output                                      */
/*Interface :                                                                 */
/*  - IN : number of output                                                   */
/*  - IN : requested state (IODC_ACTIVE, IODC_INACTIVE)                       */
/*Pre-condition : -                                                           */
/*Constraints : -                                                             */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [set requested state on the requested output]                           */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
/*PROC IODC_SetOuputData                                                      */
/*  (                                                                         */
/*  IN VirtualPinId (UBYTE)                                                   */
/*  IN StateInOutput (IODC_ACTIVE, IODC_INACTIVE) (UBYTE)                     */
/*  )                                                                         */
/*                                                                            */
/*DATA                                                                        */
/*ATAD                                                                        */
/*                                                                            */
/*DO                                                                          */
/*  IF (StateInOutput = IODC_ACTIVE)                                          */
/*  THEN                                                                      */
/*    [ set pin to logic state given by configuration ]                       */
/*  ELSE                                                                      */
/*    [ set pin to NOT logic state given by configuration ]                   */
/*  FI                                                                        */
/*OD                                                                          */
/*----------------------------------------------------------------------------*/
#define IODC_SetOutputData(VirtualId,\
                           State) \
        IODC_SelectOutputType(IODC_GetOutputType(VirtualId), \
                              _OUTPUT, \
                              VirtualId, \
                              State)

/* sub-macros used by IODC_SetOutputData in function the output type */

/*Role : Set a state on a led which is drive by a matrix                      */
/*Interface :                                                                 */
/*  - IN : Column where the led is connected                                  */
/*  - IN : Line where the led is connected                                    */
/*  - IN : State of the led                                                   */
#define IODC_DriveLedMatrix(Column, \
                            Line,   \
                            State)  \
        IODC_SetLedState(Column, Line, State)

#define IODC_SetLedState(Column, \
                         Line,   \
                         State)  \
        ( *(IODC_LedStateType_t *)&(IODC_TabStateLed[(Column)]) )._bit.BIT ## Line = (State)

#define IODC_GetOutputType(VirtualId) \
        IODC_Out_Type_ ## VirtualId

#define IODC_SelectOutputType(Type, Action, VirtualId, State) \
        IODC_SetOutputAction(Type, Action, VirtualId, State)

#define IODC_SetOutputAction(Type, Action, VirtualId, State ) \
        Type ## Action(VirtualId, State)


/* direct output */
#define IODC_NORMAL_OUTPUT(VirtualId, State)         \
        IODD_SetPinData(IODC_Out_Port_ ## VirtualId, \
                        IODC_Out_Bit_ ## VirtualId,  \
                        (ubyte)(IODC_Out_Logic_ ## VirtualId == (State)))

/* direct output with setup refresh */
#define IODC_NORMAL_SETUP_REFRESH_OUTPUT(VirtualId, State) \
        IODD_PinSetUpOutput(IODC_Out_Port_ ## VirtualId,   \
                            IODC_Out_Bit_ ## VirtualId,    \
                            IODC_Out_Drain_ ## VirtualId); \
        IODD_SetPinData(IODC_Out_Port_ ## VirtualId,       \
                        IODC_Out_Bit_ ## VirtualId,        \
                        (ubyte)(IODC_Out_Logic_ ## VirtualId == (State)))

/* option dependent direct output */
#define IODC_SEL_NORMAL_OUTPUT(VirtualId, State) \
        { \
          if (IODC_Out_Option_ ## VirtualId == TRUE) \
          { \
            IODC_NORMAL_OUTPUT(VirtualId,State);\
          } \
        }

/* Multiplexed output */
#if defined(IODC_LED_MATRIX_USED)
#if (IODC_LED_MATRIX_REFRESH == IODC_LED_MATRIX_DIRECT_REFRESH)

/* Led matrix is refreshed on-call and (for robustness) by task */
#define IODC_BYMATRIX_OUTPUT(VirtualId,\
                             State) \
        IODC_DriveLedMatrix(IODC_Out_Column_ ## VirtualId, \
                            IODC_Out_Line_ ## VirtualId, \
                            (ubyte)((State) == IODC_Out_Logic_ ## VirtualId)); \
        IODC_RefreshLedMatrix()

#else /* for IODC_LED_MATRIX_ISR_REFRESH or IODC_LED_MATRIX_TASK_REFRESH */

/* Led matrix is refreshed by an periodical interrupt or by task */
#define IODC_BYMATRIX_OUTPUT(VirtualId,\
                             State) \
        IODC_DriveLedMatrix(IODC_Out_Column_ ## VirtualId, \
                            IODC_Out_Line_ ## VirtualId, \
                            (ubyte)((State) == IODC_Out_Logic_ ## VirtualId))

#endif /* IODC_LED_MATRIX_REFRESH == IODC_LED_MATRIX_DIRECT_REFRESH */
#endif /* IODC_LED_MATRIX_USED */


/* option dependent output */

#define IODC_SEL_BYMATRIX_OUTPUT(VirtualId,\
                            State) \
        { \
          if (IODC_Out_Option_ ## VirtualId == TRUE) \
          { \
            IODC_BYMATRIX_OUTPUT(VirtualId,State);\
          } \
        }

#define IODC_DYNAMIC_OUTPUT(VirtualId,\
                            State) \
        { \
          if (IODC_Out_Option_ ## VirtualId == TRUE) \
          { \
            if (IODC_Out_Select_ ## VirtualId == FALSE) \
            { \
              IODC_NORMAL_OUTPUT(VirtualId,State);\
            } \
            else \
            { \
              IODC_BYMATRIX_OUTPUT(VirtualId,State);\
            } \
          } \
        }

/*----------------------------------------------------------------------------*/
/*Name : IODC_GetInputDataDirectEOL                                           */
/*Role : Read the not filtered state of a virtual input without use logic     */
/*Interface :                                                                 */
/*  - IN  : number of input                                                   */
/*  - OUT : state of the input (TRUE, FALSE)                                  */
/*Pre-condition : -                                                           */
/*Constraints : -                                                             */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [read the not filtered state of the requested input]                    */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#ifdef __EOL_ENABLE__
#if IODC_EOL_INPUT_LOGIC == _USED_
#define IODC_GetInputDataDirectEOL(VirtualId) \
        IODC_GetInputDataDirect(VirtualId)
#else
#define IODC_GetInputDataDirectEOL(VirtualId) \
        ((ubyte)( IODD_GetPinData(IODC_DirectIn_Port_ ## VirtualId, \
                                  IODC_DirectIn_Bit_ ## VirtualId) ))
#endif /* IODC_EOL_INPUT_LOGIC == _USED_*/
#endif /* __EOL_ENABLE__ */

/*----------------------------------------------------------------------------*/
/*Name : IODC_SetOuputDataEOL                                                 */
/*Role : Set to 1 or 0 a virtual output pin according to the state provided as*/
/*       parameter                                                            */
/*      (the otput state is independent to the logic state of the pin)        */
/*Interface :                                                                 */
/*  - IN : number of output                                                   */
/*  - IN : requested state (IODC_ACTIVE, IODC_INACTIVE)                       */
/*Pre-condition : -                                                           */
/*Constraints : -                                                             */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [set requested state on the requested output]                           */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#ifdef __EOL_ENABLE__
#define IODC_SetOutputDataEOL(VirtualId,\
                              State)\
        IODC_SetOutputData(VirtualId,State)
#endif /* __EOL_ENABLE__ */

/*----------------------------------------------------------------------------*/
/*Name : IODC_SetPinDirectionIn                                               */
/*Role : Set pin in input                                                     */
/*Interface :                                                                 */
/*  - IN  : PIN Identifier                                                    */
/*Pre-condition : -                                                           */
/*Constraints :  -                                                            */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [set the requested pin in input]                                        */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#define IODC_SetPinDirectionIn(VirtualId) \
        IODD_SetPinDirectionIn(IODC_DirectIn_Port_ ## VirtualId,\
                               IODC_DirectIn_Bit_ ## VirtualId)

/*----------------------------------------------------------------------------*/
/*Name : IODC_SetPinDirectionOut                                              */
/*Role : Set pin in output                                                    */
/*Interface :                                                                 */
/*  - IN  : PIN Identifier                                                    */
/*Pre-condition : -                                                           */
/*Constraints :  -                                                            */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [set the requested pin in output]                                       */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#define IODC_SetPinDirectionOut(VirtualId) \
        IODD_SetPinDirectionOut(IODC_Out_Port_ ## VirtualId,\
                                IODC_Out_Bit_ ## VirtualId)

/*----------------------------------------------------------------------------*/
/*Name : IODC_SetPortDirectionIn                                              */
/*Role : Set 8-bits port in input                                             */
/*Interface :                                                                 */
/*  - PortName  IN, name of port [see IODD]                                   */
/*Pre-condition : -                                                           */
/*Constraints :  -                                                            */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [set the requested port in input]                                       */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#define IODC_SetPortDirectionIn(PortName)  IODD_SetPortDirectionIn(PortName)

/*----------------------------------------------------------------------------*/
/*Name : IODC_SetPortDirectionOut                                             */
/*Role : Set 8-bits port in output                                            */
/*Interface :                                                                 */
/*  - PortName  IN, name of port [see IODD]                                   */
/*Pre-condition : -                                                           */
/*Constraints :  -                                                            */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [set the requested port in output]                                      */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#define IODC_SetPortDirectionOut(PortName)  IODD_SetPortDirectionOut(PortName)

/*----------------------------------------------------------------------------*/
/*Name : IODC_ReadBytePortIn                                                  */
/*Role : Read an 8-bits port                                                  */
/*Interface :                                                                 */
/*  - PortName  IN, name of port [see IODD]                                   */
/*Pre-condition : -                                                           */
/*Constraints :  can not read an output port                                  */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [read the requested port]                                               */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#define IODC_ReadBytePortIn(PortName)  IODD_ReadBytePortIn(PortName)

/*----------------------------------------------------------------------------*/
/*Name : IODC_ReadShortPortIn                                                  */
/*Role : Read an 16-bits port                                                  */
/*Interface :                                                                 */
/*  - PortName  IN, name of port [see IODD]                                   */
/*Pre-condition : -                                                           */
/*Constraints :  can not read an output port                                  */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [read the requested port]                                               */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#define IODC_ReadShortPortIn(PortName)  IODD_ReadShortPortIn(PortName)

/*----------------------------------------------------------------------------*/
/*Name : IODC_WriteBytePortOut                                                */
/*Role : Write into 8-bits port                                               */
/*Interface :                                                                 */
/*  - PortName  IN, name of port [see IODD]                                   */
/*  - Value     IN, ubyte value                                               */
/*Pre-condition : -                                                           */
/*Constraints :  -                                                            */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [write the requested port]                                              */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#define IODC_WriteBytePortOut(PortName,\
                              Value)   \
        IODD_WriteBytePortOut(PortName,\
                              Value)
							  
							  
/*----------------------------------------------------------------------------*/
/*Name : IODC_WriteShortPortOut                                                */
/*Role : Write into 16-bits port                                               */
/*Interface :                                                                 */
/*  - PortName  IN, name of port [see IODD]                                   */
/*  - Value     IN, ubyte value                                               */
/*Pre-condition : -                                                           */
/*Constraints :  -                                                            */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [write the requested port]                                              */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#define IODC_WriteShortPortOut(PortName,\
                              Value)   \
        IODD_WriteShortPortOut(PortName,\
                              Value)

/*----------------------------------------------------------------------------*/
/* Name : IODC_EnableIrq                                                      */
/* Role : Enable interrupt request                                            */
/* Interface :                                                                */
/*   - IrqName IN, name of Irq for                                            */
/*                                 Motorola STAR12                            */
/*                                 [IODC_IRQ0..IODC_IRQ12]                    */
/* Pre-condition : -                                                          */
/* Constraints : -                                                            */
/* Behavior :                                                                 */
/*   DO                                                                       */
/*     [enable interrupt requested]                                           */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/
#if defined(__FSL_IMX53x__) || defined(__FSL_IMX6x__)
#define IODC_EnableIrq(IrqName) IODD_EnableIrq(IrqName)
#else
#ifndef __CY_TV2__
#define IODC_EnableIrq(IrqName) IODC_EnableIrq_ ## IrqName
#endif /*__CY_TV2__*/
#endif /* __FSL_IMX53x__, __FSL_IMX6x__ */

#if (defined(__MC9S12xx__))
#define IODC_EnableIrq_IODC_IRQ0   IODD_EnableIrq(IODD_IRQ0)
#define IODC_EnableIrq_IODC_IRQ1   IODD_EnableIrq(IODD_IRQ1)
#define IODC_EnableIrq_IODC_IRQ2   IODD_EnableIrq(IODD_IRQ2)
#define IODC_EnableIrq_IODC_IRQ3   IODD_EnableIrq(IODD_IRQ3)
#define IODC_EnableIrq_IODC_IRQ4   IODD_EnableIrq(IODD_IRQ4)
#define IODC_EnableIrq_IODC_IRQ5   IODD_EnableIrq(IODD_IRQ5)
#define IODC_EnableIrq_IODC_IRQ6   IODD_EnableIrq(IODD_IRQ6)
#define IODC_EnableIrq_IODC_IRQ7   IODD_EnableIrq(IODD_IRQ7)
#define IODC_EnableIrq_IODC_IRQ8   IODD_EnableIrq(IODD_IRQ8)
/* --- MC9S12-H variant --- */
#if defined(__MC9S12H__)
#define IODC_EnableIrq_IODC_IRQ9   IODD_EnableIrq(IODD_IRQ9)
#define IODC_EnableIrq_IODC_IRQ10  IODD_EnableIrq(IODD_IRQ10)
#define IODC_EnableIrq_IODC_IRQ11  IODD_EnableIrq(IODD_IRQ11)
#define IODC_EnableIrq_IODC_IRQ12  IODD_EnableIrq(IODD_IRQ12)
#endif /* defined(__MC9S12H__) */
#endif /* (defined(__MC9S12xx__)) */

#if (defined(__MC9S08xx__))
#define IODC_EnableIrq_IODC_IRQPIN IODD_EnableIrq(IODD_IRQPIN)

#define IODC_EnableIrq_IODC_IRQ1   IODD_EnableIrq(IODD_IRQ1)
#define IODC_EnableIrq_IODC_IRQ2   IODD_EnableIrq(IODD_IRQ2)
#define IODC_EnableIrq_IODC_IRQ3   IODD_EnableIrq(IODD_IRQ3)
#define IODC_EnableIrq_IODC_IRQ4   IODD_EnableIrq(IODD_IRQ4)
#define IODC_EnableIrq_IODC_IRQ5   IODD_EnableIrq(IODD_IRQ5)
#define IODC_EnableIrq_IODC_IRQ6   IODD_EnableIrq(IODD_IRQ6)
#define IODC_EnableIrq_IODC_IRQ7   IODD_EnableIrq(IODD_IRQ7)
#endif /* (defined(__MC9S08xx__)) */

#ifdef __TX49__
#define IODC_EnableIrq_IODC_IRQ0  IODD_EnableIrq(IODD_IRQ0)
#define IODC_EnableIrq_IODC_IRQ1  IODD_EnableIrq(IODD_IRQ1)
#define IODC_EnableIrq_IODC_IRQ2  IODD_EnableIrq(IODD_IRQ2)
#define IODC_EnableIrq_IODC_IRQ3  IODD_EnableIrq(IODD_IRQ3)
#endif /* __TX49__ */

#ifdef __NEC_V850_Fx3__
#define IODC_EnableIrq_IODC_IRQ0        IODD_EnableIrq_IODD_IRQ0
#define IODC_EnableIrq_IODC_IRQ1        IODD_EnableIrq_IODD_IRQ1
#define IODC_EnableIrq_IODC_IRQ2        IODD_EnableIrq_IODD_IRQ2
#define IODC_EnableIrq_IODC_IRQ3        IODD_EnableIrq_IODD_IRQ3
#define IODC_DisableIrq_IODC_IRQ0       IODD_DisableIrq_IODD_IRQ0
#define IODC_DisableIrq_IODC_IRQ1       IODD_DisableIrq_IODD_IRQ1
#define IODC_DisableIrq_IODC_IRQ2       IODD_DisableIrq_IODD_IRQ2
#define IODC_DisableIrq_IODC_IRQ3       IODD_DisableIrq_IODD_IRQ3
#define IODC_ReadStatusIrq_IODC_IRQ0    IODD_ReadStatusIrq_IODD_IRQ0
#define IODC_ReadStatusIrq_IODC_IRQ1    IODD_ReadStatusIrq_IODD_IRQ1
#define IODC_ReadStatusIrq_IODC_IRQ2    IODD_ReadStatusIrq_IODD_IRQ2
#define IODC_ReadStatusIrq_IODC_IRQ3    IODD_ReadStatusIrq_IODD_IRQ3
#define IODC_ClearStatusIrq_IODC_IRQ0   IODD_ClearStatusIrq_IODD_IRQ0
#define IODC_ClearStatusIrq_IODC_IRQ1   IODD_ClearStatusIrq_IODD_IRQ1
#define IODC_ClearStatusIrq_IODC_IRQ2   IODD_ClearStatusIrq_IODD_IRQ2
#define IODC_ClearStatusIrq_IODC_IRQ3   IODD_ClearStatusIrq_IODD_IRQ3

#if     defined(__NEC_V850_FJ3__) ||                                    \
        defined(__NEC_V850_FK3__)

#define IODC_EnableIrq_IODC_IRQ4        IODD_EnableIrq_IODD_IRQ4
#define IODC_EnableIrq_IODC_IRQ5        IODD_EnableIrq_IODD_IRQ5
#define IODC_EnableIrq_IODC_IRQ6        IODD_EnableIrq_IODD_IRQ6
#define IODC_DisableIrq_IODC_IRQ4       IODD_DisableIrq_IODD_IRQ4
#define IODC_DisableIrq_IODC_IRQ5       IODD_DisableIrq_IODD_IRQ5
#define IODC_DisableIrq_IODC_IRQ6       IODD_DisableIrq_IODD_IRQ6
#define IODC_ReadStatusIrq_IODC_IRQ4    IODD_ReadStatusIrq_IODD_IRQ4
#define IODC_ReadStatusIrq_IODC_IRQ5    IODD_ReadStatusIrq_IODD_IRQ5
#define IODC_ReadStatusIrq_IODC_IRQ6    IODD_ReadStatusIrq_IODD_IRQ6
#define IODC_ClearStatusIrq_IODC_IRQ4   IODD_ClearStatusIrq_IODD_IRQ4
#define IODC_ClearStatusIrq_IODC_IRQ5   IODD_ClearStatusIrq_IODD_IRQ5
#define IODC_ClearStatusIrq_IODC_IRQ6   IODD_ClearStatusIrq_IODD_IRQ6
#endif

#define IODC_EnableIrq_IODC_IRQ7        IODD_EnableIrq_IODD_IRQ7
#define IODC_DisableIrq_IODC_IRQ7       IODD_DisableIrq_IODD_IRQ7
#define IODC_ReadStatusIrq_IODC_IRQ7    IODD_ReadStatusIrq_IODD_IRQ7
#define IODC_ClearStatusIrq_IODC_IRQ7   IODD_ClearStatusIrq_IODD_IRQ7

#if     defined(__NEC_V850_FG3__) ||                                    \
        defined(__NEC_V850_FJ3__) ||                                    \
        defined(__NEC_V850_FK3__)

#define IODC_EnableIrq_IODC_IRQ8        IODD_EnableIrq_IODD_IRQ8
#define IODC_DisableIrq_IODC_IRQ8       IODD_DisableIrq_IODD_IRQ8
#define IODC_ReadStatusIrq_IODC_IRQ8    IODD_ReadStatusIrq_IODD_IRQ8
#define IODC_ClearStatusIrq_IODC_IRQ8   IODD_ClearStatusIrq_IODD_IRQ8
#endif

#define IODC_EnableIrq_IODC_IRQ9        IODD_EnableIrq_IODD_IRQ9
#define IODC_EnableIrq_IODC_IRQ10       IODD_EnableIrq_IODD_IRQ10
#define IODC_DisableIrq_IODC_IRQ9       IODD_DisableIrq_IODD_IRQ9
#define IODC_DisableIrq_IODC_IRQ10      IODD_DisableIrq_IODD_IRQ10
#define IODC_ReadStatusIrq_IODC_IRQ9    IODD_ReadStatusIrq_IODD_IRQ9
#define IODC_ReadStatusIrq_IODC_IRQ10   IODD_ReadStatusIrq_IODD_IRQ10
#define IODC_ClearStatusIrq_IODC_IRQ9   IODD_ClearStatusIrq_IODD_IRQ9
#define IODC_ClearStatusIrq_IODC_IRQ10  IODD_ClearStatusIrq_IODD_IRQ10

#if     defined(__NEC_V850_FJ3__) ||                                    \
        defined(__NEC_V850_FK3__)

#define IODC_EnableIrq_IODC_IRQ11       IODD_EnableIrq_IODD_IRQ11
#define IODC_EnableIrq_IODC_IRQ12       IODD_EnableIrq_IODD_IRQ12
#define IODC_EnableIrq_IODC_IRQ13       IODD_EnableIrq_IODD_IRQ13
#define IODC_EnableIrq_IODC_IRQ14       IODD_EnableIrq_IODD_IRQ14
#define IODC_DisableIrq_IODC_IRQ11      IODD_DisableIrq_IODD_IRQ11
#define IODC_DisableIrq_IODC_IRQ12      IODD_DisableIrq_IODD_IRQ12
#define IODC_DisableIrq_IODC_IRQ13      IODD_DisableIrq_IODD_IRQ13
#define IODC_DisableIrq_IODC_IRQ14      IODD_DisableIrq_IODD_IRQ14
#define IODC_ReadStatusIrq_IODC_IRQ11   IODD_ReadStatusIrq_IODD_IRQ11
#define IODC_ReadStatusIrq_IODC_IRQ12   IODD_ReadStatusIrq_IODD_IRQ12
#define IODC_ReadStatusIrq_IODC_IRQ13   IODD_ReadStatusIrq_IODD_IRQ13
#define IODC_ReadStatusIrq_IODC_IRQ14   IODD_ReadStatusIrq_IODD_IRQ14
#define IODC_ClearStatusIrq_IODC_IRQ11  IODD_ClearStatusIrq_IODD_IRQ11
#define IODC_ClearStatusIrq_IODC_IRQ12  IODD_ClearStatusIrq_IODD_IRQ12
#define IODC_ClearStatusIrq_IODC_IRQ13  IODD_ClearStatusIrq_IODD_IRQ13
#define IODC_ClearStatusIrq_IODC_IRQ14  IODD_ClearStatusIrq_IODD_IRQ14
#endif

#if     defined(__NEC_V850_FK3__)

#define IODC_EnableIrq_IODC_IRQ15       IODD_EnableIrq_IODD_IRQ15
#define IODC_DisableIrq_IODC_IRQ15      IODD_DisableIrq_IODD_IRQ15
#define IODC_ReadStatusIrq_IODC_IRQ15   IODD_ReadStatusIrq_IODD_IRQ15
#define IODC_ClearStatusIrq_IODC_IRQ15  IODD_ClearStatusIrq_IODD_IRQ15
#endif

#define IODC_EnableIrq_IODC_IRQ_NMI
#define IODC_DisableIrq_IODC_IRQ_NMI
#define IODC_ReadStatusIrq_IODC_IRQ_NMI
#define IODC_ClearStatusIrq_IODC_IRQ_NMI

#endif /* __NEC_V850_Fx3__ */

#if     defined(__NEC_V850_Dx3__)

#define IODC_EnableIrq_IODC_IRQ0       IODD_EnableIrq_IODD_IRQ0
#define IODC_DisableIrq_IODC_IRQ0      IODD_DisableIrq_IODD_IRQ0
#define IODC_ReadStatusIrq_IODC_IRQ0   IODD_ReadStatusIrq_IODD_IRQ0
#define IODC_ClearStatusIrq_IODC_IRQ0  IODD_ClearStatusIrq_IODD_IRQ0

#define IODC_EnableIrq_IODC_IRQ1       IODD_EnableIrq_IODD_IRQ1
#define IODC_DisableIrq_IODC_IRQ1      IODD_DisableIrq_IODD_IRQ1
#define IODC_ReadStatusIrq_IODC_IRQ1   IODD_ReadStatusIrq_IODD_IRQ1
#define IODC_ClearStatusIrq_IODC_IRQ1  IODD_ClearStatusIrq_IODD_IRQ1

#define IODC_EnableIrq_IODC_IRQ2       IODD_EnableIrq_IODD_IRQ2
#define IODC_DisableIrq_IODC_IRQ2      IODD_DisableIrq_IODD_IRQ2
#define IODC_ReadStatusIrq_IODC_IRQ2   IODD_ReadStatusIrq_IODD_IRQ2
#define IODC_ClearStatusIrq_IODC_IRQ2  IODD_ClearStatusIrq_IODD_IRQ2

#define IODC_EnableIrq_IODC_IRQ3       IODD_EnableIrq_IODD_IRQ3
#define IODC_DisableIrq_IODC_IRQ3      IODD_DisableIrq_IODD_IRQ3
#define IODC_ReadStatusIrq_IODC_IRQ3   IODD_ReadStatusIrq_IODD_IRQ3
#define IODC_ClearStatusIrq_IODC_IRQ3  IODD_ClearStatusIrq_IODD_IRQ3

#ifndef __NEC_V850_DG3__
#define IODC_EnableIrq_IODC_IRQ4       IODD_EnableIrq_IODD_IRQ4
#define IODC_DisableIrq_IODC_IRQ4      IODD_DisableIrq_IODD_IRQ4
#define IODC_ReadStatusIrq_IODC_IRQ4   IODD_ReadStatusIrq_IODD_IRQ4
#define IODC_ClearStatusIrq_IODC_IRQ4  IODD_ClearStatusIrq_IODD_IRQ4

#define IODC_EnableIrq_IODC_IRQ5       IODD_EnableIrq_IODD_IRQ5
#define IODC_DisableIrq_IODC_IRQ5      IODD_DisableIrq_IODD_IRQ5
#define IODC_ReadStatusIrq_IODC_IRQ5   IODD_ReadStatusIrq_IODD_IRQ5
#define IODC_ClearStatusIrq_IODC_IRQ5  IODD_ClearStatusIrq_IODD_IRQ5

#define IODC_EnableIrq_IODC_IRQ6       IODD_EnableIrq_IODD_IRQ6
#define IODC_DisableIrq_IODC_IRQ6      IODD_DisableIrq_IODD_IRQ6
#define IODC_ReadStatusIrq_IODC_IRQ6   IODD_ReadStatusIrq_IODD_IRQ6
#define IODC_ClearStatusIrq_IODC_IRQ6  IODD_ClearStatusIrq_IODD_IRQ6
#endif  /* __NEC_V850_DG3__ */

#if defined (__NEC_V850_DJ3_HE__) || defined (__NEC_V850_DL3__)
#define IODC_EnableIrq_IODC_IRQ7       IODD_EnableIrq_IODD_IRQ7
#define IODC_DisableIrq_IODC_IRQ7      IODD_DisableIrq_IODD_IRQ7
#define IODC_ReadStatusIrq_IODC_IRQ7   IODD_ReadStatusIrq_IODD_IRQ7
#define IODC_ClearStatusIrq_IODC_IRQ7  IODD_ClearStatusIrq_IODD_IRQ7
#endif  /* defined (__NEC_V850_DJ3_HE__) || defined (__NEC_V850_DL3__) */
#endif  /* __NEC_V850_Dx3__     */

#if     defined(__REL_V850_Dx4__)

#define IODC_EnableIrq_IODC_IRQ0       IODD_EnableIrq_IODD_IRQ0
#define IODC_DisableIrq_IODC_IRQ0      IODD_DisableIrq_IODD_IRQ0
#define IODC_ReadStatusIrq_IODC_IRQ0   IODD_ReadStatusIrq_IODD_IRQ0
#define IODC_ClearStatusIrq_IODC_IRQ0  IODD_ClearStatusIrq_IODD_IRQ0

#define IODC_EnableIrq_IODC_IRQ1       IODD_EnableIrq_IODD_IRQ1
#define IODC_DisableIrq_IODC_IRQ1      IODD_DisableIrq_IODD_IRQ1
#define IODC_ReadStatusIrq_IODC_IRQ1   IODD_ReadStatusIrq_IODD_IRQ1
#define IODC_ClearStatusIrq_IODC_IRQ1  IODD_ClearStatusIrq_IODD_IRQ1

#define IODC_EnableIrq_IODC_IRQ2       IODD_EnableIrq_IODD_IRQ2
#define IODC_DisableIrq_IODC_IRQ2      IODD_DisableIrq_IODD_IRQ2
#define IODC_ReadStatusIrq_IODC_IRQ2   IODD_ReadStatusIrq_IODD_IRQ2
#define IODC_ClearStatusIrq_IODC_IRQ2  IODD_ClearStatusIrq_IODD_IRQ2

#define IODC_EnableIrq_IODC_IRQ3       IODD_EnableIrq_IODD_IRQ3
#define IODC_DisableIrq_IODC_IRQ3      IODD_DisableIrq_IODD_IRQ3
#define IODC_ReadStatusIrq_IODC_IRQ3   IODD_ReadStatusIrq_IODD_IRQ3
#define IODC_ClearStatusIrq_IODC_IRQ3  IODD_ClearStatusIrq_IODD_IRQ3

#define IODC_EnableIrq_IODC_IRQ4       IODD_EnableIrq_IODD_IRQ4
#define IODC_DisableIrq_IODC_IRQ4      IODD_DisableIrq_IODD_IRQ4
#define IODC_ReadStatusIrq_IODC_IRQ4   IODD_ReadStatusIrq_IODD_IRQ4
#define IODC_ClearStatusIrq_IODC_IRQ4  IODD_ClearStatusIrq_IODD_IRQ4

#define IODC_EnableIrq_IODC_IRQ5       IODD_EnableIrq_IODD_IRQ5
#define IODC_DisableIrq_IODC_IRQ5      IODD_DisableIrq_IODD_IRQ5
#define IODC_ReadStatusIrq_IODC_IRQ5   IODD_ReadStatusIrq_IODD_IRQ5
#define IODC_ClearStatusIrq_IODC_IRQ5  IODD_ClearStatusIrq_IODD_IRQ5

#define IODC_EnableIrq_IODC_IRQ6       IODD_EnableIrq_IODD_IRQ6
#define IODC_DisableIrq_IODC_IRQ6      IODD_DisableIrq_IODD_IRQ6
#define IODC_ReadStatusIrq_IODC_IRQ6   IODD_ReadStatusIrq_IODD_IRQ6
#define IODC_ClearStatusIrq_IODC_IRQ6  IODD_ClearStatusIrq_IODD_IRQ6

#define IODC_EnableIrq_IODC_IRQ7       IODD_EnableIrq_IODD_IRQ7
#define IODC_DisableIrq_IODC_IRQ7      IODD_DisableIrq_IODD_IRQ7
#define IODC_ReadStatusIrq_IODC_IRQ7   IODD_ReadStatusIrq_IODD_IRQ7
#define IODC_ClearStatusIrq_IODC_IRQ7  IODD_ClearStatusIrq_IODD_IRQ7

#define IODC_EnableIrq_IODC_IRQ8       IODD_EnableIrq_IODD_IRQ8
#define IODC_DisableIrq_IODC_IRQ8      IODD_DisableIrq_IODD_IRQ8
#define IODC_ReadStatusIrq_IODC_IRQ8   IODD_ReadStatusIrq_IODD_IRQ8
#define IODC_ClearStatusIrq_IODC_IRQ8  IODD_ClearStatusIrq_IODD_IRQ8

#define IODC_EnableIrq_IODC_IRQ9       IODD_EnableIrq_IODD_IRQ9
#define IODC_DisableIrq_IODC_IRQ9      IODD_DisableIrq_IODD_IRQ9
#define IODC_ReadStatusIrq_IODC_IRQ9   IODD_ReadStatusIrq_IODD_IRQ9
#define IODC_ClearStatusIrq_IODC_IRQ9  IODD_ClearStatusIrq_IODD_IRQ9

#define IODC_EnableIrq_IODC_IRQ10       IODD_EnableIrq_IODD_IRQ10
#define IODC_DisableIrq_IODC_IRQ10      IODD_DisableIrq_IODD_IRQ10
#define IODC_ReadStatusIrq_IODC_IRQ10   IODD_ReadStatusIrq_IODD_IRQ10
#define IODC_ClearStatusIrq_IODC_IRQ10  IODD_ClearStatusIrq_IODD_IRQ10
#endif  /* __REL_V850_Dx4__     */

#ifdef __REL_RL78__
#ifdef __REL_RL78_D1x__
#ifdef __REL_RL78_D1A__
#define IODC_EnableIrq_IODC_IRQ0   IODD_EnableIrq(IODD_IRQ0)
#define IODC_EnableIrq_IODC_IRQ1   IODD_EnableIrq(IODD_IRQ1)
#define IODC_EnableIrq_IODC_IRQ2   IODD_EnableIrq(IODD_IRQ2)
#define IODC_EnableIrq_IODC_IRQ3   IODD_EnableIrq(IODD_IRQ3)
#define IODC_EnableIrq_IODC_IRQ4   IODD_EnableIrq(IODD_IRQ4)
#define IODC_EnableIrq_IODC_IRQ5   IODD_EnableIrq(IODD_IRQ5)
#endif /* __REL_RL78_D1A__ */
#endif /* __REL_RL78_D1x__ */

#ifdef __REL_RL78_F1x__
#ifdef __REL_RL78_F12__
#define IODC_EnableIrq_IODC_IRQ0    IODD_EnableIrq(IODD_IRQ0)
#define IODC_EnableIrq_IODC_IRQ1    IODD_EnableIrq(IODD_IRQ1)
#define IODC_EnableIrq_IODC_IRQ2    IODD_EnableIrq(IODD_IRQ2)
#define IODC_EnableIrq_IODC_IRQ3    IODD_EnableIrq(IODD_IRQ3)
#define IODC_EnableIrq_IODC_IRQ4    IODD_EnableIrq(IODD_IRQ4)
#define IODC_EnableIrq_IODC_IRQ5    IODD_EnableIrq(IODD_IRQ5)
#define IODC_EnableIrq_IODC_IRQ6    IODD_EnableIrq(IODD_IRQ6)
#define IODC_EnableIrq_IODC_IRQ7    IODD_EnableIrq(IODD_IRQ7)
#define IODC_EnableIrq_IODC_IRQ8    IODD_EnableIrq(IODD_IRQ8)
#define IODC_EnableIrq_IODC_IRQ9    IODD_EnableIrq(IODD_IRQ9)
#define IODC_EnableIrq_IODC_IRQ10   IODD_EnableIrq(IODD_IRQ10)
#define IODC_EnableIrq_IODC_IRQ11   IODD_EnableIrq(IODD_IRQ11)
#endif /* __REL_RL78_F12__ */
#endif /* __REL_RL78_F1x__ */
#endif /* __REL_RL78__ */

/*----------------------------------------------------------------------------*/
/* Name : IODC_DisableIrq                                                     */
/* Role : Disable interrupt request                                           */
/* Interface :                                                                */
/*   - IrqName IN, name of Irq for                                            */
/*                                 Motorola STAR12                            */
/*                                 [IODC_IRQ0..IODC_IRQ12]                    */
/*                                 Freescale MC9S12XHZ                        */
/*                                 [IODC_IRQ0..IODC_IRQ8]                     */
/* Pre-condition : -                                                          */
/* Constraints : -                                                            */
/* Behavior :                                                                 */
/*   DO                                                                       */
/*     [disable interrupt requested]                                          */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/
#if defined(__FSL_IMX53x__) || defined(__FSL_IMX6x__)
#define IODC_DisableIrq(IrqName) IODD_DisableIrq(IrqName)
#else
#ifndef __CY_TV2__
#define IODC_DisableIrq(IrqName) IODC_DisableIrq_ ## IrqName
#endif /*__CY_TV2__*/
#endif /* __FSL_IMX53x__, __FSL_IMX6x__ */

#if (defined(__MC9S12xx__))
#define IODC_DisableIrq_IODC_IRQ0   IODD_DisableIrq(IODD_IRQ0)
#define IODC_DisableIrq_IODC_IRQ1   IODD_DisableIrq(IODD_IRQ1)
#define IODC_DisableIrq_IODC_IRQ2   IODD_DisableIrq(IODD_IRQ2)
#define IODC_DisableIrq_IODC_IRQ3   IODD_DisableIrq(IODD_IRQ3)
#define IODC_DisableIrq_IODC_IRQ4   IODD_DisableIrq(IODD_IRQ4)
#define IODC_DisableIrq_IODC_IRQ5   IODD_DisableIrq(IODD_IRQ5)
#define IODC_DisableIrq_IODC_IRQ6   IODD_DisableIrq(IODD_IRQ6)
#define IODC_DisableIrq_IODC_IRQ7   IODD_DisableIrq(IODD_IRQ7)
#define IODC_DisableIrq_IODC_IRQ8   IODD_DisableIrq(IODD_IRQ8)
/* --- MC9S12-H variant --- */
#if defined(__MC9S12H__)
#define IODC_DisableIrq_IODC_IRQ9   IODD_DisableIrq(IODD_IRQ9)
#define IODC_DisableIrq_IODC_IRQ10  IODD_DisableIrq(IODD_IRQ10)
#define IODC_DisableIrq_IODC_IRQ11  IODD_DisableIrq(IODD_IRQ11)
#define IODC_DisableIrq_IODC_IRQ12  IODD_DisableIrq(IODD_IRQ12)
#endif /* defined(__MC9S12H__) */
#endif /* (defined(__MC9S12xx__)) */

#if (defined(__MC9S08xx__))
#define IODC_DisableIrq_IODC_IRQPIN  IODD_DisableIrq(IODD_IRQPIN)

#define IODC_DisableIrq_IODC_IRQ1   IODD_DisableIrq(IODD_IRQ1)
#define IODC_DisableIrq_IODC_IRQ2   IODD_DisableIrq(IODD_IRQ2)
#define IODC_DisableIrq_IODC_IRQ3   IODD_DisableIrq(IODD_IRQ3)
#define IODC_DisableIrq_IODC_IRQ4   IODD_DisableIrq(IODD_IRQ4)
#define IODC_DisableIrq_IODC_IRQ5   IODD_DisableIrq(IODD_IRQ5)
#define IODC_DisableIrq_IODC_IRQ6   IODD_DisableIrq(IODD_IRQ6)
#define IODC_DisableIrq_IODC_IRQ7   IODD_DisableIrq(IODD_IRQ7)
#endif /* (defined(__MC9S08xx__)) */

#ifdef __TX49__
#define IODC_DisableIrq_IODC_IRQ0  IODD_DisableIrq(IODD_IRQ00)
#define IODC_DisableIrq_IODC_IRQ1  IODD_DisableIrq(IODD_IRQ01)
#define IODC_DisableIrq_IODC_IRQ2  IODD_DisableIrq(IODD_IRQ02)
#define IODC_DisableIrq_IODC_IRQ3  IODD_DisableIrq(IODD_IRQ03)
#endif /* __TX49__ */

#ifdef __REL_RL78__
#ifdef __REL_RL78_D1x__
#ifdef __REL_RL78_D1A__
#define IODC_DisableIrq_IODC_IRQ0   IODD_DisableIrq(IODD_IRQ0)
#define IODC_DisableIrq_IODC_IRQ1   IODD_DisableIrq(IODD_IRQ1)
#define IODC_DisableIrq_IODC_IRQ2   IODD_DisableIrq(IODD_IRQ2)
#define IODC_DisableIrq_IODC_IRQ3   IODD_DisableIrq(IODD_IRQ3)
#define IODC_DisableIrq_IODC_IRQ4   IODD_DisableIrq(IODD_IRQ4)
#define IODC_DisableIrq_IODC_IRQ5   IODD_DisableIrq(IODD_IRQ5)
#endif /* __REL_RL78_D1A__ */
#endif /* __REL_RL78_D1x__ */

#ifdef __REL_RL78_F1x__
#ifdef __REL_RL78_F12__
#define IODC_DisableIrq_IODC_IRQ0    IODD_DisableIrq(IODD_IRQ0)
#define IODC_DisableIrq_IODC_IRQ1    IODD_DisableIrq(IODD_IRQ1)
#define IODC_DisableIrq_IODC_IRQ2    IODD_DisableIrq(IODD_IRQ2)
#define IODC_DisableIrq_IODC_IRQ3    IODD_DisableIrq(IODD_IRQ3)
#define IODC_DisableIrq_IODC_IRQ4    IODD_DisableIrq(IODD_IRQ4)
#define IODC_DisableIrq_IODC_IRQ5    IODD_DisableIrq(IODD_IRQ5)
#define IODC_DisableIrq_IODC_IRQ6    IODD_DisableIrq(IODD_IRQ6)
#define IODC_DisableIrq_IODC_IRQ7    IODD_DisableIrq(IODD_IRQ7)
#define IODC_DisableIrq_IODC_IRQ8    IODD_DisableIrq(IODD_IRQ8)
#define IODC_DisableIrq_IODC_IRQ9    IODD_DisableIrq(IODD_IRQ9)
#define IODC_DisableIrq_IODC_IRQ10   IODD_DisableIrq(IODD_IRQ10)
#define IODC_DisableIrq_IODC_IRQ11   IODD_DisableIrq(IODD_IRQ11)
#endif /* __REL_RL78_F12__ */
#endif /* __REL_RL78_F1x__ */
#endif /* __REL_RL78__ */

/*----------------------------------------------------------------------------*/
/* Name : IODC_ClearStatusIrq                                                 */
/* Role : Clear interrupt request flag                                        */
/* Interface :                                                                */
/*   - IrqName IN, name of Irq for Motorola STAR12                            */
/*                                 [IODC_IRQ1..IODC_IRQ12]                    */
/*                                 Freescale MC9S12XHZ                        */
/*                                 [IODC_IRQ0..IODC_IRQ8]                     */
/* Pre-condition : -                                                          */
/* Constraints : -                                                            */
/* Behavior :                                                                 */
/*   DO                                                                       */
/*     [Clear the interrupt status]                                           */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/
#if defined(__FSL_IMX53x__) || defined(__FSL_IMX6x__)
#define IODC_ClearStatusIrq(IrqName) IODD_ClearStatusIrq(IrqName)
#else
#ifndef __CY_TV2__
#define IODC_ClearStatusIrq(IrqName) IODC_ClearStatusIrq_ ## IrqName
#endif /*__CY_TV2__*/
#endif /* __FSL_IMX53x__, __FSL_IMX6x__ */

#if (defined(__MC9S12xx__))
#define IODC_ClearStatusIrq_IODC_IRQ0   IODD_ClearStatusIrq(IODD_IRQ0)
#define IODC_ClearStatusIrq_IODC_IRQ1   IODD_ClearStatusIrq(IODD_IRQ1)
#define IODC_ClearStatusIrq_IODC_IRQ2   IODD_ClearStatusIrq(IODD_IRQ2)
#define IODC_ClearStatusIrq_IODC_IRQ3   IODD_ClearStatusIrq(IODD_IRQ3)
#define IODC_ClearStatusIrq_IODC_IRQ4   IODD_ClearStatusIrq(IODD_IRQ4)
#define IODC_ClearStatusIrq_IODC_IRQ5   IODD_ClearStatusIrq(IODD_IRQ5)
#define IODC_ClearStatusIrq_IODC_IRQ6   IODD_ClearStatusIrq(IODD_IRQ6)
#define IODC_ClearStatusIrq_IODC_IRQ7   IODD_ClearStatusIrq(IODD_IRQ7)
#define IODC_ClearStatusIrq_IODC_IRQ8   IODD_ClearStatusIrq(IODD_IRQ8)
/* --- MC9S12-H variant --- */
#if defined(__MC9S12H__)
#define IODC_ClearStatusIrq_IODC_IRQ9   IODD_ClearStatusIrq(IODD_IRQ9)
#define IODC_ClearStatusIrq_IODC_IRQ10  IODD_ClearStatusIrq(IODD_IRQ10)
#define IODC_ClearStatusIrq_IODC_IRQ11  IODD_ClearStatusIrq(IODD_IRQ11)
#define IODC_ClearStatusIrq_IODC_IRQ12  IODD_ClearStatusIrq(IODD_IRQ12)
#endif /* defined(__MC9S12H__) */
#endif /* (defined(__MC9S12xx__)) */

#if (defined(__MC9S08xx__))
#define IODC_ClearStatusIrq_IODC_IRQPIN   IODD_ClearStatusIrq(IODD_IRQPIN);

#define IODC_ClearStatusIrq_IODC_IRQ0   IODD_ClearStatusIrq(IODD_IRQKBI);
#define IODC_ClearStatusIrq_IODC_IRQ1   IODD_ClearStatusIrq(IODD_IRQKBI);
#define IODC_ClearStatusIrq_IODC_IRQ2   IODD_ClearStatusIrq(IODD_IRQKBI);
#define IODC_ClearStatusIrq_IODC_IRQ3   IODD_ClearStatusIrq(IODD_IRQKBI);
#define IODC_ClearStatusIrq_IODC_IRQ4   IODD_ClearStatusIrq(IODD_IRQKBI);
#define IODC_ClearStatusIrq_IODC_IRQ5   IODD_ClearStatusIrq(IODD_IRQKBI);
#define IODC_ClearStatusIrq_IODC_IRQ6   IODD_ClearStatusIrq(IODD_IRQKBI);
#define IODC_ClearStatusIrq_IODC_IRQ7   IODD_ClearStatusIrq(IODD_IRQKBI);
#endif /* (defined(__MC9S08xx__)) */

#ifdef __REL_RL78__
#ifdef __REL_RL78_D1x__
#ifdef __REL_RL78_D1A__
#define IODC_ClearStatusIrq_IODC_IRQ0   IODD_ClearStatusIrq(IODD_IRQ0)
#define IODC_ClearStatusIrq_IODC_IRQ1   IODD_ClearStatusIrq(IODD_IRQ1)
#define IODC_ClearStatusIrq_IODC_IRQ2   IODD_ClearStatusIrq(IODD_IRQ2)
#define IODC_ClearStatusIrq_IODC_IRQ3   IODD_ClearStatusIrq(IODD_IRQ3)
#define IODC_ClearStatusIrq_IODC_IRQ4   IODD_ClearStatusIrq(IODD_IRQ4)
#define IODC_ClearStatusIrq_IODC_IRQ5   IODD_ClearStatusIrq(IODD_IRQ5)
#endif /* __REL_RL78_D1A__ */
#endif /* __REL_RL78_D1x__ */

#ifdef __REL_RL78_F1x__
#ifdef __REL_RL78_F12__
#define IODC_ClearStatusIrq_IODC_IRQ0    IODD_ClearStatusIrq(IODD_IRQ0)
#define IODC_ClearStatusIrq_IODC_IRQ1    IODD_ClearStatusIrq(IODD_IRQ1)
#define IODC_ClearStatusIrq_IODC_IRQ2    IODD_ClearStatusIrq(IODD_IRQ2)
#define IODC_ClearStatusIrq_IODC_IRQ3    IODD_ClearStatusIrq(IODD_IRQ3)
#define IODC_ClearStatusIrq_IODC_IRQ4    IODD_ClearStatusIrq(IODD_IRQ4)
#define IODC_ClearStatusIrq_IODC_IRQ5    IODD_ClearStatusIrq(IODD_IRQ5)
#define IODC_ClearStatusIrq_IODC_IRQ6    IODD_ClearStatusIrq(IODD_IRQ6)
#define IODC_ClearStatusIrq_IODC_IRQ7    IODD_ClearStatusIrq(IODD_IRQ7)
#define IODC_ClearStatusIrq_IODC_IRQ8    IODD_ClearStatusIrq(IODD_IRQ8)
#define IODC_ClearStatusIrq_IODC_IRQ9    IODD_ClearStatusIrq(IODD_IRQ9)
#define IODC_ClearStatusIrq_IODC_IRQ10   IODD_ClearStatusIrq(IODD_IRQ10)
#define IODC_ClearStatusIrq_IODC_IRQ11   IODD_ClearStatusIrq(IODD_IRQ11)
#endif /* __REL_RL78_F12__ */
#endif /* __REL_RL78_F1x__ */
#endif /* __REL_RL78__ */

/*----------------------------------------------------------------------------*/
/* Name : IODC_ReadStatusIrq                                                  */
/* Role : Read interrupt request flag                                         */
/* Interface :                                                                */
/*   - IrqName IN, name of Irq for Motorola STAR12                            */
/*                                 [IODC_IRQ1..IODC_IRQ12]                    */
/*                                 Freescale MC9S12XHZ                        */
/*                                 [IODC_IRQ0..IODC_IRQ8]                     */
/* Pre-condition : -                                                          */
/* Constraints : -                                                            */
/* Behavior :                                                                 */
/*   DO                                                                       */
/*     [read the interrupt status]                                            */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/
#if defined(__FSL_IMX53x__) || defined(__FSL_IMX6x__)
#define IODC_ReadStatusIrq(IrqName) IODD_ReadStatusIrq(IrqName)
#else
#ifndef __CY_TV2__
#define IODC_ReadStatusIrq(IrqName) IODC_ReadStatusIrq_ ## IrqName
#endif /*__CY_TV2__*/
#endif /* __FSL_IMX53x__ , __FSL_IMX6x__*/

#ifdef __MC9S12xx__
#define IODC_ReadStatusIrq_IODC_IRQ0   IODD_ReadStatusIrq(IODD_IRQ0)
#define IODC_ReadStatusIrq_IODC_IRQ1   IODD_ReadStatusIrq(IODD_IRQ1)
#define IODC_ReadStatusIrq_IODC_IRQ2   IODD_ReadStatusIrq(IODD_IRQ2)
#define IODC_ReadStatusIrq_IODC_IRQ3   IODD_ReadStatusIrq(IODD_IRQ3)
#define IODC_ReadStatusIrq_IODC_IRQ4   IODD_ReadStatusIrq(IODD_IRQ4)
#define IODC_ReadStatusIrq_IODC_IRQ5   IODD_ReadStatusIrq(IODD_IRQ5)
#define IODC_ReadStatusIrq_IODC_IRQ6   IODD_ReadStatusIrq(IODD_IRQ6)
#define IODC_ReadStatusIrq_IODC_IRQ7   IODD_ReadStatusIrq(IODD_IRQ7)
#define IODC_ReadStatusIrq_IODC_IRQ8   IODD_ReadStatusIrq(IODD_IRQ8)
/* --- MC9S12-H variant --- */
#if defined(__MC9S12H__)
#define IODC_ReadStatusIrq_IODC_IRQ9   IODD_ReadStatusIrq(IODD_IRQ9)
#define IODC_ReadStatusIrq_IODC_IRQ10  IODD_ReadStatusIrq(IODD_IRQ10)
#define IODC_ReadStatusIrq_IODC_IRQ11  IODD_ReadStatusIrq(IODD_IRQ11)
#define IODC_ReadStatusIrq_IODC_IRQ12  IODD_ReadStatusIrq(IODD_IRQ12)
#endif /* defined(__MC9S12H__) */
#endif /* (defined(__MC9S12xx__)) */

#ifdef __REL_RL78__
#ifdef __REL_RL78_D1x__
#ifdef __REL_RL78_D1A__
#define IODC_ReadStatusIrq_IODC_IRQ0   IODD_ReadStatusIrq(IODD_IRQ0)
#define IODC_ReadStatusIrq_IODC_IRQ1   IODD_ReadStatusIrq(IODD_IRQ1)
#define IODC_ReadStatusIrq_IODC_IRQ2   IODD_ReadStatusIrq(IODD_IRQ2)
#define IODC_ReadStatusIrq_IODC_IRQ3   IODD_ReadStatusIrq(IODD_IRQ3)
#define IODC_ReadStatusIrq_IODC_IRQ4   IODD_ReadStatusIrq(IODD_IRQ4)
#define IODC_ReadStatusIrq_IODC_IRQ5   IODD_ReadStatusIrq(IODD_IRQ5)
#endif /* __REL_RL78_D1A__ */
#endif /* __REL_RL78_D1x__ */

#ifdef __REL_RL78_F1x__
#ifdef __REL_RL78_F12__
#define IODC_ReadStatusIrq_IODC_IRQ0    IODD_ReadStatusIrq(IODD_IRQ0)
#define IODC_ReadStatusIrq_IODC_IRQ1    IODD_ReadStatusIrq(IODD_IRQ1)
#define IODC_ReadStatusIrq_IODC_IRQ2    IODD_ReadStatusIrq(IODD_IRQ2)
#define IODC_ReadStatusIrq_IODC_IRQ3    IODD_ReadStatusIrq(IODD_IRQ3)
#define IODC_ReadStatusIrq_IODC_IRQ4    IODD_ReadStatusIrq(IODD_IRQ4)
#define IODC_ReadStatusIrq_IODC_IRQ5    IODD_ReadStatusIrq(IODD_IRQ5)
#define IODC_ReadStatusIrq_IODC_IRQ6    IODD_ReadStatusIrq(IODD_IRQ6)
#define IODC_ReadStatusIrq_IODC_IRQ7    IODD_ReadStatusIrq(IODD_IRQ7)
#define IODC_ReadStatusIrq_IODC_IRQ8    IODD_ReadStatusIrq(IODD_IRQ8)
#define IODC_ReadStatusIrq_IODC_IRQ9    IODD_ReadStatusIrq(IODD_IRQ9)
#define IODC_ReadStatusIrq_IODC_IRQ10   IODD_ReadStatusIrq(IODD_IRQ10)
#define IODC_ReadStatusIrq_IODC_IRQ11   IODD_ReadStatusIrq(IODD_IRQ11)
#endif /* __REL_RL78_F12__ */
#endif /* __REL_RL78_F1x__ */
#endif /* __REL_RL78__ */
#if (defined(__MC9S08xx__))
#define IODC_ReadStatusIrq_IODC_IRQPIN  IODD_ReadStatusIrq(IODD_IRQPIN)

/* Only 1 flag for all KBI pins */
#define IODC_ReadStatusIrq_IODC_IRQ0  IODD_ReadStatusIrq(IODD_IRQ0);
#define IODC_ReadStatusIrq_IODC_IRQ1  IODD_ReadStatusIrq(IODD_IRQ1);
#define IODC_ReadStatusIrq_IODC_IRQ2  IODD_ReadStatusIrq(IODD_IRQ2);
#define IODC_ReadStatusIrq_IODC_IRQ3  IODD_ReadStatusIrq(IODD_IRQ3);
#define IODC_ReadStatusIrq_IODC_IRQ4  IODD_ReadStatusIrq(IODD_IRQ4);
#define IODC_ReadStatusIrq_IODC_IRQ5  IODD_ReadStatusIrq(IODD_IRQ5);
#define IODC_ReadStatusIrq_IODC_IRQ6  IODD_ReadStatusIrq(IODD_IRQ6);
#define IODC_ReadStatusIrq_IODC_IRQ7  IODD_ReadStatusIrq(IODD_IRQ7);
#endif /* (defined(__MC9S08xx__)) */

#if (defined(__BOOT_LOADER_FLASHER_LINK__) || defined(__BOOT_CLIENT_EOL_LINK__) || defined(__BOOT_LOADER_LINK__))
/*----------------------------------------------------------------------------*/
/*Name : IODC_BootInit                                                        */
/*Role : Initialise the hardware by using the base layer for the Boot part.   */
/*       Loader, EOL or Client will launch after their own HW initialisation. */
/*       This macro is usefull when a HW bootkey is used.                     */
/*Interface : -                                                               */
/*Pre-condition : -                                                           */
/*Constraints : A macro is used to not embedded this code when it is not      */
/*              needed.                                                       */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [Call general init and call specific Boot init]                         */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#define IODC_BootInit Iodc_InitBoot
#endif /* __BOOT_LOADER_FLASHER_LINK__ || __BOOT_CLIENT_EOL_LINK__  || __BOOT_LOADER_LINK__ */



/*----------------------------------------------------------------------------*/
/*Name : IODC_SetPortOutputPinData                                            */
/*Role : Set a state on the pin of a port in uotput mode                      */
/*Interface :                                                                 */
/*  - PortNumber IN, Number of port for :                                     */
/*                                    NEC V850 Dx3                            */
/*                                    [0,1,2,3,4,5,6,8,9,10,11,12,13,14]      */
/*                                                                            */
/*  - PinNumber IN, number of the selected pin [0..7]                         */
/*  - State     IN, requested output state of the pin [0, 1]                  */
/*Pre-condition : -                                                           */
/*Constraints :  -                                                            */
/*----------------------------------------------------------------------------*/
#define IODC_SetPortOutputPinData(PortNumber, PinNumber, State) \
        IODD_SetPortOutputPinData(PortNumber, PinNumber, State)


/*----------------------------------------------------------------------------*/
/*Name : IODC_GetPortOutputPinData                                            */
/*Role : Get the state of a pin of a port in uotput mode                      */
/*Interface :                                                                 */
/*  - PortNumber IN, Number of port for :                                     */
/*                                    NEC V850 Dx3                            */
/*                                    [0,1,2,3,4,5,6,8,9,10,11,12,13,14]      */
/*                                                                            */
/*  - PinNumber IN, number of the selected pin [0..7]                         */
/*  - State     OUT, state of the pin (0, 1)                                  */
/*Pre-condition : -                                                           */
/*Constraints :  -                                                            */
/*----------------------------------------------------------------------------*/
#define IODC_GetPortOutputPinData(PortNumber, PinNumber) \
        IODD_GetPortOutputPinData(PortNumber, PinNumber)


/*______ G L O B A L - T Y P E S______________________________________________*/

#ifdef IODC_LED_MATRIX_USED
  #if (IODC_NUMBER_OF_LINE_PIN > 16) && (IODC_NUMBER_OF_LINE_PIN <= 32)
    #define IODC_TabStateLed_t  ulong
    #define IODC_LedStateType_t bitfield_long_t
  #else
   #if (IODC_NUMBER_OF_LINE_PIN > 8) && (IODC_NUMBER_OF_LINE_PIN <= 16)
    #define IODC_TabStateLed_t  ushort
    #define IODC_LedStateType_t bitfield_short_t
   #else
    #if (IODC_NUMBER_OF_LINE_PIN <= 8)
    #define IODC_TabStateLed_t  ubyte
    #define IODC_LedStateType_t bitfield_byte_t
    #else
      #error <LED matrix by shift register acces can not have more than 32 lines>
    #endif /* (IODC_NUMBER_OF_LINE_PIN <= 8) */
   #endif /* (IODC_NUMBER_OF_LINE_PIN > 8) && (IODC_NUMBER_OF_LINE_PIN <= 16) */
  #endif /* (IODC_NUMBER_OF_LINE_PIN > 16) && (IODC_NUMBER_OF_LINE_PIN <= 32) */
#endif /* IODC_LED_MATRIX_USED */


/*______ G L O B A L - D A T A _______________________________________________*/

#ifdef IODC_LED_MATRIX_USED
/* note : global data to reduce CPU load */
/* but used via a macro                  */
extern IODC_TabStateLed_t IODC_TabStateLed[IODC_NUMBER_OF_COLUMN_PIN];
#endif /* IODC_LED_MATRIX_USED */


#ifdef IODC_INPUT_MATRIX_USED
#if (IODC_NUMBER_OF_INPUT_MATRIX > 0)
extern ubyte IODC_IndexMatrix;
extern ubyte IODC_LastNoRotaryIndex1;
extern ubyte IODC_LastNoRotaryColumn1;

extern          bitfield_byte_t IODC_TabStateInputMatrix1[IODC_MUXIN_NB_SAMPLE];
extern volatile bitfield_byte_t IODC_TabStateButtonMatrix1[IODC_NB_COLUMN_INMUX_1];
#endif /* (IODC_NUMBER_OF_INPUT_MATRIX > 0) */

#if (IODC_NUMBER_OF_INPUT_MATRIX > 1)
extern ubyte IODC_LastNoRotaryIndex2;
extern ubyte IODC_LastNoRotaryColumn2;

extern          bitfield_byte_t IODC_TabStateInputMatrix2[IODC_MUXIN_NB_SAMPLE];
extern volatile bitfield_byte_t IODC_TabStateButtonMatrix2[IODC_NB_COLUMN_INMUX_2];
#endif /* (IODC_NUMBER_OF_INPUT_MATRIX > 1) */
#endif /* IODC_INPUT_MATRIX_USED */


/*______ G L O B A L - F U N C T I O N S - P R O T O T Y P E S _______________*/

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
#ifdef __MC9S08xx__

/* install irq interrupt */
#if IODC_IT_IRQPIN == _USED_
extern ISR(IODC_Irq_it);
#else
#define IODC_Irq_it  NULL
#endif /* IODC_IT_IRQPIN == _USED_ */

/* install irq H interrupt */
#if ((IODC_IT_IRQ0 == _USED_) || \
     (IODC_IT_IRQ1 == _USED_) || \
     (IODC_IT_IRQ2 == _USED_) || \
     (IODC_IT_IRQ3 == _USED_) || \
     (IODC_IT_IRQ4 == _USED_) || \
     (IODC_IT_IRQ5 == _USED_) || \
     (IODC_IT_IRQ6 == _USED_) || \
     (IODC_IT_IRQ7 == _USED_))

extern ISR(IODC_IrqKbi_it);

#else

#define IODC_IrqKbi_it  NULL

#endif /* IODC_IT_IRQX == _USED_ */

#endif /* __MC9S08xx__ */

#ifdef __MC9S12xx__

/* install irq interrupt */
#if IODC_IT_IRQ0 == _USED_
extern ISR(IODC_Irq_it);
#else
#define IODC_Irq_it  NULL
#endif /* IODC_IT_IRQ0 == _USED_ */

/* install irq H interrupt */
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

extern ISR(IODC_IrqH_it);

#endif /* defined(__MC9S12H__) */

/* --- MC9S12-HZ and MMC9S12XHZ variant --- */
#if (defined(__MC9S12HZ__) || defined(__MC9S12XHZ__))

/* install irq port AD interrupt */
extern ISR(IODC_IrqAD_it);

#endif /* (defined(__MC9S12HZ__) || defined(__MC9S12XHZ__)) */

#else

/* --- MC9S12-H variant --- */
#if defined(__MC9S12H__)

#define IODC_IrqH_it  NULL

#endif /* defined(__MC9S12H__) */

/* --- MC9S12-HZ and MC9S12XHZ variant --- */
#if (defined(__MC9S12HZ__) || defined(__MC9S12XHZ__))

#define IODC_IrqAD_it  NULL

#endif /*(defined(__MC9S12HZ__) || defined(__MC9S12XHZ__)) */

#endif /* at least one Irq used on port H  (MC9S12-H  variant) */
       /* at least one Irq used on port AD (MC9S12-HZ and MC9s12XHZ variant) */

/* --- MC9S12-H variant --- */
#if defined(__MC9S12H__)

/* install irq J interrupt */
#if ((IODC_IT_IRQ9  == _USED_) || \
     (IODC_IT_IRQ10 == _USED_) || \
     (IODC_IT_IRQ11 == _USED_) || \
     (IODC_IT_IRQ12 == _USED_))
extern ISR(IODC_IrqJ_it);
#else
#define IODC_IrqJ_it  NULL
#endif /* at least one Irq used on port J */

#endif /* defined(__MC9S12H__) */

#endif  /* __MC9S12xx__  */

#ifdef __TX49__
#ifdef IODC_IRQ_USED
extern ISR(IODC_Irq0_it);
extern ISR(IODC_Irq1_it);
extern ISR(IODC_Irq2_it);
extern ISR(IODC_Irq3_it);
#endif /* IODC_IRQ_USED */
#endif /* __TX49__ */

#if defined(__FSL_IMX53x__) || defined(__FSL_IMX6x__)
#if IODC_IT_IRQ0 == _USED_
extern ISR(IODC_Irq0_it);
#endif /* IODC_IT_IRQ0 == _USED_ */

#if IODC_IT_IRQ1 == _USED_
extern ISR(IODC_Irq1_it);
#endif /* IODC_IT_IRQ1 == _USED_ */

#if IODC_IT_IRQ2 == _USED_
extern ISR(IODC_Irq2_it);
#endif /* IODC_IT_IRQ2 == _USED_ */

#if IODC_IT_IRQ3 == _USED_
extern ISR(IODC_Irq3_it);
#endif /* IODC_IT_IRQ3 == _USED_ */

#if IODC_IT_IRQ4 == _USED_
extern ISR(IODC_Irq4_it);
#endif /* IODC_IT_IRQ4 == _USED_ */

#if IODC_IT_IRQ5 == _USED_
extern ISR(IODC_Irq5_it);
#endif /* IODC_IT_IRQ5 == _USED_ */

#if IODC_IT_IRQ6 == _USED_
extern ISR(IODC_Irq6_it);
#endif /* IODC_IT_IRQ6 == _USED_ */

#if IODC_IT_IRQ7 == _USED_
extern ISR(IODC_Irq7_it);
#endif /* IODC_IT_IRQ7 == _USED_ */

#if IODC_IT_IRQ8 == _USED_
extern ISR(IODC_Irq8_it);
#endif /* IODC_IT_IRQ8 == _USED_ */

#if IODC_IT_IRQ9 == _USED_
extern ISR(IODC_Irq9_it);
#endif /* IODC_IT_IRQ9 == _USED_ */

#if IODC_IT_IRQ10 == _USED_
extern ISR(IODC_Irq10_it);
#endif /* IODC_IT_IRQ10 == _USED_ */

#if IODC_IT_IRQ11 == _USED_
extern ISR(IODC_Irq11_it);
#endif /* IODC_IT_IRQ11 == _USED_ */

#if IODC_IT_IRQ12 == _USED_
extern ISR(IODC_Irq12_it);
#endif /* IODC_IT_IRQ12 == _USED_ */

#if IODC_IT_IRQ13 == _USED_
extern ISR(IODC_Irq13_it);
#endif /* IODC_IT_IRQ13 == _USED_ */

#if IODC_IT_IRQ14 == _USED_
extern ISR(IODC_Irq14_it);
#endif /* IODC_IT_IRQ14 == _USED_ */

#if IODC_IT_IRQ15 == _USED_
extern ISR(IODC_Irq15_it);
#endif /* IODC_IT_IRQ15 == _USED_ */

#if IODC_IT_IRQ16 == _USED_
extern ISR(IODC_Irq16_it);
#endif /* IODC_IT_IRQ16 == _USED_ */

#if IODC_IT_IRQ17 == _USED_
extern ISR(IODC_Irq17_it);
#endif /* IODC_IT_IRQ17 == _USED_ */

#if IODC_IT_IRQ18 == _USED_
extern ISR(IODC_Irq18_it);
#endif /* IODC_IT_IRQ18 == _USED_ */

#if IODC_IT_IRQ19 == _USED_
extern ISR(IODC_Irq19_it);
#endif /* IODC_IT_IRQ19 == _USED_ */

#if IODC_IT_IRQ20 == _USED_
extern ISR(IODC_Irq20_it);
#endif /* IODC_IT_IRQ20 == _USED_ */

#if IODC_IT_IRQ21 == _USED_
extern ISR(IODC_Irq21_it);
#endif /* IODC_IT_IRQ21 == _USED_ */

#if IODC_IT_IRQ22 == _USED_
extern ISR(IODC_Irq22_it);
#endif /* IODC_IT_IRQ22 == _USED_ */

#if IODC_IT_IRQ23 == _USED_
extern ISR(IODC_Irq23_it);
#endif /* IODC_IT_IRQ23 == _USED_ */

#if IODC_IT_IRQ24 == _USED_
extern ISR(IODC_Irq24_it);
#endif /* IODC_IT_IRQ24 == _USED_ */

#if IODC_IT_IRQ25 == _USED_
extern ISR(IODC_Irq25_it);
#endif /* IODC_IT_IRQ25 == _USED_ */

#if IODC_IT_IRQ26 == _USED_
extern ISR(IODC_Irq26_it);
#endif /* IODC_IT_IRQ26 == _USED_ */

#if IODC_IT_IRQ27 == _USED_
extern ISR(IODC_Irq27_it);
#endif /* IODC_IT_IRQ27 == _USED_ */

#if IODC_IT_IRQ28 == _USED_
extern ISR(IODC_Irq28_it);
#endif /* IODC_IT_IRQ28 == _USED_ */

#if IODC_IT_IRQ29 == _USED_
extern ISR(IODC_Irq29_it);
#endif /* IODC_IT_IRQ29 == _USED_ */

#if IODC_IT_IRQ30 == _USED_
extern ISR(IODC_Irq30_it);
#endif /* IODC_IT_IRQ30 == _USED_ */

#if IODC_IT_IRQ31 == _USED_
extern ISR(IODC_Irq31_it);
#endif /* IODC_IT_IRQ31 == _USED_ */

#if IODC_IT_IRQ32 == _USED_
extern ISR(IODC_Irq32_it);
#endif /* IODC_IT_IRQ32 == _USED_ */

#if IODC_IT_IRQ33 == _USED_
extern ISR(IODC_Irq33_it);
#endif /* IODC_IT_IRQ33 == _USED_ */

#if IODC_IT_IRQ34 == _USED_
extern ISR(IODC_Irq34_it);
#endif /* IODC_IT_IRQ34 == _USED_ */

#if IODC_IT_IRQ35 == _USED_
extern ISR(IODC_Irq35_it);
#endif /* IODC_IT_IRQ35 == _USED_ */

#if IODC_IT_IRQ36 == _USED_
extern ISR(IODC_Irq36_it);
#endif /* IODC_IT_IRQ36 == _USED_ */

#if IODC_IT_IRQ37 == _USED_
extern ISR(IODC_Irq37_it);
#endif /* IODC_IT_IRQ37 == _USED_ */

#if IODC_IT_IRQ38 == _USED_
extern ISR(IODC_Irq38_it);
#endif /* IODC_IT_IRQ38 == _USED_ */

#if IODC_IT_IRQ39 == _USED_
extern ISR(IODC_Irq39_it);
#endif /* IODC_IT_IRQ39 == _USED_ */

#if IODC_IT_IRQ40 == _USED_
extern ISR(IODC_Irq40_it);
#endif /* IODC_IT_IRQ40 == _USED_ */

#if IODC_IT_IRQ41 == _USED_
extern ISR(IODC_Irq41_it);
#endif /* IODC_IT_IRQ41 == _USED_ */

#if IODC_IT_IRQ42 == _USED_
extern ISR(IODC_Irq42_it);
#endif /* IODC_IT_IRQ42 == _USED_ */

#if IODC_IT_IRQ43 == _USED_
extern ISR(IODC_Irq43_it);
#endif /* IODC_IT_IRQ43 == _USED_ */

#if IODC_IT_IRQ44 == _USED_
extern ISR(IODC_Irq44_it);
#endif /* IODC_IT_IRQ44 == _USED_ */

#if IODC_IT_IRQ45 == _USED_
extern ISR(IODC_Irq45_it);
#endif /* IODC_IT_IRQ45 == _USED_ */

#if IODC_IT_IRQ46 == _USED_
extern ISR(IODC_Irq46_it);
#endif /* IODC_IT_IRQ46 == _USED_ */

#if IODC_IT_IRQ47 == _USED_
extern ISR(IODC_Irq47_it);
#endif /* IODC_IT_IRQ47 == _USED_ */

#if IODC_IT_IRQ48 == _USED_
extern ISR(IODC_Irq48_it);
#endif /* IODC_IT_IRQ48 == _USED_ */

#if IODC_IT_IRQ49 == _USED_
extern ISR(IODC_Irq49_it);
#endif /* IODC_IT_IRQ49 == _USED_ */

#if IODC_IT_IRQ50 == _USED_
extern ISR(IODC_Irq50_it);
#endif /* IODC_IT_IRQ50 == _USED_ */

#if IODC_IT_IRQ51 == _USED_
extern ISR(IODC_Irq51_it);
#endif /* IODC_IT_IRQ51 == _USED_ */

#if IODC_IT_IRQ52 == _USED_
extern ISR(IODC_Irq52_it);
#endif /* IODC_IT_IRQ52 == _USED_ */

#if IODC_IT_IRQ53 == _USED_
extern ISR(IODC_Irq53_it);
#endif /* IODC_IT_IRQ53 == _USED_ */

#if IODC_IT_IRQ54 == _USED_
extern ISR(IODC_Irq54_it);
#endif /* IODC_IT_IRQ54 == _USED_ */

#if IODC_IT_IRQ55 == _USED_
extern ISR(IODC_Irq55_it);
#endif /* IODC_IT_IRQ55 == _USED_ */

#if IODC_IT_IRQ56 == _USED_
extern ISR(IODC_Irq56_it);
#endif /* IODC_IT_IRQ56 == _USED_ */

#if IODC_IT_IRQ57 == _USED_
extern ISR(IODC_Irq57_it);
#endif /* IODC_IT_IRQ57 == _USED_ */

#if IODC_IT_IRQ58 == _USED_
extern ISR(IODC_Irq58_it);
#endif /* IODC_IT_IRQ58 == _USED_ */

#if IODC_IT_IRQ59 == _USED_
extern ISR(IODC_Irq59_it);
#endif /* IODC_IT_IRQ59 == _USED_ */

#if IODC_IT_IRQ60 == _USED_
extern ISR(IODC_Irq60_it);
#endif /* IODC_IT_IRQ60 == _USED_ */

#if IODC_IT_IRQ61 == _USED_
extern ISR(IODC_Irq61_it);
#endif /* IODC_IT_IRQ61 == _USED_ */

#if IODC_IT_IRQ62 == _USED_
extern ISR(IODC_Irq62_it);
#endif /* IODC_IT_IRQ62 == _USED_ */

#if IODC_IT_IRQ63 == _USED_
extern ISR(IODC_Irq63_it);
#endif /* IODC_IT_IRQ63 == _USED_ */

#if IODC_IT_IRQ64 == _USED_
extern ISR(IODC_Irq64_it);
#endif /* IODC_IT_IRQ64 == _USED_ */

#if IODC_IT_IRQ65 == _USED_
extern ISR(IODC_Irq65_it);
#endif /* IODC_IT_IRQ65 == _USED_ */

#if IODC_IT_IRQ66 == _USED_
extern ISR(IODC_Irq66_it);
#endif /* IODC_IT_IRQ66 == _USED_ */

#if IODC_IT_IRQ67 == _USED_
extern ISR(IODC_Irq67_it);
#endif /* IODC_IT_IRQ67 == _USED_ */

#if IODC_IT_IRQ68 == _USED_
extern ISR(IODC_Irq68_it);
#endif /* IODC_IT_IRQ68 == _USED_ */

#if IODC_IT_IRQ69 == _USED_
extern ISR(IODC_Irq69_it);
#endif /* IODC_IT_IRQ69 == _USED_ */

#if IODC_IT_IRQ70 == _USED_
extern ISR(IODC_Irq70_it);
#endif /* IODC_IT_IRQ70 == _USED_ */

#if IODC_IT_IRQ71 == _USED_
extern ISR(IODC_Irq71_it);
#endif /* IODC_IT_IRQ71 == _USED_ */

#if IODC_IT_IRQ72 == _USED_
extern ISR(IODC_Irq72_it);
#endif /* IODC_IT_IRQ72 == _USED_ */

#if IODC_IT_IRQ73 == _USED_
extern ISR(IODC_Irq73_it);
#endif /* IODC_IT_IRQ73 == _USED_ */

#if IODC_IT_IRQ74 == _USED_
extern ISR(IODC_Irq74_it);
#endif /* IODC_IT_IRQ74 == _USED_ */

#if IODC_IT_IRQ75 == _USED_
extern ISR(IODC_Irq75_it);
#endif /* IODC_IT_IRQ75 == _USED_ */

#if IODC_IT_IRQ76 == _USED_
extern ISR(IODC_Irq76_it);
#endif /* IODC_IT_IRQ76 == _USED_ */

#if IODC_IT_IRQ77 == _USED_
extern ISR(IODC_Irq77_it);
#endif /* IODC_IT_IRQ77 == _USED_ */

#if IODC_IT_IRQ78 == _USED_
extern ISR(IODC_Irq78_it);
#endif /* IODC_IT_IRQ78 == _USED_ */

#if IODC_IT_IRQ79 == _USED_
extern ISR(IODC_Irq79_it);
#endif /* IODC_IT_IRQ79 == _USED_ */

#if IODC_IT_IRQ80 == _USED_
extern ISR(IODC_Irq80_it);
#endif /* IODC_IT_IRQ80 == _USED_ */

#if IODC_IT_IRQ81 == _USED_
extern ISR(IODC_Irq81_it);
#endif /* IODC_IT_IRQ81 == _USED_ */

#if IODC_IT_IRQ82 == _USED_
extern ISR(IODC_Irq82_it);
#endif /* IODC_IT_IRQ82 == _USED_ */

#if IODC_IT_IRQ83 == _USED_
extern ISR(IODC_Irq83_it);
#endif /* IODC_IT_IRQ83 == _USED_ */

#if IODC_IT_IRQ84 == _USED_
extern ISR(IODC_Irq84_it);
#endif /* IODC_IT_IRQ84 == _USED_ */

#if IODC_IT_IRQ85 == _USED_
extern ISR(IODC_Irq85_it);
#endif /* IODC_IT_IRQ85 == _USED_ */

#if IODC_IT_IRQ86 == _USED_
extern ISR(IODC_Irq86_it);
#endif /* IODC_IT_IRQ86 == _USED_ */

#if IODC_IT_IRQ87 == _USED_
extern ISR(IODC_Irq87_it);
#endif /* IODC_IT_IRQ87 == _USED_ */

#if IODC_IT_IRQ88 == _USED_
extern ISR(IODC_Irq88_it);
#endif /* IODC_IT_IRQ88 == _USED_ */

#if IODC_IT_IRQ89 == _USED_
extern ISR(IODC_Irq89_it);
#endif /* IODC_IT_IRQ89 == _USED_ */

#if IODC_IT_IRQ90 == _USED_
extern ISR(IODC_Irq90_it);
#endif /* IODC_IT_IRQ90 == _USED_ */

#if IODC_IT_IRQ91 == _USED_
extern ISR(IODC_Irq91_it);
#endif /* IODC_IT_IRQ91 == _USED_ */

#if IODC_IT_IRQ92 == _USED_
extern ISR(IODC_Irq92_it);
#endif /* IODC_IT_IRQ92 == _USED_ */

#if IODC_IT_IRQ93 == _USED_
extern ISR(IODC_Irq93_it);
#endif /* IODC_IT_IRQ93 == _USED_ */

#if IODC_IT_IRQ94 == _USED_
extern ISR(IODC_Irq94_it);
#endif /* IODC_IT_IRQ94 == _USED_ */

#if IODC_IT_IRQ95 == _USED_
extern ISR(IODC_Irq95_it);
#endif /* IODC_IT_IRQ95 == _USED_ */

#if IODC_IT_IRQ96 == _USED_
extern ISR(IODC_Irq96_it);
#endif /* IODC_IT_IRQ96 == _USED_ */

#if IODC_IT_IRQ97 == _USED_
extern ISR(IODC_Irq97_it);
#endif /* IODC_IT_IRQ97 == _USED_ */

#if IODC_IT_IRQ98 == _USED_
extern ISR(IODC_Irq98_it);
#endif /* IODC_IT_IRQ98 == _USED_ */

#if IODC_IT_IRQ99 == _USED_
extern ISR(IODC_Irq99_it);
#endif /* IODC_IT_IRQ99 == _USED_ */

#if IODC_IT_IRQ100 == _USED_
extern ISR(IODC_Irq100_it);
#endif /* IODC_IT_IRQ100 == _USED_ */

#if IODC_IT_IRQ101 == _USED_
extern ISR(IODC_Irq101_it);
#endif /* IODC_IT_IRQ101 == _USED_ */

#if IODC_IT_IRQ102 == _USED_
extern ISR(IODC_Irq102_it);
#endif /* IODC_IT_IRQ102 == _USED_ */

#if IODC_IT_IRQ103 == _USED_
extern ISR(IODC_Irq103_it);
#endif /* IODC_IT_IRQ103 == _USED_ */

#if IODC_IT_IRQ104 == _USED_
extern ISR(IODC_Irq104_it);
#endif /* IODC_IT_IRQ104 == _USED_ */

#if IODC_IT_IRQ105 == _USED_
extern ISR(IODC_Irq105_it);
#endif /* IODC_IT_IRQ105 == _USED_ */

#if IODC_IT_IRQ106 == _USED_
extern ISR(IODC_Irq106_it);
#endif /* IODC_IT_IRQ106 == _USED_ */

#if IODC_IT_IRQ107 == _USED_
extern ISR(IODC_Irq107_it);
#endif /* IODC_IT_IRQ107 == _USED_ */

#if IODC_IT_IRQ108 == _USED_
extern ISR(IODC_Irq108_it);
#endif /* IODC_IT_IRQ108 == _USED_ */

#if IODC_IT_IRQ109 == _USED_
extern ISR(IODC_Irq109_it);
#endif /* IODC_IT_IRQ109 == _USED_ */

#if IODC_IT_IRQ110 == _USED_
extern ISR(IODC_Irq110_it);
#endif /* IODC_IT_IRQ110 == _USED_ */

#if IODC_IT_IRQ111 == _USED_
extern ISR(IODC_Irq111_it);
#endif /* IODC_IT_IRQ111 == _USED_ */

#if IODC_IT_IRQ112 == _USED_
extern ISR(IODC_Irq112_it);
#endif /* IODC_IT_IRQ112 == _USED_ */

#if IODC_IT_IRQ113 == _USED_
extern ISR(IODC_Irq113_it);
#endif /* IODC_IT_IRQ113 == _USED_ */

#if IODC_IT_IRQ114 == _USED_
extern ISR(IODC_Irq114_it);
#endif /* IODC_IT_IRQ114 == _USED_ */

#if IODC_IT_IRQ115 == _USED_
extern ISR(IODC_Irq115_it);
#endif /* IODC_IT_IRQ115 == _USED_ */

#if IODC_IT_IRQ116 == _USED_
extern ISR(IODC_Irq116_it);
#endif /* IODC_IT_IRQ116 == _USED_ */

#if IODC_IT_IRQ117 == _USED_
extern ISR(IODC_Irq117_it);
#endif /* IODC_IT_IRQ117 == _USED_ */

#if IODC_IT_IRQ118 == _USED_
extern ISR(IODC_Irq118_it);
#endif /* IODC_IT_IRQ118 == _USED_ */

#if IODC_IT_IRQ119 == _USED_
extern ISR(IODC_Irq119_it);
#endif /* IODC_IT_IRQ119 == _USED_ */

#if IODC_IT_IRQ120 == _USED_
extern ISR(IODC_Irq120_it);
#endif /* IODC_IT_IRQ120 == _USED_ */

#if IODC_IT_IRQ121 == _USED_
extern ISR(IODC_Irq121_it);
#endif /* IODC_IT_IRQ121 == _USED_ */

#if IODC_IT_IRQ122 == _USED_
extern ISR(IODC_Irq122_it);
#endif /* IODC_IT_IRQ122 == _USED_ */

#if IODC_IT_IRQ123 == _USED_
extern ISR(IODC_Irq123_it);
#endif /* IODC_IT_IRQ123 == _USED_ */

#if IODC_IT_IRQ124 == _USED_
extern ISR(IODC_Irq124_it);
#endif /* IODC_IT_IRQ124 == _USED_ */

#if IODC_IT_IRQ125 == _USED_
extern ISR(IODC_Irq125_it);
#endif /* IODC_IT_IRQ125 == _USED_ */

#if IODC_IT_IRQ126 == _USED_
extern ISR(IODC_Irq126_it);
#endif /* IODC_IT_IRQ126 == _USED_ */

#if IODC_IT_IRQ127 == _USED_
extern ISR(IODC_Irq127_it);
#endif /* IODC_IT_IRQ127 == _USED_ */
#endif /* __FSL_IMX53x__ , __FSL_IMX6x__*/

#ifdef __REL_RL78__
#ifdef __REL_RL78_D1x__
#ifdef __REL_RL78_D1A__
#if IODC_IT_IRQ0 == _USED_
extern ISR(IODC_Irq0_it);
#endif /* IODC_IT_IRQ0 == _USED_ */

#if IODC_IT_IRQ1 == _USED_
extern ISR(IODC_Irq1_it);
#endif /* IODC_IT_IRQ1 == _USED_ */

#if IODC_IT_IRQ2 == _USED_
extern ISR(IODC_Irq2_it);
#endif /* IODC_IT_IRQ2 == _USED_ */

#if IODC_IT_IRQ3 == _USED_
extern ISR(IODC_Irq3_it);
#endif /* IODC_IT_IRQ3 == _USED_ */

#if IODC_IT_IRQ4 == _USED_
extern ISR(IODC_Irq4_it);
#endif /* IODC_IT_IRQ4 == _USED_ */

#if IODC_IT_IRQ5 == _USED_
extern ISR(IODC_Irq5_it);
#endif /* IODC_IT_IRQ5 == _USED_ */

#endif /* __REL_RL78_D1A__ */
#endif /* __REL_RL78_D1x__ */

#ifdef __REL_RL78_F1x__
#ifdef __REL_RL78_F12__
#if IODC_IT_IRQ0 == _USED_
extern ISR(IODC_Irq0_it);
#endif /* IODC_IT_IRQ0 == _USED_ */

#if IODC_IT_IRQ1 == _USED_
extern ISR(IODC_Irq1_it);
#endif /* IODC_IT_IRQ1 == _USED_ */

#if IODC_IT_IRQ2 == _USED_
extern ISR(IODC_Irq2_it);
#endif /* IODC_IT_IRQ2 == _USED_ */

#if IODC_IT_IRQ3 == _USED_
extern ISR(IODC_Irq3_it);
#endif /* IODC_IT_IRQ3 == _USED_ */

#if IODC_IT_IRQ4 == _USED_
extern ISR(IODC_Irq4_it);
#endif /* IODC_IT_IRQ4 == _USED_ */

#if IODC_IT_IRQ5 == _USED_
extern ISR(IODC_Irq5_it);
#endif /* IODC_IT_IRQ5 == _USED_ */

#if IODC_IT_IRQ6 == _USED_
extern ISR(IODC_Irq6_it);
#endif /* IODC_IT_IRQ6 == _USED_ */

#if IODC_IT_IRQ7 == _USED_
extern ISR(IODC_Irq7_it);
#endif /* IODC_IT_IRQ7 == _USED_ */

#if IODC_IT_IRQ8 == _USED_
extern ISR(IODC_Irq8_it);
#endif /* IODC_IT_IRQ8 == _USED_ */

#if IODC_IT_IRQ9 == _USED_
extern ISR(IODC_Irq9_it);
#endif /* IODC_IT_IRQ9 == _USED_ */

#if IODC_IT_IRQ10 == _USED_
extern ISR(IODC_Irq10_it);
#endif /* IODC_IT_IRQ10 == _USED_ */

#if IODC_IT_IRQ11 == _USED_
extern ISR(IODC_Irq11_it);
#endif /* IODC_IT_IRQ11 == _USED_ */

#endif /* __REL_RL78_F12__ */
#endif /* __REL_RL78_F1x__ */
#endif /* __REL_RL78__ */

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
extern void IODC_InitSystem(void);

/*----------------------------------------------------------------------------*/
/*Name : IODC_Init                                                            */
/*Role : Initialise the hardware by using the base layer                      */
/*Interface : -                                                               */
/*Pre-condition : -                                                           */
/*Constraints :                                                               */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [initialise the port direction]                                         */
/*    [initialise a timer to control the refreshments of the matrix of leds if*/
/*      this one is used by the HW]                                           */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
extern void IODC_Init(void);

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
extern void IODC_WakeUp(void);

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
extern void IODC_Sleep(void);

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
extern TASK(IODC_Task_ts);
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
#ifdef IODC_LED_MATRIX_USED
#if IODC_LED_MATRIX_REFRESH == IODC_LED_MATRIX_ISR_REFRESH
extern ISR(IODC_RefreshLedMatrix);
#else
extern void IODC_RefreshLedMatrix(void);
#endif /* IODC_LED_MATRIX_REFRESH == IODC_LED_MATRIX_ISR_REFRESH */
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
extern void IODC_SetLedMatrixActiveLed(ubyte Column, ubyte Line, ubyte StateLed);

/*----------------------------------------------------------------------------*/
/*Name : IODC_GetLedMatrixActiveLed                                           */
/*Role : return TRUE if the led at the matrix coordinates  specified is       */
/*       enabled when the function is called                                  */
/*Interface :                                                                 */
/*----------------------------------------------------------------------------*/
extern bool_t IODC_GetLedMatrixActiveLed(ushort Column, ushort Row);

#endif /* IODC_LED_MATRIX_USED */

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
#if defined(IODC_LED_MATRIX_USED) && defined(IODC_LED_MATRIX_RELAX_TIME_USED)
extern void IODC_UpdateRelaxTimeLedMatrix(ushort battery, bool_t RelaxTimeNeed);
#endif /* IODC_LED_MATRIX_USED && IODC_LED_MATRIX_RELAX_TIME_USED */

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

#if (IODC_IRQ_READING_MATRIX_1 == _USED_) ||\
    (IODC_IRQ_READING_MATRIX_2 == _USED_)

void IODC_InputMatrixSample(void);

#endif /* (IODC_IRQ_READING_MATRIX_1 = _USED_) ||\
          (IODC_IRQ_READING_MATRIX_2 = _USED_) */

#endif /* IODC_INPUT_MATRIX_USED */


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
extern void IODC_InitEol(void);

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
extern void IODC_EolpConfigureLcdPin(void);

/*----------------------------------------------------------------------------*/
/*Name : IODC_InitEOLDigOutPin                                                */
/*Role : configure the microcontroller output pins according to the EOL needs */
/*       This function is called by EOL module.                               */
/*Interface : -                                                               */
/*----------------------------------------------------------------------------*/
extern void IODC_InitEOLDigOutPin(void);

/*----------------------------------------------------------------------------*/
/*Name : IODC_InitEOLLed                                                      */
/*Role : configure the microcontroller output pins to drive the led matrix    */
/*       This function is called by EOL module.                               */
/*Interface : -                                                               */
/*----------------------------------------------------------------------------*/
extern void IODC_InitEOLLed(void);

/*----------------------------------------------------------------------------*/
/*Name : IODC_InitEOLFrequencyInPin                                           */
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
extern void IODC_InitEOLFrequencyInPin(void);
#endif /*__EOL_ENABLE__*/

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
extern void IODC_SetIoDown(void);

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
void IODC_SetIoUp(void);

#endif /*IODC_H*/

/*_____END _____ (iodc.h) ____________________________________________________*/

