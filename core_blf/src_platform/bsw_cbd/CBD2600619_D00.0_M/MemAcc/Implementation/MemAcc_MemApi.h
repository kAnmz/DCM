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
/*!        \file  MemAcc_MemApi.h
 *        \brief  MemAcc Mem driver API header file
 *      \details  Defines API for Mem drivers.
 *         \unit  MemAcc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#if !defined (MEMACC_MEMAPI_H)
# define MEMACC_MEMAPI_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "MemAcc_GeneralTypes.h"

/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/
typedef MemAcc_AddressType MemAcc_MemAddressType;
typedef MemAcc_DataType    MemAcc_MemDataType;
typedef uint32             MemAcc_MemInstanceIdType;
typedef MemAcc_LengthType  MemAcc_MemLengthType;
typedef uint32             MemAcc_MemHwServiceIdType;

typedef void MemAcc_MemConfigType;

typedef void (*MemAcc_MemInitFuncType)(const MemAcc_MemConfigType* configPtr);
typedef void (*MemAcc_MemDeinitFuncType)(void);
typedef void (*MemAcc_MemMainFuncType)(void);
typedef Std_ReturnType (*MemAcc_MemReadFuncType)(MemAcc_MemInstanceIdType instanceId, MemAcc_MemAddressType sourceAddress, MemAcc_MemDataType* destinationDataPtr, MemAcc_MemLengthType length);
typedef Std_ReturnType (*MemAcc_MemWriteFuncType)(MemAcc_MemInstanceIdType instanceId, MemAcc_MemAddressType targetAddress, const MemAcc_MemDataType* sourceDataPtr, MemAcc_MemLengthType length);
typedef Std_ReturnType (*MemAcc_MemEraseFuncType)(MemAcc_MemInstanceIdType instanceId, MemAcc_MemAddressType targetAddress, MemAcc_MemLengthType length);
typedef void (*MemAcc_MemPropagateErrorFuncType)(MemAcc_MemInstanceIdType instanceId);
typedef Std_ReturnType (*MemAcc_MemBlankCheckFuncType)(MemAcc_MemInstanceIdType instanceId, MemAcc_MemAddressType targetAddress, MemAcc_MemLengthType length);
typedef Std_ReturnType (*MemAcc_MemSuspendFuncType)(MemAcc_MemInstanceIdType instanceId);
typedef Std_ReturnType (*MemAcc_MemResumeFuncType)(MemAcc_MemInstanceIdType instanceId);
typedef Std_ReturnType (*MemAcc_MemHwSpecificServiceFuncType)(MemAcc_MemInstanceIdType instanceId, MemAcc_MemHwServiceIdType hwServiceId, MemAcc_MemDataType* dataPtr, MemAcc_MemLengthType* lengthPtr);
typedef MemAcc_MemJobResultType (*MemAcc_MemGetJobResultFuncType)(MemAcc_MemInstanceIdType instanceId);

typedef struct
{
   uint64                                 UniqueID;               /*!< Unique ID. */
   uint64                                 Flags;                  /*!< Header flags. */
   MemAcc_AddressType                     Header;                 /*!< Address of Mem driver image header structure. */
   MemAcc_AddressType                     Delimiter;              /*!< Address of Mem driver image delimiter pattern. */
   MemAcc_MemInitFuncType                 InitFunc;               /*!< Mem_Init function pointer. */
   MemAcc_MemDeinitFuncType               DeinitFunc;             /*!< Mem_Deinit function pointer. */
   MemAcc_MemMainFuncType                 MainFunc;               /*!< Mem_Main function pointer. */
   MemAcc_MemGetJobResultFuncType         GetJobResultFunc;       /*!< Mem_GetJobResult function pointer. */
   MemAcc_MemReadFuncType                 ReadFunc;               /*!< Mem_Read function pointer. */
   MemAcc_MemWriteFuncType                WriteFunc;              /*!< Mem_Write function pointer. */
   MemAcc_MemEraseFuncType                EraseFunc;              /*!< Mem_Erase function pointer. */
   MemAcc_MemPropagateErrorFuncType       PropagateErrorFunc;     /*!< Mem_PropagateError function pointer.  */
   MemAcc_MemBlankCheckFuncType           BlankCheckFunc;         /*!< Mem_BlankCheck function pointer. */
   MemAcc_MemSuspendFuncType              SuspendFunc;            /*!< Mem_Suspend function pointer. */
   MemAcc_MemResumeFuncType               ResumeFunc;             /*!< Mem_Resume function pointer. */
   MemAcc_MemHwSpecificServiceFuncType    HwSpecificServiceFunc;  /*!< Mem_HwSpecificService function pointer. */
} MemAcc_MemBinaryHeaderType;


/***********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

#endif /* MEMACC_MEMAPI_H */

/**********************************************************************************************************************
 *  END OF FILE: MemAcc_MemApi.h
 *********************************************************************************************************************/
