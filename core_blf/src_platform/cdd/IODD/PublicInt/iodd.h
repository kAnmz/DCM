/******************************************************************************/
/*@F_NAME:          iodd.h                                                    */
/*@F_PURPOSE:       Public interface for Logic port I/O driver                */
/*@F_CREATED_BY:    Vincent RIOUAL                                            */
/*@F_CREATION_DATE: 24/08/2000                                                */
/*@F_MPROC_TYPE:    Toshiba TX49                                              */
/*                  Motorola STAR12(H/HZ), MC9S12XHZ and S08AW                */
/*                  Nec V850 Fx3 / Dx3 / Dx4                                  */
/*                  Renesas RL78_D1A, RL78_F12                                */
/*                  Freescale  IMX53x,IMX6x                                   */
/************************************** (C) Copyright 2014 Magneti Marelli ****/

#ifndef IODD_H
#define IODD_H

/*______ Use sub iodd module for cypress traveo II ___________________________*/

#if defined(__CY_TV2__)
#include "iodd_tv2.h"
#endif /* defined(__CY_TV2__) */

/*_____________________E N D _________________________________________________*/

/***** RH850 ******************************************************************/
#if defined(__RH850__)
#include "iodd_rh850.h"
#endif

/***** STAR12, FX3, DX3 *******************************************************/

#if (defined(__MC9S12xx__) || defined(__MC9S08xx__) || defined(__NEC_V850__))


/*______ I N C L U D E - F I L E S ___________________________________________*/

#include "syst.h"
#include "targ.h"
#if defined(C_COMP_GHS_V850)
#include <v800_ghs.h>
#endif

/*______ G L O B A L - D E F I N E S _________________________________________*/

#define IODD_HIGH ((ubyte) 1)
#define IODD_LOW  ((ubyte) 0)


/*______ G L O B A L - T Y P E S _____________________________________________*/


/*______ G L O B A L - D A T A _______________________________________________*/


/*______ P R I V A T E - M A C R O S _________________________________________*/

#define PSW_ID_BIT_MASK 0x20 

/* port / bit mask name definition ------------------------------------------ */

#ifdef __NEC_V850_Fx3__
#include "iodd_priv_v850_fx3.h"
#endif

#ifdef __NEC_V850_Dx3__
#include "iodd_priv_v850_dx3.h"
#endif

#ifdef __REL_V850_Dx4__
#include "iodd_priv_v850_dx4.h"
#endif

#ifdef __MC9S12xx__
/* - readable 8-bits port - */

/* MEBI */
#define PORT_R_PA(PortName)  PORT ## PortName
#define PORT_R_PB(PortName)  PORT ## PortName

#ifdef __MC9S12XHZ__

#define PORT_R_PC(PortName)  PORT ## PortName

#endif

#define PORT_R_PE(PortName)  PORT ## PortName
#define PORT_R_PK(PortName)  PORT ## PortName

/* PIM */
#define PORT_R_PT(PortName)  PT ## PortName
#define PORT_R_PS(PortName)  PT ## PortName
#define PORT_R_PM(PortName)  PT ## PortName
#define PORT_R_PP(PortName)  PT ## PortName

#ifndef __MC9S12XHZ__

#define PORT_R_PH(PortName)  PT ## PortName
#define PORT_R_PJ(PortName)  PT ## PortName

#endif /* not __MC9S12XHZ__ */

#define PORT_R_PL(PortName)  PT ## PortName
#define PORT_R_PU(PortName)  PT ## PortName
#define PORT_R_PV(PortName)  PT ## PortName
#define PORT_R_PW(PortName)  PT ## PortName

/* ATD */

/* MC9S12-H variant */
#if defined(__MC9S12H__)

#define PORT_R_P0(PortName)  PORTAD ## PortName

#endif /* defined(__MC9S12H__) */

/* MC9S12-HZ and MC9S12XHZ variant */
#if (defined(__MC9S12HZ__) || defined(__MC9S12XHZ__))

/*  In pin setup we use ports name 0 and 1 to be compliant with S12H */
/*  For S12HZ anlaog port ATD1 = I/O port AD (PORTAD = PORT1)        */

/* used when pin only used as digital input (no analog input used) */
/* port name : AD */
#define PORT_R_PAD(PortName)  PT ## PortName

#endif /* (defined(__MC9S12HZ__) || defined(__MC9S12XHZ__)) */

/* used when pin used as digital input and as analog input */
/* port name : 1 */
#define PORT_R_P1(PortName)  PORTAD ## PortName

#define Iodd_ReadRegisterName(PortName) \
        PORT_R_P ## PortName(PortName)


/* - writable 8-bits port - */

/* MEBI */
#define PORT_W_PA(PortName)  PORT ## PortName
#define PORT_W_PB(PortName)  PORT ## PortName

#ifdef __MC9S12XHZ__

#define PORT_W_PC(PortName)  PORT ## PortName
#define PORT_W_PE(PortName)  PORT ## PortName

#endif /* __MC9S12XHZ__ */

#define PORT_W_PK(PortName)  PORT ## PortName

/* PIM */
#define PORT_W_PT(PortName)  PT ## PortName
#define PORT_W_PS(PortName)  PT ## PortName
#define PORT_W_PM(PortName)  PT ## PortName
#define PORT_W_PP(PortName)  PT ## PortName

#ifndef __MC9S12XHZ__

#define PORT_W_PH(PortName)  PT ## PortName
#define PORT_W_PJ(PortName)  PT ## PortName

#endif /* !__MC9S12XHZ__ */

#define PORT_W_PL(PortName)  PT ## PortName
#define PORT_W_PU(PortName)  PT ## PortName
#define PORT_W_PV(PortName)  PT ## PortName
#define PORT_W_PW(PortName)  PT ## PortName

/* ATD */

/* MC9S12-HZ and MC9S12XHZ variant */
#if (defined(__MC9S12HZ__) || defined(__MC9S12XHZ__))

/*  In pin setup we use ports name 0 and 1 to be compliant with S12H */
/*  For S12HZ anlaog port ATD1 = I/O port AD (PORTAD = PORT1)        */

/* used when pin only used as digital input (no analog input used) */
/* port name : AD */
#define PORT_W_PAD(PortName)  PT ## PortName

#endif /* (defined(__MC9S12HZ__) || defined(__MC9S12XHZ__)) */


#define Iodd_WriteRegisterName(PortName) \
        PORT_W_P ## PortName(PortName)
#endif /* __MC9S12xx__ */

#ifdef __MC9S08xx__
/* - readable 8-bits port - */

#define PORT_R_PA(PortName)  PORT ## PortName
#define PORT_R_PB(PortName)  PORT ## PortName
#define PORT_R_PC(PortName)  PORT ## PortName
#define PORT_R_PD(PortName)  PORT ## PortName
#define PORT_R_PE(PortName)  PORT ## PortName
#define PORT_R_PF(PortName)  PORT ## PortName
#define PORT_R_PG(PortName)  PORT ## PortName

/* - writable 8-bits port - */

#define PORT_W_PA(PortName)  PORT ## PortName
#define PORT_W_PB(PortName)  PORT ## PortName
#define PORT_W_PC(PortName)  PORT ## PortName
#define PORT_W_PD(PortName)  PORT ## PortName
#define PORT_W_PE(PortName)  PORT ## PortName
#define PORT_W_PF(PortName)  PORT ## PortName
#define PORT_W_PG(PortName)  PORT ## PortName

#endif /* __MC9S08xx__ */


/* Open-drain control ------------------------------------------------------- */

