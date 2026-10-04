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
/*!        \file  NvM_MultiBlockProcessorFsm.h
 *        \brief  NvM multiblock processor FSM header file.
 *         \unit  NvM_MultiBlockProcessorFsm
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#if (!defined NVM_MULTIBLOCKPROCESSORFSM_H)
#define NVM_MULTIBLOCKPROCESSORFSM_H

/***********************************************************************************************************************
 * INCLUDES
 **********************************************************************************************************************/
#include "NvM_CfgDefines.h"

#if (NVM_MULTIPARTITION_USAGE_SCENARIO == STD_ON) /* COV_MSR_UT_OPTIONAL_UNIT */

#include "NvM_InternalTypes.h"

/***********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
# define NVM_START_SEC_CODE
# include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * NvM_MultiBlockProcessorFsm_Spawn()
 *********************************************************************************************************************/
/*! \brief           Spawn MultiBlockProcessorFsm on processing stack that is only responsible for this FSM.
 *  \details         -
 *  \param[in]       partitionId Partition identifier
 *  \pre             -
 *  \context         TASK
 *  \reentrant       FALSE
 *  \synchronous     TRUE
 *********************************************************************************************************************/
FUNC(void, NVM_PRIVATE_CODE) NvM_MultiBlockProcessorFsm_Spawn(NvM_PartitionIdType partitionId);

/**********************************************************************************************************************
 * NvM_MultiBlockProcessorFsm_GetActivePartitionId()
 *********************************************************************************************************************/
 /*!  \brief       Get currently processed partition ID
  *   \details     -
  *   \return      Active partitionID.
  *   \pre         -
  *   \context     TASK
  *   \reentrant   FALSE
  *   \synchronous TRUE
  *********************************************************************************************************************/
FUNC(NvM_PartitionIdType, NVM_PRIVATE_CODE) NvM_MultiBlockProcessorFsm_GetActivePartitionId(void);

# define NVM_STOP_SEC_CODE
# include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* NVM_MULTIPARTITION_USAGE_SCENARIO */

#endif  /* NVM_MULTIBLOCKPROCESSORFSM_H */

/***********************************************************************************************************************
 *  END OF FILE: NvM_MultiBlockProcessorFsm.h
 **********************************************************************************************************************/
