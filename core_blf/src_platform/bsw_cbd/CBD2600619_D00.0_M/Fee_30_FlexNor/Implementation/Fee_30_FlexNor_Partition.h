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
/*!        \file  Fee_30_FlexNor_Partition.h
 *        \brief  Partition interface
 *      \details  Provides the interface to the partition services that implement the high level data mangement.
 *         \unit  Partition
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 **********************************************************************************************************************/

#if !defined (FEE_30_FLEXNOR_PARTITION_H)
# define FEE_30_FLEXNOR_PARTITION_H

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

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
# define FEE_30_FLEXNOR_START_SEC_CODE
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_Init()
 *********************************************************************************************************************/
/*! \brief         Initialize the partition unit
 *  \details       -
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_Init(void);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_IsStartedUp()
 *********************************************************************************************************************/
/*! \brief       Checks whether the given partition is already started up
 *  \details     -
 *  \param[in]   partitionId        Id of the partition that shall be checked.
 *  \pre         -
 *  \return      TRUE   If the given partition was already started up
 *               FALSE  Otherwise
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(boolean, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_IsStartedUp(Fee_30_FlexNor_PartitionIdType partitionId);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_StartUp()
 *********************************************************************************************************************/
/*! \brief       Startup the given partition.
 *  \details     -
 *  \param[in]   partitionId      Id of the partition that shall be started up.
 *  \param[in]   resultCbk        The result callback that is called in case the service is complete. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_StartUp(Fee_30_FlexNor_PartitionIdType partitionId,
                                                                 Fee_30_FlexNor_ResultCallback resultCbk);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_ReadBlock()
 *********************************************************************************************************************/
/*! \brief         Read the most recently stored data for the given block from memory
 *  \details       -
 *  \param[in,out] currentJob    Contains the job parameters
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_ReadBlock(Fee_30_FlexNor_JobPtrType currentJob);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_WriteBlock()
 *********************************************************************************************************************/
/*! \brief         Write the given data for a block into memory
 *  \details       -
 *  \param[in,out] currentJob  Contains the job parameters
 * 
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_WriteBlock(Fee_30_FlexNor_JobPtrType currentJob);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_ResetStartup()
 *********************************************************************************************************************/
/*! \brief       Resets the startup state of the given partition to not started up.
 *  \details     -
 *  \param[in]   partitionId        Id of the partition of which the startup shall be reset.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_ResetStartup(Fee_30_FlexNor_PartitionIdType partitionId);

# define FEE_30_FLEXNOR_STOP_SEC_CODE
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* FEE_30_FLEXNOR_PARTITION_H */

/**********************************************************************************************************************
 *  END OF FILE: Fee_30_FlexNor_Partition.h
 *********************************************************************************************************************/
