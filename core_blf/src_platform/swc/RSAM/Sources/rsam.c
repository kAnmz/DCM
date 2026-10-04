/******************************************************************************/
/* @F_NAME :          rsam.c                                                  */
/* @F_PURPOSE :       RSA management                                          */
/* @F_CREATED_BY :    Weng dejian                                             */
/* @F_CREATION_DATE : 2022/09/22                                              */
/* @F_LANGUAGE :      ANSI C                                                  */
/* @F_MPROC_TYPE :    target independent                                      */
/*************************************** (C) Copyright 2021 Marelli ***********/
/*______ I N C L U D E - F I L E S ___________________________________________*/
#include "sha256.h"
#include "rsam.h"
#include "rsa.h"
#include "rsam_config.h"
#include "mcwdt_config.h"
#include "fblm_config.h"
#include "fblm_priv.h"
#include "vers.h"
/*______ L O C A L - D E F I N E S ___________________________________________*/

#define RSAM_SHACHECKLEN                     0x400u
#define RSAM_APP_SHAOFFSET                   12u
#define RASM_FLASHDRV_STARTADDRESS           FBLM_FLASHDRV_STARTADDRESS
#define RASM_FLASHDRV_LENGTH                 FlashDrv_BlockSize
#define RASM_APP_STARTADDRESS                FBLM_APP_STARTADDRESS
#define RASM_APP_LENGTH                      FBLM_APP_LENGTH
#define RASM_SWP1_STARTADDRESS               FBLM_SWP1_STARTADDRESS
#define RASM_SWP1_LENGTH                     FBLM_SWP1_SIZE

/*______ L O C A L - T Y P E S _______________________________________________*/
typedef struct {
  uint8 FormatId[2];
  uint8 NumOfBlk[2];
  uint8 StartAddress[4];
  uint8 Length[4];
  uint8 Hash[32];
} Rsam_Vbt_t;
/*______ G L O B A L - D A T A _______________________________________________*/


/*______ L O C A L - D A T A _________________________________________________*/

static uint8 *Rsam_SignaturePtr = NULL;
static Rsam_Vbt_t *Rsam_VbtPtr = NULL;
static uint32 Rsam_VbtLen = 0;
static uint32 Rsam_VbtAddress = 0;
static uint32 Rsam_ApplAddress = 0u;
static uint32 Rsam_ApplLength = 0u;
static uint8 ApplHash[32] = {0};
static uint8 Rsam_RsaState = RSAM_IDLE;
static uint8 Rsam_RsaErrType = RSAM_RSA_OTHER_FAIL;
/*______ L O C A L - F U N C T I O N S - P R O T O T Y P E S _________________*/
static void Rsam_CalVbtHash(uint8 Output[32]);
static void Rsam_CalApplHash(uint8 Output[32], uint32 ApplAddr, uint32 ApplLength);
static void Rsam_CalDataHash(uint8 Output[32], uint8 *DataCalAddr, uint32 DataCalLength);

/*______ G L O B A L - F U N C T I O N S _____________________________________*/

/******************************************************************************/
/*Name : RSAM_Init                                                            */
/*Role:                                                                       */
/*Interface :                                                                 */
/*Pre-condition :                                                             */
/*Constraints: -                                                              */
/*Behaviour:                                                                  */
/******************************************************************************/
void RSAM_Init(void)
{
  Rsam_SignaturePtr = NULL;
  Rsam_VbtPtr = NULL;
  Rsam_VbtLen = 0;
  Rsam_RsaState = RSAM_IDLE;
  Rsam_RsaErrType = RSAM_RSA_OTHER_FAIL;
}

