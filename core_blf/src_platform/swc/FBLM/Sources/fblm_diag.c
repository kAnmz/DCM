/******************************************************************************/
/* @F_NAME :          fblm_diag.c                                             */
/* @F_PURPOSE :       manage UDS for FBL		                              */
/* @F_CREATED_BY :    Jianhua.Wu  			                                  */
/* @F_CREATION_DATE : 2021.07.14                                              */
/* @F_LANGUAGE :      ANSI C                                                  */
/* @F_MPROC_TYPE :    target independent           						      */
/*************************************** (C) Copyright 2021 Marelli ***********/

/*______ I N C L U D E - F I L E S ___________________________________________*/
#include"fblm_diag.h"
#include"tpmc.h"
#include"fblm_priv.h"
#include "MemAcc.h"
#include "Fee_30_FlexNor.h"
#include "NvM.h"
#include "fblm_config.h"
#include "wdfs_config_dynamic.h"
#ifdef EEPC_FUN_ENABLE
#include"eepio_config.h"
#endif
#include "SbcM.h"
/*______ L O C A L - D E F I N E S ___________________________________________*/
#if defined ( TP_ENABLE_NORMAL_ADDRESSING )
# if defined ( TP_TYPE_MULTI_DYNAMIC_NORMAL_ADDRESSING )
#  define FblTpFuncResetChannel()   TpFuncResetChannel()
#  define FblTpRxResetChannel()     TpRxResetChannel(0)
# else
#  define FblTpFuncResetChannel()   TpRxResetChannel()
#  define FblTpRxResetChannel()     TpRxResetChannel()
# endif
#else
# if defined ( TP_ENABLE_EXTENDED_ADDRESSING )
#  define FblTpFuncResetChannel()   TpRxResetChannel()
#  define FblTpRxResetChannel()     TpRxResetChannel()
# else
#  define FblTpFuncResetChannel()   TpFuncResetChannel()
#  define FblTpRxResetChannel()     TpRxResetChannel()
# endif
#endif

#if defined ( TP_TYPE_MULTI_DYNAMIC_NORMAL_ADDRESSING )
#define RCRRPTransmit(a)   TpTransmit(tpTxChannel, (TP_MEMORY_MODEL_DATA vuint8*)rcrrpDiagBuffer, (a))
#define DiagTpTransmit(a)  TpTransmit(tpTxChannel, (TP_MEMORY_MODEL_DATA vuint8*)DiagBuffer, (a))
#else
#define RCRRPTransmit(a)   TpTransmit((TP_MEMORY_MODEL_DATA vuint8*)rcrrpDiagBuffer, (a))
#define DiagTpTransmit(a)  TpTransmit((TP_MEMORY_MODEL_DATA vuint8*)DiagBuffer, (a))
#endif /* TP_TYPE_MULTI_DYNAMIC_NORMAL_ADDRESSING */

#define BootFlag  (*((uint32*)0x0801F240)) /*in RRAM*/
#define BootCommand  (*((uint32*)0x0801F200)) /*in RRAM*/
#define FBLM_Command_ToAPP  ((uint32) 0x00000000)
#define FBLM_Command_ToBoot  ((uint32) 0xA5A5A5A5)



#if defined(TP_ENABLE_DIAG_SERVICE_QUEUE)
#define DiagGetSwapQueBufSts(queNum)           (K_diagQueBufferState[g_diagQueSwap[queNum]]) /*Used to query other queue*/
#define FblRespRequestTimeParm                  1  /* 0ms after request process done , it will response*/
#define WaitNextReqTime                         15   /*0Ms, This is used to wait if it have twice frame Queue*/
#endif




/*______ L O C A L - T Y P E S _______________________________________________*/
#if defined(TP_ENABLE_DIAG_SERVICE_QUEUE)
typedef struct             /*Queue Properties */
{
  uint8        bufferIsFree;
  uint8        requestProcess;
  uint16       dataLength;
  uint8         phyReqInd;
  vuint32         reqStep;
  uint8          waitReqTime;
  uint8          FunctionReq;
}DiagQueueBufferAttribute;
#endif

/*______ G L O B A L - D A T A _______________________________________________*/
ushort WDTimer = 0u;                    /* Watchdog timer */
ushort P2Timer = 0u;                    /* P2 timeout timer */
ubyte DiagFrameCounter = 0u;           /* Diagnostic communication sync*/
ubyte flashState = 0u;                /* state flags for flash driver interface(if flash driver was initialized) */
ushort fblStates = 0u;                /* Internal state flags for FBL state machine,for UDS*/
BlockEraseFlag fblm_EraseFlag = {       /*It is used to judge the erasure status of each block*/
   .APP_EraseSucceeded = 0,
   .APPSHA_EraseSucceeded = 0,
    .SWP1_EraseSucceeded = 0,
    .SWP1SHA_EraseSucceeded = 0,
    .reserve = 0};                 
ushort fbl2ndStates = 0u;			/* Further internal state flags for FBL state machine,fblStates's 16 bit all used,here only for CAN communication*/
ubyte diagResponseFlag = 0u;       	/* Flag to enable/suppress diagnostic response,example,SID 0x3E will not answer*/
ubyte rcrrpDiagBuffer[3] = {0u};	/*For store diagnostic negative response NRC78 temporarily,requestCorrectlyReceived-ResponsePending=RCRRP*/
ubyte diagErrorCode = kDiagErrorNone;             /*Diagnostic error code*/
ulong Fblm_RandomValue = 1;     /*Used to add randomness*/
ubyte Fblm_RunningEraseCommandFlag = FALSE;
ubyte Fblm_ActivateSblFlag = FALSE;
ubyte checkMemoryAllowed = kFblFailed;/* Check memory is only allowed after data transfer */
#if defined(IMC_FUN_ENABLE)
ushort DiagResetTimerCounter = 0u;    /* When OTA,need wait for GPU sync */
#endif
#if defined(FBL_ENABLE_SEC_ACCESS_DELAY)
/* Counter for invalid key of security access procedure */
static ubyte secSendKeyInvalid = 0u;/*Number of invalid option of $27*/
static ubyte SeedRequestCount = 0;   /* Number of consecutive seed requests $27*/ 
static ulong secSecurityAccessDelay = 0u;/*Delay time once exceeded Number Of Attempts*/
#endif
static boolean Fblm_FlashDrvDownloadDone = false;  /* Detect whether sbl has been downloaded. */

// ubyte Info_Array[FlashDrv_BlockSize] = {0u};/*virtual flash driver, actuall this is a information block*/
#if defined(TP_ENABLE_DIAG_SERVICE_QUEUE)
ubyte basicDiagBuffer[kDiagQueBufferNum][FBL_DIAG_BUFFER_LENGTH+kDiagBufferAlign] = {0u};/* Data buffer for diagnostic data */
vuint8 FblRespRequest = FALSE;     /*mechanism of delay Response*/
vuint8 FblRespRequestLen = FALSE;
vuint8 FblRespRequestTime = 0;

#else
ubyte basicDiagBuffer[FBL_DIAG_BUFFER_LENGTH+kDiagBufferAlign] = {0u};/* Data buffer for diagnostic data */
#endif
ubyte *DiagBuffer = NULL;
ubyte *DiagBufPtr = NULL;
ushort testerPresentTimeout = 0u;   /*Timer value for TesterPresent timeout*/
ushort DiagDataLength = 0u;         /* Stores number of received data */
ubyte ActiveLogicBlock = Invalid_BlockIndex;
ubyte Fblm_FlashDrvShaData[44] = {0};
ubyte Fblm_AppShaData[44] = {0};
ubyte Fblm_Swp1ShaData[44] = {0};
uint8 Fblm_StartTpStateTaskFlag = FALSE; /*used to Control  TpStatetask running */
ubyte Fblm_TriggerCounter = 0;
ubyte Fblm_RunRoutineIdEraseMemoryFlag = FALSE; /*set flag to know if it is erasing*/
ulong Fblm_EraseMemoryAddress = 0;
ulong Fblm_ErasememorySize = 0;
//TO DO
/*For CAN reprogramming*/
ubyte tpRCRRPflag = 0u;/*NRC78 sending flag*/
ubyte tpBufferLocked = 0u;/*For lock diag buffer*/
ubyte server36_dataBuffer[FBL_DIAG_CAN_SEGMENT_SIZE+FBL_MEMORY_WRITE_512BYTE] = {0};
static ulong  outof_512_size = 0;
ulong g_StartAddress = 0;
ulong g_StartAddressLength =0;

static boolean Fblm_SwplBlankCheckFlag = FALSE;  /* swpl check sum flag */
static boolean Fblm_AppBlankCheckFlag = FALSE;	 /* app check sum flag */	

extern uint8_t            flashCode[];
extern uint8_t         FBLM_Swp1Code[];
/*NVM Variable*/
extern uint8 Fblm_ReadWriteNvmBlockData[Fblm_ReadWriteNvmBlockDataMaxLen];
extern uint8 Fblm_CurrentNvMBlockId;
extern boolean Fblm_IsReadWriteNvmBlock;
extern boolean Fblm_IsReadNvmBlock;
extern uint16 Fblm_DiagRespDataLen;
extern uint8 *Fblm_DiagData;
extern ushort Fblm_AppSwUpdateAttemptCounter;
extern ushort Fblm_CurrentOdometer;

#ifdef FBLM_DIAG_USE_NVM
Fblm_NvmWriteResult_t Fblm_NvmWriteResult = Fblm_NVM_WRITE_PENDING;
Fblm_NvmWriteReq_t Fblm_NvmWriteReqInternal = {0, NULL, &Fblm_NvmWriteResult};
uint16 Fblm_NvmTimeoutCounter = 0;
Fblm_NvmProcessState_t Fblm_NvmProcessState = Fblm_NVM_IDLE;
#endif /* FBLM_DIAG_USE_NVM */

#if defined(TP_ENABLE_DIAG_SERVICE_QUEUE)
static DiagQueueBufferAttribute    K_diagQueBufferState[kDiagQueBufferNum];
static vuint32               K_diagPhyReqStep;
static vuint16               k_diagQueBlockTime;

const static vuint8 g_diagQueSwap[2] = {1u,0u};

#endif

/*______ P R I V A T E - D A T A _____________________________________________*/

ubyte securitySeedResponse = kNewSeedRequest;
tSessionMngmntTbl kSessionMngmntTbl[] = \
{
   {
      kDiagSidDiagnosticSessionControl,
      kFblSessionDefaultExtendedProgramming
   },
   {
      kDiagSidEcuReset,
      kFblSessionDefaultExtendedProgramming
   },
   {
      kDiagSidReadDataByIdentifier,
      kFblSessionDefaultExtendedProgramming
   },
   {
      kDiagSidSecurityAccess,
      kFblSessionProgramming
   },
   {
      kDiagSidCommunicationControl,
      kFblSessionExtended
   },
   {
      kDiagSidRoutineControl,
      kFblSessionDefaultExtendedProgramming
   },
   {
      kDiagSidRequestDownload,
      kFblSessionProgramming
   },
   {
      kDiagSidTransferData,
      kFblSessionProgramming
   },
   {
      kDiagSidRequestTransferExit,
      kFblSessionProgramming
   },
   {
      kDiagSidWriteDataByIdentifier,
      kFblSessionProgramming
   },
   {
      kDiagSidTesterPresent,
      kFblSessionDefaultExtendedProgramming
   },
   {
      kDiagSidControlDTCSetting,
      kFblSessionExtended
   }
};

/*______ L O C A L - D A T A _________________________________________________*/
static ulong transferAddress = 0u;     /* Actual transfer address */
static ubyte *transferShaAddress = NULL;     /*SHA Actual transfer address */
static ulong transferRemainder = 0u;/* Number of remaining transfer bytes */
static ubyte transferType = 0u;     /* Download into RAM/Flash or upload  */
static ubyte expectedSequenceCnt = 0u; /*Block sequence counter in transfer data service*/
static ubyte currentSequenceCnt = 0u;  /*Current Block sequence counter*/
static ubyte retryCounter = 0u;  /* Counter for TransferData retries */
static sshort memSegment = -1; /* Memory segment handle */
static tBlockDescriptor downloadBlockDescriptor = {0u};/* Transfer block information */
static ubyte checkMemoryCnt = 0u;/*Consecutive check memory counter*/
/*______ L O C A L - M A C R O S _____________________________________________*/

/*______ I M P O R T - F U N C T I O N S - P R O T O T Y P E S _______________*/

/*______ L O C A L - F U N C T I O N S - P R O T O T Y P E S _________________*/
static void ChkSuppressPosRspMsgIndication(ubyte *subparam);
static void ApplFblSecurityInit(void);
static void Fblm_SecuritySeedInit(void);
static void TpResetRxBlock(void);
static void DiagDiscardReception(void);
static void DiagForceTransmit(void);
static void DiagWaitForConfirmation(void);
#ifdef FBLM_DIAG_USE_NVM
static void Fblm_NvmWriteReqHandler(void);
#endif /* FBLM_DIAG_USE_NVM */

#if defined(TP_ENABLE_DIAG_SERVICE_QUEUE)
static void Fblm_DiagUsdQueStsInit(void);
static ubyte Fblm_DiagGetBufferFreeSts(void);
static ubyte Fblm_DiagAllQueueIsBusySts(void);
static void FblDiagUpdateRequest(void);
static void DiagQuePhyReqInd( vuint8 queueNum);
static void DiagQueFuncReqInd( vuint8 queueNum);
static void FblRespRequestProcess(void);
#endif /*TP_ENABLE_DIAG_SERVICE_QUEUE*/

static void FblTpTxStateTaskProcess(void);
static uint8 Fblm_GetTpStateTaskFlag(void);
static void Fblm_StartTpStateTask(void);
void Fblm_StopTpStateTask(void);
/*______ G L O B A L - F U N C T I O N S _____________________________________*/
/*----------------------------------------------------------------------------*/
/*Name : Fblm_DiagTask                                                		  */
/*Role : UDS runnable                                                         */
/*Interface :                                                                 */
/*  - IN  : none                                                              */
/*  - OUT : none                                                              */
/*Pre-condition : assumed operation                                           */
/*Constraints   : use restriction                                             */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [operation to carry out]                                                */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
void Fblm_DiagTask(void)
{
  vuint8 queNum = 0u;
  
/*Tester present timing*/
	if (0u != TimeoutTesterValue())
	{
		DecTimeoutTesterValue();
		if (0u == TimeoutTesterValue())
		{
			if(UPDATE_MODE_OTA == Fblm_GetUpdateMode())
			{
		         /*
		            Tester present timer expired,Exit programming session!!
		            Use FblDiagInit() to return dafault session and init DIAG!!!
		            FBL need to have ability to update APP again!!!
		         */
		        /* Restart the tester present timer if not in default session */
		        if (GetDiagProgrammingSession() || GetDiagExtendedDiagSession())
		        {
		          Fblm_DiagInit();
		        }
			}
			else
			{
				/*CAN reprogramming need to reset MCU*/
				Fblm_DiagEcuReset(kDiagResetNoResponse);
			}

		}
	}
#if defined(FBL_ENABLE_SEC_ACCESS_DELAY)
   /* Security access delay timing */
   if (GetSecurityAccessDelay() > 0u)
   {
      DecSecurityAccessDelay();

      if (0u == GetSecurityAccessDelay())
      {
         if (kSecMaxInvalidKeys == secSendKeyInvalid)
         {
         /* Reset invalid counter */
            /* GEFDCM-243 The key failure counter needs to be cleared after 10S. */
            secSendKeyInvalid = 0;
           /*Save to EEPROM*/
/*            EEPS_RamBootsecurityaccessfailuretimes = secSendKeyInvalid;
            EEPC_WriteEepromId(EEPC_ID_BOOTSECURITYACCESSFAILURETIMES);*///to do
            securitySeedResponse = kNewSeedRequest;
         }
         /* GEFDCM-242 Number of seed recovery attempts after 10s. */
         if(kSecMaxInvalidKeys == SeedRequestCount)
         {
            SeedRequestCount--;
         }
      }
   }
#endif

/*Handle diagnostic service*/
	if (GetDiagIndication())
	{
		ClrDiagIndication();
		ClrSuppressPosRspMsg();/*SID&0x80 14229 specific*/
		DiagClrError();

		if (kFblOk == Fblm_DiagCheckAddressing(DiagBuffer[kDiagFmtServiceId]))
		{
	         /* Check if service is supported in active session */
	         if ((kFblFailed == FblDiagCheckSession(DiagBuffer[kDiagFmtServiceId])))
	         {
	            /* ServiceNotSupportedInActiveSession */
	            DiagNRCServiceNotSupportedInActiveSession();
	         }
	         else
	         {
	        	 /* Parse Service IDs supported in current session */
	        	 switch (DiagBuffer[kDiagFmtServiceId])
	        	 {

                 case kDiagSidDiagnosticSessionControl:    /* 0x10 */
                    ChkSuppressPosRspMsgIndication(&DiagBuffer[kDiagFmtSubparam]);
                    Fblm_DiagDiagnosticSessionControl();
                    break;
                 case kDiagSidEcuReset:                    /* 0x11 */
                    ChkSuppressPosRspMsgIndication(&DiagBuffer[kDiagFmtSubparam]);
                    Fblm_DiagEcuReset(kDiagResetPutResponse);
                    break;
                 case kDiagSidReadDataByIdentifier:        /* 0x22 */
                    Fblm_DiagReadDataByIdentifier();
                    break;
                 case kDiagSidSecurityAccess:              /* 0x27 */
                    ChkSuppressPosRspMsgIndication(&DiagBuffer[kDiagFmtSubparam]);
                    Fblm_DiagSecurityAccess();
                    break;
                 case kDiagSidCommunicationControl:        /* 0x28 */
                    ChkSuppressPosRspMsgIndication(&DiagBuffer[kDiagFmtSubparam]);
                    Fblm_DiagCommunicationControl();
                    break;
                 case kDiagSidWriteDataByIdentifier:       /* 0x2E */
                    Fblm_DiagWriteDataByIdentifier();
                    break;
                 case kDiagSidRoutineControl:              /* 0x31 */
                    ChkSuppressPosRspMsgIndication(&DiagBuffer[kDiagFmtSubparam]);
                    Fblm_DiagRoutineControl();
                    break;
                 case kDiagSidRequestDownload:             /* 0x34 */
                    Fblm_DiagRequestDownload();
                    break;
                 case kDiagSidTransferData:                /* 0x36 */
                	Fblm_DiagTransferDownload();
                    break;
                 case kDiagSidRequestTransferExit:         /* 0x37 */
                    Fblm_DiagRequestTransferExit();
                    break;
                 case kDiagSidTesterPresent:               /* 0x3E */
                    ChkSuppressPosRspMsgIndication(&DiagBuffer[kDiagFmtSubparam]);
                    Fblm_DiagTesterPresent();
                    break;
                 case kDiagSidControlDTCSetting:           /* 0x85 */
                    ChkSuppressPosRspMsgIndication(&DiagBuffer[kDiagFmtSubparam]);
                    Fblm_DiagControlDTCSetting();
                    break;
                 default:
                    /*If service is not supported as user service,Send negative response:ServiceNotSupported*/
                	 DiagNRCServiceNotSupported();
                    break;
	        	 }
	         }
		}
		else
		{
		  /*do nothing*/
		}/*end of Fblm_DiagCheckAddressing()*/

	     /* -- 14229 specific -- */
	     if (DiagGetError() != kDiagErrorNone)
	     {
	       DiagResponseProcessor(0);
	     }
	}
	else
	{
		/*do nothing*/
	}/*end of GetDiagIndication()*/
	Fblm_SyncNvMTask();
	Fblm_AsyncWriteQueueUpdateRequest();
	Fblm_AsyncWriteNvmTask();
#ifdef FBLM_DIAG_USE_NVM
   Fblm_NvmWriteReqHandler();
#endif /* FBLM_DIAG_USE_NVM */
	Fblm_RandomValue *= 3;

#if defined(TP_ENABLE_DIAG_SERVICE_QUEUE)
  FblDiagUpdateRequest();
/*  FblRespRequestProcess();*//*don't need add time between request and reply*/
#endif
  FblTpTxStateTaskProcess();
}

