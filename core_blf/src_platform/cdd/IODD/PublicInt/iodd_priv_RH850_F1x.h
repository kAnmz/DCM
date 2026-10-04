/******************************************************************************/
/*@F_NAME:           iodd_priv_rh850_f1x.h                                    */
/*@F_PURPOSE:        PRIVATE HEADER FOR LOGIC PORT I/O DRIVER                 */
/*@F_CREATED_BY:     shubin liang                                             */
/*@F_CREATION_DATE:  03/11/2017                                               */
/*@F_MPROC_TYPE:     RH850 F1x                                                */
/************************************** (C) Copyright 2011 Magneti Marelli ****/
#ifndef IODD_PRIV_RH850_F1X_H
#define IODD_PRIV_RH850_F1X_H
/*______ I N C L U D E - F I L E S ___________________________________________*/

#include "syst.h"

#if defined(__RH850_F1x__)
/*______ P R I V A T E - D E F I N E S _______________________________________*/

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



/* Port group 1 */
#define PORT_BIT_P1_0  BIT0
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
#define PORT_BIT_P1_12  BIT12
#define PORT_BIT_P1_13  BIT13
#define PORT_BIT_P1_14  BIT14
#define PORT_BIT_P1_15  BIT15

#define PORT_MSK_P1_0  ((ushort)0x0001U)
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





/* Port group 2 */
#define PORT_BIT_P2_0  BIT0
#define PORT_BIT_P2_1  BIT1
#define PORT_BIT_P2_2  BIT2
#define PORT_BIT_P2_3  BIT3
#define PORT_BIT_P2_4  BIT4
#define PORT_BIT_P2_5  BIT5
#define PORT_BIT_P2_6  BIT6


#define PORT_MSK_P2_0  ((ushort)0x0001U)
#define PORT_MSK_P2_1  ((ushort)0x0002U)
#define PORT_MSK_P2_2  ((ushort)0x0004U)
#define PORT_MSK_P2_3  ((ushort)0x0008U)
#define PORT_MSK_P2_4  ((ushort)0x0010U)
#define PORT_MSK_P2_5  ((ushort)0x0020U)
#define PORT_MSK_P2_6  ((ushort)0x0040U)



/* Port group 8 */
#define PORT_BIT_P8_0  BIT0
#define PORT_BIT_P8_1  BIT1
#define PORT_BIT_P8_2  BIT2
#define PORT_BIT_P8_3  BIT3
#define PORT_BIT_P8_4  BIT4
#define PORT_BIT_P8_5  BIT5
#define PORT_BIT_P8_6  BIT6
#define PORT_BIT_P8_7  BIT7
#define PORT_BIT_P8_8  BIT8
#define PORT_BIT_P8_9  BIT9
#define PORT_BIT_P8_10 BIT10
#define PORT_BIT_P8_11 BIT11
#define PORT_BIT_P8_12 BIT12

#define PORT_MSK_P8_0  ((ushort)0x0001U)
#define PORT_MSK_P8_1  ((ushort)0x0002U)
#define PORT_MSK_P8_2  ((ushort)0x0004U)
#define PORT_MSK_P8_3  ((ushort)0x0008U)
#define PORT_MSK_P8_4  ((ushort)0x0010U)
#define PORT_MSK_P8_5  ((ushort)0x0020U)
#define PORT_MSK_P8_6  ((ushort)0x0040U)
#define PORT_MSK_P8_7  ((ushort)0x0080U)
#define PORT_MSK_P8_8  ((ushort)0x0100U)
#define PORT_MSK_P8_9  ((ushort)0x0200U)
#define PORT_MSK_P8_10 ((ushort)0x0400U)
#define PORT_MSK_P8_11 ((ushort)0x0800U)
#define PORT_MSK_P8_12 ((ushort)0x1000U)


/* Port group 9 */
#define PORT_BIT_P9_0  BIT0
#define PORT_BIT_P9_1  BIT1
#define PORT_BIT_P9_2  BIT2
#define PORT_BIT_P9_3  BIT3
#define PORT_BIT_P9_4  BIT4
#define PORT_BIT_P9_5  BIT5
#define PORT_BIT_P9_6  BIT6


#define PORT_MSK_P9_0  ((ushort)0x0001U)
#define PORT_MSK_P9_1  ((ushort)0x0002U)
#define PORT_MSK_P9_2  ((ushort)0x0004U)
#define PORT_MSK_P9_3  ((ushort)0x0008U)
#define PORT_MSK_P9_4  ((ushort)0x0010U)
#define PORT_MSK_P9_5  ((ushort)0x0020U)
#define PORT_MSK_P9_6  ((ushort)0x0040U)


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
#define PORT_BIT_P10_12 BIT12
#define PORT_BIT_P10_13 BIT13
#define PORT_BIT_P10_14 BIT14
#define PORT_BIT_P10_15 BIT15

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
#define PORT_MSK_P10_12 ((ushort)0x1000U)
#define PORT_MSK_P10_13 ((ushort)0x2000U)
#define PORT_MSK_P10_14 ((ushort)0x4000U)
#define PORT_MSK_P10_15 ((ushort)0x8000U)

