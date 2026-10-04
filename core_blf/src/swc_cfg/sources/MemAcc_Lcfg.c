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
 *            Module: MemAcc
 *           Program: MSR_Geely_SLP2
 *          Customer: Marelli Automotive Electronics (Guangzhou) Co., Ltd
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: CYT2B75BA
 *    License Scope : The usage is restricted to CBD2600619_D00
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: MemAcc_Lcfg.c
 *   Generation Time: 2026-07-29 15:28:48
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


#define MEMACC_LCFG_C

/**********************************************************************************************************************
 * MISRA JUSTIFICATION
 *********************************************************************************************************************/
/* PRQA S 0857 EOF */ /* MD_MSR_1.1_857 */
/* PRQA S 0779 EOF */ /* MD_CSL_0779 */

/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/
#include "MemAcc_Cfg.h"




/**********************************************************************************************************************
  GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/
# define MEMACC_START_SEC_CODE
# include "MemAcc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */



/**********************************************************************************************************************
  LOCAL FUNCTION PROTOTYPES
**********************************************************************************************************************/



#define MEMACC_STOP_SEC_CODE
#include "MemAcc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
  LOCAL CONSTANT MACROS
**********************************************************************************************************************/

/**********************************************************************************************************************
  LOCAL FUNCTION MACROS
**********************************************************************************************************************/

/**********************************************************************************************************************
  LOCAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/

/**********************************************************************************************************************
  LOCAL DATA PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: LOCAL DATA PROTOTYPES
**********************************************************************************************************************/


/**********************************************************************************************************************
  LOCAL DATA
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
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
  MemAcc_AddressArea
**********************************************************************************************************************/
/** 
  \var    MemAcc_AddressArea
  \details
  Element                   Description
  Priority              
  PriorityBasedIndex    
  SubAddressAreaEndIdx      the end index of the 1:n relation pointing to MemAcc_SubAddressArea
  SubAddressAreaStartIdx    the start index of the 1:n relation pointing to MemAcc_SubAddressArea
  AddressAreaId         
  ErrorNotification     
  JobEndNotification    
*/ 
#define MEMACC_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemAcc_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(MemAcc_AddressAreaType, MEMACC_CONST) MemAcc_AddressArea[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Priority  PriorityBasedIndex  SubAddressAreaEndIdx                                                           SubAddressAreaStartIdx                                                           AddressAreaId                                                             ErrorNotification  JobEndNotification        Referable Keys */
  { /*     0 */       0u,                 0u,                   1u  /* /ActiveEcuC/MemAcc/MemAccAddressAreaConfiguration */,                     0u  /* /ActiveEcuC/MemAcc/MemAccAddressAreaConfiguration */, MemAccConf_MemAccAddressAreaConfiguration_MemAccAddressAreaConfiguration, NULL_PTR         , NULL_PTR           }   /* [/ActiveEcuC/MemAcc/MemAccAddressAreaConfiguration] */
};
#define MEMACC_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemAcc_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  MemAcc_CLowerLayer
**********************************************************************************************************************/
/** 
  \var    MemAcc_CLowerLayer
  \details
  Element                  Description
  StaticMemBinaryHeader
*/ 
#define MEMACC_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemAcc_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(MemAcc_CLowerLayerType, MEMACC_CONST) MemAcc_CLowerLayer[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    StaticMemBinaryHeader                             Referable Keys */
  { /*     0 */ &Mem_30_LegacyAdapter_FunctionPointerTable }   /* [Mem_30_LegacyAdapter] */
};
#define MEMACC_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemAcc_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  MemAcc_GeneralFeatures
**********************************************************************************************************************/
/** 
  \var    MemAcc_GeneralFeatures
  \details
  Element              Description
  DevErrorDetection
  DevErrorReport   
*/ 
#define MEMACC_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemAcc_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(MemAcc_GeneralFeaturesType, MEMACC_CONST) MemAcc_GeneralFeatures[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    DevErrorDetection  DevErrorReport */
  { /*     0 */              TRUE,           TRUE }
};
#define MEMACC_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemAcc_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  MemAcc_MemInstance
**********************************************************************************************************************/
/** 
  \var    MemAcc_MemInstance
  \brief  Stores data related to MemInstance Configuration
  \details
  Element       Description
  InstanceId
  HardwareId
*/ 
#define MEMACC_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemAcc_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(MemAcc_MemInstanceType, MEMACC_CONST) MemAcc_MemInstance[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    InstanceId  HardwareId                    Referable Keys */
  { /*     0 */         0u, MEMACC_MEM_MEMINSTANCE }   /* [/ActiveEcuC/Mem/MemInstance] */
};
#define MEMACC_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemAcc_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  MemAcc_MemSectorBatch
**********************************************************************************************************************/
/** 
  \var    MemAcc_MemSectorBatch
  \brief  Stores MemSectorBatch sizes for Read/Write/Erase Operations.
  \details
  Element            Description
  EraseBurstSize 
  EraseSectorSize
  MaxReadSize    
  MinReadSize    
  WriteBurstSize 
  WritePageSize  
*/ 
#define MEMACC_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemAcc_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(MemAcc_MemSectorBatchType, MEMACC_CONST) MemAcc_MemSectorBatch[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    EraseBurstSize  EraseSectorSize  MaxReadSize  MinReadSize  WriteBurstSize  WritePageSize        Referable Keys */
  { /*     0 */          2048u,           2048u,       1024u,          1u,             4u,            4u }   /* [[2048, 1, 4, 1024, 4, 2048]] */
};
#define MEMACC_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemAcc_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  MemAcc_SubAddressArea
**********************************************************************************************************************/
/** 
  \var    MemAcc_SubAddressArea
  \details
  Element                 Description
  LogicalEndAddress   
  PhysicalEndAddress  
  PhysicalStartAddress
  UseEraseBurst       
  UseWriteBurst       
  LogicalStartAddress 
  LowerLayerIdx           the index of the 1:1 relation pointing to MemAcc_CLowerLayer
  MemInstanceIdx          the index of the 1:1 relation pointing to MemAcc_MemInstance
  MemSectorBatchIdx       the index of the 1:1 relation pointing to MemAcc_MemSectorBatch
  NumberOfEraseRetries
  NumberOfReadRetries 
  NumberOfSectors     
  NumberOfWriteRetries
  SectorOffset        
  SyncGroupId         
  AccessType          
*/ 
#define MEMACC_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemAcc_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(MemAcc_SubAddressAreaType, MEMACC_CONST) MemAcc_SubAddressArea[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    LogicalEndAddress  PhysicalEndAddress  PhysicalStartAddress  UseEraseBurst  UseWriteBurst  LogicalStartAddress  LowerLayerIdx                              MemInstanceIdx                                     MemSectorBatchIdx                                     NumberOfEraseRetries  NumberOfReadRetries  NumberOfSectors  NumberOfWriteRetries  SectorOffset  SyncGroupId  AccessType                              Referable Keys */
  { /*     0 */       0x00011FFFu,        0x14011FFFu,          0x14000000u,          TRUE,          TRUE,               0x00u,            0u  /* Mem_30_LegacyAdapter */,             0u  /* /ActiveEcuC/Mem/MemInstance */,                0u  /* [2048, 1, 4, 1024, 4, 2048] */,                   0u,                  0u,             36u,                   0u,           0u,          0u, MEMACC_MULTIBINARY_DIRECT_ACCESS }   /* [/ActiveEcuC/MemAcc/MemAccAddressAreaConfiguration] */
};
#define MEMACC_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemAcc_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  MemAcc_VLowerLayer
**********************************************************************************************************************/
/** 
  \var    MemAcc_VLowerLayer
  \details
  Element                           Description
  IndirectDynamicMemBinaryHeader
*/ 
#define MEMACC_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemAcc_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(MemAcc_VLowerLayerUType, MEMACC_VAR_NO_INIT) MemAcc_VLowerLayer;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [Mem_30_LegacyAdapter] */

