/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2025 by Vector Informatik GmbH.                                             All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  _MemMap.h
 *    Component:  -
 *       Module:  -
 *    Generator:  -
 *
 *  Description:  This File is a template for the MemMap.h
 *                This file has to be extended with the memory section defined for all BSW modules
 *                which are used.
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  MISRA VIOLATIONS
 *  -------------------------------------------------------------------------------------------------------------------
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  -------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id      Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  01.00.00  2007-08-01  Jk                     Initial creation
 *  01.01.00  2007-12-14  Jk                     Component specific defines filtering added
 *  01.01.02  2008-11-04  Jk                     Component specific defines filtering added
 *  01.01.03  2008-12-17  Ht                     Improve list of components  (Tp_AsrTpCan,Tp_AsrTpFr,DrvMcu,DrvIcu added)
 *  01.01.04  2009-04-27  Ht                     improve list of components  (Cp_XcpOnCanAsr, Il_AsrIpduM, If_VxFblDcm,
 *                                               If_VxFblVpm_Volvo_ab, DrvFls added)
 *  01.01.05  2009-04-24  Msr                    Renamed J1939_AsrBase as TpJ1939_AsrBase
 *  01.01.06  2009-06-03  Ht                     Improve list of components (Adc, Dio, Gpt, Pwm, Spi, Wdg, Fls, Port, Fim)
 *  01.02.00  2009-08-01  Ht                     Improve list of components (Fee_30_Inst2, Can, ...Sub)
 *                                               Support filtering for RTE
 *  01.02.01  2009-08-18  HH                     replaced C++ comment by C comment
 *  01.02.02  2009-09-02  Lo                     add external Flash driver support
 *  01.02.03  2009-09-12  Lo                     add DrvFls_Mcs12xFslftm01ExtVx
 *                        Ht                     Improve list of components (CanTrcv_30_Tja1040dio,
 *                                                 Eth, EthTrcv, EthIf, SoAd, TcpIp, EthSM)
 *  01.03.00  2009-10-30  Ht                     support R8: change EthTrcv to EthTrcv_30_Canoeemu
 *                                               support EthTrcv_30_Dp83848
 *                                               change CanTrcv_30_Xdio to CanTrcv_30___Your_Trcv__
 *                                               change CanTrcv_30_Tja1040dio to CanTrcv_30_Tja1041
 *                                               change name FrTrcv to FrTrcv_30_Tja1080dio
 *                        Lo                     add Cp_AsrXcp
 *                        Ht                     add Cp_XcpOnFrAsr
 *  01.03.01  2010-01-13  Ht                     support SysService_AsrCal
 *  01.03.02  2010-02-15  Ht                     support SysService_SswRcs_Daimler, SysService_Tls, Tp_Http,
 *                                                       SysService_Dns, SysService_Json, DrvTrans_GenericLindioAsr
 *                        Lo                     add Diag_AsrDem for all OEMs
 *                                               rename internal variables and filter methods
 *  01.04.00  2010-03-04  Ht                     change name FrTrcv_30_Tja1080dio to FrTrcv_30_Tja1080
 *  01.04.01  2010-03-10  Ht                     support DrvTrans_GenericFrAsr, DrvTrans_As8223FrspiAsr, DrvEep and If_AsrIfEa
 *  01.04.02  2010-04-07  Lo                     change IfFee to real components and add If_AsrIfWdV85xNec01Sub
 *  01.04.03  2010-06-11  Ht                     add CanTrcv_30_Tja1043
 *                        Lo                     add Il_AsrIpduMEbBmwSub
 *  01.04.04  2010-08-24  Ht                     add CanTrcv_30_Tle62512G, DrvEep_XAt25128EAsr, Tp_AsrTpFrEbBmwSub
 *  01.05.00  2010-08-24  Ht                     support R10:
 *                                               change LinTrcv_30_Tle7259dio to LinTrcv_30_Tle7259
 *  01.05.01  2010-10-14  Ht                     add VStdLib, SysService_SswScc, SysService_IpBase, SysService_Crypto
 *  01.05.02  2010-10-20  Ht                     support comments for Package Merge Tool
 *  01.05.03  2010-11-03  Ht                     add SysService_E2eLibTttechSub, SysService_E2ePwTttechSub
 *  01.05.04  2010-11-16  Ht                     add SysService_Exi, DrvTrans_Int6400EthAsr, Cdd_AsrCdd_Fiat, Diag_AsrDem_Fiat
 *  01.05.05  2010-12-17  Ht                     add SysService_AsrSchM, DrvEep_XXStubAsr, DrvIcu_Tms570Tinhet01ExtVx
 *                                                   DrvWd_XTle4278gEAsr, DrvWd_XXStubAsr
 *  01.05.06  2011-02-17  Ht                     add DrvEed, SysService_AsrBswM
 *  01.05.07  2011-03-04  Ht                     add DrvTrans_Tja1055CandioAsr
 *                                               rename CanTrcv_30_Tja1040dio to CanTrcv_30_Tja1040
 *                                               add SysService_XmlEngine
 *  01.06.00  2011-03-15  Ht                     support ASR4.0
 *                                               add Ccl_Asr4ComM, Ccl_Asr4SmCan, Nm_Asr4NmIf, Nm_AsrNmDirOsek
 *  01.06.01  2011-04-15  Ht                     add Diag_AsrDcm_<OEM>
 *  01.06.02  2011-06-17  Ht                     correct Diag_AsrDcm_<OEM>
 *                                               add Monitoring_AsrDlt and Monitoring_GenericMeasurement
 *  01.06.03  2011-09-20  Ht                     add DrvTrans_Tja1145CanSpiAsr, DrvTrans_E52013CanspiAsr, DrvFls_XXStubAsr,
 *                                               If_AsrIfFeeV85xNec05Sub, If_AsrIfFeeV85xNec06Sub, If_AsrIfFeeV85xNec07Sub
 *                                               SysService_AsrWdMTttechSub and If_AsrIfWdTttechSub
 *  01.06.04  2011-11-22  Ht                     add If_AsrIfFeeTiSub,
 *                                               ESCAN00054718: add Cdd_AsrCdd
 *  01.06.05  2011-12-09  Ht                     add Tp_IpV4, Tp_IpV6
 *  01.06.06  2011-12-14  Ht                     add Monitoring_RuntimeMeasurement
 *  01.06.07  2012-01-03  Ht                     add DrvI2c, SysService_Asr4BswM
 *  01.06.08  2012-01-31  Ht                     add DrvTrans_Ar7000EthAsr, DrvTrans_GenericEthmiiAsr
 *  01.06.09  2012-03-06  Ht                     add If_AsrIfFeeMb9df126Fuji01Sub,
 *                                               Infineon_Tc1767Inf01Sub, Infineon_Tc178xInf01Sub, Infineon_Tc1797Inf01Sub, Infineon_Tc1797Inf02Sub
 *  01.06.10  2012-03-13  Ht                     add Gw_AsrPduRCfg5, Il_AsrComCfg5, Il_AsrIpduMCfg5, Cdd_AsrCddCfg5,
 *                                               Tp_Asr4TpCan, Diag_Asr4Dcm, Diag_Asr4Dem
 *  01.06.11  2012-03-20  Ht                     add Cp_AsrCcp, Cp_XcpOnTcpIpAsr
 *  01.07.00  2012-07-26  Ht                     ESCAN00059365: [AUTOSAR4, compiler warning]: Wrong define name in #undef statement causes re-definition warning
 *                                               add Nm_Asr4NmCan, Nm_Asr4NmFr, Infineon_Xc2000Inf01Sub, Ccl_Asr4ComMCfg5, SysService_Asr4BswMCfg5, SysService_Asr4EcuM, SysService_AsrRamTst,
 *                                                   Ccl_Asr4SmLin
 *            2012-09-04  Ht                     add support for ASR specification 4.0 R3
 *  01.07.01  2012-10-23  Seu                    add SysService_XmlSecurity
 *  01.07.02  2013-01-10  Seu                    MISRA deviation comments added
 *  01.08.00  2013-03-01  Seu     ESCAN00065501  AR4-325: Add support for Post-build RAM memory section
 *            2013-04-12  Seu     ESCAN00066614  Add the deviation for violation of MISRA rule 19.6
 *  01.09.00  2013-12-10  Seu     ESCAN00072537  Add *_NOCACHE_* memory sections for variables
 *            2013-12-16  Seu                    MISRA compliance: usage of character "'" removed, typos corrected
 *  01.10.00  2016-09-27  Seu                    FEATC-317: FEAT-2002: CommonAsr__Common: Support 64 Bit Signal Types for COM according to ASR 4.2.2
 *  01.11.00  2017-07-05  Seu     ESCAN00095756  FEAT-2455: Support ASR4.2 compatible MemMap for MCALs
 *            2017-08-01  Seu     ESCAN00096129  MEMMAP_SW_MINOR_VERSION / MEM_SW_MINOR_VERSION is not correct
 *  01.12.00  2018-10-17  visdfe  ESCAN00095695  Add support for Os_CoreGen7 within _MemMap.h (Include of Os_MemMap.h)
 *                                TASK-78775     Change MemMap_Common.h to Template
 *  01.13.00  2021-05-06  virmfr  HALBE-3985     CommonAsr_MemMap shall include Common_MemMap generated compatibility header
 *  02.00.00  2021-06-09  visto   HALBE-4594     Create a branch for >=R27 Features
 *  02.01.00  2021-08-25  virmfr  HALBE-4526     MemMap_Common.h removed
 *  02.01.01  2021-09-07  virmfr  HALBE-5304     MemMapIncludesList removed
 *  02.02.00  2022-08-18  virmfr  HALBE-7504     Interchange include order of MemMap_Common.h and MemMap_Compatibility.h
 *            2022-08-18  virmfr                 ASR3 defines removed
 *  02.02.01  2022-08-26  virmfr                 Correction of small non-functional findings
 *  03.00.00  2024-11-05  virjas  OSHAL-1936     Adaption for new ASR Mem module
 *  03.01.00  2025-10-13  virjas  OSHAL-3696     Adaption for changed infrastructure (veHub)
 *********************************************************************************************************************/

/* PRQA S 0841 MEMMAP_0841_TAG */ /* MD_MSR_19.6 */

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

 /* PRQA S 0883 1 */ /* MD_MemMap_19.15 */
#undef MEMMAP_VENDOR_ID /* PRQA S 0841 */ /* MD_MSR_19.6 */

#define MEMMAP_VENDOR_ID        (30u)

/* AUTOSAR Software Specification Version Information */
#undef MEMMAP_AR_RELEASE_MAJOR_VERSION /* PRQA S 0841 */ /* MD_MSR_19.6 */
#undef MEMMAP_AR_RELEASE_MINOR_VERSION /* PRQA S 0841 */ /* MD_MSR_19.6 */
#undef MEMMAP_AR_RELEASE_REVISION_VERSION /* PRQA S 0841 */ /* MD_MSR_19.6 */

/* AUTOSAR release 4.0 R3 */
#define MEMMAP_AR_RELEASE_MAJOR_VERSION       (4u)
#define MEMMAP_AR_RELEASE_MINOR_VERSION       (0u)
#define MEMMAP_AR_RELEASE_REVISION_VERSION    (3u)

#undef MEMMAP_SW_MAJOR_VERSION /* PRQA S 0841 */ /* MD_MSR_19.6 */
#undef MEMMAP_SW_MINOR_VERSION /* PRQA S 0841 */ /* MD_MSR_19.6 */
#undef MEMMAP_SW_PATCH_VERSION /* PRQA S 0841 */ /* MD_MSR_19.6 */

#define MEMMAP_SW_MAJOR_VERSION     (3u)
#define MEMMAP_SW_MINOR_VERSION     (1u)
#define MEMMAP_SW_PATCH_VERSION     (0u)

#define MEMMAP_ERROR

/* Package Merger: Start Section MemMapModuleList */



/***********************************************************************************************************************
 *  LINSM START
 **********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef LINSM_START_SEC_CODE
# undef LINSM_START_SEC_CODE
# define START_SEC_CODE
#endif
#ifdef LINSM_STOP_SEC_CODE
# undef LINSM_STOP_SEC_CODE
# define STOP_SEC_CODE
#endif

/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef LINSM_START_SEC_CONST_8BIT
# undef LINSM_START_SEC_CONST_8BIT
# define START_SEC_CONST_8BIT
#endif
#ifdef LINSM_STOP_SEC_CONST_8BIT
# undef LINSM_STOP_SEC_CONST_8BIT
# define STOP_SEC_CONST
#endif

#ifdef LINSM_START_SEC_CONST_UNSPECIFIED
# undef LINSM_START_SEC_CONST_UNSPECIFIED
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef LINSM_STOP_SEC_CONST_UNSPECIFIED
# undef LINSM_STOP_SEC_CONST_UNSPECIFIED
# define STOP_SEC_CONST
#endif


/* Postbuild CFG CONST sections */

#ifdef LINSM_START_SEC_PBCFG
# undef LINSM_START_SEC_PBCFG
# define START_SEC_CONST_PBCFG
#endif
#ifdef LINSM_STOP_SEC_PBCFG
# undef LINSM_STOP_SEC_PBCFG
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR NOINIT sections */

#ifdef LINSM_START_SEC_VAR_NOINIT_8BIT
# undef LINSM_START_SEC_VAR_NOINIT_8BIT
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef LINSM_STOP_SEC_VAR_NOINIT_8BIT
# undef LINSM_STOP_SEC_VAR_NOINIT_8BIT
# define STOP_SEC_VAR
#endif

#ifdef LINSM_START_SEC_VAR_NOINIT_16BIT
# undef LINSM_START_SEC_VAR_NOINIT_16BIT
# define START_SEC_VAR_NOINIT_16BIT
#endif
#ifdef LINSM_STOP_SEC_VAR_NOINIT_16BIT
# undef LINSM_STOP_SEC_VAR_NOINIT_16BIT
# define STOP_SEC_VAR
#endif

#ifdef LINSM_START_SEC_VAR_NOINIT_32BIT
# undef LINSM_START_SEC_VAR_NOINIT_32BIT
# define START_SEC_VAR_NOINIT_32BIT
#endif
#ifdef LINSM_STOP_SEC_VAR_NOINIT_32BIT
# undef LINSM_STOP_SEC_VAR_NOINIT_32BIT
# define STOP_SEC_VAR
#endif

