/******************************************************************************/
/* @F_NAME :          fblm_priv.h                                             */
/* @F_PURPOSE :       private data/function of module                         */
/* @F_CREATED_BY :    Jianhua.Wu  			                                  */
/* @F_CREATION_DATE : 2021.07.14                                              */
/* @F_LANGUAGE :      ANSI C                                                  */
/* @F_MPROC_TYPE :    target independent           						      */
/*************************************** (C) Copyright 2021 Marelli ***********/

#ifndef __FBLM_PRIVATE_H_
#define __FBLM_PRIVATE_H_

/*______ I N C L U D E - F I L E S ___________________________________________*/
#include "fblm_diag.h"

/*______ P R I V A T E - DATA - P R O T O T Y P E S __________________________*/
extern ubyte WDInitFlag;
extern FBLM_UpdateMode_t Fblm_UpdateMode;
extern ubyte  diagResponseFlag;
extern ushort testerPresentTimeout;
extern ubyte diagErrorCode;
extern ushort fblStates;
extern BlockEraseFlag fblm_EraseFlag;
extern ubyte flashState;
extern uint8 AES_Seed[16];
extern uint8 lastAES_Seed[16];/*store last seed*/
extern ubyte securitySeedResponse;
extern ushort DiagDataLength;
extern ubyte *DiagBuffer;
// extern ubyte Info_Array[FlashDrv_BlockSize];
extern ubyte ActiveLogicBlock;
extern volatile const SYST_SwIdentifier_t M0AppHeader;
extern ubyte Fblm_BootMangerRunningSts;
extern ubyte Fblm_BmNeedToJumpApp;

extern boolean FblInitDone;

#ifdef FBLM_DIAG_USE_NVM
extern Fblm_NvmWriteResult_t Fblm_NvmWriteResult;
extern Fblm_NvmWriteReq_t Fblm_NvmWriteReqInternal;
extern uint16 Fblm_NvmTimeoutCounter;
extern Fblm_NvmProcessState_t Fblm_NvmProcessState;
#endif /* FBLM_DIAG_USE_NVM */
/*______ P R I V A T E - D E F I N E S _______________________________________*/
/* Define return code of several functions */
#define kFblOk                ((ubyte) 0x00u)  /*compare to IO_E_OK*/
#define kFblFailed            ((ubyte) 0x01u)
/* -- Special return code for ApplFblWriteDataByIdentifier */
#define kDiagReturnValidationOk ((ubyte) 0x5Cu)

/* Transfer types (used with transferType) */
#define DOWNLOAD_INIT            ((ubyte) 0x00u)
#define DOWNLOAD_RAM             ((ubyte) 0x10u)
#define DOWNLOAD_FLASH           ((ubyte) 0x40u)
#define DOWNLOAD_FLASHDRVSHA     ((ubyte) 0x80u)
#define DOWNLOAD_APPSHA          ((ubyte) 0x81u)
#define DOWNLOAD_SWP1            ((ubyte) 0x82u)
#define DOWNLOAD_SWP1SHA         ((ubyte) 0x83u)

#define kDiagNoResponse          ((ubyte) 0x00)
#define kDiagPutResponse         ((ubyte) 0x01)

#define kDiagInitSequenceNum     ((ubyte) 0x01)

/* Sequence counter retry init number */
#if !defined(kDiagInitDataRetries)
#define kDiagInitDataRetries  ((ubyte) 0x03u)
#endif

/* Parameters for busy response handling function */
#define kNotForceSendResponsePending         ((ubyte) 0x00u)
#define kForceSendResponsePending            ((ubyte) 0x01u)

/* Reset type for function FblDiagEcuReset() */
#define kDiagResetNoResponse                 ((ubyte) 0x00u)
#define kDiagResetPutResponse                ((ubyte) 0x01u)

#define DiagSetNoResponse()      (diagResponseFlag = kDiagNoResponse)
#define DiagSetPutResponse()     (diagResponseFlag = kDiagPutResponse)

#define Fblm_SetBootInitDone()   (FblInitDone = TRUE)
#define Fblm_GetBootInitDone()	 (FblInitDone)	    


/*UDS response handle*/
#define DiagProcessingDone(len)   DiagResponseProcessor(len)


