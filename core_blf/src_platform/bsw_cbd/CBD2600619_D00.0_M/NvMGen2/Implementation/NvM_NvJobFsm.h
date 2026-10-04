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
/*!        \file  NvM_NvJobFsm.h
 *        \brief  NvM_NvJobFsm header file
 *      \details  Header of NvM_NvJobFsm unit. This unit manages incoming upper layer service requests
 *                and provide only relevant informations to lower layers.
 *         \unit  NvM_NvJobFsm
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#if !defined (NVM_NVJOBFSM_H)
# define NVM_NVJOBFSM_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "NvM_Types.h"
#include "NvM_InternalTypes.h"

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
# define NVM_START_SEC_CODE
# include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * NvM_NvJobFsm_Execute()
 *********************************************************************************************************************/
/*! \brief       Nv Job execute API.
 *  \details     Will spawn a FSM executing the requested service. The requested service is determined based on the
 *               information provided within the single block job context.
 *  \param[in]   partitionId     Partition ID.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, NVM_PRIVATE_CODE) NvM_NvJobFsm_Execute(NvM_PartitionIdType partitionId);

# define NVM_STOP_SEC_CODE
# include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* NVM_NVJOBFSM_H */

/**********************************************************************************************************************
 *  END OF FILE: NvM_NvJobFsm.h
 *********************************************************************************************************************/
