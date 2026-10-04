/***********************************************************************************************************************
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
/*!        \file  vMem_30_Traveo2Cyp01_LL.c
 *        \brief  vMem_30_Traveo2Cyp01 LowLevel source file
 *
 *      \details  See vMem_30_Traveo2Cyp01_LL.h
 *         \unit  vMem_LL
 *
 **********************************************************************************************************************/
 
 /**********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 **********************************************************************************************************************/

#define VMEM_30_TRAVEO2CYP01_LL_SOURCE

/*lint -e537 */ /* Suppress ID537 due to MD_MSR_19.1 */
/*lint -e451 */ /* Suppress ID451 because MemMap.h cannot use a include guard */

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
#include "vMem_30_Traveo2Cyp01_LL.h"
#include "vMem_30_Traveo2Cyp01_IntShared.h"
#include "vMem_30_Traveo2Cyp01_LL_Regs.h"
#include "vMem_30_Traveo2Cyp01_LL_FlashMgtLib.h"
#include "vMem_30_Traveo2Cyp01_Extended_Func.h"
#include "vstdlib.h"

#if (VMEM_30_TRAVEO2CYP01_READONLY_MODE == STD_OFF) 
# include "vMem_30_Traveo2Cyp01_LL_DetChecks.h"
#endif /* VMEM_30_TRAVEO2CYP01_READONLY_MODE */

/***********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 **********************************************************************************************************************/
#define VMEM_30_TRAVEO2CYP01_CODE_FLASH_WORD_BLANK_PATTERN           0xFFFFFFFFuL

/* Hardware supports only one flash instance. */
# define VMEM_30_TRAVEO2CYP01_INSTANCE_ID                            (0u)

/***********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

#if !defined (VMEM_30_TRAVEO2CYP01_LOCAL) /* COV_VMEM_30_TRAVEO2CYP01_COMPATIBILITY */
# define VMEM_30_TRAVEO2CYP01_LOCAL static
#endif

#if !defined (VMEM_30_TRAVEO2CYP01_LOCAL_INLINE) /* COV_VMEM_30_TRAVEO2CYP01_COMPATIBILITY */
//# define VMEM_30_TRAVEO2CYP01_LOCAL_INLINE LOCAL_INLINE
# define VMEM_30_TRAVEO2CYP01_LOCAL_INLINE
#endif

/*! Timeout counter for asynchronous requests */
typedef uint16 vMem_30_Traveo2Cyp01_TimeoutCounterType;

/*! Length of a word, used for BlankCheck */
typedef uint32 vMem_30_Traveo2Cyp01_wordType;

/*! Const Ptr Type to a word used for BlankCheck */
typedef P2CONST(vMem_30_Traveo2Cyp01_wordType, AUTOMATIC, VMEM_30_TRAVEO2CYP01_VAR) vMem_30_Traveo2Cyp01_ConstWordPtrType;

/*! Indicates the state of the current job. */
typedef enum
{
  VMEM_30_TRAVEO2CYP01_JOB_STATE_IDLE = 0,
#if (VMEM_30_TRAVEO2CYP01_READONLY_MODE == STD_OFF)
  VMEM_30_TRAVEO2CYP01_JOB_STATE_SETUP_WRITE,
  VMEM_30_TRAVEO2CYP01_JOB_STATE_SETUP_ERASE,
#endif /* VMEM_30_TRAVEO2CYP01_READONLY_MODE */
  VMEM_30_TRAVEO2CYP01_JOB_STATE_SETUP_BLANK,
  VMEM_30_TRAVEO2CYP01_JOB_STATE_WAIT_FOR_FLASHMGTLIB,
  VMEM_30_TRAVEO2CYP01_JOB_STATE_WAIT_FOR_FLASH,
  VMEM_30_TRAVEO2CYP01_JOB_STATE_TIMEOUT
} vMem_30_Traveo2Cyp01_JobStateType;

/*! Indicates the kind of asynchronous job. */
typedef enum
{
  VMEM_30_TRAVEO2CYP01_ASYNC_WRITE = 0,
  VMEM_30_TRAVEO2CYP01_ASYNC_ERASE,
  VMEM_30_TRAVEO2CYP01_ASYNC_ISBLANK,
  VMEM_30_TRAVEO2CYP01_ASYNC_NONE
} vMem_30_Traveo2Cyp01_AsyncJobType;

/*! Pointer type for write buffer, which gets forwardet to the FlashMgtLib unit for the ProgramRow system call. */
typedef vMem_30_Traveo2Cyp01_FlashMgtLib_ConstWriteBufferPtrType vMem_30_Traveo2Cyp01_WriteBufferPtrType;

/*! Stores information about current job */
typedef struct
{
  vMem_30_Traveo2Cyp01_AddressType TargetAddress;            /*!< Indicates the target address of the job. */
  vMem_30_Traveo2Cyp01_WriteBufferPtrType SourceAddressPtr;  /*!< Indicates the source address of the job. */
  vMem_30_Traveo2Cyp01_LengthType Length;                    /*!< Indicates the length in bytes of the job. */
  vMem_30_Traveo2Cyp01_JobStateType JobState;                /*!< Indicates the state of the job. */
  vMem_30_Traveo2Cyp01_JobResultType JobResult;              /*!< Indicates the result of the job. */
  vMem_30_Traveo2Cyp01_AsyncJobType CurrentAsyncJob;         /*!< Indicates the currently processed type of asynchronous job. */
} vMem_30_Traveo2Cyp01_JobInfoType;

/***********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 **********************************************************************************************************************/

#define VMEM_30_TRAVEO2CYP01_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"                                                                                                     /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Stores information about the current job */
VMEM_30_TRAVEO2CYP01_LOCAL VAR(vMem_30_Traveo2Cyp01_JobInfoType, VMEM_30_TRAVEO2CYP01_VAR_NOINIT)
  vMem_30_Traveo2Cyp01_CurrentJobInfo;

#define VMEM_30_TRAVEO2CYP01_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"                                                                                                     /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define VMEM_30_TRAVEO2CYP01_START_SEC_VAR_NOINIT_16BIT
#include "MemMap.h"                                                                                                     /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Ipc Get Lock Timeout Counter */
VMEM_30_TRAVEO2CYP01_LOCAL VAR(vMem_30_Traveo2Cyp01_TimeoutCounterType, VMEM_30_TRAVEO2CYP01_VAR_NOINIT)
  vMem_30_Traveo2Cyp01_IpcGetLockTimeoutCounter;

#define VMEM_30_TRAVEO2CYP01_STOP_SEC_VAR_NOINIT_16BIT
#include "MemMap.h"                                                                                                     /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  GLOBAL DATA
 **********************************************************************************************************************/

#define VMEM_30_TRAVEO2CYP01_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"                                                                                                     /* PRQA S 5087 */ /* MD_MSR_MemMap */

CONST(vMemAccM_vMemHwSpecificFuncPtr, AUTOMATIC) vMem_30_Traveo2Cyp01_HwSpecificFunctions[VMEM_30_TRAVEO2CYP01_EXTENDED_FUNCTION_COUNT] =
{
  &vMem_30_Traveo2Cyp01_SetDualBankMode,
  &vMem_30_Traveo2Cyp01_PerformMemorySwap
};

#define VMEM_30_TRAVEO2CYP01_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"                                                                                                     /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

#define VMEM_30_TRAVEO2CYP01_START_SEC_CODE
#include "MemMap.h"                                                                                                     /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_LLStartJobProcessing()
 **********************************************************************************************************************/
/*!
 * \brief       Starts the asynchronous job processing state machine.
 * \details     -
 * \return      TRUE - Job processing could be successfully started.
 *              FALSE - Job state is incorrect or FlashMgtLib returned FALSE.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 **********************************************************************************************************************/
