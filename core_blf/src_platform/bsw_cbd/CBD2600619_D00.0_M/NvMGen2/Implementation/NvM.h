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
/*!        \file  NvM.h
 *        \brief  NvM header file
 *      \details  The NVRAM Manager ensure the data storage and maintenance of NV data.
 *                The NVRAM Manager shall be able to administrate the NV data of an EEPROM
 *                and/or a FLASH EEPROM emulation device.
 *         \unit  NvM_Api
 *********************************************************************************************************************/

#if (!defined NVM_H)
#define NVM_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "NvM_Types.h"
#include "NvM_InternalTypes.h"

#if (NVM_MULTIPARTITION_USAGE_SCENARIO == STD_ON)
# include "Os.h" /* ApplicationType required */
#endif

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* Vendor and module identification */
#define NVM_VENDOR_ID              (30u)
#define NVM_MODULE_ID              (20u)
#define NVM_INSTANCE_ID            (0u)

/* AUTOSAR Software specification version information */
#define NVM_AR_RELEASE_MAJOR_VERSION    (23u)
#define NVM_AR_RELEASE_MINOR_VERSION    (11u)
#define NVM_AR_RELEASE_REVISION_VERSION (0u)

/* Component version information (decimal version of implementation package) */
# define NVM_SW_MAJOR_VERSION       (3u)
# define NVM_SW_MINOR_VERSION       (6u)
# define NVM_SW_PATCH_VERSION       (2u)

/* Development Errors */
#define NVM_E_NO_ERROR             (0x00u) /*!< Used to check if no error occurred - value unequal to any error code. */
#define NVM_E_PARAM_BLOCK_ID       (0x0Au) /*!< Error code: API is called with wrong parameter block ID.              */
#define NVM_E_PARAM_BLOCK_DATA_IDX (0x0Cu) /*!< Error code: API is called with wrong parameter block data.            */
#define NVM_E_PARAM_ADDRESS        (0x0Du) /*!< Error code: API is called with wrong parameter address.               */
#define NVM_E_PARAM_DATA           (0x0Eu) /*!< Error code: API is called with wrong parameter data.                  */
#define NVM_E_PARAM_POINTER        (0x0Fu) /*!< Error code: API is called with wrong parameter pointer.               */
#define NVM_E_BLOCK_WITHOUT_DEFAULTS  (0x11u) /*!< Error code: API is called for block which has no default data configured. */
#define NVM_E_UNINIT               (0x14u) /*!< Error code: API is called when NVRAM manager is not initialized yet.  */
#define NVM_E_BLOCK_PENDING        (0x15u) /*!< Error code: API is called for a block which is pending.               */
#define NVM_E_BLOCK_CONFIG         (0x18u) /*!< Error code: API service invoked with invalid block configuration.     */
#define NVM_E_WRITE_PROTECTED      (0x1Bu) /*!< Error code: API service invoked but block is write protected.         */

/* Runtime Errors */
#define NVM_E_QUEUE_FULL           (0xA0u) /*!< Error code: NvM queue is full so request cannot be queued. */

/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
# define NVM_START_SEC_CODE
# include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * NvM_Init
 *********************************************************************************************************************/
/*! \brief       Initialization function
 *  \details     Service to initialize the NvM.
 *  \pre         Interrupts are disabled.
 *  \pre         Module is uninitialized.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, NVM_PUBLIC_CODE) NvM_Init(void);

/**********************************************************************************************************************
 * NvM_MainFunction
 *********************************************************************************************************************/
/*! \brief       Scheduled function of the NvM.
 *  \details     It processes the requested NvM jobs.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, NVM_PUBLIC_CODE) NvM_MainFunction(void);

#if (NVM_MULTIPARTITION_USAGE_SCENARIO == STD_ON)
/**********************************************************************************************************************
 * NvM_MainFunctionMaster
 *********************************************************************************************************************/
/*! \brief       Scheduled function of the NvM NvService Layer and MultiBlockProcessorFsm.
 *  \details     It processes the requested NvM jobs.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, NVM_PUBLIC_CODE) NvM_MainFunctionMaster(void);
#endif

/**********************************************************************************************************************
 * NvM_GetErrorStatus
 *********************************************************************************************************************/
/*! \brief       Service to read the block dependent error/status information.
 *  \details     -
 *  \param[in]   BlockId               Unique identifier for one NvRAM block descriptor.
 *  \param[out]  RequestResultPtr      Pointer where the result is stored. Parameter must not be NULL.
 *  \return      E_OK: The block dependent error/status information was read successfully.
 *               E_NOT_OK: An error occurred.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, NVM_PUBLIC_CODE) NvM_GetErrorStatus(
    NvM_BlockIdType BlockId,
    P2VAR(NvM_RequestResultType, AUTOMATIC, NVM_APPL_DATA) RequestResultPtr);

/**********************************************************************************************************************
 * NvM_SetRamBlockStatus
 *********************************************************************************************************************/
