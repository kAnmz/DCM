/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2025 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!        \file  vMem_30_Traveo2Cyp01_LL_FlashMgtLib.c
 *        \brief  Flash Management Library header file of the vMem driver.
 *
 *      \details  Flash operations are implemented as system calls. System calls are executed out of SROM in the
 *                privileged mode of operation. Users have no access to read or modify the SROM code.
 *                The driver API requests the system call by acquiring the Inter-processor communication (IPC)
 *                and writing the SROM function opcode and parameters to its input registers. This Library
 *                implements the needed SystemCalls for all supported Flash operations by the vMem.
 *         \unit  vMem_LL_FlashMgtLib
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#define VMEM_30_TRAVEO2CYP01_LL_FLASHMGTLIB_SOURCE

/*lint -e537 */ /* Suppress ID537 due to MD_MSR_19.1 */
/*lint -e451 */ /* Suppress ID451 because MemMap.h cannot use a include guard */

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "vMem_30_Traveo2Cyp01_LL_FlashMgtLib.h"

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
/* Operation Code of the Flash management APIs */
#define VMEM_30_TRAVEO2CYP01_FLASHMGTLIB_OPCODE_BLANK_CHECK                         (0x2Au)
#define VMEM_30_TRAVEO2CYP01_FLASHMGTLIB_OPCODE_CHECK_FM_STATUS                     (0x07u)
#define VMEM_30_TRAVEO2CYP01_FLASHMGTLIB_OPCODE_CHECKSUM                            (0x0Bu)
#define VMEM_30_TRAVEO2CYP01_FLASHMGTLIB_OPCODE_COMPUTE_BASIC_HASH                  (0x0Du)
#define VMEM_30_TRAVEO2CYP01_FLASHMGTLIB_OPCODE_CONFIGURE_FM_INTERRUPT              (0x08u)
#define VMEM_30_TRAVEO2CYP01_FLASHMGTLIB_OPCODE_ENTER_FLASH_MARGIN_MODE             (0x20u)
#define VMEM_30_TRAVEO2CYP01_FLASHMGTLIB_OPCODE_ERASE_ALL                           (0x0Au)
#define VMEM_30_TRAVEO2CYP01_FLASHMGTLIB_OPCODE_ERASE_RESUME                        (0x23u)
#define VMEM_30_TRAVEO2CYP01_FLASHMGTLIB_OPCODE_ERASE_SECTOR                        (0x14u)
#define VMEM_30_TRAVEO2CYP01_FLASHMGTLIB_OPCODE_ERASE_SUSPEND                       (0x22u)
#define VMEM_30_TRAVEO2CYP01_FLASHMGTLIB_OPCODE_EXIT_FLASH_MARGIN_MODE              (0x21u)
#define VMEM_30_TRAVEO2CYP01_FLASHMGTLIB_OPCODE_INJECT_PUBLIC_KEY                   (0x26u)
#define VMEM_30_TRAVEO2CYP01_FLASHMGTLIB_OPCODE_PROGRAM_ROW                         (0x06u)
#define VMEM_30_TRAVEO2CYP01_FLASHMGTLIB_OPCODE_READ_UNIQUE_ID                      (0x1Fu)
#define VMEM_30_TRAVEO2CYP01_FLASHMGTLIB_OPCODE_WRITE_ROW                           (0x05u)

#define VMEM_30_TRAVEO2CYP01_FLASHMGTLIB_OPCODE_OFFSET                              (24u)
#define VMEM_30_TRAVEO2CYP01_FLASHMGTLIB_DATA_LOCATION_SRAM                         (1u)
#define VMEM_30_TRAVEO2CYP01_FLASHMGTLIB_DATA_LOCATION_OFFSET                       (8u)

/* System Call argument code flash write sizes */
#define VMEM_30_TRAVEO2CYP01_FLASHMGTLIB_SYSCALL_ARG_CF_WRITE_SIZE_8_BYTE           (3u)
#define VMEM_30_TRAVEO2CYP01_FLASHMGTLIB_SYSCALL_ARG_CF_WRITE_SIZE_32_BYTE          (5u)
#define VMEM_30_TRAVEO2CYP01_FLASHMGTLIB_SYSCALL_ARG_CF_WRITE_SIZE_512_BYTE         (9u)

#define VMEM_30_TRAVEO2CYP01_FLASHMGTLIB_SYSCALL_STATUS_ERROR_CODE_NOT_BLANK        (0xA4u)

