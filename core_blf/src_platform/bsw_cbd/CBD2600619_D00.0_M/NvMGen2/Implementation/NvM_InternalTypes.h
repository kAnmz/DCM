/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2026 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!        \file  NvM_InternalTypes.h
 *        \brief  NvM internal types header file.
 *         \unit  NvM
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#if (!defined NVM_INTERNALTYPES_H)
#define NVM_INTERNALTYPES_H

/***********************************************************************************************************************
 * INCLUDES
 **********************************************************************************************************************/
# include "NvM_Types.h"
# include "NvM_CfgDefines.h"

/**********************************************************************************************************************
  GLOBAL CONSTANT MACROS
**********************************************************************************************************************/

/* First Block Id to start internal iterations over block descriptor table. */
#define NVM_FIRST_INTERNAL_BLOCK_ID            0u

/* Immediate job priority */
#define NVM_IMMEDIATE_JOB_PRIORITY             0u

/* ConfigBlock Id is always first internal block id in case of dynamic configuration enabled. */
#if (NVM_DYNAMIC_CONFIGURATION == STD_ON)
#define NVM_CONFIG_BLOCK_ID                    NVM_FIRST_INTERNAL_BLOCK_ID
#endif

/* Block management types */
#define NVM_BLOCK_MANAGEMENT_TYPE_NATIVE       0u
#define NVM_BLOCK_MANAGEMENT_TYPE_DATASET      1u
#define NVM_BLOCK_MANAGEMENT_TYPE_REDUNDANT    2u

/* Data integrity types */
/* Note: CRC_8 not used (not supported) but define kept for completeness. */
#define NVM_BLOCK_DATA_INTEGRITY_OFF             0u
#define NVM_BLOCK_DATA_INTEGRITY_CRC_8           1u
#define NVM_BLOCK_DATA_INTEGRITY_CRC_16          2u
#define NVM_BLOCK_DATA_INTEGRITY_CRC_32          3u
#define NVM_BLOCK_DATA_INTEGRITY_MAC             4u

/* Special value for CrcCompBuffer in case default data were restored */
#define NVM_CRCCOMPBUFFER_RESET_VALUE            0xFFu

/* Size of DataIntegrityRecord in bytes */
#define NVM_DATAINTEGRITYRECORD_SIZE_CRC16       2u
#define NVM_DATAINTEGRITYRECORD_SIZE_CRC32       4u

/* Block's Flag bit mask, used in the block descriptor element "Flags" */
#define NVM_SELECT_BLOCK_FOR_READALL_ON          STD_ON
#define NVM_SELECT_BLOCK_FOR_READALL_OFF         STD_OFF
#define NVM_SELECT_BLOCK_FOR_WRITEALL_ON         STD_ON
#define NVM_SELECT_BLOCK_FOR_WRITEALL_OFF        STD_OFF
#define NVM_INVOKE_CALLBACKS_FOR_READALL_ON      STD_ON
#define NVM_INVOKE_CALLBACKS_FOR_READALL_OFF     STD_OFF
#define NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON    STD_ON
#define NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_OFF   STD_OFF
#define NVM_RESISTANT_TO_CHANGED_SW_ON           STD_ON
#define NVM_RESISTANT_TO_CHANGED_SW_OFF          STD_OFF
#define NVM_WRITE_BLOCK_ONCE_ON                  STD_ON
#define NVM_WRITE_BLOCK_ONCE_OFF                 STD_OFF
#define NVM_BLOCK_WRITE_PROT_ON                  STD_ON
#define NVM_BLOCK_WRITE_PROT_OFF                 STD_OFF
#define NVM_CALC_RAM_BLOCK_CRC_ON                STD_ON
#define NVM_CALC_RAM_BLOCK_CRC_OFF               STD_OFF
#define NVM_BLOCK_USE_AUTO_VALIDATION_ON         STD_ON
#define NVM_BLOCK_USE_AUTO_VALIDATION_OFF        STD_OFF


/*
 * Flags of MultiBlock job information
 * Limitation to 16 bits
 */

#define NVM_MULTIBLOCK_FLAG_READALL_REQUESTED           0u
#define NVM_MULTIBLOCK_FLAG_READALL_ACTIVE              1u
#define NVM_MULTIBLOCK_FLAG_WRITEALL_REQUESTED          2u
#define NVM_MULTIBLOCK_FLAG_WRITEALL_ACTIVE             3u
#define NVM_MULTIBLOCK_FLAG_WRITEALL_CANCEL_REQUESTED   4u
#define NVM_MULTIBLOCK_FLAG_VALIDATEALL_REQUESTED       5u
#define NVM_MULTIBLOCK_FLAG_VALIDATEALL_ACTIVE          6u

/* Special value of IMMEDIATE block priority */
#define NVM_BLOCK_PRIORITY_IMMEDIATE                    0u

/*
 * Satellite Port Single Block Job Request types
 */

#define NVM_SATELLITE_SINGLEBLOCK_JOB_REQUEST_NONE              0u
#define NVM_SATELLITE_SINGLEBLOCK_JOB_REQUEST_REQUESTED         1u
#define NVM_SATELLITE_SINGLEBLOCK_JOB_REQUEST_CANCEL_IMMEDIATE  2u

/*
 * Satellite Port MultiBlock Job Status types
 */

#define NVM_SATELLITE_MULTIBLOCK_JOB_STATUS_NONE       0u
#define NVM_SATELLITE_MULTIBLOCK_JOB_STATUS_READY      1u
#define NVM_SATELLITE_MULTIBLOCK_JOB_STATUS_ACTIVE     2u
#define NVM_SATELLITE_MULTIBLOCK_JOB_STATUS_NOT_OK     3u
#define NVM_SATELLITE_MULTIBLOCK_JOB_STATUS_OK         4u


/*
 * MasterSatellite Port Single Block Job Status types
 */

#define NVM_MASTERSATELLITE_SINGLEBLOCK_JOB_STATUS_NONE               0u
#define NVM_MASTERSATELLITE_SINGLEBLOCK_JOB_STATUS_PENDING            1u
#define NVM_MASTERSATELLITE_SINGLEBLOCK_JOB_STATUS_NOT_OK             2u
#define NVM_MASTERSATELLITE_SINGLEBLOCK_JOB_STATUS_OK                 3u
#define NVM_MASTERSATELLITE_SINGLEBLOCK_JOB_STATUS_CANCELED           4u

