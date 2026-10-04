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
/*!        \file  NvM_Notification.h
 *        \brief  NvM notification functions header file.
 *         \unit  NvM_Notification
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#if (!defined NVM_NOTIFICATION_H)
#define NVM_NOTIFICATION_H

/***********************************************************************************************************************
 * INCLUDES
 **********************************************************************************************************************/
#include "NvM_Types.h"
#include "NvM_InternalTypes.h"


/***********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
# define NVM_START_SEC_CODE
# include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * NvM_Notification_ProcessSingleBlockCallback
 *********************************************************************************************************************/
/*! \brief       Invokes a singleblock callback if configured.
 *  \details     -
 *  \param[in]   singleBlockJobContext Single Block Job Context which contains all relevant information.
 *  \param[in]   partitionId           Current Partition Id.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, NVM_PRIVATE_CODE) NvM_Notification_ProcessSingleBlockCallback(
  NvM_SingleBlockJobContextPtrToConstType singleBlockJobContext,
  NvM_PartitionIdType partitionId);

/**********************************************************************************************************************
 * NvM_Notification_ProcessMultiBlockNotification
 *********************************************************************************************************************/
/*! \brief       Invokes a multiblock request if configured.
 *  \details     -
 *  \param[in]   multiBlockJobType Type of the multiblock job.
 *  \param[in]   requestResult The result of the request.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, NVM_PRIVATE_CODE) NvM_Notification_ProcessMultiBlockNotification(
  const NvM_MultiBlockJobType multiBlockJobType,
  const NvM_RequestResultType requestResult);

/**********************************************************************************************************************
 * NvM_Notification_ProcessBackgroundCrcRecalcNotification
 *********************************************************************************************************************/
/*! \brief       Invokes a background CRC recaluculation callback if configured.
 *  \details     Must only be invoked with NVM_REQ_OK for successful background CRC calculation step
 *               and NVM_REQ_NOT_OK for unsuccessful case.
 *  \param[in]   blockDescriptorLookupTableId   Block Descriptor Look Up Table ID of block to be notified about.
 *  \param[in]   requestResult                  The result of the request.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, NVM_PRIVATE_CODE) NvM_Notification_ProcessBackgroundCrcRecalcNotification(
  const NvM_BlockDescriptorLookupTableIdType blockDescriptorLookupTableId,
  const NvM_RequestResultType requestResult);

# define NVM_STOP_SEC_CODE
# include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#endif  /* NVM_NOTIFICATION_H */

/***********************************************************************************************************************
 *  END OF FILE: NvM_NOTIFICATION.h
 **********************************************************************************************************************/
