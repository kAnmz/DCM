/******************************************************************************/
/* @F_NAME:           targ.h                                                  */
/* @F_PURPOSE:        Description of access services for the target           */
/* @F_CREATED_BY:     J-E LUC                                                 */
/* @F_CREATION_DATE:  06/09/2000                                              */
/* @F_MPROC_TYPE:     NEC_V850, MC9S12xx, MC9S08xx, TX49,IMX53 ,REL_RL78,IMX6x*/
/*                    ,rh850                                                  */
/************************************** (C) Copyright 2013 Magneti Marelli ****/

#ifndef TARG_H
#define TARG_H

/*_____ I N C L U D E - F I L E S ____________________________________________*/

#include "type.h"

/*----------------------------------------------------------------------------*/
/* for TVII                                                                   */
/*----------------------------------------------------------------------------*/
#if defined(__CY_TV2__)
#include "targ_TVII.h"
#endif /* __CY_TV2__ */

/*----------------------------------------------------------------------------*/
/* for RH850                                                                  */
/*----------------------------------------------------------------------------*/
#if defined(__RH850__)
#include "targ_rh850.h"
#endif /* __RH850__ */

/*----------------------------------------------------------------------------*/
/* for NEC V850                                                               */
/*----------------------------------------------------------------------------*/
#ifdef __NEC_V850__

  #include "rgv850.h"

#endif /* __NEC_V850__ */

/*----------------------------------------------------------------------------*/
/* for TX49                                                                   */
/*----------------------------------------------------------------------------*/
#ifdef __TX49__

  #include "rgtx49.h"

#endif /* __TX49__ */

/*----------------------------------------------------------------------------*/
/* for __MC9S12xx__                                                           */
/*----------------------------------------------------------------------------*/
#ifdef __MC9S12xx__

  #include "rg12.h"

#endif /* __MC9S12xx__ */

/*----------------------------------------------------------------------------*/
/* for __MC9S08xx__                                                           */
/*----------------------------------------------------------------------------*/
#ifdef __MC9S08xx__

  #include "rg08.h"

#endif /* __MC9S08xx__ */

/*----------------------------------------------------------------------------*/
/* for IMX53 ,IMX6x                                                           */
/*----------------------------------------------------------------------------*/

 
#ifdef __FSL_IMX53x__
 #include "rgimx53.h"
 
  #if defined(C_COMP_GHS_ARM) && !defined(__POLYSPACE__)
    #include "arm_ghs.h"
  #endif /* C_COMP_GHS_ARM */

#endif /* __FSL_IMX53x__ */

#ifdef __FSL_IMX6x__
 #include "rgimx6.h"

   #if defined(C_COMP_GHS_ARM) && !defined(__POLYSPACE__)
    #include "arm_ghs.h"
  #endif /* C_COMP_GHS_ARM */

#endif /*__FSL_IMX6x__ */



/*----------------------------------------------------------------------------*/
/* for RENESAS RL78                                                           */
/*----------------------------------------------------------------------------*/

#ifdef __REL_RL78__
  #include "rgrl78.h"
#endif /* __REL_RL78__ */


/*_____ G L O B A L - D E F I N E ____________________________________________*/


/*_____ G L O B A L - T Y P E S ______________________________________________*/


/*_____ G L O B A L - D A T A ________________________________________________*/


/*_____ G L O B A L - M A C R O S ____________________________________________*/

#ifndef __PC_SIMULATION__

/*----------------------------------------------------------------------------*/
/*Name : TARG_WriteBit                                                        */
/*Role : Assign a value to a bit                                              */
/*Interface :                                                                 */
/*  - Reg   IN, register name [use names define in rgxx_xxx.h]                */
/*  - Bit   IN, bit name [BIT0,BIT1,BIT2,BIT3,BIT4,BIT5,BIT6,BIT7]            */
/*                        if registers are 8 bits   OR                        */
/*  - Bit   IN, bit name [BIT0,BIT1,BIT2,...,BIT28,BIT29,BIT30,BIT31]         */
/*                        if registers are 32 bits                            */
/*  - Value IN, bit value                                                     */
/*Pre-condition : -                                                           */
/*Constraints : -                                                             */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [assign the value to the requested bit]                                 */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#if (defined(__MC9S12xx__) || defined(__MC9S08xx__)     \
      || defined(__NEC_V850__) || defined (__REL_RL78__))
#define TARG_WriteBit(Reg,Bit,Value)                    \
  (*(volatile bitfield_byte_t*)(&Reg))._bit.Bit = Value
#endif /* __MC9S12xx__ || __MC9S08xx__ || __NEC_V850__ */

#if defined(__FSL_IMX53x__)
#if defined(C_COMP_GHS_ARM) && !defined(__POLYSPACE__)
/* LDREX and STREX instructions are used to prevent unexpected */
/* accesses (via interrupt) on 'reg' register                  */
/* LDREX : read current value for 'reg' register and mark it   */
/*         as exclusive access                                 */
/* STREX : verify if current 'reg' register is exclusive       */
/*         access. Return (after write), if write invalid      */
#define TARG_WriteBit(Reg,Bit,Value)                    \
        {                                               \
          register bitfield_long_t Val;                 \
                                                        \
          do                                            \
          {                                             \
            Val._long = __LDREX((int *)&Reg);           \
            Val._bit.Bit = Value;                       \
          } while (__STREX(Val._long, (int *)&Reg));    \
        }
#else
#define TARG_WriteBit(Reg,Bit,Value)                    \
  (*(volatile bitfield_long_t*)(&Reg))._bit.Bit = Value
#endif /* C_COMP_GHS_ARM && !__POLYSPACE__ */
#endif /* __FSL_IMX53x__ */

#if defined(__FSL_IMX6x__)
#define TARG_WriteBit(Reg,Bit,Value)                    \
  (*(volatile bitfield_long_t*)(&Reg))._bit.Bit = Value
