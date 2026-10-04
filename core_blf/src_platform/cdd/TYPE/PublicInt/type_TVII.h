/******************************************************************************/
/* @F_NAME:           type.h                                                  */
/* @F_PURPOSE:        Definition of basic types and define                    */
/* @F_CREATED_BY:     Vincent RIOUAL                                          */
/* @F_CREATION_DATE:  21/12/2000                                              */
/* @F_MPROC_TYPE:     NEC_V850, MC9S12xx, MC9S08xx, TX49, IMX53, REL_RL78,IMX6x     */
/************************************** (C) Copyright 2013 Magneti Marelli ****/

#ifndef TYPE_TVII_H
#define TYPE_TVII_H

/*_____ I N C L U D E - F I L E S ____________________________________________*/

#if defined(C_COMP_GHS_ARM)
  #include "cmsis_compiler.h"
#endif /* defined(C_COMP_GHS_ARM) */

/*_____ G L O B A L - M A C R O S ____________________________________________*/

//#pragma anon_unions

/* #define __LITTLE_ENDIAN__ */
    /*  __BIG_ENDIAN__ */
    /*  __LITTLE_ENDIAN__ */

#define __BITFIELD_LSB_FIRST__
     /* __BITFIELD_LSB_FIRST__ */
     /* BITFIELD_MSB_FIRST */
     

/*_____ G L O B A L - T Y P E S ______________________________________________*/

/* Interrupt control definition */
#if defined __BLF_LINK__ /* only used for Bootloader */
#define EnableAllInterrupts()   __enable_irq()
#define DisableAllInterrupts()  __disable_irq()
#endif 
#ifndef __POLYSPACE__
#define Poly_DisableAllInterrupts()  DisableAllInterrupts()
#else
extern void Poly_DisableAllInterrupts(void);
#endif /* !__POLYSPACE__ */

/******************************************************************************/
/* Name : Poly_EnableAllInterrupts                                            */
/* Role : Enable all maskable interrupts of the system                        */
/* Interface : OSEK compliant                                                 */
/* Pre-condition : none                                                       */
/* Constraints : - Do not call this service in an interrupt function          */
/*               - Must be called instead of EnableAllInterrupts() when       */
/*                 critical section starts whith Poly_DisableAllInterrupts(). */
/******************************************************************************/
#ifndef __POLYSPACE__
#define Poly_EnableAllInterrupts()  EnableAllInterrupts()
#else
extern void Poly_EnableAllInterrupts(void);
#endif /* !__POLYSPACE__ */

#if 0
/* basic types definition */
 typedef unsigned char  bool_t;
/* #define bool bool_t */

typedef unsigned char   ubyte;   /* unsigned byte       (1 byte ) */
typedef signed   char   sbyte;   /* signed byte         (1 byte ) */

typedef unsigned short int  ushort;  /* short unsigned word (2 bytes) */
typedef signed   short int  sshort;  /* short signed word   (2 bytes) */

typedef unsigned long  int  ulong;   /* long unsigned word  (4 bytes) */
typedef signed   long  int  slong;   /* long signed word    (4 bytes) */

typedef unsigned long long int ulonglong; /* long unsigned long  (8 bytes) */
typedef signed long long  int  slonglong; /* long signed long    (8 bytes) */
#endif
//typedef ulong uint32_t;

#if 0
/* Type definition for byte and bit acces */
typedef union
{
  ubyte data; /* for byte acces */
  struct
  {
  #ifdef __BITFIELD_LSB_FIRST__
    ubyte BIT0 :1;    /* lsb */
    ubyte BIT1 :1;
    ubyte BIT2 :1;
    ubyte BIT3 :1;
    ubyte BIT4 :1;
    ubyte BIT5 :1;
    ubyte BIT6 :1;
    ubyte BIT7 :1;    /* msb */
  #endif /* __BITFIELD_LSB_FIRST__ */

  #ifdef __BITFIELD_MSB_FIRST__
    ubyte BIT7 :1;    /* msb */
    ubyte BIT6 :1;
    ubyte BIT5 :1;
    ubyte BIT4 :1;
    ubyte BIT3 :1;
    ubyte BIT2 :1;
    ubyte BIT1 :1;
    ubyte BIT0 :1;    /* lsb */
  #endif /* __BITFIELD_MSB_FIRST__ */

  } _bit; /* for bit  acces */

  ubyte _byte; /* for byte acces */
} bitfield_byte_t;

/* Type definition for short, byte and bit acces */

