/*****************************************************************************
| Project Name: FblDrvFlash_V85xUx6lfHis
|    File Name: flashdrv.c
|
|  Description: Implementation of the flash algorythm
|               Target systems: V850 with UX6LF flash technology
|               Compiler:       GHS                                         */
/*----------------------------------------------------------------------------
|               C O P Y R I G H T
|-----------------------------------------------------------------------------
| Copyright (c) 2010 by Vector Informatik GmbH.       All rights reserved.
|
| This software is copyright protected and proprietary 
| to Vector Informatik GmbH. Vector Informatik GmbH 
| grants to you only those rights as set out in the 
| license conditions. All other rights remain with 
| Vector Informatik GmbH.
|
|-----------------------------------------------------------------------------
|               A U T H O R   I D E N T I T Y
|-----------------------------------------------------------------------------
| Initials     Name                      Company
| --------     ---------------------     -------------------------------------
| Rr           Robert Schaeffner         Vector Informatik GmbH
|-----------------------------------------------------------------------------
|               R E V I S I O N   H I S T O R Y
|-----------------------------------------------------------------------------
| Date        Version   Author  Description                                 */
/*----------  --------  ------  ---------------------------------------------
| 2010-04-08  01.00.00  Rr      Creation, derived from MF2
|****************************************************************************/

#include "type.h"
#ifdef __RH850_F1x__
#include "fcl_user.h"
#include "r_typedefs.h"
#include "r_fcl_types.h"
#include "r_fcl.h"
#include "flashdrv.h"

/******************************************************************************/
/* Version control                                                            */
/******************************************************************************/
#if (FBLDRVFLASH_V85XUX6LFHIS_VERSION != 0x0100)     || \
    (FBLDRVFLASH_V85XUX6LFHIS_RELEASE_VERSION != 0x00)
# error "Source and header file versions are inconsistent!"
#endif

/******************************************************************************/
/* CPU-Type check                                                             */
/******************************************************************************/
# if (FLASH_DRIVER_VERSION_MCUTYPE   != 0x85) || \
     (FLASH_DRIVER_VERSION_MASKTYPE  != 0x09) || \
     (FLASH_DRIVER_VERSION_INTERFACE != 0x03)
#  error "CPU type error! Wrong flashdrv.h file."
# endif
#endif
/* Defines *******************************************************************/

/* The following value must be a multiple of 8!*/
#define kFlashNrOfBlocks 1000 

/* Types *********************************************************************/
#ifdef __RH850_F1x__
/* Flash header structure */
typedef struct
{
  /* Definition of the 4-byte flash algorithm header */
  unsigned char version;
  unsigned char reserved;
  unsigned char maskType;
  unsigned char CPUType;
  tFlashFct flashInitFct;
  tFlashFct flashDeinitFct;
  tFlashFct flashEraseFct;
  tFlashFct flashWriteFct;
  tFlashFct flashVerifyFct;   
}tFlashHeader;

typedef struct {
    unsigned long  BlockSize;
    unsigned long  BlockCount;
    unsigned char BlockModified[kFlashNrOfBlocks/8];
} tFlashStructure;

/* Prototypes ------------------------------------------------------------ */

/* Flash API functions                                                     */
void FblDrvFlashInit( tFlashParam *flashStruct );
void FblDrvFlashDeinit( tFlashParam *flashStruct );
void FblDrvFlashErase( tFlashParam *flashStruct );
void FblDrvFlashWrite( tFlashParam *flashStruct );
void FblDrvFlashVerify( tFlashParam *flashStruct );
ubyte FblGetBlockIdByAddress(tFlashAddress address);

/* Variables and constants ----------------------------------------------- */
# define NOINIT
# define BREL
# pragma ghs section bss=".FLASHDRV_data"
/* remember the location of the structure                                  */
BREL NOINIT tFlashParam* pflashParam;
/* Local Version of Flash Block Table                                      */
BREL NOINIT tFlashStructure FlashStructure;
# pragma ghs section bss=default


