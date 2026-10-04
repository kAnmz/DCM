/**********************************************************************************************************************
* File Name     : $Source: fcl_user.c $
* Mod. Revision : $Revision: 1.6 $
* Mod. Date     : $Date: 2015/11/09 09:34:14MEZ $
* Device(s)     : RV40 Flash based RH850 microcontroller
* Description   : Sample application functions to prepare Self-Programming
**********************************************************************************************************************/

/**********************************************************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only  intended for use with
* Renesas products. No other uses are authorized. This software is owned by Renesas Electronics
* Corporation and is protected under all applicable laws, including copyright laws.
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING THIS SOFTWARE,
* WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.
* TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR
* ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR
* CONSEQUENTIAL DAMAGES FOR ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE
* BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software and to discontinue the
* availability of this software. By using this software, you agree to the additional terms and conditions
* found by accessing the  following link:
* http://www.renesas.com/disclaimer
*
* Copyright (C) 2015 Renesas Electronics Corporation. All rights reserved.
**********************************************************************************************************************/

#ifdef ENABLE_QAC_TEST
    #pragma PRQA_MESSAGES_ON 0292
#endif

/**********************************************************************************************************************
* MISRA Rule:   MISRA-C 2004 rule 3.1 (QAC message 0292)
* Reason:       To support automatic insertion of revision, module name etc. by the source
*               revision control system it is necessary to violate the rule, because the
*               system uses non basic characters as placeholders.
* Verification: The placeholders are used in commentars only. Therefore rule violation cannot
*               influency code compilation.
**********************************************************************************************************************/
#include "cy_device_headers.h"
#include "cy_flash.h"
#include "cy_mw_flash.h"


//extern void Cy_FlashWriteCode(ulong writeAddr, const ulong* data, ulong size, ulong blocking);
extern void Cy_FlashWriteCode(uint32_t writeAddr, const uint32_t* data, cy_en_flash_programrow_datasize_t size, cy_en_flash_driver_blocking_t blocking);
extern void Cy_FlashSectorErase(uint32_t sectorAddr, cy_en_flash_driver_blocking_t blocking);
extern en_flash_bounds_t Cy_Flash_MainBoundsCheck(uint32_t address);
extern void Cy_FlashInit(bool non_blocking);
void Flash_DRV_RAM_Init(void);
#if 1
//int __ramVectors[20];
//#define __ramVectors    Fcl_AsmArray
uint32_t cy_delay32kMs;
uint32_t SystemCoreClock  = 0UL;

uint32_t CPUS_delayFreqHz   = 0UL;

uint32_t cy_delayFreqKhz  = 0UL;

uint8_t cy_delayFreqMhz   = 0UL;

uint32_t cy_delay32kMs    = 0UL;

//int __Vectors[];

 const cy_israddress __Vectors[]; /**< Vector table in Flash */
  cy_israddress __ramVectors[]; /**< Relocated vector table in SRAM */
#endif
/* Flash Driver hardware information */
# define FLASH_DRIVER_VERSION_MCUTYPE   0x85
# define FLASH_DRIVER_VERSION_MASKTYPE  0x09
# define FLASH_DRIVER_VERSION_INTERFACE 0x03

typedef void(* tFlashFct) ( uint32_t writeAddr, const uint32_t* data, cy_en_flash_programrow_datasize_t size, cy_en_flash_driver_blocking_t blocking );
typedef en_flash_bounds_t(* tFlashCheckFct) (uint32_t address);
typedef void(* tFlashEraseFct) (uint32_t sectorAddr, cy_en_flash_driver_blocking_t blocking);
typedef void (* tFlashInit)(bool non_blocking);
typedef cy_en_flashdrv_status_t (* tFlashGetDrvStatusFct)(cy_un_flash_context_t *context);
typedef void (* tFlashDRVRAMInitFct)(void);

/* Flash header structure */
typedef struct
{
  /* Definition of the 4-byte flash algorithm header */
  unsigned char version;
  unsigned char reserved;
  unsigned char maskType;
  unsigned char CPUType;
  tFlashCheckFct flashMainBoundsCheck;
  tFlashEraseFct flashEraseFct;
  tFlashFct flashWriteFct;
  tFlashInit flashInit;
  tFlashGetDrvStatusFct flashInitGetDrvStatusFct;
  tFlashDRVRAMInitFct FlashDRVRAMInitFct;
}tFlashHeader;

#define flashCode __ghsbegin_flashdriver
extern uint8_t            flashCode[];  /* Address of flash algorithms in RAM */
extern char __ghsbegin_data[], __ghsend_data[] ,__ghsbegin_ROM_data[];
# pragma ghs section rodata=".flashdriver"
/* Header which includes the flash driver interface for the flio. */
/* This code will be placed into the section .signatur.const      */
const tFlashHeader flashHeader=
{
   FLASH_DRIVER_VERSION_INTERFACE
  ,0x00
  ,FLASH_DRIVER_VERSION_MASKTYPE
  ,FLASH_DRIVER_VERSION_MCUTYPE
  ,&Cy_Flash_MainBoundsCheck
  ,&Cy_FlashSectorErase
  ,&Cy_FlashWriteCode
  ,&Cy_FlashInit
  ,&Cy_Flash_GetDrvStatus
  ,&Flash_DRV_RAM_Init
};

/* Flash write function --------------------------------------------*/
# define FLASH_DRIVER_WRITE(flashCode, flashParam)\
   ((tFlashFct)(*(unsigned long *)&flashCode[12]))(flashParam)

