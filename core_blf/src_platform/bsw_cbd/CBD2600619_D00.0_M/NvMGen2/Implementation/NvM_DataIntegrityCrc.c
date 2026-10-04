/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2025 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!        \file  NvM_DataIntegrityCrc.c
 *        \brief  NvM_DataIntegrityCrc source file
 *      \details  Implementation of the data integrity service unit of the NvM.
 *         \unit  NvM_DataIntegrityCrc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#define NVM_DATAINTEGRITYCRC_SOURCE

 /**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "NvM_DataIntegrityCrc.h"
#include "Crc.h"
#include "NvM_InternalTypes.h"
#include "NvM_GlobalUtilityLib.h"
#include "NvM_CfgDefines.h"

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
#define NVM_LENGTH_BLOCKID_CHECK 3u

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

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
#define NVM_START_SEC_CODE
#include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if(NVM_USE_BLOCK_ID_CHECK == STD_ON) /* COV_NVM_USEBLOCKIDCHECK */

/**********************************************************************************************************************
 * NvM_DataIntegrityCrc_ProcessBlockIdCheck
 *********************************************************************************************************************/
/*! \brief       Processes the BlockId check
 *  \details     -
 *  \param[in,out]   Instance  Service instance which contains relevant information about the job.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
NVM_LOCAL_INLINE FUNC(void, NVM_PRIVATE_CODE) NvM_DataIntegrityCrc_ProcessBlockIdCheck(
  NvM_DataIntegrityService_InstancePtrType Instance);

#endif

/**********************************************************************************************************************
 * NvM_DataIntegrityCrc_Calculate_Crc16()
 *********************************************************************************************************************/
/*! \brief       Calculates a Crc16 data integrity record.
 *  \details     -
 *  \param[in]   dataBuffer                Pointer to data which is used for calculation
 *  \param[in]   currentLength             The current length of bytes the CRC Lib gets for calculation.
 *  \param[in,out]   Instance  Service instance which contains relevant information about the job.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
NVM_LOCAL_INLINE FUNC(void, NVM_PRIVATE_CODE) NvM_DataIntegrityCrc_Calculate_Crc16(
  NvM_DataPtrToConstType dataBuffer,
  uint32 currentLength,
  NvM_DataIntegrityService_InstancePtrType Instance);

/**********************************************************************************************************************
 * NvM_DataIntegrityCrc_Append_Crc16()
 *********************************************************************************************************************/
/*! \brief           Appends CRC16 CurrentCrcValue to the DataIntegrityRecordPtr
 *  \details         -
 *  \param[in,out]   Instance  Service instance which contains relevant information about the job.
 *  \pre             -
 *  \context         TASK
 *  \reentrant       FALSE
 *  \synchronous     TRUE
 *********************************************************************************************************************/
NVM_LOCAL_INLINE FUNC(void, NVM_PRIVATE_CODE) NvM_DataIntegrityCrc_Append_Crc16(
  NvM_DataIntegrityService_InstancePtrToConstType Instance);

/**********************************************************************************************************************
 * NvM_DataIntegrityCrc_Compare_Crc16()
 *********************************************************************************************************************/
/*! \brief           Compares CRC16 CurrentCrcValue with DataIntegrityRecordPtr
 *  \details         -
 *  \param[in,out]   Instance  Service instance which contains relevant information about the job.
 *  \pre             -
 *  \context         TASK
 *  \reentrant       FALSE
 *  \synchronous     TRUE
 *********************************************************************************************************************/
NVM_LOCAL_INLINE FUNC(boolean, NVM_PRIVATE_CODE) NvM_DataIntegrityCrc_Compare_Crc16(
  NvM_DataIntegrityService_InstancePtrToConstType Instance);

/**********************************************************************************************************************
 * NvM_DataIntegrityCrc_Calculate_Crc32()
 *********************************************************************************************************************/
