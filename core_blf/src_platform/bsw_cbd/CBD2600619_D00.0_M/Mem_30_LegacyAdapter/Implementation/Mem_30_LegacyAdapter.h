/***********************************************************************************************************************
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
/*!        \file  Mem_30_LegacyAdapter.h
 *        \brief  Mem_30_LegacyAdapter header file
 *      \details  Header file of the Mem driver.
 *         \unit  General
 **********************************************************************************************************************/

#if !defined (MEM_30_LEGACYADAPTER_H)
# define MEM_30_LEGACYADAPTER_H

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
# include "Mem_30_LegacyAdapter_Cfg.h"

/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/
# if !defined (MEM_30_LEGACYADAPTER_LOCAL_INLINE)
#  define MEM_30_LEGACYADAPTER_LOCAL_INLINE                           LOCAL_INLINE
# endif

# if !defined (MEM_30_LEGACYADAPTER_LOCAL)
#  define MEM_30_LEGACYADAPTER_LOCAL                                  static
# endif

/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/

# define MEM_30_LEGACYADAPTER_SW_MAJOR_VERSION                        (2u)
# define MEM_30_LEGACYADAPTER_SW_MINOR_VERSION                        (0u)
# define MEM_30_LEGACYADAPTER_SW_PATCH_VERSION                        (5u)

/***********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 **********************************************************************************************************************/

# define MEM_30_LEGACYADAPTER_START_SEC_CONST_HEADER_ASIL_D_UNSPECIFIED
# include "Mem_30_LegacyAdapter_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */

/*! Global function pointer table */
extern CONST(MemAcc_MemBinaryHeaderType, AUTOMATIC) Mem_30_LegacyAdapter_FunctionPointerTable;

# define MEM_30_LEGACYADAPTER_STOP_SEC_CONST_HEADER_ASIL_D_UNSPECIFIED
# include "Mem_30_LegacyAdapter_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

# define MEM_30_LEGACYADAPTER_START_SEC_CODE_ASIL_D
# include "Mem_30_LegacyAdapter_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 * Mem_30_LegacyAdapter_Init()
 **********************************************************************************************************************/
/*! \brief       Initialization function
 *  \details     Service to initialize the module Mem_30_LegacyAdapter. It initializes all variables, calls the init
 *               service of underlying vMem drivers and sets the module state to initialized.
 *  \param[in]   configPtr               Pointer to the configuration data.
 *  \pre         Module is uninitialized.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \note        Specification of module initialization
 *  \trace       CREQ-Mem-Initialization
 **********************************************************************************************************************/
FUNC(void, MEM_30_LEGACYADAPTER_CODE) Mem_30_LegacyAdapter_Init(Mem_30_LegacyAdapter_ConfigPtrType configPtr);

/***********************************************************************************************************************
 *  Mem_30_LegacyAdapter_InitMemory()
 **********************************************************************************************************************/
/*! \brief       Initialization for *_INIT_*-variables
 *  \details     Service to initialize module global variables at power up. This function initializes the
 *               variables in *_INIT_* sections. Used in case they are not initialized by the startup code.
 *  \pre         Module is uninitialized.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 */
FUNC(void, MEM_30_LEGACYADAPTER_CODE) Mem_30_LegacyAdapter_InitMemory(void);

/***********************************************************************************************************************
 * Mem_30_LegacyAdapter_DeInit()
 **********************************************************************************************************************/
/*! \brief       De-Initialization function
 *  \details     De-Initialization is not supported by this module. It does nothing.
 *  \pre         Module is initialized.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \note        Specification of module initialization
 **********************************************************************************************************************/
FUNC(void, MEM_30_LEGACYADAPTER_CODE) Mem_30_LegacyAdapter_DeInit(void);

/***********************************************************************************************************************
 * Mem_30_LegacyAdapter_MainFunction()
 **********************************************************************************************************************/
/*! \brief        Triggers the main function of all managed vMem drivers.
 *  \details      -
 *  \pre          -
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 **********************************************************************************************************************/
FUNC(void, MEM_30_LEGACYADAPTER_CODE) Mem_30_LegacyAdapter_MainFunction(void);

/**********************************************************************************************************************
 * Mem_30_LegacyAdapter_GetJobResult
 *********************************************************************************************************************/
/*! \brief       Checks and returns result of the most recent job for the requested memory instance.
 *  \details     -
 *  \param[in]   instanceId          ID of the related memory driver instance.
 *  \retval      MEM_JOB_OK          The last job has been finished successfully.
 *  \retval      MEM_JOB_PENDING     A job is currently being processed.
 *  \retval      MEM_JOB_FAILED      Job failed due to some unspecific reason.
 *  \retval      MEM_INCONSISTENT    The checked page is not blank.
 *  \retval      MEM_ECC_UNCORRECTED Uncorrectable ECC errors occurred during memory access.
 *  \retval      MEM_ECC_CORRECTED   Correctable ECC errors occurred during memory access.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   TRUE
 *  \synchronous FALSE
 *  \trace       CREQ-Mem-GetJobResult
 *********************************************************************************************************************/
