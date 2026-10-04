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
/*!        \file  Fee_30_FlexNor_SectorContainer.h
 *        \brief  Sector container interface
 *      \details  Provides an interface for accessing the runtime sector objects for each configured partition.
 *         \unit  SectorContainer
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 **********************************************************************************************************************/

#if !defined (FEE_30_FLEXNOR_SECTORCONTAINER_H)
# define FEE_30_FLEXNOR_SECTORCONTAINER_H

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
 * Fee_30_FlexNor_SectorContainer_Init()
 *********************************************************************************************************************/
/*! \brief       Initializes the sector container unit.
 *  \details     This especially includes the internally stored sectors.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SectorContainer_Init(void);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SectorContainer_IsOlder()
 *********************************************************************************************************************/
/*! \brief       Checks if the given sector id that shall be checked is older than the given id it shall be compared to.
 *  \details     -
 *  \param[in]   idToCheck      Id that shall be checked if its older than the other id.
 *  \param[in]   idToCompare    Id that is compared the sector id that shall be checked.
 *  \return      TRUE if the checked sector id is older then the compared id, otherwise FALSE.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(boolean, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SectorContainer_IsOlder(Fee_30_FlexNor_SectorIdType idToCheck, Fee_30_FlexNor_SectorIdType idToCompare);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SectorContainer_Get()
 *********************************************************************************************************************/
/*! \brief       Gets the pointer to the sector with the given sector id.
 *  \details     In case the checkValidity flag is set, this function only returns valid sectors.
 *  \param[in]   partitionId            Id of the partition that contains the sector.
 *  \param[in]   sectorId               Id of the sector
 *  \param[in]   checkValidity          TRUE: Only for valid sectors is searched
 *                                      FALSE: For all sectos with the given Id is searched
 *  \return      Pointer to the sector with the given id.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_SectorPtrType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SectorContainer_Get(Fee_30_FlexNor_PartitionIdType partitionId,
    Fee_30_FlexNor_SectorIdType sectorId, boolean getOnlyValid);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SectorContainer_GetSectorIdDifference()
 *********************************************************************************************************************/
/*! \brief       Calculates the sector id difference.
 *  \details     -
 *  \param[in]   newerSectorId        Sector Id of the newer sector.
 *  \param[in]   olderSectorId        Sector Id of the older sector.
 *  \return      Difference of given sector ids.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(uint8, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SectorContainer_GetSectorIdDifference(Fee_30_FlexNor_SectorIdType newerSectorId,
    Fee_30_FlexNor_SectorIdType olderSectorId);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SectorContainer_GetSectorIdSpan()
 *********************************************************************************************************************/
/*! \brief       Gets the span size be the oldest and newest sector id of the given partition
 *  \details     -
 *  \param[in]   partitionId    Pointer to the context containing the garbage collection information. Must not be NULL.
 *  \return      Size of the id span between the oldest and newest sector
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(uint8, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SectorContainer_GetSectorIdSpan(Fee_30_FlexNor_PartitionIdType partitionId);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SectorContainer_GetFirst()
 *********************************************************************************************************************/
/*! \brief       Gets the pointer to the first stored sector.
 *  \details     -
 *  \param[in]   partitionId               Id of the partition the first sector shall be returned for.
 *  \return      Pointer to the first sector of the partition.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_SectorPtrType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SectorContainer_GetFirst(Fee_30_FlexNor_PartitionIdType partitionId);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SectorContainer_GetNext()
 *********************************************************************************************************************/
/*! \brief       Gets the next sector based on the given current sector.
 *  \details     The function returns the next stored sector while ignoring all sector properties. 
 *               If there is no subsequent sector, NULL is returned.
 *  \param[in]   current               Pointer to the current sector thats successor shall be returned.
 *  \return      Pointer to the subsequent sector, if none exists, NULL is returned.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_SectorPtrType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SectorContainer_GetNext(Fee_30_FlexNor_ConstSectorPtrType current);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SectorContainer_GetOldestValid()
 *********************************************************************************************************************/
