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
/*!        \file  NvM_Types.h
 *        \brief  NvM types header file
 **********************************************************************************************************************/

#if !defined (NVM_TYPES_H)
# define NVM_TYPES_H

/***********************************************************************************************************************
 * INCLUDES
 **********************************************************************************************************************/
#include "Std_Types.h"
/* #include "NvM_Swc_Types.h" */
#include "NvM_CfgDefines.h"

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

#if !defined (NVM_LOCAL) /* COV_NVM_COMPATIBILITY */
# define NVM_LOCAL static
#endif

#if !defined (NVM_LOCAL_INLINE) /* COV_NVM_COMPATIBILITY */
# define NVM_LOCAL_INLINE LOCAL_INLINE
#endif

/*
 * VCA specific defines
 * Only provided if Rte header is not available
 */
#ifndef Rte_TypeDef_NvM_BlockIdType
#if defined(__VCA__) /* COV_NVM_VCA */
uint8 GetSizeOfPartitionIdentifiers(void);
uint16 GetSizeOfBlockDescriptor(void);
#endif
#endif

/**********************************************************************************************************************
  GLOBAL CONSTANT MACROS
**********************************************************************************************************************/

/* DCM Block Offset */
#define NVM_DCM_BLOCK_OFFSET                   0x8000u

/**********************************************************************************************************************
 * API TYPE DEFINITIONS
 *********************************************************************************************************************/

/*!< Type used to store a job result. Published via GetErrorStatus API. */
#ifndef Rte_TypeDef_NvM_RequestResultType
typedef uint8 NvM_RequestResultType;
#endif

/* Result values of asynchronous requests (stored in the RAM Management),
 * They are also defined by the RTE, since these are the important values for an SW-C */
#ifndef NVM_REQ_OK
# define NVM_REQ_OK                     (0u)  /* The last asynchronous request has been finished successfully */
#endif
#ifndef NVM_REQ_NOT_OK
# define NVM_REQ_NOT_OK                 (1u)  /* The last asynchronous request has been finished unsuccessfully */
#endif
#ifndef NVM_REQ_PENDING
# define NVM_REQ_PENDING                (2u)  /* An asynchronous request is currently being processed */
#endif
#ifndef NVM_REQ_INTEGRITY_FAILED
# define NVM_REQ_INTEGRITY_FAILED       (3u)  /* Result of the last NvM_ReadBlock or NvM_ReadAll is an integrity failure */
#endif
#ifndef NVM_REQ_BLOCK_SKIPPED
# define NVM_REQ_BLOCK_SKIPPED          (4u)  /* The referenced block was skipped during a multi block request */
#endif
#ifndef NVM_REQ_NV_INVALIDATED
# define NVM_REQ_NV_INVALIDATED         (5u)  /* The NV block is invalidated. */
#endif
#ifndef NVM_REQ_CANCELED
# define NVM_REQ_CANCELED               (6u)  /* A WriteAll was cancelled */
#endif
#ifndef NVM_REQ_REDUNDANCY_FAILED
# define NVM_REQ_REDUNDANCY_FAILED      (7u) /* A redundant block lost its redundancy */
#endif
#ifndef NVM_REQ_RESTORED_DEFAULTS
# define NVM_REQ_RESTORED_DEFAULTS      (8u) /* Default data from ROM are restored */
#endif
/* Map the REQ_RESTORED_DEFAULTS to NVM_REQ_RESTORED_FROM_ROM request result type due to backward compatibility. */
#ifndef NVM_REQ_RESTORED_FROM_ROM
# define NVM_REQ_RESTORED_FROM_ROM      NVM_REQ_RESTORED_DEFAULTS  /* Default data from ROM are restored */
#endif

