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
/*!        \file  MemAcc_BBMJobManager.c
 *        \brief  MemAcc_BBMJobManager source file
 *      \details  -
 *         \unit  BBMJobManager
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#define MEMACC_BBMJOBMANAGER_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "MemAcc_BBMJobManager.h"
// #include "SchM_MemAcc.h"
#include "MemAcc_BBM.h"
#include "MemAcc_Queue.h"
#include "MemAcc_Utils.h"

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/
#if !defined (MEMACC_LOCAL)
# define MEMACC_LOCAL                                                    static
#endif

#if !defined (MEMACC_LOCAL_INLINE)
# define MEMACC_LOCAL_INLINE                                             LOCAL_INLINE
#endif

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

#if (MEMACC_BBM_ENABLED == STD_ON) /* COV_MSR_UT_OPTIONAL_UNIT */

typedef enum
{
  MEMACC_BBM_INIT_PENDING,   /*!< Indicates that the NAND bad block scan process is pending. */
  MEMACC_BBM_INIT_DONE,      /*!< Indicates that the NAND bad block scan process has completed. */
  MEMACC_BBM_INIT_FAILED     /*!< Indicates that the NAND bad block scan process has failed. */
} MemAcc_BBM_InitStatusType; /*!< Enum that defines the initialization state of the NAND bad block scan process. */

typedef struct
{
  MemAcc_BBM_InitStatusType InitState;                        /*!< Enum that defines the initialization state of the NAND bad block scan for a AA. */
  MemAcc_SubAddressAreaIndexType SaaIdx;                      /*!< Index of the SAA where the BB marker should be scanned if InitState is PENDING. */
  MemAcc_NumberOfSectorsOfSubAddressAreaType PhysicalBlockNr; /*!< Physical block number of the SaaIdx where the BB marker should be scanned if InitState is PENDING. */
} MemAcc_BBM_AddressAreaInitStateType;                        /*!< Stores the current state of the initialization for the NAND bad block scan process for a AA. */

typedef struct
{
  MemAcc_SubAddressAreaIndexType SaaIdx;                      /*!< Stores sub address area index of the current job. */
  MemAcc_NumberOfSectorsOfSubAddressAreaType PhysicalBlockNr; /*!< Stores physical block number of the current job. */
  MemAcc_MemRecoverDataJobDataType RecoverDataJobData;        /*!< Data buffer for HwSpecificService: MEMACC_MEMHWSID_RECOVERDATA. */
  MemAcc_MemWriteBBMarkerJobDataType WriteBBMarkerJobData;    /*!< Data buffer for HwSpecificService: MEMACC_MEMHWSID_WRITEBBMARKER. */
  MemAcc_MemReadBBMarkerJobDataType ReadBBMarkerJobData;      /*!< Data buffer for HwSpecificService: MEMACC_MEMHWSID_READBBMARKER. */
  MemAcc_LengthType JobDataLength;                            /*!< Length of the data buffers. */
} MemAcc_BBM_JobContextType;                                  /*!< Job context information for queued BBM jobs. */

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/
#define MEMACC_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemAcc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*!< Stores the current state of the initialization for the NAND bad block scan process for each AA. */
/* PRQA S 3408 1 */ /* MD_MemAcc_LocalVariableExternalLinkage */
MEMACC_LOCAL MemAcc_BBM_AddressAreaInitStateType AddressAreaInitState[MemAcc_GetSizeOfAddressArea()];

/* Job context information for queued BBM jobs for each AA. */
/* PRQA S 3408 1 */ /* MD_MemAcc_LocalVariableExternalLinkage */
MEMACC_LOCAL MemAcc_BBM_JobContextType MemAcc_BBM_JobContext[MemAcc_GetSizeOfAddressArea()];

#define MEMACC_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemAcc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
# define MEMACC_START_SEC_CODE
# include "MemAcc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * MemAcc_BBMJobManager_ResetAllJobContexts()
 *********************************************************************************************************************/
/*! \brief       Resets all BBM job contexts.
 *  \details     -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
MEMACC_LOCAL void MemAcc_BBMJobManager_ResetAllJobContexts(void);

/**********************************************************************************************************************
 * MemAcc_BBMJobManager_ResetAndPrepareInitScan()
 *********************************************************************************************************************/
/*! \brief       Resets the BBM initialization status to prepare for the NAND bad block scan.
 *  \details     After this call read bb marker jobs will be queued to scan NAND memory.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
MEMACC_LOCAL void MemAcc_BBMJobManager_ResetAndPrepareInitScan(void);

/**********************************************************************************************************************
 * MemAcc_BBMJobManager_QueueHwSpecificService()
 *********************************************************************************************************************/
/*! \brief       Queues a hwspecific job.
 *  \details     -
 *  \param[in]   jobClassification - Job classification.
 *  \param[in]   saaIdx - SubAddress Area Index.
 *  \param[in]   hwServiceId - Hw Service Id.
 *  \param[in]   dataPtr - Pointer to the data buffer.
 *  \param[in]   lengthPtr - Pointer to the length buffer.
 *  \return      E_OK if job was accepted.
 *  \return      E_NOT_OK if job was rejected.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
MEMACC_LOCAL Std_ReturnType MemAcc_BBMJobManager_QueueHwSpecificService(
  const MemAcc_JobClassificationType jobClassification,
  const MemAcc_SubAddressAreaIndexType saaIdx,
  const MemAcc_MemHwServiceIdType hwServiceId,
  MemAcc_DataType* dataPtr,
  MemAcc_LengthType* lengthPtr);

/**********************************************************************************************************************
 * MemAcc_BBMJobManager_QueueReadBBMarkerJob()
 *********************************************************************************************************************/
/*! \brief       Queues the next read bb marker job for a AA.
 *  \details     -
 *  \param[in]   aaIdx - AA Index.
 *  \return      E_OK if job was accepted.
 *  \return      E_NOT_OK if job was rejected.
 *  \pre         When called, no internal job may exist in the queue.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
MEMACC_LOCAL Std_ReturnType MemAcc_BBMJobManager_QueueReadBBMarkerJob(
  const MemAcc_AddressAreaIndexType aaIdx);

/**********************************************************************************************************************
 * MemAcc_BBMJobManager_QueueRecoverSectorJob()
 *********************************************************************************************************************/
/*! \brief       Queues a recover sector job.
 *  \details     -
 *  \param[in]   saaIdx - SAA Index.
 *  \param[in]   sourcePhysicalBlockNr - Source physical block number.
 *  \param[in]   targetPhysicalBlockNr - Target physical block number.
 *  \param[in]   numberOfBytesToRecover - Number of bytes that should be recovered from source block to target block.
 *  \return      E_OK if job was accepted.
 *  \return      E_NOT_OK if job was rejected.
 *  \pre         When called, no internal job may exist in the queue.
 *               sectorOffsetToCopy must be greater then 0.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
MEMACC_LOCAL Std_ReturnType MemAcc_BBMJobManager_QueueRecoverSectorJob(
  const MemAcc_SubAddressAreaIndexType saaIdx,
  const MemAcc_NumberOfSectorsOfSubAddressAreaType sourcePhysicalBlockNr,
  const MemAcc_NumberOfSectorsOfSubAddressAreaType targetPhysicalBlockNr,
  const MemAcc_AddressType numberOfBytesToRecover);

/**********************************************************************************************************************
 * MemAcc_BBMJobManager_QueueEraseBlockJob()
 *********************************************************************************************************************/
