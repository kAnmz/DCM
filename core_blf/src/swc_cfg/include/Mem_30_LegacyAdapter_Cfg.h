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
 *            Module: Mem_30_LegacyAdapter
 *           Program: MSR_Geely_SLP2
 *          Customer: Marelli Automotive Electronics (Guangzhou) Co., Ltd
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: CYT2B75BA
 *    License Scope : The usage is restricted to CBD2600619_D00
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Mem_30_LegacyAdapter_Cfg.h
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

#ifndef MEM_30_LEGACYADAPTER_CFG_H
# define MEM_30_LEGACYADAPTER_CFG_H

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
# include "Std_Types.h"
// # include "Det.h"
# include "Mem_30_LegacyAdapter_Types.h"
# include "vMem_30_Traveo2Cyp01.h"

/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/
/* Configuration major version identification. */
# define MEM_30_LEGACYADAPTER_CFG_MAJOR_VERSION (2u)
/* Configuration minor version identification. */
# define MEM_30_LEGACYADAPTER_CFG_MINOR_VERSION (0u)

/* Defines whether development error detection or reporting is enabled (STD_ON) or not (STD_OFF). */
# define MEM_30_LEGACYADAPTER_DEV_ERROR_DETECT                                                      STD_ON
# define MEM_30_LEGACYADAPTER_DEV_ERROR_REPORT                                                      STD_OFF

/*! Mem driver ID */
#define MEM_30_LEGACYADAPTER_DRIVER_ID 0x69EBFA0Eu

# if !defined (MEM_30_LEGACYADAPTER_LOCAL_INLINE)
#  define MEM_30_LEGACYADAPTER_LOCAL_INLINE LOCAL_INLINE
# endif