/*! \brief       Gets the pointer to the oldest valid sector of the given partition.
 *  \details     -
 *  \param[in]   partitionId               Id of the partition the oldest sector shall be returned for.
 *  \return      Pointer to the oldest valid sector object of the partition, if no valid sector was found, NULL is returned.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_SectorPtrType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SectorContainer_GetOldestValid(Fee_30_FlexNor_PartitionIdType partitionId);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SectorContainer_GetNextNewerValid()
 *********************************************************************************************************************/
/*! \brief       Gets the pointer to the next newer valid sector of the partition.
 *  \details     Based on the given sector, the next newer valid sector is returned. If there is no subsequent sector, NULL is returned.
 *  \param[in]   current               Pointer to the current sector thats successor shall be returned.
 *  \return      Pointer to the subsequent sector, if none exists, NULL is returned.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_SectorPtrType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SectorContainer_GetNextNewerValid(Fee_30_FlexNor_SectorPtrType current);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SectorContainer_GetNewestValid()
 *********************************************************************************************************************/
/*! \brief       Gets the pointer to the newest valid sector of the given partition.
 *  \details     -
 *  \param[in]   partitionId               Id of the partition the newest sector shall be returned for.
 *  \return      Pointer to the newest valid sector object of the partition, if no valid sector was found, NULL is 
 *               returned.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_SectorPtrType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SectorContainer_GetNewestValid(
    Fee_30_FlexNor_PartitionIdType partitionId);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SectorContainer_GetNextSectorId()
 *********************************************************************************************************************/
/*! \brief       Gets the id of the sector that is used for the next sector allocation in the given partition
 *  \details     -
 *  \param[in]   partitionId               Id of the partition the next sector id shall be calculated for
 *  \return      Id of the next sector
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_SectorIdType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SectorContainer_GetNextSectorId(Fee_30_FlexNor_PartitionIdType partitionId);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SectorContainer_GetNextEraseCycle()
 *********************************************************************************************************************/
/*! \brief       Gets the subsequent erase cycle counter value for the given sector.
 *  \details     Evaluates the validity of the given sector and either increases the existing erase cycle by one
 *               or uses the average erase cycle counter from other valid sectors of the partition.
 *  \param[in]   sector     Pointer to the sector whose next erase cycle shall be found
 *  \return      Next erase cycle counter value
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_EraseCycleCounterType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SectorContainer_GetNextEraseCycle(
    Fee_30_FlexNor_ConstSectorPtrType sector);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SectorContainer_GetSectorByAddress()
 *********************************************************************************************************************/
/*! \brief       Gets the sector of the given partition which contains the given address. 
 *  \details     -
 *  \param[in]   partitionId    Id of the partition.
 *  \param[in]   sectorAddress  Any address within the sector. Not necessarily the start address.
 *  \return      Pointer to the sector which contains the given address. If it does not exist NULL is returned.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_SectorPtrType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SectorContainer_GetSectorByAddress(
    Fee_30_FlexNor_PartitionIdType partitionId,
    Fee_30_FlexNor_AddressType sectorAddress
    );

/**********************************************************************************************************************
 * Fee_30_FlexNor_SectorContainer_GetEraseCycleCounter()
 *********************************************************************************************************************/
/*! \brief       Calculates the maximal erase cycle counter (ECC) of all sectors belonging to the provided partition.
 *  \details     -
 *  \param[in]   partitionId    Id of the partition.
 *  \return      Maximal ECC of all sectors for the given partition.
 *  \pre         The provided partition has to be already started up.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_EraseCycleCounterType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SectorContainer_GetEraseCycleCounter(Fee_30_FlexNor_PartitionIdType partitionId);

# define FEE_30_FLEXNOR_STOP_SEC_CODE
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* FEE_30_FLEXNOR_SECTORCONTAINER_H */

/**********************************************************************************************************************
 *  END OF FILE: Fee_30_FlexNor_SectorContainer.h
 *********************************************************************************************************************/
