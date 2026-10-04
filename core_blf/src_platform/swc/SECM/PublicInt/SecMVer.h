/****************************************************************************
 ** Main author: Sst                     Creation date: 04/24/06
 ** $Author::                          $ $JustDate:: 04/24/06             $
 ** $Workfile:: SecMVer.h              $ $Revision:: 1                    $
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
 ** This file contains: Implementation of the verification component 
 **                     of the HIS security module
 **
 ** constants:
 **   SECM_VER_OK 
 **   SECM_VER_ERROR
 **   SECM_VER_CRC
 **   SECM_VER_SIG
 **   SECM_HASH_INIT
 **   SECM_HASH_COMPUTE
 **   SECM_HASH_FINALIZE
 **
 ** types:
 **   SecM_VerifyInitType
 **   SecM_VerifyDeinitType
 **   SecM_VerifyDataType
 **   SecM_VerifyParamType
 **   SecM_SignatureType
 **   SecM_SignatureParamType
 **   pSecInitVerificationFct
 **   pSecDeinitVerificationFct
 **   pSecVerificationFct
 **   pSecTaskFct
 **
 ** functions:
 **   SecM_InitVerification
 **   SecM_DeinitVerification
 **   SecM_Verification
 **   SecM_VerifySignature
 **
 ***************************************************************************/

#ifndef SECM_VER_H
#define SECM_VER_H

#ifdef  __cplusplus
extern "C" {
#endif

/* Compatibility defines for SecMod CV2*/
#if defined (SECM_VERIFICATION_CRC_OFFSET)
#else
# define SECM_VERIFICATION_CRC_OFFSET      SECM_VER_CRC_OFFSET
#endif

#if defined (SECM_VERIFICATION_SIG_OFFSET)
#else
# define SECM_VERIFICATION_SIG_OFFSET      SECM_VER_SIG_OFFSET
#endif

#if defined (SECM_VERIFY_SIG_OFFSET)
#else
# define SECM_VERIFY_SIG_OFFSET            SECM_VER_SIG_OFFSET
#endif

#if defined (SEC_SECURITY_CLASS_VERIFY)
#else
# define SEC_SECURITY_CLASS_VERIFY         SEC_SECURITY_CLASS
#endif

#if defined (SEC_SECURITY_CLASS_VERIFICATION)
#else
# define SEC_SECURITY_CLASS_VERIFICATION   SEC_SECURITY_CLASS
#endif

#if (SEC_SECURITY_CLASS == SEC_CLASS_C)
# if defined (SEC_SECURITY_CLASS_C_USED)
# else
#  define SEC_SECURITY_CLASS_C_USED
# endif
#endif

#if (SEC_SECURITY_CLASS == SEC_CLASS_CCC)
# if defined (SEC_SECURITY_CLASS_CCC_USED)
# else
#  define SEC_SECURITY_CLASS_CCC_USED
# endif
#endif

#if defined(SEC_VERIFY_BYTES)
 #if (SEC_VERIFY_BYTES > 65535)
  /* ESCAN00018531: Sec_Verify_Bytes can not exceed 2^16-1 bytes */
  #error "Configuration of SEC_VERIFY_BYTES exceeds the limits".
 #endif
#endif

/****************************************************************************
 ** Types and constants
 ***************************************************************************/

/* Verification return codes */
#define SECM_VER_OK    0x00
#define SECM_VER_ERROR 0x01            /* Error occured during verification  */
#define SECM_VER_CRC   0x02            /* CRC verification failed            */
#define SECM_VER_SIG   0x04            /* HMAC/Signature verification failed */

/* Defines from SecM222 (V1.1) */
#define kHashInit          ((vuint8) 0x01u) /* Init signature verification        */ 
#define kHashCompute       ((vuint8) 0x02u) /* Computation state                  */
#define kHashFinalize      ((vuint8) 0x03u) /* Finalize hash (not implemented)    */
#define kSigVerify         ((vuint8) 0x04u) /* Final tasks                        */

/* Signature verification states */
#define SECM_HASH_INIT     kHashInit     /* Init signature verification        */ 
#define SECM_HASH_COMPUTE  kHashCompute  /* Computation state                  */
#define SECM_HASH_FINALIZE kHashFinalize /* Finalize hash (not implemented)    */
#define SECM_SIG_FINALIZE  kSigVerify    /* Final tasks                        */ 

/* Types for verification functionality */
typedef void* SecM_VerifyInitType;
typedef void* SecM_VerifyDeinitType;
typedef vuint8* SecM_VerifyDataType;

/* Parameter structure for Verification procedure */
typedef struct tagSecM_VerifyParamType
{
   /* Address- and length info for segments   */
   FL_SegmentListType   segmentList;    
   /* Start address of logical block      */
   SecM_AddrType        blockStartAddress;  
   /* Length of logical block             */
   SecM_SizeType        blockLength;           
   SecM_VerifyDataType  verificationData;
   SecM_CRCType         crcTotal;
   /* Pointer to watchdog trigger function */
   FL_WDTriggerFctType  wdTriggerFct;        
   FL_ReadMemoryFctType readMemory;
}SecM_VerifyParamType;

/* Structure to describe signature */
typedef struct tagSecM_SignatureType
{
   vuint32 sigResultBuffer;
   vuint32 length;
}SecM_SignatureType;

/* Parameter structure for signature verification */
typedef struct tagSecM_SignatureParamType
{
   SecM_SignatureType currentHash;
   vuint32           *currentDataLength;
   vuint8             sigState;
   vuint8            *sigSourceBuffer;
   SecM_LengthType    sigByteCount;
   FL_WDTriggerFctType wdTriggerFct;
}SecM_SignatureParamType;

/* Pointer types for function calls from external application */
typedef SecM_StatusType SECM_CALL_TYPE (*pSecInitVerificationFct) (SecM_VerifyInitType init);
typedef SecM_StatusType SECM_CALL_TYPE (*pSecDeinitVerificationFct) (SecM_VerifyDeinitType deinit);
typedef SecM_StatusType SECM_CALL_TYPE (*pSecVerificationFct) (SecM_VerifyParamType *verifyParam);
typedef SecM_StatusType SECM_CALL_TYPE (*pSecVerifySignatureFct) (SecM_SignatureParamType *signatureParam);

/****************************************************************************
 ** Function Prototypes
 ***************************************************************************/

extern SecM_StatusType SecM_InitVerification( SecM_VerifyInitType init );
extern SecM_StatusType SecM_DeinitVerification( SecM_VerifyDeinitType deinit );
extern SecM_StatusType SecM_Verification( SecM_VerifyParamType *verifyParam );

extern SecM_StatusType SecM_VerifySignature (SecM_SignatureParamType *signatureParam);



#ifdef  __cplusplus
} /* extern "C" */
#endif


#endif /* SECM_VER_H */
