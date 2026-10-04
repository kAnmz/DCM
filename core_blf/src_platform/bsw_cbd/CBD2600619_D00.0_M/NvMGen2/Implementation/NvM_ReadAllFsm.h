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
/*!        \file  NvM_ReadAllFsm.h
 *        \brief  NvM_ReadAllFsm header file
 *      \details  Implementation of read all state machine
 *         \unit  NvM_ReadAllFsm
 **********************************************************************************************************************/

#if !defined (NVM_READALLFSM_H)
# define NVM_READALLFSM_H

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
#include "NvM_Types.h"
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
 * NvM_ReadAllFsm_ReadAll()
 *********************************************************************************************************************/
/*!  \brief       ReadAll service API.
 *   \details     Will spawn a FSM executing the requested service.
 *   \param[in]   partitionId      Partition ID.
 *   \pre         -
 *   \context     TASK
 *   \reentrant   FALSE
 *   \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, NVM_PRIVATE_CODE) NvM_ReadAllFsm_ReadAll(NvM_PartitionIdType partitionId);

/**********************************************************************************************************************
 * NvM_ReadAllFsm_GetCurrentProcessedBlockDescriptorLookupTableId()
 *********************************************************************************************************************/
/*!  \brief       Get currently processed block descriptor look up table id.
 *   \details     -
 *   \param[in]   partitionId      Partition ID.
 *   \pre         -
 *   \context     TASK
 *   \reentrant   FALSE
 *   \synchronous TRUE
 *********************************************************************************************************************/
FUNC(NvM_BlockDescriptorLookupTableIdType, NVM_PRIVATE_CODE)
    NvM_ReadAllFsm_GetCurrentProcessedBlockDescriptorLookupTableId(NvM_PartitionIdType partitionId);

#if (NVM_JOB_PRIORITIZATION == STD_ON)
/**********************************************************************************************************************
 * NvM_ReadAllFsm_NotifyImmediateJobInterrupt()
 *********************************************************************************************************************/
/*!  \brief       Notifies the ReadAllFsm about an immediate job interrupt.
 *   \details     Notification for the ReadAllFsm to set the ReadAllFsm on hold by making a transition into
 *                the resume state. The ReadAll Fsm is no longer processed in case an immediate interruption occurred.
 *                In case the processing of the multi block job stack is continued
 *                (after the immediate job is finished), a transition from the resume state
 *                back to the appropriate state (according to the last processed block) is made.
 *   \pre         -
 *   \param[in]   partitionId      Partition ID.
 *   \context     TASK
 *   \reentrant   FALSE
 *   \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, NVM_PRIVATE_CODE) NvM_ReadAllFsm_NotifyImmediateJobInterrupt(const NvM_PartitionIdType partitionId);
#endif /* NVM_JOB_PRIORITIZATION == STD_ON */

#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* NVM_READALLFSM_H */

/***********************************************************************************************************************
 *  END OF FILE: NvM_ReadAllFsm.h
 **********************************************************************************************************************/