# pragma ghs section rodata=".FLASHDRV"
/* Header which includes the flash driver interface for the flio. */
/* This code will be placed into the section .signatur.const      */
const tFlashHeader flashHeader=
{
   FLASH_DRIVER_VERSION_INTERFACE
  ,0x00
  ,FLASH_DRIVER_VERSION_MASKTYPE
  ,FLASH_DRIVER_VERSION_MCUTYPE
  ,&FblDrvFlashInit
  ,&FblDrvFlashDeinit
  ,&FblDrvFlashErase
  ,&FblDrvFlashWrite
  ,&FblDrvFlashVerify
};
# pragma ghs section rodata=default

/* Defines --------------------------------------------------------------- */
# pragma ghs section bss=".FLASHDRV_data"
static bool_t FCL_Initialed;
# pragma ghs section bss=default

#define FCL_AUTHENTICATION_ID {0xFFFFFFFF, \
                               0xFFFFFFFF, \
                               0xFFFFFFFF, \
                               0xFFFFFFFF}                    /*!< 128Bit authentication ID */


/*F1L*/
#ifdef __RH850_F1L__
  #define FCL_CPU_FREQUENCY_MHZ   80   /*80 MHZ,CPU frequency in MHz*/
  extern char  __ghsbegin_FCL_RESERVED[];
  #define FCL_RAM_ADDRESS         (uint32_t)__ghsbegin_FCL_RESERVED                     /*!< RAM address range blocked for FCL */

  /* F1L WS2.0 needs Code Flash authentication prior to switch mode */
  #define R_FCL_DEVICE_SPECIFIC_INIT                                  \
              *(volatile uint32_t *)0xFFA08000 = 0xFFFFFFFF;          \
              *(volatile uint32_t *)0xFFA08004 = 0xFFFFFFFF;          \
              *(volatile uint32_t *)0xFFA08008 = 0xFFFFFFFF;          \
              *(volatile uint32_t *)0xFFA0800C = 0xFFFFFFFF;

  /*F1L R7F7010303 code flash: 8*8K, 46*32K*/
#define FCL_SmallBlock_Nr     8
#define FCL_SmallBlock_Size  (8*1024)
#define FCL_LargeBlock_Nr     46
#define FCL_LargeBlock_Size  (32*1024)
#define FCL_RomStartAddress   0x0
#endif /*end __RH850_F1L__*/

/*F1K*/

#ifdef __RH850_F1K__
  #define FCL_CPU_FREQUENCY_MHZ   80   /*80 MHZ,CPU frequency in MHz*/
  extern char  __ghsbegin_FCL_RESERVED[];
  #define FCL_RAM_ADDRESS         (uint32_t)__ghsbegin_FCL_RESERVED                     /*!< RAM address range blocked for FCL */

  /*F1L R7F7015834 code flash: 8*8K, 62*32K*/
#define FCL_SmallBlock_Nr     8
#define FCL_SmallBlock_Size  (8*1024)
#define FCL_LargeBlock_Nr     62
#define FCL_LargeBlock_Size  (32*1024)
#define FCL_RomStartAddress   0x0
#endif /*end __RH850_F1K__*/

/*Common*/
# pragma ghs section rodata=".FLASHDRV_Const"
const r_fcl_descriptor_t r_fcl_descriptor = {
    FCL_AUTHENTICATION_ID,      /*!< Authentication ID */
    FCL_RAM_ADDRESS,            /*!< Start of RAM range blocked for FCL */
    FCL_CPU_FREQUENCY_MHZ       /*!< CPU frequency in MHz */
};
# pragma ghs section rodata=default

#define FBL_FLASHER_INVALIDID 0xffu

#endif /*end __RH850_F1x__*/

#ifdef __RH850_F1x__

