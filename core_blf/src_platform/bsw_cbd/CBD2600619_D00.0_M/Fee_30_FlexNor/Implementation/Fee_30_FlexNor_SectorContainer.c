/**********************************************************************************************************************
 *  COPYRIGHT
 *  --------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2025 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  --------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/*!        \file  Fee_30_FlexNor_SectorContainer.c
 *        \brief  Sector container implementation
 *      \details  Provides the implementation to access the partitions sector objects.
 *         \unit  SectorContainer
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#define FEE_30_FLEXNOR_SECTORCONTAINER_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Fee_30_FlexNor_SectorContainer.h"

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
#define FEE_30_FLEXNOR_SECTORCONTAINER_MAX_SECTOR_ID (254u)
#define FEE_30_FLEXNOR_SECTORCONTAINER_MIN_SECTOR_ID (1u)
#define FEE_30_FLEXNOR_SECTORCONTAINER_WRAPAROUND_LOWBOARDER (191u)
#define FEE_30_FLEXNOR_SECTORCONTAINER_WRAPAROUND_HIGHBOARDER (64u)

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/
#if !defined (FEE_30_FLEXNOR_LOCAL) /* COV_FEE_30_FLEXNOR_COMPATIBILITY */
# define FEE_30_FLEXNOR_LOCAL static
#endif

#if !defined (FEE_30_FLEXNOR_LOCAL_INLINE) /* COV_FEE_30_FLEXNOR_COMPATIBILITY */
# define FEE_30_FLEXNOR_LOCAL_INLINE LOCAL_INLINE
#endif

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
#define FEE_30_FLEXNOR_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Stores all sectors of all partitions. */
FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_SectorType Fee_30_FlexNor_Sectors[FEE_30_FLEXNOR_CONFIGURED_PARTITIONS][FEE_30_FLEXNOR_MAX_CONFIGURED_SECTORS]; /* PRQA S 3218 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */

#define FEE_30_FLEXNOR_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define FEE_30_FLEXNOR_START_SEC_CODE
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Fee_30_FlexNor_SectorContainer_InitializeSector()
 *********************************************************************************************************************/
