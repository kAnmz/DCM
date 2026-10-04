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
/*!        \file  NvM_GlobalUtilityLib.h
 *        \brief  NvM global utility functions header file.
 *         \unit  NvM_GlobalUtilityLib
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#if (!defined NVM_GLOBALUTILITYLIB_H)
#define NVM_GLOBALUTILITYLIB_H

/***********************************************************************************************************************
 * INCLUDES
 **********************************************************************************************************************/
# include "NvM_Types.h"
# include "NvM_InternalTypes.h"
# include "MemIf.h"
# include "NvM_Cfg.h"


/***********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
# define NVM_START_SEC_CODE
# include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * NvM_GlobalUtilityLib_ConvertMemIfResultToServiceJobResult()
 *********************************************************************************************************************/
/*! \brief       Map given MemIf job result to a NvJob result
 *  \details     -
 *  \param[in]   memIfJobResult MemIf job result to be mapped
 *  \pre         -
 *  \return      Mapped ServiceJobResult result
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(NvM_ServiceJobResultType, NVM_PRIVATE_CODE) NvM_GlobalUtilityLib_ConvertMemIfResultToServiceJobResult(
  const MemIf_JobResultType memIfJobResult);

/**********************************************************************************************************************
 * NvM_GlobalUtilityLib_ConvertServiceJobResultToNvMRequestResult()
 *********************************************************************************************************************/
/*! \brief       Map given service job result to a NvM request result
 *  \details     -
 *  \param[in]   serviceJobResult Service job result to be mapped
 *  \pre         -
 *  \return      Mapped NvM request result
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(NvM_RequestResultType, NVM_PRIVATE_CODE) NvM_GlobalUtilityLib_ConvertServiceJobResultToNvMRequestResult(
  const NvM_ServiceJobResultType serviceJobResult);

/**********************************************************************************************************************
 * NvM_GlobalUtilityLib_ConvertServiceJobResultToSatelliteMultiBlockJobStatus()
 *********************************************************************************************************************/
/*! \brief           Maps given service job result to a satellite multiblock job status
 *  \details         -
 *  \param[in]       serviceJobResult   Service job result to be mapped
 *  \pre             -
 *  \context         TASK
 *  \reentrant       FALSE
 *  \synchronous     TRUE
 *  \return          Mapped request result
 *********************************************************************************************************************/
FUNC(NvM_SatelliteMultiBlockJobStatusType, NVM_PRIVATE_CODE)
NvM_GlobalUtilityLib_ConvertServiceJobResultToSatelliteMultiBlockJobStatus(
  const NvM_ServiceJobResultType serviceJobResult);

/**********************************************************************************************************************
 * NvM_GlobalUtilityLib_IsFlagSet()
 *********************************************************************************************************************/
/*! \brief       Check if the given flag is set or not
 *  \details     -
 *  \param[in]   bitmask  Bitmask to be used for operation
 *  \param[in]   flagPosition Position of flag that is checked
 *  \pre         -
 *  \return      True if flag is set, otherwise false
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(boolean, NVM_PRIVATE_CODE) NvM_GlobalUtilityLib_IsFlagSet(const uint16 bitmask, const uint8 flagPosition);

/**********************************************************************************************************************
 * NvM_GlobalUtilityLib_SetFlag()
 *********************************************************************************************************************/
/*! \brief       Set the given flag
 *  \details     -
 *  \param[in]   bitmask  Bitmask to be used for operation
 *  \param[in]   flagPosition Position of flag that is set
 *  \pre         -
 *  \return      Updated bitmask
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(uint16, NVM_PRIVATE_CODE) NvM_GlobalUtilityLib_SetFlag(const uint16 bitmask, const uint8 flagPosition);

/**********************************************************************************************************************
 *  NvM_GlobalUtilityLib_IsAnyMultiBlockJobRequested()
 *********************************************************************************************************************/
/*! \brief       Check if any multiblock job is requested.
 *  \details     -
 *  \param[in]   multiBlockJobFlag - MultiBlockJob Flag.
 *  \return      True if MultiBlock job is requested, otherwise False.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(boolean, NVM_PRIVATE_CODE) NvM_GlobalUtilityLib_IsAnyMultiBlockJobRequested(
  const NvM_MultiBlockJobFlagType multiBlockJobStatusFlag);

/**********************************************************************************************************************
 * NvM_GlobalUtilityLib_EnterCriticalSection
 *********************************************************************************************************************/
