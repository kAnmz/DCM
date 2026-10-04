/******************************************************************************/
/*@F_NAME:           rsam_config.c                                            */
/*@F_PURPOSE:        RSAM - Module configuration implementation               */
/*@F_CREATED_BY:     Weng dejian                                              */
/*@F_CREATION_DATE:  2022/10/18                                               */
/*@F_LANGUAGE :      ANSI C                                                   */
/*@F_MPROC_TYPE:     Processor independent                                    */
/************************************** (C) Copyright 2011 Magneti Marelli ****/

/*______ I N C L U D E - F I L E S ___________________________________________*/
#include "platform_Types.h"
#include "string.h"
#include "fblm_config.h"
#include "rsam_config.h"
/*______ L O C A L - D E F I N E S ___________________________________________*/

#define DIAG_PK_MODULUS_LEN											(256u)
#define DIAG_PK_EXPONENT_LEN										(4u)
#define DIAG_PK_CHECKSUM_LEN										(32u)

/*______ L O C A L - T Y P E S _______________________________________________*/

/*______ G L O B A L - D A T A _______________________________________________*/
extern uint8 RSA_N_JIDU[512];
extern uint8 RSA_E_JIDU[8];


/*______ P R I V A T E - D A T A _____________________________________________*/

/*______ L O C A L - D A T A _________________________________________________*/
#if 0  /*it be placed in wdfs_config.h*/
static const uint8 Diag_PublicKeyExponent[DIAG_PK_EXPONENT_LEN] =  {0x00,0x01,0x00,0x01};

static const uint8 Diag_PublicKeyModulus[DIAG_PK_MODULUS_LEN] =
{
  0xB7,0xE9,0x74,0x4B,0x45,0xFA,0xA6,0x20,0xD3,0x1C,
  0x30,0xE9,0x63,0x86,0xE9,0xCD,0x5F,0xB9,0x93,0xDE,
  0xCA,0x45,0xC9,0xD6,0x08,0x94,0xF7,0x7D,0xB9,0xEE,
  0xA9,0xD0,0x78,0x45,0x76,0x94,0x80,0x9D,0xF7,0x05,
  0x24,0xD7,0x30,0xE2,0xC0,0x0F,0x04,0x6E,0x60,0x53,
  0x23,0xBD,0x50,0x03,0xBF,0x2C,0xA9,0xBB,0xB4,0x5C,
  0xC5,0x11,0x5A,0x1D,0xCE,0x25,0x7D,0x42,0x03,0x4F,
  0x7E,0x1C,0x7A,0x3E,0x1A,0x68,0xE8,0x9A,0x00,0x10,
  0x8D,0x18,0x28,0xAC,0x26,0xBD,0x71,0xAE,0x4A,0xC9,
  0xB9,0x23,0x0B,0x9B,0xC1,0x01,0x67,0x46,0xA9,0x01,
  0x5E,0x70,0xF1,0xD9,0xBD,0x7F,0x56,0x4B,0x97,0x61,
  0x64,0xFF,0xC1,0xD9,0x6E,0x93,0xAB,0x40,0x66,0xD5,
  0xCB,0xF4,0x02,0xF5,0xFC,0x53,0x11,0x51,0xA9,0x80,
  0x5C,0x07,0x16,0xAB,0xCB,0x98,0x25,0xFE,0x02,0xF3,
  0x89,0x7E,0x57,0x91,0x7A,0x64,0xCC,0x2C,0x7A,0x71,
  0xE8,0x83,0x33,0x59,0x0A,0xA9,0x59,0x23,0xCF,0x4A,
  0x6B,0xE4,0x24,0x1A,0xF7,0x8C,0xA9,0x04,0x5D,0x65,
  0xB6,0x74,0x87,0x19,0x42,0x49,0xE3,0x69,0x03,0xDD,
  0xA4,0xC9,0x75,0xFE,0xA7,0x3C,0x07,0xC1,0x91,0x67,
  0x54,0x45,0xFE,0x5F,0xCF,0x45,0x72,0xF8,0xBD,0x47,
  0x95,0xBA,0x81,0xA7,0x54,0x50,0x55,0x29,0x92,0x2F,
  0x81,0x82,0x71,0x9B,0x43,0x1C,0xEB,0x27,0x16,0xCA,
  0x87,0xE2,0xBA,0x83,0xA0,0x1E,0x85,0xEF,0x75,0xE4,
  0x63,0x88,0x2D,0x0B,0x53,0x76,0xB6,0xB3,0xD6,0x68,
  0x19,0xE2,0x6C,0x2B,0x67,0x4F,0x0A,0x9D,0xDE,0xFE,
  0x93,0x42,0x43,0xCE,0x87,0xAD
};
#endif
/*______ L O C A L - M A C R O S _____________________________________________*/

/*______ I M P O R T - F U N C T I O N S - P R O T O T Y P E S _______________*/

/*______ L O C A L - F U N C T I O N S - P R O T O T Y P E S _________________*/
static uint8 Rsam_HexToASCII(uint8 data);
static void Rsam_TransferKey(uint8* RSA_Inkey, uint8* RSA_OutKey, uint16 length);

/*______ G L O B A L - F U N C T I O N S _____________________________________*/

/*______ P R I V A T E - F U N C T I O N S ___________________________________*/