/******************************************************************************/
/*Name : RSAM_Runnable                                                        */
/*Role:                                                                       */
/*Interface :                                                                 */
/*Pre-condition :                                                             */
/*Constraints: -                                                              */
/*Behaviour:                                                                  */
/******************************************************************************/
void RSAM_Runnable(void)
{
  uint8 Vbtsha256[32] = {0};
  uint8 Applsha256[32] = {0};
  uint32 FileAddress = 0u;
  //if((RSAM_START_RSA == Rsam_RsaState) || ((RSAM_RSA_ONGOING == Rsam_RsaState)))
  {
	Fblm_LookForWatchdog();
    Rsam_RsaState = RSAM_RSA_ONGOING;
    FileAddress = ((Rsam_VbtPtr->StartAddress[0] << 24u) & 0xFF000000U)
      | ((Rsam_VbtPtr->StartAddress[1] << 16u) & 0x00FF0000U)
      | ((Rsam_VbtPtr->StartAddress[2] <<  8u) & 0x0000FF00U)
      | ((Rsam_VbtPtr->StartAddress[3] <<  0u) & 0x000000FFU);
    if(RASM_FLASHDRV_STARTADDRESS == FileAddress)
    {
      Rsam_CalApplHash(Applsha256, RASM_FLASHDRV_STARTADDRESS, RASM_FLASHDRV_LENGTH);
      if(0 == Rsam_Memcmp(Applsha256, (Rsam_VbtPtr->Hash), 32u))
      {
        Rsam_CalVbtHash(Vbtsha256);
        Rsam_RsaState = mbedtls_rsa_self_test(Rsam_SignaturePtr, Vbtsha256);
      }
      else
      {
        Rsam_RsaErrType = RSAM_RSA_APPHASH_FAIL;
        Rsam_RsaState = RSAM_RSA_FAIL;
      }
    }
    else if(RASM_APP_STARTADDRESS == FileAddress)
    {
      Fblm_LookForWatchdog();
      Rsam_CalApplHash(Applsha256, RASM_APP_STARTADDRESS, RASM_APP_LENGTH);
      if(0 == Rsam_Memcmp(Applsha256, (Rsam_VbtPtr->Hash), 32u))
      {
    	Fblm_LookForWatchdog();
        Rsam_CalVbtHash(Vbtsha256);
        Rsam_RsaState = mbedtls_rsa_self_test(Rsam_SignaturePtr, Vbtsha256);
      }
      else
      {
        Rsam_RsaErrType = RSAM_RSA_APPHASH_FAIL;
        Rsam_RsaState = RSAM_RSA_FAIL;
      }
    }
    else if(RASM_SWP1_STARTADDRESS == FileAddress)
    {
      Fblm_LookForWatchdog();
      Rsam_CalApplHash(Applsha256, RASM_SWP1_STARTADDRESS, RASM_SWP1_LENGTH);
      if(0 == Rsam_Memcmp(Applsha256, (Rsam_VbtPtr->Hash), 32u))
      {
        Rsam_CalVbtHash(Vbtsha256);
        Rsam_RsaState = mbedtls_rsa_self_test(Rsam_SignaturePtr, Vbtsha256);
      }
      else
      {
        Rsam_RsaErrType = RSAM_RSA_APPHASH_FAIL;
        Rsam_RsaState = RSAM_RSA_FAIL;
      }
    }
    else
    {
      Fblm_LookForWatchdog();
      Rsam_CalVbtHash(Vbtsha256);
      Rsam_RsaState = mbedtls_rsa_self_test(Rsam_SignaturePtr, Vbtsha256);
    }
  }
}