/* Flash erase function --------------------------------------------*/
# define FLASH_DRIVER_ERASE(flashCode, flashParam)\
   ((tFlashEraseFct)(*(unsigned long *)&flashCode[8]))(flashParam)

/* Flash Bound Check ---------------------------------------------*/
# define FLASH_DRIVER_BOUNDSCHECK(flashCode, flashParam)\
   ((tFlashCheckFct)(*(unsigned long *)&flashCode[FLASH_DRIVER_INIT_OFFSET]))(flashParam)





/*ushort *APPVectorPtr = (ushort __far*)0x6800;
(*((void(*)(void))(*APPVectorPtr)))(); *///JumpApp  JSR(x)

/**********************************************************************************************************************
Includes   <System Includes> , "Project Includes"
**********************************************************************************************************************/

#ifdef __RH850_F1x__
#include "r_fcl_types.h"
#include "r_typedefs.h"
#ifdef __RH850_F1L__
#include "f1x.dvf.h"
#endif

#ifdef __RH850_F1K__
  #if defined (__RH850_R7F701587__)
    #include "dr7f701587.dvf.h"
  #elif defined (__RH850_R7F701583__)
    #include "dr7f701583.dvf.h"
  #elif defined (__RH850_R7F701603__)
    #include "dr7f701603.dvf.h"
  #else
    #error "CPU Type must be defined"
  #endif
#endif


#define FLMD0_PROTECTION_OFF    (0x01u)
#define FLMD0_PROTECTION_ON     (0x00u)

#define FCL_INIT_FLASHACCESS                                        \
            volatile uint32_t i;                                    \
                                                                    \
            /* enable FLMD0 */                                      \
            FLMDPCMD = 0xa5;                                        \
            FLMDCNT  = FLMD0_PROTECTION_OFF;                        \
            FLMDCNT  = ~FLMD0_PROTECTION_OFF;                       \
            FLMDCNT  = FLMD0_PROTECTION_OFF;                        \
            for (i=0; i<10000; i++)                                 \
            {                                                       \
                /* do nothing ... delay time may depend on */       \
                /* external FLMD0 pin connection */                 \
            }

#define FCL_DISABLE_FLASHACCESS                                     \
            volatile uint32_t i;                                    \
                                                                    \
            /* enable FLMD0 */                                      \
            FLMDPCMD = 0xa5;                                        \
            FLMDCNT  = FLMD0_PROTECTION_ON;                         \
            FLMDCNT  = ~FLMD0_PROTECTION_ON;                        \
            FLMDCNT  = FLMD0_PROTECTION_ON;                         \
            for (i=0; i<10000; i++)                                 \
            {                                                       \
                /* do nothing ... delay time may depend on */       \
                /* external FLMD0 pin connection */                 \
            }

/************************************************************************************************************
 * Function name: FCLUser_Open
 ***********************************************************************************************************/
/**
 * Prepare Flash programming hardware for Flash modification operations
 *
 * @param         ---
 * @return        ---
 */
/***********************************************************************************************************/
#if   R_FCL_COMPILER == R_FCL_COMP_GHS
  #pragma ghs section text =".R_FCL_CODE_USR"
#elif R_FCL_COMPILER == R_FCL_COMP_IAR
  #pragma location = "R_FCL_CODE_USR"
#elif R_FCL_COMPILER == R_FCL_COMP_REC
  #pragma section text "R_FCL_CODE_USR"
#endif
void FCLUser_Open (void)
{
    FCL_INIT_FLASHACCESS
}

/************************************************************************************************************
 * Function name: FCLUser_Close
 ***********************************************************************************************************/
/**
 * Prepare Flash programming hardware for Flash modification operations
 *
 * @param         ---
 * @return        ---
 */
/***********************************************************************************************************/
#if   R_FCL_COMPILER == R_FCL_COMP_GHS
  #pragma ghs section text =".R_FCL_CODE_USR"
#elif R_FCL_COMPILER == R_FCL_COMP_IAR
  #pragma location = "R_FCL_CODE_USR"
#elif R_FCL_COMPILER == R_FCL_COMP_REC
  #pragma section text "R_FCL_CODE_USR"
#endif
void FCLUser_Close (void)
{
    FCL_DISABLE_FLASHACCESS
}

#endif
void Flash_DRV_RAM_Init(void)
{
  volatile uint32_t *memPtr;
	volatile uint32_t *romPtr; 
	volatile uint32_t *memEndPtr;
	uint32_t Fblm_FLASHDRVRamStartAddress = (uint32_t)__ghsbegin_data;
	uint32_t Fblm_FLASHDRVRamEndAddress = (uint32_t)__ghsend_data;
	uint32_t Fblm_FLASHDRVRomStartAddress = (uint32_t)__ghsbegin_ROM_data;
	if(((Fblm_FLASHDRVRamEndAddress - Fblm_FLASHDRVRamStartAddress) > 0))
	{
		memPtr = (volatile uint32_t*)Fblm_FLASHDRVRamStartAddress;
		romPtr = (volatile uint32_t*)Fblm_FLASHDRVRomStartAddress;
		memEndPtr = (volatile uint32_t*)Fblm_FLASHDRVRamEndAddress;
		while ((uint32_t)memPtr < (uint32_t)memEndPtr)
		{
			*memPtr = *romPtr; 
			memPtr++;
			romPtr++;
		}
	}
}
