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
 *            Module: MemAcc
 *           Program: MSR_Geely_SLP2
 *          Customer: Marelli Automotive Electronics (Guangzhou) Co., Ltd
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: CYT2B75BA
 *    License Scope : The usage is restricted to CBD2600619_D00
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: MemAcc_Cfg.h
 *   Generation Time: 2026-07-29 15:28:47
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

#if !defined (MEMACC_CFG_H)
# define MEMACC_CFG_H

/***********************************************************************************************************************
 * MISRA JUSTIFICATION
 **********************************************************************************************************************/
/* PRQA S 0857 EOF */ /* MD_MSR_1.1_857 */
/* PRQA S 0779 EOF */ /* MD_CSL_0779 */

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/

// # include "Det.h" 
# include "MemAcc_GeneralTypes.h"
# include "MemAcc_MemApi.h"
# include "MemAcc_MemCfg.h"


/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/
 
# define MEMACC_CFG_MAJOR_VERSION 3u
# define MEMACC_CFG_MINOR_VERSION 5u
# define MEMACC_NUMBER_OF_SYNCHRONIZATION_GROUPS                                  1u      
# define MEMACC_READCOMPAREALIGNMENT_REQUIRED                                     STD_ON  
# define MEMACC_COMPAREAPI_ENABLED                                                STD_OFF 
# define MEMACC_SUSPENDRESUME_ENABLED                                             STD_ON  
# define MemAccConf_MemAccAddressAreaConfiguration_MemAccAddressAreaConfiguration 0u      /*!< Symbolic Name for AdressAreaId */
# define MEMACC_NUMBER_OF_HARDWARE_IDS                                            1u      
# define MEMACC_READONLYMODE_ENABLED                                              STD_OFF 
# define MEMACC_BBM_ENABLED                                                       STD_OFF 
 
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  MemAccPCDataSwitches  MemAcc Data Switches  (PRE_COMPILE)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define MEMACC_ADDRESSAREA                                                                          STD_ON
#define MEMACC_ADDRESSAREAIDOFADDRESSAREA                                                           STD_ON
#define MEMACC_ERRORNOTIFICATIONOFADDRESSAREA                                                       STD_ON
#define MEMACC_JOBENDNOTIFICATIONOFADDRESSAREA                                                      STD_ON
#define MEMACC_PRIORITYBASEDINDEXOFADDRESSAREA                                                      STD_ON
#define MEMACC_PRIORITYOFADDRESSAREA                                                                STD_ON
#define MEMACC_SUBADDRESSAREAENDIDXOFADDRESSAREA                                                    STD_ON
#define MEMACC_SUBADDRESSAREASTARTIDXOFADDRESSAREA                                                  STD_ON
#define MEMACC_BBLUT                                                                                STD_OFF  /**< Deactivateable: 'MemAcc_BBLUT' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define MEMACC_BBMARKERSTATEOFBBLUT                                                                 STD_OFF  /**< Deactivateable: 'MemAcc_BBLUT.BBMarkerState' Reason: 'the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define MEMACC_PHYSICALBLOCKNROFBBLUT                                                               STD_OFF  /**< Deactivateable: 'MemAcc_BBLUT.PhysicalBlockNr' Reason: 'the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define MEMACC_SAAIDXOFBBLUT                                                                        STD_OFF  /**< Deactivateable: 'MemAcc_BBLUT.SAAIdx' Reason: 'the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define MEMACC_CLOWERLAYER                                                                          STD_ON
#define MEMACC_MEMDRIVERINDEXOFLOWERLAYER                                                           STD_OFF  /**< Deactivateable: 'MemAcc_CLowerLayer.MemDriverIndex' Reason: 'No Redirect requests configured so this Index is not needed.' */
#define MEMACC_STATICMEMBINARYHEADEROFLOWERLAYER                                                    STD_ON
#define MEMACC_CREADONLYCONFIGURATION                                                               STD_OFF  /**< Deactivateable: 'MemAcc_CReadOnlyConfiguration' Reason: 'ReadOnlyMode is not configured.' */
#define MEMACC_READONLYMODESUPPORTSHWSPECIFICSERVICEOFREADONLYCONFIGURATION                         STD_OFF  /**< Deactivateable: 'MemAcc_CReadOnlyConfiguration.ReadOnlyModeSupportsHwSpecificService' Reason: 'ReadOnlyMode is not configured.' */
#define MEMACC_UNLOCKTOKENPOINTEROFREADONLYCONFIGURATION                                            STD_OFF  /**< Deactivateable: 'MemAcc_CReadOnlyConfiguration.UnlockTokenPointer' Reason: 'ReadOnlyMode is not configured.' */
#define MEMACC_UNLOCKTOKENSIZEOFREADONLYCONFIGURATION                                               STD_OFF  /**< Deactivateable: 'MemAcc_CReadOnlyConfiguration.UnlockTokenSize' Reason: 'ReadOnlyMode is not configured.' */
#define MEMACC_COMPAREBUFFER                                                                        STD_OFF  /**< Deactivateable: 'MemAcc_CompareBuffer' Reason: 'Compare API disabled.' */
#define MEMACC_FINALMAGICNUMBER                                                                     STD_OFF  /**< Deactivateable: 'MemAcc_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define MEMACC_GENERALFEATURES                                                                      STD_ON
#define MEMACC_DEVERRORDETECTIONOFGENERALFEATURES                                                   STD_ON
#define MEMACC_DEVERRORREPORTOFGENERALFEATURES                                                      STD_ON
#define MEMACC_INITDATAHASHCODE                                                                     STD_OFF  /**< Deactivateable: 'MemAcc_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define MEMACC_MEMINSTANCE                                                                          STD_ON
#define MEMACC_BBLUTENDIDXOFMEMINSTANCE                                                             STD_OFF  /**< Deactivateable: 'MemAcc_MemInstance.BBLUTEndIdx' Reason: 'the optional indirection is deactivated because BBLUTUsedOfMemInstance is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define MEMACC_BBLUTSTARTIDXOFMEMINSTANCE                                                           STD_OFF  /**< Deactivateable: 'MemAcc_MemInstance.BBLUTStartIdx' Reason: 'the optional indirection is deactivated because BBLUTUsedOfMemInstance is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define MEMACC_BBLUTUSEDOFMEMINSTANCE                                                               STD_OFF  /**< Deactivateable: 'MemAcc_MemInstance.BBLUTUsed' Reason: 'the optional indirection is deactivated because BBLUTUsedOfMemInstance is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define MEMACC_BBSTRATEGYOFMEMINSTANCE                                                              STD_OFF  /**< Deactivateable: 'MemAcc_MemInstance.BBStrategy' Reason: 'BBM is disabled.' */
#define MEMACC_HARDWAREIDOFMEMINSTANCE                                                              STD_ON
#define MEMACC_INSTANCEIDOFMEMINSTANCE                                                              STD_ON
#define MEMACC_MEMSECTORBATCH                                                                       STD_ON
#define MEMACC_ERASEBURSTSIZEOFMEMSECTORBATCH                                                       STD_ON
#define MEMACC_ERASESECTORSIZEOFMEMSECTORBATCH                                                      STD_ON
#define MEMACC_MAXREADSIZEOFMEMSECTORBATCH                                                          STD_ON
#define MEMACC_MINREADSIZEOFMEMSECTORBATCH                                                          STD_ON
#define MEMACC_WRITEBURSTSIZEOFMEMSECTORBATCH                                                       STD_ON
#define MEMACC_WRITEPAGESIZEOFMEMSECTORBATCH                                                        STD_ON
#define MEMACC_REDIRECTSECTORBATCH                                                                  STD_OFF  /**< Deactivateable: 'MemAcc_RedirectSectorBatch' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define MEMACC_INSTANCEIDOFREDIRECTSECTORBATCH                                                      STD_OFF  /**< Deactivateable: 'MemAcc_RedirectSectorBatch.InstanceId' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define MEMACC_LENGTHOFREDIRECTSECTORBATCH                                                          STD_OFF  /**< Deactivateable: 'MemAcc_RedirectSectorBatch.Length' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define MEMACC_MEMDRIVERINDEXOFREDIRECTSECTORBATCH                                                  STD_OFF  /**< Deactivateable: 'MemAcc_RedirectSectorBatch.MemDriverIndex' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define MEMACC_PHYSICALSTARTADDRESSOFREDIRECTSECTORBATCH                                            STD_OFF  /**< Deactivateable: 'MemAcc_RedirectSectorBatch.PhysicalStartAddress' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define MEMACC_SATELLITEIDOFREDIRECTSECTORBATCH                                                     STD_OFF  /**< Deactivateable: 'MemAcc_RedirectSectorBatch.SatelliteId' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define MEMACC_SIZEOFADDRESSAREA                                                                    STD_ON
#define MEMACC_SIZEOFBBLUT                                                                          STD_OFF  /**< Deactivateable: 'MemAcc_SizeOfBBLUT' Reason: 'Deactivateable: 'BBLUT' Reason: 'Deactivateable: 'MemAcc_BBLUT' Reason: 'the struct is deactivated because all elements are deactivated in all variants.''' */
#define MEMACC_SIZEOFCLOWERLAYER                                                                    STD_ON
#define MEMACC_SIZEOFCREADONLYCONFIGURATION                                                         STD_OFF  /**< Deactivateable: 'MemAcc_SizeOfCReadOnlyConfiguration' Reason: 'Deactivateable: 'CReadOnlyConfiguration' Reason: 'Deactivateable: 'MemAcc_CReadOnlyConfiguration' Reason: 'ReadOnlyMode is not configured.''' */
#define MEMACC_SIZEOFCOMPAREBUFFER                                                                  STD_OFF  /**< Deactivateable: 'MemAcc_SizeOfCompareBuffer' Reason: 'Deactivateable: 'CompareBuffer' Reason: 'Deactivateable: 'MemAcc_CompareBuffer' Reason: 'Compare API disabled.''' */
#define MEMACC_SIZEOFGENERALFEATURES                                                                STD_ON
#define MEMACC_SIZEOFMEMINSTANCE                                                                    STD_ON
#define MEMACC_SIZEOFMEMSECTORBATCH                                                                 STD_ON
#define MEMACC_SIZEOFREDIRECTSECTORBATCH                                                            STD_OFF  /**< Deactivateable: 'MemAcc_SizeOfRedirectSectorBatch' Reason: 'Deactivateable: 'RedirectSectorBatch' Reason: 'Deactivateable: 'MemAcc_RedirectSectorBatch' Reason: 'the struct is deactivated because all elements are deactivated.''' */
#define MEMACC_SIZEOFSUBADDRESSAREA                                                                 STD_ON
#define MEMACC_SIZEOFSYNCGROUP                                                                      STD_OFF  /**< Deactivateable: 'MemAcc_SizeOfSyncGroup' Reason: 'Deactivateable: 'SyncGroup' Reason: 'Deactivateable: 'MemAcc_SyncGroup' Reason: 'Read alignment is required, no alignment buffer needed.''' */
#define MEMACC_SIZEOFVLOWERLAYER                                                                    STD_ON
#define MEMACC_SIZEOFVREADONLYCONFIGURATION                                                         STD_OFF  /**< Deactivateable: 'MemAcc_SizeOfVReadOnlyConfiguration' Reason: 'Deactivateable: 'VReadOnlyConfiguration' Reason: 'Deactivateable: 'MemAcc_VReadOnlyConfiguration' Reason: 'ReadOnlyMode is not configured.''' */
#define MEMACC_SUBADDRESSAREA                                                                       STD_ON
#define MEMACC_ACCESSTYPEOFSUBADDRESSAREA                                                           STD_ON
#define MEMACC_LOGICALENDADDRESSOFSUBADDRESSAREA                                                    STD_ON
#define MEMACC_LOGICALSTARTADDRESSOFSUBADDRESSAREA                                                  STD_ON
#define MEMACC_LOWERLAYERIDXOFSUBADDRESSAREA                                                        STD_ON
#define MEMACC_MEMINSTANCEIDXOFSUBADDRESSAREA                                                       STD_ON
#define MEMACC_MEMSECTORBATCHIDXOFSUBADDRESSAREA                                                    STD_ON
#define MEMACC_NUMBEROFERASERETRIESOFSUBADDRESSAREA                                                 STD_ON
#define MEMACC_NUMBEROFREADRETRIESOFSUBADDRESSAREA                                                  STD_ON
#define MEMACC_NUMBEROFSECTORSOFSUBADDRESSAREA                                                      STD_ON
#define MEMACC_NUMBEROFWRITERETRIESOFSUBADDRESSAREA                                                 STD_ON
#define MEMACC_PHYSICALENDADDRESSOFSUBADDRESSAREA                                                   STD_ON
#define MEMACC_PHYSICALSTARTADDRESSOFSUBADDRESSAREA                                                 STD_ON
#define MEMACC_READONLYCONFIGURATIONIDXOFSUBADDRESSAREA                                             STD_OFF  /**< Deactivateable: 'MemAcc_SubAddressArea.ReadOnlyConfigurationIdx' Reason: 'ReadOnlyMode is not configured.' */
#define MEMACC_READONLYCONFIGURATIONUSEDOFSUBADDRESSAREA                                            STD_OFF  /**< Deactivateable: 'MemAcc_SubAddressArea.ReadOnlyConfigurationUsed' Reason: 'ReadOnlyMode is not configured.' */
#define MEMACC_SECTOROFFSETOFSUBADDRESSAREA                                                         STD_ON
#define MEMACC_SYNCGROUPIDOFSUBADDRESSAREA                                                          STD_ON
#define MEMACC_USEERASEBURSTOFSUBADDRESSAREA                                                        STD_ON
#define MEMACC_USEWRITEBURSTOFSUBADDRESSAREA                                                        STD_ON
#define MEMACC_SYNCGROUP                                                                            STD_OFF  /**< Deactivateable: 'MemAcc_SyncGroup' Reason: 'Read alignment is required, no alignment buffer needed.' */
#define MEMACC_READALIGNMENTBUFFERPTROFSYNCGROUP                                                    STD_OFF  /**< Deactivateable: 'MemAcc_SyncGroup.ReadAlignmentBufferPtr' Reason: 'Read alignment is required, no alignment buffer needed.' */
#define MEMACC_VLOWERLAYER                                                                          STD_ON
#define MEMACC_INDIRECTDYNAMICMEMBINARYHEADEROFLOWERLAYER                                           STD_ON
#define MEMACC_VREADONLYCONFIGURATION                                                               STD_OFF  /**< Deactivateable: 'MemAcc_VReadOnlyConfiguration' Reason: 'ReadOnlyMode is not configured.' */
#define MEMACC_READONLYENABLEDOFREADONLYCONFIGURATION                                               STD_OFF  /**< Deactivateable: 'MemAcc_VReadOnlyConfiguration.ReadOnlyEnabled' Reason: 'ReadOnlyMode is not configured.' */
#define MEMACC_PCCONFIG                                                                             STD_ON
#define MEMACC_ADDRESSAREAOFPCCONFIG                                                                STD_ON
#define MEMACC_CLOWERLAYEROFPCCONFIG                                                                STD_ON
#define MEMACC_FINALMAGICNUMBEROFPCCONFIG                                                           STD_OFF  /**< Deactivateable: 'MemAcc_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define MEMACC_GENERALFEATURESOFPCCONFIG                                                            STD_ON
#define MEMACC_INITDATAHASHCODEOFPCCONFIG                                                           STD_OFF  /**< Deactivateable: 'MemAcc_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define MEMACC_MEMINSTANCEOFPCCONFIG                                                                STD_ON
#define MEMACC_MEMSECTORBATCHOFPCCONFIG                                                             STD_ON
#define MEMACC_SIZEOFADDRESSAREAOFPCCONFIG                                                          STD_ON
#define MEMACC_SIZEOFBBLUTOFPCCONFIG                                                                STD_OFF  /**< Deactivateable: 'MemAcc_PCConfig.SizeOfBBLUT' Reason: 'Deactivateable: 'BBLUT' Reason: 'Deactivateable: 'MemAcc_BBLUT' Reason: 'the struct is deactivated because all elements are deactivated in all variants.''' */
#define MEMACC_SIZEOFCLOWERLAYEROFPCCONFIG                                                          STD_ON
#define MEMACC_SIZEOFCREADONLYCONFIGURATIONOFPCCONFIG                                               STD_OFF  /**< Deactivateable: 'MemAcc_PCConfig.SizeOfCReadOnlyConfiguration' Reason: 'Deactivateable: 'CReadOnlyConfiguration' Reason: 'Deactivateable: 'MemAcc_CReadOnlyConfiguration' Reason: 'ReadOnlyMode is not configured.''' */
#define MEMACC_SIZEOFCOMPAREBUFFEROFPCCONFIG                                                        STD_OFF  /**< Deactivateable: 'MemAcc_PCConfig.SizeOfCompareBuffer' Reason: 'Deactivateable: 'CompareBuffer' Reason: 'Deactivateable: 'MemAcc_CompareBuffer' Reason: 'Compare API disabled.''' */
#define MEMACC_SIZEOFGENERALFEATURESOFPCCONFIG                                                      STD_ON
#define MEMACC_SIZEOFMEMINSTANCEOFPCCONFIG                                                          STD_ON
#define MEMACC_SIZEOFMEMSECTORBATCHOFPCCONFIG                                                       STD_ON
#define MEMACC_SIZEOFREDIRECTSECTORBATCHOFPCCONFIG                                                  STD_OFF  /**< Deactivateable: 'MemAcc_PCConfig.SizeOfRedirectSectorBatch' Reason: 'Deactivateable: 'RedirectSectorBatch' Reason: 'Deactivateable: 'MemAcc_RedirectSectorBatch' Reason: 'the struct is deactivated because all elements are deactivated.''' */
#define MEMACC_SIZEOFSUBADDRESSAREAOFPCCONFIG                                                       STD_ON
#define MEMACC_SIZEOFSYNCGROUPOFPCCONFIG                                                            STD_OFF  /**< Deactivateable: 'MemAcc_PCConfig.SizeOfSyncGroup' Reason: 'Deactivateable: 'SyncGroup' Reason: 'Deactivateable: 'MemAcc_SyncGroup' Reason: 'Read alignment is required, no alignment buffer needed.''' */
#define MEMACC_SIZEOFVLOWERLAYEROFPCCONFIG                                                          STD_ON
#define MEMACC_SIZEOFVREADONLYCONFIGURATIONOFPCCONFIG                                               STD_OFF  /**< Deactivateable: 'MemAcc_PCConfig.SizeOfVReadOnlyConfiguration' Reason: 'Deactivateable: 'VReadOnlyConfiguration' Reason: 'Deactivateable: 'MemAcc_VReadOnlyConfiguration' Reason: 'ReadOnlyMode is not configured.''' */
#define MEMACC_SUBADDRESSAREAOFPCCONFIG                                                             STD_ON
#define MEMACC_VLOWERLAYEROFPCCONFIG                                                                STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  MemAccPCIsReducedToDefineDefines  MemAcc Is Reduced To Define Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define is STD_ON else STD_OFF.
  \{
*/ 
#define MEMACC_ISDEF_ADDRESSAREAIDOFADDRESSAREA                                                     STD_OFF
#define MEMACC_ISDEF_ERRORNOTIFICATIONOFADDRESSAREA                                                 STD_OFF
#define MEMACC_ISDEF_JOBENDNOTIFICATIONOFADDRESSAREA                                                STD_OFF
#define MEMACC_ISDEF_PRIORITYBASEDINDEXOFADDRESSAREA                                                STD_OFF
#define MEMACC_ISDEF_PRIORITYOFADDRESSAREA                                                          STD_OFF
#define MEMACC_ISDEF_SUBADDRESSAREAENDIDXOFADDRESSAREA                                              STD_OFF
#define MEMACC_ISDEF_SUBADDRESSAREASTARTIDXOFADDRESSAREA                                            STD_OFF
#define MEMACC_ISDEF_STATICMEMBINARYHEADEROFLOWERLAYER                                              STD_OFF
#define MEMACC_ISDEF_DEVERRORDETECTIONOFGENERALFEATURES                                             STD_OFF
#define MEMACC_ISDEF_DEVERRORREPORTOFGENERALFEATURES                                                STD_OFF
#define MEMACC_ISDEF_HARDWAREIDOFMEMINSTANCE                                                        STD_OFF
#define MEMACC_ISDEF_INSTANCEIDOFMEMINSTANCE                                                        STD_OFF
#define MEMACC_ISDEF_ERASEBURSTSIZEOFMEMSECTORBATCH                                                 STD_OFF
#define MEMACC_ISDEF_ERASESECTORSIZEOFMEMSECTORBATCH                                                STD_OFF
#define MEMACC_ISDEF_MAXREADSIZEOFMEMSECTORBATCH                                                    STD_OFF
#define MEMACC_ISDEF_MINREADSIZEOFMEMSECTORBATCH                                                    STD_OFF
#define MEMACC_ISDEF_WRITEBURSTSIZEOFMEMSECTORBATCH                                                 STD_OFF
#define MEMACC_ISDEF_WRITEPAGESIZEOFMEMSECTORBATCH                                                  STD_OFF
#define MEMACC_ISDEF_ACCESSTYPEOFSUBADDRESSAREA                                                     STD_OFF
#define MEMACC_ISDEF_LOGICALENDADDRESSOFSUBADDRESSAREA                                              STD_OFF
#define MEMACC_ISDEF_LOGICALSTARTADDRESSOFSUBADDRESSAREA                                            STD_OFF
#define MEMACC_ISDEF_LOWERLAYERIDXOFSUBADDRESSAREA                                                  STD_OFF
#define MEMACC_ISDEF_MEMINSTANCEIDXOFSUBADDRESSAREA                                                 STD_OFF
#define MEMACC_ISDEF_MEMSECTORBATCHIDXOFSUBADDRESSAREA                                              STD_OFF
#define MEMACC_ISDEF_NUMBEROFERASERETRIESOFSUBADDRESSAREA                                           STD_OFF
#define MEMACC_ISDEF_NUMBEROFREADRETRIESOFSUBADDRESSAREA                                            STD_OFF
#define MEMACC_ISDEF_NUMBEROFSECTORSOFSUBADDRESSAREA                                                STD_OFF
#define MEMACC_ISDEF_NUMBEROFWRITERETRIESOFSUBADDRESSAREA                                           STD_OFF
#define MEMACC_ISDEF_PHYSICALENDADDRESSOFSUBADDRESSAREA                                             STD_OFF
#define MEMACC_ISDEF_PHYSICALSTARTADDRESSOFSUBADDRESSAREA                                           STD_OFF
#define MEMACC_ISDEF_SECTOROFFSETOFSUBADDRESSAREA                                                   STD_OFF
#define MEMACC_ISDEF_SYNCGROUPIDOFSUBADDRESSAREA                                                    STD_OFF
#define MEMACC_ISDEF_USEERASEBURSTOFSUBADDRESSAREA                                                  STD_OFF
#define MEMACC_ISDEF_USEWRITEBURSTOFSUBADDRESSAREA                                                  STD_OFF
#define MEMACC_ISDEF_ADDRESSAREAOFPCCONFIG                                                          STD_ON
#define MEMACC_ISDEF_CLOWERLAYEROFPCCONFIG                                                          STD_ON
#define MEMACC_ISDEF_GENERALFEATURESOFPCCONFIG                                                      STD_ON
#define MEMACC_ISDEF_MEMINSTANCEOFPCCONFIG                                                          STD_ON
#define MEMACC_ISDEF_MEMSECTORBATCHOFPCCONFIG                                                       STD_ON
#define MEMACC_ISDEF_SUBADDRESSAREAOFPCCONFIG                                                       STD_ON
#define MEMACC_ISDEF_VLOWERLAYEROFPCCONFIG                                                          STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  MemAccPCEqualsAlwaysToDefines  MemAcc Equals Always To Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define contains the always equals value.
  \{
*/ 
#define MEMACC_EQ2_ADDRESSAREAIDOFADDRESSAREA                                                       
#define MEMACC_EQ2_ERRORNOTIFICATIONOFADDRESSAREA                                                   
#define MEMACC_EQ2_JOBENDNOTIFICATIONOFADDRESSAREA                                                  
#define MEMACC_EQ2_PRIORITYBASEDINDEXOFADDRESSAREA                                                  
#define MEMACC_EQ2_PRIORITYOFADDRESSAREA                                                            
#define MEMACC_EQ2_SUBADDRESSAREAENDIDXOFADDRESSAREA                                                
#define MEMACC_EQ2_SUBADDRESSAREASTARTIDXOFADDRESSAREA                                              
#define MEMACC_EQ2_STATICMEMBINARYHEADEROFLOWERLAYER                                                
#define MEMACC_EQ2_DEVERRORDETECTIONOFGENERALFEATURES                                               
#define MEMACC_EQ2_DEVERRORREPORTOFGENERALFEATURES                                                  
#define MEMACC_EQ2_HARDWAREIDOFMEMINSTANCE                                                          
#define MEMACC_EQ2_INSTANCEIDOFMEMINSTANCE                                                          
#define MEMACC_EQ2_ERASEBURSTSIZEOFMEMSECTORBATCH                                                   
#define MEMACC_EQ2_ERASESECTORSIZEOFMEMSECTORBATCH                                                  
#define MEMACC_EQ2_MAXREADSIZEOFMEMSECTORBATCH                                                      
#define MEMACC_EQ2_MINREADSIZEOFMEMSECTORBATCH                                                      
#define MEMACC_EQ2_WRITEBURSTSIZEOFMEMSECTORBATCH                                                   
#define MEMACC_EQ2_WRITEPAGESIZEOFMEMSECTORBATCH                                                    
#define MEMACC_EQ2_ACCESSTYPEOFSUBADDRESSAREA                                                       
#define MEMACC_EQ2_LOGICALENDADDRESSOFSUBADDRESSAREA                                                
#define MEMACC_EQ2_LOGICALSTARTADDRESSOFSUBADDRESSAREA                                              
#define MEMACC_EQ2_LOWERLAYERIDXOFSUBADDRESSAREA                                                    
#define MEMACC_EQ2_MEMINSTANCEIDXOFSUBADDRESSAREA                                                   
#define MEMACC_EQ2_MEMSECTORBATCHIDXOFSUBADDRESSAREA                                                
#define MEMACC_EQ2_NUMBEROFERASERETRIESOFSUBADDRESSAREA                                             
#define MEMACC_EQ2_NUMBEROFREADRETRIESOFSUBADDRESSAREA                                              
#define MEMACC_EQ2_NUMBEROFSECTORSOFSUBADDRESSAREA                                                  
#define MEMACC_EQ2_NUMBEROFWRITERETRIESOFSUBADDRESSAREA                                             
#define MEMACC_EQ2_PHYSICALENDADDRESSOFSUBADDRESSAREA                                               
#define MEMACC_EQ2_PHYSICALSTARTADDRESSOFSUBADDRESSAREA                                             
#define MEMACC_EQ2_SECTOROFFSETOFSUBADDRESSAREA                                                     
#define MEMACC_EQ2_SYNCGROUPIDOFSUBADDRESSAREA                                                      
#define MEMACC_EQ2_USEERASEBURSTOFSUBADDRESSAREA                                                    
#define MEMACC_EQ2_USEWRITEBURSTOFSUBADDRESSAREA                                                    
#define MEMACC_EQ2_ADDRESSAREAOFPCCONFIG                                                            MemAcc_AddressArea
#define MEMACC_EQ2_CLOWERLAYEROFPCCONFIG                                                            MemAcc_CLowerLayer
#define MEMACC_EQ2_GENERALFEATURESOFPCCONFIG                                                        MemAcc_GeneralFeatures
#define MEMACC_EQ2_MEMINSTANCEOFPCCONFIG                                                            MemAcc_MemInstance
#define MEMACC_EQ2_MEMSECTORBATCHOFPCCONFIG                                                         MemAcc_MemSectorBatch
#define MEMACC_EQ2_SUBADDRESSAREAOFPCCONFIG                                                         MemAcc_SubAddressArea
#define MEMACC_EQ2_VLOWERLAYEROFPCCONFIG                                                            MemAcc_VLowerLayer.raw
/** 
  \}
*/ 

/** 
  \defgroup  MemAccPCSymbolicInitializationPointers  MemAcc Symbolic Initialization Pointers (PRE_COMPILE)
  \brief  Symbolic initialization pointers to be used in the call of a preinit or init function.
  \{
*/ 
#define MemAcc_Config_Ptr                                                                           NULL_PTR  /**< symbolic identifier which shall be used to initialize 'MemAcc' */
/** 
  \}
*/ 

/** 
  \defgroup  MemAccPCInitializationSymbols  MemAcc Initialization Symbols (PRE_COMPILE)
  \brief  Symbolic initialization pointers which may be used in the call of a preinit or init function. Please note, that the defined value can be a 'NULL_PTR' and the address operator is not usable.
  \{
*/ 
#define MemAcc_Config                                                                               NULL_PTR  /**< symbolic identifier which could be used to initialize 'MemAcc */
/** 
  \}
*/ 

/** 
  \defgroup  MemAccPCGeneral  MemAcc General (PRE_COMPILE)
  \brief  General constant defines not associated with a group of defines.
  \{
*/ 
#define MEMACC_CHECK_INIT_POINTER                                                                   STD_OFF  /**< STD_ON if the init pointer shall not be used as NULL_PTR and a check shall validate this. */
#define MEMACC_FINAL_MAGIC_NUMBER                                                                   0x291Eu  /**< the precompile constant to validate the size of the initialization structure at initialization time of MemAcc */
#define MEMACC_INDIVIDUAL_POSTBUILD                                                                 STD_OFF  /**< the precompile constant to check, that the module is individual postbuildable. The module 'MemAcc' is not configured to be postbuild capable. */
#define MEMACC_INIT_DATA                                                                            MEMACC_CONST  /**< CompilerMemClassDefine for the initialization data. */
#define MEMACC_INIT_DATA_HASH_CODE                                                                  1725667768  /**< the precompile constant to validate the initialization structure at initialization time of MemAcc with a hashcode. The seed value is '0x291Eu' */
#define MEMACC_USE_ECUM_BSW_ERROR_HOOK                                                              STD_OFF  /**< STD_ON if the EcuM_BswErrorHook shall be called in the ConfigPtr check. */
#define MEMACC_USE_INIT_POINTER                                                                     STD_OFF  /**< STD_ON if the init pointer MemAcc shall be used. */
/** 
  \}
*/ 


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  MemAccLTDataSwitches  MemAcc Data Switches  (LINK)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define MEMACC_LTCONFIG                                                                             STD_OFF  /**< Deactivateable: 'MemAcc_LTConfig' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
/** 
  \}
*/ 


/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  MemAccPBDataSwitches  MemAcc Data Switches  (POST_BUILD)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define MEMACC_PBCONFIG                                                                             STD_OFF  /**< Deactivateable: 'MemAcc_PBConfig' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define MEMACC_LTCONFIGIDXOFPBCONFIG                                                                STD_OFF  /**< Deactivateable: 'MemAcc_PBConfig.LTConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define MEMACC_PCCONFIGIDXOFPBCONFIG                                                                STD_OFF  /**< Deactivateable: 'MemAcc_PBConfig.PCConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
/** 
  \}
*/ 



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
  \defgroup  MemAccPCGetConstantDuplicatedRootDataMacros  MemAcc Get Constant Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated by constance root data elements.
  \{
*/ 
#define MemAcc_GetAddressAreaOfPCConfig()                                                           MemAcc_AddressArea  /**< the pointer to MemAcc_AddressArea */
#define MemAcc_GetCLowerLayerOfPCConfig()                                                           MemAcc_CLowerLayer  /**< the pointer to MemAcc_CLowerLayer */
#define MemAcc_GetGeneralFeaturesOfPCConfig()                                                       MemAcc_GeneralFeatures  /**< the pointer to MemAcc_GeneralFeatures */
#define MemAcc_GetMemInstanceOfPCConfig()                                                           MemAcc_MemInstance  /**< the pointer to MemAcc_MemInstance */
#define MemAcc_GetMemSectorBatchOfPCConfig()                                                        MemAcc_MemSectorBatch  /**< the pointer to MemAcc_MemSectorBatch */
#define MemAcc_GetSizeOfAddressAreaOfPCConfig()                                                     1u  /**< the number of accomplishable value elements in MemAcc_AddressArea */
#define MemAcc_GetSizeOfCLowerLayerOfPCConfig()                                                     1u  /**< the number of accomplishable value elements in MemAcc_CLowerLayer */
#define MemAcc_GetSizeOfGeneralFeaturesOfPCConfig()                                                 1u  /**< the number of accomplishable value elements in MemAcc_GeneralFeatures */
#define MemAcc_GetSizeOfMemInstanceOfPCConfig()                                                     1u  /**< the number of accomplishable value elements in MemAcc_MemInstance */
#define MemAcc_GetSizeOfMemSectorBatchOfPCConfig()                                                  1u  /**< the number of accomplishable value elements in MemAcc_MemSectorBatch */
#define MemAcc_GetSizeOfSubAddressAreaOfPCConfig()                                                  1u  /**< the number of accomplishable value elements in MemAcc_SubAddressArea */
#define MemAcc_GetSubAddressAreaOfPCConfig()                                                        MemAcc_SubAddressArea  /**< the pointer to MemAcc_SubAddressArea */
#define MemAcc_GetVLowerLayerOfPCConfig()                                                           MemAcc_VLowerLayer.raw  /**< the pointer to MemAcc_VLowerLayer */
/** 
  \}
*/ 

/** 
  \defgroup  MemAccPCGetDuplicatedRootDataMacros  MemAcc Get Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated root data elements.
  \{
*/ 
#define MemAcc_GetSizeOfVLowerLayerOfPCConfig()                                                     MemAcc_GetSizeOfCLowerLayerOfPCConfig()  /**< the number of accomplishable value elements in MemAcc_VLowerLayer */
/** 
  \}
*/ 

/** 
  \defgroup  MemAccPCGetDataMacros  MemAcc Get Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read CONST and VAR data.
  \{
*/ 
#define MemAcc_GetAddressAreaIdOfAddressArea(Index)                                                 (MemAcc_GetAddressAreaOfPCConfig()[(Index)].AddressAreaIdOfAddressArea)
#define MemAcc_GetErrorNotificationOfAddressArea(Index)                                             (MemAcc_GetAddressAreaOfPCConfig()[(Index)].ErrorNotificationOfAddressArea)
#define MemAcc_GetJobEndNotificationOfAddressArea(Index)                                            (MemAcc_GetAddressAreaOfPCConfig()[(Index)].JobEndNotificationOfAddressArea)
#define MemAcc_GetPriorityBasedIndexOfAddressArea(Index)                                            (MemAcc_GetAddressAreaOfPCConfig()[(Index)].PriorityBasedIndexOfAddressArea)
#define MemAcc_GetPriorityOfAddressArea(Index)                                                      (MemAcc_GetAddressAreaOfPCConfig()[(Index)].PriorityOfAddressArea)
#define MemAcc_GetSubAddressAreaEndIdxOfAddressArea(Index)                                          (MemAcc_GetAddressAreaOfPCConfig()[(Index)].SubAddressAreaEndIdxOfAddressArea)
#define MemAcc_GetSubAddressAreaStartIdxOfAddressArea(Index)                                        (MemAcc_GetAddressAreaOfPCConfig()[(Index)].SubAddressAreaStartIdxOfAddressArea)
#define MemAcc_GetStaticMemBinaryHeaderOfLowerLayer(Index)                                          (MemAcc_GetCLowerLayerOfPCConfig()[(Index)].StaticMemBinaryHeaderOfLowerLayer)
#define MemAcc_IsDevErrorDetectionOfGeneralFeatures(Index)                                          ((MemAcc_GetGeneralFeaturesOfPCConfig()[(Index)].DevErrorDetectionOfGeneralFeatures) != FALSE)
#define MemAcc_IsDevErrorReportOfGeneralFeatures(Index)                                             ((MemAcc_GetGeneralFeaturesOfPCConfig()[(Index)].DevErrorReportOfGeneralFeatures) != FALSE)
#define MemAcc_GetHardwareIdOfMemInstance(Index)                                                    (MemAcc_GetMemInstanceOfPCConfig()[(Index)].HardwareIdOfMemInstance)
#define MemAcc_GetInstanceIdOfMemInstance(Index)                                                    (MemAcc_GetMemInstanceOfPCConfig()[(Index)].InstanceIdOfMemInstance)
#define MemAcc_GetEraseBurstSizeOfMemSectorBatch(Index)                                             (MemAcc_GetMemSectorBatchOfPCConfig()[(Index)].EraseBurstSizeOfMemSectorBatch)
#define MemAcc_GetEraseSectorSizeOfMemSectorBatch(Index)                                            (MemAcc_GetMemSectorBatchOfPCConfig()[(Index)].EraseSectorSizeOfMemSectorBatch)
#define MemAcc_GetMaxReadSizeOfMemSectorBatch(Index)                                                (MemAcc_GetMemSectorBatchOfPCConfig()[(Index)].MaxReadSizeOfMemSectorBatch)
#define MemAcc_GetMinReadSizeOfMemSectorBatch(Index)                                                (MemAcc_GetMemSectorBatchOfPCConfig()[(Index)].MinReadSizeOfMemSectorBatch)
#define MemAcc_GetWriteBurstSizeOfMemSectorBatch(Index)                                             (MemAcc_GetMemSectorBatchOfPCConfig()[(Index)].WriteBurstSizeOfMemSectorBatch)
#define MemAcc_GetWritePageSizeOfMemSectorBatch(Index)                                              (MemAcc_GetMemSectorBatchOfPCConfig()[(Index)].WritePageSizeOfMemSectorBatch)
#define MemAcc_GetAccessTypeOfSubAddressArea(Index)                                                 (MemAcc_GetSubAddressAreaOfPCConfig()[(Index)].AccessTypeOfSubAddressArea)
#define MemAcc_GetLogicalEndAddressOfSubAddressArea(Index)                                          (MemAcc_GetSubAddressAreaOfPCConfig()[(Index)].LogicalEndAddressOfSubAddressArea)
#define MemAcc_GetLogicalStartAddressOfSubAddressArea(Index)                                        (MemAcc_GetSubAddressAreaOfPCConfig()[(Index)].LogicalStartAddressOfSubAddressArea)
#define MemAcc_GetLowerLayerIdxOfSubAddressArea(Index)                                              (MemAcc_GetSubAddressAreaOfPCConfig()[(Index)].LowerLayerIdxOfSubAddressArea)
#define MemAcc_GetMemInstanceIdxOfSubAddressArea(Index)                                             (MemAcc_GetSubAddressAreaOfPCConfig()[(Index)].MemInstanceIdxOfSubAddressArea)
#define MemAcc_GetMemSectorBatchIdxOfSubAddressArea(Index)                                          (MemAcc_GetSubAddressAreaOfPCConfig()[(Index)].MemSectorBatchIdxOfSubAddressArea)
#define MemAcc_GetNumberOfEraseRetriesOfSubAddressArea(Index)                                       (MemAcc_GetSubAddressAreaOfPCConfig()[(Index)].NumberOfEraseRetriesOfSubAddressArea)
#define MemAcc_GetNumberOfReadRetriesOfSubAddressArea(Index)                                        (MemAcc_GetSubAddressAreaOfPCConfig()[(Index)].NumberOfReadRetriesOfSubAddressArea)
#define MemAcc_GetNumberOfSectorsOfSubAddressArea(Index)                                            (MemAcc_GetSubAddressAreaOfPCConfig()[(Index)].NumberOfSectorsOfSubAddressArea)
#define MemAcc_GetNumberOfWriteRetriesOfSubAddressArea(Index)                                       (MemAcc_GetSubAddressAreaOfPCConfig()[(Index)].NumberOfWriteRetriesOfSubAddressArea)
#define MemAcc_GetPhysicalEndAddressOfSubAddressArea(Index)                                         (MemAcc_GetSubAddressAreaOfPCConfig()[(Index)].PhysicalEndAddressOfSubAddressArea)
#define MemAcc_GetPhysicalStartAddressOfSubAddressArea(Index)                                       (MemAcc_GetSubAddressAreaOfPCConfig()[(Index)].PhysicalStartAddressOfSubAddressArea)
#define MemAcc_GetSectorOffsetOfSubAddressArea(Index)                                               (MemAcc_GetSubAddressAreaOfPCConfig()[(Index)].SectorOffsetOfSubAddressArea)
#define MemAcc_GetSyncGroupIdOfSubAddressArea(Index)                                                (MemAcc_GetSubAddressAreaOfPCConfig()[(Index)].SyncGroupIdOfSubAddressArea)
#define MemAcc_IsUseEraseBurstOfSubAddressArea(Index)                                               ((MemAcc_GetSubAddressAreaOfPCConfig()[(Index)].UseEraseBurstOfSubAddressArea) != FALSE)
#define MemAcc_IsUseWriteBurstOfSubAddressArea(Index)                                               ((MemAcc_GetSubAddressAreaOfPCConfig()[(Index)].UseWriteBurstOfSubAddressArea) != FALSE)
#define MemAcc_GetIndirectDynamicMemBinaryHeaderOfLowerLayer(Index)                                 (MemAcc_GetVLowerLayerOfPCConfig()[(Index)].IndirectDynamicMemBinaryHeaderOfLowerLayer)
/** 
  \}
*/ 

/** 
  \defgroup  MemAccPCGetDeduplicatedDataMacros  MemAcc Get Deduplicated Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated data elements.
  \{
*/ 
#define MemAcc_GetSizeOfAddressArea()                                                               MemAcc_GetSizeOfAddressAreaOfPCConfig()
#define MemAcc_GetSizeOfCLowerLayer()                                                               MemAcc_GetSizeOfCLowerLayerOfPCConfig()
#define MemAcc_GetSizeOfGeneralFeatures()                                                           MemAcc_GetSizeOfGeneralFeaturesOfPCConfig()
#define MemAcc_GetSizeOfMemInstance()                                                               MemAcc_GetSizeOfMemInstanceOfPCConfig()
#define MemAcc_GetSizeOfMemSectorBatch()                                                            MemAcc_GetSizeOfMemSectorBatchOfPCConfig()
#define MemAcc_GetSizeOfSubAddressArea()                                                            MemAcc_GetSizeOfSubAddressAreaOfPCConfig()
#define MemAcc_GetSizeOfVLowerLayer()                                                               MemAcc_GetSizeOfVLowerLayerOfPCConfig()
/** 
  \}
*/ 

/** 
  \defgroup  MemAccPCSetDataMacros  MemAcc Set Data Macros (PRE_COMPILE)
  \brief  These macros can be used to write data.
  \{
*/ 
#define MemAcc_SetIndirectDynamicMemBinaryHeaderOfLowerLayer(Index, Value)                          MemAcc_GetVLowerLayerOfPCConfig()[(Index)].IndirectDynamicMemBinaryHeaderOfLowerLayer = (Value)
/** 
  \}
*/ 

/** 
  \defgroup  MemAccPCHasMacros  MemAcc Has Macros (PRE_COMPILE)
  \brief  These macros can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
#define MemAcc_HasAddressArea()                                                                     (TRUE != FALSE)
#define MemAcc_HasAddressAreaIdOfAddressArea()                                                      (TRUE != FALSE)
#define MemAcc_HasErrorNotificationOfAddressArea()                                                  (TRUE != FALSE)
#define MemAcc_HasJobEndNotificationOfAddressArea()                                                 (TRUE != FALSE)
#define MemAcc_HasPriorityBasedIndexOfAddressArea()                                                 (TRUE != FALSE)
#define MemAcc_HasPriorityOfAddressArea()                                                           (TRUE != FALSE)
#define MemAcc_HasSubAddressAreaEndIdxOfAddressArea()                                               (TRUE != FALSE)
#define MemAcc_HasSubAddressAreaStartIdxOfAddressArea()                                             (TRUE != FALSE)
#define MemAcc_HasCLowerLayer()                                                                     (TRUE != FALSE)
#define MemAcc_HasStaticMemBinaryHeaderOfLowerLayer()                                               (TRUE != FALSE)
#define MemAcc_HasGeneralFeatures()                                                                 (TRUE != FALSE)
#define MemAcc_HasDevErrorDetectionOfGeneralFeatures()                                              (TRUE != FALSE)
#define MemAcc_HasDevErrorReportOfGeneralFeatures()                                                 (TRUE != FALSE)
#define MemAcc_HasMemInstance()                                                                     (TRUE != FALSE)
#define MemAcc_HasHardwareIdOfMemInstance()                                                         (TRUE != FALSE)
#define MemAcc_HasInstanceIdOfMemInstance()                                                         (TRUE != FALSE)
#define MemAcc_HasMemSectorBatch()                                                                  (TRUE != FALSE)
#define MemAcc_HasEraseBurstSizeOfMemSectorBatch()                                                  (TRUE != FALSE)
#define MemAcc_HasEraseSectorSizeOfMemSectorBatch()                                                 (TRUE != FALSE)
#define MemAcc_HasMaxReadSizeOfMemSectorBatch()                                                     (TRUE != FALSE)
#define MemAcc_HasMinReadSizeOfMemSectorBatch()                                                     (TRUE != FALSE)
#define MemAcc_HasWriteBurstSizeOfMemSectorBatch()                                                  (TRUE != FALSE)
#define MemAcc_HasWritePageSizeOfMemSectorBatch()                                                   (TRUE != FALSE)
#define MemAcc_HasSizeOfAddressArea()                                                               (TRUE != FALSE)
#define MemAcc_HasSizeOfCLowerLayer()                                                               (TRUE != FALSE)
#define MemAcc_HasSizeOfGeneralFeatures()                                                           (TRUE != FALSE)
#define MemAcc_HasSizeOfMemInstance()                                                               (TRUE != FALSE)
#define MemAcc_HasSizeOfMemSectorBatch()                                                            (TRUE != FALSE)
#define MemAcc_HasSizeOfSubAddressArea()                                                            (TRUE != FALSE)
#define MemAcc_HasSizeOfVLowerLayer()                                                               (TRUE != FALSE)
#define MemAcc_HasSubAddressArea()                                                                  (TRUE != FALSE)
#define MemAcc_HasAccessTypeOfSubAddressArea()                                                      (TRUE != FALSE)
#define MemAcc_HasLogicalEndAddressOfSubAddressArea()                                               (TRUE != FALSE)
#define MemAcc_HasLogicalStartAddressOfSubAddressArea()                                             (TRUE != FALSE)
#define MemAcc_HasLowerLayerIdxOfSubAddressArea()                                                   (TRUE != FALSE)
#define MemAcc_HasMemInstanceIdxOfSubAddressArea()                                                  (TRUE != FALSE)
#define MemAcc_HasMemSectorBatchIdxOfSubAddressArea()                                               (TRUE != FALSE)
#define MemAcc_HasNumberOfEraseRetriesOfSubAddressArea()                                            (TRUE != FALSE)
#define MemAcc_HasNumberOfReadRetriesOfSubAddressArea()                                             (TRUE != FALSE)
#define MemAcc_HasNumberOfSectorsOfSubAddressArea()                                                 (TRUE != FALSE)
#define MemAcc_HasNumberOfWriteRetriesOfSubAddressArea()                                            (TRUE != FALSE)
#define MemAcc_HasPhysicalEndAddressOfSubAddressArea()                                              (TRUE != FALSE)
#define MemAcc_HasPhysicalStartAddressOfSubAddressArea()                                            (TRUE != FALSE)
#define MemAcc_HasSectorOffsetOfSubAddressArea()                                                    (TRUE != FALSE)
#define MemAcc_HasSyncGroupIdOfSubAddressArea()                                                     (TRUE != FALSE)
#define MemAcc_HasUseEraseBurstOfSubAddressArea()                                                   (TRUE != FALSE)
#define MemAcc_HasUseWriteBurstOfSubAddressArea()                                                   (TRUE != FALSE)
#define MemAcc_HasVLowerLayer()                                                                     (TRUE != FALSE)
#define MemAcc_HasIndirectDynamicMemBinaryHeaderOfLowerLayer()                                      (TRUE != FALSE)
#define MemAcc_HasPCConfig()                                                                        (TRUE != FALSE)
#define MemAcc_HasAddressAreaOfPCConfig()                                                           (TRUE != FALSE)
#define MemAcc_HasCLowerLayerOfPCConfig()                                                           (TRUE != FALSE)
#define MemAcc_HasGeneralFeaturesOfPCConfig()                                                       (TRUE != FALSE)
#define MemAcc_HasMemInstanceOfPCConfig()                                                           (TRUE != FALSE)
#define MemAcc_HasMemSectorBatchOfPCConfig()                                                        (TRUE != FALSE)
#define MemAcc_HasSizeOfAddressAreaOfPCConfig()                                                     (TRUE != FALSE)
#define MemAcc_HasSizeOfCLowerLayerOfPCConfig()                                                     (TRUE != FALSE)
#define MemAcc_HasSizeOfGeneralFeaturesOfPCConfig()                                                 (TRUE != FALSE)
#define MemAcc_HasSizeOfMemInstanceOfPCConfig()                                                     (TRUE != FALSE)
#define MemAcc_HasSizeOfMemSectorBatchOfPCConfig()                                                  (TRUE != FALSE)
#define MemAcc_HasSizeOfSubAddressAreaOfPCConfig()                                                  (TRUE != FALSE)
#define MemAcc_HasSizeOfVLowerLayerOfPCConfig()                                                     (TRUE != FALSE)
#define MemAcc_HasSubAddressAreaOfPCConfig()                                                        (TRUE != FALSE)
#define MemAcc_HasVLowerLayerOfPCConfig()                                                           (TRUE != FALSE)
/** 
  \}
*/ 

/** 
  \defgroup  MemAccPCIncrementDataMacros  MemAcc Increment Data Macros (PRE_COMPILE)
  \brief  These macros can be used to increment VAR data with numerical nature.
  \{
*/ 
#define MemAcc_IncIndirectDynamicMemBinaryHeaderOfLowerLayer(Index)                                 MemAcc_GetIndirectDynamicMemBinaryHeaderOfLowerLayer(Index)++
/** 
  \}
*/ 

/** 
  \defgroup  MemAccPCDecrementDataMacros  MemAcc Decrement Data Macros (PRE_COMPILE)
  \brief  These macros can be used to decrement VAR data with numerical nature.
  \{
*/ 
#define MemAcc_DecIndirectDynamicMemBinaryHeaderOfLowerLayer(Index)                                 MemAcc_GetIndirectDynamicMemBinaryHeaderOfLowerLayer(Index)--
/** 
  \}
*/ 

/** 
  \defgroup  MemAccPCAddDataMacros  MemAcc Add Data Macros (PRE_COMPILE)
  \brief  These macros can be used to add VAR data with numerical nature.
  \{
*/ 
#define MemAcc_AddIndirectDynamicMemBinaryHeaderOfLowerLayer(Index, Value)                          MemAcc_SetIndirectDynamicMemBinaryHeaderOfLowerLayer(Index, (MemAcc_GetIndirectDynamicMemBinaryHeaderOfLowerLayer(Index) + Value))
/** 
  \}
*/ 

/** 
  \defgroup  MemAccPCSubstractDataMacros  MemAcc Substract Data Macros (PRE_COMPILE)
  \brief  These macros can be used to substract VAR data with numerical nature.
  \{
*/ 
#define MemAcc_SubIndirectDynamicMemBinaryHeaderOfLowerLayer(Index, Value)                          MemAcc_SetIndirectDynamicMemBinaryHeaderOfLowerLayer(Index, (MemAcc_GetIndirectDynamicMemBinaryHeaderOfLowerLayer(Index) - Value))
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

/** 
  \defgroup  DataAccessMacros  Data Access Macros
  \brief  generated data access macros to abstract the generated data from the code to read and write CONST or VAR data.
  \{
*/ 
  /* PRQA S 3453 Macros_3453 */  /* MD_MSR_FctLikeMacro */
/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL FUNCTION MACROS
**********************************************************************************************************************/
  /* PRQA L:Macros_3453 */
/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL ACCESS FUNCTION MACROS
**********************************************************************************************************************/

/** 
  \defgroup  DataAccessMacros  Data Access Macros
  \brief  generated data access macros to abstract the generated data from the code to read and write CONST or VAR data.
  \{
*/ 
  /* PRQA S 3453 Macros_3453 */  /* MD_MSR_FctLikeMacro */
/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL FUNCTION MACROS
**********************************************************************************************************************/
  /* PRQA L:Macros_3453 */
/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL ACCESS FUNCTION MACROS
**********************************************************************************************************************/


#ifndef MEMACC_DUMMY_STATEMENT
# define MEMACC_DUMMY_STATEMENT(v) (void)(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#endif

# define MemAcc_CallDetReportError(ModuleId, InstanceId, ApiId, ErrorId) // ((void)Det_ReportError((ModuleId), (InstanceId), (ApiId), (ErrorId)))

/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/ 

extern CONST(MemAcc_MemBinaryHeaderType, MEMACC_CONST) Mem_30_LegacyAdapter_FunctionPointerTable;

typedef enum
{
  MEMACC_SINGLEBINARY_ACCESS         = 0u, /*!< Direct access to Mem. */
  MEMACC_MULTIBINARY_DIRECT_ACCESS   = 1u, /*!< Access to underlying Mem need to be approved by master binary. */
  MEMACC_MULTIBINARY_REDIRECT_ACCESS = 2u  /*!< Jobs are redirected to master binary. */
} MemAcc_AccessType; /*!< Defines how each SubAddressArea access the Mem. */

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: SIZEOF DATA TYPES
**********************************************************************************************************************/
/** 
  \defgroup  MemAccPCSizeOfTypes  MemAcc SizeOf Types (PRE_COMPILE)
  \brief  These type definitions are used for the SizeOf information.
  \{
*/ 
/**   \brief  value based type definition for MemAcc_SizeOfAddressArea */
typedef uint8 MemAcc_SizeOfAddressAreaType;

/**   \brief  value based type definition for MemAcc_SizeOfCLowerLayer */
typedef uint8 MemAcc_SizeOfCLowerLayerType;

/**   \brief  value based type definition for MemAcc_SizeOfGeneralFeatures */
typedef uint8 MemAcc_SizeOfGeneralFeaturesType;

/**   \brief  value based type definition for MemAcc_SizeOfMemInstance */
typedef uint8 MemAcc_SizeOfMemInstanceType;

/**   \brief  value based type definition for MemAcc_SizeOfMemSectorBatch */
typedef uint8 MemAcc_SizeOfMemSectorBatchType;

/**   \brief  value based type definition for MemAcc_SizeOfSubAddressArea */
typedef uint8 MemAcc_SizeOfSubAddressAreaType;

/**   \brief  value based type definition for MemAcc_SizeOfVLowerLayer */
typedef uint8 MemAcc_SizeOfVLowerLayerType;

/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  MemAccPCIterableTypes  MemAcc Iterable Types (PRE_COMPILE)
  \brief  These type definitions are used to iterate over an array with least processor cycles for variable access as possible.
  \{
*/ 
/**   \brief  type used to iterate MemAcc_AddressArea */
typedef uint8_least MemAcc_AddressAreaIterType;

/**   \brief  type used to iterate MemAcc_CLowerLayer */
typedef uint8_least MemAcc_CLowerLayerIterType;

/**   \brief  type used to iterate MemAcc_GeneralFeatures */
typedef uint8_least MemAcc_GeneralFeaturesIterType;

/**   \brief  type used to iterate MemAcc_MemInstance */
typedef uint8_least MemAcc_MemInstanceIterType;

/**   \brief  type used to iterate MemAcc_MemSectorBatch */
typedef uint8_least MemAcc_MemSectorBatchIterType;

/**   \brief  type used to iterate MemAcc_SubAddressArea */
typedef uint8_least MemAcc_SubAddressAreaIterType;

/** 
  \}
*/ 

/** 
  \defgroup  MemAccPCIterableTypesWithSizeRelations  MemAcc Iterable Types With Size Relations (PRE_COMPILE)
  \brief  These type definitions are used to iterate over a VAR based array with the same iterator as the related CONST array.
  \{
*/ 
/**   \brief  type used to iterate MemAcc_VLowerLayer */
typedef MemAcc_CLowerLayerIterType MemAcc_VLowerLayerIterType;

/** 
  \}
*/ 

/** 
  \defgroup  MemAccPCValueTypes  MemAcc Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value based data representations.
  \{
*/ 
/**   \brief  value based type definition for MemAcc_PriorityBasedIndexOfAddressArea */
typedef uint8 MemAcc_PriorityBasedIndexOfAddressAreaType;

/**   \brief  value based type definition for MemAcc_PriorityOfAddressArea */
typedef uint8 MemAcc_PriorityOfAddressAreaType;

/**   \brief  value based type definition for MemAcc_SubAddressAreaEndIdxOfAddressArea */
typedef uint8 MemAcc_SubAddressAreaEndIdxOfAddressAreaType;

/**   \brief  value based type definition for MemAcc_SubAddressAreaStartIdxOfAddressArea */
typedef uint8 MemAcc_SubAddressAreaStartIdxOfAddressAreaType;

/**   \brief  value based type definition for MemAcc_DevErrorDetectionOfGeneralFeatures */
typedef boolean MemAcc_DevErrorDetectionOfGeneralFeaturesType;

/**   \brief  value based type definition for MemAcc_DevErrorReportOfGeneralFeatures */
typedef boolean MemAcc_DevErrorReportOfGeneralFeaturesType;

/**   \brief  value based type definition for MemAcc_InstanceIdOfMemInstance */
typedef uint8 MemAcc_InstanceIdOfMemInstanceType;

/**   \brief  value based type definition for MemAcc_EraseBurstSizeOfMemSectorBatch */
typedef uint16 MemAcc_EraseBurstSizeOfMemSectorBatchType;

/**   \brief  value based type definition for MemAcc_EraseSectorSizeOfMemSectorBatch */
typedef uint16 MemAcc_EraseSectorSizeOfMemSectorBatchType;

/**   \brief  value based type definition for MemAcc_MaxReadSizeOfMemSectorBatch */
typedef uint16 MemAcc_MaxReadSizeOfMemSectorBatchType;

/**   \brief  value based type definition for MemAcc_MinReadSizeOfMemSectorBatch */
typedef uint8 MemAcc_MinReadSizeOfMemSectorBatchType;

/**   \brief  value based type definition for MemAcc_WriteBurstSizeOfMemSectorBatch */
typedef uint8 MemAcc_WriteBurstSizeOfMemSectorBatchType;

/**   \brief  value based type definition for MemAcc_WritePageSizeOfMemSectorBatch */
typedef uint8 MemAcc_WritePageSizeOfMemSectorBatchType;

/**   \brief  value based type definition for MemAcc_LogicalEndAddressOfSubAddressArea */
typedef uint32 MemAcc_LogicalEndAddressOfSubAddressAreaType;

/**   \brief  value based type definition for MemAcc_LogicalStartAddressOfSubAddressArea */
typedef uint8 MemAcc_LogicalStartAddressOfSubAddressAreaType;

/**   \brief  value based type definition for MemAcc_LowerLayerIdxOfSubAddressArea */
typedef uint8 MemAcc_LowerLayerIdxOfSubAddressAreaType;

/**   \brief  value based type definition for MemAcc_MemInstanceIdxOfSubAddressArea */
typedef uint8 MemAcc_MemInstanceIdxOfSubAddressAreaType;

/**   \brief  value based type definition for MemAcc_MemSectorBatchIdxOfSubAddressArea */
typedef uint8 MemAcc_MemSectorBatchIdxOfSubAddressAreaType;

/**   \brief  value based type definition for MemAcc_NumberOfEraseRetriesOfSubAddressArea */
typedef uint8 MemAcc_NumberOfEraseRetriesOfSubAddressAreaType;

/**   \brief  value based type definition for MemAcc_NumberOfReadRetriesOfSubAddressArea */
typedef uint8 MemAcc_NumberOfReadRetriesOfSubAddressAreaType;

/**   \brief  value based type definition for MemAcc_NumberOfSectorsOfSubAddressArea */
typedef uint8 MemAcc_NumberOfSectorsOfSubAddressAreaType;

/**   \brief  value based type definition for MemAcc_NumberOfWriteRetriesOfSubAddressArea */
typedef uint8 MemAcc_NumberOfWriteRetriesOfSubAddressAreaType;

/**   \brief  value based type definition for MemAcc_PhysicalEndAddressOfSubAddressArea */
typedef uint32 MemAcc_PhysicalEndAddressOfSubAddressAreaType;

/**   \brief  value based type definition for MemAcc_PhysicalStartAddressOfSubAddressArea */
typedef uint32 MemAcc_PhysicalStartAddressOfSubAddressAreaType;

/**   \brief  value based type definition for MemAcc_SectorOffsetOfSubAddressArea */
typedef uint8 MemAcc_SectorOffsetOfSubAddressAreaType;

/**   \brief  value based type definition for MemAcc_SyncGroupIdOfSubAddressArea */
typedef uint8 MemAcc_SyncGroupIdOfSubAddressAreaType;

/**   \brief  value based type definition for MemAcc_UseEraseBurstOfSubAddressArea */
typedef boolean MemAcc_UseEraseBurstOfSubAddressAreaType;

/**   \brief  value based type definition for MemAcc_UseWriteBurstOfSubAddressArea */
typedef boolean MemAcc_UseWriteBurstOfSubAddressAreaType;

/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  MemAccPCStructTypes  MemAcc Struct Types (PRE_COMPILE)
  \brief  These type definitions are used for structured data representations.
  \{
*/ 
/**   \brief  type used in MemAcc_AddressArea */
typedef struct sMemAcc_AddressAreaType
{
  MemAcc_PriorityOfAddressAreaType PriorityOfAddressArea;
  MemAcc_PriorityBasedIndexOfAddressAreaType PriorityBasedIndexOfAddressArea;
  MemAcc_SubAddressAreaEndIdxOfAddressAreaType SubAddressAreaEndIdxOfAddressArea;  /**< the end index of the 1:n relation pointing to MemAcc_SubAddressArea */
  MemAcc_SubAddressAreaStartIdxOfAddressAreaType SubAddressAreaStartIdxOfAddressArea;  /**< the start index of the 1:n relation pointing to MemAcc_SubAddressArea */
  MemAcc_AddressAreaIdType AddressAreaIdOfAddressArea;
  MemAcc_ErrorNotificationFuncType ErrorNotificationOfAddressArea;
  MemAcc_JobEndNotificationFuncType JobEndNotificationOfAddressArea;
} MemAcc_AddressAreaType;

/**   \brief  type used in MemAcc_CLowerLayer */
typedef struct sMemAcc_CLowerLayerType
{
  const MemAcc_MemBinaryHeaderType* StaticMemBinaryHeaderOfLowerLayer;
} MemAcc_CLowerLayerType;

/**   \brief  type used in MemAcc_GeneralFeatures */
typedef struct sMemAcc_GeneralFeaturesType
{
  MemAcc_DevErrorDetectionOfGeneralFeaturesType DevErrorDetectionOfGeneralFeatures;
  MemAcc_DevErrorReportOfGeneralFeaturesType DevErrorReportOfGeneralFeatures;
} MemAcc_GeneralFeaturesType;

/**   \brief  type used in MemAcc_MemInstance */
typedef struct sMemAcc_MemInstanceType
{
  MemAcc_InstanceIdOfMemInstanceType InstanceIdOfMemInstance;
  MemAcc_HwIdType HardwareIdOfMemInstance;
} MemAcc_MemInstanceType;

/**   \brief  type used in MemAcc_MemSectorBatch */
typedef struct sMemAcc_MemSectorBatchType
{
  MemAcc_EraseBurstSizeOfMemSectorBatchType EraseBurstSizeOfMemSectorBatch;
  MemAcc_EraseSectorSizeOfMemSectorBatchType EraseSectorSizeOfMemSectorBatch;
  MemAcc_MaxReadSizeOfMemSectorBatchType MaxReadSizeOfMemSectorBatch;
  MemAcc_MinReadSizeOfMemSectorBatchType MinReadSizeOfMemSectorBatch;
  MemAcc_WriteBurstSizeOfMemSectorBatchType WriteBurstSizeOfMemSectorBatch;
  MemAcc_WritePageSizeOfMemSectorBatchType WritePageSizeOfMemSectorBatch;
} MemAcc_MemSectorBatchType;

/**   \brief  type used in MemAcc_SubAddressArea */
typedef struct sMemAcc_SubAddressAreaType
{
  MemAcc_LogicalEndAddressOfSubAddressAreaType LogicalEndAddressOfSubAddressArea;
  MemAcc_PhysicalEndAddressOfSubAddressAreaType PhysicalEndAddressOfSubAddressArea;
  MemAcc_PhysicalStartAddressOfSubAddressAreaType PhysicalStartAddressOfSubAddressArea;
  MemAcc_UseEraseBurstOfSubAddressAreaType UseEraseBurstOfSubAddressArea;
  MemAcc_UseWriteBurstOfSubAddressAreaType UseWriteBurstOfSubAddressArea;
  MemAcc_LogicalStartAddressOfSubAddressAreaType LogicalStartAddressOfSubAddressArea;
  MemAcc_LowerLayerIdxOfSubAddressAreaType LowerLayerIdxOfSubAddressArea;  /**< the index of the 1:1 relation pointing to MemAcc_CLowerLayer */
  MemAcc_MemInstanceIdxOfSubAddressAreaType MemInstanceIdxOfSubAddressArea;  /**< the index of the 1:1 relation pointing to MemAcc_MemInstance */
  MemAcc_MemSectorBatchIdxOfSubAddressAreaType MemSectorBatchIdxOfSubAddressArea;  /**< the index of the 1:1 relation pointing to MemAcc_MemSectorBatch */
  MemAcc_NumberOfEraseRetriesOfSubAddressAreaType NumberOfEraseRetriesOfSubAddressArea;
  MemAcc_NumberOfReadRetriesOfSubAddressAreaType NumberOfReadRetriesOfSubAddressArea;
  MemAcc_NumberOfSectorsOfSubAddressAreaType NumberOfSectorsOfSubAddressArea;
  MemAcc_NumberOfWriteRetriesOfSubAddressAreaType NumberOfWriteRetriesOfSubAddressArea;
  MemAcc_SectorOffsetOfSubAddressAreaType SectorOffsetOfSubAddressArea;
  MemAcc_SyncGroupIdOfSubAddressAreaType SyncGroupIdOfSubAddressArea;
  MemAcc_AccessType AccessTypeOfSubAddressArea;
} MemAcc_SubAddressAreaType;

/**   \brief  type used in MemAcc_VLowerLayer */
typedef struct sMemAcc_VLowerLayerType
{
  MemAcc_MemBinaryHeaderType* IndirectDynamicMemBinaryHeaderOfLowerLayer;
} MemAcc_VLowerLayerType;

/** 
  \}
*/ 

/** 
  \defgroup  MemAccPCSymbolicStructTypes  MemAcc Symbolic Struct Types (PRE_COMPILE)
  \brief  These structs are used in unions to have a symbol based data representation style for debugging purposes. These types are not used in the implementation!.
  \{
*/ 
/**   \brief  type to be used as symbolic data element access to MemAcc_VLowerLayer for debugging purposes */
typedef struct MemAcc_VLowerLayerStructSTag
{
  MemAcc_VLowerLayerType Mem_30_LegacyAdapter;
} MemAcc_VLowerLayerStructSType;

/** 
  \}
*/ 

/** 
  \defgroup  MemAccPCUnionIndexAndSymbolTypes  MemAcc Union Index And Symbol Types (PRE_COMPILE)
  \brief  These unions are used to access arrays in an index and symbol based style. This type is for debugging purposes, in the implementation the access over the real array type with raw is always used.
  \{
*/ 
/**   \brief  type to access MemAcc_VLowerLayer in an index and symbol based style for debugging purposes */
typedef union MemAcc_VLowerLayerUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  MemAcc_VLowerLayerType raw[1];
  MemAcc_VLowerLayerStructSType str;
} MemAcc_VLowerLayerUType;

/** 
  \}
*/ 

/** 
  \defgroup  MemAccPCRootPointerTypes  MemAcc Root Pointer Types (PRE_COMPILE)
  \brief  These type definitions are used to point from the config root to symbol instances.
  \{
*/ 
/**   \brief  type used to point to MemAcc_AddressArea */
typedef P2CONST(MemAcc_AddressAreaType, TYPEDEF, MEMACC_CONST) MemAcc_AddressAreaPtrType;

/**   \brief  type used to point to MemAcc_CLowerLayer */
typedef P2CONST(MemAcc_CLowerLayerType, TYPEDEF, MEMACC_CONST) MemAcc_CLowerLayerPtrType;

/**   \brief  type used to point to MemAcc_GeneralFeatures */
typedef P2CONST(MemAcc_GeneralFeaturesType, TYPEDEF, MEMACC_CONST) MemAcc_GeneralFeaturesPtrType;

/**   \brief  type used to point to MemAcc_MemInstance */
typedef P2CONST(MemAcc_MemInstanceType, TYPEDEF, MEMACC_CONST) MemAcc_MemInstancePtrType;

/**   \brief  type used to point to MemAcc_MemSectorBatch */
typedef P2CONST(MemAcc_MemSectorBatchType, TYPEDEF, MEMACC_CONST) MemAcc_MemSectorBatchPtrType;

/**   \brief  type used to point to MemAcc_SubAddressArea */
typedef P2CONST(MemAcc_SubAddressAreaType, TYPEDEF, MEMACC_CONST) MemAcc_SubAddressAreaPtrType;

/**   \brief  type used to point to MemAcc_VLowerLayer */
typedef P2VAR(MemAcc_VLowerLayerType, TYPEDEF, MEMACC_VAR_NO_INIT) MemAcc_VLowerLayerPtrType;

/** 
  \}
*/ 

/** 
  \defgroup  MemAccPCRootValueTypes  MemAcc Root Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value representations in root arrays.
  \{
*/ 
/**   \brief  type used in MemAcc_PCConfig */
typedef struct sMemAcc_PCConfigType
{
  uint8 MemAcc_PCConfigNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} MemAcc_PCConfigType;

typedef MemAcc_PCConfigType MemAcc_ConfigType;  /**< A structure type is present for data in each configuration class. This typedef redefines the probably different name to the specified one. */

/** 
  \}
*/ 


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: SIZEOF DATA TYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: SIZEOF DATA TYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL MULTIBINARY DATA PROTOTYPES
 **********************************************************************************************************************/
 
# define MEMACC_MULTIBINARY_ISMULTIBINARYUSECASE STD_ON  
# define MEMACC_MULTIBINARY_ISMASTERBINARY       STD_ON  
# define MEMACC_MULTIBINARY_ISSATELLITEBINARY    STD_OFF 
# define MEMACC_MULTIBINARY_HASREDIRECTREQUESTS  STD_OFF 

typedef enum
{
  MEMACC_MULTIBINARY_NO_REQUEST = 0u, /*!< No multi binary request. */
  MEMACC_MULTIBINARY_REDIRECT   = 1u, /*!< Redirect job step to master binary. */
  MEMACC_MULTIBINARY_DIRECT     = 2u  /*!< Direct Mem access request for a shared Mem. */
} MemAcc_MultiBinary_PublishedRequestType; /*!< Defines how each SubAddressArea access the Mem. */

# define MEMACC_SINGLEBINARY_USECASE            0x01u                               
# define MEMACC_MULTIBINARY_MASTER_BINARY_ID    0x00u                               
# define MEMACC_MULTIBINARY_TOKEN_STOP_MASK     0x80u                               /*!< 0b 1000 0000 */
# define MEMACC_MULTIBINARY_TOKEN_BINARYID_MASK 0x0Fu                               /*!< 0b 0000 1111 */
# define MEMACC_MULTIBINARY_NR_Of_BINARIES      2u                                  
# define MEMACC_MULTIBINARY_BINARY_ID           MEMACC_MULTIBINARY_MASTER_BINARY_ID /*!< defines my own BinaryId */
# define MEMACC_MULTIBINARY_SYNCGROUPID         0u                                  /*!< defines sync group Id */
# define MEMACC_BINARY_CONFIGURED_USECASE       MEMACC_MULTIBINARY_USECASE          



/*!
 * +----+------+---+---+---+---+---+---+---+
 * |    | 7    | 6 | 5 | 4 | 3 | 2 | 1 | 0 |
 * +----+------+---+---+---+---+---+---+---+
 * | 0b | STOP | reserved  | BinaryId      |
 * +----+------+-----------+---------------+
 */
typedef volatile uint8 MemAcc_MultiBinary_SynchronizationTokenType;

/*!
 * Id of Binary in multi binary usecase.
 *  - ID 0 is Master
 *  - ID 1 .. 15 are Satellites
 */
typedef uint8 MemAcc_MultiBinary_IdType;

/*!
 * AtomicRequestType from a MemAcc_MultiBinary_AccessRequestType
 * This Type represents the MemAcc_MultiBinary_PublishedRequestType enum as 8-Bit Value for atomic read/write access
 */
typedef uint8 MemAcc_MultiBinary_AtomicPublishedRequestType;

typedef uint8 MemAcc_MultiBinary_CounterType; /*!< Counter for detecting updates in shared memory */

typedef struct
{
  volatile MemAcc_MultiBinary_CounterType JobStepRequestCounter; /*!< Counter to track job step request changes. */
  volatile MemAcc_JobType                 JobStepType;           /*!< Job step type to be processed. */
  volatile MemAcc_MemDriverIndexType      MemDriverIndex;        /*!< Mem driver index of the targeted Mem. */
  volatile MemAcc_MemInstanceIdType       MemInstanceId;         /*!< Instance ID of the targeted Mem. */
  volatile MemAcc_AddressType             PhysicalAddress;       /*!< Targeted start address for the job step. */
  volatile MemAcc_LengthType              Length;                /*!< Length of the job step. */
} MemAcc_MultiBinary_RedirectJobStepInfoType; /*!< Information shared by the satellite regarding a redirect job step request. */

typedef struct
{
  volatile MemAcc_MultiBinary_CounterType JobStepResultCounter; /*!< Counter to track job step result changes. */
  volatile MemAcc_MemJobResultType        JobStepResult;        /*!< Job result of the redirect job step request. */
} MemAcc_MultiBinary_RedirectJobStepResultType; /*!< Information shared by the master regarding a redirect job step result. */

typedef struct
{
  const MemAcc_MultiBinary_IdType                        BinaryId;                     /*!< Id of Binary */
  volatile MemAcc_MultiBinary_AtomicPublishedRequestType PublishedRequestType;         /*!< Type of request */
  volatile MemAcc_PriorityOfAddressAreaType              Priority;                     /*!< Priority of the request */
  MemAcc_MultiBinary_RedirectJobStepInfoType* const      RedirectJobStepInfoPtr;       /*!< Pointer to the job step information in case of a redirect job step request. */
  MemAcc_MultiBinary_RedirectJobStepResultType* const    RedirectJobStepResultPtr;     /*!< Pointer to the job step result in case of a redirect job step request. */
  MemAcc_DataType* const                                 RedirectJobStepDataBufferPtr; /*!< Pointer to a data buffer for data transfer in case of a redirect job step request. */
} MemAcc_MultiBinary_AccessRequestType; /*!< Stores satellite intents to enable the master to synchronize memory access. Also manages data transfer for redirect job step requests. */

/***********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 **********************************************************************************************************************/
 
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  MemAcc_AddressArea
**********************************************************************************************************************/
/** 
  \var    MemAcc_AddressArea
  \details
  Element                   Description
  Priority              
  PriorityBasedIndex    
  SubAddressAreaEndIdx      the end index of the 1:n relation pointing to MemAcc_SubAddressArea
  SubAddressAreaStartIdx    the start index of the 1:n relation pointing to MemAcc_SubAddressArea
  AddressAreaId         
  ErrorNotification     
  JobEndNotification    
*/ 
#define MEMACC_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemAcc_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(MemAcc_AddressAreaType, MEMACC_CONST) MemAcc_AddressArea[1];
#define MEMACC_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemAcc_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  MemAcc_CLowerLayer
**********************************************************************************************************************/
/** 
  \var    MemAcc_CLowerLayer
  \details
  Element                  Description
  StaticMemBinaryHeader
*/ 
#define MEMACC_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemAcc_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(MemAcc_CLowerLayerType, MEMACC_CONST) MemAcc_CLowerLayer[1];
#define MEMACC_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemAcc_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  MemAcc_GeneralFeatures
**********************************************************************************************************************/
/** 
  \var    MemAcc_GeneralFeatures
  \details
  Element              Description
  DevErrorDetection
  DevErrorReport   
*/ 
#define MEMACC_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemAcc_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(MemAcc_GeneralFeaturesType, MEMACC_CONST) MemAcc_GeneralFeatures[1];
#define MEMACC_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemAcc_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  MemAcc_MemInstance
**********************************************************************************************************************/
/** 
  \var    MemAcc_MemInstance
  \brief  Stores data related to MemInstance Configuration
  \details
  Element       Description
  InstanceId
  HardwareId
*/ 
#define MEMACC_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemAcc_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(MemAcc_MemInstanceType, MEMACC_CONST) MemAcc_MemInstance[1];
#define MEMACC_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemAcc_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  MemAcc_MemSectorBatch
**********************************************************************************************************************/
/** 
  \var    MemAcc_MemSectorBatch
  \brief  Stores MemSectorBatch sizes for Read/Write/Erase Operations.
  \details
  Element            Description
  EraseBurstSize 
  EraseSectorSize
  MaxReadSize    
  MinReadSize    
  WriteBurstSize 
  WritePageSize  
*/ 
#define MEMACC_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemAcc_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(MemAcc_MemSectorBatchType, MEMACC_CONST) MemAcc_MemSectorBatch[1];
#define MEMACC_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemAcc_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  MemAcc_SubAddressArea
**********************************************************************************************************************/
/** 
  \var    MemAcc_SubAddressArea
  \details
  Element                 Description
  LogicalEndAddress   
  PhysicalEndAddress  
  PhysicalStartAddress
  UseEraseBurst       
  UseWriteBurst       
  LogicalStartAddress 
  LowerLayerIdx           the index of the 1:1 relation pointing to MemAcc_CLowerLayer
  MemInstanceIdx          the index of the 1:1 relation pointing to MemAcc_MemInstance
  MemSectorBatchIdx       the index of the 1:1 relation pointing to MemAcc_MemSectorBatch
  NumberOfEraseRetries
  NumberOfReadRetries 
  NumberOfSectors     
  NumberOfWriteRetries
  SectorOffset        
  SyncGroupId         
  AccessType          
*/ 
#define MEMACC_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemAcc_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(MemAcc_SubAddressAreaType, MEMACC_CONST) MemAcc_SubAddressArea[1];
#define MEMACC_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemAcc_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  MemAcc_VLowerLayer
**********************************************************************************************************************/
/** 
  \var    MemAcc_VLowerLayer
  \details
  Element                           Description
  IndirectDynamicMemBinaryHeader
*/ 
#define MEMACC_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemAcc_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(MemAcc_VLowerLayerUType, MEMACC_VAR_NO_INIT) MemAcc_VLowerLayer;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define MEMACC_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemAcc_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/
 
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/


#define MEMACC_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
/* lint -save -esym(961, 19.1) */
#include "MemAcc_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/* lint -restore */

extern MemAcc_MultiBinary_SynchronizationTokenType MemAcc_MultiBinary_SynchronizationToken;

extern MemAcc_MultiBinary_AccessRequestType MemAcc_MultiBinary_AccessRequestSatellite_Id1;

#define MEMACC_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
/* lint -save -esym(961, 19.1) */
#include "MemAcc_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/* lint -restore */

#define MEMACC_START_SEC_VAR_INIT_UNSPECIFIED
/* lint -save -esym(961, 19.1) */
#include "MemAcc_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/* lint -restore */

extern MemAcc_MultiBinary_AccessRequestType MemAcc_MultiBinary_AccessRequestMaster_Id0;

extern MemAcc_MultiBinary_SynchronizationTokenType* const MemAcc_MultiBinary_SynchronizationTokenPtr;

extern MemAcc_MultiBinary_AccessRequestType* const MemAcc_MultiBinary_AccessRequestPtr;

extern MemAcc_MultiBinary_AccessRequestType* const MemAcc_MultiBinary_AccessRequests[MEMACC_MULTIBINARY_NR_Of_BINARIES];

#define MEMACC_STOP_SEC_VAR_INIT_UNSPECIFIED
/* lint -save -esym(961, 19.1) */
#include "MemAcc_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/* lint -restore */

#endif /* MEMACC_CFG_H */
/**********************************************************************************************************************
  END OF FILE: MemAcc_Cfg.h
**********************************************************************************************************************/

