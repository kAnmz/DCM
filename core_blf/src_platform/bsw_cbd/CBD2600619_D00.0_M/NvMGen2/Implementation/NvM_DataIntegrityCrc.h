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
/*!        \file  NvM_DataIntegrityCrc.h
 *        \brief  NvM_DataIntegrityCrc header file
 *      \details  Implementation of data integrity state machine
 *         \unit  NvM_DataIntegrityCrc
 **********************************************************************************************************************/


#ifndef NVM_DATAINTEGRITYCRC_H
#define NVM_DATAINTEGRITYCRC_H

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
 *  NvM_DataIntegrityCrc_Init
 *********************************************************************************************************************/
/*!
 * \brief           Initialize a CRC job structure with provided parameters
 * \details         Sets job status to PENDING, configures CRC strategy based on data integrity type and initializes 
 *                  CRC context fields.
 * \param[in,out]   Instance          Pointer to CRC job structure to initialize
 * \pre             Instance pointer generic information MUST be setup correctly by the user of this unit.  
 * \config          -
 * \context         TASK
 * \reentrant       FALSE
 * \synchronous     TRUE
 */
extern FUNC(void, NVM_PRIVATE_CODE) NvM_DataIntegrityCrc_Init(
  NvM_DataIntegrityService_InstancePtrType Instance
);

/**********************************************************************************************************************
 *  NvM_DataIntegrityCrc_Process
 *********************************************************************************************************************/
/*!
 * \brief           Process a pending CRC job
 * \details         Executes CRC generation or verification job. Updates job status based on result. 
 *                  The generation job always completes successfully. Hence, the job status will never be UNSUCCESSFUL 
 *                  for generation.
 * \param[in,out]   Instance          Pointer to CRC job structure
 * \pre             Instance must point to initialized CRC job structure
 * \config          -
 * \context         TASK
 * \reentrant       FALSE
 * \synchronous     TRUE
 */
extern FUNC(void, NVM_PRIVATE_CODE) NvM_DataIntegrityCrc_Process(
  NvM_DataIntegrityService_InstancePtrType Instance
);

# define NVM_STOP_SEC_CODE
# include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* NVM_DATAINTEGRITYCRC_H */

/**********************************************************************************************************************
 *  END OF FILE: NvM_DataIntegrityCrc.h
 *********************************************************************************************************************/