/*! \brief       Initializes the given sector object.
 *  \details     -
 *  \param[in]   partitionId          Id of the partition the sector belongs to.
 *  \param[in]   startAddress         Configured start address of the sector. 
 *  \param[in]   length               Configured length of the sector.
 *  \param[in]   sector               Pointer to the sector that shall be initialized.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FEE_30_FLEXNOR_LOCAL FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SectorContainer_InitializeSector(Fee_30_FlexNor_PartitionIdType partitionId, 
    Fee_30_FlexNor_AddressType startAddress,
    Fee_30_FlexNor_LengthType length,
    Fee_30_FlexNor_SectorPtrType sector);

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
 /**********************************************************************************************************************
 * Fee_30_FlexNor_SectorContainer_InitializeSector()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FEE_30_FLEXNOR_LOCAL FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SectorContainer_InitializeSector(Fee_30_FlexNor_PartitionIdType partitionId, 
    Fee_30_FlexNor_AddressType startAddress,
    Fee_30_FlexNor_LengthType length,
    Fee_30_FlexNor_SectorPtrType sector)
{
    sector->PartitionId = partitionId;                              /* SBSW_Fee_30_FlexNor_SectorInit */
    sector->Validity = FEE_30_FLEXNOR_EMPTY;                        /* SBSW_Fee_30_FlexNor_SectorInit */
    sector->ErrorLocation = FEE_30_FLEXNOR_SECTOR_ERROR_NOERROR;    /* SBSW_Fee_30_FlexNor_SectorInit */
    sector->StartAddress = startAddress;                            /* SBSW_Fee_30_FlexNor_SectorInit */
    sector->Length = length;                                        /* SBSW_Fee_30_FlexNor_SectorInit */
    sector->SectorId = 0u;                                          /* SBSW_Fee_30_FlexNor_SectorInit */
    sector->EraseCycle = 0u;                                        /* SBSW_Fee_30_FlexNor_SectorInit */
    sector->LutChunkLink.Target = 0u;                               /* SBSW_Fee_30_FlexNor_SectorInit */
    sector->LutChunkLink.Validity = FEE_30_FLEXNOR_EMPTY;           /* SBSW_Fee_30_FlexNor_SectorInit */
    sector->SourceSectorId = FEE_30_FLEXNOR_SECTOR_ID_INVALID;      /* SBSW_Fee_30_FlexNor_SectorInit */
    sector->NextFreeAddress = 0u;                                   /* SBSW_Fee_30_FlexNor_SectorInit */
    sector->SelectedForRecoveryGarbageCollection = FALSE;           /* SBSW_Fee_30_FlexNor_SectorInit */
}

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
 /**********************************************************************************************************************
 * Fee_30_FlexNor_SectorContainer_Init()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SectorContainer_Init(void)
{
    Fee_30_FlexNor_ConstConfigPtrType activeConfig = Fee_30_FlexNor_ConfigInterface_GetConfig();

    for(uint8 pIndex = 0; pIndex < activeConfig->PartitionCount; pIndex++)
    {
        Fee_30_FlexNor_ConstPartitionConfigPtrType partitionConfig = &activeConfig->Partitions[pIndex];

        for(uint8 sIndex = 0; sIndex < partitionConfig->SectorCount; sIndex++)
        {
            Fee_30_FlexNor_SectorContainer_InitializeSector(partitionConfig->PartitionId, 
            partitionConfig->Sectors[sIndex].StartAddress,
            partitionConfig->Sectors[sIndex].Length,
            &Fee_30_FlexNor_Sectors[pIndex][sIndex]); /* SBSW_Fee_30_FlexNor_SectorInit */
        }
    }
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SectorContainer_IsOlder()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(boolean, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SectorContainer_IsOlder(Fee_30_FlexNor_SectorIdType idToCheck, Fee_30_FlexNor_SectorIdType idToCompare)
{
    boolean isOlder = FALSE;

    /*
     * Because of the id wraparound that must be supported, the condition which sector is older is quite complex. 
     * 
     * The trivial case is that the id to check is smaller than the compare id. This check is only valid if the id to check is not in the first quantile
     * while the compare id is in the fourth.
     * 
     * Additionally the id to check is older in case its in the fourth quantile of the id range while the compare id is in the first quantile.
     */

    if(((idToCheck < idToCompare) && !((idToCheck < FEE_30_FLEXNOR_SECTORCONTAINER_WRAPAROUND_HIGHBOARDER) && (idToCompare > FEE_30_FLEXNOR_SECTORCONTAINER_WRAPAROUND_LOWBOARDER))) || 
       ((idToCheck > FEE_30_FLEXNOR_SECTORCONTAINER_WRAPAROUND_LOWBOARDER) && (idToCompare < FEE_30_FLEXNOR_SECTORCONTAINER_WRAPAROUND_HIGHBOARDER)))
    {
        isOlder = TRUE;
    }

    return isOlder;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SectorContainer_Get()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_SectorPtrType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SectorContainer_Get(Fee_30_FlexNor_PartitionIdType partitionId,
    Fee_30_FlexNor_SectorIdType sectorId, boolean getOnlyValid)
{
    Fee_30_FlexNor_SectorPtrType targetSector = NULL_PTR;
    Fee_30_FlexNor_SectorPtrType currentSector = Fee_30_FlexNor_SectorContainer_GetFirst(partitionId);

    while(currentSector != NULL_PTR)
    { 
        if((currentSector->SectorId == sectorId)
            && ((getOnlyValid == FALSE) || (currentSector->Validity == FEE_30_FLEXNOR_VALID)))
        {
            targetSector = currentSector;
            break;
        }

        currentSector = Fee_30_FlexNor_SectorContainer_GetNext(currentSector); /* SBSW_Fee_30_FlexNor_LoopStoredSectors */
    }

    return targetSector;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SectorContainer_GetSectorIdDifference()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(uint8, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SectorContainer_GetSectorIdDifference(Fee_30_FlexNor_SectorIdType newerSectorId,
    Fee_30_FlexNor_SectorIdType olderSectorId)
{
    uint8 idDifference = 0u;
    if(newerSectorId >= olderSectorId)
    {
        idDifference = newerSectorId - olderSectorId;
    }
    else
    {
        idDifference = (FEE_30_FLEXNOR_SECTORCONTAINER_MAX_SECTOR_ID - olderSectorId) + newerSectorId;
    }

    return idDifference;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SectorContainer_GetSectorIdSpan()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(uint8, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SectorContainer_GetSectorIdSpan(
    Fee_30_FlexNor_PartitionIdType partitionId)
{
    Fee_30_FlexNor_SectorIdType oldestId = 0u;
    Fee_30_FlexNor_SectorIdType newestId = 0u;
    Fee_30_FlexNor_SectorPtrType currentSector = Fee_30_FlexNor_SectorContainer_GetOldestValid(partitionId);

    if(currentSector != NULL_PTR)
    {
        oldestId = currentSector->SectorId;
    }

    while(currentSector != NULL_PTR)
    {
        newestId = currentSector->SectorId;
        currentSector = Fee_30_FlexNor_SectorContainer_GetNextNewerValid(currentSector); /* SBSW_Fee_30_FlexNor_LoopStoredSectors */
    }

    return Fee_30_FlexNor_SectorContainer_GetSectorIdDifference(newestId, oldestId);
}

 /**********************************************************************************************************************
 * Fee_30_FlexNor_SectorContainer_GetFirst()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Fee_30_FlexNor_SectorPtrType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SectorContainer_GetFirst(Fee_30_FlexNor_PartitionIdType partitionId)
{
    return &Fee_30_FlexNor_Sectors[partitionId][0];
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SectorContainer_GetNext()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_SectorPtrType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SectorContainer_GetNext(Fee_30_FlexNor_ConstSectorPtrType current)
{
    Fee_30_FlexNor_PartitionIdType partitionId = current->PartitionId;
    Fee_30_FlexNor_ConstPartitionConfigPtrType partitionConfig = Fee_30_FlexNor_ConfigInterface_GetPartitionConfig(partitionId);
    Fee_30_FlexNor_SectorPtrType nextSector = NULL_PTR;
    
    for(uint8 index = 0u; index < partitionConfig->SectorCount; index++)
    {
        if((Fee_30_FlexNor_Sectors[partitionId][index].StartAddress == current->StartAddress) && (index < (partitionConfig->SectorCount - 1u)))
        {
            nextSector = &Fee_30_FlexNor_Sectors[partitionId][index + 1u];
            break;
        }
    }

    return nextSector;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SectorContainer_GetOldestValid()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_SectorPtrType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SectorContainer_GetOldestValid(Fee_30_FlexNor_PartitionIdType partitionId)
{
    Fee_30_FlexNor_ConstPartitionConfigPtrType partitionConfig = Fee_30_FlexNor_ConfigInterface_GetPartitionConfig(partitionId);
    Fee_30_FlexNor_SectorPtrType oldestSector = NULL_PTR;

    for(uint8 index = 0u; index < partitionConfig->SectorCount; index++)
    {
        Fee_30_FlexNor_SectorPtrType sector = &Fee_30_FlexNor_Sectors[partitionId][index];

        if(sector->Validity == FEE_30_FLEXNOR_VALID)
        {            
            if((oldestSector == NULL_PTR) || (Fee_30_FlexNor_SectorContainer_IsOlder(sector->SectorId, oldestSector->SectorId) == TRUE))
            {
                oldestSector = sector;
            }
        }
    }

    return oldestSector;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SectorContainer_GetNextNewerValid()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_SectorPtrType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SectorContainer_GetNextNewerValid(Fee_30_FlexNor_SectorPtrType current)
{
    Fee_30_FlexNor_PartitionIdType partitionId = current->PartitionId;
    Fee_30_FlexNor_ConstPartitionConfigPtrType partitionConfig = Fee_30_FlexNor_ConfigInterface_GetPartitionConfig(partitionId);
    Fee_30_FlexNor_SectorPtrType nextSector = current;

    for(uint8 index = 0u; index < partitionConfig->SectorCount; index++)
    {
        Fee_30_FlexNor_SectorPtrType storedSector = &Fee_30_FlexNor_Sectors[partitionId][index];

        if(storedSector->Validity == FEE_30_FLEXNOR_VALID)
        {
            /* 
             * The currently processed stored sector is used as next sector if it is basically newer than the given sector and
             * it is older than the currently set next sector or the currently set next sector is still equal to the given sector 
             * (i.e) no next sector was found yet.
             */

            if((Fee_30_FlexNor_SectorContainer_IsOlder(current->SectorId, storedSector->SectorId) == TRUE) && 
            ((Fee_30_FlexNor_SectorContainer_IsOlder(storedSector->SectorId, nextSector->SectorId) == TRUE) || (nextSector->SectorId == current->SectorId)))
            {
                nextSector = storedSector;
            }
        }
    }

    if(nextSector->SectorId == current->SectorId)
    {
        nextSector = NULL_PTR;
    }

    return nextSector;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SectorContainer_GetNewestValid()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_SectorPtrType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SectorContainer_GetNewestValid(Fee_30_FlexNor_PartitionIdType partitionId)
{
    Fee_30_FlexNor_ConstPartitionConfigPtrType partitionConfig = Fee_30_FlexNor_ConfigInterface_GetPartitionConfig(partitionId);
    Fee_30_FlexNor_SectorPtrType newestSector = NULL_PTR;

    for(uint8 index = 0u; index < partitionConfig->SectorCount; index++)
    {
        Fee_30_FlexNor_SectorPtrType sector = &Fee_30_FlexNor_Sectors[partitionId][index];

        if(sector->Validity == FEE_30_FLEXNOR_VALID)
        {            
            if((newestSector == NULL_PTR) || (Fee_30_FlexNor_SectorContainer_IsOlder(newestSector->SectorId, sector->SectorId) == TRUE))
            {
                newestSector = sector;
            }
        }
    }

    return newestSector;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SectorContainer_GetNextSectorId()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_SectorIdType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SectorContainer_GetNextSectorId(Fee_30_FlexNor_PartitionIdType partitionId)
{
    Fee_30_FlexNor_SectorPtrType newestValidSector = Fee_30_FlexNor_SectorContainer_GetOldestValid(partitionId);
    Fee_30_FlexNor_SectorIdType nextSectorId = FEE_30_FLEXNOR_SECTORCONTAINER_MIN_SECTOR_ID;

    while(newestValidSector != NULL_PTR)
    {
        nextSectorId = newestValidSector->SectorId + 1u;
        newestValidSector = Fee_30_FlexNor_SectorContainer_GetNextNewerValid(newestValidSector); /* SBSW_Fee_30_FlexNor_LoopStoredSectors */
    }

    if(nextSectorId > FEE_30_FLEXNOR_SECTORCONTAINER_MAX_SECTOR_ID)
    {
        nextSectorId = FEE_30_FLEXNOR_SECTORCONTAINER_MIN_SECTOR_ID;
    }

    return nextSectorId;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SectorContainer_GetNextEraseCycle()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_EraseCycleCounterType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SectorContainer_GetNextEraseCycle(
    Fee_30_FlexNor_ConstSectorPtrType sector)
{
    Fee_30_FlexNor_EraseCycleCounterType ecc = 0u;

    if(sector->ErrorLocation == FEE_30_FLEXNOR_SECTOR_ERROR_PROPERTIESINVALID)
    {
        uint16 validSectorCount = 0u;
        uint32 eraseCycleSum = 0u;
        Fee_30_FlexNor_SectorPtrType currentSector = Fee_30_FlexNor_SectorContainer_GetOldestValid(sector->PartitionId);

        while(currentSector != NULL_PTR)
        {
            eraseCycleSum += currentSector->EraseCycle;
            validSectorCount++;

            currentSector = Fee_30_FlexNor_SectorContainer_GetNextNewerValid(currentSector); /* SBSW_Fee_30_FlexNor_LoopStoredSectors */
        }

        if(validSectorCount > 0u)
        {
            ecc = eraseCycleSum / validSectorCount;
        }
    }
    else
    {
        ecc = sector->EraseCycle + 1u;
    }

    return ecc;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SectorContainer_GetSectorByAddress()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_SectorPtrType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SectorContainer_GetSectorByAddress(
    Fee_30_FlexNor_PartitionIdType partitionId,
    Fee_30_FlexNor_AddressType sectorAddress
    )
{
    Fee_30_FlexNor_ConstPartitionConfigPtrType partitionConfig = Fee_30_FlexNor_ConfigInterface_GetPartitionConfig(partitionId);
    Fee_30_FlexNor_SectorPtrType sectorReturn = NULL_PTR;

    for(uint8 index = 0u; index < partitionConfig->SectorCount; index++)
    {
        Fee_30_FlexNor_SectorPtrType sector = &Fee_30_FlexNor_Sectors[partitionId][index];

        if((sector->StartAddress <= sectorAddress) && (sectorAddress < (sector->StartAddress + sector->Length)))
        {
            sectorReturn = sector;
            break;
        }
    }

    return sectorReturn;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SectorContainer_GetEraseCycleCounter()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_EraseCycleCounterType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SectorContainer_GetEraseCycleCounter(Fee_30_FlexNor_PartitionIdType partitionId)
{
    Fee_30_FlexNor_ConstPartitionConfigPtrType partitionConfig = Fee_30_FlexNor_ConfigInterface_GetPartitionConfig(partitionId);
    Fee_30_FlexNor_EraseCycleCounterType maximalEraseCycleCount = 0u;

    for(uint8 index = 0u; index < partitionConfig->SectorCount; index++)
    {
        Fee_30_FlexNor_ConstSectorPtrType sector = &Fee_30_FlexNor_Sectors[partitionId][index];

        if ((sector->ErrorLocation != FEE_30_FLEXNOR_SECTOR_ERROR_PROPERTIESINVALID) && (sector->EraseCycle > maximalEraseCycleCount))
        {
            maximalEraseCycleCount = sector->EraseCycle;
        }
    }

    return maximalEraseCycleCount;
}

#define FEE_30_FLEXNOR_STOP_SEC_CODE
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: Fee_30_FlexNor_SectorContainer.c
 *********************************************************************************************************************/
