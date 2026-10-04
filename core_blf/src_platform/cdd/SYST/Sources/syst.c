/******************************************************************************/
/* @F_NAME:          syst.c                                                   */
/* @F_PURPOSE:       syst module                                              */
/* @F_CREATED_BY:    Vincent RIOUAL                                           */
/* @F_CREATION_DATE: 14/06/2001                                               */
/* @F_MPROC_TYPE:    NEC_V850, MC9S12xx, MC9S08xx, TX49, IMX53, IMX6          */
/*                   REL_RL78_D1A, REL_RL78_F12, IMX6x                        */
/************************************** (C) Copyright 2015 Magneti Marelli ****/


/*______ I N C L U D E - F I L E S ___________________________________________*/

#include "syst.h"
#include "syst_config.h"
#ifndef  __CY_TV2__
#include "cpus_rh850.h"
#endif
#if defined(__REL_V850_DJ4_HE__) || \
    defined(__REL_V850_DN4H__)
#include "sscs.h"
#include "wdtd.h"
#endif

#ifdef SYST_DEBUG_RESET
#if defined(SYST_SPY_UART_USED) && defined(C_COMP_GHS_ARM)
#include <stdio.h>
#include <arm_ghs.h>
#endif /* SYST_SPY_UART_USED && C_COMP_GHS_ARM*/
#endif /* SYST_DEBUG_RESET */

#ifdef SYST_EVENT_SPY
#include "spys.h"
#endif/* SYST_EVENT_SPY*/
#include "vers_config_swid.h"
#ifndef __BOOT_LINK__
#include "vers_config.h"
#endif

#ifdef __POLYSPACE__
#include "pstgoto.h"
#endif /* __POLYSPACE__ */

#ifdef Syst_READ_EXTERNAL_SPI_FLASH_SERVICE
#include "iodc.h"
#include "spic.h"
#endif /* Syst_READ_EXTERNAL_SPI_FLASH_SERVICE */

#ifdef SYST_PREPARE_CLK_SELECTOR_CFG
#include "cpus.h"
#endif

#ifdef __GHOS__
#include "syst_priv.h"
#ifdef SYST_SW_IDENT_TABLE_USED
#ifdef __FLASHER_LINK__
#include "ftls.h"
#endif /* __FLASHER_LINK__ */
#endif /* SYST_SW_IDENT_TABLE_USED */
#endif /* __GHOS__ */
#if !defined(__CORE_CM0P__)
// #include "eeps.h"
// #include "eepc.h"
#endif
#ifdef __CLIENT_EOL_LINK__
#if !defined(__CORE_CM0P__)
// #include "vers_config_eep.h"
#endif
#if !defined(CY_CORE_CM7_0) && !defined(__CORE_CM0P__)
#include "spic.h"
#endif
#ifndef  __CY_TV2__
#include "rgrh850.h"
#else
#include "cy_sysreset.h"
#endif
#endif/*__CLIENT_EOL_LINK__*/


#ifdef  __CY_TV2__
#ifndef __CORE_CM0P__
// #include "syst_crypto_config_client.h"
#endif
#endif
/*______ L O C A L - D E F I N E _____________________________________________*/

#define Syst_POLYNOM_CCITT_INV  0x8408
#define Syst_POLYNOM_CCITT      0x1021

#define Syst_POLYNOM_CRC32      0x04C11DB7 /* generator polynomial for CRC32      */
#define Syst_INITIAL_REMAINDER  0xFFFFFFFFu /* POLYNOM is on 32 bits (not 33 bits) */
#define Syst_FINAL_XOR_VALUE    0xFFFFFFFF /* POLYNOM is on 32 bits (not 33 bits) */
#define Syst_WIDTH              (ubyte) 32u /* CRC size in bit                     */


#define SYST_CRC_Input_Width_32bit   (0u)
#define SYST_CRC_Input_Width_16bit   (1u)
#define SYST_CRC_Input_Width_8bit    (2u)

#define SYST_CRC_Method_32bit        (0u)
#define SYST_CRC_Method_16bit        (1u)

#define SYST_CRC_Output_Initial_32bit      (0xFFFFFFFFu)
#define SYST_CRC_Output_Initial_16bit      (0x0000FFFFu)


#ifdef __GHOS__
#ifdef SYST_SW_IDENT_TABLE_USED
#ifdef __FLASHER_LINK__

/* ELF File format types and headers structures */

#define EI_NIDENT 16

/* Elf Typedefs */
typedef unsigned long Elf32_Addr;  /* Unsigned program address */
typedef unsigned short Elf32_Half; /* Unsigned medium integer */
typedef unsigned long Elf32_Off;   /* Unsigned file offset */
typedef signed long Elf32_Sword;   /* Signed large integer */
typedef unsigned long Elf32_Word;  /* Unsigned large integer */

/* The Elf Header Structure */
typedef struct {
    unsigned char e_ident[EI_NIDENT];
    Elf32_Half e_type;
    Elf32_Half e_machine;
    Elf32_Word e_version;
    Elf32_Addr e_entry;
    Elf32_Off e_phoff;
    Elf32_Off e_shoff;
    Elf32_Word e_flags;
    Elf32_Half e_ehsize;
    Elf32_Half e_phentsize;
    Elf32_Half e_phnum;
    Elf32_Half e_shentsize;
    Elf32_Half e_shnum;
    Elf32_Half e_shstrndx;
} Elf32_Ehdr;    

/* Section Header Struct */
typedef struct {
    Elf32_Word sh_name;
    Elf32_Word sh_type;
    Elf32_Word sh_flags;
    Elf32_Addr sh_addr;
    Elf32_Off sh_offset;
    Elf32_Word sh_size;
    Elf32_Word sh_link;
    Elf32_Word sh_info;
    Elf32_Word sh_addralign;
    Elf32_Word sh_entsize;
} Elf32_Shdr;

/* The Symbol Table */
typedef struct {
    Elf32_Word st_name;
    Elf32_Addr st_value;
    Elf32_Word st_size;
    unsigned char st_info;
    unsigned char st_other;
    Elf32_Half st_shndx;
} Elf32_Sym;

/* The Program Header */
typedef struct {
    Elf32_Word p_type;
    Elf32_Off p_offset;
    Elf32_Addr p_vaddr;
    Elf32_Addr p_paddr;
    Elf32_Word p_filesz;
    Elf32_Word p_memsz;
    Elf32_Word p_flags;
    Elf32_Word p_align;
} Elf32_Phdr;

#endif /* __FLASHER_LINK__ */
#endif /* SYST_SW_IDENT_TABLE_USED */
#endif /* __GHOS__ */


/*______ L O C A L - T Y P E S________________________________________________*/

#if (defined(__REL_V850_Dx4__) || defined(__RH850_F1x__)) && (defined(SYST_DATA_SAVE_IN_RESET) || defined(SYST_DATA_SAVE_IN_DEEPSTOP))
typedef struct
{
  ulong* KeyPtr;
  const Syst_BkpSec_t* Secs;
  ubyte SecNb;
} Syst_BkpSecDef_t;
#endif /* (__REL_V850_DX4__ || __RH850_F1x__) && (SYST_DATA_SAVE_IN_RESET || SYST_DATA_SAVE_IN_DEEPSTOP) */

#ifdef SYST_DEBUG_ALLOC
typedef union
{
  struct
  {
    ulong Mod;
    ulong Size;
    ulong File;
    ulong Line;    
  } Computable;

  struct
  {
    char Mod[4];
    ulong Size;
    char File[4];
    ulong Line;
  } HumanReadable;
} Syst_DebugAllocHeader_t;
#endif /* SYST_DEBUG_ALLOC */


/*______ G L O B A L - D A T A _______________________________________________*/

#ifndef  __CY_TV2__
#pragma ghs startdata
#pragma ghs section bss=".DataBackupSyst"
#endif
#ifdef SYST_UseEMMCRecoverLogic
/*RstCounter and eMMCRecoverflag were stored in backup RAM.*/
static  ulong SystSWResetCounter;
static  ulong SystSWResetCounterCRC;
#endif /*SYST_UseLowVolBlockingLogic*/

#ifdef SYST_LimitSystemResetTimeLogic
static  ulong SystSWResetCounterTotal;
static  ulong SystSWResetCounterTotalCRC;
#endif /*SYST_LimitSystemResetTimeLogic*/

#ifdef SYST_UseEMMCRecoverLogic
static  ulong EmmcRecoveryStrategyFlag;
static  ulong SystInitializeBackRamFlag;
static  ulong SystInitializeBackRamFlagComp;
#endif /*SYST_UseLowVolBlockingLogic*/
#ifndef  __CY_TV2__
#pragma ghs section bss=default
#pragma ghs enddata
#endif/* __CY_TV2__*/

#ifdef SYST_UseEMMCRecoverLogic
static bool_t KL30_OffOnFlag  = FALSE  ;
#endif  /*SYST_UseEMMCRecoverLogic*/

#ifdef SYST_UseLowVolBlockingLogic
static bool_t CheckVoltageFlag  = FALSE  ;
#endif /*SYST_UseLowVolBlockingLogic*/

static  int SYST_PowerOnFlag  = FALSE  ;

#ifdef  __CY_TV2__
SYST_SleepMode_t SYST_SleepMode;

#endif
/* --- CRC16 computation table ---*/

#if (defined(Syst_CRC16_DATA_USED) && defined(Syst_COMPUTE_CRC16_USING_TABLE))
extern const ushort Syst_InvCrcTable[];
#endif


#if !defined(__GHOS__)

/* --- Boot key RAM statement --- */

#if defined(C_COMP_GHS_TX49) || defined(C_COMP_GHS_V850) || defined(C_COMP_GHS_RH850) || defined(C_COMP_GHS_ARM)
#ifdef __BOOT_LINK__
#pragma ghs startdata
#pragma ghs section bss=".BootKeyZone"
#endif/*__BOOT_LINK__*/
/* WARNING : Authors VIR, ALC                                                     */
/*           This .bss or .sbss section will not be cleared by the startup code,  */
/*           in the mapping description section attribute is set to NOCLEAR       */
#endif /* C_COMP_GHS_TX49 || C_COMP_GHS_V850 || C_COMP_GHS_ARM */

#if defined(C_COMP_COSMIC_MC9S12) || defined(C_COMP_COSMIC_MC9S08)
#pragma section [BootKeyZone]
#endif /* C_COMP_COSMIC_MC9S12 || C_COMP_COSMIC_MC9S08 */

#if defined(C_COMP_IAR_RL78)
#pragma dataseg=BootKeyZone
#endif /*C_COMP_IAR_RL78*/

__NO_INIT__ SYST_BootKey_t SYST_BOOT_KEY_RAM;
__NO_INIT__ SYST_BootKey_t SYST_BOOT_KEY_RAM_COMP;

#if defined(C_COMP_IAR_RL78)
#pragma dataseg=default
#endif /*C_COMP_IAR_RL78*/

#if defined(C_COMP_GHS_TX49) || defined(C_COMP_GHS_V850) || defined(C_COMP_GHS_RH850) || defined(C_COMP_GHS_ARM)
#ifdef __BOOT_LINK__
#pragma ghs section bss=default
#pragma ghs enddata
#endif/*__BOOT_LINK__*/
#endif /* C_COMP_GHS_TX49 || C_COMP_GHS_V850 || C_COMP_GHS_ARM */

#if defined(C_COMP_COSMIC_MC9S12) || defined(C_COMP_COSMIC_MC9S08)
#pragma section []
#endif /* C_COMP_COSMIC_MC9S12 || C_COMP_COSMIC_MC9S08 */

#endif /* !__GHOS__ */


/* --- Sleep key statement --- */

#ifdef SYST_DX4_DEEPSTOP_USED
#if defined(C_COMP_GHS_V850) && !defined(__GHOS__)
#pragma ghs startdata
#pragma ghs section bss=".SleepKey"
#endif /* C_COMP_GHS_V850 && !__GHOS__ */

__NO_INIT__ SYST_SleepKey_t SYST_SLEEP_KEY_RAM;

#if defined(C_COMP_GHS_V850) && !defined(__GHOS__)
#pragma ghs section bss=default
#pragma ghs enddata
#endif /* C_COMP_GHS_V850 && !__GHOS__ */
#endif /* SYST_DX4_DEEPSTOP_USED */

/* --- Application End flag ---*/
#if 0
#if defined(C_COMP_GHS_TX49) || defined(C_COMP_GHS_V850) || defined(C_COMP_GHS_RH850) || defined(__CY_TV2__) ||(defined(C_COMP_GHS_ARM) && (!defined(__GHOS__)))
#pragma ghs startdata
#pragma ghs section rodata=".ApplEndFlag"
#endif /* C_COMP_GHS_TX49 || C_COMP_GHS_V850 || (C_COMP_GHS_ARM && !__GHOS__) */
__ROOT__ const ubyte Syst_End[] = {'e','n','d'};
#if defined(C_COMP_GHS_TX49) || defined(C_COMP_GHS_V850) || defined(C_COMP_GHS_RH850) || defined(__CY_TV2__) || (defined(C_COMP_GHS_ARM) && (!defined(__GHOS__)))
#pragma ghs section rodata=default
#pragma ghs enddata
#endif /* C_COMP_GHS_TX49 || C_COMP_GHS_V850 || (C_COMP_GHS_ARM && !__GHOS__) */

#endif
/* --- SW identifier statement ---*/
#if !defined(__FBL_UPDATER__)
#if defined(C_COMP_GHS_TX49) || defined(C_COMP_GHS_V850) || defined(C_COMP_GHS_RH850) || defined(__CY_TV2__) || (defined(C_COMP_GHS_ARM) && (!defined(__GHOS__)))
//#pragma ghs startdata
//#pragma ghs section rodata=".CONST_SW_ID"
#endif /* C_COMP_GHS_TX49 || C_COMP_GHS_V850 || (C_COMP_GHS_ARM && !__GHOS__) */

#if defined(C_COMP_COSMIC_MC9S12) || defined(C_COMP_COSMIC_MC9S08)
#pragma section const {CONST_SW_ID}
#endif /* C_COMP_COSMIC_MC9S12 || C_COMP_COSMIC_MC9S08 */

#if defined(C_COMP_IAR_RL78)
#pragma constseg=CONST_SW_ID
#endif /*C_COMP_IAR_RL78*/

__ROOT__ const SYST_SwIdentifier_t SYST_SwIdentifier =
{
  NULL,
#if 0
  &_start,
  (ulong)Syst_End,
  Vers_PROJECT_NAME,
  Vers_VERSION,
  Syst_VERSION_TYPE,
  {Vers_DAY, Vers_MONTH, Vers_YEAR}, /* BCD */
  SYST_SW_YEAR,                      /* Hex */
#if defined ( DIAG_SERVICE_22F189 )
  SYST_SW_WEEK,                       /* Hex */
  ECU_SW_VerNum					 /* ASCII, string,Store Diagnosis Service $22 $F1 $89,--VehicleManufacturerECUSoftwareVersionNumber*/
#else
  SYST_SW_WEEK                       /* Hex */
#endif
#endif
};

#if defined(C_COMP_IAR_RL78)
#pragma constseg=default
#endif /*C_COMP_IAR_RL78*/

#if defined(C_COMP_GHS_TX49) || defined(C_COMP_GHS_V850) || defined(C_COMP_GHS_RH850) || defined(__CY_TV2__) || (defined(C_COMP_GHS_ARM) && (!defined(__GHOS__)))
//#pragma ghs section rodata=default
//#pragma ghs enddata
#endif /* C_COMP_GHS_TX49 || C_COMP_GHS_V850 || (C_COMP_GHS_ARM && !__GHOS__) */
#endif /*__FBL_UPDATER__*/

#if defined(C_COMP_COSMIC_MC9S12) || defined(C_COMP_COSMIC_MC9S08)
#pragma section const {}
#endif /* C_COMP_COSMIC_MC9S12 || C_COMP_COSMIC_MC9S08 */


#if !defined(__GHOS__)

#ifdef SYST_SW_IDENT_TABLE_USED

/* --- All SW part Ident table statement ---*/

#if defined(C_COMP_GHS_ARM)
#pragma ghs startdata
#pragma ghs section bss=".SwIdentArea"
#endif /* C_COMP_GHS_ARM */

SYST_SwIdentifier_t SYST_SwIdentTable[4];

#if defined(C_COMP_GHS_ARM)
#pragma ghs section bss=default
#pragma ghs enddata
#endif /* C_COMP_GHS_ARM */

#endif /* SYST_SW_IDENT_TABLE_USED */

#endif /* !__GHOS__ */


#ifdef __GHOS__

IODevice SYST_IODevice;

#ifdef __FSL_IMX6x__
MemoryRegion SYST_AnalogMemoryRegion;
MemoryRegion SYST_AnalogVirtualMemoryRegion;
#endif /* __FSL_IMX6x__ */

#endif /* __GHOS__ */


/*______ L O C A L - D A T A _________________________________________________*/

#if (defined(__REL_V850_Dx4__) || defined(__RH850_F1x__)) && (defined(SYST_DATA_SAVE_IN_RESET) || defined(SYST_DATA_SAVE_IN_DEEPSTOP))
/* --- BURAM statement key --- */

#if defined(SYST_DATA_SAVE_IN_RESET)

#if defined(C_COMP_GHS_V850) || defined(C_COMP_GHS_RH850)
#pragma ghs startdata
#pragma ghs section bss=".BkpKeyBoot"
#endif /* C_COMP_GHS_V850 */

static __NO_INIT__ SYST_BkpKey_t Syst_BkpKeyBoot;

#if defined(C_COMP_GHS_V850) || defined(C_COMP_GHS_RH850)
#pragma ghs section bss=default
#pragma ghs enddata
#endif /* C_COMP_GHS_V850 */

#if defined(C_COMP_GHS_V850) || defined(C_COMP_GHS_RH850)
#pragma ghs startdata
#pragma ghs section bss=".BkpKeyBeforeInit"
#endif /* C_COMP_GHS_V850 */

static __NO_INIT__ SYST_BkpKey_t Syst_BkpKeyBeforeInit;

#if defined(C_COMP_GHS_V850) || defined(C_COMP_GHS_RH850)
#pragma ghs section bss=default
#pragma ghs enddata
#endif /* C_COMP_GHS_V850 */

#endif /* SYST_DATA_SAVE_IN_RESET */

#if defined(SYST_DATA_SAVE_IN_DEEPSTOP) || defined(C_COMP_GHS_RH850)

#if defined(C_COMP_GHS_V850) || defined(C_COMP_GHS_RH850)
#pragma ghs startdata
#pragma ghs section bss=".BkpKeySleepBeforeInit"
#endif /* C_COMP_GHS_V850 */

static __NO_INIT__ SYST_BkpKey_t Syst_BkpKeySleepBeforeInit;

#if defined(C_COMP_GHS_V850) || defined(C_COMP_GHS_RH850)
#pragma ghs section bss=default
#pragma ghs enddata
#endif /* C_COMP_GHS_V850 */

#if defined(C_COMP_GHS_V850) || defined(C_COMP_GHS_RH850)
#pragma ghs startdata
#pragma ghs section bss=".BkpKeySleepAfterInit"
#endif /* C_COMP_GHS_V850 */

static __NO_INIT__ SYST_BkpKey_t Syst_BkpKeySleepAfterInit;

#if defined(C_COMP_GHS_V850) || defined(C_COMP_GHS_RH850)
#pragma ghs section bss=default
#pragma ghs enddata
#endif /* C_COMP_GHS_V850 */

#endif /* SYST_DATA_SAVE_IN_DEEPSTOP */


extern Syst_BkpSec_t const Syst_BkpSectBoot[Syst_BKP_SEC_NB_BOOT];
extern Syst_BkpSec_t const Syst_BkpSecBeforeInit[Syst_BKP_SEC_NB_BEFORE_INIT];
extern Syst_BkpSec_t const Syst_BkpSecSleepBeforeInit[Syst_BKP_SEC_NB_SLEEP_BEFORE_INIT];
extern Syst_BkpSec_t const Syst_BkpSecSleepAfterInit[Syst_BKP_SEC_NB_SLEEP_AFTER_INIT];


static Syst_BkpSecDef_t const Syst_BkpSecDefs[SYST_BKP_SEC_NB] =
{
  #if defined(SYST_DATA_SAVE_IN_RESET)
  {&Syst_BkpKeyBoot, Syst_BkpSectBoot, Syst_BKP_SEC_NB_BOOT},
  {&Syst_BkpKeyBeforeInit, Syst_BkpSecBeforeInit, Syst_BKP_SEC_NB_BEFORE_INIT},
  #else
  {NULL, NULL, 0},
  {NULL, NULL, 0},
  #endif /* SYST_DATA_SAVE_IN_RESET */
  #if defined(SYST_DATA_SAVE_IN_DEEPSTOP)
  {&Syst_BkpKeySleepBeforeInit, Syst_BkpSecSleepBeforeInit, Syst_BKP_SEC_NB_SLEEP_BEFORE_INIT},
  {&Syst_BkpKeySleepAfterInit, Syst_BkpSecSleepAfterInit, Syst_BKP_SEC_NB_SLEEP_AFTER_INIT}
  #else
  {NULL, NULL, 0},
  {NULL, NULL, 0}
  #endif /* SYST_DATA_SAVE_IN_DEEPSTOP */
};
#endif /* __REL_V850_DX4__ && (SYST_DATA_SAVE_IN_RESET || SYST_DATA_SAVE_IN_DEEPSTOP) */

#ifdef SYST_DEBUG_ALLOC
static ulong Syst_TotalAllocSize = 0;
#endif /* SYST_DEBUG_ALLOC */

