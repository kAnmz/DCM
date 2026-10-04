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
/*!        \file  MemAcc_InternalTypes.h
 *        \brief  MemAcc types header file
 *      \details  Defines MemAcc types.
 *         \unit  MemAcc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#if !defined (MEMACC_INTERNALTYPES_H)
# define MEMACC_INTERNALTYPES_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "MemAcc_GeneralTypes.h"
# include "MemAcc_MemApi.h"
# include "MemAcc_Cfg.h"
# include "MemAcc_BBMHwSpecificServiceTypes.h"

#if defined(MEMACC_VCA_SILENT) /* COV_MEMACC_VCA */
void* GetMemAccQueueRange(void);
#endif

/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/

#define MemAcc_GetSizeOfLowerLayer()             MemAcc_GetSizeOfCLowerLayer()

/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
/* This Type represents the MemAcc_JobType enum as uint8 value for atomic read/write operations. */
typedef uint8                                      MemAcc_AtomicJobType;
typedef uint8                                      MemAcc_JobStepRetryCounterType;
/*!
 * \spec strong type invariant () { self < MEMACC_NUMBER_OF_SYNCHRONIZATION_GROUPS; } \endspec
 */
typedef MemAcc_SyncGroupIdOfSubAddressAreaType     MemAcc_SyncGroupIndexType;
typedef MemAcc_PriorityBasedIndexOfAddressAreaType MemAcc_JobPriorityIndexType;
/*!
 * \spec strong type invariant () { self < MemAcc_GetSizeOfAddressArea(); } \endspec
 */
typedef MemAcc_SizeOfAddressAreaType              MemAcc_AddressAreaIndexType;
/*!
 * \spec strong type invariant () { self < MemAcc_GetSizeOfSubAddressArea(); } \endspec
 */
typedef MemAcc_SizeOfSubAddressAreaType           MemAcc_SubAddressAreaIndexType;
/*!
 * \spec strong type invariant () { self < MemAcc_GetSizeOfLowerLayer() } \endspec
 */
typedef MemAcc_SizeOfCLowerLayerType              MemAcc_LowerLayerIndexType;

typedef enum
{
  MEMACC_LOCKSTATE_UNLOCKED = 0,
  MEMACC_LOCKSTATE_LOCKED
} MemAcc_MemLockStateType;

typedef enum
{
  MEMACC_JOBCLASSIFICATION_USERJOB,
  MEMACC_JOBCLASSIFICATION_BBM_READBBMARKER,
  MEMACC_JOBCLASSIFICATION_BBM_RECOVERSECTOR,
  MEMACC_JOBCLASSIFICATION_BBM_ERASEBLOCK,
  MEMACC_JOBCLASSIFICATION_BBM_WRITEBBMARKER
} MemAcc_JobClassificationType;

typedef boolean MemAcc_JobStepIsSuspendedType;

typedef struct
{
  MemAcc_JobStatusType            Status;             /*!< Stores the current job step status. */
  MemAcc_JobResultType            Result;             /*!< Stores the latest job step result. */
  MemAcc_SubAddressAreaIndexType  SubAddrAreaIdx;     /*!< Stores the current job step target sub address area index. */
  MemAcc_LengthType               Length;             /*!< Stores the latest job step length */
  MemAcc_AddressType              LogicalAddress;     /*!< Stores the logical address of the current memory driver request. */
  MemAcc_AddressType              PhysicalAddress;    /*!< Stores the physical address of the current memory driver request. */
  MemAcc_JobStepRetryCounterType  RetryCounter;       /*!< Stores the number of retries left for this job step. */
  MemAcc_JobStepIsSuspendedType   IsSuspended;        /*!< Stores the status whether a job step is suspended. */
  boolean                         Rejected;           /*!< Stores wether a job step was rejected. */
#if (MEMACC_BBM_ENABLED == STD_ON)
  MemAcc_MemErrorType             MemError;           /*!< Stores errorstate from mem in case of failed job step. */
#endif /* (MEMACC_BBM_ENABLED == STD_ON) */
} MemAcc_JobStepType; /*!< Stores runtime information about the current/last processed job step. */

typedef struct
{
  MemAcc_JobStepType       JobStep;              /*!< Stores information related to single job steps. */
  MemAcc_JobResultType     JobResult;            /*!< Stores the latest published address area job result. */
  MemAcc_LengthType        Offset;               /*!< Stores the current job progress (already done bytes)
                                                      from start address. */
  boolean                  ReadJobEccCorrected;  /*!< Store the information that one Read Job step had
                                                      result MEM_ECC_CORRECTED */
  boolean                  JobCanceled;          /*!< Stores the information that the job was canceled */
  MemAcc_ErrorType         JobError;             /*!< Stores wether an internal error was detected during execution */
} MemAcc_MngmtAreaType; /*!< Stores runtime information about one single address area. */

typedef struct
{
  MemAcc_AddressAreaIndexType AddressAreaIndex;                  /*!< Index of the job in the MemAcc_AddressArea. */
  MemAcc_AtomicJobType JobType;                                  /*!< Job to be done for this queue element. */
  MemAcc_AddressType Address;                                    /*!< Address the job shall be done for. */
  MemAcc_LengthType Length;                                      /*!< Job length. */
  MemAcc_DataType* DataBuffer;                                   /*!< Mutable data buffer used for read, compare, and hwSpecific requests. */
  const MemAcc_DataType* ConstDataBuffer;                        /*!< Const data buffer used for write and compare requests. */
  MemAcc_HwIdType HwId;                                          /*!< Referenced memory driver hardware identifier. */
  MemAcc_MemHwServiceIdType HwServiceId;                         /*!< Index type for Mem driver hardware specific service table. */
  MemAcc_LengthType* LengthPtr;                                  /*!< Length of data buffer used for hwSpecific. */
  MemAcc_ApplicationLockNotificationType LockNotificationFctPtr; /*!< Pointer to lock notification callback function. */
  MemAcc_JobClassificationType JobClassification;                /*!< Indicates the origin and type of the job. */
} MemAcc_JobAreaType; /*!< Stores the job information about one single address area as a queue entry. */

typedef struct
{
  MemAcc_MngmtAreaType MngmtArea; /*!< Runtime information */
  MemAcc_JobAreaType JobArea;     /*!< Static job information */
} MemAcc_JobContextType;   /*!< Overall job contect information for one Address Area */

/***********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

#endif /* MEMACC_INTERNALTYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: MemAcc_InternalTypes.h
 *********************************************************************************************************************/