#ifdef LINSM_START_SEC_VAR_NOINIT_64BIT
# undef LINSM_START_SEC_VAR_NOINIT_64BIT
# define START_SEC_VAR_NOINIT_64BIT
#endif
#ifdef LINSM_STOP_SEC_VAR_NOINIT_64BIT
# undef LINSM_STOP_SEC_VAR_NOINIT_64BIT
# define STOP_SEC_VAR
#endif

#ifdef LINSM_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef LINSM_START_SEC_VAR_NOINIT_UNSPECIFIED
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef LINSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef LINSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif


/* VAR ZERO INIT sections */

#ifdef LINSM_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef LINSM_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#ifdef LINSM_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef LINSM_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

#ifdef LINSM_START_SEC_VAR_ZERO_INIT_8BIT
# undef LINSM_START_SEC_VAR_ZERO_INIT_8BIT
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#ifdef LINSM_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef LINSM_STOP_SEC_VAR_ZERO_INIT_8BIT
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  LINSM END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  FLS_30_VMEMACCM START
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#if defined(FLS_30_VMEMACCM_START_SEC_CODE)
# undef FLS_30_VMEMACCM_START_SEC_CODE      /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE         /* mapped to default code section */
#endif
#if defined(FLS_30_VMEMACCM_STOP_SEC_CODE)
# undef FLS_30_VMEMACCM_STOP_SEC_CODE       /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE          /* default code stop section */
#endif

/*******  CONST sections  ********************************************************************************************/

/* CONST sections */
#ifdef FLS_30_VMEMACCM_START_SEC_CONST_UNSPECIFIED
# undef FLS_30_VMEMACCM_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef FLS_30_VMEMACCM_STOP_SEC_CONST_UNSPECIFIED
# undef FLS_30_VMEMACCM_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/


#ifdef FLS_30_VMEMACCM_START_SEC_VAR_NO_INIT_RAM_BUFFER
/* Non-standard MemMap section for internal write buffer, which will be forwarded to the vMemAccM if RAM alignment
 * feature is enabled. Depending on hardware restrictions, this buffer might have to be aligned to prevent unaligned
 * memory access exceptions. */
# undef FLS_30_VMEMACCM_START_SEC_VAR_NO_INIT_RAM_BUFFER /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NO_INIT_64 
#endif
#ifdef FLS_30_VMEMACCM_STOP_SEC_VAR_NO_INIT_RAM_BUFFER
# undef FLS_30_VMEMACCM_STOP_SEC_VAR_NO_INIT_RAM_BUFFER /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef FLS_30_VMEMACCM_START_SEC_VAR_INIT_UNSPECIFIED
# undef FLS_30_VMEMACCM_START_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#ifdef FLS_30_VMEMACCM_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef FLS_30_VMEMACCM_STOP_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(FLS_30_VMEMACCM_START_SEC_VAR_NOINIT_UNSPECIFIED)
# undef FLS_30_VMEMACCM_START_SEC_VAR_NOINIT_UNSPECIFIED      /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_UNSPECIFIED        /* mapped to default variable section */
#endif
#if defined(FLS_30_VMEMACCM_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
# undef FLS_30_VMEMACCM_STOP_SEC_VAR_NOINIT_UNSPECIFIED       /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR          /* default variable stop section */
#endif
/**********************************************************************************************************************
 *  FLS_30_VMEMACCM END
 *********************************************************************************************************************/

/***********************************************************************************************************************
 *  COPYRIGHT
 *  --------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2023 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  --------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/**        \file  Lin_MemMap.inc
 *        \brief  AUTOSAR LIN Driver
 *
 *      \details  AUTOSAR LIN Driver for all target systems
 *
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  LIN START
 **********************************************************************************************************************/

/*******  CODE sections ***********************************************************************************************/
/* PRQA S 0883 514 */ /* MD_LIN_TESTSUITE_WORKAROUND */
#if defined(LIN_START_SEC_CODE)
# undef LIN_START_SEC_CODE      /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE                                               /* mapped to default code section */
#endif
#if defined(LIN_STOP_SEC_CODE)
# undef LIN_STOP_SEC_CODE       /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE                                                /* default code stop section */
#endif

#if defined(LIN_START_SEC_CODE_FAST)
# undef LIN_START_SEC_CODE_FAST /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE_FAST                                          /* mapped to default fast code section */
#endif
#if defined(LIN_STOP_SEC_CODE_FAST)
# undef LIN_STOP_SEC_CODE_FAST  /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE                                                /* default code stop section */
#endif

#if defined(LIN_START_SEC_CODE_ISR)
# undef LIN_START_SEC_CODE_ISR  /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE_ISR                                           /* mapped to default ISR code section */
#endif
#if defined(LIN_STOP_SEC_CODE_ISR)
# undef LIN_STOP_SEC_CODE_ISR   /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE                                                /* default code stop section */
#endif

#ifdef LIN_START_SEC_CODE_APPL
# undef LIN_START_SEC_CODE_APPL /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE                                               /* mapped to default code section */
#endif
#ifdef LIN_STOP_SEC_CODE_APPL
# undef LIN_STOP_SEC_CODE_APPL /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE                                                /* default code stop section */
#endif


/*******  CONST sections  *********************************************************************************************/

/* CONST sections */

#if defined(LIN_START_SEC_CONST_8BIT)
# undef LIN_START_SEC_CONST_8BIT  /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_8BIT                                         /* mapped to default const 8bit section */
#endif
#if defined(LIN_STOP_SEC_CONST_8BIT)
# undef LIN_STOP_SEC_CONST_8BIT   /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST                                               /* default const stop section */
#endif

#if defined(LIN_START_SEC_CONST_16BIT)
# undef LIN_START_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_16BIT
#endif
#if defined(LIN_STOP_SEC_CONST_16BIT)
# undef LIN_STOP_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined(LIN_START_SEC_CONST_32BIT)
# undef LIN_START_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_32BIT
#endif
#if defined(LIN_STOP_SEC_CONST_32BIT)
# undef LIN_STOP_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined(LIN_START_SEC_CONST_UNSPECIFIED)
# undef LIN_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#if defined(LIN_STOP_SEC_CONST_UNSPECIFIED)
# undef LIN_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/* FAST CONST sections */

#if defined(LIN_START_SEC_FAST_CONST_8BIT)
# undef LIN_START_SEC_FAST_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_FAST_CONST_8BIT
#endif
#if defined(LIN_STOP_SEC_FAST_CONST_8BIT)
# undef LIN_STOP_SEC_FAST_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined(LIN_START_SEC_FAST_CONST_16BIT)
# undef LIN_START_SEC_FAST_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_FAST_CONST_16BIT
#endif
#if defined(LIN_STOP_SEC_FAST_CONST_16BIT)
# undef LIN_STOP_SEC_FAST_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined(LIN_START_SEC_FAST_CONST_32BIT)
# undef LIN_START_SEC_FAST_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_FAST_CONST_32BIT
#endif
#if defined(LIN_STOP_SEC_FAST_CONST_32BIT)
# undef LIN_STOP_SEC_FAST_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined(LIN_START_SEC_FAST_CONST_UNSPECIFIED)
# undef LIN_START_SEC_FAST_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_FAST_CONST_UNSPECIFIED
#endif
#if defined(LIN_STOP_SEC_FAST_CONST_UNSPECIFIED)
# undef LIN_STOP_SEC_FAST_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/* Postbuild CFG CONST sections */

/* NOTE: ASR3.x till ASR4.0.1 only. Root table for postbuild data */
#if defined(LIN_START_SEC_PBCFG_ROOT)
# undef LIN_START_SEC_PBCFG_ROOT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_PBCFG
#endif
#if defined(LIN_STOP_SEC_PBCFG_ROOT)
# undef LIN_STOP_SEC_PBCFG_ROOT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

/* ESCAN00065501 */
/* NOTE: ASR4.0.3 (CFG5) only. The origin root table for postbuild data. Relevant only for EcuM. */
#if defined(LIN_START_SEC_PBCFG_GLOBALROOT)
# undef LIN_START_SEC_PBCFG_GLOBALROOT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_PBCFG_GLOBALROOT
#endif
#if defined(LIN_STOP_SEC_PBCFG_GLOBALROOT)
# undef LIN_STOP_SEC_PBCFG_GLOBALROOT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined(LIN_START_SEC_PBCFG)
# undef LIN_START_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_PBCFG
#endif
#if defined(LIN_STOP_SEC_PBCFG)
# undef LIN_STOP_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/*******  VAR sections  ***********************************************************************************************/

/* VAR INIT sections */

#if defined(LIN_START_SEC_VAR_INIT_8BIT)
# undef LIN_START_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_8BIT                                      /* mapped to default var init 8bit section */
#endif
#if defined(LIN_STOP_SEC_VAR_INIT_8BIT)
# undef LIN_STOP_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR                                                 /* default var stop section */
#endif

#if defined(LIN_START_SEC_VAR_INIT_16BIT)
# undef LIN_START_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_16BIT
#endif
#if defined(LIN_STOP_SEC_VAR_INIT_16BIT)
# undef LIN_STOP_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(LIN_START_SEC_VAR_INIT_32BIT)
# undef LIN_START_SEC_VAR_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_32BIT
#endif
#if defined(LIN_STOP_SEC_VAR_INIT_32BIT)
# undef LIN_STOP_SEC_VAR_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(LIN_START_SEC_VAR_INIT_UNSPECIFIED)
# undef LIN_START_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#if defined(LIN_STOP_SEC_VAR_INIT_UNSPECIFIED)
# undef LIN_STOP_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR NOINIT sections */

#if defined(LIN_START_SEC_VAR_NOINIT_8BIT)
# undef LIN_START_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_8BIT
#endif
#if defined(LIN_STOP_SEC_VAR_NOINIT_8BIT)
# undef LIN_STOP_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(LIN_START_SEC_VAR_NOINIT_16BIT)
# undef LIN_START_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_16BIT
#endif
#if defined(LIN_STOP_SEC_VAR_NOINIT_16BIT)
# undef LIN_STOP_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(LIN_START_SEC_VAR_NOINIT_32BIT)
# undef LIN_START_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_32BIT
#endif
#if defined(LIN_STOP_SEC_VAR_NOINIT_32BIT)
# undef LIN_STOP_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(LIN_START_SEC_VAR_NOINIT_UNSPECIFIED)
# undef LIN_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#if defined(LIN_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
# undef LIN_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* ESCAN00065501 */
#if defined(LIN_START_SEC_VAR_PBCFG)
# undef LIN_START_SEC_VAR_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_PBCFG
#endif
#if defined(LIN_STOP_SEC_VAR_PBCFG)
# undef LIN_STOP_SEC_VAR_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR ZERO INIT sections */

#if defined(LIN_START_SEC_VAR_ZERO_INIT_8BIT)
# undef LIN_START_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#if defined(LIN_STOP_SEC_VAR_ZERO_INIT_8BIT)
# undef LIN_STOP_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(LIN_START_SEC_VAR_ZERO_INIT_16BIT)
# undef LIN_START_SEC_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_16BIT
#endif
#if defined(LIN_STOP_SEC_VAR_ZERO_INIT_16BIT)
# undef LIN_STOP_SEC_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(LIN_START_SEC_VAR_ZERO_INIT_32BIT)
# undef LIN_START_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_32BIT
#endif
#if defined(LIN_STOP_SEC_VAR_ZERO_INIT_32BIT)
# undef LIN_STOP_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(LIN_START_SEC_VAR_ZERO_INIT_UNSPECIFIED)
# undef LIN_START_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#if defined(LIN_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED)
# undef LIN_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR FAST INIT sections */

#if defined(LIN_START_SEC_VAR_FAST_INIT_8BIT)
# undef LIN_START_SEC_VAR_FAST_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_8BIT
#endif
#if defined(LIN_STOP_SEC_VAR_FAST_INIT_8BIT)
# undef LIN_STOP_SEC_VAR_FAST_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(LIN_START_SEC_VAR_FAST_INIT_16BIT)
# undef LIN_START_SEC_VAR_FAST_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_16BIT
#endif
#if defined(LIN_STOP_SEC_VAR_FAST_INIT_16BIT)
# undef LIN_STOP_SEC_VAR_FAST_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(LIN_START_SEC_VAR_FAST_INIT_32BIT)
# undef LIN_START_SEC_VAR_FAST_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_32BIT
#endif
#if defined(LIN_STOP_SEC_VAR_FAST_INIT_32BIT)
# undef LIN_STOP_SEC_VAR_FAST_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(LIN_START_SEC_VAR_FAST_INIT_UNSPECIFIED)
# undef LIN_START_SEC_VAR_FAST_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_UNSPECIFIED
#endif
#if defined(LIN_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED)
# undef LIN_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR FAST NOINIT sections */

#if defined(LIN_START_SEC_VAR_FAST_NOINIT_8BIT)
# undef LIN_START_SEC_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_8BIT
#endif
#if defined(LIN_STOP_SEC_VAR_FAST_NOINIT_8BIT)
# undef LIN_STOP_SEC_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(LIN_START_SEC_VAR_FAST_NOINIT_16BIT)
# undef LIN_START_SEC_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_16BIT
#endif
#if defined(LIN_STOP_SEC_VAR_FAST_NOINIT_16BIT)
# undef LIN_STOP_SEC_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(LIN_START_SEC_VAR_FAST_NOINIT_32BIT)
# undef LIN_START_SEC_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_32BIT
#endif
#if defined(LIN_STOP_SEC_VAR_FAST_NOINIT_32BIT)
# undef LIN_STOP_SEC_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(LIN_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED)
# undef LIN_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
#endif
#if defined(LIN_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED)
# undef LIN_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR FAST ZERO INIT sections */

#if defined(LIN_START_SEC_VAR_FAST_ZERO_INIT_8BIT)
# undef LIN_START_SEC_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_8BIT
#endif
#if defined(LIN_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT)
# undef LIN_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(LIN_START_SEC_VAR_FAST_ZERO_INIT_16BIT)
# undef LIN_START_SEC_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_16BIT
#endif
#if defined(LIN_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT)
# undef LIN_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(LIN_START_SEC_VAR_FAST_ZERO_INIT_32BIT)
# undef LIN_START_SEC_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_32BIT
#endif
#if defined(LIN_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT)
# undef LIN_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(LIN_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED)
# undef LIN_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
#endif
#if defined(LIN_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED)
# undef LIN_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE INIT sections */