/*----------------------------------------------------------------------------*/
/*Name : FblTpTxStateTaskProcess                                              */
/*Role :                                                                      */
/*Interface :                                                                 */
/*  - IN  : none                                                              */
/*  - OUT : none                                                              */
/*Pre-condition : assumed operation                                           */
/*Constraints   : use restriction                                             */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [operation to carry out]                                                */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
static void FblTpTxStateTaskProcess(void)
{
   /*When we need to run TpTxStateTask*/
  if(TRUE == Fblm_GetTpStateTaskFlag())
  {
    TpTxStateTask(0);
    if(kCanTxOk == Fblm_CanMsgTransmitted())
    {
      CAN5_TxMsgCallback();   /*Tramsimt OK. Enter callback*/
      Fblm_StopTpStateTask();
    }
  }
}



#if defined(IMC_FUN_ENABLE)
/*----------------------------------------------------------------------------*/
/*Name : Fblm_IMCRxTask                                                		  */
/*Role : IMC receive UDS data runnable                                        */
/*Interface :                                                                 */
/*  - IN  : none                                                              */
/*  - OUT : none                                                              */
/*Pre-condition : assumed operation                                           */
/*Constraints   : use restriction                                             */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [operation to carry out]                                                */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
void Fblm_IMCRxTask(void)
{
	  ubyte TmpFrameCounter = 0u;
	  ushort TmpDataLength = 0u;
	  ubyte GPURequestBuffer[FBL_DiagRequestZize] = {0u};
	  if (TRUE/*IM_GET_DATA_OK == IMCM_GetConstLenData(IM_DIS_ID_CB_GFMM_DiagRequest,\
	      GPURequestBuffer, NULL)*/)
	  {
	    TmpFrameCounter = GPURequestBuffer[FBL_FrameCounterOffset];
	    if (TmpFrameCounter != DiagFrameCounter)
	    {
	      DiagFrameCounter = TmpFrameCounter;
	      /*valid data length include service ID*/
	      TmpDataLength = (ushort)((((ushort)GPURequestBuffer[FBL_DataLengthHiOffset])<<8) \
	          | GPURequestBuffer[FBL_DataLengthLoOffset]);
	      if ((0u == TmpDataLength) || (0u == GPURequestBuffer[FBL_ServiceIDOffset]))
	      {
	    	  return;
	      }
	      /*excluding the Service-ID*/
	      DiagDataLength = TmpDataLength - 1;
	      diagResponseFlag = kDiagPutResponse;
	      SetDiagIndication();
	      DiagClrError();
	      /* Halts the tester-present timer while receiving a diagnostic message */
	      ResetTesterTimeout();/*if not default session*/
	      /* Indicate an ongoing service processing */
	      SetServiceInProgress();
	      SetP2Timer(kFblDiagTimeP2);   /* Reset P2 timer (initial timing) */

	      /* Initialize security seed */
	      Fblm_SecuritySeedInit();

	      memcpy((void *)DiagBuffer,(const void *)(&GPURequestBuffer[FBL_ServiceIDOffset]),\
	          TmpDataLength);
	      /*CAN reprogramming also need check SID&0x80*/
	    }
	    else
	    {
	      /*Not a new request,do nothing*/
	    }
	  }
	  else
	  {
	    /*IMC not OK,do nothing*/
	  }

}
#endif
/*______ P R I V A T E - F U N C T I O N S ___________________________________*/
/*----------------------------------------------------------------------------*/
/*Name : Fblm_DiagInit    			                                          */
/*Role : Initialize UDS module 						      				      */
/*Interface :                                                                 */
/*  - IN  : none	                                                          */
/*  - OUT : none  							                                  */
/*Pre-condition : none			                                              */
/*Constraints   : none             			                                  */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [initialize parameters and main loop]                                   */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
void Fblm_DiagInit(void)
{
   /* Initialize Transport Layer */
  TpInitPowerOn();
  Fblm_TriggerCounter = 0;
  WDTimer = 0u;
  ClrP2Timer();
  DiagFrameCounter = 0u;
  flashState = 0u;
  fblStates = 0u;
  fbl2ndStates = 0u;

  transferRemainder = 0u;
  transferType = DOWNLOAD_INIT;
  expectedSequenceCnt = 0u;
  memSegment = -1;
  diagResponseFlag = kDiagPutResponse;/*Initialize as need response*/
  //downloadBlockDescriptor.blockNr = 0u;  //to do
  tpRCRRPflag = 0u;
  tpBufferLocked = 0u;
  DiagDataLength = 0u;
  checkMemoryCnt = 0u;
  rcrrpDiagBuffer[0] = kDiagRidNegativeResponse;
  rcrrpDiagBuffer[2] = kDiagNrcRcrResponsePending;

   memset(&fblm_EraseFlag, 0, sizeof(fblm_EraseFlag));
    DiagClrError();
#if defined(IMC_FUN_ENABLE)
    DiagResetTimerCounter = 0u;
#endif
    /*Set diagnostic session (Programming session)*/
    ClrDiagExtendedDiagSession();
    ClrDiagDefaultDiagSession();
    SetDiagProgrammingSession();
# if defined(TP_ENABLE_DIAG_SERVICE_QUEUE)
    /*4 byte aligned,point to the real memory address*/
    DiagBuffer = (4-(((ulong)&basicDiagBuffer[0][0])%4))+ &basicDiagBuffer[0][0];
    DiagBufPtr = (4-(((ulong)&basicDiagBuffer[0][0])%4))+ &basicDiagBuffer[0][0];
    Fblm_DiagUsdQueStsInit();
#else
    /*4 byte aligned,point to the real memory address*/
    DiagBuffer = (4-(((ulong)basicDiagBuffer)%4))+basicDiagBuffer;
#endif

    /*Stop tester present timer*/
    StopTesterTimeout();
    ActiveLogicBlock = Invalid_BlockIndex;


    /*Init $27 Seed response status*/
    securitySeedResponse = kNewSeedRequest;
#if defined(FBL_ENABLE_SEC_ACCESS_DELAY)
    secSendKeyInvalid = WDFS_RamBootPara.BootSwFingerprint.SAFailedAccessCounter_L1; 
    /* Initialize security access delay timer */
    if (secSendKeyInvalid >= kSecMaxInvalidKeys)
    {
       SetSecurityAccessDelay();
    }
    else
    {
       ClrSecurityAccessDelay();
    }
#endif
#if defined(FBL_ENABLE_DEBUG_STATUS)
    //To do
#endif

    /*Initialize security module*/
    ApplFblSecurityInit();

#if defined(FBL_WATCHDOG_ON)
    WDTimer = (ushort)FBL_WATCHDOG_TIME;/*Start refresh watch dog period*/
#endif

}

/*----------------------------------------------------------------------------*/
/*Name : Fblm_LookForWatchdog    			                                  */
/*Role : Refresh watch dog						      			     	      */
/*Interface :                                                                 */
/*  - IN  : none	                                                          */
/*  - OUT : none  							                                  */
/*Pre-condition : none			                                              */
/*Constraints   : none             			                                  */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [initialize parameters and main loop]                                   */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
ubyte Fblm_LookForWatchdog(void)
{
	ubyte retValue = FBLM_NO_TRIGGER;

  
#if defined( FBL_WATCHDOG_ON )
  
   if (GetWDInit()) /* Check if watchdog flag already initialized */
#endif
   {
	   if (TRUE == TIMD_TimerGet())
	   {
       (void)Sbcc_WatchdogMonitor();

       if (Fblm_TriggerCounter < Fblm_TriggerCounterFactor)
       {
         Fblm_TriggerCounter ++;
       }
       else
       {

       }
       retValue = FBLM_TM_TRIGGERED;

	     if (Fblm_TriggerCounterFactor == Fblm_TriggerCounter)
	     {
	       Fblm_TriggerCounter = 0;

	         if (P2Timer > 0x00u)
	         {
	            P2Timer--;

	            if ((P2Timer < (kFblDiagTimeP2Star/2u)) && (GetRcrRpInProgress()))
	            {
	             if (UPDATE_MODE_CAN == Fblm_GetUpdateMode())
	             {
	                  Fblm_RetransmitRcrRp();/*For NRC78*/
	             }
	               SetP2Timer(kFblDiagTimeP2Star);
	            }
	         }

	#if defined( FBL_WATCHDOG_ON )
	         if (0x00u != WDTimer)
	         {
	            WDTimer--;
	            if (0x00u == WDTimer)
	            {
	              Fblm_WDRefresh();
	                WDTimer = FBL_WATCHDOG_TIME;
	            }
	         }
	#endif /* FBL_WATCHDOG_ON */


	     }
	   }
   }

   return retValue;
}

/******************************************************************************
* Name         :  Fblm_DiagCheckAddressing
* Called by    :  DiagTask
* Preconditions:  None
* Parameters   :  Service-ID of actual request
* Return code  :  kFblOk - if service is allowed
*                 kFblFailed - if service is not allowed
* Description  :  check if actual SID is allowed
******************************************************************************/
ubyte Fblm_DiagCheckAddressing(ubyte serviceID)
{
   ubyte returnValue = kFblOk;

   /* Check if request is functional */
   if (GetFunctionalRequest())
   {
      /* Parse Service IDs */
      switch (serviceID)
      {
      /* These services are not supported functionally addressed */
         case kDiagSidWriteDataByIdentifier:       /* 0x2E */
         /* GEFDCM-259 $34 Need to support functional addressing*/
         /*case kDiagSidRequestDownload:*/             /* 0x34 */
         /*case kDiagSidTesterPresent:*/               /* 0x3E */
            DiagSetNoResponse();/*No response for these SID after call DiagProcessingDone(0)*/
            DiagProcessingDone(0);
            returnValue = kFblFailed;
            break;

         default:
            break;
      }
   }
   else
   {
	   /*physical request always OK*/
   }

   return returnValue;
}

#if defined(TP_ENABLE_DIAG_SERVICE_QUEUE)
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
void Fblm_DiagInitQueue(uint8 queueNumber)
{
  vuint8 index = 0u;
 /*used to init single queue*/
  K_diagQueBufferState[queueNumber].bufferIsFree = TRUE;
  K_diagQueBufferState[queueNumber].dataLength = 0u;
  K_diagQueBufferState[queueNumber].phyReqInd = FALSE;
  K_diagQueBufferState[queueNumber].requestProcess = FALSE;
  K_diagQueBufferState[queueNumber].reqStep = 0u;
  K_diagQueBufferState[queueNumber].FunctionReq = FALSE;
}

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
static void Fblm_DiagUsdQueStsInit(void)
{
  vuint8 index = 0u;

  K_diagPhyReqStep = 0u;
  //g_descQueBlockTime = 0u;
  for(index = 0u; index < kDiagQueBufferNum; index++)
  {
    K_diagQueBufferState[index].bufferIsFree = TRUE;
    K_diagQueBufferState[index].dataLength = 0u;
    K_diagQueBufferState[index].phyReqInd = FALSE;
    K_diagQueBufferState[index].requestProcess = FALSE;
    K_diagQueBufferState[index].reqStep = 0u;
    K_diagQueBufferState[index].FunctionReq = FALSE;
  }
}

/*******************************************************************************
* NAME:              DescGetBufferFreeSts
*
* CALLED BY:         Transport layer
* PRECONDITIONS:
*
* DESCRIPTION:       StartOfFrame reception function
*                    Return the free buffer
*******************************************************************************/
static ubyte Fblm_DiagGetBufferFreeSts(void)
{
  vuint8 index = 0u;
  vuint8 Ret = FALSE;
  for(index = 0u; index < kDiagQueBufferNum; index++)
  {
    if(K_diagQueBufferState[index].bufferIsFree != TRUE)
    {
      Ret = FALSE;
      break;
    }
    else
    {
      Ret = TRUE;
    }
  }
  return Ret;
}

/*******************************************************************************
* NAME:              DescGetBufferFreeSts
*
* CALLED BY:         Transport layer
* PRECONDITIONS:
*
* DESCRIPTION:       StartOfFrame reception function
*                    Return the free buffer
*******************************************************************************/
static ubyte Fblm_DiagAllQueueIsBusySts(void)
{
  vuint8 index = 0u;
  vuint8 Ret = TRUE;
  for(index = 0u; index < kDiagQueBufferNum; index++)
  {
    if(K_diagQueBufferState[index].bufferIsFree == TRUE)
    {
      Ret = FALSE;
      break;
    }
    else
    {
      Ret = TRUE;
    }
  }
  return Ret;
}

#endif

/******************************************************************************
* Name         :  DiagResponseProcessor - 14229 specific
* Called by    :  Diagnostic service functions
* Preconditions:  - Current SID must be in DiagBuffer[0]
*                 - diagErrorCode must be initialized
* Parameters   :  Data length to be transmitted.
* Return code  :  None
* Description  :  Send diagnostic response message
******************************************************************************/
void DiagResponseProcess(ushort dataLength)
{
  FblRespRequest = TRUE;
  FblRespRequestLen = dataLength;
  FblRespRequestTime = FblRespRequestTimeParm;
}

