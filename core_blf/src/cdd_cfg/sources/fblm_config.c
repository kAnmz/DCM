/******************************************************************************/
/* @F_NAME :          fblm_config.c                                           */
/* @F_PURPOSE :       manage reprogramming for MCU                            */
/* @F_CREATED_BY :    Jianhua.Wu  			                                  */
/* @F_CREATION_DATE : 2021.07.14                                              */
/* @F_LANGUAGE :      ANSI C                                                  */
/* @F_MPROC_TYPE :    target independent           						      */
/*************************************** (C) Copyright 2021 Marelli ***********/
/*______ I N C L U D E - F I L E S ___________________________________________*/
#include "fblm_config.h"
#include "fblm_diag.h"
#include "fblm_priv.h"
#ifdef EEPC_FUN_ENABLE
#include "eepc.h"
#include "eepio_config.h"
#endif
#include "cy_project.h"
#include "cy_flash.h"//delete
#include "Fee_30_FlexNor.h"
#include "Nvm.h"
#include "Nvm_Cfg.h"
#include "vers_config_swid.h"
#include "stdlib.h"
#include "spid.h"
#include "SbcM.h"
#include "rsam.h"
#include "mcwdt_config.h"
#include "wdfs_config_dynamic.h"
#include "vers_config.h"
#include "cy_canfd.h"
#include "fblm_main.h"
#include "MemAcc.h"
/*______ L O C A L - D E F I N E S ___________________________________________*/
#define BootFlag  (*((uint32*)0x0801F240)) /*in RRAM*/

/*DID List*/
#define Fblm_Public_Key_Did_D01C                             0xD01C
#define Fblm_SecurityConstantLevel_F109                      0xF109  /*Only for secondary boot*/
#define Fblm_PrimaryBootDiagDataPN_Did_F121                  0xF121
#define Fblm_SecondaryBootDiagDataPN_Did_F122                0xF122  /*Only for secondary boot*/
#define Fblm_SecondaryBootSwPN_Did_F124                      0xF124  /*Only for secondary boot*/
#define Fblm_PrimaryBootSwPN_Did_F125                        0xF125
#define Fblm_EcuCoreAssemblPN_Did_F12A                       0xF12A
#define Fblm_EcuDeliveryAssemblyPN_Did_F12B                  0xF12B
#define Fblm_ActiveDiagSession_Did_F186                      0xF186
#define Fblm_SystemSupplierIdentifier_Did_F18A               0xF18A
#define Fblm_EcuSerialNum_Did_F18C                           0xF18C
#define Fblm_PrimaryBootDiagDataPN_Geely_Did_F1A1            0xF1A1
#define Fblm_SecondaryBootDiagDataPN_Geely_Did_F1A2          0xF1A2  /*Only for secondary boot*/
#define Fblm_PrimaryBootDiagSwPN_Geely_Did_F1A5              0xF1A5
#define Fblm_EcuCoreAssemblyPN_Geely_Did_F1AA                0xF1AA
#define Fblm_EcuDeliveryAssemblyPN_Geely_Did_F1AB            0xF1AB

#define Fblm_Primary_Bootloader_Version_F1FA                 0xF1FA
/* Composite DID List */
#define Fblm_Complete_ECU_Part_Serial_Number_s_PBL_Geely_Did_ED20                 0xED20
#define Fblm_Complete_ECU_Part_Serial_Number_s_Did_EDA0                           0xEDA0

#define Fblm_WDFC_ID_BOOT_DATA_Length                40
#define Fblm_WDFC_ID_BOOT_SW_FRINGER_Length          16
#define Fblm_WriteDoneDelayTime                1000 /*ms*/

#define BootCommand  (*((uint32*)0x0801F200)) /*in RRAM*/
#define SeedBackupRam (*((uint32*)0x0801F244)) /*in RRAM*/
#define SeedCntBackupRam (*((uint32*)0x0801F248)) /*in RRAM, monotonic seed-generation counter*/

#define FBLM_Command_ToAPP  ((uint32) 0x00000000)
#define FBLM_Command_ToBoot  ((uint32) 0xA5A5A5A5)

#define CY_SYS_PWR_CTL_KEY_OPEN  (0x05FAUL)
#define CY_SYS_PWR_CTL_KEY_CLOSE (0xFA05UL)
/* #define CORTEX_M4_APPL_ADDR  0x10028800 */
#define CORTEX_M4_APPL_ADDR     (0x10029400)

#define FBLM_CODEFLASH_ADDRESS  (*((Fblm_PartNumber_t*)((uint32)&__ghsbegin_EOLStartFlag[0])))
#define EOL_CHECKEOLDONE (*((Fblm_CodeFlashSector_RAMAdrTbl[Fblm_EolDoneID].Address_CodeFlash)))
/*______ L O C A L - T Y P E S _______________________________________________*/

/*______ G L O B A L - D A T A _______________________________________________*/
uint8 NVMM_PublicKeyStatusDidStatus;
uint8 NVMM_BootDataStatusDidStatus;
uint8 NVMM_EcuRdiProgramDidStatus;
uint8 NVMM_IdIdoptionSecurity;
uint8 NVMM_PartNumberGeelyDidStatus;

uint8 Fblm_RunningCheckVerificationStatus = FALSE;

/* NvM Variable */
uint8 Fblm_ReadWriteNvmBlockData[Fblm_ReadWriteNvmBlockDataMaxLen];
uint8 Fblm_AsyncWriteNvmBlockDataBuf[Fblm_ReadWriteNvmBlockDataMaxLen];
Fblm_WriteQueueBufferAttribute Fblm_AsyncWriteNvmBlockData[Fblm_AsyncWriteQueueNumber];
uint8 Fblm_AsyncWriteReqStep;
uint8 Fblm_AsyncWriteCurrentNvMBlockId = 0u;
uint8 Fblm_CurrentNvMBlockId = 0u;
boolean Fblm_IsReadWriteNvmBlock = FALSE;
boolean Fblm_IsReadNvmBlock = FALSE;
boolean Fblm_IsAsyncWriteNvmBlock = FALSE;
boolean Fblm_IsAsyncWriteNvmBlockhandle = FALSE;
uint16 Fblm_DiagRespDataLen = 0;
uint8 *Fblm_DiagData = NULL;



uint8 Fblm_AppVerificationBlockTable[FBLM_VBT_SIZE] = {0};
uint16 Fblm_AppVerificationBlockTableLength = FBLM_VBT_SIZE;
ubyte Fblm_SecurityConstantLevel[16] = {0};
ubyte Fblm_PublicKeyData[256] = {0};
ubyte Fblm_PublicKeyExponent[4] = {0};
ushort Fblm_WriteDoneDelayTimer = 0;
ubyte Fblm_AppFlashSigntureSucFlag = FALSE;
ubyte Fblm_QueueOfMinReqStep = 0u;
ubyte Fblm_RequestForResetFlag = FALSE;
uint32 Fblm_CodeflashChecksumValue = 0;
uint8 Fblm_CheckIfResultIsOk = FALSE;
uint32 Fblm_AppCrc32Value = 0;    
uint16 Fblm_Swp1Crc16Value = 0;
uint8 Fblm_AsyncReqForRunningNvmFeeFlsTask = FALSE;  /* flag used to open or close nvm fee fls task */
uint8 Fblm_SyncReqForRunningNvmFeeFlsTask = FALSE;  /* flag used to open or close nvm fee fls task */

uint8 Fblm_UpgradeSWP1BlockFlag = FALSE;
uint8 Fblm_UpgradeAPPBlockFlag = FALSE;
uint8 Fblm_AppProgramStsUpdateFlag = FALSE;
uint8 Fblm_Swp1ProgramStsUpdateFlag = FALSE;

boolean Fblm_EraseDoneFlag = FALSE;

static FBLM_BootParaSubId_t FBLM_BootParaSubId = FBLM_BOOT_PARA_UNKNOW;


extern ubyte Fblm_RunningEraseCommandFlag;
extern ubyte checkMemoryAllowed;
extern ubyte Fblm_ActivateSblFlag;
static boolean Fblm_NvmWriteReqStart = FALSE;
extern cy_stc_scb_spi_context_t Spid_contextSCB2;

# pragma ghs section bss=".flashdriver"
uint8_t   flashCode[FlashDrv_BlockSize];
# pragma ghs section bss=default

# pragma ghs section bss=".swp1"
uint8_t   FBLM_Swp1Code[FBLM_SWP1_SIZE];  /*used to store temp SWP1 data,and then write into NVM */
# pragma ghs section bss=default

#pragma ghs section rodata=".ApplEndFlag"
#pragma ghs startdata
volatile const ubyte M0BOOT_End[2] =
{
#if defined(DCU_FL)
  'F','L'
#elif defined(DCU_FR)
  'F','R'
#elif defined(DCU_RL)
  'R','L'
#elif defined(DCU_RR)
  'R','R'
#endif
};
#pragma ghs enddata
#pragma ghs section


// #define  SBL_DIAG_DB_PART_NUMBER          0x66, 0x08, 0x68, 0x35, 0x86, 0x20, 0x20, 0x41  /* '  A' */

// /* DID F124 */
// #define  SBL_SW_VERSION_NUMBER          0x66, 0x08, 0x11, 0x54, 0x13, 0x00, 0x00

// /* DID F1A1 */
// #define Diag_PBLDiagDatabasePN 0x66u, 0x08u, 0x68u, 0x35u, 0x88u
// /* DID F1A5 */
// #define Diag_PBLSoftDiagDatabasePN 0x66u, 0x08u, 0x68u, 0x35u, 0x68u
// /* DID F1AA */
// #define Diag_ECUCoreAsmPN 0x66u, 0x08u, 0x50u, 0x77u, 0x54u
// /* DID F1AB */
// #define Diag_ECUDeliAsmPN 0x66u, 0x08u, 0x58u, 0x02u, 0x60u


typedef enum {
    VARIANT_DATA_SBL_DIAG_DB_PART_NUMBER = 56,
    VARIANT_DATA_SBL_SW_VERSION_NUMBER = 57,
    VARIANT_DATA_DIAG_PBL_DIAG_DATABASE_PN = 58,
    VARIANT_DATA_DIAG_PBL_SOFT_DIAG_DATABASE_PN = 59,
    VARIANT_DATA_DIAG_ECU_CORE_ASM_PN = 60,
    VARIANT_DATA_DIAG_ECU_DELI_ASM_PN = 61,
    VARIANT_DATA_BOOT_VESRION = 62,
    VARIANT_DATA_BOOT_END_FLAG = 63,
}Variant_Data_Type;

// Variant data slot configuration, reserved totally 4K
#define VARIANT_SLOT_SIZE  (64U)
#define VARIANT_SLOT_COUNT (64U)

#pragma ghs section rodata=".variant_data"
#pragma ghs startdata
volatile const ubyte Variant_Data[VARIANT_SLOT_COUNT][VARIANT_SLOT_SIZE] =
{
    [VARIANT_DATA_SBL_DIAG_DB_PART_NUMBER] = {0},
    [VARIANT_DATA_SBL_SW_VERSION_NUMBER] = {0},
    [VARIANT_DATA_DIAG_PBL_DIAG_DATABASE_PN] = {0},
    [VARIANT_DATA_DIAG_PBL_SOFT_DIAG_DATABASE_PN] = {0},
    [VARIANT_DATA_DIAG_ECU_CORE_ASM_PN] = {0},
    [VARIANT_DATA_DIAG_ECU_DELI_ASM_PN] = {0},
    [VARIANT_DATA_BOOT_VESRION] = {0x0B,0x07,0x00},
    [VARIANT_DATA_BOOT_END_FLAG] = {'F','L'},
};
#pragma ghs enddata
#pragma ghs section

#if 0
#pragma ghs section rodata=".M0AppEndFlag"
#pragma ghs startdata
volatile const ubyte M0App_End[5];
#pragma ghs enddata
#pragma ghs section

#pragma ghs section rodata=".M0AppConf"
#pragma ghs startdata
volatile const SYST_SwIdentifier_t M0AppHeader =
{
   (tExportFct)(0x00),
   (ulong)0x00
};
#pragma ghs enddata
#pragma ghs section

#pragma ghs section rodata=".M4AppConf"
#pragma ghs startdata
volatile const SYST_SwIdentifier_t M4AppHeader =
{
   (tExportFct)(0x00),
   (ulong)0x00
};
#pragma ghs enddata
#pragma ghs section
#endif
/*______ P R I V A T E - D A T A _____________________________________________*/
extern char __ghsbegin_M4AppEndFlag[];
extern char __ghsbegin_EOLStartFlag[];
extern ubyte*  __ghs_rombootcodestart;
extern ubyte*  __ghs_rombootcodeend;
extern ubyte*  __ghs_rambootcodestart;
extern ubyte*  __ghs_rambootcodeend;
extern ulong Fblm_RandomValue;
#define BootFlashStartAdd 	((uint32_t) &__ghs_rombootcodestart)
#define BootFlashEndAdd 	((uint32_t) &__ghs_rombootcodeend)
#define BootRamStartAdd     ((uint32_t) &__ghs_rambootcodestart)
#define BootRamEndAdd      	((uint32_t) &__ghs_rambootcodeend)

/*The premise is that each block's address is contiguous*/
tLogicalBlockTable FblLogicalBlockTable =
{
    FBL_MTAB_NO_OF_BLOCKS,/*Total number or memory block*/
    {
            {
              FlashDrv_BlockIndex, /* Block Index - Flash Driver*/
              FBLM_FLASHDRV_STARTADDRESS, /*blockStartAddress*/
              FlashDrv_BlockSize, /*blockLength memory size*/
              0x00		/*maxProgAttempts,0x00 means no limited*/
            },

            {
              FlashDrvSHA_BlockIndex, /* Block Index - Flash Driver SHA*/
              FBLM_FLASHDRIVER_VBTADDR, /*blockStartAddress, but no useful*/
              FlashDrvSHA_BlockSize, /*blockLength memory size*/
              0x00		/*maxProgAttempts,0x00 means no limited*/
            },
            {
              APP_BlockIndex, /* Block Index - APP*/
              FBLM_APP_STARTADDRESS, /*blockStartAddress*/
              FBLM_APP_LENGTH, /*blockLength memory size*/
              0x00		/*maxProgAttempts,0x00 means no limited*/
            },

            {
              APPSHA_BlockIndex, /* Block Index - APP SHA*/
              FBLM_APP_VBTADDR, /*blockStartAddress, but no useful*/
              APPSHA_BlockSize, /*blockLength memory size*/
              0x00		/*maxProgAttempts,0x00 means no limited*/
            },
            {
              SWP1_BlockIndex, /* Block Index - SWP1*/
              FBLM_SWP1_STARTADDRESS, /*blockStartAddress*/
              FBLM_SWP1_SIZE, /*blockLength memory size*/
              0x00		/*maxProgAttempts,0x00 means no limited*/
            },

            {
              SWP1SHA_BlockIndex, /* Block Index - SWP1 SHA*/
              FBLM_SWP1_VBTADDR, /*blockStartAddress, but no useful*/
              FBLM_VBT_SIZE, /*blockLength memory size*/
              0x00		/*maxProgAttempts,0x00 means no limited*/
            },
   }

};


/*______ L O C A L - D A T A _________________________________________________*/
static ubyte Fblm_FlashData[FBL_MEMORY_WRITE_512BYTE] __attribute__ ((aligned (8)))   = {0u};
static boolean IsWriteReadNvm = FALSE;
static boolean IsAsyncWriteReadNvm = FALSE;
static tDid didTable[] =
{
    /* -- BootSoftwareIdentification-- */              /* DID Length(2byte) +  Content Length  */
    /* -- Primary Bootloader Version-- */
    { Fblm_Primary_Bootloader_Version_F1FA              , kDiagRqlDataByIdentifierVersionPrintParameterPrint},

    /* 22/2E:Public Key  */ 
    /*The response data length should be 32, not 292.*/
    { Fblm_Public_Key_Did_D01C                          , kDiagRqlReadDataByIdentifier + 32},


    /* 22:Primary Bootloader Diagnostic Database Part Number */
    { Fblm_PrimaryBootDiagDataPN_Did_F121               , kDiagRqlReadDataByIdentifier + 7},

    /* 22: Secondary Bootloader Diagnostic Database Part Number */
    { Fblm_SecondaryBootDiagDataPN_Did_F122              , kDiagRqlReadDataByIdentifier + 7},

    /* 22: Primary Bootloader Software Part Number */
    { Fblm_SecondaryBootSwPN_Did_F124                   , kDiagRqlReadDataByIdentifier + 7},

    /* 22: Primary Bootloader Software Part Number */
    { Fblm_PrimaryBootSwPN_Did_F125                     , kDiagRqlReadDataByIdentifier + 7},

    /* 22: ECU Core Assembly Part Number */
    { Fblm_EcuCoreAssemblPN_Did_F12A                    , kDiagRqlReadDataByIdentifier + 7},

    /* 22: ECU Delivery Assembly Part Number */
    { Fblm_EcuDeliveryAssemblyPN_Did_F12B               , kDiagRqlReadDataByIdentifier + 7},

    /* 22: Active Diagnostic Session */
    { Fblm_ActiveDiagSession_Did_F186                   , kDiagRqlReadDataByIdentifier + 1},

    /* 22: System Supplier Identifier */
    { Fblm_SystemSupplierIdentifier_Did_F18A            , kDiagRqlReadDataByIdentifier + 6},

    /* 22: ECU Serial Number */
    { Fblm_EcuSerialNum_Did_F18C                	    , kDiagRqlReadDataByIdentifier + 4},

    /* 22: Primary Bootloader Diagnostic Database Part Number Geely */
    { Fblm_PrimaryBootDiagDataPN_Geely_Did_F1A1         , kDiagRqlReadDataByIdentifier + 8},

    /* 22: Primary Bootloader Diagnostic Database Part Number Geely */
    { Fblm_SecondaryBootDiagDataPN_Geely_Did_F1A2       , kDiagRqlReadDataByIdentifier + 8},

    /* 22: Primary Bootloader Software Part Number Geely */
    { Fblm_PrimaryBootDiagSwPN_Geely_Did_F1A5           , kDiagRqlReadDataByIdentifier + 8},

    /* 22: ECU Core Assembly Part Number Geely */
    { Fblm_EcuCoreAssemblyPN_Geely_Did_F1AA             , kDiagRqlReadDataByIdentifier + 8},

    /* 22: ECU Delivery Assembly Part Number Geely */
    { Fblm_EcuDeliveryAssemblyPN_Geely_Did_F1AB         , kDiagRqlReadDataByIdentifier + 8},

    /* 22: Complete ECU Part/Serial Number(s) (PBL) Geely */
    { Fblm_Complete_ECU_Part_Serial_Number_s_PBL_Geely_Did_ED20         , kDiagRqlReadDataByIdentifier + 46},

    /* 22: Complete ECU Part/Serial Number(s) */
    { Fblm_Complete_ECU_Part_Serial_Number_s_Did_EDA0                   , kDiagRqlReadDataByIdentifier + 42},
};
static const ubyte XorArray[4] = {0x31,0x23,0x56,0x71};/*For verify $27 key*/