#if !defined(__BOOT_LOADER_LINK__)
static enum
{
  Syst_WRITE_BOOT_KEY_IDLE = 0,
  Syst_WRITE_BOOT_KEY,
  Syst_WRITE_BOOT_KEY_END
} Syst_WriteBootKeyState;
#endif /* !__BOOT_LOADER_LINK__ */

#ifdef __GHOS__
#ifdef SYST_SW_IDENT_TABLE_USED
#ifdef __FLASHER_LINK__

static enum
{
  Syst_UPDATE_CLIENT_IDENT_IDLE = 0,
  Syst_UPDATE_CLIENT_IDENT_WAIT_ELF_HEADER_READ,
  Syst_UPDATE_CLIENT_IDENT_DATA_READ,
  Syst_UPDATE_CLIENT_IDENT_WAIT_1ST_DATA_READ,
  Syst_UPDATE_CLIENT_IDENT_WAIT_END_DATA_READ,
  Syst_UPDATE_CLIENT_IDENT_END,
  Syst_UPDATE_CLIENT_IDENT_ERROR
} Syst_UpdateClientIdentState;

#pragma align (4)         /* Buffers must be Word aligned */
static ubyte Syst_ElfHeaderBuffer[FTLS_PAGE_SIZE];
static ubyte Syst_ElfDataBuffer[FTLS_PAGE_SIZE];
static ubyte Syst_SwIdentBuffer[sizeof(SYST_SwIdentifier_t)];

#endif /* __FLASHER_LINK__ */
#endif /* SYST_SW_IDENT_TABLE_USED */
#endif /* __GHOS__ */

#ifdef SYST_NAND_FLASH_USED
#ifdef Syst_READ_ROM_SERVICE
static enum
{
  Syst_READ_NAND_FLASH_IDLE = 0,
  Syst_READ_NAND_FLASH_WAIT_1ST_DATA_READ,
  Syst_READ_NAND_FLASH_WAIT_END_DATA_READ
} Syst_ReadNandFlashState;

#pragma align (4)         /* Buffers must be Word aligned */
static ubyte Syst_NandFlashBuffer[FTLS_PAGE_SIZE];
#endif /* Syst_READ_ROM_SERVICE */
#endif /* SYST_NAND_FLASH_USED */

#ifdef __GHOS__
#ifdef SYST_MEASUREMENT_TIMER_USED
/* Clock object for measurement */
static Clock Syst_MeasureClock;

static Time Syst_MeasureClockStartTime;

#endif /* SYST_MEASUREMENT_TIMER_USED */
#endif /* __GHOS__ */


/*______ L O C A L - M A C R O S _____________________________________________*/


/*______ I M P O R T - F U N C T I O N S - P R O T O T Y P E S _______________*/


/*______ L O C A L - F U N C T I O N S - P R O T O T Y P E S _________________*/

#if defined(Syst_CRC16_CCITT)
static ushort Syst_UpdateCrc16Ccitt(ushort crc, ubyte data);
#endif /* Syst_CRC16_CCITT */

#if defined(Syst_CRC32)
static ulong Syst_reflect( ulong data, ubyte nBits );
#endif /* Syst_CRC32 */


/*______ G L O B A L - F U N C T I O N S _____________________________________*/

/*----------------------------------------------------------------------------*/
/* Name : SYST_Init                                                           */
/* Role : Init this module                                                    */
/* Interface : void                                                           */
/* Pre-condition : -                                                          */
/* Constraints : Call one time at reset                                       */
/* Behavior :                                                                 */
/*  DO                                                                        */
/*    [ Request System IO device resource ]                                   */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
void SYST_Init(void)
{
  #ifdef __GHOS__

  #ifdef __FSL_IMX6x__
  Value Attr;
  Address Start;
  Address Last;
  #endif /* __FSL_IMX6x__ */

  CheckSuccess(RequestResource((Object*)&SYST_IODevice, "SYST_IODevice", "!systempassword"));

  #ifdef __FSL_IMX6x__
  /* Map in ANALOG registers to allow access to Chip Silicon Version (USB_ANALOG_DIGPROG register) */
  CheckSuccess(RequestResource((Object*)&SYST_AnalogMemoryRegion, "SYST_AnalogMemoryArea", "!systempassword"));
  CheckSuccess(GetMemoryRegionAddresses(SYST_AnalogMemoryRegion, &Start, &Last));
  /* Request a virtual memory region at the same address as the physical one */
  CheckSuccess(AllocateMemoryRegion(__ghs_VirtualMemoryRegionPool, ANALOG_BASE_ADDR_ASM, ANALOG_BASE_ADDR_ASM + Last - Start, &SYST_AnalogVirtualMemoryRegion));
  CheckSuccess(GetMemoryRegionAttributes(SYST_AnalogMemoryRegion, &Attr));
  CheckSuccess(SetMemoryRegionAttributes(SYST_AnalogVirtualMemoryRegion, Attr));
  CheckSuccess(MapMemoryRegion(SYST_AnalogVirtualMemoryRegion, SYST_AnalogMemoryRegion));
  #endif /* __FSL_IMX6x__ */

  #ifdef SYST_SW_IDENT_TABLE_USED
  #ifdef __FLASHER_LINK__
  Syst_UpdateClientIdentState = Syst_UPDATE_CLIENT_IDENT_IDLE;
  #endif /* __FLASHER_LINK__ */
  #endif /* SYST_SW_IDENT_TABLE_USED */

  #ifdef SYST_MEASUREMENT_TIMER_USED
  /* Create the clock object for measurement */
  CheckSuccess(CreateVirtualClock(HighResClock, CLOCK_READTIME, &Syst_MeasureClock));
  #endif /* SYST_MEASUREMENT_TIMER_USED */

  #endif /* __GHOS__ */

  #if !defined(__BOOT_LOADER_LINK__)
  Syst_WriteBootKeyState = Syst_WRITE_BOOT_KEY_IDLE;
  #endif /* !__BOOT_LOADER_LINK__ */

  #ifdef SYST_NAND_FLASH_USED
  #ifdef Syst_READ_ROM_SERVICE
  Syst_ReadNandFlashState = Syst_READ_NAND_FLASH_IDLE;
  #endif /* Syst_READ_ROM_SERVICE */
  #endif /* SYST_NAND_FLASH_USED */

#ifdef __CLIENT_EOL_LINK__
#if !defined(CY_CORE_CM7_0) && !defined(__CORE_CM0P__)
  // IODC_Init();
  // SPID_Init();
  // SPIC_Init();

  // EEPC_Init();


  // SYST_BOOT_KEY_RAM = VERS_GetBootKey1();
#endif

  if((SYST_BOOT_KEY_RAM != SYST_CLIENT) &&
     (SYST_BOOT_KEY_RAM != SYST_EOL))
  { /* If boot key does not match EOL or CLIENT, enter to CLIENT forcefully*/
    SYST_BOOT_KEY_RAM = SYST_CLIENT;
  }

#endif
}


#ifdef __GHOS__
/*----------------------------------------------------------------------------*/
/* Name : SYST_GetPhysicalAddress                                             */
/* Role : Get physical address of a data belonging in this VAS                */
/* Interface :                                                                */
/*    IN:  - Pointer to the data                                              */
/*    OUT: - Physical address                                                 */
/* Pre-condition : none                                                       */
/* Constraints : none                                                         */
/* Behavior :                                                                 */
/*  DO                                                                        */
/*    [ Use INtegrity IO device to get physical address of the data ]         */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
ulong SYST_GetPhysicalAddress(void *DataPtr)
{
  Buffer BuffStruct;
  Value PhysicalAddress;

  PhysicalAddress = 0;

  BuffStruct.BufferType  = DataBuffer | LastBuffer;
  BuffStruct.TheAddress  = (Address)DataPtr;
  BuffStruct.Length      = 1;
  BuffStruct.Transferred = 0;
  CheckSuccess(WriteBuffersToIODevice(SYST_IODevice, 0 ,0, &BuffStruct));
  CheckSuccess(ReadIODeviceRegister(SYST_IODevice, Syst_PHYSICAL_ADDRESS, &PhysicalAddress));

  return (ulong)PhysicalAddress;
}
#endif /* __GHOS__ */

#ifdef __GHOS__
/*----------------------------------------------------------------------------*/
/* Name : SYST_PrintCpuClocks                                                 */
/* Role : Print System On Chip clocks                                         */
/* Interface :                                                                */
/*    IN:  -                                                                  */
/*    OUT: -                                                                  */
/* Pre-condition : none                                                       */
/* Constraints : none                                                         */
/* Behavior :                                                                 */
/*  DO                                                                        */
/*    [ Use INtegrity IO device to print the clocks ]                         */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
void SYST_PrintSocClocks(void)
{
  /* Print all clocks */
  CheckSuccess(WriteIODeviceRegister(SYST_IODevice, Syst_PRINT_CLOCKS, 0));
}
#endif


#ifdef __GHOS__
#ifdef SYST_SW_IDENT_TABLE_USED

/*----------------------------------------------------------------------------*/
/* Name : SYST_GetSwPartIdent                                                 */
/* Role : Get Idenitifaction of a Sw Part of the system.                      */
/*        These identifications have been got from Nand Flash memory at       */
/*        system boot time by Boot Loader.                                    */
/* Interface :                                                                */
/*    IN:  - Pointer where to store SW Part Ident                             */
/*         - Sw Part Ident Index:                                             */
/*             SYST_BL_SW_ID_INDEX                                            */
/*             SYST_FLASHER_SW_ID_INDEX                                       */
/*             SYST_CLIENT_SW_ID_INDEX                                        */
/*             SYST_EOL_SW_ID_INDEX                                           */
/*    OUT: - Ident of the requested Sw Part                                   */
/* Pre-condition : none                                                       */
/* Constraints : none                                                         */
/* Behavior :                                                                 */
/*  DO                                                                        */
/*   [ Store Ident of requested SW Part ]                                     */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
void SYST_GetSwPartIdent(ubyte *SwIdentPtr, ubyte SwPartIndex)
{
  switch (SwPartIndex)
  {
    case SYST_BL_SW_ID_INDEX:
     CheckSuccess(ReadIODeviceStatus(SYST_IODevice, Syst_BL_SW_ID_INDEX, SwIdentPtr, sizeof(SYST_SwIdentifier_t)));
     break;

    case SYST_FLASHER_SW_ID_INDEX:
     CheckSuccess(ReadIODeviceStatus(SYST_IODevice, Syst_FLASHER_SW_ID_INDEX, SwIdentPtr, sizeof(SYST_SwIdentifier_t)));
     break;

    case SYST_CLIENT_SW_ID_INDEX:
     CheckSuccess(ReadIODeviceStatus(SYST_IODevice, Syst_CLIENT_SW_ID_INDEX, SwIdentPtr, sizeof(SYST_SwIdentifier_t)));
     break;

    case SYST_EOL_SW_ID_INDEX:
     CheckSuccess(ReadIODeviceStatus(SYST_IODevice, Syst_EOL_SW_ID_INDEX, SwIdentPtr, sizeof(SYST_SwIdentifier_t)));
     break;
  }
}

#ifdef __FLASHER_LINK__
/*----------------------------------------------------------------------------*/
/* Name : SYST_UpdateClientSwIdentFromFlash                                   */
/* Role : Read Idenitifaction of CLIENT Sw Part from Nand Flash memory and    */
/*        update Client SW Part identification information returned by .      */
/*        SYST_GetSwPartIdent service.                                        */
/*        Typically used after a CLIENT Sw Update by FLASHER application.     */
/* Interface :                                                                */
/*    IN:  -                                                                  */
/*    OUT: - Operation status:                                                */
/*           SYST_IN_PROGRESS if operation in progress                        */
/*           SYST_ERROR if operation fails                                    */
/*           SYST_COMPLETE when operation is completed                        */
/* Pre-condition : none                                                       */
/* Constraints : Must be called while returns SYST_IN_PROGRESS                */
/* Behavior :                                                                 */
/*  DO                                                                        */
/*  DO                                                                        */
/*   [ Read ELF file Header ]                                                 */
/*   [ Point to the program header containing the SW Idenitification ]        */
/*   IF Program segment size is equal to Ident structure                      */
/*    [ Copy SW Ident Program segment content into RAM ]                      */
/*   ELSE                                                                     */
/*    [ Set all Sw Id area to 0 in RAM ]                                      */
/*   FI                                                                       */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
SYST_Status_t SYST_UpdateClientSwIdentFromFlash(void)
{
  SYST_Status_t Status;
  FTLS_Status FtlsReturn;
  FTLS_RequestType FtlsStatus;
  Elf32_Phdr* ProgramHeader;
  ubyte *RamAddress;
  ulong FlashAddress;
  ulong PageOffset;
  ulong FlashSize;

  Status = SYST_IN_PROGRESS;

  switch (Syst_UpdateClientIdentState)
  {
    case Syst_UPDATE_CLIENT_IDENT_IDLE:
      /* Load ELF header */
      FtlsReturn = FTLS_ReadRequest(Syst_ElfHeaderBuffer, (ubyte *)SYST_CLIENT_START_NAND_ADDRESS, FTLS_PAGE_SIZE);
      if (FtlsReturn == FTLS_NO_ERROR)
      {
        Syst_UpdateClientIdentState = Syst_UPDATE_CLIENT_IDENT_WAIT_ELF_HEADER_READ;
      }
      break;

    case Syst_UPDATE_CLIENT_IDENT_WAIT_ELF_HEADER_READ:
      FtlsStatus = FTLS_GetFTLStatus();
      if (FtlsStatus == FTLS_READ_FINISHED)
      {
        Syst_UpdateClientIdentState = Syst_UPDATE_CLIENT_IDENT_DATA_READ;
      }
      else if (FtlsStatus == FTLS_READ_ERROR)
      {
        /* Read failed */
        Syst_UpdateClientIdentState = Syst_UPDATE_CLIENT_IDENT_ERROR;
      }
      break;

    case Syst_UPDATE_CLIENT_IDENT_DATA_READ:
      /* Point to the program header containing the SW Idenitification */
      ProgramHeader = (Elf32_Phdr*)(Syst_ElfHeaderBuffer + (((Elf32_Ehdr*)Syst_ElfHeaderBuffer)->e_phoff) + (SYST_SW_ID_ELF_PROG_SEG_NB * (((Elf32_Ehdr*)Syst_ElfHeaderBuffer)->e_phentsize)));

      /* If Flash segment size is the correct one */
      if (ProgramHeader->p_filesz == sizeof(SYST_SwIdentifier_t))
      {
        /* Set program segment FLASH source address */
        FlashAddress = (ulong)SYST_CLIENT_START_NAND_ADDRESS + ProgramHeader->p_offset;
        
        /* Set Flash page alignment offset */
        PageOffset = FlashAddress & (FTLS_PAGE_SIZE - 1);
        
        /* Set Flash segment size */
        FlashSize = ProgramHeader->p_filesz;

        /* if Flash start address not Flash page aligned */
        if (PageOffset)
        {
          /* Read useful part of 1st Flash page */
          FlashAddress = FlashAddress & ~(ulong)(FTLS_PAGE_SIZE - 1);
          FtlsReturn = FTLS_ReadRequest(Syst_ElfDataBuffer, (ubyte *)FlashAddress, FTLS_PAGE_SIZE);
          if (FtlsReturn == FTLS_NO_ERROR)
          {
            Syst_UpdateClientIdentState = Syst_UPDATE_CLIENT_IDENT_WAIT_1ST_DATA_READ;
          }
        }
        /* else, start address is Flash page aligned */
        else
        {
          /* Raed all usefull part in one time */
          FtlsReturn = FTLS_ReadRequest(Syst_SwIdentBuffer, (ubyte *)FlashAddress, FlashSize);
          if (FtlsReturn == FTLS_NO_ERROR)
          {
            Syst_UpdateClientIdentState = Syst_UPDATE_CLIENT_IDENT_WAIT_END_DATA_READ;
          }
        }
      }
      else
      {
        /* Wrong Flash segment */
        Syst_UpdateClientIdentState = Syst_UPDATE_CLIENT_IDENT_ERROR;
      }
      break;

    case Syst_UPDATE_CLIENT_IDENT_WAIT_1ST_DATA_READ:
      FtlsStatus = FTLS_GetFTLStatus();
      if (FtlsStatus == FTLS_READ_FINISHED)
      {
        /* Point to the program header containing the SW Idenitification */
        ProgramHeader = (Elf32_Phdr*)(Syst_ElfHeaderBuffer + (((Elf32_Ehdr*)Syst_ElfHeaderBuffer)->e_phoff) + (SYST_SW_ID_ELF_PROG_SEG_NB * (((Elf32_Ehdr*)Syst_ElfHeaderBuffer)->e_phentsize)));

        /* Set program segment FLASH source address */
        FlashAddress = (ulong)SYST_CLIENT_START_NAND_ADDRESS + ProgramHeader->p_offset;
        
        /* Set RAM destination address */
        RamAddress = Syst_SwIdentBuffer;
        
        /* Set Flash page alignment offset */
        PageOffset = FlashAddress & (FTLS_PAGE_SIZE - 1);
        
        /* Set Flash segment size */
        FlashSize = ProgramHeader->p_filesz;

        /* Save useful part of 1st Flash page */
        memcpy((void *)RamAddress,
               Syst_ElfDataBuffer + PageOffset,
               ((FTLS_PAGE_SIZE - PageOffset) < FlashSize) ? FTLS_PAGE_SIZE - PageOffset : FlashSize);
        RamAddress += ((FTLS_PAGE_SIZE - PageOffset) < FlashSize) ? FTLS_PAGE_SIZE - PageOffset : FlashSize;
        FlashAddress += FTLS_PAGE_SIZE;
        FlashSize -= ((FTLS_PAGE_SIZE - PageOffset) < FlashSize) ? FTLS_PAGE_SIZE - PageOffset : FlashSize;
  
        /* Read rest of segment if any */
        if (FlashSize)
        {
          FtlsReturn = FTLS_ReadRequest(RamAddress, (ubyte *)FlashAddress, FlashSize);
          if (FtlsReturn == FTLS_NO_ERROR)
          {
            Syst_UpdateClientIdentState = Syst_UPDATE_CLIENT_IDENT_WAIT_END_DATA_READ;
          }
        }
        else
        {
          Syst_UpdateClientIdentState = Syst_UPDATE_CLIENT_IDENT_END;
        }
      }
      else if (FtlsStatus == FTLS_READ_ERROR)
      {
        /* Read failed */
        Syst_UpdateClientIdentState = Syst_UPDATE_CLIENT_IDENT_ERROR;
      }
      break;

    case Syst_UPDATE_CLIENT_IDENT_WAIT_END_DATA_READ:
      FtlsStatus = FTLS_GetFTLStatus();
      if (FtlsStatus == FTLS_READ_FINISHED)
      {
        Syst_UpdateClientIdentState = Syst_UPDATE_CLIENT_IDENT_END;
      }
      else if (FtlsStatus == FTLS_READ_ERROR)
      {
        /* Read failed */
        Syst_UpdateClientIdentState = Syst_UPDATE_CLIENT_IDENT_ERROR;
      }
      break;

    case Syst_UPDATE_CLIENT_IDENT_END:
      /* Update Client SW Ident in SW Ident table */
      CheckSuccess(WriteIODeviceStatus(SYST_IODevice, Syst_CLIENT_SW_ID_INDEX, Syst_SwIdentBuffer, sizeof(SYST_SwIdentifier_t)));

      Syst_UpdateClientIdentState = Syst_UPDATE_CLIENT_IDENT_IDLE;

      Status = SYST_COMPLETE;
      break;

    case Syst_UPDATE_CLIENT_IDENT_ERROR:
      /* In case of error, do not update Client SW Ident */

      Syst_UpdateClientIdentState = Syst_UPDATE_CLIENT_IDENT_IDLE;

      Status = SYST_ERROR;
      break;

    default:
      break;
  }

  return Status;
}
#endif /* __FLASHER_LINK__ */

#endif /* SYST_SW_IDENT_TABLE_USED */
#endif /* __GHOS__ */


#if !defined(__BOOT_LOADER_LINK__)
#if defined(__CLIENT_EOL_LINK__) || defined(__BOOT_CLIENT_EOL_LINK__)
/*----------------------------------------------------------------------------*/
/* Name : SYST_GetBootKey                                                     */
/* Role : Get BootKey value in Ram                                            */
/* Interface :                                                                */
/*    IN:  -                                                                  */
/*    OUT: - Boot Key value                                                   */
/* Pre-condition : none                                                       */
/* Constraints : none                                                         */
/* Behavior :                                                                 */
/*  DO                                                                        */
/*   [ Return boot key value in RAM ]                                         */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
SYST_BootKey_t SYST_GetBootKey(void)
{
  #if !defined(__GHOS__)

  return SYST_BOOT_KEY_RAM;

  #else

  ulong BootKey;

  CheckSuccess(ReadIODeviceRegister(SYST_IODevice, Syst_BOOT_KEY_RAM, &BootKey));
  return (SYST_BootKey_t)BootKey;

  #endif /* !__GHOS__ */
}
#endif /* __CLIENT_EOL_LINK__ || __BOOT_CLIENT_EOL_LINK__ */


