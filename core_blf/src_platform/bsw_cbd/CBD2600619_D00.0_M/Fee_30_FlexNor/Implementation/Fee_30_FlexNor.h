/**********************************************************************************************************************
 *  COPYRIGHT
 *  ------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2025 by Vector Informatik GmbH. All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  ------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/*!        \file  Fee_30_FlexNor.h
 *        \brief  Fee_30_FlexNor component header file
 *      \details  Header file of the Fee_30_FlexNor component interface.
 *         \unit  Fee
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  00.01.00  2020-04-02  virlra       -             Initial creation of FEE implementation.
 *                        virljs
 *  00.02.00  2020-04-24  virlra       -             Implementing instance units.
 *                        virljs
 *                        virjwa
 *  00.03.00  2020-06-17  virlra       -             Implementing chunk units.
 *                        virljs
 *  00.04.00  2020-08-04  virlra       -             Implementing sector unit.
 *                        virljs
 *                        virjwa
 *  00.05.00  2020-08-28  virlra       -             Implementing start, sector container and lookup table unit.
 *                        virjwa
 *  00.06.00  2020-10-26  virlra       -             Implementing chunk search.
 *  00.07.00  2020-12-01  virlra       MWDG-2840     Implementing basic read functionality.
 *  00.08.00  2020-12-21  virlra       MWDG-4419     Improve implementation.
 *                        virbka       MWDG-4681     Add chunk allocation service to sector unit.
 *                                     MWDG-2838     Add write behavior to FEE FlexNor.
 *                                     MWDG-4945     Add missing component services.
 *  00.09.00 2021-06-01   virlra       MWDG-5185     Fixing product validation findings.
 *  00.10.00 2021-08-02   virlra       MWDG-5562     Fixing issues found during component testing.
 *  00.11.00 2021-08-05   virlra       MWDG-5670     Fixing additional issues found during component testing.
 *  00.12.00 2021-09-29   virlra       MWDG-5487     Implementing job cancellation.
 *  01.00.00 2021-11-15   virlra       MWDG-6167     Prepare and execute beta release of Fee FlexNor.
 *  01.01.00 2021-12-17   virjwa       MWDG-5483     Prepare persisting of lookup table in flash for FEE FlexNor.
 *                                     MWDG-5485     Load persisted lookup table block from flash for FEE FlexNor.
 *  01.02.00 2022-03-17   virlra       MWDG-6739     Improve instance copy mechanism of Fee FlexNor.
 *                                     MWDG-6603     Reduce footprint of Fee FlexNor.
 *                                     MWDG-5697     Generate Fee_30_FlexNor_MemMap.h.
 *                                     MWDG-3866     Add bootloader support to FEE FlexNor.
 *  01.02.01 2022-08-18   virlra       MWDG-7263     Create derived test configurations for FEE FlexNor.
 *  02.00.00 2022-08-22   virlra       MWDG-6989     Add error handling to instance units.
 *                        virlra       MWDG-6987     Add error handling to chunk units.
 *                        virbka       MWDG-6983     Add error handling to sector metadata services.
 *                        virbka       MWDG-6985     Add error handling to sectors chunk management.
 *                        vircre       MWDG-6991     Make an own unit for copying blocks.
 *                        virbka       -             -
 *                        vircre       MWDG-6993     Add error handling to garbage collection.
 *                        vireno       MWDG-7370     Change static marker implementation in FEE FlexNor.
 *                        virlra       MWDG-6995     Create internal job processing unit.
 *                        vircre       -             -
 *                        vireno       MWDG-6997     Add recovery garbage collection to internal jobs.
 *                        virbka       MWDG-7041     Trigger recovery garbage collection when reallocation is requested for FEE FlexNor.
 *                        virlra       MWDG-7577     Fix cancel handling.
 *                        virbka       MWDG-7573     Internal Jobs handling: StartUp and failing jobs.
 *                        vireno       MWDG-7663     Fix sector scan implementation.
 *                        vireno       MWDG-7632     Fix lookup table link validation in FEE FlexNor.
 *                        virbka       MWDG-7621     Prepare and execute production release of FEE FlexNor.
 * 02.00.02 2022-03-16    virlra       MWDG-8099     ESCAN00114144: FlexNor does not read the latest block value.
 * 02.00.03 2022-04-23    virhdr       MWDG-8154     ESCAN00114362: Fee calls Fee_30_FlexNor_NvMJobEndNotification for
 *                                                   MEMIF_BLOCK_INVALID and MEMIF_BLOCK_INCONSISTENT
 *          2022-04-24    vireno       MWDG-8195     ESCAN00114461: Fee erase check of chunk link fails
 *          2023-04-25    vireno       MWDG-8188     ESCAN00114438: Fee writes in non empty memory
 * 02.00.04 2023-03-27    vireno       MWDG-8047     Fix findings of safety check concerning the silent analysis of Fee FlexNor.
 *          2023-05-08    vireno       MWDG-8165     ESCAN00114243: Fee reads erased memory - Sector
 * 02.01.00 2023-06-05    vireno       MWDG-7913     Fee FlexNor shall handle asynchronous cancel in lower layer (ASR 22-11)
 *          2023-07-12    vireno       MWDG-7887     Update Fee FlexNor to QAC 2022.2
 *          2023-07-13    virneo       MWDG-8468     ESCAN00114965: Compiler/Linker error: Variables are placed in the wrong memory section
 *          2023-07-14    vireno       MWDG-8493     ESCAN00115021: MainFunction gets stuck due to an endless loop
 * 03.00.00 2023-07-25    vireno       MWDG-7960     Fee FlexNor shall additionally support the MemAcc (ASR 22-11)
 * 03.01.00 2023-11-14    twagenpfeil  MEMSLP-8694   ESCAN00115451 Fee FlexNor writes into non empty memory due to wrong alignment calculation
 *          2023-11-29    twagenpfeil  MEMSLP-8097   ESCAN00115451 Check all interfaces contracts of the Fee FlexNors structural units
 *          2023-11-29    virhdr       MEMSLP-8813   ESCAN00115697: Fee writes non empty memory due to wrong next free address calculation
 *          2023-12-04    virhdr       MEMSLP-8937   ESCAN00115886: Compiler error due to missing define in Compiler_Cfg.inc
 *          2023-12-05    virhdr       MEMSLP-8633   ESCAN00115296: Compiler error: Fls.h: No such file or directory
 *          2023-12-06    twagenpfeil  MEMSLP-8881   Fee FlexNor gets stuck in a Persist Lookuptable job and stays pending until reset
 *          2023-12-14    twagenpfeil  MEMSLP-9060   Performe GC in case properties flip to valid
 *          2023-12-15    twagenpfeil  MEMSLP-8932   ESCAN00115939: Fix MemAcc Support Issues
 *          2023-12-16    twagenpfeil  MEMSLP-8743   Support AUTOSAR MemAcc
 *  main-37 2023-11-01    vireno       MEMSLP-8840   Change history is maintained in the global ChangeHistory.txt file starting with this release.
 *********************************************************************************************************************/