/******************************************************************************/
/*Name : RSAM_CheckVBTFormat                                                  */
/*Role:  check the VBT format and length correct or not                       */
/*Interface :                                                                 */
/*Pre-condition :                                                             */
/*Constraints: -                                                              */
/*Behaviour:                                                                  */
/******************************************************************************/
uint8 RSAM_CheckVBTFormat(uint8 *vbtPtr, uint32 vbtLength, uint32 FileStartAddress, uint32 FileTotalLength)
{
  uint8 Ret_Value = FALSE;
  Rsam_Vbt_t *Rsam_LocalVbtPtr = NULL;
  uint32 FileAddress_loacal = 0u;
  uint32 Filelength_loacal = 0u;

  Rsam_LocalVbtPtr = (Rsam_Vbt_t *)vbtPtr;

  FileAddress_loacal = ((Rsam_LocalVbtPtr->StartAddress[0] << 24u) & 0xFF000000U)
                      | ((Rsam_LocalVbtPtr->StartAddress[1] << 16u) & 0x00FF0000U)
                      | ((Rsam_LocalVbtPtr->StartAddress[2] <<  8u) & 0x0000FF00U)
                      | ((Rsam_LocalVbtPtr->StartAddress[3] <<  0u) & 0x000000FFU);

  Filelength_loacal = ((Rsam_LocalVbtPtr->Length[0] << 24u) & 0xFF000000U)
                      | ((Rsam_LocalVbtPtr->Length[1] << 16u) & 0x00FF0000U)
                      | ((Rsam_LocalVbtPtr->Length[2] <<  8u) & 0x0000FF00U)
                      | ((Rsam_LocalVbtPtr->Length[3] <<  0u) & 0x000000FFU);

  if(   (FBLM_VBT_SIZE == vbtLength)
      && (Rsam_LocalVbtPtr->FormatId[0] == 0x00)
      && (Rsam_LocalVbtPtr->FormatId[1] == 0x00)
      && (Rsam_LocalVbtPtr->NumOfBlk[0] == 0x00)
      && (Rsam_LocalVbtPtr->NumOfBlk[1] == 0x01)
      && (FileAddress_loacal == FileStartAddress)
      && (Filelength_loacal == FileTotalLength)   )
  {
    Ret_Value = TRUE;
  }

  return Ret_Value;
}

/******************************************************************************/
/*Name : RSAM_StartSignVerify                                                 */
/*Role:  Rsa signature verify                                                 */
/*Interface :                                                                 */
/*Pre-condition :                                                             */
/*Constraints: -                                                              */
/*Behaviour:                                                                  */
/******************************************************************************/
uint8 RSAM_StartSignVerify(uint8 *Signature, uint8* vbtPtr, uint32 vbtLength, uint32 vbtAddr)
{
   uint8 status = 0;
   uint8 Fblm_CheckMemoryResult = 0;
  if((RSAM_START_RSA != Rsam_RsaState) && ((RSAM_RSA_ONGOING != Rsam_RsaState)))
  {
    Rsam_SignaturePtr = Signature;
    Rsam_VbtPtr = (Rsam_Vbt_t *)vbtPtr;
    Rsam_VbtLen = vbtLength;
    Rsam_VbtAddress = vbtAddr;
    Rsam_RsaState = RSAM_START_RSA;
    Rsam_RsaErrType = RSAM_RSA_OTHER_FAIL;
    Fblm_LookForWatchdog();
    Rsam_GetPublicKey();
  }

  RSAM_Runnable();
  status = RSAM_GetRsaState();
  if(status == MBEDTLS_RSA_SUCCESS)
  {
  	Fblm_CheckMemoryResult = TRUE;
  }
  else if(status == MBEDTLS_RSA_FAIL)
  {
  	Fblm_CheckMemoryResult = FALSE;
  }
  return Fblm_CheckMemoryResult;
}

/******************************************************************************/
/*Name : RSAM_GetRsaState                                                     */
/*Role:  Get Rsa verify state                                                 */
/*Interface :                                                                 */
/*Pre-condition :                                                             */
/*Constraints: -                                                              */
/*Behaviour:                                                                  */
/******************************************************************************/
uint8 RSAM_GetRsaState(void)
{
  return Rsam_RsaState;
}

/******************************************************************************/
/*Name : RSAM_GetDetailErrType                                                */
/*Role:  Get Rsa detail fail type                                             */
/*Interface :                                                                 */
/*Pre-condition :                                                             */
/*Constraints: -                                                              */
/*Behaviour:                                                                  */
/******************************************************************************/
uint8 RSAM_GetDetailErrType(void)
{
  return Rsam_RsaErrType;
}