#if defined(LIN_START_SEC_VAR_NOCACHE_INIT_8BIT)
# undef LIN_START_SEC_VAR_NOCACHE_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_8BIT
#endif
#if defined(LIN_STOP_SEC_VAR_NOCACHE_INIT_8BIT)
# undef LIN_STOP_SEC_VAR_NOCACHE_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(LIN_START_SEC_VAR_NOCACHE_INIT_16BIT)
# undef LIN_START_SEC_VAR_NOCACHE_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_16BIT
#endif
#if defined(LIN_STOP_SEC_VAR_NOCACHE_INIT_16BIT)
# undef LIN_STOP_SEC_VAR_NOCACHE_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(LIN_START_SEC_VAR_NOCACHE_INIT_32BIT)
# undef LIN_START_SEC_VAR_NOCACHE_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_32BIT
#endif
#if defined(LIN_STOP_SEC_VAR_NOCACHE_INIT_32BIT)
# undef LIN_STOP_SEC_VAR_NOCACHE_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(LIN_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED)
# undef LIN_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
#endif
#if defined(LIN_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED)
# undef LIN_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE NOINIT sections */

#if defined(LIN_START_SEC_VAR_NOCACHE_NOINIT_8BIT)
# undef LIN_START_SEC_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_8BIT
#endif
#if defined(LIN_STOP_SEC_VAR_NOCACHE_NOINIT_8BIT)
# undef LIN_STOP_SEC_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(LIN_START_SEC_VAR_NOCACHE_NOINIT_16BIT)
# undef LIN_START_SEC_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_16BIT
#endif
#if defined(LIN_STOP_SEC_VAR_NOCACHE_NOINIT_16BIT)
# undef LIN_STOP_SEC_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(LIN_START_SEC_VAR_NOCACHE_NOINIT_32BIT)
# undef LIN_START_SEC_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_32BIT
#endif
#if defined(LIN_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT)
# undef LIN_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(LIN_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED)
# undef LIN_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
#endif
#if defined(LIN_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED)
# undef LIN_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE ZERO INIT sections */

#if defined(LIN_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT)
# undef LIN_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
#endif
#if defined(LIN_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT)
# undef LIN_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(LIN_START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT)
# undef LIN_START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
#endif
#if defined(LIN_STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT)
# undef LIN_STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(LIN_START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT)
# undef LIN_START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
#endif
#if defined(LIN_STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT)
# undef LIN_STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(LIN_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED)
# undef LIN_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
#endif
#if defined(LIN_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED)
# undef LIN_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/***********************************************************************************************************************
 *  LIN END
 **********************************************************************************************************************/



/**********************************************************************************************************************
 *  VMEM_30_FLS START
 *********************************************************************************************************************/


/*******  CODE sections **********************************************************************************************/

#if defined(VMEM_30_FLS_START_SEC_CODE)
# undef VMEM_30_FLS_START_SEC_CODE      /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE         /* mapped to default code section */
#endif
#if defined(VMEM_30_FLS_STOP_SEC_CODE)
# undef VMEM_30_FLS_STOP_SEC_CODE       /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE          /* default code stop section */
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */
#ifdef VMEM_30_FLS_START_SEC_CONST_UNSPECIFIED
# undef VMEM_30_FLS_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef VMEM_30_FLS_STOP_SEC_CONST_UNSPECIFIED
# undef VMEM_30_FLS_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined VMEM_30_FLS_START_SEC_HEADER_CONST_UNSPECIFIED
# undef VMEM_30_FLS_START_SEC_HEADER_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#if defined VMEM_30_FLS_STOP_SEC_HEADER_CONST_UNSPECIFIED
# undef VMEM_30_FLS_STOP_SEC_HEADER_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined VMEM_30_FLS_START_SEC_FOOTER_CONST_32BIT
# undef VMEM_30_FLS_START_SEC_FOOTER_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_32BIT
#endif
#if defined VMEM_30_FLS_STOP_SEC_FOOTER_CONST_32BIT
# undef VMEM_30_FLS_STOP_SEC_FOOTER_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR NOINIT sections */

/* VAR ZERO INIT sections */
#ifdef VMEM_30_FLS_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef VMEM_30_FLS_START_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#ifdef VMEM_30_FLS_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef VMEM_30_FLS_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/**********************************************************************************************************************
 *  VMEM_30_FLS END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  WDGIF START
 *********************************************************************************************************************/

#include "WdgIf_OsMemMap.h"

/*******  CODE sections **********************************************************************************************/

#if defined WDGIF_START_SEC_CODE_ASIL_D
# undef WDGIF_START_SEC_CODE_ASIL_D /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif
#if defined WDGIF_STOP_SEC_CODE_ASIL_D
# undef WDGIF_STOP_SEC_CODE_ASIL_D /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif


/*******  CONST sections  ********************************************************************************************/

#if defined WDGIF_START_SEC_CONST_ASIL_D_LOCAL_UNSPECIFIED
# undef WDGIF_START_SEC_CONST_ASIL_D_LOCAL_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_UNSPECIFIED
#endif
#if defined WDGIF_STOP_SEC_CONST_ASIL_D_LOCAL_UNSPECIFIED
# undef WDGIF_STOP_SEC_CONST_ASIL_D_LOCAL_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

#if defined WDGIF_START_SEC_VAR_INIT_ASIL_D_LOCAL_8
# undef WDGIF_START_SEC_VAR_INIT_ASIL_D_LOCAL_8 /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_8
#endif
#if defined WDGIF_STOP_SEC_VAR_INIT_ASIL_D_LOCAL_8
# undef WDGIF_STOP_SEC_VAR_INIT_ASIL_D_LOCAL_8 /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined WDGIF_START_SEC_VAR_INIT_ASIL_D_LOCAL_16
# undef WDGIF_START_SEC_VAR_INIT_ASIL_D_LOCAL_16 /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_16
#endif
#if defined WDGIF_STOP_SEC_VAR_INIT_ASIL_D_LOCAL_16
# undef WDGIF_STOP_SEC_VAR_INIT_ASIL_D_LOCAL_16 /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined WDGIF_START_SEC_VAR_CLEARED_ASIL_D_GLOBAL_UNSPECIFIED
# undef WDGIF_START_SEC_VAR_CLEARED_ASIL_D_GLOBAL_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_CLEARED_UNSPECIFIED
#endif
#if defined WDGIF_STOP_SEC_VAR_CLEARED_ASIL_D_GLOBAL_UNSPECIFIED
# undef WDGIF_STOP_SEC_VAR_CLEARED_ASIL_D_GLOBAL_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif


/**********************************************************************************************************************
 *  WDGIF END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  VMEMACCM START
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#if defined(VMEMACCM_START_SEC_CODE)
# undef VMEMACCM_START_SEC_CODE      /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE         /* mapped to default code section */
#endif
#if defined(VMEMACCM_STOP_SEC_CODE)
# undef VMEMACCM_STOP_SEC_CODE       /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE          /* default code stop section */
#endif

/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

#if defined(VMEMACCM_START_SEC_VAR_INIT_8BIT)
# undef VMEMACCM_START_SEC_VAR_INIT_8BIT  /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_8BIT          /* mapped to default var init 8bit section */
#endif
#if defined(VMEMACCM_STOP_SEC_VAR_INIT_8BIT)
# undef VMEMACCM_STOP_SEC_VAR_INIT_8BIT   /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR                     /* default var stop section */
#endif

#if defined(VMEMACCM_START_SEC_VAR_INIT_16BIT)
# undef VMEMACCM_START_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_16BIT
#endif
#if defined(VMEMACCM_STOP_SEC_VAR_INIT_16BIT)
# undef VMEMACCM_STOP_SEC_VAR_INIT_16BIT  /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(VMEMACCM_START_SEC_VAR_INIT_32BIT)
# undef VMEMACCM_START_SEC_VAR_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_32BIT
#endif
#if defined(VMEMACCM_STOP_SEC_VAR_INIT_32BIT)
# undef VMEMACCM_STOP_SEC_VAR_INIT_32BIT  /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(VMEMACCM_START_SEC_VAR_INIT_UNSPECIFIED)
# undef VMEMACCM_START_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#if defined(VMEMACCM_STOP_SEC_VAR_INIT_UNSPECIFIED)
# undef VMEMACCM_STOP_SEC_VAR_INIT_UNSPECIFIED  /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR ZERO INIT sections */

#if defined(VMEMACCM_START_SEC_VAR_ZERO_INIT_8BIT)
# undef VMEMACCM_START_SEC_VAR_ZERO_INIT_8BIT   /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#if defined(VMEMACCM_STOP_SEC_VAR_ZERO_INIT_8BIT)
# undef VMEMACCM_STOP_SEC_VAR_ZERO_INIT_8BIT    /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(VMEMACCM_START_SEC_VAR_ZERO_INIT_UNSPECIFIED)
# undef VMEMACCM_START_SEC_VAR_ZERO_INIT_UNSPECIFIED   /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#if defined(VMEMACCM_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED)
# undef VMEMACCM_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED    /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR CONST sections */

#if defined(VMEMACCM_START_SEC_CONST_UNSPECIFIED)
# undef VMEMACCM_START_SEC_CONST_UNSPECIFIED  /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#if defined(VMEMACCM_STOP_SEC_CONST_UNSPECIFIED)
# undef VMEMACCM_STOP_SEC_CONST_UNSPECIFIED   /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

/* VAR NOINIT sections */

#if defined(VMEMACCM_START_SEC_VAR_NOINIT_8BIT)
# undef VMEMACCM_START_SEC_VAR_NOINIT_8BIT  /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_8BIT
#endif
#if defined(VMEMACCM_STOP_SEC_VAR_NOINIT_8BIT)
# undef VMEMACCM_STOP_SEC_VAR_NOINIT_8BIT   /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(VMEMACCM_START_SEC_VAR_NOINIT_16BIT)
# undef VMEMACCM_START_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_16BIT
#endif
#if defined(VMEMACCM_STOP_SEC_VAR_NOINIT_16BIT)
# undef VMEMACCM_STOP_SEC_VAR_NOINIT_16BIT  /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(VMEMACCM_START_SEC_VAR_NOINIT_32BIT)
# undef VMEMACCM_START_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_32BIT
#endif
#if defined(VMEMACCM_STOP_SEC_VAR_NOINIT_32BIT)
# undef VMEMACCM_STOP_SEC_VAR_NOINIT_32BIT  /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(VMEMACCM_START_SEC_VAR_NOINIT_UNSPECIFIED)
# undef VMEMACCM_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#if defined(VMEMACCM_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
# undef VMEMACCM_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* Multi partition sections. */

#if defined VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID0
# undef VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID0
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else    
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
   /* Pragma demo for GHS compiler: */
#   pragma ghs section data=".vMemAccMPartition0"
#   pragma ghs section sdata=".svMemAccMPartition0"
#  else 
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define START_SEC_VAR_INIT_32BIT
#endif

#if defined VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID0
# undef VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID0
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
    /* Pragma demo for GHS compiler: */
#   pragma ghs section data=default
#   pragma ghs section sdata=default
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define STOP_SEC_VAR
#endif


#if defined VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID1
# undef VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID1
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else    
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
   /* Pragma demo for GHS compiler: */
#   pragma ghs section data=".vMemAccMPartition1"
#   pragma ghs section sdata=".svMemAccMPartition1"
#  else 
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define START_SEC_VAR_INIT_32BIT
#endif

#if defined VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID1
# undef VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID1
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
    /* Pragma demo for GHS compiler: */
#   pragma ghs section data=default
#   pragma ghs section sdata=default
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define STOP_SEC_VAR
#endif

#if defined VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID2
# undef VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID2
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else    
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
   /* Pragma demo for GHS compiler: */
#   pragma ghs section data=".vMemAccMPartition2"
#   pragma ghs section sdata=".svMemAccMPartition2"
#  else 
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define START_SEC_VAR_INIT_32BIT
#endif

#if defined VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID2
# undef VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID2
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
    /* Pragma demo for GHS compiler: */
#   pragma ghs section data=default
#   pragma ghs section sdata=default
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define STOP_SEC_VAR
#endif

#if defined VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID3
# undef VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID3
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else    
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
   /* Pragma demo for GHS compiler: */
#   pragma ghs section data=".vMemAccMPartition3"
#   pragma ghs section sdata=".svMemAccMPartition3"
#  else 
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define START_SEC_VAR_INIT_32BIT
#endif

#if defined VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID3
# undef VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID3
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
    /* Pragma demo for GHS compiler: */
#   pragma ghs section data=default
#   pragma ghs section sdata=default
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define STOP_SEC_VAR
#endif

#if defined VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID4
# undef VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID4
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else    
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
   /* Pragma demo for GHS compiler: */
#   pragma ghs section data=".vMemAccMPartition4"
#   pragma ghs section sdata=".svMemAccMPartition4"
#  else 
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define START_SEC_VAR_INIT_32BIT
#endif

#if defined VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID4
# undef VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID4
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
    /* Pragma demo for GHS compiler: */
#   pragma ghs section data=default
#   pragma ghs section sdata=default
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define STOP_SEC_VAR
#endif

#if defined VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID5
# undef VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID5
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else    
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
   /* Pragma demo for GHS compiler: */
#   pragma ghs section data=".vMemAccMPartition5"
#   pragma ghs section sdata=".svMemAccMPartition5"
#  else 
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define START_SEC_VAR_INIT_32BIT
#endif

#if defined VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID5
# undef VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID5
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
    /* Pragma demo for GHS compiler: */
#   pragma ghs section data=default
#   pragma ghs section sdata=default
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define STOP_SEC_VAR
#endif

#if defined VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID6
# undef VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID6
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else    
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
   /* Pragma demo for GHS compiler: */
#   pragma ghs section data=".vMemAccMPartition6"
#   pragma ghs section sdata=".svMemAccMPartition6"
#  else 
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define START_SEC_VAR_INIT_32BIT
#endif

#if defined VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID6
# undef VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID6
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
    /* Pragma demo for GHS compiler: */
#   pragma ghs section data=default
#   pragma ghs section sdata=default
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define STOP_SEC_VAR
#endif

#if defined VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID7
# undef VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID7
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else    
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
   /* Pragma demo for GHS compiler: */
#   pragma ghs section data=".vMemAccMPartition7"
#   pragma ghs section sdata=".svMemAccMPartition7"
#  else 
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define START_SEC_VAR_INIT_32BIT
#endif

#if defined VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID7
# undef VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID7
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
    /* Pragma demo for GHS compiler: */
#   pragma ghs section data=default
#   pragma ghs section sdata=default
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define STOP_SEC_VAR
#endif

#if defined VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID8
# undef VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID8
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else    
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
   /* Pragma demo for GHS compiler: */
