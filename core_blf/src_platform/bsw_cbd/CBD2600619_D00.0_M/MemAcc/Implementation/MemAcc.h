/***********************************************************************************************************************
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
/*!        \file  MemAcc.h
 *        \brief  MemAcc header file
 *      \details  Header file of the MemAcc component interface.
 *         \unit  General
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author      Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  00.01.00  2022-12-02  virbmz      MWDG-7638     Create the MemAcc interface.
 *  00.01.00  2023-01-30  virbmz      MWDG-7786     MemAcc: Asynchronous Job Handling
 *  00.01.00  2023-02-23  virbmz      MWDG-7794     MemAcc: Implement Error Handling
 *  00.01.00  2023-02-23  virbka      MWDG-7792     MemAcc: Create MemAb unit
 *  00.02.00  2023-03-23  sstemplinge MWDG-7949     MemAcc: Provide Job End Notification
 *  00.02.00  2023-04-20  virbmz      MWDG-7939     MemAcc: Refactoring post-MVP
 *  00.02.00  2023-05-23  sstemplinge MWDG-8150     MemAcc: Remove the infix 30_SyncMemory from all work packages
                                                            of the component
 *  00.02.00  2023-06-28  virbmz      MWDG-7941     MemAcc: Support Multiple Users
 *  01.00.00  2023-08-18  sstemplinge MWDG-7945     MemAcc: Provide Hw Specific service
 *  01.01.00  2023-08-28  sstemplinge MWDG-8401     MemAcc: Provide Compare service
 *  01.01.00  2023-09-07  sstemplinge MWDG-7947     MemAcc: Provide synchronous Getter-APIs
 *  01.01.00  2023-09-07  sstemplinge MEMSLP-8582   MemAcc: Support Mem Driver indirect Mode
 *  main-1    2023-11-07  smacht      MEMSLP-7953   Change history is maintained in the global ChangeHistory.txt file starting with this release.
 **********************************************************************************************************************/

#if !defined (MEMACC_H)
# define MEMACC_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "MemAcc_Cfg.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/* Published information */

/* AUTOSAR Software specification version information */
# define MEMACC_AR_RELEASE_MAJOR_VERSION            (23u)
# define MEMACC_AR_RELEASE_MINOR_VERSION            (11u)
# define MEMACC_AR_RELEASE_REVISION_VERSION         (0u)

/* ----- Component version information (decimal version of ALM implementation package) ----- */
# define MEMACC_SW_MAJOR_VERSION                    (3u)
# define MEMACC_SW_MINOR_VERSION                    (5u)
# define MEMACC_SW_PATCH_VERSION                    (0u)

/* ----- API service IDs ----- */
# define MEMACC_SID_INIT                 (0x01u)     /*!< Service ID: MemAcc_Init() */
# define MEMACC_SID_GETVERSIONINFO       (0x02u)     /*!< Service ID: MemAcc_GetVersionInfo() */
# define MEMACC_SID_MAIN                 (0x03u)     /*!< Service ID: MemAcc_MainFunction() */
# define MEMACC_SID_CANCEL               (0x04u)     /*!< Service ID: MemAcc_Cancel() */
# define MEMACC_SID_GETJOBRESULT         (0x05u)     /*!< Service ID: MemAcc_GetJobResult() */
# define MEMACC_SID_GETMEMORYINFO        (0x06u)     /*!< Service ID: MemAcc_GetMemoryInfo() */
# define MEMACC_SID_GETPROCESSEDLENGTH   (0x07u)     /*!< Service ID: MemAcc_GetProcessedLength() */
# define MEMACC_SID_GETJOBINFO           (0x08u)     /*!< Service ID: MemAcc_GetJobInfo() */
# define MEMACC_SID_READ                 (0x09u)     /*!< Service ID: MemAcc_Read() */
# define MEMACC_SID_WRITE                (0x0au)     /*!< Service ID: MemAcc_Write() */
# define MEMACC_SID_ERASE                (0x0bu)     /*!< Service ID: MemAcc_Erase() */
# define MEMACC_SID_COMPARE              (0x0cu)     /*!< Service ID: MemAcc_Compare() */
# define MEMACC_SID_BLANKCHECK           (0x0du)     /*!< Service ID: MemAcc_BlankCheck() */
# define MEMACC_SID_HWSPECIFICSERVICE    (0x0eu)     /*!< Service ID: MemAcc_HwSpecificService() */
# define MEMACC_SID_GETJOBSTATUS         (0x10u)     /*!< Service ID: MemAcc_GetJobStatus() */
# define MEMACC_SID_REQUESTLOCK          (0x11u)     /*!< Service ID: MemAcc_RequestLock() */
# define MEMACC_SID_RELEASELOCK          (0x12u)     /*!< Service ID: MemAcc_ReleaseLock() */
# define MEMACC_SID_DEINIT               (0x13u)     /*!< Service ID: MemAcc_DeInit() */
# define MEMACC_SID_ACTIVATEMEM          (0x14u)     /*!< Service ID: MemAcc_ActivateMem() */
# define MEMACC_SID_DEACTIVATEMEM        (0x15u)     /*!< Service ID: MemAcc_DeactivateMem() */


