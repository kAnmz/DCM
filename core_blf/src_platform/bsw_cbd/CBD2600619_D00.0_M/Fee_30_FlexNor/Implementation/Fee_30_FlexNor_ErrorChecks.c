/**********************************************************************************************************************
 *  COPYRIGHT
 *  --------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2025 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  --------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/*!        \file  Fee_30_FlexNor_ErrorChecks.c
 *        \brief  DET checks implementations
 *      \details  Provides the implementation for error check functions of API parameters.
 *         \unit  ErrorChecks
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#define FEE_30_FLEXNOR_DETCHECKS_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Fee_30_FlexNor.h"
#include "Fee_30_FlexNor_ErrorChecks.h"
#include "Fee_30_FlexNor_ConfigInterface.h"

#if (FEE_30_FLEXNOR_DEV_ERROR_REPORT == STD_ON)
# include "Det.h"
#endif

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/
#if !defined (FEE_30_FLEXNOR_LOCAL) /* COV_FEE_30_FLEXNOR_COMPATIBILITY */
# define FEE_30_FLEXNOR_LOCAL static
#endif

#if !defined (FEE_30_FLEXNOR_LOCAL_INLINE) /* COV_FEE_30_FLEXNOR_COMPATIBILITY */
# define FEE_30_FLEXNOR_LOCAL_INLINE LOCAL_INLINE
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
#define FEE_30_FLEXNOR_START_SEC_CODE
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * Fee_30_FlexNor_ErrorChecks_IsDetConditionTrue()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(boolean, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_ErrorChecks_IsDetConditionTrue(boolean condition)
{
#if (FEE_30_FLEXNOR_DEV_ERROR_DETECT == STD_ON)
    return condition;
#else
    FEE_DUMMY_STATEMENT(condition);
    return FALSE;
#endif
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_DetChecks_ReportDetError()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE)Fee_30_FlexNor_ErrorChecks_ReportDetError(Fee_30_FlexNor_ServiceId serviceId, 
    Fee_30_FlexNor_ErrorCode errorCode)
{
#if (FEE_30_FLEXNOR_DEV_ERROR_REPORT == STD_ON)
    (void)Det_ReportError(FEE_30_FLEXNOR_MODULE_ID, FEE_30_FLEXNOR_INSTANCE_ID_DET, (uint8)serviceId, (uint8)errorCode);
#else
    FEE_DUMMY_STATEMENT(serviceId);
    FEE_DUMMY_STATEMENT(errorCode);
#endif
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_DetChecks_ReportRuntimeError()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_ErrorChecks_ReportRuntimeError(Fee_30_FlexNor_ServiceId serviceId, 
    Fee_30_FlexNor_ErrorCode errorCode)
{
#if (FEE_30_FLEXNOR_DEV_ERROR_REPORT == STD_ON)
    (void)Det_ReportRuntimeError(FEE_30_FLEXNOR_MODULE_ID, FEE_30_FLEXNOR_INSTANCE_ID_DET, (uint8)serviceId, 
        (uint8)errorCode);
#else
    FEE_DUMMY_STATEMENT(serviceId);
    FEE_DUMMY_STATEMENT(errorCode);
#endif
}

#define FEE_30_FLEXNOR_STOP_SEC_CODE
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: Fee_30_FlexNor_ErrorChecks.c
 *********************************************************************************************************************/