#define TimeoutTesterValue()     testerPresentTimeout
#define DecTimeoutTesterValue()  (testerPresentTimeout--)
#define ResetTesterTimeout()     (testerPresentTimeout = (ushort)(TESTER_PRESENT_TIMEOUT/DIAG_CALL_CYCLE))
#define InitTesterTimeoutLong()  (testerPresentTimeout = (ushort)(TESTER_PRESENT_TIMEOUT_LONG/DIAG_CALL_CYCLE))
#define StopTesterTimeout()      (testerPresentTimeout = 0)

/* Security seed response status defines,already request for seed or not */
#define kSeedAlreadyRequested               ((ubyte)0x00u)
#define kNewSeedRequest                     ((ubyte)0x01u)
#if defined( FBL_ENABLE_SEC_ACCESS_DELAY )
/* Macros for security access delay */
#define SetSecurityAccessDelay()       (secSecurityAccessDelay = \
                                       (ulong)(kSecSecurityAccessDelay))
#define GetSecurityAccessDelay()       (secSecurityAccessDelay)
#define DecSecurityAccessDelay()       (secSecurityAccessDelay--)
#define ClrSecurityAccessDelay()       (secSecurityAccessDelay = 0)
#endif /* FBL_ENABLE_SEC_ACCESS_DELAY */



#define FBL_FrameCounterOffset               ((ubyte)(0x00u))
#define FBL_DataLengthHiOffset               ((ubyte)(0x01u))
#define FBL_DataLengthLoOffset               ((ubyte)(0x02u))
#define FBL_ServiceIDOffset                  ((ubyte)(0x03u))

/* -- Defines of diag services SID-- */
#define kDiagSidDiagnosticSessionControl                 ((ubyte) 0x10u)
#define kDiagSidEcuReset                                 ((ubyte) 0x11u)
#define kDiagSidReadDataByIdentifier                     ((ubyte) 0x22u)
#define kDiagSidSecurityAccess                           ((ubyte) 0x27u)
#define kDiagSidCommunicationControl                     ((ubyte) 0x28u)
#define kDiagSidWriteDataByIdentifier                    ((ubyte) 0x2Eu)
#define kDiagSidRoutineControl                           ((ubyte) 0x31u)
#define kDiagSidRequestDownload                          ((ubyte) 0x34u)
#define kDiagSidTransferData                             ((ubyte) 0x36u)
#define kDiagSidRequestTransferExit                      ((ubyte) 0x37u)
#define kDiagSidTesterPresent                            ((ubyte) 0x3Eu)
#define kDiagSidControlDTCSetting                        ((ubyte) 0x85u)

/* DiagnosticSessionControl */
#define kDiagSubDefaultSession                           ((ubyte) 0x01u)
#define kDiagSubProgrammingSession                       ((ubyte) 0x02u)
#define kDiagSubExtendedDiagSession                      ((ubyte) 0x03u)

/* ECUReset */
#define kDiagSubHardReset                                ((ubyte) 0x01u)
#define kDiagSubSoftReset                                ((ubyte) 0x03u)


/* ControlDTCSetting */
#define kDiagSubDtcOn                                    ((ubyte) 0x01u)
#define kDiagSubDtcOff                                   ((ubyte) 0x02u)

/* CommunicationControl */
#define kDiagSubEnableRxAndTx                            ((ubyte) 0x00u)
#define kDiagSubEnableRxAndDisableTx                     ((ubyte) 0x01u)
#define kDiagSubNormalCommunication                      ((ubyte) 0x01u)

/* RoutineControl, routineControlType */
#define kDiagSubStartRoutine                             ((ubyte) 0x01u)
#define kDiagSubStopRoutine                              ((ubyte) 0x02u)
#define kDiagSubRequestRoutineResult                     ((ubyte) 0x03u)

#ifndef kDiagWriteRepairShopCode
#define kDiagWriteRepairShopCode    ((ushort) 0xF198u)
#endif

#ifndef kDiagWriteProgrammingData
#define kDiagWriteProgrammingData    ((ushort) 0xF199u)
#endif

#if !defined(kDiagWriteFingerprint)
#define kDiagWriteFingerprint       ((ushort) 0xF15Au)
#endif

#if !defined(kDiagWriteBootFingerprint)
#define kDiagWriteBootFingerprint       ((ushort) 0xF183u)
#endif

