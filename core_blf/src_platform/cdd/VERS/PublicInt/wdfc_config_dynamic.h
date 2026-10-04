/******************************************************************************/
/*!
* \file        wdfc_config_dynamic.h
* \brief       Export for WDFC module 
* \author      Ken XU
* \since       
* \version     1.0
* \copyright   Magneti Marelli - Guangzhou
*
* \note        This file is generated dynamically, please don't edit!!!
*
* <br>
*/
/******************************************************************************/

#ifndef WDFC_CONFIG_DYNAMIC_H
#define WDFC_CONFIG_DYNAMIC_H

/*______ I N C L U D E - F I L E S ___________________________________________*/

#include "Platform_Types.h"

/*______ G L O B A L - D E F I N E S _________________________________________*/

/* Set value of Eeprom Identifier, if not use, remove this define */
#define WDFC_FLASH_MAIN_ID          (0x19)   /* Main ID */

#if defined(DCU_FL)
  #define WDFC_FLASH_SUB_ID         (0x1000) /* Sub ID for normal release*/
#elif defined(DCU_FR)
  #define WDFC_FLASH_SUB_ID         (0x2000) /* Sub ID for normal release*/
#elif defined(DCU_RL)
  #define WDFC_FLASH_SUB_ID         (0x4000) /* Sub ID for normal release*/
#elif defined(DCU_RR)
  #define WDFC_FLASH_SUB_ID         (0x8000) /* Sub ID for normal release*/
#endif

#define WDFC_FLASH_IDENTIFIER       ((uint16)((uint16)WDFC_FLASH_MAIN_ID | (uint16)WDFC_FLASH_SUB_ID))

#define WDFC_MAGIC_WORD_EEP         (0x9999)
#define WDFC_MAGIC_WORD_ROM         (0x3333)

/* Define version struct identifier. If the struct dimension is changed is necessary to change this version */
#define VERS_NOTHING                (0xff)   /* This define must always to 0xff */
#define VERS_THING                  (0x01)   /* This define must always to 0xff */
#define VERS_THING2                 (0x02)   /* This define must always to 0xff */


#define WDFC_EOL_DONE               0xAA

//#define WDFC_IS_BOOT_ID(id)         (((id) >= (uint16)WDFC_BOOT_ID_START) && ((id) <= (uint16)WDFC_BOOT_ID_END))
//#define WDFC_IS_EOL_ID(id)          (((id) >= (uint16)WDFC_ID_ID_OPTION) && ((id) <= (uint16)WDFC_ID_EOL_EXT2))
//#define WDFC_IS_APP_ID(id)          (((id) > (uint16)WDFC_ID_EOL_EXT2) && ((id) < (uint16)WDFC_NUM_ID))
//#define WDFC_START_ID               WDFC_ID_ID_OPTION
//#define WDFC_BOOT_ID_START          WDFC_ID_SWP1
//#define WDFC_BOOT_ID_END            WDFC_ID_BOOT_EXT1

#define WDFC_MAX_ID                 (96U)

#define ASSERT_CONCAT_(a, b)        a##b
#define ASSERT_CONCAT(a, b)         ASSERT_CONCAT_(a, b)
#define WDFC_CHECK_SIZE(e)          enum { ASSERT_CONCAT(assert_line_, __LINE__) = (uint8)1/((uint8)(e)) }
#define VERS_AP_LEARN               ((uint16)0x0002)
#define VERS_WLC_CONTEXT            ((uint16)0x0002)
#define VERS_AP_SEAL			          ((uint16)0x0002)
#define VERS_WL_MC__DRV_CONF		    ((uint16)0x0002)
#define VERS_AP_FILTER              ((uint16)0x0002)
#define VERS_THPA                   ((uint16)0x0003)

/*______ G L O B A L - T Y P E S _____________________________________________*/

typedef uint8  * const Wdfc_VarRomRamTab_t;


/* Identify data Ram or Rom pointer eeprom */
typedef enum
{
   WDFC_TYPE_ROM = 0
,  WDFC_TYPE_RAM
,  WDFC_NUM_TYPE_MEM
} WDFC_Type_mem_t;


/* -------------------------------------------------------------------------- */
/* Eeprom data Identifiers                                                    */
/* -------------------------------------------------------------------------- */
typedef enum
{
  /* Phase 1:Before first frame */
  WDFC_ID_IDENT_BANK = 0,
  WDFC_ID_CCP,
  WDFC_ID_WL_INFO,
  WDFC_ID_WLC_AP_LEARN,
  WDFC_ID_DLC,
  WDFC_ID_AP_CONNEX,
  WDFC_ID_HANDLE_CFG,
  WDFC_ID_MIRROR_CFG,
  WDFC_ID_PMM,
  WDFC_ID_SWP1,
  WDFC_ID_VOL_POWER_MODE_CFG,
  WDFC_ID_ECUID_RDI_PROGRAMMING_INFO,

  /* Phase 2:APP running */
  WDFC_ID_AP_PARA,
  WDFC_ID_MIRROR_ST,
  WDFC_ID_SR_PROFILE,
#if defined(DCU_FL) || defined(DCU_FR)
  WDFC_ID_MIRROR_OTHER_1,
  WDFC_ID_MIRROR_POS_REC,
#endif
  WDFC_ID_THPA,
  WDFC_ID_VEH_CFG,
  WDFC_ID_WL_LOG,
  WDFC_ID_SECURITY_ACCESS,

  /* Phase 3:DTC, Log */
  WDFC_ID_BOOT_PARA,
  WDFC_ID_EOL_INFO,
  WDFC_ID_IDOPTION_SECURITY,
  WDFC_ID_QCM_FAULT_DATA,
  
  WDFC_ID_MAX_FDC,
  WDFC_ID_DTCTime,
  WDFC_ID_LAST_FDC,

  
  WDFC_NUM_ID
} WDFC_Id_t;


/* Struct data eeprom */
typedef struct
{
   uint8            BlockId;             /* BlockId */
   uint16           Wdfc_SizeBank;       /* Size bank */
} WDFC_GroupConfigMapping_t;

/*______ G L O B A L - D A T A _______________________________________________*/

extern Wdfc_VarRomRamTab_t              WDFC_VarRomRamTable         [WDFC_NUM_ID][WDFC_NUM_TYPE_MEM];
extern WDFC_GroupConfigMapping_t const  WDFC_GroupConfigMappingROM  [WDFC_NUM_ID];


#endif

/*______ E N D _____ (wdfc_config_dynamic.h) _________________________________*/
