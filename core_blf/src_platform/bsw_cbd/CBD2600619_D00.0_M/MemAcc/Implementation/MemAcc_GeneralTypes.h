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
/*!        \file  MemAcc_GeneralTypes.h
 *        \brief  MemAcc types header file
 *      \details  Defines MemAcc types.
 *         \unit  MemAcc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#if !defined (MEMACC_GENERALTYPES_H)
# define MEMACC_GENERALTYPES_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "Std_Types.h"
# include "MemAcc_MemCfg.h"

/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/
/* Vendor and module identification */
# define MEMACC_VENDOR_ID               (30u)
# define MEMACC_MODULE_ID               (41u)
# define MEMACC_INSTANCE_ID             (0u)

/* ----- Modes ----- */
# define MEMACC_UNINIT                  (0x00u)
# define MEMACC_INIT                    (0x01u)

#ifndef E_MEM_SERVICE_NOT_AVAIL /* COV_MemAcc_COMPATIBILITY */
# define E_MEM_SERVICE_NOT_AVAIL   (0x03u)
#endif

/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

# if (MEMACC_64BITSUPPORT == STD_ON)
typedef uint64 MemAcc_AddressType; /*!< Logical memory address type. */
typedef uint64 MemAcc_LengthType;  /*!< Job length type. */
# else
typedef uint32 MemAcc_AddressType; /*!< Logical memory address type. */
typedef uint32 MemAcc_LengthType;  /*!< Job length type. */
# endif

typedef uint16 MemAcc_AddressAreaIdType;    /*!< Unique address area ID type. */
typedef uint8  MemAcc_DataType;             /*!< General data type. */

typedef enum
{
  MEM_JOB_OK = 0,      /*!< The last job has been finished successfully */
  MEM_JOB_PENDING,     /*!< A job is currently being processed */
  MEM_JOB_FAILED,      /*!< Job failed for some unspecific reason */
  MEM_INCONSISTENT,    /*!< The checked page is not blank */
  MEM_ECC_UNCORRECTED, /*!< Uncorrectable ECC errors occurred during memory access */
  MEM_ECC_CORRECTED    /*!< Correctable ECC errors occurred during memory access */
} MemAcc_MemJobResultType; /*!< Stores all possible Mem results. */

#ifdef MEMACC_ASR22_11_COMPATIBILITY /* COV_MemAcc_COMPATIBILITY */
/* Between AUTOSAR 22-11 and 23-11 member names of enum MemAcc_JobResultType
   and struct MemAcc_MemoryInfoType changed.
   For backward compatibility old names are provided if the user of the MemAcc relies on them */
# define MEMACC_OK MEMACC_MEM_OK
# define MEMACC_FAILED MEMACC_MEM_FAILED
# define MEMACC_INCONSISTENT MEMACC_MEM_INCONSISTENT
# define MEMACC_CANCELED MEMACC_MEM_CANCELED
# define MEMACC_ECC_UNCORRECTED MEMACC_MEM_ECC_UNCORRECTED
# define MEMACC_ECC_CORRECTED MEMACC_MEM_ECC_CORRECTED

typedef enum
{
  MEMACC_MEM_OK = 0,          /*!< The last job was finished successfully. */
  MEMACC_MEM_FAILED,          /*!< The last job resulted in an unspecific failure, job was not completed. */
  MEMACC_MEM_INCONSISTENT,    /*!< The results of the job did not meet the expected result. */
                              /*!< e.g. a blank check operation was applied on a non-blank memory area. */
  MEMACC_MEM_CANCELED,        /*!< The last job was canceled. */
  MEMACC_MEM_ECC_UNCORRECTED, /*!< The last memory operation returned an uncorrectable ECC error. */
  MEMACC_MEM_ECC_CORRECTED    /*!< The last memory operation returned a correctable ECC error. */
} MemAcc_JobResultType;   /*!< Stores all possible MemAcc results. */