#if !defined (FEE_30_FLEXNOR_H)
# define FEE_30_FLEXNOR_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "Fee_30_FlexNor_Types.h"
# include "Fee_30_FlexNor_ConfigInterface.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/* Vendor and module identification */
# define FEE_30_FLEXNOR_VENDOR_ID                           (30u)
# define FEE_30_FLEXNOR_MODULE_ID                           (21u)

/* AUTOSAR Software specification version information */
# define FEE_30_FLEXNOR_AR_RELEASE_MAJOR_VERSION            (4u)
# define FEE_30_FLEXNOR_AR_RELEASE_MINOR_VERSION            (8u)
# define FEE_30_FLEXNOR_AR_RELEASE_REVISION_VERSION         (0u)

/* ----- Component version information (decimal version of ALM implementation package) ----- */
# define FEE_30_FLEXNOR_SW_MAJOR_VERSION                    (4u)
# define FEE_30_FLEXNOR_SW_MINOR_VERSION                    (4u)
# define FEE_30_FLEXNOR_SW_PATCH_VERSION                    (1u)

# define FEE_30_FLEXNOR_INSTANCE_ID_DET                     (0u)

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
# define FEE_30_FLEXNOR_START_SEC_CODE
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Fee_30_FlexNor_Init()
 *********************************************************************************************************************/
/*! \brief       Initialization function
 *  \details     Service to initialize the module Fee_30_FlexNor. It initializes all variables
 *               and sets the module state to initialized.
 *  \param[in]   ConfigPtr               Configuration structure for initializing the module. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Init(void);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SetMode()
 *********************************************************************************************************************/
/*! \brief       Dummy service for setting the mode. Only implemented for compatibility reasons.
 *  \details     This function implements no functionality and will ignore the Mode parameter.
 *  \param[in]   mode               Mode to set
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous FALSE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SetMode(MemIf_ModeType mode);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Read()
 *********************************************************************************************************************/
/*! \brief       Service to initiate a read job
 *  \details     -
 *  \param[in]   blockNumber        Unique identifier of block
 *  \param[in]   offset             Offset in the block
 *  \param[out]  dataBufferPtr      Pointer to buffer from upper layer
 *  \param[in]   length             Amount of bytes which should be read
 *  \return      E_OK       The job was accepted
 *               E_NOT_OK   The job was rejected
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Read(
    Fee_30_FlexNor_BlockNumberType blockNumber,
    Fee_30_FlexNor_BlockOffsetType offset,
    Fee_30_FlexNor_DataPtrType dataBufferPtr,
    uint16 length);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Write()
 *********************************************************************************************************************/
/*! \brief       Service to initiate a write job
 *  \details     -
 *  \param[in]   blockNumber        Unique identifier of block
 *  \param[in]  dataBufferPtr      Pointer to buffer from upper layer
 *  \return      E_OK       The job was accepted
 *               E_NOT_OK   The job was rejected
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Write(
    Fee_30_FlexNor_BlockNumberType blockNumber,
    Fee_30_FlexNor_ConstDataPtrType dataBufferPtr);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Cancel()
 *********************************************************************************************************************/