/*
 * MasterSatellite Port MultiBlock Job Request types
 */

#define NVM_MASTERSATELLITE_MULTIBLOCK_JOB_REQUEST_NONE          0u
#define NVM_MASTERSATELLITE_MULTIBLOCK_JOB_REQUEST_REQUESTED     1u
#define NVM_MASTERSATELLITE_MULTIBLOCK_JOB_REQUEST_PROCESSING    2u

/*
 * DataIntegrityRecalcQueue
 */

/* Bitstring definitions to operate queueing mechanism */
#define NVM_DATAINTEGRITYRECALCQUEUE_ENTRY_BITS                             32u                 /* 32-bit words are stored */
#define NVM_DATAINTEGRITYRECALCQUEUE_ENTRY_BITMASK                          0x1Fu               /* 31 shifts maximum allowed for a 32-bit word */
#define NVM_DATAINTEGRITYRECALCQUEUE_ENTRY_SHIFT                            5u                  /* 2^5=32, shift left by this provides index of word in array */
#define NVM_DATAINTEGRITYRECALCQUEUE_ENTRY_MASK                             0xFFFFFFFFu         /* Full 32-bit mask */

/* Amount of elements to store all possible block IDs: count=(entries + 31) / 32
   note: this is essentially computing count=ceil(entries / 32) */
#define NVM_DATAINTEGRITYRECALCQUEUE_ELEMENTCOUNT ((NVM_NUM_OF_BLOCKDESCRIPTORS + NVM_DATAINTEGRITYRECALCQUEUE_ENTRY_BITMASK) >> NVM_DATAINTEGRITYRECALCQUEUE_ENTRY_SHIFT)



/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

 /*!
 * \spec strong type invariant () { self < GetSizeOfBlockDescriptor() } \endspec
 */
typedef NvM_BlockIdType NvM_BlockDescriptorLookupTableIdType;

/* Definition of Single Block Job Types */
typedef enum
{
  NVM_SINGLEBLOCKJOBTYPE_NONE,                        /*!< No NvM single block job is requested. */
  NVM_SINGLEBLOCKJOBTYPE_READ_BLOCK,                  /*!< NvM read block job is requested. */
  NVM_SINGLEBLOCKJOBTYPE_WRITE_BLOCK,                 /*!< NvM write block job is requested. */
  NVM_SINGLEBLOCKJOBTYPE_READ_ALL_BLOCK,              /*!< NvM read block job in ReadAll context is requested */
  NVM_SINGLEBLOCKJOBTYPE_WRITE_ALL_BLOCK,             /*!< NvM write block job in WriteAll context is requested */
  NVM_SINGLEBLOCKJOBTYPE_INVALIDATE_NV_BLOCK,         /*!< NvM invalidate nv block job is requested */
  NVM_SINGLEBLOCKJOBTYPE_ERASE_NV_BLOCK,              /*!< NvM erase nv block job is requested */
  NVM_SINGLEBLOCKJOBTYPE_RESTORE_BLOCK_DEFAULTS       /*!< NvM restore block defaults job is requested */
} NvM_SingleBlockJobType;

/* Definition of MultiBlock Job Types */
typedef enum
{
  NVM_MULTIBLOCKJOBTYPE_NONE,                         /*!< No NvM multiblock job is requested */
  NVM_MULTIBLOCKJOBTYPE_READ_ALL,                     /*!< NvM ReadAll job is requested */
  NVM_MULTIBLOCKJOBTYPE_WRITE_ALL,                    /*!< NvM WriteAll job is requested */
  NVM_MULTIBLOCKJOBTYPE_CANCEL_WRITE_ALL,             /*!< NvM CancelWriteAll job is requested */
  NVM_MULTIBLOCKJOBTYPE_KILL_WRITE_ALL,               /*!< NvM KillWriteAll job is requested */
  NVM_MULTIBLOCKJOBTYPE_KILL_READ_ALL,                /*!< NvM KillReadAll job is requested */
  NVM_MULTIBLOCKJOBTYPE_VALIDATE_ALL                  /*!< NvM ValidateAll job is requested */
} NvM_MultiBlockJobType;

/*
 * Types of partition-specific information
 */


/*! Type of partition ID
 * \spec strong type invariant () { self < GetSizeOfPartitionIdentifiers() } \endspec
 */
typedef uint8 NvM_PartitionIdType;

/*!< Pointer type referencing a partition ID */
typedef P2VAR(NvM_PartitionIdType, AUTOMATIC, NVM_PRIVATE_DATA) NvM_PartitionIdPtrType;

/*! Type of request counter */
typedef uint8 NvM_RequestCounterType;

/*!< Pointer type referencing a request counter */
typedef P2VAR(NvM_RequestCounterType, AUTOMATIC, NVM_PRIVATE_DATA) NvM_RequestCounterPtrType;

/*! Type of satellite single block job request */
typedef uint8 NvM_SatelliteSingleBlockJobRequestType;

/*! Type of satellite multiblock job status */
typedef uint8 NvM_SatelliteMultiBlockJobStatusType;

/*! Type of master single block job status */
typedef uint8 NvM_MasterSingleBlockJobStatusType;

/*! Type of master multiblock job request */
typedef uint8 NvM_MasterMultiBlockJobRequestType;

/*
 * Types of satellite ports
 */

/*!< Structure containing the satellite job information relevant for multipartition communication */
typedef struct
{
  NvM_SingleBlockJobType               SingleBlockJobType;             /*! Type of single block job to be performed */
  NvM_BlockDescriptorLookupTableIdType BlockDescriptorLookupTableId;   /*! Block Descriptor lookup table identifier */
  uint8                                DataIndex;                      /*! Data Index of Block */
} NvM_SatelliteJobInformationType;

/*!< Pointer type referencing a satellite job information */
typedef P2VAR(NvM_SatelliteJobInformationType, AUTOMATIC, NVM_PRIVATE_DATA) NvM_SatelliteJobInformationPtrType;