#define VMEM_30_TRAVEO2CYP01_FLASHMGTLIB_SYSCALL_STATUS_OFFSET                      (28u)
#define VMEM_30_TRAVEO2CYP01_FLASHMGTLIB_SYSCALL_STATUS_OK_VALUE                    (0xAu)
#define VMEM_30_TRAVEO2CYP01_FLASHMGTLIB_SYSCALL_STATUS_ERROR_VALUE                 (0xFu)
#define VMEM_30_TRAVEO2CYP01_FLASHMGTLIB_SYSCALL_STATUS_ERROR_CODE_MASK             (0xFFu)

#define VMEM_30_TRAVEO2CYP01_FLASHMGTLIB_SYSCALL_STATUS_INIT_VALUE                  (0xA0000000uL)

/* Supported write sizes for the code flash */
#define VMEM_30_TRAVEO2CYP01_CF_WRITE_SIZE_8_BYTE                                   (8u)
#define VMEM_30_TRAVEO2CYP01_CF_WRITE_SIZE_32_BYTE                                  (32u)
#define VMEM_30_TRAVEO2CYP01_CF_WRITE_SIZE_512_BYTE                                 (512u)

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/
#define vMem_30_Traveo2Cyp01_FlashMgtLib_GetSystemCallStatusCode()  (vMem_30_Traveo2Cyp01_SysCallArguments[0]) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#define vMem_30_Traveo2Cyp01_FlashMgtLib_SetSystemCallStatusCode(n) (vMem_30_Traveo2Cyp01_SysCallArguments[0] = (n)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#define vMem_30_Traveo2Cyp01_FlashMgtLib_GetSystemCallErrorCode()   (vMem_30_Traveo2Cyp01_SysCallArguments[0] & VMEM_30_TRAVEO2CYP01_FLASHMGTLIB_SYSCALL_STATUS_ERROR_CODE_MASK) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
#if !defined (VMEM_30_TRAVEO2CYP01_FLASHMGTLIB_LOCAL) /* COV_VMEM_30_TRAVEO2CYP01_COMPATIBILITY */
# define VMEM_30_TRAVEO2CYP01_FLASHMGTLIB_LOCAL static
#endif

#if !defined (VMEM_30_TRAVEO2CYP01_FLASHMGTLIB_LOCAL_INLINE) /* COV_VMEM_30_TRAVEO2CYP01_COMPATIBILITY */
# define VMEM_30_TRAVEO2CYP01_FLASHMGTLIB_LOCAL_INLINE LOCAL_INLINE
#endif

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

/*! Data type for the status of the system call */
typedef enum
{
  VMEM_30_TRAVEO2CYP01_FLASHMGTLIB_SYSCALL_STATUS_OK,
  VMEM_30_TRAVEO2CYP01_FLASHMGTLIB_SYSCALL_STATUS_ERROR
} vMem_30_Traveo2Cyp01_FlashMgtLib_SystemCallStatusType;

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
#define VMEM_30_TRAVEO2CYP01_START_SEC_VAR_NOINIT_32BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Stores the IPC arguments for the system call. */
VMEM_30_TRAVEO2CYP01_FLASHMGTLIB_LOCAL VAR(vMem_30_Traveo2Cyp01_FlashMgtLib_SystemCallArgumentsType, VMEM_30_TRAVEO2CYP01_VAR_NOINIT)
  vMem_30_Traveo2Cyp01_SysCallArguments[VMEM_30_TRAVEO2CYP01_FLASHMGTLIB_SYSCALL_NUM_OF_ARGUMENTS];

#define VMEM_30_TRAVEO2CYP01_STOP_SEC_VAR_NOINIT_32BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define VMEM_30_TRAVEO2CYP01_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_FlashMgtLib_GetSystemCallStatus()
 *********************************************************************************************************************/
/*! \brief       Returns the status of the current system call.
 *  \details     -
 *  \return      Current result of the system call.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
VMEM_30_TRAVEO2CYP01_FLASHMGTLIB_LOCAL_INLINE FUNC(vMem_30_Traveo2Cyp01_FlashMgtLib_SystemCallStatusType, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_FlashMgtLib_GetSystemCallStatus(void);

/**********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_FlashMgtLib_IsSystemCallPending()
 *********************************************************************************************************************/