/******************************************************************************
* Name         :  DiagResponseProcessor - 14229 specific
* Called by    :  Diagnostic service functions
* Preconditions:  - Current SID must be in DiagBuffer[0]
*                 - diagErrorCode must be initialized
* Parameters   :  Data length to be transmitted.
* Return code  :  None
* Description  :  Send diagnostic response message
******************************************************************************/
void DiagResponseProcessor(ushort dataLength)
{
#if defined(TP_ENABLE_DIAG_SERVICE_QUEUE)
	vuint8 TpResetRxBlockReq= TRUE;
#endif
	bool_t sendResponse = FALSE;   /*Indicates if a response will be issued*/
# if defined ( TP_TYPE_MULTI_DYNAMIC_NORMAL_ADDRESSING )
   ubyte tpTxChannel = 0u;
# endif
#if defined(TP_ENABLE_DIAG_SERVICE_QUEUE)
      vuint8 queNum = 0u;
#endif

   if(UPDATE_MODE_CAN == Fblm_GetUpdateMode())
   {
	 ClrRcrRpInProgress();/*For CAN communication,a response means no need NRC$78 anymore*/
   }
	ClrP2Timer();

	if(UPDATE_MODE_CAN == Fblm_GetUpdateMode())
	{
		DiagDiscardReception();
	}
#if defined(TP_ENABLE_DIAG_SERVICE_QUEUE)
    if((K_diagQueBufferState[queNum].requestProcess == TRUE) && \
    		(DiagGetSwapQueBufSts(queNum).bufferIsFree == FALSE) &&
    		(DiagGetSwapQueBufSts(queNum).phyReqInd == FALSE))
    {/*Need proccess done when other queue is receive can package*/
      TpResetRxBlockReq = FALSE;
    }
#endif

/*Response follow difference situations*/
   if (kDiagErrorNone != DiagGetError())/*Negative response*/
   {
	   if (GetFunctionalRequest() && (kDiagNrcServiceNotSupported == DiagGetError()\
			   ||kDiagNrcSubFunctionNotSupported == DiagGetError()\
			   ||kDiagNrcRequestOutOfRange == DiagGetError()\
			   ||kDiagNrcServiceNotSupportedInActiveSession == DiagGetError()\
			   ||kDiagNrcSubfunctionNotSupportedInActiveSession == DiagGetError()\
			   ))
	   {
		   /*Negative response for FunctionalRequest*/
	         /*
	            No response for functionally addressed requests if
	            service or subfunction not supported.
	         */
#if defined(TP_ENABLE_DIAG_SERVICE_QUEUE) /*due it don't enter FblTpTxConfirmation ,and so here update status*/
         for(queNum = 0u; queNum < kDiagQueBufferNum; queNum++)
         {
           if(K_diagQueBufferState[queNum].requestProcess == TRUE)
           {/*This Queue is done*/
             K_diagQueBufferState[queNum].bufferIsFree = TRUE;
             K_diagQueBufferState[queNum].requestProcess = FALSE;
             DiagGetSwapQueBufSts(queNum).waitReqTime = WaitNextReqTime; /*reinit time*/
             K_diagQueBufferState[queNum].FunctionReq = FALSE; /*reinit time*/
           }
         }
#endif
	   }
	   else/*physical request Negative response or other Negative response for FunctionalRequest*/
	   {
	         /* Prepare response message */
	         DiagBuffer[kDiagFmtSubparam]     = DiagBuffer[kDiagFmtServiceId];
	         DiagBuffer[kDiagFmtServiceId]    = kDiagRidNegativeResponse;
	         DiagBuffer[kDiagFmtNegResponse]  = DiagGetError();
	         /*
	            Set timeout for repetition of message transmission.
	            Use P2 timer decremented in watchdog routine for this task.
	            P2 timer is currently not used, it was cleared above
	            and response pending handling was disabled.
	         */
	         /*In fact,P2 Timer is currently not used*/
	         SetP2Timer(kDiagTransmitTimeout);
#if defined(IMC_FUN_ENABLE)
	     	if(UPDATE_MODE_OTA == Fblm_GetUpdateMode())
	     	{
	            /*Send negative response to GPU*/
	            FblIMCTransmit(DiagBuffer,3);/*ClrServiceInProgress() and ResetTesterTimeout() inside*/
	            sendResponse = TRUE;
	     	}
	     	else
#endif			
	     	{
				#if defined ( TP_TYPE_MULTI_DYNAMIC_NORMAL_ADDRESSING )
				   tpTxChannel = TpTxGetFreeChannel(0);
#if defined(CAN_STD_ID_USED)
                   TpTxSetChannelID(tpTxChannel, CAN_TP_TXID, CAN_TP_RXID);
#elif defined(CAN_EXT_ID_USED)
                   TpTxSetChannelExtID(tpTxChannel, CAN_TP_TXID, CAN_TP_RXID);
#endif
				#endif
				   while ((sendResponse == 0) && (GetP2Timer() > 0))
				   {
					  if (DiagTpTransmit(3) == kTpSuccess)/*3 bytes*/
					  {
						 sendResponse = 1;
					  }
					  Fblm_StartTpStateTask();   /*advoid blocking*/
					  Fblm_LookForWatchdog();
					  (void)Fblm_WDRefresh();
				   }
	     	}

          /*Clear P2 timer used for transmission timeout*/
          ClrP2Timer();
	   }


	 /*Clear pending error*/
     DiagClrError();
   }/*end of Negative response*/
   else if (kDiagPutResponse == diagResponseFlag)/*Doesn't limited by example Fblm_DiagCheckAddressing() function SID*/
   {
	   if (!GetSuppressPosRspMsg())/*CAN reprogramming also need check SubID&0x80*/
	   {
		 /* Transmit positive response if not suppressed */
		 DiagBuffer[kDiagFmtServiceId] += 0x40;
         /*
            Set timeout for repetition of message transmission.
            Use P2 timer decremented in watchdog routine for this task.
            P2 timer is currently not used, it was cleared above
            and response pending handling was disabled.
         */
         SetP2Timer(kDiagTransmitTimeout);
#if defined(IMC_FUN_ENABLE)
         if(UPDATE_MODE_OTA == Fblm_GetUpdateMode())
         {
             /*Send positive response to GPU,include service ID*/
             FblIMCTransmit(DiagBuffer,(dataLength + 1));
             sendResponse = 1;
         }
         else
#endif
         {
			#if defined ( TP_TYPE_MULTI_DYNAMIC_NORMAL_ADDRESSING )
						tpTxChannel = TpTxGetFreeChannel(0);
#if defined(CAN_STD_ID_USED)
                        TpTxSetChannelID(tpTxChannel, CAN_TP_TXID, CAN_TP_RXID);
#elif defined(CAN_EXT_ID_USED)
                        TpTxSetChannelExtID(tpTxChannel, CAN_TP_TXID, CAN_TP_RXID);
#endif
			#endif
					   while ((sendResponse == 0) && (GetP2Timer() > 0))
					   {
						  if (DiagTpTransmit(dataLength + 1) == kTpSuccess)
						  {
							 sendResponse = 1;
						  }
						  Fblm_StartTpStateTask();  /*advoid blocking*/
						  Fblm_LookForWatchdog();
						  (void)Fblm_WDRefresh();
					   }

         }

         /* Clear P2 timer used for transmission timeout */
         ClrP2Timer();
	   }
	   else
	   {
	   /*Due to that we don't need to reponse but need to update queue when it is SuppressPosRspMsg */
#if defined(TP_ENABLE_DIAG_SERVICE_QUEUE)
         for(queNum = 0u; queNum < kDiagQueBufferNum; queNum++)
         {
           if(K_diagQueBufferState[queNum].requestProcess == TRUE)
           {/*This Queue is done*/
             K_diagQueBufferState[queNum].bufferIsFree = TRUE;
             K_diagQueBufferState[queNum].requestProcess = FALSE;
             DiagGetSwapQueBufSts(queNum).waitReqTime = WaitNextReqTime; /*reinit time*/
             K_diagQueBufferState[queNum].FunctionReq = FALSE; /*reinit time*/
           }
         }
#endif
		 ClrSuppressPosRspMsg();
	   }

   }
   else
   {
	   /*do nothing*/
#if defined(TP_ENABLE_DIAG_SERVICE_QUEUE) /*due it don't enter FblTpTxConfirmation ,and so here update status*/
         for(queNum = 0u; queNum < kDiagQueBufferNum; queNum++)
         {
           if(K_diagQueBufferState[queNum].requestProcess == TRUE)
           {/*This Queue is done*/
             K_diagQueBufferState[queNum].bufferIsFree = TRUE;
             K_diagQueBufferState[queNum].requestProcess = FALSE;
             DiagGetSwapQueBufSts(queNum).waitReqTime = WaitNextReqTime; /*reinit time*/
             K_diagQueBufferState[queNum].FunctionReq = FALSE; /*reinit time*/
           }
         }
#endif
   }

   /*Reset internal state in case no response was sent*/
   if (FALSE == sendResponse)/*ex:limited by Fblm_DiagCheckAddressing() function SID*/
   {
#if defined(TP_ENABLE_DIAG_SERVICE_QUEUE)
     /* No response via TP - reset all functions */
     if(TRUE == TpResetRxBlockReq)
     {
       TpResetRxBlock();
     }
     else if(FALSE == TpResetRxBlockReq)
     {
      /*when tx reposnse ,the action of resetRxBlock will cause RX init.*/
     }
     else
     {
   	  /*error*/
     }
#endif
      /* Start the tester-present timer if not in default session */
      if (GetDiagProgrammingSession() || GetDiagExtendedDiagSession())
      {
         ResetTesterTimeout();
      }

      ClrServiceInProgress();
   }

}
/******************************************************************************
* Name         :  FblDiagCheckSession
* Called by    :  DiagTask
* Preconditions:  None
* Parameters   :  Service-ID of actual request
* Return code  :  kFblOk - if service is allowed
*                 kFblFailed - if service is not allowed
* Description  :  check if actual SID is allowed in active session
******************************************************************************/
ubyte FblDiagCheckSession( ubyte serviceID )
{
   ubyte tempCounter = kFblFailed;

   /* Check table */
   for (tempCounter = 0; tempCounter < (sizeof(kSessionMngmntTbl)/sizeof(kSessionMngmntTbl[0])); tempCounter++)
   {
      if (serviceID == kSessionMngmntTbl[tempCounter].sID)
      {
         if (0x00 == (kSessionMngmntTbl[tempCounter].allowedSessions & fblStates))
         {
            /* No allowed sessions found */
            return kFblFailed;

         }
      }
   }

   /*if a SID is not known, it is allowed (e.g. an user function)*/
   return kFblOk;
}
#if defined(IMC_FUN_ENABLE)
/******************************************************************************/
/* Name: FblIMCTransmit                                                       */
/* Role: GFMM diagnostic service response                                     */
/* Interface: void                                                            */
/* Pre-condition: none                                                        */
/* Constraints:   none                                                        */
/* Behavior:                                                                  */
/*   DO                                                                       */
/*     [ Initialize the data structures ]                                     */
/*   OD                                                                       */
/******************************************************************************/
void FblIMCTransmit(ubyte *DiagResponseBufferPtr,ushort dataLength)
{
  ubyte TempBuffer[FBL_DiagResponseZize] = {0};
  if (dataLength < (FBL_DiagResponseZize - 2))
  {
    TempBuffer[FBL_FrameCounterOffset] = DiagFrameCounter;
    TempBuffer[FBL_DataLengthHiOffset] = (ubyte)((dataLength & 0xff00)>>8);
    TempBuffer[FBL_DataLengthLoOffset] = (ubyte)(dataLength & 0x00ff);
    memcpy((void *)(&TempBuffer[FBL_ServiceIDOffset]),(const void *)DiagResponseBufferPtr,dataLength);

/*    (void)IMCM_SendConstLenData(IM_STD_ID_PA_GFMM_DiagResponse,IM_FORCE_SEND,\
        (const void *)TempBuffer);*/
  }
  /* Restart the tester present timer if not in default session */
  if (GetDiagProgrammingSession() || GetDiagExtendedDiagSession())
  {
     ResetTesterTimeout();
  }
  ClrServiceInProgress();
}
#endif
/******************************************************************************/
/* Name: Fblm_RetransmitRcrRp                                                 */
/* Role: NRC78							                                      */
/* Interface: void                                                            */
/* Pre-condition: none                                                        */
/* Constraints:   none                                                        */
/* Behavior:                                                                  */
/*   DO                                                                       */
/*     [ Initialize the data structures ]                                     */
/*   OD                                                                       */
/******************************************************************************/
void Fblm_RetransmitRcrRp(void)
{
#if FBLM_CANFD_SUPPORT
	tCanFdMsgObject RetPortingData;
#else
	tMsgObject RetPortingData;
#endif
	(void)CanTransmit(0,&RetPortingData);
	(void)FblCanTransmit(&RetPortingData);
}

/* Diagnostic service functions  *********************************************/
/******************************************************************************
* Name         :  Fblm_DiagnosticSessionControl - 14229 specific
* Called by    :  FblDiagTask
* Preconditions:  None
* Parameters   :  None
* Return code  :  None
* Description  :  FblDiagnosticSessionControl service function
******************************************************************************/
void Fblm_DiagDiagnosticSessionControl(void)
{
   /* Check minimum request length */
   if (DiagDataLength < kDiagRqlDiagnosticSessionControl)
   {
	  DiagNRCIncorrectMessageLengthOrInvalidFormat();
	  return;
   }
   /* Check entry conditions */
   if (   (DiagBuffer[kDiagFmtSubparam] != kDiagSubDefaultSession)\
		   && (DiagBuffer[kDiagFmtSubparam] != kDiagSubProgrammingSession)\
		   && (DiagBuffer[kDiagFmtSubparam] != kDiagSubExtendedDiagSession))
   {
      DiagNRCSubFunctionNotSupported();
      return;
   }
   /* Check exact request length */
   if (DiagDataLength != kDiagRqlDiagnosticSessionControl)
   {
      DiagNRCIncorrectMessageLengthOrInvalidFormat();
      return;
   }

   if (kDiagSubProgrammingSession == DiagBuffer[kDiagFmtSubparam])
   {
#if 0   /*Send NRC78 on AppMode */
		if (UPDATE_MODE_CAN== Fblm_GetUpdateMode())
		{
			/* Send response pending */
			DiagExRCRResponsePending(kForceSendResponsePending);
		}
#endif
	      /* Set diagnostic session (programming session) */
	      ClrDiagDefaultDiagSession();
	      ClrDiagExtendedDiagSession();
	      SetDiagProgrammingSession();

	      /* Diagnostic session timing */
	      DiagBuffer[kDiagFmtSubparam+1] = (ubyte)((kDiagSessionTimingP2>>8) & 0xFF);
	      DiagBuffer[kDiagFmtSubparam+2] = (ubyte)((kDiagSessionTimingP2) & 0xFF);
	      DiagBuffer[kDiagFmtSubparam+3] = (ubyte)((kDiagSessionTimingP2Star>>8) & 0xFF);
	      DiagBuffer[kDiagFmtSubparam+4] = (ubyte)((kDiagSessionTimingP2Star) & 0xFFu);

			if (UPDATE_MODE_CAN== Fblm_GetUpdateMode())
			{
				ClrTpConfirmationFlag();
	         memset(server36_dataBuffer,0,sizeof(server36_dataBuffer));
	         outof_512_size = 0;
			}
		    if(TRUE == Fblm_BootMangerRunningSts)/*Used to know if need to jump app in BM*/
		    {
		      Fblm_BmNeedToJumpApp = FALSE;
		    }
		  /* GEFDCM-96  Clear the flag when entering programming session. */
          Fblm_AppBlankCheckFlag = FALSE;
          Fblm_SwplBlankCheckFlag = FALSE;
	      DiagProcessingDone(kDiagRslDiagnosticSessionControl);
   }
   else if (kDiagSubExtendedDiagSession == DiagBuffer[kDiagFmtSubparam])
   {
	   /* -- Extended session -- */
	   if (UPDATE_MODE_CAN== Fblm_GetUpdateMode())
	   {
		      /* Check if programming session is active */
		      if (GetDiagProgrammingSession())
		      {
		         /* Transition not possible from programming session */
		         DiagNRCSubfunctionNotSupportedInActiveSession();
		         return;
		      }
	   }
	   else
	   {
		  /*From programming to extend session,it is a new gfmm sequence again*/
		  if (GetDiagProgrammingSession())
		  {
			/* reset fblstates */
			fblStates           = 0u;
			fbl2ndStates        = 0u;
			transferRemainder   = 0u;
			transferType        = DOWNLOAD_INIT;
			expectedSequenceCnt = 0u;

			/* Initialize security module */
			ApplFblSecurityInit();
		  }
	   }


	      /* Set diagnostic session (extended session) */
	       ClrDiagDefaultDiagSession();
	       ClrDiagProgrammingSession();
	       SetDiagExtendedDiagSession();

	       /* Diagnostic session timing */
	       DiagBuffer[kDiagFmtSubparam+1] = (ubyte)((kDiagSessionTimingP2>>8) & 0xFFu);
	       DiagBuffer[kDiagFmtSubparam+2] = (ubyte)((kDiagSessionTimingP2) & 0xFFu);
	       DiagBuffer[kDiagFmtSubparam+3] = (ubyte)((kDiagSessionTimingP2Star>>8) & 0xFFu);
	       DiagBuffer[kDiagFmtSubparam+4] = (ubyte)((kDiagSessionTimingP2Star) & 0xFFu);

	       if(UPDATE_MODE_CAN == Fblm_GetUpdateMode())
	       {
		       ClrTpConfirmationFlag();
	       }

	       DiagProcessingDone(kDiagRslDiagnosticSessionControl);
   }
   else if (kDiagSubDefaultSession == DiagBuffer[kDiagFmtSubparam])
   {
	   /*Default session,if presession is programming session,in CAN reprogramming,should jump to APP*/

	   /* Disable tester present timeout monitoring */
	   StopTesterTimeout();
	    /* Check if programming session is active */

	      if (GetDiagProgrammingSession())
	      {
	    	  if(UPDATE_MODE_CAN == Fblm_GetUpdateMode())
	    	  {
	 	         ClrTpConfirmationFlag();
	    	  }

	         /* Diagnostic session timing */
	         DiagBuffer[kDiagFmtSubparam+1] = (ubyte)((kDiagSessionTimingP2DefaultSession>>8) & 0xFFu);
	         DiagBuffer[kDiagFmtSubparam+2] = (ubyte)((kDiagSessionTimingP2DefaultSession) & 0xFFu);
	         DiagBuffer[kDiagFmtSubparam+3] = (ubyte)((kDiagSessionTimingP2Star>>8) & 0xFFu);
	         DiagBuffer[kDiagFmtSubparam+4] = (ubyte)((kDiagSessionTimingP2Star) & 0xFFu);

	         DiagProcessingDone(kDiagRslDiagnosticSessionControl);

	         if(UPDATE_MODE_CAN == Fblm_GetUpdateMode())
	         {
		         DiagWaitForConfirmation();
	         }

	        /*IPK will response to client after reset*/
	        /*EEPS_RamSessionswitchflag = SessionSwitchFromProgramToDefault;*/
	        /*EEPC_WriteEepromId(EEPC_ID_SESSIONSWITCHFLAG);*/
	         if(UPDATE_MODE_OTA == Fblm_GetUpdateMode())
	         {
	        	 Fblm_DiagInit();
	         }
	         else
	         {
		       /* Call reset application call-back */
		       Fblm_RequestForReset();

	         }
	         /* Code that is placed here will be never reached! */
	      }
	      else /*current active session is extended or default session */
	      {
	          /* Active session is extended or default session */

	          /* Set diagnostic session (default session) */
	          ClrDiagExtendedDiagSession();
	          ClrDiagProgrammingSession();
	          SetDiagDefaultDiagSession();

	          /* Diagnostic session timing */
	          DiagBuffer[kDiagFmtSubparam+1] = (ubyte)((kDiagSessionTimingP2>>8) & 0xFFu);
	          DiagBuffer[kDiagFmtSubparam+2] = (ubyte)((kDiagSessionTimingP2) & 0xFFu);
	          DiagBuffer[kDiagFmtSubparam+3] = (ubyte)((kDiagSessionTimingP2Star>>8) & 0xFFu);
	          DiagBuffer[kDiagFmtSubparam+4] = (ubyte)((kDiagSessionTimingP2Star) & 0xFFu);
	          if(UPDATE_MODE_CAN == Fblm_GetUpdateMode())
	          {
		          ClrTpConfirmationFlag();
	          }
	          DiagProcessingDone(kDiagRslDiagnosticSessionControl);
	      }
   }
   else
   {
	   /*do nothing*/
   }

   /*Always reset internal states */
   /* reset fblstates */
   fblStates &= (kFblStateSuppressPosRspMsg | kFblStateFunctionalRequest | kFblStateDefaultDiagSession\
		   | kFblStateExtendedDiagSession | kFblStateProgrammingSession |kFblStatePreconditionsChecked | kFblStateFingerprintValid);
   fbl2ndStates &= kFbl2ndStateRcrRpInProgress;
   transferRemainder = 0;
   transferType = DOWNLOAD_INIT;
   expectedSequenceCnt  = 0; 

   /* Initialize security module */
   ApplFblSecurityInit();

}

