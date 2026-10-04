/**********************************************************************************************************************
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
/*!        \file  vMem_30_Traveo2Cyp01_LL_Regs.h
 *        \brief  Register header of the vMem driver
 *
 *      \details  Defines macros and data types representing and abstracting the register layout of the
 *                FLASHC Interface.
 *         \unit  vMem_LL_RegAccess
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#if !defined (VMEM_30_TRAVEO2CYP01_LL_REGS_H)
# define      VMEM_30_TRAVEO2CYP01_LL_REGS_H

/**********************************************************************************************************************
 * HARDWARE SOFTWARE INTERFACE (HSI)
 *********************************************************************************************************************/
/*! \internal
 *  Hardware manuals: Traveo II Automotive Body Controller High Family Architecture Technical Reference Manual;
 *                    Document No. 002-24401 Rev. *A
 *  Chapter: 5. Inter-Processor Communication, 8. Code Flash, 9 Work Flash, 37. Nonvolatile Memory Programming;
 *  Errata sheets: Silicon Errata for the CYT3BB/4BB Series Rev. B, Document Revision: 2.2
 *  Access mechanism: Memory mapped registers and descriptor data structures located in RAM.
 *  Used registers: See definitions below.
 *  Hardware features related to independence or partitioning: -
 *  Operating modes: Refer to the states specified in the CAD.
 *  Hardware diagnostics: -
 *  Specifics: -
 *  \endinternal
 */

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* Registers address offsets */                                                     

/* FLASHC */                                                                        
# define VMEM_30_TRAVEO2CYP01_FLASHC_REG_OFFS_FLASH_CTL                             (0x0000u) /*!< Control. */
# define VMEM_30_TRAVEO2CYP01_FLASHC_REG_OFFS_FLASH_PWR_CTL                         (0x0004u) /*!< Flash power control. */
# define VMEM_30_TRAVEO2CYP01_FLASHC_REG_OFFS_FLASH_CMD                             (0x0008u) /*!< Command. */
# define VMEM_30_TRAVEO2CYP01_FLASHC_REG_OFFS_ECC_CTL                               (0x02A0u) /*!< ECC control. */
/* n from 0 to 3 */                                                                 
# define VMEM_30_TRAVEO2CYP01_FLASHC_REG_OFFS_FM_SRAM_ECC_CTL(n)                    (0x02B0u + ((n) * 0x4u)) /*!< eCT Flash SRAM ECC control. */ /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/* n from 0 to 2 */                                                                 
# define VMEM_30_TRAVEO2CYP01_FLASHC_REG_OFFS_CM0_CA_CTL(n)                         (0x0400u + ((n) * 0x4u)) /*!< CM0+ cache control. */ /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/* n from 0 to 2 */                                                                 
# define VMEM_30_TRAVEO2CYP01_FLASHC_REG_OFFS_CM0_CA_STATUS(n)                      (0x0440u + ((n) * 0x4u)) /*!< CM0+ cache status. */ /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
# define VMEM_30_TRAVEO2CYP01_FLASHC_REG_OFFS_CM0_STATUS                            (0x0460u) /*!< CM0+ interface status. */

# define VMEM_30_TRAVEO2CYP01_FLASHC_REG_OFFS_CM7_0_STATUS                          (0x04E0u) /*!< CM4/CM7 0 interface status. */
# define VMEM_30_TRAVEO2CYP01_FLASHC_REG_OFFS_CM7_1_STATUS                          (0x0560u) /*!< CM4/CM7 1 interface status. */

# define VMEM_30_TRAVEO2CYP01_FLASHC_REG_OFFS_CRYPTO_BUFF_CTL                       (0x0580u) /*!< Cryptography buffer control. */

# define VMEM_30_TRAVEO2CYP01_FLASHC_REG_OFFS_DW0_BUFF_CTL                          (0x0600u) /*!< Datawire 0 buffer control. */
# define VMEM_30_TRAVEO2CYP01_FLASHC_REG_OFFS_DW1_BUFF_CTL                          (0x0680u) /*!< Datawire 1 buffer control. */

# define VMEM_30_TRAVEO2CYP01_FLASHC_REG_OFFS_SLOW0_MS_BUFF_CTL                     (0x0780u) /*!< Slow external master 0 buffer control. */
# define VMEM_30_TRAVEO2CYP01_FLASHC_REG_OFFS_SLOW1_MS_BUFF_CTL                     (0x0800u) /*!< Slow external master 1 buffer control. */

