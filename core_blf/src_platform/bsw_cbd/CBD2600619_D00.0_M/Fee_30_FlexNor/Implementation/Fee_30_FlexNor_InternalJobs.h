/**********************************************************************************************************************
 *  COPYRIGHT
 *  --------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2025 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  --------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/*!        \file  Fee_30_FlexNor_InternalJobs.h
 *        \brief  Internal jobs interface
 *      \details  Provides the interface for accessing and handling the internal jobs.
 *         \unit  InternalJobs
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 **********************************************************************************************************************/

#if !defined(FEE_30_FLEXNOR_INTERNALJOBS_H)
# define FEE_30_FLEXNOR_INTERNALJOBS_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "Fee_30_FlexNor_Types.h"
# include "Fee_30_FlexNor_ConfigInterface.h"

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
# define FEE_30_FLEXNOR_START_SEC_CODE
# include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Fee_30_FlexNor_InternalJobs_Init()
 *********************************************************************************************************************/
/*! \brief       Initialize the internal jobs unit
 *  \details     -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_InternalJobs_Init(void);

/**********************************************************************************************************************
 * Fee_30_FlexNor_InternalJobs_Run()
 *********************************************************************************************************************/
/*! \brief       Checks for pending internal jobs and starts processing them
 *  \details     -
 *  \param[in]   currentJob    Contains the job parameters
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous FALSE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_InternalJobs_Run(Fee_30_FlexNor_JobPtrType currentJob);

/**********************************************************************************************************************
 * Fee_30_FlexNor_InternalJobs_RequestRecoveryGarbageCollection()
 *********************************************************************************************************************/
/*! \brief       Requests a recovery of the given sector
 *  \details     -
 *  \param[in]   partitionId    Id of the partition that contains the sector that shall be recovered
 *  \param[in]   sectorAddress  Start address of the sector that shall be recovered - calling unit may also pass an 
 *                              address within the sector, not necessarily the start address.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_InternalJobs_RequestRecoveryGarbageCollection(
  Fee_30_FlexNor_PartitionIdType partitionId,
  Fee_30_FlexNor_AddressType sectorAddress);

/**********************************************************************************************************************
 * Fee_30_FlexNor_InternalJobs_SuspendRecoveryJobs()
 *********************************************************************************************************************/
/*! \brief       Enables/Disables suspension of recovery jobs.
 *  \details     -
 *  \param[in]   suspendRecoveryJobsEnabled  Flag indicating whether suspension of recovery jobs is enabled 
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_InternalJobs_SuspendRecoveryJobs(boolean suspendRecoveryJobsEnabled);

# define FEE_30_FLEXNOR_STOP_SEC_CODE
# include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* FEE_30_FLEXNOR_INTERNALJOBS_H */

/**********************************************************************************************************************
 *  END OF FILE: Fee_30_FlexNor_InternalJobs.h
 *********************************************************************************************************************/