/******************************************************************************
* Name         :  Fblm_EcuReset - 14229 specific
* Called by    :  FblDiagTask
* Preconditions:  None
* Parameters   :  kDiagResetNoResponse (timeout of TesterPresent)
*                 kDiagResetPutResponse (service EcuReset received)
* Return code  :  None
* Description  :  Return to normal message communication
******************************************************************************/
void Fblm_DiagEcuReset(ubyte response)
{
	if (kDiagResetPutResponse == response)/*Need response,from UDS*/
	{
	      /* Check minimum request length */
	      if (DiagDataLength < kDiagRqlEcuReset)
	      {
	         DiagNRCIncorrectMessageLengthOrInvalidFormat();
	         return;
	      }
	      if ( (DiagBuffer[kDiagFmtSubparam] != kDiagSubHardReset)&&
	          ((DiagBuffer[kDiagFmtSubparam] != kDiagSubSoftReset)))
	      {
	         DiagNRCSubFunctionNotSupported();
	         return;
	      }
	      /* Check exact request length */
	      if (DiagDataLength != kDiagRqlEcuReset)
	      {
	         DiagNRCIncorrectMessageLengthOrInvalidFormat();
	         return;
	      }
	      if(UPDATE_MODE_CAN == Fblm_GetUpdateMode())
	      {
			 ClrTpConfirmationFlag();
	      }
	         BootCommand = FBLM_Command_ToAPP;
	         DiagProcessingDone(kDiagRslEcuReset);
	         if(UPDATE_MODE_CAN == Fblm_GetUpdateMode())
	         {
	        	 DiagWaitForConfirmation();
	         }

	}
	else
	{
	      /* Do not transmit response message */
	      DiagSetNoResponse();
	}

#if defined(IMC_FUN_ENABLE)
	   if(UPDATE_MODE_OTA == Fblm_GetUpdateMode())
	   {
		   /*Waiting*/
		   if (0u == DiagResetTimerCounter)
		   {
		     DiagResetTimerCounter = FBLM_RESET_WAITING_TIMEOUT;
		   }
		   else
		   {
		     /*do nothing*/
		   }
	   }
	   else
#endif
	   {
		   /* Call reset application call-back */
		   Fblm_RequestForReset(); 
	   }
}

/******************************************************************************
* Name         :  Fblm_ReadDataByIdentifier
* Called by    :  FblDiagTask
* Preconditions:  None
* Parameters   :  None
* Return code  :  None
* Description  :  ReadDataByIdentifier service checks before entering callback
*                 routine
******************************************************************************/
void Fblm_DiagReadDataByIdentifier(void)
{
   /* Check diagnostic request length */
   /* For ZEEA3.0 BaseTech SWRS 708400 v1. In programmingSession only one dataIdentifier needs to be supported -- GEFDCM-87/GEFDCM-74*/
   if (DiagDataLength != kDiagRqlReadDataByIdentifier)
   {
	  DiagNRCIncorrectMessageLengthOrInvalidFormat();
	  return;
   }
   /* Callback function for RDBI */
   Fblm_ReadDataByIdentifier(&DiagBuffer[kDiagFmtSubparam], DiagDataLength);
}

/******************************************************************************
* Name         :  Fblm_DiagSecurityAccess
* Called by    :  FblDiagTask
* Preconditions:  None
* Parameters   :  None
* Return code  :  None
* Description  :  Performs the security access procedure.
******************************************************************************/
void Fblm_DiagSecurityAccess(void)
{
    ubyte i = 0u;
    ubyte returnCode = kFblFailed;
	/* GEFDCM-379 Server is busy, Need to wait for boot initialization to complete.*/
	if(TRUE != Fblm_GetBootInitDone())
	{
		DiagNRCBusyRepeatRequest();
		return;
	}
   /* Check request length */
   if (DiagDataLength < kDiagRqlSecurityAccessSeed)
   {
	  DiagNRCIncorrectMessageLengthOrInvalidFormat();
	  return;
   }
   switch (DiagBuffer[kDiagFmtSubparam] & kDiagSubSecTypeMask)
   {
		/* -- 14229 specific -- */
		case kDiagSubRequestSeed:
	         /* Check request length */
	         if (DiagDataLength != kDiagRqlSecurityAccessSeed)
	         {
	            DiagNRCIncorrectMessageLengthOrInvalidFormat();
	            return;
	         }
#if defined ( FBL_ENABLE_SEC_ACCESS_DELAY )
         /* Check if security level is locked (delay counter is active) */
         if (GetSecurityAccessDelay() > 0u)/*Means that already invalid access over times*/
         {
            DiagNRCRequiredTimeDelayNotExpired();
            return;
         }
         else
         {
#ifndef Fblm_UNLOCKED_27_01_REQ_SEED_TIMES_NO_LIMIT
            if (GetSecurityKeyAllowed())/*Seed has been generated and sent,allow to verify key*/
            {
              SeedRequestCount++;
              while(1)
              {
                if (FBLM_TM_TRIGGERED == Fblm_LookForWatchdog())
                {
                  returnCode = Fblm_SetSecurityAccessUnlockedL1AttemptCounter(SeedRequestCount);
                  if (kDiagErrorNone == returnCode)
                  {
                    /* Save attempt counter to NVM success */
                    if (SeedRequestCount>=kSecMaxInvalidKeys)/*beyond the number of times*/
                    {
                      DiagNRCExceedNumberOfAttempts();
                      SetSecurityAccessDelay();
                      ClrSecurityKeyAllowed();
                      return;
                    }
                    else
                    {
                      break; /* Save to NVM success */
                    }
                  }
                  else if (kDiagNrcRcrResponsePending == returnCode)
                  {
                    DiagExRCRResponsePending(kNotForceSendResponsePending);
                  }
                  else
                  {
                    /* Save to NVM failed */
                    DiagNRCGeneralProgrammingFailure();
                    return;
                  }
                }
              }
            }
#endif /* Fblm_UNLOCKED_27_01_REQ_SEED_TIMES_NO_LIMIT */
         }
#endif
         /* Init response length for seed */
         DiagDataLength = kDiagRslSecurityAccessSeed;
         /* Check if security level is already active */
         if (GetSecurityUnlock())/*already unlock,all seed are 0*/
         {
            /* ECU already unlocked, send zero-seed */
            for (i = 0; i < kSecSeedLength; i++)
            {
               DiagBuffer[kDiagFmtSeedKeyStart+i] = 0x00;
            }
         }
         else
         {
             /* Generate seed by application function */
             returnCode = Fblm_GenerateSecuritySeed();/*also send response inside*/
             if (returnCode == kFblOk)
             {
                /* Accept security key next */
                SetSecurityKeyAllowed();
             }
             else
             {
                /* Set NRC */
                //FblErrStatSetError(FBL_ERR_SEED_GENERATION_FAILED);/to do/
                DiagNRCConditionsNotCorrect();
                return;
             }
         }
			break;
		case kDiagSubSendKey:
	         /* Check request length */
	         if (DiagDataLength != kDiagRqlSecurityAccessKey)
	         {
	            DiagNRCIncorrectMessageLengthOrInvalidFormat();
	            return;
	         }
	         /* Check for security level and key allowance */
	         /* Sequence of checks is important !          */

	         /* Check if security level is already active */
	         if (GetSecurityUnlock())/*Already unlock*/
	         {
	            DiagNRCRequestSequenceError();
	            return;
	         }
#if defined(FBL_ENABLE_SEC_ACCESS_DELAY)
         /* Check if security level is locked (delay counter is active) */
         if (GetSecurityAccessDelay() > 0u)
         {
            DiagNRCRequestSequenceError();
            return;
         }
#endif
         /* Check if key is allowed */
         if (!GetSecurityKeyAllowed())/*No seed step*/
         {
           DiagNRCRequestSequenceError();
           return;
         }
		  /*Don't response pending while there is no timeout*/
          /*if(UPDATE_MODE_CAN == Fblm_GetUpdateMode())
          {
              DiagExRCRResponsePending(kForceSendResponsePending);
          }*/

         /* Reset sequence ,next will accept seed*/
         ClrSecurityKeyAllowed();
         returnCode = Fblm_SecurityVerifyKey();/*key verification*/
         if (returnCode != kFblOk)   
         {
#if defined( FBL_ENABLE_SEC_ACCESS_DELAY )

           secSendKeyInvalid++; /* Increase counter for invalid tries */
#if 0    /*use Async write*/
           while(1)
           {
             if (FBLM_TM_TRIGGERED == Fblm_LookForWatchdog())
             {
#endif
               returnCode = Fblm_SetSecurityAccessUnlockedL1AttemptCounter(SeedRequestCount);
               if (kDiagErrorNone == returnCode)
               {
                 /* Save attempt counter to NVM success */
                 if (secSendKeyInvalid >= kSecMaxInvalidKeys)
                 {
                   /* Too many invalid security attempts, enable security access delay */
                   SetSecurityAccessDelay();
                   /* Set NRC */
                   DiagNRCExceedNumberOfAttempts();
                   return;
                 }
                 else
                 {
                   /* Set NRC */
                   DiagNRCInvalidKey();
                   return;
                 }
               }
#if 0    /*use Async write*/
               else if (kDiagNrcRcrResponsePending == returnCode)
               {
                 DiagExRCRResponsePending(kNotForceSendResponsePending);
               }
               else
               {
                 /* Save to NVM failed */
                 DiagNRCGeneralProgrammingFailure();
                 return;
               }
             }
           }
#endif

#else
          /* Set NRC */
          DiagNRCInvalidKey();
#endif
         }/*if (returnCode != kFblOk)*/
         else/*Key OK*/
         {
             /* Security access successful, clear security access delay flag */
             SetSecurityUnlock();
#if defined( FBL_ENABLE_SEC_ACCESS_DELAY )
            /* Reset invalid counter */
            secSendKeyInvalid = 0u;
#if 0    /*use Async write*/
            while(1)
            {
              if (FBLM_TM_TRIGGERED == Fblm_LookForWatchdog())
              {
#endif
                returnCode = Fblm_SetSecurityAccessUnlockedL1AttemptCounter(secSendKeyInvalid);
#if 0     /*use Async write*/
                if (kDiagErrorNone == returnCode)
                {
                  /* Save attempt counter to NVM success */
                  break;
                }
                else if (kDiagNrcRcrResponsePending == returnCode)
                {
                  DiagExRCRResponsePending(kNotForceSendResponsePending);
                }
                else
                {
                  /* Save to NVM failed */
                  DiagNRCGeneralProgrammingFailure();
                  return;
                }

              }
            }
#endif
            ClrSecurityAccessDelay();
#endif
            DiagDataLength = kDiagRslSecurityAccessKey;

         }/*end of if Key OK*/
         	break;
		default:
			DiagNRCSubFunctionNotSupported();
			break;
   }
   DiagProcessingDone(DiagDataLength);
}

/******************************************************************************
* Name         :  Fblm_CommunicationControl - 14229 specific
* Called by    :  FblDiagTask()
* Preconditions:  None
* Parameters   :  None
* Return code  :  None
* Description  :  CommunicationControl service function.
******************************************************************************/
void Fblm_DiagCommunicationControl(void)
{
   /* Check minimum request length */
   if (DiagDataLength < kDiagRqlServiceSubfunction)
   {
	  DiagNRCIncorrectMessageLengthOrInvalidFormat();
	  return;
   }
   /* Check control type */
   if (DiagBuffer[kDiagFmtSubparam] > kDiagSubEnableRxAndDisableTx)
   {
	   DiagNRCSubFunctionNotSupported();
	   return;
   }
   /* Check exact request length */
   if (DiagDataLength != kDiagRqlCommunicationControl)
   {
      DiagNRCIncorrectMessageLengthOrInvalidFormat();
      return;
   }
   /* Check communication type */
   if (DiagBuffer[kDiagFmtSubRoutineIdHigh] != kDiagSubNormalCommunication)
   {
      DiagNRCRequestOutOfRange();
      return;
   }

   /* Simply transmit a positive response message with subfunction parameter */
   DiagProcessingDone(kDiagRslCommunicationControl);
}

/******************************************************************************
* Name         :  Fblm_DiagWriteDataByIdentifier
* Called by    :  FblDiagTask
* Preconditions:  Request only accepted after successful security access
*                 procedure
* Parameters   :  None
* Return code  :  None
* Description  :  WriteDataByIdentifier service, handling of fingerprint
*                 and identification data
******************************************************************************/
void Fblm_DiagWriteDataByIdentifier(void)
{
   if (TRUE == Fblm_ActivateSblFlag)
   {
      /* Check request length */
      if (DiagDataLength <= kDiagRqlWriteDataByIdentifier) /*GEFDCM-298 Service 2E Minimun Length Check Incorrect in SBL*/
      {
      DiagNRCIncorrectMessageLengthOrInvalidFormat();
      return;
      }

      /* Callback function for WDBI */
      if (kDiagReturnValidationOk == Fblm_WriteDataByIdentifier(&DiagBuffer[kDiagFmtSubparam], DiagDataLength))
      {
         /* if fingerprint is completely written, set valid */
         SetFingerprintValid();

      }
      else
      {
         /*return kFblOk or kFblFailed*/
      }
      /* Send response */
      if(Fblm_ReadWriteNvmBlockStatus() == FALSE)
      {
         DiagProcessingDone(kDiagRslWriteDataByIdentifier);
      }
   }
   else
   {
      DiagNRCServiceNotSupported();
   }

}

/******************************************************************************
* Name         :  Fblm_SetFingerprintValid
* Called by    :  FblDiagTask()
* Preconditions:  None
* Parameters   :  None
* Return code  :  None
* Description  :  FblTesterPresent service function.
******************************************************************************/
void Fblm_SetFingerprintValid(void)
{
  SetFingerprintValid();
}

/******************************************************************************
* Name         :  Fblm_DiagTesterPresent - 14229 specific
* Called by    :  FblDiagTask()
* Preconditions:  None
* Parameters   :  None
* Return code  :  None
* Description  :  FblTesterPresent service function.
******************************************************************************/
void Fblm_DiagTesterPresent(void)
{
   /* Check minimum request length */
   if (DiagDataLength < kDiagRqlTesterPresent)
   {
	  DiagNRCIncorrectMessageLengthOrInvalidFormat();
	  return;
   }
   /* Check subparameter */
   if (DiagBuffer[kDiagFmtSubparam] != 0x00)
   {
      DiagNRCSubFunctionNotSupported();
      return;
   }
   /* Check exact request length */
   if (DiagDataLength != kDiagRqlTesterPresent)
   {
      DiagNRCIncorrectMessageLengthOrInvalidFormat();
      return;
   }

   DiagProcessingDone(kDiagRslTesterPresent);
}

void Fblm_ChecksumTimesCheck(void)
{
	
}