/*______ L O C A L - F U N C T I O N S _______________________________________*/

/******************************************************************************/
/*Name : Rsam_CalVbtHash                                                      */
/*Role:  Get Hash of VBT block                                                */
/*Interface :                                                                 */
/*Pre-condition :                                                             */
/*Constraints: -                                                              */
/*Behaviour:                                                                  */
/******************************************************************************/
static void Rsam_CalVbtHash(uint8 Output[32])
{
  mbedtls_sha256_context Rsam_sha256_ctx;
  uint8 vbtStart[4] = { (uint8)(Rsam_VbtAddress >> 24u) & 0xFFU,
                        (uint8)(Rsam_VbtAddress >> 16u) & 0xFFU,
                        (uint8)(Rsam_VbtAddress >>  8u) & 0xFFU,
                        (uint8)(Rsam_VbtAddress >>  0u) & 0xFFU };
  uint8 vbtLen[4] = { (uint8)(Rsam_VbtLen >> 24u) & 0xFFU,
                      (uint8)(Rsam_VbtLen >> 16u) & 0xFFU,
                      (uint8)(Rsam_VbtLen >>  8u) & 0xFFU,
                      (uint8)(Rsam_VbtLen >>  0u) & 0xFFU };
  Fblm_LookForWatchdog();
  mbedtls_sha256_init(&Rsam_sha256_ctx);
  Fblm_LookForWatchdog();
  mbedtls_sha256_starts(&Rsam_sha256_ctx,0);
  Fblm_LookForWatchdog();
  mbedtls_sha256_update(&Rsam_sha256_ctx, vbtStart, sizeof(vbtStart));
  Fblm_LookForWatchdog();
  mbedtls_sha256_update(&Rsam_sha256_ctx, vbtLen, sizeof(vbtLen));
  Fblm_LookForWatchdog();
  mbedtls_sha256_update(&Rsam_sha256_ctx, (unsigned char *)Rsam_VbtPtr, Rsam_VbtLen);
  Fblm_LookForWatchdog();
  mbedtls_sha256_finish(&Rsam_sha256_ctx, Output);
  Fblm_LookForWatchdog();
  mbedtls_sha256_free(&Rsam_sha256_ctx);
  Fblm_LookForWatchdog();
}

/******************************************************************************/
/*Name : Rsam_CalApplHash                                                     */
/*Role:  Get Hash of VBT block                                                */
/*Interface :                                                                 */
/*Pre-condition :                                                             */
/*Constraints: -                                                              */
/*Behaviour:                                                                  */
/******************************************************************************/
static void Rsam_CalApplHash(uint8 Output[32], uint32 ApplAddr, uint32 ApplLength)
{
  mbedtls_sha256_context Rsam_sha256_ctx;

  Rsam_ApplAddress = ApplAddr;
  Rsam_ApplLength = ApplLength;
  Fblm_LookForWatchdog();
  mbedtls_sha256_init(&Rsam_sha256_ctx);
  Fblm_LookForWatchdog();
  mbedtls_sha256_starts(&Rsam_sha256_ctx,0);
  do
  {
	  Fblm_LookForWatchdog();
    mbedtls_sha256_update(&Rsam_sha256_ctx, (unsigned char *)Rsam_ApplAddress, RSAM_SHACHECKLEN);
    Rsam_ApplLength -= RSAM_SHACHECKLEN;
    Rsam_ApplAddress += RSAM_SHACHECKLEN;
  }while(Rsam_ApplLength > RSAM_SHACHECKLEN);

  Fblm_LookForWatchdog();
  mbedtls_sha256_update(&Rsam_sha256_ctx, (unsigned char *)Rsam_ApplAddress, Rsam_ApplLength);
  Fblm_LookForWatchdog();
  mbedtls_sha256_finish(&Rsam_sha256_ctx, Output);
  Fblm_LookForWatchdog();
  mbedtls_sha256_free(&Rsam_sha256_ctx);
  Fblm_LookForWatchdog();
}

