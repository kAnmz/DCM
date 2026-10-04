/******************************************************************************/
/* @F_NAME :          can_config.c                                            */
/* @F_PURPOSE :       manage CAN driver for MCU                               */
/* @F_CREATED_BY :    Jianhua.Wu  			                                  */
/* @F_CREATION_DATE : 2021.07.30                                              */
/* @F_LANGUAGE :      ANSI C                                                  */
/* @F_MPROC_TYPE :    µC supported              						      */
/*************************************** (C) Copyright 2021 Marelli ***********/

/*______ I N C L U D E - F I L E S ___________________________________________*/
#include<stdint.h>
#include "fblm_config.h"
#include "fblm_priv.h"
#include "cpus_config_tvii.h"
#include "can_config.h"
#include "can_def.h"
#include "system_cyt2b7.h"
#include "tpmc.h"
/*______ L O C A L - D E F I N E S ___________________________________________*/

/*______ L O C A L - T Y P E S _______________________________________________*/
#define FRAME_LENGTH                   8 /* CAN-Frame */
/*______ G L O B A L - D A T A _______________________________________________*/
extern uint8 TpLongCanFdTxTransmit; /*from tpmc.c, used to send long frame*/

#if defined(CAN_STD_ID_USED)
/*Standard ID Filter configration*/
/*In FBL,only receive physical diagnostic ID 0x721 and function diagnostic ID 0x7df,response:0x729*/


cy_stc_id_filter_t Cand_stdIdFilterCh5[2] =
{
   //CANFD_CONFIG_STD_ID_FILTER_CLASSIC_RXBUFF(CAN_TP_RXID, 0u),      /* store into RX buffer Idx0 */
  // CANFD_CONFIG_STD_ID_FILTER_CLASSIC_RXBUFF(CAN_TP_FUNC_RXID, 1u),      /* store into RX buffer Idx1 */
   CANFD_CONFIG_STD_ID_FILTER_CLASSIC(CAN_TP_RXID,0x7FF,CY_CANFD_ID_FILTER_ELEMNT_CONFIG_SET_PIORITY_STORE_RXFIFO0),
   CANFD_CONFIG_STD_ID_FILTER_CLASSIC(CAN_TP_FUNC_RXID,0x7FF,CY_CANFD_ID_FILTER_ELEMNT_CONFIG_SET_PIORITY_STORE_RXFIFO1),
};

/*Extended ID Filter configration*/
/*physical diagnostic ID 0x18DA60F1 and function diagnostic ID 0x18DA6055,response:0x18DAF160*/
const cy_stc_extid_filter_t Cand_extIdFilterCh5[2] =
{
 0u,
 0u,
};

#endif

#if defined(CAN_EXT_ID_USED)
/*Standard ID Filter configration*/
/*In FBL,only receive physical diagnostic ID 0x721 and function diagnostic ID 0x7df,response:0x729*/
cy_stc_id_filter_t Cand_stdIdFilterCh5[2] =
{
 0u,
 0u,
};

/*Extended ID Filter configration*/
/*physical diagnostic ID 0x18DA60F1 and function diagnostic ID 0x18DA6055,response:0x18DAF160*/
const cy_stc_extid_filter_t Cand_extIdFilterCh5[2] =
{
//	CANFD_CONFIG_EXT_ID_FILTER_CLASSIC_RXBUFF(CAN_TP_RXID, 1u),    /* store into RX buffer Idx2 */
//	CANFD_CONFIG_EXT_ID_FILTER_CLASSIC_RXBUFF(CAN_TP_FUNC_RXID, 2u),    /* store into RX buffer Idx3 */

	CANFD_CONFIG_EXT_ID_FILTER_CLASSIC(CAN_TP_RXID, 0x1fffffff, CY_CANFD_ID_FILTER_ELEMNT_CONFIG_STORE_RXFIFO0),    /* ID = 0x10010, store into RX FIFO0 */
    CANFD_CONFIG_EXT_ID_FILTER_CLASSIC(CAN_TP_FUNC_RXID, 0x1fffffff, CY_CANFD_ID_FILTER_ELEMNT_CONFIG_STORE_RXFIFO1),    /* ID = 0x10020, store into RX FIFO1 */

};
#endif
/*______ P R I V A T E - D A T A _____________________________________________*/
#if FBLM_CANFD_SUPPORT
tTmpCanFdMsgObj CanLL_RxBuf[kCanNumberOfHwChannels] = {0u};/*Used for reconstruct receive data*/
#else /*CANFD USED */
tTmpMsgObj CanLL_RxBuf[kCanNumberOfHwChannels] = {0u};/*Used for reconstruct receive data*/
#endif



_c_TxDynamicMsg0_buf TxDynamicMsg0 = {0u};
ulong TxDynamicMsgId = 0x00u;
/* CAN port configuration */