/******************************************************************************
* Name         :  Fblm_DiagRoutineControl - 14229 specific
* Called by    :  FblDataInd
* Preconditions:  $27 unlock
* Parameters   :  None
* Return code  :  None
* Description  :  RoutineControl service, erase memory and check routine
******************************************************************************/
void Fblm_DiagRoutineControl(void)
{
   /* Two-byte routine identifier */
   ushort routineControlId = 0u;
   static ulong memoryAddress = 0u;
   static ulong memorySize = 0u;
   ubyte progReqFlag = 0u;
   ubyte lengthFormat = 0u;
   ubyte addrFormat = 0u;
   ushort verificationIndex = 0u;/*CRC data start*/

   uint32 StartMemoryAdress = 0;

   /* Read two-byte routineControlId */
   routineControlId = (ushort)((((ushort)DiagBuffer[kDiagFmtSubRoutineIdHigh])<<8) \
                    	| DiagBuffer[kDiagFmtSubRoutineIdLow]);

   /* Check request length */
   if (DiagDataLength < kDiagRqlRoutineControl)
   {
      DiagNRCIncorrectMessageLengthOrInvalidFormat();
      return;
   }

   /* Check if last data transfer succeeded */
   if (GetTransferDataSucceeded())
   {
      /* Last data transfer was successful, check memory is allowed */
      checkMemoryAllowed = kFblOk;
      /* Clear TransferData successful flag */
      ClrTransferDataSucceeded();
   }
   /* -- 14229 specific -- */
   /* GEFDCM-175 Don't need support StopRoutine and RoutineResult*/
   if ((kDiagSubStartRoutine != (DiagBuffer[kDiagFmtSubparam])))
   {
	   DiagNRCSubFunctionNotSupported();
	   return;
   }

#if 1 /*need to be supported on zeekr*/
   /* Check functional addressing                                             *
    * Functional addressing is supported for check prog preconditions only    */
   if (GetFunctionalRequest() && (kDiagSubRequestRoutineResult == DiagBuffer[kDiagFmtSubparam]))
   {
      DiagSetNoResponse();
      DiagProcessingDone(0);
      return;
   }
#endif


    /* RoutineControlID */
    switch(routineControlId)
    {
#ifdef FBL_DISABLE_ROUTINE_CONTROL_ID
    /* -- Write Program Flag routine  -- */
    	case (kDiagRoutineIdWriteProgramFlag):/*Only for OTA,no $27 check*/
    			if (UPDATE_MODE_OTA != Fblm_GetUpdateMode())
    			{
    				DiagNRCGeneralReject();
    				return;
    			}
			  /* Check request length */
			  if ( DiagDataLength != kDiagRqlRoutineControlCheckRoutine)
			  {
				 DiagNRCIncorrectMessageLengthOrInvalidFormat();
				 return;
			  }
			/* Set Reprogramming flag */
			 /*progReqFlag = kEepFblOTAReprogram;*/
			  BootFlag = kEepFblOTAReprogram;
			 if (TRUE/*kFblOk == ApplFblWriteProgReqFlag(&progReqFlag)*/)//to do
			 {
				 if (TRUE/*kFblOk == ApplFblReadProgReqFlag(&progReqFlag)*/)//to do
				 {
	                  if (kEepFblOTAReprogram == BootFlag/*progReqFlag*/)
	                  {
	                    /* Initialize positive response */
	                    DiagBuffer[kDiagFmtRoutineIdDataRecord] = 0x04;
	                    /* Send positive response with routine status */
	                    DiagProcessingDone(kDiagRslRoutineControlWriteProFlag);
	                  }
	                  else
	                  {
	                    /*Write fail*/
	                    DiagNRCGeneralProgrammingFailure();
	                    return;
	                  }
				 }
				 else
				 {
	                  /*Write OK but Read fail,cann't be verify,treat as programming failure,if this happen,need GPU read MCU info to handle when power on*/
	                  DiagNRCGeneralProgrammingFailure();
	                  return;
				 }

			 }
			 else
			 {
				/*Write fail*/
				DiagNRCGeneralProgrammingFailure();
				return;
			 }
    			break;
        /* -- Erase Program Flag routine  -- */
		case (kDiagRoutineIdEraseProgramFlag):/*Only for OTA,no $27 check*/
				if (UPDATE_MODE_OTA != Fblm_GetUpdateMode())
				{
					DiagNRCGeneralReject();
					return;
				}
				/* Check request length */
				if ( DiagDataLength != kDiagRqlRoutineControlCheckRoutine)
				{
				   DiagNRCIncorrectMessageLengthOrInvalidFormat();
				   return;
				}
				/* Clear Reprogramming flag */
				/*progReqFlag = 0x0u;*/
				 BootFlag = 0x0u;
				if (TRUE/*kFblOk == ApplFblWriteProgReqFlag(&progReqFlag)*/)//to do
				 {
					 if (TRUE/*kFblOk == ApplFblReadProgReqFlag(&progReqFlag)*/)//to do
					 {
		                  if (kEepFblOTAReprogram == BootFlag/*progReqFlag*/)
		                  {
		                    /* Initialize positive response */
		                    DiagBuffer[kDiagFmtRoutineIdDataRecord] = 0x04;
		                    /* Send positive response with routine status */
		                    DiagProcessingDone(kDiagRslRoutineControlWriteProFlag);
		                  }
		                  else
		                  {
		                    /*Write fail*/
		                    DiagNRCGeneralProgrammingFailure();
		                    return;
		                  }
					 }
					 else
					 {
		                  /*Write OK but Read fail,cann't be verify,treat as programming failure,if this happen,need GPU read MCU info to handle when power on*/
		                  DiagNRCGeneralProgrammingFailure();
		                  return;
					 }

				 }
				 else
				 {
					/*Write fail*/
					DiagNRCGeneralProgrammingFailure();
					return;
				 }
				break;
#endif
        /* -- Checksum verification -- */
        case (kDiagRoutineIdChecksum):
        		/* Check state flags */
              if(kDiagSubStartRoutine == DiagBuffer[kDiagFmtSubparam])
              {

				if (!GetDiagProgrammingSession())
				{
				   /* Not supported in non-programming session */
				   DiagNRCRequestOutOfRange();
				   return;
				}
				verificationIndex = (ushort)(kDiagFmtSubRoutineIdLow+1);

	            /* Check security access state */
	            if (!GetSecurityUnlock())
	            {
	               DiagNRCSecurityAccessDenied();
	               return; 
	            }
				/* Check request length */
				if ( DiagDataLength < kDiagRqlRoutineControlCheckRoutine)
				{
				   DiagNRCIncorrectMessageLengthOrInvalidFormat();
				   return;
				}

            /*According to the BT,here add CheckMemory attempts limited*/
            if(checkMemoryCnt < FBL_CHECKMEMORY_MAXLIMITED)
            {
               checkMemoryCnt ++;
            }
            else
            {
               checkMemoryAllowed = kFblFailed;/*Not allow to check memory anymore*/
            }


				/* GEFDCM-99 If it has not been erased, it should return 'FBLM_NO_DATA_DOWNLOADED' if it is directly verified. */
				if((ActiveLogicBlock!=FlashDrv_BlockIndex) && (ActiveLogicBlock!=FlashDrvSHA_BlockIndex) && (ActiveLogicBlock!=APPSHA_BlockIndex))
				{
					/* GEFDCM-96  Respectively judging whether over-erasing is performed.*/
					if((ActiveLogicBlock==SWP1SHA_BlockIndex || ActiveLogicBlock==SWP1_BlockIndex) && (!Fblm_SwplBlankCheckFlag))
					{
						DiagBuffer[kDiagFmtSubRoutineIdPar] = 0x10;
						DiagBuffer[kDiagFmtSubRoutineIdDataRecord] = FBLM_NO_DATA_DOWNLOADED;  /*App no data*/
						DiagBuffer[kDiagFmtSubRoutineIdDataRecord2] = 0x00;
						DiagProcessingDone(kDiagRslRoutineControlCheckSumLength);
						return;
					}
					else if((ActiveLogicBlock==APP_BlockIndex) && (!Fblm_AppBlankCheckFlag))
					{
						DiagBuffer[kDiagFmtSubRoutineIdPar] = 0x10;
						DiagBuffer[kDiagFmtSubRoutineIdDataRecord] = FBLM_NO_DATA_DOWNLOADED;  /*App no data*/
						DiagBuffer[kDiagFmtSubRoutineIdDataRecord2] = 0x00;
						DiagProcessingDone(kDiagRslRoutineControlCheckSumLength);
						return;
					}
					else
					{
						/* do noting */
					}
				}

	            /* Check state flags */
	            /*
	               Check if transfer type has a usable value (DOWNLOAD_RAM or DOWNLOAD_FLASH)
	               Otherwise the download check function must not be started
	            */
	            if ((DOWNLOAD_INIT == transferType) || (checkMemoryAllowed == kFblFailed))
	            {
	               DiagBuffer[kDiagFmtSubRoutineIdPar] = 0x10;
	               DiagBuffer[kDiagFmtSubRoutineIdDataRecord] = FBLM_NO_DATA_DOWNLOADED;  /*App no data*/
	               DiagBuffer[kDiagFmtSubRoutineIdDataRecord2] = 0x00;
	               DiagProcessingDone(kDiagRslRoutineControlCheckSumLength);
	               return;
	            }

	            if(UPDATE_MODE_CAN == Fblm_GetUpdateMode())
	            {
	              /* Send response pending => required for gap fill and InitVerification */
	              DiagExRCRResponsePending(kNotForceSendResponsePending);
	            }
               Fblm_DownloadCheck(verificationIndex);/*Maybe NRC and POC inside*/
              }
              else if(kDiagSubRequestRoutineResult == DiagBuffer[kDiagFmtSubparam])
              {
            	DiagProcessingDone(kDiagRslRoutineControlCheckRoutine);
              }


        		break;

                /* -- Activate SBL -- */
         case (kDiagRoutineIdActiveSbl):
            /*GEFDCM-174 Check security access state */
            if (!GetSecurityUnlock())
            {
               DiagNRCSecurityAccessDenied();
               return;
            }
			/* Check request length */
			if ( DiagDataLength < kDiagRqlRoutineControlActiveSbl)
			{
				DiagNRCIncorrectMessageLengthOrInvalidFormat();
				return;
			}
			if(!Fblm_FlashDrvDownloadDone)
			{
				DiagNRCConditionsNotCorrect();
				return;
			}
            StartMemoryAdress = DiagBuffer[kDiagFmtSubRoutineIdDataRecord-1];
            StartMemoryAdress = (StartMemoryAdress<<8U) + DiagBuffer[kDiagFmtSubRoutineIdDataRecord];
            StartMemoryAdress = (StartMemoryAdress<<8U) + DiagBuffer[kDiagFmtSubRoutineIdDataRecord2];
            StartMemoryAdress = (StartMemoryAdress<<8U) + DiagBuffer[kDiagFmtSubRoutineIdDataRecord3];
            /* GEFDCM-266 Need to determine whether the addresses are the same. */
            if((StartMemoryAdress != g_StartAddress))
            {
                DiagNRCRequestOutOfRange();
				return;
            }
            
           if(GetMemDriverInitialized())  /*FlashDriver Verify is OK*/
           {
             Fblm_ActivateSblFlag = TRUE;
             DiagBuffer[kDiagFmtSubRoutineIdPar] = 0x10;
           }
           else
           {
             Fblm_ActivateSblFlag = FALSE;
             DiagBuffer[kDiagFmtSubRoutineIdPar] = 0x11; /*not able to active due to error Signature*/
           }

		     DiagProcessingDone(kDiagRslRoutineControlActiveSblRoutine);
           break;
        /* -- Erase Routine -- */
        case (kDiagRoutineIdEraseMemory):
			/* Check state flags */
		
			if (!GetDiagProgrammingSession())
			{
				/* Not supported in non-programming session */
				DiagNRCRequestOutOfRange();
				return;
			}

			/* Get length and address format from message */
			lengthFormat = (ubyte)((DiagBuffer[kDiagFmtSubRoutineIdPar] & 0xF0 )>>4);
			addrFormat   =  (DiagBuffer[kDiagFmtSubRoutineIdPar] & 0x0F );

			/* STLA no-format */
			lengthFormat = 4;
			addrFormat   =  4;
			/* Check request length */
			if ((kDiagSubStartRoutine == (DiagBuffer[kDiagFmtSubparam])))
			{
                /*Check SBL active*/
                if (FALSE == Fblm_ActivateSblFlag)
                {
                    DiagNRCRequestOutOfRange();/*Need to check Routine 0x0301*/
                    return;
                }
                /* GEFDCM-48 It needs to be called after flashdriver checks the memory. */
				/* GEFDCM-100 FLASH_DRIVER_INIT needs to be initialized after SBL activation. */
               //  FBLM_FlashDriverInit();
            
                if (DiagDataLength != (kDiagRqlRoutineControlEraseRoutine+addrFormat+lengthFormat))
                {
                    DiagNRCIncorrectMessageLengthOrInvalidFormat();
                    return;
                }
                /* Get memoryAddress */
                memoryAddress = Fblm_GetInteger(addrFormat, &(DiagBuffer[kDiagFmtSubRoutineIdPar]));

                /* Check security access state */
                if (!GetSecurityUnlock())
                {
                    DiagNRCSecurityAccessDenied();
                    return;
                }
                /*FBL_ENABLE_ADDR_BASED_DOWNLOAD*/
                /* Maximum supported length is 4, address length must not be 0 */
                if((addrFormat == 0) || (lengthFormat == 0) || (addrFormat > 4) || (lengthFormat > 4))
                {
                    /* ALFI is invalid, send ROOR according to ISO-14229-1.2 */
                    DiagNRCRequestOutOfRange();
                    return;
                }

                /* Get memorySize */
                memorySize = Fblm_GetInteger(lengthFormat, &(DiagBuffer[kDiagFmtSubRoutineIdPar+addrFormat]));

                /*Because GFMM before sending info block(flash driver) didn't erase,but CAN download toll may send erase cmd for every block*/
                if (kFblFailed == Fblm_CheckValidAddressRange(memoryAddress,memorySize))/*By Jianhua*/
                {
					DiagNRCRequestOutOfRange();
					return;
                }

				if (TRUE == Fblm_IsMemoryProtectedArea(memoryAddress,memorySize))/*Must check*/
				{
					DiagNRCRequestOutOfRange();
					return;
				}

				if (FlashDrv_BlockIndex == ActiveLogicBlock)
				{
					DiagNRCRequestSequenceError();/*Need to upgrade FlashDrive*/
					return;
				}
				else if(SWP1_BlockIndex == ActiveLogicBlock)
				{
					/* GEFDCM-52  It is judged whether the erasure has been performed. If the flash has been erased, 
					the NRC78 will not be returned if the erasure is performed again, and a positive response will be returned directly*/
               /* GEFDCM-98  The judgment condition for modifying erasure is fblm_EraseFlag.*/
					if((UPDATE_MODE_CAN == Fblm_GetUpdateMode()) && (!fblm_EraseFlag.SWP1_EraseSucceeded))
					{
						/* Invalidate application before erase procedure */
						DiagExRCRResponsePending(kForceSendResponsePending);
					}
					/*Send positive response directly, due to that SWP1 block don't store in codeflash*/
					DiagBuffer[kDiagFmtRoutineIdDataRecord] = 0x10;
					Fblm_SetProgramStatusInfo(Fblm_SWP1ProgramStatus, Fblm_ProgramStatusInvaild);
					Fblm_SyncWriteNvmData(WDFC_SIZE_ECUSIZE_RDI_PROGRAMMING_INFO,\
							NvMConf_NvMBlockDescriptor_WDFC_ID_ECUID_RDI_PROGRAMMING_INFO, \
							(kDiagRslRoutineControlEraseProFlag), (ubyte *)&WDFS_RamRDIProgInfo);
					fblm_EraseFlag.SWP1_EraseSucceeded = 1;
					return;
				}
				else if (APP_BlockIndex == ActiveLogicBlock)
				{
					Fblm_AppBlankCheckFlag = TRUE;
					if(!fblm_EraseFlag.APP_EraseSucceeded)
					{
						if(UPDATE_MODE_CAN == Fblm_GetUpdateMode())
						{
							/* Invalidate application before erase procedure */
							DiagExRCRResponsePending(kForceSendResponsePending);
						}
						Fblm_RunRoutineIdEraseMemoryFlag = TRUE;
					}
					/* Initialize positive response */
					DiagBuffer[kDiagFmtRoutineIdDataRecord] = 0x10;
					Fblm_EraseMemoryAddress = memoryAddress;
					Fblm_ErasememorySize = memorySize;
					/*Firstly, it will set program status flag, and then erase APP code flash */
					Fblm_SetProgramStatusInfo(Fblm_AppCodeProgramStatus, Fblm_ProgramStatusInvaild);
					Fblm_SyncWriteNvmData(WDFC_SIZE_ECUSIZE_RDI_PROGRAMMING_INFO,\
								NvMConf_NvMBlockDescriptor_WDFC_ID_ECUID_RDI_PROGRAMMING_INFO, \
								(kDiagRslRoutineControlEraseProFlag), (ubyte *)&WDFS_RamRDIProgInfo);
					return;
				}
				else if(FlashDrvSHA_BlockIndex == ActiveLogicBlock) /*Erase VBT */
				{
					if(FALSE == Fblm_ActivateSblFlag)
					{
						memset(Fblm_FlashDrvShaData,0,sizeof(Fblm_FlashDrvShaData));
						DiagBuffer[kDiagFmtRoutineIdDataRecord] = 0x10;
					}
					else
					{
						DiagNRCRequestOutOfRange();
						return; 
					}

				}
				else if(APPSHA_BlockIndex == ActiveLogicBlock)  /*Erase VBT */
				{
					memset(Fblm_AppShaData,0,sizeof(Fblm_AppShaData));
					fblm_EraseFlag.APPSHA_EraseSucceeded = 1;
					DiagBuffer[kDiagFmtRoutineIdDataRecord] = 0x10;
					Fblm_AppFlashSigntureSucFlag = FALSE; /*Clear App Signture successful flag*/
				}
				else if(SWP1SHA_BlockIndex == ActiveLogicBlock) /*Erase VBT */
				{
					Fblm_SwplBlankCheckFlag = TRUE;
					memset(Fblm_Swp1ShaData,0,sizeof(Fblm_Swp1ShaData));
					fblm_EraseFlag.SWP1SHA_EraseSucceeded = 1;
					DiagBuffer[kDiagFmtRoutineIdDataRecord] = 0x10;
				}
				else
				{
					DiagNRCRequestOutOfRange();
					return;
				}
			}
			else if((kDiagSubRequestRoutineResult == (DiagBuffer[kDiagFmtSubparam])))
			{
				;/*Default OK*/
			}

			DiagProcessingDone(kDiagRslRoutineControlEraseProFlag);

			/*to do,Another judge if the memory range OK or not compare with config file?*/
			/*DiagProcessingDone(kDiagRslRoutineControlEraseRoutine);*/ /*Due to write NvM ID */

			break;
#ifdef FBL_DISABLE_ROUTINE_CONTROL_ID
        /* -- Check Programming Preconditions -- */
        case (kDiagRoutineIdCheckProgPreCond):
#if 0 /* SLTA supported in default session,By Honghai */
				if (!GetDiagExtendedDiagSession())
				{
				   /* Not supported in non-extended session */
				   DiagNRCRequestOutOfRange();
				}
#endif

			   /* Check request length */
			   if (DiagDataLength != kDiagRqlRoutineControlCheckProgPreCond)
			   {
				  DiagNRCIncorrectMessageLengthOrInvalidFormat();
				  return;
			   }
			   /* Current fingerprint is handled and no longer used */
			     ClrFingerprintValid();
			   /* set flag for checked preconditions */
			   if (kFblOk == Fblm_CheckProgConditions())
			   {
		         DiagBuffer[kDiagFmtSubRoutineIdPar] = 0x10;
		         DiagBuffer[kDiagFmtSubRoutineIdPar + 1] = 0x01;
                 DiagProcessingDone(kDiagRslRoutineControlCheckPreCond);
                 SetPreconditionsChecked();
			   }
			   else
			   {
				  DiagNRCConditionsNotCorrect();
				  ClrPreconditionsChecked();
			   }

         break;

        case (kDiagRoutineIdCheckProg):
			/* Check state flags */
			if (!GetDiagProgrammingSession())
			{
			   /* Not supported in non-programming session */
			   DiagNRCRequestOutOfRange();
			}
			else
			{

			   /* Check request length */
			   if (DiagDataLength != kDiagRqlRoutineControlCheckProg)
			   {
				  DiagNRCIncorrectMessageLengthOrInvalidFormat();
				  return;
			   }
			   /* Check security access state */
			   if (!GetSecurityUnlock())
			   {
				  DiagNRCSecurityAccessDenied();
				  return;
			   }
			   /* Check state flags */
			   if ((!GetFingerprintValid()) || (!GetMemDriverInitialized()))
			   {
				  DiagNRCConditionsNotCorrect();
				  return;
			   }

			   /* Call function to check programming */
			   DiagBuffer[kDiagFmtSubRoutineIdPar] = 0x01;
			   DiagProcessingDone(kDiagRslRoutineControlCheckRoutine);
			}

        		break;
#endif
        /* -- Check Programming Dependencies -- */
        case (kDiagRoutineIdCheckProgDep):  
			/* Check state flags */ 
			if (!GetDiagProgrammingSession())
			{
			   /* Not supported in non-programming session */
			   DiagNRCRequestOutOfRange();
			}
			else if(!GetSecurityUnlock())
			{
				/* GEFDCM-97:CheckProgDep can only be performed after 27 services are unlocked. */
				DiagNRCSecurityAccessDenied();
			}
			else
			{
			   /* Check request length */
			   if (DiagDataLength != kDiagRqlRoutineControlCheckProgDep)
			   {
				  DiagNRCIncorrectMessageLengthOrInvalidFormat();
				  return;
			   }
#if 0      /*ZCBD-460:No need Security Access */
			   /* Check security access state */
			   if (!GetSecurityUnlock())
			   {
				  DiagNRCSecurityAccessDenied();
				  return;
			   }
#endif

#if 0       /*ZCBD-290*/
			   /* Check state flags */
			   if (/*(!GetFingerprintValid()) || */(!GetMemDriverInitialized()))
			   {
				  DiagNRCConditionsNotCorrect();
				  return;
			   }
#endif

			   /* Call function to check programming dependencies */
			   DiagBuffer[kDiagFmtSubRoutineIdPar] = 0x10;
			   DiagBuffer[kDiagFmtSubRoutineIdDataRecord] = 0;
			   DiagBuffer[kDiagFmtSubRoutineIdDataRecord2] = 0;
			   DiagBuffer[kDiagFmtSubRoutineIdDataRecord3] = 0;
			   DiagBuffer[kDiagFmtSubRoutineIdDataRecord4] = Fblm_CheckProgDependencies();
			   if((TRUE == Fblm_AppProgramStsUpdateFlag) || (TRUE == Fblm_Swp1ProgramStsUpdateFlag)) /*Need to upadte program status*/
			   {
				    Fblm_AppProgramStsUpdateFlag = FALSE;
				    Fblm_Swp1ProgramStsUpdateFlag = FALSE;
			   //   Fblm_AsyncWriteNvmData(WDFC_SIZE_ECUSIZE_RDI_PROGRAMMING_INFO,\
				//                  NvMConf_NvMBlockDescriptor_WDFC_ID_ECUID_RDI_PROGRAMMING_INFO, (ubyte *)&WDFS_RamRDIProgInfo);

			   }
			   DiagProcessingDone(kDiagRoutineIdCheckProgDepRespLength);
			
			}
			break;
#ifdef FBL_DISABLE_ROUTINE_CONTROL_ID
        case (kDiagRoutineIdDisableFailSafeReactionPreCond):
		   DiagProcessingDone(kDiagRslRoutineControlDisableFailSafeReactionRoutine);
        break;
        case kDiagRoutineIdApplicationSoftBlockHash:
        	DiagProcessingDone(kDiagRslRoutineControlApplicationSoftBlockHash);
        	break;
#endif
        default:
            /* Unsupported routine control id: */
            DiagNRCRequestOutOfRange();
        	break;
    }/* switch RoutineControlID */
}