#if !defined(kDiagWriteAppSoftwareFingerprint)
#define kDiagWriteAppSoftwareFingerprint       ((ushort) 0xF184u)
#endif

#if !defined(kDiagWriteAppDataFingerprint)
#define kDiagWriteAppDataFingerprint       ((ushort) 0xF185u)
#endif


#if !defined(kDiagSubSecTypeMask)
# define kDiagSubSecTypeMask         ((ubyte) 0x7Fu)
#endif
/* Macros for security access */
#if !defined(kDiagSubRequestSeed)
# define kDiagSubRequestSeed         ((ubyte) 0x01u)
#endif

#if !defined(kDiagSubSendKey)
# define kDiagSubSendKey             ((ubyte) 0x02u)
#endif

#if !defined(kSecSeedLength)
# define kSecSeedLength              ((ubyte) 0x10u)
#endif

#if !defined(kSecKeyLength)
# define kSecKeyLength               kSecSeedLength
#endif


/* RoutineControl, RoutineIdentifier */
#define kDiagRoutineIdDisableFailSafeReactionPreCond     ((ushort) 0xD001u)
#define kDiagRoutineIdCheckProgPreCond                   ((ushort) 0x0206u)
#define kDiagRoutineIdEraseMemory                        ((ushort) 0xFF00u)
#define kDiagRoutineIdChecksum                           ((ushort) 0x0212u)
#define kDiagRoutineIdCheckProg                          ((ushort) 0xFF01u)
#define kDiagRoutineIdCheckProgDep                       ((ushort) 0x0205u)
#define kDiagRoutineIdWriteProgramFlag                   ((ushort) 0x5801u)
#define kDiagRoutineIdEraseProgramFlag                   ((ushort) 0x5803u)

#define kDiagRoutineIdBootBlockHash                      ((ushort) 0xD000u)
#define kDiagRoutineIdApplicationSoftBlockHash           ((ushort) 0xD003u)
#define kDiagRoutineIdApplicationDataBlockHash           ((ushort) 0xD004u)
#define kDiagRoutineIdActiveSbl                          ((ushort) 0x0301u)

/* -- Response Identifier -- */
/* Negative response SID */
#define kDiagRidNegativeResponse                         ((ubyte) 0x7Fu)

/* -- Negative Response Codes -- */
#define kDiagErrorNone                                   ((ubyte) 0x00u)
#define kDiagNrcGeneralReject                            ((ubyte) 0x10u)
#define kDiagNrcServiceNotSupported                      ((ubyte) 0x11u)
#define kDiagNrcSubFunctionNotSupported                  ((ubyte) 0x12u)
#define kDiagNrcIncorrectMessageLengthOrInvalidFormat    ((ubyte) 0x13u)
#define kDiagNrcBusyRepeatRequest                        ((ubyte) 0x21u)
#define kDiagNrcConditionsNotCorrect                     ((ubyte) 0x22u)
#define kDiagNrcRequestSequenceError                     ((ubyte) 0x24u)
#define kDiagNrcRequestOutOfRange                        ((ubyte) 0x31u)
#define kDiagNrcSecurityAccessDenied                     ((ubyte) 0x33u)
#define kDiagNrcInvalidKey                               ((ubyte) 0x35u)
#define kDiagNrcExceedNumberOfAttempts                   ((ubyte) 0x36u)
#define kDiagNrcRequiredTimeDelayNotExpired              ((ubyte) 0x37u)
#define kDiagNrcUploadDownloadNotAccepted                ((ubyte) 0x70u)
#define kDiagNrcTransferDataSuspended                    ((ubyte) 0x71u)
#define kDiagNrcGeneralProgrammingFailure                ((ubyte) 0x72u)
#define kDiagNrcWrongBlockSequenceCounter                ((ubyte) 0x73u)
#define kDiagNrcRcrResponsePending                       ((ubyte) 0x78u)
#define kDiagNrcSubfunctionNotSupportedInActiveSession   ((ubyte) 0x7Eu)
#define kDiagNrcServiceNotSupportedInActiveSession       ((ubyte) 0x7Fu)

/* RoutineControl response codes */
#define kDiagCheckVerificationOk                ((ubyte) 0x00u)
#define kDiagCheckVerificationFailed            ((ubyte) 0x02u)

