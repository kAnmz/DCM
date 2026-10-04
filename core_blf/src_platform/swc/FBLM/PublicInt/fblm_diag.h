/******************************************************************************/
/* @F_NAME :          fblm_diag.h                                             */
/* @F_PURPOSE :       manage diag for MCU bootloader                          */
/* @F_CREATED_BY :    Jianhua.Wu  			                                  */
/* @F_CREATION_DATE : 2021.07.14                                              */
/* @F_LANGUAGE :      ANSI C                                                  */
/* @F_MPROC_TYPE :    target independent           						      */
/*************************************** (C) Copyright 2021 Marelli ***********/

#ifndef _FBLM_DIAG_H_
#define _FBLM_DIAG_H_

/*______ I N C L U D E - F I L E S ___________________________________________*/
#include"fblm_config.h"
/*______ G L O B A L - D E F I N E S _________________________________________*/

# define kDiagBufferAlign ((ubyte) 0x04u)/*C_CPUTYPE_32BIT*/


#define FBLM_MAX_DID_COUNT  ((ubyte) 8u)

/* request message definition */
#define kFbldataFormatId               ((ubyte)0x00u)
#define kFbladdressAndLengthFormatId   ((ubyte)0x44u)

/* Macros for watchdog initialization */
#define GetWDInit()        (WDInitFlag == 0x01u)
#define SetWDInit()        (WDInitFlag = 0x01u)
#define ClrWDInit()        (WDInitFlag = 0x00u)

/* Macros for multiple purpose timer */
#define GetP2Timer()       (P2Timer)
#define SetP2Timer(val)    (P2Timer = (val))
#define ClrP2Timer()       (P2Timer = 0x00u)
#define DecP2Timer()       (P2Timer --)/*where do --,if timer=0,send pending?*/

/* Macros and values for fblMode */
#define START_FROM_APPL          FBL_BIT0
#define START_FROM_RESET         FBL_BIT1
#define APPL_CORRUPT             FBL_BIT2
#define STAY_IN_FLASHER          FBL_BIT3

#define SetFblMode(state)        (fblMode = (ubyte)((fblMode & 0xF0u) | (state)))
#define GetFblMode()              ((ubyte)(fblMode & 0x0Fu))
#define ResetFblMode()            ((ubyte)(fblMode = 0x00u))


/*Have reprogramming request flag or not*/
#define FblProgRequest         ((ubyte)0x01u)
#define FblNoProgRequest       ((ubyte)0x00u)

#define kEepFblCANReprogram       ((ubyte)0xB5u)/*CAN Reprogram flag*/
#define kEepFblOTAReprogram       ((ubyte)0x5Bu)/*OTA Reprogram flag*/

/*Application validation*/
#define FblApplValid            ((ubyte)0x01u)     /* Application is fully programmed */
#define FblApplInvalid          ((ubyte)0x00u)     /* Application software is not valid */

#define FBLM_NO_TRIGGER     		((ubyte)0x00u)
#define FBLM_TM_TRIGGERED        	((ubyte)0x01u)
/* Defines for bootloader state flags */

/* Memory driver state flags */
#define kFblMemDriverInitialized    ((ubyte) 0x01u)
#define GetMemDriverInitialized()   ((flashState & kFblMemDriverInitialized) == kFblMemDriverInitialized)
#define SetMemDriverInitialized()   (flashState |= kFblMemDriverInitialized)
#define ClrMemDriverInitialized()   (flashState &= (ubyte)~kFblMemDriverInitialized)


/* Internal state(fblStates) for FBL state machine */
#define kFblStateDiagIndication           ((ushort) 0x0001u)
#define kFblStateSuppressPosRspMsg        ((ushort) 0x0002u)
#define kFblStateFingerprintValid         ((ushort) 0x0004u)
#define kFblStateTransferDataAllowed      ((ushort) 0x0008u)
#define kFblStateServiceInProgress        ((ushort) 0x0010u)
#define kFblStateFunctionalRequest        ((ushort) 0x0020u)
#define kFblStateResponseProcessing       ((ushort) 0x0040u)
#define kFblStateTpConfirmationFlag       ((ushort) 0x0080u)
#define kFblStateDefaultDiagSession       ((ushort) 0x0100u)
#define kFblStateExtendedDiagSession      ((ushort) 0x0200u)
#define kFblStateProgrammingMode          ((ushort) 0x0400u)
#define kFblStateProgrammingSession       ((ushort) 0x0400u)
#define kFblStateSecurityKey              ((ushort) 0x0800u)
#define kFblStateSecurityAccess           ((ushort) 0x1000u)
#define kFblStatePreconditionsChecked     ((ushort) 0x2000u)
#define kFblStateTransferDataSucceeded    ((ushort) 0x4000u)
#define kFblStateEraseSucceeded           ((ushort) 0x8000u)

