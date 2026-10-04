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
/*!        \file  NvM_WriteAllFsm.h
 *        \brief  NvM_WriteAllFsm header file
 *      \details  Implementation of write all state machine
 *         \unit  NvM_WriteAllFsm
 **********************************************************************************************************************/

#if !defined (NVM_WRITEALLFSM_H)
# define NVM_WRITEALLFSM_H

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
 * NvM_WriteAllFsm_WriteAll()
 *********************************************************************************************************************/
/*!  \brief       WriteAll service API.
 *   \details     Will spawn a FSM executing the requested service.
 *   \param[in]   partitionId      Partition ID.
 *   \pre         -
 *   \context     TASK
 *   \reentrant   FALSE
 *   \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, NVM_PRIVATE_CODE) NvM_WriteAllFsm_WriteAll(NvM_PartitionIdType partitionId);

/**********************************************************************************************************************
 * NvM_WriteAllFsm_GetCurrentProcessedBlockDescriptorLookupTableId()
 *********************************************************************************************************************/
/*!  \brief       Get currently processed block descriptor lookup table id.
 *   \details     The user must check if NVM_BLOCK_COUNT is returned,
 *                because this is no valid block ID and
 *                can lead to out-of-bound array access.
 *   \param[in]   partitionId      Partition ID.
 *   \return      Current processed block descriptor lookup table id.
 *   \pre         -
 *   \context     TASK
 *   \reentrant   FALSE
 *   \synchronous TRUE
 *********************************************************************************************************************/
FUNC(NvM_BlockDescriptorLookupTableIdType, NVM_PRIVATE_CODE)
    NvM_WriteAllFsm_GetCurrentProcessedBlockDescriptorLookupTableId(NvM_PartitionIdType partitionId);

#if (NVM_JOB_PRIORITIZATION == STD_ON)
/**********************************************************************************************************************
 * NvM_WriteAllFsm_NotifyImmediateJobInterrupt()
 *********************************************************************************************************************/
/*!  \brief       Notifies the WriteAllFsm about an immediate job interrupt.
 *   \details     Notification for the WriteAllFsm to set the WriteAllFsm on hold by making a transition into
 *                the resume state. The WriteAll Fsm is no longer processed in case an immediate interruption occurred.
 *                In case the processing of the multi block job stack is continued
 *                (after the immediate job is finished), a transition from the resume state
 *                back to the appropriate state (according to the last processed block) is made.
 *   \pre         -
 *   \param[in]   partitionId      Partition ID.
 *   \context     TASK
 *   \reentrant   FALSE
 *   \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, NVM_PRIVATE_CODE) NvM_WriteAllFsm_NotifyImmediateJobInterrupt(const NvM_PartitionIdType partitionId);
#endif /* NVM_JOB_PRIORITIZATION == STD_ON */

#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* NVM_WRITEALLFSM_H */

/***********************************************************************************************************************
 *  END OF FILE: NvM_WriteAllFsm.h
 **********************************************************************************************************************/