VMEM_30_TRAVEO2CYP01_LOCAL_INLINE FUNC(Std_ReturnType, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_LLStartJobProcessing(void);

#if (VMEM_30_TRAVEO2CYP01_READONLY_MODE == STD_OFF)
/***********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_LLProcessWrite()
 **********************************************************************************************************************/
/*!
 * \brief       Processes the asynchronous write job.
 * \details     -
 * \return      TRUE - FlashMgtLib accepted write request.
 *              FALSE - FlashMgtLib declined write request.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 **********************************************************************************************************************/
VMEM_30_TRAVEO2CYP01_LOCAL_INLINE FUNC(Std_ReturnType, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_LLProcessWrite(void);

/***********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_LLProcessErase()
 **********************************************************************************************************************/
/*!
 * \brief       Processes the asynchronous erase job.
 * \details     -
 * \return      TRUE - FlashMgtLib accepted erase request.
 *              FALSE - FlashMgtLib declined erase request.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 **********************************************************************************************************************/
VMEM_30_TRAVEO2CYP01_LOCAL_INLINE FUNC(Std_ReturnType, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_LLProcessErase(void);

/***********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_LLCodeFlashWriteEnable()
 **********************************************************************************************************************/
/*!
 * \brief       Enables the hardware write access of the code flash.
 * \details     This function has to be called directly before the hardware gets a write or erase request
 *              for the code flash. See hardware safety manual for more details.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 **********************************************************************************************************************/
VMEM_30_TRAVEO2CYP01_LOCAL_INLINE FUNC(void, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_LLCodeFlashWriteEnable(void);

/***********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_LLWorkFlashWriteEnable()
 **********************************************************************************************************************/
/*!
 * \brief       Enables the hardware write access of the work flash.
 * \details     This function has to be called directly before the hardware gets a write or erase request
 *              for the work flash. See hardware safety manual for more details.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 **********************************************************************************************************************/
VMEM_30_TRAVEO2CYP01_LOCAL_INLINE FUNC(void, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_LLWorkFlashWriteEnable(void);

/***********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_LLGetBitOffsetFromMemType()
 **********************************************************************************************************************/
/*!
 * \brief       Returns a bit offset for a given flash type.
 * \details     -
 * \param[in]   FlashMemoryType       FlashType for which a bit offset should be calculated
 * \return      Bit offset for the given flash type.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 **********************************************************************************************************************/
VMEM_30_TRAVEO2CYP01_LOCAL_INLINE FUNC(uint8, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_LLGetBitOffsetFromMemType(
    vMem_30_Traveo2Cyp01_FlashTypeType FlashMemoryType);

#endif /* VMEM_30_TRAVEO2CYP01_READONLY_MODE */

/***********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_LLProcessBlank()
 **********************************************************************************************************************/
/*!
 * \brief       Processes the asynchronous blank check job for work flash.
 * \details     -
 * \return      TRUE - Blank check request was accepted.
 *              FALSE - Blank check request was declined.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 **********************************************************************************************************************/
VMEM_30_TRAVEO2CYP01_LOCAL_INLINE FUNC(Std_ReturnType, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_LLProcessBlank(void);

/***********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_LLIsJobSetup()
 **********************************************************************************************************************/
/*!
 * \brief       Checks if a job is already setup and ready for processing.
 * \details     -
 * \return      TRUE - Job is already setup.
 *              FALSE - No job is setup.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 **********************************************************************************************************************/
VMEM_30_TRAVEO2CYP01_LOCAL_INLINE FUNC(boolean, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_LLIsJobSetup(void);

/***********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_LLProcStateSetup()
 **********************************************************************************************************************/
/*!
 * \brief       Implements the processing of the setup write, setup erase and setup blank state.
 * \details     -
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 **********************************************************************************************************************/
VMEM_30_TRAVEO2CYP01_LOCAL_INLINE FUNC(void, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_LLProcStateSetup(void);

/***********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_LLProcStateWaitForFlashMgtLib()
 **********************************************************************************************************************/
/*!
 * \brief       Implements the processing of the wait for FlashMgtLib state.
 * \details     -
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 **********************************************************************************************************************/
VMEM_30_TRAVEO2CYP01_LOCAL_INLINE FUNC(void, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_LLProcStateWaitForFlashMgtLib(void);

/***********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_LLProcStateWaitForFlash()
 **********************************************************************************************************************/
/*!
 * \brief       Implements the processing of the wait for Flash state.
 * \details     -
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 **********************************************************************************************************************/
VMEM_30_TRAVEO2CYP01_LOCAL_INLINE FUNC(void, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_LLProcStateWaitForFlash(void);

/***********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_LLIsFlashMgtLibReady()
 **********************************************************************************************************************/
/*!
 * \brief       Checks if the flash management library is ready for a new job.
 * \details     -
 * \return      TRUE - flash management library is ready.
 *              FALSE - flash management library is busy.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 **********************************************************************************************************************/
VMEM_30_TRAVEO2CYP01_LOCAL_INLINE FUNC(boolean, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_LLIsFlashMgtLibReady(void);

/***********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_LLIsFlashReady()
 **********************************************************************************************************************/
/*!
 * \brief       Checks if the flash hardware is ready for a new job.
 * \details     -
 * \return      TRUE - Flash is ready.
 *              FALSE - Flash is busy.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 **********************************************************************************************************************/
VMEM_30_TRAVEO2CYP01_LOCAL_INLINE FUNC(boolean, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_LLIsFlashReady(void);

/***********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_LLIsFlashHanging()
 **********************************************************************************************************************/
/*!
 * \brief       Checks if the flash hardware is hanging.
 * \details     -
 * \return      TRUE - Flash is hanging.
 *              FALSE - Flash is not hanging.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 **********************************************************************************************************************/
VMEM_30_TRAVEO2CYP01_LOCAL_INLINE FUNC(boolean, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_LLIsFlashHanging(void);

/***********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_LLAnalyzeFlashMgtLibResult()
 **********************************************************************************************************************/
/*!
 * \brief       Analyzes the result of the FlashMgtLib.
 * \details     -
 * \return      TRUE - Flash is hanging.
 *              FALSE - Flash is not hanging.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 **********************************************************************************************************************/
VMEM_30_TRAVEO2CYP01_LOCAL_INLINE FUNC(vMem_30_Traveo2Cyp01_JobResultType, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_LLAnalyzeFlashMgtLibResult(void);

/***********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_LLTriggerTimeoutCounter()
 **********************************************************************************************************************/
/*!
 * \brief       Increments Ipc get lock timeout counter and check for overflow.
 * \details     -
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 **********************************************************************************************************************/
VMEM_30_TRAVEO2CYP01_LOCAL_INLINE FUNC(void, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_LLTriggerTimeoutCounter(void);

/***********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_LLFlashWriteDisable()
 **********************************************************************************************************************/
/*!
 * \brief       Disables the hardware write access of the work and code flash.
 * \details     This function has to be called directly after the hardware finished the write or erase request
 *              for the flash. See hardware safety manual for more details.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 **********************************************************************************************************************/
VMEM_30_TRAVEO2CYP01_LOCAL_INLINE FUNC(void, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_LLFlashWriteDisable(void);

/***********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_LLWorkFlashEccEnable()
 **********************************************************************************************************************/
/*!
 * \brief       Enables ECC error detection for work flash.
 * \details     -
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 **********************************************************************************************************************/
VMEM_30_TRAVEO2CYP01_LOCAL_INLINE FUNC(void, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_LLWorkFlashEccEnable(void);

/***********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_LLSuppressEccErrors()
 **********************************************************************************************************************/
/*!
 * \brief       Suppresses non-correctable errors.
 * \details     Bus transfer does not have a bus error (the error is silent).
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 **********************************************************************************************************************/
VMEM_30_TRAVEO2CYP01_LOCAL_INLINE FUNC(void, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_LLSuppressEccErrors(void);

/***********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_LLIsCodeFlashBlank()
 **********************************************************************************************************************/
/*!
 * \brief       Checks if the given code flash pages are blank.
 * \details     -
 * \param[in]   TargetAddress       Address of the flash page to be checked.
 * \param[in]   Length              Number of bytes to be checked (must be page aligned).
 * \return      TRUE - code flash pages are blank.
 *              FALSE - code flash pages are not blank.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 **********************************************************************************************************************/
VMEM_30_TRAVEO2CYP01_LOCAL_INLINE FUNC(boolean, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_LLIsCodeFlashBlank(
    vMem_30_Traveo2Cyp01_AddressType TargetAddress,
    vMem_30_Traveo2Cyp01_LengthType Length);

/***********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_LLPerformDummyRead()
 **********************************************************************************************************************/
/*!
 * \brief       Performs a dummy read in case of a write or erase job is currently processed.
 * \details     -
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 **********************************************************************************************************************/
VMEM_30_TRAVEO2CYP01_LOCAL_INLINE FUNC(void, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_LLPerformDummyRead(void);

/***********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_LLGetFlashType()
 **********************************************************************************************************************/
/*!
 * \brief       Retreives the flash type from a given TargetAddress.
 * \details     -
 * \param[in]   TargetAddress       Address of the flash to be checked.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 **********************************************************************************************************************/
VMEM_30_TRAVEO2CYP01_LOCAL_INLINE FUNC(vMem_30_Traveo2Cyp01_FlashTypeType, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_LLGetFlashType(
  vMem_30_Traveo2Cyp01_AddressType TargetAddress);

/***********************************************************************************************************************
 *  LOCAL FUNCTIONS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_LLStartJobProcessing()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VMEM_30_TRAVEO2CYP01_LOCAL_INLINE FUNC(Std_ReturnType, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_LLStartJobProcessing(void)
{
  /* ----------- Local variables ----------------------------------------------------------------- */
  Std_ReturnType retVal;

  /* ----------- Implementation ------------------------------------------------------------------ */
  switch (vMem_30_Traveo2Cyp01_CurrentJobInfo.JobState)                                                                 /* PRQA S 3315 */ /* MD_vMem_30_Traveo2Cyp01_3315_RedundantSwitch */
  {
#if (VMEM_30_TRAVEO2CYP01_READONLY_MODE == STD_OFF)
    case VMEM_30_TRAVEO2CYP01_JOB_STATE_SETUP_WRITE:
      retVal = vMem_30_Traveo2Cyp01_LLProcessWrite();
      break;
    case VMEM_30_TRAVEO2CYP01_JOB_STATE_SETUP_ERASE:
      retVal = vMem_30_Traveo2Cyp01_LLProcessErase();
      break;
#endif /* VMEM_30_TRAVEO2CYP01_READONLY_MODE */
    default: /* VMEM_30_TRAVEO2CYP01_JOB_STATE_SETUP_BLANK is the only remaining possible state */
      retVal = vMem_30_Traveo2Cyp01_LLProcessBlank();
      break;
  }

  return retVal;
} /* vMem_30_Traveo2Cyp01_LLStartJobProcessing */

#if (VMEM_30_TRAVEO2CYP01_READONLY_MODE == STD_OFF)
/***********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_LLProcessWrite()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
VMEM_30_TRAVEO2CYP01_LOCAL_INLINE FUNC(Std_ReturnType, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_LLProcessWrite(void)
{
  /* ----------- Local variables ----------------------------------------------------------------- */
  vMem_30_Traveo2Cyp01_FlashTypeType flashType = vMem_30_Traveo2Cyp01_LLGetFlashType(vMem_30_Traveo2Cyp01_CurrentJobInfo.TargetAddress);

  /* ----------- Implementation ------------------------------------------------------------------ */
  /* #10 Enable write access for code or work flash. Depending on the given sector address. */
  if(flashType == VMEM_30_TRAVEO2CYP01_FLASH_TYPE_CODE)
  {
    vMem_30_Traveo2Cyp01_LLCodeFlashWriteEnable();
  }
  else /* flashType == VMEM_30_TRAVEO2CYP01_FLASH_TYPE_WORK */
  {
    vMem_30_Traveo2Cyp01_LLWorkFlashWriteEnable();
  }

  /* #20 Forward write job request to FlashMgtLib. */
  return vMem_30_Traveo2Cyp01_FlashMgtLib_ProgramRow(vMem_30_Traveo2Cyp01_CurrentJobInfo.TargetAddress,
      vMem_30_Traveo2Cyp01_CurrentJobInfo.SourceAddressPtr, flashType, vMem_30_Traveo2Cyp01_CurrentJobInfo.Length);
} /* vMem_30_Traveo2Cyp01_LLProcessWrite */

/***********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_LLProcessErase()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
VMEM_30_TRAVEO2CYP01_LOCAL_INLINE FUNC(Std_ReturnType, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_LLProcessErase(void)
{
  /* ----------- Local variables ----------------------------------------------------------------- */
  vMem_30_Traveo2Cyp01_FlashTypeType flashType = vMem_30_Traveo2Cyp01_LLGetFlashType(vMem_30_Traveo2Cyp01_CurrentJobInfo.TargetAddress);

  /* ----------- Implementation ------------------------------------------------------------------ */
  /* #10 Enable write access for code or work flash. Depending on the given sector address. */
  if (flashType == VMEM_30_TRAVEO2CYP01_FLASH_TYPE_CODE)
  {
    vMem_30_Traveo2Cyp01_LLCodeFlashWriteEnable();
  }
  else /* flashType == VMEM_30_TRAVEO2CYP01_FLASH_TYPE_WORK */
  {
    vMem_30_Traveo2Cyp01_LLWorkFlashWriteEnable();
  }

  /* #20 Forward erase job request to FlashMgtLib. */
  return vMem_30_Traveo2Cyp01_FlashMgtLib_EraseSector(vMem_30_Traveo2Cyp01_CurrentJobInfo.TargetAddress);
} /* vMem_30_Traveo2Cyp01_LLProcessErase */

/***********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_LLCodeFlashWriteEnable()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VMEM_30_TRAVEO2CYP01_LOCAL_INLINE FUNC(void, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_LLCodeFlashWriteEnable(void)
{
  /* #10 Enable write access to main (code) flash. */
  vMem_30_Traveo2Cyp01_Reg_WriteBits(VMEM_30_TRAVEO2CYP01_BASE_FLASHC,
      VMEM_30_TRAVEO2CYP01_FLASHC_FM_CTL_ECT_REG_OFFS_MAIN_FLASH_SAFETY,
      VMEM_30_TRAVEO2CYP01_FLASHC_FM_CTL_ECT_REG_MAIN_FLASH_SAFETY,
      VMEM_30_TRAVEO2CYP01_FLASHC_FM_CTL_ECT_REG_MAIN_FLASH_SAFETY_WRITE_ENABLE);

} /* vMem_30_Traveo2Cyp01_LLCodeFlashWriteEnable */

/***********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_LLWorkFlashWriteEnable()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VMEM_30_TRAVEO2CYP01_LOCAL_INLINE FUNC(void, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_LLWorkFlashWriteEnable(void)
{
  /* #10 Enable write access to work flash. */
  vMem_30_Traveo2Cyp01_Reg_WriteBits(VMEM_30_TRAVEO2CYP01_BASE_FLASHC,
      VMEM_30_TRAVEO2CYP01_FLASHC_FM_CTL_ECT_REG_OFFS_WORK_FLASH_SAFETY,
      VMEM_30_TRAVEO2CYP01_FLASHC_FM_CTL_ECT_REG_WORK_FLASH_SAFETY,
      VMEM_30_TRAVEO2CYP01_FLASHC_FM_CTL_ECT_REG_WORK_FLASH_SAFETY_WRITE_ENABLE);

} /* vMem_30_Traveo2Cyp01_LLWorkFlashWriteEnable */

/***********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_LLGetBitOffsetFromMemType()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VMEM_30_TRAVEO2CYP01_LOCAL_INLINE FUNC(uint8, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_LLGetBitOffsetFromMemType(
    vMem_30_Traveo2Cyp01_FlashTypeType FlashMemoryType)
{
  uint8 bitOffset;

  /* #10 Set the bitOffset accordingly to the FlashMemoryType. */
  if(FlashMemoryType == VMEM_30_TRAVEO2CYP01_FLASH_TYPE_CODE)
  {
    bitOffset = 0;
  }
  else
  {
    bitOffset = 1;
  }

  return bitOffset;

} /* vMem_30_Traveo2Cyp01_LLGetBitOffsetFromMemType */

#endif /* VMEM_30_TRAVEO2CYP01_READONLY_MODE */

/***********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_LLProcessBlank()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VMEM_30_TRAVEO2CYP01_LOCAL_INLINE FUNC(Std_ReturnType, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_LLProcessBlank(void)
{
  /* ----------- Implementation ------------------------------------------------------------------ */
  return vMem_30_Traveo2Cyp01_FlashMgtLib_BlankCheck(vMem_30_Traveo2Cyp01_CurrentJobInfo.TargetAddress,
      (uint16)(vMem_30_Traveo2Cyp01_CurrentJobInfo.Length / VMEM_30_TRAVEO2CYP01_WORD_IN_BYTES));
} /* vMem_30_Traveo2Cyp01_LLProcessBlank */

/***********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_LLIsJobSetup()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VMEM_30_TRAVEO2CYP01_LOCAL_INLINE FUNC(boolean, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_LLIsJobSetup(void)
{
  /* ----------- Implementation ------------------------------------------------------------------ */
  return (
#if (VMEM_30_TRAVEO2CYP01_READONLY_MODE == STD_OFF)
      (vMem_30_Traveo2Cyp01_CurrentJobInfo.JobState == VMEM_30_TRAVEO2CYP01_JOB_STATE_SETUP_WRITE) ||
      (vMem_30_Traveo2Cyp01_CurrentJobInfo.JobState == VMEM_30_TRAVEO2CYP01_JOB_STATE_SETUP_ERASE) ||
#endif /* VMEM_30_TRAVEO2CYP01_READONLY_MODE */
      (vMem_30_Traveo2Cyp01_CurrentJobInfo.JobState == VMEM_30_TRAVEO2CYP01_JOB_STATE_SETUP_BLANK)) ? TRUE : FALSE;
} /* vMem_30_Traveo2Cyp01_LLIsJobSetup */

/***********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_LLProcStateSetup()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VMEM_30_TRAVEO2CYP01_LOCAL_INLINE FUNC(void, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_LLProcStateSetup(void)
{
  if (vMem_30_Traveo2Cyp01_LLStartJobProcessing() == E_OK)
  {
    vMem_30_Traveo2Cyp01_CurrentJobInfo.JobState = VMEM_30_TRAVEO2CYP01_JOB_STATE_WAIT_FOR_FLASHMGTLIB;
  }
  else
  {
    vMem_30_Traveo2Cyp01_LLTriggerTimeoutCounter();
  }
} /* vMem_30_Traveo2Cyp01_LLProcStateSetup */

/***********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_LLProcStateWaitForFlashMgtLib()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VMEM_30_TRAVEO2CYP01_LOCAL_INLINE FUNC(void, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_LLProcStateWaitForFlashMgtLib(void)
{
  if (vMem_30_Traveo2Cyp01_LLIsFlashMgtLibReady() == TRUE)
  {
    vMem_30_Traveo2Cyp01_CurrentJobInfo.JobState = VMEM_30_TRAVEO2CYP01_JOB_STATE_WAIT_FOR_FLASH;
  }
} /* vMem_30_Traveo2Cyp01_LLProcStateWaitForFlashMgtLib */

/***********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_LLProcStateWaitForFlash()
 **********************************************************************************************************************/
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
 */
VMEM_30_TRAVEO2CYP01_LOCAL_INLINE FUNC(void, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_LLProcStateWaitForFlash(void)
{
  /* #10 Check if Flash hardware is ready.  */
  if (vMem_30_Traveo2Cyp01_LLIsFlashReady() == TRUE)
  {
    /* #20 Check if Flash hardware is hanging. */
    if(vMem_30_Traveo2Cyp01_LLIsFlashHanging() == TRUE)
    {
      /* #30 In case of a hanging hardware the job was not processed successfully. So set the job result to failed. */
      vMem_30_Traveo2Cyp01_CurrentJobInfo.JobResult = VMEM_JOB_FAILED;
    }
    else
    {
      /* #40 Otherwise return the result of the FlashMgtLib. */
      vMem_30_Traveo2Cyp01_CurrentJobInfo.JobResult = vMem_30_Traveo2Cyp01_LLAnalyzeFlashMgtLibResult();
    }

    /* #50 Disable write access to Flash.  */
    vMem_30_Traveo2Cyp01_LLFlashWriteDisable();

    /* #60 Perform DummyRead. */
    vMem_30_Traveo2Cyp01_LLPerformDummyRead();                                                                          /* PRQA S 2987 1 */ /* MD_vMem_30_Traveo2Cyp01_2987_DummyRead */

    /* #70 Switch back to IDLE. Means the job is completely processed. */
    vMem_30_Traveo2Cyp01_CurrentJobInfo.JobState        = VMEM_30_TRAVEO2CYP01_JOB_STATE_IDLE;
    vMem_30_Traveo2Cyp01_CurrentJobInfo.CurrentAsyncJob = VMEM_30_TRAVEO2CYP01_ASYNC_NONE;
  }

} /* vMem_30_Traveo2Cyp01_LLProcStateWaitForFlash */

/***********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_LLIsFlashMgtLibReady()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VMEM_30_TRAVEO2CYP01_LOCAL_INLINE FUNC(boolean, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_LLIsFlashMgtLibReady(void)
{
  return (vMem_30_Traveo2Cyp01_FlashMgtLib_GetResult() != VMEM_30_TRAVEO2CYP01_RESULT_PENDING) ? TRUE : FALSE;
} /* vMem_30_Traveo2Cyp01_LLIsFlashMgtLibReady */

/***********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_LLIsFlashReady()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VMEM_30_TRAVEO2CYP01_LOCAL_INLINE FUNC(boolean, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_LLIsFlashReady(void)
{
  /* ----------- Local variables ----------------------------------------------------------------- */
  vMem_30_Traveo2Cyp01_RegWidthType flashBusyStatus;

  /* ----------- Implementation ------------------------------------------------------------------ */
  flashBusyStatus = vMem_30_Traveo2Cyp01_Reg_ReadBits(VMEM_30_TRAVEO2CYP01_BASE_FLASHC,
      VMEM_30_TRAVEO2CYP01_FLASHC_FM_CTL_ECT_REG_OFFS_STATUS, VMEM_30_TRAVEO2CYP01_FLASHC_FM_CTL_ECT_REG_STATUS_BUSY);

  return (flashBusyStatus == VMEM_30_TRAVEO2CYP01_FLASHC_FM_CTL_ECT_REG_STATUS_BUSY_READY) ? TRUE : FALSE;
} /* vMem_30_Traveo2Cyp01_LLIsFlashReady */

/***********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_LLIsFlashReady()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VMEM_30_TRAVEO2CYP01_LOCAL_INLINE FUNC(boolean, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_LLIsFlashHanging(void)
{
  /* ----------- Local variables ----------------------------------------------------------------- */
  vMem_30_Traveo2Cyp01_RegWidthType flashHangStatus;

  /* ----------- Implementation ------------------------------------------------------------------ */
  flashHangStatus = vMem_30_Traveo2Cyp01_Reg_ReadBits(VMEM_30_TRAVEO2CYP01_BASE_FLASHC,
      VMEM_30_TRAVEO2CYP01_FLASHC_FM_CTL_ECT_REG_OFFS_STATUS, VMEM_30_TRAVEO2CYP01_FLASHC_FM_CTL_ECT_REG_STATUS_HANG);

  return (flashHangStatus == VMEM_30_TRAVEO2CYP01_FLASHC_FM_CTL_ECT_REG_STATUS_HANG_FAIL) ? TRUE : FALSE;
} /* vMem_30_Traveo2Cyp01_LLIsFlashReady */

/***********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_LLAnalyzeFlashMgtLibResult()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VMEM_30_TRAVEO2CYP01_LOCAL_INLINE FUNC(vMem_30_Traveo2Cyp01_JobResultType, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_LLAnalyzeFlashMgtLibResult(void)
{
  /* ----------- Local variables ----------------------------------------------------------------- */
  vMem_30_Traveo2Cyp01_JobResultType jobResult;
  vMem_30_Traveo2Cyp01_FlashMgtLib_ResultType flashMgtLibResult = vMem_30_Traveo2Cyp01_FlashMgtLib_GetResult();

  /* ----------- Implementation ------------------------------------------------------------------ */
  switch (flashMgtLibResult)
  {
    case VMEM_30_TRAVEO2CYP01_RESULT_OK:
      jobResult = VMEM_JOB_OK;
      break;
    case VMEM_30_TRAVEO2CYP01_RESULT_MEM_NOT_BLANK:
      jobResult = VMEM_MEM_NOT_BLANK;
      break;
    case VMEM_30_TRAVEO2CYP01_RESULT_PENDING:
      jobResult = VMEM_JOB_FAILED; 
      /* It was already checked in the last state 'VMEM_30_TRAVEO2CYP01_JOB_STATE_WAIT_FOR_FLASHMGTLIB', that the
         FlashMgtLib is not pending anymore. If it is now back to pending, this would be undefined behavior from HW
         side. Therefor, we set the jobResult to VMEM_JOB_FAILED. */
      break;
    case VMEM_30_TRAVEO2CYP01_RESULT_FAILED:
      jobResult = VMEM_JOB_FAILED;
      break;
    default:
      jobResult = VMEM_JOB_FAILED;
      break;
  }

  return jobResult;
} /* vMem_30_Traveo2Cyp01_LLAnalyzeFlashMgtLibResult */

/***********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_LLTriggerTimeoutCounter()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
VMEM_30_TRAVEO2CYP01_LOCAL_INLINE FUNC(void, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_LLTriggerTimeoutCounter(void)
{
  /* ----------- Implementation ------------------------------------------------------------------ */
  if(vMem_30_Traveo2Cyp01_IpcGetLockTimeoutCounter >= (VMEM_30_TRAVEO2CYP01_IPC_GET_LOCK_TIMEOUT_COUNTER_MAX_VALUE - 1u))
  {
    vMem_30_Traveo2Cyp01_CurrentJobInfo.JobState = VMEM_30_TRAVEO2CYP01_JOB_STATE_TIMEOUT;
    vMem_30_Traveo2Cyp01_CurrentJobInfo.JobResult = VMEM_JOB_FAILED;
  }
  else
  {
    vMem_30_Traveo2Cyp01_IpcGetLockTimeoutCounter++;
  }
} /* vMem_30_Traveo2Cyp01_LLTriggerTimeoutCounter */

/***********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_LLIsCodeFlashBlank()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VMEM_30_TRAVEO2CYP01_LOCAL_INLINE FUNC(boolean, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_LLIsCodeFlashBlank(
    vMem_30_Traveo2Cyp01_AddressType TargetAddress,
    vMem_30_Traveo2Cyp01_LengthType  Length)
{
  boolean result = TRUE;
  vMem_30_Traveo2Cyp01_LengthType wordIndex;
                                                                                                                        /* PRQA S 0306 1 */ /* MD_vMem_30_Traveo2Cyp01_0326_0306_FlashReadAccess */
  vMem_30_Traveo2Cyp01_ConstWordPtrType wordPtr        = (vMem_30_Traveo2Cyp01_ConstWordPtrType) TargetAddress;
  vMem_30_Traveo2Cyp01_LengthType       numberOfWords  = Length / VMEM_30_TRAVEO2CYP01_WORD_IN_BYTES;

  /* #10 Iterate over calculated words and check for blank check pattern. */
  for(wordIndex = 0; wordIndex < numberOfWords; wordIndex++)
  {
    if(wordPtr[wordIndex] != VMEM_30_TRAVEO2CYP01_CODE_FLASH_WORD_BLANK_PATTERN)                               /* VCA_VMEM_VALID_TARGETADDRESS */
    {
      result = FALSE;
      break;
    }
  }
  return result;
} /* vMem_30_Traveo2Cyp01_LLIsCodeFlashBlank */

/***********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_LLFlashWriteDisable()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
VMEM_30_TRAVEO2CYP01_LOCAL_INLINE FUNC(void, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_LLFlashWriteDisable(void)
{
  /* #10 Disable write access to main (code) flash. */
  vMem_30_Traveo2Cyp01_Reg_WriteBits(VMEM_30_TRAVEO2CYP01_BASE_FLASHC,
      VMEM_30_TRAVEO2CYP01_FLASHC_FM_CTL_ECT_REG_OFFS_MAIN_FLASH_SAFETY,
      VMEM_30_TRAVEO2CYP01_FLASHC_FM_CTL_ECT_REG_MAIN_FLASH_SAFETY,
      VMEM_30_TRAVEO2CYP01_FLASHC_FM_CTL_ECT_REG_MAIN_FLASH_SAFETY_WRITE_DISABLE);

  /* #20 Disable write access to work flash. */
  vMem_30_Traveo2Cyp01_Reg_WriteBits(VMEM_30_TRAVEO2CYP01_BASE_FLASHC,
      VMEM_30_TRAVEO2CYP01_FLASHC_FM_CTL_ECT_REG_OFFS_WORK_FLASH_SAFETY,
      VMEM_30_TRAVEO2CYP01_FLASHC_FM_CTL_ECT_REG_WORK_FLASH_SAFETY,
      VMEM_30_TRAVEO2CYP01_FLASHC_FM_CTL_ECT_REG_WORK_FLASH_SAFETY_WRITE_DISABLE);
} /* vMem_30_Traveo2Cyp01_LLFlashWriteDisable */

/***********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_LLWorkFlashEccEnable()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VMEM_30_TRAVEO2CYP01_LOCAL_INLINE FUNC(void, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_LLWorkFlashEccEnable(void)
{
  /* #10 Enable ECC for work flash. */
  vMem_30_Traveo2Cyp01_Reg_WriteBits(VMEM_30_TRAVEO2CYP01_BASE_FLASHC,
      VMEM_30_TRAVEO2CYP01_FLASHC_REG_OFFS_FLASH_CTL,
      VMEM_30_TRAVEO2CYP01_FLASHC_FLASH_CTL_REG_WORK_FLASH_WORK_ECC_EN,
      VMEM_30_TRAVEO2CYP01_FLASHC_FLASH_CTL_REG_WORK_FLASH_WORK_ECC_EN);
} /* vMem_30_Traveo2Cyp01_LLWorkFlashEccEnable */

/***********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_LLSuppressEccErrors()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VMEM_30_TRAVEO2CYP01_LOCAL_INLINE FUNC(void, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_LLSuppressEccErrors(void)
{
  /* #10 Suppress ECC errors. */
  vMem_30_Traveo2Cyp01_Reg_WriteBits(VMEM_30_TRAVEO2CYP01_BASE_FLASHC,
      VMEM_30_TRAVEO2CYP01_FLASHC_REG_OFFS_FLASH_CTL,
      VMEM_30_TRAVEO2CYP01_FLASHC_FLASH_CTL_REG_WORK_FLASH_WORK_ERR_SILENT,
      VMEM_30_TRAVEO2CYP01_FLASHC_FLASH_CTL_REG_WORK_FLASH_WORK_ERR_SILENT);
} /* vMem_30_Traveo2Cyp01_LLSuppressEccErrors */

/***********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_LLPerformDummyRead()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
VMEM_30_TRAVEO2CYP01_LOCAL_INLINE FUNC(void, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_LLPerformDummyRead(void)
{
  vMem_30_Traveo2Cyp01_FlashTypeType flashType = vMem_30_Traveo2Cyp01_LLGetFlashType(vMem_30_Traveo2Cyp01_CurrentJobInfo.TargetAddress);

  /* #10 Check which type of asynchronous job is currently processed and if the flash type of the targetAddress is work flash. */
  if(((vMem_30_Traveo2Cyp01_CurrentJobInfo.CurrentAsyncJob == VMEM_30_TRAVEO2CYP01_ASYNC_WRITE) ||
      (vMem_30_Traveo2Cyp01_CurrentJobInfo.CurrentAsyncJob == VMEM_30_TRAVEO2CYP01_ASYNC_ERASE))
    &&(flashType == VMEM_30_TRAVEO2CYP01_FLASH_TYPE_WORK))
  {
    /* #20 Perform the dummy read only for write and erase jobs on work flash. */
    uint8 dummyVar = *(vMem_30_Traveo2Cyp01_RegConstVolatilePtrType)vMem_30_Traveo2Cyp01_CurrentJobInfo.TargetAddress;  /* PRQA S 0303, 3205, 4461 */ /* MD_30_Traveo2Cyp01_DummyVar */ /* VCA_VMEM_DUMMYVAR */
  }
} /* vMem_30_Traveo2Cyp01_LLPerformDummyRead */

/***********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_LLGetFlashType()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
VMEM_30_TRAVEO2CYP01_LOCAL_INLINE FUNC(vMem_30_Traveo2Cyp01_FlashTypeType, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_LLGetFlashType(
  vMem_30_Traveo2Cyp01_AddressType TargetAddress)
{
  /* #10 Get sectorIndex from TargetAddress. */
  uint32 sectorIndex = vMem_30_Traveo2Cyp01_GetSectorIndex(VMEM_30_TRAVEO2CYP01_INSTANCE_ID, TargetAddress);

  /* #20 Get FlashType from sectorIndex. */
  return vMem_30_Traveo2Cyp01_GetFlashTypeOfMemSector(sectorIndex);  
} /* vMem_30_Traveo2Cyp01_LLGetFlashType */

/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_LLRead
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_LLRead(
  vMem_30_Traveo2Cyp01_InstanceIdType InstanceId,
  vMem_30_Traveo2Cyp01_AddressType SourceAddress,
  vMem_30_Traveo2Cyp01_DataPtrType TargetAddressPtr,
  vMem_30_Traveo2Cyp01_LengthType Length)
{
  /* ----------- Implementation ------------------------------------------------------------------ */
                                                                                                                        /* PRQA S 0315 2 */ /* MD_MSR_VStdLibCopy */
                                                                                                                        /* PRQA S 0326 1 */ /* MD_vMem_30_Traveo2Cyp01_0326_0306_FlashReadAccess */
  VStdLib_MemCpy(TargetAddressPtr, (vMem_30_Traveo2Cyp01_DataPtrType)SourceAddress, Length);                            /* VCA_VMEM_VALID_TARGETADDRESS */
  vMem_30_Traveo2Cyp01_CurrentJobInfo.JobResult = VMEM_JOB_OK;
  VMEM_30_TRAVEO2CYP01_DUMMY_STATEMENT(InstanceId);                                                                     /* PRQA S 1338, 2983 */ /* MD_MSR_DummyStmt */
  return E_OK;
} /* vMem_30_Traveo2Cyp01_LLRead */

/***********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_LLWrite
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_LLWrite(
  vMem_30_Traveo2Cyp01_InstanceIdType InstanceId,
  vMem_30_Traveo2Cyp01_AddressType TargetAddress,
  vMem_30_Traveo2Cyp01_ConstDataPtrType SourceAddressPtr,
  vMem_30_Traveo2Cyp01_LengthType Length)
{
#if (VMEM_30_TRAVEO2CYP01_READONLY_MODE == STD_OFF) 
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = VMEM_30_TRAVEO2CYP01_E_NO_ERROR;
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
  if (vMem_30_Traveo2Cyp01_LL_DevCheck_IsConditionTrue(vMem_30_Traveo2Cyp01_LLIsSourceAddressPtrNotAligned(SourceAddressPtr)) == TRUE)
  {
    errorId = VMEM_30_TRAVEO2CYP01_E_PARAM_BUFFER_ALIGNMENT;
  }
  else
  {
    /* ----- Implementation ----------------------------------------------- */
    vMem_30_Traveo2Cyp01_CurrentJobInfo.JobState         = VMEM_30_TRAVEO2CYP01_JOB_STATE_SETUP_WRITE;
    vMem_30_Traveo2Cyp01_CurrentJobInfo.JobResult        = VMEM_JOB_PENDING;
    vMem_30_Traveo2Cyp01_CurrentJobInfo.TargetAddress    = TargetAddress;
    vMem_30_Traveo2Cyp01_CurrentJobInfo.SourceAddressPtr = (vMem_30_Traveo2Cyp01_WriteBufferPtrType)SourceAddressPtr;   /* PRQA S 0316 */ /* MD_vMem_30_Traveo2Cyp01_0316_Write */
    vMem_30_Traveo2Cyp01_CurrentJobInfo.Length           = Length;
    vMem_30_Traveo2Cyp01_CurrentJobInfo.CurrentAsyncJob  = VMEM_30_TRAVEO2CYP01_ASYNC_WRITE;
    vMem_30_Traveo2Cyp01_IpcGetLockTimeoutCounter        = 0;

    VMEM_30_TRAVEO2CYP01_DUMMY_STATEMENT(InstanceId);                                                                   /* PRQA S 1338, 2983 */ /* MD_MSR_DummyStmt */
    retVal = E_OK;
  }

  /* ----- Development Error Report --------------------------------------- */
  vMem_30_Traveo2Cyp01_LLReportDevelopmentError(VMEM_30_TRAVEO2CYP01_SID_WRITE, errorId);
  return retVal;

#else /* VMEM_30_TRAVEO2CYP01_READONLY_MODE == STD_ON */
  VMEM_30_TRAVEO2CYP01_DUMMY_STATEMENT(InstanceId);                                                                     /* PRQA S 1338, 2983 */ /* MD_MSR_DummyStmt */
  VMEM_30_TRAVEO2CYP01_DUMMY_STATEMENT(TargetAddress);                                                                  /* PRQA S 1338, 2983 */ /* MD_MSR_DummyStmt */
  VMEM_30_TRAVEO2CYP01_DUMMY_STATEMENT(SourceAddressPtr);                                                               /* PRQA S 1338, 2983 */ /* MD_MSR_DummyStmt */
  VMEM_30_TRAVEO2CYP01_DUMMY_STATEMENT(Length);                                                                         /* PRQA S 1338, 2983 */ /* MD_MSR_DummyStmt */
  return E_NOT_OK;
#endif /* VMEM_30_TRAVEO2CYP01_READONLY_MODE */
} /* vMem_30_Traveo2Cyp01_LLWrite */

/***********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_LLErase
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_LLErase(
  vMem_30_Traveo2Cyp01_InstanceIdType InstanceId,
  vMem_30_Traveo2Cyp01_AddressType TargetAddress,
  vMem_30_Traveo2Cyp01_LengthType Length)
{
#if (VMEM_30_TRAVEO2CYP01_READONLY_MODE == STD_OFF) 
  /* ----------- Implementation ------------------------------------------------------------------ */
  vMem_30_Traveo2Cyp01_CurrentJobInfo.JobState         = VMEM_30_TRAVEO2CYP01_JOB_STATE_SETUP_ERASE;
  vMem_30_Traveo2Cyp01_CurrentJobInfo.JobResult        = VMEM_JOB_PENDING;
  vMem_30_Traveo2Cyp01_CurrentJobInfo.TargetAddress    = TargetAddress;
  vMem_30_Traveo2Cyp01_CurrentJobInfo.SourceAddressPtr = NULL_PTR;
  vMem_30_Traveo2Cyp01_CurrentJobInfo.Length           = Length;
  vMem_30_Traveo2Cyp01_CurrentJobInfo.CurrentAsyncJob  = VMEM_30_TRAVEO2CYP01_ASYNC_ERASE;
  vMem_30_Traveo2Cyp01_IpcGetLockTimeoutCounter        = 0;
  VMEM_30_TRAVEO2CYP01_DUMMY_STATEMENT(InstanceId);                                                                     /* PRQA S 1338, 2983 */ /* MD_MSR_DummyStmt */

  return E_OK;

#else /* VMEM_30_TRAVEO2CYP01_READONLY_MODE == STD_ON */
  VMEM_30_TRAVEO2CYP01_DUMMY_STATEMENT(InstanceId);                                                                     /* PRQA S 1338, 2983 */ /* MD_MSR_DummyStmt */
  VMEM_30_TRAVEO2CYP01_DUMMY_STATEMENT(TargetAddress);                                                                  /* PRQA S 1338, 2983 */ /* MD_MSR_DummyStmt */
  VMEM_30_TRAVEO2CYP01_DUMMY_STATEMENT(Length);                                                                         /* PRQA S 1338, 2983 */ /* MD_MSR_DummyStmt */
  return E_NOT_OK;
#endif /* VMEM_30_TRAVEO2CYP01_READONLY_MODE */
} /* vMem_30_Traveo2Cyp01_LLErase */

/***********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_LLIsBlank
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_LLIsBlank(
  vMem_30_Traveo2Cyp01_InstanceIdType InstanceId,
  vMem_30_Traveo2Cyp01_AddressType TargetAddress,
  vMem_30_Traveo2Cyp01_LengthType Length)
{
  /* ----- Local Variables ---------------------------------------------- */
  vMem_30_Traveo2Cyp01_FlashTypeType flashType = vMem_30_Traveo2Cyp01_LLGetFlashType(TargetAddress);

  /* ----------- Implementation ------------------------------------------------------------------ */
  /* #10 Check for flash type where blank check was requested. For code flash a simple memory compare to
   *     the blank pattern is sufficient. For work flash the request is asynchronous and has to be
   *     forwarded to the FlashMgtLib.  */
  if (flashType == VMEM_30_TRAVEO2CYP01_FLASH_TYPE_CODE)
  {
    if(vMem_30_Traveo2Cyp01_LLIsCodeFlashBlank(TargetAddress, Length) == TRUE)
    {
      vMem_30_Traveo2Cyp01_CurrentJobInfo.JobResult = VMEM_JOB_OK;
    }
    else
    {
      vMem_30_Traveo2Cyp01_CurrentJobInfo.JobResult = VMEM_MEM_NOT_BLANK;
    }
  }
  else /* flashType == VMEM_30_TRAVEO2CYP01_FLASH_TYPE_WORK */
  {
    /* #20 Save all blank check parameter to reserved job structure and clear timeout counter. */
    vMem_30_Traveo2Cyp01_CurrentJobInfo.JobState         = VMEM_30_TRAVEO2CYP01_JOB_STATE_SETUP_BLANK;
    vMem_30_Traveo2Cyp01_CurrentJobInfo.JobResult        = VMEM_JOB_PENDING;
    vMem_30_Traveo2Cyp01_CurrentJobInfo.TargetAddress    = TargetAddress;
    vMem_30_Traveo2Cyp01_CurrentJobInfo.SourceAddressPtr = NULL_PTR;
    vMem_30_Traveo2Cyp01_CurrentJobInfo.Length           = Length;
    vMem_30_Traveo2Cyp01_CurrentJobInfo.CurrentAsyncJob  = VMEM_30_TRAVEO2CYP01_ASYNC_ISBLANK;
    vMem_30_Traveo2Cyp01_IpcGetLockTimeoutCounter        = 0;
  }

  VMEM_30_TRAVEO2CYP01_DUMMY_STATEMENT(InstanceId);                                                                     /* PRQA S 1338, 2983 */ /* MD_MSR_DummyStmt */

  return E_OK;
}

/***********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_SetDualBankMode
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_SetDualBankMode(
    vMem_30_Traveo2Cyp01_InstanceIdType InstanceId,
    vMem_30_Traveo2Cyp01_DataPtrType ReqSpecificData, /* PRQA S 3673 */ /* MD_vMem_30_Traveo2Cyp01_3673_NotModified */
    vMem_30_Traveo2Cyp01_LengthType SizeOfData)
{
#if (VMEM_30_TRAVEO2CYP01_READONLY_MODE == STD_OFF) 
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = VMEM_30_TRAVEO2CYP01_E_NO_ERROR;
  Std_ReturnType retVal = E_NOT_OK;                                                                                     /* PRQA S 2981 */ /* MD_MSR_RetVal */
  vMem_30_Traveo2Cyp01_CurrentJobInfo.JobResult = VMEM_JOB_FAILED;

  /* ----- Development Error Checks ------------------------------------- */
  if (vMem_30_Traveo2Cyp01_LL_DevCheck_IsConditionTrue(vMem_30_Traveo2Cyp01_LLIsNullPointer(ReqSpecificData)) == TRUE)
  {
    errorId = VMEM_30_TRAVEO2CYP01_E_PARAM_POINTER;
  }
  else
  {
    /* ----------- Implementation ------------------------------------------------------------------ */
    uint8 bitOffset = vMem_30_Traveo2Cyp01_LLGetBitOffsetFromMemType(*((vMem_30_Traveo2Cyp01_FlashTypeType*)ReqSpecificData)); /* PRQA S 0316 */ /* MD_vMem_30_Traveo2Cyp01_0316_FlashType */

    /* #10 Set dual bank mode active for the requested bank. */
    vMem_30_Traveo2Cyp01_Reg_WriteBits(VMEM_30_TRAVEO2CYP01_BASE_FLASHC,
        VMEM_30_TRAVEO2CYP01_FLASHC_REG_OFFS_FLASH_CTL,
        VMEM_30_TRAVEO2CYP01_FLASHC_FLASH_CTL_REG_MAIN_BANK_MODE << bitOffset,
        VMEM_30_TRAVEO2CYP01_FLASHC_FLASH_CTL_REG_MAIN_BANK_MODE_DUAL << bitOffset);
    
    retVal = E_OK;
    vMem_30_Traveo2Cyp01_CurrentJobInfo.JobResult = VMEM_JOB_OK;
  }
  /* ----- Development Error Report --------------------------------------- */
  vMem_30_Traveo2Cyp01_LLReportDevelopmentError(VMEM_30_TRAVEO2CYP01_SID_SETDUALBANKMODE, errorId);

  /* The signature of the extended hardware specific functionality is defined by the vMemAccM. For this service the 
     parameter InstanceId and SizeOfData are not needed. */
  VMEM_30_TRAVEO2CYP01_DUMMY_STATEMENT(InstanceId);                                                                     /* PRQA S 1338, 2983 */ /* MD_MSR_DummyStmt */
  VMEM_30_TRAVEO2CYP01_DUMMY_STATEMENT(SizeOfData);                                                                     /* PRQA S 1338, 2983 */ /* MD_MSR_DummyStmt */
  return retVal;

#else /* VMEM_30_TRAVEO2CYP01_READONLY_MODE == STD_ON */
  VMEM_30_TRAVEO2CYP01_DUMMY_STATEMENT(InstanceId);                                                                     /* PRQA S 1338, 2983 */ /* MD_MSR_DummyStmt */
  VMEM_30_TRAVEO2CYP01_DUMMY_STATEMENT(ReqSpecificData);                                                                /* PRQA S 1338, 2983 */ /* MD_MSR_DummyStmt */
  VMEM_30_TRAVEO2CYP01_DUMMY_STATEMENT(SizeOfData);                                                                     /* PRQA S 1338, 2983 */ /* MD_MSR_DummyStmt */
  return E_NOT_OK;
#endif /* VMEM_30_TRAVEO2CYP01_READONLY_MODE */
} /* vMem_30_Traveo2Cyp01_SetDualBankMode */

