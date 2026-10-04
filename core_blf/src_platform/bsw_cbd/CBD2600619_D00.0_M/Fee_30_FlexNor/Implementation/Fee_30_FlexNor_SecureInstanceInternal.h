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
/*!        \file  Fee_30_FlexNor_SecureInstanceInternal.h
 *        \brief  Internal secure instance business logic prototypes
 *      \details  Provides the internal prototypes for the business logic of the secure instance implementation.
 *         \unit  SecureInstance
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 **********************************************************************************************************************/

#if !defined(FEE_30_FLEXNOR_SECUREINSTANCEINTERNAL_H)
#    define FEE_30_FLEXNOR_SECUREINSTANCEINTERNAL_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#    include "Fee_30_FlexNor_Instance.h"
#    include "Fee_30_FlexNor_InstanceInternal.h"
#    include "Fee_30_FlexNor_ConfigInterface.h"

#    if (FEE_30_FLEXNOR_SECURELAYOUT_ENABLED == STD_ON) /* COV_MSR_UT_OPTIONAL_UNIT */

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef struct Fee_30_FlexNor_SecureInstance
{
    Fee_30_FlexNor_InstanceDataPtrType InstanceData;           /*!< Pointer to the generic instance data. */
    Fee_30_FlexNor_ConstInstanceDataPtrType ConstInstanceData; /*!< Pointer to the const generic instance data. */
    Fee_30_FlexNor_StructureValidityType StartMarkerValidity;  /*!< Stores the start marker validity of the instance. */
    Fee_30_FlexNor_StructureValidityType SealMarkerValidity;   /*!< Stores the seal marker validity of the instance. */
    Fee_30_FlexNor_StructureValidityType CommitMarkerValidity; /*!< Stores the commit marker validity of the instance. */
} Fee_30_FlexNor_SecureInstanceType;                           /*!< Holds all information about the data used by the concrete type. */

typedef struct P2VAR(Fee_30_FlexNor_SecureInstance_Context, AUTOMATIC, FEE_30_FLEXNOR_VAR) Fee_30_FlexNor_SecureInstance_ContextPtrType;

/* Module state */
typedef P2FUNC(Fee_30_FlexNor_ScheduleBehaviorType, AUTOMATIC, Fee_30_FlexNor_SecureInstance_ProcessEvt)(
    Fee_30_FlexNor_SecureInstance_ContextPtrType ctx);
typedef P2FUNC(void, AUTOMATIC, Fee_30_FlexNor_SecureInstance_FailEvt)(Fee_30_FlexNor_SecureInstance_ContextPtrType ctx);

typedef struct Fee_30_FlexNor_SecureInstance_State
{
    Fee_30_FlexNor_SecureInstance_ProcessEvt ProcessEvent; /*!< Pointer to the handler for the process event of the state */
    Fee_30_FlexNor_SecureInstance_FailEvt FailEvent;       /*!< Pointer to the handler for the fail event of the state */
} Fee_30_FlexNor_SecureInstance_StateType;                 /*!< Represents a state of the internal unit state machine */

typedef CONST(Fee_30_FlexNor_SecureInstance_StateType, AUTOMATIC) Fee_30_FlexNor_SecureInstance_ConstStateType;
typedef P2CONST(Fee_30_FlexNor_SecureInstance_StateType, AUTOMATIC, FEE_30_FLEXNOR_VAR) Fee_30_FlexNor_SecureInstance_ConstStatePtrType;

/* Module context */
typedef struct Fee_30_FlexNor_SecureInstance_Context
{
    Fee_30_FlexNor_SecureInstance_ConstStatePtrType CurrentState; /*!< Current state of the state machine */

    Fee_30_FlexNor_SecureInstanceType Instance;         /*!< Secure instance data the unit operates on. */
    Fee_30_FlexNor_Instance_ContextType GenericContext; /*!< Parts of the context that is the same for both layouts. */
} Fee_30_FlexNor_SecureInstance_ContextType;            /*!< Represents the context for the internal state machine of the unit */

typedef P2CONST(Fee_30_FlexNor_SecureInstance_ContextType, AUTOMATIC, FEE_30_FLEXNOR_VAR) Fee_30_FlexNor_SecureInstance_ConstContextPtrType;
/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#        define FEE_30_FLEXNOR_START_SEC_CODE
#        include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_StartJob()
 *********************************************************************************************************************/
/*! \brief       Start a job for the unit
 *  \details     Registers the unit at the scheduler to start the asynchronous processing for the unit.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_StartJob(void);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_EndJob()
 *********************************************************************************************************************/
/*! \brief       Ends a job for the unit
 *  \details     Unregisters the unit from the scheduler.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_EndJob(void);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_ResultHandler()
 *********************************************************************************************************************/
/*! \brief       Handles the result of a called service
 *  \details     This function is used as a result callback for services called by this unit.
 *  \param[in]   result               Result of the called service
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_ResultHandler(
    Fee_30_FlexNor_ServiceResult result);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_GetAlignedMetadataSize()
 *********************************************************************************************************************/
/*! \brief       Gets the aligned size of the instance metadata
 *  \details     -
 *  \param[in]   partition    Partition which contains the instance.
 *  \return      The aligned size of the instance metadata
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(uint32, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_GetAlignedMetadataSize(
    Fee_30_FlexNor_ConstPartitionConfigPtrType partition);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_ReadInstanceMetadata()
 *********************************************************************************************************************/
