/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2025 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!        \file  vMem_30_Traveo2Cyp01_LL_FlashMgtLib.h
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

 #if !defined VMEM_30_TRAVEO2CYP01_FLASHMGTLIB_LL_H
# define VMEM_30_TRAVEO2CYP01_FLASHMGTLIB_LL_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "vMem_30_Traveo2Cyp01_LL_Ipc.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define VMEM_30_TRAVEO2CYP01_FLASHMGTLIB_SYSCALL_NUM_OF_ARGUMENTS      (4u)

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
/*! Data type for the argument of the system call */
typedef uint32 vMem_30_Traveo2Cyp01_FlashMgtLib_SystemCallArgumentsType;

/*! Data type for the write buffer for the ProgramRow system call */
typedef uint32 vMem_30_Traveo2Cyp01_FlashMgtLib_WriteBufferType;

/*! Const pointer for the write buffer for the ProgramRow system call */
typedef P2CONST(vMem_30_Traveo2Cyp01_FlashMgtLib_WriteBufferType, AUTOMATIC, VMEM_30_TRAVEO2CYP01_APPL_VAR)
    vMem_30_Traveo2Cyp01_FlashMgtLib_ConstWriteBufferPtrType;

/*! Data type for the status of the Flash Management Library */
typedef enum
{
  VMEM_30_TRAVEO2CYP01_RESULT_OK,
  VMEM_30_TRAVEO2CYP01_RESULT_MEM_NOT_BLANK,
  VMEM_30_TRAVEO2CYP01_RESULT_PENDING,
  VMEM_30_TRAVEO2CYP01_RESULT_FAILED
} vMem_30_Traveo2Cyp01_FlashMgtLib_ResultType;

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
# define VMEM_30_TRAVEO2CYP01_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_FlashMgtLib_Init()
 *********************************************************************************************************************/
/*! \brief       Initializes the Flash Management Library.
 *  \details     -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_FlashMgtLib_Init(void);

/**********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_FlashMgtLib_BlankCheck()
 *********************************************************************************************************************/
/*! \brief       Asynchronous service to perform an blank check on the addressed work flash.
 *  \details     -
 *  \param[in]   TargetAddress       NV memory address to perform an blank check.
 *  \param[in]   NumberOfWords       Number of words (word means 4 bytes) to be checked.
 *  \return      E_OK - Operation was accepted and triggered.
 *               FALSE - Another system call is still active.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous FALSE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_FlashMgtLib_BlankCheck
(
    vMem_30_Traveo2Cyp01_AddressType TargetAddress,
    uint16 NumberOfWords
);

#if (VMEM_30_TRAVEO2CYP01_READONLY_MODE == STD_OFF)
/**********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_FlashMgtLib_EraseSector()
 *********************************************************************************************************************/
/*! \brief       Asynchronous service to erase an addressed sector on the flash.
 *  \details     -
 *  \param[in]   TargetAddress       NV memory sector address to erase.
 *  \return      E_OK - Operation was accepted and triggered.
 *               FALSE - Another system call is still active.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous FALSE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_FlashMgtLib_EraseSector
(
    vMem_30_Traveo2Cyp01_AddressType TargetAddress
);

/**********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_FlashMgtLib_ProgramRow()
 *********************************************************************************************************************/
/*! \brief       Asynchronous service to write an array of data to a single row of flash.
 *  \details     -
 *  \param[in]   TargetAddress       NV memory sector address to erase.
 *  \param[in]   WriteBufferPtr      Pointer to buffer with data to write to nv memory.
 *                                   Must stay valid until job is completed.
 *  \param[in]   TargetAddress       Flash type Code or Work.
 *  \param[in]   Length              Length in bytes to write.
 *  \return      E_OK - Operation was accepted and triggered.
 *               FALSE - Another system call is still active.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous FALSE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_FlashMgtLib_ProgramRow
(
    vMem_30_Traveo2Cyp01_AddressType TargetAddress,
    vMem_30_Traveo2Cyp01_FlashMgtLib_ConstWriteBufferPtrType WriteBufferPtr,
    vMem_30_Traveo2Cyp01_FlashTypeType FlashType,
    vMem_30_Traveo2Cyp01_LengthType Length
);
#endif /* VMEM_30_TRAVEO2CYP01_READONLY_MODE */

/**********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_FlashMgtLib_GetResult()
 *********************************************************************************************************************/
/*! \brief       Returns the result of the last accepted flash operation, as long as no new operation is accepted.
 *  \details     -
 *  \return      Current result of the flash operation.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(vMem_30_Traveo2Cyp01_FlashMgtLib_ResultType, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_FlashMgtLib_GetResult(void);

# define VMEM_30_TRAVEO2CYP01_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* VMEM_30_TRAVEO2CYP01_FLASHMGTLIB_LL_H */

/*********************************************************************************************************************
 *  END OF FILE: vMem_30_Traveo2Cyp01_LL_FlashMgtLib.h
 *********************************************************************************************************************/