/* Internal Service ID Definition */
#define NVM_SID_INIT                     (0x00u)  /*!< Service ID NvM_Init().                     */
#define NVM_SID_SETDATAINDEX             (0x01u)  /*!< Service ID NvM_SetDataIndex().             */
#define NVM_SID_GETDATAINDEX             (0x02u)  /*!< Service ID NvM_GetDataIndex().             */
#define NVM_SID_SETBLOCKPROTECTION       (0x03u)  /*!< Service ID NvM_SetBlockProtection().       */
#define NVM_SID_GETERRORSTATUS           (0x04u)  /*!< Service ID NvM_GetErrorStatus().           */
#define NVM_SID_SETRAMBLOCKSTATUS        (0x05u)  /*!< Service ID NvM_SetRamBlockStatus().        */
#define NVM_SID_READBLOCK                (0x06u)  /*!< Service ID NvM_ReadBlock().                */
#define NVM_SID_WRITEBLOCK               (0x07u)  /*!< Service ID NvM_WriteBlock().               */
#define NVM_SID_RESTOREBLOCKDEFAULTS     (0x08u)  /*!< Service ID NvM_RestoreBlockDefaults().     */
#define NVM_SID_ERASENVBLOCK             (0x09u)  /*!< Service ID NvM_EraseNvBlock().             */
#define NVM_SID_CANCELWRITEALL           (0x0Au)  /*!< Service ID NvM_CancelWriteAll().           */
#define NVM_SID_INVALIDATENVBLOCK        (0x0Bu)  /*!< Service ID NvM_InvalidateNvBlock().        */
#define NVM_SID_READALL                  (0x0Cu)  /*!< Service ID NvM_ReadAll().                  */
#define NVM_SID_WRITEALL                 (0x0Du)  /*!< Service ID NvM_WriteAll().                 */
#define NVM_SID_MAINFUNCTION             (0x0Eu)  /*!< Service ID NvM_MainFunction().             */
#define NVM_SID_GETVERSIONINFO           (0x0Fu)  /*!< Service ID NvM_GetVersionInfo().           */
#define NVM_SID_CANCELJOBS               (0x10u)  /*!< Service ID NvM_CancelJobs().               */
#define NVM_SID_JOBENDNOTIFICATION       (0x11u)  /*!< Service ID NvM_JobEndNotification().       */
#define NVM_SID_JOBERRORNOTIFICATION     (0x12u)  /*!< Service ID NvM_JobErrorNotification().     */
#define NVM_SID_SETBLOCKLOCKSTATUS       (0x13u)  /*!< Service ID NvM_SetBlockLockStatus().       */
#define NVM_SID_READPRAMBLOCK            (0x16u)  /*!< Service ID NvM_ReadPRAMBlock().            */
#define NVM_SID_WRITEPRAMBLOCK           (0x17u)  /*!< Service ID NvM_WritePRAMBlock().           */
#define NVM_SID_RESTOREPRAMBLOCKDEFAULTS (0x18u)  /*!< Service ID NvM_RestorePRAMBlockDefaults(). */
#define NVM_SID_VALIDATEALL              (0x19u)  /*!< Service ID NvM_ValidateAll().              */

/* Non-Autosar Service IDs */
#define NVM_SID_KILLREADALL                      (0xF0u)  /*!< Service ID NvM_KillReadAll().                          */
#define NVM_SID_KILLWRITEALL                     (0xF1u)  /*!< Service ID NvM_KillWriteAll().                         */
#define NVM_SID_GETACTIVEMULTIBLOCKAPPLICATIONID (0xF2u)  /*!< Service ID NvM_GetActiveMultiBlockPartitionId().       */

/* Map the internal ServiceIds to user defined ServiceIds to be compatible to user implementations */

