/*****************************************************************************
| Project Name: Security Module
|    File Name: SecMCrc.c
|
|  Description: Implementation of CRC32 component of the security module
|               
|
|-----------------------------------------------------------------------------
|               C O P Y R I G H T
|-----------------------------------------------------------------------------
| Copyright (c) 2006-2011 by Vector Informatik GmbH, all rights reserved.
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
| Initials      Name                   Company
| --------      --------------------   ---------------------------------------
| Cb            Christian Baeuerle     Vector Informatik GmbH
| Hp            Armin Happel           Vector Informatik GmbH
| FHe           Florian Hees           Vector Informatik GmbH
| JHg           Joern Herwig           Vector Informatik GmbH
|
|-----------------------------------------------------------------------------
|               R E V I S I O N   H I S T O R Y
|-----------------------------------------------------------------------------
| Date        Version   Author  Description
| ----------  --------  ------  ----------------------------------------------
| 2009-09-07  02.00.00  FHe      ESCAN00037604: New SecMod 2 branch
|*****************************************************************************/

/* Includes ******************************************************************/

/* Security module configuration settings */
#include "SecM_inc.h"

/* Global definitions for security module */
#include "SecM_def.h"

/* CRC32 interfaces */
#include "SecMCrc.h"

/* --- Version --- */
#if (SECM_CRC_VERSION != 0x0200)
# error "Error in SecMVer.c: Source and Header file are inconsistent!"
#endif
#if (SECM_CRC_RELEASE_VERSION != 0x00)
# error "Error in SecMVer.c: Source and Header file are inconsistent!"
#endif
 
/* Defines *******************************************************************/

#if (SEC_CRC_OPT == SEC_CRC_SPEED_OPTIMIZED)
/* Eight bits are used as table index */
# define CRC_INDEX_BITS 8
# define CRC_INDEX_MASK 0x000000FFul
# define CRC_TABLE_SIZE 256
#endif

#if (SEC_CRC_OPT == SEC_CRC_SIZE_OPTIMIZED)
/* Four bits are used as table index */
# define CRC_INDEX_BITS 4
# define CRC_INDEX_MASK 0x0Fu
# define CRC_TABLE_SIZE 16
#endif

/* "Reflected" CRC32 polynomial. This value can be found in literature
 * in reverse bit order: 0x04C11DB7                                     */
#define SEC_CRC32_POLYNOMIAL  0x04C11DB7

/* Typedefs ******************************************************************/



/* Local data ****************************************************************/

#if (SEC_CRC_OPT == SEC_CRC_SIZE_OPTIMIZED)
/* CRC calculation table based on 4-bit algorithm */
static MEMORY_ROM SecM_CRCType crc32Table[]=
{
   0x00000000,
   0x1DB71064,
   0x3b6e20C8,
   0x26D930AC,
   0x76DC4190,
   0x6B6B51F4,
   0x4DB26158,
   0x5005713C,
   0xEDB88320,
   0xF00F9344,
   0xD6D6A3E8,
   0xCB61B38C,
   0x9B64C2B0,
   0x86D3D2d4,
   0xA00AE278,
   0xBDBDF21C
};
#endif

#if (SEC_CRC_OPT == SEC_CRC_SPEED_OPTIMIZED)
/* For speed optimization, the CRC table is dynamically generated in RAM */
static SecM_CRCType crc32Table[CRC_TABLE_SIZE];
#endif

/* Implementation ************************************************************/

