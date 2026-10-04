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
/*!        \file  Fee_30_FlexNor_SecureChunk.h
 *        \brief  Secure chunk interface
 *      \details  Provides the secure layout specific chunk services.
 *         \unit  SecureChunk
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 **********************************************************************************************************************/

#if !defined(FEE_30_FLEXNOR_SECURECHUNK_H)
#define FEE_30_FLEXNOR_SECURECHUNK_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Fee_30_FlexNor_Chunk.h"
#include "Fee_30_FlexNor_ConfigInterface.h"

# if (FEE_30_FLEXNOR_SECURELAYOUT_ENABLED == STD_ON) /* COV_MSR_UT_OPTIONAL_UNIT */

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
#define FEE_30_FLEXNOR_START_SEC_CODE
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureChunk_Init()
 *********************************************************************************************************************/
/*! \brief       Initialize the chunk unit
 *  \details     -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureChunk_Init(void);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureChunk_ReadHeader()
 *********************************************************************************************************************/
/*! \brief          Read the chunk header and validate it.
 *  \details        Read the chunk header and validate it. The chunk header consists of metadata and the chunk link.
 *  \param[in,out]  chunk                  Pointer to the chunk whose header shall be read and validated. Must not be NULL.
 *  \param[in]      resultCbk              The result call back that is called in case the service is complete. Must not be NULL.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    FALSE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureChunk_ReadHeader(
    Fee_30_FlexNor_ChunkPtrType chunk,
    Fee_30_FlexNor_ResultCallback resultCbk);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureChunk_GetHeaderSize()
 *********************************************************************************************************************/
/*! \brief          Get the size of the header. Includes metadata and chunk link.
 *  \details        -
 *  \param[in]      chunk                  Pointer to the chunk whose header size shall be calculated. Must not be NULL.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(uint32, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureChunk_GetHeaderSize(Fee_30_FlexNor_ConstChunkPtrType chunk);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureChunk_GetTotalSize()
 *********************************************************************************************************************/
/*! \brief       Get the total size of the chunk
 *  \details     Calculates the total aligned size of the chunk in flash. This includes the management data as well as 
                 the space reserved for the instances that are managed by the chunk.
 *  \param[in]   chunk               Pointer to the chunk the size shall be calculated for. Must not be NULL.
 *  \return      The total size of the chunk in bytes
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(uint32, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureChunk_GetTotalSize(Fee_30_FlexNor_ConstChunkPtrType chunk);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureChunk_Allocate()
 *********************************************************************************************************************/
/*! \brief       Allocates a new chunk in flash.
 *  \details     Uses the given chunk, predecessor chunk and Chunk to allocate a chunk in flash.
 *  \param[in]   chunk              Chunk data that shall be used for the allocation. Must not be NULL.
 *  \param[in]   predecessorChunk   Predecessor chunk that link will be updated. Must not be NULL.
 *  \param[in]   sourceInstance     Pointer to the instance that is being copied to the chunk that is being allocated.
 *                                  In case this parameter is NULL, no instance is copied but the targetInstance is directly written to the chunk.
 *  \param[in]   targetInstance     Pointer to the first instance to be written to the chunk. Must not be NULL.
 *  \param[in]   resultCbk          The result call back that is called in case the service is complete. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous FALSE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureChunk_Allocate(
    Fee_30_FlexNor_ConstChunkPtrType chunk,
    Fee_30_FlexNor_ChunkPtrType predecessorChunk,
    Fee_30_FlexNor_ConstInstancePtrType sourceInstance,
    Fee_30_FlexNor_InstancePtrType targetInstance,
    Fee_30_FlexNor_ResultCallback resultCbk);

#define FEE_30_FLEXNOR_STOP_SEC_CODE
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif

#endif /* FEE_30_FLEXNOR_SECURECHUNK_H */

/**********************************************************************************************************************
 *  END OF FILE: Fee_30_FlexNor_SecureChunk.h
 *********************************************************************************************************************/