static ulong crc32_tab[256] =
{
    0x00000000, 0x77073096, 0xee0e612c, 0x990951ba, 0x076dc419,
    0x706af48f, 0xe963a535, 0x9e6495a3, 0x0edb8832, 0x79dcb8a4,
    0xe0d5e91e, 0x97d2d988, 0x09b64c2b, 0x7eb17cbd, 0xe7b82d07,
    0x90bf1d91, 0x1db71064, 0x6ab020f2, 0xf3b97148, 0x84be41de,
    0x1adad47d, 0x6ddde4eb, 0xf4d4b551, 0x83d385c7, 0x136c9856,
    0x646ba8c0, 0xfd62f97a, 0x8a65c9ec, 0x14015c4f, 0x63066cd9,
    0xfa0f3d63, 0x8d080df5, 0x3b6e20c8, 0x4c69105e, 0xd56041e4,
    0xa2677172, 0x3c03e4d1, 0x4b04d447, 0xd20d85fd, 0xa50ab56b,
    0x35b5a8fa, 0x42b2986c, 0xdbbbc9d6, 0xacbcf940, 0x32d86ce3,
    0x45df5c75, 0xdcd60dcf, 0xabd13d59, 0x26d930ac, 0x51de003a,
    0xc8d75180, 0xbfd06116, 0x21b4f4b5, 0x56b3c423, 0xcfba9599,
    0xb8bda50f, 0x2802b89e, 0x5f058808, 0xc60cd9b2, 0xb10be924,
    0x2f6f7c87, 0x58684c11, 0xc1611dab, 0xb6662d3d, 0x76dc4190,
    0x01db7106, 0x98d220bc, 0xefd5102a, 0x71b18589, 0x06b6b51f,
    0x9fbfe4a5, 0xe8b8d433, 0x7807c9a2, 0x0f00f934, 0x9609a88e,
    0xe10e9818, 0x7f6a0dbb, 0x086d3d2d, 0x91646c97, 0xe6635c01,
    0x6b6b51f4, 0x1c6c6162, 0x856530d8, 0xf262004e, 0x6c0695ed,
    0x1b01a57b, 0x8208f4c1, 0xf50fc457, 0x65b0d9c6, 0x12b7e950,
    0x8bbeb8ea, 0xfcb9887c, 0x62dd1ddf, 0x15da2d49, 0x8cd37cf3,
    0xfbd44c65, 0x4db26158, 0x3ab551ce, 0xa3bc0074, 0xd4bb30e2,
    0x4adfa541, 0x3dd895d7, 0xa4d1c46d, 0xd3d6f4fb, 0x4369e96a,
    0x346ed9fc, 0xad678846, 0xda60b8d0, 0x44042d73, 0x33031de5,
    0xaa0a4c5f, 0xdd0d7cc9, 0x5005713c, 0x270241aa, 0xbe0b1010,
    0xc90c2086, 0x5768b525, 0x206f85b3, 0xb966d409, 0xce61e49f,
    0x5edef90e, 0x29d9c998, 0xb0d09822, 0xc7d7a8b4, 0x59b33d17,
    0x2eb40d81, 0xb7bd5c3b, 0xc0ba6cad, 0xedb88320, 0x9abfb3b6,
    0x03b6e20c, 0x74b1d29a, 0xead54739, 0x9dd277af, 0x04db2615,
    0x73dc1683, 0xe3630b12, 0x94643b84, 0x0d6d6a3e, 0x7a6a5aa8,
    0xe40ecf0b, 0x9309ff9d, 0x0a00ae27, 0x7d079eb1, 0xf00f9344,
    0x8708a3d2, 0x1e01f268, 0x6906c2fe, 0xf762575d, 0x806567cb,
    0x196c3671, 0x6e6b06e7, 0xfed41b76, 0x89d32be0, 0x10da7a5a,
    0x67dd4acc, 0xf9b9df6f, 0x8ebeeff9, 0x17b7be43, 0x60b08ed5,
    0xd6d6a3e8, 0xa1d1937e, 0x38d8c2c4, 0x4fdff252, 0xd1bb67f1,
    0xa6bc5767, 0x3fb506dd, 0x48b2364b, 0xd80d2bda, 0xaf0a1b4c,
    0x36034af6, 0x41047a60, 0xdf60efc3, 0xa867df55, 0x316e8eef,
    0x4669be79, 0xcb61b38c, 0xbc66831a, 0x256fd2a0, 0x5268e236,
    0xcc0c7795, 0xbb0b4703, 0x220216b9, 0x5505262f, 0xc5ba3bbe,
    0xb2bd0b28, 0x2bb45a92, 0x5cb36a04, 0xc2d7ffa7, 0xb5d0cf31,
    0x2cd99e8b, 0x5bdeae1d, 0x9b64c2b0, 0xec63f226, 0x756aa39c,
    0x026d930a, 0x9c0906a9, 0xeb0e363f, 0x72076785, 0x05005713,
    0x95bf4a82, 0xe2b87a14, 0x7bb12bae, 0x0cb61b38, 0x92d28e9b,
    0xe5d5be0d, 0x7cdcefb7, 0x0bdbdf21, 0x86d3d2d4, 0xf1d4e242,
    0x68ddb3f8, 0x1fda836e, 0x81be16cd, 0xf6b9265b, 0x6fb077e1,
    0x18b74777, 0x88085ae6, 0xff0f6a70, 0x66063bca, 0x11010b5c,
    0x8f659eff, 0xf862ae69, 0x616bffd3, 0x166ccf45, 0xa00ae278,
    0xd70dd2ee, 0x4e048354, 0x3903b3c2, 0xa7672661, 0xd06016f7,
    0x4969474d, 0x3e6e77db, 0xaed16a4a, 0xd9d65adc, 0x40df0b66,
    0x37d83bf0, 0xa9bcae53, 0xdebb9ec5, 0x47b2cf7f, 0x30b5ffe9,
    0xbdbdf21c, 0xcabac28a, 0x53b39330, 0x24b4a3a6, 0xbad03605,
    0xcdd70693, 0x54de5729, 0x23d967bf, 0xb3667a2e, 0xc4614ab8,
    0x5d681b02, 0x2a6f2b94, 0xb40bbe37, 0xc30c8ea1, 0x5a05df1b,
    0x2d02ef8d
};

// S盒
uint8 S[256] = {
        0x63, 0x7C, 0x77, 0x7B, 0xF2, 0x6B, 0x6F, 0xC5, 0x30, 0x01, 0x67, 0x2B, 0xFE, 0xD7, 0xAB, 0x76,
        0xCA, 0x82, 0xC9, 0x7D, 0xFA, 0x59, 0x47, 0xF0, 0xAD, 0xD4, 0xA2, 0xAF, 0x9C, 0xA4, 0x72, 0xC0,
        0xB7, 0xFD, 0x93, 0x26, 0x36, 0x3F, 0xF7, 0xCC, 0x34, 0xA5, 0xE5, 0xF1, 0x71, 0xD8, 0x31, 0x15,
        0x04, 0xC7, 0x23, 0xC3, 0x18, 0x96, 0x05, 0x9A, 0x07, 0x12, 0x80, 0xE2, 0xEB, 0x27, 0xB2, 0x75,
        0x09, 0x83, 0x2C, 0x1A, 0x1B, 0x6E, 0x5A, 0xA0, 0x52, 0x3B, 0xD6, 0xB3, 0x29, 0xE3, 0x2F, 0x84,
        0x53, 0xD1, 0x00, 0xED, 0x20, 0xFC, 0xB1, 0x5B, 0x6A, 0xCB, 0xBE, 0x39, 0x4A, 0x4C, 0x58, 0xCF,
        0xD0, 0xEF, 0xAA, 0xFB, 0x43, 0x4D, 0x33, 0x85, 0x45, 0xF9, 0x02, 0x7F, 0x50, 0x3C, 0x9F, 0xA8,
        0x51, 0xA3, 0x40, 0x8F, 0x92, 0x9D, 0x38, 0xF5, 0xBC, 0xB6, 0xDA, 0x21, 0x10, 0xFF, 0xF3, 0xD2,
        0xCD, 0x0C, 0x13, 0xEC, 0x5F, 0x97, 0x44, 0x17, 0xC4, 0xA7, 0x7E, 0x3D, 0x64, 0x5D, 0x19, 0x73,
        0x60, 0x81, 0x4F, 0xDC, 0x22, 0x2A, 0x90, 0x88, 0x46, 0xEE, 0xB8, 0x14, 0xDE, 0x5E, 0x0B, 0xDB,
        0xE0, 0x32, 0x3A, 0x0A, 0x49, 0x06, 0x24, 0x5C, 0xC2, 0xD3, 0xAC, 0x62, 0x91, 0x95, 0xE4, 0x79,
        0xE7, 0xC8, 0x37, 0x6D, 0x8D, 0xD5, 0x4E, 0xA9, 0x6C, 0x56, 0xF4, 0xEA, 0x65, 0x7A, 0xAE, 0x08,
        0xBA, 0x78, 0x25, 0x2E, 0x1C, 0xA6, 0xB4, 0xC6, 0xE8, 0xDD, 0x74, 0x1F, 0x4B, 0xBD, 0x8B, 0x8A,
        0x70, 0x3E, 0xB5, 0x66, 0x48, 0x03, 0xF6, 0x0E, 0x61, 0x35, 0x57, 0xB9, 0x86, 0xC1, 0x1D, 0x9E,
        0xE1, 0xF8, 0x98, 0x11, 0x69, 0xD9, 0x8E, 0x94, 0x9B, 0x1E, 0x87, 0xE9, 0xCE, 0x55, 0x28, 0xDF,
        0x8C, 0xA1, 0x89, 0x0D, 0xBF, 0xE6, 0x42, 0x68, 0x41, 0x99, 0x2D, 0x0F, 0xB0, 0x54, 0xBB, 0x16
};

/* For CMAC Calculation */
unsigned char const_Rb[16] = {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x87
};

// AES.key    -> Security_Constant
unsigned char Security_Constant[16] = { 
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF };

uint8 AES_keyStored[16] = {0};
uint8 keyReceived[16] = {0};
uint8 AES_Seed[16] = {0};
uint8 lastAES_Seed[16] = {0};

static uint8 Fblm_Signature[256] = {0};
static boolean StartRsa = FALSE;
static ulong Fblm_StartAddress = 0u;
static ulong Fblm_EndAddress = 0u;
static const uint8 Fblm_F1A2_PN[8u] = {SBL_DIAG_DB_PART_NUMBER};
static const uint8 Fblm_F124_Ver[7u] = {SBL_SW_VERSION_NUMBER};
/*F1A1*/
static const uint8 Diag_PBLDiagDatabasePNData[Diag_PBLDiagDatabasePN_Len] = {Diag_PBLDiagDatabasePN};
static const uint8 Diag_PBLDiagDatabaseVerData[Diag_PBLDiagDatabaseVer_Len] = {Diag_PBLDiagDatabaseVer};
/*F1A5*/
static const uint8 Diag_PBLSoftDatabasePNData[Diag_PBLSoftDiagDatabasePN_Len] = {Diag_PBLSoftDiagDatabasePN};
static const uint8 Diag_PBLSoftDatabaseVerData[Diag_PBLSoftDiagDatabaseVer_Len] = {Diag_PBLSoftDiagDatabaseVer};
/*F1AA*/
static const uint8 Diag_ECUCoreAsmPNData[Diag_ECUCoreAsmPN_Len] = {Diag_ECUCoreAsmPN};
static const uint8 Diag_ECUCoreAsmVerData[Diag_ECUCoreAsmVer_Len] = {Diag_ECUCoreAsmVer};
/*F1AB*/
static const uint8 Diag_ECUDeliAsmPNData[Diag_ECUDeliAsmPN_Len] = {Diag_ECUDeliAsmPN};
static const uint8 Diag_ECUDeliAsmVerData[Diag_ECUDeliAsmVer_Len] = {Diag_ECUDeliAsmVer};
static uint8 Fblm_WriteSecurityConstantFlag = FALSE;
static uint8 Fblm_UpdateReprogrammingCounterFlag = FALSE;

const Fblm_CodeFlashSectorAdrTbl  Fblm_CodeFlashSector_RAMAdrTbl[Fblm_CodeFlashNum] = 
{
  {&FBLM_CODEFLASH_ADDRESS.F1AA[0],             8},  /* DID F1AA */
  {&FBLM_CODEFLASH_ADDRESS.F1AB[0],             8},  /* DID F1AB */
  {&FBLM_CODEFLASH_ADDRESS.F1A1[0],             8},  /* DID F1A1 */
  {&FBLM_CODEFLASH_ADDRESS.F1A5[0],             8},  /* DID F1A5 */
  {&FBLM_CODEFLASH_ADDRESS.F18C[0],             4},  /* DID F18C */
  {&FBLM_CODEFLASH_ADDRESS.F18B[0],             3},  /* DID F18B */
  {&FBLM_CODEFLASH_ADDRESS.ChksumApl[0],        2},  /* ChksumApl */
  {&FBLM_CODEFLASH_ADDRESS.SWVersion[0],        2},  /* SWVersion */
  {&FBLM_CODEFLASH_ADDRESS.F194[0],            15},  /* DID F194 */
  {&FBLM_CODEFLASH_ADDRESS.F103[0],             6},  /* DID F103 */
  {&FBLM_CODEFLASH_ADDRESS.F19E[0],             7},  /* DID F19E */
  {&FBLM_CODEFLASH_ADDRESS.Password[0],        16},  /* Password */
  {&FBLM_CODEFLASH_ADDRESS.SecurityConstant[0], 5},  /* SecurityConstant */
  {&FBLM_CODEFLASH_ADDRESS.HWVersion[0],       10},  /* HWVersion */
  {&FBLM_CODEFLASH_ADDRESS.EolDone,             1},  /* EolDone */
};
/*______ L O C A L - M A C R O S _____________________________________________*/

/*______ I M P O R T - F U N C T I O N S - P R O T O T Y P E S _______________*/
extern void Spid_IrqSCBChannel2(void);
/*______ L O C A L - F U N C T I O N S - P R O T O T Y P E S _________________*/
static ulong Fblm_SecMComputeKey(void);
static ubyte Fblm_IsM0ApplicationValid(void);
static ubyte Fblm_IsM4ApplicationValid(void);
static ubyte Fblm_IsBootCompatibleWithApp(void);
static ubyte Fblm_IsSoftwareAndHardwareVersionMatch(void);
static uint8 Fblm_Binary2BCD(uint8 inputVal);
static void Fblm_ReadNvmData(ubyte NvmID, ushort RespLen, ubyte* diagData);
static void Fblm_NvmImmediateWriteBlock(uint16 NvmBlockId,uint8 *NvMSrcPtr);

static void AES_CMAC(uint8* key, uint8* input, uint32 length, uint8* mac);
static bool isArrayZero(uint8 arr[], uint8 size);
static void SwapEndianArray(uint8 *arr, uint8 len);

/* DID function */
static void Fblm_Complete_ECU_Part_Serial_Number_s_PBL_Geely_Did_ED20_Func(uint8 *pData);
static void Fblm_Complete_ECU_Part_Serial_Number_s_Did_EDA0_Func(uint8 *pData);
/*______ G L O B A L - F U N C T I O N S _____________________________________*/
/*----------------------------------------------------------------------------*/
/*Name : Fblm_SyncWriteNvmData 			                                      */
/*Role : IMC_DLA_TaskRun run precondition                                     */
/*Interface :                                                                 */
/*  - IN  : none	                                                          */
/*  - OUT : TRUE or FALSE					                                  */
/*Pre-condition : none			                                              */
/*Constraints   : none             			                                  */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [initialize parameters and main loop]                                   */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
void Fblm_SyncWriteNvmData(ushort WriteLen, ushort NvmID, ubyte ResponseLen, ubyte * pbDiagData)
{
  Fblm_SyncReqForRunningNvmFeeFlsTask = TRUE;
  memcpy(&Fblm_ReadWriteNvmBlockData[0],pbDiagData,WriteLen);
  Fblm_CurrentNvMBlockId = NvmID;
  Fblm_DiagRespDataLen = ResponseLen;
  Fblm_IsReadWriteNvmBlock = TRUE;
  Fblm_WDRefresh();
  (void)Sbcc_WatchdogMonitor();
  /* GEFDCM-52  It is judged whether the erasure has been performed. If the flash has been erased, 
  the NRC78 will not be returned if the erasure is performed again, and a positive response will be returned directly*/
  /* GEFDCM-98 If it is detected that it has been erased, NRC78 will not be replied next time.  */
  switch (ActiveLogicBlock)
  {
    case APP_BlockIndex:
        if(!fblm_EraseFlag.APP_EraseSucceeded)
        {
            DiagExRCRResponsePending(kNotForceSendResponsePending);
        }
        break;
    case SWP1_BlockIndex:
        if(!fblm_EraseFlag.SWP1_EraseSucceeded)
        {
            DiagExRCRResponsePending(kNotForceSendResponsePending);
        }
        break;
    default:
        DiagExRCRResponsePending(kNotForceSendResponsePending);
        break;
  } 

}

/*----------------------------------------------------------------------------*/
/*Name : Fblm_InitASyncWriteQueue 			                                  */
/*Role : IMC_DLA_TaskRun run precondition                                     */
/*Interface :                                                                 */
/*  - IN  : none	                                                          */
/*  - OUT : TRUE or FALSE					                                  */
/*Pre-condition : none			                                              */
/*Constraints   : none             			                                  */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [initialize parameters and main loop]                                   */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
void Fblm_InitASyncWriteQueue(vuint8 queuenum)
{
  Fblm_AsyncWriteNvmBlockData[queuenum].bufferIsFree = TRUE;
  Fblm_AsyncWriteNvmBlockData[queuenum].dataLength = 0u;
  Fblm_AsyncWriteNvmBlockData[queuenum].requestProcess = FALSE;
  Fblm_AsyncWriteNvmBlockData[queuenum].reqStep = 0u;
  Fblm_AsyncWriteNvmBlockData[queuenum].waitReqTime = 0u;
  memset(Fblm_AsyncWriteNvmBlockData[queuenum].databuffer, 0,\
       sizeof(Fblm_AsyncWriteNvmBlockData[queuenum].databuffer));
}

/*----------------------------------------------------------------------------*/
/*Name : Fblm_ASyncWriteQueueInit 			                                  */
/*Role : IMC_DLA_TaskRun run precondition                                     */
/*Interface :                                                                 */
/*  - IN  : none	                                                          */
/*  - OUT : TRUE or FALSE					                                  */
/*Pre-condition : none			                                              */
/*Constraints   : none             			                                  */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [initialize parameters and main loop]                                   */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
void Fblm_ASyncWriteQueueInit(void)
{
  vuint8 index = 0u;

  for(index = 0u; index < Fblm_AsyncWriteQueueNumber; index++)
  {
    Fblm_AsyncWriteNvmBlockData[index].bufferIsFree = TRUE;
    Fblm_AsyncWriteNvmBlockData[index].dataLength = 0u;
    Fblm_AsyncWriteNvmBlockData[index].requestProcess = FALSE;
    Fblm_AsyncWriteNvmBlockData[index].reqStep = 0u;
    Fblm_AsyncWriteNvmBlockData[index].waitReqTime = 0u;
    memset(Fblm_AsyncWriteNvmBlockData[index].databuffer, 0,\
         sizeof(Fblm_AsyncWriteNvmBlockData[index].databuffer));
  }
}

/*----------------------------------------------------------------------------*/
/*Name : FBLM_FlashDriverInit 			                                      */
/*Role : FLASH_DRIVER_INIT                                                    */
/*Interface :                                                                 */
/*  - IN  : none	                                                          */
/*  - OUT : none					                                          */
/*Pre-condition : none			                                              */
/*Constraints   : none             			                                  */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [initialize parameters and main loop]                                   */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
void FBLM_FlashDriverInit(void)
{
    static boolean FlashDriverInitFlag = FALSE;
    if(!FlashDriverInitFlag)
    {
        FLASH_DRIVER_RAM_INIT();
        FLASH_DRIVER_INIT(TRUE);
        FlashDriverInitFlag = TRUE;
    }
    else
    {
        FLASH_DRIVER_INIT(TRUE);
    }
}

/*******************************************************************************
* NAME:              Fblm_GetWriteQueueBufferFreeSts
*
* CALLED BY:         Transport layer
* PRECONDITIONS:
*
* DESCRIPTION:       StartOfFrame reception function
*                    Return the free buffer
*******************************************************************************/
static ubyte Fblm_GetWriteQueueBufferFreeSts(void)
{
  vuint8 index = 0u;
  vuint8 Ret = FALSE;
  for(index = 0u; index < Fblm_AsyncWriteQueueNumber; index++)
  {
    if(Fblm_AsyncWriteNvmBlockData[index].bufferIsFree != TRUE)
    {
      Ret = FALSE;
      break;
    }
    else
    {
      Ret = TRUE;
    }
  }
  return Ret;
}