#   pragma ghs section data=".vMemAccMPartition8"
#   pragma ghs section sdata=".svMemAccMPartition8"
#  else 
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define START_SEC_VAR_INIT_32BIT
#endif

#if defined VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID8
# undef VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID8
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
    /* Pragma demo for GHS compiler: */
#   pragma ghs section data=default
#   pragma ghs section sdata=default
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define STOP_SEC_VAR
#endif

#if defined VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID9
# undef VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID9
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else    
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
   /* Pragma demo for GHS compiler: */
#   pragma ghs section data=".vMemAccMPartition9"
#   pragma ghs section sdata=".svMemAccMPartition9"
#  else 
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define START_SEC_VAR_INIT_32BIT
#endif

#if defined VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID9
# undef VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID9
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
    /* Pragma demo for GHS compiler: */
#   pragma ghs section data=default
#   pragma ghs section sdata=default
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define STOP_SEC_VAR
#endif

#if defined VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID10
# undef VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID10
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else    
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
   /* Pragma demo for GHS compiler: */
#   pragma ghs section data=".vMemAccMPartition10"
#   pragma ghs section sdata=".svMemAccMPartition10"
#  else 
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define START_SEC_VAR_INIT_32BIT
#endif

#if defined VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID10
# undef VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID10
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
    /* Pragma demo for GHS compiler: */
#   pragma ghs section data=default
#   pragma ghs section sdata=default
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define STOP_SEC_VAR
#endif

#if defined VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID11
# undef VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID11
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else    
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
   /* Pragma demo for GHS compiler: */
#   pragma ghs section data=".vMemAccMPartition11"
#   pragma ghs section sdata=".svMemAccMPartition11"
#  else 
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define START_SEC_VAR_INIT_32BIT
#endif

#if defined VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID11
# undef VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID11
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
    /* Pragma demo for GHS compiler: */
#   pragma ghs section data=default
#   pragma ghs section sdata=default
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define STOP_SEC_VAR
#endif

#if defined VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID12
# undef VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID12
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else    
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
   /* Pragma demo for GHS compiler: */
#   pragma ghs section data=".vMemAccMPartition12"
#   pragma ghs section sdata=".svMemAccMPartition12"
#  else 
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define START_SEC_VAR_INIT_32BIT
#endif

#if defined VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID12
# undef VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID12
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
    /* Pragma demo for GHS compiler: */
#   pragma ghs section data=default
#   pragma ghs section sdata=default
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define STOP_SEC_VAR
#endif

#if defined VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID13
# undef VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID13
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else    
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
   /* Pragma demo for GHS compiler: */
#   pragma ghs section data=".vMemAccMPartition13"
#   pragma ghs section sdata=".svMemAccMPartition13"
#  else 
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define START_SEC_VAR_INIT_32BIT
#endif

#if defined VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID13
# undef VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID13
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
    /* Pragma demo for GHS compiler: */
#   pragma ghs section data=default
#   pragma ghs section sdata=default
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define STOP_SEC_VAR
#endif

#if defined VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID14
# undef VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID14
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else    
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
   /* Pragma demo for GHS compiler: */
#   pragma ghs section data=".vMemAccMPartition14"
#   pragma ghs section sdata=".svMemAccMPartition14"
#  else 
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define START_SEC_VAR_INIT_32BIT
#endif

#if defined VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID14
# undef VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID14
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
    /* Pragma demo for GHS compiler: */
#   pragma ghs section data=default
#   pragma ghs section sdata=default
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define STOP_SEC_VAR
#endif

#if defined VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID15
# undef VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID15
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else    
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
   /* Pragma demo for GHS compiler: */
#   pragma ghs section data=".vMemAccMPartition15"
#   pragma ghs section sdata=".svMemAccMPartition15"
#  else 
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define START_SEC_VAR_INIT_32BIT
#endif

#if defined VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID15
# undef VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID15
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
    /* Pragma demo for GHS compiler: */
#   pragma ghs section data=default
#   pragma ghs section sdata=default
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define STOP_SEC_VAR
#endif

#if defined VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID16
# undef VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID16
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else    
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
   /* Pragma demo for GHS compiler: */
#   pragma ghs section data=".vMemAccMPartition16"
#   pragma ghs section sdata=".svMemAccMPartition16"
#  else 
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define START_SEC_VAR_INIT_32BIT
#endif

#if defined VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID16
# undef VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID16
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
    /* Pragma demo for GHS compiler: */
#   pragma ghs section data=default
#   pragma ghs section sdata=default
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  VMEMACCM END
 *********************************************************************************************************************/


/**********************************************************************************************************************
* 3rdParty_Mcal START
*********************************************************************************************************************/
#ifdef ADC_CORE0_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_16
  #undef ADC_CORE0_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_16
  #define START_SEC_VAR_CLEARED_16
#endif

#ifdef ADC_CORE0_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_16
  #undef ADC_CORE0_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_16
  #define STOP_SEC_VAR
#endif

#ifdef ADC_CORE0_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
  #undef ADC_CORE0_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
  #define START_SEC_VAR_CLEARED_32
#endif

#ifdef ADC_CORE0_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
  #undef ADC_CORE0_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
  #define STOP_SEC_VAR
#endif

#ifdef ADC_CORE0_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_BOOLEAN
  #undef ADC_CORE0_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_BOOLEAN
  #define START_SEC_VAR_CLEARED_UNSPECIFIED
#endif

#ifdef ADC_CORE0_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_BOOLEAN
  #undef ADC_CORE0_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_BOOLEAN
  #define STOP_SEC_VAR
#endif

#ifdef ADC_CORE0_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_UNSPECIFIED
  #undef ADC_CORE0_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_UNSPECIFIED
  #define START_SEC_VAR_CLEARED_UNSPECIFIED
#endif

#ifdef ADC_CORE0_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_UNSPECIFIED
  #undef ADC_CORE0_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef ADC_CORE0_START_SEC_VAR_INIT_ASIL_B_GLOBAL_UNSPECIFIED
  #undef ADC_CORE0_START_SEC_VAR_INIT_ASIL_B_GLOBAL_UNSPECIFIED
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef ADC_CORE0_STOP_SEC_VAR_INIT_ASIL_B_GLOBAL_UNSPECIFIED
  #undef ADC_CORE0_STOP_SEC_VAR_INIT_ASIL_B_GLOBAL_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef ADC_START_SEC_CODE_ASIL_B
  #undef ADC_START_SEC_CODE_ASIL_B
  #define START_SEC_CODE
#endif

#ifdef ADC_STOP_SEC_CODE_ASIL_B
  #undef ADC_STOP_SEC_CODE_ASIL_B
  #define STOP_SEC_CODE
#endif

#ifdef ADC_START_SEC_CONST_ASIL_B_UNSPECIFIED
  #undef ADC_START_SEC_CONST_ASIL_B_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef ADC_STOP_SEC_CONST_ASIL_B_UNSPECIFIED
  #undef ADC_STOP_SEC_CONST_ASIL_B_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef ADC_START_SEC_VAR_INIT_ASIL_B_GLOBAL_CORE0_UNSPECIFIED
  #undef ADC_START_SEC_VAR_INIT_ASIL_B_GLOBAL_CORE0_UNSPECIFIED
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef ADC_STOP_SEC_VAR_INIT_ASIL_B_GLOBAL_CORE0_UNSPECIFIED
  #undef ADC_STOP_SEC_VAR_INIT_ASIL_B_GLOBAL_CORE0_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef ADC_START_SEC_VAR_INIT_ASIL_B_UNSPECIFIED
  #undef ADC_START_SEC_VAR_INIT_ASIL_B_UNSPECIFIED
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef ADC_STOP_SEC_VAR_INIT_ASIL_B_UNSPECIFIED
  #undef ADC_STOP_SEC_VAR_INIT_ASIL_B_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef ADC_START_SEC_VAR_NO_INIT_ASIL_B_GLOBAL_CORE0_16
  #undef ADC_START_SEC_VAR_NO_INIT_ASIL_B_GLOBAL_CORE0_16
  #define START_SEC_VAR_NO_INIT_16
#endif

#ifdef ADC_STOP_SEC_VAR_NO_INIT_ASIL_B_GLOBAL_CORE0_16
  #undef ADC_STOP_SEC_VAR_NO_INIT_ASIL_B_GLOBAL_CORE0_16
  #define STOP_SEC_VAR
#endif

#ifdef ADC_START_SEC_VAR_NO_INIT_ASIL_B_GLOBAL_CORE0_32
  #undef ADC_START_SEC_VAR_NO_INIT_ASIL_B_GLOBAL_CORE0_32
  #define START_SEC_VAR_NO_INIT_32
#endif

#ifdef ADC_STOP_SEC_VAR_NO_INIT_ASIL_B_GLOBAL_CORE0_32
  #undef ADC_STOP_SEC_VAR_NO_INIT_ASIL_B_GLOBAL_CORE0_32
  #define STOP_SEC_VAR
#endif

#ifdef ADC_START_SEC_VAR_NO_INIT_ASIL_B_LOCAL_OR_GLOBAL_CORE0_16
  #undef ADC_START_SEC_VAR_NO_INIT_ASIL_B_LOCAL_OR_GLOBAL_CORE0_16
  #define START_SEC_VAR_NO_INIT_16
#endif

#ifdef ADC_STOP_SEC_VAR_NO_INIT_ASIL_B_LOCAL_OR_GLOBAL_CORE0_16
  #undef ADC_STOP_SEC_VAR_NO_INIT_ASIL_B_LOCAL_OR_GLOBAL_CORE0_16
  #define STOP_SEC_VAR
#endif

#ifdef ADC_START_SEC_VAR_NO_INIT_ASIL_B_LOCAL_OR_GLOBAL_CORE0_32
  #undef ADC_START_SEC_VAR_NO_INIT_ASIL_B_LOCAL_OR_GLOBAL_CORE0_32
  #define START_SEC_VAR_NO_INIT_32
#endif

#ifdef ADC_STOP_SEC_VAR_NO_INIT_ASIL_B_LOCAL_OR_GLOBAL_CORE0_32
  #undef ADC_STOP_SEC_VAR_NO_INIT_ASIL_B_LOCAL_OR_GLOBAL_CORE0_32
  #define STOP_SEC_VAR
#endif

#ifdef ADC_START_SEC_VAR_NO_INIT_ASIL_B_LOCAL_OR_GLOBAL_CORE0_BOOLEAN
  #undef ADC_START_SEC_VAR_NO_INIT_ASIL_B_LOCAL_OR_GLOBAL_CORE0_BOOLEAN
  #define START_SEC_VAR_NO_INIT_UNSPECIFIED
#endif

#ifdef ADC_STOP_SEC_VAR_NO_INIT_ASIL_B_LOCAL_OR_GLOBAL_CORE0_BOOLEAN
  #undef ADC_STOP_SEC_VAR_NO_INIT_ASIL_B_LOCAL_OR_GLOBAL_CORE0_BOOLEAN
  #define STOP_SEC_VAR
#endif

#ifdef ADC_START_SEC_VAR_NO_INIT_ASIL_B_LOCAL_OR_GLOBAL_CORE0_UNSPECIFIED
  #undef ADC_START_SEC_VAR_NO_INIT_ASIL_B_LOCAL_OR_GLOBAL_CORE0_UNSPECIFIED
  #define START_SEC_VAR_NO_INIT_UNSPECIFIED
#endif

#ifdef ADC_STOP_SEC_VAR_NO_INIT_ASIL_B_LOCAL_OR_GLOBAL_CORE0_UNSPECIFIED
  #undef ADC_STOP_SEC_VAR_NO_INIT_ASIL_B_LOCAL_OR_GLOBAL_CORE0_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef ADC_START_SEC_VAR_NO_INIT_ASIL_B_UNSPECIFIED
  #undef ADC_START_SEC_VAR_NO_INIT_ASIL_B_UNSPECIFIED
  #define START_SEC_VAR_NO_INIT_UNSPECIFIED
#endif

#ifdef ADC_STOP_SEC_VAR_NO_INIT_ASIL_B_UNSPECIFIED
  #undef ADC_STOP_SEC_VAR_NO_INIT_ASIL_B_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef CAN_START_SEC_CODE
  #undef CAN_START_SEC_CODE
  #define START_SEC_CODE
#endif

#ifdef CAN_STOP_SEC_CODE
  #undef CAN_STOP_SEC_CODE
  #define STOP_SEC_CODE
#endif

#ifdef CAN_START_SEC_CODE_ASIL_B
  #undef CAN_START_SEC_CODE_ASIL_B
  #define START_SEC_CODE
#endif

#ifdef CAN_STOP_SEC_CODE_ASIL_B
  #undef CAN_STOP_SEC_CODE_ASIL_B
  #define STOP_SEC_CODE
#endif

#ifdef CAN_START_SEC_CONST_ASIL_B_UNSPECIFIED
  #undef CAN_START_SEC_CONST_ASIL_B_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef CAN_STOP_SEC_CONST_ASIL_B_UNSPECIFIED
  #undef CAN_STOP_SEC_CONST_ASIL_B_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef CAN_START_SEC_VAR_CLEARED_ASIL_B_UNSPECIFIED
  #undef CAN_START_SEC_VAR_CLEARED_ASIL_B_UNSPECIFIED
  #define START_SEC_VAR_CLEARED_UNSPECIFIED
#endif

#ifdef CAN_STOP_SEC_VAR_CLEARED_ASIL_B_UNSPECIFIED
  #undef CAN_STOP_SEC_VAR_CLEARED_ASIL_B_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef CAN_START_SEC_VAR_INIT_ASIL_B_UNSPECIFIED
  #undef CAN_START_SEC_VAR_INIT_ASIL_B_UNSPECIFIED
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef CAN_STOP_SEC_VAR_INIT_ASIL_B_UNSPECIFIED
  #undef CAN_STOP_SEC_VAR_INIT_ASIL_B_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef DIO_START_SEC_CODE_ASIL_B
  #undef DIO_START_SEC_CODE_ASIL_B
  #define START_SEC_CODE
#endif

#ifdef DIO_STOP_SEC_CODE_ASIL_B
  #undef DIO_STOP_SEC_CODE_ASIL_B
  #define STOP_SEC_CODE
#endif