/*! \brief       Queues a erase block job.
 *  \details     -
 *  \param[in]   saaIdx - SAA Index.
 *  \param[in]   physicalBlockNr - Physical block number.
 *  \return      E_OK if job was accepted.
 *  \return      E_NOT_OK if job was rejected.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
MEMACC_LOCAL Std_ReturnType MemAcc_BBMJobManager_QueueEraseBlockJob(
  const MemAcc_SubAddressAreaIndexType saaIdx,
  const MemAcc_NumberOfSectorsOfSubAddressAreaType physicalBlockNr);

/**********************************************************************************************************************
 * MemAcc_BBMJobManager_QueueWriteBBMarkerJob()
 *********************************************************************************************************************/
/*! \brief       Queues a write BB marker job.
 *  \details     -
 *  \param[in]   saaIdx - SAA Index.
 *  \param[in]   physicalBlockNr - Physical block number.
 *  \return      E_OK if job was accepted.
 *  \return      E_NOT_OK if job was rejected.
 *  \pre         When called, no internal job may exist in the queue.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
MEMACC_LOCAL Std_ReturnType MemAcc_BBMJobManager_QueueWriteBBMarkerJob(
  const MemAcc_SubAddressAreaIndexType saaIdx,
  const MemAcc_NumberOfSectorsOfSubAddressAreaType physicalBlockNr);

/**********************************************************************************************************************
 * MemAcc_BBMJobManager_CalculateTargetPhysicalBlockNumberForSkipMethodSectorRecovery()
 *********************************************************************************************************************/
/*! \brief       Calculates the target physical block number for skip method sector recovery for a given bbLutIdx.
 *  \details     -
 *  \param[in]   bbLutIdx - Index of the bad block that should be recovered.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
MEMACC_LOCAL MemAcc_NumberOfSectorsOfSubAddressAreaType MemAcc_BBMJobManager_CalculateTargetPhysicalBlockNumberForSkipMethodSectorRecovery(
  const MemAcc_BBLUTStartIdxOfMemInstanceType bbLutIdx);

/**********************************************************************************************************************
 * MemAcc_BBMJobManager_QueueRecoverSectorOrEraseBlockJobDependingOnSectorOffset()
 *********************************************************************************************************************/
/*! \brief       Queues a recover sector or erase block job depending on the calculated sector offset.
 *  \details     -
 *  \param[in]   bbLutIdx - Index of the bad block that should be recovered/erased.
 *  \return      E_OK if job was accepted.
 *  \return      E_NOT_OK if job was rejected.
 *  \pre         When called, no internal job may exist in the queue.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
MEMACC_LOCAL Std_ReturnType MemAcc_BBMJobManager_QueueRecoverSectorOrEraseBlockJobDependingOnSectorOffset(
  const MemAcc_BBLUTStartIdxOfMemInstanceType bbLutIdx);

/**********************************************************************************************************************
 * MemAcc_BBMJobManager_QueueInternalJobForBBLutEntry()
 *********************************************************************************************************************/
/*! \brief       Queues a internal job for the given bbLutIdx based on the marker state.
 *  \details     -
 *  \param[in]   bbLutIdx - BB LUT Index.
 *  \return      E_OK if job was queued.
 *  \return      E_NOT_OK if no job was queued.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
MEMACC_LOCAL Std_ReturnType MemAcc_BBMJobManager_QueueInternalJobForBBLutEntry(
  const MemAcc_BBLUTStartIdxOfMemInstanceType bbLutIdx);

/**********************************************************************************************************************
 * MemAcc_BBMJobManager_CalculateNextBlockToReadBBMarkerFromForAddressArea()
 *********************************************************************************************************************/
/*! \brief       Calculates the next block to be scanned for a given address area.
 *  \details     -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
MEMACC_LOCAL void MemAcc_BBMJobManager_CalculateNextBlockToReadBBMarkerFromForAddressArea(
  const MemAcc_AddressAreaIndexType aaIdx);

/**********************************************************************************************************************
 * MemAcc_BBMJobManager_ProcessReadBBMarkerJobResult()
 *********************************************************************************************************************/
/*! \brief       Postprocessing for a read bb marker job.
 *  \details     -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
MEMACC_LOCAL void MemAcc_BBMJobManager_ProcessReadBBMarkerJobResult(const MemAcc_JobContextType* job);

/**********************************************************************************************************************
 * MemAcc_BBMJobManager_ProcessRecoverSectorJobResult()
 *********************************************************************************************************************/
/*! \brief       Postprocessing for recover sector job.
 *  \details     -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
MEMACC_LOCAL void MemAcc_BBMJobManager_ProcessRecoverSectorJobResult(const MemAcc_JobContextType* job);

/**********************************************************************************************************************
 * MemAcc_BBMJobManager_ProcessEraseBlockJobResult()
 *********************************************************************************************************************/
/*! \brief       Postprocessing for erase block job.
 *  \details     -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
MEMACC_LOCAL void MemAcc_BBMJobManager_ProcessEraseBlockJobResult(const MemAcc_JobContextType* job);

/**********************************************************************************************************************
 * MemAcc_BBMJobManager_ProcessWriteBBMarkerJobResult()
 *********************************************************************************************************************/
