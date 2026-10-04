/******************************************************************************/
/*@F_NAME:          iodd_rh850.h                                              */
/*@F_PURPOSE:       Public interface for Logic port I/O driver                */
/*@F_CREATED_BY:    rh850                                                     */
/*@F_CREATION_DATE: 03/11/2017                                                */
/*@F_MPROC_TYPE:    rh850 f1x                                                 */
/************************************** (C) Copyright 2014 Magneti Marelli ****/

#ifndef IODD_RH850_H
#define IODD_RH850_H

#include "syst.h"

/***** rh850 f1x *************************************************************/

#if defined(__RH850__)


/*______ I N C L U D E - F I L E S ___________________________________________*/

/*//#include "syst.h"*/
#include "targ.h"
#if defined(C_COMP_GHS_RH850)
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

#ifdef __RH850_F1x__
#include "iodd_priv_RH850_F1x.h"
#endif

/* Open-drain control ------------------------------------------------------- */

#ifdef __RH850_F1x__
/* Open-drain outputs control */
/* For F1L :    each of the I/O pins can be set in open-drain mode */
#if defined (__RH850_F1L__)
#define IODD_OPEN_DRAIN(PortName,PinNumber)                                             \
        TARG_ProtWriteLong_Port(PPCMD## PortName, PPROTS##PortName, PODC## PortName, TARG_ReadLong(PODC## PortName) | (1<<PinNumber)); \
        TARG_ProtWriteLong_Port(PPCMD## PortName, PPROTS##PortName, PDSC## PortName, TARG_ReadLong(PDSC## PortName) | (1<<PinNumber)); \
        TARG_WriteBitInShort(PMC## PortName, PORT_BIT_P## PortName##_##PinNumber,  0)

#define IODD_OPEN_DRAIN_REDUCED(PortName,PinNumber)                                             \
        TARG_ProtWriteLong_Port(PPCMD## PortName, PPROTS##PortName, PODC## PortName, TARG_ReadLong(PODC## PortName) | (1<<PinNumber)); \
        TARG_ProtWriteLong_Port(PPCMD## PortName, PPROTS##PortName, PDSC## PortName, TARG_ReadLong(PDSC## PortName) & ~(1<<PinNumber));\
        TARG_WriteBitInShort(PMC## PortName, PORT_BIT_P## PortName##_##PinNumber,  0)

/*For F1L only P0,P10,P11,P12 has PDSC*/
#define IODD_NO_OPEN_DRAIN(PortName,PinNumber)     Iodd_NO_OPEN_DRAIN_ ## PortName(PortName,PinNumber)

#define Iodd_NO_OPEN_DRAIN_0(PortName,PinNumber)   IODD_NO_OPEN_DRAIN_NORMAL(PortName,PinNumber)
#define Iodd_NO_OPEN_DRAIN_1(PortName,PinNumber)   IODD_NO_OPEN_DRAIN_NORMAL_WITHOUT_PDSC(PortName,PinNumber)
#define Iodd_NO_OPEN_DRAIN_2(PortName,PinNumber)   IODD_NO_OPEN_DRAIN_NORMAL_WITHOUT_PDSC(PortName,PinNumber)
#define Iodd_NO_OPEN_DRAIN_8(PortName,PinNumber)   IODD_NO_OPEN_DRAIN_NORMAL_WITHOUT_PDSC(PortName,PinNumber)
#define Iodd_NO_OPEN_DRAIN_9(PortName,PinNumber)   IODD_NO_OPEN_DRAIN_NORMAL_WITHOUT_PDSC(PortName,PinNumber)
#define Iodd_NO_OPEN_DRAIN_10(PortName,PinNumber)  IODD_NO_OPEN_DRAIN_NORMAL(PortName,PinNumber)
#define Iodd_NO_OPEN_DRAIN_11(PortName,PinNumber)  IODD_NO_OPEN_DRAIN_NORMAL(PortName,PinNumber)
#define Iodd_NO_OPEN_DRAIN_12(PortName,PinNumber)  IODD_NO_OPEN_DRAIN_NORMAL(PortName,PinNumber)
#define Iodd_NO_OPEN_DRAIN_18(PortName,PinNumber)  IODD_NO_OPEN_DRAIN_NORMAL_WITHOUT_PDSC(PortName,PinNumber)
#define Iodd_NO_OPEN_DRAIN_20(PortName,PinNumber)  IODD_NO_OPEN_DRAIN_NORMAL_WITHOUT_PDSC(PortName,PinNumber)

#define IODD_NO_OPEN_DRAIN_NORMAL(PortName,PinNumber)                                             \
        TARG_ProtWriteLong_Port(PPCMD## PortName, PPROTS##PortName, PODC## PortName, TARG_ReadLong(PODC## PortName) & ~(1<<PinNumber)); \
        TARG_ProtWriteLong_Port(PPCMD## PortName, PPROTS##PortName, PDSC## PortName, TARG_ReadLong(PDSC## PortName) | (1<<PinNumber));\
        TARG_WriteBitInShort(PMC## PortName, PORT_BIT_P## PortName##_##PinNumber,  0)

#define IODD_NO_OPEN_DRAIN_NORMAL_WITHOUT_PDSC(PortName,PinNumber)                                             \
        TARG_ProtWriteLong_Port(PPCMD## PortName, PPROTS##PortName, PODC## PortName, TARG_ReadLong(PODC## PortName) & ~(1<<PinNumber)); \
        TARG_WriteBitInShort(PMC## PortName, PORT_BIT_P## PortName##_##PinNumber,  0)


#define IODD_NO_OPEN_DRAIN_REDUCED(PortName,PinNumber)                                             \
        TARG_ProtWriteLong_Port(PPCMD## PortName, PPROTS##PortName, PODC## PortName, TARG_ReadLong(PODC## PortName) & ~(1<<PinNumber)); \
        TARG_ProtWriteLong_Port(PPCMD## PortName, PPROTS##PortName, PDSC## PortName, TARG_ReadLong(PDSC## PortName) & ~(1<<PinNumber));\
        TARG_WriteBitInShort(PMC## PortName, PORT_BIT_P## PortName##_##PinNumber,  0)

#elif defined (__RH850_F1K__)

#define IODD_OPEN_DRAIN(PortName,PinNumber)                                             \
        TARG_ProtWriteLong_Port(PORTPPCMD## PortName, PORTPPROTS##PortName, PORTPODC## PortName, TARG_ReadLong(PORTPODC## PortName) | (1<<(PinNumber))); \
        TARG_ProtWriteLong_Port(PORTPPCMD## PortName, PORTPPROTS##PortName, PORTPDSC## PortName, TARG_ReadLong(PORTPDSC## PortName) | (1<<(PinNumber))); \
        TARG_WriteBitInShort(PORTPMC## PortName, PORT_BIT_P## PortName##_##PinNumber,  0)

#define IODD_OPEN_DRAIN_REDUCED(PortName,PinNumber)                                             \
        TARG_ProtWriteLong_Port(PORTPPCMD## PortName, PORTPPROTS##PortName, PORTPODC## PortName, TARG_ReadLong(PORTPODC## PortName) | (1<<(PinNumber))); \
        TARG_ProtWriteLong_Port(PORTPPCMD## PortName, PORTPPROTS##PortName, PORTPDSC## PortName, TARG_ReadLong(PORTPDSC## PortName) & ~(1<<(PinNumber)));\
        TARG_WriteBitInShort(PORTPMC## PortName, PORT_BIT_P## PortName##_##PinNumber,  0)

/*For F1K only P0,P1,P2,P10,P11,P12,P18,P20 has PDSC*/
#define IODD_NO_OPEN_DRAIN(PortName,PinNumber)     Iodd_NO_OPEN_DRAIN_ ## PortName(PortName,PinNumber)
#define Iodd_NO_OPEN_DRAIN_0(PortName,PinNumber)   IODD_NO_OPEN_DRAIN_NORMAL(PortName,PinNumber)
#define Iodd_NO_OPEN_DRAIN_1(PortName,PinNumber)   IODD_NO_OPEN_DRAIN_NORMAL(PortName,PinNumber)
#define Iodd_NO_OPEN_DRAIN_2(PortName,PinNumber)   IODD_NO_OPEN_DRAIN_NORMAL(PortName,PinNumber)
#define Iodd_NO_OPEN_DRAIN_8(PortName,PinNumber)  IODD_NO_OPEN_DRAIN_NORMAL_WITHOUT_PDSC(PortName,PinNumber)
#define Iodd_NO_OPEN_DRAIN_9(PortName,PinNumber)  IODD_NO_OPEN_DRAIN_NORMAL_WITHOUT_PDSC(PortName,PinNumber)
#define Iodd_NO_OPEN_DRAIN_10(PortName,PinNumber)  IODD_NO_OPEN_DRAIN_NORMAL(PortName,PinNumber)
#define Iodd_NO_OPEN_DRAIN_11(PortName,PinNumber)  IODD_NO_OPEN_DRAIN_NORMAL(PortName,PinNumber)
#define Iodd_NO_OPEN_DRAIN_12(PortName,PinNumber)  IODD_NO_OPEN_DRAIN_NORMAL(PortName,PinNumber)
#define Iodd_NO_OPEN_DRAIN_18(PortName,PinNumber) IODD_NO_OPEN_DRAIN_NORMAL(PortName,PinNumber)
#define Iodd_NO_OPEN_DRAIN_20(PortName,PinNumber) IODD_NO_OPEN_DRAIN_NORMAL(PortName,PinNumber)

#define IODD_NO_OPEN_DRAIN_NORMAL(PortName,PinNumber)                                             \
        TARG_ProtWriteLong_Port(PORTPPCMD## PortName, PORTPPROTS##PortName, PORTPODC## PortName, TARG_ReadLong(PORTPODC## PortName) & ~(1<<(PinNumber))); \
        TARG_ProtWriteLong_Port(PORTPPCMD## PortName, PORTPPROTS##PortName, PORTPDSC## PortName, TARG_ReadLong(PORTPDSC## PortName) | (1<<(PinNumber)));\
        TARG_WriteBitInShort(PORTPMC## PortName, PORT_BIT_P## PortName##_##PinNumber,  0)

#define IODD_NO_OPEN_DRAIN_NORMAL_WITHOUT_PDSC(PortName,PinNumber)                                             \
        TARG_ProtWriteLong_Port(PORTPPCMD## PortName, PORTPPROTS##PortName, PORTPODC## PortName, TARG_ReadLong(PORTPODC## PortName) & ~(1<<(PinNumber))); \
        TARG_WriteBitInShort(PORTPMC## PortName, PORT_BIT_P## PortName##_##PinNumber,  0)


#define IODD_NO_OPEN_DRAIN_REDUCED(PortName,PinNumber)                                             \
        TARG_ProtWriteLong_Port(PORTPPCMD## PortName, PORTPPROTS##PortName, PORTPODC## PortName, TARG_ReadLong(PORTPODC## PortName) & ~(1<<(PinNumber))); \
        TARG_ProtWriteLong_Port(PORTPPCMD## PortName, PORTPPROTS##PortName, PORTPDSC## PortName, TARG_ReadLong(PORTPDSC## PortName) & ~(1<<(PinNumber)));\
        TARG_WriteBitInShort(PORTPMC## PortName, PORT_BIT_P## PortName##_##PinNumber,  0)
#endif

#endif /* __RH850_F1x__ */




/* High-Inpedance control --------------------------------------------------- */


/* Interrupt Sense Control -------------------------------------------------- */


/* Input Pin Mode ----------------------------------------------------------- */

#ifdef __RH850__
#ifdef __RH850_F1x__
#if defined (__RH850_F1L__)
#define Iodd_GetInputReg(PortName,PinNumber) \
        TARG_ReadBitInShort(PPR ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber)

#define Iodd_WREG_PM(PortName,Value) \
        TARG_WriteShort(PM ## PortName,Value)  /* Except Port J0 */
#elif defined (__RH850_F1K__)
#define Iodd_GetInputReg(PortName,PinNumber) \
        TARG_ReadBitInShort(PORTPPR ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber)

#define Iodd_WREG_PM(PortName,Value) \
        TARG_WriteShort(PORTPM ## PortName,Value)  /* Except Port J0 */
#endif
#if (defined(__RH850_F1L__))

/* INTP0 */
#define Iodd_IT_EDGES_0_1(Value) \
        TARG_ClearBitsInShort(PFCAE0, PORT_MSK_PFCn1); \
        TARG_ClearBitsInShort(PFC0, PORT_MSK_PFCn1); \
        TARG_SetBitsInShort(PFCE0, PORT_MSK_PFCEn1); \
        TARG_WriteByte(FCLA0CTL0_INTPL,((TARG_ReadByte(FCLA0CTL0_INTPL)&0xf8) + Value)); \
        TARG_WriteByte(FCLA0CTL0_INTPL,((TARG_ReadByte(FCLA0CTL0_INTPL)) | 0x80 ))

/* INTP1 */
#define Iodd_IT_EDGES_0_2(Value) \
        TARG_SetBitsInShort(PFCAE0, PORT_MSK_PFCn2); \
        TARG_ClearBitsInShort(PFC0, PORT_MSK_PFCn2); \
        TARG_ClearBitsInShort(PFCE0, PORT_MSK_PFCEn2);\
        TARG_WriteByte(FCLA0CTL1_INTPL,((TARG_ReadByte(FCLA0CTL1_INTPL)&0xf8) + Value)); \
        TARG_WriteByte(FCLA0CTL1_INTPL,((TARG_ReadByte(FCLA0CTL1_INTPL)) | 0x80 ))

/* INTP10 */
#define Iodd_IT_EDGES_0_3(Value) \
        TARG_SetBitsInShort(PFCAE0, PORT_MSK_PFCn3); \
        TARG_ClearBitsInShort(PFC0, PORT_MSK_PFCn3); \
        TARG_ClearBitsInShort(PFCE0, PORT_MSK_PFCEn3);\
        TARG_WriteByte(FCLA0CTL2_INTPH,((TARG_ReadByte(FCLA0CTL2_INTPH)&0xf8) + Value)); \
        TARG_WriteByte(FCLA0CTL2_INTPH,((TARG_ReadByte(FCLA0CTL2_INTPH)) | 0x80 ))

/* INTP11 */
#define Iodd_IT_EDGES_0_4(Value) \
        TARG_ClearBitsInShort(PFCAE0, PORT_MSK_PFCn3); \
        TARG_SetBitsInShort(PFC0, PORT_MSK_PFCn4); \
        TARG_ClearBitsInShort(PFCE0, PORT_MSK_PFCEn4); \
        TARG_WriteByte(FCLA0CTL3_INTPH,((TARG_ReadByte(FCLA0CTL3_INTPH)&0xf8) + Value)); \
        TARG_WriteByte(FCLA0CTL3_INTPH,((TARG_ReadByte(FCLA0CTL3_INTPH)) | 0x80 ))

/* INTP2 */
#define Iodd_IT_EDGES_0_6(Value) \
        TARG_ClearBitsInShort(PFCAE0, PORT_MSK_PFCn6); \
        TARG_ClearBitsInShort(PFC0, PORT_MSK_PFCn6); \
        TARG_ClearBitsInShort(PFCE0, PORT_MSK_PFCEn6); \
        TARG_WriteByte(FCLA0CTL2_INTPL,((TARG_ReadByte(FCLA0CTL2_INTPL)&0xf8) + Value)); \
        TARG_WriteByte(FCLA0CTL2_INTPL,((TARG_ReadByte(FCLA0CTL2_INTPL)) | 0x80 ))

/* INTP12 */
#define Iodd_IT_EDGES_0_9(Value) \
        TARG_ClearBitsInShort(PFCAE0, PORT_MSK_PFCn9); \
        TARG_ClearBitsInShort(PFC0, PORT_MSK_PFCn9); \
        TARG_ClearBitsInShort(PFCE0, PORT_MSK_PFCEn9); \
        TARG_WriteByte(FCLA0CTL4_INTPH,((TARG_ReadByte(FCLA0CTL4_INTPH)&0xf8) + Value)); \
        TARG_WriteByte(FCLA0CTL4_INTPH,((TARG_ReadByte(FCLA0CTL4_INTPH)) | 0x80 ))

/* INTP3 */
#define Iodd_IT_EDGES_0_10(Value) \
        TARG_ClearBitsInShort(PFCAE0, PORT_MSK_PFCn10); \
        TARG_ClearBitsInShort(PFC0, PORT_MSK_PFCn10); \
        TARG_ClearBitsInShort(PFCE0, PORT_MSK_PFCEn10); \
        TARG_WriteByte(FCLA0CTL3_INTPL,((TARG_ReadByte(FCLA0CTL3_INTPL)&0xf8) + Value)); \
        TARG_WriteByte(FCLA0CTL3_INTPL,((TARG_ReadByte(FCLA0CTL3_INTPL)) | 0x80 ))

/* INTP12 */
#define Iodd_IT_EDGES_0_13(Value) \
        TARG_ClearBitsInShort(PFCAE0, PORT_MSK_PFCn13); \
        TARG_SetBitsInShort(PFC0, PORT_MSK_PFCn13); \
        TARG_ClearBitsInShort(PFCE0, PORT_MSK_PFCEn13); \
        TARG_WriteByte(FCLA0CTL4_INTPH,((TARG_ReadByte(FCLA0CTL4_INTPH)&0xf8) + Value)); \
        TARG_WriteByte(FCLA0CTL4_INTPH,((TARG_ReadByte(FCLA0CTL4_INTPH)) | 0x80 ))

/* INTP13 */
#define Iodd_IT_EDGES_1_0(Value) \
        TARG_ClearBitsInShort(PFCAE0, PORT_MSK_PFCn0); \
        TARG_SetBitsInShort(PFC0, PORT_MSK_PFCn0); \
        TARG_ClearBitsInShort(PFCE0, PORT_MSK_PFCEn0); \
        TARG_WriteByte(FCLA0CTL5_INTPH,((TARG_ReadByte(FCLA0CTL5_INTPH)&0xf8) + Value)); \
        TARG_WriteByte(FCLA0CTL5_INTPH,((TARG_ReadByte(FCLA0CTL5_INTPH)) | 0x80 ))

/* INTP3 */
#define Iodd_IT_EDGES_1_2(Value) \
        TARG_ClearBitsInShort(PFCAE0, PORT_MSK_PFCn2); \
        TARG_SetBitsInShort(PFC0, PORT_MSK_PFCn2); \
        TARG_ClearBitsInShort(PFCE0, PORT_MSK_PFCEn2); \
        TARG_WriteByte(FCLA0CTL3_INTPL,((TARG_ReadByte(FCLA0CTL3_INTPL)&0xf8) + Value)); \
        TARG_WriteByte(FCLA0CTL3_INTPL,((TARG_ReadByte(FCLA0CTL3_INTPL)) | 0x80 ))

/* INTP15 */
#define Iodd_IT_EDGES_1_4(Value) \
        TARG_ClearBitsInShort(PFCAE0, PORT_MSK_PFCn4); \
        TARG_SetBitsInShort(PFC0, PORT_MSK_PFCn4); \
        TARG_ClearBitsInShort(PFCE0, PORT_MSK_PFCEn4); \
        TARG_WriteByte(FCLA0CTL7_INTPH,((TARG_ReadByte(FCLA0CTL7_INTPH)&0xf8) + Value)); \
        TARG_WriteByte(FCLA0CTL7_INTPH,((TARG_ReadByte(FCLA0CTL7_INTPH)) | 0x80 ))

/* INTP14 */
#define Iodd_IT_EDGES_1_8(Value) \
        TARG_ClearBitsInShort(PFCAE0, PORT_MSK_PFCn8); \
        TARG_SetBitsInShort(PFC0, PORT_MSK_PFCn8); \
        TARG_ClearBitsInShort(PFCE0, PORT_MSK_PFCEn8); \
        TARG_WriteByte(FCLA0CTL6_INTPH,((TARG_ReadByte(FCLA0CTL6_INTPH)&0xf8) + Value)); \
        TARG_WriteByte(FCLA0CTL6_INTPH,((TARG_ReadByte(FCLA0CTL6_INTPH)) | 0x80 )); \

/* INTP4 */
#define Iodd_IT_EDGES_1_12(Value) \
        TARG_ClearBitsInShort(PFCAE0, PORT_MSK_PFCn12); \
        TARG_SetBitsInShort(PFC0, PORT_MSK_PFCn12); \
        TARG_ClearBitsInShort(PFCE0, PORT_MSK_PFCEn12); \
        TARG_WriteByte(FCLA0CTL4_INTPL,((TARG_ReadByte(FCLA0CTL4_INTPL)&0xf8) + Value)); \
        TARG_WriteByte(FCLA0CTL4_INTPL,((TARG_ReadByte(FCLA0CTL4_INTPL)) | 0x80 ))

/* INTP4 */
#define Iodd_IT_EDGES_8_0(Value) \
        TARG_ClearBitsInShort(PFCAE0, PORT_MSK_PFCn0); \
        TARG_ClearBitsInShort(PFC0, PORT_MSK_PFCn0); \
        TARG_SetBitsInShort(PFCE0, PORT_MSK_PFCEn0); \
        TARG_WriteByte(FCLA0CTL4_INTPL,((TARG_ReadByte(FCLA0CTL4_INTPL)&0xf8) + Value)); \
        TARG_WriteByte(FCLA0CTL4_INTPL,((TARG_ReadByte(FCLA0CTL4_INTPL)) | 0x80 ))

/* INTP5 */
#define Iodd_IT_EDGES_8_1(Value) \
        TARG_ClearBitsInShort(PFCAE0, PORT_MSK_PFCn1); \
        TARG_ClearBitsInShort(PFC0, PORT_MSK_PFCn1); \
        TARG_SetBitsInShort(PFCE0, PORT_MSK_PFCEn1); \
        TARG_WriteByte(FCLA0CTL5_INTPL,((TARG_ReadByte(FCLA0CTL5_INTPL)&0xf8) + Value)); \
        TARG_WriteByte(FCLA0CTL5_INTPL,((TARG_ReadByte(FCLA0CTL5_INTPL)) | 0x80 ))

/* INTP6 */
#define Iodd_IT_EDGES_8_2(Value) \
        TARG_ClearBitsInShort(PFCAE0, PORT_MSK_PFCn2); \
        TARG_ClearBitsInShort(PFC0, PORT_MSK_PFCn2); \
        TARG_SetBitsInShort(PFCE0, PORT_MSK_PFCEn2); \
        TARG_WriteByte(FCLA0CTL6_INTPL,((TARG_ReadByte(FCLA0CTL6_INTPL)&0xf8) + Value)); \
        TARG_WriteByte(FCLA0CTL6_INTPL,((TARG_ReadByte(FCLA0CTL6_INTPL)) | 0x80 ))

/* INTP7 */
#define Iodd_IT_EDGES_8_3(Value) \
        TARG_ClearBitsInShort(PFCAE0, PORT_MSK_PFCn3); \
        TARG_ClearBitsInShort(PFC0, PORT_MSK_PFCn3); \
        TARG_SetBitsInShort(PFCE0, PORT_MSK_PFCEn3); \
        TARG_WriteByte(FCLA0CTL7_INTPL,((TARG_ReadByte(FCLA0CTL7_INTPL)&0xf8) + Value)); \
        TARG_WriteByte(FCLA0CTL7_INTPL,((TARG_ReadByte(FCLA0CTL7_INTPL)) | 0x80 ))

/* INTP8 */
#define Iodd_IT_EDGES_8_4(Value) \
        TARG_ClearBitsInShort(PFCAE0, PORT_MSK_PFCn4); \
        TARG_ClearBitsInShort(PFC0, PORT_MSK_PFCn4); \
        TARG_SetBitsInShort(PFCE0, PORT_MSK_PFCEn4); \
        TARG_WriteByte(FCLA0CTL0_INTPH,((TARG_ReadByte(FCLA0CTL0_INTPH)&0xf8) + Value)); \
        TARG_WriteByte(FCLA0CTL0_INTPH,((TARG_ReadByte(FCLA0CTL0_INTPH)) | 0x80 ))

/* INTP9 */
#define Iodd_IT_EDGES_8_5(Value) \
        TARG_ClearBitsInShort(PFCAE0, PORT_MSK_PFCn5); \
        TARG_ClearBitsInShort(PFC0, PORT_MSK_PFCn5); \
        TARG_SetBitsInShort(PFCE0, PORT_MSK_PFCEn5); \
        TARG_WriteByte(FCLA0CTL1_INTPH,((TARG_ReadByte(FCLA0CTL1_INTPH)&0xf8) + Value)); \
        TARG_WriteByte(FCLA0CTL1_INTPH,((TARG_ReadByte(FCLA0CTL1_INTPH)) | 0x80 ))

/* NMI */
#define Iodd_IT_EDGES_8_6(Value) \
        TARG_ClearBitsInShort(PFCAE0, PORT_MSK_PFCn6); \
        TARG_ClearBitsInShort(PFC0, PORT_MSK_PFCn6); \
        TARG_ClearBitsInShort(PFCE0, PORT_MSK_PFCEn6); \
        TARG_WriteByte(FCLA0CTL0_NMI,((TARG_ReadByte(FCLA0CTL0_NMI)&0xf8) + Value)); \
        TARG_WriteByte(FCLA0CTL0_NMI,((TARG_ReadByte(FCLA0CTL0_NMI)) | 0x80 ))

/* NMI */
#define Iodd_IT_EDGES_9_0(Value) \
        TARG_ClearBitsInShort(PFCAE0, PORT_MSK_PFCn0); \
        TARG_ClearBitsInShort(PFC0, PORT_MSK_PFCn0); \
        TARG_ClearBitsInShort(PFCE0, PORT_MSK_PFCEn0); \
        TARG_WriteByte(FCLA0CTL0_NMI,((TARG_ReadByte(FCLA0CTL0_NMI)&0xf8) + Value)); \
        TARG_WriteByte(FCLA0CTL0_NMI,((TARG_ReadByte(FCLA0CTL0_NMI)) | 0x80 ))

#define Iodd_IT_EDGES_10_13(Value) \
        TARG_ClearBitsInShort(PFCAE10, PORT_MSK_PFCn13); \
        TARG_ClearBitsInShort(PFC10, PORT_MSK_PFCn13); \
        TARG_ClearBitsInShort(PFCE10, PORT_MSK_PFCn13); \
        TARG_WriteByte(FCLA0CTL4_INTPH,((TARG_ReadByte(FCLA0CTL4_INTPH)&0xf8) + Value)); \
        TARG_WriteByte(FCLA0CTL4_INTPH,((TARG_ReadByte(FCLA0CTL4_INTPH)) | 0x80 ))


#elif  defined(__RH850_F1K__)

/* INTP0 */
#define Iodd_IT_EDGES_0_1(Value) \
        TARG_ClearBitsInShort(PORTPFCAE0, PORT_MSK_PFCn1); \
        TARG_ClearBitsInShort(PORTPFC0, PORT_MSK_PFCn1); \
        TARG_SetBitsInShort(PORTPFCE0, PORT_MSK_PFCEn1); \
        TARG_WriteByte(FCLA0CTL0_INTPL,((TARG_ReadByte(FCLA0CTL0_INTPL)&0xf8) + (Value))); \
        TARG_WriteByte(FCLA0CTL0_INTPL,((TARG_ReadByte(FCLA0CTL0_INTPL)) | 0x80 ))

/* INTP1 */
#define Iodd_IT_EDGES_0_2(Value) \
        TARG_SetBitsInShort(PORTPFCAE0, PORT_MSK_PFCn2); \
        TARG_ClearBitsInShort(PORTPFC0, PORT_MSK_PFCn2); \
        TARG_ClearBitsInShort(PORTPFCE0, PORT_MSK_PFCEn2);\
        TARG_WriteByte(FCLA0CTL1_INTPL,((TARG_ReadByte(FCLA0CTL1_INTPL)&0xf8) + (Value))); \
        TARG_WriteByte(FCLA0CTL1_INTPL,((TARG_ReadByte(FCLA0CTL1_INTPL)) | 0x80 ))

/* INTP10 */
#define Iodd_IT_EDGES_0_3(Value) \
        TARG_SetBitsInShort(PORTPFCAE0, PORT_MSK_PFCn3); \
        TARG_ClearBitsInShort(PORTPFC0, PORT_MSK_PFCn3); \
        TARG_ClearBitsInShort(PORTPFCE0, PORT_MSK_PFCEn3);\
        TARG_WriteByte(FCLA0CTL2_INTPH,((TARG_ReadByte(FCLA0CTL2_INTPH)&0xf8) + (Value))); \
        TARG_WriteByte(FCLA0CTL2_INTPH,((TARG_ReadByte(FCLA0CTL2_INTPH)) | 0x80 ))

/* INTP11 */
#define Iodd_IT_EDGES_0_4(Value) \
        TARG_ClearBitsInShort(PORTPFCAE0, PORT_MSK_PFCn4); \
        TARG_SetBitsInShort(PORTPFC0, PORT_MSK_PFCn4); \
        TARG_ClearBitsInShort(PORTPFCE0, PORT_MSK_PFCEn4); \
        TARG_WriteByte(FCLA0CTL3_INTPH,((TARG_ReadByte(FCLA0CTL3_INTPH)&0xf8) + (Value))); \
        TARG_WriteByte(FCLA0CTL3_INTPH,((TARG_ReadByte(FCLA0CTL3_INTPH)) | 0x80 ))

/* INTP2 */
#define Iodd_IT_EDGES_0_6(Value) \
        TARG_ClearBitsInShort(PORTPFCAE0, PORT_MSK_PFCn6); \
        TARG_ClearBitsInShort(PORTPFC0, PORT_MSK_PFCn6); \
        TARG_ClearBitsInShort(PORTPFCE0, PORT_MSK_PFCEn6); \
        TARG_WriteByte(FCLA0CTL2_INTPL,((TARG_ReadByte(FCLA0CTL2_INTPL)&0xf8) + (Value))); \
        TARG_WriteByte(FCLA0CTL2_INTPL,((TARG_ReadByte(FCLA0CTL2_INTPL)) | 0x80 ))

#ifdef P0_9_ALTER_INTP4 
/* INTP4 */
#define Iodd_IT_EDGES_0_9(Value) \
        TARG_ClearBitsInShort(PORTPFCAE0, PORT_MSK_PFCn9); \
        TARG_ClearBitsInShort(PORTPFC0, PORT_MSK_PFCn9); \
        TARG_ClearBitsInShort(PORTPFCE0, PORT_MSK_PFCEn9); \
        TARG_WriteByte(FCLA0CTL4_INTPL,((TARG_ReadByte(FCLA0CTL4_INTPL)&0xf8) + (Value))); \
        TARG_WriteByte(FCLA0CTL4_INTPL,((TARG_ReadByte(FCLA0CTL4_INTPL)) | 0x80 ))
#else
/* INTP12 */
#define Iodd_IT_EDGES_0_9(Value) \
        TARG_ClearBitsInShort(PORTPFCAE0, PORT_MSK_PFCn9); \
        TARG_ClearBitsInShort(PORTPFC0, PORT_MSK_PFCn9); \
        TARG_ClearBitsInShort(PORTPFCE0, PORT_MSK_PFCEn9); \
        TARG_WriteByte(FCLA0CTL4_INTPH,((TARG_ReadByte(FCLA0CTL4_INTPH)&0xf8) + (Value))); \
        TARG_WriteByte(FCLA0CTL4_INTPH,((TARG_ReadByte(FCLA0CTL4_INTPH)) | 0x80 ))
#endif

/* INTP3 */
#define Iodd_IT_EDGES_0_10(Value) \
        TARG_ClearBitsInShort(PORTPFCAE0, PORT_MSK_PFCn10); \
        TARG_ClearBitsInShort(PORTPFC0, PORT_MSK_PFCn10); \
        TARG_ClearBitsInShort(PORTPFCE0, PORT_MSK_PFCEn10); \
        TARG_WriteByte(FCLA0CTL3_INTPL,((TARG_ReadByte(FCLA0CTL3_INTPL)&0xf8) + (Value))); \
        TARG_WriteByte(FCLA0CTL3_INTPL,((TARG_ReadByte(FCLA0CTL3_INTPL)) | 0x80 ))

/* INTP12 */
#define Iodd_IT_EDGES_0_13(Value) \
        TARG_ClearBitsInShort(PORTPFCAE0, PORT_MSK_PFCn13); \
        TARG_SetBitsInShort(PORTPFC0, PORT_MSK_PFCn13); \
        TARG_ClearBitsInShort(PORTPFCE0, PORT_MSK_PFCEn13); \
        TARG_WriteByte(FCLA0CTL4_INTPH,((TARG_ReadByte(FCLA0CTL4_INTPH)&0xf8) + (Value))); \
        TARG_WriteByte(FCLA0CTL4_INTPH,((TARG_ReadByte(FCLA0CTL4_INTPH)) | 0x80 ))

/* INTP13 */
#define Iodd_IT_EDGES_1_0(Value) \
        TARG_ClearBitsInShort(PORTPFCAE1, PORT_MSK_PFCn0); \
        TARG_SetBitsInShort(PORTPFC1, PORT_MSK_PFCn0); \
        TARG_ClearBitsInShort(PORTPFCE1, PORT_MSK_PFCEn0); \
        TARG_WriteByte(FCLA0CTL5_INTPH,((TARG_ReadByte(FCLA0CTL5_INTPH)&0xf8) + (Value))); \
        TARG_WriteByte(FCLA0CTL5_INTPH,((TARG_ReadByte(FCLA0CTL5_INTPH)) | 0x80 ))

/* INTP3 */
#define Iodd_IT_EDGES_1_2(Value) \
        TARG_ClearBitsInShort(PORTPFCAE1, PORT_MSK_PFCn2); \
        TARG_SetBitsInShort(PORTPFC1, PORT_MSK_PFCn2); \
        TARG_ClearBitsInShort(PORTPFCE1, PORT_MSK_PFCEn2); \
        TARG_WriteByte(FCLA0CTL3_INTPL,((TARG_ReadByte(FCLA0CTL3_INTPL)&0xf8) + (Value))); \
        TARG_WriteByte(FCLA0CTL3_INTPL,((TARG_ReadByte(FCLA0CTL3_INTPL)) | 0x80 ))

/* INTP15 */
#define Iodd_IT_EDGES_1_4(Value) \
        TARG_ClearBitsInShort(PORTPFCAE1, PORT_MSK_PFCn4); \
        TARG_SetBitsInShort(PORTPFC1, PORT_MSK_PFCn4); \
        TARG_ClearBitsInShort(PORTPFCE1, PORT_MSK_PFCEn4); \
        TARG_WriteByte(FCLA0CTL7_INTPH,((TARG_ReadByte(FCLA0CTL7_INTPH)&0xf8) + (Value))); \
        TARG_WriteByte(FCLA0CTL7_INTPH,((TARG_ReadByte(FCLA0CTL7_INTPH)) | 0x80 ))

/* INTP14 */
#define Iodd_IT_EDGES_1_8(Value) \
        TARG_ClearBitsInShort(PORTPFCAE1, PORT_MSK_PFCn8); \
        TARG_SetBitsInShort(PORTPFC1, PORT_MSK_PFCn8); \
        TARG_ClearBitsInShort(PORTPFCE1, PORT_MSK_PFCEn8); \
        TARG_WriteByte(FCLA0CTL6_INTPH,((TARG_ReadByte(FCLA0CTL6_INTPH)&0xf8) + (Value))); \
        TARG_WriteByte(FCLA0CTL6_INTPH,((TARG_ReadByte(FCLA0CTL6_INTPH)) | 0x80 )); \

/* INTP4 */
#define Iodd_IT_EDGES_1_12(Value) \
        TARG_ClearBitsInShort(PORTPFCAE1, PORT_MSK_PFCn12); \
        TARG_SetBitsInShort(PORTPFC1, PORT_MSK_PFCn12); \
        TARG_ClearBitsInShort(PORTPFCE1, PORT_MSK_PFCEn12); \
        TARG_WriteByte(FCLA0CTL4_INTPL,((TARG_ReadByte(FCLA0CTL4_INTPL)&0xf8) + (Value))); \
        TARG_WriteByte(FCLA0CTL4_INTPL,((TARG_ReadByte(FCLA0CTL4_INTPL)) | 0x80 ))

/* INTP4 */
#define Iodd_IT_EDGES_8_0(Value) \
        TARG_ClearBitsInShort(PORTPFC8, PORT_MSK_PFCn0); \
        TARG_SetBitsInShort(PORTPFCE8, PORT_MSK_PFCEn0); \
        TARG_WriteByte(FCLA0CTL4_INTPL,((TARG_ReadByte(FCLA0CTL4_INTPL)&0xf8) + (Value))); \
        TARG_WriteByte(FCLA0CTL4_INTPL,((TARG_ReadByte(FCLA0CTL4_INTPL)) | 0x80 ))

/* INTP5 */
#define Iodd_IT_EDGES_8_1(Value) \
        TARG_ClearBitsInShort(PORTPFC8, PORT_MSK_PFCn1); \
        TARG_SetBitsInShort(PORTPFCE8, PORT_MSK_PFCEn1); \
        TARG_WriteByte(FCLA0CTL5_INTPL,((TARG_ReadByte(FCLA0CTL5_INTPL)&0xf8) + (Value))); \
        TARG_WriteByte(FCLA0CTL5_INTPL,((TARG_ReadByte(FCLA0CTL5_INTPL)) | 0x80 ))

/* INTP6 */
#define Iodd_IT_EDGES_8_2(Value) \
        TARG_ClearBitsInShort(PORTPFC8, PORT_MSK_PFCn2); \
        TARG_SetBitsInShort(PORTPFCE8, PORT_MSK_PFCEn2); \
        TARG_WriteByte(FCLA0CTL6_INTPL,((TARG_ReadByte(FCLA0CTL6_INTPL)&0xf8) + (Value))); \
        TARG_WriteByte(FCLA0CTL6_INTPL,((TARG_ReadByte(FCLA0CTL6_INTPL)) | 0x80 ))

/* INTP7 */
#define Iodd_IT_EDGES_8_3(Value) \
        TARG_ClearBitsInShort(PORTPFC8, PORT_MSK_PFCn3); \
        TARG_SetBitsInShort(PORTPFCE8, PORT_MSK_PFCEn3); \
        TARG_WriteByte(FCLA0CTL7_INTPL,((TARG_ReadByte(FCLA0CTL7_INTPL)&0xf8) + (Value))); \
        TARG_WriteByte(FCLA0CTL7_INTPL,((TARG_ReadByte(FCLA0CTL7_INTPL)) | 0x80 ))

/* INTP8 */
#define Iodd_IT_EDGES_8_4(Value) \
        TARG_ClearBitsInShort(PORTPFC8, PORT_MSK_PFCn4); \
        TARG_SetBitsInShort(PORTPFCE8, PORT_MSK_PFCEn4); \
        TARG_WriteByte(FCLA0CTL0_INTPH,((TARG_ReadByte(FCLA0CTL0_INTPH)&0xf8) + (Value))); \
        TARG_WriteByte(FCLA0CTL0_INTPH,((TARG_ReadByte(FCLA0CTL0_INTPH)) | 0x80 ))

/* INTP9 */
#define Iodd_IT_EDGES_8_5(Value) \
        TARG_ClearBitsInShort(PORTPFC8, PORT_MSK_PFCn5); \
        TARG_SetBitsInShort(PORTPFCE8, PORT_MSK_PFCEn5); \
        TARG_WriteByte(FCLA0CTL1_INTPH,((TARG_ReadByte(FCLA0CTL1_INTPH)&0xf8) + (Value))); \
        TARG_WriteByte(FCLA0CTL1_INTPH,((TARG_ReadByte(FCLA0CTL1_INTPH)) | 0x80 ))

/* NMI */
#define Iodd_IT_EDGES_8_6(Value) \
        TARG_ClearBitsInShort(PORTPFC8, PORT_MSK_PFCn6); \
        TARG_ClearBitsInShort(PORTPFCE8, PORT_MSK_PFCEn6); \
        TARG_WriteByte(FCLA0CTL0_NMI,((TARG_ReadByte(FCLA0CTL0_NMI)&0xf8) + (Value))); \
        TARG_WriteByte(FCLA0CTL0_NMI,((TARG_ReadByte(FCLA0CTL0_NMI)) | 0x80 ))

/* NMI */
#define Iodd_IT_EDGES_9_0(Value) \
        TARG_ClearBitsInShort(PORTPFC9, PORT_MSK_PFCn0); \
        TARG_ClearBitsInShort(PORTPFCE9, PORT_MSK_PFCEn0); \
        TARG_WriteByte(FCLA0CTL0_NMI,((TARG_ReadByte(FCLA0CTL0_NMI)&0xf8) + (Value))); \
        TARG_WriteByte(FCLA0CTL0_NMI,((TARG_ReadByte(FCLA0CTL0_NMI)) | 0x80 ))

/* INTP12 */
/*Table 2.24->P10_13->INTP12->2nd Alternative*/
/*Refer to Table 2.24-Alternative input2-*/
/*INTP12-FCLA0CTL4_INTPH*/
#define Iodd_IT_EDGES_10_13(Value) \
        TARG_ClearBitsInShort(PORTPFCAE10, PORT_MSK_PFCn13); \
        TARG_SetBitsInShort(PORTPFC10, PORT_MSK_PFCn13); \
        TARG_ClearBitsInShort(PORTPFCE10, PORT_MSK_PFCEn13); \
        TARG_WriteByte(FCLA0CTL4_INTPH,((TARG_ReadByte(FCLA0CTL4_INTPH)&0xf8) + (Value))); \
        TARG_WriteByte(FCLA0CTL4_INTPH,((TARG_ReadByte(FCLA0CTL4_INTPH)) | 0x80 ))

#else
#error"MCU not support,line490 of iodd_rh850"
#endif /* (defined(__RH850_F1L__) || defined(__RH850_F1K__)) */

#ifdef __RH850_F1L__
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
        TARG_WriteBitInShort(PIBC ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 1

#define IODD_STANDARD(PortName,PinNumber) \
        TARG_WriteBitInShort(PMC ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 0)
#elif defined(__RH850_F1K__)
#define IODD_IT_FALLING_EDGE(PortName,PinNumber)     \
        Iodd_IT_EDGES_ ##PortName##_## PinNumber (2); \
        TARG_WriteBitInShort(PORTPM ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 1); \
        TARG_WriteBitInShort(PORTPMC ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 1); \
        TARG_WriteBitInShort(PORTPIBC ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 1)

#define IODD_IT_RISING_EDGE(PortName,PinNumber)      \
        Iodd_IT_EDGES_ ##PortName##_##PinNumber (1); \
        TARG_WriteBitInShort(PORTPM ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 1); \
        TARG_WriteBitInShort(PORTPMC ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 1); \
        TARG_WriteBitInShort(PORTPIBC ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 1)

#define IODD_IT_BOTH_EDGE(PortName,PinNumber)        \
        Iodd_IT_EDGES_ ## PortName##_## PinNumber (3); \
        TARG_WriteBitInShort(PORTPM ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 1); \
        TARG_WriteBitInShort(PORTPMC ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 1); \
        TARG_WriteBitInShort(PORTPIBC ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 1)

#define IODD_IT_LOW_LEVEL(PortName,PinNumber)        \
        Iodd_IT_EDGES_ ## PortName##_## PinNumber (4); \
        TARG_WriteBitInShort(PORTPM ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 1); \
        TARG_WriteBitInShort(PORTPMC ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 1); \
        TARG_WriteBitInShort(PORTPIBC ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 1)

#define IODD_IT_HIGH_LEVEL(PortName,PinNumber)       \
        Iodd_IT_EDGES_ ## PortName##_## PinNumber (5); \
        TARG_WriteBitInShort(PORTPM ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 1); \
        TARG_WriteBitInShort(PORTPMC ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 1); \
        TARG_WriteBitInShort(PORTPIBC ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 1)

#define IODD_NMI_FALLING_EDGE(PortName,PinNumber) \
        Iodd_IT_EDGES_ ##PortName##_## PinNumber (2); \
        TARG_WriteBitInShort(PORTPM ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 1); \
        TARG_WriteBitInShort(PORTPMC ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 1); \
        TARG_WriteBitInShort(PORTPIBC ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 1)

#define IODD_NMI_RISING_EDGE(PortName,PinNumber) \
        Iodd_IT_EDGES_ ##PortName##_##PinNumber (1); \
        TARG_WriteBitInShort(PORTPM ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 1); \
        TARG_WriteBitInShort(PORTPMC ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 1); \
        TARG_WriteBitInShort(PORTPIBC ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 1)

#define IODD_NMI_BOTH_EDGE(PortName,PinNumber) \
        Iodd_IT_EDGES_ ## PortName##_## PinNumber (3); \
        TARG_WriteBitInShort(PORTPM ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 1); \
        TARG_WriteBitInShort(PORTPMC ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 1); \
        TARG_WriteBitInShort(PORTPIBC ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 1)

#define IODD_NMI_LOW_LEVEL(PortName,PinNumber) \
        Iodd_IT_EDGES_ ## PortName##_## PinNumber (4); \
        TARG_WriteBitInShort(PORTPM ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 1); \
        TARG_WriteBitInShort(PORTPMC ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 1); \
        TARG_WriteBitInShort(PORTPIBC ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 1)

#define IODD_NMI_HIGH_LEVEL(PortName,PinNumber) \
        Iodd_IT_EDGES_ ## PortName##_## PinNumber (5); \
        TARG_WriteBitInShort(PORTPM ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 1); \
        TARG_WriteBitInShort(PORTPMC ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 1); \
        TARG_WriteBitInShort(PORTPIBC ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 1)

#define IODD_STANDARD(PortName,PinNumber) \
        TARG_WriteBitInShort(PORTPMC ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 0)
#else
#error "MUC not supported, line449, iodd_rh850h"
#endif
#endif/*__RH850_F1x__*/
#endif/*__RH850__*/
/* Pull-device control ------------------------------------------------------ */

#ifdef __RH850_F1x__
#ifdef NO_PULLUP
#define Iodd_SetPullUpBit(PortName,PinNumber)

#define Iodd_SetNoPullDeviceBit(PortName,PinNumber)

#define Iodd_SetPullDownBit(PortName,PinNumber)
#else
#ifdef __RH850_F1L__
#define Iodd_SetPullUpBit(PortName,PinNumber) \
        TARG_WriteBitInLong(PU ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 1);\
        Iodd_Write_PD(PPortName, PinNumber, 0)

#define Iodd_SetNoPullDeviceBit(PortName,PinNumber) \
        Iodd_Write_PD(PortName, PinNumber, 0);\
        TARG_WriteBitInLong(PU ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 0)

#define Iodd_SetPullDownBit(PortName,PinNumber) \
        Iodd_Write_PD(PortName, PinNumber, 1);\
        TARG_WriteBitInLong(PU ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 0)

#define Iodd_Write_PD_Reg(PortName,PinNumber,value)\
        TARG_WriteBitInLong(PD ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, value)

#define Iodd_Write_PD(PortName,PinNumber,value)\
        Iodd_Write_PD_Port ## PortName(PortName,PinNumber,value)

#define Iodd_Write_PD_Port0(PortName,PinNumber,value)\
        Iodd_Write_PD_Reg(PortName,PinNumber,value)

#define Iodd_Write_PD_Port1(PortName,PinNumber,value)

#define Iodd_Write_PD_Port2(PortName,PinNumber,value)

#define Iodd_Write_PD_Port8(PortName,PinNumber,value)\
        Iodd_Write_PD_Reg(PortName,PinNumber,value)

#define Iodd_Write_PD_Port9(PortName,PinNumber,value)\
        Iodd_Write_PD_Reg(PortName,PinNumber,value)

#define Iodd_Write_PD_Port10(PortName,PinNumber,value)\
         Iodd_Write_PD_Reg(PortName,PinNumber,value)

#define Iodd_Write_PD_Port11(PortName,PinNumber,value)\
          Iodd_Write_PD_Reg(PortName,PinNumber,value)

#define Iodd_Write_PD_Port12(PortName,PinNumber,value)

#define Iodd_Write_PD_Port18(PortName,PinNumber,value)

#define Iodd_Write_PD_Port20(PortName,PinNumber,value)

#elif defined(__RH850_F1K__)
#define Iodd_SetPullUpBit(PortName,PinNumber) \
        TARG_WriteBitInLong(PORTPU ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 1);\
        TARG_WriteBitInLong(PORTPD ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 0)

#define Iodd_SetNoPullDeviceBit(PortName,PinNumber) \
        TARG_WriteBitInLong(PORTPD ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 0);\
        TARG_WriteBitInLong(PORTPU ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 0)

#define Iodd_SetPullDownBit(PortName,PinNumber) \
        TARG_WriteBitInLong(PORTPD ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 1);\
        TARG_WriteBitInLong(PORTPU ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 0)
#else
#error "no supported MCU type, line422, iodd_rh850.h"
#endif
#endif /* NO_PULLUP */
#endif /* __RH850_F1x__ */


/* Input Pull Up Mode ------------------------------------------------------- */


#ifdef __RH850_F1x__
#define IODD_PULL_UP(PortName,PinNumber) \
        Iodd_SetPullUpBit(PortName,PinNumber)

#define IODD_NO_PULL_UP(PortName,PinNumber) \
        Iodd_SetNoPullDeviceBit(PortName,PinNumber)

#define IODD_PULL_DOWN(PortName,PinNumber) \
        Iodd_SetPullDownBit(PortName,PinNumber)

#define IODD_NO_PULL_OPTION(PortName,PinNumber)
#endif /* __RH850_F1x__ */

/* Output Open Drain State -------------------------------------------------- */

/* Output High-Inpedance selection ------------------------------------------ */

/* Set one bit in a port direction register --------------------------------- */

#if defined (__RH850__)
#if defined (__RH850_F1x__)

#if defined( __RH850_F1L__)

#define Iodd_SetDdrBit(PortName,PinNumber,Value) \
        TARG_WriteBitInShort(PM ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, Value)
#define Iodd_SetInputBuffer(PortName,PinNumber,Value) \
        TARG_WriteBitInShort(PIBC ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, Value)

#elif defined( __RH850_F1K__)

#define Iodd_SetDdrBit(PortName,PinNumber,Value) \
        TARG_WriteBitInShort(PORTPM ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, Value)
#define Iodd_SetInputBuffer(PortName,PinNumber,Value) \
        TARG_WriteBitInShort(PORTPIBC ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, Value)
#endif
#endif /* __RH850_F1x__ */
#endif /*__RH850__*/

/* Get one bit in a port input register ------------------------------------- */

/* Get one bit in a port input register on S08------------------------------- */

#ifdef __RH850__
#if defined (__RH850_F1x__)
#if defined( __RH850_F1L__)

#define Iodd_WREGS_P(PortName,PinNumber,Value) \
        TARG_WriteBitInShort(P ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, Value)
#elif defined( __RH850_F1K__)

#define Iodd_WREGS_P(PortName,PinNumber,Value) \
        TARG_WriteBitInShort(PORTP ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, Value)
#endif




#endif /* __RH850_F1x__ */

#define Iodd_SetOutputReg(PortName,PinNumber,State) \
        Iodd_WREGS_P(PortName,PinNumber,State)
#endif /* __RH850__ */


/* Get one port status bit -------------------------------------------------- */

#ifdef __RH850__
#if defined (__RH850_F1x__)
#define Iodd_GetPinState(PortName,PinNumber) \
        TARG_ReadBitInShort(PPR ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber)
#endif /* __RH850_F1x__ */
#endif /* __RH850__ */


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

#ifdef __RH850__
#ifdef __RH850_F1x__
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
#endif /* __RH850_F1x__ */
#endif /* __RH850__ */


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

#ifdef __RH850__
#define IODD_SetPinDirectionIn(PortName,\
                               PinNumber) \
        Iodd_SetDdrBit(PortName,PinNumber,1)
#endif /* __RH850__ */

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

#ifdef __RH850__
#define IODD_SetPinDirectionOut(PortName,\
                               PinNumber) \
        Iodd_SetDdrBit(PortName,PinNumber,0)
#endif /* __RH850__ */


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

#if defined(__RH850_F1x__)

#if defined(__RH850_F1L__)
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
#define IODD_EnableIrq_IODD_IRQ11      TARG_WriteBit(ICP11L,BIT7,0)
#define IODD_EnableIrq_IODD_IRQ12      TARG_WriteBit(ICP12L,BIT7,0)
#define IODD_EnableIrq_IODD_IRQ13      TARG_WriteBit(ICP13L,BIT7,0)
#define IODD_EnableIrq_IODD_IRQ14      TARG_WriteBit(ICP14L,BIT7,0)
#define IODD_EnableIrq_IODD_IRQ15      TARG_WriteBit(ICP15L,BIT7,0)
#elif  defined(__RH850_F1K__)
#define IODD_EnableIrq_IODD_IRQ0       TARG_WriteBit(INTC2ICP0L,BIT7,0)
#define IODD_EnableIrq_IODD_IRQ1       TARG_WriteBit(INTC2ICP1L,BIT7,0)
#define IODD_EnableIrq_IODD_IRQ2       TARG_WriteBit(INTC2ICP2L,BIT7,0)
#define IODD_EnableIrq_IODD_IRQ3       TARG_WriteBit(INTC2ICP3L,BIT7,0)
#define IODD_EnableIrq_IODD_IRQ4       TARG_WriteBit(INTC2ICP4L,BIT7,0)
#define IODD_EnableIrq_IODD_IRQ5       TARG_WriteBit(INTC2ICP5L,BIT7,0)
#define IODD_EnableIrq_IODD_IRQ6       TARG_WriteBit(INTC2ICP6L,BIT7,0)
#define IODD_EnableIrq_IODD_IRQ7       TARG_WriteBit(INTC2ICP7L,BIT7,0)
#define IODD_EnableIrq_IODD_IRQ8       TARG_WriteBit(INTC2ICP8L,BIT7,0)
#define IODD_EnableIrq_IODD_IRQ9       TARG_WriteBit(INTC2ICP9L,BIT7,0)
#define IODD_EnableIrq_IODD_IRQ10      TARG_WriteBit(INTC2ICP10L,BIT7,0)
#define IODD_EnableIrq_IODD_IRQ11      TARG_WriteBit(INTC2ICP11L,BIT7,0)
#define IODD_EnableIrq_IODD_IRQ12      TARG_WriteBit(INTC2ICP12L,BIT7,0)
#define IODD_EnableIrq_IODD_IRQ13      TARG_WriteBit(INTC2ICP13L,BIT7,0)
#define IODD_EnableIrq_IODD_IRQ14      TARG_WriteBit(INTC2ICP14L,BIT7,0)
#define IODD_EnableIrq_IODD_IRQ15      TARG_WriteBit(INTC2ICP15L,BIT7,0)
#endif

#endif  /* __RH850_F1x__ */



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

#if defined(__RH850_F1x__)

#if defined(__RH850_F1L__)
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
#define IODD_DisableIrq_IODD_IRQ11     TARG_WriteBit(ICP11L,BIT7,1)
#define IODD_DisableIrq_IODD_IRQ12     TARG_WriteBit(ICP12L,BIT7,1)
#define IODD_DisableIrq_IODD_IRQ13     TARG_WriteBit(ICP13L,BIT7,1)
#define IODD_DisableIrq_IODD_IRQ14     TARG_WriteBit(ICP14L,BIT7,1)
#define IODD_DisableIrq_IODD_IRQ15     TARG_WriteBit(ICP15L,BIT7,1)
#elif  defined(__RH850_F1K__)
#define IODD_DisableIrq_IODD_IRQ0      TARG_WriteBit(INTC2ICP0L,BIT7,1)
#define IODD_DisableIrq_IODD_IRQ1      TARG_WriteBit(INTC2ICP1L,BIT7,1)
#define IODD_DisableIrq_IODD_IRQ2      TARG_WriteBit(INTC2ICP2L,BIT7,1)
#define IODD_DisableIrq_IODD_IRQ3      TARG_WriteBit(INTC2ICP3L,BIT7,1)
#define IODD_DisableIrq_IODD_IRQ4      TARG_WriteBit(INTC2ICP4L,BIT7,1)
#define IODD_DisableIrq_IODD_IRQ5      TARG_WriteBit(INTC2ICP5L,BIT7,1)
#define IODD_DisableIrq_IODD_IRQ6      TARG_WriteBit(INTC2ICP6L,BIT7,1)
#define IODD_DisableIrq_IODD_IRQ7      TARG_WriteBit(INTC2ICP7L,BIT7,1)
#define IODD_DisableIrq_IODD_IRQ8      TARG_WriteBit(INTC2ICP8L,BIT7,1)
#define IODD_DisableIrq_IODD_IRQ9      TARG_WriteBit(INTC2ICP9L,BIT7,1)
#define IODD_DisableIrq_IODD_IRQ10     TARG_WriteBit(INTC2ICP10L,BIT7,1)
#define IODD_DisableIrq_IODD_IRQ11     TARG_WriteBit(INTC2ICP11L,BIT7,1)
#define IODD_DisableIrq_IODD_IRQ12     TARG_WriteBit(INTC2ICP12L,BIT7,1)
#define IODD_DisableIrq_IODD_IRQ13     TARG_WriteBit(INTC2ICP13L,BIT7,1)
#define IODD_DisableIrq_IODD_IRQ14     TARG_WriteBit(INTC2ICP14L,BIT7,1)
#define IODD_DisableIrq_IODD_IRQ15     TARG_WriteBit(INTC2ICP15L,BIT7,1)
#endif
#endif  /* __RH850_F1x__ */

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

#if defined(__RH850_F1x__)
#if defined(__RH850_F1L__)
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
#define IODD_ReadStatusIrq_IODD_IRQ11  TARG_ReadBit (ICP11H,BIT4)
#define IODD_ReadStatusIrq_IODD_IRQ12  TARG_ReadBit (ICP12H,BIT4)
#define IODD_ReadStatusIrq_IODD_IRQ13  TARG_ReadBit (ICP13H,BIT4)
#define IODD_ReadStatusIrq_IODD_IRQ14  TARG_ReadBit (ICP14H,BIT4)
#define IODD_ReadStatusIrq_IODD_IRQ15  TARG_ReadBit (ICP15H,BIT4)
#elif  defined(__RH850_F1K__)
#define IODD_ReadStatusIrq_IODD_IRQ0   TARG_ReadBit (INTC2ICP0H,BIT4)
#define IODD_ReadStatusIrq_IODD_IRQ1   TARG_ReadBit (INTC2ICP1H,BIT4)
#define IODD_ReadStatusIrq_IODD_IRQ2   TARG_ReadBit (INTC2ICP2H,BIT4)
#define IODD_ReadStatusIrq_IODD_IRQ3   TARG_ReadBit (INTC2ICP3H,BIT4)
#define IODD_ReadStatusIrq_IODD_IRQ4   TARG_ReadBit (INTC2ICP4H,BIT4)
#define IODD_ReadStatusIrq_IODD_IRQ5   TARG_ReadBit (INTC2ICP5H,BIT4)
#define IODD_ReadStatusIrq_IODD_IRQ6   TARG_ReadBit (INTC2ICP6H,BIT4)
#define IODD_ReadStatusIrq_IODD_IRQ7   TARG_ReadBit (INTC2ICP7H,BIT4)
#define IODD_ReadStatusIrq_IODD_IRQ8   TARG_ReadBit (INTC2ICP8H,BIT4)
#define IODD_ReadStatusIrq_IODD_IRQ9   TARG_ReadBit (INTC2ICP9H,BIT4)
#define IODD_ReadStatusIrq_IODD_IRQ10  TARG_ReadBit (INTC2ICP10H,BIT4)
#define IODD_ReadStatusIrq_IODD_IRQ11  TARG_ReadBit (INTC2ICP11H,BIT4)
#define IODD_ReadStatusIrq_IODD_IRQ12  TARG_ReadBit (INTC2ICP12H,BIT4)
#define IODD_ReadStatusIrq_IODD_IRQ13  TARG_ReadBit (INTC2ICP13H,BIT4)
#define IODD_ReadStatusIrq_IODD_IRQ14  TARG_ReadBit (INTC2ICP14H,BIT4)
#define IODD_ReadStatusIrq_IODD_IRQ15  TARG_ReadBit (INTC2ICP15H,BIT4)
#endif
#endif  /* __RH850_F1x__ */


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

#if defined(__RH850_F1x__)

#if defined( __RH850_F1L__)
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
#define IODD_ClearStatusIrq_IODD_IRQ11 TARG_WriteBit(ICP11H,BIT4,0)
#define IODD_ClearStatusIrq_IODD_IRQ12 TARG_WriteBit(ICP12H,BIT4,0)
#define IODD_ClearStatusIrq_IODD_IRQ13 TARG_WriteBit(ICP13H,BIT4,0)
#define IODD_ClearStatusIrq_IODD_IRQ14 TARG_WriteBit(ICP14H,BIT4,0)
#define IODD_ClearStatusIrq_IODD_IRQ15 TARG_WriteBit(ICP15H,BIT4,0)
#elif defined( __RH850_F1K__)
#define IODD_ClearStatusIrq_IODD_IRQ0  TARG_WriteBit(INTC2ICP0H,BIT4,0)
#define IODD_ClearStatusIrq_IODD_IRQ1  TARG_WriteBit(INTC2ICP1H,BIT4,0)
#define IODD_ClearStatusIrq_IODD_IRQ2  TARG_WriteBit(INTC2ICP2H,BIT4,0)
#define IODD_ClearStatusIrq_IODD_IRQ3  TARG_WriteBit(INTC2ICP3H,BIT4,0)
#define IODD_ClearStatusIrq_IODD_IRQ4  TARG_WriteBit(INTC2ICP4H,BIT4,0)
#define IODD_ClearStatusIrq_IODD_IRQ5  TARG_WriteBit(INTC2ICP5H,BIT4,0)
#define IODD_ClearStatusIrq_IODD_IRQ6  TARG_WriteBit(INTC2ICP6H,BIT4,0)
#define IODD_ClearStatusIrq_IODD_IRQ7  TARG_WriteBit(INTC2ICP7H,BIT4,0)
#define IODD_ClearStatusIrq_IODD_IRQ8  TARG_WriteBit(INTC2ICP8H,BIT4,0)
#define IODD_ClearStatusIrq_IODD_IRQ9  TARG_WriteBit(INTC2ICP9H,BIT4,0)
#define IODD_ClearStatusIrq_IODD_IRQ10 TARG_WriteBit(INTC2ICP10H,BIT4,0)
#define IODD_ClearStatusIrq_IODD_IRQ11 TARG_WriteBit(INTC2ICP11H,BIT4,0)
#define IODD_ClearStatusIrq_IODD_IRQ12 TARG_WriteBit(INTC2ICP12H,BIT4,0)
#define IODD_ClearStatusIrq_IODD_IRQ13 TARG_WriteBit(INTC2ICP13H,BIT4,0)
#define IODD_ClearStatusIrq_IODD_IRQ14 TARG_WriteBit(INTC2ICP14H,BIT4,0)
#define IODD_ClearStatusIrq_IODD_IRQ15 TARG_WriteBit(INTC2ICP15H,BIT4,0)
#endif
#endif  /* __RH850_F1x__     */

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

#ifdef __RH850__
#define IODD_PinSetUpOutput(PortName,\
                            PinNumber,\
                            OpenDrainState) \
        Iodd_SetDdrBit(PortName,PinNumber,0);\
        OpenDrainState(PortName,PinNumber)
#endif /* __RH850__ */


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

#ifdef __RH850_F1x__
#define IODD_SetOpenDrainData(PortName,PinNumber) \
        IODD_OPEN_DRAIN(PortName,PinNumber)
#endif /* __RH850_F1x__ */


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
#if defined(__RH850__)
#define IODD_GetPinStatus(PortName,\
                          PinNumber) \
        Iodd_GetPinState(PortName,PinNumber)
#endif /* defined(__RH850__) */


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
#if defined(__RH850__)
#define IODD_GetPinData(PortName,\
                        PinNumber) \
        Iodd_GetInputReg(PortName,PinNumber)
#endif /* defined(__RH850__)*/


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

#ifdef __RH850__

#define IODD_SetPinData(PortName,\
                        PinNumber,\
                        State) \
        Iodd_SetOutputReg(PortName,PinNumber,State)

#endif /*__RH850__*/


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
#if defined(__RH850__)
#define IODD_ReadBytePortIn(PortName) \
        TARG_ReadByte( P ## PortName)
#endif /* __RH850__ */

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
#ifdef __RH850_F1x__
#define IODD_ReadShortPortIn(PortName) \
        TARG_ReadShort( P ## PortName)
#endif /*__RH850_F1x__*/


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
#ifdef __RH850__
#ifdef __RH850_F1x__

#define IODD_WriteBytePortOut(PortName,Value) \
        (TARG_WriteByte( P ## PortName, Value))

#endif /*__RH850_F1x__*/
#endif /*__RH850__*/

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
#ifdef __RH850_F1x__
#define IODD_WriteShortPortOut(PortName,Value) \
    TARG_WriteShort( P ## PortName, Value);
#endif /* __RH850_F1x__ */


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

#ifdef __RH850_F1x__
#define IODD_WriteShortPortDirection(PortName,\
                                    Value) \
        Iodd_WREG_PM (PortName,Value)
#endif /* __RH850_F1x__ */


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
#if defined(__RH850__)
#ifdef __RH850_F1x__

#define IODD_SetPortDirectionIn(PortName)\
        IODD_WriteShortPortDirection(PortName,0xFFFF)

#endif /* __RH850_F1x__ */
#endif /* __RH850__ */

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

#if defined(__RH850__)
#ifdef __RH850_F1x__

#define IODD_SetPortDirectionOut(PortName)\
        IODD_WriteShortPortDirection(PortName,0x0000)

#endif /* __RH850_F1x__ */
#endif /* __RH850__ */


#ifdef __RH850_F1x__

#if defined (__RH850_F1L__)
#define IODD_ALTER_OUT(PortName,PinNumber)                                               \
        TARG_WriteBitInShort(PM ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 0)

#define IODD_ALTER_IN(PortName,PinNumber)                                               \
        TARG_WriteBitInShort(PM ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 1)

#define IODD_NO_ALTER_FUNC(PortName,PinNumber)                                               \
        TARG_WriteBitInShort(PMC ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 0)
#define IODD_ALTER1_FUNC(PortName,PinNumber)                                                 \
        TARG_WriteBitInShort(PMC ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 1);  \
        IODD_PFCE_WriteBitInShort(PortName, PinNumber, 0); \
        TARG_WriteBitInShort(PFC ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 0)
#define IODD_ALTER2_FUNC(PortName,PinNumber)                                                 \
        TARG_WriteBitInShort(PMC ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 1);  \
        IODD_PFCE_WriteBitInShort(PortName, PinNumber, 0); \
        TARG_WriteBitInShort(PFC ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 1)
#define IODD_ALTER3_FUNC(PortName,PinNumber)                                                 \
        TARG_WriteBitInShort(PMC ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 1);  \
        IODD_PFCE_WriteBitInShort(PortName,  PinNumber, 1); \
        TARG_WriteBitInShort(PFC ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 0)
#define IODD_ALTER4_FUNC(PortName,PinNumber)                                                 \
        TARG_WriteBitInShort(PMC ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 1);  \
        IODD_PFCE_WriteBitInShort(PortName,  PinNumber, 1); \
        TARG_WriteBitInShort(PFC ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 1)
#define IODD_ALTER5_FUNC(PortName,PinNumber)                                                 \
        TARG_WriteBitInShort(PMC ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 1);  \
        TARG_WriteBitInShort(PFCAE ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 1);  \
        IODD_PFCE_WriteBitInShort( PortName, PinNumber, 0); \
        TARG_WriteBitInShort(PFC ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 0)

#define IODD_PFCE_WriteBitInShort(PortName,PinNumber,Value) \
                 IODD_PFCE_Write_Port ## PortName (PortName,PinNumber,Value)

#define IODD_PFCE_WriteReg(PortName,PinNumber,Value) \
                 TARG_WriteBitInShort(PFCE ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, Value)


#define IODD_PFCE_Write_Port0(PortName,PinNumber,Value)\
                IODD_PFCE_WriteReg(PortName,PinNumber,Value)

#define IODD_PFCE_Write_Port1(PortName,PinNumber,Value)

#define IODD_PFCE_Write_Port8(PortName,PinNumber,Value)\
                IODD_PFCE_WriteReg(PortName,PinNumber,Value)

#define IODD_PFCE_Write_Port9(PortName,PinNumber,Value)\
                IODD_PFCE_WriteReg(PortName,PinNumber,Value)

#define IODD_PFCE_Write_Port10(PortName,PinNumber,Value)\
                IODD_PFCE_WriteReg(PortName,PinNumber,Value)

#define IODD_PFCE_Write_Port11(PortName,PinNumber,Value)\
                IODD_PFCE_WriteReg(PortName,PinNumber,Value)

#define IODD_PFCE_Write_Port12(PortName,PinNumber,Value)\
                IODD_PFCE_WriteReg(PortName,PinNumber,Value)

#define IODD_PFCE_Write_Port18(PortName,PinNumber,Value)

#define IODD_PFCE_Write_Port20(PortName,PinNumber,Value)

#elif defined (__RH850_F1K__)

#define IODD_ALTER_OUT(PortName,PinNumber)                                               \
        TARG_WriteBitInShort(PORTPM ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 0)

#define IODD_ALTER_IN(PortName,PinNumber)                                               \
        TARG_WriteBitInShort(PORTPM ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 1)

#define IODD_NO_ALTER_FUNC(PortName,PinNumber)                                               \
        TARG_WriteBitInShort(PORTPMC ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 0)
#define IODD_ALTER1_FUNC(PortName,PinNumber)                                                 \
        TARG_WriteBitInShort(PORTPMC ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 1);  \
        TARG_WriteBitInShort(PORTPFCE ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 0); \
        TARG_WriteBitInShort(PORTPFC ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 0)
#define IODD_ALTER2_FUNC(PortName,PinNumber)                                                 \
        TARG_WriteBitInShort(PORTPMC ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 1);  \
        TARG_WriteBitInShort(PORTPFCE ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 0); \
        TARG_WriteBitInShort(PORTPFC ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 1)
#define IODD_ALTER3_FUNC(PortName,PinNumber)                                                 \
        TARG_WriteBitInShort(PORTPMC ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 1);  \
        TARG_WriteBitInShort(PORTPFCE ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 1); \
        TARG_WriteBitInShort(PORTPFC ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 0)
#define IODD_ALTER4_FUNC(PortName,PinNumber)                                                 \
        TARG_WriteBitInShort(PORTPMC ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 1);  \
        TARG_WriteBitInShort(PORTPFCE ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 1); \
        TARG_WriteBitInShort(PORTPFC ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 1)
#define IODD_ALTER5_FUNC(PortName,PinNumber)                                                 \
        TARG_WriteBitInShort(PORTPMC ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 1);  \
        TARG_WriteBitInShort(PORTPFCAE ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 1);  \
        TARG_WriteBitInShort(PORTPFCE ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 0); \
        TARG_WriteBitInShort(PORTPFC ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 0)

#define IODD_ALTER6_FUNC(PortName,PinNumber)                                                 \
        TARG_WriteBitInShort(PORTPMC ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 1);  \
        TARG_WriteBitInShort(PORTPFCAE ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 1);  \
        TARG_WriteBitInShort(PORTPFCE ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 0); \
        TARG_WriteBitInShort(PORTPFC ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 1)

#define IODD_ALTER7_FUNC(PortName,PinNumber)                                                 \
        TARG_WriteBitInShort(PORTPMC ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 1);  \
        TARG_WriteBitInShort(PORTPFCAE ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 1);  \
        TARG_WriteBitInShort(PORTPFCE ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 1); \
        TARG_WriteBitInShort(PORTPFC ## PortName, PORT_BIT_P ## PortName ## _ ## PinNumber, 0)
#endif
#endif /* __RH850_F1x__ */

#ifdef __RH850_F1x__
#define IODD_INTP0_CTRL_REG   FCLA0CTL0_INTPL
#define IODD_INTP1_CTRL_REG   FCLA0CTL1_INTPL
#define IODD_INTP2_CTRL_REG   FCLA0CTL2_INTPL
#define IODD_INTP3_CTRL_REG   FCLA0CTL3_INTPL
#define IODD_INTP4_CTRL_REG   FCLA0CTL4_INTPL
#define IODD_INTP5_CTRL_REG   FCLA0CTL5_INTPL
#define IODD_INTP6_CTRL_REG   FCLA0CTL6_INTPL
#define IODD_INTP7_CTRL_REG   FCLA0CTL7_INTPL
#define IODD_INTP8_CTRL_REG   FCLA1CTL0_INTPH
#define IODD_INTP9_CTRL_REG   FCLA1CTL1_INTPH
#define IODD_INTP10_CTRL_REG  FCLA1CTL2_INTPH
#define IODD_INTP11_CTRL_REG  FCLA1CTL3_INTPH
#define IODD_INTP12_CTRL_REG  FCLA1CTL4_INTPH
#define IODD_INTP13_CTRL_REG  FCLA1CTL5_INTPH
#define IODD_INTP14_CTRL_REG  FCLA1CTL6_INTPH
#define IODD_INTP15_CTRL_REG  FCLA1CTL7_INTPH
#define IODD_NMI_CTRL_REG     FCLA1CTL0_NMI

#define IODD_BOTH_EDGE       0x03
#define IODD_RISING_EDGE     0x01
#define IODD_FALLING_EDGE    0x05
#define IODD_HIGH_LEVEL      0x05
#define IODD_LOW_LEVEL       0x04

#define IODD_PORT_FILTER_FUNC(IntSource,DectionType) \
    TARG_WriteByte(IntSource##_CTRL_REG, DectionType)
#endif /* __RH850_F1x__ */

/*________ G L O B A L - F U N C T I O N S ___________________________________*/

#ifdef __RH850_F1x__
extern void IODD_SetPortOutputPinData(ubyte PortNumber, ushort PinNumber, ubyte State);
extern bool_t IODD_GetPortOutputPinData(ubyte PortNumber,ubyte PinNumber);
#endif /*__RH850_F1x__*/

#endif /* __RH850__ */

#endif /*IODD_RH850_H*/

/*______ E N D _____ (iodd_rh850.h) ________________________________________________*/
