/**********************************************************************************************************************
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
/*!        \file  Mem_30_LegacyAdapter_LLAdapter.h
 *        \brief  Mem LLAdapter header file
 *
 *      \details  The Mem LLAdapter subcomponent implements wrappers to align the Mem services with the underlying
 *                driver services.
 *
 *                NOTE: For a more detailed API description please refer to MemAcc_MemApi.h
 *         \unit  LLAdapter
 *********************************************************************************************************************/

#if !defined (MEM_30_LEGACYADAPTER_LLADAPTER_H)
# define MEM_30_LEGACYADAPTER_LLADAPTER_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "Mem_30_LegacyAdapter_Cfg.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
# if !defined (MEM_30_LEGACYADAPTER_LOCAL_INLINE)
#  define MEM_30_LEGACYADAPTER_LOCAL_INLINE                           LOCAL_INLINE
# endif

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

# define MEM_30_LEGACYADAPTER_START_SEC_CODE_ASIL_D
# include "Mem_30_LegacyAdapter_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Mem_30_LegacyAdapter_LLAdapter_Init()
 *********************************************************************************************************************/
/*! \brief       Initializes LowLevel part of component.
 *  \details     -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, MEM_30_LEGACYADAPTER_CODE) Mem_30_LegacyAdapter_LLAdapter_Init(void);

/**********************************************************************************************************************
 *  Mem_30_LegacyAdapter_LLAdapter_GetJobResult()
 *********************************************************************************************************************/
/*! \brief       Returns the result of the last accepted job, as long as no new job is accepted.
 *  \details     -
 *  \param[in]   instanceId          ID of the related Mem instance, must be valid.
 *  \return      Current job result.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \spec
 *    requires instanceId < Mem_30_LegacyAdapter_GetSizeOfMemInstanceIdMapping();
 *  \endspec
 *********************************************************************************************************************/
FUNC(Mem_30_LegacyAdapter_JobResultType, MEM_30_LEGACYADAPTER_CODE) Mem_30_LegacyAdapter_LLAdapter_GetJobResult(
  const Mem_30_LegacyAdapter_InstanceIdType instanceId);

/**********************************************************************************************************************
 *  Mem_30_LegacyAdapter_LLAdapter_Read()
 *********************************************************************************************************************/
/*! \brief       Asynchronous service to read data.
 *  \details     Mem_30_LegacyAdapter_LLAdapter_Read() returns the requested data.
 *               Parameter checks are done within core part.
 *  \param[in]   instanceId          ID of the related Mem instance, must be valid.
 *  \param[in]   sourceAddress       NV memory address to read from, must be valid.
 *  \param[out]  destinationDataPtr  Application pointer to buffer to write to. Must stay valid until job is completed.
 *  \param[in]   length              Length in bytes to be read, must be valid.
 *  \return      E_OK - Job accepted.
 *  \return      E_NOT_OK - Otherwise.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous FALSE
 *  \spec
 *    requires instanceId < Mem_30_LegacyAdapter_GetSizeOfMemInstanceIdMapping();
 *  \endspec
 *********************************************************************************************************************/
FUNC(Std_ReturnType, MEM_30_LEGACYADAPTER_CODE) Mem_30_LegacyAdapter_LLAdapter_Read(
  const Mem_30_LegacyAdapter_InstanceIdType instanceId,
  const Mem_30_LegacyAdapter_AddressType sourceAddress,
  Mem_30_LegacyAdapter_DataPtrType destinationDataPtr,
  const Mem_30_LegacyAdapter_LengthType length);

/**********************************************************************************************************************
 *  Mem_30_LegacyAdapter_LLAdapter_Write()
 *********************************************************************************************************************/
/*! \brief       Asynchronous service to write data to nv memory.
 *  \details     Mem_30_LegacyAdapter_LLAdapter_Write() writes data to nv memory.
 *               Parameter checks are done within core part.
 *  \param[in]   instanceId          ID of the related Mem instance, must be valid.
 *  \param[in]   targetAddress       NV memory address to write to, must be valid.
 *  \param[in]   sourceDataPtr    application pointer to buffer with data to write to nv memory.
 *                                   Must stay valid until job is completed.
 *  \param[in]   length              Length in bytes to write, must be valid.
 *  \return      E_OK - Job accepted.
 *  \return      E_NOT_OK - Otherwise.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous FALSE
 *  \spec
 *    requires instanceId < Mem_30_LegacyAdapter_GetSizeOfMemInstanceIdMapping();
 *  \endspec
 *********************************************************************************************************************/
FUNC(Std_ReturnType, MEM_30_LEGACYADAPTER_CODE) Mem_30_LegacyAdapter_LLAdapter_Write(
  const Mem_30_LegacyAdapter_InstanceIdType instanceId,
  const Mem_30_LegacyAdapter_AddressType targetAddress,
  Mem_30_LegacyAdapter_ConstDataPtrType sourceDataPtr,
  const Mem_30_LegacyAdapter_LengthType length);

