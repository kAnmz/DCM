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
/*!        \file  Fee_30_FlexNor_LookupTable.h
 *        \brief  Lookup table interface
 *      \details  Provides the interface for accessing and handling the lookup table.
 *         \unit  LookupTable
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 **********************************************************************************************************************/

#if !defined (FEE_30_FLEXNOR_LOOKUPTABLE_H)
# define FEE_30_FLEXNOR_LOOKUPTABLE_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Fee_30_FlexNor_Types.h"
#include "Fee_30_FlexNor_ConfigInterface.h"
#include "Fee_30_FlexNor_InternalJobs.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef struct
{
    Fee_30_FlexNor_SectorIdType SectorId;                  /*!< Sector id of the sector where the chunk lies.*/
    Fee_30_FlexNor_PagebasedOffsetType ChunkOffset;        /*!< Offset of the chunk in pages relative to the sector 
                                                                start address.*/
} Fee_30_FlexNor_LookupTable_LinkType;                     /*!< Structure for easy access to the lookup table entry of 
                                                                a corresponding block.*/

typedef P2VAR(Fee_30_FlexNor_LookupTable_LinkType, AUTOMATIC, FEE_30_FLEXNOR_VAR) 
    Fee_30_FlexNor_LookupTable_LinkPtrType;
typedef P2CONST(Fee_30_FlexNor_LookupTable_LinkType, AUTOMATIC, FEE_30_FLEXNOR_VAR) 
    Fee_30_FlexNor_LookupTable_ConstLinkPtrType;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
# define FEE_30_FLEXNOR_START_SEC_CODE
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_Init()
 *********************************************************************************************************************/
/*! \brief       Initialize the lookup table unit
 *  \details     -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_Init(void);

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_GetLink()
 *********************************************************************************************************************/
/*! \brief       Gets the stored lookup table link for a given block in a given partition.
 *  \details     -
 *  \param[in]   partitionId    Id of the partition the given block resides in
 *  \param[in]   blockId        Id of the block whose link shall be get
 *  \return      The link currently stored in the lookup table for the block.
 *               If no entry was found for the given partition and block, the link is 0.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_LookupTable_LinkType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_GetLink(
    Fee_30_FlexNor_PartitionIdType partitionId, Fee_30_FlexNor_BlockIdType blockId);

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_SetLinkIfNewer()
 *********************************************************************************************************************/
/*! \brief       Updates the link in the lookup table for a given block in a given partition
 *  \details     The link is updated if the given chunk location is chronological newer than the currently stored one.
 *               This automatically also leads to the link being marked as verified.
 *  \param[in]   partitionId          Id of the partition the given block resides in
 *  \param[in]   blockId              Id of the block whose link shall be set
 *  \param[in]   link                 Link to the chunk
 *  \param[in]   reallocationRequired Indicates if the chunk needs a reallocation
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_SetLinkIfNewer(
    Fee_30_FlexNor_PartitionIdType partitionId, Fee_30_FlexNor_BlockIdType blockId, 
    Fee_30_FlexNor_LookupTable_LinkType link, Fee_30_FlexNor_StructureFlagsType reallocationRequired);

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_IsValid()
 *********************************************************************************************************************/
/*! \brief       Checks if the lookup table of the given partition is valid.
 *  \details     -
 *  \param[in]   partitionId    Id of the partition whose lookup table validity shall be checked
 *  \return      TRUE           Lookup table is valid
 *               FALSE          Lookup table is invalid
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(boolean, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_IsValid(Fee_30_FlexNor_PartitionIdType partitionId);

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_Invalidate()
 *********************************************************************************************************************/
/*! \brief       Invalidates all lookup table links for the given partition
 *  \details     Sets all links to an invalid value and resets the validation flags.
 *  \param[in]   partitionId    Id of the partition whose lookup table links shall be invalidated
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_Invalidate(Fee_30_FlexNor_PartitionIdType partitionId);

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_IsLoadedLutSuitableForPartialRecovery()
 *********************************************************************************************************************/
/*! \brief       Checks if the loaded lookup table is appropriate for partial recovery.
 *  \details     -
 *  \param[in]   partitionId          Id of which partition the LUT shall be checked.
 *  \return      TRUE                 A partial recovery can be performed. 
 *               FALSE                A full recovery must be performed. 
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(boolean, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_IsLoadedLutSuitableForPartialRecovery(
    Fee_30_FlexNor_PartitionIdType partitionId);

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_FullRecovery()
 *********************************************************************************************************************/