/* ----- Modes ----- */
# define MEMACC_UNINIT         (0x00u)
# define MEMACC_INIT           (0x01u)
/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
# define MEMACC_START_SEC_CODE
# include "MemAcc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  MemAcc_InitMemory
 **********************************************************************************************************************/
/*! \brief       Initialization for *_INIT_*-variables
 *  \details     Service to initialize module global variables at power up. This function initializes the
 *               variables in *_INIT_* sections. Used in case they are not initialized by the startup code.
 *  \pre         Module is uninitialized.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 **********************************************************************************************************************/
void MemAcc_InitMemory(void);


/**********************************************************************************************************************
 * MemAcc_Init
 *********************************************************************************************************************/
/*! \brief       Initialization function.
 *  \details     This function initializes the module MemAcc. It initializes all variables and sets the
 *               module state to initialized.
 *  \param[in]   configPtr       - Pointer to the MemACC config.
 *  \pre         MemAcc_InitMemory has been called.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \spec
 *    requires configPtr != NULL_PTR;
 *  \endspec
 *********************************************************************************************************************/
void MemAcc_Init(const MemAcc_ConfigType* configPtr);

/**********************************************************************************************************************
 * MemAcc_DeInit
 *********************************************************************************************************************/
/*! \brief       Deinitialization function.
 *  \details     Deinitialization function of the module MemAcc.
 *               The service deinitializes the MemAcc modules internal states.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
void MemAcc_DeInit(void);

/**********************************************************************************************************************
 * MemAcc_Cancel
 *********************************************************************************************************************/
/*! \brief       Mark a queued or running job for a given adress area to be canceled.
 *  \details     The cancellation of queued jobs happens during the next MainFunction cycle.
 *               The cancellation of running jobs happens upon job step completion.
 *  \param[in]   addressAreaId        - Numeric identifier of address area.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   TRUE (Conditionally, for different addressAreaId)
 *  \synchronous FALSE
 *********************************************************************************************************************/
void MemAcc_Cancel (
MemAcc_AddressAreaIdType addressAreaId);

/**********************************************************************************************************************
 * MemAcc_Read
 *********************************************************************************************************************/
/*! \brief       Read function.
 *  \details     This function triggers a read job to copy data from the source address into the referenced destination
 *               data buffer.
 *  \param[in]   addressAreaId        - Numeric identifier of address area.
 *  \param[in]   sourceAddress        - Read address in logical address space.
 *  \param[out]  destinationDataPtr   - Application pointer to buffer to read to.
 *  \param[in]   length               - Read length in bytes (aligned to read page size).
 *  \return      E_OK: The requested job has been accepted by the module.
 *               E_NOT_OK: The requested job has not been accepted by the module.
 *               E_MEM_SERVICE_NOT_AVAIL:  The underlying Mem driver service function is not available.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   TRUE (Conditionally, for different addressAreaId)
 *  \synchronous FALSE
 *  \spec
 *    requires destinationDataPtr != NULL_PTR;
 *    requires $lengthOf(destinationDataPtr) >= length;
 *  \endspec
 *********************************************************************************************************************/