typedef struct
{
  MemAcc_AddressType  LogicalStartAddress;    /*!< Logical start address of sub address area. */
  MemAcc_AddressType  PhysicalStartAddress;   /*!< Physical start address of sub address area. */
  MemAcc_LengthType   MaxOffset;              /*!< Size of sub address area in bytes -1. */
  uint32              EraseSectorSize;        /*!< Size of a sector in bytes. */
  uint32              EraseSectorBurstSize;   /*!< Size of a sector burst in bytes. Equals SectorSize in case burst is disabled. */
  uint32              ReadPageSize;           /*!< Smallest readable unit in bytes. */
  uint32              WritePageSize;          /*!< Write size of a page in bytes. */
  uint32              ReadPageBurstSize;      /*!< Largest readable unit in bytes. */
  uint32              WritePageBurstSize;     /*!< Size of a page burst in bytes. Equals WritePageSize in case burst is disabled. */
  MemAcc_HwIdType     HwId;                   /*!< Referenced memory driver hardware identifier. */
} MemAcc_MemoryInfoType; /*!< This structure contains information of Mem device characteristics. It can be accessed via the MemAcc_GetMemoryInfo() service. */
#else
typedef enum
{
  MEMACC_OK = 0,          /*!< The last job was finished successfully. */
  MEMACC_FAILED,          /*!< The last job resulted in an unspecific failure, job was not completed. */
  MEMACC_INCONSISTENT,    /*!< The results of the job did not meet the expected result. */
                          /*!< e.g. a blank check operation was applied on a non-blank memory area. */
  MEMACC_CANCELED,        /*!< The last job was canceled. */
  MEMACC_ECC_UNCORRECTED, /*!< The last memory operation returned an uncorrectable ECC error. */
  MEMACC_ECC_CORRECTED    /*!< The last memory operation returned a correctable ECC error. */
} MemAcc_JobResultType;   /*!< Stores all possible MemAcc results. */

typedef struct
{
  MemAcc_AddressType  LogicalStartAddress;    /*!< Logical start address of sub address area. */
  MemAcc_AddressType  PhysicalStartAddress;   /*!< Physical start address of sub address area. */
  MemAcc_LengthType   MaxOffset;              /*!< Size of sub address area in bytes -1. */
  uint32              EraseSectorSize;        /*!< Size of a sector in bytes. */
  uint32              EraseSectorBurstSize;   /*!< Size of a sector burst in bytes. Equals SectorSize in case burst is disabled. */
  uint32              MinReadSize;            /*!< Smallest readable unit in bytes. */
  uint32              WritePageSize;          /*!< Write size of a page in bytes. */
  uint32              MaxReadSize;            /*!< Largest readable unit in bytes. */
  uint32              WritePageBurstSize;     /*!< Size of a page burst in bytes. Equals WritePageSize in case burst is disabled. */
  MemAcc_HwIdType     HwId;                   /*!< Referenced memory driver hardware identifier. */
} MemAcc_MemoryInfoType; /*!< This structure contains information of Mem device characteristics. It can be accessed via the MemAcc_GetMemoryInfo() service. */
#endif

typedef enum
{
  MEMACC_JOB_IDLE = 0,  /*!< Job processing was completed or no job currently pending. */
  MEMACC_JOB_PENDING    /*!< Job is currently being processed. */
} MemAcc_JobStatusType; /*!< Stores the asynchronous job status. */

typedef enum
{
  MEMACC_NO_JOB = 0,        /*!< No job currently pending. */
  MEMACC_WRITE_JOB,         /*!< Write job pending. */
  MEMACC_READ_JOB,          /*!< Read job pending. */
  MEMACC_COMPARE_JOB,       /*!< Compare job pending. */
  MEMACC_ERASE_JOB,         /*!< Erase job pending. */
  MEMACC_MEMHWSPECIFIC_JOB, /*!< Hardware specific job pending. */
  MEMACC_BLANKCHECK_JOB,    /*!< Blank check job pending. */
  MEMACC_REQUESTLOCK_JOB    /*!< Request lock job pending. */
} MemAcc_JobType; /*!< Stores the type for asynchronous jobs. */