#ifdef DIO_START_SEC_CONST_ASIL_B_UNSPECIFIED
  #undef DIO_START_SEC_CONST_ASIL_B_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef DIO_STOP_SEC_CONST_ASIL_B_UNSPECIFIED
  #undef DIO_STOP_SEC_CONST_ASIL_B_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef FLS_START_SEC_CODE
  #undef FLS_START_SEC_CODE
  #define START_SEC_CODE
#endif

#ifdef FLS_STOP_SEC_CODE
  #undef FLS_STOP_SEC_CODE
  #define STOP_SEC_CODE
#endif

#ifdef FLS_START_SEC_CODE_ASIL_B
  #undef FLS_START_SEC_CODE_ASIL_B
  #define START_SEC_CODE
#endif

#ifdef FLS_STOP_SEC_CODE_ASIL_B
  #undef FLS_STOP_SEC_CODE_ASIL_B
  #define STOP_SEC_CODE
#endif

#ifdef FLS_START_SEC_CONST_ASIL_B_UNSPECIFIED
  #undef FLS_START_SEC_CONST_ASIL_B_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef FLS_STOP_SEC_CONST_ASIL_B_UNSPECIFIED
  #undef FLS_STOP_SEC_CONST_ASIL_B_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef FLS_START_SEC_CONST_UNSPECIFIED
  #undef FLS_START_SEC_CONST_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef FLS_STOP_SEC_CONST_UNSPECIFIED
  #undef FLS_STOP_SEC_CONST_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef FLS_START_SEC_VAR_INIT_ASIL_B_UNSPECIFIED
  #undef FLS_START_SEC_VAR_INIT_ASIL_B_UNSPECIFIED
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef FLS_STOP_SEC_VAR_INIT_ASIL_B_UNSPECIFIED
  #undef FLS_STOP_SEC_VAR_INIT_ASIL_B_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef FLS_START_SEC_VAR_INIT_UNSPECIFIED
  #undef FLS_START_SEC_VAR_INIT_UNSPECIFIED
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef FLS_STOP_SEC_VAR_INIT_UNSPECIFIED
  #undef FLS_STOP_SEC_VAR_INIT_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef FLS_START_SEC_VAR_NO_INIT_ASIL_B_UNSPECIFIED
  #undef FLS_START_SEC_VAR_NO_INIT_ASIL_B_UNSPECIFIED
  #define START_SEC_VAR_NO_INIT_UNSPECIFIED
#endif

#ifdef FLS_STOP_SEC_VAR_NO_INIT_ASIL_B_UNSPECIFIED
  #undef FLS_STOP_SEC_VAR_NO_INIT_ASIL_B_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef FLS_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #undef FLS_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #define START_SEC_VAR_NO_INIT_UNSPECIFIED
#endif

#ifdef FLS_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #undef FLS_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef GPT_CORE0_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_UNSPECIFIED
  #undef GPT_CORE0_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_UNSPECIFIED
  #define START_SEC_VAR_CLEARED_UNSPECIFIED
#endif

#ifdef GPT_CORE0_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_UNSPECIFIED
  #undef GPT_CORE0_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef GPT_CORE0_START_SEC_VAR_INIT_ASIL_B_GLOBAL_UNSPECIFIED
  #undef GPT_CORE0_START_SEC_VAR_INIT_ASIL_B_GLOBAL_UNSPECIFIED
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef GPT_CORE0_STOP_SEC_VAR_INIT_ASIL_B_GLOBAL_UNSPECIFIED
  #undef GPT_CORE0_STOP_SEC_VAR_INIT_ASIL_B_GLOBAL_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef GPT_START_SEC_CODE_ASIL_B
  #undef GPT_START_SEC_CODE_ASIL_B
  #define START_SEC_CODE
#endif

#ifdef GPT_STOP_SEC_CODE_ASIL_B
  #undef GPT_STOP_SEC_CODE_ASIL_B
  #define STOP_SEC_CODE
#endif

#ifdef GPT_START_SEC_CONST_ASIL_B_UNSPECIFIED
  #undef GPT_START_SEC_CONST_ASIL_B_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef GPT_STOP_SEC_CONST_ASIL_B_UNSPECIFIED
  #undef GPT_STOP_SEC_CONST_ASIL_B_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef GPT_START_SEC_VAR_INIT_ASIL_B_GLOBAL_CORE0_UNSPECIFIED
  #undef GPT_START_SEC_VAR_INIT_ASIL_B_GLOBAL_CORE0_UNSPECIFIED
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef GPT_STOP_SEC_VAR_INIT_ASIL_B_GLOBAL_CORE0_UNSPECIFIED
  #undef GPT_STOP_SEC_VAR_INIT_ASIL_B_GLOBAL_CORE0_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef GPT_START_SEC_VAR_INIT_ASIL_B_UNSPECIFIED
  #undef GPT_START_SEC_VAR_INIT_ASIL_B_UNSPECIFIED
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef GPT_STOP_SEC_VAR_INIT_ASIL_B_UNSPECIFIED
  #undef GPT_STOP_SEC_VAR_INIT_ASIL_B_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef GPT_START_SEC_VAR_NO_INIT_ASIL_B_LOCAL_OR_GLOBAL_CORE0_UNSPECIFIED
  #undef GPT_START_SEC_VAR_NO_INIT_ASIL_B_LOCAL_OR_GLOBAL_CORE0_UNSPECIFIED
  #define START_SEC_VAR_NO_INIT_UNSPECIFIED
#endif

#ifdef GPT_STOP_SEC_VAR_NO_INIT_ASIL_B_LOCAL_OR_GLOBAL_CORE0_UNSPECIFIED
  #undef GPT_STOP_SEC_VAR_NO_INIT_ASIL_B_LOCAL_OR_GLOBAL_CORE0_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef GPT_START_SEC_VAR_NO_INIT_ASIL_B_UNSPECIFIED
  #undef GPT_START_SEC_VAR_NO_INIT_ASIL_B_UNSPECIFIED
  #define START_SEC_VAR_NO_INIT_UNSPECIFIED
#endif

#ifdef GPT_STOP_SEC_VAR_NO_INIT_ASIL_B_UNSPECIFIED
  #undef GPT_STOP_SEC_VAR_NO_INIT_ASIL_B_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef ICU_CORE0_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_UNSPECIFIED
  #undef ICU_CORE0_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_UNSPECIFIED
  #define START_SEC_VAR_CLEARED_UNSPECIFIED
#endif

#ifdef ICU_CORE0_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_UNSPECIFIED
  #undef ICU_CORE0_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef ICU_CORE0_START_SEC_VAR_INIT_ASIL_B_GLOBAL_UNSPECIFIED
  #undef ICU_CORE0_START_SEC_VAR_INIT_ASIL_B_GLOBAL_UNSPECIFIED
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef ICU_CORE0_STOP_SEC_VAR_INIT_ASIL_B_GLOBAL_UNSPECIFIED
  #undef ICU_CORE0_STOP_SEC_VAR_INIT_ASIL_B_GLOBAL_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef ICU_START_SEC_CODE_ASIL_B
  #undef ICU_START_SEC_CODE_ASIL_B
  #define START_SEC_CODE
#endif

#ifdef ICU_STOP_SEC_CODE_ASIL_B
  #undef ICU_STOP_SEC_CODE_ASIL_B
  #define STOP_SEC_CODE
#endif

#ifdef ICU_START_SEC_CONST_ASIL_B_UNSPECIFIED
  #undef ICU_START_SEC_CONST_ASIL_B_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef ICU_STOP_SEC_CONST_ASIL_B_UNSPECIFIED
  #undef ICU_STOP_SEC_CONST_ASIL_B_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef ICU_START_SEC_VAR_INIT_ASIL_B_GLOBAL_CORE0_UNSPECIFIED
  #undef ICU_START_SEC_VAR_INIT_ASIL_B_GLOBAL_CORE0_UNSPECIFIED
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef ICU_STOP_SEC_VAR_INIT_ASIL_B_GLOBAL_CORE0_UNSPECIFIED
  #undef ICU_STOP_SEC_VAR_INIT_ASIL_B_GLOBAL_CORE0_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef ICU_START_SEC_VAR_INIT_ASIL_B_UNSPECIFIED
  #undef ICU_START_SEC_VAR_INIT_ASIL_B_UNSPECIFIED
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef ICU_STOP_SEC_VAR_INIT_ASIL_B_UNSPECIFIED
  #undef ICU_STOP_SEC_VAR_INIT_ASIL_B_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef ICU_START_SEC_VAR_NO_INIT_ASIL_B_GLOBAL_CORE0_UNSPECIFIED
  #undef ICU_START_SEC_VAR_NO_INIT_ASIL_B_GLOBAL_CORE0_UNSPECIFIED
  #define START_SEC_VAR_NO_INIT_UNSPECIFIED
#endif

#ifdef ICU_STOP_SEC_VAR_NO_INIT_ASIL_B_GLOBAL_CORE0_UNSPECIFIED
  #undef ICU_STOP_SEC_VAR_NO_INIT_ASIL_B_GLOBAL_CORE0_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef ICU_START_SEC_VAR_NO_INIT_ASIL_B_LOCAL_OR_GLOBAL_CORE0_UNSPECIFIED
  #undef ICU_START_SEC_VAR_NO_INIT_ASIL_B_LOCAL_OR_GLOBAL_CORE0_UNSPECIFIED
  #define START_SEC_VAR_NO_INIT_UNSPECIFIED
#endif

#ifdef ICU_STOP_SEC_VAR_NO_INIT_ASIL_B_LOCAL_OR_GLOBAL_CORE0_UNSPECIFIED
  #undef ICU_STOP_SEC_VAR_NO_INIT_ASIL_B_LOCAL_OR_GLOBAL_CORE0_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef ICU_START_SEC_VAR_NO_INIT_ASIL_B_UNSPECIFIED
  #undef ICU_START_SEC_VAR_NO_INIT_ASIL_B_UNSPECIFIED
  #define START_SEC_VAR_NO_INIT_UNSPECIFIED
#endif

#ifdef ICU_STOP_SEC_VAR_NO_INIT_ASIL_B_UNSPECIFIED
  #undef ICU_STOP_SEC_VAR_NO_INIT_ASIL_B_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef LIN_START_SEC_CODE_ASIL_B
  #undef LIN_START_SEC_CODE_ASIL_B
  #define START_SEC_CODE
#endif

#ifdef LIN_STOP_SEC_CODE_ASIL_B
  #undef LIN_STOP_SEC_CODE_ASIL_B
  #define STOP_SEC_CODE
#endif

#ifdef LIN_START_SEC_CONST_ASIL_B_UNSPECIFIED
  #undef LIN_START_SEC_CONST_ASIL_B_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef LIN_STOP_SEC_CONST_ASIL_B_UNSPECIFIED
  #undef LIN_STOP_SEC_CONST_ASIL_B_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef LIN_START_SEC_VAR_INIT_ASIL_B_UNSPECIFIED
  #undef LIN_START_SEC_VAR_INIT_ASIL_B_UNSPECIFIED
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef LIN_STOP_SEC_VAR_INIT_ASIL_B_UNSPECIFIED
  #undef LIN_STOP_SEC_VAR_INIT_ASIL_B_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef LIN_START_SEC_VAR_NO_INIT_ASIL_B_UNSPECIFIED
  #undef LIN_START_SEC_VAR_NO_INIT_ASIL_B_UNSPECIFIED
  #define START_SEC_VAR_NO_INIT_UNSPECIFIED
#endif

#ifdef LIN_STOP_SEC_VAR_NO_INIT_ASIL_B_UNSPECIFIED
  #undef LIN_STOP_SEC_VAR_NO_INIT_ASIL_B_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef MCU_CORE0_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
  #undef MCU_CORE0_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
  #define START_SEC_VAR_CLEARED_32
#endif

#ifdef MCU_CORE0_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
  #undef MCU_CORE0_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
  #define STOP_SEC_VAR
#endif

#ifdef MCU_CORE0_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_UNSPECIFIED
  #undef MCU_CORE0_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_UNSPECIFIED
  #define START_SEC_VAR_CLEARED_UNSPECIFIED
#endif

#ifdef MCU_CORE0_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_UNSPECIFIED
  #undef MCU_CORE0_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef MCU_CORE0_START_SEC_VAR_INIT_ASIL_B_GLOBAL_32
  #undef MCU_CORE0_START_SEC_VAR_INIT_ASIL_B_GLOBAL_32
  #define START_SEC_VAR_INIT_32
#endif

#ifdef MCU_CORE0_STOP_SEC_VAR_INIT_ASIL_B_GLOBAL_32
  #undef MCU_CORE0_STOP_SEC_VAR_INIT_ASIL_B_GLOBAL_32
  #define STOP_SEC_VAR
#endif

#ifdef MCU_CORE0_START_SEC_VAR_INIT_ASIL_B_GLOBAL_8
  #undef MCU_CORE0_START_SEC_VAR_INIT_ASIL_B_GLOBAL_8
  #define START_SEC_VAR_INIT_8
#endif

#ifdef MCU_CORE0_STOP_SEC_VAR_INIT_ASIL_B_GLOBAL_8
  #undef MCU_CORE0_STOP_SEC_VAR_INIT_ASIL_B_GLOBAL_8
  #define STOP_SEC_VAR
#endif

#ifdef MCU_CORE0_START_SEC_VAR_INIT_ASIL_B_GLOBAL_UNSPECIFIED
  #undef MCU_CORE0_START_SEC_VAR_INIT_ASIL_B_GLOBAL_UNSPECIFIED
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef MCU_CORE0_STOP_SEC_VAR_INIT_ASIL_B_GLOBAL_UNSPECIFIED
  #undef MCU_CORE0_STOP_SEC_VAR_INIT_ASIL_B_GLOBAL_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef MCU_START_SEC_APPL_CODE
  #undef MCU_START_SEC_APPL_CODE
  #define START_SEC_CODE
#endif

#ifdef MCU_STOP_SEC_APPL_CODE
  #undef MCU_STOP_SEC_APPL_CODE
  #define STOP_SEC_CODE
#endif

#ifdef MCU_START_SEC_CODE_ASIL_B
  #undef MCU_START_SEC_CODE_ASIL_B
  #define START_SEC_CODE
#endif

#ifdef MCU_STOP_SEC_CODE_ASIL_B
  #undef MCU_STOP_SEC_CODE_ASIL_B
  #define STOP_SEC_CODE
#endif

#ifdef MCU_START_SEC_CONST_ASIL_B_32
  #undef MCU_START_SEC_CONST_ASIL_B_32
  #define START_SEC_CONST_32
#endif