/*CAN CH5*/
const cy_stc_gpio_pin_config_t CAND_TxPinCfgCh5 =
{
		.outVal = 1,
		.driveMode = CY_GPIO_DM_STRONG,
		.hsiom = CY_CANFD5_TX_MUX,
		.intEdge = 0,
		.intMask = 0,
		.vtrip = 0,
		.slewRate = 0,
		.driveSel = 0,
		.vregEn = 0,
		.ibufMode = 0,
		.vtripSel = 0,
		.vrefSel = 0,
		.vohSel = 0,
};

const cy_stc_gpio_pin_config_t CAND_RxPinCfgCh5 =
{
		.outVal = 0,
		.driveMode = CY_GPIO_DM_HIGHZ,
		.hsiom = CY_CANFD5_RX_MUX,
		.intEdge = 0,
		.intMask = 0,
		.vtrip = 0,
		.slewRate = 0,
		.driveSel = 0,
		.vregEn = 0,
		.ibufMode = 0,
		.vtripSel = 0,
		.vrefSel = 0,
		.vohSel = 0,
};

/* CAN5 configuration */
cy_stc_canfd_config_t CAND_Ch5Cfg =
{
	    .txCallback     = CAN5_TxMsgCallback,
	    .rxCallback     = CAN5_RxMsgCallback,
	    .rxFifoWithTopCallback = NULL/*(cy_canfd_rx_fifo_msg_with_top_func_ptr_t)CAN_RxFifoWithTopCallback*/,
	    .statusCallback = NULL, /* Un-supported now*/
	    .errorCallback  = CAN5_BusErrCallback, /*Un-supported now*/
#if FBLM_CANFD_SUPPORT
	    .canFDMode      = true, /* Use standard CAN mode*/
#else
	    .canFDMode      = false, /* Use standard CAN mode*/
#endif
	    /*40 MHz*/
	    .bitrate        =       /*Nominal bit rate settings (sampling point = 81.5%)*/
	    {
	      .prescaler      = 5u - 1u,  /*cclk/10, When using 500 kbps, 1bit = 16tq*/
	      .timeSegment1   = 12u - 1u, /*tseg1 = 12tq*/
	      .timeSegment2   = 3u - 1u,  /*tseg2 = 3tq*/
	      .syncJumpWidth  = 2u - 1u,  /*sjw   = 2tq*/

	    },
#if FBLM_CANFD_SUPPORT
	    .fastBitrate    =       // Fast bit rate settings (sampling point = 80%)
	    {
	        .prescaler      = 1u - 1u,  // cclk/1, When using 2Mbps, 1bit = 20tq
	        .timeSegment1   = 15u - 1u,  // tseg1 = 15tq,
	        .timeSegment2   = 4u - 1u,  // tseg2 =  4tq
	        .syncJumpWidth  = 2u - 1u,  // sjw   =  2tq
	    },
#endif
	    .tdcConfig      =        /*Transceiver delay compensation, unused.*/
	    {
	        .tdcEnabled     = false,
	        .tdcOffset      = 0,
	        .tdcFilterWindow= 0,
	    },
	    .sidFilterConfig    =   /*Standard ID filter*/
	    {
	        .numberOfSIDFilters = sizeof(Cand_stdIdFilterCh5) / sizeof(Cand_stdIdFilterCh5[0]),
	        .sidFilter          = Cand_stdIdFilterCh5,
	    },
	    .extidFilterConfig  =    /*Extended ID filter*/
	    {
	        .numberOfEXTIDFilters   = sizeof(Cand_extIdFilterCh5) / sizeof(Cand_extIdFilterCh5[0]),
	        .extidFilter            = Cand_extIdFilterCh5,
	        .extIDANDMask           = 0x1fffffff,   /*No pre filtering.*/
	    },
	    .globalFilterConfig =   /*Global filter*/
	    {
	        .nonMatchingFramesStandard = CY_CANFD_ACCEPT_IN_RXFIFO_0,  /*Reject none match IDs*/
	        .nonMatchingFramesExtended = CY_CANFD_ACCEPT_IN_RXFIFO_1,  /*Reject none match IDs*/
	        .rejectRemoteFramesStandard = true,  /*No remote frame*/
	        .rejectRemoteFramesExtended = true,  /*No remote frame*/
	    },
#if FBLM_CANFD_SUPPORT
	    .rxBufferDataSize = CY_CANFD_BUFFER_DATA_SIZE_64,
	    .rxFifo1DataSize  = CY_CANFD_BUFFER_DATA_SIZE_64,
	    .rxFifo0DataSize  = CY_CANFD_BUFFER_DATA_SIZE_64,
	    .txBufferDataSize = CY_CANFD_BUFFER_DATA_SIZE_64,
#else
	    .rxBufferDataSize = CY_CANFD_BUFFER_DATA_SIZE_8,
	    .rxFifo1DataSize  = CY_CANFD_BUFFER_DATA_SIZE_8,
	    .rxFifo0DataSize  = CY_CANFD_BUFFER_DATA_SIZE_8,
	    .txBufferDataSize = CY_CANFD_BUFFER_DATA_SIZE_8,
#endif
    .rxFifo0Config    =  /*RX FIFO0, unused.*/
    {
        .mode = CY_CANFD_FIFO_MODE_OVERWRITE,
        .watermark = 10u,
        .numberOfFifoElements = 48u,
        .topPointerLogicEnabled = false,
    },

    .rxFifo1Config    =  /*RX FIFO1, unused.*/
    {
        .mode = CY_CANFD_FIFO_MODE_OVERWRITE,
        .watermark = 10u,
        .numberOfFifoElements = 48u,
        .topPointerLogicEnabled = false, /*true*/
    },
#if FBLM_CANFD_SUPPORT
    .noOfRxBuffers  = 4u,  /*Refer to CANFD Configure*/
    .noOfTxBuffers  = 4u,  /*Refer to CANFD Configure*/
#else
    .noOfRxBuffers  = 64u,
    .noOfTxBuffers  = 32u,
#endif
};
/*______ L O C A L - D A T A _________________________________________________*/