/*!< Pointer to constant type referencing a satellite job information */
typedef P2CONST(NvM_SatelliteJobInformationType, AUTOMATIC, NVM_PRIVATE_DATA) NvM_SatelliteJobInformationPtrToConstType;

/*!< Structure containing the satellite single block job port */
typedef struct
{
  NvM_SatelliteJobInformationType         JobInformation;    /*! Job information of satellite */
  NvM_RequestCounterType                  RequestCounter;    /*! Request counter to synchronize satellite and master */
  NvM_SatelliteSingleBlockJobRequestType  JobRequest;        /*! Satellite single block job request status */
} NvM_SatellitePort_SingleBlockJobType;

/*!< Pointer to constant type referencing a single block job port */
typedef P2CONST(NvM_SatellitePort_SingleBlockJobType, TYPEDEF, NVM_VAR_NO_INIT)
  NvM_SatellitePort_SingleBlockJobPtrToConstType;

/*!< Constant pointer to constant type referencing a single block job port */
typedef CONSTP2CONST(NvM_SatellitePort_SingleBlockJobType, TYPEDEF, NVM_VAR_NO_INIT)
  NvM_SatellitePort_SingleBlockJobConstPtrToConstType;

/*!< Structure containing the satellite multiblock job port */
typedef struct
{
  NvM_SatelliteMultiBlockJobStatusType    JobStatus;         /*! Satellite multiblock job status */
} NvM_SatellitePort_MultiBlockJobType;

/*!< Pointer to constant type referencing a multiblock job port */
typedef P2CONST(NvM_SatellitePort_MultiBlockJobType, TYPEDEF, NVM_VAR_NO_INIT)
  NvM_SatellitePort_MultiBlockJobPtrToConstType;

/*!< Constant pointer to constant type referencing a multiblock job port */
typedef CONSTP2CONST(NvM_SatellitePort_MultiBlockJobType, TYPEDEF, NVM_VAR_NO_INIT)
  NvM_SatellitePort_MultiBlockJobConstPtrToConstType;

/*
 * Types of master ports
 */

/*!< Structure containing the master - satellite single block job port */
typedef struct
{
  NvM_RequestCounterType              RequestCounter;    /*! Request counter to synchronize satellite and master */
  NvM_MasterSingleBlockJobStatusType  JobStatus;         /*! Master single block job status */
} NvM_MasterSatellitePort_SingleBlockJobType;

/*!< Pointer type referencing a master - satellite single block job port */
typedef P2VAR(NvM_MasterSatellitePort_SingleBlockJobType, AUTOMATIC, NVM_PRIVATE_DATA)
  NvM_MasterSatellitePort_SingleBlockJobPtrType;

/*!< Constant Pointer to a master - satellite single block job port */
typedef CONSTP2VAR(NvM_MasterSatellitePort_SingleBlockJobType, AUTOMATIC, NVM_PRIVATE_DATA)
  NvM_MasterSatellitePort_SingleBlockJobConstPtrType;

/*!< Pointer to constant type referencing a master - satellite single block job port */
typedef P2CONST(NvM_MasterSatellitePort_SingleBlockJobType, AUTOMATIC, NVM_PRIVATE_DATA)
  NvM_MasterSatellitePort_SingleBlockJobPtrToConstType;

/*!< Structure containing the master - satellite multiblock job port */
typedef struct
{
  NvM_MultiBlockJobType                 JobType;            /*! Type of job to be performed */
  NvM_MasterMultiBlockJobRequestType    JobRequest;         /*! Master multiblock job request */
} NvM_MasterSatellitePort_MultiBlockJobType;

/*!< Pointer type referencing a master - satellite multiblock job port */
typedef P2VAR(NvM_MasterSatellitePort_MultiBlockJobType, AUTOMATIC, NVM_PRIVATE_DATA)
  NvM_MasterSatellitePort_MultiBlockJobPtrType;

/*!< Constant Pointer to a master - satellite multiblock job port */
typedef CONSTP2VAR(NvM_MasterSatellitePort_MultiBlockJobType, AUTOMATIC, NVM_PRIVATE_DATA)
  NvM_MasterSatellitePort_MultiBlockJobConstPtrType;

/*!< Pointer to constant type referencing a master - satellite multiblock job port */
typedef P2CONST(NvM_MasterSatellitePort_MultiBlockJobType, AUTOMATIC, NVM_PRIVATE_DATA)
  NvM_MasterSatellitePort_MultiBlockJobPtrToConstType;

/*
 * Types of Errors
 */

/*!< Type of DET errors. */
typedef uint8 NvM_DetErrorIdType;

/*! Type of DEM error counts */
typedef uint8 NvM_DemErrorCountType;

/*!< Structure containing DEM error counters port */
typedef struct
{
  NvM_DemErrorCountType DataIntegrityFailedError;     /*! Type of Data Integrity failed error count */
  NvM_DemErrorCountType ReqFailedError;               /*! Type of request failed error count */
} NvM_ErrorCountersPortType;

/*!< Pointer type referencing a error counters port */
typedef P2VAR(NvM_ErrorCountersPortType, AUTOMATIC, NVM_PRIVATE_DATA) NvM_ErrorCountersPortPtrType;

/*!< Constant Pointer to a error counters port */
typedef CONSTP2VAR(NvM_ErrorCountersPortType, AUTOMATIC, NVM_PRIVATE_DATA) NvM_ErrorCountersPortConstPtrType;

/* Definition of DEM error types */
typedef enum
{
  NVM_DEM_ERROR_TYPE_NO_ERROR,                    /*!< Dem Error: None */
  NVM_DEM_ERROR_TYPE_REQ_FAILED,                  /*!< Dem Error: NVM_E_REQ_FAILED */
  NVM_DEM_ERROR_TYPE_INTEGRITY_FAILED,            /*!< Dem Error: NVM_E_INTEGRITY_FAILED */
  NVM_DEM_ERROR_TYPE_LOSS_OF_REDUNDANCY           /*!< Dem Error: NVM_E_LOSS_OF_REDUNDANCY */
} NvM_DemErrorIdType;

/*
 * Types of Job
 */