/*! \brief       Calculates a Crc32 data integrity record.
 *  \details     -
 *  \param[in]   dataBuffer                Pointer to data which is used for calculation
 *  \param[in]   currentLength             The current length of bytes the CRC Lib gets for calculation.
 *  \param[in,out]   Instance  Service instance which contains relevant information about the job.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
NVM_LOCAL_INLINE FUNC(void, NVM_PRIVATE_CODE) NvM_DataIntegrityCrc_Calculate_Crc32(
  NvM_DataPtrToConstType dataBuffer,
  uint32 currentLength,
  NvM_DataIntegrityService_InstancePtrType Instance);

/**********************************************************************************************************************
 * NvM_DataIntegrityCrc_Append_Crc32()
 *********************************************************************************************************************/
/*! \brief           Appends CRC32 CurrentCrcValue to the DataIntegrityRecordPtr
 *  \details         -
 *  \param[in,out]   Instance  Service instance which contains relevant information about the job.
 *  \pre             -
 *  \context         TASK
 *  \reentrant       FALSE
 *  \synchronous     TRUE
 *********************************************************************************************************************/
NVM_LOCAL_INLINE FUNC(void, NVM_PRIVATE_CODE) NvM_DataIntegrityCrc_Append_Crc32(
  NvM_DataIntegrityService_InstancePtrToConstType Instance);

/**********************************************************************************************************************
 * NvM_DataIntegrityCrc_Compare_Crc32()
 *********************************************************************************************************************/
/*! \brief           Compares CRC32 CurrentCrcValue with DataIntegrityRecordPtr
 *  \details         -
 *  \param[in,out]   Instance  Service instance which contains relevant information about the job.
 *  \pre             -
 *  \context         TASK
 *  \reentrant       FALSE
 *  \synchronous     TRUE
 *********************************************************************************************************************/
NVM_LOCAL_INLINE FUNC(boolean, NVM_PRIVATE_CODE) NvM_DataIntegrityCrc_Compare_Crc32(
  NvM_DataIntegrityService_InstancePtrToConstType Instance);

/**********************************************************************************************************************
 * NvM_DataIntegrityCrc_GenerateCrcStep
 *********************************************************************************************************************/
/*! \brief       Generates one step of the CRC.
 *  \details     -
 *  \param[in,out]   Instance  Service instance which contains relevant information about the job.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
NVM_LOCAL_INLINE FUNC(void, NVM_PRIVATE_CODE) NvM_DataIntegrityCrc_GenerateCrcStep(
  NvM_DataIntegrityService_InstancePtrType Instance);

#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

#define NVM_START_SEC_CONST_UNSPECIFIED
#include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

NVM_LOCAL CONST(NvM_DataIntegrityCrcStrategyType, NVM_PRIVATE_CODE) NvM_DataIntegrityCrc_Strategy_Crc16 =
{
  NvM_DataIntegrityCrc_Calculate_Crc16,
  NvM_DataIntegrityCrc_Append_Crc16,
  NvM_DataIntegrityCrc_Compare_Crc16,
  NVM_DATAINTEGRITYRECORD_SIZE_CRC16
};

NVM_LOCAL CONST(NvM_DataIntegrityCrcStrategyType, NVM_PRIVATE_CODE) NvM_DataIntegrityCrc_Strategy_Crc32 =
{
  NvM_DataIntegrityCrc_Calculate_Crc32,
  NvM_DataIntegrityCrc_Append_Crc32,
  NvM_DataIntegrityCrc_Compare_Crc32,
  NVM_DATAINTEGRITYRECORD_SIZE_CRC32
};

#define NVM_STOP_SEC_CONST_UNSPECIFIED
#include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

#define NVM_START_SEC_CODE
#include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if(NVM_USE_BLOCK_ID_CHECK == STD_ON) /* COV_NVM_USEBLOCKIDCHECK */

