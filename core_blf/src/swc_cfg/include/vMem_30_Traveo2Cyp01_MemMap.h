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
 *            Module: MemMap
 *           Program: MSR_Geely_SLP2
 *          Customer: Marelli Automotive Electronics (Guangzhou) Co., Ltd
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: CYT2B75BA
 *    License Scope : The usage is restricted to CBD2600619_D00
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: vMem_30_Traveo2Cyp01_MemMap.h
 *   Generation Time: 2026-07-14 11:05:46
 *           Project: DaVinci_Zeekr_Display - Version 1.0
 *          Delivery: CBD2600619_D00
 *      Tool Version: DaVinci Configurator Classic (beta) 5.31.60 SP6
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

/* PRQA S 0883 EOF */ /* MD_MSR_MemMap */

#ifndef MICROSAR_DISABLE_MEMMAP

/**********************************************************************************************************************
 *  PRE USER CONFIG FILE
 *********************************************************************************************************************/

/* User Config File Start */

/* User Config File End */

/**********************************************************************************************************************
 *  MEMMAP SECTIONS
 *********************************************************************************************************************/

#define MEMMAP_ERROR

#if defined VMEM_30_TRAVEO2CYP01_START_SEC_APPL_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using VMEM_30_TRAVEO2CYP01_START_SEC_APPL_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VMEM_30_TRAVEO2CYP01_APPL_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef VMEM_30_TRAVEO2CYP01_START_SEC_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined VMEM_30_TRAVEO2CYP01_STOP_SEC_APPL_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using VMEM_30_TRAVEO2CYP01_STOP_SEC_APPL_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VMEM_30_TRAVEO2CYP01_APPL_CODE_OPEN
#  error Using VMEM_30_TRAVEO2CYP01_STOP_SEC_APPL_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef VMEM_30_TRAVEO2CYP01_APPL_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef VMEM_30_TRAVEO2CYP01_STOP_SEC_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined VMEM_30_TRAVEO2CYP01_START_SEC_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using VMEM_30_TRAVEO2CYP01_START_SEC_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VMEM_30_TRAVEO2CYP01_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef VMEM_30_TRAVEO2CYP01_START_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined VMEM_30_TRAVEO2CYP01_STOP_SEC_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using VMEM_30_TRAVEO2CYP01_STOP_SEC_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VMEM_30_TRAVEO2CYP01_CODE_OPEN
#  error Using VMEM_30_TRAVEO2CYP01_STOP_SEC_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef VMEM_30_TRAVEO2CYP01_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef VMEM_30_TRAVEO2CYP01_STOP_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined VMEM_30_TRAVEO2CYP01_START_SEC_CONST_16
# ifdef MEMMAP_SECTION_OPEN
#  error Using VMEM_30_TRAVEO2CYP01_START_SEC_CONST_16 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VMEM_30_TRAVEO2CYP01_CONST_16_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_CONST/MSR_CONST */
# pragma ghs section rodata = ".MSR_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef VMEM_30_TRAVEO2CYP01_START_SEC_CONST_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined VMEM_30_TRAVEO2CYP01_STOP_SEC_CONST_16
# ifndef MEMMAP_SECTION_OPEN
#  error Using VMEM_30_TRAVEO2CYP01_STOP_SEC_CONST_16 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VMEM_30_TRAVEO2CYP01_CONST_16_OPEN
#  error Using VMEM_30_TRAVEO2CYP01_STOP_SEC_CONST_16 is not possible as the corresponding memory section has not been opened.
# endif
# undef VMEM_30_TRAVEO2CYP01_CONST_16_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_CONST/MSR_CONST */
# pragma ghs section rodata = default /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef VMEM_30_TRAVEO2CYP01_STOP_SEC_CONST_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined VMEM_30_TRAVEO2CYP01_START_SEC_CONST_32
# ifdef MEMMAP_SECTION_OPEN
#  error Using VMEM_30_TRAVEO2CYP01_START_SEC_CONST_32 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VMEM_30_TRAVEO2CYP01_CONST_32_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_CONST/MSR_CONST */
# pragma ghs section rodata = ".MSR_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef VMEM_30_TRAVEO2CYP01_START_SEC_CONST_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined VMEM_30_TRAVEO2CYP01_STOP_SEC_CONST_32
# ifndef MEMMAP_SECTION_OPEN
#  error Using VMEM_30_TRAVEO2CYP01_STOP_SEC_CONST_32 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VMEM_30_TRAVEO2CYP01_CONST_32_OPEN
#  error Using VMEM_30_TRAVEO2CYP01_STOP_SEC_CONST_32 is not possible as the corresponding memory section has not been opened.
# endif
# undef VMEM_30_TRAVEO2CYP01_CONST_32_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_CONST/MSR_CONST */
# pragma ghs section rodata = default /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef VMEM_30_TRAVEO2CYP01_STOP_SEC_CONST_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined VMEM_30_TRAVEO2CYP01_START_SEC_CONST_64
# ifdef MEMMAP_SECTION_OPEN
#  error Using VMEM_30_TRAVEO2CYP01_START_SEC_CONST_64 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VMEM_30_TRAVEO2CYP01_CONST_64_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_CONST/MSR_CONST */
# pragma ghs section rodata = ".MSR_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef VMEM_30_TRAVEO2CYP01_START_SEC_CONST_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined VMEM_30_TRAVEO2CYP01_STOP_SEC_CONST_64
# ifndef MEMMAP_SECTION_OPEN
#  error Using VMEM_30_TRAVEO2CYP01_STOP_SEC_CONST_64 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VMEM_30_TRAVEO2CYP01_CONST_64_OPEN
#  error Using VMEM_30_TRAVEO2CYP01_STOP_SEC_CONST_64 is not possible as the corresponding memory section has not been opened.
# endif
# undef VMEM_30_TRAVEO2CYP01_CONST_64_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_CONST/MSR_CONST */
# pragma ghs section rodata = default /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef VMEM_30_TRAVEO2CYP01_STOP_SEC_CONST_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined VMEM_30_TRAVEO2CYP01_START_SEC_CONST_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using VMEM_30_TRAVEO2CYP01_START_SEC_CONST_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VMEM_30_TRAVEO2CYP01_CONST_8_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_CONST/MSR_CONST */
# pragma ghs section rodata = ".MSR_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef VMEM_30_TRAVEO2CYP01_START_SEC_CONST_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined VMEM_30_TRAVEO2CYP01_STOP_SEC_CONST_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using VMEM_30_TRAVEO2CYP01_STOP_SEC_CONST_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VMEM_30_TRAVEO2CYP01_CONST_8_OPEN
#  error Using VMEM_30_TRAVEO2CYP01_STOP_SEC_CONST_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef VMEM_30_TRAVEO2CYP01_CONST_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_CONST/MSR_CONST */
# pragma ghs section rodata = default /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef VMEM_30_TRAVEO2CYP01_STOP_SEC_CONST_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined VMEM_30_TRAVEO2CYP01_START_SEC_CONST_PBCFG
# ifdef MEMMAP_SECTION_OPEN
#  error Using VMEM_30_TRAVEO2CYP01_START_SEC_CONST_PBCFG is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VMEM_30_TRAVEO2CYP01_CONST_PBCFG_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_PBCFG_CONST/MSR_PBCFG_CONST */
# pragma ghs section rodata = ".MSR_PBCFG_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef VMEM_30_TRAVEO2CYP01_START_SEC_CONST_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined VMEM_30_TRAVEO2CYP01_STOP_SEC_CONST_PBCFG
# ifndef MEMMAP_SECTION_OPEN
#  error Using VMEM_30_TRAVEO2CYP01_STOP_SEC_CONST_PBCFG is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VMEM_30_TRAVEO2CYP01_CONST_PBCFG_OPEN
#  error Using VMEM_30_TRAVEO2CYP01_STOP_SEC_CONST_PBCFG is not possible as the corresponding memory section has not been opened.
# endif
# undef VMEM_30_TRAVEO2CYP01_CONST_PBCFG_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_PBCFG_CONST/MSR_PBCFG_CONST */
# pragma ghs section rodata = default /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef VMEM_30_TRAVEO2CYP01_STOP_SEC_CONST_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined VMEM_30_TRAVEO2CYP01_START_SEC_CONST_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using VMEM_30_TRAVEO2CYP01_START_SEC_CONST_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VMEM_30_TRAVEO2CYP01_CONST_UNSPECIFIED_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_CONST/MSR_CONST */
# pragma ghs section rodata = ".MSR_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef VMEM_30_TRAVEO2CYP01_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined VMEM_30_TRAVEO2CYP01_STOP_SEC_CONST_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using VMEM_30_TRAVEO2CYP01_STOP_SEC_CONST_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VMEM_30_TRAVEO2CYP01_CONST_UNSPECIFIED_OPEN
#  error Using VMEM_30_TRAVEO2CYP01_STOP_SEC_CONST_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef VMEM_30_TRAVEO2CYP01_CONST_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_CONST/MSR_CONST */
# pragma ghs section rodata = default /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef VMEM_30_TRAVEO2CYP01_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined VMEM_30_TRAVEO2CYP01_START_SEC_PBCFG
# ifdef MEMMAP_SECTION_OPEN
#  error Using VMEM_30_TRAVEO2CYP01_START_SEC_PBCFG is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VMEM_30_TRAVEO2CYP01_PBCFG_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_PBCFG_CONST/MSR_PBCFG_CONST */
# pragma ghs section rodata = ".MSR_PBCFG_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef VMEM_30_TRAVEO2CYP01_START_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined VMEM_30_TRAVEO2CYP01_STOP_SEC_PBCFG
# ifndef MEMMAP_SECTION_OPEN
#  error Using VMEM_30_TRAVEO2CYP01_STOP_SEC_PBCFG is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VMEM_30_TRAVEO2CYP01_PBCFG_OPEN
#  error Using VMEM_30_TRAVEO2CYP01_STOP_SEC_PBCFG is not possible as the corresponding memory section has not been opened.
# endif
# undef VMEM_30_TRAVEO2CYP01_PBCFG_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_PBCFG_CONST/MSR_PBCFG_CONST */
# pragma ghs section rodata = default /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef VMEM_30_TRAVEO2CYP01_STOP_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined VMEM_30_TRAVEO2CYP01_START_SEC_VAR_CLEARED_16
# ifdef MEMMAP_SECTION_OPEN
#  error Using VMEM_30_TRAVEO2CYP01_START_SEC_VAR_CLEARED_16 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VMEM_30_TRAVEO2CYP01_VAR_CLEARED_16_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma ghs section bss = ".MSR_VAR_CLEARED" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma ghs section data = ".MSR_VAR_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef VMEM_30_TRAVEO2CYP01_START_SEC_VAR_CLEARED_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined VMEM_30_TRAVEO2CYP01_STOP_SEC_VAR_CLEARED_16
# ifndef MEMMAP_SECTION_OPEN
#  error Using VMEM_30_TRAVEO2CYP01_STOP_SEC_VAR_CLEARED_16 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VMEM_30_TRAVEO2CYP01_VAR_CLEARED_16_OPEN
#  error Using VMEM_30_TRAVEO2CYP01_STOP_SEC_VAR_CLEARED_16 is not possible as the corresponding memory section has not been opened.
# endif
# undef VMEM_30_TRAVEO2CYP01_VAR_CLEARED_16_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma ghs section bss = default /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma ghs section data = default /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef VMEM_30_TRAVEO2CYP01_STOP_SEC_VAR_CLEARED_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined VMEM_30_TRAVEO2CYP01_START_SEC_VAR_CLEARED_32
# ifdef MEMMAP_SECTION_OPEN
#  error Using VMEM_30_TRAVEO2CYP01_START_SEC_VAR_CLEARED_32 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VMEM_30_TRAVEO2CYP01_VAR_CLEARED_32_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma ghs section bss = ".MSR_VAR_CLEARED" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma ghs section data = ".MSR_VAR_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef VMEM_30_TRAVEO2CYP01_START_SEC_VAR_CLEARED_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined VMEM_30_TRAVEO2CYP01_STOP_SEC_VAR_CLEARED_32
# ifndef MEMMAP_SECTION_OPEN
#  error Using VMEM_30_TRAVEO2CYP01_STOP_SEC_VAR_CLEARED_32 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VMEM_30_TRAVEO2CYP01_VAR_CLEARED_32_OPEN
#  error Using VMEM_30_TRAVEO2CYP01_STOP_SEC_VAR_CLEARED_32 is not possible as the corresponding memory section has not been opened.
# endif
# undef VMEM_30_TRAVEO2CYP01_VAR_CLEARED_32_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma ghs section bss = default /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma ghs section data = default /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef VMEM_30_TRAVEO2CYP01_STOP_SEC_VAR_CLEARED_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined VMEM_30_TRAVEO2CYP01_START_SEC_VAR_CLEARED_64
# ifdef MEMMAP_SECTION_OPEN
#  error Using VMEM_30_TRAVEO2CYP01_START_SEC_VAR_CLEARED_64 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VMEM_30_TRAVEO2CYP01_VAR_CLEARED_64_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma ghs section bss = ".MSR_VAR_CLEARED" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma ghs section data = ".MSR_VAR_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef VMEM_30_TRAVEO2CYP01_START_SEC_VAR_CLEARED_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined VMEM_30_TRAVEO2CYP01_STOP_SEC_VAR_CLEARED_64
# ifndef MEMMAP_SECTION_OPEN
#  error Using VMEM_30_TRAVEO2CYP01_STOP_SEC_VAR_CLEARED_64 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VMEM_30_TRAVEO2CYP01_VAR_CLEARED_64_OPEN
#  error Using VMEM_30_TRAVEO2CYP01_STOP_SEC_VAR_CLEARED_64 is not possible as the corresponding memory section has not been opened.
# endif
# undef VMEM_30_TRAVEO2CYP01_VAR_CLEARED_64_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma ghs section bss = default /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma ghs section data = default /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef VMEM_30_TRAVEO2CYP01_STOP_SEC_VAR_CLEARED_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined VMEM_30_TRAVEO2CYP01_START_SEC_VAR_CLEARED_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using VMEM_30_TRAVEO2CYP01_START_SEC_VAR_CLEARED_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VMEM_30_TRAVEO2CYP01_VAR_CLEARED_8_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma ghs section bss = ".MSR_VAR_CLEARED" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma ghs section data = ".MSR_VAR_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef VMEM_30_TRAVEO2CYP01_START_SEC_VAR_CLEARED_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined VMEM_30_TRAVEO2CYP01_STOP_SEC_VAR_CLEARED_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using VMEM_30_TRAVEO2CYP01_STOP_SEC_VAR_CLEARED_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VMEM_30_TRAVEO2CYP01_VAR_CLEARED_8_OPEN
#  error Using VMEM_30_TRAVEO2CYP01_STOP_SEC_VAR_CLEARED_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef VMEM_30_TRAVEO2CYP01_VAR_CLEARED_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma ghs section bss = default /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma ghs section data = default /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef VMEM_30_TRAVEO2CYP01_STOP_SEC_VAR_CLEARED_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined VMEM_30_TRAVEO2CYP01_START_SEC_VAR_CLEARED_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using VMEM_30_TRAVEO2CYP01_START_SEC_VAR_CLEARED_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VMEM_30_TRAVEO2CYP01_VAR_CLEARED_UNSPECIFIED_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma ghs section bss = ".MSR_VAR_CLEARED" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma ghs section data = ".MSR_VAR_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef VMEM_30_TRAVEO2CYP01_START_SEC_VAR_CLEARED_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined VMEM_30_TRAVEO2CYP01_STOP_SEC_VAR_CLEARED_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using VMEM_30_TRAVEO2CYP01_STOP_SEC_VAR_CLEARED_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VMEM_30_TRAVEO2CYP01_VAR_CLEARED_UNSPECIFIED_OPEN
#  error Using VMEM_30_TRAVEO2CYP01_STOP_SEC_VAR_CLEARED_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef VMEM_30_TRAVEO2CYP01_VAR_CLEARED_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma ghs section bss = default /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma ghs section data = default /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef VMEM_30_TRAVEO2CYP01_STOP_SEC_VAR_CLEARED_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined VMEM_30_TRAVEO2CYP01_START_SEC_VAR_INIT_16
# ifdef MEMMAP_SECTION_OPEN
#  error Using VMEM_30_TRAVEO2CYP01_START_SEC_VAR_INIT_16 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VMEM_30_TRAVEO2CYP01_VAR_INIT_16_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma ghs section bss = ".MSR_VAR_CLEARED" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma ghs section data = ".MSR_VAR_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef VMEM_30_TRAVEO2CYP01_START_SEC_VAR_INIT_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined VMEM_30_TRAVEO2CYP01_STOP_SEC_VAR_INIT_16
# ifndef MEMMAP_SECTION_OPEN
#  error Using VMEM_30_TRAVEO2CYP01_STOP_SEC_VAR_INIT_16 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VMEM_30_TRAVEO2CYP01_VAR_INIT_16_OPEN
#  error Using VMEM_30_TRAVEO2CYP01_STOP_SEC_VAR_INIT_16 is not possible as the corresponding memory section has not been opened.
# endif
# undef VMEM_30_TRAVEO2CYP01_VAR_INIT_16_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma ghs section bss = default /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma ghs section data = default /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef VMEM_30_TRAVEO2CYP01_STOP_SEC_VAR_INIT_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined VMEM_30_TRAVEO2CYP01_START_SEC_VAR_INIT_32
# ifdef MEMMAP_SECTION_OPEN
#  error Using VMEM_30_TRAVEO2CYP01_START_SEC_VAR_INIT_32 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VMEM_30_TRAVEO2CYP01_VAR_INIT_32_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma ghs section bss = ".MSR_VAR_CLEARED" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma ghs section data = ".MSR_VAR_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef VMEM_30_TRAVEO2CYP01_START_SEC_VAR_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined VMEM_30_TRAVEO2CYP01_STOP_SEC_VAR_INIT_32
# ifndef MEMMAP_SECTION_OPEN
#  error Using VMEM_30_TRAVEO2CYP01_STOP_SEC_VAR_INIT_32 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VMEM_30_TRAVEO2CYP01_VAR_INIT_32_OPEN
#  error Using VMEM_30_TRAVEO2CYP01_STOP_SEC_VAR_INIT_32 is not possible as the corresponding memory section has not been opened.
# endif
# undef VMEM_30_TRAVEO2CYP01_VAR_INIT_32_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma ghs section bss = default /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma ghs section data = default /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef VMEM_30_TRAVEO2CYP01_STOP_SEC_VAR_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined VMEM_30_TRAVEO2CYP01_START_SEC_VAR_INIT_64
# ifdef MEMMAP_SECTION_OPEN
#  error Using VMEM_30_TRAVEO2CYP01_START_SEC_VAR_INIT_64 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VMEM_30_TRAVEO2CYP01_VAR_INIT_64_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma ghs section bss = ".MSR_VAR_CLEARED" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma ghs section data = ".MSR_VAR_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef VMEM_30_TRAVEO2CYP01_START_SEC_VAR_INIT_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined VMEM_30_TRAVEO2CYP01_STOP_SEC_VAR_INIT_64
# ifndef MEMMAP_SECTION_OPEN
#  error Using VMEM_30_TRAVEO2CYP01_STOP_SEC_VAR_INIT_64 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VMEM_30_TRAVEO2CYP01_VAR_INIT_64_OPEN
#  error Using VMEM_30_TRAVEO2CYP01_STOP_SEC_VAR_INIT_64 is not possible as the corresponding memory section has not been opened.
# endif
# undef VMEM_30_TRAVEO2CYP01_VAR_INIT_64_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma ghs section bss = default /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma ghs section data = default /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef VMEM_30_TRAVEO2CYP01_STOP_SEC_VAR_INIT_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined VMEM_30_TRAVEO2CYP01_START_SEC_VAR_INIT_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using VMEM_30_TRAVEO2CYP01_START_SEC_VAR_INIT_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VMEM_30_TRAVEO2CYP01_VAR_INIT_8_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma ghs section bss = ".MSR_VAR_CLEARED" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma ghs section data = ".MSR_VAR_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef VMEM_30_TRAVEO2CYP01_START_SEC_VAR_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined VMEM_30_TRAVEO2CYP01_STOP_SEC_VAR_INIT_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using VMEM_30_TRAVEO2CYP01_STOP_SEC_VAR_INIT_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VMEM_30_TRAVEO2CYP01_VAR_INIT_8_OPEN
#  error Using VMEM_30_TRAVEO2CYP01_STOP_SEC_VAR_INIT_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef VMEM_30_TRAVEO2CYP01_VAR_INIT_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma ghs section bss = default /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma ghs section data = default /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef VMEM_30_TRAVEO2CYP01_STOP_SEC_VAR_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined VMEM_30_TRAVEO2CYP01_START_SEC_VAR_INIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using VMEM_30_TRAVEO2CYP01_START_SEC_VAR_INIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VMEM_30_TRAVEO2CYP01_VAR_INIT_UNSPECIFIED_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma ghs section bss = ".MSR_VAR_CLEARED" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma ghs section data = ".MSR_VAR_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef VMEM_30_TRAVEO2CYP01_START_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined VMEM_30_TRAVEO2CYP01_STOP_SEC_VAR_INIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using VMEM_30_TRAVEO2CYP01_STOP_SEC_VAR_INIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VMEM_30_TRAVEO2CYP01_VAR_INIT_UNSPECIFIED_OPEN
#  error Using VMEM_30_TRAVEO2CYP01_STOP_SEC_VAR_INIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef VMEM_30_TRAVEO2CYP01_VAR_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma ghs section bss = default /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma ghs section data = default /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef VMEM_30_TRAVEO2CYP01_STOP_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined VMEM_30_TRAVEO2CYP01_START_SEC_VAR_NO_INIT_16
# ifdef MEMMAP_SECTION_OPEN
#  error Using VMEM_30_TRAVEO2CYP01_START_SEC_VAR_NO_INIT_16 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VMEM_30_TRAVEO2CYP01_VAR_NO_INIT_16_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma ghs section bss = ".MSR_VAR_NO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma ghs section data = ".MSR_VAR_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef VMEM_30_TRAVEO2CYP01_START_SEC_VAR_NO_INIT_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined VMEM_30_TRAVEO2CYP01_STOP_SEC_VAR_NO_INIT_16
# ifndef MEMMAP_SECTION_OPEN
#  error Using VMEM_30_TRAVEO2CYP01_STOP_SEC_VAR_NO_INIT_16 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VMEM_30_TRAVEO2CYP01_VAR_NO_INIT_16_OPEN
#  error Using VMEM_30_TRAVEO2CYP01_STOP_SEC_VAR_NO_INIT_16 is not possible as the corresponding memory section has not been opened.
# endif
# undef VMEM_30_TRAVEO2CYP01_VAR_NO_INIT_16_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma ghs section bss = default /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma ghs section data = default /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef VMEM_30_TRAVEO2CYP01_STOP_SEC_VAR_NO_INIT_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined VMEM_30_TRAVEO2CYP01_START_SEC_VAR_NO_INIT_32
# ifdef MEMMAP_SECTION_OPEN
#  error Using VMEM_30_TRAVEO2CYP01_START_SEC_VAR_NO_INIT_32 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VMEM_30_TRAVEO2CYP01_VAR_NO_INIT_32_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma ghs section bss = ".MSR_VAR_NO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma ghs section data = ".MSR_VAR_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef VMEM_30_TRAVEO2CYP01_START_SEC_VAR_NO_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined VMEM_30_TRAVEO2CYP01_STOP_SEC_VAR_NO_INIT_32
# ifndef MEMMAP_SECTION_OPEN
#  error Using VMEM_30_TRAVEO2CYP01_STOP_SEC_VAR_NO_INIT_32 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VMEM_30_TRAVEO2CYP01_VAR_NO_INIT_32_OPEN
#  error Using VMEM_30_TRAVEO2CYP01_STOP_SEC_VAR_NO_INIT_32 is not possible as the corresponding memory section has not been opened.
# endif
# undef VMEM_30_TRAVEO2CYP01_VAR_NO_INIT_32_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma ghs section bss = default /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma ghs section data = default /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef VMEM_30_TRAVEO2CYP01_STOP_SEC_VAR_NO_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined VMEM_30_TRAVEO2CYP01_START_SEC_VAR_NO_INIT_64
# ifdef MEMMAP_SECTION_OPEN
#  error Using VMEM_30_TRAVEO2CYP01_START_SEC_VAR_NO_INIT_64 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VMEM_30_TRAVEO2CYP01_VAR_NO_INIT_64_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma ghs section bss = ".MSR_VAR_NO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma ghs section data = ".MSR_VAR_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef VMEM_30_TRAVEO2CYP01_START_SEC_VAR_NO_INIT_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined VMEM_30_TRAVEO2CYP01_STOP_SEC_VAR_NO_INIT_64
# ifndef MEMMAP_SECTION_OPEN
#  error Using VMEM_30_TRAVEO2CYP01_STOP_SEC_VAR_NO_INIT_64 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VMEM_30_TRAVEO2CYP01_VAR_NO_INIT_64_OPEN
#  error Using VMEM_30_TRAVEO2CYP01_STOP_SEC_VAR_NO_INIT_64 is not possible as the corresponding memory section has not been opened.
# endif
# undef VMEM_30_TRAVEO2CYP01_VAR_NO_INIT_64_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma ghs section bss = default /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma ghs section data = default /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef VMEM_30_TRAVEO2CYP01_STOP_SEC_VAR_NO_INIT_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined VMEM_30_TRAVEO2CYP01_START_SEC_VAR_NO_INIT_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using VMEM_30_TRAVEO2CYP01_START_SEC_VAR_NO_INIT_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VMEM_30_TRAVEO2CYP01_VAR_NO_INIT_8_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma ghs section bss = ".MSR_VAR_NO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma ghs section data = ".MSR_VAR_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef VMEM_30_TRAVEO2CYP01_START_SEC_VAR_NO_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined VMEM_30_TRAVEO2CYP01_STOP_SEC_VAR_NO_INIT_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using VMEM_30_TRAVEO2CYP01_STOP_SEC_VAR_NO_INIT_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VMEM_30_TRAVEO2CYP01_VAR_NO_INIT_8_OPEN
#  error Using VMEM_30_TRAVEO2CYP01_STOP_SEC_VAR_NO_INIT_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef VMEM_30_TRAVEO2CYP01_VAR_NO_INIT_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma ghs section bss = default /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma ghs section data = default /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef VMEM_30_TRAVEO2CYP01_STOP_SEC_VAR_NO_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined VMEM_30_TRAVEO2CYP01_START_SEC_VAR_NO_INIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using VMEM_30_TRAVEO2CYP01_START_SEC_VAR_NO_INIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VMEM_30_TRAVEO2CYP01_VAR_NO_INIT_UNSPECIFIED_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma ghs section bss = ".MSR_VAR_NO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma ghs section data = ".MSR_VAR_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef VMEM_30_TRAVEO2CYP01_START_SEC_VAR_NO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined VMEM_30_TRAVEO2CYP01_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using VMEM_30_TRAVEO2CYP01_STOP_SEC_VAR_NO_INIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VMEM_30_TRAVEO2CYP01_VAR_NO_INIT_UNSPECIFIED_OPEN
#  error Using VMEM_30_TRAVEO2CYP01_STOP_SEC_VAR_NO_INIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef VMEM_30_TRAVEO2CYP01_VAR_NO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma ghs section bss = default /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma ghs section data = default /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef VMEM_30_TRAVEO2CYP01_STOP_SEC_VAR_NO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined VMEM_30_TRAVEO2CYP01_START_SEC_VAR_PBCFG
# ifdef MEMMAP_SECTION_OPEN
#  error Using VMEM_30_TRAVEO2CYP01_START_SEC_VAR_PBCFG is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VMEM_30_TRAVEO2CYP01_VAR_PBCFG_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_PBCFG_VAR/MSR_PBCFG_VAR */
# pragma ghs section bss = ".MSR_PBCFG_VAR_CLEARED" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma ghs section data = ".MSR_PBCFG_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef VMEM_30_TRAVEO2CYP01_START_SEC_VAR_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined VMEM_30_TRAVEO2CYP01_STOP_SEC_VAR_PBCFG
# ifndef MEMMAP_SECTION_OPEN
#  error Using VMEM_30_TRAVEO2CYP01_STOP_SEC_VAR_PBCFG is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VMEM_30_TRAVEO2CYP01_VAR_PBCFG_OPEN
#  error Using VMEM_30_TRAVEO2CYP01_STOP_SEC_VAR_PBCFG is not possible as the corresponding memory section has not been opened.
# endif
# undef VMEM_30_TRAVEO2CYP01_VAR_PBCFG_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_PBCFG_VAR/MSR_PBCFG_VAR */
# pragma ghs section bss = default /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma ghs section data = default /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef VMEM_30_TRAVEO2CYP01_STOP_SEC_VAR_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

