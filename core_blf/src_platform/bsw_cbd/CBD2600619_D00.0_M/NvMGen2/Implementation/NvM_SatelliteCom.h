/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2026 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!        \file  NvM_SatelliteCom.h
 *        \brief  NvM satellite communication header file.
 *         \unit  NvM_SatelliteCom
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#if (!defined NVM_SATELLITECOM_H)
#define NVM_SATELLITECOM_H

/***********************************************************************************************************************
 * INCLUDES
 **********************************************************************************************************************/
#include "NvM_CfgDefines.h"

#if (NVM_MULTIPARTITION_USAGE_SCENARIO == STD_ON) /* COV_MSR_UT_OPTIONAL_UNIT */

#include "NvM_InternalTypes.h"

/***********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
# define NVM_START_SEC_CODE
# include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * NvM_SatelliteCom_RequestSingleBlockJob()
 *********************************************************************************************************************/
/*! \brief       Requests a single block job via the SatellitePort at the master.
 *  \details     Only NvJobFsm is allowed to call this function. Therefore, the FSM ensures
 *               that no other request is PENDING when calling this function.
 *  \param[in]   singleBlockJobContext Single Block Job context of job to be requested.
 *  \param[in]   partitionId Partition ID.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, NVM_PRIVATE_CODE) NvM_SatelliteCom_RequestSingleBlockJob(
  NvM_SingleBlockJobContextPtrToConstType singleBlockJobContext,
  const NvM_PartitionIdType partitionId);


/**********************************************************************************************************************
 * NvM_SatelliteCom_GetSingleBlockJobStatus()
 *********************************************************************************************************************/
/*! \brief       Gets the status of requested single block job.
 *  \details     -
 *  \param[in]   partitionId Partition ID.
 *  \pre         -
 *  \return      Service job result of job.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(NvM_ServiceJobResultType, NVM_PRIVATE_CODE) NvM_SatelliteCom_GetSingleBlockJobStatus(
  const NvM_PartitionIdType partitionId);

/**********************************************************************************************************************
 * NvM_SatelliteCom_FinalizeSingleBlockJob()
 *********************************************************************************************************************/
/*! \brief       Finalize the requested single block job.
 *  \details     -
 *  \param[in]   partitionId Partition ID.
 *  \pre         Requested single block job status != PENDING
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, NVM_PRIVATE_CODE) NvM_SatelliteCom_FinalizeSingleBlockJob(const NvM_PartitionIdType partitionId);

/**********************************************************************************************************************
 * NvM_SatelliteCom_GetMultiBlockJobStatus()
 *********************************************************************************************************************/
/*! \brief           Returns the current master-satellite job status.
 *  \details         -
 *  \param[in]       partitionId  Partition ID.
 *  \pre             -
 *  \context         TASK
 *  \reentrant       FALSE
 *  \synchronous     TRUE
 *  \return          NONE, REQUESTED, PROCESSING
 *********************************************************************************************************************/
FUNC(NvM_MasterMultiBlockJobRequestType, NVM_PRIVATE_CODE) NvM_SatelliteCom_GetMultiBlockJobStatus(
  const NvM_PartitionIdType partitionId);

/**********************************************************************************************************************
 * NvM_SatelliteCom_GetRequestedMultiBlockJob()
 *********************************************************************************************************************/
/*! \brief           Returns a requested multiblock job information.
 *  \details         -
 *  \param[in]       partitionId Partition ID.
 *  \pre             Shall only be used when NvM_SatelliteCom_GetMultiBlockJobStatus() returns REQUESTED.
 *  \context         TASK
 *  \reentrant       FALSE
 *  \synchronous     TRUE
 *  \return          The requested multiblock job.
 *********************************************************************************************************************/
FUNC(NvM_MultiBlockJobType, NVM_PRIVATE_CODE) NvM_SatelliteCom_GetRequestedMultiBlockJob(
  const NvM_PartitionIdType partitionId);

/**********************************************************************************************************************
 * NvM_SatelliteCom_SetMultiBlockJobStatus()
 *********************************************************************************************************************/
/*! \brief           Updates the satellites port job status.
 *  \details         -
 *  \param[in]       status      Status information to set on the satellite-port
 *  \param[in]       partitionId Partition ID.
 *  \pre             -
 *  \context         TASK
 *  \reentrant       FALSE
 *  \synchronous     TRUE
 *********************************************************************************************************************/
FUNC(void, NVM_PRIVATE_CODE) NvM_SatelliteCom_SetMultiBlockJobStatus(
  const NvM_SatelliteMultiBlockJobStatusType status,
  const NvM_PartitionIdType partitionId);

/**********************************************************************************************************************
 * NvM_SatelliteCom_IncrementDemErrorCount()
 *********************************************************************************************************************/
/*! \brief           Increments the given DEM error count.
 *  \details         -
 *  \param[in]       error       DEM error to be incremented.
 *  \param[in]       partitionId Partition ID.
 *  \pre             -
 *  \context         TASK
 *  \reentrant       FALSE
 *  \synchronous     TRUE
 *********************************************************************************************************************/
FUNC(void, NVM_PRIVATE_CODE) NvM_SatelliteCom_IncrementDemErrorCount(
  const NvM_DemErrorIdType error,
  const NvM_PartitionIdType partitionId);

#if (NVM_JOB_PRIORITIZATION == STD_ON)

/**********************************************************************************************************************
 * NvM_SatelliteCom_PropagateImmediateBlockJob()
 *********************************************************************************************************************/
/*! \brief       Propagate an immediate block job via the SatellitePort at the master.
 *  \details     This function gets called as soon as an immediate job is popped from the queue.
 *  \param[in]   partitionId Partition ID.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, NVM_PRIVATE_CODE) NvM_SatelliteCom_PropagateImmediateBlockJob(
  const NvM_PartitionIdType partitionId);

#endif /* (NVM_JOB_PRIORITIZATION == STD_ON) */

# define NVM_STOP_SEC_CODE
# include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* NVM_MULTIPARTITION_USAGE_SCENARIO */

#endif  /* NVM_SATELLITECOM_H */

/***********************************************************************************************************************
 *  END OF FILE: NvM_SatelliteCom.h
 **********************************************************************************************************************/