/* Macros for state flag access */
/* Additional macros for FBL state flag access */
#define SetTransferDataSucceeded()     (fblStates |= kFblStateTransferDataSucceeded)
#define ClrTransferDataSucceeded()     (fblStates &= FblInvert16Bit(kFblStateTransferDataSucceeded))

#define SetEraseSucceeded()            (fblStates |= kFblStateEraseSucceeded)
#define ClrEraseSucceeded()            (fblStates &= FblInvert16Bit(kFblStateEraseSucceeded))

#define SetTpConfirmationFlag()        (fblStates |=  kFblStateTpConfirmationFlag)/*TP layer has been sent*/
#define ClrTpConfirmationFlag()        (fblStates &= FblInvert16Bit(kFblStateTpConfirmationFlag))
#define GetTpConfirmationFlag()        ((fblStates & kFblStateTpConfirmationFlag) == kFblStateTpConfirmationFlag)


/* Sequence SEED followed by KEY is now not checked */
#define SetSecurityKeyAllowed()        (fblStates |= kFblStateSecurityKey)/*Seed has been sent,allow to verify key*/
#define ClrSecurityKeyAllowed()        (fblStates &= FblInvert16Bit(kFblStateSecurityKey))

#define SetSecurityUnlock()            (fblStates |= kFblStateSecurityAccess)
#define ClrSecurityUnlock()            (fblStates &= FblInvert16Bit(kFblStateSecurityAccess))

/* Flag to indicate that a request is functionally addressed */
#define SetFunctionalRequest()         (fblStates |= kFblStateFunctionalRequest)
#define ClrFunctionalRequest()         (fblStates &= FblInvert16Bit(kFblStateFunctionalRequest))

/* Flag to indicate a running response processing */
#define SetResponseProcessing()        (fblStates |= kFblStateResponseProcessing)
#define ClrResponseProcessing()        (fblStates &= FblInvert16Bit(kFblStateResponseProcessing))


#define SetServiceInProgress()         (fblStates |=  kFblStateServiceInProgress)
#define ClrServiceInProgress()         (fblStates &= FblInvert16Bit(kFblStateServiceInProgress))

#define SetDiagIndication()            (fblStates |= kFblStateDiagIndication)
#define ClrDiagIndication()            (fblStates &= FblInvert16Bit(kFblStateDiagIndication))

#define SetFingerprintValid()          (fblStates |= kFblStateFingerprintValid)
#define ClrFingerprintValid()          (fblStates &= FblInvert16Bit(kFblStateFingerprintValid))

#define SetEnablePrgMode()             (fblStates |= kFblStateProgrammingMode)
#define ClrEnablePrgMode()             (fblStates &= FblInvert16Bit(kFblStateProgrammingMode))

#define SetTransferDataAllowed()       (fblStates |= kFblStateTransferDataAllowed)
#define ClrTransferDataAllowed()       (fblStates &= FblInvert16Bit(kFblStateTransferDataAllowed))

/* Flag for suppressing positive responses */
#define SetSuppressPosRspMsg()         (fblStates |= kFblStateSuppressPosRspMsg)
#define ClrSuppressPosRspMsg()         (fblStates &= FblInvert16Bit(kFblStateSuppressPosRspMsg))

/* Flag if CheckProgrammingPreConditions is done */
#define SetPreconditionsChecked()      (fblStates |= kFblStatePreconditionsChecked)
#define ClrPreconditionsChecked()      (fblStates &= FblInvert16Bit(kFblStatePreconditionsChecked))


/* Session management macros */
#define SetDiagProgrammingSession()    (fblStates |= kFblStateProgrammingSession)
#define ClrDiagProgrammingSession()    (fblStates &= FblInvert16Bit(kFblStateProgrammingSession))
#define SetDiagExtendedDiagSession()   (fblStates |= kFblStateExtendedDiagSession)
#define ClrDiagExtendedDiagSession()   (fblStates &= FblInvert16Bit(kFblStateExtendedDiagSession))
#define SetDiagDefaultDiagSession()    (fblStates |= kFblStateDefaultDiagSession)
#define ClrDiagDefaultDiagSession()    (fblStates &= FblInvert16Bit(kFblStateDefaultDiagSession))