# pragma ghs section text=".FLASHDRV_Func"
/*Find Block id by Address*/
ubyte FblGetBlockIdByAddress(tFlashAddress address)
{
  ubyte ret = FBL_FLASHER_INVALIDID;
  tFlashAddress tmpStart;

  if(address < (FCL_RomStartAddress + FCL_SmallBlock_Nr*FCL_SmallBlock_Size))
  {
    /*Small block*/
    tmpStart = FCL_RomStartAddress;

    ret = (address - tmpStart)/FCL_SmallBlock_Size;

  }else{
    /*Large block*/
    tmpStart = (FCL_RomStartAddress + FCL_SmallBlock_Nr*FCL_SmallBlock_Size);

    ret = (address - tmpStart)/FCL_LargeBlock_Size + FCL_SmallBlock_Nr;
  }

  if(ret > FCL_SmallBlock_Nr + FCL_LargeBlock_Nr - 1)
  {
    ret = FBL_FLASHER_INVALIDID;
  }

  return ret;
}

/****************************************************************************
* Name         :  FblDrvFlashInit
* Called by    :  FlashEntrypoint
* Preconditions:  None
* Parameters   :  Flash Parameter Structure - WatchDog function
* Return code  :  None
* Description  :  Initialization of Flash Library and needed variables
****************************************************************************/
void FblDrvFlashInit( tFlashParam *flashStruct )
{
  r_fcl_status_t ret;
  r_fcl_request_t  flasherRequest;

  FCL_Initialed = FALSE;
  flashStruct->errorCode = kFlashInitFailed;
#ifdef __RH850_F1L__
  R_FCL_DEVICE_SPECIFIC_INIT
#endif

  ret = R_FCL_Init (&r_fcl_descriptor);
  if(R_FCL_OK == ret)
  {
    ret = R_FCL_CopySections ();
    if(R_FCL_OK == ret)
    {
      /*enable FLahser access*/
      FCLUser_Open ();

      /* prepare environment */
      flasherRequest.command_enu = R_FCL_CMD_PREPARE_ENV;
      R_FCL_Execute (&flasherRequest);

      /* wait to accomplish*/
      while (R_FCL_BUSY == flasherRequest.status_enu)
      {
          R_FCL_Handler ();
          flashStruct->wdTriggerFct();
      }
    }
  }

  /*Disable Lock Bit*/
  if (R_FCL_OK == flasherRequest.status_enu)
  {
    flasherRequest.command_enu = R_FCL_CMD_DISABLE_LOCKBITS;
    R_FCL_Execute(&flasherRequest);

    /* wait to accomplish*/
    while (R_FCL_BUSY == flasherRequest.status_enu)
    {
        R_FCL_Handler ();
        flashStruct->wdTriggerFct();
    }
  }

  if(R_FCL_OK == flasherRequest.status_enu)
  {
    FCL_Initialed = TRUE;
    flashStruct->errorCode = kFlashOk;
  }
  return;
}

/****************************************************************************
* Name         :  FblDrvFlashErase
* Called by    :  FlashEntrypoint
* Preconditions:  FblDrvFlashInit
* Parameters   :  Flash Parameter Structure - StartAddress, Length
* Return code  :  None
* Description  :  Erase flash according to the given parameter.
*                 If the flash can not be erased or the erase requst will 
*                 overlap the section in which the FBL is placed a error 
*                 will be returned.
*                 The function will erase the memory block by block.
****************************************************************************/
void FblDrvFlashErase( tFlashParam *flashStruct )
{
  r_fcl_request_t     flasherRequest;
  ubyte startBlock;
  ubyte endBlock;

  flashStruct->errorCode = kFlashEraseFailed;

  if(FCL_Initialed == TRUE)
  {
    startBlock = FblGetBlockIdByAddress(flashStruct->address);
    endBlock = FblGetBlockIdByAddress(flashStruct->address + flashStruct->length - 1);

    if((startBlock != FBL_FLASHER_INVALIDID) && (endBlock != FBL_FLASHER_INVALIDID))
    {
      flasherRequest.command_enu = R_FCL_CMD_ERASE;
      flasherRequest.idx_u32     = startBlock;
      flasherRequest.cnt_u16     = (endBlock-startBlock+1);
      R_FCL_Execute (&flasherRequest);
      while (R_FCL_BUSY == flasherRequest.status_enu)
      {
          R_FCL_Handler ();
          flashStruct->wdTriggerFct();
      }

      if(flasherRequest.status_enu == R_FCL_OK)
      {
        flashStruct->errorCode = kFlashOk;
      }
    }
  }/*end FCL_Initialed == TRUE*/

  return;
}