/*----------------------------------------------------------------------------*/
/*Name : Fblm_AsyncWriteNvmData 			                                  */
/*Role : IMC_DLA_TaskRun run precondition                                     */
/*Interface :                                                                 */
/*  - IN  : none	                                                          */
/*  - OUT : TRUE or FALSE					                                  */
/*Pre-condition : none			                                              */
/*Constraints   : none             			                                  */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [initialize parameters and main loop]                                   */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
void Fblm_AsyncWriteNvmData(ushort WriteLen, ushort NvmID, ubyte * pbDiagData)
{
  uint8 index = 0;

  Fblm_AsyncWriteReqStep++;
  for(index = 0u; index < Fblm_AsyncWriteQueueNumber; index++)
   {
     if(Fblm_AsyncWriteNvmBlockData[index].bufferIsFree == TRUE)
     {
       Fblm_AsyncWriteNvmBlockData[index].RequestNvmID = NvmID;
       Fblm_AsyncWriteNvmBlockData[index].dataLength = WriteLen;
       Fblm_AsyncWriteNvmBlockData[index].bufferIsFree = FALSE;
       Fblm_AsyncWriteNvmBlockData[index].reqStep = Fblm_AsyncWriteReqStep;
       memcpy(Fblm_AsyncWriteNvmBlockData[index].databuffer, pbDiagData, WriteLen);
       break;
     }
   }

}

/*----------------------------------------------------------------------------*/
/*Name : Fblm_GetAsyncWriteQueueReqProcessSts 			                      */
/*Role : IMC_DLA_TaskRun run precondition                                     */
/*Interface :                                                                 */
/*  - IN  : none	                                                          */
/*  - OUT : TRUE or FALSE					                                  */
/*Pre-condition : none			                                              */
/*Constraints   : none             			                                  */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [initialize parameters and main loop]                                   */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
uint8 Fblm_GetAsyncWriteQueueReqProcessSts(ubyte CurrentQueueNum)
{
  uint8 index = 0;
  uint8 Ret = FALSE; /*No request process*/
  for(index = 0u; index < Fblm_AsyncWriteQueueNumber; index++)
   {
       if(Fblm_AsyncWriteNvmBlockData[index].requestProcess == TRUE)
       {
         Ret = TRUE;
         break;
       }
   }
  return Ret;
}

/*******************************************************************************
* NAME:              Fblm_AsyncWriteQueueUpdateRequest
*
* CALLED BY:         DescTask
* PRECONDITIONS:
*
* DESCRIPTION:       Update diag request to desc ptr.
*
*******************************************************************************/
void Fblm_AsyncWriteQueueUpdateRequest(void)
{
  vuint8 queNumber = 0u;
  vuint8 ReadyToRequestQueue = 0u;


  if(TRUE == Fblm_GetSyncWriteFreeSts())
  {
    for(queNumber = 0u; queNumber < Fblm_AsyncWriteQueueNumber; queNumber++)
    {
      if((0u != Fblm_AsyncWriteNvmBlockData[queNumber].dataLength) && (FALSE == Fblm_GetAsyncWriteQueueReqProcessSts(queNumber)))
      {
         /*When the queNumber is ready , and others is not in processing*/
          Fblm_QueueOfMinReqStep = queNumber;/*init value*/
         for(uint8 index = 0u; index < Fblm_AsyncWriteQueueNumber; index++)
         {
             if(queNumber != index)
             {
             if((FALSE == Fblm_AsyncWriteNvmBlockData[index].bufferIsFree) &&
                         (0 != Fblm_AsyncWriteNvmBlockData[index].dataLength))
             {
               if(Fblm_AsyncWriteNvmBlockData[Fblm_QueueOfMinReqStep].reqStep > Fblm_AsyncWriteNvmBlockData[index].reqStep)
               {
                 Fblm_QueueOfMinReqStep = index;  /*Get min request step*/
               }
             }
             }
         }
         /*update data of queue*/
         memcpy(Fblm_AsyncWriteNvmBlockDataBuf, &Fblm_AsyncWriteNvmBlockData[Fblm_QueueOfMinReqStep].databuffer[0], \
                                                    Fblm_AsyncWriteNvmBlockData[Fblm_QueueOfMinReqStep].dataLength);
         Fblm_AsyncWriteCurrentNvMBlockId = Fblm_AsyncWriteNvmBlockData[Fblm_QueueOfMinReqStep].RequestNvmID;
         Fblm_IsAsyncWriteNvmBlockhandle = TRUE;
         Fblm_AsyncWriteNvmBlockData[Fblm_QueueOfMinReqStep].requestProcess = TRUE;
         Fblm_AsyncReqForRunningNvmFeeFlsTask = TRUE;
         break;
      }

    }

  }

}





/*----------------------------------------------------------------------------*/
/*Name : Fblm_ReadNvmData        			                                  */
/*Role : IMC_DLA_TaskRun run precondition                                     */
/*Interface :                                                                 */
/*  - IN  : none	                                                          */
/*  - OUT : TRUE or FALSE					                                  */
/*Pre-condition : none			                                              */
/*Constraints   : none             			                                  */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [initialize parameters and main loop]                                   */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
static void Fblm_ReadNvmData(ubyte NvmID, ushort RespLen, ubyte* diagData)
{
  Fblm_SyncReqForRunningNvmFeeFlsTask = TRUE;
  Fblm_CurrentNvMBlockId = NvmID;
  Fblm_DiagRespDataLen = RespLen;
  Fblm_DiagData = diagData;
  Fblm_IsReadNvmBlock = TRUE;
  DiagExRCRResponsePending(kNotForceSendResponsePending);
}

/*----------------------------------------------------------------------------*/
/*Name : Fblm_IsIMCTaskNextRun 			                                      */
/*Role : IMC_DLA_TaskRun run precondition                                     */
/*Interface :                                                                 */
/*  - IN  : none	                                                          */
/*  - OUT : TRUE or FALSE					                                  */
/*Pre-condition : none			                                              */
/*Constraints   : none             			                                  */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [initialize parameters and main loop]                                   */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
bool_t Fblm_IsIMCTaskNextRun(void)
{
    if (TRUE/*(IODC_POSITIVE == IODC_GetInputDataDirect(MCU_IMC_RDY)) && (TRUE == Cy_SCB_SPI_IsTxComplete(SCB5))\
            && (0ul == Spid_contextSCB5.rxBufSize) && (0ul == Spid_contextSCB5.txBufSize)*/)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }

}

/*----------------------------------------------------------------------------*/
/*Name : Fblm_SPIRunnable    			                                      */
/*Role : Polling mode to receive and send SPI data                            */
/*Interface :                                                                 */
/*  - IN  : none	                                                          */
/*  - OUT : TRUE or FALSE					                                  */
/*Pre-condition : none			                                              */
/*Constraints   : none             			                                  */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [initialize parameters and main loop]                                   */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
void Fblm_SPIRunnable(void)
{
  while (CY_SCB_SPI_TRANSFER_ACTIVE == (Spid_contextSCB2.status & CY_SCB_SPI_TRANSFER_ACTIVE))
    {
        Spid_IrqSCBChannel2();
    }
}

/*----------------------------------------------------------------------------*/
/*Name : Fblm_CANRunnable    			                                      */
/*Role : Polling mode to receive and send CAN data                            */
/*Interface :                                                                 */
/*  - IN  : none	                                                          */
/*  - OUT : none        					                                  */
/*Pre-condition : none			                                              */
/*Constraints   : none             			                                  */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [initialize parameters and main loop]                                   */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
void Fblm_CANRunnable(void)
{
    Cy_CANFD_IrqHandler(CY_CANFD5_TYPE);/*Polling mode to refresh internal interrupt*/
}


/*----------------------------------------------------------------------------*/
/*Name : FBLM_ReadAll    			                                          */
/*Role : Preinitialization step,for example,whatever stay in bootloader or    */
/*  jump to app,must provide flash access right								  */
/*Interface :                                                                 */
/*  - IN  : none	                                                          */
/*  - OUT : none  							                                  */
/*Pre-condition : none			                                              */
/*Constraints   : none             			                                  */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [initialize parameters and main loop]                                   */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
void Fblm_ReadNvMIdBeforeJump(void)
{

  /*Get RamRDIProgInfo,get programming status*/
  NvM_ReadBlock(NvMConf_NvMBlockDescriptor_WDFC_ID_ECUID_RDI_PROGRAMMING_INFO, &WDFS_RamRDIProgInfo);
  do  /*Used to ReadBlock RamVaule, Due to it find the function of Read ALL is NOK */
  {
    MemAcc_MainFunction();
    Fee_30_FlexNor_MainFunction();
    NvM_MainFunction();
     NvM_GetErrorStatus(NvMConf_NvMBlockDescriptor_WDFC_ID_ECUID_RDI_PROGRAMMING_INFO,&NVMM_EcuRdiProgramDidStatus);
  }while(NVMM_EcuRdiProgramDidStatus == NVM_REQ_PENDING);

}

/*----------------------------------------------------------------------------*/
/*Name : FBLM_ReadAll    			                                          */
/*Role : Preinitialization step,for example,whatever stay in bootloader or    */
/*  jump to app,must provide flash access right								  */
/*Interface :                                                                 */
/*  - IN  : none	                                                          */
/*  - OUT : none  							                                  */
/*Pre-condition : none			                                              */
/*Constraints   : none             			                                  */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [initialize parameters and main loop]                                   */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
void Fblm_ReadAll(void) 
{
    /*Get PUBILC kEY and Boot Data Config*/
    NvM_ReadBlock(NvMConf_NvMBlockDescriptor_WDFC_ID_BOOT_PARA, &WDFS_RamBootPara);
    do  /*Used to ReadBlock RamVaule, Due to it find the function of Read ALL is NOK */
    {
        MemAcc_MainFunction(); 
        Fee_30_FlexNor_MainFunction();
        NvM_MainFunction();
        NvM_GetErrorStatus(NvMConf_NvMBlockDescriptor_WDFC_ID_BOOT_PARA,&NVMM_PublicKeyStatusDidStatus);
    }while(NVMM_PublicKeyStatusDidStatus == NVM_REQ_PENDING);

    
    NvM_ReadBlock(NvMConf_NvMBlockDescriptor_WDFC_ID_IDOPTION_SECURITY, &WDFS_RamIDOptionSecurity);
    do  /*Used to ReadBlock RamVaule, Due to it find the function of Read ALL is NOK */
    {
        MemAcc_MainFunction(); 
        Fee_30_FlexNor_MainFunction();
        NvM_MainFunction();
        NvM_GetErrorStatus(NvMConf_NvMBlockDescriptor_WDFC_ID_IDOPTION_SECURITY,&NVMM_IdIdoptionSecurity);
    }while(NVMM_IdIdoptionSecurity== NVM_REQ_PENDING);

    /*Get Part_Number_Geely */
    NvM_ReadBlock(NvMConf_NvMBlockDescriptor_WDFC_ID_PART_NUMBER_GEELY, &WDFS_RamPart_Number_Geely);
    do  /*Used to ReadBlock RamVaule, Due to it find the function of Read ALL is NOK */
    {
        MemAcc_MainFunction(); 
        Fee_30_FlexNor_MainFunction();
        NvM_MainFunction();
        NvM_GetErrorStatus(NvMConf_NvMBlockDescriptor_WDFC_ID_PART_NUMBER_GEELY,&NVMM_PartNumberGeelyDidStatus);
    }while(NVMM_PartNumberGeelyDidStatus == NVM_REQ_PENDING);

    for(uint16 i = 0; i < 256; i++)
    {
      Fblm_PublicKeyData[i] = WDFS_RamBootPara.PublicKeyData.PublicKeyModulus[i];
    }
    for(uint8 i = 0; i < 4; i++)
    {
      Fblm_PublicKeyExponent[i] = WDFS_RamBootPara.PublicKeyData.PublicKeyExponent[i];
    }

    for(uint8 i = 0; i < 16; i++)
    {
      Fblm_SecurityConstantLevel[i] = WDFS_RamBootPara.BootDataConfig.FixedByte[i];
    }

}
/*----------------------------------------------------------------------------*/
/*Name : Fblm_PreInit    			                                          */
/*Role : Preinitialization step,for example,whatever stay in bootloader or    */
/*  jump to app,must provide flash access right								  */
/*Interface :                                                                 */
/*  - IN  : none	                                                          */
/*  - OUT : none  							                                  */
/*Pre-condition : none			                                              */
/*Constraints   : none             			                                  */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [initialize parameters and main loop]                                   */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
void Fblm_PreInit(void)
{
#if defined( FBL_WATCHDOG_ON )
    /*Watchdog*/
    Fblm_WDInit();
    SetWDInit();
#endif
  /*Initialize Flash，blocking*/
   // Cy_FlashInit(FALSE);
    /*EEPROM*/
     //Cy_FlashInit(false /*blocking*/);   /*aim to advoid FLS ,be put it in cheksum cmd*/

/*	(void)EepromDriver_InitSync();*/
}

/*----------------------------------------------------------------------------*/
/*Name : Fblm_PreInit    			                                          */
/*Role : Initialize hardware/application module 						      */
/*Interface :                                                                 */
/*  - IN  : none	                                                          */
/*  - OUT : none  							                                  */
/*Pre-condition : none			                                              */
/*Constraints   : none             			                                  */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [initialize parameters and main loop]                                   */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
void Fblm_OtherModuleInit(void)
{
      /*1ms timer*/
      TIMD_TimerInit();
      TIMD_Timer1Init();
      IODC_Init();
      SPID_Init();

      MemAcc_Init(NULL_PTR);
      Fee_30_FlexNor_Init();  /*After fls module init*/
      NvM_Init();
      RSAM_Init();


      /*Power up GPU*/
      if(UPDATE_MODE_OTA == Fblm_GetUpdateMode())
      {
          IODC_SetOutputData(GPU_5V_EN,IODC_ACTIVE);
          IODC_SetOutputData(GPU_3V3_EN,IODC_ACTIVE);
          IODC_SetOutputData(PMIC_ON2,IODC_ACTIVE);
          IODC_SetOutputData(MCU_TO_GPU_RST,IODC_INACTIVE);
      }
      /*Setup IMC*/
      /*IMCM_Init(IM_MODE_FLASHER);*/

}

/*----------------------------------------------------------------------------*/
/*Name : Fblm_CalculateAndGetAPPChecksumResult    			                  */
/*Role : Initialize hardware/application module 						      */
/*Interface :                                                                 */
/*  - IN  : none	                                                          */
/*  - OUT : none  							                                  */
/*Pre-condition : none			                                              */
/*Constraints   : none             			                                  */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [initialize parameters and main loop]                                   */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
uint8 Fblm_CalculateAndGetAPPChecksumResult(void)
{
  uint8 *Address = NULL;
  uint16 CheckSum = 0u;
  for (Address = ((uint8*)FBLM_APP_STARTADDRESS) ; Address <= ((uint8*)(FBLM_APP_END - FBLM_Checksum_Length)); Address ++) /*SYST_FLASH_END_ADDRESS*/
  {
    CheckSum += *(Address);
  }
  Fblm_CodeflashChecksumValue = (__ghsbegin_M4AppEndFlag[28]  + ((uint16)__ghsbegin_M4AppEndFlag[29] << 8));
  if(Fblm_CodeflashChecksumValue == CheckSum)
  {
    Fblm_CheckIfResultIsOk = TRUE; /*TRUE : PASS*/
  }
  else
  {
    Fblm_CheckIfResultIsOk = FALSE;  /*FALSE: FAIL*/
  }
  return Fblm_CheckIfResultIsOk;
}

/*----------------------------------------------------------------------------*/
/*Name : Fblm_PreInit    			                                          */
/*Role : Initialize hardware/application module 						      */
/*Interface :                                                                 */
/*  - IN  : none	                                                          */
/*  - OUT : none  							                                  */
/*Pre-condition : none			                                              */
/*Constraints   : none             			                                  */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [initialize parameters and main loop]                                   */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
uint8 Fblm_GetAPPChecksumResult(void)
{
  return Fblm_CheckIfResultIsOk;
}


/*----------------------------------------------------------------------------*/
/*Name : Fblm_IsExistProgRequest    			                              */
/*Role : Read reprogramming request flag from data flash                      */
/*Interface :                                                                 */
/*  - IN  : none	                                                          */
/*  - OUT : FblProgRequest or FblNoProgRequest					              */
/*Pre-condition : none			                                              */
/*Constraints   : none             			                                  */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [initialize parameters and main loop]                                   */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
ubyte Fblm_IsExistProgRequest(void)
{
    ubyte progReqFlag = 0x00u;

    /*TEST CODE*/
#if 0
    EEPC_WriteEepromId(EEPC_ID_BOOTLOADER_INFO);
    EEPS_RamBootloaderInfo[0]=0x00;
    EEPC_WriteEepromId(EEPC_ID_BOOTLOADER_INFO);
#endif
    //BootFlag = kEepFblCANReprogram;
    if (TRUE/*kFblOk == ApplFblReadProgReqFlag(&progReqFlag)*/)
    {
        if (kEepFblCANReprogram == BootFlag/*progReqFlag*/)
        {
            BootFlag = 0;
            /*progReqFlag = 0x00u;*/
           /* (void)ApplFblWriteProgReqFlag(&progReqFlag);*///to do
            Fblm_SetUpdateMode(UPDATE_MODE_CAN);

            return FblProgRequest;
        }
        else if (kEepFblOTAReprogram == BootFlag/*progReqFlag*/)
        {
            //Fblm_SetUpdateMode(UPDATE_MODE_OTA);
            return FblProgRequest;
        }
        else
        {
            /*do nothing*/
        }

    }

    return FblNoProgRequest;
}

/*----------------------------------------------------------------------------*/
/*Name : Fblm_IsApplicationValid    			                              */
/*Role : judge application software is valid or not                           */
/*Interface :                                                                 */
/*  - IN  : none	                                                          */
/*  - OUT : FblApplValid or FblApplInvalid					                  */
/*Pre-condition : none			                                              */
/*Constraints   : none             			                                  */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [initialize parameters and main loop]                                   */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
ubyte Fblm_IsApplicationValid(void)
{
    if ((FblApplValid == Fblm_IsM4ApplicationValid()) &&\
       (FblApplValid == Fblm_IsBootCompatibleWithApp()))
    {
        return FblApplValid;
    }
    else
    {
        return FblApplInvalid;
    }
}

