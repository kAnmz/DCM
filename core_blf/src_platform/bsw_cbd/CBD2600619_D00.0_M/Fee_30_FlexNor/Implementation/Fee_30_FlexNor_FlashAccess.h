/**********************************************************************************************************************
 *  COPYRIGHT
 *  --------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2025 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  --------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/*!        \file  Fee_30_FlexNor_FlashAccess.h
 *        \brief  Flash access interface
 *      \details  This unit provides an interface to the flash driver that makes it possible to modify incoming flash 
 *                requests from upper units in a centralized unit.
 *         \unit  FlashAccess
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 **********************************************************************************************************************/

#if !defined (FEE_30_FLEXNOR_FLASHACCESS_H)
# define FEE_30_FLEXNOR_FLASHACCESS_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Fee_30_FlexNor_Types.h"
#include "Fee_30_FlexNor_Scheduler.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum
{
    FEE_30_FLEXNOR_FLASH_FAIL,    /*!< The requested operation failed */
    FEE_30_FLEXNOR_FLASH_ECCERROR,
    FEE_30_FLEXNOR_FLASH_OK,      /*!< The requested operation was completed successfully */
    FEE_30_FLEXNOR_FLASH_PENDING  /*!< The requested operation is still pending */
} Fee_30_FlexNor_FlashAccess_FlashResultType; /*!< Result type for internal operations */

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
# define FEE_30_FLEXNOR_START_SEC_CODE
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Fee_30_FlexNor_FlashAccess_Init()
 *********************************************************************************************************************/
/*! \brief       Initialize the flash access unit
 *  \details     -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_FlashAccess_Init(void);

/**********************************************************************************************************************
 * Fee_30_FlexNor_FlashAccess_ReadFlash()
 *********************************************************************************************************************/
/*! \brief       Reads data from flash
 *  \details     Service to read data from flash at the given address.
 *  \param[in]   partitionId           Id of the partition the flash access is made for
 *  \param[in]   address               Start address of the flash that shall be read
 *  \param[in]   data                  Target array where the read data is copied to
 *  \param[in]   length                Amount of data in bytes that shall be read
 *  \param[in]   resultCbk             The result call back that is called in case the service is complete. 
 *                                     Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous FALSE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_FlashAccess_ReadFlash(Fee_30_FlexNor_PartitionIdType partitionId,
    Fee_30_FlexNor_AddressType address, 
    Fee_30_FlexNor_DataPtrType data, 
    Fee_30_FlexNor_LengthType length,
    Fee_30_FlexNor_ResultCallback resultCbk);

/**********************************************************************************************************************
 * Fee_30_FlexNor_FlashAccess_ReadFlashImmediate()
 *********************************************************************************************************************/
/*! \brief       Reads data from flash without a blank check
 *  \details     Service to read data from flash at the given address without executing a blank check.
 *  \param[in]   partitionId     Id of the partition the flash access is made for
 *  \param[in]   address         Start address of the flash that shall be read
 *  \param[in]   data            Target array where the read data is copied to
 *  \param[in]   length          Amount of data in bytes that shall be read
 *  \param[in]   resultCbk       The result call back that is called in case the service is complete. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous FALSE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_FlashAccess_ReadFlashImmediate(
    Fee_30_FlexNor_PartitionIdType partitionId,
    Fee_30_FlexNor_AddressType address, 
    Fee_30_FlexNor_DataPtrType data, 
    Fee_30_FlexNor_LengthType length,
    Fee_30_FlexNor_ResultCallback resultCbk);

/**********************************************************************************************************************
 * Fee_30_FlexNor_FlashAccess_WriteFlash()
 *********************************************************************************************************************/
/*! \brief       Writes data to flash
 *  \details     Service to write the given data to flash asynchronously.
 *  \param[in]   partitionId     Id of the partition the flash access is made for
 *  \param[in]   address         Start address of the flash where the data shall be written to
 *  \param[in]   data            Pointer to the data that shall be written
 *  \param[in]   length          Amount of data in bytes that shall be written
 *  \param[in]   resultCbk       The result call back that is called in case the service is complete. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous FALSE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_FlashAccess_WriteFlash(Fee_30_FlexNor_PartitionIdType partitionId,
    Fee_30_FlexNor_AddressType address, 
    Fee_30_FlexNor_ConstDataPtrType data, 
    Fee_30_FlexNor_LengthType length,
    Fee_30_FlexNor_ResultCallback resultCbk);

/**********************************************************************************************************************
 * Fee_30_FlexNor_FlashAccess_EraseFlash()
 *********************************************************************************************************************/
/*! \brief       Erases flash
 *  \details     Service to erase flash at a given address with a given length. 
 *  \param[in]   partitionId     Id of the partition the flash access is made for
 *  \param[in]   address         Start address of the flash that shall be erased
 *  \param[in]   length          Amount of data in bytes that shall be erased
 *  \param[in]   resultCbk       The result call back that is called in case the service is complete. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous FALSE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_FlashAccess_EraseFlash(Fee_30_FlexNor_PartitionIdType partitionId,
    Fee_30_FlexNor_AddressType address,
    Fee_30_FlexNor_LengthType length,
    Fee_30_FlexNor_ResultCallback resultCbk);

/**********************************************************************************************************************
 * Fee_30_FlexNor_FlashAccess_Cancel()
 *********************************************************************************************************************/
/*! \brief       Cancels an ongoing flash job
 *  \details     Check if there is a flash job running and cancels it.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_FlashAccess_Cancel(void);

/**********************************************************************************************************************
 * Fee_30_FlexNor_FlashAccess_SuspendWrites()
 *********************************************************************************************************************/
/*! \brief       Activates or deactivates the suspension of lower layer write/erase job requests.
 *  \details     -
*   \param[in]   suspendWritesEnabled     Flag indicating whether suspension should be activated or deactivated    
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_FlashAccess_SuspendWrites(boolean suspendWritesEnabled);

/**********************************************************************************************************************
 * Fee_30_FlexNor_FlashAccess_GetReadJobResult()
 *********************************************************************************************************************/
/*! \brief       Get the current job result of the unit.
 *  \details     -
 *  \pre         -
 *  \return      Jobresult of the flash read job.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_FlashAccess_FlashResultType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_FlashAccess_GetReadJobResult(void);

# define FEE_30_FLEXNOR_STOP_SEC_CODE
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* FEE_30_FLEXNOR_FLASHACCESS_H */

/**********************************************************************************************************************
 *  END OF FILE: Fee_30_FlexNor_FlashAccess.h
 *********************************************************************************************************************/
