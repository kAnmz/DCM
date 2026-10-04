/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2026 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!        \file  MemAcc_BBM.c
 *        \brief  MemAcc_BBM source file
 *      \details  -
 *         \unit  BBM
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#define MEMACC_BBM_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "MemAcc_BBM.h"
#include "MemAcc_Queue.h"
#include "MemAcc_Utils.h"
#include "MemAcc_BBMJobManager.h"

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/
#if !defined (MEMACC_LOCAL)
# define MEMACC_LOCAL                                                    static
#endif

#if !defined (MEMACC_LOCAL_INLINE)
# define MEMACC_LOCAL_INLINE                                             LOCAL_INLINE
#endif

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define MEMACC_START_SEC_CODE
#include "MemAcc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if (MEMACC_BBM_ENABLED == STD_ON) /* COV_MSR_UT_OPTIONAL_UNIT */

/**********************************************************************************************************************
 * MemAcc_BBM_CalculateSkipMethodPhysicalBlockOffset()
 *********************************************************************************************************************/
/*! \brief       Calculates the physical block offset to the logical block number for the BB Skip Method.
 *  \details     -
 *  \param[in]   saaIdx - Index of the SAA where the logical block is located.
 *  \param[in]   logicalBlockNr - Logical block where the offset should be calculated.
 *  \return      The calculated physical block offset
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
MEMACC_LOCAL MemAcc_NumberOfSectorsOfSubAddressAreaType MemAcc_BBM_CalculateSkipMethodPhysicalBlockOffset(
  const MemAcc_SubAddressAreaIndexType saaIdx,
  const MemAcc_NumberOfSectorsOfSubAddressAreaType logicalBlockNr);

/**********************************************************************************************************************
 * MemAcc_BBM_InsertSkipMethodBadBlockUsingInsertionSort()
 *********************************************************************************************************************/
/*! \brief       Performs an insertion sort to insert the given bb lut entry into the bb lut sub array between
 *               the given first and last index. It will be ordered by SaaIdx and then by PhysicalBlockNr.
 *  \details     -
 *  \param[in]   firstBbLutIdx - First index of the bb lut to insert.
 *  \param[in]   lastBbLutIdx - Last index of the bb lut to insert.
 *  \param[in]   bbLutEntry - bb lut entry to insert.
 *  \pre         May only be called from MemAcc_BBM_InsertSkipMethodBadBlock().
 *               Unique Key may not exist in the bb lut.
 *               At least one markerstate NONE must exist in the sub array to signal there is a open position for the new entry.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
MEMACC_LOCAL void MemAcc_BBM_InsertSkipMethodBadBlockUsingInsertionSort(
  const MemAcc_BBLUTStartIdxOfMemInstanceType firstBbLutIdx,
  const MemAcc_BBLUTStartIdxOfMemInstanceType lastBbLutIdx,
  const MemAcc_BBLUTType bbLutEntry);

/**********************************************************************************************************************
 * MemAcc_BBM_InsertSkipMethodBadBlock()
 *********************************************************************************************************************/
/*! \brief       Inserts the given bb lut entry into the bb lut.
 *  \details     -
 *  \param[in]   bbLutEntry - bb lut entry to insert.
 *  \pre         Unique Key may not exist in the bb lut.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
MEMACC_LOCAL void MemAcc_BBM_InsertSkipMethodBadBlock(const MemAcc_BBLUTType bbLutEntry);

/**********************************************************************************************************************
 * MemAcc_BBM_UpdateSkipMethodBadBlockMarkerState()
 *********************************************************************************************************************/
