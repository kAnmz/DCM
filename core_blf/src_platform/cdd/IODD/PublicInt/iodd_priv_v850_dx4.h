/******************************************************************************/
/*@F_NAME:           iodd_priv_v850_dx4.h                                     */
/*@F_PURPOSE:        PRIVATE HEADER FOR LOGIC PORT I/O DRIVER                 */
/*@F_CREATED_BY:     Shi Zhenyang                                             */
/*@F_CREATION_DATE:  11/25/2010                                               */
/*@F_MPROC_TYPE:     NEC V850 DX4 and Dx4-H                                   */
/************************************** (C) Copyright 2011 Magneti Marelli ****/

/*______ I N C L U D E - F I L E S ___________________________________________*/


/*______ P R I V A T E - D E F I N E S _______________________________________*/

/* __REL_V850_DJ4__    OK */
/* __REL_V850_DK4H__   -  */
/* __REL_V850_DN4H__   OK */
/* __REL_V850_DP4H__   OK */

/* Not applicable for below 32-bit registers                */
/* {PMCSRn/JPMCSR0; PMSRn/JPMSR0; PSRn/JPSR0}               */
/* {PUCCn/JPUCC0; PDSCn/JPDSC0; PODCn/JPODC0; PSBCn/JPSBC0} */

/* Port group 0 */
#define PORT_BIT_P0_0  BIT0
#define PORT_BIT_P0_1  BIT1
#define PORT_BIT_P0_2  BIT2
#define PORT_BIT_P0_3  BIT3
#define PORT_BIT_P0_4  BIT4
#define PORT_BIT_P0_5  BIT5
#define PORT_BIT_P0_6  BIT6
#define PORT_BIT_P0_7  BIT7
#define PORT_BIT_P0_8  BIT8
#define PORT_BIT_P0_9  BIT9
#define PORT_BIT_P0_10 BIT10
#define PORT_BIT_P0_11 BIT11
#define PORT_BIT_P0_12 BIT12
#define PORT_BIT_P0_13 BIT13
#define PORT_BIT_P0_14 BIT14
#define PORT_BIT_P0_15 BIT15

#define PORT_MSK_P0_0  ((ushort)0x0001U)
#define PORT_MSK_P0_1  ((ushort)0x0002U)
#define PORT_MSK_P0_2  ((ushort)0x0004U)
#define PORT_MSK_P0_3  ((ushort)0x0008U)
#define PORT_MSK_P0_4  ((ushort)0x0010U)
#define PORT_MSK_P0_5  ((ushort)0x0020U)
#define PORT_MSK_P0_6  ((ushort)0x0040U)
#define PORT_MSK_P0_7  ((ushort)0x0080U)
#define PORT_MSK_P0_8  ((ushort)0x0100U)
#define PORT_MSK_P0_9  ((ushort)0x0200U)
#define PORT_MSK_P0_10 ((ushort)0x0400U)
#define PORT_MSK_P0_11 ((ushort)0x0800U)
#define PORT_MSK_P0_12 ((ushort)0x1000U)
#define PORT_MSK_P0_13 ((ushort)0x2000U)
#define PORT_MSK_P0_14 ((ushort)0x4000U)
#define PORT_MSK_P0_15 ((ushort)0x8000U)

/* Port group 1 */
#ifdef __REL_V850_DK4H__
#define PORT_BIT_P1_0  BIT0
#define PORT_BIT_P1_1  BIT1
#define PORT_BIT_P1_2  BIT2
#define PORT_BIT_P1_3  BIT3
#define PORT_BIT_P1_4  BIT4
#define PORT_BIT_P1_5  BIT5
#define PORT_BIT_P1_6  BIT6
#define PORT_BIT_P1_7  BIT7
#define PORT_BIT_P1_8  BIT8
#define PORT_BIT_P1_9  /* n.a. */
#define PORT_BIT_P1_10 /* n.a. */
#define PORT_BIT_P1_11 /* n.a. */
#define PORT_BIT_P1_12 /* n.a. */
#define PORT_BIT_P1_13 /* n.a. */
#define PORT_BIT_P1_14 /* n.a. */
#define PORT_BIT_P1_15 /* n.a. */
#else
#define PORT_BIT_P1_0  /* n.a. */
#define PORT_BIT_P1_1  BIT1
#define PORT_BIT_P1_2  BIT2
#define PORT_BIT_P1_3  BIT3
#define PORT_BIT_P1_4  BIT4
#define PORT_BIT_P1_5  BIT5
#define PORT_BIT_P1_6  BIT6
#define PORT_BIT_P1_7  BIT7
#define PORT_BIT_P1_8  BIT8
#define PORT_BIT_P1_9  BIT9
#define PORT_BIT_P1_10 BIT10
#define PORT_BIT_P1_11 BIT11
#define PORT_BIT_P1_12 BIT12
#define PORT_BIT_P1_13 BIT13
#define PORT_BIT_P1_14 BIT14
#define PORT_BIT_P1_15 BIT15
#endif /* __REL_V850_DK4H__ */

