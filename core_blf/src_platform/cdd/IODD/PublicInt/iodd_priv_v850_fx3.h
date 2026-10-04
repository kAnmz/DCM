/******************************************************************************/
/*@F_NAME:           iodd_priv_v850_fx3.h                                     */
/*@F_PURPOSE:        Private header for Logic port I/O driver                 */
/*@F_CREATED_BY:     Cedric LE LABOUSSE                                       */
/*@F_CREATION_DATE:  12/12/2006                                               */
/*@F_MPROC_TYPE:     Nec V850 Fx3                                             */
/************************************** (C) Copyright 2010 Magneti Marelli ****/


/*______ I N C L U D E - F I L E S ___________________________________________*/


/*______ P R I V A T E - D E F I N E S _______________________________________*/

/* Definitions PORT 0 */

#if                                          \
      defined(__NEC_V850_Fx3__)

#define Iodd_RREG_P_00                       TARG_ReadBit(P0, BIT0)
#define Iodd_RREG_P_01                       TARG_ReadBit(P0, BIT1)
#define Iodd_RREG_P_02                       TARG_ReadBit(P0, BIT2)
#define Iodd_RREG_P_03                       TARG_ReadBit(P0, BIT3)
#define Iodd_RREG_P_04                       TARG_ReadBit(P0, BIT4)
#define Iodd_RREG_P_05                       TARG_ReadBit(P0, BIT5)
#define Iodd_RREG_P_06                       TARG_ReadBit(P0, BIT6)
#define Iodd_RREG_P_07                       /* read access defined but should not be used */

#define Iodd_WREG_P_00(Value)                TARG_WriteBit(P0, BIT0, Value)
#define Iodd_WREG_P_01(Value)                TARG_WriteBit(P0, BIT1, Value)
#define Iodd_WREG_P_02(Value)                TARG_WriteBit(P0, BIT2, Value)
#define Iodd_WREG_P_03(Value)                TARG_WriteBit(P0, BIT3, Value)
#define Iodd_WREG_P_04(Value)                TARG_WriteBit(P0, BIT4, Value)
#define Iodd_WREG_P_05(Value)                TARG_WriteBit(P0, BIT5, Value)
#define Iodd_WREG_P_06(Value)                TARG_WriteBit(P0, BIT6, Value)
#define Iodd_WREG_P_07(Value)                /* write access not defined */

#endif

#if                                          \
      defined(__NEC_V850_Fx3__)

#define Iodd_RREG_M_00                       TARG_ReadBit(PM0, BIT0)
#define Iodd_RREG_M_01                       TARG_ReadBit(PM0, BIT1)
#define Iodd_RREG_M_02                       TARG_ReadBit(PM0, BIT2)
#define Iodd_RREG_M_03                       TARG_ReadBit(PM0, BIT3)
#define Iodd_RREG_M_04                       TARG_ReadBit(PM0, BIT4)
#define Iodd_RREG_M_05                       TARG_ReadBit(PM0, BIT5)
#define Iodd_RREG_M_06                       TARG_ReadBit(PM0, BIT6)
#define Iodd_RREG_M_07                       /* read access defined but should not be used */

#define Iodd_WREG_M_00(Value)                TARG_WriteBit(PM0, BIT0, Value)
#define Iodd_WREG_M_01(Value)                TARG_WriteBit(PM0, BIT1, Value)
#define Iodd_WREG_M_02(Value)                TARG_WriteBit(PM0, BIT2, Value)
#define Iodd_WREG_M_03(Value)                TARG_WriteBit(PM0, BIT3, Value)
#define Iodd_WREG_M_04(Value)                TARG_WriteBit(PM0, BIT4, Value)
#define Iodd_WREG_M_05(Value)                TARG_WriteBit(PM0, BIT5, Value)
#define Iodd_WREG_M_06(Value)                TARG_WriteBit(PM0, BIT6, Value)
#define Iodd_WREG_M_07(Value)                /* write access not defined */

#endif

#if                                          \
      defined(__NEC_V850_Fx3__)

#define Iodd_RREG_MC_00                      TARG_ReadBit(PMC0, BIT0)
#define Iodd_RREG_MC_01                      TARG_ReadBit(PMC0, BIT1)
#define Iodd_RREG_MC_02                      TARG_ReadBit(PMC0, BIT2)
#define Iodd_RREG_MC_03                      TARG_ReadBit(PMC0, BIT3)
#define Iodd_RREG_MC_04                      TARG_ReadBit(PMC0, BIT4)
#define Iodd_RREG_MC_05                      TARG_ReadBit(PMC0, BIT5)
#define Iodd_RREG_MC_06                      TARG_ReadBit(PMC0, BIT6)
#define Iodd_RREG_MC_07                      /* read access defined but should not be used */

#define Iodd_WREG_MC_00(Value)               TARG_WriteBit(PMC0, BIT0, Value)
#define Iodd_WREG_MC_01(Value)               TARG_WriteBit(PMC0, BIT1, Value)
#define Iodd_WREG_MC_02(Value)               TARG_WriteBit(PMC0, BIT2, Value)
#define Iodd_WREG_MC_03(Value)               TARG_WriteBit(PMC0, BIT3, Value)
#define Iodd_WREG_MC_04(Value)               TARG_WriteBit(PMC0, BIT4, Value)
#define Iodd_WREG_MC_05(Value)               TARG_WriteBit(PMC0, BIT5, Value)
#define Iodd_WREG_MC_06(Value)               TARG_WriteBit(PMC0, BIT6, Value)
#define Iodd_WREG_MC_07(Value)               /* write access not defined */

#endif

#if                                          \
      defined(__NEC_V850_Fx3__)

#define Iodd_RREG_FC_00                      TARG_ReadBit(PFC0, BIT0)
#define Iodd_RREG_FC_01                      TARG_ReadBit(PFC0, BIT1)
#define Iodd_RREG_FC_02                      TARG_ReadBit(PFC0, BIT2)
#define Iodd_RREG_FC_03                      TARG_ReadBit(PFC0, BIT3)
#define Iodd_RREG_FC_04                      TARG_ReadBit(PFC0, BIT4)
#define Iodd_RREG_FC_05                      /* read access defined but should not be used */
#define Iodd_RREG_FC_06                      TARG_ReadBit(PFC0, BIT6)
#define Iodd_RREG_FC_07                      /* read access defined but should not be used */

#define Iodd_WREG_FC_00(Value)               TARG_WriteBit(PFC0, BIT0, Value)
#define Iodd_WREG_FC_01(Value)               TARG_WriteBit(PFC0, BIT1, Value)
#define Iodd_WREG_FC_02(Value)               TARG_WriteBit(PFC0, BIT2, Value)
#define Iodd_WREG_FC_03(Value)               TARG_WriteBit(PFC0, BIT3, Value)
#define Iodd_WREG_FC_04(Value)               TARG_WriteBit(PFC0, BIT4, Value)
#define Iodd_WREG_FC_05(Value)               /* write access not defined */
#define Iodd_WREG_FC_06(Value)               TARG_WriteBit(PFC0, BIT6, Value)
#define Iodd_WREG_FC_07(Value)               /* write access not defined */

#endif

#if                                          \
      defined(__NEC_V850_Fx3__)

#define Iodd_RREG_FCE_00                     /* read access defined but should not be used */
#define Iodd_RREG_FCE_01                     /* read access defined but should not be used */
#define Iodd_RREG_FCE_02                     TARG_ReadBit(PFCE0, BIT2)
#define Iodd_RREG_FCE_03                     TARG_ReadBit(PFCE0, BIT3)
#define Iodd_RREG_FCE_04                     /* read access defined but should not be used */
#define Iodd_RREG_FCE_05                     /* read access defined but should not be used */
#define Iodd_RREG_FCE_06                     /* read access defined but should not be used */
#define Iodd_RREG_FCE_07                     /* read access defined but should not be used */

#define Iodd_WREG_FCE_00(Value)              /* write access not defined */
#define Iodd_WREG_FCE_01(Value)              /* write access not defined */
#define Iodd_WREG_FCE_02(Value)              TARG_WriteBit(PFCE0, BIT2, Value)
#define Iodd_WREG_FCE_03(Value)              TARG_WriteBit(PFCE0, BIT3, Value)
#define Iodd_WREG_FCE_04(Value)              /* write access not defined */
#define Iodd_WREG_FCE_05(Value)              /* write access not defined */
#define Iodd_WREG_FCE_06(Value)              /* write access not defined */
#define Iodd_WREG_FCE_07(Value)              /* write access not defined */

#endif

#if                                          \
      defined(__NEC_V850_Fx3__)

#define Iodd_RREG_PU_00                      TARG_ReadBit(PU0, BIT0)
#define Iodd_RREG_PU_01                      TARG_ReadBit(PU0, BIT1)
#define Iodd_RREG_PU_02                      TARG_ReadBit(PU0, BIT2)
#define Iodd_RREG_PU_03                      TARG_ReadBit(PU0, BIT3)
#define Iodd_RREG_PU_04                      TARG_ReadBit(PU0, BIT4)
#define Iodd_RREG_PU_05                      TARG_ReadBit(PU0, BIT5)
#define Iodd_RREG_PU_06                      TARG_ReadBit(PU0, BIT6)
#define Iodd_RREG_PU_07                      /* read access defined but should not be used */

#define Iodd_WREG_PU_00(Value)               TARG_WriteBit(PU0, BIT0, Value)
#define Iodd_WREG_PU_01(Value)               TARG_WriteBit(PU0, BIT1, Value)
#define Iodd_WREG_PU_02(Value)               TARG_WriteBit(PU0, BIT2, Value)
#define Iodd_WREG_PU_03(Value)               TARG_WriteBit(PU0, BIT3, Value)
#define Iodd_WREG_PU_04(Value)               TARG_WriteBit(PU0, BIT4, Value)
#define Iodd_WREG_PU_05(Value)               TARG_WriteBit(PU0, BIT5, Value)
#define Iodd_WREG_PU_06(Value)               TARG_WriteBit(PU0, BIT6, Value)
#define Iodd_WREG_PU_07(Value)               /* write access not defined */

#endif

#if                                          \
      defined(__NEC_V850_Fx3__)

#define Iodd_RREG_PF_00                      /* register undefined */
#define Iodd_RREG_PF_01                      /* register undefined */
#define Iodd_RREG_PF_02                      /* register undefined */
#define Iodd_RREG_PF_03                      /* register undefined */
#define Iodd_RREG_PF_04                      /* register undefined */
#define Iodd_RREG_PF_05                      /* register undefined */
#define Iodd_RREG_PF_06                      /* register undefined */
#define Iodd_RREG_PF_07                      /* register undefined */

#define Iodd_WREG_PF_00(Value)               /* register undefined */
#define Iodd_WREG_PF_01(Value)               /* register undefined */
#define Iodd_WREG_PF_02(Value)               /* register undefined */
#define Iodd_WREG_PF_03(Value)               /* register undefined */
#define Iodd_WREG_PF_04(Value)               /* register undefined */
#define Iodd_WREG_PF_05(Value)               /* register undefined */
#define Iodd_WREG_PF_06(Value)               /* register undefined */
#define Iodd_WREG_PF_07(Value)               /* register undefined */

#endif

/* Definitions PORT 1 */

#if                                          \
      defined(__NEC_V850_FG3_F3374__)||      \
      defined(__NEC_V850_FG3_F3375__)||      \
      defined(__NEC_V850_FG3_F3376__)||      \
      defined(__NEC_V850_FG3_F3377__)||      \
      defined(__NEC_V850_FJ3_F3378__)||      \
      defined(__NEC_V850_FJ3_F3379__)||      \
      defined(__NEC_V850_FJ3_F3380__)||      \
      defined(__NEC_V850_FJ3_F3381__)||      \
      defined(__NEC_V850_FJ3_F3382__)||      \
      defined(__NEC_V850_FK3_F3383__)||      \
      defined(__NEC_V850_FK3_F3384__)||      \
      defined(__NEC_V850_FK3_F3385__)

#define Iodd_RREG_P_10                       TARG_ReadBit(P1, BIT0)
#define Iodd_RREG_P_11                       TARG_ReadBit(P1, BIT1)
#define Iodd_RREG_P_12                       /* read access defined but should not be used */
#define Iodd_RREG_P_13                       /* read access defined but should not be used */
#define Iodd_RREG_P_14                       /* read access defined but should not be used */
#define Iodd_RREG_P_15                       /* read access defined but should not be used */
#define Iodd_RREG_P_16                       /* read access defined but should not be used */
#define Iodd_RREG_P_17                       /* read access defined but should not be used */

#define Iodd_WREG_P_10(Value)                TARG_WriteBit(P1, BIT0, Value)
#define Iodd_WREG_P_11(Value)                TARG_WriteBit(P1, BIT1, Value)
#define Iodd_WREG_P_12(Value)                /* write access not defined */
#define Iodd_WREG_P_13(Value)                /* write access not defined */
#define Iodd_WREG_P_14(Value)                /* write access not defined */
#define Iodd_WREG_P_15(Value)                /* write access not defined */
#define Iodd_WREG_P_16(Value)                /* write access not defined */
#define Iodd_WREG_P_17(Value)                /* write access not defined */

#endif

#if                                          \
      defined(__NEC_V850_FG3_F3374__)||      \
      defined(__NEC_V850_FG3_F3375__)||      \
      defined(__NEC_V850_FG3_F3376__)||      \
      defined(__NEC_V850_FG3_F3377__)||      \
      defined(__NEC_V850_FJ3_F3378__)||      \
      defined(__NEC_V850_FJ3_F3379__)||      \
      defined(__NEC_V850_FJ3_F3380__)||      \
      defined(__NEC_V850_FJ3_F3381__)||      \
      defined(__NEC_V850_FJ3_F3382__)||      \
      defined(__NEC_V850_FK3_F3383__)||      \
      defined(__NEC_V850_FK3_F3384__)||      \
      defined(__NEC_V850_FK3_F3385__)

#define Iodd_RREG_M_10                       TARG_ReadBit(PM1, BIT0)
#define Iodd_RREG_M_11                       TARG_ReadBit(PM1, BIT1)
#define Iodd_RREG_M_12                       /* read access defined but should not be used */
#define Iodd_RREG_M_13                       /* read access defined but should not be used */
#define Iodd_RREG_M_14                       /* read access defined but should not be used */
#define Iodd_RREG_M_15                       /* read access defined but should not be used */
#define Iodd_RREG_M_16                       /* read access defined but should not be used */
#define Iodd_RREG_M_17                       /* read access defined but should not be used */

#define Iodd_WREG_M_10(Value)                TARG_WriteBit(PM1, BIT0, Value)
#define Iodd_WREG_M_11(Value)                TARG_WriteBit(PM1, BIT1, Value)
#define Iodd_WREG_M_12(Value)                /* write access not defined */
#define Iodd_WREG_M_13(Value)                /* write access not defined */
#define Iodd_WREG_M_14(Value)                /* write access not defined */
#define Iodd_WREG_M_15(Value)                /* write access not defined */
#define Iodd_WREG_M_16(Value)                /* write access not defined */
#define Iodd_WREG_M_17(Value)                /* write access not defined */

#endif

#if                                          \
      defined(__NEC_V850_FG3_F3374__)||      \
      defined(__NEC_V850_FG3_F3375__)||      \
      defined(__NEC_V850_FG3_F3376__)||      \
      defined(__NEC_V850_FG3_F3377__)||      \
      defined(__NEC_V850_FJ3_F3378__)||      \
      defined(__NEC_V850_FJ3_F3379__)||      \
      defined(__NEC_V850_FJ3_F3380__)||      \
      defined(__NEC_V850_FJ3_F3381__)||      \
      defined(__NEC_V850_FJ3_F3382__)||      \
      defined(__NEC_V850_FK3_F3383__)||      \
      defined(__NEC_V850_FK3_F3384__)||      \
      defined(__NEC_V850_FK3_F3385__)

#define Iodd_RREG_MC_10                      TARG_ReadBit(PMC1, BIT0)
#define Iodd_RREG_MC_11                      TARG_ReadBit(PMC1, BIT1)
#define Iodd_RREG_MC_12                      /* read access defined but should not be used */
#define Iodd_RREG_MC_13                      /* read access defined but should not be used */
#define Iodd_RREG_MC_14                      /* read access defined but should not be used */
#define Iodd_RREG_MC_15                      /* read access defined but should not be used */
#define Iodd_RREG_MC_16                      /* read access defined but should not be used */
#define Iodd_RREG_MC_17                      /* read access defined but should not be used */

#define Iodd_WREG_MC_10(Value)               TARG_WriteBit(PMC1, BIT0, Value)
#define Iodd_WREG_MC_11(Value)               TARG_WriteBit(PMC1, BIT1, Value)
#define Iodd_WREG_MC_12(Value)               /* write access not defined */
#define Iodd_WREG_MC_13(Value)               /* write access not defined */
#define Iodd_WREG_MC_14(Value)               /* write access not defined */
#define Iodd_WREG_MC_15(Value)               /* write access not defined */
#define Iodd_WREG_MC_16(Value)               /* write access not defined */
#define Iodd_WREG_MC_17(Value)               /* write access not defined */

#endif

#if                                          \
      defined(__NEC_V850_FG3_F3374__)||      \
      defined(__NEC_V850_FG3_F3375__)||      \
      defined(__NEC_V850_FG3_F3376__)||      \
      defined(__NEC_V850_FG3_F3377__)||      \
      defined(__NEC_V850_FJ3_F3378__)||      \
      defined(__NEC_V850_FJ3_F3379__)||      \
      defined(__NEC_V850_FJ3_F3380__)||      \
      defined(__NEC_V850_FJ3_F3381__)||      \
      defined(__NEC_V850_FJ3_F3382__)||      \
      defined(__NEC_V850_FK3_F3383__)||      \
      defined(__NEC_V850_FK3_F3384__)||      \
      defined(__NEC_V850_FK3_F3385__)

#define Iodd_RREG_PU_10                      TARG_ReadBit(PU1, BIT0)
#define Iodd_RREG_PU_11                      TARG_ReadBit(PU1, BIT1)
#define Iodd_RREG_PU_12                      /* read access defined but should not be used */
#define Iodd_RREG_PU_13                      /* read access defined but should not be used */
#define Iodd_RREG_PU_14                      /* read access defined but should not be used */
#define Iodd_RREG_PU_15                      /* read access defined but should not be used */
#define Iodd_RREG_PU_16                      /* read access defined but should not be used */
#define Iodd_RREG_PU_17                      /* read access defined but should not be used */

#define Iodd_WREG_PU_10(Value)               TARG_WriteBit(PU1, BIT0, Value)
#define Iodd_WREG_PU_11(Value)               TARG_WriteBit(PU1, BIT1, Value)
#define Iodd_WREG_PU_12(Value)               /* write access not defined */
#define Iodd_WREG_PU_13(Value)               /* write access not defined */
#define Iodd_WREG_PU_14(Value)               /* write access not defined */
#define Iodd_WREG_PU_15(Value)               /* write access not defined */
#define Iodd_WREG_PU_16(Value)               /* write access not defined */
#define Iodd_WREG_PU_17(Value)               /* write access not defined */

#endif

#if                                          \
      defined(__NEC_V850_FE3_F3370__)||      \
      defined(__NEC_V850_FE3_F3371__)||      \
      defined(__NEC_V850_FF3_F3372__)||      \
      defined(__NEC_V850_FF3_F3373__)||      \
      defined(__NEC_V850_FF3L_F3618__)

#define Iodd_RREG_P_10                       /* register undefined */
#define Iodd_RREG_P_11                       /* register undefined */
#define Iodd_RREG_P_12                       /* register undefined */
#define Iodd_RREG_P_13                       /* register undefined */
#define Iodd_RREG_P_14                       /* register undefined */
#define Iodd_RREG_P_15                       /* register undefined */
#define Iodd_RREG_P_16                       /* register undefined */
#define Iodd_RREG_P_17                       /* register undefined */

#define Iodd_WREG_P_10(Value)                /* register undefined */
#define Iodd_WREG_P_11(Value)                /* register undefined */
#define Iodd_WREG_P_12(Value)                /* register undefined */
#define Iodd_WREG_P_13(Value)                /* register undefined */
#define Iodd_WREG_P_14(Value)                /* register undefined */
#define Iodd_WREG_P_15(Value)                /* register undefined */
#define Iodd_WREG_P_16(Value)                /* register undefined */
#define Iodd_WREG_P_17(Value)                /* register undefined */

#endif

#if                                          \
      defined(__NEC_V850_FE3_F3370__)||      \
      defined(__NEC_V850_FE3_F3371__)||      \
      defined(__NEC_V850_FF3_F3372__)||      \
      defined(__NEC_V850_FF3_F3373__)||      \
      defined(__NEC_V850_FF3L_F3618__)

#define Iodd_RREG_M_10                       /* register undefined */
#define Iodd_RREG_M_11                       /* register undefined */
#define Iodd_RREG_M_12                       /* register undefined */
#define Iodd_RREG_M_13                       /* register undefined */
#define Iodd_RREG_M_14                       /* register undefined */
#define Iodd_RREG_M_15                       /* register undefined */
#define Iodd_RREG_M_16                       /* register undefined */
#define Iodd_RREG_M_17                       /* register undefined */

#define Iodd_WREG_M_10(Value)                /* register undefined */
#define Iodd_WREG_M_11(Value)                /* register undefined */
#define Iodd_WREG_M_12(Value)                /* register undefined */
#define Iodd_WREG_M_13(Value)                /* register undefined */
#define Iodd_WREG_M_14(Value)                /* register undefined */
#define Iodd_WREG_M_15(Value)                /* register undefined */
#define Iodd_WREG_M_16(Value)                /* register undefined */
#define Iodd_WREG_M_17(Value)                /* register undefined */

#endif

#if                                          \
      defined(__NEC_V850_FE3_F3370__)||      \
      defined(__NEC_V850_FE3_F3371__)||      \
      defined(__NEC_V850_FF3_F3372__)||      \
      defined(__NEC_V850_FF3_F3373__)||      \
      defined(__NEC_V850_FF3L_F3618__)

#define Iodd_RREG_MC_10                      /* register undefined */
#define Iodd_RREG_MC_11                      /* register undefined */
#define Iodd_RREG_MC_12                      /* register undefined */
#define Iodd_RREG_MC_13                      /* register undefined */
#define Iodd_RREG_MC_14                      /* register undefined */
#define Iodd_RREG_MC_15                      /* register undefined */
#define Iodd_RREG_MC_16                      /* register undefined */
#define Iodd_RREG_MC_17                      /* register undefined */

#define Iodd_WREG_MC_10(Value)               /* register undefined */
#define Iodd_WREG_MC_11(Value)               /* register undefined */
#define Iodd_WREG_MC_12(Value)               /* register undefined */
#define Iodd_WREG_MC_13(Value)               /* register undefined */
#define Iodd_WREG_MC_14(Value)               /* register undefined */
#define Iodd_WREG_MC_15(Value)               /* register undefined */
#define Iodd_WREG_MC_16(Value)               /* register undefined */
#define Iodd_WREG_MC_17(Value)               /* register undefined */

#endif

#if                                          \
      defined(__NEC_V850_Fx3__)

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
      defined(__NEC_V850_Fx3__)

#define Iodd_RREG_FCE_10                     /* register undefined */
#define Iodd_RREG_FCE_11                     /* register undefined */
#define Iodd_RREG_FCE_12                     /* register undefined */
#define Iodd_RREG_FCE_13                     /* register undefined */
#define Iodd_RREG_FCE_14                     /* register undefined */
#define Iodd_RREG_FCE_15                     /* register undefined */
#define Iodd_RREG_FCE_16                     /* register undefined */
#define Iodd_RREG_FCE_17                     /* register undefined */

#define Iodd_WREG_FCE_10(Value)              /* register undefined */
#define Iodd_WREG_FCE_11(Value)              /* register undefined */
#define Iodd_WREG_FCE_12(Value)              /* register undefined */
#define Iodd_WREG_FCE_13(Value)              /* register undefined */
#define Iodd_WREG_FCE_14(Value)              /* register undefined */
#define Iodd_WREG_FCE_15(Value)              /* register undefined */
#define Iodd_WREG_FCE_16(Value)              /* register undefined */
#define Iodd_WREG_FCE_17(Value)              /* register undefined */

#endif

#if                                          \
      defined(__NEC_V850_FE3_F3370__)||      \
      defined(__NEC_V850_FE3_F3371__)||      \
      defined(__NEC_V850_FF3_F3372__)||      \
      defined(__NEC_V850_FF3_F3373__)||      \
      defined(__NEC_V850_FF3L_F3618__)

#define Iodd_RREG_PU_10                      /* register undefined */
#define Iodd_RREG_PU_11                      /* register undefined */
#define Iodd_RREG_PU_12                      /* register undefined */
#define Iodd_RREG_PU_13                      /* register undefined */
#define Iodd_RREG_PU_14                      /* register undefined */
#define Iodd_RREG_PU_15                      /* register undefined */
#define Iodd_RREG_PU_16                      /* register undefined */
#define Iodd_RREG_PU_17                      /* register undefined */

#define Iodd_WREG_PU_10(Value)               /* register undefined */
#define Iodd_WREG_PU_11(Value)               /* register undefined */
#define Iodd_WREG_PU_12(Value)               /* register undefined */
#define Iodd_WREG_PU_13(Value)               /* register undefined */
#define Iodd_WREG_PU_14(Value)               /* register undefined */
#define Iodd_WREG_PU_15(Value)               /* register undefined */
#define Iodd_WREG_PU_16(Value)               /* register undefined */
#define Iodd_WREG_PU_17(Value)               /* register undefined */

#endif

#if                                          \
      defined(__NEC_V850_Fx3__)

#define Iodd_RREG_PF_10                      /* register undefined */
#define Iodd_RREG_PF_11                      /* register undefined */
#define Iodd_RREG_PF_12                      /* register undefined */
#define Iodd_RREG_PF_13                      /* register undefined */
#define Iodd_RREG_PF_14                      /* register undefined */
#define Iodd_RREG_PF_15                      /* register undefined */
#define Iodd_RREG_PF_16                      /* register undefined */
#define Iodd_RREG_PF_17                      /* register undefined */

#define Iodd_WREG_PF_10(Value)               /* register undefined */
#define Iodd_WREG_PF_11(Value)               /* register undefined */
#define Iodd_WREG_PF_12(Value)               /* register undefined */
#define Iodd_WREG_PF_13(Value)               /* register undefined */
#define Iodd_WREG_PF_14(Value)               /* register undefined */
#define Iodd_WREG_PF_15(Value)               /* register undefined */
#define Iodd_WREG_PF_16(Value)               /* register undefined */
#define Iodd_WREG_PF_17(Value)               /* register undefined */

#endif

/* Definitions PORT 2 */

#if                                          \
      defined(__NEC_V850_FK3_F3383__)||      \
      defined(__NEC_V850_FK3_F3384__)||      \
      defined(__NEC_V850_FK3_F3385__)

#define Iodd_RREG_P_20                       TARG_ReadBit(P2L, BIT0)
#define Iodd_RREG_P_21                       TARG_ReadBit(P2L, BIT1)
#define Iodd_RREG_P_22                       TARG_ReadBit(P2L, BIT2)
#define Iodd_RREG_P_23                       TARG_ReadBit(P2L, BIT3)
#define Iodd_RREG_P_24                       TARG_ReadBit(P2L, BIT4)
#define Iodd_RREG_P_25                       TARG_ReadBit(P2L, BIT5)
#define Iodd_RREG_P_26                       TARG_ReadBit(P2L, BIT6)
#define Iodd_RREG_P_27                       TARG_ReadBit(P2L, BIT7)

#define Iodd_WREG_P_20(Value)                TARG_WriteBit(P2L, BIT0, Value)
#define Iodd_WREG_P_21(Value)                TARG_WriteBit(P2L, BIT1, Value)
#define Iodd_WREG_P_22(Value)                TARG_WriteBit(P2L, BIT2, Value)
#define Iodd_WREG_P_23(Value)                TARG_WriteBit(P2L, BIT3, Value)
#define Iodd_WREG_P_24(Value)                TARG_WriteBit(P2L, BIT4, Value)
#define Iodd_WREG_P_25(Value)                TARG_WriteBit(P2L, BIT5, Value)
#define Iodd_WREG_P_26(Value)                TARG_WriteBit(P2L, BIT6, Value)
#define Iodd_WREG_P_27(Value)                TARG_WriteBit(P2L, BIT7, Value)

#endif

#if                                          \
      defined(__NEC_V850_FK3_F3383__)||      \
      defined(__NEC_V850_FK3_F3384__)||      \
      defined(__NEC_V850_FK3_F3385__)

#define Iodd_RREG_P_28                       TARG_ReadBit(P2H, BIT0)
#define Iodd_RREG_P_29                       TARG_ReadBit(P2H, BIT1)
#define Iodd_RREG_P_210                      TARG_ReadBit(P2H, BIT2)
#define Iodd_RREG_P_211                      TARG_ReadBit(P2H, BIT3)
#define Iodd_RREG_P_212                      TARG_ReadBit(P2H, BIT4)
#define Iodd_RREG_P_213                      TARG_ReadBit(P2H, BIT5)
#define Iodd_RREG_P_214                      TARG_ReadBit(P2H, BIT6)
#define Iodd_RREG_P_215                      TARG_ReadBit(P2H, BIT7)

#define Iodd_WREG_P_28(Value)                TARG_WriteBit(P2H, BIT0, Value)
#define Iodd_WREG_P_29(Value)                TARG_WriteBit(P2H, BIT1, Value)
#define Iodd_WREG_P_210(Value)               TARG_WriteBit(P2H, BIT2, Value)
#define Iodd_WREG_P_211(Value)               TARG_WriteBit(P2H, BIT3, Value)
#define Iodd_WREG_P_212(Value)               TARG_WriteBit(P2H, BIT4, Value)
#define Iodd_WREG_P_213(Value)               TARG_WriteBit(P2H, BIT5, Value)
#define Iodd_WREG_P_214(Value)               TARG_WriteBit(P2H, BIT6, Value)
#define Iodd_WREG_P_215(Value)               TARG_WriteBit(P2H, BIT7, Value)

#endif

#if                                          \
      defined(__NEC_V850_FK3_F3383__)||      \
      defined(__NEC_V850_FK3_F3384__)||      \
      defined(__NEC_V850_FK3_F3385__)

#define Iodd_RREG_M_20                       TARG_ReadBit(PM2L, BIT0)
#define Iodd_RREG_M_21                       TARG_ReadBit(PM2L, BIT1)
#define Iodd_RREG_M_22                       TARG_ReadBit(PM2L, BIT2)
#define Iodd_RREG_M_23                       TARG_ReadBit(PM2L, BIT3)
#define Iodd_RREG_M_24                       TARG_ReadBit(PM2L, BIT4)
#define Iodd_RREG_M_25                       TARG_ReadBit(PM2L, BIT5)
#define Iodd_RREG_M_26                       TARG_ReadBit(PM2L, BIT6)
#define Iodd_RREG_M_27                       TARG_ReadBit(PM2L, BIT7)

#define Iodd_WREG_M_20(Value)                TARG_WriteBit(PM2L, BIT0, Value)
#define Iodd_WREG_M_21(Value)                TARG_WriteBit(PM2L, BIT1, Value)
#define Iodd_WREG_M_22(Value)                TARG_WriteBit(PM2L, BIT2, Value)
#define Iodd_WREG_M_23(Value)                TARG_WriteBit(PM2L, BIT3, Value)
#define Iodd_WREG_M_24(Value)                TARG_WriteBit(PM2L, BIT4, Value)
#define Iodd_WREG_M_25(Value)                TARG_WriteBit(PM2L, BIT5, Value)
#define Iodd_WREG_M_26(Value)                TARG_WriteBit(PM2L, BIT6, Value)
#define Iodd_WREG_M_27(Value)                TARG_WriteBit(PM2L, BIT7, Value)

#endif

#if                                          \
      defined(__NEC_V850_FK3_F3383__)||      \
      defined(__NEC_V850_FK3_F3384__)||      \
      defined(__NEC_V850_FK3_F3385__)

#define Iodd_RREG_M_28                       TARG_ReadBit(PM2H, BIT0)
#define Iodd_RREG_M_29                       TARG_ReadBit(PM2H, BIT1)
#define Iodd_RREG_M_210                      TARG_ReadBit(PM2H, BIT2)
#define Iodd_RREG_M_211                      TARG_ReadBit(PM2H, BIT3)
#define Iodd_RREG_M_212                      TARG_ReadBit(PM2H, BIT4)
#define Iodd_RREG_M_213                      TARG_ReadBit(PM2H, BIT5)
#define Iodd_RREG_M_214                      TARG_ReadBit(PM2H, BIT6)
#define Iodd_RREG_M_215                      TARG_ReadBit(PM2H, BIT7)

#define Iodd_WREG_M_28(Value)                TARG_WriteBit(PM2H, BIT0, Value)
#define Iodd_WREG_M_29(Value)                TARG_WriteBit(PM2H, BIT1, Value)
#define Iodd_WREG_M_210(Value)               TARG_WriteBit(PM2H, BIT2, Value)
#define Iodd_WREG_M_211(Value)               TARG_WriteBit(PM2H, BIT3, Value)
#define Iodd_WREG_M_212(Value)               TARG_WriteBit(PM2H, BIT4, Value)
#define Iodd_WREG_M_213(Value)               TARG_WriteBit(PM2H, BIT5, Value)
#define Iodd_WREG_M_214(Value)               TARG_WriteBit(PM2H, BIT6, Value)
#define Iodd_WREG_M_215(Value)               TARG_WriteBit(PM2H, BIT7, Value)

#endif

#if                                          \
      defined(__NEC_V850_FK3_F3383__)||      \
      defined(__NEC_V850_FK3_F3384__)||      \
      defined(__NEC_V850_FK3_F3385__)

#define Iodd_RREG_MC_20                      TARG_ReadBit(PMC2L, BIT0)
#define Iodd_RREG_MC_21                      TARG_ReadBit(PMC2L, BIT1)
#define Iodd_RREG_MC_22                      TARG_ReadBit(PMC2L, BIT2)
#define Iodd_RREG_MC_23                      TARG_ReadBit(PMC2L, BIT3)
#define Iodd_RREG_MC_24                      TARG_ReadBit(PMC2L, BIT4)
#define Iodd_RREG_MC_25                      TARG_ReadBit(PMC2L, BIT5)
#define Iodd_RREG_MC_26                      TARG_ReadBit(PMC2L, BIT6)
#define Iodd_RREG_MC_27                      TARG_ReadBit(PMC2L, BIT7)

#define Iodd_WREG_MC_20(Value)               TARG_WriteBit(PMC2L, BIT0, Value)
#define Iodd_WREG_MC_21(Value)               TARG_WriteBit(PMC2L, BIT1, Value)
#define Iodd_WREG_MC_22(Value)               TARG_WriteBit(PMC2L, BIT2, Value)
#define Iodd_WREG_MC_23(Value)               TARG_WriteBit(PMC2L, BIT3, Value)
#define Iodd_WREG_MC_24(Value)               TARG_WriteBit(PMC2L, BIT4, Value)
#define Iodd_WREG_MC_25(Value)               TARG_WriteBit(PMC2L, BIT5, Value)
#define Iodd_WREG_MC_26(Value)               TARG_WriteBit(PMC2L, BIT6, Value)
#define Iodd_WREG_MC_27(Value)               TARG_WriteBit(PMC2L, BIT7, Value)

#endif

#if                                          \
      defined(__NEC_V850_FK3_F3383__)||      \
      defined(__NEC_V850_FK3_F3384__)||      \
      defined(__NEC_V850_FK3_F3385__)

#define Iodd_RREG_MC_28                      TARG_ReadBit(PMC2H, BIT0)
#define Iodd_RREG_MC_29                      TARG_ReadBit(PMC2H, BIT1)
#define Iodd_RREG_MC_210                     TARG_ReadBit(PMC2H, BIT2)
#define Iodd_RREG_MC_211                     TARG_ReadBit(PMC2H, BIT3)
#define Iodd_RREG_MC_212                     TARG_ReadBit(PMC2H, BIT4)
#define Iodd_RREG_MC_213                     TARG_ReadBit(PMC2H, BIT5)
#define Iodd_RREG_MC_214                     TARG_ReadBit(PMC2H, BIT6)
#define Iodd_RREG_MC_215                     TARG_ReadBit(PMC2H, BIT7)

#define Iodd_WREG_MC_28(Value)               TARG_WriteBit(PMC2H, BIT0, Value)
#define Iodd_WREG_MC_29(Value)               TARG_WriteBit(PMC2H, BIT1, Value)
#define Iodd_WREG_MC_210(Value)              TARG_WriteBit(PMC2H, BIT2, Value)
#define Iodd_WREG_MC_211(Value)              TARG_WriteBit(PMC2H, BIT3, Value)
#define Iodd_WREG_MC_212(Value)              TARG_WriteBit(PMC2H, BIT4, Value)
#define Iodd_WREG_MC_213(Value)              TARG_WriteBit(PMC2H, BIT5, Value)
#define Iodd_WREG_MC_214(Value)              TARG_WriteBit(PMC2H, BIT6, Value)
#define Iodd_WREG_MC_215(Value)              TARG_WriteBit(PMC2H, BIT7, Value)

#endif

#if                                          \
      defined(__NEC_V850_FE3_F3370__)||      \
      defined(__NEC_V850_FE3_F3371__)||      \
      defined(__NEC_V850_FF3_F3372__)||      \
      defined(__NEC_V850_FF3_F3373__)||      \
      defined(__NEC_V850_FG3_F3374__)||      \
      defined(__NEC_V850_FG3_F3375__)||      \
      defined(__NEC_V850_FG3_F3376__)||      \
      defined(__NEC_V850_FG3_F3377__)||      \
      defined(__NEC_V850_FJ3_F3378__)||      \
      defined(__NEC_V850_FJ3_F3379__)||      \
      defined(__NEC_V850_FJ3_F3380__)||      \
      defined(__NEC_V850_FJ3_F3381__)||      \
      defined(__NEC_V850_FJ3_F3382__)||      \
      defined(__NEC_V850_FF3L_F3618__)

#define Iodd_RREG_P_20                       /* register undefined */
#define Iodd_RREG_P_21                       /* register undefined */
#define Iodd_RREG_P_22                       /* register undefined */
#define Iodd_RREG_P_23                       /* register undefined */
#define Iodd_RREG_P_24                       /* register undefined */
#define Iodd_RREG_P_25                       /* register undefined */
#define Iodd_RREG_P_26                       /* register undefined */
#define Iodd_RREG_P_27                       /* register undefined */

#define Iodd_WREG_P_20(Value)                /* register undefined */
#define Iodd_WREG_P_21(Value)                /* register undefined */
#define Iodd_WREG_P_22(Value)                /* register undefined */
#define Iodd_WREG_P_23(Value)                /* register undefined */
#define Iodd_WREG_P_24(Value)                /* register undefined */
#define Iodd_WREG_P_25(Value)                /* register undefined */
#define Iodd_WREG_P_26(Value)                /* register undefined */
#define Iodd_WREG_P_27(Value)                /* register undefined */

#endif

#if                                          \
      defined(__NEC_V850_FE3_F3370__)||      \
      defined(__NEC_V850_FE3_F3371__)||      \
      defined(__NEC_V850_FF3_F3372__)||      \
      defined(__NEC_V850_FF3_F3373__)||      \
      defined(__NEC_V850_FG3_F3374__)||      \
      defined(__NEC_V850_FG3_F3375__)||      \
      defined(__NEC_V850_FG3_F3376__)||      \
      defined(__NEC_V850_FG3_F3377__)||      \
      defined(__NEC_V850_FJ3_F3378__)||      \
      defined(__NEC_V850_FJ3_F3379__)||      \
      defined(__NEC_V850_FJ3_F3380__)||      \
      defined(__NEC_V850_FJ3_F3381__)||      \
      defined(__NEC_V850_FJ3_F3382__)||      \
      defined(__NEC_V850_FF3L_F3618__)

#define Iodd_RREG_P_28                       /* register undefined */
#define Iodd_RREG_P_29                       /* register undefined */
#define Iodd_RREG_P_210                      /* register undefined */
#define Iodd_RREG_P_211                      /* register undefined */
#define Iodd_RREG_P_212                      /* register undefined */
#define Iodd_RREG_P_213                      /* register undefined */
#define Iodd_RREG_P_214                      /* register undefined */
#define Iodd_RREG_P_215                      /* register undefined */

#define Iodd_WREG_P_28(Value)                /* register undefined */
#define Iodd_WREG_P_29(Value)                /* register undefined */
#define Iodd_WREG_P_210(Value)               /* register undefined */
#define Iodd_WREG_P_211(Value)               /* register undefined */
#define Iodd_WREG_P_212(Value)               /* register undefined */
#define Iodd_WREG_P_213(Value)               /* register undefined */
#define Iodd_WREG_P_214(Value)               /* register undefined */
#define Iodd_WREG_P_215(Value)               /* register undefined */

#endif

#if                                          \
      defined(__NEC_V850_FE3_F3370__)||      \
      defined(__NEC_V850_FE3_F3371__)||      \
      defined(__NEC_V850_FF3_F3372__)||      \
      defined(__NEC_V850_FF3_F3373__)||      \
      defined(__NEC_V850_FG3_F3374__)||      \
      defined(__NEC_V850_FG3_F3375__)||      \
      defined(__NEC_V850_FG3_F3376__)||      \
      defined(__NEC_V850_FG3_F3377__)||      \
      defined(__NEC_V850_FJ3_F3378__)||      \
      defined(__NEC_V850_FJ3_F3379__)||      \
      defined(__NEC_V850_FJ3_F3380__)||      \
      defined(__NEC_V850_FJ3_F3381__)||      \
      defined(__NEC_V850_FJ3_F3382__)||      \
      defined(__NEC_V850_FF3L_F3618__)

#define Iodd_RREG_M_20                       /* register undefined */
#define Iodd_RREG_M_21                       /* register undefined */
#define Iodd_RREG_M_22                       /* register undefined */
#define Iodd_RREG_M_23                       /* register undefined */
#define Iodd_RREG_M_24                       /* register undefined */
#define Iodd_RREG_M_25                       /* register undefined */
#define Iodd_RREG_M_26                       /* register undefined */
#define Iodd_RREG_M_27                       /* register undefined */

#define Iodd_WREG_M_20(Value)                /* register undefined */
#define Iodd_WREG_M_21(Value)                /* register undefined */
#define Iodd_WREG_M_22(Value)                /* register undefined */
#define Iodd_WREG_M_23(Value)                /* register undefined */
#define Iodd_WREG_M_24(Value)                /* register undefined */
#define Iodd_WREG_M_25(Value)                /* register undefined */
#define Iodd_WREG_M_26(Value)                /* register undefined */
#define Iodd_WREG_M_27(Value)                /* register undefined */

#endif

#if                                          \
      defined(__NEC_V850_FE3_F3370__)||      \
      defined(__NEC_V850_FE3_F3371__)||      \
      defined(__NEC_V850_FF3_F3372__)||      \
      defined(__NEC_V850_FF3_F3373__)||      \
      defined(__NEC_V850_FG3_F3374__)||      \
      defined(__NEC_V850_FG3_F3375__)||      \
      defined(__NEC_V850_FG3_F3376__)||      \
      defined(__NEC_V850_FG3_F3377__)||      \
      defined(__NEC_V850_FJ3_F3378__)||      \
      defined(__NEC_V850_FJ3_F3379__)||      \
      defined(__NEC_V850_FJ3_F3380__)||      \
      defined(__NEC_V850_FJ3_F3381__)||      \
      defined(__NEC_V850_FJ3_F3382__)||      \
      defined(__NEC_V850_FF3L_F3618__)

#define Iodd_RREG_M_28                       /* register undefined */
#define Iodd_RREG_M_29                       /* register undefined */
#define Iodd_RREG_M_210                      /* register undefined */
#define Iodd_RREG_M_211                      /* register undefined */
#define Iodd_RREG_M_212                      /* register undefined */
#define Iodd_RREG_M_213                      /* register undefined */
#define Iodd_RREG_M_214                      /* register undefined */
#define Iodd_RREG_M_215                      /* register undefined */

#define Iodd_WREG_M_28(Value)                /* register undefined */
#define Iodd_WREG_M_29(Value)                /* register undefined */
#define Iodd_WREG_M_210(Value)               /* register undefined */
#define Iodd_WREG_M_211(Value)               /* register undefined */
#define Iodd_WREG_M_212(Value)               /* register undefined */
#define Iodd_WREG_M_213(Value)               /* register undefined */
#define Iodd_WREG_M_214(Value)               /* register undefined */
#define Iodd_WREG_M_215(Value)               /* register undefined */

#endif

#if                                          \
      defined(__NEC_V850_FE3_F3370__)||      \
      defined(__NEC_V850_FE3_F3371__)||      \
      defined(__NEC_V850_FF3_F3372__)||      \
      defined(__NEC_V850_FF3_F3373__)||      \
      defined(__NEC_V850_FG3_F3374__)||      \
      defined(__NEC_V850_FG3_F3375__)||      \
      defined(__NEC_V850_FG3_F3376__)||      \
      defined(__NEC_V850_FG3_F3377__)||      \
      defined(__NEC_V850_FJ3_F3378__)||      \
      defined(__NEC_V850_FJ3_F3379__)||      \
      defined(__NEC_V850_FJ3_F3380__)||      \
      defined(__NEC_V850_FJ3_F3381__)||      \
      defined(__NEC_V850_FJ3_F3382__)||      \
      defined(__NEC_V850_FF3L_F3618__)

#define Iodd_RREG_MC_20                      /* register undefined */
#define Iodd_RREG_MC_21                      /* register undefined */
#define Iodd_RREG_MC_22                      /* register undefined */
#define Iodd_RREG_MC_23                      /* register undefined */
#define Iodd_RREG_MC_24                      /* register undefined */
#define Iodd_RREG_MC_25                      /* register undefined */
#define Iodd_RREG_MC_26                      /* register undefined */
#define Iodd_RREG_MC_27                      /* register undefined */

#define Iodd_WREG_MC_20(Value)               /* register undefined */
#define Iodd_WREG_MC_21(Value)               /* register undefined */
#define Iodd_WREG_MC_22(Value)               /* register undefined */
#define Iodd_WREG_MC_23(Value)               /* register undefined */
#define Iodd_WREG_MC_24(Value)               /* register undefined */
#define Iodd_WREG_MC_25(Value)               /* register undefined */
#define Iodd_WREG_MC_26(Value)               /* register undefined */
#define Iodd_WREG_MC_27(Value)               /* register undefined */

#endif

#if                                          \
      defined(__NEC_V850_FE3_F3370__)||      \
      defined(__NEC_V850_FE3_F3371__)||      \
      defined(__NEC_V850_FF3_F3372__)||      \
      defined(__NEC_V850_FF3_F3373__)||      \
      defined(__NEC_V850_FG3_F3374__)||      \
      defined(__NEC_V850_FG3_F3375__)||      \
      defined(__NEC_V850_FG3_F3376__)||      \
      defined(__NEC_V850_FG3_F3377__)||      \
      defined(__NEC_V850_FJ3_F3378__)||      \
      defined(__NEC_V850_FJ3_F3379__)||      \
      defined(__NEC_V850_FJ3_F3380__)||      \
      defined(__NEC_V850_FJ3_F3381__)||      \
      defined(__NEC_V850_FJ3_F3382__)||      \
      defined(__NEC_V850_FF3L_F3618__)

#define Iodd_RREG_MC_28                      /* register undefined */
#define Iodd_RREG_MC_29                      /* register undefined */
#define Iodd_RREG_MC_210                     /* register undefined */
#define Iodd_RREG_MC_211                     /* register undefined */
#define Iodd_RREG_MC_212                     /* register undefined */
#define Iodd_RREG_MC_213                     /* register undefined */
#define Iodd_RREG_MC_214                     /* register undefined */
#define Iodd_RREG_MC_215                     /* register undefined */

#define Iodd_WREG_MC_28(Value)               /* register undefined */
#define Iodd_WREG_MC_29(Value)               /* register undefined */
#define Iodd_WREG_MC_210(Value)              /* register undefined */
#define Iodd_WREG_MC_211(Value)              /* register undefined */
#define Iodd_WREG_MC_212(Value)              /* register undefined */
#define Iodd_WREG_MC_213(Value)              /* register undefined */
#define Iodd_WREG_MC_214(Value)              /* register undefined */
#define Iodd_WREG_MC_215(Value)              /* register undefined */

#endif

#if                                          \
      defined(__NEC_V850_Fx3__)

#define Iodd_RREG_FC_20                      /* register undefined */
#define Iodd_RREG_FC_21                      /* register undefined */
#define Iodd_RREG_FC_22                      /* register undefined */
#define Iodd_RREG_FC_23                      /* register undefined */
#define Iodd_RREG_FC_24                      /* register undefined */
#define Iodd_RREG_FC_25                      /* register undefined */
#define Iodd_RREG_FC_26                      /* register undefined */
#define Iodd_RREG_FC_27                      /* register undefined */
#define Iodd_RREG_FC_28                      /* register undefined */
#define Iodd_RREG_FC_29                      /* register undefined */
#define Iodd_RREG_FC_210                     /* register undefined */
#define Iodd_RREG_FC_211                     /* register undefined */
#define Iodd_RREG_FC_212                     /* register undefined */
#define Iodd_RREG_FC_213                     /* register undefined */
#define Iodd_RREG_FC_214                     /* register undefined */
#define Iodd_RREG_FC_215                     /* register undefined */

#define Iodd_WREG_FC_20(Value)               /* register undefined */
#define Iodd_WREG_FC_21(Value)               /* register undefined */
#define Iodd_WREG_FC_22(Value)               /* register undefined */
#define Iodd_WREG_FC_23(Value)               /* register undefined */
#define Iodd_WREG_FC_24(Value)               /* register undefined */
#define Iodd_WREG_FC_25(Value)               /* register undefined */
#define Iodd_WREG_FC_26(Value)               /* register undefined */
#define Iodd_WREG_FC_27(Value)               /* register undefined */
#define Iodd_WREG_FC_28(Value)               /* register undefined */
#define Iodd_WREG_FC_29(Value)               /* register undefined */
#define Iodd_WREG_FC_210(Value)              /* register undefined */
#define Iodd_WREG_FC_211(Value)              /* register undefined */
#define Iodd_WREG_FC_212(Value)              /* register undefined */
#define Iodd_WREG_FC_213(Value)              /* register undefined */
#define Iodd_WREG_FC_214(Value)              /* register undefined */
#define Iodd_WREG_FC_215(Value)              /* register undefined */

#endif

#if                                          \
      defined(__NEC_V850_Fx3__)

#define Iodd_RREG_FCE_20                     /* register undefined */
#define Iodd_RREG_FCE_21                     /* register undefined */
#define Iodd_RREG_FCE_22                     /* register undefined */
#define Iodd_RREG_FCE_23                     /* register undefined */
#define Iodd_RREG_FCE_24                     /* register undefined */
#define Iodd_RREG_FCE_25                     /* register undefined */
#define Iodd_RREG_FCE_26                     /* register undefined */
#define Iodd_RREG_FCE_27                     /* register undefined */
#define Iodd_RREG_FCE_28                     /* register undefined */
#define Iodd_RREG_FCE_29                     /* register undefined */
#define Iodd_RREG_FCE_210                    /* register undefined */
#define Iodd_RREG_FCE_211                    /* register undefined */
#define Iodd_RREG_FCE_212                    /* register undefined */
#define Iodd_RREG_FCE_213                    /* register undefined */
#define Iodd_RREG_FCE_214                    /* register undefined */
#define Iodd_RREG_FCE_215                    /* register undefined */

#define Iodd_WREG_FCE_20(Value)              /* register undefined */
#define Iodd_WREG_FCE_21(Value)              /* register undefined */
#define Iodd_WREG_FCE_22(Value)              /* register undefined */
#define Iodd_WREG_FCE_23(Value)              /* register undefined */
#define Iodd_WREG_FCE_24(Value)              /* register undefined */
#define Iodd_WREG_FCE_25(Value)              /* register undefined */
#define Iodd_WREG_FCE_26(Value)              /* register undefined */
#define Iodd_WREG_FCE_27(Value)              /* register undefined */
#define Iodd_WREG_FCE_28(Value)              /* register undefined */
#define Iodd_WREG_FCE_29(Value)              /* register undefined */
#define Iodd_WREG_FCE_210(Value)             /* register undefined */
#define Iodd_WREG_FCE_211(Value)             /* register undefined */
#define Iodd_WREG_FCE_212(Value)             /* register undefined */
#define Iodd_WREG_FCE_213(Value)             /* register undefined */
#define Iodd_WREG_FCE_214(Value)             /* register undefined */
#define Iodd_WREG_FCE_215(Value)             /* register undefined */

#endif

#if                                          \
      defined(__NEC_V850_Fx3__)

#define Iodd_RREG_PU_20                      /* register undefined */
#define Iodd_RREG_PU_21                      /* register undefined */
#define Iodd_RREG_PU_22                      /* register undefined */
#define Iodd_RREG_PU_23                      /* register undefined */
#define Iodd_RREG_PU_24                      /* register undefined */
#define Iodd_RREG_PU_25                      /* register undefined */
#define Iodd_RREG_PU_26                      /* register undefined */
#define Iodd_RREG_PU_27                      /* register undefined */
#define Iodd_RREG_PU_28                      /* register undefined */
#define Iodd_RREG_PU_29                      /* register undefined */
#define Iodd_RREG_PU_210                     /* register undefined */
#define Iodd_RREG_PU_211                     /* register undefined */
#define Iodd_RREG_PU_212                     /* register undefined */
#define Iodd_RREG_PU_213                     /* register undefined */
#define Iodd_RREG_PU_214                     /* register undefined */
#define Iodd_RREG_PU_215                     /* register undefined */

#define Iodd_WREG_PU_20(Value)               /* register undefined */
#define Iodd_WREG_PU_21(Value)               /* register undefined */
#define Iodd_WREG_PU_22(Value)               /* register undefined */
#define Iodd_WREG_PU_23(Value)               /* register undefined */
#define Iodd_WREG_PU_24(Value)               /* register undefined */
#define Iodd_WREG_PU_25(Value)               /* register undefined */
#define Iodd_WREG_PU_26(Value)               /* register undefined */
#define Iodd_WREG_PU_27(Value)               /* register undefined */
#define Iodd_WREG_PU_28(Value)               /* register undefined */
#define Iodd_WREG_PU_29(Value)               /* register undefined */
#define Iodd_WREG_PU_210(Value)              /* register undefined */
#define Iodd_WREG_PU_211(Value)              /* register undefined */
#define Iodd_WREG_PU_212(Value)              /* register undefined */
#define Iodd_WREG_PU_213(Value)              /* register undefined */
#define Iodd_WREG_PU_214(Value)              /* register undefined */
#define Iodd_WREG_PU_215(Value)              /* register undefined */

#endif

#if                                          \
      defined(__NEC_V850_Fx3__)

#define Iodd_RREG_PF_20                      /* register undefined */
#define Iodd_RREG_PF_21                      /* register undefined */
#define Iodd_RREG_PF_22                      /* register undefined */
#define Iodd_RREG_PF_23                      /* register undefined */
#define Iodd_RREG_PF_24                      /* register undefined */
#define Iodd_RREG_PF_25                      /* register undefined */
#define Iodd_RREG_PF_26                      /* register undefined */
#define Iodd_RREG_PF_27                      /* register undefined */
#define Iodd_RREG_PF_28                      /* register undefined */
#define Iodd_RREG_PF_29                      /* register undefined */
#define Iodd_RREG_PF_210                     /* register undefined */
#define Iodd_RREG_PF_211                     /* register undefined */
#define Iodd_RREG_PF_212                     /* register undefined */
#define Iodd_RREG_PF_213                     /* register undefined */
#define Iodd_RREG_PF_214                     /* register undefined */
#define Iodd_RREG_PF_215                     /* register undefined */

#define Iodd_WREG_PF_20(Value)               /* register undefined */
#define Iodd_WREG_PF_21(Value)               /* register undefined */
#define Iodd_WREG_PF_22(Value)               /* register undefined */
#define Iodd_WREG_PF_23(Value)               /* register undefined */
#define Iodd_WREG_PF_24(Value)               /* register undefined */
#define Iodd_WREG_PF_25(Value)               /* register undefined */
#define Iodd_WREG_PF_26(Value)               /* register undefined */
#define Iodd_WREG_PF_27(Value)               /* register undefined */
#define Iodd_WREG_PF_28(Value)               /* register undefined */
#define Iodd_WREG_PF_29(Value)               /* register undefined */
#define Iodd_WREG_PF_210(Value)              /* register undefined */
#define Iodd_WREG_PF_211(Value)              /* register undefined */
#define Iodd_WREG_PF_212(Value)              /* register undefined */
#define Iodd_WREG_PF_213(Value)              /* register undefined */
#define Iodd_WREG_PF_214(Value)              /* register undefined */
#define Iodd_WREG_PF_215(Value)              /* register undefined */

#endif

/* Definitions PORT 3 */

#if                                          \
      defined(__NEC_V850_FE3_F3370__)||      \
      defined(__NEC_V850_FE3_F3371__)

#define Iodd_RREG_P_30                       TARG_ReadBit(P3L, BIT0)
#define Iodd_RREG_P_31                       TARG_ReadBit(P3L, BIT1)
#define Iodd_RREG_P_32                       TARG_ReadBit(P3L, BIT2)
#define Iodd_RREG_P_33                       TARG_ReadBit(P3L, BIT3)
#define Iodd_RREG_P_34                       TARG_ReadBit(P3L, BIT4)
#define Iodd_RREG_P_35                       TARG_ReadBit(P3L, BIT5)
#define Iodd_RREG_P_36                       /* read access defined but should not be used */
#define Iodd_RREG_P_37                       /* read access defined but should not be used */

#define Iodd_WREG_P_30(Value)                TARG_WriteBit(P3L, BIT0, Value)
#define Iodd_WREG_P_31(Value)                TARG_WriteBit(P3L, BIT1, Value)
#define Iodd_WREG_P_32(Value)                TARG_WriteBit(P3L, BIT2, Value)
#define Iodd_WREG_P_33(Value)                TARG_WriteBit(P3L, BIT3, Value)
#define Iodd_WREG_P_34(Value)                TARG_WriteBit(P3L, BIT4, Value)
#define Iodd_WREG_P_35(Value)                TARG_WriteBit(P3L, BIT5, Value)
#define Iodd_WREG_P_36(Value)                /* write access not defined */
#define Iodd_WREG_P_37(Value)                /* write access not defined */

#endif

#if                                          \
      defined(__NEC_V850_FF3_F3372__)||      \
      defined(__NEC_V850_FF3_F3373__)||      \
      defined(__NEC_V850_FF3L_F3618__)

#define Iodd_RREG_P_30                       TARG_ReadBit(P3L, BIT0)
#define Iodd_RREG_P_31                       TARG_ReadBit(P3L, BIT1)
#define Iodd_RREG_P_32                       TARG_ReadBit(P3L, BIT2)
#define Iodd_RREG_P_33                       TARG_ReadBit(P3L, BIT3)
#define Iodd_RREG_P_34                       TARG_ReadBit(P3L, BIT4)
#define Iodd_RREG_P_35                       TARG_ReadBit(P3L, BIT5)
#define Iodd_RREG_P_36                       /* read access defined but should not be used */
#define Iodd_RREG_P_37                       /* read access defined but should not be used */
#define Iodd_RREG_P_38                       TARG_ReadBit(P3H, BIT0)
#define Iodd_RREG_P_39                       TARG_ReadBit(P3H, BIT1)
#define Iodd_RREG_P_310                      /* read access defined but should not be used */
#define Iodd_RREG_P_311                      /* read access defined but should not be used */
#define Iodd_RREG_P_312                      /* read access defined but should not be used */
#define Iodd_RREG_P_313                      /* read access defined but should not be used */
#define Iodd_RREG_P_314                      /* read access defined but should not be used */
#define Iodd_RREG_P_315                      /* read access defined but should not be used */

#define Iodd_WREG_P_30(Value)                TARG_WriteBit(P3L, BIT0, Value)
#define Iodd_WREG_P_31(Value)                TARG_WriteBit(P3L, BIT1, Value)
#define Iodd_WREG_P_32(Value)                TARG_WriteBit(P3L, BIT2, Value)
#define Iodd_WREG_P_33(Value)                TARG_WriteBit(P3L, BIT3, Value)
#define Iodd_WREG_P_34(Value)                TARG_WriteBit(P3L, BIT4, Value)
#define Iodd_WREG_P_35(Value)                TARG_WriteBit(P3L, BIT5, Value)
#define Iodd_WREG_P_36(Value)                /* write access not defined */
#define Iodd_WREG_P_37(Value)                /* write access not defined */
#define Iodd_WREG_P_38(Value)                TARG_WriteBit(P3H, BIT0, Value)
#define Iodd_WREG_P_39(Value)                TARG_WriteBit(P3H, BIT1, Value)
#define Iodd_WREG_P_310(Value)               /* write access not defined */
#define Iodd_WREG_P_311(Value)               /* write access not defined */
#define Iodd_WREG_P_312(Value)               /* write access not defined */
#define Iodd_WREG_P_313(Value)               /* write access not defined */
#define Iodd_WREG_P_314(Value)               /* write access not defined */
#define Iodd_WREG_P_315(Value)               /* write access not defined */

#endif

#if                                          \
      defined(__NEC_V850_FG3_F3374__)||      \
      defined(__NEC_V850_FG3_F3375__)||      \
      defined(__NEC_V850_FG3_F3376__)||      \
      defined(__NEC_V850_FG3_F3377__)||      \
      defined(__NEC_V850_FJ3_F3378__)||      \
      defined(__NEC_V850_FJ3_F3379__)||      \
      defined(__NEC_V850_FJ3_F3380__)||      \
      defined(__NEC_V850_FJ3_F3381__)||      \
      defined(__NEC_V850_FJ3_F3382__)||      \
      defined(__NEC_V850_FK3_F3383__)||      \
      defined(__NEC_V850_FK3_F3384__)||      \
      defined(__NEC_V850_FK3_F3385__)

#define Iodd_RREG_P_30                       TARG_ReadBit(P3L, BIT0)
#define Iodd_RREG_P_31                       TARG_ReadBit(P3L, BIT1)
#define Iodd_RREG_P_32                       TARG_ReadBit(P3L, BIT2)
#define Iodd_RREG_P_33                       TARG_ReadBit(P3L, BIT3)
#define Iodd_RREG_P_34                       TARG_ReadBit(P3L, BIT4)
#define Iodd_RREG_P_35                       TARG_ReadBit(P3L, BIT5)
#define Iodd_RREG_P_36                       TARG_ReadBit(P3L, BIT6)
#define Iodd_RREG_P_37                       TARG_ReadBit(P3L, BIT7)
#define Iodd_RREG_P_38                       TARG_ReadBit(P3H, BIT0)
#define Iodd_RREG_P_39                       TARG_ReadBit(P3H, BIT1)
#define Iodd_RREG_P_310                      /* read access defined but should not be used */
#define Iodd_RREG_P_311                      /* read access defined but should not be used */
#define Iodd_RREG_P_312                      /* read access defined but should not be used */
#define Iodd_RREG_P_313                      /* read access defined but should not be used */
#define Iodd_RREG_P_314                      /* read access defined but should not be used */
#define Iodd_RREG_P_315                      /* read access defined but should not be used */

#define Iodd_WREG_P_30(Value)                TARG_WriteBit(P3L, BIT0, Value)
#define Iodd_WREG_P_31(Value)                TARG_WriteBit(P3L, BIT1, Value)
#define Iodd_WREG_P_32(Value)                TARG_WriteBit(P3L, BIT2, Value)
#define Iodd_WREG_P_33(Value)                TARG_WriteBit(P3L, BIT3, Value)
#define Iodd_WREG_P_34(Value)                TARG_WriteBit(P3L, BIT4, Value)
#define Iodd_WREG_P_35(Value)                TARG_WriteBit(P3L, BIT5, Value)
#define Iodd_WREG_P_36(Value)                TARG_WriteBit(P3L, BIT6, Value)
#define Iodd_WREG_P_37(Value)                TARG_WriteBit(P3L, BIT7, Value)
#define Iodd_WREG_P_38(Value)                TARG_WriteBit(P3H, BIT0, Value)
#define Iodd_WREG_P_39(Value)                TARG_WriteBit(P3H, BIT1, Value)
#define Iodd_WREG_P_310(Value)               /* write access not defined */
#define Iodd_WREG_P_311(Value)               /* write access not defined */
#define Iodd_WREG_P_312(Value)               /* write access not defined */
#define Iodd_WREG_P_313(Value)               /* write access not defined */
#define Iodd_WREG_P_314(Value)               /* write access not defined */
#define Iodd_WREG_P_315(Value)               /* write access not defined */

#endif

#if                                          \
      defined(__NEC_V850_FE3_F3370__)||      \
      defined(__NEC_V850_FE3_F3371__)

#define Iodd_RREG_M_30                       TARG_ReadBit(PM3L, BIT0)
#define Iodd_RREG_M_31                       TARG_ReadBit(PM3L, BIT1)
#define Iodd_RREG_M_32                       TARG_ReadBit(PM3L, BIT2)
#define Iodd_RREG_M_33                       TARG_ReadBit(PM3L, BIT3)
#define Iodd_RREG_M_34                       TARG_ReadBit(PM3L, BIT4)
#define Iodd_RREG_M_35                       TARG_ReadBit(PM3L, BIT5)
#define Iodd_RREG_M_36                       /* read access defined but should not be used */
#define Iodd_RREG_M_37                       /* read access defined but should not be used */

#define Iodd_WREG_M_30(Value)                TARG_WriteBit(PM3L, BIT0, Value)
#define Iodd_WREG_M_31(Value)                TARG_WriteBit(PM3L, BIT1, Value)
#define Iodd_WREG_M_32(Value)                TARG_WriteBit(PM3L, BIT2, Value)
#define Iodd_WREG_M_33(Value)                TARG_WriteBit(PM3L, BIT3, Value)
#define Iodd_WREG_M_34(Value)                TARG_WriteBit(PM3L, BIT4, Value)
#define Iodd_WREG_M_35(Value)                TARG_WriteBit(PM3L, BIT5, Value)
#define Iodd_WREG_M_36(Value)                /* write access not defined */
#define Iodd_WREG_M_37(Value)                /* write access not defined */

#endif

#if                                          \
      defined(__NEC_V850_FF3_F3372__)||      \
      defined(__NEC_V850_FF3_F3373__)||      \
      defined(__NEC_V850_FF3L_F3618__)

#define Iodd_RREG_M_30                       TARG_ReadBit(PM3L, BIT0)
#define Iodd_RREG_M_31                       TARG_ReadBit(PM3L, BIT1)
#define Iodd_RREG_M_32                       TARG_ReadBit(PM3L, BIT2)
#define Iodd_RREG_M_33                       TARG_ReadBit(PM3L, BIT3)
#define Iodd_RREG_M_34                       TARG_ReadBit(PM3L, BIT4)
#define Iodd_RREG_M_35                       TARG_ReadBit(PM3L, BIT5)
#define Iodd_RREG_M_36                       /* read access defined but should not be used */
#define Iodd_RREG_M_37                       /* read access defined but should not be used */
#define Iodd_RREG_M_38                       TARG_ReadBit(PM3H, BIT0)
#define Iodd_RREG_M_39                       TARG_ReadBit(PM3H, BIT1)
#define Iodd_RREG_M_310                      /* read access defined but should not be used */
#define Iodd_RREG_M_311                      /* read access defined but should not be used */
#define Iodd_RREG_M_312                      /* read access defined but should not be used */
#define Iodd_RREG_M_313                      /* read access defined but should not be used */
#define Iodd_RREG_M_314                      /* read access defined but should not be used */
#define Iodd_RREG_M_315                      /* read access defined but should not be used */

#define Iodd_WREG_M_30(Value)                TARG_WriteBit(PM3L, BIT0, Value)
#define Iodd_WREG_M_31(Value)                TARG_WriteBit(PM3L, BIT1, Value)
#define Iodd_WREG_M_32(Value)                TARG_WriteBit(PM3L, BIT2, Value)
#define Iodd_WREG_M_33(Value)                TARG_WriteBit(PM3L, BIT3, Value)
#define Iodd_WREG_M_34(Value)                TARG_WriteBit(PM3L, BIT4, Value)
#define Iodd_WREG_M_35(Value)                TARG_WriteBit(PM3L, BIT5, Value)
#define Iodd_WREG_M_36(Value)                /* write access not defined */
#define Iodd_WREG_M_37(Value)                /* write access not defined */
#define Iodd_WREG_M_38(Value)                TARG_WriteBit(PM3H, BIT0, Value)
#define Iodd_WREG_M_39(Value)                TARG_WriteBit(PM3H, BIT1, Value)
#define Iodd_WREG_M_310(Value)               /* write access not defined */
#define Iodd_WREG_M_311(Value)               /* write access not defined */
#define Iodd_WREG_M_312(Value)               /* write access not defined */
#define Iodd_WREG_M_313(Value)               /* write access not defined */
#define Iodd_WREG_M_314(Value)               /* write access not defined */
#define Iodd_WREG_M_315(Value)               /* write access not defined */

#endif

#if                                          \
      defined(__NEC_V850_FG3_F3374__)||      \
      defined(__NEC_V850_FG3_F3375__)||      \
      defined(__NEC_V850_FG3_F3376__)||      \
      defined(__NEC_V850_FG3_F3377__)||      \
      defined(__NEC_V850_FJ3_F3378__)||      \
      defined(__NEC_V850_FJ3_F3379__)||      \
      defined(__NEC_V850_FJ3_F3380__)||      \
      defined(__NEC_V850_FJ3_F3381__)||      \
      defined(__NEC_V850_FJ3_F3382__)||      \
      defined(__NEC_V850_FK3_F3383__)||      \
      defined(__NEC_V850_FK3_F3384__)||      \
      defined(__NEC_V850_FK3_F3385__)

#define Iodd_RREG_M_30                       TARG_ReadBit(PM3L, BIT0)
#define Iodd_RREG_M_31                       TARG_ReadBit(PM3L, BIT1)
#define Iodd_RREG_M_32                       TARG_ReadBit(PM3L, BIT2)
#define Iodd_RREG_M_33                       TARG_ReadBit(PM3L, BIT3)
#define Iodd_RREG_M_34                       TARG_ReadBit(PM3L, BIT4)
#define Iodd_RREG_M_35                       TARG_ReadBit(PM3L, BIT5)
#define Iodd_RREG_M_36                       TARG_ReadBit(PM3L, BIT6)
#define Iodd_RREG_M_37                       TARG_ReadBit(PM3L, BIT7)
#define Iodd_RREG_M_38                       TARG_ReadBit(PM3H, BIT0)
#define Iodd_RREG_M_39                       TARG_ReadBit(PM3H, BIT1)
#define Iodd_RREG_M_310                      /* read access defined but should not be used */
#define Iodd_RREG_M_311                      /* read access defined but should not be used */
#define Iodd_RREG_M_312                      /* read access defined but should not be used */
#define Iodd_RREG_M_313                      /* read access defined but should not be used */
#define Iodd_RREG_M_314                      /* read access defined but should not be used */
#define Iodd_RREG_M_315                      /* read access defined but should not be used */

#define Iodd_WREG_M_30(Value)                TARG_WriteBit(PM3L, BIT0, Value)
#define Iodd_WREG_M_31(Value)                TARG_WriteBit(PM3L, BIT1, Value)
#define Iodd_WREG_M_32(Value)                TARG_WriteBit(PM3L, BIT2, Value)
#define Iodd_WREG_M_33(Value)                TARG_WriteBit(PM3L, BIT3, Value)
#define Iodd_WREG_M_34(Value)                TARG_WriteBit(PM3L, BIT4, Value)
#define Iodd_WREG_M_35(Value)                TARG_WriteBit(PM3L, BIT5, Value)
#define Iodd_WREG_M_36(Value)                TARG_WriteBit(PM3L, BIT6, Value)
#define Iodd_WREG_M_37(Value)                TARG_WriteBit(PM3L, BIT7, Value)
#define Iodd_WREG_M_38(Value)                TARG_WriteBit(PM3H, BIT0, Value)
#define Iodd_WREG_M_39(Value)                TARG_WriteBit(PM3H, BIT1, Value)
#define Iodd_WREG_M_310(Value)               /* write access not defined */
#define Iodd_WREG_M_311(Value)               /* write access not defined */
#define Iodd_WREG_M_312(Value)               /* write access not defined */
#define Iodd_WREG_M_313(Value)               /* write access not defined */
#define Iodd_WREG_M_314(Value)               /* write access not defined */
#define Iodd_WREG_M_315(Value)               /* write access not defined */

#endif

#if                                          \
      defined(__NEC_V850_FE3_F3370__)||      \
      defined(__NEC_V850_FE3_F3371__)||      \
      defined(__NEC_V850_FF3_F3372__)||      \
      defined(__NEC_V850_FF3_F3373__)||      \
      defined(__NEC_V850_FF3L_F3618__)

#define Iodd_RREG_MC_30                      TARG_ReadBit(PMC3L, BIT0)
#define Iodd_RREG_MC_31                      TARG_ReadBit(PMC3L, BIT1)
#define Iodd_RREG_MC_32                      TARG_ReadBit(PMC3L, BIT2)
#define Iodd_RREG_MC_33                      TARG_ReadBit(PMC3L, BIT3)
#define Iodd_RREG_MC_34                      TARG_ReadBit(PMC3L, BIT4)
#define Iodd_RREG_MC_35                      TARG_ReadBit(PMC3L, BIT5)
#define Iodd_RREG_MC_36                      /* read access defined but should not be used */
#define Iodd_RREG_MC_37                      /* read access defined but should not be used */

#define Iodd_WREG_MC_30(Value)               TARG_WriteBit(PMC3L, BIT0, Value)
#define Iodd_WREG_MC_31(Value)               TARG_WriteBit(PMC3L, BIT1, Value)
#define Iodd_WREG_MC_32(Value)               TARG_WriteBit(PMC3L, BIT2, Value)
#define Iodd_WREG_MC_33(Value)               TARG_WriteBit(PMC3L, BIT3, Value)
#define Iodd_WREG_MC_34(Value)               TARG_WriteBit(PMC3L, BIT4, Value)
#define Iodd_WREG_MC_35(Value)               TARG_WriteBit(PMC3L, BIT5, Value)
#define Iodd_WREG_MC_36(Value)               /* write access not defined */
#define Iodd_WREG_MC_37(Value)               /* write access not defined */

#endif

#if                                          \
      defined(__NEC_V850_FG3_F3374__)||      \
      defined(__NEC_V850_FG3_F3375__)||      \
      defined(__NEC_V850_FG3_F3376__)||      \
      defined(__NEC_V850_FG3_F3377__)||      \
      defined(__NEC_V850_FJ3_F3378__)||      \
      defined(__NEC_V850_FJ3_F3379__)||      \
      defined(__NEC_V850_FJ3_F3380__)||      \
      defined(__NEC_V850_FJ3_F3381__)||      \
      defined(__NEC_V850_FJ3_F3382__)||      \
      defined(__NEC_V850_FK3_F3383__)||      \
      defined(__NEC_V850_FK3_F3384__)||      \
      defined(__NEC_V850_FK3_F3385__)

#define Iodd_RREG_MC_30                      TARG_ReadBit(PMC3L, BIT0)
#define Iodd_RREG_MC_31                      TARG_ReadBit(PMC3L, BIT1)
#define Iodd_RREG_MC_32                      TARG_ReadBit(PMC3L, BIT2)
#define Iodd_RREG_MC_33                      TARG_ReadBit(PMC3L, BIT3)
#define Iodd_RREG_MC_34                      TARG_ReadBit(PMC3L, BIT4)
#define Iodd_RREG_MC_35                      TARG_ReadBit(PMC3L, BIT5)
#define Iodd_RREG_MC_36                      TARG_ReadBit(PMC3L, BIT6)
#define Iodd_RREG_MC_37                      TARG_ReadBit(PMC3L, BIT7)
#define Iodd_RREG_MC_38                      TARG_ReadBit(PMC3H, BIT0)
#define Iodd_RREG_MC_39                      TARG_ReadBit(PMC3H, BIT1)
#define Iodd_RREG_MC_310                     /* read access defined but should not be used */
#define Iodd_RREG_MC_311                     /* read access defined but should not be used */
#define Iodd_RREG_MC_312                     /* read access defined but should not be used */
#define Iodd_RREG_MC_313                     /* read access defined but should not be used */
#define Iodd_RREG_MC_314                     /* read access defined but should not be used */
#define Iodd_RREG_MC_315                     /* read access defined but should not be used */

#define Iodd_WREG_MC_30(Value)               TARG_WriteBit(PMC3L, BIT0, Value)
#define Iodd_WREG_MC_31(Value)               TARG_WriteBit(PMC3L, BIT1, Value)
#define Iodd_WREG_MC_32(Value)               TARG_WriteBit(PMC3L, BIT2, Value)
#define Iodd_WREG_MC_33(Value)               TARG_WriteBit(PMC3L, BIT3, Value)
#define Iodd_WREG_MC_34(Value)               TARG_WriteBit(PMC3L, BIT4, Value)
#define Iodd_WREG_MC_35(Value)               TARG_WriteBit(PMC3L, BIT5, Value)
#define Iodd_WREG_MC_36(Value)               TARG_WriteBit(PMC3L, BIT6, Value)
#define Iodd_WREG_MC_37(Value)               TARG_WriteBit(PMC3L, BIT7, Value)
#define Iodd_WREG_MC_38(Value)               TARG_WriteBit(PMC3H, BIT0, Value)
#define Iodd_WREG_MC_39(Value)               TARG_WriteBit(PMC3H, BIT1, Value)
#define Iodd_WREG_MC_310(Value)              /* write access not defined */
#define Iodd_WREG_MC_311(Value)              /* write access not defined */
#define Iodd_WREG_MC_312(Value)              /* write access not defined */
#define Iodd_WREG_MC_313(Value)              /* write access not defined */
#define Iodd_WREG_MC_314(Value)              /* write access not defined */
#define Iodd_WREG_MC_315(Value)              /* write access not defined */

#endif

#if                                          \
      defined(__NEC_V850_Fx3__)

#define Iodd_RREG_FC_30                      /* read access defined but should not be used */
#define Iodd_RREG_FC_31                      /* read access defined but should not be used */
#define Iodd_RREG_FC_32                      TARG_ReadBit(PFC3L, BIT2)
#define Iodd_RREG_FC_33                      TARG_ReadBit(PFC3L, BIT3)
#define Iodd_RREG_FC_34                      TARG_ReadBit(PFC3L, BIT4)
#define Iodd_RREG_FC_35                      TARG_ReadBit(PFC3L, BIT5)
#define Iodd_RREG_FC_36                      /* read access defined but should not be used */
#define Iodd_RREG_FC_37                      /* read access defined but should not be used */

#define Iodd_WREG_FC_30(Value)               /* write access not defined */
#define Iodd_WREG_FC_31(Value)               /* write access not defined */
#define Iodd_WREG_FC_32(Value)               TARG_WriteBit(PFC3L, BIT2, Value)
#define Iodd_WREG_FC_33(Value)               TARG_WriteBit(PFC3L, BIT3, Value)
#define Iodd_WREG_FC_34(Value)               TARG_WriteBit(PFC3L, BIT4, Value)
#define Iodd_WREG_FC_35(Value)               TARG_WriteBit(PFC3L, BIT5, Value)
#define Iodd_WREG_FC_36(Value)               /* write access not defined */
#define Iodd_WREG_FC_37(Value)               /* write access not defined */

#endif

#if                                          \
      defined(__NEC_V850_Fx3__)

#define Iodd_RREG_FCE_30                     /* read access defined but should not be used */
#define Iodd_RREG_FCE_31                     /* read access defined but should not be used */
#define Iodd_RREG_FCE_32                     TARG_ReadBit(PFCE3L, BIT2)
#define Iodd_RREG_FCE_33                     TARG_ReadBit(PFCE3L, BIT3)
#define Iodd_RREG_FCE_34                     TARG_ReadBit(PFCE3L, BIT4)
#define Iodd_RREG_FCE_35                     /* read access defined but should not be used */
#define Iodd_RREG_FCE_36                     /* read access defined but should not be used */
#define Iodd_RREG_FCE_37                     /* read access defined but should not be used */

#define Iodd_WREG_FCE_30(Value)              /* write access not defined */
#define Iodd_WREG_FCE_31(Value)              /* write access not defined */
#define Iodd_WREG_FCE_32(Value)              TARG_WriteBit(PFCE3L, BIT2, Value)
#define Iodd_WREG_FCE_33(Value)              TARG_WriteBit(PFCE3L, BIT3, Value)
#define Iodd_WREG_FCE_34(Value)              TARG_WriteBit(PFCE3L, BIT4, Value)
#define Iodd_WREG_FCE_35(Value)              /* write access not defined */
#define Iodd_WREG_FCE_36(Value)              /* write access not defined */
#define Iodd_WREG_FCE_37(Value)              /* write access not defined */

#endif

#if                                          \
      defined(__NEC_V850_FE3_F3370__)||      \
      defined(__NEC_V850_FE3_F3371__)

#define Iodd_RREG_PU_30                      TARG_ReadBit(PU3L, BIT0)
#define Iodd_RREG_PU_31                      TARG_ReadBit(PU3L, BIT1)
#define Iodd_RREG_PU_32                      TARG_ReadBit(PU3L, BIT2)
#define Iodd_RREG_PU_33                      TARG_ReadBit(PU3L, BIT3)
#define Iodd_RREG_PU_34                      TARG_ReadBit(PU3L, BIT4)
#define Iodd_RREG_PU_35                      TARG_ReadBit(PU3L, BIT5)
#define Iodd_RREG_PU_36                      /* read access defined but should not be used */
#define Iodd_RREG_PU_37                      /* read access defined but should not be used */

#define Iodd_WREG_PU_30(Value)               TARG_WriteBit(PU3L, BIT0, Value)
#define Iodd_WREG_PU_31(Value)               TARG_WriteBit(PU3L, BIT1, Value)
#define Iodd_WREG_PU_32(Value)               TARG_WriteBit(PU3L, BIT2, Value)
#define Iodd_WREG_PU_33(Value)               TARG_WriteBit(PU3L, BIT3, Value)
#define Iodd_WREG_PU_34(Value)               TARG_WriteBit(PU3L, BIT4, Value)
#define Iodd_WREG_PU_35(Value)               TARG_WriteBit(PU3L, BIT5, Value)
#define Iodd_WREG_PU_36(Value)               /* write access not defined */
#define Iodd_WREG_PU_37(Value)               /* write access not defined */

#endif

#if                                          \
      defined(__NEC_V850_FF3_F3372__)||      \
      defined(__NEC_V850_FF3_F3373__)||      \
      defined(__NEC_V850_FF3L_F3618__)

#define Iodd_RREG_PU_30                      TARG_ReadBit(PU3L, BIT0)
#define Iodd_RREG_PU_31                      TARG_ReadBit(PU3L, BIT1)
#define Iodd_RREG_PU_32                      TARG_ReadBit(PU3L, BIT2)
#define Iodd_RREG_PU_33                      TARG_ReadBit(PU3L, BIT3)
#define Iodd_RREG_PU_34                      TARG_ReadBit(PU3L, BIT4)
#define Iodd_RREG_PU_35                      TARG_ReadBit(PU3L, BIT5)
#define Iodd_RREG_PU_36                      /* read access defined but should not be used */
#define Iodd_RREG_PU_37                      /* read access defined but should not be used */
#define Iodd_RREG_PU_38                      TARG_ReadBit(PU3H, BIT0)
#define Iodd_RREG_PU_39                      TARG_ReadBit(PU3H, BIT1)
#define Iodd_RREG_PU_310                     /* read access defined but should not be used */
#define Iodd_RREG_PU_311                     /* read access defined but should not be used */
#define Iodd_RREG_PU_312                     /* read access defined but should not be used */
#define Iodd_RREG_PU_313                     /* read access defined but should not be used */
#define Iodd_RREG_PU_314                     /* read access defined but should not be used */
#define Iodd_RREG_PU_315                     /* read access defined but should not be used */

#define Iodd_WREG_PU_30(Value)               TARG_WriteBit(PU3L, BIT0, Value)
#define Iodd_WREG_PU_31(Value)               TARG_WriteBit(PU3L, BIT1, Value)
#define Iodd_WREG_PU_32(Value)               TARG_WriteBit(PU3L, BIT2, Value)
#define Iodd_WREG_PU_33(Value)               TARG_WriteBit(PU3L, BIT3, Value)
#define Iodd_WREG_PU_34(Value)               TARG_WriteBit(PU3L, BIT4, Value)
#define Iodd_WREG_PU_35(Value)               TARG_WriteBit(PU3L, BIT5, Value)
#define Iodd_WREG_PU_36(Value)               /* write access not defined */
#define Iodd_WREG_PU_37(Value)               /* write access not defined */
#define Iodd_WREG_PU_38(Value)               TARG_WriteBit(PU3H, BIT0, Value)
#define Iodd_WREG_PU_39(Value)               TARG_WriteBit(PU3H, BIT1, Value)
#define Iodd_WREG_PU_310(Value)              /* write access not defined */
#define Iodd_WREG_PU_311(Value)              /* write access not defined */
#define Iodd_WREG_PU_312(Value)              /* write access not defined */
#define Iodd_WREG_PU_313(Value)              /* write access not defined */
#define Iodd_WREG_PU_314(Value)              /* write access not defined */
#define Iodd_WREG_PU_315(Value)              /* write access not defined */

#endif

#if                                          \
      defined(__NEC_V850_FG3_F3374__)||      \
      defined(__NEC_V850_FG3_F3375__)||      \
      defined(__NEC_V850_FG3_F3376__)||      \
      defined(__NEC_V850_FG3_F3377__)||      \
      defined(__NEC_V850_FJ3_F3378__)||      \
      defined(__NEC_V850_FJ3_F3379__)||      \
      defined(__NEC_V850_FJ3_F3380__)||      \
      defined(__NEC_V850_FJ3_F3381__)||      \
      defined(__NEC_V850_FJ3_F3382__)||      \
      defined(__NEC_V850_FK3_F3383__)||      \
      defined(__NEC_V850_FK3_F3384__)||      \
      defined(__NEC_V850_FK3_F3385__)

#define Iodd_RREG_PU_30                      TARG_ReadBit(PU3L, BIT0)
#define Iodd_RREG_PU_31                      TARG_ReadBit(PU3L, BIT1)
#define Iodd_RREG_PU_32                      TARG_ReadBit(PU3L, BIT2)
#define Iodd_RREG_PU_33                      TARG_ReadBit(PU3L, BIT3)
#define Iodd_RREG_PU_34                      TARG_ReadBit(PU3L, BIT4)
#define Iodd_RREG_PU_35                      TARG_ReadBit(PU3L, BIT5)
#define Iodd_RREG_PU_36                      TARG_ReadBit(PU3L, BIT6)
#define Iodd_RREG_PU_37                      TARG_ReadBit(PU3L, BIT7)
#define Iodd_RREG_PU_38                      TARG_ReadBit(PU3H, BIT0)
#define Iodd_RREG_PU_39                      TARG_ReadBit(PU3H, BIT1)
#define Iodd_RREG_PU_310                     /* read access defined but should not be used */
#define Iodd_RREG_PU_311                     /* read access defined but should not be used */
#define Iodd_RREG_PU_312                     /* read access defined but should not be used */
#define Iodd_RREG_PU_313                     /* read access defined but should not be used */
#define Iodd_RREG_PU_314                     /* read access defined but should not be used */
#define Iodd_RREG_PU_315                     /* read access defined but should not be used */

#define Iodd_WREG_PU_30(Value)               TARG_WriteBit(PU3L, BIT0, Value)
#define Iodd_WREG_PU_31(Value)               TARG_WriteBit(PU3L, BIT1, Value)
#define Iodd_WREG_PU_32(Value)               TARG_WriteBit(PU3L, BIT2, Value)
#define Iodd_WREG_PU_33(Value)               TARG_WriteBit(PU3L, BIT3, Value)
#define Iodd_WREG_PU_34(Value)               TARG_WriteBit(PU3L, BIT4, Value)
#define Iodd_WREG_PU_35(Value)               TARG_WriteBit(PU3L, BIT5, Value)
#define Iodd_WREG_PU_36(Value)               TARG_WriteBit(PU3L, BIT6, Value)
#define Iodd_WREG_PU_37(Value)               TARG_WriteBit(PU3L, BIT7, Value)
#define Iodd_WREG_PU_38(Value)               TARG_WriteBit(PU3H, BIT0, Value)
#define Iodd_WREG_PU_39(Value)               TARG_WriteBit(PU3H, BIT1, Value)
#define Iodd_WREG_PU_310(Value)              /* write access not defined */
#define Iodd_WREG_PU_311(Value)              /* write access not defined */
#define Iodd_WREG_PU_312(Value)              /* write access not defined */
#define Iodd_WREG_PU_313(Value)              /* write access not defined */
#define Iodd_WREG_PU_314(Value)              /* write access not defined */
#define Iodd_WREG_PU_315(Value)              /* write access not defined */

#endif

#if                                          \
      defined(__NEC_V850_FE3_F3370__)||      \
      defined(__NEC_V850_FE3_F3370__)||      \
      defined(__NEC_V850_FE3_F3371__)

#define Iodd_RREG_P_38                       /* register undefined */
#define Iodd_RREG_P_39                       /* register undefined */
#define Iodd_RREG_P_310                      /* register undefined */
#define Iodd_RREG_P_311                      /* register undefined */
#define Iodd_RREG_P_312                      /* register undefined */
#define Iodd_RREG_P_313                      /* register undefined */
#define Iodd_RREG_P_314                      /* register undefined */
#define Iodd_RREG_P_315                      /* register undefined */

#define Iodd_WREG_P_38(Value)                /* register undefined */
#define Iodd_WREG_P_39(Value)                /* register undefined */
#define Iodd_WREG_P_310(Value)               /* register undefined */
#define Iodd_WREG_P_311(Value)               /* register undefined */
#define Iodd_WREG_P_312(Value)               /* register undefined */
#define Iodd_WREG_P_313(Value)               /* register undefined */
#define Iodd_WREG_P_314(Value)               /* register undefined */
#define Iodd_WREG_P_315(Value)               /* register undefined */

#endif

#if                                          \
      defined(__NEC_V850_FE3_F3370__)||      \
      defined(__NEC_V850_FE3_F3370__)||      \
      defined(__NEC_V850_FE3_F3371__)

#define Iodd_RREG_M_38                       /* register undefined */
#define Iodd_RREG_M_39                       /* register undefined */
#define Iodd_RREG_M_310                      /* register undefined */
#define Iodd_RREG_M_311                      /* register undefined */
#define Iodd_RREG_M_312                      /* register undefined */
#define Iodd_RREG_M_313                      /* register undefined */
#define Iodd_RREG_M_314                      /* register undefined */
#define Iodd_RREG_M_315                      /* register undefined */

#define Iodd_WREG_M_38(Value)                /* register undefined */
#define Iodd_WREG_M_39(Value)                /* register undefined */
#define Iodd_WREG_M_310(Value)               /* register undefined */
#define Iodd_WREG_M_311(Value)               /* register undefined */
#define Iodd_WREG_M_312(Value)               /* register undefined */
#define Iodd_WREG_M_313(Value)               /* register undefined */
#define Iodd_WREG_M_314(Value)               /* register undefined */
#define Iodd_WREG_M_315(Value)               /* register undefined */

#endif

#if                                          \
      defined(__NEC_V850_FE3_F3370__)||      \
      defined(__NEC_V850_FE3_F3370__)||      \
      defined(__NEC_V850_FE3_F3371__)||      \
      defined(__NEC_V850_FF3_F3372__)||      \
      defined(__NEC_V850_FF3_F3373__)||      \
      defined(__NEC_V850_FF3L_F3618__)

#define Iodd_RREG_MC_38                      /* register undefined */
#define Iodd_RREG_MC_39                      /* register undefined */
#define Iodd_RREG_MC_310                     /* register undefined */
#define Iodd_RREG_MC_311                     /* register undefined */
#define Iodd_RREG_MC_312                     /* register undefined */
#define Iodd_RREG_MC_313                     /* register undefined */
#define Iodd_RREG_MC_314                     /* register undefined */
#define Iodd_RREG_MC_315                     /* register undefined */

#define Iodd_WREG_MC_38(Value)               /* register undefined */
#define Iodd_WREG_MC_39(Value)               /* register undefined */
#define Iodd_WREG_MC_310(Value)              /* register undefined */
#define Iodd_WREG_MC_311(Value)              /* register undefined */
#define Iodd_WREG_MC_312(Value)              /* register undefined */
#define Iodd_WREG_MC_313(Value)              /* register undefined */
#define Iodd_WREG_MC_314(Value)              /* register undefined */
#define Iodd_WREG_MC_315(Value)              /* register undefined */

#endif

#if                                          \
      defined(__NEC_V850_FE3_F3370__)||      \
      defined(__NEC_V850_FE3_F3370__)||      \
      defined(__NEC_V850_FE3_F3371__)||      \
      defined(__NEC_V850_FF3_F3372__)||      \
      defined(__NEC_V850_FF3_F3373__)||      \
      defined(__NEC_V850_FG3_F3374__)||      \
      defined(__NEC_V850_FG3_F3375__)||      \
      defined(__NEC_V850_FG3_F3376__)||      \
      defined(__NEC_V850_FG3_F3377__)||      \
      defined(__NEC_V850_FJ3_F3378__)||      \
      defined(__NEC_V850_FJ3_F3379__)||      \
      defined(__NEC_V850_FJ3_F3380__)||      \
      defined(__NEC_V850_FJ3_F3381__)||      \
      defined(__NEC_V850_FJ3_F3382__)||      \
      defined(__NEC_V850_FK3_F3383__)||      \
      defined(__NEC_V850_FK3_F3384__)||      \
      defined(__NEC_V850_FK3_F3385__)||      \
      defined(__NEC_V850_FF3L_F3618__)

#define Iodd_RREG_FC_38                      /* register undefined */
#define Iodd_RREG_FC_39                      /* register undefined */
#define Iodd_RREG_FC_310                     /* register undefined */
#define Iodd_RREG_FC_311                     /* register undefined */
#define Iodd_RREG_FC_312                     /* register undefined */
#define Iodd_RREG_FC_313                     /* register undefined */
#define Iodd_RREG_FC_314                     /* register undefined */
#define Iodd_RREG_FC_315                     /* register undefined */

#define Iodd_WREG_FC_38(Value)               /* register undefined */
#define Iodd_WREG_FC_39(Value)               /* register undefined */
#define Iodd_WREG_FC_310(Value)              /* register undefined */
#define Iodd_WREG_FC_311(Value)              /* register undefined */
#define Iodd_WREG_FC_312(Value)              /* register undefined */
#define Iodd_WREG_FC_313(Value)              /* register undefined */
#define Iodd_WREG_FC_314(Value)              /* register undefined */
#define Iodd_WREG_FC_315(Value)              /* register undefined */

#endif

#if                                          \
      defined(__NEC_V850_FE3_F3370__)||      \
      defined(__NEC_V850_FE3_F3370__)||      \
      defined(__NEC_V850_FE3_F3371__)||      \
      defined(__NEC_V850_FF3_F3372__)||      \
      defined(__NEC_V850_FF3_F3373__)||      \
      defined(__NEC_V850_FG3_F3374__)||      \
      defined(__NEC_V850_FG3_F3375__)||      \
      defined(__NEC_V850_FG3_F3376__)||      \
      defined(__NEC_V850_FG3_F3377__)||      \
      defined(__NEC_V850_FJ3_F3378__)||      \
      defined(__NEC_V850_FJ3_F3379__)||      \
      defined(__NEC_V850_FJ3_F3380__)||      \
      defined(__NEC_V850_FJ3_F3381__)||      \
      defined(__NEC_V850_FJ3_F3382__)||      \
      defined(__NEC_V850_FK3_F3383__)||      \
      defined(__NEC_V850_FK3_F3384__)||      \
      defined(__NEC_V850_FK3_F3385__)||      \
      defined(__NEC_V850_FF3L_F3618__)

#define Iodd_RREG_FCE_38                     /* register undefined */
#define Iodd_RREG_FCE_39                     /* register undefined */
#define Iodd_RREG_FCE_310                    /* register undefined */
#define Iodd_RREG_FCE_311                    /* register undefined */
#define Iodd_RREG_FCE_312                    /* register undefined */
#define Iodd_RREG_FCE_313                    /* register undefined */
#define Iodd_RREG_FCE_314                    /* register undefined */
#define Iodd_RREG_FCE_315                    /* register undefined */

#define Iodd_WREG_FCE_38(Value)              /* register undefined */
#define Iodd_WREG_FCE_39(Value)              /* register undefined */
#define Iodd_WREG_FCE_310(Value)             /* register undefined */
#define Iodd_WREG_FCE_311(Value)             /* register undefined */
#define Iodd_WREG_FCE_312(Value)             /* register undefined */
#define Iodd_WREG_FCE_313(Value)             /* register undefined */
#define Iodd_WREG_FCE_314(Value)             /* register undefined */
#define Iodd_WREG_FCE_315(Value)             /* register undefined */

#endif

#if                                          \
      defined(__NEC_V850_FE3_F3370__)||      \
      defined(__NEC_V850_FE3_F3370__)||      \
      defined(__NEC_V850_FE3_F3371__)

#define Iodd_RREG_PU_38                      /* register undefined */
#define Iodd_RREG_PU_39                      /* register undefined */
#define Iodd_RREG_PU_310                     /* register undefined */
#define Iodd_RREG_PU_311                     /* register undefined */
#define Iodd_RREG_PU_312                     /* register undefined */
#define Iodd_RREG_PU_313                     /* register undefined */
#define Iodd_RREG_PU_314                     /* register undefined */
#define Iodd_RREG_PU_315                     /* register undefined */

#define Iodd_WREG_PU_38(Value)               /* register undefined */
#define Iodd_WREG_PU_39(Value)               /* register undefined */
#define Iodd_WREG_PU_310(Value)              /* register undefined */
#define Iodd_WREG_PU_311(Value)              /* register undefined */
#define Iodd_WREG_PU_312(Value)              /* register undefined */
#define Iodd_WREG_PU_313(Value)              /* register undefined */
#define Iodd_WREG_PU_314(Value)              /* register undefined */
#define Iodd_WREG_PU_315(Value)              /* register undefined */

#endif

#if                                          \
      defined(__NEC_V850_Fx3__)

#define Iodd_RREG_PF_30                      /* register undefined */
#define Iodd_RREG_PF_31                      /* register undefined */
#define Iodd_RREG_PF_32                      /* register undefined */
#define Iodd_RREG_PF_33                      /* register undefined */
#define Iodd_RREG_PF_34                      /* register undefined */
#define Iodd_RREG_PF_35                      /* register undefined */
#define Iodd_RREG_PF_36                      /* register undefined */
#define Iodd_RREG_PF_37                      /* register undefined */
#define Iodd_RREG_PF_38                      /* register undefined */
#define Iodd_RREG_PF_39                      /* register undefined */
#define Iodd_RREG_PF_310                     /* register undefined */
#define Iodd_RREG_PF_311                     /* register undefined */
#define Iodd_RREG_PF_312                     /* register undefined */
#define Iodd_RREG_PF_313                     /* register undefined */
#define Iodd_RREG_PF_314                     /* register undefined */
#define Iodd_RREG_PF_315                     /* register undefined */

#define Iodd_WREG_PF_30(Value)               /* register undefined */
#define Iodd_WREG_PF_31(Value)               /* register undefined */
#define Iodd_WREG_PF_32(Value)               /* register undefined */
#define Iodd_WREG_PF_33(Value)               /* register undefined */
#define Iodd_WREG_PF_34(Value)               /* register undefined */
#define Iodd_WREG_PF_35(Value)               /* register undefined */
#define Iodd_WREG_PF_36(Value)               /* register undefined */
#define Iodd_WREG_PF_37(Value)               /* register undefined */
#define Iodd_WREG_PF_38(Value)               /* register undefined */
#define Iodd_WREG_PF_39(Value)               /* register undefined */
#define Iodd_WREG_PF_310(Value)              /* register undefined */
#define Iodd_WREG_PF_311(Value)              /* register undefined */
#define Iodd_WREG_PF_312(Value)              /* register undefined */
#define Iodd_WREG_PF_313(Value)              /* register undefined */
#define Iodd_WREG_PF_314(Value)              /* register undefined */
#define Iodd_WREG_PF_315(Value)              /* register undefined */

#endif

/* Definitions PORT 4 */

#if                                          \
      defined(__NEC_V850_Fx3__)

#define Iodd_RREG_P_40                       TARG_ReadBit(P4, BIT0)
#define Iodd_RREG_P_41                       TARG_ReadBit(P4, BIT1)
#define Iodd_RREG_P_42                       TARG_ReadBit(P4, BIT2)
#define Iodd_RREG_P_43                       /* read access defined but should not be used */
#define Iodd_RREG_P_44                       /* read access defined but should not be used */
#define Iodd_RREG_P_45                       /* read access defined but should not be used */
#define Iodd_RREG_P_46                       /* read access defined but should not be used */
#define Iodd_RREG_P_47                       /* read access defined but should not be used */

#define Iodd_WREG_P_40(Value)                TARG_WriteBit(P4, BIT0, Value)
#define Iodd_WREG_P_41(Value)                TARG_WriteBit(P4, BIT1, Value)
#define Iodd_WREG_P_42(Value)                TARG_WriteBit(P4, BIT2, Value)
#define Iodd_WREG_P_43(Value)                /* write access not defined */
#define Iodd_WREG_P_44(Value)                /* write access not defined */
#define Iodd_WREG_P_45(Value)                /* write access not defined */
#define Iodd_WREG_P_46(Value)                /* write access not defined */
#define Iodd_WREG_P_47(Value)                /* write access not defined */

#endif

#if                                          \
      defined(__NEC_V850_Fx3__)

#define Iodd_RREG_M_40                       TARG_ReadBit(PM4, BIT0)
#define Iodd_RREG_M_41                       TARG_ReadBit(PM4, BIT1)
#define Iodd_RREG_M_42                       TARG_ReadBit(PM4, BIT2)
#define Iodd_RREG_M_43                       /* read access defined but should not be used */
#define Iodd_RREG_M_44                       /* read access defined but should not be used */
#define Iodd_RREG_M_45                       /* read access defined but should not be used */
#define Iodd_RREG_M_46                       /* read access defined but should not be used */
#define Iodd_RREG_M_47                       /* read access defined but should not be used */

#define Iodd_WREG_M_40(Value)                TARG_WriteBit(PM4, BIT0, Value)
#define Iodd_WREG_M_41(Value)                TARG_WriteBit(PM4, BIT1, Value)
#define Iodd_WREG_M_42(Value)                TARG_WriteBit(PM4, BIT2, Value)
#define Iodd_WREG_M_43(Value)                /* write access not defined */
#define Iodd_WREG_M_44(Value)                /* write access not defined */
#define Iodd_WREG_M_45(Value)                /* write access not defined */
#define Iodd_WREG_M_46(Value)                /* write access not defined */
#define Iodd_WREG_M_47(Value)                /* write access not defined */

#endif

#if                                          \
      defined(__NEC_V850_Fx3__)

#define Iodd_RREG_MC_40                      TARG_ReadBit(PMC4, BIT0)
#define Iodd_RREG_MC_41                      TARG_ReadBit(PMC4, BIT1)
#define Iodd_RREG_MC_42                      TARG_ReadBit(PMC4, BIT2)
#define Iodd_RREG_MC_43                      /* read access defined but should not be used */
#define Iodd_RREG_MC_44                      /* read access defined but should not be used */
#define Iodd_RREG_MC_45                      /* read access defined but should not be used */
#define Iodd_RREG_MC_46                      /* read access defined but should not be used */
#define Iodd_RREG_MC_47                      /* read access defined but should not be used */

#define Iodd_WREG_MC_40(Value)               TARG_WriteBit(PMC4, BIT0, Value)
#define Iodd_WREG_MC_41(Value)               TARG_WriteBit(PMC4, BIT1, Value)
#define Iodd_WREG_MC_42(Value)               TARG_WriteBit(PMC4, BIT2, Value)
#define Iodd_WREG_MC_43(Value)               /* write access not defined */
#define Iodd_WREG_MC_44(Value)               /* write access not defined */
#define Iodd_WREG_MC_45(Value)               /* write access not defined */
#define Iodd_WREG_MC_46(Value)               /* write access not defined */
#define Iodd_WREG_MC_47(Value)               /* write access not defined */

#endif

#if                                          \
      defined(__NEC_V850_Fx3__)

#define Iodd_RREG_FC_40                      TARG_ReadBit(PFC4, BIT0)
#define Iodd_RREG_FC_41                      TARG_ReadBit(PFC4, BIT1)
#define Iodd_RREG_FC_42                      TARG_ReadBit(PFC4, BIT2)
#define Iodd_RREG_FC_43                      /* read access defined but should not be used */
#define Iodd_RREG_FC_44                      /* read access defined but should not be used */
#define Iodd_RREG_FC_45                      /* read access defined but should not be used */
#define Iodd_RREG_FC_46                      /* read access defined but should not be used */
#define Iodd_RREG_FC_47                      /* read access defined but should not be used */

#define Iodd_WREG_FC_40(Value)               TARG_WriteBit(PFC4, BIT0, Value)
#define Iodd_WREG_FC_41(Value)               TARG_WriteBit(PFC4, BIT1, Value)
#define Iodd_WREG_FC_42(Value)               TARG_WriteBit(PFC4, BIT2, Value)
#define Iodd_WREG_FC_43(Value)               /* write access not defined */
#define Iodd_WREG_FC_44(Value)               /* write access not defined */
#define Iodd_WREG_FC_45(Value)               /* write access not defined */
#define Iodd_WREG_FC_46(Value)               /* write access not defined */
#define Iodd_WREG_FC_47(Value)               /* write access not defined */

#endif

#if                                          \
      defined(__NEC_V850_FG3_F3376__)||      \
      defined(__NEC_V850_FG3_F3377__)||      \
      defined(__NEC_V850_FJ3_F3379__)||      \
      defined(__NEC_V850_FJ3_F3380__)||      \
      defined(__NEC_V850_FJ3_F3381__)||      \
      defined(__NEC_V850_FJ3_F3382__)||      \
      defined(__NEC_V850_FK3_F3383__)||      \
      defined(__NEC_V850_FK3_F3384__)||      \
      defined(__NEC_V850_FK3_F3385__)

#define Iodd_RREG_FCE_40                     TARG_ReadBit(PFCE4, BIT0)
#define Iodd_RREG_FCE_41                     TARG_ReadBit(PFCE4, BIT1)
#define Iodd_RREG_FCE_42                     /* read access defined but should not be used */
#define Iodd_RREG_FCE_43                     /* read access defined but should not be used */
#define Iodd_RREG_FCE_44                     /* read access defined but should not be used */
#define Iodd_RREG_FCE_45                     /* read access defined but should not be used */
#define Iodd_RREG_FCE_46                     /* read access defined but should not be used */
#define Iodd_RREG_FCE_47                     /* read access defined but should not be used */

#define Iodd_WREG_FCE_40(Value)              TARG_WriteBit(PFCE4, BIT0, Value)
#define Iodd_WREG_FCE_41(Value)              TARG_WriteBit(PFCE4, BIT1, Value)
#define Iodd_WREG_FCE_42(Value)              /* write access not defined */
#define Iodd_WREG_FCE_43(Value)              /* write access not defined */
#define Iodd_WREG_FCE_44(Value)              /* write access not defined */
#define Iodd_WREG_FCE_45(Value)              /* write access not defined */
#define Iodd_WREG_FCE_46(Value)              /* write access not defined */
#define Iodd_WREG_FCE_47(Value)              /* write access not defined */

#endif

#if                                          \
      defined(__NEC_V850_Fx3__)

#define Iodd_RREG_PU_40                      TARG_ReadBit(PU4, BIT0)
#define Iodd_RREG_PU_41                      TARG_ReadBit(PU4, BIT1)
#define Iodd_RREG_PU_42                      TARG_ReadBit(PU4, BIT2)
#define Iodd_RREG_PU_43                      /* read access defined but should not be used */
#define Iodd_RREG_PU_44                      /* read access defined but should not be used */
#define Iodd_RREG_PU_45                      /* read access defined but should not be used */
#define Iodd_RREG_PU_46                      /* read access defined but should not be used */
#define Iodd_RREG_PU_47                      /* read access defined but should not be used */

#define Iodd_WREG_PU_40(Value)               TARG_WriteBit(PU4, BIT0, Value)
#define Iodd_WREG_PU_41(Value)               TARG_WriteBit(PU4, BIT1, Value)
#define Iodd_WREG_PU_42(Value)               TARG_WriteBit(PU4, BIT2, Value)
#define Iodd_WREG_PU_43(Value)               /* write access not defined */
#define Iodd_WREG_PU_44(Value)               /* write access not defined */
#define Iodd_WREG_PU_45(Value)               /* write access not defined */
#define Iodd_WREG_PU_46(Value)               /* write access not defined */
#define Iodd_WREG_PU_47(Value)               /* write access not defined */

#endif

#if                                          \
      defined(__NEC_V850_FE3_F3370__)||      \
      defined(__NEC_V850_FE3_F3371__)||      \
      defined(__NEC_V850_FF3_F3372__)||      \
      defined(__NEC_V850_FF3_F3373__)||      \
      defined(__NEC_V850_FG3_F3374__)||      \
      defined(__NEC_V850_FG3_F3375__)||      \
      defined(__NEC_V850_FJ3_F3378__)||      \
      defined(__NEC_V850_FF3L_F3618__)

#define Iodd_RREG_FCE_40                     /* register undefined */
#define Iodd_RREG_FCE_41                     /* register undefined */
#define Iodd_RREG_FCE_42                     /* register undefined */
#define Iodd_RREG_FCE_43                     /* register undefined */
#define Iodd_RREG_FCE_44                     /* register undefined */
#define Iodd_RREG_FCE_45                     /* register undefined */
#define Iodd_RREG_FCE_46                     /* register undefined */
#define Iodd_RREG_FCE_47                     /* register undefined */

#define Iodd_WREG_FCE_40(Value)              /* register undefined */
#define Iodd_WREG_FCE_41(Value)              /* register undefined */
#define Iodd_WREG_FCE_42(Value)              /* register undefined */
#define Iodd_WREG_FCE_43(Value)              /* register undefined */
#define Iodd_WREG_FCE_44(Value)              /* register undefined */
#define Iodd_WREG_FCE_45(Value)              /* register undefined */
#define Iodd_WREG_FCE_46(Value)              /* register undefined */
#define Iodd_WREG_FCE_47(Value)              /* register undefined */

#endif

#if                                          \
      defined(__NEC_V850_Fx3__)

#define Iodd_RREG_PF_40                      /* register undefined */
#define Iodd_RREG_PF_41                      /* register undefined */
#define Iodd_RREG_PF_42                      /* register undefined */
#define Iodd_RREG_PF_43                      /* register undefined */
#define Iodd_RREG_PF_44                      /* register undefined */
#define Iodd_RREG_PF_45                      /* register undefined */
#define Iodd_RREG_PF_46                      /* register undefined */
#define Iodd_RREG_PF_47                      /* register undefined */

#define Iodd_WREG_PF_40(Value)               /* register undefined */
#define Iodd_WREG_PF_41(Value)               /* register undefined */
#define Iodd_WREG_PF_42(Value)               /* register undefined */
#define Iodd_WREG_PF_43(Value)               /* register undefined */
#define Iodd_WREG_PF_44(Value)               /* register undefined */
#define Iodd_WREG_PF_45(Value)               /* register undefined */
#define Iodd_WREG_PF_46(Value)               /* register undefined */
#define Iodd_WREG_PF_47(Value)               /* register undefined */

#endif

/* Definitions PORT 5 */

#if                                          \
      defined(__NEC_V850_Fx3__)

#define Iodd_RREG_P_50                       TARG_ReadBit(P5, BIT0)
#define Iodd_RREG_P_51                       TARG_ReadBit(P5, BIT1)
#define Iodd_RREG_P_52                       TARG_ReadBit(P5, BIT2)
#define Iodd_RREG_P_53                       TARG_ReadBit(P5, BIT3)
#define Iodd_RREG_P_54                       TARG_ReadBit(P5, BIT4)
#define Iodd_RREG_P_55                       TARG_ReadBit(P5, BIT5)
#define Iodd_RREG_P_56                       /* read access defined but should not be used */
#define Iodd_RREG_P_57                       /* read access defined but should not be used */

#define Iodd_WREG_P_50(Value)                TARG_WriteBit(P5, BIT0, Value)
#define Iodd_WREG_P_51(Value)                TARG_WriteBit(P5, BIT1, Value)
#define Iodd_WREG_P_52(Value)                TARG_WriteBit(P5, BIT2, Value)
#define Iodd_WREG_P_53(Value)                TARG_WriteBit(P5, BIT3, Value)
#define Iodd_WREG_P_54(Value)                TARG_WriteBit(P5, BIT4, Value)
#define Iodd_WREG_P_55(Value)                TARG_WriteBit(P5, BIT5, Value)
#define Iodd_WREG_P_56(Value)                /* write access not defined */
#define Iodd_WREG_P_57(Value)                /* write access not defined */

#endif

#if                                          \
      defined(__NEC_V850_Fx3__)

#define Iodd_RREG_M_50                       TARG_ReadBit(PM5, BIT0)
#define Iodd_RREG_M_51                       TARG_ReadBit(PM5, BIT1)
#define Iodd_RREG_M_52                       TARG_ReadBit(PM5, BIT2)
#define Iodd_RREG_M_53                       TARG_ReadBit(PM5, BIT3)
#define Iodd_RREG_M_54                       TARG_ReadBit(PM5, BIT4)
#define Iodd_RREG_M_55                       TARG_ReadBit(PM5, BIT5)
#define Iodd_RREG_M_56                       /* read access defined but should not be used */
#define Iodd_RREG_M_57                       /* read access defined but should not be used */

#define Iodd_WREG_M_50(Value)                TARG_WriteBit(PM5, BIT0, Value)
#define Iodd_WREG_M_51(Value)                TARG_WriteBit(PM5, BIT1, Value)
#define Iodd_WREG_M_52(Value)                TARG_WriteBit(PM5, BIT2, Value)
#define Iodd_WREG_M_53(Value)                TARG_WriteBit(PM5, BIT3, Value)
#define Iodd_WREG_M_54(Value)                TARG_WriteBit(PM5, BIT4, Value)
#define Iodd_WREG_M_55(Value)                TARG_WriteBit(PM5, BIT5, Value)
#define Iodd_WREG_M_56(Value)                /* write access not defined */
#define Iodd_WREG_M_57(Value)                /* write access not defined */

#endif

#if                                          \
      defined(__NEC_V850_Fx3__)

#define Iodd_RREG_MC_50                      TARG_ReadBit(PMC5, BIT0)
#define Iodd_RREG_MC_51                      TARG_ReadBit(PMC5, BIT1)
#define Iodd_RREG_MC_52                      TARG_ReadBit(PMC5, BIT2)
#define Iodd_RREG_MC_53                      TARG_ReadBit(PMC5, BIT3)
#define Iodd_RREG_MC_54                      TARG_ReadBit(PMC5, BIT4)
#define Iodd_RREG_MC_55                      TARG_ReadBit(PMC5, BIT5)
#define Iodd_RREG_MC_56                      /* read access defined but should not be used */
#define Iodd_RREG_MC_57                      /* read access defined but should not be used */

#define Iodd_WREG_MC_50(Value)               TARG_WriteBit(PMC5, BIT0, Value)
#define Iodd_WREG_MC_51(Value)               TARG_WriteBit(PMC5, BIT1, Value)
#define Iodd_WREG_MC_52(Value)               TARG_WriteBit(PMC5, BIT2, Value)
#define Iodd_WREG_MC_53(Value)               TARG_WriteBit(PMC5, BIT3, Value)
#define Iodd_WREG_MC_54(Value)               TARG_WriteBit(PMC5, BIT4, Value)
#define Iodd_WREG_MC_55(Value)               TARG_WriteBit(PMC5, BIT5, Value)
#define Iodd_WREG_MC_56(Value)               /* write access not defined */
#define Iodd_WREG_MC_57(Value)               /* write access not defined */

#endif

#if                                          \
      defined(__NEC_V850_Fx3__)

#define Iodd_RREG_FC_50                      TARG_ReadBit(PFC5, BIT0)
#define Iodd_RREG_FC_51                      TARG_ReadBit(PFC5, BIT1)
#define Iodd_RREG_FC_52                      TARG_ReadBit(PFC5, BIT2)
#define Iodd_RREG_FC_53                      TARG_ReadBit(PFC5, BIT3)
#define Iodd_RREG_FC_54                      TARG_ReadBit(PFC5, BIT4)
#define Iodd_RREG_FC_55                      TARG_ReadBit(PFC5, BIT5)
#define Iodd_RREG_FC_56                      /* read access defined but should not be used */
#define Iodd_RREG_FC_57                      /* read access defined but should not be used */

#define Iodd_WREG_FC_50(Value)               TARG_WriteBit(PFC5, BIT0, Value)
#define Iodd_WREG_FC_51(Value)               TARG_WriteBit(PFC5, BIT1, Value)
#define Iodd_WREG_FC_52(Value)               TARG_WriteBit(PFC5, BIT2, Value)
#define Iodd_WREG_FC_53(Value)               TARG_WriteBit(PFC5, BIT3, Value)
#define Iodd_WREG_FC_54(Value)               TARG_WriteBit(PFC5, BIT4, Value)
#define Iodd_WREG_FC_55(Value)               TARG_WriteBit(PFC5, BIT5, Value)
#define Iodd_WREG_FC_56(Value)               /* write access not defined */
#define Iodd_WREG_FC_57(Value)               /* write access not defined */

#endif

#if                                          \
      defined(__NEC_V850_Fx3__)

#define Iodd_RREG_FCE_50                     TARG_ReadBit(PFCE5, BIT0)
#define Iodd_RREG_FCE_51                     TARG_ReadBit(PFCE5, BIT1)
#define Iodd_RREG_FCE_52                     TARG_ReadBit(PFCE5, BIT2)
#define Iodd_RREG_FCE_53                     TARG_ReadBit(PFCE5, BIT3)
#define Iodd_RREG_FCE_54                     TARG_ReadBit(PFCE5, BIT4)
#define Iodd_RREG_FCE_55                     TARG_ReadBit(PFCE5, BIT5)
#define Iodd_RREG_FCE_56                     /* read access defined but should not be used */
#define Iodd_RREG_FCE_57                     /* read access defined but should not be used */

#define Iodd_WREG_FCE_50(Value)              TARG_WriteBit(PFCE5, BIT0, Value)
#define Iodd_WREG_FCE_51(Value)              TARG_WriteBit(PFCE5, BIT1, Value)
#define Iodd_WREG_FCE_52(Value)              TARG_WriteBit(PFCE5, BIT2, Value)
#define Iodd_WREG_FCE_53(Value)              TARG_WriteBit(PFCE5, BIT3, Value)
#define Iodd_WREG_FCE_54(Value)              TARG_WriteBit(PFCE5, BIT4, Value)
#define Iodd_WREG_FCE_55(Value)              TARG_WriteBit(PFCE5, BIT5, Value)
#define Iodd_WREG_FCE_56(Value)              /* write access not defined */
#define Iodd_WREG_FCE_57(Value)              /* write access not defined */

#endif

#if                                          \
      defined(__NEC_V850_Fx3__)

#define Iodd_RREG_PU_50                      TARG_ReadBit(PU5, BIT0)
#define Iodd_RREG_PU_51                      TARG_ReadBit(PU5, BIT1)
#define Iodd_RREG_PU_52                      TARG_ReadBit(PU5, BIT2)
#define Iodd_RREG_PU_53                      TARG_ReadBit(PU5, BIT3)
#define Iodd_RREG_PU_54                      TARG_ReadBit(PU5, BIT4)
#define Iodd_RREG_PU_55                      TARG_ReadBit(PU5, BIT5)
#define Iodd_RREG_PU_56                      /* read access defined but should not be used */
#define Iodd_RREG_PU_57                      /* read access defined but should not be used */

#define Iodd_WREG_PU_50(Value)               TARG_WriteBit(PU5, BIT0, Value)
#define Iodd_WREG_PU_51(Value)               TARG_WriteBit(PU5, BIT1, Value)
#define Iodd_WREG_PU_52(Value)               TARG_WriteBit(PU5, BIT2, Value)
#define Iodd_WREG_PU_53(Value)               TARG_WriteBit(PU5, BIT3, Value)
#define Iodd_WREG_PU_54(Value)               TARG_WriteBit(PU5, BIT4, Value)
#define Iodd_WREG_PU_55(Value)               TARG_WriteBit(PU5, BIT5, Value)
#define Iodd_WREG_PU_56(Value)               /* write access not defined */
#define Iodd_WREG_PU_57(Value)               /* write access not defined */

#endif

#if                                          \
      defined(__NEC_V850_Fx3__)

#define Iodd_RREG_PF_50                      /* register undefined */
#define Iodd_RREG_PF_51                      /* register undefined */
#define Iodd_RREG_PF_52                      /* register undefined */
#define Iodd_RREG_PF_53                      /* register undefined */
#define Iodd_RREG_PF_54                      /* register undefined */
#define Iodd_RREG_PF_55                      /* register undefined */
#define Iodd_RREG_PF_56                      /* register undefined */
#define Iodd_RREG_PF_57                      /* register undefined */

#define Iodd_WREG_PF_50(Value)               /* register undefined */
#define Iodd_WREG_PF_51(Value)               /* register undefined */
#define Iodd_WREG_PF_52(Value)               /* register undefined */
#define Iodd_WREG_PF_53(Value)               /* register undefined */
#define Iodd_WREG_PF_54(Value)               /* register undefined */
#define Iodd_WREG_PF_55(Value)               /* register undefined */
#define Iodd_WREG_PF_56(Value)               /* register undefined */
#define Iodd_WREG_PF_57(Value)               /* register undefined */

#endif

/* Definitions PORT 6 */

#if                                          \
      defined(__NEC_V850_FJ3_F3378__)||      \
      defined(__NEC_V850_FJ3_F3379__)||      \
      defined(__NEC_V850_FJ3_F3380__)||      \
      defined(__NEC_V850_FJ3_F3381__)||      \
      defined(__NEC_V850_FJ3_F3382__)||      \
      defined(__NEC_V850_FK3_F3383__)||      \
      defined(__NEC_V850_FK3_F3384__)||      \
      defined(__NEC_V850_FK3_F3385__)

#define Iodd_RREG_P_60                       TARG_ReadBit(P6L, BIT0)
#define Iodd_RREG_P_61                       TARG_ReadBit(P6L, BIT1)
#define Iodd_RREG_P_62                       TARG_ReadBit(P6L, BIT2)
#define Iodd_RREG_P_63                       TARG_ReadBit(P6L, BIT3)
#define Iodd_RREG_P_64                       TARG_ReadBit(P6L, BIT4)
#define Iodd_RREG_P_65                       TARG_ReadBit(P6L, BIT5)
#define Iodd_RREG_P_66                       TARG_ReadBit(P6L, BIT6)
#define Iodd_RREG_P_67                       TARG_ReadBit(P6L, BIT7)
#define Iodd_RREG_P_68                       TARG_ReadBit(P6H, BIT0)
#define Iodd_RREG_P_69                       TARG_ReadBit(P6H, BIT1)
#define Iodd_RREG_P_610                      TARG_ReadBit(P6H, BIT2)
#define Iodd_RREG_P_611                      TARG_ReadBit(P6H, BIT3)
#define Iodd_RREG_P_612                      TARG_ReadBit(P6H, BIT4)
#define Iodd_RREG_P_613                      TARG_ReadBit(P6H, BIT5)
#define Iodd_RREG_P_614                      TARG_ReadBit(P6H, BIT6)
#define Iodd_RREG_P_615                      TARG_ReadBit(P6H, BIT7)

#define Iodd_WREG_P_60(Value)                TARG_WriteBit(P6L, BIT0, Value)
#define Iodd_WREG_P_61(Value)                TARG_WriteBit(P6L, BIT1, Value)
#define Iodd_WREG_P_62(Value)                TARG_WriteBit(P6L, BIT2, Value)
#define Iodd_WREG_P_63(Value)                TARG_WriteBit(P6L, BIT3, Value)
#define Iodd_WREG_P_64(Value)                TARG_WriteBit(P6L, BIT4, Value)
#define Iodd_WREG_P_65(Value)                TARG_WriteBit(P6L, BIT5, Value)
#define Iodd_WREG_P_66(Value)                TARG_WriteBit(P6L, BIT6, Value)
#define Iodd_WREG_P_67(Value)                TARG_WriteBit(P6L, BIT7, Value)
#define Iodd_WREG_P_68(Value)                TARG_WriteBit(P6H, BIT0, Value)
#define Iodd_WREG_P_69(Value)                TARG_WriteBit(P6H, BIT1, Value)
#define Iodd_WREG_P_610(Value)               TARG_WriteBit(P6H, BIT2, Value)
#define Iodd_WREG_P_611(Value)               TARG_WriteBit(P6H, BIT3, Value)
#define Iodd_WREG_P_612(Value)               TARG_WriteBit(P6H, BIT4, Value)
#define Iodd_WREG_P_613(Value)               TARG_WriteBit(P6H, BIT5, Value)
#define Iodd_WREG_P_614(Value)               TARG_WriteBit(P6H, BIT6, Value)
#define Iodd_WREG_P_615(Value)               TARG_WriteBit(P6H, BIT7, Value)

#endif

#if                                          \
      defined(__NEC_V850_FJ3_F3378__)||      \
      defined(__NEC_V850_FJ3_F3379__)||      \
      defined(__NEC_V850_FJ3_F3380__)||      \
      defined(__NEC_V850_FJ3_F3381__)||      \
      defined(__NEC_V850_FJ3_F3382__)||      \
      defined(__NEC_V850_FK3_F3383__)||      \
      defined(__NEC_V850_FK3_F3384__)||      \
      defined(__NEC_V850_FK3_F3385__)

#define Iodd_RREG_M_60                       TARG_ReadBit(PM6L, BIT0)
#define Iodd_RREG_M_61                       TARG_ReadBit(PM6L, BIT1)
#define Iodd_RREG_M_62                       TARG_ReadBit(PM6L, BIT2)
#define Iodd_RREG_M_63                       TARG_ReadBit(PM6L, BIT3)
#define Iodd_RREG_M_64                       TARG_ReadBit(PM6L, BIT4)
#define Iodd_RREG_M_65                       TARG_ReadBit(PM6L, BIT5)
#define Iodd_RREG_M_66                       TARG_ReadBit(PM6L, BIT6)
#define Iodd_RREG_M_67                       TARG_ReadBit(PM6L, BIT7)
#define Iodd_RREG_M_68                       TARG_ReadBit(PM6H, BIT0)
#define Iodd_RREG_M_69                       TARG_ReadBit(PM6H, BIT1)
#define Iodd_RREG_M_610                      TARG_ReadBit(PM6H, BIT2)
#define Iodd_RREG_M_611                      TARG_ReadBit(PM6H, BIT3)
#define Iodd_RREG_M_612                      TARG_ReadBit(PM6H, BIT4)
#define Iodd_RREG_M_613                      TARG_ReadBit(PM6H, BIT5)
#define Iodd_RREG_M_614                      TARG_ReadBit(PM6H, BIT6)
#define Iodd_RREG_M_615                      TARG_ReadBit(PM6H, BIT7)

#define Iodd_WREG_M_60(Value)                TARG_WriteBit(PM6L, BIT0, Value)
#define Iodd_WREG_M_61(Value)                TARG_WriteBit(PM6L, BIT1, Value)
#define Iodd_WREG_M_62(Value)                TARG_WriteBit(PM6L, BIT2, Value)
#define Iodd_WREG_M_63(Value)                TARG_WriteBit(PM6L, BIT3, Value)
#define Iodd_WREG_M_64(Value)                TARG_WriteBit(PM6L, BIT4, Value)
#define Iodd_WREG_M_65(Value)                TARG_WriteBit(PM6L, BIT5, Value)
#define Iodd_WREG_M_66(Value)                TARG_WriteBit(PM6L, BIT6, Value)
#define Iodd_WREG_M_67(Value)                TARG_WriteBit(PM6L, BIT7, Value)
#define Iodd_WREG_M_68(Value)                TARG_WriteBit(PM6H, BIT0, Value)
#define Iodd_WREG_M_69(Value)                TARG_WriteBit(PM6H, BIT1, Value)
#define Iodd_WREG_M_610(Value)               TARG_WriteBit(PM6H, BIT2, Value)
#define Iodd_WREG_M_611(Value)               TARG_WriteBit(PM6H, BIT3, Value)
#define Iodd_WREG_M_612(Value)               TARG_WriteBit(PM6H, BIT4, Value)
#define Iodd_WREG_M_613(Value)               TARG_WriteBit(PM6H, BIT5, Value)
#define Iodd_WREG_M_614(Value)               TARG_WriteBit(PM6H, BIT6, Value)
#define Iodd_WREG_M_615(Value)               TARG_WriteBit(PM6H, BIT7, Value)

#endif

#if                                          \
      defined(__NEC_V850_FJ3_F3378__)

#define Iodd_RREG_MC_60                      TARG_ReadBit(PMC6L, BIT0)
#define Iodd_RREG_MC_61                      TARG_ReadBit(PMC6L, BIT1)
#define Iodd_RREG_MC_62                      TARG_ReadBit(PMC6L, BIT2)
#define Iodd_RREG_MC_63                      /* read access defined but should not be used */
#define Iodd_RREG_MC_64                      /* read access defined but should not be used */
#define Iodd_RREG_MC_65                      TARG_ReadBit(PMC6L, BIT5)
#define Iodd_RREG_MC_66                      TARG_ReadBit(PMC6L, BIT6)
#define Iodd_RREG_MC_67                      /* read access defined but should not be used */
#define Iodd_RREG_MC_68                      /* read access defined but should not be used */
#define Iodd_RREG_MC_69                      /* read access defined but should not be used */
#define Iodd_RREG_MC_610                     TARG_ReadBit(PMC6H, BIT2)
#define Iodd_RREG_MC_611                     TARG_ReadBit(PMC6H, BIT3)
#define Iodd_RREG_MC_612                     TARG_ReadBit(PMC6H, BIT4)
#define Iodd_RREG_MC_613                     TARG_ReadBit(PMC6H, BIT5)
#define Iodd_RREG_MC_614                     /* read access defined but should not be used */
#define Iodd_RREG_MC_615                     /* read access defined but should not be used */

#define Iodd_WREG_MC_60(Value)               TARG_WriteBit(PMC6L, BIT0, Value)
#define Iodd_WREG_MC_61(Value)               TARG_WriteBit(PMC6L, BIT1, Value)
#define Iodd_WREG_MC_62(Value)               TARG_WriteBit(PMC6L, BIT2, Value)
#define Iodd_WREG_MC_63(Value)               /* write access not defined */
#define Iodd_WREG_MC_64(Value)               /* write access not defined */
#define Iodd_WREG_MC_65(Value)               TARG_WriteBit(PMC6L, BIT5, Value)
#define Iodd_WREG_MC_66(Value)               TARG_WriteBit(PMC6L, BIT6, Value)
#define Iodd_WREG_MC_67(Value)               /* write access not defined */
#define Iodd_WREG_MC_68(Value)               /* write access not defined */
#define Iodd_WREG_MC_69(Value)               /* write access not defined */
#define Iodd_WREG_MC_610(Value)              TARG_WriteBit(PMC6H, BIT2, Value)
#define Iodd_WREG_MC_611(Value)              TARG_WriteBit(PMC6H, BIT3, Value)
#define Iodd_WREG_MC_612(Value)              TARG_WriteBit(PMC6H, BIT4, Value)
#define Iodd_WREG_MC_613(Value)              TARG_WriteBit(PMC6H, BIT5, Value)
#define Iodd_WREG_MC_614(Value)              /* write access not defined */
#define Iodd_WREG_MC_615(Value)              /* write access not defined */

#endif

#if                                          \
      defined(__NEC_V850_FJ3_F3379__)||      \
      defined(__NEC_V850_FJ3_F3380__)

#define Iodd_RREG_MC_60                      TARG_ReadBit(PMC6L, BIT0)
#define Iodd_RREG_MC_61                      TARG_ReadBit(PMC6L, BIT1)
#define Iodd_RREG_MC_62                      TARG_ReadBit(PMC6L, BIT2)
#define Iodd_RREG_MC_63                      /* read access defined but should not be used */
#define Iodd_RREG_MC_64                      /* read access defined but should not be used */
#define Iodd_RREG_MC_65                      TARG_ReadBit(PMC6L, BIT5)
#define Iodd_RREG_MC_66                      TARG_ReadBit(PMC6L, BIT6)
#define Iodd_RREG_MC_67                      TARG_ReadBit(PMC6L, BIT7)
#define Iodd_RREG_MC_68                      TARG_ReadBit(PMC6H, BIT0)
#define Iodd_RREG_MC_69                      /* read access defined but should not be used */
#define Iodd_RREG_MC_610                     TARG_ReadBit(PMC6H, BIT2)
#define Iodd_RREG_MC_611                     TARG_ReadBit(PMC6H, BIT3)
#define Iodd_RREG_MC_612                     TARG_ReadBit(PMC6H, BIT4)
#define Iodd_RREG_MC_613                     TARG_ReadBit(PMC6H, BIT5)
#define Iodd_RREG_MC_614                     /* read access defined but should not be used */
#define Iodd_RREG_MC_615                     /* read access defined but should not be used */

#define Iodd_WREG_MC_60(Value)               TARG_WriteBit(PMC6L, BIT0, Value)
#define Iodd_WREG_MC_61(Value)               TARG_WriteBit(PMC6L, BIT1, Value)
#define Iodd_WREG_MC_62(Value)               TARG_WriteBit(PMC6L, BIT2, Value)
#define Iodd_WREG_MC_63(Value)               /* write access not defined */
#define Iodd_WREG_MC_64(Value)               /* write access not defined */
#define Iodd_WREG_MC_65(Value)               TARG_WriteBit(PMC6L, BIT5, Value)
#define Iodd_WREG_MC_66(Value)               TARG_WriteBit(PMC6L, BIT6, Value)
#define Iodd_WREG_MC_67(Value)               TARG_WriteBit(PMC6L, BIT7, Value)
#define Iodd_WREG_MC_68(Value)               TARG_WriteBit(PMC6H, BIT0, Value)
#define Iodd_WREG_MC_69(Value)               /* write access not defined */
#define Iodd_WREG_MC_610(Value)              TARG_WriteBit(PMC6H, BIT2, Value)
#define Iodd_WREG_MC_611(Value)              TARG_WriteBit(PMC6H, BIT3, Value)
#define Iodd_WREG_MC_612(Value)              TARG_WriteBit(PMC6H, BIT4, Value)
#define Iodd_WREG_MC_613(Value)              TARG_WriteBit(PMC6H, BIT5, Value)
#define Iodd_WREG_MC_614(Value)              /* write access not defined */
#define Iodd_WREG_MC_615(Value)              /* write access not defined */

#endif

#if                                          \
      defined(__NEC_V850_FJ3_F3381__)||      \
      defined(__NEC_V850_FJ3_F3382__)

#define Iodd_RREG_MC_60                      TARG_ReadBit(PMC6L, BIT0)
#define Iodd_RREG_MC_61                      TARG_ReadBit(PMC6L, BIT1)
#define Iodd_RREG_MC_62                      TARG_ReadBit(PMC6L, BIT2)
#define Iodd_RREG_MC_63                      TARG_ReadBit(PMC6L, BIT3)
#define Iodd_RREG_MC_64                      TARG_ReadBit(PMC6L, BIT4)
#define Iodd_RREG_MC_65                      TARG_ReadBit(PMC6L, BIT5)
#define Iodd_RREG_MC_66                      TARG_ReadBit(PMC6L, BIT6)
#define Iodd_RREG_MC_67                      TARG_ReadBit(PMC6L, BIT7)
#define Iodd_RREG_MC_68                      TARG_ReadBit(PMC6H, BIT0)
#define Iodd_RREG_MC_69                      /* read access defined but should not be used */
#define Iodd_RREG_MC_610                     TARG_ReadBit(PMC6H, BIT2)
#define Iodd_RREG_MC_611                     TARG_ReadBit(PMC6H, BIT3)
#define Iodd_RREG_MC_612                     TARG_ReadBit(PMC6H, BIT4)
#define Iodd_RREG_MC_613                     TARG_ReadBit(PMC6H, BIT5)
#define Iodd_RREG_MC_614                     /* read access defined but should not be used */
#define Iodd_RREG_MC_615                     /* read access defined but should not be used */

#define Iodd_WREG_MC_60(Value)               TARG_WriteBit(PMC6L, BIT0, Value)
#define Iodd_WREG_MC_61(Value)               TARG_WriteBit(PMC6L, BIT1, Value)
#define Iodd_WREG_MC_62(Value)               TARG_WriteBit(PMC6L, BIT2, Value)
#define Iodd_WREG_MC_63(Value)               TARG_WriteBit(PMC6L, BIT3, Value)
#define Iodd_WREG_MC_64(Value)               TARG_WriteBit(PMC6L, BIT4, Value)
#define Iodd_WREG_MC_65(Value)               TARG_WriteBit(PMC6L, BIT5, Value)
#define Iodd_WREG_MC_66(Value)               TARG_WriteBit(PMC6L, BIT6, Value)
#define Iodd_WREG_MC_67(Value)               TARG_WriteBit(PMC6L, BIT7, Value)
#define Iodd_WREG_MC_68(Value)               TARG_WriteBit(PMC6H, BIT0, Value)
#define Iodd_WREG_MC_69(Value)               /* write access not defined */
#define Iodd_WREG_MC_610(Value)              TARG_WriteBit(PMC6H, BIT2, Value)
#define Iodd_WREG_MC_611(Value)              TARG_WriteBit(PMC6H, BIT3, Value)
#define Iodd_WREG_MC_612(Value)              TARG_WriteBit(PMC6H, BIT4, Value)
#define Iodd_WREG_MC_613(Value)              TARG_WriteBit(PMC6H, BIT5, Value)
#define Iodd_WREG_MC_614(Value)              /* write access not defined */
#define Iodd_WREG_MC_615(Value)              /* write access not defined */

#endif

#if                                          \
      defined(__NEC_V850_FK3_F3383__)||      \
      defined(__NEC_V850_FK3_F3384__)||      \
      defined(__NEC_V850_FK3_F3385__)

#define Iodd_RREG_MC_60                      TARG_ReadBit(PMC6L, BIT0)
#define Iodd_RREG_MC_61                      TARG_ReadBit(PMC6L, BIT1)
#define Iodd_RREG_MC_62                      TARG_ReadBit(PMC6L, BIT2)
#define Iodd_RREG_MC_63                      TARG_ReadBit(PMC6L, BIT3)
#define Iodd_RREG_MC_64                      TARG_ReadBit(PMC6L, BIT4)
#define Iodd_RREG_MC_65                      TARG_ReadBit(PMC6L, BIT5)
#define Iodd_RREG_MC_66                      TARG_ReadBit(PMC6L, BIT6)
#define Iodd_RREG_MC_67                      TARG_ReadBit(PMC6L, BIT7)
#define Iodd_RREG_MC_68                      TARG_ReadBit(PMC6H, BIT0)
#define Iodd_RREG_MC_69                      TARG_ReadBit(PMC6H, BIT1)
#define Iodd_RREG_MC_610                     TARG_ReadBit(PMC6H, BIT2)
#define Iodd_RREG_MC_611                     TARG_ReadBit(PMC6H, BIT3)
#define Iodd_RREG_MC_612                     TARG_ReadBit(PMC6H, BIT4)
#define Iodd_RREG_MC_613                     TARG_ReadBit(PMC6H, BIT5)
#define Iodd_RREG_MC_614                     TARG_ReadBit(PMC6H, BIT6)
#define Iodd_RREG_MC_615                     TARG_ReadBit(PMC6H, BIT7)

#define Iodd_WREG_MC_60(Value)               TARG_WriteBit(PMC6L, BIT0, Value)
#define Iodd_WREG_MC_61(Value)               TARG_WriteBit(PMC6L, BIT1, Value)
#define Iodd_WREG_MC_62(Value)               TARG_WriteBit(PMC6L, BIT2, Value)
#define Iodd_WREG_MC_63(Value)               TARG_WriteBit(PMC6L, BIT3, Value)
#define Iodd_WREG_MC_64(Value)               TARG_WriteBit(PMC6L, BIT4, Value)
#define Iodd_WREG_MC_65(Value)               TARG_WriteBit(PMC6L, BIT5, Value)
#define Iodd_WREG_MC_66(Value)               TARG_WriteBit(PMC6L, BIT6, Value)
#define Iodd_WREG_MC_67(Value)               TARG_WriteBit(PMC6L, BIT7, Value)
#define Iodd_WREG_MC_68(Value)               TARG_WriteBit(PMC6H, BIT0, Value)
#define Iodd_WREG_MC_69(Value)               TARG_WriteBit(PMC6H, BIT1, Value)
#define Iodd_WREG_MC_610(Value)              TARG_WriteBit(PMC6H, BIT2, Value)
#define Iodd_WREG_MC_611(Value)              TARG_WriteBit(PMC6H, BIT3, Value)
#define Iodd_WREG_MC_612(Value)              TARG_WriteBit(PMC6H, BIT4, Value)
#define Iodd_WREG_MC_613(Value)              TARG_WriteBit(PMC6H, BIT5, Value)
#define Iodd_WREG_MC_614(Value)              TARG_WriteBit(PMC6H, BIT6, Value)
#define Iodd_WREG_MC_615(Value)              TARG_WriteBit(PMC6H, BIT7, Value)

#endif

#if                                          \
      defined(__NEC_V850_FJ3_F3378__)

#define Iodd_RREG_FC_60                      TARG_ReadBit(PFC6L, BIT0)
#define Iodd_RREG_FC_61                      TARG_ReadBit(PFC6L, BIT1)
#define Iodd_RREG_FC_62                      TARG_ReadBit(PFC6L, BIT2)
#define Iodd_RREG_FC_63                      /* read access defined but should not be used */
#define Iodd_RREG_FC_64                      /* read access defined but should not be used */
#define Iodd_RREG_FC_65                      TARG_ReadBit(PFC6L, BIT5)
#define Iodd_RREG_FC_66                      TARG_ReadBit(PFC6L, BIT6)
#define Iodd_RREG_FC_67                      /* read access defined but should not be used */
#define Iodd_RREG_FC_68                      /* read access defined but should not be used */
#define Iodd_RREG_FC_69                      /* read access defined but should not be used */
#define Iodd_RREG_FC_610                     TARG_ReadBit(PFC6H, BIT2)
#define Iodd_RREG_FC_611                     TARG_ReadBit(PFC6H, BIT3)
#define Iodd_RREG_FC_612                     TARG_ReadBit(PFC6H, BIT4)
#define Iodd_RREG_FC_613                     TARG_ReadBit(PFC6H, BIT5)
#define Iodd_RREG_FC_614                     /* read access defined but should not be used */
#define Iodd_RREG_FC_615                     /* read access defined but should not be used */

#define Iodd_WREG_FC_60(Value)               TARG_WriteBit(PFC6L, BIT0, Value)
#define Iodd_WREG_FC_61(Value)               TARG_WriteBit(PFC6L, BIT1, Value)
#define Iodd_WREG_FC_62(Value)               TARG_WriteBit(PFC6L, BIT2, Value)
#define Iodd_WREG_FC_63(Value)               /* write access not defined */
#define Iodd_WREG_FC_64(Value)               /* write access not defined */
#define Iodd_WREG_FC_65(Value)               TARG_WriteBit(PFC6L, BIT5, Value)
#define Iodd_WREG_FC_66(Value)               TARG_WriteBit(PFC6L, BIT6, Value)
#define Iodd_WREG_FC_67(Value)               /* write access not defined */
#define Iodd_WREG_FC_68(Value)               /* write access not defined */
#define Iodd_WREG_FC_69(Value)               /* write access not defined */
#define Iodd_WREG_FC_610(Value)              TARG_WriteBit(PFC6H, BIT2, Value)
#define Iodd_WREG_FC_611(Value)              TARG_WriteBit(PFC6H, BIT3, Value)
#define Iodd_WREG_FC_612(Value)              TARG_WriteBit(PFC6H, BIT4, Value)
#define Iodd_WREG_FC_613(Value)              TARG_WriteBit(PFC6H, BIT5, Value)
#define Iodd_WREG_FC_614(Value)              /* write access not defined */
#define Iodd_WREG_FC_615(Value)              /* write access not defined */

#endif

#if                                          \
      defined(__NEC_V850_FJ3_F3379__)||      \
      defined(__NEC_V850_FJ3_F3380__)

#define Iodd_RREG_FC_60                      TARG_ReadBit(PFC6L, BIT0)
#define Iodd_RREG_FC_61                      TARG_ReadBit(PFC6L, BIT1)
#define Iodd_RREG_FC_62                      TARG_ReadBit(PFC6L, BIT2)
#define Iodd_RREG_FC_63                      /* read access defined but should not be used */
#define Iodd_RREG_FC_64                      /* read access defined but should not be used */
#define Iodd_RREG_FC_65                      TARG_ReadBit(PFC6L, BIT5)
#define Iodd_RREG_FC_66                      TARG_ReadBit(PFC6L, BIT6)
#define Iodd_RREG_FC_67                      TARG_ReadBit(PFC6L, BIT7)
#define Iodd_RREG_FC_68                      TARG_ReadBit(PFC6H, BIT0)
#define Iodd_RREG_FC_69                      /* read access defined but should not be used */
#define Iodd_RREG_FC_610                     TARG_ReadBit(PFC6H, BIT2)
#define Iodd_RREG_FC_611                     TARG_ReadBit(PFC6H, BIT3)
#define Iodd_RREG_FC_612                     TARG_ReadBit(PFC6H, BIT4)
#define Iodd_RREG_FC_613                     TARG_ReadBit(PFC6H, BIT5)
#define Iodd_RREG_FC_614                     /* read access defined but should not be used */
#define Iodd_RREG_FC_615                     /* read access defined but should not be used */

#define Iodd_WREG_FC_60(Value)               TARG_WriteBit(PFC6L, BIT0, Value)
#define Iodd_WREG_FC_61(Value)               TARG_WriteBit(PFC6L, BIT1, Value)
#define Iodd_WREG_FC_62(Value)               TARG_WriteBit(PFC6L, BIT2, Value)
#define Iodd_WREG_FC_63(Value)               /* write access not defined */
#define Iodd_WREG_FC_64(Value)               /* write access not defined */
#define Iodd_WREG_FC_65(Value)               TARG_WriteBit(PFC6L, BIT5, Value)
#define Iodd_WREG_FC_66(Value)               TARG_WriteBit(PFC6L, BIT6, Value)
#define Iodd_WREG_FC_67(Value)               TARG_WriteBit(PFC6L, BIT7, Value)
#define Iodd_WREG_FC_68(Value)               TARG_WriteBit(PFC6H, BIT0, Value)
#define Iodd_WREG_FC_69(Value)               /* write access not defined */
#define Iodd_WREG_FC_610(Value)              TARG_WriteBit(PFC6H, BIT2, Value)
#define Iodd_WREG_FC_611(Value)              TARG_WriteBit(PFC6H, BIT3, Value)
#define Iodd_WREG_FC_612(Value)              TARG_WriteBit(PFC6H, BIT4, Value)
#define Iodd_WREG_FC_613(Value)              TARG_WriteBit(PFC6H, BIT5, Value)
#define Iodd_WREG_FC_614(Value)              /* write access not defined */
#define Iodd_WREG_FC_615(Value)              /* write access not defined */

#endif

#if                                          \
      defined(__NEC_V850_FJ3_F3381__)||      \
      defined(__NEC_V850_FJ3_F3382__)||      \
      defined(__NEC_V850_FK3_F3383__)||      \
      defined(__NEC_V850_FK3_F3384__)||      \
      defined(__NEC_V850_FK3_F3385__)

#define Iodd_RREG_FC_60                      TARG_ReadBit(PFC6L, BIT0)
#define Iodd_RREG_FC_61                      TARG_ReadBit(PFC6L, BIT1)
#define Iodd_RREG_FC_62                      TARG_ReadBit(PFC6L, BIT2)
#define Iodd_RREG_FC_63                      TARG_ReadBit(PFC6L, BIT3)
#define Iodd_RREG_FC_64                      TARG_ReadBit(PFC6L, BIT4)
#define Iodd_RREG_FC_65                      TARG_ReadBit(PFC6L, BIT5)
#define Iodd_RREG_FC_66                      TARG_ReadBit(PFC6L, BIT6)
#define Iodd_RREG_FC_67                      TARG_ReadBit(PFC6L, BIT7)
#define Iodd_RREG_FC_68                      TARG_ReadBit(PFC6H, BIT0)
#define Iodd_RREG_FC_69                      /* read access defined but should not be used */
#define Iodd_RREG_FC_610                     TARG_ReadBit(PFC6H, BIT2)
#define Iodd_RREG_FC_611                     TARG_ReadBit(PFC6H, BIT3)
#define Iodd_RREG_FC_612                     TARG_ReadBit(PFC6H, BIT4)
#define Iodd_RREG_FC_613                     TARG_ReadBit(PFC6H, BIT5)
#define Iodd_RREG_FC_614                     /* read access defined but should not be used */
#define Iodd_RREG_FC_615                     /* read access defined but should not be used */

#define Iodd_WREG_FC_60(Value)               TARG_WriteBit(PFC6L, BIT0, Value)
#define Iodd_WREG_FC_61(Value)               TARG_WriteBit(PFC6L, BIT1, Value)
#define Iodd_WREG_FC_62(Value)               TARG_WriteBit(PFC6L, BIT2, Value)
#define Iodd_WREG_FC_63(Value)               TARG_WriteBit(PFC6L, BIT3, Value)
#define Iodd_WREG_FC_64(Value)               TARG_WriteBit(PFC6L, BIT4, Value)
#define Iodd_WREG_FC_65(Value)               TARG_WriteBit(PFC6L, BIT5, Value)
#define Iodd_WREG_FC_66(Value)               TARG_WriteBit(PFC6L, BIT6, Value)
#define Iodd_WREG_FC_67(Value)               TARG_WriteBit(PFC6L, BIT7, Value)
#define Iodd_WREG_FC_68(Value)               TARG_WriteBit(PFC6H, BIT0, Value)
#define Iodd_WREG_FC_69(Value)               /* write access not defined */
#define Iodd_WREG_FC_610(Value)              TARG_WriteBit(PFC6H, BIT2, Value)
#define Iodd_WREG_FC_611(Value)              TARG_WriteBit(PFC6H, BIT3, Value)
#define Iodd_WREG_FC_612(Value)              TARG_WriteBit(PFC6H, BIT4, Value)
#define Iodd_WREG_FC_613(Value)              TARG_WriteBit(PFC6H, BIT5, Value)
#define Iodd_WREG_FC_614(Value)              /* write access not defined */
#define Iodd_WREG_FC_615(Value)              /* write access not defined */

#endif

#if                                          \
      defined(__NEC_V850_FJ3_F3381__)||      \
      defined(__NEC_V850_FJ3_F3382__)||      \
      defined(__NEC_V850_FK3_F3383__)||      \
      defined(__NEC_V850_FK3_F3384__)||      \
      defined(__NEC_V850_FK3_F3385__)

#define Iodd_RREG_FCE_60                     /* read access defined but should not be used */
#define Iodd_RREG_FCE_61                     /* read access defined but should not be used */
#define Iodd_RREG_FCE_62                     TARG_ReadBit(PFCE6L, BIT2)
#define Iodd_RREG_FCE_63                     TARG_ReadBit(PFCE6L, BIT3)
#define Iodd_RREG_FCE_64                     TARG_ReadBit(PFCE6L, BIT4)
#define Iodd_RREG_FCE_65                     /* read access defined but should not be used */
#define Iodd_RREG_FCE_66                     /* read access defined but should not be used */
#define Iodd_RREG_FCE_67                     /* read access defined but should not be used */

#define Iodd_WREG_FCE_60(Value)              /* write access not defined */
#define Iodd_WREG_FCE_61(Value)              /* write access not defined */
#define Iodd_WREG_FCE_62(Value)              TARG_WriteBit(PFCE6L, BIT2, Value)
#define Iodd_WREG_FCE_63(Value)              TARG_WriteBit(PFCE6L, BIT3, Value)
#define Iodd_WREG_FCE_64(Value)              TARG_WriteBit(PFCE6L, BIT4, Value)
#define Iodd_WREG_FCE_65(Value)              /* write access not defined */
#define Iodd_WREG_FCE_66(Value)              /* write access not defined */
#define Iodd_WREG_FCE_67(Value)              /* write access not defined */

#endif

#if                                          \
      defined(__NEC_V850_FJ3_F3378__)||      \
      defined(__NEC_V850_FJ3_F3379__)||      \
      defined(__NEC_V850_FJ3_F3380__)||      \
      defined(__NEC_V850_FJ3_F3381__)||      \
      defined(__NEC_V850_FJ3_F3382__)||      \
      defined(__NEC_V850_FK3_F3383__)||      \
      defined(__NEC_V850_FK3_F3384__)||      \
      defined(__NEC_V850_FK3_F3385__)

#define Iodd_RREG_PU_60                      TARG_ReadBit(PU6L, BIT0)
#define Iodd_RREG_PU_61                      TARG_ReadBit(PU6L, BIT1)
#define Iodd_RREG_PU_62                      TARG_ReadBit(PU6L, BIT2)
#define Iodd_RREG_PU_63                      TARG_ReadBit(PU6L, BIT3)
#define Iodd_RREG_PU_64                      TARG_ReadBit(PU6L, BIT4)
#define Iodd_RREG_PU_65                      TARG_ReadBit(PU6L, BIT5)
#define Iodd_RREG_PU_66                      TARG_ReadBit(PU6L, BIT6)
#define Iodd_RREG_PU_67                      TARG_ReadBit(PU6L, BIT7)
#define Iodd_RREG_PU_68                      TARG_ReadBit(PU6H, BIT0)
#define Iodd_RREG_PU_69                      TARG_ReadBit(PU6H, BIT1)
#define Iodd_RREG_PU_610                     TARG_ReadBit(PU6H, BIT2)
#define Iodd_RREG_PU_611                     TARG_ReadBit(PU6H, BIT3)
#define Iodd_RREG_PU_612                     TARG_ReadBit(PU6H, BIT4)
#define Iodd_RREG_PU_613                     TARG_ReadBit(PU6H, BIT5)
#define Iodd_RREG_PU_614                     TARG_ReadBit(PU6H, BIT6)
#define Iodd_RREG_PU_615                     TARG_ReadBit(PU6H, BIT7)

#define Iodd_WREG_PU_60(Value)               TARG_WriteBit(PU6L, BIT0, Value)
#define Iodd_WREG_PU_61(Value)               TARG_WriteBit(PU6L, BIT1, Value)
#define Iodd_WREG_PU_62(Value)               TARG_WriteBit(PU6L, BIT2, Value)
#define Iodd_WREG_PU_63(Value)               TARG_WriteBit(PU6L, BIT3, Value)
#define Iodd_WREG_PU_64(Value)               TARG_WriteBit(PU6L, BIT4, Value)
#define Iodd_WREG_PU_65(Value)               TARG_WriteBit(PU6L, BIT5, Value)
#define Iodd_WREG_PU_66(Value)               TARG_WriteBit(PU6L, BIT6, Value)
#define Iodd_WREG_PU_67(Value)               TARG_WriteBit(PU6L, BIT7, Value)
#define Iodd_WREG_PU_68(Value)               TARG_WriteBit(PU6H, BIT0, Value)
#define Iodd_WREG_PU_69(Value)               TARG_WriteBit(PU6H, BIT1, Value)
#define Iodd_WREG_PU_610(Value)              TARG_WriteBit(PU6H, BIT2, Value)
#define Iodd_WREG_PU_611(Value)              TARG_WriteBit(PU6H, BIT3, Value)
#define Iodd_WREG_PU_612(Value)              TARG_WriteBit(PU6H, BIT4, Value)
#define Iodd_WREG_PU_613(Value)              TARG_WriteBit(PU6H, BIT5, Value)
#define Iodd_WREG_PU_614(Value)              TARG_WriteBit(PU6H, BIT6, Value)
#define Iodd_WREG_PU_615(Value)              TARG_WriteBit(PU6H, BIT7, Value)

#endif

#if                                          \
      defined(__NEC_V850_FE3_F3370__)||      \
      defined(__NEC_V850_FE3_F3371__)||      \
      defined(__NEC_V850_FF3_F3372__)||      \
      defined(__NEC_V850_FF3_F3373__)||      \
      defined(__NEC_V850_FG3_F3374__)||      \
      defined(__NEC_V850_FG3_F3375__)||      \
      defined(__NEC_V850_FG3_F3376__)||      \
      defined(__NEC_V850_FG3_F3377__)||      \
      defined(__NEC_V850_FF3L_F3618__)

#define Iodd_RREG_P_60                       /* register undefined */
#define Iodd_RREG_P_61                       /* register undefined */
#define Iodd_RREG_P_62                       /* register undefined */
#define Iodd_RREG_P_63                       /* register undefined */
#define Iodd_RREG_P_64                       /* register undefined */
#define Iodd_RREG_P_65                       /* register undefined */
#define Iodd_RREG_P_66                       /* register undefined */
#define Iodd_RREG_P_67                       /* register undefined */

#define Iodd_WREG_P_60(Value)                /* register undefined */
#define Iodd_WREG_P_61(Value)                /* register undefined */
#define Iodd_WREG_P_62(Value)                /* register undefined */
#define Iodd_WREG_P_63(Value)                /* register undefined */
#define Iodd_WREG_P_64(Value)                /* register undefined */
#define Iodd_WREG_P_65(Value)                /* register undefined */
#define Iodd_WREG_P_66(Value)                /* register undefined */
#define Iodd_WREG_P_67(Value)                /* register undefined */

#endif

#if                                          \
      defined(__NEC_V850_FE3_F3370__)||      \
      defined(__NEC_V850_FE3_F3371__)||      \
      defined(__NEC_V850_FF3_F3372__)||      \
      defined(__NEC_V850_FF3_F3373__)||      \
      defined(__NEC_V850_FG3_F3374__)||      \
      defined(__NEC_V850_FG3_F3375__)||      \
      defined(__NEC_V850_FG3_F3376__)||      \
      defined(__NEC_V850_FG3_F3377__)||      \
      defined(__NEC_V850_FF3L_F3618__)

#define Iodd_RREG_P_68                       /* register undefined */
#define Iodd_RREG_P_69                       /* register undefined */
#define Iodd_RREG_P_610                      /* register undefined */
#define Iodd_RREG_P_611                      /* register undefined */
#define Iodd_RREG_P_612                      /* register undefined */
#define Iodd_RREG_P_613                      /* register undefined */
#define Iodd_RREG_P_614                      /* register undefined */
#define Iodd_RREG_P_615                      /* register undefined */

#define Iodd_WREG_P_68(Value)                /* register undefined */
#define Iodd_WREG_P_69(Value)                /* register undefined */
#define Iodd_WREG_P_610(Value)               /* register undefined */
#define Iodd_WREG_P_611(Value)               /* register undefined */
#define Iodd_WREG_P_612(Value)               /* register undefined */
#define Iodd_WREG_P_613(Value)               /* register undefined */
#define Iodd_WREG_P_614(Value)               /* register undefined */
#define Iodd_WREG_P_615(Value)               /* register undefined */

#endif

#if                                          \
      defined(__NEC_V850_FE3_F3370__)||      \
      defined(__NEC_V850_FE3_F3371__)||      \
      defined(__NEC_V850_FF3_F3372__)||      \
      defined(__NEC_V850_FF3_F3373__)||      \
      defined(__NEC_V850_FG3_F3374__)||      \
      defined(__NEC_V850_FG3_F3375__)||      \
      defined(__NEC_V850_FG3_F3376__)||      \
      defined(__NEC_V850_FG3_F3377__)||      \
      defined(__NEC_V850_FF3L_F3618__)

#define Iodd_RREG_M_60                       /* register undefined */
#define Iodd_RREG_M_61                       /* register undefined */
#define Iodd_RREG_M_62                       /* register undefined */
#define Iodd_RREG_M_63                       /* register undefined */
#define Iodd_RREG_M_64                       /* register undefined */
#define Iodd_RREG_M_65                       /* register undefined */
#define Iodd_RREG_M_66                       /* register undefined */
#define Iodd_RREG_M_67                       /* register undefined */

#define Iodd_WREG_M_60(Value)                /* register undefined */
#define Iodd_WREG_M_61(Value)                /* register undefined */
#define Iodd_WREG_M_62(Value)                /* register undefined */
#define Iodd_WREG_M_63(Value)                /* register undefined */
#define Iodd_WREG_M_64(Value)                /* register undefined */
#define Iodd_WREG_M_65(Value)                /* register undefined */
#define Iodd_WREG_M_66(Value)                /* register undefined */
#define Iodd_WREG_M_67(Value)                /* register undefined */

#endif

#if                                          \
      defined(__NEC_V850_FE3_F3370__)||      \
      defined(__NEC_V850_FE3_F3371__)||      \
      defined(__NEC_V850_FF3_F3372__)||      \
      defined(__NEC_V850_FF3_F3373__)||      \
      defined(__NEC_V850_FG3_F3374__)||      \
      defined(__NEC_V850_FG3_F3375__)||      \
      defined(__NEC_V850_FG3_F3376__)||      \
      defined(__NEC_V850_FG3_F3377__)||      \
      defined(__NEC_V850_FF3L_F3618__)

#define Iodd_RREG_M_68                       /* register undefined */
#define Iodd_RREG_M_69                       /* register undefined */
#define Iodd_RREG_M_610                      /* register undefined */
#define Iodd_RREG_M_611                      /* register undefined */
#define Iodd_RREG_M_612                      /* register undefined */
#define Iodd_RREG_M_613                      /* register undefined */
#define Iodd_RREG_M_614                      /* register undefined */
#define Iodd_RREG_M_615                      /* register undefined */

#define Iodd_WREG_M_68(Value)                /* register undefined */
#define Iodd_WREG_M_69(Value)                /* register undefined */
#define Iodd_WREG_M_610(Value)               /* register undefined */
#define Iodd_WREG_M_611(Value)               /* register undefined */
#define Iodd_WREG_M_612(Value)               /* register undefined */
#define Iodd_WREG_M_613(Value)               /* register undefined */
#define Iodd_WREG_M_614(Value)               /* register undefined */
#define Iodd_WREG_M_615(Value)               /* register undefined */

#endif

#if                                          \
      defined(__NEC_V850_FE3_F3370__)||      \
      defined(__NEC_V850_FE3_F3371__)||      \
      defined(__NEC_V850_FF3_F3372__)||      \
      defined(__NEC_V850_FF3_F3373__)||      \
      defined(__NEC_V850_FG3_F3374__)||      \
      defined(__NEC_V850_FG3_F3375__)||      \
      defined(__NEC_V850_FG3_F3376__)||      \
      defined(__NEC_V850_FG3_F3377__)||      \
      defined(__NEC_V850_FF3L_F3618__)

#define Iodd_RREG_MC_60                      /* register undefined */
#define Iodd_RREG_MC_61                      /* register undefined */
#define Iodd_RREG_MC_62                      /* register undefined */
#define Iodd_RREG_MC_63                      /* register undefined */
#define Iodd_RREG_MC_64                      /* register undefined */
#define Iodd_RREG_MC_65                      /* register undefined */
#define Iodd_RREG_MC_66                      /* register undefined */
#define Iodd_RREG_MC_67                      /* register undefined */

#define Iodd_WREG_MC_60(Value)               /* register undefined */
#define Iodd_WREG_MC_61(Value)               /* register undefined */
#define Iodd_WREG_MC_62(Value)               /* register undefined */
#define Iodd_WREG_MC_63(Value)               /* register undefined */
#define Iodd_WREG_MC_64(Value)               /* register undefined */
#define Iodd_WREG_MC_65(Value)               /* register undefined */
#define Iodd_WREG_MC_66(Value)               /* register undefined */
#define Iodd_WREG_MC_67(Value)               /* register undefined */

#endif

#if                                          \
      defined(__NEC_V850_FE3_F3370__)||      \
      defined(__NEC_V850_FE3_F3371__)||      \
      defined(__NEC_V850_FF3_F3372__)||      \
      defined(__NEC_V850_FF3_F3373__)||      \
      defined(__NEC_V850_FG3_F3374__)||      \
      defined(__NEC_V850_FG3_F3375__)||      \
      defined(__NEC_V850_FG3_F3376__)||      \
      defined(__NEC_V850_FG3_F3377__)||      \
      defined(__NEC_V850_FF3L_F3618__)

#define Iodd_RREG_MC_68                      /* register undefined */
#define Iodd_RREG_MC_69                      /* register undefined */
#define Iodd_RREG_MC_610                     /* register undefined */
#define Iodd_RREG_MC_611                     /* register undefined */
#define Iodd_RREG_MC_612                     /* register undefined */
#define Iodd_RREG_MC_613                     /* register undefined */
#define Iodd_RREG_MC_614                     /* register undefined */
#define Iodd_RREG_MC_615                     /* register undefined */

#define Iodd_WREG_MC_68(Value)               /* register undefined */
#define Iodd_WREG_MC_69(Value)               /* register undefined */
#define Iodd_WREG_MC_610(Value)              /* register undefined */
#define Iodd_WREG_MC_611(Value)              /* register undefined */
#define Iodd_WREG_MC_612(Value)              /* register undefined */
#define Iodd_WREG_MC_613(Value)              /* register undefined */
#define Iodd_WREG_MC_614(Value)              /* register undefined */
#define Iodd_WREG_MC_615(Value)              /* register undefined */

#endif

#if                                          \
      defined(__NEC_V850_FE3_F3370__)||      \
      defined(__NEC_V850_FE3_F3371__)||      \
      defined(__NEC_V850_FF3_F3372__)||      \
      defined(__NEC_V850_FF3_F3373__)||      \
      defined(__NEC_V850_FG3_F3374__)||      \
      defined(__NEC_V850_FG3_F3375__)||      \
      defined(__NEC_V850_FG3_F3376__)||      \
      defined(__NEC_V850_FG3_F3377__)||      \
      defined(__NEC_V850_FF3L_F3618__)

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

#endif

#if                                          \
      defined(__NEC_V850_FE3_F3370__)||      \
      defined(__NEC_V850_FE3_F3371__)||      \
      defined(__NEC_V850_FF3_F3372__)||      \
      defined(__NEC_V850_FF3_F3373__)||      \
      defined(__NEC_V850_FG3_F3374__)||      \
      defined(__NEC_V850_FG3_F3375__)||      \
      defined(__NEC_V850_FG3_F3376__)||      \
      defined(__NEC_V850_FG3_F3377__)||      \
      defined(__NEC_V850_FF3L_F3618__)

#define Iodd_RREG_FC_68                      /* register undefined */
#define Iodd_RREG_FC_69                      /* register undefined */
#define Iodd_RREG_FC_610                     /* register undefined */
#define Iodd_RREG_FC_611                     /* register undefined */
#define Iodd_RREG_FC_612                     /* register undefined */
#define Iodd_RREG_FC_613                     /* register undefined */
#define Iodd_RREG_FC_614                     /* register undefined */
#define Iodd_RREG_FC_615                     /* register undefined */

#define Iodd_WREG_FC_68(Value)               /* register undefined */
#define Iodd_WREG_FC_69(Value)               /* register undefined */
#define Iodd_WREG_FC_610(Value)              /* register undefined */
#define Iodd_WREG_FC_611(Value)              /* register undefined */
#define Iodd_WREG_FC_612(Value)              /* register undefined */
#define Iodd_WREG_FC_613(Value)              /* register undefined */
#define Iodd_WREG_FC_614(Value)              /* register undefined */
#define Iodd_WREG_FC_615(Value)              /* register undefined */

#endif

#if                                          \
      defined(__NEC_V850_FE3_F3370__)||      \
      defined(__NEC_V850_FE3_F3371__)||      \
      defined(__NEC_V850_FF3_F3372__)||      \
      defined(__NEC_V850_FF3_F3373__)||      \
      defined(__NEC_V850_FG3_F3374__)||      \
      defined(__NEC_V850_FG3_F3375__)||      \
      defined(__NEC_V850_FG3_F3376__)||      \
      defined(__NEC_V850_FG3_F3377__)||      \
      defined(__NEC_V850_FJ3_F3378__)||      \
      defined(__NEC_V850_FJ3_F3379__)||      \
      defined(__NEC_V850_FJ3_F3380__)||      \
      defined(__NEC_V850_FF3L_F3618__)

#define Iodd_RREG_FCE_60                     /* register undefined */
#define Iodd_RREG_FCE_61                     /* register undefined */
#define Iodd_RREG_FCE_62                     /* register undefined */
#define Iodd_RREG_FCE_63                     /* register undefined */
#define Iodd_RREG_FCE_64                     /* register undefined */
#define Iodd_RREG_FCE_65                     /* register undefined */
#define Iodd_RREG_FCE_66                     /* register undefined */
#define Iodd_RREG_FCE_67                     /* register undefined */

#define Iodd_WREG_FCE_60(Value)              /* register undefined */
#define Iodd_WREG_FCE_61(Value)              /* register undefined */
#define Iodd_WREG_FCE_62(Value)              /* register undefined */
#define Iodd_WREG_FCE_63(Value)              /* register undefined */
#define Iodd_WREG_FCE_64(Value)              /* register undefined */
#define Iodd_WREG_FCE_65(Value)              /* register undefined */
#define Iodd_WREG_FCE_66(Value)              /* register undefined */
#define Iodd_WREG_FCE_67(Value)              /* register undefined */

#endif

#if                                          \
      defined(__NEC_V850_FE3_F3370__)||      \
      defined(__NEC_V850_FE3_F3371__)||      \
      defined(__NEC_V850_FF3_F3372__)||      \
      defined(__NEC_V850_FF3_F3373__)||      \
      defined(__NEC_V850_FG3_F3374__)||      \
      defined(__NEC_V850_FG3_F3375__)||      \
      defined(__NEC_V850_FG3_F3376__)||      \
      defined(__NEC_V850_FG3_F3377__)||      \
      defined(__NEC_V850_FJ3_F3378__)||      \
      defined(__NEC_V850_FJ3_F3379__)||      \
      defined(__NEC_V850_FJ3_F3380__)||      \
      defined(__NEC_V850_FJ3_F3381__)||      \
      defined(__NEC_V850_FJ3_F3382__)||      \
      defined(__NEC_V850_FK3_F3383__)||      \
      defined(__NEC_V850_FK3_F3384__)||      \
      defined(__NEC_V850_FK3_F3385__)||      \
      defined(__NEC_V850_FF3L_F3618__)

#define Iodd_RREG_FCE_68                     /* register undefined */
#define Iodd_RREG_FCE_69                     /* register undefined */
#define Iodd_RREG_FCE_610                    /* register undefined */
#define Iodd_RREG_FCE_611                    /* register undefined */
#define Iodd_RREG_FCE_612                    /* register undefined */
#define Iodd_RREG_FCE_613                    /* register undefined */
#define Iodd_RREG_FCE_614                    /* register undefined */
#define Iodd_RREG_FCE_615                    /* register undefined */

#define Iodd_WREG_FCE_68(Value)              /* register undefined */
#define Iodd_WREG_FCE_69(Value)              /* register undefined */
#define Iodd_WREG_FCE_610(Value)             /* register undefined */
#define Iodd_WREG_FCE_611(Value)             /* register undefined */
#define Iodd_WREG_FCE_612(Value)             /* register undefined */
#define Iodd_WREG_FCE_613(Value)             /* register undefined */
#define Iodd_WREG_FCE_614(Value)             /* register undefined */
#define Iodd_WREG_FCE_615(Value)             /* register undefined */

#endif

#if                                          \
      defined(__NEC_V850_FE3_F3370__)||      \
      defined(__NEC_V850_FE3_F3371__)||      \
      defined(__NEC_V850_FF3_F3372__)||      \
      defined(__NEC_V850_FF3_F3373__)||      \
      defined(__NEC_V850_FG3_F3374__)||      \
      defined(__NEC_V850_FG3_F3375__)||      \
      defined(__NEC_V850_FG3_F3376__)||      \
      defined(__NEC_V850_FG3_F3377__)||      \
      defined(__NEC_V850_FF3L_F3618__)

#define Iodd_RREG_PU_60                      /* register undefined */
#define Iodd_RREG_PU_61                      /* register undefined */
#define Iodd_RREG_PU_62                      /* register undefined */
#define Iodd_RREG_PU_63                      /* register undefined */
#define Iodd_RREG_PU_64                      /* register undefined */
#define Iodd_RREG_PU_65                      /* register undefined */
#define Iodd_RREG_PU_66                      /* register undefined */
#define Iodd_RREG_PU_67                      /* register undefined */

#define Iodd_WREG_PU_60(Value)               /* register undefined */
#define Iodd_WREG_PU_61(Value)               /* register undefined */
#define Iodd_WREG_PU_62(Value)               /* register undefined */
#define Iodd_WREG_PU_63(Value)               /* register undefined */
#define Iodd_WREG_PU_64(Value)               /* register undefined */
#define Iodd_WREG_PU_65(Value)               /* register undefined */
#define Iodd_WREG_PU_66(Value)               /* register undefined */
#define Iodd_WREG_PU_67(Value)               /* register undefined */

#endif

#if                                          \
      defined(__NEC_V850_FE3_F3370__)||      \
      defined(__NEC_V850_FE3_F3371__)||      \
      defined(__NEC_V850_FF3_F3372__)||      \
      defined(__NEC_V850_FF3_F3373__)||      \
      defined(__NEC_V850_FG3_F3374__)||      \
      defined(__NEC_V850_FG3_F3375__)||      \
      defined(__NEC_V850_FG3_F3376__)||      \
      defined(__NEC_V850_FG3_F3377__)||      \
      defined(__NEC_V850_FF3L_F3618__)

#define Iodd_RREG_PU_68                      /* register undefined */
#define Iodd_RREG_PU_69                      /* register undefined */
#define Iodd_RREG_PU_610                     /* register undefined */
#define Iodd_RREG_PU_611                     /* register undefined */
#define Iodd_RREG_PU_612                     /* register undefined */
#define Iodd_RREG_PU_613                     /* register undefined */
#define Iodd_RREG_PU_614                     /* register undefined */
#define Iodd_RREG_PU_615                     /* register undefined */

#define Iodd_WREG_PU_68(Value)               /* register undefined */
#define Iodd_WREG_PU_69(Value)               /* register undefined */
#define Iodd_WREG_PU_610(Value)              /* register undefined */
#define Iodd_WREG_PU_611(Value)              /* register undefined */
#define Iodd_WREG_PU_612(Value)              /* register undefined */
#define Iodd_WREG_PU_613(Value)              /* register undefined */
#define Iodd_WREG_PU_614(Value)              /* register undefined */
#define Iodd_WREG_PU_615(Value)              /* register undefined */

#endif

#if                                          \
      defined(__NEC_V850_Fx3__)

#define Iodd_RREG_PF_60                      /* register undefined */
#define Iodd_RREG_PF_61                      /* register undefined */
#define Iodd_RREG_PF_62                      /* register undefined */
#define Iodd_RREG_PF_63                      /* register undefined */
#define Iodd_RREG_PF_64                      /* register undefined */
#define Iodd_RREG_PF_65                      /* register undefined */
#define Iodd_RREG_PF_66                      /* register undefined */
#define Iodd_RREG_PF_67                      /* register undefined */
#define Iodd_RREG_PF_68                      /* register undefined */
#define Iodd_RREG_PF_69                      /* register undefined */
#define Iodd_RREG_PF_610                     /* register undefined */
#define Iodd_RREG_PF_611                     /* register undefined */
#define Iodd_RREG_PF_612                     /* register undefined */
#define Iodd_RREG_PF_613                     /* register undefined */
#define Iodd_RREG_PF_614                     /* register undefined */
#define Iodd_RREG_PF_615                     /* register undefined */

#define Iodd_WREG_PF_60(Value)               /* register undefined */
#define Iodd_WREG_PF_61(Value)               /* register undefined */
#define Iodd_WREG_PF_62(Value)               /* register undefined */
#define Iodd_WREG_PF_63(Value)               /* register undefined */
#define Iodd_WREG_PF_64(Value)               /* register undefined */
#define Iodd_WREG_PF_65(Value)               /* register undefined */
#define Iodd_WREG_PF_66(Value)               /* register undefined */
#define Iodd_WREG_PF_67(Value)               /* register undefined */
#define Iodd_WREG_PF_68(Value)               /* register undefined */
#define Iodd_WREG_PF_69(Value)               /* register undefined */
#define Iodd_WREG_PF_610(Value)              /* register undefined */
#define Iodd_WREG_PF_611(Value)              /* register undefined */
#define Iodd_WREG_PF_612(Value)              /* register undefined */
#define Iodd_WREG_PF_613(Value)              /* register undefined */
#define Iodd_WREG_PF_614(Value)              /* register undefined */
#define Iodd_WREG_PF_615(Value)              /* register undefined */

#endif

/* Definitions PORT 7 */

#if                                          \
      defined(__NEC_V850_Fx3__)

#define Iodd_RREG_P_70                       TARG_ReadBit(P7L, BIT0)
#define Iodd_RREG_P_71                       TARG_ReadBit(P7L, BIT1)
#define Iodd_RREG_P_72                       TARG_ReadBit(P7L, BIT2)
#define Iodd_RREG_P_73                       TARG_ReadBit(P7L, BIT3)
#define Iodd_RREG_P_74                       TARG_ReadBit(P7L, BIT4)
#define Iodd_RREG_P_75                       TARG_ReadBit(P7L, BIT5)
#define Iodd_RREG_P_76                       TARG_ReadBit(P7L, BIT6)
#define Iodd_RREG_P_77                       TARG_ReadBit(P7L, BIT7)

#define Iodd_WREG_P_70(Value)                TARG_WriteBit(P7L, BIT0, Value)
#define Iodd_WREG_P_71(Value)                TARG_WriteBit(P7L, BIT1, Value)
#define Iodd_WREG_P_72(Value)                TARG_WriteBit(P7L, BIT2, Value)
#define Iodd_WREG_P_73(Value)                TARG_WriteBit(P7L, BIT3, Value)
#define Iodd_WREG_P_74(Value)                TARG_WriteBit(P7L, BIT4, Value)
#define Iodd_WREG_P_75(Value)                TARG_WriteBit(P7L, BIT5, Value)
#define Iodd_WREG_P_76(Value)                TARG_WriteBit(P7L, BIT6, Value)
#define Iodd_WREG_P_77(Value)                TARG_WriteBit(P7L, BIT7, Value)

#endif

#if                                          \
      defined(__NEC_V850_FE3_F3370__)||      \
      defined(__NEC_V850_FE3_F3371__)

#define Iodd_RREG_P_78                       TARG_ReadBit(P7H, BIT0)
#define Iodd_RREG_P_79                       TARG_ReadBit(P7H, BIT1)
#define Iodd_RREG_P_710                      /* read access defined but should not be used */
#define Iodd_RREG_P_711                      /* read access defined but should not be used */
#define Iodd_RREG_P_712                      /* read access defined but should not be used */
#define Iodd_RREG_P_713                      /* read access defined but should not be used */
#define Iodd_RREG_P_714                      /* read access defined but should not be used */
#define Iodd_RREG_P_715                      /* read access defined but should not be used */

#define Iodd_WREG_P_78(Value)                TARG_WriteBit(P7H, BIT0, Value)
#define Iodd_WREG_P_79(Value)                TARG_WriteBit(P7H, BIT1, Value)
#define Iodd_WREG_P_710(Value)               /* write access not defined */
#define Iodd_WREG_P_711(Value)               /* write access not defined */
#define Iodd_WREG_P_712(Value)               /* write access not defined */
#define Iodd_WREG_P_713(Value)               /* write access not defined */
#define Iodd_WREG_P_714(Value)               /* write access not defined */
#define Iodd_WREG_P_715(Value)               /* write access not defined */

#endif

#if                                          \
      defined(__NEC_V850_FF3_F3372__)||      \
      defined(__NEC_V850_FF3_F3373__)||      \
      defined(__NEC_V850_FF3L_F3618__)

#define Iodd_RREG_P_78                       TARG_ReadBit(P7H, BIT0)
#define Iodd_RREG_P_79                       TARG_ReadBit(P7H, BIT1)
#define Iodd_RREG_P_710                      TARG_ReadBit(P7H, BIT2)
#define Iodd_RREG_P_711                      TARG_ReadBit(P7H, BIT3)
#define Iodd_RREG_P_712                      /* read access defined but should not be used */
#define Iodd_RREG_P_713                      /* read access defined but should not be used */
#define Iodd_RREG_P_714                      /* read access defined but should not be used */
#define Iodd_RREG_P_715                      /* read access defined but should not be used */

#define Iodd_WREG_P_78(Value)                TARG_WriteBit(P7H, BIT0, Value)
#define Iodd_WREG_P_79(Value)                TARG_WriteBit(P7H, BIT1, Value)
#define Iodd_WREG_P_710(Value)               TARG_WriteBit(P7H, BIT2, Value)
#define Iodd_WREG_P_711(Value)               TARG_WriteBit(P7H, BIT3, Value)
#define Iodd_WREG_P_712(Value)               /* write access not defined */
#define Iodd_WREG_P_713(Value)               /* write access not defined */
#define Iodd_WREG_P_714(Value)               /* write access not defined */
#define Iodd_WREG_P_715(Value)               /* write access not defined */

#endif

#if                                          \
      defined(__NEC_V850_FG3_F3374__)||      \
      defined(__NEC_V850_FG3_F3375__)||      \
      defined(__NEC_V850_FG3_F3376__)||      \
      defined(__NEC_V850_FG3_F3377__)||      \
      defined(__NEC_V850_FJ3_F3378__)||      \
      defined(__NEC_V850_FJ3_F3379__)||      \
      defined(__NEC_V850_FJ3_F3380__)||      \
      defined(__NEC_V850_FJ3_F3381__)||      \
      defined(__NEC_V850_FJ3_F3382__)||      \
      defined(__NEC_V850_FK3_F3383__)||      \
      defined(__NEC_V850_FK3_F3384__)||      \
      defined(__NEC_V850_FK3_F3385__)

#define Iodd_RREG_P_78                       TARG_ReadBit(P7H, BIT0)
#define Iodd_RREG_P_79                       TARG_ReadBit(P7H, BIT1)
#define Iodd_RREG_P_710                      TARG_ReadBit(P7H, BIT2)
#define Iodd_RREG_P_711                      TARG_ReadBit(P7H, BIT3)
#define Iodd_RREG_P_712                      TARG_ReadBit(P7H, BIT4)
#define Iodd_RREG_P_713                      TARG_ReadBit(P7H, BIT5)
#define Iodd_RREG_P_714                      TARG_ReadBit(P7H, BIT6)
#define Iodd_RREG_P_715                      TARG_ReadBit(P7H, BIT7)

#define Iodd_WREG_P_78(Value)                TARG_WriteBit(P7H, BIT0, Value)
#define Iodd_WREG_P_79(Value)                TARG_WriteBit(P7H, BIT1, Value)
#define Iodd_WREG_P_710(Value)               TARG_WriteBit(P7H, BIT2, Value)
#define Iodd_WREG_P_711(Value)               TARG_WriteBit(P7H, BIT3, Value)
#define Iodd_WREG_P_712(Value)               TARG_WriteBit(P7H, BIT4, Value)
#define Iodd_WREG_P_713(Value)               TARG_WriteBit(P7H, BIT5, Value)
#define Iodd_WREG_P_714(Value)               TARG_WriteBit(P7H, BIT6, Value)
#define Iodd_WREG_P_715(Value)               TARG_WriteBit(P7H, BIT7, Value)

#endif

#if                                          \
      defined(__NEC_V850_Fx3__)

#define Iodd_RREG_M_70                       TARG_ReadBit(PM7L, BIT0)
#define Iodd_RREG_M_71                       TARG_ReadBit(PM7L, BIT1)
#define Iodd_RREG_M_72                       TARG_ReadBit(PM7L, BIT2)
#define Iodd_RREG_M_73                       TARG_ReadBit(PM7L, BIT3)
#define Iodd_RREG_M_74                       TARG_ReadBit(PM7L, BIT4)
#define Iodd_RREG_M_75                       TARG_ReadBit(PM7L, BIT5)
#define Iodd_RREG_M_76                       TARG_ReadBit(PM7L, BIT6)
#define Iodd_RREG_M_77                       TARG_ReadBit(PM7L, BIT7)

#define Iodd_WREG_M_70(Value)                TARG_WriteBit(PM7L, BIT0, Value)
#define Iodd_WREG_M_71(Value)                TARG_WriteBit(PM7L, BIT1, Value)
#define Iodd_WREG_M_72(Value)                TARG_WriteBit(PM7L, BIT2, Value)
#define Iodd_WREG_M_73(Value)                TARG_WriteBit(PM7L, BIT3, Value)
#define Iodd_WREG_M_74(Value)                TARG_WriteBit(PM7L, BIT4, Value)
#define Iodd_WREG_M_75(Value)                TARG_WriteBit(PM7L, BIT5, Value)
#define Iodd_WREG_M_76(Value)                TARG_WriteBit(PM7L, BIT6, Value)
#define Iodd_WREG_M_77(Value)                TARG_WriteBit(PM7L, BIT7, Value)

#endif

#if                                          \
      defined(__NEC_V850_FE3_F3370__)||      \
      defined(__NEC_V850_FE3_F3371__)

#define Iodd_RREG_M_78                       TARG_ReadBit(PM7H, BIT0)
#define Iodd_RREG_M_79                       TARG_ReadBit(PM7H, BIT1)
#define Iodd_RREG_M_710                      /* read access defined but should not be used */
#define Iodd_RREG_M_711                      /* read access defined but should not be used */
#define Iodd_RREG_M_712                      /* read access defined but should not be used */
#define Iodd_RREG_M_713                      /* read access defined but should not be used */
#define Iodd_RREG_M_714                      /* read access defined but should not be used */
#define Iodd_RREG_M_715                      /* read access defined but should not be used */

#define Iodd_WREG_M_78(Value)                TARG_WriteBit(PM7H, BIT0, Value)
#define Iodd_WREG_M_79(Value)                TARG_WriteBit(PM7H, BIT1, Value)
#define Iodd_WREG_M_710(Value)               /* write access not defined */
#define Iodd_WREG_M_711(Value)               /* write access not defined */
#define Iodd_WREG_M_712(Value)               /* write access not defined */
#define Iodd_WREG_M_713(Value)               /* write access not defined */
#define Iodd_WREG_M_714(Value)               /* write access not defined */
#define Iodd_WREG_M_715(Value)               /* write access not defined */

#endif

#if                                          \
      defined(__NEC_V850_FF3_F3372__)||      \
      defined(__NEC_V850_FF3_F3373__)||      \
      defined(__NEC_V850_FF3L_F3618__)

#define Iodd_RREG_M_78                       TARG_ReadBit(PM7H, BIT0)
#define Iodd_RREG_M_79                       TARG_ReadBit(PM7H, BIT1)
#define Iodd_RREG_M_710                      TARG_ReadBit(PM7H, BIT2)
#define Iodd_RREG_M_711                      TARG_ReadBit(PM7H, BIT3)
#define Iodd_RREG_M_712                      /* read access defined but should not be used */
#define Iodd_RREG_M_713                      /* read access defined but should not be used */
#define Iodd_RREG_M_714                      /* read access defined but should not be used */
#define Iodd_RREG_M_715                      /* read access defined but should not be used */

#define Iodd_WREG_M_78(Value)                TARG_WriteBit(PM7H, BIT0, Value)
#define Iodd_WREG_M_79(Value)                TARG_WriteBit(PM7H, BIT1, Value)
#define Iodd_WREG_M_710(Value)               TARG_WriteBit(PM7H, BIT2, Value)
#define Iodd_WREG_M_711(Value)               TARG_WriteBit(PM7H, BIT3, Value)
#define Iodd_WREG_M_712(Value)               /* write access not defined */
#define Iodd_WREG_M_713(Value)               /* write access not defined */
#define Iodd_WREG_M_714(Value)               /* write access not defined */
#define Iodd_WREG_M_715(Value)               /* write access not defined */

#endif

#if                                          \
      defined(__NEC_V850_FG3_F3374__)||      \
      defined(__NEC_V850_FG3_F3375__)||      \
      defined(__NEC_V850_FG3_F3376__)||      \
      defined(__NEC_V850_FG3_F3377__)||      \
      defined(__NEC_V850_FJ3_F3378__)||      \
      defined(__NEC_V850_FJ3_F3379__)||      \
      defined(__NEC_V850_FJ3_F3380__)||      \
      defined(__NEC_V850_FJ3_F3381__)||      \
      defined(__NEC_V850_FJ3_F3382__)||      \
      defined(__NEC_V850_FK3_F3383__)||      \
      defined(__NEC_V850_FK3_F3384__)||      \
      defined(__NEC_V850_FK3_F3385__)

#define Iodd_RREG_M_78                       TARG_ReadBit(PM7H, BIT0)
#define Iodd_RREG_M_79                       TARG_ReadBit(PM7H, BIT1)
#define Iodd_RREG_M_710                      TARG_ReadBit(PM7H, BIT2)
#define Iodd_RREG_M_711                      TARG_ReadBit(PM7H, BIT3)
#define Iodd_RREG_M_712                      TARG_ReadBit(PM7H, BIT4)
#define Iodd_RREG_M_713                      TARG_ReadBit(PM7H, BIT5)
#define Iodd_RREG_M_714                      TARG_ReadBit(PM7H, BIT6)
#define Iodd_RREG_M_715                      TARG_ReadBit(PM7H, BIT7)

#define Iodd_WREG_M_78(Value)                TARG_WriteBit(PM7H, BIT0, Value)
#define Iodd_WREG_M_79(Value)                TARG_WriteBit(PM7H, BIT1, Value)
#define Iodd_WREG_M_710(Value)               TARG_WriteBit(PM7H, BIT2, Value)
#define Iodd_WREG_M_711(Value)               TARG_WriteBit(PM7H, BIT3, Value)
#define Iodd_WREG_M_712(Value)               TARG_WriteBit(PM7H, BIT4, Value)
#define Iodd_WREG_M_713(Value)               TARG_WriteBit(PM7H, BIT5, Value)
#define Iodd_WREG_M_714(Value)               TARG_WriteBit(PM7H, BIT6, Value)
#define Iodd_WREG_M_715(Value)               TARG_WriteBit(PM7H, BIT7, Value)

#endif

#if                                          \
      defined(__NEC_V850_Fx3__)

#define Iodd_RREG_MC_70                      TARG_ReadBit(PMC7L, BIT0)
#define Iodd_RREG_MC_71                      TARG_ReadBit(PMC7L, BIT1)
#define Iodd_RREG_MC_72                      TARG_ReadBit(PMC7L, BIT2)
#define Iodd_RREG_MC_73                      TARG_ReadBit(PMC7L, BIT3)
#define Iodd_RREG_MC_74                      TARG_ReadBit(PMC7L, BIT4)
#define Iodd_RREG_MC_75                      TARG_ReadBit(PMC7L, BIT5)
#define Iodd_RREG_MC_76                      TARG_ReadBit(PMC7L, BIT6)
#define Iodd_RREG_MC_77                      TARG_ReadBit(PMC7L, BIT7)

#define Iodd_WREG_MC_70(Value)               TARG_WriteBit(PMC7L, BIT0, Value)
#define Iodd_WREG_MC_71(Value)               TARG_WriteBit(PMC7L, BIT1, Value)
#define Iodd_WREG_MC_72(Value)               TARG_WriteBit(PMC7L, BIT2, Value)
#define Iodd_WREG_MC_73(Value)               TARG_WriteBit(PMC7L, BIT3, Value)
#define Iodd_WREG_MC_74(Value)               TARG_WriteBit(PMC7L, BIT4, Value)
#define Iodd_WREG_MC_75(Value)               TARG_WriteBit(PMC7L, BIT5, Value)
#define Iodd_WREG_MC_76(Value)               TARG_WriteBit(PMC7L, BIT6, Value)
#define Iodd_WREG_MC_77(Value)               TARG_WriteBit(PMC7L, BIT7, Value)

#endif

#if                                          \
      defined(__NEC_V850_FE3_F3370__)||      \
      defined(__NEC_V850_FE3_F3371__)

#define Iodd_RREG_MC_78                      TARG_ReadBit(PMC7H, BIT0)
#define Iodd_RREG_MC_79                      TARG_ReadBit(PMC7H, BIT1)
#define Iodd_RREG_MC_710                     /* read access defined but should not be used */
#define Iodd_RREG_MC_711                     /* read access defined but should not be used */
#define Iodd_RREG_MC_712                     /* read access defined but should not be used */
#define Iodd_RREG_MC_713                     /* read access defined but should not be used */
#define Iodd_RREG_MC_714                     /* read access defined but should not be used */
#define Iodd_RREG_MC_715                     /* read access defined but should not be used */

#define Iodd_WREG_MC_78(Value)               TARG_WriteBit(PMC7H, BIT0, Value)
#define Iodd_WREG_MC_79(Value)               TARG_WriteBit(PMC7H, BIT1, Value)
#define Iodd_WREG_MC_710(Value)              /* write access not defined */
#define Iodd_WREG_MC_711(Value)              /* write access not defined */
#define Iodd_WREG_MC_712(Value)              /* write access not defined */
#define Iodd_WREG_MC_713(Value)              /* write access not defined */
#define Iodd_WREG_MC_714(Value)              /* write access not defined */
#define Iodd_WREG_MC_715(Value)              /* write access not defined */

#endif

#if                                          \
      defined(__NEC_V850_FF3_F3372__)||      \
      defined(__NEC_V850_FF3_F3373__)||      \
      defined(__NEC_V850_FF3L_F3618__)

#define Iodd_RREG_MC_78                      TARG_ReadBit(PMC7H, BIT0)
#define Iodd_RREG_MC_79                      TARG_ReadBit(PMC7H, BIT1)
#define Iodd_RREG_MC_710                     TARG_ReadBit(PMC7H, BIT2)
#define Iodd_RREG_MC_711                     TARG_ReadBit(PMC7H, BIT3)
#define Iodd_RREG_MC_712                     /* read access defined but should not be used */
#define Iodd_RREG_MC_713                     /* read access defined but should not be used */
#define Iodd_RREG_MC_714                     /* read access defined but should not be used */
#define Iodd_RREG_MC_715                     /* read access defined but should not be used */

#define Iodd_WREG_MC_78(Value)               TARG_WriteBit(PMC7H, BIT0, Value)
#define Iodd_WREG_MC_79(Value)               TARG_WriteBit(PMC7H, BIT1, Value)
#define Iodd_WREG_MC_710(Value)              TARG_WriteBit(PMC7H, BIT2, Value)
#define Iodd_WREG_MC_711(Value)              TARG_WriteBit(PMC7H, BIT3, Value)
#define Iodd_WREG_MC_712(Value)              /* write access not defined */
#define Iodd_WREG_MC_713(Value)              /* write access not defined */
#define Iodd_WREG_MC_714(Value)              /* write access not defined */
#define Iodd_WREG_MC_715(Value)              /* write access not defined */

#endif

#if                                          \
      defined(__NEC_V850_FG3_F3374__)||      \
      defined(__NEC_V850_FG3_F3375__)||      \
      defined(__NEC_V850_FG3_F3376__)||      \
      defined(__NEC_V850_FG3_F3377__)||      \
      defined(__NEC_V850_FJ3_F3378__)||      \
      defined(__NEC_V850_FJ3_F3379__)||      \
      defined(__NEC_V850_FJ3_F3380__)||      \
      defined(__NEC_V850_FJ3_F3381__)||      \
      defined(__NEC_V850_FJ3_F3382__)||      \
      defined(__NEC_V850_FK3_F3383__)||      \
      defined(__NEC_V850_FK3_F3384__)||      \
      defined(__NEC_V850_FK3_F3385__)

#define Iodd_RREG_MC_78                      TARG_ReadBit(PMC7H, BIT0)
#define Iodd_RREG_MC_79                      TARG_ReadBit(PMC7H, BIT1)
#define Iodd_RREG_MC_710                     TARG_ReadBit(PMC7H, BIT2)
#define Iodd_RREG_MC_711                     TARG_ReadBit(PMC7H, BIT3)
#define Iodd_RREG_MC_712                     TARG_ReadBit(PMC7H, BIT4)
#define Iodd_RREG_MC_713                     TARG_ReadBit(PMC7H, BIT5)
#define Iodd_RREG_MC_714                     TARG_ReadBit(PMC7H, BIT6)
#define Iodd_RREG_MC_715                     TARG_ReadBit(PMC7H, BIT7)

#define Iodd_WREG_MC_78(Value)               TARG_WriteBit(PMC7H, BIT0, Value)
#define Iodd_WREG_MC_79(Value)               TARG_WriteBit(PMC7H, BIT1, Value)
#define Iodd_WREG_MC_710(Value)              TARG_WriteBit(PMC7H, BIT2, Value)
#define Iodd_WREG_MC_711(Value)              TARG_WriteBit(PMC7H, BIT3, Value)
#define Iodd_WREG_MC_712(Value)              TARG_WriteBit(PMC7H, BIT4, Value)
#define Iodd_WREG_MC_713(Value)              TARG_WriteBit(PMC7H, BIT5, Value)
#define Iodd_WREG_MC_714(Value)              TARG_WriteBit(PMC7H, BIT6, Value)
#define Iodd_WREG_MC_715(Value)              TARG_WriteBit(PMC7H, BIT7, Value)

#endif

#if                                          \
      defined(__NEC_V850_Fx3__)

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
      defined(__NEC_V850_Fx3__)

#define Iodd_RREG_FCE_70                     /* register undefined */
#define Iodd_RREG_FCE_71                     /* register undefined */
#define Iodd_RREG_FCE_72                     /* register undefined */
#define Iodd_RREG_FCE_73                     /* register undefined */
#define Iodd_RREG_FCE_74                     /* register undefined */
#define Iodd_RREG_FCE_75                     /* register undefined */
#define Iodd_RREG_FCE_76                     /* register undefined */
#define Iodd_RREG_FCE_77                     /* register undefined */
#define Iodd_RREG_FCE_78                     /* register undefined */
#define Iodd_RREG_FCE_79                     /* register undefined */
#define Iodd_RREG_FCE_710                    /* register undefined */
#define Iodd_RREG_FCE_711                    /* register undefined */
#define Iodd_RREG_FCE_712                    /* register undefined */
#define Iodd_RREG_FCE_713                    /* register undefined */
#define Iodd_RREG_FCE_714                    /* register undefined */
#define Iodd_RREG_FCE_715                    /* register undefined */

#define Iodd_WREG_FCE_70(Value)              /* register undefined */
#define Iodd_WREG_FCE_71(Value)              /* register undefined */
#define Iodd_WREG_FCE_72(Value)              /* register undefined */
#define Iodd_WREG_FCE_73(Value)              /* register undefined */
#define Iodd_WREG_FCE_74(Value)              /* register undefined */
#define Iodd_WREG_FCE_75(Value)              /* register undefined */
#define Iodd_WREG_FCE_76(Value)              /* register undefined */
#define Iodd_WREG_FCE_77(Value)              /* register undefined */
#define Iodd_WREG_FCE_78(Value)              /* register undefined */
#define Iodd_WREG_FCE_79(Value)              /* register undefined */
#define Iodd_WREG_FCE_710(Value)             /* register undefined */
#define Iodd_WREG_FCE_711(Value)             /* register undefined */
#define Iodd_WREG_FCE_712(Value)             /* register undefined */
#define Iodd_WREG_FCE_713(Value)             /* register undefined */
#define Iodd_WREG_FCE_714(Value)             /* register undefined */
#define Iodd_WREG_FCE_715(Value)             /* register undefined */

#endif

#if                                          \
      defined(__NEC_V850_Fx3__)

#define Iodd_RREG_PU_70                      /* register undefined */
#define Iodd_RREG_PU_71                      /* register undefined */
#define Iodd_RREG_PU_72                      /* register undefined */
#define Iodd_RREG_PU_73                      /* register undefined */
#define Iodd_RREG_PU_74                      /* register undefined */
#define Iodd_RREG_PU_75                      /* register undefined */
#define Iodd_RREG_PU_76                      /* register undefined */
#define Iodd_RREG_PU_77                      /* register undefined */
#define Iodd_RREG_PU_78                      /* register undefined */
#define Iodd_RREG_PU_79                      /* register undefined */
#define Iodd_RREG_PU_710                     /* register undefined */
#define Iodd_RREG_PU_711                     /* register undefined */
#define Iodd_RREG_PU_712                     /* register undefined */
#define Iodd_RREG_PU_713                     /* register undefined */
#define Iodd_RREG_PU_714                     /* register undefined */
#define Iodd_RREG_PU_715                     /* register undefined */

#define Iodd_WREG_PU_70(Value)               /* register undefined */
#define Iodd_WREG_PU_71(Value)               /* register undefined */
#define Iodd_WREG_PU_72(Value)               /* register undefined */
#define Iodd_WREG_PU_73(Value)               /* register undefined */
#define Iodd_WREG_PU_74(Value)               /* register undefined */
#define Iodd_WREG_PU_75(Value)               /* register undefined */
#define Iodd_WREG_PU_76(Value)               /* register undefined */
#define Iodd_WREG_PU_77(Value)               /* register undefined */
#define Iodd_WREG_PU_78(Value)               /* register undefined */
#define Iodd_WREG_PU_79(Value)               /* register undefined */
#define Iodd_WREG_PU_710(Value)              /* register undefined */
#define Iodd_WREG_PU_711(Value)              /* register undefined */
#define Iodd_WREG_PU_712(Value)              /* register undefined */
#define Iodd_WREG_PU_713(Value)              /* register undefined */
#define Iodd_WREG_PU_714(Value)              /* register undefined */
#define Iodd_WREG_PU_715(Value)              /* register undefined */

#endif

#if                                          \
      defined(__NEC_V850_Fx3__)

#define Iodd_RREG_PF_70                      /* register undefined */
#define Iodd_RREG_PF_71                      /* register undefined */
#define Iodd_RREG_PF_72                      /* register undefined */
#define Iodd_RREG_PF_73                      /* register undefined */
#define Iodd_RREG_PF_74                      /* register undefined */
#define Iodd_RREG_PF_75                      /* register undefined */
#define Iodd_RREG_PF_76                      /* register undefined */
#define Iodd_RREG_PF_77                      /* register undefined */
#define Iodd_RREG_PF_78                      /* register undefined */
#define Iodd_RREG_PF_79                      /* register undefined */
#define Iodd_RREG_PF_710                     /* register undefined */
#define Iodd_RREG_PF_711                     /* register undefined */
#define Iodd_RREG_PF_712                     /* register undefined */
#define Iodd_RREG_PF_713                     /* register undefined */
#define Iodd_RREG_PF_714                     /* register undefined */
#define Iodd_RREG_PF_715                     /* register undefined */

#define Iodd_WREG_PF_70(Value)               /* register undefined */
#define Iodd_WREG_PF_71(Value)               /* register undefined */
#define Iodd_WREG_PF_72(Value)               /* register undefined */
#define Iodd_WREG_PF_73(Value)               /* register undefined */
#define Iodd_WREG_PF_74(Value)               /* register undefined */
#define Iodd_WREG_PF_75(Value)               /* register undefined */
#define Iodd_WREG_PF_76(Value)               /* register undefined */
#define Iodd_WREG_PF_77(Value)               /* register undefined */
#define Iodd_WREG_PF_78(Value)               /* register undefined */
#define Iodd_WREG_PF_79(Value)               /* register undefined */
#define Iodd_WREG_PF_710(Value)              /* register undefined */
#define Iodd_WREG_PF_711(Value)              /* register undefined */
#define Iodd_WREG_PF_712(Value)              /* register undefined */
#define Iodd_WREG_PF_713(Value)              /* register undefined */
#define Iodd_WREG_PF_714(Value)              /* register undefined */
#define Iodd_WREG_PF_715(Value)              /* register undefined */

#endif

/* Definitions PORT 8 */

#if                                          \
      defined(__NEC_V850_FJ3_F3378__)||      \
      defined(__NEC_V850_FJ3_F3379__)||      \
      defined(__NEC_V850_FJ3_F3380__)||      \
      defined(__NEC_V850_FJ3_F3381__)||      \
      defined(__NEC_V850_FJ3_F3382__)||      \
      defined(__NEC_V850_FK3_F3383__)||      \
      defined(__NEC_V850_FK3_F3384__)||      \
      defined(__NEC_V850_FK3_F3385__)

#define Iodd_RREG_P_80                       TARG_ReadBit(P8, BIT0)
#define Iodd_RREG_P_81                       TARG_ReadBit(P8, BIT1)
#define Iodd_RREG_P_82                       /* read access defined but should not be used */
#define Iodd_RREG_P_83                       /* read access defined but should not be used */
#define Iodd_RREG_P_84                       /* read access defined but should not be used */
#define Iodd_RREG_P_85                       /* read access defined but should not be used */
#define Iodd_RREG_P_86                       /* read access defined but should not be used */
#define Iodd_RREG_P_87                       /* read access defined but should not be used */

#define Iodd_WREG_P_80(Value)                TARG_WriteBit(P8, BIT0, Value)
#define Iodd_WREG_P_81(Value)                TARG_WriteBit(P8, BIT1, Value)
#define Iodd_WREG_P_82(Value)                /* write access not defined */
#define Iodd_WREG_P_83(Value)                /* write access not defined */
#define Iodd_WREG_P_84(Value)                /* write access not defined */
#define Iodd_WREG_P_85(Value)                /* write access not defined */
#define Iodd_WREG_P_86(Value)                /* write access not defined */
#define Iodd_WREG_P_87(Value)                /* write access not defined */

#endif

#if                                          \
      defined(__NEC_V850_FJ3_F3378__)||      \
      defined(__NEC_V850_FJ3_F3379__)||      \
      defined(__NEC_V850_FJ3_F3380__)||      \
      defined(__NEC_V850_FJ3_F3381__)||      \
      defined(__NEC_V850_FJ3_F3382__)||      \
      defined(__NEC_V850_FK3_F3383__)||      \
      defined(__NEC_V850_FK3_F3384__)||      \
      defined(__NEC_V850_FK3_F3385__)

#define Iodd_RREG_M_80                       TARG_ReadBit(PM8, BIT0)
#define Iodd_RREG_M_81                       TARG_ReadBit(PM8, BIT1)
#define Iodd_RREG_M_82                       /* read access defined but should not be used */
#define Iodd_RREG_M_83                       /* read access defined but should not be used */
#define Iodd_RREG_M_84                       /* read access defined but should not be used */
#define Iodd_RREG_M_85                       /* read access defined but should not be used */
#define Iodd_RREG_M_86                       /* read access defined but should not be used */
#define Iodd_RREG_M_87                       /* read access defined but should not be used */

#define Iodd_WREG_M_80(Value)                TARG_WriteBit(PM8, BIT0, Value)
#define Iodd_WREG_M_81(Value)                TARG_WriteBit(PM8, BIT1, Value)
#define Iodd_WREG_M_82(Value)                /* write access not defined */
#define Iodd_WREG_M_83(Value)                /* write access not defined */
#define Iodd_WREG_M_84(Value)                /* write access not defined */
#define Iodd_WREG_M_85(Value)                /* write access not defined */
#define Iodd_WREG_M_86(Value)                /* write access not defined */
#define Iodd_WREG_M_87(Value)                /* write access not defined */

#endif

#if                                          \
      defined(__NEC_V850_FJ3_F3378__)

#define Iodd_RREG_MC_80                      TARG_ReadBit(PMC8, BIT0)
#define Iodd_RREG_MC_81                      /* read access defined but should not be used */
#define Iodd_RREG_MC_82                      /* read access defined but should not be used */
#define Iodd_RREG_MC_83                      /* read access defined but should not be used */
#define Iodd_RREG_MC_84                      /* read access defined but should not be used */
#define Iodd_RREG_MC_85                      /* read access defined but should not be used */
#define Iodd_RREG_MC_86                      /* read access defined but should not be used */
#define Iodd_RREG_MC_87                      /* read access defined but should not be used */

#define Iodd_WREG_MC_80(Value)               TARG_WriteBit(PMC8, BIT0, Value)
#define Iodd_WREG_MC_81(Value)               /* write access not defined */
#define Iodd_WREG_MC_82(Value)               /* write access not defined */
#define Iodd_WREG_MC_83(Value)               /* write access not defined */
#define Iodd_WREG_MC_84(Value)               /* write access not defined */
#define Iodd_WREG_MC_85(Value)               /* write access not defined */
#define Iodd_WREG_MC_86(Value)               /* write access not defined */
#define Iodd_WREG_MC_87(Value)               /* write access not defined */

#endif

#if                                          \
      defined(__NEC_V850_FJ3_F3379__)||      \
      defined(__NEC_V850_FJ3_F3380__)||      \
      defined(__NEC_V850_FJ3_F3381__)||      \
      defined(__NEC_V850_FJ3_F3382__)||      \
      defined(__NEC_V850_FK3_F3383__)||      \
      defined(__NEC_V850_FK3_F3384__)||      \
      defined(__NEC_V850_FK3_F3385__)

#define Iodd_RREG_MC_80                      TARG_ReadBit(PMC8, BIT0)
#define Iodd_RREG_MC_81                      TARG_ReadBit(PMC8, BIT1)
#define Iodd_RREG_MC_82                      /* read access defined but should not be used */
#define Iodd_RREG_MC_83                      /* read access defined but should not be used */
#define Iodd_RREG_MC_84                      /* read access defined but should not be used */
#define Iodd_RREG_MC_85                      /* read access defined but should not be used */
#define Iodd_RREG_MC_86                      /* read access defined but should not be used */
#define Iodd_RREG_MC_87                      /* read access defined but should not be used */

#define Iodd_WREG_MC_80(Value)               TARG_WriteBit(PMC8, BIT0, Value)
#define Iodd_WREG_MC_81(Value)               TARG_WriteBit(PMC8, BIT1, Value)
#define Iodd_WREG_MC_82(Value)               /* write access not defined */
#define Iodd_WREG_MC_83(Value)               /* write access not defined */
#define Iodd_WREG_MC_84(Value)               /* write access not defined */
#define Iodd_WREG_MC_85(Value)               /* write access not defined */
#define Iodd_WREG_MC_86(Value)               /* write access not defined */
#define Iodd_WREG_MC_87(Value)               /* write access not defined */

#endif

#if                                          \
      defined(__NEC_V850_FJ3_F3378__)||      \
      defined(__NEC_V850_FJ3_F3379__)||      \
      defined(__NEC_V850_FJ3_F3380__)||      \
      defined(__NEC_V850_FJ3_F3381__)||      \
      defined(__NEC_V850_FJ3_F3382__)||      \
      defined(__NEC_V850_FK3_F3383__)||      \
      defined(__NEC_V850_FK3_F3384__)||      \
      defined(__NEC_V850_FK3_F3385__)

#define Iodd_RREG_PU_80                      TARG_ReadBit(PU8, BIT0)
#define Iodd_RREG_PU_81                      TARG_ReadBit(PU8, BIT1)
#define Iodd_RREG_PU_82                      /* read access defined but should not be used */
#define Iodd_RREG_PU_83                      /* read access defined but should not be used */
#define Iodd_RREG_PU_84                      /* read access defined but should not be used */
#define Iodd_RREG_PU_85                      /* read access defined but should not be used */
#define Iodd_RREG_PU_86                      /* read access defined but should not be used */
#define Iodd_RREG_PU_87                      /* read access defined but should not be used */

#define Iodd_WREG_PU_80(Value)               TARG_WriteBit(PU8, BIT0, Value)
#define Iodd_WREG_PU_81(Value)               TARG_WriteBit(PU8, BIT1, Value)
#define Iodd_WREG_PU_82(Value)               /* write access not defined */
#define Iodd_WREG_PU_83(Value)               /* write access not defined */
#define Iodd_WREG_PU_84(Value)               /* write access not defined */
#define Iodd_WREG_PU_85(Value)               /* write access not defined */
#define Iodd_WREG_PU_86(Value)               /* write access not defined */
#define Iodd_WREG_PU_87(Value)               /* write access not defined */

#endif

#if                                          \
      defined(__NEC_V850_FE3_F3370__)||      \
      defined(__NEC_V850_FE3_F3371__)||      \
      defined(__NEC_V850_FF3_F3372__)||      \
      defined(__NEC_V850_FF3_F3373__)||      \
      defined(__NEC_V850_FG3_F3374__)||      \
      defined(__NEC_V850_FG3_F3375__)||      \
      defined(__NEC_V850_FG3_F3376__)||      \
      defined(__NEC_V850_FG3_F3377__)||      \
      defined(__NEC_V850_FF3L_F3618__)

#define Iodd_RREG_P_80                       /* register undefined */
#define Iodd_RREG_P_81                       /* register undefined */
#define Iodd_RREG_P_82                       /* register undefined */
#define Iodd_RREG_P_83                       /* register undefined */
#define Iodd_RREG_P_84                       /* register undefined */
#define Iodd_RREG_P_85                       /* register undefined */
#define Iodd_RREG_P_86                       /* register undefined */
#define Iodd_RREG_P_87                       /* register undefined */

#define Iodd_WREG_P_80(Value)                /* register undefined */
#define Iodd_WREG_P_81(Value)                /* register undefined */
#define Iodd_WREG_P_82(Value)                /* register undefined */
#define Iodd_WREG_P_83(Value)                /* register undefined */
#define Iodd_WREG_P_84(Value)                /* register undefined */
#define Iodd_WREG_P_85(Value)                /* register undefined */
#define Iodd_WREG_P_86(Value)                /* register undefined */
#define Iodd_WREG_P_87(Value)                /* register undefined */

#endif

#if                                          \
      defined(__NEC_V850_FE3_F3370__)||      \
      defined(__NEC_V850_FE3_F3371__)||      \
      defined(__NEC_V850_FF3_F3372__)||      \
      defined(__NEC_V850_FF3_F3373__)||      \
      defined(__NEC_V850_FG3_F3374__)||      \
      defined(__NEC_V850_FG3_F3375__)||      \
      defined(__NEC_V850_FG3_F3376__)||      \
      defined(__NEC_V850_FG3_F3377__)||      \
      defined(__NEC_V850_FF3L_F3618__)

#define Iodd_RREG_M_80                       /* register undefined */
#define Iodd_RREG_M_81                       /* register undefined */
#define Iodd_RREG_M_82                       /* register undefined */
#define Iodd_RREG_M_83                       /* register undefined */
#define Iodd_RREG_M_84                       /* register undefined */
#define Iodd_RREG_M_85                       /* register undefined */
#define Iodd_RREG_M_86                       /* register undefined */
#define Iodd_RREG_M_87                       /* register undefined */

#define Iodd_WREG_M_80(Value)                /* register undefined */
#define Iodd_WREG_M_81(Value)                /* register undefined */
#define Iodd_WREG_M_82(Value)                /* register undefined */
#define Iodd_WREG_M_83(Value)                /* register undefined */
#define Iodd_WREG_M_84(Value)                /* register undefined */
#define Iodd_WREG_M_85(Value)                /* register undefined */
#define Iodd_WREG_M_86(Value)                /* register undefined */
#define Iodd_WREG_M_87(Value)                /* register undefined */

#endif

#if                                          \
      defined(__NEC_V850_FE3_F3370__)||      \
      defined(__NEC_V850_FE3_F3371__)||      \
      defined(__NEC_V850_FF3_F3372__)||      \
      defined(__NEC_V850_FF3_F3373__)||      \
      defined(__NEC_V850_FG3_F3374__)||      \
      defined(__NEC_V850_FG3_F3375__)||      \
      defined(__NEC_V850_FG3_F3376__)||      \
      defined(__NEC_V850_FG3_F3377__)||      \
      defined(__NEC_V850_FF3L_F3618__)

#define Iodd_RREG_MC_80                      /* register undefined */
#define Iodd_RREG_MC_81                      /* register undefined */
#define Iodd_RREG_MC_82                      /* register undefined */
#define Iodd_RREG_MC_83                      /* register undefined */
#define Iodd_RREG_MC_84                      /* register undefined */
#define Iodd_RREG_MC_85                      /* register undefined */
#define Iodd_RREG_MC_86                      /* register undefined */
#define Iodd_RREG_MC_87                      /* register undefined */

#define Iodd_WREG_MC_80(Value)               /* register undefined */
#define Iodd_WREG_MC_81(Value)               /* register undefined */
#define Iodd_WREG_MC_82(Value)               /* register undefined */
#define Iodd_WREG_MC_83(Value)               /* register undefined */
#define Iodd_WREG_MC_84(Value)               /* register undefined */
#define Iodd_WREG_MC_85(Value)               /* register undefined */
#define Iodd_WREG_MC_86(Value)               /* register undefined */
#define Iodd_WREG_MC_87(Value)               /* register undefined */

#endif

#if                                          \
      defined(__NEC_V850_Fx3__)

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

#endif

#if                                          \
      defined(__NEC_V850_Fx3__)

#define Iodd_RREG_FCE_80                     /* register undefined */
#define Iodd_RREG_FCE_81                     /* register undefined */
#define Iodd_RREG_FCE_82                     /* register undefined */
#define Iodd_RREG_FCE_83                     /* register undefined */
#define Iodd_RREG_FCE_84                     /* register undefined */
#define Iodd_RREG_FCE_85                     /* register undefined */
#define Iodd_RREG_FCE_86                     /* register undefined */
#define Iodd_RREG_FCE_87                     /* register undefined */

#define Iodd_WREG_FCE_80(Value)              /* register undefined */
#define Iodd_WREG_FCE_81(Value)              /* register undefined */
#define Iodd_WREG_FCE_82(Value)              /* register undefined */
#define Iodd_WREG_FCE_83(Value)              /* register undefined */
#define Iodd_WREG_FCE_84(Value)              /* register undefined */
#define Iodd_WREG_FCE_85(Value)              /* register undefined */
#define Iodd_WREG_FCE_86(Value)              /* register undefined */
#define Iodd_WREG_FCE_87(Value)              /* register undefined */

#endif

#if                                          \
      defined(__NEC_V850_FE3_F3370__)||      \
      defined(__NEC_V850_FE3_F3371__)||      \
      defined(__NEC_V850_FF3_F3372__)||      \
      defined(__NEC_V850_FF3_F3373__)||      \
      defined(__NEC_V850_FG3_F3374__)||      \
      defined(__NEC_V850_FG3_F3375__)||      \
      defined(__NEC_V850_FG3_F3376__)||      \
      defined(__NEC_V850_FG3_F3377__)||      \
      defined(__NEC_V850_FF3L_F3618__)

#define Iodd_RREG_PU_80                      /* register undefined */
#define Iodd_RREG_PU_81                      /* register undefined */
#define Iodd_RREG_PU_82                      /* register undefined */
#define Iodd_RREG_PU_83                      /* register undefined */
#define Iodd_RREG_PU_84                      /* register undefined */
#define Iodd_RREG_PU_85                      /* register undefined */
#define Iodd_RREG_PU_86                      /* register undefined */
#define Iodd_RREG_PU_87                      /* register undefined */

#define Iodd_WREG_PU_80(Value)               /* register undefined */
#define Iodd_WREG_PU_81(Value)               /* register undefined */
#define Iodd_WREG_PU_82(Value)               /* register undefined */
#define Iodd_WREG_PU_83(Value)               /* register undefined */
#define Iodd_WREG_PU_84(Value)               /* register undefined */
#define Iodd_WREG_PU_85(Value)               /* register undefined */
#define Iodd_WREG_PU_86(Value)               /* register undefined */
#define Iodd_WREG_PU_87(Value)               /* register undefined */

#endif

#if                                          \
      defined(__NEC_V850_Fx3__)

#define Iodd_RREG_PF_80                      /* register undefined */
#define Iodd_RREG_PF_81                      /* register undefined */
#define Iodd_RREG_PF_82                      /* register undefined */
#define Iodd_RREG_PF_83                      /* register undefined */
#define Iodd_RREG_PF_84                      /* register undefined */
#define Iodd_RREG_PF_85                      /* register undefined */
#define Iodd_RREG_PF_86                      /* register undefined */
#define Iodd_RREG_PF_87                      /* register undefined */

#define Iodd_WREG_PF_80(Value)               /* register undefined */
#define Iodd_WREG_PF_81(Value)               /* register undefined */
#define Iodd_WREG_PF_82(Value)               /* register undefined */
#define Iodd_WREG_PF_83(Value)               /* register undefined */
#define Iodd_WREG_PF_84(Value)               /* register undefined */
#define Iodd_WREG_PF_85(Value)               /* register undefined */
#define Iodd_WREG_PF_86(Value)               /* register undefined */
#define Iodd_WREG_PF_87(Value)               /* register undefined */

#endif

/* Definitions PORT 9 */

#if                                          \
      defined(__NEC_V850_FE3_F3370__)||      \
      defined(__NEC_V850_FE3_F3371__)||      \
      defined(__NEC_V850_FF3_F3372__)||      \
      defined(__NEC_V850_FF3_F3373__)||      \
      defined(__NEC_V850_FF3L_F3618__)

#define Iodd_RREG_P_90                       TARG_ReadBit(P9L, BIT0)
#define Iodd_RREG_P_91                       TARG_ReadBit(P9L, BIT1)
#define Iodd_RREG_P_92                       /* read access defined but should not be used */
#define Iodd_RREG_P_93                       /* read access defined but should not be used */
#define Iodd_RREG_P_94                       /* read access defined but should not be used */
#define Iodd_RREG_P_95                       /* read access defined but should not be used */
#define Iodd_RREG_P_96                       TARG_ReadBit(P9L, BIT6)
#define Iodd_RREG_P_97                       TARG_ReadBit(P9L, BIT7)
#define Iodd_RREG_P_98                       TARG_ReadBit(P9H, BIT0)
#define Iodd_RREG_P_99                       TARG_ReadBit(P9H, BIT1)
#define Iodd_RREG_P_910                      /* read access defined but should not be used */
#define Iodd_RREG_P_911                      /* read access defined but should not be used */
#define Iodd_RREG_P_912                      /* read access defined but should not be used */
#define Iodd_RREG_P_913                      TARG_ReadBit(P9H, BIT5)
#define Iodd_RREG_P_914                      TARG_ReadBit(P9H, BIT6)
#define Iodd_RREG_P_915                      TARG_ReadBit(P9H, BIT7)

#define Iodd_WREG_P_90(Value)                TARG_WriteBit(P9L, BIT0, Value)
#define Iodd_WREG_P_91(Value)                TARG_WriteBit(P9L, BIT1, Value)
#define Iodd_WREG_P_92(Value)                /* write access not defined */
#define Iodd_WREG_P_93(Value)                /* write access not defined */
#define Iodd_WREG_P_94(Value)                /* write access not defined */
#define Iodd_WREG_P_95(Value)                /* write access not defined */
#define Iodd_WREG_P_96(Value)                TARG_WriteBit(P9L, BIT6, Value)
#define Iodd_WREG_P_97(Value)                TARG_WriteBit(P9L, BIT7, Value)
#define Iodd_WREG_P_98(Value)                TARG_WriteBit(P9H, BIT0, Value)
#define Iodd_WREG_P_99(Value)                TARG_WriteBit(P9H, BIT1, Value)
#define Iodd_WREG_P_910(Value)               /* write access not defined */
#define Iodd_WREG_P_911(Value)               /* write access not defined */
#define Iodd_WREG_P_912(Value)               /* write access not defined */
#define Iodd_WREG_P_913(Value)               TARG_WriteBit(P9H, BIT5, Value)
#define Iodd_WREG_P_914(Value)               TARG_WriteBit(P9H, BIT6, Value)
#define Iodd_WREG_P_915(Value)               TARG_WriteBit(P9H, BIT7, Value)

#endif

#if                                          \
      defined(__NEC_V850_FG3_F3374__)||      \
      defined(__NEC_V850_FG3_F3375__)||      \
      defined(__NEC_V850_FG3_F3376__)||      \
      defined(__NEC_V850_FG3_F3377__)||      \
      defined(__NEC_V850_FJ3_F3378__)||      \
      defined(__NEC_V850_FJ3_F3379__)||      \
      defined(__NEC_V850_FJ3_F3380__)||      \
      defined(__NEC_V850_FJ3_F3381__)||      \
      defined(__NEC_V850_FJ3_F3382__)||      \
      defined(__NEC_V850_FK3_F3383__)||      \
      defined(__NEC_V850_FK3_F3384__)||      \
      defined(__NEC_V850_FK3_F3385__)

#define Iodd_RREG_P_90                       TARG_ReadBit(P9L, BIT0)
#define Iodd_RREG_P_91                       TARG_ReadBit(P9L, BIT1)
#define Iodd_RREG_P_92                       TARG_ReadBit(P9L, BIT2)
#define Iodd_RREG_P_93                       TARG_ReadBit(P9L, BIT3)
#define Iodd_RREG_P_94                       TARG_ReadBit(P9L, BIT4)
#define Iodd_RREG_P_95                       TARG_ReadBit(P9L, BIT5)
#define Iodd_RREG_P_96                       TARG_ReadBit(P9L, BIT6)
#define Iodd_RREG_P_97                       TARG_ReadBit(P9L, BIT7)
#define Iodd_RREG_P_98                       TARG_ReadBit(P9H, BIT0)
#define Iodd_RREG_P_99                       TARG_ReadBit(P9H, BIT1)
#define Iodd_RREG_P_910                      TARG_ReadBit(P9H, BIT2)
#define Iodd_RREG_P_911                      TARG_ReadBit(P9H, BIT3)
#define Iodd_RREG_P_912                      TARG_ReadBit(P9H, BIT4)
#define Iodd_RREG_P_913                      TARG_ReadBit(P9H, BIT5)
#define Iodd_RREG_P_914                      TARG_ReadBit(P9H, BIT6)
#define Iodd_RREG_P_915                      TARG_ReadBit(P9H, BIT7)

#define Iodd_WREG_P_90(Value)                TARG_WriteBit(P9L, BIT0, Value)
#define Iodd_WREG_P_91(Value)                TARG_WriteBit(P9L, BIT1, Value)
#define Iodd_WREG_P_92(Value)                TARG_WriteBit(P9L, BIT2, Value)
#define Iodd_WREG_P_93(Value)                TARG_WriteBit(P9L, BIT3, Value)
#define Iodd_WREG_P_94(Value)                TARG_WriteBit(P9L, BIT4, Value)
#define Iodd_WREG_P_95(Value)                TARG_WriteBit(P9L, BIT5, Value)
#define Iodd_WREG_P_96(Value)                TARG_WriteBit(P9L, BIT6, Value)
#define Iodd_WREG_P_97(Value)                TARG_WriteBit(P9L, BIT7, Value)
#define Iodd_WREG_P_98(Value)                TARG_WriteBit(P9H, BIT0, Value)
#define Iodd_WREG_P_99(Value)                TARG_WriteBit(P9H, BIT1, Value)
#define Iodd_WREG_P_910(Value)               TARG_WriteBit(P9H, BIT2, Value)
#define Iodd_WREG_P_911(Value)               TARG_WriteBit(P9H, BIT3, Value)
#define Iodd_WREG_P_912(Value)               TARG_WriteBit(P9H, BIT4, Value)
#define Iodd_WREG_P_913(Value)               TARG_WriteBit(P9H, BIT5, Value)
#define Iodd_WREG_P_914(Value)               TARG_WriteBit(P9H, BIT6, Value)
#define Iodd_WREG_P_915(Value)               TARG_WriteBit(P9H, BIT7, Value)

#endif

#if                                          \
      defined(__NEC_V850_FE3_F3370__)||      \
      defined(__NEC_V850_FE3_F3371__)||      \
      defined(__NEC_V850_FF3_F3372__)||      \
      defined(__NEC_V850_FF3_F3373__)||      \
      defined(__NEC_V850_FF3L_F3618__)

#define Iodd_RREG_M_90                       TARG_ReadBit(PM9L, BIT0)
#define Iodd_RREG_M_91                       TARG_ReadBit(PM9L, BIT1)
#define Iodd_RREG_M_92                       /* read access defined but should not be used */
#define Iodd_RREG_M_93                       /* read access defined but should not be used */
#define Iodd_RREG_M_94                       /* read access defined but should not be used */
#define Iodd_RREG_M_95                       /* read access defined but should not be used */
#define Iodd_RREG_M_96                       TARG_ReadBit(PM9L, BIT6)
#define Iodd_RREG_M_97                       TARG_ReadBit(PM9L, BIT7)
#define Iodd_RREG_M_98                       TARG_ReadBit(PM9H, BIT0)
#define Iodd_RREG_M_99                       TARG_ReadBit(PM9H, BIT1)
#define Iodd_RREG_M_910                      /* read access defined but should not be used */
#define Iodd_RREG_M_911                      /* read access defined but should not be used */
#define Iodd_RREG_M_912                      /* read access defined but should not be used */
#define Iodd_RREG_M_913                      TARG_ReadBit(PM9H, BIT5)
#define Iodd_RREG_M_914                      TARG_ReadBit(PM9H, BIT6)
#define Iodd_RREG_M_915                      TARG_ReadBit(PM9H, BIT7)

#define Iodd_WREG_M_90(Value)                TARG_WriteBit(PM9L, BIT0, Value)
#define Iodd_WREG_M_91(Value)                TARG_WriteBit(PM9L, BIT1, Value)
#define Iodd_WREG_M_92(Value)                /* write access not defined */
#define Iodd_WREG_M_93(Value)                /* write access not defined */
#define Iodd_WREG_M_94(Value)                /* write access not defined */
#define Iodd_WREG_M_95(Value)                /* write access not defined */
#define Iodd_WREG_M_96(Value)                TARG_WriteBit(PM9L, BIT6, Value)
#define Iodd_WREG_M_97(Value)                TARG_WriteBit(PM9L, BIT7, Value)
#define Iodd_WREG_M_98(Value)                TARG_WriteBit(PM9H, BIT0, Value)
#define Iodd_WREG_M_99(Value)                TARG_WriteBit(PM9H, BIT1, Value)
#define Iodd_WREG_M_910(Value)               /* write access not defined */
#define Iodd_WREG_M_911(Value)               /* write access not defined */
#define Iodd_WREG_M_912(Value)               /* write access not defined */
#define Iodd_WREG_M_913(Value)               TARG_WriteBit(PM9H, BIT5, Value)
#define Iodd_WREG_M_914(Value)               TARG_WriteBit(PM9H, BIT6, Value)
#define Iodd_WREG_M_915(Value)               TARG_WriteBit(PM9H, BIT7, Value)

#endif

#if                                          \
      defined(__NEC_V850_FG3_F3374__)||      \
      defined(__NEC_V850_FG3_F3375__)||      \
      defined(__NEC_V850_FG3_F3376__)||      \
      defined(__NEC_V850_FG3_F3377__)||      \
      defined(__NEC_V850_FJ3_F3378__)||      \
      defined(__NEC_V850_FJ3_F3379__)||      \
      defined(__NEC_V850_FJ3_F3380__)||      \
      defined(__NEC_V850_FJ3_F3381__)||      \
      defined(__NEC_V850_FJ3_F3382__)||      \
      defined(__NEC_V850_FK3_F3383__)||      \
      defined(__NEC_V850_FK3_F3384__)||      \
      defined(__NEC_V850_FK3_F3385__)

#define Iodd_RREG_M_90                       TARG_ReadBit(PM9L, BIT0)
#define Iodd_RREG_M_91                       TARG_ReadBit(PM9L, BIT1)
#define Iodd_RREG_M_92                       TARG_ReadBit(PM9L, BIT2)
#define Iodd_RREG_M_93                       TARG_ReadBit(PM9L, BIT3)
#define Iodd_RREG_M_94                       TARG_ReadBit(PM9L, BIT4)
#define Iodd_RREG_M_95                       TARG_ReadBit(PM9L, BIT5)
#define Iodd_RREG_M_96                       TARG_ReadBit(PM9L, BIT6)
#define Iodd_RREG_M_97                       TARG_ReadBit(PM9L, BIT7)
#define Iodd_RREG_M_98                       TARG_ReadBit(PM9H, BIT0)
#define Iodd_RREG_M_99                       TARG_ReadBit(PM9H, BIT1)
#define Iodd_RREG_M_910                      TARG_ReadBit(PM9H, BIT2)
#define Iodd_RREG_M_911                      TARG_ReadBit(PM9H, BIT3)
#define Iodd_RREG_M_912                      TARG_ReadBit(PM9H, BIT4)
#define Iodd_RREG_M_913                      TARG_ReadBit(PM9H, BIT5)
#define Iodd_RREG_M_914                      TARG_ReadBit(PM9H, BIT6)
#define Iodd_RREG_M_915                      TARG_ReadBit(PM9H, BIT7)

#define Iodd_WREG_M_90(Value)                TARG_WriteBit(PM9L, BIT0, Value)
#define Iodd_WREG_M_91(Value)                TARG_WriteBit(PM9L, BIT1, Value)
#define Iodd_WREG_M_92(Value)                TARG_WriteBit(PM9L, BIT2, Value)
#define Iodd_WREG_M_93(Value)                TARG_WriteBit(PM9L, BIT3, Value)
#define Iodd_WREG_M_94(Value)                TARG_WriteBit(PM9L, BIT4, Value)
#define Iodd_WREG_M_95(Value)                TARG_WriteBit(PM9L, BIT5, Value)
#define Iodd_WREG_M_96(Value)                TARG_WriteBit(PM9L, BIT6, Value)
#define Iodd_WREG_M_97(Value)                TARG_WriteBit(PM9L, BIT7, Value)
#define Iodd_WREG_M_98(Value)                TARG_WriteBit(PM9H, BIT0, Value)
#define Iodd_WREG_M_99(Value)                TARG_WriteBit(PM9H, BIT1, Value)
#define Iodd_WREG_M_910(Value)               TARG_WriteBit(PM9H, BIT2, Value)
#define Iodd_WREG_M_911(Value)               TARG_WriteBit(PM9H, BIT3, Value)
#define Iodd_WREG_M_912(Value)               TARG_WriteBit(PM9H, BIT4, Value)
#define Iodd_WREG_M_913(Value)               TARG_WriteBit(PM9H, BIT5, Value)
#define Iodd_WREG_M_914(Value)               TARG_WriteBit(PM9H, BIT6, Value)
#define Iodd_WREG_M_915(Value)               TARG_WriteBit(PM9H, BIT7, Value)

#endif

#if                                          \
      defined(__NEC_V850_FE3_F3370__)||      \
      defined(__NEC_V850_FE3_F3371__)||      \
      defined(__NEC_V850_FF3_F3372__)||      \
      defined(__NEC_V850_FF3_F3373__)||      \
      defined(__NEC_V850_FF3L_F3618__)

#define Iodd_RREG_MC_90                      TARG_ReadBit(PMC9L, BIT0)
#define Iodd_RREG_MC_91                      TARG_ReadBit(PMC9L, BIT1)
#define Iodd_RREG_MC_92                      /* read access defined but should not be used */
#define Iodd_RREG_MC_93                      /* read access defined but should not be used */
#define Iodd_RREG_MC_94                      /* read access defined but should not be used */
#define Iodd_RREG_MC_95                      /* read access defined but should not be used */
#define Iodd_RREG_MC_96                      TARG_ReadBit(PMC9L, BIT6)
#define Iodd_RREG_MC_97                      TARG_ReadBit(PMC9L, BIT7)
#define Iodd_RREG_MC_98                      TARG_ReadBit(PMC9H, BIT0)
#define Iodd_RREG_MC_99                      TARG_ReadBit(PMC9H, BIT1)
#define Iodd_RREG_MC_910                     /* read access defined but should not be used */
#define Iodd_RREG_MC_911                     /* read access defined but should not be used */
#define Iodd_RREG_MC_912                     /* read access defined but should not be used */
#define Iodd_RREG_MC_913                     TARG_ReadBit(PMC9H, BIT5)
#define Iodd_RREG_MC_914                     TARG_ReadBit(PMC9H, BIT6)
#define Iodd_RREG_MC_915                     TARG_ReadBit(PMC9H, BIT7)

#define Iodd_WREG_MC_90(Value)               TARG_WriteBit(PMC9L, BIT0, Value)
#define Iodd_WREG_MC_91(Value)               TARG_WriteBit(PMC9L, BIT1, Value)
#define Iodd_WREG_MC_92(Value)               /* write access not defined */
#define Iodd_WREG_MC_93(Value)               /* write access not defined */
#define Iodd_WREG_MC_94(Value)               /* write access not defined */
#define Iodd_WREG_MC_95(Value)               /* write access not defined */
#define Iodd_WREG_MC_96(Value)               TARG_WriteBit(PMC9L, BIT6, Value)
#define Iodd_WREG_MC_97(Value)               TARG_WriteBit(PMC9L, BIT7, Value)
#define Iodd_WREG_MC_98(Value)               TARG_WriteBit(PMC9H, BIT0, Value)
#define Iodd_WREG_MC_99(Value)               TARG_WriteBit(PMC9H, BIT1, Value)
#define Iodd_WREG_MC_910(Value)              /* write access not defined */
#define Iodd_WREG_MC_911(Value)              /* write access not defined */
#define Iodd_WREG_MC_912(Value)              /* write access not defined */
#define Iodd_WREG_MC_913(Value)              TARG_WriteBit(PMC9H, BIT5, Value)
#define Iodd_WREG_MC_914(Value)              TARG_WriteBit(PMC9H, BIT6, Value)
#define Iodd_WREG_MC_915(Value)              TARG_WriteBit(PMC9H, BIT7, Value)

#endif

#if                                          \
      defined(__NEC_V850_FG3_F3374__)||      \
      defined(__NEC_V850_FG3_F3375__)||      \
      defined(__NEC_V850_FG3_F3376__)||      \
      defined(__NEC_V850_FG3_F3377__)

#define Iodd_RREG_MC_90                      TARG_ReadBit(PMC9L, BIT0)
#define Iodd_RREG_MC_91                      TARG_ReadBit(PMC9L, BIT1)
#define Iodd_RREG_MC_92                      TARG_ReadBit(PMC9L, BIT2)
#define Iodd_RREG_MC_93                      TARG_ReadBit(PMC9L, BIT3)
#define Iodd_RREG_MC_94                      TARG_ReadBit(PMC9L, BIT4)
#define Iodd_RREG_MC_95                      TARG_ReadBit(PMC9L, BIT5)
#define Iodd_RREG_MC_96                      TARG_ReadBit(PMC9L, BIT6)
#define Iodd_RREG_MC_97                      TARG_ReadBit(PMC9L, BIT7)
#define Iodd_RREG_MC_98                      TARG_ReadBit(PMC9H, BIT0)
#define Iodd_RREG_MC_99                      TARG_ReadBit(PMC9H, BIT1)
#define Iodd_RREG_MC_910                     /* read access defined but should not be used */
#define Iodd_RREG_MC_911                     /* read access defined but should not be used */
#define Iodd_RREG_MC_912                     /* read access defined but should not be used */
#define Iodd_RREG_MC_913                     TARG_ReadBit(PMC9H, BIT5)
#define Iodd_RREG_MC_914                     TARG_ReadBit(PMC9H, BIT6)
#define Iodd_RREG_MC_915                     TARG_ReadBit(PMC9H, BIT7)

#define Iodd_WREG_MC_90(Value)               TARG_WriteBit(PMC9L, BIT0, Value)
#define Iodd_WREG_MC_91(Value)               TARG_WriteBit(PMC9L, BIT1, Value)
#define Iodd_WREG_MC_92(Value)               TARG_WriteBit(PMC9L, BIT2, Value)
#define Iodd_WREG_MC_93(Value)               TARG_WriteBit(PMC9L, BIT3, Value)
#define Iodd_WREG_MC_94(Value)               TARG_WriteBit(PMC9L, BIT4, Value)
#define Iodd_WREG_MC_95(Value)               TARG_WriteBit(PMC9L, BIT5, Value)
#define Iodd_WREG_MC_96(Value)               TARG_WriteBit(PMC9L, BIT6, Value)
#define Iodd_WREG_MC_97(Value)               TARG_WriteBit(PMC9L, BIT7, Value)
#define Iodd_WREG_MC_98(Value)               TARG_WriteBit(PMC9H, BIT0, Value)
#define Iodd_WREG_MC_99(Value)               TARG_WriteBit(PMC9H, BIT1, Value)
#define Iodd_WREG_MC_910(Value)              /* write access not defined */
#define Iodd_WREG_MC_911(Value)              /* write access not defined */
#define Iodd_WREG_MC_912(Value)              /* write access not defined */
#define Iodd_WREG_MC_913(Value)              TARG_WriteBit(PMC9H, BIT5, Value)
#define Iodd_WREG_MC_914(Value)              TARG_WriteBit(PMC9H, BIT6, Value)
#define Iodd_WREG_MC_915(Value)              TARG_WriteBit(PMC9H, BIT7, Value)

#endif

#if                                          \
      defined(__NEC_V850_FJ3_F3378__)||      \
      defined(__NEC_V850_FJ3_F3379__)||      \
      defined(__NEC_V850_FJ3_F3380__)||      \
      defined(__NEC_V850_FJ3_F3381__)||      \
      defined(__NEC_V850_FJ3_F3382__)||      \
      defined(__NEC_V850_FK3_F3383__)||      \
      defined(__NEC_V850_FK3_F3384__)||      \
      defined(__NEC_V850_FK3_F3385__)

#define Iodd_RREG_MC_90                      TARG_ReadBit(PMC9L, BIT0)
#define Iodd_RREG_MC_91                      TARG_ReadBit(PMC9L, BIT1)
#define Iodd_RREG_MC_92                      TARG_ReadBit(PMC9L, BIT2)
#define Iodd_RREG_MC_93                      TARG_ReadBit(PMC9L, BIT3)
#define Iodd_RREG_MC_94                      TARG_ReadBit(PMC9L, BIT4)
#define Iodd_RREG_MC_95                      TARG_ReadBit(PMC9L, BIT5)
#define Iodd_RREG_MC_96                      TARG_ReadBit(PMC9L, BIT6)
#define Iodd_RREG_MC_97                      TARG_ReadBit(PMC9L, BIT7)
#define Iodd_RREG_MC_98                      TARG_ReadBit(PMC9H, BIT0)
#define Iodd_RREG_MC_99                      TARG_ReadBit(PMC9H, BIT1)
#define Iodd_RREG_MC_910                     TARG_ReadBit(PMC9H, BIT2)
#define Iodd_RREG_MC_911                     TARG_ReadBit(PMC9H, BIT3)
#define Iodd_RREG_MC_912                     TARG_ReadBit(PMC9H, BIT4)
#define Iodd_RREG_MC_913                     TARG_ReadBit(PMC9H, BIT5)
#define Iodd_RREG_MC_914                     TARG_ReadBit(PMC9H, BIT6)
#define Iodd_RREG_MC_915                     TARG_ReadBit(PMC9H, BIT7)

#define Iodd_WREG_MC_90(Value)               TARG_WriteBit(PMC9L, BIT0, Value)
#define Iodd_WREG_MC_91(Value)               TARG_WriteBit(PMC9L, BIT1, Value)
#define Iodd_WREG_MC_92(Value)               TARG_WriteBit(PMC9L, BIT2, Value)
#define Iodd_WREG_MC_93(Value)               TARG_WriteBit(PMC9L, BIT3, Value)
#define Iodd_WREG_MC_94(Value)               TARG_WriteBit(PMC9L, BIT4, Value)
#define Iodd_WREG_MC_95(Value)               TARG_WriteBit(PMC9L, BIT5, Value)
#define Iodd_WREG_MC_96(Value)               TARG_WriteBit(PMC9L, BIT6, Value)
#define Iodd_WREG_MC_97(Value)               TARG_WriteBit(PMC9L, BIT7, Value)
#define Iodd_WREG_MC_98(Value)               TARG_WriteBit(PMC9H, BIT0, Value)
#define Iodd_WREG_MC_99(Value)               TARG_WriteBit(PMC9H, BIT1, Value)
#define Iodd_WREG_MC_910(Value)              TARG_WriteBit(PMC9H, BIT2, Value)
#define Iodd_WREG_MC_911(Value)              TARG_WriteBit(PMC9H, BIT3, Value)
#define Iodd_WREG_MC_912(Value)              TARG_WriteBit(PMC9H, BIT4, Value)
#define Iodd_WREG_MC_913(Value)              TARG_WriteBit(PMC9H, BIT5, Value)
#define Iodd_WREG_MC_914(Value)              TARG_WriteBit(PMC9H, BIT6, Value)
#define Iodd_WREG_MC_915(Value)              TARG_WriteBit(PMC9H, BIT7, Value)

#endif

#if                                          \
      defined(__NEC_V850_FE3_F3370__)||      \
      defined(__NEC_V850_FE3_F3371__)||      \
      defined(__NEC_V850_FF3_F3372__)||      \
      defined(__NEC_V850_FF3_F3373__)||      \
      defined(__NEC_V850_FF3L_F3618__)

#define Iodd_RREG_FC_90                      TARG_ReadBit(PFC9L, BIT0)
#define Iodd_RREG_FC_91                      TARG_ReadBit(PFC9L, BIT1)
#define Iodd_RREG_FC_92                      /* read access defined but should not be used */
#define Iodd_RREG_FC_93                      /* read access defined but should not be used */
#define Iodd_RREG_FC_94                      /* read access defined but should not be used */
#define Iodd_RREG_FC_95                      /* read access defined but should not be used */
#define Iodd_RREG_FC_96                      TARG_ReadBit(PFC9L, BIT6)
#define Iodd_RREG_FC_97                      TARG_ReadBit(PFC9L, BIT7)
#define Iodd_RREG_FC_98                      TARG_ReadBit(PFC9H, BIT0)
#define Iodd_RREG_FC_99                      TARG_ReadBit(PFC9H, BIT1)
#define Iodd_RREG_FC_910                     /* read access defined but should not be used */
#define Iodd_RREG_FC_911                     /* read access defined but should not be used */
#define Iodd_RREG_FC_912                     /* read access defined but should not be used */
#define Iodd_RREG_FC_913                     TARG_ReadBit(PFC9H, BIT5)
#define Iodd_RREG_FC_914                     TARG_ReadBit(PFC9H, BIT6)
#define Iodd_RREG_FC_915                     TARG_ReadBit(PFC9H, BIT7)

#define Iodd_WREG_FC_90(Value)               TARG_WriteBit(PFC9L, BIT0, Value)
#define Iodd_WREG_FC_91(Value)               TARG_WriteBit(PFC9L, BIT1, Value)
#define Iodd_WREG_FC_92(Value)               /* write access not defined */
#define Iodd_WREG_FC_93(Value)               /* write access not defined */
#define Iodd_WREG_FC_94(Value)               /* write access not defined */
#define Iodd_WREG_FC_95(Value)               /* write access not defined */
#define Iodd_WREG_FC_96(Value)               TARG_WriteBit(PFC9L, BIT6, Value)
#define Iodd_WREG_FC_97(Value)               TARG_WriteBit(PFC9L, BIT7, Value)
#define Iodd_WREG_FC_98(Value)               TARG_WriteBit(PFC9H, BIT0, Value)
#define Iodd_WREG_FC_99(Value)               TARG_WriteBit(PFC9H, BIT1, Value)
#define Iodd_WREG_FC_910(Value)              /* write access not defined */
#define Iodd_WREG_FC_911(Value)              /* write access not defined */
#define Iodd_WREG_FC_912(Value)              /* write access not defined */
#define Iodd_WREG_FC_913(Value)              TARG_WriteBit(PFC9H, BIT5, Value)
#define Iodd_WREG_FC_914(Value)              TARG_WriteBit(PFC9H, BIT6, Value)
#define Iodd_WREG_FC_915(Value)              TARG_WriteBit(PFC9H, BIT7, Value)

#endif

#if                                          \
      defined(__NEC_V850_FG3_F3374__)||      \
      defined(__NEC_V850_FG3_F3375__)||      \
      defined(__NEC_V850_FG3_F3376__)||      \
      defined(__NEC_V850_FG3_F3377__)

#define Iodd_RREG_FC_90                      TARG_ReadBit(PFC9L, BIT0)
#define Iodd_RREG_FC_91                      TARG_ReadBit(PFC9L, BIT1)
#define Iodd_RREG_FC_92                      TARG_ReadBit(PFC9L, BIT2)
#define Iodd_RREG_FC_93                      TARG_ReadBit(PFC9L, BIT3)
#define Iodd_RREG_FC_94                      TARG_ReadBit(PFC9L, BIT4)
#define Iodd_RREG_FC_95                      TARG_ReadBit(PFC9L, BIT5)
#define Iodd_RREG_FC_96                      TARG_ReadBit(PFC9L, BIT6)
#define Iodd_RREG_FC_97                      TARG_ReadBit(PFC9L, BIT7)
#define Iodd_RREG_FC_98                      TARG_ReadBit(PFC9H, BIT0)
#define Iodd_RREG_FC_99                      TARG_ReadBit(PFC9H, BIT1)
#define Iodd_RREG_FC_910                     /* read access defined but should not be used */
#define Iodd_RREG_FC_911                     /* read access defined but should not be used */
#define Iodd_RREG_FC_912                     /* read access defined but should not be used */
#define Iodd_RREG_FC_913                     TARG_ReadBit(PFC9H, BIT5)
#define Iodd_RREG_FC_914                     TARG_ReadBit(PFC9H, BIT6)
#define Iodd_RREG_FC_915                     TARG_ReadBit(PFC9H, BIT7)

#define Iodd_WREG_FC_90(Value)               TARG_WriteBit(PFC9L, BIT0, Value)
#define Iodd_WREG_FC_91(Value)               TARG_WriteBit(PFC9L, BIT1, Value)
#define Iodd_WREG_FC_92(Value)               TARG_WriteBit(PFC9L, BIT2, Value)
#define Iodd_WREG_FC_93(Value)               TARG_WriteBit(PFC9L, BIT3, Value)
#define Iodd_WREG_FC_94(Value)               TARG_WriteBit(PFC9L, BIT4, Value)
#define Iodd_WREG_FC_95(Value)               TARG_WriteBit(PFC9L, BIT5, Value)
#define Iodd_WREG_FC_96(Value)               TARG_WriteBit(PFC9L, BIT6, Value)
#define Iodd_WREG_FC_97(Value)               TARG_WriteBit(PFC9L, BIT7, Value)
#define Iodd_WREG_FC_98(Value)               TARG_WriteBit(PFC9H, BIT0, Value)
#define Iodd_WREG_FC_99(Value)               TARG_WriteBit(PFC9H, BIT1, Value)
#define Iodd_WREG_FC_910(Value)              /* write access not defined */
#define Iodd_WREG_FC_911(Value)              /* write access not defined */
#define Iodd_WREG_FC_912(Value)              /* write access not defined */
#define Iodd_WREG_FC_913(Value)              TARG_WriteBit(PFC9H, BIT5, Value)
#define Iodd_WREG_FC_914(Value)              TARG_WriteBit(PFC9H, BIT6, Value)
#define Iodd_WREG_FC_915(Value)              TARG_WriteBit(PFC9H, BIT7, Value)

#endif

#if                                          \
      defined(__NEC_V850_FJ3_F3378__)||      \
      defined(__NEC_V850_FJ3_F3379__)||      \
      defined(__NEC_V850_FJ3_F3380__)||      \
      defined(__NEC_V850_FJ3_F3381__)||      \
      defined(__NEC_V850_FJ3_F3382__)||      \
      defined(__NEC_V850_FK3_F3383__)||      \
      defined(__NEC_V850_FK3_F3384__)||      \
      defined(__NEC_V850_FK3_F3385__)

#define Iodd_RREG_FC_90                      TARG_ReadBit(PFC9L, BIT0)
#define Iodd_RREG_FC_91                      TARG_ReadBit(PFC9L, BIT1)
#define Iodd_RREG_FC_92                      TARG_ReadBit(PFC9L, BIT2)
#define Iodd_RREG_FC_93                      TARG_ReadBit(PFC9L, BIT3)
#define Iodd_RREG_FC_94                      TARG_ReadBit(PFC9L, BIT4)
#define Iodd_RREG_FC_95                      TARG_ReadBit(PFC9L, BIT5)
#define Iodd_RREG_FC_96                      TARG_ReadBit(PFC9L, BIT6)
#define Iodd_RREG_FC_97                      TARG_ReadBit(PFC9L, BIT7)
#define Iodd_RREG_FC_98                      TARG_ReadBit(PFC9H, BIT0)
#define Iodd_RREG_FC_99                      TARG_ReadBit(PFC9H, BIT1)
#define Iodd_RREG_FC_910                     TARG_ReadBit(PFC9H, BIT2)
#define Iodd_RREG_FC_911                     TARG_ReadBit(PFC9H, BIT3)
#define Iodd_RREG_FC_912                     TARG_ReadBit(PFC9H, BIT4)
#define Iodd_RREG_FC_913                     TARG_ReadBit(PFC9H, BIT5)
#define Iodd_RREG_FC_914                     TARG_ReadBit(PFC9H, BIT6)
#define Iodd_RREG_FC_915                     TARG_ReadBit(PFC9H, BIT7)

#define Iodd_WREG_FC_90(Value)               TARG_WriteBit(PFC9L, BIT0, Value)
#define Iodd_WREG_FC_91(Value)               TARG_WriteBit(PFC9L, BIT1, Value)
#define Iodd_WREG_FC_92(Value)               TARG_WriteBit(PFC9L, BIT2, Value)
#define Iodd_WREG_FC_93(Value)               TARG_WriteBit(PFC9L, BIT3, Value)
#define Iodd_WREG_FC_94(Value)               TARG_WriteBit(PFC9L, BIT4, Value)
#define Iodd_WREG_FC_95(Value)               TARG_WriteBit(PFC9L, BIT5, Value)
#define Iodd_WREG_FC_96(Value)               TARG_WriteBit(PFC9L, BIT6, Value)
#define Iodd_WREG_FC_97(Value)               TARG_WriteBit(PFC9L, BIT7, Value)
#define Iodd_WREG_FC_98(Value)               TARG_WriteBit(PFC9H, BIT0, Value)
#define Iodd_WREG_FC_99(Value)               TARG_WriteBit(PFC9H, BIT1, Value)
#define Iodd_WREG_FC_910(Value)              TARG_WriteBit(PFC9H, BIT2, Value)
#define Iodd_WREG_FC_911(Value)              TARG_WriteBit(PFC9H, BIT3, Value)
#define Iodd_WREG_FC_912(Value)              TARG_WriteBit(PFC9H, BIT4, Value)
#define Iodd_WREG_FC_913(Value)              TARG_WriteBit(PFC9H, BIT5, Value)
#define Iodd_WREG_FC_914(Value)              TARG_WriteBit(PFC9H, BIT6, Value)
#define Iodd_WREG_FC_915(Value)              TARG_WriteBit(PFC9H, BIT7, Value)

#endif

#if                                          \
      defined(__NEC_V850_FE3_F3370__)||      \
      defined(__NEC_V850_FE3_F3371__)||      \
      defined(__NEC_V850_FF3_F3372__)||      \
      defined(__NEC_V850_FF3_F3373__)||      \
      defined(__NEC_V850_FF3L_F3618__)

#define Iodd_RREG_FCE_90                     TARG_ReadBit(PFCE9L, BIT0)
#define Iodd_RREG_FCE_91                     TARG_ReadBit(PFCE9L, BIT1)
#define Iodd_RREG_FCE_92                     /* read access defined but should not be used */
#define Iodd_RREG_FCE_93                     /* read access defined but should not be used */
#define Iodd_RREG_FCE_94                     /* read access defined but should not be used */
#define Iodd_RREG_FCE_95                     /* read access defined but should not be used */
#define Iodd_RREG_FCE_96                     TARG_ReadBit(PFCE9L, BIT6)
#define Iodd_RREG_FCE_97                     TARG_ReadBit(PFCE9L, BIT7)
#define Iodd_RREG_FCE_98                     TARG_ReadBit(PFCE9H, BIT0)
#define Iodd_RREG_FCE_99                     TARG_ReadBit(PFCE9H, BIT1)
#define Iodd_RREG_FCE_910                    /* read access defined but should not be used */
#define Iodd_RREG_FCE_911                    /* read access defined but should not be used */
#define Iodd_RREG_FCE_912                    /* read access defined but should not be used */
#define Iodd_RREG_FCE_913                    TARG_ReadBit(PFCE9H, BIT5)
#define Iodd_RREG_FCE_914                    TARG_ReadBit(PFCE9H, BIT6)
#define Iodd_RREG_FCE_915                    TARG_ReadBit(PFCE9H, BIT7)

#define Iodd_WREG_FCE_90(Value)              TARG_WriteBit(PFCE9L, BIT0, Value)
#define Iodd_WREG_FCE_91(Value)              TARG_WriteBit(PFCE9L, BIT1, Value)
#define Iodd_WREG_FCE_92(Value)              /* write access not defined */
#define Iodd_WREG_FCE_93(Value)              /* write access not defined */
#define Iodd_WREG_FCE_94(Value)              /* write access not defined */
#define Iodd_WREG_FCE_95(Value)              /* write access not defined */
#define Iodd_WREG_FCE_96(Value)              TARG_WriteBit(PFCE9L, BIT6, Value)
#define Iodd_WREG_FCE_97(Value)              TARG_WriteBit(PFCE9L, BIT7, Value)
#define Iodd_WREG_FCE_98(Value)              TARG_WriteBit(PFCE9H, BIT0, Value)
#define Iodd_WREG_FCE_99(Value)              TARG_WriteBit(PFCE9H, BIT1, Value)
#define Iodd_WREG_FCE_910(Value)             /* write access not defined */
#define Iodd_WREG_FCE_911(Value)             /* write access not defined */
#define Iodd_WREG_FCE_912(Value)             /* write access not defined */
#define Iodd_WREG_FCE_913(Value)             TARG_WriteBit(PFCE9H, BIT5, Value)
#define Iodd_WREG_FCE_914(Value)             TARG_WriteBit(PFCE9H, BIT6, Value)
#define Iodd_WREG_FCE_915(Value)             TARG_WriteBit(PFCE9H, BIT7, Value)

#endif

#if                                          \
      defined(__NEC_V850_FG3_F3374__)||      \
      defined(__NEC_V850_FG3_F3375__)||      \
      defined(__NEC_V850_FG3_F3376__)||      \
      defined(__NEC_V850_FG3_F3377__)

#define Iodd_RREG_FCE_90                     TARG_ReadBit(PFCE9L, BIT0)
#define Iodd_RREG_FCE_91                     TARG_ReadBit(PFCE9L, BIT1)
#define Iodd_RREG_FCE_92                     TARG_ReadBit(PFCE9L, BIT2)
#define Iodd_RREG_FCE_93                     TARG_ReadBit(PFCE9L, BIT3)
#define Iodd_RREG_FCE_94                     TARG_ReadBit(PFCE9L, BIT4)
#define Iodd_RREG_FCE_95                     TARG_ReadBit(PFCE9L, BIT5)
#define Iodd_RREG_FCE_96                     TARG_ReadBit(PFCE9L, BIT6)
#define Iodd_RREG_FCE_97                     TARG_ReadBit(PFCE9L, BIT7)
#define Iodd_RREG_FCE_98                     TARG_ReadBit(PFCE9H, BIT0)
#define Iodd_RREG_FCE_99                     TARG_ReadBit(PFCE9H, BIT1)
#define Iodd_RREG_FCE_910                    /* read access defined but should not be used */
#define Iodd_RREG_FCE_911                    /* read access defined but should not be used */
#define Iodd_RREG_FCE_912                    /* read access defined but should not be used */
#define Iodd_RREG_FCE_913                    TARG_ReadBit(PFCE9H, BIT5)
#define Iodd_RREG_FCE_914                    TARG_ReadBit(PFCE9H, BIT6)
#define Iodd_RREG_FCE_915                    TARG_ReadBit(PFCE9H, BIT7)

#define Iodd_WREG_FCE_90(Value)              TARG_WriteBit(PFCE9L, BIT0, Value)
#define Iodd_WREG_FCE_91(Value)              TARG_WriteBit(PFCE9L, BIT1, Value)
#define Iodd_WREG_FCE_92(Value)              TARG_WriteBit(PFCE9L, BIT2, Value)
#define Iodd_WREG_FCE_93(Value)              TARG_WriteBit(PFCE9L, BIT3, Value)
#define Iodd_WREG_FCE_94(Value)              TARG_WriteBit(PFCE9L, BIT4, Value)
#define Iodd_WREG_FCE_95(Value)              TARG_WriteBit(PFCE9L, BIT5, Value)
#define Iodd_WREG_FCE_96(Value)              TARG_WriteBit(PFCE9L, BIT6, Value)
#define Iodd_WREG_FCE_97(Value)              TARG_WriteBit(PFCE9L, BIT7, Value)
#define Iodd_WREG_FCE_98(Value)              TARG_WriteBit(PFCE9H, BIT0, Value)
#define Iodd_WREG_FCE_99(Value)              TARG_WriteBit(PFCE9H, BIT1, Value)
#define Iodd_WREG_FCE_910(Value)             /* write access not defined */
#define Iodd_WREG_FCE_911(Value)             /* write access not defined */
#define Iodd_WREG_FCE_912(Value)             /* write access not defined */
#define Iodd_WREG_FCE_913(Value)             TARG_WriteBit(PFCE9H, BIT5, Value)
#define Iodd_WREG_FCE_914(Value)             TARG_WriteBit(PFCE9H, BIT6, Value)
#define Iodd_WREG_FCE_915(Value)             TARG_WriteBit(PFCE9H, BIT7, Value)

#endif

#if                                          \
      defined(__NEC_V850_FJ3_F3378__)

#define Iodd_RREG_FCE_90                     TARG_ReadBit(PFCE9L, BIT0)
#define Iodd_RREG_FCE_91                     TARG_ReadBit(PFCE9L, BIT1)
#define Iodd_RREG_FCE_92                     TARG_ReadBit(PFCE9L, BIT2)
#define Iodd_RREG_FCE_93                     TARG_ReadBit(PFCE9L, BIT3)
#define Iodd_RREG_FCE_94                     TARG_ReadBit(PFCE9L, BIT4)
#define Iodd_RREG_FCE_95                     TARG_ReadBit(PFCE9L, BIT5)
#define Iodd_RREG_FCE_96                     TARG_ReadBit(PFCE9L, BIT6)
#define Iodd_RREG_FCE_97                     TARG_ReadBit(PFCE9L, BIT7)
#define Iodd_RREG_FCE_98                     TARG_ReadBit(PFCE9H, BIT0)
#define Iodd_RREG_FCE_99                     TARG_ReadBit(PFCE9H, BIT1)
#define Iodd_RREG_FCE_910                    TARG_ReadBit(PFCE9H, BIT2)
#define Iodd_RREG_FCE_911                    TARG_ReadBit(PFCE9H, BIT3)
#define Iodd_RREG_FCE_912                    /* read access defined but should not be used */
#define Iodd_RREG_FCE_913                    TARG_ReadBit(PFCE9H, BIT5)
#define Iodd_RREG_FCE_914                    TARG_ReadBit(PFCE9H, BIT6)
#define Iodd_RREG_FCE_915                    TARG_ReadBit(PFCE9H, BIT7)

#define Iodd_WREG_FCE_90(Value)              TARG_WriteBit(PFCE9L, BIT0, Value)
#define Iodd_WREG_FCE_91(Value)              TARG_WriteBit(PFCE9L, BIT1, Value)
#define Iodd_WREG_FCE_92(Value)              TARG_WriteBit(PFCE9L, BIT2, Value)
#define Iodd_WREG_FCE_93(Value)              TARG_WriteBit(PFCE9L, BIT3, Value)
#define Iodd_WREG_FCE_94(Value)              TARG_WriteBit(PFCE9L, BIT4, Value)
#define Iodd_WREG_FCE_95(Value)              TARG_WriteBit(PFCE9L, BIT5, Value)
#define Iodd_WREG_FCE_96(Value)              TARG_WriteBit(PFCE9L, BIT6, Value)
#define Iodd_WREG_FCE_97(Value)              TARG_WriteBit(PFCE9L, BIT7, Value)
#define Iodd_WREG_FCE_98(Value)              TARG_WriteBit(PFCE9H, BIT0, Value)
#define Iodd_WREG_FCE_99(Value)              TARG_WriteBit(PFCE9H, BIT1, Value)
#define Iodd_WREG_FCE_910(Value)             TARG_WriteBit(PFCE9H, BIT2, Value)
#define Iodd_WREG_FCE_911(Value)             TARG_WriteBit(PFCE9H, BIT3, Value)
#define Iodd_WREG_FCE_912(Value)             /* write access not defined */
#define Iodd_WREG_FCE_913(Value)             TARG_WriteBit(PFCE9H, BIT5, Value)
#define Iodd_WREG_FCE_914(Value)             TARG_WriteBit(PFCE9H, BIT6, Value)
#define Iodd_WREG_FCE_915(Value)             TARG_WriteBit(PFCE9H, BIT7, Value)

#endif

#if                                          \
      defined(__NEC_V850_FJ3_F3379__)||      \
      defined(__NEC_V850_FJ3_F3380__)||      \
      defined(__NEC_V850_FJ3_F3381__)||      \
      defined(__NEC_V850_FJ3_F3382__)||      \
      defined(__NEC_V850_FK3_F3383__)||      \
      defined(__NEC_V850_FK3_F3384__)||      \
      defined(__NEC_V850_FK3_F3385__)

#define Iodd_RREG_FCE_90                     TARG_ReadBit(PFCE9L, BIT0)
#define Iodd_RREG_FCE_91                     TARG_ReadBit(PFCE9L, BIT1)
#define Iodd_RREG_FCE_92                     TARG_ReadBit(PFCE9L, BIT2)
#define Iodd_RREG_FCE_93                     TARG_ReadBit(PFCE9L, BIT3)
#define Iodd_RREG_FCE_94                     TARG_ReadBit(PFCE9L, BIT4)
#define Iodd_RREG_FCE_95                     TARG_ReadBit(PFCE9L, BIT5)
#define Iodd_RREG_FCE_96                     TARG_ReadBit(PFCE9L, BIT6)
#define Iodd_RREG_FCE_97                     TARG_ReadBit(PFCE9L, BIT7)
#define Iodd_RREG_FCE_98                     TARG_ReadBit(PFCE9H, BIT0)
#define Iodd_RREG_FCE_99                     TARG_ReadBit(PFCE9H, BIT1)
#define Iodd_RREG_FCE_910                    TARG_ReadBit(PFCE9H, BIT2)
#define Iodd_RREG_FCE_911                    TARG_ReadBit(PFCE9H, BIT3)
#define Iodd_RREG_FCE_912                    TARG_ReadBit(PFCE9H, BIT4)
#define Iodd_RREG_FCE_913                    TARG_ReadBit(PFCE9H, BIT5)
#define Iodd_RREG_FCE_914                    TARG_ReadBit(PFCE9H, BIT6)
#define Iodd_RREG_FCE_915                    TARG_ReadBit(PFCE9H, BIT7)

#define Iodd_WREG_FCE_90(Value)              TARG_WriteBit(PFCE9L, BIT0, Value)
#define Iodd_WREG_FCE_91(Value)              TARG_WriteBit(PFCE9L, BIT1, Value)
#define Iodd_WREG_FCE_92(Value)              TARG_WriteBit(PFCE9L, BIT2, Value)
#define Iodd_WREG_FCE_93(Value)              TARG_WriteBit(PFCE9L, BIT3, Value)
#define Iodd_WREG_FCE_94(Value)              TARG_WriteBit(PFCE9L, BIT4, Value)
#define Iodd_WREG_FCE_95(Value)              TARG_WriteBit(PFCE9L, BIT5, Value)
#define Iodd_WREG_FCE_96(Value)              TARG_WriteBit(PFCE9L, BIT6, Value)
#define Iodd_WREG_FCE_97(Value)              TARG_WriteBit(PFCE9L, BIT7, Value)
#define Iodd_WREG_FCE_98(Value)              TARG_WriteBit(PFCE9H, BIT0, Value)
#define Iodd_WREG_FCE_99(Value)              TARG_WriteBit(PFCE9H, BIT1, Value)
#define Iodd_WREG_FCE_910(Value)             TARG_WriteBit(PFCE9H, BIT2, Value)
#define Iodd_WREG_FCE_911(Value)             TARG_WriteBit(PFCE9H, BIT3, Value)
#define Iodd_WREG_FCE_912(Value)             TARG_WriteBit(PFCE9H, BIT4, Value)
#define Iodd_WREG_FCE_913(Value)             TARG_WriteBit(PFCE9H, BIT5, Value)
#define Iodd_WREG_FCE_914(Value)             TARG_WriteBit(PFCE9H, BIT6, Value)
#define Iodd_WREG_FCE_915(Value)             TARG_WriteBit(PFCE9H, BIT7, Value)

#endif

#if                                          \
      defined(__NEC_V850_FE3_F3370__)||      \
      defined(__NEC_V850_FE3_F3371__)||      \
      defined(__NEC_V850_FF3_F3372__)||      \
      defined(__NEC_V850_FF3_F3373__)||      \
      defined(__NEC_V850_FF3L_F3618__)

#define Iodd_RREG_PU_90                      TARG_ReadBit(PU9L, BIT0)
#define Iodd_RREG_PU_91                      TARG_ReadBit(PU9L, BIT1)
#define Iodd_RREG_PU_92                      /* read access defined but should not be used */
#define Iodd_RREG_PU_93                      /* read access defined but should not be used */
#define Iodd_RREG_PU_94                      /* read access defined but should not be used */
#define Iodd_RREG_PU_95                      /* read access defined but should not be used */
#define Iodd_RREG_PU_96                      TARG_ReadBit(PU9L, BIT6)
#define Iodd_RREG_PU_97                      TARG_ReadBit(PU9L, BIT7)
#define Iodd_RREG_PU_98                      TARG_ReadBit(PU9H, BIT0)
#define Iodd_RREG_PU_99                      TARG_ReadBit(PU9H, BIT1)
#define Iodd_RREG_PU_910                     /* read access defined but should not be used */
#define Iodd_RREG_PU_911                     /* read access defined but should not be used */
#define Iodd_RREG_PU_912                     /* read access defined but should not be used */
#define Iodd_RREG_PU_913                     TARG_ReadBit(PU9H, BIT5)
#define Iodd_RREG_PU_914                     TARG_ReadBit(PU9H, BIT6)
#define Iodd_RREG_PU_915                     TARG_ReadBit(PU9H, BIT7)

#define Iodd_WREG_PU_90(Value)               TARG_WriteBit(PU9L, BIT0, Value)
#define Iodd_WREG_PU_91(Value)               TARG_WriteBit(PU9L, BIT1, Value)
#define Iodd_WREG_PU_92(Value)               /* write access not defined */
#define Iodd_WREG_PU_93(Value)               /* write access not defined */
#define Iodd_WREG_PU_94(Value)               /* write access not defined */
#define Iodd_WREG_PU_95(Value)               /* write access not defined */
#define Iodd_WREG_PU_96(Value)               TARG_WriteBit(PU9L, BIT6, Value)
#define Iodd_WREG_PU_97(Value)               TARG_WriteBit(PU9L, BIT7, Value)
#define Iodd_WREG_PU_98(Value)               TARG_WriteBit(PU9H, BIT0, Value)
#define Iodd_WREG_PU_99(Value)               TARG_WriteBit(PU9H, BIT1, Value)
#define Iodd_WREG_PU_910(Value)              /* write access not defined */
#define Iodd_WREG_PU_911(Value)              /* write access not defined */
#define Iodd_WREG_PU_912(Value)              /* write access not defined */
#define Iodd_WREG_PU_913(Value)              TARG_WriteBit(PU9H, BIT5, Value)
#define Iodd_WREG_PU_914(Value)              TARG_WriteBit(PU9H, BIT6, Value)
#define Iodd_WREG_PU_915(Value)              TARG_WriteBit(PU9H, BIT7, Value)

#endif

#if                                          \
      defined(__NEC_V850_FG3_F3374__)||      \
      defined(__NEC_V850_FG3_F3375__)||      \
      defined(__NEC_V850_FG3_F3376__)||      \
      defined(__NEC_V850_FG3_F3377__)||      \
      defined(__NEC_V850_FJ3_F3378__)||      \
      defined(__NEC_V850_FJ3_F3379__)||      \
      defined(__NEC_V850_FJ3_F3380__)||      \
      defined(__NEC_V850_FJ3_F3381__)||      \
      defined(__NEC_V850_FJ3_F3382__)||      \
      defined(__NEC_V850_FK3_F3383__)||      \
      defined(__NEC_V850_FK3_F3384__)||      \
      defined(__NEC_V850_FK3_F3385__)

#define Iodd_RREG_PU_90                      TARG_ReadBit(PU9L, BIT0)
#define Iodd_RREG_PU_91                      TARG_ReadBit(PU9L, BIT1)
#define Iodd_RREG_PU_92                      TARG_ReadBit(PU9L, BIT2)
#define Iodd_RREG_PU_93                      TARG_ReadBit(PU9L, BIT3)
#define Iodd_RREG_PU_94                      TARG_ReadBit(PU9L, BIT4)
#define Iodd_RREG_PU_95                      TARG_ReadBit(PU9L, BIT5)
#define Iodd_RREG_PU_96                      TARG_ReadBit(PU9L, BIT6)
#define Iodd_RREG_PU_97                      TARG_ReadBit(PU9L, BIT7)
#define Iodd_RREG_PU_98                      TARG_ReadBit(PU9H, BIT0)
#define Iodd_RREG_PU_99                      TARG_ReadBit(PU9H, BIT1)
#define Iodd_RREG_PU_910                     TARG_ReadBit(PU9H, BIT2)
#define Iodd_RREG_PU_911                     TARG_ReadBit(PU9H, BIT3)
#define Iodd_RREG_PU_912                     TARG_ReadBit(PU9H, BIT4)
#define Iodd_RREG_PU_913                     TARG_ReadBit(PU9H, BIT5)
#define Iodd_RREG_PU_914                     TARG_ReadBit(PU9H, BIT6)
#define Iodd_RREG_PU_915                     TARG_ReadBit(PU9H, BIT7)

#define Iodd_WREG_PU_90(Value)               TARG_WriteBit(PU9L, BIT0, Value)
#define Iodd_WREG_PU_91(Value)               TARG_WriteBit(PU9L, BIT1, Value)
#define Iodd_WREG_PU_92(Value)               TARG_WriteBit(PU9L, BIT2, Value)
#define Iodd_WREG_PU_93(Value)               TARG_WriteBit(PU9L, BIT3, Value)
#define Iodd_WREG_PU_94(Value)               TARG_WriteBit(PU9L, BIT4, Value)
#define Iodd_WREG_PU_95(Value)               TARG_WriteBit(PU9L, BIT5, Value)
#define Iodd_WREG_PU_96(Value)               TARG_WriteBit(PU9L, BIT6, Value)
#define Iodd_WREG_PU_97(Value)               TARG_WriteBit(PU9L, BIT7, Value)
#define Iodd_WREG_PU_98(Value)               TARG_WriteBit(PU9H, BIT0, Value)
#define Iodd_WREG_PU_99(Value)               TARG_WriteBit(PU9H, BIT1, Value)
#define Iodd_WREG_PU_910(Value)              TARG_WriteBit(PU9H, BIT2, Value)
#define Iodd_WREG_PU_911(Value)              TARG_WriteBit(PU9H, BIT3, Value)
#define Iodd_WREG_PU_912(Value)              TARG_WriteBit(PU9H, BIT4, Value)
#define Iodd_WREG_PU_913(Value)              TARG_WriteBit(PU9H, BIT5, Value)
#define Iodd_WREG_PU_914(Value)              TARG_WriteBit(PU9H, BIT6, Value)
#define Iodd_WREG_PU_915(Value)              TARG_WriteBit(PU9H, BIT7, Value)

#endif

#if                                          \
      defined(__NEC_V850_Fx3__)

#define Iodd_RREG_PF_98                      /* read access defined but should not be used */
#define Iodd_RREG_PF_99                      /* read access defined but should not be used */
#define Iodd_RREG_PF_910                     /* read access defined but should not be used */
#define Iodd_RREG_PF_911                     /* read access defined but should not be used */
#define Iodd_RREG_PF_912                     /* read access defined but should not be used */
#define Iodd_RREG_PF_913                     /* read access defined but should not be used */
#define Iodd_RREG_PF_914                     TARG_ReadBit(PF9H, BIT6)
#define Iodd_RREG_PF_915                     TARG_ReadBit(PF9H, BIT7)

#define Iodd_WREG_PF_98(Value)               /* write access not defined */
#define Iodd_WREG_PF_99(Value)               /* write access not defined */
#define Iodd_WREG_PF_910(Value)              /* write access not defined */
#define Iodd_WREG_PF_911(Value)              /* write access not defined */
#define Iodd_WREG_PF_912(Value)              /* write access not defined */
#define Iodd_WREG_PF_913(Value)              /* write access not defined */
#define Iodd_WREG_PF_914(Value)              TARG_WriteBit(PF9H, BIT6, Value)
#define Iodd_WREG_PF_915(Value)              TARG_WriteBit(PF9H, BIT7, Value)

#endif

#if                                          \
      defined(__NEC_V850_FE3_F3370__)||      \
      defined(__NEC_V850_FE3_F3371__)||      \
      defined(__NEC_V850_FF3_F3372__)||      \
      defined(__NEC_V850_FF3_F3373__)||      \
      defined(__NEC_V850_FG3_F3374__)||      \
      defined(__NEC_V850_FG3_F3375__)||      \
      defined(__NEC_V850_FG3_F3376__)||      \
      defined(__NEC_V850_FG3_F3377__)||      \
      defined(__NEC_V850_FJ3_F3378__)||      \
      defined(__NEC_V850_FJ3_F3379__)||      \
      defined(__NEC_V850_FJ3_F3380__)||      \
      defined(__NEC_V850_FJ3_F3381__)||      \
      defined(__NEC_V850_FJ3_F3382__)||      \
      defined(__NEC_V850_FK3_F3383__)||      \
      defined(__NEC_V850_FK3_F3384__)||      \
      defined(__NEC_V850_FK3_F3385__)||      \
      defined(__NEC_V850_FF3L_F3618__)

#define Iodd_RREG_PF_90                      /* register undefined */
#define Iodd_RREG_PF_91                      /* register undefined */
#define Iodd_RREG_PF_92                      /* register undefined */
#define Iodd_RREG_PF_93                      /* register undefined */
#define Iodd_RREG_PF_94                      /* register undefined */
#define Iodd_RREG_PF_95                      /* register undefined */
#define Iodd_RREG_PF_96                      /* register undefined */
#define Iodd_RREG_PF_97                      /* register undefined */

#define Iodd_WREG_PF_90(Value)               /* register undefined */
#define Iodd_WREG_PF_91(Value)               /* register undefined */
#define Iodd_WREG_PF_92(Value)               /* register undefined */
#define Iodd_WREG_PF_93(Value)               /* register undefined */
#define Iodd_WREG_PF_94(Value)               /* register undefined */
#define Iodd_WREG_PF_95(Value)               /* register undefined */
#define Iodd_WREG_PF_96(Value)               /* register undefined */
#define Iodd_WREG_PF_97(Value)               /* register undefined */

#endif

/* Definitions PORT 12 */

#if                                          \
      defined(__NEC_V850_FJ3_F3378__)||      \
      defined(__NEC_V850_FJ3_F3379__)||      \
      defined(__NEC_V850_FJ3_F3380__)||      \
      defined(__NEC_V850_FJ3_F3381__)||      \
      defined(__NEC_V850_FJ3_F3382__)||      \
      defined(__NEC_V850_FK3_F3383__)||      \
      defined(__NEC_V850_FK3_F3384__)||      \
      defined(__NEC_V850_FK3_F3385__)

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
      defined(__NEC_V850_FJ3_F3378__)||      \
      defined(__NEC_V850_FJ3_F3379__)||      \
      defined(__NEC_V850_FJ3_F3380__)||      \
      defined(__NEC_V850_FJ3_F3381__)||      \
      defined(__NEC_V850_FJ3_F3382__)||      \
      defined(__NEC_V850_FK3_F3383__)||      \
      defined(__NEC_V850_FK3_F3384__)||      \
      defined(__NEC_V850_FK3_F3385__)

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
      defined(__NEC_V850_FJ3_F3378__)||      \
      defined(__NEC_V850_FJ3_F3379__)||      \
      defined(__NEC_V850_FJ3_F3380__)||      \
      defined(__NEC_V850_FJ3_F3381__)||      \
      defined(__NEC_V850_FJ3_F3382__)||      \
      defined(__NEC_V850_FK3_F3383__)||      \
      defined(__NEC_V850_FK3_F3384__)||      \
      defined(__NEC_V850_FK3_F3385__)

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
      defined(__NEC_V850_FE3_F3370__)||      \
      defined(__NEC_V850_FE3_F3371__)||      \
      defined(__NEC_V850_FF3_F3372__)||      \
      defined(__NEC_V850_FF3_F3373__)||      \
      defined(__NEC_V850_FG3_F3374__)||      \
      defined(__NEC_V850_FG3_F3375__)||      \
      defined(__NEC_V850_FG3_F3376__)||      \
      defined(__NEC_V850_FG3_F3377__)||      \
      defined(__NEC_V850_FF3L_F3618__)

#define Iodd_RREG_P_120                      /* register undefined */
#define Iodd_RREG_P_121                      /* register undefined */
#define Iodd_RREG_P_122                      /* register undefined */
#define Iodd_RREG_P_123                      /* register undefined */
#define Iodd_RREG_P_124                      /* register undefined */
#define Iodd_RREG_P_125                      /* register undefined */
#define Iodd_RREG_P_126                      /* register undefined */
#define Iodd_RREG_P_127                      /* register undefined */

#define Iodd_WREG_P_120(Value)               /* register undefined */
#define Iodd_WREG_P_121(Value)               /* register undefined */
#define Iodd_WREG_P_122(Value)               /* register undefined */
#define Iodd_WREG_P_123(Value)               /* register undefined */
#define Iodd_WREG_P_124(Value)               /* register undefined */
#define Iodd_WREG_P_125(Value)               /* register undefined */
#define Iodd_WREG_P_126(Value)               /* register undefined */
#define Iodd_WREG_P_127(Value)               /* register undefined */

#endif

#if                                          \
      defined(__NEC_V850_FE3_F3370__)||      \
      defined(__NEC_V850_FE3_F3371__)||      \
      defined(__NEC_V850_FF3_F3372__)||      \
      defined(__NEC_V850_FF3_F3373__)||      \
      defined(__NEC_V850_FG3_F3374__)||      \
      defined(__NEC_V850_FG3_F3375__)||      \
      defined(__NEC_V850_FG3_F3376__)||      \
      defined(__NEC_V850_FG3_F3377__)||      \
      defined(__NEC_V850_FF3L_F3618__)

#define Iodd_RREG_M_120                      /* register undefined */
#define Iodd_RREG_M_121                      /* register undefined */
#define Iodd_RREG_M_122                      /* register undefined */
#define Iodd_RREG_M_123                      /* register undefined */
#define Iodd_RREG_M_124                      /* register undefined */
#define Iodd_RREG_M_125                      /* register undefined */
#define Iodd_RREG_M_126                      /* register undefined */
#define Iodd_RREG_M_127                      /* register undefined */

#define Iodd_WREG_M_120(Value)               /* register undefined */
#define Iodd_WREG_M_121(Value)               /* register undefined */
#define Iodd_WREG_M_122(Value)               /* register undefined */
#define Iodd_WREG_M_123(Value)               /* register undefined */
#define Iodd_WREG_M_124(Value)               /* register undefined */
#define Iodd_WREG_M_125(Value)               /* register undefined */
#define Iodd_WREG_M_126(Value)               /* register undefined */
#define Iodd_WREG_M_127(Value)               /* register undefined */

#endif

#if                                          \
      defined(__NEC_V850_FE3_F3370__)||      \
      defined(__NEC_V850_FE3_F3371__)||      \
      defined(__NEC_V850_FF3_F3372__)||      \
      defined(__NEC_V850_FF3_F3373__)||      \
      defined(__NEC_V850_FG3_F3374__)||      \
      defined(__NEC_V850_FG3_F3375__)||      \
      defined(__NEC_V850_FG3_F3376__)||      \
      defined(__NEC_V850_FG3_F3377__)||      \
      defined(__NEC_V850_FF3L_F3618__)

#define Iodd_RREG_MC_120                     /* register undefined */
#define Iodd_RREG_MC_121                     /* register undefined */
#define Iodd_RREG_MC_122                     /* register undefined */
#define Iodd_RREG_MC_123                     /* register undefined */
#define Iodd_RREG_MC_124                     /* register undefined */
#define Iodd_RREG_MC_125                     /* register undefined */
#define Iodd_RREG_MC_126                     /* register undefined */
#define Iodd_RREG_MC_127                     /* register undefined */

#define Iodd_WREG_MC_120(Value)              /* register undefined */
#define Iodd_WREG_MC_121(Value)              /* register undefined */
#define Iodd_WREG_MC_122(Value)              /* register undefined */
#define Iodd_WREG_MC_123(Value)              /* register undefined */
#define Iodd_WREG_MC_124(Value)              /* register undefined */
#define Iodd_WREG_MC_125(Value)              /* register undefined */
#define Iodd_WREG_MC_126(Value)              /* register undefined */
#define Iodd_WREG_MC_127(Value)              /* register undefined */

#endif

#if                                          \
      defined(__NEC_V850_Fx3__)

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
      defined(__NEC_V850_Fx3__)

#define Iodd_RREG_FCE_120                    /* register undefined */
#define Iodd_RREG_FCE_121                    /* register undefined */
#define Iodd_RREG_FCE_122                    /* register undefined */
#define Iodd_RREG_FCE_123                    /* register undefined */
#define Iodd_RREG_FCE_124                    /* register undefined */
#define Iodd_RREG_FCE_125                    /* register undefined */
#define Iodd_RREG_FCE_126                    /* register undefined */
#define Iodd_RREG_FCE_127                    /* register undefined */

#define Iodd_WREG_FCE_120(Value)             /* register undefined */
#define Iodd_WREG_FCE_121(Value)             /* register undefined */
#define Iodd_WREG_FCE_122(Value)             /* register undefined */
#define Iodd_WREG_FCE_123(Value)             /* register undefined */
#define Iodd_WREG_FCE_124(Value)             /* register undefined */
#define Iodd_WREG_FCE_125(Value)             /* register undefined */
#define Iodd_WREG_FCE_126(Value)             /* register undefined */
#define Iodd_WREG_FCE_127(Value)             /* register undefined */

#endif

#if                                          \
      defined(__NEC_V850_Fx3__)

#define Iodd_RREG_PU_120                     /* register undefined */
#define Iodd_RREG_PU_121                     /* register undefined */
#define Iodd_RREG_PU_122                     /* register undefined */
#define Iodd_RREG_PU_123                     /* register undefined */
#define Iodd_RREG_PU_124                     /* register undefined */
#define Iodd_RREG_PU_125                     /* register undefined */
#define Iodd_RREG_PU_126                     /* register undefined */
#define Iodd_RREG_PU_127                     /* register undefined */

#define Iodd_WREG_PU_120(Value)              /* register undefined */
#define Iodd_WREG_PU_121(Value)              /* register undefined */
#define Iodd_WREG_PU_122(Value)              /* register undefined */
#define Iodd_WREG_PU_123(Value)              /* register undefined */
#define Iodd_WREG_PU_124(Value)              /* register undefined */
#define Iodd_WREG_PU_125(Value)              /* register undefined */
#define Iodd_WREG_PU_126(Value)              /* register undefined */
#define Iodd_WREG_PU_127(Value)              /* register undefined */

#endif

#if                                          \
      defined(__NEC_V850_Fx3__)

#define Iodd_RREG_PF_120                     /* register undefined */
#define Iodd_RREG_PF_121                     /* register undefined */
#define Iodd_RREG_PF_122                     /* register undefined */
#define Iodd_RREG_PF_123                     /* register undefined */
#define Iodd_RREG_PF_124                     /* register undefined */
#define Iodd_RREG_PF_125                     /* register undefined */
#define Iodd_RREG_PF_126                     /* register undefined */
#define Iodd_RREG_PF_127                     /* register undefined */

#define Iodd_WREG_PF_120(Value)              /* register undefined */
#define Iodd_WREG_PF_121(Value)              /* register undefined */
#define Iodd_WREG_PF_122(Value)              /* register undefined */
#define Iodd_WREG_PF_123(Value)              /* register undefined */
#define Iodd_WREG_PF_124(Value)              /* register undefined */
#define Iodd_WREG_PF_125(Value)              /* register undefined */
#define Iodd_WREG_PF_126(Value)              /* register undefined */
#define Iodd_WREG_PF_127(Value)              /* register undefined */

#endif

/* Definitions PORT 15 */

#if                                          \
      defined(__NEC_V850_FK3_F3383__)||      \
      defined(__NEC_V850_FK3_F3384__)||      \
      defined(__NEC_V850_FK3_F3385__)

#define Iodd_RREG_P_150                      TARG_ReadBit(P15, BIT0)
#define Iodd_RREG_P_151                      TARG_ReadBit(P15, BIT1)
#define Iodd_RREG_P_152                      TARG_ReadBit(P15, BIT2)
#define Iodd_RREG_P_153                      TARG_ReadBit(P15, BIT3)
#define Iodd_RREG_P_154                      TARG_ReadBit(P15, BIT4)
#define Iodd_RREG_P_155                      TARG_ReadBit(P15, BIT5)
#define Iodd_RREG_P_156                      TARG_ReadBit(P15, BIT6)
#define Iodd_RREG_P_157                      TARG_ReadBit(P15, BIT7)

#define Iodd_WREG_P_150(Value)               TARG_WriteBit(P15, BIT0, Value)
#define Iodd_WREG_P_151(Value)               TARG_WriteBit(P15, BIT1, Value)
#define Iodd_WREG_P_152(Value)               TARG_WriteBit(P15, BIT2, Value)
#define Iodd_WREG_P_153(Value)               TARG_WriteBit(P15, BIT3, Value)
#define Iodd_WREG_P_154(Value)               TARG_WriteBit(P15, BIT4, Value)
#define Iodd_WREG_P_155(Value)               TARG_WriteBit(P15, BIT5, Value)
#define Iodd_WREG_P_156(Value)               TARG_WriteBit(P15, BIT6, Value)
#define Iodd_WREG_P_157(Value)               TARG_WriteBit(P15, BIT7, Value)

#endif

#if                                          \
      defined(__NEC_V850_FK3_F3383__)||      \
      defined(__NEC_V850_FK3_F3384__)||      \
      defined(__NEC_V850_FK3_F3385__)

#define Iodd_RREG_M_150                      TARG_ReadBit(PM15, BIT0)
#define Iodd_RREG_M_151                      TARG_ReadBit(PM15, BIT1)
#define Iodd_RREG_M_152                      TARG_ReadBit(PM15, BIT2)
#define Iodd_RREG_M_153                      TARG_ReadBit(PM15, BIT3)
#define Iodd_RREG_M_154                      TARG_ReadBit(PM15, BIT4)
#define Iodd_RREG_M_155                      TARG_ReadBit(PM15, BIT5)
#define Iodd_RREG_M_156                      TARG_ReadBit(PM15, BIT6)
#define Iodd_RREG_M_157                      TARG_ReadBit(PM15, BIT7)

#define Iodd_WREG_M_150(Value)               TARG_WriteBit(PM15, BIT0, Value)
#define Iodd_WREG_M_151(Value)               TARG_WriteBit(PM15, BIT1, Value)
#define Iodd_WREG_M_152(Value)               TARG_WriteBit(PM15, BIT2, Value)
#define Iodd_WREG_M_153(Value)               TARG_WriteBit(PM15, BIT3, Value)
#define Iodd_WREG_M_154(Value)               TARG_WriteBit(PM15, BIT4, Value)
#define Iodd_WREG_M_155(Value)               TARG_WriteBit(PM15, BIT5, Value)
#define Iodd_WREG_M_156(Value)               TARG_WriteBit(PM15, BIT6, Value)
#define Iodd_WREG_M_157(Value)               TARG_WriteBit(PM15, BIT7, Value)

#endif

#if                                          \
      defined(__NEC_V850_FK3_F3383__)||      \
      defined(__NEC_V850_FK3_F3384__)||      \
      defined(__NEC_V850_FK3_F3385__)

#define Iodd_RREG_MC_150                     TARG_ReadBit(PMC15, BIT0)
#define Iodd_RREG_MC_151                     TARG_ReadBit(PMC15, BIT1)
#define Iodd_RREG_MC_152                     TARG_ReadBit(PMC15, BIT2)
#define Iodd_RREG_MC_153                     TARG_ReadBit(PMC15, BIT3)
#define Iodd_RREG_MC_154                     TARG_ReadBit(PMC15, BIT4)
#define Iodd_RREG_MC_155                     TARG_ReadBit(PMC15, BIT5)
#define Iodd_RREG_MC_156                     TARG_ReadBit(PMC15, BIT6)
#define Iodd_RREG_MC_157                     TARG_ReadBit(PMC15, BIT7)

#define Iodd_WREG_MC_150(Value)              TARG_WriteBit(PMC15, BIT0, Value)
#define Iodd_WREG_MC_151(Value)              TARG_WriteBit(PMC15, BIT1, Value)
#define Iodd_WREG_MC_152(Value)              TARG_WriteBit(PMC15, BIT2, Value)
#define Iodd_WREG_MC_153(Value)              TARG_WriteBit(PMC15, BIT3, Value)
#define Iodd_WREG_MC_154(Value)              TARG_WriteBit(PMC15, BIT4, Value)
#define Iodd_WREG_MC_155(Value)              TARG_WriteBit(PMC15, BIT5, Value)
#define Iodd_WREG_MC_156(Value)              TARG_WriteBit(PMC15, BIT6, Value)
#define Iodd_WREG_MC_157(Value)              TARG_WriteBit(PMC15, BIT7, Value)

#endif

#if                                          \
      defined(__NEC_V850_FK3_F3383__)||      \
      defined(__NEC_V850_FK3_F3384__)||      \
      defined(__NEC_V850_FK3_F3385__)

#define Iodd_RREG_FC_150                     TARG_ReadBit(PFC15, BIT0)
#define Iodd_RREG_FC_151                     TARG_ReadBit(PFC15, BIT1)
#define Iodd_RREG_FC_152                     TARG_ReadBit(PFC15, BIT2)
#define Iodd_RREG_FC_153                     TARG_ReadBit(PFC15, BIT3)
#define Iodd_RREG_FC_154                     TARG_ReadBit(PFC15, BIT4)
#define Iodd_RREG_FC_155                     TARG_ReadBit(PFC15, BIT5)
#define Iodd_RREG_FC_156                     /* read access defined but should not be used */
#define Iodd_RREG_FC_157                     /* read access defined but should not be used */

#define Iodd_WREG_FC_150(Value)              TARG_WriteBit(PFC15, BIT0, Value)
#define Iodd_WREG_FC_151(Value)              TARG_WriteBit(PFC15, BIT1, Value)
#define Iodd_WREG_FC_152(Value)              TARG_WriteBit(PFC15, BIT2, Value)
#define Iodd_WREG_FC_153(Value)              TARG_WriteBit(PFC15, BIT3, Value)
#define Iodd_WREG_FC_154(Value)              TARG_WriteBit(PFC15, BIT4, Value)
#define Iodd_WREG_FC_155(Value)              TARG_WriteBit(PFC15, BIT5, Value)
#define Iodd_WREG_FC_156(Value)              /* write access not defined */
#define Iodd_WREG_FC_157(Value)              /* write access not defined */

#endif

#if                                          \
      defined(__NEC_V850_FK3_F3383__)||      \
      defined(__NEC_V850_FK3_F3384__)||      \
      defined(__NEC_V850_FK3_F3385__)

#define Iodd_RREG_PU_150                     TARG_ReadBit(PU15, BIT0)
#define Iodd_RREG_PU_151                     TARG_ReadBit(PU15, BIT1)
#define Iodd_RREG_PU_152                     TARG_ReadBit(PU15, BIT2)
#define Iodd_RREG_PU_153                     TARG_ReadBit(PU15, BIT3)
#define Iodd_RREG_PU_154                     TARG_ReadBit(PU15, BIT4)
#define Iodd_RREG_PU_155                     TARG_ReadBit(PU15, BIT5)
#define Iodd_RREG_PU_156                     TARG_ReadBit(PU15, BIT6)
#define Iodd_RREG_PU_157                     TARG_ReadBit(PU15, BIT7)

#define Iodd_WREG_PU_150(Value)              TARG_WriteBit(PU15, BIT0, Value)
#define Iodd_WREG_PU_151(Value)              TARG_WriteBit(PU15, BIT1, Value)
#define Iodd_WREG_PU_152(Value)              TARG_WriteBit(PU15, BIT2, Value)
#define Iodd_WREG_PU_153(Value)              TARG_WriteBit(PU15, BIT3, Value)
#define Iodd_WREG_PU_154(Value)              TARG_WriteBit(PU15, BIT4, Value)
#define Iodd_WREG_PU_155(Value)              TARG_WriteBit(PU15, BIT5, Value)
#define Iodd_WREG_PU_156(Value)              TARG_WriteBit(PU15, BIT6, Value)
#define Iodd_WREG_PU_157(Value)              TARG_WriteBit(PU15, BIT7, Value)

#endif

#if                                          \
      defined(__NEC_V850_FE3_F3370__)||      \
      defined(__NEC_V850_FE3_F3371__)||      \
      defined(__NEC_V850_FF3_F3372__)||      \
      defined(__NEC_V850_FF3_F3373__)||      \
      defined(__NEC_V850_FG3_F3374__)||      \
      defined(__NEC_V850_FG3_F3375__)||      \
      defined(__NEC_V850_FG3_F3376__)||      \
      defined(__NEC_V850_FG3_F3377__)||      \
      defined(__NEC_V850_FJ3_F3378__)||      \
      defined(__NEC_V850_FJ3_F3379__)||      \
      defined(__NEC_V850_FJ3_F3380__)||      \
      defined(__NEC_V850_FJ3_F3381__)||      \
      defined(__NEC_V850_FJ3_F3382__)||      \
      defined(__NEC_V850_FF3L_F3618__)

#define Iodd_RREG_P_150                      /* register undefined */
#define Iodd_RREG_P_151                      /* register undefined */
#define Iodd_RREG_P_152                      /* register undefined */
#define Iodd_RREG_P_153                      /* register undefined */
#define Iodd_RREG_P_154                      /* register undefined */
#define Iodd_RREG_P_155                      /* register undefined */
#define Iodd_RREG_P_156                      /* register undefined */
#define Iodd_RREG_P_157                      /* register undefined */

#define Iodd_WREG_P_150(Value)               /* register undefined */
#define Iodd_WREG_P_151(Value)               /* register undefined */
#define Iodd_WREG_P_152(Value)               /* register undefined */
#define Iodd_WREG_P_153(Value)               /* register undefined */
#define Iodd_WREG_P_154(Value)               /* register undefined */
#define Iodd_WREG_P_155(Value)               /* register undefined */
#define Iodd_WREG_P_156(Value)               /* register undefined */
#define Iodd_WREG_P_157(Value)               /* register undefined */

#endif

#if                                          \
      defined(__NEC_V850_FE3_F3370__)||      \
      defined(__NEC_V850_FE3_F3371__)||      \
      defined(__NEC_V850_FF3_F3372__)||      \
      defined(__NEC_V850_FF3_F3373__)||      \
      defined(__NEC_V850_FG3_F3374__)||      \
      defined(__NEC_V850_FG3_F3375__)||      \
      defined(__NEC_V850_FG3_F3376__)||      \
      defined(__NEC_V850_FG3_F3377__)||      \
      defined(__NEC_V850_FJ3_F3378__)||      \
      defined(__NEC_V850_FJ3_F3379__)||      \
      defined(__NEC_V850_FJ3_F3380__)||      \
      defined(__NEC_V850_FJ3_F3381__)||      \
      defined(__NEC_V850_FJ3_F3382__)||      \
      defined(__NEC_V850_FF3L_F3618__)

#define Iodd_RREG_M_150                      /* register undefined */
#define Iodd_RREG_M_151                      /* register undefined */
#define Iodd_RREG_M_152                      /* register undefined */
#define Iodd_RREG_M_153                      /* register undefined */
#define Iodd_RREG_M_154                      /* register undefined */
#define Iodd_RREG_M_155                      /* register undefined */
#define Iodd_RREG_M_156                      /* register undefined */
#define Iodd_RREG_M_157                      /* register undefined */

#define Iodd_WREG_M_150(Value)               /* register undefined */
#define Iodd_WREG_M_151(Value)               /* register undefined */
#define Iodd_WREG_M_152(Value)               /* register undefined */
#define Iodd_WREG_M_153(Value)               /* register undefined */
#define Iodd_WREG_M_154(Value)               /* register undefined */
#define Iodd_WREG_M_155(Value)               /* register undefined */
#define Iodd_WREG_M_156(Value)               /* register undefined */
#define Iodd_WREG_M_157(Value)               /* register undefined */

#endif

#if                                          \
      defined(__NEC_V850_FE3_F3370__)||      \
      defined(__NEC_V850_FE3_F3371__)||      \
      defined(__NEC_V850_FF3_F3372__)||      \
      defined(__NEC_V850_FF3_F3373__)||      \
      defined(__NEC_V850_FG3_F3374__)||      \
      defined(__NEC_V850_FG3_F3375__)||      \
      defined(__NEC_V850_FG3_F3376__)||      \
      defined(__NEC_V850_FG3_F3377__)||      \
      defined(__NEC_V850_FJ3_F3378__)||      \
      defined(__NEC_V850_FJ3_F3379__)||      \
      defined(__NEC_V850_FJ3_F3380__)||      \
      defined(__NEC_V850_FJ3_F3381__)||      \
      defined(__NEC_V850_FJ3_F3382__)||      \
      defined(__NEC_V850_FF3L_F3618__)

#define Iodd_RREG_MC_150                     /* register undefined */
#define Iodd_RREG_MC_151                     /* register undefined */
#define Iodd_RREG_MC_152                     /* register undefined */
#define Iodd_RREG_MC_153                     /* register undefined */
#define Iodd_RREG_MC_154                     /* register undefined */
#define Iodd_RREG_MC_155                     /* register undefined */
#define Iodd_RREG_MC_156                     /* register undefined */
#define Iodd_RREG_MC_157                     /* register undefined */

#define Iodd_WREG_MC_150(Value)              /* register undefined */
#define Iodd_WREG_MC_151(Value)              /* register undefined */
#define Iodd_WREG_MC_152(Value)              /* register undefined */
#define Iodd_WREG_MC_153(Value)              /* register undefined */
#define Iodd_WREG_MC_154(Value)              /* register undefined */
#define Iodd_WREG_MC_155(Value)              /* register undefined */
#define Iodd_WREG_MC_156(Value)              /* register undefined */
#define Iodd_WREG_MC_157(Value)              /* register undefined */

#endif

#if                                          \
      defined(__NEC_V850_FE3_F3370__)||      \
      defined(__NEC_V850_FE3_F3371__)||      \
      defined(__NEC_V850_FF3_F3372__)||      \
      defined(__NEC_V850_FF3_F3373__)||      \
      defined(__NEC_V850_FG3_F3374__)||      \
      defined(__NEC_V850_FG3_F3375__)||      \
      defined(__NEC_V850_FG3_F3376__)||      \
      defined(__NEC_V850_FG3_F3377__)||      \
      defined(__NEC_V850_FJ3_F3378__)||      \
      defined(__NEC_V850_FJ3_F3379__)||      \
      defined(__NEC_V850_FJ3_F3380__)||      \
      defined(__NEC_V850_FJ3_F3381__)||      \
      defined(__NEC_V850_FJ3_F3382__)||      \
      defined(__NEC_V850_FF3L_F3618__)

#define Iodd_RREG_FC_150                     /* register undefined */
#define Iodd_RREG_FC_151                     /* register undefined */
#define Iodd_RREG_FC_152                     /* register undefined */
#define Iodd_RREG_FC_153                     /* register undefined */
#define Iodd_RREG_FC_154                     /* register undefined */
#define Iodd_RREG_FC_155                     /* register undefined */
#define Iodd_RREG_FC_156                     /* register undefined */
#define Iodd_RREG_FC_157                     /* register undefined */

#define Iodd_WREG_FC_150(Value)              /* register undefined */
#define Iodd_WREG_FC_151(Value)              /* register undefined */
#define Iodd_WREG_FC_152(Value)              /* register undefined */
#define Iodd_WREG_FC_153(Value)              /* register undefined */
#define Iodd_WREG_FC_154(Value)              /* register undefined */
#define Iodd_WREG_FC_155(Value)              /* register undefined */
#define Iodd_WREG_FC_156(Value)              /* register undefined */
#define Iodd_WREG_FC_157(Value)              /* register undefined */

#endif

#if                                          \
      defined(__NEC_V850_Fx3__)

#define Iodd_RREG_FCE_150                    /* register undefined */
#define Iodd_RREG_FCE_151                    /* register undefined */
#define Iodd_RREG_FCE_152                    /* register undefined */
#define Iodd_RREG_FCE_153                    /* register undefined */
#define Iodd_RREG_FCE_154                    /* register undefined */
#define Iodd_RREG_FCE_155                    /* register undefined */
#define Iodd_RREG_FCE_156                    /* register undefined */
#define Iodd_RREG_FCE_157                    /* register undefined */

#define Iodd_WREG_FCE_150(Value)             /* register undefined */
#define Iodd_WREG_FCE_151(Value)             /* register undefined */
#define Iodd_WREG_FCE_152(Value)             /* register undefined */
#define Iodd_WREG_FCE_153(Value)             /* register undefined */
#define Iodd_WREG_FCE_154(Value)             /* register undefined */
#define Iodd_WREG_FCE_155(Value)             /* register undefined */
#define Iodd_WREG_FCE_156(Value)             /* register undefined */
#define Iodd_WREG_FCE_157(Value)             /* register undefined */

#endif

#if                                          \
      defined(__NEC_V850_FE3_F3370__)||      \
      defined(__NEC_V850_FE3_F3371__)||      \
      defined(__NEC_V850_FF3_F3372__)||      \
      defined(__NEC_V850_FF3_F3373__)||      \
      defined(__NEC_V850_FG3_F3374__)||      \
      defined(__NEC_V850_FG3_F3375__)||      \
      defined(__NEC_V850_FG3_F3376__)||      \
      defined(__NEC_V850_FG3_F3377__)||      \
      defined(__NEC_V850_FJ3_F3378__)||      \
      defined(__NEC_V850_FJ3_F3379__)||      \
      defined(__NEC_V850_FJ3_F3380__)||      \
      defined(__NEC_V850_FJ3_F3381__)||      \
      defined(__NEC_V850_FJ3_F3382__)||      \
      defined(__NEC_V850_FF3L_F3618__)

#define Iodd_RREG_PU_150                     /* register undefined */
#define Iodd_RREG_PU_151                     /* register undefined */
#define Iodd_RREG_PU_152                     /* register undefined */
#define Iodd_RREG_PU_153                     /* register undefined */
#define Iodd_RREG_PU_154                     /* register undefined */
#define Iodd_RREG_PU_155                     /* register undefined */
#define Iodd_RREG_PU_156                     /* register undefined */
#define Iodd_RREG_PU_157                     /* register undefined */

#define Iodd_WREG_PU_150(Value)              /* register undefined */
#define Iodd_WREG_PU_151(Value)              /* register undefined */
#define Iodd_WREG_PU_152(Value)              /* register undefined */
#define Iodd_WREG_PU_153(Value)              /* register undefined */
#define Iodd_WREG_PU_154(Value)              /* register undefined */
#define Iodd_WREG_PU_155(Value)              /* register undefined */
#define Iodd_WREG_PU_156(Value)              /* register undefined */
#define Iodd_WREG_PU_157(Value)              /* register undefined */

#endif

#if                                          \
      defined(__NEC_V850_Fx3__)

#define Iodd_RREG_PF_150                     /* register undefined */
#define Iodd_RREG_PF_151                     /* register undefined */
#define Iodd_RREG_PF_152                     /* register undefined */
#define Iodd_RREG_PF_153                     /* register undefined */
#define Iodd_RREG_PF_154                     /* register undefined */
#define Iodd_RREG_PF_155                     /* register undefined */
#define Iodd_RREG_PF_156                     /* register undefined */
#define Iodd_RREG_PF_157                     /* register undefined */

#define Iodd_WREG_PF_150(Value)              /* register undefined */
#define Iodd_WREG_PF_151(Value)              /* register undefined */
#define Iodd_WREG_PF_152(Value)              /* register undefined */
#define Iodd_WREG_PF_153(Value)              /* register undefined */
#define Iodd_WREG_PF_154(Value)              /* register undefined */
#define Iodd_WREG_PF_155(Value)              /* register undefined */
#define Iodd_WREG_PF_156(Value)              /* register undefined */
#define Iodd_WREG_PF_157(Value)              /* register undefined */

#endif

/* Definitions PORT CD */

#if                                          \
      defined(__NEC_V850_FJ3_F3378__)||      \
      defined(__NEC_V850_FJ3_F3379__)||      \
      defined(__NEC_V850_FJ3_F3380__)||      \
      defined(__NEC_V850_FJ3_F3381__)||      \
      defined(__NEC_V850_FJ3_F3382__)||      \
      defined(__NEC_V850_FK3_F3383__)||      \
      defined(__NEC_V850_FK3_F3384__)||      \
      defined(__NEC_V850_FK3_F3385__)

#define Iodd_RREG_P_CD0                      TARG_ReadBit(PCD, BIT0)
#define Iodd_RREG_P_CD1                      TARG_ReadBit(PCD, BIT1)
#define Iodd_RREG_P_CD2                      TARG_ReadBit(PCD, BIT2)
#define Iodd_RREG_P_CD3                      TARG_ReadBit(PCD, BIT3)
#define Iodd_RREG_P_CD4                      /* read access defined but should not be used */
#define Iodd_RREG_P_CD5                      /* read access defined but should not be used */
#define Iodd_RREG_P_CD6                      /* read access defined but should not be used */
#define Iodd_RREG_P_CD7                      /* read access defined but should not be used */

#define Iodd_WREG_P_CD0(Value)               TARG_WriteBit(PCD, BIT0, Value)
#define Iodd_WREG_P_CD1(Value)               TARG_WriteBit(PCD, BIT1, Value)
#define Iodd_WREG_P_CD2(Value)               TARG_WriteBit(PCD, BIT2, Value)
#define Iodd_WREG_P_CD3(Value)               TARG_WriteBit(PCD, BIT3, Value)
#define Iodd_WREG_P_CD4(Value)               /* write access not defined */
#define Iodd_WREG_P_CD5(Value)               /* write access not defined */
#define Iodd_WREG_P_CD6(Value)               /* write access not defined */
#define Iodd_WREG_P_CD7(Value)               /* write access not defined */

#endif

#if                                          \
      defined(__NEC_V850_FJ3_F3378__)||      \
      defined(__NEC_V850_FJ3_F3379__)||      \
      defined(__NEC_V850_FJ3_F3380__)||      \
      defined(__NEC_V850_FJ3_F3381__)||      \
      defined(__NEC_V850_FJ3_F3382__)||      \
      defined(__NEC_V850_FK3_F3383__)||      \
      defined(__NEC_V850_FK3_F3384__)||      \
      defined(__NEC_V850_FK3_F3385__)

#define Iodd_RREG_M_CD0                      TARG_ReadBit(PMCD, BIT0)
#define Iodd_RREG_M_CD1                      TARG_ReadBit(PMCD, BIT1)
#define Iodd_RREG_M_CD2                      TARG_ReadBit(PMCD, BIT2)
#define Iodd_RREG_M_CD3                      TARG_ReadBit(PMCD, BIT3)
#define Iodd_RREG_M_CD4                      /* read access defined but should not be used */
#define Iodd_RREG_M_CD5                      /* read access defined but should not be used */
#define Iodd_RREG_M_CD6                      /* read access defined but should not be used */
#define Iodd_RREG_M_CD7                      /* read access defined but should not be used */

#define Iodd_WREG_M_CD0(Value)               TARG_WriteBit(PMCD, BIT0, Value)
#define Iodd_WREG_M_CD1(Value)               TARG_WriteBit(PMCD, BIT1, Value)
#define Iodd_WREG_M_CD2(Value)               TARG_WriteBit(PMCD, BIT2, Value)
#define Iodd_WREG_M_CD3(Value)               TARG_WriteBit(PMCD, BIT3, Value)
#define Iodd_WREG_M_CD4(Value)               /* write access not defined */
#define Iodd_WREG_M_CD5(Value)               /* write access not defined */
#define Iodd_WREG_M_CD6(Value)               /* write access not defined */
#define Iodd_WREG_M_CD7(Value)               /* write access not defined */

#endif

#if                                          \
      defined(__NEC_V850_FE3_F3370__)||      \
      defined(__NEC_V850_FE3_F3371__)||      \
      defined(__NEC_V850_FF3_F3372__)||      \
      defined(__NEC_V850_FF3_F3373__)||      \
      defined(__NEC_V850_FG3_F3374__)||      \
      defined(__NEC_V850_FG3_F3375__)||      \
      defined(__NEC_V850_FG3_F3376__)||      \
      defined(__NEC_V850_FG3_F3377__)||      \
      defined(__NEC_V850_FF3L_F3618__)

#define Iodd_RREG_P_CD0                      /* register undefined */
#define Iodd_RREG_P_CD1                      /* register undefined */
#define Iodd_RREG_P_CD2                      /* register undefined */
#define Iodd_RREG_P_CD3                      /* register undefined */
#define Iodd_RREG_P_CD4                      /* register undefined */
#define Iodd_RREG_P_CD5                      /* register undefined */
#define Iodd_RREG_P_CD6                      /* register undefined */
#define Iodd_RREG_P_CD7                      /* register undefined */

#define Iodd_WREG_P_CD0(Value)               /* register undefined */
#define Iodd_WREG_P_CD1(Value)               /* register undefined */
#define Iodd_WREG_P_CD2(Value)               /* register undefined */
#define Iodd_WREG_P_CD3(Value)               /* register undefined */
#define Iodd_WREG_P_CD4(Value)               /* register undefined */
#define Iodd_WREG_P_CD5(Value)               /* register undefined */
#define Iodd_WREG_P_CD6(Value)               /* register undefined */
#define Iodd_WREG_P_CD7(Value)               /* register undefined */

#endif

#if                                          \
      defined(__NEC_V850_FE3_F3370__)||      \
      defined(__NEC_V850_FE3_F3371__)||      \
      defined(__NEC_V850_FF3_F3372__)||      \
      defined(__NEC_V850_FF3_F3373__)||      \
      defined(__NEC_V850_FG3_F3374__)||      \
      defined(__NEC_V850_FG3_F3375__)||      \
      defined(__NEC_V850_FG3_F3376__)||      \
      defined(__NEC_V850_FG3_F3377__)||      \
      defined(__NEC_V850_FF3L_F3618__)

#define Iodd_RREG_M_CD0                      /* register undefined */
#define Iodd_RREG_M_CD1                      /* register undefined */
#define Iodd_RREG_M_CD2                      /* register undefined */
#define Iodd_RREG_M_CD3                      /* register undefined */
#define Iodd_RREG_M_CD4                      /* register undefined */
#define Iodd_RREG_M_CD5                      /* register undefined */
#define Iodd_RREG_M_CD6                      /* register undefined */
#define Iodd_RREG_M_CD7                      /* register undefined */

#define Iodd_WREG_M_CD0(Value)               /* register undefined */
#define Iodd_WREG_M_CD1(Value)               /* register undefined */
#define Iodd_WREG_M_CD2(Value)               /* register undefined */
#define Iodd_WREG_M_CD3(Value)               /* register undefined */
#define Iodd_WREG_M_CD4(Value)               /* register undefined */
#define Iodd_WREG_M_CD5(Value)               /* register undefined */
#define Iodd_WREG_M_CD6(Value)               /* register undefined */
#define Iodd_WREG_M_CD7(Value)               /* register undefined */

#endif

#if                                          \
      defined(__NEC_V850_Fx3__)

#define Iodd_RREG_MC_CD0                     /* register undefined */
#define Iodd_RREG_MC_CD1                     /* register undefined */
#define Iodd_RREG_MC_CD2                     /* register undefined */
#define Iodd_RREG_MC_CD3                     /* register undefined */
#define Iodd_RREG_MC_CD4                     /* register undefined */
#define Iodd_RREG_MC_CD5                     /* register undefined */
#define Iodd_RREG_MC_CD6                     /* register undefined */
#define Iodd_RREG_MC_CD7                     /* register undefined */

#define Iodd_WREG_MC_CD0(Value)              /* register undefined */
#define Iodd_WREG_MC_CD1(Value)              /* register undefined */
#define Iodd_WREG_MC_CD2(Value)              /* register undefined */
#define Iodd_WREG_MC_CD3(Value)              /* register undefined */
#define Iodd_WREG_MC_CD4(Value)              /* register undefined */
#define Iodd_WREG_MC_CD5(Value)              /* register undefined */
#define Iodd_WREG_MC_CD6(Value)              /* register undefined */
#define Iodd_WREG_MC_CD7(Value)              /* register undefined */

#endif

#if                                          \
      defined(__NEC_V850_Fx3__)

#define Iodd_RREG_FC_CD0                     /* register undefined */
#define Iodd_RREG_FC_CD1                     /* register undefined */
#define Iodd_RREG_FC_CD2                     /* register undefined */
#define Iodd_RREG_FC_CD3                     /* register undefined */
#define Iodd_RREG_FC_CD4                     /* register undefined */
#define Iodd_RREG_FC_CD5                     /* register undefined */
#define Iodd_RREG_FC_CD6                     /* register undefined */
#define Iodd_RREG_FC_CD7                     /* register undefined */

#define Iodd_WREG_FC_CD0(Value)              /* register undefined */
#define Iodd_WREG_FC_CD1(Value)              /* register undefined */
#define Iodd_WREG_FC_CD2(Value)              /* register undefined */
#define Iodd_WREG_FC_CD3(Value)              /* register undefined */
#define Iodd_WREG_FC_CD4(Value)              /* register undefined */
#define Iodd_WREG_FC_CD5(Value)              /* register undefined */
#define Iodd_WREG_FC_CD6(Value)              /* register undefined */
#define Iodd_WREG_FC_CD7(Value)              /* register undefined */

#endif

#if                                          \
      defined(__NEC_V850_Fx3__)

#define Iodd_RREG_FCE_CD0                    /* register undefined */
#define Iodd_RREG_FCE_CD1                    /* register undefined */
#define Iodd_RREG_FCE_CD2                    /* register undefined */
#define Iodd_RREG_FCE_CD3                    /* register undefined */
#define Iodd_RREG_FCE_CD4                    /* register undefined */
#define Iodd_RREG_FCE_CD5                    /* register undefined */
#define Iodd_RREG_FCE_CD6                    /* register undefined */
#define Iodd_RREG_FCE_CD7                    /* register undefined */

#define Iodd_WREG_FCE_CD0(Value)             /* register undefined */
#define Iodd_WREG_FCE_CD1(Value)             /* register undefined */
#define Iodd_WREG_FCE_CD2(Value)             /* register undefined */
#define Iodd_WREG_FCE_CD3(Value)             /* register undefined */
#define Iodd_WREG_FCE_CD4(Value)             /* register undefined */
#define Iodd_WREG_FCE_CD5(Value)             /* register undefined */
#define Iodd_WREG_FCE_CD6(Value)             /* register undefined */
#define Iodd_WREG_FCE_CD7(Value)             /* register undefined */

#endif

#if                                          \
      defined(__NEC_V850_Fx3__)

#define Iodd_RREG_PU_CD0                     /* register undefined */
#define Iodd_RREG_PU_CD1                     /* register undefined */
#define Iodd_RREG_PU_CD2                     /* register undefined */
#define Iodd_RREG_PU_CD3                     /* register undefined */
#define Iodd_RREG_PU_CD4                     /* register undefined */
#define Iodd_RREG_PU_CD5                     /* register undefined */
#define Iodd_RREG_PU_CD6                     /* register undefined */
#define Iodd_RREG_PU_CD7                     /* register undefined */

#define Iodd_WREG_PU_CD0(Value)              /* register undefined */
#define Iodd_WREG_PU_CD1(Value)              /* register undefined */
#define Iodd_WREG_PU_CD2(Value)              /* register undefined */
#define Iodd_WREG_PU_CD3(Value)              /* register undefined */
#define Iodd_WREG_PU_CD4(Value)              /* register undefined */
#define Iodd_WREG_PU_CD5(Value)              /* register undefined */
#define Iodd_WREG_PU_CD6(Value)              /* register undefined */
#define Iodd_WREG_PU_CD7(Value)              /* register undefined */

#endif

#if                                          \
      defined(__NEC_V850_Fx3__)

#define Iodd_RREG_PF_CD0                     /* register undefined */
#define Iodd_RREG_PF_CD1                     /* register undefined */
#define Iodd_RREG_PF_CD2                     /* register undefined */
#define Iodd_RREG_PF_CD3                     /* register undefined */
#define Iodd_RREG_PF_CD4                     /* register undefined */
#define Iodd_RREG_PF_CD5                     /* register undefined */
#define Iodd_RREG_PF_CD6                     /* register undefined */
#define Iodd_RREG_PF_CD7                     /* register undefined */

#define Iodd_WREG_PF_CD0(Value)              /* register undefined */
#define Iodd_WREG_PF_CD1(Value)              /* register undefined */
#define Iodd_WREG_PF_CD2(Value)              /* register undefined */
#define Iodd_WREG_PF_CD3(Value)              /* register undefined */
#define Iodd_WREG_PF_CD4(Value)              /* register undefined */
#define Iodd_WREG_PF_CD5(Value)              /* register undefined */
#define Iodd_WREG_PF_CD6(Value)              /* register undefined */
#define Iodd_WREG_PF_CD7(Value)              /* register undefined */

#endif

/* Definitions PORT CM */

#if                                          \
      defined(__NEC_V850_FE3_F3370__)||      \
      defined(__NEC_V850_FE3_F3371__)

#define Iodd_RREG_P_CM0                      TARG_ReadBit(PCM, BIT0)
#define Iodd_RREG_P_CM1                      TARG_ReadBit(PCM, BIT1)
#define Iodd_RREG_P_CM2                      /* read access defined but should not be used */
#define Iodd_RREG_P_CM3                      /* read access defined but should not be used */
#define Iodd_RREG_P_CM4                      /* read access defined but should not be used */
#define Iodd_RREG_P_CM5                      /* read access defined but should not be used */
#define Iodd_RREG_P_CM6                      /* read access defined but should not be used */
#define Iodd_RREG_P_CM7                      /* read access defined but should not be used */

#define Iodd_WREG_P_CM0(Value)               TARG_WriteBit(PCM, BIT0, Value)
#define Iodd_WREG_P_CM1(Value)               TARG_WriteBit(PCM, BIT1, Value)
#define Iodd_WREG_P_CM2(Value)               /* write access not defined */
#define Iodd_WREG_P_CM3(Value)               /* write access not defined */
#define Iodd_WREG_P_CM4(Value)               /* write access not defined */
#define Iodd_WREG_P_CM5(Value)               /* write access not defined */
#define Iodd_WREG_P_CM6(Value)               /* write access not defined */
#define Iodd_WREG_P_CM7(Value)               /* write access not defined */

#endif

#if                                          \
      defined(__NEC_V850_FF3_F3372__)||      \
      defined(__NEC_V850_FF3_F3373__)||      \
      defined(__NEC_V850_FG3_F3374__)||      \
      defined(__NEC_V850_FG3_F3375__)||      \
      defined(__NEC_V850_FG3_F3376__)||      \
      defined(__NEC_V850_FG3_F3377__)||      \
      defined(__NEC_V850_FF3L_F3618__)

#define Iodd_RREG_P_CM0                      TARG_ReadBit(PCM, BIT0)
#define Iodd_RREG_P_CM1                      TARG_ReadBit(PCM, BIT1)
#define Iodd_RREG_P_CM2                      TARG_ReadBit(PCM, BIT2)
#define Iodd_RREG_P_CM3                      TARG_ReadBit(PCM, BIT3)
#define Iodd_RREG_P_CM4                      /* read access defined but should not be used */
#define Iodd_RREG_P_CM5                      /* read access defined but should not be used */
#define Iodd_RREG_P_CM6                      /* read access defined but should not be used */
#define Iodd_RREG_P_CM7                      /* read access defined but should not be used */

#define Iodd_WREG_P_CM0(Value)               TARG_WriteBit(PCM, BIT0, Value)
#define Iodd_WREG_P_CM1(Value)               TARG_WriteBit(PCM, BIT1, Value)
#define Iodd_WREG_P_CM2(Value)               TARG_WriteBit(PCM, BIT2, Value)
#define Iodd_WREG_P_CM3(Value)               TARG_WriteBit(PCM, BIT3, Value)
#define Iodd_WREG_P_CM4(Value)               /* write access not defined */
#define Iodd_WREG_P_CM5(Value)               /* write access not defined */
#define Iodd_WREG_P_CM6(Value)               /* write access not defined */
#define Iodd_WREG_P_CM7(Value)               /* write access not defined */

#endif

#if                                          \
      defined(__NEC_V850_FJ3_F3378__)||      \
      defined(__NEC_V850_FJ3_F3379__)||      \
      defined(__NEC_V850_FJ3_F3380__)||      \
      defined(__NEC_V850_FJ3_F3381__)||      \
      defined(__NEC_V850_FJ3_F3382__)||      \
      defined(__NEC_V850_FK3_F3383__)||      \
      defined(__NEC_V850_FK3_F3384__)||      \
      defined(__NEC_V850_FK3_F3385__)

#define Iodd_RREG_P_CM0                      TARG_ReadBit(PCM, BIT0)
#define Iodd_RREG_P_CM1                      TARG_ReadBit(PCM, BIT1)
#define Iodd_RREG_P_CM2                      TARG_ReadBit(PCM, BIT2)
#define Iodd_RREG_P_CM3                      TARG_ReadBit(PCM, BIT3)
#define Iodd_RREG_P_CM4                      TARG_ReadBit(PCM, BIT4)
#define Iodd_RREG_P_CM5                      TARG_ReadBit(PCM, BIT5)
#define Iodd_RREG_P_CM6                      /* read access defined but should not be used */
#define Iodd_RREG_P_CM7                      /* read access defined but should not be used */

#define Iodd_WREG_P_CM0(Value)               TARG_WriteBit(PCM, BIT0, Value)
#define Iodd_WREG_P_CM1(Value)               TARG_WriteBit(PCM, BIT1, Value)
#define Iodd_WREG_P_CM2(Value)               TARG_WriteBit(PCM, BIT2, Value)
#define Iodd_WREG_P_CM3(Value)               TARG_WriteBit(PCM, BIT3, Value)
#define Iodd_WREG_P_CM4(Value)               TARG_WriteBit(PCM, BIT4, Value)
#define Iodd_WREG_P_CM5(Value)               TARG_WriteBit(PCM, BIT5, Value)
#define Iodd_WREG_P_CM6(Value)               /* write access not defined */
#define Iodd_WREG_P_CM7(Value)               /* write access not defined */

#endif

#if                                          \
      defined(__NEC_V850_FE3_F3370__)||      \
      defined(__NEC_V850_FE3_F3371__)

#define Iodd_RREG_M_CM0                      TARG_ReadBit(PMCM, BIT0)
#define Iodd_RREG_M_CM1                      TARG_ReadBit(PMCM, BIT1)
#define Iodd_RREG_M_CM2                      /* read access defined but should not be used */
#define Iodd_RREG_M_CM3                      /* read access defined but should not be used */
#define Iodd_RREG_M_CM4                      /* read access defined but should not be used */
#define Iodd_RREG_M_CM5                      /* read access defined but should not be used */
#define Iodd_RREG_M_CM6                      /* read access defined but should not be used */
#define Iodd_RREG_M_CM7                      /* read access defined but should not be used */

#define Iodd_WREG_M_CM0(Value)               TARG_WriteBit(PMCM, BIT0, Value)
#define Iodd_WREG_M_CM1(Value)               TARG_WriteBit(PMCM, BIT1, Value)
#define Iodd_WREG_M_CM2(Value)               /* write access not defined */
#define Iodd_WREG_M_CM3(Value)               /* write access not defined */
#define Iodd_WREG_M_CM4(Value)               /* write access not defined */
#define Iodd_WREG_M_CM5(Value)               /* write access not defined */
#define Iodd_WREG_M_CM6(Value)               /* write access not defined */
#define Iodd_WREG_M_CM7(Value)               /* write access not defined */

#endif

#if                                          \
      defined(__NEC_V850_FF3_F3372__)||      \
      defined(__NEC_V850_FF3_F3373__)||      \
      defined(__NEC_V850_FG3_F3374__)||      \
      defined(__NEC_V850_FG3_F3375__)||      \
      defined(__NEC_V850_FG3_F3376__)||      \
      defined(__NEC_V850_FG3_F3377__)||      \
      defined(__NEC_V850_FF3L_F3618__)

#define Iodd_RREG_M_CM0                      TARG_ReadBit(PMCM, BIT0)
#define Iodd_RREG_M_CM1                      TARG_ReadBit(PMCM, BIT1)
#define Iodd_RREG_M_CM2                      TARG_ReadBit(PMCM, BIT2)
#define Iodd_RREG_M_CM3                      TARG_ReadBit(PMCM, BIT3)
#define Iodd_RREG_M_CM4                      /* read access defined but should not be used */
#define Iodd_RREG_M_CM5                      /* read access defined but should not be used */
#define Iodd_RREG_M_CM6                      /* read access defined but should not be used */
#define Iodd_RREG_M_CM7                      /* read access defined but should not be used */

#define Iodd_WREG_M_CM0(Value)               TARG_WriteBit(PMCM, BIT0, Value)
#define Iodd_WREG_M_CM1(Value)               TARG_WriteBit(PMCM, BIT1, Value)
#define Iodd_WREG_M_CM2(Value)               TARG_WriteBit(PMCM, BIT2, Value)
#define Iodd_WREG_M_CM3(Value)               TARG_WriteBit(PMCM, BIT3, Value)
#define Iodd_WREG_M_CM4(Value)               /* write access not defined */
#define Iodd_WREG_M_CM5(Value)               /* write access not defined */
#define Iodd_WREG_M_CM6(Value)               /* write access not defined */
#define Iodd_WREG_M_CM7(Value)               /* write access not defined */

#endif

#if                                          \
      defined(__NEC_V850_FJ3_F3378__)||      \
      defined(__NEC_V850_FJ3_F3379__)||      \
      defined(__NEC_V850_FJ3_F3380__)||      \
      defined(__NEC_V850_FJ3_F3381__)||      \
      defined(__NEC_V850_FJ3_F3382__)||      \
      defined(__NEC_V850_FK3_F3383__)||      \
      defined(__NEC_V850_FK3_F3384__)||      \
      defined(__NEC_V850_FK3_F3385__)

#define Iodd_RREG_M_CM0                      TARG_ReadBit(PMCM, BIT0)
#define Iodd_RREG_M_CM1                      TARG_ReadBit(PMCM, BIT1)
#define Iodd_RREG_M_CM2                      TARG_ReadBit(PMCM, BIT2)
#define Iodd_RREG_M_CM3                      TARG_ReadBit(PMCM, BIT3)
#define Iodd_RREG_M_CM4                      TARG_ReadBit(PMCM, BIT4)
#define Iodd_RREG_M_CM5                      TARG_ReadBit(PMCM, BIT5)
#define Iodd_RREG_M_CM6                      /* read access defined but should not be used */
#define Iodd_RREG_M_CM7                      /* read access defined but should not be used */

#define Iodd_WREG_M_CM0(Value)               TARG_WriteBit(PMCM, BIT0, Value)
#define Iodd_WREG_M_CM1(Value)               TARG_WriteBit(PMCM, BIT1, Value)
#define Iodd_WREG_M_CM2(Value)               TARG_WriteBit(PMCM, BIT2, Value)
#define Iodd_WREG_M_CM3(Value)               TARG_WriteBit(PMCM, BIT3, Value)
#define Iodd_WREG_M_CM4(Value)               TARG_WriteBit(PMCM, BIT4, Value)
#define Iodd_WREG_M_CM5(Value)               TARG_WriteBit(PMCM, BIT5, Value)
#define Iodd_WREG_M_CM6(Value)               /* write access not defined */
#define Iodd_WREG_M_CM7(Value)               /* write access not defined */

#endif

#if                                          \
      defined(__NEC_V850_FE3_F3370__)||      \
      defined(__NEC_V850_FE3_F3371__)||      \
      defined(__NEC_V850_FF3_F3372__)||      \
      defined(__NEC_V850_FF3_F3373__)||      \
      defined(__NEC_V850_FG3_F3374__)||      \
      defined(__NEC_V850_FG3_F3375__)||      \
      defined(__NEC_V850_FG3_F3376__)||      \
      defined(__NEC_V850_FG3_F3377__)||      \
      defined(__NEC_V850_FF3L_F3618__)

#define Iodd_RREG_MC_CM0                     /* read access defined but should not be used */
#define Iodd_RREG_MC_CM1                     TARG_ReadBit(PMCCM, BIT1)
#define Iodd_RREG_MC_CM2                     /* read access defined but should not be used */
#define Iodd_RREG_MC_CM3                     /* read access defined but should not be used */
#define Iodd_RREG_MC_CM4                     /* read access defined but should not be used */
#define Iodd_RREG_MC_CM5                     /* read access defined but should not be used */
#define Iodd_RREG_MC_CM6                     /* read access defined but should not be used */
#define Iodd_RREG_MC_CM7                     /* read access defined but should not be used */

#define Iodd_WREG_MC_CM0(Value)              /* write access not defined */
#define Iodd_WREG_MC_CM1(Value)              TARG_WriteBit(PMCCM, BIT1, Value)
#define Iodd_WREG_MC_CM2(Value)              /* write access not defined */
#define Iodd_WREG_MC_CM3(Value)              /* write access not defined */
#define Iodd_WREG_MC_CM4(Value)              /* write access not defined */
#define Iodd_WREG_MC_CM5(Value)              /* write access not defined */
#define Iodd_WREG_MC_CM6(Value)              /* write access not defined */
#define Iodd_WREG_MC_CM7(Value)              /* write access not defined */

#endif

#if                                          \
      defined(__NEC_V850_FJ3_F3378__)||      \
      defined(__NEC_V850_FJ3_F3379__)||      \
      defined(__NEC_V850_FJ3_F3380__)||      \
      defined(__NEC_V850_FJ3_F3381__)||      \
      defined(__NEC_V850_FJ3_F3382__)||      \
      defined(__NEC_V850_FK3_F3383__)||      \
      defined(__NEC_V850_FK3_F3384__)||      \
      defined(__NEC_V850_FK3_F3385__)

#define Iodd_RREG_MC_CM0                     TARG_ReadBit(PMCCM, BIT0)
#define Iodd_RREG_MC_CM1                     TARG_ReadBit(PMCCM, BIT1)
#define Iodd_RREG_MC_CM2                     TARG_ReadBit(PMCCM, BIT2)
#define Iodd_RREG_MC_CM3                     TARG_ReadBit(PMCCM, BIT3)
#define Iodd_RREG_MC_CM4                     /* read access defined but should not be used */
#define Iodd_RREG_MC_CM5                     /* read access defined but should not be used */
#define Iodd_RREG_MC_CM6                     /* read access defined but should not be used */
#define Iodd_RREG_MC_CM7                     /* read access defined but should not be used */

#define Iodd_WREG_MC_CM0(Value)              TARG_WriteBit(PMCCM, BIT0, Value)
#define Iodd_WREG_MC_CM1(Value)              TARG_WriteBit(PMCCM, BIT1, Value)
#define Iodd_WREG_MC_CM2(Value)              TARG_WriteBit(PMCCM, BIT2, Value)
#define Iodd_WREG_MC_CM3(Value)              TARG_WriteBit(PMCCM, BIT3, Value)
#define Iodd_WREG_MC_CM4(Value)              /* write access not defined */
#define Iodd_WREG_MC_CM5(Value)              /* write access not defined */
#define Iodd_WREG_MC_CM6(Value)              /* write access not defined */
#define Iodd_WREG_MC_CM7(Value)              /* write access not defined */

#endif

#if                                          \
      defined(__NEC_V850_Fx3__)

#define Iodd_RREG_FC_CM0                     /* register undefined */
#define Iodd_RREG_FC_CM1                     /* register undefined */
#define Iodd_RREG_FC_CM2                     /* register undefined */
#define Iodd_RREG_FC_CM3                     /* register undefined */
#define Iodd_RREG_FC_CM4                     /* register undefined */
#define Iodd_RREG_FC_CM5                     /* register undefined */
#define Iodd_RREG_FC_CM6                     /* register undefined */
#define Iodd_RREG_FC_CM7                     /* register undefined */

#define Iodd_WREG_FC_CM0(Value)              /* register undefined */
#define Iodd_WREG_FC_CM1(Value)              /* register undefined */
#define Iodd_WREG_FC_CM2(Value)              /* register undefined */
#define Iodd_WREG_FC_CM3(Value)              /* register undefined */
#define Iodd_WREG_FC_CM4(Value)              /* register undefined */
#define Iodd_WREG_FC_CM5(Value)              /* register undefined */
#define Iodd_WREG_FC_CM6(Value)              /* register undefined */
#define Iodd_WREG_FC_CM7(Value)              /* register undefined */

#endif

#if                                          \
      defined(__NEC_V850_Fx3__)

#define Iodd_RREG_FCE_CM0                    /* register undefined */
#define Iodd_RREG_FCE_CM1                    /* register undefined */
#define Iodd_RREG_FCE_CM2                    /* register undefined */
#define Iodd_RREG_FCE_CM3                    /* register undefined */
#define Iodd_RREG_FCE_CM4                    /* register undefined */
#define Iodd_RREG_FCE_CM5                    /* register undefined */
#define Iodd_RREG_FCE_CM6                    /* register undefined */
#define Iodd_RREG_FCE_CM7                    /* register undefined */

#define Iodd_WREG_FCE_CM0(Value)             /* register undefined */
#define Iodd_WREG_FCE_CM1(Value)             /* register undefined */
#define Iodd_WREG_FCE_CM2(Value)             /* register undefined */
#define Iodd_WREG_FCE_CM3(Value)             /* register undefined */
#define Iodd_WREG_FCE_CM4(Value)             /* register undefined */
#define Iodd_WREG_FCE_CM5(Value)             /* register undefined */
#define Iodd_WREG_FCE_CM6(Value)             /* register undefined */
#define Iodd_WREG_FCE_CM7(Value)             /* register undefined */

#endif

#if                                          \
      defined(__NEC_V850_Fx3__)

#define Iodd_RREG_PU_CM0                     /* register undefined */
#define Iodd_RREG_PU_CM1                     /* register undefined */
#define Iodd_RREG_PU_CM2                     /* register undefined */
#define Iodd_RREG_PU_CM3                     /* register undefined */
#define Iodd_RREG_PU_CM4                     /* register undefined */
#define Iodd_RREG_PU_CM5                     /* register undefined */
#define Iodd_RREG_PU_CM6                     /* register undefined */
#define Iodd_RREG_PU_CM7                     /* register undefined */

#define Iodd_WREG_PU_CM0(Value)              /* register undefined */
#define Iodd_WREG_PU_CM1(Value)              /* register undefined */
#define Iodd_WREG_PU_CM2(Value)              /* register undefined */
#define Iodd_WREG_PU_CM3(Value)              /* register undefined */
#define Iodd_WREG_PU_CM4(Value)              /* register undefined */
#define Iodd_WREG_PU_CM5(Value)              /* register undefined */
#define Iodd_WREG_PU_CM6(Value)              /* register undefined */
#define Iodd_WREG_PU_CM7(Value)              /* register undefined */

#endif

#if                                          \
      defined(__NEC_V850_Fx3__)

#define Iodd_RREG_PF_CM0                     /* register undefined */
#define Iodd_RREG_PF_CM1                     /* register undefined */
#define Iodd_RREG_PF_CM2                     /* register undefined */
#define Iodd_RREG_PF_CM3                     /* register undefined */
#define Iodd_RREG_PF_CM4                     /* register undefined */
#define Iodd_RREG_PF_CM5                     /* register undefined */
#define Iodd_RREG_PF_CM6                     /* register undefined */
#define Iodd_RREG_PF_CM7                     /* register undefined */

#define Iodd_WREG_PF_CM0(Value)              /* register undefined */
#define Iodd_WREG_PF_CM1(Value)              /* register undefined */
#define Iodd_WREG_PF_CM2(Value)              /* register undefined */
#define Iodd_WREG_PF_CM3(Value)              /* register undefined */
#define Iodd_WREG_PF_CM4(Value)              /* register undefined */
#define Iodd_WREG_PF_CM5(Value)              /* register undefined */
#define Iodd_WREG_PF_CM6(Value)              /* register undefined */
#define Iodd_WREG_PF_CM7(Value)              /* register undefined */

#endif

/* Definitions PORT CS */

#if                                          \
      defined(__NEC_V850_FF3_F3372__)||      \
      defined(__NEC_V850_FF3_F3373__)||      \
      defined(__NEC_V850_FG3_F3374__)||      \
      defined(__NEC_V850_FG3_F3375__)||      \
      defined(__NEC_V850_FG3_F3376__)||      \
      defined(__NEC_V850_FG3_F3377__)||      \
      defined(__NEC_V850_FF3L_F3618__)

#define Iodd_RREG_P_CS0                      TARG_ReadBit(PCS, BIT0)
#define Iodd_RREG_P_CS1                      TARG_ReadBit(PCS, BIT1)
#define Iodd_RREG_P_CS2                      /* read access defined but should not be used */
#define Iodd_RREG_P_CS3                      /* read access defined but should not be used */
#define Iodd_RREG_P_CS4                      /* read access defined but should not be used */
#define Iodd_RREG_P_CS5                      /* read access defined but should not be used */
#define Iodd_RREG_P_CS6                      /* read access defined but should not be used */
#define Iodd_RREG_P_CS7                      /* read access defined but should not be used */

#define Iodd_WREG_P_CS0(Value)               TARG_WriteBit(PCS, BIT0, Value)
#define Iodd_WREG_P_CS1(Value)               TARG_WriteBit(PCS, BIT1, Value)
#define Iodd_WREG_P_CS2(Value)               /* write access not defined */
#define Iodd_WREG_P_CS3(Value)               /* write access not defined */
#define Iodd_WREG_P_CS4(Value)               /* write access not defined */
#define Iodd_WREG_P_CS5(Value)               /* write access not defined */
#define Iodd_WREG_P_CS6(Value)               /* write access not defined */
#define Iodd_WREG_P_CS7(Value)               /* write access not defined */

#endif

#if                                          \
      defined(__NEC_V850_FJ3_F3378__)||      \
      defined(__NEC_V850_FJ3_F3379__)||      \
      defined(__NEC_V850_FJ3_F3380__)||      \
      defined(__NEC_V850_FJ3_F3381__)||      \
      defined(__NEC_V850_FJ3_F3382__)||      \
      defined(__NEC_V850_FK3_F3383__)||      \
      defined(__NEC_V850_FK3_F3384__)||      \
      defined(__NEC_V850_FK3_F3385__)

#define Iodd_RREG_P_CS0                      TARG_ReadBit(PCS, BIT0)
#define Iodd_RREG_P_CS1                      TARG_ReadBit(PCS, BIT1)
#define Iodd_RREG_P_CS2                      TARG_ReadBit(PCS, BIT2)
#define Iodd_RREG_P_CS3                      TARG_ReadBit(PCS, BIT3)
#define Iodd_RREG_P_CS4                      TARG_ReadBit(PCS, BIT4)
#define Iodd_RREG_P_CS5                      TARG_ReadBit(PCS, BIT5)
#define Iodd_RREG_P_CS6                      TARG_ReadBit(PCS, BIT6)
#define Iodd_RREG_P_CS7                      TARG_ReadBit(PCS, BIT7)

#define Iodd_WREG_P_CS0(Value)               TARG_WriteBit(PCS, BIT0, Value)
#define Iodd_WREG_P_CS1(Value)               TARG_WriteBit(PCS, BIT1, Value)
#define Iodd_WREG_P_CS2(Value)               TARG_WriteBit(PCS, BIT2, Value)
#define Iodd_WREG_P_CS3(Value)               TARG_WriteBit(PCS, BIT3, Value)
#define Iodd_WREG_P_CS4(Value)               TARG_WriteBit(PCS, BIT4, Value)
#define Iodd_WREG_P_CS5(Value)               TARG_WriteBit(PCS, BIT5, Value)
#define Iodd_WREG_P_CS6(Value)               TARG_WriteBit(PCS, BIT6, Value)
#define Iodd_WREG_P_CS7(Value)               TARG_WriteBit(PCS, BIT7, Value)

#endif

#if                                          \
      defined(__NEC_V850_FF3_F3372__)||      \
      defined(__NEC_V850_FF3_F3373__)||      \
      defined(__NEC_V850_FG3_F3374__)||      \
      defined(__NEC_V850_FG3_F3375__)||      \
      defined(__NEC_V850_FG3_F3376__)||      \
      defined(__NEC_V850_FG3_F3377__)||      \
      defined(__NEC_V850_FF3L_F3618__)

#define Iodd_RREG_M_CS0                      TARG_ReadBit(PMCS, BIT0)
#define Iodd_RREG_M_CS1                      TARG_ReadBit(PMCS, BIT1)
#define Iodd_RREG_M_CS2                      /* read access defined but should not be used */
#define Iodd_RREG_M_CS3                      /* read access defined but should not be used */
#define Iodd_RREG_M_CS4                      /* read access defined but should not be used */
#define Iodd_RREG_M_CS5                      /* read access defined but should not be used */
#define Iodd_RREG_M_CS6                      /* read access defined but should not be used */
#define Iodd_RREG_M_CS7                      /* read access defined but should not be used */

#define Iodd_WREG_M_CS0(Value)               TARG_WriteBit(PMCS, BIT0, Value)
#define Iodd_WREG_M_CS1(Value)               TARG_WriteBit(PMCS, BIT1, Value)
#define Iodd_WREG_M_CS2(Value)               /* write access not defined */
#define Iodd_WREG_M_CS3(Value)               /* write access not defined */
#define Iodd_WREG_M_CS4(Value)               /* write access not defined */
#define Iodd_WREG_M_CS5(Value)               /* write access not defined */
#define Iodd_WREG_M_CS6(Value)               /* write access not defined */
#define Iodd_WREG_M_CS7(Value)               /* write access not defined */

#endif

#if                                          \
      defined(__NEC_V850_FJ3_F3378__)||      \
      defined(__NEC_V850_FJ3_F3379__)||      \
      defined(__NEC_V850_FJ3_F3380__)||      \
      defined(__NEC_V850_FJ3_F3381__)||      \
      defined(__NEC_V850_FJ3_F3382__)||      \
      defined(__NEC_V850_FK3_F3383__)||      \
      defined(__NEC_V850_FK3_F3384__)||      \
      defined(__NEC_V850_FK3_F3385__)

#define Iodd_RREG_M_CS0                      TARG_ReadBit(PMCS, BIT0)
#define Iodd_RREG_M_CS1                      TARG_ReadBit(PMCS, BIT1)
#define Iodd_RREG_M_CS2                      TARG_ReadBit(PMCS, BIT2)
#define Iodd_RREG_M_CS3                      TARG_ReadBit(PMCS, BIT3)
#define Iodd_RREG_M_CS4                      TARG_ReadBit(PMCS, BIT4)
#define Iodd_RREG_M_CS5                      TARG_ReadBit(PMCS, BIT5)
#define Iodd_RREG_M_CS6                      TARG_ReadBit(PMCS, BIT6)
#define Iodd_RREG_M_CS7                      TARG_ReadBit(PMCS, BIT7)

#define Iodd_WREG_M_CS0(Value)               TARG_WriteBit(PMCS, BIT0, Value)
#define Iodd_WREG_M_CS1(Value)               TARG_WriteBit(PMCS, BIT1, Value)
#define Iodd_WREG_M_CS2(Value)               TARG_WriteBit(PMCS, BIT2, Value)
#define Iodd_WREG_M_CS3(Value)               TARG_WriteBit(PMCS, BIT3, Value)
#define Iodd_WREG_M_CS4(Value)               TARG_WriteBit(PMCS, BIT4, Value)
#define Iodd_WREG_M_CS5(Value)               TARG_WriteBit(PMCS, BIT5, Value)
#define Iodd_WREG_M_CS6(Value)               TARG_WriteBit(PMCS, BIT6, Value)
#define Iodd_WREG_M_CS7(Value)               TARG_WriteBit(PMCS, BIT7, Value)

#endif

#if                                          \
      defined(__NEC_V850_FJ3_F3378__)||      \
      defined(__NEC_V850_FJ3_F3379__)||      \
      defined(__NEC_V850_FJ3_F3380__)||      \
      defined(__NEC_V850_FJ3_F3381__)||      \
      defined(__NEC_V850_FJ3_F3382__)||      \
      defined(__NEC_V850_FK3_F3383__)||      \
      defined(__NEC_V850_FK3_F3384__)||      \
      defined(__NEC_V850_FK3_F3385__)

#define Iodd_RREG_MC_CS0                     TARG_ReadBit(PMCCS, BIT0)
#define Iodd_RREG_MC_CS1                     TARG_ReadBit(PMCCS, BIT1)
#define Iodd_RREG_MC_CS2                     TARG_ReadBit(PMCCS, BIT2)
#define Iodd_RREG_MC_CS3                     TARG_ReadBit(PMCCS, BIT3)
#define Iodd_RREG_MC_CS4                     /* read access defined but should not be used */
#define Iodd_RREG_MC_CS5                     /* read access defined but should not be used */
#define Iodd_RREG_MC_CS6                     /* read access defined but should not be used */
#define Iodd_RREG_MC_CS7                     /* read access defined but should not be used */

#define Iodd_WREG_MC_CS0(Value)              TARG_WriteBit(PMCCS, BIT0, Value)
#define Iodd_WREG_MC_CS1(Value)              TARG_WriteBit(PMCCS, BIT1, Value)
#define Iodd_WREG_MC_CS2(Value)              TARG_WriteBit(PMCCS, BIT2, Value)
#define Iodd_WREG_MC_CS3(Value)              TARG_WriteBit(PMCCS, BIT3, Value)
#define Iodd_WREG_MC_CS4(Value)              /* write access not defined */
#define Iodd_WREG_MC_CS5(Value)              /* write access not defined */
#define Iodd_WREG_MC_CS6(Value)              /* write access not defined */
#define Iodd_WREG_MC_CS7(Value)              /* write access not defined */

#endif

#if                                          \
      defined(__NEC_V850_FE3_F3370__)||      \
      defined(__NEC_V850_FE3_F3371__)

#define Iodd_RREG_P_CS0                      /* register undefined */
#define Iodd_RREG_P_CS1                      /* register undefined */
#define Iodd_RREG_P_CS2                      /* register undefined */
#define Iodd_RREG_P_CS3                      /* register undefined */
#define Iodd_RREG_P_CS4                      /* register undefined */
#define Iodd_RREG_P_CS5                      /* register undefined */
#define Iodd_RREG_P_CS6                      /* register undefined */
#define Iodd_RREG_P_CS7                      /* register undefined */

#define Iodd_WREG_P_CS0(Value)               /* register undefined */
#define Iodd_WREG_P_CS1(Value)               /* register undefined */
#define Iodd_WREG_P_CS2(Value)               /* register undefined */
#define Iodd_WREG_P_CS3(Value)               /* register undefined */
#define Iodd_WREG_P_CS4(Value)               /* register undefined */
#define Iodd_WREG_P_CS5(Value)               /* register undefined */
#define Iodd_WREG_P_CS6(Value)               /* register undefined */
#define Iodd_WREG_P_CS7(Value)               /* register undefined */

#endif

#if                                          \
      defined(__NEC_V850_FE3_F3370__)||      \
      defined(__NEC_V850_FE3_F3371__)

#define Iodd_RREG_M_CS0                      /* register undefined */
#define Iodd_RREG_M_CS1                      /* register undefined */
#define Iodd_RREG_M_CS2                      /* register undefined */
#define Iodd_RREG_M_CS3                      /* register undefined */
#define Iodd_RREG_M_CS4                      /* register undefined */
#define Iodd_RREG_M_CS5                      /* register undefined */
#define Iodd_RREG_M_CS6                      /* register undefined */
#define Iodd_RREG_M_CS7                      /* register undefined */

#define Iodd_WREG_M_CS0(Value)               /* register undefined */
#define Iodd_WREG_M_CS1(Value)               /* register undefined */
#define Iodd_WREG_M_CS2(Value)               /* register undefined */
#define Iodd_WREG_M_CS3(Value)               /* register undefined */
#define Iodd_WREG_M_CS4(Value)               /* register undefined */
#define Iodd_WREG_M_CS5(Value)               /* register undefined */
#define Iodd_WREG_M_CS6(Value)               /* register undefined */
#define Iodd_WREG_M_CS7(Value)               /* register undefined */

#endif

#if                                          \
      defined(__NEC_V850_FE3_F3370__)||      \
      defined(__NEC_V850_FE3_F3371__)||      \
      defined(__NEC_V850_FF3_F3372__)||      \
      defined(__NEC_V850_FF3_F3373__)||      \
      defined(__NEC_V850_FG3_F3374__)||      \
      defined(__NEC_V850_FG3_F3375__)||      \
      defined(__NEC_V850_FG3_F3376__)||      \
      defined(__NEC_V850_FG3_F3377__)||      \
      defined(__NEC_V850_FF3L_F3618__)

#define Iodd_RREG_MC_CS0                     /* register undefined */
#define Iodd_RREG_MC_CS1                     /* register undefined */
#define Iodd_RREG_MC_CS2                     /* register undefined */
#define Iodd_RREG_MC_CS3                     /* register undefined */
#define Iodd_RREG_MC_CS4                     /* register undefined */
#define Iodd_RREG_MC_CS5                     /* register undefined */
#define Iodd_RREG_MC_CS6                     /* register undefined */
#define Iodd_RREG_MC_CS7                     /* register undefined */

#define Iodd_WREG_MC_CS0(Value)              /* register undefined */
#define Iodd_WREG_MC_CS1(Value)              /* register undefined */
#define Iodd_WREG_MC_CS2(Value)              /* register undefined */
#define Iodd_WREG_MC_CS3(Value)              /* register undefined */
#define Iodd_WREG_MC_CS4(Value)              /* register undefined */
#define Iodd_WREG_MC_CS5(Value)              /* register undefined */
#define Iodd_WREG_MC_CS6(Value)              /* register undefined */
#define Iodd_WREG_MC_CS7(Value)              /* register undefined */

#endif

#if                                          \
      defined(__NEC_V850_Fx3__)

#define Iodd_RREG_FC_CS0                     /* register undefined */
#define Iodd_RREG_FC_CS1                     /* register undefined */
#define Iodd_RREG_FC_CS2                     /* register undefined */
#define Iodd_RREG_FC_CS3                     /* register undefined */
#define Iodd_RREG_FC_CS4                     /* register undefined */
#define Iodd_RREG_FC_CS5                     /* register undefined */
#define Iodd_RREG_FC_CS6                     /* register undefined */
#define Iodd_RREG_FC_CS7                     /* register undefined */

#define Iodd_WREG_FC_CS0(Value)              /* register undefined */
#define Iodd_WREG_FC_CS1(Value)              /* register undefined */
#define Iodd_WREG_FC_CS2(Value)              /* register undefined */
#define Iodd_WREG_FC_CS3(Value)              /* register undefined */
#define Iodd_WREG_FC_CS4(Value)              /* register undefined */
#define Iodd_WREG_FC_CS5(Value)              /* register undefined */
#define Iodd_WREG_FC_CS6(Value)              /* register undefined */
#define Iodd_WREG_FC_CS7(Value)              /* register undefined */

#endif

#if                                          \
      defined(__NEC_V850_Fx3__)

#define Iodd_RREG_FCE_CS0                    /* register undefined */
#define Iodd_RREG_FCE_CS1                    /* register undefined */
#define Iodd_RREG_FCE_CS2                    /* register undefined */
#define Iodd_RREG_FCE_CS3                    /* register undefined */
#define Iodd_RREG_FCE_CS4                    /* register undefined */
#define Iodd_RREG_FCE_CS5                    /* register undefined */
#define Iodd_RREG_FCE_CS6                    /* register undefined */
#define Iodd_RREG_FCE_CS7                    /* register undefined */

#define Iodd_WREG_FCE_CS0(Value)             /* register undefined */
#define Iodd_WREG_FCE_CS1(Value)             /* register undefined */
#define Iodd_WREG_FCE_CS2(Value)             /* register undefined */
#define Iodd_WREG_FCE_CS3(Value)             /* register undefined */
#define Iodd_WREG_FCE_CS4(Value)             /* register undefined */
#define Iodd_WREG_FCE_CS5(Value)             /* register undefined */
#define Iodd_WREG_FCE_CS6(Value)             /* register undefined */
#define Iodd_WREG_FCE_CS7(Value)             /* register undefined */

#endif

#if                                          \
      defined(__NEC_V850_Fx3__)

#define Iodd_RREG_PU_CS0                     /* register undefined */
#define Iodd_RREG_PU_CS1                     /* register undefined */
#define Iodd_RREG_PU_CS2                     /* register undefined */
#define Iodd_RREG_PU_CS3                     /* register undefined */
#define Iodd_RREG_PU_CS4                     /* register undefined */
#define Iodd_RREG_PU_CS5                     /* register undefined */
#define Iodd_RREG_PU_CS6                     /* register undefined */
#define Iodd_RREG_PU_CS7                     /* register undefined */

#define Iodd_WREG_PU_CS0(Value)              /* register undefined */
#define Iodd_WREG_PU_CS1(Value)              /* register undefined */
#define Iodd_WREG_PU_CS2(Value)              /* register undefined */
#define Iodd_WREG_PU_CS3(Value)              /* register undefined */
#define Iodd_WREG_PU_CS4(Value)              /* register undefined */
#define Iodd_WREG_PU_CS5(Value)              /* register undefined */
#define Iodd_WREG_PU_CS6(Value)              /* register undefined */
#define Iodd_WREG_PU_CS7(Value)              /* register undefined */

#endif

#if                                          \
      defined(__NEC_V850_Fx3__)

#define Iodd_RREG_PF_CS0                     /* register undefined */
#define Iodd_RREG_PF_CS1                     /* register undefined */
#define Iodd_RREG_PF_CS2                     /* register undefined */
#define Iodd_RREG_PF_CS3                     /* register undefined */
#define Iodd_RREG_PF_CS4                     /* register undefined */
#define Iodd_RREG_PF_CS5                     /* register undefined */
#define Iodd_RREG_PF_CS6                     /* register undefined */
#define Iodd_RREG_PF_CS7                     /* register undefined */

#define Iodd_WREG_PF_CS0(Value)              /* register undefined */
#define Iodd_WREG_PF_CS1(Value)              /* register undefined */
#define Iodd_WREG_PF_CS2(Value)              /* register undefined */
#define Iodd_WREG_PF_CS3(Value)              /* register undefined */
#define Iodd_WREG_PF_CS4(Value)              /* register undefined */
#define Iodd_WREG_PF_CS5(Value)              /* register undefined */
#define Iodd_WREG_PF_CS6(Value)              /* register undefined */
#define Iodd_WREG_PF_CS7(Value)              /* register undefined */

#endif

/* Definitions PORT CT */

#if                                          \
      defined(__NEC_V850_FF3_F3372__)||      \
      defined(__NEC_V850_FF3_F3373__)||      \
      defined(__NEC_V850_FG3_F3374__)||      \
      defined(__NEC_V850_FG3_F3375__)||      \
      defined(__NEC_V850_FG3_F3376__)||      \
      defined(__NEC_V850_FG3_F3377__)||      \
      defined(__NEC_V850_FF3L_F3618__)

#define Iodd_RREG_P_CT0                      TARG_ReadBit(PCT, BIT0)
#define Iodd_RREG_P_CT1                      TARG_ReadBit(PCT, BIT1)
#define Iodd_RREG_P_CT2                      /* read access defined but should not be used */
#define Iodd_RREG_P_CT3                      /* read access defined but should not be used */
#define Iodd_RREG_P_CT4                      TARG_ReadBit(PCT, BIT4)
#define Iodd_RREG_P_CT5                      /* read access defined but should not be used */
#define Iodd_RREG_P_CT6                      TARG_ReadBit(PCT, BIT6)
#define Iodd_RREG_P_CT7                      /* read access defined but should not be used */

#define Iodd_WREG_P_CT0(Value)               TARG_WriteBit(PCT, BIT0, Value)
#define Iodd_WREG_P_CT1(Value)               TARG_WriteBit(PCT, BIT1, Value)
#define Iodd_WREG_P_CT2(Value)               /* write access not defined */
#define Iodd_WREG_P_CT3(Value)               /* write access not defined */
#define Iodd_WREG_P_CT4(Value)               TARG_WriteBit(PCT, BIT4, Value)
#define Iodd_WREG_P_CT5(Value)               /* write access not defined */
#define Iodd_WREG_P_CT6(Value)               TARG_WriteBit(PCT, BIT6, Value)
#define Iodd_WREG_P_CT7(Value)               /* write access not defined */

#endif

#if                                          \
      defined(__NEC_V850_FJ3_F3378__)||      \
      defined(__NEC_V850_FJ3_F3379__)||      \
      defined(__NEC_V850_FJ3_F3380__)||      \
      defined(__NEC_V850_FJ3_F3381__)||      \
      defined(__NEC_V850_FJ3_F3382__)||      \
      defined(__NEC_V850_FK3_F3383__)||      \
      defined(__NEC_V850_FK3_F3384__)||      \
      defined(__NEC_V850_FK3_F3385__)

#define Iodd_RREG_P_CT0                      TARG_ReadBit(PCT, BIT0)
#define Iodd_RREG_P_CT1                      TARG_ReadBit(PCT, BIT1)
#define Iodd_RREG_P_CT2                      TARG_ReadBit(PCT, BIT2)
#define Iodd_RREG_P_CT3                      TARG_ReadBit(PCT, BIT3)
#define Iodd_RREG_P_CT4                      TARG_ReadBit(PCT, BIT4)
#define Iodd_RREG_P_CT5                      TARG_ReadBit(PCT, BIT5)
#define Iodd_RREG_P_CT6                      TARG_ReadBit(PCT, BIT6)
#define Iodd_RREG_P_CT7                      TARG_ReadBit(PCT, BIT7)

#define Iodd_WREG_P_CT0(Value)               TARG_WriteBit(PCT, BIT0, Value)
#define Iodd_WREG_P_CT1(Value)               TARG_WriteBit(PCT, BIT1, Value)
#define Iodd_WREG_P_CT2(Value)               TARG_WriteBit(PCT, BIT2, Value)
#define Iodd_WREG_P_CT3(Value)               TARG_WriteBit(PCT, BIT3, Value)
#define Iodd_WREG_P_CT4(Value)               TARG_WriteBit(PCT, BIT4, Value)
#define Iodd_WREG_P_CT5(Value)               TARG_WriteBit(PCT, BIT5, Value)
#define Iodd_WREG_P_CT6(Value)               TARG_WriteBit(PCT, BIT6, Value)
#define Iodd_WREG_P_CT7(Value)               TARG_WriteBit(PCT, BIT7, Value)

#endif

#if                                          \
      defined(__NEC_V850_FF3_F3372__)||      \
      defined(__NEC_V850_FF3_F3373__)||      \
      defined(__NEC_V850_FG3_F3374__)||      \
      defined(__NEC_V850_FG3_F3375__)||      \
      defined(__NEC_V850_FG3_F3376__)||      \
      defined(__NEC_V850_FG3_F3377__)||      \
      defined(__NEC_V850_FF3L_F3618__)

#define Iodd_RREG_M_CT0                      TARG_ReadBit(PMCT, BIT0)
#define Iodd_RREG_M_CT1                      TARG_ReadBit(PMCT, BIT1)
#define Iodd_RREG_M_CT2                      /* read access defined but should not be used */
#define Iodd_RREG_M_CT3                      /* read access defined but should not be used */
#define Iodd_RREG_M_CT4                      TARG_ReadBit(PMCT, BIT4)
#define Iodd_RREG_M_CT5                      /* read access defined but should not be used */
#define Iodd_RREG_M_CT6                      TARG_ReadBit(PMCT, BIT6)
#define Iodd_RREG_M_CT7                      /* read access defined but should not be used */

#define Iodd_WREG_M_CT0(Value)               TARG_WriteBit(PMCT, BIT0, Value)
#define Iodd_WREG_M_CT1(Value)               TARG_WriteBit(PMCT, BIT1, Value)
#define Iodd_WREG_M_CT2(Value)               /* write access not defined */
#define Iodd_WREG_M_CT3(Value)               /* write access not defined */
#define Iodd_WREG_M_CT4(Value)               TARG_WriteBit(PMCT, BIT4, Value)
#define Iodd_WREG_M_CT5(Value)               /* write access not defined */
#define Iodd_WREG_M_CT6(Value)               TARG_WriteBit(PMCT, BIT6, Value)
#define Iodd_WREG_M_CT7(Value)               /* write access not defined */

#endif

#if                                          \
      defined(__NEC_V850_FJ3_F3378__)||      \
      defined(__NEC_V850_FJ3_F3379__)||      \
      defined(__NEC_V850_FJ3_F3380__)||      \
      defined(__NEC_V850_FJ3_F3381__)||      \
      defined(__NEC_V850_FJ3_F3382__)||      \
      defined(__NEC_V850_FK3_F3383__)||      \
      defined(__NEC_V850_FK3_F3384__)||      \
      defined(__NEC_V850_FK3_F3385__)

#define Iodd_RREG_M_CT0                      TARG_ReadBit(PMCT, BIT0)
#define Iodd_RREG_M_CT1                      TARG_ReadBit(PMCT, BIT1)
#define Iodd_RREG_M_CT2                      TARG_ReadBit(PMCT, BIT2)
#define Iodd_RREG_M_CT3                      TARG_ReadBit(PMCT, BIT3)
#define Iodd_RREG_M_CT4                      TARG_ReadBit(PMCT, BIT4)
#define Iodd_RREG_M_CT5                      TARG_ReadBit(PMCT, BIT5)
#define Iodd_RREG_M_CT6                      TARG_ReadBit(PMCT, BIT6)
#define Iodd_RREG_M_CT7                      TARG_ReadBit(PMCT, BIT7)

#define Iodd_WREG_M_CT0(Value)               TARG_WriteBit(PMCT, BIT0, Value)
#define Iodd_WREG_M_CT1(Value)               TARG_WriteBit(PMCT, BIT1, Value)
#define Iodd_WREG_M_CT2(Value)               TARG_WriteBit(PMCT, BIT2, Value)
#define Iodd_WREG_M_CT3(Value)               TARG_WriteBit(PMCT, BIT3, Value)
#define Iodd_WREG_M_CT4(Value)               TARG_WriteBit(PMCT, BIT4, Value)
#define Iodd_WREG_M_CT5(Value)               TARG_WriteBit(PMCT, BIT5, Value)
#define Iodd_WREG_M_CT6(Value)               TARG_WriteBit(PMCT, BIT6, Value)
#define Iodd_WREG_M_CT7(Value)               TARG_WriteBit(PMCT, BIT7, Value)

#endif

#if                                          \
      defined(__NEC_V850_FJ3_F3378__)||      \
      defined(__NEC_V850_FJ3_F3379__)||      \
      defined(__NEC_V850_FJ3_F3380__)||      \
      defined(__NEC_V850_FJ3_F3381__)||      \
      defined(__NEC_V850_FJ3_F3382__)||      \
      defined(__NEC_V850_FK3_F3383__)||      \
      defined(__NEC_V850_FK3_F3384__)||      \
      defined(__NEC_V850_FK3_F3385__)

#define Iodd_RREG_MC_CT0                     TARG_ReadBit(PMCCT, BIT0)
#define Iodd_RREG_MC_CT1                     TARG_ReadBit(PMCCT, BIT1)
#define Iodd_RREG_MC_CT2                     /* read access defined but should not be used */
#define Iodd_RREG_MC_CT3                     /* read access defined but should not be used */
#define Iodd_RREG_MC_CT4                     TARG_ReadBit(PMCCT, BIT4)
#define Iodd_RREG_MC_CT5                     /* read access defined but should not be used */
#define Iodd_RREG_MC_CT6                     TARG_ReadBit(PMCCT, BIT6)
#define Iodd_RREG_MC_CT7                     /* read access defined but should not be used */

#define Iodd_WREG_MC_CT0(Value)              TARG_WriteBit(PMCCT, BIT0, Value)
#define Iodd_WREG_MC_CT1(Value)              TARG_WriteBit(PMCCT, BIT1, Value)
#define Iodd_WREG_MC_CT2(Value)              /* write access not defined */
#define Iodd_WREG_MC_CT3(Value)              /* write access not defined */
#define Iodd_WREG_MC_CT4(Value)              TARG_WriteBit(PMCCT, BIT4, Value)
#define Iodd_WREG_MC_CT5(Value)              /* write access not defined */
#define Iodd_WREG_MC_CT6(Value)              TARG_WriteBit(PMCCT, BIT6, Value)
#define Iodd_WREG_MC_CT7(Value)              /* write access not defined */

#endif

#if                                          \
      defined(__NEC_V850_FE3_F3370__)||      \
      defined(__NEC_V850_FE3_F3371__)

#define Iodd_RREG_P_CT0                      /* register undefined */
#define Iodd_RREG_P_CT1                      /* register undefined */
#define Iodd_RREG_P_CT2                      /* register undefined */
#define Iodd_RREG_P_CT3                      /* register undefined */
#define Iodd_RREG_P_CT4                      /* register undefined */
#define Iodd_RREG_P_CT5                      /* register undefined */
#define Iodd_RREG_P_CT6                      /* register undefined */
#define Iodd_RREG_P_CT7                      /* register undefined */

#define Iodd_WREG_P_CT0(Value)               /* register undefined */
#define Iodd_WREG_P_CT1(Value)               /* register undefined */
#define Iodd_WREG_P_CT2(Value)               /* register undefined */
#define Iodd_WREG_P_CT3(Value)               /* register undefined */
#define Iodd_WREG_P_CT4(Value)               /* register undefined */
#define Iodd_WREG_P_CT5(Value)               /* register undefined */
#define Iodd_WREG_P_CT6(Value)               /* register undefined */
#define Iodd_WREG_P_CT7(Value)               /* register undefined */

#endif

#if                                          \
      defined(__NEC_V850_FE3_F3370__)||      \
      defined(__NEC_V850_FE3_F3371__)

#define Iodd_RREG_M_CT0                      /* register undefined */
#define Iodd_RREG_M_CT1                      /* register undefined */
#define Iodd_RREG_M_CT2                      /* register undefined */
#define Iodd_RREG_M_CT3                      /* register undefined */
#define Iodd_RREG_M_CT4                      /* register undefined */
#define Iodd_RREG_M_CT5                      /* register undefined */
#define Iodd_RREG_M_CT6                      /* register undefined */
#define Iodd_RREG_M_CT7                      /* register undefined */

#define Iodd_WREG_M_CT0(Value)               /* register undefined */
#define Iodd_WREG_M_CT1(Value)               /* register undefined */
#define Iodd_WREG_M_CT2(Value)               /* register undefined */
#define Iodd_WREG_M_CT3(Value)               /* register undefined */
#define Iodd_WREG_M_CT4(Value)               /* register undefined */
#define Iodd_WREG_M_CT5(Value)               /* register undefined */
#define Iodd_WREG_M_CT6(Value)               /* register undefined */
#define Iodd_WREG_M_CT7(Value)               /* register undefined */

#endif

#if                                          \
      defined(__NEC_V850_FE3_F3370__)||      \
      defined(__NEC_V850_FE3_F3371__)||      \
      defined(__NEC_V850_FF3_F3372__)||      \
      defined(__NEC_V850_FF3_F3373__)||      \
      defined(__NEC_V850_FG3_F3374__)||      \
      defined(__NEC_V850_FG3_F3375__)||      \
      defined(__NEC_V850_FG3_F3376__)||      \
      defined(__NEC_V850_FG3_F3377__)||      \
      defined(__NEC_V850_FF3L_F3618__)

#define Iodd_RREG_MC_CT0                     /* register undefined */
#define Iodd_RREG_MC_CT1                     /* register undefined */
#define Iodd_RREG_MC_CT2                     /* register undefined */
#define Iodd_RREG_MC_CT3                     /* register undefined */
#define Iodd_RREG_MC_CT4                     /* register undefined */
#define Iodd_RREG_MC_CT5                     /* register undefined */
#define Iodd_RREG_MC_CT6                     /* register undefined */
#define Iodd_RREG_MC_CT7                     /* register undefined */

#define Iodd_WREG_MC_CT0(Value)              /* register undefined */
#define Iodd_WREG_MC_CT1(Value)              /* register undefined */
#define Iodd_WREG_MC_CT2(Value)              /* register undefined */
#define Iodd_WREG_MC_CT3(Value)              /* register undefined */
#define Iodd_WREG_MC_CT4(Value)              /* register undefined */
#define Iodd_WREG_MC_CT5(Value)              /* register undefined */
#define Iodd_WREG_MC_CT6(Value)              /* register undefined */
#define Iodd_WREG_MC_CT7(Value)              /* register undefined */

#endif

#if                                          \
      defined(__NEC_V850_Fx3__)

#define Iodd_RREG_FC_CT0                     /* register undefined */
#define Iodd_RREG_FC_CT1                     /* register undefined */
#define Iodd_RREG_FC_CT2                     /* register undefined */
#define Iodd_RREG_FC_CT3                     /* register undefined */
#define Iodd_RREG_FC_CT4                     /* register undefined */
#define Iodd_RREG_FC_CT5                     /* register undefined */
#define Iodd_RREG_FC_CT6                     /* register undefined */
#define Iodd_RREG_FC_CT7                     /* register undefined */

#define Iodd_WREG_FC_CT0(Value)              /* register undefined */
#define Iodd_WREG_FC_CT1(Value)              /* register undefined */
#define Iodd_WREG_FC_CT2(Value)              /* register undefined */
#define Iodd_WREG_FC_CT3(Value)              /* register undefined */
#define Iodd_WREG_FC_CT4(Value)              /* register undefined */
#define Iodd_WREG_FC_CT5(Value)              /* register undefined */
#define Iodd_WREG_FC_CT6(Value)              /* register undefined */
#define Iodd_WREG_FC_CT7(Value)              /* register undefined */

#endif

#if                                          \
      defined(__NEC_V850_Fx3__)

#define Iodd_RREG_FCE_CT0                    /* register undefined */
#define Iodd_RREG_FCE_CT1                    /* register undefined */
#define Iodd_RREG_FCE_CT2                    /* register undefined */
#define Iodd_RREG_FCE_CT3                    /* register undefined */
#define Iodd_RREG_FCE_CT4                    /* register undefined */
#define Iodd_RREG_FCE_CT5                    /* register undefined */
#define Iodd_RREG_FCE_CT6                    /* register undefined */
#define Iodd_RREG_FCE_CT7                    /* register undefined */

#define Iodd_WREG_FCE_CT0(Value)             /* register undefined */
#define Iodd_WREG_FCE_CT1(Value)             /* register undefined */
#define Iodd_WREG_FCE_CT2(Value)             /* register undefined */
#define Iodd_WREG_FCE_CT3(Value)             /* register undefined */
#define Iodd_WREG_FCE_CT4(Value)             /* register undefined */
#define Iodd_WREG_FCE_CT5(Value)             /* register undefined */
#define Iodd_WREG_FCE_CT6(Value)             /* register undefined */
#define Iodd_WREG_FCE_CT7(Value)             /* register undefined */

#endif

#if                                          \
      defined(__NEC_V850_Fx3__)

#define Iodd_RREG_PU_CT0                     /* register undefined */
#define Iodd_RREG_PU_CT1                     /* register undefined */
#define Iodd_RREG_PU_CT2                     /* register undefined */
#define Iodd_RREG_PU_CT3                     /* register undefined */
#define Iodd_RREG_PU_CT4                     /* register undefined */
#define Iodd_RREG_PU_CT5                     /* register undefined */
#define Iodd_RREG_PU_CT6                     /* register undefined */
#define Iodd_RREG_PU_CT7                     /* register undefined */

#define Iodd_WREG_PU_CT0(Value)              /* register undefined */
#define Iodd_WREG_PU_CT1(Value)              /* register undefined */
#define Iodd_WREG_PU_CT2(Value)              /* register undefined */
#define Iodd_WREG_PU_CT3(Value)              /* register undefined */
#define Iodd_WREG_PU_CT4(Value)              /* register undefined */
#define Iodd_WREG_PU_CT5(Value)              /* register undefined */
#define Iodd_WREG_PU_CT6(Value)              /* register undefined */
#define Iodd_WREG_PU_CT7(Value)              /* register undefined */

#endif

#if                                          \
      defined(__NEC_V850_Fx3__)

#define Iodd_RREG_PF_CT0                     /* register undefined */
#define Iodd_RREG_PF_CT1                     /* register undefined */
#define Iodd_RREG_PF_CT2                     /* register undefined */
#define Iodd_RREG_PF_CT3                     /* register undefined */
#define Iodd_RREG_PF_CT4                     /* register undefined */
#define Iodd_RREG_PF_CT5                     /* register undefined */
#define Iodd_RREG_PF_CT6                     /* register undefined */
#define Iodd_RREG_PF_CT7                     /* register undefined */

#define Iodd_WREG_PF_CT0(Value)              /* register undefined */
#define Iodd_WREG_PF_CT1(Value)              /* register undefined */
#define Iodd_WREG_PF_CT2(Value)              /* register undefined */
#define Iodd_WREG_PF_CT3(Value)              /* register undefined */
#define Iodd_WREG_PF_CT4(Value)              /* register undefined */
#define Iodd_WREG_PF_CT5(Value)              /* register undefined */
#define Iodd_WREG_PF_CT6(Value)              /* register undefined */
#define Iodd_WREG_PF_CT7(Value)              /* register undefined */

#endif

/* Definitions PORT DL */

#if                                          \
      defined(__NEC_V850_FE3_F3370__)||      \
      defined(__NEC_V850_FE3_F3371__)

#define Iodd_RREG_P_DL0                      TARG_ReadBit(PDLL, BIT0)
#define Iodd_RREG_P_DL1                      TARG_ReadBit(PDLL, BIT1)
#define Iodd_RREG_P_DL2                      TARG_ReadBit(PDLL, BIT2)
#define Iodd_RREG_P_DL3                      TARG_ReadBit(PDLL, BIT3)
#define Iodd_RREG_P_DL4                      TARG_ReadBit(PDLL, BIT4)
#define Iodd_RREG_P_DL5                      TARG_ReadBit(PDLL, BIT5)
#define Iodd_RREG_P_DL6                      TARG_ReadBit(PDLL, BIT6)
#define Iodd_RREG_P_DL7                      TARG_ReadBit(PDLL, BIT7)

#define Iodd_WREG_P_DL0(Value)               TARG_WriteBit(PDLL, BIT0, Value)
#define Iodd_WREG_P_DL1(Value)               TARG_WriteBit(PDLL, BIT1, Value)
#define Iodd_WREG_P_DL2(Value)               TARG_WriteBit(PDLL, BIT2, Value)
#define Iodd_WREG_P_DL3(Value)               TARG_WriteBit(PDLL, BIT3, Value)
#define Iodd_WREG_P_DL4(Value)               TARG_WriteBit(PDLL, BIT4, Value)
#define Iodd_WREG_P_DL5(Value)               TARG_WriteBit(PDLL, BIT5, Value)
#define Iodd_WREG_P_DL6(Value)               TARG_WriteBit(PDLL, BIT6, Value)
#define Iodd_WREG_P_DL7(Value)               TARG_WriteBit(PDLL, BIT7, Value)

#endif

#if                                          \
      defined(__NEC_V850_FF3_F3372__)||      \
      defined(__NEC_V850_FF3_F3373__)||      \
      defined(__NEC_V850_FF3L_F3618__)

#define Iodd_RREG_P_DL0                      TARG_ReadBit(PDLL, BIT0)
#define Iodd_RREG_P_DL1                      TARG_ReadBit(PDLL, BIT1)
#define Iodd_RREG_P_DL2                      TARG_ReadBit(PDLL, BIT2)
#define Iodd_RREG_P_DL3                      TARG_ReadBit(PDLL, BIT3)
#define Iodd_RREG_P_DL4                      TARG_ReadBit(PDLL, BIT4)
#define Iodd_RREG_P_DL5                      TARG_ReadBit(PDLL, BIT5)
#define Iodd_RREG_P_DL6                      TARG_ReadBit(PDLL, BIT6)
#define Iodd_RREG_P_DL7                      TARG_ReadBit(PDLL, BIT7)
#define Iodd_RREG_P_DL8                      TARG_ReadBit(PDLH, BIT0)
#define Iodd_RREG_P_DL9                      TARG_ReadBit(PDLH, BIT1)
#define Iodd_RREG_P_DL10                     TARG_ReadBit(PDLH, BIT2)
#define Iodd_RREG_P_DL11                     TARG_ReadBit(PDLH, BIT3)
#define Iodd_RREG_P_DL12                     /* read access defined but should not be used */
#define Iodd_RREG_P_DL13                     /* read access defined but should not be used */
#define Iodd_RREG_P_DL14                     /* read access defined but should not be used */
#define Iodd_RREG_P_DL15                     /* read access defined but should not be used */

#define Iodd_WREG_P_DL0(Value)               TARG_WriteBit(PDLL, BIT0, Value)
#define Iodd_WREG_P_DL1(Value)               TARG_WriteBit(PDLL, BIT1, Value)
#define Iodd_WREG_P_DL2(Value)               TARG_WriteBit(PDLL, BIT2, Value)
#define Iodd_WREG_P_DL3(Value)               TARG_WriteBit(PDLL, BIT3, Value)
#define Iodd_WREG_P_DL4(Value)               TARG_WriteBit(PDLL, BIT4, Value)
#define Iodd_WREG_P_DL5(Value)               TARG_WriteBit(PDLL, BIT5, Value)
#define Iodd_WREG_P_DL6(Value)               TARG_WriteBit(PDLL, BIT6, Value)
#define Iodd_WREG_P_DL7(Value)               TARG_WriteBit(PDLL, BIT7, Value)
#define Iodd_WREG_P_DL8(Value)               TARG_WriteBit(PDLH, BIT0, Value)
#define Iodd_WREG_P_DL9(Value)               TARG_WriteBit(PDLH, BIT1, Value)
#define Iodd_WREG_P_DL10(Value)              TARG_WriteBit(PDLH, BIT2, Value)
#define Iodd_WREG_P_DL11(Value)              TARG_WriteBit(PDLH, BIT3, Value)
#define Iodd_WREG_P_DL12(Value)              /* write access not defined */
#define Iodd_WREG_P_DL13(Value)              /* write access not defined */
#define Iodd_WREG_P_DL14(Value)              /* write access not defined */
#define Iodd_WREG_P_DL15(Value)              /* write access not defined */

#endif

#if                                          \
      defined(__NEC_V850_FG3_F3374__)||      \
      defined(__NEC_V850_FG3_F3375__)||      \
      defined(__NEC_V850_FG3_F3376__)||      \
      defined(__NEC_V850_FG3_F3377__)

#define Iodd_RREG_P_DL0                      TARG_ReadBit(PDLL, BIT0)
#define Iodd_RREG_P_DL1                      TARG_ReadBit(PDLL, BIT1)
#define Iodd_RREG_P_DL2                      TARG_ReadBit(PDLL, BIT2)
#define Iodd_RREG_P_DL3                      TARG_ReadBit(PDLL, BIT3)
#define Iodd_RREG_P_DL4                      TARG_ReadBit(PDLL, BIT4)
#define Iodd_RREG_P_DL5                      TARG_ReadBit(PDLL, BIT5)
#define Iodd_RREG_P_DL6                      TARG_ReadBit(PDLL, BIT6)
#define Iodd_RREG_P_DL7                      TARG_ReadBit(PDLL, BIT7)
#define Iodd_RREG_P_DL8                      TARG_ReadBit(PDLH, BIT0)
#define Iodd_RREG_P_DL9                      TARG_ReadBit(PDLH, BIT1)
#define Iodd_RREG_P_DL10                     TARG_ReadBit(PDLH, BIT2)
#define Iodd_RREG_P_DL11                     TARG_ReadBit(PDLH, BIT3)
#define Iodd_RREG_P_DL12                     TARG_ReadBit(PDLH, BIT4)
#define Iodd_RREG_P_DL13                     TARG_ReadBit(PDLH, BIT5)
#define Iodd_RREG_P_DL14                     /* read access defined but should not be used */
#define Iodd_RREG_P_DL15                     /* read access defined but should not be used */

#define Iodd_WREG_P_DL0(Value)               TARG_WriteBit(PDLL, BIT0, Value)
#define Iodd_WREG_P_DL1(Value)               TARG_WriteBit(PDLL, BIT1, Value)
#define Iodd_WREG_P_DL2(Value)               TARG_WriteBit(PDLL, BIT2, Value)
#define Iodd_WREG_P_DL3(Value)               TARG_WriteBit(PDLL, BIT3, Value)
#define Iodd_WREG_P_DL4(Value)               TARG_WriteBit(PDLL, BIT4, Value)
#define Iodd_WREG_P_DL5(Value)               TARG_WriteBit(PDLL, BIT5, Value)
#define Iodd_WREG_P_DL6(Value)               TARG_WriteBit(PDLL, BIT6, Value)
#define Iodd_WREG_P_DL7(Value)               TARG_WriteBit(PDLL, BIT7, Value)
#define Iodd_WREG_P_DL8(Value)               TARG_WriteBit(PDLH, BIT0, Value)
#define Iodd_WREG_P_DL9(Value)               TARG_WriteBit(PDLH, BIT1, Value)
#define Iodd_WREG_P_DL10(Value)              TARG_WriteBit(PDLH, BIT2, Value)
#define Iodd_WREG_P_DL11(Value)              TARG_WriteBit(PDLH, BIT3, Value)
#define Iodd_WREG_P_DL12(Value)              TARG_WriteBit(PDLH, BIT4, Value)
#define Iodd_WREG_P_DL13(Value)              TARG_WriteBit(PDLH, BIT5, Value)
#define Iodd_WREG_P_DL14(Value)              /* write access not defined */
#define Iodd_WREG_P_DL15(Value)              /* write access not defined */

#endif

#if                                          \
      defined(__NEC_V850_FJ3_F3378__)||      \
      defined(__NEC_V850_FJ3_F3379__)||      \
      defined(__NEC_V850_FJ3_F3380__)||      \
      defined(__NEC_V850_FJ3_F3381__)||      \
      defined(__NEC_V850_FJ3_F3382__)||      \
      defined(__NEC_V850_FK3_F3383__)||      \
      defined(__NEC_V850_FK3_F3384__)||      \
      defined(__NEC_V850_FK3_F3385__)

#define Iodd_RREG_P_DL0                      TARG_ReadBit(PDLL, BIT0)
#define Iodd_RREG_P_DL1                      TARG_ReadBit(PDLL, BIT1)
#define Iodd_RREG_P_DL2                      TARG_ReadBit(PDLL, BIT2)
#define Iodd_RREG_P_DL3                      TARG_ReadBit(PDLL, BIT3)
#define Iodd_RREG_P_DL4                      TARG_ReadBit(PDLL, BIT4)
#define Iodd_RREG_P_DL5                      TARG_ReadBit(PDLL, BIT5)
#define Iodd_RREG_P_DL6                      TARG_ReadBit(PDLL, BIT6)
#define Iodd_RREG_P_DL7                      TARG_ReadBit(PDLL, BIT7)
#define Iodd_RREG_P_DL8                      TARG_ReadBit(PDLH, BIT0)
#define Iodd_RREG_P_DL9                      TARG_ReadBit(PDLH, BIT1)
#define Iodd_RREG_P_DL10                     TARG_ReadBit(PDLH, BIT2)
#define Iodd_RREG_P_DL11                     TARG_ReadBit(PDLH, BIT3)
#define Iodd_RREG_P_DL12                     TARG_ReadBit(PDLH, BIT4)
#define Iodd_RREG_P_DL13                     TARG_ReadBit(PDLH, BIT5)
#define Iodd_RREG_P_DL14                     TARG_ReadBit(PDLH, BIT6)
#define Iodd_RREG_P_DL15                     TARG_ReadBit(PDLH, BIT7)

#define Iodd_WREG_P_DL0(Value)               TARG_WriteBit(PDLL, BIT0, Value)
#define Iodd_WREG_P_DL1(Value)               TARG_WriteBit(PDLL, BIT1, Value)
#define Iodd_WREG_P_DL2(Value)               TARG_WriteBit(PDLL, BIT2, Value)
#define Iodd_WREG_P_DL3(Value)               TARG_WriteBit(PDLL, BIT3, Value)
#define Iodd_WREG_P_DL4(Value)               TARG_WriteBit(PDLL, BIT4, Value)
#define Iodd_WREG_P_DL5(Value)               TARG_WriteBit(PDLL, BIT5, Value)
#define Iodd_WREG_P_DL6(Value)               TARG_WriteBit(PDLL, BIT6, Value)
#define Iodd_WREG_P_DL7(Value)               TARG_WriteBit(PDLL, BIT7, Value)
#define Iodd_WREG_P_DL8(Value)               TARG_WriteBit(PDLH, BIT0, Value)
#define Iodd_WREG_P_DL9(Value)               TARG_WriteBit(PDLH, BIT1, Value)
#define Iodd_WREG_P_DL10(Value)              TARG_WriteBit(PDLH, BIT2, Value)
#define Iodd_WREG_P_DL11(Value)              TARG_WriteBit(PDLH, BIT3, Value)
#define Iodd_WREG_P_DL12(Value)              TARG_WriteBit(PDLH, BIT4, Value)
#define Iodd_WREG_P_DL13(Value)              TARG_WriteBit(PDLH, BIT5, Value)
#define Iodd_WREG_P_DL14(Value)              TARG_WriteBit(PDLH, BIT6, Value)
#define Iodd_WREG_P_DL15(Value)              TARG_WriteBit(PDLH, BIT7, Value)

#endif

#if                                          \
      defined(__NEC_V850_FE3_F3370__)||      \
      defined(__NEC_V850_FE3_F3371__)

#define Iodd_RREG_M_DL0                      TARG_ReadBit(PMDLL, BIT0)
#define Iodd_RREG_M_DL1                      TARG_ReadBit(PMDLL, BIT1)
#define Iodd_RREG_M_DL2                      TARG_ReadBit(PMDLL, BIT2)
#define Iodd_RREG_M_DL3                      TARG_ReadBit(PMDLL, BIT3)
#define Iodd_RREG_M_DL4                      TARG_ReadBit(PMDLL, BIT4)
#define Iodd_RREG_M_DL5                      TARG_ReadBit(PMDLL, BIT5)
#define Iodd_RREG_M_DL6                      TARG_ReadBit(PMDLL, BIT6)
#define Iodd_RREG_M_DL7                      TARG_ReadBit(PMDLL, BIT7)

#define Iodd_WREG_M_DL0(Value)               TARG_WriteBit(PMDLL, BIT0, Value)
#define Iodd_WREG_M_DL1(Value)               TARG_WriteBit(PMDLL, BIT1, Value)
#define Iodd_WREG_M_DL2(Value)               TARG_WriteBit(PMDLL, BIT2, Value)
#define Iodd_WREG_M_DL3(Value)               TARG_WriteBit(PMDLL, BIT3, Value)
#define Iodd_WREG_M_DL4(Value)               TARG_WriteBit(PMDLL, BIT4, Value)
#define Iodd_WREG_M_DL5(Value)               TARG_WriteBit(PMDLL, BIT5, Value)
#define Iodd_WREG_M_DL6(Value)               TARG_WriteBit(PMDLL, BIT6, Value)
#define Iodd_WREG_M_DL7(Value)               TARG_WriteBit(PMDLL, BIT7, Value)

#endif

#if                                          \
      defined(__NEC_V850_FF3_F3372__)||      \
      defined(__NEC_V850_FF3_F3373__)||      \
      defined(__NEC_V850_FF3L_F3618__)

#define Iodd_RREG_M_DL0                      TARG_ReadBit(PMDLL, BIT0)
#define Iodd_RREG_M_DL1                      TARG_ReadBit(PMDLL, BIT1)
#define Iodd_RREG_M_DL2                      TARG_ReadBit(PMDLL, BIT2)
#define Iodd_RREG_M_DL3                      TARG_ReadBit(PMDLL, BIT3)
#define Iodd_RREG_M_DL4                      TARG_ReadBit(PMDLL, BIT4)
#define Iodd_RREG_M_DL5                      TARG_ReadBit(PMDLL, BIT5)
#define Iodd_RREG_M_DL6                      TARG_ReadBit(PMDLL, BIT6)
#define Iodd_RREG_M_DL7                      TARG_ReadBit(PMDLL, BIT7)
#define Iodd_RREG_M_DL8                      TARG_ReadBit(PMDLH, BIT0)
#define Iodd_RREG_M_DL9                      TARG_ReadBit(PMDLH, BIT1)
#define Iodd_RREG_M_DL10                     TARG_ReadBit(PMDLH, BIT2)
#define Iodd_RREG_M_DL11                     TARG_ReadBit(PMDLH, BIT3)
#define Iodd_RREG_M_DL12                     /* read access defined but should not be used */
#define Iodd_RREG_M_DL13                     /* read access defined but should not be used */
#define Iodd_RREG_M_DL14                     /* read access defined but should not be used */
#define Iodd_RREG_M_DL15                     /* read access defined but should not be used */

#define Iodd_WREG_M_DL0(Value)               TARG_WriteBit(PMDLL, BIT0, Value)
#define Iodd_WREG_M_DL1(Value)               TARG_WriteBit(PMDLL, BIT1, Value)
#define Iodd_WREG_M_DL2(Value)               TARG_WriteBit(PMDLL, BIT2, Value)
#define Iodd_WREG_M_DL3(Value)               TARG_WriteBit(PMDLL, BIT3, Value)
#define Iodd_WREG_M_DL4(Value)               TARG_WriteBit(PMDLL, BIT4, Value)
#define Iodd_WREG_M_DL5(Value)               TARG_WriteBit(PMDLL, BIT5, Value)
#define Iodd_WREG_M_DL6(Value)               TARG_WriteBit(PMDLL, BIT6, Value)
#define Iodd_WREG_M_DL7(Value)               TARG_WriteBit(PMDLL, BIT7, Value)
#define Iodd_WREG_M_DL8(Value)               TARG_WriteBit(PMDLH, BIT0, Value)
#define Iodd_WREG_M_DL9(Value)               TARG_WriteBit(PMDLH, BIT1, Value)
#define Iodd_WREG_M_DL10(Value)              TARG_WriteBit(PMDLH, BIT2, Value)
#define Iodd_WREG_M_DL11(Value)              TARG_WriteBit(PMDLH, BIT3, Value)
#define Iodd_WREG_M_DL12(Value)              /* write access not defined */
#define Iodd_WREG_M_DL13(Value)              /* write access not defined */
#define Iodd_WREG_M_DL14(Value)              /* write access not defined */
#define Iodd_WREG_M_DL15(Value)              /* write access not defined */

#endif

#if                                          \
      defined(__NEC_V850_FG3_F3374__)||      \
      defined(__NEC_V850_FG3_F3375__)||      \
      defined(__NEC_V850_FG3_F3376__)||      \
      defined(__NEC_V850_FG3_F3377__)

#define Iodd_RREG_M_DL0                      TARG_ReadBit(PMDLL, BIT0)
#define Iodd_RREG_M_DL1                      TARG_ReadBit(PMDLL, BIT1)
#define Iodd_RREG_M_DL2                      TARG_ReadBit(PMDLL, BIT2)
#define Iodd_RREG_M_DL3                      TARG_ReadBit(PMDLL, BIT3)
#define Iodd_RREG_M_DL4                      TARG_ReadBit(PMDLL, BIT4)
#define Iodd_RREG_M_DL5                      TARG_ReadBit(PMDLL, BIT5)
#define Iodd_RREG_M_DL6                      TARG_ReadBit(PMDLL, BIT6)
#define Iodd_RREG_M_DL7                      TARG_ReadBit(PMDLL, BIT7)
#define Iodd_RREG_M_DL8                      TARG_ReadBit(PMDLH, BIT0)
#define Iodd_RREG_M_DL9                      TARG_ReadBit(PMDLH, BIT1)
#define Iodd_RREG_M_DL10                     TARG_ReadBit(PMDLH, BIT2)
#define Iodd_RREG_M_DL11                     TARG_ReadBit(PMDLH, BIT3)
#define Iodd_RREG_M_DL12                     TARG_ReadBit(PMDLH, BIT4)
#define Iodd_RREG_M_DL13                     TARG_ReadBit(PMDLH, BIT5)
#define Iodd_RREG_M_DL14                     /* read access defined but should not be used */
#define Iodd_RREG_M_DL15                     /* read access defined but should not be used */

#define Iodd_WREG_M_DL0(Value)               TARG_WriteBit(PMDLL, BIT0, Value)
#define Iodd_WREG_M_DL1(Value)               TARG_WriteBit(PMDLL, BIT1, Value)
#define Iodd_WREG_M_DL2(Value)               TARG_WriteBit(PMDLL, BIT2, Value)
#define Iodd_WREG_M_DL3(Value)               TARG_WriteBit(PMDLL, BIT3, Value)
#define Iodd_WREG_M_DL4(Value)               TARG_WriteBit(PMDLL, BIT4, Value)
#define Iodd_WREG_M_DL5(Value)               TARG_WriteBit(PMDLL, BIT5, Value)
#define Iodd_WREG_M_DL6(Value)               TARG_WriteBit(PMDLL, BIT6, Value)
#define Iodd_WREG_M_DL7(Value)               TARG_WriteBit(PMDLL, BIT7, Value)
#define Iodd_WREG_M_DL8(Value)               TARG_WriteBit(PMDLH, BIT0, Value)
#define Iodd_WREG_M_DL9(Value)               TARG_WriteBit(PMDLH, BIT1, Value)
#define Iodd_WREG_M_DL10(Value)              TARG_WriteBit(PMDLH, BIT2, Value)
#define Iodd_WREG_M_DL11(Value)              TARG_WriteBit(PMDLH, BIT3, Value)
#define Iodd_WREG_M_DL12(Value)              TARG_WriteBit(PMDLH, BIT4, Value)
#define Iodd_WREG_M_DL13(Value)              TARG_WriteBit(PMDLH, BIT5, Value)
#define Iodd_WREG_M_DL14(Value)              /* write access not defined */
#define Iodd_WREG_M_DL15(Value)              /* write access not defined */

#endif

#if                                          \
      defined(__NEC_V850_FJ3_F3378__)||      \
      defined(__NEC_V850_FJ3_F3379__)||      \
      defined(__NEC_V850_FJ3_F3380__)||      \
      defined(__NEC_V850_FJ3_F3381__)||      \
      defined(__NEC_V850_FJ3_F3382__)||      \
      defined(__NEC_V850_FK3_F3383__)||      \
      defined(__NEC_V850_FK3_F3384__)||      \
      defined(__NEC_V850_FK3_F3385__)

#define Iodd_RREG_M_DL0                      TARG_ReadBit(PMDLL, BIT0)
#define Iodd_RREG_M_DL1                      TARG_ReadBit(PMDLL, BIT1)
#define Iodd_RREG_M_DL2                      TARG_ReadBit(PMDLL, BIT2)
#define Iodd_RREG_M_DL3                      TARG_ReadBit(PMDLL, BIT3)
#define Iodd_RREG_M_DL4                      TARG_ReadBit(PMDLL, BIT4)
#define Iodd_RREG_M_DL5                      TARG_ReadBit(PMDLL, BIT5)
#define Iodd_RREG_M_DL6                      TARG_ReadBit(PMDLL, BIT6)
#define Iodd_RREG_M_DL7                      TARG_ReadBit(PMDLL, BIT7)
#define Iodd_RREG_M_DL8                      TARG_ReadBit(PMDLH, BIT0)
#define Iodd_RREG_M_DL9                      TARG_ReadBit(PMDLH, BIT1)
#define Iodd_RREG_M_DL10                     TARG_ReadBit(PMDLH, BIT2)
#define Iodd_RREG_M_DL11                     TARG_ReadBit(PMDLH, BIT3)
#define Iodd_RREG_M_DL12                     TARG_ReadBit(PMDLH, BIT4)
#define Iodd_RREG_M_DL13                     TARG_ReadBit(PMDLH, BIT5)
#define Iodd_RREG_M_DL14                     TARG_ReadBit(PMDLH, BIT6)
#define Iodd_RREG_M_DL15                     TARG_ReadBit(PMDLH, BIT7)

#define Iodd_WREG_M_DL0(Value)               TARG_WriteBit(PMDLL, BIT0, Value)
#define Iodd_WREG_M_DL1(Value)               TARG_WriteBit(PMDLL, BIT1, Value)
#define Iodd_WREG_M_DL2(Value)               TARG_WriteBit(PMDLL, BIT2, Value)
#define Iodd_WREG_M_DL3(Value)               TARG_WriteBit(PMDLL, BIT3, Value)
#define Iodd_WREG_M_DL4(Value)               TARG_WriteBit(PMDLL, BIT4, Value)
#define Iodd_WREG_M_DL5(Value)               TARG_WriteBit(PMDLL, BIT5, Value)
#define Iodd_WREG_M_DL6(Value)               TARG_WriteBit(PMDLL, BIT6, Value)
#define Iodd_WREG_M_DL7(Value)               TARG_WriteBit(PMDLL, BIT7, Value)
#define Iodd_WREG_M_DL8(Value)               TARG_WriteBit(PMDLH, BIT0, Value)
#define Iodd_WREG_M_DL9(Value)               TARG_WriteBit(PMDLH, BIT1, Value)
#define Iodd_WREG_M_DL10(Value)              TARG_WriteBit(PMDLH, BIT2, Value)
#define Iodd_WREG_M_DL11(Value)              TARG_WriteBit(PMDLH, BIT3, Value)
#define Iodd_WREG_M_DL12(Value)              TARG_WriteBit(PMDLH, BIT4, Value)
#define Iodd_WREG_M_DL13(Value)              TARG_WriteBit(PMDLH, BIT5, Value)
#define Iodd_WREG_M_DL14(Value)              TARG_WriteBit(PMDLH, BIT6, Value)
#define Iodd_WREG_M_DL15(Value)              TARG_WriteBit(PMDLH, BIT7, Value)

#endif

#if                                          \
      defined(__NEC_V850_FJ3_F3378__)||      \
      defined(__NEC_V850_FJ3_F3379__)||      \
      defined(__NEC_V850_FJ3_F3380__)||      \
      defined(__NEC_V850_FJ3_F3381__)||      \
      defined(__NEC_V850_FJ3_F3382__)||      \
      defined(__NEC_V850_FK3_F3383__)||      \
      defined(__NEC_V850_FK3_F3384__)||      \
      defined(__NEC_V850_FK3_F3385__)

#define Iodd_RREG_MC_DL0                     TARG_ReadBit(PMCDLL, BIT0)
#define Iodd_RREG_MC_DL1                     TARG_ReadBit(PMCDLL, BIT1)
#define Iodd_RREG_MC_DL2                     TARG_ReadBit(PMCDLL, BIT2)
#define Iodd_RREG_MC_DL3                     TARG_ReadBit(PMCDLL, BIT3)
#define Iodd_RREG_MC_DL4                     TARG_ReadBit(PMCDLL, BIT4)
#define Iodd_RREG_MC_DL5                     TARG_ReadBit(PMCDLL, BIT5)
#define Iodd_RREG_MC_DL6                     TARG_ReadBit(PMCDLL, BIT6)
#define Iodd_RREG_MC_DL7                     TARG_ReadBit(PMCDLL, BIT7)
#define Iodd_RREG_MC_DL8                     TARG_ReadBit(PMCDLH, BIT0)
#define Iodd_RREG_MC_DL9                     TARG_ReadBit(PMCDLH, BIT1)
#define Iodd_RREG_MC_DL10                    TARG_ReadBit(PMCDLH, BIT2)
#define Iodd_RREG_MC_DL11                    TARG_ReadBit(PMCDLH, BIT3)
#define Iodd_RREG_MC_DL12                    TARG_ReadBit(PMCDLH, BIT4)
#define Iodd_RREG_MC_DL13                    TARG_ReadBit(PMCDLH, BIT5)
#define Iodd_RREG_MC_DL14                    TARG_ReadBit(PMCDLH, BIT6)
#define Iodd_RREG_MC_DL15                    TARG_ReadBit(PMCDLH, BIT7)

#define Iodd_WREG_MC_DL0(Value)              TARG_WriteBit(PMCDLL, BIT0, Value)
#define Iodd_WREG_MC_DL1(Value)              TARG_WriteBit(PMCDLL, BIT1, Value)
#define Iodd_WREG_MC_DL2(Value)              TARG_WriteBit(PMCDLL, BIT2, Value)
#define Iodd_WREG_MC_DL3(Value)              TARG_WriteBit(PMCDLL, BIT3, Value)
#define Iodd_WREG_MC_DL4(Value)              TARG_WriteBit(PMCDLL, BIT4, Value)
#define Iodd_WREG_MC_DL5(Value)              TARG_WriteBit(PMCDLL, BIT5, Value)
#define Iodd_WREG_MC_DL6(Value)              TARG_WriteBit(PMCDLL, BIT6, Value)
#define Iodd_WREG_MC_DL7(Value)              TARG_WriteBit(PMCDLL, BIT7, Value)
#define Iodd_WREG_MC_DL8(Value)              TARG_WriteBit(PMCDLH, BIT0, Value)
#define Iodd_WREG_MC_DL9(Value)              TARG_WriteBit(PMCDLH, BIT1, Value)
#define Iodd_WREG_MC_DL10(Value)             TARG_WriteBit(PMCDLH, BIT2, Value)
#define Iodd_WREG_MC_DL11(Value)             TARG_WriteBit(PMCDLH, BIT3, Value)
#define Iodd_WREG_MC_DL12(Value)             TARG_WriteBit(PMCDLH, BIT4, Value)
#define Iodd_WREG_MC_DL13(Value)             TARG_WriteBit(PMCDLH, BIT5, Value)
#define Iodd_WREG_MC_DL14(Value)             TARG_WriteBit(PMCDLH, BIT6, Value)
#define Iodd_WREG_MC_DL15(Value)             TARG_WriteBit(PMCDLH, BIT7, Value)

#endif

#if                                          \
      defined(__NEC_V850_FE3_F3370__)||      \
      defined(__NEC_V850_FE3_F3370__)||      \
      defined(__NEC_V850_FE3_F3371__)

#define Iodd_RREG_P_DL8                      /* register undefined */
#define Iodd_RREG_P_DL9                      /* register undefined */
#define Iodd_RREG_P_DL10                     /* register undefined */
#define Iodd_RREG_P_DL11                     /* register undefined */
#define Iodd_RREG_P_DL12                     /* register undefined */
#define Iodd_RREG_P_DL13                     /* register undefined */
#define Iodd_RREG_P_DL14                     /* register undefined */
#define Iodd_RREG_P_DL15                     /* register undefined */

#define Iodd_WREG_P_DL8(Value)               /* register undefined */
#define Iodd_WREG_P_DL9(Value)               /* register undefined */
#define Iodd_WREG_P_DL10(Value)              /* register undefined */
#define Iodd_WREG_P_DL11(Value)              /* register undefined */
#define Iodd_WREG_P_DL12(Value)              /* register undefined */
#define Iodd_WREG_P_DL13(Value)              /* register undefined */
#define Iodd_WREG_P_DL14(Value)              /* register undefined */
#define Iodd_WREG_P_DL15(Value)              /* register undefined */

#endif

#if                                          \
      defined(__NEC_V850_FE3_F3370__)||      \
      defined(__NEC_V850_FE3_F3370__)||      \
      defined(__NEC_V850_FE3_F3371__)

#define Iodd_RREG_M_DL8                      /* register undefined */
#define Iodd_RREG_M_DL9                      /* register undefined */
#define Iodd_RREG_M_DL10                     /* register undefined */
#define Iodd_RREG_M_DL11                     /* register undefined */
#define Iodd_RREG_M_DL12                     /* register undefined */
#define Iodd_RREG_M_DL13                     /* register undefined */
#define Iodd_RREG_M_DL14                     /* register undefined */
#define Iodd_RREG_M_DL15                     /* register undefined */

#define Iodd_WREG_M_DL8(Value)               /* register undefined */
#define Iodd_WREG_M_DL9(Value)               /* register undefined */
#define Iodd_WREG_M_DL10(Value)              /* register undefined */
#define Iodd_WREG_M_DL11(Value)              /* register undefined */
#define Iodd_WREG_M_DL12(Value)              /* register undefined */
#define Iodd_WREG_M_DL13(Value)              /* register undefined */
#define Iodd_WREG_M_DL14(Value)              /* register undefined */
#define Iodd_WREG_M_DL15(Value)              /* register undefined */

#endif

#if                                          \
      defined(__NEC_V850_FE3_F3370__)||      \
      defined(__NEC_V850_FE3_F3371__)||      \
      defined(__NEC_V850_FF3_F3372__)||      \
      defined(__NEC_V850_FF3_F3373__)||      \
      defined(__NEC_V850_FG3_F3374__)||      \
      defined(__NEC_V850_FG3_F3375__)||      \
      defined(__NEC_V850_FG3_F3376__)||      \
      defined(__NEC_V850_FG3_F3377__)||      \
      defined(__NEC_V850_FF3L_F3618__)

#define Iodd_RREG_MC_DL0                     /* register undefined */
#define Iodd_RREG_MC_DL1                     /* register undefined */
#define Iodd_RREG_MC_DL2                     /* register undefined */
#define Iodd_RREG_MC_DL3                     /* register undefined */
#define Iodd_RREG_MC_DL4                     /* register undefined */
#define Iodd_RREG_MC_DL5                     /* register undefined */
#define Iodd_RREG_MC_DL6                     /* register undefined */
#define Iodd_RREG_MC_DL7                     /* register undefined */

#define Iodd_WREG_MC_DL0(Value)              /* register undefined */
#define Iodd_WREG_MC_DL1(Value)              /* register undefined */
#define Iodd_WREG_MC_DL2(Value)              /* register undefined */
#define Iodd_WREG_MC_DL3(Value)              /* register undefined */
#define Iodd_WREG_MC_DL4(Value)              /* register undefined */
#define Iodd_WREG_MC_DL5(Value)              /* register undefined */
#define Iodd_WREG_MC_DL6(Value)              /* register undefined */
#define Iodd_WREG_MC_DL7(Value)              /* register undefined */

#endif

#if                                          \
      defined(__NEC_V850_FE3_F3370__)||      \
      defined(__NEC_V850_FE3_F3371__)||      \
      defined(__NEC_V850_FF3_F3372__)||      \
      defined(__NEC_V850_FF3_F3373__)||      \
      defined(__NEC_V850_FG3_F3374__)||      \
      defined(__NEC_V850_FG3_F3375__)||      \
      defined(__NEC_V850_FG3_F3376__)||      \
      defined(__NEC_V850_FG3_F3377__)||      \
      defined(__NEC_V850_FF3L_F3618__)

#define Iodd_RREG_MC_DL8                     /* register undefined */
#define Iodd_RREG_MC_DL9                     /* register undefined */
#define Iodd_RREG_MC_DL10                    /* register undefined */
#define Iodd_RREG_MC_DL11                    /* register undefined */
#define Iodd_RREG_MC_DL12                    /* register undefined */
#define Iodd_RREG_MC_DL13                    /* register undefined */
#define Iodd_RREG_MC_DL14                    /* register undefined */
#define Iodd_RREG_MC_DL15                    /* register undefined */

#define Iodd_WREG_MC_DL8(Value)              /* register undefined */
#define Iodd_WREG_MC_DL9(Value)              /* register undefined */
#define Iodd_WREG_MC_DL10(Value)             /* register undefined */
#define Iodd_WREG_MC_DL11(Value)             /* register undefined */
#define Iodd_WREG_MC_DL12(Value)             /* register undefined */
#define Iodd_WREG_MC_DL13(Value)             /* register undefined */
#define Iodd_WREG_MC_DL14(Value)             /* register undefined */
#define Iodd_WREG_MC_DL15(Value)             /* register undefined */

#endif

#if                                          \
      defined(__NEC_V850_Fx3__)

#define Iodd_RREG_FC_DL0                     /* register undefined */
#define Iodd_RREG_FC_DL1                     /* register undefined */
#define Iodd_RREG_FC_DL2                     /* register undefined */
#define Iodd_RREG_FC_DL3                     /* register undefined */
#define Iodd_RREG_FC_DL4                     /* register undefined */
#define Iodd_RREG_FC_DL5                     /* register undefined */
#define Iodd_RREG_FC_DL6                     /* register undefined */
#define Iodd_RREG_FC_DL7                     /* register undefined */
#define Iodd_RREG_FC_DL8                     /* register undefined */
#define Iodd_RREG_FC_DL9                     /* register undefined */
#define Iodd_RREG_FC_DL10                    /* register undefined */
#define Iodd_RREG_FC_DL11                    /* register undefined */
#define Iodd_RREG_FC_DL12                    /* register undefined */
#define Iodd_RREG_FC_DL13                    /* register undefined */
#define Iodd_RREG_FC_DL14                    /* register undefined */
#define Iodd_RREG_FC_DL15                    /* register undefined */

#define Iodd_WREG_FC_DL0(Value)              /* register undefined */
#define Iodd_WREG_FC_DL1(Value)              /* register undefined */
#define Iodd_WREG_FC_DL2(Value)              /* register undefined */
#define Iodd_WREG_FC_DL3(Value)              /* register undefined */
#define Iodd_WREG_FC_DL4(Value)              /* register undefined */
#define Iodd_WREG_FC_DL5(Value)              /* register undefined */
#define Iodd_WREG_FC_DL6(Value)              /* register undefined */
#define Iodd_WREG_FC_DL7(Value)              /* register undefined */
#define Iodd_WREG_FC_DL8(Value)              /* register undefined */
#define Iodd_WREG_FC_DL9(Value)              /* register undefined */
#define Iodd_WREG_FC_DL10(Value)             /* register undefined */
#define Iodd_WREG_FC_DL11(Value)             /* register undefined */
#define Iodd_WREG_FC_DL12(Value)             /* register undefined */
#define Iodd_WREG_FC_DL13(Value)             /* register undefined */
#define Iodd_WREG_FC_DL14(Value)             /* register undefined */
#define Iodd_WREG_FC_DL15(Value)             /* register undefined */

#endif

#if                                          \
      defined(__NEC_V850_Fx3__)

#define Iodd_RREG_FCE_DL0                    /* register undefined */
#define Iodd_RREG_FCE_DL1                    /* register undefined */
#define Iodd_RREG_FCE_DL2                    /* register undefined */
#define Iodd_RREG_FCE_DL3                    /* register undefined */
#define Iodd_RREG_FCE_DL4                    /* register undefined */
#define Iodd_RREG_FCE_DL5                    /* register undefined */
#define Iodd_RREG_FCE_DL6                    /* register undefined */
#define Iodd_RREG_FCE_DL7                    /* register undefined */
#define Iodd_RREG_FCE_DL8                    /* register undefined */
#define Iodd_RREG_FCE_DL9                    /* register undefined */
#define Iodd_RREG_FCE_DL10                   /* register undefined */
#define Iodd_RREG_FCE_DL11                   /* register undefined */
#define Iodd_RREG_FCE_DL12                   /* register undefined */
#define Iodd_RREG_FCE_DL13                   /* register undefined */
#define Iodd_RREG_FCE_DL14                   /* register undefined */
#define Iodd_RREG_FCE_DL15                   /* register undefined */

#define Iodd_WREG_FCE_DL0(Value)             /* register undefined */
#define Iodd_WREG_FCE_DL1(Value)             /* register undefined */
#define Iodd_WREG_FCE_DL2(Value)             /* register undefined */
#define Iodd_WREG_FCE_DL3(Value)             /* register undefined */
#define Iodd_WREG_FCE_DL4(Value)             /* register undefined */
#define Iodd_WREG_FCE_DL5(Value)             /* register undefined */
#define Iodd_WREG_FCE_DL6(Value)             /* register undefined */
#define Iodd_WREG_FCE_DL7(Value)             /* register undefined */
#define Iodd_WREG_FCE_DL8(Value)             /* register undefined */
#define Iodd_WREG_FCE_DL9(Value)             /* register undefined */
#define Iodd_WREG_FCE_DL10(Value)            /* register undefined */
#define Iodd_WREG_FCE_DL11(Value)            /* register undefined */
#define Iodd_WREG_FCE_DL12(Value)            /* register undefined */
#define Iodd_WREG_FCE_DL13(Value)            /* register undefined */
#define Iodd_WREG_FCE_DL14(Value)            /* register undefined */
#define Iodd_WREG_FCE_DL15(Value)            /* register undefined */

#endif

#if                                          \
      defined(__NEC_V850_Fx3__)

#define Iodd_RREG_PU_DL0                     /* register undefined */
#define Iodd_RREG_PU_DL1                     /* register undefined */
#define Iodd_RREG_PU_DL2                     /* register undefined */
#define Iodd_RREG_PU_DL3                     /* register undefined */
#define Iodd_RREG_PU_DL4                     /* register undefined */
#define Iodd_RREG_PU_DL5                     /* register undefined */
#define Iodd_RREG_PU_DL6                     /* register undefined */
#define Iodd_RREG_PU_DL7                     /* register undefined */
#define Iodd_RREG_PU_DL8                     /* register undefined */
#define Iodd_RREG_PU_DL9                     /* register undefined */
#define Iodd_RREG_PU_DL10                    /* register undefined */
#define Iodd_RREG_PU_DL11                    /* register undefined */
#define Iodd_RREG_PU_DL12                    /* register undefined */
#define Iodd_RREG_PU_DL13                    /* register undefined */
#define Iodd_RREG_PU_DL14                    /* register undefined */
#define Iodd_RREG_PU_DL15                    /* register undefined */

#define Iodd_WREG_PU_DL0(Value)              /* register undefined */
#define Iodd_WREG_PU_DL1(Value)              /* register undefined */
#define Iodd_WREG_PU_DL2(Value)              /* register undefined */
#define Iodd_WREG_PU_DL3(Value)              /* register undefined */
#define Iodd_WREG_PU_DL4(Value)              /* register undefined */
#define Iodd_WREG_PU_DL5(Value)              /* register undefined */
#define Iodd_WREG_PU_DL6(Value)              /* register undefined */
#define Iodd_WREG_PU_DL7(Value)              /* register undefined */
#define Iodd_WREG_PU_DL8(Value)              /* register undefined */
#define Iodd_WREG_PU_DL9(Value)              /* register undefined */
#define Iodd_WREG_PU_DL10(Value)             /* register undefined */
#define Iodd_WREG_PU_DL11(Value)             /* register undefined */
#define Iodd_WREG_PU_DL12(Value)             /* register undefined */
#define Iodd_WREG_PU_DL13(Value)             /* register undefined */
#define Iodd_WREG_PU_DL14(Value)             /* register undefined */
#define Iodd_WREG_PU_DL15(Value)             /* register undefined */

#endif

#if                                          \
      defined(__NEC_V850_Fx3__)

#define Iodd_RREG_PF_DL0                     /* register undefined */
#define Iodd_RREG_PF_DL1                     /* register undefined */
#define Iodd_RREG_PF_DL2                     /* register undefined */
#define Iodd_RREG_PF_DL3                     /* register undefined */
#define Iodd_RREG_PF_DL4                     /* register undefined */
#define Iodd_RREG_PF_DL5                     /* register undefined */
#define Iodd_RREG_PF_DL6                     /* register undefined */
#define Iodd_RREG_PF_DL7                     /* register undefined */
#define Iodd_RREG_PF_DL8                     /* register undefined */
#define Iodd_RREG_PF_DL9                     /* register undefined */
#define Iodd_RREG_PF_DL10                    /* register undefined */
#define Iodd_RREG_PF_DL11                    /* register undefined */
#define Iodd_RREG_PF_DL12                    /* register undefined */
#define Iodd_RREG_PF_DL13                    /* register undefined */
#define Iodd_RREG_PF_DL14                    /* register undefined */
#define Iodd_RREG_PF_DL15                    /* register undefined */

#define Iodd_WREG_PF_DL0(Value)              /* register undefined */
#define Iodd_WREG_PF_DL1(Value)              /* register undefined */
#define Iodd_WREG_PF_DL2(Value)              /* register undefined */
#define Iodd_WREG_PF_DL3(Value)              /* register undefined */
#define Iodd_WREG_PF_DL4(Value)              /* register undefined */
#define Iodd_WREG_PF_DL5(Value)              /* register undefined */
#define Iodd_WREG_PF_DL6(Value)              /* register undefined */
#define Iodd_WREG_PF_DL7(Value)              /* register undefined */
#define Iodd_WREG_PF_DL8(Value)              /* register undefined */
#define Iodd_WREG_PF_DL9(Value)              /* register undefined */
#define Iodd_WREG_PF_DL10(Value)             /* register undefined */
#define Iodd_WREG_PF_DL11(Value)             /* register undefined */
#define Iodd_WREG_PF_DL12(Value)             /* register undefined */
#define Iodd_WREG_PF_DL13(Value)             /* register undefined */
#define Iodd_WREG_PF_DL14(Value)             /* register undefined */
#define Iodd_WREG_PF_DL15(Value)             /* register undefined */

#endif

/*______ E N D _____ (iodd_priv_v850_fx3.h) __________________________________*/
