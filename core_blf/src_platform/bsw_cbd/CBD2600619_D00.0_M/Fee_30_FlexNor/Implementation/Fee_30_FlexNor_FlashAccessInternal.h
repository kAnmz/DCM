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
/*!        \file  Fee_30_FlexNor_FlashAccessInternal.h
 *        \brief  Internal flash access business logic prototypes
 *      \details  Provides the prototypes for the business logic functions for accessing the Fls driver.
 *         \unit  FlashAccess
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 **********************************************************************************************************************/

#if !defined (FEE_30_FLEXNOR_FLASHACCESS_INTERNAL_H)
# define FEE_30_FLEXNOR_FLASHACCESS_INTERNAL_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Fee_30_FlexNor_Types.h"
#include "Fee_30_FlexNor_FlashAccess.h"

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum
{
    FEE_30_FLEXNOR_ISBLANK,             /*!< The memory is blank */
    FEE_30_FLEXNOR_ISNOTBLANK,          /*!< The memory is blank */
    FEE_30_FLEXNOR_BLANKCHECK_FAILED    /*!< The blank check failed */
} Fee_30_FlexNor_BlankCheckResultType;  /*!< Type which indicates the status of a blank check result */

typedef enum
{
    FEE_30_FLEXNOR_FLASHACCESS_READ,          /*!< Flash access read job requested. */
    FEE_30_FLEXNOR_FLASHACCESS_READIMMEDIATE, /*!< Flash access read immediate job requested. */
    FEE_30_FLEXNOR_FLASHACCESS_WRITE,         /*!< Flash access write job requested. */
    FEE_30_FLEXNOR_FLASHACCESS_ERASE          /*!< Flash access erase job requested. */
}Fee_30_FlexNor_FlashAccess_JobType;          /*!< Represents the requested flash job. */

typedef struct P2VAR(Fee_30_FlexNor_FlashAccess_Context, AUTOMATIC, FEE_30_FLEXNOR_VAR) 
    Fee_30_FlexNor_FlashAccess_ContextPtrType;

/* Module state */
typedef P2FUNC(Fee_30_FlexNor_ScheduleBehaviorType, AUTOMATIC, Fee_30_FlexNor_FlashAccess_ProcessEvt)(
    Fee_30_FlexNor_FlashAccess_ContextPtrType ctx);

typedef struct Fee_30_FlexNor_FlashAccess_State
{
    Fee_30_FlexNor_FlashAccess_ProcessEvt ProcessEvent;    /*!< Pointer to the handler for the process event of the 
                                                                state */
} Fee_30_FlexNor_FlashAccess_StateType;                    /*!< Represents a state of the internal unit state machine */

typedef CONST(Fee_30_FlexNor_FlashAccess_StateType, AUTOMATIC) Fee_30_FlexNor_FlashAccess_ConstStateType;
typedef P2CONST(Fee_30_FlexNor_FlashAccess_StateType, AUTOMATIC, FEE_30_FLEXNOR_VAR) 
    Fee_30_FlexNor_FlashAccess_ConstStatePtrType;

/* Module context */
typedef struct Fee_30_FlexNor_FlashAccess_Context
{
    Fee_30_FlexNor_FlashAccess_ConstStatePtrType CurrentState; /*!< Current state of the state machine */

    /* Parameters for requested job */
    Fee_30_FlexNor_PartitionIdType PartitionId;                /*!< Id of the partition thats flash shall be accessed */
    Fee_30_FlexNor_AddressType JobAddress;                     /*!< Target address for the requested job */
    Fee_30_FlexNor_DataPtrType JobData;                        /*!< Pointer to a data buffer for reading data from 
                                                                    flash */
    Fee_30_FlexNor_ConstDataPtrType JobConstData;              /*!< Pointer to a const data buffer in case data 
                                                                    shall be written to flash */
    Fee_30_FlexNor_LengthType JobLength;                       /*!< Length of the flash job */
    Fee_30_FlexNor_FlashAccess_JobType RequestedJob;           /*!< Requested job */

    /* Result of the latest read job. */
    Fee_30_FlexNor_FlashAccess_FlashResultType ReadJobResult;  /*!< Result of the latest read job. */

    /* Internal information storage */   
    Fee_30_FlexNor_StatusType FlashJobStatus;                  /*!< Status of the flash job in case callbacks are used 
                                                                    for notification about the flash job status */
    Fee_30_FlexNor_ResultCallback ResultCallback;              /*!< Result callback that is used to communicate the 
                                                                    service result back to the caller. */  
    boolean SuspendWritesEnabled;                              /*!< Indicates whether flash write like jobs are 
                                                                    suspended or not. */ 
} Fee_30_FlexNor_FlashAccess_ContextType;                      /*!< Represents the context for the internal state 
                                                                    machine of the unit */

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
# define FEE_30_FLEXNOR_START_SEC_CODE
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Fee_30_FlexNor_FlashAccess_StartJob()
 *********************************************************************************************************************/