/*----------------------------------------------------------------------------*/
/*Name : Fblm_IsMemoryProtectedArea    			                              */
/*Role : judge memory is being protected or not                               */
/*Interface :                                                                 */
/*  - IN  : none	                                                          */
/*  - OUT : TRUE or FALSE                					                  */
/*Pre-condition : none			                                              */
/*Constraints   : none             			                                  */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [Bootloader only can upgrade APP,can't erase and upgrade self memory!!!]*/
/*    [Once erase bootloader's memory in bootloader,it may be system crash!!!]*/
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
ubyte Fblm_IsMemoryProtectedArea(ulong address,ulong size)
{
 if (((address >= BootFlashStartAdd) && (address <= BootFlashEndAdd))\
         || (((address+size) >= BootFlashStartAdd) && ((address+size) <= BootFlashEndAdd)))
 {
     return TRUE;
 }
 else
 {
     return FALSE;
 }
}
//to do,if jump to app,stop necessary peripheral
/*----------------------------------------------------------------------------*/
/*Name : Fblm_TimerStop			    			                              */
/*Role : Stop timer before reset                          					  */
/*Interface :                                                                 */
/*  - IN  : none	                                                          */
/*  - OUT : none											                  */
/*Pre-condition : none			                                              */
/*Constraints   : none             			                                  */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [initialize parameters and main loop]                                   */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
void Fblm_TimerStop(void)
{
    Cy_Tcpwm_Counter_Disable(TCPWM0_GRP0_CNT0);
  Cy_Tcpwm_Counter_Disable(TCPWM0_GRP2_CNT0);
}

/*----------------------------------------------------------------------------*/
/*Name : Fblm_Reset  			    			                              */
/*Role : Reset MCU				                           					  */
/*Interface :                                                                 */
/*  - IN  : none	                                                          */
/*  - OUT : none											                  */
/*Pre-condition : none			                                              */
/*Constraints   : none             			                                  */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [initialize parameters and main loop]                                   */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
void Fblm_Reset(void)
{
    SYST_Reset();
    while(1);
}

/*----------------------------------------------------------------------------*/
/*Name : Fblm_RequestForReset  			    			                      */
/*Role : Reset MCU				                           					  */
/*Interface :                                                                 */
/*  - IN  : none	                                                          */
/*  - OUT : none											                  */
/*Pre-condition : none			                                              */
/*Constraints   : none             			                                  */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [initialize parameters and main loop]                                   */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
void Fblm_RequestForReset(void)
{
  Fblm_RequestForResetFlag = TRUE;
}

/*----------------------------------------------------------------------------*/
/*Name : Fblm_RequestForReset  			    			                      */
/*Role : Reset MCU				                           					  */
/*Interface :                                                                 */
/*  - IN  : none	                                                          */
/*  - OUT : none											                  */
/*Pre-condition : none			                                              */
/*Constraints   : none             			                                  */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [initialize parameters and main loop]                                   */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
ubyte Fblm_GetRequestForReset(void)
{
  return Fblm_RequestForResetFlag;
}

/*----------------------------------------------------------------------------*/
/*Name : Fblm_ManageResetAction  			    			                  */
/*Role : Reset MCU				                           					  */
/*Interface :                                                                 */
/*  - IN  : none	                                                          */
/*  - OUT : none											                  */
/*Pre-condition : none			                                              */
/*Constraints   : none             			                                  */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [initialize parameters and main loop]                                   */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
void Fblm_ManageResetAction(void)
{
  /*need to wait All queues of Async Write are free */
  /* GEFDCM-180 If the condition(Fblm_GetWriteQueueBufferFreeSts) is not true, wait for 1s and then reset.  
    Avoid the situation that the customer cannot reset after sending 1181.*/
  if(TRUE == Fblm_GetRequestForReset() && ((TRUE == Fblm_GetWriteQueueBufferFreeSts()) || (FBLM_TIMTRESET_PERIOD == FBLM_TimeoutResetCount)))
  {
    /* Disable tester present timeout monitoring */
    StopTesterTimeout();
    /*Reset internal FBL states*/
    fblStates = 0;
    /*Stop timer to avoid a timer interrupt after application start */
    Fblm_TimerStop();
    /* Sbcc_Reset(); */
    Fblm_Reset();
  }
}


/*______ P R I V A T E - F U N C T I O N S ___________________________________*/
/*----------------------------------------------------------------------------*/
/*Name : Fblm_GetTimerValue			    			                          */
/*Role : Returns the value in timer counter                          		  */
/*Interface :                                                                 */
/*  - IN  : none	                                                          */
/*  - OUT : none											                  */
/*Pre-condition : none			                                              */
/*Constraints   : none             			                                  */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [initialize parameters and main loop]                                   */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
ulong Fblm_GetTimerValue(void)
{
  return ((ulong) Cy_Tcpwm_Counter_GetCounter(TCPWM0_GRP0_CNT0));
}

ulong Fblm_GptGetTimeElapsed(void)
{
  return ((ulong) Cy_Tcpwm_Counter_GetCounter(TCPWM0_GRP2_CNT0));
}

/******************************************************************************
* Name         :  Fblm_ReadDataByIdentifier
* Called by    :  Diagnostic module
* Preconditions:  None
* Parameters   :  pbDiagData:     Pointer to diag service data (Sub ID!!)
*                 diagReqDataLen: Service data length (without SID!!)
* Return code  :  None
* Description  :  ReadDataByIdentifier service function.
******************************************************************************/
void Fblm_ReadDataByIdentifier(ubyte *pbDiagData, ushort diagReqDataLen)
{
    ushort diagRespDataLen = 0u;
    ushort didIdx = 0u;
    ushort outIdx = 0u;
    ushort outIdxAdd = 0u;
    ushort currentDid = 0u;
    ushort didNo = 0u;
    ubyte  didBuffer[(FBLM_MAX_DID_COUNT << 1)] = {0u};
    ushort i = 0u;
    ushort j = 0u;
    ushort index = 0u;
    ushort length = 0u;

    ubyte* diagData = NULL;

    /* Check diagnostic request length */
    if (    (diagReqDataLen < kDiagRqlReadDataByIdentifier)
    || ((diagReqDataLen % 2) != 0)
    )
    {
        DiagNRCIncorrectMessageLengthOrInvalidFormat();
        return;
    }

    didNo = (diagReqDataLen / 2);/*After $22 SID,is all didNo,2 bytes is one DID,maybe several DID*/

    if (didNo > FBLM_MAX_DID_COUNT)
    {
        DiagNRCRequestOutOfRange();
        return;
    }

    for (i = 0; i < diagReqDataLen; i++)
    {
        didBuffer[i] = pbDiagData[i];/*Store DID into buffer*/
    }

    outIdx = 0;
    didIdx = 0;

    for (i = 0; i < didNo; i++)
    {
        currentDid =  (ushort)(didBuffer[didIdx] << 8);
        currentDid |= (ushort)(didBuffer[didIdx+1]);
        diagData = &pbDiagData[outIdx];
        diagData[0] = didBuffer[didIdx];
        diagData[1] = didBuffer[didIdx+1];

        didIdx += 2;/*Prepare for next DID*/
        outIdxAdd = 0;
    }

    for (j = 0; j < (sizeof(didTable)/sizeof(tDid)); j++)
    {
        if (didTable[j].did == currentDid)
        {
            outIdxAdd = didTable[j].maxSize;
            break;
        }
    }

    if (0u != outIdxAdd)/*DID in didTable*/
    {
        if ((outIdx + outIdxAdd) > (FBL_DIAG_BUFFER_LENGTH - 1))
        {
            DiagNRCRequestOutOfRange();
            return;
        }
        switch (currentDid)
        {
            /* -- BootPrimaryBootloaderVersion-- */
            case Fblm_Primary_Bootloader_Version_F1FA:
                for(index = 0u; index < kDiagRqlDataByIdentifierVersionPrintParameter; index++)
                {
                    diagData[2 +index] = VERS_BootInfo[index];
                }
                break;

            /*Public Key */
            case Fblm_Public_Key_Did_D01C:
                /*ZCBD-519 :reply By RAM data to reduce reposnse time */
                if(Fblm_PublicKeyNoDefaultStatus != VERS_GetPublicKeyDataPublicKeyProgramFlag())
                {
                    DiagNRCConditionsNotCorrect();
                    DiagProcessingDone(0);
                    return;
                }
                else
                {
                    VERS_GetPublicKeyDataPublicKeyCheckSum(&diagData[2], sizeof(WDFS_RamBootPara.PublicKeyData.PublicKeyCheckSum));
                }
                break;

            /*Primary Bootloader Diagnostic Database Part Number*/
            case Fblm_PrimaryBootDiagDataPN_Did_F121:
                memset(&diagData[2], 0, 7);
                break;

            /* Primary Bootloader Software Part Number*/
            case Fblm_PrimaryBootSwPN_Did_F125:
                memset(&diagData[2], 0, 7);
                break;

            /*ECU Core Assembly Part Number*/
            case Fblm_EcuCoreAssemblPN_Did_F12A:
                memset(&diagData[2], 0, 7);
                break;

            /*ECU Delivery Assembly Part Number*/
            case Fblm_EcuDeliveryAssemblyPN_Did_F12B:
                memset(&diagData[2], 0, 7);
                break;

            /*Active Diagnostic Session*/
            case Fblm_ActiveDiagSession_Did_F186:

                if (GetDiagProgrammingSession())
                {
                    /*program session*/
                    diagData[2] = kDiagSubProgrammingSession;
                }
                else if (GetDiagExtendedDiagSession())
                {
                    diagData[2] = kDiagSubExtendedDiagSession;
                }
                else
                {
                    diagData[2] = kDiagSubDefaultSession;
                }

                break;
            case Fblm_SystemSupplierIdentifier_Did_F18A:
                memset(&diagData[2], 0, 6); 
                break;

            /*ECU Serial Number*/
            case Fblm_EcuSerialNum_Did_F18C:
                if(EOL_CHECKEOLDONE == 0xFF)
                {
                    /*Read Data from NVM*/
                    for (index = 0U; index < 4U ; index++)
                    {
                        diagData[index + 2u] = WDFS_RamIDOptionSecurity.IdOptionData.ECUSerialNumber[index];
                    }
                }
                else
                {
                    /*Read Data from CodeFlash*/
                    memcpy(&diagData[index + 2],Fblm_CodeFlashSector_RAMAdrTbl[Fblm_F18CID].Address_CodeFlash,Fblm_CodeFlashSector_RAMAdrTbl[Fblm_F18CID].length);
                }
                break;

            /* Primary Bootloader Diagnostic Database Part Number Geely*/
            case Fblm_PrimaryBootDiagDataPN_Geely_Did_F1A1:
                if(EOL_CHECKEOLDONE == 0xFF)
                {
                    /*Read Data from NVM*/
                    for (index = 0U; index < 8; index++)
                    {
                        diagData[index + 2] = WDFS_RamPart_Number_Geely.PN_F1A1[index];
                    }
                }
                else
                {
                    /*Read Data from CodeFlash*/
                    memcpy(&diagData[index + 2],Fblm_CodeFlashSector_RAMAdrTbl[Fblm_F1A1ID].Address_CodeFlash,Fblm_CodeFlashSector_RAMAdrTbl[Fblm_F1A1ID].length);
                }
                break;

            /* Primary Bootloader Software Part Number Geely*/
            case Fblm_PrimaryBootDiagSwPN_Geely_Did_F1A5:
                if(EOL_CHECKEOLDONE == 0xFF)
                {
                    /*Read Data from NVM*/
                    for (index = 0U; index < 8; index++)
                    {
                        diagData[index + 2] = WDFS_RamPart_Number_Geely.PN_F1A5[index];
                    }
                }
                else
                {
                    /*Read Data from CodeFlash*/
                    memcpy(&diagData[index + 2],Fblm_CodeFlashSector_RAMAdrTbl[Fblm_F1A5ID].Address_CodeFlash,Fblm_CodeFlashSector_RAMAdrTbl[Fblm_F1A5ID].length);
                }
                break;

            /* ECU Core Assembly Part Number Geely*/
            case Fblm_EcuCoreAssemblyPN_Geely_Did_F1AA:
                if(EOL_CHECKEOLDONE == 0xFF)
                {
                    /*Read Data from NVM*/
                    for (index = 0U; index < 8; index++)
                    {
                        diagData[index + 2] = WDFS_RamPart_Number_Geely.PN_F1AA[index];
                    }
                }
                else
                {
                    /*Read Data from CodeFlash*/
                    memcpy(&diagData[index + 2],Fblm_CodeFlashSector_RAMAdrTbl[Fblm_F1AAID].Address_CodeFlash,Fblm_CodeFlashSector_RAMAdrTbl[Fblm_F1AAID].length);
                }
                break;

            /*ECU Delivery Assembly Part Number Geely*/
            case Fblm_EcuDeliveryAssemblyPN_Geely_Did_F1AB:
                if(EOL_CHECKEOLDONE == 0xFF)
                {
                    /*Read Data from NVM*/
                    for (index = 0U; index < 8; index++)
                    {
                        diagData[index + 2] = WDFS_RamPart_Number_Geely.PN_F1AB[index];
                    }
                }
                else
                {
                    /*Read Data from CodeFlash*/
                    memcpy(&diagData[index + 2],Fblm_CodeFlashSector_RAMAdrTbl[Fblm_F1ABID].Address_CodeFlash,Fblm_CodeFlashSector_RAMAdrTbl[Fblm_F1ABID].length);
                }
                break;

            case Fblm_Complete_ECU_Part_Serial_Number_s_PBL_Geely_Did_ED20:
                Fblm_Complete_ECU_Part_Serial_Number_s_PBL_Geely_Did_ED20_Func(&diagData[2]);
                if (TRUE == Fblm_ActivateSblFlag)
                {
                    /* Special handler for PBL response length differ with SBL response length for the same DID */
                    DiagProcessingDone(kDiagRqlReadDataByIdentifier + 45u);
                    return;
                }
                break;

            case Fblm_Complete_ECU_Part_Serial_Number_s_Did_EDA0:
                Fblm_Complete_ECU_Part_Serial_Number_s_Did_EDA0_Func(&diagData[2]);
                break;

            /*Only support on Secondary bootloader*/
            /*Primary Bootloader Diagnostic Database Part Number*/
            case Fblm_SecondaryBootDiagDataPN_Did_F122:
                if(TRUE == Fblm_ActivateSblFlag)
                {
                    memset(&diagData[2], 0, 7);
                }
                else
                {
                    DiagNRCRequestOutOfRange();
                }
                break;

            /* Primary Bootloader Software Part Number*/
            case Fblm_SecondaryBootSwPN_Did_F124:
                if(TRUE == Fblm_ActivateSblFlag)
                {
                    for(index = 0u; index < outIdxAdd - 2u; index++)
                    {
                        diagData[2u + index] = Fblm_F124_Ver[index];
                    }
                }
                else
                {
                    DiagNRCRequestOutOfRange();
                }
                break;
            /* Primary Bootloader Diagnostic Database Part Number Geely*/
            case Fblm_SecondaryBootDiagDataPN_Geely_Did_F1A2:
                if(TRUE == Fblm_ActivateSblFlag)
                {
                    for(index = 0u; index < outIdxAdd - 2u; index++)
                    {
                        diagData[2u + index] = Fblm_F1A2_PN[index];
                    }
                }
                else
                {
                    DiagNRCRequestOutOfRange();
                }
                break;
            default:
                DiagNRCRequestOutOfRange();
                break;
        }

        outIdx += outIdxAdd;
    }
    else
    {
        DiagNRCRequestOutOfRange();
    }

    diagRespDataLen = outIdx;

    /*
    Transmit response message:
    If a negative response has to be transmitted, the length parameter is
    ignored. In case of a positive response, the length parameter does not
    include the service id.
    */
    if(Fblm_IsReadNvmBlock == FALSE)
    {
        DiagProcessingDone(diagRespDataLen);
    }

}

/*----------------------------------------------------------------------------*/
/*Name : Fblm_NvMTask			    			                              */
/*Role : NvM Task                          	                            	  */
/*Interface :                                                                 */
/*  - IN  : none	                                                          */
/*  - OUT : none											                  */
/*Pre-condition : none			                                              */
/*Constraints   : none             			                                  */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*                                                                            */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
void Fblm_SyncNvMTask(void)
{
    NvM_RequestResultType NvMRequestResult;
    if(Fblm_IsReadWriteNvmBlock == TRUE)  /*Write Handler*/
    {
      if(IsWriteReadNvm == FALSE)
      {
        if(E_OK == NvM_WriteBlock(Fblm_CurrentNvMBlockId,&Fblm_ReadWriteNvmBlockData[0]))
        {
          IsWriteReadNvm = TRUE;
        }
      }
      else
      {
        if(E_OK == NvM_GetErrorStatus(Fblm_CurrentNvMBlockId,&NvMRequestResult))
        {
          if(NVM_REQ_OK == NvMRequestResult || (NVM_REQ_RESTORED_FROM_ROM == NvMRequestResult))
          {
            /*Some DID need special deal*/
            if(NvMConf_NvMBlockDescriptor_WDFC_ID_BOOT_PARA == Fblm_CurrentNvMBlockId)
            {
                /*update SecurityConstantLevel Only after Write OK */
                for(uint8 i = 0; i < 16; i++)
                {
                  Fblm_SecurityConstantLevel[i] = WDFS_RamBootPara.BootDataConfig.FixedByte[i];
                }
              /*update Public_Key Only after Write OK */
              for(uint16 i = 0; i < 256; i++)
              {
                Fblm_PublicKeyData[i] = WDFS_RamBootPara.PublicKeyData.PublicKeyModulus[i];
              }
              for(uint8 i = 0; i < 4; i++)
              {
                Fblm_PublicKeyExponent[i] = WDFS_RamBootPara.PublicKeyData.PublicKeyExponent[i];
              }
            }
            else if(NvMConf_NvMBlockDescriptor_WDFC_ID_ECUID_RDI_PROGRAMMING_INFO == Fblm_CurrentNvMBlockId)
            {
                /*When CAN send erase command, MCU will set PROGRAMMING_INFO flag, and then erase app here*/
                if(TRUE == Fblm_RunRoutineIdEraseMemoryFlag)
                {
                    /* Erase memory */
                    Fblm_RunRoutineIdEraseMemoryFlag = FALSE;
                    if(kFblOk == Fblm_EraseRoutine(Fblm_EraseMemoryAddress,Fblm_ErasememorySize))
                    {
                        /* GEFDCM-52  Set the flag bit after erasing, and clear it after performing 36 services. */
                        fblm_EraseFlag.APP_EraseSucceeded = 1;
                        Fblm_AppFlashSigntureSucFlag = FALSE;
                        SetEraseSucceeded();
                    }
                    else
                    {
                        /* Negative response */
                        //DiagBuffer[kDiagFmtRoutineIdDataRecord] = 0x05;
                        ClrEraseSucceeded();
                        DiagNRCGeneralProgrammingFailure(); /*otherwise negative response shall be returned (see cs.00100 for NRC code*/
                    
                        Fblm_IsReadWriteNvmBlock = FALSE; /*don't take DiagProcessingDone*/
                        IsWriteReadNvm = FALSE;
                        Fblm_SyncReqForRunningNvmFeeFlsTask = FALSE;
                        return;
                    }
                }
            }
            DiagProcessingDone(Fblm_DiagRespDataLen);
            Fblm_IsReadWriteNvmBlock = FALSE;
            IsWriteReadNvm = FALSE;
            Fblm_SyncReqForRunningNvmFeeFlsTask = FALSE;
          }
          else if(NVM_REQ_NOT_OK == NvMRequestResult)
          {
            DiagNRCGeneralProgrammingFailure();
            DiagProcessingDone(0);
            Fblm_IsReadWriteNvmBlock = FALSE;
            IsWriteReadNvm = FALSE;

            /*Some DID need to special deal*/
            if(FBLM_BOOT_PARA_PUBLIC_KEY == FBLM_BootParaSubId) /* need bilun to modify*/
            {
              /*If write nok, it revert value*/
              VERS_SetPublicKeyDataPublicKeyProgramFlag(Fblm_PublicKeyDefaultStatus);
              FBLM_BootParaSubId = FBLM_BOOT_PARA_UNKNOW;
            }
            else if(FBLM_BOOT_PARA_BOOT_DATA == FBLM_BootParaSubId) /* need bilun to modify*/
            {
              /*If write nok, it revert value*/
              VERS_SetBootDataConfigProgramFlag(Fblm_BootDataConfigDefaultStatus);
              FBLM_BootParaSubId = FBLM_BOOT_PARA_UNKNOW;
            }
            else
            {
                /*do nothing*/
            }
            Fblm_SyncReqForRunningNvmFeeFlsTask = FALSE;
          }
          else
          {
            ;//nothing
          }
        }
        else
        {
        /*Return Error*/
        }
      }
    }
    if(Fblm_IsReadNvmBlock) /*Read Handler*/
    {
      if(IsWriteReadNvm == FALSE)
      {
          for(int i = 0;i< Fblm_ReadWriteNvmBlockDataMaxLen;i++)
          {
              Fblm_ReadWriteNvmBlockData[i] = 0;
          }
          NvMRequestResult = NvM_ReadBlock(Fblm_CurrentNvMBlockId,&Fblm_ReadWriteNvmBlockData[0]);
          if((NVM_REQ_OK == NvMRequestResult))
          {
              IsWriteReadNvm = TRUE;
      }
    }
    else
    {
      if(NVM_REQ_OK == NvM_GetErrorStatus(Fblm_CurrentNvMBlockId,&NvMRequestResult))
      {
        if((NVM_REQ_OK == NvMRequestResult) || (NVM_REQ_RESTORED_FROM_ROM == NvMRequestResult))
          {

          if(Fblm_DiagData != NULL)
          {
            /*copy data to respond data*/
            memcpy(&Fblm_DiagData[2],&Fblm_ReadWriteNvmBlockData[0],Fblm_DiagRespDataLen);
          }
          DiagProcessingDone(Fblm_DiagRespDataLen);
          Fblm_IsReadNvmBlock = FALSE;
          IsWriteReadNvm = FALSE;
          Fblm_SyncReqForRunningNvmFeeFlsTask = FALSE;
        }
          else if(NVM_REQ_NOT_OK == NvMRequestResult)
          {
            DiagNRCGeneralProgrammingFailure();
            DiagProcessingDone(0);
            Fblm_IsReadNvmBlock = FALSE;
            IsWriteReadNvm = FALSE;
            Fblm_SyncReqForRunningNvmFeeFlsTask = FALSE;
          }
          else
          {
            ;/*nothing*/
          }

      }

    }
  }
}


/*----------------------------------------------------------------------------*/
/*Name : Fblm_GetSyncWriteFreeSts			    			                  */
/*Role : NvM Task                          	                            	  */
/*Interface :                                                                 */
/*  - IN  : none	                                                          */
/*  - OUT : none											                  */
/*Pre-condition : none			                                              */
/*Constraints   : none             			                                  */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*                                                                            */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
ubyte Fblm_GetSyncWriteFreeSts(void)
{
  uint8 Ret = FALSE;
  if((TRUE != Fblm_IsReadNvmBlock) && (TRUE != Fblm_IsReadWriteNvmBlock))
  {
    Ret = TRUE;
  }
  return Ret;
}

/*----------------------------------------------------------------------------*/
/*Name : Fblm_AsyncWriteNvmTask			    			                      */
/*Role : NvM Task                          	                            	  */
/*Interface :                                                                 */
/*  - IN  : none	                                                          */
/*  - OUT : none											                  */
/*Pre-condition : none			                                              */
/*Constraints   : none             			                                  */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*                                                                            */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
void Fblm_AsyncWriteNvmTask(void)
{
  NvM_RequestResultType NvMRequestResult;
  /*If mcu don't enter Sync write or read,it can enter async write*/
  if(TRUE == Fblm_GetSyncWriteFreeSts())
  {
    if(TRUE == Fblm_IsAsyncWriteNvmBlockhandle)
    {
      if(Fblm_IsAsyncWriteNvmBlock == FALSE)
      {
        if(E_OK == NvM_WriteBlock(Fblm_AsyncWriteCurrentNvMBlockId,&Fblm_AsyncWriteNvmBlockDataBuf[0]))
        {
          Fblm_IsAsyncWriteNvmBlock = TRUE;
        }
      }
      else
      {
        if(E_OK == NvM_GetErrorStatus(Fblm_AsyncWriteCurrentNvMBlockId,&NvMRequestResult))
        {
          if(NVM_REQ_OK == NvMRequestResult || (NVM_REQ_RESTORED_FROM_ROM == NvMRequestResult))
          {

              Fblm_IsAsyncWriteNvmBlock = FALSE;
              Fblm_IsAsyncWriteNvmBlockhandle = FALSE;
              Fblm_InitASyncWriteQueue(Fblm_QueueOfMinReqStep); /*When Finish , reinit the queue again*/
              Fblm_AsyncReqForRunningNvmFeeFlsTask = FALSE;
          }
          else if(NVM_REQ_NOT_OK == NvMRequestResult)
          {
              Fblm_IsAsyncWriteNvmBlock = FALSE;
              Fblm_IsAsyncWriteNvmBlockhandle = FALSE;
              Fblm_InitASyncWriteQueue(Fblm_QueueOfMinReqStep);  /*When Finish , reinit the queue again*/
              Fblm_AsyncReqForRunningNvmFeeFlsTask = FALSE;
          }

        }
        else
        {
        /*Return Error*/
        }
      }
    }
  }

}

/******************************************************************************/
/*Name : Fblm_SetSecurityAccessUnlockedL1AttemptCounter                       */
/*Role:  Set Security Access Unlocked L1(27 01_02) attempt counter from NVM   */
/*Interface :                                                                 */
/*Pre-condition :                                                             */
/*Constraints: -                                                              */
/*Behaviour:                                                                  */
/******************************************************************************/
uint8 Fblm_SetSecurityAccessUnlockedL1AttemptCounter(uint8 AttemptCounter)
{
  uint8 ret = kDiagErrorNone;
  Fblm_NvmWriteResult_t NvmWriteResult = Fblm_NVM_WRITE_PENDING;
  uint8 AttemptCounterTmp = AttemptCounter;

#if 0   /*need to Async write*/
  if (FALSE == Fblm_NvmWriteReqStart)
  {
#endif
    /* Limit to 3 to avoid overflow */
    if (AttemptCounterTmp > kSecMaxInvalidKeys)
    {
      AttemptCounterTmp = (uint8)(0xFFu & (kSecMaxInvalidKeys + 1u));
    }
    #if 0 /*GEFDCM-299  BT716929 -- The false attempts shall be reset to zero (0): ECU Reset to start again.  */
    if(WDFS_RamBootPara.BootSwFingerprint.SAFailedAccessCounter_L1 != AttemptCounterTmp)
    {
      if(WDFS_RamBootPara.BootSwFingerprint.SAFailedAccessCounter_L1 == 0)
      {
        Fblm_NvmImmediateWriteBlock(NvMConf_NvMBlockDescriptor_WDFC_ID_BOOT_PARA,(ubyte *)&WDFS_RamBootPara);
      }
      else
      {
        /* the first times to write NVM would take too much time after erase ALL NVM data, need take about 130 ms，and
        the P2server time is 25ms，so when the AttemptCounter more then 0, use the Asynwrite mode*/
        Fblm_AsyncWriteNvmData(WDFC_SIZE_BOOT_PARA,\
        NvMConf_NvMBlockDescriptor_WDFC_ID_BOOT_PARA, (ubyte *)&WDFS_RamBootPara);
      }
    }
    #endif 
  return ret;
}

/*----------------------------------------------------------------------------*/
/*Name : Fblm_ReadWriteNvmBlockStatus			    			              */
/*Role : Read and Write Nvm Block Status                          	          */
/*Interface :                                                                 */
/*  - IN  : none	                                                          */
/*  - OUT : none											                  */
/*Pre-condition : none			                                              */
/*Constraints   : none             			                                  */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*                                                                            */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
boolean Fblm_ReadWriteNvmBlockStatus(void)
{
    return Fblm_IsReadWriteNvmBlock;
}

/******************************************************************************
* Name         :  ApplDiagWriteDataByIdentifier
* Called by    :  Diagnostic module
* Preconditions:  None
* Parameters   :  pbDiagData:     Pointer to diag service data (AFTER SID!!)
*                 diagReqDataLen: Service data length (without SID!!)
* Return code  :  kFblOk:         WriteDataByIdentifer was successful.
*                 KFblFailed:     WriteDataByIdentifier failed.
*                 kDiagReturnValidationOk: This is special return code for
*                                 Write Fingerprint. It will be returned, if
*                                 the fingerprint is written and no error
*                                 occurs.
* Description  :  WriteDataByIdentifier service function.
******************************************************************************/
ubyte Fblm_WriteDataByIdentifier(ubyte *pbDiagData, ushort diagReqDataLen)
{
    /* Two-byte routine identifier */
    ushort diagFmtDataId = 0u;
    /*Read two-byte routineControlId (min. length already checked)*/
    diagFmtDataId =  (ushort)(((ushort)pbDiagData[0]) << 8);
    diagFmtDataId |= (ushort)(pbDiagData[1]);

    switch(diagFmtDataId)
    {
      /* -- write TesterSerNum/ProgDate -- */
      case (Fblm_Public_Key_Did_D01C):
            /* Check request length */
            if (DiagDataLength != kDiagRqlWriteDataByIdentifierPublicKey)
            {
                DiagNRCIncorrectMessageLengthOrInvalidFormat();
                return kFblFailed;
            }
            if (!GetDiagProgrammingSession())/*Only programming session support*/
            {
                /* Not supported in non-programming session */
                DiagNRCRequestOutOfRange();
                return kFblFailed;
            }
            if(Fblm_PublicKeyNoDefaultStatus == VERS_GetPublicKeyDataPublicKeyProgramFlag())
            {
                /* Public Key shall only be possible to write once */
                DiagNRCConditionsNotCorrect();
                return kFblFailed;
            }
            /* Check security access state */
            /*		 if (!GetSecurityUnlock())     //On boot Mode, Service $2E don't need to unlock.
            {
                DiagNRCSecurityAccessDenied();
                return kFblFailed;
            }*/

            if(TRUE != RSAM_CheckMemoryHash256(&pbDiagData[2],&pbDiagData[2+kDiagPublicKeyValidDataLength],kDiagPublicKeyValidDataLength))
            {
                DiagNRCIncorrectMessageLengthOrInvalidFormat();
                return kFblFailed;
            }

            memcpy(&WDFS_RamBootPara.PublicKeyData,&pbDiagData[2],292);
            VERS_SetPublicKeyDataPublicKeyProgramFlag(Fblm_PublicKeyNoDefaultStatus);
            FBLM_BootParaSubId = FBLM_BOOT_PARA_PUBLIC_KEY;
            /*it should use total length of public key to write programflag,spare and checksum */
            Fblm_SyncWriteNvmData(WDFC_SIZE_BOOT_PARA, \
                                NvMConf_NvMBlockDescriptor_WDFC_ID_BOOT_PARA, \
                                            kDiagRslWriteDataByIdentifier, (ubyte *)&WDFS_RamBootPara);
            return kDiagReturnValidationOk;

            break;
        case (Fblm_SecurityConstantLevel_F109):
            if(TRUE == Fblm_ActivateSblFlag)
            {
                /* Check request length */
                if (DiagDataLength != kDiagRqlDataByIdentifierSecurityConstantLevel)
                {
                    DiagNRCIncorrectMessageLengthOrInvalidFormat();
                    return kFblFailed;
                }
                if (!GetDiagProgrammingSession())/*Only programming session support*/
                {
                    /* Not supported in non-programming session */
                    DiagNRCRequestOutOfRange();
                    return kFblFailed;
                }
                if(Fblm_BootDataConfigNoDefaultStatus == VERS_GetBootDataConfigProgramFlag())
                {
                    /* Boot Data shall only be possible to write once */
                    DiagNRCConditionsNotCorrect();
                    return kFblFailed;
                }
                /* Check security access state */
            /*		 if (!GetSecurityUnlock())  //On boot Mode, Service $2E don't need to unlock.
                {
                DiagNRCSecurityAccessDenied();
                return kFblFailed;
                }*/

                for(uint8 i = 0; i < 16; i++)
                {
                    WDFS_RamBootPara.BootDataConfig.FixedByte[i] = pbDiagData[i + 2];
                }
                VERS_SetBootDataConfigProgramFlag(Fblm_BootDataConfigNoDefaultStatus);
                FBLM_BootParaSubId = FBLM_BOOT_PARA_BOOT_DATA;
                Fblm_SyncWriteNvmData(WDFC_SIZE_BOOT_PARA,\
                                    NvMConf_NvMBlockDescriptor_WDFC_ID_BOOT_PARA, \
                                                kDiagRslWriteDataByIdentifier, (ubyte *)&WDFS_RamBootPara);
                return kDiagReturnValidationOk;
            }
            else
            {
                DiagNRCRequestOutOfRange();
            }
            break;
        default:
            DiagNRCRequestOutOfRange();
            break;

    }

    return kFblOk;
}

/******************************************************************************/
/* Private helper: avalanche mix of three 32-bit values                       */
/******************************************************************************/
static uint32 Fblm_Mix32(uint32 a, uint32 b, uint32 c)
{
    uint32 v = a ^ (b + 0x9E3779B9u + (a << 6) + (a >> 2));
    v ^= c * 0x85EBCA6Bu;
    v ^= v >> 16; v *= 0x7FEB352Du;
    v ^= v >> 15; v *= 0x846CA68Bu;
    v ^= v >> 16;
    return v;
}

/******************************************************************************
* Name         :  Fblm_GenerateSecuritySeed
* Called by    :  Diagnostic module
* Preconditions:  None
* Parameters   :  None
* Return code  :  Status of seed generation
* Description  :  This function is called when the tester requests the
*                 security seed.
******************************************************************************/
ubyte Fblm_GenerateSecuritySeed(void)
{
    ubyte i = 0u;
    ubyte j = 0u;
    ulong srandSeed = 0u;
    ulong srandSeed1 = 0u;
    ulong srandSeed2 = 0u;

    /* Boot counter -- monotonic, never self-cancels like XOR chain */
    SeedCntBackupRam++;

    srandSeed1 = Fblm_GptGetTimeElapsed();
    srandSeed2 = SeedBackupRam ^ Fblm_GetTimerValue();

    srandSeed = Fblm_Mix32(srandSeed1, srandSeed2, SeedCntBackupRam);
    srand(srandSeed);
    SeedBackupRam = srandSeed;   /* mixed value, stronger than XOR chain */

   if(0/* securitySeedResponse == kSeedAlreadyRequested */)
   {
       /*
          If "Request Seed 27 11" was requested more like one time without key request
          => the last seed must be sent to the Tester
       */

   }
   else/*generate new seed*/
   {
        if (isArrayZero(AES_Seed,kSecSeedLength))
        {
            /* Always generate seed */
            for (j = 0; j < kSecSeedLength; j++)
            {
                AES_Seed[j] = (uint8_t)((rand() + j * 13) ^ (Fblm_GptGetTimeElapsed() >> (j % 4)) ^ SeedBackupRam);
            }

            /* Inject monotonic counter into seed bytes for guaranteed uniqueness across boots */
            for (j = 0; j < 4; j++)
            {
                AES_Seed[j] ^= (uint8)(SeedCntBackupRam >> (j * 8));
            }
        } 

        if (isArrayZero(AES_Seed,kSecSeedLength))/*Obtain counter two times,no reason for this*/
        {
            return kFblFailed;
        }
   }
   /* Initialize response length */
   DiagDataLength = kSecSeedLength+1;
   /* Save last seed */
   memcpy(lastAES_Seed, AES_Seed, kSecSeedLength);
   //memcpy(lastAES_Seed, seedArray, 16);//Test code

   /* Write seed valued into DiagBuffer */
   for (i = 0; i < kSecSeedLength; i++)
   {
      DiagBuffer[(kDiagFmtSubparam + kSecSeedLength) - i] = lastAES_Seed[i];
   }

   /* Set seed status to seed requested */
   securitySeedResponse = kSeedAlreadyRequested;

    return kFblOk;
}

/******************************************************************************
* Name         :  Fblm_SecurityVerifyKey
* Called by    :  Diagnostic module
* Preconditions:  None
* Parameters   :  None
* Return code  :  Status of key verification
* Description  :  This function is called when the security key
*                 has been received from tester
******************************************************************************/

ubyte Fblm_SecurityVerifyKey(void)
{
    ubyte i = 0u;

   /* Key received => New seed can be requested */
   securitySeedResponse = kNewSeedRequest;
   /* Get key from DiagBuffer */
    for (i = kDiagFmtSeedKeyStart; i < (kDiagFmtSeedKeyStart + kSecKeyLength); i++)
    {
        keyReceived[i - kDiagFmtSeedKeyStart] = DiagBuffer[i];
    }

    SwapEndianArray(lastAES_Seed,kSecSeedLength); //Endianness conversion


    for (ubyte j = 0; j < kSecSeedLength; j++)
    {
        Security_Constant[j] = Fblm_SecurityConstantLevel[j];
    }

       AES_CMAC(Security_Constant, lastAES_Seed, kSecSeedLength, &AES_keyStored[0]);

   if (memcmp(keyReceived, AES_keyStored, kSecSeedLength) == 0)
   {
       return kFblOk;
   }
   else
   {
        return kFblFailed;
   }
}
/*----------------------------------------------------------------------------*/
/*Name : Fblm_EraseRoutine     			    			              		  */
/*Role : erase memory 										                  */
/*Interface :                                                                 */
/*  - IN  : ulong StartAddress,ulong MemorySize(length)	                      */
/*  - OUT : none											                  */
/*Pre-condition : Start address must be a start address of logicalBlock  	  */
/*Constraints   : none             			                                  */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [initialize parameters and main loop]                                   */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
ubyte Fblm_EraseRoutine(ulong StartAddress,ulong MemorySize)
{
    ubyte i = 0u;
    ubyte blockNo = Invalid_BlockIndex;
    ulong endAddress = 0u;

    ubyte numOfLargeSector = 0u;
    ubyte numOfSmallSector = 0u;

  ubyte erasedSectorsInCycle = 0; 

    Fblm_StartAddress = StartAddress;
    endAddress = StartAddress + MemorySize - 1;
    Fblm_EndAddress = endAddress;

    FBLM_FlashDriverInit();

     /*Use FlashDrive Lib to boundcheck*/
    if ((CY_FLASH_OUT_OF_BOUNDS == FLASH_DRIVER_BOUNDCHECK(Fblm_StartAddress))\
            || (CY_FLASH_OUT_OF_BOUNDS == FLASH_DRIVER_BOUNDCHECK(Fblm_EndAddress)))
    {
        return kFblFailed;
    }/*check address*/

    if ((Fblm_StartAddress < CY_FLASH_LG_SBM_END) && (0u != (Fblm_StartAddress%CY_CODE_LES_SIZE_IN_BYTE)))
    {
        return kFblFailed;
    }

    if ((Fblm_StartAddress >= CY_FLASH_SM_SBM_TOP) && (0u != (Fblm_StartAddress%CY_CODE_SES_SIZE_IN_BYTE)))
    {
        return kFblFailed;
    }

    for (i=0;i<FBL_MTAB_NO_OF_BLOCKS;i++)
    {
         if (Fblm_StartAddress == FblLogicalBlockTable.logicalBlock[i].blockStartAddress)
         {
            blockNo = FblLogicalBlockTable.logicalBlock[i].blockIndex;
            break;
         }
    }
    if (Invalid_BlockIndex == blockNo)
    {
        return kFblFailed;
    }
    else
    {
        /*OK,equal to our private setting,do nothing*/
    }
    /*large sector and small sector,unit of erase is sector*/
    if (Fblm_EndAddress < CY_FLASH_LG_SBM_END)
    {
        /*All are large sector*/
        if (0u == (MemorySize%CY_CODE_LES_SIZE_IN_BYTE))
        {
            numOfLargeSector = MemorySize/CY_CODE_LES_SIZE_IN_BYTE;
        }
        else
        {
            numOfLargeSector = (MemorySize/CY_CODE_LES_SIZE_IN_BYTE)+1;
        }

        for (i = 0; i< numOfLargeSector; i++)
        {
          Fblm_WDRefresh();
         (void)Fblm_LookForWatchdog();
         FLASH_DRIVER_ERASE(Fblm_StartAddress+(CY_CODE_LES_SIZE_IN_BYTE*i), CY_FLASH_DRIVER_NON_BLOCKING);
         Sbcc_WatchdogMonitorFLASH();
        }

    }
    else if (Fblm_StartAddress >= CY_FLASH_SM_SBM_TOP)
    {
        /*All are small sector*/
        if (0u == (MemorySize%CY_CODE_SES_SIZE_IN_BYTE))
        {
            numOfSmallSector = MemorySize/CY_CODE_SES_SIZE_IN_BYTE;
        }
        else
        {
            numOfSmallSector = (MemorySize/CY_CODE_SES_SIZE_IN_BYTE)+1;
        }

        for (i = 0; i< numOfSmallSector; i++)
        {
            Fblm_WDRefresh();
            (void)Fblm_LookForWatchdog();
            FLASH_DRIVER_ERASE(Fblm_StartAddress+(CY_CODE_SES_SIZE_IN_BYTE*i), CY_FLASH_DRIVER_NON_BLOCKING);
            Sbcc_WatchdogMonitorFLASH();
        }
    }
    else
    {
        /*exit both large and small sector*/
        /*address must be n*large sector*/
        numOfLargeSector = (CY_FLASH_SM_SBM_TOP - Fblm_StartAddress)/CY_CODE_LES_SIZE_IN_BYTE;

        if (0u == (Fblm_EndAddress - CY_FLASH_SM_SBM_TOP + 1)%CY_CODE_SES_SIZE_IN_BYTE)
        {
            numOfSmallSector = (Fblm_EndAddress - CY_FLASH_SM_SBM_TOP + 1)/CY_CODE_SES_SIZE_IN_BYTE;
        }
        else
        {
            numOfSmallSector = ((Fblm_EndAddress - CY_FLASH_SM_SBM_TOP + 1)/CY_CODE_SES_SIZE_IN_BYTE)+1;
        }

        for (i = 0; i< numOfLargeSector; i++)
        {
           Fblm_WDRefresh();
          (void)Fblm_LookForWatchdog();
          FLASH_DRIVER_ERASE(Fblm_StartAddress+(CY_CODE_LES_SIZE_IN_BYTE*i), CY_FLASH_DRIVER_NON_BLOCKING);
          Sbcc_WatchdogMonitorFLASH();
        }

        for (i = 0; i< numOfSmallSector; i++)
        {
          Fblm_WDRefresh();
          (void)Fblm_LookForWatchdog();
          FLASH_DRIVER_ERASE(CY_FLASH_SM_SBM_TOP+(CY_CODE_SES_SIZE_IN_BYTE*i), CY_FLASH_DRIVER_NON_BLOCKING);
          Sbcc_WatchdogMonitorFLASH();
        }

    }/*judge sector done*/

    return kFblOk;
}

/*----------------------------------------------------------------------------*/
/*Name : Fblm_WriteFlash     			    			              		  */
/*Role : write memory 										                  */
/*Interface :                                                                 */
/*  - IN  : ulong StartAddress,data,ulong MemorySize(length)	              */
/*  - OUT : none											                  */
/*Pre-condition : Start address must be a start address of logicalBlock  	  */
/*Constraints   : Code flash supports 8 bytes,32 bytes,and 512 bytes program  */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [initialize parameters and main loop]                                   */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
ubyte Fblm_WriteFlash(ulong StartAddress,ubyte* StoreData,ulong MemoryLength)
{
    ubyte i = 0u,j = 0u;
    ubyte numOfWrite = 0u;
    if ((NULL == StoreData) || (0U == MemoryLength))
    {
       return kFblFailed;
    }

    if (0u != MemoryLength%FBL_MEMORY_WRITE_512BYTE)
    {
       return kFblFailed;
    }
    else
    {
        numOfWrite = MemoryLength/FBL_MEMORY_WRITE_512BYTE;

        for (i=0;i<numOfWrite;i++)
        {
            (void)Fblm_WDRefresh();
            memcpy((void*)(&Fblm_FlashData[0]),(const void*)((&StoreData[0]) + (i*FBL_MEMORY_WRITE_512BYTE)),FBL_MEMORY_WRITE_512BYTE);
            /*Call Flash Driver*/
            FLASH_DRIVER_WRITE(StartAddress+(i*FBL_MEMORY_WRITE_512BYTE), (const uint32_t*)(&Fblm_FlashData[0]),\
                            CY_FLASH_PROGRAMROW_DATA_SIZE_4096BIT,CY_FLASH_DRIVER_NON_BLOCKING);
            Sbcc_WatchdogMonitorFLASH();
            (void)Fblm_WDRefresh();
            for (j=0;j<FBL_MEMORY_WRITE_NOP;j++)
            {
                ;/*nop*/
            }
        }
       return kFblOk;
    }
}


static void Fblm_Diag_0212_DownloadCheck_SWP1_Write_Nvm_Handle(void)
{
   NvM_RequestResultType Int_NvMultiBlockStatus;

   NvM_WriteBlock(NvMConf_NvMBlockDescriptor_WDFC_ID_SWP1, &WDFS_RamSWP1);
   do  /*Ensure that the NVM write is completed before proceeding with subsequent operations.*/
   {
      MemAcc_MainFunction();
      Fee_30_FlexNor_MainFunction();   
      NvM_MainFunction();
      NvM_GetErrorStatus(NvMConf_NvMBlockDescriptor_WDFC_ID_SWP1,&Int_NvMultiBlockStatus); 
      Sbcc_WatchdogMonitor();
   }while(Int_NvMultiBlockStatus == NVM_REQ_PENDING);
}

static void Fblm_Diag_31_Write_RamRDIProgInfo_Nvm_Handle(void)
{
   NvM_RequestResultType Int_NvMultiBlockStatus;

   NvM_WriteBlock(NvMConf_NvMBlockDescriptor_WDFC_ID_ECUID_RDI_PROGRAMMING_INFO, &WDFS_RamRDIProgInfo);
   do  /*Ensure that the NVM write is completed before proceeding with subsequent operations.*/
   {
      MemAcc_MainFunction();
      Fee_30_FlexNor_MainFunction();   
      NvM_MainFunction();
      NvM_GetErrorStatus(NvMConf_NvMBlockDescriptor_WDFC_ID_ECUID_RDI_PROGRAMMING_INFO,&Int_NvMultiBlockStatus); 
      Sbcc_WatchdogMonitor();
   }while(Int_NvMultiBlockStatus == NVM_REQ_PENDING);
}
/******************************************************************************
* Name         :  Fblm_DownloadCheck
* Called by    :  FblDiagRoutineControl
* Preconditions:  May only be called after download of logical block
*
* Parameters   :  Index of verification data in diagnostic buffer
* Return code  :  None
* Description  :  Verify the downloaded flashware
******************************************************************************/
void Fblm_DownloadCheck(ushort verDataIndex)
{
    ulong VerificationSha = 0u;
    ulong LocalVerificationCrc = 0u;
    ulong VerStartAddress = 0u;
    ulong VerblockLength =  0u;
    uint16 i = 0;
    uint8 result = FALSE;
    boolean VBT_FormatError = FALSE;
    boolean PublickeyError = FALSE;
    boolean SoftHardwareNotMatch = FALSE;

    memcpy(Fblm_Signature, &DiagBuffer[4], sizeof(Fblm_Signature));
    if(DOWNLOAD_FLASHDRVSHA == Fblm_GetTransferType())
    {
      if(TRUE == RSAM_CheckVBTFormat(Fblm_FlashDrvShaData, Fblm_AppVerificationBlockTableLength, FBLM_FLASHDRV_STARTADDRESS , FlashDrv_BlockSize))
      {
        if(TRUE == RSAM_CheckPublicKeyIntegrity())
        {
            result = RSAM_StartSignVerify(Fblm_Signature,Fblm_FlashDrvShaData,Fblm_AppVerificationBlockTableLength,FBLM_FLASHDRIVER_VBTADDR );
        }
        else
        {
            PublickeyError = TRUE;
        }
      }
      else
      {
        VBT_FormatError = TRUE;
      }
    }
    else if((DOWNLOAD_APPSHA == Fblm_GetTransferType()) || (DOWNLOAD_FLASH == Fblm_GetTransferType()))
    {
      if(TRUE == RSAM_CheckVBTFormat(Fblm_AppShaData, Fblm_AppVerificationBlockTableLength, FBLM_APP_STARTADDRESS , FBLM_APP_LENGTH))
      {
        if(TRUE == RSAM_CheckPublicKeyIntegrity())
        {
          result = RSAM_StartSignVerify(Fblm_Signature,Fblm_AppShaData,Fblm_AppVerificationBlockTableLength, FBLM_APP_VBTADDR); 
          Fblm_UpgradeAPPBlockFlag = TRUE;
        }
        else
        {
          PublickeyError = TRUE;
        }
      }  
      else
      {
        VBT_FormatError = TRUE;
      } 
    }
    else if((DOWNLOAD_SWP1SHA == Fblm_GetTransferType()) || (DOWNLOAD_SWP1 == Fblm_GetTransferType()))
    {
      if(TRUE == RSAM_CheckVBTFormat(Fblm_Swp1ShaData, Fblm_AppVerificationBlockTableLength, FBLM_SWP1_STARTADDRESS , FBLM_SWP1_SIZE))
      {
        if(TRUE == RSAM_CheckPublicKeyIntegrity())
        {
          result = RSAM_StartSignVerify(Fblm_Signature,Fblm_Swp1ShaData,Fblm_AppVerificationBlockTableLength, FBLM_SWP1_VBTADDR);
          Fblm_UpgradeSWP1BlockFlag = TRUE;
        }
        else
        {
          PublickeyError = TRUE;
        }
      }
      else
      {
        VBT_FormatError = TRUE;
      }
    }

  if(TRUE == result)
  {
    if((DOWNLOAD_APPSHA == Fblm_GetTransferType()) || (DOWNLOAD_FLASH == Fblm_GetTransferType()))
    {
      if(FblApplInvalid == Fblm_IsSoftwareAndHardwareVersionMatch())
      {
        SoftHardwareNotMatch = TRUE;
        result  = FALSE;
      }
    }
  }

    if(TRUE == result)
    {
      DiagBuffer[kDiagFmtSubRoutineIdPar] = 0x10;
      DiagBuffer[kDiagFmtSubRoutineIdPar + 1] = FBLM_VERIFICAITON_PASSED;

      if((DOWNLOAD_FLASHDRVSHA == Fblm_GetTransferType()) || (DOWNLOAD_RAM == Fblm_GetTransferType())) /*Init FlashDrive Only after Signature OK*/
      {
        /*SHA Ok, Set flash driver initialization flag */
        SetMemDriverInitialized();
        /* GEFDCM-48 It needs to be called after flashdriver checks the memory. */
        /* FLASH_DRIVER_INIT(FALSE); */  /*  Call init routine of the Flash driver */
        DiagProcessingDone(kDiagRslRoutineControlCheckSumLength);
      }
      if((DOWNLOAD_APPSHA == Fblm_GetTransferType()) || (DOWNLOAD_FLASH == Fblm_GetTransferType()))/*When App Signature is OK */
      {
         Fblm_AppFlashSigntureSucFlag = TRUE;
         /*checksum with crc32*/
         Fblm_AppCrc32Value = Fblm_crc32(((ubyte*)FBLM_APP_STARTADDRESS), (FBLM_APP_LENGTH -4));
         Fblm_CodeflashChecksumValue = ((uint32)__ghsbegin_M4AppEndFlag[31]  + ((uint32)__ghsbegin_M4AppEndFlag[30] << 8) + \
                 (uint32)(__ghsbegin_M4AppEndFlag[29] << 16)  + (uint32)(__ghsbegin_M4AppEndFlag[28] << 24));

        Fblm_AppProgramStsUpdateFlag = TRUE;
        if(Fblm_AppCrc32Value == Fblm_CodeflashChecksumValue)
        {
          Fblm_UpdateReprogrammingCounter(Fblm_AppCodeProgramStatus); /*UPDATE*/
          /*When CRC32 and SignatureOK , and set app Flag as 0XA5A5 */
          /*Async Write App ProgramStatus Info  */
           Fblm_SetProgramStatusInfo(Fblm_AppCodeProgramStatus, Fblm_ProgramStatusVaild);
         //  Fblm_AsyncWriteNvmData(WDFC_SIZE_ECUSIZE_RDI_PROGRAMMING_INFO,\
              NvMConf_NvMBlockDescriptor_WDFC_ID_ECUID_RDI_PROGRAMMING_INFO, (ubyte *)&WDFS_RamRDIProgInfo);
        }
        else
        {
            /*When CRC32 is NOK and Signature is OK , and set app Flag as 0XBCBC */
            /*Async Write App ProgramStatus Info  */
          Fblm_SetProgramStatusInfo(Fblm_AppCodeProgramStatus, Fblm_ProgramStatusCrcInVaild);
         // Fblm_AsyncWriteNvmData(WDFC_SIZE_ECUSIZE_RDI_PROGRAMMING_INFO,\
                NvMConf_NvMBlockDescriptor_WDFC_ID_ECUID_RDI_PROGRAMMING_INFO, (ubyte *)&WDFS_RamRDIProgInfo);
        }
        /* GEFDCM-330 only write the app, you also need to write the flag. */
        Fblm_Diag_31_Write_RamRDIProgInfo_Nvm_Handle();
           DiagProcessingDone(kDiagRslRoutineControlCheckSumLength);
      }
      else if((DOWNLOAD_SWP1SHA == Fblm_GetTransferType()) || (DOWNLOAD_SWP1 == Fblm_GetTransferType()))
      {
        /*when flash SWP1 data done */
        Fblm_WDRefresh();
        (void)Sbcc_WatchdogMonitor();
        memcpy(&WDFS_RamSWP1,FBLM_Swp1Code,FBLM_SWP1_SIZE);
        /*When download SWP1 and check ok done, need to write it into NvM*/
        /*set flag and deal with 31 01 02 05 on upgrading swp1 */
        Fblm_Swp1Crc16Value = Fblm_ChecksumForSwp1();
        Fblm_Swp1ProgramStsUpdateFlag = TRUE;
        Fblm_UpdateReprogrammingCounter(Fblm_SWP1ProgramStatus);
        if(WDFS_RamSWP1.Checksum == Fblm_Swp1Crc16Value)
        {
          Fblm_SetProgramStatusInfo(Fblm_SWP1ProgramStatus, Fblm_ProgramStatusVaild);
        }
        else
        {
          Fblm_SetProgramStatusInfo(Fblm_SWP1ProgramStatus, Fblm_ProgramStatusCrcInVaild);
        }
        /* GEFDCM-329 Write nvm modification synchronously. */
        Fblm_Diag_0212_DownloadCheck_SWP1_Write_Nvm_Handle(); 
        // Fblm_AsyncWriteNvmData(FBLM_SWP1_SIZE, NvMConf_NvMBlockDescriptor_WDFC_ID_SWP1, (ubyte *)&WDFS_RamSWP1);
        if((TRUE == Fblm_AppProgramStsUpdateFlag) || (TRUE == Fblm_Swp1ProgramStsUpdateFlag)) /*Need to upadte program status*/
        {
            Fblm_Diag_31_Write_RamRDIProgInfo_Nvm_Handle();
        }
        // Fblm_AsyncWriteNvmData(FBLM_SWP1_SIZE, NvMConf_NvMBlockDescriptor_WDFC_ID_SWP1, (ubyte *)&WDFS_RamSWP1);
        DiagProcessingDone(kDiagRslRoutineControlCheckSumLength);
      }
      
        /*checkMemoryAllowed = kFblFailed;*/ /*GEFDCM-287*/
    }
    else
    {
    /*SHA check error, response POC 0x10 0x01*/
    DiagBuffer[kDiagFmtSubRoutineIdPar] = 0x10;
      if(TRUE == VBT_FormatError)
    {
          DiagBuffer[kDiagFmtSubRoutineIdPar + 1] = FBLM_INVALID_FORMAT_VBT;  
      }
      else if(TRUE == PublickeyError)
      {
      if((NVM_REQ_OK == NVMM_PublicKeyStatusDidStatus)
        ||(NVM_REQ_RESTORED_FROM_ROM == NVMM_PublicKeyStatusDidStatus))
      {
        DiagBuffer[kDiagFmtSubRoutineIdPar + 1] = FBLM_PUBLIC_KEY_FAIL;  
      }
      else
      {
        DiagBuffer[kDiagFmtSubRoutineIdPar + 1] = FBLM_STORAGE_VALIDITY_STATUS_FAIL; 
      }
      }
      else if(RSAM_RSA_APPHASH_FAIL == RSAM_GetDetailErrType())
      {
          DiagBuffer[kDiagFmtSubRoutineIdPar + 1] = FBLM_BLOCK_HASH_INVALID;  
      }
    else if(SoftHardwareNotMatch == TRUE)
    {
      DiagBuffer[kDiagFmtSubRoutineIdPar + 1] = FBLM_FBLM_USER_DEFINED;  
    }
    else 
      {
          DiagBuffer[kDiagFmtSubRoutineIdPar + 1] = FBLM_SIGNATURE_VERIFICAITON_FAIL; 
      }
    DiagProcessingDone(kDiagRslRoutineControlCheckSumLength);
    }

#if 0
 /*Enable CRC32 Function*/
    ulong VerificationCrc = 0u;
    ulong LocalVerificationCrc = 0u;
    ulong VerStartAddress = 0u;
    ulong VerblockLength =  0u;

    VerificationCrc = DiagBuffer[6]*(ulong)0x01000000 + DiagBuffer[7]*(ulong)0x00010000 +\
            DiagBuffer[8]*(ulong)0x00000100 + DiagBuffer[9]*(ulong)0x00000001;

    if (DOWNLOAD_RAM == Fblm_GetTransferType())
    {
        VerStartAddress = (ulong)(&(flashCode[0]));
        VerblockLength = FblLogicalBlockTable.logicalBlock[FlashDrv_BlockIndex].blockLength;
    }
    else/*Download code flash*/
    {
        VerStartAddress = FblLogicalBlockTable.logicalBlock[APP_BlockIndex].blockStartAddress;
        VerblockLength = FblLogicalBlockTable.logicalBlock[APP_BlockIndex].blockLength;
    }

    LocalVerificationCrc = Fblm_crc32(((ubyte*)VerStartAddress), VerblockLength);

    if (DOWNLOAD_RAM != Fblm_GetTransferType())
    {
      if(VerificationCrc != LocalVerificationCrc)
      {
          /*   DiagBuffer[kDiagFmtSubRoutineIdPar] = kDiagCheckVerificationFailed;*/
         DiagNRCGeneralProgrammingFailure();
         return;
      }
      else
      {
          Fblm_RunningCheckVerificationStatus = TRUE;
          Fblm_ReadWriteNvmBlockData[0] = 0xFF;/*ProgrammingStatus*/
          Fblm_ReadWriteNvmBlockData[1] = 0x0;/*ProgrammingStatus*/
          Fblm_CurrentNvMBlockId = NvMConf_NvMBlockDescriptor_ProgrammingStatusDid2010;
          Fblm_DiagRespDataLen = kDiagRslRoutineControlCheckRoutine;
          Fblm_IsReadWriteNvmBlock = TRUE;
          DiagExRCRResponsePending(kForceSendResponsePending);
          BootCommand = ((uint32) FBLM_Command_ToAPP);
            /* Write return value to DiagBuffer */
           /* DiagBuffer[kDiagFmtSubRoutineIdPar] = kDiagCheckVerificationOk;*/

            /*DiagProcessingDone(kDiagRslRoutineControlCheckRoutine);*/  /*need to write NVM*/
      }
    }
    else
    {
      if(VerificationCrc != LocalVerificationCrc)
      {
          /*   DiagBuffer[kDiagFmtSubRoutineIdPar] = kDiagCheckVerificationFailed;*/
         DiagNRCGeneralProgrammingFailure();
         return;
      }
      else
      {
        FLASH_DRIVER_INIT(FALSE);  /*  Call init routine of the Flash driver */
        DiagBuffer[kDiagFmtSubRoutineIdPar] = kDiagCheckVerificationOk;

        DiagProcessingDone(kDiagRslRoutineControlCheckRoutine);
      }

    }

    if (DOWNLOAD_RAM == Fblm_GetTransferType())
    {
          /* Set flash driver initialization flag */
          SetMemDriverInitialized();
    }
    else/*Download code flash*/
    {
        //to do
        //Set valid block OK
    }
#endif



}