/* -- Makros for diag exceptions -- */
#define DiagSetError(errorNo)                            (diagErrorCode = (errorNo))
#define DiagClrError()                                   (diagErrorCode = kDiagErrorNone)
#define DiagGetError()                                   (diagErrorCode)
#define DiagNRCGeneralReject()                           DiagSetError(kDiagNrcGeneralReject)
#define DiagNRCServiceNotSupported()                     DiagSetError(kDiagNrcServiceNotSupported)
#define DiagNRCSubFunctionNotSupported()                 DiagSetError(kDiagNrcSubFunctionNotSupported)
#define DiagNRCIncorrectMessageLengthOrInvalidFormat()   DiagSetError(kDiagNrcIncorrectMessageLengthOrInvalidFormat)
#define DiagNRCBusyRepeatRequest()                       DiagSetError(kDiagNrcBusyRepeatRequest)
#define DiagNRCConditionsNotCorrect()                    DiagSetError(kDiagNrcConditionsNotCorrect)
#define DiagNRCRequestSequenceError()                    DiagSetError(kDiagNrcRequestSequenceError)
#define DiagNRCRequestOutOfRange()                       DiagSetError(kDiagNrcRequestOutOfRange)
#define DiagNRCSecurityAccessDenied()                    DiagSetError(kDiagNrcSecurityAccessDenied)
#define DiagNRCInvalidKey()                              DiagSetError(kDiagNrcInvalidKey)
#define DiagNRCExceedNumberOfAttempts()                  DiagSetError(kDiagNrcExceedNumberOfAttempts)
#define DiagNRCRequiredTimeDelayNotExpired()             DiagSetError(kDiagNrcRequiredTimeDelayNotExpired)
#define DiagNRCUploadDownloadNotAccepted()               DiagSetError(kDiagNrcUploadDownloadNotAccepted)
#define DiagNRCTransferDataSuspended()                   DiagSetError(kDiagNrcTransferDataSuspended)
#define DiagNRCGeneralProgrammingFailure()               DiagSetError(kDiagNrcGeneralProgrammingFailure)
#define DiagNRCWrongBlockSequenceCounter()               DiagSetError(kDiagNrcWrongBlockSequenceCounter)
#define DiagNRCRcrResponsePending()                      DiagSetError(kDiagNrcRcrResponsePending)
#define DiagNRCSubfunctionNotSupportedInActiveSession()  DiagSetError(kDiagNrcSubfunctionNotSupportedInActiveSession)
#define DiagNRCServiceNotSupportedInActiveSession()      DiagSetError(kDiagNrcServiceNotSupportedInActiveSession)


/* Diagnostic service format definitions */
#define kDiagFmtSequenceCnt      ((ubyte) (kDiagFmtServiceId+1))     /* Position of sequence counter */
#define kDiagFmtDataOffset       ((ubyte) (kDiagFmtSequenceCnt+1))   /* Offset to download data in TransferData frame */
#define kDiagFmtSeedKeyStart     ((ubyte) (kDiagFmtSubparam+1))      /* Start index of seed/key value */
#define kDiagFmtAddrOffset       ((ubyte) 0x03u)
#define kDiagFmtFormatOffset     ((ubyte) 0x02u)
#define kDiagFmtServiceId           ((ubyte) 0x00u)
#define kDiagFmtSubparam            ((ubyte) (kDiagFmtServiceId+1))
#define kDiagFmtRoutineIdHigh       ((ubyte) (kDiagFmtServiceId+1))
#define kDiagFmtRoutineIdLow        ((ubyte) (kDiagFmtRoutineIdHigh+1))
#define kDiagFmtRoutineIdPar        ((ubyte) (kDiagFmtRoutineIdLow+1))
#define kDiagFmtRoutineIdDataRecord ((ubyte) (kDiagFmtRoutineIdPar+1))
#define kDiagFmtSubRoutineIdHigh    ((ubyte) (kDiagFmtSubparam+1))
#define kDiagFmtSubRoutineIdLow     ((ubyte) (kDiagFmtSubRoutineIdHigh+1))
#define kDiagFmtSubRoutineIdPar     ((ubyte) (kDiagFmtSubRoutineIdLow+1))
#define kDiagFmtSubRoutineIdDataRecord    ((ubyte) (kDiagFmtSubRoutineIdPar+1))
#define kDiagFmtSubRoutineIdDataRecord2    ((ubyte) (kDiagFmtSubRoutineIdDataRecord+1))
#define kDiagFmtSubRoutineIdDataRecord3    ((ubyte) (kDiagFmtSubRoutineIdDataRecord2+1))
#define kDiagFmtSubRoutineIdDataRecord4    ((ubyte) (kDiagFmtSubRoutineIdDataRecord3+1))