/***********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_PerformMemorySwap
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_PerformMemorySwap(
    vMem_30_Traveo2Cyp01_InstanceIdType InstanceId,
    vMem_30_Traveo2Cyp01_DataPtrType ReqSpecificData,                                                                   /* PRQA S 3673 */ /* MD_vMem_30_Traveo2Cyp01_3673_NotModified */
    vMem_30_Traveo2Cyp01_LengthType SizeOfData)
{
#if (VMEM_30_TRAVEO2CYP01_READONLY_MODE == STD_OFF) 
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = VMEM_30_TRAVEO2CYP01_E_NO_ERROR;
  Std_ReturnType retVal = E_NOT_OK;                                                                                     /* PRQA S 2981 */ /* MD_MSR_RetVal */
  vMem_30_Traveo2Cyp01_CurrentJobInfo.JobResult = VMEM_JOB_FAILED;

  /* ----- Development Error Checks ------------------------------------- */
  if (vMem_30_Traveo2Cyp01_LL_DevCheck_IsConditionTrue(vMem_30_Traveo2Cyp01_LLIsNullPointer(ReqSpecificData)) == TRUE)
  {
    errorId = VMEM_30_TRAVEO2CYP01_E_PARAM_POINTER;
  }
  else
  {
    /* ----------- Implementation ------------------------------------------------------------------ */
    uint8 bitOffset = vMem_30_Traveo2Cyp01_LLGetBitOffsetFromMemType(*((vMem_30_Traveo2Cyp01_FlashTypeType*)ReqSpecificData)); /* PRQA S 0316 */ /* MD_vMem_30_Traveo2Cyp01_0316_FlashType */
    
    /* #10 Retrieve the current bank mode of the requested bank. */
    if(vMem_30_Traveo2Cyp01_Reg_ReadBits(VMEM_30_TRAVEO2CYP01_BASE_FLASHC,
        VMEM_30_TRAVEO2CYP01_FLASHC_REG_OFFS_FLASH_CTL,
        VMEM_30_TRAVEO2CYP01_FLASHC_FLASH_CTL_REG_MAIN_BANK_MODE << bitOffset) 
        == (VMEM_30_TRAVEO2CYP01_FLASHC_FLASH_CTL_REG_MAIN_BANK_MODE_DUAL << bitOffset))
    {
      /* #20 If dual bank mode is active retrieve the current mapping. */
      vMem_30_Traveo2Cyp01_RegWidthType currentMapping = vMem_30_Traveo2Cyp01_Reg_ReadBits(VMEM_30_TRAVEO2CYP01_BASE_FLASHC,
          VMEM_30_TRAVEO2CYP01_FLASHC_REG_OFFS_FLASH_CTL,
          VMEM_30_TRAVEO2CYP01_FLASHC_FLASH_CTL_REG_MAIN_MAP << bitOffset);

      /* #30 Swap the current mapping. */
      vMem_30_Traveo2Cyp01_Reg_WriteBits(VMEM_30_TRAVEO2CYP01_BASE_FLASHC,
          VMEM_30_TRAVEO2CYP01_FLASHC_REG_OFFS_FLASH_CTL,
          VMEM_30_TRAVEO2CYP01_FLASHC_FLASH_CTL_REG_MAIN_MAP << bitOffset,
          (~currentMapping) & (VMEM_30_TRAVEO2CYP01_FLASHC_FLASH_CTL_REG_MAIN_MAP << bitOffset));

      retVal = E_OK;
      vMem_30_Traveo2Cyp01_CurrentJobInfo.JobResult = VMEM_JOB_OK;
    }
  }
  /* ----- Development Error Report --------------------------------------- */
  vMem_30_Traveo2Cyp01_LLReportDevelopmentError(VMEM_30_TRAVEO2CYP01_SID_PERFORMMEMORYSWAP, errorId);

  /* The signature of the extended hardware specific functionality is defined by the vMemAccM. For this service the parameter InstanceId and
   * SizeOfData are not needed. */
  VMEM_30_TRAVEO2CYP01_DUMMY_STATEMENT(InstanceId);                                                                     /* PRQA S 1338, 2983 */ /* MD_MSR_DummyStmt */
  VMEM_30_TRAVEO2CYP01_DUMMY_STATEMENT(SizeOfData);                                                                     /* PRQA S 1338, 2983 */ /* MD_MSR_DummyStmt */
  return retVal;

#else /* VMEM_30_TRAVEO2CYP01_READONLY_MODE == STD_ON */
  VMEM_30_TRAVEO2CYP01_DUMMY_STATEMENT(InstanceId);                                                                     /* PRQA S 1338, 2983 */ /* MD_MSR_DummyStmt */
  VMEM_30_TRAVEO2CYP01_DUMMY_STATEMENT(ReqSpecificData);                                                                /* PRQA S 1338, 2983 */ /* MD_MSR_DummyStmt */
  VMEM_30_TRAVEO2CYP01_DUMMY_STATEMENT(SizeOfData);                                                                     /* PRQA S 1338, 2983 */ /* MD_MSR_DummyStmt */
  return E_NOT_OK;
#endif /* VMEM_30_TRAVEO2CYP01_READONLY_MODE */
} /* vMem_30_Traveo2Cyp01_PerformMemorySwap */