#ifdef __REL_V850_DK4H__
#define PORT_MSK_P1_0  ((ushort)0x0001U)
#define PORT_MSK_P1_1  ((ushort)0x0002U)
#define PORT_MSK_P1_2  ((ushort)0x0004U)
#define PORT_MSK_P1_3  ((ushort)0x0008U)
#define PORT_MSK_P1_4  ((ushort)0x0010U)
#define PORT_MSK_P1_5  ((ushort)0x0020U)
#define PORT_MSK_P1_6  ((ushort)0x0040U)
#define PORT_MSK_P1_7  ((ushort)0x0080U)
#define PORT_MSK_P1_8  ((ushort)0x0100U)
#define PORT_MSK_P1_9  /* n.a. */
#define PORT_MSK_P1_10 /* n.a. */
#define PORT_MSK_P1_11 /* n.a. */
#define PORT_MSK_P1_12 /* n.a. */
#define PORT_MSK_P1_13 /* n.a. */
#define PORT_MSK_P1_14 /* n.a. */
#define PORT_MSK_P1_15 /* n.a. */
#else
#define PORT_MSK_P1_0  /* n.a. */
#define PORT_MSK_P1_1  ((ushort)0x0002U)
#define PORT_MSK_P1_2  ((ushort)0x0004U)
#define PORT_MSK_P1_3  ((ushort)0x0008U)
#define PORT_MSK_P1_4  ((ushort)0x0010U)
#define PORT_MSK_P1_5  ((ushort)0x0020U)
#define PORT_MSK_P1_6  ((ushort)0x0040U)
#define PORT_MSK_P1_7  ((ushort)0x0080U)
#define PORT_MSK_P1_8  ((ushort)0x0100U)
#define PORT_MSK_P1_9  ((ushort)0x0200U)
#define PORT_MSK_P1_10 ((ushort)0x0400U)
#define PORT_MSK_P1_11 ((ushort)0x0800U)
#define PORT_MSK_P1_12 ((ushort)0x1000U)
#define PORT_MSK_P1_13 ((ushort)0x2000U)
#define PORT_MSK_P1_14 ((ushort)0x4000U)
#define PORT_MSK_P1_15 ((ushort)0x8000U)
#endif /* __REL_V850_DK4H__ */

#ifndef __REL_V850_DK4H__
/* Port group 2 */
#define PORT_BIT_P2_0  BIT0
#define PORT_BIT_P2_1  BIT1
#define PORT_BIT_P2_2  BIT2
#define PORT_BIT_P2_3  /* n.a. */
#define PORT_BIT_P2_4  /* n.a. */
#define PORT_BIT_P2_5  /* n.a. */
#define PORT_BIT_P2_6  /* n.a. */
#define PORT_BIT_P2_7  /* n.a. */
#define PORT_BIT_P2_8  /* n.a. */
#define PORT_BIT_P2_9  /* n.a. */
#define PORT_BIT_P2_10 /* n.a. */
#define PORT_BIT_P2_11 /* n.a. */
#define PORT_BIT_P2_12 /* n.a. */
#define PORT_BIT_P2_13 /* n.a. */
#define PORT_BIT_P2_14 /* n.a. */
#define PORT_BIT_P2_15 /* n.a. */

#define PORT_MSK_P2_0  ((ushort)0x0001U)
#define PORT_MSK_P2_1  ((ushort)0x0002U)
#define PORT_MSK_P2_2  ((ushort)0x0004U)
#define PORT_MSK_P2_3  /* n.a. */
#define PORT_MSK_P2_4  /* n.a. */
#define PORT_MSK_P2_5  /* n.a. */
#define PORT_MSK_P2_6  /* n.a. */
#define PORT_MSK_P2_7  /* n.a. */
#define PORT_MSK_P2_8  /* n.a. */
#define PORT_MSK_P2_9  /* n.a. */
#define PORT_MSK_P2_10 /* n.a. */
#define PORT_MSK_P2_11 /* n.a. */
#define PORT_MSK_P2_12 /* n.a. */
#define PORT_MSK_P2_13 /* n.a. */
#define PORT_MSK_P2_14 /* n.a. */
#define PORT_MSK_P2_15 /* n.a. */

/* Port group 3 */
#define PORT_BIT_P3_0  BIT0
#define PORT_BIT_P3_1  BIT1
#define PORT_BIT_P3_2  BIT2
#define PORT_BIT_P3_3  BIT3
#define PORT_BIT_P3_4  BIT4
#define PORT_BIT_P3_5  BIT5
#define PORT_BIT_P3_6  BIT6
#define PORT_BIT_P3_7  BIT7
#define PORT_BIT_P3_8  BIT8
#define PORT_BIT_P3_9  BIT9
#define PORT_BIT_P3_10 BIT10
#define PORT_BIT_P3_11 BIT11
#define PORT_BIT_P3_12 BIT12
#define PORT_BIT_P3_13 /* n.a. */
#define PORT_BIT_P3_14 /* n.a. */
#define PORT_BIT_P3_15 /* n.a. */

#define PORT_MSK_P3_0  ((ushort)0x0001U)
#define PORT_MSK_P3_1  ((ushort)0x0002U)
#define PORT_MSK_P3_2  ((ushort)0x0004U)
#define PORT_MSK_P3_3  ((ushort)0x0008U)
#define PORT_MSK_P3_4  ((ushort)0x0010U)
#define PORT_MSK_P3_5  ((ushort)0x0020U)
#define PORT_MSK_P3_6  ((ushort)0x0040U)
#define PORT_MSK_P3_7  ((ushort)0x0080U)
#define PORT_MSK_P3_8  ((ushort)0x0100U)
#define PORT_MSK_P3_9  ((ushort)0x0200U)
#define PORT_MSK_P3_10 ((ushort)0x0400U)
#define PORT_MSK_P3_11 ((ushort)0x0800U)
#define PORT_MSK_P3_12 ((ushort)0x1000U)
#define PORT_MSK_P3_13 /* n.a. */
#define PORT_MSK_P3_14 /* n.a. */
#define PORT_MSK_P3_15 /* n.a. */
#endif /* !__REL_V850_DK4H__ */

