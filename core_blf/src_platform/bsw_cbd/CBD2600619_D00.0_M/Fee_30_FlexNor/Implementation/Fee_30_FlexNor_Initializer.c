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
/*!        \file  Fee_30_FlexNor_Initializer.c
 *        \brief  Initializer implementation
 *      \details  Provides the implementation for the component initializer.
 *         \unit  Initializer
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#define FEE_30_FLEXNOR_INITIALIZER_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Fee_30_FlexNor_Initializer.h"

#include "Fee_30_FlexNor_Scheduler.h"

#include "Fee_30_FlexNor_ChunkSearch.h"
#include "Fee_30_FlexNor_CopyBlock.h"
#include "Fee_30_FlexNor_GarbageCollection.h"
#include "Fee_30_FlexNor_InternalJobs.h"
#include "Fee_30_FlexNor_LookupTable.h"
#include "Fee_30_FlexNor_Partition.h"
#include "Fee_30_FlexNor_SectorContainer.h"
#include "Fee_30_FlexNor_Startup.h"

#include "Fee_30_FlexNor_FlashAccess.h"

#include "Fee_30_FlexNor_Chunk.h"
#include "Fee_30_FlexNor_SecureChunk.h"
#include "Fee_30_FlexNor_SlimChunk.h"
#include "Fee_30_FlexNor_SecureInstance.h"
#include "Fee_30_FlexNor_SlimInstance.h"
#include "Fee_30_FlexNor_Sector.h"
#include "Fee_30_FlexNor_DiagnosticHandler.h"

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
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define FEE_30_FLEXNOR_START_SEC_CODE
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
/**********************************************************************************************************************
 * Fee_30_FlexNor_Initializer_InitStructuralLayer()
 *********************************************************************************************************************/
/*! \brief       Initialized the units in the structural layer
 *  \details     -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Initializer_InitStructuralLayer(void);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Initializer_InitCoreLayer()
 *********************************************************************************************************************/
/*! \brief       Initializes the core layer
 *  \details     -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Initializer_InitCoreLayer(void);

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * Fee_30_FlexNor_Initializer_InitStructuralLayer()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Initializer_InitStructuralLayer(void)
{
    Fee_30_FlexNor_Chunk_Init();
    Fee_30_FlexNor_Sector_Init();

#if (FEE_30_FLEXNOR_SECURELAYOUT_ENABLED == STD_ON) /* COV_MSR_UT_OPTIONAL_UNIT */
    Fee_30_FlexNor_SecureInstance_Init();
    Fee_30_FlexNor_SecureChunk_Init();
#endif

#if (FEE_30_FLEXNOR_SLIMLAYOUT_ENABLED == STD_ON) /* COV_MSR_UT_OPTIONAL_UNIT */
    Fee_30_FlexNor_SlimInstance_Init();
    Fee_30_FlexNor_SlimChunk_Init();
#endif
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Initializer_InitCoreLayer()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Initializer_InitCoreLayer(void) /* PRQA S 6050 */ /* MD_MSR_STCAL */
{
    Fee_30_FlexNor_SectorContainer_Init();
    Fee_30_FlexNor_Startup_Init();
    Fee_30_FlexNor_LookupTable_Init();
    Fee_30_FlexNor_ChunkSearch_Init();
    Fee_30_FlexNor_Partition_Init();
    Fee_30_FlexNor_GarbageCollection_Init();
    Fee_30_FlexNor_CopyBlock_Init();
    Fee_30_FlexNor_InternalJobs_Init();
}

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * Fee_30_FlexNor_Initializer_Init()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Initializer_Init(void)
{
    Fee_30_FlexNor_Scheduler_Init();
    Fee_30_FlexNor_FlashAccess_Init();
    Fee_30_FlexNor_DiagnosticHandler_Init();

    Fee_30_FlexNor_Initializer_InitStructuralLayer();
    Fee_30_FlexNor_Initializer_InitCoreLayer();
}

#define FEE_30_FLEXNOR_STOP_SEC_CODE
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: Fee_30_FlexNor_Initializer.c
 *********************************************************************************************************************/
