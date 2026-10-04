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
/*!        \file  Fee_30_FlexNor_InstanceInternal.h
 *        \brief  Internal instance business logic prototypes
 *      \details  Provides the internal prototypes for the business logic of the instance implementation.
 *         \unit  SecureInstance
 *         \unit  SlimInstance
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 **********************************************************************************************************************/

#if !defined (FEE_30_FLEXNOR_INSTANCEINTERNAL_H)
# define FEE_30_FLEXNOR_INSTANCEINTERNAL_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Fee_30_FlexNor_Instance.h"
#include "Fee_30_FlexNor_Types.h"
#include "Fee_30_FlexNor_ConfigInterface.h"
#include "Fee_30_FlexNor_FlashAccess.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define FEE_30_FLEXNOR_INSTANCE_STATUS_SIZE (0x4u)

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef struct P2VAR(Fee_30_FlexNor_Instance_Context, AUTOMATIC, FEE_30_FLEXNOR_VAR) Fee_30_FlexNor_Instance_ContextPtrType;
typedef P2CONST(struct Fee_30_FlexNor_Instance_Context, AUTOMATIC, FEE_30_FLEXNOR_VAR) Fee_30_FlexNor_Instance_ConstContextPtrType;
typedef P2FUNC(void, AUTOMATIC, Fee_30_FlexNor_Instance_FailEvt)(Fee_30_FlexNor_Instance_ContextPtrType ctx);

/* Module context */
typedef struct Fee_30_FlexNor_Instance_Context
{
    Fee_30_FlexNor_ConstInstanceDataPtrType SourceInstance;     /*!< Pointer to the source instance that shall be copied. */

    Fee_30_FlexNor_DataPtrType InstanceBuffer;                  /*!< Internal buffer to store the instance data that shall be written to/read from flash. */
    Fee_30_FlexNor_LengthType ContentWritten;                   /*!< Represents the amount of content (i.e. status + payload) that was already written to flash. */ 
    Fee_30_FlexNor_ConstPartitionConfigPtrType PartitionConfig; /*!< Pointer to the partition configuration of the processed instance. */
    Fee_30_FlexNor_LengthType ContentRead;                      /*!< Represents the amount of content (i.e. status + payload) that was already read from flash. */ 
        
    Fee_30_FlexNor_ResultCallback ResultCallback;               /*!< Result callback that is used to communicate the service result back to the caller. */   
} Fee_30_FlexNor_Instance_ContextType;                          /*!< Represents the context for the internal state machine of the unit */

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
# define FEE_30_FLEXNOR_START_SEC_CODE
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Fee_30_FlexNor_Instance_WritePayload
 *********************************************************************************************************************/
/*! \brief       Writes the next part of the payload.
 *  \details     Payload is written in 1-3 steps, according to the payload size. The progress will be stored within the context.
 *  \param[in,out]   ctx            Context for the instance payload write.
 *  \param[in]       instance       Instance that shall be written
 *  \param[in]       metadataSize   Size of the metadata, depending on the target layout
 *  \param[in]       resultCbk      Pointer to the result handler for the flash write jobs.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Instance_WritePayload(Fee_30_FlexNor_Instance_ContextPtrType ctx,
    Fee_30_FlexNor_ConstInstanceDataPtrType instance,
    Fee_30_FlexNor_LengthType metadataSize,
    Fee_30_FlexNor_ResultCallback resultCbk);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Instance_IsAnotherWriteStepNecessary
 *********************************************************************************************************************/
/*! \brief       Checks if another write step must be triggered.
 *  \details     -
 *  \param[in]   ctx            Context for the instance payload write.
 *  \param[in]       instance       Instance that shall be written
 *  \return          True: another write step necessary, 
 *                   False: no further write step necessary
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(boolean, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Instance_IsAnotherWriteStepNecessary(Fee_30_FlexNor_Instance_ConstContextPtrType ctx,
    Fee_30_FlexNor_ConstInstanceDataPtrType instance);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Instance_ReadSourceContent()
 *********************************************************************************************************************/
