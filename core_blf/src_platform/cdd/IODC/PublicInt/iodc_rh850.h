/******************************************************************************/
/*@F_NAME:               iodc_rh850.h                                         */
/*@F_PURPOSE:            Public interface of iodc module                      */
/*@F_CREATED_BY:         shubin liang                                         */
/*@F_CREATION_DATE:      2017 03 17                                           */
/*@F_MPROC_TYPE:         RH850 F1x                                            */
/************************************** (C) Copyright 2013 Magneti Marelli ****/

#ifndef IODC_RH850_H
#define IODC_RH850_H

#ifdef __RH850__
/*______ I N C L U D E - F I L E S ___________________________________________*/

#include "syst.h"


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
#define   IODC_IT_LOW_LEVEL     ((ubyte)  4)

#ifndef IODC_IT_TOGGLE
#define   IODC_IT_TOGGLE        ((ubyte)  5)
#endif /*IODC_IT_TOGGLE*/

#ifndef IODC_LED_TURN_ON
#define   IODC_LED_TURN_ON      IODC_ACTIVE
#endif /*IODC_LED_TURN_ON*/

#ifndef IODC_LED_TURN_OFF
#define   IODC_LED_TURN_OFF     IODC_INACTIVE
#endif /*IODC_LED_TURN_OFF*/

#ifdef __RH850__
#define   IODC_IRQ0         ((ubyte)  0)
#define   IODC_IRQ1         ((ubyte)  1)
#define   IODC_IRQ2         ((ubyte)  2)
#define   IODC_IRQ3         ((ubyte)  3)
#define   IODC_IRQ4         ((ubyte)  4)
#define   IODC_IRQ5         ((ubyte)  5)
#define   IODC_IRQ6         ((ubyte)  6)
#define   IODC_IRQ7         ((ubyte)  7)
#define   IODC_IRQ8         ((ubyte)  8)
#define   IODC_IRQ9         ((ubyte)  9)
#define   IODC_IRQ10        ((ubyte) 10)
#define   IODC_IRQ11        ((ubyte) 11)
#define   IODC_IRQ12        ((ubyte) 12)
#define   IODC_IRQ13        ((ubyte) 13)
#define   IODC_IRQ14        ((ubyte) 14)
#define   IODC_IRQ15        ((ubyte) 15)
#define   IODC_IRQ_NMI      ((ubyte) 16)
#endif /* __RH850__ */


#if (defined(__RH850_F1x__))
#if (defined(__RH850_F1L__) || defined(__RH850_F1K__))
/*TAUD*/
#ifdef IODC_INPUT_TAUD002_IS_P000
#define IODC_DirectIn_Port_TIMER_D002    0
#define IODC_DirectIn_Bit_TIMER_D002     0
#define IODC_DirectIn_Logic_TIMER_D002   IODC_POSITIVE
#endif /* IODC_INPUT_TAUD002_IS_P000 */

#ifdef IODC_INPUT_TAUD004_IS_P001
#define IODC_DirectIn_Port_TIMER_D004    0
#define IODC_DirectIn_Bit_TIMER_D004     1
#define IODC_DirectIn_Logic_TIMER_D004   IODC_POSITIVE
#endif /* IODC_INPUT_TAUD004_IS_P001 */

#ifdef IODC_INPUT_TAUD006_IS_P002
#define IODC_DirectIn_Port_TIMER_D006    0
#define IODC_DirectIn_Bit_TIMER_D006     2
#define IODC_DirectIn_Logic_TIMER_D006   IODC_POSITIVE
#endif /* IODC_INPUT_TAUD006_IS_P002 */

#ifdef IODC_INPUT_TAUD008_IS_P003
#define IODC_DirectIn_Port_TIMER_D008    0
#define IODC_DirectIn_Bit_TIMER_D008     3
#define IODC_DirectIn_Logic_TIMER_D008   IODC_POSITIVE
#endif /* IODC_INPUT_TAUD008_IS_P003 */

#ifdef IODC_INPUT_TAUD000_IS_P900
#define IODC_DirectIn_Port_TIMER_D000    9
#define IODC_DirectIn_Bit_TIMER_D000     0
#define IODC_DirectIn_Logic_TIMER_D000   IODC_POSITIVE
#endif /* IODC_INPUT_TAUD000_IS_P900 */

