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
/*!        \file  vMem_30_Traveo2Cyp01_LL_Ipc.c
 *        \brief  Inter Processor Communication source file of the vMem driver.
 *
 *      \details  The IPC module provides the methods to transfer the data for the SystemCalls to the HSM core.
 *                Only the Core CM0+ is allowed to call the SROM Api Library for writing erasing the Flash hardware.
 *         \unit  vMem_LL_Ipc
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#define VMEM_30_TRAVEO2CYP01_LL_IPC_SOURCE

/*lint -e537 */ /* Suppress ID537 due to MD_MSR_19.1 */
/*lint -e451 */ /* Suppress ID451 because MemMap.h cannot use a include guard */

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "vMem_30_Traveo2Cyp01_LL_Ipc.h"
#include "vMem_30_Traveo2Cyp01_LL_Regs.h"
// #include "SchM_vMem_30_Traveo2Cyp01.h"

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
#if !defined (VMEM_30_TRAVEO2CYP01_IPC_LOCAL) /* COV_VMEM_30_TRAVEO2CYP01_COMPATIBILITY */
# define VMEM_30_TRAVEO2CYP01_IPC_LOCAL static
#endif

#if !defined (VMEM_30_TRAVEO2CYP01_IPC_LOCAL_INLINE) /* COV_VMEM_30_TRAVEO2CYP01_COMPATIBILITY */
# define VMEM_30_TRAVEO2CYP01_IPC_LOCAL_INLINE LOCAL_INLINE
#endif

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define VMEM_30_TRAVEO2CYP01_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_Ipc_Lock()
 *********************************************************************************************************************/
/*! \brief       Tries to get the lock of the configured IPC structure.
 *  \details     -
 *  \return      E_OK - IPC structure could be locked.
 *               E_NOT_OK - IPC could not be locked.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
VMEM_30_TRAVEO2CYP01_IPC_LOCAL_INLINE FUNC(Std_ReturnType, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_Ipc_Lock(void);

/**********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_Ipc_Notify()
 *********************************************************************************************************************/
/*! \brief       Triggers a notification event for the configured master IPC interrupt structure.
 *  \details     -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
VMEM_30_TRAVEO2CYP01_IPC_LOCAL_INLINE FUNC(void, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_Ipc_Notify(void);

/**********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_Ipc_IsReleaseInteruptSet()
 *********************************************************************************************************************/
/*! \brief       Checks if the release interrupt flag for the configured IPC structure is set.
 *  \details     -
 *  \return      TRUE - Release interrupt flag is set.
 *               FALSE - Release interrupt flag is not set.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
VMEM_30_TRAVEO2CYP01_IPC_LOCAL_INLINE FUNC(boolean, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_Ipc_IsReleaseInterruptSet(void);

/**********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_Ipc_SetReleaseInterrupt()
 *********************************************************************************************************************/
/*! \brief       Sets the release interrupt flag for the configured IPC structure.
 *  \details     -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
VMEM_30_TRAVEO2CYP01_IPC_LOCAL_INLINE FUNC(void, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_Ipc_SetReleaseInterrupt(void);

/**********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_Ipc_ClearReleaseInterrupt()
 *********************************************************************************************************************/