/*! \brief       Updates the given marker state in the bb lut for the given entry.
 *  \details     If the unique key does not exist in the bb lut, does nothing.
 *  \param[in]   bbLutEntry - bb lut entry to update.
 *  \return      TRUE - if the update was successful.
 *  \return      FALSE - if the entry was not found in bb lut.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
MEMACC_LOCAL boolean MemAcc_BBM_UpdateSkipMethodBadBlockMarkerState(const MemAcc_BBLUTType bbLutEntry);

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * MemAcc_BBM_CalculateSkipMethodPhysicalBlockOffset()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
MEMACC_LOCAL MemAcc_NumberOfSectorsOfSubAddressAreaType MemAcc_BBM_CalculateSkipMethodPhysicalBlockOffset(
  const MemAcc_SubAddressAreaIndexType saaIdx,
  const MemAcc_NumberOfSectorsOfSubAddressAreaType logicalBlockNr)
{
  MemAcc_NumberOfSectorsOfSubAddressAreaType offset = 0u;
  const MemAcc_SizeOfMemInstanceType bbCfgIdx = MemAcc_GetMemInstanceIdxOfSubAddressArea(saaIdx);

  /*
   * Searches for all bb lut entries in the same SAA that exist before the given block number.
   * Increases the search range for each bad block found this way.
   * The resulting offset indicates the number of blocks that have to be skipped from the logical to the physical block number.
  */
  for (MemAcc_BBLUTStartIdxOfMemInstanceType bbLutIdx = MemAcc_GetBBLUTStartIdxOfMemInstance(bbCfgIdx);
    (bbLutIdx < MemAcc_GetBBLUTEndIdxOfMemInstance(bbCfgIdx))
    && (MemAcc_GetBBMarkerStateOfBBLUT(bbLutIdx) != MEMACC_BBM_BBMARKERSTATE_NONE)
    && (MemAcc_GetSAAIdxOfBBLUT(bbLutIdx) <= saaIdx);
    bbLutIdx++)
  {
    if (MemAcc_GetSAAIdxOfBBLUT(bbLutIdx) == saaIdx)
    {
      if (MemAcc_GetPhysicalBlockNrOfBBLUT(bbLutIdx) <= (logicalBlockNr + offset))
      {
        /* Increment offset for each bad block found before the target block in the same SAA. */
        offset++;
      }
      else
      {
        break;
      }
    }
  }

  return offset;
}

/**********************************************************************************************************************
 * MemAcc_BBM_InsertSkipMethodBadBlockUsingInsertionSort()
 *********************************************************************************************************************/
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
 *
 *
 *
 *
 *
 * \spec
 *   requires firstBbLutIdx < MemAcc_GetSizeOfBBLUT();
 *   requires lastBbLutIdx < MemAcc_GetSizeOfBBLUT();
 *   requires bbLutEntry.SAAIdxOfBBLUT < MemAcc_GetSizeOfSubAddressArea();
 * \endspec
 */
MEMACC_LOCAL void MemAcc_BBM_InsertSkipMethodBadBlockUsingInsertionSort(
  const MemAcc_BBLUTStartIdxOfMemInstanceType firstBbLutIdx,
  const MemAcc_BBLUTStartIdxOfMemInstanceType lastBbLutIdx,
  const MemAcc_BBLUTType bbLutEntry)
{
  /*
   * Each bb lut sub array, defined by the first and last index, is ordered by SAAIdx and then by PhysicalBlockNr.
   * MarkerState NONE indicates that this lut entry is unused and is always at the end of the sub array.
   * This loop functions as a insertion sort, preparing the array for insertion of the new entry in a ordered manner.
   */
  MemAcc_BBLUTStartIdxOfMemInstanceType currBbLutIdx = lastBbLutIdx;
  for (; currBbLutIdx > firstBbLutIdx; currBbLutIdx--)
  {
    const MemAcc_BBLUTStartIdxOfMemInstanceType prevBbLutIdx = currBbLutIdx - ((MemAcc_BBLUTStartIdxOfMemInstanceType)1u);

    if (MemAcc_GetBBMarkerStateOfBBLUT(prevBbLutIdx) == MEMACC_BBM_BBMARKERSTATE_NONE)
    {
      /* no need to copy 'none' to 'none' marker entries. */
    }
    else if ((MemAcc_GetSAAIdxOfBBLUT(prevBbLutIdx) > bbLutEntry.SAAIdxOfBBLUT)
      || ((MemAcc_GetSAAIdxOfBBLUT(prevBbLutIdx) == bbLutEntry.SAAIdxOfBBLUT)
      && (MemAcc_GetPhysicalBlockNrOfBBLUT(prevBbLutIdx) > bbLutEntry.PhysicalBlockNrOfBBLUT)))
    {
      /* Shift prevBbLutIdx element to currBbLutIdx position. If element would not be in order. */
      MemAcc_SetPhysicalBlockNrOfBBLUT(currBbLutIdx, MemAcc_GetPhysicalBlockNrOfBBLUT(prevBbLutIdx));
      MemAcc_SetSAAIdxOfBBLUT(currBbLutIdx, MemAcc_GetSAAIdxOfBBLUT(prevBbLutIdx));
      MemAcc_SetBBMarkerStateOfBBLUT(currBbLutIdx, MemAcc_GetBBMarkerStateOfBBLUT(prevBbLutIdx));
    }
    else
    {
      /* If element would be in order, break so it can be inserted at the currBbLutIdx. */
      break;
    }
  }

  /* Insert the new element on the open position cleared by the loop above to keep the array sorted. */
  MemAcc_SetPhysicalBlockNrOfBBLUT(currBbLutIdx, bbLutEntry.PhysicalBlockNrOfBBLUT);
  MemAcc_SetSAAIdxOfBBLUT(currBbLutIdx, bbLutEntry.SAAIdxOfBBLUT);
  MemAcc_SetBBMarkerStateOfBBLUT(currBbLutIdx, bbLutEntry.BBMarkerStateOfBBLUT);
  MemAcc_BBMJobManager_NotifyBBLutEntryChanged(currBbLutIdx);
}

