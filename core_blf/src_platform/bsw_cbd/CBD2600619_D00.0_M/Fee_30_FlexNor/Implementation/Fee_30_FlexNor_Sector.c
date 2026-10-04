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
/*!        \file  Fee_30_FlexNor_Sector.c
 *        \brief  Sector unit implementation
 *      \details  Implementation of the sector services.
 *         \unit  Sector
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#define FEE_30_FLEXNOR_SECTOR_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Fee_30_FlexNor_Sector.h"
#include "Fee_30_FlexNor_SectorInternal.h"
#include "Fee_30_FlexNor_SectorMachine.h"

#include "Fee_30_FlexNor_ConfigInterface.h"
#include "Fee_30_FlexNor_Scheduler.h"
#include "Fee_30_FlexNor_Shared.h"

#include "Fee_30_FlexNor_ChunkSearch.h"
#include "Fee_30_FlexNor_InternalJobs.h"
#include "Fee_30_FlexNor_LookupTable.h"
#include "Fee_30_FlexNor_FlashAccess.h"
#include "Fee_30_FlexNor_ChunkFactory.h"
#include "Fee_30_FlexNor_DiagnosticHandler.h"

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

#define FEE_30_FLEXNOR_SECTORHEADER_SECTORID_SIZE 1u
#define FEE_30_FLEXNOR_SECTORHEADER_ERASECYCLECOUNTER_SIZE 4u
#define FEE_30_FLEXNOR_SECTORHEADER_MULTIFIELD_SIZE 1u
#define FEE_30_FLEXNOR_SECTORHEADER_GCREASON_SIZE_IN_BITS 2u
#define FEE_30_FLEXNOR_SECTORHEADER_TYPE_SIZE_IN_BITS 2u
#define FEE_30_FLEXNOR_SECTORHEADER_PROPERTIES_SIZE 7u              /*!< Properties include Sector Id, erase cycle counter, 4 reserved bits, gc reason and layout type */
#define FEE_30_FLEXNOR_SECTORHEADER_PROPERTIESCHECKSUM_SIZE 1u
#define FEE_30_FLEXNOR_SECTORHEADER_LUTLINKTARGET_SIZE 4u
#define FEE_30_FLEXNOR_SECTORHEADER_LUTLINKCHECKSUM_SIZE 1u
#define FEE_30_FLEXNOR_SECTORHEADER_SOURCESECTOR_SIZE 1u

/* Indices of the single parts in the buffer after the sector header meta data was read in */

/* Indices inside the first write alignment */
#define FEE_30_FLEXNOR_SECTORHEADER_SECTORID_INDEX 0u
#define FEE_30_FLEXNOR_SECTORHEADER_ERASECYCLECOUNTER_INDEX 1u
#define FEE_30_FLEXNOR_SECTORHEADER_MULTIFIELD_INDEX 5u
#define FEE_30_FLEXNOR_SECTORHEADER_PROPERTIESCHECKSUM_INDEX 6u

/* Indices of the single parts in the buffer after the sector header additional info was read in */

/* Indices inside the first write alignment */
#define FEE_30_FLEXNOR_SECTORHEADER_LUTLINK_INDEX 0u
#define FEE_30_FLEXNOR_SECTORHEADER_LUTLINKCHECKSUM_INDEX 4u

/* Indices inside the second write alignment */
#define FEE_30_FLEXNOR_SECTORHEADER_SOURCESECTOR_INDEX 0u

#define FEE_30_FLEXNOR_SECTORHEADER_GCREASONLAYOUTYPE_MASK 3u  /* Both informations are 2 bits, so we need a mask with lowest 2 bits set */

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

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/
#define FEE_30_FLEXNOR_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Context variable of the sector state machine. */
FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_Sector_ContextType Fee_30_FlexNor_SectorStmContext = { 0u };

/*! Stores chunk data and services for used memory layout. */
FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_ChunkType Fee_30_FlexNor_Chunk = {
    .Data = {
        .Validity = FEE_30_FLEXNOR_INVALID,
        .ErrorLocation = FEE_30_FLEXNOR_CHUNK_ERROR_STARTMARKER,
        .ReallocationRequired = FALSE,
        .PartitionId = 0u,
        .SectorId = 0u,
        .BlockId = 0u,
        .PayloadSize = 0u,
        .InstanceCount = 0u,
        .StartAddress = 0u,
        .ChunkLink = {
            .Target = 0u,
            .Validity = FEE_30_FLEXNOR_INVALID
        }
    },
    .Services = { 0u }
}; /* PRQA S 3218 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */

#define FEE_30_FLEXNOR_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define FEE_30_FLEXNOR_START_SEC_CODE
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_GetAlignedMetadataSize()
 *********************************************************************************************************************/
/*! \brief       Computes the aligned length of the meta data part of the sector header
 *  \details     -
 *  \param[in]   sector Sector whose meta data size shall be computed.
 *  \return      Aligned length of the meta data
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FEE_30_FLEXNOR_LOCAL_INLINE FUNC(Fee_30_FlexNor_LengthType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_GetAlignedMetadataSize(
    Fee_30_FlexNor_ConstSectorPtrType sector);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_GetAlignedPropertiesSize()
 *********************************************************************************************************************/
/*! \brief       Computes the aligned length of the properties of the sector header
 *  \details     -
 *  \param[in]   sector Sector whose properties size shall be computed.
 *  \return      Aligned length of the properties.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FEE_30_FLEXNOR_LOCAL_INLINE FUNC(Fee_30_FlexNor_LengthType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_GetAlignedPropertiesSize(
    Fee_30_FlexNor_ConstSectorPtrType sector);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_GetAlignedLutLinkSize()
 *********************************************************************************************************************/
/*! \brief       Computes the aligned length of the LUT link of the sector header
 *  \details     -
 *  \param[in]   sector Sector whose LUT link size shall be computed
 *  \return      Aligned length of the LUT link.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FEE_30_FLEXNOR_LOCAL_INLINE FUNC(Fee_30_FlexNor_LengthType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_GetAlignedLutLinkSize(
    Fee_30_FlexNor_ConstSectorPtrType sector);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_GetAlignedSourceSectorIdSize()
 *********************************************************************************************************************/
/*! \brief       Computes the aligned length of the source sector id of the sector header
 *  \details     -
 *  \param[in]   sector Sector whose source sector id size shall be computed.
 *  \return      Aligned length of the source sector id.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FEE_30_FLEXNOR_LOCAL_INLINE FUNC(Fee_30_FlexNor_LengthType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_GetAlignedSourceSectorIdSize(
    Fee_30_FlexNor_ConstSectorPtrType sector);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_GetAlignedAdditionalInfoSize()
 *********************************************************************************************************************/
/*! \brief       Computes the aligned length of the additional info part of the sector header.
 *  \details     -
 *  \param[in]   sector Sector whose additional info size shall be computed.
 *  \return      Aligned length of the additional info part of the sector header.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FEE_30_FLEXNOR_LOCAL_INLINE FUNC(Fee_30_FlexNor_LengthType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_GetAlignedAdditionalInfoSize(
    Fee_30_FlexNor_ConstSectorPtrType sector);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ValidateMetadataEraseMarker()
 *********************************************************************************************************************/
/*! \brief          Validates the sector header meta data erase marker part previously read from flash.
 *  \details        -
 *  \param[in,out]  ctx            Context that contains the read sector header meta data that shall be validated. Must not be NULL.
 *  \return         Result of the validation (see enum Fee_30_FlexNor_StructureValidityType).
 *  \pre            Sector header meta data must have been read from flash.
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_StructureValidityType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ValidateMetadataEraseMarker(Fee_30_FlexNor_Sector_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ValidateMetadataSealMarker()
 *********************************************************************************************************************/
/*! \brief          Validates the sector header meta data seal marker previously read from flash.
 *  \details        -
 *  \param[in]      ctx            Context that contains the read sector header meta data that shall be validated. Must not be NULL.
 *  \return         Result of the validation (see enum Fee_30_FlexNor_StructureValidityType).
 *  \pre            Sector header meta data must have been read from flash.
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_StructureValidityType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ValidateMetadataSealMarker(Fee_30_FlexNor_Sector_ConstContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ValidateMetadataCommitMarker()
 *********************************************************************************************************************/
/*! \brief          Validates the sector header meta data commit marker previously read from flash.
 *  \details        -
 *  \param[in]      ctx            Context that contains the read sector header meta data that shall be validated. Must not be NULL.
 *  \return         Result of the validation (see enum Fee_30_FlexNor_StructureValidityType).
 *  \pre            Sector header meta data must have been read from flash.
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_StructureValidityType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ValidateMetadataCommitMarker(Fee_30_FlexNor_Sector_ConstContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ValidateGcReason()
 *********************************************************************************************************************/
/*! \brief          Tries to parse the GcReason.
 *  \details        -
 *  \param[in,out]  ctx            Context that contains the read sector header meta data. Must not be NULL.
 *  \return         Result of the validation (see enum Fee_30_FlexNor_StructureValidityType).
 *  \pre            Sector header meta data must have been read from flash.
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_StructureValidityType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ValidateGcReason(Fee_30_FlexNor_Sector_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ValidateLayoutType()
 *********************************************************************************************************************/