/*! \brief        Invoke the SchM API to enter NvM's critical section.
 *  \details      -
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *  \pre -
 */
FUNC(void, NVM_PRIVATE_CODE) NvM_GlobalUtilityLib_EnterCriticalSection(void);

/**********************************************************************************************************************
 * NvM_GlobalUtilityLib_ExitCriticalSection
 *********************************************************************************************************************/
/*! \brief        Invoke the SchM API to exit NvM's critical section.
 *  \details      -
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *  \pre -
 */
FUNC(void, NVM_PRIVATE_CODE) NvM_GlobalUtilityLib_ExitCriticalSection(void);

#if (NVM_MULTIPARTITION_USAGE_SCENARIO == STD_ON)
/**********************************************************************************************************************
 * NvM_GlobalUtilityLib_GetPartitionId
 *********************************************************************************************************************/
/*! \brief        Gets the partition ID via the partition identifier generated by the CSL.
 *  \details      -
 *  \param[out]   partitionId Partition ID to be returned.
 *  \param[in]    applicationId Application ID used for lookup.
 *  \return       E_OK if ID is found, otherwise E_NOT_OK.
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *  \pre -
 */
FUNC(Std_ReturnType, NVM_PRIVATE_CODE) NvM_GlobalUtilityLib_GetPartitionId(
  NvM_PartitionIdType* partitionId,
  ApplicationType applicationId);

/**********************************************************************************************************************
 * NvM_GlobalUtilityLib_FindOsApplicationId()
 *********************************************************************************************************************/
/*! \brief           Searches configured partitions for the given partition identifier, providing the OS application
 *                   identifier if found.
 *  \details         -
 *  \param[out]      foundApplicationIdPtr     Pointer to be used to assign the found OS application identifier.
 *                                             Only to be used when E_OK is the result.
 *  \param[in]       partitionId               Partition identifier to search with
 *  \pre             -
 *  \context         TASK
 *  \reentrant       FALSE
 *  \synchronous     TRUE
 *  \return          E_OK: Success
 *                   E_NOT_OK: Error
 *********************************************************************************************************************/
FUNC(Std_ReturnType, NVM_PRIVATE_CODE) NvM_GlobalUtilityLib_FindOsApplicationId(
  ApplicationType* foundApplicationIdPtr,
  const NvM_PartitionIdType partitionId);
#endif /* (NVM_MULTIPARTITION_USAGE_SCENARIO == STD_ON) */

/**********************************************************************************************************************
 * NvM_GlobalUtilityLib_CopyDataIntegrityRecord()
 *********************************************************************************************************************/
/*! \brief           Copys data integrity data from one buffer to another buffer according to given
 *                   data integrity setting.
 *  \details         -
 *  \param[in]       dataIntegritySetting    Data Integrity Setting of the block
 *  \param[in,out]   targetBuffer            Target buffer
 *  \param[in]       srcBuffer               Source buffer
 *  \pre             -
 *  \context         TASK
 *  \reentrant       FALSE
 *  \synchronous     TRUE
 *********************************************************************************************************************/
FUNC(void, NVM_PRIVATE_CODE) NvM_GlobalUtilityLib_CopyDataIntegrityRecord(
  const NvM_DataIntegrityType dataIntegritySetting,
    NvM_DataPtrType targetBuffer, NvM_DataConstPtrToConstType srcBuffer);

/**********************************************************************************************************************
 * NvM_GlobalUtilityLib_ResetCrcCompMechanismBuffer()
 *********************************************************************************************************************/
/*! \brief           Resets the CRC comp mechanism buffer according to the given data integrity setting.
 *  \details         -
 *  \param[in,out]  crcCompMechanismBuffer    CRC comp mechanism buffer
 *  \param[in]       dataIntegritySetting      Data Integrity Setting of the block
 *  \pre             -
 *  \context         TASK
 *  \reentrant       FALSE
 *  \synchronous     TRUE
 *********************************************************************************************************************/
FUNC(void, NVM_PRIVATE_CODE) NvM_GlobalUtilityLib_ResetCrcCompMechanismBuffer(
  const NvM_DataPtrType crcCompMechanismBuffer,
  const NvM_DataIntegrityType dataIntegritySetting);
  
