/**********************************************************************************************************************
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
/*!        \file  NvM_NvJobDispatcherFsm.h
 *        \brief  NvM_NvJobDispatcherFsm header file
 *      \details  Header of NvM_NvJobDispatcherFsm unit. This unit manages incoming upper layer service requests
 *                and dispatches the relevant NvBlock FSM.
 *         \unit  NvM_NvJobDispatcherFsm
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#if !defined (NVM_NVJOBDISPATCHERFSM_H)
# define NVM_NVJOBDISPATCHERFSM_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
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

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
# define NVM_START_SEC_CODE
# include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * NvM_NvJobDispatcherFsm_Execute()
 *********************************************************************************************************************/
/*! \brief       Nv Job Dispatcher execute service API.
 *  \details     Will spawn a FSM executing the requested service.
 *  \param[in]   singleBlockJobContext      Pointer to executed job context information.
 *  \param[in]   partitionId     Partition ID.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \spec
 *    requires partitionId == NVM_PARTITION_ID_MASTER;
 * \endspec
 *********************************************************************************************************************/
FUNC(void, NVM_PRIVATE_CODE) NvM_NvJobDispatcherFsm_Execute(
    NvM_SingleBlockJobContextPtrToConstType singleBlockJobContext,
    NvM_PartitionIdType partitionId);


# define NVM_STOP_SEC_CODE
# include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* NVM_NVJOBDISPATCHERFSM_H */

/**********************************************************************************************************************
 *  END OF FILE: NvM_NvJobDispatcherFsm.h
 *********************************************************************************************************************/