#define GetDiagIndication()            ((fblStates & kFblStateDiagIndication) == kFblStateDiagIndication)
#define GetFingerprintValid()          ((fblStates & kFblStateFingerprintValid) == kFblStateFingerprintValid)
#define GetEnablePrgMode()             ((fblStates & kFblStateProgrammingMode) == kFblStateProgrammingMode)
#define GetTransferDataAllowed()       ((fblStates & kFblStateTransferDataAllowed) == kFblStateTransferDataAllowed)
#define GetSecurityKeyAllowed()        ((fblStates & kFblStateSecurityKey) == kFblStateSecurityKey)
#define GetSecurityUnlock()            ((fblStates & kFblStateSecurityAccess) == kFblStateSecurityAccess)
#define GetFunctionalRequest()         ((fblStates & kFblStateFunctionalRequest) == kFblStateFunctionalRequest)
#define GetResponseProcessing()        ((fblStates & kFblStateResponseProcessing) == kFblStateResponseProcessing)
#define GetSuppressPosRspMsg()         ((fblStates & kFblStateSuppressPosRspMsg)  == kFblStateSuppressPosRspMsg)
#define GetDiagProgrammingSession()    ((fblStates & kFblStateProgrammingSession) == kFblStateProgrammingSession)
#define GetDiagExtendedDiagSession()   ((fblStates & kFblStateExtendedDiagSession) == kFblStateExtendedDiagSession)
#define GetDiagDefaultDiagSession()    ((fblStates & kFblStateDefaultDiagSession) == kFblStateDefaultDiagSession)
#define GetServiceInProgress()         ((fblStates & kFblStateServiceInProgress) == kFblStateServiceInProgress)
#define GetPreconditionsChecked()      ((fblStates & kFblStatePreconditionsChecked) == kFblStatePreconditionsChecked)
#define GetTransferDataSucceeded()     ((fblStates & kFblStateTransferDataSucceeded) == kFblStateTransferDataSucceeded)
#define GetEraseSucceeded()            ((fblStates & kFblStateEraseSucceeded) == kFblStateEraseSucceeded)


/* Defines for allowed sessions */
#define kFblSessionDefault                    kFblStateDefaultDiagSession
#define kFblSessionExtended                   kFblStateExtendedDiagSession
#define kFblSessionProgramming                kFblStateProgrammingSession
#define kFblSessionExtendedProgramming        ((ushort)(kFblSessionExtended | kFblSessionProgramming))
#define kFblSessionDefaultExtendedProgramming ((ushort)(kFblSessionDefault | kFblSessionExtended | kFblSessionProgramming))

#define GetCurrentSession()            ((ubyte)((fblStates & kFblSessionDefaultExtendedProgramming) >> 8))

/* Defines for 2nd bootloader state flags,here only for CAN communication*/
#define kFbl2ndStateRcrRpInProgress         ((ushort) 0x0001u)
#define SetRcrRpInProgress()                (fbl2ndStates |= kFbl2ndStateRcrRpInProgress)
#define ClrRcrRpInProgress()                (fbl2ndStates &= FblInvert16Bit(kFbl2ndStateRcrRpInProgress))
#define GetRcrRpInProgress()           ((fbl2ndStates & kFbl2ndStateRcrRpInProgress) == kFbl2ndStateRcrRpInProgress)

#define Fblm_TriggerCounterFactor               10/* Factor */
/* -- bit 7 of the sub-function parameter) -- */
#define kDiagSuppressPosRspMsgIndicationBit    ((ubyte) 0x80u)
#define FBL_CHECKMEMORY_MAXLIMITED ((ubyte)0x02u)
/*______ G L O B A L - T Y P E S _____________________________________________*/

typedef struct 
{
   ubyte APP_EraseSucceeded : 1;
   ubyte APPSHA_EraseSucceeded : 1;
   ubyte SWP1_EraseSucceeded : 1;
   ubyte SWP1SHA_EraseSucceeded : 1;

   ubyte reserve : 4;
}BlockEraseFlag;

/*______ G L O B A L - D A T A _______________________________________________*/
extern ubyte Fblm_FlashDrvShaData[44];
extern ubyte Fblm_AppShaData[44];
extern ubyte Fblm_Swp1ShaData[44];
extern ubyte Fblm_RunRoutineIdEraseMemoryFlag;
extern ulong Fblm_EraseMemoryAddress;
extern ulong Fblm_ErasememorySize;
/*______ G L O B A L - M A C R O S ___________________________________________*/

/*______ G L O B A L - F U N C T I O N S - P R O T O T Y P E S _______________*/
extern void Fblm_DiagTask(void);
extern void Fblm_IMCRxTask(void);

/******************************************************************************
* Name         :  Fblm_SetFingerprintValid
* Called by    :  FblDiagTask()
* Preconditions:  None
* Parameters   :  None
* Return code  :  None
* Description  :  FblTesterPresent service function.
******************************************************************************/
extern void Fblm_SetFingerprintValid(void);

/*******************************************************************************
* NAME:              Fblm_StopTpStateTask
*
* CALLED BY:         Transport layer
* PRECONDITIONS:
*
* DESCRIPTION:       Rx path for physical requests.
*                    Function name must be entered to the CANgen OSEK-TP Options
*                    dialog in the fields "RxIndication".
*******************************************************************************/
extern void Fblm_StopTpStateTask(void);

/*******************************************************************************
* NAME:              DescUsdtNetIsoTpInit
*
* CALLED BY:         CANdesc
* PRECONDITIONS:
*
* DESCRIPTION:       Re-initialization
*
*
*******************************************************************************/
extern void Fblm_DiagInitQueue(uint8 queueNumber);

#endif /* _FBLM_DIAG_H_ */