/* FLAHSC FM_CTL_ECT */
# define VMEM_30_TRAVEO2CYP01_FLASHC_REG_OFFS_FLASHC_FM_CTL_ECT                     (0xF000u) /*!< Flash Macro Registers. */
# define VMEM_30_TRAVEO2CYP01_FLASHC_FM_CTL_ECT_REG_OFFS_FM_CTL                     (VMEM_30_TRAVEO2CYP01_FLASHC_REG_OFFS_FLASHC_FM_CTL_ECT + 0x0000u) /*!< Flash Macro Control. */
# define VMEM_30_TRAVEO2CYP01_FLASHC_FM_CTL_ECT_REG_OFFS_FM_CODE_MARGIN             (VMEM_30_TRAVEO2CYP01_FLASHC_REG_OFFS_FLASHC_FM_CTL_ECT + 0x0004u) /*!< Flash Macro Margin Mode on Code Flash. */
# define VMEM_30_TRAVEO2CYP01_FLASHC_FM_CTL_ECT_REG_OFFS_FM_ADDR                    (VMEM_30_TRAVEO2CYP01_FLASHC_REG_OFFS_FLASHC_FM_CTL_ECT + 0x0008u) /*!< Flash Macro Address. */
# define VMEM_30_TRAVEO2CYP01_FLASHC_FM_CTL_ECT_REG_OFFS_GEOMTRY                    (VMEM_30_TRAVEO2CYP01_FLASHC_REG_OFFS_FLASHC_FM_CTL_ECT + 0x000Cu) /*!< Flash Density Information. */
# define VMEM_30_TRAVEO2CYP01_FLASHC_FM_CTL_ECT_REG_OFFS_INTR                       (VMEM_30_TRAVEO2CYP01_FLASHC_REG_OFFS_FLASHC_FM_CTL_ECT + 0x0020u) /*!< Interrupt. */
# define VMEM_30_TRAVEO2CYP01_FLASHC_FM_CTL_ECT_REG_OFFS_INTR_SET                   (VMEM_30_TRAVEO2CYP01_FLASHC_REG_OFFS_FLASHC_FM_CTL_ECT + 0x0024u) /*!< Interrupt Set. */
# define VMEM_30_TRAVEO2CYP01_FLASHC_FM_CTL_ECT_REG_OFFS_INTR_MASK                  (VMEM_30_TRAVEO2CYP01_FLASHC_REG_OFFS_FLASHC_FM_CTL_ECT + 0x0028u) /*!< Interrupt Mask. */
# define VMEM_30_TRAVEO2CYP01_FLASHC_FM_CTL_ECT_REG_OFFS_INTR_MASKED                (VMEM_30_TRAVEO2CYP01_FLASHC_REG_OFFS_FLASHC_FM_CTL_ECT + 0x002Cu) /*!< Interrupt Masked. */
# define VMEM_30_TRAVEO2CYP01_FLASHC_FM_CTL_ECT_REG_OFFS_ECC_OVERRIDE               (VMEM_30_TRAVEO2CYP01_FLASHC_REG_OFFS_FLASHC_FM_CTL_ECT + 0x0030u) /*!< ECC Data In override information and control bits. */
# define VMEM_30_TRAVEO2CYP01_FLASHC_FM_CTL_ECT_REG_OFFS_FM_DATA                    (VMEM_30_TRAVEO2CYP01_FLASHC_REG_OFFS_FLASHC_FM_CTL_ECT + 0x0040u) /*!< Flash macro data_in[31 to 0] both Code and Work Flash. */
# define VMEM_30_TRAVEO2CYP01_FLASHC_FM_CTL_ECT_REG_OFFS_BOOKMARK                   (VMEM_30_TRAVEO2CYP01_FLASHC_REG_OFFS_FLASHC_FM_CTL_ECT + 0x0064u) /*!< Bookmark register keeps the current FW HV seq. */
# define VMEM_30_TRAVEO2CYP01_FLASHC_FM_CTL_ECT_REG_OFFS_MAIN_FLASH_SAFETY          (VMEM_30_TRAVEO2CYP01_FLASHC_REG_OFFS_FLASHC_FM_CTL_ECT + 0x0400u) /*!< Main (Code) Flash Security enable. */
# define VMEM_30_TRAVEO2CYP01_FLASHC_FM_CTL_ECT_REG_OFFS_STATUS                     (VMEM_30_TRAVEO2CYP01_FLASHC_REG_OFFS_FLASHC_FM_CTL_ECT + 0x0404u) /*!< Status read from Flash Macro. */
# define VMEM_30_TRAVEO2CYP01_FLASHC_FM_CTL_ECT_REG_OFFS_WORK_FLASH_SAFETY          (VMEM_30_TRAVEO2CYP01_FLASHC_REG_OFFS_FLASHC_FM_CTL_ECT + 0x0500u) /*!< Work Flash Security enable. */