/**********************************************************************************************************************
 *  NvM_DataIntegrityCrc_ProcessBlockIdCheck
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
NVM_LOCAL_INLINE FUNC(void, NVM_PRIVATE_CODE) NvM_DataIntegrityCrc_ProcessBlockIdCheck(
  NvM_DataIntegrityService_InstancePtrType Instance)
{
  const uint8 blockIdCheckData[NVM_LENGTH_BLOCKID_CHECK] = {
    (uint8)(Instance->BlockId >> 8),
    (uint8)Instance->BlockId,
    Instance->DataIndex
  };

#if !defined(__VCA__) /* COV_NVM_VCA */
    /* VCA Disable SLC-10, SLC-22 : VCA_NVM_DataIntegrityStrategy */
  Instance->CrcContext.CrcStrategy.Calculate(blockIdCheckData, NVM_LENGTH_BLOCKID_CHECK, Instance);
    /* VCA Enable : VCA_NVM_DataIntegrityStrategy */ 
#endif
}

#endif

/**********************************************************************************************************************
 *  NvM_DataIntegrityCrc_Calculate_Crc16
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 * 
 * \spec
 *    requires Instance != NULL_PTR;
 * \endspec
 */
NVM_LOCAL_INLINE FUNC(void, NVM_PRIVATE_CODE) NvM_DataIntegrityCrc_Calculate_Crc16(
  NvM_DataPtrToConstType dataBuffer,
  uint32 currentLength,
  NvM_DataIntegrityService_InstancePtrType Instance)
{
  Instance->CrcContext.CurrentCrcValue = Crc_CalculateCRC16(dataBuffer,
    currentLength, (uint16)Instance->CrcContext.CurrentCrcValue, Instance->CrcContext.IsFirstCall);
}

/**********************************************************************************************************************
 * NvM_DataIntegrityCrc_Append_Crc16()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 * 
 * \spec
 *    requires Instance != NULL_PTR;
 * \endspec
 */
NVM_LOCAL_INLINE FUNC(void, NVM_PRIVATE_CODE) NvM_DataIntegrityCrc_Append_Crc16(
  NvM_DataIntegrityService_InstancePtrToConstType Instance)
{
  /* Get LSF Bytes of CurrentCrcValue by cast to uint16 */
  uint16 crc16Val = ((uint16)Instance->CrcContext.CurrentCrcValue);
  /* Cast current CRC value address to NvM_DataPtrToConstType in order to be able to bytewise append */ 
  NvM_DataPtrToConstType crc16ValPtr = ((NvM_DataPtrToConstType)&crc16Val);

  NvM_GlobalUtilityLib_CopyDataIntegrityRecord(NVM_BLOCK_DATA_INTEGRITY_CRC_16, 
    Instance->DataIntegrityRecordPtr,
    crc16ValPtr);
}

/**********************************************************************************************************************
 * NvM_DataIntegrityCrc_Compare_Crc16()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 * 
 * \spec
 *    requires Instance != NULL_PTR;
 *    requires Instance->DataIntegrityRecordPtr != NULL_PTR;
 *    requires $lengthOf(Instance->DataIntegrityRecordPtr) == 2;
 * \endspec
 */
NVM_LOCAL_INLINE FUNC(boolean, NVM_PRIVATE_CODE) NvM_DataIntegrityCrc_Compare_Crc16(
  NvM_DataIntegrityService_InstancePtrToConstType Instance)
{
  /* Get LSF Bytes of CurrentCrcValue by cast to uint16 */
  uint16 crc16Val = ((uint16)Instance->CrcContext.CurrentCrcValue);
  /* Cast current CRC value address to NvM_DataPtrToConstType in order to be able to bytewise compare */ 
  NvM_DataPtrToConstType crc16ValPtr = (NvM_DataPtrToConstType)&crc16Val;

  return (
    (Instance->DataIntegrityRecordPtr[0] == crc16ValPtr[0])
    && (Instance->DataIntegrityRecordPtr[1] == crc16ValPtr[1])
  );
}

