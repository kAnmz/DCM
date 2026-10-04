/******************************************************************************/
/* @F_NAME :          fblm_config.h                                           */
/* @F_PURPOSE :       manage reprogramming for MCU                            */
/* @F_CREATED_BY :    Jianhua.Wu  			                                  */
/* @F_CREATION_DATE : 2021.07.14                                              */
/* @F_LANGUAGE :      ANSI C                                                  */
/* @F_MPROC_TYPE :    target independent           						      */
/*************************************** (C) Copyright 2021 Marelli ***********/

#ifndef _FBL_CONFIG_H_
#define _FBL_CONFIG_H_

/*______ I N C L U D E - F I L E S ___________________________________________*/
#include "type.h"
/*#include "imcm.h"*/
/*#include "imc_config.h"*/
#include "iodc.h"
/*#include "spid.h"*/
#include "timer_config.h"
#include "mcwdt_config.h"
#include "can_config.h"
#include "fbl_cfg.h"

#include "cy_device_headers.h"
#include "cy_flash.h"
#include "cy_mw_flash.h"
#include "NvM.h"
#include "wdfs_config_dynamic.h"

/*______ G L O B A L - D E F I N E S _________________________________________*/
#define FBLM_CANFD_SUPPORT      1 /*1: Support, 0: not support*/

#define Fblm_ReadWriteNvmBlockDataMaxLen       1280
#define Fblm_AsyncWriteQueueNumber             3   /*Total number*/
#define FBLM_IMCTASK_PERIOD    ((ubyte)0x05)/*ms*/
#define FBLM_DIAGTASK_PERIOD   ((ubyte)0x01)/*ms*/
#define FBLM_MAINTASK_PERIOD   ((ubyte)0x01)/*ms*/
#define Fblm_10_MS ((ubyte)10u)/*ms*/
#define FBLM_TIMTRESET_PERIOD     (200)       /* 1s */

#define TESTER_PRESENT_TIMEOUT   ((ulong)5000)/*ms*/
#define DIAG_CALL_CYCLE          ((ubyte)0x01)/*ms*/ /* Same call cycle as tp */

/*#define FBL_DIAG_BUFFER_LENGTH  ((ushort)4094)*/
#define FBL_DIAG_CAN_SEGMENT_SIZE  ((ushort)3072)/*must < FBL_DIAG_BUFFER_LENGTH,n*512*/
#define FBL_DIAG_OTA_SEGMENT_SIZE  ((ushort)512)/*Also use as MaxNumberOfBlockLength when OTA, Limited by Code Flash's character(8/32/512)*/

#define FBL_DiagRequestZize    ((ushort)(778))
#define FBL_DiagResponseZize   ((ubyte)(60))


/*Physical limit of writing code flash*/
#define FBL_MEMORY_WRITE_8BYTE    ((ushort)8)
#define FBL_MEMORY_WRITE_32BYTE   ((ushort)32)
#define FBL_MEMORY_WRITE_512BYTE  ((ushort)512)
#define FBL_MEMORY_WRITE_NOP	  ((ubyte)50)



#define FBLM_RESET_WAITING_TIMEOUT  ((ushort) (3000/FBLM_MAINTASK_PERIOD))

/*UDS MACRO setting-------------------$27-----------------Start*/
#define FBL_ENABLE_SEC_ACCESS_DELAY   /*if exceededNumberOfAttempts,must delay...*/

#if defined( FBL_ENABLE_SEC_ACCESS_DELAY )
# if !defined(kSecMaxInvalidKeys)
#  define kSecMaxInvalidKeys          ((ubyte) 0x02u)
# endif
# define kSecSecurityAccessDelay     ((ulong) 10000/FBLM_DIAGTASK_PERIOD)/*10S*/
#endif
/*UDS MACRO setting-------------------$27-----------------END*/
/*UDS timer parameter setting------------------------------------Start*/
/*Diagnostic Application Layer Parameters*/
//#define FBL_DIAG_TIME_P2MAX   (50/FBLM_DIAGTASK_PERIOD)
//#define FBL_DIAG_TIME_P3MAX   (2000/FBLM_DIAGTASK_PERIOD)
/*P2CAN_server is defined as the duration in which an ECU\
 *must prepare and transmit a “proper” diagnostic response\
 *(positive or negative) to an external test tool.*/