/*----------------------------------------------------------------------------*/
/* Name : SYST_SetBootKey                                                     */
/* Role : Write a BootKey value in Eeprom or Ram                              */
/* Interface :                                                                */
/*    IN:  - Boot Key value                                                   */
/*    IN:  - TRUE to store value in Eeprom, FALSE to store in Ram             */
/*    OUT: - Operation status:                                                */
/*           SYST_IN_PROGRESS if operation in progress                        */
/*           SYST_COMPLETE when operation is completed                        */
/* Pre-condition : none                                                       */
/* Constraints : If Store value in eeprom is requested, must be called until  */
/*               returns SYST_COMPLETE                                        */
/* Behavior :                                                                 */
/*  DO                                                                        */
/*   IF Store value in eeprom is requested                                    */
/*    [ Manage Write boot key value in EEPROM ]                               */
/*   ELSE                                                                     */
/*    [ Write Boot Key in backup RAM ]                                        */
/*   FI                                                                       */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
SYST_Status_t SYST_SetBootKey(SYST_BootKey_t BootKey,
                              bool_t         StoreInEep)
{
  SYST_Status_t Status;

  Status = SYST_IN_PROGRESS;

  if (StoreInEep == TRUE)
  {
      /*
       * by shubin
       * porting is not finished,
       * there is no eepc module integrated
       * */
#if 0
    if (EEPC_GetStatus() == EEPC_TERMINATED)
    {
      /* Manage Write of new boot key value */
      switch (Syst_WriteBootKeyState)
      {
        case Syst_WRITE_BOOT_KEY_IDLE:
          EEPS_RamBootKey1 = BootKey;
          EEPS_RamBootKey2 = (SYST_BootKey_t)(~BootKey);
          EEPC_WriteData(EEPC_ID_BOOT_KEY_1);
          Syst_WriteBootKeyState = Syst_WRITE_BOOT_KEY;
          break;

        case Syst_WRITE_BOOT_KEY:
          EEPC_WriteData(EEPC_ID_BOOT_KEY_2);
          Syst_WriteBootKeyState = Syst_WRITE_BOOT_KEY_END;
          break;

        case Syst_WRITE_BOOT_KEY_END:
          Syst_WriteBootKeyState = Syst_WRITE_BOOT_KEY_IDLE;
          Status = SYST_COMPLETE;
          break;

        default:
          break;
      }
    }
#else
    Syst_WriteBootKeyState = Syst_WRITE_BOOT_KEY_IDLE;
#endif
  }
  else
  {
    #if !defined(__GHOS__)
    SYST_BOOT_KEY_RAM = BootKey;
    SYST_BOOT_KEY_RAM_COMP = (SYST_BootKey_t)(~BootKey);
    #else
    CheckSuccess(WriteIODeviceRegister(SYST_IODevice, Syst_BOOT_KEY_RAM, BootKey));
    #endif /* !__GHOS__ */

    Status = SYST_COMPLETE;
  }

  return Status;
}
#endif /* !__BOOT_LOADER_LINK__ */


#ifdef Syst_VOID_ISR_SERVICE
/*----------------------------------------------------------------------------*/
/*Name : SYST_VoidInterruptHandler_it                                         */
/*Role : create an empty interrupt handler                                    */
/*Interface : -                                                               */
/*Pre-condition : -                                                           */
/*Constraints :  -                                                            */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [no operation]                                                          */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
ISR(SYST_VoidInterruptHandler_it)
{
  #ifdef SYST_EVENT_SPY
  SPYS_IncEvtSpy(SPYS_EVT_SPY_VOID_IT);
  #endif/* SYST_EVENT_SPY*/

  __NOP__;
}
#endif  /* Syst_VOID_ISR_SERVICE */


#ifdef Syst_UNHANDLED_ISR_SERVICE
/*----------------------------------------------------------------------------*/
/*Name : SYST_UnhandledException_it                                           */
/*Role : Endless-loop is called when unused interrupt vector is fetched       */
/*Interface : -                                                               */
/*Pre-condition : -                                                           */
/*Constraints :  -                                                            */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [endless-loop]                                                          */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
ISR(SYST_UnhandledException_it)
{
  #ifdef SYST_EVENT_SPY
  SPYS_IncEvtSpy(SPYS_EVT_SPY_UNHANDLED_IT);
  #endif/* SYST_EVENT_SPY*/

  /* wait forever for watchdog reset */
  SYST_Reset();
}
#endif /* Syst_UNHANDLED_ISR_SERVICE */


#ifdef Syst_WAIT_SERVICE
/*----------------------------------------------------------------------------*/
/*Name : SYST_WaitLoop                                                        */
/*Role : System polling timing                                                */
/*Interface :                                                                 */
/*   delay (ushort) INPUT, number of loop to reach requested timing           */
/*Pre-condition : none                                                        */
/*Constraints :                                                               */
/*   - This function is able to lengthen if interrupts function appear.       */
/*     Protect it against ISR if necessary.                                   */
/*   - time is different for each processor (different machine cycle)         */
/*   - timing is independent of compiler options or optimizer configuration   */
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*  For NEC V850 Fx3/Dx3 (core V850ES, V850E1)                                */
/*  duration in CPU cycles :                                                  */
/*   total cpu cycle = 13 + (5 * delay cpu cycle)                             */
/*  duration in second :                                                      */
/*   time  (ushort) = (13 * cycle time) + (5 * delay cpu cycle * cycle time)  */
/*                                                                            */
/* For GHS compiler v5.1.7d:                                                  */
/*                                                                            */
/*  At 240 kHz, cycle time = 4167ns                                           */
/*   time  (ushort) = 54.167 us + (delay * 20.833 us)                         */
/*                                                                            */
/*   time max  (delay = 65535) =>    1365366.7 us                             */
/*   time mini (delay = 0)     =>    54167 ns                                 */
/*                                                                            */
/*  At 4 MHz, cycle time = 250ns                                              */
/*   time  (ushort) = 3.25 us + (delay * 1.25 us)                             */
/*                                                                            */
/*   time max  (delay = 65535) =>    81922 us                                 */
/*   time mini (delay = 0)     =>    3250 ns                                  */
/*                                                                            */
/*  At 16 MHz, cycle time = 62.5ns                                            */
/*   time  (ushort) = 0.8125 us + (delay * 0.3125 us)                         */
/*                                                                            */
/*   time max  (delay = 65535) =>    20480.5 us                               */
/*   time mini (delay = 0)     =>    812.5 ns                                 */
/*                                                                            */
/*  At 20 MHz, cycle time = 50 ns                                             */
/*   time  (ushort) = 0.650 us + (delay * 0.25 us)                            */
/*                                                                            */
/*   time max  (delay = 65535) =>    16384.4 us                               */
/*   time mini (delay = 0)     =>    650 ns                                   */
/*                                                                            */
/*  At 32 MHz, cycle time = 31.25 ns                                          */
/*   time  (ushort) = 0.40625 us + (delay * 0.15625 us)                       */
/*                                                                            */
/*   time max  (delay = 65535) =>    10240.25 us                              */
/*   time mini (delay = 0)     =>    406.25 ns                                */
/*                                                                            */
/*  At 40 MHz, cycle time = 25 ns                                             */
/*   time  (ushort) = 0.325 us + (delay * 0.125 us)                           */
/*                                                                            */
/*   time max  (delay = 65535) =>    8192.200 us                              */
/*   time mini (delay = 0)     =>       0.325 us                              */
/*                                                                            */
/*  At 48 MHz, cycle time = 20.83 ns                                          */
/*   time  (ushort) = 0.27083 us + (delay * 0.10417 us)                       */
/*                                                                            */
/*   time max  (delay = 65535) =>    6826.58 us                               */
/*   time mini (delay = 0)     =>    270.83 ns                                */
/*                                                                            */
/* call :                                                                     */
/*    mov   12,r6          ;  2 cycles                                        */
/*    jarl  _SYST_Wait,lp  ;  3 cycles ; = 5 cycles                           */
/*                                                                            */
/* Function body :                                                            */
/* _SYST_Wait:                                                                */
/*    zxh   r6             ;  1 cycle                                         */
/*    mov   0,r2           ;  1 cycle ; = 2 cycles                            */
/* .L343:                                                                     */
/*    cmp   r6,r2          ;  1 cycle                                         */
/*    bnl   .L341          ;  1 (no branch), 2 (branch)                       */
/*    add   1,r2           ;  1 cycle                                         */
/*    zxh   r2             ;  1 cycle                                         */
/*    br    .L343          ;  1 cycle  ; = 5 cycles                           */
/* .L341:                                                                     */
/*    jmp   [lp]           ;  3 cycles                                        */
/*                                                                            */
/*               --------------------------------------------------           */
/*                                                                            */
/*  For NEC V850 DX4 (core V850E2V3)                                          */
/*  duration in CPU cycles :                                                  */
/*   total cpu cycle = 16 + (5 * delay cpu cycle)                             */
/*  duration in second :                                                      */
/*   time  (ushort) = (16 * cycle time) + (8 * delay cpu cycle * cycle time)  */
/*                                                                            */
/*  At 40 MHz, cycle time = 25 ns                                             */
/*   time  (ushort) = 0.4 us + (delay * 0.200 us)                             */
/*                                                                            */
/* call :                                                                     */
/*    movea 12,r6          ;  1 cycle                                         */
/*    jarl  _SYST_Wait,lp  ;  4 cycles ; = 5 cycles                           */
/*                                                                            */
/* Function body :                                                            */
/* _SYST_Wait:                                                                */
/*    zxh   r6             ;  1 cycle                                         */
/*    mov   0,r2           ;  1 cycle ; = 2 cycles                            */
/* .L343:                                                                     */
/*    cmp   r6,r2          ;  1 cycle                                         */
/*    bnl   .L341          ;  1 (no branch), 4 (branch)                       */
/*    add   1,r2           ;  1 cycle                                         */
/*    zxh   r2             ;  1 cycle                                         */
/*    br    .L343          ;  4 cycles  ; = 8 cycles                          */
/* .L341:                                                                     */
/*    jmp   [lp]           ;  4 cycles                                        */
/*----------------------------------------------------------------------------*/
/*  For Freescale HCS12, HCS12H and HCS12HZ                                   */
/*  duration in CPU cycles :                                                  */
/*   total cpu cycle = 32 + (8 * delay cpu cycle)                             */
/*   delay cpu cycle =  (total cpu cycle - 32) / 8                            */
/*  duration in second :                                                      */
/*   time  (ushort) = (32 * cycle time) + (8 * delay cpu cycle * cycle time)  */
/*                                                                            */
/* For Cosmic compiler v4.7.8 :                                               */
/*                                                                            */
/*  At 16 MHz, cycle time = 62.5 ns                                           */
/*   time  (ushort) = 2.000 us + (delay * 0.5 us)                             */
/*                                                                            */
/*   time max  (delay = 65535) =>    32 769 .5 us                             */
/*   time mini (delay = 0)     =>            2 us                             */
/*                                                                            */
/*; call                                                                      */
/*       ldd   #1              2 cycle                                        */
/*       call  f_SYST_Wait     7 cycle                                        */
/*                                                                            */
/*f_SYST_Wait:                                                                */
/*       pshd           ; delay parameter   (sp)     2 cycle                  */
/*       pshd           ; stack reservation (sp-2)   2 cycle                  */
/*       ldy  #0        ; 0 is stored in y           2 cycle                  */
/*       sty  OFST-2,s  ; 0 is stored in (sp-2)      2 cycle                  */
/*L52:                                                                        */
/*       cpy  OFST+0,s  ; compare y with delay (sp)  3 cycle                  */
/*       bhs  LC001     ; branch if >=               1 (no branch), 3 (branch)*/
/*       iny            ; increment y                1 cycle                  */
/*       bra  L52       ; goto                       3 cycle                  */
/*LC001:                                                                      */
/*       leas 4,s       ; restore stack              2 cycle                  */
/*       rtc                                         7 cycle                  */
/*----------------------------------------------------------------------------*/
/*  For Freescale HCS12XHZ                                                    */
/*  duration in CPU cycles :                                                  */
/*   total cpu cycle = 32 + (14 * delay cpu cycle)                            */
/*  duration in second :                                                      */
/*   time  (ushort) = (32 * cycle time) + (14 * delay cpu cycle * cycle time) */
/*                                                                            */
/* For Cosmic compiler v4.7.8 :                                               */
/*                                                                            */
/*  At 32 MHz, cycle time = 31.25 ns                                          */
/*   time  (ushort) = 1 us + (delay * 0.4375 us)                              */
/*                                                                            */
/*   time max  (delay = 65535) =>    28673.562 us                             */
/*   time mini (delay = 0)     =>     1 us                                    */
/*                                                                            */
/* call :                                                                     */
/*       ldd  #36         ; 2 cycles                                          */
/*       call f_SYST_Wait ; 7 cycles                                          */
/*                                                                            */
/* Function body :                                                            */
/*f_SYST_Wait:                                                                */
/*       pshd           ; 2 cycles                                            */
/*       pshd           ; 2 cycles                                            */
/*       clra           ; 1 cycles                                            */
/*       clrb           ; 1 cycles                                            */
/*       std  OFST-2,s  ; 2 cycles                                            */
/*L53:                                                                        */
/*       cpd  OFST+0,s  ; 3 cycles                                            */
/*       bhs  L55       ; 1 (no branch), 3 (branch)                           */
/*       incw OFST-2,s  ; 4 cycles                                            */
/*       ldd  OFST-2,s  ; 3 cycles                                            */
/*       bra  L53       ; 3 cycles                                            */
/*L55:                                                                        */
/*       leas 4,s       ; 2 cycles                                            */
/*       rtc            ; 7 cycles                                            */
/*----------------------------------------------------------------------------*/
/*  For Freescale S08AW60                                                     */
/*  duration in CPU cycles :                                                  */
/*   total cpu cycle = 47 + (24 * delay cpu cycle)                            */
/*  duration in second :                                                      */
/*   time  (ushort) = (47 * cycle time) + (24 * delay cpu cycle * cycle time) */
/*                                                                            */
/* For Cosmic compiler v4.510  :                                              */
/*                                                                            */
/*  At 8388608 Hz, cycle time = 119.209 ns                                    */
/*   time  (ushort) = 5.602us + (delay * 2.861us)                             */
/*                                                                            */
/*   time max  (delay = 65535) =>   187502.286 us                             */
/*   time mini (delay = 0)     =>        5.602 us                             */
/*                                                                            */
/* call :                                                                     */
/*    clrx                 ;  1 cycle                                         */
/*    lda      #1          ;  2 cycles                                        */
/*    jsr      _SYST_Wait  ;  5 cycles  ; = 8 cycles                          */
/*                                                                            */
/* Function body :                                                            */
/* _SYST_Wait:                                                                */
/*    psha                 ;  2 cycles                                        */
/*    pshx                 ;  2 cycles                                        */
/*    ais      #-2         ;  2 cycles                                        */
/*    tsx                  ;  2 cycles                                        */
/*    clr      0,x         ;  4 cycles                                        */
/*    clr      1,x         ;  5 cycles                                        */
/*    ldhx     0,x         ;  5 cycles                                        */
/*                         ;  Sub total Loop Init = 22 cycles                 */
/* L13:                                                                       */
/*    cphx     3,sp        ;  6 cycles                                        */
/*    bhs      L74         ;  3 cycles  ; = 9 cycles                          */
/*    ldhx     1,sp        ;  5 cycles                                        */
/*    aix      #1          ;  2 cycles                                        */
/*    sthx     1,sp        ;  5 cycles                                        */
/*    bra      L13         ;  3 cycles  ; = 15 cycles                         */
/*                                                                            */
/* L74:                                                                       */
/*    ais      #4          ;  2 cycles                                        */
/*    rts                  ;  6 cycles                                        */
/*                         ;  Sub total post loop = 8 cycles                  */
/*----------------------------------------------------------------------------*/
/*  For  Toshiba TX49                                                         */
/*  duration in CPU cycles :                                                  */
/*   total cpu cycle = 106 + (4 * delay cpu cycle)                            */
/*  duration in second :                                                      */
/*   time  (ushort) = (106 * cycle time) + (4 * delay cpu cycle * cycle time) */
/*                                                                            */
/* For ghs compiler v4.23 :                                                   */
/*                                                                            */
/*  At 120 MHz, cycle time = 8.3 ns                                           */
/*   time  (ushort) = 887.0296ns + (delay * 33.4728ns)                        */
/*                                                                            */
/*   time max  (delay = 65535) =>    2 194 527 ns                             */
/*   time mini (delay = 0)     =>    887ns                                    */
/*                                                                            */
/* call :                                                                     */
/*                                                                            */
/* Function body :                                                            */
/*                                                                            */
/*----------------------------------------------------------------------------*/
/* For Freescale IMX53                                                        */
/*  duration in CPU cycles (no dual pipeline used) :                          */
/*   total cpu cycle = 8 + (3 * nb loops)                                     */
/*  At 800 MHz, cycle time = 1.25 ns                                          */
/*                total time = (8 * 1.25) + ((3 * 1.25) * nb loops)           */
/*                 in ns     =        10  + (     3.75  * nb loops)           */
/*  Example of computation :                                                  */
/*   wait time =  250 ns -> nb loops = ( 250 - 10) / 3.75 = 64                */
/*   wait time = 5000 ns -> nb loops = (5000 - 10) / 3.75 = 1330.67 -> 1331   */
/*----------------------------------------------------------------------------*/
/* For REL_RL78                                                               */
/*  duration in CPU cycles:                                                   */
/*   total cpu cycle = 16 + (6 * nb loops)                                    */
/*  At 8 MHz, cycle time = 125 ns                                             */
/*                total time = (16 * 125) + ((6 * 125) * nb loops)            */
/*                 in ns     =     2000  + (    750  * nb loops)              */
/*                                                                            */
/*   time max  (delay = 65535) =>    49 153 250 ns                            */
/*   time mini (delay = 0)     =>    2000 ns                                  */
/*                                                                            */
/*                                                                            */
/*  At 20 MHz, cycle time = 50 ns                                             */
/*                total time = (16 * 50) + ((6 * 50) * nb loops)              */
/*                 in ns     =      800  + (    300  * nb loops)              */
/*                                                                            */
/*   time max  (delay = 65535) =>    19 661 300 ns                            */
/*   time mini (delay = 0)     =>    300 ns                                   */
/*----------------------------------------------------------------------------*/
/*Behaviour :                                                                 */
/*DO                                                                          */
/*  [Wait the specified delay]                                                */
/*OD                                                                          */
/*----------------------------------------------------------------------------*/
#ifndef __PC_SIMULATION__
void SYST_WaitLoop(ushort Syst_delay)
{
  register ushort i = 0;

  #ifdef __POLYSPACE__
  USE_1_GOTO(Syst_label);
  #endif /* __POLYSPACE__ */


Syst_label:
  if (i < Syst_delay)
  {
    i++;

    #ifdef __POLYSPACE__
    GOTO(Syst_label);
    #else
    goto Syst_label;
    #endif /* __POLYSPACE__ */
  }

  #ifdef __POLYSPACE__
  EXIT_1_GOTO(Syst_label);
  #endif /* __POLYSPACE__ */
}
#endif /* !__PC_SIMULATION__ */
#endif /* Syst_WAIT_SERVICE */


