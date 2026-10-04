/******************************************************************************/
/*@F_NAME:          star.h                                                    */
/*@F_PURPOSE:       Public Interface                                          */
/*@F_CREATED_BY:    Laura Tarini                                              */
/*@F_CREATION_DATE: 29/03/2002                                                */
/*@F_LANGUAGE :     ANSI C                                                    */
/*@F_MPROC_TYPE:    NEC V850, TOSHIBA TX49, HCS12, HCS08, FSL IMX53           */
/********************************* (C) Copyright 2011 Magneti Marelli *********/

#ifndef STAR_H
#define STAR_H


/* _____ I N C L U D E - F I L E S ___________________________________________*/

#include "syst.h"
#ifdef SYST_EVENT_SPY
#include "spys.h"
#endif/* SYST_EVENT_SPY*/
#include "star_config.h"
#ifdef FIAT_AUTOSAR_STACK
 #include "EcuM.h"
#endif

#include "Std_Types.h"
/* _____ G L O B A L - D E F I N E ___________________________________________*/

/* Stack overflow check defines */
#ifdef STAR_STACK_OVF_RESET_SIZE

  #if (STAR_STACK_OVF_RESET_SIZE+2) <= STAR_STACK_SIZE

    #if defined(STAR_STACK_PTR_DECREASE)
      #define STAR_STACK_OVF_MARKER_POS_1   (STAR_STACK_SIZE - STAR_STACK_OVF_RESET_SIZE - 1)
      #define STAR_STACK_OVF_MARKER_POS_2   (STAR_STACK_OVF_MARKER_POS_1 - 1)
    #elif defined(STAR_STACK_PTR_INCREASE)
      #define STAR_STACK_OVF_MARKER_POS_1   (STAR_STACK_OVF_RESET_SIZE)
      #define STAR_STACK_OVF_MARKER_POS_2   (STAR_STACK_OVF_MARKER_POS_1 + 1)
    #else
      #error <Is stack ptr increase (STAR_STACK_PTR_INCREASE) or decrease (STAR_STACK_PTR_DECREASE)?>
    #endif

    #define STAR_STACK_OVF_MARKER_VAL_1     ((ubyte)0x55)
    #define STAR_STACK_OVF_MARKER_VAL_2     ((ubyte)0xAA)

  #else

    #error <STAR_STACK_OVF_RESET_SIZE must be equal or lower than (STAR_STACK_SIZE-2)>

  #endif /* (STAR_STACK_OVF_RESET_SIZE+2) <= STAR_STACK_SIZE */

#endif /* STAR_STACK_OVF_RESET_SIZE*/


/* _____ G L O B A L - T Y P E S _____________________________________________*/

#if (defined(__MC9S12xx__)  || defined(__MC9S08xx__))

typedef __NON_BANKED__ void (*STAR_IsrHandler_t)(void);

typedef struct
{
  ubyte             code_jmp;
  STAR_IsrHandler_t IsrHandler;
} STAR_RedirectVector_t;

#endif /* __MC9S12xx__ || __MC9S08xx__*/

#if defined(__REL_RL78__)
typedef __INTERRUPT__ void (*STAR_IsrHandler_t)(void);

#pragma pack(1)
typedef struct
{
  ubyte        code_jmp;
  STAR_IsrHandler_t IsrHandler;
} STAR_RedirectVector_t;
#pragma pack()

typedef struct
{
  ulong  CodeJmpLong_RamRedirectVectAddr;
} STAR_InterRedirectVector_t;
#endif /* __REL_RL78__ */

#ifdef __NEC_V850__

#pragma pack(1) /* force no data aligment*/

typedef  struct
{
  ushort codop1;
  void * codop2;
  ushort codop3;
  ushort codop4;
  ushort dummy1;
  ulong  dummy2;
} STAR_V850_IsrEntryVector_t;

#pragma pack()