/******************************************************************************
* Name         :  Fblm_DiagRequestDownload - 14229 specific
* Called by    :  FblDiagTask
* Preconditions:  None
* Parameters   :  None
* Return code  :  None
* Description  :  Request download service function
******************************************************************************/
void Fblm_DiagRequestDownload(void)
{
	ulong memorySize = 0u;
	ulong memoryAddress = 0u;
	ubyte lengthFormat = 0u;
	ubyte addrFormat = 0u;

	ubyte dataFormatId = 0u;       /* Combined encryption and compression method   */
	ubyte dataFormatEnc = 0u;      /* Encryption method of transferred data        */
	ubyte dataFormatComp = 0u;     /* Compression method of transferred data       */

    /* Clear TransferData successful flag */
	ClrTransferDataSucceeded();/*Set when TransferExit $37*/

   	/*GEFDCM-267 Minimum length check */
	if (DiagDataLength < kDiagRqlRequestDownload)
	{
		DiagNRCIncorrectMessageLengthOrInvalidFormat();
		return;
	}

	/* Get encryption and compression method */
	dataFormatId = DiagBuffer[kDiagFmtSubparam];
	dataFormatEnc  = (ubyte)((dataFormatId & 0xF0 )>>4);
	dataFormatComp =  (ubyte)(dataFormatId & 0x0F );

	/* Get length and address format from message */
	lengthFormat = (ubyte)((DiagBuffer[kDiagFmtShortRoutineId] & 0xF0 )>>4);
	addrFormat   = (ubyte) (DiagBuffer[kDiagFmtShortRoutineId] & 0x0F );

	/* Check request length */
	if (DiagDataLength != (kDiagRqlRequestDownload+addrFormat+lengthFormat))
	{
		DiagNRCIncorrectMessageLengthOrInvalidFormat();
		return;
	}

	/* Check security access state */
	if (!GetSecurityUnlock())
	{
		DiagNRCSecurityAccessDenied();
		return;
	}

   /* Maximum supported length is 4, address length must no be 0 */
	if((addrFormat == 0) || (lengthFormat == 0) || (addrFormat > 4) || (lengthFormat > 4))
	{
		/* ALFI is invalid, send ROOR according to ISO-14229-1.2 */
		DiagNRCRequestOutOfRange();
		return;
	}

	/* No encrypted data supported */
	if (dataFormatEnc != 0)
	{
		DiagNRCRequestOutOfRange();
		return;
	}

		/* No compressed data supported */
	if (dataFormatComp != 0)
	{
		DiagNRCRequestOutOfRange();
		return;
	}

		/* Get memoryAddress (address based download) or block index */
	memoryAddress = Fblm_GetInteger(addrFormat, &(DiagBuffer[kDiagFmtShortRoutineId+1]));
		/* Get memorySize */
	memorySize = Fblm_GetInteger(lengthFormat, &(DiagBuffer[kDiagFmtShortRoutineId+1+addrFormat]));
	if(memorySize > 45u)
	{
		g_StartAddress = memoryAddress;
		g_StartAddressLength = memorySize;
	}

	if (kFblFailed == Fblm_CheckValidAddressRange(memoryAddress,memorySize))/*Obtain active block index*/
	{
	DiagNRCRequestOutOfRange();
	return;
	}

	if (TRUE == Fblm_IsMemoryProtectedArea(memoryAddress,memorySize))/*Must check*/
	{
		DiagNRCRequestOutOfRange();
		return;
	}

	/* Check security access state */
	if (!GetSecurityUnlock())
	{
		DiagNRCSecurityAccessDenied();
		return;
	}

    /*If address is valid*/
    if (FlashDrv_BlockIndex == ActiveLogicBlock)
    {
    	transferType = DOWNLOAD_RAM;
    }
    else if(FlashDrvSHA_BlockIndex == ActiveLogicBlock)
    {
    	transferType = DOWNLOAD_FLASHDRVSHA;
    }
    else if(APP_BlockIndex == ActiveLogicBlock)
    {
      if (FALSE == Fblm_ActivateSblFlag)
	  {
    	DiagNRCRequestOutOfRange();/*Check whether download flashdrive done */
	  	return;
	  }
      transferType = DOWNLOAD_FLASH;
    }
    else if(APPSHA_BlockIndex == ActiveLogicBlock)
    {
      if (FALSE == Fblm_ActivateSblFlag)
  	  {
    	DiagNRCRequestOutOfRange();/*Check whether download flashdrive done */
  	  	return;
  	  }
      transferType = DOWNLOAD_APPSHA;
    }
    else if(SWP1_BlockIndex == ActiveLogicBlock)
    {
      if (FALSE == Fblm_ActivateSblFlag)
  	  {
    	DiagNRCRequestOutOfRange();/*Check whether download flashdrive done */
  	  	return;
  	  }
      transferType = DOWNLOAD_SWP1;
    }
    else if(SWP1SHA_BlockIndex == ActiveLogicBlock)
    {
		if (FALSE == Fblm_ActivateSblFlag)
		{
			DiagNRCRequestOutOfRange();/*Check whether download flashdrive done */
			return;
		}
		transferType = DOWNLOAD_SWP1SHA;
    }

    /* Init expected sequence counter for TransferData */
    expectedSequenceCnt = kDiagInitSequenceNum;
    /* Init current sequence counter for TransferData */
    currentSequenceCnt = kDiagInitSequenceNum;

    /* Initialize the number of retries allowed for a specific block in TransferData */
    retryCounter = kDiagInitDataRetries;

    /* Check state flags and request download cycle */
    if (/*(!GetFingerprintValid()) ||*/ (GetTransferDataAllowed()))
    {
		DiagNRCConditionsNotCorrect();
		return;
    }

    /* Initialize internal states */
    ClrTransferDataAllowed();/*allow after $34*/

    /* Get length from request */
    transferRemainder = memorySize;

    if (DOWNLOAD_FLASH == transferType)
    {
        transferAddress = memoryAddress;
        /* Check state flags */
        if ((!GetMemDriverInitialized()) || (!GetEraseSucceeded()))/*Set MemDriverInitialized when info block CRC check OK*/
        {
           DiagNRCUploadDownloadNotAccepted();
           return;
        }
        /*need more check? to do*/

    }/*DOWNLOAD_FLASH*/
    else if(DOWNLOAD_RAM == transferType)
    {
    	if(TRUE == Fblm_ActivateSblFlag)
    	{
          DiagNRCUploadDownloadNotAccepted();
          return;
    	}
        /* Existing flashCode is no longer valid */
        ClrMemDriverInitialized();
        /* Get Address from array */
        transferAddress = (FBL_ADDR_TYPE)FBLM_FLASHDRV_STARTADDRESS; /*Store into a buffer*/

        if (memorySize > FlashDrv_BlockSize)
        {
            DiagNRCRequestOutOfRange();
            return;
        }

    }/*DOWNLOAD_RAM*/
    else if(DOWNLOAD_FLASHDRVSHA == transferType)
    {
      Fblm_AppVerificationBlockTableLength = 0;
      transferShaAddress = Fblm_FlashDrvShaData;
      if (memorySize > FlashDrvSHA_BlockSize)
      {
          DiagNRCRequestOutOfRange();
          return;
      }
    }/*DOWNLOAD_FlashDrv SHA*/
    else if(DOWNLOAD_APPSHA == transferType)
    {
      Fblm_AppVerificationBlockTableLength = 0;
      transferShaAddress = Fblm_AppShaData;
      /* Check state flags */
      if (!fblm_EraseFlag.APPSHA_EraseSucceeded)/*Set MemDriverInitialized when info block CRC check OK*/
      {
         DiagNRCUploadDownloadNotAccepted();
         return;
      }
      
      if (memorySize > APPSHA_BlockSize)
      {
          DiagNRCRequestOutOfRange();
          return;
      }
    }/*DOWNLOAD_APP SHA*/
    else if(DOWNLOAD_SWP1 == transferType)
    {
      /* Get Address from array */
      transferAddress = (FBL_ADDR_TYPE)FBLM_Swp1Code; /*Store into a buffer*/

      /* Check state flags */
      if (!fblm_EraseFlag.SWP1_EraseSucceeded)/*Set MemDriverInitialized when info block CRC check OK*/
      {
         DiagNRCUploadDownloadNotAccepted();
         return;
      }

      if (memorySize > FBLM_SWP1_SIZE)
      {
        DiagNRCRequestOutOfRange();
        return;
      }
    } /*DOWNLOAD_SWP1*/
    else if(DOWNLOAD_SWP1SHA == transferType)
    {
      Fblm_AppVerificationBlockTableLength = 0;
      transferShaAddress = Fblm_Swp1ShaData;
      /* Check state flags */
      if (!fblm_EraseFlag.SWP1SHA_EraseSucceeded)/*Set MemDriverInitialized when info block CRC check OK*/
      {
         DiagNRCUploadDownloadNotAccepted();
         return;
      }
      
      if (memorySize > FBLM_VBT_SIZE)
      {
          DiagNRCRequestOutOfRange();
          return;
      }
    }/*DOWNLOAD_SWP1 SHA*/

    /* Allow now reception of TransferData($36) */
    SetTransferDataAllowed();

    /* Prepare response: Transmit always 2 bytes (high nibble) */
    DiagBuffer[kDiagFmtSubparam] = 2<<4;

    if (UPDATE_MODE_CAN == Fblm_GetUpdateMode())
    {
      DiagBuffer[2] = (ubyte)(((FBL_DIAG_CAN_SEGMENT_SIZE + 2) >> 8) & 0x00FFu);
      DiagBuffer[3] = (ubyte)((FBL_DIAG_CAN_SEGMENT_SIZE + 2) & 0x00FFu);
    }
    else
    {
        /* For all segment size values up to 0x1FF: No mask operation necessary */
        DiagBuffer[2] = (ubyte)(((FBL_DIAG_OTA_SEGMENT_SIZE + 2) >> 8) & 0x00FFu);
        DiagBuffer[3] = (ubyte)((FBL_DIAG_OTA_SEGMENT_SIZE + 2) & 0x00FFu);
    }
    if(DOWNLOAD_RAM == transferType)
    {
       DiagProcessingDone(kDiagRslRequestDownload+2);
    }
    else
    {
      DiagProcessingDone(kDiagRslRequestDownload+2);
    }


}
/******************************************************************************
* Name         :  Fblm_DiagTransferDownload - 14229 specific
* Called by    :  FblDiagTask
* Preconditions:  TransferData must be enabled by RequestDownload service
* Parameters   :  None
* Return code  :  None
* Description  :  TransferData service function;
******************************************************************************/
void Fblm_DiagTransferDownload(void)
{
  ushort transferDataLength = 0u;
  ubyte *dataBuffer = NULL;

  /* Check request length */
  if (DiagDataLength < kDiagRqlTransferData)
  {
     DiagNRCIncorrectMessageLengthOrInvalidFormat();
     return;
  }

  /* Check security access state */
  if (!GetSecurityUnlock())
  {
     DiagNRCRequestSequenceError();
     return;
  }

  if (!GetTransferDataAllowed())
  {
     DiagNRCRequestSequenceError();
     return;
  }

  /* Check if the requested sequence number is expected */
  if (DiagBuffer[kDiagFmtSubparam] != expectedSequenceCnt)
  {/*Not the expected*/
      /* Check if sequence number corresponds to a retransmission of the last message */
      if (DiagBuffer[kDiagFmtSequenceCnt] == currentSequenceCnt)
      {
          /* Repetition of last transferData request */
          /* Simply send a positive response without loading data to memory */
          DiagProcessingDone(kDiagRslTransferData);
          return;
      }
      else/*Other Sequence number is for a retry,support or not is up to Tester*/
      {
          /* Handle the retries here */
          /* If max number of retries exceeded */
          if (retryCounter == 0u)
          {
             ClrTransferDataAllowed();
             DiagNRCTransferDataSuspended();
             return;
          }
          else
          {
             retryCounter--;
          }
          /* Send a WrongSequenceError */
          DiagNRCWrongBlockSequenceCounter();
          return;
      }
  }
  else
  {/*as expected*/
      /* Check if anymore data is expected */
      if (transferRemainder == 0u)
      {
         /* Send NRC RequestSequenceError and abort, no more data expected! */
         DiagNRCRequestSequenceError();
         ClrTransferDataAllowed();
         return;
      }
      /* Re-initialize retry counter in case a correct sequence number was received */
      retryCounter = kDiagInitDataRetries;
  }

  /* Memorize current counter */
  currentSequenceCnt = expectedSequenceCnt;

  /* Sequence counter value of next transferData request */
  expectedSequenceCnt++;

  /* Length without sequence counter byte */
  transferDataLength = DiagDataLength-1;

  /* Set buffer for flash data to transferred data */
  dataBuffer = &DiagBuffer[kDiagFmtDataOffset];

  /*transferDataLength should be <= SEGMENT_SIZE*/
  if(UPDATE_MODE_CAN == Fblm_GetUpdateMode())
  {
	  if (transferDataLength > FBL_DIAG_CAN_SEGMENT_SIZE)
	  {
	     /* Requested transfer length is larger than indicated data length */
	     DiagNRCIncorrectMessageLengthOrInvalidFormat();
	     ClrTransferDataAllowed();
	     return;
	  }
  }
  else
  {
	  if (transferDataLength > FBL_DIAG_OTA_SEGMENT_SIZE)
	  {
	     /* Requested transfer length is larger than indicated data length */
	     DiagNRCIncorrectMessageLengthOrInvalidFormat();
	     ClrTransferDataAllowed();
	     return;
	  }
  }

   //copy diag transfer data to backup data buffer
   
   if(DOWNLOAD_FLASH == transferType)
   {
      memcpy(&server36_dataBuffer[outof_512_size],&DiagBuffer[kDiagFmtDataOffset],transferDataLength);
      transferDataLength = transferDataLength + outof_512_size;
      //get more then 3072 and less than 512 data lenth
      outof_512_size = transferDataLength%FBL_MEMORY_WRITE_512BYTE;

      transferDataLength = transferDataLength - outof_512_size;
   }   


  if (transferDataLength > transferRemainder)
  {
     transferRemainder = 0u;
     /* Send NRC RequestSequenceError and abort, more data than expected! */
     DiagNRCRequestSequenceError();
     ClrTransferDataAllowed();
     return;
  }

  /* Transfer remainder is a counter for uncompressed (transmission) data */
  transferRemainder -= transferDataLength;

  if(UPDATE_MODE_CAN == Fblm_GetUpdateMode())
  {
	/* Invalidate application before erase procedure */
	DiagExRCRResponsePending(kForceSendResponsePending);
  }

  if (DOWNLOAD_RAM == transferType)
  {
      if (transferDataLength > FlashDrv_BlockSize)
      {
          DiagNRCRequestOutOfRange();
          return;
      }
      /*NumberOfBlockLength must > FlashDrv_BlockSize*/
	  (void)memcpy((void*)transferAddress, (void*)dataBuffer, transferDataLength);/*Info block here,only transfer once,otherwise will error*/
	  transferAddress += transferDataLength;
	  Fblm_FlashDrvDownloadDone = TRUE;
  }
  else if((DOWNLOAD_FLASH == transferType) && (transferDataLength >= FBL_MEMORY_WRITE_512BYTE))
  {
      /* GEFDCM-98 If 36 services are performed, clear the flag. */
	   fblm_EraseFlag.APP_EraseSucceeded = 0;
      if (kFblOk != Fblm_WriteFlash(transferAddress,server36_dataBuffer,transferDataLength))
      {
         /*Programming failure occurred*/
         DiagNRCGeneralProgrammingFailure();
         ClrTransferDataAllowed();
         return;
      }
      transferAddress += transferDataLength;
      memcpy(&server36_dataBuffer[0],&server36_dataBuffer[transferDataLength],outof_512_size);
      memset(&server36_dataBuffer[outof_512_size],0,(sizeof(server36_dataBuffer)-outof_512_size));
  }
  else if(DOWNLOAD_FLASHDRVSHA == transferType)
  {
    if (transferDataLength > FlashDrvSHA_BlockSize)
    {
      DiagNRCRequestOutOfRange();
      return;
    }
    Fblm_AppVerificationBlockTableLength += transferDataLength;
    /*NumberOfBlockLength must > FlashDrv_BlockSize*/
	(void)memcpy(transferShaAddress, (void*)dataBuffer, transferDataLength);/*Transfer Flash Drv SHA data */
	transferShaAddress += transferDataLength;
  }
  else if(DOWNLOAD_APPSHA == transferType)
  {
    if (transferDataLength > APPSHA_BlockSize)
    {
        DiagNRCRequestOutOfRange();
        return;
    }
    /*NumberOfBlockLength must > FlashDrv_BlockSize*/
    Fblm_AppVerificationBlockTableLength += transferDataLength;
    (void)memcpy(transferShaAddress, (void*)dataBuffer, transferDataLength);/*Transfer APP SHA data */
    transferShaAddress += transferDataLength;
  }
  else if(DOWNLOAD_SWP1 == transferType)
  {
    /* GEFDCM-98 If 36 services are performed, clear the flag. */
	 fblm_EraseFlag.SWP1_EraseSucceeded = 0;
    if (transferDataLength > FBLM_SWP1_SIZE)
    {
      DiagNRCRequestOutOfRange();
      return;
    }
    /*NumberOfBlockLength must > FlashDrv_BlockSize*/
	(void)memcpy((void*)transferAddress, (void*)dataBuffer, transferDataLength);/*Info block here,only transfer once,otherwise will error*/
	transferAddress += transferDataLength;
  }
  else if(DOWNLOAD_SWP1SHA == transferType)
  {
    if (transferDataLength > APPSHA_BlockSize)
    {
        DiagNRCRequestOutOfRange();
        return;
    }
    /*NumberOfBlockLength must > FlashDrv_BlockSize*/
    Fblm_AppVerificationBlockTableLength += transferDataLength;
    (void)memcpy(transferShaAddress, (void*)dataBuffer, transferDataLength);/*Transfer APP SHA data */
    transferShaAddress += transferDataLength;
  }

  DiagProcessingDone(kDiagRslTransferData);

}