/*----------------------------------------------------------------------------*/
/* Name           : SYST_GetPowerOnFlag                                       */
/* Role           :                                                           */
/* Interface      :                                                           */
/* Returns:       : none                                                      */
/* Pre-condition  :                                                           */
/* Constraints    :                                                           */
/*----------------------------------------------------------------------------*/
int SYST_GetPowerOnFlag(void )
{
  return  SYST_PowerOnFlag;
}
#ifdef Syst_ROM_CHECKSUM_SERVICE
/*----------------------------------------------------------------------------*/
/*Name : SYST_RomChecksum                                                     */
/*Role : Make a FLASH/ROM memory checksum byte per byte into an ushort format */
/*Interface :                                                                 */
/*   StartAdd (ulong) INPUT  The Start address to sum up according to s19 file*/
/*                           This address is included                         */
/*   EndAdd   (ulong) INPUT  The End address to sum up according to s19 file  */
/*                           This address is ALSO included                    */
/*           (ushort) OUTPUT The checksum value                               */
/*Pre-condition :                                                             */
/*   The FLASH/ROM memory init should be done                                 */
/*   The memory have to be in readable state                                  */
/*Constraints :                                                               */
/*   The time execution could be long, depending of the area size to make the */
/*   checksum. For example :                                                  */
/*   - Star12 micro:         108 msec for 16 kbytes   (16Mhz bus Clock)       */
/*   - SPI Ext Flash / S12X: 8.2 msec for 4 Kbytes (32MHz bus clock/SPI 16MHz)*/
/*                                                                            */
/*   FOR START12 MICRO, THIS ROUTINE HAVE TO BE PUT INTO A NON-BANKED PAGE    */
/*   By default,to save place in not-banked page, __FAR__ routines of         */
/*   NON-BANKED page are placed in a banked page                              */
/*   Add __NEAR__ on this routine to force map in the NON-banked page         */
/*                                                                            */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [Over run the checksum value according to the zone ]                    */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
__NON_BANKED__ ushort SYST_RomChecksum(SYST_AddressWidth_t StartLinearAddr,
                                       SYST_AddressWidth_t   EndLinearAddr)
{
  ushort  Checksum;

  #if defined(__TX49__)      || \
      defined(__MC9S08xx__)  || \
      defined(__RH850__)     || \
      defined(__NEC_V850__)  || \
      defined(__REL_RL78__)
  SYST_AddressWidth_t   Address;
  #endif /* defined(__TX49__)     ||
            defined(__MC9S08xx__) ||
            defined(__RH850__)     || \
            defined(__NEC_V850__) ||
            defined(__REL_RL78__) */

  #if defined(__MC9S12xx__)
  ubyte   SaveCurrentPPage;

  #if defined(__MC9S12XHZ__)
  ushort  FirstPage;
  ushort  LastPage;
  ushort  PageIndex;  /* ushort to support Page number = 0xFF */
  #else
  ubyte   FirstPage;
  ubyte   LastPage;
  ubyte   PageIndex;
  #endif /* defined(__MC9S12XHZ__) */

  ushort  StartBankedAddr;
  ushort  EndBankedAddr;
  ushort  Address;
  #endif /* defined(__MC9S12xx__) */


  Checksum = 0;

  #ifdef Syst_READ_EXTERNAL_SPI_FLASH_SERVICE
  if ( (StartLinearAddr >= ((SYST_AddressWidth_t*)&(SYST_FlashBlockAddress[0]))[(Syst_EXT_FLASH_APPLI_BLOCK*2)+SYST_FLASH_INDEX_OF_START])
    && (StartLinearAddr <= ((SYST_AddressWidth_t*)&(SYST_FlashBlockAddress[0]))[(Syst_EXT_FLASH_APPLI_BLOCK*2)+SYST_FLASH_INDEX_OF_END]) )
  {
    /* External FLASH/ROM */
    Checksum = SYST_ExternalFlashChecksum(StartLinearAddr, EndLinearAddr);
  }
  else
  #endif /* Syst_READ_EXTERNAL_SPI_FLASH_SERVICE */
  {
    /* Internal FLASH/ROM */
    #if defined(__TX49__)      || \
        defined(__MC9S08xx__)  || \
        defined(__RH850__)     || \
        defined(__NEC_V850__)  || \
        defined(__REL_RL78__)

    {
      /* these block was formely a for(;;;) loop, but changed by do-while */
      /* to avoid out of range error when end-address is equal            */
      /* to max range value of SYST_AddressWidth_t (i.e. S08 micro )      */

      bool_t LoopExit = FALSE;

      Address = StartLinearAddr;
      do
      {
        #if defined(C_COMP_IAR_RL78)
        /* if without  __far, the pointer will point to the address 0xFFFFF~0xF0000,*/
        /* when data and code model set to near,but the rom start address is 0x0000 */
        Checksum += (ushort)( *((ubyte __FAR__ *)Address) );
        #else
        Checksum += (ushort)( *((ubyte *)Address) );
        #endif

        if (Address < EndLinearAddr)
        {
          Address++;
        }
        else
        {
          LoopExit = TRUE;
        }
      } while ( LoopExit == FALSE);
    }

    #endif /* defined(__TX49__)      || \
              defined(__MC9S08xx__)  || \
              defined(__RH850__)     || \
              defined(__NEC_V850__)  ||
              defined(__REL_RL78__) */

    #ifdef __MC9S12xx__
    /* --- paged processor --- */

    /* save current page number */
    SaveCurrentPPage = TARG_ReadByte(PPAGE);

    /* set pages to access */
    FirstPage = (ubyte)(StartLinearAddr / SYST_FLASH_PAGE_SIZE);
    LastPage  = (ubyte)(  EndLinearAddr / SYST_FLASH_PAGE_SIZE);

    StartBankedAddr = (ushort)((StartLinearAddr % SYST_FLASH_PAGE_SIZE)
                               + SYST_FLASH_BANK_OFFSET);

    /* access requested pages */
    for (PageIndex = FirstPage; PageIndex <= LastPage; PageIndex++)
    {
      /* set page number */
      TARG_WriteByte(PPAGE, (ubyte)PageIndex);

      /* set banked end address */
      if (PageIndex != LastPage)
      {
        EndBankedAddr = SYST_FLASH_PAGE_SIZE + SYST_FLASH_BANK_OFFSET - 1;
      }
      else
      {
        EndBankedAddr = (ushort)((EndLinearAddr % SYST_FLASH_PAGE_SIZE)
                                 + SYST_FLASH_BANK_OFFSET);
      }

      /* compute checksum */
      for (Address = StartBankedAddr; Address <= EndBankedAddr; Address++)
      {
        Checksum += (ushort)(*((ubyte *)Address));
      }

      /* new start address for next banked page */
      StartBankedAddr = SYST_FLASH_BANK_OFFSET;
    }

    /* restore page number */
    TARG_WriteByte(PPAGE, SaveCurrentPPage);
    #endif /* __MC9S12xx__ */
  }

  return (Checksum);
}
#endif /* Syst_ROM_CHECKSUM_SERVICE */

#ifdef Syst_RAM_CHECKSUM_SERVICE
/*----------------------------------------------------------------------------*/
/*Name : SYST_RamChecksum                                                     */
/*Role : Make a RAM memory checksum byte per byte into an ushort format       */
/*Interface :                                                                 */
/*   StartLinearAddr (ulong) INPUT  The Start address to sum up               */
/*                           This address is included                         */
/*   EndLinearAddr   (ulong) INPUT  The End address to sum up                 */
/*                           This address is ALSO included                    */
/*           (ushort) OUTPUT The checksum value                               */
/*Pre-condition :                                                             */
/*Constraints :                                                               */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [Over run the checksum value according to the zone ]                    */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
ushort SYST_RamChecksum(SYST_AddressWidth_t StartLinearAddr,
                        SYST_AddressWidth_t EndLinearAddr)
{
  ushort  Checksum;
  SYST_AddressWidth_t   Address;

  /* Initialization */
  Checksum = 0;

  for (Address = StartLinearAddr ; Address <= EndLinearAddr; Address++)
  {
    #ifndef __POLYSPACE__
    #if defined(C_COMP_IAR_RL78)
    Checksum += *((ubyte __FAR__ *)Address);
    #else
    Checksum += *((__GCONST__ ubyte *)Address);
    #endif
    #else
    /* Discard this code for Polyspace to avoid justifyng following Orange warnings: */
    /* IDP.6�Warning : pointer may be outside its bounds                             */
    /* NIV.7�Warning : variable may be non-initialized (type: unsigned int 8)        */
    #endif /* __POLYSPACE__ */
  }

  return (Checksum);
}
#endif /* Syst_RAM_CHECKSUM_SERVICE */


#ifdef Syst_READ_ROM_SERVICE
/*----------------------------------------------------------------------------*/
/*Name : SYST_ReadRom                                                         */
/*Role : Copy Rom in a buffer                                                 */
/*Interface :                                                                 */
/*   StartAdd         INPUT  The Start address to read according to s19 file  */
/*                           This address is included                         */
/*   EndAdd           INPUT  The End address to read according to s19 file    */
/*                           This address is ALSO included                    */
/*   ReadTable(ubyte*)INPUT  return buffer address                            */
/*Pre-condition :                                                             */
/*   The FLASH/ROM memory init should be done                                 */
/*   The memory have to be in readable state                                  */
/*Constraints :                                                               */
/*   The time execution could be long, depending of the area size             */
/*    For example :                                                           */
/*      - Star12 micro, 1.7 msec for 255 bytes   (16Mhz bus Clock)            */
/*                                                                            */
/*   FOR START12 MICRO, THIS ROUTINE HAVE TO BE PUT INTO A NON-BANKED PAGE    */
/*   By default,to save place in not-banked page, __FAR__ routines of         */
/*   NON-BANKED page are placed in a banked page                              */
/*   Add __NEAR__ on this routine to force map in the NON-banked page         */
/*                                                                            */
/*   FOR START12 MICRO, only use this service for small area                  */
/*                                                                            */
/*   When read in external FLASH/ROM, DON'T read more than 65535 bytes        */
/*                                                                            */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [copy Rom byte in buffer ]                                              */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
__NON_BANKED__ void SYST_ReadRom(SYST_AddressWidth_t StartLinearAddr,
                                 SYST_AddressWidth_t EndLinearAddr,
                                 __GCONST__ ubyte*   ReadTable)
{
  #if defined(__TX49__) || defined(__MC9S08xx__) || defined(__NEC_V850__) || defined(__RH850__) || defined(__REL_RL78__) || defined(__MC9S12xx__)
  SYST_AddressWidth_t   Address;
  #endif /* defined(__TX49__) || defined(__MC9S08xx__) || defined(__NEC_V850__) || defined(__RH850__) || defined(__REL_RL78__) || defined(__MC9S12xx__) */

  #if defined(__MC9S12xx__)
  ushort  BankedAddr;
  ubyte   SaveCurrentPPage;
  #endif /* defined(__MC9S12xx__) */


  #ifdef Syst_READ_EXTERNAL_SPI_FLASH_SERVICE
  if ((StartLinearAddr >= ((SYST_AddressWidth_t*)&(SYST_FlashBlockAddress[0]))[(Syst_EXT_FLASH_APPLI_BLOCK*2)+SYST_FLASH_INDEX_OF_START])
      &&(StartLinearAddr <= ((SYST_AddressWidth_t*)&(SYST_FlashBlockAddress[0]))[(Syst_EXT_FLASH_APPLI_BLOCK*2)+SYST_FLASH_INDEX_OF_END]))
  {
    /* External FLASH/ROM, must be less than 65535 bytes */
    SYST_ReadExternalFlash(StartLinearAddr, ReadTable, (ushort)((EndLinearAddr-StartLinearAddr)+1));
  }
  else
  #endif /* Syst_READ_EXTERNAL_SPI_FLASH_SERVICE */
  {
    #if defined(__TX49__) || defined(__MC9S08xx__) || defined(__NEC_V850__) || defined(__RH850__) || defined(__REL_RL78__)
      /* for (Address = StartLinearAddr; Address <= EndLinearAddr; Address++)
         {
           *ReadTable = *((ubyte *)Address);
           ReadTable++;
         }                                                                */
      /* these block was formely a for(;;;) loop, but changed by do-while */
      /* to avoid out of range error when end-address is equal            */
      /* to max range value of SYST_AddressWidth_t (i.e. S08 micro )      */
    {
      bool_t LoopExit = FALSE;

      Address = StartLinearAddr;
      do
      {
        #if defined(C_COMP_IAR_RL78)
        /* if without  __far, the pointer will point to the address 0xFFFFF~0xF0000,*/
        /* when data and code model set to near,but the rom start address is 0x0000 */
        *ReadTable = *((ubyte __FAR__ *)Address);
        #else
        *ReadTable = *((ubyte *)Address);
        #endif

        if (Address < EndLinearAddr)
        {
          ReadTable++;
          Address++;
        }
        else
        {
          LoopExit = TRUE;
        }
      } while ( LoopExit == FALSE);
    }

    #endif /* defined(__TX49__) || defined(__MC9S08xx__) || defined(__NEC_V850__) || defined(__RH850__) || defined(__REL_RL78__)*/

    #ifdef __MC9S12xx__
    /* --- paged processor --- */

    /* save current page number */
    SaveCurrentPPage = TARG_ReadByte(PPAGE);

    for (Address = StartLinearAddr; Address <= EndLinearAddr; Address++)
    {
      /* set page number */
      TARG_WriteByte(PPAGE, (ubyte)(Address / SYST_FLASH_PAGE_SIZE) );
      /* address in page */
      BankedAddr = (ushort)( (Address % SYST_FLASH_PAGE_SIZE) + SYST_FLASH_BANK_OFFSET );
      /* get data */
      *ReadTable = *( (ubyte *)(BankedAddr));
      ReadTable++;
    }

    /* restore page number */
    TARG_WriteByte(PPAGE, SaveCurrentPPage);
    #endif /* __MC9S12xx__ */
  }
}
#endif /* Syst_READ_ROM_SERVICE */


#ifdef Syst_READ_RAM_SERVICE
/*----------------------------------------------------------------------------*/
/*Name : SYST_ReadRam                                                         */
/*Role : Copy Ram in a buffer                                                 */
/*Interface :                                                                 */
/*   StartAdd        INPUT  The Start address to read                         */
/*                          For GHOS, the address is relative to start of RAM */
/*                          This address is included                          */
/*   EndAdd          INPUT  The End address to read                           */
/*                          For GHOS, the address is relative to start of RAM */
/*                          This address is ALSO included                     */
/*   ReadTable       INPUT  return buffer address                             */
/*Pre-condition : -                                                           */
/*Constraints : -                                                             */
/*----------------------------------------------------------------------------*/
__NEAR_FUNC__ void SYST_ReadRam(SYST_AddressWidth_t StartLinearAddr,
                                SYST_AddressWidth_t EndLinearAddr,
                                __GCONST__ ubyte*   ReadTable)
{
  SYST_AddressWidth_t Address;

  #ifndef __GHOS__

  /* Databyte is an intermediate variable to work around a Cosmic S12x compiler */
  /* bug. When an assignment such as "*x = *y" is compile, with x and y         */
  /* both declared as "__GCONST__ ubyte *", *y is read with the GPAGE of *x.    */
  ubyte DataByte;

  for (Address = StartLinearAddr; Address <= EndLinearAddr; Address++)
  {
    #if defined(C_COMP_IAR_RL78)
    DataByte    = *((ubyte __FAR__ *)Address);
    #else
    DataByte    = *((__GCONST__ ubyte *)Address);
    #endif
    *ReadTable  = DataByte;
    ReadTable++;
  }

  #else  /* __GHOS__ */

  ulong RamData;

  for (Address = StartLinearAddr; Address <= EndLinearAddr; Address++)
  {
    CheckSuccess(WriteIODeviceRegister(SYST_IODevice, Syst_SET_RAM_ADDRESS, Address));
    CheckSuccess(ReadIODeviceRegister(SYST_IODevice, Syst_READ_RAM, &RamData));
    *ReadTable = (ubyte)RamData;
    ReadTable++;
  }

  #endif /* !__GHOS__ */
}
#endif /* Syst_READ_RAM_SERVICE */


#ifdef __GHOS__
/*----------------------------------------------------------------------------*/
/*Name : SYST_WriteRam                                                        */
/*Role : Copy Buffer in Ram                                                   */
/*Interface :                                                                 */
/*   StartLinearAddr  INPUT  The Start address to write                       */
/*                           The address is relative to start of RAM          */
/*                           This address is included                         */
/*   EndLinearAddr    INPUT  The End address to write                         */
/*                           The address is relative to start of RAM          */
/*                           This address is ALSO included                    */
/*   WriteTable       INPUT  Data to write buffer address                     */
/*Pre-condition : -                                                           */
/*Constraints : -                                                             */
/*----------------------------------------------------------------------------*/
void SYST_WriteRam(SYST_AddressWidth_t StartLinearAddr,
                   SYST_AddressWidth_t EndLinearAddr,
                   ubyte*              WriteTable)
{
  SYST_AddressWidth_t Address;

  for (Address = StartLinearAddr; Address <= EndLinearAddr; Address++)
  {
    CheckSuccess(WriteIODeviceRegister(SYST_IODevice, Syst_SET_RAM_ADDRESS, Address));
    CheckSuccess(WriteIODeviceRegister(SYST_IODevice, Syst_WRITE_RAM, (Value)(*WriteTable)));
    WriteTable++;
  }
}
#endif /* __GHOS__ */


#ifdef Syst_READ_EXTERNAL_SPI_FLASH_SERVICE

#define Syst_EXT_FLASH_OPCODE_READ    0x03

/*----------------------------------------------------------------------------*/
/* Name: SYST_ReadExternalFlash                                               */
/* Role: Read data from external Flash                                        */
/* Interface: FlashAddr      IN   Address of data in Flash                    */
/*            Buffer         IN   Destination buffer                          */
/*            DataSize       IN   Size of data to read                        */
/* Pre-condition: none                                                        */
/* Constraints:   none                                                        */
/* Behavior:                                                                  */
/*   DO                                                                       */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/
void SYST_ReadExternalFlash(SYST_AddressWidth_t  FlashAddr,
                            __GCONST__ ubyte*    Buffer,
                            ushort               DataSize)
{
#ifndef __PC_SIMULATION__
  ubyte ByteToTransmit;

  /* Send READ command and 24 bits address */
  IODC_SetOutputData(CS_EXT_FLASH, IODC_ACTIVE);
  SPIC_TransmitOneByte(SPIC_EXT_FLASH_CH, Syst_EXT_FLASH_OPCODE_READ);
  ByteToTransmit = (ubyte)(FlashAddr >> 16);
  SPIC_TransmitOneByte(SPIC_EXT_FLASH_CH, ByteToTransmit);
  ByteToTransmit = (ubyte)(FlashAddr >> 8);
  SPIC_TransmitOneByte(SPIC_EXT_FLASH_CH, ByteToTransmit);
  ByteToTransmit = (ubyte)FlashAddr;
  SPIC_TransmitOneByte(SPIC_EXT_FLASH_CH, ByteToTransmit);

  /* Read data from Flash */
  while (DataSize > 0)
  {
    /* Read one byte from flash */
    SPIC_ReceiveOneByte(SPIC_EXT_FLASH_CH, Buffer);

    Buffer++;
    DataSize--;
  }

  IODC_SetOutputData(CS_EXT_FLASH, IODC_INACTIVE);

#else

  ubyte* Ptr;

  Ptr  = (ubyte*) FlashAddr;

  /* Read data from Flash */
  while (DataSize > 0)
  {
    /* Simulate read one byte from flash */
    *Buffer = *Ptr;

    Ptr++;
    Buffer++;

    DataSize--;
  }
#endif  /* __PC_SIMULATION__ */
}

#ifdef Syst_READ_EXTERNAL_SPI_FLASH_UNTIL_BYTE_SERVICE
/*----------------------------------------------------------------------------*/
/* Name: SYST_ReadExternalFlashUntilByte                                      */
/* Role: Read data from external Flash until byte value found                 */
/* Interface: FlashAddr      IN   Address of data in Flash                    */
/*            Buffer         IN   Destination buffer                          */
/*            DataValue      IN   Value of data to found                      */
/*            Size          OUT   Number of data read from flash              */
/* Pre-condition: none                                                        */
/* Constraints:   none                                                        */
/* Behavior:                                                                  */
/*   DO                                                                       */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/
ushort SYST_ReadExternalFlashUntilByte(SYST_AddressWidth_t  FlashAddr,
                                       __GCONST__ ubyte*    Buffer,
                                       ubyte                DataValue)
{
  #define Syst_EXT_FLASH_OPCODE_READ    0x03
  ushort Size;
  ubyte ByteToTransmit;

  /* Send READ command and 24 bits address */
  IODC_SetOutputData(CS_EXT_FLASH, IODC_ACTIVE);
  SPIC_TransmitOneByte(SPIC_EXT_FLASH_CH, Syst_EXT_FLASH_OPCODE_READ);
  ByteToTransmit = (ubyte)(FlashAddr >> 16);
  SPIC_TransmitOneByte(SPIC_EXT_FLASH_CH, ByteToTransmit);
  ByteToTransmit = (ubyte)(FlashAddr >> 8);
  SPIC_TransmitOneByte(SPIC_EXT_FLASH_CH, ByteToTransmit);
  ByteToTransmit = (ubyte)FlashAddr;
  SPIC_TransmitOneByte(SPIC_EXT_FLASH_CH, ByteToTransmit);

  /* Read data from Flash */
  Size = 0;
  do
  {
    /* Read one ubyte from flash */
    SPIC_ReceiveOneByte(SPIC_EXT_FLASH_CH, Buffer);
    Buffer++;
    Size++;
  } while (*(Buffer - 1) != DataValue);

  IODC_SetOutputData(CS_EXT_FLASH, IODC_INACTIVE);

  return (Size);
}
#endif /* Syst_READ_EXTERNAL_SPI_FLASH_UNTIL_BYTE_SERVICE */

#ifdef Syst_READ_EXTERNAL_SPI_FLASH_UNTIL_SHORT_SERVICE
/*----------------------------------------------------------------------------*/
/* Name: SYST_ReadExternalFlashUntilShort                                     */
/* Role: Read data from external Flash until short value found                */
/* Interface: FlashAddr      IN   Address of data in Flash                    */
/*            Buffer         IN   Destination buffer                          */
/*            DataValue      IN   Value of data to found                      */
/*            Size          OUT   Number of data read from flash              */
/* Pre-condition: none                                                        */
/* Constraints:   none                                                        */
/* Behavior:                                                                  */
/*   DO                                                                       */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/
ushort SYST_ReadExternalFlashUntilShort(SYST_AddressWidth_t  FlashAddr,
                                        __GCONST__ ushort*   Buffer,
                                        ushort               DataValue)
{
#ifndef __PC_SIMULATION__
  #define Syst_EXT_FLASH_OPCODE_READ    0x03
  bitfield_short_t Data;
  ushort Size;
  ubyte ByteToTransmit;

  /* Send READ command and 24 bits address */
  IODC_SetOutputData(CS_EXT_FLASH, IODC_ACTIVE);
  SPIC_TransmitOneByte(SPIC_EXT_FLASH_CH, Syst_EXT_FLASH_OPCODE_READ);
  ByteToTransmit = (ubyte)(FlashAddr >> 16);
  SPIC_TransmitOneByte(SPIC_EXT_FLASH_CH, ByteToTransmit);
  ByteToTransmit = (ubyte)(FlashAddr >> 8);
  SPIC_TransmitOneByte(SPIC_EXT_FLASH_CH, ByteToTransmit);
  ByteToTransmit = (ubyte)FlashAddr;
  SPIC_TransmitOneByte(SPIC_EXT_FLASH_CH, ByteToTransmit);

  /* Read data from Flash */
  Size = 0;
  do
  {
    /* Read one short from flash */
    #ifdef __BIG_ENDIAN__
    SPIC_ReceiveOneByte(SPIC_EXT_FLASH_CH, &Data._byte.high);
    SPIC_ReceiveOneByte(SPIC_EXT_FLASH_CH, &Data._byte.low);
    #else
    SPIC_ReceiveOneByte(SPIC_EXT_FLASH_CH, &Data._byte.low);
    SPIC_ReceiveOneByte(SPIC_EXT_FLASH_CH, &Data._byte.high);
    #endif
    *Buffer = Data._short;
    Buffer++;
    Size++;
  } while (Data._short != DataValue);

  IODC_SetOutputData(CS_EXT_FLASH, IODC_INACTIVE);

#else

  ushort* Ptr;
  ushort  Size;
  ushort  Data;

  Size = 0;
  Ptr  = (ushort*) FlashAddr;

  do
  {
    /* Simulate read one short from flash */
    Data = *Ptr;
    *Buffer = Data;

    Buffer++;
    Ptr++;

    Size++;
  } while (Data != DataValue);

#endif  /* __PC_SIMULATION__ */

  return (Size);
}
#endif /* Syst_READ_EXTERNAL_SPI_FLASH_UNTIL_SHORT_SERVICE */