/***********************************************************************************************************************
 * vMem_30_Traveo2Cyp01_LLGetJobResult
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(vMem_30_Traveo2Cyp01_JobResultType, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_LLGetJobResult(
    vMem_30_Traveo2Cyp01_InstanceIdType InstanceId)
{
  /* ----------- Implementation ------------------------------------------------------------------ */
  VMEM_30_TRAVEO2CYP01_DUMMY_STATEMENT(InstanceId);                                                                     /* PRQA S 1338, 2983 */ /* MD_MSR_DummyStmt */
  return vMem_30_Traveo2Cyp01_CurrentJobInfo.JobResult;
} /* vMem_30_Traveo2Cyp01_LLGetJobResult */

/***********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_LLProcessing
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_LLProcessing(void)
{
  /* ----------- Implementation ------------------------------------------------------------------ */
  /* #10 Check if write, erase or blank check job request was setup. */
  if (vMem_30_Traveo2Cyp01_LLIsJobSetup() == TRUE)
  {
    /* #20 Call state handler for setting up the requested job. */
    vMem_30_Traveo2Cyp01_LLProcStateSetup();
  }

  /* #30 Call state handler for wait for FlashMgtLib. */
  if (vMem_30_Traveo2Cyp01_CurrentJobInfo.JobState == VMEM_30_TRAVEO2CYP01_JOB_STATE_WAIT_FOR_FLASHMGTLIB)
  {
    vMem_30_Traveo2Cyp01_LLProcStateWaitForFlashMgtLib();
  }

  /* #40 Call state handler for wait for Flash. */
  if (vMem_30_Traveo2Cyp01_CurrentJobInfo.JobState == VMEM_30_TRAVEO2CYP01_JOB_STATE_WAIT_FOR_FLASH)
  {
    vMem_30_Traveo2Cyp01_LLProcStateWaitForFlash();
  }
} /* vMem_30_Traveo2Cyp01_LLProcessing */