/* FAULT */                                                                         
/* faultId from 0 to 3 */                                                           
# define VMEM_30_TRAVEO2CYP01_FAULT_REG_OFFS_STRUCT(faultId)                        (0x0000u + ((faultId) * 0x100u)) /*!< Fault structures. */ /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

# define VMEM_30_TRAVEO2CYP01_FAULT_STRUCT_REG_OFFS_CTL(faultId)                    (VMEM_30_TRAVEO2CYP01_FAULT_REG_OFFS_STRUCT(faultId) + 0x0000u) /*!< Fault control. */ /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
# define VMEM_30_TRAVEO2CYP01_FAULT_STRUCT_REG_OFFS_STATUS(faultId)                 (VMEM_30_TRAVEO2CYP01_FAULT_REG_OFFS_STRUCT(faultId) + 0x000Cu) /*!< Fault status. */ /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
# define VMEM_30_TRAVEO2CYP01_FAULT_STRUCT_REG_OFFS_DATA(faultId)                   (VMEM_30_TRAVEO2CYP01_FAULT_REG_OFFS_STRUCT(faultId) + 0x0010u) /*!< Fault data. */ /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/* n from 0 to 2 */                                                                 
# define VMEM_30_TRAVEO2CYP01_FAULT_STRUCT_REG_OFFS_PENDING(faultId, n)             (VMEM_30_TRAVEO2CYP01_FAULT_REG_OFFS_STRUCT(faultId) + 0x0040u + ((n) * 0x4u)) /*!< Fault pending. */ /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
# define VMEM_30_TRAVEO2CYP01_FAULT_STRUCT_REG_OFFS_MASK(faultId, n)                (VMEM_30_TRAVEO2CYP01_FAULT_REG_OFFS_STRUCT(faultId) + 0x0050u + ((n) * 0x4u)) /*!< Fault mask. */ /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

# define VMEM_30_TRAVEO2CYP01_FAULT_STRUCT_REG_OFFS_INTR(faultId)                   (VMEM_30_TRAVEO2CYP01_FAULT_REG_OFFS_STRUCT(faultId) + 0x00C0u) /*!< Interrupt. */ /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
# define VMEM_30_TRAVEO2CYP01_FAULT_STRUCT_REG_OFFS_INTR_SET(faultId)               (VMEM_30_TRAVEO2CYP01_FAULT_REG_OFFS_STRUCT(faultId) + 0x00C4u) /*!< Interrupt set. */ /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
# define VMEM_30_TRAVEO2CYP01_FAULT_STRUCT_REG_OFFS_INTR_MASK(faultId)              (VMEM_30_TRAVEO2CYP01_FAULT_REG_OFFS_STRUCT(faultId) + 0x00C8u) /*!< Interrupt mask. */ /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
# define VMEM_30_TRAVEO2CYP01_FAULT_STRUCT_REG_OFFS_INTR_MASKED(faultId)            (VMEM_30_TRAVEO2CYP01_FAULT_REG_OFFS_STRUCT(faultId) + 0x00CCu) /*!< Interrupt masked. */ /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/* IPC */                                                                           
/* structId from 0 to 7 */                                                          
# define VMEM_30_TRAVEO2CYP01_IPC_REG_OFFS_STRUCT(structId)                         (0x0000u + ((structId) * 0x20u)) /*!< IPC structures. */ /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
# define VMEM_30_TRAVEO2CYP01_IPC_REG_OFFS_INTR_STRUCT(structId)                    (0x1000u + ((structId) * 0x20u)) /*!< IPC interrupt structures. */ /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/* IPC structure */                                                                 
/* structId from 0 to 7 */                                                          
# define VMEM_30_TRAVEO2CYP01_IPC_STRUCT_REG_OFFS_ACQUIRE(structId)                 (VMEM_30_TRAVEO2CYP01_IPC_REG_OFFS_STRUCT(structId) + 0x0000u) /*!< IPC acquire. */ /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
# define VMEM_30_TRAVEO2CYP01_IPC_STRUCT_REG_OFFS_RELEASE(structId)                 (VMEM_30_TRAVEO2CYP01_IPC_REG_OFFS_STRUCT(structId) + 0x0004u) /*!< IPC release. */ /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
# define VMEM_30_TRAVEO2CYP01_IPC_STRUCT_REG_OFFS_NOTIFY(structId)                  (VMEM_30_TRAVEO2CYP01_IPC_REG_OFFS_STRUCT(structId) + 0x0008u) /*!< IPC notify. */ /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/* n from 0 to 1 */                                                                 
# define VMEM_30_TRAVEO2CYP01_IPC_STRUCT_REG_OFFS_DATA(structId, n)                 (VMEM_30_TRAVEO2CYP01_IPC_REG_OFFS_STRUCT(structId) + 0x000Cu + ((n) * 0x4u)) /*!< IPC data. */ /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