#ifdef Syst_READ_EXTERNAL_SPI_FLASH_ID_SERVICE
/*----------------------------------------------------------------------------*/
/* Name: SYST_ReadExternalFlashId                                             */
/* Role: Read 24bits Id of external Flash                                     */
/* Interface: Buffer        IN   Destination buffer                           */
/* Pre-condition: none                                                        */
/* Constraints:   none                                                        */
/* Behavior:                                                                  */
/*   DO                                                                       */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/
void SYST_ReadExternalFlashId(ubyte* Buffer)
{
  #define Syst_EXT_FLASH_OPCODE_READID    0x9F

  IODC_SetOutputData(CS_EXT_FLASH, IODC_ACTIVE);
  SPIC_TransmitOneByte(SPIC_EXT_FLASH_CH, Syst_EXT_FLASH_OPCODE_READID);
  SPIC_ReceiveOneByte(SPIC_EXT_FLASH_CH, Buffer);
  SPIC_ReceiveOneByte(SPIC_EXT_FLASH_CH, Buffer + 1);
  SPIC_ReceiveOneByte(SPIC_EXT_FLASH_CH, Buffer + 2);
  IODC_SetOutputData(CS_EXT_FLASH, IODC_INACTIVE);
}
#endif /* Syst_READ_EXTERNAL_SPI_FLASH_ID_SERVICE */


#ifdef Syst_ROM_CHECKSUM_SERVICE
/*----------------------------------------------------------------------------*/
/* Name: SYST_ExternalFlashChecksum                                           */
/* Role: Make the external flash checksum byte per byte into an ushort format */
/* Interface: StartFlashAddr   IN   Start address of data in external Flash   */
/*            EndFlashAddr     IN   End address of data in external Flash     */
/*            (ushort)         OUT  The checksum value                        */
/* Pre-condition: none                                                        */
/* Constraints:   none                                                        */
/*----------------------------------------------------------------------------*/
ushort SYST_ExternalFlashChecksum(SYST_AddressWidth_t  StartFlashAddr,
                                  SYST_AddressWidth_t  EndFlashAddr)
{
#ifndef __PC_SIMULATION__
  SYST_AddressWidth_t address;
  ushort              checksum;
  ubyte               dataByte;
  ubyte ByteToTransmit;


  /* Send READ command and 24 bits address */
  IODC_SetOutputData(CS_EXT_FLASH, IODC_ACTIVE);
  SPIC_TransmitOneByte(SPIC_EXT_FLASH_CH, Syst_EXT_FLASH_OPCODE_READ);
  ByteToTransmit = (ubyte)(StartFlashAddr >> 16);
  SPIC_TransmitOneByte(SPIC_EXT_FLASH_CH, ByteToTransmit);
  ByteToTransmit = (ubyte)(StartFlashAddr >> 8);
  SPIC_TransmitOneByte(SPIC_EXT_FLASH_CH, ByteToTransmit);
  ByteToTransmit = (ubyte)StartFlashAddr;
  SPIC_TransmitOneByte(SPIC_EXT_FLASH_CH, ByteToTransmit);

  checksum = 0;
  for (address=StartFlashAddr; address<=EndFlashAddr; address++)
  {
    /* Read one byte from flash */
    SPIC_ReceiveOneByte(SPIC_EXT_FLASH_CH, &dataByte);

    checksum += dataByte;
  }

  IODC_SetOutputData(CS_EXT_FLASH, IODC_INACTIVE);

  return (checksum);

#else

  /* Nothing to do */
  return (0);

#endif  /* __PC_SIMULATION__ */
}
#endif /* Syst_ROM_CHECKSUM_SERVICE */
#endif /* Syst_READ_EXTERNAL_SPI_FLASH_SERVICE */

#if defined(Syst_CRC16_INV_CCITT)
/*----------------------------------------------------------------------------*/
/* Name: SYST_ComputeCRC16Inverted                                            */
/* Role: Compute the CRC of a data (Inverted Crc16 ccitt)                     */
/* Interface: Address IN address of data                                      */
/*            size    IN datas size                                           */
/*            Result  OUT the CRC                                             */
/* Pre-condition: none                                                        */
/* Constraints:   none                                                        */
/* Behavior:                                                                  */
/*   DO                                                                       */
/*    [ compute ]                                                             */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/
ushort SYST_ComputeCRC16Inverted(__GCONST__ ubyte *address, ushort size)
{
  ushort Crc16 ;
  ushort i;

  Crc16 = 0xFFFF;

  for (i=0;i<size;i++)
  {
    Crc16 = SYST_UpdateInvCrc16Ccitt(Crc16, address[i]);
  }

  return (Crc16);
}
#endif /* Syst_CRC16_INV_CCITT */

#if defined(Syst_CRC16_INV_CCITT)
/*----------------------------------------------------------------------------*/
/* Name: SYST_ComputeCRC16                                                    */
/* Role: Compute the CRC of a data (Inverted Crc16 ccitt)                     */
/* Interface: Address IN address of data                                      */
/*            size    IN datas size                                           */
/*            Result  OUT the CRC                                             */
/* Pre-condition: none                                                        */
/* Constraints:   none                                                        */
/* Behavior:                                                                  */
/*   DO                                                                       */
/*    [ compute ]                                                             */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/
ushort SYST_ComputeCRC16(__GCONST__ ubyte *address, ubyte size)
{
  ushort Crc16 ;
  ubyte i;

  Crc16 = 0xFFFF;

  for (i=0;i<size;i++)
  {
    Crc16 = SYST_UpdateInvCrc16Ccitt(Crc16, address[i]);
  }

  return (Crc16);
}
#endif /* Syst_CRC16_INV_CCITT */


#if defined(Syst_CRC16_INV_CCITT) || defined(Syst_UPDATE_CRC16_INV_CCITT)
/*----------------------------------------------------------------------------*/
/*Name : SYST_UpdateInvCrc16Ccitt                                             */
/*Role : calculates a new inverted CRC16-CCITT value  based  on the previous  */
/*       value of the CRC and the next byte of the data to be checked.        */
/*Interface :                                                                 */
/*    IN InputData  : previous crc value                                      */
/*    IN InputData  : next byte of the data to be checked                     */
/*    OUT return value : new INV_CRC16_CCITT value                            */
/*Pre-condition : none                                                        */
/*Constraints : none                                                          */
/*Behaviour :                                                                 */
/*DO                                                                          */
/*  [ Update CRC with incoming data flow  ]                                   */
/*OD                                                                          */
/*----------------------------------------------------------------------------*/
ushort SYST_UpdateInvCrc16Ccitt(ushort crc, ubyte data)
{
#if defined(Syst_COMPUTE_CRC16_USING_TABLE)
  crc = (ushort)((crc >> 8) ^ Syst_InvCrcTable[(crc ^ data) & 0xFF]);
#else
  ubyte i;
  ubyte c;
  ubyte bit;

  for (i=0; i<8; i++)
  {
    bit = (ubyte)  ((data >> i) & 0x01);
    c   = (ubyte)  (crc & 0x0001);
    crc = (ushort) (crc >> 1);

    if ((c ^ bit) != 0)
    {
      crc = (ushort) (crc ^ Syst_POLYNOM_CCITT_INV);
    }
  }
#endif
  return (crc);
}
#endif /* Syst_CRC16_INV_CCITT || Syst_UPDATE_CRC16_INV_CCITT */


#if defined(Syst_CRC16_CCITT)
/*----------------------------------------------------------------------------*/
/* Name: SYST_ComputeCRC16NonInverted                                         */
/* Role: Compute the CRC of a data (Crc16 ccitt)                              */
/* Interface: Address IN address of data                                      */
/*            size    IN datas size                                           */
/*            Result  OUT the CRC                                             */
/* Pre-condition: none                                                        */
/* Constraints:   none                                                        */
/* Behavior:                                                                  */
/*   DO                                                                       */
/*    [ compute ]                                                             */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/
ushort SYST_ComputeCRC16NonInverted(__GCONST__ ubyte *address, ubyte size)
{
  ushort Crc16;
  ubyte i;

  Crc16 = 0xFFFF;

  for (i=0;i<size;i++)
  {
    Crc16 = Syst_UpdateCrc16Ccitt(Crc16, address[i]);
  }

  return (Crc16);
}
#endif /* defined (Syst_CRC16_CCITT) */


#if defined(Syst_CHKSUM16_DATA_USED)
/*----------------------------------------------------------------------------*/
/* Name: SYST_ComputeCHKSUM                                                   */
/* Role: Compute the Chksum of a table data                                   */
/* Interface: Address IN address of data                                      */
/*            size    IN datas size                                           */
/*            Result  OUT the CRC                                             */
/* Pre-condition: none                                                        */
/* Constraints:   none                                                        */
/* Behavior:                                                                  */
/*   DO                                                                       */
/*    [ compute ]                                                             */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/
ushort SYST_ComputeCHKSUM16(__GCONST__ ubyte *address, ubyte size)
{
  ushort Index;
  ushort ChkSum;

  ChkSum = 0;

  /* calculate Checksum */
  for (Index = 0; Index < size ; Index++)
  {
    ChkSum += *(address+Index);
  }

  return (ChkSum);
}
#endif /* defined(Syst_CHKSUM16_DATA_USED) */


#ifdef Syst_CRC32
/*----------------------------------------------------------------------------*/
/* Name: SYST_ComputeCrc32                                                    */
/* Role:  Compute the CRC32 of a given data                                   */
/* Interface: Address IN address of data                                      */
/*            nBytes  IN datas size                                           */
/*            Result  OUT the CRC                                             */
/* Pre-condition: none                                                        */
/* Constraints:   none                                                        */
/* Behavior:                                                                  */
/*   DO                                                                       */
/*    [ compute CRC32 ]                                                       */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/
ulong SYST_ComputeCrc32( ubyte *address, ubyte nBytes )
{
  ulong          remainder;
  ubyte          byteCnt;
  ubyte          bit;

  remainder = Syst_INITIAL_REMAINDER;

  /* Perform modulo-2 division, a byte at a time. */
  for (byteCnt = 0; byteCnt < nBytes; byteCnt++)
  {
    /* Bring the next byte into the remainder. */
    remainder ^= (ulong)(((ulong) Syst_reflect((address[byteCnt]), 8)) << (Syst_WIDTH - 8));

    /* Perform modulo-2 division, a bit at a time. */
    for (bit = 0; bit < 8; bit++)
    {
      /* Try to divide the current data bit. */
      if (remainder & 0x80000000u)
      {
        remainder = (ulong)((remainder << 1) ^ Syst_POLYNOM_CRC32);
      }
      else
      {
        remainder = (ulong)(remainder << 1);
      }
    }
  }

  /* The final remainder is the CRC result.  */
  return (((ulong) Syst_reflect((remainder), Syst_WIDTH)) ^ Syst_FINAL_XOR_VALUE);
}
#endif /* Syst_CRC32 */

#ifdef SYST_RESET_INFO
/*----------------------------------------------------------------------------*/
/*Name : SYST_GetResetType                                                    */
/*Role : Give the reset type                                                  */
/*Interface :                                                                 */
/*   IN : -                                                                   */
/*  OUT : -ResetType                                                          */
/*Pre-condition : -                                                           */
/*Constraints : -                                                             */
/* Behavior:                                                                  */
/*   DO                                                                       */
/*    [ return the cause of reset ]                                           */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/
SYST_ResetType_t SYST_GetResetType(void)
{
#if defined(__REL_RL78__) || defined(__NEC_V850_Fx3__) || defined(__NEC_V850_Dx3__) \
   || defined(__MC9S08xx__) || defined(__FSL_IMX53x__) || defined(__FSL_IMX6x__)
  ubyte Reg;
#endif
#if defined(__REL_V850_Dx4__) || defined(__RH850_F1x__) || defined(__CY_TV2__)
  ulong Reg;
#endif

  SYST_ResetType_t ResetType;

  ResetType = SYST_RESET_UNKNOW;

#ifdef __REL_RL78__
#if((defined(__REL_RL78_D1x__)) || (defined(__REL_RL78_F1x__)))
#if((defined(__REL_RL78_D1A__)) || (defined(__REL_RL78_F12__)))
  Reg = TARG_ReadByte(RESF);
  if (Reg & SYST_MSK_BIT0)
   {
      ResetType = SYST_RESET_LOW_VOLT;
   }
  else
   {
     if (Reg & SYST_MSK_BIT1)
     {
       ResetType = SYST_RESET_ILLEGAL_MEMORY_ACCESS;
     }
     else
     {
      if (Reg & SYST_MSK_BIT2)
      {
        ResetType = SYST_RESET_RAM_PARITY_ERROR;
      }
      else
      {
       if (Reg & SYST_MSK_BIT4)
       {
         ResetType = SYST_RESET_WDG;
       }
       else
       {
         if (Reg & SYST_MSK_BIT7)
         {
          ResetType = SYST_RESET_ILLEGAL_OP;
         }
         else
         {
           #ifdef __REL_RL78_D1A__
           Reg = TARG_ReadByte(RESFCLM);
           if (Reg & SYST_MSK_BIT0)
           {
             ResetType = SYST_RESET_CLOCK;
           }
           else
           {
             ResetType = SYST_RESET_EXT_OR_POWER;
           }
           #endif /*__REL_RL78_D1A__ */
           #ifdef __REL_RL78_F12__
           ResetType = SYST_RESET_EXT_OR_POWER;
           #endif /*__REL_RL78_F12__ */
         }
        }
       }
     }
   }
#endif /*__REL_RL78_D1A__ || __REL_RL78_F12__*/
#endif /*__REL_RL78_D1x__ || __REL_RL78_F1x__*/
#endif /*__REL_RL78__ */

  #ifdef __NEC_V850__
  #ifdef __NEC_V850_Fx3__
  Reg = TARG_ReadByte(RESF);
  if (Reg & SYST_MSK_BIT4)
  {
    ResetType = SYST_RESET_WDG;
  }
  else
  {
    if (Reg & SYST_MSK_BIT1)
    {
      ResetType = SYST_RESET_CLOCK;
    }
    else
    {
      if (Reg & SYST_MSK_BIT0)
      {
        ResetType = SYST_RESET_LOW_VOLT;
      }
      else
      {
        if (Reg == 0)
        {
          ResetType = SYST_RESET_EXT_OR_POWER;
        }
        else
        {
          ResetType = SYST_RESET_UNKNOW;
        }
      }
    }
  }
  #endif /* __NEC_V850_Fx3__ */

  #ifdef __NEC_V850_Dx3__
  Reg = TARG_ReadByte(RESSTAT);
  if (Reg & SYST_MSK_BIT0) || /* Reset at Power-On-Clear */
     (Reg & SYST_MSK_BIT1)    /* External RESET */
  {
    ResetType = SYST_RESET_EXT_OR_POWER;
  }
  else if (Reg & SYST_MSK_BIT2) || /* Reset by Clock Monitor of main osc. */
          (Reg & SYST_MSK_BIT3)    /* Reset by Clock Monitor of sub osc. */
  {
    ResetType = SYST_RESET_CLOCK;
  }
  else if (Reg & SYST_MSK_BIT4) /* Reset by Watchdog Timer */
  {
    ResetType = SYST_RESET_WDG;
  }
  else /* (Reg & SYST_MSK_BIT5)  Software reset */
  {
    ResetType = SYST_RESET_UNKNOW;
  }
  #endif /* __NEC_V850_Dx3__ */

  #ifdef __REL_V850_Dx4__
  Reg = TARG_ReadLong(RESF);
  if (Reg & RES_MSK_RESF0) /* SW reset flag */
  {
    ResetType = SYST_RESET_UNKNOW;
  }
  else if ((Reg & RES_MSK_RESF1) || /* WDTA0 reset flag */
           (Reg & RES_MSK_RESF2))   /* WDTA1 reset flag */
  {
    ResetType = SYST_RESET_WDG;
  }
  else if ((Reg & RES_MSK_RESF3) || /* CLMA0 reset flag */
           (Reg & RES_MSK_RESF4) || /* CLMA1 reset flag */
           (Reg & RES_MSK_RESF5) || /* CLMA2 reset flag */
           (Reg & RES_MSK_RESF6))   /* CLMA3 reset flag */
  {
    ResetType = SYST_RESET_CLOCK;
  }
  else if (Reg & RES_MSK_RESF7) /* LVI reset flag */
  {
    ResetType = SYST_RESET_LOW_VOLT;
  }
  else if (Reg & RES_MSK_RESF8) /* External reset flag */
  {
    ResetType = SYST_RESET_EXT_OR_POWER;
  }
  else /* (Reg & RES_MSK_RESF9)  Debug reset flag */
  {
    ResetType = SYST_RESET_UNKNOW;
  }
  #endif /* __REL_V850_Dx4__ */
  #endif /* __NEC_V850__ */

  #ifdef __MC9S08xx__
  Reg = TARG_ReadByte(SRS);
  if (Reg & (SYST_MSK_BIT7 | SYST_MSK_BIT6))
  {
    ResetType = SYST_RESET_EXT_OR_POWER;
  }
  else
  {
    if (Reg & SYST_MSK_BIT5)
    {
      ResetType = SYST_RESET_WDG;
    }
    else
    {
      if (Reg & SYST_MSK_BIT4)
      {
        ResetType = SYST_RESET_ILLEGAL_OP;
      }
      else
      {
        if (Reg & SYST_MSK_BIT2)
        {
          ResetType = SYST_RESET_CLOCK;
        }
        else
        {
          if (Reg & SYST_MSK_BIT1)
          {
            ResetType = SYST_RESET_LOW_VOLT;
          }
          else
          {
            ResetType = SYST_RESET_UNKNOW;
          }
        }
      }
    }
  }
  #endif /* __MC9S08xx__ */

  #if defined(__FSL_IMX53x__) || defined(__FSL_IMX6x__)
  Reg = TARG_ReadByte(SRC_SRSR);

  /* Bit 4 is a wdog_rst_b */
  if (Reg & SYST_MSK_BIT4 )
  {
    ResetType = SYST_RESET_WDG ;
  }
  else
  {
    /* Bit 0 is a ipp_reset_b (Power-up sequence)*/
    if (Reg & SYST_MSK_BIT0)
    {
      ResetType = SYST_RESET_EXT_OR_POWER;
    }
    else
    {
     /* Bit 3 is a ipp_user_reset_b */
     /* Bit 5 is a jtag_rst_b */
     /* Bit 6 is a jtag_sw_rst */
    if (Reg & (SYST_MSK_BIT3 | SYST_MSK_BIT5 | SYST_MSK_BIT6))
      {
        ResetType = SYST_RESET_UNKNOW;
      }
      else
      {
        ResetType = SYST_RESET_ALREADY_CONSUMMED;
      }
    }
  }

  /* clear SRC_SRSR register */
  TARG_WriteByte(SRC_SRSR,0xFF);

  #endif /* __FSL_IMX53x__,__FSL_IMX6x__ */

#ifdef __RH850__
#ifdef __RH850_F1x__

#ifdef __RH850_F1L__
  Reg = TARG_ReadLong(RESF);
#endif/*__RH850_F1L__*/
#ifdef __RH850_F1K__
  Reg = TARG_ReadLong(RESCTLRESF);
  if (Reg & SYST_MSK_BIT9 )
  {
    SYST_PowerOnFlag= TRUE;
  }
#endif/*__RH850_F1K__*/
  if ((Reg & SYST_MSK_BIT1 )||(Reg & SYST_MSK_BIT2 ))
  {
    ResetType = SYST_RESET_WDG;
  }
  else if (Reg & SYST_MSK_BIT0 )
  {
    ResetType = SYST_SW_RESET;
  }
  else if ((Reg & SYST_MSK_BIT3 )||(Reg & SYST_MSK_BIT4 )||(Reg & SYST_MSK_BIT5 ))
  {
    ResetType = SYST_RESET_CLOCK;
  }
  else if ((Reg & SYST_MSK_BIT6 ))
  {
    ResetType = SYST_RESET_LOW_VOLT;
  }
  else if ((Reg & SYST_MSK_BIT7 )||(Reg & SYST_MSK_BIT8 ))
  {
    ResetType = SYST_RESET_EXT_OR_POWER;
  }
  else if (Reg & SYST_MSK_BIT10 )
  {
    ResetType = SYST_DEEPSTOP_RESET;
#ifdef __BOOT_LINK__
    STAR_WakeUpFromDeepSleep();
#else
#ifdef _MCU_DEBUG_
    STAR_WakeUpFromDeepSleep();
#endif
#endif
  }
  else if (Reg & SYST_MSK_BIT9 )
  {
    ResetType = SYST_POWER_ON;
  }
  else
  {

  }
#endif/*__RH850_F1x__*/
#endif/*__RH850__*/

#ifdef __CY_TV2__
  Reg = Cy_SysReset_GetResetReason();
  if( (( Reg & CY_SYSRESET_WDT ) == CY_SYSRESET_WDT)
   || (( Reg & CY_SYSRESET_MCWDT0 ) == CY_SYSRESET_MCWDT0)
   || (( Reg & CY_SYSRESET_MCWDT1 ) == CY_SYSRESET_MCWDT1)
   || (( Reg & CY_SYSRESET_MCWDT2 ) == CY_SYSRESET_MCWDT2)
   || (( Reg & CY_SYSRESET_MCWDT3 ) == CY_SYSRESET_MCWDT3)
    )
  {
    ResetType = SYST_RESET_WDG;
  }
  else if( ( Reg & CY_SYSRESET_ACT_FAULT ) == CY_SYSRESET_ACT_FAULT )
  {
    ResetType = SYST_RESET_ACT_FAULT;
  }
  else if( ( Reg & CY_SYSRESET_SOFT ) == CY_SYSRESET_SOFT )
  {
    ResetType = SYST_SW_RESET;
  }
  else if( (( Reg & CY_SYSRESET_CSV_HF ) == CY_SYSRESET_CSV_HF)
        || (( Reg & CY_SYSRESET_CSV_REF ) == CY_SYSRESET_CSV_REF)
         )
  {
    ResetType = SYST_RESET_CLOCK;
  }
  else if( (Reg & CY_SYSRESET_XRES ) == CY_SYSRESET_XRES )
  {
    ResetType = SYST_RESET_EXT_OR_POWER;
  }
  else if( (( Reg & CY_SYSRESET_DPSLP_FAULT ) == CY_SYSRESET_DPSLP_FAULT )
        || (( Reg & CY_SYSRESET_HIB_WAKEUP ) == CY_SYSRESET_HIB_WAKEUP)
		/* || (SYST_SleepMode == SYST_FROM_DEEPSLEEP_TO_WAKEUP )*/
         )
  {
    ResetType = SYST_DEEPSTOP_RESET;
  }
  else if( ( Reg & CY_SYSRESET_PORVDDD ) == CY_SYSRESET_PORVDDD )
  {
    ResetType = SYST_POWER_ON;
  }
  else if( (( Reg & CY_SYSRESET_BODVDDD ) == CY_SYSRESET_BODVDDD)
   || (( Reg & CY_SYSRESET_BODVDDA ) == CY_SYSRESET_BODVDDA)
   || (( Reg & CY_SYSRESET_BODVCCD ) == CY_SYSRESET_BODVCCD)
    )
  {
    ResetType = SYST_RESET_BODVXXX;
  }
  else if( (( Reg & CY_SYSRESET_OVDVDDD ) == CY_SYSRESET_OVDVDDD)
   || (( Reg & CY_SYSRESET_OVDVDDA ) == CY_SYSRESET_OVDVDDA)
   || (( Reg & CY_SYSRESET_OVDVCCD ) == CY_SYSRESET_OVDVCCD)
    )
  {
    ResetType = SYST_RESET_OVDVXXX;
  }
  else if (   (( Reg & CY_SYSRESET_OCD_ACT_LINREG ) == CY_SYSRESET_OCD_ACT_LINREG)
   || (( Reg & CY_SYSRESET_OCD_DPSLP_LINREG ) == CY_SYSRESET_OCD_DPSLP_LINREG)
   || (( Reg & CY_SYSRESET_OCD_REGHC ) == CY_SYSRESET_OCD_REGHC)
   )
   {
    ResetType = SYST_RESET_OCDXXX;
   }
  else if( ( Reg & CY_SYSRESET_PMIC ) == CY_SYSRESET_PMIC)
  {
    ResetType = SYST_RESET_PMIC;
  }
  else if ( ( Reg & CY_SYSRESET_PXRES ) == CY_SYSRESET_PXRES)
  {
    ResetType = SYST_RESET_PXRES;
  }
  else if ( ( Reg & CY_SYSRESET_STRUCT_XRES ) == CY_SYSRESET_STRUCT_XRES)
  {
    ResetType = SYST_RESET_STRUCT_XRES;
  }
  else if( (Reg & CY_SYSRESET_TC_DBGRESET ) == CY_SYSRESET_TC_DBGRESET )
  {
    ResetType = SYST_RESET_TC_DBGRESET;
  }
  else
  {

  }

#endif /*__CY_TV2__*/

  return ResetType;
}
#endif /* SYST_RESET_INFO */