/******************************************************************************
* Name         :  Fblm_CheckProgConditions
* Called by    :  Diagnostic module
* Preconditions:  None
* Parameters   :  None
* Return code  :  kFblOk/kFblFailed
* Description  :  This function is called after receiving the service request
*                 SessionControl ProgrammingSession to check the programming
*                 conditions like reprogramming counter, ambient temperature,
*                 programming voltage, etc.
*                 If all conditions are correct, the function returns kFblOk,
*                 otherwise kFblFailed.
******************************************************************************/
ubyte Fblm_CheckProgConditions(void)
{
    /*to do*/
   return kFblOk;
}

/******************************************************************************
* Name         :  Fblm_CheckProgDependencies
* Called by    :  FblDiagRoutineControl
* Preconditions:  None
* Parameters   :  None
* Return code  :  Status of programming dependencies (OEM specific)
* Description  :  Check if programming dependencies are given
******************************************************************************/
ubyte Fblm_CheckProgDependencies(void)
{
  uint8 Ret = 0;
  /*if crc is nok and Signature is ok */
  if((Fblm_ProgramStatusCrcInVaild == (Fblm_GetProgramStatusInfo() & 0xFFFF)) || \
     (Fblm_ProgramStatusCrcInVaild == ((Fblm_GetProgramStatusInfo() & 0xFFFF0000) >> 16)))
  {
    Ret = 0x02;
  }
  else if((Fblm_AllProgramStatusVaild == Fblm_GetProgramStatusInfo()))
    /*All Checksum OK*/
  {
    if( FblApplValid  ==  Fblm_IsApplicationValid())
    {
      Ret = 0;
    }
    else
    {
      Ret = 6;
    }
  }
  else if((Fblm_ProgramStatusInvaild == (Fblm_GetProgramStatusInfo() & 0xFFFF)))
  {
    /*When APP Codeflash may be erased or  Signature is Nok*/
    Ret = 0x05;  /*error status*/
  }
  else if(Fblm_ProgramStatusInvaild == ((Fblm_GetProgramStatusInfo() & 0xFFFF0000) >> 16)) /*When SWP1 Checksum No OK*/
  {
      Ret = 0x11;  /*error status*/
  }
  return Ret;
}