#endif /* __FSL_IMX6x__ */

#if defined(__TX49__)
#define TARG_WriteBit(Reg,Bit,Value)                          \
  (*(volatile bitfield_long_long_t*)(&Reg))._bit.Bit = Value
#endif /* __TX49__ */


/*----------------------------------------------------------------------------*/
/*Name : TARG_WriteBitInByte                                                  */
/*Role : Assign a value to a bit into a byte                                  */
/*Interface :                                                                 */
/*  - Reg   IN, register name [use names define in rgxx_xxx.h]                */
/*  - Bit   IN, bit name [BIT0,BIT1,BIT2,BIT3,BIT4,BIT5,BIT6,BIT7]            */
/*  - Value IN, bit value                                                     */
/*Pre-condition : -                                                           */
/*Constraints : -                                                             */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [assign the value to the requested bit]                                 */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#if defined(__TX49__)
#define TARG_WriteBitInByte(Reg,Bit,Value)              \
  (*(volatile bitfield_byte_t*)(&Reg))._bit.Bit = Value
#endif /* __TX49__ */


/*----------------------------------------------------------------------------*/
/*Name : TARG_WriteBitIndexed                                                 */
/*Role : Assign a value to a bit by using an indexed access to the register   */
/*Interface :                                                                 */
/*  - Reg   IN, register name [use names define in rgxx_xxx.h]                */
/*  - Index IN, offset value                                                  */
/*  - Bit   IN, bit name [BIT0,BIT1,BIT2,BIT3,BIT4,BIT5,BIT6,BIT7]            */
/*                        if registers are 8 bits   OR                        */
/*  - Bit   IN, bit name [BIT0,BIT1,BIT2,...,BIT28,BIT29,BIT30,BIT31]         */
/*                        if registers are 32 bits                            */
/*  - Value IN, bit value                                                     */
/*Pre-condition : -                                                           */
/*Constraints : -                                                             */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [assign the value to the requested bit]                                 */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#if (defined(__MC9S12xx__)  || defined(__MC9S08xx__) \
     || defined(__NEC_V850__) || defined(__REL_RL78__))
#define TARG_WriteBitIndexed(Reg,Index,Bit,Value)             \
  (*(volatile bitfield_byte_t*)(&Reg+Index))._bit.Bit = Value
#endif /* __MC9S12xx__ || __MC9S08xx__ || __NEC_V850__ || __REL_RL78__*/

#if defined(__TX49__)
#define TARG_WriteBitIndexed(Reg,Index,Bit,Value)                       \
  (*(volatile bitfield_long_long_t*)(&Reg+Index))._bit.BIT##Bit = Value
#endif /* __TX49__ */

#if defined(__FSL_IMX53x__) || defined(__FSL_IMX6x__)
#define TARG_WriteBitIndexed(Reg,Index,Bit,Value)             \
  (*(volatile bitfield_long_t*)(&Reg+Index))._bit.Bit = Value
#endif /* __FSL_IMX53x__ ,__FSL_IMX6x__ */


/*----------------------------------------------------------------------------*/
/*Name : TARG_WriteByte                                                       */
/*Role : Assign an ubyte value to an 8-bits register                          */
/*Interface :                                                                 */
/*  - Reg   IN, register name [use names define in rgxx_xxx.h]                */
/*  - Value IN, register value                                                */
/*Pre-condition : -                                                           */
/*Constraints : -                                                             */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [assign the value to the requested register]                            */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#define TARG_WriteByte(Reg,Value) \
  (Reg) = (ubyte)(Value)


/*----------------------------------------------------------------------------*/
/*Name : TARG_WriteByteIndexed                                                */
/*Role : Assign an ubyte value to an 8-bits indexed register                  */
/*Interface :                                                                 */
/*  - Reg   IN, register name [use names define in rgxx_xxx.h]                */
/*  - Index IN, offset value                                                  */
/*  - Value IN, register value                                                */
/*Pre-condition : -                                                           */
/*Constraints : -                                                             */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [assign the value to the requested register]                            */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#define TARG_WriteByteIndexed(Reg,Index,Value)              \
  (*(volatile bitfield_byte_t*)(&(Reg)+(Index)))._byte = (Value)


/*----------------------------------------------------------------------------*/
/*Name : TARG_WriteByteInsideLong                                             */
/*Role : Assign a value to a byte inside a 32-bits register                   */
/*Interface :                                                                 */
/*  - Reg   IN, register name [use names define in rgxx_xxx.h]                */
/*  - Index IN, byte position [0,1,2,3]                                       */
/*  - Value IN, byte value                                                    */
/*Pre-condition : -                                                           */
/*Constraints : - Verify if the register allow write on single byte           */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [assign the value to the requested byte]                                */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
/* Verify if it works correctly with all micro */
#define TARG_WriteByteInsideLong(Reg,Index,Value)                 \
  (*(volatile bitfield_long_t*)(&(Reg)))._IndexedByte[(Index)]=(Value)


/*----------------------------------------------------------------------------*/
/*Name : TARG_WriteLongIndexed                                                */
/*Role : Assign an ulong value to a 32-bits indexed register                  */
/*Interface :                                                                 */
/*  - Reg   IN, register name [use names define in rgxx_xxx.h]                */
/*  - Index IN, offset value                                                  */
/*  - Value IN, register value                                                */
/*Pre-condition : -                                                           */
/*Constraints : -                                                             */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [assign the value to the requested register]                            */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#if (!defined(__TX49__)) && (!defined(__FSL_IMX6x__))
#define TARG_WriteLongIndexed(Reg,Index,Value)              \
  (*(volatile bitfield_long_t*)(&(Reg)+(Index)))._long = (Value)
#endif /* !__TX49__ && !__FSL_IMX6x__ */