#define MOV_REG_R15_IMM32          0x062F  /* mov imm32,r15 */
#define MOV_REG_R16_IMM32          0x0630  /* mov imm32,r16 */
#define MOV_REG_R17_IMM32          0x0631  /* mov imm32,r17 */
#define MOV_REG_R18_IMM32          0x0632  /* mov imm32,r18 */
#define MOV_REG_R19_IMM32          0x0633  /* mov imm32,r19 */
#define MOV_REG_R20_IMM32          0x0634  /* mov imm32,r20 */
#define MOV_REG_R21_IMM32          0x0635  /* mov imm32,r21 */
#define MOV_REG_R22_IMM32          0x0636  /* mov imm32,r22 */
#define JMP_R15                    0x006F  /* jmp [r15]     */
#define JMP_R16                    0x0070  /* jmp [r16]     */
#define JMP_R17                    0x0071  /* jmp [r17]     */
#define JMP_R18                    0x0072  /* jmp [r18]     */
#define JMP_R19                    0x0073  /* jmp [r19]     */
#define JMP_R20                    0x0074  /* jmp [r20]     */
#define JMP_R21                    0x0075  /* jmp [r21]     */
#define JMP_R22                    0x0076  /* jmp [r22]     */

#define MOV_INDIRECT_R15_R15_LOW   0x7F2F  /* mov 0[r15],r15  low-order 16 bits */
#define MOV_INDIRECT_R15_R15_HIGH  0x0001  /* mov 0[r15],r15 high-order 16 bits */
#define MOV_INDIRECT_R16_R16_LOW   0x8730  /* mov 0[r16],r16  low-order 16 bits */
#define MOV_INDIRECT_R16_R16_HIGH  0x0001  /* mov 0[r16],r16 high-order 16 bits */

#define MOV_INDIRECT_R17_R17_LOW   0x8F31  /* mov 0[r17],r17  low-order 16 bits */
#define MOV_INDIRECT_R17_R17_HIGH  0x0001  /* mov 0[r17],r17 high-order 16 bits */
#define MOV_INDIRECT_R18_R18_LOW   0x9732  /* mov 0[r18],r18  low-order 16 bits */
#define MOV_INDIRECT_R18_R18_HIGH  0x0001  /* mov 0[r18],r18 high-order 16 bits */
#define MOV_INDIRECT_R19_R19_LOW   0x9F33  /* mov 0[r19],r19  low-order 16 bits */
#define MOV_INDIRECT_R19_R19_HIGH  0x0001  /* mov 0[r19],r19 high-order 16 bits */
#define MOV_INDIRECT_R20_R20_LOW   0xA734  /* mov 0[r20],r20  low-order 16 bits */
#define MOV_INDIRECT_R20_R20_HIGH  0x0001  /* mov 0[r20],r20 high-order 16 bits */
#define MOV_INDIRECT_R21_R21_LOW   0xAF35  /* mov 0[r21],r21  low-order 16 bits */
#define MOV_INDIRECT_R21_R21_HIGH  0x0001  /* mov 0[r21],r21 high-order 16 bits */
#define MOV_INDIRECT_R22_R22_LOW   0xB736  /* mov 0[r22],r22  low-order 16 bits */
#define MOV_INDIRECT_R22_R22_HIGH  0x0001  /* mov 0[r22],r22 high-order 16 bits */

#endif /* __NEC_V850__ */

#ifdef __RH850__

#pragma pack(1) /* force no data aligment*/

typedef  struct
{
  ushort codop1;
  void * codop2;
  ushort codop3;
  ushort codop4;
  ushort dummy1;
  ulong  dummy2;
} STAR_RH850_IsrEntryVector_t;

#pragma pack()

#pragma pack()

#define MOV_REG_R15_IMM32          0x062F  /* mov imm32,r15 */
#define MOV_REG_R16_IMM32          0x0630  /* mov imm32,r16 */
#define MOV_REG_R17_IMM32          0x0631  /* mov imm32,r17 */
#define MOV_REG_R18_IMM32          0x0632  /* mov imm32,r18 */
#define MOV_REG_R19_IMM32          0x0633  /* mov imm32,r19 */
#define MOV_REG_R20_IMM32          0x0634  /* mov imm32,r20 */
#define MOV_REG_R21_IMM32          0x0635  /* mov imm32,r21 */
#define MOV_REG_R22_IMM32          0x0636  /* mov imm32,r22 */
#define JMP_R15                    0x006F  /* jmp [r15]     */
#define JMP_R16                    0x0070  /* jmp [r16]     */
#define JMP_R17                    0x0071  /* jmp [r17]     */
#define JMP_R18                    0x0072  /* jmp [r18]     */
#define JMP_R19                    0x0073  /* jmp [r19]     */
#define JMP_R20                    0x0074  /* jmp [r20]     */
#define JMP_R21                    0x0075  /* jmp [r21]     */
#define JMP_R22                    0x0076  /* jmp [r22]     */

