/**********************************************************************************************************************
 *  COPYRIGHT
 *  --------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2025 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  --------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/*!        \file  Fee_30_FlexNor_InstanceFactory.c
 *        \brief  Interface to create the generic instance.
 *      \details  Provides the implementation of an interface to create an instance.
 *         \unit  InstanceFactory
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#define FEE_30_FLEXNOR_INSTANCEFACTORY_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Fee_30_FlexNor_InstanceFactory.h"

#include "Fee_30_FlexNor_SecureInstance.h"
#include "Fee_30_FlexNor_SlimInstance.h"
#include "Fee_30_FlexNor_ConfigInterface.h"

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/
#if !defined(FEE_30_FLEXNOR_LOCAL) /* COV_FEE_30_FLEXNOR_COMPATIBILITY */
#    define FEE_30_FLEXNOR_LOCAL static
#endif

#if !defined(FEE_30_FLEXNOR_LOCAL_INLINE) /* COV_FEE_30_FLEXNOR_COMPATIBILITY */
#    define FEE_30_FLEXNOR_LOCAL_INLINE LOCAL_INLINE
#endif

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define FEE_30_FLEXNOR_START_SEC_CODE
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

#if (FEE_30_FLEXNOR_SECURELAYOUT_ENABLED == STD_ON) /* COV_MSR_UT_OPTIONAL_UNIT */
/**********************************************************************************************************************
 * Fee_30_FlexNor_InstanceFactory_CreateSecurePartOfInstance()
 *********************************************************************************************************************/
/*! \brief       Creates the part of the instance that is specific to the secure instance into the given pointer.
 *  \details     -
 *  \param[out]  instanceToCreate      Pointer to the structure the instance shall be created in. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FEE_30_FLEXNOR_LOCAL FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_InstanceFactory_CreateSecurePartOfInstance(
    Fee_30_FlexNor_InstancePtrType instanceToCreate);
#endif

#if (FEE_30_FLEXNOR_SLIMLAYOUT_ENABLED == STD_ON) /* COV_MSR_UT_OPTIONAL_UNIT */
/**********************************************************************************************************************
 * Fee_30_FlexNor_InstanceFactory_CreateSlimPartOfInstance()
 *********************************************************************************************************************/
/*! \brief       Creates the part of the instance that is specific to the slim instance into the given pointer.
 *  \details     -
 *  \param[out]  instanceToCreate      Pointer to the structure the instance shall be created in. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FEE_30_FLEXNOR_LOCAL FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_InstanceFactory_CreateSlimPartOfInstance(
    Fee_30_FlexNor_InstancePtrType instanceToCreate);
#endif

/**********************************************************************************************************************
 * Fee_30_FlexNor_InstanceFactory_CreateGeneralPartOfInstance()
 *********************************************************************************************************************/
/*! \brief       Creates the general part of the instance, i.e. the information that is independent from the layout.
 *  \details     -
 *  \param[in]   address               Address of the instance that shall be created
 *  \param[in]   partitionId           Id of the partition the instance belongs to
 *  \param[out]  instanceToCreate      Pointer to the structure the instance shall be created in.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FEE_30_FLEXNOR_LOCAL FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_InstanceFactory_CreateGeneralPartOfInstance(
    Fee_30_FlexNor_AddressType address,
    Fee_30_FlexNor_PartitionIdType partitionId,
    Fee_30_FlexNor_InstancePtrType instanceToCreate);

#if (FEE_30_FLEXNOR_SECURELAYOUT_ENABLED == STD_ON) /* COV_MSR_UT_OPTIONAL_UNIT */
/**********************************************************************************************************************
 * Fee_30_FlexNor_InstanceFactory_CreateSecurePartOfInstance()
 *********************************************************************************************************************/
/*! Internal comment removed.
 *
 *
 */
FEE_30_FLEXNOR_LOCAL FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_InstanceFactory_CreateSecurePartOfInstance(
    Fee_30_FlexNor_InstancePtrType instanceToCreate)
{
    instanceToCreate->Services.GetTotalSize = &Fee_30_FlexNor_SecureInstance_GetTotalSize; /* SBSW_Fee_30_FlexNor_Factory */
    instanceToCreate->Services.ReadContent  = &Fee_30_FlexNor_SecureInstance_ReadContent;  /* SBSW_Fee_30_FlexNor_Factory */
    instanceToCreate->Services.Validate     = &Fee_30_FlexNor_SecureInstance_Validate;     /* SBSW_Fee_30_FlexNor_Factory */
    instanceToCreate->Services.Write        = &Fee_30_FlexNor_SecureInstance_Write;        /* SBSW_Fee_30_FlexNor_Factory */
    instanceToCreate->Services.Copy         = &Fee_30_FlexNor_SecureInstance_Copy;         /* SBSW_Fee_30_FlexNor_Factory */
}
#endif