/*! Enumeration describing the result of NvM internal service execution */
typedef enum
{
    NVM_SERVICE_JOB_PENDING,                       /*!< NvM service job pending. */
    NVM_SERVICE_JOB_OK,                            /*!< NvM service job finished successfully. */
    NVM_SERVICE_JOB_NOT_OK,                        /*!< NvM service job finished unsuccessfully. */
    NVM_SERVICE_JOB_CANCELED,                      /*!< NvM service job canceled */
    NVM_SERVICE_JOB_RESTORED_DEFAULTS,             /*!< NvM service job restored default data successfully. */
    NVM_SERVICE_JOB_INVALIDATED                    /*!< NvM service job invalidated */
} NvM_ServiceJobResultType;

/*!< Structure containing all information of an application service single block job that is executed */
typedef struct
{
  NvM_DataPtrType                      DataBuffer;                     /*! Pointer to buffer that shall be used for this job */
  NvM_DataPtrType                      TemporaryRamBlockAddr;          /*! Address of the temporary RAM block if used */
  NvM_SingleBlockJobType               SingleBlockJobType;             /*! Type of single block job to be performed */
  NvM_BlockIdType                      BlockId;                        /*! External Block ID of job */
  NvM_BlockDescriptorLookupTableIdType BlockDescriptorLookupTableId;   /*! Block Descriptor lookup table identifier */
  uint8                                DataIndex;                      /*! Data Index of Block */
} NvM_SingleBlockJobContextType;

/*!< Pointer to Const type referencing a JobContext */
typedef P2CONST(NvM_SingleBlockJobContextType, AUTOMATIC, NVM_PRIVATE_DATA) NvM_SingleBlockJobContextPtrToConstType;

/*!< Structure containing all information of an NvService job that is executed */
typedef struct
{
  NvM_DataPtrType                      DataBuffer;                     /*! Pointer to buffer that shall be used for this job */
  NvM_SingleBlockJobType               SingleBlockJobType;             /*! Type of single block job to be performed */
  NvM_BlockDescriptorLookupTableIdType BlockDescriptorLookupTableId;   /*! Block Descriptor Lookup Table ID  */
  uint16                               BlockNumber;                    /*! Block number used by MemIf Write */
} NvM_NvJobContextType;

/*
 * Types of Queue
 */

  /*! Reference type used for doubly linked list.  */
 typedef uint16 NvM_QueueEntryRefType;

 /*! Structure which holds all information about the job which is necessary to process it. */
typedef struct
{
  NvM_DataPtrType                      TemporaryRamBlockAddr;          /*! Address of the temporary RAM block if used. */
  NvM_BlockIdType                      BlockId;                        /*! Block which shall be processed. */
  NvM_BlockDescriptorLookupTableIdType BlockDescriptorLookupTableId;   /*! Block Descriptor Lookup Table identifier. */
  NvM_SingleBlockJobType               SingleBlockJobType;             /*! Type of single block job to be performed. */
} NvM_Queue_JobType;

typedef struct
{
  NvM_Queue_JobType                    Job;                  /*! The Nvm Job information stored in this list entry*/
  NvM_QueueEntryRefType                Predecessor;          /*! Predecessor index of current queue entry */
  NvM_QueueEntryRefType                Successor;            /*! Successor index of current queue entry */
  uint8                                Priority;             /*! Priority of the stored job for enabled prioritization */
} NvM_Queue_ListElement;

/*!< Pointer type referencing a queue JobType */
typedef P2VAR(NvM_Queue_JobType, AUTOMATIC, NVM_PRIVATE_DATA) NvM_Queue_JobPtrType;

/*!< Pointer to constant type referencing a queue JobType */
typedef P2CONST(NvM_Queue_JobType, AUTOMATIC, NVM_PRIVATE_DATA) NvM_Queue_JobPtrToConstType;

typedef struct
{
  NvM_Queue_ListElement* QueueEntries;                              /*!< Contains all job which are stored in the queue. */
  NvM_QueueEntryRefType HeadIndex;                                  /*!< Points to the head of the queue. */
  NvM_QueueEntryRefType EmptyListHeadIndex;                         /*!< Points to the head of the empty list. */
  uint16 JobCounter;                                                /*!< Number of jobs which are currently stored. */
  uint16 QueueSize;                                                 /*!< Size of the queue. */
} NvM_Queue_InstanceType;


/*!< Pointer to constant type referencing a queue. */
typedef P2CONST(NvM_Queue_InstanceType, AUTOMATIC, NVM_PRIVATE_DATA) NvM_Queue_InstancePtrToConstType;

/*
 * Type definitions of DataIntegrityRecalcQueue
 */

 /*! Entry of queue that stores DataIntegrity recalculation IDs. Storing relative ID positions via bit position */
typedef uint32 NvM_DataIntegrityRecalcQueueEntryType;

/*! Pointer to a queue entry type */
typedef P2VAR(NvM_DataIntegrityRecalcQueueEntryType, AUTOMATIC, NVM_PRIVATE_DATA) NvM_DataIntegrityRecalcQueueEntryPtrType;

/*! Structure of an instance of unit DataIntegrityRecalcQueue */
typedef struct
{
  NvM_DataIntegrityRecalcQueueEntryType entries[NVM_DATAINTEGRITYRECALCQUEUE_ELEMENTCOUNT];   /*! Entries storing IDs of blocks that shall be recalculated */
} NvM_DataIntegrityRecalcQueue_InstanceType;

/*! Pointer to constant NvM_DataIntegrityRecalcQueue_InstanceType */
typedef P2CONST(NvM_DataIntegrityRecalcQueue_InstanceType, AUTOMATIC, NVM_PRIVATE_DATA) NvM_DataIntegrityRecalcQueue_InstancePtrToConstType;

/*
 * Type definitions for FSM contexts
 */




/*! Context type of BackgroundCrcRecalcFsm */
typedef struct NvM_BackgroundCrcRecalcFsm_ContextTypeStruct
{
  NvM_BlockDescriptorLookupTableIdType CurrentBlockDescriptorLookUpTableId;   /*! Current Block Descriptor LookUp Table ID of job*/
} NvM_BackgroundCrcRecalcFsm_ContextType;