/**********************************************************************************************************************
 * MemAcc_BBM_InsertSkipMethodBadBlock()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 * \spec
 *   requires bbLutEntry.SAAIdxOfBBLUT < MemAcc_GetSizeOfSubAddressArea();
 * \endspec
 */
MEMACC_LOCAL void MemAcc_BBM_InsertSkipMethodBadBlock(const MemAcc_BBLUTType bbLutEntry)
{
  const MemAcc_SizeOfMemInstanceType bbCfgIdx = MemAcc_GetMemInstanceIdxOfSubAddressArea(bbLutEntry.SAAIdxOfBBLUT);

  /* First and last index of the sub array for the bbCfgIdx. */
  const MemAcc_BBLUTStartIdxOfMemInstanceType firstBbLutIdx = MemAcc_GetBBLUTStartIdxOfMemInstance(bbCfgIdx);
  const MemAcc_BBLUTStartIdxOfMemInstanceType lastBbLutIdx =
    MemAcc_GetBBLUTEndIdxOfMemInstance(bbCfgIdx) - ((MemAcc_BBLUTStartIdxOfMemInstanceType)1u);
  /*@ assert firstBbLutIdx < MemAcc_GetSizeOfBBLUT(); */ /* VCA_MemAcc_BBLUTIteration */
  /*@ assert lastBbLutIdx < MemAcc_GetSizeOfBBLUT(); */ /* VCA_MemAcc_BBLUTIteration */

  /*
   * If the last element of the bbLut for a bbCfgIdx is not a 'NONE' marker then the bbLut for the given MemInstance is full.
   * In this case no new entry can be inserted and a error is raised.
   * This is also the case if there are no entries in the bbLut to begin with for the given MemInstance. This however is validated via VCA.
   */
  if (MemAcc_GetBBMarkerStateOfBBLUT(lastBbLutIdx) != MEMACC_BBM_BBMARKERSTATE_NONE)
  {
    MemAcc_Queue_RaiseError(MemAcc_Utils_GetAddrAreaIdxOfSubAddrAreaIdx(bbLutEntry.SAAIdxOfBBLUT), MEMACC_ERRORTYPE_BBM_BBLUTFULL);
  }
  else
  {
    MemAcc_BBM_InsertSkipMethodBadBlockUsingInsertionSort(firstBbLutIdx, lastBbLutIdx, bbLutEntry);
  }
}

/**********************************************************************************************************************
 * MemAcc_BBM_UpdateSkipMethodBadBlockMarkerState()
 *********************************************************************************************************************/
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
 *
 */
