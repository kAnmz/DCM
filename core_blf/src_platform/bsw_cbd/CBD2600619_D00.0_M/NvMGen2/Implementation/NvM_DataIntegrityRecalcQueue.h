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
/*!        \file  NvM_DataIntegrityRecalcQueue.h
 *        \brief  NvM_DataIntegrityRecalcQueue header file
 *      \details  Header of the DataIntegrity recalculation queue unit of the NvM.
 *         \unit  NvM_DataIntegrityRecalcQueue
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#if !defined (NVM_DATAINTEGRITYRECALCQUEUE_H)
# define NVM_DATAINTEGRITYRECALCQUEUE_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "NvM_InternalTypes.h"
#include "NvM_Cfg.h"


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
# define NVM_START_SEC_CODE
# include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * NvM_DataIntegrityRecalcQueue_Init
 *********************************************************************************************************************/
/*! \brief       Initialize the unit.
 *  \details     -
 *  \pre         Unit is uninitialized.
 *  \param[in,out] queuePtr                         - Unit instance pointer.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 * \spec
 *    requires queuePtr != NULL_PTR;
 * \endspec
 *********************************************************************************************************************/
FUNC(void, NVM_PRIVATE_CODE) NvM_DataIntegrityRecalcQueue_Init(NvM_DataIntegrityRecalcQueue_InstancePtrType queuePtr);

/**********************************************************************************************************************
 *  NvM_DataIntegrityRecalcQueue_Push
 *********************************************************************************************************************/
/*! \brief       Add a new job to the queue.
 *  \details     -
 *  \param[in,out] queuePtr                         - Unit instance pointer.
 *  \param[in]     blockDescriptorLookupTableId     - Block ID that shall be enqueued
 *  \pre         NvM_DataIntegrityRecalcQueue_Init() MUST be called before using this function.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, NVM_PRIVATE_CODE) NvM_DataIntegrityRecalcQueue_Push(
    NvM_DataIntegrityRecalcQueue_InstancePtrType queuePtr,
    const NvM_BlockDescriptorLookupTableIdType blockDescriptorLookupTableId
);

/**********************************************************************************************************************
 *  NvM_DataIntegrityRecalcQueue_Pop
 *********************************************************************************************************************/
/*! \brief       Get the job from the queue which shall be processed next.
 *  \details     Additionally the job will be removed from the queue.
 *  \param[in,out] queuePtr                         - Unit instance pointer.
 *  \param[out]    blockDescriptorLookupTableIdPtr  - Pointer to the job which shall be processed.
 *  \return      E_OK     - A queued ID available, blockDescriptorLookupTableIdPtr contains ID to be processed.
 *  \return      E_NOT_OK - The queue was empty.
 *  \pre         NvM_DataIntegrityRecalcQueue_Init() MUST be called before using this function.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 * \spec
 *    requires queuePtr != NULL_PTR && blockDescriptorLookupTableIdPtr != NULL_PTR;
 * \endspec
 *********************************************************************************************************************/
FUNC(Std_ReturnType, NVM_PRIVATE_CODE) NvM_DataIntegrityRecalcQueue_Pop(
    NvM_DataIntegrityRecalcQueue_InstancePtrType queuePtr,
    NvM_BlockDescriptorLookupTableIdType* blockDescriptorLookupTableIdPtr
);

# define NVM_STOP_SEC_CODE
# include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* NVM_DATAINTEGRITYRECALCQUEUE_H */

/**********************************************************************************************************************
 *  END OF FILE: NvM_DataIntegrityRecalcQueue.h
 *********************************************************************************************************************/