/******************************************************************************
* Name         :  CrcGenerate256Table 
* Called by    :  SecM_ComputeCRC()
* Preconditions:  None
* Parameters   :  None
* Return code  :  None
* Description  :  Generates the CRC32 lookup table
*                 
******************************************************************************/
void CrcGenerate256Table(void)
{
#if (SEC_CRC_OPT == SEC_CRC_SPEED_OPTIMIZED)
   /* Create CRC32 table in RAM -> reflected */
   vuint16  tableIdx;
   vuint8   bitIdx;
   SecM_CRCType crc;

   for (tableIdx = 0; tableIdx < CRC_TABLE_SIZE; tableIdx++)
   {
      crc = tableIdx;
      for (bitIdx = 0; bitIdx < CRC_INDEX_BITS; bitIdx++)
      {
         if ((crc & 0x01u) == 0x01u)
         {
            crc >>= 1;
            crc ^= SEC_CRC32_POLYNOMIAL;
         }
         else
         {
            crc >>= 1;
         }
      }
      crc32Table[tableIdx] = crc;
   }
#endif
}


/******************************************************************************
* Name         :  CrcUpdateCrc()
* Called by    :  SecM_ComputeCRC()
* Preconditions:  None
* Parameters   :  byteCount   : Number of bytes to process
*                 *data       : Pointer to source data buffer  
*                 *currentCrc : Pointer to current CRC value
*
* Return code  :  None
* Description  :  Computes the CRC32 upon the given data buffer.
*                 
******************************************************************************/
void CrcUpdateCrc (SecM_LengthType byteCount, vuint8 *data, SecM_CRCType *currentCrc, FL_WDTriggerFctType wdTriggerFct)
{
   vuint16           tableIndex;       /* Index for crc32Table access */
   SecM_LengthType   sourceIdx;        /* Index for source data buffer */
   
#if (SEC_CRC_OPT == SEC_CRC_SIZE_OPTIMIZED)   
   SecM_CRCType      tmpCrc;
   vuint8            tmpData;
#endif   

   for (sourceIdx = 0; sourceIdx < byteCount; sourceIdx++)
   {
      /* Call watchdog trigger function */
      (void)wdTriggerFct();
      
      tableIndex = (vuint16)((data[sourceIdx] ^ *currentCrc) & CRC_INDEX_MASK);
#if (SEC_CRC_OPT == SEC_CRC_SPEED_OPTIMIZED)
      *currentCrc = ((*currentCrc) >> CRC_INDEX_BITS) ^ crc32Table[tableIndex];
#endif

#if (SEC_CRC_OPT == SEC_CRC_SIZE_OPTIMIZED)
      /* Calculate CRC32 with small table in ROM*/
      tmpCrc = ((*currentCrc) >> CRC_INDEX_BITS) ^ crc32Table[tableIndex];

      /* High nibble */
      tmpData = data[sourceIdx] >> CRC_INDEX_BITS;
      tableIndex = (vuint16)(tmpData ^ tmpCrc) & CRC_INDEX_MASK;
      *currentCrc = (tmpCrc >> CRC_INDEX_BITS) ^ crc32Table[tableIndex];
#endif      
   }
}


/******************************************************************************
* Name         :  SecM_ComputeCRC
* Called by    :  SecM_Verification and Application
* Preconditions:  None
* Parameters   :  *crcParam   : Pointer to parameter structure
*
* Return code  :  Status of CRC32 computation
* Description  :  Function that manages the state of CRC32 computation
*                 
******************************************************************************/
SecM_StatusType SecM_ComputeCRC( SecM_CRCParamType *crcParam )
{
   SecM_StatusType result;   

   switch(crcParam->crcState)
   {
      case SECM_CRC_INIT:
         crcParam->currentCRC = 0xFFFFFFFF;
         result = SECM_OK;
         break;
         
      case SECM_CRC_COMPUTE:
         CrcUpdateCrc (crcParam->crcByteCount, crcParam->crcSourceBuffer, &(crcParam->currentCRC), crcParam->wdTriggerFct);
         result = SECM_OK;
         break;
         
      case SECM_CRC_FINALIZE:
         /* Complement CRC value */     
         crcParam->currentCRC = ~crcParam->currentCRC;    
         result = SECM_OK;
         break;
         
      default:
         result = SECM_NOT_OK;
         break;
   }
   return result;
}


/******************************************************************************
*******************************************************************************/