#if defined(__FSL_IMX6x__)
#define TARG_WriteLongIndexed(Reg,Index,Value)              \
  *(&Reg+Index) = Value
#endif /* __FSL_IMX6x__ */

#if defined(__TX49__)
#define TARG_WriteLongIndexed(Reg,Index,Value)                      \
  (*(volatile bitfield_long_long_t*)(&Reg+Index))._long[0] = Value
#endif /* __TX49__ */

/*----------------------------------------------------------------------------*/
/*Name : TARG_WriteLongLongIndexed                                            */
/*Role : Assign an ulong value to a 32-bits indexed register                  */
/*Interface :                                                                 */
/*  - Reg   IN, register name [use names define in rgxx_xxx.h]                */
/*  - Index IN, offset value                                                  */
/*  - Value IN, register value                                                */
/*Pre-condition : -                                                           */
/*Constraints : -                                                             */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [assign the value to the requested register]                            */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#ifdef __TX49__
#define TARG_WriteLongLongIndexed(Reg,Index,Value)                  \
  (*(volatile bitfield_long_long_t*)(&Reg+Index))._longlong = Value
#endif /* __TX49__ */


/*----------------------------------------------------------------------------*/
/*Name : TARG_WriteShort                                                      */
/*Role : Assign a ushort value to a 16-bits register                          */
/*Interface :                                                                 */
/*  - Reg   IN, register name [use names define in rgxx_xxx.h]                */
/*  - Value IN, register value                                                */
/*Pre-condition : -                                                           */
/*Constraints : -                                                             */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [assign the value to the requested register]                            */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#ifdef __POLYSPACE__
#define TARG_WriteShort(Reg,Value)
#else
#define TARG_WriteShort(Reg,Value)              \
  (Reg) = (ushort)(Value)
#endif

/*----------------------------------------------------------------------------*/
/*Name : TARG_WriteLong                                                       */
/*Role : Assign a ulong value to a 32-bits register                           */
/*Interface :                                                                 */
/*  - Reg   IN, register name [use names define in rgxx_xxx.h]                */
/*  - Value IN, register value                                                */
/*Pre-condition : -                                                           */
/*Constraints : -                                                             */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [assign the value to the requested register]                            */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#if !defined(__TX49__)
#ifdef __POLYSPACE__
#define TARG_WriteLong(Reg,Value)
#else
#define TARG_WriteLong(Reg,Value)                     \
  (Reg) = (ulong)(Value)
#endif /*__POLYSPACE__*/
#endif /* !__TX49__ */

#ifdef __TX49__
#define TARG_WriteLong(Reg,Value)                             \
  (*(volatile bitfield_long_long_t*)(&Reg))._long[0] = Value
#endif /* __TX49__ */


/*----------------------------------------------------------------------------*/
/*Name : TARG_WriteLongLong                                                   */
/*Role : Assign a ulonglong value to a 64-bits register                       */
/*Interface :                                                                 */
/*  - Reg   IN, register name [use names define in rgTX49_xxx.h]              */
/*  - Value IN, register value                                                */
/*Pre-condition : -                                                           */
/*Constraints : -                                                             */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [assign the value to the requested register]                            */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#ifdef __TX49__
#define TARG_WriteLongLong(Reg,Value)                         \
  (*(volatile bitfield_long_long_t*)(&Reg))._longlong = Value
#endif /* __TX49__ */


/*----------------------------------------------------------------------------*/
/*Name : TARG_ReadBit                                                         */
/*Role : Read a bit state                                                     */
/*Interface :                                                                 */
/*  - Reg    IN, register name [use names define in rgxx_xxx.h]               */
/*  - Bit    IN, bit name [BIT0,BIT1,BIT2,BIT3,BIT4,BIT5,BIT6,BIT7]           */
/*                        if registers are 8 bits   OR                        */
/*  - Bit    IN, bit name [BIT0,BIT1,BIT2,...,BIT28,BIT29,BIT30,BIT31]        */
/*                        if registers are 32 bits                            */
/*  - Value OUT, bit value                                                    */
/*Pre-condition : -                                                           */
/*Constraints : -                                                             */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [return the state of the requested bit]                                 */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#if (defined(__MC9S12xx__) || defined(__MC9S08xx__) \
     || defined(__NEC_V850__) || defined(__REL_RL78__))
#define TARG_ReadBit(Reg,Bit)                     \
  ((*(volatile bitfield_byte_t*)(&Reg))._bit.Bit)
#endif /* __MC9S12xx__ || __MC9S08xx__ || __NEC_V850__ */

#if defined(__FSL_IMX53x__) || defined(__FSL_IMX6x__)
#define TARG_ReadBit(Reg,Bit)                     \
  ((*(volatile bitfield_long_t*)(&Reg))._bit.Bit)
#endif /* __FSL_IMX53x__,__FSL_IMX6x__ */

#if defined(__TX49__)
#define TARG_ReadBit(Reg,Bit)                           \
  ((*(volatile bitfield_long_long_t*)(&Reg))._bit.Bit)
#endif /* __TX49__ */


/*----------------------------------------------------------------------------*/
/*Name : TARG_ReadBitInByte                                                   */
/*Role : Read a bit state                                                     */
/*Interface :                                                                 */
/*  - Reg    IN, register name [use names define in rgxx_xxx.h]               */
/*  - Bit    IN, bit name [BIT0,BIT1,BIT2,BIT3,BIT4,BIT5,BIT6,BIT7]           */
/*  - Value OUT, bit value                                                    */
/*Pre-condition : -                                                           */
/*Constraints : -                                                             */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [return the state of the requested bit]                                 */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#if defined(__TX49__)
#define TARG_ReadBitInByte(Reg,Bit)               \
  ((*(volatile bitfield_byte_t*)(&Reg))._bit.Bit)
#endif /* __TX49__ */