/*! Pointer to constant BackgroundCrcRecalcFsm context information */
typedef P2CONST(NvM_BackgroundCrcRecalcFsm_ContextType, AUTOMATIC, NVM_PRIVATE_DATA) NvM_BackgroundCrcRecalcFsm_ContextPtrToConstType;

/*! Context type of ServiceProcessorFsm */
typedef struct
{
  NvM_Queue_JobType SingleBlockJobToResume;     /*! Single block job to resume after immediate block job finished */
#if (NVM_JOB_PRIORITIZATION == STD_ON)
  boolean IsImmediateJobActive;                 /*! Flag indicating if an immediate job is currently active */
#endif /* NVM_JOB_PRIORITIZATION */
} NvM_ServiceProcessorFsm_ContextType;

/*! Pointer to constant ServiceProcessorFsm context information */
typedef P2CONST(NvM_ServiceProcessorFsm_ContextType, TYPEDEF, NVM_VAR_NO_INIT) NvM_ServiceProcessorFsm_ContextPtrToConstType;

/*! Context type of ReadBlockFsm */
typedef struct
{
  NvM_ServiceJobResultType RequestResult;     /*! Result of job that is processed */
  NvM_ServiceJobResultType NvJobResult;       /*! Result of NV job that is processed */
} NvM_ReadBlockFsm_ContextType;

/*! Pointer to constant ReadBlockFsm context information */
typedef P2CONST(NvM_ReadBlockFsm_ContextType, TYPEDEF, NVM_VAR_NO_INIT) NvM_ReadBlockFsm_ContextPtrToConstType;

typedef struct
{
  NvM_MultiBlockJobType activeMultiBlockJobType;   /*! Type of multi block job that is currently active */
} NvM_MultiBlockJobFsm_ContextType;

/*! Pointer to constant MultiBlockJobFsm context information */
typedef P2CONST(NvM_MultiBlockJobFsm_ContextType, TYPEDEF, NVM_VAR_NO_INIT) NvM_MultiBlockJobFsm_ContextTypePtrToConstType;

/*! Context type of WriteBlockFsm */
typedef struct
{
  NvM_ServiceJobResultType RequestResult;     /*! Result of job that is processed */
} NvM_WriteBlockFsm_ContextType;

/*! Pointer to constant WriteBlockFsm context information */
typedef P2CONST(NvM_WriteBlockFsm_ContextType, TYPEDEF, NVM_VAR_NO_INIT) NvM_WriteBlockFsm_ContextPtrToConstType;

/*! Context type of MultiBlock state machines: ReadAllFsm, WriteAllFsm */
typedef struct
{
  NvM_BlockDescriptorLookupTableIdType CurrentBlockDescriptorLookupTableId;  /*! Current block descriptor lookup table id to process */
  boolean                              HasAnyJobIterationFailed;             /*! Flag indicated if any job has failed */
#if (NVM_JOB_PRIORITIZATION == STD_ON)
  boolean                              IsFinalizationDelayOngoing;           /*! Flag indicated if finalization delay is ongoing */
#endif /* NVM_JOB_PRIORITIZATION == STD_ON */
} NvM_MultiBlockFsm_ContextType;

/*! Context type of MultiBlock state machines: ReadAllFsm */
typedef struct
{
  NvM_MultiBlockFsm_ContextType MultiBlockContext;      /*! Common multiblock job context */
  boolean ConfigBlockMismatch;                          /*! Flag indicated if config block mismatch occured, only significant for master partition */
} NvM_ReadAllFsm_ContextType;

/*! Pointer to constant WriteAllFsm context information */
typedef P2CONST(NvM_MultiBlockFsm_ContextType, TYPEDEF, NVM_VAR_NO_INIT) NvM_WriteAllFsm_ContextPtrToConstType;

/*! Pointer to constant ReadAllFsm context information */
typedef P2CONST(NvM_ReadAllFsm_ContextType, TYPEDEF, NVM_VAR_NO_INIT) NvM_ReadAllFsm_ContextPtrToConstType;


/*
 * Types for BlockManagement
 */

/*!< Enumeration describing RAM block states */
typedef enum
{
    NVM_RAMBLOCKSTATE_INVALID_UNCHANGED,        /*!< State: Invalid and Unchanged. */
    NVM_RAMBLOCKSTATE_VALID_UNCHANGED,          /*!< State: Valid and Unchanged. */
    NVM_RAMBLOCKSTATE_VALID_CHANGED             /*!< State: Valid and Changed. */
} NvM_RamBlockStateType;

/*!< Type to consolidate RAM management information of NV blocks */
typedef struct
{
  NvM_RequestResultType ErrorStatus;    /*!< Error status of block */
  uint8 DataIndex;                      /*!< Current data index for DATASET Nv blocks */
  NvM_RamBlockStateType RamBlockState;  /*!< RAM block state of block */
  boolean BlockLocked;                  /*!< Block Lock Status */
  boolean WriteProtection;              /*!< Write Protection Status */
} NvM_BlockManagementInformationType;

/*!< Pointer to a block management information */
typedef P2VAR(NvM_BlockManagementInformationType, AUTOMATIC, NVM_PRIVATE_DATA) NvM_BlockManagementInformationPtrType;

/*!< Constant Pointer to a block management information */
typedef CONSTP2VAR(NvM_BlockManagementInformationType, AUTOMATIC, NVM_PRIVATE_DATA)
  NvM_BlockManagementInformationConstPtrType;

/*! Pointer to constant block management information */
typedef P2CONST(NvM_BlockManagementInformationType, AUTOMATIC, NVM_PRIVATE_DATA)
  NvM_BlockManagementInformationPtrToConstType;

/*
 * Types of Block Descriptors
 */

/*!< Pointer type referencing RAM data for read/write access */
typedef P2VAR(uint8, AUTOMATIC, NVM_APPL_DATA) NvM_RamAddressType;

/*!< Pointer type referencing RAM data for read-only access */
typedef P2CONST(uint8, AUTOMATIC, NVM_APPL_DATA) NvM_ConstRamAddressType;

/*!< Pointer type referencing ROM data */
typedef P2CONST(uint8, AUTOMATIC, NVM_APPL_CONST) NvM_RomAddressType;