/*! \brief       Service for setting the RAM block status of a permanent RAM block or the status of
                 the explicit synchronization of a NVRAM block.
 *  \details     -
 *  \param[in]   BlockId               Unique identifier for one NvRAM block descriptor.
 *  \param[in]   BlockChanged          TRUE: Validated the RAM block and mark block as changed.
 *                                     FALSE: Invalidate the RAM block and mark block as unchanged.
 *  \return      E_OK: The status of the permanent RAM block or the explicit synchronization was changed as requested.
 *               E_NOT_OK: An error occurred.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, NVM_PUBLIC_CODE) NvM_SetRamBlockStatus(
        NvM_BlockIdType BlockId,
        boolean BlockChanged);

/**********************************************************************************************************************
 * NvM_GetDataIndex
 *********************************************************************************************************************/
/*! \brief       Service for getting the currently set DataIndex of a dataset NVRAM block.
 *  \details     -
 *  \param[in]   BlockId               Unique identifier for one NvRAM block descriptor.
 *  \param[out]  DataIndexPtr          Pointer to where to store the current dataset index (0..255)
 *  \return      E_OK: The index position has been retrieved successfully.
 *               E_NOT_OK: An error occurred.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, NVM_PUBLIC_CODE) NvM_GetDataIndex(
        NvM_BlockIdType BlockId,
        P2VAR(uint8, AUTOMATIC, NVM_APPL_DATA) DataIndexPtr);

/**********************************************************************************************************************
 * NvM_SetDataIndex
 *********************************************************************************************************************/
/*! \brief       Service for setting the DataIndex of a dataset NVRAM block.
 *  \details     -
 *  \param[in]   BlockId        Unique identifier for one NvRAM block descriptor.
 *  \param[in]   DataIndex      Index position of a NV/ROM block.
 *  \return      E_OK: The index position was set successfully.
 *               E_NOT_OK: An error occurred.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, NVM_PUBLIC_CODE) NvM_SetDataIndex(
        NvM_BlockIdType BlockId,
        uint8 DataIndex);

/**********************************************************************************************************************
 * NvM_SetBlockProtection
 *********************************************************************************************************************/
/*! \brief       Service for setting/resetting the write protection for a NV block.
 *  \details     -
 *  \param[in]   BlockId               Unique identifier for one NvRAM block descriptor.
 *  \param[in]   ProtectionEnabled     TRUE: Write protection shall be enabled
 *                                     FALSE: Write protection shall be disabled
 *  \return      E_OK: The block was enabled/disabled as requested
 *               E_NOT_OK: An error occured.
 *  \pre         Module is initialized.
 *  \context     TASK
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, NVM_PUBLIC_CODE) NvM_SetBlockProtection(
        NvM_BlockIdType BlockId,
        boolean ProtectionEnabled);

/**********************************************************************************************************************
 * NvM_SetBlockLockStatus
 *********************************************************************************************************************/
/*! \brief       Service for setting the lock status of a permanent RAM block or of
 *               the explicit synchronization of a NVRAM block.
 *  \details     -
 *  \param[in]   BlockId               Unique identifier for one NvRAM block descriptor.
 *  \param[in]   BlockLocked           TRUE:  Block Locked for application
 *                                     FALSE: Block Unlocked for application
 *  \pre         Module is initialized.
 *  \context     TASK
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, NVM_PUBLIC_CODE) NvM_SetBlockLockStatus(
        NvM_BlockIdType BlockId,
        boolean BlockLocked);

/**********************************************************************************************************************
 * NvM_CancelJobs
 *********************************************************************************************************************/
/*! \brief       Service to cancel all jobs pending for a NV block.
 *  \details     -
 *  \param[in]   BlockId               Unique identifier for one NvRAM block descriptor.
 *  \return      E_OK: The job was successfully removed from queue.
 *               E_NOT_OK: The job could not be found in the queue.
 *  \pre         Module is initialized.
 *  \context     TASK
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, NVM_PUBLIC_CODE) NvM_CancelJobs(NvM_BlockIdType BlockId);

/**********************************************************************************************************************
 *  NvM_GetVersionInfo
 *********************************************************************************************************************/
/*! \brief       Returns the version information
 *  \details     NvM_GetVersionInfo() returns version information, vendor ID and AUTOSAR module ID of the component.
 *  \param[out]  Versioninfo             Pointer to where to store the version information. Parameter must not be NULL.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, NVM_PUBLIC_CODE) NvM_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, NVM_APPL_DATA) Versioninfo);


/**********************************************************************************************************************
 * NvM_ReadBlock
 *********************************************************************************************************************/