/**********************************************************************************************************************
 * NvM_GlobalUtilityLib_CompareDataIntegrityRecords()
 *********************************************************************************************************************/
/*! \brief           Bytewise comparison of data integrity data from one buffer to another buffer according to given
 *                   data integrity setting.
 *  \details         -
 *  \param[in]       dataIntegritySetting    Data Integrity Setting of the block
 *  \param[in]       buffer1                 First buffer to be compared
 *  \param[in]       buffer2                 Second buffer to be compared
 *  \pre             -
 *  \context         TASK
 *  \reentrant       FALSE
 *  \synchronous     TRUE
 *  \return          TRUE if CRC16/CRC32 data integrity records are identical, otherwise FALSE
 *********************************************************************************************************************/
FUNC(boolean, NVM_PRIVATE_CODE) NvM_GlobalUtilityLib_CompareDataIntegrityRecords(
  const NvM_DataIntegrityType dataIntegritySetting,
  NvM_DataConstPtrToConstType buffer1,
  NvM_DataConstPtrToConstType buffer2);

/**********************************************************************************************************************
 * NvM_GlobalUtilityLib_GetNvDataLength()
 *********************************************************************************************************************/
/*! \brief           Return the size of the Payload + DataIntegrityRecord configured for the given BlockDescriptor
 *  \details         -
 *  \param[in]       descPtr    Pointer to a BlockDescriptor
 *  \pre             -
 *  \context         TASK
 *  \reentrant       FALSE
 *  \synchronous     TRUE
 *  \return          Size of the Payload + DataIntegrityRecord, Zero if no strategy configured
 *********************************************************************************************************************/
FUNC(uint16, NVM_PRIVATE_CODE) NvM_GlobalUtilityLib_GetNvDataLength(const NvM_BlockDescriptorPtrType descPtr);

/**********************************************************************************************************************
 * NvM_GlobalUtilityLib_FindBlockDescriptorLookupTableId()
 *********************************************************************************************************************/
/*! \brief           Searches configured BlockDescriptors for a matching NvramBlockIdentifier and provides the index
 *                   if an entity was found.
 *  \details         The provided index of NvM_BlockDescriptor[] is the "internal blockID".
 *  \param[in]       externalBlockId                      External blockID (NvMConf_NvMBlockDescriptor_*) to search for.
 *  \param[in,out]   outBlockDescriptorLookupTableIdPtr   Index of BlockDescriptor array, so called "internal blockId"
 *  \pre             -
 *  \context         TASK
 *  \reentrant       FALSE
 *  \synchronous     TRUE
 *  \return          TRUE:  Block Descriptor Lookup Table ID was found
 *                   FALSE: No ID found, outBlockDescriptorLookupTableIdPtr MUST NOT be used
 *********************************************************************************************************************/
FUNC(boolean, NVM_PRIVATE_CODE) NvM_GlobalUtilityLib_FindBlockDescriptorLookupTableId(
  const NvM_BlockIdType externalBlockId,
  NvM_BlockDescriptorLookupTableIdType* outBlockDescriptorLookupTableIdPtr);

/**********************************************************************************************************************
 * NvM_GlobalUtilityLib_GetBlockManagementInfo()
 *********************************************************************************************************************/
/*! \brief           Return the block management information
 *  \details         Depending on whether the given block is a DCM block,
 *                   either the DCM data or block descriptor data is returned.
 *  \param[in]       externalBlockId                 External Block Id of block
 *  \param[in]       blockDescriptorLookupTableId    Block Descriptor Lookup Table ID
 *  \param[in]       partitionId                     Current Partition ID
 *  \pre             -
 *  \return          DCM Block: Return DCM block management info data pointer
 *                   No DCM Block: Return block management info pointer of block descriptor
 *  \context         TASK
 *  \reentrant       FALSE
 *  \synchronous     TRUE
 *  \return          Size of the Payload + DataIntegrityRecord, Zero if no strategy configured
 *********************************************************************************************************************/
FUNC(NvM_BlockManagementInformationPtrType, NVM_PRIVATE_CODE) NvM_GlobalUtilityLib_GetBlockManagementInfo(
  const NvM_BlockIdType externalBlockId,
  const NvM_BlockDescriptorLookupTableIdType blockDescriptorLookupTableId,
  const NvM_PartitionIdType partitionId);

