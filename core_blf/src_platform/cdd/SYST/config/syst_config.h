/******************************************************************************/
/* @F_NAME:           syst_config.h                                           */
/* @F_PURPOSE:        export for syst config module                           */
/* @F_CREATED_BY:     MORIN Pascal                                            */
/* @F_CREATION_DATE:  29/01/2003                                              */
/* @F_MPROC_TYPE:     NEC_V850                                                */
/************************************** (C) Copyright 2015 Magneti Marelli ****/

#ifndef SYST_CONFIG_H
#define SYST_CONFIG_H

/*_____ I N C L U D E - F I L E S ____________________________________________*/

#define SYST_CONFIG_PROJECT_VERSION_DEFINED
#define SYST_CONFIG_PROJECT_NAME_DEFINED
/*#define SYST_SOFTRESETCHECK_BEFORE_DEEPSTOP*/

#define SYST_FBL_RESTART_FROM_BOOT                  ((SYST_BootKey_t) 0xA7A6A5A4)

/* syst_config.h IS included only by "syst.h"                                 */

/* EEPS module must be included if SYST_FLASH_BLOCK_DEF_IN_EEPROM is used. See
   below. */
/*#include "eeps.h"*/


#ifdef __PC_SIMULATION__
/* This file configures the CUnit test to be executed, it is owned by a       */
/* SIMUL_XXX project. See SIMU module for template.                           */
#include "simu_cunit_config.h"
#endif /*__PC_SIMULATION__  */


/*_____ G L O B A L - D E F I N E ____________________________________________*/

#ifdef __REL_V850_Dx4__
/* ---------------- DEEPSTOP CONFIGURATION for V850 Dx4 --------------------- */

#define SYST_DX4_DEEPSTOP_USED
#ifdef SYST_DX4_DEEPSTOP_USED
/* Define if you want to activate backup of RAM appli data in BURAM
 * (=maintained at sleep) */
/*#define SYST_DATA_SAVE_IN_DEEPSTOP*/
#endif
/* Define if you want to activate backup of RAM shared and reset data in BURAM
 * (=maintained at reset) */
//#define SYST_DATA_SAVE_IN_RESET

/* Define here table size of Syst_BkpSectBoot, Syst_BkpSecBeforeInit,
 * Syst_BkpSecAfterInit. */
#define Syst_BKP_SEC_NB_BOOT        1
#define Syst_BKP_SEC_NB_BEFORE_INIT  1
#define Syst_BKP_SEC_NB_SLEEP_BEFORE_INIT  1
#define Syst_BKP_SEC_NB_SLEEP_AFTER_INIT  2

/* ---------------- END DEEPSTOP CONFIGURATION ----------------------------- */
#endif /*__REL_V850_Dx4__  */

#if defined(__NEC_V850_DG3_3416__  ) || \
    defined(__NEC_V850_DG3_F3416__ ) || \
    defined(__NEC_V850_DG3_3417__  ) || \
    defined(__NEC_V850_DG3_F3417__ ) || \
    defined(__NEC_V850_DJ3_F3421__ ) || \
    defined(__NEC_V850_DJ3_F3422__ ) || \
    defined(__NEC_V850_DJ3_F3423__ ) || \
    defined(__NEC_V850_FE3_F3370__ ) || \
    defined(__NEC_V850_FE3_F3371__ ) || \
    defined(__NEC_V850_FF3_F3372__ ) || \
    defined(__NEC_V850_FF3_F3373__ ) || \
    defined(__NEC_V850_FF3L_F3618__) || \
    defined(__NEC_V850_FG3_F3374__ ) || \
    defined(__NEC_V850_FG3_F3375__ ) || \
    defined(__NEC_V850_FJ3_F3378__ ) || \
    defined(__NEC_V850_FG3_F3376__ ) || \
    defined(__NEC_V850_FG3_F3377__ ) || \
    defined(__NEC_V850_FJ3_F3379__ ) || \
    defined(__NEC_V850_FJ3_F3380__ ) || \
    defined(__NEC_V850_FJ3_F3381__ ) || \
    defined(__NEC_V850_FJ3_F3382__ ) || \
    defined(__NEC_V850_FK3_F3383__ ) || \
    defined(__NEC_V850_FK3_F3384__ ) || \
    defined(__NEC_V850_FK3_F3385__ ) || \
    defined(__NEC_V850_DJ3_F3424__ ) || \
    defined(__NEC_V850_DJ3_F3425__ ) || \
    defined(__NEC_V850_DJ3_F3426__ ) || \
    defined(__NEC_V850_DL3_F3427__ ) || \
    defined(__REL_V850_DK4__)        || \
    defined(__REL_V850_DX4__)        || \
	defined(__REL_V850_DJ4_HE__)