/*----------------------------------------------------------------------------*/
/*Name : TARG_ReadBitIndexed                                                  */
/*Role : Read a bit state by using an indexed access to the register          */
/*Interface :                                                                 */
/*  - Reg   IN, register name [use names define in rgxx_xxx.h]                */
/*  - Index IN, offset value                                                  */
/*  - Bit   IN, bit name [BIT0,BIT1,BIT2,BIT3,BIT4,BIT5,BIT6,BIT7]            */
/*                        if registers are 8 bits   OR                        */
/*  - Bit    IN, bit name [BIT0,BIT1,BIT2,...,BIT28,BIT29,BIT30,BIT31]        */
/*                        if registers are 32 bits                            */
/*  - Value OUT, bit value                                                    */
/*Pre-condition : -                                                           */
/*Constraints : -                                                             */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [read the state of the requested bit]                                   */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#if (defined(__MC9S12xx__) || defined(__MC9S08xx__) \
     || defined(__NEC_V850__) || defined(__REL_RL78__))
#define TARG_ReadBitIndexed(Reg,Index,Bit)              \
  ((*(volatile bitfield_byte_t*)(&Reg+Index))._bit.Bit)
#endif /* __MC9S12xx__ || __MC9S08xx__ || __NEC_V850__ || __REL_RL78__*/

#if defined(__FSL_IMX53x__) || defined(__FSL_IMX6x__)
#define TARG_ReadBitIndexed(Reg,Index,Bit)              \
  ((*(volatile bitfield_long_t*)(&Reg+Index))._bit.Bit)
#endif /* __FSL_IMX53x__,__FSL_IMX6x_ */

#if defined(__TX49__)
#define TARG_ReadBitIndexed(Reg,Index,Bit)                    \
  ((*(volatile bitfield_long_long_t*)(&Reg+Index))._bit.Bit)
#endif /* __TX49__ */


/*----------------------------------------------------------------------------*/
/*Name : TARG_ReadByte                                                        */
/*Role : Read the state of an 8-bits register                                 */
/*Interface :                                                                 */
/*  - Reg    IN, register name [use names define in rgxx_xxx.h]               */
/*  - Value  IN, register                                                     */
/*  - Value OUT, register ubyte value                                         */
/*Pre-condition : -                                                           */
/*Constraints : -                                                             */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [read the state of the requested register]                              */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#define TARG_ReadByte(Reg) \
  ((ubyte)(Reg))


/*----------------------------------------------------------------------------*/
/*Name : TARG_ReadByteIndexed                                                 */
/*Role : Read the state of an 8-bits indexed egister                          */
/*Interface :                                                                 */
/*  - Reg    IN, register name [use names define in rgxx_xxx.h]               */
/*  - Value  IN, register                                                     */
/*  - Value OUT, register ubyte value                                         */
/*Pre-condition : -                                                           */
/*Constraints : -                                                             */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [read the state of the requested register]                              */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#define TARG_ReadByteIndexed(Reg,Index)               \
  ((*(volatile bitfield_byte_t*)(&(Reg)+(Index)))._byte)


/*----------------------------------------------------------------------------*/
/*Name : TARG_ReadLongIndexed                                                 */
/*Role : Read the state of a 32-bits indexed egister                          */
/*Interface :                                                                 */
/*  - Reg    IN, register name [use names define in rgxx_xxx.h]               */
/*  - Value  IN, register                                                     */
/*  - Value OUT, register ulong value                                         */
/*Pre-condition : -                                                           */
/*Constraints : -                                                             */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [read the state of the requested register]                              */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#if !defined(__TX49__)
#define TARG_ReadLongIndexed(Reg,Index)               \
  ((*(volatile bitfield_long_t*)(&(Reg)+(Index)))._long)
#endif /* !__TX49__ */

#ifdef __TX49__
#define TARG_ReadLongIndexed(Reg,Index)                       \
  ((*(volatile bitfield_long_long_t*)(&Reg+Index))._long[0])
#endif /* __TX49__ */


/*----------------------------------------------------------------------------*/
/*Name : TARG_ReadByteInsideLong                                              */
/*Role : Read a byte of a 32-bit registers                                    */
/*Interface :                                                                 */
/*  - Reg   IN, register name [use names define in rgxx_xxx.h]                */
/*  - Index IN, byte position [0,1,2,3]                                       */
/*  - Value OUT, byte value                                                   */
/*Pre-condition : -                                                           */
/*Constraints : -  Verify if the register allow write on single byte          */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [read the state of the requested byte]                                  */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
/* Verify if it works correctly with all micro */
#define TARG_ReadByteInsideLong(Reg,Index)                    \
  ((*(volatile bitfield_long_t*)(&(Reg)))._IndexedByte[(Index)])


/*----------------------------------------------------------------------------*/
/*Name : TARG_ReadShort                                                       */
/*Role : Read the state of a 16-bits register                                 */
/*Interface :                                                                 */
/*  - Reg    IN, register name [use names define in rgxx_xxx.h]               */
/*  - Value  IN, register                                                     */
/*  - Value OUT, register ushort value                                        */
/*Pre-condition : -                                                           */
/*Constraints : -                                                             */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [read the state of the requested register]                              */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#define TARG_ReadShort(Reg)                     \
  ((ushort)(Reg))


/*----------------------------------------------------------------------------*/
/*Name : TARG_ReadLong                                                        */
/*Role : Read the state of a 32-bits register                                 */
/*Interface :                                                                 */
/*  - Reg    IN, register name [use names define in rgxx_xxx.h]               */
/*  - Value  IN, register                                                     */
/*  - Value OUT, register ulong value                                         */
/*Pre-condition : -                                                           */
/*Constraints : -                                                             */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [read the state of the requested register]                              */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#if !defined(__TX49__)
#define TARG_ReadLong(Reg)                      \
  ((ulong)(Reg))
