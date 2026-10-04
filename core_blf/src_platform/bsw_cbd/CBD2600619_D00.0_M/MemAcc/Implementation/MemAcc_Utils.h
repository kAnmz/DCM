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
/*!        \file  MemAcc_Utils.h
 *        \brief  MemAcc_Utils header file
 *      \details  Implementation of the unit Utils.
 *                The unit is for the collection of shared functionality.

 *         \unit  Utils
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/
#ifndef MEMACC_UTILS_H
# define MEMACC_UTILS_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "MemAcc_InternalTypes.h"

/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

# define MEMACC_START_SEC_CODE
# include "MemAcc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * MemAcc_Utils_GetLowerLayerIndexOfHwId()
 *********************************************************************************************************************/
/*!
 *  \brief         Gets the lowerlayer index for a given hardware ID.
 *  \details       -
 *  \param[in]     hwId - Hardware ID
 *  \return        Index of the lower layer table that targets the given hardware ID.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 */
MemAcc_SizeOfCLowerLayerType MemAcc_Utils_GetLowerLayerIndexOfHwId(MemAcc_HwIdType hwId);

/**********************************************************************************************************************
 * MemAcc_Utils_IsInternalJob()
 *********************************************************************************************************************/
/*!
 *  \brief         Checks if the job classification is for an internal job.
 *  \details       -
 *  \param[in]     jobClassification Job classification to check.
 *  \return        TRUE if it is an internal job, FALSE otherwise.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 */
boolean MemAcc_Utils_IsInternalJob(MemAcc_JobClassificationType jobClassification);

#if (MEMACC_BBM_ENABLED == STD_ON) /* COV_MSR_UT_OPTIONAL_UNIT */

/**********************************************************************************************************************
 * MemAcc_Utils_GetAddrAreaIdxOfSubAddrAreaIdx()
 *********************************************************************************************************************/
/*!
 *  \brief         Gets the address area index for a given sub-address area index.
 *  \details       -
 *  \param[in]     saaIdx Index of the sub-address area.
 *  \return        Index of the address area.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 */
MemAcc_AddressAreaIndexType MemAcc_Utils_GetAddrAreaIdxOfSubAddrAreaIdx(MemAcc_SubAddressAreaIndexType saaIdx);

/**********************************************************************************************************************
 * MemAcc_Utils_GetPhysicalBlockNr()
 *********************************************************************************************************************/
/*!
 *  \brief         Gets the physical block number for a given sub-address area index and physical address.
 *  \details       -
 *  \param[in]     saaIdx Index of the sub-address area.
 *  \param[in]     physicalAddress Physical address to get the block number for.
 *  \return        Calculated physical block number.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 */
MemAcc_NumberOfSectorsOfSubAddressAreaType MemAcc_Utils_GetPhysicalBlockNr(
  MemAcc_SubAddressAreaIndexType saaIdx,
  MemAcc_AddressType physicalAddress);

/**********************************************************************************************************************
 * MemAcc_Utils_GetPhysicalAddress()
 *********************************************************************************************************************/
/*!
 *  \brief         Gets the physical address for a given sub-address area index and physical block number.
 *  \details       -
 *  \param[in]     saaIdx Index of the sub-address area.
 *  \param[in]     physicalBlockNr Physical block number to get the address for.
 *  \return        Physical address.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 */
MemAcc_AddressType MemAcc_Utils_GetPhysicalAddress(
  MemAcc_SubAddressAreaIndexType saaIdx,
  MemAcc_NumberOfSectorsOfSubAddressAreaType physicalBlockNr);

#endif /* MEMACC_BBM_ENABLED */

/**********************************************************************************************************************
 * MemAcc_Utils_GetSubAddrAreaIndexOfAddress()
 *********************************************************************************************************************/
/*! \brief         Determines the index in Sub Address Area array.
 *  \details       -
 *  \param[in]     addressAreaIdx Index of the address area
 *  \param[in]     logicalAddress Address in logical address space
 *  \return        Sub Address Area Index.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
MemAcc_SubAddressAreaIndexType MemAcc_Utils_GetSubAddrAreaIndexOfAddress(
  MemAcc_AddressAreaIndexType addressAreaIdx,
  MemAcc_AddressType logicalAddress);

/**********************************************************************************************************************
 * MemAcc_Utils_GetIndexOfAddrAreaId()
 *********************************************************************************************************************/
/*! \brief         Determines the index of an Address Area Id in MemAcc_AddressArea
 *  \details       -
 *  \param[in]     addressAreaId Numeric identifier of address area
 *  \return        MemAcc_AddressAreaIndexType
 *  \pre           IsAddrAreaIdValid must be invoked with the param and return TRUE
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
MemAcc_AddressAreaIndexType MemAcc_Utils_GetIndexOfAddrAreaId(MemAcc_AddressAreaIdType addressAreaId);

/**********************************************************************************************************************
 * MemAcc_Utils_GetSubAddrAreaIndexOfHwId()
 *********************************************************************************************************************/
/*! \brief         Determines the index of a Hardware Id in MemAcc_SubAddressArea
 *  \details       -
 *  \param[in]     addressAreaIdx Index of the address area
 *  \param[in]     hwId Numeric identifier of Mem hardware instance
 *  \return        MemAcc_AddressAreaIndexType
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
MemAcc_SubAddressAreaIndexType MemAcc_Utils_GetSubAddrAreaIndexOfHwId(
  MemAcc_AddressAreaIndexType addressAreaIdx,
  MemAcc_HwIdType hwId);

/**********************************************************************************************************************
 * MemAcc_Utils_GetNumberOfJobStepRetries()
 *********************************************************************************************************************/
/*! \brief         Returns the number of retries for a job step in a sub address area.
 *  \details       -
 *  \param[in]     subAddrAreaIdx Index of the sub address area.
 *  \param[in]     jobType JobType of the job.
 *  \return        The number of retries
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
MemAcc_JobStepRetryCounterType MemAcc_Utils_GetNumberOfJobStepRetries(
  MemAcc_SubAddressAreaIndexType subAddrAreaIdx,
  MemAcc_JobType jobType);

/**********************************************************************************************************************
 * MemAcc_Utils_GetSAAIndicesForAddressRange()
 *********************************************************************************************************************/
/*! \brief         Calculates the sub address area index for a address range referenced by Address and Length.
                   The function updates the values of the Address and Length for the calculation of the next SAA:
                   Address to the start address of the next SAA, Length to the remaining length.
                   The function is intended to be called in a loop as long as it returns TRUE to get all SAA indices.
 *  \details       -
 *  \param[in]     AddressAreaIndex Index of the address area.
 *  \param[in,out] Address Pointer to the address.
 *  \param[in,out] Length Pointer to the length.
 *  \param[in,out] SubAddressAreaIndex Pointer to the SubAddressAreaIndex.
 *  \return        TRUE if valid value is written into SubAddressAreaIndex pointer, otherwise
 *                 FALSE.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
boolean MemAcc_Utils_GetSAAIndicesForAddressRange(
  MemAcc_AddressAreaIndexType AddressAreaIndex,
  MemAcc_AddressType* Address,
  MemAcc_LengthType* Length,
  MemAcc_SubAddressAreaIndexType* SubAddressAreaIndex);

# define MEMACC_STOP_SEC_CODE
# include "MemAcc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* MEMACC_UTILS_H */

/**********************************************************************************************************************
 *  END OF FILE: MemAcc_Utils.h
 *********************************************************************************************************************/