# define MEM_30_LEGACYADAPTER_MEMIFTYPESENABLED                                                     STD_OFF
# define MEM_30_LEGACYADAPTER_VMEMTYPESENABLED                                                      STD_ON

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  Mem_30_LegacyAdapterPCDataSwitches  Mem_30_LegacyAdapter Data Switches  (PRE_COMPILE)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define MEM_30_LEGACYADAPTER_FINALMAGICNUMBER                                                       STD_OFF  /**< the module configuration does not support flashing of data. */
#define MEM_30_LEGACYADAPTER_INITDATAHASHCODE                                                       STD_OFF  /**< the module configuration does not support flashing of data. */
#define MEM_30_LEGACYADAPTER_LLAPI                                                                  STD_ON
#define MEM_30_LEGACYADAPTER_ERASEOFLLAPI                                                           STD_ON
#define MEM_30_LEGACYADAPTER_GETJOBRESULTOFLLAPI                                                    STD_ON
#define MEM_30_LEGACYADAPTER_HWFUNCTIONSOFLLAPI                                                     STD_ON
#define MEM_30_LEGACYADAPTER_INITOFLLAPI                                                            STD_ON
#define MEM_30_LEGACYADAPTER_ISBLANKOFLLAPI                                                         STD_ON
#define MEM_30_LEGACYADAPTER_MAINFUNCTIONOFLLAPI                                                    STD_ON
#define MEM_30_LEGACYADAPTER_READOFLLAPI                                                            STD_ON
#define MEM_30_LEGACYADAPTER_WRITEOFLLAPI                                                           STD_ON
#define MEM_30_LEGACYADAPTER_MEMINSTANCEIDMAPPING                                                   STD_ON
#define MEM_30_LEGACYADAPTER_LLAPIIDXOFMEMINSTANCEIDMAPPING                                         STD_ON
#define MEM_30_LEGACYADAPTER_LLINSTANCEIDOFMEMINSTANCEIDMAPPING                                     STD_ON
#define MEM_30_LEGACYADAPTER_SIZEOFLLAPI                                                            STD_ON
#define MEM_30_LEGACYADAPTER_SIZEOFMEMINSTANCEIDMAPPING                                             STD_ON
#define MEM_30_LEGACYADAPTER_PCCONFIG                                                               STD_ON
#define MEM_30_LEGACYADAPTER_FINALMAGICNUMBEROFPCCONFIG                                             STD_OFF  /**< the module configuration does not support flashing of data. */
#define MEM_30_LEGACYADAPTER_INITDATAHASHCODEOFPCCONFIG                                             STD_OFF  /**< the module configuration does not support flashing of data. */
#define MEM_30_LEGACYADAPTER_LLAPIOFPCCONFIG                                                        STD_ON
#define MEM_30_LEGACYADAPTER_MEMINSTANCEIDMAPPINGOFPCCONFIG                                         STD_ON
#define MEM_30_LEGACYADAPTER_SIZEOFLLAPIOFPCCONFIG                                                  STD_ON
#define MEM_30_LEGACYADAPTER_SIZEOFMEMINSTANCEIDMAPPINGOFPCCONFIG                                   STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  Mem_30_LegacyAdapterPCIsReducedToDefineDefines  Mem_30_LegacyAdapter Is Reduced To Define Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define is STD_ON else STD_OFF.
  \{
*/ 
#define MEM_30_LEGACYADAPTER_ISDEF_ERASEOFLLAPI                                                     STD_OFF
#define MEM_30_LEGACYADAPTER_ISDEF_GETJOBRESULTOFLLAPI                                              STD_OFF
#define MEM_30_LEGACYADAPTER_ISDEF_HWFUNCTIONSOFLLAPI                                               STD_OFF
#define MEM_30_LEGACYADAPTER_ISDEF_INITOFLLAPI                                                      STD_OFF
#define MEM_30_LEGACYADAPTER_ISDEF_ISBLANKOFLLAPI                                                   STD_OFF
#define MEM_30_LEGACYADAPTER_ISDEF_MAINFUNCTIONOFLLAPI                                              STD_OFF
#define MEM_30_LEGACYADAPTER_ISDEF_READOFLLAPI                                                      STD_OFF
#define MEM_30_LEGACYADAPTER_ISDEF_WRITEOFLLAPI                                                     STD_OFF
#define MEM_30_LEGACYADAPTER_ISDEF_LLAPIIDXOFMEMINSTANCEIDMAPPING                                   STD_ON
#define MEM_30_LEGACYADAPTER_ISDEF_LLINSTANCEIDOFMEMINSTANCEIDMAPPING                               STD_ON
#define MEM_30_LEGACYADAPTER_ISDEF_LLAPIOFPCCONFIG                                                  STD_ON
#define MEM_30_LEGACYADAPTER_ISDEF_MEMINSTANCEIDMAPPINGOFPCCONFIG                                   STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  Mem_30_LegacyAdapterPCEqualsAlwaysToDefines  Mem_30_LegacyAdapter Equals Always To Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define contains the always equals value.
  \{
*/ 
#define MEM_30_LEGACYADAPTER_EQ2_ERASEOFLLAPI                                                       
#define MEM_30_LEGACYADAPTER_EQ2_GETJOBRESULTOFLLAPI                                                
#define MEM_30_LEGACYADAPTER_EQ2_HWFUNCTIONSOFLLAPI                                                 
#define MEM_30_LEGACYADAPTER_EQ2_INITOFLLAPI                                                        
#define MEM_30_LEGACYADAPTER_EQ2_ISBLANKOFLLAPI                                                     
#define MEM_30_LEGACYADAPTER_EQ2_MAINFUNCTIONOFLLAPI                                                
#define MEM_30_LEGACYADAPTER_EQ2_READOFLLAPI                                                        
#define MEM_30_LEGACYADAPTER_EQ2_WRITEOFLLAPI                                                       
#define MEM_30_LEGACYADAPTER_EQ2_LLAPIIDXOFMEMINSTANCEIDMAPPING                                     0u
#define MEM_30_LEGACYADAPTER_EQ2_LLINSTANCEIDOFMEMINSTANCEIDMAPPING                                 0u
#define MEM_30_LEGACYADAPTER_EQ2_LLAPIOFPCCONFIG                                                    Mem_30_LegacyAdapter_LLApi
#define MEM_30_LEGACYADAPTER_EQ2_MEMINSTANCEIDMAPPINGOFPCCONFIG                                     Mem_30_LegacyAdapter_MemInstanceIdMapping
/** 
  \}
*/ 

/** 
  \defgroup  Mem_30_LegacyAdapterPCSymbolicInitializationPointers  Mem_30_LegacyAdapter Symbolic Initialization Pointers (PRE_COMPILE)
  \brief  Symbolic initialization pointers to be used in the call of a preinit or init function.
  \{
*/ 
#define Mem_30_LegacyAdapter_Config_Ptr                                                             NULL_PTR  /**< symbolic identifier which shall be used to initialize 'Mem_30_LegacyAdapter' */
/** 
  \}
*/ 

/** 
  \defgroup  Mem_30_LegacyAdapterPCInitializationSymbols  Mem_30_LegacyAdapter Initialization Symbols (PRE_COMPILE)
  \brief  Symbolic initialization pointers which may be used in the call of a preinit or init function. Please note, that the defined value can be a 'NULL_PTR' and the address operator is not usable.
  \{
*/ 
#define Mem_30_LegacyAdapter_Config                                                                 NULL_PTR  /**< symbolic identifier which could be used to initialize 'Mem_30_LegacyAdapter */
/** 
  \}
*/ 

/** 
  \defgroup  Mem_30_LegacyAdapterPCGeneral  Mem_30_LegacyAdapter General (PRE_COMPILE)
  \brief  General constant defines not associated with a group of defines.
  \{
*/ 
#define MEM_30_LEGACYADAPTER_CHECK_INIT_POINTER                                                     STD_OFF  /**< STD_ON if the init pointer shall not be used as NULL_PTR and a check shall validate this. */
#define MEM_30_LEGACYADAPTER_FINAL_MAGIC_NUMBER                                                     0x5B1Eu  /**< the precompile constant to validate the size of the initialization structure at initialization time of Mem_30_LegacyAdapter */
#define MEM_30_LEGACYADAPTER_INDIVIDUAL_POSTBUILD                                                   STD_OFF  /**< the precompile constant to check, that the module is individual postbuildable. The module 'Mem_30_LegacyAdapter' is not configured to be postbuild capable. */
#define MEM_30_LEGACYADAPTER_INIT_DATA                                                              MEM_30_LEGACYADAPTER_CONST  /**< CompilerMemClassDefine for the initialization data. */
#define MEM_30_LEGACYADAPTER_INIT_DATA_HASH_CODE                                                    -444032603  /**< the precompile constant to validate the initialization structure at initialization time of Mem_30_LegacyAdapter with a hashcode. The seed value is '0x5B1Eu' */
#define MEM_30_LEGACYADAPTER_USE_ECUM_BSW_ERROR_HOOK                                                STD_OFF  /**< STD_ON if the EcuM_BswErrorHook shall be called in the ConfigPtr check. */
#define MEM_30_LEGACYADAPTER_USE_INIT_POINTER                                                       STD_OFF  /**< STD_ON if the init pointer Mem_30_LegacyAdapter shall be used. */
/** 
  \}
*/ 


/**********************************************************************************************************************
 *  GENERAL DEFINE BLOCK
 *********************************************************************************************************************/
#ifndef MEM_30_LEGACYADAPTER_USE_DUMMY_STATEMENT
#define MEM_30_LEGACYADAPTER_USE_DUMMY_STATEMENT STD_ON /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef MEM_30_LEGACYADAPTER_DUMMY_STATEMENT
#define MEM_30_LEGACYADAPTER_DUMMY_STATEMENT(v) (v)=(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef MEM_30_LEGACYADAPTER_DUMMY_STATEMENT_CONST
#define MEM_30_LEGACYADAPTER_DUMMY_STATEMENT_CONST(v) (void)(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef MEM_30_LEGACYADAPTER_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define MEM_30_LEGACYADAPTER_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef MEM_30_LEGACYADAPTER_ATOMIC_VARIABLE_ACCESS
#define MEM_30_LEGACYADAPTER_ATOMIC_VARIABLE_ACCESS 32u /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef MEM_30_LEGACYADAPTER_PROCESSOR_CYT2B75BXX
#define MEM_30_LEGACYADAPTER_PROCESSOR_CYT2B75BXX
#endif
#ifndef MEM_30_LEGACYADAPTER_COMP_GREENHILLS
#define MEM_30_LEGACYADAPTER_COMP_GREENHILLS
#endif
#ifndef MEM_30_LEGACYADAPTER_GEN_GENERATOR_MSR
#define MEM_30_LEGACYADAPTER_GEN_GENERATOR_MSR
#endif
#ifndef MEM_30_LEGACYADAPTER_CPUTYPE_BITORDER_LSB2MSB
#define MEM_30_LEGACYADAPTER_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/vSet/vSetPlatform/vSetBitOrder */
#endif
#ifndef MEM_30_LEGACYADAPTER_CONFIGURATION_VARIANT_PRECOMPILE
#define MEM_30_LEGACYADAPTER_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef MEM_30_LEGACYADAPTER_CONFIGURATION_VARIANT_LINKTIME
#define MEM_30_LEGACYADAPTER_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef MEM_30_LEGACYADAPTER_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define MEM_30_LEGACYADAPTER_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef MEM_30_LEGACYADAPTER_CONFIGURATION_VARIANT
#define MEM_30_LEGACYADAPTER_CONFIGURATION_VARIANT MEM_30_LEGACYADAPTER_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef MEM_30_LEGACYADAPTER_POSTBUILD_VARIANT_SUPPORT
#define MEM_30_LEGACYADAPTER_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif

/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
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
  \defgroup  Mem_30_LegacyAdapterPCGetConstantDuplicatedRootDataMacros  Mem_30_LegacyAdapter Get Constant Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated by constance root data elements.
  \{
*/ 
#define Mem_30_LegacyAdapter_GetFinalMagicNumberOfPCConfig()                                        0x5B1Eu  /**< the FinalMagicNumber to validate the size of the initialization structure at initialization time of Mem_30_LegacyAdapter */
#define Mem_30_LegacyAdapter_GetInitDataHashCodeOfPCConfig()                                        -920669804  /**< the hashcode to validate the initialization structure at initialization time of Mem_30_LegacyAdapter */
#define Mem_30_LegacyAdapter_GetLLApiOfPCConfig()                                                   Mem_30_LegacyAdapter_LLApi  /**< the pointer to Mem_30_LegacyAdapter_LLApi */
#define Mem_30_LegacyAdapter_GetMemInstanceIdMappingOfPCConfig()                                    Mem_30_LegacyAdapter_MemInstanceIdMapping  /**< the pointer to Mem_30_LegacyAdapter_MemInstanceIdMapping */
#define Mem_30_LegacyAdapter_GetSizeOfLLApiOfPCConfig()                                             1u  /**< the number of accomplishable value elements in Mem_30_LegacyAdapter_LLApi */
#define Mem_30_LegacyAdapter_GetSizeOfMemInstanceIdMappingOfPCConfig()                              1u  /**< the number of accomplishable value elements in Mem_30_LegacyAdapter_MemInstanceIdMapping */
/** 
  \}
*/ 

/** 
  \defgroup  Mem_30_LegacyAdapterPCGetDataMacros  Mem_30_LegacyAdapter Get Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read CONST and VAR data.
  \{
*/ 
#define Mem_30_LegacyAdapter_GetEraseOfLLApi(Index)                                                 (Mem_30_LegacyAdapter_GetLLApiOfPCConfig()[(Index)].EraseOfLLApi)
#define Mem_30_LegacyAdapter_GetGetJobResultOfLLApi(Index)                                          (Mem_30_LegacyAdapter_GetLLApiOfPCConfig()[(Index)].GetJobResultOfLLApi)
#define Mem_30_LegacyAdapter_GetHwFunctionsOfLLApi(Index)                                           (Mem_30_LegacyAdapter_GetLLApiOfPCConfig()[(Index)].HwFunctionsOfLLApi)
#define Mem_30_LegacyAdapter_GetInitOfLLApi(Index)                                                  (Mem_30_LegacyAdapter_GetLLApiOfPCConfig()[(Index)].InitOfLLApi)
#define Mem_30_LegacyAdapter_GetIsBlankOfLLApi(Index)                                               (Mem_30_LegacyAdapter_GetLLApiOfPCConfig()[(Index)].IsBlankOfLLApi)
#define Mem_30_LegacyAdapter_GetMainFunctionOfLLApi(Index)                                          (Mem_30_LegacyAdapter_GetLLApiOfPCConfig()[(Index)].MainFunctionOfLLApi)
#define Mem_30_LegacyAdapter_GetReadOfLLApi(Index)                                                  (Mem_30_LegacyAdapter_GetLLApiOfPCConfig()[(Index)].ReadOfLLApi)
#define Mem_30_LegacyAdapter_GetWriteOfLLApi(Index)                                                 (Mem_30_LegacyAdapter_GetLLApiOfPCConfig()[(Index)].WriteOfLLApi)
/** 
  \}
*/ 

/** 
  \defgroup  Mem_30_LegacyAdapterPCGetDeduplicatedDataMacros  Mem_30_LegacyAdapter Get Deduplicated Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated data elements.
  \{
*/ 
#define Mem_30_LegacyAdapter_GetFinalMagicNumber()                                                  Mem_30_LegacyAdapter_GetFinalMagicNumberOfPCConfig()
#define Mem_30_LegacyAdapter_GetInitDataHashCode()                                                  Mem_30_LegacyAdapter_GetInitDataHashCodeOfPCConfig()
#define Mem_30_LegacyAdapter_GetLLApiIdxOfMemInstanceIdMapping(Index)                               0u  /**< the index of the 1:1 relation pointing to Mem_30_LegacyAdapter_LLApi */
#define Mem_30_LegacyAdapter_GetLLInstanceIdOfMemInstanceIdMapping(Index)                           0u  /**< the LLInstanceId that the LLApi the Mem_30_LegacyAdapter references */
#define Mem_30_LegacyAdapter_GetSizeOfLLApi()                                                       Mem_30_LegacyAdapter_GetSizeOfLLApiOfPCConfig()
#define Mem_30_LegacyAdapter_GetSizeOfMemInstanceIdMapping()                                        Mem_30_LegacyAdapter_GetSizeOfMemInstanceIdMappingOfPCConfig()
/** 
  \}
*/ 

/** 
  \defgroup  Mem_30_LegacyAdapterPCHasMacros  Mem_30_LegacyAdapter Has Macros (PRE_COMPILE)
  \brief  These macros can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
#define Mem_30_LegacyAdapter_HasFinalMagicNumber()                                                  (FALSE != FALSE)
#define Mem_30_LegacyAdapter_HasInitDataHashCode()                                                  (FALSE != FALSE)
#define Mem_30_LegacyAdapter_HasLLApi()                                                             (TRUE != FALSE)
#define Mem_30_LegacyAdapter_HasEraseOfLLApi()                                                      (TRUE != FALSE)
#define Mem_30_LegacyAdapter_HasGetJobResultOfLLApi()                                               (TRUE != FALSE)
#define Mem_30_LegacyAdapter_HasHwFunctionsOfLLApi()                                                (TRUE != FALSE)
#define Mem_30_LegacyAdapter_HasInitOfLLApi()                                                       (TRUE != FALSE)
#define Mem_30_LegacyAdapter_HasIsBlankOfLLApi()                                                    (TRUE != FALSE)
#define Mem_30_LegacyAdapter_HasMainFunctionOfLLApi()                                               (TRUE != FALSE)
#define Mem_30_LegacyAdapter_HasReadOfLLApi()                                                       (TRUE != FALSE)
#define Mem_30_LegacyAdapter_HasWriteOfLLApi()                                                      (TRUE != FALSE)
#define Mem_30_LegacyAdapter_HasMemInstanceIdMapping()                                              (TRUE != FALSE)
#define Mem_30_LegacyAdapter_HasLLApiIdxOfMemInstanceIdMapping()                                    (TRUE != FALSE)
#define Mem_30_LegacyAdapter_HasLLInstanceIdOfMemInstanceIdMapping()                                (TRUE != FALSE)
#define Mem_30_LegacyAdapter_HasSizeOfLLApi()                                                       (TRUE != FALSE)
#define Mem_30_LegacyAdapter_HasSizeOfMemInstanceIdMapping()                                        (TRUE != FALSE)
#define Mem_30_LegacyAdapter_HasPCConfig()                                                          (TRUE != FALSE)
#define Mem_30_LegacyAdapter_HasFinalMagicNumberOfPCConfig()                                        (FALSE != FALSE)
#define Mem_30_LegacyAdapter_HasInitDataHashCodeOfPCConfig()                                        (FALSE != FALSE)
#define Mem_30_LegacyAdapter_HasLLApiOfPCConfig()                                                   (TRUE != FALSE)
#define Mem_30_LegacyAdapter_HasMemInstanceIdMappingOfPCConfig()                                    (TRUE != FALSE)
#define Mem_30_LegacyAdapter_HasSizeOfLLApiOfPCConfig()                                             (TRUE != FALSE)
#define Mem_30_LegacyAdapter_HasSizeOfMemInstanceIdMappingOfPCConfig()                              (TRUE != FALSE)
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

/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: SIZEOF DATA TYPES
**********************************************************************************************************************/
/** 
  \defgroup  Mem_30_LegacyAdapterPCSizeOfTypes  Mem_30_LegacyAdapter SizeOf Types (PRE_COMPILE)
  \brief  These type definitions are used for the SizeOf information.
  \{
*/ 
/**   \brief  value based type definition for Mem_30_LegacyAdapter_SizeOfLLApi */
typedef uint8 Mem_30_LegacyAdapter_SizeOfLLApiType;

/**   \brief  value based type definition for Mem_30_LegacyAdapter_SizeOfMemInstanceIdMapping */
typedef uint8 Mem_30_LegacyAdapter_SizeOfMemInstanceIdMappingType;

/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  Mem_30_LegacyAdapterPCIterableTypes  Mem_30_LegacyAdapter Iterable Types (PRE_COMPILE)
  \brief  These type definitions are used to iterate over an array with least processor cycles for variable access as possible.
  \{
*/ 
/**   \brief  type used to iterate Mem_30_LegacyAdapter_LLApi */
typedef uint8_least Mem_30_LegacyAdapter_LLApiIterType;

/**   \brief  type used to iterate Mem_30_LegacyAdapter_MemInstanceIdMapping */
typedef uint8_least Mem_30_LegacyAdapter_MemInstanceIdMappingIterType;

/** 
  \}
*/ 

/** 
  \defgroup  Mem_30_LegacyAdapterPCValueTypes  Mem_30_LegacyAdapter Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value based data representations.
  \{
*/ 
/**   \brief  value based type definition for Mem_30_LegacyAdapter_FinalMagicNumber */
typedef uint16 Mem_30_LegacyAdapter_FinalMagicNumberType;

/**   \brief  value based type definition for Mem_30_LegacyAdapter_InitDataHashCode */
typedef sint32 Mem_30_LegacyAdapter_InitDataHashCodeType;

/**   \brief  value based type definition for Mem_30_LegacyAdapter_LLApiIdxOfMemInstanceIdMapping */
typedef uint8 Mem_30_LegacyAdapter_LLApiIdxOfMemInstanceIdMappingType;

/**   \brief  value based type definition for Mem_30_LegacyAdapter_LLInstanceIdOfMemInstanceIdMapping */
typedef uint8 Mem_30_LegacyAdapter_LLInstanceIdOfMemInstanceIdMappingType;

/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  Mem_30_LegacyAdapterPCStructTypes  Mem_30_LegacyAdapter Struct Types (PRE_COMPILE)
  \brief  These type definitions are used for structured data representations.
  \{
*/ 
/**   \brief  type used in Mem_30_LegacyAdapter_LLApi */
typedef struct sMem_30_LegacyAdapter_LLApiType
{
  Mem_30_LegacyAdapter_LLEraseFuncPtr EraseOfLLApi;
  Mem_30_LegacyAdapter_LLGetJobResultFuncPtr GetJobResultOfLLApi;
  Mem_30_LegacyAdapter_LLInitFuncPtr InitOfLLApi;
  Mem_30_LegacyAdapter_LLIsBlankFuncPtr IsBlankOfLLApi;
  Mem_30_LegacyAdapter_LLMainFunctionFuncPtr MainFunctionOfLLApi;
  Mem_30_LegacyAdapter_LLReadFuncPtr ReadOfLLApi;
  Mem_30_LegacyAdapter_LLWriteFuncPtr WriteOfLLApi;
  Mem_30_LegacyAdapter_vMemHwSpecificFunctionsPtrType HwFunctionsOfLLApi;
} Mem_30_LegacyAdapter_LLApiType;

/**   \brief  type used in Mem_30_LegacyAdapter_MemInstanceIdMapping */
typedef struct sMem_30_LegacyAdapter_MemInstanceIdMappingType
{
  uint8 Mem_30_LegacyAdapter_MemInstanceIdMappingNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} Mem_30_LegacyAdapter_MemInstanceIdMappingType;

/** 
  \}
*/ 

/** 
  \defgroup  Mem_30_LegacyAdapterPCRootPointerTypes  Mem_30_LegacyAdapter Root Pointer Types (PRE_COMPILE)
  \brief  These type definitions are used to point from the config root to symbol instances.
  \{
*/ 
/**   \brief  type used to point to Mem_30_LegacyAdapter_LLApi */
typedef P2CONST(Mem_30_LegacyAdapter_LLApiType, TYPEDEF, MEM_30_LEGACYADAPTER_CONST) Mem_30_LegacyAdapter_LLApiPtrType;

/**   \brief  type used to point to Mem_30_LegacyAdapter_MemInstanceIdMapping */
typedef P2CONST(Mem_30_LegacyAdapter_MemInstanceIdMappingType, TYPEDEF, MEM_30_LEGACYADAPTER_CONST) Mem_30_LegacyAdapter_MemInstanceIdMappingPtrType;

/** 
  \}
*/ 

/** 
  \defgroup  Mem_30_LegacyAdapterPCRootValueTypes  Mem_30_LegacyAdapter Root Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value representations in root arrays.
  \{
*/ 
/**   \brief  type used in Mem_30_LegacyAdapter_PCConfig */
typedef struct sMem_30_LegacyAdapter_PCConfigType
{
  uint8 Mem_30_LegacyAdapter_PCConfigNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} Mem_30_LegacyAdapter_PCConfigType;

typedef Mem_30_LegacyAdapter_PCConfigType Mem_30_LegacyAdapter_ConfigType;  /**< A structure type is present for data in each configuration class. This typedef redefines the probably different name to the specified one. */

/** 
  \}
*/ 


/***********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 **********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  Mem_30_LegacyAdapter_LLApi
**********************************************************************************************************************/
/** 
  \var    Mem_30_LegacyAdapter_LLApi
  \details
  Element         Description
  Erase       
  GetJobResult
  Init        
  IsBlank     
  MainFunction
  Read        
  Write       
  HwFunctions 
*/ 
#define MEM_30_LEGACYADAPTER_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Mem_30_LegacyAdapter_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Mem_30_LegacyAdapter_LLApiType, MEM_30_LEGACYADAPTER_CONST) Mem_30_LegacyAdapter_LLApi[1];
#define MEM_30_LEGACYADAPTER_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Mem_30_LegacyAdapter_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */


/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL SIZEOF INLINE FUNCTION PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL INLINE FUNCTION PROTOTYPES
**********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL INLINE FUNCTIONS
 **********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL INLINE FUNCTIONS
**********************************************************************************************************************/

#endif /* MEM_30_LEGACYADAPTER_CFG_H */
/***********************************************************************************************************************
  END OF FILE: Mem_30_LegacyAdapter_Cfg.h
 **********************************************************************************************************************/
