/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                 This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                 Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                 All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  LICENSE
 *  -------------------------------------------------------------------------------------------------------------------
 *            Module: NvM
 *           Program: MSR_Geely_SLP2
 *          Customer: Marelli Automotive Electronics (Guangzhou) Co., Ltd
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: CYT2B75BA
 *    License Scope : The usage is restricted to CBD2600619_D00
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: NvM_PrivateCfg.h
 *   Generation Time: 2026-06-11 12:02:22
 *           Project: DaVinci_Zeekr_Display - Version 1.0
 *          Delivery: CBD2600619_D00
 *      Tool Version: DaVinci Configurator Classic (beta) 5.31.55 SP5
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 ! BETA VERSION                                                                                                       !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 ! This version of DaVinci Configurator Classic and/or the related Basic Software Package is BETA software.               !
 ! BETA Software is basically operable, but not sufficiently tested, verified and/or qualified for use in series      !
 ! production and/or in vehicles operating on public or non-public roads.                                             !
 ! In particular, without limitation, BETA Software may cause unpredictable ECU behavior, may not provide all         !
 ! functions necessary for use in series production and/or may not comply with quality requirements which are         !
 ! necessary according to the state of the art. BETA Software must not be used in series production.                  !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
**********************************************************************************************************************/


/* ---- private section of configuration ---------------------------------- */
/* ---- used as interface to all submodules of the NvM -------------------- */

/**********************************************************************************************************************
 * PROTECTION AGAINST MULTIPLE INCLUSION
 *********************************************************************************************************************/
#if (!defined NVM_PRIVATE_CFG_H)
# define NVM_PRIVATE_CFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "nvmm_config.h" /* Generated include (NvmCfgCbkIncludeList) */
/* #include "EcuM_Cbk.h" */ /* Generated include (NvmCfgCbkIncludeList) */
/* #include "BswInit.h" */ /* Generated include (NvmCfgCbkIncludeList) */
/* #include "Dem_Cbk.h" */ /* Generated include (NvmCfgCbkIncludeList) */
#include "wdfs_config_dynamic.h" /* Generated include (NvmCfgCbkIncludeList) */


/* #include "Det.h" */ /* Development Error Detect is enabled */
/* #include "BswM.h" */ /* NvMBswMMultiBlockJobStatusInformation is enabled */

/**********************************************************************************************************************
  GLOBAL CONSTANT MACROS
**********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/

#define NvM_InvokeCurrentJobMode(request, jobResult) /* (BswM_NvM_CurrentJobMode(request, jobResult)) */
#define NvM_DemSetEventStatusIntegrityFailed() 
#define NvM_DemSetEventStatusLossOfRedundancy() 
#define NvM_DemSetEventStatusReqFailed() 


/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/


/* ---- end private configuration section --------------------------------- */
#endif /* NVM_PRIVATE_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: NvM_PrivateCfg.h
 *********************************************************************************************************************/