/*! \brief          Tries to parse the LayoutType.
 *  \details        -
 *  \param[in,out]  ctx            Context that contains the read sector header meta data. Must not be NULL.
 *  \return         Result of the validation (see enum Fee_30_FlexNor_StructureValidityType).
 *  \pre            Sector header meta data must have been read from flash.
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_StructureValidityType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ValidateLayoutType(Fee_30_FlexNor_Sector_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ProcessingHandler()
 *********************************************************************************************************************/
/*! \brief       Handles the processing event
 *  \details     Triggers the Process event at the local state machine.
 *  \return      FEE_30_FLEXNOR_STOP_SCHEDULE       In case the scheduling shall be stopped
 *               FEE_30_FLEXNOR_CONTINUE_SCHEDULE   In case the scheduling can be continued
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FEE_30_FLEXNOR_LOCAL FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ProcessingHandler(void);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_EndReached()
 *********************************************************************************************************************/
/*! \brief       Checks if the end of the sector was reached with the next free address
 *  \details     The end was reached if no chunk would fit into the space between next free address and sector end anymore.
 *  \param[in]   ctx        Context that contains the chunk the end check shall be executed for. Must not be NULL.
 *  \return      TRUE       The end of the sector was reached with the next free address.
 *               FALSE      There could still fit a chunk between the next free address and the sector end.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(boolean, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_EndReached(Fee_30_FlexNor_Sector_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_CalculateMaximumInstanceCount()
 *********************************************************************************************************************/
/*! \brief       Calculates the instance count for the chunk that shall be allocated.
 *  \details     -
 *  \param[in]   predecessorChunk    Predecessor of the chunk that shall be allocated.
 *  \param[in]   targetSector        Sector in which the chunk shall be allocated. Must not be NULL.
 *  \param[in]   resetInstanceCount  Specifies if the instance count shall be reset to one.
 *  \return      The instance count of the chunk that shall be allocated.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_InstanceCountType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_CalculateMaximumInstanceCount(
    Fee_30_FlexNor_ConstChunkPtrType predecessorChunk, Fee_30_FlexNor_ConstSectorPtrType targetSector,
    boolean resetInstanceCount);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_GetSealMarkerStartIndex
 *********************************************************************************************************************/
/*! \brief       Returns the summarized and completely aligned size of properties and erase marker.
 *  \details     -
 *  \param[in]   sector        Sector that shall be used for computation.
 *  \return      The aligned size
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_LengthType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_GetSealMarkerStartIndex(Fee_30_FlexNor_ConstSectorPtrType sector);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_GetCommitMarkerStartIndex
 *********************************************************************************************************************/
/*! \brief       Returns the summarized and completely aligned size of properties, erase marker and seal marker.
 *  \details     -
 *  \param[in]   sector        Sector that shall be used for computation.
 *  \return      The aligned size
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_LengthType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_GetCommitMarkerStartIndex(Fee_30_FlexNor_ConstSectorPtrType sector);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_RequestRecoveryGarbageCollection
 *********************************************************************************************************************/
