/*****************************************************************************
| Project Name: FblDrvFlash_V85xUx6lfHis
|    File Name: flashdrv.h
|
|  Description: Interface for flash algorythm
|               Declaration of functions, variables, and constants
|
|     Compiler: see module file
|                                                                           */
/*----------------------------------------------------------------------------
|               C O P Y R I G H T
|-----------------------------------------------------------------------------
| Copyright (c) 2010 by Vector Informatik GmbH.      All rights reserved.
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
| --------     ---------------------     ------------------------------------
| Rr           Robert Schaeffner         Vector Informatik GmbH
|-----------------------------------------------------------------------------
|               R E V I S I O N   H I S T O R Y
|-----------------------------------------------------------------------------
| Date        Version   Author  Description                                 */
/*----------  --------  ------  ---------------------------------------------
| 2010-04-08  01.00.00  Rr      Creation, derived from MF2
|****************************************************************************/
#ifndef FBLDRVFLASH_RH850_F1X_H
# define FBLDRVFLASH_RH850_F1X_H
/***************************************************************************/
/* Version control                                                         */
/***************************************************************************/
/* --- Version --- */
/* ##V_CFG_MANAGEMENT ##CQProject : FblDrvFlash_V85xUx6lfHis CQComponent : Implementation */
# define FBLDRVFLASH_V85XUX6LFHIS_VERSION          0x0100
# define FBLDRVFLASH_V85XUX6LFHIS_RELEASE_VERSION  0x00
/* Flash Driver hardware information */
# define FLASH_DRIVER_VERSION_MCUTYPE   0x85
# define FLASH_DRIVER_VERSION_MASKTYPE  0x09
# define FLASH_DRIVER_VERSION_INTERFACE 0x03

/* Flash Driver software information */
# define FLASH_DRIVER_VERSION_MAJOR     ((FBLDRVFLASH_V85XUX6LFHIS_VERSION>>8)& 0xff)
# define FLASH_DRIVER_VERSION_MINOR      (FBLDRVFLASH_V85XUX6LFHIS_VERSION    & 0xff)
# define FLASH_DRIVER_VERSION_PATCH       FBLDRVFLASH_V85XUX6LFHIS_RELEASE_VERSION

/* If Flash Driver is notrelocatable, set this define */
# define FLASH_DRIVER_NOT_RELOCATABLE

/* Function call table offsets */
# define FLASH_DRIVER_HEADER_OFFSET     0x04

# define FLASH_DRIVER_INIT_OFFSET       (FLASH_DRIVER_HEADER_OFFSET + 0x00)
# define FLASH_DRIVER_DEINIT_OFFSET     (FLASH_DRIVER_HEADER_OFFSET + 0x04)
# define FLASH_DRIVER_ERASE_OFFSET      (FLASH_DRIVER_HEADER_OFFSET + 0x08)
# define FLASH_DRIVER_WRITE_OFFSET      (FLASH_DRIVER_HEADER_OFFSET + 0x0c)
# define FLASH_DRIVER_VERIFY_OFFSET     (FLASH_DRIVER_HEADER_OFFSET + 0x10)

/* Defines to access version and type information */
# define FLASH_DRIVER_MCUTYPE(flashCode)      (*(unsigned char*)(flashCode+FLASH_DRIVER_HEADER_OFFSET-1))
# define FLASH_DRIVER_MASKTYPE(flashCode)     (*(unsigned char*)(flashCode+FLASH_DRIVER_HEADER_OFFSET-2))
# define FLASH_DRIVER_INTERFACE(flashCode)    (*(unsigned char*)(flashCode+FLASH_DRIVER_HEADER_OFFSET-4))


/* Minimum number of bytes that has to be programmed at a time */
/*256 byte aligned for RH850_F1L Flash writting*/
# define FLASH_SEGMENT_SIZE      0x100

/* Minimum number of bytes that has to be erased at a time */
# define FLASH_MIN_ERASE_SIZE  0x2000

/* If flash code is relocatable, set this define                           */
# define FLASHCODE_NOT_RELOCATABLE

/* Value which can be read from flash when it is deleted. */
# define FBL_FLASH_DELETED   0xffu
/********************************************************************/
/* Error codes                                                      */
/********************************************************************/
/*-- Routine specific error groups ---------------------------------*/
# define kFlashFctInit         0x00
# define kFlashFctDeinit       0x20
# define kFlashFctErase        0x40
# define kFlashFctWrite        0x60
# define kFlashFctUsrFct       0x80

/*-- Common error codes --------------------------------------------*/
# define kFlashOk              0x00   /* Function call successful    */
# define kFlashFailed          0x01   /* Function call failed        */
# define kFlashVerify          0x02   /* Verify error                */
# define kFlashInvalidParam    0x03   /* Invalid parameter           */
# define kFlashInvalidAddress  0x04   /* Invalid flash address       */
# define kFlashInvalidSize     0x05   /* Invalid flash size          */
# define kFlashInvalidClock    0x06   /* Missing/wrong clock supply  */
# define kFlashProtect         0x07   /* Protection error            */
# define kFlashAcc             0x08   /* Access error                */
# define kFlashCmdBufFull      0x09   /* Command buffer not empty    */
# define kFlashInvalidVersion  0x0A   /* Invalid version             */