/**********************************************************************************************************************
 *  NvM_DataIntegrityCrc_Calculate_Crc32
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 * 
 * \spec
 *    requires Instance != NULL_PTR;
 * \endspec
 */
NVM_LOCAL_INLINE FUNC(void, NVM_PRIVATE_CODE) NvM_DataIntegrityCrc_Calculate_Crc32(
  NvM_DataPtrToConstType dataBuffer,
  uint32 currentLength,
  NvM_DataIntegrityService_InstancePtrType Instance)
{
  Instance->CrcContext.CurrentCrcValue = Crc_CalculateCRC32(dataBuffer,
    currentLength, Instance->CrcContext.CurrentCrcValue, Instance->CrcContext.IsFirstCall); 
}

/**********************************************************************************************************************
 * NvM_DataIntegrityCrc_Append_Crc32()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 * 
 * \spec
 *    requires Instance != NULL_PTR;
 *    requires Instance->DataIntegrityRecordPtr != NULL_PTR;
 *    requires $lengthOf(Instance->DataIntegrityRecordPtr) == 4;
 * \endspec
 */
NVM_LOCAL_INLINE FUNC(void, NVM_PRIVATE_CODE) NvM_DataIntegrityCrc_Append_Crc32(
  NvM_DataIntegrityService_InstancePtrToConstType Instance)
{
  /* Cast current CRC value address to NvM_DataPtrToConstType in order to be able to bytewise append */ 
  NvM_DataPtrToConstType crc32ValPtr = (NvM_DataPtrToConstType)&Instance->CrcContext.CurrentCrcValue;

  NvM_GlobalUtilityLib_CopyDataIntegrityRecord(NVM_BLOCK_DATA_INTEGRITY_CRC_32,
    Instance->DataIntegrityRecordPtr,
    crc32ValPtr);
}

/**********************************************************************************************************************
 * NvM_DataIntegrityCrc_Compare_Crc32()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 * 
 * \spec
 *    requires Instance != 0;
 *    requires Instance->DataIntegrityRecordPtr != NULL_PTR;
 *    requires $lengthOf(Instance->DataIntegrityRecordPtr) == 4;
 * \endspec
 */
NVM_LOCAL_INLINE FUNC(boolean, NVM_PRIVATE_CODE) NvM_DataIntegrityCrc_Compare_Crc32(
  NvM_DataIntegrityService_InstancePtrToConstType Instance)
{
  /* Cast current CRC value address to NvM_DataPtrToConstType in order to be able to bytewise compare */ 
  NvM_DataPtrToConstType crc32ValPtr = (NvM_DataPtrToConstType)&Instance->CrcContext.CurrentCrcValue;

  return (
    (Instance->DataIntegrityRecordPtr[0] == crc32ValPtr[0])
    && (Instance->DataIntegrityRecordPtr[1] == crc32ValPtr[1])
    && (Instance->DataIntegrityRecordPtr[2] == crc32ValPtr[2])
    && (Instance->DataIntegrityRecordPtr[3] == crc32ValPtr[3])
  );
}

/**********************************************************************************************************************
 * NvM_DataIntegrityCrc_GenerateCrcStep()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
NVM_LOCAL_INLINE FUNC(void, NVM_PRIVATE_CODE) NvM_DataIntegrityCrc_GenerateCrcStep(
  NvM_DataIntegrityService_InstancePtrType Instance)
{
  uint16 currentLength = 0u;

  if(Instance->CrcContext.RemainingLength >= NVM_CRC_NUM_OF_BYTES_PER_CYCLE)
  {
    currentLength = NVM_CRC_NUM_OF_BYTES_PER_CYCLE;
    Instance->CrcContext.RemainingLength -= NVM_CRC_NUM_OF_BYTES_PER_CYCLE;
  }
  else
  {
    currentLength = Instance->CrcContext.RemainingLength;
    Instance->CrcContext.RemainingLength = 0u;
  }

#if !defined(__VCA__) /* COV_NVM_VCA */
    /* VCA Disable SLC-10, SLC-22 : VCA_NVM_DataIntegrityStrategy */
    Instance->CrcContext.CrcStrategy.Calculate(Instance->BlockDataPtr, currentLength, Instance);
    /* VCA Enable : VCA_NVM_DataIntegrityStrategy */ 