/*! \brief       Reads a part of the source instances content depending on the amount of content that was already copied
 *  \details     -
 *  \param[in]   ctx            Context for the instance copy operation.
 *  \param[in]       metadataSize   Size of the metadata, depending on the target layout.
 *  \param[in]       resultCbk      Pointer to the result handler for the flash read jobs.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Instance_ReadSourceContent(Fee_30_FlexNor_Instance_ConstContextPtrType ctx,
    Fee_30_FlexNor_LengthType metadataSize,
    Fee_30_FlexNor_ResultCallback resultCbk);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Instance_WriteTargetContent()
 *********************************************************************************************************************/
/*! \brief       Writes the previously read source instance content to the target instance
 *  \details     -
 *  \param[in,out]   ctx            Context for the instance copy operation.
 *  \param[in]       targetInstance Pointer to the target instance data whose content shall be written.
 *  \param[in]       metadataSize   Size of the metadata, depending on the target layout.
 *  \param[in]       resultCbk      Pointer to the result handler for the flash write jobs.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Instance_WriteTargetContent(Fee_30_FlexNor_Instance_ContextPtrType ctx,
    Fee_30_FlexNor_ConstInstanceDataPtrType targetInstance,
    Fee_30_FlexNor_LengthType metadataSize,
    Fee_30_FlexNor_ResultCallback resultCbk);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Instance_GetAlignedContentSize()
 *********************************************************************************************************************/
/*! \brief       Calculates the page aligned content size of the source instance in the given context
 *  \details     -
 *  \param[in]   ctx               Pointer to the context containing the source instance.
 *  \return      The page aligned content size in bytes.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_LengthType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Instance_GetAlignedContentSize(Fee_30_FlexNor_Instance_ConstContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Instance_ReadCommitMarker()
 *********************************************************************************************************************/
/*! \brief       Reads the commit marker into the buffer
 *  \details     -
 *  \param[in]   ctx                        Context of the validation.
 *  \param[in]   commitMarkerStartAddress   Start address of the commit marker.
 *  \param[in]   resultCbk                  Callback thas is called after reading the commit marker from flash.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Instance_ReadCommitMarker(
    Fee_30_FlexNor_Instance_ConstContextPtrType ctx,
    Fee_30_FlexNor_AddressType commitMarkerStartAddress,
    Fee_30_FlexNor_ResultCallback resultCbk);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Instance_RequestRecoveryGarbageCollection()
 *********************************************************************************************************************/
/*! \brief       Requests recovery garbage collection.
 *  \details     -
 *  \param[in]   partitionId    Id of the partition that contains the sector that shall be recovered
 *  \param[in]   address        Address within the sector that shall be recovered
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Instance_RequestRecoveryGarbageCollection(
    Fee_30_FlexNor_PartitionIdType partitionId,
    Fee_30_FlexNor_AddressType address);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Instance_ReadStatus()
 *********************************************************************************************************************/
/*! \brief       Reads the instance status from flash into the internal buffer. Depending on the read alignment, 
 *               additionally some payload bytes are read. 
 *  \details     -
 *  \param[in]    instance        Instance whose status shall be read. Must not be NULL.
 *  \param[in]    ctx             Context of the read content service. Must not be NULL.
 *  \param[in]    metadataSize    Aligned metadata size of the given instance.
 *  \param[in]    resultCbk       Callback that is called after reading the status from flash. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Instance_ReadStatus(    
    Fee_30_FlexNor_ConstInstanceDataPtrType instance,
    Fee_30_FlexNor_Instance_ConstContextPtrType ctx, 
    Fee_30_FlexNor_LengthType metadataSize,
    Fee_30_FlexNor_ResultCallback resultCbk
);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Instance_ParseInstanceStatus()
 *********************************************************************************************************************/
/*! \brief       Parses the instance status from the read instance content.
 *  \details     -
 *  \param[in]   instanceBuffer   Buffer with the read content from the status read request. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_InstanceStatusType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Instance_ParseInstanceStatus(
    Fee_30_FlexNor_DataPtrType instanceBuffer);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Instance_CopyDataFromStatusPageInUserBuffer()
 *********************************************************************************************************************/
/*! \brief       If some payload bytes were read with the instance status, copy them from the internal buffer into the 
 *               user buffer. 
 *  \details     -
 *  \param[in]    instance        Instance whose status shall be read. Must not be NULL.
 *  \param[in]    ctx             Context of the read read content service. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Instance_CopyDataFromStatusPageInUserBuffer(
    Fee_30_FlexNor_ConstInstanceDataPtrType instance,
    Fee_30_FlexNor_Instance_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Instance_ReadOffsetPage()
 *********************************************************************************************************************/