/***********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_LLInit
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_LLInit(void)
{
  /* ----------- Implementation ------------------------------------------------------------------ */
  /* #10 Initialize all job parameters and timeout counter. */
  vMem_30_Traveo2Cyp01_CurrentJobInfo.JobState         = VMEM_30_TRAVEO2CYP01_JOB_STATE_IDLE;
  vMem_30_Traveo2Cyp01_CurrentJobInfo.JobResult        = VMEM_JOB_OK;
  vMem_30_Traveo2Cyp01_CurrentJobInfo.TargetAddress    = 0;
  vMem_30_Traveo2Cyp01_CurrentJobInfo.SourceAddressPtr = NULL_PTR;
  vMem_30_Traveo2Cyp01_CurrentJobInfo.Length           = 0;
  vMem_30_Traveo2Cyp01_CurrentJobInfo.CurrentAsyncJob  = VMEM_30_TRAVEO2CYP01_ASYNC_NONE;
  vMem_30_Traveo2Cyp01_IpcGetLockTimeoutCounter        = 0;

  /* #20 Disable write access to Flash.  */
  vMem_30_Traveo2Cyp01_LLFlashWriteDisable();

  /* #30 Enable ECC for work Flash. */
  vMem_30_Traveo2Cyp01_LLWorkFlashEccEnable();

  if(vMem_30_Traveo2Cyp01_IsSuppressEccErrorsEnabled())                                                                 /* PRQA S 2741, 2742 */ /* MD_vMem_30_Traveo2Cyp01_ConstValue */
  {
    /* #40 Suppress ECC errors. */
    vMem_30_Traveo2Cyp01_LLSuppressEccErrors();                                                                         /* PRQA S 2880 */ /* MD_MSR_Unreachable */
  }

  /* #50 Initialize underlying modules. */
  vMem_30_Traveo2Cyp01_FlashMgtLib_Init();
  vMem_30_Traveo2Cyp01_Ipc_Init();

  return E_OK;
} /* vMem_30_Traveo2Cyp01_LLInit */