/*Port group 11*/
#define PORT_BIT_P11_0  BIT0
#define PORT_BIT_P11_1  BIT1
#define PORT_BIT_P11_2  BIT2
#define PORT_BIT_P11_3  BIT3
#define PORT_BIT_P11_4  BIT4
#define PORT_BIT_P11_5  BIT5
#define PORT_BIT_P11_6  BIT6
#define PORT_BIT_P11_7  BIT7
#define PORT_BIT_P11_8  BIT8
#define PORT_BIT_P11_9  BIT9
#define PORT_BIT_P11_10 BIT10
#define PORT_BIT_P11_11 BIT11
#define PORT_BIT_P11_12 BIT12
#define PORT_BIT_P11_13 BIT13
#define PORT_BIT_P11_14 BIT14
#define PORT_BIT_P11_15 BIT15

#define PORT_MSK_P11_0  ((ushort)0x0001U)
#define PORT_MSK_P11_1  ((ushort)0x0002U)
#define PORT_MSK_P11_2  ((ushort)0x0004U)
#define PORT_MSK_P11_3  ((ushort)0x0008U)
#define PORT_MSK_P11_4  ((ushort)0x0010U)
#define PORT_MSK_P11_5  ((ushort)0x0020U)
#define PORT_MSK_P11_6  ((ushort)0x0040U)
#define PORT_MSK_P11_7  ((ushort)0x0080U)
#define PORT_MSK_P11_8  ((ushort)0x0100U)
#define PORT_MSK_P11_9  ((ushort)0x0200U)
#define PORT_MSK_P11_10 ((ushort)0x0400U)
#define PORT_MSK_P11_11 ((ushort)0x0800U)
#define PORT_MSK_P11_12 ((ushort)0x1000U)
#define PORT_MSK_P11_13 ((ushort)0x2000U)
#define PORT_MSK_P11_14 ((ushort)0x4000U)
#define PORT_MSK_P11_15 ((ushort)0x8000U)



/*Port group 12*/

#define PORT_BIT_P12_0  BIT0
#define PORT_BIT_P12_1  BIT1
#define PORT_BIT_P12_2  BIT2
#define PORT_BIT_P12_3  BIT3
#define PORT_BIT_P12_4  BIT4
#define PORT_BIT_P12_5  BIT5

#define PORT_MSK_P12_0  ((ushort)0x0001U)
#define PORT_MSK_P12_1  ((ushort)0x0002U)
#define PORT_MSK_P12_2  ((ushort)0x0004U)
#define PORT_MSK_P12_3 ((ushort)0x0008U)
#define PORT_MSK_P12_4 ((ushort)0x0010U)
#define PORT_MSK_P12_5 ((ushort)0x0020U)


/* Port group 18 */

#define PORT_BIT_P18_0  BIT0
#define PORT_BIT_P18_1  BIT1
#define PORT_BIT_P18_2  BIT2
#define PORT_BIT_P18_3  BIT3
#define PORT_BIT_P18_4  BIT4
#define PORT_BIT_P18_5  BIT5
#define PORT_BIT_P18_6  BIT6
#define PORT_BIT_P18_7  BIT7

#define PORT_MSK_P18_0  ((ushort)0x0001U)
#define PORT_MSK_P18_1  ((ushort)0x0002U)
#define PORT_MSK_P18_2  ((ushort)0x0004U)
#define PORT_MSK_P18_3  ((ushort)0x0008U)
#define PORT_MSK_P18_4  ((ushort)0x0010U)
#define PORT_MSK_P18_5  ((ushort)0x0020U)
#define PORT_MSK_P18_6  ((ushort)0x0040U)
#define PORT_MSK_P18_7  ((ushort)0x0080U)



/* Port group 20 */

#define PORT_BIT_P20_0  BIT0
#define PORT_BIT_P20_1  BIT1
#define PORT_BIT_P20_2  BIT2
#define PORT_BIT_P20_3  BIT3
#define PORT_BIT_P20_4  BIT4
#define PORT_BIT_P20_5  BIT5


#define PORT_MSK_P20_0  ((ushort)0x0001U)
#define PORT_MSK_P20_1  ((ushort)0x0002U)
#define PORT_MSK_P20_2  ((ushort)0x0004U)
#define PORT_MSK_P20_3  ((ushort)0x0008U)
#define PORT_MSK_P20_4  ((ushort)0x0010U)
#define PORT_MSK_P20_5  ((ushort)0x0020U)

#endif /* __RH850_F1x__ */
#endif
/*______ E N D _____ (iodd_priv_v850_dx4.h) __________________________________*/