/*! \brief       Scan every available sector of the partition completely and build up the lookup table out of it
 *  \details     In case the lookup table is lost (or never written), this service will build it up again.
 *  \param[in]   partitionId    Id of the partition the recovery shall be made
 *  \param[in]   resultCbk      The result callback that is called in case the service is complete. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous FALSE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_FullRecovery(Fee_30_FlexNor_PartitionIdType partitionId, 
    Fee_30_FlexNor_ResultCallback resultCbk);

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_PartialRecovery()
 *********************************************************************************************************************/
/*! \brief       Scan every available sector of the partition partially and build up the lookup table out of it
 *  \details     The scan of every sector is stared from the latest known chunk. If no chunk is known in the sector,
 *               a full scan is executed.
 *  \param[in]   partitionId    Id of the partition the recovery shall be made
 *  \param[in]   resultCbk      The result callback that is called in case the service is complete. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous FALSE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_PartialRecovery(Fee_30_FlexNor_PartitionIdType partitionId, 
    Fee_30_FlexNor_ResultCallback resultCbk);

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_PersistIfRequired()
 *********************************************************************************************************************/
/*! \brief       Persist the content of the lookup table for the given partition if required.
 *  \details     Persists the lookup table in case it is required by the metric or it is explicitly requested.
 *  \param[in]   partitionId    Id of the target partition
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous FALSE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_PersistIfRequired(
        Fee_30_FlexNor_PartitionIdType partitionId);

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_Load()
 *********************************************************************************************************************/
/*! \brief       Loads the content of the lookup table for the given partition
 *  \details     Searches for the most recent LUT chunk and loads its content into the RAM.
 *  \param[in]   partitionId    Id of the target partition
 *  \param[in]   resultCbk      The result callback that is called in case the service is complete. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous FALSE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_Load(Fee_30_FlexNor_PartitionIdType partitionId, 
    Fee_30_FlexNor_ResultCallback resultCbk);


/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_IsReallocationRequested()
 *********************************************************************************************************************/
/*! \brief       Check if chunk reallocation is requested for the given block.
 *  \details     -
 *  \param[in]   partitionId          Id of the partition the given block resides in
 *  \param[in]   blockId              Id of the block which shall be checked
 *  \return      TRUE  Reallocation is requested.
 *               FALSE Reallocation is not requested.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(boolean, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_IsReallocationRequested(
    Fee_30_FlexNor_PartitionIdType partitionId, Fee_30_FlexNor_BlockIdType blockId);

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_RequestChunkReallocation()
 *********************************************************************************************************************/
/*! \brief       Sets or clear the flag which indicates that the chunk reallocation is requested.
 *  \details     -
 *  \param[in]   partitionId          Id of the partition the given block resides in
 *  \param[in]   blockId              Block Id of the chunk which shall be reallocated.
 *  \param[in]   reallocationRequired TRUE: Reallocation flag is set.
 *                                    FALSE: Reallocation flag is cleared.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_RequestChunkReallocation(
    Fee_30_FlexNor_PartitionIdType partitionId, Fee_30_FlexNor_BlockIdType blockId, 
    Fee_30_FlexNor_StructureFlagsType reallocationRequired);

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_IncrementNewChunkCounter()
 *********************************************************************************************************************/
/*! \brief       Increments the counter which stores the number of chunks which were allocated since the last 
 *               storage of the LUT.
 *  \details     The counter is incremented, in case the counter is not invalid. 
 *  \param[in]   partitionId          Id of the partition which contains the chunks.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_IncrementNewChunkCounter(
    Fee_30_FlexNor_PartitionIdType partitionId);

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_RequestPersistLut()
 *********************************************************************************************************************/
/*! \brief       Sets the flag which indicatest, that the Lut of the given partition shall be peresisted.
 *  \details     -
 *  \param[in]   partitionId          Id of which partition the LUT shall be stored.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_RequestPersistLut(
    Fee_30_FlexNor_PartitionIdType partitionId);


# define FEE_30_FLEXNOR_STOP_SEC_CODE
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* FEE_30_FLEXNOR_LOOKUPTABLE_H */

/**********************************************************************************************************************
 *  END OF FILE: Fee_30_Flexnor_LookupTable.h
 *********************************************************************************************************************/