# define VMEM_30_TRAVEO2CYP01_IPC_STRUCT_REG_OFFS_LOCK_STATUS(structId)             (VMEM_30_TRAVEO2CYP01_IPC_REG_OFFS_STRUCT(structId) + 0x001Cu) /*!< IPC lock status. */ /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/* IPC interrupt structure */                                                       
# define VMEM_30_TRAVEO2CYP01_IPC_INTR_STRUCT_REG_OFFS_INTR(structId)               (VMEM_30_TRAVEO2CYP01_IPC_REG_OFFS_INTR_STRUCT(structId) + 0x0000u) /*!< IPC interrupt. */ /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
# define VMEM_30_TRAVEO2CYP01_IPC_INTR_STRUCT_REG_OFFS_INTR_SET(structId)           (VMEM_30_TRAVEO2CYP01_IPC_REG_OFFS_INTR_STRUCT(structId) + 0x0004u) /*!< IPC interrupt set. */ /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
# define VMEM_30_TRAVEO2CYP01_IPC_INTR_STRUCT_REG_OFFS_INTR_MASK(structId)          (VMEM_30_TRAVEO2CYP01_IPC_REG_OFFS_INTR_STRUCT(structId) + 0x0008u) /*!< IPC interrupt mask. */ /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
# define VMEM_30_TRAVEO2CYP01_IPC_INTR_STRUCT_REG_OFFS_INTR_MASKED(structId)        (VMEM_30_TRAVEO2CYP01_IPC_REG_OFFS_INTR_STRUCT(structId) + 0x000Cu) /*!< IPC interrupt masked. */ /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/* Register Masks */

/* FLASHC FLASH_CTL */
# define VMEM_30_TRAVEO2CYP01_FLASHC_FLASH_CTL_REG_MAIN_MAP                         (1uL << 8u) /*!< Main map is Mapping A or Mapping B. (main bank is for code flash) */
# define VMEM_30_TRAVEO2CYP01_FLASHC_FLASH_CTL_REG_MAIN_MAP_MAPPING_A               (0uL << 8u) /*!< Mapping A. */
# define VMEM_30_TRAVEO2CYP01_FLASHC_FLASH_CTL_REG_MAIN_MAP_MAPPING_B               (1uL << 8u) /*!< Mapping B. */

# define VMEM_30_TRAVEO2CYP01_FLASHC_FLASH_CTL_REG_WORK_MAP                         (1uL << 9u) /*!< Work map is Mapping A or Mapping B. */
# define VMEM_30_TRAVEO2CYP01_FLASHC_FLASH_CTL_REG_WORK_MAP_MAPPING_A               (0uL << 9u) /*!< Mapping A. */
# define VMEM_30_TRAVEO2CYP01_FLASHC_FLASH_CTL_REG_WORK_MAP_MAPPING_B               (1uL << 9u) /*!< Mapping B. */