/* Define CPU frequency in MHz */

/* NEC V850 :                                               */
/* #define SYST_FX_CLOCK  16                                */
/* #define SYST_FX_CLOCK  20                                */
/* #define SYST_FX_CLOCK  32                                */
/* #define SYST_FX_CLOCK  48                                */
/* #define SYST_FX_CLOCK  80                                */
/* #define SYST_FX_CLOCK  120 ( DJ4_F3525,DJ4_F3526,DN4 )   */
/* #define SYST_FX_CLOCK  160 ( DN4 only )                  */
#define SYST_FX_CLOCK  80

/*#define SYST_SOFTRESETCHECK_BEFORE_DEEPSTOP*/

/*#define SYST_WAKEUP_EVENT_NMI*/
/*#define SYST_WAKEUP_EVENT_INTWDTA0*/
/*#define SYST_WAKEUP_EVENT_INTLVI*/
/*#define SYST_WAKEUP_EVENT_INTRTCA0AL*/
/*#define SYST_WAKEUP_EVENT_INTRTCA0R*/
/*#define SYST_WAKEUP_EVENT_INTRTCA01S*/
/*#define SYST_WAKEUP_EVENT_INTP0*/
/*#define SYST_WAKEUP_EVENT_INTP1*/
#define SYST_WAKEUP_EVENT_INTP2       /*kl15*/
/*#define SYST_WAKEUP_EVENT_INTP3*/
/*#define SYST_WAKEUP_EVENT_INTP4*/
/*#define SYST_WAKEUP_EVENT_INTP5*/
/*#define SYST_WAKEUP_EVENT_INTP6*/
/*#define SYST_WAKEUP_EVENT_INTP7*/
/*#define SYST_WAKEUP_EVENT_INTP8*/
/*#define SYST_WAKEUP_EVENT_INTP9*/
/*#define SYST_WAKEUP_EVENT_INTP10*/
#define SYST_WAKEUP_EVENT_FCN0RX
/*#define SYST_WAKEUP_EVENT_FCN1RX*/
/*#define SYST_WAKEUP_EVENT_FCN2RX*/
/*#define SYST_WAKEUP_EVENT_INTCLMA0*/
/*#define SYST_WAKEUP_EVENT_INTCLMA1*/
/*#define SYST_WAKEUP_EVENT_INTCLMA2*/

/*#define SYST_WAKEUP_EVENT_INTVCPC0*/
/*#define SYST_WAKEUP_EVENT_INTVCPC1*/
/*#define SYST_WAKEUP_EVENT_INTTAUJ0I0*/
/*#define SYST_WAKEUP_EVENT_INTTAUJ0I1*/
/*#define SYST_WAKEUP_EVENT_INTTAUJ0I2*/
/*#define SYST_WAKEUP_EVENT_INTTAUJ0I3*/
/*#define SYST_WAKEUP_EVENT_INTTAUJ1I0*/
/*#define SYST_WAKEUP_EVENT_INTTAUJ1I1*/
/*#define SYST_WAKEUP_EVENT_INTTAUJ1I2*/
/*#define SYST_WAKEUP_EVENT_INTTAUJ1I3*/
/*#define SYST_WAKEUP_EVENT_INTADCA0ERR*/
/*#define SYST_WAKEUP_EVENT_INTADCA0I0*/
/*#define SYST_WAKEUP_EVENT_INTADCA0I1*/
/*#define SYST_WAKEUP_EVENT_INTADcA0I2*/
/*#define SYST_WAKEUP_EVENT_INTADCA0LLT*/
/*#define SYST_WAKEUP_EVENT_INTWDTA1*/
/*#define SYST_WAKEUP_EVENT_INTCLMA3*/
/*#define SYST_WAKEUP_EVENT_INTTAUA0I0*/
/*#define SYST_WAKEUP_EVENT_INTTAUA0I1*/
/*#define SYST_WAKEUP_EVENT_INTTAUA0I2*/

