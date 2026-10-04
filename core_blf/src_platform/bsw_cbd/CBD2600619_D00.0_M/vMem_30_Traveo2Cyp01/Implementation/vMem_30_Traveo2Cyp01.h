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
/*!        \file  vMem_30_Traveo2Cyp01.h
 *        \brief  vMem_30_Traveo2Cyp01 header file
 *
 *      \details  This is the header file of the vMem_30_Traveo2Cyp01. It declares the interfaces of the vMem_30_
 *                Traveo2Cyp01.
 *         \unit  vMem__core
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version  Date        Author          Change Id                Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  0.05.00  2019-05-03  virskl          STORYC-8658              Initial creation.
 *  0.06.00  2019-08-08  virskl          STORYC-8871              Add RAM alignment.
 *  1.00.00  2019-09-18  virskl          STORYC-8873              Reach QM status.
 *                                       ESCAN00104361            BETA version - the BSW module is in BETA state.
 *                                       ESCAN00104124            Handling of unaligned data.
 *  2.00.00  2019-10-30  virskl          CTM-866                  Support Code Flash.
 *  2.00.01  2020-01-30  virskl          ESCAN00105511            Read service returns wrong job result.
 *                                       ESCAN00105512            Flash Safety registers handled incorrectly.
 *  2.01.00  2021-02-15  virskl          CTM-1495                 Support blank check for code flash.
 *                                       ESCAN00106100            Wrong status register definition.
 *  2.01.01  2021-07-22  virskl          ESCAN00109625            IsBlank API may return wrong result.
 *  2.02.00  2021-08-11  virrdl          CTM-3374                 Create config switch for WORK_ERR_SILENT and always
 *                                                                enable ECC for work flash.
 *  3.00.00  2021-09-22  fbatz           CTM-3471                 Update to new core version 3.00.00
 *  3.01.00  2022-05-24  jforstner       CTM-3649                 Update to latest vMem_core (3.02.00)
 *  3.02.00  2023-08-01  virepm          CTM-6253                 Support SetDualBankMode.
 *  3.02.00  2023-08-03  virepm          CTM-6244                 Support PerformMemorySwap.
 *  3.02.01  2024-03-15  virepm          MEMHLP-6704              Implemented DummyRead.
 *  3.03.00  2025-01-28  virepm          MEMHLP-7442              Issue Fix: ESCAN00119242: Missing volatile key word 
 *                                                                leads to exception
 *********************************************************************************************************************/

#if !defined (VMEM_30_TRAVEO2CYP01_H)
# define VMEM_30_TRAVEO2CYP01_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "vMem_30_Traveo2Cyp01_Cfg.h"
# include "vMem_30_Traveo2Cyp01_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/* ----- Component version information (decimal version of ALM implementation package) ----- */
# define VMEM_30_TRAVEO2CYP01_SW_MAJOR_VERSION                    (3u)
# define VMEM_30_TRAVEO2CYP01_SW_MINOR_VERSION                    (6u)
# define VMEM_30_TRAVEO2CYP01_SW_PATCH_VERSION                    (0u)

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

#define VMEM_30_TRAVEO2CYP01_START_SEC_HEADER_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Global API pointer table */
extern CONST(vMemAccM_vMemApiType, AUTOMATIC) vMem_30_Traveo2Cyp01_FunctionPointerTable;

#define VMEM_30_TRAVEO2CYP01_STOP_SEC_HEADER_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

# define VMEM_30_TRAVEO2CYP01_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  vMem_30_Traveo2Cyp01_GetVersionInfo()
 *********************************************************************************************************************/
/*! \brief       Returns the version information. This service is always available.
 *  \details     vMem_30_Traveo2Cyp01_GetVersionInfo() returns version information, vendor ID and AUTOSAR module ID of the component.
 *  \param[out]  versioninfo           Pointer to where to store the version information. Parameter must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \trace       CREQ-150071
 *********************************************************************************************************************/
FUNC(void, VMEM_30_TRAVEO2CYP01_CODE) vMem_30_Traveo2Cyp01_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, VMEM_30_TRAVEO2CYP01_APPL_VAR) VersionInfo);

# define VMEM_30_TRAVEO2CYP01_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */  /* MD_MSR_MemMap */

#endif /* VMEM_30_TRAVEO2CYP01_H */

/**********************************************************************************************************************
 *  END OF FILE: vMem_30_Traveo2Cyp01.h
 *********************************************************************************************************************/