#define kDiagFmtShortRoutineId      ((ubyte) (kDiagFmtSubparam+1))
#define kDiagFmtShortRoutineIdPar   ((ubyte) (kDiagFmtShortRoutineId+1))
#define kDiagFmtShortRoutineIdDataRecord  ((ubyte) (kDiagFmtShortRoutineIdPar+1))
#define kDiagFmtNegResponse         ((ubyte) (kDiagFmtSubparam+1))      /* Position of negative response code */

/*define Response length*/
#define kDiagRoutineIdCheckProgDepRespLength                     8



/* -- Defines for additional length codes for optional request parameters -- */
/* -- only if applicable; excluding the Service-ID.                       -- */
# define kSecKeyLength               kSecSeedLength
#define kDiagRqlDiagnosticSessionControlParameter           ((ubyte) 0x00u)
#define kDiagRqlSecurityAccessSeedParameter                 ((ubyte) 0x00u)
#define kDiagRqlSecurityAccessKeyParameter                  kSecKeyLength
#define kDiagRqlWriteDataByIdentifierFingerPrintParameter   ((ubyte) 0x0Eu)
#define kDiagRqlWriteDataByIdentiTesterNumberParameter      ((ubyte) 0x10u)
#define kDiagRqlWriteDataByIdentifierFingerProgDate         ((ubyte) 0x04u)
#define kDiagRqlRoutineControlAddrAndLenFormatIdParameter   ((ubyte) 0x00u)
#define kDiagRqlRequestTransferExitParameter                ((ubyte) 0x00u)
#define kDiagRqlControlDTCSettingParameter                  ((ubyte) 0x03u)

#define kDiagRqlDataByIdentifierVersionPrintParameter   ((ubyte) 0x03u)
#define kDiagRqlDataByIdentifierFingerPrintParameter   ((ubyte) 0x0Eu)

#define kDiagRqlDataByIdentifierSystemIdentificationDataPrintParameter        ((ubyte) 0x5Au)
#define kDiagRqlWriteDataByIdentifierPublicKeyParameter                       ((ushort) 292u)
#define kDiagPublicKeySpareAndCheckParameterLength                            ((ushort) 4u)
#define kDiagPublicKeyValidDataLength                                         ((ushort) 260u)
#define kDiagRqlReadDataByIdentifierPublicKeyParameter                        ((ushort) 32u)

#define kDiagRqlDataByIdentifierSecurityConstantLevelParameter           ((ubyte) 16u)
#define kDiagRqlDataByIdentifierEcuSerialNumParameter          ((ubyte) 4u)