MEMACC_LOCAL boolean MemAcc_BBM_UpdateSkipMethodBadBlockMarkerState(const MemAcc_BBLUTType bbLutEntry)
{
  boolean updatedExistingEntry = FALSE;
  const MemAcc_SizeOfMemInstanceType bbCfgIdx = MemAcc_GetMemInstanceIdxOfSubAddressArea(bbLutEntry.SAAIdxOfBBLUT);

  /*
   * Check if the entry already exists in the array and update the markerstate if it does.
   * The unique key of a entry is the SAAIdx and the PhysicalBlockNr.
   */
  for (MemAcc_BBLUTStartIdxOfMemInstanceType bbLutIdx = MemAcc_GetBBLUTStartIdxOfMemInstance(bbCfgIdx);
    (bbLutIdx < MemAcc_GetBBLUTEndIdxOfMemInstance(bbCfgIdx))
    && (MemAcc_GetBBMarkerStateOfBBLUT(bbLutIdx) != MEMACC_BBM_BBMARKERSTATE_NONE)
    && (MemAcc_GetSAAIdxOfBBLUT(bbLutIdx) <= bbLutEntry.SAAIdxOfBBLUT);
    bbLutIdx++)
  {
    if ((MemAcc_GetPhysicalBlockNrOfBBLUT(bbLutIdx) == bbLutEntry.PhysicalBlockNrOfBBLUT)
      && (MemAcc_GetSAAIdxOfBBLUT(bbLutIdx) == bbLutEntry.SAAIdxOfBBLUT))
    {
      updatedExistingEntry = TRUE;
      /*@ assert bbLutIdx < MemAcc_GetSizeOfBBLUT(); */ /* VCA_MemAcc_BBLUTIteration */
      /* Update existing marker state. */
      MemAcc_SetBBMarkerStateOfBBLUT(bbLutIdx, bbLutEntry.BBMarkerStateOfBBLUT);
      MemAcc_BBMJobManager_NotifyBBLutEntryChanged(bbLutIdx);
      break;
    }
  }

  return updatedExistingEntry;
}

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * MemAcc_BBM_Reset()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
void MemAcc_BBM_Reset(void)
{
  for (MemAcc_BBLUTStartIdxOfMemInstanceType bbLutIdx = 0u; bbLutIdx < MemAcc_GetSizeOfBBLUT(); bbLutIdx++)
  {
    MemAcc_SetPhysicalBlockNrOfBBLUT(bbLutIdx, 0u);
    MemAcc_SetSAAIdxOfBBLUT(bbLutIdx, 0u);
    MemAcc_SetBBMarkerStateOfBBLUT(bbLutIdx, MEMACC_BBM_BBMARKERSTATE_NONE);
  }

  MemAcc_BBMJobManager_Reset();
}

/**********************************************************************************************************************
 * MemAcc_BBM_TranslateLogicalToPhysicalAddress()
 *********************************************************************************************************************/
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
 *
 *
 *
 */
MemAcc_AddressType MemAcc_BBM_TranslateLogicalToPhysicalAddress(
  const MemAcc_JobClassificationType jobClassification,
  const MemAcc_SubAddressAreaIndexType saaIdx,
  const MemAcc_AddressType logicalAddress)
{
  const MemAcc_LengthType logicalOffset = logicalAddress - MemAcc_GetLogicalStartAddressOfSubAddressArea(saaIdx);
  MemAcc_AddressType physicalAddress = MemAcc_GetPhysicalStartAddressOfSubAddressArea(saaIdx) + logicalOffset;

  if(MemAcc_GetBBStrategyOfMemInstance(MemAcc_GetMemInstanceIdxOfSubAddressArea(saaIdx)) == MEMACC_BBM_BBSTRATEGY_SKIPMETHOD)
  {
    if(jobClassification == MEMACC_JOBCLASSIFICATION_BBM_ERASEBLOCK)
    {
      /*
       * For erase block jobs, the physical address is calculated from the job context.
       * The bad block is already in the BBLUT, so no logical address can calculate this physical address.
       */
      const MemAcc_AddressAreaIndexType aaIdx = MemAcc_Utils_GetAddrAreaIdxOfSubAddrAreaIdx(saaIdx);
      physicalAddress = MemAcc_BBMJobManager_CalculatePhysicalAddressFromJobContext(aaIdx);
    }
    else
    {
      /* MemAcc_LengthType can be used, because the memdriver specifies the sector size with unit32 max. */
      const MemAcc_LengthType sectorSize = MemAcc_GetEraseSectorSizeOfMemSectorBatch(MemAcc_GetMemSectorBatchIdxOfSubAddressArea(saaIdx));

      /* The block number is always rounded down. There are multiple addresses per block. */
      const MemAcc_NumberOfSectorsOfSubAddressAreaType logicalBlockNr =
        (MemAcc_NumberOfSectorsOfSubAddressAreaType)(logicalOffset / sectorSize);

      /*
      * With a high logical address and existing bad blocks, the physical address may be out of bounds of the sub address area.
      * This needs to be handled by the caller.
      */
      physicalAddress += ((MemAcc_AddressType)MemAcc_BBM_CalculateSkipMethodPhysicalBlockOffset(saaIdx, logicalBlockNr))
                          * sectorSize;
    }
  }

  return physicalAddress;
}