/*! \brief       Checks if the current system call is still pending.
 *  \details     -
 *  \return      TRUE - Current system call is pending.
 *               FALSE - Current system call is completed.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
VMEM_30_TRAVEO2CYP01_FLASHMGTLIB_LOCAL_INLINE FUNC(boolean, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_FlashMgtLib_IsSystemCallPending(void);

/**********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_FlashMgtLib_AnalyzeSystemCallErrorCode()
 *********************************************************************************************************************/
/*! \brief       Analyzes the system call error code and returns the result.
 *  \details     -
 *  \return      Result of the last system call.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
VMEM_30_TRAVEO2CYP01_FLASHMGTLIB_LOCAL_INLINE FUNC(vMem_30_Traveo2Cyp01_FlashMgtLib_ResultType, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_FlashMgtLib_AnalyzeSystemCallErrorCode(void);

#if (VMEM_30_TRAVEO2CYP01_READONLY_MODE == STD_OFF)
/**********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_FlashMgtLib_MapLengthToSysCallSizeArg()
 *********************************************************************************************************************/
/*! \brief       Maps write length to system call data size argument for code flash.
 *  \details     -
 *  \param[in]   Length          write length size.
 *  \return      System Call data size argument for code flash.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
VMEM_30_TRAVEO2CYP01_FLASHMGTLIB_LOCAL_INLINE FUNC(vMem_30_Traveo2Cyp01_FlashMgtLib_SystemCallArgumentsType, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_FlashMgtLib_MapLengthToSysCallSizeArg(
    vMem_30_Traveo2Cyp01_LengthType Length);
#endif /* VMEM_30_TRAVEO2CYP01_READONLY_MODE */

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_FlashMgtLib_IsSystemCallPending()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
VMEM_30_TRAVEO2CYP01_FLASHMGTLIB_LOCAL_INLINE FUNC(boolean, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_FlashMgtLib_IsSystemCallPending(void)
{
  return (vMem_30_Traveo2Cyp01_Ipc_IsReleased() == FALSE) ? TRUE : FALSE;
}

/**********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_FlashMgtLib_GetSystemCallStatus()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VMEM_30_TRAVEO2CYP01_FLASHMGTLIB_LOCAL_INLINE FUNC(vMem_30_Traveo2Cyp01_FlashMgtLib_SystemCallStatusType, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_FlashMgtLib_GetSystemCallStatus(void)
{
  /* ----------- Local variables ----------------------------------------------------------------- */
  vMem_30_Traveo2Cyp01_FlashMgtLib_SystemCallArgumentsType SystemCallStatusValue;

  /* ----------- Implementation ------------------------------------------------------------------ */
  SystemCallStatusValue = vMem_30_Traveo2Cyp01_FlashMgtLib_GetSystemCallStatusCode() >> VMEM_30_TRAVEO2CYP01_FLASHMGTLIB_SYSCALL_STATUS_OFFSET;

  return (SystemCallStatusValue == VMEM_30_TRAVEO2CYP01_FLASHMGTLIB_SYSCALL_STATUS_OK_VALUE) ?
      VMEM_30_TRAVEO2CYP01_FLASHMGTLIB_SYSCALL_STATUS_OK : VMEM_30_TRAVEO2CYP01_FLASHMGTLIB_SYSCALL_STATUS_ERROR;
}

/**********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_FlashMgtLib_AnalyzeSystemCallErrorCode()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VMEM_30_TRAVEO2CYP01_FLASHMGTLIB_LOCAL_INLINE FUNC(vMem_30_Traveo2Cyp01_FlashMgtLib_ResultType, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_FlashMgtLib_AnalyzeSystemCallErrorCode(void)
{
  /* ----------- Local variables ----------------------------------------------------------------- */
  vMem_30_Traveo2Cyp01_FlashMgtLib_SystemCallArgumentsType systemCallErrorCode =
      vMem_30_Traveo2Cyp01_FlashMgtLib_GetSystemCallErrorCode();
  vMem_30_Traveo2Cyp01_FlashMgtLib_ResultType result;

  /* ----------- Implementation ------------------------------------------------------------------ */
  if(systemCallErrorCode == VMEM_30_TRAVEO2CYP01_FLASHMGTLIB_SYSCALL_STATUS_ERROR_CODE_NOT_BLANK)
  {
    result = VMEM_30_TRAVEO2CYP01_RESULT_MEM_NOT_BLANK;
  }
  else
  {
    result = VMEM_30_TRAVEO2CYP01_RESULT_FAILED;
  }

  return result;
}