/* -- Defines length of service request         -- */
/* -- (if applicable; excluding the Service-ID. -- */
#define kDiagRqlServiceSubfunction                 ((ubyte)  0x01u)
#define kDiagRqlDiagnosticSessionControl           ((ubyte) (0x01u+kDiagRqlDiagnosticSessionControlParameter))
#define kDiagRqlEcuReset                           ((ubyte)  0x01u)
#define kDiagRqlSecurityAccessSeed                 ((ubyte) (0x01u+kDiagRqlSecurityAccessSeedParameter))
#define kDiagRqlSecurityAccessKey                  ((ubyte) (0x01u+kDiagRqlSecurityAccessKeyParameter))
#define kDiagRqlCommunicationControl               ((ubyte)  0x02u)
#define kDiagRqlReadDataByIdentifier               ((ubyte)  0x02u)
#define kDiagRqlWriteDataByIdentifier              ((ubyte)  0x02u)
#define kDiagRqlWriteDataByIdentifierFingerPrint   ((ubyte) (kDiagRqlWriteDataByIdentifier+kDiagRqlWriteDataByIdentifierFingerPrintParameter))
#define kDiagRqlWriteDataByIdentiTesterNumber      ((ubyte) (kDiagRqlWriteDataByIdentifier+kDiagRqlWriteDataByIdentiTesterNumberParameter))
#define kDiagRqlWriteDataByIdentiProgDate          ((ubyte) (kDiagRqlWriteDataByIdentifier+kDiagRqlWriteDataByIdentifierFingerProgDate))
#define kDiagRqlRoutineControl                     ((ubyte)  0x03u)
#define kDiagRqlRoutineCheckRoutineDataLen         ((ushort)  256u)
#define kDiagRqlRoutineControlEraseRoutine         ((ubyte) (kDiagRqlRoutineControl+kDiagRqlRoutineControlAddrAndLenFormatIdParameter))
#define kDiagRqlRoutineControlCheckRoutine        ((ushort) (kDiagRqlRoutineControl + kDiagRqlRoutineCheckRoutineDataLen))
#define kDiagRqlRoutineControlCheckProg            ((ubyte) (kDiagRqlRoutineControl))
#define kDiagRqlRoutineControlCheckProgDep         ((ubyte) (kDiagRqlRoutineControl))
#define kDiagRqlRoutineControlCheckProgPreCond     ((ubyte) (kDiagRqlRoutineControl))
#define kDiagRqlRoutineControlActiveSbl            ((ubyte) (kDiagRqlRoutineControl) + 4)

#define kDiagRqlDataByIdentifierVersionPrintParameterPrint   ((ubyte) (kDiagRqlWriteDataByIdentifier+kDiagRqlDataByIdentifierVersionPrintParameter))
#define kDiagRqlDataByIdentifierFingerPrintParameterPrint   ((ubyte) (kDiagRqlWriteDataByIdentifier+kDiagRqlDataByIdentifierFingerPrintParameter))
#define kDiagRqlDataByIdentifierSystemIdentificationDataPrint   ((ubyte) (kDiagRqlWriteDataByIdentifier+kDiagRqlDataByIdentifierSystemIdentificationDataPrintParameter))
#define kDiagRqlWriteDataByIdentifierPublicKey         ((ushort) (kDiagRqlWriteDataByIdentifier+kDiagRqlWriteDataByIdentifierPublicKeyParameter))
#define kDiagRqlWriteDataByIdentifierTotalPublicKey         ((ushort) (kDiagRqlWriteDataByIdentifierPublicKeyParameter+ kDiagPublicKeySpareAndCheckParameterLength))
#define kDiagRqlReadDataByIdentifierPublicKey         ((ushort) (kDiagRqlWriteDataByIdentifier+kDiagRqlReadDataByIdentifierPublicKeyParameter))

#define kDiagRqlDataByIdentifierSecurityConstantLevel         ((ubyte) (kDiagRqlWriteDataByIdentifier+kDiagRqlDataByIdentifierSecurityConstantLevelParameter))
#define kDiagRqlDataByIdentifierEcuSerialNum        ((ubyte) (kDiagRqlWriteDataByIdentifier+kDiagRqlDataByIdentifierEcuSerialNumParameter ))

#define kDiagRqlRequestDownload                    ((ubyte)  0x02u)
#define kDiagRqlTransferData                       ((ubyte)  0x02u) /* + Download data, at least one data byte mandatory */
#define kDiagRqlRequestTransferExit                ((ubyte) (0x00u+kDiagRqlRequestTransferExitParameter))
#define kDiagRqlTesterPresent                      ((ubyte) 0x01u)
#define kDiagRqlControlDTCSetting                  ((ubyte) (0x01u+kDiagRqlControlDTCSettingParameter))


/* -- Defines for additional length codes for optional response parameters -- */
/* -- only if applicable; excluding the Service-ID.                        -- */
#define kDiagRslEcuResetParameter                           ((ubyte) 0x00u)
#define kDiagRslDiagnosticSessionControlParameter           ((ubyte) 0x04u)
#define kDiagRslSecurityAccessSeedParameter                 kSecSeedLength
#define kDiagRslSecurityAccessKeyParameter                  ((ubyte) 0x00u)
#define kDiagRslRoutineControlEraseRoutineParameter         ((ubyte) 0x01u)
#define kDiagRslRoutineControlCheckRoutineParameter         ((ubyte) 0x01u)
#define kDiagRslRoutineControlCheckPreCondParameter         ((ubyte) 0x02u)
#define kDiagRslRoutineControlApplicationSoftBlockHashParameter         ((ubyte) 0x02u)
#define kDiagRslRoutineControlDisableFailSafeReactionRoutinParameter  ((ubyte) 0x02u)
#define kDiagRslRoutineControlWriteProFlagParameter         ((ubyte) 0x01u)
#define kDiagRslRoutineControlEraseProFlagParameter         ((ubyte) 0x01u)
#define kDiagRslTransferDataParameter                       ((ubyte) 0x00u)
#define kDiagRslRequestTransferExitParameter                ((ubyte) 0x00u)