/*! \brief       Postprocessing for write BB marker job.
 *  \details     -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
MEMACC_LOCAL void MemAcc_BBMJobManager_ProcessWriteBBMarkerJobResult(const MemAcc_JobContextType* job);

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * MemAcc_BBMJobManager_ResetAllJobContexts()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
MEMACC_LOCAL void MemAcc_BBMJobManager_ResetAllJobContexts(void)
{
  for (MemAcc_AddressAreaIndexType aaIdx = 0u; aaIdx < MemAcc_GetSizeOfAddressArea(); aaIdx++)
  {
    MemAcc_BBM_JobContext[aaIdx].SaaIdx = 0u;
    MemAcc_BBM_JobContext[aaIdx].PhysicalBlockNr = 0u;

    MemAcc_BBM_JobContext[aaIdx].ReadBBMarkerJobData.BbSourceAddress = 0u;
    MemAcc_BBM_JobContext[aaIdx].ReadBBMarkerJobData.IsBbMarkerSet = MEMACC_MEMBBMARKERSTATUS_NOT_SET;

    MemAcc_BBM_JobContext[aaIdx].RecoverDataJobData.SourceSectorAddress = 0u;
    MemAcc_BBM_JobContext[aaIdx].RecoverDataJobData.TargetSectorAddress = 0u;
    MemAcc_BBM_JobContext[aaIdx].RecoverDataJobData.Length = 0u;

    MemAcc_BBM_JobContext[aaIdx].WriteBBMarkerJobData = 0u;

    MemAcc_BBM_JobContext[aaIdx].JobDataLength = 0u;
  }
}

/**********************************************************************************************************************
 * MemAcc_BBMJobManager_ResetAndPrepareInitScan()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
MEMACC_LOCAL void MemAcc_BBMJobManager_ResetAndPrepareInitScan(void)
{
  for (MemAcc_AddressAreaIndexType aaIdx = 0u; aaIdx < MemAcc_GetSizeOfAddressArea(); aaIdx++)
  {
    AddressAreaInitState[aaIdx].InitState = MEMACC_BBM_INIT_DONE;
    AddressAreaInitState[aaIdx].PhysicalBlockNr = 0u;
    AddressAreaInitState[aaIdx].SaaIdx = 0u;

    for (MemAcc_SubAddressAreaIndexType saaIdx = MemAcc_GetSubAddressAreaStartIdxOfAddressArea(aaIdx);
      saaIdx < MemAcc_GetSubAddressAreaEndIdxOfAddressArea(aaIdx);
      saaIdx++)
    {
      if (MemAcc_GetBBStrategyOfMemInstance(MemAcc_GetMemInstanceIdxOfSubAddressArea(saaIdx)) == MEMACC_BBM_BBSTRATEGY_SKIPMETHOD)
      {
        /* If a address area uses the BBM skip method set the first saaIdx and break the loop to start init scan there. */
        AddressAreaInitState[aaIdx].SaaIdx = saaIdx;
        AddressAreaInitState[aaIdx].InitState = MEMACC_BBM_INIT_PENDING;
        break;
      }
    }
  }
}

/**********************************************************************************************************************
 * MemAcc_BBMJobManager_QueueHwSpecificService()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 * \spec
 *   requires saaIdx < MemAcc_GetSizeOfSubAddressArea();
 * \endspec
 */
MEMACC_LOCAL Std_ReturnType MemAcc_BBMJobManager_QueueHwSpecificService(
  const MemAcc_JobClassificationType jobClassification,
  const MemAcc_SubAddressAreaIndexType saaIdx,
  const MemAcc_MemHwServiceIdType hwServiceId,
  MemAcc_DataType* dataPtr,
  MemAcc_LengthType* lengthPtr)
{
  MemAcc_JobAreaType job;
  job.JobType = (MemAcc_AtomicJobType)MEMACC_MEMHWSPECIFIC_JOB;
  job.AddressAreaIndex = MemAcc_Utils_GetAddrAreaIdxOfSubAddrAreaIdx(saaIdx);
  /*@ assert job.AddressAreaIndex < MemAcc_GetSizeOfAddressArea(); */ /* VCA_MemAcc_GetAddrAreaIdxOfSubAddrAreaIdxIsValid */
  job.Address = 0u;
  job.Length = 0u;
  job.DataBuffer = dataPtr;
  job.ConstDataBuffer = NULL_PTR;
  job.HwId = MemAcc_GetHardwareIdOfMemInstance(MemAcc_GetMemInstanceIdxOfSubAddressArea(saaIdx));
  job.HwServiceId = hwServiceId;
  job.LengthPtr = lengthPtr;
  job.LockNotificationFctPtr = NULL_PTR;
  job.JobClassification = jobClassification;

  return MemAcc_Queue_PushJob(&job);
}

/**********************************************************************************************************************
 * MemAcc_BBMJobManager_QueueReadBBMarkerJob()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 * \spec
 *   requires aaIdx < MemAcc_GetSizeOfAddressArea();
 * \endspec
 */
MEMACC_LOCAL Std_ReturnType MemAcc_BBMJobManager_QueueReadBBMarkerJob(
  const MemAcc_AddressAreaIndexType aaIdx)
{
  Std_ReturnType retVal = E_NOT_OK;

  if (AddressAreaInitState[aaIdx].InitState == MEMACC_BBM_INIT_PENDING)
  {
    const MemAcc_SubAddressAreaIndexType saaIdx = AddressAreaInitState[aaIdx].SaaIdx;
    const MemAcc_NumberOfSectorsOfSubAddressAreaType physicalBlockNr = AddressAreaInitState[aaIdx].PhysicalBlockNr;
    /*@ assert saaIdx < MemAcc_GetSizeOfSubAddressArea(); */ /* VCA_MemAcc_SaaIdxOfAddressAreaInitStateIsValid */

    /* Set job context information. */
    MemAcc_BBM_JobContext[aaIdx].SaaIdx = saaIdx;
    MemAcc_BBM_JobContext[aaIdx].PhysicalBlockNr = physicalBlockNr;
    MemAcc_BBM_JobContext[aaIdx].ReadBBMarkerJobData.BbSourceAddress = MemAcc_Utils_GetPhysicalAddress(saaIdx, physicalBlockNr);
    MemAcc_BBM_JobContext[aaIdx].ReadBBMarkerJobData.IsBbMarkerSet = MEMACC_MEMBBMARKERSTATUS_NOT_SET;
    MemAcc_BBM_JobContext[aaIdx].JobDataLength = sizeof(MemAcc_MemReadBBMarkerJobDataType);

    retVal = MemAcc_BBMJobManager_QueueHwSpecificService(
      MEMACC_JOBCLASSIFICATION_BBM_READBBMARKER,
      saaIdx,
      MEMACC_MEMHWSID_READBBMARKER,
      (MemAcc_DataType*) &MemAcc_BBM_JobContext[aaIdx].ReadBBMarkerJobData,
      &MemAcc_BBM_JobContext[aaIdx].JobDataLength);
  }

  return retVal;
}

/**********************************************************************************************************************
 * MemAcc_BBMJobManager_QueueRecoverSectorJob()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 * \spec
 *   requires saaIdx < MemAcc_GetSizeOfSubAddressArea();
 * \endspec
 */
MEMACC_LOCAL Std_ReturnType MemAcc_BBMJobManager_QueueRecoverSectorJob(
  const MemAcc_SubAddressAreaIndexType saaIdx,
  const MemAcc_NumberOfSectorsOfSubAddressAreaType sourcePhysicalBlockNr,
  const MemAcc_NumberOfSectorsOfSubAddressAreaType targetPhysicalBlockNr,
  const MemAcc_AddressType numberOfBytesToRecover)
{
  const MemAcc_AddressAreaIndexType aaIdx = MemAcc_Utils_GetAddrAreaIdxOfSubAddrAreaIdx(saaIdx);
  /*@ assert aaIdx < MemAcc_GetSizeOfAddressArea(); */ /* VCA_MemAcc_GetAddrAreaIdxOfSubAddrAreaIdxIsValid */

  /* Set job context information. */
  MemAcc_BBM_JobContext[aaIdx].SaaIdx = saaIdx;
  MemAcc_BBM_JobContext[aaIdx].PhysicalBlockNr = sourcePhysicalBlockNr;
  MemAcc_BBM_JobContext[aaIdx].RecoverDataJobData.SourceSectorAddress = MemAcc_Utils_GetPhysicalAddress(saaIdx, sourcePhysicalBlockNr);
  MemAcc_BBM_JobContext[aaIdx].RecoverDataJobData.TargetSectorAddress = MemAcc_Utils_GetPhysicalAddress(saaIdx, targetPhysicalBlockNr);
  MemAcc_BBM_JobContext[aaIdx].RecoverDataJobData.Length = numberOfBytesToRecover;
  MemAcc_BBM_JobContext[aaIdx].JobDataLength = sizeof(MemAcc_MemRecoverDataJobDataType);

  return MemAcc_BBMJobManager_QueueHwSpecificService(
    MEMACC_JOBCLASSIFICATION_BBM_RECOVERSECTOR,
    saaIdx,
    MEMACC_MEMHWSID_RECOVERDATA,
    (MemAcc_DataType*) &MemAcc_BBM_JobContext[aaIdx].RecoverDataJobData,
    &MemAcc_BBM_JobContext[aaIdx].JobDataLength);
}

