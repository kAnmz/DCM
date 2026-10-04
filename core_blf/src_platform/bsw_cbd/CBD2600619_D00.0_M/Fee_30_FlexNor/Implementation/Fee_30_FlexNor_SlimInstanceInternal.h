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
/*!        \file  Fee_30_FlexNor_SlimInstanceInternal.h
 *        \brief  Internal slim instance business logic prototypes
 *      \details  Provides the internal prototypes for the business logic of the slim instance implementation.
 *         \unit  SlimInstance
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 **********************************************************************************************************************/

#if !defined(FEE_30_FLEXNOR_SLIMINSTANCEINTERNAL_H)
#    define FEE_30_FLEXNOR_SLIMINSTANCEINTERNAL_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#    include "Fee_30_FlexNor_Instance.h"
#    include "Fee_30_FlexNor_InstanceInternal.h"
#    include "Fee_30_FlexNor_ConfigInterface.h"

#    if (FEE_30_FLEXNOR_SLIMLAYOUT_ENABLED == STD_ON) /* COV_MSR_UT_OPTIONAL_UNIT */

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef struct Fee_30_FlexNor_SlimInstance
{
    Fee_30_FlexNor_InstanceDataPtrType InstanceData;           /*!< Pointer to the generic instance data. */
    Fee_30_FlexNor_ConstInstanceDataPtrType ConstInstanceData; /*!< Pointer to the const generic instance data. */
    Fee_30_FlexNor_MarkerType CommitMarker;                    /*!< Stores the commit marker of the instance. */
} Fee_30_FlexNor_SlimInstanceType;                             /*!< Holds all private data used by the concrete type. */

typedef struct P2VAR(Fee_30_FlexNor_SlimInstance_Context, AUTOMATIC, FEE_30_FLEXNOR_VAR) Fee_30_FlexNor_SlimInstance_ContextPtrType;

/* Module state */
typedef P2FUNC(Fee_30_FlexNor_ScheduleBehaviorType, AUTOMATIC, Fee_30_FlexNor_SlimInstance_ProcessEvt)(
    Fee_30_FlexNor_SlimInstance_ContextPtrType ctx);
typedef P2FUNC(void, AUTOMATIC, Fee_30_FlexNor_SlimInstance_FailEvt)(Fee_30_FlexNor_SlimInstance_ContextPtrType ctx);

typedef struct Fee_30_FlexNor_SlimInstance_State
{
    Fee_30_FlexNor_SlimInstance_ProcessEvt ProcessEvent; /*!< Pointer to the handler for the process event of the state */
    Fee_30_FlexNor_SlimInstance_FailEvt FailEvent;       /*!< Pointer to the handler for the fail event of the state */
} Fee_30_FlexNor_SlimInstance_StateType;                 /*!< Represents a state of the internal unit state machine */

typedef CONST(Fee_30_FlexNor_SlimInstance_StateType, AUTOMATIC) Fee_30_FlexNor_SlimInstance_ConstStateType;
typedef P2CONST(Fee_30_FlexNor_SlimInstance_StateType, AUTOMATIC, FEE_30_FLEXNOR_VAR) Fee_30_FlexNor_SlimInstance_ConstStatePtrType;

/* Module context */
typedef struct Fee_30_FlexNor_SlimInstance_Context
{
    Fee_30_FlexNor_SlimInstance_ConstStatePtrType CurrentState; /*!< Current state of the state machine. */

    Fee_30_FlexNor_SlimInstanceType Instance;           /*!< Slim instance data the unit operates on. */
    Fee_30_FlexNor_Instance_ContextType GenericContext; /*!< Parts of the context that is the same for both layouts. */
} Fee_30_FlexNor_SlimInstance_ContextType;              /*!< Represents the context for the internal state machine of the unit. */

typedef P2CONST(Fee_30_FlexNor_SlimInstance_ContextType, AUTOMATIC, FEE_30_FLEXNOR_VAR) Fee_30_FlexNor_SlimInstance_ConstContextPtrType;
/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#        define FEE_30_FLEXNOR_START_SEC_CODE
#        include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimInstance_StartJob()
 *********************************************************************************************************************/