typedef struct
{
  MemAcc_AddressType        LogicalAddress;     /*!< Address of currently active address area request. */
  MemAcc_LengthType         Length;             /*!< Length of the currently active address area request. */
  MemAcc_HwIdType           HwId;               /*!< Referenced memory driver hardware identifier. */
  uint32                    MemInstanceId;      /*!< Instance ID of the current memory request. */
  MemAcc_AddressType        MemAddress;         /*!< Physical address of the current memory driver request. */
  MemAcc_LengthType         MemLength;          /*!< Length of memory driver request. */
  MemAcc_JobType            CurrentJob;         /*!< Currently active MemAcc job. */
  MemAcc_MemJobResultType   MemResult;          /*!< Current or last Mem driver result. */
} MemAcc_JobInfoType; /*!< This structure contains information the current processing state of the MemAcc module. */

typedef void (*MemAcc_JobEndNotificationFuncType)(MemAcc_AddressAreaIdType addressAreaId, MemAcc_JobResultType jobResult);

typedef enum
{
  MEMACC_ERRORTYPE_NONE = 0u,                         /*!< No Error. */
  MEMACC_ERRORTYPE_BBM_READBBMARKER_REJECTED,         /*!< Read BB marker job was rejected. */
  MEMACC_ERRORTYPE_BBM_READBBMARKER_FAILED,           /*!< Read BB marker job failed. */
  MEMACC_ERRORTYPE_BBM_RECOVERSECTOR_REJECTED,        /*!< Recover Sector job was rejected. */
  MEMACC_ERRORTYPE_BBM_RECOVERSECTOR_FAILED,          /*!< Recover Sector job failed. */
  MEMACC_ERRORTYPE_BBM_ERASEBLOCK_REJECTED,           /*!< Erase block job was rejected. */
  MEMACC_ERRORTYPE_BBM_ERASEBLOCK_FAILED,             /*!< Erase block job failed. */
  MEMACC_ERRORTYPE_BBM_WRITEBBMARKER_REJECTED,        /*!< Write BB marker job was rejected. */
  MEMACC_ERRORTYPE_BBM_WRITEBBMARKER_FAILED,          /*!< Write BB marker job failed. */
  MEMACC_ERRORTYPE_BBM_READERRORSTATE_REJECTED,       /*!< Read Error State job was rejected. */
  MEMACC_ERRORTYPE_BBM_READERRORSTATE_INVALIDADDRESS, /*!< Read Error State job returned a invalid physical address. */
  MEMACC_ERRORTYPE_BBM_BBLUTFULL,                     /*!< BB need to be inserted but BB LUT is full. */
  MEMACC_ERRORTYPE_BBM_RECOVERYTARGETOUTOFBOUNDS,     /*!< Recovery target for recover sector job is out of bounds. */
  MEMACC_ERRORTYPE_BBM_TRANSLATEDADDRESSOUTOFBOUNDS,  /*!< Translated physical address is out of bounds. */
  MEMACC_ERRORTYPE_BBM_UNEXPECTED_P_FAIL,             /*!< Unexpected P_FAIL error. */
  MEMACC_ERRORTYPE_BBM_UNEXPECTED_E_FAIL              /*!< Unexpected E_FAIL error. */
} MemAcc_ErrorType; /*!< This enum indicates the type of error for NAND bad block management that occoured. */

typedef void (*MemAcc_ErrorNotificationFuncType)(MemAcc_AddressAreaIdType addressAreaId, MemAcc_ErrorType errorType);

typedef void (*MemAcc_ApplicationLockNotificationType)(void);

/***********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

#endif /* MEMACC_GENERALTYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: MemAcc_GeneralTypes.h
 *********************************************************************************************************************/
