/***********************************************************************************************************************
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
/*!        \file  NvM_DataIntegrityFsm.h
 *        \brief  NvM_DataIntegrityFsm header file
 *      \details  Implementation of data integrity state machine
 *         \unit  NvM_DataIntegrityFsm
 **********************************************************************************************************************/

#if !defined (NVM_DATAINTEGRITYFSM_H)
# define NVM_DATAINTEGRITYFSM_H

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
#include "NvM_Types.h"
#include "NvM_InternalTypes.h"

/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/
#define NVM_START_SEC_CODE
#include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * NvM_DataIntegrityFsm_Process()
 *********************************************************************************************************************/
/*! \brief       Data Integrity processing service API.
 *  \details     Will spawn a FSM which will either generate the data integrity record and append it to the payload or 
                 validate the data integrity record depending on the provided job type.
 *  \param[in]   dataIntegrityJobContext  Job Context which contains relevant information about the job.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, NVM_PRIVATE_CODE) NvM_DataIntegrityFsm_Process(
  NvM_DataIntegrityJobContextConstPtrType dataIntegrityJobContext);

#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* NVM_DATAINTEGRITYFSM_H */

/***********************************************************************************************************************
 *  END OF FILE: NvM_DataIntegrityFsm.h
 **********************************************************************************************************************/
