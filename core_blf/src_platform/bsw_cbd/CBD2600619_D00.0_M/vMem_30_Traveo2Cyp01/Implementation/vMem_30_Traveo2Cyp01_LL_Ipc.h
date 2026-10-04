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
/*!        \file  vMem_30_Traveo2Cyp01_LL_Ipc.h
 *        \brief  Inter Processor Communication header file of the vMem driver.
 *
 *      \details  The IPC module provides the methods to transfer the data for the System Calls to the HSM core.
 *                Only the Core CM0+ is allowed to call the SROM Api Library for writing and erasing the Flash.
 *         \unit  vMem_LL_Ipc
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#if !defined VMEM_30_TRAVEO2CYP01_LL_IPC_H
# define VMEM_30_TRAVEO2CYP01_LL_IPC_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
# include "vMem_30_Traveo2Cyp01_Types.h"
# include "vMem_30_Traveo2Cyp01_LL_RegAccess_Int.h"

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
# define VMEM_30_TRAVEO2CYP01_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_Ipc_Init()
 *********************************************************************************************************************/
/*! \brief       Initializes the IPC hardware.
 *  \details     -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_Ipc_Init(void);

/**********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_Ipc_IsReleased()
 *********************************************************************************************************************/
/*! \brief       Checks if IPC struct is released.
 *  \details     Checks if the configured IPC struct is released by checking the state of the release interrupt flag.
 *  \return      TRUE - IPC struct is released.
 *               FALSE - IPC struct is not released.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(boolean, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_Ipc_IsReleased(void);

/**********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_Ipc_SetMessageAndNotify()
 *********************************************************************************************************************/
/*! \brief       Sets the IPC message and triggers the notification.
 *  \details     Checks if IPC can be locked. Sets the IPC message by writing to the reserved data registers and
 *               triggers the notification event.
 *  \param[in]   Data0      First Data element of IPC structure.
 *  \param[in]   Data1      Second Data element of IPC structure.
 *  \return      E_OK - Message was set and notification event was triggered.
 *               E_NOT_OK - IPC could not be locked.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_Ipc_SetMessageAndNotify
(
    vMem_30_Traveo2Cyp01_RegWidthType Data0,
    vMem_30_Traveo2Cyp01_RegWidthType Data1
);

# define VMEM_30_TRAVEO2CYP01_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* VMEM_30_TRAVEO2CYP01_LL_IPC_H */

/*********************************************************************************************************************
 *  END OF FILE: vMem_30_Traveo2Cyp01_Ipc.h
 *********************************************************************************************************************/