/*______ L O C A L - M A C R O S _____________________________________________*/

/*______ I M P O R T - F U N C T I O N S - P R O T O T Y P E S _______________*/

/*______ L O C A L - F U N C T I O N S - P R O T O T Y P E S _________________*/
cy_en_canfd_status_t CANFD_EnableInterruptCallBackFunction(cy_pstc_canfd_type_t pstcCanFD);
/*______ G L O B A L - F U N C T I O N S _____________________________________*/
/*----------------------------------------------------------------------------*/
/*Name : CAND_Init                                                            */
/*Role : Init CAN for Bootloader                            		          */
/*Interface :                                                                 */
/*  - IN  : none                                                   			  */
/*  - OUT : none                                         					  */
/*Pre-condition : none                                        			      */
/*Constraints   : none                                             			  */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [operation to carry out]                                                */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
void CAND_Init(void)
{

#if(CAND_CHANNEL5 == CAND_ACTIVE)//Group 1 CAN2 is channel 5
	/*Clock configuration*/
	Cy_SysClk_PeriphAssignDivider(PCLK_CANFD1_CLOCK_CAN2, CY_SYSCLK_DIV_8_BIT, CPUS_PERI_CLOCK_DIV_8_CHANNEL5);
	Cy_SysClk_PeriphSetDivider(CY_SYSCLK_DIV_8_BIT, CPUS_PERI_CLOCK_DIV_8_CHANNEL5, CAND_INT_DIV_CHANNEL5);/*80MHz/2=40MHz*/
	Cy_SysClk_PeriphEnableDivider(CY_SYSCLK_DIV_8_BIT, CPUS_PERI_CLOCK_DIV_8_CHANNEL5);

	Cy_CANFD_DeInit(CY_CANFD1_2_TYPE);

	/*Port Initial*/
	Cy_GPIO_Pin_Init(CY_CANFD5_TX_PORT, CY_CANFD5_TX_PIN, &CAND_TxPinCfgCh5);
	Cy_GPIO_Pin_Init(CY_CANFD5_RX_PORT, CY_CANFD5_RX_PIN, &CAND_RxPinCfgCh5);
	IODC_SetOutputData(HSCAN_STB,IODC_ACTIVE);/*Enable CAN STB */
	IODC_SetOutputData(HSCAN_EN,IODC_ACTIVE);/*Enable CAN EN */


#if 0  /*Doesn't use interrupt*/
	/*Interrupt Configuration*/
	Can_irq_cfg.intIdx = CAND_INT_ID_CHANNEL5;
	Can_irq_cfg.sysIntSrc = CAND_INT_SRC_CHANNEL5;
	Can_irq_cfg.isEnabled = TRUE;
	Cy_SysInt_InitIRQ(&Can_irq_cfg);
	Cy_SysInt_SetSystemIrqVector(Can_irq_cfg.sysIntSrc, CanfdInterruptHandler5);
	NVIC_SetPriority(Can_irq_cfg.intIdx, CAND_IRQ_PRORITY_CHANNEL5);
	NVIC_EnableIRQ(Can_irq_cfg.intIdx);
#endif
	/* Initialize CAN as CANFD */
	Cy_CANFD_Init(CY_CANFD5_TYPE, &CAND_Ch5Cfg);
	CANFD_EnableInterruptCallBackFunction(CY_CANFD5_TYPE);/*to Advoid modifying Autosar Cypress SDL Lib*/


#if (CAND_NON_ISO_OPERATION_CH5 == CAND_ACTIVE)
	CAND_SetISOFormat(CY_CANFD5_TYPE);/*We use ISO CANFD*/
#endif

#endif
}