typedef union
{
  ushort data; /* for word access */
  struct
  {
  #if 1//def __BITFIELD_LSB_FIRST__
    ushort BIT0  :1;    /* lsb */
    ushort BIT1  :1;
    ushort BIT2  :1;
    ushort BIT3  :1;
    ushort BIT4  :1;
    ushort BIT5  :1;
    ushort BIT6  :1;
    ushort BIT7  :1;
    ushort BIT8  :1;
    ushort BIT9  :1;
    ushort BIT10 :1;
    ushort BIT11 :1;
    ushort BIT12 :1;
    ushort BIT13 :1;
    ushort BIT14 :1;
    ushort BIT15 :1;    /* msb */
  #endif /* __BITFIELD_LSB_FIRST__ */

  #ifdef __BITFIELD_MSB_FIRST__
    ushort BIT15 :1;    /* msb */
    ushort BIT14 :1;
    ushort BIT13 :1;
    ushort BIT12 :1;
    ushort BIT11 :1;
    ushort BIT10 :1;
    ushort BIT9  :1;
    ushort BIT8  :1;
    ushort BIT7  :1;
    ushort BIT6  :1;
    ushort BIT5  :1;
    ushort BIT4  :1;
    ushort BIT3  :1;
    ushort BIT2  :1;
    ushort BIT1  :1;
    ushort BIT0  :1;    /* lsb */
  #endif /* __BITFIELD_MSB_FIRST__ */

  } _bit; /* for bit  acces */


  struct
  {
  #if 1//def __LITTLE_ENDIAN__
  /* little endian format (Intel) */
  ubyte low;
  ubyte high;
  #endif /* __LITTLE_ENDIAN__ */

  #if 0//def __BIG_ENDIAN__
  /* big endian format (Motorola) */
  ubyte high;
  ubyte low;
  #endif /* __BIG_ENDIAN__ */
  } _byte; /* for byte access */

  ushort _short; /* for word access */
  struct
  {
  #if 1//def __LITTLE_ENDIAN__
  /* little endian format (Intel) */
  ubyte byteL;
  ubyte byteH;
  #endif /* __LITTLE_ENDIAN__ */

  #ifdef __BIG_ENDIAN__
  /* big endian format (Motorola) */
  ubyte byteH;
  ubyte byteL;
  #endif /* __BIG_ENDIAN__ */
  }; /* for byte access */
} bitfield_short_t;


/* Type definition for long, short, byte and bit acces */
typedef union
{
  ulong data; /* for longword access */
  ushort IndexedWord[2]; /* to access word by an index */

  ubyte  IndexedByte[4]; /* to access byte by an index */
  struct
  {
  #ifdef __LITTLE_ENDIAN__
  /* little endian format (Intel) */
  ushort wordL;
  ushort wordH;
  #endif /* __LITTLE_ENDIAN__ */

  #ifdef __BIG_ENDIAN__
  /* big endian format (Motorola) */
  ushort wordH;
  ushort wordL;
  #endif /* __BIG_ENDIAN__ */
  };  /* for word access */

  struct
  {
  #ifdef __LITTLE_ENDIAN__
  /* little endian format (Intel) */
  ubyte low_l;
  ubyte high_l;
  ubyte low_m;
  ubyte high_m;
  #endif /* __LITTLE_ENDIAN__ */

  #ifdef __BIG_ENDIAN__
  /* big endian format (Motorola) */
  ubyte high_m;
  ubyte low_m;
  ubyte high_l;
  ubyte low_l;
  #endif /* __BIG_ENDIAN__ */
  } _byte; /* for byte access */

  struct
  {
  #ifdef __BITFIELD_LSB_FIRST__
    ulong BIT0  :1;    /* lsb */
    ulong BIT1  :1;
    ulong BIT2  :1;
    ulong BIT3  :1;
    ulong BIT4  :1;
    ulong BIT5  :1;
    ulong BIT6  :1;
    ulong BIT7  :1;
    ulong BIT8  :1;
    ulong BIT9  :1;
    ulong BIT10 :1;
    ulong BIT11 :1;
    ulong BIT12 :1;
    ulong BIT13 :1;
    ulong BIT14 :1;
    ulong BIT15 :1;    /* msb */
    ulong BIT16 :1;    /* lsb */
    ulong BIT17 :1;
    ulong BIT18 :1;
    ulong BIT19 :1;
    ulong BIT20 :1;
    ulong BIT21 :1;
    ulong BIT22 :1;
    ulong BIT23 :1;
    ulong BIT24 :1;
    ulong BIT25 :1;
    ulong BIT26 :1;
    ulong BIT27 :1;
    ulong BIT28 :1;
    ulong BIT29 :1;
    ulong BIT30 :1;
    ulong BIT31 :1;    /* msb */
  #endif /* __BITFIELD_LSB_FIRST__ */

  #ifdef __BITFIELD_MSB_FIRST__
    ulong BIT31 :1;    /* msb */
    ulong BIT30 :1;
    ulong BIT29 :1;
    ulong BIT28 :1;
    ulong BIT27 :1;
    ulong BIT26 :1;
    ulong BIT25 :1;
    ulong BIT24 :1;
    ulong BIT23 :1;
    ulong BIT22 :1;
    ulong BIT21 :1;
    ulong BIT20 :1;
    ulong BIT19 :1;
    ulong BIT18 :1;
    ulong BIT17 :1;
    ulong BIT16 :1;    /* lsb */
    ulong BIT15 :1;    /* msb */
    ulong BIT14 :1;
    ulong BIT13 :1;
    ulong BIT12 :1;
    ulong BIT11 :1;
    ulong BIT10 :1;
    ulong BIT9  :1;
    ulong BIT8  :1;
    ulong BIT7  :1;
    ulong BIT6  :1;
    ulong BIT5  :1;
    ulong BIT4  :1;
    ulong BIT3  :1;
    ulong BIT2  :1;
    ulong BIT1  :1;
    ulong BIT0  :1;    /* lsb */
  #endif /* BITFIELD_MSB_FIRST */

  } _bit; /* for bit  acces */

  struct
  {
  #ifdef __LITTLE_ENDIAN__
  /* little endian format (Intel) */
  ushort low;
  ushort high;
  #endif /* __LITTLE_ENDIAN__ */

  #ifdef __BIG_ENDIAN__
  /* big endian format (Motorola) */
  ushort high;
  ushort low;
  #endif /* __BIG_ENDIAN__ */
  } _short;  /* for word access */

  ubyte _IndexedByte[4]; /* to access byte by an index */
  ulong _long; /* for longword access */
} bitfield_long_t;