/* -- Defines for response length codes         -- */
/* -- (if applicable; excluding the Service-ID. -- */
#define kDiagRslDiagnosticSessionControl           ((ubyte) (0x01u+kDiagRslDiagnosticSessionControlParameter))
#define kDiagRslEcuReset                           ((ubyte) (0x01u+kDiagRslEcuResetParameter))
#define kDiagRslSecurityAccessSeed                 ((ubyte) (0x01u+kDiagRslSecurityAccessSeedParameter))
#define kDiagRslSecurityAccessKey                  ((ubyte) (0x01u+kDiagRslSecurityAccessKeyParameter))
#define kDiagRslCommunicationControl               ((ubyte)  0x01u)
#define kDiagRslWriteDataByIdentifier              ((ubyte)  0x02u)
#define kDiagRslRoutineControlEraseRoutine         ((ubyte) (0x03u/*+kDiagRslRoutineControlEraseRoutineParameter*/))
#define kDiagRslRoutineControlCheckRoutine         ((ubyte) (0x04u))
#define kDiagRslRoutineControlCheckSumLength        ((ubyte) kDiagRslRoutineControlCheckRoutine + kDiagRslRoutineControlCheckRoutineParameter)
#define kDiagRslRoutineControlApplicationSoftBlockHash ((ubyte) (0x02u+kDiagRslRoutineControlApplicationSoftBlockHashParameter))
#define kDiagRslRoutineControlDisableFailSafeReactionRoutine  ((ubyte) (0x01u+kDiagRslRoutineControlDisableFailSafeReactionRoutinParameter))
#define kDiagRslRoutineControlCheckPreCond         ((ubyte) (0x03u+kDiagRslRoutineControlCheckPreCondParameter))
#define kDiagRslRoutineControlWriteProFlag         ((ubyte) (0x03u+kDiagRslRoutineControlWriteProFlagParameter))
#define kDiagRslRoutineControlEraseProFlag         ((ubyte) (0x03u+kDiagRslRoutineControlEraseProFlagParameter))
#define kDiagRslRoutineControlActiveSblRoutine     ((ubyte) (0x04u))
#define kDiagRslRequestDownload                    ((ubyte)  0x01u) /* + maxNumberOfBlockLength */
#define kDiagRslTransferData                       ((ubyte) (0x01u+kDiagRslTransferDataParameter))
#define kDiagRslRequestTransferExit                ((ubyte) (0x00u+kDiagRslRequestTransferExitParameter))
#define kDiagRslTesterPresent                      ((ubyte)  0x01u)
#define kDiagRslControlDTCSetting                  ((ubyte)  0x01u)



/*______ P R I V A T E - T Y P E S ___________________________________________*/
typedef ulong FBL_ADDR_TYPE;
typedef ulong FBL_MEMSIZE_TYPE;
typedef ulong tMtabAddress;
typedef ulong tMtabLength;

typedef struct {
	ushort   did;
	ushort   maxSize;/*Response length,exclude SID*/
} tDid;
typedef struct {
	ubyte sID;
	ushort allowedSessions;
} tSessionMngmntTbl;
/* Entry type of logical block table */
typedef struct tBlockDescriptor
{
	//ubyte blockNr;  //to do does not need this                		/* Number of logical block*/
	ubyte blockIndex;			    		/*Index*/
	tMtabAddress blockStartAddress;        /* Start address of current block */
	tMtabLength blockLength;              /* Block length in bytes */
    ushort maxProgAttempts;        		 /* Maximum number of reprogramming attempts */
} tBlockDescriptor;

