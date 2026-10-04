/****************************************************************************
 ** Main author: Sst                     Creation date: 04/24/06
 ** $Author::                          $ $JustDate:: 04/24/06             $
 ** $Workfile:: SecMDec.h              $ $Revision:: 1                    $
 ** $NoKeywords::                                                         $
 **
 **
 ** \copyright(cv cryptovision GmbH, 1999 - 2006                          )
 **
 ** \version(1.0 (     )                                                  )
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
 **   SIZE_OF_AES_IV
 **
 ** types:
 **   SecM_DecInitType
 **   SecM_DecDeinitType
 **   SecM_DecInputParamType
 **   SecM_DecOutputParamType
 **   SecM_DecParamType
 **   pSecInitDecryptionFct
 **   pSecInitDecryptionFct
 **   pSecDeinitDecryptionFct
 **   pSecDecryptionFct
 **
 ** functions:
 **   SecM_InitDecryption
 **   SecM_DeinitDecryption
 **   SecM_Decryption
 **
 ***************************************************************************/

#ifndef SECM_DEC_H
#define SECM_DEC_H

#ifdef  __cplusplus
extern "C" {
#endif

/****************************************************************************
 ** Types and constants
 ***************************************************************************/

/* Constants */ 
#define SIZE_OF_AES_IV  16

/* Types for decryption */
typedef void *SecM_DecInitType;
typedef void *SecM_DecDeinitType;

typedef struct
{
   vuint8     *DataBuffer;
   SecM_LengthType  Length;
}SecM_DecInputParamType;
   
typedef struct
{
   vuint8    *DataBuffer;
   SecM_LengthType  Length;
}SecM_DecOutputParamType;

typedef struct
{  /* Start address of the segment */
   vuint32 segmentAddress; 
   /* Length of segment in bytes */
   vuint32 segmentLength;  
   /* Data format ID of encryption and compression */
   vuint8  mode;           
   /* Pointer to watchdog trigger function */
   FL_WDTriggerFctType  wdTriggerFct;      

} SecM_DecParamType;

/* Pointer types for API-functions */
typedef SecM_StatusType SECM_CALL_TYPE (*pSecInitDecryptionFct) (SecM_DecInitType init);
typedef SecM_StatusType SECM_CALL_TYPE (*pSecDeinitDecryptionFct) (SecM_DecDeinitType deinit);
typedef SecM_StatusType SECM_CALL_TYPE (*pSecDecryptionFct) (SecM_DecInputParamType *inBlock, 
            SecM_DecOutputParamType *outBlock, SecM_DecParamType *decParam);


/****************************************************************************
 ** Function Prototypes
 ***************************************************************************/

extern SecM_StatusType SecM_InitDecryption( SecM_DecInitType init );
extern SecM_StatusType SecM_DeinitDecryption( SecM_DecDeinitType deinit );
extern SecM_StatusType SecM_Decryption( SecM_DecInputParamType *inBlock, 
            SecM_DecOutputParamType *outBlock, SecM_DecParamType *decParam );

#ifdef  __cplusplus
} /* extern "C" */
#endif

#endif /* SECM_DEC_H */
