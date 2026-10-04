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
/*!        \file  vMem_30_Traveo2Cyp01_LL_DetChecks.h
 *        \brief  Handles DetChecks for LLApis
 *
 *      \details  -
 *         \unit  vMem_LL_DetChecks
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#if !defined (VMEM_30_TRAVEO2CYP01_LL_DETCHECKS_H)
# define VMEM_30_TRAVEO2CYP01_LL_DETCHECKS_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

# include "vMem_30_Traveo2Cyp01_Types.h"
# include "vMem_30_Traveo2Cyp01_Cfg.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
# if !defined (VMEM_30_TRAVEO2CYP01_LL_DETCHECKS_INLINE) /* COV_VMEM_30_TRAVEO2CYP01_COMPATIBILITY */
#  define VMEM_30_TRAVEO2CYP01_LL_DETCHECKS_INLINE LOCAL_INLINE
# endif /* VMEM_30_TRAVEO2CYP01_LL_DETCHECKS_INLINE */

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
#define VMEM_30_TRAVEO2CYP01_WRITE_BUFFER_PTR_ALIGNMENT              4u

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
# define VMEM_30_TRAVEO2CYP01_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_LL_DevCheck_IsConditionTrue()
 *********************************************************************************************************************/
/*! 
 *  \brief        Generic Condition Check; modified by Development error Detection switch
 *  \details      Any given conditon becomes FALSE, if development error Detection is DISABLED;
 *  \param[in]    condition    The condition, i.e. the result of a boolean expression
 *  \return       FALSE        Condition is FALSE or Development Error Detection is DISABLED
 *  \return       TRUE         Condition is TRUE AND Development Error Detection is ENABLED
 *  \pre          -
 *  \context      TASK
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *********************************************************************************************************************/
VMEM_30_TRAVEO2CYP01_LL_DETCHECKS_INLINE FUNC(boolean, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_LL_DevCheck_IsConditionTrue
(
  boolean condition
);

/**********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_LLReportDevelopmentError()
 *********************************************************************************************************************/
/*! 
 *  \brief        Report given error to DET, or drop it (if Development Error Reporting is disabled)
 *  \details      Does nothing if error is VMEM_30_TRAVEO2CYP01_E_NO_ERROR
 *  \param[in]    ApiId      ApiId of calling service
 *  \param[in]    ErrorID    Error Code
 *  \pre          -
 *  \context      TASK
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *********************************************************************************************************************/
VMEM_30_TRAVEO2CYP01_LL_DETCHECKS_INLINE FUNC(void, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_LLReportDevelopmentError
(
  uint8 ApiId, 
  uint8 ErrorId
);

/**********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_LLIsSourceAddressPtrNotAligned()
 *********************************************************************************************************************/
/*!
 * \brief       Checks if the given buffer pointer is 4 bytes (32 bit) aligned.
 * \details     -
 * \param[in]   SourceAddressPtr    Pointer to an addresse whose alignment has to be checked
 * \return      TRUE - source address pointer is 4 bytes aligned.
 *              FALSE - source address pointer is not 4 bytes aligned.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 *********************************************************************************************************************/
VMEM_30_TRAVEO2CYP01_LL_DETCHECKS_INLINE FUNC(boolean, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_LLIsSourceAddressPtrNotAligned
(
  vMem_30_Traveo2Cyp01_ConstDataPtrType SourceAddressPtr
);

/**********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_LLIsNullPointer()
 *********************************************************************************************************************/
/*!
 * \brief       Checks if the given pointer is a null pointer.
 * \details     -
 * \param[in]   vMem_30_Traveo2Cyp01_DataPtrType    Pointer
 * \return      TRUE - FlashType is valid
 *              FALSE - FlashType is not valid
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 *********************************************************************************************************************/
VMEM_30_TRAVEO2CYP01_LL_DETCHECKS_INLINE FUNC(boolean, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_LLIsNullPointer
(
  vMem_30_Traveo2Cyp01_DataPtrType Pointer
);

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/
# ifndef VMEM_30_TRAVEO2CYP01_NOUNIT_VMEM_LL_DETCHECKS /* COV_VMEM_30_TRAVEO2CYP01_NOUNIT */

/**********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_LL_DevCheck_IsConditionTrue()
 *********************************************************************************************************************/
/*!
 * \internal
 * - #10 If DevErrorDetect is enabled, return if condition is true
 * \endinternal
 */
VMEM_30_TRAVEO2CYP01_LL_DETCHECKS_INLINE FUNC(boolean, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_LL_DevCheck_IsConditionTrue(
  boolean condition)
{
  return (vMem_30_Traveo2Cyp01_IsDevErrorDetectEnabled() && (condition == TRUE)); /* PRQA S 4404 */ /* MD_MSR_AutosarBoolean */
} /* vMem_30_Traveo2Cyp01_LL_DevCheck_IsConditionTrue */

/**********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_LLReportDevelopmentError()
 *********************************************************************************************************************/
/*!
 * \internal
 * - #10 Check if ErrorId is unequal to NO_ERROR
 * -   #11 Call DET Error Reporting
 * \endinternal
 */
VMEM_30_TRAVEO2CYP01_LL_DETCHECKS_INLINE FUNC(void, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_LLReportDevelopmentError(
  uint8 ApiId, /* PRQA S 3206 */ /* MD_vMem_30_Traveo2Cyp01_3206_ApiId */
  uint8 ErrorId)
{
  if (ErrorId != VMEM_30_TRAVEO2CYP01_E_NO_ERROR)
  {
    vMem_30_Traveo2Cyp01_CallDetErrorReporting(VMEM_30_TRAVEO2CYP01_MODULE_ID, VMEM_30_TRAVEO2CYP01_INSTANCE_ID_DET, ApiId, ErrorId);
  }
} /* vMem_30_Traveo2Cyp01_LLReportDevelopmentError */

/**********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_LLIsSourceAddressPtrNotAligned()
 *********************************************************************************************************************/
/*!
 * \internal
 * - Check if alignment is correct by dividing through required alignment and check for rest.
 * \endinternal
 */
VMEM_30_TRAVEO2CYP01_LL_DETCHECKS_INLINE FUNC(boolean, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_LLIsSourceAddressPtrNotAligned(
    vMem_30_Traveo2Cyp01_ConstDataPtrType SourceAddressPtr)
{
  vMem_30_Traveo2Cyp01_AddressType sourceAddress = (vMem_30_Traveo2Cyp01_AddressType)SourceAddressPtr; /* PRQA S 0326 */ /* MD_vMem_30_Traveo2Cyp01_0326_SourceAddress */
  return ((sourceAddress % VMEM_30_TRAVEO2CYP01_WRITE_BUFFER_PTR_ALIGNMENT) == 0u) ? FALSE : TRUE;
} /* vMem_30_Traveo2Cyp01_LLIsSourceAddressPtrNotAligned */

/**********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_LLIsNullPointer()
 *********************************************************************************************************************/
/*!
 * \internal
 * - Check if the passed pointer is a null pointer.
 * \endinternal
 */
VMEM_30_TRAVEO2CYP01_LL_DETCHECKS_INLINE FUNC(boolean, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_LLIsNullPointer(
  vMem_30_Traveo2Cyp01_DataPtrType Pointer) /* PRQA S 3673 */ /* MD_vMem_30_Traveo2Cyp01_3673_NotModified */
{
  return (Pointer == NULL_PTR); /* PRQA S 4404 */ /* MD_MSR_AutosarBoolean */
}

# endif /* VMEM_30_TRAVEO2CYP01_NOUNIT_VMEM_LL_DETCHECKS */

# define VMEM_30_TRAVEO2CYP01_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* VMEM_30_TRAVEO2CYP01_LL_DETCHECKS_H */

/* START_COVERAGE_JUSTIFICATION

Variant coverage:

\ID COV_VMEM_30_TRAVEO2CYP01_COMPATIBILITY
 \ACCEPT TX
 \REASON COV_MSR_COMPATIBILITY

\ID COV_VMEM_30_TRAVEO2CYP01_NOUNIT
 \ACCEPT TX
 \REASON This directiv is needed because this logical unit contains only inline functions which are fully implemented in 
         the header. To make it possible to mock this unit when testing other units, this directiv disables the actual 
         implementation.

END_COVERAGE_JUSTIFICATION */

/**********************************************************************************************************************
 *  END OF FILE: vMem_30_Traveo2Cyp01_LL_DetChecks.h
 *********************************************************************************************************************/
