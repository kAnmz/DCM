/****************************************************************************
 ** Main author: Sst                     Creation date: 04/20/06
 ** $Author:: Sst                      $ $JustDate:: 04/20/06             $
 ** $Workfile:: SecMDec.c              $ $Revision::    1                 $
 ** $NoKeywords::                                                         $
 **
 **
 ** \copyright(cv cryptovision GmbH, 1999 - 2006                          )
 **
 ** \version(1.0                                                          )
 ***************************************************************************/

/****************************************************************************
 **
 **     Part of the HIS security module
 **
 **     Layer: User interface level
 **
 ***************************************************************************/

/****************************************************************************
 **
 ** This file contains: Implementation of the decryption component 
 **                     of the HIS security module
 **
 ** constants:
 **
 ** types:
 **
 ** global variables:
 **
 ** macros:
 **
 ** functions:
 **   SecM_InitDecryption
 **   SecM_DeinitDecryption
 **   SecM_Decryption
 **
 ***************************************************************************/


/* Security module configuration settings */
#include "SecM_inc.h"

/* Global definitions for security module */
#include "SecM_def.h"

/* CRC32 interfaces */
#include "SecMCrc.h"

/* Verification interface */
#include "SecMDec.h"

/* Key data */
#include "SecMPar.h"



/* Local data ****************************************************************/


/* Implementation ************************************************************/


/****************************************************************************
 **
 ** FUNCTION:
 ** SecM_StatusType SecM_InitDecryption( SecM_DecInitType init )
 **                           
 **  This function deintializes the decryption.
 **
 ** input:
 ** - init:       
 **
 ** output:
 ** None
 **
 ** assumes:
 ** 
 **
 ** uses:
 **
 ***************************************************************************/


SecM_StatusType SecM_InitDecryption( SecM_DecInitType init )
{

   /* Avoid compiler warnings */
   init = init;
   return SECM_OK;

}

/****************************************************************************
 **
 ** FUNCTION:
 ** SecM_StatusType SecM_DeinitDecryption( SecM_DecDeinitType deinit )
 **                           
 **  This function deintializes the decryption.
 **
 ** input:
 ** - deinit:       
 **
 ** output:
 ** None
 **
 ** assumes:
 ** 
 **
 ** uses:
 **
 ***************************************************************************/

SecM_StatusType SecM_DeinitDecryption( SecM_DecDeinitType deinit )
{
   /* Avoid compiler warnings */
   deinit = deinit;
   return SECM_OK;
}


/****************************************************************************
 **
 ** FUNCTION:
 ** SecM_StatusType SecM_Decryption( SecM_DecInputParamType *inBlock, 
 **    SecM_DecOutputParamType *outBlock, SecM_DecParamType *decParam )
 **                           
 **  This function performs the decryption..
 **
 ** input:
 **             inBlock  : Input parameter structure 
 **             outBlock : Ouptut parameter sturcture
 **             decParam : Decryption parameters      
 **
 ** output:
 **             tbd.
 **
 ** assumes:
 ** 
 **
 ** uses:
 **
 ***************************************************************************/

SecM_StatusType SecM_Decryption( SecM_DecInputParamType *inBlock, 
     SecM_DecOutputParamType *outBlock, SecM_DecParamType *decParam )
{
   return SECM_OK;
}