/*#define SYST_WAKEUP_EVENT_INTTAUA0I3*/
/*#define SYST_WAKEUP_EVENT_INTTAUA0I4*/
/*#define SYST_WAKEUP_EVENT_INTTAUA0I5*/
/*#define SYST_WAKEUP_EVENT_INTTAUA0I6*/
/*#define SYST_WAKEUP_EVENT_INTTAUA0I7*/
/*#define SYST_WAKEUP_EVENT_INTTAUA0I8*/
/*#define SYST_WAKEUP_EVENT_INTTAUA0I9*/
/*#define SYST_WAKEUP_EVENT_INTTAUA0I10*/
/*#define SYST_WAKEUP_EVENT_INTTAUA0I11*/
/*#define SYST_WAKEUP_EVENT_INTTAUA0I12*/
/*#define SYST_WAKEUP_EVENT_INTTAUA0I13*/
/*#define SYST_WAKEUP_EVENT_INTTAUA0I14*/
/*#define SYST_WAKEUP_EVENT_INTTAUA0I15*/
/*#define SYST_WAKEUP_EVENT_WDTA0NMI*/
/*#define SYST_WAKEUP_EVENT_WDTA1NMI*/
/*#define SYST_WAKEUP_EVENT_OCDSTPRQ*/ /* wakeup with JTAG connected */

#endif /* __NEC_V850_Xxx__ */


/***************************************************************/
/* Uncomment SYST_SPECIAL_RESET to activate the special reset, */
/* and include file needed for the special reset declaration.  */
/***************************************************************/
/* #define SYST_SPECIAL_RESET */
/* #include "coms.h"          */

/***************************************************************/
/* Define SYST_DEBUG_RESET to redirect SYST_Reset to hook      */
/* SYST_DebugReset to facilitate emulator debug.               */
/* Releases sw are protected against its integration by        */
/* undefined __debug__.                                        */
/***************************************************************/
#ifdef __debug__
#define SYST_DEBUG_RESET
#endif

/***************************************************************/
/* Define SYST_ASSERT_ENABLED to activate assertions.          */
/* Releases sw are protected against its integration by        */
/* undefined __debug__.                                        */
/***************************************************************/
#ifdef __debug__
#define SYST_ASSERT_ENABLED
#endif

/***************************************************************/
/* Define SYST_DEBUG_ENABLED to activate debug actions.        */
/* Releases sw are protected against its integration by        */
/* undefined __debug__.                                        */
/***************************************************************/
#ifdef __debug__
#define SYST_DEBUG_ENABLED
#endif

/***************************************************************/
/* Define SYST_DEBUG_ALLOC to activate debug allocation        */
/* Releases sw are protected against its integration by        */
/* undefined __debug__.                                        */
/***************************************************************/
#ifdef __debug__
#define SYST_DEBUG_ALLOC
#endif

/***************************************************************/
/* Define SYST_SPY_UART_USED to activate uart output.          */
/***************************************************************/
#define SYST_SPY_UART_USED

/* -------------------------------------------------------------------------- */

/* Define if you want enable event spys */
/* #define SYST_EVENT_SPY */

/* Define if you want enable reset info */
#define SYST_RESET_INFO

#ifdef __RTOS__
/* define Scss task period */
#define SYST_SSCS_TASK_PERIOD 100

/* define Wkss task period */
#define SYST_WKSS_TASK_PERIOD 100

/* define Wkss task delay */
#define SYST_WKSS_TASK_DELAY 0

/* define Sscs task delay */
#define SYST_SSCS_TASK_DELAY 0

#endif

#ifdef __OSEK__
/* define Scss task period */
#define SYST_SSCS_TASK_PERIOD MSEC(100)

/* define Wkss task period */
#define SYST_WKSS_TASK_PERIOD MSEC(100)

/* define Wkss task delay */
#define SYST_WKSS_TASK_DELAY USEC(2500)

/* define Sscs task delay */
#define SYST_SSCS_TASK_DELAY USEC(2500)

#define NO_PERIOD            (0)
#define NO_DELAY             USEC(2500)
#define DELAY_2_5MS          USEC(2500)
#define DELAY_7_5MS          USEC(7500)
#define PERIOD_2_5MS         USEC(2500)
#define PERIOD_5MS           USEC(5000)
#define PERIOD_10MS          USEC(10000)
#define PERIOD_20MS          USEC(20000)
#define PERIOD_15MS          USEC(15000)
#define PERIOD_25MS          USEC(25000)
#define PERIOD_12_5MS        USEC(12500)
#define PERIOD_50MS          USEC(50000)
#define PERIOD_100MS         USEC(100000)
#define PERIOD_200MS         USEC(200000)

#define DELAY_500MS          MSEC(500)
#define DELAY_3000MS         MSEC(3000)

#define RTOS_ENTER_IT(x)
#define RTOS_LEAVE_IT(x)

