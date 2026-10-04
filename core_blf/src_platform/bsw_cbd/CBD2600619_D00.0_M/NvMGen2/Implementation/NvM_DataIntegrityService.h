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
/*!        \file  NvM_DataIntegrityService.h
 *        \brief  NvM data integrity service functions header file.
 *         \unit  NvM_DataIntegrityService
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#if (!defined NVM_DATAINTEGRITYSERVICE_H)
#define NVM_DATAINTEGRITYSERVICE_H

/***********************************************************************************************************************
 * INCLUDES
 **********************************************************************************************************************/
# include "NvM_Types.h"
# include "NvM_InternalTypes.h"
# include "NvM_Cfg.h"


/***********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
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
 * NvM_DataIntegrityService_Init()
 *********************************************************************************************************************/
/*! \brief       Init data integrity service instance.
 *  \details     This function assumes that a valid data integrity type is configured in the referenced block. In case of 
                 NVM_BLOCK_DATA_INTEGRITY_OFF, the DataIntegrityService should not be called in the first place.
 *  \param[in,out]   dataIntegrityServiceInstance  Data Integrity Instance to be instantiated.
 *  \param[in]       dataIntegrityJobContext  Context which contains relevant information about the job.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, NVM_PRIVATE_CODE) NvM_DataIntegrityService_Init(
  NvM_DataIntegrityService_InstancePtrType dataIntegrityServiceInstance,
  NvM_DataIntegrityJobContextConstPtrType dataIntegrityJobContext);

/**********************************************************************************************************************
 * NvM_DataIntegrityService_GetStatus()
 *********************************************************************************************************************/
/*! \brief         Retrieve the current status of a data integrity job
 *  \details       Returns the job status (PENDING, FINISHED_SUCCESSFUL, or FINISHED_UNSUCCESSFUL)
 *  \param[in]     dataIntegrityServiceInstance  Service instance which contains relevant information about the job.
 *  \return        Current job status
 *  \pre           Instance must point to initialized job structure
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 * 
 * 
 *********************************************************************************************************************/
FUNC(NvM_DataIntegrityService_Status, NVM_PRIVATE_CODE) NvM_DataIntegrityService_GetStatus(
  NvM_DataIntegrityService_InstancePtrToConstType dataIntegrityServiceInstance);


/**********************************************************************************************************************
 * NvM_DataIntegrityService_Process()
 *********************************************************************************************************************/
/*! \brief       Process data integrity job of given instance.
 *  \details     This function assumes that a valid data integrity type is configured in the referenced block. In case of 
                 NVM_BLOCK_DATA_INTEGRITY_OFF, the DataIntegrityService should not be called in the first place.
 *  \param[in,out]   dataIntegrityServiceInstance  Service instance which contains relevant information about the job.
 *  \pre         Unit is initialized.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, NVM_PRIVATE_CODE) NvM_DataIntegrityService_Process(
  NvM_DataIntegrityService_InstancePtrType dataIntegrityServiceInstance);

# define NVM_STOP_SEC_CODE
# include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#endif  /* NVM_DATAINTEGRITYSERVICE_H */

/***********************************************************************************************************************
 *  END OF FILE: NvM_DataIntegrityService.h
 **********************************************************************************************************************/
