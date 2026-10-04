/*****************************************************************************
| Project Name: Security Module
|    File Name: SecM.h
|
|  Description: Interfaces of the security module
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
| Rr            Robert Schaeffner      Vector Informatik GmbH
| Ach           Achim Strobelt         Vector Informatik GmbH
|-----------------------------------------------------------------------------
|               R E V I S I O N   H I S T O R Y
|-----------------------------------------------------------------------------
| Date        Version   Author  Description
| ----------  --------  ------  ----------------------------------------------
| 2009-09-07  02.00.00  FHe      ESCAN00037604: New SecMod 2 branch
| 2011-06-10  02.01.00  Ach      ESCAN00051583: Add compatiblity defines
|*****************************************************************************/
#ifndef __SECM_H_
#define __SECM_H_

#ifdef  __cplusplus
extern "C" {
#endif

/* --- Version --- */
/* ##V_CFG_MANAGEMENT ##CQProject : FblSecMod_Vector CQComponent : Implementation */
# define FBLSECMOD_VECTOR_VERSION                    0x0201u
# define FBLSECMOD_VECTOR_RELEASE_VERSION            0x00u

# define SECM_HIS_SECURITY_MODULE_VERSION             0x010001u

/* Includes ******************************************************************/

/* Security module configuration settings */
#include "SecM_inc.h"

/* Global definitions for security module */
#include "SecM_def.h"

/* Seed-Key interfaces */
#include "SecMSK.h"

/* CRC32 interfaces */
#include "SecMCrc.h"


/* Verification interface */
#include "SecMVer.h"

/* Defines *******************************************************************/
#define  SecM_StartKeyTimer()
#define  SecM_StopKeyTimer()
#define  SecM_GetKeyTimer()        (1)
#define  SecM_DecrKeyTimer()

/* Typedefs ******************************************************************/
typedef void* SecM_InitType;

/* Pointer types for function calls from external application */
typedef void       SECM_CALL_TYPE (*pSecTaskFct) (void);

/* Prototypes ****************************************************************/
extern SecM_StatusType SecM_InitPowerOn( SecM_InitType initParam);
extern void SecM_Task( void );

#ifdef  __cplusplus
}
#endif

#endif
/******************************************************************************
*******************************************************************************/