#if (NVM_MULTIPARTITION_USAGE_SCENARIO == STD_ON)
/**********************************************************************************************************************
 * NvM_GlobalUtilityLib_GetAccessIndexForInternalMasterBuffers()
 *********************************************************************************************************************/
/*! \brief           Return the access index for the internal master buffers
 *  \details         -
 *  \param[in]       expectedPartitionId             Expected Partition ID
 *  \pre             -
 *  \return
 *  \context         TASK
 *  \reentrant       FALSE
 *  \synchronous     TRUE
 *  \return          Access index for the internal master buffers
 *********************************************************************************************************************/
FUNC(NvM_InternalMasterBuffersStructIterType, NVM_PRIVATE_CODE)
  NvM_GlobalUtilityLib_GetAccessIndexForInternalMasterBuffers(
  const NvM_PartitionIdentifiersIterType expectedPartitionId);

/**********************************************************************************************************************
 * NvM_GlobalUtilityLib_GetAccessIndexForMasterSatellitePorts_SingleBlockJob()
 *********************************************************************************************************************/
/*! \brief           Return the access index for the internal master satellite ports for a single block job
 *  \details         -
 *  \param[in]       expectedPartitionId             Expected Partition ID
 *  \pre             -
 *  \return
 *  \context         TASK
 *  \reentrant       FALSE
 *  \synchronous     TRUE
 *  \return          Access index for the internal master satellite ports for a single block job
 *********************************************************************************************************************/
FUNC(NvM_MasterSatellitePortsStruct_SingleBlockJobIterType, NVM_PRIVATE_CODE)
  NvM_GlobalUtilityLib_GetAccessIndexForMasterSatellitePorts_SingleBlockJob(
  const NvM_PartitionIdentifiersIterType expectedPartitionId);

/**********************************************************************************************************************
 * NvM_GlobalUtilityLib_GetAccessIndexForMasterSatellitePorts_MultiBlockJob()
 *********************************************************************************************************************/
/*! \brief           Return the access index for the internal master satellite ports for a multi block job
 *  \details         -
 *  \param[in]       expectedPartitionId             Expected Partition ID
 *  \pre             -
 *  \return
 *  \context         TASK
 *  \reentrant       FALSE
 *  \synchronous     TRUE
 *  \return          Access index for the internal master satellite ports for a multi block job
 *********************************************************************************************************************/
FUNC(NvM_MasterSatellitePortsStruct_MultiBlockJobIterType, NVM_PRIVATE_CODE)
  NvM_GlobalUtilityLib_GetAccessIndexForMasterSatellitePorts_MultiBlockJob(
  const NvM_PartitionIdentifiersIterType expectedPartitionId);

#if (NVM_DEM_ERROR_REPORT == STD_ON)
/**********************************************************************************************************************
 * NvM_GlobalUtilityLib_GetAccessIndexForMasterSatellitePorts_ErrorCountersMirror()
 *********************************************************************************************************************/
/*! \brief           Return the access index for the internal master satellite ports for the error counters mirror
 *  \details         -
 *  \param[in]       expectedPartitionId             Expected Partition ID
 *  \pre             -
 *  \return
 *  \context         TASK
 *  \reentrant       FALSE
 *  \synchronous     TRUE
 *  \return          Access index for the internal master satellite ports for theerror counters mirror
 *********************************************************************************************************************/
FUNC(NvM_MasterSatellitePortsStruct_ErrorCountersMirrorIterType, NVM_PRIVATE_CODE)
  NvM_GlobalUtilityLib_GetAccessIndexForMasterSatellitePorts_ErrorCountersMirror(
  const NvM_PartitionIdentifiersIterType expectedPartitionId);
#endif  /* (NVM_DEM_ERROR_REPORT == STD_ON) */
#endif  /* (NVM_MULTIPARTITION_USAGE_SCENARIO == STD_ON) */

# define NVM_STOP_SEC_CODE
# include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif  /* NVM_GLOBALUTILITYLIB_H */

/***********************************************************************************************************************
 *  END OF FILE: NvM_GlobalUtilityLib.h
 **********************************************************************************************************************/