#ifdef Syst_BYTE_SEQ_BIG_ENDIAN_TO_ULONG
/*----------------------------------------------------------------------------*/
/*Name : SYST_ByteSeqBigEndianToUlong                                         */
/*Role : Convert a big endian byte sequence into ulong (32 bits).             */
/*Interface :                                                                 */
/*   IN : const ubyte* ByteSeq                                                */
/*  OUT : ulong Value                                                         */
/*Pre-condition : -                                                           */
/*Constraints :   -                                                           */
/*Behavior:       -                                                           */
/*----------------------------------------------------------------------------*/
ulong SYST_ByteSeqBigEndianToUlong(const ubyte* ByteSeq)
{
  bitfield_long_t Value;

  Value._IndexedByte[TYPE_FIRST_MS_ID]  = ByteSeq[0];
  Value._IndexedByte[TYPE_SECOND_MS_ID] = ByteSeq[1];
  Value._IndexedByte[TYPE_THIRD_MS_ID ] = ByteSeq[2];
  Value._IndexedByte[TYPE_FOURTH_MS_ID] = ByteSeq[3];

  return (Value._long);
}
#endif /*Syst_BYTE_SEQ_BIG_ENDIAN_TO_ULONG*/

#ifdef Syst_BYTE_SEQ_LITTLE_ENDIAN_TO_ULONG
/*----------------------------------------------------------------------------*/
/*Name : SYST_ByteSeqLittleEndianToUlong                                      */
/*Role : Convert a little endian byte sequence into ulong (32 bits).          */
/*Interface :                                                                 */
/*   IN : const ubyte* ByteSeq                                                */
/*  OUT : ulong Value                                                         */
/*Pre-condition : -                                                           */
/*Constraints :   -                                                           */
/*Behavior:       -                                                           */
/*----------------------------------------------------------------------------*/
ulong SYST_ByteSeqLittleEndianToUlong(const ubyte* ByteSeq)
{
  bitfield_long_t Value;

  Value._IndexedByte[TYPE_FIRST_MS_ID ] = ByteSeq[3];
  Value._IndexedByte[TYPE_SECOND_MS_ID] = ByteSeq[2];
  Value._IndexedByte[TYPE_THIRD_MS_ID ] = ByteSeq[1];
  Value._IndexedByte[TYPE_FOURTH_MS_ID] = ByteSeq[0];

  return (Value._long);
}
#endif /*Syst_BYTE_SEQ_LITTLE_ENDIAN_TO_ULONG*/

#ifdef Syst_BYTE_SEQ_BIG_ENDIAN_TO_USHORT
/*----------------------------------------------------------------------------*/
/*Name : SYST_ByteSeqBigEndianToUshort                                        */
/*Role : Convert a big endian byte sequence into ushort (16 bits).            */
/*Interface :                                                                 */
/*   IN : const ubyte* ByteSeq                                                */
/*  OUT : ulong Value                                                         */
/*Pre-condition : -                                                           */
/*Constraints :   -                                                           */
/*Behavior:       -                                                           */
/*----------------------------------------------------------------------------*/
ushort SYST_ByteSeqBigEndianToUshort(const ubyte* ByteSeq)
{
  bitfield_short_t Value;

  Value._byte.high = ByteSeq[0];
  Value._byte.low  = ByteSeq[1];

  return (Value._short);
}
#endif /*Syst_BYTE_SEQ_BIG_ENDIAN_TO_USHORT*/

#ifdef Syst_BYTE_SEQ_LITTLE_ENDIAN_TO_USHORT
/*----------------------------------------------------------------------------*/
/*Name : SYST_ByteSeqLittleEndianToUshort                                     */
/*Role : Convert a little endian byte sequence into ushort (16 bits).         */
/*Interface :                                                                 */
/*   IN : const ubyte* ByteSeq                                                */
/*  OUT : ulong Value                                                         */
/*Pre-condition : -                                                           */
/*Constraints :   -                                                           */
/*Behavior:       -                                                           */
/*----------------------------------------------------------------------------*/
ushort SYST_ByteSeqLittleEndianToUshort(const ubyte* ByteSeq)
{
  bitfield_short_t Value;

  Value._byte.high = ByteSeq[1];
  Value._byte.low  = ByteSeq[0];

  return (Value._short);
}
#endif /*Syst_BYTE_SEQ_LITTLE_ENDIAN_TO_USHORT*/

#ifdef SYST_DEBUG_RESET
/*----------------------------------------------------------------------------*/
/*Name : SYST_DebugReset                                                      */
/*Role : Hook for SYST_Reset to facilitate debug on emulator                  */
/*Interface :                                                                 */
/*   IN : -                                                                   */
/*  OUT : -                                                                   */
/*Pre-condition : -                                                           */
/*Constraints :   -                                                           */
/*Behavior:       -                                                           */
/*----------------------------------------------------------------------------*/
void SYST_DebugReset(void)
{
  volatile bool_t lock;

  lock = TRUE;

  #ifdef __PC_SIMULATION__
  __debugbreak();
  lock = FALSE;
  #endif /*__PC_SIMULATION__ */

  #if defined(SYST_SPY_UART_USED) && defined(C_COMP_GHS_ARM)
  {
    ulong returnAddress;
    returnAddress = (ulong) (__builtin_return_address(0));
    printf ("SYST_Reset : %x\n", returnAddress);
  }
  #endif /* SYST_SPY_UART_USED && C_COMP_GHS_ARM */

  while (lock);
}
#endif /* SYST_DEBUG_RESET */

#ifdef Syst_CHECKSUM_XOR_USED
/*----------------------------------------------------------------------------*/
/* Name: SYST_ComputeChecksumXOR                                              */
/* Role: Compute the XOR checksum of a table data                             */
/* Interface:                                                                 */
/*   IN : Address  : data pointer                                             */
/*   IN : Size     : data size                                                */
/*  OUT : Checksum : computed checksum                                        */
/* Pre-condition: none                                                        */
/* Constraints: none                                                          */
/* Behavior:                                                                  */
/* DO                                                                         */
/*    [ return checksum = Byte0 XOR Byte1 XOR ... XOR ByteN ]                 */
/* OD                                                                         */
/*----------------------------------------------------------------------------*/
ubyte SYST_ComputeChecksumXOR(ubyte *Address, ubyte Size)
{
  ubyte Checksum;
  ubyte Index;

  Checksum = 0;

  for (Index = 0; Index < Size; Index++)
  {
    Checksum = (ubyte)(Checksum ^ *(Address + Index));
  }

  return (Checksum);
}
#endif /* Syst_CHECKSUM_XOR_USED */


#ifdef SYST_DEBUG_ALLOC
/*----------------------------------------------------------------------------*/
/* Name : SYST_DebugMalloc                                                    */
/* Role : Allocates memory with debug information                             */
/* Interface      :                                                           */
/*   - IN  : (size_t) : Required allocation size                              */
/*   - IN  : (ulong)  : ID of the module where the allocation is done         */
/*   - IN  : (ulong)  : ID of the file where the allocation is done           */
/*   - IN  : (ulong)  : line of the malloc call                               */
/*   - OUT : (void*)  : allocated mem                                         */
/* Pre-condition: none                                                        */
/* Constraints:   none                                                        */
/* Behaviour      :                                                           */
/*  DO                                                                        */
/*    Header =  {"SYST", Size, FileId, Line}                                  */
/*    NewSize = Size + sizeof(Header)                                         */
/*    Pointer = malloc(NewSize)                                               */
/*    IF Pointer != NULL THEN                                                 */
/*      TotalAllocSize += NewSize                                             */
/*    FI                                                                      */
/*    RETURN Pointer+sizeof(Header)                                           */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
extern void* SYST_DebugMalloc(size_t Size, ulong Module,
                              ulong FileId, ulong LineNb)
{
  ulong Pointer;
  ulong OutPointer;
  size_t NewSize;
  Syst_DebugAllocHeader_t* Header;

  OutPointer = (ulong) NULL;

  if (Size > 0)
  {
    NewSize = Size + sizeof(Syst_DebugAllocHeader_t);
    Pointer = (ulong) malloc(NewSize);
    if (NULL != (void*)Pointer)
    {
      Syst_TotalAllocSize += NewSize;
      Header = (Syst_DebugAllocHeader_t*)Pointer;
      Header->Computable.Mod  = Module;
      Header->Computable.File = FileId;
      Header->Computable.Line = LineNb;
      Header->Computable.Size = NewSize;
    }
    OutPointer = Pointer + sizeof(Syst_DebugAllocHeader_t);
  }

  return (void*)OutPointer;
}

/*----------------------------------------------------------------------------*/
/* Name : SYST_DebugCalloc                                                    */
/* Role : Allocates and clears memory with debug information                  */
/* Interface      :                                                           */
/*   - IN  : (ulong)  : Number of elements to allocate                        */
/*   - IN  : (size_t) : Size of an element                                    */
/*   - IN  : (ulong)  : ID of the module where the allocation is done         */
/*   - IN  : (ulong)  : ID of the file where the allocation is done           */
/*   - IN  : (ulong)  : line of the malloc call                               */
/* Pre-condition: none                                                        */
/* Constraints:   none                                                        */
/* Behaviour      :                                                           */
/*  DO                                                                        */
/*    Header =  {"SYST", Size, FileId, Line}                                  */
/*    NewSize = Size + sizeof(Header)                                         */
/*    Pointer = malloc(NewSize)                                               */
/*    IF Pointer != NULL THEN                                                 */
/*      TotalAllocSize += NewSize                                             */
/*    FI                                                                      */
/*    RETURN Pointer+sizeof(Header)                                           */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
extern void* SYST_DebugCalloc(ulong Nb, size_t ElementSize,
                              ulong Module, ulong FileId, ulong LineNb)
{
  ulong Pointer;
  ulong OutPointer;
  ulong NewNb;
  Syst_DebugAllocHeader_t* Header;
  OutPointer = (ulong)NULL;
  
  if (ElementSize > 0 && Nb > 0)
  {
    NewNb = Nb + sizeof(Syst_DebugAllocHeader_t)/ElementSize;
    if (sizeof(Syst_DebugAllocHeader_t) % ElementSize)
    {
      NewNb += 1;
    }

    Pointer = (ulong) calloc(NewNb, ElementSize);
    if (NULL != (void*)Pointer)
    {
      Syst_TotalAllocSize += NewNb * ElementSize;

      Header = (Syst_DebugAllocHeader_t*)Pointer;
      Header->Computable.Mod  = Module;
      Header->Computable.File = FileId;
      Header->Computable.Line = LineNb;
      Header->Computable.Size = NewNb * ElementSize;
    }
    OutPointer = Pointer + sizeof(Syst_DebugAllocHeader_t);
  }
  return (void*)OutPointer;
}


/*----------------------------------------------------------------------------*/
/* Name : SYST_DebugFree                                                      */
/* Role : Frees allocated memory                                              */
/* Interface      :                                                           */
/*   - IN  : (void*)  : memory to free                                        */
/*   - IN  : (ulong)  : ID of the module where the allocation is done         */
/* Pre-condition: none                                                        */
/* Constraints:   none                                                        */
/* Behaviour      :                                                           */
/*  DO                                                                        */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
extern void SYST_DebugFree(void* Pointer, ulong Module)
{
  ulong RealPointer;
  Syst_DebugAllocHeader_t* Header;

  RealPointer = (ulong)Pointer - sizeof(Syst_DebugAllocHeader_t);
  Header = (Syst_DebugAllocHeader_t*) RealPointer;
  if (Header->Computable.Mod != Module)
  {
    free(Pointer);
  }
  else
  {
    Syst_TotalAllocSize -= Header->Computable.Size;
    free((void*)RealPointer);
  }  
}
#endif /* SYST_DEBUG_ALLOC */


#if (defined(__REL_V850_Dx4__) || defined(__RH850_F1x__ )) && (defined(SYST_DATA_SAVE_IN_RESET) || defined(SYST_DATA_SAVE_IN_DEEPSTOP))
/*----------------------------------------------------------------------------*/
/* Name: SYST_BackupRam                                                       */
/* Role: Backup/retore data to BURAM (in 32bits access)                       */
/* Interface:                                                                 */
/*   IN : Action : SYST_BKP_STORE: Copy data to Backup RAM (BURAM)            */
/*                 SYST_BKP_RESTORE: Restore data from Backup RAM             */
/*   IN : BkpSecType : The section group to perform:                          */
/*                       - the shared data (SYST_BKP_SEC_BOOT)                */
/*                       - the reset data, data that must be maintained       */
/*                         between 2 reset (SYST_BKP_SEC_BEFORE_INIT)         */
/*                       - the sleep data, data that must be maintained       */
/*                         between 2 sleep (SYST_BKP_SEC_AFTER_INIT)          */
/* Pre-condition: -                                                           */
/* Constraints: -                                                             */
/*----------------------------------------------------------------------------*/
void SYST_BackupRam(SYST_BkpAction_t Action, SYST_BkpSecType_t BkpSecType)
{
  register ulong* save;
  register ulong* saveEnd;
  register ulong* backup;
  const Syst_BkpSec_t* secs;
  ulong* keyPtr;
  ubyte secNb;
  ubyte i;


  if (BkpSecType < SYST_BKP_SEC_NB)
  {
    keyPtr = Syst_BkpSecDefs[BkpSecType].KeyPtr;
    secs = Syst_BkpSecDefs[BkpSecType].Secs;
    secNb = Syst_BkpSecDefs[BkpSecType].SecNb;

    if ((keyPtr != NULL) && (secs != NULL))
    {
      for (i=0; i<secNb; i++)
      {
        save = secs[i].Start;
        saveEnd = secs[i].End;
        backup = secs[i].Backup;

        if (Action == SYST_BKP_RESTORE)
        {
          if (*keyPtr == SYST_BKP_KEY_VALID)
          {
            while (save < saveEnd)
            {
              *save = *backup;
              save++;
              backup++;
            }
          }
        }
        else
        {
          while (save < saveEnd)
          {
            *backup = *save;
            save++;
            backup++;
          }
        }
      }

      if (Action == SYST_BKP_RESTORE)
      {
        *keyPtr = SYST_BKP_KEY_UNVALID;
      }
      else
      {
        *keyPtr = SYST_BKP_KEY_VALID;
      }

    }
  }

}

/*----------------------------------------------------------------------------*/
/* Name : SYST_UnprotectBackupRam                                             */
/* Role : Enable to write in backup Ram                                       */
/* Interface : -                                                              */
/* Pre-condition :                                                            */
/* Constraints : -                                                            */
/*----------------------------------------------------------------------------*/
void SYST_UnprotectBackupRam(void)
{
#if defined(__REL_V850_Dx4__)
  TARG_WriteByte(BURC, 0x01);
  TARG_WriteByte(BURAEC, 0x01);
#endif

#if defined(__RH850_F1x__)
  /*
   * if f1x need to manage protection of backup ram,
   * the management will be added here.
   *
   * shubin.liang
   * */
#endif
}

/*----------------------------------------------------------------------------*/
/* Name : SYST_ProtectBackupRam                                               */
/* Role : Disable write in backup Ram                                         */
/* Interface : -                                                              */
/* Pre-condition :                                                            */
/* Constraints : -                                                            */
/*----------------------------------------------------------------------------*/
void SYST_ProtectBackupRam(void)
{
#if defined(__REL_V850_Dx4__)
  TARG_WriteByte(BURC, 0x00);
#endif

#if defined(__RH850_F1x__)
  /*
   * if f1x need to manage protection of backup ram,
   * the management will be added here.
   *
   * shubin.liang
   * */
#endif
}

/*----------------------------------------------------------------------------*/
/* Name : SYST_ConfigureWakeUpFactors                                         */
/* Role :                                                                     */
/* Interface : -                                                              */
/* Pre-condition :                                                            */
/* Constraints : -                                                            */
/*----------------------------------------------------------------------------*/
void SYST_ConfigureWakeUpFactors(void)
{
#if defined(__REL_V850_Dx4__)
  TARG_WriteLong(WUFCL0, 0xFFFFFFFF);
  TARG_WriteLong(WUFCL1, 0xFFFFFFFF);
  TARG_WriteLong(WUFCM0, 0xFFFFFFFF);
  TARG_WriteLong(WUFCM1, 0xFFFFFFFF);
  TARG_WriteLong(WUFCH0, 0xFFFFFFFF);
  TARG_WriteLong(WUFCH1, 0xFFFFFFFF);
  TARG_WriteLong(WUFMSKL0, SYST_WUFL);
  TARG_WriteLong(WUFMSKL1, 0xFFFFFFFF);
  TARG_WriteLong(WUFMSKM0, SYST_WUFM);
  TARG_WriteLong(WUFMSKM1, 0xFFFFFFFF);
  TARG_WriteLong(WUFMSKH0, SYST_WUFH);
  TARG_WriteLong(WUFMSKH1, 0xFFFFFFFF);
#endif
}

