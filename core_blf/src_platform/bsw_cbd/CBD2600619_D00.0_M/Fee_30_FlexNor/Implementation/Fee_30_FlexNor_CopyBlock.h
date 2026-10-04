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
/*!        \file  Fee_30_FlexNor_CopyBlock.h
 *        \brief  Copy block interface
 *      \details  Provides the interface for accessing and handling the copy block.
 *         \unit  CopyBlock
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 **********************************************************************************************************************/

#if !defined (FEE_30_FLEXNOR_COPYBLOCK_H)
# define FEE_30_FLEXNOR_COPYBLOCK_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Fee_30_FlexNor_Types.h"
#include "Fee_30_FlexNor_ConfigInterface.h"
#include "Fee_30_FlexNor_Sector.h"

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

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
# define FEE_30_FLEXNOR_START_SEC_CODE
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Fee_30_FlexNor_CopyBlock_Init()
 *********************************************************************************************************************/
/*! \brief       Initialize the copy block unit
 *  \details     -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_CopyBlock_Init(void);

/**********************************************************************************************************************
 * Fee_30_FlexNor_CopyBlock_Copy()
 *********************************************************************************************************************/
/*! \brief       Copies the source block instance from the source chunk to the target sector.
 *  \details     -
 *  \param[in]   partitionId        Id of the partition the copy block shall be executed for.
 *  \param[in]   blockId            Id of the block the copy operation shall be executed for.
 *  \param[in]   sourceSector       Pointer to an explicit source sector.
 *  \param[in]   targetSector       Pointer to the sector the valid data from the source sector is copied to.
 *  \param[in]   chunkOffset        Offset of the chunk in pages relative to the sector start address. 
 *  \param[in]   resetInstanceCount Flag indicating that the instance count of the allocated chunk shall be reset to one. 
 *  \param[in]   resultCbk          The result callback that is called in case the service is complete. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous FALSE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_CopyBlock_Copy(
    Fee_30_FlexNor_PartitionIdType partitionId,
    Fee_30_FlexNor_BlockIdType blockId, 
    Fee_30_FlexNor_SectorPtrType sourceSector,
    Fee_30_FlexNor_SectorPtrType targetSector, 
    Fee_30_FlexNor_PagebasedOffsetType chunkOffset, 
    boolean resetInstanceCount,          
    Fee_30_FlexNor_ResultCallback resultCbk);

# define FEE_30_FLEXNOR_STOP_SEC_CODE
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* FEE_30_FLEXNOR_COPYBLOCK_H */

/**********************************************************************************************************************
 *  END OF FILE: Fee_30_FlexNor_CopyBlock.h
 *********************************************************************************************************************/