#ifdef IODC_INPUT_TAUD002_IS_P901
#define IODC_DirectIn_Port_TIMER_D002    9
#define IODC_DirectIn_Bit_TIMER_D002     2
#define IODC_DirectIn_Logic_TIMER_D002   IODC_POSITIVE
#endif /* IODC_INPUT_TAUD002_IS_P901 */

#ifdef IODC_INPUT_TAUD001_IS_P1000
#define IODC_DirectIn_Port_TIMER_D001    10
#define IODC_DirectIn_Bit_TIMER_D001     0
#define IODC_DirectIn_Logic_TIMER_D001   IODC_POSITIVE
#endif /* IODC_INPUT_TAUD001_IS_P1000 */

#ifdef IODC_INPUT_TAUD003_IS_P1001
#define IODC_DirectIn_Port_TIMER_D003    10
#define IODC_DirectIn_Bit_TIMER_D003     1
#define IODC_DirectIn_Logic_TIMER_D003   IODC_POSITIVE
#endif /* IODC_INPUT_TAUD003_IS_P1001 */

#ifdef IODC_INPUT_TAUD005_IS_P1002
#define IODC_DirectIn_Port_TIMER_D005    10
#define IODC_DirectIn_Bit_TIMER_D005     2
#define IODC_DirectIn_Logic_TIMER_D005   IODC_POSITIVE
#endif /* IODC_INPUT_TAUD005_IS_P1002 */

#ifdef IODC_INPUT_TAUD007_IS_P1003
#define IODC_DirectIn_Port_TIMER_D007    10
#define IODC_DirectIn_Bit_TIMER_D007     3
#define IODC_DirectIn_Logic_TIMER_D007   IODC_POSITIVE
#endif /* IODC_INPUT_TAUD007_IS_P1003 */

#ifdef IODC_INPUT_TAUD009_IS_P1004
#define IODC_DirectIn_Port_TIMER_D009    10
#define IODC_DirectIn_Bit_TIMER_D009     4
#define IODC_DirectIn_Logic_TIMER_D009   IODC_POSITIVE
#endif /* IODC_INPUT_TAUD009_IS_P1004 */

#ifdef IODC_INPUT_TAUD011_IS_P1005
#define IODC_DirectIn_Port_TIMER_D011    10
#define IODC_DirectIn_Bit_TIMER_D011     5
#define IODC_DirectIn_Logic_TIMER_D011   IODC_POSITIVE
#endif /* IODC_INPUT_TAUD011_IS_P1005 */

#ifdef IODC_INPUT_TAUD013_IS_P1006
#define IODC_DirectIn_Port_TIMER_D013    10
#define IODC_DirectIn_Bit_TIMER_D013     6
#define IODC_DirectIn_Logic_TIMER_D013   IODC_POSITIVE
#endif /* IODC_INPUT_TAUD013_IS_P1006 */

#ifdef IODC_INPUT_TAUD015_IS_P1007
#define IODC_DirectIn_Port_TIMER_D015    10
#define IODC_DirectIn_Bit_TIMER_D015     7
#define IODC_DirectIn_Logic_TIMER_D015   IODC_POSITIVE
#endif /* IODC_INPUT_TAUD015_IS_P1007 */

#ifdef IODC_INPUT_TAUD010_IS_P1008
#define IODC_DirectIn_Port_TIMER_D010    10
#define IODC_DirectIn_Bit_TIMER_D010     8
#define IODC_DirectIn_Logic_TIMER_D010   IODC_POSITIVE
#endif /* IODC_INPUT_TAUD010_IS_P1008 */

#ifdef IODC_INPUT_TAUD012_IS_P1009
#define IODC_DirectIn_Port_TIMER_D012    10
#define IODC_DirectIn_Bit_TIMER_D012     9
#define IODC_DirectIn_Logic_TIMER_D012   IODC_POSITIVE
#endif /* IODC_INPUT_TAUD012_IS_P1009 */

#ifdef IODC_INPUT_TAUD014_IS_P1010
#define IODC_DirectIn_Port_TIMER_D014    10
#define IODC_DirectIn_Bit_TIMER_D014     10
#define IODC_DirectIn_Logic_TIMER_D014   IODC_POSITIVE
#endif /* IODC_INPUT_TAUD014_IS_P1010 */


/*TAUB*/
#ifdef IODC_INPUT_TAUB000_IS_P007
#define IODC_DirectIn_Port_TIMER_B000    0
#define IODC_DirectIn_Bit_TIMER_B000     7
#define IODC_DirectIn_Logic_TIMER_B000   IODC_POSITIVE
#endif /* IODC_INPUT_TAUB000_IS_P007 */