/*!< Pointer type referencing Init Block Callback function */
typedef P2FUNC(Std_ReturnType, NVM_APPL_CODE, NvM_InitBlockCbkPtrType)(void);

/*!< Pointer type referencing Extended Init Block Callback function */
typedef P2FUNC(Std_ReturnType, NVM_APPL_CODE, NvM_ExtendedInitBlockCbkPtrType)
  (NvM_BlockIdType BlockId, NvM_DataPtrType DataBuffer, uint16 Length);


#if (NVM_USE_ASR440_CALLBACK_INTERFACE == STD_ON)
/*!< Pointer type referencing Job End Block Callback function */
typedef P2FUNC(Std_ReturnType, NVM_APPL_CODE, NvM_SingleBlockCbkPtrType)
/*!< Pointer type referencing Extended Job End Block Callback function */
  (NvM_BlockRequestType BlockRequest, NvM_RequestResultType JobResult);
typedef P2FUNC(Std_ReturnType, NVM_APPL_CODE, NvM_ExtendedSingleBlockCbkPtrType)
  (NvM_BlockIdType BlockId, NvM_BlockRequestType BlockRequest, NvM_RequestResultType JobResult);
#else
/*!< Pointer type referencing Job End Block Callback function */
typedef P2FUNC(Std_ReturnType, NVM_APPL_CODE, NvM_SingleBlockCbkPtrType)
  (NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult);
/*!< Pointer type referencing Extended Job End Block Callback function */
typedef P2FUNC(Std_ReturnType, NVM_APPL_CODE, NvM_ExtendedSingleBlockCbkPtrType)
  (NvM_BlockIdType BlockId, NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult);
#endif /* NVM_USE_ASR440_CALLBACK_INTERFACE */

/*!< Pointer type referencing Config Id Callback function */
typedef P2FUNC(void, NVM_APPL_CODE, NvM_ConfigIdCbkPtrType)
  (NvM_DataPtrType DataPtr, uint16 PayloadLength);

/*!< Pointer type referencing Background CRC Recalculation Callback function */
typedef P2FUNC(void, NVM_APPL_CODE, NvM_BackgroundCrcRecalcCbkPtrType)
  (NvM_RequestResultType RequestResult);

/*!< Callback of the write service for the blocks which have explicit synchronization enabled. */
typedef P2FUNC(Std_ReturnType, NVM_APPL_CODE, NvMWriteRamBlockToNvCallbackFptr) (NvM_DataPtrType dataPtr);

/*!< Callback of the read service for the blocks which have explicit synchronization enabled. */
typedef P2FUNC(Std_ReturnType, NVM_APPL_CODE, NvMReadRamBlockFromNvCallbackFptr) (NvM_DataPtrToConstType dataPtr);

/*!< Type, which contains all flags a configured block can have */
typedef struct
{
    NvM_BitfieldType SelectBlockForReadAllEnabled : 1;
    NvM_BitfieldType SelectBlockForWriteAllEnabled : 1;
    NvM_BitfieldType CallbackInvocationForReadAllEnabled : 1;
    NvM_BitfieldType BlockUseSetRamBlockStatusEnabled : 1;
    NvM_BitfieldType ResistantToChangedSwEnabled : 1;
    NvM_BitfieldType WriteBlockOnceEnabled : 1;
    NvM_BitfieldType BlockWriteProtEnabled : 1;
    NvM_BitfieldType CalcRamBlockCrcEnabled : 1;
    NvM_BitfieldType UseAutoValidationEnabled : 1;
} NvM_BlockDescriptorFlagsType;

/* Data integrity type. Kept as a bitfield to reduce storage size. */
typedef NvM_BitfieldType NvM_DataIntegrityType;

typedef uint32 NvM_CsmJobIdType; /*!< Type of the CSM job identifier. */

/*!< Type to consolidate configurable NV block options */
typedef struct
{
  NvM_RamAddressType                    RamBlockDataAddress;               /*!< Start address of RAM block data */
  NvM_RomAddressType                    RomBlockDataAddress;               /*!< Start address of ROM block data */
  NvM_InitBlockCbkPtrType               InitBlockCallback;                 /*!< Function Pointer of the Initialization Block Callback */
  NvM_ExtendedInitBlockCbkPtrType       ExtendedInitBlockCallback;         /*!< Function Pointer of the Extended Initialization Block Callback */
  NvM_SingleBlockCbkPtrType             SingleBlockCallback;               /*!< Function Pointer of the Single Block Callback */
  NvM_ExtendedSingleBlockCbkPtrType     ExtendedSingleBlockCallback;       /*!< Function Pointer of the Extended Single Block Callback */
  NvM_BackgroundCrcRecalcCbkPtrType     BackgroundCrcRecalcCallback;       /*!< Function Pointer of the Background CRC Recalc Callback */
  NvMWriteRamBlockToNvCallbackFptr      WriteRamBlockToNvCallback;         /*!< Callback of the write service. */
  NvMReadRamBlockFromNvCallbackFptr     ReadRamBlockFromNvCallback;        /*!< Callback of the read service. */
  NvM_BlockManagementInformationPtrType BlockManagementInfo;               /*!< Pointer to Block management info of the block */
  NvM_DataPtrType                       DataIntegrityIntBuffer;            /*!< Internal data integrity buffer of the block */
  NvM_DataPtrType                       CrcCompMechanismBuffer;            /*!< Internal CRC comp mechanism buffer of the block */
  NvM_BlockDescriptorFlagsType          Flags;                             /*!< Flags of NV block */
  NvM_CsmJobIdType                      MacGenerationJobId;                /*!< CSM Job ID for MAC generation */
  NvM_CsmJobIdType                      MacVerificationJobId;              /*!< CSM Job ID for MAC verification */
  uint16                                NvramBlockIdentifier;              /*!< ID of NV RAM block */
  uint16                                NvBlockLength;                     /*!< Length of NV block */
  uint16                                HwAbsBlockNumber;                  /*!< Block Number defined by hardware abstraction (Fee/Ea) */
  uint16                                MacLength;                         /*!< Length of MAC appended to block */
  uint8                                 NvBlockNumber;                     /*!< Number of multiple NV blocks */
  uint8                                 Priority;                          /*!< Priority of block, smaller is higher prio, zero means IMMEDIATE */
  NvM_PartitionIdType                   PartitionId;                       /*!< ID of the partition associated to the block */
  NvM_BitfieldType                      MemIfDeviceIndex    : 4;           /*!< Device Index defined by MemIf */
  NvM_DataIntegrityType                 DataIntegritySettings : 3;         /*!< Enumeration for data integrity settings */
  NvM_BitfieldType                      BlockManagementType : 2;           /*!< Enumeration for block management type */
} NvM_BlockDescriptorType;