#define MOV_INDIRECT_R15_R15_LOW   0x7F2F  /* mov 0[r15],r15  low-order 16 bits */
#define MOV_INDIRECT_R15_R15_HIGH  0x0001  /* mov 0[r15],r15 high-order 16 bits */
#define MOV_INDIRECT_R16_R16_LOW   0x8730  /* mov 0[r16],r16  low-order 16 bits */
#define MOV_INDIRECT_R16_R16_HIGH  0x0001  /* mov 0[r16],r16 high-order 16 bits */

#define MOV_INDIRECT_R17_R17_LOW   0x8F31  /* mov 0[r17],r17  low-order 16 bits */
#define MOV_INDIRECT_R17_R17_HIGH  0x0001  /* mov 0[r17],r17 high-order 16 bits */
#define MOV_INDIRECT_R18_R18_LOW   0x9732  /* mov 0[r18],r18  low-order 16 bits */
#define MOV_INDIRECT_R18_R18_HIGH  0x0001  /* mov 0[r18],r18 high-order 16 bits */
#define MOV_INDIRECT_R19_R19_LOW   0x9F33  /* mov 0[r19],r19  low-order 16 bits */
#define MOV_INDIRECT_R19_R19_HIGH  0x0001  /* mov 0[r19],r19 high-order 16 bits */
#define MOV_INDIRECT_R20_R20_LOW   0xA734  /* mov 0[r20],r20  low-order 16 bits */
#define MOV_INDIRECT_R20_R20_HIGH  0x0001  /* mov 0[r20],r20 high-order 16 bits */
#define MOV_INDIRECT_R21_R21_LOW   0xAF35  /* mov 0[r21],r21  low-order 16 bits */
#define MOV_INDIRECT_R21_R21_HIGH  0x0001  /* mov 0[r21],r21 high-order 16 bits */
#define MOV_INDIRECT_R22_R22_LOW   0xB736  /* mov 0[r22],r22  low-order 16 bits */
#define MOV_INDIRECT_R22_R22_HIGH  0x0001  /* mov 0[r22],r22 high-order 16 bits */

#define STAR_WUFCx_CLEARED 0xFFFFFFFFUL
#endif /* __RH850__ */

typedef __NON_BANKED__ void (STAR_BootSetKeyCall_t)(SYST_BootKey_t, bool_t);


/* _____ G L O B A L - D A T A _______________________________________________*/
#ifdef __RTOS__
#if defined(C_COMP_GHS_TX49)  \
  || defined(C_COMP_GHS_V850) \
  || defined(C_COMP_GHS_ARM)
#pragma ghs startdata
#pragma ghs section bss=".stack"
#endif /* C_COMP_GHS_TX49 || C_COMP_GHS_V850 || C_COMP_GHS_ARM */

#ifdef STAR_STACK_SIZE
extern ubyte STAR_Stack[STAR_STACK_SIZE];
#endif

#if defined(C_COMP_GHS_TX49)  \
  || defined(C_COMP_GHS_V850) \
  || defined(C_COMP_GHS_ARM)
#pragma ghs section bss=default
#pragma ghs enddata
#endif /* C_COMP_GHS_TX49 || C_COMP_GHS_V850 || C_COMP_GHS_ARM */
#endif /*__RTOS__*/

/* _____ G L O B A L - M A C R O S ___________________________________________*/

#ifdef __NEC_V850__

#define STAR_NEC_RAM_NMI_ENTRY(VectorNumber)                                   \
                 { MOV_REG_R17_IMM32,                                          \
                 (void *)(SYST_TABLE_VECT_RAM + sizeof(void*) * VectorNumber), \
                 MOV_INDIRECT_R17_R17_LOW,                                     \
                 MOV_INDIRECT_R17_R17_HIGH,                                    \
                 JMP_R17 }

#define STAR_NEC_RAM_IT_ENTRY(VectorNumber,ItPriority)                         \
                 STAR_NEC_RAM_IT_ENTRY_ ## ItPriority ## (VectorNumber)

#ifdef __OSEK__ /* R18 must be reserved for OSEK */