#define kFblDiagTimeP2DefaultSession        FBL_DIAG_TIME_P2MAX_DEFAULT_SESSION
#define kFblDiagTimeP2        FBL_DIAG_TIME_P2MAX
#define kFblDiagTimeP2Star    FBL_DIAG_TIME_P3MAX/*P2*CAN_server,0x78-Response Pending*/
#define kDiagConfirmationTimeout ((ushort) 100u)/*TP confirmation timeout*/
/*Diagnostic session timing for SID10*/
#define kDiagSessionTimingP2Resolution (1u) /* 1ms */
#define kDiagSessionTimingP2StarResolution (10u) /* 10ms */
#define kDiagSessionTimingP2DefaultSession     ((ushort) ((kFblDiagTimeP2DefaultSession*FBLM_DIAGTASK_PERIOD)/kDiagSessionTimingP2Resolution))
#define kDiagSessionTimingP2     ((ushort) ((kFblDiagTimeP2*FBLM_DIAGTASK_PERIOD)/kDiagSessionTimingP2Resolution))
#define kDiagSessionTimingP2Star ((ushort) ((kFblDiagTimeP2Star*FBLM_DIAGTASK_PERIOD)/kDiagSessionTimingP2StarResolution))

#define kDiagTransmitTimeout    ((ushort) 10u)
/*UDS timer parameter setting------------------------------------END*/



/*************************Flash Block number start********************************/
#define FlashDrv_BlockIndex      ((ubyte) 0x00u)  /*flash driver block*/
#define FlashDrvSHA_BlockIndex   ((ubyte) 0x01u)  /*flash driver SHA block*/
#define APP_BlockIndex           ((ubyte) 0x02u)  /*MCU APP block*/
#define APPSHA_BlockIndex        ((ubyte) 0x03u)  /*MCU APP SHAblock*/
#define SWP1_BlockIndex          ((ubyte) 0x04u)  /*SWP1 block*/
#define SWP1SHA_BlockIndex       ((ubyte) 0x05u)  /*SWP1 SHA block*/

#define Invalid_BlockIndex    ((ubyte) 0xFFu)  /*Invalid block*/

//#define FBL_MTAB_NO_OF_BLOCKS ((ubyte) 0x02u)  /*Total blocks*/

#define FBLM_FLASHDRV_STARTADDRESS       0x8017000u /*FlashDrv Ram Address*/
#define FlashDrv_BlockSize               0x8000      /*size of flash driver block*/
#define FBLM_APP_STARTADDRESS            0x10060000u  /*Application codeflash Start Address*/
#define FBLM_APP_LENGTH                  0xAE000u     /*Application codeflash Length*/
#define FBLM_APP_END                     0x1010DFFFu     /*Application codeflash End Address*/
#define FBLM_FLASHDRIVER_VBTADDR         0x801F100u   /*FlashDrv VBT Start Address*/
#define FBLM_APP_VBTADDR                 0x801902Cu    /*Application VBT Address*/
#define FBLM_SWP1_STARTADDRESS           0x8016C00u    /*SWP1 Block Vitual Start Address*/
#define FBLM_SWP1_SIZE                   0x400u       /*SWP1 Block Start Size*/
#define FBLM_SWP1_VBTADDR                0x8019100u    /*SWP1 Block Vitual Start Address*/


#define FBLM_VBT_SIZE                    44
#define FlashDrvSHA_BlockSize     FBLM_VBT_SIZE  /*size of flash driver SHA block*/
#define APPSHA_BlockSize          FBLM_VBT_SIZE  /*size of flash driver SHA block*/

#define FBLM_Checksum_Length                    4u   /*codeflash checksum length*/
/*************************Flash Block number end********************************/