#define VMEM_30_TRAVEO2CYP01_STOP_SEC_CODE
#include "MemMap.h"                                                                                                     /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Module specific MISRA deviations: 

MD_CRC_2.1_StaticFunctionNotUsed:
    Reason: This inline functions are defined as a utility functionality and shall be accessible by each translation
            unit of the component. In some cases this functionality might not be used. This is not a problem as the
            compiler will optimize this code away in this case.
    Risk: No risk.
    Prevention: A compile switch could be introduced.

MD_vMem_30_Traveo2Cyp01_3219: 
    Reason:     This function is inlined and therefore it has to be implemented here. The function is not used by all 
                implementation files which include this header file. 
    Risk:       None. 
    Prevention: None.

MD_vMem_30_Traveo2Cyp01_0306_RegisterAccess: 
    Reason:     vMem directly reads from registers via memory mapped read. The conversion between pointer and an 
                integral type is required to access the register address which is defined as 
                vMem_30_Traveo2Cyp01_RegWidthType. 
    Risk:       If the object referenced by vMem_30_Traveo2Cyp01_RegVarPtrType is of wrong type, the behavior is 
                undefined.
    Prevention: Component tests ensures that the vMem accesses the referenced object correctly.

MD_vMem_30_Traveo2Cyp01_0303_RegisterVolatileAccess:
    Reason:     Hardware register accesses need a cast from integral type to a pointer to volatile object.
    Risk:       There is no risk as the register is mapped to the respective memory address.
    Prevention: Covered by code review.