#ifdef MCU_STOP_SEC_CONST_ASIL_B_32
  #undef MCU_STOP_SEC_CONST_ASIL_B_32
  #define STOP_SEC_CONST
#endif

#ifdef MCU_START_SEC_CONST_ASIL_B_UNSPECIFIED
  #undef MCU_START_SEC_CONST_ASIL_B_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef MCU_STOP_SEC_CONST_ASIL_B_UNSPECIFIED
  #undef MCU_STOP_SEC_CONST_ASIL_B_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef MCU_START_SEC_VAR_INIT_ASIL_B_32
  #undef MCU_START_SEC_VAR_INIT_ASIL_B_32
  #define START_SEC_VAR_INIT_32
#endif

#ifdef MCU_STOP_SEC_VAR_INIT_ASIL_B_32
  #undef MCU_STOP_SEC_VAR_INIT_ASIL_B_32
  #define STOP_SEC_VAR
#endif

#ifdef MCU_START_SEC_VAR_INIT_ASIL_B_8
  #undef MCU_START_SEC_VAR_INIT_ASIL_B_8
  #define START_SEC_VAR_INIT_8
#endif

#ifdef MCU_STOP_SEC_VAR_INIT_ASIL_B_8
  #undef MCU_STOP_SEC_VAR_INIT_ASIL_B_8
  #define STOP_SEC_VAR
#endif

#ifdef MCU_START_SEC_VAR_INIT_ASIL_B_BOOLEAN
  #undef MCU_START_SEC_VAR_INIT_ASIL_B_BOOLEAN
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef MCU_STOP_SEC_VAR_INIT_ASIL_B_BOOLEAN
  #undef MCU_STOP_SEC_VAR_INIT_ASIL_B_BOOLEAN
  #define STOP_SEC_VAR
#endif

#ifdef MCU_START_SEC_VAR_INIT_ASIL_B_GLOBAL_CORE0_32
  #undef MCU_START_SEC_VAR_INIT_ASIL_B_GLOBAL_CORE0_32
  #define START_SEC_VAR_INIT_32
#endif

#ifdef MCU_STOP_SEC_VAR_INIT_ASIL_B_GLOBAL_CORE0_32
  #undef MCU_STOP_SEC_VAR_INIT_ASIL_B_GLOBAL_CORE0_32
  #define STOP_SEC_VAR
#endif

#ifdef MCU_START_SEC_VAR_INIT_ASIL_B_GLOBAL_CORE0_8
  #undef MCU_START_SEC_VAR_INIT_ASIL_B_GLOBAL_CORE0_8
  #define START_SEC_VAR_INIT_8
#endif

#ifdef MCU_STOP_SEC_VAR_INIT_ASIL_B_GLOBAL_CORE0_8
  #undef MCU_STOP_SEC_VAR_INIT_ASIL_B_GLOBAL_CORE0_8
  #define STOP_SEC_VAR
#endif

#ifdef MCU_START_SEC_VAR_INIT_ASIL_B_GLOBAL_CORE0_UNSPECIFIED
  #undef MCU_START_SEC_VAR_INIT_ASIL_B_GLOBAL_CORE0_UNSPECIFIED
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef MCU_STOP_SEC_VAR_INIT_ASIL_B_GLOBAL_CORE0_UNSPECIFIED
  #undef MCU_STOP_SEC_VAR_INIT_ASIL_B_GLOBAL_CORE0_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef MCU_START_SEC_VAR_INIT_ASIL_B_UNSPECIFIED
  #undef MCU_START_SEC_VAR_INIT_ASIL_B_UNSPECIFIED
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef MCU_STOP_SEC_VAR_INIT_ASIL_B_UNSPECIFIED
  #undef MCU_STOP_SEC_VAR_INIT_ASIL_B_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef MCU_START_SEC_VAR_NO_INIT_ASIL_B_32
  #undef MCU_START_SEC_VAR_NO_INIT_ASIL_B_32
  #define START_SEC_VAR_NO_INIT_32
#endif

#ifdef MCU_STOP_SEC_VAR_NO_INIT_ASIL_B_32
  #undef MCU_STOP_SEC_VAR_NO_INIT_ASIL_B_32
  #define STOP_SEC_VAR
#endif

#ifdef MCU_START_SEC_VAR_NO_INIT_ASIL_B_GLOBAL_CORE0_UNSPECIFIED
  #undef MCU_START_SEC_VAR_NO_INIT_ASIL_B_GLOBAL_CORE0_UNSPECIFIED
  #define START_SEC_VAR_NO_INIT_UNSPECIFIED
#endif

#ifdef MCU_STOP_SEC_VAR_NO_INIT_ASIL_B_GLOBAL_CORE0_UNSPECIFIED
  #undef MCU_STOP_SEC_VAR_NO_INIT_ASIL_B_GLOBAL_CORE0_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef MCU_START_SEC_VAR_NO_INIT_ASIL_B_UNSPECIFIED
  #undef MCU_START_SEC_VAR_NO_INIT_ASIL_B_UNSPECIFIED
  #define START_SEC_VAR_NO_INIT_UNSPECIFIED
#endif

#ifdef MCU_STOP_SEC_VAR_NO_INIT_ASIL_B_UNSPECIFIED
  #undef MCU_STOP_SEC_VAR_NO_INIT_ASIL_B_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef OCU_START_SEC_CODE_ASIL_B
  #undef OCU_START_SEC_CODE_ASIL_B
  #define START_SEC_CODE
#endif

#ifdef OCU_STOP_SEC_CODE_ASIL_B
  #undef OCU_STOP_SEC_CODE_ASIL_B
  #define STOP_SEC_CODE
#endif

#ifdef OCU_START_SEC_CONST_ASIL_B_UNSPECIFIED
  #undef OCU_START_SEC_CONST_ASIL_B_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef OCU_STOP_SEC_CONST_ASIL_B_UNSPECIFIED
  #undef OCU_STOP_SEC_CONST_ASIL_B_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef OCU_START_SEC_VAR_INIT_ASIL_B_UNSPECIFIED
  #undef OCU_START_SEC_VAR_INIT_ASIL_B_UNSPECIFIED
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef OCU_STOP_SEC_VAR_INIT_ASIL_B_UNSPECIFIED
  #undef OCU_STOP_SEC_VAR_INIT_ASIL_B_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef OCU_START_SEC_VAR_NO_INIT_ASIL_B_UNSPECIFIED
  #undef OCU_START_SEC_VAR_NO_INIT_ASIL_B_UNSPECIFIED
  #define START_SEC_VAR_NO_INIT_UNSPECIFIED
#endif

#ifdef OCU_STOP_SEC_VAR_NO_INIT_ASIL_B_UNSPECIFIED
  #undef OCU_STOP_SEC_VAR_NO_INIT_ASIL_B_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef PORT_START_SEC_CODE_ASIL_B
  #undef PORT_START_SEC_CODE_ASIL_B
  #define START_SEC_CODE
#endif

#ifdef PORT_STOP_SEC_CODE_ASIL_B
  #undef PORT_STOP_SEC_CODE_ASIL_B
  #define STOP_SEC_CODE
#endif

#ifdef PORT_START_SEC_CONST_ASIL_B_UNSPECIFIED
  #undef PORT_START_SEC_CONST_ASIL_B_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef PORT_STOP_SEC_CONST_ASIL_B_UNSPECIFIED
  #undef PORT_STOP_SEC_CONST_ASIL_B_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef PORT_START_SEC_VAR_INIT_ASIL_B_UNSPECIFIED
  #undef PORT_START_SEC_VAR_INIT_ASIL_B_UNSPECIFIED
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef PORT_STOP_SEC_VAR_INIT_ASIL_B_UNSPECIFIED
  #undef PORT_STOP_SEC_VAR_INIT_ASIL_B_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef PWM_CORE0_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_UNSPECIFIED
  #undef PWM_CORE0_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_UNSPECIFIED
  #define START_SEC_VAR_CLEARED_UNSPECIFIED
#endif

#ifdef PWM_CORE0_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_UNSPECIFIED
  #undef PWM_CORE0_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef PWM_CORE0_START_SEC_VAR_INIT_ASIL_B_GLOBAL_UNSPECIFIED
  #undef PWM_CORE0_START_SEC_VAR_INIT_ASIL_B_GLOBAL_UNSPECIFIED
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef PWM_CORE0_STOP_SEC_VAR_INIT_ASIL_B_GLOBAL_UNSPECIFIED
  #undef PWM_CORE0_STOP_SEC_VAR_INIT_ASIL_B_GLOBAL_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef PWM_START_SEC_CODE_ASIL_B
  #undef PWM_START_SEC_CODE_ASIL_B
  #define START_SEC_CODE
#endif

#ifdef PWM_STOP_SEC_CODE_ASIL_B
  #undef PWM_STOP_SEC_CODE_ASIL_B
  #define STOP_SEC_CODE
#endif

#ifdef PWM_START_SEC_CONST_ASIL_B_UNSPECIFIED
  #undef PWM_START_SEC_CONST_ASIL_B_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef PWM_STOP_SEC_CONST_ASIL_B_UNSPECIFIED
  #undef PWM_STOP_SEC_CONST_ASIL_B_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef PWM_START_SEC_VAR_INIT_ASIL_B_GLOBAL_CORE0_UNSPECIFIED
  #undef PWM_START_SEC_VAR_INIT_ASIL_B_GLOBAL_CORE0_UNSPECIFIED
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef PWM_STOP_SEC_VAR_INIT_ASIL_B_GLOBAL_CORE0_UNSPECIFIED
  #undef PWM_STOP_SEC_VAR_INIT_ASIL_B_GLOBAL_CORE0_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef PWM_START_SEC_VAR_INIT_ASIL_B_UNSPECIFIED
  #undef PWM_START_SEC_VAR_INIT_ASIL_B_UNSPECIFIED
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef PWM_STOP_SEC_VAR_INIT_ASIL_B_UNSPECIFIED
  #undef PWM_STOP_SEC_VAR_INIT_ASIL_B_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef PWM_START_SEC_VAR_NO_INIT_ASIL_B_LOCAL_OR_GLOBAL_CORE0_UNSPECIFIED
  #undef PWM_START_SEC_VAR_NO_INIT_ASIL_B_LOCAL_OR_GLOBAL_CORE0_UNSPECIFIED
  #define START_SEC_VAR_NO_INIT_UNSPECIFIED
#endif

#ifdef PWM_STOP_SEC_VAR_NO_INIT_ASIL_B_LOCAL_OR_GLOBAL_CORE0_UNSPECIFIED
  #undef PWM_STOP_SEC_VAR_NO_INIT_ASIL_B_LOCAL_OR_GLOBAL_CORE0_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef PWM_START_SEC_VAR_NO_INIT_ASIL_B_UNSPECIFIED
  #undef PWM_START_SEC_VAR_NO_INIT_ASIL_B_UNSPECIFIED
  #define START_SEC_VAR_NO_INIT_UNSPECIFIED
#endif

#ifdef PWM_STOP_SEC_VAR_NO_INIT_ASIL_B_UNSPECIFIED
  #undef PWM_STOP_SEC_VAR_NO_INIT_ASIL_B_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef RTE_START_SEC_CODE
  #undef RTE_START_SEC_CODE
  #define START_SEC_CODE
#endif

#ifdef RTE_STOP_SEC_CODE
  #undef RTE_STOP_SEC_CODE
  #define STOP_SEC_CODE
#endif

#ifdef SPI_CORE0_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_UNSPECIFIED
  #undef SPI_CORE0_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_UNSPECIFIED
  #define START_SEC_VAR_CLEARED_UNSPECIFIED
#endif

#ifdef SPI_CORE0_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_UNSPECIFIED
  #undef SPI_CORE0_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef SPI_CORE0_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_32
  #undef SPI_CORE0_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_32
  #define START_SEC_VAR_CLEARED_32
#endif

#ifdef SPI_CORE0_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_32
  #undef SPI_CORE0_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_32
  #define STOP_SEC_VAR
#endif

#ifdef SPI_CORE0_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_UNSPECIFIED
  #undef SPI_CORE0_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_UNSPECIFIED
  #define START_SEC_VAR_CLEARED_UNSPECIFIED
#endif

#ifdef SPI_CORE0_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_UNSPECIFIED
  #undef SPI_CORE0_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef SPI_CORE0_START_SEC_VAR_INIT_ASIL_B_GLOBAL_UNSPECIFIED
  #undef SPI_CORE0_START_SEC_VAR_INIT_ASIL_B_GLOBAL_UNSPECIFIED
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef SPI_CORE0_STOP_SEC_VAR_INIT_ASIL_B_GLOBAL_UNSPECIFIED
  #undef SPI_CORE0_STOP_SEC_VAR_INIT_ASIL_B_GLOBAL_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef SPI_CORE0_START_SEC_VAR_INIT_ASIL_B_LOCAL_UNSPECIFIED
  #undef SPI_CORE0_START_SEC_VAR_INIT_ASIL_B_LOCAL_UNSPECIFIED
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef SPI_CORE0_STOP_SEC_VAR_INIT_ASIL_B_LOCAL_UNSPECIFIED
  #undef SPI_CORE0_STOP_SEC_VAR_INIT_ASIL_B_LOCAL_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef SPI_START_SEC_CODE
  #undef SPI_START_SEC_CODE
  #define START_SEC_CODE
#endif

#ifdef SPI_STOP_SEC_CODE
  #undef SPI_STOP_SEC_CODE
  #define STOP_SEC_CODE
#endif

#ifdef SPI_START_SEC_CODE_ASIL_B
  #undef SPI_START_SEC_CODE_ASIL_B
  #define START_SEC_CODE
#endif

#ifdef SPI_STOP_SEC_CODE_ASIL_B
  #undef SPI_STOP_SEC_CODE_ASIL_B
  #define STOP_SEC_CODE
#endif

#ifdef SPI_START_SEC_CONST_ASIL_B_UNSPECIFIED
  #undef SPI_START_SEC_CONST_ASIL_B_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef SPI_STOP_SEC_CONST_ASIL_B_UNSPECIFIED
  #undef SPI_STOP_SEC_CONST_ASIL_B_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef SPI_START_SEC_VAR_INIT_ASIL_B_8
  #undef SPI_START_SEC_VAR_INIT_ASIL_B_8
  #define START_SEC_VAR_INIT_8
#endif

#ifdef SPI_STOP_SEC_VAR_INIT_ASIL_B_8
  #undef SPI_STOP_SEC_VAR_INIT_ASIL_B_8
  #define STOP_SEC_VAR