/*----------------------------------------------------------------------------*/
/*Name : CAND_DeInit                                                          */
/*Role : DeInit CAN driver                            		    		      */
/*Interface :                                                                 */
/*  - IN  : none                                                   			  */
/*  - OUT : none                                         					  */
/*Pre-condition : none                                        			      */
/*Constraints   : none                                             			  */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [operation to carry out]                                                */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
void CAND_DeInit(void)
{
	Cy_CANFD_DeInit(CY_CANFD5_TYPE);
}

cy_en_canfd_status_t CANFD_EnableInterruptCallBackFunction(cy_pstc_canfd_type_t pstcCanFD)
{
    volatile stc_CANFD_CH_M_TTCAN_t* pstcCanFDChMTTCAN;
    un_CANFD_CH_TXBTIE_t  unTXBTIE = { 0 };

    /* Check for NULL pointers */
    if ( pstcCanFD  == NULL)
    {
        return CY_CANFD_BAD_PARAM;
    }
    /* Get the pointer to M_TTCAN of the CAN FD channel */
    pstcCanFDChMTTCAN = &pstcCanFD->M_TTCAN;

    pstcCanFDChMTTCAN->unIE.u32Register |= 0x200;

    /*Configure CANFD_CH_TXBTIE to enable Transmission interrupt*/
    unTXBTIE.stcField.u32TIE = 0xFFFFFFFF;
    pstcCanFDChMTTCAN->unTXBTIE.u32Register = unTXBTIE.u32Register;
    return CY_CANFD_SUCCESS;
}


/******************************************************************************
* Name         :  CAN5_TxMsgCallback
* Called by    :
* Preconditions:
* Parameters   :  None
* Return code  :  None
* Description  : This function is called for CAN channel 5 Tx message callback
******************************************************************************/
void CAN5_TxMsgCallback(void)
{
  if (CAN_TP_TXID == TxDynamicMsgId)/*Diagnostic message*/
  {
	TpDrvConfirmation(0);
  }
}

/******************************************************************************
* Name         :  CAN5_RxMsgCallback
* Called by    :
* Preconditions:
* Parameters   :  None
* Return code  :  None
* Description  : This function is called for CAN channel 5 Rx message callback
******************************************************************************/
void CAN5_RxMsgCallback(bool bRxFifoMsg, uint8 u8MsgBufOrRxFifoNum, cy_stc_canfd_msg_t* pstcCanFDmsg)
{
	ubyte canHwChannel = 0;
	tCanRxInfoStruct tpmcrxStruct = {0u};
#if 0
	if (8u != pstcCanFDmsg->dataConfig.dataLengthCode)/*Only receive DLC 8*/
	{
		return;
	}
#endif
	canHwChannel = CAND_CHANNEL5_TPMC_INDEX;
	 /*Littile-endian we used*/
	 /* copy message (ID, DLC, DATA) to buffer */
	 CanLL_RxBuf[canHwChannel].Id         = pstcCanFDmsg->idConfig.identifier;
	 CanLL_RxBuf[canHwChannel].Id        |= (pstcCanFDmsg->idConfig.extended << 31u);
	 CanLL_RxBuf[canHwChannel].Dlc        = pstcCanFDmsg->dataConfig.dataLengthCode;
	 CanLL_RxBuf[canHwChannel].u.iData[0] = pstcCanFDmsg->dataConfig.data[0];
	 CanLL_RxBuf[canHwChannel].u.iData[1] = pstcCanFDmsg->dataConfig.data[1];
#if FBLM_CANFD_SUPPORT
	 CanLL_RxBuf[canHwChannel].u.iData[2] = pstcCanFDmsg->dataConfig.data[2];
	 CanLL_RxBuf[canHwChannel].u.iData[3] = pstcCanFDmsg->dataConfig.data[3];
	 CanLL_RxBuf[canHwChannel].u.iData[4] = pstcCanFDmsg->dataConfig.data[4];
	 CanLL_RxBuf[canHwChannel].u.iData[5] = pstcCanFDmsg->dataConfig.data[5];
	 CanLL_RxBuf[canHwChannel].u.iData[6] = pstcCanFDmsg->dataConfig.data[6];
	 CanLL_RxBuf[canHwChannel].u.iData[7] = pstcCanFDmsg->dataConfig.data[7];
	 CanLL_RxBuf[canHwChannel].u.iData[8] = pstcCanFDmsg->dataConfig.data[8];
	 CanLL_RxBuf[canHwChannel].u.iData[9] = pstcCanFDmsg->dataConfig.data[9];
	 CanLL_RxBuf[canHwChannel].u.iData[10] = pstcCanFDmsg->dataConfig.data[10];
	 CanLL_RxBuf[canHwChannel].u.iData[11] = pstcCanFDmsg->dataConfig.data[11];
	 CanLL_RxBuf[canHwChannel].u.iData[12] = pstcCanFDmsg->dataConfig.data[12];
	 CanLL_RxBuf[canHwChannel].u.iData[13] = pstcCanFDmsg->dataConfig.data[13];
	 CanLL_RxBuf[canHwChannel].u.iData[14] = pstcCanFDmsg->dataConfig.data[14];
	 CanLL_RxBuf[canHwChannel].u.iData[15] = pstcCanFDmsg->dataConfig.data[15];
#endif

	 //tpmcrxStruct = &CanLL_RxBuf[canHwChannel];
	 (tpmcrxStruct.Channel) = canHwChannel;
	 (tpmcrxStruct.pChipMsgObj) = (CanChipMsgPtr)&(CanLL_RxBuf[canHwChannel].Id);
	 (tpmcrxStruct.pChipData) = (CanChipDataPtr)&(CanLL_RxBuf[canHwChannel].u.bData[0]);
	 (tpmcrxStruct.Handle) = 0u;

	 //Cy_CANFD_UpdateAndTransmitMsgBuffer(CY_CANFD5_TYPE,0,pstcCanFDmsg);/*for test .test ok*/

	switch (pstcCanFDmsg->idConfig.identifier )
	{
#if defined(CAN_STD_ID_USED)
	case CAN_TP_RXID:
		TpPrecopy(&tpmcrxStruct);
		break;
	case CAN_TP_FUNC_RXID:
		TpFuncPrecopy(&tpmcrxStruct);
		break;

#endif

#if defined(CAN_EXT_ID_USED)
	case CAN_TP_RXID:
		TpPrecopy(&tpmcrxStruct);
		break;
	case CAN_TP_FUNC_RXID:
		TpFuncPrecopy(&tpmcrxStruct);
		break;
#endif

	default:
		break;
	}

}