/*! \brief       Requests recovery garbage collection.
 *  \details     -
 *  \param[in]   ctx        The context that contains the required information for forwarding the request.
 *                          Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_RequestRecoveryGarbageCollection(Fee_30_FlexNor_Sector_ConstContextPtrType ctx);

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_GetAlignedMetadataSize()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FEE_30_FLEXNOR_LOCAL_INLINE FUNC(Fee_30_FlexNor_LengthType, FEE_30_FLEXNOR_CODE)
    Fee_30_FlexNor_Sector_GetAlignedMetadataSize(Fee_30_FlexNor_ConstSectorPtrType sector)
{
    Fee_30_FlexNor_ConstPartitionConfigPtrType partitionConfig
        = Fee_30_FlexNor_ConfigInterface_GetPartitionConfig(sector->PartitionId);
    Fee_30_FlexNor_LengthType commitMarkerStartIndex =
        Fee_30_FlexNor_Sector_GetCommitMarkerStartIndex(sector); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
    Fee_30_FlexNor_LengthType totalSize = Fee_30_FlexNor_Shared_AlignUp(
        commitMarkerStartIndex + partitionConfig->PageAlignment, partitionConfig->InterferenceFreeAlignment);
    return totalSize;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_GetAlignedPropertiesSize()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FEE_30_FLEXNOR_LOCAL_INLINE FUNC(Fee_30_FlexNor_LengthType, FEE_30_FLEXNOR_CODE)
    Fee_30_FlexNor_Sector_GetAlignedPropertiesSize(Fee_30_FlexNor_ConstSectorPtrType sector)
{
    Fee_30_FlexNor_ConstPartitionConfigPtrType partitionConfig
        = Fee_30_FlexNor_ConfigInterface_GetPartitionConfig(sector->PartitionId);

    return Fee_30_FlexNor_Shared_AlignUp(FEE_30_FLEXNOR_SECTORHEADER_PROPERTIES_SIZE, partitionConfig->PageAlignment);
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_GetAlignedLutLinkSize()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FEE_30_FLEXNOR_LOCAL_INLINE FUNC(Fee_30_FlexNor_LengthType, FEE_30_FLEXNOR_CODE)
    Fee_30_FlexNor_Sector_GetAlignedLutLinkSize(Fee_30_FlexNor_ConstSectorPtrType sector)
{
    Fee_30_FlexNor_ConstPartitionConfigPtrType partitionConfig =
							Fee_30_FlexNor_ConfigInterface_GetPartitionConfig(sector->PartitionId);

    return  Fee_30_FlexNor_Shared_AlignUp(
        FEE_30_FLEXNOR_SECTORHEADER_LUTLINKTARGET_SIZE + FEE_30_FLEXNOR_SECTORHEADER_LUTLINKCHECKSUM_SIZE,
        partitionConfig->PageAlignment);
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_GetAlignedLutLinkSize()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FEE_30_FLEXNOR_LOCAL_INLINE FUNC(Fee_30_FlexNor_LengthType, FEE_30_FLEXNOR_CODE)
    Fee_30_FlexNor_Sector_GetAlignedSourceSectorIdSize(Fee_30_FlexNor_ConstSectorPtrType sector)
{
    Fee_30_FlexNor_ConstPartitionConfigPtrType partitionConfig =
							Fee_30_FlexNor_ConfigInterface_GetPartitionConfig(sector->PartitionId);

    return Fee_30_FlexNor_Shared_AlignUp(
        FEE_30_FLEXNOR_SECTORHEADER_SOURCESECTOR_SIZE,
        partitionConfig->PageAlignment);
}


/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_GetAlignedAdditionalInfoSize()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FEE_30_FLEXNOR_LOCAL_INLINE FUNC(Fee_30_FlexNor_LengthType, FEE_30_FLEXNOR_CODE)
    Fee_30_FlexNor_Sector_GetAlignedAdditionalInfoSize(Fee_30_FlexNor_ConstSectorPtrType sector)
{
    Fee_30_FlexNor_ConstPartitionConfigPtrType partitionConfig =
							Fee_30_FlexNor_ConfigInterface_GetPartitionConfig(sector->PartitionId);

    Fee_30_FlexNor_LengthType additionalInfoSize = Fee_30_FlexNor_Sector_GetAlignedLutLinkSize(sector) /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
        + Fee_30_FlexNor_Sector_GetAlignedSourceSectorIdSize(sector); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    return Fee_30_FlexNor_Shared_AlignUp(additionalInfoSize, partitionConfig->InterferenceFreeAlignment);
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ValidateGcReason()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_StructureValidityType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ValidateGcReason(Fee_30_FlexNor_Sector_ContextPtrType ctx)    /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    Fee_30_FlexNor_StructureValidityType retVal = FEE_30_FLEXNOR_VALID;

    uint8 value = (uint8) (ctx->SectorBuffer[FEE_30_FLEXNOR_SECTORHEADER_MULTIFIELD_INDEX] >> (uint8) FEE_30_FLEXNOR_SECTORHEADER_TYPE_SIZE_IN_BITS) &
             (uint8) FEE_30_FLEXNOR_SECTORHEADER_GCREASONLAYOUTYPE_MASK;

    if(value == (uint8)FEE_30_FLEXNOR_GC_REASON_SPACE)
    {
        ctx->Sector->GcReason = FEE_30_FLEXNOR_GC_REASON_SPACE; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    }
    else if (value == (uint8)FEE_30_FLEXNOR_GC_REASON_RECOVERY)
    {
        ctx->Sector->GcReason = FEE_30_FLEXNOR_GC_REASON_RECOVERY; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    }
    else
    {
        retVal = FEE_30_FLEXNOR_INVALID;
    }

    return retVal;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ValidateLayoutType()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_StructureValidityType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ValidateLayoutType(Fee_30_FlexNor_Sector_ContextPtrType ctx)    /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    Fee_30_FlexNor_StructureValidityType retVal = FEE_30_FLEXNOR_VALID;

    uint8 value = ctx->SectorBuffer[FEE_30_FLEXNOR_SECTORHEADER_MULTIFIELD_INDEX] & (uint8) FEE_30_FLEXNOR_SECTORHEADER_GCREASONLAYOUTYPE_MASK;

    if(value == (uint8)FEE_30_FLEXNOR_SECURELAYOUT)
    {
        ctx->Sector->Layout = FEE_30_FLEXNOR_SECURELAYOUT; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    }
    else if (value == (uint8)FEE_30_FLEXNOR_SLIMLAYOUT)
    {
        ctx->Sector->Layout = FEE_30_FLEXNOR_SLIMLAYOUT; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    }
    else
    {
        retVal = FEE_30_FLEXNOR_INVALID;
    }

    return retVal;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ValidateMetadataEraseMarker()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_StructureValidityType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ValidateMetadataEraseMarker(Fee_30_FlexNor_Sector_ContextPtrType ctx)    /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    Fee_30_FlexNor_ConstPartitionConfigPtrType partitionConfig = Fee_30_FlexNor_ConfigInterface_GetPartitionConfig(ctx->Sector->PartitionId);

    Fee_30_FlexNor_AddressType alignedEraseMarkerStartIndex = Fee_30_FlexNor_Sector_GetAlignedPropertiesSize(ctx->Sector); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    return Fee_30_FlexNor_Shared_GetMarkerValidity(
        ctx->SectorBuffer,
        alignedEraseMarkerStartIndex,
        Fee_30_FlexNor_EraseMarker,
        partitionConfig->PageAlignment,
        partitionConfig->ErasedValue); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ValidateMetadataSealMarker()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_StructureValidityType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ValidateMetadataSealMarker(Fee_30_FlexNor_Sector_ConstContextPtrType ctx)
{
    Fee_30_FlexNor_ConstPartitionConfigPtrType partitionConfig = Fee_30_FlexNor_ConfigInterface_GetPartitionConfig(ctx->Sector->PartitionId);

    Fee_30_FlexNor_AddressType alignedSealMarkerStartIndex = Fee_30_FlexNor_Sector_GetAlignedPropertiesSize(ctx->Sector) /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
        + partitionConfig->PageAlignment;

    return Fee_30_FlexNor_Shared_GetMarkerValidity(
        ctx->SectorBuffer,
        alignedSealMarkerStartIndex,
        Fee_30_FlexNor_SealMarker,
        partitionConfig->PageAlignment,
        partitionConfig->ErasedValue); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ValidateMetadataCommitMarker()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_StructureValidityType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ValidateMetadataCommitMarker(Fee_30_FlexNor_Sector_ConstContextPtrType ctx)    /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    Fee_30_FlexNor_ConstPartitionConfigPtrType partitionConfig = Fee_30_FlexNor_ConfigInterface_GetPartitionConfig(ctx->Sector->PartitionId);

    Fee_30_FlexNor_AddressType alignedCommitMarkerStartIndex = Fee_30_FlexNor_Sector_GetCommitMarkerStartIndex(ctx->Sector); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    return Fee_30_FlexNor_Shared_GetMarkerValidity(
        ctx->SectorBuffer,
        alignedCommitMarkerStartIndex,
        Fee_30_FlexNor_CommitMarker,
        partitionConfig->PageAlignment,
        partitionConfig->ErasedValue); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ProcessingHandler()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FEE_30_FLEXNOR_LOCAL FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ProcessingHandler(void)
{
    return Fee_30_FlexNor_SectorStmContext.CurrentState->ProcessEvent(&Fee_30_FlexNor_SectorStmContext); /* SBSW_Fee_30_FlexNor_TriggerEventAtState */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ResultHandler()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ResultHandler(Fee_30_FlexNor_ServiceResult result)
{
    if(result == FEE_30_FLEXNOR_SERVICE_FAIL)
    {
        Fee_30_FlexNor_SectorStmContext.CurrentState->FailEvent(&Fee_30_FlexNor_SectorStmContext); /* SBSW_Fee_30_FlexNor_TriggerEventAtState */
    }
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_EndReached()
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
FUNC(boolean, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_EndReached(Fee_30_FlexNor_Sector_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    boolean endReached = TRUE;
    Fee_30_FlexNor_LengthType sectorLength = Fee_30_FlexNor_ConfigInterface_GetSectorLength(ctx->Sector->PartitionId, ctx->Sector->StartAddress);
    Fee_30_FlexNor_AddressType sectorEndAddress = ctx->Sector->StartAddress + sectorLength;
    uint32 chunkHeaderSize = ctx->Chunk->Services.GetHeaderSize(ctx->Chunk); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    if((ctx->TemporaryNextFreeAddress + chunkHeaderSize) < sectorEndAddress)
    {
        endReached = FALSE;
    }

    return endReached;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_CalculateMaximumInstanceCount()
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
FUNC(Fee_30_FlexNor_InstanceCountType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_CalculateMaximumInstanceCount(
    Fee_30_FlexNor_ConstChunkPtrType predecessorChunk, Fee_30_FlexNor_ConstSectorPtrType targetSector,
    boolean resetInstanceCount)
{
    Fee_30_FlexNor_InstanceCountType targetInstanceCount = 1u;

    if((predecessorChunk != NULL_PTR) && (resetInstanceCount == FALSE))
    {
        targetInstanceCount = predecessorChunk->Data.InstanceCount + 1u;

        if(targetSector->SectorId != predecessorChunk->Data.SectorId)
        {
            targetInstanceCount = targetInstanceCount / 2u;
        }
    }

    return targetInstanceCount;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_GetSealMarkerStartIndex
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_LengthType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_GetSealMarkerStartIndex(
    Fee_30_FlexNor_ConstSectorPtrType sector)
{
    Fee_30_FlexNor_ConstPartitionConfigPtrType partitionConfig =
        Fee_30_FlexNor_ConfigInterface_GetPartitionConfig(sector->PartitionId);
    Fee_30_FlexNor_LengthType alignedPropertiesSize = Fee_30_FlexNor_Sector_GetAlignedPropertiesSize(sector); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
    Fee_30_FlexNor_LengthType alignedEraseMarkerSize = partitionConfig->PageAlignment;

    Fee_30_FlexNor_LengthType totalSize = alignedPropertiesSize + alignedEraseMarkerSize;

    return totalSize;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_GetCommitMarkerStartIndex
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_LengthType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_GetCommitMarkerStartIndex(
    Fee_30_FlexNor_ConstSectorPtrType sector)
{
    Fee_30_FlexNor_ConstPartitionConfigPtrType partitionConfig =
        Fee_30_FlexNor_ConfigInterface_GetPartitionConfig(sector->PartitionId);
    Fee_30_FlexNor_LengthType alignedPropertiesSize = Fee_30_FlexNor_Sector_GetAlignedPropertiesSize(sector); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
    Fee_30_FlexNor_LengthType alignedEraseMarkerSize = partitionConfig->PageAlignment;
    Fee_30_FlexNor_LengthType alignedSealMarkerSize = partitionConfig->PageAlignment;
    Fee_30_FlexNor_LengthType totalSize =
        Fee_30_FlexNor_Shared_AlignUp(alignedPropertiesSize + alignedEraseMarkerSize + alignedSealMarkerSize,
            partitionConfig->InterferenceFreeAlignment);
    return totalSize;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_RequestRecoveryGarbageCollection
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_RequestRecoveryGarbageCollection(Fee_30_FlexNor_Sector_ConstContextPtrType ctx)
{
    Fee_30_FlexNor_InternalJobs_RequestRecoveryGarbageCollection(ctx->Sector->PartitionId, ctx->Sector->StartAddress);
}

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_Init()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_Init(void)
{
    Fee_30_FlexNor_SectorStmContext.SectorBuffer = Fee_30_FlexNor_ConfigInterface_GetInternalBuffer();
    Fee_30_FlexNor_SectorStmContext.Chunk = &Fee_30_FlexNor_Chunk;
    Fee_30_FlexNor_Sector_InitState(&Fee_30_FlexNor_SectorStmContext); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_IsUsed()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(boolean, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_IsUsed(Fee_30_FlexNor_ConstSectorPtrType sector)
{
    return (sector->Validity == FEE_30_FLEXNOR_VALID) ? TRUE : FALSE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_StartJob()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_StartJob(void)
{
    Fee_30_FlexNor_Scheduler_RegisterUnit(&Fee_30_FlexNor_Sector_ProcessingHandler); /* SBSW_Fee_30_FlexNor_RegisterUnit */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_EndJob()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_EndJob(void)
{
    Fee_30_FlexNor_Scheduler_UnregisterUnit();
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ReadHeader()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ReadHeader(Fee_30_FlexNor_SectorPtrType sector, Fee_30_FlexNor_ResultCallback resultCbk)
{
    Fee_30_FlexNor_SectorStmContext.Sector = sector;
    Fee_30_FlexNor_SectorStmContext.ResultCallback = resultCbk;
    Fee_30_FlexNor_Sector_ReadHeader_Initialize(&Fee_30_FlexNor_SectorStmContext); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ReadMetadata()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ReadMetadata(Fee_30_FlexNor_Sector_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    Fee_30_FlexNor_DiagnosticHandler_SetCurrentMilestone(FEE_30_FLEXNOR_DIAGMST_READ_SECTOR_METADATA);

    Fee_30_FlexNor_ConstPartitionConfigPtrType partitionConfig = Fee_30_FlexNor_ConfigInterface_GetPartitionConfig(ctx->Sector->PartitionId);
    Fee_30_FlexNor_LengthType alignedMetadataLength = Fee_30_FlexNor_Sector_GetAlignedMetadataSize(ctx->Sector); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    Fee_30_FlexNor_Shared_SetBufferValues(
        ctx->SectorBuffer,
        alignedMetadataLength,
        partitionConfig->ErasedValue); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    Fee_30_FlexNor_FlashAccess_ReadFlash(ctx->Sector->PartitionId,
        ctx->Sector->StartAddress,
        ctx->SectorBuffer,
        alignedMetadataLength,
        &Fee_30_FlexNor_Sector_ResultHandler); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ReadAdditionalInfo()
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
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ReadAdditionalInfo(Fee_30_FlexNor_Sector_ContextPtrType ctx)    /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    Fee_30_FlexNor_DiagnosticHandler_SetCurrentMilestone(FEE_30_FLEXNOR_DIAGMST_READ_SECTOR_ADDITIONALINFORMATION);

    Fee_30_FlexNor_ConstPartitionConfigPtrType partitionConfig = Fee_30_FlexNor_ConfigInterface_GetPartitionConfig(ctx->Sector->PartitionId);

    Fee_30_FlexNor_AddressType startAddress = ctx->Sector->StartAddress
        + Fee_30_FlexNor_Sector_GetAlignedMetadataSize(ctx->Sector); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
    Fee_30_FlexNor_LengthType alignedAdditionalInfoLength = Fee_30_FlexNor_Sector_GetAlignedAdditionalInfoSize(ctx->Sector); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    Fee_30_FlexNor_Shared_SetBufferValues(
        ctx->SectorBuffer,
        alignedAdditionalInfoLength,
        partitionConfig->ErasedValue); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    Fee_30_FlexNor_FlashAccess_ReadFlash(ctx->Sector->PartitionId,
        startAddress,
        ctx->SectorBuffer,
        alignedAdditionalInfoLength,
        &Fee_30_FlexNor_Sector_ResultHandler); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ReadEraseMarker()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ReadEraseMarker(Fee_30_FlexNor_Sector_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    Fee_30_FlexNor_DiagnosticHandler_SetCurrentMilestone(FEE_30_FLEXNOR_DIAGMST_READ_SECTOR_ERASEMARKER);

    Fee_30_FlexNor_ConstPartitionConfigPtrType partitionConfig = Fee_30_FlexNor_ConfigInterface_GetPartitionConfig(ctx->Sector->PartitionId);

    Fee_30_FlexNor_LengthType eraseMarkerStartAddress = ctx->Sector->StartAddress
        + Fee_30_FlexNor_Sector_GetAlignedPropertiesSize(ctx->Sector); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    Fee_30_FlexNor_Shared_SetBufferValues(
        ctx->SectorBuffer,
        partitionConfig->PageAlignment,
        partitionConfig->ErasedValue); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    Fee_30_FlexNor_FlashAccess_ReadFlash(ctx->Sector->PartitionId,
        eraseMarkerStartAddress,
        ctx->SectorBuffer,
        partitionConfig->PageAlignment,
        &Fee_30_FlexNor_Sector_ResultHandler); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ReadProperties()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ReadProperties(Fee_30_FlexNor_Sector_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    Fee_30_FlexNor_DiagnosticHandler_SetCurrentMilestone(FEE_30_FLEXNOR_DIAGMST_READ_SECTOR_PROPERTIES);

    Fee_30_FlexNor_ConstPartitionConfigPtrType partitionConfig = Fee_30_FlexNor_ConfigInterface_GetPartitionConfig(ctx->Sector->PartitionId);
    Fee_30_FlexNor_LengthType alignedPropertiesSize = Fee_30_FlexNor_Sector_GetAlignedPropertiesSize(ctx->Sector); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */;

    Fee_30_FlexNor_Shared_SetBufferValues(
        ctx->SectorBuffer,
        alignedPropertiesSize,
        partitionConfig->ErasedValue); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    Fee_30_FlexNor_FlashAccess_ReadFlash(ctx->Sector->PartitionId,
        ctx->Sector->StartAddress,
        ctx->SectorBuffer,
        alignedPropertiesSize,
        &Fee_30_FlexNor_Sector_ResultHandler); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ReadCommitMarker()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ReadCommitMarker(Fee_30_FlexNor_Sector_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    Fee_30_FlexNor_DiagnosticHandler_SetCurrentMilestone(FEE_30_FLEXNOR_DIAGMST_READ_SECTOR_COMMIT_MARKER);

    Fee_30_FlexNor_ConstPartitionConfigPtrType partitionConfig = Fee_30_FlexNor_ConfigInterface_GetPartitionConfig(ctx->Sector->PartitionId);

    Fee_30_FlexNor_LengthType alignedCommitMarkerLength = partitionConfig->PageAlignment;

    Fee_30_FlexNor_AddressType startAddress = ctx->Sector->StartAddress
        + Fee_30_FlexNor_Sector_GetCommitMarkerStartIndex(ctx->Sector); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    Fee_30_FlexNor_Shared_SetBufferValues(
        ctx->SectorBuffer,
        alignedCommitMarkerLength,
        partitionConfig->ErasedValue); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    Fee_30_FlexNor_FlashAccess_ReadFlash(ctx->Sector->PartitionId,
        startAddress,
        ctx->SectorBuffer,
        alignedCommitMarkerLength,
        &Fee_30_FlexNor_Sector_ResultHandler); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ReadSealMarker()
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
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ReadSealMarker(Fee_30_FlexNor_Sector_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    Fee_30_FlexNor_DiagnosticHandler_SetCurrentMilestone(FEE_30_FLEXNOR_DIAGMST_READ_SECTOR_SEAL_MARKER);

    Fee_30_FlexNor_ConstPartitionConfigPtrType partitionConfig = Fee_30_FlexNor_ConfigInterface_GetPartitionConfig(ctx->Sector->PartitionId);

    Fee_30_FlexNor_AddressType startAddress =  ctx->Sector->StartAddress
        + Fee_30_FlexNor_Sector_GetSealMarkerStartIndex(ctx->Sector); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    Fee_30_FlexNor_LengthType alignedSealMarkerLength = partitionConfig->PageAlignment;

    Fee_30_FlexNor_Shared_SetBufferValues(
        ctx->SectorBuffer,
        alignedSealMarkerLength,
        partitionConfig->ErasedValue); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    Fee_30_FlexNor_FlashAccess_ReadFlash(ctx->Sector->PartitionId,
        startAddress,
        ctx->SectorBuffer,
        alignedSealMarkerLength,
        &Fee_30_FlexNor_Sector_ResultHandler); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ReadLutLink()
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
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ReadLutLink(Fee_30_FlexNor_Sector_ContextPtrType ctx)    /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    Fee_30_FlexNor_DiagnosticHandler_SetCurrentMilestone(FEE_30_FLEXNOR_DIAGMST_READ_SECTOR_LOOKUPTABLESHORTCUT);

    Fee_30_FlexNor_ConstPartitionConfigPtrType partitionConfig = Fee_30_FlexNor_ConfigInterface_GetPartitionConfig(ctx->Sector->PartitionId);

    Fee_30_FlexNor_AddressType startAddress = ctx->Sector->StartAddress
        + Fee_30_FlexNor_Sector_GetAlignedMetadataSize(ctx->Sector); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
    Fee_30_FlexNor_LengthType alignedLutLinkSize = Fee_30_FlexNor_Sector_GetAlignedLutLinkSize(ctx->Sector); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    Fee_30_FlexNor_Shared_SetBufferValues(
        ctx->SectorBuffer,
        alignedLutLinkSize,
        partitionConfig->ErasedValue); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    Fee_30_FlexNor_FlashAccess_ReadFlash(ctx->Sector->PartitionId,
        startAddress,
        ctx->SectorBuffer,
        alignedLutLinkSize,
        &Fee_30_FlexNor_Sector_ResultHandler); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ReadSourceSector()
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
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ReadSourceSector(Fee_30_FlexNor_Sector_ContextPtrType ctx)    /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    Fee_30_FlexNor_DiagnosticHandler_SetCurrentMilestone(FEE_30_FLEXNOR_DIAGMST_READ_SECTOR_SOURCESECTORID);

    Fee_30_FlexNor_ConstPartitionConfigPtrType partitionConfig =
        Fee_30_FlexNor_ConfigInterface_GetPartitionConfig(ctx->Sector->PartitionId);

    Fee_30_FlexNor_AddressType startAddress = ctx->Sector->StartAddress
        + Fee_30_FlexNor_Sector_GetAlignedMetadataSize(ctx->Sector) /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
        + Fee_30_FlexNor_Sector_GetAlignedLutLinkSize(ctx->Sector); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    Fee_30_FlexNor_LengthType alignedSourceSectorSize = Fee_30_FlexNor_Sector_GetAlignedSourceSectorIdSize(ctx->Sector); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    Fee_30_FlexNor_Shared_SetBufferValues(
        ctx->SectorBuffer,
        alignedSourceSectorSize,
        partitionConfig->ErasedValue); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    Fee_30_FlexNor_FlashAccess_ReadFlash(ctx->Sector->PartitionId,
        startAddress,
        ctx->SectorBuffer,
        alignedSourceSectorSize,
        &Fee_30_FlexNor_Sector_ResultHandler); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ValidateMetadata()
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
FUNC(Fee_30_FlexNor_Sector_ErrorLocation, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ValidateMetadata( /* PRQA S 6080 */ /* MD_MSR_STMIF */
    Fee_30_FlexNor_Sector_ContextPtrType ctx)
{
    Fee_30_FlexNor_Sector_ErrorLocation metadataErrorLocation = FEE_30_FLEXNOR_SECTOR_ERROR_NOERROR;

    /* The properties validation function reads the erase cycle counter from the memory. As long as the properties are
       valid, the value is used for the allocation of the next sector, even if the erase marker is set. To make
       sure that this value is available, the properties are validated first. */
    Fee_30_FlexNor_StructureValidityType partialValidationResult
        = Fee_30_FlexNor_Sector_ValidateMetadataProperties(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */

    if(partialValidationResult == FEE_30_FLEXNOR_VALID)
    {
        partialValidationResult = Fee_30_FlexNor_Sector_ValidateMetadataEraseMarker(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */

        if(partialValidationResult == FEE_30_FLEXNOR_EMPTY)
        {
            partialValidationResult = Fee_30_FlexNor_Sector_ValidateMetadataCommitMarker(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */

            if(partialValidationResult == FEE_30_FLEXNOR_VALID)
            {
                metadataErrorLocation = FEE_30_FLEXNOR_SECTOR_ERROR_NOERROR;
                ctx->Sector->Validity = FEE_30_FLEXNOR_VALID; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
            }
            else /* FEE_30_FLEXNOR_EMPTY / FEE_30_FLEXNOR_INVALID */
            {
                partialValidationResult = Fee_30_FlexNor_Sector_ValidateMetadataSealMarker(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */

                if(partialValidationResult == FEE_30_FLEXNOR_VALID)
                {
                    metadataErrorLocation = FEE_30_FLEXNOR_SECTOR_ERROR_COMMITMARKERBROKEN; /* From previous check -> Commit marker is not valid */
                    ctx->Sector->Validity = FEE_30_FLEXNOR_VALID; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
                    Fee_30_FlexNor_Sector_RequestRecoveryGarbageCollection(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
                }
                else
                {
                   metadataErrorLocation = FEE_30_FLEXNOR_SECTOR_ERROR_SEALMARKERBROKEN;
                   ctx->Sector->Validity = FEE_30_FLEXNOR_INVALID; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
                }
            }
        }
        else
        {
            metadataErrorLocation = FEE_30_FLEXNOR_SECTOR_ERROR_ERASEMARKERSET;
            ctx->Sector->Validity = FEE_30_FLEXNOR_INVALID; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        }
    }
    else
    {
        metadataErrorLocation = FEE_30_FLEXNOR_SECTOR_ERROR_PROPERTIESINVALID;
        ctx->Sector->Validity = FEE_30_FLEXNOR_INVALID; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    }

    ctx->Sector->ErrorLocation = metadataErrorLocation; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */

    return metadataErrorLocation;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ParseAdditionalInfo()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ParseAdditionalInfo(Fee_30_FlexNor_Sector_ContextPtrType ctx)
{
    Fee_30_FlexNor_AddressType alignedSourceSectorStartIndex = Fee_30_FlexNor_Sector_GetAlignedLutLinkSize(ctx->Sector); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    Fee_30_FlexNor_Sector_ParseAdditionalInfoLutLink(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    Fee_30_FlexNor_Sector_ParseAdditionalInfoSourceSector(ctx, alignedSourceSectorStartIndex); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ParseAdditionalInfoLutLink()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ParseAdditionalInfoLutLink(
    Fee_30_FlexNor_Sector_ContextPtrType ctx)    /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    Fee_30_FlexNor_ConstPartitionConfigPtrType partitionConfig =
		Fee_30_FlexNor_ConfigInterface_GetPartitionConfig(ctx->Sector->PartitionId);

    boolean isLUTChunkLinkEmpty =
        Fee_30_FlexNor_Shared_IsErased(ctx->SectorBuffer, sizeof(Fee_30_FlexNor_ChunkLocationType), partitionConfig->ErasedValue); /* SBSW_Fee_30_FlexNor_FunctionPointerCallWithGivenPointer */

    ctx->Sector->LutChunkLink.Target = Fee_30_FlexNor_Shared_GetValueFromBuffer(
        ctx->SectorBuffer,
        FEE_30_FLEXNOR_SECTORHEADER_LUTLINKTARGET_SIZE,
        FEE_30_FLEXNOR_SECTORHEADER_LUTLINK_INDEX); /* SBSW_Fee_30_FlexNor_ContextPointerAccess */ /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    Fee_30_FlexNor_ChecksumType checksum = ctx->SectorBuffer[FEE_30_FLEXNOR_SECTORHEADER_LUTLINKCHECKSUM_INDEX];

    Fee_30_FlexNor_ChecksumType calculatedChecksum = Fee_30_FlexNor_Shared_CalculateChecksum(ctx->SectorBuffer,
        FEE_30_FLEXNOR_SECTORHEADER_LUTLINKTARGET_SIZE,
        FEE_30_FLEXNOR_SECTORHEADER_LUTLINK_INDEX); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    if(isLUTChunkLinkEmpty == TRUE)
    {
        ctx->Sector->LutChunkLink.Validity = FEE_30_FLEXNOR_EMPTY; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    }
    else if((ctx->Sector->LutChunkLink.Target != FEE_30_FLEXNOR_CHUNKLOCATION_INVALID) && (checksum == calculatedChecksum))
    {
        ctx->Sector->LutChunkLink.Validity = FEE_30_FLEXNOR_VALID; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    }
    else
    {
        ctx->Sector->LutChunkLink.Validity = FEE_30_FLEXNOR_INVALID; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    }
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ParseAdditionalInfoSourceSector()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ParseAdditionalInfoSourceSector(Fee_30_FlexNor_Sector_ContextPtrType ctx, Fee_30_FlexNor_AddressType alignedSourceSectorStartIndex)    /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    ctx->Sector->SourceSectorId = ctx->SectorBuffer[alignedSourceSectorStartIndex]; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
}



/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ValidateEraseMarker()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_Sector_ErrorLocation, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ValidateEraseMarker(Fee_30_FlexNor_Sector_ConstContextPtrType ctx)
{
    Fee_30_FlexNor_Sector_ErrorLocation metadataErrorLocation = FEE_30_FLEXNOR_SECTOR_ERROR_NOERROR;

    Fee_30_FlexNor_ConstPartitionConfigPtrType partitionConfig = Fee_30_FlexNor_ConfigInterface_GetPartitionConfig(ctx->Sector->PartitionId);

    Fee_30_FlexNor_AddressType alignedEraseMarkerStartIndex = 0u;

    Fee_30_FlexNor_StructureValidityType eraseMarkerValidity = Fee_30_FlexNor_Shared_GetMarkerValidity(
        ctx->SectorBuffer,
        alignedEraseMarkerStartIndex,
        Fee_30_FlexNor_EraseMarker,
        partitionConfig->PageAlignment,
        partitionConfig->ErasedValue); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    if(eraseMarkerValidity == FEE_30_FLEXNOR_EMPTY)
    {
        metadataErrorLocation = FEE_30_FLEXNOR_SECTOR_ERROR_NOERROR;
        ctx->Sector->Validity = FEE_30_FLEXNOR_VALID; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    }
    else
    {
        metadataErrorLocation = FEE_30_FLEXNOR_SECTOR_ERROR_ERASEMARKERSET;
        ctx->Sector->Validity = FEE_30_FLEXNOR_INVALID; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    }

    ctx->Sector->ErrorLocation = metadataErrorLocation; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */

    return metadataErrorLocation;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ValidateMetadataProperties()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_StructureValidityType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ValidateMetadataProperties(Fee_30_FlexNor_Sector_ContextPtrType ctx)    /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    Fee_30_FlexNor_StructureValidityType retVal = FEE_30_FLEXNOR_INVALID;

    ctx->Sector->SectorId = ctx->SectorBuffer[FEE_30_FLEXNOR_SECTORHEADER_SECTORID_INDEX]; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */

    ctx->Sector->EraseCycle = Fee_30_FlexNor_Shared_GetValueFromBuffer(ctx->SectorBuffer,
                FEE_30_FLEXNOR_SECTORHEADER_ERASECYCLECOUNTER_SIZE,
                FEE_30_FLEXNOR_SECTORHEADER_ERASECYCLECOUNTER_INDEX); /* SBSW_Fee_30_FlexNor_ContextPointerAccess */ /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    Fee_30_FlexNor_ChecksumType checksum = ctx->SectorBuffer[FEE_30_FLEXNOR_SECTORHEADER_PROPERTIESCHECKSUM_INDEX];
    Fee_30_FlexNor_ChecksumType checksumExpected = Fee_30_FlexNor_Shared_CalculateChecksum(ctx->SectorBuffer, /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
                FEE_30_FLEXNOR_SECTORHEADER_SECTORID_SIZE + FEE_30_FLEXNOR_SECTORHEADER_ERASECYCLECOUNTER_SIZE + FEE_30_FLEXNOR_SECTORHEADER_MULTIFIELD_SIZE,
                FEE_30_FLEXNOR_SECTORHEADER_SECTORID_INDEX);

    Fee_30_FlexNor_StructureValidityType gcReasonValidationResult = Fee_30_FlexNor_Sector_ValidateGcReason(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
    Fee_30_FlexNor_StructureValidityType layoutTypeValidationResult = Fee_30_FlexNor_Sector_ValidateLayoutType(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    /*
     * In case the properties are erased and the erased value is 0, the checksum would be equal to checksumExpected.
     * Nevertheless, it would be returned as expected FEE_30_FLEXNOR_INVALID
     * as gcReasonValidationResult and layoutTypeValidationResult would be FEE_30_FLEXNOR_INVALID.
     */
    if((gcReasonValidationResult == FEE_30_FLEXNOR_VALID)
       && (layoutTypeValidationResult == FEE_30_FLEXNOR_VALID)
       && (checksum == checksumExpected))
    {
        retVal = FEE_30_FLEXNOR_VALID;
    }

    return retVal;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ValidateCommitMarker()
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
 *
 *
 */
FUNC(Fee_30_FlexNor_Sector_ErrorLocation, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ValidateCommitMarker(Fee_30_FlexNor_Sector_ConstContextPtrType ctx)
{
    Fee_30_FlexNor_Sector_ErrorLocation metadataErrorLocation = FEE_30_FLEXNOR_SECTOR_ERROR_NOERROR;
    Fee_30_FlexNor_ConstPartitionConfigPtrType partitionConfig = Fee_30_FlexNor_ConfigInterface_GetPartitionConfig(ctx->Sector->PartitionId);
    Fee_30_FlexNor_StructureValidityType commitMarkerValidity = Fee_30_FlexNor_Shared_GetMarkerValidity(
        ctx->SectorBuffer,
        0u,
        Fee_30_FlexNor_CommitMarker,
        partitionConfig->PageAlignment,
        partitionConfig->ErasedValue); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    if(commitMarkerValidity == FEE_30_FLEXNOR_VALID)
    {
        metadataErrorLocation = FEE_30_FLEXNOR_SECTOR_ERROR_NOERROR;
        ctx->Sector->Validity = FEE_30_FLEXNOR_VALID; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    }
    else if(commitMarkerValidity == FEE_30_FLEXNOR_EMPTY)
    {
        metadataErrorLocation = FEE_30_FLEXNOR_SECTOR_ERROR_COMMITMARKEREMPTY;
        ctx->Sector->Validity = FEE_30_FLEXNOR_VALID; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    }
    else /* Commit Marker is invalid */
    {
        /* At this point of time it is ensured that the seal marker is valid, so always trigger garbage collection */
        metadataErrorLocation = FEE_30_FLEXNOR_SECTOR_ERROR_COMMITMARKERBROKEN; /* From previous check -> Commit marker is not valid */
        ctx->Sector->Validity = FEE_30_FLEXNOR_VALID; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        Fee_30_FlexNor_Sector_RequestRecoveryGarbageCollection(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }

    ctx->Sector->ErrorLocation = metadataErrorLocation; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */

    return metadataErrorLocation;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ValidateSealMarker()
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
 */
FUNC(Fee_30_FlexNor_Sector_ErrorLocation, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ValidateSealMarker(Fee_30_FlexNor_Sector_ConstContextPtrType ctx)
{
    Fee_30_FlexNor_Sector_ErrorLocation metadataErrorLocation = FEE_30_FLEXNOR_SECTOR_ERROR_NOERROR;
    Fee_30_FlexNor_ConstPartitionConfigPtrType partitionConfig = Fee_30_FlexNor_ConfigInterface_GetPartitionConfig(ctx->Sector->PartitionId);
    Fee_30_FlexNor_StructureValidityType sealMarkerValidity = Fee_30_FlexNor_Shared_GetMarkerValidity(
        ctx->SectorBuffer,
        0u,
        Fee_30_FlexNor_SealMarker,
        partitionConfig->PageAlignment,
        partitionConfig->ErasedValue); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    /* SealMarker is only read if CommitMarker is invalid or empty.
       - In case the seal marker is valid, the sector is still considered as valid, but selected for recovery GC to
         avoid a loss of data.
       - In case the seal marker is invalid or empty it cannot be guaranteed that the sector header was written successfully .
         So the sector is considered as invalid. */
    if(sealMarkerValidity == FEE_30_FLEXNOR_VALID)
    {
        metadataErrorLocation = FEE_30_FLEXNOR_SECTOR_ERROR_NOERROR;
        ctx->Sector->Validity = FEE_30_FLEXNOR_VALID; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        Fee_30_FlexNor_Sector_RequestRecoveryGarbageCollection(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }
    else /* Seal Marker is invalid or empty */
    {
        metadataErrorLocation = FEE_30_FLEXNOR_SECTOR_ERROR_SEALMARKERBROKEN; /* From previous check -> Commit marker is not valid */
        ctx->Sector->Validity = FEE_30_FLEXNOR_INVALID; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    }

    return metadataErrorLocation;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_WriteEraseMarker()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_WriteEraseMarker(Fee_30_FlexNor_SectorPtrType sector,
    Fee_30_FlexNor_ResultCallback resultCbk)
{
    Fee_30_FlexNor_SectorStmContext.Sector = sector;
    Fee_30_FlexNor_SectorStmContext.ResultCallback = resultCbk;
    Fee_30_FlexNor_Sector_WriteEraseMarker_Initialize(&Fee_30_FlexNor_SectorStmContext); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_WriteEraseMarkerToMemory()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE)Fee_30_FlexNor_Sector_WriteEraseMarkerToMemory(Fee_30_FlexNor_Sector_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    Fee_30_FlexNor_ConstPartitionConfigPtrType partitionConfig = Fee_30_FlexNor_ConfigInterface_GetPartitionConfig(ctx->Sector->PartitionId);

    Fee_30_FlexNor_AddressType eraseMarkerAddress = ctx->Sector->StartAddress + Fee_30_FlexNor_Sector_GetAlignedPropertiesSize(ctx->Sector); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    Fee_30_FlexNor_Shared_SetBufferValues(ctx->SectorBuffer, partitionConfig->PageAlignment, Fee_30_FlexNor_EraseMarker); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    Fee_30_FlexNor_FlashAccess_WriteFlash(ctx->Sector->PartitionId,
        eraseMarkerAddress,
        ctx->SectorBuffer,
        partitionConfig->PageAlignment,
        &Fee_30_FlexNor_Sector_ResultHandler); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_WriteLutLink()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_WriteLutLink(Fee_30_FlexNor_SectorPtrType sector, Fee_30_FlexNor_ResultCallback resultCbk)
{
    Fee_30_FlexNor_SectorStmContext.Sector = sector;
    Fee_30_FlexNor_SectorStmContext.ResultCallback = resultCbk;
    Fee_30_FlexNor_Sector_WriteLutLink_Initialize(&Fee_30_FlexNor_SectorStmContext); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_WriteLutLinkToMemory()
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
FUNC(void, FEE_30_FLEXNOR_CODE)Fee_30_FlexNor_Sector_WriteLutLinkToMemory(Fee_30_FlexNor_Sector_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    Fee_30_FlexNor_ConstPartitionConfigPtrType partitionConfig = Fee_30_FlexNor_ConfigInterface_GetPartitionConfig(ctx->Sector->PartitionId);

    Fee_30_FlexNor_LengthType alignedLutLinkSize = Fee_30_FlexNor_Sector_GetAlignedLutLinkSize(ctx->Sector); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
    Fee_30_FlexNor_Shared_SetBufferValues(ctx->SectorBuffer, alignedLutLinkSize, partitionConfig->ErasedValue); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    Fee_30_FlexNor_AddressType lutLinkAddress = ctx->Sector->StartAddress + Fee_30_FlexNor_Sector_GetAlignedMetadataSize(ctx->Sector); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
    Fee_30_FlexNor_Shared_SetValueToBuffer(ctx->Sector->LutChunkLink.Target, ctx->SectorBuffer, FEE_30_FLEXNOR_SECTORHEADER_LUTLINKTARGET_SIZE, 0u); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    ctx->SectorBuffer[FEE_30_FLEXNOR_SECTORHEADER_LUTLINKCHECKSUM_INDEX] = Fee_30_FlexNor_Shared_CalculateChecksum(ctx->SectorBuffer, /* SBSW_Fee_30_FlexNor_ModifyContextArray */ /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
        FEE_30_FLEXNOR_SECTORHEADER_LUTLINKTARGET_SIZE,
        FEE_30_FLEXNOR_SECTORHEADER_LUTLINK_INDEX);

    Fee_30_FlexNor_FlashAccess_WriteFlash(ctx->Sector->PartitionId,
        lutLinkAddress,
        ctx->SectorBuffer,
        alignedLutLinkSize,
        &Fee_30_FlexNor_Sector_ResultHandler); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_WriteSourceSector()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_WriteSourceSector(Fee_30_FlexNor_SectorPtrType sector, Fee_30_FlexNor_SectorIdType sourceSectorId,
                                                                        Fee_30_FlexNor_ResultCallback resultCbk)
{
    Fee_30_FlexNor_SectorStmContext.Sector = sector;
    Fee_30_FlexNor_SectorStmContext.SourceSectorId = sourceSectorId;
    Fee_30_FlexNor_SectorStmContext.ResultCallback = resultCbk;
    Fee_30_FlexNor_Sector_WriteSourceSector_Initialize(&Fee_30_FlexNor_SectorStmContext); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_WriteSourceSectorToMemory()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE)Fee_30_FlexNor_Sector_WriteSourceSectorToMemory(Fee_30_FlexNor_Sector_ContextPtrType ctx)    /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    Fee_30_FlexNor_ConstPartitionConfigPtrType partitionConfig = Fee_30_FlexNor_ConfigInterface_GetPartitionConfig(ctx->Sector->PartitionId);

    Fee_30_FlexNor_LengthType alignedLutLinkSize = Fee_30_FlexNor_Sector_GetAlignedLutLinkSize(ctx->Sector); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
    Fee_30_FlexNor_LengthType alignedAdditionalInformationSize = Fee_30_FlexNor_Shared_AlignUp(alignedLutLinkSize
        + FEE_30_FLEXNOR_SECTORHEADER_SOURCESECTOR_SIZE, partitionConfig->InterferenceFreeAlignment);
    Fee_30_FlexNor_LengthType alignedSourceSectorSize = alignedAdditionalInformationSize - alignedLutLinkSize;

    Fee_30_FlexNor_Shared_SetBufferValues(ctx->SectorBuffer, alignedSourceSectorSize, partitionConfig->ErasedValue); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    Fee_30_FlexNor_AddressType sourceSectorAddress = ctx->Sector->StartAddress
        + Fee_30_FlexNor_Sector_GetAlignedMetadataSize(ctx->Sector)  /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
        + alignedLutLinkSize;

    ctx->SectorBuffer[FEE_30_FLEXNOR_SECTORHEADER_SOURCESECTOR_INDEX] = ctx->SourceSectorId;    /* SBSW_Fee_30_FlexNor_ModifyContextArray */

    Fee_30_FlexNor_FlashAccess_WriteFlash(ctx->Sector->PartitionId,
        sourceSectorAddress,
        ctx->SectorBuffer,
        alignedSourceSectorSize,
        &Fee_30_FlexNor_Sector_ResultHandler); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_Allocate()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_Allocate(Fee_30_FlexNor_SectorPtrType sector,
    Fee_30_FlexNor_ResultCallback resultCbk)
{
    Fee_30_FlexNor_SectorStmContext.Sector = sector;
    Fee_30_FlexNor_SectorStmContext.SourceInstance = NULL_PTR;
    Fee_30_FlexNor_SectorStmContext.ResultCallback = resultCbk;
    Fee_30_FlexNor_Sector_Allocate_Initialize(&Fee_30_FlexNor_SectorStmContext); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_EraseSector()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE)Fee_30_FlexNor_Sector_EraseSector(Fee_30_FlexNor_Sector_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    Fee_30_FlexNor_LengthType sectorLength = Fee_30_FlexNor_ConfigInterface_GetSectorLength(ctx->Sector->PartitionId, ctx->Sector->StartAddress);
    Fee_30_FlexNor_FlashAccess_EraseFlash(ctx->Sector->PartitionId, ctx->Sector->StartAddress, sectorLength, &Fee_30_FlexNor_Sector_ResultHandler); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_WritePropertiesToMemory()
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
FUNC(void, FEE_30_FLEXNOR_CODE)Fee_30_FlexNor_Sector_WritePropertiesToMemory(Fee_30_FlexNor_Sector_ContextPtrType ctx)    /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    Fee_30_FlexNor_ConstPartitionConfigPtrType partitionConfig = Fee_30_FlexNor_ConfigInterface_GetPartitionConfig(ctx->Sector->PartitionId);

    Fee_30_FlexNor_LengthType alignedProperties = Fee_30_FlexNor_Sector_GetAlignedPropertiesSize(ctx->Sector); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
    Fee_30_FlexNor_Shared_SetBufferValues(ctx->SectorBuffer, alignedProperties, partitionConfig->ErasedValue); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    ctx->SectorBuffer[FEE_30_FLEXNOR_SECTORHEADER_SECTORID_INDEX] = ctx->Sector->SectorId; /* SBSW_Fee_30_FlexNor_ModifyContextArray */

    Fee_30_FlexNor_Shared_SetValueToBuffer(ctx->Sector->EraseCycle, ctx->SectorBuffer, FEE_30_FLEXNOR_SECTORHEADER_ERASECYCLECOUNTER_SIZE,
        FEE_30_FLEXNOR_SECTORHEADER_ERASECYCLECOUNTER_INDEX); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    ctx->SectorBuffer[FEE_30_FLEXNOR_SECTORHEADER_MULTIFIELD_INDEX] = (uint8) ((uint8)ctx->Sector->GcReason << FEE_30_FLEXNOR_SECTORHEADER_TYPE_SIZE_IN_BITS) | /* SBSW_Fee_30_FlexNor_ModifyContextArray */
        (uint8)ctx->Sector->Layout;

    ctx->SectorBuffer[FEE_30_FLEXNOR_SECTORHEADER_PROPERTIESCHECKSUM_INDEX] = Fee_30_FlexNor_Shared_CalculateChecksum(ctx->SectorBuffer,  /* SBSW_Fee_30_FlexNor_ModifyContextArray */ /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
        FEE_30_FLEXNOR_SECTORHEADER_PROPERTIES_SIZE - FEE_30_FLEXNOR_SECTORHEADER_PROPERTIESCHECKSUM_SIZE, FEE_30_FLEXNOR_SECTORHEADER_SECTORID_INDEX);

    Fee_30_FlexNor_FlashAccess_WriteFlash(ctx->Sector->PartitionId,
        ctx->Sector->StartAddress,
        ctx->SectorBuffer,
        alignedProperties,
        &Fee_30_FlexNor_Sector_ResultHandler); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_WriteSealMarkerToMemory()
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
FUNC(void, FEE_30_FLEXNOR_CODE)Fee_30_FlexNor_Sector_WriteSealMarkerToMemory(Fee_30_FlexNor_Sector_ContextPtrType ctx)    /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    Fee_30_FlexNor_ConstPartitionConfigPtrType partitionConfig = Fee_30_FlexNor_ConfigInterface_GetPartitionConfig(ctx->Sector->PartitionId);

    Fee_30_FlexNor_AddressType sealMarkerAddress = ctx->Sector->StartAddress
        + Fee_30_FlexNor_Sector_GetSealMarkerStartIndex(ctx->Sector); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    Fee_30_FlexNor_AddressType commitMarkerAddress = ctx->Sector->StartAddress
        + Fee_30_FlexNor_Sector_GetCommitMarkerStartIndex(ctx->Sector); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    Fee_30_FlexNor_LengthType paddedLength = commitMarkerAddress - sealMarkerAddress;

    Fee_30_FlexNor_Shared_SetBufferValues(ctx->SectorBuffer,
        paddedLength,
        partitionConfig->ErasedValue); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    Fee_30_FlexNor_Shared_SetBufferValues(ctx->SectorBuffer,
        partitionConfig->PageAlignment,
        Fee_30_FlexNor_SealMarker); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    Fee_30_FlexNor_FlashAccess_WriteFlash(ctx->Sector->PartitionId,
        sealMarkerAddress,
        ctx->SectorBuffer,
        paddedLength,
        &Fee_30_FlexNor_Sector_ResultHandler); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_WriteCommitMarkerToMemory()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE)Fee_30_FlexNor_Sector_WriteCommitMarkerToMemory(Fee_30_FlexNor_Sector_ContextPtrType ctx)    /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    Fee_30_FlexNor_ConstPartitionConfigPtrType partitionConfig = Fee_30_FlexNor_ConfigInterface_GetPartitionConfig(ctx->Sector->PartitionId);
    Fee_30_FlexNor_AddressType commitMarkerAddress = ctx->Sector->StartAddress + Fee_30_FlexNor_Sector_GetCommitMarkerStartIndex(ctx->Sector); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    Fee_30_FlexNor_Shared_SetBufferValues(ctx->SectorBuffer,
        partitionConfig->InterferenceFreeAlignment,
        partitionConfig->ErasedValue); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    Fee_30_FlexNor_Shared_SetBufferValues(ctx->SectorBuffer,
        partitionConfig->PageAlignment,
        Fee_30_FlexNor_CommitMarker); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    Fee_30_FlexNor_FlashAccess_WriteFlash(ctx->Sector->PartitionId,
        commitMarkerAddress,
        ctx->SectorBuffer,
        partitionConfig->InterferenceFreeAlignment,
        &Fee_30_FlexNor_Sector_ResultHandler); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_FullScan()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_FullScan(Fee_30_FlexNor_SectorPtrType sector, Fee_30_FlexNor_ResultCallback resultCbk)
{
    Fee_30_FlexNor_Sector_PartialScan(sector, FEE_30_FLEXNOR_CHUNKSEARCH_INVALID_CHUNKLOCATION, resultCbk);  /* SBSW_Fee_30_FlexNor_FunctionCallForwardsResultCallback */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_PartialScan()
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
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_PartialScan(Fee_30_FlexNor_SectorPtrType sector, Fee_30_FlexNor_AddressType startAddress, Fee_30_FlexNor_ResultCallback resultCbk)
{
    Fee_30_FlexNor_SectorStmContext.Sector = sector;
    Fee_30_FlexNor_SectorStmContext.ResultCallback = resultCbk;
    Fee_30_FlexNor_SectorStmContext.Chunk = &Fee_30_FlexNor_Chunk;
    Fee_30_FlexNor_SectorStmContext.Sector->NextFreeAddress = 0u; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */

    if(startAddress == FEE_30_FLEXNOR_CHUNKSEARCH_INVALID_CHUNKLOCATION)
    {
        Fee_30_FlexNor_SectorStmContext.TemporaryNextFreeAddress = Fee_30_FlexNor_SectorStmContext.Sector->StartAddress
            + Fee_30_FlexNor_Sector_GetAlignedMetadataSize(Fee_30_FlexNor_SectorStmContext.Sector) /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
            + Fee_30_FlexNor_Sector_GetAlignedAdditionalInfoSize(Fee_30_FlexNor_SectorStmContext.Sector); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
    }
    else
    {
        Fee_30_FlexNor_SectorStmContext.TemporaryNextFreeAddress = startAddress;
    }

    Fee_30_FlexNor_Sector_Scan_Initialize(&Fee_30_FlexNor_SectorStmContext); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ReadChunkHeader()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE)Fee_30_FlexNor_Sector_ReadChunkHeader(Fee_30_FlexNor_Sector_ContextPtrType ctx)  /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    Fee_30_FlexNor_ChunkFactory_CreateChunk(ctx->TemporaryNextFreeAddress, ctx->Sector->PartitionId, ctx->Sector->SectorId, ctx->Chunk); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
    ctx->Chunk->Services.ReadHeader(ctx->Chunk, &Fee_30_FlexNor_Sector_ResultHandler); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ProcessReadChunkHeader()
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
 */
FUNC(Fee_30_FlexNor_Sector_ScanCurrentResult, FEE_30_FLEXNOR_CODE)Fee_30_FlexNor_Sector_ProcessReadChunkHeader(Fee_30_FlexNor_Sector_ContextPtrType ctx)  /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    Fee_30_FlexNor_Sector_ScanCurrentResult retVal = FEE_30_FLEXNOR_SECTOR_SCAN_FINISHED;

    if(ctx->Chunk->Data.Validity != FEE_30_FLEXNOR_EMPTY)
    {
        if(ctx->Chunk->Data.Validity == FEE_30_FLEXNOR_VALID)
        {
            Fee_30_FlexNor_ConstPartitionConfigPtrType partitionConfig = Fee_30_FlexNor_ConfigInterface_GetPartitionConfig(ctx->Sector->PartitionId);

            Fee_30_FlexNor_LookupTable_LinkType chunkLink;
			chunkLink.SectorId = ctx->Sector->SectorId;
			chunkLink.ChunkOffset = (ctx->Chunk->Data.StartAddress - ctx->Sector->StartAddress) / partitionConfig->PageAlignment;

            Fee_30_FlexNor_LookupTable_SetLinkIfNewer(ctx->Sector->PartitionId, ctx->Chunk->Data.BlockId, chunkLink, ctx->Chunk->Data.ReallocationRequired);
        }

        Fee_30_FlexNor_LookupTable_IncrementNewChunkCounter(ctx->Sector->PartitionId);

        /* Handles the calculation of the correct step size */
        ctx->TemporaryNextFreeAddress += ctx->Chunk->Services.GetTotalSize(ctx->Chunk); /* SBSW_Fee_30_FlexNor_ContextPointerAccess */ /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

        if(Fee_30_FlexNor_Sector_EndReached(ctx) == FALSE) /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
        {
            retVal = FEE_30_FLEXNOR_SECTOR_SCAN_CONTINUE;
        }
    }

    if(retVal == FEE_30_FLEXNOR_SECTOR_SCAN_FINISHED)
    {
        ctx->Sector->NextFreeAddress = ctx->TemporaryNextFreeAddress; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    }

    return retVal;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_TryAllocateChunk()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_TryAllocateChunk( /* PRQA S 6060 */ /* MD_MSR_STPAR */
    Fee_30_FlexNor_SectorPtrType sector,
    Fee_30_FlexNor_ChunkPtrType chunk,
    Fee_30_FlexNor_ConstInstancePtrType sourceInstance,
    Fee_30_FlexNor_InstancePtrType targetInstance,
    Fee_30_FlexNor_ChunkPtrType predecessorChunk,
    boolean resetInstanceCount,
    Fee_30_FlexNor_ResultCallback resultCbk)
{
    Fee_30_FlexNor_SectorStmContext.Sector = sector;
    Fee_30_FlexNor_SectorStmContext.Chunk = chunk;
    Fee_30_FlexNor_SectorStmContext.SourceInstance = sourceInstance;
    Fee_30_FlexNor_SectorStmContext.TargetInstance = targetInstance;
    Fee_30_FlexNor_SectorStmContext.PredecessorChunk = predecessorChunk;
    Fee_30_FlexNor_SectorStmContext.resetInstanceCount = resetInstanceCount;
    Fee_30_FlexNor_SectorStmContext.ResultCallback = resultCbk;

    Fee_30_FlexNor_Sector_TryAllocateChunk_Initialize(&Fee_30_FlexNor_SectorStmContext); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_SetInstanceCountInChunkToAllocate()
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
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_SetInstanceCountInChunkToAllocate(
    Fee_30_FlexNor_ChunkPtrType chunkToAllocate, Fee_30_FlexNor_ConstChunkPtrType predecessorChunk,
    Fee_30_FlexNor_ConstSectorPtrType targetSector, boolean resetInstanceCount)
{
    Fee_30_FlexNor_ChunkFactory_CreateChunk(0u, targetSector->PartitionId, targetSector->SectorId, chunkToAllocate); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    chunkToAllocate->Data.InstanceCount
        = Fee_30_FlexNor_Sector_CalculateMaximumInstanceCount(predecessorChunk, targetSector, resetInstanceCount); /* SBSW_Fee_30_FlexNor_ContextPointerAccess */ /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */

    while (chunkToAllocate->Data.InstanceCount > 0u)
    {
        Fee_30_FlexNor_LengthType totalChunkSize = chunkToAllocate->Services.GetTotalSize(chunkToAllocate); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
        Fee_30_FlexNor_LengthType sectorLength
            = Fee_30_FlexNor_ConfigInterface_GetSectorLength(targetSector->PartitionId, targetSector->StartAddress);

        if((targetSector->StartAddress + sectorLength) > (targetSector->NextFreeAddress + totalChunkSize))
        {
            break;
        }

        chunkToAllocate->Data.InstanceCount--; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    }
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_TriggerChunkAllocation()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_TriggerChunkAllocation(Fee_30_FlexNor_Sector_ConstContextPtrType ctx)
{
    Fee_30_FlexNor_AddressType targetChunkAddress = ctx->Sector->NextFreeAddress;
    Fee_30_FlexNor_ChunkFactory_CreateChunk(targetChunkAddress, ctx->Sector->PartitionId, ctx->Sector->SectorId, ctx->Chunk); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    Fee_30_FlexNor_Sector_UpdateNextFreeAddress(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */

    ctx->Chunk->Services.Allocate(ctx->Chunk, ctx->PredecessorChunk, ctx->SourceInstance, ctx->TargetInstance, &Fee_30_FlexNor_Sector_ResultHandler); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_UpdateLookupTableAndNewChunkCounter()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_UpdateLookupTableAndNewChunkCounter(
    Fee_30_FlexNor_Sector_ConstContextPtrType ctx)
{
    Fee_30_FlexNor_ConstPartitionConfigPtrType partitionConfig =
							Fee_30_FlexNor_ConfigInterface_GetPartitionConfig(ctx->Sector->PartitionId);

    Fee_30_FlexNor_LookupTable_LinkType updatedLink;

    updatedLink.SectorId = ctx->Sector->SectorId;
    updatedLink.ChunkOffset
        = (ctx->Chunk->Data.StartAddress - ctx->Sector->StartAddress) / partitionConfig->PageAlignment;

    Fee_30_FlexNor_LookupTable_SetLinkIfNewer(ctx->Chunk->Data.PartitionId, ctx->Chunk->Data.BlockId, updatedLink, FALSE);
    Fee_30_FlexNor_LookupTable_IncrementNewChunkCounter(ctx->Chunk->Data.PartitionId);
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_UpdateNextFreeAddress()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_UpdateNextFreeAddress(Fee_30_FlexNor_Sector_ConstContextPtrType ctx)
{
    Fee_30_FlexNor_LengthType totalChunkSize = ctx->Chunk->Services.GetTotalSize(ctx->Chunk); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
    ctx->Sector->NextFreeAddress = ctx->Sector->NextFreeAddress + totalChunkSize; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_GetFirstFreeAddress()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Fee_30_FlexNor_AddressType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_GetFirstFreeAddress(Fee_30_FlexNor_Sector_ConstContextPtrType ctx)
{
    return ctx->Sector->StartAddress + Fee_30_FlexNor_Sector_GetAlignedMetadataSize(ctx->Sector) +    /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
           Fee_30_FlexNor_Sector_GetAlignedAdditionalInfoSize(ctx->Sector);    /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ResetRecoveryGarbageCollection()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ResetRecoveryGarbageCollection(Fee_30_FlexNor_SectorPtrType sector)
{
    sector->SelectedForRecoveryGarbageCollection = FALSE; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
}


#define FEE_30_FLEXNOR_STOP_SEC_CODE
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: Fee_30_FlexNor_Sector.c
 *********************************************************************************************************************/
