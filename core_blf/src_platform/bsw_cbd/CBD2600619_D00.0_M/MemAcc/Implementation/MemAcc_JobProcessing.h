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
/*!        \file  MemAcc_JobProcessing.h
 *        \brief  MemAcc_JobProcessing header file
 *      \details  Header of JobProcessing unit of the MemAcc.
 *         \unit  JobProcessing
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#if !defined (MEMACC_JOBPROCESSING_H)
# define MEMACC_JOBPROCESSING_H

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

#if (MEMACC_MULTIBINARY_ISMULTIBINARYUSECASE == STD_ON)

/**********************************************************************************************************************
 * MemAcc_JobProcessing_DispatchJobStepToSharedMemory()
 *********************************************************************************************************************/
/*! \brief       Dispatches the job step to the Shared Memory.
 *  \details     -
 *  \param[in]   job - Pointer to the job.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
void MemAcc_JobProcessing_DispatchJobStepToSharedMemory(MemAcc_JobContextType* job);

#endif /* MEMACC_MULTIBINARY_ISMULTIBINARYUSECASE */

/**********************************************************************************************************************
 * MemAcc_JobProcessing_DispatchJobStepToMem()
 *********************************************************************************************************************/
/*! \brief       Dispatches the job step to the Mem.
 *  \details     -
 *  \param[in]   job - Pointer to the job.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
void MemAcc_JobProcessing_DispatchJobStepToMem(MemAcc_JobContextType* job);

/**********************************************************************************************************************
 * MemAcc_JobProcessing_UpdateJobStep()
 *********************************************************************************************************************/
/*! \brief       Updates and processes the current step of a dispatched job step.
 *  \details     -
 *  \param[in]   job - Pointer to the job.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
void MemAcc_JobProcessing_UpdateJobStep(MemAcc_JobContextType* job);

/**********************************************************************************************************************
 * MemAcc_JobProcessing_CalculateNextJobStep()
 *********************************************************************************************************************/
/*! \brief         Calculates the next job step
 *  \details       -
 *  \param[in]     JobArea - Pointer to the job area.
 *  \param[in]     JobStep - Pointer to the job step.
 *  \param[in]     Offset - Offset for which the job step should be calculated.
 *  \param[in]     isNewJob - Indicates wether the job step is calculated for a new job.
 *  \return        E_OK if the calculations were successful (i.e. a sub address area index was found), otherwise
 *                 E_NOT_OK.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
Std_ReturnType MemAcc_JobProcessing_CalculateNextJobStep(
  const MemAcc_JobAreaType* JobArea,
  MemAcc_JobStepType* JobStep,
  const MemAcc_LengthType Offset,
  const boolean isNewJob);

#define MEMACC_STOP_SEC_CODE
#include "MemAcc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* MEMACC_JOBPROCESSING_H */

/**********************************************************************************************************************
 *  END OF FILE: MemAcc_JobProcessing.h
 *********************************************************************************************************************/