/*! \brief       If the offset points into a different read page than the status page and it is not read page aligned,
 *               read the offset page into the internal buffer.
 *  \details     -
 *  \param[in]    instance        Instance whose payload shall be read. Must not be NULL.
 *  \param[in]    ctx             Context of the read content service. Must not be NULL.
 *  \param[in]    metaDataSize    Aligned metadata size of the given instance.
 *  \param[in]    resultCbk       Callback that is called after reading the offset page from flash. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(boolean, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Instance_ReadOffsetPage(
    Fee_30_FlexNor_ConstInstanceDataPtrType instance,
    Fee_30_FlexNor_Instance_ConstContextPtrType ctx, 
    Fee_30_FlexNor_LengthType metaDataSize,
    Fee_30_FlexNor_ResultCallback resultCbk);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Instance_CopyDataFromOffsetPageInUserBuffer()
 *********************************************************************************************************************/
/*! \brief       If the offset points into a different read page than the status page and it is not read page aligned,
 *               copy the payload bytes from the internal buffer into the user buffer. 
 *  \details     -
 *  \param[in]    instance        Instance whose payload shall be read. Must not be NULL.
 *  \param[in]    ctx             Context of the read content service. Must not be NULL.
 *  \param[in]    metaDataSize    Aligned metadata size of the given instance.
 *  \param[in]    resultCbk       Callback that is called after reading the offset page from flash. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Instance_CopyDataFromOffsetPageInUserBuffer(
    Fee_30_FlexNor_ConstInstanceDataPtrType instance,
    Fee_30_FlexNor_Instance_ContextPtrType ctx, 
    Fee_30_FlexNor_LengthType metaDataSize);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Instance_ReadCompletelyFilledPages()
 *********************************************************************************************************************/
/*! \brief       Read the payload of all completely filled pages into the user buffer.
 *  \details     -
 *  \param[in]    instance        Instance whose payload shall be read. Must not be NULL.
 *  \param[in]    ctx             Context of the read content service. Must not be NULL.
 *  \param[in]    metaDataSize    Aligned metadata size of the given instance.
 *  \param[in]    resultCbk       Callback that is called after reading the offset page from flash. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(boolean, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Instance_ReadCompletelyFilledPages(
    Fee_30_FlexNor_ConstInstanceDataPtrType instance,
    Fee_30_FlexNor_Instance_ContextPtrType ctx, 
    Fee_30_FlexNor_LengthType metaDataSize,
    Fee_30_FlexNor_ResultCallback resultCbk);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Instance_ReadLastPage()
 *********************************************************************************************************************/
/*! \brief       If there is payload left to read, read the last page into the internal buffer. 
 *  \details     -
 *  \param[in]    instance        Instance whose payload shall be read. Must not be NULL.
 *  \param[in]    ctx             Context of the read content service. Must not be NULL.
 *  \param[in]    metaDataSize    Aligned metadata size of the given instance.
 *  \param[in]    resultCbk       Callback that is called after reading the offset page from flash. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(boolean, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Instance_ReadLastPage(
    Fee_30_FlexNor_ConstInstanceDataPtrType instance,
    Fee_30_FlexNor_Instance_ConstContextPtrType ctx, 
    Fee_30_FlexNor_LengthType metaDataSize,
    Fee_30_FlexNor_ResultCallback resultCbk);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Instance_CopyDataFromLastPageInUserBuffer()
 *********************************************************************************************************************/
/*! \brief       If the last page was read separately, copy the payload into the user buffer. 
 *  \details     -
 *  \param[in]    instance        Instance whose payload shall be read. Must not be NULL.
 *  \param[in]    ctx             Context of the read content service. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/

FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Instance_CopyDataFromLastPageInUserBuffer(
    Fee_30_FlexNor_ConstInstanceDataPtrType instance,
    Fee_30_FlexNor_Instance_ContextPtrType ctx);

#    define FEE_30_FLEXNOR_STOP_SEC_CODE
#    include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* FEE_30_FLEXNOR_INSTANCEINTERNAL_H */

/**********************************************************************************************************************
 *  END OF FILE: Fee_30_FlexNor_InstanceInternal.h
 *********************************************************************************************************************/