#if (FEE_30_FLEXNOR_SLIMLAYOUT_ENABLED == STD_ON) /* COV_MSR_UT_OPTIONAL_UNIT */
/**********************************************************************************************************************
 * Fee_30_FlexNor_InstanceFactory_CreateSlimPartOfInstance()
 *********************************************************************************************************************/
/*! Internal comment removed.
 *
 *
 */
FEE_30_FLEXNOR_LOCAL FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_InstanceFactory_CreateSlimPartOfInstance(
    Fee_30_FlexNor_InstancePtrType instanceToCreate)
{
    instanceToCreate->Services.GetTotalSize = &Fee_30_FlexNor_SlimInstance_GetTotalSize; /* SBSW_Fee_30_FlexNor_Factory */
    instanceToCreate->Services.ReadContent  = &Fee_30_FlexNor_SlimInstance_ReadContent;  /* SBSW_Fee_30_FlexNor_Factory */
    instanceToCreate->Services.Validate     = &Fee_30_FlexNor_SlimInstance_Validate;     /* SBSW_Fee_30_FlexNor_Factory */
    instanceToCreate->Services.Write        = &Fee_30_FlexNor_SlimInstance_Write;        /* SBSW_Fee_30_FlexNor_Factory */
    instanceToCreate->Services.Copy         = &Fee_30_FlexNor_SlimInstance_Copy;         /* SBSW_Fee_30_FlexNor_Factory */
}
#endif

/**********************************************************************************************************************
 * Fee_30_FlexNor_InstanceFactory_CreateGeneralPartOfInstance()
 *********************************************************************************************************************/
/*! Internal comment removed.
 *
 *
 */
FEE_30_FLEXNOR_LOCAL FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_InstanceFactory_CreateGeneralPartOfInstance(
    Fee_30_FlexNor_AddressType address,
    Fee_30_FlexNor_PartitionIdType partitionId,
    Fee_30_FlexNor_InstancePtrType instanceToCreate)
{
    instanceToCreate->Data.PartitionId  = partitionId;   /* SBSW_Fee_30_FlexNor_Factory */
    instanceToCreate->Data.StartAddress = address;       /* SBSW_Fee_30_FlexNor_Factory */
    instanceToCreate->Data.ReallocationRequired = FALSE; /* SBSW_Fee_30_FlexNor_Factory */
}

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * Fee_30_FlexNor_InstanceFactory_CreateInstance()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_InstanceFactory_CreateInstance(
    Fee_30_FlexNor_AddressType address,
    Fee_30_FlexNor_PartitionIdType partitionId,
    Fee_30_FlexNor_InstancePtrType instanceToCreate)
{
    Fee_30_FlexNor_InstanceFactory_CreateGeneralPartOfInstance(address, partitionId, instanceToCreate); /* SBSW_Fee_30_FlexNor_Factory */

#if ((FEE_30_FLEXNOR_SECURELAYOUT_ENABLED == STD_ON) && (FEE_30_FLEXNOR_SLIMLAYOUT_ENABLED == STD_ON)) /* COV_FEE_30_FLEXNOR_MULTIPLE_OPTIONAL_UNITS */
    if (Fee_30_FlexNor_ConfigInterface_GetPartitionLayout(partitionId) == FEE_30_FLEXNOR_SECURELAYOUT)
    {
#endif
#if (FEE_30_FLEXNOR_SECURELAYOUT_ENABLED == STD_ON) /* COV_MSR_UT_OPTIONAL_UNIT */
        Fee_30_FlexNor_InstanceFactory_CreateSecurePartOfInstance(instanceToCreate); /* SBSW_Fee_30_FlexNor_Factory */
#endif
#if ((FEE_30_FLEXNOR_SECURELAYOUT_ENABLED == STD_ON) && (FEE_30_FLEXNOR_SLIMLAYOUT_ENABLED == STD_ON)) /* COV_FEE_30_FLEXNOR_MULTIPLE_OPTIONAL_UNITS */
    }
    else
    {
#endif
#if (FEE_30_FLEXNOR_SLIMLAYOUT_ENABLED == STD_ON) /* COV_MSR_UT_OPTIONAL_UNIT */
        Fee_30_FlexNor_InstanceFactory_CreateSlimPartOfInstance(instanceToCreate); /* SBSW_Fee_30_FlexNor_Factory */
#endif
#if ((FEE_30_FLEXNOR_SECURELAYOUT_ENABLED == STD_ON) && (FEE_30_FLEXNOR_SLIMLAYOUT_ENABLED == STD_ON)) /* COV_FEE_30_FLEXNOR_MULTIPLE_OPTIONAL_UNITS */
    }
#endif
}

#define FEE_30_FLEXNOR_STOP_SEC_CODE
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: Fee_30_FlexNor_InstanceFactory.c
 *********************************************************************************************************************/