/* Port group 4 */
#define PORT_BIT_P4_0  BIT0
#define PORT_BIT_P4_1  BIT1
#define PORT_BIT_P4_2  BIT2
#define PORT_BIT_P4_3  BIT3
#define PORT_BIT_P4_4  BIT4
#define PORT_BIT_P4_5  BIT5
#define PORT_BIT_P4_6  BIT6
#define PORT_BIT_P4_7  BIT7
#define PORT_BIT_P4_8  BIT8
#define PORT_BIT_P4_9  BIT9
#ifdef __REL_V850_DK4H__
#define PORT_BIT_P4_10 /* n.a. */
#define PORT_BIT_P4_11 /* n.a. */
#else
#define PORT_BIT_P4_10 BIT10
#define PORT_BIT_P4_11 BIT11
#endif /* __REL_V850_DK4H__ */
#define PORT_BIT_P4_12 /* n.a. */
#define PORT_BIT_P4_13 /* n.a. */
#define PORT_BIT_P4_14 /* n.a. */
#define PORT_BIT_P4_15 /* n.a. */

#define PORT_MSK_P4_0  ((ushort)0x0001U)
#define PORT_MSK_P4_1  ((ushort)0x0002U)
#define PORT_MSK_P4_2  ((ushort)0x0004U)
#define PORT_MSK_P4_3  ((ushort)0x0008U)
#define PORT_MSK_P4_4  ((ushort)0x0010U)
#define PORT_MSK_P4_5  ((ushort)0x0020U)
#define PORT_MSK_P4_6  ((ushort)0x0040U)
#define PORT_MSK_P4_7  ((ushort)0x0080U)
#define PORT_MSK_P4_8  ((ushort)0x0100U)
#define PORT_MSK_P4_9  ((ushort)0x0200U)
#ifdef __REL_V850_DK4H__
#define PORT_MSK_P4_10 /* n.a. */
#define PORT_MSK_P4_11 /* n.a. */
#else
#define PORT_MSK_P4_10 ((ushort)0x0400U)
#define PORT_MSK_P4_11 ((ushort)0x0800U)
#endif /* __REL_V850_DK4H__ */
#define PORT_MSK_P4_12 /* n.a. */
#define PORT_MSK_P4_13 /* n.a. */
#define PORT_MSK_P4_14 /* n.a. */
#define PORT_MSK_P4_15 /* n.a. */

/* Port group 10 */
#define PORT_BIT_P10_0  BIT0
#define PORT_BIT_P10_1  BIT1
#define PORT_BIT_P10_2  BIT2
#define PORT_BIT_P10_3  BIT3
#define PORT_BIT_P10_4  BIT4
#define PORT_BIT_P10_5  BIT5
#define PORT_BIT_P10_6  BIT6
#define PORT_BIT_P10_7  BIT7
#define PORT_BIT_P10_8  BIT8
#define PORT_BIT_P10_9  BIT9
#define PORT_BIT_P10_10 BIT10
#define PORT_BIT_P10_11 BIT11
#ifdef __REL_V850_DK4H__
#define PORT_BIT_P10_12 /* n.a. */
#define PORT_BIT_P10_13 /* n.a. */
#define PORT_BIT_P10_14 /* n.a. */
#define PORT_BIT_P10_15 /* n.a. */
#else
#define PORT_BIT_P10_12 BIT12
#define PORT_BIT_P10_13 BIT13
#define PORT_BIT_P10_14 BIT14
#define PORT_BIT_P10_15 BIT15
#endif /* __REL_V850_DK4H__ */

#define PORT_MSK_P10_0  ((ushort)0x0001U)
#define PORT_MSK_P10_1  ((ushort)0x0002U)
#define PORT_MSK_P10_2  ((ushort)0x0004U)
#define PORT_MSK_P10_3  ((ushort)0x0008U)
#define PORT_MSK_P10_4  ((ushort)0x0010U)
#define PORT_MSK_P10_5  ((ushort)0x0020U)
#define PORT_MSK_P10_6  ((ushort)0x0040U)
#define PORT_MSK_P10_7  ((ushort)0x0080U)
#define PORT_MSK_P10_8  ((ushort)0x0100U)
#define PORT_MSK_P10_9  ((ushort)0x0200U)
#define PORT_MSK_P10_10 ((ushort)0x0400U)
#define PORT_MSK_P10_11 ((ushort)0x0800U)
#ifdef __REL_V850_DK4H__
#define PORT_MSK_P10_12 /* n.a. */
#define PORT_MSK_P10_13 /* n.a. */
#define PORT_MSK_P10_14 /* n.a. */
#define PORT_MSK_P10_15 /* n.a. */
#else
#define PORT_MSK_P10_12 ((ushort)0x1000U)
#define PORT_MSK_P10_13 ((ushort)0x2000U)
#define PORT_MSK_P10_14 ((ushort)0x4000U)
#define PORT_MSK_P10_15 ((ushort)0x8000U)
#endif /* __REL_V850_DK4H__ */

/* Port group 16 */
#define PORT_BIT_P16_0  BIT0
#define PORT_BIT_P16_1  BIT1
#define PORT_BIT_P16_2  BIT2
#define PORT_BIT_P16_3  BIT3
#define PORT_BIT_P16_4  BIT4
#define PORT_BIT_P16_5  BIT5
#define PORT_BIT_P16_6  BIT6
#define PORT_BIT_P16_7  BIT7
#define PORT_BIT_P16_8  BIT8
#define PORT_BIT_P16_9  BIT9
#define PORT_BIT_P16_10 BIT10
#define PORT_BIT_P16_11 BIT11
#define PORT_BIT_P16_12 /* n.a. */
#define PORT_BIT_P16_13 /* n.a. */
#define PORT_BIT_P16_14 /* n.a. */
#define PORT_BIT_P16_15 /* n.a. */

