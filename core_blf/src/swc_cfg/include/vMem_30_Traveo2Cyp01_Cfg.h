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
 *            Module: vMem_30_Traveo2Cyp01
 *           Program: MSR_Geely_SLP2
 *          Customer: Marelli Automotive Electronics (Guangzhou) Co., Ltd
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: CYT2B75BA
 *    License Scope : The usage is restricted to CBD2600619_D00
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: vMem_30_Traveo2Cyp01_Cfg.h
 *   Generation Time: 2026-07-14 11:05:44
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

#if !defined (VMEM_30_TRAVEO2CYP01_CFG_H)
# define VMEM_30_TRAVEO2CYP01_CFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "Std_Types.h"

/**********************************************************************************************************************
 *  VERSION INFORMATION
 *********************************************************************************************************************/

/*! \brief Version defines of generator version */
# define VMEM_30_TRAVEO2CYP01_CFG_MAJOR_VERSION        3u
# define VMEM_30_TRAVEO2CYP01_CFG_MINOR_VERSION        6u
# define VMEM_30_TRAVEO2CYP01_CFG_PATCH_VERSION        0u

/*! \brief Version defines that are used to check the compatibility of the generated data */
# define VMEM_30_TRAVEO2CYP01_CFG_COMP_MAJOR_VERSION   3u
# define VMEM_30_TRAVEO2CYP01_CFG_COMP_MINOR_VERSION   6u
# define VMEM_30_TRAVEO2CYP01_CFG_COMP_PATCH_VERSION   0u


/**********************************************************************************************************************
 *  GENERAL DEFINE BLOCK
 *********************************************************************************************************************/
# ifndef VMEM_30_TRAVEO2CYP01_USE_DUMMY_STATEMENT
#  define VMEM_30_TRAVEO2CYP01_USE_DUMMY_STATEMENT STD_ON /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
# endif
# ifndef VMEM_30_TRAVEO2CYP01_DUMMY_STATEMENT
#  define VMEM_30_TRAVEO2CYP01_DUMMY_STATEMENT(v) (v)=(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
# endif
# ifndef VMEM_30_TRAVEO2CYP01_DUMMY_STATEMENT_CONST
#  define VMEM_30_TRAVEO2CYP01_DUMMY_STATEMENT_CONST(v) (void)(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
# endif
# ifndef VMEM_30_TRAVEO2CYP01_ATOMIC_BIT_ACCESS_IN_BITFIELD
#  define VMEM_30_TRAVEO2CYP01_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
# endif
# ifndef VMEM_30_TRAVEO2CYP01_ATOMIC_VARIABLE_ACCESS
#  define VMEM_30_TRAVEO2CYP01_ATOMIC_VARIABLE_ACCESS 32u /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
# endif
# ifndef VMEM_30_TRAVEO2CYP01_PROCESSOR_CYT2B75BXX
#  define VMEM_30_TRAVEO2CYP01_PROCESSOR_CYT2B75BXX
# endif
# ifndef VMEM_30_TRAVEO2CYP01_COMP_GREENHILLS
#  define VMEM_30_TRAVEO2CYP01_COMP_GREENHILLS
# endif
# ifndef VMEM_30_TRAVEO2CYP01_GEN_GENERATOR_MSR
#  define VMEM_30_TRAVEO2CYP01_GEN_GENERATOR_MSR
# endif
# ifndef VMEM_30_TRAVEO2CYP01_CPUTYPE_BITORDER_LSB2MSB
#  define VMEM_30_TRAVEO2CYP01_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/vSet/vSetPlatform/vSetBitOrder */
# endif
# ifndef VMEM_30_TRAVEO2CYP01_CONFIGURATION_VARIANT_PRECOMPILE
#  define VMEM_30_TRAVEO2CYP01_CONFIGURATION_VARIANT_PRECOMPILE 1
# endif
# ifndef VMEM_30_TRAVEO2CYP01_CONFIGURATION_VARIANT_LINKTIME
#  define VMEM_30_TRAVEO2CYP01_CONFIGURATION_VARIANT_LINKTIME 2
# endif
# ifndef VMEM_30_TRAVEO2CYP01_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#  define VMEM_30_TRAVEO2CYP01_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
# endif
# ifndef VMEM_30_TRAVEO2CYP01_CONFIGURATION_VARIANT
#  define VMEM_30_TRAVEO2CYP01_CONFIGURATION_VARIANT VMEM_30_TRAVEO2CYP01_CONFIGURATION_VARIANT_PRECOMPILE
# endif
# ifndef VMEM_30_TRAVEO2CYP01_POSTBUILD_VARIANT_SUPPORT
#  define VMEM_30_TRAVEO2CYP01_POSTBUILD_VARIANT_SUPPORT STD_OFF
# endif


/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/

/*! Enables / disables development error detection */
#ifndef VMEM_30_TRAVEO2CYP01_DEV_ERROR_DETECT
# define VMEM_30_TRAVEO2CYP01_DEV_ERROR_DETECT         STD_ON
#endif

/*! Enables / disables development error reporting (enabled whenever error detection is configured) */
#ifndef VMEM_30_TRAVEO2CYP01_DEV_ERROR_REPORT
# define VMEM_30_TRAVEO2CYP01_DEV_ERROR_REPORT         STD_OFF
#endif