#endif
/*_____ G L O B A L - D E F I N E ____________________________________________*/

#define _USED_      1
#define _NOT_USED_  0

#ifndef NULL
#define NULL ((void*)0)
#endif /* NULL */

#ifdef NO
#define NO  ((ubyte) 0)
#endif /* NO */

#ifdef YES
#define YES ((ubyte) 1)
#endif /* YES */

#ifdef OFF
#define OFF ((ubyte) 0)
#endif /* OFF */

#ifdef ON
#define ON  ((ubyte) 1)
#endif /* ON */

#ifdef NOK
#define NOK ((sbyte) 1)
#endif /* NOK */

#ifdef OK
#define OK  ((sbyte) 0)
#endif /* OK */

//#ifndef ERROR
//#define ERROR ((sbyte) -1)
//#endif /*ERROR*/

/* boolean type definition */
#ifndef FALSE
  #define FALSE 0u
#endif /* FALSE */

#ifndef TRUE
  #define TRUE  1u
#endif /* TRUE */

#define UBYTE_MAX       ((ubyte)0xFF)
#define UBYTE_MIN       ((ubyte)0x00)
#define USHORT_MAX      ((ushort)0xFFFF)
#define USHORT_MIN      ((ushort)0x0000)
#define ULONG_MAX       ((ulong)0xFFFFFFFFUL)
#define ULONG_MIN       ((ulong)0x00000000UL)
#define ULONGLONG_MAX   ((ulonglong)0xFFFFFFFFFFFFFFFFULL)
#define ULONGLONG_MIN   ((ulonglong)0x0000000000000000ULL)

#define SBYTE_MAX       ((sbyte)0x7F)
#define SBYTE_MIN       ((sbyte)(-SBYTE_MAX-1))
#define SSHORT_MAX      ((sshort)0x7FFF)
#define SSHORT_MIN      ((sshort)(-SSHORT_MAX-1))
#define SLONG_MAX       ((slong)0x7FFFFFFFL)
#define SLONG_MIN       ((slong)(-SLONG_MAX-1))
#define SLONGLONG_MAX   ((slonglong)0x7FFFFFFFFFFFFFFFLL)
#define SLONGLONG_MIN   ((slonglong)(-SLONGLONG_MAX-1))

#define ICC_UBYTE      *(volatile ubyte*)
#define ICC_USHORT     *(volatile ushort *)
#define ICC_ULONG      *(volatile ulong *)

#define ICC_UBYTE_BitsField   *(volatile bitfield_byte_t*)
#define ICC_USHORT_BitsField  *(volatile bitfield_short_t*)
#define ICC_ULONG_BitField    *(volatile bitfield_long_t*)

#define __EEPROM__
#define __NEAR__
#define __NEAR_FUNC__
#define __FAR__
#define __SDA__
#define __INTERRUPT__    __interrupt
#define __INLINE__       __inline__
#define __BANKED__
#define __NON_BANKED__
#define __NO_INIT__
#define __GCONST__
#define __FDA__
#define __ROOT__
#endif  /*TYPE_TVII_H*/

/*______ E N D _____ (type.h) ________________________________________________*/