# define VMEM_30_TRAVEO2CYP01_FLASHC_FLASH_CTL_REG_MAIN_BANK_MODE                   (1uL << 12u) /*!< Main bank mode is single or dual. (main bank is for code flash) */
# define VMEM_30_TRAVEO2CYP01_FLASHC_FLASH_CTL_REG_MAIN_BANK_MODE_SINGLE            (0uL << 12u) /*!< Single bank mode enabled. */
# define VMEM_30_TRAVEO2CYP01_FLASHC_FLASH_CTL_REG_MAIN_BANK_MODE_DUAL              (1uL << 12u) /*!< Dual bank mode enabled. */

# define VMEM_30_TRAVEO2CYP01_FLASHC_FLASH_CTL_REG_WORK_BANK_MODE                   (1uL << 13u) /*!< Work bank mode is single or dual. */
# define VMEM_30_TRAVEO2CYP01_FLASHC_FLASH_CTL_REG_WORK_BANK_MODE_SINGLE            (0uL << 13u) /*!< Single bank mode enabled. */
# define VMEM_30_TRAVEO2CYP01_FLASHC_FLASH_CTL_REG_WORK_BANK_MODE_DUAL              (1uL << 13u) /*!< Dual bank mode enabled. */

# define VMEM_30_TRAVEO2CYP01_FLASHC_FLASH_CTL_REG_WORK_FLASH_WORK_ECC_EN           (1uL << 20u) /*!< Work Flash ECC are enabled. */
# define VMEM_30_TRAVEO2CYP01_FLASHC_FLASH_CTL_REG_WORK_FLASH_WORK_ERR_SILENT       (1uL << 22u) /*!< Work ECC error silent enabled. */

/* FLASHC FM_CTL_ECT */
# define VMEM_30_TRAVEO2CYP01_FLASHC_FM_CTL_ECT_REG_WORK_FLASH_SAFETY               (1uL << 0u) /*!< Work Flash embedded operations are enabled or disabled */
# define VMEM_30_TRAVEO2CYP01_FLASHC_FM_CTL_ECT_REG_WORK_FLASH_SAFETY_WRITE_ENABLE  (1uL << 0u) /*!< Work Flash embedded operations are enabled */
# define VMEM_30_TRAVEO2CYP01_FLASHC_FM_CTL_ECT_REG_WORK_FLASH_SAFETY_WRITE_DISABLE (0uL << 0u) /*!< Work Flash embedded operations are disabled */

# define VMEM_30_TRAVEO2CYP01_FLASHC_FM_CTL_ECT_REG_MAIN_FLASH_SAFETY               (1uL << 0u) /*!< Main Flash embedded operations are enabled or disabled */
# define VMEM_30_TRAVEO2CYP01_FLASHC_FM_CTL_ECT_REG_MAIN_FLASH_SAFETY_WRITE_ENABLE  (1uL << 0u) /*!< Main Flash embedded operations are enabled */
# define VMEM_30_TRAVEO2CYP01_FLASHC_FM_CTL_ECT_REG_MAIN_FLASH_SAFETY_WRITE_DISABLE (0uL << 0u) /*!< Main Flash embedded operations are disabled */

# define VMEM_30_TRAVEO2CYP01_FLASHC_FM_CTL_ECT_REG_STATUS_PGM_CODE                 (1uL << 0u) /*!< PGM operation to the Code flash is running or not running */
# define VMEM_30_TRAVEO2CYP01_FLASHC_FM_CTL_ECT_REG_STATUS_PGM_CODE_RUNNING         (1uL << 0u) /*!< PGM operation to the Code flash is running */
# define VMEM_30_TRAVEO2CYP01_FLASHC_FM_CTL_ECT_REG_STATUS_PGM_CODE_NOT_RUNNING     (0uL << 0u) /*!< PGM operation to the Code flash is not running */

# define VMEM_30_TRAVEO2CYP01_FLASHC_FM_CTL_ECT_REG_STATUS_PGM_WORK                 (1uL << 1u) /*!< PGM operation to the Work flash is running or not running */
# define VMEM_30_TRAVEO2CYP01_FLASHC_FM_CTL_ECT_REG_STATUS_PGM_WORK_RUNNING         (1uL << 1u) /*!< PGM operation to the Work flash is running */
# define VMEM_30_TRAVEO2CYP01_FLASHC_FM_CTL_ECT_REG_STATUS_PGM_WORK_NOT_RUNNING     (0uL << 1u) /*!< PGM operation to the Work flash is not running */