#ifdef IODC_INPUT_TAUB002_IS_P008
#define IODC_DirectIn_Port_TIMER_B002    0
#define IODC_DirectIn_Bit_TIMER_B002     8
#define IODC_DirectIn_Logic_TIMER_B002   IODC_POSITIVE
#endif /* IODC_INPUT_TAUB002_IS_P008 */

#ifdef IODC_INPUT_TAUB004_IS_P009
#define IODC_DirectIn_Port_TIMER_B004    0
#define IODC_DirectIn_Bit_TIMER_B004     9
#define IODC_DirectIn_Logic_TIMER_B004   IODC_POSITIVE
#endif /* IODC_INPUT_TAUB004_IS_P009 */

#ifdef IODC_INPUT_TAUB006_IS_P010
#define IODC_DirectIn_Port_TIMER_B006    0
#define IODC_DirectIn_Bit_TIMER_B006     10
#define IODC_DirectIn_Logic_TIMER_B004   IODC_POSITIVE
#endif /* IODC_INPUT_TAUB006_IS_P010 */

#ifdef IODC_INPUT_TAUB008_IS_P011
#define IODC_DirectIn_Port_TIMER_B008    0
#define IODC_DirectIn_Bit_TIMER_B008     11
#define IODC_DirectIn_Logic_TIMER_B008   IODC_POSITIVE
#endif /* IODC_INPUT_TAUB008_IS_P011 */

#ifdef IODC_INPUT_TAUB010_IS_P012
#define IODC_DirectIn_Port_TIMER_B010    0
#define IODC_DirectIn_Bit_TIMER_B010     12
#define IODC_DirectIn_Logic_TIMER_B010   IODC_POSITIVE
#endif /* IODC_INPUT_TAUB010_IS_P012 */

#ifdef IODC_INPUT_TAUB012_IS_P013
#define IODC_DirectIn_Port_TIMER_B012    0
#define IODC_DirectIn_Bit_TIMER_B012     13
#define IODC_DirectIn_Logic_TIMER_B012   IODC_POSITIVE
#endif /* IODC_INPUT_TAUB012_IS_P013 */

#ifdef IODC_INPUT_TAUB014_IS_P014
#define IODC_DirectIn_Port_TIMER_B014    0
#define IODC_DirectIn_Bit_TIMER_B014     14
#define IODC_DirectIn_Logic_TIMER_B014   IODC_POSITIVE
#endif /* IODC_INPUT_TAUB014_IS_P014 */

#ifdef IODC_INPUT_TAUB001_IS_P1011
#define IODC_DirectIn_Port_TIMER_B001    10
#define IODC_DirectIn_Bit_TIMER_B001     11
#define IODC_DirectIn_Logic_TIMER_B001   IODC_POSITIVE
#endif /* IODC_INPUT_TAUB001_IS_P1011 */

#ifdef IODC_INPUT_TAUB003_IS_P1012
#define IODC_DirectIn_Port_TIMER_B003    10
#define IODC_DirectIn_Bit_TIMER_B003     12
#define IODC_DirectIn_Logic_TIMER_B003   IODC_POSITIVE
#endif /* IODC_INPUT_TAUB003_IS_P1012 */

#ifdef IODC_INPUT_TAUB005_IS_P1013
#define IODC_DirectIn_Port_TIMER_B005    10
#define IODC_DirectIn_Bit_TIMER_B005     13
#define IODC_DirectIn_Logic_TIMER_B005   IODC_POSITIVE
#endif /* IODC_INPUT_TAUB005_IS_P1013 */

#ifdef IODC_INPUT_TAUB007_IS_P1014
#define IODC_DirectIn_Port_TIMER_B007    10
#define IODC_DirectIn_Bit_TIMER_B007     14
#define IODC_DirectIn_Logic_TIMER_B007   IODC_POSITIVE
#endif /* IODC_INPUT_TAUB007_IS_P1014 */

#ifdef IODC_INPUT_TAUB009_IS_P1015
#define IODC_DirectIn_Port_TIMER_B007    10
#define IODC_DirectIn_Bit_TIMER_B009     15
#define IODC_DirectIn_Logic_TIMER_B009   IODC_POSITIVE
#endif /* IODC_INPUT_TAUB009_IS_P1015 */

