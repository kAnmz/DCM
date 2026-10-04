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
/*!        \file  Fee_30_FlexNor_SlimInstance.h
 *        \brief  Slim instance interface
 *      \details  Provides the slim layout specific instance services.
 *         \unit  SlimInstance
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 **********************************************************************************************************************/

#if !defined(FEE_30_FLEXNOR_SLIMINSTANCE_H)
#    define FEE_30_FLEXNOR_SLIMINSTANCE_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#    include "Fee_30_FlexNor_Instance.h"
#    include "Fee_30_FlexNor_ConfigInterface.h"

#    if (FEE_30_FLEXNOR_SLIMLAYOUT_ENABLED == STD_ON) /* COV_MSR_UT_OPTIONAL_UNIT */

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
#        define FEE_30_FLEXNOR_START_SEC_CODE
#        include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimInstance_Init()
 *********************************************************************************************************************/
/*! \brief       Initialize the instance unit
 *  \details     -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimInstance_Init(void);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimInstance_GetTotalSize()
 *********************************************************************************************************************/
/*! \brief       Get the total size of the instance
 *  \details     Calculates the total aligned size of the instance in flash. This includes the size of the management 
 *               and payload data.
 *  \param[in]   instance               Pointer to the instance the size shall be calculated for. Must not be NULL.
 *  \return      The total size of the instance in bytes
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(uint32, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimInstance_GetTotalSize(Fee_30_FlexNor_ConstInstanceDataPtrType instance);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimInstance_Validate()
 *********************************************************************************************************************/
/*! \brief          Validates the given instance
 *  \details        Checks the validity of the given instance in flash at the location that is specified by the start address.
 *  \param[in,out]  instance               Pointer to the instance thats validity shall be checked for. Must not be NULL.
 *  \param[in]      resultCbk              The result call back that is called in case the service is complete. Must not be NULL.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    FALSE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimInstance_Validate(
    Fee_30_FlexNor_InstanceDataPtrType instance,
    Fee_30_FlexNor_ResultCallback resultCbk);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimInstance_ReadContent()
 *********************************************************************************************************************/
/*! \brief          Read the instance content
 *  \details        Read the content of the instance, i.e. the status and payload, from flash.
 *  \param[in,out]  instance               Pointer to the instance the payload and the status shall be read for. Must not be NULL.
 *  \param[in]      resultCbk              The result call back that is called in case the service is complete. Must not be NULL.
 *  \pre            The instance must be valid because the content is read without a blank check.
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    FALSE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimInstance_ReadContent(
    Fee_30_FlexNor_InstanceDataPtrType instance,
    Fee_30_FlexNor_ResultCallback resultCbk);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimInstance_Write()
 *********************************************************************************************************************/
/*! \brief       Writes the given instance to flash
 *  \details     Writes the instance to flash with the data and status set inside the given instance. As target address
 *               the start address that is set in the instance is used.
 *  \param[in]   instance               Pointer to the instance that shall be written to flash. Must not be NULL.
 *  \param[in]   resultCbk              The result call back that is called in case the service is complete. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous FALSE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimInstance_Write(
    Fee_30_FlexNor_ConstInstanceDataPtrType instance,
    Fee_30_FlexNor_ResultCallback resultCbk);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimInstance_Copy()
 *********************************************************************************************************************/
/*! \brief       Copies the status and the content of the given source instance to the target instance
 *  \details     -
 *  \param[in]   sourceInstance     Pointer to the source instance whose status and content shall be copied. Must not be NULL.
 *  \param[in]   targetInstance     Pointer to the target instance the given source instance shall be copied to. Must not be NULL.
 *  \param[in]   resultCbk          The result call back that is called in case the service is complete. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimInstance_Copy(
    Fee_30_FlexNor_ConstInstanceDataPtrType sourceInstance,
    Fee_30_FlexNor_InstanceDataPtrType targetInstance,
    Fee_30_FlexNor_ResultCallback resultCbk);

#        define FEE_30_FLEXNOR_STOP_SEC_CODE
#        include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#    endif

#endif /* FEE_30_FLEXNOR_SLIMINSTANCE_H */

/**********************************************************************************************************************
 *  END OF FILE: Fee_30_FlexNor_SlimInstance.h
 *********************************************************************************************************************/