#endif

  Instance->BlockDataPtr = &Instance->BlockDataPtr[currentLength];
}

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  NvM_DataIntegrityCrc_Init
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, NVM_PRIVATE_CODE) NvM_DataIntegrityCrc_Init(
  NvM_DataIntegrityService_InstancePtrType Instance
)
{
  Instance->JobStatus = NVM_DATAINTEGRITYSERVICE_STATUS_PENDING;

  Instance->CrcContext.CurrentCrcValue = 0u;
  Instance->CrcContext.RemainingLength = Instance->BlockDataLength;
  Instance->CrcContext.IsFirstCall = TRUE;
  
  switch(Instance->DataIntegrityType)
  {
    case NVM_BLOCK_DATA_INTEGRITY_CRC_16:
      Instance->CrcContext.CrcStrategy = NvM_DataIntegrityCrc_Strategy_Crc16;
      break;
    /* The default case is NVM_BLOCK_DATA_INTEGRITY_CRC_32 */
    default:
      Instance->CrcContext.CrcStrategy = NvM_DataIntegrityCrc_Strategy_Crc32;
      break;
  }
}


/**********************************************************************************************************************
 *  NvM_DataIntegrityCrc_Process
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
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(void, NVM_PRIVATE_CODE) NvM_DataIntegrityCrc_Process(
  NvM_DataIntegrityService_InstancePtrType Instance
)
{
  if (Instance->JobStatus == NVM_DATAINTEGRITYSERVICE_STATUS_PENDING)
  {
#if (NVM_USE_BLOCK_ID_CHECK == STD_ON) /* COV_NVM_USEBLOCKIDCHECK */
    if (Instance->CrcContext.IsFirstCall == TRUE)
    {
      NvM_DataIntegrityCrc_ProcessBlockIdCheck(Instance);
      Instance->CrcContext.IsFirstCall = FALSE;
    }
    else
#endif
    {
      NvM_DataIntegrityCrc_GenerateCrcStep(Instance);
      Instance->CrcContext.IsFirstCall = FALSE;

      /* Final step was processed */
      if (Instance->CrcContext.RemainingLength == 0u)
      {
        /* Perform CRC job processing */
        if (Instance->JobType == NVM_DATAINTEGRITYSERVICE_JOB_GENERATE)
        {
#if !defined(__VCA__) /* COV_NVM_VCA */
          /* VCA Disable SLC-10, SLC-22 : VCA_NVM_DataIntegrityStrategy */
          Instance->CrcContext.CrcStrategy.Append(Instance);
          /* VCA Enable : VCA_NVM_DataIntegrityStrategy */ 
#endif
          Instance->JobStatus = NVM_DATAINTEGRITYSERVICE_STATUS_FINISHED_SUCCESSFUL;
        }
        else /* NVM_DATAINTEGRITYCRC_JOB_VERIFY */
        {
          /* Compare recalculated CRC with stored CRC */
          boolean isIdentical = FALSE;

#if !defined(__VCA__) /* COV_NVM_VCA */
          /* VCA Disable SLC-10, SLC-22 : VCA_NVM_DataIntegrityStrategy */
          isIdentical = Instance->CrcContext.CrcStrategy.Compare(Instance);
          /* VCA Enable : VCA_NVM_DataIntegrityStrategy */ 
#endif

          Instance->JobStatus = isIdentical ?
            NVM_DATAINTEGRITYSERVICE_STATUS_FINISHED_SUCCESSFUL :
            NVM_DATAINTEGRITYSERVICE_STATUS_FINISHED_UNSUCCESSFUL;
        }
      }
    }
  }
}

#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