#ifdef IODC_INPUT_TAUB011_IS_P1100
#define IODC_DirectIn_Port_TIMER_B011    11
#define IODC_DirectIn_Bit_TIMER_B011     0
#define IODC_DirectIn_Logic_TIMER_B011   IODC_POSITIVE
#endif /* IODC_INPUT_TAUB011_IS_P1100 */

#ifdef IODC_INPUT_TAUB013_IS_P1101
#define IODC_DirectIn_Port_TIMER_B013    11
#define IODC_DirectIn_Bit_TIMER_B013     1
#define IODC_DirectIn_Logic_TIMER_B013   IODC_POSITIVE
#endif /* IODC_INPUT_TAUB013_IS_P1101 */

#ifdef IODC_INPUT_TAUB015_IS_P1102
#define IODC_DirectIn_Port_TIMER_B015    11
#define IODC_DirectIn_Bit_TIMER_B015     2
#define IODC_DirectIn_Logic_TIMER_B015   IODC_POSITIVE
#endif /* IODC_INPUT_TAUB015_IS_P1102 */

#ifdef IODC_INPUT_TAUB101_IS_P1103
#define IODC_DirectIn_Port_TIMER_B101    11
#define IODC_DirectIn_Bit_TIMER_B101     3
#define IODC_DirectIn_Logic_TIMER_B101   IODC_POSITIVE
#endif /* IODC_INPUT_TAUB101_IS_P1103 */

#ifdef IODC_INPUT_TAUB103_IS_P1104
#define IODC_DirectIn_Port_TIMER_B103    11
#define IODC_DirectIn_Bit_TIMER_B103     4
#define IODC_DirectIn_Logic_TIMER_B103   IODC_POSITIVE
#endif /* IODC_INPUT_TAUB103_IS_P1104 */

#ifdef IODC_INPUT_TAUB105_IS_P1105
#define IODC_DirectIn_Port_TIMER_B105    11
#define IODC_DirectIn_Bit_TIMER_B105     5
#define IODC_DirectIn_Logic_TIMER_B105   IODC_POSITIVE
#endif /* IODC_INPUT_TAUB105_IS_P1105 */

#ifdef IODC_INPUT_TAUB107_IS_P1106
#define IODC_DirectIn_Port_TIMER_B107    11
#define IODC_DirectIn_Bit_TIMER_B107     6
#define IODC_DirectIn_Logic_TIMER_B107   IODC_POSITIVE
#endif /* IODC_INPUT_TAUB107_IS_P1106 */

#ifdef IODC_INPUT_TAUB109_IS_P1107
#define IODC_DirectIn_Port_TIMER_B109    11
#define IODC_DirectIn_Bit_TIMER_B109     7
#define IODC_DirectIn_Logic_TIMER_B109   IODC_POSITIVE
#endif /* IODC_INPUT_TAUB109_IS_P1107 */

#ifdef IODC_INPUT_TAUB111_IS_P1108
#define IODC_DirectIn_Port_TIMER_B111    11
#define IODC_DirectIn_Bit_TIMER_B111     8
#define IODC_DirectIn_Logic_TIMER_B111   IODC_POSITIVE
#endif /* IODC_INPUT_TAUB111_IS_P1108 */

#ifdef IODC_INPUT_TAUB113_IS_P1109
#define IODC_DirectIn_Port_TIMER_B113    11
#define IODC_DirectIn_Bit_TIMER_B113     9
#define IODC_DirectIn_Logic_TIMER_B113   IODC_POSITIVE
#endif /* IODC_INPUT_TAUB113_IS_P1109 */

#ifdef IODC_INPUT_TAUB115_IS_P1110
#define IODC_DirectIn_Port_TIMER_B115    11
#define IODC_DirectIn_Bit_TIMER_B115     10
#define IODC_DirectIn_Logic_TIMER_B115   IODC_POSITIVE
#endif /* IODC_INPUT_TAUB115_IS_P1110 */

#ifdef IODC_INPUT_TAUB100_IS_P1111
#define IODC_DirectIn_Port_TIMER_B100    11
#define IODC_DirectIn_Bit_TIMER_B100     11
#define IODC_DirectIn_Logic_TIMER_B100   IODC_POSITIVE
#endif /* IODC_INPUT_TAUB100_IS_P1111 */

#ifdef IODC_INPUT_TAUB102_IS_P1112
#define IODC_DirectIn_Port_TIMER_B102    11
#define IODC_DirectIn_Bit_TIMER_B102     12
#define IODC_DirectIn_Logic_TIMER_B102   IODC_POSITIVE
#endif /* IODC_INPUT_TAUB102_IS_P1112 */