/*! Pointer to const to a block descriptor */
typedef P2CONST(NvM_BlockDescriptorType, AUTOMATIC, NVM_PRIVATE_DATA) NvM_BlockDescriptorPtrToConstType;

/*
 * Types of MultiBlock Informations
 */

/*!< Type for multiblock job flag */
typedef uint16 NvM_MultiBlockJobFlagType;

/*!< Type for multiblock job information */
typedef struct
{
  NvM_MultiBlockJobFlagType JobStatusFlag;            /*!< MultiBlock Job Flag: None, Requested, Active, Canceled */
  NvM_RequestResultType ErrorStatus;                  /*!< Error status of MultiBlock job */
} NvM_MultiBlockJobInformationType;

/*!< Constant Pointer to the multiblock job information */
typedef CONSTP2VAR(NvM_MultiBlockJobInformationType, AUTOMATIC, NVM_PRIVATE_DATA)
  NvM_MultiBlockJobInformationConstPtrType;

/*! Pointer to constant multiblock job information */
typedef P2CONST(NvM_MultiBlockJobInformationType, AUTOMATIC, NVM_PRIVATE_DATA)
  NvM_MultiBlockJobInformationPtrToConstType;



/* Forward declaration for function pointer definitions */
struct NvM_DataIntegrityService_InstanceTypeStruct;

/*! CRC calculation functionality for a DataIntegrityStrategy */
typedef P2FUNC(void, NVM_PRIVATE_CODE, NvM_DataIntegrityCrcStrategy_CalculateFPtr)(
  NvM_DataPtrToConstType dataBuffer,
  uint32 currentLength,
  struct NvM_DataIntegrityService_InstanceTypeStruct* instancePtr);

/*! CRC append functionality for a DataIntegrityStrategy */
typedef P2FUNC(void, NVM_PRIVATE_CODE, NvM_DataIntegrityCrcStrategy_AppendDataFPtr)(
  const struct NvM_DataIntegrityService_InstanceTypeStruct* instancePtr);

/*! CRC append functionality for a DataIntegrityStrategy */
typedef P2FUNC(boolean, NVM_PRIVATE_CODE, NvM_DataIntegrityCrcStrategy_CompareFPtr)(
  const struct NvM_DataIntegrityService_InstanceTypeStruct* instancePtr);

/*! Structure storing all required information to generate and validate a CRC. */
typedef struct
{
  NvM_DataIntegrityCrcStrategy_CalculateFPtr    Calculate;                    /*! Stores the function pointer to CRC calculation function */
  NvM_DataIntegrityCrcStrategy_AppendDataFPtr   Append;                       /*! Append current CRC value to DataIntegrityRecord pointer */
  NvM_DataIntegrityCrcStrategy_CompareFPtr      Compare;                      /*! Compare current CRC value to DataIntegrityRecord pointer */
  uint8                                         SizeOfDataIntegrityRecord;    /*! The size of the data integrity record */
} NvM_DataIntegrityCrcStrategyType;

/** Job type enumeration */
typedef enum
{
  NVM_DATAINTEGRITYSERVICE_JOB_GENERATE,
  NVM_DATAINTEGRITYSERVICE_JOB_VERIFY
} NvM_DataIntegrityService_JobType;

/** Job status enumeration */
typedef enum
{
  NVM_DATAINTEGRITYSERVICE_STATUS_PENDING,
  NVM_DATAINTEGRITYSERVICE_STATUS_FINISHED_SUCCESSFUL,
  NVM_DATAINTEGRITYSERVICE_STATUS_FINISHED_UNSUCCESSFUL
} NvM_DataIntegrityService_Status;

/* CRC-specific context */
typedef struct
{
  uint32 CurrentCrcValue;
  uint16 RemainingLength;
  boolean IsFirstCall;
  NvM_DataIntegrityCrcStrategyType CrcStrategy;
} NvM_DataIntegrityService_CrcContextType;

#if (NVM_MAC_ENABLED == STD_ON)
/* MAC-specific context */
typedef struct
{
  NvM_CsmJobIdType CsmJobId;
  uint16 BlockMacLength;
  uint8 CsmJobAttemptCounter;
} NvM_DataIntegrityService_MacContextType;
#endif /* NVM_MAC_ENABLED  == STD_ON*/
typedef struct NvM_DataIntegrityService_InstanceTypeStruct
{
  /* Job configuration */
  NvM_DataIntegrityService_JobType JobType;
  NvM_DataIntegrityService_Status JobStatus;
  NvM_DataIntegrityType DataIntegrityType;
  
  /* Block information */
  NvM_DataPtrToConstType BlockDataPtr;
  uint16 BlockDataLength;
  NvM_BlockIdType BlockId;
  uint8 DataIndex;
  
  /* Data integrity record */
  NvM_DataPtrType DataIntegrityRecordPtr;

  /* Context-specific information */
  NvM_DataIntegrityService_CrcContextType CrcContext;
#if (NVM_MAC_ENABLED == STD_ON)
  NvM_DataIntegrityService_MacContextType MacContext;
#endif /* NVM_MAC_ENABLED  == STD_ON*/
} NvM_DataIntegrityService_InstanceType;

/*! Pointer to DataIntegrityService instance information */
typedef P2VAR(NvM_DataIntegrityService_InstanceType, AUTOMATIC, NVM_PRIVATE_DATA) NvM_DataIntegrityService_InstancePtrType;

/*! Pointer to constant DataIntegrityService instance information */
typedef P2CONST(NvM_DataIntegrityService_InstanceType, AUTOMATIC, NVM_PRIVATE_DATA) NvM_DataIntegrityService_InstancePtrToConstType;