FUNC(Mem_30_LegacyAdapter_JobResultType, MEM_30_LEGACYADAPTER_CODE) Mem_30_LegacyAdapter_GetJobResult(
  Mem_30_LegacyAdapter_InstanceIdType instanceId);

/**********************************************************************************************************************
 * Mem_30_LegacyAdapter_Read
 *********************************************************************************************************************/
/*! \brief       Read function.
 *  \details     This function triggers a read job to copy data from the source address into the referenced destination
 *               data buffer for the underlying driver associated with the requested memory instance.
 *  \param[in]   instanceId           ID of the related memory driver instance.
 *  \param[in]   sourceAddress        Physical address to read data from.
 *  \param[in]   destinationDataPtr   Destination memory pointer to store the read data.
 *  \param[in]   length               Read length in bytes.
 *  \retval      E_OK       The requested job has been accepted and queued by the underlying driver.
 *  \retval      E_NOT_OK   Otherwise.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   TRUE
 *  \synchronous FALSE
 *  \trace       CREQ-Mem-Read
 *********************************************************************************************************************/
FUNC(Std_ReturnType, MEM_30_LEGACYADAPTER_CODE) Mem_30_LegacyAdapter_Read(
  Mem_30_LegacyAdapter_InstanceIdType instanceId,
  Mem_30_LegacyAdapter_AddressType sourceAddress,
  Mem_30_LegacyAdapter_DataPtrType destinationDataPtr,
  Mem_30_LegacyAdapter_LengthType length);

/**********************************************************************************************************************
 * Mem_30_LegacyAdapter_Write
 *********************************************************************************************************************/
/*! \brief       Asynchronous service to write data to nv memory.
 *  \details     This function triggers the service to write data from the source buffer to the target nv memory for the
 *               underlying driver associated with the requested memory instance.
 *  \param[in]   instanceId          ID of the related Mem_30_LegacyAdapter instance.
 *  \param[in]   targetAddress       NV memory address to write to.
 *  \param[in]   sourceDataPtr       Application pointer to buffer with data to write to nv memory.
 *                                   Must stay valid until job is completed.
 *  \param[in]   length              Length in bytes to write.
 *  \retval      E_OK       The requested job has been accepted and queued by the underlying driver.
 *  \retval      E_NOT_OK   Otherwise.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous FALSE
 *  \trace       CREQ-Mem-Write
 *********************************************************************************************************************/
FUNC(Std_ReturnType, MEM_30_LEGACYADAPTER_CODE) Mem_30_LegacyAdapter_Write(
  Mem_30_LegacyAdapter_InstanceIdType instanceId,
  Mem_30_LegacyAdapter_AddressType targetAddress,
  Mem_30_LegacyAdapter_ConstDataPtrType sourceDataPtr,
  Mem_30_LegacyAdapter_LengthType length);

/**********************************************************************************************************************
 * Mem_30_LegacyAdapter_Erase
 *********************************************************************************************************************/
/*! \brief       Asynchronous service to erase data from nv memory.
 *  \details     This function triggers the service to erases data from the target nv memory for the underlying driver
 *               associated with the requested memory instance.
 *  \param[in]   instanceId          ID of the related Mem_30_LegacyAdapter instance.
 *  \param[in]   targetAddress       NV memory address to erase.
 *  \param[in]   length              Length in bytes to erase.
 *  \retval      E_OK       The requested job has been accepted and queued by the underlying driver.
 *  \retval      E_NOT_OK   Otherwise.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous FALSE
 *  \trace       CREQ-Mem-Erase
 *********************************************************************************************************************/
FUNC(Std_ReturnType, MEM_30_LEGACYADAPTER_CODE) Mem_30_LegacyAdapter_Erase(
  Mem_30_LegacyAdapter_InstanceIdType instanceId,
  Mem_30_LegacyAdapter_AddressType targetAddress,
  Mem_30_LegacyAdapter_LengthType length);

/**********************************************************************************************************************
 * Mem_30_LegacyAdapter_BlankCheck
 *********************************************************************************************************************/
/*! \brief       Asynchronous service to check if a page is blank in nv memory.
 *  \details     This function triggers a job to check the erased state of the page which is referenced by
 *               targetAddress for the underlying driver associated with the requested memory instance. This is only
 *               done, if the underlying driver supports the blank check api.
 *  \param[in]   instanceId              ID of the related Mem_30_LegacyAdapter instance.
 *  \param[in]   targetAddress           Blank check memory address.
 *  \param[in]   length                  Length in bytes to blank check.
 *  \retval      E_MEM_SERVICE_NOT_AVAIL The underlying driver does not support the blank check api.
 *  \retval      E_OK                    The requested job has been accepted and queued by the underlying driver.
 *  \retval      E_NOT_OK                Otherwise.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous FALSE
 *  \trace       CREQ-Mem-BlankCheck
 *********************************************************************************************************************/
FUNC(Std_ReturnType, MEM_30_LEGACYADAPTER_CODE) Mem_30_LegacyAdapter_BlankCheck(
  Mem_30_LegacyAdapter_InstanceIdType instanceId,
  Mem_30_LegacyAdapter_AddressType targetAddress,
  Mem_30_LegacyAdapter_LengthType length);