Std_ReturnType MemAcc_Read (
MemAcc_AddressAreaIdType addressAreaId,
MemAcc_AddressType sourceAddress,
MemAcc_DataType* destinationDataPtr,
MemAcc_LengthType length);

/**********************************************************************************************************************
 * MemAcc_Write
 *********************************************************************************************************************/
/*! \brief       Write function.
 *  \details     This function triggers a write job to store the passed data to the provided address area with given
 *               address and length.
 *  \param[in]   addressAreaId        - Numeric identifier of address area.
 *  \param[in]   targetAddress        - Write address in logical address space.
 *  \param[in]   sourceDataPtr        - Source data pointer (aligned to MemAccBufferAlignmentValue).
 *  \param[in]   length               - Write length in bytes (aligned to page size).
 *  \return      E_OK: The requested job has been accepted by the module.
 *               E_NOT_OK: The requested job has not been accepted by the module.
 *               E_MEM_SERVICE_NOT_AVAIL:  The underlying Mem driver service function is not available.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   TRUE (Conditionally, for different addressAreaId)
 *  \synchronous FALSE
 *  \spec
 *    requires sourceDataPtr != NULL_PTR;
 *  \endspec
 *********************************************************************************************************************/
Std_ReturnType MemAcc_Write (
MemAcc_AddressAreaIdType addressAreaId,
MemAcc_AddressType targetAddress,
const MemAcc_DataType* sourceDataPtr,
MemAcc_LengthType length);

/**********************************************************************************************************************
 * MemAcc_Erase
 *********************************************************************************************************************/
/*! \brief       Erase function.
 *  \details     This function triggers an erase job of the given area defined by targetAddress and length.
 *  \param[in]   addressAreaId        - Numeric identifier of address area.
 *  \param[in]   targetAddress        - Erase address in logical address space (aligned to sector size).
 *  \param[in]   length               - Erase length in bytes (aligned to sector size).
 *  \return      E_OK: The requested job has been accepted by the module.
 *               E_NOT_OK: The requested job has not been accepted by the module.
 *               E_MEM_SERVICE_NOT_AVAIL:  The underlying Mem driver service function is not available.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   TRUE (Conditionally, for different addressAreaId)
 *  \synchronous FALSE
 *********************************************************************************************************************/
Std_ReturnType MemAcc_Erase (
MemAcc_AddressAreaIdType addressAreaId,
MemAcc_AddressType targetAddress,
MemAcc_LengthType length);

#if (MEMACC_COMPAREAPI_ENABLED == STD_ON)

/**********************************************************************************************************************
 * MemAcc_Compare
 *********************************************************************************************************************/
/*! \brief       Compare function.
 *  \details     This function triggers an read job of the given area defined by sourceAddress and Length, and compares
                 it to content passed in dataPtr.
 *  \param[in]   addressAreaId        - Numeric identifier of address area.
 *  \param[in]   sourceAddress        - Compare address in logical address space.
 *  \param[in]   dataPtr              - Pointer to user data which shall be compared to data in memory.
 *  \param[in]   length               - Compare length in bytes.
 *  \return      E_OK: The requested job has been accepted by the module.
 *               E_NOT_OK: The requested job has not been accepted by the module.
 *               E_MEM_SERVICE_NOT_AVAIL:  The underlying Mem driver service function is not available.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   TRUE (Conditionally, for different addressAreaId)
 *  \synchronous FALSE
 *  \spec
 *    requires dataPtr != NULL_PTR;
 *  \endspec
 *********************************************************************************************************************/