#define FBL_BIT0   0x01u
#define FBL_BIT1   0x02u
#define FBL_BIT2   0x04u
#define FBL_BIT3   0x08u
#define FBL_BIT4   0x10u
#define FBL_BIT5   0x20u
#define FBL_BIT6   0x40u
#define FBL_BIT7   0x80u


/* macros to harmonize type casts for inverting bits ~*/
#define FblInvertBits(x,type)  ( (type)  ~((type) (x))      )
#define FblInvert8Bit(x)       ( FblInvertBits((x),ubyte)  )
#define FblInvert16Bit(x)      ( FblInvertBits((x),ushort) )
#define FblInvert32Bit(x)      ( FblInvertBits((x),ulong) )

/* decompose 32 bit data in byte stream */
#define FblmGetHiHiByte(data)         ((ubyte)(((ulong)(data))>>24))
#define FblmGetHiLoByte(data)         ((ubyte)(((ulong)(data))>>16))
#define FblmGetLoHiByte(data)         ((ubyte)(((ulong)(data))>>8))
#define FblmGetLoLoByte(data)         ((ubyte)(data))

/* compose from byte stream a 16 bit data */
#define FblmMake16Bit(hiByte,loByte)  ((ushort)((((ushort)(hiByte))<<8)| \
                                      ((ushort)(loByte))))
/* compose from byte stream a 32 bit data */
#define FblmMake32Bit(hiHiByte,hiLoByte,loHiByte,loLoByte)  ((ulong)((((ulong)(hiHiByte))<<24)| \
                                                                     (((ulong)(hiLoByte))<<16)| \
                                                                     (((ulong)(loHiByte))<<8) | \
                                                                     ((ulong)(loLoByte))))
/* decompose 16 bit data in byte stream */

//#define FBLM_DIAG_USE_NVM   /*no used*/
#define Fblm_NVM_WRITE_TIMEOUT ((uint16)(500u*Fblm_10_MS))
/* #define Fblm_UNLOCKED_27_01_REQ_SEED_TIMES_NO_LIMIT */

#define Fblm_AllProgramStatusVaild   0xA5A5A5A5
#define Fblm_ProgramStatusVaild      0xA5A5
#define Fblm_ProgramStatusInvaild    0x1234
#define Fblm_ProgramStatusCrcInVaild 0xBCBC

#define Fblm_PublicKeyNoDefaultStatus   0xAB
#define Fblm_PublicKeyDefaultStatus     0xFF

#define Fblm_BootDataConfigNoDefaultStatus   0xABAB
#define Fblm_BootDataConfigDefaultStatus     0xFFFF

/* #define FBL_DISABLE_ROUTINE_CONTROL_ID */

#define FBLM_CHECKMEMORY_RESPONSE_VERIFICAITON_PASSED          0x00
#define FBLM_CHECKMEMORY_RESPONSE_SIGNATURE_FAIL               0x01
#define FBLM_CHECKMEMORY_RESPONSE_PUBLICKEY_INTEGRITY_FAIL     0x02
#define FBLM_CHECKMEMORY_RESPONSE_PUBLICKEY_INTEGRITY_FAIL     0x02

// 从uint32_t x中提取从低位开始的第n个字节
#define BYTE(x, n) (((x) >> (8 * (n))) & 0xff)

// uint8_t y[4] -> uint32_t x
#define LOAD32H(x, y) \
  do { (x) = ((uint32_t)((y)[0] & 0xff)<<24) | ((uint32_t)((y)[1] & 0xff)<<16) | \
             ((uint32_t)((y)[2] & 0xff)<<8)  | ((uint32_t)((y)[3] & 0xff));} while(0)

             // 密钥扩展中的SubWord(RotWord(temp),字节替换然后循环左移1位
#define MIX(x) (((S[BYTE(x, 2)] << 24) & 0xff000000) ^ ((S[BYTE(x, 1)] << 16) & 0xff0000) ^ \
                ((S[BYTE(x, 0)] << 8) & 0xff00) ^ (S[BYTE(x, 3)] & 0xff))