/******************************************************************************/
/*Name : Rsam_CalDataHash                                                     */
/*Role:  Get Hash of data                                                     */
/*Interface :                                                                 */
/*Pre-condition :                                                             */
/*Constraints: -                                                              */
/*Behaviour:                                                                  */
/******************************************************************************/
static void Rsam_CalDataHash(uint8 Output[32], uint8 *DataCalAddr, uint32 DataCalLength)
{
  mbedtls_sha256_context Rsam_sha256_ctx;
  uint32 remainingLength = DataCalLength;
  uint8 *currentAddr = DataCalAddr;
  uint32 chunkLength = 0;

  Fblm_LookForWatchdog();
  mbedtls_sha256_init(&Rsam_sha256_ctx);
  Fblm_LookForWatchdog();
  mbedtls_sha256_starts(&Rsam_sha256_ctx, 0);

  while (remainingLength > 0) 
  {
    chunkLength = (remainingLength > RSAM_SHACHECKLEN) ? RSAM_SHACHECKLEN : remainingLength;

    Fblm_LookForWatchdog();
    mbedtls_sha256_update(&Rsam_sha256_ctx, (uint8 *)currentAddr, chunkLength);

    remainingLength -= chunkLength;
    currentAddr += chunkLength;
  }

  Fblm_LookForWatchdog();
  mbedtls_sha256_finish(&Rsam_sha256_ctx, Output);
  Fblm_LookForWatchdog();
  mbedtls_sha256_free(&Rsam_sha256_ctx);
  Fblm_LookForWatchdog();
}

/******************************************************************************/
/*Name : RSAM_CheckPublicKeyIntegrity                                         */
/*Role:  public key integrity check                                           */
/*Interface :                                                                 */
/*Pre-condition :                                                             */
/*Constraints: -                                                              */
/*Behaviour:                                                                  */
/******************************************************************************/
boolean RSAM_CheckPublicKeyIntegrity(void)
{
  boolean Ret_Value = FALSE;
  uint8 PublicKeysha256[RSAM_PK_CHECKSUM_LEN] = {0};
  uint8 RSA_PublicKey[RSAM_PUBLICKEY_LEN] = {0};
  uint8 *PublicKeyChecksumPtr = NULL;

  PublicKeyChecksumPtr = VERS_GetPublicKeyDataPublicKeyCheckSumPtr();
  DIAG_RSAPublicKey_RD(RSA_PublicKey);
  Rsam_CalDataHash(PublicKeysha256, RSA_PublicKey, RSAM_PUBLICKEY_LEN);
  if(0 == Rsam_Memcmp(PublicKeysha256, PublicKeyChecksumPtr, RSAM_PK_CHECKSUM_LEN))
  {
    Ret_Value = TRUE;
  } 

  return Ret_Value;
}

/******************************************************************************/
/*Name : RSAM_CheckMemoryHash256                                              */
/*Role:  calculate the HASH256 for given buffer and length and check          */
 /*      correct or not                                                       */
/*Interface :                                                                 */
/*Pre-condition :                                                             */
/*Constraints: -                                                              */
/*Behaviour:  Check OK return TRUE,not OK return FALSE                        */
/******************************************************************************/
boolean RSAM_CheckMemoryHash256(uint8 *HashCalPtr, uint8 *HashCompPtr ,uint32 HashLen)
{
  boolean Ret_Value = FALSE;
  uint8 HashCalsha256[RSAM_PK_CHECKSUM_LEN] = {0};

  if((HashCalPtr != NULL)
      && (HashCompPtr != NULL))
  {
    Rsam_CalDataHash(HashCalsha256, HashCalPtr, HashLen);
    if(0 == Rsam_Memcmp(HashCalsha256, HashCompPtr, RSAM_PK_CHECKSUM_LEN))
    {
      Ret_Value = TRUE;
    } 
  }

  return Ret_Value;
}

