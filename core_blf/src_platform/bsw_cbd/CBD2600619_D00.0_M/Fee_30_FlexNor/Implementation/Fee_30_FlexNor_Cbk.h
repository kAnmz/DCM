/***********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2025 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!        \file  Fee_30_FlexNor_Cbk.h
 *        \brief  Provides the callback definitions for notification
 *         \unit  Fee
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 * 
 *  FILE VERSION
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the VERSION CHECK below.
 **********************************************************************************************************************/

#if !defined (FEE_30_FLEXNOR_CBK_H)
# define FEE_30_FLEXNOR_CBK_H

/***********************************************************************************************************************
 * INCLUDES
 **********************************************************************************************************************/
#include "Fee_30_FlexNor_Cfg.h"

#if (FEE_30_FLEXNOR_MEMORY_VARIANT == FEE_30_FLEXNOR_MEMORY_VARIANT_MEMACC)
# include "MemAcc.h"
#endif

/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/
# define FEE_30_FLEXNOR_START_SEC_CODE
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Fee_30_FlexNor_JobErrorNotification
 *********************************************************************************************************************/
/*! \brief       Called by Flash driver for reporting an error in job processing
 *  \details     -
 *  \pre         Module is initialized
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_JobErrorNotification(void);

/**********************************************************************************************************************
 * Fee_30_FlexNor_JobEndNotification
 *********************************************************************************************************************/
/*! \brief       Called by Flash driver for reporting a successful job processing
 *  \details     -
 *  \pre         Module is initialized
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_JobEndNotification(void);

#if (FEE_30_FLEXNOR_MEMORY_VARIANT == FEE_30_FLEXNOR_MEMORY_VARIANT_MEMACC)
/**********************************************************************************************************************
 * Fee_30_FlexNor_AddressAreaJobEndNotification
 *********************************************************************************************************************/
/*! \brief       Called by MemAcc for reporting that the requested job has finished. 
 *  \details     -
 *  \param[in]   addressAreaId         Id of the Fees AddressArea.
 *  \param[in]   jobResult             Result of the finished job.
 *  \pre         Module is initialized
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_AddressAreaJobEndNotification (
    MemAcc_AddressAreaIdType addressAreaId,
    MemAcc_JobResultType jobResult
);
#endif /* FEE_30_FLEXNOR_MEMORY_VARIANT == FEE_30_FLEXNOR_MEMORY_VARIANT_MEMACC */

# define FEE_30_FLEXNOR_STOP_SEC_CODE
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif  /* FEE_30_FLEXNOR_CBK_H */

/***********************************************************************************************************************
 *  END OF FILE: Fee_30_FlexNor_Cbk.h
 **********************************************************************************************************************/