// uint32_t x循环左移n位
#define ROF32(x, n)  (((x) << (n)) | ((x) >> (32-(n))))
// uint32_t x循环右移n位
#define ROR32(x, n)  (((x) >> (n)) | ((x) << (32-(n))))

// uint32_t x -> uint8_t y[4]
#define STORE32H(x, y) \
  do { (y)[0] = (uint8_t)(((x)>>24) & 0xff); (y)[1] = (uint8_t)(((x)>>16) & 0xff);   \
       (y)[2] = (uint8_t)(((x)>>8) & 0xff); (y)[3] = (uint8_t)((x) & 0xff); } while(0)

#define BLOCKSIZE 16  //AES-128分组长度为16字节

// AES-128轮常量,无符号长整型 
static const uint32 rcon[10] = {
		0x01000000UL, 0x02000000UL, 0x04000000UL, 0x08000000UL, 0x10000000UL,
		0x20000000UL, 0x40000000UL, 0x80000000UL, 0x1B000000UL, 0x36000000UL
};
#define  FLASH_DRIVER_BOUNDCHECK_OFFSET                  4
#define  FLASH_DRIVER_ERASE_OFFSET                       8
#define  FLASH_DRIVER_WRITE_OFFSET                       12
#define  FLASH_DRIVER_INIT_OFFSET                        16
#define  FLASH_DRIVER_RAM_INIT_OFFSET                    24
/* Flash erase function --------------------------------------------*/
# define FLASH_DRIVER_ERASE(sectorAddr, blocking)\
   ((tFlashEraseFct)(*(unsigned long *)&flashCode[FLASH_DRIVER_ERASE_OFFSET]))(sectorAddr, blocking)

/* Flash write function --------------------------------------------*/
# define FLASH_DRIVER_WRITE(writeAddr, data, size, blocking)\
   ((tFlashFct)(*(unsigned long *)&flashCode[FLASH_DRIVER_WRITE_OFFSET]))(writeAddr, data, size, blocking)

# define FLASH_DRIVER_BOUNDCHECK(address)\
   ((tFlashCheckFct)(*(unsigned long *)&flashCode[FLASH_DRIVER_BOUNDCHECK_OFFSET]))(address)

# define FLASH_DRIVER_INIT(non_blocking)\
   ((tFlashInit)(*(unsigned long *)&flashCode[FLASH_DRIVER_INIT_OFFSET]))(non_blocking)

# define FLASH_DRIVER_RAM_INIT(void)\
   ((tFlashDRVRAMInitFct)(*(unsigned long *)&flashCode[FLASH_DRIVER_RAM_INIT_OFFSET]))(void)

# define FLASH_DRIVER_GETDRVSTATUS(context)\
   ((tFlashGetDrvStatusFct)(*(unsigned long *)&flashCode[20]))(context)
/*______ G L O B A L - T Y P E S _____________________________________________*/
typedef enum
{
  FBLM_VERIFICAITON_PASSED,
  FBLM_SIGNATURE_VERIFICAITON_FAIL,
  FBLM_PUBLIC_KEY_FAIL,
  FBLM_INVALID_FORMAT_VBT,
  FBLM_BLOCK_HASH_INVALID,
  FBLM_BLANK_CHECK_FAIL, /* RESERVED */
  FBLM_NO_DATA_DOWNLOADED,
  FBLM_READ_ERROR_HASH_CAL,  /* RESERVED */
  FBLM_ESS_VERIFY_FAIL,  /* RESERVED */
  FBLM_ADDITIONAL_PROCESSOR_FAIL,  /* RESERVED */
  FBLM_STORAGE_VALIDITY_STATUS_FAIL,
  FBLM_CERTIFICATE_VERIFICATION_FAIL, /* RESERVED */
  FBLM_FBLM_USER_DEFINED  /* Means Software and hadware version not match */
} FBLM_CheckMemoryResId_t;

