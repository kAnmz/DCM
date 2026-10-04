/******************************************************************************/
/* @F_NAME :          can_config.h                                            */
/* @F_PURPOSE :       manage CAN driver for MCU                               */
/* @F_CREATED_BY :    Jianhua.Wu  			                                  */
/* @F_CREATION_DATE : 2021.07.30                                              */
/* @F_LANGUAGE :      ANSI C                                                  */
/* @F_MPROC_TYPE :    µC supported              						      */
/*************************************** (C) Copyright 2021 Marelli ***********/

#ifndef _CAN_CONFIG_H_
#define _CAN_CONFIG_H_

/*______ I N C L U D E - F I L E S ___________________________________________*/
#include "cy_project.h"
#include "cy_device_headers.h"
#include "can_def.h"
#include "tp_cfg.h"
#include "Platform_types.h"
/*______ G L O B A L - D E F I N E S _________________________________________*/
#define CAN_STD_ID_USED
//#define CAN_EXT_ID_USED

#define CAND_INACTIVE     0U
#define CAND_ACTIVE       1U
#define CAND_CHANNEL5     CAND_ACTIVE

#if 1 /* CAN CH5*/
#define	CAND_INT_DIV_CHANNEL5       (1u)
#define CAND_NON_ISO_OPERATION_CH5	 CAND_INACTIVE
#define CAND_CHANNEL5_TPMC_INDEX (0u)
#endif

#define kCanNumberOfHwChannels   (1u)
#define kCanNumberOfChannels     (1u)

#define CAND_CHANNEL6     CAND_INACTIVE
#define	CAND_INT_DIV_CHANNEL6       (1u)
#define CAND_NON_ISO_OPERATION_CH6	 CAND_INACTIVE
#define CAND_CHANNEL6_TPMC_INDEX    (0u)

/*______ G L O B A L - T Y P E S _____________________________________________*/

/*______ G L O B A L - D A T A _______________________________________________*/
typedef struct tTmpMsgObjTag
{
  vuint32 Id;
  vuint32 Dlc;
  union
  { /* PRQA S 0750 */ /* MD_Can_0750 */
    vuint8  bData[8];
    vuint16 wData[4];
    vuint32 iData[2];
  } u;
} tTmpMsgObj;/*The same can_drv.c,CanRxActualDLC need to check with this*/

typedef struct tTmpCanFdMsgObjTag
{
  vuint32 Id;
  vuint32 Dlc;
  union
  { /* PRQA S 0750 */ /* MD_Can_0750 */
    vuint8  bData[64];
    vuint16 wData[32];
    vuint32 iData[16];
  } u;
} tTmpCanFdMsgObj;/*The same can_drv.c,CanRxActualDLC need to check with this*/

/*______ G L O B A L - M A C R O S ___________________________________________*/

/*______ G L O B A L - F U N C T I O N S - P R O T O T Y P E S _______________*/
extern void CAND_Init(void);
extern void CAND_DeInit(void);
#if 1/* CAN CH5*/
extern void CAN5_BusErrCallback(cy_en_canfd_bus_error_t enCanFDError);
extern void CAN5_RxMsgCallback(bool bRxFifoMsg, uint8 u8MsgBufOrRxFifoNum, cy_stc_canfd_msg_t* pstcCanFDmsg);
extern void CAN5_TxMsgCallback(void);
extern void CAN_RxFifoWithTopCallback(uint8 u8FifoNum, uint8   u8BufferSizeInWord, cy_stc_canfd_msg_t* pu32RxBuf);

#endif

extern void CAN6_BusErrCallback(cy_en_canfd_bus_error_t enCanFDError);
extern void CAN6_RxMsgCallback(bool bRxFifoMsg, uint8 u8MsgBufOrRxFifoNum, cy_stc_canfd_msg_t* pstcCanFDmsg);
extern void CAN6_TxMsgCallback(void);
extern void check_busoff_event(void);
#endif /* _CAN_CONFIG_H_ */