/******************************************************************************/
/* Name : Poly_DisableAllInterrupts                                           */
/* Role : Disable all maskable interrupts of the system                       */
/* Interface : OSEK compliant                                                 */
/* Pre-condition : none                                                       */
/* Constraints : - Do not call this service in an interrupt function          */
/*               - Must be called instead of DisableAllInterrupts() when      */
/*                 critical section does not end in the same block.           */
/*                 Poly_EnableAllInterrupts() must end this critical section. */
/******************************************************************************/
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

#endif

#ifdef __NEC_V850__

/******************************************************************************/
/******************************************************************************/
/*     Put here address you want retrieve from mapping and NOTHING ELSE!      */
/******************************************************************************/
/******************************************************************************/
#ifdef C_COMP_GHS_V850
/* Suppress remark 1824: incomplete array type with external linkage not
   allowed for variable "__ghsbegin_xxxx".
   __ghsbegin_xxxx and __ghsend_xxxx are pointers on section defined by GreenHills
   tool chain to retrieve begin and end of section dynamically. This allow to always
   be in accordance with link mapping.
   This warning must not be suppressed globally by compilation option because we
   want to suppress warning only for __ghsbegin_xxx and __ghsend_xxxx.
   This pragma takes end with pragma endnowarning. */
#pragma ghs nowarning 1824
#endif /* C_COMP_GHS_V850 */

/* Define below the address of the BLF and Client SW identifier CONST variables
   Section defined in link command file                                       */
#pragma ghs startdata
#pragma ghs section rodata=".BLF_CONST_SW_ID"
extern ubyte __ghsbegin_BLF_CONST_SW_ID[1];
#pragma ghs section rodata=default
#pragma ghs enddata

#define SYST_BLF_SW_ID_ADDR               ((SYST_AddressWidth_t)__ghsbegin_BLF_CONST_SW_ID)

#pragma ghs startdata
#pragma ghs section rodata=".CONST_SW_ID"
extern ubyte __ghsbegin_CONST_SW_ID[1];
#pragma ghs section rodata=default
#pragma ghs enddata

#define SYST_APP_SW_ID_ADDR               ((SYST_AddressWidth_t)__ghsbegin_CONST_SW_ID)


/* Define below address of Custormer SW product identifier (BLF + Client) for
   CONST data.
   Section defined in link command file                                       */
#pragma ghs startdata
#pragma ghs section rodata=".FlashStart"
extern const ubyte __ghsbegin_FlashStart[];
#pragma ghs section rodata=default
#pragma ghs enddata

#define SYST_FLASH_START_ADDRESS          ((SYST_AddressWidth_t)__ghsbegin_FlashStart)

#pragma ghs startdata
#pragma ghs section rodata=".BlfStart"
extern const ubyte __ghsbegin_BlfStart[];
#pragma ghs section rodata=default
#pragma ghs enddata

#define SYST_CHKS_BLF_START_ADDRESS       ((SYST_AddressWidth_t)__ghsbegin_BlfStart)

#pragma ghs startdata
#pragma ghs section rodata=".FlashEnd"
extern const ubyte __ghsbegin_FlashEnd[];
#pragma ghs section rodata=default
#pragma ghs enddata

#define SYST_FLASH_END_ADDRESS            ((SYST_AddressWidth_t)__ghsbegin_FlashEnd)

#pragma ghs startdata
#pragma ghs section rodata=".AppliStart"
extern const ubyte __ghsbegin_AppliStart[];
#pragma ghs section rodata=default
#pragma ghs enddata

#define SYST_CHKS_APPLI_START_ADDRESS     ((SYST_AddressWidth_t)__ghsbegin_AppliStart)

#pragma ghs startdata
#pragma ghs section rodata=".BlfEnd"
extern const ubyte __ghsbegin_BlfEnd[];
#pragma ghs section rodata=default
#pragma ghs enddata

#define SYST_CHKS_BLF_END_ADDRESS          ((SYST_AddressWidth_t)__ghsbegin_BlfEnd)

#pragma ghs startdata
#pragma ghs section rodata=".BOOT_ID"
extern const ubyte __ghsbegin_BOOT_ID[];
#pragma ghs section rodata=default
#pragma ghs enddata

#define SYST_BOOT_ID_ADDRESS                ((SYST_AddressWidth_t)__ghsbegin_BOOT_ID)

#pragma ghs startdata
#pragma ghs section rodata=".AppliEnd"
extern const ubyte __ghsbegin_AppliEnd[];
#pragma ghs section rodata=default
#pragma ghs enddata

#define SYST_CHKS_APPLI_END_ADDRESS        ((SYST_AddressWidth_t)__ghsbegin_AppliEnd)