#if (VMEM_30_TRAVEO2CYP01_READONLY_MODE == STD_OFF)
/**********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_FlashMgtLib_MapLengthToSysCallSizeArg()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VMEM_30_TRAVEO2CYP01_FLASHMGTLIB_LOCAL_INLINE FUNC(vMem_30_Traveo2Cyp01_FlashMgtLib_SystemCallArgumentsType, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_FlashMgtLib_MapLengthToSysCallSizeArg(
    vMem_30_Traveo2Cyp01_LengthType Length)
{
  vMem_30_Traveo2Cyp01_FlashMgtLib_SystemCallArgumentsType dataSize;

  switch(Length)
  {
    case VMEM_30_TRAVEO2CYP01_CF_WRITE_SIZE_8_BYTE:
      dataSize = VMEM_30_TRAVEO2CYP01_FLASHMGTLIB_SYSCALL_ARG_CF_WRITE_SIZE_8_BYTE;
      break;
    case VMEM_30_TRAVEO2CYP01_CF_WRITE_SIZE_32_BYTE:
      dataSize = VMEM_30_TRAVEO2CYP01_FLASHMGTLIB_SYSCALL_ARG_CF_WRITE_SIZE_32_BYTE;
      break;
    case VMEM_30_TRAVEO2CYP01_CF_WRITE_SIZE_512_BYTE:
      dataSize = VMEM_30_TRAVEO2CYP01_FLASHMGTLIB_SYSCALL_ARG_CF_WRITE_SIZE_512_BYTE;
      break;
    default:
      dataSize = 0;
      break;
  }

  return dataSize;
}
#endif /* VMEM_30_TRAVEO2CYP01_READONLY_MODE */

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_FlashMgtLib_Init()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_FlashMgtLib_Init(void)
{
  vMem_30_Traveo2Cyp01_FlashMgtLib_SetSystemCallStatusCode(VMEM_30_TRAVEO2CYP01_FLASHMGTLIB_SYSCALL_STATUS_INIT_VALUE);
}

/**********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_FlashMgtLib_BlankCheck()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_FlashMgtLib_BlankCheck
(
    vMem_30_Traveo2Cyp01_AddressType TargetAddress,
    uint16 NumberOfWords
)
{
  /* ----------- Local variables ----------------------------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----------- Implementation ------------------------------------------------------------------ */
  if(vMem_30_Traveo2Cyp01_FlashMgtLib_IsSystemCallPending() == FALSE)
  {
    vMem_30_Traveo2Cyp01_SysCallArguments[0] = (vMem_30_Traveo2Cyp01_FlashMgtLib_SystemCallArgumentsType)
        VMEM_30_TRAVEO2CYP01_FLASHMGTLIB_OPCODE_BLANK_CHECK << VMEM_30_TRAVEO2CYP01_FLASHMGTLIB_OPCODE_OFFSET;
    vMem_30_Traveo2Cyp01_SysCallArguments[1] = TargetAddress;
    vMem_30_Traveo2Cyp01_SysCallArguments[2] = NumberOfWords - 1uL;

    retVal = vMem_30_Traveo2Cyp01_Ipc_SetMessageAndNotify((vMem_30_Traveo2Cyp01_RegWidthType) /* PRQA S 0306 */ /* MD_vMem_30_Traveo2Cyp01_0306_SystemCallArguments */
        vMem_30_Traveo2Cyp01_SysCallArguments, 0u);
  }

  return retVal;
}

#if (VMEM_30_TRAVEO2CYP01_READONLY_MODE == STD_OFF)
/**********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_FlashMgtLib_EraseSector()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_FlashMgtLib_EraseSector
(
    vMem_30_Traveo2Cyp01_AddressType TargetAddress
)
{
  /* ----------- Local variables ----------------------------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----------- Implementation ------------------------------------------------------------------ */
  if(vMem_30_Traveo2Cyp01_FlashMgtLib_IsSystemCallPending() == FALSE)
  {
    vMem_30_Traveo2Cyp01_SysCallArguments[0] = (vMem_30_Traveo2Cyp01_FlashMgtLib_SystemCallArgumentsType)
        VMEM_30_TRAVEO2CYP01_FLASHMGTLIB_OPCODE_ERASE_SECTOR << VMEM_30_TRAVEO2CYP01_FLASHMGTLIB_OPCODE_OFFSET;
    vMem_30_Traveo2Cyp01_SysCallArguments[1] = TargetAddress;

    retVal =  vMem_30_Traveo2Cyp01_Ipc_SetMessageAndNotify((vMem_30_Traveo2Cyp01_RegWidthType) /* PRQA S 0306 */ /* MD_vMem_30_Traveo2Cyp01_0306_SystemCallArguments */
        vMem_30_Traveo2Cyp01_SysCallArguments, 0u);
  }

  return retVal;
}

