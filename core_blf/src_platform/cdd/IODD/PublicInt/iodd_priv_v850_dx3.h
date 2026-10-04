/******************************************************************************/
/*@F_NAME:           iodd_priv_v850_dx3.h                                     */
/*@F_PURPOSE:        PRIVATE HEADER FOR LOGIC PORT I/O DRIVER                 */
/*@F_CREATED_BY:     C. LE LABOUSSE                                           */
/*@F_CREATION_DATE:  01/12/2006                                               */
/*@F_MPROC_TYPE:     NEC V850 DX3                                             */
/************************************** (C) Copyright 2008 Magneti Marelli ****/

/*______ I N C L U D E - F I L E S ___________________________________________*/  


/*______ P R I V A T E - D E F I N E S _______________________________________*/

/* Definitions PORT 0 */

#if                                          \
      defined(__NEC_V850_DJ3__)||            \
      defined(__NEC_V850_DL3__)

#define Iodd_RREG_P_00                       TARG_ReadBit(P0, BIT0)
#define Iodd_RREG_P_01                       TARG_ReadBit(P0, BIT1)
#define Iodd_RREG_P_02                       TARG_ReadBit(P0, BIT2)
#define Iodd_RREG_P_03                       TARG_ReadBit(P0, BIT3)
#define Iodd_RREG_P_04                       TARG_ReadBit(P0, BIT4)
#define Iodd_RREG_P_05                       TARG_ReadBit(P0, BIT5)
#define Iodd_RREG_P_06                       TARG_ReadBit(P0, BIT6)
#define Iodd_RREG_P_07                       TARG_ReadBit(P0, BIT7)

#define Iodd_WREG_P_00(Value)                TARG_WriteBit(P0, BIT0, Value)
#define Iodd_WREG_P_01(Value)                TARG_WriteBit(P0, BIT1, Value)
#define Iodd_WREG_P_02(Value)                TARG_WriteBit(P0, BIT2, Value)
#define Iodd_WREG_P_03(Value)                TARG_WriteBit(P0, BIT3, Value)
#define Iodd_WREG_P_04(Value)                TARG_WriteBit(P0, BIT4, Value)
#define Iodd_WREG_P_05(Value)                TARG_WriteBit(P0, BIT5, Value)
#define Iodd_WREG_P_06(Value)                TARG_WriteBit(P0, BIT6, Value)
#define Iodd_WREG_P_07(Value)                TARG_WriteBit(P0, BIT7, Value)

#endif /* defined(__NEC_V850_DJ3__) || defined(__NEC_V850_DL3__) */

#if                                          \
      defined(__NEC_V850_DG3__)

#define Iodd_RREG_P_00                       TARG_ReadBit(P0, BIT0)
#define Iodd_RREG_P_01                       TARG_ReadBit(P0, BIT1)
#define Iodd_RREG_P_02                       TARG_ReadBit(P0, BIT2)
#define Iodd_RREG_P_03                       TARG_ReadBit(P0, BIT3)
#define Iodd_RREG_P_04                       /* read access defined but should not be used */
#define Iodd_RREG_P_05                       /* read access defined but should not be used */
#define Iodd_RREG_P_06                       /* read access defined but should not be used */
#define Iodd_RREG_P_07                       /* read access defined but should not be used */

#define Iodd_WREG_P_00(Value)                TARG_WriteBit(P0, BIT0, Value)
#define Iodd_WREG_P_01(Value)                TARG_WriteBit(P0, BIT1, Value)
#define Iodd_WREG_P_02(Value)                TARG_WriteBit(P0, BIT2, Value)
#define Iodd_WREG_P_03(Value)                TARG_WriteBit(P0, BIT3, Value)
#define Iodd_WREG_P_04(Value)                /* write access defined but should not be used */
#define Iodd_WREG_P_05(Value)                /* write access defined but should not be used */
#define Iodd_WREG_P_06(Value)                /* write access defined but should not be used */
#define Iodd_WREG_P_07(Value)                /* write access defined but should not be used */

#endif /* defined(__NEC_V850_DG3__) */

#if                                          \
      defined(__NEC_V850_DJ3__)||            \
      defined(__NEC_V850_DL3__)

#define Iodd_RREG_M_00                       TARG_ReadBit(PM0, BIT0)
#define Iodd_RREG_M_01                       TARG_ReadBit(PM0, BIT1)
#define Iodd_RREG_M_02                       TARG_ReadBit(PM0, BIT2)
#define Iodd_RREG_M_03                       TARG_ReadBit(PM0, BIT3)
#define Iodd_RREG_M_04                       TARG_ReadBit(PM0, BIT4)
#define Iodd_RREG_M_05                       TARG_ReadBit(PM0, BIT5)
#define Iodd_RREG_M_06                       TARG_ReadBit(PM0, BIT6)
#define Iodd_RREG_M_07                       TARG_ReadBit(PM0, BIT7)

#define Iodd_WREG_M_00(Value)                TARG_WriteBit(PM0, BIT0, Value)
#define Iodd_WREG_M_01(Value)                TARG_WriteBit(PM0, BIT1, Value)
#define Iodd_WREG_M_02(Value)                TARG_WriteBit(PM0, BIT2, Value)
#define Iodd_WREG_M_03(Value)                TARG_WriteBit(PM0, BIT3, Value)
#define Iodd_WREG_M_04(Value)                TARG_WriteBit(PM0, BIT4, Value)
#define Iodd_WREG_M_05(Value)                TARG_WriteBit(PM0, BIT5, Value)
#define Iodd_WREG_M_06(Value)                TARG_WriteBit(PM0, BIT6, Value)
#define Iodd_WREG_M_07(Value)                TARG_WriteBit(PM0, BIT7, Value)

#endif /* defined(__NEC_V850_DJ3__) || defined(__NEC_V850_DL3__) */

#if                                          \
      defined(__NEC_V850_DG3__)

#define Iodd_RREG_M_00                       TARG_ReadBit(PM0, BIT0)
#define Iodd_RREG_M_01                       TARG_ReadBit(PM0, BIT1)
#define Iodd_RREG_M_02                       TARG_ReadBit(PM0, BIT2)
#define Iodd_RREG_M_03                       TARG_ReadBit(PM0, BIT3)
#define Iodd_RREG_M_04                       /* read access defined but should not be used */
#define Iodd_RREG_M_05                       /* read access defined but should not be used */
#define Iodd_RREG_M_06                       /* read access defined but should not be used */
#define Iodd_RREG_M_07                       /* read access defined but should not be used */

#define Iodd_WREG_M_00(Value)                TARG_WriteBit(PM0, BIT0, Value)
#define Iodd_WREG_M_01(Value)                TARG_WriteBit(PM0, BIT1, Value)
#define Iodd_WREG_M_02(Value)                TARG_WriteBit(PM0, BIT2, Value)
#define Iodd_WREG_M_03(Value)                TARG_WriteBit(PM0, BIT3, Value)
#define Iodd_WREG_M_04(Value)                /* write access defined but should not be used */
#define Iodd_WREG_M_05(Value)                /* write access defined but should not be used */
#define Iodd_WREG_M_06(Value)                /* write access defined but should not be used */
#define Iodd_WREG_M_07(Value)                /* write access defined but should not be used */

#endif /* defined(__NEC_V850_DG3__) */

#if                                          \
      defined(__NEC_V850_DJ3__)||            \
      defined(__NEC_V850_DL3__)

#define Iodd_RREG_MC_00                      TARG_ReadBit(PMC0, BIT0)
#define Iodd_RREG_MC_01                      TARG_ReadBit(PMC0, BIT1)
#define Iodd_RREG_MC_02                      TARG_ReadBit(PMC0, BIT2)
#define Iodd_RREG_MC_03                      TARG_ReadBit(PMC0, BIT3)
#define Iodd_RREG_MC_04                      TARG_ReadBit(PMC0, BIT4)
#define Iodd_RREG_MC_05                      /* read access defined but should not be used */
#define Iodd_RREG_MC_06                      TARG_ReadBit(PMC0, BIT6)
#define Iodd_RREG_MC_07                      TARG_ReadBit(PMC0, BIT7)

#define Iodd_WREG_MC_00(Value)               TARG_WriteBit(PMC0, BIT0, Value)
#define Iodd_WREG_MC_01(Value)               TARG_WriteBit(PMC0, BIT1, Value)
#define Iodd_WREG_MC_02(Value)               TARG_WriteBit(PMC0, BIT2, Value)
#define Iodd_WREG_MC_03(Value)               TARG_WriteBit(PMC0, BIT3, Value)
#define Iodd_WREG_MC_04(Value)               TARG_WriteBit(PMC0, BIT4, Value)
#define Iodd_WREG_MC_05(Value)               /* write access not defined */
#define Iodd_WREG_MC_06(Value)               TARG_WriteBit(PMC0, BIT6, Value)
#define Iodd_WREG_MC_07(Value)               TARG_WriteBit(PMC0, BIT7, Value)

#endif /* defined(__NEC_V850_DJ3__) || defined(__NEC_V850_DL3__) */

#if                                          \
      defined(__NEC_V850_DG3__)

#define Iodd_RREG_MC_00                      /* register undefined */
#define Iodd_RREG_MC_01                      /* register undefined */
#define Iodd_RREG_MC_02                      /* register undefined */
#define Iodd_RREG_MC_03                      /* register undefined */
#define Iodd_RREG_MC_04                      /* register undefined */
#define Iodd_RREG_MC_05                      /* register undefined */
#define Iodd_RREG_MC_06                      /* register undefined */
#define Iodd_RREG_MC_07                      /* register undefined */

#define Iodd_WREG_MC_00(Value)               /* register undefined */
#define Iodd_WREG_MC_01(Value)               /* register undefined */
#define Iodd_WREG_MC_02(Value)               /* register undefined */
#define Iodd_WREG_MC_03(Value)               /* register undefined */
#define Iodd_WREG_MC_04(Value)               /* register undefined */
#define Iodd_WREG_MC_05(Value)               /* register undefined */
#define Iodd_WREG_MC_06(Value)               /* register undefined */
#define Iodd_WREG_MC_07(Value)               /* register undefined */

#endif /* defined(__NEC_V850_DG3__) */

#if                                          \
      defined(__NEC_V850_DJ3__)||            \
      defined(__NEC_V850_DL3__)

#define Iodd_RREG_DSC_00                     TARG_ReadBit(PDSC0, BIT0)
#define Iodd_RREG_DSC_01                     TARG_ReadBit(PDSC0, BIT1)
#define Iodd_RREG_DSC_02                     TARG_ReadBit(PDSC0, BIT2)
#define Iodd_RREG_DSC_03                     TARG_ReadBit(PDSC0, BIT3)
#define Iodd_RREG_DSC_04                     TARG_ReadBit(PDSC0, BIT4)
#define Iodd_RREG_DSC_05                     TARG_ReadBit(PDSC0, BIT5)
#define Iodd_RREG_DSC_06                     TARG_ReadBit(PDSC0, BIT6)
#define Iodd_RREG_DSC_07                     TARG_ReadBit(PDSC0, BIT7)

#define Iodd_WREG_DSC_00(Value)              TARG_WriteBit(PDSC0, BIT0, Value)
#define Iodd_WREG_DSC_01(Value)              TARG_WriteBit(PDSC0, BIT1, Value)
#define Iodd_WREG_DSC_02(Value)              TARG_WriteBit(PDSC0, BIT2, Value)
#define Iodd_WREG_DSC_03(Value)              TARG_WriteBit(PDSC0, BIT3, Value)
#define Iodd_WREG_DSC_04(Value)              TARG_WriteBit(PDSC0, BIT4, Value)
#define Iodd_WREG_DSC_05(Value)              TARG_WriteBit(PDSC0, BIT5, Value)
#define Iodd_WREG_DSC_06(Value)              TARG_WriteBit(PDSC0, BIT6, Value)
#define Iodd_WREG_DSC_07(Value)              TARG_WriteBit(PDSC0, BIT7, Value)

#endif /* defined(__NEC_V850_DJ3__) || defined(__NEC_V850_DL3__) */

#if                                          \
      defined(__NEC_V850_DG3__)

#define Iodd_RREG_DSC_00                     TARG_ReadBit(PDSC0, BIT0)
#define Iodd_RREG_DSC_01                     TARG_ReadBit(PDSC0, BIT1)
#define Iodd_RREG_DSC_02                     TARG_ReadBit(PDSC0, BIT2)
#define Iodd_RREG_DSC_03                     TARG_ReadBit(PDSC0, BIT3)
#define Iodd_RREG_DSC_04                     /* read access defined but should not be used */
#define Iodd_RREG_DSC_05                     /* read access defined but should not be used */
#define Iodd_RREG_DSC_06                     /* read access defined but should not be used */
#define Iodd_RREG_DSC_07                     /* read access defined but should not be used */

#define Iodd_WREG_DSC_00(Value)              TARG_WriteBit(PDSC0, BIT0, Value)
#define Iodd_WREG_DSC_01(Value)              TARG_WriteBit(PDSC0, BIT1, Value)
#define Iodd_WREG_DSC_02(Value)              TARG_WriteBit(PDSC0, BIT2, Value)
#define Iodd_WREG_DSC_03(Value)              TARG_WriteBit(PDSC0, BIT3, Value)
#define Iodd_WREG_DSC_04(Value)              /* write access defined but should not be used */
#define Iodd_WREG_DSC_05(Value)              /* write access defined but should not be used */
#define Iodd_WREG_DSC_06(Value)              /* write access defined but should not be used */
#define Iodd_WREG_DSC_07(Value)              /* write access defined but should not be used */

#endif /* defined(__NEC_V850_DG3__) */

#if                                          \
      defined(__NEC_V850_DJ3__)||            \
      defined(__NEC_V850_DL3__)

#define Iodd_RREG_ICC_00                     TARG_ReadBit(PICC0, BIT0)
#define Iodd_RREG_ICC_01                     TARG_ReadBit(PICC0, BIT1)
#define Iodd_RREG_ICC_02                     TARG_ReadBit(PICC0, BIT2)
#define Iodd_RREG_ICC_03                     TARG_ReadBit(PICC0, BIT3)
#define Iodd_RREG_ICC_04                     TARG_ReadBit(PICC0, BIT4)
#define Iodd_RREG_ICC_05                     TARG_ReadBit(PICC0, BIT5)
#define Iodd_RREG_ICC_06                     TARG_ReadBit(PICC0, BIT6)
#define Iodd_RREG_ICC_07                     TARG_ReadBit(PICC0, BIT7)

#define Iodd_WREG_ICC_00(Value)              TARG_WriteBit(PICC0, BIT0, Value)
#define Iodd_WREG_ICC_01(Value)              TARG_WriteBit(PICC0, BIT1, Value)
#define Iodd_WREG_ICC_02(Value)              TARG_WriteBit(PICC0, BIT2, Value)
#define Iodd_WREG_ICC_03(Value)              TARG_WriteBit(PICC0, BIT3, Value)
#define Iodd_WREG_ICC_04(Value)              TARG_WriteBit(PICC0, BIT4, Value)
#define Iodd_WREG_ICC_05(Value)              TARG_WriteBit(PICC0, BIT5, Value)
#define Iodd_WREG_ICC_06(Value)              TARG_WriteBit(PICC0, BIT6, Value)
#define Iodd_WREG_ICC_07(Value)              TARG_WriteBit(PICC0, BIT7, Value)

#endif /* defined(__NEC_V850_DJ3__) || defined(__NEC_V850_DL3__) */

#if                                          \
      defined(__NEC_V850_DG3__)

#define Iodd_RREG_ICC_00                     TARG_ReadBit(PICC0, BIT0)
#define Iodd_RREG_ICC_01                     TARG_ReadBit(PICC0, BIT1)
#define Iodd_RREG_ICC_02                     TARG_ReadBit(PICC0, BIT2)
#define Iodd_RREG_ICC_03                     TARG_ReadBit(PICC0, BIT3)
#define Iodd_RREG_ICC_04                     /* read access defined but should not be used */
#define Iodd_RREG_ICC_05                     /* read access defined but should not be used */
#define Iodd_RREG_ICC_06                     /* read access defined but should not be used */
#define Iodd_RREG_ICC_07                     /* read access defined but should not be used */

#define Iodd_WREG_ICC_00(Value)              TARG_WriteBit(PICC0, BIT0, Value)
#define Iodd_WREG_ICC_01(Value)              TARG_WriteBit(PICC0, BIT1, Value)
#define Iodd_WREG_ICC_02(Value)              TARG_WriteBit(PICC0, BIT2, Value)
#define Iodd_WREG_ICC_03(Value)              TARG_WriteBit(PICC0, BIT3, Value)
#define Iodd_WREG_ICC_04(Value)              /* write access defined but should not be used */
#define Iodd_WREG_ICC_05(Value)              /* write access defined but should not be used */
#define Iodd_WREG_ICC_06(Value)              /* write access defined but should not be used */
#define Iodd_WREG_ICC_07(Value)              /* write access defined but should not be used */

#endif /* defined(__NEC_V850_DG3__) */

#if                                          \
      defined(__NEC_V850_DJ3__)||            \
      defined(__NEC_V850_DL3__)

#define Iodd_RREG_ODC_00                     TARG_ReadBit(PODC0, BIT0)
#define Iodd_RREG_ODC_01                     TARG_ReadBit(PODC0, BIT1)
#define Iodd_RREG_ODC_02                     TARG_ReadBit(PODC0, BIT2)
#define Iodd_RREG_ODC_03                     TARG_ReadBit(PODC0, BIT3)
#define Iodd_RREG_ODC_04                     TARG_ReadBit(PODC0, BIT4)
#define Iodd_RREG_ODC_05                     TARG_ReadBit(PODC0, BIT5)
#define Iodd_RREG_ODC_06                     TARG_ReadBit(PODC0, BIT6)
#define Iodd_RREG_ODC_07                     TARG_ReadBit(PODC0, BIT7)

#define Iodd_WREG_ODC_00(Value)              TARG_WriteBit(PODC0, BIT0, Value)
#define Iodd_WREG_ODC_01(Value)              TARG_WriteBit(PODC0, BIT1, Value)
#define Iodd_WREG_ODC_02(Value)              TARG_WriteBit(PODC0, BIT2, Value)
#define Iodd_WREG_ODC_03(Value)              TARG_WriteBit(PODC0, BIT3, Value)
#define Iodd_WREG_ODC_04(Value)              TARG_WriteBit(PODC0, BIT4, Value)
#define Iodd_WREG_ODC_05(Value)              TARG_WriteBit(PODC0, BIT5, Value)
#define Iodd_WREG_ODC_06(Value)              TARG_WriteBit(PODC0, BIT6, Value)
#define Iodd_WREG_ODC_07(Value)              TARG_WriteBit(PODC0, BIT7, Value)

#endif /* defined(__NEC_V850_DJ3__) || defined(__NEC_V850_DL3__) */

#if                                          \
      defined(__NEC_V850_DG3__)

#define Iodd_RREG_ODC_00                     TARG_ReadBit(PODC0, BIT0)
#define Iodd_RREG_ODC_01                     TARG_ReadBit(PODC0, BIT1)
#define Iodd_RREG_ODC_02                     TARG_ReadBit(PODC0, BIT2)
#define Iodd_RREG_ODC_03                     TARG_ReadBit(PODC0, BIT3)
#define Iodd_RREG_ODC_04                     /* read access defined but should not be used */
#define Iodd_RREG_ODC_05                     /* read access defined but should not be used */
#define Iodd_RREG_ODC_06                     /* read access defined but should not be used */
#define Iodd_RREG_ODC_07                     /* read access defined but should not be used */

#define Iodd_WREG_ODC_00(Value)              TARG_WriteBit(PODC0, BIT0, Value)
#define Iodd_WREG_ODC_01(Value)              TARG_WriteBit(PODC0, BIT1, Value)
#define Iodd_WREG_ODC_02(Value)              TARG_WriteBit(PODC0, BIT2, Value)
#define Iodd_WREG_ODC_03(Value)              TARG_WriteBit(PODC0, BIT3, Value)
#define Iodd_WREG_ODC_04(Value)              /* write access defined but should not be used */
#define Iodd_WREG_ODC_05(Value)              /* write access defined but should not be used */
#define Iodd_WREG_ODC_06(Value)              /* write access defined but should not be used */
#define Iodd_WREG_ODC_07(Value)              /* write access defined but should not be used */

#endif /* defined(__NEC_V850_DG3__) */

#if                                          \
      defined(__NEC_V850_DJ3__)||            \
      defined(__NEC_V850_DL3__)

#define Iodd_RREG_FC_00                      /* read access defined but should not be used */
#define Iodd_RREG_FC_01                      /* read access defined but should not be used */
#define Iodd_RREG_FC_02                      /* read access defined but should not be used */
#define Iodd_RREG_FC_03                      /* read access defined but should not be used */
#define Iodd_RREG_FC_04                      /* read access defined but should not be used */
#define Iodd_RREG_FC_05                      TARG_ReadBit(PFC0, BIT5)
#define Iodd_RREG_FC_06                      /* read access defined but should not be used */
#define Iodd_RREG_FC_07                      TARG_ReadBit(PFC0, BIT7)

#define Iodd_WREG_FC_00(Value)               /* write access not defined */  
#define Iodd_WREG_FC_01(Value)               /* write access not defined */  
#define Iodd_WREG_FC_02(Value)               /* write access not defined */  
#define Iodd_WREG_FC_03(Value)               /* write access not defined */  
#define Iodd_WREG_FC_04(Value)               /* write access not defined */  
#define Iodd_WREG_FC_05(Value)               TARG_WriteBit(PFC0, BIT5, Value)
#define Iodd_WREG_FC_06(Value)               /* write access not defined */  
#define Iodd_WREG_FC_07(Value)               TARG_WriteBit(PFC0, BIT7, Value)

#endif /* defined(__NEC_V850_DJ3__) || defined(__NEC_V850_DL3__) */

#if                                          \
      defined(__NEC_V850_DG3__)

#define Iodd_RREG_FC_00                      /* register undefined */
#define Iodd_RREG_FC_01                      /* register undefined */
#define Iodd_RREG_FC_02                      /* register undefined */
#define Iodd_RREG_FC_03                      /* register undefined */
#define Iodd_RREG_FC_04                      /* register undefined */
#define Iodd_RREG_FC_05                      /* register undefined */
#define Iodd_RREG_FC_06                      /* register undefined */
#define Iodd_RREG_FC_07                      /* register undefined */

#define Iodd_WREG_FC_00(Value)               /* register undefined */
#define Iodd_WREG_FC_01(Value)               /* register undefined */
#define Iodd_WREG_FC_02(Value)               /* register undefined */
#define Iodd_WREG_FC_03(Value)               /* register undefined */
#define Iodd_WREG_FC_04(Value)               /* register undefined */
#define Iodd_WREG_FC_05(Value)               /* register undefined */
#define Iodd_WREG_FC_06(Value)               /* register undefined */
#define Iodd_WREG_FC_07(Value)               /* register undefined */

#endif /* defined(__NEC_V850_DG3__) */

#if                                          \
      defined(__NEC_V850_DJ3__)||            \
      defined(__NEC_V850_DL3__)

#define Iodd_RREG_PR_00                      TARG_ReadBit(PPR0, BIT0)
#define Iodd_RREG_PR_01                      TARG_ReadBit(PPR0, BIT1)
#define Iodd_RREG_PR_02                      TARG_ReadBit(PPR0, BIT2)
#define Iodd_RREG_PR_03                      TARG_ReadBit(PPR0, BIT3)
#define Iodd_RREG_PR_04                      TARG_ReadBit(PPR0, BIT4)
#define Iodd_RREG_PR_05                      TARG_ReadBit(PPR0, BIT5)
#define Iodd_RREG_PR_06                      TARG_ReadBit(PPR0, BIT6)
#define Iodd_RREG_PR_07                      TARG_ReadBit(PPR0, BIT7)

#define Iodd_WREG_PR_00(Value)               /* write access not defined */
#define Iodd_WREG_PR_01(Value)               /* write access not defined */
#define Iodd_WREG_PR_02(Value)               /* write access not defined */
#define Iodd_WREG_PR_03(Value)               /* write access not defined */
#define Iodd_WREG_PR_04(Value)               /* write access not defined */
#define Iodd_WREG_PR_05(Value)               /* write access not defined */
#define Iodd_WREG_PR_06(Value)               /* write access not defined */
#define Iodd_WREG_PR_07(Value)               /* write access not defined */

#endif /* defined(__NEC_V850_DJ3__) || defined(__NEC_V850_DL3__) */

#if                                          \
      defined(__NEC_V850_DG3__)

#define Iodd_RREG_PR_00                      TARG_ReadBit(PPR0, BIT0)
#define Iodd_RREG_PR_01                      TARG_ReadBit(PPR0, BIT1)
#define Iodd_RREG_PR_02                      TARG_ReadBit(PPR0, BIT2)
#define Iodd_RREG_PR_03                      TARG_ReadBit(PPR0, BIT3)
#define Iodd_RREG_PR_04                      /* read access defined but should not be used */
#define Iodd_RREG_PR_05                      /* read access defined but should not be used */
#define Iodd_RREG_PR_06                      /* read access defined but should not be used */
#define Iodd_RREG_PR_07                      /* read access defined but should not be used */

#define Iodd_WREG_PR_00(Value)               /* write access not defined */
#define Iodd_WREG_PR_01(Value)               /* write access not defined */
#define Iodd_WREG_PR_02(Value)               /* write access not defined */
#define Iodd_WREG_PR_03(Value)               /* write access not defined */
#define Iodd_WREG_PR_04(Value)               /* write access not defined */
#define Iodd_WREG_PR_05(Value)               /* write access not defined */
#define Iodd_WREG_PR_06(Value)               /* write access not defined */
#define Iodd_WREG_PR_07(Value)               /* write access not defined */

#endif /* defined(__NEC_V850_DG3__) */

#if                                          \
      defined(__NEC_V850_DJ3__)||            \
      defined(__NEC_V850_DL3__)

#define Iodd_RREG_ILC_00                     /* register undefined */
#define Iodd_RREG_ILC_01                     /* register undefined */
#define Iodd_RREG_ILC_02                     /* register undefined */
#define Iodd_RREG_ILC_03                     /* register undefined */
#define Iodd_RREG_ILC_04                     /* register undefined */
#define Iodd_RREG_ILC_05                     /* register undefined */
#define Iodd_RREG_ILC_06                     /* register undefined */
#define Iodd_RREG_ILC_07                     /* register undefined */
                                                                    
#define Iodd_WREG_ILC_00(Value)              /* register undefined */
#define Iodd_WREG_ILC_01(Value)              /* register undefined */
#define Iodd_WREG_ILC_02(Value)              /* register undefined */
#define Iodd_WREG_ILC_03(Value)              /* register undefined */
#define Iodd_WREG_ILC_04(Value)              /* register undefined */
#define Iodd_WREG_ILC_05(Value)              /* register undefined */
#define Iodd_WREG_ILC_06(Value)              /* register undefined */
#define Iodd_WREG_ILC_07(Value)              /* register undefined */

#endif /* defined(__NEC_V850_DJ3__) || defined(__NEC_V850_DL3__) */

#if                                          \
      defined(__NEC_V850_DG3__)

#define Iodd_RREG_ILC_00                     TARG_ReadBit(PILC0, BIT0)
#define Iodd_RREG_ILC_01                     TARG_ReadBit(PILC0, BIT1)
#define Iodd_RREG_ILC_02                     TARG_ReadBit(PILC0, BIT2)
#define Iodd_RREG_ILC_03                     TARG_ReadBit(PILC0, BIT3)
#define Iodd_RREG_ILC_04                     /* read access defined but should not be used */
#define Iodd_RREG_ILC_05                     /* read access defined but should not be used */
#define Iodd_RREG_ILC_06                     /* read access defined but should not be used */
#define Iodd_RREG_ILC_07                     /* read access defined but should not be used */

#define Iodd_WREG_ILC_00(Value)              TARG_WriteBit(PILC0, BIT0, Value)
#define Iodd_WREG_ILC_01(Value)              TARG_WriteBit(PILC0, BIT1, Value)
#define Iodd_WREG_ILC_02(Value)              TARG_WriteBit(PILC0, BIT2, Value)
#define Iodd_WREG_ILC_03(Value)              TARG_WriteBit(PILC0, BIT3, Value)
#define Iodd_WREG_ILC_04(Value)              /* write access not defined */
#define Iodd_WREG_ILC_05(Value)              /* write access not defined */
#define Iodd_WREG_ILC_06(Value)              /* write access not defined */
#define Iodd_WREG_ILC_07(Value)              /* write access not defined */

#endif /* defined(__NEC_V850_DG3__) */

#if                                          \
      defined(__NEC_V850_Dx3__)

#define Iodd_RREG_LCDC_00                    /* register undefined */
#define Iodd_RREG_LCDC_01                    /* register undefined */
#define Iodd_RREG_LCDC_02                    /* register undefined */
#define Iodd_RREG_LCDC_03                    /* register undefined */
#define Iodd_RREG_LCDC_04                    /* register undefined */
#define Iodd_RREG_LCDC_05                    /* register undefined */
#define Iodd_RREG_LCDC_06                    /* register undefined */
#define Iodd_RREG_LCDC_07                    /* register undefined */

#define Iodd_WREG_LCDC_00(Value)             /* register undefined */
#define Iodd_WREG_LCDC_01(Value)             /* register undefined */
#define Iodd_WREG_LCDC_02(Value)             /* register undefined */
#define Iodd_WREG_LCDC_03(Value)             /* register undefined */
#define Iodd_WREG_LCDC_04(Value)             /* register undefined */
#define Iodd_WREG_LCDC_05(Value)             /* register undefined */
#define Iodd_WREG_LCDC_06(Value)             /* register undefined */
#define Iodd_WREG_LCDC_07(Value)             /* register undefined */

#endif

#if                                          \
      defined(__NEC_V850_DJ3__)||            \
      defined(__NEC_V850_DL3__)

#define Iodd_RREG_RC_00                       /* register undefined */
#define Iodd_RREG_RC_01                       /* register undefined */
#define Iodd_RREG_RC_02                       /* register undefined */
#define Iodd_RREG_RC_03                       /* register undefined */
#define Iodd_RREG_RC_04                       /* register undefined */
#define Iodd_RREG_RC_05                       /* register undefined */
#define Iodd_RREG_RC_06                       /* register undefined */
#define Iodd_RREG_RC_07                       /* register undefined */
                                                                      
#define Iodd_WREG_RC_00(Value)                /* register undefined */
#define Iodd_WREG_RC_01(Value)                /* register undefined */
#define Iodd_WREG_RC_02(Value)                /* register undefined */
#define Iodd_WREG_RC_03(Value)                /* register undefined */
#define Iodd_WREG_RC_04(Value)                /* register undefined */
#define Iodd_WREG_RC_05(Value)                /* register undefined */
#define Iodd_WREG_RC_06(Value)                /* register undefined */
#define Iodd_WREG_RC_07(Value)                /* register undefined */

#endif /* defined(__NEC_V850_DJ3__) || defined(__NEC_V850_DL3__) */

#if                                          \
      defined(__NEC_V850_DG3__)

#define Iodd_RREG_RC_00                       TARG_ReadBit(PRC0, BIT0)
#define Iodd_RREG_RC_01                       /* read access defined but should not be used */
#define Iodd_RREG_RC_02                       /* read access defined but should not be used */
#define Iodd_RREG_RC_03                       /* read access defined but should not be used */
#define Iodd_RREG_RC_04                       /* read access defined but should not be used */
#define Iodd_RREG_RC_05                       /* read access defined but should not be used */
#define Iodd_RREG_RC_06                       /* read access defined but should not be used */
#define Iodd_RREG_RC_07                       /* read access defined but should not be used */

#define Iodd_WREG_RC_00(Value)                TARG_WriteBit(PRC0, BIT0, Value)
#define Iodd_WREG_RC_01(Value)                /* write access not defined */
#define Iodd_WREG_RC_02(Value)                /* write access not defined */
#define Iodd_WREG_RC_03(Value)                /* write access not defined */
#define Iodd_WREG_RC_04(Value)                /* write access not defined */
#define Iodd_WREG_RC_05(Value)                /* write access not defined */
#define Iodd_WREG_RC_06(Value)                /* write access not defined */
#define Iodd_WREG_RC_07(Value)                /* write access not defined */

#endif /* defined(__NEC_V850_DG3__) */

/* Definitions PORT 1 */

#if                                          \
      defined(__NEC_V850_Dx3__)

#define Iodd_RREG_P_10                       /* read access defined but should not be used */
#define Iodd_RREG_P_11                       /* read access defined but should not be used */
#define Iodd_RREG_P_12                       /* read access defined but should not be used */
#define Iodd_RREG_P_13                       /* read access defined but should not be used */
#define Iodd_RREG_P_14                       /* read access defined but should not be used */
#define Iodd_RREG_P_15                       /* read access defined but should not be used */
#define Iodd_RREG_P_16                       TARG_ReadBit(P1, BIT6)
#define Iodd_RREG_P_17                       TARG_ReadBit(P1, BIT7)

#define Iodd_WREG_P_10(Value)                /* write access not defined */
#define Iodd_WREG_P_11(Value)                /* write access not defined */
#define Iodd_WREG_P_12(Value)                /* write access not defined */
#define Iodd_WREG_P_13(Value)                /* write access not defined */
#define Iodd_WREG_P_14(Value)                /* write access not defined */
#define Iodd_WREG_P_15(Value)                /* write access not defined */
#define Iodd_WREG_P_16(Value)                TARG_WriteBit(P1, BIT6, Value)
#define Iodd_WREG_P_17(Value)                TARG_WriteBit(P1, BIT7, Value)

#endif

#if                                          \
      defined(__NEC_V850_Dx3__)

#define Iodd_RREG_M_10                       /* read access defined but should not be used */
#define Iodd_RREG_M_11                       /* read access defined but should not be used */
#define Iodd_RREG_M_12                       /* read access defined but should not be used */
#define Iodd_RREG_M_13                       /* read access defined but should not be used */
#define Iodd_RREG_M_14                       /* read access defined but should not be used */
#define Iodd_RREG_M_15                       /* read access defined but should not be used */
#define Iodd_RREG_M_16                       TARG_ReadBit(PM1, BIT6)
#define Iodd_RREG_M_17                       TARG_ReadBit(PM1, BIT7)

#define Iodd_WREG_M_10(Value)                /* write access not defined */
#define Iodd_WREG_M_11(Value)                /* write access not defined */
#define Iodd_WREG_M_12(Value)                /* write access not defined */
#define Iodd_WREG_M_13(Value)                /* write access not defined */
#define Iodd_WREG_M_14(Value)                /* write access not defined */
#define Iodd_WREG_M_15(Value)                /* write access not defined */
#define Iodd_WREG_M_16(Value)                TARG_WriteBit(PM1, BIT6, Value)
#define Iodd_WREG_M_17(Value)                TARG_WriteBit(PM1, BIT7, Value)

#endif

#if                                          \
      defined(__NEC_V850_Dx3__)

#define Iodd_RREG_MC_10                      /* read access defined but should not be used */
#define Iodd_RREG_MC_11                      /* read access defined but should not be used */
#define Iodd_RREG_MC_12                      /* read access defined but should not be used */
#define Iodd_RREG_MC_13                      /* read access defined but should not be used */
#define Iodd_RREG_MC_14                      /* read access defined but should not be used */
#define Iodd_RREG_MC_15                      /* read access defined but should not be used */
#define Iodd_RREG_MC_16                      TARG_ReadBit(PMC1, BIT6)
#define Iodd_RREG_MC_17                      TARG_ReadBit(PMC1, BIT7)

#define Iodd_WREG_MC_10(Value)               /* write access not defined */
#define Iodd_WREG_MC_11(Value)               /* write access not defined */
#define Iodd_WREG_MC_12(Value)               /* write access not defined */
#define Iodd_WREG_MC_13(Value)               /* write access not defined */
#define Iodd_WREG_MC_14(Value)               /* write access not defined */
#define Iodd_WREG_MC_15(Value)               /* write access not defined */
#define Iodd_WREG_MC_16(Value)               TARG_WriteBit(PMC1, BIT6, Value)
#define Iodd_WREG_MC_17(Value)               TARG_WriteBit(PMC1, BIT7, Value)

#endif

#if                                          \
      defined(__NEC_V850_Dx3__)

#define Iodd_RREG_DSC_10                     /* read access defined but should not be used */
#define Iodd_RREG_DSC_11                     /* read access defined but should not be used */
#define Iodd_RREG_DSC_12                     /* read access defined but should not be used */
#define Iodd_RREG_DSC_13                     /* read access defined but should not be used */
#define Iodd_RREG_DSC_14                     /* read access defined but should not be used */
#define Iodd_RREG_DSC_15                     /* read access defined but should not be used */
#define Iodd_RREG_DSC_16                     TARG_ReadBit(PDSC1, BIT6)
#define Iodd_RREG_DSC_17                     TARG_ReadBit(PDSC1, BIT7)

#define Iodd_WREG_DSC_10(Value)              /* write access not defined */
#define Iodd_WREG_DSC_11(Value)              /* write access not defined */
#define Iodd_WREG_DSC_12(Value)              /* write access not defined */
#define Iodd_WREG_DSC_13(Value)              /* write access not defined */
#define Iodd_WREG_DSC_14(Value)              /* write access not defined */
#define Iodd_WREG_DSC_15(Value)              /* write access not defined */
#define Iodd_WREG_DSC_16(Value)              TARG_WriteBit(PDSC1, BIT6, Value)
#define Iodd_WREG_DSC_17(Value)              TARG_WriteBit(PDSC1, BIT7, Value)

#endif

#if                                          \
      defined(__NEC_V850_Dx3__)

#define Iodd_RREG_ICC_10                     /* read access defined but should not be used */
#define Iodd_RREG_ICC_11                     /* read access defined but should not be used */
#define Iodd_RREG_ICC_12                     /* read access defined but should not be used */
#define Iodd_RREG_ICC_13                     /* read access defined but should not be used */
#define Iodd_RREG_ICC_14                     /* read access defined but should not be used */
#define Iodd_RREG_ICC_15                     /* read access defined but should not be used */
#define Iodd_RREG_ICC_16                     TARG_ReadBit(PICC1, BIT6)
#define Iodd_RREG_ICC_17                     TARG_ReadBit(PICC1, BIT7)

#define Iodd_WREG_ICC_10(Value)              /* write access not defined */
#define Iodd_WREG_ICC_11(Value)              /* write access not defined */
#define Iodd_WREG_ICC_12(Value)              /* write access not defined */
#define Iodd_WREG_ICC_13(Value)              /* write access not defined */
#define Iodd_WREG_ICC_14(Value)              /* write access not defined */
#define Iodd_WREG_ICC_15(Value)              /* write access not defined */
#define Iodd_WREG_ICC_16(Value)              TARG_WriteBit(PICC1, BIT6, Value)
#define Iodd_WREG_ICC_17(Value)              TARG_WriteBit(PICC1, BIT7, Value)

#endif

#if                                          \
      defined(__NEC_V850_Dx3__)

#define Iodd_RREG_ODC_10                     /* read access defined but should not be used */
#define Iodd_RREG_ODC_11                     /* read access defined but should not be used */
#define Iodd_RREG_ODC_12                     /* read access defined but should not be used */
#define Iodd_RREG_ODC_13                     /* read access defined but should not be used */
#define Iodd_RREG_ODC_14                     /* read access defined but should not be used */
#define Iodd_RREG_ODC_15                     /* read access defined but should not be used */
#define Iodd_RREG_ODC_16                     TARG_ReadBit(PODC1, BIT6)
#define Iodd_RREG_ODC_17                     TARG_ReadBit(PODC1, BIT7)

#define Iodd_WREG_ODC_10(Value)              /* write access not defined */
#define Iodd_WREG_ODC_11(Value)              /* write access not defined */
#define Iodd_WREG_ODC_12(Value)              /* write access not defined */
#define Iodd_WREG_ODC_13(Value)              /* write access not defined */
#define Iodd_WREG_ODC_14(Value)              /* write access not defined */
#define Iodd_WREG_ODC_15(Value)              /* write access not defined */
#define Iodd_WREG_ODC_16(Value)              TARG_WriteBit(PODC1, BIT6, Value)
#define Iodd_WREG_ODC_17(Value)              TARG_WriteBit(PODC1, BIT7, Value)

#endif

#if                                          \
      defined(__NEC_V850_Dx3__)

#define Iodd_RREG_PR_10                      /* read access defined but should not be used */
#define Iodd_RREG_PR_11                      /* read access defined but should not be used */
#define Iodd_RREG_PR_12                      /* read access defined but should not be used */
#define Iodd_RREG_PR_13                      /* read access defined but should not be used */
#define Iodd_RREG_PR_14                      /* read access defined but should not be used */
#define Iodd_RREG_PR_15                      /* read access defined but should not be used */
#define Iodd_RREG_PR_16                      TARG_ReadBit(PPR1, BIT6)
#define Iodd_RREG_PR_17                      TARG_ReadBit(PPR1, BIT7)

#define Iodd_WREG_PR_10(Value)               /* write access not defined */
#define Iodd_WREG_PR_11(Value)               /* write access not defined */
#define Iodd_WREG_PR_12(Value)               /* write access not defined */
#define Iodd_WREG_PR_13(Value)               /* write access not defined */
#define Iodd_WREG_PR_14(Value)               /* write access not defined */
#define Iodd_WREG_PR_15(Value)               /* write access not defined */
#define Iodd_WREG_PR_16(Value)               /* write access not defined */
#define Iodd_WREG_PR_17(Value)               /* write access not defined */

#endif

#if                                          \
      defined(__NEC_V850_DJ3__)||            \
      defined(__NEC_V850_DL3__)

#define Iodd_RREG_ILC_10                     /* register undefined */
#define Iodd_RREG_ILC_11                     /* register undefined */
#define Iodd_RREG_ILC_12                     /* register undefined */
#define Iodd_RREG_ILC_13                     /* register undefined */
#define Iodd_RREG_ILC_14                     /* register undefined */
#define Iodd_RREG_ILC_15                     /* register undefined */
#define Iodd_RREG_ILC_16                     /* register undefined */
#define Iodd_RREG_ILC_17                     /* register undefined */
                                                                    
#define Iodd_WREG_ILC_10(Value)              /* register undefined */
#define Iodd_WREG_ILC_11(Value)              /* register undefined */
#define Iodd_WREG_ILC_12(Value)              /* register undefined */
#define Iodd_WREG_ILC_13(Value)              /* register undefined */
#define Iodd_WREG_ILC_14(Value)              /* register undefined */
#define Iodd_WREG_ILC_15(Value)              /* register undefined */
#define Iodd_WREG_ILC_16(Value)              /* register undefined */
#define Iodd_WREG_ILC_17(Value)              /* register undefined */

#endif /* defined(__NEC_V850_DJ3__) || defined(__NEC_V850_DL3__) */

#if                                          \
      defined(__NEC_V850_DG3__)

#define Iodd_RREG_ILC_10                     /* read access defined but should not be used */
#define Iodd_RREG_ILC_11                     /* read access defined but should not be used */
#define Iodd_RREG_ILC_12                     /* read access defined but should not be used */
#define Iodd_RREG_ILC_13                     /* read access defined but should not be used */
#define Iodd_RREG_ILC_14                     /* read access defined but should not be used */
#define Iodd_RREG_ILC_15                     /* read access defined but should not be used */
#define Iodd_RREG_ILC_16                     TARG_ReadBit(PILC1, BIT6)
#define Iodd_RREG_ILC_17                     TARG_ReadBit(PILC1, BIT7)

#define Iodd_WREG_ILC_10(Value)              /* write access not defined */
#define Iodd_WREG_ILC_11(Value)              /* write access not defined */
#define Iodd_WREG_ILC_12(Value)              /* write access not defined */
#define Iodd_WREG_ILC_13(Value)              /* write access not defined */
#define Iodd_WREG_ILC_14(Value)              /* write access not defined */
#define Iodd_WREG_ILC_15(Value)              /* write access not defined */
#define Iodd_WREG_ILC_16(Value)              TARG_WriteBit(PILC1, BIT6, Value)
#define Iodd_WREG_ILC_17(Value)              TARG_WriteBit(PILC1, BIT7, Value)

#endif /* defined(__NEC_V850_DG3__) */

#if                                          \
      defined(__NEC_V850_Dx3__)

#define Iodd_RREG_FC_10                      /* register undefined */
#define Iodd_RREG_FC_11                      /* register undefined */
#define Iodd_RREG_FC_12                      /* register undefined */
#define Iodd_RREG_FC_13                      /* register undefined */
#define Iodd_RREG_FC_14                      /* register undefined */
#define Iodd_RREG_FC_15                      /* register undefined */
#define Iodd_RREG_FC_16                      /* register undefined */
#define Iodd_RREG_FC_17                      /* register undefined */

#define Iodd_WREG_FC_10(Value)               /* register undefined */
#define Iodd_WREG_FC_11(Value)               /* register undefined */
#define Iodd_WREG_FC_12(Value)               /* register undefined */
#define Iodd_WREG_FC_13(Value)               /* register undefined */
#define Iodd_WREG_FC_14(Value)               /* register undefined */
#define Iodd_WREG_FC_15(Value)               /* register undefined */
#define Iodd_WREG_FC_16(Value)               /* register undefined */
#define Iodd_WREG_FC_17(Value)               /* register undefined */

#endif

#if                                          \
      defined(__NEC_V850_Dx3__)

#define Iodd_RREG_LCDC_10                    /* register undefined */
#define Iodd_RREG_LCDC_11                    /* register undefined */
#define Iodd_RREG_LCDC_12                    /* register undefined */
#define Iodd_RREG_LCDC_13                    /* register undefined */
#define Iodd_RREG_LCDC_14                    /* register undefined */
#define Iodd_RREG_LCDC_15                    /* register undefined */
#define Iodd_RREG_LCDC_16                    /* register undefined */
#define Iodd_RREG_LCDC_17                    /* register undefined */

#define Iodd_WREG_LCDC_10(Value)             /* register undefined */
#define Iodd_WREG_LCDC_11(Value)             /* register undefined */
#define Iodd_WREG_LCDC_12(Value)             /* register undefined */
#define Iodd_WREG_LCDC_13(Value)             /* register undefined */
#define Iodd_WREG_LCDC_14(Value)             /* register undefined */
#define Iodd_WREG_LCDC_15(Value)             /* register undefined */
#define Iodd_WREG_LCDC_16(Value)             /* register undefined */
#define Iodd_WREG_LCDC_17(Value)             /* register undefined */

#endif

#if                                          \
      defined(__NEC_V850_DJ3__)||            \
      defined(__NEC_V850_DL3__)

#define Iodd_RREG_RC_10                       /* register undefined */
#define Iodd_RREG_RC_11                       /* register undefined */
#define Iodd_RREG_RC_12                       /* register undefined */
#define Iodd_RREG_RC_13                       /* register undefined */
#define Iodd_RREG_RC_14                       /* register undefined */
#define Iodd_RREG_RC_15                       /* register undefined */
#define Iodd_RREG_RC_16                       /* register undefined */
#define Iodd_RREG_RC_17                       /* register undefined */
                                                                      
#define Iodd_WREG_RC_10(Value)                /* register undefined */
#define Iodd_WREG_RC_11(Value)                /* register undefined */
#define Iodd_WREG_RC_12(Value)                /* register undefined */
#define Iodd_WREG_RC_13(Value)                /* register undefined */
#define Iodd_WREG_RC_14(Value)                /* register undefined */
#define Iodd_WREG_RC_15(Value)                /* register undefined */
#define Iodd_WREG_RC_16(Value)                /* register undefined */
#define Iodd_WREG_RC_17(Value)                /* register undefined */

#endif /* defined(__NEC_V850_DJ3__) || defined(__NEC_V850_DL3__) */

#if                                          \
      defined(__NEC_V850_DG3__)

#define Iodd_RREG_RC_10                       TARG_ReadBit(PRC1, BIT0)
#define Iodd_RREG_RC_11                       /* read access defined but should not be used */
#define Iodd_RREG_RC_12                       /* read access defined but should not be used */
#define Iodd_RREG_RC_13                       /* read access defined but should not be used */
#define Iodd_RREG_RC_14                       /* read access defined but should not be used */
#define Iodd_RREG_RC_15                       /* read access defined but should not be used */
#define Iodd_RREG_RC_16                       /* read access defined but should not be used */
#define Iodd_RREG_RC_17                       /* read access defined but should not be used */

#define Iodd_WREG_RC_10(Value)                TARG_WriteBit(PRC1, BIT0, Value)
#define Iodd_WREG_RC_11(Value)                /* write access not defined */
#define Iodd_WREG_RC_12(Value)                /* write access not defined */
#define Iodd_WREG_RC_13(Value)                /* write access not defined */
#define Iodd_WREG_RC_14(Value)                /* write access not defined */
#define Iodd_WREG_RC_15(Value)                /* write access not defined */
#define Iodd_WREG_RC_16(Value)                /* write access not defined */
#define Iodd_WREG_RC_17(Value)                /* write access not defined */

#endif /* defined(__NEC_V850_DG3__) */

/* Definitions PORT 2 */

#if                                          \
      defined(__NEC_V850_Dx3__)

#define Iodd_RREG_P_20                       TARG_ReadBit(P2, BIT0)
#define Iodd_RREG_P_21                       TARG_ReadBit(P2, BIT1)
#define Iodd_RREG_P_22                       TARG_ReadBit(P2, BIT2)
#define Iodd_RREG_P_23                       TARG_ReadBit(P2, BIT3)
#define Iodd_RREG_P_24                       TARG_ReadBit(P2, BIT4)
#define Iodd_RREG_P_25                       TARG_ReadBit(P2, BIT5)
#define Iodd_RREG_P_26                       TARG_ReadBit(P2, BIT6)
#define Iodd_RREG_P_27                       TARG_ReadBit(P2, BIT7)

#define Iodd_WREG_P_20(Value)                TARG_WriteBit(P2, BIT0, Value)
#define Iodd_WREG_P_21(Value)                TARG_WriteBit(P2, BIT1, Value)
#define Iodd_WREG_P_22(Value)                TARG_WriteBit(P2, BIT2, Value)
#define Iodd_WREG_P_23(Value)                TARG_WriteBit(P2, BIT3, Value)
#define Iodd_WREG_P_24(Value)                TARG_WriteBit(P2, BIT4, Value)
#define Iodd_WREG_P_25(Value)                TARG_WriteBit(P2, BIT5, Value)
#define Iodd_WREG_P_26(Value)                TARG_WriteBit(P2, BIT6, Value)
#define Iodd_WREG_P_27(Value)                TARG_WriteBit(P2, BIT7, Value)

#endif

#if                                          \
      defined(__NEC_V850_Dx3__)

#define Iodd_RREG_M_20                       TARG_ReadBit(PM2, BIT0)
#define Iodd_RREG_M_21                       TARG_ReadBit(PM2, BIT1)
#define Iodd_RREG_M_22                       TARG_ReadBit(PM2, BIT2)
#define Iodd_RREG_M_23                       TARG_ReadBit(PM2, BIT3)
#define Iodd_RREG_M_24                       TARG_ReadBit(PM2, BIT4)
#define Iodd_RREG_M_25                       TARG_ReadBit(PM2, BIT5)
#define Iodd_RREG_M_26                       TARG_ReadBit(PM2, BIT6)
#define Iodd_RREG_M_27                       TARG_ReadBit(PM2, BIT7)

#define Iodd_WREG_M_20(Value)                TARG_WriteBit(PM2, BIT0, Value)
#define Iodd_WREG_M_21(Value)                TARG_WriteBit(PM2, BIT1, Value)
#define Iodd_WREG_M_22(Value)                TARG_WriteBit(PM2, BIT2, Value)
#define Iodd_WREG_M_23(Value)                TARG_WriteBit(PM2, BIT3, Value)
#define Iodd_WREG_M_24(Value)                TARG_WriteBit(PM2, BIT4, Value)
#define Iodd_WREG_M_25(Value)                TARG_WriteBit(PM2, BIT5, Value)
#define Iodd_WREG_M_26(Value)                TARG_WriteBit(PM2, BIT6, Value)
#define Iodd_WREG_M_27(Value)                TARG_WriteBit(PM2, BIT7, Value)

#endif

#if                                          \
      defined(__NEC_V850_Dx3__)

#define Iodd_RREG_MC_20                      TARG_ReadBit(PMC2, BIT0)
#define Iodd_RREG_MC_21                      TARG_ReadBit(PMC2, BIT1)
#define Iodd_RREG_MC_22                      TARG_ReadBit(PMC2, BIT2)
#define Iodd_RREG_MC_23                      TARG_ReadBit(PMC2, BIT3)
#define Iodd_RREG_MC_24                      TARG_ReadBit(PMC2, BIT4)
#define Iodd_RREG_MC_25                      TARG_ReadBit(PMC2, BIT5)
#define Iodd_RREG_MC_26                      TARG_ReadBit(PMC2, BIT6)
#define Iodd_RREG_MC_27                      TARG_ReadBit(PMC2, BIT7)

#define Iodd_WREG_MC_20(Value)               TARG_WriteBit(PMC2, BIT0, Value)
#define Iodd_WREG_MC_21(Value)               TARG_WriteBit(PMC2, BIT1, Value)
#define Iodd_WREG_MC_22(Value)               TARG_WriteBit(PMC2, BIT2, Value)
#define Iodd_WREG_MC_23(Value)               TARG_WriteBit(PMC2, BIT3, Value)
#define Iodd_WREG_MC_24(Value)               TARG_WriteBit(PMC2, BIT4, Value)
#define Iodd_WREG_MC_25(Value)               TARG_WriteBit(PMC2, BIT5, Value)
#define Iodd_WREG_MC_26(Value)               TARG_WriteBit(PMC2, BIT6, Value)
#define Iodd_WREG_MC_27(Value)               TARG_WriteBit(PMC2, BIT7, Value)

#endif

#if                                          \
      defined(__NEC_V850_Dx3__)

#define Iodd_RREG_DSC_20                     TARG_ReadBit(PDSC2, BIT0)
#define Iodd_RREG_DSC_21                     TARG_ReadBit(PDSC2, BIT1)
#define Iodd_RREG_DSC_22                     TARG_ReadBit(PDSC2, BIT2)
#define Iodd_RREG_DSC_23                     TARG_ReadBit(PDSC2, BIT3)
#define Iodd_RREG_DSC_24                     TARG_ReadBit(PDSC2, BIT4)
#define Iodd_RREG_DSC_25                     TARG_ReadBit(PDSC2, BIT5)
#define Iodd_RREG_DSC_26                     TARG_ReadBit(PDSC2, BIT6)
#define Iodd_RREG_DSC_27                     TARG_ReadBit(PDSC2, BIT7)

#define Iodd_WREG_DSC_20(Value)              TARG_WriteBit(PDSC2, BIT0, Value)
#define Iodd_WREG_DSC_21(Value)              TARG_WriteBit(PDSC2, BIT1, Value)
#define Iodd_WREG_DSC_22(Value)              TARG_WriteBit(PDSC2, BIT2, Value)
#define Iodd_WREG_DSC_23(Value)              TARG_WriteBit(PDSC2, BIT3, Value)
#define Iodd_WREG_DSC_24(Value)              TARG_WriteBit(PDSC2, BIT4, Value)
#define Iodd_WREG_DSC_25(Value)              TARG_WriteBit(PDSC2, BIT5, Value)
#define Iodd_WREG_DSC_26(Value)              TARG_WriteBit(PDSC2, BIT6, Value)
#define Iodd_WREG_DSC_27(Value)              TARG_WriteBit(PDSC2, BIT7, Value)

#endif

#if                                          \
      defined(__NEC_V850_Dx3__)

#define Iodd_RREG_ICC_20                     TARG_ReadBit(PICC2, BIT0)
#define Iodd_RREG_ICC_21                     TARG_ReadBit(PICC2, BIT1)
#define Iodd_RREG_ICC_22                     TARG_ReadBit(PICC2, BIT2)
#define Iodd_RREG_ICC_23                     TARG_ReadBit(PICC2, BIT3)
#define Iodd_RREG_ICC_24                     TARG_ReadBit(PICC2, BIT4)
#define Iodd_RREG_ICC_25                     TARG_ReadBit(PICC2, BIT5)
#define Iodd_RREG_ICC_26                     TARG_ReadBit(PICC2, BIT6)
#define Iodd_RREG_ICC_27                     TARG_ReadBit(PICC2, BIT7)

#define Iodd_WREG_ICC_20(Value)              TARG_WriteBit(PICC2, BIT0, Value)
#define Iodd_WREG_ICC_21(Value)              TARG_WriteBit(PICC2, BIT1, Value)
#define Iodd_WREG_ICC_22(Value)              TARG_WriteBit(PICC2, BIT2, Value)
#define Iodd_WREG_ICC_23(Value)              TARG_WriteBit(PICC2, BIT3, Value)
#define Iodd_WREG_ICC_24(Value)              TARG_WriteBit(PICC2, BIT4, Value)
#define Iodd_WREG_ICC_25(Value)              TARG_WriteBit(PICC2, BIT5, Value)
#define Iodd_WREG_ICC_26(Value)              TARG_WriteBit(PICC2, BIT6, Value)
#define Iodd_WREG_ICC_27(Value)              TARG_WriteBit(PICC2, BIT7, Value)

#endif

#if                                          \
      defined(__NEC_V850_Dx3__)

#define Iodd_RREG_ODC_20                     TARG_ReadBit(PODC2, BIT0)
#define Iodd_RREG_ODC_21                     TARG_ReadBit(PODC2, BIT1)
#define Iodd_RREG_ODC_22                     TARG_ReadBit(PODC2, BIT2)
#define Iodd_RREG_ODC_23                     TARG_ReadBit(PODC2, BIT3)
#define Iodd_RREG_ODC_24                     TARG_ReadBit(PODC2, BIT4)
#define Iodd_RREG_ODC_25                     TARG_ReadBit(PODC2, BIT5)
#define Iodd_RREG_ODC_26                     TARG_ReadBit(PODC2, BIT6)
#define Iodd_RREG_ODC_27                     TARG_ReadBit(PODC2, BIT7)

#define Iodd_WREG_ODC_20(Value)              TARG_WriteBit(PODC2, BIT0, Value)
#define Iodd_WREG_ODC_21(Value)              TARG_WriteBit(PODC2, BIT1, Value)
#define Iodd_WREG_ODC_22(Value)              TARG_WriteBit(PODC2, BIT2, Value)
#define Iodd_WREG_ODC_23(Value)              TARG_WriteBit(PODC2, BIT3, Value)
#define Iodd_WREG_ODC_24(Value)              TARG_WriteBit(PODC2, BIT4, Value)
#define Iodd_WREG_ODC_25(Value)              TARG_WriteBit(PODC2, BIT5, Value)
#define Iodd_WREG_ODC_26(Value)              TARG_WriteBit(PODC2, BIT6, Value)
#define Iodd_WREG_ODC_27(Value)              TARG_WriteBit(PODC2, BIT7, Value)

#endif

#if                                          \
      defined(__NEC_V850_DJ3__)||            \
      defined(__NEC_V850_DL3__)

#define Iodd_RREG_FC_20                      /* register undefined */
#define Iodd_RREG_FC_21                      /* register undefined */
#define Iodd_RREG_FC_22                      /* register undefined */
#define Iodd_RREG_FC_23                      /* register undefined */
#define Iodd_RREG_FC_24                      /* register undefined */
#define Iodd_RREG_FC_25                      /* register undefined */
#define Iodd_RREG_FC_26                      /* register undefined */
#define Iodd_RREG_FC_27                      /* register undefined */
                                                                     
#define Iodd_WREG_FC_20(Value)               /* register undefined */
#define Iodd_WREG_FC_21(Value)               /* register undefined */
#define Iodd_WREG_FC_22(Value)               /* register undefined */
#define Iodd_WREG_FC_23(Value)               /* register undefined */
#define Iodd_WREG_FC_24(Value)               /* register undefined */
#define Iodd_WREG_FC_25(Value)               /* register undefined */
#define Iodd_WREG_FC_26(Value)               /* register undefined */
#define Iodd_WREG_FC_27(Value)               /* register undefined */

#endif /* defined(__NEC_V850_DJ3__) || defined(__NEC_V850_DL3__) */

#if                                          \
      defined(__NEC_V850_DG3__)

#define Iodd_RREG_FC_20                      TARG_ReadBit(PFC2, BIT0)
#define Iodd_RREG_FC_21                      TARG_ReadBit(PFC2, BIT1)
#define Iodd_RREG_FC_22                      /* read access defined but should not be used */
#define Iodd_RREG_FC_23                      /* read access defined but should not be used */
#define Iodd_RREG_FC_24                      /* read access defined but should not be used */
#define Iodd_RREG_FC_25                      /* read access defined but should not be used */
#define Iodd_RREG_FC_26                      /* read access defined but should not be used */
#define Iodd_RREG_FC_27                      /* read access defined but should not be used */
                                                                                             
#define Iodd_WREG_FC_20(Value)               TARG_WriteBit(PFC2, BIT0, Value)                  
#define Iodd_WREG_FC_21(Value)               TARG_WriteBit(PFC2, BIT1, Value)                  
#define Iodd_WREG_FC_22(Value)               /* write access not defined */                  
#define Iodd_WREG_FC_23(Value)               /* write access not defined */                  
#define Iodd_WREG_FC_24(Value)               /* write access not defined */                  
#define Iodd_WREG_FC_25(Value)               /* write access not defined */                                  
#define Iodd_WREG_FC_26(Value)               /* write access not defined */                  
#define Iodd_WREG_FC_27(Value)               /* write access not defined */                  

#endif /* defined(__NEC_V850_DG3__) */

#if                                          \
      defined(__NEC_V850_Dx3__)

#define Iodd_RREG_PR_20                      TARG_ReadBit(PPR2, BIT0)
#define Iodd_RREG_PR_21                      TARG_ReadBit(PPR2, BIT1)
#define Iodd_RREG_PR_22                      TARG_ReadBit(PPR2, BIT2)
#define Iodd_RREG_PR_23                      TARG_ReadBit(PPR2, BIT3)
#define Iodd_RREG_PR_24                      TARG_ReadBit(PPR2, BIT4)
#define Iodd_RREG_PR_25                      TARG_ReadBit(PPR2, BIT5)
#define Iodd_RREG_PR_26                      TARG_ReadBit(PPR2, BIT6)
#define Iodd_RREG_PR_27                      TARG_ReadBit(PPR2, BIT7)

#define Iodd_WREG_PR_20(Value)               /* write access not defined */
#define Iodd_WREG_PR_21(Value)               /* write access not defined */
#define Iodd_WREG_PR_22(Value)               /* write access not defined */
#define Iodd_WREG_PR_23(Value)               /* write access not defined */
#define Iodd_WREG_PR_24(Value)               /* write access not defined */
#define Iodd_WREG_PR_25(Value)               /* write access not defined */
#define Iodd_WREG_PR_26(Value)               /* write access not defined */
#define Iodd_WREG_PR_27(Value)               /* write access not defined */

#endif

#if                                          \
      defined(__NEC_V850_DG3__)||            \
      defined(__NEC_V850_DJ3_LE__)

#define Iodd_RREG_LCDC_20                    TARG_ReadBit(PLCDC2, BIT0)
#define Iodd_RREG_LCDC_21                    TARG_ReadBit(PLCDC2, BIT1)
#define Iodd_RREG_LCDC_22                    TARG_ReadBit(PLCDC2, BIT2)
#define Iodd_RREG_LCDC_23                    TARG_ReadBit(PLCDC2, BIT3)
#define Iodd_RREG_LCDC_24                    TARG_ReadBit(PLCDC2, BIT4)
#define Iodd_RREG_LCDC_25                    TARG_ReadBit(PLCDC2, BIT5)
#define Iodd_RREG_LCDC_26                    TARG_ReadBit(PLCDC2, BIT6)
#define Iodd_RREG_LCDC_27                    TARG_ReadBit(PLCDC2, BIT7)

#define Iodd_WREG_LCDC_20(Value)             TARG_WriteBit(PLCDC2, BIT0, Value)
#define Iodd_WREG_LCDC_21(Value)             TARG_WriteBit(PLCDC2, BIT1, Value)
#define Iodd_WREG_LCDC_22(Value)             TARG_WriteBit(PLCDC2, BIT2, Value)
#define Iodd_WREG_LCDC_23(Value)             TARG_WriteBit(PLCDC2, BIT3, Value)
#define Iodd_WREG_LCDC_24(Value)             TARG_WriteBit(PLCDC2, BIT4, Value)
#define Iodd_WREG_LCDC_25(Value)             TARG_WriteBit(PLCDC2, BIT5, Value)
#define Iodd_WREG_LCDC_26(Value)             TARG_WriteBit(PLCDC2, BIT6, Value)
#define Iodd_WREG_LCDC_27(Value)             TARG_WriteBit(PLCDC2, BIT7, Value)

#endif

#if                                          \
      defined(__NEC_V850_DL3__)||            \
      defined(__NEC_V850_DJ3_HE__)

#define Iodd_RREG_LCDC_20                    /* register undefined */
#define Iodd_RREG_LCDC_21                    /* register undefined */
#define Iodd_RREG_LCDC_22                    /* register undefined */
#define Iodd_RREG_LCDC_23                    /* register undefined */
#define Iodd_RREG_LCDC_24                    /* register undefined */
#define Iodd_RREG_LCDC_25                    /* register undefined */
#define Iodd_RREG_LCDC_26                    /* register undefined */
#define Iodd_RREG_LCDC_27                    /* register undefined */

#define Iodd_WREG_LCDC_20(Value)             /* register undefined */
#define Iodd_WREG_LCDC_21(Value)             /* register undefined */
#define Iodd_WREG_LCDC_22(Value)             /* register undefined */
#define Iodd_WREG_LCDC_23(Value)             /* register undefined */
#define Iodd_WREG_LCDC_24(Value)             /* register undefined */
#define Iodd_WREG_LCDC_25(Value)             /* register undefined */
#define Iodd_WREG_LCDC_26(Value)             /* register undefined */
#define Iodd_WREG_LCDC_27(Value)             /* register undefined */

#endif

#if                                          \
      defined(__NEC_V850_DJ3__)||            \
      defined(__NEC_V850_DL3__)

#define Iodd_RREG_ILC_20                     /* register undefined */
#define Iodd_RREG_ILC_21                     /* register undefined */
#define Iodd_RREG_ILC_22                     /* register undefined */
#define Iodd_RREG_ILC_23                     /* register undefined */
#define Iodd_RREG_ILC_24                     /* register undefined */
#define Iodd_RREG_ILC_25                     /* register undefined */
#define Iodd_RREG_ILC_26                     /* register undefined */
#define Iodd_RREG_ILC_27                     /* register undefined */
                                                                    
#define Iodd_WREG_ILC_20(Value)              /* register undefined */
#define Iodd_WREG_ILC_21(Value)              /* register undefined */
#define Iodd_WREG_ILC_22(Value)              /* register undefined */
#define Iodd_WREG_ILC_23(Value)              /* register undefined */
#define Iodd_WREG_ILC_24(Value)              /* register undefined */
#define Iodd_WREG_ILC_25(Value)              /* register undefined */
#define Iodd_WREG_ILC_26(Value)              /* register undefined */
#define Iodd_WREG_ILC_27(Value)              /* register undefined */

#endif /* defined(__NEC_V850_DJ3__) || defined(__NEC_V850_DL3__) */

#if                                          \
      defined(__NEC_V850_DG3__)

#define Iodd_RREG_ILC_20                     TARG_ReadBit(PILC2, BIT0)
#define Iodd_RREG_ILC_21                     TARG_ReadBit(PILC2, BIT1)
#define Iodd_RREG_ILC_22                     TARG_ReadBit(PILC2, BIT2)
#define Iodd_RREG_ILC_23                     TARG_ReadBit(PILC2, BIT3)
#define Iodd_RREG_ILC_24                     TARG_ReadBit(PILC2, BIT4)
#define Iodd_RREG_ILC_25                     TARG_ReadBit(PILC2, BIT5)
#define Iodd_RREG_ILC_26                     TARG_ReadBit(PILC2, BIT6)
#define Iodd_RREG_ILC_27                     TARG_ReadBit(PILC2, BIT7)

#define Iodd_WREG_ILC_20(Value)              TARG_WriteBit(PILC2, BIT0, Value)
#define Iodd_WREG_ILC_21(Value)              TARG_WriteBit(PILC2, BIT1, Value)
#define Iodd_WREG_ILC_22(Value)              TARG_WriteBit(PILC2, BIT2, Value)
#define Iodd_WREG_ILC_23(Value)              TARG_WriteBit(PILC2, BIT3, Value)
#define Iodd_WREG_ILC_24(Value)              TARG_WriteBit(PILC2, BIT4, Value)
#define Iodd_WREG_ILC_25(Value)              TARG_WriteBit(PILC2, BIT5, Value)
#define Iodd_WREG_ILC_26(Value)              TARG_WriteBit(PILC2, BIT6, Value)
#define Iodd_WREG_ILC_27(Value)              TARG_WriteBit(PILC2, BIT7, Value)

#endif /* defined(__NEC_V850_DG3__) */

#if                                          \
      defined(__NEC_V850_DJ3__)||            \
      defined(__NEC_V850_DL3__)

#define Iodd_RREG_RC_20                       /* register undefined */
#define Iodd_RREG_RC_21                       /* register undefined */
#define Iodd_RREG_RC_22                       /* register undefined */
#define Iodd_RREG_RC_23                       /* register undefined */
#define Iodd_RREG_RC_24                       /* register undefined */
#define Iodd_RREG_RC_25                       /* register undefined */
#define Iodd_RREG_RC_26                       /* register undefined */
#define Iodd_RREG_RC_27                       /* register undefined */
                                                                      
#define Iodd_WREG_RC_20(Value)                /* register undefined */
#define Iodd_WREG_RC_21(Value)                /* register undefined */
#define Iodd_WREG_RC_22(Value)                /* register undefined */
#define Iodd_WREG_RC_23(Value)                /* register undefined */
#define Iodd_WREG_RC_24(Value)                /* register undefined */
#define Iodd_WREG_RC_25(Value)                /* register undefined */
#define Iodd_WREG_RC_26(Value)                /* register undefined */
#define Iodd_WREG_RC_27(Value)                /* register undefined */

#endif /* defined(__NEC_V850_DJ3__) || defined(__NEC_V850_DL3__) */

#if                                          \
      defined(__NEC_V850_DG3__)

#define Iodd_RREG_RC_20                       TARG_ReadBit(PRC2, BIT0)
#define Iodd_RREG_RC_21                       /* read access defined but should not be used */
#define Iodd_RREG_RC_22                       /* read access defined but should not be used */
#define Iodd_RREG_RC_23                       /* read access defined but should not be used */
#define Iodd_RREG_RC_24                       /* read access defined but should not be used */
#define Iodd_RREG_RC_25                       /* read access defined but should not be used */
#define Iodd_RREG_RC_26                       /* read access defined but should not be used */
#define Iodd_RREG_RC_27                       /* read access defined but should not be used */

#define Iodd_WREG_RC_20(Value)                TARG_WriteBit(PRC2, BIT0, Value)
#define Iodd_WREG_RC_21(Value)                /* write access not defined */
#define Iodd_WREG_RC_22(Value)                /* write access not defined */
#define Iodd_WREG_RC_23(Value)                /* write access not defined */
#define Iodd_WREG_RC_24(Value)                /* write access not defined */
#define Iodd_WREG_RC_25(Value)                /* write access not defined */
#define Iodd_WREG_RC_26(Value)                /* write access not defined */
#define Iodd_WREG_RC_27(Value)                /* write access not defined */

#endif /* defined(__NEC_V850_DG3__) */

/* Definitions PORT 3 */

#if                                          \
      defined(__NEC_V850_Dx3__)

#define Iodd_RREG_P_30                       TARG_ReadBit(P3, BIT0)
#define Iodd_RREG_P_31                       TARG_ReadBit(P3, BIT1)
#define Iodd_RREG_P_32                       TARG_ReadBit(P3, BIT2)
#define Iodd_RREG_P_33                       TARG_ReadBit(P3, BIT3)
#define Iodd_RREG_P_34                       TARG_ReadBit(P3, BIT4)
#define Iodd_RREG_P_35                       TARG_ReadBit(P3, BIT5)
#define Iodd_RREG_P_36                       TARG_ReadBit(P3, BIT6)
#define Iodd_RREG_P_37                       TARG_ReadBit(P3, BIT7)

#define Iodd_WREG_P_30(Value)                TARG_WriteBit(P3, BIT0, Value)
#define Iodd_WREG_P_31(Value)                TARG_WriteBit(P3, BIT1, Value)
#define Iodd_WREG_P_32(Value)                TARG_WriteBit(P3, BIT2, Value)
#define Iodd_WREG_P_33(Value)                TARG_WriteBit(P3, BIT3, Value)
#define Iodd_WREG_P_34(Value)                TARG_WriteBit(P3, BIT4, Value)
#define Iodd_WREG_P_35(Value)                TARG_WriteBit(P3, BIT5, Value)
#define Iodd_WREG_P_36(Value)                TARG_WriteBit(P3, BIT6, Value)
#define Iodd_WREG_P_37(Value)                TARG_WriteBit(P3, BIT7, Value)

#endif

#if                                          \
      defined(__NEC_V850_Dx3__)

#define Iodd_RREG_M_30                       TARG_ReadBit(PM3, BIT0)
#define Iodd_RREG_M_31                       TARG_ReadBit(PM3, BIT1)
#define Iodd_RREG_M_32                       TARG_ReadBit(PM3, BIT2)
#define Iodd_RREG_M_33                       TARG_ReadBit(PM3, BIT3)
#define Iodd_RREG_M_34                       TARG_ReadBit(PM3, BIT4)
#define Iodd_RREG_M_35                       TARG_ReadBit(PM3, BIT5)
#define Iodd_RREG_M_36                       TARG_ReadBit(PM3, BIT6)
#define Iodd_RREG_M_37                       TARG_ReadBit(PM3, BIT7)

#define Iodd_WREG_M_30(Value)                TARG_WriteBit(PM3, BIT0, Value)
#define Iodd_WREG_M_31(Value)                TARG_WriteBit(PM3, BIT1, Value)
#define Iodd_WREG_M_32(Value)                TARG_WriteBit(PM3, BIT2, Value)
#define Iodd_WREG_M_33(Value)                TARG_WriteBit(PM3, BIT3, Value)
#define Iodd_WREG_M_34(Value)                TARG_WriteBit(PM3, BIT4, Value)
#define Iodd_WREG_M_35(Value)                TARG_WriteBit(PM3, BIT5, Value)
#define Iodd_WREG_M_36(Value)                TARG_WriteBit(PM3, BIT6, Value)
#define Iodd_WREG_M_37(Value)                TARG_WriteBit(PM3, BIT7, Value)

#endif

#if                                          \
      defined(__NEC_V850_DJ3__)||            \
      defined(__NEC_V850_DL3__)

#define Iodd_RREG_MC_30                      TARG_ReadBit(PMC3, BIT0)
#define Iodd_RREG_MC_31                      TARG_ReadBit(PMC3, BIT1)
#define Iodd_RREG_MC_32                      TARG_ReadBit(PMC3, BIT2)
#define Iodd_RREG_MC_33                      TARG_ReadBit(PMC3, BIT3)
#define Iodd_RREG_MC_34                      TARG_ReadBit(PMC3, BIT4)
#define Iodd_RREG_MC_35                      TARG_ReadBit(PMC3, BIT5)
#define Iodd_RREG_MC_36                      TARG_ReadBit(PMC3, BIT6)
#define Iodd_RREG_MC_37                      TARG_ReadBit(PMC3, BIT7)

#define Iodd_WREG_MC_30(Value)               TARG_WriteBit(PMC3, BIT0, Value)
#define Iodd_WREG_MC_31(Value)               TARG_WriteBit(PMC3, BIT1, Value)
#define Iodd_WREG_MC_32(Value)               TARG_WriteBit(PMC3, BIT2, Value)
#define Iodd_WREG_MC_33(Value)               TARG_WriteBit(PMC3, BIT3, Value)
#define Iodd_WREG_MC_34(Value)               TARG_WriteBit(PMC3, BIT4, Value)
#define Iodd_WREG_MC_35(Value)               TARG_WriteBit(PMC3, BIT5, Value)
#define Iodd_WREG_MC_36(Value)               TARG_WriteBit(PMC3, BIT6, Value)
#define Iodd_WREG_MC_37(Value)               TARG_WriteBit(PMC3, BIT7, Value)

#endif /* defined(__NEC_V850_DJ3__) || defined(__NEC_V850_DL3__) */

#if                                          \
      defined(__NEC_V850_DG3__)

#define Iodd_RREG_MC_30                      TARG_ReadBit(PMC3, BIT0)                         
#define Iodd_RREG_MC_31                      /* read access defined but should not be used */ 
#define Iodd_RREG_MC_32                      TARG_ReadBit(PMC3, BIT2)                         
#define Iodd_RREG_MC_33                      /* read access defined but should not be used */ 
#define Iodd_RREG_MC_34                      TARG_ReadBit(PMC3, BIT4)                         
#define Iodd_RREG_MC_35                      /* read access defined but should not be used */ 
#define Iodd_RREG_MC_36                      /* read access defined but should not be used */ 
#define Iodd_RREG_MC_37                      /* read access defined but should not be used */ 
                                                                                              
#define Iodd_WREG_MC_30(Value)               TARG_WriteBit(PMC3, BIT0, Value)                 
#define Iodd_WREG_MC_31(Value)               /* write access not defined */                   
#define Iodd_WREG_MC_32(Value)               TARG_WriteBit(PMC3, BIT2, Value)                 
#define Iodd_WREG_MC_33(Value)               /* write access not defined */                   
#define Iodd_WREG_MC_34(Value)               TARG_WriteBit(PMC3, BIT4, Value)                 
#define Iodd_WREG_MC_35(Value)               /* write access not defined */                   
#define Iodd_WREG_MC_36(Value)               /* write access not defined */                   
#define Iodd_WREG_MC_37(Value)               /* write access not defined */                   

#endif /* defined(__NEC_V850_DG3__) */

#if                                          \
      defined(__NEC_V850_DG3__)||            \
      defined(__NEC_V850_DJ3__)

#define Iodd_RREG_DSC_30                     TARG_ReadBit(PDSC3, BIT0)
#define Iodd_RREG_DSC_31                     TARG_ReadBit(PDSC3, BIT1)
#define Iodd_RREG_DSC_32                     TARG_ReadBit(PDSC3, BIT2)
#define Iodd_RREG_DSC_33                     TARG_ReadBit(PDSC3, BIT3)
#define Iodd_RREG_DSC_34                     TARG_ReadBit(PDSC3, BIT4)
#define Iodd_RREG_DSC_35                     TARG_ReadBit(PDSC3, BIT5)
#define Iodd_RREG_DSC_36                     TARG_ReadBit(PDSC3, BIT6)
#define Iodd_RREG_DSC_37                     TARG_ReadBit(PDSC3, BIT7)

#define Iodd_WREG_DSC_30(Value)              TARG_WriteBit(PDSC3, BIT0, Value)
#define Iodd_WREG_DSC_31(Value)              TARG_WriteBit(PDSC3, BIT1, Value)
#define Iodd_WREG_DSC_32(Value)              TARG_WriteBit(PDSC3, BIT2, Value)
#define Iodd_WREG_DSC_33(Value)              TARG_WriteBit(PDSC3, BIT3, Value)
#define Iodd_WREG_DSC_34(Value)              TARG_WriteBit(PDSC3, BIT4, Value)
#define Iodd_WREG_DSC_35(Value)              TARG_WriteBit(PDSC3, BIT5, Value)
#define Iodd_WREG_DSC_36(Value)              TARG_WriteBit(PDSC3, BIT6, Value)
#define Iodd_WREG_DSC_37(Value)              TARG_WriteBit(PDSC3, BIT7, Value)

#endif /* defined(__NEC_V850_DG3__) || defined(__NEC_V850_DJ3__) */

#if                                          \
      defined(__NEC_V850_DL3__)

#define Iodd_RREG_DSC_30                     TARG_ReadBit(PDSC3, BIT0)
#define Iodd_RREG_DSC_31                     TARG_ReadBit(PDSC3, BIT1)
#define Iodd_RREG_DSC_32                     /* read access not defined */ 
#define Iodd_RREG_DSC_33                     /* read access not defined */
#define Iodd_RREG_DSC_34                     TARG_ReadBit(PDSC3, BIT4)
#define Iodd_RREG_DSC_35                     TARG_ReadBit(PDSC3, BIT5)
#define Iodd_RREG_DSC_36                     TARG_ReadBit(PDSC3, BIT6)
#define Iodd_RREG_DSC_37                     TARG_ReadBit(PDSC3, BIT7)

#define Iodd_WREG_DSC_30(Value)              TARG_WriteBit(PDSC3, BIT0, Value)
#define Iodd_WREG_DSC_31(Value)              TARG_WriteBit(PDSC3, BIT1, Value)
#define Iodd_WREG_DSC_32(Value)              /* write access not defined */
#define Iodd_WREG_DSC_33(Value)              /* write access not defined */
#define Iodd_WREG_DSC_34(Value)              TARG_WriteBit(PDSC3, BIT4, Value)
#define Iodd_WREG_DSC_35(Value)              TARG_WriteBit(PDSC3, BIT5, Value)
#define Iodd_WREG_DSC_36(Value)              TARG_WriteBit(PDSC3, BIT6, Value)
#define Iodd_WREG_DSC_37(Value)              TARG_WriteBit(PDSC3, BIT7, Value)

#endif /* defined(__NEC_V850_DL3__) */

#if                                          \
      defined(__NEC_V850_DJ3__)||            \
      defined(__NEC_V850_DL3__)

#define Iodd_RREG_ICC_30                     /* register undefined */
#define Iodd_RREG_ICC_31                     /* register undefined */
#define Iodd_RREG_ICC_32                     /* register undefined */
#define Iodd_RREG_ICC_33                     /* register undefined */
#define Iodd_RREG_ICC_34                     /* register undefined */
#define Iodd_RREG_ICC_35                     /* register undefined */
#define Iodd_RREG_ICC_36                     /* register undefined */
#define Iodd_RREG_ICC_37                     /* register undefined */

#define Iodd_WREG_ICC_30(Value)              /* register undefined */
#define Iodd_WREG_ICC_31(Value)              /* register undefined */
#define Iodd_WREG_ICC_32(Value)              /* register undefined */
#define Iodd_WREG_ICC_33(Value)              /* register undefined */
#define Iodd_WREG_ICC_34(Value)              /* register undefined */
#define Iodd_WREG_ICC_35(Value)              /* register undefined */
#define Iodd_WREG_ICC_36(Value)              /* register undefined */
#define Iodd_WREG_ICC_37(Value)              /* register undefined */

#endif /* defined(__NEC_V850_DJ3__) || defined(__NEC_V850_DL3__) */

#if                                          \
      defined(__NEC_V850_DG3__)

#define Iodd_RREG_ICC_30                     TARG_ReadBit(PICC3, BIT0)        
#define Iodd_RREG_ICC_31                     TARG_ReadBit(PICC3, BIT1)        
#define Iodd_RREG_ICC_32                     TARG_ReadBit(PICC3, BIT2)        
#define Iodd_RREG_ICC_33                     TARG_ReadBit(PICC3, BIT3)        
#define Iodd_RREG_ICC_34                     TARG_ReadBit(PICC3, BIT4)        
#define Iodd_RREG_ICC_35                     TARG_ReadBit(PICC3, BIT5)        
#define Iodd_RREG_ICC_36                     TARG_ReadBit(PICC3, BIT6)        
#define Iodd_RREG_ICC_37                     TARG_ReadBit(PICC3, BIT7)        
                                                                              
#define Iodd_WREG_ICC_30(Value)              TARG_WriteBit(PICC3, BIT0, Value)
#define Iodd_WREG_ICC_31(Value)              TARG_WriteBit(PICC3, BIT1, Value)
#define Iodd_WREG_ICC_32(Value)              TARG_WriteBit(PICC3, BIT2, Value)
#define Iodd_WREG_ICC_33(Value)              TARG_WriteBit(PICC3, BIT3, Value)
#define Iodd_WREG_ICC_34(Value)              TARG_WriteBit(PICC3, BIT4, Value)
#define Iodd_WREG_ICC_35(Value)              TARG_WriteBit(PICC3, BIT5, Value)
#define Iodd_WREG_ICC_36(Value)              TARG_WriteBit(PICC3, BIT6, Value)
#define Iodd_WREG_ICC_37(Value)              TARG_WriteBit(PICC3, BIT7, Value)

#endif /* defined(__NEC_V850_DG3__) */

#if                                          \
      defined(__NEC_V850_Dx3__)

#define Iodd_RREG_ODC_30                     TARG_ReadBit(PODC3, BIT0)
#define Iodd_RREG_ODC_31                     TARG_ReadBit(PODC3, BIT1)
#define Iodd_RREG_ODC_32                     TARG_ReadBit(PODC3, BIT2)
#define Iodd_RREG_ODC_33                     TARG_ReadBit(PODC3, BIT3)
#define Iodd_RREG_ODC_34                     TARG_ReadBit(PODC3, BIT4)
#define Iodd_RREG_ODC_35                     TARG_ReadBit(PODC3, BIT5)
#define Iodd_RREG_ODC_36                     TARG_ReadBit(PODC3, BIT6)
#define Iodd_RREG_ODC_37                     TARG_ReadBit(PODC3, BIT7)

#define Iodd_WREG_ODC_30(Value)              TARG_WriteBit(PODC3, BIT0, Value)
#define Iodd_WREG_ODC_31(Value)              TARG_WriteBit(PODC3, BIT1, Value)
#define Iodd_WREG_ODC_32(Value)              TARG_WriteBit(PODC3, BIT2, Value)
#define Iodd_WREG_ODC_33(Value)              TARG_WriteBit(PODC3, BIT3, Value)
#define Iodd_WREG_ODC_34(Value)              TARG_WriteBit(PODC3, BIT4, Value)
#define Iodd_WREG_ODC_35(Value)              TARG_WriteBit(PODC3, BIT5, Value)
#define Iodd_WREG_ODC_36(Value)              TARG_WriteBit(PODC3, BIT6, Value)
#define Iodd_WREG_ODC_37(Value)              TARG_WriteBit(PODC3, BIT7, Value)

#endif

#if                                          \
      defined(__NEC_V850_DJ3__)||            \
      defined(__NEC_V850_DL3__)

#define Iodd_RREG_FC_30                      TARG_ReadBit(PFC3, BIT0)        
#define Iodd_RREG_FC_31                      /* read access defined but should not be used */ 
#define Iodd_RREG_FC_32                      /* read access defined but should not be used */ 
#define Iodd_RREG_FC_33                      /* read access defined but should not be used */ 
#define Iodd_RREG_FC_34                      TARG_ReadBit(PFC3, BIT4)        
#define Iodd_RREG_FC_35                      TARG_ReadBit(PFC3, BIT5)        
#define Iodd_RREG_FC_36                      TARG_ReadBit(PFC3, BIT6)        
#define Iodd_RREG_FC_37                      TARG_ReadBit(PFC3, BIT7)        
                                                                             
#define Iodd_WREG_FC_30(Value)               TARG_WriteBit(PFC3, BIT0, Value)
#define Iodd_WREG_FC_31(Value)               /* write access not defined */  
#define Iodd_WREG_FC_32(Value)               /* write access not defined */  
#define Iodd_WREG_FC_33(Value)               /* write access not defined */  
#define Iodd_WREG_FC_34(Value)               TARG_WriteBit(PFC3, BIT4, Value)
#define Iodd_WREG_FC_35(Value)               TARG_WriteBit(PFC3, BIT5, Value)
#define Iodd_WREG_FC_36(Value)               TARG_WriteBit(PFC3, BIT6, Value)
#define Iodd_WREG_FC_37(Value)               TARG_WriteBit(PFC3, BIT7, Value)

#endif /* defined(__NEC_V850_DJ3__) || defined(__NEC_V850_DL3__) */

#if                                          \
      defined(__NEC_V850_DG3__)

#define Iodd_RREG_FC_30                      /* register undefined */
#define Iodd_RREG_FC_31                      /* register undefined */
#define Iodd_RREG_FC_32                      /* register undefined */
#define Iodd_RREG_FC_33                      /* register undefined */
#define Iodd_RREG_FC_34                      /* register undefined */
#define Iodd_RREG_FC_35                      /* register undefined */
#define Iodd_RREG_FC_36                      /* register undefined */
#define Iodd_RREG_FC_37                      /* register undefined */

#define Iodd_WREG_FC_30(Value)               /* register undefined */
#define Iodd_WREG_FC_31(Value)               /* register undefined */
#define Iodd_WREG_FC_32(Value)               /* register undefined */
#define Iodd_WREG_FC_33(Value)               /* register undefined */
#define Iodd_WREG_FC_34(Value)               /* register undefined */
#define Iodd_WREG_FC_35(Value)               /* register undefined */
#define Iodd_WREG_FC_36(Value)               /* register undefined */
#define Iodd_WREG_FC_37(Value)               /* register undefined */

#endif /* defined(__NEC_V850_DG3__) */

#if                                          \
      defined(__NEC_V850_Dx3__)

#define Iodd_RREG_PR_30                      TARG_ReadBit(PPR3, BIT0)
#define Iodd_RREG_PR_31                      TARG_ReadBit(PPR3, BIT1)
#define Iodd_RREG_PR_32                      TARG_ReadBit(PPR3, BIT2)
#define Iodd_RREG_PR_33                      TARG_ReadBit(PPR3, BIT3)
#define Iodd_RREG_PR_34                      TARG_ReadBit(PPR3, BIT4)
#define Iodd_RREG_PR_35                      TARG_ReadBit(PPR3, BIT5)
#define Iodd_RREG_PR_36                      TARG_ReadBit(PPR3, BIT6)
#define Iodd_RREG_PR_37                      TARG_ReadBit(PPR3, BIT7)

#define Iodd_WREG_PR_30(Value)               /* write access not defined */
#define Iodd_WREG_PR_31(Value)               /* write access not defined */
#define Iodd_WREG_PR_32(Value)               /* write access not defined */
#define Iodd_WREG_PR_33(Value)               /* write access not defined */
#define Iodd_WREG_PR_34(Value)               /* write access not defined */
#define Iodd_WREG_PR_35(Value)               /* write access not defined */
#define Iodd_WREG_PR_36(Value)               /* write access not defined */
#define Iodd_WREG_PR_37(Value)               /* write access not defined */

#endif

#if                                          \
      defined(__NEC_V850_DG3__)||            \
      defined(__NEC_V850_DJ3_LE__)

#define Iodd_RREG_LCDC_30                    /* read access defined but should not be used */
#define Iodd_RREG_LCDC_31                    /* read access defined but should not be used */
#define Iodd_RREG_LCDC_32                    TARG_ReadBit(PLCDC3, BIT2)
#define Iodd_RREG_LCDC_33                    TARG_ReadBit(PLCDC3, BIT3)
#define Iodd_RREG_LCDC_34                    TARG_ReadBit(PLCDC3, BIT4)
#define Iodd_RREG_LCDC_35                    TARG_ReadBit(PLCDC3, BIT5)
#define Iodd_RREG_LCDC_36                    TARG_ReadBit(PLCDC3, BIT6)
#define Iodd_RREG_LCDC_37                    TARG_ReadBit(PLCDC3, BIT7)

#define Iodd_WREG_LCDC_30(Value)             /* write access not defined */
#define Iodd_WREG_LCDC_31(Value)             /* write access not defined */
#define Iodd_WREG_LCDC_32(Value)             TARG_WriteBit(PLCDC3, BIT2, Value)
#define Iodd_WREG_LCDC_33(Value)             TARG_WriteBit(PLCDC3, BIT3, Value)
#define Iodd_WREG_LCDC_34(Value)             TARG_WriteBit(PLCDC3, BIT4, Value)
#define Iodd_WREG_LCDC_35(Value)             TARG_WriteBit(PLCDC3, BIT5, Value)
#define Iodd_WREG_LCDC_36(Value)             TARG_WriteBit(PLCDC3, BIT6, Value)
#define Iodd_WREG_LCDC_37(Value)             TARG_WriteBit(PLCDC3, BIT7, Value)

#endif /* defined(__NEC_V850_DG3__) || defined(__NEC_V850_DJ3_LE__) */

#if                                          \
      defined(__NEC_V850_DL3__)||            \
      defined(__NEC_V850_DJ3_HE__)

#define Iodd_RREG_LCDC_30                    /* register undefined */
#define Iodd_RREG_LCDC_31                    /* register undefined */
#define Iodd_RREG_LCDC_32                    /* register undefined */
#define Iodd_RREG_LCDC_33                    /* register undefined */
#define Iodd_RREG_LCDC_34                    /* register undefined */
#define Iodd_RREG_LCDC_35                    /* register undefined */
#define Iodd_RREG_LCDC_36                    /* register undefined */
#define Iodd_RREG_LCDC_37                    /* register undefined */

#define Iodd_WREG_LCDC_30(Value)             /* register undefined */
#define Iodd_WREG_LCDC_31(Value)             /* register undefined */
#define Iodd_WREG_LCDC_32(Value)             /* register undefined */
#define Iodd_WREG_LCDC_33(Value)             /* register undefined */
#define Iodd_WREG_LCDC_34(Value)             /* register undefined */
#define Iodd_WREG_LCDC_35(Value)             /* register undefined */
#define Iodd_WREG_LCDC_36(Value)             /* register undefined */
#define Iodd_WREG_LCDC_37(Value)             /* register undefined */

#endif /* defined(__NEC_V850_DL3__) || defined(__NEC_V850_DJ3_HE__) */

#if                                          \
      defined(__NEC_V850_DJ3__)||            \
      defined(__NEC_V850_DL3__)

#define Iodd_RREG_ILC_30                     /* register undefined */
#define Iodd_RREG_ILC_31                     /* register undefined */
#define Iodd_RREG_ILC_32                     /* register undefined */
#define Iodd_RREG_ILC_33                     /* register undefined */
#define Iodd_RREG_ILC_34                     /* register undefined */
#define Iodd_RREG_ILC_35                     /* register undefined */
#define Iodd_RREG_ILC_36                     /* register undefined */
#define Iodd_RREG_ILC_37                     /* register undefined */
                                                                    
#define Iodd_WREG_ILC_30(Value)              /* register undefined */
#define Iodd_WREG_ILC_31(Value)              /* register undefined */
#define Iodd_WREG_ILC_32(Value)              /* register undefined */
#define Iodd_WREG_ILC_33(Value)              /* register undefined */
#define Iodd_WREG_ILC_34(Value)              /* register undefined */
#define Iodd_WREG_ILC_35(Value)              /* register undefined */
#define Iodd_WREG_ILC_36(Value)              /* register undefined */
#define Iodd_WREG_ILC_37(Value)              /* register undefined */

#endif /* defined(__NEC_V850_DJ3__) || defined(__NEC_V850_DL3__) */

#if                                          \
      defined(__NEC_V850_DG3__)

#define Iodd_RREG_ILC_30                     TARG_ReadBit(PILC3, BIT0)
#define Iodd_RREG_ILC_31                     TARG_ReadBit(PILC3, BIT1)
#define Iodd_RREG_ILC_32                     TARG_ReadBit(PILC3, BIT2)
#define Iodd_RREG_ILC_33                     TARG_ReadBit(PILC3, BIT3)
#define Iodd_RREG_ILC_34                     TARG_ReadBit(PILC3, BIT4)
#define Iodd_RREG_ILC_35                     TARG_ReadBit(PILC3, BIT5)
#define Iodd_RREG_ILC_36                     TARG_ReadBit(PILC3, BIT6)
#define Iodd_RREG_ILC_37                     TARG_ReadBit(PILC3, BIT7)

#define Iodd_WREG_ILC_30(Value)              TARG_WriteBit(PILC3, BIT0, Value)
#define Iodd_WREG_ILC_31(Value)              TARG_WriteBit(PILC3, BIT1, Value)
#define Iodd_WREG_ILC_32(Value)              TARG_WriteBit(PILC3, BIT2, Value)
#define Iodd_WREG_ILC_33(Value)              TARG_WriteBit(PILC3, BIT3, Value)
#define Iodd_WREG_ILC_34(Value)              TARG_WriteBit(PILC3, BIT4, Value)
#define Iodd_WREG_ILC_35(Value)              TARG_WriteBit(PILC3, BIT5, Value)
#define Iodd_WREG_ILC_36(Value)              TARG_WriteBit(PILC3, BIT6, Value)
#define Iodd_WREG_ILC_37(Value)              TARG_WriteBit(PILC3, BIT7, Value)

#endif /* defined(__NEC_V850_DG3__) */

#if                                          \
      defined(__NEC_V850_DJ3__)||            \
      defined(__NEC_V850_DL3__)

#define Iodd_RREG_RC_30                       /* register undefined */
#define Iodd_RREG_RC_31                       /* register undefined */
#define Iodd_RREG_RC_32                       /* register undefined */
#define Iodd_RREG_RC_33                       /* register undefined */
#define Iodd_RREG_RC_34                       /* register undefined */
#define Iodd_RREG_RC_35                       /* register undefined */
#define Iodd_RREG_RC_36                       /* register undefined */
#define Iodd_RREG_RC_37                       /* register undefined */
                                                                      
#define Iodd_WREG_RC_30(Value)                /* register undefined */
#define Iodd_WREG_RC_31(Value)                /* register undefined */
#define Iodd_WREG_RC_32(Value)                /* register undefined */
#define Iodd_WREG_RC_33(Value)                /* register undefined */
#define Iodd_WREG_RC_34(Value)                /* register undefined */
#define Iodd_WREG_RC_35(Value)                /* register undefined */
#define Iodd_WREG_RC_36(Value)                /* register undefined */
#define Iodd_WREG_RC_37(Value)                /* register undefined */

#endif /* defined(__NEC_V850_DJ3__) || defined(__NEC_V850_DL3__) */

#if                                          \
      defined(__NEC_V850_DG3__)

#define Iodd_RREG_RC_30                       TARG_ReadBit(PRC3, BIT0)
#define Iodd_RREG_RC_31                       /* read access defined but should not be used */
#define Iodd_RREG_RC_32                       /* read access defined but should not be used */
#define Iodd_RREG_RC_33                       /* read access defined but should not be used */
#define Iodd_RREG_RC_34                       /* read access defined but should not be used */
#define Iodd_RREG_RC_35                       /* read access defined but should not be used */
#define Iodd_RREG_RC_36                       /* read access defined but should not be used */
#define Iodd_RREG_RC_37                       /* read access defined but should not be used */

#define Iodd_WREG_RC_30(Value)                TARG_WriteBit(PRC3, BIT0, Value)
#define Iodd_WREG_RC_31(Value)                /* write access not defined */
#define Iodd_WREG_RC_32(Value)                /* write access not defined */
#define Iodd_WREG_RC_33(Value)                /* write access not defined */
#define Iodd_WREG_RC_34(Value)                /* write access not defined */
#define Iodd_WREG_RC_35(Value)                /* write access not defined */
#define Iodd_WREG_RC_36(Value)                /* write access not defined */
#define Iodd_WREG_RC_37(Value)                /* write access not defined */

#endif /* defined(__NEC_V850_DG3__) */

/* Definitions PORT 4 */

#if                                          \
      defined(__NEC_V850_DJ3__)||            \
      defined(__NEC_V850_DL3__)

#define Iodd_RREG_P_40                       TARG_ReadBit(P4, BIT0)
#define Iodd_RREG_P_41                       TARG_ReadBit(P4, BIT1)
#define Iodd_RREG_P_42                       TARG_ReadBit(P4, BIT2)
#define Iodd_RREG_P_43                       TARG_ReadBit(P4, BIT3)
#define Iodd_RREG_P_44                       TARG_ReadBit(P4, BIT4)
#define Iodd_RREG_P_45                       TARG_ReadBit(P4, BIT5)
#define Iodd_RREG_P_46                       TARG_ReadBit(P4, BIT6)
#define Iodd_RREG_P_47                       TARG_ReadBit(P4, BIT7)

#define Iodd_WREG_P_40(Value)                TARG_WriteBit(P4, BIT0, Value)
#define Iodd_WREG_P_41(Value)                TARG_WriteBit(P4, BIT1, Value)
#define Iodd_WREG_P_42(Value)                TARG_WriteBit(P4, BIT2, Value)
#define Iodd_WREG_P_43(Value)                TARG_WriteBit(P4, BIT3, Value)
#define Iodd_WREG_P_44(Value)                TARG_WriteBit(P4, BIT4, Value)
#define Iodd_WREG_P_45(Value)                TARG_WriteBit(P4, BIT5, Value)
#define Iodd_WREG_P_46(Value)                TARG_WriteBit(P4, BIT6, Value)
#define Iodd_WREG_P_47(Value)                TARG_WriteBit(P4, BIT7, Value)

#endif /* defined(__NEC_V850_DJ3__) || defined(__NEC_V850_DL3__) */

#if                                          \
      defined(__NEC_V850_DG3__)

#define Iodd_RREG_P_40                       /* read access defined but should not be used */
#define Iodd_RREG_P_41                       /* read access defined but should not be used */
#define Iodd_RREG_P_42                       /* read access defined but should not be used */
#define Iodd_RREG_P_43                       TARG_ReadBit(P4, BIT3)
#define Iodd_RREG_P_44                       TARG_ReadBit(P4, BIT4)
#define Iodd_RREG_P_45                       TARG_ReadBit(P4, BIT5)
#define Iodd_RREG_P_46                       TARG_ReadBit(P4, BIT6)
#define Iodd_RREG_P_47                       TARG_ReadBit(P4, BIT7)

#define Iodd_WREG_P_40(Value)                /* write access not defined */
#define Iodd_WREG_P_41(Value)                /* write access not defined */
#define Iodd_WREG_P_42(Value)                /* write access not defined */
#define Iodd_WREG_P_43(Value)                TARG_WriteBit(P4, BIT3, Value)
#define Iodd_WREG_P_44(Value)                TARG_WriteBit(P4, BIT4, Value)
#define Iodd_WREG_P_45(Value)                TARG_WriteBit(P4, BIT5, Value)
#define Iodd_WREG_P_46(Value)                TARG_WriteBit(P4, BIT6, Value)
#define Iodd_WREG_P_47(Value)                TARG_WriteBit(P4, BIT7, Value)

#endif /* defined(__NEC_V850_DG3__) */

#if                                          \
      defined(__NEC_V850_DJ3__)||            \
      defined(__NEC_V850_DL3__)

#define Iodd_RREG_M_40                       TARG_ReadBit(PM4, BIT0)
#define Iodd_RREG_M_41                       TARG_ReadBit(PM4, BIT1)
#define Iodd_RREG_M_42                       TARG_ReadBit(PM4, BIT2)
#define Iodd_RREG_M_43                       TARG_ReadBit(PM4, BIT3)
#define Iodd_RREG_M_44                       TARG_ReadBit(PM4, BIT4)
#define Iodd_RREG_M_45                       TARG_ReadBit(PM4, BIT5)
#define Iodd_RREG_M_46                       TARG_ReadBit(PM4, BIT6)
#define Iodd_RREG_M_47                       TARG_ReadBit(PM4, BIT7)

#define Iodd_WREG_M_40(Value)                TARG_WriteBit(PM4, BIT0, Value)
#define Iodd_WREG_M_41(Value)                TARG_WriteBit(PM4, BIT1, Value)
#define Iodd_WREG_M_42(Value)                TARG_WriteBit(PM4, BIT2, Value)
#define Iodd_WREG_M_43(Value)                TARG_WriteBit(PM4, BIT3, Value)
#define Iodd_WREG_M_44(Value)                TARG_WriteBit(PM4, BIT4, Value)
#define Iodd_WREG_M_45(Value)                TARG_WriteBit(PM4, BIT5, Value)
#define Iodd_WREG_M_46(Value)                TARG_WriteBit(PM4, BIT6, Value)
#define Iodd_WREG_M_47(Value)                TARG_WriteBit(PM4, BIT7, Value)

#endif /* defined(__NEC_V850_DJ3__) || defined(__NEC_V850_DL3__) */

#if                                          \
      defined(__NEC_V850_DG3__)

#define Iodd_RREG_M_40                       /* read access defined but should not be used */ 
#define Iodd_RREG_M_41                       /* read access defined but should not be used */ 
#define Iodd_RREG_M_42                       /* read access defined but should not be used */ 
#define Iodd_RREG_M_43                       TARG_ReadBit(PM4, BIT3)                           
#define Iodd_RREG_M_44                       TARG_ReadBit(PM4, BIT4)                           
#define Iodd_RREG_M_45                       TARG_ReadBit(PM4, BIT5)                           
#define Iodd_RREG_M_46                       TARG_ReadBit(PM4, BIT6)                           
#define Iodd_RREG_M_47                       TARG_ReadBit(PM4, BIT7)                           
                                                                                              
#define Iodd_WREG_M_40(Value)                /* write access not defined */
#define Iodd_WREG_M_41(Value)                /* write access not defined */
#define Iodd_WREG_M_42(Value)                /* write access not defined */
#define Iodd_WREG_M_43(Value)                TARG_WriteBit(PM4, BIT3, Value)                   
#define Iodd_WREG_M_44(Value)                TARG_WriteBit(PM4, BIT4, Value)                   
#define Iodd_WREG_M_45(Value)                TARG_WriteBit(PM4, BIT5, Value)                   
#define Iodd_WREG_M_46(Value)                TARG_WriteBit(PM4, BIT6, Value)                   
#define Iodd_WREG_M_47(Value)                TARG_WriteBit(PM4, BIT7, Value)                   

#endif /* defined(__NEC_V850_DG3__) */

#if                                          \
      defined(__NEC_V850_DJ3__)||            \
      defined(__NEC_V850_DL3__)

#define Iodd_RREG_MC_40                      TARG_ReadBit(PMC4, BIT0)
#define Iodd_RREG_MC_41                      TARG_ReadBit(PMC4, BIT1)
#define Iodd_RREG_MC_42                      TARG_ReadBit(PMC4, BIT2)
#define Iodd_RREG_MC_43                      TARG_ReadBit(PMC4, BIT3)
#define Iodd_RREG_MC_44                      TARG_ReadBit(PMC4, BIT4)
#define Iodd_RREG_MC_45                      TARG_ReadBit(PMC4, BIT5)
#define Iodd_RREG_MC_46                      TARG_ReadBit(PMC4, BIT6)
#define Iodd_RREG_MC_47                      TARG_ReadBit(PMC4, BIT7)

#define Iodd_WREG_MC_40(Value)               TARG_WriteBit(PMC4, BIT0, Value)
#define Iodd_WREG_MC_41(Value)               TARG_WriteBit(PMC4, BIT1, Value)
#define Iodd_WREG_MC_42(Value)               TARG_WriteBit(PMC4, BIT2, Value)
#define Iodd_WREG_MC_43(Value)               TARG_WriteBit(PMC4, BIT3, Value)
#define Iodd_WREG_MC_44(Value)               TARG_WriteBit(PMC4, BIT4, Value)
#define Iodd_WREG_MC_45(Value)               TARG_WriteBit(PMC4, BIT5, Value)
#define Iodd_WREG_MC_46(Value)               TARG_WriteBit(PMC4, BIT6, Value)
#define Iodd_WREG_MC_47(Value)               TARG_WriteBit(PMC4, BIT7, Value)

#endif /* defined(__NEC_V850_DJ3__) || defined(__NEC_V850_DL3__) */

#if                                          \
      defined(__NEC_V850_DG3__)

#define Iodd_RREG_MC_40                      /* read access defined but should not be used */        
#define Iodd_RREG_MC_41                      /* read access defined but should not be used */        
#define Iodd_RREG_MC_42                      /* read access defined but should not be used */        
#define Iodd_RREG_MC_43                      TARG_ReadBit(PMC4, BIT3)        
#define Iodd_RREG_MC_44                      TARG_ReadBit(PMC4, BIT4)        
#define Iodd_RREG_MC_45                      TARG_ReadBit(PMC4, BIT5)        
#define Iodd_RREG_MC_46                      TARG_ReadBit(PMC4, BIT6)        
#define Iodd_RREG_MC_47                      TARG_ReadBit(PMC4, BIT7)        
                                                                             
#define Iodd_WREG_MC_40(Value)               /* write access not defined */
#define Iodd_WREG_MC_41(Value)               /* write access not defined */
#define Iodd_WREG_MC_42(Value)               /* write access not defined */
#define Iodd_WREG_MC_43(Value)               TARG_WriteBit(PMC4, BIT3, Value)
#define Iodd_WREG_MC_44(Value)               TARG_WriteBit(PMC4, BIT4, Value)
#define Iodd_WREG_MC_45(Value)               TARG_WriteBit(PMC4, BIT5, Value)
#define Iodd_WREG_MC_46(Value)               TARG_WriteBit(PMC4, BIT6, Value)
#define Iodd_WREG_MC_47(Value)               TARG_WriteBit(PMC4, BIT7, Value)

#endif /* defined(__NEC_V850_DG3__) */

#if                                          \
      defined(__NEC_V850_DJ3__)||            \
      defined(__NEC_V850_DL3__)

#define Iodd_RREG_DSC_40                     TARG_ReadBit(PDSC4, BIT0)
#define Iodd_RREG_DSC_41                     TARG_ReadBit(PDSC4, BIT1)
#define Iodd_RREG_DSC_42                     TARG_ReadBit(PDSC4, BIT2)
#define Iodd_RREG_DSC_43                     TARG_ReadBit(PDSC4, BIT3)
#define Iodd_RREG_DSC_44                     TARG_ReadBit(PDSC4, BIT4)
#define Iodd_RREG_DSC_45                     TARG_ReadBit(PDSC4, BIT5)
#define Iodd_RREG_DSC_46                     TARG_ReadBit(PDSC4, BIT6)
#define Iodd_RREG_DSC_47                     TARG_ReadBit(PDSC4, BIT7)

#define Iodd_WREG_DSC_40(Value)              TARG_WriteBit(PDSC4, BIT0, Value)
#define Iodd_WREG_DSC_41(Value)              TARG_WriteBit(PDSC4, BIT1, Value)
#define Iodd_WREG_DSC_42(Value)              TARG_WriteBit(PDSC4, BIT2, Value)
#define Iodd_WREG_DSC_43(Value)              TARG_WriteBit(PDSC4, BIT3, Value)
#define Iodd_WREG_DSC_44(Value)              TARG_WriteBit(PDSC4, BIT4, Value)
#define Iodd_WREG_DSC_45(Value)              TARG_WriteBit(PDSC4, BIT5, Value)
#define Iodd_WREG_DSC_46(Value)              TARG_WriteBit(PDSC4, BIT6, Value)
#define Iodd_WREG_DSC_47(Value)              TARG_WriteBit(PDSC4, BIT7, Value)

#endif /* defined(__NEC_V850_DJ3__) || defined(__NEC_V850_DL3__) */

#if                                          \
      defined(__NEC_V850_DG3__)

#define Iodd_RREG_DSC_40                     /* read access defined but should not be used */
#define Iodd_RREG_DSC_41                     /* read access defined but should not be used */
#define Iodd_RREG_DSC_42                     /* read access defined but should not be used */
#define Iodd_RREG_DSC_43                     TARG_ReadBit(PDSC4, BIT3)
#define Iodd_RREG_DSC_44                     TARG_ReadBit(PDSC4, BIT4)
#define Iodd_RREG_DSC_45                     TARG_ReadBit(PDSC4, BIT5)
#define Iodd_RREG_DSC_46                     TARG_ReadBit(PDSC4, BIT6)
#define Iodd_RREG_DSC_47                     TARG_ReadBit(PDSC4, BIT7)

#define Iodd_WREG_DSC_40(Value)              /* write access not defined */
#define Iodd_WREG_DSC_41(Value)              /* write access not defined */
#define Iodd_WREG_DSC_42(Value)              /* write access not defined */
#define Iodd_WREG_DSC_43(Value)              TARG_WriteBit(PDSC4, BIT3, Value)
#define Iodd_WREG_DSC_44(Value)              TARG_WriteBit(PDSC4, BIT4, Value)
#define Iodd_WREG_DSC_45(Value)              TARG_WriteBit(PDSC4, BIT5, Value)
#define Iodd_WREG_DSC_46(Value)              TARG_WriteBit(PDSC4, BIT6, Value)
#define Iodd_WREG_DSC_47(Value)              TARG_WriteBit(PDSC4, BIT7, Value)

#endif /* defined(__NEC_V850_DG3__) */

#if                                          \
      defined(__NEC_V850_DJ3__)||            \
      defined(__NEC_V850_DL3__)

#define Iodd_RREG_ICC_40                     TARG_ReadBit(PICC4, BIT0)
#define Iodd_RREG_ICC_41                     TARG_ReadBit(PICC4, BIT1)
#define Iodd_RREG_ICC_42                     TARG_ReadBit(PICC4, BIT2)
#define Iodd_RREG_ICC_43                     TARG_ReadBit(PICC4, BIT3)
#define Iodd_RREG_ICC_44                     TARG_ReadBit(PICC4, BIT4)
#define Iodd_RREG_ICC_45                     TARG_ReadBit(PICC4, BIT5)
#define Iodd_RREG_ICC_46                     TARG_ReadBit(PICC4, BIT6)
#define Iodd_RREG_ICC_47                     TARG_ReadBit(PICC4, BIT7)

#define Iodd_WREG_ICC_40(Value)              TARG_WriteBit(PICC4, BIT0, Value)
#define Iodd_WREG_ICC_41(Value)              TARG_WriteBit(PICC4, BIT1, Value)
#define Iodd_WREG_ICC_42(Value)              TARG_WriteBit(PICC4, BIT2, Value)
#define Iodd_WREG_ICC_43(Value)              TARG_WriteBit(PICC4, BIT3, Value)
#define Iodd_WREG_ICC_44(Value)              TARG_WriteBit(PICC4, BIT4, Value)
#define Iodd_WREG_ICC_45(Value)              TARG_WriteBit(PICC4, BIT5, Value)
#define Iodd_WREG_ICC_46(Value)              TARG_WriteBit(PICC4, BIT6, Value)
#define Iodd_WREG_ICC_47(Value)              TARG_WriteBit(PICC4, BIT7, Value)

#endif /* defined(__NEC_V850_DJ3__) || defined(__NEC_V850_DL3__) */

#if                                          \
      defined(__NEC_V850_DG3__)

#define Iodd_RREG_ICC_40                     /* read access defined but should not be used */
#define Iodd_RREG_ICC_41                     /* read access defined but should not be used */
#define Iodd_RREG_ICC_42                     /* read access defined but should not be used */
#define Iodd_RREG_ICC_43                     TARG_ReadBit(PICC4, BIT3)
#define Iodd_RREG_ICC_44                     TARG_ReadBit(PICC4, BIT4)
#define Iodd_RREG_ICC_45                     TARG_ReadBit(PICC4, BIT5)
#define Iodd_RREG_ICC_46                     TARG_ReadBit(PICC4, BIT6)
#define Iodd_RREG_ICC_47                     TARG_ReadBit(PICC4, BIT7)

#define Iodd_WREG_ICC_40(Value)              /* write access not defined */
#define Iodd_WREG_ICC_41(Value)              /* write access not defined */
#define Iodd_WREG_ICC_42(Value)              /* write access not defined */
#define Iodd_WREG_ICC_43(Value)              TARG_WriteBit(PICC4, BIT3, Value)
#define Iodd_WREG_ICC_44(Value)              TARG_WriteBit(PICC4, BIT4, Value)
#define Iodd_WREG_ICC_45(Value)              TARG_WriteBit(PICC4, BIT5, Value)
#define Iodd_WREG_ICC_46(Value)              TARG_WriteBit(PICC4, BIT6, Value)
#define Iodd_WREG_ICC_47(Value)              TARG_WriteBit(PICC4, BIT7, Value)

#endif /* defined(__NEC_V850_DG3__) */

#if                                          \
      defined(__NEC_V850_DJ3__)||            \
      defined(__NEC_V850_DL3__)

#define Iodd_RREG_ODC_40                     TARG_ReadBit(PODC4, BIT0)
#define Iodd_RREG_ODC_41                     TARG_ReadBit(PODC4, BIT1)
#define Iodd_RREG_ODC_42                     TARG_ReadBit(PODC4, BIT2)
#define Iodd_RREG_ODC_43                     TARG_ReadBit(PODC4, BIT3)
#define Iodd_RREG_ODC_44                     TARG_ReadBit(PODC4, BIT4)
#define Iodd_RREG_ODC_45                     TARG_ReadBit(PODC4, BIT5)
#define Iodd_RREG_ODC_46                     TARG_ReadBit(PODC4, BIT6)
#define Iodd_RREG_ODC_47                     TARG_ReadBit(PODC4, BIT7)

#define Iodd_WREG_ODC_40(Value)              TARG_WriteBit(PODC4, BIT0, Value)
#define Iodd_WREG_ODC_41(Value)              TARG_WriteBit(PODC4, BIT1, Value)
#define Iodd_WREG_ODC_42(Value)              TARG_WriteBit(PODC4, BIT2, Value)
#define Iodd_WREG_ODC_43(Value)              TARG_WriteBit(PODC4, BIT3, Value)
#define Iodd_WREG_ODC_44(Value)              TARG_WriteBit(PODC4, BIT4, Value)
#define Iodd_WREG_ODC_45(Value)              TARG_WriteBit(PODC4, BIT5, Value)
#define Iodd_WREG_ODC_46(Value)              TARG_WriteBit(PODC4, BIT6, Value)
#define Iodd_WREG_ODC_47(Value)              TARG_WriteBit(PODC4, BIT7, Value)

#endif /* defined(__NEC_V850_DJ3__) || defined(__NEC_V850_DL3__) */

#if                                          \
      defined(__NEC_V850_DG3__)

#define Iodd_RREG_ODC_40                     /* read access defined but should not be used */
#define Iodd_RREG_ODC_41                     /* read access defined but should not be used */
#define Iodd_RREG_ODC_42                     /* read access defined but should not be used */
#define Iodd_RREG_ODC_43                     TARG_ReadBit(PODC4, BIT3)
#define Iodd_RREG_ODC_44                     TARG_ReadBit(PODC4, BIT4)
#define Iodd_RREG_ODC_45                     TARG_ReadBit(PODC4, BIT5)
#define Iodd_RREG_ODC_46                     TARG_ReadBit(PODC4, BIT6)
#define Iodd_RREG_ODC_47                     TARG_ReadBit(PODC4, BIT7)

#define Iodd_WREG_ODC_40(Value)              /* write access not defined */
#define Iodd_WREG_ODC_41(Value)              /* write access not defined */
#define Iodd_WREG_ODC_42(Value)              /* write access not defined */
#define Iodd_WREG_ODC_43(Value)              TARG_WriteBit(PODC4, BIT3, Value)
#define Iodd_WREG_ODC_44(Value)              TARG_WriteBit(PODC4, BIT4, Value)
#define Iodd_WREG_ODC_45(Value)              TARG_WriteBit(PODC4, BIT5, Value)
#define Iodd_WREG_ODC_46(Value)              TARG_WriteBit(PODC4, BIT6, Value)
#define Iodd_WREG_ODC_47(Value)              TARG_WriteBit(PODC4, BIT7, Value)

#endif /* defined(__NEC_V850_DG3__) */

#if                                          \
      defined(__NEC_V850_DJ3__)||            \
      defined(__NEC_V850_DL3__)

#define Iodd_RREG_PR_40                      TARG_ReadBit(PPR4, BIT0)
#define Iodd_RREG_PR_41                      TARG_ReadBit(PPR4, BIT1)
#define Iodd_RREG_PR_42                      TARG_ReadBit(PPR4, BIT2)
#define Iodd_RREG_PR_43                      TARG_ReadBit(PPR4, BIT3)
#define Iodd_RREG_PR_44                      TARG_ReadBit(PPR4, BIT4)
#define Iodd_RREG_PR_45                      TARG_ReadBit(PPR4, BIT5)
#define Iodd_RREG_PR_46                      TARG_ReadBit(PPR4, BIT6)
#define Iodd_RREG_PR_47                      TARG_ReadBit(PPR4, BIT7)

#define Iodd_WREG_PR_40(Value)               /* write access not defined */
#define Iodd_WREG_PR_41(Value)               /* write access not defined */
#define Iodd_WREG_PR_42(Value)               /* write access not defined */
#define Iodd_WREG_PR_43(Value)               /* write access not defined */
#define Iodd_WREG_PR_44(Value)               /* write access not defined */
#define Iodd_WREG_PR_45(Value)               /* write access not defined */
#define Iodd_WREG_PR_46(Value)               /* write access not defined */
#define Iodd_WREG_PR_47(Value)               /* write access not defined */

#endif /* defined(__NEC_V850_DJ3__) || defined(__NEC_V850_DL3__) */

#if                                          \
      defined(__NEC_V850_DG3__)

#define Iodd_RREG_PR_40                      /* read access defined but should not be used */
#define Iodd_RREG_PR_41                      /* read access defined but should not be used */
#define Iodd_RREG_PR_42                      /* read access defined but should not be used */
#define Iodd_RREG_PR_43                      TARG_ReadBit(PPR4, BIT3)
#define Iodd_RREG_PR_44                      TARG_ReadBit(PPR4, BIT4)
#define Iodd_RREG_PR_45                      TARG_ReadBit(PPR4, BIT5)
#define Iodd_RREG_PR_46                      TARG_ReadBit(PPR4, BIT6)
#define Iodd_RREG_PR_47                      TARG_ReadBit(PPR4, BIT7)

#define Iodd_WREG_PR_40(Value)               /* write access not defined */
#define Iodd_WREG_PR_41(Value)               /* write access not defined */
#define Iodd_WREG_PR_42(Value)               /* write access not defined */
#define Iodd_WREG_PR_43(Value)               /* write access not defined */
#define Iodd_WREG_PR_44(Value)               /* write access not defined */
#define Iodd_WREG_PR_45(Value)               /* write access not defined */
#define Iodd_WREG_PR_46(Value)               /* write access not defined */
#define Iodd_WREG_PR_47(Value)               /* write access not defined */

#endif /* defined(__NEC_V850_DG3__) */

#if                                          \
      defined(__NEC_V850_DG3__)||            \
      defined(__NEC_V850_DJ3_LE__)

#define Iodd_RREG_LCDC_40                    TARG_ReadBit(PLCDC4, BIT0)
#define Iodd_RREG_LCDC_41                    TARG_ReadBit(PLCDC4, BIT1)
#define Iodd_RREG_LCDC_42                    TARG_ReadBit(PLCDC4, BIT2)
#define Iodd_RREG_LCDC_43                    TARG_ReadBit(PLCDC4, BIT3)
#define Iodd_RREG_LCDC_44                    TARG_ReadBit(PLCDC4, BIT4)
#define Iodd_RREG_LCDC_45                    TARG_ReadBit(PLCDC4, BIT5)
#define Iodd_RREG_LCDC_46                    TARG_ReadBit(PLCDC4, BIT6)
#define Iodd_RREG_LCDC_47                    TARG_ReadBit(PLCDC4, BIT7)

#define Iodd_WREG_LCDC_40(Value)             /* write access not defined */
#define Iodd_WREG_LCDC_41(Value)             /* write access not defined */
#define Iodd_WREG_LCDC_42(Value)             /* write access not defined */
#define Iodd_WREG_LCDC_43(Value)             TARG_WriteBit(PLCDC4, BIT3, Value)
#define Iodd_WREG_LCDC_44(Value)             TARG_WriteBit(PLCDC4, BIT4, Value)
#define Iodd_WREG_LCDC_45(Value)             TARG_WriteBit(PLCDC4, BIT5, Value)
#define Iodd_WREG_LCDC_46(Value)             /* write access not defined */
#define Iodd_WREG_LCDC_47(Value)             /* write access not defined */

#endif /* defined(__NEC_V850_DG3__) || defined(__NEC_V850_DJ3_LE__) */

#if                                          \
      defined(__NEC_V850_DL3__)||            \
      defined(__NEC_V850_DJ3_HE__)

#define Iodd_RREG_LCDC_40                    /* register undefined */
#define Iodd_RREG_LCDC_41                    /* register undefined */
#define Iodd_RREG_LCDC_42                    /* register undefined */
#define Iodd_RREG_LCDC_43                    /* register undefined */
#define Iodd_RREG_LCDC_44                    /* register undefined */
#define Iodd_RREG_LCDC_45                    /* register undefined */
#define Iodd_RREG_LCDC_46                    /* register undefined */
#define Iodd_RREG_LCDC_47                    /* register undefined */

#define Iodd_WREG_LCDC_40(Value)             /* register undefined */
#define Iodd_WREG_LCDC_41(Value)             /* register undefined */
#define Iodd_WREG_LCDC_42(Value)             /* register undefined */
#define Iodd_WREG_LCDC_43(Value)             /* register undefined */
#define Iodd_WREG_LCDC_44(Value)             /* register undefined */
#define Iodd_WREG_LCDC_45(Value)             /* register undefined */
#define Iodd_WREG_LCDC_46(Value)             /* register undefined */
#define Iodd_WREG_LCDC_47(Value)             /* register undefined */

#endif /* defined(__NEC_V850_DL3__) || defined(__NEC_V850_DJ3_HE__) */

#if                                          \
      defined(__NEC_V850_DJ3__)||            \
      defined(__NEC_V850_DL3__)

#define Iodd_RREG_ILC_40                     /* register undefined */
#define Iodd_RREG_ILC_41                     /* register undefined */
#define Iodd_RREG_ILC_42                     /* register undefined */
#define Iodd_RREG_ILC_43                     /* register undefined */
#define Iodd_RREG_ILC_44                     /* register undefined */
#define Iodd_RREG_ILC_45                     /* register undefined */
#define Iodd_RREG_ILC_46                     /* register undefined */
#define Iodd_RREG_ILC_47                     /* register undefined */
                                                                    
#define Iodd_WREG_ILC_40(Value)              /* register undefined */
#define Iodd_WREG_ILC_41(Value)              /* register undefined */
#define Iodd_WREG_ILC_42(Value)              /* register undefined */
#define Iodd_WREG_ILC_43(Value)              /* register undefined */
#define Iodd_WREG_ILC_44(Value)              /* register undefined */
#define Iodd_WREG_ILC_45(Value)              /* register undefined */
#define Iodd_WREG_ILC_46(Value)              /* register undefined */
#define Iodd_WREG_ILC_47(Value)              /* register undefined */

#endif /* defined(__NEC_V850_DJ3__) || defined(__NEC_V850_DL3__) */

#if                                          \
      defined(__NEC_V850_DG3__)

#define Iodd_RREG_ILC_40                     /* read access defined but should not be used */
#define Iodd_RREG_ILC_41                     /* read access defined but should not be used */
#define Iodd_RREG_ILC_42                     /* read access defined but should not be used */
#define Iodd_RREG_ILC_43                     TARG_ReadBit(PILC4, BIT3)
#define Iodd_RREG_ILC_44                     TARG_ReadBit(PILC4, BIT4)
#define Iodd_RREG_ILC_45                     TARG_ReadBit(PILC4, BIT5)
#define Iodd_RREG_ILC_46                     TARG_ReadBit(PILC4, BIT6)
#define Iodd_RREG_ILC_47                     TARG_ReadBit(PILC4, BIT7)

#define Iodd_WREG_ILC_40(Value)              /* write access not defined */
#define Iodd_WREG_ILC_41(Value)              /* write access not defined */
#define Iodd_WREG_ILC_42(Value)              /* write access not defined */
#define Iodd_WREG_ILC_43(Value)              TARG_WriteBit(PILC4, BIT3, Value)
#define Iodd_WREG_ILC_44(Value)              TARG_WriteBit(PILC4, BIT4, Value)
#define Iodd_WREG_ILC_45(Value)              TARG_WriteBit(PILC4, BIT5, Value)
#define Iodd_WREG_ILC_46(Value)              TARG_WriteBit(PILC4, BIT6, Value)
#define Iodd_WREG_ILC_47(Value)              TARG_WriteBit(PILC4, BIT7, Value)

#endif /* defined(__NEC_V850_DG3__) */

#if                                          \
      defined(__NEC_V850_Dx3__)

#define Iodd_RREG_FC_40                      /* register undefined */
#define Iodd_RREG_FC_41                      /* register undefined */
#define Iodd_RREG_FC_42                      /* register undefined */
#define Iodd_RREG_FC_43                      /* register undefined */
#define Iodd_RREG_FC_44                      /* register undefined */
#define Iodd_RREG_FC_45                      /* register undefined */
#define Iodd_RREG_FC_46                      /* register undefined */
#define Iodd_RREG_FC_47                      /* register undefined */

#define Iodd_WREG_FC_40(Value)               /* register undefined */
#define Iodd_WREG_FC_41(Value)               /* register undefined */
#define Iodd_WREG_FC_42(Value)               /* register undefined */
#define Iodd_WREG_FC_43(Value)               /* register undefined */
#define Iodd_WREG_FC_44(Value)               /* register undefined */
#define Iodd_WREG_FC_45(Value)               /* register undefined */
#define Iodd_WREG_FC_46(Value)               /* register undefined */
#define Iodd_WREG_FC_47(Value)               /* register undefined */

#endif

#if                                          \
      defined(__NEC_V850_DJ3__)||            \
      defined(__NEC_V850_DL3__)

#define Iodd_RREG_RC_40                       /* register undefined */
#define Iodd_RREG_RC_41                       /* register undefined */
#define Iodd_RREG_RC_42                       /* register undefined */
#define Iodd_RREG_RC_43                       /* register undefined */
#define Iodd_RREG_RC_44                       /* register undefined */
#define Iodd_RREG_RC_45                       /* register undefined */
#define Iodd_RREG_RC_46                       /* register undefined */
#define Iodd_RREG_RC_47                       /* register undefined */
                                                                      
#define Iodd_WREG_RC_40(Value)                /* register undefined */
#define Iodd_WREG_RC_41(Value)                /* register undefined */
#define Iodd_WREG_RC_42(Value)                /* register undefined */
#define Iodd_WREG_RC_43(Value)                /* register undefined */
#define Iodd_WREG_RC_44(Value)                /* register undefined */
#define Iodd_WREG_RC_45(Value)                /* register undefined */
#define Iodd_WREG_RC_46(Value)                /* register undefined */
#define Iodd_WREG_RC_47(Value)                /* register undefined */

#endif /* defined(__NEC_V850_DJ3__) || defined(__NEC_V850_DL3__) */

#if                                          \
      defined(__NEC_V850_DG3__)

#define Iodd_RREG_RC_40                       TARG_ReadBit(PRC4, BIT0)
#define Iodd_RREG_RC_41                       /* read access defined but should not be used */
#define Iodd_RREG_RC_42                       /* read access defined but should not be used */
#define Iodd_RREG_RC_43                       /* read access defined but should not be used */
#define Iodd_RREG_RC_44                       /* read access defined but should not be used */
#define Iodd_RREG_RC_45                       /* read access defined but should not be used */
#define Iodd_RREG_RC_46                       /* read access defined but should not be used */
#define Iodd_RREG_RC_47                       /* read access defined but should not be used */

#define Iodd_WREG_RC_40(Value)                TARG_WriteBit(PRC4, BIT0, Value)
#define Iodd_WREG_RC_41(Value)                /* write access not defined */
#define Iodd_WREG_RC_42(Value)                /* write access not defined */
#define Iodd_WREG_RC_43(Value)                /* write access not defined */
#define Iodd_WREG_RC_44(Value)                /* write access not defined */
#define Iodd_WREG_RC_45(Value)                /* write access not defined */
#define Iodd_WREG_RC_46(Value)                /* write access not defined */
#define Iodd_WREG_RC_47(Value)                /* write access not defined */

#endif /* defined(__NEC_V850_DG3__) */

/* Definitions PORT 5 */

#if                                          \
      defined(__NEC_V850_DJ3__)||            \
      defined(__NEC_V850_DL3__)

#define Iodd_RREG_P_50                       TARG_ReadBit(P5, BIT0)
#define Iodd_RREG_P_51                       TARG_ReadBit(P5, BIT1)
#define Iodd_RREG_P_52                       TARG_ReadBit(P5, BIT2)
#define Iodd_RREG_P_53                       TARG_ReadBit(P5, BIT3)
#define Iodd_RREG_P_54                       TARG_ReadBit(P5, BIT4)
#define Iodd_RREG_P_55                       TARG_ReadBit(P5, BIT5)
#define Iodd_RREG_P_56                       TARG_ReadBit(P5, BIT6)
#define Iodd_RREG_P_57                       TARG_ReadBit(P5, BIT7)

#define Iodd_WREG_P_50(Value)                TARG_WriteBit(P5, BIT0, Value)
#define Iodd_WREG_P_51(Value)                TARG_WriteBit(P5, BIT1, Value)
#define Iodd_WREG_P_52(Value)                TARG_WriteBit(P5, BIT2, Value)
#define Iodd_WREG_P_53(Value)                TARG_WriteBit(P5, BIT3, Value)
#define Iodd_WREG_P_54(Value)                TARG_WriteBit(P5, BIT4, Value)
#define Iodd_WREG_P_55(Value)                TARG_WriteBit(P5, BIT5, Value)
#define Iodd_WREG_P_56(Value)                TARG_WriteBit(P5, BIT6, Value)
#define Iodd_WREG_P_57(Value)                TARG_WriteBit(P5, BIT7, Value)

#endif /* defined(__NEC_V850_DJ3__) || defined(__NEC_V850_DL3__) */

#if                                          \
      defined(__NEC_V850_DG3__)

#define Iodd_RREG_P_50                       TARG_ReadBit(P5, BIT0)
#define Iodd_RREG_P_51                       TARG_ReadBit(P5, BIT1)
#define Iodd_RREG_P_52                       /* read access defined but should not be used */
#define Iodd_RREG_P_53                       /* read access defined but should not be used */
#define Iodd_RREG_P_54                       /* read access defined but should not be used */
#define Iodd_RREG_P_55                       /* read access defined but should not be used */
#define Iodd_RREG_P_56                       /* read access defined but should not be used */
#define Iodd_RREG_P_57                       /* read access defined but should not be used */

#define Iodd_WREG_P_50(Value)                TARG_WriteBit(P5, BIT0, Value)
#define Iodd_WREG_P_51(Value)                TARG_WriteBit(P5, BIT1, Value)
#define Iodd_WREG_P_52(Value)                /* write access not defined */
#define Iodd_WREG_P_53(Value)                /* write access not defined */
#define Iodd_WREG_P_54(Value)                /* write access not defined */
#define Iodd_WREG_P_55(Value)                /* write access not defined */
#define Iodd_WREG_P_56(Value)                /* write access not defined */
#define Iodd_WREG_P_57(Value)                /* write access not defined */

#endif /* defined(__NEC_V850_DG3__) */

#if                                          \
      defined(__NEC_V850_DJ3__)||            \
      defined(__NEC_V850_DL3__)

#define Iodd_RREG_M_50                       TARG_ReadBit(PM5, BIT0)
#define Iodd_RREG_M_51                       TARG_ReadBit(PM5, BIT1)
#define Iodd_RREG_M_52                       TARG_ReadBit(PM5, BIT2)
#define Iodd_RREG_M_53                       TARG_ReadBit(PM5, BIT3)
#define Iodd_RREG_M_54                       TARG_ReadBit(PM5, BIT4)
#define Iodd_RREG_M_55                       TARG_ReadBit(PM5, BIT5)
#define Iodd_RREG_M_56                       TARG_ReadBit(PM5, BIT6)
#define Iodd_RREG_M_57                       TARG_ReadBit(PM5, BIT7)

#define Iodd_WREG_M_50(Value)                TARG_WriteBit(PM5, BIT0, Value)
#define Iodd_WREG_M_51(Value)                TARG_WriteBit(PM5, BIT1, Value)
#define Iodd_WREG_M_52(Value)                TARG_WriteBit(PM5, BIT2, Value)
#define Iodd_WREG_M_53(Value)                TARG_WriteBit(PM5, BIT3, Value)
#define Iodd_WREG_M_54(Value)                TARG_WriteBit(PM5, BIT4, Value)
#define Iodd_WREG_M_55(Value)                TARG_WriteBit(PM5, BIT5, Value)
#define Iodd_WREG_M_56(Value)                TARG_WriteBit(PM5, BIT6, Value)
#define Iodd_WREG_M_57(Value)                TARG_WriteBit(PM5, BIT7, Value)

#endif /* defined(__NEC_V850_DJ3__) || defined(__NEC_V850_DL3__) */

#if                                          \
      defined(__NEC_V850_DG3__)

#define Iodd_RREG_M_50                       TARG_ReadBit(PM5, BIT0)
#define Iodd_RREG_M_51                       TARG_ReadBit(PM5, BIT1)
#define Iodd_RREG_M_52                       /* read access defined but should not be used */
#define Iodd_RREG_M_53                       /* read access defined but should not be used */
#define Iodd_RREG_M_54                       /* read access defined but should not be used */
#define Iodd_RREG_M_55                       /* read access defined but should not be used */
#define Iodd_RREG_M_56                       /* read access defined but should not be used */
#define Iodd_RREG_M_57                       /* read access defined but should not be used */

#define Iodd_WREG_M_50(Value)                TARG_WriteBit(PM5, BIT0, Value)
#define Iodd_WREG_M_51(Value)                TARG_WriteBit(PM5, BIT1, Value)
#define Iodd_WREG_M_52(Value)                /* write access not defined */
#define Iodd_WREG_M_53(Value)                /* write access not defined */
#define Iodd_WREG_M_54(Value)                /* write access not defined */
#define Iodd_WREG_M_55(Value)                /* write access not defined */
#define Iodd_WREG_M_56(Value)                /* write access not defined */
#define Iodd_WREG_M_57(Value)                /* write access not defined */

#endif /* defined(__NEC_V850_DG3__) */

#if                                          \
      defined(__NEC_V850_DJ3__)||            \
      defined(__NEC_V850_DL3__)

#define Iodd_RREG_MC_50                      TARG_ReadBit(PMC5, BIT0)
#define Iodd_RREG_MC_51                      TARG_ReadBit(PMC5, BIT1)
#define Iodd_RREG_MC_52                      /* read access defined but should not be used */
#define Iodd_RREG_MC_53                      /* read access defined but should not be used */
#define Iodd_RREG_MC_54                      /* read access defined but should not be used */
#define Iodd_RREG_MC_55                      /* read access defined but should not be used */
#define Iodd_RREG_MC_56                      TARG_ReadBit(PMC5, BIT6)
#define Iodd_RREG_MC_57                      TARG_ReadBit(PMC5, BIT7)

#define Iodd_WREG_MC_50(Value)               TARG_WriteBit(PMC5, BIT0, Value)
#define Iodd_WREG_MC_51(Value)               TARG_WriteBit(PMC5, BIT1, Value)
#define Iodd_WREG_MC_52(Value)               /* write access not defined */
#define Iodd_WREG_MC_53(Value)               /* write access not defined */
#define Iodd_WREG_MC_54(Value)               /* write access not defined */
#define Iodd_WREG_MC_55(Value)               /* write access not defined */
#define Iodd_WREG_MC_56(Value)               TARG_WriteBit(PMC5, BIT6, Value)
#define Iodd_WREG_MC_57(Value)               TARG_WriteBit(PMC5, BIT7, Value)

#endif /* defined(__NEC_V850_DJ3__) || defined(__NEC_V850_DL3__) */

#if                                          \
      defined(__NEC_V850_DG3__)

#define Iodd_RREG_MC_50                      TARG_ReadBit(PMC5, BIT0)
#define Iodd_RREG_MC_51                      TARG_ReadBit(PMC5, BIT1)
#define Iodd_RREG_MC_52                      /* read access defined but should not be used */
#define Iodd_RREG_MC_53                      /* read access defined but should not be used */
#define Iodd_RREG_MC_54                      /* read access defined but should not be used */
#define Iodd_RREG_MC_55                      /* read access defined but should not be used */
#define Iodd_RREG_MC_56                      /* read access defined but should not be used */
#define Iodd_RREG_MC_57                      /* read access defined but should not be used */

#define Iodd_WREG_MC_50(Value)               TARG_WriteBit(PMC5, BIT0, Value)
#define Iodd_WREG_MC_51(Value)               TARG_WriteBit(PMC5, BIT1, Value)
#define Iodd_WREG_MC_52(Value)               /* write access not defined */
#define Iodd_WREG_MC_53(Value)               /* write access not defined */
#define Iodd_WREG_MC_54(Value)               /* write access not defined */
#define Iodd_WREG_MC_55(Value)               /* write access not defined */
#define Iodd_WREG_MC_56(Value)               /* write access not defined */
#define Iodd_WREG_MC_57(Value)               /* write access not defined */

#endif /* defined(__NEC_V850_DG3__) */

#if                                          \
      defined(__NEC_V850_DJ3__)||            \
      defined(__NEC_V850_DL3__)

#define Iodd_RREG_DSC_50                     TARG_ReadBit(PDSC5, BIT0)
#define Iodd_RREG_DSC_51                     TARG_ReadBit(PDSC5, BIT1)
#define Iodd_RREG_DSC_52                     TARG_ReadBit(PDSC5, BIT2)
#define Iodd_RREG_DSC_53                     TARG_ReadBit(PDSC5, BIT3)
#define Iodd_RREG_DSC_54                     TARG_ReadBit(PDSC5, BIT4)
#define Iodd_RREG_DSC_55                     TARG_ReadBit(PDSC5, BIT5)
#define Iodd_RREG_DSC_56                     TARG_ReadBit(PDSC5, BIT6)
#define Iodd_RREG_DSC_57                     TARG_ReadBit(PDSC5, BIT7)

#define Iodd_WREG_DSC_50(Value)              TARG_WriteBit(PDSC5, BIT0, Value)
#define Iodd_WREG_DSC_51(Value)              TARG_WriteBit(PDSC5, BIT1, Value)
#define Iodd_WREG_DSC_52(Value)              TARG_WriteBit(PDSC5, BIT2, Value)
#define Iodd_WREG_DSC_53(Value)              TARG_WriteBit(PDSC5, BIT3, Value)
#define Iodd_WREG_DSC_54(Value)              TARG_WriteBit(PDSC5, BIT4, Value)
#define Iodd_WREG_DSC_55(Value)              TARG_WriteBit(PDSC5, BIT5, Value)
#define Iodd_WREG_DSC_56(Value)              TARG_WriteBit(PDSC5, BIT6, Value)
#define Iodd_WREG_DSC_57(Value)              TARG_WriteBit(PDSC5, BIT7, Value)

#endif /* defined(__NEC_V850_DJ3__) || defined(__NEC_V850_DL3__) */

#if                                          \
      defined(__NEC_V850_DG3__)

#define Iodd_RREG_DSC_50                     TARG_ReadBit(PDSC5, BIT0)
#define Iodd_RREG_DSC_51                     TARG_ReadBit(PDSC5, BIT1)
#define Iodd_RREG_DSC_52                     /* read access defined but should not be used */
#define Iodd_RREG_DSC_53                     /* read access defined but should not be used */
#define Iodd_RREG_DSC_54                     /* read access defined but should not be used */
#define Iodd_RREG_DSC_55                     /* read access defined but should not be used */
#define Iodd_RREG_DSC_56                     /* read access defined but should not be used */
#define Iodd_RREG_DSC_57                     /* read access defined but should not be used */

#define Iodd_WREG_DSC_50(Value)              TARG_WriteBit(PDSC5, BIT0, Value)
#define Iodd_WREG_DSC_51(Value)              TARG_WriteBit(PDSC5, BIT1, Value)
#define Iodd_WREG_DSC_52(Value)              /* write access not defined */
#define Iodd_WREG_DSC_53(Value)              /* write access not defined */
#define Iodd_WREG_DSC_54(Value)              /* write access not defined */
#define Iodd_WREG_DSC_55(Value)              /* write access not defined */
#define Iodd_WREG_DSC_56(Value)              /* write access not defined */
#define Iodd_WREG_DSC_57(Value)              /* write access not defined */

#endif /* defined(__NEC_V850_DG3__) */

#if                                          \
      defined(__NEC_V850_DJ3__)||            \
      defined(__NEC_V850_DL3__)

#define Iodd_RREG_ICC_50                     TARG_ReadBit(PICC5, BIT0)
#define Iodd_RREG_ICC_51                     TARG_ReadBit(PICC5, BIT1)
#define Iodd_RREG_ICC_52                     TARG_ReadBit(PICC5, BIT2)
#define Iodd_RREG_ICC_53                     TARG_ReadBit(PICC5, BIT3)
#define Iodd_RREG_ICC_54                     TARG_ReadBit(PICC5, BIT4)
#define Iodd_RREG_ICC_55                     TARG_ReadBit(PICC5, BIT5)
#define Iodd_RREG_ICC_56                     TARG_ReadBit(PICC5, BIT6)
#define Iodd_RREG_ICC_57                     TARG_ReadBit(PICC5, BIT7)

#define Iodd_WREG_ICC_50(Value)              TARG_WriteBit(PICC5, BIT0, Value)
#define Iodd_WREG_ICC_51(Value)              TARG_WriteBit(PICC5, BIT1, Value)
#define Iodd_WREG_ICC_52(Value)              TARG_WriteBit(PICC5, BIT2, Value)
#define Iodd_WREG_ICC_53(Value)              TARG_WriteBit(PICC5, BIT3, Value)
#define Iodd_WREG_ICC_54(Value)              TARG_WriteBit(PICC5, BIT4, Value)
#define Iodd_WREG_ICC_55(Value)              TARG_WriteBit(PICC5, BIT5, Value)
#define Iodd_WREG_ICC_56(Value)              TARG_WriteBit(PICC5, BIT6, Value)
#define Iodd_WREG_ICC_57(Value)              TARG_WriteBit(PICC5, BIT7, Value)

#endif /* defined(__NEC_V850_DJ3__) || defined(__NEC_V850_DL3__) */

#if                                          \
      defined(__NEC_V850_DG3__)

#define Iodd_RREG_ICC_50                     TARG_ReadBit(PICC5, BIT0)
#define Iodd_RREG_ICC_51                     TARG_ReadBit(PICC5, BIT1)
#define Iodd_RREG_ICC_52                     /* read access defined but should not be used */
#define Iodd_RREG_ICC_53                     /* read access defined but should not be used */
#define Iodd_RREG_ICC_54                     /* read access defined but should not be used */
#define Iodd_RREG_ICC_55                     /* read access defined but should not be used */
#define Iodd_RREG_ICC_56                     /* read access defined but should not be used */
#define Iodd_RREG_ICC_57                     /* read access defined but should not be used */

#define Iodd_WREG_ICC_50(Value)              TARG_WriteBit(PICC5, BIT0, Value)
#define Iodd_WREG_ICC_51(Value)              TARG_WriteBit(PICC5, BIT1, Value)
#define Iodd_WREG_ICC_52(Value)              /* write access not defined */
#define Iodd_WREG_ICC_53(Value)              /* write access not defined */
#define Iodd_WREG_ICC_54(Value)              /* write access not defined */
#define Iodd_WREG_ICC_55(Value)              /* write access not defined */
#define Iodd_WREG_ICC_56(Value)              /* write access not defined */
#define Iodd_WREG_ICC_57(Value)              /* write access not defined */

#endif /* defined(__NEC_V850_DG3__) */

#if                                          \
      defined(__NEC_V850_DJ3__)||            \
      defined(__NEC_V850_DL3__)

#define Iodd_RREG_ODC_50                     TARG_ReadBit(PODC5, BIT0)
#define Iodd_RREG_ODC_51                     TARG_ReadBit(PODC5, BIT1)
#define Iodd_RREG_ODC_52                     TARG_ReadBit(PODC5, BIT2)
#define Iodd_RREG_ODC_53                     TARG_ReadBit(PODC5, BIT3)
#define Iodd_RREG_ODC_54                     TARG_ReadBit(PODC5, BIT4)
#define Iodd_RREG_ODC_55                     TARG_ReadBit(PODC5, BIT5)
#define Iodd_RREG_ODC_56                     TARG_ReadBit(PODC5, BIT6)
#define Iodd_RREG_ODC_57                     TARG_ReadBit(PODC5, BIT7)

#define Iodd_WREG_ODC_50(Value)              TARG_WriteBit(PODC5, BIT0, Value)
#define Iodd_WREG_ODC_51(Value)              TARG_WriteBit(PODC5, BIT1, Value)
#define Iodd_WREG_ODC_52(Value)              TARG_WriteBit(PODC5, BIT2, Value)
#define Iodd_WREG_ODC_53(Value)              TARG_WriteBit(PODC5, BIT3, Value)
#define Iodd_WREG_ODC_54(Value)              TARG_WriteBit(PODC5, BIT4, Value)
#define Iodd_WREG_ODC_55(Value)              TARG_WriteBit(PODC5, BIT5, Value)
#define Iodd_WREG_ODC_56(Value)              TARG_WriteBit(PODC5, BIT6, Value)
#define Iodd_WREG_ODC_57(Value)              TARG_WriteBit(PODC5, BIT7, Value)

#endif /* defined(__NEC_V850_DJ3__) || defined(__NEC_V850_DL3__) */

#if                                          \
      defined(__NEC_V850_DG3__)

#define Iodd_RREG_ODC_50                     TARG_ReadBit(PODC5, BIT0)
#define Iodd_RREG_ODC_51                     TARG_ReadBit(PODC5, BIT1)
#define Iodd_RREG_ODC_52                     /* read access defined but should not be used */
#define Iodd_RREG_ODC_53                     /* read access defined but should not be used */
#define Iodd_RREG_ODC_54                     /* read access defined but should not be used */
#define Iodd_RREG_ODC_55                     /* read access defined but should not be used */
#define Iodd_RREG_ODC_56                     /* read access defined but should not be used */
#define Iodd_RREG_ODC_57                     /* read access defined but should not be used */

#define Iodd_WREG_ODC_50(Value)              TARG_WriteBit(PODC5, BIT0, Value)
#define Iodd_WREG_ODC_51(Value)              TARG_WriteBit(PODC5, BIT1, Value)
#define Iodd_WREG_ODC_52(Value)              /* write access not defined */
#define Iodd_WREG_ODC_53(Value)              /* write access not defined */
#define Iodd_WREG_ODC_54(Value)              /* write access not defined */
#define Iodd_WREG_ODC_55(Value)              /* write access not defined */
#define Iodd_WREG_ODC_56(Value)              /* write access not defined */
#define Iodd_WREG_ODC_57(Value)              /* write access not defined */

#endif /* defined(__NEC_V850_DG3__) */

#if                                          \
      defined(__NEC_V850_DJ3__)||            \
      defined(__NEC_V850_DL3__)

#define Iodd_RREG_FC_50                      TARG_ReadBit(PFC5, BIT0)
#define Iodd_RREG_FC_51                      /* read access defined but should not be used */
#define Iodd_RREG_FC_52                      /* read access defined but should not be used */
#define Iodd_RREG_FC_53                      /* read access defined but should not be used */
#define Iodd_RREG_FC_54                      /* read access defined but should not be used */
#define Iodd_RREG_FC_55                      /* read access defined but should not be used */
#define Iodd_RREG_FC_56                      /* read access defined but should not be used */
#define Iodd_RREG_FC_57                      TARG_ReadBit(PFC5, BIT7)

#define Iodd_WREG_FC_50(Value)               TARG_WriteBit(PFC5, BIT0, Value)
#define Iodd_WREG_FC_51(Value)               /* write access not defined */
#define Iodd_WREG_FC_52(Value)               /* write access not defined */
#define Iodd_WREG_FC_53(Value)               /* write access not defined */
#define Iodd_WREG_FC_54(Value)               /* write access not defined */
#define Iodd_WREG_FC_55(Value)               /* write access not defined */
#define Iodd_WREG_FC_56(Value)               /* write access not defined */
#define Iodd_WREG_FC_57(Value)               TARG_WriteBit(PFC5, BIT7, Value)

#endif /* defined(__NEC_V850_DJ3__) || defined(__NEC_V850_DL3__) */

#if                                          \
      defined(__NEC_V850_DG3__)

#define Iodd_RREG_FC_50                      TARG_ReadBit(PFC5, BIT0)
#define Iodd_RREG_FC_51                      /* read access defined but should not be used */
#define Iodd_RREG_FC_52                      /* read access defined but should not be used */
#define Iodd_RREG_FC_53                      /* read access defined but should not be used */
#define Iodd_RREG_FC_54                      /* read access defined but should not be used */
#define Iodd_RREG_FC_55                      /* read access defined but should not be used */
#define Iodd_RREG_FC_56                      /* read access defined but should not be used */
#define Iodd_RREG_FC_57                      /* read access defined but should not be used */

#define Iodd_WREG_FC_50(Value)               TARG_WriteBit(PFC5, BIT0, Value)
#define Iodd_WREG_FC_51(Value)               /* write access not defined */
#define Iodd_WREG_FC_52(Value)               /* write access not defined */
#define Iodd_WREG_FC_53(Value)               /* write access not defined */
#define Iodd_WREG_FC_54(Value)               /* write access not defined */
#define Iodd_WREG_FC_55(Value)               /* write access not defined */
#define Iodd_WREG_FC_56(Value)               /* write access not defined */
#define Iodd_WREG_FC_57(Value)               /* write access not defined */

#endif /* defined(__NEC_V850_DG3__) */

#if                                          \
      defined(__NEC_V850_DJ3__)||            \
      defined(__NEC_V850_DL3__)

#define Iodd_RREG_PR_50                      TARG_ReadBit(PPR5, BIT0)
#define Iodd_RREG_PR_51                      TARG_ReadBit(PPR5, BIT1)
#define Iodd_RREG_PR_52                      TARG_ReadBit(PPR5, BIT2)
#define Iodd_RREG_PR_53                      TARG_ReadBit(PPR5, BIT3)
#define Iodd_RREG_PR_54                      TARG_ReadBit(PPR5, BIT4)
#define Iodd_RREG_PR_55                      TARG_ReadBit(PPR5, BIT5)
#define Iodd_RREG_PR_56                      TARG_ReadBit(PPR5, BIT6)
#define Iodd_RREG_PR_57                      TARG_ReadBit(PPR5, BIT7)

#define Iodd_WREG_PR_50(Value)               /* write access not defined */
#define Iodd_WREG_PR_51(Value)               /* write access not defined */
#define Iodd_WREG_PR_52(Value)               /* write access not defined */
#define Iodd_WREG_PR_53(Value)               /* write access not defined */
#define Iodd_WREG_PR_54(Value)               /* write access not defined */
#define Iodd_WREG_PR_55(Value)               /* write access not defined */
#define Iodd_WREG_PR_56(Value)               /* write access not defined */
#define Iodd_WREG_PR_57(Value)               /* write access not defined */

#endif /* defined(__NEC_V850_DJ3__) || defined(__NEC_V850_DL3__) */

#if                                          \
      defined(__NEC_V850_DG3__)

#define Iodd_RREG_PR_50                      TARG_ReadBit(PPR5, BIT0)
#define Iodd_RREG_PR_51                      TARG_ReadBit(PPR5, BIT1)
#define Iodd_RREG_PR_52                      /* read access defined but should not be used */
#define Iodd_RREG_PR_53                      /* read access defined but should not be used */
#define Iodd_RREG_PR_54                      /* read access defined but should not be used */
#define Iodd_RREG_PR_55                      /* read access defined but should not be used */
#define Iodd_RREG_PR_56                      /* read access defined but should not be used */
#define Iodd_RREG_PR_57                      /* read access defined but should not be used */

#define Iodd_WREG_PR_50(Value)               /* write access not defined */
#define Iodd_WREG_PR_51(Value)               /* write access not defined */
#define Iodd_WREG_PR_52(Value)               /* write access not defined */
#define Iodd_WREG_PR_53(Value)               /* write access not defined */
#define Iodd_WREG_PR_54(Value)               /* write access not defined */
#define Iodd_WREG_PR_55(Value)               /* write access not defined */
#define Iodd_WREG_PR_56(Value)               /* write access not defined */
#define Iodd_WREG_PR_57(Value)               /* write access not defined */

#endif /* defined(__NEC_V850_DG3__) */

#if                                          \
      defined(__NEC_V850_DJ3__)||            \
      defined(__NEC_V850_DL3__)

#define Iodd_RREG_ILC_50                     /* register undefined */
#define Iodd_RREG_ILC_51                     /* register undefined */
#define Iodd_RREG_ILC_52                     /* register undefined */
#define Iodd_RREG_ILC_53                     /* register undefined */
#define Iodd_RREG_ILC_54                     /* register undefined */
#define Iodd_RREG_ILC_55                     /* register undefined */
#define Iodd_RREG_ILC_56                     /* register undefined */
#define Iodd_RREG_ILC_57                     /* register undefined */

#define Iodd_WREG_ILC_50(Value)              /* register undefined */
#define Iodd_WREG_ILC_51(Value)              /* register undefined */
#define Iodd_WREG_ILC_52(Value)              /* register undefined */
#define Iodd_WREG_ILC_53(Value)              /* register undefined */
#define Iodd_WREG_ILC_54(Value)              /* register undefined */
#define Iodd_WREG_ILC_55(Value)              /* register undefined */
#define Iodd_WREG_ILC_56(Value)              /* register undefined */
#define Iodd_WREG_ILC_57(Value)              /* register undefined */

#endif /* defined(__NEC_V850_DJ3__) || defined(__NEC_V850_DL3__) */

#if                                          \
      defined(__NEC_V850_DG3__)

#define Iodd_RREG_ILC_50                     TARG_ReadBit(PILC5, BIT0)
#define Iodd_RREG_ILC_51                     TARG_ReadBit(PILC5, BIT1)
#define Iodd_RREG_ILC_52                     /* read access defined but should not be used */
#define Iodd_RREG_ILC_53                     /* read access defined but should not be used */
#define Iodd_RREG_ILC_54                     /* read access defined but should not be used */
#define Iodd_RREG_ILC_55                     /* read access defined but should not be used */
#define Iodd_RREG_ILC_56                     /* read access defined but should not be used */
#define Iodd_RREG_ILC_57                     /* read access defined but should not be used */

#define Iodd_WREG_ILC_50(Value)              TARG_WriteBit(PILC5, BIT0, Value)
#define Iodd_WREG_ILC_51(Value)              TARG_WriteBit(PILC5, BIT1, Value)
#define Iodd_WREG_ILC_52(Value)              /* write access not defined */
#define Iodd_WREG_ILC_53(Value)              /* write access not defined */
#define Iodd_WREG_ILC_54(Value)              /* write access not defined */
#define Iodd_WREG_ILC_55(Value)              /* write access not defined */
#define Iodd_WREG_ILC_56(Value)              /* write access not defined */
#define Iodd_WREG_ILC_57(Value)              /* write access not defined */

#endif /* defined(__NEC_V850_DG3__) */

#if                                          \
      defined(__NEC_V850_Dx3__)

#define Iodd_RREG_LCDC_50                    /* register undefined */
#define Iodd_RREG_LCDC_51                    /* register undefined */
#define Iodd_RREG_LCDC_52                    /* register undefined */
#define Iodd_RREG_LCDC_53                    /* register undefined */
#define Iodd_RREG_LCDC_54                    /* register undefined */
#define Iodd_RREG_LCDC_55                    /* register undefined */
#define Iodd_RREG_LCDC_56                    /* register undefined */
#define Iodd_RREG_LCDC_57                    /* register undefined */

#define Iodd_WREG_LCDC_50(Value)             /* register undefined */
#define Iodd_WREG_LCDC_51(Value)             /* register undefined */
#define Iodd_WREG_LCDC_52(Value)             /* register undefined */
#define Iodd_WREG_LCDC_53(Value)             /* register undefined */
#define Iodd_WREG_LCDC_54(Value)             /* register undefined */
#define Iodd_WREG_LCDC_55(Value)             /* register undefined */
#define Iodd_WREG_LCDC_56(Value)             /* register undefined */
#define Iodd_WREG_LCDC_57(Value)             /* register undefined */

#endif

#if                                          \
      defined(__NEC_V850_DJ3__)||            \
      defined(__NEC_V850_DL3__)

#define Iodd_RREG_RC_50                     /* register undefined */
#define Iodd_RREG_RC_51                     /* register undefined */
#define Iodd_RREG_RC_52                     /* register undefined */
#define Iodd_RREG_RC_53                     /* register undefined */
#define Iodd_RREG_RC_54                     /* register undefined */
#define Iodd_RREG_RC_55                     /* register undefined */
#define Iodd_RREG_RC_56                     /* register undefined */
#define Iodd_RREG_RC_57                     /* register undefined */

#define Iodd_WREG_RC_50(Value)              /* register undefined */
#define Iodd_WREG_RC_51(Value)              /* register undefined */
#define Iodd_WREG_RC_52(Value)              /* register undefined */
#define Iodd_WREG_RC_53(Value)              /* register undefined */
#define Iodd_WREG_RC_54(Value)              /* register undefined */
#define Iodd_WREG_RC_55(Value)              /* register undefined */
#define Iodd_WREG_RC_56(Value)              /* register undefined */
#define Iodd_WREG_RC_57(Value)              /* register undefined */

#endif /* defined(__NEC_V850_DJ3__) || defined(__NEC_V850_DL3__) */

#if                                          \
      defined(__NEC_V850_DG3__)

#define Iodd_RREG_RC_50                     TARG_ReadBit(PRC5, BIT0)
#define Iodd_RREG_RC_51                     /* read access defined but should not be used */
#define Iodd_RREG_RC_52                     /* read access defined but should not be used */
#define Iodd_RREG_RC_53                     /* read access defined but should not be used */
#define Iodd_RREG_RC_54                     /* read access defined but should not be used */
#define Iodd_RREG_RC_55                     /* read access defined but should not be used */
#define Iodd_RREG_RC_56                     /* read access defined but should not be used */
#define Iodd_RREG_RC_57                     /* read access defined but should not be used */

#define Iodd_WREG_RC_50(Value)              TARG_WriteBit(PRC5, BIT0, Value)
#define Iodd_WREG_RC_51(Value)              /* write access not defined */
#define Iodd_WREG_RC_52(Value)              /* write access not defined */
#define Iodd_WREG_RC_53(Value)              /* write access not defined */
#define Iodd_WREG_RC_54(Value)              /* write access not defined */
#define Iodd_WREG_RC_55(Value)              /* write access not defined */
#define Iodd_WREG_RC_56(Value)              /* write access not defined */
#define Iodd_WREG_RC_57(Value)              /* write access not defined */

#endif /* defined(__NEC_V850_DG3__) */

/* Definitions PORT 6 */

#if                                          \
      defined(__NEC_V850_Dx3__)

#define Iodd_RREG_P_60                       TARG_ReadBit(P6, BIT0)
#define Iodd_RREG_P_61                       TARG_ReadBit(P6, BIT1)
#define Iodd_RREG_P_62                       TARG_ReadBit(P6, BIT2)
#define Iodd_RREG_P_63                       TARG_ReadBit(P6, BIT3)
#define Iodd_RREG_P_64                       TARG_ReadBit(P6, BIT4)
#define Iodd_RREG_P_65                       TARG_ReadBit(P6, BIT5)
#define Iodd_RREG_P_66                       TARG_ReadBit(P6, BIT6)
#define Iodd_RREG_P_67                       TARG_ReadBit(P6, BIT7)

#define Iodd_WREG_P_60(Value)                TARG_WriteBit(P6, BIT0, Value)
#define Iodd_WREG_P_61(Value)                TARG_WriteBit(P6, BIT1, Value)
#define Iodd_WREG_P_62(Value)                TARG_WriteBit(P6, BIT2, Value)
#define Iodd_WREG_P_63(Value)                TARG_WriteBit(P6, BIT3, Value)
#define Iodd_WREG_P_64(Value)                TARG_WriteBit(P6, BIT4, Value)
#define Iodd_WREG_P_65(Value)                TARG_WriteBit(P6, BIT5, Value)
#define Iodd_WREG_P_66(Value)                TARG_WriteBit(P6, BIT6, Value)
#define Iodd_WREG_P_67(Value)                TARG_WriteBit(P6, BIT7, Value)

#endif

#if                                          \
      defined(__NEC_V850_Dx3__)

#define Iodd_RREG_M_60                       TARG_ReadBit(PM6, BIT0)
#define Iodd_RREG_M_61                       TARG_ReadBit(PM6, BIT1)
#define Iodd_RREG_M_62                       TARG_ReadBit(PM6, BIT2)
#define Iodd_RREG_M_63                       TARG_ReadBit(PM6, BIT3)
#define Iodd_RREG_M_64                       TARG_ReadBit(PM6, BIT4)
#define Iodd_RREG_M_65                       TARG_ReadBit(PM6, BIT5)
#define Iodd_RREG_M_66                       TARG_ReadBit(PM6, BIT6)
#define Iodd_RREG_M_67                       TARG_ReadBit(PM6, BIT7)

#define Iodd_WREG_M_60(Value)                TARG_WriteBit(PM6, BIT0, Value)
#define Iodd_WREG_M_61(Value)                TARG_WriteBit(PM6, BIT1, Value)
#define Iodd_WREG_M_62(Value)                TARG_WriteBit(PM6, BIT2, Value)
#define Iodd_WREG_M_63(Value)                TARG_WriteBit(PM6, BIT3, Value)
#define Iodd_WREG_M_64(Value)                TARG_WriteBit(PM6, BIT4, Value)
#define Iodd_WREG_M_65(Value)                TARG_WriteBit(PM6, BIT5, Value)
#define Iodd_WREG_M_66(Value)                TARG_WriteBit(PM6, BIT6, Value)
#define Iodd_WREG_M_67(Value)                TARG_WriteBit(PM6, BIT7, Value)

#endif

#if                                          \
      defined(__NEC_V850_DJ3__)||            \
      defined(__NEC_V850_DL3__)

#define Iodd_RREG_MC_60                      TARG_ReadBit(PMC6, BIT0)
#define Iodd_RREG_MC_61                      TARG_ReadBit(PMC6, BIT1)
#define Iodd_RREG_MC_62                      TARG_ReadBit(PMC6, BIT2)
#define Iodd_RREG_MC_63                      TARG_ReadBit(PMC6, BIT3)
#define Iodd_RREG_MC_64                      TARG_ReadBit(PMC6, BIT4)
#define Iodd_RREG_MC_65                      TARG_ReadBit(PMC6, BIT5)
#define Iodd_RREG_MC_66                      TARG_ReadBit(PMC6, BIT6)
#define Iodd_RREG_MC_67                      TARG_ReadBit(PMC6, BIT7)

#define Iodd_WREG_MC_60(Value)               TARG_WriteBit(PMC6, BIT0, Value)
#define Iodd_WREG_MC_61(Value)               TARG_WriteBit(PMC6, BIT1, Value)
#define Iodd_WREG_MC_62(Value)               TARG_WriteBit(PMC6, BIT2, Value)
#define Iodd_WREG_MC_63(Value)               TARG_WriteBit(PMC6, BIT3, Value)
#define Iodd_WREG_MC_64(Value)               TARG_WriteBit(PMC6, BIT4, Value)
#define Iodd_WREG_MC_65(Value)               TARG_WriteBit(PMC6, BIT5, Value)
#define Iodd_WREG_MC_66(Value)               TARG_WriteBit(PMC6, BIT6, Value)
#define Iodd_WREG_MC_67(Value)               TARG_WriteBit(PMC6, BIT7, Value)

#endif /* defined(__NEC_V850_DJ3__) || defined(__NEC_V850_DL3__) */

#if                                          \
      defined(__NEC_V850_DG3__)

#define Iodd_RREG_MC_60                      TARG_ReadBit(PMC6, BIT0)
#define Iodd_RREG_MC_61                      TARG_ReadBit(PMC6, BIT1)
#define Iodd_RREG_MC_62                      /* read access defined but should not be used */
#define Iodd_RREG_MC_63                      /* read access defined but should not be used */
#define Iodd_RREG_MC_64                      TARG_ReadBit(PMC6, BIT4)
#define Iodd_RREG_MC_65                      TARG_ReadBit(PMC6, BIT5)
#define Iodd_RREG_MC_66                      /* read access defined but should not be used */
#define Iodd_RREG_MC_67                      /* read access defined but should not be used */

#define Iodd_WREG_MC_60(Value)               TARG_WriteBit(PMC6, BIT0, Value)
#define Iodd_WREG_MC_61(Value)               TARG_WriteBit(PMC6, BIT1, Value)
#define Iodd_WREG_MC_62(Value)               /* write access not defined */
#define Iodd_WREG_MC_63(Value)               /* write access not defined */
#define Iodd_WREG_MC_64(Value)               TARG_WriteBit(PMC6, BIT4, Value)
#define Iodd_WREG_MC_65(Value)               TARG_WriteBit(PMC6, BIT5, Value)
#define Iodd_WREG_MC_66(Value)               /* write access not defined */
#define Iodd_WREG_MC_67(Value)               /* write access not defined */

#endif /* defined(__NEC_V850_DG3__) */

#if                                          \
      defined(__NEC_V850_Dx3__)

#define Iodd_RREG_DSC_60                     TARG_ReadBit(PDSC6, BIT0)
#define Iodd_RREG_DSC_61                     TARG_ReadBit(PDSC6, BIT1)
#define Iodd_RREG_DSC_62                     TARG_ReadBit(PDSC6, BIT2)
#define Iodd_RREG_DSC_63                     TARG_ReadBit(PDSC6, BIT3)
#define Iodd_RREG_DSC_64                     TARG_ReadBit(PDSC6, BIT4)
#define Iodd_RREG_DSC_65                     TARG_ReadBit(PDSC6, BIT5)
#define Iodd_RREG_DSC_66                     TARG_ReadBit(PDSC6, BIT6)
#define Iodd_RREG_DSC_67                     TARG_ReadBit(PDSC6, BIT7)

#define Iodd_WREG_DSC_60(Value)              TARG_WriteBit(PDSC6, BIT0, Value)
#define Iodd_WREG_DSC_61(Value)              TARG_WriteBit(PDSC6, BIT1, Value)
#define Iodd_WREG_DSC_62(Value)              TARG_WriteBit(PDSC6, BIT2, Value)
#define Iodd_WREG_DSC_63(Value)              TARG_WriteBit(PDSC6, BIT3, Value)
#define Iodd_WREG_DSC_64(Value)              TARG_WriteBit(PDSC6, BIT4, Value)
#define Iodd_WREG_DSC_65(Value)              TARG_WriteBit(PDSC6, BIT5, Value)
#define Iodd_WREG_DSC_66(Value)              TARG_WriteBit(PDSC6, BIT6, Value)
#define Iodd_WREG_DSC_67(Value)              TARG_WriteBit(PDSC6, BIT7, Value)

#endif

#if                                          \
      defined(__NEC_V850_Dx3__)

#define Iodd_RREG_ICC_60                     TARG_ReadBit(PICC6, BIT0)
#define Iodd_RREG_ICC_61                     TARG_ReadBit(PICC6, BIT1)
#define Iodd_RREG_ICC_62                     TARG_ReadBit(PICC6, BIT2)
#define Iodd_RREG_ICC_63                     TARG_ReadBit(PICC6, BIT3)
#define Iodd_RREG_ICC_64                     TARG_ReadBit(PICC6, BIT4)
#define Iodd_RREG_ICC_65                     TARG_ReadBit(PICC6, BIT5)
#define Iodd_RREG_ICC_66                     TARG_ReadBit(PICC6, BIT6)
#define Iodd_RREG_ICC_67                     TARG_ReadBit(PICC6, BIT7)

#define Iodd_WREG_ICC_60(Value)              TARG_WriteBit(PICC6, BIT0, Value)
#define Iodd_WREG_ICC_61(Value)              TARG_WriteBit(PICC6, BIT1, Value)
#define Iodd_WREG_ICC_62(Value)              TARG_WriteBit(PICC6, BIT2, Value)
#define Iodd_WREG_ICC_63(Value)              TARG_WriteBit(PICC6, BIT3, Value)
#define Iodd_WREG_ICC_64(Value)              TARG_WriteBit(PICC6, BIT4, Value)
#define Iodd_WREG_ICC_65(Value)              TARG_WriteBit(PICC6, BIT5, Value)
#define Iodd_WREG_ICC_66(Value)              TARG_WriteBit(PICC6, BIT6, Value)
#define Iodd_WREG_ICC_67(Value)              TARG_WriteBit(PICC6, BIT7, Value)

#endif

#if                                          \
      defined(__NEC_V850_Dx3__)

#define Iodd_RREG_ODC_60                     TARG_ReadBit(PODC6, BIT0)
#define Iodd_RREG_ODC_61                     TARG_ReadBit(PODC6, BIT1)
#define Iodd_RREG_ODC_62                     TARG_ReadBit(PODC6, BIT2)
#define Iodd_RREG_ODC_63                     TARG_ReadBit(PODC6, BIT3)
#define Iodd_RREG_ODC_64                     TARG_ReadBit(PODC6, BIT4)
#define Iodd_RREG_ODC_65                     TARG_ReadBit(PODC6, BIT5)
#define Iodd_RREG_ODC_66                     TARG_ReadBit(PODC6, BIT6)
#define Iodd_RREG_ODC_67                     TARG_ReadBit(PODC6, BIT7)

#define Iodd_WREG_ODC_60(Value)              TARG_WriteBit(PODC6, BIT0, Value)
#define Iodd_WREG_ODC_61(Value)              TARG_WriteBit(PODC6, BIT1, Value)
#define Iodd_WREG_ODC_62(Value)              TARG_WriteBit(PODC6, BIT2, Value)
#define Iodd_WREG_ODC_63(Value)              TARG_WriteBit(PODC6, BIT3, Value)
#define Iodd_WREG_ODC_64(Value)              TARG_WriteBit(PODC6, BIT4, Value)
#define Iodd_WREG_ODC_65(Value)              TARG_WriteBit(PODC6, BIT5, Value)
#define Iodd_WREG_ODC_66(Value)              TARG_WriteBit(PODC6, BIT6, Value)
#define Iodd_WREG_ODC_67(Value)              TARG_WriteBit(PODC6, BIT7, Value)

#endif

#if                                          \
      defined(__NEC_V850_DJ3__)||            \
      defined(__NEC_V850_DL3__)

#define Iodd_RREG_FC_60                      /* read access defined but should not be used */
#define Iodd_RREG_FC_61                      TARG_ReadBit(PFC6, BIT1)
#define Iodd_RREG_FC_62                      TARG_ReadBit(PFC6, BIT2)
#define Iodd_RREG_FC_63                      TARG_ReadBit(PFC6, BIT3)
#define Iodd_RREG_FC_64                      TARG_ReadBit(PFC6, BIT4)
#define Iodd_RREG_FC_65                      TARG_ReadBit(PFC6, BIT5)
#define Iodd_RREG_FC_66                      TARG_ReadBit(PFC6, BIT6)
#define Iodd_RREG_FC_67                      TARG_ReadBit(PFC6, BIT7)

#define Iodd_WREG_FC_60(Value)               /* write access not defined */
#define Iodd_WREG_FC_61(Value)               /* write access defined but should not be used */
#define Iodd_WREG_FC_62(Value)               /* write access defined but should not be used */
#define Iodd_WREG_FC_63(Value)               /* write access defined but should not be used */
#define Iodd_WREG_FC_64(Value)               /* write access defined but should not be used */
#define Iodd_WREG_FC_65(Value)               TARG_WriteBit(PFC6, BIT5, Value)
#define Iodd_WREG_FC_66(Value)               /* write access defined but should not be used */
#define Iodd_WREG_FC_67(Value)               /* write access defined but should not be used */

#endif /* defined(__NEC_V850_DJ3__) || defined(__NEC_V850_DL3__) */

#if                                          \
      defined(__NEC_V850_DG3__)

#define Iodd_RREG_FC_60                      /* register undefined */
#define Iodd_RREG_FC_61                      /* register undefined */
#define Iodd_RREG_FC_62                      /* register undefined */
#define Iodd_RREG_FC_63                      /* register undefined */
#define Iodd_RREG_FC_64                      /* register undefined */
#define Iodd_RREG_FC_65                      /* register undefined */
#define Iodd_RREG_FC_66                      /* register undefined */
#define Iodd_RREG_FC_67                      /* register undefined */

#define Iodd_WREG_FC_60(Value)               /* register undefined */
#define Iodd_WREG_FC_61(Value)               /* register undefined */
#define Iodd_WREG_FC_62(Value)               /* register undefined */
#define Iodd_WREG_FC_63(Value)               /* register undefined */
#define Iodd_WREG_FC_64(Value)               /* register undefined */
#define Iodd_WREG_FC_65(Value)               /* register undefined */
#define Iodd_WREG_FC_66(Value)               /* register undefined */
#define Iodd_WREG_FC_67(Value)               /* register undefined */

#endif /* defined(__NEC_V850_DG3__) */

#if                                          \
      defined(__NEC_V850_Dx3__)

#define Iodd_RREG_PR_60                      TARG_ReadBit(PPR6, BIT0)
#define Iodd_RREG_PR_61                      TARG_ReadBit(PPR6, BIT1)
#define Iodd_RREG_PR_62                      TARG_ReadBit(PPR6, BIT2)
#define Iodd_RREG_PR_63                      TARG_ReadBit(PPR6, BIT3)
#define Iodd_RREG_PR_64                      TARG_ReadBit(PPR6, BIT4)
#define Iodd_RREG_PR_65                      TARG_ReadBit(PPR6, BIT5)
#define Iodd_RREG_PR_66                      TARG_ReadBit(PPR6, BIT6)
#define Iodd_RREG_PR_67                      TARG_ReadBit(PPR6, BIT7)

#define Iodd_WREG_PR_60(Value)               /* write access not defined */
#define Iodd_WREG_PR_61(Value)               /* write access not defined */
#define Iodd_WREG_PR_62(Value)               /* write access not defined */
#define Iodd_WREG_PR_63(Value)               /* write access not defined */
#define Iodd_WREG_PR_64(Value)               /* write access not defined */
#define Iodd_WREG_PR_65(Value)               /* write access not defined */
#define Iodd_WREG_PR_66(Value)               /* write access not defined */
#define Iodd_WREG_PR_67(Value)               /* write access not defined */

#endif

#if                                          \
      defined(__NEC_V850_DG3__)||            \
      defined(__NEC_V850_DJ3_LE__)

#define Iodd_RREG_LCDC_60                    TARG_ReadBit(PLCDC6, BIT0)
#define Iodd_RREG_LCDC_61                    TARG_ReadBit(PLCDC6, BIT1)
#define Iodd_RREG_LCDC_62                    TARG_ReadBit(PLCDC6, BIT2)
#define Iodd_RREG_LCDC_63                    TARG_ReadBit(PLCDC6, BIT3)
#define Iodd_RREG_LCDC_64                    TARG_ReadBit(PLCDC6, BIT4)
#define Iodd_RREG_LCDC_65                    TARG_ReadBit(PLCDC6, BIT5)
#define Iodd_RREG_LCDC_66                    TARG_ReadBit(PLCDC6, BIT6)
#define Iodd_RREG_LCDC_67                    TARG_ReadBit(PLCDC6, BIT7)

#define Iodd_WREG_LCDC_60(Value)             TARG_WriteBit(PLCDC6, BIT0, Value)
#define Iodd_WREG_LCDC_61(Value)             TARG_WriteBit(PLCDC6, BIT1, Value)
#define Iodd_WREG_LCDC_62(Value)             TARG_WriteBit(PLCDC6, BIT2, Value)
#define Iodd_WREG_LCDC_63(Value)             TARG_WriteBit(PLCDC6, BIT3, Value)
#define Iodd_WREG_LCDC_64(Value)             TARG_WriteBit(PLCDC6, BIT4, Value)
#define Iodd_WREG_LCDC_65(Value)             TARG_WriteBit(PLCDC6, BIT5, Value)
#define Iodd_WREG_LCDC_66(Value)             TARG_WriteBit(PLCDC6, BIT6, Value)
#define Iodd_WREG_LCDC_67(Value)             TARG_WriteBit(PLCDC6, BIT7, Value)

#endif /* defined(__NEC_V850_DG3__) || defined(__NEC_V850_DJ3_LE__) */

#if                                          \
      defined(__NEC_V850_DL3__)||            \
      defined(__NEC_V850_DJ3_HE__)

#define Iodd_RREG_LCDC_60                    /* register undefined */
#define Iodd_RREG_LCDC_61                    /* register undefined */
#define Iodd_RREG_LCDC_62                    /* register undefined */
#define Iodd_RREG_LCDC_63                    /* register undefined */
#define Iodd_RREG_LCDC_64                    /* register undefined */
#define Iodd_RREG_LCDC_65                    /* register undefined */
#define Iodd_RREG_LCDC_66                    /* register undefined */
#define Iodd_RREG_LCDC_67                    /* register undefined */

#define Iodd_WREG_LCDC_60(Value)             /* register undefined */
#define Iodd_WREG_LCDC_61(Value)             /* register undefined */
#define Iodd_WREG_LCDC_62(Value)             /* register undefined */
#define Iodd_WREG_LCDC_63(Value)             /* register undefined */
#define Iodd_WREG_LCDC_64(Value)             /* register undefined */
#define Iodd_WREG_LCDC_65(Value)             /* register undefined */
#define Iodd_WREG_LCDC_66(Value)             /* register undefined */
#define Iodd_WREG_LCDC_67(Value)             /* register undefined */

#endif /* defined(__NEC_V850_DL3__) || defined(__NEC_V850_DJ3_HE__) */

#if                                          \
      defined(__NEC_V850_DJ3__)||            \
      defined(__NEC_V850_DL3__)

#define Iodd_RREG_ILC_60                     /* register undefined */
#define Iodd_RREG_ILC_61                     /* register undefined */
#define Iodd_RREG_ILC_62                     /* register undefined */
#define Iodd_RREG_ILC_63                     /* register undefined */
#define Iodd_RREG_ILC_64                     /* register undefined */
#define Iodd_RREG_ILC_65                     /* register undefined */
#define Iodd_RREG_ILC_66                     /* register undefined */
#define Iodd_RREG_ILC_67                     /* register undefined */

#define Iodd_WREG_ILC_60(Value)              /* register undefined */
#define Iodd_WREG_ILC_61(Value)              /* register undefined */
#define Iodd_WREG_ILC_62(Value)              /* register undefined */
#define Iodd_WREG_ILC_63(Value)              /* register undefined */
#define Iodd_WREG_ILC_64(Value)              /* register undefined */
#define Iodd_WREG_ILC_65(Value)              /* register undefined */
#define Iodd_WREG_ILC_66(Value)              /* register undefined */
#define Iodd_WREG_ILC_67(Value)              /* register undefined */

#endif /* defined(__NEC_V850_DJ3__) || defined(__NEC_V850_DL3__) */

#if                                          \
      defined(__NEC_V850_DG3__)

#define Iodd_RREG_ILC_60                     TARG_ReadBit(PILC6, BIT0)
#define Iodd_RREG_ILC_61                     TARG_ReadBit(PILC6, BIT1)
#define Iodd_RREG_ILC_62                     TARG_ReadBit(PILC6, BIT2)
#define Iodd_RREG_ILC_63                     TARG_ReadBit(PILC6, BIT3)
#define Iodd_RREG_ILC_64                     TARG_ReadBit(PILC6, BIT4)
#define Iodd_RREG_ILC_65                     TARG_ReadBit(PILC6, BIT5)
#define Iodd_RREG_ILC_66                     TARG_ReadBit(PILC6, BIT6)
#define Iodd_RREG_ILC_67                     TARG_ReadBit(PILC6, BIT7)

#define Iodd_WREG_ILC_60(Value)              TARG_WriteBit(PILC6, BIT0, Value)
#define Iodd_WREG_ILC_61(Value)              TARG_WriteBit(PILC6, BIT1, Value)
#define Iodd_WREG_ILC_62(Value)              TARG_WriteBit(PILC6, BIT2, Value)
#define Iodd_WREG_ILC_63(Value)              TARG_WriteBit(PILC6, BIT3, Value)
#define Iodd_WREG_ILC_64(Value)              TARG_WriteBit(PILC6, BIT4, Value)
#define Iodd_WREG_ILC_65(Value)              TARG_WriteBit(PILC6, BIT5, Value)
#define Iodd_WREG_ILC_66(Value)              TARG_WriteBit(PILC6, BIT6, Value)
#define Iodd_WREG_ILC_67(Value)              TARG_WriteBit(PILC6, BIT7, Value)

#endif /* defined(__NEC_V850_DG3__) */

#if                                          \
      defined(__NEC_V850_DJ3__)||            \
      defined(__NEC_V850_DL3__)

#define Iodd_RREG_RC_60                     /* register undefined */
#define Iodd_RREG_RC_61                     /* register undefined */
#define Iodd_RREG_RC_62                     /* register undefined */
#define Iodd_RREG_RC_63                     /* register undefined */
#define Iodd_RREG_RC_64                     /* register undefined */
#define Iodd_RREG_RC_65                     /* register undefined */
#define Iodd_RREG_RC_66                     /* register undefined */
#define Iodd_RREG_RC_67                     /* register undefined */

#define Iodd_WREG_RC_60(Value)              /* register undefined */
#define Iodd_WREG_RC_61(Value)              /* register undefined */
#define Iodd_WREG_RC_62(Value)              /* register undefined */
#define Iodd_WREG_RC_63(Value)              /* register undefined */
#define Iodd_WREG_RC_64(Value)              /* register undefined */
#define Iodd_WREG_RC_65(Value)              /* register undefined */
#define Iodd_WREG_RC_66(Value)              /* register undefined */
#define Iodd_WREG_RC_67(Value)              /* register undefined */

#endif /* defined(__NEC_V850_DJ3__) || defined(__NEC_V850_DL3__) */

#if                                          \
      defined(__NEC_V850_DG3__)

#define Iodd_RREG_RC_60                     TARG_ReadBit(PRC6, BIT0)
#define Iodd_RREG_RC_61                     /* read access defined but should not be used */
#define Iodd_RREG_RC_62                     /* read access defined but should not be used */
#define Iodd_RREG_RC_63                     /* read access defined but should not be used */
#define Iodd_RREG_RC_64                     /* read access defined but should not be used */
#define Iodd_RREG_RC_65                     /* read access defined but should not be used */
#define Iodd_RREG_RC_66                     /* read access defined but should not be used */
#define Iodd_RREG_RC_67                     /* read access defined but should not be used */

#define Iodd_WREG_RC_60(Value)              TARG_WriteBit(PRC6, BIT0, Value)
#define Iodd_WREG_RC_61(Value)              /* write access not defined */
#define Iodd_WREG_RC_62(Value)              /* write access not defined */
#define Iodd_WREG_RC_63(Value)              /* write access not defined */
#define Iodd_WREG_RC_64(Value)              /* write access not defined */
#define Iodd_WREG_RC_65(Value)              /* write access not defined */
#define Iodd_WREG_RC_66(Value)              /* write access not defined */
#define Iodd_WREG_RC_67(Value)              /* write access not defined */

#endif /* defined(__NEC_V850_DG3__) */

/* Definitions PORT 7 */

#if                                          \
      defined(__NEC_V850_DJ3__)||            \
      defined(__NEC_V850_DL3__)

#define Iodd_RREG_P_70                       TARG_ReadBit(P7L, BIT0)
#define Iodd_RREG_P_71                       TARG_ReadBit(P7L, BIT1)
#define Iodd_RREG_P_72                       TARG_ReadBit(P7L, BIT2)
#define Iodd_RREG_P_73                       TARG_ReadBit(P7L, BIT3)
#define Iodd_RREG_P_74                       TARG_ReadBit(P7L, BIT4)
#define Iodd_RREG_P_75                       TARG_ReadBit(P7L, BIT5)
#define Iodd_RREG_P_76                       TARG_ReadBit(P7L, BIT6)
#define Iodd_RREG_P_77                       TARG_ReadBit(P7L, BIT7)
#define Iodd_RREG_P_78                       TARG_ReadBit(P7H, BIT0)
#define Iodd_RREG_P_79                       TARG_ReadBit(P7H, BIT1)
#define Iodd_RREG_P_710                      TARG_ReadBit(P7H, BIT2)
#define Iodd_RREG_P_711                      TARG_ReadBit(P7H, BIT3)
#define Iodd_RREG_P_712                      TARG_ReadBit(P7H, BIT4)
#define Iodd_RREG_P_713                      TARG_ReadBit(P7H, BIT5)
#define Iodd_RREG_P_714                      TARG_ReadBit(P7H, BIT6)
#define Iodd_RREG_P_715                      TARG_ReadBit(P7H, BIT7)

#define Iodd_WREG_P_70(Value)                /* write access not defined */
#define Iodd_WREG_P_71(Value)                /* write access not defined */
#define Iodd_WREG_P_72(Value)                /* write access not defined */
#define Iodd_WREG_P_73(Value)                /* write access not defined */
#define Iodd_WREG_P_74(Value)                /* write access not defined */
#define Iodd_WREG_P_75(Value)                /* write access not defined */
#define Iodd_WREG_P_76(Value)                /* write access not defined */
#define Iodd_WREG_P_77(Value)                /* write access not defined */
#define Iodd_WREG_P_78(Value)                /* write access not defined */
#define Iodd_WREG_P_79(Value)                /* write access not defined */
#define Iodd_WREG_P_710(Value)               /* write access not defined */
#define Iodd_WREG_P_711(Value)               /* write access not defined */
#define Iodd_WREG_P_712(Value)               /* write access not defined */
#define Iodd_WREG_P_713(Value)               /* write access not defined */
#define Iodd_WREG_P_714(Value)               /* write access not defined */
#define Iodd_WREG_P_715(Value)               /* write access not defined */

#endif /* defined(__NEC_V850_DJ3__) || defined(__NEC_V850_DL3__) */

#if                                          \
      defined(__NEC_V850_DG3__)

#define Iodd_RREG_P_70                       TARG_ReadBit(P7, BIT0)
#define Iodd_RREG_P_71                       TARG_ReadBit(P7, BIT1)
#define Iodd_RREG_P_72                       TARG_ReadBit(P7, BIT2)
#define Iodd_RREG_P_73                       TARG_ReadBit(P7, BIT3)
#define Iodd_RREG_P_74                       TARG_ReadBit(P7, BIT4)
#define Iodd_RREG_P_75                       TARG_ReadBit(P7, BIT5)
#define Iodd_RREG_P_76                       TARG_ReadBit(P7, BIT6)
#define Iodd_RREG_P_77                       TARG_ReadBit(P7, BIT7)
#define Iodd_RREG_P_78                       /* register undefined */
#define Iodd_RREG_P_79                       /* register undefined */
#define Iodd_RREG_P_710                      /* register undefined */
#define Iodd_RREG_P_711                      /* register undefined */
#define Iodd_RREG_P_712                      /* register undefined */
#define Iodd_RREG_P_713                      /* register undefined */
#define Iodd_RREG_P_714                      /* register undefined */
#define Iodd_RREG_P_715                      /* register undefined */

#define Iodd_WREG_P_70(Value)                /* write access not defined */
#define Iodd_WREG_P_71(Value)                /* write access not defined */
#define Iodd_WREG_P_72(Value)                /* write access not defined */
#define Iodd_WREG_P_73(Value)                /* write access not defined */
#define Iodd_WREG_P_74(Value)                /* write access not defined */
#define Iodd_WREG_P_75(Value)                /* write access not defined */
#define Iodd_WREG_P_76(Value)                /* write access not defined */
#define Iodd_WREG_P_77(Value)                /* write access not defined */
#define Iodd_WREG_P_78(Value)                /* register undefined */
#define Iodd_WREG_P_79(Value)                /* register undefined */
#define Iodd_WREG_P_710(Value)               /* register undefined */
#define Iodd_WREG_P_711(Value)               /* register undefined */
#define Iodd_WREG_P_712(Value)               /* register undefined */
#define Iodd_WREG_P_713(Value)               /* register undefined */
#define Iodd_WREG_P_714(Value)               /* register undefined */
#define Iodd_WREG_P_715(Value)               /* register undefined */

#endif /* defined(__NEC_V850_DG3__) */

#if                                          \
      defined(__NEC_V850_DJ3__)||            \
      defined(__NEC_V850_DL3__)

#define Iodd_RREG_MC_70                      TARG_ReadBit(PMC7L, BIT0)
#define Iodd_RREG_MC_71                      TARG_ReadBit(PMC7L, BIT1)
#define Iodd_RREG_MC_72                      TARG_ReadBit(PMC7L, BIT2)
#define Iodd_RREG_MC_73                      TARG_ReadBit(PMC7L, BIT3)
#define Iodd_RREG_MC_74                      TARG_ReadBit(PMC7L, BIT4)
#define Iodd_RREG_MC_75                      TARG_ReadBit(PMC7L, BIT5)
#define Iodd_RREG_MC_76                      TARG_ReadBit(PMC7L, BIT6)
#define Iodd_RREG_MC_77                      TARG_ReadBit(PMC7L, BIT7)
#define Iodd_RREG_MC_78                      TARG_ReadBit(PMC7H, BIT0)
#define Iodd_RREG_MC_79                      TARG_ReadBit(PMC7H, BIT1)
#define Iodd_RREG_MC_710                     TARG_ReadBit(PMC7H, BIT2)
#define Iodd_RREG_MC_711                     TARG_ReadBit(PMC7H, BIT3)
#define Iodd_RREG_MC_712                     TARG_ReadBit(PMC7H, BIT4)
#define Iodd_RREG_MC_713                     TARG_ReadBit(PMC7H, BIT5)
#define Iodd_RREG_MC_714                     TARG_ReadBit(PMC7H, BIT6)
#define Iodd_RREG_MC_715                     TARG_ReadBit(PMC7H, BIT7)

#define Iodd_WREG_MC_70(Value)               TARG_WriteBit(PMC7L, BIT0, Value)
#define Iodd_WREG_MC_71(Value)               TARG_WriteBit(PMC7L, BIT1, Value)
#define Iodd_WREG_MC_72(Value)               TARG_WriteBit(PMC7L, BIT2, Value)
#define Iodd_WREG_MC_73(Value)               TARG_WriteBit(PMC7L, BIT3, Value)
#define Iodd_WREG_MC_74(Value)               TARG_WriteBit(PMC7L, BIT4, Value)
#define Iodd_WREG_MC_75(Value)               TARG_WriteBit(PMC7L, BIT5, Value)
#define Iodd_WREG_MC_76(Value)               TARG_WriteBit(PMC7L, BIT6, Value)
#define Iodd_WREG_MC_77(Value)               TARG_WriteBit(PMC7L, BIT7, Value)
#define Iodd_WREG_MC_78(Value)               TARG_WriteBit(PMC7H, BIT0, Value)
#define Iodd_WREG_MC_79(Value)               TARG_WriteBit(PMC7H, BIT1, Value)
#define Iodd_WREG_MC_710(Value)              TARG_WriteBit(PMC7H, BIT2, Value)
#define Iodd_WREG_MC_711(Value)              TARG_WriteBit(PMC7H, BIT3, Value)
#define Iodd_WREG_MC_712(Value)              TARG_WriteBit(PMC7H, BIT4, Value)
#define Iodd_WREG_MC_713(Value)              TARG_WriteBit(PMC7H, BIT5, Value)
#define Iodd_WREG_MC_714(Value)              TARG_WriteBit(PMC7H, BIT6, Value)
#define Iodd_WREG_MC_715(Value)              TARG_WriteBit(PMC7H, BIT7, Value)

#endif /* defined(__NEC_V850_DJ3__) || defined(__NEC_V850_DL3__) */

#if                                          \
      defined(__NEC_V850_DG3__)

#define Iodd_RREG_MC_70                      TARG_ReadBit(PMC7, BIT0)
#define Iodd_RREG_MC_71                      TARG_ReadBit(PMC7, BIT1)
#define Iodd_RREG_MC_72                      TARG_ReadBit(PMC7, BIT2)
#define Iodd_RREG_MC_73                      TARG_ReadBit(PMC7, BIT3)
#define Iodd_RREG_MC_74                      TARG_ReadBit(PMC7, BIT4)
#define Iodd_RREG_MC_75                      TARG_ReadBit(PMC7, BIT5)
#define Iodd_RREG_MC_76                      TARG_ReadBit(PMC7, BIT6)
#define Iodd_RREG_MC_77                      TARG_ReadBit(PMC7, BIT7)
#define Iodd_RREG_MC_78                      /* register undefined */
#define Iodd_RREG_MC_79                      /* register undefined */
#define Iodd_RREG_MC_710                     /* register undefined */
#define Iodd_RREG_MC_711                     /* register undefined */
#define Iodd_RREG_MC_712                     /* register undefined */
#define Iodd_RREG_MC_713                     /* register undefined */
#define Iodd_RREG_MC_714                     /* register undefined */
#define Iodd_RREG_MC_715                     /* register undefined */

#define Iodd_WREG_MC_70(Value)               TARG_WriteBit(PMC7, BIT0, Value)
#define Iodd_WREG_MC_71(Value)               TARG_WriteBit(PMC7, BIT1, Value)
#define Iodd_WREG_MC_72(Value)               TARG_WriteBit(PMC7, BIT2, Value)
#define Iodd_WREG_MC_73(Value)               TARG_WriteBit(PMC7, BIT3, Value)
#define Iodd_WREG_MC_74(Value)               TARG_WriteBit(PMC7, BIT4, Value)
#define Iodd_WREG_MC_75(Value)               TARG_WriteBit(PMC7, BIT5, Value)
#define Iodd_WREG_MC_76(Value)               TARG_WriteBit(PMC7, BIT6, Value)
#define Iodd_WREG_MC_77(Value)               TARG_WriteBit(PMC7, BIT7, Value)
#define Iodd_WREG_MC_78(Value)               /* register undefined */
#define Iodd_WREG_MC_79(Value)               /* register undefined */
#define Iodd_WREG_MC_710(Value)              /* register undefined */
#define Iodd_WREG_MC_711(Value)              /* register undefined */
#define Iodd_WREG_MC_712(Value)              /* register undefined */
#define Iodd_WREG_MC_713(Value)              /* register undefined */
#define Iodd_WREG_MC_714(Value)              /* register undefined */
#define Iodd_WREG_MC_715(Value)              /* register undefined */

#endif /* defined(__NEC_V850_DG3__) */

#if                                          \
      defined(__NEC_V850_DJ3__)||            \
      defined(__NEC_V850_DL3__)

#define Iodd_RREG_ILC_70                     /* register undefined */
#define Iodd_RREG_ILC_71                     /* register undefined */
#define Iodd_RREG_ILC_72                     /* register undefined */
#define Iodd_RREG_ILC_73                     /* register undefined */
#define Iodd_RREG_ILC_74                     /* register undefined */
#define Iodd_RREG_ILC_75                     /* register undefined */
#define Iodd_RREG_ILC_76                     /* register undefined */
#define Iodd_RREG_ILC_77                     /* register undefined */
#define Iodd_RREG_ILC_78                     /* register undefined */
#define Iodd_RREG_ILC_79                     /* register undefined */
#define Iodd_RREG_ILC_710                    /* register undefined */
#define Iodd_RREG_ILC_711                    /* register undefined */
#define Iodd_RREG_ILC_712                    /* register undefined */
#define Iodd_RREG_ILC_713                    /* register undefined */
#define Iodd_RREG_ILC_714                    /* register undefined */
#define Iodd_RREG_ILC_715                    /* register undefined */

#define Iodd_WREG_ILC_70(Value)              /* register undefined */
#define Iodd_WREG_ILC_71(Value)              /* register undefined */
#define Iodd_WREG_ILC_72(Value)              /* register undefined */
#define Iodd_WREG_ILC_73(Value)              /* register undefined */
#define Iodd_WREG_ILC_74(Value)              /* register undefined */
#define Iodd_WREG_ILC_75(Value)              /* register undefined */
#define Iodd_WREG_ILC_76(Value)              /* register undefined */
#define Iodd_WREG_ILC_77(Value)              /* register undefined */
#define Iodd_WREG_ILC_78(Value)              /* register undefined */
#define Iodd_WREG_ILC_79(Value)              /* register undefined */
#define Iodd_WREG_ILC_710(Value)             /* register undefined */
#define Iodd_WREG_ILC_711(Value)             /* register undefined */
#define Iodd_WREG_ILC_712(Value)             /* register undefined */
#define Iodd_WREG_ILC_713(Value)             /* register undefined */
#define Iodd_WREG_ILC_714(Value)             /* register undefined */
#define Iodd_WREG_ILC_715(Value)             /* register undefined */

#endif /* defined(__NEC_V850_DJ3__) || defined(__NEC_V850_DL3__) */

#if                                          \
      defined(__NEC_V850_DG3__)

#define Iodd_RREG_ILC_70                     TARG_ReadBit(PILC7, BIT0)
#define Iodd_RREG_ILC_71                     TARG_ReadBit(PILC7, BIT1)
#define Iodd_RREG_ILC_72                     TARG_ReadBit(PILC7, BIT2)
#define Iodd_RREG_ILC_73                     TARG_ReadBit(PILC7, BIT3)
#define Iodd_RREG_ILC_74                     TARG_ReadBit(PILC7, BIT4)
#define Iodd_RREG_ILC_75                     TARG_ReadBit(PILC7, BIT5)
#define Iodd_RREG_ILC_76                     TARG_ReadBit(PILC7, BIT6)
#define Iodd_RREG_ILC_77                     TARG_ReadBit(PILC7, BIT7)
#define Iodd_RREG_ILC_78                     /* register undefined */
#define Iodd_RREG_ILC_79                     /* register undefined */
#define Iodd_RREG_ILC_710                    /* register undefined */
#define Iodd_RREG_ILC_711                    /* register undefined */
#define Iodd_RREG_ILC_712                    /* register undefined */
#define Iodd_RREG_ILC_713                    /* register undefined */
#define Iodd_RREG_ILC_714                    /* register undefined */
#define Iodd_RREG_ILC_715                    /* register undefined */

#define Iodd_WREG_ILC_70(Value)              TARG_WriteBit(PILC7, BIT0, Value)
#define Iodd_WREG_ILC_71(Value)              TARG_WriteBit(PILC7, BIT1, Value)
#define Iodd_WREG_ILC_72(Value)              TARG_WriteBit(PILC7, BIT2, Value)
#define Iodd_WREG_ILC_73(Value)              TARG_WriteBit(PILC7, BIT3, Value)
#define Iodd_WREG_ILC_74(Value)              TARG_WriteBit(PILC7, BIT4, Value)
#define Iodd_WREG_ILC_75(Value)              TARG_WriteBit(PILC7, BIT5, Value)
#define Iodd_WREG_ILC_76(Value)              TARG_WriteBit(PILC7, BIT6, Value)
#define Iodd_WREG_ILC_77(Value)              TARG_WriteBit(PILC7, BIT7, Value)
#define Iodd_WREG_ILC_78(Value)              /* register undefined */
#define Iodd_WREG_ILC_79(Value)              /* register undefined */
#define Iodd_WREG_ILC_710(Value)             /* register undefined */
#define Iodd_WREG_ILC_711(Value)             /* register undefined */
#define Iodd_WREG_ILC_712(Value)             /* register undefined */
#define Iodd_WREG_ILC_713(Value)             /* register undefined */
#define Iodd_WREG_ILC_714(Value)             /* register undefined */
#define Iodd_WREG_ILC_715(Value)             /* register undefined */

#endif /* defined(__NEC_V850_DG3__) */

#if                                          \
      defined(__NEC_V850_Dx3__)

#define Iodd_RREG_M_70                       /* register undefined */
#define Iodd_RREG_M_71                       /* register undefined */
#define Iodd_RREG_M_72                       /* register undefined */
#define Iodd_RREG_M_73                       /* register undefined */
#define Iodd_RREG_M_74                       /* register undefined */
#define Iodd_RREG_M_75                       /* register undefined */
#define Iodd_RREG_M_76                       /* register undefined */
#define Iodd_RREG_M_77                       /* register undefined */
#define Iodd_RREG_M_78                       /* register undefined */
#define Iodd_RREG_M_79                       /* register undefined */
#define Iodd_RREG_M_710                      /* register undefined */
#define Iodd_RREG_M_711                      /* register undefined */
#define Iodd_RREG_M_712                      /* register undefined */
#define Iodd_RREG_M_713                      /* register undefined */
#define Iodd_RREG_M_714                      /* register undefined */
#define Iodd_RREG_M_715                      /* register undefined */

#define Iodd_WREG_M_70(Value)                /* register undefined */
#define Iodd_WREG_M_71(Value)                /* register undefined */
#define Iodd_WREG_M_72(Value)                /* register undefined */
#define Iodd_WREG_M_73(Value)                /* register undefined */
#define Iodd_WREG_M_74(Value)                /* register undefined */
#define Iodd_WREG_M_75(Value)                /* register undefined */
#define Iodd_WREG_M_76(Value)                /* register undefined */
#define Iodd_WREG_M_77(Value)                /* register undefined */
#define Iodd_WREG_M_78(Value)                /* register undefined */
#define Iodd_WREG_M_79(Value)                /* register undefined */
#define Iodd_WREG_M_710(Value)               /* register undefined */
#define Iodd_WREG_M_711(Value)               /* register undefined */
#define Iodd_WREG_M_712(Value)               /* register undefined */
#define Iodd_WREG_M_713(Value)               /* register undefined */
#define Iodd_WREG_M_714(Value)               /* register undefined */
#define Iodd_WREG_M_715(Value)               /* register undefined */

#endif

#if                                          \
      defined(__NEC_V850_Dx3__)

#define Iodd_RREG_DSC_70                     /* register undefined */
#define Iodd_RREG_DSC_71                     /* register undefined */
#define Iodd_RREG_DSC_72                     /* register undefined */
#define Iodd_RREG_DSC_73                     /* register undefined */
#define Iodd_RREG_DSC_74                     /* register undefined */
#define Iodd_RREG_DSC_75                     /* register undefined */
#define Iodd_RREG_DSC_76                     /* register undefined */
#define Iodd_RREG_DSC_77                     /* register undefined */
#define Iodd_RREG_DSC_78                     /* register undefined */
#define Iodd_RREG_DSC_79                     /* register undefined */
#define Iodd_RREG_DSC_710                    /* register undefined */
#define Iodd_RREG_DSC_711                    /* register undefined */
#define Iodd_RREG_DSC_712                    /* register undefined */
#define Iodd_RREG_DSC_713                    /* register undefined */
#define Iodd_RREG_DSC_714                    /* register undefined */
#define Iodd_RREG_DSC_715                    /* register undefined */

#define Iodd_WREG_DSC_70(Value)              /* register undefined */
#define Iodd_WREG_DSC_71(Value)              /* register undefined */
#define Iodd_WREG_DSC_72(Value)              /* register undefined */
#define Iodd_WREG_DSC_73(Value)              /* register undefined */
#define Iodd_WREG_DSC_74(Value)              /* register undefined */
#define Iodd_WREG_DSC_75(Value)              /* register undefined */
#define Iodd_WREG_DSC_76(Value)              /* register undefined */
#define Iodd_WREG_DSC_77(Value)              /* register undefined */
#define Iodd_WREG_DSC_78(Value)              /* register undefined */
#define Iodd_WREG_DSC_79(Value)              /* register undefined */
#define Iodd_WREG_DSC_710(Value)             /* register undefined */
#define Iodd_WREG_DSC_711(Value)             /* register undefined */
#define Iodd_WREG_DSC_712(Value)             /* register undefined */
#define Iodd_WREG_DSC_713(Value)             /* register undefined */
#define Iodd_WREG_DSC_714(Value)             /* register undefined */
#define Iodd_WREG_DSC_715(Value)             /* register undefined */

#endif

#if                                          \
      defined(__NEC_V850_Dx3__)

#define Iodd_RREG_ICC_70                     /* register undefined */
#define Iodd_RREG_ICC_71                     /* register undefined */
#define Iodd_RREG_ICC_72                     /* register undefined */
#define Iodd_RREG_ICC_73                     /* register undefined */
#define Iodd_RREG_ICC_74                     /* register undefined */
#define Iodd_RREG_ICC_75                     /* register undefined */
#define Iodd_RREG_ICC_76                     /* register undefined */
#define Iodd_RREG_ICC_77                     /* register undefined */
#define Iodd_RREG_ICC_78                     /* register undefined */
#define Iodd_RREG_ICC_79                     /* register undefined */
#define Iodd_RREG_ICC_710                    /* register undefined */
#define Iodd_RREG_ICC_711                    /* register undefined */
#define Iodd_RREG_ICC_712                    /* register undefined */
#define Iodd_RREG_ICC_713                    /* register undefined */
#define Iodd_RREG_ICC_714                    /* register undefined */
#define Iodd_RREG_ICC_715                    /* register undefined */

#define Iodd_WREG_ICC_70(Value)              /* register undefined */
#define Iodd_WREG_ICC_71(Value)              /* register undefined */
#define Iodd_WREG_ICC_72(Value)              /* register undefined */
#define Iodd_WREG_ICC_73(Value)              /* register undefined */
#define Iodd_WREG_ICC_74(Value)              /* register undefined */
#define Iodd_WREG_ICC_75(Value)              /* register undefined */
#define Iodd_WREG_ICC_76(Value)              /* register undefined */
#define Iodd_WREG_ICC_77(Value)              /* register undefined */
#define Iodd_WREG_ICC_78(Value)              /* register undefined */
#define Iodd_WREG_ICC_79(Value)              /* register undefined */
#define Iodd_WREG_ICC_710(Value)             /* register undefined */
#define Iodd_WREG_ICC_711(Value)             /* register undefined */
#define Iodd_WREG_ICC_712(Value)             /* register undefined */
#define Iodd_WREG_ICC_713(Value)             /* register undefined */
#define Iodd_WREG_ICC_714(Value)             /* register undefined */
#define Iodd_WREG_ICC_715(Value)             /* register undefined */

#endif

#if                                          \
      defined(__NEC_V850_Dx3__)

#define Iodd_RREG_ODC_70                     /* register undefined */
#define Iodd_RREG_ODC_71                     /* register undefined */
#define Iodd_RREG_ODC_72                     /* register undefined */
#define Iodd_RREG_ODC_73                     /* register undefined */
#define Iodd_RREG_ODC_74                     /* register undefined */
#define Iodd_RREG_ODC_75                     /* register undefined */
#define Iodd_RREG_ODC_76                     /* register undefined */
#define Iodd_RREG_ODC_77                     /* register undefined */
#define Iodd_RREG_ODC_78                     /* register undefined */
#define Iodd_RREG_ODC_79                     /* register undefined */
#define Iodd_RREG_ODC_710                    /* register undefined */
#define Iodd_RREG_ODC_711                    /* register undefined */
#define Iodd_RREG_ODC_712                    /* register undefined */
#define Iodd_RREG_ODC_713                    /* register undefined */
#define Iodd_RREG_ODC_714                    /* register undefined */
#define Iodd_RREG_ODC_715                    /* register undefined */

#define Iodd_WREG_ODC_70(Value)              /* register undefined */
#define Iodd_WREG_ODC_71(Value)              /* register undefined */
#define Iodd_WREG_ODC_72(Value)              /* register undefined */
#define Iodd_WREG_ODC_73(Value)              /* register undefined */
#define Iodd_WREG_ODC_74(Value)              /* register undefined */
#define Iodd_WREG_ODC_75(Value)              /* register undefined */
#define Iodd_WREG_ODC_76(Value)              /* register undefined */
#define Iodd_WREG_ODC_77(Value)              /* register undefined */
#define Iodd_WREG_ODC_78(Value)              /* register undefined */
#define Iodd_WREG_ODC_79(Value)              /* register undefined */
#define Iodd_WREG_ODC_710(Value)             /* register undefined */
#define Iodd_WREG_ODC_711(Value)             /* register undefined */
#define Iodd_WREG_ODC_712(Value)             /* register undefined */
#define Iodd_WREG_ODC_713(Value)             /* register undefined */
#define Iodd_WREG_ODC_714(Value)             /* register undefined */
#define Iodd_WREG_ODC_715(Value)             /* register undefined */

#endif

#if                                          \
      defined(__NEC_V850_Dx3__)

#define Iodd_RREG_FC_70                      /* register undefined */
#define Iodd_RREG_FC_71                      /* register undefined */
#define Iodd_RREG_FC_72                      /* register undefined */
#define Iodd_RREG_FC_73                      /* register undefined */
#define Iodd_RREG_FC_74                      /* register undefined */
#define Iodd_RREG_FC_75                      /* register undefined */
#define Iodd_RREG_FC_76                      /* register undefined */
#define Iodd_RREG_FC_77                      /* register undefined */
#define Iodd_RREG_FC_78                      /* register undefined */
#define Iodd_RREG_FC_79                      /* register undefined */
#define Iodd_RREG_FC_710                     /* register undefined */
#define Iodd_RREG_FC_711                     /* register undefined */
#define Iodd_RREG_FC_712                     /* register undefined */
#define Iodd_RREG_FC_713                     /* register undefined */
#define Iodd_RREG_FC_714                     /* register undefined */
#define Iodd_RREG_FC_715                     /* register undefined */

#define Iodd_WREG_FC_70(Value)               /* register undefined */
#define Iodd_WREG_FC_71(Value)               /* register undefined */
#define Iodd_WREG_FC_72(Value)               /* register undefined */
#define Iodd_WREG_FC_73(Value)               /* register undefined */
#define Iodd_WREG_FC_74(Value)               /* register undefined */
#define Iodd_WREG_FC_75(Value)               /* register undefined */
#define Iodd_WREG_FC_76(Value)               /* register undefined */
#define Iodd_WREG_FC_77(Value)               /* register undefined */
#define Iodd_WREG_FC_78(Value)               /* register undefined */
#define Iodd_WREG_FC_79(Value)               /* register undefined */
#define Iodd_WREG_FC_710(Value)              /* register undefined */
#define Iodd_WREG_FC_711(Value)              /* register undefined */
#define Iodd_WREG_FC_712(Value)              /* register undefined */
#define Iodd_WREG_FC_713(Value)              /* register undefined */
#define Iodd_WREG_FC_714(Value)              /* register undefined */
#define Iodd_WREG_FC_715(Value)              /* register undefined */

#endif

#if                                          \
      defined(__NEC_V850_Dx3__)

#define Iodd_RREG_PR_70                      /* register undefined */
#define Iodd_RREG_PR_71                      /* register undefined */
#define Iodd_RREG_PR_72                      /* register undefined */
#define Iodd_RREG_PR_73                      /* register undefined */
#define Iodd_RREG_PR_74                      /* register undefined */
#define Iodd_RREG_PR_75                      /* register undefined */
#define Iodd_RREG_PR_76                      /* register undefined */
#define Iodd_RREG_PR_77                      /* register undefined */
#define Iodd_RREG_PR_78                      /* register undefined */
#define Iodd_RREG_PR_79                      /* register undefined */
#define Iodd_RREG_PR_710                     /* register undefined */
#define Iodd_RREG_PR_711                     /* register undefined */
#define Iodd_RREG_PR_712                     /* register undefined */
#define Iodd_RREG_PR_713                     /* register undefined */
#define Iodd_RREG_PR_714                     /* register undefined */
#define Iodd_RREG_PR_715                     /* register undefined */

#define Iodd_WREG_PR_70(Value)               /* register undefined */
#define Iodd_WREG_PR_71(Value)               /* register undefined */
#define Iodd_WREG_PR_72(Value)               /* register undefined */
#define Iodd_WREG_PR_73(Value)               /* register undefined */
#define Iodd_WREG_PR_74(Value)               /* register undefined */
#define Iodd_WREG_PR_75(Value)               /* register undefined */
#define Iodd_WREG_PR_76(Value)               /* register undefined */
#define Iodd_WREG_PR_77(Value)               /* register undefined */
#define Iodd_WREG_PR_78(Value)               /* register undefined */
#define Iodd_WREG_PR_79(Value)               /* register undefined */
#define Iodd_WREG_PR_710(Value)              /* register undefined */
#define Iodd_WREG_PR_711(Value)              /* register undefined */
#define Iodd_WREG_PR_712(Value)              /* register undefined */
#define Iodd_WREG_PR_713(Value)              /* register undefined */
#define Iodd_WREG_PR_714(Value)              /* register undefined */
#define Iodd_WREG_PR_715(Value)              /* register undefined */

#endif

#if                                          \
      defined(__NEC_V850_Dx3__)

#define Iodd_RREG_LCDC_70                    /* register undefined */
#define Iodd_RREG_LCDC_71                    /* register undefined */
#define Iodd_RREG_LCDC_72                    /* register undefined */
#define Iodd_RREG_LCDC_73                    /* register undefined */
#define Iodd_RREG_LCDC_74                    /* register undefined */
#define Iodd_RREG_LCDC_75                    /* register undefined */
#define Iodd_RREG_LCDC_76                    /* register undefined */
#define Iodd_RREG_LCDC_77                    /* register undefined */
#define Iodd_RREG_LCDC_78                    /* register undefined */
#define Iodd_RREG_LCDC_79                    /* register undefined */
#define Iodd_RREG_LCDC_710                   /* register undefined */
#define Iodd_RREG_LCDC_711                   /* register undefined */
#define Iodd_RREG_LCDC_712                   /* register undefined */
#define Iodd_RREG_LCDC_713                   /* register undefined */
#define Iodd_RREG_LCDC_714                   /* register undefined */
#define Iodd_RREG_LCDC_715                   /* register undefined */

#define Iodd_WREG_LCDC_70(Value)             /* register undefined */
#define Iodd_WREG_LCDC_71(Value)             /* register undefined */
#define Iodd_WREG_LCDC_72(Value)             /* register undefined */
#define Iodd_WREG_LCDC_73(Value)             /* register undefined */
#define Iodd_WREG_LCDC_74(Value)             /* register undefined */
#define Iodd_WREG_LCDC_75(Value)             /* register undefined */
#define Iodd_WREG_LCDC_76(Value)             /* register undefined */
#define Iodd_WREG_LCDC_77(Value)             /* register undefined */
#define Iodd_WREG_LCDC_78(Value)             /* register undefined */
#define Iodd_WREG_LCDC_79(Value)             /* register undefined */
#define Iodd_WREG_LCDC_710(Value)            /* register undefined */
#define Iodd_WREG_LCDC_711(Value)            /* register undefined */
#define Iodd_WREG_LCDC_712(Value)            /* register undefined */
#define Iodd_WREG_LCDC_713(Value)            /* register undefined */
#define Iodd_WREG_LCDC_714(Value)            /* register undefined */
#define Iodd_WREG_LCDC_715(Value)            /* register undefined */

#endif

#if                                          \
      defined(__NEC_V850_Dx3__)

#define Iodd_RREG_RC_70                    /* register undefined */
#define Iodd_RREG_RC_71                    /* register undefined */
#define Iodd_RREG_RC_72                    /* register undefined */
#define Iodd_RREG_RC_73                    /* register undefined */
#define Iodd_RREG_RC_74                    /* register undefined */
#define Iodd_RREG_RC_75                    /* register undefined */
#define Iodd_RREG_RC_76                    /* register undefined */
#define Iodd_RREG_RC_77                    /* register undefined */
#define Iodd_RREG_RC_78                    /* register undefined */
#define Iodd_RREG_RC_79                    /* register undefined */
#define Iodd_RREG_RC_710                   /* register undefined */
#define Iodd_RREG_RC_711                   /* register undefined */
#define Iodd_RREG_RC_712                   /* register undefined */
#define Iodd_RREG_RC_713                   /* register undefined */
#define Iodd_RREG_RC_714                   /* register undefined */
#define Iodd_RREG_RC_715                   /* register undefined */

#define Iodd_WREG_RC_70(Value)             /* register undefined */
#define Iodd_WREG_RC_71(Value)             /* register undefined */
#define Iodd_WREG_RC_72(Value)             /* register undefined */
#define Iodd_WREG_RC_73(Value)             /* register undefined */
#define Iodd_WREG_RC_74(Value)             /* register undefined */
#define Iodd_WREG_RC_75(Value)             /* register undefined */
#define Iodd_WREG_RC_76(Value)             /* register undefined */
#define Iodd_WREG_RC_77(Value)             /* register undefined */
#define Iodd_WREG_RC_78(Value)             /* register undefined */
#define Iodd_WREG_RC_79(Value)             /* register undefined */
#define Iodd_WREG_RC_710(Value)            /* register undefined */
#define Iodd_WREG_RC_711(Value)            /* register undefined */
#define Iodd_WREG_RC_712(Value)            /* register undefined */
#define Iodd_WREG_RC_713(Value)            /* register undefined */
#define Iodd_WREG_RC_714(Value)            /* register undefined */
#define Iodd_WREG_RC_715(Value)            /* register undefined */

#endif

/* Definitions PORT 8 */

#if                                          \
      defined(__NEC_V850_DJ3__)||            \
      defined(__NEC_V850_DL3__)

#define Iodd_RREG_P_80                       TARG_ReadBit(P8, BIT0)
#define Iodd_RREG_P_81                       TARG_ReadBit(P8, BIT1)
#define Iodd_RREG_P_82                       TARG_ReadBit(P8, BIT2)
#define Iodd_RREG_P_83                       TARG_ReadBit(P8, BIT3)
#define Iodd_RREG_P_84                       TARG_ReadBit(P8, BIT4)
#define Iodd_RREG_P_85                       TARG_ReadBit(P8, BIT5)
#define Iodd_RREG_P_86                       TARG_ReadBit(P8, BIT6)
#define Iodd_RREG_P_87                       TARG_ReadBit(P8, BIT7)

#define Iodd_WREG_P_80(Value)                TARG_WriteBit(P8, BIT0, Value)
#define Iodd_WREG_P_81(Value)                TARG_WriteBit(P8, BIT1, Value)
#define Iodd_WREG_P_82(Value)                TARG_WriteBit(P8, BIT2, Value)
#define Iodd_WREG_P_83(Value)                TARG_WriteBit(P8, BIT3, Value)
#define Iodd_WREG_P_84(Value)                TARG_WriteBit(P8, BIT4, Value)
#define Iodd_WREG_P_85(Value)                TARG_WriteBit(P8, BIT5, Value)
#define Iodd_WREG_P_86(Value)                TARG_WriteBit(P8, BIT6, Value)
#define Iodd_WREG_P_87(Value)                TARG_WriteBit(P8, BIT7, Value)

#endif /* defined(__NEC_V850_DJ3__) || defined(__NEC_V850_DL3__) */

#if                                          \
      defined(__NEC_V850_DG3__)

#define Iodd_RREG_P_80                       TARG_ReadBit(P8, BIT0)
#define Iodd_RREG_P_81                       TARG_ReadBit(P8, BIT1)
#define Iodd_RREG_P_82                       TARG_ReadBit(P8, BIT2)
#define Iodd_RREG_P_83                       TARG_ReadBit(P8, BIT3)
#define Iodd_RREG_P_84                       /* read access defined but should not be used */
#define Iodd_RREG_P_85                       TARG_ReadBit(P8, BIT5)
#define Iodd_RREG_P_86                       TARG_ReadBit(P8, BIT6)
#define Iodd_RREG_P_87                       TARG_ReadBit(P8, BIT7)

#define Iodd_WREG_P_80(Value)                TARG_WriteBit(P8, BIT0, Value)
#define Iodd_WREG_P_81(Value)                TARG_WriteBit(P8, BIT1, Value)
#define Iodd_WREG_P_82(Value)                TARG_WriteBit(P8, BIT2, Value)
#define Iodd_WREG_P_83(Value)                TARG_WriteBit(P8, BIT3, Value)
#define Iodd_WREG_P_84(Value)                /* write access not defined */
#define Iodd_WREG_P_85(Value)                TARG_WriteBit(P8, BIT5, Value)
#define Iodd_WREG_P_86(Value)                TARG_WriteBit(P8, BIT6, Value)
#define Iodd_WREG_P_87(Value)                TARG_WriteBit(P8, BIT7, Value)

#endif /* defined(__NEC_V850_DG3__) */

#if                                          \
      defined(__NEC_V850_DJ3__)||            \
      defined(__NEC_V850_DL3__)

#define Iodd_RREG_M_80                       TARG_ReadBit(PM8, BIT0)
#define Iodd_RREG_M_81                       TARG_ReadBit(PM8, BIT1)
#define Iodd_RREG_M_82                       TARG_ReadBit(PM8, BIT2)
#define Iodd_RREG_M_83                       TARG_ReadBit(PM8, BIT3)
#define Iodd_RREG_M_84                       TARG_ReadBit(PM8, BIT4)
#define Iodd_RREG_M_85                       TARG_ReadBit(PM8, BIT5)
#define Iodd_RREG_M_86                       TARG_ReadBit(PM8, BIT6)
#define Iodd_RREG_M_87                       TARG_ReadBit(PM8, BIT7)

#define Iodd_WREG_M_80(Value)                TARG_WriteBit(PM8, BIT0, Value)
#define Iodd_WREG_M_81(Value)                TARG_WriteBit(PM8, BIT1, Value)
#define Iodd_WREG_M_82(Value)                TARG_WriteBit(PM8, BIT2, Value)
#define Iodd_WREG_M_83(Value)                TARG_WriteBit(PM8, BIT3, Value)
#define Iodd_WREG_M_84(Value)                TARG_WriteBit(PM8, BIT4, Value)
#define Iodd_WREG_M_85(Value)                TARG_WriteBit(PM8, BIT5, Value)
#define Iodd_WREG_M_86(Value)                TARG_WriteBit(PM8, BIT6, Value)
#define Iodd_WREG_M_87(Value)                TARG_WriteBit(PM8, BIT7, Value)

#endif /* defined(__NEC_V850_DJ3__) || defined(__NEC_V850_DL3__) */

#if                                          \
      defined(__NEC_V850_DG3__)

#define Iodd_RREG_M_80                       TARG_ReadBit(PM8, BIT0)
#define Iodd_RREG_M_81                       TARG_ReadBit(PM8, BIT1)
#define Iodd_RREG_M_82                       TARG_ReadBit(PM8, BIT2)
#define Iodd_RREG_M_83                       TARG_ReadBit(PM8, BIT3)
#define Iodd_RREG_M_84                       /* read access defined but should not be used */
#define Iodd_RREG_M_85                       TARG_ReadBit(PM8, BIT5)
#define Iodd_RREG_M_86                       TARG_ReadBit(PM8, BIT6)
#define Iodd_RREG_M_87                       TARG_ReadBit(PM8, BIT7)

#define Iodd_WREG_M_80(Value)                TARG_WriteBit(PM8, BIT0, Value)
#define Iodd_WREG_M_81(Value)                TARG_WriteBit(PM8, BIT1, Value)
#define Iodd_WREG_M_82(Value)                TARG_WriteBit(PM8, BIT2, Value)
#define Iodd_WREG_M_83(Value)                TARG_WriteBit(PM8, BIT3, Value)
#define Iodd_WREG_M_84(Value)                /* write access not defined */
#define Iodd_WREG_M_85(Value)                TARG_WriteBit(PM8, BIT5, Value)
#define Iodd_WREG_M_86(Value)                TARG_WriteBit(PM8, BIT6, Value)
#define Iodd_WREG_M_87(Value)                TARG_WriteBit(PM8, BIT7, Value)

#endif /* defined(__NEC_V850_DG3__) */

#if                                          \
      defined(__NEC_V850_DJ3__)||            \
      defined(__NEC_V850_DL3__)

#define Iodd_RREG_MC_80                       TARG_ReadBit(PMC8, BIT0)
#define Iodd_RREG_MC_81                       TARG_ReadBit(PMC8, BIT1)
#define Iodd_RREG_MC_82                       TARG_ReadBit(PMC8, BIT2)
#define Iodd_RREG_MC_83                       TARG_ReadBit(PMC8, BIT3)
#define Iodd_RREG_MC_84                       TARG_ReadBit(PMC8, BIT4)
#define Iodd_RREG_MC_85                       TARG_ReadBit(PMC8, BIT5)
#define Iodd_RREG_MC_86                       TARG_ReadBit(PMC8, BIT6)
#define Iodd_RREG_MC_87                       TARG_ReadBit(PMC8, BIT7)

#define Iodd_WREG_MC_80(Value)                TARG_WriteBit(PMC8, BIT0, Value)
#define Iodd_WREG_MC_81(Value)                TARG_WriteBit(PMC8, BIT1, Value)
#define Iodd_WREG_MC_82(Value)                TARG_WriteBit(PMC8, BIT2, Value)
#define Iodd_WREG_MC_83(Value)                TARG_WriteBit(PMC8, BIT3, Value)
#define Iodd_WREG_MC_84(Value)                TARG_WriteBit(PMC8, BIT4, Value)
#define Iodd_WREG_MC_85(Value)                TARG_WriteBit(PMC8, BIT5, Value)
#define Iodd_WREG_MC_86(Value)                TARG_WriteBit(PMC8, BIT6, Value)
#define Iodd_WREG_MC_87(Value)                TARG_WriteBit(PMC8, BIT7, Value)

#endif /* defined(__NEC_V850_DJ3__) || defined(__NEC_V850_DL3__) */

#if                                          \
      defined(__NEC_V850_DG3__)

#define Iodd_RREG_MC_80                       /* read access defined but should not be used */
#define Iodd_RREG_MC_81                       /* read access defined but should not be used */
#define Iodd_RREG_MC_82                       /* read access defined but should not be used */
#define Iodd_RREG_MC_83                       TARG_ReadBit(PMC8, BIT3)
#define Iodd_RREG_MC_84                       /* read access defined but should not be used */
#define Iodd_RREG_MC_85                       TARG_ReadBit(PMC8, BIT5)
#define Iodd_RREG_MC_86                       TARG_ReadBit(PMC8, BIT6)
#define Iodd_RREG_MC_87                       TARG_ReadBit(PMC8, BIT7)

#define Iodd_WREG_MC_80(Value)                /* write access not defined */
#define Iodd_WREG_MC_81(Value)                /* write access not defined */
#define Iodd_WREG_MC_82(Value)                /* write access not defined */
#define Iodd_WREG_MC_83(Value)                TARG_WriteBit(PMC8, BIT3, Value)
#define Iodd_WREG_MC_84(Value)                /* write access not defined */
#define Iodd_WREG_MC_85(Value)                TARG_WriteBit(PMC8, BIT5, Value)
#define Iodd_WREG_MC_86(Value)                TARG_WriteBit(PMC8, BIT6, Value)
#define Iodd_WREG_MC_87(Value)                TARG_WriteBit(PMC8, BIT7, Value)

#endif /* defined(__NEC_V850_DG3__) */

#if                                          \
      defined(__NEC_V850_DL3__)

#define Iodd_RREG_DSC_80                     TARG_ReadBit(PDSC8, BIT0)
#define Iodd_RREG_DSC_81                     TARG_ReadBit(PDSC8, BIT1)
#define Iodd_RREG_DSC_82                     TARG_ReadBit(PDSC8, BIT2)
#define Iodd_RREG_DSC_83                     TARG_ReadBit(PDSC8, BIT3)
#define Iodd_RREG_DSC_84                     TARG_ReadBit(PDSC8, BIT4)
#define Iodd_RREG_DSC_85                     TARG_ReadBit(PDSC8, BIT5)
#define Iodd_RREG_DSC_86                     /* read access defined but should not be used */
#define Iodd_RREG_DSC_87                     /* read access defined but should not be used */

#define Iodd_WREG_DSC_80(Value)              TARG_WriteBit(PDSC8, BIT0, Value)
#define Iodd_WREG_DSC_81(Value)              TARG_WriteBit(PDSC8, BIT1, Value)
#define Iodd_WREG_DSC_82(Value)              TARG_WriteBit(PDSC8, BIT2, Value)
#define Iodd_WREG_DSC_83(Value)              TARG_WriteBit(PDSC8, BIT3, Value)
#define Iodd_WREG_DSC_84(Value)              TARG_WriteBit(PDSC8, BIT4, Value)
#define Iodd_WREG_DSC_85(Value)              TARG_WriteBit(PDSC8, BIT5, Value)
#define Iodd_WREG_DSC_86(Value)              /* write access not defined */
#define Iodd_WREG_DSC_87(Value)              /* write access not defined */

#endif /* defined(__NEC_V850_DL3__) */

#if                                          \
      defined(__NEC_V850_DJ3__)

#define Iodd_RREG_DSC_80                     TARG_ReadBit(PDSC8, BIT0)
#define Iodd_RREG_DSC_81                     TARG_ReadBit(PDSC8, BIT1)
#define Iodd_RREG_DSC_82                     TARG_ReadBit(PDSC8, BIT2)
#define Iodd_RREG_DSC_83                     TARG_ReadBit(PDSC8, BIT3)
#define Iodd_RREG_DSC_84                     TARG_ReadBit(PDSC8, BIT4)
#define Iodd_RREG_DSC_85                     TARG_ReadBit(PDSC8, BIT5)
#define Iodd_RREG_DSC_86                     TARG_ReadBit(PDSC8, BIT6)
#define Iodd_RREG_DSC_87                     TARG_ReadBit(PDSC8, BIT7)

#define Iodd_WREG_DSC_80(Value)              TARG_WriteBit(PDSC8, BIT0, Value)
#define Iodd_WREG_DSC_81(Value)              TARG_WriteBit(PDSC8, BIT1, Value)
#define Iodd_WREG_DSC_82(Value)              TARG_WriteBit(PDSC8, BIT2, Value)
#define Iodd_WREG_DSC_83(Value)              TARG_WriteBit(PDSC8, BIT3, Value)
#define Iodd_WREG_DSC_84(Value)              TARG_WriteBit(PDSC8, BIT4, Value)
#define Iodd_WREG_DSC_85(Value)              TARG_WriteBit(PDSC8, BIT5, Value)
#define Iodd_WREG_DSC_86(Value)              TARG_WriteBit(PDSC8, BIT6, Value)
#define Iodd_WREG_DSC_87(Value)              TARG_WriteBit(PDSC8, BIT7, Value)

#endif /* defined(__NEC_V850_DJ3__) */

#if                                          \
      defined(__NEC_V850_DG3__)

#define Iodd_RREG_DSC_80                     TARG_ReadBit(PDSC8, BIT0)
#define Iodd_RREG_DSC_81                     TARG_ReadBit(PDSC8, BIT1)
#define Iodd_RREG_DSC_82                     TARG_ReadBit(PDSC8, BIT2)
#define Iodd_RREG_DSC_83                     TARG_ReadBit(PDSC8, BIT3)
#define Iodd_RREG_DSC_84                     /* read access defined but should not be used */
#define Iodd_RREG_DSC_85                     TARG_ReadBit(PDSC8, BIT5)
#define Iodd_RREG_DSC_86                     TARG_ReadBit(PDSC8, BIT6)
#define Iodd_RREG_DSC_87                     TARG_ReadBit(PDSC8, BIT7)

#define Iodd_WREG_DSC_80(Value)              TARG_WriteBit(PDSC8, BIT0, Value)
#define Iodd_WREG_DSC_81(Value)              TARG_WriteBit(PDSC8, BIT1, Value)
#define Iodd_WREG_DSC_82(Value)              TARG_WriteBit(PDSC8, BIT2, Value)
#define Iodd_WREG_DSC_83(Value)              TARG_WriteBit(PDSC8, BIT3, Value)
#define Iodd_WREG_DSC_84(Value)              /* write access not defined */
#define Iodd_WREG_DSC_85(Value)              TARG_WriteBit(PDSC8, BIT5, Value)
#define Iodd_WREG_DSC_86(Value)              TARG_WriteBit(PDSC8, BIT6, Value)
#define Iodd_WREG_DSC_87(Value)              TARG_WriteBit(PDSC8, BIT7, Value)

#endif /* defined(__NEC_V850_DG3__) */

#if                                          \
      defined(__NEC_V850_DL3__)

#define Iodd_RREG_ICC_80                     TARG_ReadBit(PICC8, BIT0)
#define Iodd_RREG_ICC_81                     TARG_ReadBit(PICC8, BIT1)
#define Iodd_RREG_ICC_82                     TARG_ReadBit(PICC8, BIT2)
#define Iodd_RREG_ICC_83                     TARG_ReadBit(PICC8, BIT3)
#define Iodd_RREG_ICC_84                     TARG_ReadBit(PICC8, BIT4)
#define Iodd_RREG_ICC_85                     TARG_ReadBit(PICC8, BIT5)
#define Iodd_RREG_ICC_86                     /* read access defined but should not be used */
#define Iodd_RREG_ICC_87                     /* read access defined but should not be used */

#define Iodd_WREG_ICC_80(Value)              TARG_WriteBit(PICC8, BIT0, Value)
#define Iodd_WREG_ICC_81(Value)              TARG_WriteBit(PICC8, BIT1, Value)
#define Iodd_WREG_ICC_82(Value)              TARG_WriteBit(PICC8, BIT2, Value)
#define Iodd_WREG_ICC_83(Value)              TARG_WriteBit(PICC8, BIT3, Value)
#define Iodd_WREG_ICC_84(Value)              TARG_WriteBit(PICC8, BIT4, Value)
#define Iodd_WREG_ICC_85(Value)              TARG_WriteBit(PICC8, BIT5, Value)
#define Iodd_WREG_ICC_86(Value)              /* write access not defined */
#define Iodd_WREG_ICC_87(Value)              /* write access not defined */

#endif /* defined(__NEC_V850_DL3__) */

#if                                          \
      defined(__NEC_V850_DJ3__)

#define Iodd_RREG_ICC_80                     TARG_ReadBit(PICC8, BIT0)
#define Iodd_RREG_ICC_81                     TARG_ReadBit(PICC8, BIT1)
#define Iodd_RREG_ICC_82                     TARG_ReadBit(PICC8, BIT2)
#define Iodd_RREG_ICC_83                     TARG_ReadBit(PICC8, BIT3)
#define Iodd_RREG_ICC_84                     TARG_ReadBit(PICC8, BIT4)
#define Iodd_RREG_ICC_85                     TARG_ReadBit(PICC8, BIT5)
#define Iodd_RREG_ICC_86                     TARG_ReadBit(PICC8, BIT6)
#define Iodd_RREG_ICC_87                     TARG_ReadBit(PICC8, BIT7)

#define Iodd_WREG_ICC_80(Value)              TARG_WriteBit(PICC8, BIT0, Value)
#define Iodd_WREG_ICC_81(Value)              TARG_WriteBit(PICC8, BIT1, Value)
#define Iodd_WREG_ICC_82(Value)              TARG_WriteBit(PICC8, BIT2, Value)
#define Iodd_WREG_ICC_83(Value)              TARG_WriteBit(PICC8, BIT3, Value)
#define Iodd_WREG_ICC_84(Value)              TARG_WriteBit(PICC8, BIT4, Value)
#define Iodd_WREG_ICC_85(Value)              TARG_WriteBit(PICC8, BIT5, Value)
#define Iodd_WREG_ICC_86(Value)              TARG_WriteBit(PICC8, BIT6, Value)
#define Iodd_WREG_ICC_87(Value)              TARG_WriteBit(PICC8, BIT7, Value)

#endif /* defined(__NEC_V850_DJ3__) */

#if                                          \
      defined(__NEC_V850_DG3__)

#define Iodd_RREG_ICC_80                     TARG_ReadBit(PICC8, BIT0)
#define Iodd_RREG_ICC_81                     TARG_ReadBit(PICC8, BIT1)
#define Iodd_RREG_ICC_82                     TARG_ReadBit(PICC8, BIT2)
#define Iodd_RREG_ICC_83                     TARG_ReadBit(PICC8, BIT3)
#define Iodd_RREG_ICC_84                     /* read access defined but should not be used */
#define Iodd_RREG_ICC_85                     TARG_ReadBit(PICC8, BIT5)
#define Iodd_RREG_ICC_86                     TARG_ReadBit(PICC8, BIT6)
#define Iodd_RREG_ICC_87                     TARG_ReadBit(PICC8, BIT7)

#define Iodd_WREG_ICC_80(Value)              TARG_WriteBit(PICC8, BIT0, Value)
#define Iodd_WREG_ICC_81(Value)              TARG_WriteBit(PICC8, BIT1, Value)
#define Iodd_WREG_ICC_82(Value)              TARG_WriteBit(PICC8, BIT2, Value)
#define Iodd_WREG_ICC_83(Value)              TARG_WriteBit(PICC8, BIT3, Value)
#define Iodd_WREG_ICC_84(Value)              /* write access not defined */
#define Iodd_WREG_ICC_85(Value)              TARG_WriteBit(PICC8, BIT5, Value)
#define Iodd_WREG_ICC_86(Value)              TARG_WriteBit(PICC8, BIT6, Value)
#define Iodd_WREG_ICC_87(Value)              TARG_WriteBit(PICC8, BIT7, Value)

#endif /* defined(__NEC_V850_DG3__) */

#if                                          \
      defined(__NEC_V850_DL3__)

#define Iodd_RREG_ILC_80                     TARG_ReadBit(PILC8, BIT0)
#define Iodd_RREG_ILC_81                     TARG_ReadBit(PILC8, BIT1)
#define Iodd_RREG_ILC_82                     TARG_ReadBit(PILC8, BIT2)
#define Iodd_RREG_ILC_83                     TARG_ReadBit(PILC8, BIT3)
#define Iodd_RREG_ILC_84                     TARG_ReadBit(PILC8, BIT4)
#define Iodd_RREG_ILC_85                     TARG_ReadBit(PILC8, BIT5)
#define Iodd_RREG_ILC_86                     /* read access defined but should not be used */
#define Iodd_RREG_ILC_87                     /* read access defined but should not be used */

#define Iodd_WREG_ILC_80(Value)              TARG_WriteBit(PILC8, BIT0, Value)
#define Iodd_WREG_ILC_81(Value)              TARG_WriteBit(PILC8, BIT1, Value)
#define Iodd_WREG_ILC_82(Value)              TARG_WriteBit(PILC8, BIT2, Value)
#define Iodd_WREG_ILC_83(Value)              TARG_WriteBit(PILC8, BIT3, Value)
#define Iodd_WREG_ILC_84(Value)              TARG_WriteBit(PILC8, BIT4, Value)
#define Iodd_WREG_ILC_85(Value)              TARG_WriteBit(PILC8, BIT5, Value)
#define Iodd_WREG_ILC_86(Value)              /* write access not defined */
#define Iodd_WREG_ILC_87(Value)              /* write access not defined */

#endif /* defined(__NEC_V850_DL3__) */

#if                                          \
      defined(__NEC_V850_DJ3__)

#define Iodd_RREG_ILC_80                     TARG_ReadBit(PILC8, BIT0)
#define Iodd_RREG_ILC_81                     TARG_ReadBit(PILC8, BIT1)
#define Iodd_RREG_ILC_82                     TARG_ReadBit(PILC8, BIT2)
#define Iodd_RREG_ILC_83                     TARG_ReadBit(PILC8, BIT3)
#define Iodd_RREG_ILC_84                     TARG_ReadBit(PILC8, BIT4)
#define Iodd_RREG_ILC_85                     TARG_ReadBit(PILC8, BIT5)
#define Iodd_RREG_ILC_86                     TARG_ReadBit(PILC8, BIT6)
#define Iodd_RREG_ILC_87                     TARG_ReadBit(PILC8, BIT7)

#define Iodd_WREG_ILC_80(Value)              TARG_WriteBit(PILC8, BIT0, Value)
#define Iodd_WREG_ILC_81(Value)              TARG_WriteBit(PILC8, BIT1, Value)
#define Iodd_WREG_ILC_82(Value)              TARG_WriteBit(PILC8, BIT2, Value)
#define Iodd_WREG_ILC_83(Value)              TARG_WriteBit(PILC8, BIT3, Value)
#define Iodd_WREG_ILC_84(Value)              TARG_WriteBit(PILC8, BIT4, Value)
#define Iodd_WREG_ILC_85(Value)              TARG_WriteBit(PILC8, BIT5, Value)
#define Iodd_WREG_ILC_86(Value)              TARG_WriteBit(PILC8, BIT6, Value)
#define Iodd_WREG_ILC_87(Value)              TARG_WriteBit(PILC8, BIT7, Value)

#endif /* defined(__NEC_V850_DJ3__) */

#if                                          \
      defined(__NEC_V850_DG3__)

#define Iodd_RREG_ILC_80                     TARG_ReadBit(PILC8, BIT0)
#define Iodd_RREG_ILC_81                     TARG_ReadBit(PILC8, BIT1)
#define Iodd_RREG_ILC_82                     TARG_ReadBit(PILC8, BIT2)
#define Iodd_RREG_ILC_83                     TARG_ReadBit(PILC8, BIT3)
#define Iodd_RREG_ILC_84                     /* read access defined but should not be used */
#define Iodd_RREG_ILC_85                     TARG_ReadBit(PILC8, BIT5)
#define Iodd_RREG_ILC_86                     TARG_ReadBit(PILC8, BIT6)
#define Iodd_RREG_ILC_87                     TARG_ReadBit(PILC8, BIT7)

#define Iodd_WREG_ILC_80(Value)              TARG_WriteBit(PILC8, BIT0, Value)
#define Iodd_WREG_ILC_81(Value)              TARG_WriteBit(PILC8, BIT1, Value)
#define Iodd_WREG_ILC_82(Value)              TARG_WriteBit(PILC8, BIT2, Value)
#define Iodd_WREG_ILC_83(Value)              TARG_WriteBit(PILC8, BIT3, Value)
#define Iodd_WREG_ILC_84(Value)              /* write access not defined */
#define Iodd_WREG_ILC_85(Value)              TARG_WriteBit(PILC8, BIT5, Value)
#define Iodd_WREG_ILC_86(Value)              TARG_WriteBit(PILC8, BIT6, Value)
#define Iodd_WREG_ILC_87(Value)              TARG_WriteBit(PILC8, BIT7, Value)

#endif /* defined(__NEC_V850_DG3__) */

#if                                          \
      defined(__NEC_V850_DJ3__)||            \
      defined(__NEC_V850_DL3__)

#define Iodd_RREG_ODC_80                     TARG_ReadBit(PODC8, BIT0)
#define Iodd_RREG_ODC_81                     TARG_ReadBit(PODC8, BIT1)
#define Iodd_RREG_ODC_82                     TARG_ReadBit(PODC8, BIT2)
#define Iodd_RREG_ODC_83                     TARG_ReadBit(PODC8, BIT3)
#define Iodd_RREG_ODC_84                     TARG_ReadBit(PODC8, BIT4)
#define Iodd_RREG_ODC_85                     TARG_ReadBit(PODC8, BIT5)
#define Iodd_RREG_ODC_86                     TARG_ReadBit(PODC8, BIT6)
#define Iodd_RREG_ODC_87                     TARG_ReadBit(PODC8, BIT7)

#define Iodd_WREG_ODC_80(Value)              TARG_WriteBit(PODC8, BIT0, Value)
#define Iodd_WREG_ODC_81(Value)              TARG_WriteBit(PODC8, BIT1, Value)
#define Iodd_WREG_ODC_82(Value)              TARG_WriteBit(PODC8, BIT2, Value)
#define Iodd_WREG_ODC_83(Value)              TARG_WriteBit(PODC8, BIT3, Value)
#define Iodd_WREG_ODC_84(Value)              TARG_WriteBit(PODC8, BIT4, Value)
#define Iodd_WREG_ODC_85(Value)              TARG_WriteBit(PODC8, BIT5, Value)
#define Iodd_WREG_ODC_86(Value)              TARG_WriteBit(PODC8, BIT6, Value)
#define Iodd_WREG_ODC_87(Value)              TARG_WriteBit(PODC8, BIT7, Value)

#endif /* defined(__NEC_V850_DJ3__) || defined(__NEC_V850_DL3__) */

#if                                          \
      defined(__NEC_V850_DG3__)

#define Iodd_RREG_ODC_80                     TARG_ReadBit(PODC8, BIT0)
#define Iodd_RREG_ODC_81                     TARG_ReadBit(PODC8, BIT1)
#define Iodd_RREG_ODC_82                     TARG_ReadBit(PODC8, BIT2)
#define Iodd_RREG_ODC_83                     TARG_ReadBit(PODC8, BIT3)
#define Iodd_RREG_ODC_84                     /* read access defined but should not be used */
#define Iodd_RREG_ODC_85                     TARG_ReadBit(PODC8, BIT5)
#define Iodd_RREG_ODC_86                     TARG_ReadBit(PODC8, BIT6)
#define Iodd_RREG_ODC_87                     TARG_ReadBit(PODC8, BIT7)

#define Iodd_WREG_ODC_80(Value)              TARG_WriteBit(PODC8, BIT0, Value)
#define Iodd_WREG_ODC_81(Value)              TARG_WriteBit(PODC8, BIT1, Value)
#define Iodd_WREG_ODC_82(Value)              TARG_WriteBit(PODC8, BIT2, Value)
#define Iodd_WREG_ODC_83(Value)              TARG_WriteBit(PODC8, BIT3, Value)
#define Iodd_WREG_ODC_84(Value)              /* write access not defined */
#define Iodd_WREG_ODC_85(Value)              TARG_WriteBit(PODC8, BIT5, Value)
#define Iodd_WREG_ODC_86(Value)              TARG_WriteBit(PODC8, BIT6, Value)
#define Iodd_WREG_ODC_87(Value)              TARG_WriteBit(PODC8, BIT7, Value)

#endif /* defined(__NEC_V850_DG3__) */

#if                                          \
      defined(__NEC_V850_DJ3__)||            \
      defined(__NEC_V850_DL3__)

#define Iodd_RREG_FC_80                      /* register undefined */
#define Iodd_RREG_FC_81                      /* register undefined */
#define Iodd_RREG_FC_82                      /* register undefined */
#define Iodd_RREG_FC_83                      /* register undefined */
#define Iodd_RREG_FC_84                      /* register undefined */
#define Iodd_RREG_FC_85                      /* register undefined */
#define Iodd_RREG_FC_86                      /* register undefined */
#define Iodd_RREG_FC_87                      /* register undefined */

#define Iodd_WREG_FC_80(Value)               /* register undefined */
#define Iodd_WREG_FC_81(Value)               /* register undefined */
#define Iodd_WREG_FC_82(Value)               /* register undefined */
#define Iodd_WREG_FC_83(Value)               /* register undefined */
#define Iodd_WREG_FC_84(Value)               /* register undefined */
#define Iodd_WREG_FC_85(Value)               /* register undefined */
#define Iodd_WREG_FC_86(Value)               /* register undefined */
#define Iodd_WREG_FC_87(Value)               /* register undefined */

#endif /* defined(__NEC_V850_DJ3__) || defined(__NEC_V850_DL3__) */

#if                                          \
      defined(__NEC_V850_DG3__)

#define Iodd_RREG_FC_80                      /* read access defined but should not be used */
#define Iodd_RREG_FC_81                      /* read access defined but should not be used */
#define Iodd_RREG_FC_82                      /* read access defined but should not be used */
#define Iodd_RREG_FC_83                      TARG_ReadBit(PFC8, BIT3)
#define Iodd_RREG_FC_84                      /* read access defined but should not be used */
#define Iodd_RREG_FC_85                      /* read access defined but should not be used */
#define Iodd_RREG_FC_86                      /* read access defined but should not be used */
#define Iodd_RREG_FC_87                      /* read access defined but should not be used */

#define Iodd_WREG_FC_80(Value)               /* write access not defined */
#define Iodd_WREG_FC_81(Value)               /* write access not defined */
#define Iodd_WREG_FC_82(Value)               /* write access not defined */
#define Iodd_WREG_FC_83(Value)               TARG_WriteBit(PFC8, BIT3, Value)
#define Iodd_WREG_FC_84(Value)               /* write access not defined */
#define Iodd_WREG_FC_85(Value)               /* write access not defined */
#define Iodd_WREG_FC_86(Value)               /* write access not defined */
#define Iodd_WREG_FC_87(Value)               /* write access not defined */

#endif /* defined(__NEC_V850_DG3__) */

#if                                          \
      defined(__NEC_V850_DJ3__)||            \
      defined(__NEC_V850_DL3__)

#define Iodd_RREG_PR_80                     TARG_ReadBit(PPR8, BIT0)
#define Iodd_RREG_PR_81                     TARG_ReadBit(PPR8, BIT1)
#define Iodd_RREG_PR_82                     TARG_ReadBit(PPR8, BIT2)
#define Iodd_RREG_PR_83                     TARG_ReadBit(PPR8, BIT3)
#define Iodd_RREG_PR_84                     TARG_ReadBit(PPR8, BIT4)
#define Iodd_RREG_PR_85                     TARG_ReadBit(PPR8, BIT5)
#define Iodd_RREG_PR_86                     TARG_ReadBit(PPR8, BIT6)
#define Iodd_RREG_PR_87                     TARG_ReadBit(PPR8, BIT7)

#define Iodd_WREG_PR_80(Value)              /* write access not defined */
#define Iodd_WREG_PR_81(Value)              /* write access not defined */
#define Iodd_WREG_PR_82(Value)              /* write access not defined */
#define Iodd_WREG_PR_83(Value)              /* write access not defined */
#define Iodd_WREG_PR_84(Value)              /* write access not defined */
#define Iodd_WREG_PR_85(Value)              /* write access not defined */
#define Iodd_WREG_PR_86(Value)              /* write access not defined */
#define Iodd_WREG_PR_87(Value)              /* write access not defined */

#endif /* defined(__NEC_V850_DJ3__) || defined(__NEC_V850_DL3__) */

#if                                          \
      defined(__NEC_V850_DG3__)

#define Iodd_RREG_PR_80                     TARG_ReadBit(PPR8, BIT0)
#define Iodd_RREG_PR_81                     TARG_ReadBit(PPR8, BIT1)
#define Iodd_RREG_PR_82                     TARG_ReadBit(PPR8, BIT2)
#define Iodd_RREG_PR_83                     TARG_ReadBit(PPR8, BIT3)
#define Iodd_RREG_PR_84                     /* read access defined but should not be used */
#define Iodd_RREG_PR_85                     TARG_ReadBit(PPR8, BIT5)
#define Iodd_RREG_PR_86                     TARG_ReadBit(PPR8, BIT6)
#define Iodd_RREG_PR_87                     TARG_ReadBit(PPR8, BIT7)

#define Iodd_WREG_PR_80(Value)              /* write access not defined */
#define Iodd_WREG_PR_81(Value)              /* write access not defined */
#define Iodd_WREG_PR_82(Value)              /* write access not defined */
#define Iodd_WREG_PR_83(Value)              /* write access not defined */
#define Iodd_WREG_PR_84(Value)              /* write access not defined */
#define Iodd_WREG_PR_85(Value)              /* write access not defined */
#define Iodd_WREG_PR_86(Value)              /* write access not defined */
#define Iodd_WREG_PR_87(Value)              /* write access not defined */

#endif /* defined(__NEC_V850_DG3__) */

#if                                          \
      defined(__NEC_V850_DG3__)||            \
      defined(__NEC_V850_DJ3_LE__)

#define Iodd_RREG_LCDC_80                    TARG_ReadBit(PLCDC8, BIT0)
#define Iodd_RREG_LCDC_81                    TARG_ReadBit(PLCDC8, BIT1)
#define Iodd_RREG_LCDC_82                    TARG_ReadBit(PLCDC8, BIT2)
#define Iodd_RREG_LCDC_83                    TARG_ReadBit(PLCDC8, BIT3)
#define Iodd_RREG_LCDC_84                    /* read access defined but should not be used */
#define Iodd_RREG_LCDC_85                    TARG_ReadBit(PLCDC8, BIT5)
#define Iodd_RREG_LCDC_86                    TARG_ReadBit(PLCDC8, BIT6)
#define Iodd_RREG_LCDC_87                    TARG_ReadBit(PLCDC8, BIT7)

#define Iodd_WREG_LCDC_80(Value)             TARG_WriteBit(PLCDC8, BIT0, Value)
#define Iodd_WREG_LCDC_81(Value)             TARG_WriteBit(PLCDC8, BIT1, Value)
#define Iodd_WREG_LCDC_82(Value)             TARG_WriteBit(PLCDC8, BIT2, Value)
#define Iodd_WREG_LCDC_83(Value)             TARG_WriteBit(PLCDC8, BIT3, Value)
#define Iodd_WREG_LCDC_84(Value)             /* write access not defined */
#define Iodd_WREG_LCDC_85(Value)             TARG_WriteBit(PLCDC8, BIT5, Value)
#define Iodd_WREG_LCDC_86(Value)             TARG_WriteBit(PLCDC8, BIT6, Value)
#define Iodd_WREG_LCDC_87(Value)             TARG_WriteBit(PLCDC8, BIT7, Value)

#endif /* defined(__NEC_V850_DG3__) || defined(__NEC_V850_DJ3_LE__) */

#if                                          \
      defined(__NEC_V850_DL3__)||            \
      defined(__NEC_V850_DJ3_HE__)

#define Iodd_RREG_LCDC_80                    /* register undefined */
#define Iodd_RREG_LCDC_81                    /* register undefined */
#define Iodd_RREG_LCDC_82                    /* register undefined */
#define Iodd_RREG_LCDC_83                    /* register undefined */
#define Iodd_RREG_LCDC_84                    /* register undefined */
#define Iodd_RREG_LCDC_85                    /* register undefined */
#define Iodd_RREG_LCDC_86                    /* register undefined */
#define Iodd_RREG_LCDC_87                    /* register undefined */

#define Iodd_WREG_LCDC_80(Value)             /* register undefined */
#define Iodd_WREG_LCDC_81(Value)             /* register undefined */
#define Iodd_WREG_LCDC_82(Value)             /* register undefined */
#define Iodd_WREG_LCDC_83(Value)             /* register undefined */
#define Iodd_WREG_LCDC_84(Value)             /* register undefined */
#define Iodd_WREG_LCDC_85(Value)             /* register undefined */
#define Iodd_WREG_LCDC_86(Value)             /* register undefined */
#define Iodd_WREG_LCDC_87(Value)             /* register undefined */

#endif /* defined(__NEC_V850_DL3__) || defined(__NEC_V850_DJ3_HE__) */

#if                                          \
      defined(__NEC_V850_DJ3__)||            \
      defined(__NEC_V850_DL3__)

#define Iodd_RREG_RC_80                     /* register undefined */
#define Iodd_RREG_RC_81                     /* register undefined */
#define Iodd_RREG_RC_82                     /* register undefined */
#define Iodd_RREG_RC_83                     /* register undefined */
#define Iodd_RREG_RC_84                     /* register undefined */
#define Iodd_RREG_RC_85                     /* register undefined */
#define Iodd_RREG_RC_86                     /* register undefined */
#define Iodd_RREG_RC_87                     /* register undefined */

#define Iodd_WREG_RC_80(Value)              /* register undefined */
#define Iodd_WREG_RC_81(Value)              /* register undefined */
#define Iodd_WREG_RC_82(Value)              /* register undefined */
#define Iodd_WREG_RC_83(Value)              /* register undefined */
#define Iodd_WREG_RC_84(Value)              /* register undefined */
#define Iodd_WREG_RC_85(Value)              /* register undefined */
#define Iodd_WREG_RC_86(Value)              /* register undefined */
#define Iodd_WREG_RC_87(Value)              /* register undefined */

#endif /* defined(__NEC_V850_DJ3__) || defined(__NEC_V850_DL3__) */

#if                                          \
      defined(__NEC_V850_DG3__)

#define Iodd_RREG_RC_80                     TARG_ReadBit(PRC8, BIT0)
#define Iodd_RREG_RC_81                     /* read access defined but should not be used */
#define Iodd_RREG_RC_82                     /* read access defined but should not be used */
#define Iodd_RREG_RC_83                     /* read access defined but should not be used */
#define Iodd_RREG_RC_84                     /* read access defined but should not be used */
#define Iodd_RREG_RC_85                     /* read access defined but should not be used */
#define Iodd_RREG_RC_86                     /* read access defined but should not be used */
#define Iodd_RREG_RC_87                     /* read access defined but should not be used */

#define Iodd_WREG_RC_80(Value)              TARG_WriteBit(PRC8, BIT0, Value)
#define Iodd_WREG_RC_81(Value)              /* write access not defined */
#define Iodd_WREG_RC_82(Value)              /* write access not defined */
#define Iodd_WREG_RC_83(Value)              /* write access not defined */
#define Iodd_WREG_RC_84(Value)              /* write access not defined */
#define Iodd_WREG_RC_85(Value)              /* write access not defined */
#define Iodd_WREG_RC_86(Value)              /* write access not defined */
#define Iodd_WREG_RC_87(Value)              /* write access not defined */

#endif /* defined(__NEC_V850_DG3__) */

/* Definitions PORT 9 */

#if                                          \
      defined(__NEC_V850_Dx3__)

#define Iodd_RREG_P_90                       TARG_ReadBit(P9, BIT0)
#define Iodd_RREG_P_91                       TARG_ReadBit(P9, BIT1)
#define Iodd_RREG_P_92                       TARG_ReadBit(P9, BIT2)
#define Iodd_RREG_P_93                       TARG_ReadBit(P9, BIT3)
#define Iodd_RREG_P_94                       TARG_ReadBit(P9, BIT4)
#define Iodd_RREG_P_95                       TARG_ReadBit(P9, BIT5)
#define Iodd_RREG_P_96                       TARG_ReadBit(P9, BIT6)
#define Iodd_RREG_P_97                       TARG_ReadBit(P9, BIT7)

#define Iodd_WREG_P_90(Value)                TARG_WriteBit(P9, BIT0, Value)
#define Iodd_WREG_P_91(Value)                TARG_WriteBit(P9, BIT1, Value)
#define Iodd_WREG_P_92(Value)                TARG_WriteBit(P9, BIT2, Value)
#define Iodd_WREG_P_93(Value)                TARG_WriteBit(P9, BIT3, Value)
#define Iodd_WREG_P_94(Value)                TARG_WriteBit(P9, BIT4, Value)
#define Iodd_WREG_P_95(Value)                TARG_WriteBit(P9, BIT5, Value)
#define Iodd_WREG_P_96(Value)                TARG_WriteBit(P9, BIT6, Value)
#define Iodd_WREG_P_97(Value)                TARG_WriteBit(P9, BIT7, Value)

#endif

#if                                          \
      defined(__NEC_V850_Dx3__)

#define Iodd_RREG_M_90                       TARG_ReadBit(PM9, BIT0)
#define Iodd_RREG_M_91                       TARG_ReadBit(PM9, BIT1)
#define Iodd_RREG_M_92                       TARG_ReadBit(PM9, BIT2)
#define Iodd_RREG_M_93                       TARG_ReadBit(PM9, BIT3)
#define Iodd_RREG_M_94                       TARG_ReadBit(PM9, BIT4)
#define Iodd_RREG_M_95                       TARG_ReadBit(PM9, BIT5)
#define Iodd_RREG_M_96                       TARG_ReadBit(PM9, BIT6)
#define Iodd_RREG_M_97                       TARG_ReadBit(PM9, BIT7)

#define Iodd_WREG_M_90(Value)                TARG_WriteBit(PM9, BIT0, Value)
#define Iodd_WREG_M_91(Value)                TARG_WriteBit(PM9, BIT1, Value)
#define Iodd_WREG_M_92(Value)                TARG_WriteBit(PM9, BIT2, Value)
#define Iodd_WREG_M_93(Value)                TARG_WriteBit(PM9, BIT3, Value)
#define Iodd_WREG_M_94(Value)                TARG_WriteBit(PM9, BIT4, Value)
#define Iodd_WREG_M_95(Value)                TARG_WriteBit(PM9, BIT5, Value)
#define Iodd_WREG_M_96(Value)                TARG_WriteBit(PM9, BIT6, Value)
#define Iodd_WREG_M_97(Value)                TARG_WriteBit(PM9, BIT7, Value)

#endif

#if                                          \
      defined(__NEC_V850_DJ3__)||            \
      defined(__NEC_V850_DL3__)

#define Iodd_RREG_MC_90                      TARG_ReadBit(PMC9, BIT0)
#define Iodd_RREG_MC_91                      TARG_ReadBit(PMC9, BIT1)
#define Iodd_RREG_MC_92                      TARG_ReadBit(PMC9, BIT2)
#define Iodd_RREG_MC_93                      TARG_ReadBit(PMC9, BIT3)
#define Iodd_RREG_MC_94                      TARG_ReadBit(PMC9, BIT4)
#define Iodd_RREG_MC_95                      TARG_ReadBit(PMC9, BIT5)
#define Iodd_RREG_MC_96                      TARG_ReadBit(PMC9, BIT6)
#define Iodd_RREG_MC_97                      TARG_ReadBit(PMC9, BIT7)

#define Iodd_WREG_MC_90(Value)               TARG_WriteBit(PMC9, BIT0, Value)
#define Iodd_WREG_MC_91(Value)               TARG_WriteBit(PMC9, BIT1, Value)
#define Iodd_WREG_MC_92(Value)               TARG_WriteBit(PMC9, BIT2, Value)
#define Iodd_WREG_MC_93(Value)               TARG_WriteBit(PMC9, BIT3, Value)
#define Iodd_WREG_MC_94(Value)               TARG_WriteBit(PMC9, BIT4, Value)
#define Iodd_WREG_MC_95(Value)               TARG_WriteBit(PMC9, BIT5, Value)
#define Iodd_WREG_MC_96(Value)               TARG_WriteBit(PMC9, BIT6, Value)
#define Iodd_WREG_MC_97(Value)               TARG_WriteBit(PMC9, BIT7, Value)

#endif /* defined(__NEC_V850_DJ3__) || defined(__NEC_V850_DL3__) */

#if                                          \
      defined(__NEC_V850_DG3__)

#define Iodd_RREG_MC_90                      TARG_ReadBit(PMC9, BIT0)
#define Iodd_RREG_MC_91                      TARG_ReadBit(PMC9, BIT1)
#define Iodd_RREG_MC_92                      TARG_ReadBit(PMC9, BIT2)
#define Iodd_RREG_MC_93                      /* read access defined but should not be used */
#define Iodd_RREG_MC_94                      /* read access defined but should not be used */
#define Iodd_RREG_MC_95                      /* read access defined but should not be used */
#define Iodd_RREG_MC_96                      /* read access defined but should not be used */
#define Iodd_RREG_MC_97                      /* read access defined but should not be used */

#define Iodd_WREG_MC_90(Value)               TARG_WriteBit(PMC9, BIT0, Value)
#define Iodd_WREG_MC_91(Value)               TARG_WriteBit(PMC9, BIT1, Value)
#define Iodd_WREG_MC_92(Value)               TARG_WriteBit(PMC9, BIT2, Value)
#define Iodd_WREG_MC_93(Value)               /* write access not defined */
#define Iodd_WREG_MC_94(Value)               /* write access not defined */
#define Iodd_WREG_MC_95(Value)               /* write access not defined */
#define Iodd_WREG_MC_96(Value)               /* write access not defined */
#define Iodd_WREG_MC_97(Value)               /* write access not defined */

#endif /* defined(__NEC_V850_DG3__) */

#if                                          \
      defined(__NEC_V850_DG3__)||            \
      defined(__NEC_V850_DJ3__)

#define Iodd_RREG_DSC_90                     TARG_ReadBit(PDSC9, BIT0)
#define Iodd_RREG_DSC_91                     TARG_ReadBit(PDSC9, BIT1)
#define Iodd_RREG_DSC_92                     TARG_ReadBit(PDSC9, BIT2)
#define Iodd_RREG_DSC_93                     TARG_ReadBit(PDSC9, BIT3)
#define Iodd_RREG_DSC_94                     TARG_ReadBit(PDSC9, BIT4)
#define Iodd_RREG_DSC_95                     TARG_ReadBit(PDSC9, BIT5)
#define Iodd_RREG_DSC_96                     TARG_ReadBit(PDSC9, BIT6)
#define Iodd_RREG_DSC_97                     TARG_ReadBit(PDSC9, BIT7)

#define Iodd_WREG_DSC_90(Value)              TARG_WriteBit(PDSC9, BIT0, Value)
#define Iodd_WREG_DSC_91(Value)              TARG_WriteBit(PDSC9, BIT1, Value)
#define Iodd_WREG_DSC_92(Value)              TARG_WriteBit(PDSC9, BIT2, Value)
#define Iodd_WREG_DSC_93(Value)              TARG_WriteBit(PDSC9, BIT3, Value)
#define Iodd_WREG_DSC_94(Value)              TARG_WriteBit(PDSC9, BIT4, Value)
#define Iodd_WREG_DSC_95(Value)              TARG_WriteBit(PDSC9, BIT5, Value)
#define Iodd_WREG_DSC_96(Value)              TARG_WriteBit(PDSC9, BIT6, Value)
#define Iodd_WREG_DSC_97(Value)              TARG_WriteBit(PDSC9, BIT7, Value)

#endif /* defined(__NEC_V850_DG3__) || defined(__NEC_V850_DJ3__) */

#if                                          \
      defined(__NEC_V850_DL3__)

#define Iodd_RREG_DSC_90                     /* register undefined */
#define Iodd_RREG_DSC_91                     /* register undefined */
#define Iodd_RREG_DSC_92                     /* register undefined */
#define Iodd_RREG_DSC_93                     /* register undefined */
#define Iodd_RREG_DSC_94                     /* register undefined */
#define Iodd_RREG_DSC_95                     /* register undefined */
#define Iodd_RREG_DSC_96                     /* register undefined */
#define Iodd_RREG_DSC_97                     /* register undefined */

#define Iodd_WREG_DSC_90(Value)              /* register undefined */
#define Iodd_WREG_DSC_91(Value)              /* register undefined */
#define Iodd_WREG_DSC_92(Value)              /* register undefined */
#define Iodd_WREG_DSC_93(Value)              /* register undefined */
#define Iodd_WREG_DSC_94(Value)              /* register undefined */
#define Iodd_WREG_DSC_95(Value)              /* register undefined */
#define Iodd_WREG_DSC_96(Value)              /* register undefined */
#define Iodd_WREG_DSC_97(Value)              /* register undefined */

#endif /* defined(__NEC_V850_DL3__) */

#if                                          \
      defined(__NEC_V850_DG3__)||            \
      defined(__NEC_V850_DJ3__)

#define Iodd_RREG_ICC_90                     TARG_ReadBit(PICC9, BIT0)
#define Iodd_RREG_ICC_91                     TARG_ReadBit(PICC9, BIT1)
#define Iodd_RREG_ICC_92                     TARG_ReadBit(PICC9, BIT2)
#define Iodd_RREG_ICC_93                     TARG_ReadBit(PICC9, BIT3)
#define Iodd_RREG_ICC_94                     TARG_ReadBit(PICC9, BIT4)
#define Iodd_RREG_ICC_95                     TARG_ReadBit(PICC9, BIT5)
#define Iodd_RREG_ICC_96                     TARG_ReadBit(PICC9, BIT6)
#define Iodd_RREG_ICC_97                     TARG_ReadBit(PICC9, BIT7)

#define Iodd_WREG_ICC_90(Value)              TARG_WriteBit(PICC9, BIT0, Value)
#define Iodd_WREG_ICC_91(Value)              TARG_WriteBit(PICC9, BIT1, Value)
#define Iodd_WREG_ICC_92(Value)              TARG_WriteBit(PICC9, BIT2, Value)
#define Iodd_WREG_ICC_93(Value)              TARG_WriteBit(PICC9, BIT3, Value)
#define Iodd_WREG_ICC_94(Value)              TARG_WriteBit(PICC9, BIT4, Value)
#define Iodd_WREG_ICC_95(Value)              TARG_WriteBit(PICC9, BIT5, Value)
#define Iodd_WREG_ICC_96(Value)              TARG_WriteBit(PICC9, BIT6, Value)
#define Iodd_WREG_ICC_97(Value)              TARG_WriteBit(PICC9, BIT7, Value)

#endif /* defined(__NEC_V850_DG3__) || defined(__NEC_V850_DJ3__) */

#if                                          \
      defined(__NEC_V850_DL3__)

#define Iodd_RREG_ICC_90                     /* register undefined */
#define Iodd_RREG_ICC_91                     /* register undefined */
#define Iodd_RREG_ICC_92                     /* register undefined */
#define Iodd_RREG_ICC_93                     /* register undefined */
#define Iodd_RREG_ICC_94                     /* register undefined */
#define Iodd_RREG_ICC_95                     /* register undefined */
#define Iodd_RREG_ICC_96                     /* register undefined */
#define Iodd_RREG_ICC_97                     /* register undefined */
                                                                     
#define Iodd_WREG_ICC_90(Value)              /* register undefined */
#define Iodd_WREG_ICC_91(Value)              /* register undefined */
#define Iodd_WREG_ICC_92(Value)              /* register undefined */
#define Iodd_WREG_ICC_93(Value)              /* register undefined */
#define Iodd_WREG_ICC_94(Value)              /* register undefined */
#define Iodd_WREG_ICC_95(Value)              /* register undefined */
#define Iodd_WREG_ICC_96(Value)              /* register undefined */
#define Iodd_WREG_ICC_97(Value)              /* register undefined */

#endif /* defined(__NEC_V850_DL3__) */

#if                                          \
      defined(__NEC_V850_Dx3__)

#define Iodd_RREG_ODC_90                     TARG_ReadBit(PODC9, BIT0)
#define Iodd_RREG_ODC_91                     TARG_ReadBit(PODC9, BIT1)
#define Iodd_RREG_ODC_92                     TARG_ReadBit(PODC9, BIT2)
#define Iodd_RREG_ODC_93                     TARG_ReadBit(PODC9, BIT3)
#define Iodd_RREG_ODC_94                     TARG_ReadBit(PODC9, BIT4)
#define Iodd_RREG_ODC_95                     TARG_ReadBit(PODC9, BIT5)
#define Iodd_RREG_ODC_96                     TARG_ReadBit(PODC9, BIT6)
#define Iodd_RREG_ODC_97                     TARG_ReadBit(PODC9, BIT7)

#define Iodd_WREG_ODC_90(Value)              TARG_WriteBit(PODC9, BIT0, Value)
#define Iodd_WREG_ODC_91(Value)              TARG_WriteBit(PODC9, BIT1, Value)
#define Iodd_WREG_ODC_92(Value)              TARG_WriteBit(PODC9, BIT2, Value)
#define Iodd_WREG_ODC_93(Value)              TARG_WriteBit(PODC9, BIT3, Value)
#define Iodd_WREG_ODC_94(Value)              TARG_WriteBit(PODC9, BIT4, Value)
#define Iodd_WREG_ODC_95(Value)              TARG_WriteBit(PODC9, BIT5, Value)
#define Iodd_WREG_ODC_96(Value)              TARG_WriteBit(PODC9, BIT6, Value)
#define Iodd_WREG_ODC_97(Value)              TARG_WriteBit(PODC9, BIT7, Value)

#endif

#if                                          \
      defined(__NEC_V850_DJ3__)||            \
      defined(__NEC_V850_DL3__)

#define Iodd_RREG_FC_90                      /* register undefined */
#define Iodd_RREG_FC_91                      /* register undefined */
#define Iodd_RREG_FC_92                      /* register undefined */
#define Iodd_RREG_FC_93                      /* register undefined */
#define Iodd_RREG_FC_94                      /* register undefined */
#define Iodd_RREG_FC_95                      /* register undefined */
#define Iodd_RREG_FC_96                      /* register undefined */
#define Iodd_RREG_FC_97                      /* register undefined */

#define Iodd_WREG_FC_90(Value)               /* register undefined */
#define Iodd_WREG_FC_91(Value)               /* register undefined */
#define Iodd_WREG_FC_92(Value)               /* register undefined */
#define Iodd_WREG_FC_93(Value)               /* register undefined */
#define Iodd_WREG_FC_94(Value)               /* register undefined */
#define Iodd_WREG_FC_95(Value)               /* register undefined */
#define Iodd_WREG_FC_96(Value)               /* register undefined */
#define Iodd_WREG_FC_97(Value)               /* register undefined */

#endif /* defined(__NEC_V850_DJ3__) || defined(__NEC_V850_DL3__) */

#if                                          \
      defined(__NEC_V850_DG3__)

#define Iodd_RREG_FC_90                      /* read access defined but should not be used */
#define Iodd_RREG_FC_91                      TARG_ReadBit(PFC9, BIT1)
#define Iodd_RREG_FC_92                      TARG_ReadBit(PFC9, BIT2)
#define Iodd_RREG_FC_93                      /* read access defined but should not be used */
#define Iodd_RREG_FC_94                      /* read access defined but should not be used */
#define Iodd_RREG_FC_95                      /* read access defined but should not be used */
#define Iodd_RREG_FC_96                      /* read access defined but should not be used */
#define Iodd_RREG_FC_97                      /* read access defined but should not be used */

#define Iodd_WREG_FC_90(Value)               /* write access not defined */
#define Iodd_WREG_FC_91(Value)               TARG_WriteBit(PFC9, BIT1, Value)
#define Iodd_WREG_FC_92(Value)               TARG_WriteBit(PFC9, BIT2, Value)
#define Iodd_WREG_FC_93(Value)               /* write access not defined */
#define Iodd_WREG_FC_94(Value)               /* write access not defined */
#define Iodd_WREG_FC_95(Value)               /* write access not defined */
#define Iodd_WREG_FC_96(Value)               /* write access not defined */
#define Iodd_WREG_FC_97(Value)               /* write access not defined */

#endif /* defined(__NEC_V850_DG3__) */

#if                                          \
      defined(__NEC_V850_Dx3__)

#define Iodd_RREG_PR_90                      TARG_ReadBit(PPR9, BIT0)
#define Iodd_RREG_PR_91                      TARG_ReadBit(PPR9, BIT1)
#define Iodd_RREG_PR_92                      TARG_ReadBit(PPR9, BIT2)
#define Iodd_RREG_PR_93                      TARG_ReadBit(PPR9, BIT3)
#define Iodd_RREG_PR_94                      TARG_ReadBit(PPR9, BIT4)
#define Iodd_RREG_PR_95                      TARG_ReadBit(PPR9, BIT5)
#define Iodd_RREG_PR_96                      TARG_ReadBit(PPR9, BIT6)
#define Iodd_RREG_PR_97                      TARG_ReadBit(PPR9, BIT7)

#define Iodd_WREG_PR_90(Value)               /* write access not defined */
#define Iodd_WREG_PR_91(Value)               /* write access not defined */
#define Iodd_WREG_PR_92(Value)               /* write access not defined */
#define Iodd_WREG_PR_93(Value)               /* write access not defined */
#define Iodd_WREG_PR_94(Value)               /* write access not defined */
#define Iodd_WREG_PR_95(Value)               /* write access not defined */
#define Iodd_WREG_PR_96(Value)               /* write access not defined */
#define Iodd_WREG_PR_97(Value)               /* write access not defined */

#endif

#if                                          \
      defined(__NEC_V850_DG3__)||            \
      defined(__NEC_V850_DJ3_LE__)

#define Iodd_RREG_LCDC_90                    TARG_ReadBit(PLCDC9, BIT0)
#define Iodd_RREG_LCDC_91                    TARG_ReadBit(PLCDC9, BIT1)
#define Iodd_RREG_LCDC_92                    TARG_ReadBit(PLCDC9, BIT2)
#define Iodd_RREG_LCDC_93                    TARG_ReadBit(PLCDC9, BIT3)
#define Iodd_RREG_LCDC_94                    TARG_ReadBit(PLCDC9, BIT4)
#define Iodd_RREG_LCDC_95                    TARG_ReadBit(PLCDC9, BIT5)
#define Iodd_RREG_LCDC_96                    TARG_ReadBit(PLCDC9, BIT6)
#define Iodd_RREG_LCDC_97                    TARG_ReadBit(PLCDC9, BIT7)

#define Iodd_WREG_LCDC_90(Value)             TARG_WriteBit(PLCDC9, BIT0, Value)
#define Iodd_WREG_LCDC_91(Value)             TARG_WriteBit(PLCDC9, BIT1, Value)
#define Iodd_WREG_LCDC_92(Value)             TARG_WriteBit(PLCDC9, BIT2, Value)
#define Iodd_WREG_LCDC_93(Value)             TARG_WriteBit(PLCDC9, BIT3, Value)
#define Iodd_WREG_LCDC_94(Value)             TARG_WriteBit(PLCDC9, BIT4, Value)
#define Iodd_WREG_LCDC_95(Value)             TARG_WriteBit(PLCDC9, BIT5, Value)
#define Iodd_WREG_LCDC_96(Value)             TARG_WriteBit(PLCDC9, BIT6, Value)
#define Iodd_WREG_LCDC_97(Value)             TARG_WriteBit(PLCDC9, BIT7, Value)

#endif /* defined(__NEC_V850_DG3__) || defined(__NEC_V850_DJ3_LE__) */

#if                                          \
      defined(__NEC_V850_DL3__)||            \
      defined(__NEC_V850_DJ3_HE__)

#define Iodd_RREG_LCDC_90                    /* register undefined */
#define Iodd_RREG_LCDC_91                    /* register undefined */
#define Iodd_RREG_LCDC_92                    /* register undefined */
#define Iodd_RREG_LCDC_93                    /* register undefined */
#define Iodd_RREG_LCDC_94                    /* register undefined */
#define Iodd_RREG_LCDC_95                    /* register undefined */
#define Iodd_RREG_LCDC_96                    /* register undefined */
#define Iodd_RREG_LCDC_97                    /* register undefined */

#define Iodd_WREG_LCDC_90(Value)             /* register undefined */
#define Iodd_WREG_LCDC_91(Value)             /* register undefined */
#define Iodd_WREG_LCDC_92(Value)             /* register undefined */
#define Iodd_WREG_LCDC_93(Value)             /* register undefined */
#define Iodd_WREG_LCDC_94(Value)             /* register undefined */
#define Iodd_WREG_LCDC_95(Value)             /* register undefined */
#define Iodd_WREG_LCDC_96(Value)             /* register undefined */
#define Iodd_WREG_LCDC_97(Value)             /* register undefined */

#endif /* defined(__NEC_V850_DL3__) || defined(__NEC_V850_DJ3_HE__) */

#if                                          \
      defined(__NEC_V850_DJ3__)||            \
      defined(__NEC_V850_DL3__)

#define Iodd_RREG_ILC_90                     /* register undefined */
#define Iodd_RREG_ILC_91                     /* register undefined */
#define Iodd_RREG_ILC_92                     /* register undefined */
#define Iodd_RREG_ILC_93                     /* register undefined */
#define Iodd_RREG_ILC_94                     /* register undefined */
#define Iodd_RREG_ILC_95                     /* register undefined */
#define Iodd_RREG_ILC_96                     /* register undefined */
#define Iodd_RREG_ILC_97                     /* register undefined */

#define Iodd_WREG_ILC_90(Value)              /* register undefined */
#define Iodd_WREG_ILC_91(Value)              /* register undefined */
#define Iodd_WREG_ILC_92(Value)              /* register undefined */
#define Iodd_WREG_ILC_93(Value)              /* register undefined */
#define Iodd_WREG_ILC_94(Value)              /* register undefined */
#define Iodd_WREG_ILC_95(Value)              /* register undefined */
#define Iodd_WREG_ILC_96(Value)              /* register undefined */
#define Iodd_WREG_ILC_97(Value)              /* register undefined */

#endif /* defined(__NEC_V850_DJ3__) || defined(__NEC_V850_DL3__) */

#if                                          \
      defined(__NEC_V850_DG3__)

#define Iodd_RREG_ILC_90                     TARG_ReadBit(PILC9, BIT0)
#define Iodd_RREG_ILC_91                     TARG_ReadBit(PILC9, BIT1)
#define Iodd_RREG_ILC_92                     TARG_ReadBit(PILC9, BIT2)
#define Iodd_RREG_ILC_93                     TARG_ReadBit(PILC9, BIT3)
#define Iodd_RREG_ILC_94                     TARG_ReadBit(PILC9, BIT4)
#define Iodd_RREG_ILC_95                     TARG_ReadBit(PILC9, BIT5)
#define Iodd_RREG_ILC_96                     TARG_ReadBit(PILC9, BIT6)
#define Iodd_RREG_ILC_97                     TARG_ReadBit(PILC9, BIT7)

#define Iodd_WREG_ILC_90(Value)              TARG_WriteBit(PILC9, BIT0, Value)
#define Iodd_WREG_ILC_91(Value)              TARG_WriteBit(PILC9, BIT1, Value)
#define Iodd_WREG_ILC_92(Value)              TARG_WriteBit(PILC9, BIT2, Value)
#define Iodd_WREG_ILC_93(Value)              TARG_WriteBit(PILC9, BIT3, Value)
#define Iodd_WREG_ILC_94(Value)              TARG_WriteBit(PILC9, BIT4, Value)
#define Iodd_WREG_ILC_95(Value)              TARG_WriteBit(PILC9, BIT5, Value)
#define Iodd_WREG_ILC_96(Value)              TARG_WriteBit(PILC9, BIT6, Value)
#define Iodd_WREG_ILC_97(Value)              TARG_WriteBit(PILC9, BIT7, Value)

#endif /* defined(__NEC_V850_DG3__) */

#if                                          \
      defined(__NEC_V850_DJ3__)||            \
      defined(__NEC_V850_DL3__)

#define Iodd_RREG_RC_90                     /* register undefined */
#define Iodd_RREG_RC_91                     /* register undefined */
#define Iodd_RREG_RC_92                     /* register undefined */
#define Iodd_RREG_RC_93                     /* register undefined */
#define Iodd_RREG_RC_94                     /* register undefined */
#define Iodd_RREG_RC_95                     /* register undefined */
#define Iodd_RREG_RC_96                     /* register undefined */
#define Iodd_RREG_RC_97                     /* register undefined */

#define Iodd_WREG_RC_90(Value)              /* register undefined */
#define Iodd_WREG_RC_91(Value)              /* register undefined */
#define Iodd_WREG_RC_92(Value)              /* register undefined */
#define Iodd_WREG_RC_93(Value)              /* register undefined */
#define Iodd_WREG_RC_94(Value)              /* register undefined */
#define Iodd_WREG_RC_95(Value)              /* register undefined */
#define Iodd_WREG_RC_96(Value)              /* register undefined */
#define Iodd_WREG_RC_97(Value)              /* register undefined */

#endif /* defined(__NEC_V850_DJ3__) || defined(__NEC_V850_DL3__) */

#if                                          \
      defined(__NEC_V850_DG3__)

#define Iodd_RREG_RC_90                     TARG_ReadBit(PRC9, BIT0)
#define Iodd_RREG_RC_91                     /* read access defined but should not be used */
#define Iodd_RREG_RC_92                     /* read access defined but should not be used */
#define Iodd_RREG_RC_93                     /* read access defined but should not be used */
#define Iodd_RREG_RC_94                     /* read access defined but should not be used */
#define Iodd_RREG_RC_95                     /* read access defined but should not be used */
#define Iodd_RREG_RC_96                     /* read access defined but should not be used */
#define Iodd_RREG_RC_97                     /* read access defined but should not be used */

#define Iodd_WREG_RC_90(Value)              TARG_WriteBit(PRC9, BIT0, Value)
#define Iodd_WREG_RC_91(Value)              /* write access not defined */
#define Iodd_WREG_RC_92(Value)              /* write access not defined */
#define Iodd_WREG_RC_93(Value)              /* write access not defined */
#define Iodd_WREG_RC_94(Value)              /* write access not defined */
#define Iodd_WREG_RC_95(Value)              /* write access not defined */
#define Iodd_WREG_RC_96(Value)              /* write access not defined */
#define Iodd_WREG_RC_97(Value)              /* write access not defined */

#endif /* defined(__NEC_V850_DG3__) */

/* Definitions PORT 10 */

#if                                          \
      defined(__NEC_V850_DJ3__)||            \
      defined(__NEC_V850_DL3__)

#define Iodd_RREG_P_100                      TARG_ReadBit(P10, BIT0)
#define Iodd_RREG_P_101                      TARG_ReadBit(P10, BIT1)
#define Iodd_RREG_P_102                      TARG_ReadBit(P10, BIT2)
#define Iodd_RREG_P_103                      TARG_ReadBit(P10, BIT3)
#define Iodd_RREG_P_104                      TARG_ReadBit(P10, BIT4)
#define Iodd_RREG_P_105                      TARG_ReadBit(P10, BIT5)
#define Iodd_RREG_P_106                      TARG_ReadBit(P10, BIT6)
#define Iodd_RREG_P_107                      TARG_ReadBit(P10, BIT7)

#define Iodd_WREG_P_100(Value)               TARG_WriteBit(P10, BIT0, Value)
#define Iodd_WREG_P_101(Value)               TARG_WriteBit(P10, BIT1, Value)
#define Iodd_WREG_P_102(Value)               TARG_WriteBit(P10, BIT2, Value)
#define Iodd_WREG_P_103(Value)               TARG_WriteBit(P10, BIT3, Value)
#define Iodd_WREG_P_104(Value)               TARG_WriteBit(P10, BIT4, Value)
#define Iodd_WREG_P_105(Value)               TARG_WriteBit(P10, BIT5, Value)
#define Iodd_WREG_P_106(Value)               TARG_WriteBit(P10, BIT6, Value)
#define Iodd_WREG_P_107(Value)               TARG_WriteBit(P10, BIT7, Value)

#endif /* defined(__NEC_V850_DJ3__) || defined(__NEC_V850_DL3__) */

#if                                          \
      defined(__NEC_V850_DG3__)

#define Iodd_RREG_P_100                      /* read access defined but should not be used */
#define Iodd_RREG_P_101                      /* read access defined but should not be used */
#define Iodd_RREG_P_102                      /* read access defined but should not be used */
#define Iodd_RREG_P_103                      /* read access defined but should not be used */
#define Iodd_RREG_P_104                      TARG_ReadBit(P10, BIT4)
#define Iodd_RREG_P_105                      TARG_ReadBit(P10, BIT5)
#define Iodd_RREG_P_106                      TARG_ReadBit(P10, BIT6)
#define Iodd_RREG_P_107                      TARG_ReadBit(P10, BIT7)

#define Iodd_WREG_P_100(Value)               /* write access not defined */
#define Iodd_WREG_P_101(Value)               /* write access not defined */
#define Iodd_WREG_P_102(Value)               /* write access not defined */
#define Iodd_WREG_P_103(Value)               /* write access not defined */
#define Iodd_WREG_P_104(Value)               TARG_WriteBit(P10, BIT4, Value)
#define Iodd_WREG_P_105(Value)               TARG_WriteBit(P10, BIT5, Value)
#define Iodd_WREG_P_106(Value)               TARG_WriteBit(P10, BIT6, Value)
#define Iodd_WREG_P_107(Value)               TARG_WriteBit(P10, BIT7, Value)

#endif /* defined(__NEC_V850_DG3__) */

#if                                          \
      defined(__NEC_V850_DJ3__)||            \
      defined(__NEC_V850_DL3__)

#define Iodd_RREG_M_100                      TARG_ReadBit(PM10, BIT0)
#define Iodd_RREG_M_101                      TARG_ReadBit(PM10, BIT1)
#define Iodd_RREG_M_102                      TARG_ReadBit(PM10, BIT2)
#define Iodd_RREG_M_103                      TARG_ReadBit(PM10, BIT3)
#define Iodd_RREG_M_104                      TARG_ReadBit(PM10, BIT4)
#define Iodd_RREG_M_105                      TARG_ReadBit(PM10, BIT5)
#define Iodd_RREG_M_106                      TARG_ReadBit(PM10, BIT6)
#define Iodd_RREG_M_107                      TARG_ReadBit(PM10, BIT7)

#define Iodd_WREG_M_100(Value)               TARG_WriteBit(PM10, BIT0, Value)
#define Iodd_WREG_M_101(Value)               TARG_WriteBit(PM10, BIT1, Value)
#define Iodd_WREG_M_102(Value)               TARG_WriteBit(PM10, BIT2, Value)
#define Iodd_WREG_M_103(Value)               TARG_WriteBit(PM10, BIT3, Value)
#define Iodd_WREG_M_104(Value)               TARG_WriteBit(PM10, BIT4, Value)
#define Iodd_WREG_M_105(Value)               TARG_WriteBit(PM10, BIT5, Value)
#define Iodd_WREG_M_106(Value)               TARG_WriteBit(PM10, BIT6, Value)
#define Iodd_WREG_M_107(Value)               TARG_WriteBit(PM10, BIT7, Value)

#endif /* defined(__NEC_V850_DJ3__) || defined(__NEC_V850_DL3__) */

#if                                          \
      defined(__NEC_V850_DG3__)

#define Iodd_RREG_M_100                      /* read access defined but should not be used */
#define Iodd_RREG_M_101                      /* read access defined but should not be used */
#define Iodd_RREG_M_102                      /* read access defined but should not be used */
#define Iodd_RREG_M_103                      /* read access defined but should not be used */
#define Iodd_RREG_M_104                      TARG_ReadBit(PM10, BIT4)
#define Iodd_RREG_M_105                      TARG_ReadBit(PM10, BIT5)
#define Iodd_RREG_M_106                      TARG_ReadBit(PM10, BIT6)
#define Iodd_RREG_M_107                      TARG_ReadBit(PM10, BIT7)

#define Iodd_WREG_M_100(Value)               /* write access not defined */
#define Iodd_WREG_M_101(Value)               /* write access not defined */
#define Iodd_WREG_M_102(Value)               /* write access not defined */
#define Iodd_WREG_M_103(Value)               /* write access not defined */
#define Iodd_WREG_M_104(Value)               TARG_WriteBit(PM10, BIT4, Value)
#define Iodd_WREG_M_105(Value)               TARG_WriteBit(PM10, BIT5, Value)
#define Iodd_WREG_M_106(Value)               TARG_WriteBit(PM10, BIT6, Value)
#define Iodd_WREG_M_107(Value)               TARG_WriteBit(PM10, BIT7, Value)

#endif /* defined(__NEC_V850_DG3__) */

#if                                          \
      defined(__NEC_V850_DJ3__)||            \
      defined(__NEC_V850_DL3__)

#define Iodd_RREG_MC_100                     TARG_ReadBit(PMC10, BIT0)
#define Iodd_RREG_MC_101                     TARG_ReadBit(PMC10, BIT1)
#define Iodd_RREG_MC_102                     TARG_ReadBit(PMC10, BIT2)
#define Iodd_RREG_MC_103                     TARG_ReadBit(PMC10, BIT3)
#define Iodd_RREG_MC_104                     TARG_ReadBit(PMC10, BIT4)
#define Iodd_RREG_MC_105                     TARG_ReadBit(PMC10, BIT5)
#define Iodd_RREG_MC_106                     TARG_ReadBit(PMC10, BIT6)
#define Iodd_RREG_MC_107                     TARG_ReadBit(PMC10, BIT7)

#define Iodd_WREG_MC_100(Value)              TARG_WriteBit(PMC10, BIT0, Value)
#define Iodd_WREG_MC_101(Value)              TARG_WriteBit(PMC10, BIT1, Value)
#define Iodd_WREG_MC_102(Value)              TARG_WriteBit(PMC10, BIT2, Value)
#define Iodd_WREG_MC_103(Value)              TARG_WriteBit(PMC10, BIT3, Value)
#define Iodd_WREG_MC_104(Value)              TARG_WriteBit(PMC10, BIT4, Value)
#define Iodd_WREG_MC_105(Value)              TARG_WriteBit(PMC10, BIT5, Value)
#define Iodd_WREG_MC_106(Value)              TARG_WriteBit(PMC10, BIT6, Value)
#define Iodd_WREG_MC_107(Value)              TARG_WriteBit(PMC10, BIT7, Value)

#endif /* defined(__NEC_V850_DJ3__) || defined(__NEC_V850_DL3__) */

#if                                          \
      defined(__NEC_V850_DG3__)

#define Iodd_RREG_MC_100                     /* read access defined but should not be used */
#define Iodd_RREG_MC_101                     /* read access defined but should not be used */
#define Iodd_RREG_MC_102                     /* read access defined but should not be used */
#define Iodd_RREG_MC_103                     /* read access defined but should not be used */
#define Iodd_RREG_MC_104                     /* read access defined but should not be used */
#define Iodd_RREG_MC_105                     TARG_ReadBit(PMC10, BIT5)
#define Iodd_RREG_MC_106                     TARG_ReadBit(PMC10, BIT6)
#define Iodd_RREG_MC_107                     TARG_ReadBit(PMC10, BIT7)

#define Iodd_WREG_MC_100(Value)              /* write access not defined */
#define Iodd_WREG_MC_101(Value)              /* write access not defined */
#define Iodd_WREG_MC_102(Value)              /* write access not defined */
#define Iodd_WREG_MC_103(Value)              /* write access not defined */
#define Iodd_WREG_MC_104(Value)              /* write access not defined */
#define Iodd_WREG_MC_105(Value)              TARG_WriteBit(PMC10, BIT5, Value)
#define Iodd_WREG_MC_106(Value)              TARG_WriteBit(PMC10, BIT6, Value)
#define Iodd_WREG_MC_107(Value)              TARG_WriteBit(PMC10, BIT7, Value)

#endif /* defined(__NEC_V850_DG3__) */

#if                                          \
      defined(__NEC_V850_DL3__)

#define Iodd_RREG_DSC_100                    TARG_ReadBit(PDSC10, BIT0)
#define Iodd_RREG_DSC_101                    TARG_ReadBit(PDSC10, BIT1)
#define Iodd_RREG_DSC_102                    TARG_ReadBit(PDSC10, BIT2)
#define Iodd_RREG_DSC_103                    TARG_ReadBit(PDSC10, BIT3)
#define Iodd_RREG_DSC_104                    /* read access defined but should not be used */
#define Iodd_RREG_DSC_105                    /* read access defined but should not be used */
#define Iodd_RREG_DSC_106                    /* read access defined but should not be used */
#define Iodd_RREG_DSC_107                    /* read access defined but should not be used */

#define Iodd_WREG_DSC_100(Value)             TARG_WriteBit(PDSC10, BIT0, Value)
#define Iodd_WREG_DSC_101(Value)             TARG_WriteBit(PDSC10, BIT1, Value)
#define Iodd_WREG_DSC_102(Value)             TARG_WriteBit(PDSC10, BIT2, Value)
#define Iodd_WREG_DSC_103(Value)             TARG_WriteBit(PDSC10, BIT3, Value)
#define Iodd_WREG_DSC_104(Value)             /* write access not defined */
#define Iodd_WREG_DSC_105(Value)             /* write access not defined */
#define Iodd_WREG_DSC_106(Value)             /* write access not defined */
#define Iodd_WREG_DSC_107(Value)             /* write access not defined */

#endif /* defined(__NEC_V850_DL3__) */

#if                                          \
      defined(__NEC_V850_DJ3__)

#define Iodd_RREG_DSC_100                    TARG_ReadBit(PDSC10, BIT0)
#define Iodd_RREG_DSC_101                    TARG_ReadBit(PDSC10, BIT1)
#define Iodd_RREG_DSC_102                    TARG_ReadBit(PDSC10, BIT2)
#define Iodd_RREG_DSC_103                    TARG_ReadBit(PDSC10, BIT3)
#define Iodd_RREG_DSC_104                    TARG_ReadBit(PDSC10, BIT4)
#define Iodd_RREG_DSC_105                    TARG_ReadBit(PDSC10, BIT5)
#define Iodd_RREG_DSC_106                    TARG_ReadBit(PDSC10, BIT6)
#define Iodd_RREG_DSC_107                    TARG_ReadBit(PDSC10, BIT7)

#define Iodd_WREG_DSC_100(Value)             TARG_WriteBit(PDSC10, BIT0, Value)
#define Iodd_WREG_DSC_101(Value)             TARG_WriteBit(PDSC10, BIT1, Value)
#define Iodd_WREG_DSC_102(Value)             TARG_WriteBit(PDSC10, BIT2, Value)
#define Iodd_WREG_DSC_103(Value)             TARG_WriteBit(PDSC10, BIT3, Value)
#define Iodd_WREG_DSC_104(Value)             TARG_WriteBit(PDSC10, BIT4, Value)
#define Iodd_WREG_DSC_105(Value)             TARG_WriteBit(PDSC10, BIT5, Value)
#define Iodd_WREG_DSC_106(Value)             TARG_WriteBit(PDSC10, BIT6, Value)
#define Iodd_WREG_DSC_107(Value)             TARG_WriteBit(PDSC10, BIT7, Value)

#endif /* defined(__NEC_V850_DJ3__) */

#if                                          \
      defined(__NEC_V850_DG3__)

#define Iodd_RREG_DSC_100                    /* read access defined but should not be used */
#define Iodd_RREG_DSC_101                    /* read access defined but should not be used */
#define Iodd_RREG_DSC_102                    /* read access defined but should not be used */
#define Iodd_RREG_DSC_103                    /* read access defined but should not be used */
#define Iodd_RREG_DSC_104                    TARG_ReadBit(PDSC10, BIT4)
#define Iodd_RREG_DSC_105                    TARG_ReadBit(PDSC10, BIT5)
#define Iodd_RREG_DSC_106                    TARG_ReadBit(PDSC10, BIT6)
#define Iodd_RREG_DSC_107                    TARG_ReadBit(PDSC10, BIT7)

#define Iodd_WREG_DSC_100(Value)             /* write access not defined */
#define Iodd_WREG_DSC_101(Value)             /* write access not defined */
#define Iodd_WREG_DSC_102(Value)             /* write access not defined */
#define Iodd_WREG_DSC_103(Value)             /* write access not defined */
#define Iodd_WREG_DSC_104(Value)             TARG_WriteBit(PDSC10, BIT4, Value)
#define Iodd_WREG_DSC_105(Value)             TARG_WriteBit(PDSC10, BIT5, Value)
#define Iodd_WREG_DSC_106(Value)             TARG_WriteBit(PDSC10, BIT6, Value)
#define Iodd_WREG_DSC_107(Value)             TARG_WriteBit(PDSC10, BIT7, Value)

#endif /* defined(__NEC_V850_DG3__) */

#if                                          \
      defined(__NEC_V850_DL3__)

#define Iodd_RREG_ICC_100                    TARG_ReadBit(PICC10, BIT0)
#define Iodd_RREG_ICC_101                    TARG_ReadBit(PICC10, BIT1)
#define Iodd_RREG_ICC_102                    TARG_ReadBit(PICC10, BIT2)
#define Iodd_RREG_ICC_103                    TARG_ReadBit(PICC10, BIT3)
#define Iodd_RREG_ICC_104                    /* read access defined but should not be used */
#define Iodd_RREG_ICC_105                    /* read access defined but should not be used */
#define Iodd_RREG_ICC_106                    /* read access defined but should not be used */
#define Iodd_RREG_ICC_107                    /* read access defined but should not be used */

#define Iodd_WREG_ICC_100(Value)             TARG_WriteBit(PICC10, BIT0, Value)
#define Iodd_WREG_ICC_101(Value)             TARG_WriteBit(PICC10, BIT1, Value)
#define Iodd_WREG_ICC_102(Value)             TARG_WriteBit(PICC10, BIT2, Value)
#define Iodd_WREG_ICC_103(Value)             TARG_WriteBit(PICC10, BIT3, Value)
#define Iodd_WREG_ICC_104(Value)             /* write access not defined */
#define Iodd_WREG_ICC_105(Value)             /* write access not defined */
#define Iodd_WREG_ICC_106(Value)             /* write access not defined */
#define Iodd_WREG_ICC_107(Value)             /* write access not defined */

#endif /* defined(__NEC_V850_DL3__) */

#if                                          \
      defined(__NEC_V850_DJ3__)

#define Iodd_RREG_ICC_100                    TARG_ReadBit(PICC10, BIT0)
#define Iodd_RREG_ICC_101                    TARG_ReadBit(PICC10, BIT1)
#define Iodd_RREG_ICC_102                    TARG_ReadBit(PICC10, BIT2)
#define Iodd_RREG_ICC_103                    TARG_ReadBit(PICC10, BIT3)
#define Iodd_RREG_ICC_104                    TARG_ReadBit(PICC10, BIT4)
#define Iodd_RREG_ICC_105                    TARG_ReadBit(PICC10, BIT5)
#define Iodd_RREG_ICC_106                    TARG_ReadBit(PICC10, BIT6)
#define Iodd_RREG_ICC_107                    TARG_ReadBit(PICC10, BIT7)

#define Iodd_WREG_ICC_100(Value)             TARG_WriteBit(PICC10, BIT0, Value)
#define Iodd_WREG_ICC_101(Value)             TARG_WriteBit(PICC10, BIT1, Value)
#define Iodd_WREG_ICC_102(Value)             TARG_WriteBit(PICC10, BIT2, Value)
#define Iodd_WREG_ICC_103(Value)             TARG_WriteBit(PICC10, BIT3, Value)
#define Iodd_WREG_ICC_104(Value)             TARG_WriteBit(PICC10, BIT4, Value)
#define Iodd_WREG_ICC_105(Value)             TARG_WriteBit(PICC10, BIT5, Value)
#define Iodd_WREG_ICC_106(Value)             TARG_WriteBit(PICC10, BIT6, Value)
#define Iodd_WREG_ICC_107(Value)             TARG_WriteBit(PICC10, BIT7, Value)

#endif /* defined(__NEC_V850_DJ3__) */

#if                                          \
      defined(__NEC_V850_DG3__)

#define Iodd_RREG_ICC_100                    /* read access defined but should not be used */
#define Iodd_RREG_ICC_101                    /* read access defined but should not be used */
#define Iodd_RREG_ICC_102                    /* read access defined but should not be used */
#define Iodd_RREG_ICC_103                    /* read access defined but should not be used */
#define Iodd_RREG_ICC_104                    TARG_ReadBit(PICC10, BIT4)
#define Iodd_RREG_ICC_105                    TARG_ReadBit(PICC10, BIT5)
#define Iodd_RREG_ICC_106                    TARG_ReadBit(PICC10, BIT6)
#define Iodd_RREG_ICC_107                    TARG_ReadBit(PICC10, BIT7)

#define Iodd_WREG_ICC_100(Value)             /* write access not defined */
#define Iodd_WREG_ICC_101(Value)             /* write access not defined */
#define Iodd_WREG_ICC_102(Value)             /* write access not defined */
#define Iodd_WREG_ICC_103(Value)             /* write access not defined */
#define Iodd_WREG_ICC_104(Value)             TARG_WriteBit(PICC10, BIT4, Value)
#define Iodd_WREG_ICC_105(Value)             TARG_WriteBit(PICC10, BIT5, Value)
#define Iodd_WREG_ICC_106(Value)             TARG_WriteBit(PICC10, BIT6, Value)
#define Iodd_WREG_ICC_107(Value)             TARG_WriteBit(PICC10, BIT7, Value)

#endif /* defined(__NEC_V850_DG3__) */

#if                                          \
      defined(__NEC_V850_DL3__)

#define Iodd_RREG_ODC_100                    TARG_ReadBit(PODC10, BIT0)
#define Iodd_RREG_ODC_101                    TARG_ReadBit(PODC10, BIT1)
#define Iodd_RREG_ODC_102                    TARG_ReadBit(PODC10, BIT2)
#define Iodd_RREG_ODC_103                    TARG_ReadBit(PODC10, BIT3)
#define Iodd_RREG_ODC_104                    /* read access defined but should not be used */
#define Iodd_RREG_ODC_105                    /* read access defined but should not be used */
#define Iodd_RREG_ODC_106                    /* read access defined but should not be used */
#define Iodd_RREG_ODC_107                    /* read access defined but should not be used */

#define Iodd_WREG_ODC_100(Value)             TARG_WriteBit(PODC10, BIT0, Value)
#define Iodd_WREG_ODC_101(Value)             TARG_WriteBit(PODC10, BIT1, Value)
#define Iodd_WREG_ODC_102(Value)             TARG_WriteBit(PODC10, BIT2, Value)
#define Iodd_WREG_ODC_103(Value)             TARG_WriteBit(PODC10, BIT3, Value)
#define Iodd_WREG_ODC_104(Value)             /* write access not defined */
#define Iodd_WREG_ODC_105(Value)             /* write access not defined */
#define Iodd_WREG_ODC_106(Value)             /* write access not defined */
#define Iodd_WREG_ODC_107(Value)             /* write access not defined */

#endif /* defined(__NEC_V850_DL3__) */

#if                                          \
      defined(__NEC_V850_DJ3__)

#define Iodd_RREG_ODC_100                    TARG_ReadBit(PODC10, BIT0)
#define Iodd_RREG_ODC_101                    TARG_ReadBit(PODC10, BIT1)
#define Iodd_RREG_ODC_102                    TARG_ReadBit(PODC10, BIT2)
#define Iodd_RREG_ODC_103                    TARG_ReadBit(PODC10, BIT3)
#define Iodd_RREG_ODC_104                    TARG_ReadBit(PODC10, BIT4)
#define Iodd_RREG_ODC_105                    TARG_ReadBit(PODC10, BIT5)
#define Iodd_RREG_ODC_106                    TARG_ReadBit(PODC10, BIT6)
#define Iodd_RREG_ODC_107                    TARG_ReadBit(PODC10, BIT7)

#define Iodd_WREG_ODC_100(Value)             TARG_WriteBit(PODC10, BIT0, Value)
#define Iodd_WREG_ODC_101(Value)             TARG_WriteBit(PODC10, BIT1, Value)
#define Iodd_WREG_ODC_102(Value)             TARG_WriteBit(PODC10, BIT2, Value)
#define Iodd_WREG_ODC_103(Value)             TARG_WriteBit(PODC10, BIT3, Value)
#define Iodd_WREG_ODC_104(Value)             TARG_WriteBit(PODC10, BIT4, Value)
#define Iodd_WREG_ODC_105(Value)             TARG_WriteBit(PODC10, BIT5, Value)
#define Iodd_WREG_ODC_106(Value)             TARG_WriteBit(PODC10, BIT6, Value)
#define Iodd_WREG_ODC_107(Value)             TARG_WriteBit(PODC10, BIT7, Value)

#endif /* defined(__NEC_V850_DJ3__) */

#if                                          \
      defined(__NEC_V850_DG3__)

#define Iodd_RREG_ODC_100                    /* read access defined but should not be used */
#define Iodd_RREG_ODC_101                    /* read access defined but should not be used */
#define Iodd_RREG_ODC_102                    /* read access defined but should not be used */
#define Iodd_RREG_ODC_103                    /* read access defined but should not be used */
#define Iodd_RREG_ODC_104                    TARG_ReadBit(PODC10, BIT4)
#define Iodd_RREG_ODC_105                    TARG_ReadBit(PODC10, BIT5)
#define Iodd_RREG_ODC_106                    TARG_ReadBit(PODC10, BIT6)
#define Iodd_RREG_ODC_107                    TARG_ReadBit(PODC10, BIT7)

#define Iodd_WREG_ODC_100(Value)             /* write access not defined */
#define Iodd_WREG_ODC_101(Value)             /* write access not defined */
#define Iodd_WREG_ODC_102(Value)             /* write access not defined */
#define Iodd_WREG_ODC_103(Value)             /* write access not defined */
#define Iodd_WREG_ODC_104(Value)             TARG_WriteBit(PODC10, BIT4, Value)
#define Iodd_WREG_ODC_105(Value)             TARG_WriteBit(PODC10, BIT5, Value)
#define Iodd_WREG_ODC_106(Value)             TARG_WriteBit(PODC10, BIT6, Value)
#define Iodd_WREG_ODC_107(Value)             TARG_WriteBit(PODC10, BIT7, Value)

#endif /* defined(__NEC_V850_DG3__) */

#if                                          \
      defined(__NEC_V850_Dx3__)

#define Iodd_RREG_FC_100                     /* register undefined */
#define Iodd_RREG_FC_101                     /* register undefined */
#define Iodd_RREG_FC_102                     /* register undefined */
#define Iodd_RREG_FC_103                     /* register undefined */
#define Iodd_RREG_FC_104                     /* register undefined */
#define Iodd_RREG_FC_105                     /* register undefined */
#define Iodd_RREG_FC_106                     /* register undefined */
#define Iodd_RREG_FC_107                     /* register undefined */
                                                                     
#define Iodd_WREG_FC_100(Value)              /* register undefined */
#define Iodd_WREG_FC_101(Value)              /* register undefined */
#define Iodd_WREG_FC_102(Value)              /* register undefined */
#define Iodd_WREG_FC_103(Value)              /* register undefined */
#define Iodd_WREG_FC_104(Value)              /* register undefined */
#define Iodd_WREG_FC_105(Value)              /* register undefined */
#define Iodd_WREG_FC_106(Value)              /* register undefined */
#define Iodd_WREG_FC_107(Value)              /* register undefined */

#endif

#if                                          \
      defined(__NEC_V850_DJ3__)||            \
      defined(__NEC_V850_DL3__)

#define Iodd_RREG_PR_100                     TARG_ReadBit(PPR10, BIT0)
#define Iodd_RREG_PR_101                     TARG_ReadBit(PPR10, BIT1)
#define Iodd_RREG_PR_102                     TARG_ReadBit(PPR10, BIT2)
#define Iodd_RREG_PR_103                     TARG_ReadBit(PPR10, BIT3)
#define Iodd_RREG_PR_104                     TARG_ReadBit(PPR10, BIT4)
#define Iodd_RREG_PR_105                     TARG_ReadBit(PPR10, BIT5)
#define Iodd_RREG_PR_106                     TARG_ReadBit(PPR10, BIT6)
#define Iodd_RREG_PR_107                     TARG_ReadBit(PPR10, BIT7)

#define Iodd_WREG_PR_100(Value)              /* write access not defined */
#define Iodd_WREG_PR_101(Value)              /* write access not defined */
#define Iodd_WREG_PR_102(Value)              /* write access not defined */
#define Iodd_WREG_PR_103(Value)              /* write access not defined */
#define Iodd_WREG_PR_104(Value)              /* write access not defined */
#define Iodd_WREG_PR_105(Value)              /* write access not defined */
#define Iodd_WREG_PR_106(Value)              /* write access not defined */
#define Iodd_WREG_PR_107(Value)              /* write access not defined */

#endif /* defined(__NEC_V850_DJ3__) || defined(__NEC_V850_DL3__) */

#if                                          \
      defined(__NEC_V850_DG3__)

#define Iodd_RREG_PR_100                     /* read access defined but should not be used */
#define Iodd_RREG_PR_101                     /* read access defined but should not be used */
#define Iodd_RREG_PR_102                     /* read access defined but should not be used */
#define Iodd_RREG_PR_103                     /* read access defined but should not be used */
#define Iodd_RREG_PR_104                     TARG_ReadBit(PPR10, BIT4)
#define Iodd_RREG_PR_105                     TARG_ReadBit(PPR10, BIT5)
#define Iodd_RREG_PR_106                     TARG_ReadBit(PPR10, BIT6)
#define Iodd_RREG_PR_107                     TARG_ReadBit(PPR10, BIT7)

#define Iodd_WREG_PR_100(Value)              /* write access not defined */
#define Iodd_WREG_PR_101(Value)              /* write access not defined */
#define Iodd_WREG_PR_102(Value)              /* write access not defined */
#define Iodd_WREG_PR_103(Value)              /* write access not defined */
#define Iodd_WREG_PR_104(Value)              /* write access not defined */
#define Iodd_WREG_PR_105(Value)              /* write access not defined */
#define Iodd_WREG_PR_106(Value)              /* write access not defined */
#define Iodd_WREG_PR_107(Value)              /* write access not defined */

#endif /* defined(__NEC_V850_DG3__) */

#if                                          \
      defined(__NEC_V850_DG3__)||            \
      defined(__NEC_V850_DJ3_LE__)

#define Iodd_RREG_LCDC_100                   /* read access defined but should not be used */
#define Iodd_RREG_LCDC_101                   /* read access defined but should not be used */
#define Iodd_RREG_LCDC_102                   /* read access defined but should not be used */
#define Iodd_RREG_LCDC_103                   /* read access defined but should not be used */
#define Iodd_RREG_LCDC_104                   TARG_ReadBit(PLCDC10, BIT4)
#define Iodd_RREG_LCDC_105                   TARG_ReadBit(PLCDC10, BIT5)
#define Iodd_RREG_LCDC_106                   TARG_ReadBit(PLCDC10, BIT6)
#define Iodd_RREG_LCDC_107                   TARG_ReadBit(PLCDC10, BIT7)

#define Iodd_WREG_LCDC_100(Value)            /* write access not defined */
#define Iodd_WREG_LCDC_101(Value)            /* write access not defined */
#define Iodd_WREG_LCDC_102(Value)            /* write access not defined */
#define Iodd_WREG_LCDC_103(Value)            /* write access not defined */
#define Iodd_WREG_LCDC_104(Value)            TARG_WriteBit(PLCDC10, BIT4, Value)
#define Iodd_WREG_LCDC_105(Value)            TARG_WriteBit(PLCDC10, BIT5, Value)
#define Iodd_WREG_LCDC_106(Value)            TARG_WriteBit(PLCDC10, BIT6, Value)
#define Iodd_WREG_LCDC_107(Value)            TARG_WriteBit(PLCDC10, BIT7, Value)

#endif /* defined(__NEC_V850_DG3__) || defined(__NEC_V850_DJ3_LE__) */

#if                                          \
      defined(__NEC_V850_DL3__)||            \
      defined(__NEC_V850_DJ3_HE__)

#define Iodd_RREG_LCDC_100                   /* register undefined */
#define Iodd_RREG_LCDC_101                   /* register undefined */
#define Iodd_RREG_LCDC_102                   /* register undefined */
#define Iodd_RREG_LCDC_103                   /* register undefined */
#define Iodd_RREG_LCDC_104                   /* register undefined */
#define Iodd_RREG_LCDC_105                   /* register undefined */
#define Iodd_RREG_LCDC_106                   /* register undefined */
#define Iodd_RREG_LCDC_107                   /* register undefined */

#define Iodd_WREG_LCDC_100(Value)            /* register undefined */
#define Iodd_WREG_LCDC_101(Value)            /* register undefined */
#define Iodd_WREG_LCDC_102(Value)            /* register undefined */
#define Iodd_WREG_LCDC_103(Value)            /* register undefined */
#define Iodd_WREG_LCDC_104(Value)            /* register undefined */
#define Iodd_WREG_LCDC_105(Value)            /* register undefined */
#define Iodd_WREG_LCDC_106(Value)            /* register undefined */
#define Iodd_WREG_LCDC_107(Value)            /* register undefined */

#endif /* defined(__NEC_V850_DL3__) || defined(__NEC_V850_DJ3_HE__) */

#if                                          \
      defined(__NEC_V850_DJ3__)||            \
      defined(__NEC_V850_DL3__)

#define Iodd_RREG_ILC_100                     /* register undefined */
#define Iodd_RREG_ILC_101                     /* register undefined */
#define Iodd_RREG_ILC_102                     /* register undefined */
#define Iodd_RREG_ILC_103                     /* register undefined */
#define Iodd_RREG_ILC_104                     /* register undefined */
#define Iodd_RREG_ILC_105                     /* register undefined */
#define Iodd_RREG_ILC_106                     /* register undefined */
#define Iodd_RREG_ILC_107                     /* register undefined */

#define Iodd_WREG_ILC_100(Value)              /* register undefined */
#define Iodd_WREG_ILC_101(Value)              /* register undefined */
#define Iodd_WREG_ILC_102(Value)              /* register undefined */
#define Iodd_WREG_ILC_103(Value)              /* register undefined */
#define Iodd_WREG_ILC_104(Value)              /* register undefined */
#define Iodd_WREG_ILC_105(Value)              /* register undefined */
#define Iodd_WREG_ILC_106(Value)              /* register undefined */
#define Iodd_WREG_ILC_107(Value)              /* register undefined */

#endif /* defined(__NEC_V850_DJ3__) || defined(__NEC_V850_DL3__) */

#if                                          \
      defined(__NEC_V850_DG3__)

#define Iodd_RREG_ILC_100                     /* read access defined but should not be used */
#define Iodd_RREG_ILC_101                     /* read access defined but should not be used */
#define Iodd_RREG_ILC_102                     /* read access defined but should not be used */
#define Iodd_RREG_ILC_103                     /* read access defined but should not be used */
#define Iodd_RREG_ILC_104                     TARG_ReadBit(PILC10, BIT4)
#define Iodd_RREG_ILC_105                     TARG_ReadBit(PILC10, BIT5)
#define Iodd_RREG_ILC_106                     TARG_ReadBit(PILC10, BIT6)
#define Iodd_RREG_ILC_107                     TARG_ReadBit(PILC10, BIT7)

#define Iodd_WREG_ILC_100(Value)              /* write access not defined */
#define Iodd_WREG_ILC_101(Value)              /* write access not defined */
#define Iodd_WREG_ILC_102(Value)              /* write access not defined */
#define Iodd_WREG_ILC_103(Value)              /* write access not defined */
#define Iodd_WREG_ILC_104(Value)              TARG_WriteBit(PILC10, BIT4, Value)
#define Iodd_WREG_ILC_105(Value)              TARG_WriteBit(PILC10, BIT5, Value)
#define Iodd_WREG_ILC_106(Value)              TARG_WriteBit(PILC10, BIT6, Value)
#define Iodd_WREG_ILC_107(Value)              TARG_WriteBit(PILC10, BIT7, Value)

#endif /* defined(__NEC_V850_DG3__) */

#if                                          \
      defined(__NEC_V850_DJ3__)||            \
      defined(__NEC_V850_DL3__)

#define Iodd_RREG_RC_100                     /* register undefined */
#define Iodd_RREG_RC_101                     /* register undefined */
#define Iodd_RREG_RC_102                     /* register undefined */
#define Iodd_RREG_RC_103                     /* register undefined */
#define Iodd_RREG_RC_104                     /* register undefined */
#define Iodd_RREG_RC_105                     /* register undefined */
#define Iodd_RREG_RC_106                     /* register undefined */
#define Iodd_RREG_RC_107                     /* register undefined */

#define Iodd_WREG_RC_100(Value)              /* register undefined */
#define Iodd_WREG_RC_101(Value)              /* register undefined */
#define Iodd_WREG_RC_102(Value)              /* register undefined */
#define Iodd_WREG_RC_103(Value)              /* register undefined */
#define Iodd_WREG_RC_104(Value)              /* register undefined */
#define Iodd_WREG_RC_105(Value)              /* register undefined */
#define Iodd_WREG_RC_106(Value)              /* register undefined */
#define Iodd_WREG_RC_107(Value)              /* register undefined */

#endif /* defined(__NEC_V850_DJ3__) || defined(__NEC_V850_DL3__) */

#if                                          \
      defined(__NEC_V850_DG3__)

#define Iodd_RREG_RC_100                     TARG_ReadBit(PRC10, BIT0)
#define Iodd_RREG_RC_101                     /* read access defined but should not be used */
#define Iodd_RREG_RC_102                     /* read access defined but should not be used */
#define Iodd_RREG_RC_103                     /* read access defined but should not be used */
#define Iodd_RREG_RC_104                     /* read access defined but should not be used */
#define Iodd_RREG_RC_105                     /* read access defined but should not be used */
#define Iodd_RREG_RC_106                     /* read access defined but should not be used */
#define Iodd_RREG_RC_107                     /* read access defined but should not be used */

#define Iodd_WREG_RC_100(Value)              TARG_WriteBit(PRC10, BIT0, Value)
#define Iodd_WREG_RC_101(Value)              /* write access not defined */
#define Iodd_WREG_RC_102(Value)              /* write access not defined */
#define Iodd_WREG_RC_103(Value)              /* write access not defined */
#define Iodd_WREG_RC_104(Value)              /* write access not defined */
#define Iodd_WREG_RC_105(Value)              /* write access not defined */
#define Iodd_WREG_RC_106(Value)              /* write access not defined */
#define Iodd_WREG_RC_107(Value)              /* write access not defined */

#endif /* defined(__NEC_V850_DG3__) */

/* Definitions PORT 11 */

#if                                          \
      defined(__NEC_V850_DJ3__)||            \
      defined(__NEC_V850_DL3__)

#define Iodd_RREG_P_110                      TARG_ReadBit(P11, BIT0)
#define Iodd_RREG_P_111                      TARG_ReadBit(P11, BIT1)
#define Iodd_RREG_P_112                      TARG_ReadBit(P11, BIT2)
#define Iodd_RREG_P_113                      TARG_ReadBit(P11, BIT3)
#define Iodd_RREG_P_114                      TARG_ReadBit(P11, BIT4)
#define Iodd_RREG_P_115                      TARG_ReadBit(P11, BIT5)
#define Iodd_RREG_P_116                      TARG_ReadBit(P11, BIT6)
#define Iodd_RREG_P_117                      TARG_ReadBit(P11, BIT7)

#define Iodd_WREG_P_110(Value)               TARG_WriteBit(P11, BIT0, Value)
#define Iodd_WREG_P_111(Value)               TARG_WriteBit(P11, BIT1, Value)
#define Iodd_WREG_P_112(Value)               TARG_WriteBit(P11, BIT2, Value)
#define Iodd_WREG_P_113(Value)               TARG_WriteBit(P11, BIT3, Value)
#define Iodd_WREG_P_114(Value)               TARG_WriteBit(P11, BIT4, Value)
#define Iodd_WREG_P_115(Value)               TARG_WriteBit(P11, BIT5, Value)
#define Iodd_WREG_P_116(Value)               TARG_WriteBit(P11, BIT6, Value)
#define Iodd_WREG_P_117(Value)               TARG_WriteBit(P11, BIT7, Value)

#endif /* defined(__NEC_V850_DJ3__) || defined(__NEC_V850_DL3__) */

#if                                          \
      defined(__NEC_V850_DG3__)

#define Iodd_RREG_P_110                      /* register undefined */
#define Iodd_RREG_P_111                      /* register undefined */
#define Iodd_RREG_P_112                      /* register undefined */
#define Iodd_RREG_P_113                      /* register undefined */
#define Iodd_RREG_P_114                      /* register undefined */
#define Iodd_RREG_P_115                      /* register undefined */
#define Iodd_RREG_P_116                      /* register undefined */
#define Iodd_RREG_P_117                      /* register undefined */
                                                                     
#define Iodd_WREG_P_110(Value)               /* register undefined */
#define Iodd_WREG_P_111(Value)               /* register undefined */
#define Iodd_WREG_P_112(Value)               /* register undefined */
#define Iodd_WREG_P_113(Value)               /* register undefined */
#define Iodd_WREG_P_114(Value)               /* register undefined */
#define Iodd_WREG_P_115(Value)               /* register undefined */
#define Iodd_WREG_P_116(Value)               /* register undefined */
#define Iodd_WREG_P_117(Value)               /* register undefined */

#endif /* defined(__NEC_V850_DG3__) */

#if                                          \
      defined(__NEC_V850_DJ3__)||            \
      defined(__NEC_V850_DL3__)

#define Iodd_RREG_M_110                      TARG_ReadBit(PM11, BIT0)
#define Iodd_RREG_M_111                      TARG_ReadBit(PM11, BIT1)
#define Iodd_RREG_M_112                      TARG_ReadBit(PM11, BIT2)
#define Iodd_RREG_M_113                      TARG_ReadBit(PM11, BIT3)
#define Iodd_RREG_M_114                      TARG_ReadBit(PM11, BIT4)
#define Iodd_RREG_M_115                      TARG_ReadBit(PM11, BIT5)
#define Iodd_RREG_M_116                      TARG_ReadBit(PM11, BIT6)
#define Iodd_RREG_M_117                      TARG_ReadBit(PM11, BIT7)

#define Iodd_WREG_M_110(Value)               TARG_WriteBit(PM11, BIT0, Value)
#define Iodd_WREG_M_111(Value)               TARG_WriteBit(PM11, BIT1, Value)
#define Iodd_WREG_M_112(Value)               TARG_WriteBit(PM11, BIT2, Value)
#define Iodd_WREG_M_113(Value)               TARG_WriteBit(PM11, BIT3, Value)
#define Iodd_WREG_M_114(Value)               TARG_WriteBit(PM11, BIT4, Value)
#define Iodd_WREG_M_115(Value)               TARG_WriteBit(PM11, BIT5, Value)
#define Iodd_WREG_M_116(Value)               TARG_WriteBit(PM11, BIT6, Value)
#define Iodd_WREG_M_117(Value)               TARG_WriteBit(PM11, BIT7, Value)

#endif /* defined(__NEC_V850_DJ3__) || defined(__NEC_V850_DL3__) */

#if                                          \
      defined(__NEC_V850_DG3__)

#define Iodd_RREG_M_110                      /* register undefined */
#define Iodd_RREG_M_111                      /* register undefined */
#define Iodd_RREG_M_112                      /* register undefined */
#define Iodd_RREG_M_113                      /* register undefined */
#define Iodd_RREG_M_114                      /* register undefined */
#define Iodd_RREG_M_115                      /* register undefined */
#define Iodd_RREG_M_116                      /* register undefined */
#define Iodd_RREG_M_117                      /* register undefined */
                                                                     
#define Iodd_WREG_M_110(Value)               /* register undefined */
#define Iodd_WREG_M_111(Value)               /* register undefined */
#define Iodd_WREG_M_112(Value)               /* register undefined */
#define Iodd_WREG_M_113(Value)               /* register undefined */
#define Iodd_WREG_M_114(Value)               /* register undefined */
#define Iodd_WREG_M_115(Value)               /* register undefined */
#define Iodd_WREG_M_116(Value)               /* register undefined */
#define Iodd_WREG_M_117(Value)               /* register undefined */

#endif /* defined(__NEC_V850_DG3__) */

#if                                          \
      defined(__NEC_V850_DJ3__)||            \
      defined(__NEC_V850_DL3__)

#define Iodd_RREG_MC_110                     TARG_ReadBit(PMC11, BIT0)
#define Iodd_RREG_MC_111                     TARG_ReadBit(PMC11, BIT1)
#define Iodd_RREG_MC_112                     TARG_ReadBit(PMC11, BIT2)
#define Iodd_RREG_MC_113                     TARG_ReadBit(PMC11, BIT3)
#define Iodd_RREG_MC_114                     TARG_ReadBit(PMC11, BIT4)
#define Iodd_RREG_MC_115                     TARG_ReadBit(PMC11, BIT5)
#define Iodd_RREG_MC_116                     TARG_ReadBit(PMC11, BIT6)
#define Iodd_RREG_MC_117                     TARG_ReadBit(PMC11, BIT7)

#define Iodd_WREG_MC_110(Value)              TARG_WriteBit(PMC11, BIT0, Value)
#define Iodd_WREG_MC_111(Value)              TARG_WriteBit(PMC11, BIT1, Value)
#define Iodd_WREG_MC_112(Value)              TARG_WriteBit(PMC11, BIT2, Value)
#define Iodd_WREG_MC_113(Value)              TARG_WriteBit(PMC11, BIT3, Value)
#define Iodd_WREG_MC_114(Value)              TARG_WriteBit(PMC11, BIT4, Value)
#define Iodd_WREG_MC_115(Value)              TARG_WriteBit(PMC11, BIT5, Value)
#define Iodd_WREG_MC_116(Value)              TARG_WriteBit(PMC11, BIT6, Value)
#define Iodd_WREG_MC_117(Value)              TARG_WriteBit(PMC11, BIT7, Value)

#endif /* defined(__NEC_V850_DJ3__) || defined(__NEC_V850_DL3__) */

#if                                          \
      defined(__NEC_V850_DG3__)

#define Iodd_RREG_MC_110                     /* register undefined */
#define Iodd_RREG_MC_111                     /* register undefined */
#define Iodd_RREG_MC_112                     /* register undefined */
#define Iodd_RREG_MC_113                     /* register undefined */
#define Iodd_RREG_MC_114                     /* register undefined */
#define Iodd_RREG_MC_115                     /* register undefined */
#define Iodd_RREG_MC_116                     /* register undefined */
#define Iodd_RREG_MC_117                     /* register undefined */
                                                                     
#define Iodd_WREG_MC_110(Value)              /* register undefined */
#define Iodd_WREG_MC_111(Value)              /* register undefined */
#define Iodd_WREG_MC_112(Value)              /* register undefined */
#define Iodd_WREG_MC_113(Value)              /* register undefined */
#define Iodd_WREG_MC_114(Value)              /* register undefined */
#define Iodd_WREG_MC_115(Value)              /* register undefined */
#define Iodd_WREG_MC_116(Value)              /* register undefined */
#define Iodd_WREG_MC_117(Value)              /* register undefined */

#endif /* defined(__NEC_V850_DG3__) */

#if                                          \
      defined(__NEC_V850_DJ3__)||            \
      defined(__NEC_V850_DL3__)

#define Iodd_RREG_ICC_110                    TARG_ReadBit(PICC11, BIT0)
#define Iodd_RREG_ICC_111                    TARG_ReadBit(PICC11, BIT1)
#define Iodd_RREG_ICC_112                    TARG_ReadBit(PICC11, BIT2)
#define Iodd_RREG_ICC_113                    TARG_ReadBit(PICC11, BIT3)
#define Iodd_RREG_ICC_114                    TARG_ReadBit(PICC11, BIT4)
#define Iodd_RREG_ICC_115                    TARG_ReadBit(PICC11, BIT5)
#define Iodd_RREG_ICC_116                    TARG_ReadBit(PICC11, BIT6)
#define Iodd_RREG_ICC_117                    TARG_ReadBit(PICC11, BIT7)

#define Iodd_WREG_ICC_110(Value)             TARG_WriteBit(PICC11, BIT0, Value)
#define Iodd_WREG_ICC_111(Value)             TARG_WriteBit(PICC11, BIT1, Value)
#define Iodd_WREG_ICC_112(Value)             TARG_WriteBit(PICC11, BIT2, Value)
#define Iodd_WREG_ICC_113(Value)             TARG_WriteBit(PICC11, BIT3, Value)
#define Iodd_WREG_ICC_114(Value)             TARG_WriteBit(PICC11, BIT4, Value)
#define Iodd_WREG_ICC_115(Value)             TARG_WriteBit(PICC11, BIT5, Value)
#define Iodd_WREG_ICC_116(Value)             TARG_WriteBit(PICC11, BIT6, Value)
#define Iodd_WREG_ICC_117(Value)             TARG_WriteBit(PICC11, BIT7, Value)

#endif /* defined(__NEC_V850_DJ3__) || defined(__NEC_V850_DL3__) */

#if                                          \
      defined(__NEC_V850_DG3__)

#define Iodd_RREG_ICC_110                    /* register undefined */
#define Iodd_RREG_ICC_111                    /* register undefined */
#define Iodd_RREG_ICC_112                    /* register undefined */
#define Iodd_RREG_ICC_113                    /* register undefined */
#define Iodd_RREG_ICC_114                    /* register undefined */
#define Iodd_RREG_ICC_115                    /* register undefined */
#define Iodd_RREG_ICC_116                    /* register undefined */
#define Iodd_RREG_ICC_117                    /* register undefined */
                                                                     
#define Iodd_WREG_ICC_110(Value)             /* register undefined */
#define Iodd_WREG_ICC_111(Value)             /* register undefined */
#define Iodd_WREG_ICC_112(Value)             /* register undefined */
#define Iodd_WREG_ICC_113(Value)             /* register undefined */
#define Iodd_WREG_ICC_114(Value)             /* register undefined */
#define Iodd_WREG_ICC_115(Value)             /* register undefined */
#define Iodd_WREG_ICC_116(Value)             /* register undefined */
#define Iodd_WREG_ICC_117(Value)             /* register undefined */

#endif /* defined(__NEC_V850_DG3__) */

#if                                          \
      defined(__NEC_V850_DJ3__)||            \
      defined(__NEC_V850_DL3__)

#define Iodd_RREG_ODC_110                    TARG_ReadBit(PODC11, BIT0)
#define Iodd_RREG_ODC_111                    TARG_ReadBit(PODC11, BIT1)
#define Iodd_RREG_ODC_112                    TARG_ReadBit(PODC11, BIT2)
#define Iodd_RREG_ODC_113                    TARG_ReadBit(PODC11, BIT3)
#define Iodd_RREG_ODC_114                    TARG_ReadBit(PODC11, BIT4)
#define Iodd_RREG_ODC_115                    TARG_ReadBit(PODC11, BIT5)
#define Iodd_RREG_ODC_116                    TARG_ReadBit(PODC11, BIT6)
#define Iodd_RREG_ODC_117                    TARG_ReadBit(PODC11, BIT7)

#define Iodd_WREG_ODC_110(Value)             TARG_WriteBit(PODC11, BIT0, Value)
#define Iodd_WREG_ODC_111(Value)             TARG_WriteBit(PODC11, BIT1, Value)
#define Iodd_WREG_ODC_112(Value)             TARG_WriteBit(PODC11, BIT2, Value)
#define Iodd_WREG_ODC_113(Value)             TARG_WriteBit(PODC11, BIT3, Value)
#define Iodd_WREG_ODC_114(Value)             TARG_WriteBit(PODC11, BIT4, Value)
#define Iodd_WREG_ODC_115(Value)             TARG_WriteBit(PODC11, BIT5, Value)
#define Iodd_WREG_ODC_116(Value)             TARG_WriteBit(PODC11, BIT6, Value)
#define Iodd_WREG_ODC_117(Value)             TARG_WriteBit(PODC11, BIT7, Value)

#endif /* defined(__NEC_V850_DJ3__) || defined(__NEC_V850_DL3__) */

#if                                          \
      defined(__NEC_V850_DG3__)

#define Iodd_RREG_ODC_110                    /* register undefined */
#define Iodd_RREG_ODC_111                    /* register undefined */
#define Iodd_RREG_ODC_112                    /* register undefined */
#define Iodd_RREG_ODC_113                    /* register undefined */
#define Iodd_RREG_ODC_114                    /* register undefined */
#define Iodd_RREG_ODC_115                    /* register undefined */
#define Iodd_RREG_ODC_116                    /* register undefined */
#define Iodd_RREG_ODC_117                    /* register undefined */
                                                                     
#define Iodd_WREG_ODC_110(Value)             /* register undefined */
#define Iodd_WREG_ODC_111(Value)             /* register undefined */
#define Iodd_WREG_ODC_112(Value)             /* register undefined */
#define Iodd_WREG_ODC_113(Value)             /* register undefined */
#define Iodd_WREG_ODC_114(Value)             /* register undefined */
#define Iodd_WREG_ODC_115(Value)             /* register undefined */
#define Iodd_WREG_ODC_116(Value)             /* register undefined */
#define Iodd_WREG_ODC_117(Value)             /* register undefined */

#endif /* defined(__NEC_V850_DG3__) */

#if                                          \
      defined(__NEC_V850_Dx3__)

#define Iodd_RREG_FC_110                     /* register undefined */
#define Iodd_RREG_FC_111                     /* register undefined */
#define Iodd_RREG_FC_112                     /* register undefined */
#define Iodd_RREG_FC_113                     /* register undefined */
#define Iodd_RREG_FC_114                     /* register undefined */
#define Iodd_RREG_FC_115                     /* register undefined */
#define Iodd_RREG_FC_116                     /* register undefined */
#define Iodd_RREG_FC_117                     /* register undefined */
                                                                     
#define Iodd_WREG_FC_110(Value)              /* register undefined */
#define Iodd_WREG_FC_111(Value)              /* register undefined */
#define Iodd_WREG_FC_112(Value)              /* register undefined */
#define Iodd_WREG_FC_113(Value)              /* register undefined */
#define Iodd_WREG_FC_114(Value)              /* register undefined */
#define Iodd_WREG_FC_115(Value)              /* register undefined */
#define Iodd_WREG_FC_116(Value)              /* register undefined */
#define Iodd_WREG_FC_117(Value)              /* register undefined */

#endif

#if                                          \
      defined(__NEC_V850_DJ3__)||            \
      defined(__NEC_V850_DL3__)

#define Iodd_RREG_PR_110                     TARG_ReadBit(PPR11, BIT0)
#define Iodd_RREG_PR_111                     TARG_ReadBit(PPR11, BIT1)
#define Iodd_RREG_PR_112                     TARG_ReadBit(PPR11, BIT2)
#define Iodd_RREG_PR_113                     TARG_ReadBit(PPR11, BIT3)
#define Iodd_RREG_PR_114                     TARG_ReadBit(PPR11, BIT4)
#define Iodd_RREG_PR_115                     TARG_ReadBit(PPR11, BIT5)
#define Iodd_RREG_PR_116                     TARG_ReadBit(PPR11, BIT6)
#define Iodd_RREG_PR_117                     TARG_ReadBit(PPR11, BIT7)

#define Iodd_WREG_PR_110(Value)              /* write access not defined */
#define Iodd_WREG_PR_111(Value)              /* write access not defined */
#define Iodd_WREG_PR_112(Value)              /* write access not defined */
#define Iodd_WREG_PR_113(Value)              /* write access not defined */
#define Iodd_WREG_PR_114(Value)              /* write access not defined */
#define Iodd_WREG_PR_115(Value)              /* write access not defined */
#define Iodd_WREG_PR_116(Value)              /* write access not defined */
#define Iodd_WREG_PR_117(Value)              /* write access not defined */

#endif /* defined(__NEC_V850_DJ3__) || defined(__NEC_V850_DL3__) */

#if                                          \
      defined(__NEC_V850_DG3__)

#define Iodd_RREG_PR_110                     /* register undefined */
#define Iodd_RREG_PR_111                     /* register undefined */
#define Iodd_RREG_PR_112                     /* register undefined */
#define Iodd_RREG_PR_113                     /* register undefined */
#define Iodd_RREG_PR_114                     /* register undefined */
#define Iodd_RREG_PR_115                     /* register undefined */
#define Iodd_RREG_PR_116                     /* register undefined */
#define Iodd_RREG_PR_117                     /* register undefined */
                                                                     
#define Iodd_WREG_PR_110(Value)              /* register undefined */
#define Iodd_WREG_PR_111(Value)              /* register undefined */
#define Iodd_WREG_PR_112(Value)              /* register undefined */
#define Iodd_WREG_PR_113(Value)              /* register undefined */
#define Iodd_WREG_PR_114(Value)              /* register undefined */
#define Iodd_WREG_PR_115(Value)              /* register undefined */
#define Iodd_WREG_PR_116(Value)              /* register undefined */
#define Iodd_WREG_PR_117(Value)              /* register undefined */

#endif /* defined(__NEC_V850_DG3__) */

#if                                          \
      defined(__NEC_V850_Dx3__)

#define Iodd_RREG_DSC_110                    /* register undefined */
#define Iodd_RREG_DSC_111                    /* register undefined */
#define Iodd_RREG_DSC_112                    /* register undefined */
#define Iodd_RREG_DSC_113                    /* register undefined */
#define Iodd_RREG_DSC_114                    /* register undefined */
#define Iodd_RREG_DSC_115                    /* register undefined */
#define Iodd_RREG_DSC_116                    /* register undefined */
#define Iodd_RREG_DSC_117                    /* register undefined */

#define Iodd_WREG_DSC_110(Value)             /* register undefined */
#define Iodd_WREG_DSC_111(Value)             /* register undefined */
#define Iodd_WREG_DSC_112(Value)             /* register undefined */
#define Iodd_WREG_DSC_113(Value)             /* register undefined */
#define Iodd_WREG_DSC_114(Value)             /* register undefined */
#define Iodd_WREG_DSC_115(Value)             /* register undefined */
#define Iodd_WREG_DSC_116(Value)             /* register undefined */
#define Iodd_WREG_DSC_117(Value)             /* register undefined */

#endif

#if                                          \
      defined(__NEC_V850_Dx3__)

#define Iodd_RREG_ILC_110                    /* register undefined */
#define Iodd_RREG_ILC_111                    /* register undefined */
#define Iodd_RREG_ILC_112                    /* register undefined */
#define Iodd_RREG_ILC_113                    /* register undefined */
#define Iodd_RREG_ILC_114                    /* register undefined */
#define Iodd_RREG_ILC_115                    /* register undefined */
#define Iodd_RREG_ILC_116                    /* register undefined */
#define Iodd_RREG_ILC_117                    /* register undefined */

#define Iodd_WREG_ILC_110(Value)             /* register undefined */
#define Iodd_WREG_ILC_111(Value)             /* register undefined */
#define Iodd_WREG_ILC_112(Value)             /* register undefined */
#define Iodd_WREG_ILC_113(Value)             /* register undefined */
#define Iodd_WREG_ILC_114(Value)             /* register undefined */
#define Iodd_WREG_ILC_115(Value)             /* register undefined */
#define Iodd_WREG_ILC_116(Value)             /* register undefined */
#define Iodd_WREG_ILC_117(Value)             /* register undefined */

#endif

#if                                          \
      defined(__NEC_V850_Dx3__)

#define Iodd_RREG_LCDC_110                   /* register undefined */
#define Iodd_RREG_LCDC_111                   /* register undefined */
#define Iodd_RREG_LCDC_112                   /* register undefined */
#define Iodd_RREG_LCDC_113                   /* register undefined */
#define Iodd_RREG_LCDC_114                   /* register undefined */
#define Iodd_RREG_LCDC_115                   /* register undefined */
#define Iodd_RREG_LCDC_116                   /* register undefined */
#define Iodd_RREG_LCDC_117                   /* register undefined */

#define Iodd_WREG_LCDC_110(Value)            /* register undefined */
#define Iodd_WREG_LCDC_111(Value)            /* register undefined */
#define Iodd_WREG_LCDC_112(Value)            /* register undefined */
#define Iodd_WREG_LCDC_113(Value)            /* register undefined */
#define Iodd_WREG_LCDC_114(Value)            /* register undefined */
#define Iodd_WREG_LCDC_115(Value)            /* register undefined */
#define Iodd_WREG_LCDC_116(Value)            /* register undefined */
#define Iodd_WREG_LCDC_117(Value)            /* register undefined */

#endif

#if                                          \
      defined(__NEC_V850_Dx3__)

#define Iodd_RREG_RC_110                     /* register undefined */
#define Iodd_RREG_RC_111                     /* register undefined */
#define Iodd_RREG_RC_112                     /* register undefined */
#define Iodd_RREG_RC_113                     /* register undefined */
#define Iodd_RREG_RC_114                     /* register undefined */
#define Iodd_RREG_RC_115                     /* register undefined */
#define Iodd_RREG_RC_116                     /* register undefined */
#define Iodd_RREG_RC_117                     /* register undefined */
                                             
#define Iodd_WREG_RC_110(Value)              /* register undefined */
#define Iodd_WREG_RC_111(Value)              /* register undefined */
#define Iodd_WREG_RC_112(Value)              /* register undefined */
#define Iodd_WREG_RC_113(Value)              /* register undefined */
#define Iodd_WREG_RC_114(Value)              /* register undefined */
#define Iodd_WREG_RC_115(Value)              /* register undefined */
#define Iodd_WREG_RC_116(Value)              /* register undefined */
#define Iodd_WREG_RC_117(Value)              /* register undefined */

#endif

/* Definitions PORT 12 */

#if                                          \
      defined(__NEC_V850_Dx3__)

#define Iodd_RREG_P_120                      TARG_ReadBit(P12, BIT0)
#define Iodd_RREG_P_121                      TARG_ReadBit(P12, BIT1)
#define Iodd_RREG_P_122                      TARG_ReadBit(P12, BIT2)
#define Iodd_RREG_P_123                      TARG_ReadBit(P12, BIT3)
#define Iodd_RREG_P_124                      TARG_ReadBit(P12, BIT4)
#define Iodd_RREG_P_125                      TARG_ReadBit(P12, BIT5)
#define Iodd_RREG_P_126                      TARG_ReadBit(P12, BIT6)
#define Iodd_RREG_P_127                      TARG_ReadBit(P12, BIT7)

#define Iodd_WREG_P_120(Value)               TARG_WriteBit(P12, BIT0, Value)
#define Iodd_WREG_P_121(Value)               TARG_WriteBit(P12, BIT1, Value)
#define Iodd_WREG_P_122(Value)               TARG_WriteBit(P12, BIT2, Value)
#define Iodd_WREG_P_123(Value)               TARG_WriteBit(P12, BIT3, Value)
#define Iodd_WREG_P_124(Value)               TARG_WriteBit(P12, BIT4, Value)
#define Iodd_WREG_P_125(Value)               TARG_WriteBit(P12, BIT5, Value)
#define Iodd_WREG_P_126(Value)               TARG_WriteBit(P12, BIT6, Value)
#define Iodd_WREG_P_127(Value)               TARG_WriteBit(P12, BIT7, Value)

#endif

#if                                          \
      defined(__NEC_V850_Dx3__)

#define Iodd_RREG_M_120                      TARG_ReadBit(PM12, BIT0)
#define Iodd_RREG_M_121                      TARG_ReadBit(PM12, BIT1)
#define Iodd_RREG_M_122                      TARG_ReadBit(PM12, BIT2)
#define Iodd_RREG_M_123                      TARG_ReadBit(PM12, BIT3)
#define Iodd_RREG_M_124                      TARG_ReadBit(PM12, BIT4)
#define Iodd_RREG_M_125                      TARG_ReadBit(PM12, BIT5)
#define Iodd_RREG_M_126                      TARG_ReadBit(PM12, BIT6)
#define Iodd_RREG_M_127                      TARG_ReadBit(PM12, BIT7)

#define Iodd_WREG_M_120(Value)               TARG_WriteBit(PM12, BIT0, Value)
#define Iodd_WREG_M_121(Value)               TARG_WriteBit(PM12, BIT1, Value)
#define Iodd_WREG_M_122(Value)               TARG_WriteBit(PM12, BIT2, Value)
#define Iodd_WREG_M_123(Value)               TARG_WriteBit(PM12, BIT3, Value)
#define Iodd_WREG_M_124(Value)               TARG_WriteBit(PM12, BIT4, Value)
#define Iodd_WREG_M_125(Value)               TARG_WriteBit(PM12, BIT5, Value)
#define Iodd_WREG_M_126(Value)               TARG_WriteBit(PM12, BIT6, Value)
#define Iodd_WREG_M_127(Value)               TARG_WriteBit(PM12, BIT7, Value)

#endif

#if                                          \
      defined(__NEC_V850_Dx3__)

#define Iodd_RREG_MC_120                     TARG_ReadBit(PMC12, BIT0)
#define Iodd_RREG_MC_121                     TARG_ReadBit(PMC12, BIT1)
#define Iodd_RREG_MC_122                     TARG_ReadBit(PMC12, BIT2)
#define Iodd_RREG_MC_123                     TARG_ReadBit(PMC12, BIT3)
#define Iodd_RREG_MC_124                     TARG_ReadBit(PMC12, BIT4)
#define Iodd_RREG_MC_125                     TARG_ReadBit(PMC12, BIT5)
#define Iodd_RREG_MC_126                     TARG_ReadBit(PMC12, BIT6)
#define Iodd_RREG_MC_127                     TARG_ReadBit(PMC12, BIT7)

#define Iodd_WREG_MC_120(Value)              TARG_WriteBit(PMC12, BIT0, Value)
#define Iodd_WREG_MC_121(Value)              TARG_WriteBit(PMC12, BIT1, Value)
#define Iodd_WREG_MC_122(Value)              TARG_WriteBit(PMC12, BIT2, Value)
#define Iodd_WREG_MC_123(Value)              TARG_WriteBit(PMC12, BIT3, Value)
#define Iodd_WREG_MC_124(Value)              TARG_WriteBit(PMC12, BIT4, Value)
#define Iodd_WREG_MC_125(Value)              TARG_WriteBit(PMC12, BIT5, Value)
#define Iodd_WREG_MC_126(Value)              TARG_WriteBit(PMC12, BIT6, Value)
#define Iodd_WREG_MC_127(Value)              TARG_WriteBit(PMC12, BIT7, Value)

#endif

#if                                          \
      defined(__NEC_V850_Dx3__)

#define Iodd_RREG_ICC_120                    TARG_ReadBit(PICC12, BIT0)
#define Iodd_RREG_ICC_121                    TARG_ReadBit(PICC12, BIT1)
#define Iodd_RREG_ICC_122                    TARG_ReadBit(PICC12, BIT2)
#define Iodd_RREG_ICC_123                    TARG_ReadBit(PICC12, BIT3)
#define Iodd_RREG_ICC_124                    TARG_ReadBit(PICC12, BIT4)
#define Iodd_RREG_ICC_125                    TARG_ReadBit(PICC12, BIT5)
#define Iodd_RREG_ICC_126                    TARG_ReadBit(PICC12, BIT6)
#define Iodd_RREG_ICC_127                    TARG_ReadBit(PICC12, BIT7)

#define Iodd_WREG_ICC_120(Value)             TARG_WriteBit(PICC12, BIT0, Value)
#define Iodd_WREG_ICC_121(Value)             TARG_WriteBit(PICC12, BIT1, Value)
#define Iodd_WREG_ICC_122(Value)             TARG_WriteBit(PICC12, BIT2, Value)
#define Iodd_WREG_ICC_123(Value)             TARG_WriteBit(PICC12, BIT3, Value)
#define Iodd_WREG_ICC_124(Value)             TARG_WriteBit(PICC12, BIT4, Value)
#define Iodd_WREG_ICC_125(Value)             TARG_WriteBit(PICC12, BIT5, Value)
#define Iodd_WREG_ICC_126(Value)             TARG_WriteBit(PICC12, BIT6, Value)
#define Iodd_WREG_ICC_127(Value)             TARG_WriteBit(PICC12, BIT7, Value)

#endif

#if                                          \
      defined(__NEC_V850_Dx3__)

#define Iodd_RREG_ODC_120                    TARG_ReadBit(PODC12, BIT0)
#define Iodd_RREG_ODC_121                    TARG_ReadBit(PODC12, BIT1)
#define Iodd_RREG_ODC_122                    TARG_ReadBit(PODC12, BIT2)
#define Iodd_RREG_ODC_123                    TARG_ReadBit(PODC12, BIT3)
#define Iodd_RREG_ODC_124                    TARG_ReadBit(PODC12, BIT4)
#define Iodd_RREG_ODC_125                    TARG_ReadBit(PODC12, BIT5)
#define Iodd_RREG_ODC_126                    TARG_ReadBit(PODC12, BIT6)
#define Iodd_RREG_ODC_127                    TARG_ReadBit(PODC12, BIT7)

#define Iodd_WREG_ODC_120(Value)             TARG_WriteBit(PODC12, BIT0, Value)
#define Iodd_WREG_ODC_121(Value)             TARG_WriteBit(PODC12, BIT1, Value)
#define Iodd_WREG_ODC_122(Value)             TARG_WriteBit(PODC12, BIT2, Value)
#define Iodd_WREG_ODC_123(Value)             TARG_WriteBit(PODC12, BIT3, Value)
#define Iodd_WREG_ODC_124(Value)             TARG_WriteBit(PODC12, BIT4, Value)
#define Iodd_WREG_ODC_125(Value)             TARG_WriteBit(PODC12, BIT5, Value)
#define Iodd_WREG_ODC_126(Value)             TARG_WriteBit(PODC12, BIT6, Value)
#define Iodd_WREG_ODC_127(Value)             TARG_WriteBit(PODC12, BIT7, Value)

#endif

#if                                          \
      defined(__NEC_V850_Dx3__)

#define Iodd_RREG_PR_120                     TARG_ReadBit(PPR12, BIT0)
#define Iodd_RREG_PR_121                     TARG_ReadBit(PPR12, BIT1)
#define Iodd_RREG_PR_122                     TARG_ReadBit(PPR12, BIT2)
#define Iodd_RREG_PR_123                     TARG_ReadBit(PPR12, BIT3)
#define Iodd_RREG_PR_124                     TARG_ReadBit(PPR12, BIT4)
#define Iodd_RREG_PR_125                     TARG_ReadBit(PPR12, BIT5)
#define Iodd_RREG_PR_126                     TARG_ReadBit(PPR12, BIT6)
#define Iodd_RREG_PR_127                     TARG_ReadBit(PPR12, BIT7)

#define Iodd_WREG_PR_120(Value)              /* write access not defined */
#define Iodd_WREG_PR_121(Value)              /* write access not defined */
#define Iodd_WREG_PR_122(Value)              /* write access not defined */
#define Iodd_WREG_PR_123(Value)              /* write access not defined */
#define Iodd_WREG_PR_124(Value)              /* write access not defined */
#define Iodd_WREG_PR_125(Value)              /* write access not defined */
#define Iodd_WREG_PR_126(Value)              /* write access not defined */
#define Iodd_WREG_PR_127(Value)              /* write access not defined */

#endif

#if                                          \
      defined(__NEC_V850_Dx3__)

#define Iodd_RREG_DSC_120                    /* register undefined */
#define Iodd_RREG_DSC_121                    /* register undefined */
#define Iodd_RREG_DSC_122                    /* register undefined */
#define Iodd_RREG_DSC_123                    /* register undefined */
#define Iodd_RREG_DSC_124                    /* register undefined */
#define Iodd_RREG_DSC_125                    /* register undefined */
#define Iodd_RREG_DSC_126                    /* register undefined */
#define Iodd_RREG_DSC_127                    /* register undefined */

#define Iodd_WREG_DSC_120(Value)             /* register undefined */
#define Iodd_WREG_DSC_121(Value)             /* register undefined */
#define Iodd_WREG_DSC_122(Value)             /* register undefined */
#define Iodd_WREG_DSC_123(Value)             /* register undefined */
#define Iodd_WREG_DSC_124(Value)             /* register undefined */
#define Iodd_WREG_DSC_125(Value)             /* register undefined */
#define Iodd_WREG_DSC_126(Value)             /* register undefined */
#define Iodd_WREG_DSC_127(Value)             /* register undefined */

#endif

#if                                          \
      defined(__NEC_V850_DJ3__)||            \
      defined(__NEC_V850_DL3__)

#define Iodd_RREG_ILC_120                    /* register undefined */
#define Iodd_RREG_ILC_121                    /* register undefined */
#define Iodd_RREG_ILC_122                    /* register undefined */
#define Iodd_RREG_ILC_123                    /* register undefined */
#define Iodd_RREG_ILC_124                    /* register undefined */
#define Iodd_RREG_ILC_125                    /* register undefined */
#define Iodd_RREG_ILC_126                    /* register undefined */
#define Iodd_RREG_ILC_127                    /* register undefined */

#define Iodd_WREG_ILC_120(Value)             /* register undefined */
#define Iodd_WREG_ILC_121(Value)             /* register undefined */
#define Iodd_WREG_ILC_122(Value)             /* register undefined */
#define Iodd_WREG_ILC_123(Value)             /* register undefined */
#define Iodd_WREG_ILC_124(Value)             /* register undefined */
#define Iodd_WREG_ILC_125(Value)             /* register undefined */
#define Iodd_WREG_ILC_126(Value)             /* register undefined */
#define Iodd_WREG_ILC_127(Value)             /* register undefined */

#endif /* defined(__NEC_V850_DJ3__) || defined(__NEC_V850_DL3__) */

#if                                          \
      defined(__NEC_V850_DG3__)

#define Iodd_RREG_ILC_120                    TARG_ReadBit(PILC12, BIT0) 
#define Iodd_RREG_ILC_121                    TARG_ReadBit(PILC12, BIT1) 
#define Iodd_RREG_ILC_122                    TARG_ReadBit(PILC12, BIT2) 
#define Iodd_RREG_ILC_123                    TARG_ReadBit(PILC12, BIT3) 
#define Iodd_RREG_ILC_124                    TARG_ReadBit(PILC12, BIT4)                       
#define Iodd_RREG_ILC_125                    TARG_ReadBit(PILC12, BIT5)                       
#define Iodd_RREG_ILC_126                    TARG_ReadBit(PILC12, BIT6)                       
#define Iodd_RREG_ILC_127                    TARG_ReadBit(PILC12, BIT7)                       
                                                                                              
#define Iodd_WREG_ILC_120(Value)             TARG_WriteBit(PILC12, BIT0, Value)                   
#define Iodd_WREG_ILC_121(Value)             TARG_WriteBit(PILC12, BIT1, Value)                   
#define Iodd_WREG_ILC_122(Value)             TARG_WriteBit(PILC12, BIT2, Value)                   
#define Iodd_WREG_ILC_123(Value)             TARG_WriteBit(PILC12, BIT3, Value)                   
#define Iodd_WREG_ILC_124(Value)             TARG_WriteBit(PILC12, BIT4, Value)               
#define Iodd_WREG_ILC_125(Value)             TARG_WriteBit(PILC12, BIT5, Value)               
#define Iodd_WREG_ILC_126(Value)             TARG_WriteBit(PILC12, BIT6, Value)               
#define Iodd_WREG_ILC_127(Value)             TARG_WriteBit(PILC12, BIT7, Value)               

#endif /* defined(__NEC_V850_DG3__) */

#if                                          \
      defined(__NEC_V850_Dx3__)

#define Iodd_RREG_FC_120                     /* register undefined */
#define Iodd_RREG_FC_121                     /* register undefined */
#define Iodd_RREG_FC_122                     /* register undefined */
#define Iodd_RREG_FC_123                     /* register undefined */
#define Iodd_RREG_FC_124                     /* register undefined */
#define Iodd_RREG_FC_125                     /* register undefined */
#define Iodd_RREG_FC_126                     /* register undefined */
#define Iodd_RREG_FC_127                     /* register undefined */

#define Iodd_WREG_FC_120(Value)              /* register undefined */
#define Iodd_WREG_FC_121(Value)              /* register undefined */
#define Iodd_WREG_FC_122(Value)              /* register undefined */
#define Iodd_WREG_FC_123(Value)              /* register undefined */
#define Iodd_WREG_FC_124(Value)              /* register undefined */
#define Iodd_WREG_FC_125(Value)              /* register undefined */
#define Iodd_WREG_FC_126(Value)              /* register undefined */
#define Iodd_WREG_FC_127(Value)              /* register undefined */

#endif

#if                                          \
      defined(__NEC_V850_Dx3__)

#define Iodd_RREG_LCDC_120                   /* register undefined */
#define Iodd_RREG_LCDC_121                   /* register undefined */
#define Iodd_RREG_LCDC_122                   /* register undefined */
#define Iodd_RREG_LCDC_123                   /* register undefined */
#define Iodd_RREG_LCDC_124                   /* register undefined */
#define Iodd_RREG_LCDC_125                   /* register undefined */
#define Iodd_RREG_LCDC_126                   /* register undefined */
#define Iodd_RREG_LCDC_127                   /* register undefined */

#define Iodd_WREG_LCDC_120(Value)            /* register undefined */
#define Iodd_WREG_LCDC_121(Value)            /* register undefined */
#define Iodd_WREG_LCDC_122(Value)            /* register undefined */
#define Iodd_WREG_LCDC_123(Value)            /* register undefined */
#define Iodd_WREG_LCDC_124(Value)            /* register undefined */
#define Iodd_WREG_LCDC_125(Value)            /* register undefined */
#define Iodd_WREG_LCDC_126(Value)            /* register undefined */
#define Iodd_WREG_LCDC_127(Value)            /* register undefined */

#endif

#if                                          \
      defined(__NEC_V850_DJ3__)||            \
      defined(__NEC_V850_DL3__)

#define Iodd_RREG_RC_120                     /* register undefined */
#define Iodd_RREG_RC_121                     /* register undefined */
#define Iodd_RREG_RC_122                     /* register undefined */
#define Iodd_RREG_RC_123                     /* register undefined */
#define Iodd_RREG_RC_124                     /* register undefined */
#define Iodd_RREG_RC_125                     /* register undefined */
#define Iodd_RREG_RC_126                     /* register undefined */
#define Iodd_RREG_RC_127                     /* register undefined */

#define Iodd_WREG_RC_120(Value)              /* register undefined */
#define Iodd_WREG_RC_121(Value)              /* register undefined */
#define Iodd_WREG_RC_122(Value)              /* register undefined */
#define Iodd_WREG_RC_123(Value)              /* register undefined */
#define Iodd_WREG_RC_124(Value)              /* register undefined */
#define Iodd_WREG_RC_125(Value)              /* register undefined */
#define Iodd_WREG_RC_126(Value)              /* register undefined */
#define Iodd_WREG_RC_127(Value)              /* register undefined */

#endif /* defined(__NEC_V850_DJ3__) || defined(__NEC_V850_DL3__) */

#if                                          \
      defined(__NEC_V850_DG3__)

#define Iodd_RREG_RC_120                     TARG_ReadBit(PRC12, BIT0)
#define Iodd_RREG_RC_121                     /* read access defined but should not be used */
#define Iodd_RREG_RC_122                     /* read access defined but should not be used */
#define Iodd_RREG_RC_123                     /* read access defined but should not be used */
#define Iodd_RREG_RC_124                     /* read access defined but should not be used */
#define Iodd_RREG_RC_125                     /* read access defined but should not be used */
#define Iodd_RREG_RC_126                     /* read access defined but should not be used */
#define Iodd_RREG_RC_127                     /* read access defined but should not be used */

#define Iodd_WREG_RC_120(Value)              TARG_WriteBit(PRC12, BIT0, Value)
#define Iodd_WREG_RC_121(Value)              /* write access not defined */
#define Iodd_WREG_RC_122(Value)              /* write access not defined */
#define Iodd_WREG_RC_123(Value)              /* write access not defined */
#define Iodd_WREG_RC_124(Value)              /* write access not defined */
#define Iodd_WREG_RC_125(Value)              /* write access not defined */
#define Iodd_WREG_RC_126(Value)              /* write access not defined */
#define Iodd_WREG_RC_127(Value)              /* write access not defined */

#endif /* defined(__NEC_V850_DG3__) */

/* Definitions PORT 13 */

#if                                          \
      defined(__NEC_V850_Dx3__)

#define Iodd_RREG_P_130                      TARG_ReadBit(P13, BIT0)
#define Iodd_RREG_P_131                      TARG_ReadBit(P13, BIT1)
#define Iodd_RREG_P_132                      TARG_ReadBit(P13, BIT2)
#define Iodd_RREG_P_133                      TARG_ReadBit(P13, BIT3)
#define Iodd_RREG_P_134                      TARG_ReadBit(P13, BIT4)
#define Iodd_RREG_P_135                      TARG_ReadBit(P13, BIT5)
#define Iodd_RREG_P_136                      TARG_ReadBit(P13, BIT6)
#define Iodd_RREG_P_137                      TARG_ReadBit(P13, BIT7)

#define Iodd_WREG_P_130(Value)               TARG_WriteBit(P13, BIT0, Value)
#define Iodd_WREG_P_131(Value)               TARG_WriteBit(P13, BIT1, Value)
#define Iodd_WREG_P_132(Value)               TARG_WriteBit(P13, BIT2, Value)
#define Iodd_WREG_P_133(Value)               TARG_WriteBit(P13, BIT3, Value)
#define Iodd_WREG_P_134(Value)               TARG_WriteBit(P13, BIT4, Value)
#define Iodd_WREG_P_135(Value)               TARG_WriteBit(P13, BIT5, Value)
#define Iodd_WREG_P_136(Value)               TARG_WriteBit(P13, BIT6, Value)
#define Iodd_WREG_P_137(Value)               TARG_WriteBit(P13, BIT7, Value)

#endif

#if                                          \
      defined(__NEC_V850_Dx3__)

#define Iodd_RREG_M_130                      TARG_ReadBit(PM13, BIT0)
#define Iodd_RREG_M_131                      TARG_ReadBit(PM13, BIT1)
#define Iodd_RREG_M_132                      TARG_ReadBit(PM13, BIT2)
#define Iodd_RREG_M_133                      TARG_ReadBit(PM13, BIT3)
#define Iodd_RREG_M_134                      TARG_ReadBit(PM13, BIT4)
#define Iodd_RREG_M_135                      TARG_ReadBit(PM13, BIT5)
#define Iodd_RREG_M_136                      TARG_ReadBit(PM13, BIT6)
#define Iodd_RREG_M_137                      TARG_ReadBit(PM13, BIT7)

#define Iodd_WREG_M_130(Value)               TARG_WriteBit(PM13, BIT0, Value)
#define Iodd_WREG_M_131(Value)               TARG_WriteBit(PM13, BIT1, Value)
#define Iodd_WREG_M_132(Value)               TARG_WriteBit(PM13, BIT2, Value)
#define Iodd_WREG_M_133(Value)               TARG_WriteBit(PM13, BIT3, Value)
#define Iodd_WREG_M_134(Value)               TARG_WriteBit(PM13, BIT4, Value)
#define Iodd_WREG_M_135(Value)               TARG_WriteBit(PM13, BIT5, Value)
#define Iodd_WREG_M_136(Value)               TARG_WriteBit(PM13, BIT6, Value)
#define Iodd_WREG_M_137(Value)               TARG_WriteBit(PM13, BIT7, Value)

#endif

#if                                          \
      defined(__NEC_V850_Dx3__)

#define Iodd_RREG_MC_130                     TARG_ReadBit(PMC13, BIT0)
#define Iodd_RREG_MC_131                     TARG_ReadBit(PMC13, BIT1)
#define Iodd_RREG_MC_132                     TARG_ReadBit(PMC13, BIT2)
#define Iodd_RREG_MC_133                     TARG_ReadBit(PMC13, BIT3)
#define Iodd_RREG_MC_134                     TARG_ReadBit(PMC13, BIT4)
#define Iodd_RREG_MC_135                     TARG_ReadBit(PMC13, BIT5)
#define Iodd_RREG_MC_136                     TARG_ReadBit(PMC13, BIT6)
#define Iodd_RREG_MC_137                     TARG_ReadBit(PMC13, BIT7)

#define Iodd_WREG_MC_130(Value)              TARG_WriteBit(PMC13, BIT0, Value)
#define Iodd_WREG_MC_131(Value)              TARG_WriteBit(PMC13, BIT1, Value)
#define Iodd_WREG_MC_132(Value)              TARG_WriteBit(PMC13, BIT2, Value)
#define Iodd_WREG_MC_133(Value)              TARG_WriteBit(PMC13, BIT3, Value)
#define Iodd_WREG_MC_134(Value)              TARG_WriteBit(PMC13, BIT4, Value)
#define Iodd_WREG_MC_135(Value)              TARG_WriteBit(PMC13, BIT5, Value)
#define Iodd_WREG_MC_136(Value)              TARG_WriteBit(PMC13, BIT6, Value)
#define Iodd_WREG_MC_137(Value)              TARG_WriteBit(PMC13, BIT7, Value)

#endif

#if                                          \
      defined(__NEC_V850_Dx3__)

#define Iodd_RREG_ICC_130                    TARG_ReadBit(PICC13, BIT0)
#define Iodd_RREG_ICC_131                    TARG_ReadBit(PICC13, BIT1)
#define Iodd_RREG_ICC_132                    TARG_ReadBit(PICC13, BIT2)
#define Iodd_RREG_ICC_133                    TARG_ReadBit(PICC13, BIT3)
#define Iodd_RREG_ICC_134                    TARG_ReadBit(PICC13, BIT4)
#define Iodd_RREG_ICC_135                    TARG_ReadBit(PICC13, BIT5)
#define Iodd_RREG_ICC_136                    TARG_ReadBit(PICC13, BIT6)
#define Iodd_RREG_ICC_137                    TARG_ReadBit(PICC13, BIT7)

#define Iodd_WREG_ICC_130(Value)             TARG_WriteBit(PICC13, BIT0, Value)
#define Iodd_WREG_ICC_131(Value)             TARG_WriteBit(PICC13, BIT1, Value)
#define Iodd_WREG_ICC_132(Value)             TARG_WriteBit(PICC13, BIT2, Value)
#define Iodd_WREG_ICC_133(Value)             TARG_WriteBit(PICC13, BIT3, Value)
#define Iodd_WREG_ICC_134(Value)             TARG_WriteBit(PICC13, BIT4, Value)
#define Iodd_WREG_ICC_135(Value)             TARG_WriteBit(PICC13, BIT5, Value)
#define Iodd_WREG_ICC_136(Value)             TARG_WriteBit(PICC13, BIT6, Value)
#define Iodd_WREG_ICC_137(Value)             TARG_WriteBit(PICC13, BIT7, Value)

#endif

#if                                          \
      defined(__NEC_V850_Dx3__)

#define Iodd_RREG_ODC_130                    TARG_ReadBit(PODC13, BIT0)
#define Iodd_RREG_ODC_131                    TARG_ReadBit(PODC13, BIT1)
#define Iodd_RREG_ODC_132                    TARG_ReadBit(PODC13, BIT2)
#define Iodd_RREG_ODC_133                    TARG_ReadBit(PODC13, BIT3)
#define Iodd_RREG_ODC_134                    TARG_ReadBit(PODC13, BIT4)
#define Iodd_RREG_ODC_135                    TARG_ReadBit(PODC13, BIT5)
#define Iodd_RREG_ODC_136                    TARG_ReadBit(PODC13, BIT6)
#define Iodd_RREG_ODC_137                    TARG_ReadBit(PODC13, BIT7)

#define Iodd_WREG_ODC_130(Value)             TARG_WriteBit(PODC13, BIT0, Value)
#define Iodd_WREG_ODC_131(Value)             TARG_WriteBit(PODC13, BIT1, Value)
#define Iodd_WREG_ODC_132(Value)             TARG_WriteBit(PODC13, BIT2, Value)
#define Iodd_WREG_ODC_133(Value)             TARG_WriteBit(PODC13, BIT3, Value)
#define Iodd_WREG_ODC_134(Value)             TARG_WriteBit(PODC13, BIT4, Value)
#define Iodd_WREG_ODC_135(Value)             TARG_WriteBit(PODC13, BIT5, Value)
#define Iodd_WREG_ODC_136(Value)             TARG_WriteBit(PODC13, BIT6, Value)
#define Iodd_WREG_ODC_137(Value)             TARG_WriteBit(PODC13, BIT7, Value)

#endif

#if                                          \
      defined(__NEC_V850_Dx3__)

#define Iodd_RREG_FC_130                     TARG_ReadBit(PFC13, BIT0)
#define Iodd_RREG_FC_131                     TARG_ReadBit(PFC13, BIT1)
#define Iodd_RREG_FC_132                     TARG_ReadBit(PFC13, BIT2)
#define Iodd_RREG_FC_133                     TARG_ReadBit(PFC13, BIT3)
#define Iodd_RREG_FC_134                     TARG_ReadBit(PFC13, BIT4)
#define Iodd_RREG_FC_135                     TARG_ReadBit(PFC13, BIT5)
#define Iodd_RREG_FC_136                     TARG_ReadBit(PFC13, BIT6)
#define Iodd_RREG_FC_137                     TARG_ReadBit(PFC13, BIT7)

#define Iodd_WREG_FC_130(Value)              TARG_WriteBit(PFC13, BIT0, Value)
#define Iodd_WREG_FC_131(Value)              TARG_WriteBit(PFC13, BIT1, Value)
#define Iodd_WREG_FC_132(Value)              TARG_WriteBit(PFC13, BIT2, Value)
#define Iodd_WREG_FC_133(Value)              TARG_WriteBit(PFC13, BIT3, Value)
#define Iodd_WREG_FC_134(Value)              TARG_WriteBit(PFC13, BIT4, Value)
#define Iodd_WREG_FC_135(Value)              TARG_WriteBit(PFC13, BIT5, Value)
#define Iodd_WREG_FC_136(Value)              TARG_WriteBit(PFC13, BIT6, Value)
#define Iodd_WREG_FC_137(Value)              TARG_WriteBit(PFC13, BIT7, Value)

#endif

#if                                          \
      defined(__NEC_V850_Dx3__)

#define Iodd_RREG_PR_130                     TARG_ReadBit(PPR13, BIT0)
#define Iodd_RREG_PR_131                     TARG_ReadBit(PPR13, BIT1)
#define Iodd_RREG_PR_132                     TARG_ReadBit(PPR13, BIT2)
#define Iodd_RREG_PR_133                     TARG_ReadBit(PPR13, BIT3)
#define Iodd_RREG_PR_134                     TARG_ReadBit(PPR13, BIT4)
#define Iodd_RREG_PR_135                     TARG_ReadBit(PPR13, BIT5)
#define Iodd_RREG_PR_136                     TARG_ReadBit(PPR13, BIT6)
#define Iodd_RREG_PR_137                     TARG_ReadBit(PPR13, BIT7)

#define Iodd_WREG_PR_130(Value)              /* write access not defined */
#define Iodd_WREG_PR_131(Value)              /* write access not defined */
#define Iodd_WREG_PR_132(Value)              /* write access not defined */
#define Iodd_WREG_PR_133(Value)              /* write access not defined */
#define Iodd_WREG_PR_134(Value)              /* write access not defined */
#define Iodd_WREG_PR_135(Value)              /* write access not defined */
#define Iodd_WREG_PR_136(Value)              /* write access not defined */
#define Iodd_WREG_PR_137(Value)              /* write access not defined */

#endif

#if                                          \
      defined(__NEC_V850_Dx3__)

#define Iodd_RREG_DSC_130                    /* register undefined */
#define Iodd_RREG_DSC_131                    /* register undefined */
#define Iodd_RREG_DSC_132                    /* register undefined */
#define Iodd_RREG_DSC_133                    /* register undefined */
#define Iodd_RREG_DSC_134                    /* register undefined */
#define Iodd_RREG_DSC_135                    /* register undefined */
#define Iodd_RREG_DSC_136                    /* register undefined */
#define Iodd_RREG_DSC_137                    /* register undefined */

#define Iodd_WREG_DSC_130(Value)             /* register undefined */
#define Iodd_WREG_DSC_131(Value)             /* register undefined */
#define Iodd_WREG_DSC_132(Value)             /* register undefined */
#define Iodd_WREG_DSC_133(Value)             /* register undefined */
#define Iodd_WREG_DSC_134(Value)             /* register undefined */
#define Iodd_WREG_DSC_135(Value)             /* register undefined */
#define Iodd_WREG_DSC_136(Value)             /* register undefined */
#define Iodd_WREG_DSC_137(Value)             /* register undefined */

#endif

#if                                          \
      defined(__NEC_V850_DJ3__)||            \
      defined(__NEC_V850_DL3__)

#define Iodd_RREG_ILC_130                    /* register undefined */
#define Iodd_RREG_ILC_131                    /* register undefined */
#define Iodd_RREG_ILC_132                    /* register undefined */
#define Iodd_RREG_ILC_133                    /* register undefined */
#define Iodd_RREG_ILC_134                    /* register undefined */
#define Iodd_RREG_ILC_135                    /* register undefined */
#define Iodd_RREG_ILC_136                    /* register undefined */
#define Iodd_RREG_ILC_137                    /* register undefined */

#define Iodd_WREG_ILC_130(Value)             /* register undefined */
#define Iodd_WREG_ILC_131(Value)             /* register undefined */
#define Iodd_WREG_ILC_132(Value)             /* register undefined */
#define Iodd_WREG_ILC_133(Value)             /* register undefined */
#define Iodd_WREG_ILC_134(Value)             /* register undefined */
#define Iodd_WREG_ILC_135(Value)             /* register undefined */
#define Iodd_WREG_ILC_136(Value)             /* register undefined */
#define Iodd_WREG_ILC_137(Value)             /* register undefined */

#endif /* defined(__NEC_V850_DJ3__) || defined(__NEC_V850_DL3__) */

#if                                          \
      defined(__NEC_V850_DG3__)

#define Iodd_RREG_ILC_130                    TARG_ReadBit(PILC13, BIT0) 
#define Iodd_RREG_ILC_131                    TARG_ReadBit(PILC13, BIT1) 
#define Iodd_RREG_ILC_132                    TARG_ReadBit(PILC13, BIT2) 
#define Iodd_RREG_ILC_133                    TARG_ReadBit(PILC13, BIT3) 
#define Iodd_RREG_ILC_134                    TARG_ReadBit(PILC13, BIT4)                       
#define Iodd_RREG_ILC_135                    TARG_ReadBit(PILC13, BIT5)                       
#define Iodd_RREG_ILC_136                    TARG_ReadBit(PILC13, BIT6)                       
#define Iodd_RREG_ILC_137                    TARG_ReadBit(PILC13, BIT7)                       
                                                                                              
#define Iodd_WREG_ILC_130(Value)             TARG_WriteBit(PILC13, BIT0, Value)                   
#define Iodd_WREG_ILC_131(Value)             TARG_WriteBit(PILC13, BIT1, Value)                   
#define Iodd_WREG_ILC_132(Value)             TARG_WriteBit(PILC13, BIT2, Value)                   
#define Iodd_WREG_ILC_133(Value)             TARG_WriteBit(PILC13, BIT3, Value)                   
#define Iodd_WREG_ILC_134(Value)             TARG_WriteBit(PILC13, BIT4, Value)               
#define Iodd_WREG_ILC_135(Value)             TARG_WriteBit(PILC13, BIT5, Value)               
#define Iodd_WREG_ILC_136(Value)             TARG_WriteBit(PILC13, BIT6, Value)               
#define Iodd_WREG_ILC_137(Value)             TARG_WriteBit(PILC13, BIT7, Value)               

#endif /* defined(__NEC_V850_DG3__) */

#if                                          \
      defined(__NEC_V850_Dx3__)

#define Iodd_RREG_LCDC_130                   /* register undefined */
#define Iodd_RREG_LCDC_131                   /* register undefined */
#define Iodd_RREG_LCDC_132                   /* register undefined */
#define Iodd_RREG_LCDC_133                   /* register undefined */
#define Iodd_RREG_LCDC_134                   /* register undefined */
#define Iodd_RREG_LCDC_135                   /* register undefined */
#define Iodd_RREG_LCDC_136                   /* register undefined */
#define Iodd_RREG_LCDC_137                   /* register undefined */

#define Iodd_WREG_LCDC_130(Value)            /* register undefined */
#define Iodd_WREG_LCDC_131(Value)            /* register undefined */
#define Iodd_WREG_LCDC_132(Value)            /* register undefined */
#define Iodd_WREG_LCDC_133(Value)            /* register undefined */
#define Iodd_WREG_LCDC_134(Value)            /* register undefined */
#define Iodd_WREG_LCDC_135(Value)            /* register undefined */
#define Iodd_WREG_LCDC_136(Value)            /* register undefined */
#define Iodd_WREG_LCDC_137(Value)            /* register undefined */

#endif

#if                                          \
      defined(__NEC_V850_DJ3__)||            \
      defined(__NEC_V850_DL3__)

#define Iodd_RREG_RC_130                     /* register undefined */
#define Iodd_RREG_RC_131                     /* register undefined */
#define Iodd_RREG_RC_132                     /* register undefined */
#define Iodd_RREG_RC_133                     /* register undefined */
#define Iodd_RREG_RC_134                     /* register undefined */
#define Iodd_RREG_RC_135                     /* register undefined */
#define Iodd_RREG_RC_136                     /* register undefined */
#define Iodd_RREG_RC_137                     /* register undefined */

#define Iodd_WREG_RC_130(Value)              /* register undefined */
#define Iodd_WREG_RC_131(Value)              /* register undefined */
#define Iodd_WREG_RC_132(Value)              /* register undefined */
#define Iodd_WREG_RC_133(Value)              /* register undefined */
#define Iodd_WREG_RC_134(Value)              /* register undefined */
#define Iodd_WREG_RC_135(Value)              /* register undefined */
#define Iodd_WREG_RC_136(Value)              /* register undefined */
#define Iodd_WREG_RC_137(Value)              /* register undefined */

#endif /* defined(__NEC_V850_DJ3__) || defined(__NEC_V850_DL3__) */

#if                                          \
      defined(__NEC_V850_DG3__)

#define Iodd_RREG_RC_130                     TARG_ReadBit(PRC13, BIT0)
#define Iodd_RREG_RC_131                     /* read access defined but should not be used */
#define Iodd_RREG_RC_132                     /* read access defined but should not be used */
#define Iodd_RREG_RC_133                     /* read access defined but should not be used */
#define Iodd_RREG_RC_134                     /* read access defined but should not be used */
#define Iodd_RREG_RC_135                     /* read access defined but should not be used */
#define Iodd_RREG_RC_136                     /* read access defined but should not be used */
#define Iodd_RREG_RC_137                     /* read access defined but should not be used */

#define Iodd_WREG_RC_130(Value)              TARG_WriteBit(PRC13, BIT0, Value)
#define Iodd_WREG_RC_131(Value)              /* write access not defined */
#define Iodd_WREG_RC_132(Value)              /* write access not defined */
#define Iodd_WREG_RC_133(Value)              /* write access not defined */
#define Iodd_WREG_RC_134(Value)              /* write access not defined */
#define Iodd_WREG_RC_135(Value)              /* write access not defined */
#define Iodd_WREG_RC_136(Value)              /* write access not defined */
#define Iodd_WREG_RC_137(Value)              /* write access not defined */

#endif /* defined(__NEC_V850_DG3__) */

/* Definitions PORT 14 */

#if                                          \
      defined(__NEC_V850_DL3__)

#define Iodd_RREG_P_140                      TARG_ReadBit(P14, BIT0)
#define Iodd_RREG_P_141                      TARG_ReadBit(P14, BIT1)
#define Iodd_RREG_P_142                      TARG_ReadBit(P14, BIT2)
#define Iodd_RREG_P_143                      /* read access defined but should not be used */
#define Iodd_RREG_P_144                      /* read access defined but should not be used */
#define Iodd_RREG_P_145                      /* read access defined but should not be used */
#define Iodd_RREG_P_146                      /* read access defined but should not be used */
#define Iodd_RREG_P_147                      /* read access defined but should not be used */

#define Iodd_WREG_P_140(Value)               TARG_WriteBit(P14, BIT0, Value)
#define Iodd_WREG_P_141(Value)               TARG_WriteBit(P14, BIT1, Value)
#define Iodd_WREG_P_142(Value)               TARG_WriteBit(P14, BIT2, Value)
#define Iodd_WREG_P_143(Value)               /* write access not defined */
#define Iodd_WREG_P_144(Value)               /* write access not defined */
#define Iodd_WREG_P_145(Value)               /* write access not defined */
#define Iodd_WREG_P_146(Value)               /* write access not defined */
#define Iodd_WREG_P_147(Value)               /* write access not defined */

#endif /* defined(__NEC_V850_DL3__) */

#if                                          \
      defined(__NEC_V850_DG3__)||            \
      defined(__NEC_V850_DJ3__)

#define Iodd_RREG_P_140                      /* register undefined */
#define Iodd_RREG_P_141                      /* register undefined */
#define Iodd_RREG_P_142                      /* register undefined */
#define Iodd_RREG_P_143                      /* register undefined */
#define Iodd_RREG_P_144                      /* register undefined */
#define Iodd_RREG_P_145                      /* register undefined */
#define Iodd_RREG_P_146                      /* register undefined */
#define Iodd_RREG_P_147                      /* register undefined */
                                                                     
#define Iodd_WREG_P_140(Value)               /* register undefined */
#define Iodd_WREG_P_141(Value)               /* register undefined */
#define Iodd_WREG_P_142(Value)               /* register undefined */
#define Iodd_WREG_P_143(Value)               /* register undefined */
#define Iodd_WREG_P_144(Value)               /* register undefined */
#define Iodd_WREG_P_145(Value)               /* register undefined */
#define Iodd_WREG_P_146(Value)               /* register undefined */
#define Iodd_WREG_P_147(Value)               /* register undefined */

#endif /* defined(__NEC_V850_DG3__) || defined(__NEC_V850_DJ3__) */

#if                                          \
      defined(__NEC_V850_DL3__)

#define Iodd_RREG_M_140                      TARG_ReadBit(PM14, BIT0)
#define Iodd_RREG_M_141                      TARG_ReadBit(PM14, BIT1)
#define Iodd_RREG_M_142                      TARG_ReadBit(PM14, BIT2)
#define Iodd_RREG_M_143                      /* read access defined but should not be used */
#define Iodd_RREG_M_144                      /* read access defined but should not be used */
#define Iodd_RREG_M_145                      /* read access defined but should not be used */
#define Iodd_RREG_M_146                      /* read access defined but should not be used */
#define Iodd_RREG_M_147                      /* read access defined but should not be used */

#define Iodd_WREG_M_140(Value)               TARG_WriteBit(PM14, BIT0, Value)
#define Iodd_WREG_M_141(Value)               TARG_WriteBit(PM14, BIT1, Value)
#define Iodd_WREG_M_142(Value)               TARG_WriteBit(PM14, BIT2, Value)
#define Iodd_WREG_M_143(Value)               /* write access not defined */
#define Iodd_WREG_M_144(Value)               /* write access not defined */
#define Iodd_WREG_M_145(Value)               /* write access not defined */
#define Iodd_WREG_M_146(Value)               /* write access not defined */
#define Iodd_WREG_M_147(Value)               /* write access not defined */

#endif /* defined(__NEC_V850_DL3__) */

#if                                          \
      defined(__NEC_V850_DG3__)||            \
      defined(__NEC_V850_DJ3__)

#define Iodd_RREG_M_140                      /* register undefined */
#define Iodd_RREG_M_141                      /* register undefined */
#define Iodd_RREG_M_142                      /* register undefined */
#define Iodd_RREG_M_143                      /* register undefined */
#define Iodd_RREG_M_144                      /* register undefined */
#define Iodd_RREG_M_145                      /* register undefined */
#define Iodd_RREG_M_146                      /* register undefined */
#define Iodd_RREG_M_147                      /* register undefined */
                                                                     
#define Iodd_WREG_M_140(Value)               /* register undefined */
#define Iodd_WREG_M_141(Value)               /* register undefined */
#define Iodd_WREG_M_142(Value)               /* register undefined */
#define Iodd_WREG_M_143(Value)               /* register undefined */
#define Iodd_WREG_M_144(Value)               /* register undefined */
#define Iodd_WREG_M_145(Value)               /* register undefined */
#define Iodd_WREG_M_146(Value)               /* register undefined */
#define Iodd_WREG_M_147(Value)               /* register undefined */

#endif /* defined(__NEC_V850_DG3__) || defined(__NEC_V850_DJ3__) */

#if                                          \
      defined(__NEC_V850_DL3__)

#define Iodd_RREG_MC_140                     TARG_ReadBit(PMC14, BIT0)
#define Iodd_RREG_MC_141                     TARG_ReadBit(PMC14, BIT1)
#define Iodd_RREG_MC_142                     TARG_ReadBit(PMC14, BIT2)
#define Iodd_RREG_MC_143                     TARG_ReadBit(PMC14, BIT3)
#define Iodd_RREG_MC_144                     /* read access defined but should not be used */
#define Iodd_RREG_MC_145                     /* read access defined but should not be used */
#define Iodd_RREG_MC_146                     /* read access defined but should not be used */
#define Iodd_RREG_MC_147                     /* read access defined but should not be used */

#define Iodd_WREG_MC_140(Value)              TARG_WriteBit(PMC14, BIT0, Value)
#define Iodd_WREG_MC_141(Value)              TARG_WriteBit(PMC14, BIT1, Value)
#define Iodd_WREG_MC_142(Value)              TARG_WriteBit(PMC14, BIT2, Value)
#define Iodd_WREG_MC_143(Value)              TARG_WriteBit(PMC14, BIT3, Value)
#define Iodd_WREG_MC_144(Value)              /* write access not defined */
#define Iodd_WREG_MC_145(Value)              /* write access not defined */
#define Iodd_WREG_MC_146(Value)              /* write access not defined */
#define Iodd_WREG_MC_147(Value)              /* write access not defined */

#endif /* defined(__NEC_V850_DL3__) */

#if                                          \
      defined(__NEC_V850_DG3__)||            \
      defined(__NEC_V850_DJ3__)

#define Iodd_RREG_MC_140                     /* register undefined */
#define Iodd_RREG_MC_141                     /* register undefined */
#define Iodd_RREG_MC_142                     /* register undefined */
#define Iodd_RREG_MC_143                     /* register undefined */
#define Iodd_RREG_MC_144                     /* register undefined */
#define Iodd_RREG_MC_145                     /* register undefined */
#define Iodd_RREG_MC_146                     /* register undefined */
#define Iodd_RREG_MC_147                     /* register undefined */
                                                                     
#define Iodd_WREG_MC_140(Value)              /* register undefined */
#define Iodd_WREG_MC_141(Value)              /* register undefined */
#define Iodd_WREG_MC_142(Value)              /* register undefined */
#define Iodd_WREG_MC_143(Value)              /* register undefined */
#define Iodd_WREG_MC_144(Value)              /* register undefined */
#define Iodd_WREG_MC_145(Value)              /* register undefined */
#define Iodd_WREG_MC_146(Value)              /* register undefined */
#define Iodd_WREG_MC_147(Value)              /* register undefined */

#endif /* defined(__NEC_V850_DG3__) || defined(__NEC_V850_DJ3__) */

#if                                          \
      defined(__NEC_V850_DL3__)

#define Iodd_RREG_PR_140                     TARG_ReadBit(PPR14, BIT0)
#define Iodd_RREG_PR_141                     TARG_ReadBit(PPR14, BIT1)
#define Iodd_RREG_PR_142                     TARG_ReadBit(PPR14, BIT2)
#define Iodd_RREG_PR_143                     /* read access defined but should not be used */
#define Iodd_RREG_PR_144                     /* read access defined but should not be used */
#define Iodd_RREG_PR_145                     /* read access defined but should not be used */
#define Iodd_RREG_PR_146                     /* read access defined but should not be used */
#define Iodd_RREG_PR_147                     /* read access defined but should not be used */

#define Iodd_WREG_PR_140(Value)              /* write access not defined */
#define Iodd_WREG_PR_141(Value)              /* write access not defined */
#define Iodd_WREG_PR_142(Value)              /* write access not defined */
#define Iodd_WREG_PR_143(Value)              /* write access not defined */
#define Iodd_WREG_PR_144(Value)              /* write access not defined */
#define Iodd_WREG_PR_145(Value)              /* write access not defined */
#define Iodd_WREG_PR_146(Value)              /* write access not defined */
#define Iodd_WREG_PR_147(Value)              /* write access not defined */

#endif /* defined(__NEC_V850_DL3__) */

#if                                          \
      defined(__NEC_V850_DG3__)||            \
      defined(__NEC_V850_DJ3__)

#define Iodd_RREG_PR_140                     /* register undefined */
#define Iodd_RREG_PR_141                     /* register undefined */
#define Iodd_RREG_PR_142                     /* register undefined */
#define Iodd_RREG_PR_143                     /* register undefined */
#define Iodd_RREG_PR_144                     /* register undefined */
#define Iodd_RREG_PR_145                     /* register undefined */
#define Iodd_RREG_PR_146                     /* register undefined */
#define Iodd_RREG_PR_147                     /* register undefined */
                                                                     
#define Iodd_WREG_PR_140(Value)              /* register undefined */
#define Iodd_WREG_PR_141(Value)              /* register undefined */
#define Iodd_WREG_PR_142(Value)              /* register undefined */
#define Iodd_WREG_PR_143(Value)              /* register undefined */
#define Iodd_WREG_PR_144(Value)              /* register undefined */
#define Iodd_WREG_PR_145(Value)              /* register undefined */
#define Iodd_WREG_PR_146(Value)              /* register undefined */
#define Iodd_WREG_PR_147(Value)              /* register undefined */

#endif /* defined(__NEC_V850_DG3__) || defined(__NEC_V850_DJ3__) */

#if                                          \
      defined(__NEC_V850_Dx3__)

#define Iodd_RREG_DSC_140                    /* register undefined */
#define Iodd_RREG_DSC_141                    /* register undefined */
#define Iodd_RREG_DSC_142                    /* register undefined */
#define Iodd_RREG_DSC_143                    /* register undefined */
#define Iodd_RREG_DSC_144                    /* register undefined */
#define Iodd_RREG_DSC_145                    /* register undefined */
#define Iodd_RREG_DSC_146                    /* register undefined */
#define Iodd_RREG_DSC_147                    /* register undefined */

#define Iodd_WREG_DSC_140(Value)             /* register undefined */
#define Iodd_WREG_DSC_141(Value)             /* register undefined */
#define Iodd_WREG_DSC_142(Value)             /* register undefined */
#define Iodd_WREG_DSC_143(Value)             /* register undefined */
#define Iodd_WREG_DSC_144(Value)             /* register undefined */
#define Iodd_WREG_DSC_145(Value)             /* register undefined */
#define Iodd_WREG_DSC_146(Value)             /* register undefined */
#define Iodd_WREG_DSC_147(Value)             /* register undefined */

#endif

#if                                          \
      defined(__NEC_V850_Dx3__)

#define Iodd_RREG_ICC_140                    /* register undefined */
#define Iodd_RREG_ICC_141                    /* register undefined */
#define Iodd_RREG_ICC_142                    /* register undefined */
#define Iodd_RREG_ICC_143                    /* register undefined */
#define Iodd_RREG_ICC_144                    /* register undefined */
#define Iodd_RREG_ICC_145                    /* register undefined */
#define Iodd_RREG_ICC_146                    /* register undefined */
#define Iodd_RREG_ICC_147                    /* register undefined */

#define Iodd_WREG_ICC_140(Value)             /* register undefined */
#define Iodd_WREG_ICC_141(Value)             /* register undefined */
#define Iodd_WREG_ICC_142(Value)             /* register undefined */
#define Iodd_WREG_ICC_143(Value)             /* register undefined */
#define Iodd_WREG_ICC_144(Value)             /* register undefined */
#define Iodd_WREG_ICC_145(Value)             /* register undefined */
#define Iodd_WREG_ICC_146(Value)             /* register undefined */
#define Iodd_WREG_ICC_147(Value)             /* register undefined */

#endif

#if                                          \
      defined(__NEC_V850_Dx3__)

#define Iodd_RREG_ILC_140                    /* register undefined */
#define Iodd_RREG_ILC_141                    /* register undefined */
#define Iodd_RREG_ILC_142                    /* register undefined */
#define Iodd_RREG_ILC_143                    /* register undefined */
#define Iodd_RREG_ILC_144                    /* register undefined */
#define Iodd_RREG_ILC_145                    /* register undefined */
#define Iodd_RREG_ILC_146                    /* register undefined */
#define Iodd_RREG_ILC_147                    /* register undefined */

#define Iodd_WREG_ILC_140(Value)             /* register undefined */
#define Iodd_WREG_ILC_141(Value)             /* register undefined */
#define Iodd_WREG_ILC_142(Value)             /* register undefined */
#define Iodd_WREG_ILC_143(Value)             /* register undefined */
#define Iodd_WREG_ILC_144(Value)             /* register undefined */
#define Iodd_WREG_ILC_145(Value)             /* register undefined */
#define Iodd_WREG_ILC_146(Value)             /* register undefined */
#define Iodd_WREG_ILC_147(Value)             /* register undefined */

#endif

#if                                          \
      defined(__NEC_V850_Dx3__)

#define Iodd_RREG_ODC_140                    /* register undefined */
#define Iodd_RREG_ODC_141                    /* register undefined */
#define Iodd_RREG_ODC_142                    /* register undefined */
#define Iodd_RREG_ODC_143                    /* register undefined */
#define Iodd_RREG_ODC_144                    /* register undefined */
#define Iodd_RREG_ODC_145                    /* register undefined */
#define Iodd_RREG_ODC_146                    /* register undefined */
#define Iodd_RREG_ODC_147                    /* register undefined */

#define Iodd_WREG_ODC_140(Value)             /* register undefined */
#define Iodd_WREG_ODC_141(Value)             /* register undefined */
#define Iodd_WREG_ODC_142(Value)             /* register undefined */
#define Iodd_WREG_ODC_143(Value)             /* register undefined */
#define Iodd_WREG_ODC_144(Value)             /* register undefined */
#define Iodd_WREG_ODC_145(Value)             /* register undefined */
#define Iodd_WREG_ODC_146(Value)             /* register undefined */
#define Iodd_WREG_ODC_147(Value)             /* register undefined */

#endif

#if                                          \
      defined(__NEC_V850_Dx3__)

#define Iodd_RREG_FC_140                     /* register undefined */
#define Iodd_RREG_FC_141                     /* register undefined */
#define Iodd_RREG_FC_142                     /* register undefined */
#define Iodd_RREG_FC_143                     /* register undefined */
#define Iodd_RREG_FC_144                     /* register undefined */
#define Iodd_RREG_FC_145                     /* register undefined */
#define Iodd_RREG_FC_146                     /* register undefined */
#define Iodd_RREG_FC_147                     /* register undefined */

#define Iodd_WREG_FC_140(Value)              /* register undefined */
#define Iodd_WREG_FC_141(Value)              /* register undefined */
#define Iodd_WREG_FC_142(Value)              /* register undefined */
#define Iodd_WREG_FC_143(Value)              /* register undefined */
#define Iodd_WREG_FC_144(Value)              /* register undefined */
#define Iodd_WREG_FC_145(Value)              /* register undefined */
#define Iodd_WREG_FC_146(Value)              /* register undefined */
#define Iodd_WREG_FC_147(Value)              /* register undefined */

#endif

#if                                          \
      defined(__NEC_V850_Dx3__)

#define Iodd_RREG_LCDC_140                   /* register undefined */
#define Iodd_RREG_LCDC_141                   /* register undefined */
#define Iodd_RREG_LCDC_142                   /* register undefined */
#define Iodd_RREG_LCDC_143                   /* register undefined */
#define Iodd_RREG_LCDC_144                   /* register undefined */
#define Iodd_RREG_LCDC_145                   /* register undefined */
#define Iodd_RREG_LCDC_146                   /* register undefined */
#define Iodd_RREG_LCDC_147                   /* register undefined */

#define Iodd_WREG_LCDC_140(Value)            /* register undefined */
#define Iodd_WREG_LCDC_141(Value)            /* register undefined */
#define Iodd_WREG_LCDC_142(Value)            /* register undefined */
#define Iodd_WREG_LCDC_143(Value)            /* register undefined */
#define Iodd_WREG_LCDC_144(Value)            /* register undefined */
#define Iodd_WREG_LCDC_145(Value)            /* register undefined */
#define Iodd_WREG_LCDC_146(Value)            /* register undefined */
#define Iodd_WREG_LCDC_147(Value)            /* register undefined */

#endif

#if                                          \
      defined(__NEC_V850_Dx3__)

#define Iodd_RREG_RC_140                   /* register undefined */
#define Iodd_RREG_RC_141                   /* register undefined */
#define Iodd_RREG_RC_142                   /* register undefined */
#define Iodd_RREG_RC_143                   /* register undefined */
#define Iodd_RREG_RC_144                   /* register undefined */
#define Iodd_RREG_RC_145                   /* register undefined */
#define Iodd_RREG_RC_146                   /* register undefined */
#define Iodd_RREG_RC_147                   /* register undefined */

#define Iodd_WREG_RC_140(Value)            /* register undefined */
#define Iodd_WREG_RC_141(Value)            /* register undefined */
#define Iodd_WREG_RC_142(Value)            /* register undefined */
#define Iodd_WREG_RC_143(Value)            /* register undefined */
#define Iodd_WREG_RC_144(Value)            /* register undefined */
#define Iodd_WREG_RC_145(Value)            /* register undefined */
#define Iodd_WREG_RC_146(Value)            /* register undefined */
#define Iodd_WREG_RC_147(Value)            /* register undefined */

#endif

/*______ E N D _____ (iodd_priv_v850_dx3.h) __________________________________*/