/* FLASH blocks definition */

/* Use this defined if FLASH block definition must be stored in EEPROM.
   This feature is used to have a BLF (or other application) with "dynamic"
   block definition.
   The block definition are always present in ROM of client application.
   The client has to write block definition before changing application mode.
   BLF (or other application) read in EEPROM block definition. */
/* #define SYST_FLASH_BLOCK_DEF_IN_EEPROM */


#if defined(__CLIENT_LINK__)                        \
  || defined(__CLIENT_EOL_LINK__)                   \
  || ( ! defined(SYST_FLASH_BLOCK_DEF_IN_EEPROM))
#define SYST_FLASH_NB_OF_APPLI_BLOCK      ((ubyte)9)
#else
#define SYST_FLASH_NB_OF_APPLI_BLOCK      ((ubyte)(EEPS_SIZE_FLASH_BLOCK_ADDRESS/2/4 /* 4 is sizeof(SYST_AddressWidth_t) */))
#endif /* __CLIENT_LINK__
          || __CLIENT_EOL_LINK__
          || ! SYST_FLASH_BLOCK_DEF_IN_EEPROM */

#define SYST_FLASH_INDEX_OF_START         ((ubyte)0)
#define SYST_FLASH_INDEX_OF_END           ((ubyte)1)

/* Allowed programming number for one block blocks */
#define SYST_MAX_UPDATE_NB                2000


#if defined(__NEC_V850_Fx3__) || defined(__NEC_V850_Dx3__)
/* defined below the Start address of the FLASH/RAM re-direct boot code */
#pragma ghs startdata
#pragma ghs section data=".reservedForSelfLib"
extern ubyte __ghsbegin_reservedForSelfLib[];
#pragma ghs section data=default
#pragma ghs enddata

#define SYST_SELFLIB_RAMADD               ((SYST_AddressWidth_t)__ghsbegin_reservedForSelfLib)

/* defined below the Start address of the FLASH/RAM re-direct interrupt table */
#pragma ghs startdata
#pragma ghs section data=".DataRedVect"
extern ubyte __ghsbegin_DataRedVect[];
#pragma ghs section data=default
#pragma ghs enddata

#define SYST_TABLE_VECT_RAM               ((SYST_AddressWidth_t)__ghsbegin_DataRedVect)
#endif /* __NEC_V850_Fx3__ || __NEC_V850_Dx3__ */

#ifdef __REL_V850_Dx4__

/* defined below the Start address of the FLASH/RAM re-direct interrupt table */
#pragma ghs startdata
#pragma ghs section sdata=".DataRedVect"
extern ubyte __ghsbegin_DataRedVect[];
#pragma ghs section sdata=default
#pragma ghs enddata

#define SYST_TABLE_VECT_RAM               ((SYST_AddressWidth_t)__ghsbegin_DataRedVect)

#endif /* __REL_V850_Dx4__ */


/* Defined below the micro logical address (RAM, ROM and EEPROM) */
#pragma ghs startdata
#pragma ghs section data=".RamStart"
extern ubyte __ghsbegin_RamStart[];
#pragma ghs section data=default
#pragma ghs enddata

#define SYST_RAM_START_ADDRESS            ((SYST_AddressWidth_t)__ghsbegin_RamStart)

#pragma ghs startdata
#pragma ghs section data=".RamEnd"
extern ubyte __ghsbegin_RamEnd[];
#pragma ghs section data=default
#pragma ghs enddata

#define SYST_RAM_END_ADDRESS              ((SYST_AddressWidth_t)__ghsbegin_RamEnd)

#define SYST_EEPROM_SIZE                  (0x00001000) /* 4k */
#define SYST_EEPROM_START_ADDRESS         (SYST_AddressWidth_t)0x00800000 /* 8MB offset */
#define SYST_EEPROM_END_ADDRESS           (SYST_AddressWidth_t)(SYST_EEPROM_START_ADDRESS + SYST_EEPROM_SIZE - 1)


#define SYST_BURAM_SIZE                   (0x00002000) /* 8KB */
#define SYST_BURAM_START_ADDRESS          ((SYST_AddressWidth_t)0xFF760000)
#define SYST_BURAM_END_ADDRESS            ((SYST_AddressWidth_t)(SYST_BURAM_START_ADDRESS + SYST_BURAM_SIZE - 1))


/* Define below the address BOOT routine that permits to restart the product
into another application mode */

