/*****************************************************************************
| Project Name: Security Module
|    File Name: SecMCrc.h
|
|  Description: Interfaces of CRC component of the security module
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

#ifndef __SECM_CRC_H_
#define __SECM_CRC_H_

#ifdef  __cplusplus
extern "C" {
#endif

/* --- Version --- */
/* ##V_CFG_MANAGEMENT ##CQProject : SecMCrc CQComponent : Implementation */
#define SECM_CRC_VERSION           0x0200
#define SECM_CRC_RELEASE_VERSION   0x00

/* Includes ******************************************************************/

/* Defines *******************************************************************/

/* Defines from SecM214 (V1.1) */
#define kCRCInit          ((vuint8) 0x01u)
#define kCRCCompute       ((vuint8) 0x02u)
#define kCRCFinalize      ((vuint8) 0x04u)

/* CRC32 internal states */
#define SECM_CRC_INIT     kCRCInit
#define SECM_CRC_COMPUTE  kCRCCompute
#define SECM_CRC_FINALIZE kCRCFinalize

/* Typedefs ******************************************************************/

/* Type for CRC value */
typedef SecM_WordType SecM_CRCType;


/* Parameter structure for CRC computation */
typedef struct tagSecM_CRCParamType
{
   SecM_CRCType      currentCRC;         /* Current CRC-value                 */
   vuint8            crcState;           /* State value for CRC computation   */
   
   /* The following values have to be initialized by application:             */
   vuint8           *crcSourceBuffer;    /* Pointer to source data            */
   SecM_LengthType   crcByteCount;       /* Number of bytes in source buffer  */

   /* Pointer to watchdog trigger function */
   FL_WDTriggerFctType  wdTriggerFct;    /* ## */
} SecM_CRCParamType;

/* Pointer types for API-functions */
typedef SecM_StatusType SECM_CALL_TYPE (*pSecComputeCRCFct) (SecM_CRCParamType *crcParam);

/* Prototypes (API of CRC32 Component) ****************************************/
SecM_StatusType   SecM_ComputeCRC( SecM_CRCParamType *crcParam );
void              CrcGenerate256Table(void);
/* Internal prototypes */


/* Configuration check ********************************************************/

#if !defined(SEC_CRC_OPT)
#error "Error in SecM_cfg.h: SEC_CRC_OPT not defined"
#endif
#if ((SEC_CRC_OPT != SEC_CRC_SPEED_OPTIMIZED) && (SEC_CRC_OPT != SEC_CRC_SIZE_OPTIMIZED))
# error "Error in SecM_cfg.h: Either SEC_CRC_SPEED_OPTIMIZED or SEC_CRC_SIZE_OPTIMIZED must be defined"
#endif

#ifdef  __cplusplus
}
#endif

#endif
/******************************************************************************
*******************************************************************************/