/**********************************************************************************************************************
 * MemAcc_BBMJobManager_QueueEraseBlockJob()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 * \spec
 *   requires saaIdx < MemAcc_GetSizeOfSubAddressArea();
 * \endspec
 */
MEMACC_LOCAL Std_ReturnType MemAcc_BBMJobManager_QueueEraseBlockJob(
  const MemAcc_SubAddressAreaIndexType saaIdx,
  const MemAcc_NumberOfSectorsOfSubAddressAreaType physicalBlockNr)
{
  /*
   * For JobClassification erase block there is custom logic in the MemAcc_BBM_TranslateLogicalToPhysicalAddress function.
   * The physical address cannot be calculated via normal program flow since bad blocks are targeted here
   * which are explicitly skipped during the normal logical to physical address translation.
   * For this job the physical address is calculated via the MemAcc_BBM_JobContext.
   */
  MemAcc_JobAreaType job;
  job.JobType = (MemAcc_AtomicJobType)MEMACC_ERASE_JOB;
  job.AddressAreaIndex = MemAcc_Utils_GetAddrAreaIdxOfSubAddrAreaIdx(saaIdx);
  /*@ assert job.AddressAreaIndex < MemAcc_GetSizeOfAddressArea(); */ /* VCA_MemAcc_GetAddrAreaIdxOfSubAddrAreaIdxIsValid */
  /* Uses the first address of the SAA so the program flow calculates the sync group and other properties correctly. */
  job.Address = MemAcc_GetLogicalStartAddressOfSubAddressArea(saaIdx);
  /* Length for erase block is always the erase sector size. */
  job.Length = MemAcc_GetEraseSectorSizeOfMemSectorBatch(MemAcc_GetMemSectorBatchIdxOfSubAddressArea(saaIdx));
  job.DataBuffer = NULL_PTR;
  job.ConstDataBuffer = NULL_PTR;
  job.HwId = (MemAcc_HwIdType) 0;    /* PRQA S 4332 */ /* MD_MemAcc_HwIdEnumCasting */
  job.HwServiceId = 0u;
  job.LengthPtr = NULL_PTR;
  job.LockNotificationFctPtr = NULL_PTR;
  job.JobClassification = MEMACC_JOBCLASSIFICATION_BBM_ERASEBLOCK;

  /* Set job context information. */
  MemAcc_BBM_JobContext[job.AddressAreaIndex].SaaIdx = saaIdx;
  MemAcc_BBM_JobContext[job.AddressAreaIndex].PhysicalBlockNr = physicalBlockNr;

  return MemAcc_Queue_PushJob(&job);
}

/**********************************************************************************************************************
 * MemAcc_BBMJobManager_QueueWriteBBMarkerJob()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 * \spec
 *   requires saaIdx < MemAcc_GetSizeOfSubAddressArea();
 * \endspec
 */
MEMACC_LOCAL Std_ReturnType MemAcc_BBMJobManager_QueueWriteBBMarkerJob(
  const MemAcc_SubAddressAreaIndexType saaIdx,
  const MemAcc_NumberOfSectorsOfSubAddressAreaType physicalBlockNr)
{
  const MemAcc_AddressAreaIndexType aaIdx = MemAcc_Utils_GetAddrAreaIdxOfSubAddrAreaIdx(saaIdx);
  /*@ assert aaIdx < MemAcc_GetSizeOfAddressArea(); */ /* VCA_MemAcc_GetAddrAreaIdxOfSubAddrAreaIdxIsValid */

  /* Set job context information. */
  MemAcc_BBM_JobContext[aaIdx].SaaIdx = saaIdx;
  MemAcc_BBM_JobContext[aaIdx].PhysicalBlockNr = physicalBlockNr;
  MemAcc_BBM_JobContext[aaIdx].WriteBBMarkerJobData = MemAcc_Utils_GetPhysicalAddress(saaIdx, physicalBlockNr);
  MemAcc_BBM_JobContext[aaIdx].JobDataLength = sizeof(MemAcc_MemWriteBBMarkerJobDataType);

  return MemAcc_BBMJobManager_QueueHwSpecificService(
    MEMACC_JOBCLASSIFICATION_BBM_WRITEBBMARKER,
    saaIdx,
    MEMACC_MEMHWSID_WRITEBBMARKER,
    (MemAcc_DataType*) &MemAcc_BBM_JobContext[aaIdx].WriteBBMarkerJobData,
    &MemAcc_BBM_JobContext[aaIdx].JobDataLength);
}

/**********************************************************************************************************************
 * MemAcc_BBMJobManager_CalculateTargetPhysicalBlockNumberForSkipMethodSectorRecovery()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
MEMACC_LOCAL MemAcc_NumberOfSectorsOfSubAddressAreaType MemAcc_BBMJobManager_CalculateTargetPhysicalBlockNumberForSkipMethodSectorRecovery(
  const MemAcc_BBLUTStartIdxOfMemInstanceType bbLutIdx)
{
  const MemAcc_SizeOfMemInstanceType bbCfgIdx = MemAcc_GetMemInstanceIdxOfSubAddressArea(MemAcc_GetSAAIdxOfBBLUT(bbLutIdx));
  MemAcc_NumberOfSectorsOfSubAddressAreaType targetPhysicalBlockNumber = MemAcc_GetPhysicalBlockNrOfBBLUT(bbLutIdx) + 1u;

  /* Check following bb lut entries to check if bad blocks in sequence exist. Skip bad blocks in sequence one by one until a good block for recovery is found. */
  for (MemAcc_BBLUTStartIdxOfMemInstanceType currBbLutIdx = bbLutIdx + ((MemAcc_BBLUTStartIdxOfMemInstanceType)1u);
    (currBbLutIdx < MemAcc_GetBBLUTEndIdxOfMemInstance(bbCfgIdx))
    && (MemAcc_GetBBMarkerStateOfBBLUT(currBbLutIdx) != MEMACC_BBM_BBMARKERSTATE_NONE)
    && (MemAcc_GetSAAIdxOfBBLUT(currBbLutIdx) == MemAcc_GetSAAIdxOfBBLUT(bbLutIdx));
    currBbLutIdx++)
  {
    /* Check if the next block's physical block number doesn't match the current sequence. */
    if (MemAcc_GetPhysicalBlockNrOfBBLUT(currBbLutIdx) != targetPhysicalBlockNumber)
    {
      /* Next physical block is good. Recovery block was found. */
      break;
    }
    else
    {
      /* Next physical block is bad. Check the next one. */
      targetPhysicalBlockNumber++;
    }
  }

  /* The calculated physical block number may be out of range of the current SAA. */
  return targetPhysicalBlockNumber;
}