#define PORT_MSK_P16_0  ((ushort)0x0001U)
#define PORT_MSK_P16_1  ((ushort)0x0002U)
#define PORT_MSK_P16_2  ((ushort)0x0004U)
#define PORT_MSK_P16_3  ((ushort)0x0008U)
#define PORT_MSK_P16_4  ((ushort)0x0010U)
#define PORT_MSK_P16_5  ((ushort)0x0020U)
#define PORT_MSK_P16_6  ((ushort)0x0040U)
#define PORT_MSK_P16_7  ((ushort)0x0080U)
#define PORT_MSK_P16_8  ((ushort)0x0100U)
#define PORT_MSK_P16_9  ((ushort)0x0200U)
#define PORT_MSK_P16_10 ((ushort)0x0400U)
#define PORT_MSK_P16_11 ((ushort)0x0800U)
#define PORT_MSK_P16_12 /* n.a. */
#define PORT_MSK_P16_13 /* n.a. */
#define PORT_MSK_P16_14 /* n.a. */
#define PORT_MSK_P16_15 /* n.a. */

/* Port group 17 */
#define PORT_BIT_P17_0  BIT0
#define PORT_BIT_P17_1  BIT1
#define PORT_BIT_P17_2  BIT2
#define PORT_BIT_P17_3  BIT3
#define PORT_BIT_P17_4  BIT4
#define PORT_BIT_P17_5  BIT5
#define PORT_BIT_P17_6  BIT6
#define PORT_BIT_P17_7  BIT7
#define PORT_BIT_P17_8  BIT8
#define PORT_BIT_P17_9  BIT9
#define PORT_BIT_P17_10 BIT10
#define PORT_BIT_P17_11 BIT11
#define PORT_BIT_P17_12 /* n.a. */
#define PORT_BIT_P17_13 /* n.a. */
#define PORT_BIT_P17_14 /* n.a. */
#define PORT_BIT_P17_15 /* n.a. */

#define PORT_MSK_P17_0  ((ushort)0x0001U)
#define PORT_MSK_P17_1  ((ushort)0x0002U)
#define PORT_MSK_P17_2  ((ushort)0x0004U)
#define PORT_MSK_P17_3  ((ushort)0x0008U)
#define PORT_MSK_P17_4  ((ushort)0x0010U)
#define PORT_MSK_P17_5  ((ushort)0x0020U)
#define PORT_MSK_P17_6  ((ushort)0x0040U)
#define PORT_MSK_P17_7  ((ushort)0x0080U)
#define PORT_MSK_P17_8  ((ushort)0x0100U)
#define PORT_MSK_P17_9  ((ushort)0x0200U)
#define PORT_MSK_P17_10 ((ushort)0x0400U)
#define PORT_MSK_P17_11 ((ushort)0x0800U)
#define PORT_MSK_P17_12 /* n.a. */
#define PORT_MSK_P17_13 /* n.a. */
#define PORT_MSK_P17_14 /* n.a. */
#define PORT_MSK_P17_15 /* n.a. */

#ifndef __REL_V850_DJ4__
#ifndef __REL_V850_DK4H__
/* Port group 21 */
#define PORT_BIT_P21_0  /* n.a. */
#define PORT_BIT_P21_1  /* n.a. */
#define PORT_BIT_P21_2  /* n.a. */
#define PORT_BIT_P21_3  /* n.a. */
#define PORT_BIT_P21_4  /* n.a. */
#define PORT_BIT_P21_5  /* n.a. */
#define PORT_BIT_P21_6  BIT6
#define PORT_BIT_P21_7  /* n.a. */
#define PORT_BIT_P21_8  BIT8
#define PORT_BIT_P21_9  /* n.a. */
#define PORT_BIT_P21_10 /* n.a. */
#define PORT_BIT_P21_11 /* n.a. */
#define PORT_BIT_P21_12 /* n.a. */
#define PORT_BIT_P21_13 BIT13
#define PORT_BIT_P21_14 BIT14
#define PORT_BIT_P21_15 BIT15

#define PORT_MSK_P21_0  /* n.a. */
#define PORT_MSK_P21_1  /* n.a. */
#define PORT_MSK_P21_2  /* n.a. */
#define PORT_MSK_P21_3  /* n.a. */
#define PORT_MSK_P21_4  /* n.a. */
#define PORT_MSK_P21_5  /* n.a. */
#define PORT_MSK_P21_6  ((ushort)0x0040U)
#define PORT_MSK_P21_7  /* n.a. */
#define PORT_MSK_P21_8  ((ushort)0x0100U)
#define PORT_MSK_P21_9  /* n.a. */
#define PORT_MSK_P21_10 /* n.a. */
#define PORT_MSK_P21_11 /* n.a. */
#define PORT_MSK_P21_12 /* n.a. */
#define PORT_MSK_P21_13 ((ushort)0x2000U)
#define PORT_MSK_P21_14 ((ushort)0x4000U)
#define PORT_MSK_P21_15 ((ushort)0x8000U)

/* Port group 22 */
#define PORT_BIT_P22_0  BIT0
#define PORT_BIT_P22_1  BIT1
#define PORT_BIT_P22_2  BIT2
#define PORT_BIT_P22_3  BIT3
#define PORT_BIT_P22_4  BIT4
#define PORT_BIT_P22_5  BIT5
#define PORT_BIT_P22_6  BIT6
#define PORT_BIT_P22_7  /* n.a. */
#define PORT_BIT_P22_8  /* n.a. */
#define PORT_BIT_P22_9  /* n.a. */
#define PORT_BIT_P22_10 /* n.a. */
#define PORT_BIT_P22_11 /* n.a. */
#define PORT_BIT_P22_12 /* n.a. */
#define PORT_BIT_P22_13 /* n.a. */
#define PORT_BIT_P22_14 /* n.a. */
#define PORT_BIT_P22_15 /* n.a. */