/**********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_FlashMgtLib_ProgramRow()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_FlashMgtLib_ProgramRow
(
    vMem_30_Traveo2Cyp01_AddressType TargetAddress,
    vMem_30_Traveo2Cyp01_FlashMgtLib_ConstWriteBufferPtrType WriteBufferPtr,
    vMem_30_Traveo2Cyp01_FlashTypeType FlashType,
    vMem_30_Traveo2Cyp01_LengthType Length
)
{
  /* ----------- Local variables ----------------------------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----------- Implementation ------------------------------------------------------------------ */
  if(vMem_30_Traveo2Cyp01_FlashMgtLib_IsSystemCallPending() == FALSE)
  {
    vMem_30_Traveo2Cyp01_SysCallArguments[0] = (vMem_30_Traveo2Cyp01_FlashMgtLib_SystemCallArgumentsType)
        VMEM_30_TRAVEO2CYP01_FLASHMGTLIB_OPCODE_PROGRAM_ROW << VMEM_30_TRAVEO2CYP01_FLASHMGTLIB_OPCODE_OFFSET;
    vMem_30_Traveo2Cyp01_SysCallArguments[1] = (vMem_30_Traveo2Cyp01_FlashMgtLib_SystemCallArgumentsType)
        VMEM_30_TRAVEO2CYP01_FLASHMGTLIB_DATA_LOCATION_SRAM << VMEM_30_TRAVEO2CYP01_FLASHMGTLIB_DATA_LOCATION_OFFSET;

    if(FlashType == VMEM_30_TRAVEO2CYP01_FLASH_TYPE_CODE)
    {
      vMem_30_Traveo2Cyp01_FlashMgtLib_SystemCallArgumentsType dataSize =
          vMem_30_Traveo2Cyp01_FlashMgtLib_MapLengthToSysCallSizeArg(Length);

      vMem_30_Traveo2Cyp01_SysCallArguments[1] |= dataSize;
    }

    vMem_30_Traveo2Cyp01_SysCallArguments[2] = TargetAddress;
    vMem_30_Traveo2Cyp01_SysCallArguments[3] = (vMem_30_Traveo2Cyp01_AddressType)WriteBufferPtr; /* PRQA S 0306 */ /* MD_vMem_30_Traveo2Cyp01_0306_SourceAddress */

    retVal = vMem_30_Traveo2Cyp01_Ipc_SetMessageAndNotify((vMem_30_Traveo2Cyp01_RegWidthType) /* PRQA S 0306 */ /* MD_vMem_30_Traveo2Cyp01_0306_SystemCallArguments */
        vMem_30_Traveo2Cyp01_SysCallArguments, 0u);
  }

  return retVal;
}
#endif /* VMEM_30_TRAVEO2CYP01_READONLY_MODE */

/**********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_FlashMgtLib_GetResult()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(vMem_30_Traveo2Cyp01_FlashMgtLib_ResultType, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_FlashMgtLib_GetResult(void)
{
  /* ----------- Local variables ----------------------------------------------------------------- */
  vMem_30_Traveo2Cyp01_FlashMgtLib_ResultType result;

  /* ----------- Implementation ------------------------------------------------------------------ */
  if(vMem_30_Traveo2Cyp01_FlashMgtLib_IsSystemCallPending() == TRUE)
  {
    result = VMEM_30_TRAVEO2CYP01_RESULT_PENDING;
  }
  else
  {
    if (vMem_30_Traveo2Cyp01_FlashMgtLib_GetSystemCallStatus() == VMEM_30_TRAVEO2CYP01_FLASHMGTLIB_SYSCALL_STATUS_OK)
    {
      result = VMEM_30_TRAVEO2CYP01_RESULT_OK;
    }
    else
    {
      result = vMem_30_Traveo2Cyp01_FlashMgtLib_AnalyzeSystemCallErrorCode();
    }
  }

  return result;
}

#define VMEM_30_TRAVEO2CYP01_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: vMem_30_Traveo2Cyp01_FlashMgtLib.c
 *********************************************************************************************************************/