/*----------------------------------------------------------------------------*/
/* Name : SYST_ClearWakeUpEventInterrupt                                      */
/* Role :                                                                     */
/* Interface : -                                                              */
/* Pre-condition :                                                            */
/* Constraints : -                                                            */
/*----------------------------------------------------------------------------*/
void SYST_ClearWakeUpEventInterrupt(void)
{
#if defined(SYST_WAKEUP_EVENT_INTWDTA0)
TARG_ClearBitsInShort(ICWDTA0, INT_MSK_EIRFn|INT_MSK_EIMKn);
#endif
#if defined(SYST_WAKEUP_EVENT_INTWDTA1)
TARG_ClearBitsInShort(ICWDTA1, INT_MSK_EIRFn|INT_MSK_EIMKn);
#endif
#if defined(SYST_WAKEUP_EVENT_INTLVI)
TARG_ClearBitsInShort(ICLVI, INT_MSK_EIRFn|INT_MSK_EIMKn);
#endif
#if defined(SYST_WAKEUP_EVENT_INTP0)
  TARG_ClearBitsInShort(ICP0, INT_MSK_EIRFn|INT_MSK_EIMKn);
#endif
#if defined(SYST_WAKEUP_EVENT_INTP1)
  TARG_ClearBitsInShort(ICP1, INT_MSK_EIRFn|INT_MSK_EIMKn);
#endif
#if defined(SYST_WAKEUP_EVENT_INTP2)
  TARG_ClearBitsInShort(ICP2, INT_MSK_EIRFn|INT_MSK_EIMKn);
#endif
#if defined(SYST_WAKEUP_EVENT_INTP3)
  TARG_ClearBitsInShort(ICP3, INT_MSK_EIRFn|INT_MSK_EIMKn);
#endif
#if defined(SYST_WAKEUP_EVENT_INTP4)
  TARG_ClearBitsInShort(ICP4, INT_MSK_EIRFn|INT_MSK_EIMKn);
#endif
#if defined(SYST_WAKEUP_EVENT_INTP5)
  TARG_ClearBitsInShort(ICP5, INT_MSK_EIRFn|INT_MSK_EIMKn);
#endif
#if defined(SYST_WAKEUP_EVENT_INTP6)
  TARG_ClearBitsInShort(ICP6, INT_MSK_EIRFn|INT_MSK_EIMKn);
#endif
#if defined(SYST_WAKEUP_EVENT_INTP7)
  TARG_ClearBitsInShort(ICP1, INT_MSK_EIRFn|INT_MSK_EIMKn);
#endif
#if defined(SYST_WAKEUP_EVENT_INTP8)
  TARG_ClearBitsInShort(ICP8, INT_MSK_EIRFn|INT_MSK_EIMKn);
#endif
#if defined(SYST_WAKEUP_EVENT_INTP9)
  TARG_ClearBitsInShort(ICP9, INT_MSK_EIRFn|INT_MSK_EIMKn);
#endif
#if defined(SYST_WAKEUP_EVENT_INTP10)
  TARG_ClearBitsInShort(ICP10, INT_MSK_EIRFn|INT_MSK_EIMKn);
#endif
#if defined(SYST_WAKEUP_EVENT_FCN0RX)
  TARG_ClearBitsInShort(ICFCN0REC, INT_MSK_EIRFn|INT_MSK_EIMKn);
#endif
#if defined(SYST_WAKEUP_EVENT_FCN1RX)
  TARG_ClearBitsInShort(ICFCN1REC, INT_MSK_EIRFn|INT_MSK_EIMKn);
#endif
#if defined(SYST_WAKEUP_EVENT_FCN2RX)
  TARG_ClearBitsInShort(ICFCN2REC, INT_MSK_EIRFn|INT_MSK_EIMKn);
#endif
#if defined(SYST_WAKEUP_EVENT_INTRTCA0R)
  TARG_ClearBitsInShort(ICRTCA0R, INT_MSK_EIRFn|INT_MSK_EIMKn);
#endif
#if defined(SYST_WAKEUP_EVENT_INTRTCA0AL)
  TARG_ClearBitsInShort(ICRTCA0AL, INT_MSK_EIRFn|INT_MSK_EIMKn);
#endif
#if defined(SYST_WAKEUP_EVENT_INTRTCA01S)
  TARG_ClearBitsInShort(ICRTCA01S, INT_MSK_EIRFn|INT_MSK_EIMKn);
#endif
#if defined(SYST_WAKEUP_EVENT_INTCLMA0)
  TARG_ClearBitsInShort(ICCLMA0, INT_MSK_EIRFn|INT_MSK_EIMKn);
#endif
#if defined(SYST_WAKEUP_EVENT_INTCLMA1)
  TARG_ClearBitsInShort(ICCLMA1, INT_MSK_EIRFn|INT_MSK_EIMKn);
#endif
#if defined(SYST_WAKEUP_EVENT_INTCLMA2)
  TARG_ClearBitsInShort(ICCLMA2, INT_MSK_EIRFn|INT_MSK_EIMKn);
#endif
#if defined(SYST_WAKEUP_EVENT_INTCLMA3)
  TARG_ClearBitsInShort(ICCLMA2, INT_MSK_EIRFn|INT_MSK_EIMKn);
#endif
#if defined(SYST_WAKEUP_EVENT_INTVCPC0)
  TARG_ClearBitsInShort(ICVCPC0, INT_MSK_EIRFn|INT_MSK_EIMKn);
#endif
#if defined(SYST_WAKEUP_EVENT_INTVCPC1)
  TARG_ClearBitsInShort(ICVCPC1, INT_MSK_EIRFn|INT_MSK_EIMKn);
#endif
#if defined(SYST_WAKEUP_EVENT_INTTAUJ0I0)
  TARG_ClearBitsInShort(ICTAUJ0I0, INT_MSK_EIRFn|INT_MSK_EIMKn);
#endif
#if defined(SYST_WAKEUP_EVENT_INTTAUJ0I1)
  TARG_ClearBitsInShort(ICTAUJ0I1, INT_MSK_EIRFn|INT_MSK_EIMKn);
#endif
#if defined(SYST_WAKEUP_EVENT_INTTAUJ0I2)
  TARG_ClearBitsInShort(ICTAUJ0I2, INT_MSK_EIRFn|INT_MSK_EIMKn);
#endif
#if defined(SYST_WAKEUP_EVENT_INTTAUJ0I3)
  TARG_ClearBitsInShort(ICTAUJ0I3, INT_MSK_EIRFn|INT_MSK_EIMKn);
#endif
#if defined(SYST_WAKEUP_EVENT_INTTAUJ1I0)
  TARG_ClearBitsInShort(ICTAUJ1I0, INT_MSK_EIRFn|INT_MSK_EIMKn);
#endif
#if defined(SYST_WAKEUP_EVENT_INTTAUJ1I1)
  TARG_ClearBitsInShort(ICTAUJ1I1, INT_MSK_EIRFn|INT_MSK_EIMKn);
#endif
#if defined(SYST_WAKEUP_EVENT_INTTAUJ1I2)
  TARG_ClearBitsInShort(ICTAUJ1I2, INT_MSK_EIRFn|INT_MSK_EIMKn);
#endif
#if defined(SYST_WAKEUP_EVENT_INTTAUJ1I3)
  TARG_ClearBitsInShort(ICTAUJ1I3, INT_MSK_EIRFn|INT_MSK_EIMKn);
#endif
#if defined(SYST_WAKEUP_EVENT_INTADCA0ERR)
  TARG_ClearBitsInShort(ICADCA0ERR, INT_MSK_EIRFn|INT_MSK_EIMKn);
#endif
#if defined(SYST_WAKEUP_EVENT_INTADCA0I0)
  TARG_ClearBitsInShort(ICADCA0I0, INT_MSK_EIRFn|INT_MSK_EIMKn);
#endif
#if defined(SYST_WAKEUP_EVENT_INTADCA0I1)
  TARG_ClearBitsInShort(ICADCA0I1, INT_MSK_EIRFn|INT_MSK_EIMKn);
#endif
#if defined(SYST_WAKEUP_EVENT_INTADCA0I2)
  TARG_ClearBitsInShort(ICADCA0I2, INT_MSK_EIRFn|INT_MSK_EIMKn);
#endif
#if defined(SYST_WAKEUP_EVENT_INTADCA0LLT)
  TARG_ClearBitsInShort(ICADCA0LLT, INT_MSK_EIRFn|INT_MSK_EIMKn);
#endif
#if defined(SYST_WAKEUP_EVENT_INTTAUA0I0)
  TARG_ClearBitsInShort(ICTAUA0I0, INT_MSK_EIRFn|INT_MSK_EIMKn);
#endif
#if defined(SYST_WAKEUP_EVENT_INTTAUA0I1)
  TARG_ClearBitsInShort(ICTAUA0I1, INT_MSK_EIRFn|INT_MSK_EIMKn);
#endif
#if defined(SYST_WAKEUP_EVENT_INTTAUA0I2)
  TARG_ClearBitsInShort(ICTAUA0I2, INT_MSK_EIRFn|INT_MSK_EIMKn);
#endif
#if defined(SYST_WAKEUP_EVENT_INTTAUA0I3)
  TARG_ClearBitsInShort(ICTAUA0I3, INT_MSK_EIRFn|INT_MSK_EIMKn);
#endif
#if defined(SYST_WAKEUP_EVENT_INTTAUA0I4)
  TARG_ClearBitsInShort(ICTAUA0I4, INT_MSK_EIRFn|INT_MSK_EIMKn);
#endif
#if defined(SYST_WAKEUP_EVENT_INTTAUA0I5)
  TARG_ClearBitsInShort(ICTAUA0I5, INT_MSK_EIRFn|INT_MSK_EIMKn);
#endif
#if defined(SYST_WAKEUP_EVENT_INTTAUA0I6)
  TARG_ClearBitsInShort(ICTAUA0I6, INT_MSK_EIRFn|INT_MSK_EIMKn);
#endif
#if defined(SYST_WAKEUP_EVENT_INTTAUA0I7)
  TARG_ClearBitsInShort(ICTAUA0I7, INT_MSK_EIRFn|INT_MSK_EIMKn);
#endif
#if defined(SYST_WAKEUP_EVENT_INTTAUA0I8)
  TARG_ClearBitsInShort(ICTAUA0I8, INT_MSK_EIRFn|INT_MSK_EIMKn);
#endif
#if defined(SYST_WAKEUP_EVENT_INTTAUA0I9)
  TARG_ClearBitsInShort(ICTAUA0I9, INT_MSK_EIRFn|INT_MSK_EIMKn);
#endif
#if defined(SYST_WAKEUP_EVENT_INTTAUA0I10)
  TARG_ClearBitsInShort(ICTAUA0I10, INT_MSK_EIRFn|INT_MSK_EIMKn);
#endif
#if defined(SYST_WAKEUP_EVENT_INTTAUA0I11)
  TARG_ClearBitsInShort(ICTAUA0I11, INT_MSK_EIRFn|INT_MSK_EIMKn);
#endif
#if defined(SYST_WAKEUP_EVENT_INTTAUA0I12)
  TARG_ClearBitsInShort(ICTAUA0I12, INT_MSK_EIRFn|INT_MSK_EIMKn);
#endif
#if defined(SYST_WAKEUP_EVENT_INTTAUA0I13)
  TARG_ClearBitsInShort(ICTAUA0I13, INT_MSK_EIRFn|INT_MSK_EIMKn);
#endif
#if defined(SYST_WAKEUP_EVENT_INTTAUA0I14)
  TARG_ClearBitsInShort(ICTAUA0I14, INT_MSK_EIRFn|INT_MSK_EIMKn);
#endif
#if defined(SYST_WAKEUP_EVENT_INTTAUA0I15)
  TARG_ClearBitsInShort(ICTAUA0I15, INT_MSK_EIRFn|INT_MSK_EIMKn);
#endif

}

#endif /* (__REL_V850_DX4__ || __RH850_F1x__) && (SYST_DATA_SAVE_IN_RESET || SYST_DATA_SAVE_IN_DEEPSTOP) */


#ifdef SYST_F1x_DEEPSTOP_USED
/*----------------------------------------------------------------------------*/
/* Name : SYST_ConfigureWakeUpFactors                                         */
/* Role :                                                                     */
/* Interface : -                                                              */
/* Pre-condition :                                                            */
/* Constraints : -                                                            */
/*----------------------------------------------------------------------------*/
void SYST_ConfigureWakeUpFactors(void)
{
#ifndef  __CY_TV2__
  /* Clear all the wakeup factor
  WUFC0     - Wake-Up Factor Registers
  b31:b0      WUFy         - Indicates the generation of a wake-up event.  */
  TARG_WriteLong(SYST_WUFC0, SYST_WUFCx_CLEARED);

  /* Clear all the wakeup factor
  WUFC20    - Wake-Up Factor Registers
  b31:b0      WUFy         - Indicates the generation of a wake-up event.  */
  TARG_WriteLong(SYST_WUFC20, SYST_WUFCx_CLEARED);

  /* Clear all the wakeup factor
  WUFC_ISO0 - Wake-Up Factor Registers
  b31:b0      WUFy         - Indicates the generation of a wake-up event.  */
  TARG_WriteLong(SYST_WUFC_ISO0, SYST_WUFCx_CLEARED);

  /* Masked the interrupt of the unused wakeup factor, and Unmasked the interrupt of the wakeup factor.
  WUFMSK0   - Wake-Up Factor Mask Registers
  b31:b0      WUFMSKy      - Enables/disables a wake-up event. */
  TARG_WriteLong(SYST_WUFMSK0, SYST_WUFMSK0_FACTOR_1);       /* Wakeup factor 1   */
  TARG_WriteLong(SYST_WUFMSK20, SYST_WUFMSK20_FACTOR_2);        /* Wakeup factor 2    */
  TARG_WriteLong(SYST_WUFMSK_ISO0, SYST_WUFMSK_ISO0_FACTOR_1);   /* Wakeup factor 1_ISO  */
#endif

}

/*----------------------------------------------------------------------------*/
/* Name : SYST_ClearWakeUpEventInterrupt                                      */
/* Role :                                                                     */
/* Interface : -                                                              */
/* Pre-condition :                                                            */
/* Constraints : -                                                            */
/*----------------------------------------------------------------------------*/
void SYST_ClearWakeUpEventInterrupt(void)
{
/*Wake-Up Factor 1 */
#ifdef SYST_WAKEUP_EVENT_INTLVIL
  TARG_ClearBitsInShort(ECON_FEINTFEINTFC, INT_MSK_EIP0n);
  TARG_ClearBitsInShort(ECON_FEINTFEINTFMSK, INT_MSK_EIP0n);
#endif
#ifdef SYST_WAKEUP_EVENT_INTP0
  TARG_ClearBitsInShort(INTC2ICP0, INT_MSK_EIRFn|INT_MSK_EIMKn);
#endif
#ifdef SYST_WAKEUP_EVENT_INTP1
  TARG_ClearBitsInShort(INTC2ICP1, INT_MSK_EIRFn|INT_MSK_EIMKn);
#endif
#ifdef SYST_WAKEUP_EVENT_INTP2
  TARG_ClearBitsInShort(INTC2ICP2, INT_MSK_EIRFn|INT_MSK_EIMKn);
#endif
#ifdef SYST_WAKEUP_EVENT_INTWDTA0
  TARG_ClearBitsInShort(INTC2ICWDTA0, INT_MSK_EIRFn|INT_MSK_EIMKn);
#endif
#ifdef SYST_WAKEUP_EVENT_INTP3
  TARG_ClearBitsInShort(INTC2ICP3, INT_MSK_EIRFn|INT_MSK_EIMKn);
#endif
#ifdef SYST_WAKEUP_EVENT_INTP4
  TARG_ClearBitsInShort(INTC2ICP4, INT_MSK_EIRFn|INT_MSK_EIMKn);
#endif
#ifdef SYST_WAKEUP_EVENT_INTP5
  TARG_ClearBitsInShort(INTC2ICP5, INT_MSK_EIRFn|INT_MSK_EIMKn);
#endif
#ifdef SYST_WAKEUP_EVENT_INTP10
  TARG_ClearBitsInShort(INTC2ICP10, INT_MSK_EIRFn|INT_MSK_EIMKn);
#endif
#ifdef SYST_WAKEUP_EVENT_INTP11
  TARG_ClearBitsInShort(INTC2ICP11, INT_MSK_EIRFn|INT_MSK_EIMKn);
#endif
#ifdef SYST_WAKEUP_EVENT_INTTAUJ0I0
  TARG_ClearBitsInShort(INTC2ICTAUJ0I0, INT_MSK_EIRFn|INT_MSK_EIMKn);
#endif
#ifdef SYST_WAKEUP_EVENT_INTTAUJ0I1
  TARG_ClearBitsInShort(INTC2ICTAUJ0I1, INT_MSK_EIRFn|INT_MSK_EIMKn);
#endif
#ifdef SYST_WAKEUP_EVENT_INTTAUJ0I2
  TARG_ClearBitsInShort(INTC2ICTAUJ0I2, INT_MSK_EIRFn|INT_MSK_EIMKn);
#endif
#ifdef SYST_WAKEUP_EVENT_INTTAUJ0I3
  TARG_ClearBitsInShort(INTC2ICTAUJ0I3, INT_MSK_EIRFn|INT_MSK_EIMKn);
#endif
#ifdef SYST_WAKEUP_EVENT_INTP6
  TARG_ClearBitsInShort(INTC2ICP6, INT_MSK_EIRFn|INT_MSK_EIMKn);
#endif
#ifdef SYST_WAKEUP_EVENT_INTP7
  TARG_ClearBitsInShort(INTC2ICP7, INT_MSK_EIRFn|INT_MSK_EIMKn);
#endif
#ifdef SYST_WAKEUP_EVENT_INTP8
  TARG_ClearBitsInShort(INTC2ICP8, INT_MSK_EIRFn|INT_MSK_EIMKn);
#endif
#ifdef SYST_WAKEUP_EVENT_INTP12
  TARG_ClearBitsInShort(INTC2ICP12, INT_MSK_EIRFn|INT_MSK_EIMKn);
#endif
#ifdef SYST_WAKEUP_EVENT_INTP9
  TARG_ClearBitsInShort(INTC2ICP9, INT_MSK_EIRFn|INT_MSK_EIMKn);
#endif
#ifdef SYST_WAKEUP_EVENT_INTP13
  TARG_ClearBitsInShort(INTC2ICP13, INT_MSK_EIRFn|INT_MSK_EIMKn);
#endif
#ifdef SYST_WAKEUP_EVENT_INTP14
  TARG_ClearBitsInShort(INTC2ICP14, INT_MSK_EIRFn|INT_MSK_EIMKn);
#endif
#ifdef SYST_WAKEUP_EVENT_INTP15
  TARG_ClearBitsInShort(INTC2ICP15, INT_MSK_EIRFn|INT_MSK_EIMKn);
#endif
#ifdef SYST_WAKEUP_EVENT_INTRTCA01S
  TARG_ClearBitsInShort(INTC2ICRTCA01S, INT_MSK_EIRFn|INT_MSK_EIMKn);
#endif
#ifdef SYST_WAKEUP_EVENT_INTRTCA0AL
  TARG_ClearBitsInShort(INTC2ICRTCA0AL, INT_MSK_EIRFn|INT_MSK_EIMKn);
#endif
#ifdef SYST_WAKEUP_EVENT_INTRTCA0R
  TARG_ClearBitsInShort(INTC2ICRTCA0R, INT_MSK_EIRFn|INT_MSK_EIMKn);
#endif
#ifdef SYST_WAKEUP_EVENT_INTDCUTDI
  TARG_ClearBitsInShort(INTC1ICDCUTDI, INT_MSK_EIRFn|INT_MSK_EIMKn);
#endif
/*End of Wake-Up Factor 1 Register */
}
#endif /*SYST_F1x_DEEPSTOP_USED*/



#if defined(__REL_V850_DJ4_HE__) || \
    defined(__REL_V850_DN4H__)
/*----------------------------------------------------------------------------*/
/* Name : SYST_GoIntoStopMode                                                 */
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
void SYST_GoIntoStopMode(void)
{
  volatile ulong regValue;
  ubyte INTP_Flag = 1;


#ifdef WDTD_Refresh
  WDTD_Refresh();
#endif /* WDTD_Refresh */


  /*----------------------*/
  /* DEEPSTOP Preparation */
  /*----------------------*/
  /* STEP 1: Stop interrupt activities and clear interrupt flags */
  DisableAllInterrupts();

#if defined(__REL_V850_Dx4__) && (defined(SYST_DATA_SAVE_IN_RESET) || defined(SYST_DATA_SAVE_IN_DEEPSTOP))
  /* STEP 2: Configure wake-up factor */
  SYST_ConfigureWakeUpFactors();


  /* STEP 3: Clear Interrupt flags for the Wakeup Factors */
  SYST_ClearWakeUpEventInterrupt();
#endif

  /* STEP 4: Check for Early wakeup */
  INTP_Flag = SSCS_CheckEarlyUp();


#ifdef SYST_SOFTRESETCHECK_BEFORE_DEEPSTOP
  /* First Check before turn OFF unessential clock, if some input signal is not on ISO0 CLK */
  SYST_Config_SoftResetCheck();
#endif /* SYST_SOFTRESETCHECK_BEFORE_DEEPSTOP */

  /* STEP 5: Prepare Iso0 and AWO clocks */
#ifdef SYST_PREPARE_CLK_SELECTOR_CFG
  SYST_ClockSelectorConfigSleep();  /* Could be put another macro */
#endif /* SYST_PREPARE_CLK_SELECTOR_CFG */


  /*-----------------------------------*/
  /* DEEPSTOP execution with wait time */
  /*-----------------------------------*/
  /* STEP 6: Set Iso1 DEEPSTOP */

  while(!(TARG_ReadLong(PWS1) & SBC_MSK_PWSnPSS) || (TARG_ReadLong(PWS1) & SBC_MSK_PWSnISO))
  {
    regValue = TARG_ReadLong(PSC1);
    do
    {
      TARG_ProtWriteLong(PROTCMD2, PSC1, regValue | (SBC_MSK_PSCnSTP | SBC_MSK_PSCnPOF | SBC_MSK_PSCnREGSTP | SBC_MSK_PSCnIOHLDMSK));
    } while(TARG_ReadLong(PROTS2));
  }


  /* STEP 7: Stop PLLk */
  /* Make sure that the PLL0 is stopped */
  if (TARG_ReadBitInLong(PLLS0,CLO_BIT_nCLKEN))
  {
    /* Wait for PLL0 enable status bit */
    do {
      regValue = TARG_ReadLong(PLLE0) | CLO_MSK_nDISTRG;
      TARG_ProtWriteLong(PROTCMD2, PLLE0, regValue);
    } while (TARG_ReadBitInLong(PLLS0,CLO_BIT_nCLKEN));
  }
  /* Make sure that the PLL1 is stopped */
  if (TARG_ReadBitInLong(PLLS1,CLO_BIT_nCLKEN))
  {
    /* Wait for PLL1 enable status bit */
    do {
      regValue = TARG_ReadLong(PLLE1) | CLO_MSK_nDISTRG;
      TARG_ProtWriteLong(PROTCMD2, PLLE1, regValue);
    } while (TARG_ReadBitInLong(PLLS1,CLO_BIT_nCLKEN));
  }


  #ifndef __REL_V850_DK4__
  /* Make sure that the PLL2 is stopped */
  if (TARG_ReadBitInLong(PLLS2,CLO_BIT_nCLKEN))
  {
    /* Wait for PLL2 enable status bit */
    do {
      regValue = TARG_ReadLong(PLLE2) | CLO_MSK_nDISTRG;
      TARG_ProtWriteLong(PROTCMD2, PLLE2, regValue);
    } while (TARG_ReadBitInLong(PLLS2,CLO_BIT_nCLKEN));
  }
  #endif /* !__REL_V850_DK4__ */


#ifdef SYST_SOFTRESETCHECK_BEFORE_DEEPSTOP
  /* Second Check before Turn OFF ISO 0*/
  SYST_Config_SoftResetCheck();
#endif /* SYST_SOFTRESETCHECK_BEFORE_DEEPSTOP */


  /* STEP 8: Reset in case of early wakup */
  if(INTP_Flag == 0)
  {
   INTP_Flag = 1;
   #pragma asm
    mov 0x0, r1
    jmp [r1]
   #pragma endasm
  }


  /* STEP 9: Set Iso0 DEEPSTOP */
  if(TARG_ReadLong(WUFL0) == 0
  && TARG_ReadLong(WUFM0) == 0
  && TARG_ReadLong(WUFH0) == 0 )
  {
    TARG_ProtWriteLong(PROTCMD2, PSC0, SBC_MSK_PSCnSTP | SBC_MSK_PSCnPOF | SBC_MSK_PSCnREGSTP | SBC_MSK_PSCnIOHLDMSK);
  }
  /* wait wakeup event */
  /* Evaluate Stop mode end */
  while (!(TARG_ReadLong(PWS0) & SBC_MSK_PWSnPSS))
  {
    continue;
  }
  /* Perform a software reset if early wake-up occurs */
   #pragma asm
   mov 0x0, r1
   jmp [r1]
   #pragma endasm
}
#endif /* defined(__REL_V850_DJ4_HE__) || \
          defined(__REL_V850_DN4H__) */