#define PORT_MSK_P22_0  ((ushort)0x0001U)
#define PORT_MSK_P22_1  ((ushort)0x0002U)
#define PORT_MSK_P22_2  ((ushort)0x0004U)
#define PORT_MSK_P22_3  ((ushort)0x0008U)
#define PORT_MSK_P22_4  ((ushort)0x0010U)
#define PORT_MSK_P22_5  ((ushort)0x0020U)
#define PORT_MSK_P22_6  ((ushort)0x0040U)
#define PORT_MSK_P22_7  /* n.a. */
#define PORT_MSK_P22_8  /* n.a. */
#define PORT_MSK_P22_9  /* n.a. */
#define PORT_MSK_P22_10 /* n.a. */
#define PORT_MSK_P22_11 /* n.a. */
#define PORT_MSK_P22_12 /* n.a. */
#define PORT_MSK_P22_13 /* n.a. */
#define PORT_MSK_P22_14 /* n.a. */
#define PORT_MSK_P22_15 /* n.a. */

/* Port group 23 */
#define PORT_BIT_P23_0  BIT0
#define PORT_BIT_P23_1  BIT1
#define PORT_BIT_P23_2  BIT2
#define PORT_BIT_P23_3  BIT3
#define PORT_BIT_P23_4  BIT4
#define PORT_BIT_P23_5  BIT5
#define PORT_BIT_P23_6  BIT6
#define PORT_BIT_P23_7  BIT7
#define PORT_BIT_P23_8  BIT8
#define PORT_BIT_P23_9  BIT9
#define PORT_BIT_P23_10 BIT10
#define PORT_BIT_P23_11 BIT11
#define PORT_BIT_P23_12 BIT12
#define PORT_BIT_P23_13 BIT13
#define PORT_BIT_P23_14 BIT14
#define PORT_BIT_P23_15 BIT15

#define PORT_MSK_P23_0  ((ushort)0x0001U)
#define PORT_MSK_P23_1  ((ushort)0x0002U)
#define PORT_MSK_P23_2  ((ushort)0x0004U)
#define PORT_MSK_P23_3  ((ushort)0x0008U)
#define PORT_MSK_P23_4  ((ushort)0x0010U)
#define PORT_MSK_P23_5  ((ushort)0x0020U)
#define PORT_MSK_P23_6  ((ushort)0x0040U)
#define PORT_MSK_P23_7  ((ushort)0x0080U)
#define PORT_MSK_P23_8  ((ushort)0x0100U)
#define PORT_MSK_P23_9  ((ushort)0x0200U)
#define PORT_MSK_P23_10 ((ushort)0x0400U)
#define PORT_MSK_P23_11 ((ushort)0x0800U)
#define PORT_MSK_P23_12 ((ushort)0x1000U)
#define PORT_MSK_P23_13 ((ushort)0x2000U)
#define PORT_MSK_P23_14 ((ushort)0x4000U)
#define PORT_MSK_P23_15 ((ushort)0x8000U)

/* Port group 24 */
#define PORT_BIT_P24_0  BIT0
#define PORT_BIT_P24_1  BIT1
#define PORT_BIT_P24_2  BIT2
#define PORT_BIT_P24_3  BIT3
#define PORT_BIT_P24_4  BIT4
#define PORT_BIT_P24_5  BIT5
#define PORT_BIT_P24_6  BIT6
#define PORT_BIT_P24_7  BIT7
#define PORT_BIT_P24_8  BIT8
#define PORT_BIT_P24_9  BIT9
#define PORT_BIT_P24_10 BIT10
#define PORT_BIT_P24_11 BIT11
#define PORT_BIT_P24_12 BIT12
#define PORT_BIT_P24_13 BIT13
#define PORT_BIT_P24_14 BIT14
#define PORT_BIT_P24_15 BIT15

#define PORT_MSK_P24_0  ((ushort)0x0001U)
#define PORT_MSK_P24_1  ((ushort)0x0002U)
#define PORT_MSK_P24_2  ((ushort)0x0004U)
#define PORT_MSK_P24_3  ((ushort)0x0008U)
#define PORT_MSK_P24_4  ((ushort)0x0010U)
#define PORT_MSK_P24_5  ((ushort)0x0020U)
#define PORT_MSK_P24_6  ((ushort)0x0040U)
#define PORT_MSK_P24_7  ((ushort)0x0080U)
#define PORT_MSK_P24_8  ((ushort)0x0100U)
#define PORT_MSK_P24_9  ((ushort)0x0200U)
#define PORT_MSK_P24_10 ((ushort)0x0400U)
#define PORT_MSK_P24_11 ((ushort)0x0800U)
#define PORT_MSK_P24_12 ((ushort)0x1000U)
#define PORT_MSK_P24_13 ((ushort)0x2000U)
#define PORT_MSK_P24_14 ((ushort)0x4000U)
#define PORT_MSK_P24_15 ((ushort)0x8000U)

/* Port group 26 */
#define PORT_BIT_P26_0  BIT0
#define PORT_BIT_P26_1  BIT1
#define PORT_BIT_P26_2  BIT2
#define PORT_BIT_P26_3  BIT3
#define PORT_BIT_P26_4  BIT4
#define PORT_BIT_P26_5  BIT5
#define PORT_BIT_P26_6  BIT6
#define PORT_BIT_P26_7  BIT7
#define PORT_BIT_P26_8  BIT8
#define PORT_BIT_P26_9  BIT9
#define PORT_BIT_P26_10 BIT10
#define PORT_BIT_P26_11 BIT11
#define PORT_BIT_P26_12 BIT12
#define PORT_BIT_P26_13 /* n.a. */
#define PORT_BIT_P26_14 /* n.a. */
#define PORT_BIT_P26_15 /* n.a. */

