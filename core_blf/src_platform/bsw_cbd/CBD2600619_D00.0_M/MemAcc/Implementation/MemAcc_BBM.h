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
/*!        \file  MemAcc_BBM.h
 *        \brief  MemAcc_BBM header file
 *      \details  Provides all bad block management services to other MemAcc units.
 *         \unit  BBM
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#if !defined (MemAcc_BBM_H)
# define MemAcc_BBM_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "MemAcc_InternalTypes.h"

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

# if (MEMACC_BBM_ENABLED == STD_ON) /* COV_MSR_UT_OPTIONAL_UNIT */

/**********************************************************************************************************************
 * MemAcc_BBM_Reset()
 *********************************************************************************************************************/
/*! \brief       Resets the internal state for BBM and BBMJobManager.
 *  \details     -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
void MemAcc_BBM_Reset(void);

/**********************************************************************************************************************
 * MemAcc_BBM_TranslateLogicalToPhysicalAddress()
 *********************************************************************************************************************/
/*! \brief       Translates a logical address of a SAA into the corresponding physical address.
 *               This also accounts for BB.
 *  \details     -
 *  \param[in]   jobClassification - job classification.
 *  \param[in]   saaIdx - Index of the SAA where the logical address is located.
 *  \param[in]   logicalAddress - Logical address.
 *  \return      The calculated physical address. The address may be out of bounds.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
MemAcc_AddressType MemAcc_BBM_TranslateLogicalToPhysicalAddress(
  const MemAcc_JobClassificationType jobClassification,
  const MemAcc_SubAddressAreaIndexType saaIdx,
  const MemAcc_AddressType logicalAddress);

/**********************************************************************************************************************
 * MemAcc_BBM_UpsertBadBlock()
 *********************************************************************************************************************/
/*! \brief       Adds or Updates the BB marker state for a given physical block.
 *  \details     A physical block is uniquely identified using a SAA Idx and a physical block number.
 *  \param[in]   bbMarkerState - Marker State of the BB.
 *  \param[in]   saaIdx - SAA Idx of the BB.
 *  \param[in]   physicalBlockNr - Physical block number of the BB.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
void MemAcc_BBM_UpsertBadBlock(
  const MemAcc_BBM_BBMarkerStateType bbMarkerState,
  const MemAcc_SubAddressAreaIndexType saaIdx,
  const MemAcc_NumberOfSectorsOfSubAddressAreaType physicalBlockNr);

/**********************************************************************************************************************
 * MemAcc_BBM_ProcessInternalJobResult()
 *********************************************************************************************************************/
/*! \brief       Process the result of a completed internal BBM job.
 *  \details     -
 *  \param[in]   job - Job that has completed.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
void MemAcc_BBM_ProcessInternalJobResult(const MemAcc_JobContextType* job);

# endif /* (MEMACC_BBM_ENABLED == STD_ON) */

# define MEMACC_STOP_SEC_CODE
# include "MemAcc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* MemAcc_BBM_H */

/**********************************************************************************************************************
 *  END OF FILE: MemAcc_BBM.h
 *********************************************************************************************************************/
