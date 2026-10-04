/*****************************************************************************
| Project Name: Security Module
|    File Name: SecMSK.h
|
|  Description: Interfaces of seed-key component of the security module
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
| JHg           Joern Herwig           Vector Informatik GmbH
| Rr            Robert Schaeffner      Vector Informatik GmbH
| FHe           Florian Hees           Vector Informatik GmbH
|
|-----------------------------------------------------------------------------
|               R E V I S I O N   H I S T O R Y
|-----------------------------------------------------------------------------
| Date        Version   Author  Description
| ----------  --------  ------  ----------------------------------------------
| 2006-02-16  01.00.00  Cb       Initial implementation
| 2006-07-03  01.01.00  Hp       Revision for specification compatibility.
| 2008-05-07  01.02.00  JHg      No changes
| 2008-09-19  01.03.00  JHg      Changed seed and key types for use with RSA
|                                 Support arbitary length (not limited to 4 byte)
|                       Rr       No changes
| 2009-09-10  01.04.00  FHe      ESCAN00034892: Wrong pointer for compute key function
|                       JHg      ESCAN00037018: Changed default seed length for use with RSA
| 2009-09-21  01.05.00  JHg      ESCAN00037921: No changes
| 2010-03-01  01.06.00  JHg      ESCAN00039522: No changes
|*****************************************************************************/
#ifndef __SECM_SEEDKEY_H_
#define __SECM_SEEDKEY_H_

#ifdef  __cplusplus
extern "C" {
#endif

#include "fbl_cfg.h"
#include "SecM.h"


/* --- Version --- */
/* ##V_CFG_MANAGEMENT ##CQProject : SecMSK CQComponent : Implementation */
#define SECM_SK_VERSION           0x0106
#define SECM_SK_RELEASE_VERSION   0x00

/* Includes ******************************************************************/

/* Defines *******************************************************************/

/* Typedefs ******************************************************************/
typedef struct tagSecM_SeedType
{
   SecM_WordType seedX;
   SecM_WordType seedY;
}SecM_SeedType;

typedef SecM_WordType SecM_KeyType;

/* Pointer types for API-functions */
typedef SecM_StatusType SECM_CALL_TYPE (*pSecGenerateSeedFct) (SecM_SeedType *seed);
typedef SecM_StatusType SECM_CALL_TYPE (*pSecComputeKeyFct) (SecM_SeedType seed, SecM_WordType k, SecM_KeyType *key);
#if (SECM_HIS_SECURITY_MODULE_VERSION < 0x010002u)
typedef SecM_StatusType SECM_CALL_TYPE (*pSecCompareKeyFct) (SecM_KeyType key);
#else
typedef SecM_StatusType SECM_CALL_TYPE (*pSecCompareKeyFct) (SecM_KeyType key, SecM_SeedType seed );
#endif


/* Prototypes (API of Seed-Key Component) ************************************/
extern void SecM_InitSeedKey(void);
extern vuint32 SecM_GetRandom(void);
extern SecM_StatusType SecM_GenerateSeed( SecM_SeedType *seed );
extern SecM_StatusType SecM_ComputeKey( SecM_SeedType seed, SecM_WordType k, SecM_KeyType *key );
#if (SECM_HIS_SECURITY_MODULE_VERSION < 0x010002u)
extern SecM_StatusType SecM_CompareKey( SecM_KeyType key );
#else
extern SecM_StatusType SecM_CompareKey( SecM_KeyType key, SecM_SeedType seed );
#endif

#ifdef  __cplusplus
}
#endif

#endif
/******************************************************************************
*******************************************************************************/