/****************************************************************************
* Name         :  FblDrvFlashWrite
* Called by    :  FlashEntrypoint
* Preconditions:  FblDrvFlashInit
* Parameters   :  Flash Parameter Structure - Source, DestinationAdr, Length
* Return code  :  None
* Description  :  This function writes data into the flash memory.
*                 It is only posisble to write multiple of 4 bytes into flash.
****************************************************************************/
void FblDrvFlashWrite( tFlashParam *flashStruct )
{
  r_fcl_request_t     flasherRequest;

  flashStruct->errorCode = kFlashWriteFailed;

  /*256bytes aligned*/
  if((FCL_Initialed == TRUE) && \
      (flashStruct->address % FLASH_SEGMENT_SIZE == 0) && \
      (flashStruct->length % FLASH_SEGMENT_SIZE == 0))
  {

    flasherRequest.command_enu = R_FCL_CMD_WRITE;
    flasherRequest.bufferAdd_u32 = (uint32_t)flashStruct->data;
    flasherRequest.idx_u32       = flashStruct->address;
    /* written bytes = 256 * cnt_u16 */
    flasherRequest.cnt_u16       = flashStruct->length / FLASH_SEGMENT_SIZE;
    R_FCL_Execute (&flasherRequest);
    while (R_FCL_BUSY == flasherRequest.status_enu)
    {
        R_FCL_Handler ();
        flashStruct->wdTriggerFct();
    }

    if(flasherRequest.status_enu == R_FCL_OK)
    {
      flashStruct->errorCode = kFlashOk;
    }

  }/*end FCL_Initialed == TRUE*/

  return;
}

/****************************************************************************
* Name         :  FblDrvFlashDeinit
* Called by    :  FlashEntrypoint
* Preconditions:  None
* Parameters   :  Flash Parameter Structure - Not used
* Return code  :  None
* Description  :  Deinitialization of Flash Library and needed variables.
*                 This function also checks if the verification for the 
*                 flash blocks where perfomed. In case there is a flash block 
*                 found, which is not verified a error code is returned.
****************************************************************************/
void FblDrvFlashDeinit( tFlashParam *flashStruct )
{
  r_fcl_request_t     flasherRequest;

  if (TRUE == FCL_Initialed)
  {
    /*Enable Lock Bit*/
    flasherRequest.command_enu = R_FCL_CMD_ENABLE_LOCKBITS;
    R_FCL_Execute(&flasherRequest);

    /* wait to accomplish*/
    while (R_FCL_BUSY == flasherRequest.status_enu)
    {
        R_FCL_Handler ();
        flashStruct->wdTriggerFct();
    }

    FCLUser_Close();
    FCL_Initialed = FALSE;
  }
  return;
}

/****************************************************************************
* Name         :  FblDrvFlashVerify
* Called by    :  FlashEntrypoint
* Preconditions:  None
* Parameters   :  Flash Parameter Structure - Not used
* Return code  :  None
* Description  :  Checks the whole flash for errors
****************************************************************************/
void FblDrvFlashVerify( tFlashParam *flashStruct )
{


  return;
}

# pragma ghs section text=default
#endif
