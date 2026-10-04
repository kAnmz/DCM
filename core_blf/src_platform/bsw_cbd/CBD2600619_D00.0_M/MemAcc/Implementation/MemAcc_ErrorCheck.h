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
/*!        \file  MemAcc_ErrorCheck.h
 *        \brief  MemAcc_ErrorCheck header file
 *      \details  Implementation of the unit ErrorCheck.
 *                The unit is responsible for the abstraction of DET and runtime error checks.

 *         \unit  ErrorCheck
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/
#ifndef MEMACC_ERRORCHECK_H
# define MEMACC_ERRORCHECK_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "MemAcc_InternalTypes.h"

/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/
/* ----- Error codes ----- */
/*!
 *  /defgroup errorIDs Error IDs
 */
/*! Used to check if no error occurred. */
# define MEMACC_E_NO_ERROR               (0x00u)
/*! API service called without module initialization  */
# define MEMACC_E_UNINIT                 (0x01u)
/*! API service called with NULL pointer argument */
# define MEMACC_E_PARAM_POINTER          (0x02u)
/*! API service called with wrong address area ID */
# define MEMACC_E_PARAM_ADDRESS_AREA_ID  (0x03u)
/*! API service called with address and length not belonging to the passed address area ID */
# define MEMACC_E_PARAM_ADDRESS_LENGTH   (0x04u)
/*! API service called with a hardware ID not belonging to the passed address area ID */
# define MEMACC_E_PARAM_HW_ID            (0x05u)
/*! API service called for an address area ID with a pending job request */
# define MEMACC_E_BUSY                   (0x06u)
/*! API service called for an address area ID with a pending job request */
# define MEMACC_E_MEM_INIT_FAILED        (0x07u)
/*! Redirect job requested with wrong redirect job information */
# define MEMACC_E_REDIRECT_JOB           (0x10u)
/*!< Service ID: Service ID for redirect job request */
# define MEMACC_SID_REDIRECT_JOB         (0x1au)

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

# define MEMACC_START_SEC_CODE
# include "MemAcc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * MemAcc_ErrorCheck_IsSynchServiceInvocationValid
 *********************************************************************************************************************/
/*! \brief         Checks whether the component is intizalized and the needed parameters are valid.
 *  \details       -
 *  \param[in]     serviceId Id used for reporting.
 *  \param[in]     moduleInitialized - MEMACC_UNINIT In case module is not initialized
 *                                     MEMACC_INIT Otherwise
 *  \param[in]     addressAreaIdx Index of address area
 *  \param[in]     dataPtr Pointer to data, only required/checked for GetMemoryInfo and GetJobInfo jobs
 *  \param[in]     isNullPtrCheckRequired Determines whether DataPtr is checked for NULL_PTR
 *  \return        TRUE   All checks are valid, no error was reported
 *                 FALSE  Otherwise
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
boolean MemAcc_ErrorCheck_IsSynchServiceInvocationValid(
  uint8 serviceId,
  uint8 moduleInitialized,
  MemAcc_AddressAreaIndexType addressAreaIdx,
  const void* dataPtr,
  boolean isNullPtrCheckRequired);

/**********************************************************************************************************************
 * MemAcc_ErrorCheck_IsGetVersionInfoInvocationValid
 *********************************************************************************************************************/
/*! \brief         Checks whether the version info pointer is valid.
 *  \details       -
 *  \param[in]     ServiceId Id used for reporting.
 *  \param[in]     VersionInfoPtr  Pointer to where to store the version information.
 *  \return        TRUE   Pointer check is valid, no error was reported
 *                 FALSE  Otherwise
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
boolean MemAcc_ErrorCheck_IsGetVersionInfoInvocationValid(
  uint8 ServiceId,
  const Std_VersionInfoType* VersionInfoPtr);

/**********************************************************************************************************************
 * MemAcc_ErrorCheck_IsAsynchServiceInvocationValid
 *********************************************************************************************************************/
/*! \brief         Checks, dependent of the job type, if the needed parameters are valid and whether the component
 *                 is intizalized and the used AddressArea is not busy.
 *  \details       -
 *  \param[in]     ServiceId Id used for reporting
 *  \param[in]     ModuleInitialized - MEMACC_UNINIT In case module is not initialized
 *                                     MEMACC_INIT Otherwise
 *  \param[in]     JobPtr Pointer to job information
 *  \return        TRUE   All checks are valid inclusive init and busy checks, no error was reported
 *                 FALSE  Otherwise
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
boolean MemAcc_ErrorCheck_IsAsynchServiceInvocationValid(
  uint8 ServiceId,
  uint8 ModuleInitialized,
  const MemAcc_JobAreaType* JobPtr);

/**********************************************************************************************************************
 * MemAcc_ErrorCheck_IsHwSpecificServiceInvocationValid
 *********************************************************************************************************************/