void CAN_RxFifoWithTopCallback(uint8 u8FifoNum, uint8   u8BufferSizeInWord, cy_stc_canfd_msg_t* pstcCanFDmsg)
{
	#if 0
	/*TODO*/
    cy_stc_canfd_msg_t pstcCanFDmsg;

    pstcCanFDmsg.idConfig.identifier = 0x300;
    pstcCanFDmsg.idConfig.extended = 0;
    pstcCanFDmsg.dataConfig.data[0] = 0x12345678;
    pstcCanFDmsg.dataConfig.dataLengthCode = 8;
    pstcCanFDmsg.canFDFormat = 1;

    Cy_CANFD_UpdateAndTransmitMsgBuffer
    (
        CY_CANFD5_TYPE,
        3,
        &pstcCanFDmsg
    );
#endif

	ubyte canHwChannel = 0;
	tCanRxInfoStruct tpmcrxStruct = {0u};

	if (8u != pstcCanFDmsg->dataConfig.dataLengthCode)/*Only receive DLC 8*/
	{
		return;
	}
	canHwChannel = CAND_CHANNEL5_TPMC_INDEX;
	 /*Littile-endian we used*/
	 /* copy message (ID, DLC, DATA) to buffer */
	 CanLL_RxBuf[canHwChannel].Id         = pstcCanFDmsg->idConfig.identifier;
	 CanLL_RxBuf[canHwChannel].Id        |= (pstcCanFDmsg->idConfig.extended << 31u);
	 CanLL_RxBuf[canHwChannel].Dlc        = pstcCanFDmsg->dataConfig.dataLengthCode;
	 CanLL_RxBuf[canHwChannel].u.iData[0] = pstcCanFDmsg->dataConfig.data[0];
	 CanLL_RxBuf[canHwChannel].u.iData[1] = pstcCanFDmsg->dataConfig.data[1];

	 //tpmcrxStruct = &CanLL_RxBuf[canHwChannel];
	 (tpmcrxStruct.Channel) = canHwChannel;
	 (tpmcrxStruct.pChipMsgObj) = (CanChipMsgPtr)&(CanLL_RxBuf[canHwChannel].Id);
	 (tpmcrxStruct.pChipData) = (CanChipDataPtr)&(CanLL_RxBuf[canHwChannel].u.bData[0]);
	 (tpmcrxStruct.Handle) = 0u;

	 //Cy_CANFD_UpdateAndTransmitMsgBuffer(CY_CANFD5_TYPE,0,pstcCanFDmsg);/*for test .test ok*/

	switch (pstcCanFDmsg->idConfig.identifier )
	{
#if defined(CAN_STD_ID_USED)
	case CAN_TP_RXID:
		TpPrecopy(&tpmcrxStruct);
		break;
	case CAN_TP_FUNC_RXID:
		TpFuncPrecopy(&tpmcrxStruct);
		break;

#endif

#if defined(CAN_EXT_ID_USED)
	case CAN_TP_RXID:
		TpPrecopy(&tpmcrxStruct);
		break;
	case CAN_TP_FUNC_RXID:
		TpFuncPrecopy(&tpmcrxStruct);
		break;
#endif

	default:
		break;
	}

}
/******************************************************************************
* Name         :  CAN5_BusErrCallback
* Called by    :
* Preconditions:
* Parameters   :  None
* Return code  :  None
* Description  : This function is called for CAN channel 5 error callback
******************************************************************************/
void CAN5_BusErrCallback(cy_en_canfd_bus_error_t enCanFDError)
{
	if(enCanFDError == CY_CANFD_BUSOFF)
    {
        // Cy_CANFD_Init(CY_CANFD5_TYPE, &CAND_Ch5Cfg);
		CAND_Init();
		DELAY(100000);
    }/*TO DO*/;
}
/*______ P R I V A T E - F U N C T I O N S ___________________________________*/