Std_ReturnType MemAcc_Compare (
MemAcc_AddressAreaIdType addressAreaId,
MemAcc_AddressType sourceAddress,
const MemAcc_DataType* dataPtr,
MemAcc_LengthType length);

#endif /* MEMACC_COMPAREAPI_ENABLED */

/**********************************************************************************************************************
 * MemAcc_BlankCheck
 *********************************************************************************************************************/
/*! \brief       BlankCheck function.
 *  \details     This function checks if the passed address space is blank, i.e. erased and writeable.
 *  \param[in]   addressAreaId        - Numeric identifier of address area.
 *  \param[in]   targetAddress        - Blank check address in logical address space.
 *  \param[in]   length               - Blank check length in bytes.
 *  \return      E_OK: The requested job has been accepted by the module.
 *               E_NOT_OK: The requested job has not been accepted by the module.
 *               E_MEM_SERVICE_NOT_AVAIL:  The underlying Mem driver service function is not available.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   TRUE (Conditionally, for different addressAreaId)
 *  \synchronous FALSE
 *********************************************************************************************************************/
Std_ReturnType MemAcc_BlankCheck (
MemAcc_AddressAreaIdType addressAreaId,
MemAcc_AddressType targetAddress,
MemAcc_LengthType length);

/**********************************************************************************************************************
 * MemAcc_HwSpecificService
 *********************************************************************************************************************/
/*! \brief       HwSpecificService function.
 *  \details     This function triggers a hardware specific job request.
 *  \param[in]   addressAreaId        - Numeric identifier of address area.
 *  \param[in]   hwId                 - Unique numeric memory driver identifier.
 *  \param[in]   hwServiceId          - Hardware specific service request identifier for dispatching the request.
 *  \param[in,out] dataPtr              - Data pointer pointing to the job buffer. Value can be NULL_PTR, if not needed.
 *                                      If dataPtr is used by the hardware specific service, the pointer must be valid
 *                                      until the job completed.
 *  \param[in,out] lengthPtr            - Size pointer of the data passed by dataPtr. Can be NULL_PTR if dataPtr is also
 *                                      NULL_PTR.
 *  \return      E_OK: The requested job has been accepted by the module.
 *               E_NOT_OK: The requested job has not been accepted by the module.
 *               E_MEM_SERVICE_NOT_AVAIL:  The underlying Mem driver service function is not available.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   TRUE (Conditionally, for different addressAreaId)
 *  \synchronous FALSE
 *  \spec
 *    requires dataPtr != NULL_PTR;
 *    requires lengthPtr != NULL_PTR;
 *    requires $lengthOf(dataPtr) >= *lengthPtr;
 *  \endspec
 *********************************************************************************************************************/
Std_ReturnType MemAcc_HwSpecificService (
MemAcc_AddressAreaIdType addressAreaId,
MemAcc_HwIdType hwId,
MemAcc_MemHwServiceIdType hwServiceId,
MemAcc_DataType* dataPtr,
MemAcc_LengthType* lengthPtr);

/**********************************************************************************************************************
 * MemAcc_RequestLock
 *********************************************************************************************************************/
/*! \brief       RequestLock function.
 *  \details     This function requests an access lock to the underlying Mem driver instances referenced by address and
                 length.
 *  \param[in]   addressAreaId           - Numeric identifier of address area.
 *  \param[in]   address                 - Logical start address of the address area to identify the Mem driver
 *                                         instances to be locked.
 *  \param[in]   length                  - Length of the address area to identify the Mem driver instances to be locked.
 *  \param[in]   lockNotificationFctPtr  - Pointer to the callback function to be notified once the address
 *                                         area lock was successfully acquired.
 *  \return      E_OK: The requested job has been accepted by the module.
 *               E_NOT_OK: The requested job has not been accepted by the module.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   TRUE (Conditionally, for different addressAreaId)
 *  \synchronous FALSE
 *********************************************************************************************************************/