/**********************************************************************************************************************
 * Mem_30_LegacyAdapter_PropagateError
 *********************************************************************************************************************/
/*! \brief       This service reports an access error in case the Mem driver cannot provide the
 *               access error information - typically for ECC faults.
 *  \details     It is called by the system ECC handler to propagate an ECC error to the memory upper layers.
 *  \param[in]   instanceId          ID of the related Mem_30_LegacyAdapter instance.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \trace       DSGN-Mem-PropagateError
 *********************************************************************************************************************/
FUNC(void, MEM_30_LEGACYADAPTER_CODE) Mem_30_LegacyAdapter_PropagateError(
  Mem_30_LegacyAdapter_InstanceIdType instanceId);

/**********************************************************************************************************************
 * Mem_30_LegacyAdapter_Suspend
 *********************************************************************************************************************/
/*! \brief       This service is not supported by this module. It always returns E_MEM_SERVICE_NOT_AVAIL.
 *  \details     -
 *  \param[in]   instanceId          ID of the related Mem_30_LegacyAdapter instance.
 *  \pre         -
 *  \retval      E_MEM_SERVICE_NOT_AVAIL - The service is not supported by this module.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \trace       CREQ-Mem-AutosarCompatibility
 *********************************************************************************************************************/
FUNC(Std_ReturnType, MEM_30_LEGACYADAPTER_CODE) Mem_30_LegacyAdapter_Suspend(
  Mem_30_LegacyAdapter_InstanceIdType instanceId);

/**********************************************************************************************************************
 * Mem_30_LegacyAdapter_Resume
 *********************************************************************************************************************/
/*! \brief       This service is not supported by this module. It alwyays returns E_MEM_SERVICE_NOT_AVAIL.
 *  \details     -
 *  \param[in]   instanceId          ID of the related Mem_30_LegacyAdapter instance.
 *  \pre         -
 *  \retval      E_MEM_SERVICE_NOT_AVAIL - The service is not supported by this module.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \trace       CREQ-Mem-AutosarCompatibility
 *********************************************************************************************************************/
FUNC(Std_ReturnType, MEM_30_LEGACYADAPTER_CODE) Mem_30_LegacyAdapter_Resume(
  Mem_30_LegacyAdapter_InstanceIdType instanceId);

/**********************************************************************************************************************
 * Mem_30_LegacyAdapter_HwSpecificService
 *********************************************************************************************************************/
/*! \brief       Asynchronous service to trigger a hardware specific job.
 *  \details     This service is just a dispatcher to the hardware specific service implementation referenced by
 *               the hwServiceId.
 *  \param[in]   instanceId          ID of the related Mem_30_LegacyAdapter instance.
 *  \param[in]   hwServiceId         Hardware specific service request identifier for dispatching the request.
 *  \param[in,out]   dataPtr         Data pointer pointing to the job buffer. Value must not be NULL_PTR.
 *                                   If dataPtr is used by the hardware specific service, the pointer must be valid
 *                                   until the job completed.
 *  \param[in]   lengthPtr           Size pointer of the data passed by dataPtr. Value must not be NULL_PTR.
 *  \return      E_OK  - The requested job has been accepted by the module.
 *               E_NOT_OK - The requested job has not been accepted by the module.
 *               E_MEM_SERVICE_NOT_AVAIL - The underlying Mem driver service function is not available.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous FALSE
 *  \trace       CREQ-Mem-HwSpecificService
 *********************************************************************************************************************/
FUNC(Std_ReturnType, MEM_30_LEGACYADAPTER_CODE) Mem_30_LegacyAdapter_HwSpecificService(
  Mem_30_LegacyAdapter_InstanceIdType instanceId,
  Mem_30_LegacyAdapter_HwServiceIdType hwServiceId,
  Mem_30_LegacyAdapter_DataType* dataPtr,
  Mem_30_LegacyAdapter_LengthType* lengthPtr);

/***********************************************************************************************************************
 *  Mem_30_LegacyAdapter_GetVersionInfo()
 ***********************************************************************************************************************/
/*! \brief        Returns the version information
 *  \details      Mem_30_LegacyAdapter_GetVersionInfo() returns version information, vendor ID and AUTOSAR module ID of the
 *                component.
 *  \param[out]   versioninfo             Pointer to where to store the version information. Parameter must not be NULL.
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *  \pre          -
 *  \trace        CREQ-Mem-VersionInfo
 ***********************************************************************************************************************/
FUNC(void, MEM_30_LEGACYADAPTER_CODE) Mem_30_LegacyAdapter_GetVersionInfo(
  P2VAR(Std_VersionInfoType, AUTOMATIC, MEM_30_LEGACYADAPTER_APPL_VAR) versioninfo);

# define MEM_30_LEGACYADAPTER_STOP_SEC_CODE_ASIL_D
# include "Mem_30_LegacyAdapter_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* MEM_30_LEGACYADAPTER_H */
/***********************************************************************************************************************
 *  END OF FILE: Mem_30_LegacyAdapter.h
 **********************************************************************************************************************/