#endif /* !__TX49__ */

#ifdef __TX49__
#define TARG_ReadLong(Reg)                              \
  ((*(volatile bitfield_long_long_t*)(&Reg))._long[0])
#endif /* __TX49__ */


/*----------------------------------------------------------------------------*/
/*Name : TARG_ReadLongLong                                                    */
/*Role : Read the state of a 64-bits register                                 */
/*Interface :                                                                 */
/*  - Reg    IN, register name [use names define in rgxx_xxx.h]               */
/*  - Value  IN, register                                                     */
/*  - Value OUT, register ulong value                                         */
/*Pre-condition : -                                                           */
/*Constraints : -                                                             */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [read the state of the requested register]                              */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#ifdef __TX49__
#define TARG_ReadLongLong(Reg)                          \
  ((*(volatile bitfield_long_long_t*)(&Reg))._longlong)
#endif /* __TX49__ */


/*----------------------------------------------------------------------------*/
/*Name : TARG_SetBits                                                         */
/*Role : Set some bits into a register                                        */
/*Interface :                                                                 */
/*  - Reg   IN, register name [use names define in rgxx_xxx.h]                */
/*  - Mask  IN, bit name [MSK_xxx with xxx = bit name, or a logical operation]*/
/*                        with several MSK_xxx bits]                          */
/*                        bit name are define in rgxx_xxx.h files             */
/*Pre-condition : -                                                           */
/*Constraints : - Mask must be accordling with register use                   */
/*                 8 bits or 32 bits                                          */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [Set the requested bits]                                                */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#if (defined(__MC9S12xx__) || defined(__MC9S08xx__) || defined(__NEC_V850__) || defined (__REL_RL78__))
#define TARG_SetBits(Reg,Mask)                              \
  TARG_WriteByte(Reg, (ubyte)(TARG_ReadByte(Reg) | (Mask)))
#endif /* __MC9S12xx__ || __MC9S08xx__ || __NEC_V850__ || __REL_RL78__*/

#if defined(__FSL_IMX53x__) || defined(__FSL_IMX6x__)
#define TARG_SetBits(Reg,Mask)                  \
  TARG_WriteLong(Reg, TARG_ReadLong(Reg) | Mask)
#endif /* __FSL_IMX53x__,__FSL_IMX6x__ */

#if defined(__TX49__)
#define TARG_SetBits(Reg,Mask)                          \
  TARG_WriteLongLong(Reg, TARG_ReadLongLong(Reg) | Mask)
#endif /*  __TX49__ */


/*----------------------------------------------------------------------------*/
/*Name : TARG_SetBitsInByte                                                   */
/*Role : Set some bits into a register of one byte long                       */
/*Interface :                                                                 */
/*  - Reg   IN, register name [use names define in rgxx_xxx.h]                */
/*  - Mask  IN, bit name [MSK_xxx with xxx = bit name, or a logical operation]*/
/*                        with several MSK_xxx bits]                          */
/*Pre-condition : -                                                           */
/*Constraints : - Mask must be accordling with register use                   */
/*                 8 bits or 32 bits                                          */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [Set the requested bits]                                                */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#ifdef __TX49__
#define TARG_SetBitsInByte(Reg, Mask)           \
  Reg |= Mask
#endif /* __TX49__ */

/*----------------------------------------------------------------------------*/
/*Name : TARG_SetBitsInShort                                                  */
/*Role : Set some bits into a register                                        */
/*Interface :                                                                 */
/*  - Reg   IN, register name [use names define in rgxx_xxx.h]                */
/*  - Mask  IN, bit name [MSK_xxx with xxx = bit name, or a logical operation]*/
/*                        with several MSK_xxx bits]                          */
/*                        bit name are define in rgh8_xxx.h files             */
/*Pre-condition : -                                                           */
/*Constraints : - Mask must be accordling with register use                   */
/*                 16bit                                                      */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [Set the requested bits]                                                */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#ifdef __REL_RL78__
#define TARG_SetBitsInShort(Reg,Mask) \
  TARG_WriteShort(Reg, (ushort)(TARG_ReadShort(Reg) | (Mask)))
#endif /* __REL_RL78__ */


/*----------------------------------------------------------------------------*/
/*Name : TARG_SetBitsIndexed                                                  */
/*Role : Set some bits into a register by using an indexed access             */
/*Interface :                                                                 */
/*  - Reg   IN, register name [use names define in rgxx_xxx.h]                */
/*  - Index IN, offset value                                                  */
/*  - Mask  IN, bit name [MSK_xxx with xxx = bit name, or a logical operation]*/
/*                        with several MSK_xxx bits]                          */
/*                        bit name are define in rgxx_xxx.h files             */
/*Pre-condition : -                                                           */
/*Constraints : -                                                             */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [set the requested bits]                                                */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#if (defined(__MC9S12xx__) || defined(__MC9S08xx__) \
     || defined(__NEC_V850__))
#define TARG_SetBitsIndexed(Reg,Index,Mask)                             \
  TARG_WriteByteIndexed(Reg, Index, (ubyte)(TARG_ReadByteIndexed(Reg,Index) | Mask))
#endif /* __MC9S12xx__ || __MC9S08xx__ || __NEC_V850__ */

#if defined(__TX49__) || defined(__FSL_IMX53x__) || defined(__FSL_IMX6x__)
#define TARG_SetBitsIndexed(Reg,Index,Mask)                             \
  TARG_WriteLongIndexed(Reg, Index, TARG_ReadLongIndexed(Reg,Index) | Mask)
#endif /* __TX49__ , __FSL_IMX53x__,__FSL_IMX6x__ */


