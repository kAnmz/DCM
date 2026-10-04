/***********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2026 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!        \file  NvM_ServiceProcessorFsm.h
 *        \brief  NvM_ServiceProcessorFsm header file
 *      \details  Implementation of service base state machine
 *         \unit  NvM_ServiceProcessorFsm
 **********************************************************************************************************************/


#if !defined (NVM_SERVICEPROCESSORFSM_H)
# define NVM_SERVICEPROCESSORFSM_H

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
#include "NvM_InternalTypes.h"

/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/
#define NVM_START_SEC_CODE
#include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * NvM_ServiceProcessorFsm_Spawn()
 *********************************************************************************************************************/
/*!  \brief       ServiceProcessorFsm service API.
 *   \details     Will spawn the service Processor FSM.
 *   \param[in]   partitionId      Partition ID.
 *   \pre         -
 *   \context     TASK
 *   \reentrant   FALSE
 *   \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, NVM_PRIVATE_CODE) NvM_ServiceProcessorFsm_Spawn(NvM_PartitionIdType partitionId);

#if (NVM_JOB_PRIORITIZATION == STD_ON)
/**********************************************************************************************************************
 * NvM_ServiceProcessorFsm_IsImmediateJobActive()
 *********************************************************************************************************************/
/*!  \brief       Check if an immediate job is requested.
 *   \details     -
 *   \pre         -
 *   \param[in]   partitionId      Partition ID.
 *   \context     TASK
 *   \reentrant   FALSE
 *   \synchronous TRUE
 *   \return      TRUE if an immediate job is requested, FALSE otherwise.
 *********************************************************************************************************************/
FUNC(boolean, NVM_PRIVATE_CODE) NvM_ServiceProcessorFsm_IsImmediateJobActive(const NvM_PartitionIdType partitionId);
#endif /* (NVM_JOB_PRIORITIZATION == STD_ON) */
#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* NVM_SERVICEPROCESSORFSM_H */

/***********************************************************************************************************************
 *  END OF FILE: NvM_ServiceProcessorFsm.h
 **********************************************************************************************************************/
