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
/*!        \file  Fee_30_FlexNor_Shared.c
 *        \brief  Shared functionality
 *      \details  Implementation of the shared unit functionality.
 *         \unit  Shared
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/
#define FEE_30_FLEXNOR_SHARED_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Fee_30_FlexNor_Shared.h"
#include "Fee_30_FlexNor_ConfigInterface.h"

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
#define FEE_30_FLEXNOR_SHARED_SINGLESHIFTSIZE (0x08u)
#define FEE_30_FLEXNOR_SHARED_BYTEMASK        (0xFFu)

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/
#if !defined(FEE_30_FLEXNOR_LOCAL) /* COV_FEE_30_FLEXNOR_COMPATIBILITY */
#    define FEE_30_FLEXNOR_LOCAL static
#endif

#if !defined(FEE_30_FLEXNOR_LOCAL_INLINE) /* COV_FEE_30_FLEXNOR_COMPATIBILITY */
#    define FEE_30_FLEXNOR_LOCAL_INLINE LOCAL_INLINE
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
 * Fee_30_FlexNor_Shared_AlignUp()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(uint32, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Shared_AlignUp(uint32 value, uint16 alignment)
{
    uint32 alignedValue = value;

    if ((value % alignment) != 0u)
    {
        alignedValue = value + alignment - (value % alignment);
    }

    return alignedValue;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Shared_AlignDown()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(uint32, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Shared_AlignDown(uint32 value, uint16 alignment)
{
    uint32 alignedValue = value - (value % alignment);

    return alignedValue;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Shared_GetMarkerValidity()
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
FUNC(Fee_30_FlexNor_StructureValidityType, FEE_30_FLEXNOR_CODE)  Fee_30_FlexNor_Shared_GetMarkerValidity(
    Fee_30_FlexNor_ConstDataPtrType buffer, 
    Fee_30_FlexNor_LengthType offset,
    Fee_30_FlexNor_MarkerType expectedMarker,
    uint16 pageAlignment,
    uint8 erasedValue
    )
{
    Fee_30_FlexNor_StructureValidityType returnValue = FEE_30_FLEXNOR_VALID;
    Fee_30_FlexNor_MarkerType parsedMarker = (Fee_30_FlexNor_MarkerType) buffer[offset];

    for (uint16 index = 1u; index < pageAlignment; index++)
    {
        if((Fee_30_FlexNor_MarkerType) buffer[offset + index] != parsedMarker)
        {
            returnValue = FEE_30_FLEXNOR_INVALID;
            break;
        }
    }

    if(returnValue != FEE_30_FLEXNOR_INVALID)
    {
        if(parsedMarker == erasedValue)
        {
            returnValue = FEE_30_FLEXNOR_EMPTY;
        }
        else if(parsedMarker == expectedMarker)
        {
            returnValue = FEE_30_FLEXNOR_VALID;
        }
        else
        {
            returnValue = FEE_30_FLEXNOR_INVALID;
        }
    }

    return returnValue;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Shared_SetBufferValues()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Shared_SetBufferValues(
    Fee_30_FlexNor_DataPtrType buffer,
    Fee_30_FlexNor_LengthType bufferSize,
    Fee_30_FlexNor_DataType value)
{
    for (Fee_30_FlexNor_LengthType index = 0u; index < bufferSize; index++)
    {
        buffer[index] = value; /* SBSW_Fee_30_FlexNor_ModifyGivenArray */
    }
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Shared_GetValueFromBuffer()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(uint32, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Shared_GetValueFromBuffer(
    Fee_30_FlexNor_ConstDataPtrType sourceBuffer,
    Fee_30_FlexNor_LengthType length,
    Fee_30_FlexNor_LengthType offset)
{
    uint32 retVal = 0u;

    for (Fee_30_FlexNor_LengthType index = 0u; index < length; index++)
    {
        retVal += ((uint32) sourceBuffer[index + offset]) << ((length - index - 1u) 
            * FEE_30_FLEXNOR_SHARED_SINGLESHIFTSIZE);
    }

    return retVal;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Shared_SetValueToBuffer()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Shared_SetValueToBuffer(
    uint32 value,
    Fee_30_FlexNor_DataPtrType targetBuffer,
    Fee_30_FlexNor_LengthType length,
    Fee_30_FlexNor_LengthType offset)
{
    Fee_30_FlexNor_DataType shiftedValue;

    for (Fee_30_FlexNor_LengthType index = 0u; index < length; index++)
    {
        shiftedValue 
            = (Fee_30_FlexNor_DataType) ((value >> ((length - index - 1u) * FEE_30_FLEXNOR_SHARED_SINGLESHIFTSIZE)) 
                & FEE_30_FLEXNOR_SHARED_BYTEMASK);
        targetBuffer[index + offset] = shiftedValue; /* SBSW_Fee_30_FlexNor_ModifyGivenArray */
    }
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Shared_CalculateChecksum()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_ChecksumType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Shared_CalculateChecksum(
    Fee_30_FlexNor_ConstDataPtrType buffer,
    Fee_30_FlexNor_LengthType length,
    Fee_30_FlexNor_LengthType offset)
{
    Fee_30_FlexNor_ChecksumType checksum = 0u;

    for (Fee_30_FlexNor_LengthType index = 0u; index < length; index++)
    {
        checksum += buffer[index + offset];
    }

    return checksum;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Shared_IsErased()
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
FUNC(boolean, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Shared_IsErased(
    Fee_30_FlexNor_ConstDataPtrType buffer,
    Fee_30_FlexNor_LengthType length,
    uint8 erasedValue)
{
    boolean isErased = TRUE;

    for (Fee_30_FlexNor_LengthType index = 0u; index < length; index++)
    {
        if (buffer[index] != erasedValue)
        {
            isErased = FALSE;
            break;
        }
    }

    return isErased;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Shared_IsWriteLikeJob()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(boolean, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Shared_IsWriteLikeJob(Fee_30_FlexNor_ServiceId service)
{
    boolean isWriteLikeJob = FALSE;

    if ((service == FEE_30_FLEXNOR_SID_WRITE) ||
        (service == FEE_30_FLEXNOR_SID_INVALIDATEBLOCK) ||
        (service == FEE_30_FLEXNOR_SID_ERASEIMMEDIATEBLOCK))
    {
        isWriteLikeJob = TRUE;
    }

    return isWriteLikeJob;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Shared_NotifyNvM()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Shared_NotifyNvM(MemIf_JobResultType result)
{
#if (FEE_30_FLEXNOR_NVM_POLLING_MODE == STD_OFF)
    if (result == MEMIF_JOB_OK)
    {
        Fee_30_FlexNor_NvMJobEndNotification();
    }
    else
    {
        Fee_30_FlexNor_NvMJobErrorNotification();
    }
#else
    FEE_DUMMY_STATEMENT(result);
#endif
}

#define FEE_30_FLEXNOR_STOP_SEC_CODE
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: Fee_30_FlexNor_Shared.c
 *********************************************************************************************************************/