#define PORT_MSK_P26_0  ((ushort)0x0001U)
#define PORT_MSK_P26_1  ((ushort)0x0002U)
#define PORT_MSK_P26_2  ((ushort)0x0004U)
#define PORT_MSK_P26_3  ((ushort)0x0008U)
#define PORT_MSK_P26_4  ((ushort)0x0010U)
#define PORT_MSK_P26_5  ((ushort)0x0020U)
#define PORT_MSK_P26_6  ((ushort)0x0040U)
#define PORT_MSK_P26_7  ((ushort)0x0080U)
#define PORT_MSK_P26_8  ((ushort)0x0100U)
#define PORT_MSK_P26_9  ((ushort)0x0200U)
#define PORT_MSK_P26_10 ((ushort)0x0400U)
#define PORT_MSK_P26_11 ((ushort)0x0800U)
#define PORT_MSK_P26_12 ((ushort)0x1000U)
#define PORT_MSK_P26_13 /* n.a. */
#define PORT_MSK_P26_14 /* n.a. */
#define PORT_MSK_P26_15 /* n.a. */
#endif /* !__REL_V850_DK4H__ */

/* Port group 27 */
#define PORT_BIT_P27_0  BIT0
#define PORT_BIT_P27_1  BIT1
#define PORT_BIT_P27_2  BIT2
#define PORT_BIT_P27_3  BIT3
#define PORT_BIT_P27_4  BIT4
#define PORT_BIT_P27_5  BIT5
#ifdef __REL_V850_DK4H__
#define PORT_BIT_P27_6  BIT6
#define PORT_BIT_P27_7  BIT7
#define PORT_BIT_P27_8  BIT8
#else
#define PORT_BIT_P27_6  /* n.a. */
#define PORT_BIT_P27_7  /* n.a. */
#define PORT_BIT_P27_8  /* n.a. */
#endif /* __REL_V850_DK4H__ */
#define PORT_BIT_P27_9  /* n.a. */
#define PORT_BIT_P27_10 /* n.a. */
#define PORT_BIT_P27_11 /* n.a. */
#define PORT_BIT_P27_12 /* n.a. */
#define PORT_BIT_P27_13 /* n.a. */
#define PORT_BIT_P27_14 /* n.a. */
#define PORT_BIT_P27_15 /* n.a. */

#define PORT_MSK_P27_0  ((ushort)0x0001U)
#define PORT_MSK_P27_1  ((ushort)0x0002U)
#define PORT_MSK_P27_2  ((ushort)0x0004U)
#define PORT_MSK_P27_3  ((ushort)0x0008U)
#define PORT_MSK_P27_4  ((ushort)0x0010U)
#define PORT_MSK_P27_5  ((ushort)0x0020U)
#ifdef __REL_V850_DK4H__
#define PORT_MSK_P27_6  ((ushort)0x0040U)
#define PORT_MSK_P27_7  ((ushort)0x0080U)
#define PORT_MSK_P27_8  ((ushort)0x0100U)
#else
#define PORT_MSK_P27_6  /* n.a. */
#define PORT_MSK_P27_7  /* n.a. */
#define PORT_MSK_P27_8  /* n.a. */
#endif /* __REL_V850_DK4H__ */
#define PORT_MSK_P27_9  /* n.a. */
#define PORT_MSK_P27_10 /* n.a. */
#define PORT_MSK_P27_11 /* n.a. */
#define PORT_MSK_P27_12 /* n.a. */
#define PORT_MSK_P27_13 /* n.a. */
#define PORT_MSK_P27_14 /* n.a. */
#define PORT_MSK_P27_15 /* n.a. */

/* Port group 28 */
#define PORT_BIT_P28_0  BIT0
#define PORT_BIT_P28_1  BIT1
#define PORT_BIT_P28_2  BIT2
#define PORT_BIT_P28_3  BIT3
#define PORT_BIT_P28_4  BIT4
#define PORT_BIT_P28_5  BIT5
#ifdef __REL_V850_DK4H__
#define PORT_BIT_P28_6  BIT6
#define PORT_BIT_P28_7  BIT7
#define PORT_BIT_P28_8  BIT8
#define PORT_BIT_P28_9  BIT9
#define PORT_BIT_P28_10 BIT10
#define PORT_BIT_P28_11 BIT11
#define PORT_BIT_P28_12 BIT12
#else
#define PORT_BIT_P28_6  /* n.a. */
#define PORT_BIT_P28_7  /* n.a. */
#define PORT_BIT_P28_8  /* n.a. */
#define PORT_BIT_P28_9  /* n.a. */
#define PORT_BIT_P28_10 /* n.a. */
#define PORT_BIT_P28_11 /* n.a. */
#define PORT_BIT_P28_12 /* n.a. */
#endif /* __REL_V850_DK4H__ */
#define PORT_BIT_P28_13 /* n.a. */
#define PORT_BIT_P28_14 /* n.a. */
#define PORT_BIT_P28_15 /* n.a. */

