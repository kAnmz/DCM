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
/*!        \file  NvM_ErrorCheck.c
 *        \brief  NvM_ErrorCheck source file
 *      \details  Implementation of the error check unit of the NvM.
 *         \unit  NvM_ErrorCheck
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#define NVM_ERRORCHECK_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "NvM_Types.h"
#include "NvM_ErrorCheck.h"
#include "NvM.h"
#include "NvM_Cfg.h"
#include "NvM_PrivateCfg.h"

#if (NVM_MULTIPARTITION_USAGE_SCENARIO == STD_ON)
# include "NvM_SatelliteCom.h"
# include "NvM_MasterCom.h"
#endif

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define NVM_START_SEC_CODE
#include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * NvM_ErrorCheck_IsDetConditionTrue()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(boolean, NVM_PRIVATE_CODE) NvM_ErrorCheck_IsDetConditionTrue(const boolean condition)
{
#if (NVM_DEV_ERROR_DETECT == STD_ON)
  return condition;
#else
  NVM_DUMMY_STATEMENT_CONST(condition);                                                                                 /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return FALSE;
#endif
}

/**********************************************************************************************************************
 * NvM_ErrorCheck_ReportDetErrorConditionally()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, NVM_PRIVATE_CODE) NvM_ErrorCheck_ReportDetErrorConditionally(const uint8 serviceId,
  const NvM_DetErrorIdType error)
{
#if (NVM_DEV_ERROR_REPORT == STD_ON)
  if (error != NVM_E_NO_ERROR)
  {
    (void)Det_ReportError(NVM_MODULE_ID, NVM_INSTANCE_ID, serviceId, error);
  }
#else
  NVM_DUMMY_STATEMENT_CONST(serviceId);                                                                                 /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  NVM_DUMMY_STATEMENT_CONST(error);                                                                                     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif
}

/**********************************************************************************************************************
 * NvM_ErrorChecks_ReportDetRuntimeErrorConditionally()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, NVM_PRIVATE_CODE) NvM_ErrorCheck_ReportDetRuntimeErrorConditionally(const uint8 serviceId,
  const NvM_DetErrorIdType error)
{
#if (NVM_DEV_ERROR_REPORT == STD_ON)
  if (error != NVM_E_NO_ERROR)
  {
    (void)Det_ReportRuntimeError(NVM_MODULE_ID, NVM_INSTANCE_ID, serviceId, error);
  }
#else
  NVM_DUMMY_STATEMENT_CONST(serviceId);                                                                                 /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  NVM_DUMMY_STATEMENT_CONST(error);                                                                                     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif
}

/**********************************************************************************************************************
 * NvM_ErrorCheck_DispatchDemErrorConditionally()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, NVM_PRIVATE_CODE) NvM_ErrorCheck_DispatchDemErrorConditionally(const NvM_DemErrorIdType error)
{
#if (NVM_DEM_ERROR_REPORT == STD_ON)
  if (error != NVM_DEM_ERROR_TYPE_NO_ERROR)
  {
    switch(error)
    {
      case NVM_DEM_ERROR_TYPE_REQ_FAILED:
        NvM_DemSetEventStatusReqFailed();
        break;
      case NVM_DEM_ERROR_TYPE_INTEGRITY_FAILED:
        NvM_DemSetEventStatusIntegrityFailed();
        break;
      case NVM_DEM_ERROR_TYPE_LOSS_OF_REDUNDANCY:
        NvM_DemSetEventStatusLossOfRedundancy();
        break;

      default: /* COV_NVM_MISRA_BRANCH */
        /*
         * MISRA case. Do nothing.
         * This default case is empty due to the fact that the dem error id type
         * can also be of type NVM_DEM_ERROR_TYPE_NO_ERROR. In this case
         * no dem error shall be dispatched.
         */
        break;
    }
  }
#else
  NVM_DUMMY_STATEMENT_CONST(error);                                                                                     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif /* NVM_DEM_ERROR_REPORT */
}

/**********************************************************************************************************************
 * NvM_ErrorCheck_ReportDemError()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, NVM_PRIVATE_CODE) NvM_ErrorCheck_ReportDemError(
    const NvM_DemErrorIdType error,
    const NvM_PartitionIdType partitionId)
{
#if (NVM_MULTIPARTITION_USAGE_SCENARIO == STD_ON)
  NvM_SatelliteCom_IncrementDemErrorCount(error, partitionId);
#else
  NvM_ErrorCheck_DispatchDemErrorConditionally(error);

  NVM_DUMMY_STATEMENT_CONST(partitionId);                                                                               /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif /* NVM_MULTIPARTITION_USAGE_SCENARIO */
}

#if (NVM_MULTIPARTITION_USAGE_SCENARIO == STD_ON)
/**********************************************************************************************************************
 * NvM_ErrorCheck_DispatchDemErrorCountConditionally()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, NVM_PRIVATE_CODE) NvM_ErrorCheck_DispatchDemErrorCountConditionally(const NvM_DemErrorIdType error)
{
  uint16 errorCount = NvM_MasterCom_DetermineDemErrorCount(error);

  for (uint16 i = 0u; i < errorCount; i++)                                                                              /* FETA_NVM_ErrorCheck_ErrorCountReporting */
  {
    NvM_ErrorCheck_DispatchDemErrorConditionally(error);
  }
}
#endif /* NVM_MULTIPARTITION_USAGE_SCENARIO */

#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  FETA JUSTIFICATIONS
 **********************************************************************************************************************/
/* FETA_JUSTIFICATION_BEGIN

\ID FETA_NVM_ErrorCheck_ErrorCountReporting
\DESCRIPTION Loop over limited number of errors.
\COUNTERMEASURE \R The errorCount is determined as the sum of all errors reported by the satellites to the master.
                   The error count of the satellites is a uint8 variable and the master determines the
                   difference between its mirrored error count and the actual error count of the satellite.
                   These differences are summed up to the overall error count, provided by the
                   NvM_MasterCom_DetermineDemErrorCount function.
                   Therefore, the errorCount value can maximally reach a sum of full range uint8 values multiplied
                   by the number of satellites. But this is theoretical value, the real value is in range of a small
                   uint8 value, since the master always calls the NvM_ErrorCheck_DispatchDemErrorCountConditionally
                   when the master main function is triggered.
                   The errorCount is never decreased, it takes use of standardized C unsigned integer overflow handling.
                   The loop will always terminate in finite time.


FETA_JUSTIFICATION_END */


/**********************************************************************************************************************
 *  END OF FILE: NvM_ErrorCheck.c
 *********************************************************************************************************************/
