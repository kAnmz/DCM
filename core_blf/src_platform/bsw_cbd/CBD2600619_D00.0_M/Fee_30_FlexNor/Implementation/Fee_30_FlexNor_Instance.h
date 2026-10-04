/**********************************************************************************************************************
 *  COPYRIGHT
 *  --------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2025 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  --------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/*!        \file  Fee_30_FlexNor_Instance.h
 *        \brief  Generic instance interface
 *      \details  Provides the instance definition and layout independent services.
 *         \unit  SecureInstance
 *         \unit  SlimInstance
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 **********************************************************************************************************************/

#if !defined (FEE_30_FLEXNOR_INSTANCE_H)
# define FEE_30_FLEXNOR_INSTANCE_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Fee_30_FlexNor_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum
{
    FEE_30_FLEXNOR_INSTANCE_VALID = 0x5A,           /*!< The instance is valid */
    FEE_30_FLEXNOR_INSTANCE_INVALIDATED = 0x25      /*!< The instance was explicitly invalidated */
} Fee_30_FlexNor_InstanceStatusType;                /*!< Type which indicates the status of an instance */

typedef struct
{
    Fee_30_FlexNor_StructureValidityType Validity;           /*!< Validity of the instance structure in flash */

    Fee_30_FlexNor_InstanceStatusType Status;                /*!< Status of the instance */
    Fee_30_FlexNor_StructureFlagsType ReallocationRequired;  /*!< Indicates if the instance needs a reallocation of its chunk */
    Fee_30_FlexNor_AddressType StartAddress;                 /*!< Start address of the instance in flash */
    Fee_30_FlexNor_PartitionIdType PartitionId;              /*!< Id of the partition the instance belongs to */
    Fee_30_FlexNor_DataPtrType ReadBuffer;                   /*!< Pointer to the read buffer of the instance */
    Fee_30_FlexNor_ConstDataPtrType WriteBuffer;             /*!< Pointer to the write buffer of the instance */
    Fee_30_FlexNor_LengthType PayloadSize;                   /*!< Size of the payload buffer */  
    Fee_30_FlexNor_LengthType PayloadOffset;                 /*!< Offset from where the instance payload shall be read from */
} Fee_30_FlexNor_InstanceDataType;                           /*!< Structure which holds all public data */

typedef P2VAR(Fee_30_FlexNor_InstanceDataType, AUTOMATIC, FEE_30_FLEXNOR_VAR) Fee_30_FlexNor_InstanceDataPtrType;
typedef P2CONST(Fee_30_FlexNor_InstanceDataType, AUTOMATIC, FEE_30_FLEXNOR_VAR) Fee_30_FlexNor_ConstInstanceDataPtrType;

typedef P2FUNC(uint32, AUTOMATIC, Fee_30_FlexNor_Instance_GetTotalSizePtr)(Fee_30_FlexNor_ConstInstanceDataPtrType instance);
typedef P2FUNC(void, AUTOMATIC, Fee_30_FlexNor_Instance_ValidatePtr)(Fee_30_FlexNor_InstanceDataPtrType instance, Fee_30_FlexNor_ResultCallback resultCbk);
typedef P2FUNC(void, AUTOMATIC, Fee_30_FlexNor_Instance_WritePtr)(Fee_30_FlexNor_ConstInstanceDataPtrType instance, Fee_30_FlexNor_ResultCallback resultCbk);
typedef P2FUNC(void, AUTOMATIC, Fee_30_FlexNor_Instance_ReadContentPtr)(Fee_30_FlexNor_InstanceDataPtrType instance, Fee_30_FlexNor_ResultCallback resultCbk);
typedef P2FUNC(void, AUTOMATIC, Fee_30_FlexNor_Instance_CopyPtr)(Fee_30_FlexNor_ConstInstanceDataPtrType sourceInstance, 
    Fee_30_FlexNor_InstanceDataPtrType targetInstance, 
    Fee_30_FlexNor_ResultCallback resultCbk);
    
typedef struct
{
    Fee_30_FlexNor_Instance_GetTotalSizePtr GetTotalSize;  /*!< Pointer to the get total size service of the instance */
    Fee_30_FlexNor_Instance_ValidatePtr Validate;          /*!< Pointer to the validate service of the instance */
    Fee_30_FlexNor_Instance_WritePtr Write;                /*!< Pointer to the write service of the instance */
    Fee_30_FlexNor_Instance_ReadContentPtr ReadContent;    /*!< Pointer to the read payload service of the instance */
    Fee_30_FlexNor_Instance_CopyPtr Copy;                  /*!< Pointer to the copy service of the instance */

} Fee_30_FlexNor_InstanceServicesType;                     /*!< Holds all services which an instance provides to the outside */

typedef struct
{
    Fee_30_FlexNor_InstanceDataType Data;           /*!< Properties of the instance */
    Fee_30_FlexNor_InstanceServicesType Services;   /*!< Services the instance offers */
} Fee_30_FlexNor_InstanceType;                      /*!< Structure which holds all public data and services */

typedef P2VAR(Fee_30_FlexNor_InstanceType, AUTOMATIC, FEE_30_FLEXNOR_VAR) Fee_30_FlexNor_InstancePtrType;
typedef P2CONST(Fee_30_FlexNor_InstanceType, AUTOMATIC, FEE_30_FLEXNOR_VAR) Fee_30_FlexNor_ConstInstancePtrType;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
# define FEE_30_FLEXNOR_START_SEC_CODE
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define FEE_30_FLEXNOR_STOP_SEC_CODE
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* FEE_30_FLEXNOR_INSTANCE_H */

/**********************************************************************************************************************
 *  END OF FILE: Fee_30_FlexNor_Instance.h
 *********************************************************************************************************************/