/**********************************************************************************************************************
 *  Mem_30_LegacyAdapter_LLAdapter_Erase()
 *********************************************************************************************************************/
/*! \brief       Asynchronous service to erase data from nv memory.
 *  \details     Mem_30_LegacyAdapter_LLAdapter_Erase() erases data from nv memory.
 *               Parameter checks are done within core part.
 *  \param[in]   instanceId          ID of the related Mem instance, must be valid.
 *  \param[in]   targetAddress       NV memory address to be erased, must be valid.
 *  \param[in]   length              Length in bytes to erase, must be valid.
 *  \return      E_OK - Job accepted.
 *  \return      E_NOT_OK - Otherwise.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous FALSE
 *  \spec
 *    requires instanceId < Mem_30_LegacyAdapter_GetSizeOfMemInstanceIdMapping();
 *  \endspec
 *********************************************************************************************************************/
FUNC(Std_ReturnType, MEM_30_LEGACYADAPTER_CODE) Mem_30_LegacyAdapter_LLAdapter_Erase(
  const Mem_30_LegacyAdapter_InstanceIdType instanceId,
  const Mem_30_LegacyAdapter_AddressType targetAddress,
  const Mem_30_LegacyAdapter_LengthType length);

/**********************************************************************************************************************
 *  Mem_30_LegacyAdapter_LLAdapter_BlankCheck()
 *********************************************************************************************************************/
/*! \brief       Asynchronous service to check if a page is blank in nv memory.
 *  \details     Mem_30_LegacyAdapter_LLAdapter_BlankCheck() checks if the page with the given address and
 *               length is blank, i.e valid to write to.
 *               Parameter checks are done within core part.
 *  \param[in]   instanceId          ID of the related Mem instance, must be valid.
 *  \param[in]   targetAddress       Address of the flash page that is checked, must be valid.
 *  \param[in]   length              Number of bytes to be checked (must be exactly the page size).
 *  \retval      E_SERVICE_NOT_AVAIL The underlying driver does not support the blank check api.
 *  \return      E_OK                Job accepted.
 *  \return      E_NOT_OK            Otherwise.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous FALSE
 *  \spec
 *    requires instanceId < Mem_30_LegacyAdapter_GetSizeOfMemInstanceIdMapping();
 *  \endspec
 *********************************************************************************************************************/
FUNC(Std_ReturnType, MEM_30_LEGACYADAPTER_CODE) Mem_30_LegacyAdapter_LLAdapter_BlankCheck(
  const Mem_30_LegacyAdapter_InstanceIdType instanceId,
  const Mem_30_LegacyAdapter_AddressType targetAddress,
  const Mem_30_LegacyAdapter_LengthType length);

/**********************************************************************************************************************
 * Mem_30_LegacyAdapter_LLAdapter_HwSpecificService
 *********************************************************************************************************************/
/*! \brief       Asynchronous service to trigger a hardware specific job.
 *  \details     This service is just a dispatcher to the hardware specific service implementation referenced by 
 *               the hwServiceId.  
 *  \param[in]   instanceId          ID of the related Mem_30_LegacyAdapter instance.
 *  \param[in]   hwServiceId         Hardware specific service request identifier for dispatching the request.
 *  \param[in,out]   dataPtr         Data pointer pointing to the job buffer. Value can be NULL_PTR, if not needed.
 *                                   If dataPtr is used by the hardware specific service, the pointer must be valid
 *                                   until the job completed.
 *  \param[in]   lengthPtr           Size pointer of the data passed by dataPtr. Can be NULL_PTR if dataPtr is also
 *                                   NULL_PTR.
 *  \return      E_OK - The requested job has been accepted by the module.
 *               E_NOT_OK - The requested job has not been accepted by the module.
 *               E_MEM_SERVICE_NOT_AVAIL - The underlying Mem driver service function is not available.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous FALSE
 *  \spec
 *    requires instanceId < Mem_30_LegacyAdapter_GetSizeOfMemInstanceIdMapping();
 *  \endspec
 *********************************************************************************************************************/
FUNC(Std_ReturnType, MEM_30_LEGACYADAPTER_CODE) Mem_30_LegacyAdapter_LLAdapter_HwSpecificService(
  const Mem_30_LegacyAdapter_InstanceIdType instanceId,
  const Mem_30_LegacyAdapter_HwServiceIdType hwServiceId,
  Mem_30_LegacyAdapter_DataType* dataPtr,
  const Mem_30_LegacyAdapter_LengthType* lengthPtr);

/**********************************************************************************************************************
 *  Mem_30_LegacyAdapter_LLAdapter_Processing()
 *********************************************************************************************************************/