#define NVM_INIT                       NVM_SID_INIT                     /*!< Service ID NvM_Init(). */
#define NVM_SET_DATA_INDEX             NVM_SID_SETDATAINDEX             /*!< Service ID NvM_SetDataIndex(). */
#define NVM_GET_DATA_INDEX             NVM_SID_GETDATAINDEX             /*!< Service ID NvM_GetDataIndex(). */
#define NVM_SET_BLOCK_PROTECTION       NVM_SID_SETBLOCKPROTECTION       /*!< Service ID NvM_SetBlockProtection(). */
#define NVM_SET_BLOCK_LOCK_STATUS      NVM_SID_SETBLOCKLOCKSTATUS       /*!< Service ID NvM_SetBlockLockStatus(). */
#define NVM_GET_ERROR_STATUS           NVM_SID_GETERRORSTATUS           /*!< Service ID NvM_GetErrorStatus(). */
#define NVM_SET_RAM_BLOCK_STATUS       NVM_SID_SETRAMBLOCKSTATUS        /*!< Service ID NvM_SetRamBlockStatus(). */
#define NVM_MAINFUNCTION               NVM_SID_MAINFUNCTION             /*!< Service ID NvM_MainFunction(). */
#define NVM_GET_VERSION_INFO           NVM_SID_GETVERSIONINFO           /*!< Service ID NvM_GetVersionInfo(). */

#if (NVM_USE_ASR440_CALLBACK_INTERFACE == STD_ON)

/* Block Request type */
#ifndef Rte_TypeDef_NvM_BlockRequestType
typedef uint8 NvM_BlockRequestType;   /* type of a block request */
#endif

/* These BlockRequestTypes are important to an SW-C, as they can be passed to it in the
 * "single block job end notification" callback.
 * Therefore they are also defined by the RTE */
#ifndef NVM_READ_BLOCK
# define NVM_READ_BLOCK                 (0u) /* BlockRequest NvM_ReadBlock() */
#endif
#ifndef NVM_WRITE_BLOCK
# define NVM_WRITE_BLOCK                (1u) /* BlockRequest NvM_WriteBlock() */
#endif
#ifndef NVM_RESTORE_BLOCK_DEFAULTS
# define NVM_RESTORE_BLOCK_DEFAULTS     (2u) /* BlockRequest NvM_RestoreBlockDefaults() */
#endif
#ifndef NVM_ERASE_NV_BLOCK
# define NVM_ERASE_NV_BLOCK             (3u) /* BlockRequest NvM_EraseNvBlock() */
#endif
#ifndef NVM_INVALIDATE_NV_BLOCK
# define NVM_INVALIDATE_NV_BLOCK        (4u) /* BlockRequest NvM_InvalidateNvBlock() */
#endif
#ifndef NVM_READ_ALL_BLOCK
# define NVM_READ_ALL_BLOCK             (5u) /* BlockRequest NvM_ReadAll() for processed single block request */
#endif

/*
 * MultiBlock Request type
 * This is not an SWC type. Therefore check if already defined is not necessary.
 */
typedef uint8 NvM_MultiBlockRequestType;   /*!< Type of a multiblock request */

#define NVM_READ_ALL                   (0u) /* MultiBlock Request NvM_ReadAll() */
#define NVM_WRITE_ALL                  (1u) /* MultiBlock Request NvM_WriteAll() */
#define NVM_VALIDATE_ALL               (2u) /* MultiBlock Request NvM_ValidateAll() */
#define NVM_CANCEL_WRITE_ALL           (4u) /* MultiBlock Request NvM_CancelWriteAll() */
/* Extended because of MICROSAR functionality. */
/* Int values not continous in order to be able to react to changes in the AUTOSAR spec */
#define NVM_KILL_READ_ALL              (10u) /* MultiBlock Request NvM_KillReadAll() */
#define NVM_KILL_WRITE_ALL             (11u) /* MultiBlock Request NvM_KillWriteAll() */

#else

/* Service ID type */
#ifndef Rte_TypeDef_NvM_ServiceIdType
typedef uint8 NvM_ServiceIdType;   /*!< Type used to store a service identifier. */
#endif

