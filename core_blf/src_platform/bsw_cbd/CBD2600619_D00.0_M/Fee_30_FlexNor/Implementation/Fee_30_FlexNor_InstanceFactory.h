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
/*!        \file  Fee_30_FlexNor_InstanceFactory.h
 *        \brief  Interface to create the generic instance.
 *      \details  Provides an interface to create an instance.
 *         \unit  InstanceFactory
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 **********************************************************************************************************************/

#if !defined(FEE_30_FLEXNOR_INSTANCEFACTORY_H)
#    define FEE_30_FLEXNOR_INSTANCEFACTORY_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#    include "Fee_30_FlexNor_Instance.h"

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
#    define FEE_30_FLEXNOR_START_SEC_CODE
#    include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Fee_30_FlexNor_InstanceFactory_CreateInstance()
 *********************************************************************************************************************/
/*! \brief       Creates the correct instance according to the chosen FEE layout
 *  \details     Creates a structure that holds both data and functions of the created instance type (works like a c++ class).
 *  \param[in]   address               Address of the instance that shall be created
 *  \param[in]   partitionId           Id of the partition the instance belongs to
 *  \param[out]  instanceToCreate      Pointer to the structure the instance shall be created in.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_InstanceFactory_CreateInstance(
    Fee_30_FlexNor_AddressType address,
    Fee_30_FlexNor_PartitionIdType partitionId,
    Fee_30_FlexNor_InstancePtrType instanceToCreate);

#    define FEE_30_FLEXNOR_STOP_SEC_CODE
#    include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* FEE_30_FLEXNOR_INSTANCEFACTORY_H */

/**********************************************************************************************************************
 *  END OF FILE: Fee_30_FlexNor_InstanceFactory.h
 *********************************************************************************************************************/