#ifdef IODC_INPUT_TAUB104_IS_P1113
#define IODC_DirectIn_Port_TIMER_B104    11
#define IODC_DirectIn_Bit_TIMER_B104     13
#define IODC_DirectIn_Logic_TIMER_B104   IODC_POSITIVE
#endif /* IODC_INPUT_TAUB104_IS_P1113 */

#ifdef IODC_INPUT_TAUB106_IS_P1114
#define IODC_DirectIn_Port_TIMER_B106    11
#define IODC_DirectIn_Bit_TIMER_B106     14
#define IODC_DirectIn_Logic_TIMER_B106   IODC_POSITIVE
#endif /* IODC_INPUT_TAUB106_IS_P1114 */

#ifdef IODC_INPUT_TAUB108_IS_P1115
#define IODC_DirectIn_Port_TIMER_B108    11
#define IODC_DirectIn_Bit_TIMER_B108     15
#define IODC_DirectIn_Logic_TIMER_B108   IODC_POSITIVE
#endif /* IODC_INPUT_TAUB108_IS_P1115 */

#ifdef IODC_INPUT_TAUB110_IS_P1200
#define IODC_DirectIn_Port_TIMER_B110    12
#define IODC_DirectIn_Bit_TIMER_B110     0
#define IODC_DirectIn_Logic_TIMER_B110   IODC_POSITIVE
#endif /* IODC_INPUT_TAUB110_IS_P1200 */

#ifdef IODC_INPUT_TAUB112_IS_P1201
#define IODC_DirectIn_Port_TIMER_B112    12
#define IODC_DirectIn_Bit_TIMER_B112     1
#define IODC_DirectIn_Logic_TIMER_B112   IODC_POSITIVE
#endif /* IODC_INPUT_TAUB112_IS_P1201 */

#ifdef IODC_INPUT_TAUB114_IS_P1202
#define IODC_DirectIn_Port_TIMER_B114    12
#define IODC_DirectIn_Bit_TIMER_B114     2
#define IODC_DirectIn_Logic_TIMER_B114   IODC_POSITIVE
#endif /* IODC_INPUT_TAUB114_IS_P1202 */


/*TAUJ*/
#ifdef IODC_INPUT_TAUJ000_IS_P800
#define IODC_DirectIn_Port_TIMER_J000    8
#define IODC_DirectIn_Bit_TIMER_J000     0
#define IODC_DirectIn_Logic_TIMER_J000   IODC_POSITIVE
#endif /* IODC_INPUT_TAUJ000_IS_P800 */

#ifdef IODC_INPUT_TAUJ001_IS_P801
#define IODC_DirectIn_Port_TIMER_J001    8
#define IODC_DirectIn_Bit_TIMER_J001     1
#define IODC_DirectIn_Logic_TIMER_J001   IODC_POSITIVE
#endif /* IODC_INPUT_TAUJ001_IS_P801 */

#ifdef IODC_INPUT_TAUJ000_IS_P802
#define IODC_DirectIn_Port_TIMER_J000    8
#define IODC_DirectIn_Bit_TIMER_J000     2
#define IODC_DirectIn_Logic_TIMER_J000   IODC_POSITIVE
#endif /* IODC_INPUT_TAUJ000_IS_P802 */

#ifdef IODC_INPUT_TAUJ001_IS_P803
#define IODC_DirectIn_Port_TIMER_J001    8
#define IODC_DirectIn_Bit_TIMER_J001     3
#define IODC_DirectIn_Logic_TIMER_J001   IODC_POSITIVE
#endif /* IODC_INPUT_TAUJ001_IS_P803 */

#ifdef IODC_INPUT_TAUJ002_IS_P804
#define IODC_DirectIn_Port_TIMER_J002    8
#define IODC_DirectIn_Bit_TIMER_J002     4
#define IODC_DirectIn_Logic_TIMER_J002   IODC_POSITIVE
#endif /* IODC_INPUT_TAUJ002_IS_P804 */

#ifdef IODC_INPUT_TAUJ003_IS_P805
#define IODC_DirectIn_Port_TIMER_J003    8
#define IODC_DirectIn_Bit_TIMER_J003     5
#define IODC_DirectIn_Logic_TIMER_J003   IODC_POSITIVE
#endif /* IODC_INPUT_TAUJ003_IS_P805 */