Std_ReturnType MemAcc_RequestLock (
MemAcc_AddressAreaIdType addressAreaId,
MemAcc_AddressType address,
MemAcc_LengthType length,
MemAcc_ApplicationLockNotificationType lockNotificationFctPtr);

/**********************************************************************************************************************
 * MemAcc_ReleaseLock
 *********************************************************************************************************************/
/*! \brief       ReleaseLock function.
 *  \details     This function releases an access lock to the underlying Mem driver instances referenced by address and
                 length.
 *  \param[in]   addressAreaId     - Numeric identifier of address area.
 *  \param[in]   address           - Logical start address to identify lock area.
 *  \param[in]   length            - Length to identify lock area.
 *
 *  \return      E_OK: The requested job has been accepted by the module.
 *               E_NOT_OK: The requested job has not been accepted by the module.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   TRUE (Conditionally, for different addressAreaId)
 *  \synchronous TRUE
 *********************************************************************************************************************/
Std_ReturnType MemAcc_ReleaseLock (
MemAcc_AddressAreaIdType addressAreaId,
MemAcc_AddressType address,
MemAcc_LengthType length);

/**********************************************************************************************************************
 * MemAcc_GetVersionInfo
 *********************************************************************************************************************/
/*! \brief       GetVersionInfo function.
 *  \details     This function retrieves the version information of the MemAcc module.
 *  \param[out]  versionInfoPtr        - Pointer to where to store the version information of this module.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \spec
 *    requires versionInfoPtr != NULL_PTR;
 *  \endspec
 *********************************************************************************************************************/
void MemAcc_GetVersionInfo (
Std_VersionInfoType* versionInfoPtr);

/**********************************************************************************************************************
 * MemAcc_GetJobResult
 *********************************************************************************************************************/
/*! \brief       GetJobResult function.
 *  \details     This function returns the consolidated job result of the address area referenced by addressAreaId.
 *  \param[in]   addressAreaId        - Numeric identifier of address area.
 *  \return      MEMACC_OK: The last job was finished successfully.
 *               MEMACC_FAILED: The last job resulted in unspecific failure, the job was not completed.
 *               MEMACC_INCONSISTENT: The results of the last job did not meet the expected result.
 *               MEMACC_CANCELED: The last MemAcc job was canceled.
 *               MEMACC_ECC_UNCORRECTED: The last memory operation returned an uncorrectable ECC error.
 *               MEMACC_ECC_CORRECTED: The last memory operation returned a correctable ECC error.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
MemAcc_JobResultType MemAcc_GetJobResult (
MemAcc_AddressAreaIdType addressAreaId);

/**********************************************************************************************************************
 * MemAcc_GetJobStatus
 *********************************************************************************************************************/
/*! \brief       GetJobStatus function.
 *  \details     This function returns the status of the MemAcc job referenced by addressAreaId.
 *  \param[in]   addressAreaId        - Numeric identifier of address area.
 *  \return      MEMACC_JOB_IDLE:    MemAcc is not processing a job request.
 *               MEMACC_JOB_PENDING: MemAcc is currently processing a job request.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
MemAcc_JobStatusType MemAcc_GetJobStatus (
MemAcc_AddressAreaIdType addressAreaId);

/**********************************************************************************************************************
 * MemAcc_GetMemoryInfo
 *********************************************************************************************************************/
/*! \brief       GetMemoryInfo function.
 *  \details     This function retrieves the physical memory device information of a specific address area.
 *  \param[in]   addressAreaId   - Numeric identifier of address area.
 *  \param[in]   address         - Address in logical address space from which corresponding memory device information
 *                                 shall be retrieved.
 *  \param[out]  memoryInfoPtr   - Destination memory pointer to store the memory device information.
 *  \return      E_OK:     The requested addressAreaId and address are valid.
 *               E_NOT_OK: The requested addressAreaId and address are invalid.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \spec
 *    requires memoryInfoPtr != NULL_PTR;
 *  \endspec
 *********************************************************************************************************************/