/* The logical block table describes the memory layout of logical blocks. */
typedef struct tLogicalBlockTable
{
   ubyte noOfBlocks;  /* Number of configured logical blocks(logical blocks that bootloader need to refresh) */
   tBlockDescriptor  logicalBlock[FBL_MTAB_NO_OF_BLOCKS];
} tLogicalBlockTable;

/*______ P R I V A T E - D A T A _____________________________________________*/

/*______ P R I V A T E - M A C R O S _________________________________________*/

/*______ P R I V A T E - F U N C T I O N S - P R O T O T Y P E S _____________*/
extern void JUMP_TO_APPLICATION(void);
/*fblm_main.c*/
extern void Fblm_Init(void);

/*fblm_diag.c*/
extern void Fblm_DiagInit(void);
extern ubyte Fblm_DiagCheckAddressing(ubyte serviceID);
extern void DiagResponseProcessor(ushort dataLength);
extern void FblIMCTransmit(ubyte *DiagResponseBufferPtr,ushort dataLength);
extern void Fblm_RetransmitRcrRp(void);
extern ubyte FblDiagCheckSession( ubyte serviceID );
extern void Fblm_DiagDiagnosticSessionControl(void);
extern void Fblm_DiagEcuReset(ubyte response);
extern void Fblm_DiagReadDataByIdentifier(void);
extern void Fblm_DiagSecurityAccess(void);
extern void Fblm_DiagWriteDataByIdentifier(void);
extern void Fblm_DiagCommunicationControl(void);

extern void Fblm_DiagTesterPresent(void);
extern void Fblm_DiagRoutineControl(void);
extern void Fblm_DiagRequestDownload(void);
extern void Fblm_DiagTransferDownload(void);
extern void Fblm_DiagRequestTransferExit(void);
extern void Fblm_DiagControlDTCSetting(void);
extern void FblDiagInitStartFromAppl(void);
extern ubyte Fblm_GetTransferType(void);
extern ulong Fblm_GetTimerValue(void);
extern ulong Fblm_GptGetTimeElapsed(void);

/*fblm_config.c*/
#if defined(IMC_FUN_ENABLE)
extern bool_t Fblm_IsIMCTaskNextRun(void);
#endif
extern void Fblm_SPIRunnable(void);
extern void Fblm_CANRunnable(void);
extern void Fblm_PreInit(void);
extern void Fblm_OtherModuleInit(void);
extern ubyte Fblm_IsExistProgRequest(void);
extern ubyte Fblm_IsApplicationValid(void);
extern ubyte Fblm_IsMemoryProtectedArea(ulong address,ulong size);
extern void Fblm_ReadDataByIdentifier(ubyte *pbDiagData, ushort diagReqDataLen);
extern ubyte Fblm_WriteDataByIdentifier(ubyte *pbDiagData, ushort diagReqDataLen);
extern ubyte Fblm_GenerateSecuritySeed(void);
extern ubyte Fblm_SecurityVerifyKey(void);
extern void Fblm_DownloadCheck(ushort verDataIndex);
extern ubyte Fblm_EraseRoutine(ulong StartAddress,ulong MemorySize);
extern ubyte Fblm_WriteFlash(ulong StartAddress,ubyte* StoreData,ulong MemoryLength);
extern ubyte Fblm_CheckProgConditions(void);
extern ubyte Fblm_CheckProgDependencies(void);
extern ubyte Fblm_CheckValidAddressRange(ulong StartAddress,ulong MemorySize);
extern FBL_MEMSIZE_TYPE Fblm_GetInteger(ubyte count, const ubyte* buffer);
extern ubyte Fblm_CanMsgTransmitted(void);
extern void Fblm_SetUpdateMode(FBLM_UpdateMode_t mode);
extern FBLM_UpdateMode_t Fblm_GetUpdateMode(void);
extern void DiagExRCRResponsePending(ubyte forceSend);
extern void Fblm_SyncNvMTask(void);
extern void Fblm_AsyncWriteNvmTask(void);

extern boolean Fblm_ReadWriteNvmBlockStatus(void);
#ifdef FBLM_DIAG_USE_NVM
extern boolean Fblm_NvmWriteReq(NvM_BlockIdType BlockId, uint8 *pData);
extern Fblm_NvmWriteResult_t Fblm_GetNvmWriteResult(void);
#endif /* FBLM_DIAG_USE_NVM */
#endif /* __FBLM_PRIVATE_H_ */