/*----------------------------------------------------------------------------*/
/*Name : Fblm_CheckValidAddressRange  			    			              */
/*Role : check if address belong to legal range				                  */
/*Interface :                                                                 */
/*  - IN  : ulong StartAddress,ulong MemorySize	                              */
/*  - OUT : none											                  */
/*Pre-condition : none			                                              */
/*Constraints   : none             			                                  */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [initialize parameters and main loop]                                   */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
ubyte Fblm_CheckValidAddressRange(ulong StartAddress,ulong MemorySize)
{
    ubyte result = kFblFailed;
    if ((StartAddress == FblLogicalBlockTable.logicalBlock[FlashDrv_BlockIndex].blockStartAddress)\
            && (MemorySize <= FblLogicalBlockTable.logicalBlock[FlashDrv_BlockIndex].blockLength))
    {
        ActiveLogicBlock = FlashDrv_BlockIndex;
        result = kFblOk;
    }
    else if ((StartAddress == FblLogicalBlockTable.logicalBlock[FlashDrvSHA_BlockIndex].blockStartAddress)\
            && (MemorySize <= FblLogicalBlockTable.logicalBlock[FlashDrvSHA_BlockIndex].blockLength))
    {
        ActiveLogicBlock = FlashDrvSHA_BlockIndex;
        result = kFblOk;
    }
    else if ((StartAddress == FblLogicalBlockTable.logicalBlock[APP_BlockIndex].blockStartAddress)\
            && (MemorySize <= FblLogicalBlockTable.logicalBlock[APP_BlockIndex].blockLength))
    {
        ActiveLogicBlock = APP_BlockIndex;
        result = kFblOk;
    }
    else if ((StartAddress == FblLogicalBlockTable.logicalBlock[APPSHA_BlockIndex].blockStartAddress)\
            && (MemorySize <= FblLogicalBlockTable.logicalBlock[APPSHA_BlockIndex].blockLength))
    {
        ActiveLogicBlock = APPSHA_BlockIndex;
        result = kFblOk;
    }
    else if ((StartAddress == FblLogicalBlockTable.logicalBlock[SWP1_BlockIndex].blockStartAddress)\
            && (MemorySize <= FblLogicalBlockTable.logicalBlock[SWP1_BlockIndex].blockLength))
    {
        ActiveLogicBlock = SWP1_BlockIndex;
        result = kFblOk;
    }
    else if ((StartAddress == FblLogicalBlockTable.logicalBlock[SWP1SHA_BlockIndex].blockStartAddress)\
            && (MemorySize <= FblLogicalBlockTable.logicalBlock[SWP1SHA_BlockIndex].blockLength))
    {
        ActiveLogicBlock = SWP1SHA_BlockIndex;
        result = kFblOk;
    }
    else
    {
        ActiveLogicBlock = Invalid_BlockIndex;
        result = kFblFailed;/*Invalid address*/
    }

    return result;
}


