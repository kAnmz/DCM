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
/*!        \file  MemAcc_MultiBinary.h
 *        \brief  MemAcc_MultiBinary header file
 *      \details  -
 *         \unit  MultiBinary
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#if !defined (MEMACC_MULTIBINARY_H)
# define MEMACC_MULTIBINARY_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "MemAcc_InternalTypes.h"

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define MEMACC_START_SEC_CODE
#include "MemAcc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if (MEMACC_MULTIBINARY_ISMULTIBINARYUSECASE == STD_ON) /* COV_MSR_UT_OPTIONAL_UNIT */

/**********************************************************************************************************************
 * MemAcc_MultiBinary_IsDirectRequest
 *********************************************************************************************************************/
/*! \brief       Checks wether the current MultiBinary access request is a direct request.
 *  \details     -
 *  \return      TRUE if it is a direct request, otherwise FALSE.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
boolean MemAcc_MultiBinary_IsDirectRequest(void);

/**********************************************************************************************************************
 * MemAcc_MultiBinary_IsRedirectRequest
 *********************************************************************************************************************/
/*! \brief       Checks wether the current MultiBinary access request is a redirect request.
 *  \details     -
 *  \return      TRUE if it is a redirect request, otherwise FALSE.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
boolean MemAcc_MultiBinary_IsRedirectRequest(void);

/**********************************************************************************************************************
 * MemAcc_MultiBinary_CanDispatchAccessRequest
 *********************************************************************************************************************/
/*! \brief       Checks wether the current MultiBinary binary is allowed to dispatch a access request.
 *  \details     -
 *  \return      TRUE if it can be dispatched, otherwise FALSE.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
boolean MemAcc_MultiBinary_CanDispatchAccessRequest(void);

/**********************************************************************************************************************
 * MemAcc_MultiBinary_DispatchNoAccessRequest
 *********************************************************************************************************************/
/*! \brief       Dispatches the information that there is no access request for the current binary.
 *  \details     -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
void MemAcc_MultiBinary_DispatchNoAccessRequest(void);

/**********************************************************************************************************************
 * MemAcc_MultiBinary_IsActiveBinary
 *********************************************************************************************************************/
/*! \brief       Checks wether the current binary is selected by the master binary for processing.
 *  \details     -
 *  \return      TRUE if it's the current binary, otherwise FALSE.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
boolean MemAcc_MultiBinary_IsActiveBinary(void);

/**********************************************************************************************************************
 * MemAcc_MultiBinary_DispatchDirectJobStepToSharedMemory
 *********************************************************************************************************************/
/*! \brief       Dispatches the given direct job step to the shared memory for MultiBinary processing.
 *  \details     -
 *  \param[in]   job JobContext that should be dispatched.
 *  \pre         Given job must be a valid direct job.
 *               MemAcc_MultiBinary_CanDispatchAccessRequest must allow this execution.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
void MemAcc_MultiBinary_DispatchDirectJobStepToSharedMemory(const MemAcc_JobContextType* job);

# if (MEMACC_MULTIBINARY_ISMASTERBINARY == STD_ON)

/**********************************************************************************************************************
 * MemAcc_MultiBinary_UpdateSynchronizationToken
 *********************************************************************************************************************/
/*! \brief       Updates the MultiBinary synchronization token depending on incoming access requests.
 *  \details     -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
void MemAcc_MultiBinary_UpdateSynchronizationToken(void);

#  if (MEMACC_MULTIBINARY_HASREDIRECTREQUESTS == STD_ON)

/**********************************************************************************************************************
 * MemAcc_MultiBinary_ProcessRedirectRequest
 *********************************************************************************************************************/
/*! \brief       Process a redirect request if it is selected by the synchronization token.
 *  \details     -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
void MemAcc_MultiBinary_ProcessRedirectRequest(void);

#  endif /* MEMACC_MULTIBINARY_HASREDIRECTREQUESTS */
# endif /* MEMACC_MULTIBINARY_ISMASTERBINARY */

# if (MEMACC_MULTIBINARY_ISSATELLITEBINARY == STD_ON)
#  if (MEMACC_MULTIBINARY_HASREDIRECTREQUESTS == STD_ON)

/**********************************************************************************************************************
 * MemAcc_MultiBinary_DispatchRedirectJobStepToSharedMemory
 *********************************************************************************************************************/
/*! \brief       Dispatches the given redirect job step to the shared memory for MultiBinary processing.
 *  \details     -
 *  \param[in]   job JobContext that should be dispatched.
 *  \pre         Given job must be a valid redirect job.
 *               MemAcc_MultiBinary_CanDispatchAccessRequest must allow this execution.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
void MemAcc_MultiBinary_DispatchRedirectJobStepToSharedMemory(const MemAcc_JobContextType* job);

/**********************************************************************************************************************
 * MemAcc_MultiBinary_CheckIfRedirectJobStepHasFinishedAndUpdateJobContext
 *********************************************************************************************************************/
/*! \brief       Checks if the current redirect access request has finished. If it is finished it updates the given
                 JobContext with with the result from the master binary.
 *  \details     -
 *  \param[in]   job             JobContext that should be updated.
 *  \param[in]   srcBufferOffset Byte offset into the shared memory data buffer for the copy-back
 *               0 for aligned read or compare jobs.
 *  \return      The job step result.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
MemAcc_MemJobResultType MemAcc_MultiBinary_GetRedirectJobStepResultAndUpdateJobContext(
  const MemAcc_JobContextType* job,
  const MemAcc_LengthType      srcBufferOffset);

#  endif /* MEMACC_MULTIBINARY_HASREDIRECTREQUESTS */
# endif /* MEMACC_MULTIBINARY_ISSATELLITEBINARY */
#endif /* MEMACC_MULTIBINARY_ISMULTIBINARYUSECASE */

#define MEMACC_STOP_SEC_CODE
#include "MemAcc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* MEMACC_MULTIBINARY_H */

/**********************************************************************************************************************
 *  END OF FILE: MemAcc_MultiBinary.h
 *********************************************************************************************************************/