/*! \brief       Service to cancel the current job
 *  \details     -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Cancel(void);

/**********************************************************************************************************************
 * Fee_30_FlexNor_InvalidateBlock()
 *********************************************************************************************************************/
/*! \brief       Service to initiate an invalidation for the given block
 *  \details     -
 *  \param[in]   blockNumber    Unique identifier of block that shall be invalidated
 *  \return      E_OK           The job was accepted
 *               E_NOT_OK       The job was rejected
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_InvalidateBlock(Fee_30_FlexNor_BlockNumberType blockNumber);

/**********************************************************************************************************************
 * Fee_30_FlexNor_EraseImmediateBlock()
 *********************************************************************************************************************/
/*! \brief       Service to initiate an erase of immediate data block
 *  \details     The given block is erased by invalidating it.
 *  \param[in]   blockNumber    Unique identifier of block with immediate data that shall be erased
 *  \return      E_OK           The job was accepted
 *               E_NOT_OK       The job was rejected
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_EraseImmediateBlock(Fee_30_FlexNor_BlockNumberType blockNumber);

/**********************************************************************************************************************
 * Fee_30_FlexNor_GetStatus()
 *********************************************************************************************************************/
/*! \brief       Gets the current status of the module
 *  \details     -
 *  \return      Current module status
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(MemIf_StatusType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_GetStatus(void);

/**********************************************************************************************************************
 * Fee_30_FlexNor_GetJobResult()
 *********************************************************************************************************************/
/*! \brief       Gets the current job result of the module
 *  \details     -
 *  \return      Current module job result
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(MemIf_JobResultType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_GetJobResult(void);

/**********************************************************************************************************************
 * Fee_30_FlexNor_MainFunction()
 *********************************************************************************************************************/
/*! \brief       Function for asynchronous processing of the component
 *  \details     -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_MainFunction(void);

/**********************************************************************************************************************
 * Fee_30_FlexNor_PersistLookupTable()
 *********************************************************************************************************************/
/*! \brief       Service to initiate writing the content of the lookup table of the given partition to the flash.
 *  \details     This service is now automatically triggered and must not be executed manually. This API function 
 *               is only a dummy. This means that it has no functionality implemented. It is only available for 
 *               backward compatibility. 
 *  \param[in]   partitionId        Id of the partition, whose lookup table shall be persisted.
 *  \return      E_OK       The job was accepted
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_PersistLookupTable(Fee_30_FlexNor_PartitionIdType partitionId);


/**********************************************************************************************************************
 * Fee_30_FlexNor_SuspendRecoveryJobs()
 *********************************************************************************************************************/
/*! \brief       Service to suspend recovery job processing.
 *  \details     Only the sector recovery and chunk reallocation are suspended. 
 *               All other internal jobs are processed as usual (i.e. ReadSectorHeaders and GetLookupTable).
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SuspendRecoveryJobs(void);

/**********************************************************************************************************************
 * Fee_30_FlexNor_ResumeRecoveryJobs()
 *********************************************************************************************************************/
/*! \brief       Service to return to the normal job processing, where all internal jobs are performed.
 *  \details     -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_ResumeRecoveryJobs(void);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SuspendFlashWrites()
 *********************************************************************************************************************/
/*! \brief       This API blocks the Fee to request write/erase jobs from the lower layer.
 *  \details     -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SuspendFlashWrites(void);

/**********************************************************************************************************************
 * Fee_30_FlexNor_ResumeFlashWrites()
 *********************************************************************************************************************/
/*! \brief       It allows the Fee to request write/erase jobs from the lower layer.
 *  \details     -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_ResumeFlashWrites(void);

/**********************************************************************************************************************
 * Fee_30_FlexNor_GetEraseCycleCounter()
 *********************************************************************************************************************/
/*! \brief       Returns the maximal erase cycle counter of all sectors belonging to the provided partition
 *  \details     -
 *  \param[in]   partitionId           Id of the partition.
 *  \param[out]  eraseCycleCounter     Pointer to buffer from upper layer.
 *  \return      E_OK       The job was accepted
 *               E_NOT_OK   The job was rejected
 *  \pre         The provided partition must be already started up.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_GetEraseCycleCounter(
    Fee_30_FlexNor_PartitionIdType partitionId, 
    Fee_30_FlexNor_EraseCycleCounterType* eraseCycleCounter);

# if (FEE_30_FLEXNOR_VERSION_INFO_API == STD_ON)
/**********************************************************************************************************************
 *  Fee_30_FlexNor_GetVersionInfo()
 *********************************************************************************************************************/
/*! \brief       Returns the version information
 *  \details     Fee_30_FlexNor_GetVersionInfo() returns version information, vendor ID and AUTOSAR module ID of the component.
 *  \param[out]  Versioninfo             Pointer to where to store the version information. Parameter must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_GetVersionInfo(Fee_30_FlexNor_VersionInfoPtrType versioninfo);
# endif

# define FEE_30_FLEXNOR_STOP_SEC_CODE
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* FEE_30_FLEXNOR_H */

/**********************************************************************************************************************
 *  END OF FILE: Fee_30_FlexNor.h
 *********************************************************************************************************************/
