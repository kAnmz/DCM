/**
 * @file targ.h
 * @author Colea (Colea@foxmail.com)
 * @brief Target register access API header file.
 * @version 1.1
 * @date 2019-04-07
 * @copyright Copyright (c) 2019 Marelli Inc. All rights reserved.
 */
#ifndef TARG_H
#define TARG_H

/*_____ I N C L U D E - F I L E S ____________________________________________*/
#include "type.h"

/*_____ G L O B A L - M A C R O S ____________________________________________*/

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
        TARG_WriteLong(ProtReg,    0xa5);           \
        TARG_WriteLong(RegName,  (Value));          \
        TARG_WriteLong(RegName, ~(Value));          \
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
#define TARG_ProtWriteLong_Port(ProtReg, ProtStatusReg, RegName, Value) \
        do { \
             TARG_WriteLong(ProtReg, 0xa5);     \
             TARG_WriteLong(RegName, (Value));  \
             TARG_WriteLong(RegName, ~(Value)); \
             TARG_WriteLong(RegName, (Value)) ; \
           } while(TARG_ReadLong(ProtStatusReg) != 0u)


/**
 * @brief TARG_WriteByte, assign an ubyte value to an 8-bits register
 * @param Reg, register name
 * @param Value, register value
 */
#define TARG_WriteByte(Reg,Value) \
        (Reg) = (ubyte)(Value)

/**
 * @brief TARG_WriteShort, assign a ushort value to a 16-bits register
 * @param Reg, register name 
 * @param Value, register value
 */
#define TARG_WriteShort(Reg,Value) \
        (Reg) = (ushort)(Value)


/**
 * @brief TARG_WriteLong, assign a ulong value to a 32-bits register
 * @param Reg, register name
 * @param Value, register value
 */
#define TARG_WriteLong(Reg,Value) \
        (Reg) = (ulong)(Value)

/**
 * @brief TARG_WriteByteIndexed, assign an ubyte value to an 8-bits indexed register
 * @param Reg, register name 
 * @param Index, offset value
 * @param Value, register value
 */
#define TARG_WriteByteIndexed(Reg,Index,Value) \
  (*(volatile bitfield_byte_t*)(&(Reg)+(Index))).data = (Value)


/**
 * @brief TARG_WriteBit, assign a value to the requested bit 
 * @param Reg, register name
 * @param Bit, bit name [BIT0,BIT1,BIT2,...,BIT8]
 * @param Value, bit value
 */
#define TARG_WriteBit(Reg, Bit, Value) \
        (*(volatile bitfield_byte_t*)(&Reg)).Bit = (Value)

/**
 * @brief TARG_WriteBitInShort, assign a value to a bit into a short 
 * @param Reg, register name
 * @param Bit, bit name [BIT0,BIT1,BIT2,......,BIT13,BIT14,BIT15] 
 * @param Value, bit value 
 */
#define TARG_WriteBitInShort(Reg, Bit, Value) \
        (*(volatile bitfield_short_t*)(&(Reg))).Bit = (Value)


/**
 * @brief TARG_WriteBitInLong, assign a value to a bit into a long 
 * @param Reg, register name
 * @param Bit, bit name [BIT0,BIT1,BIT2,...,BIT28,BIT29,BIT30,BIT31]
 * @param Value, bit value 
 */
#define TARG_WriteBitInLong(Reg, Bit, Value) \
        (*(volatile bitfield_long_t*)(&(Reg))).Bit = (Value)

/**
 * @brief TARG_ReadByte, read the state of an 8-bit register
 * @param Reg, 8-bits register name 
 */
#define TARG_ReadByte(Reg) \
        ((ubyte)(Reg))

/**
 * @brief TARG_ReadShort, read the state of an 16-bit register
 * @param Reg, 16-bits register name
 */
#define TARG_ReadShort(Reg) \
        ((ushort)(Reg))

/**
 * @brief TARG_ReadLong, read the state of an 32-bit register
 * @param Reg, 16-bits register name
 */
#define TARG_ReadLong(Reg)  \
        ((ulong)(Reg))

/**
 * @brief TARG_WriteBit, assign a value to the requested bit 
 * @param Reg, register name
 * @param Bit, bit name [BIT0,BIT1,BIT2,...,BIT8]
 */