/*----------------------------------------------------------------------------*/
/*Name : TARG_ClearBits                                                       */
/*Role : Clear some bits into a register                                      */
/*Interface :                                                                 */
/*  - Reg   IN, register name [use names define in rgxx_xxx.h]                */
/*  - Mask  IN, bit name [MSK_xxx with xxx = bit name, or a logical operation]*/
/*                        with several MSK_xxx bits]                          */
/*                        bit name are define in rgxx_xxx.h files             */
/*Pre-condition : -                                                           */
/*Constraints : -                                                             */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [Clear the requested bits]                                              */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#if (defined(__MC9S12xx__) || defined(__MC9S08xx__) || defined(__NEC_V850__) || defined(__REL_RL78__))
#define TARG_ClearBits(Reg,Mask)                              \
  TARG_WriteByte(Reg, (ubyte)(TARG_ReadByte(Reg) & (ubyte)~(ushort)(Mask)))
#endif /* __MC9S12xx__ || __MC9S08xx__ || __NEC_V850__ || __REL_RL78__*/

#if defined(__FSL_IMX53x__) || defined(__FSL_IMX6x__)
#define TARG_ClearBits(Reg,Mask)                    \
  TARG_WriteLong(Reg, TARG_ReadLong(Reg) & ~(Mask))
#endif /* __FSL_IMX53x__ ,__FSL_IMX6x__ */

#if defined(__TX49__)
#define TARG_ClearBits(Reg,Mask)                            \
  TARG_WriteLongLong(Reg, TARG_ReadLongLong(Reg) & ~(Mask))
#endif /* __TX49__ */


/*----------------------------------------------------------------------------*/
/*Name : TARG_ClearBitsInShort                                                */
/*Role : Clear some bits into a register                                      */
/*Interface :                                                                 */
/*  - Reg   IN, register name [use names define in rgh8_xxx.h]                */
/*  - Mask  IN, bit name [MSK_xxx with xxx = bit name, or a logical operation]*/
/*                        with several MSK_xxx bits]                          */
/*                        bit name are define in rgh8_xxx.h files             */
/*Pre-condition : -                                                           */
/*Constraints : -                                                             */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [Clear the requested bits]                                              */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#ifdef __REL_RL78__
#define TARG_ClearBitsInShort(Reg,Mask) \
  TARG_WriteShort(Reg, (ushort)(TARG_ReadShort(Reg) & ~((ushort)Mask)))
#endif /* __REL_RL78__ */


/*----------------------------------------------------------------------------*/
/*Name : TARG_ClearBitsInByte                                                 */
/*Role : Clear some bits into a register of one byte long                     */
/*Interface :                                                                 */
/*  - Reg   IN, register name [use names define in rg_xxx.h]                  */
/*  - Mask  IN, bit name [MSK_xxx with xxx = bit name, or a logical operation]*/
/*                        with several MSK_xxx bits]                          */
/*Pre-condition : -                                                           */
/*Constraints : -                                                             */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [Clear the requested bits]                                              */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#ifdef __TX49__
#define TARG_ClearBitsInByte(Reg, Mask)         \
  Reg &= ~Mask
#endif /* __TX49__ */


/*----------------------------------------------------------------------------*/
/*Name : TARG_ClearBitsIndexed                                                */
/*Role : Clear some bits into a register by using an indexed access           */
/*Interface :                                                                 */
/*  - Reg   IN, register name [use names define in rgxx_xxx.h]                */
/*  - Index IN, offset value                                                  */
/*  - Mask  IN, bit name [MSK_xxx with xxx = bit name, or a logical operation]*/
/*                        with several MSK_xxx bits]                          */
/*                        bit name are define in rgxx_xxx.h files             */
/*Pre-condition : -                                                           */
/*Constraints : -                                                             */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [Clear the requested bits]                                              */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#if (defined(__MC9S12xx__) || defined(__MC9S08xx__) \
     || defined(__NEC_V850__))
#define TARG_ClearBitsIndexed(Reg,Index,Mask)                           \
  TARG_WriteByteIndexed(Reg,                                            \
                        Index,                                          \
                        (ubyte)(TARG_ReadByteIndexed(Reg, Index) & ~(Mask)))
#endif /* __MC9S12xx__ || __MC9S12xx__ || __MC9S08xx__
          || __NEC_V850__ */

#if defined(__TX49__) || defined(__FSL_IMX53x__)|| defined(__FSL_IMX6x__)
#define TARG_ClearBitsIndexed(Reg,Index,Mask)                           \
  TARG_WriteLongIndexed(Reg, Index, TARG_ReadLongIndexed(Reg, Index) & ~(Mask))
#endif /* __TX49__ || __FSL_IMX53x__ ,_FSL_IMX6x__*/