/*! Data Integrity Job Context type */
typedef struct
{
  NvM_DataIntegrityService_JobType JobType;                            /*! Type of job (Generate, Verify) */
  NvM_DataPtrToConstType DataBuffer;                                   /*! Pointer to the payload that is used for CRC calculation */
  NvM_DataPtrType DataIntegrityRecordPtr;                              /*! Pointer to the data integrity record address */
  NvM_BlockIdType ExternalBlockId;                                     /*! External Block ID of block */
  NvM_BlockDescriptorLookupTableIdType BlockDescriptorLookupTableId;   /*! Block Descriptor lookup table identifier */
  uint8 DataIndex;                                                     /*! Data Index of block */
  NvM_PartitionIdType PartitionId;                                     /*! Current processed ID of Partition */
} NvM_DataIntegrityJobContextType;

/*! Pointer to constant DataIntegrity Job Context information */
typedef P2CONST(NvM_DataIntegrityJobContextType, AUTOMATIC, NVM_PRIVATE_DATA) NvM_DataIntegrityJobContextPtrToConstType;

/*! Constant Pointer DataIntegrity Job Context information */
typedef CONSTP2VAR(NvM_DataIntegrityJobContextType, AUTOMATIC, NVM_PRIVATE_DATA) NvM_DataIntegrityJobContextConstPtrType;

/*! Pointer DataIntegrity Job Context information */
typedef P2VAR(NvM_DataIntegrityJobContextType, AUTOMATIC, NVM_PRIVATE_DATA) NvM_DataIntegrityJobContextPtrType;

/*
 * Types of FSM Lib
 */

/*! Enumeration describing a processing result */
typedef enum
{
  NVM_FSMLIB_PROCESSINGRESULT_STOP = 0,     /*! No further processing is required */
  NVM_FSMLIB_PROCESSINGRESULT_CONTINUE      /*! Continue to process */
} NvM_FsmLib_ProcessingResultType;

/*! Function pointer describing a ENTRY action */
typedef P2FUNC(void, AUTOMATIC, NvM_FsmLib_ActionEntryFptr)(NvM_PartitionIdType partitionId);

/*! Function pointer describing a DO action */
typedef P2FUNC(NvM_FsmLib_ProcessingResultType, AUTOMATIC, NvM_FsmLib_ActionDoFptr)(NvM_PartitionIdType partitionId);

/*! Structure defining a state object */
typedef struct
{
  NvM_FsmLib_ActionEntryFptr Entry;   /*! ENTRY action of state, if not required use NvM_FsmLib_EntryNoOp */
  NvM_FsmLib_ActionDoFptr Do;         /*! DO action of state */
} NvM_StateType;

/*! Pointer to a state object */
typedef P2CONST(NvM_StateType, AUTOMATIC, NVM_PRIVATE_DATA) NvM_StatePtrType;

/*! Context type of WriteNvBlockFsm */
typedef struct
{
  NvM_StateType  WriteBlockState;                    /*! State where the write block is triggered from */
  uint16 BlockNumber;                                /*! Block number used by MemIf Write */
  NvM_ServiceJobResultType PrimaryNvBlockResult;     /*! Result of the processed primary NV block job */
  NvM_ServiceJobResultType CurrentMemIfWriteResult;  /*! Result of the MemIf Write operation */
  uint8 WriteRetryCounter;                           /*! Counter for write retries */
} NvM_WriteNvBlockFsm_ContextType;

/*! Pointer to constant WriteNvBlockFsm context information */
typedef P2CONST(NvM_WriteNvBlockFsm_ContextType, TYPEDEF, NVM_VAR_NO_INIT) NvM_WriteNvBlockFsm_ContextPtrToConstType;

/*! Structure defining a FSM object */
typedef struct
{
  NvM_FsmLib_ActionEntryFptr Entry;               /*! ENTRY action of FSM */
  NvM_StateType CurrentState;                     /*! State that is currently processed */
} NvM_FsmType;

/*! Pointer to a FSM object */
typedef P2VAR(NvM_FsmType, AUTOMATIC, NVM_PRIVATE_DATA) NvM_FsmPtrType;

/*! Pointer to Const to a FSM object */
typedef P2CONST(NvM_FsmType, AUTOMATIC, NVM_PRIVATE_DATA) NvM_FsmPtrToConstType;

/*! Structure containing all information of a processing stack element
 *
 */
typedef struct
{
  NvM_FsmType CurrentFsm;                       /*! Fsm that is currently processed */
  NvM_ServiceJobResultType FsmJobResult;        /*! Service job result of the fsm */
} NvM_FsmLib_ProcessingStackElementType;

/*! Pointer to a processing stack element object */
typedef P2VAR(NvM_FsmLib_ProcessingStackElementType, AUTOMATIC, NVM_PRIVATE_DATA) NvM_ProcessingStackElementPtrType;

/*! Pointer to Const to a processing stack element object */
typedef P2CONST(NvM_FsmLib_ProcessingStackElementType, AUTOMATIC, NVM_PRIVATE_DATA)
  NvM_ProcessingStackElementPtrToConstType;

/*! Type used to iterate processing stacks of various fsm lib instances */
typedef uint8_least NvM_FsmLib_ProcessingStackElementIterType;

/*! Structure containing all information of an actual instance of FSM lib */
typedef struct
{
  NvM_ProcessingStackElementPtrType ProcessingStack; /*! Stack of FSM objects */
  sint8 CurrentProcessingStackIndex;                 /*! Stack index of current active FSM */
  NvM_PartitionIdType PartitionId;                   /*! Partition ID of instance */
  uint8 StackSize;                                   /*! Stack size of FSM objects */
} NvM_FsmLib_InstanceType;

/*! Pointer to const to a FsmLib instance object */
typedef P2CONST(NvM_FsmLib_InstanceType, AUTOMATIC, NVM_PRIVATE_DATA) NvM_FsmLib_InstancePtrToConstType;

/*! Pointer to a FsmLib instance object */
typedef P2VAR(NvM_FsmLib_InstanceType, AUTOMATIC, NVM_PRIVATE_DATA) NvM_FsmLib_InstancePtrType;

#endif /* NVM_INTERNALTYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: NvM_InternalTypes.h
 *********************************************************************************************************************/