/*! \brief       Start a job for the unit
 *  \details     Registers the unit at the scheduler to start the asynchronous processing for the unit.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_FlashAccess_StartJob(void);

/**********************************************************************************************************************
 * Fee_30_FlexNor_FlashAccess_EndJob()
 *********************************************************************************************************************/
/*! \brief       Ends a job for the unit
 *  \details     Unregisters the unit from the scheduler.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_FlashAccess_EndJob(void);

/**********************************************************************************************************************
 * Fee_30_FlexNor_FlashAccess_IsFlashBlank()
 *********************************************************************************************************************/
/*! \brief          Evaluate if the checked flash is blank
 *  \details        Gets the result of a previously executed blank check.
 *  \param[in,out]  ctx                                Context of the job thats progress shall be checked
 *  \return         FEE_30_FLEXNOR_ISBLANK             The checked flash is blank
 *                  FEE_30_FLEXNOR_ISNOTBLANK          The checked flash is not blank
 *                  FEE_30_FLEXNOR_BLANKCHECK_FAILED   The blank check failed
 *  \pre            A blank check was successfully executed before.
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_BlankCheckResultType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_FlashAccess_IsFlashBlank(void);

/**********************************************************************************************************************
 * Fee_30_FlexNor_FlashAccess_CheckJobResult()
 *********************************************************************************************************************/
/*! \brief          Check flash job result
 *  \details        Checks the result of a previously setup flash job at the Fls driver.
 *  \param[in,out]  ctx                     Context of the job thats result shall be checked. Must not be NULL.
 *  \return         FEE_30_FLEXNOR_OK       The job was completed
 *                  FEE_30_FLEXNOR_PENDING  The job is still running
 *                  FEE_30_FLEXNOR_FAIL     The job failed
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_FlashAccess_FlashResultType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_FlashAccess_CheckJobResult(
    Fee_30_FlexNor_FlashAccess_ContextPtrType ctx, boolean isReadJob);

/**********************************************************************************************************************
 * Fee_30_FlexNor_FlashAccess_SetBufferToErasedValue()
 *********************************************************************************************************************/
/*! \brief          Fill buffer with erased value
 *  \details        Fills the data buffer inside the given context with the configured erased value. 
 *  \param[in,out]  ctx                     Context of the job whose result shall be erased. Must not be NULL.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_FlashAccess_SetBufferToErasedValue(
    Fee_30_FlexNor_FlashAccess_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_FlashAccess_SetupReadJob()
 *********************************************************************************************************************/
/*! \brief          Setup read job at underlaying Fls driver
 *  \details        -
 *  \param[in,out]  ctx                   Context the job shall be set up in. Must not be NULL.
 *  \return         E_OK                  Setting up the job was successfull
 *                  E_NOT_OK              Setting up the job failed
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_FlashAccess_SetupReadJob(
    Fee_30_FlexNor_FlashAccess_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_FlashAccess_SetupBlankCheck()
 *********************************************************************************************************************/
/*! \brief          Setup blank check job at the underlaying Fls driver
 *  \details        Sets up the blank check job in case at least one partition requires a blank check. 
 *                  Otherwise the setup request in rejected by default.
 *  \param[in,out]  ctx                   Context the job shall be set up in. Must not be NULL.
 *  \return         E_OK                  Setting up the job was successfull
 *                  E_NOT_OK              Setting up the job failed or the blank check is disabled (the latter case 
 *                                        never occurs during runtime)
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_FlashAccess_SetupBlankCheck(
    Fee_30_FlexNor_FlashAccess_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_FlashAccess_SetupWriteJob()
 *********************************************************************************************************************/
/*! \brief          Setup write job at underlaying Fls driver
 *  \details        -
 *  \param[in,out]  ctx                   Context the job shall be set up in. Must not be NULL.
 *  \return         E_OK                  Setting up the job was successfull
 *                  E_NOT_OK              Setting up the job failed
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_FlashAccess_SetupWriteJob(
    Fee_30_FlexNor_FlashAccess_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_FlashAccess_SetupEraseJob()
 *********************************************************************************************************************/
/*! \brief          Setup erase job at underlaying Fls driver
 *  \details        -
 *  \param[in,out]  ctx                   Context the job shall be set up in. Must not be NULL.
 *  \return         E_OK                  Setting up the job was successfull
 *                  E_NOT_OK              Setting up the job failed
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_FlashAccess_SetupEraseJob(
    Fee_30_FlexNor_FlashAccess_ContextPtrType ctx);

# define FEE_30_FLEXNOR_STOP_SEC_CODE
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* FEE_30_FLEXNOR_FLASHACCESS_INTERNAL_H */

/**********************************************************************************************************************
 *  END OF FILE: Fee_30_FlexNor_Internal.h
 *********************************************************************************************************************/