/*! \brief       Service to copy the data of the NV block to its corresponding RAM block.
 *  \details     -
 *  \param[in]   BlockId               Unique identifier for one NvRAM block descriptor.
 *  \param[out]  NvM_DstPtr            Pointer to the RAM data block.
 *  \return      E_OK: request has been accepted.
 *               E_NOT_OK: request has not been accepted.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous FALSE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, NVM_PUBLIC_CODE) NvM_ReadBlock(
        NvM_BlockIdType BlockId,
        P2VAR(void, AUTOMATIC, NVM_APPL_DATA) NvM_DstPtr);

/**********************************************************************************************************************
 * NvM_ReadPRAMBlock
 *********************************************************************************************************************/
/*! \brief       Service to copy the data of the NV block to its corresponding PRAM block.
 *  \details     -
 *  \param[in]   BlockId               Unique identifier for one NvRAM block descriptor.
 *  \return      E_OK: request has been accepted.
 *               E_NOT_OK: request has not been accepted.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous FALSE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, NVM_PUBLIC_CODE) NvM_ReadPRAMBlock(NvM_BlockIdType BlockId);

/**********************************************************************************************************************
 * NvM_WriteBlock
 *********************************************************************************************************************/
/*! \brief       Service to copy the data of the RAM block to its corresponding NV block.
 *  \details     -
 *  \param[in]   BlockId               Unique identifier for one NvRAM block descriptor.
 *  \param[in]   SrcPtr                Pointer to the RAM data block.
 *  \return      E_OK: request has been accepted.
 *               E_NOT_OK: request has not been accepted.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous FALSE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, NVM_PUBLIC_CODE) NvM_WriteBlock(
        NvM_BlockIdType BlockId,
        P2CONST(void, AUTOMATIC, NVM_APPL_DATA) SrcPtr);

/**********************************************************************************************************************
 * NvM_WritePRAMBlock
 *********************************************************************************************************************/
/*! \brief       Service to copy the data of the PRAM block to its corresponding NV block.
 *  \details     -
 *  \param[in]   BlockId               Unique identifier for one NvRAM block descriptor.
 *  \return      E_OK: request has been accepted.
 *               E_NOT_OK: request has not been accepted.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous FALSE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, NVM_PUBLIC_CODE) NvM_WritePRAMBlock(
        NvM_BlockIdType BlockId);

/**********************************************************************************************************************
 * NvM_RestoreBlockDefaults
 *********************************************************************************************************************/
/*! \brief       Service to copy the data of the RAM block to its corresponding NV block.
 *  \details     -
 *  \param[in]   BlockId               Unique identifier for one NvRAM block descriptor.
 *  \param[out]  NvM_DstPtr            Pointer to the RAM data block.
 *  \return      E_OK: request has been accepted.
 *               E_NOT_OK: request has not been accepted.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous FALSE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, NVM_PUBLIC_CODE) NvM_RestoreBlockDefaults(
        NvM_BlockIdType BlockId,
        P2VAR(void, AUTOMATIC, NVM_APPL_DATA) NvM_DstPtr);

/**********************************************************************************************************************
 * NvM_RestorePRAMBlockDefaults
 *********************************************************************************************************************/
/*! \brief       Service to copy the data of the PRAM block to its corresponding NV block.
 *  \details     -
 *  \param[in]   BlockId               Unique identifier for one NvRAM block descriptor.
 *  \return      E_OK: request has been accepted.
 *               E_NOT_OK: request has not been accepted.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous FALSE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, NVM_PUBLIC_CODE) NvM_RestorePRAMBlockDefaults(
        NvM_BlockIdType BlockId);

/**********************************************************************************************************************
 * NvM_InvalidateNvBlock
 *********************************************************************************************************************/
/*! \brief       Service to invalidate a NV block.
 *  \details     -
 *  \param[in]   BlockId               Unique identifier for one NvRAM block descriptor.
 *  \return      E_OK: request has been accepted.
 *               E_NOT_OK: request has not been accepted.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous FALSE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, NVM_PUBLIC_CODE) NvM_InvalidateNvBlock(NvM_BlockIdType BlockId);

/**********************************************************************************************************************
 * NvM_EraseNvBlock
 *********************************************************************************************************************/
/*! \brief       Service to erase a NV block.
 *  \details     -
 *  \param[in]   BlockId               Unique identifier for one NvRAM block descriptor.
 *  \return      E_OK: request has been accepted.
 *               E_NOT_OK: request has not been accepted.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous FALSE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, NVM_PUBLIC_CODE) NvM_EraseNvBlock(NvM_BlockIdType BlockId);

/**********************************************************************************************************************
 * NvM_ReadAll
 *********************************************************************************************************************/
