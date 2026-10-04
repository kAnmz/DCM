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
/*!        \file  Fee_30_FlexNor_Startup.h
 *        \brief  Generic startup interface
 *      \details  Provides the startup definition and services.
 *         \unit  Startup
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 **********************************************************************************************************************/

#if !defined(FEE_30_FLEXNOR_STARTUP_H)
# define FEE_30_FLEXNOR_STARTUP_H

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
 * Fee_30_FlexNor_Startup_Init()
 *********************************************************************************************************************/
/*! \brief       Initialize the startup unit
 *  \details     -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Startup_Init(void);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Startup_ReadSectorHeaders()
 *********************************************************************************************************************/
/*! \brief         Reads and validates all the sector headers
 *  \details       -
 *  \param[in]     partitionId    Id of the partition whose sector headers shall be read.
 *  \param[in]     resultCbk      The result call back that is called in case the service is complete. Must not be NULL.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Startup_ReadSectorHeaders(Fee_30_FlexNor_PartitionIdType partitionId, 
    Fee_30_FlexNor_ResultCallback resultCbk);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Startup_GetLookupTable()
 *********************************************************************************************************************/
/*! \brief         Load lookup table from flash
 *  \details       Start lookup table recovery, if no valid lookup table is found in flash.
 *  \param[in]     partitionId    Id of the partition whos lookup table shall be recovered.
 *  \param[in]     resultCbk      The result call back that is called in case the service is complete. Must not be NULL.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Startup_GetLookupTable(Fee_30_FlexNor_PartitionIdType partitionId, 
    Fee_30_FlexNor_ResultCallback resultCbk);

# define FEE_30_FLEXNOR_STOP_SEC_CODE
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* FEE_30_FLEXNOR_STARTUP_H */

/**********************************************************************************************************************
 *  END OF FILE: Fee_30_FlexNor_Startup.h
 *********************************************************************************************************************/