/******************************************************************************
* Name         :  Fblm_DiagRequestTransferExit - 14229 specific
* Called by    :  FblDiagTask
* Preconditions:  None
* Parameters   :  None
* Return code  :  None
* Description  :  RequestTransferExit service function
******************************************************************************/
void Fblm_DiagRequestTransferExit(void)
{
   /* Check request length */
   if (DiagDataLength != kDiagRqlRequestTransferExit)
   {
	  DiagNRCIncorrectMessageLengthOrInvalidFormat();
	  ClrTransferDataAllowed();
	  return;
   }
   /* Check security access state */
   if (!GetSecurityUnlock())
   {
      DiagNRCRequestSequenceError();
      return;
   }
   /* This service is allowed only if the transfer data request is permitted */
   if (!GetTransferDataAllowed())
   {
      DiagNRCRequestSequenceError();
      return;
   }
   /* Reset internal states */
   ClrTransferDataAllowed();

   /* This service is allowed after all bytes of the segment are transfered */
   if (0u != transferRemainder)
   {
      DiagNRCRequestSequenceError();
      return;
   }
   /* TransferData was successful, set state flag */
   SetTransferDataSucceeded();
   /*Restart/Release checkMemoryCnt if new data will be downloaded*/
   if (0u != checkMemoryCnt)
   {
      checkMemoryCnt = 0u;
   }
   DiagProcessingDone(kDiagRslRequestTransferExit);

}
/******************************************************************************
* Name         :  Fblm_ControlDTCSetting - 14229 specific
* Called by    :  FblDiagTask()
* Preconditions:  None
* Parameters   :  None
* Return code  :  None
* Description  :  ControlDTCSetting service function.
******************************************************************************/
void Fblm_DiagControlDTCSetting(void)
{
   /* Check minimum request length */
   if (DiagDataLength < kDiagRqlServiceSubfunction)
   {
	  DiagNRCIncorrectMessageLengthOrInvalidFormat();
	  return;
   }
   /* Check DTCSettingType subfunction*/
   if (   (DiagBuffer[kDiagFmtSubparam] != kDiagSubDtcOn) \
       && (DiagBuffer[kDiagFmtSubparam] != kDiagSubDtcOff))
   {
      DiagNRCSubFunctionNotSupported();
      return;
   }

   /* Simply transmit a positive response message with subfunction parameter */
   DiagProcessingDone(kDiagRslControlDTCSetting);
}

/******************************************************************************
* Name         :  Fblm_GetTransferType - 14229 specific
* Called by    :  no restrict
* Preconditions:  None
* Parameters   :  None
* Return code  :  None
* Description  :  Return current transfer type.
******************************************************************************/
ubyte Fblm_GetTransferType(void)
{
	return transferType;
}


/******************************************************************************
* Name         :  FblDiagDataInd - 14229 specific
* Called by    :  Transport Layer
* Preconditions:  None
* Parameters   :  Number of received bytes
* Return code  :  None
* Description  :  Indication function for a transport layer message
******************************************************************************/
#if defined ( TP_TYPE_MULTI_DYNAMIC_NORMAL_ADDRESSING )
void FblDataInd(vuint8 tpChannel, tTpDataType rxDataLen )
#else
void FblDataInd( tTpDataType rxDataLen )
#endif
{
   DiagClrError();
   diagResponseFlag = kDiagPutResponse;

#if defined( FBL_ENABLE_SLEEPMODE )
   FblSleepCounterReload();
#endif

   SetP2Timer(kFblDiagTimeP2);   /* Reset P2 timer (initial timing) */

#if !defined(TP_ENABLE_DIAG_SERVICE_QUEUE) /*When use Queue , don't use it length*/
   DiagDataLength = rxDataLen-1;
#endif

#if defined(TP_ENABLE_DIAG_SERVICE_QUEUE)
   DiagQuePhyReqInd(Appl_QueNumber);
#else
   SetDiagIndication();
#endif

   /* Initialize security seed */
   (void)ApplFblSecurityInit();
}

#if defined(TP_ENABLE_DIAG_SERVICE_QUEUE)
/******************************************************************************
* Name         :  FblDiagDataInd - 14229 specific
* Called by    :  Transport Layer
* Preconditions:  None
* Parameters   :  Number of received bytes
* Return code  :  None
* Description  :  Indication function for a transport layer message
******************************************************************************/
#if defined ( TP_TYPE_MULTI_DYNAMIC_NORMAL_ADDRESSING )
void FblFuncDataInd(vuint8 tpChannel, tTpDataType rxDataLen )
#else
void FblDataInd( tTpDataType rxDataLen )
#endif
{
   DiagClrError();
   diagResponseFlag = kDiagPutResponse;

#if defined( FBL_ENABLE_SLEEPMODE )
   FblSleepCounterReload();
#endif

   SetP2Timer(kFblDiagTimeP2);   /* Reset P2 timer (initial timing) */

   DiagDataLength = rxDataLen-1;

//#if defined(TP_ENABLE_DIAG_SERVICE_QUEUE)
   //DiagQueFuncReqInd(Appl_QueNumber);
//#elsedd
   SetDiagIndication();
//#endif
   /* Initialize security seed */
   (void)ApplFblSecurityInit();
}
#endif


# if  defined ( TP_ENABLE_NORMAL_ADDRESSING ) && \
     !defined ( TP_TYPE_MULTI_DYNAMIC_NORMAL_ADDRESSING )
# else
/******************************************************************************
* Name         :  FblFuncReqInd - 14229 specific
* Called by    :  TPMC
* Preconditions:  None
* Parameters   :  Number of received bytes
* Return code  :  None
* Description  :  Indication function for a functional transport layer message
******************************************************************************/
void TP_API_CALLBACK_TYPE FblFuncReqInd( vuint16 dataLength )
{
#  if defined ( TP_TYPE_MULTI_DYNAMIC_NORMAL_ADDRESSING )
#if !defined(TP_ENABLE_DIAG_SERVICE_QUEUE)  /*Need to deal with function req and physics req*/
   TpFuncSetResponse(0);
#endif
#if defined(TP_ENABLE_DIAG_SERVICE_QUEUE)
   FblFuncDataInd(0, dataLength);  /*when it is function address request*/
#else
   FblDataInd(0, dataLength);
#endif

#  else
#   if defined ( TP_ENABLE_EXTENDED_ADDRESSING )
#   else
   TpFuncSetResponse();
#   endif
   FblDataInd(dataLength);
#  endif
}
# endif  /* TP_ENABLE_NORMAL_ADDRESSING && !TP_TYPE_MULTI_DYNAMIC_NORMAL_ADDRESSING */



/******************************************************************************
* Name         :  FblTpRxGetBuffer - 14229 specific
* Called by    :  TPMC
* Preconditions:  None
* Parameters   :  Requested buffer size
* Return code  :  Pointer to data buffer
* Description  :  This function is called by the transport layer precopy
*                 function and returns a pointer to the diagnostic buffer
******************************************************************************/
# if defined ( TP_TYPE_MULTI_DYNAMIC_NORMAL_ADDRESSING )
# if defined(TP_ENABLE_DIAG_SERVICE_QUEUE)
vuint8* FblTpRxGetBuffer( vuint8 tpChannel, vuint16 dataLength, vuint8 *queueNum)
#else
vuint8* FblTpRxGetBuffer( vuint8 tpChannel, vuint16 dataLength )
#endif/*TP_ENABLE_DIAG_SERVICE_QUEUE*/

# else
vuint8* FblTpRxGetBuffer( vuint16 dataLength )
# endif /*TP_TYPE_MULTI_DYNAMIC_NORMAL_ADDRESSING*/
{
   vuint8 index = 0u;
   /* Check if buffer is locked */
   if (tpBufferLocked == 0  && ((TRUE == K_diagQueBufferState[0].bufferIsFree)  \
		                   ||   (TRUE == K_diagQueBufferState[1].bufferIsFree)))
   {
      tpBufferLocked = 1;

#if defined(TP_ENABLE_DIAG_SERVICE_QUEUE)
	 for(index = 0u; index < kDiagQueBufferNum; index++)
	  {	
	    if(K_diagQueBufferState[index].bufferIsFree == TRUE)
	    {
	      K_diagQueBufferState[index].dataLength = dataLength;
	      K_diagQueBufferState[index].bufferIsFree = FALSE;
	      DiagGetSwapQueBufSts(index).waitReqTime = WaitNextReqTime;
	      K_diagQueBufferState[index].FunctionReq = FALSE;
	      *queueNum = index;
	      //ptr = g_descBuffer[index];
	      break;
	    }
	  }
#endif

#  if defined ( TP_TYPE_MULTI_DYNAMIC_NORMAL_ADDRESSING )
#if defined(CAN_STD_ID_USED)
#if !defined(TP_ENABLE_DIAG_SERVICE_QUEUE)
      TpRxSetTransmitID(tpChannel, CAN_TP_TXID);  /* Set Tx ID for this request */
#endif

#elif defined(CAN_EXT_ID_USED)
      TpRxSetTransmitExtID(tpChannel, CAN_TP_TXID);
#endif
     TpRxSetConnectionNumber(tpChannel, 0);  /* Set this connection to #0 */
#if !defined(TP_ENABLE_DIAG_SERVICE_QUEUE)
      TpTxSetResponse(0, 0);   /* Load addressing information into tx structure */
#endif

#  else
      TpTxSetResponse();   /* Load addressing information into tx structure */
#  endif

#  if defined (TP_ENABLE_EXTENDED_ADDRESSING)
#  else
#if !defined(TP_ENABLE_DIAG_SERVICE_QUEUE)  /*take on request update function*/
      ClrFunctionalRequest(); /* Clear functional request indication */
#endif
#  endif

      /* Halts the tester-present timer while receiving a diagnostic message */
      StopTesterTimeout();

      /* Indicate an ongoing service processing */
      SetServiceInProgress();
#if defined(TP_ENABLE_DIAG_SERVICE_QUEUE)
     // return &DiagBuffer[(*queueNum) * (FBL_DIAG_BUFFER_LENGTH+kDiagBufferAlign)];
      return &DiagBufPtr[(*queueNum) * (FBL_DIAG_BUFFER_LENGTH+kDiagBufferAlign)];
#else
      return DiagBuffer;
#endif
   }
   else
   {
      return 0;
   }
}
# if defined(TP_ENABLE_DIAG_SERVICE_QUEUE)
/*******************************************************************************
* NAME:              FblRespRequestProcess
*
* CALLED BY:         Transport layer
* PRECONDITIONS:
*
* DESCRIPTION:       Rx path for physical requests.
*                    Function name must be entered to the CANgen OSEK-TP Options
*                    dialog in the fields "RxIndication".
*******************************************************************************/
static void FblRespRequestProcess(void)
{
  if(0 != FblRespRequestTime)
  {
    FblRespRequestTime--;
  }

  if((TRUE == FblRespRequest) &&  (0 == (FblRespRequestTime)))
  {
	FblRespRequest = FALSE;
    DiagResponseProcessor(FblRespRequestLen);
  }
}
/*******************************************************************************
* NAME:              Fblm_StartTpStateTask
*
* CALLED BY:         Transport layer
* PRECONDITIONS:
*
* DESCRIPTION:       Rx path for physical requests.
*                    Function name must be entered to the CANgen OSEK-TP Options
*                    dialog in the fields "RxIndication".
*******************************************************************************/
static void Fblm_StartTpStateTask(void)
{
  Fblm_StartTpStateTaskFlag = TRUE;
}
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
void Fblm_StopTpStateTask(void)
{
  Fblm_StartTpStateTaskFlag = FALSE;
}
/*******************************************************************************
* NAME:              Fblm_GetTpStateTaskFlag
*
* CALLED BY:         Transport layer
* PRECONDITIONS:
*
* DESCRIPTION:       Rx path for physical requests.
*                    Function name must be entered to the CANgen OSEK-TP Options
*                    dialog in the fields "RxIndication".
*******************************************************************************/
static uint8 Fblm_GetTpStateTaskFlag(void)
{
  return Fblm_StartTpStateTaskFlag;
}

/*******************************************************************************
* NAME:              DiagQuePhyReqInd
*
* CALLED BY:         Transport layer
* PRECONDITIONS:
*
* DESCRIPTION:       Rx path for physical requests.
*                    Function name must be entered to the CANgen OSEK-TP Options
*                    dialog in the fields "RxIndication".
*******************************************************************************/
void DiagQuePhyReqInd( vuint8 queueNum)
{
  K_diagPhyReqStep++;
  K_diagQueBufferState[queueNum].phyReqInd = TRUE;
  K_diagQueBufferState[queueNum].reqStep = K_diagPhyReqStep;
  K_diagQueBufferState[queueNum].waitReqTime = WaitNextReqTime;
  K_diagQueBufferState[queueNum].FunctionReq = FALSE;
  tpBufferLocked = 0;
  TpRxResetChannel(0);//TpRxResetChannel(TP_CHANNEL_RX_PARAM_ONLY);
}

/*******************************************************************************
* NAME:              DiagQuePhyReqInd
*
* CALLED BY:         Transport layer
* PRECONDITIONS:
*
* DESCRIPTION:       Rx path for physical requests.
*                    Function name must be entered to the CANgen OSEK-TP Options
*                    dialog in the fields "RxIndication".
*******************************************************************************/
void DiagQueFuncReqInd( vuint8 queueNum)
{
  K_diagPhyReqStep++;
  K_diagQueBufferState[queueNum].phyReqInd = TRUE;
  K_diagQueBufferState[queueNum].reqStep = K_diagPhyReqStep;
  K_diagQueBufferState[queueNum].waitReqTime = WaitNextReqTime;
  K_diagQueBufferState[queueNum].FunctionReq = TRUE;
  tpBufferLocked = 0;
  TpRxResetChannel(0);//TpRxResetChannel(TP_CHANNEL_RX_PARAM_ONLY);
}


/*******************************************************************************
* NAME:              FblDiagUpdateRequest
*
* CALLED BY:         DescTask
* PRECONDITIONS:
*
* DESCRIPTION:       Update diag request to desc ptr.
*
*******************************************************************************/
static void FblDiagUpdateRequest(void)
{
  vuint8 queNumber = 0u;
  for(queNumber = 0u; queNumber < kDiagQueBufferNum; queNumber++)
  {

    if((K_diagQueBufferState[queNumber].dataLength != 0u) && (FALSE == DiagGetSwapQueBufSts(queNumber).requestProcess)
        && (TRUE == K_diagQueBufferState[queNumber].phyReqInd)
        /*&& ((0u == DiagGetSwapQueBufSts(queNumber).dataLength) || (TRUE == DiagGetSwapQueBufSts(queNumber).phyReqInd))*/
        /*to full deplex*/)
    {
        if((TRUE == K_diagQueBufferState[queNumber].phyReqInd) && (TRUE == DiagGetSwapQueBufSts(queNumber).phyReqInd))
        {
          if(K_diagQueBufferState[queNumber].reqStep < DiagGetSwapQueBufSts(queNumber).reqStep)
          {
            /*queNumber = queNumber;*/
          }
          else
          {
            queNumber = g_diagQueSwap[queNumber];
          }
        }
        if(0 != K_diagQueBufferState[queNumber].waitReqTime)
        {
          K_diagQueBufferState[queNumber].waitReqTime--;
        }
        if((0 == K_diagQueBufferState[queNumber].waitReqTime)|| \
            ((TRUE == K_diagQueBufferState[queNumber].phyReqInd) && \
            (TRUE == DiagGetSwapQueBufSts(queNumber).phyReqInd))
          || ((TRUE == Fblm_BootMangerRunningSts)    /* when in BOOT manger,can response for functional request quickly */
               && (TRUE == K_diagQueBufferState[queNumber].FunctionReq)))
        {
          K_diagQueBufferState[queNumber].waitReqTime = 0;
          DiagBuffer = (4-(((ulong)&basicDiagBuffer[queNumber][0])%4))+ &basicDiagBuffer[queNumber][0];
          // = FblTpRxGetBuffer(0,K_diagQueBufferState[queNumber].dataLength,queNumber);   //DescGetBuffer(K_diagQueBufferState[queNumber].dataLength,queNumber);
          SetDiagIndication();//DescPhysReqInd(K_diagQueBufferState[queNumber].dataLength);
          DiagDataLength = K_diagQueBufferState[queNumber].dataLength - 1;
          K_diagQueBufferState[queNumber].dataLength = 0u;
          K_diagQueBufferState[queNumber].phyReqInd = FALSE;
          K_diagQueBufferState[queNumber].requestProcess = TRUE;
          if(TRUE == K_diagQueBufferState[queNumber].FunctionReq)
          {
            /* Functional request indication */
            SetFunctionalRequest();
            TpFuncSetResponse(0);
          }
          else
          {
        	/*Physics request indication */
            ClrFunctionalRequest();
            TpTxSetResponse(0, 0);   /* Load addressing information into tx structure */
          }
        }
        break;
    }


  }
}