#define STAR_NEC_RAM_IT_ENTRY_1(VectorNumber)                                  \
                 { MOV_REG_R15_IMM32,                                          \
                 (void *)(SYST_TABLE_VECT_RAM + sizeof(void*) * VectorNumber), \
                 MOV_INDIRECT_R15_R15_LOW,                                     \
                 MOV_INDIRECT_R15_R15_HIGH,                                    \
                 JMP_R15 }

#else /* __OSEK__ */
#define STAR_NEC_RAM_IT_ENTRY_1(VectorNumber)                                  \
                 { MOV_REG_R18_IMM32,                                          \
                 (void *)(SYST_TABLE_VECT_RAM + sizeof(void*) * VectorNumber), \
                 MOV_INDIRECT_R18_R18_LOW,                                     \
                 MOV_INDIRECT_R18_R18_HIGH,                                    \
                 JMP_R18 }
#endif /* __OSEK__ */

#ifdef __OSEK__ /* R19 must be reserved for OSEK */

#define STAR_NEC_RAM_IT_ENTRY_2(VectorNumber)                                  \
                 { MOV_REG_R16_IMM32,                                          \
                 (void *)(SYST_TABLE_VECT_RAM + sizeof(void*) * VectorNumber), \
                 MOV_INDIRECT_R16_R16_LOW,                                     \
                 MOV_INDIRECT_R16_R16_HIGH,                                    \
                 JMP_R16 }

#else /* __OSEK__ */

#define STAR_NEC_RAM_IT_ENTRY_2(VectorNumber)                                  \
                 { MOV_REG_R19_IMM32,                                          \
                 (void *)(SYST_TABLE_VECT_RAM + sizeof(void*) * VectorNumber), \
                 MOV_INDIRECT_R19_R19_LOW,                                     \
                 MOV_INDIRECT_R19_R19_HIGH,                                    \
                 JMP_R19 }

#endif /* __OSEK__ */

#define STAR_NEC_RAM_IT_ENTRY_3(VectorNumber)                                  \
                 { MOV_REG_R20_IMM32,                                          \
                 (void *)(SYST_TABLE_VECT_RAM + sizeof(void*) * VectorNumber), \
                 MOV_INDIRECT_R20_R20_LOW,                                     \
                 MOV_INDIRECT_R20_R20_HIGH,                                    \
                 JMP_R20 }

#define STAR_NEC_RAM_IT_ENTRY_4(VectorNumber)                                  \
                 { MOV_REG_R21_IMM32,                                          \
                 (void *)(SYST_TABLE_VECT_RAM + sizeof(void*) * VectorNumber), \
                 MOV_INDIRECT_R21_R21_LOW,                                     \
                 MOV_INDIRECT_R21_R21_HIGH,                                    \
                 JMP_R21 }

#define STAR_NEC_ROM_IT_ENTRY(ItHandler)                                       \
                 { MOV_REG_R22_IMM32,                                          \
                 ItHandler,                                                    \
                 JMP_R22 }

#endif /* __NEC_V850__ */


#ifdef __RH850__

#define STAR_RH850_RAM_NMI_ENTRY(VectorNumber)                                   \
                 { MOV_REG_R17_IMM32,                                          \
                 (void *)(SYST_TABLE_VECT_RAM + sizeof(void*) * (VectorNumber)), \
                 MOV_INDIRECT_R17_R17_LOW,                                     \
                 MOV_INDIRECT_R17_R17_HIGH,                                    \
                 JMP_R17 }

#define STAR_RH850_RAM_IT_ENTRY(VectorNumber,ItPriority)                         \
                 STAR_RH850_RAM_IT_ENTRY_ ## ItPriority ## (VectorNumber)

#ifdef __OSEK__ /* R18 must be reserved for OSEK */

#define STAR_RH850_RAM_IT_ENTRY_1(VectorNumber)                                  \
                 { MOV_REG_R15_IMM32,                                          \
                 (void *)(SYST_TABLE_VECT_RAM + sizeof(void*) * (VectorNumber)), \
                 MOV_INDIRECT_R15_R15_LOW,                                     \
                 MOV_INDIRECT_R15_R15_HIGH,                                    \
                 JMP_R15 }

#else /* __OSEK__ */
#define STAR_RH850_RAM_IT_ENTRY_1(VectorNumber)                                  \
                 { MOV_REG_R18_IMM32,                                          \
                 (void *)(SYST_TABLE_VECT_RAM + sizeof(void*) * (VectorNumber)), \
                 MOV_INDIRECT_R18_R18_LOW,                                     \
                 MOV_INDIRECT_R18_R18_HIGH,                                    \
                 JMP_R18 }