/*! Enables / disables the version information API (VMEM_30_TRAVEO2CYP01_GetVersionInfo) */
#ifndef VMEM_30_TRAVEO2CYP01_VERSION_INFO_API
# define VMEM_30_TRAVEO2CYP01_VERSION_INFO_API         STD_ON
#endif

/*! Maximal number of sectors over all instances */
#define VMEM_30_TRAVEO2CYP01_MAX_NUM_OF_SECTORS_OF_ALL_INSTANCES         2u

/*! Maximal page size over all instances */
#define VMEM_30_TRAVEO2CYP01_MAX_PAGE_SIZE_OF_ALL_INSTANCES              4u

/*! Enables / disables read only mode (This define will only be used if this mode is supported by the vMem low level.) */
#define VMEM_30_TRAVEO2CYP01_READONLY_MODE             STD_OFF

/*! vMem driver ID */
#define VMEM_30_TRAVEO2CYP01_DRIVER_ID                 0x7F2D1688u

/* Add here additional general GLOBAL CONSTANT MACROS */


/* Add hw specific includes */
# include "vMem_30_Traveo2Cyp01_Extended_Func.h"

/* Add hw specific defines */

/* Register base address of used peripherals */
# define VMEM_30_TRAVEO2CYP01_BASE_FLASHC                                0x40240000u
# define VMEM_30_TRAVEO2CYP01_BASE_IPC                                   0x40220000u
# define VMEM_30_TRAVEO2CYP01_BASE_FAULT                                 0x40210000u

/*! IPC Get Lock Timeout Counter Value */
# define VMEM_30_TRAVEO2CYP01_IPC_GET_LOCK_TIMEOUT_COUNTER_MAX_VALUE     10u

/*! IPC structure Id */
# define VMEM_30_TRAVEO2CYP01_IPC_STRUCT_ID                              1u

/*! Master IPC interrupt structure Id */
# define VMEM_30_TRAVEO2CYP01_MASTER_IPC_INTR_ID                         0u

/*! Slave IPC interrupt structure Id */
# define VMEM_30_TRAVEO2CYP01_SLAVE_IPC_INTR_ID                          2u

/*! Aligned write buffer size */
# define VMEM_30_TRAVEO2CYP01_WRITE_BUFFER_SIZE                          1u

# define VMEM_30_TRAVEO2CYP01_OS_MEM_AREA_FAULT                          0u
# define VMEM_30_TRAVEO2CYP01_OS_MEM_AREA_IPC                            0u
# define VMEM_30_TRAVEO2CYP01_OS_MEM_AREA_FLASHC                         0u

# define vMem_30_Traveo2Cyp01_Os_PeripheralIdType                        uint8

# define vMem_30_Traveo2Cyp01_CallOsWritePeripheral32(PeripheralID, Address, Value)
# define vMem_30_Traveo2Cyp01_CallOsReadPeripheral32(PeripheralID, Address)              0u

// # include "Det.h"

#define vMem_30_Traveo2Cyp01_CallDetErrorReporting(ModuleId, InstanceId, ApiId, ErrorId) /* ((void)Det_ReportError((ModuleId), (InstanceId), (ApiId), (ErrorId)))*/