typedef enum
{
  UPDATE_MODE_CAN            = 0x00u,       /*default by CAN*/
  UPDATE_MODE_OTA            = 0x01u		/*by OTA*/
} FBLM_UpdateMode_t;

typedef enum
{
  FBLM_BOOT_PARA_UNKNOW,
  FBLM_BOOT_PARA_PUBLIC_KEY,
  FBLM_BOOT_PARA_BOOT_DATA
} FBLM_BootParaSubId_t;

typedef enum 
{
  Fblm_NVM_IDLE,
  Fblm_NVM_WRITE_REQ,
  Fblm_NVM_WRITE_IN_PROCESS
} Fblm_NvmProcessState_t;

typedef enum 
{
  Fblm_NVM_WRITE_PENDING,
  Fblm_NVM_WRITE_SUCCESS,
  Fblm_NVM_WRITE_FAILED
} Fblm_NvmWriteResult_t;

typedef struct 
{
  NvM_BlockIdType BlockId;
  uint8 *pData;
  Fblm_NvmWriteResult_t *pWriteResult;
} Fblm_NvmWriteReq_t;

typedef enum
{
  Fblm_AppCodeProgramStatus,
  Fblm_SWP1ProgramStatus,
} Fblm_ProgramStatusType_t;

typedef struct             /*Queue Properties */
{
  uint8        bufferIsFree;
  uint8        requestProcess;
  uint16       dataLength;
  uint8        databuffer[Fblm_ReadWriteNvmBlockDataMaxLen];
  vuint16      reqStep;
  uint8        waitReqTime;
  uint8        RequestNvmID;
}Fblm_WriteQueueBufferAttribute;

typedef struct
{
	uint32 eK[44], dK[44];    // encKey, decKey
	int Nr; // 10 rounds
}AesKey;

typedef enum
{
  Fblm_F1AAID = 0,
  Fblm_F1ABID,
  Fblm_F1A1ID,
  Fblm_F1A5ID,
  Fblm_F18CID,
  Fblm_F18BID,
  Fblm_ChksumAplID,
  Fblm_SWVersionID,
  Fblm_F194ID,
  Fblm_F103ID,
  Fblm_F19EID,
  Fblm_PasswordID,
  Fblm_SecurityConstantID,
  Fblm_HWVersionID,
  Fblm_EolDoneID,
  Fblm_CodeFlashNum,
} Fblm_CodeFlashNum_t;

typedef struct {
  uint8  F1AA[8];
  uint8  F1AB[8];
  uint8  F1A1[8];
  uint8  F1A5[8];
  uint8  F18C[4];
  uint8  F18B[3];
  uint8  ChksumApl[2];
  uint8  SWVersion[2];
  uint8  F194[15];
  uint8  F103[6];
  uint8  F19E[7];
  uint8  Password[16];
  uint8  SecurityConstant[5];
  uint8  HWVersion[10];
  uint8  EolDone;
  uint8  Reserve[25];
} Fblm_PartNumber_t;

typedef struct
{
  uint8  *Address_CodeFlash;
  uint8  length;
}Fblm_CodeFlashSectorAdrTbl;

typedef void(* tFlashEraseFct) (uint32_t sectorAddr, cy_en_flash_driver_blocking_t blocking);
typedef void(* tFlashFct) ( uint32_t writeAddr, const uint32_t* data, cy_en_flash_programrow_datasize_t size, cy_en_flash_driver_blocking_t blocking );
typedef en_flash_bounds_t(* tFlashCheckFct) (uint32_t address);
typedef void (* tFlashInit)(bool non_blocking);
typedef void (* tFlashDRVRAMInitFct)(void);
typedef cy_en_flashdrv_status_t (* tFlashGetDrvStatusFct)(cy_un_flash_context_t *context);
/*______ G L O B A L - D A T A _______________________________________________*/
extern uint8 Fblm_AppVerificationBlockTable[44];
extern uint16 Fblm_AppVerificationBlockTableLength;
extern ubyte Fblm_SecurityConstantLevel[16];
extern ubyte Fblm_PublicKeyData[256];
extern ubyte Fblm_PublicKeyExponent[4];
extern ubyte Fblm_AppFlashSigntureSucFlag;
extern uint8 Fblm_AsyncReqForRunningNvmFeeFlsTask;
extern uint8 Fblm_SyncReqForRunningNvmFeeFlsTask;