#endif /* __OSEK__ */

#ifdef __OSEK__ /* R19 must be reserved for OSEK */

#define STAR_RH850_RAM_IT_ENTRY_2(VectorNumber)                                  \
                 { MOV_REG_R16_IMM32,                                          \
                 (void *)(SYST_TABLE_VECT_RAM + sizeof(void*) * (VectorNumber)), \
                 MOV_INDIRECT_R16_R16_LOW,                                     \
                 MOV_INDIRECT_R16_R16_HIGH,                                    \
                 JMP_R16 }

#else /* __OSEK__ */

#define STAR_RH850_RAM_IT_ENTRY_2(VectorNumber)                                  \
                 { MOV_REG_R19_IMM32,                                          \
                 (void *)(SYST_TABLE_VECT_RAM + sizeof(void*) * (VectorNumber)), \
                 MOV_INDIRECT_R19_R19_LOW,                                     \
                 MOV_INDIRECT_R19_R19_HIGH,                                    \
                 JMP_R19 }

#endif /* __OSEK__ */

#define STAR_RH850_RAM_IT_ENTRY_3(VectorNumber)                                  \
                 { MOV_REG_R20_IMM32,                                          \
                 (void *)(SYST_TABLE_VECT_RAM + sizeof(void*) * (VectorNumber)), \
                 MOV_INDIRECT_R20_R20_LOW,                                     \
                 MOV_INDIRECT_R20_R20_HIGH,                                    \
                 JMP_R20 }

#define STAR_RH850_RAM_IT_ENTRY_4(VectorNumber)                                  \
                 { MOV_REG_R21_IMM32,                                          \
                 (void *)(SYST_TABLE_VECT_RAM + sizeof(void*) * (VectorNumber)), \
                 MOV_INDIRECT_R21_R21_LOW,                                     \
                 MOV_INDIRECT_R21_R21_HIGH,                                    \
                 JMP_R21 }

#define STAR_RH850_ROM_IT_ENTRY(ItHandler)                                       \
                 { MOV_REG_R22_IMM32,                                          \
                 ItHandler,                                                    \
                 JMP_R22 }

#endif /* __RH850__ */

/* Stack overflow check macro */
#ifdef STAR_STACK_OVF_RESET_SIZE

#define STAR_InitCheckStackOvf()                                         \
  STAR_Stack[STAR_STACK_OVF_MARKER_POS_1] = STAR_STACK_OVF_MARKER_VAL_1; \
  STAR_Stack[STAR_STACK_OVF_MARKER_POS_2] = STAR_STACK_OVF_MARKER_VAL_2


#ifdef SYST_EVENT_SPY

#define STAR_CheckStackOvf()                                                        \
  {                                                                                 \
    if ( (STAR_Stack[STAR_STACK_OVF_MARKER_POS_1] != STAR_STACK_OVF_MARKER_VAL_1)   \
      || (STAR_Stack[STAR_STACK_OVF_MARKER_POS_2] != STAR_STACK_OVF_MARKER_VAL_2) ) \
    {                                                                               \
      RTOS_DisableAllInterrupts();                                                  \
      SPYS_IncEvtSpy(SPYS_EVT_SPY_STACK_OVF);                                       \
      SYST_Reset();                                                                 \
    }                                                                               \
  }

#else   /* SYST_EVENT_SPY*/

#define STAR_CheckStackOvf()                                                        \
  {                                                                                 \
    if ( (STAR_Stack[STAR_STACK_OVF_MARKER_POS_1] != STAR_STACK_OVF_MARKER_VAL_1)   \
      || (STAR_Stack[STAR_STACK_OVF_MARKER_POS_2] != STAR_STACK_OVF_MARKER_VAL_2) ) \
    {                                                                               \
      RTOS_DisableAllInterrupts();                                                  \
      SYST_Reset();                                                                 \
    }                                                                               \
  }

#endif/* SYST_EVENT_SPY*/

#else /* STAR_STACK_OVF_RESET_SIZE */

#define STAR_InitCheckStackOvf()
#define STAR_CheckStackOvf()

#endif /* STAR_STACK_OVF_RESET_SIZE*/


