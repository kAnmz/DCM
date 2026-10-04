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
/*!        \file  NvM_MultiBlockJobFsm.h
 *        \brief  NvM_MultiBlockJobFsm header file
 *      \details  Implementation of service base state machine
 *         \unit  NvM_MultiBlockJobFsm
 **********************************************************************************************************************/


#if !defined (NVM_MULTIBLOCKJOBFSM_H)
# define NVM_MULTIBLOCKJOBFSM_H

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
 * NvM_MultiBlockJobFsm_Spawn()
 *********************************************************************************************************************/
/*!  \brief       MultiBlockJobFsm service API.
 *   \details     Will spawn the service FSM.
 *   \param[in]   partitionId      Partition ID.
 *   \pre         -
 *   \context     TASK
 *   \reentrant   FALSE
 *   \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, NVM_PRIVATE_CODE) NvM_MultiBlockJobFsm_Spawn(NvM_PartitionIdType partitionId);

#if (NVM_JOB_PRIORITIZATION == STD_ON)
/**********************************************************************************************************************
 * NvM_MultiBlockJobFsm_NotifyImmediateJobInterrupt()
 *********************************************************************************************************************/
/*!  \brief       Notifies the MultiBlockJobFsm about an immediate job interrupt.
 *   \details     This API is used to notify that a currentactive multi block job
 *                has to be resumed after an immediate interruption.
 *                It acts as a dispatcher for notifying the appropriate FSM (ReadAll resp. WriteAllFsm).
 *   \pre         -
 *   \param[in]   partitionId      Partition ID.
 *   \context     TASK
 *   \reentrant   FALSE
 *   \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, NVM_PRIVATE_CODE) NvM_MultiBlockJobFsm_NotifyImmediateJobInterrupt(const NvM_PartitionIdType partitionId);
#endif /* (NVM_JOB_PRIORITIZATION == STD_ON) */

#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* NVM_MultiBlockJobFsm_H */

/***********************************************************************************************************************
 *  END OF FILE: NvM_MultiBlockJobFsm.h
 **********************************************************************************************************************/