#ifdef __MC9S12xx__
#define Iodd_SetOpenDrainBit(PortName,PinNumber,State) \
        TARG_WriteBit(WOM ## PortName, PORT_BIT_WOM ## PortName ## PinNumber, State)
#endif /* __MC9S12xx__ */

#ifdef __NEC_V850_Fx3__
/* Open-drain outputs control */
/* For Fx3 :    none of the I/O pins can be set in open-drain mode,
        except P914,P915 when used as SDA,SCL in I2C mode.
        So open-drain setting is equivallent to High-Z setting (input)
        for all pins but SDA and SCL (set in open-drain mode in the I2C module) */
#define IODD_OPEN_DRAIN(PortName,PinNumber)    Iodd_WREG_M_ ## PortName ## PinNumber(1)
#define IODD_NO_OPEN_DRAIN(PortName,PinNumber) Iodd_WREG_M_ ## PortName ## PinNumber(0)
#endif /* __NEC_V850_Fx3__ */

#ifdef __NEC_V850_Dx3__
/* Open-drain outputs control */
/* For Dx3 :    each of the I/O pins can be set in open-drain mode */
#define IODD_OPEN_DRAIN(PortName,PinNumber)                             \
                            Iodd_WREG_ODC_ ## PortName ## PinNumber(1); \
                            Iodd_WREG_DSC_ ## PortName ## PinNumber(1)
#define IODD_OPEN_DRAIN_REDUCED(PortName,PinNumber)                     \
                            Iodd_WREG_ODC_ ## PortName ## PinNumber(1); \
                            Iodd_WREG_DSC_ ## PortName ## PinNumber(0)
#define IODD_NO_OPEN_DRAIN(PortName,PinNumber)                          \
                            Iodd_WREG_ODC_ ## PortName ## PinNumber(0); \
                            Iodd_WREG_DSC_ ## PortName ## PinNumber(1)
#define IODD_NO_OPEN_DRAIN_REDUCED(PortName,PinNumber)                  \
                            Iodd_WREG_ODC_ ## PortName ## PinNumber(0); \
                            Iodd_WREG_DSC_ ## PortName ## PinNumber(0)
#endif /* __NEC_V850_Dx3__ */

#ifdef __REL_V850_Dx4__
/* Open-drain outputs control */
/* For Dx4 :    each of the I/O pins can be set in open-drain mode */
#define IODD_OPEN_DRAIN(PortName,PinNumber)                                             \
        TARG_ProtWriteLong_Port(PPCMD## PortName, PPROTS##PortName, PODC## PortName, TARG_ReadLong(PODC## PortName) | (1<<PinNumber)); \
        TARG_ProtWriteLong_Port(PPCMD## PortName, PPROTS##PortName, PDSC## PortName, TARG_ReadLong(PDSC## PortName) | (1<<PinNumber)); \
        TARG_WriteBitInShort(PMC## PortName, PORT_BIT_P## PortName##_##PinNumber,  0)

#define IODD_OPEN_DRAIN_REDUCED(PortName,PinNumber)                                             \
        TARG_ProtWriteLong_Port(PPCMD## PortName, PPROTS##PortName, PODC## PortName, TARG_ReadLong(PODC## PortName) | (1<<PinNumber)); \
        TARG_ProtWriteLong_Port(PPCMD## PortName, PPROTS##PortName, PDSC## PortName, TARG_ReadLong(PDSC## PortName) & ~(1<<PinNumber));\
        TARG_WriteBitInShort(PMC## PortName, PORT_BIT_P## PortName##_##PinNumber,  0)

#define IODD_NO_OPEN_DRAIN(PortName,PinNumber)                                             \
  Iodd_NO_OPEN_DRAIN_ ## PortName(PortName,PinNumber)
#define Iodd_NO_OPEN_DRAIN_0(PortName,PinNumber)   IODD_NO_OPEN_DRAIN_NORMAL(PortName,PinNumber)
#define Iodd_NO_OPEN_DRAIN_1(PortName,PinNumber)   IODD_NO_OPEN_DRAIN_NORMAL(PortName,PinNumber)
#define Iodd_NO_OPEN_DRAIN_2(PortName,PinNumber)   IODD_NO_OPEN_DRAIN_NORMAL(PortName,PinNumber)
#define Iodd_NO_OPEN_DRAIN_3(PortName,PinNumber)   IODD_NO_OPEN_DRAIN_NORMAL(PortName,PinNumber)
#define Iodd_NO_OPEN_DRAIN_4(PortName,PinNumber)   IODD_NO_OPEN_DRAIN_NORMAL(PortName,PinNumber)
#define Iodd_NO_OPEN_DRAIN_10(PortName,PinNumber)  IODD_NO_OPEN_DRAIN_NORMAL(PortName,PinNumber)
#define Iodd_NO_OPEN_DRAIN_16(PortName,PinNumber) \
  TARG_ProtWriteLong_Port(PPCMD## PortName, PPROTS##PortName, PODC## PortName, TARG_ReadLong(PODC## PortName) & ~(1<<PinNumber)); \
  TARG_WriteBitInShort(PMC## PortName, PORT_BIT_P## PortName##_##PinNumber,  0)
#define Iodd_NO_OPEN_DRAIN_17(PortName,PinNumber) \
  TARG_ProtWriteLong_Port(PPCMD## PortName, PPROTS##PortName, PODC## PortName, TARG_ReadLong(PODC## PortName) & ~(1<<PinNumber)); \
  TARG_WriteBitInShort(PMC## PortName, PORT_BIT_P## PortName##_##PinNumber,  0)

#define IODD_NO_OPEN_DRAIN_NORMAL(PortName,PinNumber)                                             \
        TARG_ProtWriteLong_Port(PPCMD## PortName, PPROTS##PortName, PODC## PortName, TARG_ReadLong(PODC## PortName) & ~(1<<PinNumber)); \
        TARG_ProtWriteLong_Port(PPCMD## PortName, PPROTS##PortName, PDSC## PortName, TARG_ReadLong(PDSC## PortName) | (1<<PinNumber));\
        TARG_WriteBitInShort(PMC## PortName, PORT_BIT_P## PortName##_##PinNumber,  0)

#define IODD_NO_OPEN_DRAIN_REDUCED(PortName,PinNumber)                                             \
        TARG_ProtWriteLong_Port(PPCMD## PortName, PPROTS##PortName, PODC## PortName, TARG_ReadLong(PODC## PortName) & ~(1<<PinNumber)); \
        TARG_ProtWriteLong_Port(PPCMD## PortName, PPROTS##PortName, PDSC## PortName, TARG_ReadLong(PDSC## PortName) & ~(1<<PinNumber));\
        TARG_WriteBitInShort(PMC## PortName, PORT_BIT_P## PortName##_##PinNumber,  0)

#endif /* __REL_V850_Dx4__ */


/* High-Inpedance control --------------------------------------------------- */

#ifdef __NEC_V850_Fx3__
#define IODD_NO_HIGH_Z(PortName,PinNumber) Iodd_WREG_M_ ## PortName ## PinNumber(0)
#define IODD_HIGH_Z(PortName,PinNumber)    Iodd_WREG_M_ ## PortName ## PinNumber(1)
#endif /* __NEC_V850_Fx3__ */


/* Interrupt Sense Control -------------------------------------------------- */

#ifdef __MC9S12xx__

#ifndef __MC9S12XHZ__

#define Iodd_PORTH(PortName,PinNumber,Value) \
        TARG_WriteBit(PPS ## PortName, PORT_BIT_PPS ## PortName ## PinNumber, Value)

#define Iodd_PORTJ  Iodd_PORTH

#endif /* __MC9S12XHZ__ */

/* MC9S12-HZ and MC9S12XHZ variant */
#if (defined(__MC9S12HZ__) || defined(__MC9S12XHZ__))

/*  In pin setup we use ports name 0 and 1 to be compliant with S12H */
/*  For S12HZ analog port ATD1 = I/O port AD (PORTAD = PORT1)        */

/* used when pin only used as digital input (no analog input used) */
/* port name : AD */
#define Iodd_PORTAD(PortName,PinNumber,Value) \
        TARG_WriteBit(PPS ## PortName, PORT_BIT_PPS ## PortName ## PinNumber, Value)

/* used when pin used both as digital input and as analog input */
/* port name : 1 */
#define Iodd_PORT1(PortName,PinNumber,Value) \
        TARG_WriteBit(PPSAD, PORT_BIT_PPSAD ## PinNumber, Value)

#endif /* (defined(__MC9S12HZ__) || defined(__MC9S12XHZ__)) */


/* note for IRQ : FALLING = 1 and Low level = 0 */
/* reversed in comparaison with KW pin          */

/* low level */
#define Iodd_IRQ_LOW_LEVEL_PORTE \
        TARG_WriteBit(IRQCR, PORT_BIT_IRQE, 0)

/* falling edge */
#define Iodd_PORTE_IRQ_EDGE_0 \
        TARG_WriteBit(IRQCR, PORT_BIT_IRQE, 1)

#define Iodd_PORTE(PortName,PinNumber,Value) \
        Iodd_PORTE_IRQ_EDGE_ ## Value
#endif /* __MC9S12xx__ */

#ifdef __MC9S08xx__
#define Iodd_PORTG(PinNumber,Value) \
        TARG_WriteBit(KBISC , PORT_BIT_KBEDG ## PinNumber, Value)

/* low level */
#define Iodd_IRQ(Value)\
        TARG_WriteBit(IRQSC, PORT_BIT_IRQMOD, 0);TARG_WriteBit(IRQSC, PORT_BIT_IRQEDG, Value)

#endif /* __MC9S08xx__ */


/* Input Pin Mode ----------------------------------------------------------- */

#ifdef __MC9S12xx__
#define IODD_IT_FALLING_EDGE(IscrAccess,PortName,PinNumber) \
        Iodd_PORT ## IscrAccess(PortName,PinNumber,0)

#define IODD_IT_RISING_EDGE(IscrAccess,PortName,PinNumber) \
        Iodd_PORT ## IscrAccess(PortName,PinNumber,1)

/* for IRQ pin */
#define IODD_IT_LOW_LEVEL(IscrAccess,PortName,PinNumber) \
        Iodd_IRQ_LOW_LEVEL_PORT ## IscrAccess

#define IODD_STANDARD(IscrAccess,PortName,PinNumber)
#endif /* __MC9S12xx__ */

#ifdef __MC9S08xx__
#define IODD_IT_FALLING_EDGE(IscrAccess,PortName,PinNumber) \
        Iodd_PORT ## PortName(PinNumber,0)

#define IODD_IT_RISING_EDGE(IscrAccess,PortName,PinNumber) \
        Iodd_PORT ## PortName(PinNumber,1)

/* for IRQ pin */
#define IODD_IT_LOW_LEVEL(IscrAccess,PortName,PinNumber) \
        Iodd_IRQ (0)

#define IODD_IT_HIGH_LEVEL(IscrAccess,PortName,PinNumber) \
        Iodd_IRQ (1)

#define IODD_STANDARD(IscrAccess,PortName,PinNumber)
#endif /* __MC9S08xx__ */

#ifdef __NEC_V850__
#ifdef __NEC_V850_Fx3__
#define Iodd_GetInputReg(PortName,PinNumber) \
        Iodd_RREG_P_ ## PortName ## PinNumber

#define Iodd_WREG_PM(PortName,Value) \
        TARG_WriteByte(PM ## PortName,Value)

/* NMI   */
#define Iodd_IT_EDGES_02(R_Value,F_Value)  \
        TARG_WriteBit(INTR0,BIT2,R_Value); \
        TARG_WriteBit(INTF0,BIT2,F_Value)

/* INTP0 */
#define Iodd_IT_EDGES_03(R_Value,F_Value)  \
        TARG_WriteBit(INTR0,BIT3,R_Value); \
        TARG_WriteBit(INTF0,BIT3,F_Value)

/* INTP1 */
#define Iodd_IT_EDGES_04(R_Value,F_Value)  \
        TARG_WriteBit(INTR0,BIT4,R_Value); \
        TARG_WriteBit(INTF0,BIT4,F_Value)

/* INTP2 */
#define Iodd_IT_EDGES_05(R_Value,F_Value)  \
        TARG_WriteBit(INTR0,BIT5,R_Value); \
        TARG_WriteBit(INTF0,BIT5,F_Value)

/* INTP3 */
#define Iodd_IT_EDGES_06(R_Value,F_Value)  \
        TARG_WriteBit(INTR0,BIT6,R_Value); \
        TARG_WriteBit(INTF0,BIT6,F_Value)

#if defined(__NEC_V850_FJ3__) || \
    defined(__NEC_V850_FK3__)
/* INTP4 */
#define Iodd_IT_EDGES_913(R_Value,F_Value)  \
        TARG_WriteBit(INTR9H,BIT5,R_Value); \
        TARG_WriteBit(INTF9H,BIT5,F_Value)

/* INTP5 */
#define  Iodd_IT_EDGES_914(R_Value,F_Value)  \
         TARG_WriteBit(INTR9H,BIT6,R_Value); \
         TARG_WriteBit(INTF9H,BIT6,F_Value)

/* INTP6 */
#define Iodd_IT_EDGES_915(R_Value,F_Value)  \
        TARG_WriteBit(INTR9H,BIT7,R_Value); \
        TARG_WriteBit(INTF9H,BIT7,F_Value)
#endif /* defined(__NEC_V850_FJ3__) ||
         defined(__NEC_V850_FK3__) */

/* INTP7 */
#define Iodd_IT_EDGES_31(R_Value,F_Value)   \
        TARG_WriteBit(INTR3L,BIT1,R_Value); \
        TARG_WriteBit(INTF3L,BIT1,F_Value)

#if defined(__NEC_V850_FG3__) || \
    defined(__NEC_V850_FJ3__) || \
    defined(__NEC_V850_FK3__)
/* INTP8 */
#define Iodd_IT_EDGES_39(R_Value,F_Value)   \
        TARG_WriteBit(INTR3H,BIT1,R_Value); \
        TARG_WriteBit(INTF3H,BIT1,F_Value)

/* INTP9 */
#define Iodd_IT_EDGES_10(R_Value,F_Value)  \
        TARG_WriteBit(INTR1,BIT0,R_Value); \
        TARG_WriteBit(INTF1,BIT0,F_Value)

/* INTP10 */
#define Iodd_IT_EDGES_11(R_Value,F_Value)  \
        TARG_WriteBit(INTR1,BIT1,R_Value); \
        TARG_WriteBit(INTF1,BIT1,F_Value)
#endif /* defined(__NEC_V850_FG3__) ||
          defined(__NEC_V850_FJ3__) ||
          defined(__NEC_V850_FK3__) */

#if defined(__NEC_V850_FJ3__) || \
    defined(__NEC_V850_FK3__)
/* INTP11 */
#define Iodd_IT_EDGES_60(R_Value,F_Value)   \
        TARG_WriteBit(INTR6L,BIT0,R_Value); \
        TARG_WriteBit(INTF6L,BIT0,F_Value)

/* INTP12 */
#define Iodd_IT_EDGES_61(R_Value,F_Value)   \
        TARG_WriteBit(INTR6L,BIT1,R_Value); \
        TARG_WriteBit(INTF6L,BIT1,F_Value)

/* INTP13 */
#define Iodd_IT_EDGES_62(R_Value,F_Value)   \
        TARG_WriteBit(INTR6L,BIT2,R_Value); \
        TARG_WriteBit(INTF6L,BIT2,F_Value)
#endif /* defined(__NEC_V850_FJ3__) ||
          defined(__NEC_V850_FK3__) */

#if ( defined(__NEC_V850_FJ3__) && !defined(__NEC_V850_FJ3_F3378__) ) || \
    defined(__NEC_V850_FK3__)

/* INTP14 */
#define Iodd_IT_EDGES_80(R_Value,F_Value)  \
        TARG_WriteBit(INTR8,BIT0,R_Value); \
        TARG_WriteBit(INTF8,BIT0,F_Value)
#endif /* ( defined(__NEC_V850_FJ3__) && !defined(__NEC_V850_FJ3_F3378__) ) ||
          defined(__NEC_V850_FK3__) */

#if defined(__NEC_V850_FK3__)
/* INTP15 */
#define Iodd_IT_EDGES_615(R_Value,F_Value)  \
        TARG_WriteBit(INTR6H,BIT7,R_Value); \
        TARG_WriteBit(INTF6H,BIT7,F_Value)
#endif  /* defined(__NEC_V850_FK3__) */

#define Iodd_FC_69_0(PinNumber ) Iodd_WREG_FC_0 ## PinNumber(0)
#define Iodd_FC_69_1(PinNumber ) Iodd_WREG_FC_1 ## PinNumber(0)
#define Iodd_FC_69_2(PinNumber )
#define Iodd_FC_69_3(PinNumber ) Iodd_WREG_FC_3 ## PinNumber(0)
#define Iodd_FC_69_4(PinNumber ) Iodd_WREG_FC_4 ## PinNumber(0)
#define Iodd_FC_69_5(PinNumber )
#define Iodd_FC_69_6(PinNumber ) Iodd_WREG_FC_6 ## PinNumber(1)
#define Iodd_FC_69_7(PinNumber )
#define Iodd_FC_69_8(PinNumber ) Iodd_WREG_FC_8 ## PinNumber(0)
#define Iodd_FC_69_9(PinNumber ) Iodd_WREG_FC_9 ## PinNumber(1)
#define Iodd_FC_69_12(PinNumber)
#define Iodd_FC_69_15(PinNumber)
#define Iodd_FC_69_CD(PinNumber)
#define Iodd_FC_69_CM(PinNumber)
#define Iodd_FC_69_CS(PinNumber)
#define Iodd_FC_69_CT(PinNumber)
#define Iodd_FC_69_DL(PinNumber)

#define IODD_IT_FALLING_EDGE(PortName,PinNumber) \
        Iodd_WREG_FCE_ ## PortName ## PinNumber(0);  \
        Iodd_FC_69_ ## PortName(PinNumber); \
        Iodd_IT_EDGES_ ## PortName ## PinNumber (0,1) \
        Iodd_WREG_MC_ ## PortName ## PinNumber(1)

#define IODD_IT_RISING_EDGE(PortName,PinNumber) \
        Iodd_WREG_FCE_ ## PortName ## PinNumber(0); \
        Iodd_FC_69_ ## PortName(PinNumber); \
        Iodd_IT_EDGES_ ## PortName ## PinNumber (1,0); \
        Iodd_WREG_MC_ ## PortName ## PinNumber(1)

#define IODD_IT_BOTH_EDGE(PortName,PinNumber) \
        Iodd_WREG_FCE_ ## PortName ## PinNumber(0); \
        Iodd_FC_69_ ## PortName(PinNumber); \
        Iodd_IT_EDGES_ ## PortName ## PinNumber (1,1); \
        Iodd_WREG_MC_ ## PortName ## PinNumber(1)

#define IODD_IT_LOW_LEVEL(PortName,PinNumber)
#endif /* __NEC_V850_Fx3__ */

#ifdef __NEC_V850_Dx3__
#define Iodd_GetInputReg(PortName,PinNumber) \
        Iodd_RREG_P_ ## PortName ## PinNumber

#define Iodd_WREG_PM(PortName,Value) \
        TARG_WriteByte(PM ## PortName,Value)

/* INTP0 */
#define Iodd_IT_EDGES_00(Value) \
        TARG_WriteByte(INTM0,((TARG_ReadByte(INTM0)&0xf8)+Value))

/* INTP1 */
#define Iodd_IT_EDGES_01(Value) \
        TARG_WriteByte(INTM0,((TARG_ReadByte(INTM0)&0x8f)+(Value<<4)))

/* INTP2 */
#define  Iodd_IT_EDGES_02(Value) \
         TARG_WriteByte(INTM1,((TARG_ReadByte(INTM1)&0xf8)+Value))

/* INTP3 */
#define Iodd_IT_EDGES_03(Value) \
        TARG_WriteByte(INTM1,((TARG_ReadByte(INTM1)&0x8f)+(Value<<4)))

#ifndef __NEC_V850_DG3__
/* INTP4 */
#define Iodd_IT_EDGES_04(Value) \
        TARG_WriteByte(INTM2,((TARG_ReadByte(INTM2)&0xf8)+Value))
/* INTP5 */
#define Iodd_IT_EDGES_06(Value) \
        TARG_WriteByte(INTM2,((TARG_ReadByte(INTM2)&0x8f)+(Value<<4)))

/* INTP6 */
#define Iodd_IT_EDGES_07(Value) \
        TARG_WriteByte(INTM3,((TARG_ReadByte(INTM3)&0xf8)+Value))

/* INTP7 */
#define Iodd_IT_EDGES_50(Value) \
        TARG_WriteByte(INTM3,((TARG_ReadByte(INTM3)&0x8f)+(Value<<4)))
#endif /* not __NEC_V850_DG3__ */

#define Iodd_IT_EDGES_05(Value)

#define IODD_IT_FALLING_EDGE(PortName,PinNumber)     \
        Iodd_IT_EDGES_ ## PortName ## PinNumber (0); \
        Iodd_WREG_M_ ## PortName ## PinNumber(1);    \
        Iodd_WREG_MC_ ## PortName ## PinNumber(1);   \
        Iodd_WREG_LCDC_ ## PortName ## PinNumber(0)

#define IODD_IT_RISING_EDGE(PortName,PinNumber)      \
        Iodd_IT_EDGES_ ## PortName ## PinNumber (1); \
        Iodd_WREG_M_ ## PortName ## PinNumber(1);    \
        Iodd_WREG_MC_ ## PortName ## PinNumber(1);   \
        Iodd_WREG_LCDC_ ## PortName ## PinNumber(0)

#define IODD_IT_BOTH_EDGE(PortName,PinNumber)        \
        Iodd_IT_EDGES_ ## PortName ## PinNumber (3); \
        Iodd_WREG_M_ ## PortName ## PinNumber(1);    \
        Iodd_WREG_MC_ ## PortName ## PinNumber(1);   \
        Iodd_WREG_LCDC_ ## PortName ## PinNumber(0)

#define IODD_IT_LOW_LEVEL(PortName,PinNumber)        \
        Iodd_IT_EDGES_ ## PortName ## PinNumber (4); \
        Iodd_WREG_M_ ## PortName ## PinNumber(1);    \
        Iodd_WREG_MC_ ## PortName ## PinNumber(1);   \
        Iodd_WREG_LCDC_ ## PortName ## PinNumber(0)

#define IODD_IT_HIGH_LEVEL(PortName,PinNumber)       \
        Iodd_IT_EDGES_ ## PortName ## PinNumber (5); \
        Iodd_WREG_M_ ## PortName ## PinNumber(1);    \
        Iodd_WREG_MC_ ## PortName ## PinNumber(1);   \
        Iodd_WREG_LCDC_ ## PortName ## PinNumber(0)

#define IODD_NMI_FALLING_EDGE(PortName,PinNumber) \
        IODD_IT_FALLING_EDGE(0,0);                \
        TARG_WriteByte(INTM0,((TARG_ReadByte(INTM0)|0x08)))

#define IODD_NMI_RISING_EDGE(PortName,PinNumber) \
        IODD_IT_RISING_EDGE(0,0);                \
        TARG_WriteByte(INTM0,((TARG_ReadByte(INTM0)|0x08)))

#define IODD_NMI_BOTH_EDGE(PortName,PinNumber) \
        IODD_IT_BOTH_EDGE(0,0);                \
        TARG_WriteByte(INTM0,((TARG_ReadByte(INTM0)|0x08)))

#define IODD_NMI_LOW_LEVEL(PortName,PinNumber) \
        IODD_IT_LOW_LEVEL(0,0);                \
        TARG_WriteByte(INTM0,((TARG_ReadByte(INTM0)|0x08)))

#define IODD_NMI_HIGH_LEVEL(PortName,PinNumber) \
        IODD_IT_HIGH_LEVEL(0,0);                \
        TARG_WriteByte(INTM0,((TARG_ReadByte(INTM0)|0x08)))
#endif /* __NEC_V850_Dx3__ */

#ifdef __REL_V850_Dx4__
#define Iodd_GetInputReg(PortName,PinNumber) \
        TARG_ReadBitInShort(PPR ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber)
        
#define Iodd_WREG_PM(PortName,Value) \
        TARG_WriteShort(PM ## PortName,Value)  /* Except Port J0 */

#if (defined(__REL_V850_DJ4__) || defined(__REL_V850_DN4H__))

/* INTP0 */
#define Iodd_IT_EDGES_0_0(Value) \
        TARG_SetBitsInShort(PFC0, PORT_MSK_PFCn0); \
        TARG_SetBitsInShort(PFCE0, PORT_MSK_PFCEn0); \
        TARG_WriteByte(FCLA0CTL0,((TARG_ReadByte(FCLA0CTL0)&0xf8) + Value)); \
        TARG_WriteByte(FCLA0CTL0,((TARG_ReadByte(FCLA0CTL0)) | 0x80 ))

/* INTP1 */
#define Iodd_IT_EDGES_0_1(Value) \
        TARG_SetBitsInShort(PFC0, PORT_MSK_PFCn1); \
        TARG_SetBitsInShort(PFCE0, PORT_MSK_PFCEn1);\
        TARG_WriteByte(FCLA0CTL1,((TARG_ReadByte(FCLA0CTL1)&0xf8) + Value)); \
        TARG_WriteByte(FCLA0CTL1,((TARG_ReadByte(FCLA0CTL1)) | 0x80 ))

/* INTP2 */
#define Iodd_IT_EDGES_0_2(Value) \
        TARG_SetBitsInShort(PFC0, PORT_MSK_PFCn2); \
        TARG_SetBitsInShort(PFCE0, PORT_MSK_PFCEn2); \
        TARG_WriteByte(FCLA0CTL2,((TARG_ReadByte(FCLA0CTL2)&0xf8) + Value)); \
        TARG_WriteByte(FCLA0CTL2,((TARG_ReadByte(FCLA0CTL2)) | 0x80 ))

/* INTP3 */
#define Iodd_IT_EDGES_0_3(Value) \
        TARG_SetBitsInShort(PFC0, PORT_MSK_PFCn3); \
        TARG_SetBitsInShort(PFCE0, PORT_MSK_PFCEn3); \
        TARG_WriteByte(FCLA0CTL3,((TARG_ReadByte(FCLA0CTL3)&0xf8) + Value)); \
        TARG_WriteByte(FCLA0CTL3,((TARG_ReadByte(FCLA0CTL3)) | 0x80 ))

/* NMI */
#define Iodd_IT_EDGES_0_6(Value) \
        TARG_ClearBitsInShort(PFC0, PORT_MSK_PFCn6); \
        TARG_SetBitsInShort(PFCE0, PORT_MSK_PFCEn6); \
        TARG_WriteByte(FCLA2CTL0,((TARG_ReadByte(FCLA2CTL0)&0xf8) + Value)); \
        TARG_WriteByte(FCLA2CTL0,((TARG_ReadByte(FCLA2CTL0)) | 0x80 ))

/* INTP4 */
#define Iodd_IT_EDGES_0_7(Value) \
        TARG_ClearBitsInShort(PFC0, PORT_MSK_PFCn7); \
        TARG_SetBitsInShort(PFCE0, PORT_MSK_PFCEn7); \
        TARG_WriteByte(FCLA0CTL4,((TARG_ReadByte(FCLA0CTL4)&0xf8) + Value)); \
        TARG_WriteByte(FCLA0CTL4,((TARG_ReadByte(FCLA0CTL4)) | 0x80 ))

/* INTP5 */
#define Iodd_IT_EDGES_0_8(Value) \
        TARG_ClearBitsInShort(PFC0, PORT_MSK_PFCn8); \
        TARG_SetBitsInShort(PFCE0, PORT_MSK_PFCEn8); \
        TARG_WriteByte(FCLA0CTL5,((TARG_ReadByte(FCLA0CTL5)&0xf8) + Value)); \
        TARG_WriteByte(FCLA0CTL5,((TARG_ReadByte(FCLA0CTL5)) | 0x80 ))

/* INTP6 */
#define Iodd_IT_EDGES_0_9(Value) \
        TARG_ClearBitsInShort(PFC0, PORT_MSK_PFCn9); \
        TARG_SetBitsInShort(PFCE0, PORT_MSK_PFCEn9); \
        TARG_WriteByte(FCLA0CTL6,((TARG_ReadByte(FCLA0CTL6)&0xf8) + Value)); \
        TARG_WriteByte(FCLA0CTL6,((TARG_ReadByte(FCLA0CTL6)) | 0x80 ))

/* INTP9 */
#define Iodd_IT_EDGES_0_10(Value) \
        TARG_ClearBitsInShort(PFC0, PORT_MSK_PFCn10); \
        TARG_SetBitsInShort(PFCE0, PORT_MSK_PFCEn10); \
        TARG_WriteByte(FCLA1CTL1,((TARG_ReadByte(FCLA1CTL1)&0xf8) + Value)); \
        TARG_WriteByte(FCLA1CTL1,((TARG_ReadByte(FCLA1CTL1)) | 0x80 ))

/* INTP10 */
#define Iodd_IT_EDGES_0_11(Value) \
        TARG_WriteByte(FCLA1CTL2,((TARG_ReadByte(FCLA1CTL2)&0xf8) + Value)); \
        TARG_WriteByte(FCLA1CTL2,((TARG_ReadByte(FCLA1CTL2)) | 0x80 )); \
        TARG_ClearBitsInShort(PFC0, PORT_MSK_PFCn11); \
        TARG_SetBitsInShort(PFCE0, PORT_MSK_PFCEn11)

/* INTP8 */
#define Iodd_IT_EDGES_0_12(Value) \
        TARG_ClearBitsInShort(PFC0, PORT_MSK_PFCn12); \
        TARG_SetBitsInShort(PFCE0, PORT_MSK_PFCEn12); \
        TARG_WriteByte(FCLA1CTL0,((TARG_ReadByte(FCLA1CTL0)&0xf8) + Value)); \
        TARG_WriteByte(FCLA1CTL0,((TARG_ReadByte(FCLA1CTL0)) | 0x80 ))

/* INTP7 */
#define Iodd_IT_EDGES_0_13(Value) \
        TARG_ClearBitsInShort(PFC0, PORT_MSK_PFCn13); \
        TARG_SetBitsInShort(PFCE0, PORT_MSK_PFCEn13); \
        TARG_WriteByte(FCLA0CTL7,((TARG_ReadByte(FCLA0CTL7)&0xf8) + Value)); \
        TARG_WriteByte(FCLA0CTL7,((TARG_ReadByte(FCLA0CTL7)) | 0x80 ))

/* INTP4 */
#define Iodd_IT_EDGES_1_1(Value) \
        TARG_SetBitsInShort(PFC1, PORT_MSK_PFCn1); \
        TARG_SetBitsInShort(PFCE1, PORT_MSK_PFCEn1); \
        TARG_WriteByte(FCLA0CTL4,((TARG_ReadByte(FCLA0CTL4)&0xf8) + Value)); \
        TARG_WriteByte(FCLA0CTL4,((TARG_ReadByte(FCLA0CTL4)) | 0x80 ))

/* INTP5 */
#define Iodd_IT_EDGES_1_2(Value) \
        TARG_SetBitsInShort(PFC1, PORT_MSK_PFCn2); \
        TARG_SetBitsInShort(PFCE1, PORT_MSK_PFCEn2); \
        TARG_WriteByte(FCLA0CTL5,((TARG_ReadByte(FCLA0CTL5)&0xf8) + Value)); \
        TARG_WriteByte(FCLA0CTL5,((TARG_ReadByte(FCLA0CTL5)) | 0x80 ))

/* INTP6 */
#define Iodd_IT_EDGES_1_3(Value) \
        TARG_SetBitsInShort(PFC1, PORT_MSK_PFCn3); \
        TARG_SetBitsInShort(PFCE1, PORT_MSK_PFCEn3); \
        TARG_WriteByte(FCLA0CTL6,((TARG_ReadByte(FCLA0CTL6)&0xf8) + Value)); \
        TARG_WriteByte(FCLA0CTL6,((TARG_ReadByte(FCLA0CTL6)) | 0x80 ))

/* INTP7 */
#define Iodd_IT_EDGES_1_4(Value) \
        TARG_SetBitsInShort(PFC1, PORT_MSK_PFCn4); \
        TARG_SetBitsInShort(PFCE1, PORT_MSK_PFCEn4); \
        TARG_WriteByte(FCLA0CTL7,((TARG_ReadByte(FCLA0CTL7)&0xf8) + Value)); \
        TARG_WriteByte(FCLA0CTL7,((TARG_ReadByte(FCLA0CTL7)) | 0x80 ))

/* INTP8 */
#define Iodd_IT_EDGES_1_5(Value) \
        TARG_SetBitsInShort(PFC1, PORT_MSK_PFCn5); \
        TARG_SetBitsInShort(PFCE1, PORT_MSK_PFCEn5); \
        TARG_WriteByte(FCLA1CTL0,((TARG_ReadByte(FCLA1CTL0)&0xf8) + Value)); \
        TARG_WriteByte(FCLA1CTL0,((TARG_ReadByte(FCLA1CTL0)) | 0x80 ))

/* INTP9 */
#define Iodd_IT_EDGES_1_6(Value) \
        TARG_SetBitsInShort(PFC1, PORT_MSK_PFCn6); \
        TARG_SetBitsInShort(PFCE1, PORT_MSK_PFCEn6); \
        TARG_WriteByte(FCLA1CTL1,((TARG_ReadByte(FCLA1CTL1)&0xf8) + Value)); \
        TARG_WriteByte(FCLA1CTL1,((TARG_ReadByte(FCLA1CTL1)) | 0x80 ))

/* INTP10 */
#define Iodd_IT_EDGES_1_7(Value) \
        TARG_SetBitsInShort(PFC1, PORT_MSK_PFCn7); \
        TARG_SetBitsInShort(PFCE1, PORT_MSK_PFCEn7); \
        TARG_WriteByte(FCLA1CTL2,((TARG_ReadByte(FCLA1CTL2)&0xf8) + Value)); \
        TARG_WriteByte(FCLA1CTL2,((TARG_ReadByte(FCLA1CTL2)) | 0x80 ))

/* INTP3 */
#define Iodd_IT_EDGES_1_9(Value) \
        TARG_SetBitsInShort(PFC1, PORT_MSK_PFCn9); \
        TARG_ClearBitsInShort(PFCE1, PORT_MSK_PFCEn9); \
        TARG_WriteByte(FCLA0CTL3,((TARG_ReadByte(FCLA0CTL3)&0xf8) + Value)); \
        TARG_WriteByte(FCLA0CTL3,((TARG_ReadByte(FCLA0CTL3)) | 0x80 ))

/* INTP4 */
#define Iodd_IT_EDGES_1_10(Value) \
        TARG_SetBitsInShort(PFC1, PORT_MSK_PFCn10); \
        TARG_SetBitsInShort(PFCE1, PORT_MSK_PFCEn10); \
        TARG_WriteByte(FCLA0CTL4,((TARG_ReadByte(FCLA0CTL4)&0xf8) + Value)); \
        TARG_WriteByte(FCLA0CTL4,((TARG_ReadByte(FCLA0CTL4)) | 0x80 ))

/* INTP5 */
#define Iodd_IT_EDGES_1_11(Value) \
        TARG_SetBitsInShort(PFC1, PORT_MSK_PFCn11); \
        TARG_SetBitsInShort(PFCE1, PORT_MSK_PFCEn11); \
        TARG_WriteByte(FCLA0CTL5,((TARG_ReadByte(FCLA0CTL5)&0xf8) + Value)); \
        TARG_WriteByte(FCLA0CTL5,((TARG_ReadByte(FCLA0CTL5)) | 0x80 ))

/* INTP6 */
#define Iodd_IT_EDGES_1_12(Value) \
        TARG_SetBitsInShort(PFC1, PORT_MSK_PFCn12); \
        TARG_SetBitsInShort(PFCE1, PORT_MSK_PFCEn12); \
        TARG_WriteByte(FCLA0CTL6,((TARG_ReadByte(FCLA0CTL6)&0xf8) + Value)); \
        TARG_WriteByte(FCLA0CTL6,((TARG_ReadByte(FCLA0CTL6)) | 0x80 ))

/* INTP7 */
#define Iodd_IT_EDGES_1_13(Value) \
        TARG_SetBitsInShort(PFC1, PORT_MSK_PFCn13); \
        TARG_SetBitsInShort(PFCE1, PORT_MSK_PFCEn13); \
        TARG_WriteByte(FCLA0CTL7,((TARG_ReadByte(FCLA0CTL7)&0xf8) + Value)); \
        TARG_WriteByte(FCLA0CTL7,((TARG_ReadByte(FCLA0CTL7)) | 0x80 ))

/* INTP8 */
#define Iodd_IT_EDGES_1_14(Value) \
        TARG_SetBitsInShort(PFC1, PORT_MSK_PFCn14); \
        TARG_SetBitsInShort(PFCE1, PORT_MSK_PFCEn14); \
        TARG_WriteByte(FCLA1CTL0,((TARG_ReadByte(FCLA1CTL0)&0xf8) + Value)); \
        TARG_WriteByte(FCLA1CTL0,((TARG_ReadByte(FCLA1CTL0)) | 0x80 ))

/* INTP9 */
#define Iodd_IT_EDGES_1_15(Value) \
        TARG_SetBitsInShort(PFC1, PORT_MSK_PFCn15); \
        TARG_SetBitsInShort(PFCE1, PORT_MSK_PFCEn15); \
        TARG_WriteByte(FCLA1CTL1,((TARG_ReadByte(FCLA1CTL1)&0xf8) + Value)); \
        TARG_WriteByte(FCLA1CTL1,((TARG_ReadByte(FCLA1CTL1)) | 0x80 ))

/* INTP10 */
#define Iodd_IT_EDGES_2_0(Value) \
        TARG_SetBitsInShort(PFC2, PORT_MSK_PFCn0); \
        TARG_SetBitsInShort(PFCE2, PORT_MSK_PFCEn0); \
        TARG_WriteByte(FCLA1CTL2,((TARG_ReadByte(FCLA1CTL2)&0xf8) + Value)); \
        TARG_WriteByte(FCLA1CTL2,((TARG_ReadByte(FCLA1CTL2)) | 0x80 ))

/* INTP2 */
#define Iodd_IT_EDGES_4_4(Value) \
        TARG_ClearBitsInShort(PFC4, PORT_MSK_PFCn4); \
        TARG_ClearBitsInShort(PFCE4, PORT_MSK_PFCEn4); \
        TARG_WriteByte(FCLA0CTL2,((TARG_ReadByte(FCLA0CTL2)&0xf8) + Value)); \
        TARG_WriteByte(FCLA0CTL2,((TARG_ReadByte(FCLA0CTL2)) | 0x80 ))

/* INTP4 */
#define Iodd_IT_EDGES_4_7(Value) \
        TARG_ClearBitsInShort(PFC4, PORT_MSK_PFCn7); \
        TARG_ClearBitsInShort(PFCE4, PORT_MSK_PFCEn7); \
        TARG_WriteByte(FCLA0CTL4,((TARG_ReadByte(FCLA0CTL4)&0xf8) + Value)); \
        TARG_WriteByte(FCLA0CTL4,((TARG_ReadByte(FCLA0CTL4)) | 0x80 ))


#endif /* (defined(__REL_V850_DJ4__) || defined(__REL_V850_DN4H__)) */

#if defined (__REL_V850_DN4H__)
/* INTP0 */
#define Iodd_IT_EDGES_27_0(Value) \
        TARG_WriteBitInShort(PFC27, BIT0, 0); \
        TARG_WriteBitInShort(PFCE27, BIT0, 0); \
        TARG_WriteByte(FCLA0CTL0,((TARG_ReadByte(FCLA0CTL0)&0xf8) + Value)); \
        TARG_WriteByte(FCLA0CTL0,((TARG_ReadByte(FCLA0CTL0)) | 0x80 ))

/* INTP1 */
#define Iodd_IT_EDGES_27_1(Value) \
        TARG_WriteBitInShort(PFC27, BIT1, 0); \
        TARG_WriteBitInShort(PFCE27, BIT1, 0); \
        TARG_WriteByte(FCLA0CTL1,((TARG_ReadByte(FCLA0CTL1)&0xf8) + Value)); \
        TARG_WriteByte(FCLA0CTL1,((TARG_ReadByte(FCLA0CTL1)) | 0x80 ))

/* INTP2 */
#define Iodd_IT_EDGES_27_2(Value) \
        TARG_WriteBitInShort(PFC27, BIT2, 0); \
        TARG_WriteBitInShort(PFCE27, BIT2, 0); \
        TARG_WriteByte(FCLA0CTL2,((TARG_ReadByte(FCLA0CTL2)&0xf8) + Value)); \
        TARG_WriteByte(FCLA0CTL2,((TARG_ReadByte(FCLA0CTL2)) | 0x80 ))

/* INTP3 */
#define Iodd_IT_EDGES_27_3(Value) \
        TARG_WriteBitInShort(PFC27, BIT3, 0); \
        TARG_WriteBitInShort(PFCE27, BIT3, 0); \
        TARG_WriteByte(FCLA0CTL3,((TARG_ReadByte(FCLA0CTL3)&0xf8) + Value)); \
        TARG_WriteByte(FCLA0CTL3,((TARG_ReadByte(FCLA0CTL3)) | 0x80 ))

/* INTP4 */
#define Iodd_IT_EDGES_27_4(Value) \
        TARG_WriteBitInShort(PFC27, BIT4, 0); \
        TARG_WriteBitInShort(PFCE27, BIT4, 0); \
        TARG_WriteByte(FCLA0CTL4,((TARG_ReadByte(FCLA0CTL4)&0xf8) + Value)); \
        TARG_WriteByte(FCLA0CTL4,((TARG_ReadByte(FCLA0CTL4)) | 0x80 ))

/* INTP5 */
#define Iodd_IT_EDGES_27_5(Value) \
        TARG_WriteBitInShort(PFC27, BIT5, 0); \
        TARG_WriteBitInShort(PFCE27, BIT5, 0); \
        TARG_WriteByte(FCLA0CTL5,((TARG_ReadByte(FCLA0CTL5)&0xf8) + Value)); \
        TARG_WriteByte(FCLA0CTL5,((TARG_ReadByte(FCLA0CTL5)) | 0x80 ))

/* INTP6 */
#define Iodd_IT_EDGES_28_0(Value) \
        TARG_WriteBitInShort(PFC28, BIT0, 0); \
        TARG_WriteBitInShort(PFCE28, BIT0, 0); \
        TARG_WriteByte(FCLA0CTL6,((TARG_ReadByte(FCLA0CTL6)&0xf8) + Value)); \
        TARG_WriteByte(FCLA0CTL6,((TARG_ReadByte(FCLA0CTL6)) | 0x80 ))

/* INTP7 */
#define Iodd_IT_EDGES_28_1(Value) \
        TARG_WriteBitInShort(PFC28, BIT1, 0); \
        TARG_WriteBitInShort(PFCE28, BIT1, 0); \
        TARG_WriteByte(FCLA0CTL7,((TARG_ReadByte(FCLA0CTL7)&0xf8) + Value)); \
        TARG_WriteByte(FCLA0CTL7,((TARG_ReadByte(FCLA0CTL7)) | 0x80 ))

/* INTP8 */
#define Iodd_IT_EDGES_28_2(Value) \
        TARG_WriteBitInShort(PFC28, BIT2, 0); \
        TARG_WriteBitInShort(PFCE28, BIT2, 0); \
        TARG_WriteByte(FCLA1CTL0,((TARG_ReadByte(FCLA1CTL0)&0xf8) + Value)); \
        TARG_WriteByte(FCLA1CTL0,((TARG_ReadByte(FCLA1CTL0)) | 0x80 ))

/* INTP9 */
#define Iodd_IT_EDGES_28_3(Value) \
        TARG_WriteBitInShort(PFC28, BIT3, 0); \
        TARG_WriteBitInShort(PFCE28, BIT3, 0); \
        TARG_WriteByte(FCLA1CTL1,((TARG_ReadByte(FCLA1CTL1)&0xf8) + Value)); \
        TARG_WriteByte(FCLA1CTL1,((TARG_ReadByte(FCLA1CTL1)) | 0x80 ))

/* INTP10 */
#define Iodd_IT_EDGES_28_4(Value) \
        TARG_WriteBitInShort(PFC28, BIT4, 0); \
        TARG_WriteBitInShort(PFCE28, BIT4, 0); \
        TARG_WriteByte(FCLA1CTL2,((TARG_ReadByte(FCLA1CTL2)&0xf8) + Value)); \
        TARG_WriteByte(FCLA1CTL2,((TARG_ReadByte(FCLA1CTL2)) | 0x80 ))

#endif

#define IODD_IT_FALLING_EDGE(PortName,PinNumber)     \
        Iodd_IT_EDGES_ ##PortName##_## PinNumber (2); \
        TARG_WriteBitInShort(PM ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 1); \
        TARG_WriteBitInShort(PMC ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 1); \
        TARG_WriteBitInShort(PIBC ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 1)

#define IODD_IT_RISING_EDGE(PortName,PinNumber)      \
        Iodd_IT_EDGES_ ##PortName##_##PinNumber (1); \
        TARG_WriteBitInShort(PM ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 1); \
        TARG_WriteBitInShort(PMC ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 1); \
        TARG_WriteBitInShort(PIBC ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 1)

#define IODD_IT_BOTH_EDGE(PortName,PinNumber)        \
        Iodd_IT_EDGES_ ## PortName##_## PinNumber (3); \
        TARG_WriteBitInShort(PM ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 1); \
        TARG_WriteBitInShort(PMC ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 1); \
        TARG_WriteBitInShort(PIBC ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 1)

#define IODD_IT_LOW_LEVEL(PortName,PinNumber)        \
        Iodd_IT_EDGES_ ## PortName##_## PinNumber (4); \
        TARG_WriteBitInShort(PM ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 1); \
        TARG_WriteBitInShort(PMC ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 1); \
        TARG_WriteBitInShort(PIBC ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 1)

#define IODD_IT_HIGH_LEVEL(PortName,PinNumber)       \
        Iodd_IT_EDGES_ ## PortName##_## PinNumber (5); \
        TARG_WriteBitInShort(PM ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 1); \
        TARG_WriteBitInShort(PMC ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 1); \
        TARG_WriteBitInShort(PIBC ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 1)

#define IODD_NMI_FALLING_EDGE(PortName,PinNumber) \
        Iodd_IT_EDGES_ ##PortName##_## PinNumber (2); \
        TARG_WriteBitInShort(PM ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 1); \
        TARG_WriteBitInShort(PMC ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 1); \
        TARG_WriteBitInShort(PIBC ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 1)

#define IODD_NMI_RISING_EDGE(PortName,PinNumber) \
        Iodd_IT_EDGES_ ##PortName##_##PinNumber (1); \
        TARG_WriteBitInShort(PM ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 1); \
        TARG_WriteBitInShort(PMC ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 1); \
        TARG_WriteBitInShort(PIBC ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 1)

#define IODD_NMI_BOTH_EDGE(PortName,PinNumber) \
        Iodd_IT_EDGES_ ## PortName##_## PinNumber (3); \
        TARG_WriteBitInShort(PM ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 1); \
        TARG_WriteBitInShort(PMC ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 1); \
        TARG_WriteBitInShort(PIBC ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 1)

#define IODD_NMI_LOW_LEVEL(PortName,PinNumber) \
        Iodd_IT_EDGES_ ## PortName##_## PinNumber (4); \
        TARG_WriteBitInShort(PM ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 1); \
        TARG_WriteBitInShort(PMC ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 1); \
        TARG_WriteBitInShort(PIBC ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 1)

#define IODD_NMI_HIGH_LEVEL(PortName,PinNumber) \
        Iodd_IT_EDGES_ ## PortName##_## PinNumber (5); \
        TARG_WriteBitInShort(PM ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 1); \
        TARG_WriteBitInShort(PMC ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 1); \
        TARG_WriteBitInShort(PIBC ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 1)

#endif /* __REL_V850_Dx4__ */

#if defined (__NEC_V850_Dx3__) || defined(__NEC_V850_Fx3__)
#define IODD_STANDARD(PortName,PinNumber) \
        Iodd_WREG_MC_## PortName ## PinNumber(0)
#endif /* (__NEC_V850_Dx3__) || defined(__NEC_V850_Fx3__) */

#if defined (__REL_V850_Dx4__)
#define IODD_STANDARD(PortName,PinNumber) \
        TARG_WriteBitInShort(PMC ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 0)
#endif /* __REL_V850_Dx4__ */
#endif /* __NEC_V850__ */


/* Pull-device control ------------------------------------------------------ */

#ifdef __MC9S12xx__
/* PIM module */
  /* - pull-up - */
#define PORT_PER_UP_PT(PortName,PinNumber) \
        TARG_WriteBit(PER ## PortName, PORT_BIT_PER ## PortName ## PinNumber, 1);\
        TARG_WriteBit(PPS ## PortName, PORT_BIT_PPS ## PortName ## PinNumber, 0)

#define PORT_PER_UP_PS(PortName,PinNumber) \
        TARG_WriteBit(PER ## PortName, PORT_BIT_PER ## PortName ## PinNumber, 1);\
        TARG_WriteBit(PPS ## PortName, PORT_BIT_PPS ## PortName ## PinNumber, 0)

#define PORT_PER_UP_PM(PortName,PinNumber) \
        TARG_WriteBit(PER ## PortName, PORT_BIT_PER ## PortName ## PinNumber, 1);\
        TARG_WriteBit(PPS ## PortName, PORT_BIT_PPS ## PortName ## PinNumber, 0)

#define PORT_PER_UP_PP(PortName,PinNumber) \
        TARG_WriteBit(PER ## PortName, PORT_BIT_PER ## PortName ## PinNumber, 1);\
        TARG_WriteBit(PPS ## PortName, PORT_BIT_PPS ## PortName ## PinNumber, 0)

#define PORT_PER_UP_PL(PortName,PinNumber) \
        TARG_WriteBit(PER ## PortName, PORT_BIT_PER ## PortName ## PinNumber, 1);\
        TARG_WriteBit(PPS ## PortName, PORT_BIT_PPS ## PortName ## PinNumber, 0)

#define PORT_PER_UP_PU(PortName,PinNumber) \
        TARG_WriteBit(PER ## PortName, PORT_BIT_PER ## PortName ## PinNumber, 1);\
        TARG_WriteBit(PPS ## PortName, PORT_BIT_PPS ## PortName ## PinNumber, 0)

#define PORT_PER_UP_PV(PortName,PinNumber) \
        TARG_WriteBit(PER ## PortName, PORT_BIT_PER ## PortName ## PinNumber, 1);\
        TARG_WriteBit(PPS ## PortName, PORT_BIT_PPS ## PortName ## PinNumber, 0)

/* MC9S12-H variant */
#if defined(__MC9S12H__)

#define PORT_PER_UP_PH(PortName,PinNumber) \
        TARG_WriteBit(PER ## PortName, PORT_BIT_PER ## PortName ## PinNumber, 1);\
        TARG_WriteBit(PPS ## PortName, PORT_BIT_PPS ## PortName ## PinNumber, 0)

#define PORT_PER_UP_PJ(PortName,PinNumber) \
        TARG_WriteBit(PER ## PortName, PORT_BIT_PER ## PortName ## PinNumber, 1);\
        TARG_WriteBit(PPS ## PortName, PORT_BIT_PPS ## PortName ## PinNumber, 0)

#endif /* defined(__MC9S12H__) */

/* MC9S12-H variant or MC9S12XHZ variant*/
#if defined(__MC9S12H__) || defined(__MC9S12XHZ__)

#define PORT_PER_UP_PW(PortName,PinNumber) \
        TARG_WriteBit(PER ## PortName, PORT_BIT_PER ## PortName ## PinNumber, 1);\
        TARG_WriteBit(PPS ## PortName, PORT_BIT_PPS ## PortName ## PinNumber, 0)

#endif /* defined(__MC9S12H__) || defined(__MC9S12XHZ__) */

  /* - pull-down - */
#define PORT_PER_DOWN_PT(PortName,PinNumber) \
        TARG_WriteBit(PER ## PortName, PORT_BIT_PER ## PortName ## PinNumber, 1);\
        TARG_WriteBit(PPS ## PortName, PORT_BIT_PPS ## PortName ## PinNumber, 1)

#define PORT_PER_DOWN_PS(PortName,PinNumber) \
        TARG_WriteBit(PER ## PortName, PORT_BIT_PER ## PortName ## PinNumber, 1);\
        TARG_WriteBit(PPS ## PortName, PORT_BIT_PPS ## PortName ## PinNumber, 1)

#define PORT_PER_DOWN_PM(PortName,PinNumber) \
        TARG_WriteBit(PER ## PortName, PORT_BIT_PER ## PortName ## PinNumber, 1);\
        TARG_WriteBit(PPS ## PortName, PORT_BIT_PPS ## PortName ## PinNumber, 1)

#define PORT_PER_DOWN_PP(PortName,PinNumber) \
        TARG_WriteBit(PER ## PortName, PORT_BIT_PER ## PortName ## PinNumber, 1);\
        TARG_WriteBit(PPS ## PortName, PORT_BIT_PPS ## PortName ## PinNumber, 1)

#define PORT_PER_DOWN_PL(PortName,PinNumber) \
        TARG_WriteBit(PER ## PortName, PORT_BIT_PER ## PortName ## PinNumber, 1);\
        TARG_WriteBit(PPS ## PortName, PORT_BIT_PPS ## PortName ## PinNumber, 1)

#define PORT_PER_DOWN_PU(PortName,PinNumber) \
        TARG_WriteBit(PER ## PortName, PORT_BIT_PER ## PortName ## PinNumber, 1);\
        TARG_WriteBit(PPS ## PortName, PORT_BIT_PPS ## PortName ## PinNumber, 1)

#define PORT_PER_DOWN_PV(PortName,PinNumber) \
        TARG_WriteBit(PER ## PortName, PORT_BIT_PER ## PortName ## PinNumber, 1);\
        TARG_WriteBit(PPS ## PortName, PORT_BIT_PPS ## PortName ## PinNumber, 1)

/* MC9S12-H variant */
#if defined(__MC9S12H__)

#define PORT_PER_DOWN_PH(PortName,PinNumber) \
        TARG_WriteBit(PER ## PortName, PORT_BIT_PER ## PortName ## PinNumber, 1);\
        TARG_WriteBit(PPS ## PortName, PORT_BIT_PPS ## PortName ## PinNumber, 1)

#define PORT_PER_DOWN_PJ(PortName,PinNumber) \
        TARG_WriteBit(PER ## PortName, PORT_BIT_PER ## PortName ## PinNumber, 1);\
        TARG_WriteBit(PPS ## PortName, PORT_BIT_PPS ## PortName ## PinNumber, 1)

#endif /* defined(__MC9S12H__) */

/* MC9S12-H variant or MC9S12XHZ variant*/
#if defined(__MC9S12H__) || defined(__MC9S12XHZ__)

#define PORT_PER_DOWN_PW(PortName,PinNumber) \
        TARG_WriteBit(PER ## PortName, PORT_BIT_PER ## PortName ## PinNumber, 1);\
        TARG_WriteBit(PPS ## PortName, PORT_BIT_PPS ## PortName ## PinNumber, 1)

#endif /* defined(__MC9S12H__)  || defined(__MC9S12XHZ__) */

  /* - no pull device - */
#define PORT_PER_NO_PT(PortName,PinNumber) \
        TARG_WriteBit(PER ## PortName, PORT_BIT_PER ## PortName ## PinNumber, 0);\

#define PORT_PER_NO_PS(PortName,PinNumber) \
        TARG_WriteBit(PER ## PortName, PORT_BIT_PER ## PortName ## PinNumber, 0)

#define PORT_PER_NO_PM(PortName,PinNumber) \
        TARG_WriteBit(PER ## PortName, PORT_BIT_PER ## PortName ## PinNumber, 0)

#define PORT_PER_NO_PP(PortName,PinNumber) \
        TARG_WriteBit(PER ## PortName, PORT_BIT_PER ## PortName ## PinNumber, 0)

#define PORT_PER_NO_PL(PortName,PinNumber) \
        TARG_WriteBit(PER ## PortName, PORT_BIT_PER ## PortName ## PinNumber, 0)

#define PORT_PER_NOP_PU(PortName,PinNumber) \
        TARG_WriteBit(PER ## PortName, PORT_BIT_PER ## PortName ## PinNumber, 0)

#define PORT_PER_NO_PV(PortName,PinNumber) \
        TARG_WriteBit(PER ## PortName, PORT_BIT_PER ## PortName ## PinNumber, 0)

/* MC9S12-H variant */
#if defined(__MC9S12H__)

#define PORT_PER_NO_PH(PortName,PinNumber) \
        TARG_WriteBit(PER ## PortName, PORT_BIT_PER ## PortName ## PinNumber, 0)

#define PORT_PER_NO_PJ(PortName,PinNumber) \
        TARG_WriteBit(PER ## PortName, PORT_BIT_PER ## PortName ## PinNumber, 0)

#endif /* defined(__MC9S12H__) */

/* MC9S12-H variant or MC9S12XHZ variant*/
#if defined(__MC9S12H__) || defined(__MC9S12XHZ__)

#define PORT_PER_NO_PW(PortName,PinNumber) \
        TARG_WriteBit(PER ## PortName, PORT_BIT_PER ## PortName ## PinNumber, 0)

#endif /* defined(__MC9S12H__) || defined(__MC9S12XHZ__) */

/* MEBI module */
  /* - pull-up for all pins - */
#define PORT_PER_UP_PA(PortName,PinNumber) \
        TARG_WriteBit(PUCR, PORT_BIT_PUP ## PortName ## E, 1)

#define PORT_PER_UP_PB(PortName,PinNumber) \
        TARG_WriteBit(PUCR, PORT_BIT_PUP ## PortName ## E, 1)

#ifdef __MC9S12XHZ__

#define PORT_PER_UP_PC(PortName,PinNumber) \
        TARG_WriteBit(PUCR, PORT_BIT_PUP ## PortName ## E, 1)

#define PORT_PER_UP_PD(PortName,PinNumber) \
        TARG_WriteBit(PUCR, PORT_BIT_PUP ## PortName ## E, 1)

#endif /* __MC9S12XHZ__ */

#define PORT_PER_UP_PE(PortName,PinNumber) \
        TARG_WriteBit(PUCR, PORT_BIT_PUP ## PortName ## E, 1)

#define PORT_PER_UP_PK(PortName,PinNumber) \
        TARG_WriteBit(PUCR, PORT_BIT_PUP ## PortName ## E, 1)

  /* - no pull device for all pins - */
#define PORT_PER_NO_PA(PortName,PinNumber) \
        TARG_WriteBit(PUCR, PORT_BIT_PUP ## PortName ## E, 0)

#define PORT_PER_NO_PB(PortName,PinNumber) \
        TARG_WriteBit(PUCR, PORT_BIT_PUP ## PortName ## E, 0)

#ifdef __MC9S12XHZ__

#define PORT_PER_NO_PC(PortName,PinNumber) \
        TARG_WriteBit(PUCR, PORT_BIT_PUP ## PortName ## E, 0)

#define PORT_PER_NO_PD(PortName,PinNumber) \
        TARG_WriteBit(PUCR, PORT_BIT_PUP ## PortName ## E, 0)

#endif /* __MC9S12XHZ__ */

#define PORT_PER_NO_PE(PortName,PinNumber) \
        TARG_WriteBit(PUCR, PORT_BIT_PUP ## PortName ## E, 0)

#define PORT_PER_NO_PK(PortName,PinNumber) \
        TARG_WriteBit(PUCR, PORT_BIT_PUP ## PortName ## E, 0)

/* ATD */

/* MC9S12-H variant */
#if defined(__MC9S12H__)

#define PORT_PER_NO_P0(PortName,PinNumber)
#define PORT_PER_NO_P1(PortName,PinNumber)

#endif /* defined(__MC9S12H__) */


/* MC9S12-HZ and MC9S12XHZ variant */
#if (defined(__MC9S12HZ__) || defined(__MC9S12XHZ__))

/*  In pin setup we use ports name 0 and 1 to be compliant with S12H */
/*  For S12HZ analog port ATD1 = I/O port AD (PORTAD = PORT1)        */

/* used when pin only used as digital input (no analog input used) */
/* port name : AD */

/* used when pin used both as digital input and as analog input */
/* port name : 1 */

  /* - pull-up - */
#define PORT_PER_UP_PAD(PortName,PinNumber) \
        TARG_WriteBit(PER ## PortName, PORT_BIT_PER ## PortName ## PinNumber, 1);\
        TARG_WriteBit(PPS ## PortName, PORT_BIT_PPS ## PortName ## PinNumber, 0)

#define PORT_PER_UP_P1(PortName,PinNumber)  PORT_PER_UP_PAD(AD,PinNumber)

  /* - pull-down - */
#define PORT_PER_DOWN_PAD(PortName,PinNumber) \
        TARG_WriteBit(PER ## PortName, PORT_BIT_PER ## PortName ## PinNumber, 1);\
        TARG_WriteBit(PPS ## PortName, PORT_BIT_PPS ## PortName ## PinNumber, 1)

#define PORT_PER_DOWN_P1(PortName,PinNumber)  PORT_PER_DOWN_PAD(AD,PinNumber)

  /* - no pull device - */
#define PORT_PER_NO_PAD(PortName,PinNumber) \
        TARG_WriteBit(PER ## PortName, PORT_BIT_PER ## PortName ## PinNumber, 0)

#define PORT_PER_NO_P1(PortName,PinNumber)  PORT_PER_NO_PAD(AD,PinNumber)

#endif /* (defined(__MC9S12HZ__) || defined(__MC9S12XHZ__) */


#define Iodd_SetNoPullDeviceBit(PortName,PinNumber) \
        PORT_PER_NO_P ## PortName(PortName,PinNumber)

#define Iodd_SetPullUpBit(PortName,PinNumber) \
        PORT_PER_UP_P ## PortName(PortName,PinNumber)

#define Iodd_SetPullDownBit(PortName,PinNumber) \
        PORT_PER_DOWN_P ## PortName(PortName,PinNumber)
#endif /* __MC9S12xx__ */

#ifdef __MC9S08xx__
  /* - pull-up - */
#define PORT_PE_UP_PA(PinNumber) \
        TARG_WriteBit(PTAPE, PORT_BIT_PTAPE ## PinNumber, 1);

#define PORT_PE_UP_PB(PinNumber) \
        TARG_WriteBit(PTBPE, PORT_BIT_PTBPE ## PinNumber, 1);

#define PORT_PE_UP_PC(PinNumber) \
        TARG_WriteBit(PTCPE, PORT_BIT_PTCPE ## PinNumber, 1);

#define PORT_PE_UP_PD(PinNumber) \
        TARG_WriteBit(PTDPE, PORT_BIT_PTDPE ## PinNumber, 1);

#define PORT_PE_UP_PE(PinNumber) \
        TARG_WriteBit(PTEPE, PORT_BIT_PTEPE ## PinNumber, 1);

#define PORT_PE_UP_PF(PinNumber) \
        TARG_WriteBit(PTFPE, PORT_BIT_PTFPE ## PinNumber, 1);

#define PORT_PE_UP_PG(PinNumber) \
        TARG_WriteBit(PTGPE, PORT_BIT_PTGPE ## PinNumber, 1);

#define PORT_PE_UP_PIRQ(PinNumber) \
        /*NO PULL-UP configuration for IRQ*/

  /* - no pull device - */
#define PORT_PE_NO_PA(PinNumber) \
        TARG_WriteBit(PTAPE, PORT_BIT_PTAPE ## PinNumber, 0);

#define PORT_PE_NO_PB(PinNumber) \
        TARG_WriteBit(PTBPE, PORT_BIT_PTBPE ## PinNumber, 0);

#define PORT_PE_NO_PC(PinNumber) \
        TARG_WriteBit(PTCPE, PORT_BIT_PTCPE ## PinNumber, 0);

#define PORT_PE_NO_PD(PinNumber) \
        TARG_WriteBit(PTDPE, PORT_BIT_PTDPE ## PinNumber, 0);

#define PORT_PE_NO_PE(PinNumber) \
        TARG_WriteBit(PTEPE, PORT_BIT_PTEPE ## PinNumber, 0);

#define PORT_PE_NO_PF(PinNumber) \
        TARG_WriteBit(PTFPE, PORT_BIT_PTFPE ## PinNumber, 0);

#define PORT_PE_NO_PG(PinNumber) \
        TARG_WriteBit(PTGPE, PORT_BIT_PTGPE ## PinNumber, 0);

#define PORT_PE_NO_PIRQ(PinNumber) \
        /*NO PULL-UP configuration for IRQ*/

#define PORT_PE_NO_P(PortName,PinNumber) \
        PORT_PE_NO_P ## PortName(PinNumber)

#define PORT_PE_UP_P(PortName,PinNumber) \
        PORT_PE_UP_P ## PortName(PinNumber)

#define Iodd_SetNoPullDeviceBit(PortName,PinNumber)\
        PORT_PE_NO_P (PortName,PinNumber)

#define Iodd_SetPullUpBit(PortName,PinNumber) \
        PORT_PE_UP_P (PortName,PinNumber)
#endif /* __MC9S08xx__ */

#ifdef __NEC_V850_Fx3__
#define Iodd_SetPullUpBit(PortName,PinNumber) \
        Iodd_WREG_PU_## PortName ## PinNumber(1)

#define Iodd_SetPullDownBit(PortName,PinNumber) \
        Iodd_WREG_PU_## PortName ## PinNumber(0)
#endif /* __NEC_V850_Fx3__ */

#ifdef __REL_V850_Dx4__
#ifdef NO_PULLUP
#define Iodd_SetPullUpBit(PortName,PinNumber)

#define Iodd_SetNoPullDeviceBit(PortName,PinNumber)

#define Iodd_SetPullDownBit(PortName,PinNumber)
#else
#define Iodd_SetPullUpBit(PortName,PinNumber) \
        TARG_WriteBitInLong(PU ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 1);\
        TARG_WriteBitInLong(PD ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 0)

#define Iodd_SetNoPullDeviceBit(PortName,PinNumber) \
        TARG_WriteBitInLong(PD ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 0);\
        TARG_WriteBitInLong(PU ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 0)

#define Iodd_SetPullDownBit(PortName,PinNumber) \
        TARG_WriteBitInLong(PD ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 1);\
        TARG_WriteBitInLong(PU ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 0)

#endif /* NO_PULLUP */
#endif /* __REL_V850_Dx4__ */


/* Input Pull Up Mode ------------------------------------------------------- */

#ifdef __MC9S12xx__

#define IODD_NO_PULL_UP(PortName,PinNumber) \
        Iodd_SetNoPullDeviceBit(PortName,PinNumber)

#define IODD_PULL_UP(PortName,PinNumber) \
        Iodd_SetPullUpBit(PortName,PinNumber)

#define IODD_PULL_DOWN(PortName,PinNumber) \
        Iodd_SetPullDownBit(PortName,PinNumber)

#endif /* __MC9S12xx__ */

#ifdef __MC9S08xx__

#define IODD_NO_PULL_UP(PortName,PinNumber) \
        Iodd_SetNoPullDeviceBit(PortName,PinNumber)

#define IODD_PULL_UP(PortName,PinNumber) \
        Iodd_SetPullUpBit(PortName,PinNumber)

#endif /* __MC9S08xx__ */

#ifdef __NEC_V850_Fx3__

#define IODD_PULL_UP(PortName,PinNumber) \
        Iodd_SetPullUpBit(PortName,PinNumber)

#define IODD_NO_PULL_UP(PortName,PinNumber) \
        Iodd_SetPullDownBit(PortName,PinNumber)

#endif /* __NEC_V850_Fx3__ */

#ifdef __REL_V850_Dx4__
#define IODD_PULL_UP(PortName,PinNumber) \
        Iodd_SetPullUpBit(PortName,PinNumber)

#define IODD_NO_PULL_UP(PortName,PinNumber) \
        Iodd_SetNoPullDeviceBit(PortName,PinNumber)

#define IODD_PULL_DOWN(PortName,PinNumber) \
        Iodd_SetPullDownBit(PortName,PinNumber)

#define IODD_NO_PULL_OPTION(PortName,PinNumber)

#endif /* __REL_V850_Dx4__ */

#ifdef __NEC_V850_Dx3__  /* no pull-up on this chip */

#define IODD_NO_PULL_UP(PortName,PinNumber)

#define IODD_WREG_ICC_ILC(PortName,PinNumber,ICCValue,ILCValue) \
        Iodd_WREG_ICC_## PortName ## PinNumber(ICCValue);       \
        Iodd_WREG_ILC_## PortName ## PinNumber(ILCValue)

#define IODD_SCHMITT_03_07Vdd(PortName,PinNumber)  \
        Iodd_WREG_ICC_## PortName ## PinNumber(1); \
        Iodd_WREG_ILC_## PortName ## PinNumber(0)

#define IODD_SCHMITT_04_08Vdd(PortName,PinNumber)  \
        Iodd_WREG_ICC_## PortName ## PinNumber(1); \
        Iodd_WREG_ILC_## PortName ## PinNumber(1)

#define IODD_CMOS_03_07Vdd(PortName,PinNumber)     \
        Iodd_WREG_ICC_## PortName ## PinNumber(0); \
        Iodd_WREG_ILC_## PortName ## PinNumber(0)

#define IODD_CMOS_04_08Vdd(PortName,PinNumber)     \
        Iodd_WREG_ICC_## PortName ## PinNumber(0); \
        Iodd_WREG_ILC_## PortName ## PinNumber(1)

#endif /* __NEC_V850_Dx3__ */


/* Output Open Drain State -------------------------------------------------- */


/* Output High-Inpedance selection ------------------------------------------ */

/* Output pin setup for HCS12 ----------------------------------------------- */

#ifdef __MC9S12xx__
#define IODD_NO_OUT_SETUP(PortName,PinNumber)


/* - port with open drain - */
#define IODD_OPENDRAIN(PortName,PinNumber) \
        PORT_WOM_P ## PortName(PortName,PinNumber)

#define PORT_WOM_PS(PortName,PinNumber) \
        Iodd_SetOpenDrainBit(PortName,PinNumber, 1)

#define PORT_WOM_PM(PortName,PinNumber) \
        Iodd_SetOpenDrainBit(PortName,PinNumber, 1)


/* - port with slew rate control - */
#define IODD_SLEWRATE(PortName,PinNumber) \
        PORT_SRR_P ## PortName(PortName,PinNumber)

#define PORT_SRR_PU(PortName,PinNumber) \
        TARG_WriteBit(SRR ## PortName, PORT_BIT_SRR ## PortName ## PinNumber, 1)

#define PORT_SRR_PV(PortName,PinNumber) \
        TARG_WriteBit(SRR ## PortName, PORT_BIT_SRR ## PortName ## PinNumber, 1)

#ifdef __MC9S12XHZ__

#define PORT_SRR_PT(PortName,PinNumber) \
        TARG_WriteBit(SRR ## PortName, PORT_BIT_SRR ## PortName ## PinNumber, 1)

#define PORT_SRR_PS(PortName,PinNumber) \
        TARG_WriteBit(SRR ## PortName, PORT_BIT_SRR ## PortName ## PinNumber, 1)

#define PORT_SRR_PM(PortName,PinNumber) \
        TARG_WriteBit(SRR ## PortName, PORT_BIT_SRR ## PortName ## PinNumber, 1)

#define PORT_SRR_PP(PortName,PinNumber) \
        TARG_WriteBit(SRR ## PortName, PORT_BIT_SRR ## PortName ## PinNumber, 1)

#define PORT_SRR_PL(PortName,PinNumber) \
        TARG_WriteBit(SRR ## PortName, PORT_BIT_SRR ## PortName ## PinNumber, 1)

#endif /* __MC9S12XHZ__ */

/* MC9S12-H and MC9S12XHZ variant */
#if (defined(__MC9S12H__) || defined(__MC9S12XHZ__))

#define PORT_SRR_PW(PortName,PinNumber) \
        TARG_WriteBit(SRR ## PortName, PORT_BIT_SRR ## PortName ## PinNumber, 1)

#endif /* (defined(__MC9S12H__) || defined(__MC9S12XHZ__)) */


/* - port with each pin with reduced control - */
#define IODD_REDUCED(PortName,PinNumber) \
        PORT_RDR_P ## PortName(PortName,PinNumber)

#define PORT_RDR_PT(PortName,PinNumber) \
        TARG_WriteBit(RDR ## PortName, PORT_BIT_RDR ## PortName ## PinNumber, 1)

#define PORT_RDR_PS(PortName,PinNumber) \
        TARG_WriteBit(RDR ## PortName, PORT_BIT_RDR ## PortName ## PinNumber, 1)

#define PORT_RDR_PM(PortName,PinNumber) \
        TARG_WriteBit(RDR ## PortName, PORT_BIT_RDR ## PortName ## PinNumber, 1)

#define PORT_RDR_PP(PortName,PinNumber) \
        TARG_WriteBit(RDR ## PortName, PORT_BIT_RDR ## PortName ## PinNumber, 1)

/* MC9S12-H variant */
#if defined(__MC9S12H__)

#define PORT_RDR_PH(PortName,PinNumber) \
        TARG_WriteBit(RDR ## PortName, PORT_BIT_RDR ## PortName ## PinNumber, 1)

#define PORT_RDR_PJ(PortName,PinNumber) \
        TARG_WriteBit(RDR ## PortName, PORT_BIT_RDR ## PortName ## PinNumber, 1)

#endif /* defined(__MC9S12H__) */

#define PORT_RDR_PL(PortName,PinNumber) \
        TARG_WriteBit(RDR ## PortName, PORT_BIT_RDR ## PortName ## PinNumber, 1)

/* MC9S12-HZ and MC9S12XHZ variant */
#if (defined(__MC9S12HZ__) || defined(__MC9S12XHZ__))

/*  In pin setup we use ports name 0 and 1 to be compliant with S12H */
/*  For S12HZ analog port ATD1 = I/O port AD (PORTAD = PORT1)        */

/* used when pin only used as digital input (no analog input used) */
/* port name : AD */

#define PORT_RDR_PAD(PortName,PinNumber) \
        TARG_WriteBit(RDR ## PortName, PORT_BIT_RDR ## PortName ## PinNumber, 1)

#endif /* (defined(__MC9S12HZ__) || defined(__MC9S12XHZ__)) */


/* - port with reduced control for all pins - */
#define PORT_RDR_PA(PortName,PinNumber) \
        TARG_WriteBit(RDRIV, PORT_BIT_RDP ## PortName, 1)

#define PORT_RDR_PB(PortName,PinNumber) \
        TARG_WriteBit(RDRIV, PORT_BIT_RDP ## PortName, 1)

#ifdef __MC9S12XHZ__

#define PORT_RDR_PC(PortName,PinNumber) \
        TARG_WriteBit(RDRIV, PORT_BIT_RDP ## PortName, 1)

#define PORT_RDR_PD(PortName,PinNumber) \
        TARG_WriteBit(RDRIV, PORT_BIT_RDP ## PortName, 1)

#endif /* __MC9S12XHZ__ */

#define PORT_RDR_PE(PortName,PinNumber) \
        TARG_WriteBit(RDRIV, PORT_BIT_RDP ## PortName, 1)

#define PORT_RDR_PK(PortName,PinNumber) \
        TARG_WriteBit(RDRIV, PORT_BIT_RDP ## PortName, 1)


/* - open drain and reduced - */
#define IODD_OPENDRAIN_REDUCED(PortName,PinNumber) \
        IODD_OPENDRAIN(PortName,PinNumber); \
        IODD_REDUCED(PortName,PinNumber)


/* - port with pull device on open-drain output - */
#define IODD_OPENDRAIN_PULLUP(PortName,PinNumber) \
        IODD_OPENDRAIN(PortName,PinNumber); \
        IODD_PULL_UP(PortName,PinNumber)

#define IODD_OPENDRAIN_PULLDOWN(PortName,PinNumber) \
        IODD_OPENDRAIN(PortName,PinNumber); \
        IODD_PULL_DOWN(PortName,PinNumber)


/* - port with reduced control and pull device on open-drain output - */
#define IODD_OPENDRAIN_REDUCED_PULLUP(PortName,PinNumber) \
        IODD_OPENDRAIN(PortName,PinNumber); \
        IODD_REDUCED(PortName,PinNumber); \
        IODD_PULL_UP(PortName,PinNumber)

#define IODD_OPENDRAIN_REDUCED_PULLDOWN(PortName,PinNumber) \
        IODD_OPENDRAIN(PortName,PinNumber); \
        IODD_REDUCED(PortName,PinNumber); \
        IODD_PULL_DOWN(PortName,PinNumber)

#endif /* __MC9S12xx__ */


/* Output pin setup for S08 ----------------------------------------------- */

#ifdef __MC9S08xx__

#define IODD_NO_OUT_SETUP(PortName,PinNumber)

/* - port with slew rate control enabled - */
#define IODD_SLEWRATE(PortName,PinNumber) \
        PORT_SR_P ## PortName(PinNumber)

#define PORT_SR_PA(PinNumber) \
        TARG_WriteBit(PTASE , PORT_BIT_PTASE ## PinNumber, 1)

#define PORT_SR_PB(PinNumber) \
        TARG_WriteBit(PTBSE , PORT_BIT_PTBSE ## PinNumber, 1)

#define PORT_SR_PC(PinNumber) \
        TARG_WriteBit(PTCSE , PORT_BIT_PTCSE ## PinNumber, 1)

#define PORT_SR_PD(PinNumber) \
        TARG_WriteBit(PTDSE , PORT_BIT_PTDSE ## PinNumber, 1)

#define PORT_SR_PE(PinNumber) \
        TARG_WriteBit(PTESE , PORT_BIT_PTESE ## PinNumber, 1)

#define PORT_SR_PF(PinNumber) \
        TARG_WriteBit(PTFSE , PORT_BIT_PTFSE ## PinNumber, 1)

#define PORT_SR_PG(PinNumber) \
        TARG_WriteBit(PTGSE , PORT_BIT_PTGSE ## PinNumber, 1)

/* - port with each pin with high output drive control - */
#define IODD_DRIVESTRENGTH(PortName,PinNumber) \
        PORT_DS_P ## PortName(PinNumber)

#define PORT_DS_PA(PinNumber) \
        TARG_WriteBit(PTADS, PORT_BIT_PTADS ## PinNumber, 1)

#define PORT_DS_PB(PinNumber) \
        TARG_WriteBit(PTBDS, PORT_BIT_PTBDS ## PinNumber, 1)

#define PORT_DS_PC(PinNumber) \
        TARG_WriteBit(PTCDS, PORT_BIT_PTCDS ## PinNumber, 1)

#define PORT_DS_PD(PinNumber) \
        TARG_WriteBit(PTDDS, PORT_BIT_PTDDS ## PinNumber, 1)

#define PORT_DS_PE(PinNumber) \
        TARG_WriteBit(PTEDS, PORT_BIT_PTEDS ## PinNumber, 1)

#define PORT_DS_PF(PinNumber) \
        TARG_WriteBit(PTFDS, PORT_BIT_PTFDS ## PinNumber, 1)

#define PORT_DS_PG(PinNumber) \
        TARG_WriteBit(PTGDS, PORT_BIT_PTGDS ## PinNumber, 1)

#endif /* __MC9S08xx__ */


/* Set one bit in a port direction register --------------------------------- */

#ifdef __NEC_V850__
#if defined (__NEC_V850_Dx3__) || defined(__NEC_V850_Fx3__)
#define Iodd_SetDdrBit(PortName,PinNumber,Value) \
        Iodd_WREG_M_## PortName ## PinNumber(Value)
#endif /* (__NEC_V850_Dx3__) || defined(__NEC_V850_Fx3__) */

#if defined (__REL_V850_Dx4__)
#define Iodd_SetDdrBit(PortName,PinNumber,Value) \
        TARG_WriteBitInShort(PM ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, Value)
#define Iodd_SetInputBuffer(PortName,PinNumber,Value) \
        TARG_WriteBitInShort(PIBC ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, Value)
#endif /* __REL_V850_Dx4__ */

#define IODD_NO_OUT_SETUP(PortName,PinNumber)
#endif /* __NEC_V850__ */

#ifdef __MC9S12xx__
/* - ports with direction register - */

#define Iodd_WriteBitPortDirection(PortName,PinNumber,Value) \
        TARG_WriteBit(DDR ## PortName,PORT_BIT_DDR ## PortName ## PinNumber,Value)

#define PORT_DDR_PA(PortName,PinNumber,value) \
        Iodd_WriteBitPortDirection(PortName,PinNumber,value)

#define PORT_DDR_PB(PortName,PinNumber,value) \
        Iodd_WriteBitPortDirection(PortName,PinNumber,value)

#ifdef __MC9S12XHZ__

#define PORT_DDR_PC(PortName,PinNumber,value) \
        Iodd_WriteBitPortDirection(PortName,PinNumber,value)

#define PORT_DDR_PD(PortName,PinNumber,value) \
        Iodd_WriteBitPortDirection(PortName,PinNumber,value)

#endif /* __MC9S12XHZ__ */

#define PORT_DDR_PK(PortName,PinNumber,value) \
        Iodd_WriteBitPortDirection(PortName,PinNumber,value)

#define PORT_DDR_PT(PortName,PinNumber,value) \
        Iodd_WriteBitPortDirection(PortName,PinNumber,value)

#define PORT_DDR_PS(PortName,PinNumber,value) \
        Iodd_WriteBitPortDirection(PortName,PinNumber,value)

#define PORT_DDR_PM(PortName,PinNumber,value) \
        Iodd_WriteBitPortDirection(PortName,PinNumber,value)

#define PORT_DDR_PP(PortName,PinNumber,value) \
        Iodd_WriteBitPortDirection(PortName,PinNumber,value)

/* MC9S12-H variant */
#if defined(__MC9S12H__)

#define PORT_DDR_PL(PortName,PinNumber,value) \
        Iodd_WriteBitPortDirection(PortName,PinNumber,value)

#endif /* defined(__MC9S12H__) */

/* MC9S12-HZ and MC9S12XHZ variant */
#if (defined(__MC9S12HZ__) || defined(__MC9S12XHZ__))

#define PORT_DDR_PL(PortName,PinNumber,value) \
        Iodd_WriteBitPortDirection(PortName,PinNumber,value); \
        TARG_WriteBit(ATDDIEN0,ATD_BIT_IEN ## PinNumber, 1)

#endif /* (defined(__MC9S12HZ__) || defined(__MC9S12XHZ__)) */

#define PORT_DDR_PU(PortName,PinNumber,value) \
        Iodd_WriteBitPortDirection(PortName,PinNumber,value)

#define PORT_DDR_PV(PortName,PinNumber,value) \
        Iodd_WriteBitPortDirection(PortName,PinNumber,value)

/* MC9S12-H and MC9S12XHZ variant */
#if (defined(__MC9S12H__) || defined(__MC9S12XHZ__))

/* MC9S12-H variant */
#ifdef __MC9S12H__

#define PORT_DDR_PH(PortName,PinNumber,value) \
        Iodd_WriteBitPortDirection(PortName,PinNumber,value)

#define PORT_DDR_PJ(PortName,PinNumber,value) \
        Iodd_WriteBitPortDirection(PortName,PinNumber,value)

#endif /* __MC9S12H__ */

#define PORT_DDR_PW(PortName,PinNumber,value) \
        Iodd_WriteBitPortDirection(PortName,PinNumber,value)

#endif /* (defined(__MC9S12H__) || defined(__MC9S12XHZ__)) */

/* MC9S12-HZ and MC9S12XHZ variant */
#if (defined(__MC9S12HZ__) || defined(__MC9S12XHZ__))

/*  In pin setup we use ports name 0 and 1 to be compliant with S12H */
/*  For S12HZ analog port ATD1 = I/O port AD (PORTAD = PORT1)        */

/* used when pin only used as digital input (no analog input used) */
/* port name : AD */
#define PORT_DDR_PAD(PortName,PinNumber,value) \
        Iodd_WriteBitPortDirection(PortName,PinNumber,value); \
        TARG_WriteBit(ATDDIEN1,ATD_BIT_IEN ## PinNumber, 1)

/* used when pin used both as digital input and as analog input */
/* port name : 1 */
#define PORT_DDR_P1(PortName,PinNumber,value) \
        PORT_DDR_PAD(AD,PinNumber,value)

#endif /* (defined(__MC9S12HZ__) || defined(__MC9S12XHZ__)) */


/* - ports with some pins only in input - */

#define PORT_DDR_PE0(PortName,PinNumber,value)
#define PORT_DDR_PE1(PortName,PinNumber,value)

#define PORT_DDR_PE2(PortName,PinNumber,value) \
        Iodd_WriteBitPortDirection(PortName,PinNumber,value)

#define PORT_DDR_PE3(PortName,PinNumber,value) \
        Iodd_WriteBitPortDirection(PortName,PinNumber,value)

#define PORT_DDR_PE4(PortName,PinNumber,value) \
        Iodd_WriteBitPortDirection(PortName,PinNumber,value)

#define PORT_DDR_PE5(PortName,PinNumber,value) \
        Iodd_WriteBitPortDirection(PortName,PinNumber,value)

#define PORT_DDR_PE6(PortName,PinNumber,value) \
        Iodd_WriteBitPortDirection(PortName,PinNumber,value)

#define PORT_DDR_PE7(PortName,PinNumber,value) \
        Iodd_WriteBitPortDirection(PortName,PinNumber,value)

#define PORT_DDR_PE(PortName,PinNumber,value) \
        PORT_DDR_PE ## PinNumber(PortName,PinNumber,value)


/* - ports without direction register - */

/* MC9S12-H variant */
#if defined(__MC9S12H__)

#define PORT_DDR_P0(PortName,PinNumber,value) \
        TARG_WriteBit(ATDDIEN ## PortName,ATD_BIT_IEN ## PinNumber, 1)

#define PORT_DDR_P1(PortName,PinNumber,value) \
        TARG_WriteBit(ATDDIEN ## PortName,ATD_BIT_IEN ## PinNumber, 1)

#endif /* defined(__MC9S12H__) */


#define Iodd_SetDdrBit(PortName,PinNumber,value) \
        PORT_DDR_P ## PortName(PortName,PinNumber,value)
#endif /* __MC9S12xx__ */

#ifdef __MC9S08xx__
/* - ports with direction register - */
#define Iodd_SetDdrBit(PortName,PinNumber,Value) \
        PORT_DDR_P ## PortName(PinNumber,Value)

#define Iodd_WriteBitPortDirection(PortName,PinNumber,Value) \
        PORT_DDR_P ##PortName (PinNumber,Value)

#define PORT_DDR_PA(PinNumber,Value) \
        TARG_WriteBit(PTADD,PORT_BIT_PTADD ## PinNumber,Value)

#define PORT_DDR_PB(PinNumber,Value) \
        TARG_WriteBit(PTBDD,PORT_BIT_PTBDD ## PinNumber,Value)

#define PORT_DDR_PC(PinNumber,Value) \
        TARG_WriteBit(PTCDD,PORT_BIT_PTCDD ## PinNumber,Value)

#define PORT_DDR_PD(PinNumber,Value) \
        TARG_WriteBit(PTDDD,PORT_BIT_PTDDD ## PinNumber,Value)

#define PORT_DDR_PE(PinNumber,Value) \
        TARG_WriteBit(PTEDD,PORT_BIT_PTEDD ## PinNumber,Value)

#define PORT_DDR_PF(PinNumber,Value) \
        TARG_WriteBit(PTFDD,PORT_BIT_PTFDD ## PinNumber,Value)

#define PORT_DDR_PG(PinNumber,Value) \
        TARG_WriteBit(PTGDD,PORT_BIT_PTGDD ## PinNumber,Value)

#define PORT_DDR_PIRQ(PinNumber,Value)\
        /*NO I/O direction for IRQ pin*/

#endif /* __MC9S08xx__ */


/* Get one bit in a port input register ------------------------------------- */

#ifdef __MC9S12xx__
/* MEBI */
#define PORT_IN_PA(PortName,PinNumber) \
        TARG_ReadBit(PORT ## PortName,PORT_BIT_PORT ## PortName ## PinNumber)

#define PORT_IN_PB(PortName,PinNumber) \
        TARG_ReadBit(PORT ## PortName,PORT_BIT_PORT ## PortName ## PinNumber)

#ifdef __MC9S12XHZ__

#define PORT_IN_PC(PortName,PinNumber) \
        TARG_ReadBit(PORT ## PortName,PORT_BIT_PORT ## PortName ## PinNumber)

#define PORT_IN_PD(PortName,PinNumber) \
        TARG_ReadBit(PORT ## PortName,PORT_BIT_PORT ## PortName ## PinNumber)

#endif /* __MC9S12XHZ__ */

#define PORT_IN_PE(PortName,PinNumber) \
        TARG_ReadBit(PORT ## PortName,PORT_BIT_PORT ## PortName ## PinNumber)

#define PORT_IN_PK(PortName,PinNumber) \
        TARG_ReadBit(PORT ## PortName,PORT_BIT_PORT ## PortName ## PinNumber)

/* PIM */
#define PORT_IN_PT(PortName,PinNumber) \
        TARG_ReadBit(PT ## PortName,PORT_BIT_PT ## PortName ## PinNumber)

#define PORT_IN_PS(PortName,PinNumber) \
        TARG_ReadBit(PT ## PortName,PORT_BIT_PT ## PortName ## PinNumber)

#define PORT_IN_PM(PortName,PinNumber) \
        TARG_ReadBit(PT ## PortName,PORT_BIT_PT ## PortName ## PinNumber)

#define PORT_IN_PP(PortName,PinNumber) \
        TARG_ReadBit(PT ## PortName,PORT_BIT_PT ## PortName ## PinNumber)

#define PORT_IN_PL(PortName,PinNumber) \
        TARG_ReadBit(PT ## PortName,PORT_BIT_PT ## PortName ## PinNumber)

#define PORT_IN_PU(PortName,PinNumber) \
        TARG_ReadBit(PT ## PortName,PORT_BIT_PT ## PortName ## PinNumber)

#define PORT_IN_PV(PortName,PinNumber) \
        TARG_ReadBit(PT ## PortName,PORT_BIT_PT ## PortName ## PinNumber)

/* MC9S12-H and MC9S12XHZ variant */
#if (defined(__MC9S12H__) || defined(__MC9S12XHZ__))

#ifdef __MC9S12H__

#define PORT_IN_PH(PortName,PinNumber) \
        TARG_ReadBit(PT ## PortName,PORT_BIT_PT ## PortName ## PinNumber)

#define PORT_IN_PJ(PortName,PinNumber) \
        TARG_ReadBit(PT ## PortName,PORT_BIT_PT ## PortName ## PinNumber)

#endif /* __MC9S12H__ */

#define PORT_IN_PW(PortName,PinNumber) \
        TARG_ReadBit(PT ## PortName,PORT_BIT_PT ## PortName ## PinNumber)

#endif /* (defined(__MC9S12H__) || defined(__MC9S12XHZ__)) */

/* ATD */
/* MC9S12-H variant */
#if defined(__MC9S12H__)

#define PORT_IN_P0(PortName,PinNumber) \
        TARG_ReadBit(PORTAD ## PortName,ATD_BIT_PTAD ## PinNumber)

#endif /* defined(__MC9S12H__) */

/*  In pin setup we use ports name 0 and 1 to be compliant with S12H */
/*  For S12HZ analog port ATD1 = I/O port AD (PORTAD = PORT1)        */

/* used when pin used both as digital input and as analog input */
/* port name : 1 */

#define PORT_IN_P1(PortName,PinNumber) \
        TARG_ReadBit(PORTAD ## PortName,ATD_BIT_PTAD ## PinNumber)

/* MC9S12-HZ and MC9S12XHZ variant */
#if (defined(__MC9S12HZ__) || defined(__MC9S12XHZ__))

/* used when pin only used as digital input (no analog input used) */
/* port name : AD */
#define PORT_IN_PAD(PortName,PinNumber) \
        TARG_ReadBit(PT ## PortName,PORT_BIT_PT ## PortName ## PinNumber)

#endif /* (defined(__MC9S12HZ__) || defined(__MC9S12XHZ__)) */

#define Iodd_GetInputReg(PortName,PinNumber) \
        PORT_IN_P ## PortName(PortName,PinNumber)
#endif /* __MC9S12xx__ */


/* Get one bit in a port input register on S08------------------------------- */

#ifdef __MC9S08xx__
#define Iodd_GetInputReg(PortName,PinNumber) \
        PORT_IN_P##PortName(PinNumber)

#define PORT_IN_PA(PinNumber) \
        TARG_ReadBit(PTAD , PORT_BIT_PTAD ## PinNumber)

#define PORT_IN_PB(PinNumber) \
        TARG_ReadBit(PTBD , PORT_BIT_PTBD ## PinNumber)

#define PORT_IN_PC(PinNumber) \
        TARG_ReadBit(PTCD , PORT_BIT_PTCD ## PinNumber)

#define PORT_IN_PD(PinNumber) \
        TARG_ReadBit(PTDD , PORT_BIT_PTDD ## PinNumber)

#define PORT_IN_PE(PinNumber) \
        TARG_ReadBit(PTED , PORT_BIT_PTED ## PinNumber)

#define PORT_IN_PF(PinNumber) \
        TARG_ReadBit(PTFD , PORT_BIT_PTFD ## PinNumber)

#define PORT_IN_PG(PinNumber) \
        TARG_ReadBit(PTGD , PORT_BIT_PTGD ## PinNumber)
#endif /* __MC9S08xx__ */


#ifdef __MC9S12xx__
/* Set one bit in a port output register ------------------------------------ */

/* MEBI */
#define PORT_OUT_PA(PortName,PinNumber,State) \
        TARG_WriteBit(PORT ## PortName,PORT_BIT_PORT ## PortName ## PinNumber,State)

#define PORT_OUT_PB(PortName,PinNumber,State) \
        TARG_WriteBit(PORT ## PortName,PORT_BIT_PORT ## PortName ## PinNumber,State)

#ifdef __MC9S12XHZ__

#define PORT_OUT_PC(PortName,PinNumber,State) \
        TARG_WriteBit(PORT ## PortName,PORT_BIT_PORT ## PortName ## PinNumber,State)

#define PORT_OUT_PD(PortName,PinNumber,State) \
        TARG_WriteBit(PORT ## PortName,PORT_BIT_PORT ## PortName ## PinNumber,State)

#endif /* __MC9S12XHZ__ */

#define PORT_OUT_PE(PortName,PinNumber,State) \
        TARG_WriteBit(PORT ## PortName,PORT_BIT_PORT ## PortName ## PinNumber,State)

#define PORT_OUT_PK(PortName,PinNumber,State) \
        TARG_WriteBit(PORT ## PortName,PORT_BIT_PORT ## PortName ## PinNumber,State)

/* PIM */
#define PORT_OUT_PT(PortName,PinNumber,State) \
        TARG_WriteBit(PT ## PortName,PORT_BIT_PT ## PortName ## PinNumber,State)

#define PORT_OUT_PS(PortName,PinNumber,State) \
        TARG_WriteBit(PT ## PortName,PORT_BIT_PT ## PortName ## PinNumber,State)

#define PORT_OUT_PM(PortName,PinNumber,State) \
        TARG_WriteBit(PT ## PortName,PORT_BIT_PT ## PortName ## PinNumber,State)

#define PORT_OUT_PP(PortName,PinNumber,State) \
        TARG_WriteBit(PT ## PortName,PORT_BIT_PT ## PortName ## PinNumber,State)

#define PORT_OUT_PL(PortName,PinNumber,State) \
        TARG_WriteBit(PT ## PortName,PORT_BIT_PT ## PortName ## PinNumber,State)

#define PORT_OUT_PU(PortName,PinNumber,State) \
        TARG_WriteBit(PT ## PortName,PORT_BIT_PT ## PortName ## PinNumber,State)

#define PORT_OUT_PV(PortName,PinNumber,State) \
        TARG_WriteBit(PT ## PortName,PORT_BIT_PT ## PortName ## PinNumber,State)

/* MC9S12-H and MC9S12XHZ variant */
#if (defined(__MC9S12H__) || defined(__MC9S12XHZ__))

#ifdef __MC9S12H__

#define PORT_OUT_PH(PortName,PinNumber,State) \
        TARG_WriteBit(PT ## PortName,PORT_BIT_PT ## PortName ## PinNumber,State)

#define PORT_OUT_PJ(PortName,PinNumber,State) \
        TARG_WriteBit(PT ## PortName,PORT_BIT_PT ## PortName ## PinNumber,State)

#endif /* __MC9S12H__ */

#define PORT_OUT_PW(PortName,PinNumber,State) \
        TARG_WriteBit(PT ## PortName,PORT_BIT_PT ## PortName ## PinNumber,State)

#endif /* (defined(__MC9S12H__) || defined(__MC9S12XHZ__)) */

/* ATD */

/* MC9S12-HZ and MC9S12XHZ variant */
#if (defined(__MC9S12HZ__) || defined(__MC9S12XHZ__))

/*  In pin setup we use ports name 0 and 1 to be compliant with S12H */
/*  For S12HZ analog port ATD1 = I/O port AD (PORTAD = PORT1)        */

/* used when pin only used as digital input (no analog input used) */
/* port name : AD */
#define PORT_OUT_PAD(PortName,PinNumber,State) \
        TARG_WriteBit(PT ## PortName,PORT_BIT_PT ## PortName ## PinNumber,State)

#endif /* (defined(__MC9S12HZ__) || defined(__MC9S12XHZ__)) */


#define Iodd_SetOutputReg(PortName,PinNumber,State) \
        PORT_OUT_P ## PortName(PortName,PinNumber,State)
#endif /* __MC9S12xx__ */


#ifdef __MC9S08xx__
/* Set one bit in a port output register ------------------------------------ */
#define Iodd_SetOutputReg(PortName,PinNumber,State) \
        PORT_OUT_P ## PortName(PinNumber,State)

#define PORT_OUT_PA(PinNumber,State) \
        TARG_WriteBit(PTAD,PORT_BIT_PTAD ## PinNumber,State)

#define PORT_OUT_PB(PinNumber,State) \
        TARG_WriteBit(PTBD,PORT_BIT_PTBD ## PinNumber,State)

#define PORT_OUT_PC(PinNumber,State) \
        TARG_WriteBit(PTCD,PORT_BIT_PTCD ## PinNumber,State)

#define PORT_OUT_PD(PinNumber,State) \
        TARG_WriteBit(PTDD,PORT_BIT_PTDD ## PinNumber,State)

#define PORT_OUT_PE(PinNumber,State) \
        TARG_WriteBit(PTED,PORT_BIT_PTED ## PinNumber,State)

#define PORT_OUT_PF(PinNumber,State) \
        TARG_WriteBit(PTFD,PORT_BIT_PTFD ## PinNumber,State)

#define PORT_OUT_PG(PinNumber,State) \
        TARG_WriteBit(PTGD,PORT_BIT_PTGD ## PinNumber,State)
#endif /* __MC9S08xx__ */


#ifdef __NEC_V850__
/* Set one bit in a port output register ------------------------------------ */
#if defined (__NEC_V850_Dx3__) || defined(__NEC_V850_Fx3__)
#define Iodd_WREGS_P(PortName,PinNumber,Value) \
        Iodd_WREG_P_ ## PortName ## PinNumber(Value)
#endif /* (__NEC_V850_Dx3__) || defined(__NEC_V850_Fx3__) */

#if defined (__REL_V850_Dx4__)
#define Iodd_WREGS_P(PortName,PinNumber,Value) \
        TARG_WriteBitInShort(P ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, Value)
#endif /* __REL_V850_Dx4__ */

#define Iodd_SetOutputReg(PortName,PinNumber,State) \
        Iodd_WREGS_P(PortName,PinNumber,State)
#endif /* __NEC_V850__ */


/* Get one port status bit -------------------------------------------------- */

#ifdef __MC9S12xx__
#define PORT_PIN_PT(PortName,PinNumber) \
        TARG_ReadBit(PTI ## PortName,PORT_BIT_PT ## PortName ## PinNumber)

#define PORT_PIN_PS(PortName,PinNumber) \
        TARG_ReadBit(PTI ## PortName,PORT_BIT_PT ## PortName ## PinNumber)

#define PORT_PIN_PM(PortName,PinNumber) \
        TARG_ReadBit(PTI ## PortName,PORT_BIT_PT ## PortName ## PinNumber)

#define PORT_PIN_PP(PortName,PinNumber) \
        TARG_ReadBit(PTI ## PortName,PORT_BIT_PT ## PortName ## PinNumber)

#define PORT_PIN_PL(PortName,PinNumber) \
        TARG_ReadBit(PTI ## PortName,PORT_BIT_PT ## PortName ## PinNumber)

#define PORT_PIN_PU(PortName,PinNumber) \
        TARG_ReadBit(PTI ## PortName,PORT_BIT_PT ## PortName ## PinNumber)

#define PORT_PIN_PV(PortName,PinNumber) \
        TARG_ReadBit(PTI ## PortName,PORT_BIT_PT ## PortName ## PinNumber)

/* MC9S12-H and MC9S12XHZ variant */
#if (defined(__MC9S12H__) || defined(__MC9S12XHZ__))

#ifdef __MC9S12H__

#define PORT_PIN_PH(PortName,PinNumber) \
        TARG_ReadBit(PTI ## PortName,PORT_BIT_PT ## PortName ## PinNumber)

#define PORT_PIN_PJ(PortName,PinNumber) \
        TARG_ReadBit(PTI ## PortName,PORT_BIT_PT ## PortName ## PinNumber)

#endif /* __MC9S12H__ */

#define PORT_PIN_PW(PortName,PinNumber) \
        TARG_ReadBit(PTI ## PortName,PORT_BIT_PT ## PortName ## PinNumber)

#endif /* (defined(__MC9S12H__) || defined(__MC9S12XHZ__)) */

/* MC9S12-HZ and MC9S12XHZ variant */
#if (defined(__MC9S12HZ__) || defined(__MC9S12XHZ__))

/*  In pin setup we use ports name 0 and 1 to be compliant with S12H */
/*  For S12HZ analog port ATD1 = I/O port AD (PORTAD = PORT1)        */

/* used when pin only used as digital input (no analog input used) */
/* port name : AD */
#define PORT_PIN_PAD(PortName,PinNumber) \
        TARG_ReadBit(PTI ## PortName,PORT_BIT_PT ## PortName ## PinNumber)

/* used when pin used as digital input and as analog input */
/* port name : 1 */
#define PORT_PIN_P1(PortName,PinNumber)  PORT_PIN_PAD(AD,PinNumber)

#endif /* (defined(__MC9S12HZ__) || defined(__MC9S12XHZ__)) */


#define Iodd_GetPinState(PortName,PinNumber) \
        PORT_PIN_P ## PortName(PortName,PinNumber)
#endif /* __MC9S12xx__ */


#ifdef __MC9S08xx__
/* Do not exist on S08 */

/*#define Iodd_GetPinState(PortName,PinNumber) \    */
/*        PORT_PIN_P ## PortName(PortName,PinNumber)*/
#endif /* __MC9S08xx__ */


#ifdef __NEC_V850__
#if defined (__NEC_V850_Dx3__) || defined(__NEC_V850_Fx3__)
#define Iodd_GetPinState(PortName,PinNumber) \
        Iodd_RREG_PR_ ## PortName ## PinNumber
#endif /* (__NEC_V850_Dx3__) || defined(__NEC_V850_Fx3__) */

#if defined (__REL_V850_Dx4__)
#define Iodd_GetPinState(PortName,PinNumber) \
        TARG_ReadBitInShort(PPR ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber)
#endif /* __REL_V850_Dx4__ */
#endif /* __NEC_V850__ */


/*______ G L O B A L - M A C R O S ___________________________________________*/

/*----------------------------------------------------------------------------*/
/* Name : IODD_PinSetUpInput                                                  */
/* Role : Set up a microcontroler pin to work as an input                     */
/* Interface :                                                                */
/*   - PortName    IN, name of port for :                                     */
/*                                        Motorola STAR12H                    */
/*                                       [0,1,A,B,E,K,T,S,M,P,H,J,L,U,V,W]    */
/*                                        note : 0 and 1 are ATD port         */
/*                                        Motorola STAR12HZ                   */
/*                                       [AD,A,B,E,K,T,S,M,P,L,U,V]           */
/*                                        Freescale MC9S12XHZ                 */
/*                                       [AD,A,B,C,D,E,K,T,S,M,P,L,U,V,W]     */
/*  In pin setup we use ports name 0 and 1 to be compliant with S12H          */
/*  For S12HZ AND S12XHZ analog port ATD1 = I/O port AD (PORTAD = PORT1)      */
/*  used when pin only used as digital input (no analog input used)           */
/*  port name : AD                                                            */
/*  used when pin used both as digital input and as analog input              */
/*  port name : 1                                                             */
/*                                        NEC V850 Fx3                        */
/*                                 [0,1,2,3,4,5,6,7,8,9,12,15,CD,CM,CS,CT,DL] */
/*                                        NEC V850 Dx3                        */
/*                                    [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15] */
/*                                        REL V850 Dx4                        */
/*                                    [0,1,2,3,4,5,6,7,8,9,10,16,17,J0]       */
/*                                                                            */
/*   - PinNumber   IN, number of the selected pin [0..7]                      */
/*                     NOTE : for Motorola STAR12 port 0 and 1 -> port ATD    */
/*                            port 0 : PinNumber [8..15]                      */
/*                            port 1 : PinNumber [0..7]                       */
/*                     NOTE : for TX49, use macros GPIO_PIN_PinName           */
/*                                                                            */
/*   - PinMode     IN, use mode of the pin                                    */
/*                                        NEC V850 Fx3                        */
/*                                         [IODD_STANDARD,                    */
/*                                          IODD_IT_RISING_EDGE,              */
/*                                          IODD_IT_FALLING_EDGE,             */
/*                                          IODD_IT_BOTH_EDGE]                */
/*                                        Motorola STAR12                     */
/*                                         [IODD_STANDARD,                    */
/*                                          IODD_IT_RISING_EDGE,              */
/*                                          IODD_IT_FALLING_EDGE]             */
/*                                        Motorola S08                        */
/*                                         [IODD_STANDARD,                    */
/*                                          IODD_IT_RISING_EDGE,              */
/*                                          IODD_IT_FALLING_EDGE,             */
/*                                          IODD_IT_LOW_LEVEL,                */
/*                                          IODD_IT_HIGH_LEVEL]               */
/*                                        NEC V850 Dx3                        */
/*                                         [IODD_STANDARD,                    */
/*                                          IODD_IT_RISING_EDGE,              */
/*                                          IODD_IT_FALLING_EDGE,             */
/*                                          IODD_IT_BOTH_EDGE,                */
/*                                          IODD_IT_LOW_LEVEL,                */
/*                                          IODD_IT_HIGH_LEVEL]               */
/*                                        REL V850 Dx4                        */
/*                                         [IODD_STANDARD,                    */
/*                                          IODD_IT_RISING_EDGE,              */
/*                                          IODD_IT_FALLING_EDGE,             */
/*                                          IODD_IT_BOTH_EDGE,                */
/*                                          IODD_IT_LOW_LEVEL,                */
/*                                          IODD_IT_HIGH_LEVEL]               */
/*   - PullUpState IN, state of the pull-up on the pin if the pin has         */
/*                     a pull-up                                              */
/*                                        NEC V850 Fx3                        */
/*                                         [IODD_PULL_UP,                     */
/*                                          IODD_NO_PULL_UP]                  */
/*                                        Motorola STAR12                     */
/*                                         [IODD_PULL_UP,                     */
/*                                          IODD_PULL_DOWN,                   */
/*                                          IODD_NO_PULL_UP]                  */
/*                                        NEC V850 Dx3                        */
/*                                         [IODD_NO_PULL_UP                   */
/*                                          IODD_SCHMITT_03_07Vdd,            */
/*                                          IODD_SCHMITT_04_08Vdd,            */
/*                                          IODD_CMOS_03_07Vdd,               */
/*                                          IODD_CMOS_04_08Vdd]               */
/*                                        REL V850 Dx4                        */
/*                                         [IODD_PULL_UP,                     */
/*                                          IODD_NO_PULL_UP]                  */
/* Pre-condition : -                                                          */
/* Constraints : -                                                            */
/* Behavior :                                                                 */
/*   DO                                                                       */
/*     [set up the pin as requested]                                          */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/

#ifdef __MC9S12xx__
#define IODD_PinSetUpInput(PortName,\
                           PinNumber,\
                           PinMode,\
                           PullUpState) \
        Iodd_SetDdrBit(PortName,PinNumber,0);\
        PullUpState(PortName,PinNumber);\
        PinMode(PortName,PortName,PinNumber)
#endif /* __MC9S12xx__ */

#ifdef __MC9S08xx__
#define IODD_PinSetUpInput(PortName,\
                           PinNumber,\
                           PinMode,\
                           PullUpState) \
        Iodd_SetDdrBit(PortName,PinNumber,0);\
        PullUpState(PortName,PinNumber);\
        PinMode(PortName,PortName,PinNumber)
#endif /* __MC9S08xx__ */

#ifdef __NEC_V850__
#ifndef __REL_V850_Dx4__
#define IODD_PinSetUpInput(PortName,\
                           PinNumber,\
                           PinMode,\
                           PullUpState) \
        Iodd_SetDdrBit(PortName,PinNumber,1);\
        PinMode(PortName,PinNumber);\
        PullUpState(PortName,PinNumber)
#else
#define IODD_PinSetUpInput(PortName,\
                           PinNumber,\
                           PinMode,\
                           PullUpState) \
        Iodd_SetDdrBit(PortName,PinNumber,1);\
        PinMode(PortName,PinNumber);\
        PullUpState(PortName,PinNumber);\
        Iodd_SetInputBuffer(PortName,PinNumber,1)
#define IODD_PinSetUpExtIntWakeup(PortName,\
                                  PinNumber,\
                                  IntSource,\
                                  DectionType,\
                                  PinMode) \
        PinMode(PortName,PinNumber);\
        IODD_PORT_FILTER_FUNC(IntSource,DectionType)
#endif /* __REL_V850_Dx4__ */
#endif /* __NEC_V850__ */


/*----------------------------------------------------------------------------*/
/* Name : IODD_SetPinDirectionIn                                              */
/* Role : Set direction register to set pin in input                          */
/* Interface :                                                                */
/*   - PortName    IN, name of port for :                                     */
/*                                        Motorola STAR12H                    */
/*                                       [A,B,E,K,T,S,M,P,H,J,L,U,V,W]        */
/*                                        Motorola STAR12HZ                   */
/*                                       [AD,A,B,E,K,T,S,M,P,L,U,V]           */
/*                                        Freescale MC9S12XHZ                 */
/*                                       [AD,A,B,C,D,E,K,T,S,M,P,L,U,V,W]     */
/*  In pin setup we use ports name 0 and 1 to be compliant with S12H          */
/*  For S12HZ and S12XHZ analog port ATD1 = I/O port AD (PORTAD = PORT1)      */
/*  used when pin only used as digital input (no analog input used)           */
/*  port name : AD                                                            */
/*  used when pin used both as digital input and as analog input              */
/*  port name : 1                                                             */
/*                                        NEC V850 Fx3                        */
/*                                 [0,1,2,3,4,5,6,7,8,9,12,15,CD,CM,CS,CT,DL] */
/*                                        NEC V850 Dx3                        */
/*                                    [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15] */
/*                                        REL V850 Dx4                        */
/*                                    [0,1,2,3,4,10,16,17,J0]                 */
/*                                                                            */
/*   - PinNumber   IN, number of the selected pin [0..7]                      */
/* Pre-condition : -                                                          */
/* Constraints : -                                                            */
/* Behavior :                                                                 */
/*   DO                                                                       */
/*     [set up the pin as requested]                                          */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/

#ifdef __MC9S12xx__
#define IODD_SetPinDirectionIn(PortName,\
                               PinNumber) \
        Iodd_SetDdrBit(PortName,PinNumber,0)
#endif /* __MC9S12xx__ */

#ifdef __MC9S08xx__
#define IODD_SetPinDirectionIn(PortName,\
                               PinNumber) \
        Iodd_SetDdrBit(PortName,PinNumber,0)
#endif /* __MC9S08xx__ */

#ifdef __NEC_V850__
#define IODD_SetPinDirectionIn(PortName,\
                               PinNumber) \
        Iodd_SetDdrBit(PortName,PinNumber,1)
#endif /* __NEC_V850__ */


/*----------------------------------------------------------------------------*/
/* Name : IODD_SetPinDirectionOut                                             */
/* Role : Set direction register to set pin in output                         */
/* Interface :                                                                */
/*   - PortName    IN, name of port for :                                     */
/*                                        Motorola STAR12H                    */
/*                                       [A,B,E,K,T,S,M,P,H,J,L,U,V,W]        */
/*                                        Motorola STAR12HZ                   */
/*                                       [AD,A,B,E,K,T,S,M,P,L,U,V]           */
/*                                        Freescale MC9S12XHZ                 */
/*                                       [AD,A,B,C,D,E,K,T,S,M,P,L,U,V,W]     */
/*  For S12HZ and S12XHZ analog port ATD1 = I/O port AD (PORTAD = PORT1)      */
/*  used when pin only used as digital input (no analog input used)           */
/*  port name : AD                                                            */
/*                                        NEC V850 Fx3                        */
/*                                 [0,1,2,3,4,5,6,7,8,9,12,15,CD,CM,CS,CT,DL] */
/*                                        NEC V850 Dx3                        */
/*                                    [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15] */
/*                                        REL V850 Dx4                        */
/*                                    [0,1,2,3,4,10,16,17,J0]                 */
/*                                                                            */
/*   - PinNumber   IN, number of the selected pin [0..7]                      */
/* Pre-condition : -                                                          */
/* Constraints : -                                                            */
/* Behavior :                                                                 */
/*   DO                                                                       */
/*     [set up the pin as requested]                                          */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/
#ifdef __MC9S12xx__
#define IODD_SetPinDirectionOut(PortName,\
                                PinNumber) \
        Iodd_SetDdrBit(PortName,PinNumber,1)
#endif /* __MC9S12xx__ */

#ifdef __MC9S08xx__
#define IODD_SetPinDirectionOut(PortName,\
                                PinNumber) \
        Iodd_SetDdrBit(PortName,PinNumber,1)
#endif /* __MC9S08xx__ */

#ifdef __NEC_V850__
#define IODD_SetPinDirectionOut(PortName,\
                               PinNumber) \
        Iodd_SetDdrBit(PortName,PinNumber,0)
#endif /* __NEC_V850__ */


/*----------------------------------------------------------------------------*/
/*Name : IODD_SetPullUpData                                                   */
/*Role : Set the pull-up state                                                */
/*Interface :                                                                 */
/*  - PortName  IN, name of port for :                                        */
/*                                    Motorola STAR12H                        */
/*                                    [A,B,E,K,T,S,M,P,H,J,L,U,V,W]           */
/*                                    Motorola STAR12HZ                       */
/*                                    [AD,A,B,E,K,T,S,M,P,L,U,V]              */
/*                                    Freescale MC9S12XHZ                     */
/*                                    [AD,A,B,C,D,E,K,T,S,M,P,L,U,V,W]        */
/*  In pin setup we use ports name 0 and 1 to be compliant with S12H          */
/*  For S12HZ and S12XHZ analog port ATD1 = I/O port AD (PORTAD = PORT1)      */
/*  used when pin only used as digital input (no analog input used)           */
/*  port name : AD                                                            */
/*  used when pin used both as digital input and as analog input              */
/*  port name : 1                                                             */
/*                                                                            */
/*                                    NEC V850 Fx3                            */
/*                                 [0,1,2,3,4,5,6,7,8,9,12,15,CD,CM,CS,CT,DL] */
/*                                    NEC V850 Dx3                            */
/*                                    [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15] */
/*                                        REL V850 Dx4                        */
/*                                    [0,1,2,3,4,10,16,17,J0]                 */
/*  - PinNumber IN, number of the selected pin  [0..7]                        */
/*Pre-condition : -                                                           */
/*Constraints :  -                                                            */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [set the pull-up state]                                                 */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#define IODD_SetPullUpData(PortName,PinNumber) \
        Iodd_SetPullUpBit(PortName,PinNumber)


/*----------------------------------------------------------------------------*/
/*Name : IODD_SetPullDownData                                                 */
/*Role : Set the pull-down state                                              */
/*Interface :                                                                 */
/*  - PortName  IN, name of port for :                                        */
/*                                    Motorola STAR12H                        */
/*                                    [T,S,M,P,H,J,L,U,V,W]                   */
/*                                    Motorola STAR12HZ                       */
/*                                    [AD,T,S,M,P,L,U,V]                      */
/*                                    Freescale MC9S12XHZ                     */
/*                                    [AD,T,S,M,P,L,U,V,W]                    */
/*  In pin setup we use ports name 0 and 1 to be compliant with S12H          */
/*  For S12HZ S12XHZ analog port ATD1 = I/O port AD (PORTAD = PORT1)          */
/*  used when pin only used as digital input (no analog input used)           */
/*  port name : AD                                                            */
/*  used when pin used both as digital input and as analog input              */
/*  port name : 1                                                             */
/*                                                                            */
/*                                    NEC V850 Fx3                            */
/*                                 [0,1,2,3,4,5,6,7,8,9,12,15,CD,CM,CS,CT,DL] */
/*                                    NEC V850 Dx3                            */
/*                                    [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15] */
/*                                        REL V850 Dx4                        */
/*                                    [0,1,2,3,4,10,16,17,J0]                 */
/*  - PinNumber IN, number of the selected pin  [0..7]                        */
/*Pre-condition : -                                                           */
/*Constraints :  -                                                            */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [set the pull-up state]                                                 */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#define IODD_SetPullDownData(PortName,PinNumber) \
        Iodd_SetPullDownBit(PortName,PinNumber)


/*----------------------------------------------------------------------------*/
/* Name : IODD_EnableIrq                                                      */
/* Role : Enable interrupt request                                            */
/* Interface :                                                                */
/*   - IrqName IN, name of Irq for :                                          */
/*                                 Motorola STAR12H                           */
/*                                 [IODD_IRQ0  -> IRQ pin                     */
/*                                 IODD_IRQ1  -> KWH0 pin                     */
/*                                 ...                                        */
/*                                 IODD_IRQ8  -> KWH7 pin                     */
/*                                 IODD_IRQ9  -> KWJ0 pin                     */
/*                                 ...                                        */
/*                                 IODD_IRQ12 -> KWJ3 pin]                    */
/*                                 Motorola STAR12HZ                          */
/*                                 [IODD_IRQ0  -> IRQ pin                     */
/*                                  IODD_IRQ1  -> KW(1)AD0 pin                */
/*                                  ...                                       */
/*                                  IODD_IRQ8  -> KW(1)AD7 pin]               */
/*                                 note : 1 is ATD port                       */
/*                                 Freescale MC9S12XHZ                        */
/*                                 [IODD_IRQ0  -> IRQ pin                     */
/*                                  IODD_IRQ1  -> KW(1)AD0 pin                */
/*                                  ...                                       */
/*                                  IODD_IRQ8  -> KW(1)AD7 pin]               */
/*                                 note : 1 is ATD port                       */
/*  In pin setup we use ports name 0 and 1 to be compliant with S12H          */
/*  For S12HZ and S12XHZ analog port ATD1 = I/O port AD (PORTAD = PORT1)      */
/*  used when pin only used as digital input (no analog input used)           */
/*  port name : AD                                                            */
/*  used when pin used both as digital input and as analog input              */
/*  port name : 1                                                             */
/*                                 NEC V850 Fx3                               */
/*                                 [IODD_IRQ0  -> IRQ pin INTP0               */
/*                                  IODD_IRQ1  -> IRQ pin INTP1               */
/*                                  ...                                       */
/*                                  IODD_IRQ15 -> IRQ pin INTP15]             */
/*                                 NEC V850 Dx3                               */
/*                                 [IODD_IRQ0  -> IRQ pin INTP0               */
/*                                  IODD_IRQ1  -> IRQ pin INTP1               */
/*                                  ...                                       */
/*                                  IODD_IRQ7 -> IRQ pin INTP7]               */
/*                                 REL V850 Dx4                               */
/*                                 [IODD_IRQ0  -> IRQ pin INTP0               */
/*                                  IODD_IRQ1  -> IRQ pin INTP1               */
/*                                  ...                                       */
/*                                  IODD_IRQ10 -> IRQ pin INTP10]             */
/*                                                                            */
/* Pre-condition : -                                                          */
/* Constraints : -                                                            */
/* Behavior :                                                                 */
/*   DO                                                                       */
/*     [enable interrupt requested]                                           */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/
#define IODD_EnableIrq(IrqName) IODD_EnableIrq_ ## IrqName

#ifdef __MC9S12xx__
#define IODD_EnableIrq_IODD_IRQ0  TARG_WriteBit(IRQCR,PORT_BIT_IRQEN,1)

/* MC9S12-H variant */
#if defined(__MC9S12H__)

#define IODD_EnableIrq_IODD_IRQ1  TARG_WriteBit(PIEH,PORT_BIT_PIEH0,1)
#define IODD_EnableIrq_IODD_IRQ2  TARG_WriteBit(PIEH,PORT_BIT_PIEH1,1)
#define IODD_EnableIrq_IODD_IRQ3  TARG_WriteBit(PIEH,PORT_BIT_PIEH2,1)
#define IODD_EnableIrq_IODD_IRQ4  TARG_WriteBit(PIEH,PORT_BIT_PIEH3,1)
#define IODD_EnableIrq_IODD_IRQ5  TARG_WriteBit(PIEH,PORT_BIT_PIEH4,1)
#define IODD_EnableIrq_IODD_IRQ6  TARG_WriteBit(PIEH,PORT_BIT_PIEH5,1)
#define IODD_EnableIrq_IODD_IRQ7  TARG_WriteBit(PIEH,PORT_BIT_PIEH6,1)
#define IODD_EnableIrq_IODD_IRQ8  TARG_WriteBit(PIEH,PORT_BIT_PIEH7,1)

#define IODD_EnableIrq_IODD_IRQ9  TARG_WriteBit(PIEJ,PORT_BIT_PIEJ0,1)
#define IODD_EnableIrq_IODD_IRQ10 TARG_WriteBit(PIEJ,PORT_BIT_PIEJ1,1)
#define IODD_EnableIrq_IODD_IRQ11 TARG_WriteBit(PIEJ,PORT_BIT_PIEJ2,1)
#define IODD_EnableIrq_IODD_IRQ12 TARG_WriteBit(PIEJ,PORT_BIT_PIEJ3,1)

#endif /* defined(__MC9S12H__) */

/* MC9S12-HZ and MC9s12XHZ variant */
#if (defined(__MC9S12HZ__) || defined(__MC9S12XHZ__))

#define IODD_EnableIrq_IODD_IRQ1  TARG_WriteBit(PIEAD,PORT_BIT_PIEAD0,1)
#define IODD_EnableIrq_IODD_IRQ2  TARG_WriteBit(PIEAD,PORT_BIT_PIEAD1,1)
#define IODD_EnableIrq_IODD_IRQ3  TARG_WriteBit(PIEAD,PORT_BIT_PIEAD2,1)
#define IODD_EnableIrq_IODD_IRQ4  TARG_WriteBit(PIEAD,PORT_BIT_PIEAD3,1)
#define IODD_EnableIrq_IODD_IRQ5  TARG_WriteBit(PIEAD,PORT_BIT_PIEAD4,1)
#define IODD_EnableIrq_IODD_IRQ6  TARG_WriteBit(PIEAD,PORT_BIT_PIEAD5,1)
#define IODD_EnableIrq_IODD_IRQ7  TARG_WriteBit(PIEAD,PORT_BIT_PIEAD6,1)
#define IODD_EnableIrq_IODD_IRQ8  TARG_WriteBit(PIEAD,PORT_BIT_PIEAD7,1)

#endif /* (defined(__MC9S12HZ__) || defined(__MC9S12XHZ__)) */

#endif /* __MC9S12xx__ */

#ifdef __MC9S08xx__

#define IODD_EnableIrq_IODD_IRQPIN  TARG_WriteBit(IRQSC,PORT_BIT_IRQPE, 1);\
                                    TARG_WriteBit(IRQSC,PORT_BIT_IRQACK,1);\
                                    TARG_WriteBit(IRQSC,PORT_BIT_IRQIE, 1)

#define IODD_EnableIrq_IODD_IRQ0    TARG_WriteBit(KBIPE,PORT_BIT_KBIPE0,1);\
                                    TARG_WriteBit(KBISC,PORT_BIT_KBIE,  1)
#define IODD_EnableIrq_IODD_IRQ1    TARG_WriteBit(KBIPE,PORT_BIT_KBIPE1,1);\
                                    TARG_WriteBit(KBISC,PORT_BIT_KBIE,  1)
#define IODD_EnableIrq_IODD_IRQ2    TARG_WriteBit(KBIPE,PORT_BIT_KBIPE2,1);\
                                    TARG_WriteBit(KBISC,PORT_BIT_KBIE,  1)
#define IODD_EnableIrq_IODD_IRQ3    TARG_WriteBit(KBIPE,PORT_BIT_KBIPE3,1);\
                                    TARG_WriteBit(KBISC,PORT_BIT_KBIE,  1)
#define IODD_EnableIrq_IODD_IRQ4    TARG_WriteBit(KBIPE,PORT_BIT_KBIPE4,1);\
                                    TARG_WriteBit(KBISC,PORT_BIT_KBIE,  1)
#define IODD_EnableIrq_IODD_IRQ5    TARG_WriteBit(KBIPE,PORT_BIT_KBIPE5,1);\
                                    TARG_WriteBit(KBISC,PORT_BIT_KBIE,  1)
#define IODD_EnableIrq_IODD_IRQ6    TARG_WriteBit(KBIPE,PORT_BIT_KBIPE6,1);\
                                    TARG_WriteBit(KBISC,PORT_BIT_KBIE,  1)
#define IODD_EnableIrq_IODD_IRQ7    TARG_WriteBit(KBIPE,PORT_BIT_KBIPE7,1);\
                                    TARG_WriteBit(KBISC,PORT_BIT_KBIE,  1)

#endif /* __MC9S08xx__ */

#ifdef __NEC_V850_Fx3__

#define IODD_EnableIrq_IODD_IRQ0        TARG_WriteBit(PIC0, BIT6,0)
#define IODD_EnableIrq_IODD_IRQ1        TARG_WriteBit(PIC1, BIT6,0)
#define IODD_EnableIrq_IODD_IRQ2        TARG_WriteBit(PIC2, BIT6,0)
#define IODD_EnableIrq_IODD_IRQ3        TARG_WriteBit(PIC3, BIT6,0)

#if defined(__NEC_V850_FJ3__) || \
    defined(__NEC_V850_FK3__)
#define IODD_EnableIrq_IODD_IRQ4        TARG_WriteBit(PIC4, BIT6,0)
#define IODD_EnableIrq_IODD_IRQ5        TARG_WriteBit(PIC5, BIT6,0)
#define IODD_EnableIrq_IODD_IRQ6        TARG_WriteBit(PIC6, BIT6,0)
#endif /* defined(__NEC_V850_FJ3__) ||
          defined(__NEC_V850_FK3__) */

#define IODD_EnableIrq_IODD_IRQ7        TARG_WriteBit(PIC7, BIT6,0)

#if defined(__NEC_V850_FG3__) || \
    defined(__NEC_V850_FJ3__) || \
    defined(__NEC_V850_FK3__)
#define IODD_EnableIrq_IODD_IRQ8        TARG_WriteBit(PIC8, BIT6,0)
#endif /* defined(__NEC_V850_FG3__) ||
          defined(__NEC_V850_FJ3__) ||
          defined(__NEC_V850_FK3__) */

#define IODD_EnableIrq_IODD_IRQ9        TARG_WriteBit(PIC9, BIT6,0)
#define IODD_EnableIrq_IODD_IRQ10       TARG_WriteBit(PIC10,BIT6,0)

#if defined(__NEC_V850_FJ3__) || \
    defined(__NEC_V850_FK3__)
#define IODD_EnableIrq_IODD_IRQ11       TARG_WriteBit(PIC11,BIT6,0)
#define IODD_EnableIrq_IODD_IRQ12       TARG_WriteBit(PIC12,BIT6,0)
#define IODD_EnableIrq_IODD_IRQ13       TARG_WriteBit(PIC13,BIT6,0)
#define IODD_EnableIrq_IODD_IRQ14       TARG_WriteBit(PIC14,BIT6,0)
#endif /* defined(__NEC_V850_FJ3__) ||
          defined(__NEC_V850_FK3__) */

#if defined(__NEC_V850_FK3__)
#define IODD_EnableIrq_IODD_IRQ15       TARG_WriteBit(PIC15,BIT6,0)
#endif /* defined(__NEC_V850_FK3__) */

#endif /* __NEC_V850_Fx3__ */

#if defined(__NEC_V850_Dx3__)
#define IODD_EnableIrq_IODD_IRQ0       TARG_WriteBit(P0IC,BIT6,0)
#define IODD_EnableIrq_IODD_IRQ1       TARG_WriteBit(P1IC,BIT6,0)
#define IODD_EnableIrq_IODD_IRQ2       TARG_WriteBit(P2IC,BIT6,0)
#define IODD_EnableIrq_IODD_IRQ3       TARG_WriteBit(P3IC,BIT6,0)

#ifndef __NEC_V850_DG3__
#define IODD_EnableIrq_IODD_IRQ4       TARG_WriteBit(P4IC,BIT6,0)
#define IODD_EnableIrq_IODD_IRQ5       TARG_WriteBit(P5IC,BIT6,0)
#define IODD_EnableIrq_IODD_IRQ6       TARG_WriteBit(P6IC,BIT6,0)
#endif  /* not __NEC_V850_DG3__ */

#if defined (__NEC_V850_DJ3_HE__) || defined (__NEC_V850_DL3__)
#define IODD_EnableIrq_IODD_IRQ7       TARG_WriteBit(P7IC,BIT6,0)
#endif  /* defined (__NEC_V850_DJ3_HE__) || defined (__NEC_V850_DL3__) */

#endif  /* __NEC_V850_Dx3__ */

#if defined(__REL_V850_Dx4__)
#define IODD_EnableIrq_IODD_IRQ0       TARG_WriteBit(ICP0L,BIT7,0)
#define IODD_EnableIrq_IODD_IRQ1       TARG_WriteBit(ICP1L,BIT7,0)
#define IODD_EnableIrq_IODD_IRQ2       TARG_WriteBit(ICP2L,BIT7,0)
#define IODD_EnableIrq_IODD_IRQ3       TARG_WriteBit(ICP3L,BIT7,0)
#define IODD_EnableIrq_IODD_IRQ4       TARG_WriteBit(ICP4L,BIT7,0)
#define IODD_EnableIrq_IODD_IRQ5       TARG_WriteBit(ICP5L,BIT7,0)
#define IODD_EnableIrq_IODD_IRQ6       TARG_WriteBit(ICP6L,BIT7,0)
#define IODD_EnableIrq_IODD_IRQ7       TARG_WriteBit(ICP7L,BIT7,0)
#define IODD_EnableIrq_IODD_IRQ8       TARG_WriteBit(ICP8L,BIT7,0)
#define IODD_EnableIrq_IODD_IRQ9       TARG_WriteBit(ICP9L,BIT7,0)
#define IODD_EnableIrq_IODD_IRQ10      TARG_WriteBit(ICP10L,BIT7,0)
#endif  /* __REL_V850_Dx4__ */


/*----------------------------------------------------------------------------*/
/* Name : IODD_DisableIrq                                                     */
/* Role : Disable interrupt request                                           */
/* Interface :                                                                */
/*   - IrqName IN, name of Irq for :                                          */
/*                                 Motorola STAR12H                           */
/*                                 [IODD_IRQ0  -> IRQ pin                     */
/*                                 IODD_IRQ1  -> KWH0 pin                     */
/*                                 ...                                        */
/*                                 IODD_IRQ8  -> KWH7 pin                     */
/*                                 IODD_IRQ9  -> KWJ0 pin                     */
/*                                 ...                                        */
/*                                 IODD_IRQ12 -> KWJ3 pin]                    */
/*                                 Motorola STAR12HZ                          */
/*                                 [IODD_IRQ0  -> IRQ pin                     */
/*                                  IODD_IRQ1  -> KW(1)AD0 pin                */
/*                                  ...                                       */
/*                                  IODD_IRQ8  -> KW(1)AD7 pin]               */
/*                                  note : 1 is ATD port                      */
/*                                 Freescale MC9S12XHZ                        */
/*                                 [IODD_IRQ0  -> IRQ pin                     */
/*                                  IODD_IRQ1  -> KW(1)AD0 pin                */
/*                                  ...                                       */
/*                                  IODD_IRQ8  -> KW(1)AD7 pin]               */
/*                                 note : 1 is ATD port                       */
/*  In pin setup we use ports name 0 and 1 to be compliant with S12H          */
/*  For S12HZ S12XHZ analog port ATD1 = I/O port AD (PORTAD = PORT1)          */
/*  used when pin only used as digital input (no analog input used)           */
/*  port name : AD                                                            */
/*  used when pin used both as digital input and as analog input              */
/*  port name : 1                                                             */
/*                                 NEC V850 Fx3                               */
/*                                 [IODD_IRQ0  -> IRQ pin INTP0               */
/*                                  IODD_IRQ1  -> IRQ pin INTP1               */
/*                                  ...                                       */
/*                                  IODD_IRQ15 -> IRQ pin INTP15]             */
/*                                 NEC V850 Dx3                               */
/*                                 [IODD_IRQ0  -> IRQ pin INTP0               */
/*                                  IODD_IRQ1  -> IRQ pin INTP1               */
/*                                  ...                                       */
/*                                  IODD_IRQ7 -> IRQ pin INTP7]               */
/*                                 REL V850 Dx4                               */
/*                                 [IODD_IRQ0  -> IRQ pin INTP0               */
/*                                  IODD_IRQ1  -> IRQ pin INTP1               */
/*                                  ...                                       */
/*                                  IODD_IRQ10 -> IRQ pin INTP10]             */
/*                                                                            */
/* Pre-condition : -                                                          */
/* Constraints : -                                                            */
/* Behavior :                                                                 */
/*   DO                                                                       */
/*     [disable interrupt requested]                                          */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/
#define IODD_DisableIrq(IrqName) IODD_DisableIrq_ ## IrqName

#ifdef __MC9S12xx__
#define IODD_DisableIrq_IODD_IRQ0  TARG_WriteBit(IRQCR,PORT_BIT_IRQEN,0)

/* MC9S12-H variant */
#if defined(__MC9S12H__)

#define IODD_DisableIrq_IODD_IRQ1  TARG_WriteBit(PIEH,PORT_BIT_PIEH0,0)
#define IODD_DisableIrq_IODD_IRQ2  TARG_WriteBit(PIEH,PORT_BIT_PIEH1,0)
#define IODD_DisableIrq_IODD_IRQ3  TARG_WriteBit(PIEH,PORT_BIT_PIEH2,0)
#define IODD_DisableIrq_IODD_IRQ4  TARG_WriteBit(PIEH,PORT_BIT_PIEH3,0)
#define IODD_DisableIrq_IODD_IRQ5  TARG_WriteBit(PIEH,PORT_BIT_PIEH4,0)
#define IODD_DisableIrq_IODD_IRQ6  TARG_WriteBit(PIEH,PORT_BIT_PIEH5,0)
#define IODD_DisableIrq_IODD_IRQ7  TARG_WriteBit(PIEH,PORT_BIT_PIEH6,0)
#define IODD_DisableIrq_IODD_IRQ8  TARG_WriteBit(PIEH,PORT_BIT_PIEH7,0)

#define IODD_DisableIrq_IODD_IRQ9  TARG_WriteBit(PIEJ,PORT_BIT_PIEJ0,0)
#define IODD_DisableIrq_IODD_IRQ10 TARG_WriteBit(PIEJ,PORT_BIT_PIEJ1,0)
#define IODD_DisableIrq_IODD_IRQ11 TARG_WriteBit(PIEJ,PORT_BIT_PIEJ2,0)
#define IODD_DisableIrq_IODD_IRQ12 TARG_WriteBit(PIEJ,PORT_BIT_PIEJ3,0)

#endif /* defined(__MC9S12H__) */

/* MC9S12-HZ and MC9S12XHZ variant */
#if (defined(__MC9S12HZ__) || defined(__MC9S12XHZ__))

#define IODD_DisableIrq_IODD_IRQ1  TARG_WriteBit(PIEAD,PORT_BIT_PIEAD0,0)
#define IODD_DisableIrq_IODD_IRQ2  TARG_WriteBit(PIEAD,PORT_BIT_PIEAD1,0)
#define IODD_DisableIrq_IODD_IRQ3  TARG_WriteBit(PIEAD,PORT_BIT_PIEAD2,0)
#define IODD_DisableIrq_IODD_IRQ4  TARG_WriteBit(PIEAD,PORT_BIT_PIEAD3,0)
#define IODD_DisableIrq_IODD_IRQ5  TARG_WriteBit(PIEAD,PORT_BIT_PIEAD4,0)
#define IODD_DisableIrq_IODD_IRQ6  TARG_WriteBit(PIEAD,PORT_BIT_PIEAD5,0)
#define IODD_DisableIrq_IODD_IRQ7  TARG_WriteBit(PIEAD,PORT_BIT_PIEAD6,0)
#define IODD_DisableIrq_IODD_IRQ8  TARG_WriteBit(PIEAD,PORT_BIT_PIEAD7,0)

#endif /* (defined(__MC9S12HZ__) || defined(__MC9S12XHZ__)) */

#endif /* __MC9S12xx__ */

#ifdef __MC9S08xx__
#define IODD_DisableIrq_IODD_IRQPIN  TARG_WriteBit(IRQSC,PORT_BIT_IRQPE, 0);\
                                     TARG_WriteBit(IRQSC,PORT_BIT_IRQIE, 0)

#define IODD_DisableIrq_IODD_IRQ0  TARG_WriteBit(KBIPE,PORT_BIT_KBIPE0, 0);\
                                   TARG_WriteBit(KBISC,PORT_BIT_KBIE,   0)
#define IODD_DisableIrq_IODD_IRQ1  TARG_WriteBit(KBIPE,PORT_BIT_KBIPE0, 0);\
                                   TARG_WriteBit(KBISC,PORT_BIT_KBIE,   0)
#define IODD_DisableIrq_IODD_IRQ2  TARG_WriteBit(KBIPE,PORT_BIT_KBIPE2, 0);\
                                   TARG_WriteBit(KBISC,PORT_BIT_KBIE,   0)
#define IODD_DisableIrq_IODD_IRQ3  TARG_WriteBit(KBIPE,PORT_BIT_KBIPE3, 0);\
                                   TARG_WriteBit(KBISC,PORT_BIT_KBIE,   0)
#define IODD_DisableIrq_IODD_IRQ4  TARG_WriteBit(KBIPE,PORT_BIT_KBIPE4, 0);\
                                   TARG_WriteBit(KBISC,PORT_BIT_KBIE,   0)
#define IODD_DisableIrq_IODD_IRQ5  TARG_WriteBit(KBIPE,PORT_BIT_KBIPE5, 0);\
                                   TARG_WriteBit(KBISC,PORT_BIT_KBIE,   0)
#define IODD_DisableIrq_IODD_IRQ6  TARG_WriteBit(KBIPE,PORT_BIT_KBIPE6, 0);\
                                   TARG_WriteBit(KBISC,PORT_BIT_KBIE,   0)
#define IODD_DisableIrq_IODD_IRQ7  TARG_WriteBit(KBIPE,PORT_BIT_KBIPE7, 0);\
                                   TARG_WriteBit(KBISC,PORT_BIT_KBIE,   0)

#endif /* __MC9S08xx__ */

#ifdef __NEC_V850_Fx3__

#define IODD_DisableIrq_IODD_IRQ0       TARG_WriteBit(PIC0, BIT6,1)
#define IODD_DisableIrq_IODD_IRQ1       TARG_WriteBit(PIC1, BIT6,1)
#define IODD_DisableIrq_IODD_IRQ2       TARG_WriteBit(PIC2, BIT6,1)
#define IODD_DisableIrq_IODD_IRQ3       TARG_WriteBit(PIC3, BIT6,1)

#if defined(__NEC_V850_FJ3__) || \
    defined(__NEC_V850_FK3__)
#define IODD_DisableIrq_IODD_IRQ4       TARG_WriteBit(PIC4, BIT6,1)
#define IODD_DisableIrq_IODD_IRQ5       TARG_WriteBit(PIC5, BIT6,1)
#define IODD_DisableIrq_IODD_IRQ6       TARG_WriteBit(PIC6, BIT6,1)
#endif /* defined(__NEC_V850_FJ3__) ||
          defined(__NEC_V850_FK3__) */

#define IODD_DisableIrq_IODD_IRQ7       TARG_WriteBit(PIC7, BIT6,1)

#if defined(__NEC_V850_FG3__) || \
    defined(__NEC_V850_FJ3__) || \
    defined(__NEC_V850_FK3__)
#define IODD_DisableIrq_IODD_IRQ8       TARG_WriteBit(PIC8, BIT6,1)
#endif /* defined(__NEC_V850_FG3__) ||
          defined(__NEC_V850_FJ3__) ||
          defined(__NEC_V850_FK3__) */
#define IODD_DisableIrq_IODD_IRQ9       TARG_WriteBit(PIC9, BIT6,1)
#define IODD_DisableIrq_IODD_IRQ10      TARG_WriteBit(PIC10,BIT6,1)

#if defined(__NEC_V850_FJ3__) || \
    defined(__NEC_V850_FK3__)
#define IODD_DisableIrq_IODD_IRQ11      TARG_WriteBit(PIC11,BIT6,1)
#define IODD_DisableIrq_IODD_IRQ12      TARG_WriteBit(PIC12,BIT6,1)
#define IODD_DisableIrq_IODD_IRQ13      TARG_WriteBit(PIC13,BIT6,1)
#define IODD_DisableIrq_IODD_IRQ14      TARG_WriteBit(PIC14,BIT6,1)
#endif /* defined(__NEC_V850_FJ3__) ||
          defined(__NEC_V850_FK3__) */

#if defined(__NEC_V850_FK3__)
#define IODD_DisableIrq_IODD_IRQ15      TARG_WriteBit(PIC15,BIT6,1)
#endif /* defined(__NEC_V850_FK3__) */

#endif /* __NEC_V850_Fx3__ */

#if defined(__NEC_V850_Dx3__)

#define IODD_DisableIrq_IODD_IRQ0      TARG_WriteBit(P0IC,BIT6,1)
#define IODD_DisableIrq_IODD_IRQ1      TARG_WriteBit(P1IC,BIT6,1)
#define IODD_DisableIrq_IODD_IRQ2      TARG_WriteBit(P2IC,BIT6,1)
#define IODD_DisableIrq_IODD_IRQ3      TARG_WriteBit(P3IC,BIT6,1)

#ifndef __NEC_V850_DG3__
#define IODD_DisableIrq_IODD_IRQ4      TARG_WriteBit(P4IC,BIT6,1)
#define IODD_DisableIrq_IODD_IRQ5      TARG_WriteBit(P5IC,BIT6,1)
#define IODD_DisableIrq_IODD_IRQ6      TARG_WriteBit(P6IC,BIT6,1)
#endif  /* __NEC_V850_DG3__ */

#if defined (__NEC_V850_DJ3_HE__) || defined (__NEC_V850_DL3__)
#define IODD_DisableIrq_IODD_IRQ7      TARG_WriteBit(P7IC,BIT6,1)
#endif  /* defined (__NEC_V850_DJ3_HE__) || defined (__NEC_V850_DL3__) */

#endif  /* __NEC_V850_Dx3__ */

#if defined(__REL_V850_Dx4__)
#define IODD_DisableIrq_IODD_IRQ0      TARG_WriteBit(ICP0L,BIT7,1)
#define IODD_DisableIrq_IODD_IRQ1      TARG_WriteBit(ICP1L,BIT7,1)
#define IODD_DisableIrq_IODD_IRQ2      TARG_WriteBit(ICP2L,BIT7,1)
#define IODD_DisableIrq_IODD_IRQ3      TARG_WriteBit(ICP3L,BIT7,1)
#define IODD_DisableIrq_IODD_IRQ4      TARG_WriteBit(ICP4L,BIT7,1)
#define IODD_DisableIrq_IODD_IRQ5      TARG_WriteBit(ICP5L,BIT7,1)
#define IODD_DisableIrq_IODD_IRQ6      TARG_WriteBit(ICP6L,BIT7,1)
#define IODD_DisableIrq_IODD_IRQ7      TARG_WriteBit(ICP7L,BIT7,1)
#define IODD_DisableIrq_IODD_IRQ8      TARG_WriteBit(ICP8L,BIT7,1)
#define IODD_DisableIrq_IODD_IRQ9      TARG_WriteBit(ICP9L,BIT7,1)
#define IODD_DisableIrq_IODD_IRQ10     TARG_WriteBit(ICP10L,BIT7,1)
#endif  /* __REL_V850_Dx4__ */


/*----------------------------------------------------------------------------*/
/* Name : IODD_ReadStatusIrq                                                  */
/* Role : Read interrupt request flag                                         */
/* Interface :                                                                */
/*   - IrqName IN, name of Irq for :                                          */
/*                                 Motorola STAR12H                           */
/*                                 [IODD_IRQ1  -> KWH0 pin                    */
/*                                 ...                                        */
/*                                 IODD_IRQ8  -> KWH7 pin                     */
/*                                 IODD_IRQ9  -> KWJ0 pin                     */
/*                                 ...                                        */
/*                                 IODD_IRQ12 -> KWJ3 pin]                    */
/*                                 Motorola STAR12HZ                          */
/*                                 [IODD_IRQ0  -> IRQ pin                     */
/*                                  IODD_IRQ1  -> KW(1)AD0 pin                */
/*                                 ...                                        */
/*                                  IODD_IRQ8  -> KW(1)AD7 pin]               */
/*                                 note : 1 is ATD port                       */
/*                                 Freescale MC9S12XHZ                        */
/*                                 [IODD_IRQ0  -> IRQ pin                     */
/*                                  IODD_IRQ1  -> KW(1)AD0 pin                */
/*                                  ...                                       */
/*                                  IODD_IRQ8  -> KW(1)AD7 pin]               */
/*                                 note : 1 is ATD port                       */
/*  In pin setup we use ports name 0 and 1 to be compliant with S12H          */
/*  For S12HZ and S12XHZ analog port ATD1 = I/O port AD (PORTAD = PORT1)      */
/*  used when pin only used as digital input (no analog input used)           */
/*  port name : AD                                                            */
/*  used when pin used both as digital input and as analog input              */
/*  port name : 1                                                             */
/*                                 NEC V850 Fx3                               */
/*                                 [IODD_IRQ0  -> IRQ pin INTP0               */
/*                                  IODD_IRQ1  -> IRQ pin INTP1               */
/*                                  ...                                       */
/*                                  IODD_IRQ15 -> IRQ pin INTP15]             */
/*                                 NEC V850 Dx3                               */
/*                                 [IODD_IRQ0  -> IRQ pin INTP0               */
/*                                  IODD_IRQ1  -> IRQ pin INTP1               */
/*                                  ...                                       */
/*                                  IODD_IRQ7 -> IRQ pin INTP7]               */
/*                                 REL V850 Dx4                               */
/*                                 [IODD_IRQ0  -> IRQ pin INTP0               */
/*                                  IODD_IRQ1  -> IRQ pin INTP1               */
/*                                  ...                                       */
/*                                  IODD_IRQ10 -> IRQ pin INTP10]             */
/*                                                                            */
/* Pre-condition : -                                                          */
/* Constraints : -                                                            */
/* Behavior :                                                                 */
/*   DO                                                                       */
/*     [read the interrupt status]                                            */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/
#define IODD_ReadStatusIrq(IrqName) IODD_ReadStatusIrq_ ## IrqName

#ifdef __MC9S12xx__
#define IODD_ReadStatusIrq_IODD_IRQ0  /* none */

/* MC9S12-H variant */
#if defined(__MC9S12H__)

#define IODD_ReadStatusIrq_IODD_IRQ1  TARG_ReadBit(PIFH,PORT_BIT_PIFH0)
#define IODD_ReadStatusIrq_IODD_IRQ2  TARG_ReadBit(PIFH,PORT_BIT_PIFH1)
#define IODD_ReadStatusIrq_IODD_IRQ3  TARG_ReadBit(PIFH,PORT_BIT_PIFH2)
#define IODD_ReadStatusIrq_IODD_IRQ4  TARG_ReadBit(PIFH,PORT_BIT_PIFH3)
#define IODD_ReadStatusIrq_IODD_IRQ5  TARG_ReadBit(PIFH,PORT_BIT_PIFH4)
#define IODD_ReadStatusIrq_IODD_IRQ6  TARG_ReadBit(PIFH,PORT_BIT_PIFH5)
#define IODD_ReadStatusIrq_IODD_IRQ7  TARG_ReadBit(PIFH,PORT_BIT_PIFH6)
#define IODD_ReadStatusIrq_IODD_IRQ8  TARG_ReadBit(PIFH,PORT_BIT_PIFH7)

#define IODD_ReadStatusIrq_IODD_IRQ9  TARG_ReadBit(PIFJ,PORT_BIT_PIFJ0)
#define IODD_ReadStatusIrq_IODD_IRQ10 TARG_ReadBit(PIFJ,PORT_BIT_PIFJ1)
#define IODD_ReadStatusIrq_IODD_IRQ11 TARG_ReadBit(PIFJ,PORT_BIT_PIFJ2)
#define IODD_ReadStatusIrq_IODD_IRQ12 TARG_ReadBit(PIFJ,PORT_BIT_PIFJ3)

#endif /* defined(__MC9S12H__) */

/* MC9S12-HZ and S12XHZ variant */
#if (defined(__MC9S12HZ__) || defined(__MC9S12XHZ__))

#define IODD_ReadStatusIrq_IODD_IRQ1  TARG_ReadBit(PIFAD,PORT_BIT_PIFAD0)
#define IODD_ReadStatusIrq_IODD_IRQ2  TARG_ReadBit(PIFAD,PORT_BIT_PIFAD1)
#define IODD_ReadStatusIrq_IODD_IRQ3  TARG_ReadBit(PIFAD,PORT_BIT_PIFAD2)
#define IODD_ReadStatusIrq_IODD_IRQ4  TARG_ReadBit(PIFAD,PORT_BIT_PIFAD3)
#define IODD_ReadStatusIrq_IODD_IRQ5  TARG_ReadBit(PIFAD,PORT_BIT_PIFAD4)
#define IODD_ReadStatusIrq_IODD_IRQ6  TARG_ReadBit(PIFAD,PORT_BIT_PIFAD5)
#define IODD_ReadStatusIrq_IODD_IRQ7  TARG_ReadBit(PIFAD,PORT_BIT_PIFAD6)
#define IODD_ReadStatusIrq_IODD_IRQ8  TARG_ReadBit(PIFAD,PORT_BIT_PIFAD7)

#endif /* (defined(__MC9S12HZ__) || defined(__MC9S12XHZ__)) */

#endif /* __MC9S12xx__ */

#ifdef __MC9S08xx__
#define IODD_ReadStatusIrq_IODD_IRQPIN  TARG_ReadBit(IRQSC,PORT_BIT_IRQF)

/* Only 1 flag for all KBI pins */
#define IODD_ReadStatusIrq_IODD_IRQ0  TARG_ReadBit(KBISC,PORT_BIT_KBF)
#define IODD_ReadStatusIrq_IODD_IRQ1  TARG_ReadBit(KBISC,PORT_BIT_KBF)
#define IODD_ReadStatusIrq_IODD_IRQ2  TARG_ReadBit(KBISC,PORT_BIT_KBF)
#define IODD_ReadStatusIrq_IODD_IRQ3  TARG_ReadBit(KBISC,PORT_BIT_KBF)
#define IODD_ReadStatusIrq_IODD_IRQ4  TARG_ReadBit(KBISC,PORT_BIT_KBF)
#define IODD_ReadStatusIrq_IODD_IRQ5  TARG_ReadBit(KBISC,PORT_BIT_KBF)
#define IODD_ReadStatusIrq_IODD_IRQ6  TARG_ReadBit(KBISC,PORT_BIT_KBF)
#define IODD_ReadStatusIrq_IODD_IRQ7  TARG_ReadBit(KBISC,PORT_BIT_KBF)

#endif /* __MC9S08xx__ */

#ifdef __NEC_V850_Fx3__

#define IODD_ReadStatusIrq_IODD_IRQ0    TARG_ReadBit (PIC0, BIT7)
#define IODD_ReadStatusIrq_IODD_IRQ1    TARG_ReadBit (PIC1, BIT7)
#define IODD_ReadStatusIrq_IODD_IRQ2    TARG_ReadBit (PIC2, BIT7)
#define IODD_ReadStatusIrq_IODD_IRQ3    TARG_ReadBit (PIC3, BIT7)

#if defined(__NEC_V850_FJ3__) || \
    defined(__NEC_V850_FK3__)
#define IODD_ReadStatusIrq_IODD_IRQ4    TARG_ReadBit (PIC4, BIT7)
#define IODD_ReadStatusIrq_IODD_IRQ5    TARG_ReadBit (PIC5, BIT7)
#define IODD_ReadStatusIrq_IODD_IRQ6    TARG_ReadBit (PIC6, BIT7)
#endif /* defined(__NEC_V850_FJ3__) ||
          defined(__NEC_V850_FK3__) */

#define IODD_ReadStatusIrq_IODD_IRQ7    TARG_ReadBit (PIC7, BIT7)

#if defined(__NEC_V850_FG3__) || \
    defined(__NEC_V850_FJ3__) || \
    defined(__NEC_V850_FK3__)
#define IODD_ReadStatusIrq_IODD_IRQ8    TARG_ReadBit (PIC8, BIT7)
#endif /* defined(__NEC_V850_FG3__) ||
          defined(__NEC_V850_FJ3__) ||
          defined(__NEC_V850_FK3__) */

#define IODD_ReadStatusIrq_IODD_IRQ9    TARG_ReadBit (PIC9, BIT7)
#define IODD_ReadStatusIrq_IODD_IRQ10   TARG_ReadBit (PIC10,BIT7)

#if defined(__NEC_V850_FJ3__) || \
    defined(__NEC_V850_FK3__)
#define IODD_ReadStatusIrq_IODD_IRQ11   TARG_ReadBit (PIC11,BIT7)
#define IODD_ReadStatusIrq_IODD_IRQ12   TARG_ReadBit (PIC12,BIT7)
#define IODD_ReadStatusIrq_IODD_IRQ13   TARG_ReadBit (PIC13,BIT7)
#define IODD_ReadStatusIrq_IODD_IRQ14   TARG_ReadBit (PIC14,BIT7)
#endif /* defined(__NEC_V850_FJ3__) ||
          defined(__NEC_V850_FK3__) */

#if defined(__NEC_V850_FK3__)
#define IODD_ReadStatusIrq_IODD_IRQ15   TARG_ReadBit (PIC15,BIT7)
#endif /* defined(__NEC_V850_FK3__) */

#endif /* __NEC_V850_Fx3__ */

#if defined(__NEC_V850_Dx3__)

#define IODD_ReadStatusIrq_IODD_IRQ0   TARG_ReadBit (P0IC,BIT7)
#define IODD_ReadStatusIrq_IODD_IRQ1   TARG_ReadBit (P1IC,BIT7)
#define IODD_ReadStatusIrq_IODD_IRQ2   TARG_ReadBit (P2IC,BIT7)
#define IODD_ReadStatusIrq_IODD_IRQ3   TARG_ReadBit (P3IC,BIT7)

#ifndef __NEC_V850_DG3__
#define IODD_ReadStatusIrq_IODD_IRQ4   TARG_ReadBit (P4IC,BIT7)
#define IODD_ReadStatusIrq_IODD_IRQ5   TARG_ReadBit (P5IC,BIT7)
#define IODD_ReadStatusIrq_IODD_IRQ6   TARG_ReadBit (P6IC,BIT7)
#endif  /* __NEC_V850_DG3__ */

#if defined (__NEC_V850_DJ3_HE__) || defined (__NEC_V850_DL3__)
#define IODD_ReadStatusIrq_IODD_IRQ7   TARG_ReadBit (P7IC,BIT7)
#endif  /* defined (__NEC_V850_DJ3_HE__) || defined (__NEC_V850_DL3__) */

#endif  /* __NEC_V850_Dx3__ */

#if defined(__REL_V850_Dx4__)
#define IODD_ReadStatusIrq_IODD_IRQ0   TARG_ReadBit (ICP0H,BIT4)
#define IODD_ReadStatusIrq_IODD_IRQ1   TARG_ReadBit (ICP1H,BIT4)
#define IODD_ReadStatusIrq_IODD_IRQ2   TARG_ReadBit (ICP2H,BIT4)
#define IODD_ReadStatusIrq_IODD_IRQ3   TARG_ReadBit (ICP3H,BIT4)
#define IODD_ReadStatusIrq_IODD_IRQ4   TARG_ReadBit (ICP4H,BIT4)
#define IODD_ReadStatusIrq_IODD_IRQ5   TARG_ReadBit (ICP5H,BIT4)
#define IODD_ReadStatusIrq_IODD_IRQ6   TARG_ReadBit (ICP6H,BIT4)
#define IODD_ReadStatusIrq_IODD_IRQ7   TARG_ReadBit (ICP7H,BIT4)
#define IODD_ReadStatusIrq_IODD_IRQ8   TARG_ReadBit (ICP8H,BIT4)
#define IODD_ReadStatusIrq_IODD_IRQ9   TARG_ReadBit (ICP9H,BIT4)
#define IODD_ReadStatusIrq_IODD_IRQ10  TARG_ReadBit (ICP10H,BIT4)
#endif  /* __REL_V850_Dx4__ */


/*----------------------------------------------------------------------------*/
/* Name : IODD_ClearStatusIrq                                                 */
/* Role : Clear interrupt request flag                                        */
/* Interface :                                                                */
/*   - IrqName IN, name of Irq for :                                          */
/*                                 Motorola STAR12H                           */
/*                                 [IODD_IRQ1  -> KWH0 pin                    */
/*                                  ...                                       */
/*                                  IODD_IRQ8  -> KWH7 pin                    */
/*                                  IODD_IRQ9  -> KWJ0 pin                    */
/*                                  ...                                       */
/*                                  IODD_IRQ12 -> KWJ3 pin]                   */
/*                                 Motorola STAR12HZ                          */
/*                                 [IODD_IRQ0  -> IRQ pin                     */
/*                                  IODD_IRQ1  -> KW(1)AD0 pin                */
/*                                  ...                                       */
/*                                  IODD_IRQ8  -> KW(1)AD7 pin]               */
/*                                  note : 1 is ATD port                      */
/*                                 Freescale MC9S12XHZ                        */
/*                                 [IODD_IRQ0  -> IRQ pin                     */
/*                                  IODD_IRQ1  -> KW(1)AD0 pin                */
/*                                  ...                                       */
/*                                  IODD_IRQ8  -> KW(1)AD7 pin]               */
/*                                 note : 1 is ATD port                       */
/*  In pin setup we use ports name 0 and 1 to be compliant with S12H          */
/*  For S12HZ and S12XHZ analog port ATD1 = I/O port AD (PORTAD = PORT1)      */
/*  used when pin only used as digital input (no analog input used)           */
/*  port name : AD                                                            */
/*  used when pin used both as digital input and as analog input              */
/*  port name : 1                                                             */
/*                                 NEC V850 Fx3                               */
/*                                 [IODD_IRQ0  -> IRQ pin INTP0               */
/*                                  IODD_IRQ1  -> IRQ pin INTP1               */
/*                                  ...                                       */
/*                                  IODD_IRQ15 -> IRQ pin INTP15]             */
/*                                 NEC V850 Dx3                               */
/*                                 [IODD_IRQ0  -> IRQ pin INTP0               */
/*                                  IODD_IRQ1  -> IRQ pin INTP1               */
/*                                  ...                                       */
/*                                  IODD_IRQ7 -> IRQ pin INTP7]               */
/*                                 REL V850 Dx4                               */
/*                                 [IODD_IRQ0  -> IRQ pin INTP0               */
/*                                  IODD_IRQ1  -> IRQ pin INTP1               */
/*                                  ...                                       */
/*                                  IODD_IRQ10 -> IRQ pin INTP10]             */
/*                                                                            */
/* Pre-condition : -                                                          */
/* Constraints : -                                                            */
/* Behavior :                                                                 */
/*   DO                                                                       */
/*     [Clear the interrupt status]                                           */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/
#define IODD_ClearStatusIrq(IrqName) IODD_ClearStatusIrq_ ## IrqName

#ifdef __MC9S12xx__
#define IODD_ClearStatusIrq_IODD_IRQ0  /* none */

/* Clear flag by writing 1, 0 has no effect */

/* MC9S12-H variant */
#if defined(__MC9S12H__)

#define IODD_ClearStatusIrq_IODD_IRQ1  TARG_WriteByte(PIFH,PORT_MSK_PIFH0)
#define IODD_ClearStatusIrq_IODD_IRQ2  TARG_WriteByte(PIFH,PORT_MSK_PIFH1)
#define IODD_ClearStatusIrq_IODD_IRQ3  TARG_WriteByte(PIFH,PORT_MSK_PIFH2)
#define IODD_ClearStatusIrq_IODD_IRQ4  TARG_WriteByte(PIFH,PORT_MSK_PIFH3)
#define IODD_ClearStatusIrq_IODD_IRQ5  TARG_WriteByte(PIFH,PORT_MSK_PIFH4)
#define IODD_ClearStatusIrq_IODD_IRQ6  TARG_WriteByte(PIFH,PORT_MSK_PIFH5)
#define IODD_ClearStatusIrq_IODD_IRQ7  TARG_WriteByte(PIFH,PORT_MSK_PIFH6)
#define IODD_ClearStatusIrq_IODD_IRQ8  TARG_WriteByte(PIFH,PORT_MSK_PIFH7)

#define IODD_ClearStatusIrq_IODD_IRQ9  TARG_WriteByte(PIFJ,PORT_MSK_PIFJ0)
#define IODD_ClearStatusIrq_IODD_IRQ10 TARG_WriteByte(PIFJ,PORT_MSK_PIFJ1)
#define IODD_ClearStatusIrq_IODD_IRQ11 TARG_WriteByte(PIFJ,PORT_MSK_PIFJ2)
#define IODD_ClearStatusIrq_IODD_IRQ12 TARG_WriteByte(PIFJ,PORT_MSK_PIFJ3)

#endif /* defined(__MC9S12H__) */

/* MC9S12-HZ and MC9S12XHZ variant */
#if (defined(__MC9S12HZ__) || defined(__MC9S12XHZ__))

#define IODD_ClearStatusIrq_IODD_IRQ1  TARG_WriteByte(PIFAD,PORT_MSK_PIFAD0)
#define IODD_ClearStatusIrq_IODD_IRQ2  TARG_WriteByte(PIFAD,PORT_MSK_PIFAD1)
#define IODD_ClearStatusIrq_IODD_IRQ3  TARG_WriteByte(PIFAD,PORT_MSK_PIFAD2)
#define IODD_ClearStatusIrq_IODD_IRQ4  TARG_WriteByte(PIFAD,PORT_MSK_PIFAD3)
#define IODD_ClearStatusIrq_IODD_IRQ5  TARG_WriteByte(PIFAD,PORT_MSK_PIFAD4)
#define IODD_ClearStatusIrq_IODD_IRQ6  TARG_WriteByte(PIFAD,PORT_MSK_PIFAD5)
#define IODD_ClearStatusIrq_IODD_IRQ7  TARG_WriteByte(PIFAD,PORT_MSK_PIFAD6)
#define IODD_ClearStatusIrq_IODD_IRQ8  TARG_WriteByte(PIFAD,PORT_MSK_PIFAD7)

#endif /* (defined(__MC9S12HZ__) || defined(__MC9S12XHZ__)) */

#endif /* __MC9S12xx__ */

#ifdef __MC9S08xx__
#define IODD_ClearStatusIrq_IODD_IRQPIN TARG_WriteBit(IRQSC, PORT_BIT_IRQACK, 1)

/* Only 1 flag for all KBI pins */
#define IODD_ClearStatusIrq_IODD_IRQKBI TARG_WriteBit(KBISC, PORT_BIT_KBACK, 1)

#endif /* __MC9S08xx__ */

#ifdef __NEC_V850_Fx3__

#define IODD_ClearStatusIrq_IODD_IRQ0   TARG_WriteBit(PIC0, BIT7,0)
#define IODD_ClearStatusIrq_IODD_IRQ1   TARG_WriteBit(PIC1, BIT7,0)
#define IODD_ClearStatusIrq_IODD_IRQ2   TARG_WriteBit(PIC2, BIT7,0)
#define IODD_ClearStatusIrq_IODD_IRQ3   TARG_WriteBit(PIC3, BIT7,0)

#if defined(__NEC_V850_FJ3__) || \
    defined(__NEC_V850_FK3__)
#define IODD_ClearStatusIrq_IODD_IRQ4   TARG_WriteBit(PIC4, BIT7,0)
#define IODD_ClearStatusIrq_IODD_IRQ5   TARG_WriteBit(PIC5, BIT7,0)
#define IODD_ClearStatusIrq_IODD_IRQ6   TARG_WriteBit(PIC6, BIT7,0)
#endif /* defined(__NEC_V850_FJ3__) ||
          defined(__NEC_V850_FK3__) */

#define IODD_ClearStatusIrq_IODD_IRQ7   TARG_WriteBit(PIC7, BIT7,0)

#if defined(__NEC_V850_FG3__) || \
    defined(__NEC_V850_FJ3__) || \
    defined(__NEC_V850_FK3__)
#define IODD_ClearStatusIrq_IODD_IRQ8   TARG_WriteBit(PIC8, BIT7,0)
#endif /* defined(__NEC_V850_FG3__) ||
          defined(__NEC_V850_FJ3__) ||
          defined(__NEC_V850_FK3__) */

#define IODD_ClearStatusIrq_IODD_IRQ9   TARG_WriteBit(PIC9, BIT7,0)
#define IODD_ClearStatusIrq_IODD_IRQ10  TARG_WriteBit(PIC10,BIT7,0)

#if defined(__NEC_V850_FJ3__) || \
    defined(__NEC_V850_FK3__)
#define IODD_ClearStatusIrq_IODD_IRQ11  TARG_WriteBit(PIC11,BIT7,0)
#define IODD_ClearStatusIrq_IODD_IRQ12  TARG_WriteBit(PIC12,BIT7,0)
#define IODD_ClearStatusIrq_IODD_IRQ13  TARG_WriteBit(PIC13,BIT7,0)
#define IODD_ClearStatusIrq_IODD_IRQ14  TARG_WriteBit(PIC14,BIT7,0)
#endif /* defined(__NEC_V850_FJ3__) ||
          defined(__NEC_V850_FK3__) */

#if defined(__NEC_V850_FK3__)
#define IODD_ClearStatusIrq_IODD_IRQ15  TARG_WriteBit(PIC15,BIT7,0)
#endif /* defined(__NEC_V850_FK3__) */

#endif /* __NEC_V850_Fx3__ */

#if defined(__NEC_V850_Dx3__)

#define IODD_ClearStatusIrq_IODD_IRQ0  TARG_WriteBit(P0IC,BIT7,0)
#define IODD_ClearStatusIrq_IODD_IRQ1  TARG_WriteBit(P1IC,BIT7,0)
#define IODD_ClearStatusIrq_IODD_IRQ2  TARG_WriteBit(P2IC,BIT7,0)
#define IODD_ClearStatusIrq_IODD_IRQ3  TARG_WriteBit(P3IC,BIT7,0)

#ifndef __NEC_V850_DG3__
#define IODD_ClearStatusIrq_IODD_IRQ4  TARG_WriteBit(P4IC,BIT7,0)
#define IODD_ClearStatusIrq_IODD_IRQ5  TARG_WriteBit(P5IC,BIT7,0)
#define IODD_ClearStatusIrq_IODD_IRQ6  TARG_WriteBit(P6IC,BIT7,0)
#endif  /* __NEC_V850_DG3__ */

#if defined (__NEC_V850_DJ3_HE__) || defined (__NEC_V850_DL3__)
#define IODD_ClearStatusIrq_IODD_IRQ7  TARG_WriteBit(P7IC,BIT7,0)
#endif  /* defined (__NEC_V850_DJ3_HE__) || defined (__NEC_V850_DL3__) */

#endif  /* __NEC_V850_Dx3__     */

#if defined(__REL_V850_Dx4__)
#define IODD_ClearStatusIrq_IODD_IRQ0  TARG_WriteBit(ICP0H,BIT4,0)
#define IODD_ClearStatusIrq_IODD_IRQ1  TARG_WriteBit(ICP1H,BIT4,0)
#define IODD_ClearStatusIrq_IODD_IRQ2  TARG_WriteBit(ICP2H,BIT4,0)
#define IODD_ClearStatusIrq_IODD_IRQ3  TARG_WriteBit(ICP3H,BIT4,0)
#define IODD_ClearStatusIrq_IODD_IRQ4  TARG_WriteBit(ICP4H,BIT4,0)
#define IODD_ClearStatusIrq_IODD_IRQ5  TARG_WriteBit(ICP5H,BIT4,0)
#define IODD_ClearStatusIrq_IODD_IRQ6  TARG_WriteBit(ICP6H,BIT4,0)
#define IODD_ClearStatusIrq_IODD_IRQ7  TARG_WriteBit(ICP7H,BIT4,0)
#define IODD_ClearStatusIrq_IODD_IRQ8  TARG_WriteBit(ICP8H,BIT4,0)
#define IODD_ClearStatusIrq_IODD_IRQ9  TARG_WriteBit(ICP9H,BIT4,0)
#define IODD_ClearStatusIrq_IODD_IRQ10 TARG_WriteBit(ICP10H,BIT4,0)
#endif  /* __REL_V850_Dx4__     */


/*----------------------------------------------------------------------------*/
/*Name : IODD_PinSetUpOutput                                                  */
/*Role : Set up a microcontroler pin to work as an output                     */
/*Interface :                                                                 */
/*  - PortName       IN, name of port for :                                   */
/*                                    Motorola STAR12H                        */
/*                                    [A,B,E,K,T,S,M,P,H,J,L,U,V,W]           */
/*                                    Motorola STAR12HZ                       */
/*                                    [AD,A,B,E,K,T,S,M,P,L,U,V]              */
/*                                    Freescale MC9S12XHZ                     */
/*                                    [AD,A,B,C,D,E,K,T,S,M,P,L,U,V,W]        */
/*  For S12HZ and S12XHZ analog port ATD1 = I/O port AD (PORTAD = PORT1)      */
/*  used when pin only used as digital input (no analog input used)           */
/*  port name : AD                                                            */
/*                                    NEC V850 Fx3                            */
/*                                 [0,1,2,3,4,5,6,7,8,9,12,15,CD,CM,CS,CT,DL] */
/*                                    NEC V850 Dx3                            */
/*                                    [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15] */
/*                                    REL V850 Dx4                            */
/*                                    [0,1,2,3,4,5,6,7,8,9,10,16,17,J0]       */
/*                                                                            */
/*  - PinNumber      IN, number of the selected pin [0..7]                    */
/*  - OpenDrainState IN, for Freescale STAR12                                 */
/*                       [IODD_NO_OUT_SETUP                                   */
/*                        IODD_OPENDRAIN                                      */
/*                        IODD_SLEWRATE                                       */
/*                        IODD_REDUCED                                        */
/*                        IODD_OPENDRAIN_REDUCED                              */
/*                        IODD_OPENDRAIN_PULLUP                               */
/*                        IODD_OPENDRAIN_PULLDOWN                             */
/*                        IODD_OPENDRAIN_REDUCED_PULLUP                       */
/*                        IODD_OPENDRAIN_REDUCED_PULLDOWN]                    */
/*                       for Freescale S08                                    */
/*                       [IODD_NO_OUT_SETUP                                   */
/*                        IODD_SLEWRATE,                                      */
/*                        IODD_DRIVESTRENGTH]                                 */
/*                       for NEC V850 Fx3 :                                   */
/*                       [IODD_NO_HIGH_Z,                                     */
/*                        IODD_HIGH_Z,                                        */
/*                        IODD_NO_OPEN_DRAIN,                                 */
/*                        IODD_OPEN_DRAIN]                                    */
/*                        not applicable : does nothing                       */
/*                       for NEC V850 Dx3 :                                   */
/*                       [IODD_NO_OPEN_DRAIN                                  */
/*                        IODD_NO_OPEN_DRAIN_REDUCED                          */
/*                        IODD_OPEN_DRAIN                                     */
/*                        IODD_OPEN_DRAIN_REDUCED]                            */
/*                       for REL V850 Dx4 :                                   */
/*                       [IODD_NO_OPEN_DRAIN                                  */
/*                        IODD_NO_OPEN_DRAIN_REDUCED                          */
/*                        IODD_OPEN_DRAIN                                     */
/*                        IODD_OPEN_DRAIN_REDUCED]                            */
/*                                                                            */
/*Pre-condition : -                                                           */
/*Constraints :  -                                                            */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [set up the pin as requested]                                           */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#if (defined(__MC9S12xx__) || defined(__MC9S08xx__))
#define IODD_PinSetUpOutput(PortName,\
                            PinNumber,\
                            OpenDrainState) \
        Iodd_SetDdrBit(PortName,PinNumber,1);\
        OpenDrainState(PortName,PinNumber)
#endif /* (defined(__MC9S12xx__) || defined(__MC9S08xx__)) */

#ifdef __NEC_V850__
#define IODD_PinSetUpOutput(PortName,\
                            PinNumber,\
                            OpenDrainState) \
        Iodd_SetDdrBit(PortName,PinNumber,0);\
        OpenDrainState(PortName,PinNumber)
#endif /* __NEC_V850__ */


/*----------------------------------------------------------------------------*/
/*Name : IODD_SetOpenDrainData                                                */
/*Role : Set the open-drain state                                             */
/*Interface :                                                                 */
/*  - PortName  IN, name of port for :                                        */
/*                                    Freescale MC9S12XHZ                     */
/*                                    [AD,T,S,M,P]                            */
/*                                    NEC V850 Dx3                            */
/*                                    [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15] */
/*                                    REL V850 Dx4                            */
/*                                    [0,1,2,3,4,5,6,7,8,9,10,16,17,J0]       */
/*  - PinNumber IN, number of the selected pin  [0..7]                        */
/*  for Motorola STAR12 :                                                     */
/*  - State     IN, requested bit state [IODD_HIGH, IODD_LOW]                 */
/*                                                                            */
/*Pre-condition : -                                                           */
/*Constraints :  -                                                            */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [set the open-drain state]                                              */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#ifdef __MC9S12xx__
#define IODD_SetOpenDrainData(PortName,\
                              PinNumber,\
                              State) \
        Iodd_SetOpenDrainBit(PortName,PinNumber,State)
#endif /* __MC9S12xx__ */

#ifdef __NEC_V850_Fx3__
#define IODD_SetOpenDrainData(PortName,PinNumber)
#endif /* __NEC_V850_Fx3__ */

#ifdef __NEC_V850_Dx3__
#define IODD_SetOpenDrainData(PortName,PinNumber) \
        IODD_OPEN_DRAIN(PortName,PinNumber)
#endif /* __NEC_V850_Dx3__ */

#ifdef __REL_V850_Dx4__
#define IODD_SetOpenDrainData(PortName,PinNumber) \
        IODD_OPEN_DRAIN(PortName,PinNumber)
#endif /* __REL_V850_Dx4__ */


/*----------------------------------------------------------------------------*/
/*Name : IODD_GetPinStatus                                                    */
/*Role : Get the status of the pin                                            */
/*Interface :                                                                 */
/*  - PortName  IN, name of port for                                          */
/*                                    Motorola STAR12H                        */
/*                                    [T,S,M,P,H,J,L,U,V,W]                   */
/*                                    Motorola STAR12HZ                       */
/*                                    [AD,T,S,M,P,L,U,V]                      */
/*                                    Freescale MC9S12XHZ                     */
/*                                    [AD,T,S,M,P,L,U,V,W]                    */
/*  In pin setup we use ports name 0 and 1 to be compliant with S12H          */
/*  For S12HZ and S12XHZ analog port ATD1 = I/O port AD (PORTAD = PORT1)      */
/*  used when pin only used as digital input (no analog input used)           */
/*  port name : AD                                                            */
/*  used when pin used both as digital input and as analog input              */
/*  port name : 1                                                             */
/*                                    NEC V850 Dx3                            */
/*                                    [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15] */
/*                                    REL V850 Dx4                            */
/*                                    [0,1,2,3,4,5,6,7,8,9,10,16,17,J0]       */
/*                                    Freescale S08 : Not supported           */
/*                                                                            */
/*  - PinNumber IN, number of the selected pin  [0..7]                        */
/*  - State     OUT, state of the pin (IODD_HIGH, IODD_LOW)                   */
/*Pre-condition : -                                                           */
/*Constraints :  -                                                            */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [get the pin state]                                                     */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#if defined(__MC9S12xx__) || \
    defined(__NEC_V850__)
#define IODD_GetPinStatus(PortName,\
                          PinNumber) \
        Iodd_GetPinState(PortName,PinNumber)
#endif /* defined(__MC9S12xx__) ||
          defined(__NEC_V850__) */


/*----------------------------------------------------------------------------*/
/*Name : IODD_GetPinData                                                      */
/*Role : Get the pin state                                                    */
/*Interface :                                                                 */
/*  - PortName  IN, name of port for :                                        */
/*                                    Motorola STAR12H                        */
/*                                    [0,1,A,B,E,K,T,S,M,P,H,J,L,U,V,W]       */
/*                                    note : 0 and 1 are ATD port             */
/*                                    Motorola STAR12HZ                       */
/*                                    [AD,A,B,E,K,T,S,M,P,L,U,V]              */
/*                                    Freescale MC9S12XHZ                     */
/*                                    [AD,A,B,C,D,E,K,T,S,M,P,L,U,V,W]        */
/*  In pin setup we use ports name 0 and 1 to be compliant with S12H          */
/*  For S12HZ and S12XHZ analog port ATD1 = I/O port AD (PORTAD = PORT1)      */
/*  used when pin only used as digital input (no analog input used)           */
/*  port name : AD                                                            */
/*  used when pin used both as digital input and as analog input              */
/*  port name : 1                                                             */
/*                                    NEC V850 Fx3                            */
/*                                 [0,1,2,3,4,5,6,7,8,9,12,15,CD,CM,CS,CT,DL] */
/*                                    NEC V850 Dx3                            */
/*                                    [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15] */
/*                                    REL V850 Dx4                            */
/*                                    [0,1,2,3,4,5,6,7,8,9,10,16,17,J0]       */
/*                                                                            */
/*  - PinNumber IN, number of the selected pin  [0..7]                        */
/*                  NOTE : for Motorola STAR12 port 0 and 1 -> port ATD       */
/*                         port 0 : PinNumber [8..15]                         */
/*                         port 1 : PinNumber [0..7]                          */
/*  - State     OUT, state of the pin (IODD_HIGH, IODD_LOW)                   */
/*Pre-condition : -                                                           */
/*Constraints :  -                                                            */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [get the pin state]                                                     */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#if defined(__MC9S12xx__) || \
    defined(__MC9S08xx__) || \
    defined(__NEC_V850__)
#define IODD_GetPinData(PortName,\
                        PinNumber) \
        Iodd_GetInputReg(PortName,PinNumber)
#endif /* defined(__MC9S12xx__) ||
          defined(__MC9S08xx__) ||
          defined(__NEC_V850__) */


/*----------------------------------------------------------------------------*/
/*Name : IODD_SetPinData                                                      */
/*Role : Set a state on the pin                                               */
/*Interface :                                                                 */
/*  - PortName  IN, name of port for :                                        */
/*                                    Motorola STAR12H                        */
/*                                    [A,B,E,K,T,S,M,P,H,J,L,U,V,W]           */
/*                                    Motorola STAR12HZ                       */
/*                                    [AD,A,B,E,K,T,S,M,P,L,U,V]              */
/*                                    Freescale MC9S12XHZ                     */
/*                                    [AD,A,B,C,D,E,K,T,S,M,P,L,U,V,W]        */
/*  For S12HZ and S12XHZ analog port ATD1 = I/O port AD (PORTAD = PORT1)      */
/*  used when pin only used as digital input (no analog input used)           */
/*  port name : AD                                                            */
/*                                    NEC V850 Fx3                            */
/*                                 [0,1,2,3,4,5,6,7,8,9,12,15,CD,CM,CS,CT,DL] */
/*                                    NEC V850 Dx3                            */
/*                                    [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15] */
/*                                    REL V850 Dx4                            */
/*                                    [0,1,2,3,4,5,6,7,8,9,10,16,17,J0]       */
/*                                                                            */
/*  - PinNumber IN, number of the selected pin [0..7]                         */
/*  - State     IN, requested output state of the pin [IODD_HIGH, IODD_LOW]   */
/*Pre-condition : -                                                           */
/*Constraints :  -                                                            */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [set the requested state on the pin]                                    */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#if defined(__MC9S12xx__) || \
    defined(__MC9S08xx__) 
#define IODD_SetPinData(PortName,\
                        PinNumber,\
                        State) \
        Iodd_SetOutputReg(PortName,PinNumber,State)
#endif /* defined(__MC9S12xx__) ||
          defined(__MC9S08xx__) */

#ifdef __NEC_V850__


#ifdef __REL_V850_Dx4__

#define IODD_SetPinData(PortName,\
                        PinNumber,\
                        State) \
     if((__GETSR() & PSW_ID_BIT_MASK) == 0) \
     { \
       DisableAllInterrupts(); \
       Iodd_SetOutputReg(PortName,PinNumber,State); \
       EnableAllInterrupts(); \
     } \
     else \
     { \
       Iodd_SetOutputReg(PortName,PinNumber,State) ; \
     }
   
#else 

#define IODD_SetPinData(PortName,\
                        PinNumber,\
                        State) \
        Iodd_SetOutputReg(PortName,PinNumber,State)

#endif /* __REL_V850_Dx4__*/
#endif /* __NEC_V850__ */


/*----------------------------------------------------------------------------*/
/*Name : IODD_ReadBytePortIn                                                  */
/*Role : Read an 8-bits port                                                  */
/*Interface :                                                                 */
/*  - PortName  IN, name of port for :                                        */
/*                                    Motorola STAR12H                        */
/*                                    [0,1,A,B,E,K,T,S,M,P,H,J,L,U,V,W]       */
/*                                    note : 0 and 1 are ATD port             */
/*                                    Motorola STAR12HZ                       */
/*                                    [AD,A,B,E,K,T,S,M,P,L,U,V]              */
/*                                    Freescale MC9S12XHZ                     */
/*                                    [AD,A,B,C,D,E,K,T,S,M,P,L,U,V,W]        */
/*  In pin setup we use ports name 0 and 1 to be compliant with S12H          */
/*  For S12HZ and S12XHZ analog port ATD1 = I/O port AD (PORTAD = PORT1)      */
/*  used when pin only used as digital input (no analog input used)           */
/*  port name : AD                                                            */
/*  used when pin used both as digital input and as analog input              */
/*  port name : 1                                                             */
/*                                    NEC V850 Fx3                            */
/*                                 [0,1,2,3,4,5,6,7,8,9,12,15,CD,CM,CS,CT,DL  */
/*                                  with H extension for the MSB byte (DLH)]  */
/*                                  with L extension for the LSB byte (DLL)]  */
/*                                    NEC V850 Dx3                            */
/*                                    [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15] */
/*                                    REL V850 Dx4                            */
/*                                    [J0]                                    */
/*                                                                            */
/*Pre-condition : -                                                           */
/*Constraints : can not read an output port                                   */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [read the requested port]                                               */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#if defined(__MC9S12xx__) || \
    defined(__MC9S08xx__)
#define IODD_ReadBytePortIn(PortName) \
        (TARG_ReadByte( Iodd_ReadRegisterName(PortName) ))
#endif /* defined(__MC9S12xx__) ||
          defined(__MC9S08xx__) */

#if defined(__NEC_V850__)
#define IODD_ReadBytePortIn(PortName) \
        TARG_ReadByte( P ## PortName)
#endif /* __NEC_V850__ */

/*----------------------------------------------------------------------------*/
/*Name : IODD_ReadShortPortIn                                                 */
/*Role : Read an 16-bits port                                                 */
/*Interface :                                                                 */
/*  - PortName  IN, name of port for :                                        */
/*                                    REL V850 Dx4                            */
/*                                    [0,1,2,3,4,10,16,17]                    */
/*                       JP0 is 8 bit accessible                              */
/*                                                                            */
/*Pre-condition : -                                                           */
/*Constraints :  -                                                            */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [write the requested port direction]                                    */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#ifdef __REL_V850_Dx4__
#define IODD_ReadShortPortIn(PortName) \
        TARG_ReadShort( P ## PortName)
#endif /*__REL_V850_Dx4__*/

/*----------------------------------------------------------------------------*/
/*Name : IODD_WriteBytePortOut                                                */
/*Role : Write into 8-bits port                                               */
/*Interface :                                                                 */
/*  - PortName  IN, name of port for :                                        */
/*                                    Motorola STAR12H                        */
/*                                    [A,B,K,T,S,M,P,H,J,L,U,V,W]             */
/*                                    Motorola STAR12HZ                       */
/*                                    [AD,A,B,K,T,S,M,P,L,U,V]                */
/*                                    Freescale MC9S12XHZ                     */
/*                                    [AD,A,B,C,D,E,K,T,S,M,P,L,U,V,W]        */
/*  For S12HZ and S12XHZ analog port ATD1 = I/O port AD (PORTAD = PORT1)      */
/*  used when pin only used as digital input (no analog input used)           */
/*  port name : AD                                                            */
/*                                    NEC V850 Fx3                            */
/*                                 [0,1,2,3,4,5,6,7,8,9,12,15,CD,CM,CS,CT,DL] */
/*                                  with H extension for the MSB byte (DLH)]  */
/*                                  with L extension for the LSB byte (DLL)]  */
/*                                    NEC V850 Dx3                            */
/*                                    [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15] */
/*                                    REL V850 Dx4                            */
/*                                    [J0]                                    */
/*                                                                            */
/*  - Value     IN, ubyte Value                                               */
/*Pre-condition : -                                                           */
/*Constraints :  -                                                            */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [write the requested port]                                              */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#ifdef __MC9S12xx__
#define IODD_WriteBytePortOut(PortName,\
                              Value) \
        (TARG_WriteByte( Iodd_WriteRegisterName(PortName),Value))
#endif /* __MC9S12xx__ */

#ifdef __MC9S08xx__
#define IODD_WriteBytePortOut(PortName,\
                              Value) \
        (TARG_WriteByte( Iodd_WriteRegisterName(PortName),Value))
#endif /* __MC9S08xx__ */

#ifdef __NEC_V850__

#ifdef __REL_V850_Dx4__
#define IODD_WriteBytePortOut(PortName,Value) \
     if((__GETSR() & PSW_ID_BIT_MASK ) == 0) \
     { \
        DisableAllInterrupts();\
        (TARG_WriteByte( P ## PortName, Value)) ;\
        EnableAllInterrupts();\
     } \
     else   \
   {  \
        (TARG_WriteByte( P ## PortName, Value))	;\
   }

#else

#define IODD_WriteBytePortOut(PortName,Value) \
        (TARG_WriteByte( P ## PortName, Value))

#endif /* __REL_V850_Dx4__*/
#endif /* __NEC_V850__ */

/*----------------------------------------------------------------------------*/
/*Name : IODD_WriteShortPortOut                                               */
/*Role : Write into 16-bits port                                              */
/*Interface :                                                                 */
/*  - PortName  IN, name of port for :                                        */
/*                                    REL V850 Dx4                            */
/*                                    [0,1,2,3,4,10,16,17]                    */
/*                       JP0 is 8 bit accessible                              */
/*  - Value     IN, ushort value                                              */
/*Pre-condition : -                                                           */
/*Constraints :  -                                                            */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [write the requested port direction]                                    */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#ifdef __REL_V850_Dx4__
#define IODD_WriteShortPortOut(PortName,Value) \
  if ( ( __GETSR() & PSW_ID_BIT_MASK ) == 0 ) \
  { \
    DisableAllInterrupts();\
    (TARG_WriteShort( P ## PortName, Value)); \
    EnableAllInterrupts();\
  } \
  else \
  { \
    (TARG_WriteShort( P ## PortName, Value)); \
  }
#endif /* __REL_V850_Dx4__ */


/*----------------------------------------------------------------------------*/
/*Name : IODD_WriteBytePortDirection                                          */
/*Role : Change 8-bits port direction                                         */
/*Interface :                                                                 */
/*  - PortName  IN, name of port for :                                        */
/*                                   Motorola STAR12H                         */
/*                                   [A,B,K,T,S,M,P,H,J,L,U,V,W]              */
/*                                   Motorola STAR12HZ                        */
/*                                   [AD,A,B,K,T,S,M,P,L,U,V]                 */
/*                                   Freescale MC9S12XHZ                      */
/*                                   [AD,A,B,C,D,E,K,T,S,M,P,L,U,V,W]         */
/*  For S12HZ and S12XHZ analog port ATD1 = I/O port AD (PORTAD = PORT1)      */
/*  used when pin only used as digital input (no analog input used)           */
/*  port name : AD                                                            */
/*                                   NEC V850 Fx3                             */
/*                                 [0,1,2,3,4,5,6,7,8,9,12,15,CD,CM,CS,CT,DL] */
/*                                  with H extension for the MSB byte (DLH)]  */
/*                                  with L extension for the LSB byte (DLL)]  */
/*                                   NEC V850 Dx3                             */
/*                                   [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15]  */
/*                                    REL V850 Dx4                            */
/*                                    [J0]                                    */
/*                                                                            */
/*  - Value     IN, ubyte value                                               */
/*Pre-condition : -                                                           */
/*Constraints :  -                                                            */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [write the requested port direction]                                    */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#ifdef __MC9S12xx__
#define IODD_WriteBytePortDirection(PortName,\
                                    Value) \
        (TARG_WriteByte(DDR ## PortName, Value))
#endif /* __MC9S12xx__ */

#ifdef __MC9S08xx__
#define IODD_WriteBytePortDirection(PortName,\
                                    Value) \
        (TARG_WriteByte(PT ## PortName ## DD, Value))
#endif /* __MC9S08xx__ */

#ifdef __NEC_V850__
#define IODD_WriteBytePortDirection(PortName,\
                                    Value) \
        Iodd_WREG_PM (PortName,Value)
#endif /* __NEC_V850__ */

/*----------------------------------------------------------------------------*/
/*Name : IODD_WriteShortPortDirection                                         */
/*Role : Change 16-bits port direction                                        */
/*Interface :                                                                 */
/*  - PortName  IN, name of port for :                                        */
/*                                    REL V850 Dx4                            */
/*                                    [0,1,2,3,4,10,16,17]                    */
/*                       JPM0 is 8 bit accessible                             */
/*  - Value     IN, ushort value                                              */
/*Pre-condition : -                                                           */
/*Constraints :  -                                                            */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [write the requested port direction]                                    */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/

#ifdef __REL_V850_Dx4__
#define IODD_WriteShortPortDirection(PortName,\
                                    Value) \
        Iodd_WREG_PM (PortName,Value)
#endif /* __REL_V850_Dx4__ */


/*----------------------------------------------------------------------------*/
/*Name : IODD_SetPortDirectionIn                                              */
/*Role : Set 8-bits port to operate as an input                               */
/*Interface :                                                                 */
/*  - PortName  IN, name of port for :                                        */
/*                                    Motorola STAR12H                        */
/*                                    [A,B,K,T,S,M,P,H,J,L,U,V,W]             */
/*                                    Motorola STAR12HZ                       */
/*                                    [AD,A,B,K,T,S,M,P,L,U,V]                */
/*                                    Freescale MC9S12XHZ                     */
/*                                    [AD,A,B,C,D,E,K,T,S,M,P,L,U,V,W]        */
/*  For S12HZ and S12XHZ analog port ATD1 = I/O port AD (PORTAD = PORT1)      */
/*  used when pin only used as digital input (no analog input used)           */
/*  port name : AD                                                            */
/*                                    NEC V850 Fx3                            */
/*                                 [0,1,2,3,4,5,6,7,8,9,12,15,CD,CM,CS,CT,DL] */
/*                                  with H extension for the MSB byte (DLH)]  */
/*                                  with L extension for the LSB byte (DLL)]  */
/*                                    NEC V850 Dx3                            */
/*                                    [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15] */
/*                                    REL V850 Dx4                            */
/*                                    [0,1,2,3,4,5,6,7,8,9,10,16,17,J0]       */
/*                                                                            */
/*Pre-condition : -                                                           */
/*Constraints :  -                                                            */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [set the requested port in input]                                       */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#if defined(__MC9S12xx__) || \
    defined(__MC9S08xx__)
#define IODD_SetPortDirectionIn(PortName)\
        IODD_WriteBytePortDirection(PortName,0x00)
#endif /* defined(__MC9S12xx__) ||
          defined(__MC9S08xx__) */

#if defined(__NEC_V850__)
#ifdef __REL_V850_Dx4__
/* Except Port J0 */
#define IODD_SetPortDirectionIn(PortName)\
        IODD_WriteShortPortDirection(PortName,0xFFFF)
#else
#define IODD_SetPortDirectionIn(PortName,Value) \
        IODD_WriteBytePortDirection(PortName,0xFF)

#endif /* __REL_V850_Dx4__ */
#endif /* __NEC_V850__ */


/*----------------------------------------------------------------------------*/
/*Name : IODD_SetPortDirectionOut                                             */
/*Role : Set 8-bits port to operate as an output                              */
/*Interface :                                                                 */
/*  - PortName  IN, name of port for :                                        */
/*                                    Motorola STAR12H                        */
/*                                    [A,B,K,T,S,M,P,H,J,L,U,V,W]             */
/*                                    Motorola STAR12HZ                       */
/*                                    [AD,A,B,K,T,S,M,P,L,U,V]                */
/*                                    Freescale MC9S12XHZ                     */
/*                                    [AD,A,B,C,D,E,K,T,S,M,P,L,U,V,W]        */
/*  For S12HZ and S12XHZ analog port ATD1 = I/O port AD (PORTAD = PORT1)      */
/*  used when pin only used as digital input (no analog input used)           */
/*  port name : AD                                                            */
/*                                    NEC V850 Fx3                            */
/*                                 [0,1,2,3,4,5,6,7,8,9,12,15,CD,CM,CS,CT,DL] */
/*                                  with H extension for the MSB byte (DLH)]  */
/*                                  with L extension for the LSB byte (DLL)]  */
/*                                    NEC V850 Dx3                            */
/*                                    [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15] */
/*                                    REL V850 Dx4                            */
/*                                    [0,1,2,3,4,5,6,7,8,9,10,16,17,J0]       */
/*                                                                            */
/*Pre-condition : -                                                           */
/*Constraints :  -                                                            */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [set the requested port in output]                                      */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#if defined(__MC9S12xx__) || \
    defined(__MC9S08xx__)
#define IODD_SetPortDirectionOut(PortName)\
        IODD_WriteBytePortDirection(PortName,0xFF)
#endif /* defined(__MC9S12xx__) ||
          defined(__MC9S08xx__) */

#if defined(__NEC_V850__)
#ifdef __REL_V850_Dx4__
/* Except Port J0 */
#define IODD_SetPortDirectionOut(PortName)\
        IODD_WriteShortPortDirection(PortName,0x0000)
#else
#define IODD_SetPortDirectionOut(PortName)\
        IODD_WriteBytePortDirection(PortName,0x00)
#endif /* __REL_V850_Dx4__ */
#endif /* __NEC_V850__ */

#endif /* ((defined __MC9S12xx__)  ||
           (defined __MC9S08xx__)  ||
           (defined __NEC_V850__)) */

#ifdef __NEC_V850_Dx3__
/*----------------------------------------------------------------------------*/
/*Role : Alternate port function selection                                    */
/*----------------------------------------------------------------------------*/
#define IODD_LCD_FUNC_OFF(PortName,PinNumber) \
        Iodd_WREG_LCDC_ ## PortName ## PinNumber(0)
#define IODD_LCD_FUNC_ON(PortName,PinNumber) \
        Iodd_WREG_LCDC_ ## PortName ## PinNumber(1)

/*----------------------------------------------------------------------------*/
/*Role : LCD port function activation                                         */
/*----------------------------------------------------------------------------*/
#define IODD_NO_ALTER_FUNC(PortName,PinNumber) \
        Iodd_WREG_FC_ ## PortName ## PinNumber(0)
#define IODD_ALTER_FUNC(PortName,PinNumber) \
        Iodd_WREG_FC_ ## PortName ## PinNumber(1)
#endif /* __NEC_V850_Dx3__ */

#ifdef __REL_V850_Dx4__
#define IODD_NO_ALTER_FUNC(PortName,PinNumber)                                               \
        TARG_WriteBitInShort(PMC ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 0)
#define IODD_ALTER1_FUNC(PortName,PinNumber)                                                 \
        TARG_WriteBitInShort(PMC ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 1);  \
        TARG_WriteBitInShort(PFCE ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 0); \
        TARG_WriteBitInShort(PFC ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 0)
#define IODD_ALTER2_FUNC(PortName,PinNumber)                                                 \
        TARG_WriteBitInShort(PMC ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 1);  \
        TARG_WriteBitInShort(PFCE ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 0); \
        TARG_WriteBitInShort(PFC ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 1)
#define IODD_ALTER3_FUNC(PortName,PinNumber)                                                 \
        TARG_WriteBitInShort(PMC ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 1);  \
        TARG_WriteBitInShort(PFCE ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 1); \
        TARG_WriteBitInShort(PFC ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 0)
#define IODD_ALTER4_FUNC(PortName,PinNumber)                                                 \
        TARG_WriteBitInShort(PMC ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 1);  \
        TARG_WriteBitInShort(PFCE ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 1); \
        TARG_WriteBitInShort(PFC ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 1)
#endif /* __REL_V850_Dx4__ */

#ifdef __REL_V850_Dx4__
#define IODD_INTP0_CTRL_REG   FCLA0CTL0
#define IODD_INTP1_CTRL_REG   FCLA0CTL1
#define IODD_INTP2_CTRL_REG   FCLA0CTL2
#define IODD_INTP3_CTRL_REG   FCLA0CTL3
#define IODD_INTP4_CTRL_REG   FCLA0CTL4
#define IODD_INTP5_CTRL_REG   FCLA0CTL5
#define IODD_INTP6_CTRL_REG   FCLA0CTL9
#define IODD_INTP7_CTRL_REG   FCLA0CTL7
#define IODD_INTP8_CTRL_REG   FCLA1CTL0
#define IODD_INTP9_CTRL_REG   FCLA1CTL1
#define IODD_INTP10_CTRL_REG  FCLA1CTL2
#define IODD_NMI_CTRL_REG     FCLA2CTL0

#define IODD_BOTH_EDGE       0x03
#define IODD_RISING_EDGE     0x01
#define IODD_FALLING_EDGE    0x05
#define IODD_HIGH_LEVEL      0x05
#define IODD_LOW_LEVEL       0x04

#define IODD_PORT_FILTER_FUNC(IntSource,DectionType) \
    TARG_WriteByte(IntSource##_CTRL_REG, DectionType)
#endif /* __REL_V850_Dx4__ */

/***** MICRO STAR12, V850 *****************************************************/


/***** MICRO TX49 *************************************************************/

#ifdef __TX49__


/*______ I N C L U D E - F I L E S ___________________________________________*/

#include "syst.h"
#include "iodd_config.h"
#include "targ.h"


/*______ G L O B A L - D E F I N E S _________________________________________*/

#define IODD_HIGH ((ubyte) 1)
#define IODD_LOW  ((ubyte) 0)


/*______ G L O B A L - T Y P E S _____________________________________________*/


/*______ G L O B A L - D A T A _______________________________________________*/



/*______ P R I V A T E - M A C R O S _________________________________________*/

/* Input Pin Mode ----------------------------------------------------------- */
#ifdef __TX4962__
/* for IRQ pin */
#define IODD_IT_FALLING_EDGE(PinNumber)                                                            \
        RGTX49_SetPinFunction(PinNumber, 1 << RGTX49_GetIRQFuncBitPos(PinNumber));                 \
        /* check if IT is IRQ3 */                                                                  \
        if(   (PinNumber == GPIO_PIN_PNLERGB21) || (PinNumber == GPIO_PIN_EBIF_AD8)                \
           || (PinNumber == GPIO_PIN_UART1RTS) || (PinNumber == GPIO_PIN_DMA_ACK_0))               \
        {                                                                                          \
            TARG_SetBitsInByte(IMR04, INT_MSK_EIM_FALLING_EDGE);                                   \
        }                                                                                          \
        /* check if IT is IRQ2 */                                                                  \
        else if (   (PinNumber == GPIO_PIN_PNLERGB20) || (PinNumber == GPIO_PIN_EBIF_ACK)          \
                 || (PinNumber == GPIO_PIN_IRQ2) )                                                 \
        {                                                                                          \
            TARG_SetBitsInByte(IMR03, INT_MSK_EIM_FALLING_EDGE);                                   \
        }                                                                                          \
        /* check if IT is IRQ1 */                                                                  \
        else if ((PinNumber == GPIO_PIN_MLBCLK) || (PinNumber == GPIO_PIN_UART2RTS))               \
        {                                                                                          \
            TARG_SetBitsInByte(IMR02, INT_MSK_EIM_FALLING_EDGE);                                   \
        }                                                                                          \
        else /* IRQ0 */                                                                            \
        {                                                                                          \
            TARG_SetBitsInByte(IMR01, INT_MSK_EIM_FALLING_EDGE);                                   \
        }


#define IODD_IT_RISING_EDGE(PinNumber)                                                             \
        /* check if IT is IRQ3 */                                                                  \
        if(   (PinNumber == GPIO_PIN_PNLERGB21) || (PinNumber == GPIO_PIN_EBIF_AD8)                \
           || (PinNumber == GPIO_PIN_UART1RTS) || (PinNumber == GPIO_PIN_DMA_ACK_0))               \
        {                                                                                          \
            TARG_SetBitsInByte(IMR04, INT_MSK_EIM_RISING_EDGE);                                    \
        }                                                                                          \
        /* check if IT is IRQ2 */                                                                  \
        else if (   (PinNumber == GPIO_PIN_PNLERGB20) || (PinNumber == GPIO_PIN_EBIF_ACK)          \
                 || (PinNumber == GPIO_PIN_IRQ2) )                                                 \
        {                                                                                          \
            TARG_SetBitsInByte(IMR03, INT_MSK_EIM_RISING_EDGE);                                    \
        }                                                                                          \
        /* check if IT is IRQ1 */                                                                  \
        else if ((PinNumber == GPIO_PIN_MLBCLK) || (PinNumber == GPIO_PIN_UART2RTS))               \
        {                                                                                          \
            TARG_SetBitsInByte(IMR02, INT_MSK_EIM_RISING_EDGE);                                    \
        }                                                                                          \
        else /* IRQ0 */                                                                            \
        {                                                                                          \
            TARG_SetBitsInByte(IMR01, INT_MSK_EIM_RISING_EDGE);                                    \
        }                                                                                          \
        RGTX49_SetPinFunction(PinNumber, 1 << RGTX49_GetIRQFuncBitPos(PinNumber));

#define IODD_IT_LOW_LEVEL(PinNumber)                                                               \
        RGTX49_SetPinFunction(PinNumber, 1 << RGTX49_GetIRQFuncBitPos(PinNumber));                 \
        /* check if IT is IRQ3 */                                                                  \
        if(   (PinNumber == GPIO_PIN_PNLERGB21) || (PinNumber == GPIO_PIN_EBIF_AD8)                \
           || (PinNumber == GPIO_PIN_UART1RTS) || (PinNumber == GPIO_PIN_DMA_ACK_0))               \
        {                                                                                          \
            TARG_SetBitsInByte(IMR04, INT_MSK_EIM_LOW_LEVEL);                                      \
        }                                                                                          \
        /* check if IT is IRQ2 */                                                                  \
        else if (   (PinNumber == GPIO_PIN_PNLERGB20) || (PinNumber == GPIO_PIN_EBIF_ACK)          \
                 || (PinNumber == GPIO_PIN_IRQ2) )                                                 \
        {                                                                                          \
            TARG_SetBitsInByte(IMR03, INT_MSK_EIM_LOW_LEVEL);                                      \
        }                                                                                          \
        /* check if IT is IRQ1 */                                                                  \
        else if ((PinNumber == GPIO_PIN_MLBCLK) || (PinNumber == GPIO_PIN_UART2RTS))               \
        {                                                                                          \
            TARG_SetBitsInByte(IMR02, INT_MSK_EIM_LOW_LEVEL);                                      \
        }                                                                                          \
        else /* IRQ0 */                                                                            \
        {                                                                                          \
            TARG_SetBitsInByte(IMR01, INT_MSK_EIM_LOW_LEVEL);                                      \
        }

#define IODD_IT_HIGH_LEVEL(PinNumber)                                                              \
        RGTX49_SetPinFunction(PinNumber, 1 << RGTX49_GetIRQFuncBitPos(PinNumber));                 \
        /* check if IT is IRQ3 */                                                                  \
        if(   (PinNumber == GPIO_PIN_PNLERGB21) || (PinNumber == GPIO_PIN_EBIF_AD8)                \
           || (PinNumber == GPIO_PIN_UART1RTS) || (PinNumber == GPIO_PIN_DMA_ACK_0))               \
        {                                                                                          \
            TARG_SetBitsInByte(IMR04, INT_MSK_EIM_HIGH_LEVEL);                                     \
        }                                                                                          \
        /* check if IT is IRQ2 */                                                                  \
        else if (   (PinNumber == GPIO_PIN_PNLERGB20) || (PinNumber == GPIO_PIN_EBIF_ACK)          \
                 || (PinNumber == GPIO_PIN_IRQ2) )                                                 \
        {                                                                                          \
            TARG_SetBitsInByte(IMR03, INT_MSK_EIM_HIGH_LEVEL);                                     \
        }                                                                                          \
        /* check if IT is IRQ1 */                                                                  \
        else if ((PinNumber == GPIO_PIN_MLBCLK) || (PinNumber == GPIO_PIN_UART2RTS))               \
        {                                                                                          \
            TARG_SetBitsInByte(IMR02, INT_MSK_EIM_HIGH_LEVEL);                                     \
        }                                                                                          \
        else /* IRQ0 */                                                                            \
        {                                                                                          \
            TARG_SetBitsInByte(IMR01, INT_MSK_EIM_HIGH_LEVEL);                                     \
        }
#endif /* __TX4962__ */

#ifdef __TX4964__
/* for IRQ pin */
#define IODD_IT_FALLING_EDGE(PinNumber)                                                            \
        RGTX49_SetPinFunction(PinNumber, 1 << RGTX49_GetIRQFuncBitPos(PinNumber));                 \
        /* check if IT is IRQ5 */                                                                  \
        if(   (PinNumber == GPIO_PIN_CAMCBCR5) || (PinNumber == GPIO_PIN_EBIF_A4)                  \
           || (PinNumber == GPIO_PIN_ESEI0SCLK) )                                                  \
        {                                                                                          \
            TARG_SetBitsInByte(IMR010, INT_MSK_EIM_FALLING_EDGE);                                  \
        }                                                                                          \
        /* check if IT is IRQ4 */                                                                  \
        else if(   (PinNumber == GPIO_PIN_CAMCBCR5) || (PinNumber == GPIO_PIN_EBIF_ACK)            \
                || (PinNumber == GPIO_PIN_EBIF_A5)  || (PinNumber == GPIO_PIN_DISPRGB9)            \
                || (PinNumber == GPIO_PIN_ESEI0SSOI) )                                             \
        {                                                                                          \
            TARG_SetBitsInByte(IMR09, INT_MSK_EIM_FALLING_EDGE);                                   \
        }                                                                                          \
        /* check if IT is IRQ3 */                                                                  \
        else if(   (PinNumber == GPIO_PIN_CAMCBCR3) || (PinNumber == GPIO_PIN_EBIF_CE1)            \
                || (PinNumber == GPIO_PIN_EBIF_A6)  || (PinNumber == GPIO_PIN_PNLGPP0)             \
                || (PinNumber == GPIO_PIN_DISPRGB8) )                                              \
        {                                                                                          \
            TARG_SetBitsInByte(IMR04, INT_MSK_EIM_FALLING_EDGE);                                   \
        }                                                                                          \
        /* check if IT is IRQ2 */                                                                  \
        else if (   (PinNumber == GPIO_PIN_CAMHSYNC)     || (PinNumber == GPIO_PIN_CAMCBCR2)       \
                 || (PinNumber == GPIO_PIN_EBIF_SYSCLK)  || (PinNumber == GPIO_PIN_EBIF_A12)       \
                 || (PinNumber == GPIO_PIN_I2S0SD) )                                               \
        {                                                                                          \
            TARG_SetBitsInByte(IMR03, INT_MSK_EIM_FALLING_EDGE);                                   \
        }                                                                                          \
        /* check if IT is IRQ1 */                                                                  \
        else if(   (PinNumber == GPIO_PIN_CAMHDISP) || (PinNumber == GPIO_PIN_CAMCBCR1)            \
                || (PinNumber == GPIO_PIN_EBIF_A11) || (PinNumber == GPIO_PIN_IRQ1) )              \
        {                                                                                          \
            TARG_SetBitsInByte(IMR02, INT_MSK_EIM_FALLING_EDGE);                                   \
        }                                                                                          \
        /* check if IT is IRQ0 */                                                                  \
        else if(   (PinNumber == GPIO_PIN_CAMFODD)  || (PinNumber == GPIO_PIN_CAMCBCR0)            \
                || (PinNumber == GPIO_PIN_GDCCLKIN) )                                              \
        {                                                                                          \
            TARG_SetBitsInByte(IMR01, INT_MSK_EIM_FALLING_EDGE);                                   \
        }                                                                                          \
        else                                                                                       \
        {                                                                                          \
            /* nop */                                                                              \
        }


#define IODD_IT_RISING_EDGE(PinNumber)                                                             \
        /* check if IT is IRQ5 */                                                                  \
        if(   (PinNumber == GPIO_PIN_CAMCBCR5) || (PinNumber == GPIO_PIN_EBIF_A4)                  \
           || (PinNumber == GPIO_PIN_ESEI0SCLK) )                                                  \
        {                                                                                          \
            TARG_SetBitsInByte(IMR010, INT_MSK_EIM_RISING_EDGE);                                   \
        }                                                                                          \
        /* check if IT is IRQ4 */                                                                  \
        else if(   (PinNumber == GPIO_PIN_CAMCBCR5) || (PinNumber == GPIO_PIN_EBIF_ACK)            \
                || (PinNumber == GPIO_PIN_EBIF_A5)  || (PinNumber == GPIO_PIN_DISPRGB9)            \
                || (PinNumber == GPIO_PIN_ESEI0SSOI) )                                             \
        {                                                                                          \
            TARG_SetBitsInByte(IMR09, INT_MSK_EIM_RISING_EDGE);                                    \
        }                                                                                          \
        /* check if IT is IRQ3 */                                                                  \
        else if(   (PinNumber == GPIO_PIN_CAMCBCR3) || (PinNumber == GPIO_PIN_EBIF_CE1)            \
                || (PinNumber == GPIO_PIN_EBIF_A6)  || (PinNumber == GPIO_PIN_PNLGPP0)             \
                || (PinNumber == GPIO_PIN_DISPRGB8) )                                              \
        {                                                                                          \
            TARG_SetBitsInByte(IMR04, INT_MSK_EIM_RISING_EDGE);                                    \
        }                                                                                          \
        /* check if IT is IRQ2 */                                                                  \
        else if (   (PinNumber == GPIO_PIN_CAMHSYNC)     || (PinNumber == GPIO_PIN_CAMCBCR2)       \
                 || (PinNumber == GPIO_PIN_EBIF_SYSCLK)  || (PinNumber == GPIO_PIN_EBIF_A12)       \
                 || (PinNumber == GPIO_PIN_I2S0SD) )                                               \
        {                                                                                          \
            TARG_SetBitsInByte(IMR03, INT_MSK_EIM_RISING_EDGE);                                    \
        }                                                                                          \
        /* check if IT is IRQ1 */                                                                  \
        else if(   (PinNumber == GPIO_PIN_CAMHDISP) || (PinNumber == GPIO_PIN_CAMCBCR1)            \
                || (PinNumber == GPIO_PIN_EBIF_A11) || (PinNumber == GPIO_PIN_IRQ1) )              \
        {                                                                                          \
            TARG_SetBitsInByte(IMR02, INT_MSK_EIM_RISING_EDGE);                                    \
        }                                                                                          \
        /* check if IT is IRQ0 */                                                                  \
        else if(   (PinNumber == GPIO_PIN_CAMFODD)  || (PinNumber == GPIO_PIN_CAMCBCR0)            \
                || (PinNumber == GPIO_PIN_GDCCLKIN) )                                              \
        {                                                                                          \
            TARG_SetBitsInByte(IMR01, INT_MSK_EIM_RISING_EDGE);                                    \
        }                                                                                          \
        else                                                                                       \
        {                                                                                          \
            /* nop */                                                                              \
        }                                                                                          \
        RGTX49_SetPinFunction(PinNumber, 1 << RGTX49_GetIRQFuncBitPos(PinNumber));

#define IODD_IT_LOW_LEVEL(PinNumber)                                                               \
        RGTX49_SetPinFunction(PinNumber, 1 << RGTX49_GetIRQFuncBitPos(PinNumber));                 \
        /* check if IT is IRQ5 */                                                                  \
        if(   (PinNumber == GPIO_PIN_CAMCBCR5) || (PinNumber == GPIO_PIN_EBIF_A4)                  \
           || (PinNumber == GPIO_PIN_ESEI0SCLK) )                                                  \
        {                                                                                          \
            TARG_SetBitsInByte(IMR010, INT_MSK_EIM_LOW_LEVEL);                                     \
        }                                                                                          \
        /* check if IT is IRQ4 */                                                                  \
        else if(   (PinNumber == GPIO_PIN_CAMCBCR5) || (PinNumber == GPIO_PIN_EBIF_ACK)            \
                || (PinNumber == GPIO_PIN_EBIF_A5)  || (PinNumber == GPIO_PIN_DISPRGB9)            \
                || (PinNumber == GPIO_PIN_ESEI0SSOI) )                                             \
        {                                                                                          \
            TARG_SetBitsInByte(IMR09, INT_MSK_EIM_LOW_LEVEL);                                      \
        }                                                                                          \
        /* check if IT is IRQ3 */                                                                  \
        else if(   (PinNumber == GPIO_PIN_CAMCBCR3) || (PinNumber == GPIO_PIN_EBIF_CE1)            \
                || (PinNumber == GPIO_PIN_EBIF_A6)  || (PinNumber == GPIO_PIN_PNLGPP0)             \
                || (PinNumber == GPIO_PIN_DISPRGB8) )                                              \
        {                                                                                          \
            TARG_SetBitsInByte(IMR04, INT_MSK_EIM_LOW_LEVEL);                                      \
        }                                                                                          \
        /* check if IT is IRQ2 */                                                                  \
        else if (   (PinNumber == GPIO_PIN_CAMHSYNC)     || (PinNumber == GPIO_PIN_CAMCBCR2)       \
                 || (PinNumber == GPIO_PIN_EBIF_SYSCLK)  || (PinNumber == GPIO_PIN_EBIF_A12)       \
                 || (PinNumber == GPIO_PIN_I2S0SD) )                                               \
        {                                                                                          \
            TARG_SetBitsInByte(IMR03, INT_MSK_EIM_LOW_LEVEL);                                      \
        }                                                                                          \
        /* check if IT is IRQ1 */                                                                  \
        else if(   (PinNumber == GPIO_PIN_CAMHDISP) || (PinNumber == GPIO_PIN_CAMCBCR1)            \
                || (PinNumber == GPIO_PIN_EBIF_A11) || (PinNumber == GPIO_PIN_IRQ1) )              \
        {                                                                                          \
            TARG_SetBitsInByte(IMR02, INT_MSK_EIM_LOW_LEVEL);                                      \
        }                                                                                          \
        /* check if IT is IRQ0 */                                                                  \
        else if(   (PinNumber == GPIO_PIN_CAMFODD)  || (PinNumber == GPIO_PIN_CAMCBCR0)            \
                || (PinNumber == GPIO_PIN_GDCCLKIN) )                                              \
        {                                                                                          \
            TARG_SetBitsInByte(IMR01, INT_MSK_EIM_LOW_LEVEL);                                      \
        }                                                                                          \
        else                                                                                       \
        {                                                                                          \
            /* nop */                                                                              \
        }

#define IODD_IT_HIGH_LEVEL(PinNumber)                                                              \
        RGTX49_SetPinFunction(PinNumber, 1 << RGTX49_GetIRQFuncBitPos(PinNumber));                 \
        /* check if IT is IRQ5 */                                                                  \
        if(   (PinNumber == GPIO_PIN_CAMCBCR5) || (PinNumber == GPIO_PIN_EBIF_A4)                  \
           || (PinNumber == GPIO_PIN_ESEI0SCLK) )                                                  \
        {                                                                                          \
            TARG_SetBitsInByte(IMR010, INT_MSK_EIM_HIGH_LEVEL);                                    \
        }                                                                                          \
        /* check if IT is IRQ4 */                                                                  \
        else if(   (PinNumber == GPIO_PIN_CAMCBCR5) || (PinNumber == GPIO_PIN_EBIF_ACK)            \
                || (PinNumber == GPIO_PIN_EBIF_A5)  || (PinNumber == GPIO_PIN_DISPRGB9)            \
                || (PinNumber == GPIO_PIN_ESEI0SSOI) )                                             \
        {                                                                                          \
            TARG_SetBitsInByte(IMR09, INT_MSK_EIM_HIGH_LEVEL);                                     \
        }                                                                                          \
        /* check if IT is IRQ3 */                                                                  \
        else if(   (PinNumber == GPIO_PIN_CAMCBCR3) || (PinNumber == GPIO_PIN_EBIF_CE1)            \
                || (PinNumber == GPIO_PIN_EBIF_A6)  || (PinNumber == GPIO_PIN_PNLGPP0)             \
                || (PinNumber == GPIO_PIN_DISPRGB8) )                                              \
        {                                                                                          \
            TARG_SetBitsInByte(IMR04, INT_MSK_EIM_HIGH_LEVEL);                                     \
        }                                                                                          \
        /* check if IT is IRQ2 */                                                                  \
        else if (   (PinNumber == GPIO_PIN_CAMHSYNC)     || (PinNumber == GPIO_PIN_CAMCBCR2)       \
                 || (PinNumber == GPIO_PIN_EBIF_SYSCLK)  || (PinNumber == GPIO_PIN_EBIF_A12)       \
                 || (PinNumber == GPIO_PIN_I2S0SD) )                                               \
        {                                                                                          \
            TARG_SetBitsInByte(IMR03, INT_MSK_EIM_HIGH_LEVEL);                                     \
        }                                                                                          \
        /* check if IT is IRQ1 */                                                                  \
        else if(   (PinNumber == GPIO_PIN_CAMHDISP) || (PinNumber == GPIO_PIN_CAMCBCR1)            \
                || (PinNumber == GPIO_PIN_EBIF_A11) || (PinNumber == GPIO_PIN_IRQ1) )              \
        {                                                                                          \
            TARG_SetBitsInByte(IMR02, INT_MSK_EIM_HIGH_LEVEL);                                     \
        }                                                                                          \
        /* check if IT is IRQ0 */                                                                  \
        else if(   (PinNumber == GPIO_PIN_CAMFODD)  || (PinNumber == GPIO_PIN_CAMCBCR0)            \
                || (PinNumber == GPIO_PIN_GDCCLKIN) )                                              \
        {                                                                                          \
            TARG_SetBitsInByte(IMR01, INT_MSK_EIM_HIGH_LEVEL);                                     \
        }                                                                                          \
        else                                                                                       \
        {                                                                                          \
            /* nop */                                                                              \
        }
#endif /* __TX4964__ */

#define IODD_STANDARD(PinNumber) \
        RGTX49_SetPinFunction(PinNumber, 0)


/* Set one bit in a port direction register --------------------------------- */
#define Iodd_SetDdrBit(PortName,PinNumber,value) \
        Iodd_SetDdrBitTo##value(PortName,PinNumber)

#define Iodd_SetDdrBitTo0(PortName, PinNumber) \
           TARG_ClearBitsIndexed(GPIO_BASE_ADDRESS, \
                                 RGTX49_GetDirectionOffset(PinNumber), \
                                 1 << RGTX49_GetDirectionBitPos(PinNumber) )

#define Iodd_SetDdrBitTo1(PortName, PinNumber) \
           TARG_SetBitsIndexed(GPIO_BASE_ADDRESS, \
                                 RGTX49_GetDirectionOffset(PinNumber), \
                                 1 << RGTX49_GetDirectionBitPos(PinNumber) )



/*______ G L O B A L - M A C R O S ___________________________________________*/

/* PIN Description Macros-----------------------------------------------------*/
/* These macros are used to access to every pin of the chip                                  */
/* These macros return a long long byte, defined as follow :                                 */
/* - Bits 0 -> 7 : Bit position (in GPIO function registers) which defines the pin as an IT. */
/*                 If it equals to NO_IRQ_AVAILABLE, it means that current pin has an IRQ    */
/* - Bits 8 -> 10 : flag which indicate available direction for the current pin              */
/* - Bits 11 -> 18 : offset to apply to GPIO_Base_Address to access to direction registers   */
/*                   for the current pin                                                     */
/* - Bits 19 -> 23 : bit position in direction registers which define current pin            */
/* - Bits 24 -> 35 : offset to apply to GPIO_Base_Address to access to GPIO function         */
/*                   registers                                                               */



/*----------------------------------------------------------------------------*/
/* Name : IODD_PinSetUpInput                                                  */
/* Role : Set up a microcontroler pin to work as an input                     */
/* Interface :                                                                */
/*   - PortName    NOT USED                                                   */
/*                                                                            */
/*   - PinNumber   IN, name of the selected pin use macros GPIO_PIN_PinName   */
/*   - PinMode     IN, use mode of the pin                                    */
/*                                         [IODD_STANDARD,                    */
/*                                          IODD_IT_RISING_EDGE,              */
/*                                          IODD_IT_FALLING_EDGE,             */
/*                                          IODD_IT_HIGH_EDGE,                */
/*                                          IODD_IT_LOW_LEVEL]                */
/*   - PullUpState IN, NOT USED                                               */
/* Pre-condition : -                                                          */
/* Constraints : -                                                            */
/* Behavior :                                                                 */
/*   DO                                                                       */
/*     [set up the pin as requested]                                          */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/
#define IODD_PinSetUpInput(PortName,PinNumber, PinMode, PullUpState) \
        PinMode(PinNumber); \
        Iodd_SetDdrBit(PortName,PinNumber,0)

/*----------------------------------------------------------------------------*/
/* Name : IODD_SetPinDirectionIn                                              */
/* Role : Set direction register to set pin in input                          */
/* Interface :                                                                */
/*   - PortName    NOT USED                                                   */
/*                                                                            */
/*   - PinNumber   IN, name of the selected pin use macros GPIO_PIN_PinName   */
/* Pre-condition : -                                                          */
/* Constraints : -                                                            */
/* Behavior :                                                                 */
/*   DO                                                                       */
/*     [set up the pin as requested]                                          */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/
#define IODD_SetPinDirectionIn(PortName, PinNumber) \
        Iodd_SetDdrBit(PortName,PinNumber,0)

/*----------------------------------------------------------------------------*/
/* Name : IODD_SetPinDirectionOut                                             */
/* Role : Set direction register to set pin in output                         */
/* Interface :                                                                */
/*   - PortName    NOT USED                                                   */
/*                                                                            */
/*   - PinNumber   IN, name of the selected pin use macros GPIO_PIN_PinName   */
/* Pre-condition : -                                                          */
/* Constraints : -                                                            */
/* Behavior :                                                                 */
/*   DO                                                                       */
/*     [set up the pin as requested]                                          */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/
#define IODD_SetPinDirectionOut(PortName,PinNumber) \
        Iodd_SetDdrBit(PortName,PinNumber,1)

/*----------------------------------------------------------------------------*/
/*Name : IODD_SetPullUpData                                                   */
/*Role : Set the pull-up state                                                */
/*Interface :                                                                 */
/*   - PortName    NOT USED                                                   */
/*                                                                            */
/*   - PinNumber   NOT USED                                                   */
/*Pre-condition : -                                                           */
/*Constraints :  -                                                            */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [set the pull-up state]                                                 */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#define IODD_SetPullUpData(PortName,PinNumber)

/*----------------------------------------------------------------------------*/
/*Name : IODD_SetPullDownData                                                 */
/*Role : Set the pull-down state                                              */
/*Interface :                                                                 */
/*   - PortName    NOT USED                                                   */
/*                                                                            */
/*   - PinNumber   NOT USED                                                   */
/*Pre-condition : -                                                           */
/*Constraints :  -                                                            */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [set the pull-up state]                                                 */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#define IODD_SetPullDownData(PortName,PinNumber)

/*----------------------------------------------------------------------------*/
/* Name : IODD_EnableIrq                                                      */
/* Role : Enable interrupt request                                            */
/* Interface :                                                                */
/*   - IrqName IN, name of Irq for :                                          */
/*                                 [IODD_IRQ0  -> IRQ0 pin                    */
/*                                  IODD_IRQ1  -> MLBCLK or UART2RTS pins     */
/*                                  IODD_IRQ2  -> PNLERGB20 or EBIF_ACK       */
/*                                                or IRQ2 pins                */
/*                                  IODD_IRQ3  -> PNLERGB21 or EBIF_AD8 or    */
/*                                              or UART1RTS or DMA_ACK_0 pins */
/* Note : priority is level 1                                                 */
/* Pre-condition : -                                                          */
/* Constraints : -                                                            */
/* Behavior :                                                                 */
/*   DO                                                                       */
/*     [enable interrupt requested]                                           */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/
#define IODD_EnableIrq(IrqName) IODD_EnableIrq_ ## IrqName

#define IODD_EnableIrq_IODD_IRQ0  TARG_SetBitsInByte(IMR01,IODC_IRQ0_INTERRUPT_LEVEL)
#define IODD_EnableIrq_IODD_IRQ1  TARG_SetBitsInByte(IMR02,IODC_IRQ1_INTERRUPT_LEVEL)
#define IODD_EnableIrq_IODD_IRQ2  TARG_SetBitsInByte(IMR03,IODC_IRQ2_INTERRUPT_LEVEL)
#define IODD_EnableIrq_IODD_IRQ3  TARG_SetBitsInByte(IMR04,IODC_IRQ3_INTERRUPT_LEVEL)

/*----------------------------------------------------------------------------*/
/* Name : IODD_DisableIrq                                                     */
/* Role : Disable interrupt request                                           */
/* Interface :                                                                */
/*   - IrqName IN, name of Irq for :                                          */
/*                                 [IODD_IRQ0  -> IRQ0 pin                    */
/*                                  IODD_IRQ1  -> MLBCLK or UART2RTS pins     */
/*                                  IODD_IRQ2  -> PNLERGB20 or EBIF_ACK       */
/*                                                or IRQ2 pins                */
/*                                  IODD_IRQ3  -> PNLERGB21 or EBIF_AD8 or    */
/*                                              or UART1RTS or DMA_ACK_0 pins */
/*                                                                            */
/* Pre-condition : -                                                          */
/* Constraints : -                                                            */
/* Behavior :                                                                 */
/*   DO                                                                       */
/*     [disable interrupt requested]                                          */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/
#define IODD_DisableIrq(IrqName) IODD_DisableIrq_ ## IrqName

#define IODD_DisableIrq_IODD_IRQ0  TARG_ClearBitsInByte(IMR01,IODC_IRQ0_INTERRUPT_LEVEL)
#define IODD_DisableIrq_IODD_IRQ1  TARG_ClearBitsInByte(IMR02,IODC_IRQ1_INTERRUPT_LEVEL)
#define IODD_DisableIrq_IODD_IRQ2  TARG_ClearBitsInByte(IMR03,IODC_IRQ2_INTERRUPT_LEVEL)
#define IODD_DisableIrq_IODD_IRQ3  TARG_ClearBitsInByte(IMR04,IODC_IRQ3_INTERRUPT_LEVEL)

/*----------------------------------------------------------------------------*/
/* Name : IODD_ReadStatusIrq                                                  */
/* Role : Read interrupt request flag                                         */
/* Interface :                                                                */
/*   - IrqName IN, name of Irq for :                                          */
/*                                 [IODD_IRQ0  -> IRQ0 pin                    */
/*                                  IODD_IRQ1  -> MLBCLK or UART2RTS pins     */
/*                                  IODD_IRQ2  -> PNLERGB20 or EBIF_ACK       */
/*                                                or IRQ2 pins                */
/*                                  IODD_IRQ3  -> PNLERGB21 or EBIF_AD8 or    */
/*                                              or UART1RTS or DMA_ACK_0 pins */
/*                                                                            */
/* Pre-condition : -                                                          */
/* Constraints : -                                                            */
/* Behavior :                                                                 */
/*   DO                                                                       */
/*     [read the interrupt status]                                            */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/
#define IODD_ReadStatusIrq(IrqName) IODD_ReadStatusIrq_ ## IrqName

#define IODD_ReadStatusIrq_IODD_IRQ0
#define IODD_ReadStatusIrq_IODD_IRQ1
#define IODD_ReadStatusIrq_IODD_IRQ2
#define IODD_ReadStatusIrq_IODD_IRQ3

/*----------------------------------------------------------------------------*/
/* Name : IODD_ClearStatusIrq                                                 */
/* Role : Clear interrupt request flag                                        */
/* Interface :                                                                */
/*   - IrqName IN, name of Irq for :                                          */
/*                                 [IODD_IRQ0  -> IRQ0 pin                    */
/*                                  IODD_IRQ1  -> MLBCLK or UART2RTS pins     */
/*                                  IODD_IRQ2  -> PNLERGB20 or EBIF_ACK       */
/*                                                or IRQ2 pins                */
/*                                  IODD_IRQ3  -> PNLERGB21 or EBIF_AD8 or    */
/*                                              or UART1RTS or DMA_ACK_0 pins */
/*                                                                            */
/* Pre-condition : -                                                          */
/* Constraints : -                                                            */
/* Behavior :                                                                 */
/*   DO                                                                       */
/*     [nothing]                                                              */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/
#define IODD_ClearStatusIrq(IrqName) IODD_ClearStatusIrq_ ## IrqName

#define IODD_ClearStatusIrq_IODD_IRQ0
#define IODD_ClearStatusIrq_IODD_IRQ1
#define IODD_ClearStatusIrq_IODD_IRQ2
#define IODD_ClearStatusIrq_IODD_IRQ3

/*----------------------------------------------------------------------------*/
/*Name : IODD_PinSetUpOutput                                                  */
/*Role : Set up a microcontroler pin to work as an output                     */
/*Interface :                                                                 */
/*   - PortName    NOT USED                                                   */
/*                                                                            */
/*   - PinNumber   Out, name of the selected pin use macros GPIO_PIN_PinName  */
/*  -  OpenDrainState IN, NOT USED                                            */
/*Pre-condition : -                                                           */
/*Constraints :  -                                                            */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [set up the pin as requested]                                           */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#define IODD_PinSetUpOutput(PortName,PinNumber,OpenDrainState) \
        IODD_STANDARD(PinNumber); \
        Iodd_SetDdrBit(PortName,PinNumber,1)

/*----------------------------------------------------------------------------*/
/*Name : IODD_SetOpenDrainData                                                */
/*Role : Set the open-drain state                                             */
/*Interface :                                                                 */
/*   - PortName    NOT USED                                                   */
/*                                                                            */
/*   - PinNumber   IN, name of the selected pin use macros GPIO_PIN_PinName   */
/*  -  State     IN, NOT USED                                                 */
/*                                                                            */
/*Pre-condition : -                                                           */
/*Constraints :  -                                                            */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [nothing]                                                               */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#define IODD_SetOpenDrainData(PortName,PinNumber)

/*----------------------------------------------------------------------------*/
/*Name : IODD_GetPinData                                                      */
/*Role : Get the pin state                                                    */
/*Interface :                                                                 */
/*   - PortName    NOT USED                                                   */
/*                                                                            */
/*   - PinNumber   IN, name of the selected pin use macros GPIO_PIN_PinName   */
/*  -  State     OUT, state of the pin (IODD_HIGH, IODD_LOW)                  */
/*Pre-condition : -                                                           */
/*Constraints :  -                                                            */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [get the pin state]                                                     */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#define IODD_GetPinData(PortName, PinNumber) \
        (ulong)( ( TARG_ReadLongIndexed(GPIO_BASE_ADDRESS, RGTX49_GetDirectionOffset(PinNumber)  + 0x01) \
                   & (1 << RGTX49_GetDirectionBitPos(PinNumber))  ) \
                 >> RGTX49_GetDirectionBitPos(PinNumber) )

/*----------------------------------------------------------------------------*/
/*Name : IODD_GetPinStatus                                                    */
/*Role : Get the status of the pin                                            */
/*Interface :                                                                 */
/*   - PortName    NOT USED                                                   */
/*                                                                            */
/*   - PinNumber   IN, name of the selected pin use macros GPIO_PIN_PinName   */
/*   - State     OUT, NOT USED                                                */
/*Pre-condition : -                                                           */
/*Constraints :  -                                                            */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [nothing          ]                                                     */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#define IODD_GetPinStatus(PortName,  \
                          PinNumber) \
        (ubyte)IODD_GetPinData(PortName,PinNumber)

/*----------------------------------------------------------------------------*/
/*Name : IODD_SetPinData                                                      */
/*Role : Set a state on the pin                                               */
/*Interface :                                                                 */
/*  - PortName    NOT USED                                                    */
/*                                                                            */
/*  - PinNumber   IN, name of the selected pin use macros GPIO_PIN_PinName    */
/*  - State     IN, requested output state of the pin [IODD_HIGH, IODD_LOW]   */
/*Pre-condition : -                                                           */
/*Constraints :  -                                                            */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [set the requested state on the pin]                                    */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#define IODD_SetPinData(PortName,PinNumber,State) \
        if(State == 0) \
        { \
          Iodd_SetPinDataTo0(PinNumber); \
        } \
        else \
        { \
          Iodd_SetPinDataTo1(PinNumber); \
        }

#define Iodd_SetPinDataTo0(PinNumber) \
           TARG_ClearBitsIndexed(GPIO_BASE_ADDRESS, \
                                 RGTX49_GetDirectionOffset(PinNumber)+ 0x2, \
                                 (ulong)1 << RGTX49_GetDirectionBitPos(PinNumber))

#define Iodd_SetPinDataTo1(PinNumber) \
           TARG_SetBitsIndexed(GPIO_BASE_ADDRESS, \
                               RGTX49_GetDirectionOffset(PinNumber)+0x2, \
                               (ulong)1 << RGTX49_GetDirectionBitPos(PinNumber))

#endif /* __TX49__ */

/***** MICRO TX49 *************************************************************/


/***** MICRO IMX 53 ***********************************************************/

#if defined(__FSL_IMX53x__) || defined(__FSL_IMX6x__)

/*______ I N C L U D E - F I L E S ___________________________________________*/

#include "syst.h"
#include "targ.h"


/*______ G L O B A L - D E F I N E S _________________________________________*/

#define IODD_HIGH ((ubyte) 1)
#define IODD_LOW  ((ubyte) 0)

#define IODD_MAX_PIN_NUMBER 32


/*______ G L O B A L - T Y P E S _____________________________________________*/


/*______ G L O B A L - D A T A _______________________________________________*/

extern ulong IODD_MASK[IODD_MAX_PIN_NUMBER];


/*______ P R I V A T E - M A C R O S _________________________________________*/


/* Input Pin Mode ----------------------------------------------------------- */

#define IODD_STANDARD(PortName, PinNumber)                               \
        Iodd_IcrProgram(PortName, PinNumber, 0)
#define IODD_IT_LOW_LEVEL(PortName, PinNumber)                           \
        Iodd_IcrProgram(PortName, PinNumber, 0)
#define IODD_IT_HIGH_LEVEL(PortName, PinNumber)                          \
        Iodd_IcrProgram(PortName, PinNumber, 1)
#define IODD_IT_RISING_EDGE(PortName, PinNumber)                         \
        Iodd_IcrProgram(PortName, PinNumber, 2)
#define IODD_IT_FALLING_EDGE(PortName, PinNumber)                        \
        Iodd_IcrProgram(PortName, PinNumber, 3)
#define IODD_IT_BOTH_EDGE(PortName, PinNumber)                           \
        Iodd_IcrProgram(PortName, PinNumber, 4)

/* Two registers to program interrupt (GPIO_ICR1 and GPIO_ICR2) */
/* Two bits by channel ->                                       */
/* Pin Number        bits in :     GPIO_ICR2   GPIO_ICR1        */
/*      0                                           1- 0        */
/*      1                                           3- 2        */
/*     ..                                          .....        */
/*      7                                          15-16        */
/*      8                                          17-16        */
/*     ..                                          .....        */
/*     15                                          31-30        */
/*     16                               1- 0                    */
/*     ..                              .....                    */
/*     23                              15-14                    */
/*     24                              17-16                    */
/*     ..                              .....                    */
/*     31                              31-30                    */
#define Iodd_IcrProgram(PortName, PinNumber, Choice)                     \
     if(PinNumber > 15)                                                  \
     {                                                                   \
       TARG_WriteLong(GPIO_ICR2(PortName),                               \
           (TARG_ReadLong(GPIO_ICR2(PortName)) & IODD_MASK[PinNumber]) | \
           (((ulong)Choice & 0x03) << (((PinNumber - 16) * 2) & 0x1E))   \
                     );                                                  \
     }                                                                   \
     else                                                                \
     {                                                                   \
       TARG_WriteLong(GPIO_ICR1(PortName),                               \
           (TARG_ReadLong(GPIO_ICR1(PortName)) & IODD_MASK[PinNumber]) | \
           ((ulong)(Choice & 0x03) << ((PinNumber * 2) & 0x1E))          \
                     );                                                  \
     }                                                                   \
     if(Choice < 4)                                                      \
     {                                                                   \
       TARG_ClearBits(GPIO_EDGE_SEL(PortName), ((ulong)1 << PinNumber)); \
     }                                                                   \
     else                                                                \
     {                                                                   \
       TARG_SetBits(GPIO_EDGE_SEL(PortName), ((ulong)1 << PinNumber));   \
     }

/* Set one bit in a port direction register --------------------------------- */
#define Iodd_SetDdrBit(PortName, PinNumber, value)                       \
        Iodd_SetDdrBitTo ## value(PortName, PinNumber)

#define Iodd_SetDdrBitTo0(PortName, PinNumber)                           \
        TARG_ClearBits(GPIO_GDIR(PortName), ((ulong)1 << PinNumber))
#define Iodd_SetDdrBitTo1(PortName, PinNumber)                           \
        TARG_SetBits  (GPIO_GDIR(PortName), ((ulong)1 << PinNumber))


/*______ G L O B A L - M A C R O S ___________________________________________*/

/* PIN Description Macros-----------------------------------------------------*/


/*----------------------------------------------------------------------------*/
/* Name : IODD_PinSetUpInput                                                  */
/* Role : Set up a microcontroler pin to work as an input                     */
/* Interface :                                                                */
/*   - PortName    IN, name of port for : [1,2,3,4,5,6,7]                     */
/*   - PinNumber   IN, name of the selected pin use macros GPIO_PIN_PinName   */
/*   - PinMode     IN, use mode of the pin                                    */
/*                                         [IODD_STANDARD,                    */
/*                                          IODD_IT_RISING_EDGE,              */
/*                                          IODD_IT_FALLING_EDGE,             */
/*                                          IODD_IT_BOTH_EDGE,                */
/*                                          IODD_IT_LOW_LEVEL,                */
/*                                          IODD_IT_HIGH_LEVEL]               */
/*   - PullUpState IN, NOT USED                                               */
/* Pre-condition : -                                                          */
/* Constraints : -                                                            */
/* Behavior :                                                                 */
/*   DO                                                                       */
/*     [set up the pin as requested]                                          */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/
#define IODD_PinSetUpInput(PortName, PinNumber, PinMode, PullUpState)    \
        PinMode(PortName, PinNumber);                                    \
        Iodd_SetDdrBit(PortName, PinNumber, 0)

/*----------------------------------------------------------------------------*/
/*Name : IODD_PinSetUpOutput                                                  */
/*Role : Set up a microcontroler pin to work as an output                     */
/*Interface :                                                                 */
/*   - PortName    IN, name of port for : [1,2,3,4,5,6,7]                     */
/*   - PinNumber   OUT, name of the selected pin use macros GPIO_PIN_PinName  */
/*   - OpenDrainState IN, NOT USED                                            */
/*Pre-condition : -                                                           */
/*Constraints :  -                                                            */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [set up the pin as requested]                                           */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#define IODD_PinSetUpOutput(PortName, PinNumber, OpenDrainState)         \
        IODD_STANDARD(PortName, PinNumber);                              \
        Iodd_SetDdrBit(PortName, PinNumber, 1)

/*----------------------------------------------------------------------------*/
/* Name : IODD_SetPinDirectionIn                                              */
/* Role : Set direction register to set pin in input                          */
/* Interface :                                                                */
/*   - PortName    IN, name of port for : [1,2,3,4,5,6,7]                     */
/*   - PinNumber   IN, name of the selected pin use macros GPIO_PIN_PinName   */
/* Pre-condition : -                                                          */
/* Constraints : -                                                            */
/* Behavior :                                                                 */
/*   DO                                                                       */
/*     [set up the pin as requested]                                          */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/
#define IODD_SetPinDirectionIn(PortName, PinNumber)                      \
        Iodd_SetDdrBit(PortName, PinNumber, 0)

/*----------------------------------------------------------------------------*/
/* Name : IODD_SetPinDirectionOut                                             */
/* Role : Set direction register to set pin in output                         */
/* Interface :                                                                */
/*   - PortName    IN, name of port for : [1,2,3,4,5,6,7]                     */
/*   - PinNumber   IN, name of the selected pin use macros GPIO_PIN_PinName   */
/* Pre-condition : -                                                          */
/* Constraints : -                                                            */
/* Behavior :                                                                 */
/*   DO                                                                       */
/*     [set up the pin as requested]                                          */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/
#define IODD_SetPinDirectionOut(PortName, PinNumber)                     \
        Iodd_SetDdrBit(PortName, PinNumber, 1)

/*----------------------------------------------------------------------------*/
/*Name : IODD_SetPullUpData                                                   */
/*Role : Set the pull-up state                                                */
/*Interface :                                                                 */
/*   - PortName    NOT USED                                                   */
/*   - PinNumber   NOT USED                                                   */
/*Pre-condition : -                                                           */
/*Constraints :  -                                                            */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [Nothing: Pull-up and Pull-down are managed by IOMUX]                   */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#define IODD_SetPullUpData(PortName, PinNumber)

/*----------------------------------------------------------------------------*/
/*Name : IODD_SetPullDownData                                                 */
/*Role : Set the pull-down state                                              */
/*Interface :                                                                 */
/*   - PortName    NOT USED                                                   */
/*   - PinNumber   NOT USED                                                   */
/*Pre-condition : -                                                           */
/*Constraints :  -                                                            */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [Nothing: Pull-up and Pull-down are managed by IOMUX]                   */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#define IODD_SetPullDownData(PortName, PinNumber)

/*----------------------------------------------------------------------------*/
/* Name : IODD_EnableIrq                                                      */
/* Role : Enable interrupt request                                            */
/* Interface :                                                                */
/*   - IrqName     IN  Irq number [0..127]                                    */
/* Pre-condition : -                                                          */
/* Constraints : -                                                            */
/* Behavior :                                                                 */
/*   DO                                                                       */
/*     [enable interrupt requested]                                           */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/
#define IODD_EnableIrq(IrqName)                                          \
        Iodd_EnableIrq((IrqName / 4), (IrqName & 31))

#define Iodd_EnableIrq(IrqReg, IrqBit)                                   \
        Iodd_EnableIrq_ ## IrqReg(IrqBit)

#define Iodd_EnableIrq_0(IrqBit)                                         \
        TARG_WriteLong(TZIC_ENSET0, ((ulong)1 << IrqBit))
#define Iodd_EnableIrq_1(IrqBit)                                         \
        TARG_WriteLong(TZIC_ENSET1, ((ulong)1 << IrqBit))
#define Iodd_EnableIrq_2(IrqBit)                                         \
        TARG_WriteLong(TZIC_ENSET2, ((ulong)1 << IrqBit))
#define Iodd_EnableIrq_3(IrqBit)                                         \
        TARG_WriteLong(TZIC_ENSET3, ((ulong)1 << IrqBit))


/*----------------------------------------------------------------------------*/
/* Name : IODD_DisableIrq                                                     */
/* Role : Disable interrupt request                                           */
/* Interface :                                                                */
/*   - IrqName     IN  Irq number [0..127]                                    */
/* Pre-condition : -                                                          */
/* Constraints : -                                                            */
/* Behavior :                                                                 */
/*   DO                                                                       */
/*     [disable interrupt requested]                                          */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/
#define IODD_DisableIrq(IrqName)                                         \
        Iodd_DisableIrq((IrqName / 4), (IrqName & 31))

#define Iodd_DisableIrq(IrqReg, IrqBit)                                  \
        Iodd_DisableIrq_ ## IrqReg(IrqBit)

#define Iodd_DisableIrq_0(IrqBit)                                        \
        TARG_WriteLong(TZIC_ENCLEAR0, ((ulong)1 << IrqBit))
#define Iodd_DisableIrq_1(IrqBit)                                        \
        TARG_WriteLong(TZIC_ENCLEAR1, ((ulong)1 << IrqBit))
#define Iodd_DisableIrq_2(IrqBit)                                        \
        TARG_WriteLong(TZIC_ENCLEAR2, ((ulong)1 << IrqBit))
#define Iodd_DisableIrq_3(IrqBit)                                        \
        TARG_WriteLong(TZIC_ENCLEAR3, ((ulong)1 << IrqBit))

/*----------------------------------------------------------------------------*/
/* Name : IODD_ReadStatusIrq                                                  */
/* Role : Read interrupt request flag                                         */
/* Interface :                                                                */
/*   - IrqName     IN  Irq number [0..127]                                    */
/* Pre-condition : -                                                          */
/* Constraints : -                                                            */
/* Behavior :                                                                 */
/*   DO                                                                       */
/*     [read the interrupt status]                                            */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/
#define IODD_ReadStatusIrq(IrqName)                                      \
        Iodd_ReadStatusIrq((IrqName / 4), (IrqName & 31))

#define Iodd_ReadStatusIrq(IrqReg, IrqBit)                               \
        Iodd_ReadStatusIrq_ ## IrqReg(IrqBit)

#define Iodd_ReadStatusIrq_0(IrqBit)                                     \
        TARG_ReadLong(TZIC_SRCCLEAR0, ((ulong)1 << IrqBit))

/*----------------------------------------------------------------------------*/
/* Name : IODD_ClearStatusIrq                                                 */
/* Role : Clear interrupt request flag                                        */
/* Interface :                                                                */
/*   - IrqName     IN  Irq number [0..127]                                    */
/* Pre-condition : -                                                          */
/* Constraints : -                                                            */
/* Behavior :                                                                 */
/*   DO                                                                       */
/*     [nothing]                                                              */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/
#define IODD_ClearStatusIrq(IrqName)                                     \
        Iodd_ClearStatusIrq((IrqName / 4), (IrqName & 31))

#define Iodd_ClearStatusIrq(IrqReg, IrqBit)                              \
        Iodd_ClearStatusIrq_ ## IrqReg(IrqBit)

#define Iodd_ClearStatusIrq_0(IrqBit)                                    \
        TARG_WriteLong(TZIC_SRCCLEAR0, ((ulong)1 << IrqBit))
#define Iodd_ClearStatusIrq_1(IrqBit)                                    \
        TARG_WriteLong(TZIC_SRCCLEAR1, ((ulong)1 << IrqBit))
#define Iodd_ClearStatusIrq_2(IrqBit)                                    \
        TARG_WriteLong(TZIC_SRCCLEAR2, ((ulong)1 << IrqBit))
#define Iodd_ClearStatusIrq_3(IrqBit)                                    \
        TARG_WriteLong(TZIC_SRCCLEAR3, ((ulong)1 << IrqBit))


/*----------------------------------------------------------------------------*/
/*Name : IODD_SetOpenDrainData                                                */
/*Role : Set the open-drain state                                             */
/*Interface :                                                                 */
/*   - PortName    IN, name of port for : [1,2,3,4,5,6,7]                     */
/*   - PinNumber   IN, name of the selected pin use macros GPIO_PIN_PinName   */
/*   - State       IN, NOT USED                                               */
/*Pre-condition : -                                                           */
/*Constraints :  -                                                            */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [nothing]                                                               */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#define IODD_SetOpenDrainData(PortName, PinNumber)

/*----------------------------------------------------------------------------*/
/*Name : IODD_GetPinData                                                      */
/*Role : Get the pin state                                                    */
/*Interface :                                                                 */
/*   - PortName    IN, name of port for : [1,2,3,4,5,6,7]                     */
/*   - PinNumber   IN, name of the selected pin use macros GPIO_PIN_PinNam    */
/*   - State       OUT, state of the pin (IODD_HIGH, IODD_LOW)                */
/*Pre-condition : -                                                           */
/*Constraints :  -                                                            */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [get the pin state]                                                     */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#define IODD_GetPinData(PortName, PinNumber)                             \
        ((TARG_ReadLong(GPIO_PSR(PortName)) >> PinNumber) & 0x01)


/*----------------------------------------------------------------------------*/
/*Name : IODD_GetPinStatus                                                    */
/*Role : Get the status of the pin                                            */
/*Interface :                                                                 */
/*   - PortName    IN, name of port for : [1,2,3,4,5,6,7]                     */
/*   - PinNumber   IN, name of the selected pin use macros GPIO_PIN_PinName   */
/*   - State       OUT, NOT USED                                              */
/*Pre-condition : -                                                           */
/*Constraints :  -                                                            */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [nothing          ]                                                     */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#define IODD_GetPinStatus(PortName, PinNumber)                           \
        (ubyte)IODD_GetPinData(PortName, PinNumber)

/*----------------------------------------------------------------------------*/
/*Name : IODD_SetPinData                                                      */
/*Role : Set a state on the pin                                               */
/*Interface :                                                                 */
/*   - PortName    IN, name of port for : [1,2,3,4,5,6,7]                     */
/*   - PinNumber   IN, name of the selected pin use macros GPIO_PIN_PinName   */
/*   - State       IN, requested output state of the pin [IODD_HIGH, IODD_LOW]*/
/*Pre-condition : -                                                           */
/*Constraints :  -                                                            */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [set the requested state on the pin]                                    */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#define IODD_SetPinData(PortName, PinNumber, State)                      \
        if (State == 0)                                                  \
        {                                                                \
          Iodd_SetPinDataTo0(PortName, PinNumber);                       \
        }                                                                \
        else                                                             \
        {                                                                \
          Iodd_SetPinDataTo1(PortName, PinNumber);                       \
        }

#define Iodd_SetPinDataTo0(PortName, PinNumber)                          \
        TARG_ClearBits(GPIO_DR(PortName), ((ulong)1 << PinNumber))

#define Iodd_SetPinDataTo1(PortName, PinNumber)                          \
        TARG_SetBits(GPIO_DR(PortName), ((ulong)1 << PinNumber))


/******************************************************************************/
/*Name : IODD_Init                                                            */
/*Role : this function initialises the I/O Port driver                        */
/*Interface :     void                                                        */
/*Pre-condition : none                                                        */
/*Constraints :   none                                                        */
/******************************************************************************/
extern void IODD_Init(void);

#endif /* __FSL_IMX53x__,__FSL_IMX6x__ */

/***** MICRO IMX 53 ***********************************************************/


/*________ G L O B A L - F U N C T I O N S ___________________________________*/
#if defined(__NEC_V850_DL3) || defined(__NEC_V850_DJ3)
/*----------------------------------------------------------------------------*/
/*Name : IODD_SetPortOutputPinData                                            */
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
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [set the requested state on the pin]                                    */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
extern void IODD_SetPortOutputPinData(ubyte PortNumber, ubyte PinNumber, ubyte State);

/*----------------------------------------------------------------------------*/
/*Name : IODD_GetPortOutputPinData                                            */
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
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [return state on the pin]                                               */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
extern bool_t IODD_GetPortOutputPinData(ubyte PortNumber,ubyte PinNumber);
#endif /* defined(__NEC_V850_DL3) || defined(__NEC_V850_DJ3) */

#ifdef __REL_V850_Dx4__
/*----------------------------------------------------------------------------*/
/*Name : IODD_SetPortOutputPinData                                            */
/*Role : Set a state on the pin of a port in uotput mode                      */
/*Interface :                                                                 */
/*  - PortNumber IN, Number of port for :                                     */
/*                                    NEC V850 Dx4                            */
/*                                    [0,1,2,3,4,10,16,17]                    */
/*                                                                            */
/*  - PinNumber IN, number of the selected pin [0..15]                        */
/*  - State     IN, requested output state of the pin [0, 1]                  */
/*Pre-condition : -                                                           */
/*Constraints :  -                                                            */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [set the requested state on the pin]                                    */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
extern void IODD_SetPortOutputPinData(ubyte PortNumber, ushort PinNumber, ubyte State);

/*----------------------------------------------------------------------------*/
/*Name : IODD_GetPortOutputPinData                                            */
/*Role : Get the state of a pin of a port in uotput mode                      */
/*Interface :                                                                 */
/*  - PortNumber IN, Number of port for :                                     */
/*                                    NEC V850 Dx4                            */
/*                                    [0,1,2,3,4,10,16,17]                    */
/*                                                                            */
/*  - PinNumber IN, number of the selected pin [0..7]                         */
/*  - State     OUT, state of the pin (0, 1)                                  */
/*Pre-condition : -                                                           */
/*Constraints :  -                                                            */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [return state on the pin]                                               */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
extern bool_t IODD_GetPortOutputPinData(ubyte PortNumber,ubyte PinNumber);
#endif /* __REL_V850_Dx4__ */


/***** Renesas REL_RL78 *******************************************************/
#ifdef __REL_RL78__
#if ((defined(__REL_RL78_D1x__))||(defined(__REL_RL78_F1x__)))
#if ((defined(__REL_RL78_D1A__))||(defined(__REL_RL78_F12__)))

/*______ I N C L U D E - F I L E S ___________________________________________*/

#include "syst.h"
#include "targ.h"


/*______ G L O B A L - D E F I N E S _________________________________________*/

#define IODD_HIGH ((ubyte) 1)
#define IODD_LOW  ((ubyte) 0)


/*______ G L O B A L - T Y P E S _____________________________________________*/


/*_____GLOBAL-DATA____________________________________________________________*/


/*______ P R I V A T E - M A C R O S _________________________________________*/


/* port / bit mask name definition ------------------------------------------ */
#define Iodd_WriteRegisterName(PortName,reg) reg ## PortName
#define Iodd_WriteBitPortDirection(PortName,PinNumber,Value) \
        TARG_WriteBit(PM ## PortName,PORT_BIT_PM ## PortName ## PinNumber,Value)

/* Open-drain control ------------------------------------------------------- */

/* Interrupt Sense Control -------------------------------------------------- */
#ifdef __REL_RL78_D1A__
#define PORT17(EgpValue,EgnValue) \
    TARG_WriteBit(EGP0, INT_BIT_EGP0, EgpValue); \
        TARG_WriteBit(EGN0, INT_BIT_EGN0, EgnValue)
#define PORT60(EgpValue,EgnValue) \
    TARG_WriteBit(EGP0, INT_BIT_EGP1, EgpValue); \
        TARG_WriteBit(EGN0, INT_BIT_EGN1, EgnValue)
#define PORT12(EgpValue,EgnValue) \
    TARG_WriteBit(EGP0, INT_BIT_EGP2, EgpValue); \
        TARG_WriteBit(EGN0, INT_BIT_EGN2, EgnValue)
#define PORT61(EgpValue,EgnValue) \
    TARG_WriteBit(EGP0, INT_BIT_EGP3, EgpValue); \
        TARG_WriteBit(EGN0, INT_BIT_EGN3, EgnValue)
#define PORT10(EgpValue,EgnValue) \
    TARG_WriteBit(EGP0, INT_BIT_EGP4, EgpValue); \
        TARG_WriteBit(EGN0, INT_BIT_EGN4, EgnValue)
#define PORT137(EgpValue,EgnValue) \
    TARG_WriteBit(EGP0, INT_BIT_EGP5, EgpValue); \
        TARG_WriteBit(EGN0, INT_BIT_EGN5, EgnValue)



#define PORT1(PinNumber,EgpValue,EgnValue) \
        PORT1 ## PinNumber(EgpValue,EgnValue)
#define PORT6(PinNumber,EgpValue,EgnValue) \
        PORT6 ## PinNumber(EgpValue,EgnValue)
#define PORT13(PinNumber,EgpValue,EgnValue) \
        PORT13 ## PinNumber(EgpValue,EgnValue)
#define PORT7(PinNumber,EgpValue,EgnValue) \
        PORT7 ## PinNumber(EgpValue,EgnValue)
#endif /* __REL_RL78_D1A__ */

#ifdef __REL_RL78_F12__
#define PORT137(EgpValue,EgnValue) \
    TARG_WriteBit(EGP0, INT_BIT_EGP0, EgpValue); \
        TARG_WriteBit(EGN0, INT_BIT_EGN0, EgnValue)
#define PORT50(EgpValue,EgnValue) \
    TARG_WriteBit(EGP0, INT_BIT_EGP1, EgpValue); \
        TARG_WriteBit(EGN0, INT_BIT_EGN1, EgnValue)
#define PORT51(EgpValue,EgnValue) \
    TARG_WriteBit(EGP0, INT_BIT_EGP2, EgpValue); \
        TARG_WriteBit(EGN0, INT_BIT_EGN2, EgnValue)
#define PORT30(EgpValue,EgnValue) \
    TARG_WriteBit(EGP0, INT_BIT_EGP3, EgpValue); \
        TARG_WriteBit(EGN0, INT_BIT_EGN3, EgnValue)
#define PORT31(EgpValue,EgnValue) \
    TARG_WriteBit(EGP0, INT_BIT_EGP4, EgpValue); \
        TARG_WriteBit(EGN0, INT_BIT_EGN4, EgnValue)
#define PORT16(EgpValue,EgnValue) \
    TARG_WriteBit(EGP0, INT_BIT_EGP5, EgpValue); \
        TARG_WriteBit(EGN0, INT_BIT_EGN5, EgnValue)
#define PORT140(EgpValue,EgnValue) \
    TARG_WriteBit(EGP0, INT_BIT_EGP6, EgpValue); \
        TARG_WriteBit(EGN0, INT_BIT_EGN6, EgnValue)
#define PORT141(EgpValue,EgnValue) \
    TARG_WriteBit(EGP0, INT_BIT_EGP7, EgpValue); \
        TARG_WriteBit(EGN0, INT_BIT_EGN7, EgnValue)
#define PORT74(EgpValue,EgnValue) \
    TARG_WriteBit(EGP1, INT_BIT_EGP8, EgpValue); \
        TARG_WriteBit(EGN1, INT_BIT_EGN8, EgnValue)
#define PORT75(EgpValue,EgnValue) \
    TARG_WriteBit(EGP1, INT_BIT_EGP9, EgpValue); \
        TARG_WriteBit(EGN1, INT_BIT_EGN9, EgnValue)
#define PORT76(EgpValue,EgnValue) \
    TARG_WriteBit(EGP1, INT_BIT_EGP10, EgpValue); \
        TARG_WriteBit(EGN1, INT_BIT_EGN10, EgnValue)
#define PORT77(EgpValue,EgnValue) \
    TARG_WriteBit(EGP1, INT_BIT_EGP11, EgpValue); \
        TARG_WriteBit(EGN1, INT_BIT_EGN11, EgnValue)

#define PORT1(PinNumber,EgpValue,EgnValue) \
        PORT1 ## PinNumber(EgpValue,EgnValue)
#define PORT3(PinNumber,EgpValue,EgnValue) \
        PORT3 ## PinNumber(EgpValue,EgnValue)
#define PORT5(PinNumber,EgpValue,EgnValue) \
        PORT5 ## PinNumber(EgpValue,EgnValue)
#define PORT7(PinNumber,EgpValue,EgnValue) \
        PORT7 ## PinNumber(EgpValue,EgnValue)
#define PORT13(PinNumber,EgpValue,EgnValue) \
        PORT13 ## PinNumber(EgpValue,EgnValue)
#define PORT14(PinNumber,EgpValue,EgnValue) \
        PORT14 ## PinNumber(EgpValue,EgnValue)

#endif /* __REL_RL78_F12__ */


/* Input Pin Mode ----------------------------------------------------------- */
#define IODD_IT_FALLING_EDGE(IscrAccess,PinNumber) \
        PORT ## IscrAccess(PinNumber,0,1)

#define IODD_IT_RISING_EDGE(IscrAccess,PinNumber) \
        PORT ## IscrAccess(PinNumber,1,0)

#define IODD_IT_BOTH_EDGE(IscrAccess,PinNumber) \
        PORT ## IscrAccess(PinNumber,1,1)

#define IODD_STANDARD(IscrAccess,PinNumber)

/* Pull-device control ------------------------------------------------------ */
#ifdef __REL_RL78_D1A__
/* PU0,PU1,PU3~PU9,PU13,PU14 */

#define PORT_PU_P0(PortName,PinNumber) \
    TARG_WriteBit(PU ## PortName, PORT_BIT_PU ## PortName ## PinNumber, 1)
#define PORT_PU_P1(PortName,PinNumber) \
    TARG_WriteBit(PU ## PortName, PORT_BIT_PU ## PortName ## PinNumber, 1)
#define PORT_PU_P2(PortName,PinNumber)
#define PORT_PU_P3(PortName,PinNumber) \
    TARG_WriteBit(PU ## PortName, PORT_BIT_PU ## PortName ## PinNumber, 1)
#define PORT_PU_P4(PortName,PinNumber) \
    TARG_WriteBit(PU ## PortName, PORT_BIT_PU ## PortName ## PinNumber, 1)
#define PORT_PU_P5(PortName,PinNumber) \
    TARG_WriteBit(PU ## PortName, PORT_BIT_PU ## PortName ## PinNumber, 1)
#define PORT_PU_P6(PortName,PinNumber) \
    TARG_WriteBit(PU ## PortName, PORT_BIT_PU ## PortName ## PinNumber, 1)
#define PORT_PU_P7(PortName,PinNumber) \
    TARG_WriteBit(PU ## PortName, PORT_BIT_PU ## PortName ## PinNumber, 1)
#define PORT_PU_P8(PortName,PinNumber) \
    TARG_WriteBit(PU ## PortName, PORT_BIT_PU ## PortName ## PinNumber, 1)
#define PORT_PU_P9(PortName,PinNumber) \
    TARG_WriteBit(PU ## PortName, PORT_BIT_PU ## PortName ## PinNumber, 1)
#define PORT_PU_P10(PortName,PinNumber)
#define PORT_PU_P11(PortName,PinNumber)
#define PORT_PU_P12(PortName,PinNumber)
#define PORT_PU_P13(PortName,PinNumber) \
    TARG_WriteBit(PU ## PortName, PORT_BIT_PU ## PortName ## PinNumber, 1)
#define PORT_PU_P14(PortName,PinNumber) \
    TARG_WriteBit(PU ## PortName, PORT_BIT_PU ## PortName ## PinNumber, 1)
#define PORT_PU_P15(PortName,PinNumber)
#endif /* __REL_RL78_D1A__ */

#ifdef __REL_RL78_F12__
/* PU0,PU1,PU3~PU5,PU7,PU12,PU14 */

#define PORT_PU_P0(PortName,PinNumber) \
    TARG_WriteBit(PU ## PortName, PORT_BIT_PU ## PortName ## PinNumber, 1)

#define PORT_PU_P1(PortName,PinNumber) \
    TARG_WriteBit(PU ## PortName, PORT_BIT_PU ## PortName ## PinNumber, 1)

#define PORT_PU_P2(PortName,PinNumber)
#define PORT_PU_P3(PortName,PinNumber) \
    TARG_WriteBit(PU ## PortName, PORT_BIT_PU ## PortName ## PinNumber, 1)

#define PORT_PU_P4(PortName,PinNumber) \
    TARG_WriteBit(PU ## PortName, PORT_BIT_PU ## PortName ## PinNumber, 1)

#define PORT_PU_P5(PortName,PinNumber) \
    TARG_WriteBit(PU ## PortName, PORT_BIT_PU ## PortName ## PinNumber, 1)

#define PORT_PU_P6(PortName,PinNumber)

#define PORT_PU_P7(PortName,PinNumber) \
    TARG_WriteBit(PU ## PortName, PORT_BIT_PU ## PortName ## PinNumber, 1)
#define PORT_PU_P12(PortName,PinNumber) \
    TARG_WriteBit(PU ## PortName, PORT_BIT_PU ## PortName ## PinNumber, 1)
#define PORT_PU_P13(PortName,PinNumber)

#define PORT_PU_P14(PortName,PinNumber) \
    TARG_WriteBit(PU ## PortName, PORT_BIT_PU ## PortName ## PinNumber, 1)
#endif /* __REL_RL78_F12__ */

#define Iodd_SetPullUpBit(PortName,PinNumber) \
        PORT_PU_P ## PortName(PortName,PinNumber)

#define Iodd_SetPullDownBit(PortName,PinNumber)

/* Input Pull Up Mode ------------------------------------------------------- */
#define IODD_NO_PULL_UP(PortName,PinNumber)

#define IODD_PULL_UP(PortName,PinNumber) \
        Iodd_SetPullUpBit(PortName,PinNumber)

/* Output Open Drain State -------------------------------------------------- */
#define IODD_OPEN_DRAIN(PortName,PinNumber)
#define IODD_NO_OPEN_DRAIN(PortName,PinNumber)

/* Set one bit in a port direction register --------------------------------- */
#ifdef __REL_RL78_D1A__
/* P0~P9,P13~P15 */
#define PORT_DDR_P0(PortName,PinNumber,value) \
        Iodd_WriteBitPortDirection(PortName,PinNumber,value)
#define PORT_DDR_P1(PortName,PinNumber,value) \
        Iodd_WriteBitPortDirection(PortName,PinNumber,value)
#define PORT_DDR_P2(PortName,PinNumber,value) \
        Iodd_WriteBitPortDirection(PortName,PinNumber,value)
#define PORT_DDR_P3(PortName,PinNumber,value) \
        Iodd_WriteBitPortDirection(PortName,PinNumber,value)
#define PORT_DDR_P4(PortName,PinNumber,value) \
        Iodd_WriteBitPortDirection(PortName,PinNumber,value)
#define PORT_DDR_P5(PortName,PinNumber,value) \
        Iodd_WriteBitPortDirection(PortName,PinNumber,value)
#define PORT_DDR_P6(PortName,PinNumber,value) \
        Iodd_WriteBitPortDirection(PortName,PinNumber,value)
#define PORT_DDR_P7(PortName,PinNumber,value) \
        Iodd_WriteBitPortDirection(PortName,PinNumber,value)
#define PORT_DDR_P8(PortName,PinNumber,value) \
        Iodd_WriteBitPortDirection(PortName,PinNumber,value)
#define PORT_DDR_P9(PortName,PinNumber,value) \
        Iodd_WriteBitPortDirection(PortName,PinNumber,value)
#define PORT_DDR_P10(PortName,PinNumber,value)
#define PORT_DDR_P11(PortName,PinNumber,value)
#define PORT_DDR_P12(PortName,PinNumber,value)
#define PORT_DDR_P13(PortName,PinNumber,value) \
        Iodd_WriteBitPortDirection(PortName,PinNumber,value)
#define PORT_DDR_P14(PortName,PinNumber,value) \
        Iodd_WriteBitPortDirection(PortName,PinNumber,value)
#define PORT_DDR_P15(PortName,PinNumber,value) \
        Iodd_WriteBitPortDirection(PortName,PinNumber,value)
#endif /* __REL_RL78_D1A__ */

#ifdef __REL_RL78_F12__
/* P0~P7,P12,P14 */
#define PORT_DDR_P0(PortName,PinNumber,value) \
        Iodd_WriteBitPortDirection(PortName,PinNumber,value)
#define PORT_DDR_P1(PortName,PinNumber,value) \
        Iodd_WriteBitPortDirection(PortName,PinNumber,value)
#define PORT_DDR_P2(PortName,PinNumber,value) \
        Iodd_WriteBitPortDirection(PortName,PinNumber,value)
#define PORT_DDR_P3(PortName,PinNumber,value) \
        Iodd_WriteBitPortDirection(PortName,PinNumber,value)
#define PORT_DDR_P4(PortName,PinNumber,value) \
        Iodd_WriteBitPortDirection(PortName,PinNumber,value)
#define PORT_DDR_P5(PortName,PinNumber,value) \
        Iodd_WriteBitPortDirection(PortName,PinNumber,value)
#define PORT_DDR_P6(PortName,PinNumber,value) \
        Iodd_WriteBitPortDirection(PortName,PinNumber,value)
#define PORT_DDR_P7(PortName,PinNumber,value) \
        Iodd_WriteBitPortDirection(PortName,PinNumber,value)
#define PORT_DDR_P12(PortName,PinNumber,value) \
        Iodd_WriteBitPortDirection(PortName,PinNumber,value)
#define PORT_DDR_P13(PortName,PinNumber,value)
#define PORT_DDR_P14(PortName,PinNumber,value) \
        Iodd_WriteBitPortDirection(PortName,PinNumber,value)
#endif /* __REL_RL78_F12__ */

#define Iodd_SetDdrBit(PortName,PinNumber,value) \
        PORT_DDR_P ## PortName(PortName,PinNumber,value)


#define Iodd_DisableLcdPin(PortName,PinNumber) \
        TARG_ClearBits(LCDPF ## PortName,PORT_MSK_PF ## PortName ## PinNumber)


#ifdef __REL_RL78_D1A__
#define PORT_DISABLE_LCD_P0(PortName,PinNumber) \
        Iodd_DisableLcdPin(PortName,PinNumber)
#define PORT_DISABLE_LCD_P1(PortName,PinNumber) \
        Iodd_DisableLcdPin(PortName,PinNumber)
#define PORT_DISABLE_LCD_P2(PortName,PinNumber)
#define PORT_DISABLE_LCD_P3(PortName,PinNumber) \
        Iodd_DisableLcdPin(PortName,PinNumber)
#define PORT_DISABLE_LCD_P4(PortName,PinNumber)
#define PORT_DISABLE_LCD_P5(PortName,PinNumber) \
        Iodd_DisableLcdPin(PortName,PinNumber)
#define PORT_DISABLE_LCD_P6(PortName,PinNumber)
#define PORT_DISABLE_LCD_P7(PortName,PinNumber) \
        Iodd_DisableLcdPin(PortName,PinNumber)
#define PORT_DISABLE_LCD_P8(PortName,PinNumber) \
        Iodd_DisableLcdPin(PortName,PinNumber)
#define PORT_DISABLE_LCD_P9(PortName,PinNumber) \
        Iodd_DisableLcdPin(PortName,PinNumber)
#define PORT_DISABLE_LCD_P12(PortName,PinNumber)
#define PORT_DISABLE_LCD_P13(PortName,PinNumber) \
        Iodd_DisableLcdPin(PortName,PinNumber)
#define PORT_DISABLE_LCD_P14(PortName,PinNumber)
#endif /*__REL_RL78_D1A__ */

#ifdef __REL_RL78_F12__
#define PORT_DISABLE_LCD_P0(PortName,PinNumber)
#define PORT_DISABLE_LCD_P1(PortName,PinNumber)
#define PORT_DISABLE_LCD_P2(PortName,PinNumber)
#define PORT_DISABLE_LCD_P3(PortName,PinNumber)
#define PORT_DISABLE_LCD_P4(PortName,PinNumber)
#define PORT_DISABLE_LCD_P5(PortName,PinNumber)
#define PORT_DISABLE_LCD_P6(PortName,PinNumber)
#define PORT_DISABLE_LCD_P7(PortName,PinNumber)
#define PORT_DISABLE_LCD_P12(PortName,PinNumber)
#define PORT_DISABLE_LCD_P13(PortName,PinNumber)
#define PORT_DISABLE_LCD_P14(PortName,PinNumber)
#endif /*__REL_RL78_F12__ */

#define Iodd_DisableLcdFunction(PortName,PinNumber) \
        PORT_DISABLE_LCD_P ## PortName(PortName,PinNumber)

/* Get one bit in a port input register ------------------------------------- */

/* Get one port status bit -------------------------------------------------- */
/* Set one bit in a port output register */
#define Iodd_SetOutputReg(PortName,PinNumber,State) \
        TARG_WriteBit(P ## PortName, PORT_BIT_P ## PortName ## PinNumber, State)
#define Iodd_GetOutputReg(PortName,PinNumber) \
        TARG_ReadBit(P ## PortName, PORT_BIT_P ## PortName ## PinNumber)

/*_____GLOBAL-MACROS__________________________________________________________*/

/*----------------------------------------------------------------------------*/
/* Name : IODD_PinSetUpInput                                                  */
/* Role : Set up a microcontroler pin to work as an input                     */
/* Interface :                                                                */
/*   - PortName    IN, name of port for RL78 D1A: [0,1,2,3,4,5,6,7,8,9,10,    */
/*                                                 11,12,13,                  */
/*                                                 P14(100 PIN),P15(100 PIN)] */
/*   - PortName    IN, name of port for RL78 F12: [0,1,2,3,4,5,6,7,12,13,14]  */
/*   - PinNumber   IN, number of the selected pin:                            */
/*                                       [0..7]                               */
/*   - PinMode     IN, use mode of the pin [IODD_STANDARD,                    */
/*                                          IODD_IT_RISING_EDGE,              */
/*                                          IODD_IT_FALLING_EDGE,             */
/*                                          IODD_IT_BOTH_EDGE,                */
/*                                          IODD_IT_LOW_LEVEL]                */
/*   - PullUpState IN, state of the pull-up on the pin,                       */
/*                     if the pin has a pull-up [IODD_PULL_UP,                */
/*                                               IODD_NO_PULL_UP]             */
/* Pre-condition : -                                                          */
/* Constraints : -                                                            */
/* Behavior :                                                                 */
/*   DO                                                                       */
/*     [set up the pin as requested]                                          */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/

#define IODD_PinSetUpInput(PortName,\
                           PinNumber,\
                           PinMode,\
                           PullUpState) \
        Iodd_DisableLcdFunction(PortName,PinNumber);  \
        Iodd_SetDdrBit(PortName,PinNumber,1);\
        PinMode(PortName,PinNumber);\
        PullUpState(PortName,PinNumber)

/*----------------------------------------------------------------------------*/
/*Name : IODD_PinSetUpOutput                                                  */
/*Role : Set up a microcontroler pin to work as an output                     */
/*Interface :                                                                 */
/*   - PortName    IN, name of port for RL78 D1A: [0,1,2,3,4,5,6,7,8,9,10,    */
/*                                                 11,12,13,                  */
/*                                                 P14(100 PIN),P15(100 PIN)] */
/*   - PortName    IN, name of port for RL78 F12: [0,1,2,3,4,5,6,7,12,13,14]  */
/*  - PinNumber      IN, number of the selected pin                           */
/*                                       [0..7]                               */
/*  - OpenDrainState IN : state of the High-Impedance on the pin              */
/*                       [IODD_NO_HIGH_Z, IODD_HIGH_Z,                        */
/*                        IODD_NO_OPEN_DRAIN, IODD_OPEN_DRAIN]                */
/*Pre-condition : -                                                           */
/*Constraints :  -                                                            */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [set up the pin as requested]                                           */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#define IODD_PinSetUpOutput(PortName,\
                            PinNumber,\
                            OpenDrainState) \
        Iodd_DisableLcdFunction(PortName,PinNumber);  \
        Iodd_SetDdrBit(PortName,PinNumber,0);\
        OpenDrainState(PortName,PinNumber)

/*----------------------------------------------------------------------------*/
/* Name : IODD_EnableIrq                                                      */
/* Role : Enable interrupt request                                            */
/* Interface :                                                                */
/*   - IrqName IN, name of Irq for RL78 D1A:   [IODD_IRQ0..IODD_IRQ5]         */
/*   - IrqName IN, name of Irq for RL78 F12:   [IODD_IRQ0..IODD_IRQ11]        */
/* Pre-condition : -                                                          */
/* Constraints : -                                                            */
/* Behavior :                                                                 */
/*   DO                                                                       */
/*     [enable interrupt requested]                                           */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/
#define IODD_EnableIrq(IrqName) IODD_EnableIrq_ ## IrqName

#ifdef __REL_RL78_D1x__
#ifdef __REL_RL78_D1A__
#define IODD_EnableIrq_IODD_IRQ0  TARG_WriteBit(MK0L,INT_BIT_PMK0,0)
#define IODD_EnableIrq_IODD_IRQ1  TARG_WriteBit(MK0L,INT_BIT_PMK1,0)
#define IODD_EnableIrq_IODD_IRQ2  TARG_WriteBit(MK0L,INT_BIT_PMK2,0)
#define IODD_EnableIrq_IODD_IRQ3  TARG_WriteBit(MK0L,INT_BIT_PMK3,0)
#define IODD_EnableIrq_IODD_IRQ4  TARG_WriteBit(MK0L,INT_BIT_PMK4,0)
#define IODD_EnableIrq_IODD_IRQ5  TARG_WriteBit(MK0L,INT_BIT_PMK5,0)
#endif /* __REL_RL78_D1A__ */
#endif /* __REL_RL78_D1x__ */

#ifdef __REL_RL78_F1x__
#ifdef __REL_RL78_F12__
#define IODD_EnableIrq_IODD_IRQ0  TARG_WriteBit(MK0L,INT_BIT_PMK0,0)
#define IODD_EnableIrq_IODD_IRQ1  TARG_WriteBit(MK0L,INT_BIT_PMK1,0)
#define IODD_EnableIrq_IODD_IRQ2  TARG_WriteBit(MK0L,INT_BIT_PMK2,0)
#define IODD_EnableIrq_IODD_IRQ3  TARG_WriteBit(MK0L,INT_BIT_PMK3,0)
#define IODD_EnableIrq_IODD_IRQ4  TARG_WriteBit(MK0L,INT_BIT_PMK4,0)
#define IODD_EnableIrq_IODD_IRQ5  TARG_WriteBit(MK0L,INT_BIT_PMK5,0)
#define IODD_EnableIrq_IODD_IRQ6  TARG_WriteBit(MK2L,INT_BIT_PMK6,0)
#define IODD_EnableIrq_IODD_IRQ7  TARG_WriteBit(MK2L,INT_BIT_PMK7,0)
#define IODD_EnableIrq_IODD_IRQ8  TARG_WriteBit(MK2L,INT_BIT_PMK8,0)
#define IODD_EnableIrq_IODD_IRQ9  TARG_WriteBit(MK2L,INT_BIT_PMK9,0)
#define IODD_EnableIrq_IODD_IRQ10  TARG_WriteBit(MK2L,INT_BIT_PMK10,0)
#define IODD_EnableIrq_IODD_IRQ11  TARG_WriteBit(MK2H,INT_BIT_PMK11,0)
#endif /* __REL_RL78_F12__ */
#endif /* __REL_RL78_F1x__ */


/*----------------------------------------------------------------------------*/
/* Name : IODD_DisableIrq                                                     */
/* Role : Disable interrupt request                                           */
/* Interface :                                                                */
/*   - IrqName IN, name of Irq for RL78 D1A:   [IODD_IRQ0..IODD_IRQ5]         */
/*   - IrqName IN, name of Irq for RL78 F12:   [IODD_IRQ0..IODD_IRQ11]        */
/* Pre-condition : -                                                          */
/* Constraints : -                                                            */
/* Behavior :                                                                 */
/*   DO                                                                       */
/*     [disable interrupt requested]                                          */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/
#define IODD_DisableIrq(IrqName) IODD_DisableIrq_ ## IrqName

#ifdef __REL_RL78_D1x__
#ifdef __REL_RL78_D1A__
#define IODD_DisableIrq_IODD_IRQ0  TARG_WriteBit(MK0L,INT_BIT_PMK0,1)
#define IODD_DisableIrq_IODD_IRQ1  TARG_WriteBit(MK0L,INT_BIT_PMK1,1)
#define IODD_DisableIrq_IODD_IRQ2  TARG_WriteBit(MK0L,INT_BIT_PMK2,1)
#define IODD_DisableIrq_IODD_IRQ3  TARG_WriteBit(MK0L,INT_BIT_PMK3,1)
#define IODD_DisableIrq_IODD_IRQ4  TARG_WriteBit(MK0L,INT_BIT_PMK4,1)
#define IODD_DisableIrq_IODD_IRQ5  TARG_WriteBit(MK0L,INT_BIT_PMK5,1)
#endif /* __REL_RL78_D1A__ */
#endif /* __REL_RL78_D1x__ */

#ifdef __REL_RL78_F1x__
#ifdef __REL_RL78_F12__
#define IODD_DisableIrq_IODD_IRQ0  TARG_WriteBit(MK0L,INT_BIT_PMK0,1)
#define IODD_DisableIrq_IODD_IRQ1  TARG_WriteBit(MK0L,INT_BIT_PMK1,1)
#define IODD_DisableIrq_IODD_IRQ2  TARG_WriteBit(MK0L,INT_BIT_PMK2,1)
#define IODD_DisableIrq_IODD_IRQ3  TARG_WriteBit(MK0L,INT_BIT_PMK3,1)
#define IODD_DisableIrq_IODD_IRQ4  TARG_WriteBit(MK0L,INT_BIT_PMK4,1)
#define IODD_DisableIrq_IODD_IRQ5  TARG_WriteBit(MK0L,INT_BIT_PMK5,1)
#define IODD_DisableIrq_IODD_IRQ6  TARG_WriteBit(MK2L,INT_BIT_PMK6,1)
#define IODD_DisableIrq_IODD_IRQ7  TARG_WriteBit(MK2L,INT_BIT_PMK7,1)
#define IODD_DisableIrq_IODD_IRQ8  TARG_WriteBit(MK2L,INT_BIT_PMK8,1)
#define IODD_DisableIrq_IODD_IRQ9  TARG_WriteBit(MK2L,INT_BIT_PMK9,1)
#define IODD_DisableIrq_IODD_IRQ10  TARG_WriteBit(MK2L,INT_BIT_PMK10,1)
#define IODD_DisableIrq_IODD_IRQ11  TARG_WriteBit(MK2H,INT_BIT_PMK11,1)
#endif /* __REL_RL78_F12__ */
#endif /* __REL_RL78_F1x__ */

/*----------------------------------------------------------------------------*/
/* Name : IODD_ReadStatusIrq                                                  */
/* Role : Read interrupt request flag                                         */
/* Interface :                                                                */
/*   - IrqName IN, name of Irq for RL78 D1A:   [IODD_IRQ0..IODD_IRQ5]         */
/*   - IrqName IN, name of Irq for RL78 F12:   [IODD_IRQ0..IODD_IRQ11]        */
/* Pre-condition : -                                                          */
/* Constraints : -                                                            */
/* Behavior :                                                                 */
/*   DO                                                                       */
/*     [read the interrupt status]                                            */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/
#define IODD_ReadStatusIrq(IrqName) IODD_ReadStatusIrq_ ## IrqName

#ifdef __REL_RL78_D1x__
#ifdef __REL_RL78_D1A__
#define IODD_ReadStatusIrq_IODD_IRQ0  TARG_ReadBit(IF0L,INT_BIT_PIF0)
#define IODD_ReadStatusIrq_IODD_IRQ1  TARG_ReadBit(IF0L,INT_BIT_PIF1)
#define IODD_ReadStatusIrq_IODD_IRQ2  TARG_ReadBit(IF0L,INT_BIT_PIF2)
#define IODD_ReadStatusIrq_IODD_IRQ3  TARG_ReadBit(IF0L,INT_BIT_PIF3)
#define IODD_ReadStatusIrq_IODD_IRQ4  TARG_ReadBit(IF0L,INT_BIT_PIF4)
#define IODD_ReadStatusIrq_IODD_IRQ5  TARG_ReadBit(IF0L,INT_BIT_PIF5)
#endif /* __REL_RL78_D1A__ */
#endif /* __REL_RL78_D1x__ */

#ifdef __REL_RL78_F1x__
#ifdef __REL_RL78_F12__
#define IODD_ReadStatusIrq_IODD_IRQ0  TARG_ReadBit(IF0L,INT_BIT_PIF0)
#define IODD_ReadStatusIrq_IODD_IRQ1  TARG_ReadBit(IF0L,INT_BIT_PIF1)
#define IODD_ReadStatusIrq_IODD_IRQ2  TARG_ReadBit(IF0L,INT_BIT_PIF2)
#define IODD_ReadStatusIrq_IODD_IRQ3  TARG_ReadBit(IF0L,INT_BIT_PIF3)
#define IODD_ReadStatusIrq_IODD_IRQ4  TARG_ReadBit(IF0L,INT_BIT_PIF4)
#define IODD_ReadStatusIrq_IODD_IRQ5  TARG_ReadBit(IF0L,INT_BIT_PIF5)
#define IODD_ReadStatusIrq_IODD_IRQ6  TARG_ReadBit(IF2L,INT_BIT_PIF6)
#define IODD_ReadStatusIrq_IODD_IRQ7  TARG_ReadBit(IF2L,INT_BIT_PIF7)
#define IODD_ReadStatusIrq_IODD_IRQ8  TARG_ReadBit(IF2L,INT_BIT_PIF8)
#define IODD_ReadStatusIrq_IODD_IRQ9  TARG_ReadBit(IF2L,INT_BIT_PIF9)
#define IODD_ReadStatusIrq_IODD_IRQ10  TARG_ReadBit(IF2L,INT_BIT_PIF10)
#define IODD_ReadStatusIrq_IODD_IRQ11  TARG_ReadBit(IF2H,INT_BIT_PIF11)
#endif /* __REL_RL78_F12__ */
#endif /* __REL_RL78_F1x__ */

/*----------------------------------------------------------------------------*/
/* Name : IODD_ClearStatusIrq                                                 */
/* Role : Clear interrupt request flag                                        */
/* Interface :                                                                */
/*   - IrqName IN, name of Irq for RL78 D1A :   [IODD_IRQ0..IODD_IRQ5]        */
/*   - IrqName IN, name of Irq for RL78 F12 :   [IODD_IRQ0..IODD_IRQ11]       */
/* Pre-condition : -                                                          */
/* Constraints : -                                                            */
/* Behavior :                                                                 */
/*   DO                                                                       */
/*     [Clear the interrupt status]                                           */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/
#define IODD_ClearStatusIrq(IrqName) IODD_ClearStatusIrq_ ## IrqName
#ifdef __REL_RL78_D1x__
#ifdef __REL_RL78_D1A__
#define IODD_ClearStatusIrq_IODD_IRQ0  TARG_WriteBit(IF0L,INT_BIT_PIF0,0)
#define IODD_ClearStatusIrq_IODD_IRQ1  TARG_WriteBit(IF0L,INT_BIT_PIF1,0)
#define IODD_ClearStatusIrq_IODD_IRQ2  TARG_WriteBit(IF0L,INT_BIT_PIF2,0)
#define IODD_ClearStatusIrq_IODD_IRQ3  TARG_WriteBit(IF0L,INT_BIT_PIF3,0)
#define IODD_ClearStatusIrq_IODD_IRQ4  TARG_WriteBit(IF0L,INT_BIT_PIF4,0)
#define IODD_ClearStatusIrq_IODD_IRQ5  TARG_WriteBit(IF0L,INT_BIT_PIF5,0)
#endif /* __REL_RL78_D1A__ */
#endif /* __REL_RL78_D1x__ */

#ifdef __REL_RL78_F1x__
#ifdef __REL_RL78_F12__
#define IODD_ClearStatusIrq_IODD_IRQ0  TARG_WriteBit(IF0L,INT_BIT_PIF0,0)
#define IODD_ClearStatusIrq_IODD_IRQ1  TARG_WriteBit(IF0L,INT_BIT_PIF1,0)
#define IODD_ClearStatusIrq_IODD_IRQ2  TARG_WriteBit(IF0L,INT_BIT_PIF2,0)
#define IODD_ClearStatusIrq_IODD_IRQ3  TARG_WriteBit(IF0L,INT_BIT_PIF3,0)
#define IODD_ClearStatusIrq_IODD_IRQ4  TARG_WriteBit(IF0L,INT_BIT_PIF4,0)
#define IODD_ClearStatusIrq_IODD_IRQ5  TARG_WriteBit(IF0L,INT_BIT_PIF5,0)
#define IODD_ClearStatusIrq_IODD_IRQ6  TARG_WriteBit(IF2L,INT_BIT_PIF6,0)
#define IODD_ClearStatusIrq_IODD_IRQ7  TARG_WriteBit(IF2L,INT_BIT_PIF7,0)
#define IODD_ClearStatusIrq_IODD_IRQ8  TARG_WriteBit(IF2L,INT_BIT_PIF8,0)
#define IODD_ClearStatusIrq_IODD_IRQ9  TARG_WriteBit(IF2L,INT_BIT_PIF9,0)
#define IODD_ClearStatusIrq_IODD_IRQ10  TARG_WriteBit(IF2L,INT_BIT_PIF10,0)
#define IODD_ClearStatusIrq_IODD_IRQ11  TARG_WriteBit(IF2H,INT_BIT_PIF11,0)
#endif /* __REL_RL78_F12__ */
#endif /* __REL_RL78_F1x__ */

/*----------------------------------------------------------------------------*/
/*Name : IODD_SetOpenDrainData                                                */
/*Role : Set the open-drain state                                             */
/*Interface :                                                                 */
/*  - PortName  [P3, P5, P6, P13]                                             */
/*  - PinNumber IN, number of the selected pin  [P3:0,1; P5:0; P6:0,1; P13:6] */
/*Pre-condition : -                                                           */
/*Constraints :  -                                                            */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [set the open-drain state or high-impedance (target depending)]         */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#define IODD_SetOpenDrainData(PortName,PinNumber)


/*----------------------------------------------------------------------------*/
/*Name : IODD_GetPinStatus                                                    */
/*Role : Get the status of the pin                                            */
/*Interface :                                                                 */
/*   - PortName    IN, name of port for RL78 D1A: [0,1,2,3,4,5,6,7,8,9,10,    */
/*                                                 11,12,13,                  */
/*                                                 14(100 PIN),15(100 PIN)]   */
/*   - PortName    IN, name of port for RL78 F12: [0,1,2,3,4,5,6,7,12,13,14]  */
/*   - PinNumber   IN, number of the selected pin                             */
/*                                       [0..7]                               */
/*Pre-condition : -                                                           */
/*Constraints :  -                                                            */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [nothing          ]                                                     */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#define IODD_GetPinStatus(PortName, PinNumber)                           \
        IODD_GetPinData(PortName, PinNumber)


/*----------------------------------------------------------------------------*/
/*Name : IODD_GetPinData                                                      */
/*Role : Get the pin state                                                    */
/*Interface :                                                                 */
/*   - PortName    IN, name of port for RL78 D1A: [0,1,2,3,4,5,6,7,8,9,10,    */
/*                                                 11,12,13,                  */
/*                                                 14(100 PIN),15(100 PIN)]   */
/*   - PortName    IN, name of port for RL78 F12: [0,1,2,3,4,5,6,7,12,13,14]  */
/*  - PinNumber IN, number of the selected pin                                */
/*                                       [0..7]                               */
/*  - State     OUT, state of the pin [IODD_HIGH, IODD_LOW]                   */
/*Pre-condition : -                                                           */
/*Constraints :  -                                                            */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [get the pin state]                                                     */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#define IODD_GetPinData(PortName,\
                        PinNumber) \
        Iodd_GetOutputReg(PortName,PinNumber)


/*----------------------------------------------------------------------------*/
/*Name : IODD_SetPinData                                                      */
/*Role : Set a state on the pin                                               */
/*Interface :                                                                 */
/*   - PortName    IN, name of port for RL78 D1A: [0,1,2,3,4,5,6,7,8,9,10,    */
/*                                                 11,12,13,                  */
/*                                                 14(100 PIN),15(100 PIN)]   */
/*   - PortName    IN, name of port for RL78 F12: [0,1,2,3,4,5,6,7,12,13,14]  */
/*  - PinNumber IN, number of the selected pin                                */
/*                                    [0..7]                                  */
/*  - State     IN, requested output state of the pin [IODD_HIGH, IODD_LOW]   */
/*Pre-condition : -                                                           */
/*Constraints :  -                                                            */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [set the requested state on the pin]                                    */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#define IODD_SetPinData(PortName,\
                        PinNumber,\
                        State) \
        Iodd_SetOutputReg(PortName,PinNumber,State)

/*----------------------------------------------------------------------------*/
/*Name : IODD_ReadBytePortIn                                                  */
/*Role : Read an 8-bits port                                                  */
/*Interface :                                                                 */
/*   - PortName    IN, name of port for RL78 D1A: [0,1,2,3,4,5,6,7,8,9,10,    */
/*                                                 11,12,13,                  */
/*                                                 14(100 PIN),15(100 PIN)]   */
/*   - PortName    IN, name of port for RL78 F12: [0,1,2,3,4,5,6,7,12,13,14]  */
/*Pre-condition : -                                                           */
/*Constraints :                                                               */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [read the requested port]                                               */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#define IODD_ReadBytePortIn(PortName) \
        TARG_ReadByte( P ## PortName)

/*----------------------------------------------------------------------------*/
/*Name : IODD_WriteBytePortOut                                                */
/*Role : Write into 8-bits port                                               */
/*Interface :                                                                 */
/*   - PortName    IN, name of port for RL78 D1A: [P0,P1,P2,P3,P4,P5,P6,P7,   */
/*                                                 P8,P9,P10,P11,P12,P13,     */
/*                                                 P14(100 PIN),P15(100 PIN)] */
/*   - PortName    IN, name of port for RL78 F12: [P0,P1,P2,P3,P4,P5,P6,P7,   */
/*                                                 P12,P13,P14]               */
/*  - Value     IN, ubyte value                                               */
/*Pre-condition : -                                                           */
/*Constraints :                                                               */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [write the requested port]                                              */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#define IODD_WriteBytePortOut(PortName,\
                              Value) \
        (TARG_WriteByte( Iodd_WriteRegisterName(PortName,P), Value))

/*----------------------------------------------------------------------------*/
/*Name : IODD_WriteBytePortDirection                                          */
/*Role : Change 8-bits port direction                                         */
/*Interface :                                                                 */
/*   - PortName    IN, name of port for RL78 D1A: [P0,P1,P2,P3,P4,P5,P6,P7,   */
/*                                                 P8,P9,P10,P11,P12,P13,     */
/*                                                 P14(100 PIN),P15(100 PIN)] */
/*   - PortName    IN, name of port for RL78 F12: [P0,P1,P2,P3,P4,P5,P6,P7,   */
/*                                                 P12,P13,P14]               */
/*  - Value     IN, ubyte value [OUTPUT_PORT, INPUT_PORT]                     */
/*Pre-condition : -                                                           */
/*Constraints :                                                               */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [write the requested port direction]                                    */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#define IODD_WriteBytePortDirection(PortName,\
                                    Value) \
        (TARG_WriteByte( Iodd_WriteRegisterName(PortName,PM), Value))

/*----------------------------------------------------------------------------*/
/* Name : IODD_SetPinDirectionIn                                              */
/* Role : Set direction register to set pin in input                          */
/* Interface :                                                                */
/*   - PortName    IN, name of port for RL78 D1A: [0,1,2,3,4,5,6,7,8,9,10,    */
/*                                                 11,12,13,                  */
/*                                                 14(100 PIN),15(100 PIN)]   */
/*   - PortName    IN, name of port for RL78 F12: [0,1,2,3,4,5,6,7,12,13,14]  */
/*   - PinNumber   IN, number of the selected pin [0..7]                      */
/* Pre-condition : -                                                          */
/* Constraints : -                                                            */
/* Behavior :                                                                 */
/*   DO                                                                       */
/*     [set up the pin as requested]                                          */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/
#define IODD_SetPinDirectionIn(PortName,\
                               PinNumber) \
        Iodd_SetDdrBit(PortName,PinNumber,1)

/*----------------------------------------------------------------------------*/
/* Name : IODD_SetPinDirectionOut                                             */
/* Role : Set direction register to set pin in output                         */
/* Interface :                                                                */
/*   - PortName    IN, name of port for RL78 D1A: [0,1,2,3,4,5,6,7,8,9,10,    */
/*                                                 11,12,13,                  */
/*                                                 14(100 PIN),15(100 PIN)]   */
/*   - PortName    IN, name of port for RL78 F12: [0,1,2,3,4,5,6,7,12,13,14]  */
/*   - PinNumber   IN, number of the selected pin [0..7]                      */
/* Pre-condition : -                                                          */
/* Constraints : -                                                            */
/* Behavior :                                                                 */
/*   DO                                                                       */
/*     [set up the pin as requested]                                          */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/
#define IODD_SetPinDirectionOut(PortName,\
                                PinNumber) \
        Iodd_SetDdrBit(PortName,PinNumber,0)

/*----------------------------------------------------------------------------*/
/*Name : IODD_SetPullUpData                                                   */
/*Role : Set the pull-up state                                                */
/*Interface :                                                                 */
/*  - PortName  IN, name of port:   [0,1,3,4,5,6,7,8,9,13,14,15]              */
/*  - PinNumber IN, number of the selected pin  [P0,P1,P3,P5,P8,P9:0..7;      */
/*                                               P4,P14,P15:0;                */
/*                                               P6:0..6;                     */
/*                                               P7:0..5;                     */
/*                                               P13:1..6;                    */
/*Pre-condition : -                                                           */
/*Constraints :  -                                                            */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [set the pull-up state]                                                 */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#define IODD_SetPullUpData(PortName,PinNumber) \
        Iodd_SetPullUpBit(PortName,PinNumber)

/*----------------------------------------------------------------------------*/
/*Name : IODD_SetPullDownData                                                 */
/*Role : Set the pull-down state                                              */
/*Interface :                                                                 */
/*  - PortName  IN, name of port:   [0..9,A,B,..]                             */
/*  - PinNumber IN, number of the selected pin  [0..7]                        */
/*Pre-condition : -                                                           */
/*Constraints :  -                                                            */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [set the pull-down state]                                               */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#define IODD_SetPullDownData(PortName,PinNumber) \
        Iodd_SetPullDownBit(PortName,PinNumber)

/*----------------------------------------------------------------------------*/
/*Name : IODD_SetPortDirectionIn                                              */
/*Role : Set 8-bits port to operate as an input                               */
/*Interface :                                                                 */
/*   - PortName    IN, name of port for RL78 D1A: [P0,P1,P2,P3,P4,P5,P6,P7,   */
/*                                                 P8,P9,P10,P11,P12,P13,     */
/*                                                 P14(100 PIN),P15(100 PIN)] */
/*   - PortName    IN, name of port for RL78 F12: [P0,P1,P2,P3,P4,P5,P6,P7,   */
/*                                                 P12,P13,P14]               */
/*Pre-condition : -                                                           */
/*Constraints :  -                                                            */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [set the requested port as input]                                       */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#define IODD_SetPortDirectionIn(PortName)\
        IODD_WriteBytePortDirection(PortName,0xFF)

/*----------------------------------------------------------------------------*/
/*Name : IODD_SetPortDirectionOut                                             */
/*Role : Set 8-bits port to operate as an output                              */
/*Interface :                                                                 */
/*   - PortName    IN, name of port for RL78 D1A: [P0,P1,P2,P3,P4,P5,P6,P7,   */
/*                                                 P8,P9,P10,P11,P12,P13,     */
/*                                                 P14(100 PIN),P15(100 PIN)] */
/*   - PortName    IN, name of port for RL78 F12: [P0,P1,P2,P3,P4,P5,P6,P7,   */
/*                                                 P12,P13,P14]               */
/*Pre-condition : -                                                           */
/*Constraints :  -                                                            */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [set the requested port as output]                                      */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#define IODD_SetPortDirectionOut(PortName)\
        IODD_WriteBytePortDirection(PortName,0x00)



/*______ G L O B A L - F U N C T I O N S - P R O T O T Y P E S _______________*/

/******************************************************************************/
/*Name : IODD_Init                                                            */
/*Role : this function initialises the I/O Port with standard parameters      */
/*Interface :     none                                                        */
/*Pre-condition : none                                                        */
/*Constraints :   none                                                        */
/*Behaviour :                                                                 */
/*  DO                                                                        */
/*    [ configuring channel in order to preprocesseur directives ]            */
/*  OD                                                                        */
/******************************************************************************/
extern void IODD_Init(void);


#endif /* __REL_RL78_D1A__ || __REL_RL78_F12__ */
#endif /* __REL_RL78_D1x__ || __REL_RL78_F1x__ */
#endif /* __REL_RL78__ */
/***** Renesas REL_RL78 ********************************************************/

#endif /* IODD_H */


/*______ E N D _____ (iodd.h) ________________________________________________*/