/* ______ L O C A L - F U N C T I O N S ______________________________________*/

#if defined(Syst_CRC16_CCITT)
/*----------------------------------------------------------------------------*/
/*Name : Syst_UpdateCrc16Ccitt                                                */
/*Role : calculates a new CRC16-CCITT value based on the previous             */
/*       value of the CRC and the next byte of the data to be checked.        */
/*Interface :                                                                 */
/*    IN InputData  : previous crc value                                      */
/*    IN InputData  : next byte of the data to be checked                     */
/*    OUT return value : new CRC16_CCITT value                                */
/*Pre-condition : none                                                        */
/*Constraints : none                                                          */
/*Behaviour :                                                                 */
/*DO                                                                          */
/*  [ Update CRC with incoming data flow  ]                                   */
/*OD                                                                          */
/*----------------------------------------------------------------------------*/
static ushort Syst_UpdateCrc16Ccitt(ushort crc, ubyte data)
{
  bitfield_short_t data16High;
  ubyte i;

  data16High._byte.low  = 0;
  data16High._byte.high = data;

  crc  = (ushort) (crc ^ data16High._short);

  for (i=0;i<8;i++)
  {
    if (crc & 0x8000)
    {
      crc = (crc << 1) ^ Syst_POLYNOM_CCITT;
    }
    else
    {
      crc = (crc << 1);
    }
  }

  return (crc);
}
#endif /* Syst_CRC16_CCITT  */


#if defined(Syst_CRC32)
/*----------------------------------------------------------------------------*/
/* Name: Syst_reflect                                                         */
/* Role:  Reorder the bits of a binary sequence, by reflecting                */
/*        them about the middle position.                                     */
/* Interface: data    IN address of data                                      */
/*            nBits   IN datas size                                           */
/*            Result  OUT The reflection of the original data.                */
/* Pre-condition: none                                                        */
/* Constraints:   No checking is done that nBits <= 32.                       */
/* Behavior:                                                                  */
/*   DO                                                                       */
/*    [ compute data reflection / mirror ]                                    */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/
static ulong Syst_reflect( ulong data, ubyte nBits )
{
  ulong  reflection = 0x00000000;
  ubyte  bit;

  /* Reflect the data about the center bit. */
  for (bit = 0; bit < nBits; bit++)
  {
    /* If the LSB bit is set, set the reflection of it. */
    if (data & 0x01)
    {
      reflection |= (ulong)(((ulong)1) << ((nBits - 1) - bit));
    }

    data = (ulong)(data >> 1);
  }

  return (reflection);
}
#endif /* Syst_CRC32  */

#ifdef SYST_F1x_DEEPSTOP_USED
/*----------------------------------------------------------------------------*/
/* Function Name : void SYST_ShiftDeepStop( void )                             */
/* Description   : This function shifts to DEEPSTOP mode.                     */
/* Argument      : none                                                       */
/* Return Value  : none                                                       */
/*----------------------------------------------------------------------------*/
void SYST_ShiftDeepStop( void )
{
#ifndef  __CY_TV2__
#ifdef WDTD_Refresh
  WDTD_Refresh();
#endif /* WDTD_Refresh */
  /*----------------------*/
  /* DEEPSTOP Preparation */
  /*----------------------*/
  /* STEP 1: Stop interrupt activities and clear interrupt flags */
  Poly_DisableAllInterrupts();

#ifdef SYST_F1x_DEEPSTOP_USED
    IODC_SetupWakeUpIntPn();
#endif
  /* STEP 2: Configure wake-up factor */
  SYST_ConfigureWakeUpFactors();

  /* STEP 3: Clear Interrupt flags for the Wakeup Factors */
  SYST_ClearWakeUpEventInterrupt();

  /* STEP 4: Check KL15  state */
  Wkss_KL15WakeUpPin();

  TARG_WriteLong(RESCTLRESFC, RESCTLRESF);

  /* STEP 5:Set the clock stop mask and select the clock domains to be stopped and to continue operating.*/
  CPUS_PrepareClockSelectorBeforeSleep();

  /* STEP 6: Shift to DEEPSTOP mode
  STBC0PSC  - Power Save Control Register
  b31:b2                   - Reserved set to 0
  b 1         STBC0DISTRG  - DEEPSTOP mode is entered. Set to 1
  b 0                      - Reserved set to 0 */
  if((TARG_ReadLong(SYST_WUF0) == 0) && (TARG_ReadLong(SYST_WUF20) == 0))
  {

    TARG_ProtWriteLong_Port(WPROTRPROTCMD0,WPROTRPROTS0,STBC0PSC, SYST_DEEPSTOP_ACT);

  }
  else
  {
    SYST_Reset();
  }
#else
    Cy_SysPm_DeepSleep(CY_SYSPM_WAIT_FOR_INTERRUPT);
#endif
}
#endif


#ifndef __BOOT_LINK__
/*----------------------------------------------------------------------------*/
/* Name           : SYST_ComputeHWCRC16Ccitt                                  */
/* Role           :                                                           */
/* Interface      :                                                           */
/* Returns:       : none                                                      */
/* Pre-condition  :                                                           */
/* Constraints    :                                                           */
/*----------------------------------------------------------------------------*/
ushort SYST_ComputeHWCRC16Ccitt(ubyte *crc16_address, ushort crc16_size)
{
  ubyte *syst_crc16_data = crc16_address;
  ushort syst_crc16 = 0;
  ulong  syst_counter = 0;

#ifdef  __CY_TV2__
#if !defined(__CORE_CM0P__)
  syst_crc16 = SYST_RunCRC16CCITT(crc16_address, crc16_size);
#endif
#else
  /*16 bit polynomial, and input 16bit each time*/
  DCRA0CTL = (SYST_CRC_Input_Width_8bit << 1) | SYST_CRC_Method_16bit;

  /*Initial Output*/
  DCRA0COUT = SYST_CRC_Output_Initial_16bit;
  for (; syst_counter < crc16_size; (syst_counter+=1))
  {
	  DCRA0CIN = syst_crc16_data[syst_counter];
  }

  syst_crc16 = DCRA0COUT;
#endif

  return (ushort)syst_crc16;
}

/*----------------------------------------------------------------------------*/
/* Name           : SYST_ComputeHWCRC32                                       */
/* Role           :                                                           */
/* Interface      :                                                           */
/* Returns:       : none                                                      */
/* Pre-condition  :                                                           */
/* Constraints    :                                                           */
/*----------------------------------------------------------------------------*/
ulong SYST_ComputeHWCRC32(ubyte *crc32_address, ushort crc32_size)
{
  ulong *syst_crc32_data = (ulong *)crc32_address;
  static ulong syst_crc32 = 0;
  ulong syst_counter = 0;
#ifdef  __CY_TV2__
#if !defined(__CORE_CM0P__)
  syst_crc32 = SYST_RunCRC32(crc32_address, crc32_size);
#endif
#else
#ifndef __POLYSPACE__
  /*32 bit polynomial, and input 32bit each time*/
  DCRA0CTL = (SYST_CRC_Input_Width_32bit << 1) | SYST_CRC_Method_32bit;
  /* Initial Output*/
  DCRA0COUT = SYST_CRC_Output_Initial_32bit;

  for (; syst_counter < crc32_size / 4; (syst_counter+=1))
  {
    DCRA0CIN = syst_crc32_data[syst_counter];
  }
  syst_crc32 = DCRA0COUT;

  /*32 bit polynomial, and input 32bit each time*/
  DCRA0CTL = (SYST_CRC_Input_Width_8bit << 1) | SYST_CRC_Method_32bit;

  /* Initial Output*/
  DCRA0COUT = ~syst_crc32;/*The read value of this register is a value obtained by performing EXOR
                          calculation for the following value*/
  syst_counter *=4;
  for (; syst_counter < crc32_size; (syst_counter+=1))
  {
    DCRA0CIN = crc32_address[syst_counter];
  }
  syst_crc32 = DCRA0COUT;
#endif
#endif
  return syst_crc32;
}

#ifndef  __CY_TV2__
/*----------------------------------------------------------------------------*/
/* Name           : SYST_GetChipProductName                                   */
/* Role           :                                                           */
/* Interface      :                                                           */
/* Returns:       : none                                                      */
/* Pre-condition  :                                                           */
/* Constraints    :                                                           */
/*----------------------------------------------------------------------------*/
void SYST_GetChipProductName(sbyte* product_name)
{
  ubyte product_index = 0 ;
  if(product_name != NULL)
  {
    for(product_index=0;product_index<SYST_FOUR_BYTE;product_index++)
    {
      product_name[product_index]= (char)((SCDSPRDNAME1 >> (product_index*SYST_SHIFT_TWO_BYTE)) & SYST_PRODUCT_NAME_MASK);
    }

    for(product_index = SYST_FOUR_BYTE;product_index<SYST_EIGHT_BYTE;product_index++)
    {
      product_name[product_index]= (char)((SCDSPRDNAME2 >> ((product_index-SYST_FOUR_BYTE)*SYST_SHIFT_TWO_BYTE)) & SYST_PRODUCT_NAME_MASK);
    }

    for(product_index = SYST_EIGHT_BYTE;product_index<SYST_NINE_BYTE;product_index++)
    {
      product_name[product_index]= (char)((SCDSPRDNAME3 >> ((product_index-SYST_EIGHT_BYTE)*SYST_SHIFT_TWO_BYTE)) & SYST_PRODUCT_NAME_MASK);
    }
  }
}
#endif/*  __CY_TV2__*/
#endif  /*__BOOT_LINK__*/


/*----------------------------------------------------------------------------*/
/*Name : SYST_SetResetCounterAndSetFlag                                       */
/*Role : Give the reset type                                                  */
/*Interface :                                                                 */
/*   IN : -                                                                   */
/*  OUT : -ResetType                                                          */
/*Pre-condition : -                                                           */
/*Constraints : -                                                             */
/* Behavior:                                                                  */
/*   DO                                                                       */
/*    [ return the cause of reset ]                                           */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/
void SYST_SetResetCounterAndSetFlag(void)
{
#ifndef __CY_TV2__
#ifdef SYST_UseEMMCRecoverLogic
  ubyte buf[1]={0};
#endif  /*SYST_UseEMMCRecoverLogic*/
#ifdef SYST_LimitSystemResetTimeLogic
  ubyte bufTotal[1]={0};
#endif  /*SYST_LimitSystemResetTimeLogic*/
  ulong Reg;
#ifndef __BOOT_LINK__
  Reg = TARG_ReadLong(RESCTLRESF);
#ifdef SYST_UseEMMCRecoverLogic
  /*Older versions of the software modify variables in backram and need to be reinitialized*/
  if((SystInitializeBackRamFlag != 0xA5A5A5A5) || (SystInitializeBackRamFlagComp != (~(SystInitializeBackRamFlag))))
  {
    SYST_SetSWResetCounterTotal(0);
    SYST_SetSWResetCounter(0);
    SYST_SetEmmcRecoveryStrategyFlag(FALSE);
    SystSWResetCounterCRC = 0;
    SystInitializeBackRamFlag = 0xA5A5A5A5;
    SystInitializeBackRamFlagComp=(~(SystInitializeBackRamFlag));
  }
#endif  /*SYST_UseEMMCRecoverLogic*/
  /*based on KL30/KL15, limit system reset time:
  increase reset counter when system reset.*/
  if(Reg & SYST_MSK_BIT0)
  {
#ifdef SYST_UseEMMCRecoverLogic
    SystSWResetCounter++;
#endif /*SYST_UseEMMCRecoverLogic*/
#ifdef SYST_LimitSystemResetTimeLogic
    SystSWResetCounterTotal++;
#endif /*SYST_LimitSystemResetTimeLogic*/
  }
  /* MCU Check Startup Type:if(startup type = power on) OR (start up type = External Reset )*/
  if ( (Reg & SYST_MSK_BIT9) || (Reg & SYST_MSK_BIT8 ) )
  {
#ifdef SYST_UseLowVolBlockingLogic
    /*Set CheckVoltage Flag = TRUE in Ram*/
    SYST_SetKL30OffOnOrExternResetFlag(TRUE);
#endif
    /*the reset counter shall be cleared: KL30 OFF->ON OR KL15 OFF->ON*/
    if(Reg & SYST_MSK_BIT9)
    {
#ifdef SYST_LimitSystemResetTimeLogic
      SYST_SetSWResetCounterTotal(0);
#endif /*SYST_LimitSystemResetTimeLogic*/
#ifdef SYST_UseEMMCRecoverLogic
      SYST_SetSWResetCounter(0);
      /*MCU detected abnormal KL30 OFF*/
      SYST_SetKL30OffOnFlag(TRUE);
#endif /*SYST_UseEMMCRecoverLogic*/
    }
  }
#ifdef SYST_UseEMMCRecoverLogic
  buf[0] =  (ubyte) (SystSWResetCounter & 0xffu);
  SystSWResetCounterCRC= SYST_ComputeHWCRC16Ccitt(buf,1);
#endif /*SYST_UseEMMCRecoverLogic*/
#ifdef SYST_LimitSystemResetTimeLogic
  bufTotal[0] =  (ubyte) (SystSWResetCounterTotal & 0xffu);
  SystSWResetCounterTotalCRC= SYST_ComputeHWCRC16Ccitt(bufTotal,1);
#endif /*SYST_LimitSystemResetTimeLogic*/

#endif  /*__BOOT_LINK__*/
#endif /*__CY_TV2__*/
}

#ifdef SYST_UseEMMCRecoverLogic
/*----------------------------------------------------------------------------*/
/* Name           : SYST_GetKL30OffOnFlag                                     */
/* Role           :                                                           */
/* Interface      :                                                           */
/* Returns:       : none                                                      */
/* Pre-condition  :                                                           */
/* Constraints    :                                                           */
/*----------------------------------------------------------------------------*/
bool_t SYST_GetKL30OffOnFlag(void)
{
  return KL30_OffOnFlag;
}

/*----------------------------------------------------------------------------*/
/* Name           : SYST_SetKL30OffOnFlag                                     */
/* Role           :                                                           */
/* Interface      :                                                           */
/* Returns:       : none                                                      */
/* Pre-condition  :                                                           */
/* Constraints    :                                                           */
/*----------------------------------------------------------------------------*/
void SYST_SetKL30OffOnFlag( bool_t value)
{
  KL30_OffOnFlag = value;
}

/*----------------------------------------------------------------------------*/
/* Name           : SYST_GetSWResetCounter                                    */
/* Role           :                                                           */
/* Interface      :                                                           */
/* Returns:       : none                                                      */
/* Pre-condition  :                                                           */
/* Constraints    :                                                           */
/*----------------------------------------------------------------------------*/
ubyte SYST_GetSWResetCounter(void)
{
  ulong SystGetSWResetCounterCrc=0;
  ubyte buf[1]={0};
  buf[0] =  (ubyte) (SystSWResetCounter & 0xffu);
  SystGetSWResetCounterCrc = SYST_ComputeHWCRC16Ccitt(buf,1);
  if(SystGetSWResetCounterCrc !=SystSWResetCounterCRC)
  {
    SystSWResetCounter = 0;
  }
  return SystSWResetCounter;
}
/*----------------------------------------------------------------------------*/
/* Name           : SYST_SetSWResetCounter                                    */
/* Role           :                                                           */
/* Interface      :                                                           */
/* Returns:       : none                                                      */
/* Pre-condition  :                                                           */
/* Constraints    :                                                           */
/*----------------------------------------------------------------------------*/
void SYST_SetSWResetCounter( ubyte value)
{
  ubyte buf[1]={0};
  SystSWResetCounter = value;
  buf[0] =  (ubyte) (SystSWResetCounter & 0xffu);
  SystSWResetCounterCRC= SYST_ComputeHWCRC16Ccitt(buf,1);
}

/*----------------------------------------------------------------------------*/
/* Name           : SYST_GetEmmcRecoveryStrategyFlag                          */
/* Role           :                                                           */
/* Interface      :                                                           */
/* Returns:       : none                                                      */
/* Pre-condition  :                                                           */
/* Constraints    :                                                           */
/*----------------------------------------------------------------------------*/
bool_t SYST_GetEmmcRecoveryStrategyFlag(void)
{
  return EmmcRecoveryStrategyFlag;
}

/*----------------------------------------------------------------------------*/
/* Name           : SYST_SetEmmcRecoveryStrategyFlag                          */
/* Role           :                                                           */
/* Interface      :                                                           */
/* Returns:       : none                                                      */
/* Pre-condition  :                                                           */
/* Constraints    :                                                           */
/*----------------------------------------------------------------------------*/
void SYST_SetEmmcRecoveryStrategyFlag( bool_t value)
{
  EmmcRecoveryStrategyFlag = value;
}
#endif /*SYST_UseEMMCRecoverLogic*/

#ifdef SYST_UseLowVolBlockingLogic
/*----------------------------------------------------------------------------*/
/* Name           : SYST_GetKL30OffOnOrExternResetFlag                        */
/* Role           :                                                           */
/* Interface      :                                                           */
/* Returns:       : none                                                      */
/* Pre-condition  :                                                           */
/* Constraints    :                                                           */
/*----------------------------------------------------------------------------*/
bool_t SYST_GetKL30OffOnOrExternResetFlag(void)
{
  return CheckVoltageFlag;
}

/*----------------------------------------------------------------------------*/
/* Name           : SYST_SetKL30OffOnOrExternResetFlag                        */
/* Role           :                                                           */
/* Interface      :                                                           */
/* Returns:       : none                                                      */
/* Pre-condition  :                                                           */
/* Constraints    :                                                           */
/*----------------------------------------------------------------------------*/
void SYST_SetKL30OffOnOrExternResetFlag( bool_t value)
{
  CheckVoltageFlag = value;
}
#endif  /*SYST_UseLowVolBlockingLogic*/


/*----------------------------------------------------------------------------*/
/* Name           : SYST_GetSWResetCounterTotal                               */
/* Role           :                                                           */
/* Interface      :                                                           */
/* Returns:       : none                                                      */
/* Pre-condition  :                                                           */
/* Constraints    :                                                           */
/*----------------------------------------------------------------------------*/
ubyte SYST_GetSWResetCounterTotal(void)
{
#ifdef SYST_LimitSystemResetTimeLogic
  ulong SystGetSWResetCounterCrc=0;
  ubyte buf[1]={0};
  buf[0] =  (ubyte) (SystSWResetCounterTotal & 0xffu);
  SystGetSWResetCounterCrc = SYST_ComputeHWCRC16Ccitt(buf,1);
  if(SystGetSWResetCounterCrc !=SystSWResetCounterTotalCRC)
  {
    SystSWResetCounterTotal = 0;
  }
  return SystSWResetCounterTotal;
#else
  return 0;
#endif /*SYST_LimitSystemResetTimeLogic*/
}
/*----------------------------------------------------------------------------*/
/* Name           : SYST_SetSWResetCounterTotal                               */
/* Role           :                                                           */
/* Interface      :                                                           */
/* Returns:       : none                                                      */
/* Pre-condition  :                                                           */
/* Constraints    :                                                           */
/*----------------------------------------------------------------------------*/
void SYST_SetSWResetCounterTotal( ubyte value)
{
#ifdef SYST_LimitSystemResetTimeLogic
  ubyte buf[1]={0};
  SystSWResetCounterTotal = value;
  buf[0] =  (ubyte) (SystSWResetCounterTotal & 0xffu);
  SystSWResetCounterTotalCRC= SYST_ComputeHWCRC16Ccitt(buf,1);
#endif /*SYST_LimitSystemResetTimeLogic*/
}

/*_____ E N D _____ (syst.c) _________________________________________________*/
