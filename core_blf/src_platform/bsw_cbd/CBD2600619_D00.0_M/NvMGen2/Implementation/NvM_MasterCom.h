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
/*!        \file  NvM_MasterCom.h
 *        \brief  NvM_MasterCom header file
 *      \details  Header of NvM_MasterCom unit. This unit manages incoming upper layer service requests
 *                and dispatches the relevant NvBlock FSM.
 *         \unit  NvM_MasterCom
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#if !defined (NVM_MASTERCOM_H)
# define NVM_MASTERCOM_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "NvM_CfgDefines.h"

#if (NVM_MULTIPARTITION_USAGE_SCENARIO == STD_ON) /* COV_MSR_UT_OPTIONAL_UNIT */

#include "NvM_InternalTypes.h"
#include "NvM_Cfg.h"

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
 * NvM_MasterCom_CleanupAcknowledgedSingleBlockJobSatellitePorts()
 *********************************************************************************************************************/
/*! \brief           Scans for satellite-ports that have acknowledged a finalized job and resets the corresponding
 *                   master-satellite-port.
 *  \details         -
 *  \pre             -
 *  \context         TASK
 *  \reentrant       FALSE
 *  \synchronous     TRUE
 *********************************************************************************************************************/
FUNC(void, NVM_PRIVATE_CODE) NvM_MasterCom_CleanupAcknowledgedSingleBlockJobSatellitePorts(void);

/**********************************************************************************************************************
 * NvM_MasterCom_AcceptSingleBlockJobRequest()
 *********************************************************************************************************************/
/*! \brief           Scans for satellite-ports that are requesting a job to be executed, chooses one and accepts it.
 *  \details         A round-robin principle is applied by choosing from multiple ports.
 *  \pre             acceptedJobPtr->DataBuffer must not be NULL.
 *  \param[out]      acceptedJobPtr    Out-parameter holding the accepted job information, if function returns E_OK.
 *                                     Must not be NULL.
 *  \context         TASK
 *  \reentrant       FALSE
 *  \synchronous     TRUE
 *  \return          E_OK:     A job was found and accepted.
 *                   E_NOT_OK: No request was found.
 *********************************************************************************************************************/
FUNC(Std_ReturnType, NVM_PRIVATE_CODE) NvM_MasterCom_AcceptSingleBlockJobRequest(
  NvM_SingleBlockJobContextPtrType acceptedJobPtr);

/**********************************************************************************************************************
 * NvM_MasterCom_FinalizeActiveSingleBlockJobRequest()
 *********************************************************************************************************************/
/*! \brief           Finalize active job by propagating the given result.
 *  \details         No check for an active job is done.
 *  \param[in]       result               Result of the processed job.
 *  \pre             NvM_MasterCom_AcceptSingleBlockJobRequest() must have been successfully performed.
 *  \context         TASK
 *  \reentrant       FALSE
 *  \synchronous     TRUE
 *********************************************************************************************************************/
FUNC(void, NVM_PRIVATE_CODE) NvM_MasterCom_FinalizeActiveSingleBlockJobRequest(
  const NvM_ServiceJobResultType result);

/**********************************************************************************************************************
 * NvM_MasterCom_BroadcastMultiBlockRequestToSatellites()
 *********************************************************************************************************************/
/*! \brief           Broadcast a multiblock job request to all satellites.
 *  \details         -
 *  \param[in]       jobType               Job Type that is requested.
 *  \pre             -
 *  \context         TASK
 *  \reentrant       FALSE
 *  \synchronous     TRUE
 *********************************************************************************************************************/
FUNC(void, NVM_PRIVATE_CODE) NvM_MasterCom_BroadcastMultiBlockRequestToSatellites(
  const NvM_MultiBlockJobType jobType);

/**********************************************************************************************************************
 * NvM_MasterCom_StartMultiBlockJobProcessing()
 *********************************************************************************************************************/
/*! \brief       Start processing of multiblock job of given satellite.
 *  \details     -
 *  \param[in]   targetSatellitePartitionId               Partition ID of target satellite.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, NVM_PRIVATE_CODE) NvM_MasterCom_StartMultiBlockJobProcessing(
  const NvM_PartitionIdType targetSatellitePartitionId);

/**********************************************************************************************************************
 * NvM_MasterCom_StartMultiBlockJobProcessingInParallel()
 *********************************************************************************************************************/