/*-- Flash init error codes ----------------------------------------*/
# define kFlashInitFailed          (kFlashFctInit | kFlashFailed)
# define kFlashInitInvalidParam    (kFlashFctInit | kFlashInvalidParam)
# define kFlashInitInvalidAddr     (kFlashFctInit | kFlashInvalidAddress)
# define kFlashInitInvalidSize     (kFlashFctInit | kFlashInvalidSize)
# define kFlashInitInvalidClock    (kFlashFctInit | kFlashInvalidClock)
# define kFlashInitInvalidVersion  (kFlashFctInit | kFlashInvalidVersion)

/*-- Flash deinit error codes --------------------------------------*/
# define kFlashDeinitFailed        (kFlashFctDeinit | kFlashFailed)
# define kFlashDeinitInvalidParam  (kFlashFctDeinit | kFlashInvalidParam)

/*-- Flash erase error codes ---------------------------------------*/
# define kFlashEraseFailed         (kFlashFctErase | kFlashFailed)
# define kFlashEraseInvalidParam   (kFlashFctErase | kFlashInvalidParam)
# define kFlashEraseInvalidAddr    (kFlashFctErase | kFlashInvalidAddress)
# define kFlashEraseInvalidSize    (kFlashFctErase | kFlashInvalidSize)
# define kFlashEraseProtect        (kFlashFctErase | kFlashProtect)

/*-- Flash write error codes ---------------------------------------*/
# define kFlashWriteFailed         (kFlashFctWrite | kFlashFailed)
# define kFlashWriteVerify         (kFlashFctWrite | kFlashVerify)
# define kFlashWriteInvalidParam   (kFlashFctWrite | kFlashInvalidParam)
# define kFlashWriteInvalidAddr    (kFlashFctWrite | kFlashInvalidAddress)
# define kFlashWriteInvalidSize    (kFlashFctWrite | kFlashInvalidSize)
# define kFlashWriteProtect        (kFlashFctWrite | kFlashProtect)
    
/* Types *********************************************************************/
typedef unsigned char  tFlashData;  
typedef unsigned long  tFlashAddress;
typedef unsigned long  tFlashLength;
typedef unsigned short tFlashErrorCode;

/* Flasher structure */
typedef struct
{
   /* Version information */
   unsigned char     patchLevel;       /* Patchlevel                         */
   unsigned char     minorVersion;     /* Minor version number               */
   unsigned char     majorVersion;     /* Major version number               */
   unsigned char     reserved1;        /* Reserved for future use            */
           
   /* Return value/error code */
   tFlashErrorCode   errorCode;        /* Return value/error code            */
   unsigned short    reserved2;        /* Reserved for future use            */

   /* Erase/write input parameters */
   tFlashAddress     address;          /* Logical target address             */
   tFlashLength      length;           /* Length (in bytes)                  */
   tFlashData*       data;             /* Pointer to data buffer (read only) */

   /* Pointer to watchdog trigger function */
   unsigned char     (* wdTriggerFct)(void);

   /* Erase/write output parameters */
   tFlashData        intendedData[2];  /* Intended data at error address     */
   tFlashData        actualData[2];    /* Actual data at error address       */
   tFlashAddress     errorAddress;     /* Error address                      */
}tFlashParam;

/********************************************************************/
/* Function call macros                                             */
/********************************************************************/

/* Pointer to flash functions */
typedef void (* tFlashFct)( tFlashParam *flashParam ); 

/* Flash write function --------------------------------------------*/
# define FLASH_DRIVER_WRITE(flashCode, flashParam)\
   ((tFlashFct)(*(unsigned long *)&flashCode[FLASH_DRIVER_WRITE_OFFSET]))(flashParam)

/* Flash erase function --------------------------------------------*/
# define FLASH_DRIVER_ERASE(flashCode, flashParam)\
   ((tFlashFct)(*(unsigned long *)&flashCode[FLASH_DRIVER_ERASE_OFFSET]))(flashParam)

/* Flash init function ---------------------------------------------*/
# define FLASH_DRIVER_INIT(flashCode, flashParam)\
   ((tFlashFct)(*(unsigned long *)&flashCode[FLASH_DRIVER_INIT_OFFSET]))(flashParam)

/* Flash deinitialization function ---------------------------------*/
# define FLASH_DRIVER_DEINIT(flashCode,flashParam)\
   ((tFlashFct)(*(unsigned long *)&flashCode[FLASH_DRIVER_DEINIT_OFFSET]))(flashParam)

/* Flash verification function -------------------------------------*/
# define FLASH_DRIVER_VERIFY(flashCode,flashParam)\
   ((tFlashFct)(*(unsigned long *)&flashCode[FLASH_DRIVER_VERIFY_OFFSET]))(flashParam)
#endif /* FBLDRVFLASH_RH850_F1X_H */
/************   Organi, Version 3.6.5 Vector-Informatik GmbH  ************/