/*! \brief       Processes the Mem LowLevel state machine, returns when done.
 *  \details     -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, MEM_30_LEGACYADAPTER_CODE) Mem_30_LegacyAdapter_LLAdapter_Processing(void);

/**********************************************************************************************************************
 *  Mem_30_LegacyAdapter_LLAdapter_PropagateError()
 *********************************************************************************************************************/
/*! \brief       This function waits until the job of the associated underlying driver is finished and sets its result
 *               to MEM_ECC_CORRECTED.
 *  \details     -
 *  \param[in]   instanceId       ID of the related memory driver instance.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \spec
 *    requires instanceId < Mem_30_LegacyAdapter_GetSizeOfMemInstanceIdMapping();
 *  \endspec
 *********************************************************************************************************************/
FUNC(void, MEM_30_LEGACYADAPTER_CODE) Mem_30_LegacyAdapter_LLAdapter_PropagateError(
  const Mem_30_LegacyAdapter_InstanceIdType instanceId);

/***********************************************************************************************************************
 * Mem_30_LegacyAdapter_LLAdapter_IsHwServiceIdValid()
 **********************************************************************************************************************/
/*! \brief       Checks if the given hw service id is valid for the underlying driver associated with the given
                 instance id.
 *  \details     -
 *  \param[in]   instanceId        ID of the related memory driver instance.
 *  \param[in]   hwServiceId       ID of the hardware specific service.
 *  \return      TRUE if the given hw service id is valid for the underlying driver.
 *  \return      FALSE otherwise.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous FALSE
 *  \spec
 *    requires instanceId < Mem_30_LegacyAdapter_GetSizeOfMemInstanceIdMapping();
 *  \endspec
 **********************************************************************************************************************/
MEM_30_LEGACYADAPTER_LOCAL_INLINE FUNC(boolean, MEM_30_LEGACYADAPTER_CODE)
Mem_30_LegacyAdapter_LLAdapter_IsHwServiceIdValid(
  const Mem_30_LegacyAdapter_InstanceIdType instanceId,
  const Mem_30_LegacyAdapter_HwServiceIdType hwServiceId);

/**********************************************************************************************************************
 *  GLOBAL FUNCTION DEFINITIONS
 *********************************************************************************************************************/
# ifndef MEM_30_LEGACYADAPTER_NOUNIT_LLADAPTER
/*! This NOUNIT macro is defined to enable the mocking of the function contained in this unit when testing other units. 
This is required since the present unit/file contains only inline function as well as their implementation. 
If another unit is tested, this macro is used to disable the actual implementation so that their function mocks can be 
used instead. */

/***********************************************************************************************************************
 * Mem_30_LegacyAdapter_LLAdapter_IsHwServiceIdValid()
 **********************************************************************************************************************/
/*! 
 *  \internal
 *  - Checks if the given hw service id is valid for the underlying driver associated with the given instance id.
 *  \endinternal
 */
MEM_30_LEGACYADAPTER_LOCAL_INLINE FUNC(boolean, MEM_30_LEGACYADAPTER_CODE)
Mem_30_LegacyAdapter_LLAdapter_IsHwServiceIdValid(   /* PRQA S 3219 1 */ /* MD_Mem_30_LegacyAdapter_InlineFunction */
  const Mem_30_LegacyAdapter_InstanceIdType instanceId,
  const Mem_30_LegacyAdapter_HwServiceIdType hwServiceId)
{
# if (MEM_30_LEGACYADAPTER_VMEMTYPESENABLED == STD_ON)

  Mem_30_LegacyAdapter_vMemHwSpecificFunctionsPtrType hwFunctions = Mem_30_LegacyAdapter_GetHwFunctionsOfLLApi(
    Mem_30_LegacyAdapter_GetLLApiIdxOfMemInstanceIdMapping(instanceId));
  return (hwFunctions != NULL_PTR) && (hwServiceId < hwFunctions->FunctionCount);

# else
  MEM_30_LEGACYADAPTER_DUMMY_STATEMENT_CONST(instanceId);
  MEM_30_LEGACYADAPTER_DUMMY_STATEMENT_CONST(hwServiceId);
  return FALSE;

# endif /* (MEM_30_LEGACYADAPTER_VMEMTYPESENABLED == STD_ON) */
}

# endif

# define MEM_30_LEGACYADAPTER_STOP_SEC_CODE_ASIL_D
# include "Mem_30_LegacyAdapter_MemMap.h" /* PRQA S 5087 */  /* MD_MSR_MemMap */

#endif /* MEM_30_LEGACYADAPTER_LLADAPTER_H */

/**********************************************************************************************************************
 *  END OF FILE: Mem_30_LegacyAdapter_LLAdapter.h
 *********************************************************************************************************************/