#define TARG_ReadBitInByte(Reg, Bit) \
        (*(volatile bitfield_byte_t*)(&Reg)).##Bit)

/**
 * @brief TARG_ReadBitInShort, Read a bit state in a 16-bits register
 * @param Reg, register name
 * @param Bit, bit name [BIT0,BIT1,BIT2,......,BIT13,BIT14,BIT15] 
 */
#define TARG_ReadBitInShort(Reg, Bit) \
       ((*(volatile bitfield_short_t*)(&(Reg))).##Bit)


/**
 * @brief TARG_ReadBitInLong, Read a bit state in a 32-bits register
 * @param Reg, register name
 * @param Bit, bit name [BIT0,BIT1,BIT2,...,BIT28,BIT29,BIT30,BIT31]
 */
#define TARG_ReadBitInLong(Reg, Bit) \
        ((*(volatile bitfield_long_t*)(&(Reg))).##Bit)


/**
 * @brief TARG_SetBitInShort, Set some bits into a 16-bits register
 * @param Reg, 16-bits register name
 * @param Mask, bit name [MSK_xxx with xxx = bit name, or a logical operation]
 */
#define TARG_SetBitsInShort(Reg, Mask) \
        TARG_WriteShort(Reg, (ushort)(TARG_ReadShort(Reg) | (Mask)))


/**
 * @brief TARG_ClearBitsInShort,clear some bits into a 16-bits register
 * @param Reg, 16-bits register name
 * @param Mask, bit name [MSK_xxx with xxx = bit name, or a logical operation]
 */
#define TARG_CleartBitsInShort(Reg, Mask) \
        TARG_WriteShort(Reg, (ushort)(TARG_ReadShort(Reg) & ~(Mask)))


/**
 * @brief TARG_SetBitsInLong, Set some bits into a 32-bits register 
 * @param Set some bits into a 32-bits register
 * @param Mask, bit name [MSK_xxx with xxx = bit name, or a logical operation]
 */
#define TARG_SetBitsInLong(Reg,Mask)  \
  TARG_WriteLong(Reg, (ulong)(TARG_ReadLong(Reg) | (Mask)))

/**
 * @brief TARG_SetBits, set some bit into a register 
 * @param Reg, register name
 * @param Mask, bit name [MSK_xxx with xxx = bit name, or a logical operation]
 */
#define TARG_SetBits(Reg,Mask)  \
  TARG_WriteLong(Reg, TARG_ReadLong(Reg) | (Mask))

/**
 * @brief TARG_ClearBitsInShort, clear some bits into a short register
 * @param Reg, 16-bits register name
 * @param Mask, bit name [MSK_xxx with xxx = bit name, or a logical operation]
 */
#define TARG_ClearBitsInShort(Reg, Mask) \
        TARG_WriteShort(Reg, (ushort)(TARG_ReadShort(Reg) & ~(Mask)))


/**
 * @brief TARG_ClearBitsInLong, clear some bits into a long register
 * @param Reg, 32-bits register name
 * @param Mask, bit name [MSK_xxx with xxx = bit name, or a logical operation]
 */
#define TARG_ClearBitsInLong(Reg, Mask) \
        TARG_WriteLong(Reg, (ulong)(TARG_ReadLong(Reg) & ~(Mask)))

/**
 * @brief TARG_ClearBits, clear some bit into a retister
 * @param Reg, register name
 * @param Mask, bit name [MSK_xxx with xxx = bit name, or a logical operation]
 */
#define TARG_ClearBits(Reg,Mask)  \
        TARG_WriteLong(Reg, TARG_ReadLong(Reg) & ~(Mask))


#define SET_BIT(REG, BIT)    ((REG) |= (BIT))
#define CLEAR_BIT(REG, BIT)  ((REG) &=~(BIT))
#define READ_BIT(REG, BIT)   ((REG) &  (BIT))

#define CLEAR_REG(REG)       ((REG) =  (0x0))
#define WRITE_REG(REG, VAL)  ((REG) =  (VAL))
#define READ_REG(REG)        ((REG))

#define MODIFY_REG(REG, CLEARMASK, SETMASK)\
        WRITE_REG((REG), (((READ_REG(REG)) & (~(CLEARMASK))|(SETMASK)))

#endif /* TARG_H */


/*_____ E N D _____ (targ.h) _________________________________________________*/