/**********************************************************************************************************************
 * MemAcc_BBMJobManager_QueueRecoverSectorOrEraseBlockJobDependingOnSectorOffset()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 * \spec
 *   requires bbLutIdx < MemAcc_GetSizeOfBBLUT();
 * \endspec
 */
MEMACC_LOCAL Std_ReturnType MemAcc_BBMJobManager_QueueRecoverSectorOrEraseBlockJobDependingOnSectorOffset(
  const MemAcc_BBLUTStartIdxOfMemInstanceType bbLutIdx)
{
  Std_ReturnType retVal = E_NOT_OK;
  const MemAcc_SubAddressAreaIndexType saaIdx = MemAcc_GetSAAIdxOfBBLUT(bbLutIdx);
  /*@ assert saaIdx < MemAcc_GetSizeOfSubAddressArea(); */ /* VCA_MemAcc_GetSAAIdxOfBBLUTAlwaysValid */
  const MemAcc_NumberOfSectorsOfSubAddressAreaType physicalBlockNr = MemAcc_GetPhysicalBlockNrOfBBLUT(bbLutIdx);
  const MemAcc_AddressAreaIndexType aaIdx = MemAcc_Utils_GetAddrAreaIdxOfSubAddrAreaIdx(saaIdx);
  /*@ assert aaIdx < MemAcc_GetSizeOfAddressArea(); */ /* VCA_MemAcc_GetAddrAreaIdxOfSubAddrAreaIdxIsValid */

  /*
   * The offset and the logical address of the write job that caused the sector recovery are needed
   * to determine how many bytes need to be copied/recovered to the next good block.
   * This is why the user job may not be canceled or be otherwise removed from the queue if there is an ongoing internal job.
   * As long this is respected, the job pointer will never be NULL_PTR here.
   */
  const MemAcc_JobContextType *job = MemAcc_Queue_GetJob(aaIdx, FALSE);

  const MemAcc_AddressType logicalAddress = job->JobArea.Address + job->MngmtArea.Offset;
  /* The number of bytes to recover is the offset between the current logical address and the sector start address where the address is located. */
  const MemAcc_AddressType numberOfBytesToRecover = (logicalAddress - MemAcc_GetLogicalStartAddressOfSubAddressArea(saaIdx))
    % MemAcc_GetEraseSectorSizeOfMemSectorBatch(MemAcc_GetMemSectorBatchIdxOfSubAddressArea(saaIdx));

  /* If no bytes have to be recovered, the recovery can be skipped. A erase block job is queued instead. */
  if (numberOfBytesToRecover == 0u)
  {
    MemAcc_SetBBMarkerStateOfBBLUT(bbLutIdx, MEMACC_BBM_BBMARKERSTATE_DATARECOVERED);
    retVal = MemAcc_BBMJobManager_QueueEraseBlockJob(saaIdx, physicalBlockNr);
  }
  else
  {
    const MemAcc_NumberOfSectorsOfSubAddressAreaType targetPhysicalBlockNr =
      MemAcc_BBMJobManager_CalculateTargetPhysicalBlockNumberForSkipMethodSectorRecovery(bbLutIdx);

    /* If recovery target block number is out of bounds, raise an error. */
    if ((targetPhysicalBlockNr >= MemAcc_GetNumberOfSectorsOfSubAddressArea(saaIdx))
    /* Also raise error in case of integer overflow. */
      || (targetPhysicalBlockNr <= MemAcc_GetPhysicalBlockNrOfBBLUT(bbLutIdx)))
    {
      MemAcc_SetBBMarkerStateOfBBLUT(bbLutIdx, MEMACC_BBM_BBMARKERSTATE_ERROR);
      MemAcc_Queue_RaiseError(aaIdx, MEMACC_ERRORTYPE_BBM_RECOVERYTARGETOUTOFBOUNDS);
    }
    else
    {
      retVal = MemAcc_BBMJobManager_QueueRecoverSectorJob(saaIdx, physicalBlockNr, targetPhysicalBlockNr, numberOfBytesToRecover);
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 * MemAcc_BBMJobManager_QueueInternalJobForBBLutEntry()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 * \spec
 *   requires bbLutIdx < MemAcc_GetSizeOfBBLUT();
 * \endspec
 */
MEMACC_LOCAL Std_ReturnType MemAcc_BBMJobManager_QueueInternalJobForBBLutEntry(
  const MemAcc_BBLUTStartIdxOfMemInstanceType bbLutIdx)
{
  Std_ReturnType retVal = E_NOT_OK;

  const MemAcc_SubAddressAreaIndexType saaIdx = MemAcc_GetSAAIdxOfBBLUT(bbLutIdx);
  /*@ assert saaIdx < MemAcc_GetSizeOfSubAddressArea(); */ /* VCA_MemAcc_GetSAAIdxOfBBLUTAlwaysValid */

  switch (MemAcc_GetBBMarkerStateOfBBLUT(bbLutIdx))
  {
    case MEMACC_BBM_BBMARKERSTATE_MARKEDINLUT:
      if (MemAcc_Queue_HasJob(MemAcc_Utils_GetAddrAreaIdxOfSubAddrAreaIdx(saaIdx), TRUE) == FALSE)
      {
        retVal = MemAcc_BBMJobManager_QueueRecoverSectorOrEraseBlockJobDependingOnSectorOffset(bbLutIdx);
      }
      break;
    case MEMACC_BBM_BBMARKERSTATE_DATARECOVERED:
      if (MemAcc_Queue_HasJob(MemAcc_Utils_GetAddrAreaIdxOfSubAddrAreaIdx(saaIdx), TRUE) == FALSE)
      {
        retVal = MemAcc_BBMJobManager_QueueEraseBlockJob(saaIdx, MemAcc_GetPhysicalBlockNrOfBBLUT(bbLutIdx));
      }
      break;
    case MEMACC_BBM_BBMARKERSTATE_BLOCKERASED:
      if (MemAcc_Queue_HasJob(MemAcc_Utils_GetAddrAreaIdxOfSubAddrAreaIdx(saaIdx), TRUE) == FALSE)
      {
        retVal = MemAcc_BBMJobManager_QueueWriteBBMarkerJob(saaIdx, MemAcc_GetPhysicalBlockNrOfBBLUT(bbLutIdx));
      }
      break;
    case MEMACC_BBM_BBMARKERSTATE_MARKERWRITTEN:
    case MEMACC_BBM_BBMARKERSTATE_ERROR:
    case MEMACC_BBM_BBMARKERSTATE_NONE: /* COV_MemAcc_BBMJobManager_UnreachableEnumerationValue */
    default:  /* COV_MemAcc_BBMJobManager_MISRA */
      /* Do nothing */
      break;
  }

  return retVal;
}

/**********************************************************************************************************************
 * MemAcc_BBMJobManager_CalculateNextBlockToReadBBMarkerFromForAddressArea()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 * \spec
 *   requires aaIdx < MemAcc_GetSizeOfAddressArea();
 * \endspec
 */
MEMACC_LOCAL void MemAcc_BBMJobManager_CalculateNextBlockToReadBBMarkerFromForAddressArea(const MemAcc_AddressAreaIndexType aaIdx)
{
  AddressAreaInitState[aaIdx].InitState = MEMACC_BBM_INIT_DONE;

  if ((AddressAreaInitState[aaIdx].PhysicalBlockNr + 1u) >= MemAcc_GetNumberOfSectorsOfSubAddressArea(AddressAreaInitState[aaIdx].SaaIdx))
  {
    for (MemAcc_SubAddressAreaIndexType nextSaaIdx = AddressAreaInitState[aaIdx].SaaIdx + 1u;
      nextSaaIdx < MemAcc_GetSubAddressAreaEndIdxOfAddressArea(aaIdx);
      nextSaaIdx++)
    {
      if (MemAcc_GetBBStrategyOfMemInstance(MemAcc_GetMemInstanceIdxOfSubAddressArea(nextSaaIdx)) == MEMACC_BBM_BBSTRATEGY_SKIPMETHOD)
      {
        /* Next SAA exists that need to be scanned. Scan this SAA beginning with block 0. Each SAA has at least 1 block so this works. */
        AddressAreaInitState[aaIdx].InitState = MEMACC_BBM_INIT_PENDING;
        AddressAreaInitState[aaIdx].SaaIdx = nextSaaIdx;
        AddressAreaInitState[aaIdx].PhysicalBlockNr = 0u;
        break;
      }
    }
  }
  else
  {
    AddressAreaInitState[aaIdx].InitState = MEMACC_BBM_INIT_PENDING;
    AddressAreaInitState[aaIdx].PhysicalBlockNr++;
  }
}

/**********************************************************************************************************************
 * MemAcc_BBMJobManager_ProcessReadBBMarkerJobResult()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 * \spec
 *   requires job != NULL_PTR;
 *   requires job->JobArea.AddressAreaIndex < MemAcc_GetSizeOfAddressArea();
 * \endspec
 */
MEMACC_LOCAL void MemAcc_BBMJobManager_ProcessReadBBMarkerJobResult(const MemAcc_JobContextType* job)
{
  if ((job->MngmtArea.JobStep.Rejected == FALSE) && (job->MngmtArea.JobResult == MEMACC_OK))
  {
    /* If job was successful the information wether the block is bad is in the MemAcc_BBM_JobContext */
    if(MemAcc_BBM_JobContext[job->JobArea.AddressAreaIndex].ReadBBMarkerJobData.IsBbMarkerSet == MEMACC_MEMBBMARKERSTATUS_SET)
    {
      /* VCA Line+1 SPC-01 : VCA_MemAcc_SaaIdxOfJobContextIsValid */
      MemAcc_BBM_UpsertBadBlock(MEMACC_BBM_BBMARKERSTATE_MARKERWRITTEN,
        MemAcc_BBM_JobContext[job->JobArea.AddressAreaIndex].SaaIdx,
        MemAcc_BBM_JobContext[job->JobArea.AddressAreaIndex].PhysicalBlockNr);
    }

    MemAcc_BBMJobManager_CalculateNextBlockToReadBBMarkerFromForAddressArea(job->JobArea.AddressAreaIndex);
    (void)MemAcc_BBMJobManager_QueueReadBBMarkerJob(job->JobArea.AddressAreaIndex);
  }
  else
  {
    AddressAreaInitState[job->JobArea.AddressAreaIndex].InitState = MEMACC_BBM_INIT_FAILED;
    /* VCA Line+1 SPC-01 : VCA_MemAcc_SaaIdxOfJobContextIsValid */
    MemAcc_BBM_UpsertBadBlock(MEMACC_BBM_BBMARKERSTATE_ERROR,
      MemAcc_BBM_JobContext[job->JobArea.AddressAreaIndex].SaaIdx,
      MemAcc_BBM_JobContext[job->JobArea.AddressAreaIndex].PhysicalBlockNr);
    MemAcc_Queue_RaiseError(job->JobArea.AddressAreaIndex,
      (job->MngmtArea.JobStep.Rejected == TRUE) ? MEMACC_ERRORTYPE_BBM_READBBMARKER_REJECTED : MEMACC_ERRORTYPE_BBM_READBBMARKER_FAILED);
  }
}

/**********************************************************************************************************************
 * MemAcc_BBMJobManager_ProcessRecoverSectorJobResult()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 * \spec
 *   requires job != NULL_PTR;
 *   requires job->JobArea.AddressAreaIndex < MemAcc_GetSizeOfAddressArea();
 * \endspec
 */
MEMACC_LOCAL void MemAcc_BBMJobManager_ProcessRecoverSectorJobResult(const MemAcc_JobContextType* job)
{
  if ((job->MngmtArea.JobStep.Rejected == FALSE) && (job->MngmtArea.JobResult == MEMACC_OK))
  {
    /* VCA Line+1 SPC-01 : VCA_MemAcc_SaaIdxOfJobContextIsValid */
    MemAcc_BBM_UpsertBadBlock(MEMACC_BBM_BBMARKERSTATE_DATARECOVERED,
      MemAcc_BBM_JobContext[job->JobArea.AddressAreaIndex].SaaIdx,
      MemAcc_BBM_JobContext[job->JobArea.AddressAreaIndex].PhysicalBlockNr);
  }
  else if ((job->MngmtArea.JobStep.Rejected == FALSE) && (job->MngmtArea.JobStep.MemError == MEMACC_MEMERRORTYPE_P_FAIL))
  {
    /* The entry technically does not have to be updated since nothing changed. The function however also triggers requeueing of the job, which is not necessary. */
    /* VCA Line+1 SPC-01 : VCA_MemAcc_SaaIdxOfJobContextIsValid */
    MemAcc_BBM_UpsertBadBlock(MEMACC_BBM_BBMARKERSTATE_MARKEDINLUT,
      MemAcc_BBM_JobContext[job->JobArea.AddressAreaIndex].SaaIdx,
      MemAcc_BBM_JobContext[job->JobArea.AddressAreaIndex].PhysicalBlockNr);
  }
  else
  {
    /* VCA Line+1 SPC-01 : VCA_MemAcc_SaaIdxOfJobContextIsValid */
    MemAcc_BBM_UpsertBadBlock(MEMACC_BBM_BBMARKERSTATE_ERROR,
      MemAcc_BBM_JobContext[job->JobArea.AddressAreaIndex].SaaIdx,
      MemAcc_BBM_JobContext[job->JobArea.AddressAreaIndex].PhysicalBlockNr);
    MemAcc_Queue_RaiseError(job->JobArea.AddressAreaIndex,
      (job->MngmtArea.JobStep.Rejected == TRUE) ? MEMACC_ERRORTYPE_BBM_RECOVERSECTOR_REJECTED : MEMACC_ERRORTYPE_BBM_RECOVERSECTOR_FAILED);
  }
}

/**********************************************************************************************************************
 * MemAcc_BBMJobManager_ProcessEraseBlockJobResult()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 * \spec
 *   requires job != NULL_PTR;
 *   requires job->JobArea.AddressAreaIndex < MemAcc_GetSizeOfAddressArea();
 * \endspec
 */
MEMACC_LOCAL void MemAcc_BBMJobManager_ProcessEraseBlockJobResult(const MemAcc_JobContextType* job)
{
  if (job->MngmtArea.JobStep.Rejected == TRUE)
  {
    /* VCA Line+1 SPC-01 : VCA_MemAcc_SaaIdxOfJobContextIsValid */
    MemAcc_BBM_UpsertBadBlock(MEMACC_BBM_BBMARKERSTATE_ERROR,
      MemAcc_BBM_JobContext[job->JobArea.AddressAreaIndex].SaaIdx,
      MemAcc_BBM_JobContext[job->JobArea.AddressAreaIndex].PhysicalBlockNr);
    MemAcc_Queue_RaiseError(job->JobArea.AddressAreaIndex, MEMACC_ERRORTYPE_BBM_ERASEBLOCK_REJECTED);
  }
  else if (job->MngmtArea.JobStep.MemError == MEMACC_MEMERRORTYPE_P_FAIL)
  {
    /* P_FAIL is the only error that should not happen. All other job failures are ignored. */
    /* VCA Line+1 SPC-01 : VCA_MemAcc_SaaIdxOfJobContextIsValid */
    MemAcc_BBM_UpsertBadBlock(MEMACC_BBM_BBMARKERSTATE_ERROR,
      MemAcc_BBM_JobContext[job->JobArea.AddressAreaIndex].SaaIdx,
      MemAcc_BBM_JobContext[job->JobArea.AddressAreaIndex].PhysicalBlockNr);
    MemAcc_Queue_RaiseError(job->JobArea.AddressAreaIndex, MEMACC_ERRORTYPE_BBM_ERASEBLOCK_FAILED);
  }
  else
  {
    /* Even if the job failed, it doesnt matter as long the write BB marker job afterwards succeeds. */
    /* VCA Line+1 SPC-01 : VCA_MemAcc_SaaIdxOfJobContextIsValid */
    MemAcc_BBM_UpsertBadBlock(MEMACC_BBM_BBMARKERSTATE_BLOCKERASED,
      MemAcc_BBM_JobContext[job->JobArea.AddressAreaIndex].SaaIdx,
      MemAcc_BBM_JobContext[job->JobArea.AddressAreaIndex].PhysicalBlockNr);
  }
}

/**********************************************************************************************************************
 * MemAcc_BBMJobManager_ProcessWriteBBMarkerJobResult()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 * \spec
 *   requires job != NULL_PTR;
 *   requires job->JobArea.AddressAreaIndex < MemAcc_GetSizeOfAddressArea();
 * \endspec
 */
MEMACC_LOCAL void MemAcc_BBMJobManager_ProcessWriteBBMarkerJobResult(const MemAcc_JobContextType* job)
{
  if((job->MngmtArea.JobStep.Rejected == FALSE) && (job->MngmtArea.JobResult == MEMACC_OK))
  {
    /* VCA Line+1 SPC-01 : VCA_MemAcc_SaaIdxOfJobContextIsValid */
    MemAcc_BBM_UpsertBadBlock(MEMACC_BBM_BBMARKERSTATE_MARKERWRITTEN,
      MemAcc_BBM_JobContext[job->JobArea.AddressAreaIndex].SaaIdx,
      MemAcc_BBM_JobContext[job->JobArea.AddressAreaIndex].PhysicalBlockNr);
  }
  else
  {
    /* VCA Line+1 SPC-01 : VCA_MemAcc_SaaIdxOfJobContextIsValid */
    MemAcc_BBM_UpsertBadBlock(MEMACC_BBM_BBMARKERSTATE_ERROR,
      MemAcc_BBM_JobContext[job->JobArea.AddressAreaIndex].SaaIdx,
      MemAcc_BBM_JobContext[job->JobArea.AddressAreaIndex].PhysicalBlockNr);
    MemAcc_Queue_RaiseError(job->JobArea.AddressAreaIndex,
      (job->MngmtArea.JobStep.Rejected == TRUE) ? MEMACC_ERRORTYPE_BBM_WRITEBBMARKER_REJECTED : MEMACC_ERRORTYPE_BBM_WRITEBBMARKER_FAILED);
  }
}

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * MemAcc_BBMJobManager_Reset()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
void MemAcc_BBMJobManager_Reset(void)
{
  MemAcc_BBMJobManager_ResetAllJobContexts();
  MemAcc_BBMJobManager_ResetAndPrepareInitScan();

  /* Immediately queues the first batch of init scan jobs. Ensure that the BBM_JobManager is reset after the Queue. */
  for (MemAcc_AddressAreaIndexType aaIdx = 0u; aaIdx < MemAcc_GetSizeOfAddressArea(); aaIdx++)
  {
    (void)MemAcc_BBMJobManager_QueueReadBBMarkerJob(aaIdx);
  }
}

/**********************************************************************************************************************
 * MemAcc_BBMJobManager_ProcessInternalJobResult()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 * \spec
 *   requires job != NULL_PTR;
 * \endspec
 */
void MemAcc_BBMJobManager_ProcessInternalJobResult(const MemAcc_JobContextType* job)
{
  /*@ assert job->JobArea.AddressAreaIndex < MemAcc_GetSizeOfAddressArea(); */ /* VCA_MemAcc_AddressAreaIndexAlwaysValid */
  switch (job->JobArea.JobClassification)
  {
  case MEMACC_JOBCLASSIFICATION_BBM_READBBMARKER:
    MemAcc_BBMJobManager_ProcessReadBBMarkerJobResult(job);
    break;
  case MEMACC_JOBCLASSIFICATION_BBM_RECOVERSECTOR:
    MemAcc_BBMJobManager_ProcessRecoverSectorJobResult(job);
    break;
  case MEMACC_JOBCLASSIFICATION_BBM_ERASEBLOCK:
    MemAcc_BBMJobManager_ProcessEraseBlockJobResult(job);
    break;
  case MEMACC_JOBCLASSIFICATION_BBM_WRITEBBMARKER:
    MemAcc_BBMJobManager_ProcessWriteBBMarkerJobResult(job);
    break;
  case MEMACC_JOBCLASSIFICATION_USERJOB:
  default:  /* COV_MemAcc_BBMJobManager_MISRA */
    /* nothing to do */
    break;
  }
}

/**********************************************************************************************************************
 * MemAcc_BBMJobManager_NotifyBBLutEntryChanged()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 * \spec
 *   requires bbLutIdx < MemAcc_GetSizeOfBBLUT();
 * \endspec
 */
void MemAcc_BBMJobManager_NotifyBBLutEntryChanged(const MemAcc_BBLUTStartIdxOfMemInstanceType bbLutIdx)
{
  /*
   * Since internal BBM jobs are executed in sequence and the BB LUT is ordered by SAA index and then by physical block number,
   * only the given bbLutIdx and the next bbLutIdx (saa matches and physical block number is in sequence) could have a job to process.
   * For the next bbLutIdx this is only the case, if during sector recovery job, a BB is detected.
   *
   * If the internal queue is used by another unit and immediate queuing might not be possible this has to be revised.
  */

  const MemAcc_BBLUTStartIdxOfMemInstanceType nextBbLutIdx = bbLutIdx + 1u;
  const MemAcc_SubAddressAreaIndexType saaIdx = MemAcc_GetSAAIdxOfBBLUT(bbLutIdx);
  /*@ assert saaIdx < MemAcc_GetSizeOfSubAddressArea(); */ /* VCA_MemAcc_GetSAAIdxOfBBLUTAlwaysValid */

  (void)MemAcc_BBMJobManager_QueueInternalJobForBBLutEntry(bbLutIdx);

  /* Check that the next bbLutIdx is in the same SAA and in the same MemInstance index. */
  if ((nextBbLutIdx < MemAcc_GetBBLUTEndIdxOfMemInstance(MemAcc_GetMemInstanceIdxOfSubAddressArea(saaIdx)))
    && (saaIdx == MemAcc_GetSAAIdxOfBBLUT(nextBbLutIdx)))
  {
    /* If the bbLutIdx succeeded in queueing a job, it gets rejected since its in the same AA. So no further checks needed. */
    /*@ assert nextBbLutIdx < MemAcc_GetSizeOfBBLUT(); */ /* VCA_MemAcc_BBLUTIteration */
    (void)MemAcc_BBMJobManager_QueueInternalJobForBBLutEntry(nextBbLutIdx);
  }
}

/**********************************************************************************************************************
 * MemAcc_BBMJobManager_CalculatePhysicalAddressFromJobContext()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
MemAcc_AddressType MemAcc_BBMJobManager_CalculatePhysicalAddressFromJobContext(const MemAcc_AddressAreaIndexType aaIdx)
{
  return MemAcc_Utils_GetPhysicalAddress(
    MemAcc_BBM_JobContext[aaIdx].SaaIdx,
    MemAcc_BBM_JobContext[aaIdx].PhysicalBlockNr);
}

#define MEMACC_STOP_SEC_CODE
#include "MemAcc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* (MEMACC_BBM_ENABLED == STD_ON) */

/***********************************************************************************************************************
 *  VCA JUSTIFICATIONS
 **********************************************************************************************************************/
/* VCA_JUSTIFICATION_BEGIN

\ID VCA_MemAcc_GetSAAIdxOfBBLUTAlwaysValid
  \DESCRIPTION  Getting the SAA index of the BB LUT entry should always be smaller then MemAcc_GetSizeOfSubAddressArea().

  \COUNTERMEASURE \R Valid SubAddressAreas are calculated and checked within the job processing unit MemAcc_JobProcessing_CalculateNextJobStep().
                     These values are used thoughout processing.
                     Additionally the MemAcc_SetSAAIdxOfBBLUT is only used during reset (sets it to 0) and as a result
                     of calling MemAcc_BBM_InsertSkipMethodBadBlockUsingInsertionSort() which requires the SAA index to be valid.

\ID VCA_MemAcc_GetAddrAreaIdxOfSubAddrAreaIdxIsValid
  \DESCRIPTION  When calling the MemAcc_Utils_GetAddrAreaIdxOfSubAddrAreaIdx() with a valid saaIdx the result should always be valid.

  \COUNTERMEASURE \R Valid SubAddressAreas are calculated and checked within the job processing unit MemAcc_JobProcessing_CalculateNextJobStep().
                     These values are used thoughout processing.
                     Additional VCA checks (strong type invariants and assertions) are used to verify this the validity of the SubAddressArea index.

\ID VCA_MemAcc_AddressAreaIndexAlwaysValid
  \DESCRIPTION  The AddressAreaIndex of a job should always be valid.

  \COUNTERMEASURE \R The AddressAreaIndex of every job is always valid. It is only set in the following scenarios which are justified:
                     1. MemAcc API Call: See VCA_MemAcc_AddressAreaIndexAssertionFail
                     2. Internal Job Queuing: See VCA_MemAcc_GetAddrAreaIdxOfSubAddrAreaIdxIsValid

\ID VCA_MemAcc_SaaIdxOfJobContextIsValid
  \DESCRIPTION  The SaaIdx of the job context should always be valid.

  \COUNTERMEASURE \R Valid SubAddressAreas are calculated and checked within the job processing unit MemAcc_JobProcessing_CalculateNextJobStep().
                     These values are used thoughout processing.
                     The SaaIdx of the JobContext is only ever changed using the MemAcc_BBMJobManager_QueueInternalJobForBBLutEntry() function.
                     This function verifies via VCA that the used SaaIdx is valid.

\ID VCA_MemAcc_SaaIdxOfAddressAreaInitStateIsValid
  \DESCRIPTION  Access to MemAcc_SubAddressArea via indirection over MemAcc_AddressArea.

  \COUNTERMEASURE \R  This SaaIdx is only ever changed during MemAcc_BBMJobManager_ResetAndPrepareInitScan() and MemAcc_BBMJobManager_CalculateNextBlockToReadBBMarkerFromForAddressArea().
                      In both functions the SaaIdx is 0 which is valid or a qualified use-case CSL03 of ComStackLib.
                      MemAcc_BBMJobManager_ResetAndPrepareInitScan() is always called during initialization.
                  \N  Qualified use-case CSL03 of ComStackLib.

VCA_JUSTIFICATION_END */

/***********************************************************************************************************************
 *  COV JUSTIFICATION
 **********************************************************************************************************************/
/* COV_JUSTIFICATION_BEGIN

\ID COV_MemAcc_BBMJobManager_MISRA
\ACCEPT XX
\REASON [COV_MSR_MISRA]

\ID COV_MemAcc_BBMJobManager_UnreachableEnumerationValue
\ACCEPT XX
\REASON The enum value MEMACC_BBM_BBMARKERSTATE_NONE can not be reached within the implementation.
Nevertheless there is a compilation error if this case is not implemented.

COV_JUSTIFICATION_END */
/**********************************************************************************************************************
 *  END OF FILE: MemAcc_BBMJobManager.c
 *********************************************************************************************************************/
