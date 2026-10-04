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
/*!        \file  Fee_30_FlexNor_GarbageCollection.h
 *        \brief  Garbage collection interface
 *      \details  Provides the interface for accessing and handling the garbage collection.
 *         \unit  GarbageCollection
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 **********************************************************************************************************************/

#if !defined (FEE_30_FLEXNOR_GARBAGECOLLECTION_H)
# define FEE_30_FLEXNOR_GARBAGECOLLECTION_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Fee_30_FlexNor_Types.h"
#include "Fee_30_FlexNor_ConfigInterface.h"
#include "Fee_30_FlexNor_Sector.h"
#include "Fee_30_FlexNor_Chunk.h"

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
 * Fee_30_FlexNor_GarbageCollection_Init()
 *********************************************************************************************************************/
/*! \brief       Initialize the garbage collection unit
 *  \details     -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_GarbageCollection_Init(void);

/**********************************************************************************************************************
 * Fee_30_FlexNor_GarbageCollection_IsPending()
 *********************************************************************************************************************/
/*! \brief       Checks if an unfinished garbage collection is pending for the given partition
 *  \details     A garbage collection is pending in case it was interrupted in the previous cycle. Before a new block 
 *               is written, the garbage collection needs to be completed by design. Therefore this check needs to be
 *               executed at the beginning of each write job.
 *  \param[in]   partitionId    Id of the partition whose garbage collection status shall be checked
 *  \return      TRUE           An unfinished garbage collection is pending
 *               FALSE          No garbage collection is pending for the partition
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(boolean, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_GarbageCollection_IsPending(
    Fee_30_FlexNor_PartitionIdType partitionId);

/**********************************************************************************************************************
 * Fee_30_FlexNor_GarbageCollection_Run()
 *********************************************************************************************************************/
/*! \brief       Executes a garbage collection for the given partition
 *  \details     -
 *  \param[in]   partitionId             Id of the partition the garbage collection shall be executed for.
 *  \param[in]   sourceSector            Pointer to an explicit source sector. If this parameter is NULL_PTR, the 
 *                                       garbage collection selects a source sector automatically based on the build in 
 *                                       selection metric. If this parameter is NOT a NULL_PTR the garbage collection 
 *                                       will only be executed for valid sectors.
 *  \param[in]   isPersistLutJobRunning  Indicates if the GC is executed in context of a perist LUT job. In this case 
 *                                       no LUT recovery is allowed. 
 *  \param[in]   resultCbk               The result callback that is called in case the service is complete. Must not 
 *                                       be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous FALSE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_GarbageCollection_Run(
    Fee_30_FlexNor_PartitionIdType partitionId, 
    Fee_30_FlexNor_SectorPtrType sourceSector, 
    boolean isPersistLutJobRunning,
    Fee_30_FlexNor_ResultCallback resultCbk);

# define FEE_30_FLEXNOR_STOP_SEC_CODE
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* FEE_30_FLEXNOR_GARBAGECOLLECTION_H */

/**********************************************************************************************************************
 *  END OF FILE: Fee_30_FlexNor_GarbageCollection.h
 *********************************************************************************************************************/