/**********************************************************************************************************************
 * MemAcc_BBM_UpsertBadBlock()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 * \spec
 *   requires saaIdx < MemAcc_GetSizeOfSubAddressArea();
 * \endspec
 */
void MemAcc_BBM_UpsertBadBlock(
  const MemAcc_BBM_BBMarkerStateType bbMarkerState,
  const MemAcc_SubAddressAreaIndexType saaIdx,
  const MemAcc_NumberOfSectorsOfSubAddressAreaType physicalBlockNr)
{
  /*!
   * MEMACC_DEBUG_BREAKPOINT:
   * This function is called, when a new bad block is detected or if an existing bad block's marker state is updated.
   */
  if(MemAcc_GetBBStrategyOfMemInstance(MemAcc_GetMemInstanceIdxOfSubAddressArea(saaIdx)) == MEMACC_BBM_BBSTRATEGY_SKIPMETHOD)
  {
    MemAcc_BBLUTType bbLutEntry;
    bbLutEntry.PhysicalBlockNrOfBBLUT = physicalBlockNr;
    bbLutEntry.SAAIdxOfBBLUT = saaIdx;
    bbLutEntry.BBMarkerStateOfBBLUT = bbMarkerState;

    /* Update returns FALSE if a item with the given key was not found. If thats the case insert it as new element. */
    if(MemAcc_BBM_UpdateSkipMethodBadBlockMarkerState(bbLutEntry) == FALSE)
    {
      MemAcc_BBM_InsertSkipMethodBadBlock(bbLutEntry);
    }
  }
  else /* MEMACC_BBM_BBSTRATEGY_NONE */
  {
    /* nothing to do */
  }
}

/**********************************************************************************************************************
 * MemAcc_BBM_ProcessInternalJobResult()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 * \spec
 *   requires job != NULL_PTR;
 * \endspec
 */
void MemAcc_BBM_ProcessInternalJobResult(const MemAcc_JobContextType* job)
{
  MemAcc_BBMJobManager_ProcessInternalJobResult(job);
}

#endif /* (MEMACC_BBM_ENABLED == STD_ON) */

#define MEMACC_STOP_SEC_CODE
#include "MemAcc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  VCA JUSTIFICATIONS
 **********************************************************************************************************************/
/* VCA_JUSTIFICATION_BEGIN

\ID VCA_MemAcc_BBLUTIteration
  \DESCRIPTION  Access to MemAcc_BBLUT via indirection over MemAcc_MemInstance. 0 to N indirection.

  \COUNTERMEASURE \R A runtime check verifies that BBStrategy of MemInstance is other than MEMACC_BBM_BBSTRATEGY_NONE.
                     The indirection is a qualified use-case CSL03 of ComStackLib with a 0 to N indirection.

VCA_JUSTIFICATION_END */

/**********************************************************************************************************************
 *  END OF FILE: MemAcc_BBM.c
 *********************************************************************************************************************/