/*! \brief         Verify if the component is initialized and not busy, and ensure that both the address area ID and
 *                 hardware ID are valid.
 *  \details       -
 *  \param[in]     ServiceId Id used for reporting
 *  \param[in]     ModuleInitialized - MEMACC_UNINIT In case module is not initialized
 *                                     MEMACC_INIT Otherwise
 *  \param[in]     JobPtr Pointer to job information
 *  \return        TRUE   All checks are valid inclusive init and busy checks, no error was reported
 *                 FALSE  Otherwise
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
boolean MemAcc_ErrorCheck_IsHwSpecificServiceInvocationValid(
  uint8 ServiceId,
  uint8 ModuleInitialized,
  const MemAcc_JobAreaType* JobPtr);

/**********************************************************************************************************************
 * MemAcc_ErrorCheck_IsLockInvocationValid
 *********************************************************************************************************************/
/*! \brief         Verify if the component is initialized and not busy, and ensure that the address area ID, the
 *                 address, the length, and the lock notification function pointer are valid.
 *  \details       -
 *  \param[in]     serviceId Id used for reporting
 *  \param[in]     moduleInitialized - MEMACC_UNINIT In case module is not initialized
 *                                     MEMACC_INIT Otherwise
 *  \param[in]     addressAreaIdx Index of address area
 *  \param[in]     logicalAddress Logical start address of the address area to identify the Mem driver instance to be locked
 *  \param[in]     length Length of the address area to identify the Mem driver instance to be locked
 *  \param[in]     lockNotificationFctPtr Pointer to address area lock notification callback function
 *  \param[in]     isRequestLockJob Determines whether the address area is checked to be idle and the
 *                                  LockNotificationFctPtr is checked for NULL_PTR (Only required for RequestLock)
 *  \return        TRUE   All checks are valid inclusive init and busy checks, no error was reported
 *                 FALSE  Otherwise
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
boolean MemAcc_ErrorCheck_IsLockInvocationValid(
  uint8 serviceId,
  uint8 moduleInitialized,
  MemAcc_AddressAreaIndexType addressAreaIdx,
  MemAcc_AddressType logicalAddress,
  MemAcc_AddressType length,
  MemAcc_ApplicationLockNotificationType lockNotificationFctPtr,
  boolean isRequestLockJob);

#if (MEMACC_MULTIBINARY_ISMASTERBINARY == STD_ON)

/**********************************************************************************************************************
 * MemAcc_ErrorCheck_ReportMultiBinaryDetError
 *********************************************************************************************************************/
/*! \brief         Reports an error from multibinary redirect request to DET if reporting is configured.
 *  \details       -
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
void MemAcc_ErrorCheck_ReportMultiBinaryDetError(void);

#endif /* #if MEMACC_MULTIBINARY_ISMASTERBINARY */

/**********************************************************************************************************************
 * MemAcc_ErrorCheck_IsActivateMemInvocationValid
 *********************************************************************************************************************/
/*! \brief         Verify that a ActivateMem invocation is valid.
 *  \details       -
 *  \param[in]     ServiceId - Id used for reporting
 *  \param[in]     ModuleInitialized - MEMACC_UNINIT In case module is not initialized
 *                                     MEMACC_INIT Otherwise
 *  \param[in]     headerAddress - Physical start address of Mem driver header structure.
 *  \return        TRUE   All checks are valid, no error was reported
 *                 FALSE  Otherwise
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
boolean MemAcc_ErrorCheck_IsActivateMemInvocationValid(
  const uint8 ServiceId,
  const uint8 ModuleInitialized,
  const MemAcc_AddressType headerAddress);

/**********************************************************************************************************************
 * MemAcc_ErrorCheck_IsInitialized
 *********************************************************************************************************************/
/*! \brief         Verify that the MemAcc is Initialized.
 *  \details       -
 *  \param[in]     ServiceId - Id used for reporting
 *  \param[in]     ModuleInitialized - MEMACC_UNINIT In case module is not initialized
 *                                     MEMACC_INIT Otherwise
 *  \return        TRUE   All checks are valid, no error was reported
 *                 FALSE  Otherwise
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
boolean MemAcc_ErrorCheck_IsInitialized(
  const uint8 ServiceId,
  const uint8 ModuleInitialized);

# define MEMACC_STOP_SEC_CODE
# include "MemAcc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* MEMACC_ERRORCHECK_H */

/**********************************************************************************************************************
 *  END OF FILE: MemAcc_ErrorCheck.h
 *********************************************************************************************************************/