#endif

#ifdef SPI_START_SEC_VAR_INIT_ASIL_B_GLOBAL_CORE0_UNSPECIFIED
  #undef SPI_START_SEC_VAR_INIT_ASIL_B_GLOBAL_CORE0_UNSPECIFIED
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef SPI_STOP_SEC_VAR_INIT_ASIL_B_GLOBAL_CORE0_UNSPECIFIED
  #undef SPI_STOP_SEC_VAR_INIT_ASIL_B_GLOBAL_CORE0_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef SPI_START_SEC_VAR_INIT_ASIL_B_LOCAL_CORE0_UNSPECIFIED
  #undef SPI_START_SEC_VAR_INIT_ASIL_B_LOCAL_CORE0_UNSPECIFIED
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef SPI_STOP_SEC_VAR_INIT_ASIL_B_LOCAL_CORE0_UNSPECIFIED
  #undef SPI_STOP_SEC_VAR_INIT_ASIL_B_LOCAL_CORE0_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef SPI_START_SEC_VAR_INIT_ASIL_B_UNSPECIFIED
  #undef SPI_START_SEC_VAR_INIT_ASIL_B_UNSPECIFIED
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef SPI_STOP_SEC_VAR_INIT_ASIL_B_UNSPECIFIED
  #undef SPI_STOP_SEC_VAR_INIT_ASIL_B_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef SPI_START_SEC_VAR_NO_INIT_ASIL_B_32
  #undef SPI_START_SEC_VAR_NO_INIT_ASIL_B_32
  #define START_SEC_VAR_NO_INIT_32
#endif

#ifdef SPI_STOP_SEC_VAR_NO_INIT_ASIL_B_32
  #undef SPI_STOP_SEC_VAR_NO_INIT_ASIL_B_32
  #define STOP_SEC_VAR
#endif

#ifdef SPI_START_SEC_VAR_NO_INIT_ASIL_B_LOCAL_CORE0_32
  #undef SPI_START_SEC_VAR_NO_INIT_ASIL_B_LOCAL_CORE0_32
  #define START_SEC_VAR_NO_INIT_32
#endif

#ifdef SPI_STOP_SEC_VAR_NO_INIT_ASIL_B_LOCAL_CORE0_32
  #undef SPI_STOP_SEC_VAR_NO_INIT_ASIL_B_LOCAL_CORE0_32
  #define STOP_SEC_VAR
#endif

#ifdef SPI_START_SEC_VAR_NO_INIT_ASIL_B_LOCAL_CORE0_UNSPECIFIED
  #undef SPI_START_SEC_VAR_NO_INIT_ASIL_B_LOCAL_CORE0_UNSPECIFIED
  #define START_SEC_VAR_NO_INIT_UNSPECIFIED
#endif

#ifdef SPI_STOP_SEC_VAR_NO_INIT_ASIL_B_LOCAL_CORE0_UNSPECIFIED
  #undef SPI_STOP_SEC_VAR_NO_INIT_ASIL_B_LOCAL_CORE0_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef SPI_START_SEC_VAR_NO_INIT_ASIL_B_LOCAL_OR_GLOBAL_CORE0_UNSPECIFIED
  #undef SPI_START_SEC_VAR_NO_INIT_ASIL_B_LOCAL_OR_GLOBAL_CORE0_UNSPECIFIED
  #define START_SEC_VAR_NO_INIT_UNSPECIFIED
#endif

#ifdef SPI_STOP_SEC_VAR_NO_INIT_ASIL_B_LOCAL_OR_GLOBAL_CORE0_UNSPECIFIED
  #undef SPI_STOP_SEC_VAR_NO_INIT_ASIL_B_LOCAL_OR_GLOBAL_CORE0_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef SPI_START_SEC_VAR_NO_INIT_ASIL_B_UNSPECIFIED
  #undef SPI_START_SEC_VAR_NO_INIT_ASIL_B_UNSPECIFIED
  #define START_SEC_VAR_NO_INIT_UNSPECIFIED
#endif

#ifdef SPI_STOP_SEC_VAR_NO_INIT_ASIL_B_UNSPECIFIED
  #undef SPI_STOP_SEC_VAR_NO_INIT_ASIL_B_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef UART_START_SEC_CODE_ASIL_B
  #undef UART_START_SEC_CODE_ASIL_B
  #define START_SEC_CODE
#endif

#ifdef UART_STOP_SEC_CODE_ASIL_B
  #undef UART_STOP_SEC_CODE_ASIL_B
  #define STOP_SEC_CODE
#endif

#ifdef UART_START_SEC_CONST_ASIL_B_UNSPECIFIED
  #undef UART_START_SEC_CONST_ASIL_B_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef UART_STOP_SEC_CONST_ASIL_B_UNSPECIFIED
  #undef UART_STOP_SEC_CONST_ASIL_B_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef UART_START_SEC_VAR_INIT_ASIL_B_UNSPECIFIED
  #undef UART_START_SEC_VAR_INIT_ASIL_B_UNSPECIFIED
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef UART_STOP_SEC_VAR_INIT_ASIL_B_UNSPECIFIED
  #undef UART_STOP_SEC_VAR_INIT_ASIL_B_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef UART_START_SEC_VAR_NO_INIT_ASIL_B_UNSPECIFIED
  #undef UART_START_SEC_VAR_NO_INIT_ASIL_B_UNSPECIFIED
  #define START_SEC_VAR_NO_INIT_UNSPECIFIED
#endif

#ifdef UART_STOP_SEC_VAR_NO_INIT_ASIL_B_UNSPECIFIED
  #undef UART_STOP_SEC_VAR_NO_INIT_ASIL_B_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef WDG_66_IA_CORE0_START_SEC_VAR_INIT_ASIL_B_GLOBAL_8
  #undef WDG_66_IA_CORE0_START_SEC_VAR_INIT_ASIL_B_GLOBAL_8
  #define START_SEC_VAR_INIT_8
#endif

#ifdef WDG_66_IA_CORE0_STOP_SEC_VAR_INIT_ASIL_B_GLOBAL_8
  #undef WDG_66_IA_CORE0_STOP_SEC_VAR_INIT_ASIL_B_GLOBAL_8
  #define STOP_SEC_VAR
#endif

#ifdef WDG_66_IA_CORE0_START_SEC_VAR_INIT_ASIL_B_GLOBAL_UNSPECIFIED
  #undef WDG_66_IA_CORE0_START_SEC_VAR_INIT_ASIL_B_GLOBAL_UNSPECIFIED
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef WDG_66_IA_CORE0_STOP_SEC_VAR_INIT_ASIL_B_GLOBAL_UNSPECIFIED
  #undef WDG_66_IA_CORE0_STOP_SEC_VAR_INIT_ASIL_B_GLOBAL_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef WDG_66_IA_CORE0_START_SEC_VAR_INIT_ASIL_B_LOCAL_UNSPECIFIED
  #undef WDG_66_IA_CORE0_START_SEC_VAR_INIT_ASIL_B_LOCAL_UNSPECIFIED
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef WDG_66_IA_CORE0_STOP_SEC_VAR_INIT_ASIL_B_LOCAL_UNSPECIFIED
  #undef WDG_66_IA_CORE0_STOP_SEC_VAR_INIT_ASIL_B_LOCAL_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef WDG_66_IA_START_SEC_CODE
  #undef WDG_66_IA_START_SEC_CODE
  #define START_SEC_CODE
#endif

#ifdef WDG_66_IA_STOP_SEC_CODE
  #undef WDG_66_IA_STOP_SEC_CODE
  #define STOP_SEC_CODE
#endif

#ifdef WDG_66_IA_START_SEC_CODE_ASIL_B
  #undef WDG_66_IA_START_SEC_CODE_ASIL_B
  #define START_SEC_CODE
#endif

#ifdef WDG_66_IA_STOP_SEC_CODE_ASIL_B
  #undef WDG_66_IA_STOP_SEC_CODE_ASIL_B
  #define STOP_SEC_CODE
#endif

#ifdef WDG_66_IA_START_SEC_CONST_32
  #undef WDG_66_IA_START_SEC_CONST_32
  #define START_SEC_CONST_32
#endif

#ifdef WDG_66_IA_STOP_SEC_CONST_32
  #undef WDG_66_IA_STOP_SEC_CONST_32
  #define STOP_SEC_CONST
#endif

#ifdef WDG_66_IA_START_SEC_CONST_ASIL_B_32
  #undef WDG_66_IA_START_SEC_CONST_ASIL_B_32
  #define START_SEC_CONST_32
#endif

#ifdef WDG_66_IA_STOP_SEC_CONST_ASIL_B_32
  #undef WDG_66_IA_STOP_SEC_CONST_ASIL_B_32
  #define STOP_SEC_CONST
#endif

#ifdef WDG_66_IA_START_SEC_CONST_ASIL_B_UNSPECIFIED
  #undef WDG_66_IA_START_SEC_CONST_ASIL_B_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef WDG_66_IA_STOP_SEC_CONST_ASIL_B_UNSPECIFIED
  #undef WDG_66_IA_STOP_SEC_CONST_ASIL_B_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef WDG_66_IA_START_SEC_CONST_UNSPECIFIED
  #undef WDG_66_IA_START_SEC_CONST_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef WDG_66_IA_STOP_SEC_CONST_UNSPECIFIED
  #undef WDG_66_IA_STOP_SEC_CONST_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef WDG_66_IA_START_SEC_VAR_INIT_16
  #undef WDG_66_IA_START_SEC_VAR_INIT_16
  #define START_SEC_VAR_INIT_16
#endif

#ifdef WDG_66_IA_STOP_SEC_VAR_INIT_16
  #undef WDG_66_IA_STOP_SEC_VAR_INIT_16
  #define STOP_SEC_VAR
#endif

#ifdef WDG_66_IA_START_SEC_VAR_INIT_32
  #undef WDG_66_IA_START_SEC_VAR_INIT_32
  #define START_SEC_VAR_INIT_32
#endif

#ifdef WDG_66_IA_STOP_SEC_VAR_INIT_32
  #undef WDG_66_IA_STOP_SEC_VAR_INIT_32
  #define STOP_SEC_VAR
#endif

#ifdef WDG_66_IA_START_SEC_VAR_INIT_8
  #undef WDG_66_IA_START_SEC_VAR_INIT_8
  #define START_SEC_VAR_INIT_8
#endif

#ifdef WDG_66_IA_STOP_SEC_VAR_INIT_8
  #undef WDG_66_IA_STOP_SEC_VAR_INIT_8
  #define STOP_SEC_VAR
#endif

#ifdef WDG_66_IA_START_SEC_VAR_INIT_ASIL_B_16
  #undef WDG_66_IA_START_SEC_VAR_INIT_ASIL_B_16
  #define START_SEC_VAR_INIT_16
#endif

#ifdef WDG_66_IA_STOP_SEC_VAR_INIT_ASIL_B_16
  #undef WDG_66_IA_STOP_SEC_VAR_INIT_ASIL_B_16
  #define STOP_SEC_VAR
#endif

#ifdef WDG_66_IA_START_SEC_VAR_INIT_ASIL_B_8
  #undef WDG_66_IA_START_SEC_VAR_INIT_ASIL_B_8
  #define START_SEC_VAR_INIT_8
#endif

#ifdef WDG_66_IA_STOP_SEC_VAR_INIT_ASIL_B_8
  #undef WDG_66_IA_STOP_SEC_VAR_INIT_ASIL_B_8
  #define STOP_SEC_VAR
#endif

#ifdef WDG_66_IA_START_SEC_VAR_INIT_ASIL_B_UNSPECIFIED
  #undef WDG_66_IA_START_SEC_VAR_INIT_ASIL_B_UNSPECIFIED
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef WDG_66_IA_STOP_SEC_VAR_INIT_ASIL_B_UNSPECIFIED
  #undef WDG_66_IA_STOP_SEC_VAR_INIT_ASIL_B_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef WDG_66_IA_START_SEC_VAR_INIT_GLOBAL_CORE0_8
  #undef WDG_66_IA_START_SEC_VAR_INIT_GLOBAL_CORE0_8
  #define START_SEC_VAR_INIT_8
#endif

#ifdef WDG_66_IA_STOP_SEC_VAR_INIT_GLOBAL_CORE0_8
  #undef WDG_66_IA_STOP_SEC_VAR_INIT_GLOBAL_CORE0_8
  #define STOP_SEC_VAR
#endif

#ifdef WDG_66_IA_START_SEC_VAR_INIT_GLOBAL_CORE0_UNSPECIFIED
  #undef WDG_66_IA_START_SEC_VAR_INIT_GLOBAL_CORE0_UNSPECIFIED
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef WDG_66_IA_STOP_SEC_VAR_INIT_GLOBAL_CORE0_UNSPECIFIED
  #undef WDG_66_IA_STOP_SEC_VAR_INIT_GLOBAL_CORE0_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef WDG_66_IA_START_SEC_VAR_INIT_LOCAL_CORE0_UNSPECIFIED
  #undef WDG_66_IA_START_SEC_VAR_INIT_LOCAL_CORE0_UNSPECIFIED
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef WDG_66_IA_STOP_SEC_VAR_INIT_LOCAL_CORE0_UNSPECIFIED
  #undef WDG_66_IA_STOP_SEC_VAR_INIT_LOCAL_CORE0_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef WDG_66_IA_START_SEC_VAR_INIT_UNSPECIFIED
  #undef WDG_66_IA_START_SEC_VAR_INIT_UNSPECIFIED
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef WDG_66_IA_STOP_SEC_VAR_INIT_UNSPECIFIED
  #undef WDG_66_IA_STOP_SEC_VAR_INIT_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef WDG_CORE0_66_IA_START_SEC_VAR_INIT_ASIL_B_GLOBAL_8
  #undef WDG_CORE0_66_IA_START_SEC_VAR_INIT_ASIL_B_GLOBAL_8
  #define START_SEC_VAR_INIT_8
#endif

#ifdef WDG_CORE0_66_IA_STOP_SEC_VAR_INIT_ASIL_B_GLOBAL_8
  #undef WDG_CORE0_66_IA_STOP_SEC_VAR_INIT_ASIL_B_GLOBAL_8
  #define STOP_SEC_VAR
#endif