#define PORT_MSK_P28_0  ((ushort)0x0001U)
#define PORT_MSK_P28_1  ((ushort)0x0002U)
#define PORT_MSK_P28_2  ((ushort)0x0004U)
#define PORT_MSK_P28_3  ((ushort)0x0008U)
#define PORT_MSK_P28_4  ((ushort)0x0010U)
#define PORT_MSK_P28_5  ((ushort)0x0020U)
#ifdef __REL_V850_DK4H__
#define PORT_MSK_P28_6  ((ushort)0x0040U)
#define PORT_MSK_P28_7  ((ushort)0x0080U)
#define PORT_MSK_P28_8  ((ushort)0x0100U)
#define PORT_MSK_P28_9  ((ushort)0x0200U)
#define PORT_MSK_P28_10 ((ushort)0x0400U)
#define PORT_MSK_P28_11 ((ushort)0x0800U)
#define PORT_MSK_P28_12 ((ushort)0x1000U)
#else
#define PORT_MSK_P28_6  /* n.a. */
#define PORT_MSK_P28_7  /* n.a. */
#define PORT_MSK_P28_8  /* n.a. */
#define PORT_MSK_P28_9  /* n.a. */
#define PORT_MSK_P28_10 /* n.a. */
#define PORT_MSK_P28_11 /* n.a. */
#define PORT_MSK_P28_12 /* n.a. */
#endif /* __REL_V850_DK4H__ */
#define PORT_MSK_P28_13 /* n.a. */
#define PORT_MSK_P28_14 /* n.a. */
#define PORT_MSK_P28_15 /* n.a. */

#ifndef __REL_V850_DK4H__
/* Port group 29 */
#define PORT_BIT_P29_0  BIT0
#define PORT_BIT_P29_1  BIT1
#define PORT_BIT_P29_2  BIT2
#define PORT_BIT_P29_3  BIT3
#define PORT_BIT_P29_4  BIT4
#define PORT_BIT_P29_5  BIT5
#define PORT_BIT_P29_6  BIT6
#define PORT_BIT_P29_7  BIT7
#define PORT_BIT_P29_8  BIT8
#define PORT_BIT_P29_9  BIT9
#define PORT_BIT_P29_10 BIT10
#define PORT_BIT_P29_11 BIT11
#define PORT_BIT_P29_12 BIT12
#define PORT_BIT_P29_13 BIT13
#define PORT_BIT_P29_14 BIT14
#define PORT_BIT_P29_15 BIT15

#define PORT_MSK_P29_0  ((ushort)0x0001U)
#define PORT_MSK_P29_1  ((ushort)0x0002U)
#define PORT_MSK_P29_2  ((ushort)0x0004U)
#define PORT_MSK_P29_3  ((ushort)0x0008U)
#define PORT_MSK_P29_4  ((ushort)0x0010U)
#define PORT_MSK_P29_5  ((ushort)0x0020U)
#define PORT_MSK_P29_6  ((ushort)0x0040U)
#define PORT_MSK_P29_7  ((ushort)0x0080U)
#define PORT_MSK_P29_8  ((ushort)0x0100U)
#define PORT_MSK_P29_9  ((ushort)0x0200U)
#define PORT_MSK_P29_10 ((ushort)0x0400U)
#define PORT_MSK_P29_11 ((ushort)0x0800U)
#define PORT_MSK_P29_12 ((ushort)0x1000U)
#define PORT_MSK_P29_13 ((ushort)0x2000U)
#define PORT_MSK_P29_14 ((ushort)0x4000U)
#define PORT_MSK_P29_15 ((ushort)0x8000U)

/* Port group 30 */
#define PORT_BIT_P30_0  BIT0
#define PORT_BIT_P30_1  BIT1
#define PORT_BIT_P30_2  BIT2
#define PORT_BIT_P30_3  /* n.a. */
#define PORT_BIT_P30_4  /* n.a. */
#define PORT_BIT_P30_5  /* n.a. */
#define PORT_BIT_P30_6  /* n.a. */
#define PORT_BIT_P30_7  /* n.a. */
#define PORT_BIT_P30_8  /* n.a. */
#define PORT_BIT_P30_9  /* n.a. */
#define PORT_BIT_P30_10 /* n.a. */
#define PORT_BIT_P30_11 /* n.a. */
#define PORT_BIT_P30_12 /* n.a. */
#define PORT_BIT_P30_13 /* n.a. */
#define PORT_BIT_P30_14 /* n.a. */
#define PORT_BIT_P30_15 /* n.a. */

#define PORT_MSK_P30_0  ((ushort)0x0001U)
#define PORT_MSK_P30_1  ((ushort)0x0002U)
#define PORT_MSK_P30_2  ((ushort)0x0004U)
#define PORT_MSK_P30_3  /* n.a. */
#define PORT_MSK_P30_4  /* n.a. */
#define PORT_MSK_P30_5  /* n.a. */
#define PORT_MSK_P30_6  /* n.a. */
#define PORT_MSK_P30_7  /* n.a. */
#define PORT_MSK_P30_8  /* n.a. */
#define PORT_MSK_P30_9  /* n.a. */
#define PORT_MSK_P30_10 /* n.a. */
#define PORT_MSK_P30_11 /* n.a. */
#define PORT_MSK_P30_12 /* n.a. */
#define PORT_MSK_P30_13 /* n.a. */
#define PORT_MSK_P30_14 /* n.a. */
#define PORT_MSK_P30_15 /* n.a. */
#endif /* !__REL_V850_DK4H__ */

/* Port group 40 */
#define PORT_BIT_P40_0  BIT0
#define PORT_BIT_P40_1  BIT1
#define PORT_BIT_P40_2  BIT2
#define PORT_BIT_P40_3  BIT3
#define PORT_BIT_P40_4  BIT4
#define PORT_BIT_P40_5  BIT5
#define PORT_BIT_P40_6  BIT6
#define PORT_BIT_P40_7  BIT7
#define PORT_BIT_P40_8  BIT8
#define PORT_BIT_P40_9  BIT9
#define PORT_BIT_P40_10 BIT10
#define PORT_BIT_P40_11 BIT11
#define PORT_BIT_P40_12 BIT12
#define PORT_BIT_P40_13 BIT13
#define PORT_BIT_P40_14 BIT14
#define PORT_BIT_P40_15 BIT15