/******************************************************************************/
/*Name : DIAG_RSAPublicKey_RD                                                 */
/*Role:  Read  data                                                           */
/*ret:   RTE_E_INVALID means read defaut value                                */
/*Interface :                                                                 */
/*Pre-condition :                                                             */
/*Constraints: -                                                              */
/*Behaviour:                                                                  */
/******************************************************************************/
void DIAG_RSAPublicKey_RD(uint8* Data)
{
  uint8 buffer[DIAG_PK_MODULUS_LEN+DIAG_PK_EXPONENT_LEN] = {0};
#if 0   /*Now , need to add NVM*/
  uint32 workFlash_Addr = (DIAG_PUBLICKEY_FLASH_ADDR - DIAG_BLOCKS_DISTANCE_SIZE - DIAG_PK_EXPONENT_LEN);

  cy_en_flashdrv_status_t bank_status = CY_FLASH_DRV_SUCCESS;

  if (NULL == Data)
  {
    /*Error*/
  }

  bank_status = Cy_Flash_BlankCheck(&Diag_sromContext, &Diag_blankCheckConfig[0], CY_FLASH_DRIVER_BLOCKING);

  if (CY_FLASH_DRV_SUCCESS != bank_status)

  {
    memcpy(buffer, workFlash_Addr, DIAG_PK_MODULUS_LEN+DIAG_PK_EXPONENT_LEN);
    DIAG_MemeryChange(buffer,DIAG_PK_MODULUS_LEN+DIAG_PK_EXPONENT_LEN);
    memcpy(Data, buffer, DIAG_PK_MODULUS_LEN+DIAG_PK_EXPONENT_LEN);
  }
  else
#endif
  {
    memcpy(Data, Fblm_PublicKeyData, DIAG_PK_MODULUS_LEN);
    memcpy(&Data[DIAG_PK_MODULUS_LEN], Fblm_PublicKeyExponent, DIAG_PK_EXPONENT_LEN);
  }
}

/******************************************************************************/
/*Name : Rsam_GetPublicKey                                                    */
/*Role:  Get public key                                                       */
/*Interface :                                                                 */
/*Pre-condition :                                                             */
/*Constraints: -                                                              */
/*Behaviour:                                                                  */
/******************************************************************************/
void Rsam_GetPublicKey(void)
{
  uint8 RSA_PublicKey[RSAM_PUBLICKEY_LEN];
  DIAG_RSAPublicKey_RD(RSA_PublicKey);

  Rsam_TransferKey(&RSA_PublicKey[0], RSA_N_JIDU, RSAM_PK_MODULUS_LEN);
  Rsam_TransferKey(&RSA_PublicKey[RSAM_PK_MODULUS_LEN], RSA_E_JIDU, RSAM_PK_EXPONENT_LEN);
}
/******************************************************************************/
/*Name : Rsam_Memcmp                                                          */
/*Role:  Compare memory                                                       */
/*Interface :                                                                 */
/*Pre-condition :                                                             */
/*Constraints: -                                                              */
/*Behaviour:                                                                  */
/******************************************************************************/
sint8 Rsam_Memcmp(const void* buf1, const void* buf2, uint16 len)
{
  return memcmp(buf1, buf2, len);
}

/******************************************************************************/
/*Name : Rsam_GetPublicKey                                                    */
/*Role:  Get public key                                                       */
/*Interface :                                                                 */
/*Pre-condition :                                                             */
/*Constraints: -                                                              */
/*Behaviour:                                                                  */
/******************************************************************************/
uint32 Rsam_GetApplAddress(uint32 address)
{
  uint32 AddressOffset = 0u;
 // AddressOffset =  Fblm_ManageAddOffset(address);
  return AddressOffset;
}

/*______ L O C A L - F U N C T I O N S _______________________________________*/

/******************************************************************************/
/*Name : Rsam_HexToASCII                                                      */
/*Role:  Transfer Hex to ASCII                                                */
/*Interface :                                                                 */
/*Pre-condition :                                                             */
/*Constraints: -                                                              */
/*Behaviour:                                                                  */
/******************************************************************************/
static uint8 Rsam_HexToASCII(uint8 data)
{
  uint8 ret = 0;
  if(data >= 0x00U && data <= 0x09U)
  {
    ret = data + 0x30U;
  }
  else if(data >= 0x0AU && data <= 0x0FU)
  {
    ret = data + 0x57U;
  }
  else
  {
  }
  return ret;
}

/******************************************************************************/
/*Name : Rsam_TransferKey                                                     */
/*Role:  Transfer Buffer to string                                            */
/*Interface :                                                                 */
/*Pre-condition :                                                             */
/*Constraints: -                                                              */
/*Behaviour:                                                                  */
/******************************************************************************/
static void Rsam_TransferKey(uint8* RSA_Inkey, uint8* RSA_OutKey, uint16 length)
{
  uint16 i;
  uint8 temp1;
  uint8 temp2;
  for(i= 0; i<length; i++)
  {
    temp1 = ((RSA_Inkey[i] >> 4U) & 0x0FU);
    temp2 = (RSA_Inkey[i] & 0x0FU);

    RSA_OutKey[2*i] = Rsam_HexToASCII(temp1);
    RSA_OutKey[2*i+1] = Rsam_HexToASCII(temp2);
  }
}



/*______ E N D _____ (rsam_config.c) _________________________________________*/