/* Map the internal ServiceIds to user defined ServiceIds due to backward compatibility
 * to support callback interface prior AUTOSAR 4.4.0. */

/* These Service Ids are important to an SW-C, as they can be passed to it in the "single block job end notification"
 *  callback. Therefore they are also defined by the RTE. */

#ifndef NVM_READ_BLOCK
# define NVM_READ_BLOCK              NVM_SID_READBLOCK                   /*!< Service ID NvM_ReadBlock(). */
#endif
#ifndef NVM_WRITE_BLOCK
# define NVM_WRITE_BLOCK             NVM_SID_WRITEBLOCK                  /*!< Service ID NvM_WriteBlock(). */
#endif
#ifndef NVM_RESTORE_BLOCK_DEFAULTS
# define NVM_RESTORE_BLOCK_DEFAULTS  NVM_SID_RESTOREBLOCKDEFAULTS        /*!< Service ID NvM_RestoreBlockDefaults(). */
#endif
#ifndef NVM_ERASE_BLOCK
# define NVM_ERASE_BLOCK             NVM_SID_ERASENVBLOCK                /*!< Service ID NvM_EraseNvBlock(). */
#endif
#ifndef NVM_INVALIDATE_NV_BLOCK
# define NVM_INVALIDATE_NV_BLOCK     NVM_SID_INVALIDATENVBLOCK           /*!< Service ID NvM_InvalidateNvBlock(). */
#endif
#ifndef NVM_READ_ALL
# define NVM_READ_ALL                NVM_SID_READALL                     /*!< Service ID NvM_ReadAll(). */
#endif
#ifndef NVM_VALIDATE_ALL
# define NVM_VALIDATE_ALL            NVM_SID_VALIDATEALL                 /*!< Service ID NvM_ValidateAll(). */
#endif
#ifndef NVM_WRITE_ALL
# define NVM_WRITE_ALL               NVM_SID_WRITEALL                    /*!< Service ID NvM_WriteAll(). */
#endif
#ifndef NVM_CANCEL_WRITE_ALL
# define NVM_CANCEL_WRITE_ALL        NVM_SID_CANCELWRITEALL              /*!< Service ID NvM_CancelWriteAll(). */
#endif
#ifndef NVM_KILL_WRITE_ALL
# define NVM_KILL_WRITE_ALL          NVM_SID_KILLWRITEALL                /*!< Service ID NvM_KillWriteAll(). */
#endif
#ifndef NVM_KILL_READ_ALL
# define NVM_KILL_READ_ALL           NVM_SID_KILLREADALL                 /*!< Service ID NvM_KillReadAll(). */
#endif

#endif /* NVM_USE_ASR440_CALLBACK_INTERFACE */

/*!< Type used to store a block identifier. User as parameter for public APIs. */
#ifndef Rte_TypeDef_NvM_BlockIdType
typedef uint16 NvM_BlockIdType;
#endif

/*!< Type used to hold data information */
typedef uint8 NvM_DataType;

/*!< Type used to hold data information */
typedef P2VAR(NvM_DataType, AUTOMATIC, NVM_APPL_DATA) NvM_DataPtrType;

/*!< Type used to hold constant data information */
typedef P2CONST(NvM_DataType, AUTOMATIC, NVM_APPL_CONST) NvM_DataPtrToConstType;

/*!< Constant Pointer to data information */
typedef CONSTP2VAR(NvM_DataType, AUTOMATIC, NVM_APPL_CONST) NvM_DataConstPtrType;

/*!< Constant Pointer to data information */
typedef CONSTP2CONST(NvM_DataType, AUTOMATIC, NVM_APPL_CONST) NvM_DataConstPtrToConstType;

/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

/*!< Type used to address bitfields within structure definitions. */
typedef unsigned int NvM_BitfieldType;

#endif /* NVM_TYPES_H */

/***********************************************************************************************************************
 *  END OF FILE: NvM_Types.h
 **********************************************************************************************************************/