/*! \brief       Start processing of multiblock job of all satellite.
 *  \details     The parallel processing is done to not waste any main function cycles.
 *               Possible because no MemIf access is necessary.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, NVM_PRIVATE_CODE) NvM_MasterCom_StartMultiBlockJobProcessingInParallel(void);

/**********************************************************************************************************************
 * NvM_MasterCom_GetMultiBlockJobStatus()
 *********************************************************************************************************************/
/*! \brief       Gets the status of requested multi block job of given satellite.
 *  \details     -
 *  \param[in]   targetSatellitePartitionId               Partition ID of target satellite.
 *  \pre         -
 *  \return      Job Status of given satellite.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(NvM_SatelliteMultiBlockJobStatusType, NVM_PRIVATE_CODE) NvM_MasterCom_GetMultiBlockJobStatus(
  const NvM_PartitionIdType targetSatellitePartitionId);

/**********************************************************************************************************************
 * NvM_MasterCom_AreAllSatellitesFinishedWithMultiBlockJob()
 *********************************************************************************************************************/
/*! \brief       Gets the information whether all satellites are finished with multi block job processing.
 *  \details     -
 *  \pre         -
 *  \return      TRUE if all satellites are finished with multi block job processing, FALSE otherwise.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(boolean, NVM_PRIVATE_CODE) NvM_MasterCom_AreAllSatellitesFinishedWithMultiBlockJob(void);

/**********************************************************************************************************************
 * NvM_MasterCom_ResetMultiBlockJobPorts()
 *********************************************************************************************************************/
/*! \brief       Reset each multiblock job master - satellite port.
 *  \details     -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, NVM_PRIVATE_CODE) NvM_MasterCom_ResetMultiBlockJobPorts(void);

/**********************************************************************************************************************
 * NvM_MasterCom_DetermineDemErrorCount()
 *********************************************************************************************************************/
/*! \brief       Determine the error count which has to be reported to the DEM for the given error.
 *  \details     -
 *  \param[in]   error               DEM error whose error count must be determined.
 *  \pre         -
 *  \return      Error count which must be reported.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(uint16, NVM_PRIVATE_CODE) NvM_MasterCom_DetermineDemErrorCount(const NvM_DemErrorIdType error);

#if (NVM_JOB_PRIORITIZATION == STD_ON)

/**********************************************************************************************************************
 * NvM_MasterCom_IsAnyImmediateJobRequested()
 *********************************************************************************************************************/
/*! \brief       Determine if an immediate job is requested on any partition.
 *  \details     This function is necessary to decide wether the NvStack needs to be cleaned up
 *               to process an immediate job.
 *  \pre         No immediate job is currently processed.
 *  \return      TRUE if an immediate job is requested on any partition, FALSE otherwise.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(boolean, NVM_PRIVATE_CODE) NvM_MasterCom_IsAnyImmediateJobRequested(void);

/**********************************************************************************************************************
 * NvM_MasterCom_IsImmediateJobRequestedForPartition()
 *********************************************************************************************************************/
/*! \brief       Determine if an immediate job is requested for the given partition.
 *  \details     -
 *  \param[in]   targetSatellitePartitionId   Partition ID to check for an immediate job request.
 *  \pre         -
 *  \return      TRUE if an immediate job is requested for the given partition, FALSE otherwise.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(boolean, NVM_PRIVATE_CODE) NvM_MasterCom_IsImmediateJobRequestedForPartition( 
  const NvM_PartitionIdType targetSatellitePartitionId);

/**********************************************************************************************************************
 * NvM_MasterCom_IsAnyImmediateJobReadyForNvProcessing()
 *********************************************************************************************************************/
/*! \brief       Determine if any immediate job is ready for NV processing.
 *  \details     -
 *  \pre         -
 *  \return      TRUE if any immediate job is ready for NV processing, FALSE otherwise.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(boolean, NVM_PRIVATE_CODE) NvM_MasterCom_IsAnyImmediateJobReadyForNvProcessing(void);

/**********************************************************************************************************************
 * NvM_MasterCom_ResetMasterSatellitePort()
 *********************************************************************************************************************/
/*! \brief       Resets the requested master satellite port.
 *  \details     -
 *  \param[in]   targetSatellitePartitionId    Partition ID of the master satellite port to reset.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, NVM_PRIVATE_CODE) NvM_MasterCom_ResetMasterSatellitePort(
  const NvM_PartitionIdType targetSatellitePartitionId);

#endif

# define NVM_STOP_SEC_CODE
# include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* NVM_MULTIPARTITION_USAGE_SCENARIO */

#endif /* NVM_MASTERCOM_H */

/**********************************************************************************************************************
 *  END OF FILE: NvM_MasterCom.h
 *********************************************************************************************************************/