# define VMEM_30_TRAVEO2CYP01_FLASHC_FM_CTL_ECT_REG_STATUS_ERASE_CODE               (1uL << 2u) /*!< Erase operation to the Code flash is running or not running */
# define VMEM_30_TRAVEO2CYP01_FLASHC_FM_CTL_ECT_REG_STATUS_ERASE_CODE_RUNNING       (1uL << 2u) /*!< Erase operation to the Code flash is running */
# define VMEM_30_TRAVEO2CYP01_FLASHC_FM_CTL_ECT_REG_STATUS_ERASE_CODE_NOT_RUNNING   (0uL << 2u) /*!< Erase operation to the Code flash is not running */

# define VMEM_30_TRAVEO2CYP01_FLASHC_FM_CTL_ECT_REG_STATUS_ERASE_WORK               (1uL << 3u) /*!< Erase operation to the Work flash is running or not running */
# define VMEM_30_TRAVEO2CYP01_FLASHC_FM_CTL_ECT_REG_STATUS_ERASE_WORK_RUNNING       (1uL << 3u) /*!< Erase operation to the Work flash is running */
# define VMEM_30_TRAVEO2CYP01_FLASHC_FM_CTL_ECT_REG_STATUS_ERASE_WORK_NOT_RUNNING   (0uL << 3u) /*!< Erase operation to the Work flash is not running */

# define VMEM_30_TRAVEO2CYP01_FLASHC_FM_CTL_ECT_REG_STATUS_ERS_SUSPEND               (1uL << 4u) /*!< Erase operation to the Work flash is suspended or not suspended */
# define VMEM_30_TRAVEO2CYP01_FLASHC_FM_CTL_ECT_REG_STATUS_ERS_SUSPEND_SUSPENDED     (1uL << 4u) /*!< Erase operation to the Work flash is suspended */
# define VMEM_30_TRAVEO2CYP01_FLASHC_FM_CTL_ECT_REG_STATUS_ERS_SUSPEND_NOT_SUSPENDED (0uL << 4u) /*!< Erase operation to the Work flash is not suspended */

# define VMEM_30_TRAVEO2CYP01_FLASHC_FM_CTL_ECT_REG_STATUS_BLANK_CHECK_WORK             (1uL << 5u) /*!< Blank Check operation to the Work flash is running or not running */
# define VMEM_30_TRAVEO2CYP01_FLASHC_FM_CTL_ECT_REG_STATUS_BLANK_CHECK_WORK_RUNNING     (1uL << 5u) /*!< Blank Check operation to the Work flash is running */
# define VMEM_30_TRAVEO2CYP01_FLASHC_FM_CTL_ECT_REG_STATUS_BLANK_CHECK_WORK_NOT_RUNNING (0uL << 5u) /*!< Blank Check operation to the Work flash is not running */

# define VMEM_30_TRAVEO2CYP01_FLASHC_FM_CTL_ECT_REG_STATUS_BLANK_CHECK_PASS            (1uL << 6u) /*!< Blank Check passed or not */
# define VMEM_30_TRAVEO2CYP01_FLASHC_FM_CTL_ECT_REG_STATUS_BLANK_CHECK_PASS_BLANK      (1uL << 6u) /*!< Blank Check operation was passed */
# define VMEM_30_TRAVEO2CYP01_FLASHC_FM_CTL_ECT_REG_STATUS_BLANK_CHECK_PASS_NOT_BLANK  (0uL << 6u) /*!< Blank Check was not passed */

# define VMEM_30_TRAVEO2CYP01_FLASHC_FM_CTL_ECT_REG_STATUS_HANG                     (1uL << 30u) /*!< After embedded operation (pgm/erase) this flag will tell if it was successful or failed */
# define VMEM_30_TRAVEO2CYP01_FLASHC_FM_CTL_ECT_REG_STATUS_HANG_FAIL                (1uL << 30u) /*!< Fail not sucessful */
# define VMEM_30_TRAVEO2CYP01_FLASHC_FM_CTL_ECT_REG_STATUS_HANG_PASS                (0uL << 30u) /*!< Pass successful */