#endif

/******************************************************************************
* Name         :  FblFuncGetBuffer - 14229 specific
* Called by    :  TPMC
* Preconditions:  None
* Parameters   :  Requested buffer size
* Return code  :  Pointer to data buffer
* Description  :  This function is called by the transport layer precopy
*                 function in case of a function request and returns a pointer
*                 to the diagnostic buffer
******************************************************************************/
vuint8* TP_API_CALLBACK_TYPE FblFuncGetBuffer( vuint16 dataLength )
{
   TP_MEMORY_MODEL_DATA vuint8* localBuffer;

   /* Check if buffer is locked */
   if (tpBufferLocked == 0)
   {
      localBuffer = (vuint8 *)TpFuncGetCanBuffer();

      /* Check for TesterPresent request */
      if (localBuffer[0] == kDiagSidTesterPresent)
      {
         if ( (dataLength == (kDiagRqlTesterPresent+1)) && \
              (localBuffer[1] == kDiagSuppressPosRspMsgIndicationBit))
         {
            /* Restart the tester present timer if not in default session */
            if (GetDiagProgrammingSession() || GetDiagExtendedDiagSession())
            {
               ResetTesterTimeout();
            }

            return 0;
         }
      }
#if defined(TP_ENABLE_DIAG_SERVICE_QUEUE)
      if(TRUE == Fblm_DiagGetBufferFreeSts())
      {
    	/*when all queue are free, and deal with function Address request,Use First Queue */
    	DiagBuffer = (4-(((ulong)&basicDiagBuffer[0][0])%4))+ &basicDiagBuffer[0][0];
#endif
        /* Lock diagnostic buffer */
        tpBufferLocked = 1;

        /* Functional request indication */
        SetFunctionalRequest();

        /* Halts the tester-present timer while receiving a diagnostic message */
        StopTesterTimeout();

        /* Indicate an ongoing service processing */
        SetServiceInProgress();

        return DiagBuffer;

#if defined(TP_ENABLE_DIAG_SERVICE_QUEUE)
      }
      else
      {
        return 0;
      }
#endif

   }
   else
   {
      return 0;
   }
}

/******************************************************************************
* Name         :  FblTpTxErrorIndication - 14229 specific
* Called by    :  TPMC
* Preconditions:  None
* Parameters   :  TPMC error number
* Return code  :  None
* Description  :  This function is called in case of a transmit error in the
*                 transport layer
******************************************************************************/
#if defined ( TP_TYPE_MULTI_DYNAMIC_NORMAL_ADDRESSING )
vuint8 FblTpTxErrorIndication( vuint8 tpChannel, vuint8 errNo )
{
   FblTpTxConfirmation(tpChannel, errNo);
#else
vuint8 FblTpTxErrorIndication( vuint8 errNo )
{
   FblTpTxConfirmation(errNo);
#endif
   return kTpHoldChannel;
}


/******************************************************************************
* Name         :  FblDiagErrorIndication - 14229 specific
* Called by    :  TPMC if an error occurred during reception of a multi-frame
* Preconditions:  TP must been initialized
* Parameters   :  Details the error that has occurred during reception
* Return code  :  None
* Description  :  This function is called in case of a receive error in the
*                 transport layer
******************************************************************************/
#if defined ( TP_TYPE_MULTI_DYNAMIC_NORMAL_ADDRESSING )
void FblTpRxErrorIndication(vuint8 tpChannel,  vuint8 errNo )
#else
void FblTpRxErrorIndication( vuint8 errNo )
#endif
{
   /* Restart the tester present timer if not in default session */
   if (GetDiagProgrammingSession() || GetDiagExtendedDiagSession())
   {
      ResetTesterTimeout();
   }
   Fblm_DiagUsdQueStsInit();
   ClrServiceInProgress();

   /* Unlock DiagBuffer */
   tpBufferLocked = 0;
}

/******************************************************************************
* Name         :  FblTpTxConfirmation - 14229 specific
* Called by    :  TPMC when a diagnostic message has been transmitted
*                 successfully
* Preconditions:  Service must have ben received
* Parameters   :  The result type of the confirmation
* Return code  :  None
* Description  :  Indicates that a diagnostic service was sent by the TP layer
*                 or an error has occurred during transmission.
*                 According to ISO-14229, the tester present timer must be
*                 restarted.
******************************************************************************/
#if defined ( TP_TYPE_MULTI_DYNAMIC_NORMAL_ADDRESSING )
void FblTpTxConfirmation( vuint8 tpChannel, vuint8 state )
#else
void FblTpTxConfirmation( vuint8 state )
#endif
{
#if defined(TP_ENABLE_DIAG_SERVICE_QUEUE)
      vuint8 queNum = 0u;
      vuint8 TpResetRxBlockReq= TRUE;
#endif
   SetTpConfirmationFlag();
   if (tpRCRRPflag == 0)
   {
      /* Restart the tester present timer if not in default session */
      if (GetDiagProgrammingSession() || GetDiagExtendedDiagSession())
      {
         ResetTesterTimeout();
      }
      ClrServiceInProgress();
#if defined(TP_ENABLE_DIAG_SERVICE_QUEUE)
      for(queNum = 0u; queNum < kDiagQueBufferNum; queNum++)
      {
        if((K_diagQueBufferState[queNum].requestProcess == TRUE) && \
        		(DiagGetSwapQueBufSts(queNum).bufferIsFree == FALSE) &&
        		(DiagGetSwapQueBufSts(queNum).phyReqInd == FALSE))
        {/*Need proccess done when other queue is receive can package*/
          TpResetRxBlockReq = FALSE;
        }
      }

      if(TRUE == TpResetRxBlockReq)
      {
        TpResetRxBlock();
      }
      else if(FALSE == TpResetRxBlockReq)
      {
       /*when tx reposnse ,the action of resetRxBlock will cause RX init.*/
      }
      else
      {
    	/*error*/
      }

      for(queNum = 0u; queNum < kDiagQueBufferNum; queNum++)
      {
        if(K_diagQueBufferState[queNum].requestProcess == TRUE)
        {/*This Queue is done*/
          K_diagQueBufferState[queNum].bufferIsFree = TRUE;
          K_diagQueBufferState[queNum].requestProcess = FALSE;
          DiagGetSwapQueBufSts(queNum).waitReqTime = WaitNextReqTime; /*reinit time*/
        }
      }
#endif
   }
   else
   {
      tpRCRRPflag = 0;
   }

}

/******************************************************************************
* Name         :  FblDiagInitStartFromAppl
* Called by    :  main
* Preconditions:  None
* Parameters   :  None
* Return code  :  None
* Description  :  This function is called from FblInit() when the FBL is
*                 started from application. The diagnostic buffer is
*                 prepared to be able to handle the diagnostic request.
******************************************************************************/
void FblDiagInitStartFromAppl(void)
{
   /* Prepare DiagBuffer for DiagnosticSessionControl service */
   DiagBuffer[kDiagFmtServiceId] = kDiagSidDiagnosticSessionControl;
   DiagBuffer[kDiagFmtSubparam] = kDiagSubProgrammingSession;
   DiagDataLength = kDiagRqlDiagnosticSessionControl;

   /* Set diagnostic session (extended session) */
   ClrDiagDefaultDiagSession();
   ClrDiagProgrammingSession();
   SetDiagExtendedDiagSession();

   /* Activate tester present timer */
   ResetTesterTimeout();

#if defined( TP_ENABLE_NORMAL_FIXED_ADDRESSING )  || \
    defined( TP_ENABLE_EXTENDED_ADDRESSING )
   /* Set TP parameters */
   ApplFblTpParamInit();
#endif
}

/******************************************************************************
* Name         :  DiagExRCRResponsePending - 14229 specific
* Called by    :  Diag service functions
* Preconditions:  None
* Parameters   :  forceSend, determines if a message is sent independently from
*                 timer state.
* Return code  :  None
* Description  :  Transmit a busy message if timer expires (forceSend ==
*                 kNotForceSendResponsePending) or if kForceSendResponsePending
*                 is passed.
******************************************************************************/
void DiagExRCRResponsePending(ubyte forceSend)
{

# if defined ( TP_TYPE_MULTI_DYNAMIC_NORMAL_ADDRESSING )
   vuint8 tpTxChannel;
# endif

   if ((GetP2Timer() < (kFblDiagTimeP2Star/2)) || (forceSend == kForceSendResponsePending))
   {
      rcrrpDiagBuffer[1] = DiagBuffer[kDiagFmtServiceId];
# if defined ( TP_TYPE_MULTI_DYNAMIC_NORMAL_ADDRESSING )
      tpTxChannel = TpTxGetFreeChannel(0);
#if defined(CAN_STD_ID_USED)
      TpTxSetChannelID(tpTxChannel, CAN_TP_TXID, CAN_TP_RXID);
#elif defined(CAN_EXT_ID_USED)
      TpTxSetChannelExtID(tpTxChannel, CAN_TP_TXID, CAN_TP_RXID);
#endif

# endif
      if (RCRRPTransmit(3) == kTpSuccess)
      {
         tpRCRRPflag = 1;
         DiagWaitForConfirmation();

         /* Restart P2-Timer to P2* */
         SetP2Timer(kFblDiagTimeP2Star);

         /* If response pending is transmitted and no response
          * is set, a positive response has to be transmitted anyway. */
         ClrSuppressPosRspMsg();

         SetRcrRpInProgress();
      }
   }
   /* Add function need to called cyclically here */
#ifdef FBLM_DIAG_USE_NVM
   MemAcc_MainFunction();
   Fee_30_FlexNor_MainFunction();
   NvM_MainFunction();
   Fblm_NvmWriteReqHandler();
#endif /* FBLM_DIAG_USE_NVM */
}
/*______ L O C A L - F U N C T I O N S _______________________________________*/
/******************************************************************************
* Name         :  ChkSuppressPosRspMsgIndication - 14229 specific
* Called by    :  FblDiagTask
* Preconditions:  None
* Parameters   :  Diagnostic subparameter
* Return code  :  None
* Description  :  This functions checks if a diagnostic response has to be sent
*                 and resets the positive response message indication bit if
*                 necessary
******************************************************************************/
static void ChkSuppressPosRspMsgIndication(ubyte *subparam)
{
   if (0 != ((*(subparam)) & (kDiagSuppressPosRspMsgIndicationBit)))
   {
      SetSuppressPosRspMsg(); /* Set internal flag for response processor */
      (*(subparam)) &= (ubyte)~kDiagSuppressPosRspMsgIndicationBit; /* Clear indication bit */
   }
}

/******************************************************************************
* Name         :  ApplFblSecurityInit
* Called by    :  Diagnostic module
* Preconditions:  None
* Parameters   :  None
* Return code  :  Status of security module initialization
* Description  :  Initialize security module.
******************************************************************************/
static void ApplFblSecurityInit(void)
{
   memset(AES_Seed, 0, 16);
}
/******************************************************************************
* Name         :  ApplFblSecuritySeedInit
* Called by    :  Diagnostic module
* Preconditions:  None
* Parameters   :  None
* Return code  :  Status of seed initialization
* Description  :  Initialize seed values.
******************************************************************************/
static void Fblm_SecuritySeedInit(void)
{
   /* Initialize seed values */
   //seed.seedY += seed.seedX;
   //seed.seedX = Fblm_GetTimerValue();// to do ,random value not random
}

/******************************************************************************
* Name         :  TpResetRxBlock - 14229 specific
* Called by    :  Internal
* Preconditions:  None
* Parameters   :  None
* Return code  :  None
* Description  :  Reset transport layer
******************************************************************************/
static void TpResetRxBlock(void)
{
   if (GetFunctionalRequest())
   {
      FblTpFuncResetChannel();
   }
   else
   {
      FblTpRxResetChannel();
   }
   tpBufferLocked = 0;
   tpRCRRPflag = 0;
}


/* Diagnostic standard functions  ********************************************/

/******************************************************************************
* Name         :  DiagDiscardReception - 14229 specific
* Called by    :  DiagPutResponse, DiagNegResp
* Preconditions:  None
* Parameters   :  None
* Return code  :  None
* Description  :  Received diagnostic messages are discarded
******************************************************************************/
static void DiagDiscardReception(void)
{
   SetResponseProcessing();   /* Set flag for running response procedure */
   Fblm_CANRunnable();
   ClrResponseProcessing();
}
/******************************************************************************
* Name         :  DiagForceTransmit - 14229 specific
* Called by    :  Internal
* Preconditions:  None
* Parameters   :  None
* Return code  :  None
* Description  :  Force transmission of a response message
******************************************************************************/
static void DiagForceTransmit(void)
{
#if defined ( TP_TYPE_MULTI_DYNAMIC_NORMAL_ADDRESSING )
   TpTxStateTask(0);/*call CanTransmit()*/
#else
   TpTxStateTask();
#endif

   /*Jira:ZCBD-346, it will be called in while*/
   /*Waiting for TX confirm, if success, Set Tx confirm*/
   if(kCanTxOk == Fblm_CanMsgTransmitted())
   {
     CAN5_TxMsgCallback();
   }
   /*Because here is force transmit,must recognize Tx confirm here*/

}

/******************************************************************************
* Name         :  DiagWaitForConfirmation - 14229 specific
* Called by    :  Internal
* Preconditions:  None
* Parameters   :  None
* Return code  :  None
* Description  :  Wait for a response message to be transmitted
******************************************************************************/
static void DiagWaitForConfirmation(void)
{
   ClrTpConfirmationFlag();
   /*
      Set timeout for confirmation timeout.
      P2 timer is decremented in watchdog routine for this task.
      P2 timer is currently not used, it was cleared above.
   */
   ClrRcrRpInProgress();
   SetP2Timer(kDiagConfirmationTimeout);

   while (!GetTpConfirmationFlag() && (GetP2Timer() > 0))
   {
	  (void)Fblm_LookForWatchdog();
      DiagForceTransmit();
   }

   /* Clear P2 timer used for confirmation timeout */
   ClrP2Timer();

}

#ifdef FBLM_DIAG_USE_NVM
/******************************************************************************/
/*Name : Fblm_NvmWriteReq                                                     */
/*Role:  Request save diag data to NVM                                        */
/*Interface :                                                                 */
/*Pre-condition :                                                             */
/*Constraints: -                                                              */
/*Behaviour:                                                                  */
/******************************************************************************/
boolean Fblm_NvmWriteReq(NvM_BlockIdType BlockId, uint8 *pData)
{
  boolean ret = FALSE;

  if ((BlockId < NVM_TOTAL_NUM_OF_NVRAM_BLOCKS) && (NULL != pData))
  {
    if (Fblm_NVM_IDLE == Fblm_NvmProcessState)
    {
      Fblm_NvmWriteReqInternal.BlockId = BlockId;
      Fblm_NvmWriteReqInternal.pData = pData;
      *Fblm_NvmWriteReqInternal.pWriteResult = Fblm_NVM_WRITE_PENDING;
      Fblm_NvmProcessState = Fblm_NVM_WRITE_REQ;
      ret = TRUE;
    }
  }

  return ret;
}

/******************************************************************************/
/*Name : Fblm_GetNvmWriteResult                                               */
/*Role:  Get diag data NVM write result                                       */
/*Interface :                                                                 */
/*Pre-condition :                                                             */
/*Constraints: -                                                              */
/*Behaviour:                                                                  */
/******************************************************************************/
Fblm_NvmWriteResult_t Fblm_GetNvmWriteResult(void)
{
  return Fblm_NvmWriteResult;
}

/******************************************************************************/
/*Name : Fblm_NvmWriteReqHandler                                              */
/*Role:  Save diag data to NVM                                                */
/*Interface :                                                                 */
/*Pre-condition :                                                             */
/*Constraints: -                                                              */
/*Behaviour:                                                                  */
/******************************************************************************/
static void Fblm_NvmWriteReqHandler(void)
{
  NvM_RequestResultType NvM_RequestResult = E_OK;

  switch (Fblm_NvmProcessState)
  {
    case Fblm_NVM_IDLE:
      ; /* do nothing */
      break;
    case Fblm_NVM_WRITE_REQ:
      if (E_OK == NvM_WriteBlock(Fblm_NvmWriteReqInternal.BlockId, Fblm_NvmWriteReqInternal.pData))
      {
        Fblm_NvmProcessState = Fblm_NVM_WRITE_IN_PROCESS;
      }
      break;
    case Fblm_NVM_WRITE_IN_PROCESS:
      if (E_OK == NvM_GetErrorStatus(Fblm_NvmWriteReqInternal.BlockId, &NvM_RequestResult))
      {
        if (NVM_REQ_OK == NvM_RequestResult)
        {
          *Fblm_NvmWriteReqInternal.pWriteResult = Fblm_NVM_WRITE_SUCCESS;
          Fblm_NvmProcessState = Fblm_NVM_IDLE;
        }
        else if (NVM_REQ_PENDING == NvM_RequestResult)
        {
          *Fblm_NvmWriteReqInternal.pWriteResult = Fblm_NVM_WRITE_PENDING;
        }
        else
        {
          *Fblm_NvmWriteReqInternal.pWriteResult = Fblm_NVM_WRITE_FAILED;
          Fblm_NvmProcessState = Fblm_NVM_IDLE;
        }
      }
      break;
    default:
      break;
  }
  /* Timeout counter handler */
  if (Fblm_NVM_IDLE != Fblm_NvmProcessState)
  {
    if (Fblm_NvmTimeoutCounter < Fblm_NVM_WRITE_TIMEOUT)
    {
      Fblm_NvmTimeoutCounter++;
    }
    else
    {
      Fblm_NvmTimeoutCounter = 0u;
      Fblm_NvmProcessState = Fblm_NVM_IDLE;
      *Fblm_NvmWriteReqInternal.pWriteResult = Fblm_NVM_WRITE_FAILED;
    }
  }
  else
  {
    Fblm_NvmTimeoutCounter = 0u;
  }
}
#endif /* FBLM_DIAG_USE_NVM */
/*______ E N D _____ (FileName.c) ____________________________________________*/