/* _____ G L O B A L -  F U N C T I O N S - P R O T O T Y P E S ______________*/

/******************************************************************************/
/* Name : STAR_StartUpSystem                                                  */
/* Role : application entry point                                             */
/* Interface : -                                                              */
/* Pre-condition : -                                                          */
/* Constraints : This is the funcion called by Boot Code to start application */
/*               use boot stack                                               */
/*               For TX 39 :                                                  */
/*               - stored in ROM                                              */
/*               - do not call functions of sys.h (and child .h),             */
/*                 because they are located and there are not yet ready       */
/* Behaviour :                                                                */
/*  DO                                                                        */
/*     [if Boot application, Call application main because                    */
/*      start-up initialisation already done in boot]                         */
/*     [if CLIENT or EOL application, call start-up routine]                  */
/*  OD                                                                        */
/******************************************************************************/

extern __NON_BANKED__ void STAR_StartUpSystem(void);

extern void STAR_WakeUpFromDeepSleep(void);
/******************************************************************************/
/* Name : STAR_main                                                           */
/* Role : Start OSEK operating system to start application                    */
/* Interface : -                                                              */
/* Pre-condition : -                                                          */
/* Constraints : In case of use of GHS Integrity, this routine must be set as */
/*               main original task in the integrate configuration file       */
/* Behaviour :                                                                */
/*  DO                                                                        */
/*     [StartOS]                                                              */
/*     [loop infinite (or Exit if GHS Integrity is used]                      */
/*  OD                                                                        */
/******************************************************************************/
extern __NON_BANKED__ void STAR_main(void);


/*----------------------------------------------------------------------------*/
/*Name : STAR_HardwareWakeUp                                                  */
/*Role : Wake up the processor hardware (BASE Modules)                        */
/*Interface : -                                                               */
/*Pre-condition : -                                                           */
/*Constraints :  -                                                            */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [Wake up the processor hardware]                                        */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
extern void STAR_HardwareWakeUp(void);


/*----------------------------------------------------------------------------*/
/*Name : STAR_HardwareSleep                                                   */
/*Role : Stop the processor hardware (BASE Modules)                           */
/*Interface : -                                                               */
/*Pre-condition : -                                                           */
/*Constraints :  -                                                            */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [stop the processor hardware]                                           */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
extern void STAR_HardwareSleep(void);

#if defined(__OSEK__) || defined(__CY_TV2__)

/******************************************************************************/
/* Name : StartupHook                                                         */
/* Role : Start Up application                                                */
/* Interface : -                                                              */
/* Pre-condition : -                                                          */
/* Constraints : hook service called by Init OSEK OS                          */
/* Behaviour :                                                                */
/*  DO                                                                        */
/*     [Get Ram Boot Key]                                                     */
/*     [Call StartUpHook_Client]                                              */
/*  OD                                                                        */
/******************************************************************************/
extern void StartupHook(void);


/******************************************************************************/
/* Name : ShutdownHook                                                        */
/* Role : shut down OS                                                        */
/* Interface : -                                                              */
/* Pre-condition : -                                                          */
/* Constraints : hook service called by OSEK OS                               */
/* Behaviour :                                                                */
/*  DO                                                                        */
/*     [ ]                                                                    */
/*  OD                                                                        */
/******************************************************************************/
extern void ShutdownHook(StatusType error);

#endif

/******************************************************************************/
/* Name : StartUpHookClient                                                   */
/* Role : Start Up Client application                                         */
/* Interface : -                                                              */
/* Pre-condition : -                                                          */
/* Constraints : This is the funcion called by StarUpHook                     */
/* Behaviour :                                                                */
/*  DO                                                                        */
/*     [Initialise Client application]                                        */
/*  OD                                                                        */
/******************************************************************************/  
#ifdef FIAT_AUTOSAR_STACK
 
 #if defined(__CLIENT_EOL_LINK__) || defined(__BOOT_CLIENT_EOL_LINK__) || defined(__CLIENT_LINK__)
  extern void Star_StartUpHookClient(void);
 #endif /* defined(__CLIENT_EOL_LINK__) || defined(__BOOT_CLIENT_EOL_LINK__)  || defined(__CLIENT_LINK__) */

#endif /* FIAT_AUTOSAR_STACK */

#endif /* STAR_H */

/* _____ E N D _____ (star.h) ________________________________________________*/