#pragma ghs startdata
#pragma ghs section rodata=".bootservice"
extern ubyte __ghsbegin_bootservice[];
#pragma ghs section rodata=default
#pragma ghs enddata

#define SYST_BOOT_SET                     ((SYST_AddressWidth_t)__ghsbegin_bootservice)


//#define SYST_ADDR_xxxx     ((SYST_AddressWidth_t)__ghsbegin_SectionName)

/* Define the start address of ISR vector table */
#pragma ghs startdata
#pragma ghs section rodata=".intvect"
extern ubyte __ghsbegin_intvect[];
#pragma ghs section rodata=default
#pragma ghs enddata

#if defined(__REL_V850_Dx4__)

#define SYST_TABLE_VECT_ROM                ((SYST_AddressWidth_t)__ghsbegin_intvect)


#endif /* defined(__REL_V850_Dx4__) */

#ifdef C_COMP_GHS_V850
#pragma ghs endnowarning
#endif /* C_COMP_GHS_V850 */
/******************************************************************************/
/******************************************************************************/
/*               End of address you want retrieve from mapping.               */
/******************************************************************************/
/******************************************************************************/



#endif /*__NEC_V850__*/


/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */


/*______ L O C A L - D E F I N E S ___________________________________________*/

/* uncomment this define if you want to use ISR(SYST_VoidInterruptHandler_it) */
#define Syst_VOID_ISR_SERVICE

/* uncomment this define if you want to use ISR(SYST_UnhandledException_it) */
#define Syst_UNHANDLED_ISR_SERVICE

/* uncomment this define if you want to use SYST_Wait() service */
#define Syst_WAIT_SERVICE

/* uncomment this define if you want to use SYST_RomChecksum() service */
#define Syst_ROM_CHECKSUM_SERVICE

/* uncomment this define if you want to use SYST_RamChecksum() service */
#define Syst_RAM_CHECKSUM_SERVICE

/* uncomment this define if you want to use SYST_ReadRom() service */
#define Syst_READ_ROM_SERVICE

/* Project type use 2 bytes */
/* i.e. : LL, ML, HL, EUrope ...                          */
/* XX if only one SW for Marelli cluster for this vehicle */
#define Syst_VERSION_TYPE    "MI"

/* uncomment this define to activate External flash support */
/*#define Syst_READ_EXTERNAL_SPI_FLASH_SERVICE*/
/* Additional services for external flash access */
/*#define Syst_READ_EXTERNAL_SPI_FLASH_UNTIL_SHORT_SERVICE*/
/*#define Syst_READ_EXTERNAL_SPI_FLASH_UNTIL_BYTE_SERVICE*/
/*#define Syst_READ_EXTERNAL_SPI_FLASH_ID_SERVICE*/

/* Define size of External Flash if exist */
/*#define Syst_EXT_FLASH_SIZE  0x40000*/
/* Define External flash Appli block if exist */
/*#define Syst_EXT_FLASH_APPLI_BLOCK   5*/

/* Define crc16 type */
#define Syst_CRC16_INV_CCITT
#undef  Syst_CRC16_CCITT

/* uncomment this define if you want to use SYST_UpdateInvCrc16Ccitt() service */
/* #define Syst_UPDATE_CRC16_INV_CCITT */

#define Syst_CHKSUM16_DATA_USED
#undef  Syst_COMPUTE_CRC16_USING_TABLE

/* uncomment this define if you want to use SYST_ComputeChecksumXOR() service */
/* #define Syst_CHECKSUM_XOR_USED */

/* Define crc32 */
#define Syst_CRC32


/* Define byte used sequence conversion services*/
/*#define Syst_BYTE_SEQ_LITTLE_ENDIAN_TO_ULONG*/
/*#define Syst_BYTE_SEQ_LITTLE_ENDIAN_TO_USHORT*/
#define Syst_BYTE_SEQ_BIG_ENDIAN_TO_ULONG
/*#define Syst_BYTE_SEQ_BIG_ENDIAN_TO_USHORT*/


/*_____ G L O B A L - T Y P E S ______________________________________________*/

typedef enum
{
  SYST_BLOCK_PROTECTED,
  SYST_BLOCK_UNPROTECTED
} SYST_BlockStatus_t;


#if defined(__MC9S12xx__) || defined(__NEC_V850__)

typedef struct
{
  ubyte _BlockType : 4;
  ubyte _MemType   : 4;
} SYST_BlockDefinition_t;

#define SYST_BDEF_NOT_USED       0

#define SYST_BDEF_BLOCK_BLF      1
#define SYST_BDEF_BLOCK_APPLI    2
#define SYST_BDEF_BLOCK_DATASET  3