/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  vMem_30_Traveo2Cyp01PCDataSwitches  vMem_30_Traveo2Cyp01 Data Switches  (PRE_COMPILE)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define VMEM_30_TRAVEO2CYP01_DEVERRORDETECTENABLED                    STD_ON
#define VMEM_30_TRAVEO2CYP01_DEVERRORREPORTENABLED                    STD_ON
#define VMEM_30_TRAVEO2CYP01_FINALMAGICNUMBER                         STD_OFF  /**< Deactivateable: 'vMem_30_Traveo2Cyp01_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define VMEM_30_TRAVEO2CYP01_INITDATAHASHCODE                         STD_OFF  /**< Deactivateable: 'vMem_30_Traveo2Cyp01_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define VMEM_30_TRAVEO2CYP01_MEMSECTOR                                STD_ON
#define VMEM_30_TRAVEO2CYP01_ERASEBURSTSIZEOFMEMSECTOR                STD_ON
#define VMEM_30_TRAVEO2CYP01_FLASHTYPEOFMEMSECTOR                     STD_ON
#define VMEM_30_TRAVEO2CYP01_NROFSECTORSOFMEMSECTOR                   STD_ON
#define VMEM_30_TRAVEO2CYP01_PAGESIZEOFMEMSECTOR                      STD_ON
#define VMEM_30_TRAVEO2CYP01_RAMALIGNMENTOFMEMSECTOR                  STD_ON
#define VMEM_30_TRAVEO2CYP01_SECTORSIZEOFMEMSECTOR                    STD_ON
#define VMEM_30_TRAVEO2CYP01_STARTADDRESSOFMEMSECTOR                  STD_ON
#define VMEM_30_TRAVEO2CYP01_WRITEBURSTSIZEOFMEMSECTOR                STD_ON
#define VMEM_30_TRAVEO2CYP01_SIZEOFMEMSECTOR                          STD_ON
#define VMEM_30_TRAVEO2CYP01_SIZEOFVMEMINSTANCE                       STD_ON
#define VMEM_30_TRAVEO2CYP01_SUPPRESSECCERRORSENABLED                 STD_ON
#define VMEM_30_TRAVEO2CYP01_USEPERIPHERALACCESSAPIENABLED            STD_ON
#define VMEM_30_TRAVEO2CYP01_VMEMINSTANCE                             STD_ON
#define VMEM_30_TRAVEO2CYP01_IDOFVMEMINSTANCE                         STD_ON
#define VMEM_30_TRAVEO2CYP01_MEMSECTORENDIDXOFVMEMINSTANCE            STD_ON
#define VMEM_30_TRAVEO2CYP01_MEMSECTORLENGTHOFVMEMINSTANCE            STD_ON
#define VMEM_30_TRAVEO2CYP01_MEMSECTORSTARTIDXOFVMEMINSTANCE          STD_ON
#define VMEM_30_TRAVEO2CYP01_PCCONFIG                                 STD_ON
#define VMEM_30_TRAVEO2CYP01_DEVERRORDETECTENABLEDOFPCCONFIG          STD_ON
#define VMEM_30_TRAVEO2CYP01_DEVERRORREPORTENABLEDOFPCCONFIG          STD_ON
#define VMEM_30_TRAVEO2CYP01_FINALMAGICNUMBEROFPCCONFIG               STD_OFF  /**< Deactivateable: 'vMem_30_Traveo2Cyp01_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define VMEM_30_TRAVEO2CYP01_INITDATAHASHCODEOFPCCONFIG               STD_OFF  /**< Deactivateable: 'vMem_30_Traveo2Cyp01_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define VMEM_30_TRAVEO2CYP01_MEMSECTOROFPCCONFIG                      STD_ON
#define VMEM_30_TRAVEO2CYP01_SIZEOFMEMSECTOROFPCCONFIG                STD_ON
#define VMEM_30_TRAVEO2CYP01_SIZEOFVMEMINSTANCEOFPCCONFIG             STD_ON
#define VMEM_30_TRAVEO2CYP01_SUPPRESSECCERRORSENABLEDOFPCCONFIG       STD_ON
#define VMEM_30_TRAVEO2CYP01_USEPERIPHERALACCESSAPIENABLEDOFPCCONFIG  STD_ON
#define VMEM_30_TRAVEO2CYP01_VMEMINSTANCEOFPCCONFIG                   STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  vMem_30_Traveo2Cyp01PCIsReducedToDefineDefines  vMem_30_Traveo2Cyp01 Is Reduced To Define Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define is STD_ON else STD_OFF.
  \{
*/ 
#define VMEM_30_TRAVEO2CYP01_ISDEF_ERASEBURSTSIZEOFMEMSECTOR          STD_OFF
#define VMEM_30_TRAVEO2CYP01_ISDEF_FLASHTYPEOFMEMSECTOR               STD_OFF
#define VMEM_30_TRAVEO2CYP01_ISDEF_NROFSECTORSOFMEMSECTOR             STD_OFF
#define VMEM_30_TRAVEO2CYP01_ISDEF_PAGESIZEOFMEMSECTOR                STD_OFF
#define VMEM_30_TRAVEO2CYP01_ISDEF_RAMALIGNMENTOFMEMSECTOR            STD_OFF
#define VMEM_30_TRAVEO2CYP01_ISDEF_SECTORSIZEOFMEMSECTOR              STD_OFF
#define VMEM_30_TRAVEO2CYP01_ISDEF_STARTADDRESSOFMEMSECTOR            STD_OFF
#define VMEM_30_TRAVEO2CYP01_ISDEF_WRITEBURSTSIZEOFMEMSECTOR          STD_OFF
#define VMEM_30_TRAVEO2CYP01_ISDEF_IDOFVMEMINSTANCE                   STD_OFF
#define VMEM_30_TRAVEO2CYP01_ISDEF_MEMSECTORENDIDXOFVMEMINSTANCE      STD_OFF
#define VMEM_30_TRAVEO2CYP01_ISDEF_MEMSECTORLENGTHOFVMEMINSTANCE      STD_OFF
#define VMEM_30_TRAVEO2CYP01_ISDEF_MEMSECTORSTARTIDXOFVMEMINSTANCE    STD_OFF
#define VMEM_30_TRAVEO2CYP01_ISDEF_MEMSECTOROFPCCONFIG                STD_ON
#define VMEM_30_TRAVEO2CYP01_ISDEF_VMEMINSTANCEOFPCCONFIG             STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  vMem_30_Traveo2Cyp01PCEqualsAlwaysToDefines  vMem_30_Traveo2Cyp01 Equals Always To Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define contains the always equals value.
  \{
*/ 
#define VMEM_30_TRAVEO2CYP01_EQ2_ERASEBURSTSIZEOFMEMSECTOR            
#define VMEM_30_TRAVEO2CYP01_EQ2_FLASHTYPEOFMEMSECTOR                 
#define VMEM_30_TRAVEO2CYP01_EQ2_NROFSECTORSOFMEMSECTOR               
#define VMEM_30_TRAVEO2CYP01_EQ2_PAGESIZEOFMEMSECTOR                  
#define VMEM_30_TRAVEO2CYP01_EQ2_RAMALIGNMENTOFMEMSECTOR              
#define VMEM_30_TRAVEO2CYP01_EQ2_SECTORSIZEOFMEMSECTOR                
#define VMEM_30_TRAVEO2CYP01_EQ2_STARTADDRESSOFMEMSECTOR              
#define VMEM_30_TRAVEO2CYP01_EQ2_WRITEBURSTSIZEOFMEMSECTOR            
#define VMEM_30_TRAVEO2CYP01_EQ2_IDOFVMEMINSTANCE                     
#define VMEM_30_TRAVEO2CYP01_EQ2_MEMSECTORENDIDXOFVMEMINSTANCE        
#define VMEM_30_TRAVEO2CYP01_EQ2_MEMSECTORLENGTHOFVMEMINSTANCE        
#define VMEM_30_TRAVEO2CYP01_EQ2_MEMSECTORSTARTIDXOFVMEMINSTANCE      
#define VMEM_30_TRAVEO2CYP01_EQ2_MEMSECTOROFPCCONFIG                  vMem_30_Traveo2Cyp01_MemSector
#define VMEM_30_TRAVEO2CYP01_EQ2_VMEMINSTANCEOFPCCONFIG               vMem_30_Traveo2Cyp01_vMemInstance
/** 
  \}
*/ 

/** 
  \defgroup  vMem_30_Traveo2Cyp01PCSymbolicInitializationPointers  vMem_30_Traveo2Cyp01 Symbolic Initialization Pointers (PRE_COMPILE)
  \brief  Symbolic initialization pointers to be used in the call of a preinit or init function.
  \{
*/ 
#define vMem_30_Traveo2Cyp01_Config_Ptr                               NULL_PTR  /**< symbolic identifier which shall be used to initialize 'vMem_30_Traveo2Cyp01' */
/** 
  \}
*/ 

/** 
  \defgroup  vMem_30_Traveo2Cyp01PCInitializationSymbols  vMem_30_Traveo2Cyp01 Initialization Symbols (PRE_COMPILE)
  \brief  Symbolic initialization pointers which may be used in the call of a preinit or init function. Please note, that the defined value can be a 'NULL_PTR' and the address operator is not usable.
  \{
*/ 
#define vMem_30_Traveo2Cyp01_Config                                   NULL_PTR  /**< symbolic identifier which could be used to initialize 'vMem_30_Traveo2Cyp01 */
/** 
  \}
*/ 

/** 
  \defgroup  vMem_30_Traveo2Cyp01PCGeneral  vMem_30_Traveo2Cyp01 General (PRE_COMPILE)
  \brief  General constant defines not associated with a group of defines.
  \{
*/ 
#define VMEM_30_TRAVEO2CYP01_CHECK_INIT_POINTER                       STD_OFF  /**< STD_ON if the init pointer shall not be used as NULL_PTR and a check shall validate this. */
#define VMEM_30_TRAVEO2CYP01_FINAL_MAGIC_NUMBER                       0xFF1Eu  /**< the precompile constant to validate the size of the initialization structure at initialization time of vMem_30_Traveo2Cyp01 */
#define VMEM_30_TRAVEO2CYP01_INDIVIDUAL_POSTBUILD                     STD_OFF  /**< the precompile constant to check, that the module is individual postbuildable. The module 'vMem_30_Traveo2Cyp01' is not configured to be postbuild capable. */
#define VMEM_30_TRAVEO2CYP01_INIT_DATA                                VMEM_30_TRAVEO2CYP01_CONST  /**< CompilerMemClassDefine for the initialization data. */
#define VMEM_30_TRAVEO2CYP01_INIT_DATA_HASH_CODE                      23337485  /**< the precompile constant to validate the initialization structure at initialization time of vMem_30_Traveo2Cyp01 with a hashcode. The seed value is '0xFF1Eu' */
#define VMEM_30_TRAVEO2CYP01_USE_ECUM_BSW_ERROR_HOOK                  STD_OFF  /**< STD_ON if the EcuM_BswErrorHook shall be called in the ConfigPtr check. */
#define VMEM_30_TRAVEO2CYP01_USE_INIT_POINTER                         STD_OFF  /**< STD_ON if the init pointer vMem_30_Traveo2Cyp01 shall be used. */
/** 
  \}
*/ 



/**********************************************************************************************************************
  GLOBAL FUNCTION MACROS
**********************************************************************************************************************/
/** 
  \defgroup  DataAccessMacros  Data Access Macros
  \brief  generated data access macros to abstract the generated data from the code to read and write CONST or VAR data.
  \{
*/ 
  /* PRQA S 3453 Macros_3453 */  /* MD_MSR_FctLikeMacro */
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTION MACROS
**********************************************************************************************************************/
/** 
  \defgroup  vMem_30_Traveo2Cyp01PCGetConstantDuplicatedRootDataMacros  vMem_30_Traveo2Cyp01 Get Constant Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated by constance root data elements.
  \{
*/ 
#define vMem_30_Traveo2Cyp01_IsDevErrorDetectEnabledOfPCConfig()      (((TRUE)) != FALSE)  /**< Indicates if DEV_ERROR_DETECT is STD_ON. */
#define vMem_30_Traveo2Cyp01_IsDevErrorReportEnabledOfPCConfig()      (((TRUE)) != FALSE)  /**< Indicates if DEV_ERROR_REPORT is STD_ON. */
#define vMem_30_Traveo2Cyp01_GetMemSectorOfPCConfig()                 vMem_30_Traveo2Cyp01_MemSector  /**< the pointer to vMem_30_Traveo2Cyp01_MemSector */
#define vMem_30_Traveo2Cyp01_GetSizeOfMemSectorOfPCConfig()           2u  /**< the number of accomplishable value elements in vMem_30_Traveo2Cyp01_MemSector */
#define vMem_30_Traveo2Cyp01_GetSizeOfvMemInstanceOfPCConfig()        1u  /**< the number of accomplishable value elements in vMem_30_Traveo2Cyp01_vMemInstance */
#define vMem_30_Traveo2Cyp01_IsSuppressEccErrorsEnabledOfPCConfig()   (((TRUE)) != FALSE)  /**< Indicates if suppressEccErrors is enabled. */
#define vMem_30_Traveo2Cyp01_IsUsePeripheralAccessApiEnabledOfPCConfig() (((FALSE)) != FALSE)  /**< Indicates if vMemUsePeripheralAccessApi is enabled. */
#define vMem_30_Traveo2Cyp01_GetvMemInstanceOfPCConfig()              vMem_30_Traveo2Cyp01_vMemInstance  /**< the pointer to vMem_30_Traveo2Cyp01_vMemInstance */
/** 
  \}
*/ 

/** 
  \defgroup  vMem_30_Traveo2Cyp01PCGetDataMacros  vMem_30_Traveo2Cyp01 Get Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read CONST and VAR data.
  \{
*/ 
#define vMem_30_Traveo2Cyp01_GetEraseBurstSizeOfMemSector(Index)      (vMem_30_Traveo2Cyp01_GetMemSectorOfPCConfig()[(Index)].EraseBurstSizeOfMemSector)
#define vMem_30_Traveo2Cyp01_GetFlashTypeOfMemSector(Index)           (vMem_30_Traveo2Cyp01_GetMemSectorOfPCConfig()[(Index)].FlashTypeOfMemSector)
#define vMem_30_Traveo2Cyp01_GetNrOfSectorsOfMemSector(Index)         (vMem_30_Traveo2Cyp01_GetMemSectorOfPCConfig()[(Index)].NrOfSectorsOfMemSector)
#define vMem_30_Traveo2Cyp01_GetPageSizeOfMemSector(Index)            (vMem_30_Traveo2Cyp01_GetMemSectorOfPCConfig()[(Index)].PageSizeOfMemSector)
#define vMem_30_Traveo2Cyp01_GetRamAlignmentOfMemSector(Index)        (vMem_30_Traveo2Cyp01_GetMemSectorOfPCConfig()[(Index)].RamAlignmentOfMemSector)
#define vMem_30_Traveo2Cyp01_GetSectorSizeOfMemSector(Index)          (vMem_30_Traveo2Cyp01_GetMemSectorOfPCConfig()[(Index)].SectorSizeOfMemSector)
#define vMem_30_Traveo2Cyp01_GetStartAddressOfMemSector(Index)        (vMem_30_Traveo2Cyp01_GetMemSectorOfPCConfig()[(Index)].StartAddressOfMemSector)
#define vMem_30_Traveo2Cyp01_GetWriteBurstSizeOfMemSector(Index)      (vMem_30_Traveo2Cyp01_GetMemSectorOfPCConfig()[(Index)].WriteBurstSizeOfMemSector)
#define vMem_30_Traveo2Cyp01_GetIdOfvMemInstance(Index)               (vMem_30_Traveo2Cyp01_GetvMemInstanceOfPCConfig()[(Index)].IdOfvMemInstance)
#define vMem_30_Traveo2Cyp01_GetMemSectorEndIdxOfvMemInstance(Index)  (vMem_30_Traveo2Cyp01_GetvMemInstanceOfPCConfig()[(Index)].MemSectorEndIdxOfvMemInstance)
#define vMem_30_Traveo2Cyp01_GetMemSectorLengthOfvMemInstance(Index)  (vMem_30_Traveo2Cyp01_GetvMemInstanceOfPCConfig()[(Index)].MemSectorLengthOfvMemInstance)
#define vMem_30_Traveo2Cyp01_GetMemSectorStartIdxOfvMemInstance(Index) (vMem_30_Traveo2Cyp01_GetvMemInstanceOfPCConfig()[(Index)].MemSectorStartIdxOfvMemInstance)
/** 
  \}
*/ 

/** 
  \defgroup  vMem_30_Traveo2Cyp01PCGetDeduplicatedDataMacros  vMem_30_Traveo2Cyp01 Get Deduplicated Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated data elements.
  \{
*/ 
#define vMem_30_Traveo2Cyp01_IsDevErrorDetectEnabled()                vMem_30_Traveo2Cyp01_IsDevErrorDetectEnabledOfPCConfig()
#define vMem_30_Traveo2Cyp01_IsDevErrorReportEnabled()                vMem_30_Traveo2Cyp01_IsDevErrorReportEnabledOfPCConfig()
#define vMem_30_Traveo2Cyp01_GetSizeOfMemSector()                     vMem_30_Traveo2Cyp01_GetSizeOfMemSectorOfPCConfig()
#define vMem_30_Traveo2Cyp01_GetSizeOfvMemInstance()                  vMem_30_Traveo2Cyp01_GetSizeOfvMemInstanceOfPCConfig()
#define vMem_30_Traveo2Cyp01_IsSuppressEccErrorsEnabled()             vMem_30_Traveo2Cyp01_IsSuppressEccErrorsEnabledOfPCConfig()
#define vMem_30_Traveo2Cyp01_IsUsePeripheralAccessApiEnabled()        vMem_30_Traveo2Cyp01_IsUsePeripheralAccessApiEnabledOfPCConfig()
/** 
  \}
*/ 

/** 
  \defgroup  vMem_30_Traveo2Cyp01PCHasMacros  vMem_30_Traveo2Cyp01 Has Macros (PRE_COMPILE)
  \brief  These macros can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
#define vMem_30_Traveo2Cyp01_HasDevErrorDetectEnabled()               (TRUE != FALSE)
#define vMem_30_Traveo2Cyp01_HasDevErrorReportEnabled()               (TRUE != FALSE)
#define vMem_30_Traveo2Cyp01_HasMemSector()                           (TRUE != FALSE)
#define vMem_30_Traveo2Cyp01_HasEraseBurstSizeOfMemSector()           (TRUE != FALSE)
#define vMem_30_Traveo2Cyp01_HasFlashTypeOfMemSector()                (TRUE != FALSE)
#define vMem_30_Traveo2Cyp01_HasNrOfSectorsOfMemSector()              (TRUE != FALSE)
#define vMem_30_Traveo2Cyp01_HasPageSizeOfMemSector()                 (TRUE != FALSE)
#define vMem_30_Traveo2Cyp01_HasRamAlignmentOfMemSector()             (TRUE != FALSE)
#define vMem_30_Traveo2Cyp01_HasSectorSizeOfMemSector()               (TRUE != FALSE)
#define vMem_30_Traveo2Cyp01_HasStartAddressOfMemSector()             (TRUE != FALSE)
#define vMem_30_Traveo2Cyp01_HasWriteBurstSizeOfMemSector()           (TRUE != FALSE)
#define vMem_30_Traveo2Cyp01_HasSizeOfMemSector()                     (TRUE != FALSE)
#define vMem_30_Traveo2Cyp01_HasSizeOfvMemInstance()                  (TRUE != FALSE)
#define vMem_30_Traveo2Cyp01_HasSuppressEccErrorsEnabled()            (TRUE != FALSE)
#define vMem_30_Traveo2Cyp01_HasUsePeripheralAccessApiEnabled()       (TRUE != FALSE)
#define vMem_30_Traveo2Cyp01_HasvMemInstance()                        (TRUE != FALSE)
#define vMem_30_Traveo2Cyp01_HasIdOfvMemInstance()                    (TRUE != FALSE)
#define vMem_30_Traveo2Cyp01_HasMemSectorEndIdxOfvMemInstance()       (TRUE != FALSE)
#define vMem_30_Traveo2Cyp01_HasMemSectorLengthOfvMemInstance()       (TRUE != FALSE)
#define vMem_30_Traveo2Cyp01_HasMemSectorStartIdxOfvMemInstance()     (TRUE != FALSE)
#define vMem_30_Traveo2Cyp01_HasPCConfig()                            (TRUE != FALSE)
#define vMem_30_Traveo2Cyp01_HasDevErrorDetectEnabledOfPCConfig()     (TRUE != FALSE)
#define vMem_30_Traveo2Cyp01_HasDevErrorReportEnabledOfPCConfig()     (TRUE != FALSE)
#define vMem_30_Traveo2Cyp01_HasMemSectorOfPCConfig()                 (TRUE != FALSE)
#define vMem_30_Traveo2Cyp01_HasSizeOfMemSectorOfPCConfig()           (TRUE != FALSE)
#define vMem_30_Traveo2Cyp01_HasSizeOfvMemInstanceOfPCConfig()        (TRUE != FALSE)
#define vMem_30_Traveo2Cyp01_HasSuppressEccErrorsEnabledOfPCConfig()  (TRUE != FALSE)
#define vMem_30_Traveo2Cyp01_HasUsePeripheralAccessApiEnabledOfPCConfig() (TRUE != FALSE)
#define vMem_30_Traveo2Cyp01_HasvMemInstanceOfPCConfig()              (TRUE != FALSE)
/** 
  \}
*/ 

  /* PRQA L:Macros_3453 */
/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL ACCESS FUNCTION MACROS
**********************************************************************************************************************/


/**********************************************************************************************************************
  GLOBAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  vMem_30_Traveo2Cyp01PCIterableTypes  vMem_30_Traveo2Cyp01 Iterable Types (PRE_COMPILE)
  \brief  These type definitions are used to iterate over an array with least processor cycles for variable access as possible.
  \{
*/ 
/**   \brief  type used to iterate vMem_30_Traveo2Cyp01_MemSector */
typedef uint8_least vMem_30_Traveo2Cyp01_MemSectorIterType;

/**   \brief  type used to iterate vMem_30_Traveo2Cyp01_vMemInstance */
typedef uint8_least vMem_30_Traveo2Cyp01_vMemInstanceIterType;

/** 
  \}
*/ 

/** 
  \defgroup  vMem_30_Traveo2Cyp01PCValueTypes  vMem_30_Traveo2Cyp01 Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value based data representations.
  \{
*/ 
/**   \brief  value based type definition for vMem_30_Traveo2Cyp01_DevErrorDetectEnabled */
typedef boolean vMem_30_Traveo2Cyp01_DevErrorDetectEnabledType;

/**   \brief  value based type definition for vMem_30_Traveo2Cyp01_DevErrorReportEnabled */
typedef boolean vMem_30_Traveo2Cyp01_DevErrorReportEnabledType;

/**   \brief  value based type definition for vMem_30_Traveo2Cyp01_EraseBurstSizeOfMemSector */
typedef uint16 vMem_30_Traveo2Cyp01_EraseBurstSizeOfMemSectorType;

/**   \brief  value based type definition for vMem_30_Traveo2Cyp01_NrOfSectorsOfMemSector */
typedef uint8 vMem_30_Traveo2Cyp01_NrOfSectorsOfMemSectorType;

/**   \brief  value based type definition for vMem_30_Traveo2Cyp01_PageSizeOfMemSector */
typedef uint8 vMem_30_Traveo2Cyp01_PageSizeOfMemSectorType;

/**   \brief  value based type definition for vMem_30_Traveo2Cyp01_RamAlignmentOfMemSector */
typedef uint8 vMem_30_Traveo2Cyp01_RamAlignmentOfMemSectorType;

/**   \brief  value based type definition for vMem_30_Traveo2Cyp01_SectorSizeOfMemSector */
typedef uint16 vMem_30_Traveo2Cyp01_SectorSizeOfMemSectorType;

/**   \brief  value based type definition for vMem_30_Traveo2Cyp01_StartAddressOfMemSector */
typedef uint32 vMem_30_Traveo2Cyp01_StartAddressOfMemSectorType;

/**   \brief  value based type definition for vMem_30_Traveo2Cyp01_WriteBurstSizeOfMemSector */
typedef uint8 vMem_30_Traveo2Cyp01_WriteBurstSizeOfMemSectorType;

/**   \brief  value based type definition for vMem_30_Traveo2Cyp01_SizeOfMemSector */
typedef uint8 vMem_30_Traveo2Cyp01_SizeOfMemSectorType;

/**   \brief  value based type definition for vMem_30_Traveo2Cyp01_SizeOfvMemInstance */
typedef uint8 vMem_30_Traveo2Cyp01_SizeOfvMemInstanceType;

/**   \brief  value based type definition for vMem_30_Traveo2Cyp01_SuppressEccErrorsEnabled */
typedef boolean vMem_30_Traveo2Cyp01_SuppressEccErrorsEnabledType;

/**   \brief  value based type definition for vMem_30_Traveo2Cyp01_UsePeripheralAccessApiEnabled */
typedef boolean vMem_30_Traveo2Cyp01_UsePeripheralAccessApiEnabledType;

/**   \brief  value based type definition for vMem_30_Traveo2Cyp01_IdOfvMemInstance */
typedef uint8 vMem_30_Traveo2Cyp01_IdOfvMemInstanceType;

/**   \brief  value based type definition for vMem_30_Traveo2Cyp01_MemSectorEndIdxOfvMemInstance */
typedef uint8 vMem_30_Traveo2Cyp01_MemSectorEndIdxOfvMemInstanceType;

/**   \brief  value based type definition for vMem_30_Traveo2Cyp01_MemSectorLengthOfvMemInstance */
typedef uint8 vMem_30_Traveo2Cyp01_MemSectorLengthOfvMemInstanceType;

/**   \brief  value based type definition for vMem_30_Traveo2Cyp01_MemSectorStartIdxOfvMemInstance */
typedef uint8 vMem_30_Traveo2Cyp01_MemSectorStartIdxOfvMemInstanceType;

/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  vMem_30_Traveo2Cyp01PCStructTypes  vMem_30_Traveo2Cyp01 Struct Types (PRE_COMPILE)
  \brief  These type definitions are used for structured data representations.
  \{
*/ 
/**   \brief  type used in vMem_30_Traveo2Cyp01_MemSector */
typedef struct svMem_30_Traveo2Cyp01_MemSectorType
{
  vMem_30_Traveo2Cyp01_StartAddressOfMemSectorType StartAddressOfMemSector;  /**< Physical start address of the first sector. */
  vMem_30_Traveo2Cyp01_EraseBurstSizeOfMemSectorType EraseBurstSizeOfMemSector;  /**< Burst size for erase jobs, if configured. Otherwise sector size */
  vMem_30_Traveo2Cyp01_SectorSizeOfMemSectorType SectorSizeOfMemSector;  /**< Size of this sector in bytes. */
  vMem_30_Traveo2Cyp01_NrOfSectorsOfMemSectorType NrOfSectorsOfMemSector;  /**< Number of continuous sectors with identical values for vMemSectorSize and vMemPageSize. */
  vMem_30_Traveo2Cyp01_PageSizeOfMemSectorType PageSizeOfMemSector;  /**< Size of one page of this sector in bytes. */
  vMem_30_Traveo2Cyp01_RamAlignmentOfMemSectorType RamAlignmentOfMemSector;  /**< In order to perform write jobs correctly, a device might require a specific alignment of the data buffer. */
  vMem_30_Traveo2Cyp01_WriteBurstSizeOfMemSectorType WriteBurstSizeOfMemSector;  /**< Burst size for write jobs, if configured. Otherwise page size */
  vMem_30_Traveo2Cyp01_FlashTypeType FlashTypeOfMemSector;  /**< Flash type of this sector. */
} vMem_30_Traveo2Cyp01_MemSectorType;

/**   \brief  type used in vMem_30_Traveo2Cyp01_vMemInstance */
typedef struct svMem_30_Traveo2Cyp01_vMemInstanceType
{
  vMem_30_Traveo2Cyp01_IdOfvMemInstanceType IdOfvMemInstance;  /**< Unique numeric identifier of the instance, used to distinguish between vMem instances. */
  vMem_30_Traveo2Cyp01_MemSectorEndIdxOfvMemInstanceType MemSectorEndIdxOfvMemInstance;  /**< the end index of the 1:n relation pointing to vMem_30_Traveo2Cyp01_MemSector */
  vMem_30_Traveo2Cyp01_MemSectorLengthOfvMemInstanceType MemSectorLengthOfvMemInstance;  /**< the number of relations pointing to vMem_30_Traveo2Cyp01_MemSector */
  vMem_30_Traveo2Cyp01_MemSectorStartIdxOfvMemInstanceType MemSectorStartIdxOfvMemInstance;  /**< the start index of the 1:n relation pointing to vMem_30_Traveo2Cyp01_MemSector */
} vMem_30_Traveo2Cyp01_vMemInstanceType;

/** 
  \}
*/ 

/** 
  \defgroup  vMem_30_Traveo2Cyp01PCRootPointerTypes  vMem_30_Traveo2Cyp01 Root Pointer Types (PRE_COMPILE)
  \brief  These type definitions are used to point from the config root to symbol instances.
  \{
*/ 
/**   \brief  type used to point to vMem_30_Traveo2Cyp01_MemSector */
typedef P2CONST(vMem_30_Traveo2Cyp01_MemSectorType, TYPEDEF, VMEM_30_TRAVEO2CYP01_CONST) vMem_30_Traveo2Cyp01_MemSectorPtrType;

/**   \brief  type used to point to vMem_30_Traveo2Cyp01_vMemInstance */
typedef P2CONST(vMem_30_Traveo2Cyp01_vMemInstanceType, TYPEDEF, VMEM_30_TRAVEO2CYP01_CONST) vMem_30_Traveo2Cyp01_vMemInstancePtrType;

/** 
  \}
*/ 

/** 
  \defgroup  vMem_30_Traveo2Cyp01PCRootValueTypes  vMem_30_Traveo2Cyp01 Root Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value representations in root arrays.
  \{
*/ 
/**   \brief  type used in vMem_30_Traveo2Cyp01_PCConfig */
typedef struct svMem_30_Traveo2Cyp01_PCConfigType
{
  uint8 vMem_30_Traveo2Cyp01_PCConfigNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} vMem_30_Traveo2Cyp01_PCConfigType;

typedef vMem_30_Traveo2Cyp01_PCConfigType vMem_30_Traveo2Cyp01_ConfigType;  /**< A structure type is present for data in each configuration class. This typedef redefines the probably different name to the specified one. */

/** 
  \}
*/ 



/**********************************************************************************************************************
  GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  vMem_30_Traveo2Cyp01_MemSector
**********************************************************************************************************************/
/** 
  \var    vMem_30_Traveo2Cyp01_MemSector
  \brief  Configuration description of a programmable sector or sector batch.
  \details
  Element           Description
  StartAddress      Physical start address of the first sector.
  EraseBurstSize    Burst size for erase jobs, if configured. Otherwise sector size
  SectorSize        Size of this sector in bytes.
  NrOfSectors       Number of continuous sectors with identical values for vMemSectorSize and vMemPageSize.
  PageSize          Size of one page of this sector in bytes.
  RamAlignment      In order to perform write jobs correctly, a device might require a specific alignment of the data buffer.
  WriteBurstSize    Burst size for write jobs, if configured. Otherwise page size
  FlashType         Flash type of this sector.
*/ 
#define VMEM_30_TRAVEO2CYP01_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(vMem_30_Traveo2Cyp01_MemSectorType, VMEM_30_TRAVEO2CYP01_CONST) vMem_30_Traveo2Cyp01_MemSector[2];
#define VMEM_30_TRAVEO2CYP01_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  vMem_30_Traveo2Cyp01_vMemInstance
**********************************************************************************************************************/
/** 
  \var    vMem_30_Traveo2Cyp01_vMemInstance
  \brief  List of all configured vMem instances.
  \details
  Element              Description
  Id                   Unique numeric identifier of the instance, used to distinguish between vMem instances.
  MemSectorEndIdx      the end index of the 1:n relation pointing to vMem_30_Traveo2Cyp01_MemSector
  MemSectorLength      the number of relations pointing to vMem_30_Traveo2Cyp01_MemSector
  MemSectorStartIdx    the start index of the 1:n relation pointing to vMem_30_Traveo2Cyp01_MemSector
*/ 
#define VMEM_30_TRAVEO2CYP01_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(vMem_30_Traveo2Cyp01_vMemInstanceType, VMEM_30_TRAVEO2CYP01_CONST) vMem_30_Traveo2Cyp01_vMemInstance[1];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define VMEM_30_TRAVEO2CYP01_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */



/**********************************************************************************************************************
  GLOBAL INLINE FUNCTION PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL INLINE FUNCTION PROTOTYPES
**********************************************************************************************************************/


/**********************************************************************************************************************
  GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/


#endif /* VMEM_30_TRAVEO2CYP01_CFG_H */
