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
/*!        \file  MemAcc_BBMJobManager.h
 *        \brief  MemAcc_BBMJobManager header file
 *      \details  Provides internal bad block management functionality. Should only be used within bad block management
 *                unit.
 *         \unit  BBMJobManager
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#if !defined (MemAcc_BBMJOBMANAGER_H)
# define MemAcc_BBMJOBMANAGER_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "MemAcc_InternalTypes.h"

#if (MEMACC_BBM_ENABLED == STD_ON) /* COV_MSR_UT_OPTIONAL_UNIT */
/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
# define MEMACC_START_SEC_CODE
# include "MemAcc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * MemAcc_BBMJobManager_Reset()
 *********************************************************************************************************************/
/*! \brief       Resets the internal state BBMJobManager.
 *  \details     The Reset includes the initialization state. Jobs to scan the BB Markers are queued after this.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
void MemAcc_BBMJobManager_Reset(void);

/**********************************************************************************************************************
 * MemAcc_BBMJobManager_ProcessInternalJobResult()
 *********************************************************************************************************************/
/*! \brief       Process the result of a completed internal BBM job.
 *  \details     -
 *  \param[in]   job - Job that has completed.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
void MemAcc_BBMJobManager_ProcessInternalJobResult(const MemAcc_JobContextType* job);

/**********************************************************************************************************************
 * MemAcc_BBMJobManager_NotifyBBLutEntryChanged()
 *********************************************************************************************************************/
/*! \brief       Queues a new internal job for a changed bb lut entry.
 *  \details     -
 *  \param[in]   bbLutIdx - bb lut index where the entry was changed.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
void MemAcc_BBMJobManager_NotifyBBLutEntryChanged(const MemAcc_BBLUTStartIdxOfMemInstanceType bbLutIdx);

/**********************************************************************************************************************
 * MemAcc_BBMJobManager_CalculatePhysicalAddressFromJobContext()
 *********************************************************************************************************************/
/*! \brief       Calculates the physical address from the job context for a given address area.
 *  \details     -
 *  \param[in]   aaIdx - address area index.
 *  \return      Physical address.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
MemAcc_AddressType MemAcc_BBMJobManager_CalculatePhysicalAddressFromJobContext(const MemAcc_AddressAreaIndexType aaIdx);


# define MEMACC_STOP_SEC_CODE
# include "MemAcc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* (MEMACC_BBM_ENABLED == STD_ON) */

#endif /* MemAcc_BBMJOBMANAGER_H */

/**********************************************************************************************************************
 *  END OF FILE: MemAcc_BBMJOBMANAGER.h
 *********************************************************************************************************************/
