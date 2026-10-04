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
/*!        \file  NvM_DataSync.h
 *        \brief  NvM_DataSync header file
 *      \details  Header of the data synchronization unit of the NvM. This unit takes care of data synchronization
 *                handling between NvM and the user of NvM. It abstracts all possibilities how data can be transferred.
 *         \unit  NvM_DataSync
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#if !defined (NVM_DATASYNC_H)
# define NVM_DATASYNC_H

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
 * NvM_DataSync_RequestData()
 *********************************************************************************************************************/
/*! \brief       Request data synchronization of a block to the given buffer
 *  \details     This function takes care of the synchronization strategy that is configured
 *  \param[in]   blockDescriptorLookupTableId   Block identifier for which data is requested
 *  \param[in]   targetBuffer                   Target buffer, must not be NULL
 *  \param[in]   srcBuffer                      Source buffer, must not be NULL
 *  \pre         -
 *  \return      E_OK if data synchronization is successful, E_NOT_OK otherwise
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, NVM_PRIVATE_CODE) NvM_DataSync_RequestData(
    const NvM_BlockDescriptorLookupTableIdType blockDescriptorLookupTableId,
    NvM_DataPtrType targetBuffer,
    NvM_DataPtrToConstType srcBuffer);

/**********************************************************************************************************************
 * NvM_DataSync_ProvideData()
 *********************************************************************************************************************/
/*! \brief       Provide data of a block to the given buffer
 *  \details     This function takes care of the synchronization strategy that is configured
 *  \param[in]   blockDescriptorLookupTableId   Block identifier for which data can be provided
 *  \param[in]   srcBuffer                      Source buffer, must not be NULL
 *  \param[in]   targetBuffer                   Target buffer, must not be NULL
 *  \pre         -
 *  \return      E_OK if data synchronization is successful, E_NOT_OK otherwise
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, NVM_PRIVATE_CODE) NvM_DataSync_ProvideData(
    const NvM_BlockDescriptorLookupTableIdType blockDescriptorLookupTableId,
    NvM_DataPtrToConstType srcBuffer,
    NvM_DataPtrType targetBuffer);

/**********************************************************************************************************************
 * NvM_DataSync_RestoreDefaultData()
 *********************************************************************************************************************/
/*! \brief       Restore default data of a block
 *  \details     This function takes care of the default data mechanism that is configured
 *  \param[in]   blockDescriptorLookupTableId   Block identifier for which data can be provided
 *  \param[in]   jobType                        Type of the singleblock request
 *  \param[in]   targetBuffer                   Target buffer, must not be NULL
 *  \pre         -
 *  \return      E_OK if default data is restored, E_NOT_OK otherwise
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, NVM_PRIVATE_CODE) NvM_DataSync_RestoreDefaultData(
    const NvM_BlockDescriptorLookupTableIdType blockDescriptorLookupTableId,
    const NvM_SingleBlockJobType jobType,
    NvM_DataPtrType targetBuffer);

# define NVM_STOP_SEC_CODE
# include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* NVM_DATASYNC_H */

/**********************************************************************************************************************
 *  END OF FILE: NvM_DataSync.h
 *********************************************************************************************************************/