/******************************************************************************
* Name         :  FblGetInteger - 14229 specific
* Called by    :  FblRequestDownload
* Preconditions:  None
* Parameters   :  - Number of bytes to extract from array
*                 - Pointer to source data array
* Return code  :  Extracted integer number
* Description  :  This function extracts 'count' bytes from 'buffer' and
*                 converts it into an integer
******************************************************************************/
FBL_MEMSIZE_TYPE Fblm_GetInteger(ubyte count, const ubyte* buffer)
{
   FBL_MEMSIZE_TYPE num = 0;
   ubyte index = 0;

   while (count > 0)
   {
      num <<= 8;
      num |= (FBL_MEMSIZE_TYPE)buffer[index];
      index++;
      count--;
   }

   return num;
}

/***********************************************************************************************************************
 *  FblCanMsgTransmitted
 **********************************************************************************************************************/
/*! \brief       This function returns kCanTxOk, if the message was transmitted.
 *  \pre         CAN interface must be initialized before call
 *  \return      kFblCanTxInProgress - ongoing transmission\n
 *               kFblCanTxOk         - message transmitted\n
 *               kFblCanTxFailed     - no TX in progress or finished
 **********************************************************************************************************************/
ubyte Fblm_CanMsgTransmitted(void)
{
  ubyte result = kCanTxFailed;

  if (CY_CANFD_TX_BUFFER_PENDING == Cy_CANFD_GetTxBufferStatus(CY_CANFD5_TYPE,0))
  {
      /* Message transmission currently in progress */
      result = kFblCanTxInProgress;
  }
  else
  {
      result = kCanTxOk;
  }

  return result;
}

/******************************************************************************
* Name         :  Fblm_SetUpdateType
* Called by    :  User
* Preconditions:  None
* Parameters   :  None
* Description  :  Setting Update mode by user
******************************************************************************/
void Fblm_SetUpdateMode(FBLM_UpdateMode_t mode)
{
    Fblm_UpdateMode = mode;
}

/******************************************************************************
* Name         :  Fblm_SetUpdateType
* Called by    :  User
* Preconditions:  By macro or Data flash setting($2E or Reprogram flag) or UDS first received
* Parameters   :  None
* Description  :  Setting Update mode by user
******************************************************************************/
FBLM_UpdateMode_t Fblm_GetUpdateMode(void)
{
#if defined (FBL_IMC_BOOT_USED)
    Fblm_UpdateMode = UPDATE_MODE_OTA;
#elif defined (FBL_CAN_BOOT_USED)
    Fblm_UpdateMode = UPDATE_MODE_CAN;
#else
    /*Fblm_UpdateMode = Fblm_UpdateMode;*/
#endif
    return Fblm_UpdateMode;
}


/*----------------------------------------------------------------------------*/
/*Name : Fblm_crc32     			                                          */
/*Role : Calculate CRC							 						      */
/*Interface :                                                                 */
/*  - IN  : none	                                                          */
/*  - OUT : none  							                                  */
/*Pre-condition : none			                                              */
/*Constraints   : none             			                                  */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [initialize parameters and main loop]                                   */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
ulong Fblm_crc32(const ubyte *buffer, ulong datalen)
{
    ulong i;
    ulong crc32val = 0;
    crc32val ^= 0xFFFFFFFF;
    (void)Fblm_WDRefresh(); 
    (void)Sbcc_WatchdogMonitor();
    for (i = 0;  i < datalen;  i++)
    {
      crc32val = crc32_tab[(crc32val ^ buffer[i]) & 0xFF] ^ ((crc32val >> 8) & 0x00FFFFFF);
      Sbcc_WatchdogMonitor();
    }

    return (crc32val ^ 0xFFFFFFFF);
}

#if 0
void VERS_GetBootDataConfigFixedByte(uint8 *buf, uint8 len)
{
  memcpy(buf, WDFS_RamBootDataConfig.FixedByte, len);
}
#endif

/******************************************************************************/
/* Name : UDS_Uint32_BIT_Set                                                  */
/* Role : Geely SecurityAcess Service Key generate method                     */
/* Interface :     none                                                       */
/* Pre-condition :   none                                                     */
/* Constraints :  This function should not be change                          */
/******************************************************************************/
uint32 Fblm_Uint32_BIT_Set(uint32 data,uint8 index,bool b)
{

  data &= ~(1<<index);

  data |= b<<index;

  return data;
}


/******************************************************************************/
/* Name : Fblm_ChecksumForSwp1                                                */
/* Role : Geely SecurityAcess Service Key generate method                     */
/* Interface :     none                                                       */
/* Pre-condition :   none                                                     */
/* Constraints :  This function should not be change                          */
/******************************************************************************/
uint16 Fblm_ChecksumForSwp1(void)
{
  uint16 indexAddress = 0;
  uint16 CheckSum = 0;
  for (indexAddress = 0 ; indexAddress < (sizeof(WDFS_RamSWP1) - 4); indexAddress++) /*SYST_FLASH_END_ADDRESS*/
  {
    CheckSum += WDFS_RamSWP1.DataFile.Buffer[indexAddress];
  }
  CheckSum += WDFS_RamSWP1.MagicNum;
  return CheckSum;
}


/*______ L O C A L - F U N C T I O N S _______________________________________*/


/*----------------------------------------------------------------------------*/
/*Name : Fblm_IsM0ApplicationValid    			                              */
/*Role : judge application software is valid or not                           */
/*Interface :                                                                 */
/*  - IN  : none	                                                          */
/*  - OUT : FblApplValid or FblApplInvalid					                  */
/*Pre-condition : none			                                              */
/*Constraints   : none             			                                  */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [initialize parameters and main loop]                                   */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#if 0
static ubyte Fblm_IsM0ApplicationValid(void)
{
    if ((M0App_End[0] == 'M') && (M0App_End[1] == '0') &&\
                 (M0App_End[2] == 'E') && (M0App_End[3] == 'n') && (M0App_End[4] == 'd'))
    {
        return FblApplValid;
    }
    else
    {
        return FblApplInvalid;
    }
}
#endif

static ubyte Fblm_IsSoftwareAndHardwareVersionMatch(void)
{
  ubyte Ret = FblApplInvalid;

  if((__ghsbegin_M4AppEndFlag[13] == 'W') && (__ghsbegin_M4AppEndFlag[14] == 'D'))
  {
    Ret = FblApplValid;
  }

  return Ret;
}

/*----------------------------------------------------------------------------*/
/*Name : Fblm_IsM4ApplicationValid    			                              */
/*Role : judge application software is valid or not                           */
/*Interface :                                                                 */
/*  - IN  : none	                                                          */
/*  - OUT : FblApplValid or FblApplInvalid					                  */
/*Pre-condition : none			                                              */
/*Constraints   : none             			                                  */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [initialize parameters and main loop]                                   */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
static ubyte Fblm_IsM4ApplicationValid(void)
{
    /* GEFDCM-268  Add compatibility check*/
    if ((__ghsbegin_M4AppEndFlag[5] == 'E') && (__ghsbegin_M4AppEndFlag[6] == 'F') && (__ghsbegin_M4AppEndFlag[25] == 'E') && (__ghsbegin_M4AppEndFlag[26] == 'n') && (__ghsbegin_M4AppEndFlag[27] == 'd'))
    {
        return FblApplValid;
    }
    else
    {
        return FblApplInvalid;
    }
}

/*----------------------------------------------------------------------------*/
/*Name : Fblm_IsM4ApplicationValid    			                              */
/*Role : judge application software is valid or not                           */
/*Interface :                                                                 */
/*  - IN  : none	                                                          */
/*  - OUT : FblApplValid or FblApplInvalid					                  */
/*Pre-condition : none			                                              */
/*Constraints   : none             			                                  */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [initialize parameters and main loop]                                   */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
static ubyte Fblm_IsBootCompatibleWithApp(void)
{
  ubyte Ret = FblApplInvalid;
  if((M0BOOT_End[0] == __ghsbegin_M4AppEndFlag[16]) && (M0BOOT_End[1] == __ghsbegin_M4AppEndFlag[17]))
  {
    Ret = FblApplValid;
  }
  else
  {
    Ret = FblApplInvalid;
  }
  return Ret;
}




/*----------------------------------------------------------------------------*/
/*Name : Fblm_Binary2BCD                                                      */
/*Role : transform hex to BCD form.                                           */
/*Interface : -                                                               */
/*Pre-condition : -                                                           */
/*Constraints : -                                                             */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    pseudo code (PDL)                                                       */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
static uint8 Fblm_Binary2BCD(uint8 inputVal)
{
  uint16 result;

  result = (uint16)((uint16)inputVal / 100U);
  result = result << 4U;
  result |= (uint16)(((uint16)inputVal % 100U) / 10U);
  result = result << 4U;
  result |= (uint16)(((uint16)inputVal % 100U) % 10U);

  return (uint8)result;
}

/*----------------------------------------------------------------------------*/
/*Name : Fblm_Complete_ECU_Part_Serial_Number_s_PBL_Geely_Did_ED20_Func    			                                    
/*Role :                               
/*Interface :                                                                   
/*  - IN  : none	                                                              
/*  - OUT : none					                            
/*Pre-condition : none			                                                    
/*Constraints   : none             			                                        
/*Behavior :                                                                    
/*  DO                                                                          
/*                                         
/*  OD                                                                          
/*----------------------------------------------------------------------------*/
static void Fblm_Complete_ECU_Part_Serial_Number_s_PBL_Geely_Did_ED20_Func(uint8 *pData)
{
    uint16 index = 0;
    uint16 length = 0;

    if (TRUE == Fblm_ActivateSblFlag)
    {
        pData[index] = 0xF1u;
        pData[++index] = 0x24u;
        index++;
        for (length = 0U; length < sizeof(Fblm_F124_Ver); index++, length++)
        {
            pData[index] = Fblm_F124_Ver[length];
        }

        /*F18C Start*/
        pData[index] = 0xF1u;
        pData[++index] = 0x8Cu;
        index++;
        if(EOL_CHECKEOLDONE == 0xFF)
		{
			/*Read Data from NVM*/
			for (length = 0U; length < 4U ; index++, length++)
            {
                pData[index] =  WDFS_RamIDOptionSecurity.IdOptionData.ECUSerialNumber[length];
            }
		}
		else
		{
			/*Read Data from CodeFlash*/
			memcpy(&pData[index],Fblm_CodeFlashSector_RAMAdrTbl[Fblm_F18CID].Address_CodeFlash,Fblm_CodeFlashSector_RAMAdrTbl[Fblm_F18CID].length);
			index += Fblm_CodeFlashSector_RAMAdrTbl[Fblm_F18CID].length;/*Offset the index*/
		}
        /*F18C End*/

        pData[index] = 0xF1u;
        pData[++index] = 0xA2u;
        index++;
        for (length = 0U; length < sizeof(Fblm_F1A2_PN); index++, length++)
        {
            pData[index] = Fblm_F1A2_PN[length];
        }

		/*F1AA Start*/
        pData[index] = 0xF1u;
        pData[++index] = 0xAAu;
        index++;
        if(EOL_CHECKEOLDONE == 0xFF)
		{
			/*Read Data from NVM*/
			for (length = 0U; length < Diag_ECUCoreAsmTotal_Len; index++, length++)
            {
                pData[index] = WDFS_RamPart_Number_Geely.PN_F1AA[length];
            }
		}
		else
		{
			/*Read Data from CodeFlash*/
			memcpy(&pData[index],Fblm_CodeFlashSector_RAMAdrTbl[Fblm_F1AAID].Address_CodeFlash,Fblm_CodeFlashSector_RAMAdrTbl[Fblm_F1AAID].length);
			index += Fblm_CodeFlashSector_RAMAdrTbl[Fblm_F1AAID].length;/*Offset the index*/
		}
        /*F1AA End*/

        /*F1AB Start*/
        pData[index] = 0xF1u;
        pData[++index] = 0xABu;
        index++;
        if(EOL_CHECKEOLDONE == 0xFF)
		{
			/*Read Data from NVM*/
			for (length = 0U; length < Diag_ECUDeliAsmTotal_Len; index++, length++)
            {
                pData[index] = WDFS_RamPart_Number_Geely.PN_F1AB[length];
            }
		}
		else
		{
			/*Read Data from CodeFlash*/
			memcpy(&pData[index],Fblm_CodeFlashSector_RAMAdrTbl[Fblm_F1ABID].Address_CodeFlash,Fblm_CodeFlashSector_RAMAdrTbl[Fblm_F1ABID].length);
			index += Fblm_CodeFlashSector_RAMAdrTbl[Fblm_F1ABID].length;/*Offset the index*/
		}
        /*F1AB End*/
    }
    else
    {
        /*F18C Start*/
        pData[index] = 0xF1u;
        pData[++index] = 0x8Cu;
        index++;
        if(EOL_CHECKEOLDONE == 0xFF)
		{
			/*Read Data from NVM*/
			for (length = 0U; length < 4U ; index++, length++)
            {
                pData[index] = WDFS_RamIDOptionSecurity.IdOptionData.ECUSerialNumber[length];
            }
		}
		else
		{
			/*Read Data from CodeFlash*/
			memcpy(&pData[index],Fblm_CodeFlashSector_RAMAdrTbl[Fblm_F18CID].Address_CodeFlash,Fblm_CodeFlashSector_RAMAdrTbl[Fblm_F18CID].length);
			index += Fblm_CodeFlashSector_RAMAdrTbl[Fblm_F18CID].length;/*Offset the index*/
		}
        /*F18C End*/

        /*F1A1 Start*/
        pData[index] = 0xF1u;
        pData[++index] = 0xA1u;
        index++;
        if(EOL_CHECKEOLDONE == 0xFF)
		{
			/*Read Data from NVM*/
			for (length = 0U; length < Diag_PBLDiagDatabaseTotal_Len; index++, length++)
            {
                pData[index] = WDFS_RamPart_Number_Geely.PN_F1A1[length];
            }
		}
		else
		{
			/*Read Data from CodeFlash*/
			memcpy(&pData[index],Fblm_CodeFlashSector_RAMAdrTbl[Fblm_F1A1ID].Address_CodeFlash,Fblm_CodeFlashSector_RAMAdrTbl[Fblm_F1A1ID].length);
			index += Fblm_CodeFlashSector_RAMAdrTbl[Fblm_F1A1ID].length;/*Offset the index*/
		}
		/*F1A1 End*/

        /*F1A5 Start*/
        pData[index] = 0xF1u;
        pData[++index] = 0xA5u;
        index++;
        if(EOL_CHECKEOLDONE == 0xFF)
		{
			/*Read Data from NVM*/
			for (length = 0U; length < Diag_PBLSoftDiagDatabaseTotal_Len; index++, length++)
            {
                pData[index] = WDFS_RamPart_Number_Geely.PN_F1A5[length];
            }
		}
		else
		{
			/*Read Data from CodeFlash*/
			memcpy(&pData[index],Fblm_CodeFlashSector_RAMAdrTbl[Fblm_F1A5ID].Address_CodeFlash,Fblm_CodeFlashSector_RAMAdrTbl[Fblm_F1A5ID].length);
			index += Fblm_CodeFlashSector_RAMAdrTbl[Fblm_F1A5ID].length;/*Offset the index*/
		}
        /*F1A5 End*/

        /*F1AA Start*/
        pData[index] = 0xF1u;
        pData[++index] = 0xAAu;
        index++;
        if(EOL_CHECKEOLDONE == 0xFF)
		{
			/*Read Data from NVM*/
			for (length = 0U; length < Diag_ECUCoreAsmTotal_Len; index++, length++)
            {
                pData[index] = WDFS_RamPart_Number_Geely.PN_F1AA[length];
            }
		}
		else
		{
			/*Read Data from CodeFlash*/
			memcpy(&pData[index],Fblm_CodeFlashSector_RAMAdrTbl[Fblm_F1AAID].Address_CodeFlash,Fblm_CodeFlashSector_RAMAdrTbl[Fblm_F1AAID].length);
			index += Fblm_CodeFlashSector_RAMAdrTbl[Fblm_F1AAID].length;/*Offset the index*/
		}
        /*F1AA End*/

        /*F1AB Start*/
        pData[index] = 0xF1u;
        pData[++index] = 0xABu;
        index++;
        if(EOL_CHECKEOLDONE == 0xFF)
		{
			/*Read Data from NVM*/
			for (length = 0U; length < Diag_ECUDeliAsmTotal_Len; index++, length++)
            {
                pData[index] = WDFS_RamPart_Number_Geely.PN_F1AB[length];
            }
		}
		else
		{
			/*Read Data from CodeFlash*/
			memcpy(&pData[index],Fblm_CodeFlashSector_RAMAdrTbl[Fblm_F1ABID].Address_CodeFlash,Fblm_CodeFlashSector_RAMAdrTbl[Fblm_F1ABID].length);
			index += Fblm_CodeFlashSector_RAMAdrTbl[Fblm_F1ABID].length;/*Offset the index*/
		}
        /*F1AB End*/
    }
}

