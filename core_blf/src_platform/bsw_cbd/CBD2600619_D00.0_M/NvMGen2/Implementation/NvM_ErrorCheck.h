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
/*!        \file  NvM_ErrorCheck.h
 *        \brief  NvM_ErrorCheck header file
 *      \details  Header of the error check unit of the NvM. This unit takes care of DET and DEM error handling.
 *         \unit  NvM_ErrorCheck
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#if !defined (NVM_ERRORCHECK_H)
# define NVM_ERRORCHECK_H

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
 * NvM_ErrorCheck_IsDetConditionTrue()
 *********************************************************************************************************************/
/*! \brief       Checks if the given condition evaluates to TRUE and DET checking is enabled.
 *  \details     -
 *  \param[in]   condition  Condition to check.
 *  \return      TRUE   The condition evaluates to TRUE and DET is enabled.
 *               FALSE  The condition evaluates to FALSE or DET is disabled.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(boolean, NVM_PRIVATE_CODE) NvM_ErrorCheck_IsDetConditionTrue(const boolean condition);

/**********************************************************************************************************************
 * NvM_ErrorCheck_ReportDetErrorConditionally()
 *********************************************************************************************************************/
/*! \brief       Reports the given DET error if DET reporting is enabled.
 *  \details     -
 *  \param[in]   serviceId  ID of the service reporting the error.
 *  \param[in]   error      Error code that needs to be reported.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, NVM_PRIVATE_CODE) NvM_ErrorCheck_ReportDetErrorConditionally(
  const uint8 serviceId,
  const NvM_DetErrorIdType error);

/**********************************************************************************************************************
 * NvM_ErrorChecks_ReportDetRuntimeErrorConditionally()
 *********************************************************************************************************************/
/*! \brief       Reports the given DET runtime error if DET reporting is enabled.
 *  \details     -
 *  \param[in]   serviceId  ID of the service reporting the error.
 *  \param[in]   error      Error code that needs to be reported.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, NVM_PRIVATE_CODE) NvM_ErrorCheck_ReportDetRuntimeErrorConditionally(
  const uint8 serviceId,
  const NvM_DetErrorIdType error);

/**********************************************************************************************************************
 * NvM_ErrorCheck_DispatchDemErrorConditionally()
 *********************************************************************************************************************/
/*! \brief       Dispatch the given error directly to the DEM.
 *  \details     Only dispatches the error if DEM reference is set.
 *  \param[in]   error DEM error to be dispatched.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, NVM_PRIVATE_CODE) NvM_ErrorCheck_DispatchDemErrorConditionally(const NvM_DemErrorIdType error);

/**********************************************************************************************************************
 * NvM_ErrorCheck_ReportDemError()
 *********************************************************************************************************************/
/*! \brief       Reports the given DEM error.
 *  \details     Single Partition Use Case: Reports error directly to the DEM.
 *               MultiPartition Use Case: Reports error to the master and master reports errors to the DEM.
 *               This function should only be called in the Application Service Layer, as only here
 *               it is necessary to differentiate between multipartition and single partition usage scenarios.
 *  \param[in]   error        DEM error to be reported.
 *  \param[in]   partitionId  Partition ID.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, NVM_PRIVATE_CODE) NvM_ErrorCheck_ReportDemError(
  const NvM_DemErrorIdType error,
  const NvM_PartitionIdType partitionId);

#if (NVM_MULTIPARTITION_USAGE_SCENARIO == STD_ON)
/**********************************************************************************************************************
 * NvM_ErrorCheck_DispatchDemErrorCountConditionally()
 *********************************************************************************************************************/
/*! \brief        Dispatchs the given DEM error according to the determined error count.
 *  \details      The master takes care of reporting the satellite DEM errors in multipartition usage scenario.
 *                Therefore, this functions determines the error count of the satellite errors and
 *                dispatchs the error as often as necessary.
 *  \param[in]    error DEM error to be dispatched.
 *                Only NVM_DEM_ERROR_TYPE_REQ_FAILED and NVM_DEM_ERROR_TYPE_INTEGRITY_FAILED are supported.
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *  \pre -
 */
FUNC(void, NVM_PRIVATE_CODE) NvM_ErrorCheck_DispatchDemErrorCountConditionally(const NvM_DemErrorIdType error);
#endif /* NVM_MULTIPARTITION_USAGE_SCENARIO */

# define NVM_STOP_SEC_CODE
# include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* NVM_ERRORCHECK_H */

/**********************************************************************************************************************
 *  END OF FILE: NvM_ErrorCheck.h
 *********************************************************************************************************************/
