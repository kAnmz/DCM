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
/*!        \file  Fee_30_FlexNor_ConfigInterface.h
 *        \brief  Interface to generated config
 *      \details  Provides an enriched interface to access the generated configuration of the FEE component.
 *         \unit  ConfigInterface
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 **********************************************************************************************************************/

#if !defined (FEE_30_FLEXNOR_CONFIGINTERFACE_H)
# define FEE_30_FLEXNOR_CONFIGINTERFACE_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "Fee_30_FlexNor_Types.h"
# include "Fee_30_FlexNor_Cfg.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
#define FEE_30_FLEXNOR_START_SEC_CONST_UNSPECIFIED
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if (FEE_30_FLEXNOR_SECURELAYOUT_ENABLED == STD_ON) /* COV_MSR_UT_OPTIONAL_UNIT */
extern Fee_30_FlexNor_MarkerConstType Fee_30_FlexNor_ChunkStartMarker;
extern Fee_30_FlexNor_MarkerConstType Fee_30_FlexNor_InstanceStartMarker;
#endif
extern Fee_30_FlexNor_MarkerConstType Fee_30_FlexNor_SealMarker;
extern Fee_30_FlexNor_MarkerConstType Fee_30_FlexNor_CommitMarker;
extern Fee_30_FlexNor_MarkerConstType Fee_30_FlexNor_EraseMarker;

#define FEE_30_FLEXNOR_STOP_SEC_CONST_UNSPECIFIED
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
# define FEE_30_FLEXNOR_START_SEC_CODE
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Fee_30_FlexNor_ConfigInterface_SetConfig()
 *********************************************************************************************************************/
/*! \brief       Sets the FEE config pointer
 *  \details     Sets the pointer to the config that is used for FEE operation.
 *  \param[in]   cfgPtr     Pointer to the FEE config that shall be used
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_ConfigInterface_SetConfig(Fee_30_FlexNor_ConstConfigPtrType cfgPtr);

/**********************************************************************************************************************
 * Fee_30_FlexNor_ConfigInterface_GetConfig()
 *********************************************************************************************************************/
/*! \brief       Gets a pointer to the active config the component was initialized with
 *  \details     -
 *  \return      A pointer to the configuration the component was initialized with
 *  \pre         The component was initialized
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_ConstConfigPtrType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_ConfigInterface_GetConfig(void);

/**********************************************************************************************************************
 * Fee_30_FlexNor_ConfigInterface_GetBlockConfig()
 *********************************************************************************************************************/
/*! \brief       Gets the block config for a block identified by a given block number.
 *  \details     -
 *  \param[in]   blockNumber    Configured block number
 *  \return      Pointer to the block configuration. If no block with the block number is configured, NULL_PTR is 
 *               returned.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_ConstBlockConfigPtrType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_ConfigInterface_GetBlockConfig(
    Fee_30_FlexNor_BlockNumberType blockNumber);

/**********************************************************************************************************************
 * Fee_30_FlexNor_ConfigInterface_GetBlockConfigById()
 *********************************************************************************************************************/
/*! \brief       Gets the block config for a block identified by a given block id.
 *  \details     -
 *  \param[in]   partitionId    Id of the partition the block belongs to
 *  \param[in]   blockId        Id of the block
 *  \return      Pointer to the block configuration. If no block with the block number is configured, NULL_PTR is 
 *               returned.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_ConstBlockConfigPtrType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_ConfigInterface_GetBlockConfigById(
    Fee_30_FlexNor_PartitionIdType partitionId,
    Fee_30_FlexNor_BlockIdType blockId);

/**********************************************************************************************************************
 * Fee_30_FlexNor_ConfigInterface_GetPartitionConfigOfBlock()
 *********************************************************************************************************************/