/*! \brief       Initiates a multi block read request.
 *  \details     -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous FALSE
 *********************************************************************************************************************/
FUNC(void, NVM_PUBLIC_CODE) NvM_ReadAll(void);

/**********************************************************************************************************************
 * NvM_WriteAll
 *********************************************************************************************************************/
/*! \brief       Initiates a multi block write request.
 *  \details     -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous FALSE
 *********************************************************************************************************************/
FUNC(void, NVM_PUBLIC_CODE) NvM_WriteAll(void);

/**********************************************************************************************************************
 * NvM_CancelWriteAll
 *********************************************************************************************************************/
/*! \brief       Cancel pending write all job
 *  \details     Request to cancel a pending WriteAll request.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous FALSE
 *********************************************************************************************************************/
FUNC(void, NVM_PUBLIC_CODE) NvM_CancelWriteAll(void);

/**********************************************************************************************************************
 * NvM_KillWriteAll
 *********************************************************************************************************************/
/*! \brief       Kills pending write all job.
 *  \details     Request to kill a pending WriteAll request, i.e. To cancel it destructively (in contrast to
 *               NvM_CancelWriteAll). It shall only called by EcuM (or comparable SW)
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous FALSE
 *********************************************************************************************************************/
FUNC(void, NVM_PUBLIC_CODE) NvM_KillWriteAll(void);

/**********************************************************************************************************************
 * NvM_KillReadAll
 *********************************************************************************************************************/
/*! \brief       Kills an ongoing ReadAll job.
 *  \details     The function signals the request to kill an ongoing ReadAll and returns - the actual killing
 *               will be done by NvM processing.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous FALSE
 *********************************************************************************************************************/
FUNC(void, NVM_PUBLIC_CODE) NvM_KillReadAll(void);

/**********************************************************************************************************************
 * NvM_ValidateAll
 *********************************************************************************************************************/
/*! \brief       Initiates a multi block validate request.
 *  \details     -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous FALSE
 *********************************************************************************************************************/
FUNC(void, NVM_PUBLIC_CODE) NvM_ValidateAll(void);

#if (NVM_MULTIPARTITION_USAGE_SCENARIO == STD_ON)
/**********************************************************************************************************************
 * NvM_GetActiveMultiBlockApplicationId
 *********************************************************************************************************************/
 /*! \brief       Get the current application id of the processing multiblock job.
  *  \details     -
  *  \param[out]  ApplicationId               Current Application Id.
  *  \return      E_OK: request has been accepted.
  *               E_NOT_OK: request has not been accepted or no active partition available due to multiblock job not active.
  *  \pre         -
  *  \context     TASK
  *  \reentrant   FALSE
  *  \synchronous FALSE
  *********************************************************************************************************************/
FUNC(Std_ReturnType, NVM_PUBLIC_CODE) NvM_GetActiveMultiBlockApplicationId(ApplicationType* ApplicationId);
#endif /* NVM_MULTIPARTITION_USAGE_SCENARIO */



# define NVM_STOP_SEC_CODE
# include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  EXCLUSIVE AREA DEFINITION
 **********************************************************************************************************************/
/*!
 * \exclusivearea NvM_NVM_EXCLUSIVE_AREA_0
 *                Ensures consistency while modifying internal variables.
 *                Usage of exclusive area is always done via the following wrapper functions:
 *                - NvM_GlobalUtilityLib_EnterCriticalSection
 *                - NvM_GlobalUtilityLib_ExitCriticalSection
 * \protects      Internal variables, Queue consistency.
 * \usedin
 *                NvM_SetRamBlockStatus
 *                NvM_ReadBlock,
 *                NvM_WriteBlock,
 *                NvM_RestoreBlockDefaults,
 *                NvM_EraseNvBlock,
 *                NvM_InvalidateNvBlock,
 *                NvM_ReadAll,
 *                NvM_WriteAll,
 *                NvM_CancelWriteAll,
 *                NvM_KillWriteAll,
 *                NvM_KillReadAll,
 *                NvM_ServiceFsm_ProvideActiveMultiBlockJob
 *                NvM_ServiceFsm_IdleState_Do,
 *                NvM_ServiceFsm_ProcessMultiBlockServiceState_Do,
 *                NvM_MultiBlockProcessorFsm_GetMultiBlockJob,
 *                NvM_MultiBlockProcessorFsm_ProcessSatellitesState_Entry,
 *                NvM_MultiBlockProcessorFsm_FinalizeMultiBlockJobState_Do
 * \exclude       -
 * \length        SHORT Queue push/pop access, few statements.
 * \endexclusivearea
 */

#endif /* NVM_H */

/**********************************************************************************************************************
 *  END OF FILE: NvM.h
 *********************************************************************************************************************/
