/*****************************************************************************
| Project Name: Security Module
|    File Name: SecM.c
|
|  Description: Implementation of the security module
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
|
|-----------------------------------------------------------------------------
|               R E V I S I O N   H I S T O R Y
|-----------------------------------------------------------------------------
| Date        Version   Author  Description
| ----------  --------  ------  ----------------------------------------------
| 2009-09-07  02.00.00 FHe      ESCAN00037604: New SecMod 2 branch
| 2011-06-10  02.01.00 Ach      ESCAN00051583: No changes
|*****************************************************************************/

/* Includes ******************************************************************/

/* Security module configuration settings */
#include "SecM_inc.h"

/* Global definitions for security module */
#include "SecM_def.h"

#include "SecM.h"

/* --- Version check --- */
#if ( FBLSECMOD_VECTOR_VERSION != 0x0201u ) || \
    ( FBLSECMOD_VECTOR_RELEASE_VERSION != 0x00u )
# error "Error in SecM.c: Source and header file are inconsistent!"
#endif

/* Prototypes ****************************************************************/
void SecM_StateTask(void);
void SecM_TimerTask(void);

/******************************************************************************
* Name         :  SecM_InitPowerOn
* Called by    :  
* Preconditions:  None
* Parameters   :  None
* Return code  :  SECM_OK if initialization successful, SECM_NOT_OK otherwise
* Description  :  
*                 
******************************************************************************/
SecM_StatusType SecM_InitPowerOn( SecM_InitType initParam  )
{
   /* Avoid compiler warnings */
   initParam = initParam;

   return SECM_OK;
}

/******************************************************************************
* Name         :  SecM_Task
* Called by    :  
* Preconditions:  None
* Parameters   :  None
* Return code  :  None
* Description  :  
*                 
******************************************************************************/
void SecM_Task(void)
{
   SecM_TimerTask();
   SecM_StateTask();
}

/******************************************************************************
* Name         :  SecM_StateTask
* Called by    :  
* Preconditions:  None
* Parameters   :  None
* Return code  :  None
* Description  :  
*                 
******************************************************************************/
void SecM_StateTask(void)
{

}



/******************************************************************************
* Name         :  SecM_TimerTask
* Called by    :  
* Preconditions:  None
* Parameters   :  None
* Return code  :  None
* Description  :  
*                 
******************************************************************************/
void SecM_TimerTask(void)
{
}

/******************************************************************************
*******************************************************************************/