/*! \brief       Gets the partition configuration the block with the given block number belongs to
 *  \details     -
 *  \param[in]   blockNumber    The block number whose partition configuration shall be determined
 *  \return      Pointer to the partition configuration. If no block with the block number is configured, NULL_PTR is 
 *               returned.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_ConstPartitionConfigPtrType, FEE_30_FLEXNOR_CODE) 
    Fee_30_FlexNor_ConfigInterface_GetPartitionConfigOfBlock(
        Fee_30_FlexNor_BlockNumberType blockNumber);

/**********************************************************************************************************************
 * Fee_30_FlexNor_ConfigInterface_GetPartitionConfig()
 *********************************************************************************************************************/
/*! \brief       Get partition configuration based on a given partition id.
 *  \details     Checks if the given partition id is configured and returns it.
 *  \param[in]   partitionId           Id of the partition whose config shall be found.
 *  \return      Pointer to the partition configuration if the given id is configure. Otherwise NULL is returned.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_ConstPartitionConfigPtrType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_ConfigInterface_GetPartitionConfig(
    Fee_30_FlexNor_PartitionIdType partitionId);

/**********************************************************************************************************************
 * Fee_30_FlexNor_ConfigInterface_GetPartitionLayout()
 *********************************************************************************************************************/
/*! \brief       Get layout option of the given partition.
 *  \details     Get layout option of the given partition.
 *  \param[in]   partitionId           Id of the partition for which the layout option shall be returned
 *  \return      Layout option of the given partition.
 *  \pre            -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_LayoutOptionType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_ConfigInterface_GetPartitionLayout(
    Fee_30_FlexNor_PartitionIdType partitionId);

/**********************************************************************************************************************
 * Fee_30_FlexNor_ConfigInterface_GetSectorLength()
 *********************************************************************************************************************/
/*! \brief       Returns the length of the sector.
 *  \details     -
 *  \param[in]   partitionId           Id of the partition the requested sector belongs to
 *  \param[in]   startAdress           Start address of the sector whose length shall be returned
 *  \return      Length of the sector.
 *  \pre            -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_LengthType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_ConfigInterface_GetSectorLength(
    Fee_30_FlexNor_PartitionIdType partitionId, 
    Fee_30_FlexNor_AddressType startAddress);

/**********************************************************************************************************************
 * Fee_30_FlexNor_ConfigInterface_GetSectorStartAddress()
 *********************************************************************************************************************/
/*! \brief       Returns the start address of the sector.
 *  \details     -
 *  \param[in]   partitionId           Id of the partition the requested sector belongs to
 *  \param[in]   targetAddress         Arbitrary address that lies inside the sector whose start address shall be found
 *  \return      Start address of the sector.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 */
FUNC(Fee_30_FlexNor_AddressType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_ConfigInterface_GetSectorStartAddress(
    Fee_30_FlexNor_PartitionIdType partitionId, 
    Fee_30_FlexNor_AddressType targetAddress);

/**********************************************************************************************************************
 * Fee_30_FlexNor_ConfigInterface_GetInternalBuffer()
 *********************************************************************************************************************/
/*! \brief       Returns the pointer to the internal buffer
 *  \details     -
 *  \return      Pointer to the internal buffer
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 */
FUNC(Fee_30_FlexNor_DataPtrType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_ConfigInterface_GetInternalBuffer(void);

/**********************************************************************************************************************
 * Fee_30_FlexNor_ConfigInterface_IsBootloaderModeEnabled()
 *********************************************************************************************************************/
/*! \brief       Returns whether the bootloader mode is enabled or not
 *  \details     -
 *  \return      TRUE                 Bootloader mode is enabled
 *               FALSE                Bootloader mode is disabled
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 */
FUNC(boolean, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_ConfigInterface_IsBootloaderModeEnabled(void);

/**********************************************************************************************************************
 * Fee_30_FlexNor_ConfigInterface_UserErrorCallback()
 *********************************************************************************************************************/
/*! \brief       Invokes the configured user error callback
 *  \details     -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_ConfigInterface_UserErrorCallback(void);


#    define FEE_30_FLEXNOR_STOP_SEC_CODE
#    include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* FEE_30_FLEXNOR_CONFIGINTERFACE_H */

/**********************************************************************************************************************
 *  END OF FILE: Fee_30_FlexNor_ConfigInterface.h
 *********************************************************************************************************************/