#define PORT_MSK_P40_0  ((ushort)0x0001U)
#define PORT_MSK_P40_1  ((ushort)0x0002U)
#define PORT_MSK_P40_2  ((ushort)0x0004U)
#define PORT_MSK_P40_3  ((ushort)0x0008U)
#define PORT_MSK_P40_4  ((ushort)0x0010U)
#define PORT_MSK_P40_5  ((ushort)0x0020U)
#define PORT_MSK_P40_6  ((ushort)0x0040U)
#define PORT_MSK_P40_7  ((ushort)0x0080U)
#define PORT_MSK_P40_8  ((ushort)0x0100U)
#define PORT_MSK_P40_9  ((ushort)0x0200U)
#define PORT_MSK_P40_10 ((ushort)0x0400U)
#define PORT_MSK_P40_11 ((ushort)0x0800U)
#define PORT_MSK_P40_12 ((ushort)0x1000U)
#define PORT_MSK_P40_13 ((ushort)0x2000U)
#define PORT_MSK_P40_14 ((ushort)0x4000U)
#define PORT_MSK_P40_15 ((ushort)0x8000U)

/* Port group 41 */
#define PORT_BIT_P41_0  BIT0
#define PORT_BIT_P41_1  BIT1
#define PORT_BIT_P41_2  BIT2
#define PORT_BIT_P41_3  BIT3
#define PORT_BIT_P41_4  BIT4
#define PORT_BIT_P41_5  BIT5
#define PORT_BIT_P41_6  BIT6
#define PORT_BIT_P41_7  BIT7
#define PORT_BIT_P41_8  BIT8
#define PORT_BIT_P41_9  BIT9
#define PORT_BIT_P41_10 BIT10
#define PORT_BIT_P41_11 BIT11
#ifdef __REL_V850_DK4H__
#define PORT_BIT_P41_12 /* n.a. */
#else
#define PORT_BIT_P41_12 BIT12
#endif /* __REL_V850_DK4H__ */
#define PORT_BIT_P41_13 /* n.a. */
#define PORT_BIT_P41_14 /* n.a. */
#define PORT_BIT_P41_15 /* n.a. */

#define PORT_MSK_P41_0  ((ushort)0x0001U)
#define PORT_MSK_P41_1  ((ushort)0x0002U)
#define PORT_MSK_P41_2  ((ushort)0x0004U)
#define PORT_MSK_P41_3  ((ushort)0x0008U)
#define PORT_MSK_P41_4  ((ushort)0x0010U)
#define PORT_MSK_P41_5  ((ushort)0x0020U)
#define PORT_MSK_P41_6  ((ushort)0x0040U)
#define PORT_MSK_P41_7  ((ushort)0x0080U)
#define PORT_MSK_P41_8  ((ushort)0x0100U)
#define PORT_MSK_P41_9  ((ushort)0x0200U)
#define PORT_MSK_P41_10 ((ushort)0x0400U)
#define PORT_MSK_P41_11 ((ushort)0x0800U)
#ifdef __REL_V850_DK4H__
#define PORT_MSK_P41_12 /* n.a. */
#else
#define PORT_MSK_P41_12 ((ushort)0x1000U)
#endif /* __REL_V850_DK4H__ */
#define PORT_MSK_P41_13 /* n.a. */
#define PORT_MSK_P41_14 /* n.a. */
#define PORT_MSK_P41_15 /* n.a. */
#endif /* !__REL_V850_DJ4__ */

/* Port group JP0 ('J' is 74d in ASCII) */
#define PORT_BIT_P74_0  BIT0
#define PORT_BIT_P74_1  BIT1
#define PORT_BIT_P74_2  BIT2
#define PORT_BIT_P74_3  BIT3
#define PORT_BIT_P74_4  BIT4
#define PORT_BIT_P74_5  BIT5
#define PORT_BIT_P74_6  /* n.a. */
#define PORT_BIT_P74_7  /* n.a. */
#define PORT_BIT_P74_8  /* n.a. */
#define PORT_BIT_P74_9  /* n.a. */
#define PORT_BIT_P74_10 /* n.a. */
#define PORT_BIT_P74_11 /* n.a. */
#define PORT_BIT_P74_12 /* n.a. */
#define PORT_BIT_P74_13 /* n.a. */
#define PORT_BIT_P74_14 /* n.a. */
#define PORT_BIT_P74_15 /* n.a. */

#define PORT_MSK_P74_0  ((ushort)0x0001U)
#define PORT_MSK_P74_1  ((ushort)0x0002U)
#define PORT_MSK_P74_2  ((ushort)0x0004U)
#define PORT_MSK_P74_3  ((ushort)0x0008U)
#define PORT_MSK_P74_4  ((ushort)0x0010U)
#define PORT_MSK_P74_5  ((ushort)0x0020U)
#define PORT_MSK_P74_6  /* n.a. */
#define PORT_MSK_P74_7  /* n.a. */
#define PORT_MSK_P74_8  /* n.a. */
#define PORT_MSK_P74_9  /* n.a. */
#define PORT_MSK_P74_10 /* n.a. */
#define PORT_MSK_P74_11 /* n.a. */
#define PORT_MSK_P74_12 /* n.a. */
#define PORT_MSK_P74_13 /* n.a. */
#define PORT_MSK_P74_14 /* n.a. */
#define PORT_MSK_P74_15 /* n.a. */


/*______ E N D _____ (iodd_priv_v850_dx4.h) __________________________________*/