#ifdef IODC_INPUT_TAUJ100_IS_P904
#define IODC_DirectIn_Port_TIMER_J100    9
#define IODC_DirectIn_Bit_TIMER_J100     4
#define IODC_DirectIn_Logic_TIMER_J100   IODC_POSITIVE
#endif /* IODC_INPUT_TAUJ100_IS_P904 */

#ifdef IODC_INPUT_TAUJ101_IS_P905
#define IODC_DirectIn_Port_TIMER_J101    9
#define IODC_DirectIn_Bit_TIMER_J101     5
#define IODC_DirectIn_Logic_TIMER_J101   IODC_POSITIVE
#endif /* IODC_INPUT_TAUJ101_IS_P905 */

#endif /* ((defined(__RH850_F1L__) || defined(__RH850_F1K__)) */
#endif /* (defined(__RH850_F1x__)) */



/*______ G L O B A L - D I R E C T I V E _____________________________________*/

#ifdef __RH850_F1x__
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
#endif /*__RH850_F1x__*/




/*______ G L O B A L - M A C R O S ___________________________________________*/



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

#if     defined(__RH850_F1x__)

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

#define IODC_EnableIrq_IODC_IRQ11       IODD_EnableIrq_IODD_IRQ11
#define IODC_DisableIrq_IODC_IRQ11      IODD_DisableIrq_IODD_IRQ11
#define IODC_ReadStatusIrq_IODC_IRQ11   IODD_ReadStatusIrq_IODD_IRQ11
#define IODC_ClearStatusIrq_IODC_IRQ11  IODD_ClearStatusIrq_IODD_IRQ11

#define IODC_EnableIrq_IODC_IRQ12       IODD_EnableIrq_IODD_IRQ12
#define IODC_DisableIrq_IODC_IRQ12      IODD_DisableIrq_IODD_IRQ12
#define IODC_ReadStatusIrq_IODC_IRQ12   IODD_ReadStatusIrq_IODD_IRQ12
#define IODC_ClearStatusIrq_IODC_IRQ12  IODD_ClearStatusIrq_IODD_IRQ12

#define IODC_EnableIrq_IODC_IRQ13       IODD_EnableIrq_IODD_IRQ13
#define IODC_DisableIrq_IODC_IRQ13      IODD_DisableIrq_IODD_IRQ13
#define IODC_ReadStatusIrq_IODC_IRQ13   IODD_ReadStatusIrq_IODD_IRQ13
#define IODC_ClearStatusIrq_IODC_IRQ13  IODD_ClearStatusIrq_IODD_IRQ13

#define IODC_EnableIrq_IODC_IRQ14       IODD_EnableIrq_IODD_IRQ14
#define IODC_DisableIrq_IODC_IRQ14      IODD_DisableIrq_IODD_IRQ14
#define IODC_ReadStatusIrq_IODC_IRQ14   IODD_ReadStatusIrq_IODD_IRQ14
#define IODC_ClearStatusIrq_IODC_IRQ14  IODD_ClearStatusIrq_IODD_IRQ14

#define IODC_EnableIrq_IODC_IRQ15       IODD_EnableIrq_IODD_IRQ15
#define IODC_DisableIrq_IODC_IRQ15      IODD_DisableIrq_IODD_IRQ15
#define IODC_ReadStatusIrq_IODC_IRQ15   IODD_ReadStatusIrq_IODD_IRQ15
#define IODC_ClearStatusIrq_IODC_IRQ15  IODD_ClearStatusIrq_IODD_IRQ15
#endif  /* __RH850_F1x__     */



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
#ifndef IODC_DisableIrq(IrqName)
#define IODC_DisableIrq(IrqName) IODC_DisableIrq_ ## IrqName
#endif  /*IODC_DisableIrq(IrqName)*/


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
#ifndef IODC_ClearStatusIrq(IrqName)
#define IODC_ClearStatusIrq(IrqName) IODC_ClearStatusIrq_ ## IrqName
#endif /* IODC_ClearStatusIrq(IrqName) */

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
#ifndef IODC_ReadStatusIrq(IrqName)
#define IODC_ReadStatusIrq(IrqName) IODC_ReadStatusIrq_ ## IrqName
#endif /* IODC_ReadStatusIrq(IrqName) */

#endif /*__RH850__*/

#endif /*IODC_RH850_H*/

/*_____END _____ (iodc_rh850.h) _______________________________________________*/