/*----------------------------------------------------------------------------*/
/*Name : TARG_WriteField                                                      */
/*Role : Write a field value in a register. Do not use this interface for     */
/*       writing one bit (use TARG_WriteBit(Reg,Bit,Value)).                  */
/*Interface :                                                                 */
/*  - Reg   IN, register name [use names define in rgyy.h]                    */
/*  - Field IN, Name of the field                                             */
/*              [Field names definition are done in rgyy_xxx.h with following */
/*              convention:                                                   */
/*              Field Start BIT : #define XXX_FIELDNAME_FSBIT  x              */
/*              Field MaSK      : #define XXX_FIELDNAME_FMSK   y ]            */
/*  - Value IN, value to be written                                           */
/*Pre-condition : -                                                           */
/*Constraints : -                                                             */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [Write the requested field value]                                       */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#if defined(__FSL_IMX53x__) || defined(__FSL_IMX6x__)
#define TARG_WriteField(Reg, Field, Value)                              \
  TARG_WriteLong(Reg, ( ((TARG_ReadLong(Reg)) & (~(Field ## _FMSK)))    \
                        | (((ulong)(Value)<<(Field ## _FSBIT)) & (Field ## _FMSK)) ) )
#endif /* __FSL_IMX53x__ ,_FSL_IMX6x__*/

/*----------------------------------------------------------------------------*/
/*Name : TARG_ReadField                                                       */
/*Role : Read a field value in a register. Do not use this interface for      */
/*       reading one bit (use TARG_ReadBit(Reg,Bit)).                         */
/*Interface :                                                                 */
/*  - Reg   IN, register name [use names define in rgyy.h]                    */
/*  - Field IN, Name of the field                                             */
/*              [Field names definition are done in rgyy_xxx.h with following */
/*              convention:                                                   */
/*              Field Start BIT : #define XXX_FIELDNAME_FSBIT  x              */
/*              Field MaSK      : #define XXX_FIELDNAME_FMSK   y ]            */
/*  - Value OUT, field value                                                  */
/*Pre-condition : -                                                           */
/*Constraints :   -                                                           */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [Read the requested field value]                                        */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#if defined(__FSL_IMX53x__) || defined(__FSL_IMX6x__)
#define TARG_ReadField(Reg, Field)                              \
  ((TARG_ReadLong(Reg) & (Field ## _FMSK))>>(Field ## _FSBIT))
#endif /* __FSL_IMX53x__,_FSL_IMX6x__ */


/*----------------------------------------------------------------------------*/
/* for V850E2/Dx4                                                             */
/*----------------------------------------------------------------------------*/

#ifdef __REL_V850_Dx4__

/*----------------------------------------------------------------------------*/
/*Name : TARG_ProtWriteLong                                                   */
/*Role : Execute the adequate sequence to write to protected registers        */
/*Interface :                                                                 */
/*  - ProtReg   IN, name of the protection register                           */
/*  - RegName   IN, name of the protected register                            */
/*  - Value     IN, value to set the register                                 */
/*Pre-condition : -                                                           */
/*Constraints : Specify the adequate protection register                      */
/*Behavior :                                                                  */
/* 1. Write the fixed value A5H to the protection command register            */
/* 2. Write the desired value to the protected register                       */
/* 3. Write the bit-wise inversion of the desired value to the protected reg. */
/* 4. Write the desired value to the protected register                       */
/*----------------------------------------------------------------------------*/
#define TARG_ProtWriteLong(ProtReg, RegName, Value) \
    TARG_WriteLong(ProtReg,    0xa5);               \
    TARG_WriteLong(RegName,  (Value));              \
    TARG_WriteLong(RegName, ~(Value));              \
    TARG_WriteLong(RegName,  (Value))

/*----------------------------------------------------------------------------*/
/*Name : TARG_ProtWriteLong_Port                                              */
/*Role : Execute the adequate sequence to write to port protected registers   */
/*Interface :                                                                 */
/*  - ProtReg   IN, name of the protection register                           */
/*  - ProtStatusReg  IN, name of the protection status register               */
/*  - RegName   IN, name of the port protected register                       */
/*  - Value     IN, value to set the register                                 */
/*Pre-condition : -                                                           */
/*Constraints : Specify the adequate protection register                      */
/*Behavior :                                                                  */
/* 1. Write the fixed value A5H to the protection command register            */
/* 2. Write the desired value to the protected register                       */
/* 3. Write the bit-wise inversion of the desired value to the protected reg. */
/* 4. Write the desired value to the protected register                       */
/* 5. Repeat above four steps until PROTSnERR bit is not cleared.             */
/*----------------------------------------------------------------------------*/
#define TARG_ProtWriteLong_Port(ProtReg,ProtStatusReg,RegName, Value) \
        do { \
             TARG_WriteLong(ProtReg, 0xa5); \
             TARG_WriteLong(RegName, (Value)); \
             TARG_WriteLong(RegName, ~(Value)); \
             TARG_WriteLong(RegName, (Value)) ; \
           } while(TARG_ReadLong(ProtStatusReg))

/*----------------------------------------------------------------------------*/
/*Name : TARG_WriteBitInShort                                                 */
/*Role : Assign a value to a bit into a short                                 */
/*Interface :                                                                 */
/*  - Reg   IN, register name [use names define in rgxx_xxx.h]                */
/*  - Bit   IN, bit name [BIT0,BIT1,BIT2,......,BIT13,BIT14,BIT15]            */
/*  - Value IN, bit value                                                     */
/*Pre-condition : -                                                           */
/*Constraints : -                                                             */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [assign the value to the requested bit]                                 */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#define TARG_WriteBitInShort(Reg,Bit,Value)              \
  (*(volatile bitfield_short_t*)(&Reg))._bit.Bit = Value


/*----------------------------------------------------------------------------*/
/*Name : TARG_WriteBitInLong                                                  */
/*Role : Assign a value to a bit into a long                                  */
/*Interface :                                                                 */
/*  - Reg   IN, register name [use names define in rgxx_xxx.h]                */
/*  - Bit   IN, bit name [BIT0,BIT1,BIT2,......,BIT29,BIT30,BIT31]            */
/*  - Value IN, bit value                                                     */
/*Pre-condition : -                                                           */
/*Constraints : -                                                             */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [assign the value to the requested bit]                                 */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#define TARG_WriteBitInLong(Reg,Bit,Value)              \
  (*(volatile bitfield_long_t*)(&Reg))._bit.Bit = Value


/*----------------------------------------------------------------------------*/
/*Name : TARG_ClearBitsInShort                                                */
/*Role : Clear some bits into a short register                                */
/*Interface :                                                                 */
/*  - Reg   IN, 16-bits register name [use names define in rgv850_xxx.h]      */
/*  - Mask  IN, bit name [MSK_xxx with xxx = bit name, or a logical operation]*/
/*                        with several MSK_xxx bits]                          */
/*                        bit name are define in rgv850_xxx.h files           */
/*Pre-condition : -                                                           */
/*Constraints : -                                                             */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [Clear the requested bits]                                              */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#define TARG_ClearBitsInShort(Reg,Mask)                       \
  TARG_WriteShort(Reg, (ushort)(TARG_ReadShort(Reg) & ~(Mask)))


/*----------------------------------------------------------------------------*/
/*Name : TARG_ClearBitsInLong                                                 */
/*Role : Clear some bits into a long register                                 */
/*Interface :                                                                 */
/*  - Reg   IN, 32-bits register name [use names define in rgv850_xxx.h]      */
/*  - Mask  IN, bit name [MSK_xxx with xxx = bit name, or a logical operation]*/
/*                        with several MSK_xxx bits]                          */
/*                        bit name are define in rgv850_xxx.h files           */
/*Pre-condition : -                                                           */
/*Constraints : -                                                             */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [Clear the requested bits]                                              */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#define TARG_ClearBitsInLong(Reg,Mask)                       \
  TARG_WriteLong(Reg, (ulong)(TARG_ReadLong(Reg) & ~(Mask)))


/*----------------------------------------------------------------------------*/
/*Name : TARG_ReadBitInShort                                                  */
/*Role : Read a bit state in a 16-bits register                               */
/*Interface :                                                                 */
/*  - Reg    IN, register name [use names define in rgv850_xxx.h]             */
/*  - Bit    IN, bit name [BIT0,BIT1,BIT2,...,BIT12,BIT13,BIT14,BIT15]        */
/*  - Value  OUT, bit value                                                   */
/*Pre-condition : -                                                           */
/*Constraints : -                                                             */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [return the state of the requested bit]                                 */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#define TARG_ReadBitInShort(Reg,Bit)              \
  ((*(volatile bitfield_short_t*)(&Reg))._bit.Bit)


/*----------------------------------------------------------------------------*/
/*Name : TARG_ReadBitInLong                                                   */
/*Role : Read a bit state in a 32-bits register                               */
/*Interface :                                                                 */
/*  - Reg    IN, register name [use names define in rgv850_xxx.h]             */
/*  - Bit    IN, bit name [BIT0,BIT1,BIT2,...,BIT30,BIT31]                    */
/*  - Value  OUT, bit value                                                   */
/*Pre-condition : -                                                           */
/*Constraints : -                                                             */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [return the state of the requested bit]                                 */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#define TARG_ReadBitInLong(Reg,Bit)              \
  ((*(volatile bitfield_long_t*)(&Reg))._bit.Bit)


/*----------------------------------------------------------------------------*/
/*Name : TARG_SetBitsInShort                                                  */
/*Role : Set some bits into a 16-bits register                                */
/*Interface :                                                                 */
/*  - Reg   IN, register name [use names define in rgxx_xxx.h]                */
/*  - Mask  IN, bit name [MSK_xxx with xxx = bit name, or a logical operation]*/
/*                        with several MSK_xxx bits]                          */
/*                        bit name are define in rgv850_xxx.h files           */
/*Pre-condition : -                                                           */
/*Constraints : - Mask must be accordling with register use                   */
/*                 16 bits                                                    */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [Set the requested bits]                                                */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#define TARG_SetBitsInShort(Reg,Mask)                              \
  TARG_WriteShort(Reg, (ushort)(TARG_ReadShort(Reg) | (Mask)))


/*----------------------------------------------------------------------------*/
/*Name : TARG_SetBitsInLong                                                   */
/*Role : Set some bits into a 32-bits register                                */
/*Interface :                                                                 */
/*  - Reg   IN, register name [use names define in rgxx_xxx.h]                */
/*  - Mask  IN, bit name [MSK_xxx with xxx = bit name, or a logical operation]*/
/*                        with several MSK_xxx bits]                          */
/*                        bit name are define in rgv850_xxx.h files           */
/*Pre-condition : -                                                           */
/*Constraints : - Mask must be accordling with register use                   */
/*                 32 bits                                                    */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [Set the requested bits]                                                */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#define TARG_SetBitsInLong(Reg,Mask)                              \
  TARG_WriteLong(Reg, (ulong)(TARG_ReadLong(Reg) | (Mask)))

#endif /* __REL_V850_Dx4__ */

#ifdef __REL_RL78__

/*----------------------------------------------------------------------------*/
/*Name : TARG_ReadBitInShort                                                  */
/*Role : Read a bit state in a 16-bits register                               */
/*Interface :                                                                 */
/*  - Reg    IN, register name [use names define in rgv850_xxx.h]             */
/*  - Bit    IN, bit name [BIT0,BIT1,BIT2,...,BIT12,BIT13,BIT14,BIT15]        */
/*  - Value  OUT, bit value                                                   */
/*Pre-condition : -                                                           */
/*Constraints : -                                                             */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [return the state of the requested bit]                                 */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#define TARG_ReadBitInShort(Reg,Bit)              \
  ((*(volatile bitfield_short_t*)(&Reg))._bit.Bit)
  

/*----------------------------------------------------------------------------*/
/*Name : TARG_WriteBitInShort                                                 */
/*Role : Assign a value to a bit into a short                                 */
/*Interface :                                                                 */
/*  - Reg   IN, register name [use names define in rgxx_xxx.h]                */
/*  - Bit   IN, bit name [BIT0,BIT1,BIT2,......,BIT13,BIT14,BIT15]            */
/*  - Value IN, bit value                                                     */
/*Pre-condition : -                                                           */
/*Constraints : -                                                             */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [assign the value to the requested bit]                                 */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/  
#define TARG_WriteBitInShort(Reg,Bit,Value)                    \
  (*(volatile bitfield_short_t*)(&Reg))._bit.Bit = Value  
  

#endif /* __REL_Rl78__ */

#else

#include "targ_simul.h"

#endif /*__PC_SIMULATION__*/


#endif /* TARG_H */


/*_____ E N D _____ (TARG.h) _________________________________________________*/