extern uint8 Fblm_UpgradeSWP1BlockFlag;
extern uint8 Fblm_UpgradeAPPBlockFlag;
extern uint8 Fblm_AppProgramStsUpdateFlag;
extern uint8 Fblm_Swp1ProgramStsUpdateFlag;

extern uint8 NVMM_PublicKeyStatusDidStatus;


extern boolean Fblm_EraseDoneFlag;

extern uint8_t   flashCode[FlashDrv_BlockSize];
/*______ G L O B A L - M A C R O S ___________________________________________*/

/*______ G L O B A L - F U N C T I O N S - P R O T O T Y P E S _______________*/
extern void Fblm_TimerStop(void);
extern void Fblm_Reset(void);
extern ulong Fblm_crc32(const ubyte *buffer, ulong datalen);
extern void Fblm_SyncWriteNvmData(ushort WriteLen, ushort NvmID, ubyte ResponseLen, ubyte *pbDiagData);
extern void Fblm_AsyncWriteNvmData(ushort WriteLen, ushort NvmID, ubyte *pbDiagData);
extern uint8 Fblm_SetSecurityAccessUnlockedL1AttemptCounter(uint8 AttemptCounter);
extern ubyte Fblm_LookForWatchdog(void);
extern void FBLM_FlashDriverInit(void);
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
extern uint8 Fblm_ProgrammingDependenciesChecksumOK(void);
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
extern void Fblm_SetProgramStatusInfo(Fblm_ProgramStatusType_t SetType, uint16 Value);

/*----------------------------------------------------------------------------*/
/*Name : Fblm_UpdateReprogrammingCounter
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
extern void Fblm_UpdateReprogrammingCounter(Fblm_ProgramStatusType_t ProgramStaus);


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
extern uint32 Fblm_GetProgramStatusInfo(void);
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
extern uint16 Fblm_GetAppCodeProgramStatusInfo(void);

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
extern uint16 Fblm_GetSwp1ProgramStatusInfo(void);


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
extern ubyte Fblm_GetSyncWriteFreeSts(void);

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
extern void Fblm_ASyncWriteQueueInit(void);

/*******************************************************************************
* NAME:              Fblm_AsyncWriteQueueUpdateRequest
*
* CALLED BY:         DescTask
* PRECONDITIONS:
*
* DESCRIPTION:       Update diag request to desc ptr.
*
*******************************************************************************/
extern void Fblm_AsyncWriteQueueUpdateRequest(void);


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
extern void Fblm_InitASyncWriteQueue(vuint8 queuenum);

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
extern void Fblm_RequestForReset(void);


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
extern ubyte Fblm_GetRequestForReset(void);

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
extern void Fblm_ManageResetAction(void);

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
extern uint8 Fblm_CalculateAndGetAPPChecksumResult(void);


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
extern uint8 Fblm_GetAPPChecksumResult(void);

/*----------------------------------------------------------------------------*/
/*Name : Fblm_crc16           			                                      */
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
extern uint16 Fblm_crc16(const char *buf, int len);

/******************************************************************************/
/* Name : Fblm_ChecksumForSwp1                                                */
/* Role : Geely SecurityAcess Service Key generate method                     */
/* Interface :     none                                                       */
/* Pre-condition :   none                                                     */
/* Constraints :  This function should not be change                          */
/******************************************************************************/
extern uint16 Fblm_ChecksumForSwp1(void);


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
extern void Fblm_ReadNvMIdBeforeJump(void);

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
extern void Fblm_ReadAll(void);

extern void Fblm_SysEnableApplCore(void);
#endif /* _FBL_CONFIG_H_ */
