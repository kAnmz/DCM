/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2026 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!        \file  MemAcc_MainFsm.h
 *        \brief  MemAcc_MainFsm header file
 *      \details  Header of FSM library unit of the MemAcc.
 *         \unit  MainFsm
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#if !defined (MEMACC_MAINFSM_H)
# define MEMACC_MAINFSM_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "MemAcc_InternalTypes.h"

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
/*! Enumeration describing a processing result */
typedef enum
{
  MEMACC_MAINFSM_PROCESSINGRESULT_STOP = 0,     /*! No further processing is required */
  MEMACC_MAINFSM_PROCESSINGRESULT_CONTINUE      /*! Continue to process */
} MemAcc_MainFsm_ProcessingResultType;

/*! Function pointer describing an ENTRY action */
typedef void(*MemAcc_MainFsm_ActionEntryFptr)(MemAcc_SyncGroupIndexType SyncGroupIndex);

/*! Function pointer describing a DO action */
typedef MemAcc_MainFsm_ProcessingResultType(*MemAcc_MainFsm_ActionDoFptr)(MemAcc_SyncGroupIndexType SyncGroupIndex);

/*! Structure defining a state object */
typedef struct
{
  MemAcc_MainFsm_ActionEntryFptr Entry;       /*! ENTRY action of state, if not required use MemAcc_MainFsm_EntryNoOp */
  MemAcc_MainFsm_ActionDoFptr Do;             /*! DO action of state */
} MemAcc_MainFsm_StateType;

/***********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * MemAcc_MainFsm_Reset()
 *********************************************************************************************************************/
/*!  \brief       Resets the MainFsm to its initial state. Must be called before any usage of other service functions.
 *   \details     -
 *   \pre         -
 *   \context     TASK
 *   \reentrant   FALSE
 *   \synchronous TRUE
 *********************************************************************************************************************/
void MemAcc_MainFsm_Reset(void);

/**********************************************************************************************************************
 * MemAcc_MainFsm_ProcessAllSyncGroups()
 *********************************************************************************************************************/
/*!  \brief       Processes the state machines for all synchronization groups.
 *   \details     -
 *   \pre         -
 *   \context     TASK
 *   \reentrant   FALSE
 *   \synchronous TRUE
 *********************************************************************************************************************/
void MemAcc_MainFsm_ProcessAllSyncGroups(void);

#endif /* MEMACC_MAINFSM_H */

/**********************************************************************************************************************
 *  END OF FILE: MemAcc_MainFsm.h
 *********************************************************************************************************************/