/*----------------------------------------------------------------------------*/
/*Name : Fblm_Complete_ECU_Part_Serial_Number_s_Did_EDA0_Func    			                                    
/*Role :                               
/*Interface :                                                                   
/*  - IN  : none	                                                              
/*  - OUT : none					                            
/*Pre-condition : none			                                                    
/*Constraints   : none             			                                        
/*Behavior :                                                                    
/*  DO                                                                          
/*                                         
/*  OD                                                                          
/*----------------------------------------------------------------------------*/
static void Fblm_Complete_ECU_Part_Serial_Number_s_Did_EDA0_Func(uint8 *pData)
{
    uint16 index = 0;
    uint16 length = 0;

    if (TRUE == Fblm_ActivateSblFlag)
    {
        pData[index] = 0xF1u;
        pData[++index] = 0x22u;
        index++;
        memset(&pData[index], 0, 7u);
        index += 7u;

        pData[index] = 0xF1u;
        pData[++index] = 0x24u;
        index++;
        for (length = 0U; length < sizeof(Fblm_F124_Ver); index++, length++)
        {
            pData[index] = Fblm_F124_Ver[length];
        }

        pData[index] = 0xF1u;
        pData[++index] = 0x2Au;
        index++;
        memset(&pData[index], 0, 7u);
        index += 7u;

        pData[index] = 0xF1u;
        pData[++index] = 0x2Bu;
        index++;
        memset(&pData[index], 0, 7u);
        index += 7u;

        /*F18C Start*/
        pData[index] = 0xF1u;
        pData[++index] = 0x8Cu;
        index++;
        if(EOL_CHECKEOLDONE == 0xFF)
		{
			/*Read Data from NVM*/
			for (length = 0U; length < 4U ; index++, length++)
            {
                pData[index] = WDFS_RamIDOptionSecurity.IdOptionData.ECUSerialNumber[length];
            }
		}
		else
		{
			/*Read Data from CodeFlash*/
			memcpy(&pData[index],Fblm_CodeFlashSector_RAMAdrTbl[Fblm_F18CID].Address_CodeFlash,Fblm_CodeFlashSector_RAMAdrTbl[Fblm_F18CID].length);
			index += Fblm_CodeFlashSector_RAMAdrTbl[Fblm_F18CID].length;/*Offset the index*/
		}
        /*F18C End*/
    }
    else
    {
        pData[index] = 0xF1u;
        pData[++index] = 0x21u;
        index++;
        memset(&pData[index], 0, 7u);
        index += 7u;

        pData[index] = 0xF1u;
        pData[++index] = 0x25u;
        index++;
        memset(&pData[index], 0, 7u);
        index += 7u;

        pData[index] = 0xF1u;
        pData[++index] = 0x2Au;
        index++;
        memset(&pData[index], 0, 7u);
        index += 7u;

        pData[index] = 0xF1u;
        pData[++index] = 0x2Bu;
        index++;
        memset(&pData[index], 0, 7u);
        index += 7u;

        /*F18C Start*/
        pData[index] = 0xF1u;
        pData[++index] = 0x8Cu;
        index++;
        if(EOL_CHECKEOLDONE == 0xFF)
		{
			/*Read Data from NVM*/
			for (length = 0U; length < 4U ; index++, length++)
            {
                pData[index] = WDFS_RamIDOptionSecurity.IdOptionData.ECUSerialNumber[length];
            }
		}
		else
		{
			/*Read Data from CodeFlash*/
			memcpy(&pData[index],Fblm_CodeFlashSector_RAMAdrTbl[Fblm_F18CID].Address_CodeFlash,Fblm_CodeFlashSector_RAMAdrTbl[Fblm_F18CID].length);
			index += Fblm_CodeFlashSector_RAMAdrTbl[Fblm_F18CID].length;/*Offset the index*/
		}
        /*F18C End*/

    }
}

/*----------------------------------------------------------------------------*/
/*Name : Fblm_Complete_ECU_Part_Serial_Number_s_Did_EDA0_Func
/*Role :
/*Interface :
/*  - IN  : none
/*  - OUT : none
/*Pre-condition : none
/*Constraints   : none
/*Behavior :
/*  DO
/*
/*  OD
/*----------------------------------------------------------------------------*/
uint8 Fblm_ProgrammingDependenciesChecksumOK(void)
{
  uint8 Ret = FALSE;
  uint8 *Address = NULL;
  uint16 CheckSum = 0u;
  for (Address = ((uint8*)FBLM_APP_STARTADDRESS) ; Address < ((uint8*)(FBLM_APP_END - 1u)); Address ++) /*SYST_FLASH_END_ADDRESS*/
  {
    CheckSum += *(Address);
  }
  if((*((uint16*)(FBLM_APP_END - 1u))) == CheckSum)
  {
    Ret = TRUE;
  }
  return Ret;
}


/*----------------------------------------------------------------------------*/
/*Name : Fblm_SetProgramStatusInfo
/*Role :
/*Interface :
/*  - IN  : none
/*  - OUT : none
/*Pre-condition : none
/*Constraints   : none
/*Behavior :
/*  DO
/*
/*  OD
/*----------------------------------------------------------------------------*/
void Fblm_UpdateReprogrammingCounter(Fblm_ProgramStatusType_t ProgramStaus)
{
  if(FALSE == Fblm_UpdateReprogrammingCounterFlag)
  {
    if(Fblm_AppCodeProgramStatus == ProgramStaus)
    {
      if(Fblm_ProgramStatusCrcInVaild == Fblm_GetAppCodeProgramStatusInfo() || \
              Fblm_ProgramStatusInvaild ==  Fblm_GetAppCodeProgramStatusInfo())
      {
        WDFS_RamRDIProgInfo.ReprogrammingCounter++;
        Fblm_UpdateReprogrammingCounterFlag = TRUE;
      }
    }
    if(Fblm_SWP1ProgramStatus == ProgramStaus)
    {
      if(Fblm_ProgramStatusCrcInVaild == Fblm_GetSwp1ProgramStatusInfo() || \
              Fblm_ProgramStatusInvaild ==  Fblm_GetSwp1ProgramStatusInfo())
      {
        WDFS_RamRDIProgInfo.ReprogrammingCounter++;
        Fblm_UpdateReprogrammingCounterFlag = TRUE;
      }
    }
  }


}

/*----------------------------------------------------------------------------*/
/*Name : Fblm_SetProgramStatusInfo
/*Role :
/*Interface :
/*  - IN  : none
/*  - OUT : none
/*Pre-condition : none
/*Constraints   : none
/*Behavior :
/*  DO
/*
/*  OD
/*----------------------------------------------------------------------------*/
void Fblm_SetProgramStatusInfo(Fblm_ProgramStatusType_t SetType, uint16 Value)
{
  if(Fblm_AppCodeProgramStatus == SetType)
  {
    WDFS_RamRDIProgInfo.ProgrammingStatus &= 0xFFFF0000;
    WDFS_RamRDIProgInfo.ProgrammingStatus |= Value;
  }
  else if(Fblm_SWP1ProgramStatus == SetType)
  {
    WDFS_RamRDIProgInfo.ProgrammingStatus &= 0x0000FFFF;
    WDFS_RamRDIProgInfo.ProgrammingStatus |= (Value << 16);
  }
  else
  {
     /*Parm error*/
  }
}

/*----------------------------------------------------------------------------*/
/*Name : Fblm_GetProgramStatusInfo
/*Role :
/*Interface :
/*  - IN  : none
/*  - OUT : none
/*Pre-condition : none
/*Constraints   : none
/*Behavior :
/*  DO
/*
/*  OD
/*----------------------------------------------------------------------------*/
uint32 Fblm_GetProgramStatusInfo(void)
{
    /*low 16bit :app , high 16 bit :swp1*/
  return WDFS_RamRDIProgInfo.ProgrammingStatus;
}

/*----------------------------------------------------------------------------*/
/*Name : Fblm_GetProgramStatusInfo
/*Role :
/*Interface :
/*  - IN  : none
/*  - OUT : none
/*Pre-condition : none
/*Constraints   : none
/*Behavior :
/*  DO
/*
/*  OD
/*----------------------------------------------------------------------------*/
uint16 Fblm_GetAppCodeProgramStatusInfo(void)
{
  return (WDFS_RamRDIProgInfo.ProgrammingStatus & 0xFFFF);
}

/*----------------------------------------------------------------------------*/
/*Name : Fblm_GetProgramStatusInfo
/*Role :
/*Interface :
/*  - IN  : none
/*  - OUT : none
/*Pre-condition : none
/*Constraints   : none
/*Behavior :
/*  DO
/*
/*  OD
/*----------------------------------------------------------------------------*/
uint16 Fblm_GetSwp1ProgramStatusInfo(void)
{
  return ((WDFS_RamRDIProgInfo.ProgrammingStatus >> 16) & 0xFFFF);
}

/*----------------------------------------------------------------------------*/
/*Name : Fblm_NvmImmediateWriteBlock
/*Role :
/*Interface :
/*  - IN  : none
/*  - OUT : none
/*Pre-condition : none
/*Constraints   : none
/*Behavior :
/*  DO
/*
/*  OD
/*----------------------------------------------------------------------------*/
static void Fblm_NvmImmediateWriteBlock(uint16 NvmBlockId,uint8 *NvMSrcPtr)
{
  uint8 NVM_CurrentErrorStatus = 0;

  NvM_WriteBlock(NvmBlockId, NvMSrcPtr);
  do  
  {
    MemAcc_MainFunction();
    Fee_30_FlexNor_MainFunction();
    NvM_MainFunction();
    NvM_GetErrorStatus(NvmBlockId,&NVM_CurrentErrorStatus);

    /*Feed watchdog*/
       (void)Fblm_LookForWatchdog();

  }while(NVM_CurrentErrorStatus == NVM_REQ_PENDING);
}


/*******************************************************************************
* Function Name: Cy_SysGetApplCoreStatus
****************************************************************************//**
*
* Gets the Cortex-M4/M7 core power mode.
*
* \return \ref group_system_config_cm_status_macro
*
*******************************************************************************/
uint32_t Cy_SysGetApplCoreStatus(void)
{
    uint32_t regValue;
    
    /* Get current power mode */
    #ifndef FBLM_UNITTEST
    regValue = CPUSS->unCM4_PWR_CTL.u32Register;
    #endif
    regValue = (regValue >> CPUSS_CM4_PWR_CTL_PWR_MODE_Pos) & CPUSS_CM4_PWR_CTL_PWR_MODE_Msk;

    return (regValue);
}

/*******************************************************************************
* Function Name: Cy_SysEnableApplCore
****************************************************************************//**
*
* Enables the Cortex-M4/M7 core. The CPU is enabled once if it was in the disabled
* or retained mode. 
*
* \param vectorTableOffset The offset of the vector table base address from
* memory address 0x00000000. The offset should be multiple to 1024 bytes.
*
*******************************************************************************/
void Cy_SysEnableApplCore(uint32_t vectorTableOffset)
{
    uint32_t cmStatus;
    uint32_t interruptState;
    un_CPUSS_CM4_PWR_CTL_t tPwrCtl;

    interruptState = Cy_SaveIRQ();
    
    cmStatus = Cy_SysGetApplCoreStatus();
    if(cmStatus == CY_SYS_CM_STATUS_ENABLED)
    {
        // do nothing
    }
    else
    {
        #ifndef FBLM_UNITTEST
        CPUSS->unCM4_VECTOR_TABLE_BASE.u32Register = vectorTableOffset;
        #endif
    
        tPwrCtl.stcField.u16VECTKEYSTAT = CY_SYS_PWR_CTL_KEY_OPEN;
        tPwrCtl.stcField.u2PWR_MODE = CY_SYS_CM_STATUS_ENABLED;
        #ifndef FBLM_UNITTEST
        CPUSS->unCM4_PWR_CTL.u32Register = tPwrCtl.u32Register;
        #endif
    }
    
    Cy_RestoreIRQ(interruptState);
}

void Fblm_SysEnableApplCore(void)
{
    Cy_SysEnableApplCore(CORTEX_M4_APPL_ADDR);
    for(uint32 i = 0; i < 10000000; i++)
    {
    ;
    }
}

/* AES-CMAC Generation Function */
void leftshift_onebit(unsigned char* input, unsigned char* output)
{
    int i;
    unsigned char overflow = 0;
    for (i = 15; i >= 0; i--)
    {
        output[i] = input[i] << 1;
        output[i] |= overflow;
        overflow = (input[i] & 0x80) ? 1 : 0;
    }
    return;
}

void padding(uint8* lastb, uint8* pad, uint32 length)
{
    uint32 j; /* original last block */
    for (j = 0; j < 16; j++)
    {
        if (j < length)
        {
            pad[j] = lastb[j];
        }
        else if (j == length)
        {
            pad[j] = 0x80;
        }
        else
        {
            pad[j] = 0x00;
        }
    }
}

/* Basic Functions */
void xor_128(uint8* a, uint8* b, uint8* out)
{
    uint32 i;
    for (i = 0; i < 16; i++)
    {
        out[i] = a[i] ^ b[i];
    }
}


/* copy state[4][4] to out[16] */
uint32 storeStateArray(uint8(*state)[4], uint8* out)
{
    for (uint32 i = 0; i < 4; ++i)
    {
        for (uint32 j = 0; j < 4; ++j)
        {
            *out++ = state[j][i];
        }
    }
    return 0;
}

/* Galois Field (256) Multiplication of two Bytes */
uint8 GMul(uint8 u, uint8 v)
{
    uint8 p = 0;

    for (uint32 i = 0; i < 8; ++i)
    {
        if (u & 0x01)
        {
            p ^= v;
        }

        uint32 flag = (v & 0x80);
        v <<= 1;
        if (flag)
        {
            v ^= 0x1B;
        }

        u >>= 1;
    }

    return p;
}

// 列混合
uint32 mixColumns(uint8(*state)[4])
{
    uint8 tmp[4][4];
    uint8 M[4][4] = { {0x02, 0x03, 0x01, 0x01},
                       {0x01, 0x02, 0x03, 0x01},
                       {0x01, 0x01, 0x02, 0x03},
                       {0x03, 0x01, 0x01, 0x02} };

    /* copy state[4][4] to tmp[4][4] */
    for (uint32 i = 0; i < 4; ++i)
    {
        for (uint32 j = 0; j < 4; ++j)
        {
            tmp[i][j] = state[i][j];
        }
    }

    for (uint32 i = 0; i < 4; ++i)
    {
        for (uint32 j = 0; j < 4; ++j)
        {  
            state[i][j] = GMul(M[i][0], tmp[0][j]) ^ GMul(M[i][1], tmp[1][j])
                ^ GMul(M[i][2], tmp[2][j]) ^ GMul(M[i][3], tmp[3][j]);
        }
    }

    return 0;
}

//行移位
uint32 shiftRows(uint8(*state)[4])
{
    uint32 block[4] = { 0 };

    /* i: row */
    for (uint32 i = 0; i < 4; ++i)
    {
        LOAD32H(block[i], state[i]);
        block[i] = ROF32(block[i], 8 * i);
        STORE32H(block[i], state[i]);
    }
    return 0;
}

//字节替换
uint32 subBytes(uint8(*state)[4])
{
    /* i: row, j: col */
    for (uint32 i = 0; i < 4; ++i)
    {
        for (uint32 j = 0; j < 4; ++j)
        {
            state[i][j] = S[state[i][j]];
        }
    }

    return 0;
}

// 轮密钥加
uint32 addRoundKey(uint8(*state)[4], const uint32* key)
{
    uint8 k[4][4];

    /* i: row, j: col */
    for (uint32 i = 0; i < 4; ++i)
    {
        for (uint32 j = 0; j < 4; ++j)
        {
            k[i][j] = (uint8)BYTE(key[j], 3 - i);
            state[i][j] ^= k[i][j];
        }
    }

    return 0;
}

/* copy in[16] to state[4][4] */
uint32 loadStateArray(uint8(*state)[4], const uint8* in) {
    for (uint32 i = 0; i < 4; ++i) {
        for (uint32 j = 0; j < 4; ++j) {
            state[j][i] = *in++;
        }
    }
    return 0;
}

//密钥扩展，只接受16字初始密钥 
uint32 keyExpansion(const uint8* key, uint32 keyLen, AesKey* aesKey)
{

    if (NULL == key || NULL == aesKey)
    {
        return -1;
    }

    if (keyLen != 16)
    {
        return -1;
    }

    uint32* w = aesKey->eK;  
    uint32* v = aesKey->dK;

    for (uint32 i = 0; i < 4; ++i)
    {
        LOAD32H(w[i], key + 4 * i);
    }

    /* W[4-43] */
    for (uint32 i = 0; i < 10; ++i)
    {
        w[4] = w[0] ^ MIX(w[3]) ^ rcon[i];
        w[5] = w[1] ^ w[4];
        w[6] = w[2] ^ w[5];
        w[7] = w[3] ^ w[6];
        w += 4;
    }

    w = aesKey->eK + 44 - 4;
    for (uint32 j = 0; j < 11; ++j)
    {
        for (uint32 i = 0; i < 4; ++i)
        {
            v[i] = w[i];
        }
        w -= 4;
        v += 4;
    }

    return 0;
}

void AES_128(uint8* key, uint8* ct, uint8* L)
{
    AesKey aesKey;
    //uint8* pos = ct;
    const uint32* rk = aesKey.eK;
    uint8 out[BLOCKSIZE] = { 0 };
    uint8 actualKey[16] = { 0 };
    uint8 state[4][4] = { 0 };

    memcpy(actualKey, key, 16);
    keyExpansion(actualKey, 16, &aesKey);

    for (uint32 i = 0; i < 16; i += BLOCKSIZE)
    {
        loadStateArray(state, ct);
        
        addRoundKey(state, rk);

        for (uint32 j = 1; j < 10; ++j)
        {
            rk += 4;
            subBytes(state);   
            shiftRows(state);  
            mixColumns(state); 
            addRoundKey(state, rk); 
        }

        subBytes(state);
        shiftRows(state);
        addRoundKey(state, rk + 4);

        storeStateArray(state, L);

        L += BLOCKSIZE;  
        ct += BLOCKSIZE;   
        rk = aesKey.eK;
    }
}

void generate_subkey(uint8* key, uint8* K1, uint8* K2)
{
    uint8 L[16];
    uint8 Z[16];
    uint8 tmp[16];
    uint32 i;
    for (i = 0; i < 16; i++)
        Z[i] = 0;
    AES_128(key, Z, L);
    if ((L[0] & 0x80) == 0)
    { /* If MSB(L) = 0, then K1 = L << 1 */
        leftshift_onebit(L, K1);
    }
    else
    { /* Else K1 = ( L << 1 ) (+) Rb */
        leftshift_onebit(L, tmp);
        xor_128(tmp, const_Rb, K1);
    }
    if ((K1[0] & 0x80) == 0)
    {
        leftshift_onebit(K1, K2);
    }
    else
    {
        leftshift_onebit(K1, tmp);
        xor_128(tmp, const_Rb, K2);
    }
    return;
}

void AES_CMAC(uint8* key, uint8* input, uint32 length, uint8* mac)
{
    uint8 X[16], Y[16], M_last[16], padded[16];
    uint8 K1[16], K2[16];
    uint32 n, i, flag;
    generate_subkey(key, K1, K2);
    n = (length + 15) / 16; /* n is number of rounds */
    if (n == 0)
    {
        n = 1; flag = 0;
    }
    else
    {
        if ((length % 16) == 0)
        { /* last block is a complete block */
            flag = 1;
        }
        else
        { /* last block is not complete block */
            flag = 0;
        }
    }
    if (flag)
    { /* last block is complete block */
        xor_128(&input[16 * (n - 1)], K1, M_last);
    }
    else
    {
        padding(&input[16 * (n - 1)], padded, length % 16);
        xor_128(padded, K2, M_last);
    }
    for (i = 0; i < 16; i++)
        X[i] = 0;
    for (i = 0; i < n - 1; i++)
    {
        xor_128(X, &input[16 * i], Y); /* Y := Mi (+) X */
        AES_128(key, Y, X); /* X := AES-128(KEY, Y); */
    }
    xor_128(X, M_last, Y);
    AES_128(key, Y, X);
    for (i = 0; i < 16; i++)
    {
        mac[i] = X[i];
    }
}

bool isArrayZero(uint8 arr[], uint8 size)
{
    uint8 zeroArr[size];
    memset(zeroArr, 0, sizeof(zeroArr)); 
    return memcmp(arr, zeroArr, size) == 0; 
}

void SwapEndianArray(uint8 *arr, uint8 len)
{
    uint8 temp; 
    uint8 i;

    for (i = 0; i < len / 2; i++)
    {
        temp = arr[i];             
        arr[i] = arr[len - 1 - i]; 
        arr[len - 1 - i] = temp;   
    }
}
/*______ E N D _____ (FileName.c) ____________________________________________*/