Std_ReturnType MemAcc_GetMemoryInfo (
MemAcc_AddressAreaIdType addressAreaId,
MemAcc_AddressType address,
MemAcc_MemoryInfoType* memoryInfoPtr);

/**********************************************************************************************************************
 * MemAcc_GetProcessedLength
 *********************************************************************************************************************/
/*! \brief       GetProcessedLength function.
 *  \details     This function returns the accumulated number of bytes that have already been processed in the current
                 job.
 *  \param[in]   addressAreaId   - Numeric identifier of address area.
 *  \return      MemAcc_LengthType
 *  \pre         -
 *  \context     TASK
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
MemAcc_LengthType MemAcc_GetProcessedLength (
MemAcc_AddressAreaIdType addressAreaId);

/**********************************************************************************************************************
 * MemAcc_GetJobInfo
 *********************************************************************************************************************/
/*! \brief       GetJobInfo function.
 *  \details     This function returns detailed information of the memory job for given AAId like memory device ID,
 *               job type, job processing state or job result, address area as well as address and length.
 *  \param[in]   addressAreaId   - Numeric identifier of address area.
 *  \param[out]  jobInfoPtr      - Structure pointer to return the detailed processing information of the current job.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \spec
 *    requires jobInfoPtr != NULL_PTR;
 *  \endspec
 *********************************************************************************************************************/
void MemAcc_GetJobInfo (
MemAcc_AddressAreaIdType addressAreaId,
MemAcc_JobInfoType* jobInfoPtr);

/**********************************************************************************************************************
 * MemAcc_MainFunction
 *********************************************************************************************************************/
/*! \brief       Main function.
 *  \details     This function handles the requested jobs and the internal management operations. Depending on
 *               the configuration MemAcc will call the Mem driver main functions.
 *  \param[in]   -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
void MemAcc_MainFunction (void);

/**********************************************************************************************************************
 * MemAcc_ActivateMem
 *********************************************************************************************************************/
/*! \brief       ActivateMem function.
 *  \details     Dynamic activation and initialization of a Mem driver referenced by hwId and headerAddress.
 *  \param[in]   headerAddress   - Physical start address of Mem driver header structure.
 *  \param[in]   hwId            - Unique numeric memory driver identifier.
 *  \return      E_OK:     The mem driver was activated.
 *               E_NOT_OK: The mem driver could not be activated. Parameters are invalid.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
Std_ReturnType MemAcc_ActivateMem (
  MemAcc_AddressType headerAddress,
  MemAcc_HwIdType hwId);

/**********************************************************************************************************************
 * MemAcc_DeactivateMem
 *********************************************************************************************************************/
/*! \brief       DeactivateMem function.
 *  \details     Dynamic deactivation of a Mem driver referenced by hwId and headerAddress.
 *  \param[in]   headerAddress   - Physical start address of Mem driver header structure.
 *  \param[in]   hwId            - Unique numeric memory driver identifier.
 *  \return      E_OK:     The mem driver was deactivated.
 *               E_NOT_OK: The mem driver could not be deactivated.
 *                         Parameters are invalid or job for given Mem is still pending.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
Std_ReturnType MemAcc_DeactivateMem (
  MemAcc_AddressType headerAddress,
  MemAcc_HwIdType hwId);

# define MEMACC_STOP_SEC_CODE
# include "MemAcc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  EXCLUSIVE AREA DEFINITION
 **********************************************************************************************************************/
/*!
  * \exclusivearea MEMACC_EXCLUSIVE_AREA_1
  * Ensures consistency while handling 32-bit variables. Can be turned off if 32-bit variables are handled atomically.
  * \protects Offset
  * \usedin MemAcc_MemAb_CompareJobStep, MemAcc_MemAb_UpdateJobStep, MemAcc_GetProcessedLength
  * \exclude All functions provided by MemAcc.
  * \length SHORT A single variable is handled.
  * \endexclusivearea
  */

#endif /* MEMACC_H */

/**********************************************************************************************************************
 *  END OF FILE: MemAcc.h
 *********************************************************************************************************************/
