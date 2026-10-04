/***********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2025 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!        \file  NvM_DataIntegrityMac.h
 *        \brief  NvM_DataIntegrityMac header file
 *      \details  Implementation of data integrity state machine
 *         \unit  NvM_DataIntegrityMac
 **********************************************************************************************************************/


#ifndef NVM_DATAINTEGRITYMAC_H
#define NVM_DATAINTEGRITYMAC_H

#include "NvM_CfgDefines.h"

#if (NVM_MAC_ENABLED == STD_ON) /* COV_MSR_UT_OPTIONAL_UNIT */
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "NvM_InternalTypes.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
# define NVM_START_SEC_CODE
# include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  NvM_DataIntegrityMac_Init
 *********************************************************************************************************************/
/*!
 * \brief           Initialize a MAC job structure with provided parameters
 * \details         Sets up job type, status, CSM configuration, and data pointers for MAC generation or verification
 * \param[in,out]   Instance          Pointer to MAC job structure to initialize
 * \param[in]       CsmJobId          CSM job identifier
 * \param[in]       BlockMacLength    Length of MAC in bytes
 * \pre             Instance pointer generic information MUST be setup correctly by the user of this unit.  
 * \config          -
 * \context         TASK
 * \reentrant       FALSE
 * \synchronous     TRUE
 */
extern FUNC(void, NVM_PRIVATE_CODE) NvM_DataIntegrityMac_Init(
  NvM_DataIntegrityService_InstancePtrType Instance,
  NvM_CsmJobIdType CsmJobId,
  uint16 BlockMacLength
);

/**********************************************************************************************************************
 *  NvM_DataIntegrityMac_Process
 *********************************************************************************************************************/
/*!
 * \brief           Process a pending MAC job
 * \details         Attempts to execute CSM MAC generation or verification job. Updates job status based on result.
 *                  Retries up to NVM_CSM_RETRY_COUNT times if CSM is busy.
 * \param[in,out]   Instance          Pointer to MAC job structure
 * \pre             Instance must point to initialized MAC job structure
 * \config          -
 * \context         TASK
 * \reentrant       FALSE
 * \synchronous     TRUE
 */
extern FUNC(void, NVM_PRIVATE_CODE) NvM_DataIntegrityMac_Process(
  NvM_DataIntegrityService_InstancePtrType Instance
);

# define NVM_STOP_SEC_CODE
# include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* NVM_MAC_ENABLED == STD_ON */

#endif /* NVM_DATAINTEGRITYMAC_H */

/**********************************************************************************************************************
 *  END OF FILE: NvM_DataIntegrityMac.h
 *********************************************************************************************************************/