CanTransmitHandle CanGetDynTxObj(CanTransmitHandle txHandle)
{
  return (txHandle);/*not use dynamic transmission,Do nothing now,to do*/
}

void CanDynTxObjSetDlc(CanTransmitHandle txHandle, vuint8 dlc)
{
	/*not use dynamic transmission,Do nothing now,to do*/
}
#if FBLM_CANFD_SUPPORT
/******************************************************************************
* Name         :  FblCanTransmit
* Called by    :
* Preconditions: CAN interface must be initialized before call
* Parameters   : tmtObject Pointer to TransmitObject
* Return code  : None
* Description  : This function transmits a CAN message
******************************************************************************/
vuint8 FblCanTransmit( tCanFdMsgObject* tmtObject )
{
	cy_stc_canfd_msg_t pstcCanmsg = {0u};
	vuint8 msgObject_Dlc = 0;
	/*Waiting for TX confirm*/
	if(kCanTxOk != Fblm_CanMsgTransmitted())
    {
	  return kFblCanTxInProgress;
	}
	else
	{
	  pstcCanmsg.canFDFormat = true;
	#if defined(CAN_STD_ID_USED)
      pstcCanmsg.idConfig.extended = FALSE;//to do
	#else
		pstcCanmsg.idConfig.extended = TRUE;//to do
	#endif
	  pstcCanmsg.idConfig.identifier = ((ulong)(tmtObject->msgObject.Id));
	  pstcCanmsg.dataConfig.dataLengthCode = tmtObject->msgObject.DLC;
#if 1 /*CANFD USED*/
	  if(tmtObject->msgObject.DLC <= FRAME_LENGTH )
	  {
	    memcpy((void*)(&(pstcCanmsg.dataConfig.data[0])),(void*)(&(tmtObject->msgObject.DataFld[0])),tmtObject->msgObject.DLC);
	  }
	  else
	  {
	  	if(0x09 == tmtObject->msgObject.DLC)
	  	{
	      msgObject_Dlc = 12u;
	  	}
	  	else if(0x0A == tmtObject->msgObject.DLC)
	  	{
	  	  msgObject_Dlc = 16u;
	  	}
	  	else if(0x0B == tmtObject->msgObject.DLC)
	  	{
	  	  msgObject_Dlc = 20u;
	  	}
	  	else if(0x0C == tmtObject->msgObject.DLC)
	  	{
	  	  msgObject_Dlc = 24u;
	  	}
	  	else if(0x0D == tmtObject->msgObject.DLC)
	  	{
	  	  msgObject_Dlc = 32u;
	  	}
	  	else if(0x0E == tmtObject->msgObject.DLC)
	  	{
	      msgObject_Dlc = 48u;
	  	}
	  	else if(0x0F == tmtObject->msgObject.DLC)
	  	{
	  	  msgObject_Dlc = 64u;
	  	}
	  	else
	  	{
	  	  msgObject_Dlc = 0x08u; /*error*/
	  	}
		msgObject_Dlc = tpTxInfoStruct[kTpTxChannelCount-1].DataLength;
		memcpy((void*)(&(pstcCanmsg.dataConfig.data[0])),(void*)(&(tmtObject->msgObject.DataFld[0])),msgObject_Dlc);
	  }
#else
	  memcpy((void*)(&(pstcCanmsg.dataConfig.data[0])),(void*)(&(tmtObject->msgObject.DataFld[0])),tmtObject->msgObject.DLC);
#endif
	  Cy_CANFD_UpdateAndTransmitMsgBuffer(CY_CANFD5_TYPE,0,&pstcCanmsg);
	  TxDynamicMsgId = ((ulong)(tmtObject->msgObject.Id));
	  return kCanTxOk; // to d0
	}

}
#else /*CAN USED*/
/******************************************************************************
* Name         :  FblCanTransmit
* Called by    :
* Preconditions: CAN interface must be initialized before call
* Parameters   : tmtObject Pointer to TransmitObject
* Return code  : None
* Description  : This function transmits a CAN message
******************************************************************************/
vuint8 FblCanTransmit( tMsgObject* tmtObject )
{
	cy_stc_canfd_msg_t pstcCanmsg = {0u};
	/*Waiting for TX confirm*/
	if(kCanTxOk != Fblm_CanMsgTransmitted())
    {
	  return kFblCanTxInProgress;
	}
	else
	{
	  pstcCanmsg.canFDFormat = FALSE;
	#if defined(CAN_STD_ID_USED)
      pstcCanmsg.idConfig.extended = FALSE;//to do
	#else
		pstcCanmsg.idConfig.extended = TRUE;//to do
	#endif
	  pstcCanmsg.idConfig.identifier = ((ulong)(tmtObject->msgObject.Id));
	  pstcCanmsg.dataConfig.dataLengthCode = tmtObject->msgObject.DLC;
	  memcpy((void*)(&(pstcCanmsg.dataConfig.data[0])),(void*)(&(tmtObject->msgObject.DataFld[0])),tmtObject->msgObject.DLC);
	  Cy_CANFD_UpdateAndTransmitMsgBuffer(CY_CANFD5_TYPE,0,&pstcCanmsg);
	  TxDynamicMsgId = ((ulong)(tmtObject->msgObject.Id));
	  return kCanTxOk; // to d0
	}

}
#endif
/* **************************************************************************
| NAME:             CanTransmit
| CALLED BY:        application
| PRECONDITIONS:    Can driver must be initialized
| INPUT PARAMETERS: Handle of the transmit object to be send
| RETURN VALUES:    kCanTxFailed: transmit failed
|                   kCanTxOk    : transmit was succesful
| DESCRIPTION:      If the CAN driver is not ready for send, the application
|                   decide, whether the transmit request is repeated or not.
************************************************************************** */
#if FBLM_CANFD_SUPPORT
vuint8 CanTransmit(CanTransmitHandle txHandle,tCanFdMsgObject * tmpPortingData)
#else
vuint8 CanTransmit(CanTransmitHandle txHandle,tMsgObject * tmpPortingData)
#endif
{
	/*Maybe can use difference buffer to send message*/
	TxDataPtr   CanMemCopySrcPtr = NULL;

	CanMemCopySrcPtr = (TxDataPtr) TxDynamicMsg0._c;


	tmpPortingData->msgObject.Id = CAN_TP_TXID;
#if FBLM_CANFD_SUPPORT
    if(TRUE == TpLongCanFdTxTransmit)
    {
      if( (8 < tpTxInfoStruct[kTpTxChannelCount-1].DataLength) && (12 >= tpTxInfoStruct[kTpTxChannelCount-1].DataLength))
    	  tmpPortingData->msgObject.DLC = 9u;
      else if( (12 < tpTxInfoStruct[kTpTxChannelCount-1].DataLength) && (16 >= tpTxInfoStruct[kTpTxChannelCount-1].DataLength))
    	  tmpPortingData->msgObject.DLC = 10u;
      else if( (16 < tpTxInfoStruct[kTpTxChannelCount-1].DataLength) && (20 >= tpTxInfoStruct[kTpTxChannelCount-1].DataLength))
          	  tmpPortingData->msgObject.DLC = 11u;
      else if( (20 < tpTxInfoStruct[kTpTxChannelCount-1].DataLength) && (24 >= tpTxInfoStruct[kTpTxChannelCount-1].DataLength))
          	  tmpPortingData->msgObject.DLC = 12u;
      else if( (24 < tpTxInfoStruct[kTpTxChannelCount-1].DataLength) && (32 >= tpTxInfoStruct[kTpTxChannelCount-1].DataLength))
          	  tmpPortingData->msgObject.DLC = 13u;
      else if( (32 < tpTxInfoStruct[kTpTxChannelCount-1].DataLength) && (48 >= tpTxInfoStruct[kTpTxChannelCount-1].DataLength))
          	  tmpPortingData->msgObject.DLC = 14u;
      else if( (48 < tpTxInfoStruct[kTpTxChannelCount-1].DataLength) && (64 >= tpTxInfoStruct[kTpTxChannelCount-1].DataLength))
          	  tmpPortingData->msgObject.DLC = 15u;
      else
    	  tmpPortingData->msgObject.DLC = 8u;

  //    tmpPortingData->msgObject.DLC = 15;
      for(uint8 count = 0; count < 64; count++)
      {
        tmpPortingData->msgObject.DataFld[count] = CanMemCopySrcPtr[count];
      }
    }
    else
    {
      tmpPortingData->msgObject.DLC = 8;
      tmpPortingData->msgObject.DataFld[0] = CanMemCopySrcPtr[0];
      tmpPortingData->msgObject.DataFld[1] = CanMemCopySrcPtr[1];
      tmpPortingData->msgObject.DataFld[2] = CanMemCopySrcPtr[2];
      tmpPortingData->msgObject.DataFld[3] = CanMemCopySrcPtr[3];
      tmpPortingData->msgObject.DataFld[4] = CanMemCopySrcPtr[4];
      tmpPortingData->msgObject.DataFld[5] = CanMemCopySrcPtr[5];
      tmpPortingData->msgObject.DataFld[6] = CanMemCopySrcPtr[6];
      tmpPortingData->msgObject.DataFld[7] = CanMemCopySrcPtr[7];
    }
#else
	tmpPortingData->msgObject.DLC = 8;

    tmpPortingData->msgObject.DataFld[0] = CanMemCopySrcPtr[0];
    tmpPortingData->msgObject.DataFld[1] = CanMemCopySrcPtr[1];
    tmpPortingData->msgObject.DataFld[2] = CanMemCopySrcPtr[2];
    tmpPortingData->msgObject.DataFld[3] = CanMemCopySrcPtr[3];
    tmpPortingData->msgObject.DataFld[4] = CanMemCopySrcPtr[4];
    tmpPortingData->msgObject.DataFld[5] = CanMemCopySrcPtr[5];
    tmpPortingData->msgObject.DataFld[6] = CanMemCopySrcPtr[6];
    tmpPortingData->msgObject.DataFld[7] = CanMemCopySrcPtr[7];
#endif

   return (kCanTxOk);/*to do*/
}
/* **************************************************************************
| NAME:             CanCancelTransmit
| CALLED BY:        application
| PRECONDITIONS:    Can driver can be cancel
| INPUT PARAMETERS: Handle of the transmit object to be send
| RETURN VALUES:    kCanTxFailed: transmit failed
|                   kCanTxOk    : transmit was succesful
| DESCRIPTION:      If the CAN driver is not ready for send, the application
|                   decide, whether the transmit request is repeated or not.
************************************************************************** */
vuint8 CanCancelTransmit(CanTransmitHandle txHandle)
{
  cy_pstc_canfd_type_t pstcCanFD = CY_CANFD5_TYPE;  /*Only for CANFD5*/
  vuint8 u8MsgBuf = 0;

  volatile stc_CANFD_CH_M_TTCAN_t* pstcCanFDChMTTCAN;
  cy_en_canfd_tx_buffer_status_t enTxBufferStatus;

  if ((pstcCanFD  == NULL ) ||
      (u8MsgBuf > 31)
     )
  {
      return CY_CANFD_TX_BUFFER_IDLE;
  }

  /* Get the pointer to M_TTCAN of the CAN FD channel */
  pstcCanFDChMTTCAN = &pstcCanFD->M_TTCAN;

  /* Initialize the return value */
  enTxBufferStatus = CY_CANFD_TX_BUFFER_IDLE;

  if((pstcCanFDChMTTCAN->unTXBRP.u32Register & (1ul << u8MsgBuf)) != 0)     // Pending transmission request.
  {
    /*cancel request issued*/
    pstcCanFDChMTTCAN->unTXBCR.u32Register |= (1ul << u8MsgBuf);
  }
}



void CanDynTxObjSetId(CanTransmitHandle txHandle, vuint16 id)
{
	/*Do nothing now,to do*/
}
void CanDynTxObjSetExtId(CanTransmitHandle txHandle, vuint16 Hignid , vuint16 Lowid)
{
	/*Do nothing now,to do*/
}

void VStdSuspendAllInterrupts()
{
	__disable_irq(); 
}

void VStdResumeAllInterrupts()
{
	__enable_irq();
}

void check_busoff_event(void)
{

    if(CY_CANFD5_TYPE -> M_TTCAN.unPSR.stcField.u1BO == 1)
    {
        CAND_Ch5Cfg.errorCallback(CY_CANFD_BUSOFF);
        CY_CANFD5_TYPE -> M_TTCAN.unPSR.stcField.u1BO = 0;
    }

}
/*______ L O C A L - F U N C T I O N S _______________________________________*/

/*______ E N D _____ (FileName.c) ____________________________________________*/