#ifdef WDG_CORE0_66_IA_START_SEC_VAR_INIT_ASIL_B_GLOBAL_UNSPECIFIED
  #undef WDG_CORE0_66_IA_START_SEC_VAR_INIT_ASIL_B_GLOBAL_UNSPECIFIED
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef WDG_CORE0_66_IA_STOP_SEC_VAR_INIT_ASIL_B_GLOBAL_UNSPECIFIED
  #undef WDG_CORE0_66_IA_STOP_SEC_VAR_INIT_ASIL_B_GLOBAL_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef WDG_CORE0_66_IA_START_SEC_VAR_INIT_ASIL_B_LOCAL_UNSPECIFIED
  #undef WDG_CORE0_66_IA_START_SEC_VAR_INIT_ASIL_B_LOCAL_UNSPECIFIED
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef WDG_CORE0_66_IA_STOP_SEC_VAR_INIT_ASIL_B_LOCAL_UNSPECIFIED
  #undef WDG_CORE0_66_IA_STOP_SEC_VAR_INIT_ASIL_B_LOCAL_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef WDG_CORE0_66_IA_START_SEC_VAR_INIT_GLOBAL_8
  #undef WDG_CORE0_66_IA_START_SEC_VAR_INIT_GLOBAL_8
  #define START_SEC_VAR_INIT_8
#endif

#ifdef WDG_CORE0_66_IA_STOP_SEC_VAR_INIT_GLOBAL_8
  #undef WDG_CORE0_66_IA_STOP_SEC_VAR_INIT_GLOBAL_8
  #define STOP_SEC_VAR
#endif

#ifdef WDG_CORE0_66_IA_START_SEC_VAR_INIT_GLOBAL_UNSPECIFIED
  #undef WDG_CORE0_66_IA_START_SEC_VAR_INIT_GLOBAL_UNSPECIFIED
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef WDG_CORE0_66_IA_STOP_SEC_VAR_INIT_GLOBAL_UNSPECIFIED
  #undef WDG_CORE0_66_IA_STOP_SEC_VAR_INIT_GLOBAL_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef WDG_CORE0_66_IA_START_SEC_VAR_INIT_LOCAL_UNSPECIFIED
  #undef WDG_CORE0_66_IA_START_SEC_VAR_INIT_LOCAL_UNSPECIFIED
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef WDG_CORE0_66_IA_STOP_SEC_VAR_INIT_LOCAL_UNSPECIFIED
  #undef WDG_CORE0_66_IA_STOP_SEC_VAR_INIT_LOCAL_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
* 3rdParty_Mcal END
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  CSM START
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#if defined (CSM_START_SEC_CODE)
# undef CSM_START_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE                                               /* mapped to default code section */
#endif
#if defined (CSM_STOP_SEC_CODE)
# undef CSM_STOP_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE                                                /* default code stop section */
#endif

#if defined (CSM_START_SEC_APPL_CODE)
# undef CSM_START_SEC_APPL_CODE  /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE                                               /* mapped to default code section */
#endif
#if defined (CSM_STOP_SEC_APPL_CODE)
# undef CSM_STOP_SEC_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE                                                /* default code stop section */
#endif

/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#if defined (CSM_START_SEC_CONST_8BIT)
# undef CSM_START_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_8BIT
#endif

#if defined (CSM_STOP_SEC_CONST_8BIT)
# undef CSM_STOP_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined (CSM_START_SEC_CONST_UNSPECIFIED)
# undef CSM_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#if defined (CSM_STOP_SEC_CONST_UNSPECIFIED)
# undef CSM_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

/* VAR NOINIT sections */

#if defined (CSM_START_SEC_VAR_NOINIT_8BIT)
# undef CSM_START_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_8BIT
#endif
#if defined (CSM_STOP_SEC_VAR_NOINIT_8BIT)
# undef CSM_STOP_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined (CSM_START_SEC_VAR_NOINIT_16BIT)
# undef CSM_START_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_16BIT
#endif
#if defined (CSM_STOP_SEC_VAR_NOINIT_16BIT)
# undef CSM_STOP_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR ZERO INIT sections */
#if defined (CSM_START_SEC_VAR_ZERO_INIT_8BIT)
# undef CSM_START_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#if defined (CSM_STOP_SEC_VAR_ZERO_INIT_8BIT)
# undef CSM_STOP_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined (CSM_START_SEC_VAR_ZERO_INIT_32BIT)
# undef CSM_START_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_32BIT
#endif
#if defined (CSM_STOP_SEC_VAR_ZERO_INIT_32BIT)
# undef CSM_STOP_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined (CSM_START_SEC_VAR_NOINIT_UNSPECIFIED)
# undef CSM_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#if defined (CSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
# undef CSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  CSM END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  WDGM START
 *********************************************************************************************************************/

#include "WdgM_OsMemMap.h"

/*******  CODE sections **********************************************************************************************/

#if defined WDGM_START_SEC_CODE_ASIL_D
# undef WDGM_START_SEC_CODE_ASIL_D /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE
#endif
#if defined WDGM_STOP_SEC_CODE_ASIL_D
# undef WDGM_STOP_SEC_CODE_ASIL_D /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE
#endif

#if defined(WDGM_START_SEC_CALLOUT_CODE_ASIL_D)
# undef WDGM_START_SEC_CALLOUT_CODE_ASIL_D /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE
#endif
#if defined(WDGM_STOP_SEC_CALLOUT_CODE_ASIL_D)
# undef WDGM_STOP_SEC_CALLOUT_CODE_ASIL_D /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE
#endif


/*******  CONST sections  ********************************************************************************************/

#if defined WDGM_START_SEC_CONST_ASIL_D_LOCAL_8
# undef WDGM_START_SEC_CONST_ASIL_D_LOCAL_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_8
#endif
#if defined WDGM_STOP_SEC_CONST_ASIL_D_LOCAL_8
# undef WDGM_STOP_SEC_CONST_ASIL_D_LOCAL_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined WDGM_START_SEC_CONST_ASIL_D_LOCAL_16
# undef WDGM_START_SEC_CONST_ASIL_D_LOCAL_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_16
#endif
#if defined WDGM_STOP_SEC_CONST_ASIL_D_LOCAL_16
# undef WDGM_STOP_SEC_CONST_ASIL_D_LOCAL_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined WDGM_START_SEC_CONST_ASIL_D_LOCAL_32
# undef WDGM_START_SEC_CONST_ASIL_D_LOCAL_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_32
#endif
#if defined WDGM_STOP_SEC_CONST_ASIL_D_LOCAL_32
# undef WDGM_STOP_SEC_CONST_ASIL_D_LOCAL_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined WDGM_START_SEC_CONST_ASIL_D_LOCAL_UNSPECIFIED
# undef WDGM_START_SEC_CONST_ASIL_D_LOCAL_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#if defined WDGM_STOP_SEC_CONST_ASIL_D_LOCAL_UNSPECIFIED
# undef WDGM_STOP_SEC_CONST_ASIL_D_LOCAL_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR CLEARED sections */

#if defined WDGM_START_SEC_VAR_CLEARED_ASIL_D_LOCAL_UNSPECIFIED
# undef WDGM_START_SEC_VAR_CLEARED_ASIL_D_LOCAL_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_CLEARED_UNSPECIFIED
#endif
#if defined WDGM_STOP_SEC_VAR_CLEARED_ASIL_D_LOCAL_UNSPECIFIED
# undef WDGM_STOP_SEC_VAR_CLEARED_ASIL_D_LOCAL_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined WDGM_START_SEC_VAR_CLEARED_ASIL_D_LOCAL_8
# undef WDGM_START_SEC_VAR_CLEARED_ASIL_D_LOCAL_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_CLEARED_8
#endif
#if defined WDGM_STOP_SEC_VAR_CLEARED_ASIL_D_LOCAL_8
# undef WDGM_STOP_SEC_VAR_CLEARED_ASIL_D_LOCAL_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined WDGM_START_SEC_VAR_CLEARED_ASIL_D_LOCAL_16
# undef WDGM_START_SEC_VAR_CLEARED_ASIL_D_LOCAL_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_CLEARED_16
#endif
#if defined WDGM_STOP_SEC_VAR_CLEARED_ASIL_D_LOCAL_16
# undef WDGM_STOP_SEC_VAR_CLEARED_ASIL_D_LOCAL_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined WDGM_START_SEC_VAR_CLEARED_ASIL_D_LOCAL_32
# undef WDGM_START_SEC_VAR_CLEARED_ASIL_D_LOCAL_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_CLEARED_32
#endif
#if defined WDGM_STOP_SEC_VAR_CLEARED_ASIL_D_LOCAL_32
# undef WDGM_STOP_SEC_VAR_CLEARED_ASIL_D_LOCAL_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR INIT sections */

#if defined WDGM_START_SEC_VAR_INIT_ASIL_D_LOCAL_32
# undef WDGM_START_SEC_VAR_INIT_ASIL_D_LOCAL_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_32
#endif
#if defined WDGM_STOP_SEC_VAR_INIT_ASIL_D_LOCAL_32
# undef WDGM_STOP_SEC_VAR_INIT_ASIL_D_LOCAL_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  WDGM END
 *********************************************************************************************************************/

#ifdef DET_START_SEC_CODE
# undef DET_START_SEC_CODE                    /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE
#endif
#ifdef DET_STOP_SEC_CODE
# undef DET_STOP_SEC_CODE                     /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE
#endif

#ifdef DET_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef DET_START_SEC_VAR_NOINIT_UNSPECIFIED  /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef DET_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef DET_STOP_SEC_VAR_NOINIT_UNSPECIFIED   /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef DET_START_SEC_VAR_NOINIT_8BIT
# undef DET_START_SEC_VAR_NOINIT_8BIT         /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef DET_STOP_SEC_VAR_NOINIT_8BIT
# undef DET_STOP_SEC_VAR_NOINIT_8BIT          /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef DET_START_SEC_VAR_INIT_UNSPECIFIED
# undef DET_START_SEC_VAR_INIT_UNSPECIFIED    /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#ifdef DET_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef DET_STOP_SEC_VAR_INIT_UNSPECIFIED     /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef DET_START_SEC_CONST_UNSPECIFIED
# undef DET_START_SEC_CONST_UNSPECIFIED       /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef DET_STOP_SEC_CONST_UNSPECIFIED
# undef DET_STOP_SEC_CONST_UNSPECIFIED        /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

/* E2EPW_MemMap.inc: End-To-End Protection Wrapper Memory Mapping: */


/* Code */
/* To be used for mapping code to application block, boot block, external flash etc. */
#if defined   E2EPW_START_SEC_CODE
#undef        E2EPW_START_SEC_CODE
#define           START_SEC_CODE

#elif defined E2EPW_STOP_SEC_CODE
#undef        E2EPW_STOP_SEC_CODE
#define             STOP_SEC_CODE


/* Constants */
/* To be used for global or static constants.  */
#elif defined E2EPW_START_SEC_CONST_UNSPECIFIED
#undef        E2EPW_START_SEC_CONST_UNSPECIFIED
#define             START_SEC_CONST_UNSPECIFIED

#elif defined E2EPW_STOP_SEC_CONST_UNSPECIFIED
#undef        E2EPW_STOP_SEC_CONST_UNSPECIFIED
#define             STOP_SEC_CONST


/* Var init unspecified */
#elif defined E2EPW_START_SEC_VAR_INIT_UNSPECIFIED
#undef        E2EPW_START_SEC_VAR_INIT_UNSPECIFIED
#define             START_SEC_VAR_INIT_UNSPECIFIED

#elif defined E2EPW_STOP_SEC_VAR_INIT_UNSPECIFIED
#undef        E2EPW_STOP_SEC_VAR_INIT_UNSPECIFIED
#define             STOP_SEC_VAR


/* Var uninitialized unspecified */
/* To be used for all global or static variables that are never initialized */
#elif defined E2EPW_START_SEC_VAR_NOINIT_UNSPECIFIED
#undef        E2EPW_START_SEC_VAR_NOINIT_UNSPECIFIED
#define             START_SEC_VAR_NOINIT_UNSPECIFIED

#elif defined E2EPW_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#undef        E2EPW_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#define             STOP_SEC_VAR


/* Var zero init unspecified */
#elif defined E2EPW_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#undef        E2EPW_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#define             START_SEC_VAR_ZERO_INIT_UNSPECIFIED

#elif defined E2EPW_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
#undef        E2EPW_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
#define             STOP_SEC_VAR


/* Library code     */
/* To be used for code that shall go into library segments for <MSN> module. */
#elif defined E2EPW_START_SEC_CODE_LIB
#undef        E2EPW_START_SEC_CODE_LIB
#define             START_SEC_CODE

#elif defined E2EPW_STOP_SEC_CODE_LIB
#undef        E2EPW_STOP_SEC_CODE_LIB
#define             STOP_SEC_CODE

#endif

/* End of file E2EPW_MemMap.inc */


/**********************************************************************************************************************
 *  VSTDLIB START
 *********************************************************************************************************************/

#if defined(VSTDLIB_START_SEC_CODE)
# undef VSTDLIB_START_SEC_CODE                             /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE                                    /* mapped to default code section */
#endif
#if defined(VSTDLIB_STOP_SEC_CODE)
# undef VSTDLIB_STOP_SEC_CODE                              /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE
#endif

#if defined(VSTDLIB_START_SEC_CONST_8BIT)
# undef VSTDLIB_START_SEC_CONST_8BIT                       /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_8BIT                              /* mapped to const 8 bit section */
#endif
#if defined(VSTDLIB_STOP_SEC_CONST_8BIT)
# undef VSTDLIB_STOP_SEC_CONST_8BIT                        /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST                                    /* default const stop section */
#endif

/**********************************************************************************************************************
 *  VSTDLIB END
 *********************************************************************************************************************/



/* PRQA L:MEMMAP_0841_TAG */

/* MEMMAP_REMAPPING_ONLY is set if the MemMap is only used to remap Memory Allocation Keywords.
   If not set the Memory Allocation Keywords will be resolved to pragmas */
#ifndef MEMMAP_REMAPPING_ONLY
# include "MemMap_Common.h"

/* MEMMAP_ERROR is
  - still defined if MemMap_Common.h did not contain a matching section
  - undefined, if MemMap_Common.h handled the section define. */
# ifdef MEMMAP_ERROR
/* contains all configured MemMap Sections */
#  include "MemMap_Compatibility.h" /* generated by module MemMap */
# endif

# ifdef MEMMAP_ERROR
#  error No MemMap section found in MemMap_Common.h and MemMap_Compatibility.h. Check your section define for validity.
# endif
#endif


/**********************************************************************************************************************
 *  END OF FILE: MemMap.h
 *********************************************************************************************************************/