/*! \brief       Clears the release interrupt flag for the configured IPC structure.
 *  \details     -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
VMEM_30_TRAVEO2CYP01_IPC_LOCAL_INLINE FUNC(void, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_Ipc_ClearReleaseInterrupt(void);

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_Ipc_Lock()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VMEM_30_TRAVEO2CYP01_IPC_LOCAL_INLINE FUNC(Std_ReturnType, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_Ipc_Lock(void)
{
  /* ----------- Local variables ----------------------------------------------------------------- */
  vMem_30_Traveo2Cyp01_RegWidthType acquireState;
  Std_ReturnType retVal = E_NOT_OK;

  /* ----------- Implementation ------------------------------------------------------------------ */
  acquireState = vMem_30_Traveo2Cyp01_Reg_ReadBits(VMEM_30_TRAVEO2CYP01_BASE_IPC,
      VMEM_30_TRAVEO2CYP01_IPC_STRUCT_REG_OFFS_ACQUIRE(VMEM_30_TRAVEO2CYP01_IPC_STRUCT_ID),
      VMEM_30_TRAVEO2CYP01_IPC_STRUCT_REG_ACQUIRE_SUCCESS);

  if(acquireState == VMEM_30_TRAVEO2CYP01_IPC_STRUCT_REG_ACQUIRE_SUCCESS_SUCCESS)
  {
    retVal = E_OK;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_Ipc_Notify()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VMEM_30_TRAVEO2CYP01_IPC_LOCAL_INLINE FUNC(void, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_Ipc_Notify(void)
{
  vMem_30_Traveo2Cyp01_Reg_WriteBits(VMEM_30_TRAVEO2CYP01_BASE_IPC,
      VMEM_30_TRAVEO2CYP01_IPC_STRUCT_REG_OFFS_NOTIFY(VMEM_30_TRAVEO2CYP01_IPC_STRUCT_ID),
      VMEM_30_TRAVEO2CYP01_IPC_STRUCT_REG_NOTIFY_INTR_NOTIFY(VMEM_30_TRAVEO2CYP01_MASTER_IPC_INTR_ID),
      VMEM_30_TRAVEO2CYP01_IPC_STRUCT_REG_NOTIFY_INTR_NOTIFY_GENERATE(VMEM_30_TRAVEO2CYP01_MASTER_IPC_INTR_ID));
}

/**********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_Ipc_IsReleaseInterruptSet()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VMEM_30_TRAVEO2CYP01_IPC_LOCAL_INLINE FUNC(boolean, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_Ipc_IsReleaseInterruptSet(void)
{
  /* ----------- Local variables ----------------------------------------------------------------- */
  vMem_30_Traveo2Cyp01_RegWidthType slaveCurrentReleaseState;
  vMem_30_Traveo2Cyp01_RegWidthType slaveReleaseState;

  /* ----------- Implementation ------------------------------------------------------------------ */
  slaveReleaseState = VMEM_30_TRAVEO2CYP01_IPC_INTR_STRUCT_REG_INTR_RELEASE_RELEASE(VMEM_30_TRAVEO2CYP01_IPC_STRUCT_ID);

  slaveCurrentReleaseState = vMem_30_Traveo2Cyp01_Reg_ReadBits(VMEM_30_TRAVEO2CYP01_BASE_IPC,
      VMEM_30_TRAVEO2CYP01_IPC_INTR_STRUCT_REG_OFFS_INTR(VMEM_30_TRAVEO2CYP01_SLAVE_IPC_INTR_ID),
      VMEM_30_TRAVEO2CYP01_IPC_STRUCT_REG_NOTIFY_INTR_RELEASE(VMEM_30_TRAVEO2CYP01_IPC_STRUCT_ID));

  return (slaveCurrentReleaseState == slaveReleaseState) ? TRUE : FALSE;
}

/**********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_Ipc_ClearReleaseInterrupt()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VMEM_30_TRAVEO2CYP01_IPC_LOCAL_INLINE FUNC(void, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_Ipc_ClearReleaseInterrupt(void)
{
  vMem_30_Traveo2Cyp01_Reg_Write(VMEM_30_TRAVEO2CYP01_BASE_IPC,
      VMEM_30_TRAVEO2CYP01_IPC_INTR_STRUCT_REG_OFFS_INTR(VMEM_30_TRAVEO2CYP01_SLAVE_IPC_INTR_ID),
      VMEM_30_TRAVEO2CYP01_IPC_INTR_STRUCT_REG_INTR_RELEASE_RELEASE(VMEM_30_TRAVEO2CYP01_IPC_STRUCT_ID));
}

/**********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_Ipc_SetReleaseInterrupt()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VMEM_30_TRAVEO2CYP01_IPC_LOCAL_INLINE FUNC(void, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_Ipc_SetReleaseInterrupt(void)
{
  vMem_30_Traveo2Cyp01_Reg_WriteBits(VMEM_30_TRAVEO2CYP01_BASE_IPC,
      VMEM_30_TRAVEO2CYP01_IPC_INTR_STRUCT_REG_OFFS_INTR_SET(VMEM_30_TRAVEO2CYP01_SLAVE_IPC_INTR_ID),
      VMEM_30_TRAVEO2CYP01_IPC_INTR_STRUCT_REG_INTR_SET_RELEASE(VMEM_30_TRAVEO2CYP01_IPC_STRUCT_ID),
      VMEM_30_TRAVEO2CYP01_IPC_INTR_STRUCT_REG_INTR_SET_RELEASE_RELEASE(VMEM_30_TRAVEO2CYP01_IPC_STRUCT_ID));
}

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_Ipc_Init()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_Ipc_Init(void)
{
  vMem_30_Traveo2Cyp01_Ipc_SetReleaseInterrupt();
}

/**********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_Ipc_SetMessageAndNotify()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_Ipc_SetMessageAndNotify
(
    vMem_30_Traveo2Cyp01_RegWidthType Data0,
    vMem_30_Traveo2Cyp01_RegWidthType Data1
)
{
  /* ----------- Local variables ----------------------------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----------- Implementation ------------------------------------------------------------------ */
  /* #10 Try to get the lock of the IPC structure. Otherwise decline the query.  */
  // SchM_Enter_vMem_30_Traveo2Cyp01_VMEM_30_TRAVEO2CYP01_EXCLUSIVE_AREA_0();
  if (vMem_30_Traveo2Cyp01_Ipc_Lock() == E_OK)
  {
    /* #20 Clear the release interrupt flag to indicate that the IPC structure is not released.  */
    vMem_30_Traveo2Cyp01_Ipc_ClearReleaseInterrupt();

    /* #30 Set data which should be sent to another core. */
    vMem_30_Traveo2Cyp01_Reg_Write(VMEM_30_TRAVEO2CYP01_BASE_IPC,
        VMEM_30_TRAVEO2CYP01_IPC_STRUCT_REG_OFFS_DATA(VMEM_30_TRAVEO2CYP01_IPC_STRUCT_ID, 0u), Data0);

    vMem_30_Traveo2Cyp01_Reg_Write(VMEM_30_TRAVEO2CYP01_BASE_IPC,
        VMEM_30_TRAVEO2CYP01_IPC_STRUCT_REG_OFFS_DATA(VMEM_30_TRAVEO2CYP01_IPC_STRUCT_ID, 1u), Data1);

    /* #40 Trigger the IPC notification to notify the receiver of a new message. */
    vMem_30_Traveo2Cyp01_Ipc_Notify();

    retVal = E_OK;
  }
  // SchM_Exit_vMem_30_Traveo2Cyp01_VMEM_30_TRAVEO2CYP01_EXCLUSIVE_AREA_0();

  return retVal;
}

/**********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_Ipc_IsReleased()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(boolean, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_Ipc_IsReleased(void)
{
  return vMem_30_Traveo2Cyp01_Ipc_IsReleaseInterruptSet();
}

#define VMEM_30_TRAVEO2CYP01_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: vMem_30_Traveo2Cyp01_Ipc.c
 *********************************************************************************************************************/