#define SYST_BDEF_MEM_RAM        1
#define SYST_BDEF_MEM_EEPROM     2
#define SYST_BDEF_MEM_FLASH      3
#define SYST_BDEF_MEM_EXT_FLASH  4

#endif /* __MC9S12xx__ || __NEC_V850__ */


/*_____ G L O B A L - D A T A ________________________________________________*/






#if defined(__MC9S12xx__) || defined(__NEC_V850__)


  #ifdef SYST_FLASH_BLOCK_DEF_IN_EEPROM

    #if (EEPS_SIZE_FLASH_BLOCK_DEFINITION < (SYST_FLASH_NB_OF_APPLI_BLOCK*1))
    #error
    #endif /* EEPS_SIZE_FLASH_BLOCK_DEFINITION < (SYST_FLASH_NB_OF_APPLI_BLOCK*1) */
    #if (EEPS_SIZE_FLASH_BLOCK_ADDRESS < (SYST_FLASH_NB_OF_APPLI_BLOCK*2*4))
    #error
    #endif /* EEPS_SIZE_FLASH_BLOCK_ADDRESS < (SYST_FLASH_NB_OF_APPLI_BLOCK*2*4) */
    #if (EEPS_SIZE_FLASH_BLOCK_STATUS < (SYST_FLASH_NB_OF_APPLI_BLOCK*1))
    #error
    #endif /* EEPS_SIZE_FLASH_BLOCK_STATUS < (SYST_FLASH_NB_OF_APPLI_BLOCK*1) */

  #endif /* SYST_FLASH_BLOCK_DEF_IN_EEPROM */


  #if defined(__CLIENT_LINK__)                        \
    || defined(__CLIENT_EOL_LINK__)                   \
    || ( ! defined(SYST_FLASH_BLOCK_DEF_IN_EEPROM))
    extern SYST_BlockDefinition_t const SYST_FlashBlockDefinition[SYST_FLASH_NB_OF_APPLI_BLOCK];
  #else
    #define SYST_FlashBlockDefinition  ((SYST_BlockDefinition_t*)&EEPS_RamFlashBlockDefinition[0])
  #endif /* __CLIENT_LINK__
            || __CLIENT_EOL_LINK__
            || ! SYST_FLASH_BLOCK_DEF_IN_EEPROM */


  #if ( ( ! defined(SYST_FLASH_BLOCK_DEF_IN_EEPROM))  \
        &&( defined(__BOOT_LOADER_FLASHER_LINK__)     \
            ||defined(__BOOT_CLIENT_EOL_LINK__) ) )   \
    || ( defined(SYST_FLASH_BLOCK_DEF_IN_EEPROM)      \
         &&( defined(__CLIENT_LINK__)                 \
             ||defined(__CLIENT_EOL_LINK__) ) )
    extern SYST_AddressWidth_t const SYST_FlashBlockAddress[SYST_FLASH_NB_OF_APPLI_BLOCK][2];
    extern SYST_BlockStatus_t const SYST_FlashBlockStatus[SYST_FLASH_NB_OF_APPLI_BLOCK];
  #else
    #define SYST_FlashBlockAddress  ((SYST_AddressWidth_t*)&EEPS_RamFlashBlockAddress[0])
    #define SYST_FlashBlockStatus  ((SYST_BlockStatus_t*)&EEPS_RamFlashBlockStatus[0])
  #endif /* __CLIENT_LINK__
            || __CLIENT_EOL_LINK__
            || ! SYST_FLASH_BLOCK_DEF_IN_EEPROM */


#endif /* __MC9S12xx__ || __NEC_V850__ */

/* --- Marelli FBL package 07284 --- */
typedef struct
{
  ulong FblResetCommand;        /* This flag is used to handle BTL auto response in boot/app mode after a reset */
  ulong FblResetCommandCompl;   /* This flag is used to handle BTL auto response in boot/app mode after a reset (compl value) */
  ulong FblBtlCommand;          /* This flag is used by the APPL to start the BTL sequence */
  ulong FblBtlCommandCompl;     /* This flag is used by the APPL to start the BTL sequence (compl value) */
} SYST_FBLCommandDefinition_t;

/* --- Marelli FBL package 07284 --- */ 

#define SYST_FBL_START_BOOT                         ((SYST_BootKey_t) 0x33333333)

#if defined(C_COMP_GHS_TX49) || defined(C_COMP_GHS_V850) || defined(C_COMP_GHS_ARM)
#pragma ghs startdata
#pragma ghs section bss=".BootCmdZone"
#endif /* C_COMP_GHS_TX49 || C_COMP_GHS_V850 || C_COMP_GHS_ARM */

