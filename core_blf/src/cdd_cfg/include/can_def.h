/******************************************************************************/
/* @F_NAME :          can_def.h                                               */
/* @F_PURPOSE :       manage CAN driver for MCU                               */
/* @F_CREATED_BY :    Jianhua.Wu  			                                  */
/* @F_CREATION_DATE : 2021.07.14                                              */
/* @F_LANGUAGE :      ANSI C                                                  */
/* @F_MPROC_TYPE :    target independent           						      */
/*************************************** (C) Copyright 2021 Marelli ***********/

#ifndef _CAN_DEF_H_
#define _CAN_DEF_H_
#include "v_cfg.h"
#include "v_def.h"
/*______ I N C L U D E - F I L E S ___________________________________________*/

#define C_ENABLE_EXTENDED_ID


/*______ G L O B A L - T Y P E S _____________________________________________*/
/* 8-Bit qualifier */
#if !defined( vuint8 ) /* ASR compatibility */
//typedef unsigned char  vuint8;
#endif

/* 16-Bit qualifier */
#if !defined( vuint16 ) /* ASR compatibility */
//typedef unsigned short vuint16;
#endif

/* 32-Bit qualifier */
#if !defined( vuint32 ) /* ASR compatibility */
//typedef unsigned long  vuint32;
#endif

#define canuint8 vuint8
#define canuint16 vuint16
#define canuint32 vuint32

typedef vuint16 tTpDataType;


typedef vuint16           CanTransmitHandle;
typedef vuint16           CanReceiveHandle;
typedef vuint8           CanChannelHandle;

typedef volatile vuint32*  CanChipMsgPtr;
typedef volatile vuint8*  CanChipDataPtr;

typedef struct
{
  CanChannelHandle  Channel;
  CanChipMsgPtr     pChipMsgObj;
  CanChipDataPtr    pChipData;
  CanReceiveHandle  Handle;
/* CPU-specific part */
} tCanRxInfoStruct;

typedef tCanRxInfoStruct          *CanRxInfoStructPtr;

/** CAN register map */
typedef volatile struct
{
   vuint32 Id;               /**< Complete ID                                    */
   vuint8  DLC;              /**< Data length reg.:  X X X X DLC3 DLC2 DLC1 DLC0 */
   vuint8  DataFld[8];       /**< Data 0 .. 7                                    */
} tInternalMsgObject;

typedef volatile struct
{
   tInternalMsgObject msgObject;
   void (*ConfirmationFct)(vuint8 handle);
} tMsgObject;

typedef union _c_TxDynamicMsg0_bufTag
{
  vuint8 _c[64];
} _c_TxDynamicMsg0_buf;

/** CANFD register map */
typedef volatile struct
{
   vuint32 Id;               /**< Complete ID                                    */
   vuint8  DLC;              /**< Data length reg.:  X X X X DLC3 DLC2 DLC1 DLC0 */
   vuint8  DataFld[64];       /**< Data 0 .. 7                                    */
} tInternalCanFdMsgObject;

typedef volatile struct
{
	tInternalCanFdMsgObject msgObject;
   void (*ConfirmationFct)(vuint8 handle);
} tCanFdMsgObject;
/*______ G L O B A L - D E F I N E S _________________________________________*/
#define C_SINGLE_RECEIVE_CHANNEL
#define CanTxTxDynamicMsg0                   1

/* CanGetDynTxObj return values ----------------------------------------------- */
#define kCanNoTxDynObjAvailable     ((CanTransmitHandle)0xFFFFFFFFU)

/* return values for precopy-routines */
#define kCanNoCopyData                          ((vuint8)0x00)
#define kCanCopyData                            ((vuint8)0x01)

# define kCanTxFailed                            ((vuint8)0x00)  /* Tx path switched off or no sending possible */
# define kCanTxOk                                ((vuint8)0x01)  /* msg transmitted or in queue                 */
#define kFblCanTxInProgress          			 ((vuint8)0x02)

#define CanInterruptDisable()	(VStdSuspendAllInterrupts())
#define CanInterruptRestore()   (VStdResumeAllInterrupts())


//#define TpGlobalInterruptDisable()    (VStdSuspendAllInterrupts())
//#define TpGlobalInterruptRestore()    (VStdResumeAllInterrupts())

/* return values of CanRxActualIdType */
#define kCanIdTypeStd           (0x00000000UL)
#define kCanIdTypeExt           (0x80000000UL)
#define kCanStdIdMask           (0x000007FFUL)
#define kCanExtIdMask           (0x1FFFFFFFUL)
#define kCanDlcLogMask          (0x0FU)

typedef vuint32          tCanIdType;
/*Littile-endian we used*/
#define CanRxActualIdType(rxStruct)       ((tCanIdType)(*(rxStruct->pChipMsgObj) & kCanIdTypeExt))                               /* return code has to be tCanIdType */
#define CanRxActualExtId(rxStruct)        ((vuint32)(*(rxStruct->pChipMsgObj) & kCanExtIdMask))                                  /* return code has to be vuint32    */
#define CanRxActualStdId(rxStruct)        ((vuint16)(*(rxStruct->pChipMsgObj) & kCanStdIdMask))                                  /* return code has to be vuint16    */
#define CanRxActualData(rxStruct,i)       ((vuint8) (*(rxStruct->pChipData+(i))))                                                /* return code has to be vuint8     */
#define CanRxActualDLC(rxStruct)          ((vuint8)((*(rxStruct->pChipMsgObj+0x01)) & kCanDlcLogMask)) 	 						/* return code has to be vuint8     */


#if defined( C_ENABLE_EXTENDED_ID )
#define CanRxActualId(rxStruct)     (CanRxActualExtId(rxStruct))
#else
#define CanRxActualId(rxStruct)    (CanRxActualStdId(rxStruct))
#endif

/*______ G L O B A L - D A T A _______________________________________________*/
extern  _c_TxDynamicMsg0_buf TxDynamicMsg0;
/*______ G L O B A L - M A C R O S ___________________________________________*/

/*______ G L O B A L - F U N C T I O N S - P R O T O T Y P E S _______________*/
extern vuint8 TpFuncPrecopy(CanRxInfoStructPtr rxStruct);
extern vuint8 TpPrecopy(CanRxInfoStructPtr rxStruct);
extern CanTransmitHandle CanGetDynTxObj(CanTransmitHandle txHandle );
extern void CanDynTxObjSetDlc(CanTransmitHandle txHandle, vuint8 dlc);
#if 1
extern vuint8 FblCanTransmit(tCanFdMsgObject* tmtObject);
extern vuint8 CanTransmit(CanTransmitHandle txHandle,tCanFdMsgObject * tmpPortingData);
#else
extern vuint8 FblCanTransmit(tMsgObject* tmtObject);
extern vuint8 CanTransmit(CanTransmitHandle txHandle,tMsgObject * tmpPortingData);
#endif


extern vuint8 CanCancelTransmit(CanTransmitHandle txHandle);
extern void CanDynTxObjSetId(CanTransmitHandle txHandle, vuint16 id);
extern void CanDynTxObjSetExtId(CanTransmitHandle txHandle, vuint16 Hignid , vuint16 Lowid);
extern void TpDrvConfirmation(CanTransmitHandle txObject);
#endif /* _CAN_DEF_H_ */