#define MEMACC_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemAcc_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL DATA
**********************************************************************************************************************/


#define MEMACC_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
/* lint -save -esym(961, 19.1) */
#include "MemAcc_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/* lint -restore */

/*! On initialization token is set to Master */
MemAcc_MultiBinary_SynchronizationTokenType MemAcc_MultiBinary_SynchronizationToken = MEMACC_MULTIBINARY_MASTER_BINARY_ID;

/*! No MemAcc is configured as Satellite with REDIRECT access to Mem Driver, therefore no DataBuffer is needed. */





MemAcc_MultiBinary_AccessRequestType MemAcc_MultiBinary_AccessRequestSatellite_Id1 = /*!< request struct written by Satellite and read by Master */
{
  1u,                                                                            /*!< Id of Satellite Binary. */
  (MemAcc_MultiBinary_AtomicPublishedRequestType) MEMACC_MULTIBINARY_NO_REQUEST, /*!< Type of request. */
  0u,                                                                            /*!< Priority. */
  NULL_PTR,                                                                      /*!< Pointer to the job step information. */
  NULL_PTR,                                                                      /*!< Pointer to the job step result. */
  NULL_PTR                                                                       /*!< Pointer to a data buffer for data transfer in case of a redirect job step request. */
};

#define MEMACC_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
/* lint -save -esym(961, 19.1) */
#include "MemAcc_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/* lint -restore */

#define MEMACC_START_SEC_VAR_INIT_UNSPECIFIED
/* lint -save -esym(961, 19.1) */
#include "MemAcc_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/* lint -restore */

MemAcc_MultiBinary_SynchronizationTokenType* const MemAcc_MultiBinary_SynchronizationTokenPtr = &MemAcc_MultiBinary_SynchronizationToken;
MemAcc_MultiBinary_AccessRequestType* const MemAcc_MultiBinary_AccessRequestPtr = &MemAcc_MultiBinary_AccessRequestMaster_Id0;

MemAcc_MultiBinary_AccessRequestType MemAcc_MultiBinary_AccessRequestMaster_Id0 = /*!< Request struct written and read by Master. */
{
  0u,                                                                            /*!< Id of Master Binary. */
  (MemAcc_MultiBinary_AtomicPublishedRequestType) MEMACC_MULTIBINARY_NO_REQUEST, /*!< Type of published request. */
  0u,                                                                            /*!< Priority of the request. */
  NULL_PTR,                                                                      /*!< Pointer to the job step information. */
  NULL_PTR,                                                                      /*!< Pointer to the job step result. */
  NULL_PTR                                                                       /*!< Pointer to a data buffer for data transfer in case of a redirect job step request. */
};

MemAcc_MultiBinary_AccessRequestType* const MemAcc_MultiBinary_AccessRequests[MEMACC_MULTIBINARY_NR_Of_BINARIES] = /*!< multiBinary access request Queue */
{
  &MemAcc_MultiBinary_AccessRequestMaster_Id0,    
  &MemAcc_MultiBinary_AccessRequestSatellite_Id1  
};

#define MEMACC_STOP_SEC_VAR_INIT_UNSPECIFIED
/* lint -save -esym(961, 19.1) */
#include "MemAcc_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/* lint -restore */

/**********************************************************************************************************************
  LOCAL FUNCTIONS
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL FUNCTIONS
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL FUNCTIONS
**********************************************************************************************************************/


/**********************************************************************************************************************
  END OF FILE: MemAcc_Lcfg.c
**********************************************************************************************************************/