extern SYST_FBLCommandDefinition_t SYST_FBLCommand;

#if defined(C_COMP_GHS_TX49) || defined(C_COMP_GHS_V850) || defined(C_COMP_GHS_ARM)
#pragma ghs section bss=default
#pragma ghs enddata
#endif /* C_COMP_GHS_TX49 || C_COMP_GHS_V850 || C_COMP_GHS_ARM */


/*_____ G L O B A L - M A C R O S ____________________________________________*/

#ifdef SYST_DEBUG_RESET
#define SYST_Reset() SYST_DebugReset()
#else
  #ifdef SYST_SPECIAL_RESET
  #define SYST_Reset() COMS_Reset()
  #endif /* SYST_SPECIAL_RESET */
#endif /* SYST_DEBUG_RESET */


/*_____ G L O B A L - F U N C T I O N S - P R O T O T Y P E S_________________*/

#ifdef __POLYSPACE__
/* additionnal math.h function prototypes for Polyspace analysis */
extern float cosf (float v);
extern float sinf (float v);
extern float tanf (float v);
extern float sqrtf(float v);
#endif /* __POLYSPACE__ */


/*----------------------------------------------------------------------------*/
/* Name : SYST_ClockSelectorConfigSleep()                                     */
/* Role : Prepare Iso0 and AWO clock selectors before going to Deep Sleep mode*/
/* Interface : -                                                              */
/* Pre-condition :                                                            */
/*     - All interrupts have to be disabled                                   */
/* Constraints : -                                                            */
/* Behavior :                                                                 */
/*----------------------------------------------------------------------------*/
#ifdef __REL_V850_Dx4__
#ifdef SYST_PREPARE_CLK_SELECTOR_CFG
#define SYST_ClockSelectorConfigSleep()  CPUS_PrepareClockSelectorBeforeSleep()
#endif  /* SYST_PREPARE_CLK_SELECTOR_CFG */
#endif /* __REL_V850_Dx4__ */

/******************************************************************************/
/* Name: SYST_ConfigStartOsTick                                               */
/* Role: Restart Os system tick after sleep                                   */
/* Interface:                                                                 */
/* Preconditions: None                                                        */
/* Constraints: None                                                          */
/******************************************************************************/
void SYST_ConfigStartOsTick(void);

/******************************************************************************/
/* Name: SYST_ConfigStopOsTick                                                */
/* Role: Stop Os system tick before sleep                                     */
/* Interface:                                                                 */
/* Preconditions: None                                                        */
/* Constraints: None                                                          */
/******************************************************************************/
void SYST_ConfigStopOsTick(void);

/*----------------------------------------------------------------------------*/
/* Name : SYST_ConfigGoIntoStopMode()                                               */
/* Role : Put the REL V850E2/Dx4 in DEEPSTOP mode                             */
/* Interface : -                                                              */
/* Pre-condition :                                                            */
/*     - All interrupts have to be disabled                                   */
/* Constraints : -                                                            */
/*     - All interrupts have to be enabled after this service call            */
/*     - After occurrence of a wake-up event the microcontroller starts       */
/*       with its reset procedure                                             */
/* Behavior :                                                                 */
/*   DO                                                                       */
/*     [Enter ISO1 DEEPSTOP]                                                  */
/*     [Enter ISO0 DEEPSTOP to go into power save mode selected]              */
/*     [Seven nop are inserted to clear the pipeline]                         */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/
#if defined(__REL_V850_DJ4_HE__) || \
    defined(__REL_V850_DK4__) || \
    defined(__REL_V850_DN4H__)
void SYST_ConfigGoIntoStopMode(void);
#endif

#ifdef SYST_SOFTRESETCHECK_BEFORE_DEEPSTOP
/*----------------------------------------------------------------------------*/
/* Name : SYST_Config_SoftResetCheck()                                        */
/* Role : Check if the WAKEUP condition are already active before standby mode*/
/*        is started                                                          */
/* Interface : -                                                              */
/* Pre-condition :                                                            */
/* Constraints : -                                                            */
/* Behavior :                                                                 */
/*   DO                                                                       */
/*     [IF ANY wakeup condition is already active, save the wakeup FLAG status*/
/*     in internal BURAM and force reset]                                     */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/
void SYST_Config_SoftResetCheck(void);
#endif

#endif  /* SYST_CONFIG_H */

/*_____ E N D _____ (syst_config.h) __________________________________________*/