/* -------------------------------------------------------------------------------- */


/**********************************************************************************************************************
 *  MEMMAP ERROR CHECKS
 *********************************************************************************************************************/

#ifdef VMEM_30_TRAVEO2CYP01_START_SEC_APPL_CODE
# error Using VMEM_30_TRAVEO2CYP01_START_SEC_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef VMEM_30_TRAVEO2CYP01_STOP_SEC_APPL_CODE
# error Using VMEM_30_TRAVEO2CYP01_STOP_SEC_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef VMEM_30_TRAVEO2CYP01_START_SEC_CODE
# error Using VMEM_30_TRAVEO2CYP01_START_SEC_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef VMEM_30_TRAVEO2CYP01_STOP_SEC_CODE
# error Using VMEM_30_TRAVEO2CYP01_STOP_SEC_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef VMEM_30_TRAVEO2CYP01_START_SEC_CONST_16
# error Using VMEM_30_TRAVEO2CYP01_START_SEC_CONST_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef VMEM_30_TRAVEO2CYP01_STOP_SEC_CONST_16
# error Using VMEM_30_TRAVEO2CYP01_STOP_SEC_CONST_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef VMEM_30_TRAVEO2CYP01_START_SEC_CONST_32
# error Using VMEM_30_TRAVEO2CYP01_START_SEC_CONST_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef VMEM_30_TRAVEO2CYP01_STOP_SEC_CONST_32
# error Using VMEM_30_TRAVEO2CYP01_STOP_SEC_CONST_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef VMEM_30_TRAVEO2CYP01_START_SEC_CONST_64
# error Using VMEM_30_TRAVEO2CYP01_START_SEC_CONST_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef VMEM_30_TRAVEO2CYP01_STOP_SEC_CONST_64
# error Using VMEM_30_TRAVEO2CYP01_STOP_SEC_CONST_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef VMEM_30_TRAVEO2CYP01_START_SEC_CONST_8
# error Using VMEM_30_TRAVEO2CYP01_START_SEC_CONST_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef VMEM_30_TRAVEO2CYP01_STOP_SEC_CONST_8
# error Using VMEM_30_TRAVEO2CYP01_STOP_SEC_CONST_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef VMEM_30_TRAVEO2CYP01_START_SEC_CONST_PBCFG
# error Using VMEM_30_TRAVEO2CYP01_START_SEC_CONST_PBCFG is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef VMEM_30_TRAVEO2CYP01_STOP_SEC_CONST_PBCFG
# error Using VMEM_30_TRAVEO2CYP01_STOP_SEC_CONST_PBCFG is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef VMEM_30_TRAVEO2CYP01_START_SEC_CONST_UNSPECIFIED
# error Using VMEM_30_TRAVEO2CYP01_START_SEC_CONST_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef VMEM_30_TRAVEO2CYP01_STOP_SEC_CONST_UNSPECIFIED
# error Using VMEM_30_TRAVEO2CYP01_STOP_SEC_CONST_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef VMEM_30_TRAVEO2CYP01_START_SEC_PBCFG
# error Using VMEM_30_TRAVEO2CYP01_START_SEC_PBCFG is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef VMEM_30_TRAVEO2CYP01_STOP_SEC_PBCFG
# error Using VMEM_30_TRAVEO2CYP01_STOP_SEC_PBCFG is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef VMEM_30_TRAVEO2CYP01_START_SEC_VAR_CLEARED_16
# error Using VMEM_30_TRAVEO2CYP01_START_SEC_VAR_CLEARED_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef VMEM_30_TRAVEO2CYP01_STOP_SEC_VAR_CLEARED_16
# error Using VMEM_30_TRAVEO2CYP01_STOP_SEC_VAR_CLEARED_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef VMEM_30_TRAVEO2CYP01_START_SEC_VAR_CLEARED_32
# error Using VMEM_30_TRAVEO2CYP01_START_SEC_VAR_CLEARED_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef VMEM_30_TRAVEO2CYP01_STOP_SEC_VAR_CLEARED_32
# error Using VMEM_30_TRAVEO2CYP01_STOP_SEC_VAR_CLEARED_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef VMEM_30_TRAVEO2CYP01_START_SEC_VAR_CLEARED_64
# error Using VMEM_30_TRAVEO2CYP01_START_SEC_VAR_CLEARED_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef VMEM_30_TRAVEO2CYP01_STOP_SEC_VAR_CLEARED_64
# error Using VMEM_30_TRAVEO2CYP01_STOP_SEC_VAR_CLEARED_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef VMEM_30_TRAVEO2CYP01_START_SEC_VAR_CLEARED_8
# error Using VMEM_30_TRAVEO2CYP01_START_SEC_VAR_CLEARED_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef VMEM_30_TRAVEO2CYP01_STOP_SEC_VAR_CLEARED_8
# error Using VMEM_30_TRAVEO2CYP01_STOP_SEC_VAR_CLEARED_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef VMEM_30_TRAVEO2CYP01_START_SEC_VAR_CLEARED_UNSPECIFIED
# error Using VMEM_30_TRAVEO2CYP01_START_SEC_VAR_CLEARED_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef VMEM_30_TRAVEO2CYP01_STOP_SEC_VAR_CLEARED_UNSPECIFIED
# error Using VMEM_30_TRAVEO2CYP01_STOP_SEC_VAR_CLEARED_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef VMEM_30_TRAVEO2CYP01_START_SEC_VAR_INIT_16
# error Using VMEM_30_TRAVEO2CYP01_START_SEC_VAR_INIT_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef VMEM_30_TRAVEO2CYP01_STOP_SEC_VAR_INIT_16
# error Using VMEM_30_TRAVEO2CYP01_STOP_SEC_VAR_INIT_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef VMEM_30_TRAVEO2CYP01_START_SEC_VAR_INIT_32
# error Using VMEM_30_TRAVEO2CYP01_START_SEC_VAR_INIT_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef VMEM_30_TRAVEO2CYP01_STOP_SEC_VAR_INIT_32
# error Using VMEM_30_TRAVEO2CYP01_STOP_SEC_VAR_INIT_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef VMEM_30_TRAVEO2CYP01_START_SEC_VAR_INIT_64
# error Using VMEM_30_TRAVEO2CYP01_START_SEC_VAR_INIT_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef VMEM_30_TRAVEO2CYP01_STOP_SEC_VAR_INIT_64
# error Using VMEM_30_TRAVEO2CYP01_STOP_SEC_VAR_INIT_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef VMEM_30_TRAVEO2CYP01_START_SEC_VAR_INIT_8
# error Using VMEM_30_TRAVEO2CYP01_START_SEC_VAR_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef VMEM_30_TRAVEO2CYP01_STOP_SEC_VAR_INIT_8
# error Using VMEM_30_TRAVEO2CYP01_STOP_SEC_VAR_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef VMEM_30_TRAVEO2CYP01_START_SEC_VAR_INIT_UNSPECIFIED
# error Using VMEM_30_TRAVEO2CYP01_START_SEC_VAR_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef VMEM_30_TRAVEO2CYP01_STOP_SEC_VAR_INIT_UNSPECIFIED
# error Using VMEM_30_TRAVEO2CYP01_STOP_SEC_VAR_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef VMEM_30_TRAVEO2CYP01_START_SEC_VAR_NO_INIT_16
# error Using VMEM_30_TRAVEO2CYP01_START_SEC_VAR_NO_INIT_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef VMEM_30_TRAVEO2CYP01_STOP_SEC_VAR_NO_INIT_16
# error Using VMEM_30_TRAVEO2CYP01_STOP_SEC_VAR_NO_INIT_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef VMEM_30_TRAVEO2CYP01_START_SEC_VAR_NO_INIT_32
# error Using VMEM_30_TRAVEO2CYP01_START_SEC_VAR_NO_INIT_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef VMEM_30_TRAVEO2CYP01_STOP_SEC_VAR_NO_INIT_32
# error Using VMEM_30_TRAVEO2CYP01_STOP_SEC_VAR_NO_INIT_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef VMEM_30_TRAVEO2CYP01_START_SEC_VAR_NO_INIT_64
# error Using VMEM_30_TRAVEO2CYP01_START_SEC_VAR_NO_INIT_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef VMEM_30_TRAVEO2CYP01_STOP_SEC_VAR_NO_INIT_64
# error Using VMEM_30_TRAVEO2CYP01_STOP_SEC_VAR_NO_INIT_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef VMEM_30_TRAVEO2CYP01_START_SEC_VAR_NO_INIT_8
# error Using VMEM_30_TRAVEO2CYP01_START_SEC_VAR_NO_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef VMEM_30_TRAVEO2CYP01_STOP_SEC_VAR_NO_INIT_8
# error Using VMEM_30_TRAVEO2CYP01_STOP_SEC_VAR_NO_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef VMEM_30_TRAVEO2CYP01_START_SEC_VAR_NO_INIT_UNSPECIFIED
# error Using VMEM_30_TRAVEO2CYP01_START_SEC_VAR_NO_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef VMEM_30_TRAVEO2CYP01_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
# error Using VMEM_30_TRAVEO2CYP01_STOP_SEC_VAR_NO_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef VMEM_30_TRAVEO2CYP01_START_SEC_VAR_PBCFG
# error Using VMEM_30_TRAVEO2CYP01_START_SEC_VAR_PBCFG is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef VMEM_30_TRAVEO2CYP01_STOP_SEC_VAR_PBCFG
# error Using VMEM_30_TRAVEO2CYP01_STOP_SEC_VAR_PBCFG is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif

#if defined MEMMAP_ERROR && !defined MEMMAP_ERROR_TOLERATE_INVALID_KEYWORD
# error No MemMap section found in vMem_30_Traveo2Cyp01_MemMap.h. Check your section define for validity.
#endif


/**********************************************************************************************************************
 *  POST USER CONFIG FILE
 *********************************************************************************************************************/

/* User Config File Start */

/* User Config File End */

#endif
/**********************************************************************************************************************
 *  END OF FILE: vMem_30_Traveo2Cyp01_MemMap.h
 *********************************************************************************************************************/