# define VMEM_30_TRAVEO2CYP01_FLASHC_FM_CTL_ECT_REG_STATUS_BUSY                     (1uL << 31u) /*!< Whenever the device is in embedded mode the RDY goes low. */
# define VMEM_30_TRAVEO2CYP01_FLASHC_FM_CTL_ECT_REG_STATUS_BUSY_BUSY                (1uL << 31u) /*!< Busy in embedded */
# define VMEM_30_TRAVEO2CYP01_FLASHC_FM_CTL_ECT_REG_STATUS_BUSY_READY               (0uL << 31u) /*!< Ready (high also in erase suspend) */

/* IPC interrupt structure */
# define VMEM_30_TRAVEO2CYP01_IPC_STRUCT_REG_ACQUIRE_SUCCESS                        (0x1uL << 31u) /*!< Specifies if the lock is successfully acquired or not. */
# define VMEM_30_TRAVEO2CYP01_IPC_STRUCT_REG_ACQUIRE_SUCCESS_SUCCESS                (1uL << 31u) /*!< Successfully acquired. */
# define VMEM_30_TRAVEO2CYP01_IPC_STRUCT_REG_ACQUIRE_SUCCESS_NO_SUCCESS             (0uL << 31u) /*!< Not successfully acquired. */

# define VMEM_30_TRAVEO2CYP01_IPC_STRUCT_REG_NOTIFY_INTR_NOTIFY(n)                  (0x1uL << (n)) /*!< Generation of notification events to the IPC interrupt structures for given IPC interrupt structure. */ /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/* n from 0 to 15 */                                                                
# define VMEM_30_TRAVEO2CYP01_IPC_STRUCT_REG_NOTIFY_INTR_NOTIFY_GENERATE(n)         (1uL << (n)) /*!< Generate a notify event for given IPC interrupt structure. */ /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

# define VMEM_30_TRAVEO2CYP01_IPC_STRUCT_REG_NOTIFY_INTR_RELEASE(n)                 (0x1uL << (n)) /*!< Generation of notification events to the IPC interrupt structures for given master. */ /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/* n from 0 to 15 */                                                                
# define VMEM_30_TRAVEO2CYP01_IPC_INTR_STRUCT_REG_INTR_RELEASE_RELEASE(n)           (1uL << (n)) /*!< IPC release event for given master is released. */ /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
# define VMEM_30_TRAVEO2CYP01_IPC_INTR_STRUCT_REG_INTR_RELEASE_NO_RELEASE(n)        (0uL << (n)) /*!< IPC release event for given master is not released. */ /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

# define VMEM_30_TRAVEO2CYP01_IPC_INTR_STRUCT_REG_INTR_SET_RELEASE(n)               (0x1uL << (n)) /*!< Trigger Generation of notification events to the IPC interrupt structures for given master. */ /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/* n from 0 to 15 */
# define VMEM_30_TRAVEO2CYP01_IPC_INTR_STRUCT_REG_INTR_SET_RELEASE_RELEASE(n)       (1uL << (n)) /*!< Trigger IPC release event for given master is released. */ /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
# define VMEM_30_TRAVEO2CYP01_IPC_INTR_STRUCT_REG_INTR_SET_RELEASE_NO_RELEASE(n)    (0uL << (n)) /*!< Trigger IPC release event for given master is not released. */ /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

# define VMEM_30_TRAVEO2CYP01_IPC_INTR_STRUCT_REG_INTR_NOTIFY(n)                    (0x10000u << (n)) /*!< Generation of notification events to the IPC interrupt structures for given master. */ /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/* n from 0 to 15 */                                                                
# define VMEM_30_TRAVEO2CYP01_IPC_INTR_STRUCT_REG_INTR_NOTIFY_NOTIFY(n)             (1uL << (n) + 15u) /*!< IPC notification event for given master is active. */ /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
# define VMEM_30_TRAVEO2CYP01_IPC_INTR_STRUCT_REG_INTR_NOTIFY_NO_NOTIFY(n)          (0uL << (n) + 15u) /*!< IPC notification event for given master is not active. */ /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/* On this platform a word is 4 bytes wide. */
#define VMEM_30_TRAVEO2CYP01_WORD_IN_BYTES                                          4u


#endif /* VMEM_30_TRAVEO2CYP01_LL_REGS_H */

/**********************************************************************************************************************
 *  END OF FILE: vMem_30_Traveo2Cyp01_LL_Regs.h
 *********************************************************************************************************************/