MD_vMem_30_Traveo2Cyp01_0306_SystemCallArguments: 
    Reason:     The flash management library needs the address of the parameter structure. Therefore it has to be passed 
                into the Data0 register. The cast is needed to get the address of the pointer to the parameter 
                structure. The address is then used as data for the Data0 register with 
                vMem_30_Traveo2Cyp01_RegWidthType.
    Risk:       No risk. 
    Prevention: No prevention.

MD_vMem_30_Traveo2Cyp01_0306_SourceAddress: 
    Reason:     The flash management library needs the address of the source data buffer. Therefore it has to be passed 
                into the SystemCallArguments. The cast is needed to get the address of the data buffer which inherits 
                the data which should be written to the flash. The address is defined as 
                vMem_30_Traveo2Cyp01_AddressType. 
    Risk:       No risk. 
    Prevention: No prevention.

MD_vMem_30_Traveo2Cyp01_0326_0306_FlashReadAccess: 
    Reason:     vMem directly reads from flash via memory mapped read. The conversion between pointer and an integral 
                type is required to access the FLASH address/target address which is defined as 
                vMem_30_Traveo2Cyp01_AddressType. 
    Risk:       If the object referenced by TargetAddressPtr is of wrong type, the behavior is undefined. 
    Prevention: Component tests ensures that the vMem accesses the referenced object correctly. User must ensure that 
                TargetAddressPtr is valid.