/*! \brief       Start a job for the unit
 *  \details     Registers the unit at the scheduler to start the asynchronous processing for the unit.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimInstance_StartJob(void);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimInstance_EndJob()
 *********************************************************************************************************************/
/*! \brief       Ends a job for the unit
 *  \details     Unregisters the unit from the scheduler.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimInstance_EndJob(void);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimInstance_ResultHandler()
 *********************************************************************************************************************/
/*! \brief       Handles the result of a called service
 *  \details     This function is used as a result callback for services called by this unit.
 *  \param[in]   result               Result of the called service
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimInstance_ResultHandler(Fee_30_FlexNor_ServiceResult result);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimInstance_ReadInstanceMetadataAndStatus()
 *********************************************************************************************************************/
/*! \brief       Reads the instance metadata and status from flash.
 *  \details     -
 *  \param[in]   ctx        Context the instance metadata shall be read in. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimInstance_ReadInstanceMetadataAndStatus(Fee_30_FlexNor_SlimInstance_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimInstance_ValidateInstanceMetadata()
 *********************************************************************************************************************/
/*! \brief       Validates the instance metadata
 *  \details     Validates the instance metadata previously read from flash.
 *  \param[in]   ctx            Context that contains the read metadata that shall be validated. Must not be NULL.
 *  \return      Status of the instance metadata
 *  \pre         Instance metdata must be read from flash.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_StructureValidityType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimInstance_ValidateInstanceMetadata(
    Fee_30_FlexNor_SlimInstance_ConstContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimInstance_WritePayload()
 *********************************************************************************************************************/
/*! \brief       Writes the next part of the payload to the flash.
 *  \details     -
 *  \param[in]   ctx             Context that contains the payload that shall be written to flash. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimInstance_WritePayload(Fee_30_FlexNor_SlimInstance_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimInstance_WriteCommitMarker()
 *********************************************************************************************************************/
/*! \brief       Writes the commit marker of the instance to flash
 *  \details     -
 *  \param[in]   ctx             Context that contains the instance the commit marker shall be written for. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimInstance_WriteCommitMarker(Fee_30_FlexNor_SlimInstance_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimInstance_ReadSourceContent()
 *********************************************************************************************************************/
/*! \brief       Reads parts of the source instances content based on the payload that was already copied
 *  \details     -
 *  \param[in]   ctx    Context that contains the informations about the instance thats content shall be read. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimInstance_ReadSourceContent(Fee_30_FlexNor_SlimInstance_ConstContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimInstance_WriteTargetContent()
 *********************************************************************************************************************/
/*! \brief       Writes the previously read source content to the target instance
 *  \details     -
 *  \param[in]   ctx    Context that contains the context information required. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimInstance_WriteTargetContent(Fee_30_FlexNor_SlimInstance_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimInstance_ReadCommitMarker()
 *********************************************************************************************************************/
/*! \brief       Reads the commit marker into the buffer
 *  \details     -
 *  \param[in]   ctx    Context that contains the context information required. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimInstance_ReadCommitMarker(Fee_30_FlexNor_SlimInstance_ConstContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimInstance_ValidateCommitMarker()
 *********************************************************************************************************************/
/*! \brief       Validates the commit marker that was just read into the buffer.
 *  \details     -
 *  \param[in]   ctx    Context that contains the context information required. Must not be NULL.
 *  \return      Result of the validation
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_StructureValidityType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimInstance_ValidateCommitMarker(
    Fee_30_FlexNor_SlimInstance_ConstContextPtrType ctx);

#        define FEE_30_FLEXNOR_STOP_SEC_CODE
#        include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#    endif

#endif /* FEE_30_FLEXNOR_SLIMINSTANCEINTERNAL_H */

    /**********************************************************************************************************************
 *  END OF FILE: Fee_30_FlexNor_SlimInstanceInternal.h
 *********************************************************************************************************************/
