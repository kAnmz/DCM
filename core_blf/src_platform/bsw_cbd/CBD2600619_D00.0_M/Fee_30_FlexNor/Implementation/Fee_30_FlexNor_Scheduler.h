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
/*!        \file  Fee_30_FlexNor_Scheduler.h
 *        \brief  Internal processing scheduler
 *      \details  Provides a FEE internal scheduler that is responsible for processing units.
 *         \unit  Scheduler
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 **********************************************************************************************************************/

#if !defined (FEE_30_FLEXNOR_SCHEDULER_H)
# define FEE_30_FLEXNOR_SCHEDULER_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Fee_30_FlexNor_Types.h"

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef P2FUNC(Fee_30_FlexNor_ScheduleBehaviorType, AUTOMATIC, Fee_30_FlexNor_ProcessingHandler)(void);

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
# define FEE_30_FLEXNOR_START_SEC_CODE
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Fee_30_FlexNor_Scheduler_Init()
 *********************************************************************************************************************/
/*! \brief       Initializes the internal scheduler
 *  \details     -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Scheduler_Init(void);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Scheduler_GetStatus()
 *********************************************************************************************************************/
/*! \brief       Returns the current status of the scheduler unit.
 *  \details     -
 *  \return      FEE_30_FLEXNOR_IDLE       The scheduler is currently idle
 *               FEE_30_FLEXNOR_BUSY       The scheduler is currently busy
 *               FEE_30_FLEXNOR_CANCELLING The scheduler is currently busy with processing a job that shall be canceled.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_StatusType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Scheduler_GetStatus(void);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Scheduler_RegisterUnit()
 *********************************************************************************************************************/
/*! \brief       Registers a unit for processing
 *  \details     Registers units that require execution for the fulfillment of a service request.
 *  \param[in]   processingHandler   Pointer to the processing function of the unit
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Scheduler_RegisterUnit(
    Fee_30_FlexNor_ProcessingHandler processingHandler);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Scheduler_UnregisterUnit()
 *********************************************************************************************************************/
/*! \brief       Unregisters a unit from processing
 *  \details     Unregisters the last unit that was registered at the scheduler.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Scheduler_UnregisterUnit(void);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Scheduler_Schedule()
 *********************************************************************************************************************/
/*! \brief       Processes registered units
 *  \details     Processes the currently registered units until all units are done or the scheduling is stopped by
 *               one of the units that are being processed.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Scheduler_Schedule(void);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Scheduler_AllowCancel()
 *********************************************************************************************************************/
/*! \brief       Allow job cancelation
 *  \details     Calling this function allows the job cancelation, i.e. the job can be canceled immediately if
 *               requested.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Scheduler_AllowCancel(void);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Scheduler_DenyCancel()
 *********************************************************************************************************************/
/*! \brief       Denies the job cancelation
 *  \details     Calling this function denies the immediate job cancelation, i.e. the actuall cancelation is delayed
 *               until its explicitly allowed again by the processed units.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Scheduler_DenyCancel(void);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Scheduler_Cancel()
 *********************************************************************************************************************/
/*! \brief       Requests the cancelation of the of the currently running job.
 *  \details     -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Scheduler_Cancel(void);

# define FEE_30_FLEXNOR_STOP_SEC_CODE
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* FEE_30_FLEXNOR_SCHEDULER_H */

/**********************************************************************************************************************
 *  END OF FILE: Fee_30_FlexNor_Scheduler.h
 *********************************************************************************************************************/