MD_vMem_30_Traveo2Cyp01_0326_SourceAddress: 
    Reason:     vMem_30_Traveo2Cyp01_LLWrite performs write operation with given SourceAddressPtr. SourceAddressPtr 
                needs to be aligned in the memory for the operation to run successfully. Check is performed by 
                extracting few last bits of the SourceAddressPtr and checking that they are 0. To be able to perform 
                this kind of check, the SourceAddressPtr needs to be casted to integral type. 
    Risk:       No risk. 
    Prevention: Component tests ensures that the SourceAddressPtr is properly aligned.

MD_vMem_30_Traveo2Cyp01_0316_Write: 
    Reason:     vMem accepts untyped void pointers in its low level functionality, to provide a compatible interface for 
                different hardware specific function implementations: one may get a structure of type A, the other of 
                type B etc. With a void pointer interface the signature of all the functions keeps the same and can be 
                used in one typed function pointer array. In the low level write functionality, the vMem performs a cast 
                of the void pointer to a pointer to uint8, so it can write the currently active address region to the 
                referenced object. The user of this functionality has to make sure, that the referenced object is of 
                type uint8. Therefore, the buffer is cast to a pointer of type vMem_30_Traveo2Cyp01_WriteBufferPtrType. 
    Risk:       No risk. 
    Prevention: Component tests ensures that the vMem accesses the referenced object correctly.

MD_vMem_30_Traveo2Cyp01_0316_FlashType: 
    Reason:     vMem accepts untyped void pointers in its low level functionality, to provide a compatible interface for 
                different hardware specific function implementations: one may get a structure of type A, the other of 
                type B etc. With a void pointer interface, the signature of all the functions keeps the same and can be 
                used in one typed function pointer array. In the low level extended functionality, the vMem performs a 
                cast of the void pointer to a pointer to vMem_30_Traveo2Cyp01_FlashTypeType, so it can differentiate 
                between code and work flash. The user of this functionality has to make sure, that the referenced object 
                is of type vMem_30_Traveo2Cyp01_FlashTypeType. 
    Risk:       No risk. 
    Prevention: Component tests ensures that the vMem accesses the referenced object correctly.

MD_vMem_30_Traveo2Cyp01_3673_NotModified: 
    Reason:     This parameter is used only as input in this vMem extended function, thus it is not modified. However, 
                since this parameter is predefined by the vMemAccM it is unavoidable to keep it as "pointer to 
                non-const". 
    Risk:       None. 
    Prevention: None.

MD_vMem_30_Traveo2Cyp01_ConstValue: PRQA message 2741, 2742 
    Reason:     Value is constant depending on configuration aspects. This leads to constant control expressions and 
                unreachable code. 
    Risk:       Wrong or missing functionality. 
    Prevention: Code inspection and test of the different variants in the component test.

MD_vMem_30_Traveo2Cyp01_3206_ApiId: PRQA message 3206
    Reason:     This parameter is needed if Det Error Reporting is enabled by configuration. When Det Error Reporting is
                disabled, the Det module is not included and the vMem_30_Traveo2Cyp01_CallDetErrorReporting function is
                doing nothing. Therefor the parameter is not used in this case. 
    Risk:       None.
    Prevention: None.

MD_vMem_30_Traveo2Cyp01_3315_RedundantSwitch: PRQA message 3315
    Reason:     In the fully operable vMem mode variant, this switch consists of three possible cases. In the read only 
                mode variant only one case is needed. 
    Risk:       None.
    Prevention: None.

MD_vMem_30_Traveo2Cyp01_2987_DummyRead
    Reason:     In nonblocking mode, a dummy read is required to make the logical bank of work flash ready for read 
                operation after a program or erase operation.
    Risk:       None.
    Prevention: None.

MD_30_Traveo2Cyp01_DummyVar:
    Reason:     In nonblocking mode, a dummy read is required to make the logical bank of work flash ready for read 
                operation after a program or erase operation. For this we use this dummyVar variable which is not used 
                further.
    Risk:       None.
    Prevention: None.
    
*/

/* START_COVERAGE_JUSTIFICATION

Variant coverage:

\ID COV_VMEM_30_TRAVEO2CYP01_COMPATIBILITY
 \ACCEPT TX
 \REASON COV_MSR_COMPATIBILITY

\ID COV_VMEM_30_TRAVEO2CYP01_NOUNIT
 \ACCEPT TX
 \REASON This directive is needed because this logical unit contains only inline functions which are fully implemented 
         in the header. To make it possible to mock this unit when testing other units, this directive disables the 
         actual implementation.

END_COVERAGE_JUSTIFICATION */

/* VCA_JUSTIFICATION_BEGIN

\ID VCA_VMEM_REGACCESS
  \DESCRIPTION Access of hardware registers depending on the configuration parameter 'VMEM_USE_PERIPHERAL_ACCESS_API':
               - VMEM_USE_PERIPHERAL_ACCESS_API == STD_OFF: Direct register access via pointer dereferencing.
               - VMEM_USE_PERIPHERAL_ACCESS_API == STD_ON: Indirect register access via OS-provided APIs.
               The access address results from a hardware-unit-specific base address and a register-specific offset.
               The base-address is determined from generated configuration structure using parameter 'hwUnitId', whose
               correctness is ensured by the caller.
               The register-specific offset is in some cases also dependend from generated configurations. E.g. from the
               VMEM_30_TRAVEO2CYP01_IPC_STRUCT_ID, VMEM_30_TRAVEO2CYP01_MASTER_IPC_INTR_ID and
               VMEM_30_TRAVEO2CYP01_SLAVE_IPC_INTR_ID. Its correctness must be ensured by the caller as well.
  \COUNTERMEASURE \S Verify that generated addresses and IDs are correct.
                       SMI-PeripheralBaseAddresses, SMI-InterprocessorCommunication

\ID VCA_VMEM_VALID_TARGETADDRESS
  \DESCRIPTION TargetAddressPtr gets forwarded to the function VStdLib_MemCpy or is used directly for memory mapped 
               reading.
  \COUNTERMEASURE \R The function caller has to ensure, that the 'Length' and 'TargetAddressPtr' are valid. DET check 
                     ensures, that the 'Length' and 'TargetAddressPtr' pointers are valid.

\ID VCA_VMEM_DUMMYVAR
  \DESCRIPTION In nonblocking mode, a dummy read is required to make the logical bank of work flash ready for read 
               operation after a program or erase operation. The dummy read is done from the TargetAddress which was 
               used for the erase or write operation. This read has no further impact.
  \COUNTERMEASURE \R The function caller has to ensure, that the 'TargetAddress' is valid.
  
VCA_JUSTIFICATION_END */

/**********************************************************************************************************************
 *  END OF FILE: vMem_30_Traveo2Cyp01_LL.c
 *********************************************************************************************************************/