/*! \brief       Reads the instance metadata from flash.
 *  \details     -
 *  \param[in]   ctx    Context the instance metadata shall be read in. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_ReadInstanceMetadata(Fee_30_FlexNor_SecureInstance_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_ValidateInstanceMetadata()
 *********************************************************************************************************************/
/*! \brief       Validates the instance metadata
 *  \details     Validates the instance metadata previously read from flash.
 *  \param[in]   ctx    Context that contains the read metadata that shall be validated. Must not be NULL.
 *  \pre         Instance metdata must be read from flash.
 *  \return      Result of the validation
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_StructureValidityType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_ValidateInstanceMetadata(Fee_30_FlexNor_SecureInstance_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_WriteStartMarker()
 *********************************************************************************************************************/
/*! \brief       Writes the start marker of the instance to flash
 *  \details     -
 *  \param[in]   ctx    Context that contains the instance the start marker shall be written for. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_WriteStartMarker(Fee_30_FlexNor_SecureInstance_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_WritePayload()
 *********************************************************************************************************************/
/*! \brief       Writes the next part of the payload to the flash.
 *  \details     -
 *  \param[in]   ctx    Context that contains the payload that shall be written to flash. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_WritePayload(Fee_30_FlexNor_SecureInstance_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_WriteSealMarker()
 *********************************************************************************************************************/
/*! \brief       Writes the seal marker of the instance to flash
 *  \details     -
 *  \param[in]   ctx    Context that contains the instance the seal marker shall be written for. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_WriteSealMarker(Fee_30_FlexNor_SecureInstance_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_WriteCommitMarker()
 *********************************************************************************************************************/
/*! \brief       Writes the commit marker of the instance to flash
 *  \details     -
 *  \param[in]   ctx    Context that contains the instance the commit marker shall be written for. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_WriteCommitMarker(Fee_30_FlexNor_SecureInstance_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_ReadSourceContent()
 *********************************************************************************************************************/
/*! \brief       Reads parts of the source instances content based on the payload that was already copied
 *  \details     -
 *  \param[in]   ctx    Context that contains the informations about the instance thats content shall be read. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_ReadSourceContent(Fee_30_FlexNor_SecureInstance_ConstContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_WriteTargetContent()
 *********************************************************************************************************************/
/*! \brief       Writes the previously read source content to the target instance
 *  \details     -
 *  \param[in]   ctx    Context that contains the context information required. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_WriteTargetContent(Fee_30_FlexNor_SecureInstance_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_ReadStartMarker()
 *********************************************************************************************************************/
/*! \brief       Reads the start marker into the buffer
 *  \details     -
 *  \param[in]   ctx    Context that contains the context information required. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_ReadStartMarker(Fee_30_FlexNor_SecureInstance_ConstContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_ValidateStartMarker()
 *********************************************************************************************************************/
/*! \brief       Validates the start marker that was just read into the buffer
 *  \details     -
 *  \param[in]   ctx    Context that contains the context information required. Must not be NULL.
 *  \param[in]   offset Offsets that specifies where the marker starts.
 *  \return      Result of the validation
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_StructureValidityType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_ValidateStartMarker(
    Fee_30_FlexNor_SecureInstance_ConstContextPtrType ctx,
    Fee_30_FlexNor_LengthType offset);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_ReadCommitMarker()
 *********************************************************************************************************************/
/*! \brief       Reads the commit marker into the buffer
 *  \details     -
 *  \param[in]   ctx    Context that contains the context information required. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_ReadCommitMarker(Fee_30_FlexNor_SecureInstance_ConstContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_ValidateCommitMarker()
 *********************************************************************************************************************/
/*! \brief       Validates the commit marker that was just read into the buffer
 *  \details     -
 *  \param[in]   ctx    Context that contains the context information required. Must not be NULL.
 *  \param[in]   offset Offsets that specifies where the marker starts.
 *  \return      Result of the validation
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_StructureValidityType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_ValidateCommitMarker(
    Fee_30_FlexNor_SecureInstance_ConstContextPtrType ctx,
    Fee_30_FlexNor_LengthType offset);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_ReadSealMarker()
 *********************************************************************************************************************/
/*! \brief       Reads the seal marker into the buffer
 *  \details     -
 *  \param[in]   ctx    Context that contains the context information required. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_ReadSealMarker(Fee_30_FlexNor_SecureInstance_ConstContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_ValidateSealMarker()
 *********************************************************************************************************************/
/*! \brief       Validates the seal marker that was just read into the buffer
 *  \details     -
 *  \param[in]   ctx    Context that contains the context information required. Must not be NULL.
 *  \param[in]   offset Offsets that specifies where the marker starts.
 *  \return      Result of the validation
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_StructureValidityType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_ValidateSealMarker(
    Fee_30_FlexNor_SecureInstance_ConstContextPtrType ctx,
    Fee_30_FlexNor_LengthType offset);

#        define FEE_30_FLEXNOR_STOP_SEC_CODE
#        include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#    endif

#endif /* FEE_30_FLEXNOR_SECUREINSTANCEINTERNAL_H */

/**********************************************************************************************************************
 *  END OF FILE: Fee_30_FlexNor_SecureInstanceInternal.h
 *********************************************************************************************************************/
