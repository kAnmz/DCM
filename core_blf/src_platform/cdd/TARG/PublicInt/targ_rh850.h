/******************************************************************************/
/* @F_NAME:           targ_rh850.h                                            */
/* @F_PURPOSE:        Description of access services for the target           */
/* @F_CREATED_BY:     shubin liang                                            */
/* @F_CREATION_DATE:  03/08/2017                                              */
/* @F_MPROC_TYPE:     RH850 F1x*/
/************************************** (C) Copyright 2013 Magneti Marelli ****/

#ifndef TARG_RH850_H
#define TARG_RH850_H

/*_____ I N C L U D E - F I L E S ____________________________________________*/

#include "type.h"

#if defined(__RH850_F1x__)
#include "rgrh850.h"
#include "rh850_f1x.h"
#endif

/*_____ G L O B A L - D E F I N E ____________________________________________*/


/*_____ G L O B A L - T Y P E S ______________________________________________*/


/*_____ G L O B A L - D A T A ________________________________________________*/


/*_____ G L O B A L - M A C R O S ____________________________________________*/


#ifdef __RH850_F1x__

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
           } while(TARG_ReadLong(ProtStatusReg) != 0u)

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
#define TARG_WriteBit(Reg,Bit,Value)                    \
  (*(volatile bitfield_byte_t*)(&Reg))._bit.Bit = Value


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
  (*(volatile bitfield_short_t*)(&(Reg)))._bit.Bit = (Value)


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
  (*(volatile bitfield_long_t*)(&(Reg)))._bit.Bit = (Value)


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
#define TARG_ReadBitInByte(Reg,Bit)                           \
  ((*(volatile bitfield_byte_t*)(&(Reg)))._bit.##Bit)

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
  ((*(volatile bitfield_short_t*)(&(Reg)))._bit.##Bit)


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
  ((*(volatile bitfield_long_t*)(&(Reg)))._bit.##Bit)


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
/*Name : TARG_ClearBitsInShort                                                */
/*Role : clear some bits into a 16-bits register                              */
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
#define TARG_CleartBitsInShort(Reg,Mask)                             \
  TARG_WriteShort(Reg, (ushort)(TARG_ReadShort(Reg) & ~(Mask)))

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

#define TARG_ClearBits(Reg,Mask)                  \
  TARG_WriteLong(Reg, TARG_ReadLong(Reg) & ~(Mask))

#define TARG_SetBits(Reg,Mask)                    \
  TARG_WriteLong(Reg, TARG_ReadLong(Reg) | (Mask))

#endif /* __RH850_F1x__ */



#endif /* TARG_RH850_H */


/*_____ E N D _____ (targ_rh850.h) _________________________________________________*/
