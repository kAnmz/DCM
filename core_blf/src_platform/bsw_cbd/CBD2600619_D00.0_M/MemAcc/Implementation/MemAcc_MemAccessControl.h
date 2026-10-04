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
/*!        \file  MemAcc_MemAccessControl.h
 *        \brief  MemAcc_MemAccessControl header file
 *      \details  Implementation of the unit MemAccessControl.
 *                The unit contains functions to control the access to Mem in case of Activation and Deactivation.

 *         \unit  MemAccessControl
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/
#ifndef MEMACC_MEMACCESSCONTROL_H
# define MEMACC_MEMACCESSCONTROL_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "MemAcc_InternalTypes.h"

/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

# define MEMACC_START_SEC_CODE
# include "MemAcc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * MemAcc_MemAccessControl_Reset()
 *********************************************************************************************************************/
/*!
 *  \brief         Resets all MemAccessControl flags to default values.
 *  \details       -
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 */
void MemAcc_MemAccessControl_Reset(void);

/**********************************************************************************************************************
 * MemAcc_MemAccessControl_IsMemAccessAllowed()
 *********************************************************************************************************************/
/*!
 *  \brief         Checks if execution of a job type on a saa is allowed.
 *  \details       -
 *  \param[in]     saaIdx - Subaddressarea Index
 *  \param[in]     jobType - Job Type
 *  \return        TRUE if the job execution is allowed, FALSE otherwise.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 */
boolean MemAcc_MemAccessControl_IsMemAccessAllowed(
  const MemAcc_SubAddressAreaIndexType saaIdx,
  const MemAcc_JobType jobType);

/**********************************************************************************************************************
 * MemAcc_MemAccessControl_ActivateMemBinaryHeader()
 *********************************************************************************************************************/
/*!
 *  \brief         Activates a MemBinaryHeader on a given llIdx.
 *  \details       -
 *  \param[in]     llIdx - LowerLayer Index
 *  \param[in]     memBinaryHeader - Pointer to MemBinaryHeader structure.
 *  \return        TRUE if activation succeeded, FALSE otherwise.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 */
boolean MemAcc_MemAccessControl_ActivateMemBinaryHeader(
  const MemAcc_SizeOfCLowerLayerType llIdx,
  MemAcc_MemBinaryHeaderType* memBinaryHeader);

/**********************************************************************************************************************
 * MemAcc_MemAccessControl_DeactivateMemBinaryHeader()
 *********************************************************************************************************************/
/*!
 *  \brief         Deactivates a MemBinaryHeader on a given llIdx.
 *  \details       -
 *  \param[in]     llIdx - LowerLayer Index
 *  \param[in]     memBinaryHeader - Pointer to MemBinaryHeader structure.
 *  \return        TRUE if deactivation succeeded, FALSE otherwise.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 */
boolean MemAcc_MemAccessControl_DeactivateMemBinaryHeader(
  const MemAcc_SizeOfCLowerLayerType llIdx,
  const MemAcc_MemBinaryHeaderType* memBinaryHeader);

#if (MEMACC_READONLYMODE_ENABLED == STD_ON)

/**********************************************************************************************************************
 * MemAcc_MemAccessControl_SetMemReadOnlyAccess()
 *********************************************************************************************************************/
/*!
 *  \brief         Sets the ReadOnly Access.
 *  \details       -
 *  \param[in]     hwId - Hardware Id.
 *  \param[in]     unlockToken - Pointer to the unlock token.
 *  \param[in]     isReadOnlyEnabled - Value to set access to.
 *  \return        TRUE if setting the access value succeeded, FALSE otherwise.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 */
boolean MemAcc_MemAccessControl_SetMemReadOnlyAccess(
  const MemAcc_HwIdType hwId,
  const uint8* unlockToken,
  const boolean isReadOnlyEnabled);

#endif /* MEMACC_READONLYMODE_ENABLED */

# define MEMACC_STOP_SEC_CODE
# include "MemAcc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* MEMACC_MEMACCESSCONTROL_H */

/**********************************************************************************************************************
 *  END OF FILE: MemAcc_MemAccessControl.h
 *********************************************************************************************************************/
