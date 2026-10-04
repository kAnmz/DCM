/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                 This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                 Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                 All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  LICENSE
 *  -------------------------------------------------------------------------------------------------------------------
 *            Module: vMem_30_Traveo2Cyp01
 *           Program: MSR_Geely_SLP2
 *          Customer: Marelli Automotive Electronics (Guangzhou) Co., Ltd
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: CYT2B75BA
 *    License Scope : The usage is restricted to CBD2600619_D00
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: vMem_30_Traveo2Cyp01_Lcfg.c
 *   Generation Time: 2026-07-14 11:05:45
 *           Project: DaVinci_Zeekr_Display - Version 1.0
 *          Delivery: CBD2600619_D00
 *      Tool Version: DaVinci Configurator Classic (beta) 5.31.60 SP6
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 ! BETA VERSION                                                                                                       !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 ! This version of DaVinci Configurator Classic and/or the related Basic Software Package is BETA software.               !
 ! BETA Software is basically operable, but not sufficiently tested, verified and/or qualified for use in series      !
 ! production and/or in vehicles operating on public or non-public roads.                                             !
 ! In particular, without limitation, BETA Software may cause unpredictable ECU behavior, may not provide all         !
 ! functions necessary for use in series production and/or may not comply with quality requirements which are         !
 ! necessary according to the state of the art. BETA Software must not be used in series production.                  !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
**********************************************************************************************************************/


#define VMEM_30_TRAVEO2CYP01_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "vMem_30_Traveo2Cyp01_Cfg.h"

/* Add hw specific data */

/**********************************************************************************************************************
  LOCAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/


/**********************************************************************************************************************
  LOCAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA
**********************************************************************************************************************/


/**********************************************************************************************************************
  GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  vMem_30_Traveo2Cyp01_MemSector
**********************************************************************************************************************/
/** 
  \var    vMem_30_Traveo2Cyp01_MemSector
  \brief  Configuration description of a programmable sector or sector batch.
  \details
  Element           Description
  StartAddress      Physical start address of the first sector.
  EraseBurstSize    Burst size for erase jobs, if configured. Otherwise sector size
  SectorSize        Size of this sector in bytes.
  NrOfSectors       Number of continuous sectors with identical values for vMemSectorSize and vMemPageSize.
  PageSize          Size of one page of this sector in bytes.
  RamAlignment      In order to perform write jobs correctly, a device might require a specific alignment of the data buffer.
  WriteBurstSize    Burst size for write jobs, if configured. Otherwise page size
  FlashType         Flash type of this sector.
*/ 
#define VMEM_30_TRAVEO2CYP01_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(vMem_30_Traveo2Cyp01_MemSectorType, VMEM_30_TRAVEO2CYP01_CONST) vMem_30_Traveo2Cyp01_MemSector[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    StartAddress  EraseBurstSize  SectorSize  NrOfSectors  PageSize  RamAlignment  WriteBurstSize  FlashType                                   Referable Keys */
  { /*     0 */  0x14000000u,          2048u,      2048u,         36u,       4u,           1u,             4u, VMEM_30_TRAVEO2CYP01_FLASH_TYPE_WORK },  /* [/ActiveEcuC/vMem/vMemInstance] */
  { /*     1 */  0x14012000u,           128u,       128u,        192u,       4u,           1u,             4u, VMEM_30_TRAVEO2CYP01_FLASH_TYPE_WORK }   /* [/ActiveEcuC/vMem/vMemInstance] */
};
#define VMEM_30_TRAVEO2CYP01_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  vMem_30_Traveo2Cyp01_vMemInstance
**********************************************************************************************************************/
/** 
  \var    vMem_30_Traveo2Cyp01_vMemInstance
  \brief  List of all configured vMem instances.
  \details
  Element              Description
  Id                   Unique numeric identifier of the instance, used to distinguish between vMem instances.
  MemSectorEndIdx      the end index of the 1:n relation pointing to vMem_30_Traveo2Cyp01_MemSector
  MemSectorLength      the number of relations pointing to vMem_30_Traveo2Cyp01_MemSector
  MemSectorStartIdx    the start index of the 1:n relation pointing to vMem_30_Traveo2Cyp01_MemSector
*/ 
#define VMEM_30_TRAVEO2CYP01_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(vMem_30_Traveo2Cyp01_vMemInstanceType, VMEM_30_TRAVEO2CYP01_CONST) vMem_30_Traveo2Cyp01_vMemInstance[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Id  MemSectorEndIdx  MemSectorLength  MemSectorStartIdx        Referable Keys */
  { /*     0 */ 0u,              2u,              2u,                0u }   /* [/ActiveEcuC/vMem/vMemInstance] */
};
#define VMEM_30_TRAVEO2CYP01_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */



/**********************************************************************************************************************
  GLOBAL INLINE FUNCTIONS
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL INLINE FUNCTIONS
**********************************************************************************************************************/


/**********************************************************************************************************************
  GLOBAL FUNCTIONS
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTIONS
**********************************************************************************************************************/


