/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2025 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!        \file  Lin_GeneralTypes.h
 *        \brief  AUTOSAR LIN General types header
 *
 *      \details  AUTOSAR LIN General types header for the LIN stack
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *   1.00.00  2020-01-08  visjgl                create new Lin General Types
 *   1.00.01  2020-03-27  visjgl                rework Review findings
 *   2.00.00  2024-12-11  visjgl                added compatibility support for the Frame Response Type
 *   2.01.00  2025-07-21  visjgl  LIN-1393      include Std_Types and add numerical representation of enum
 *********************************************************************************************************************/

#if !defined (LIN_GENERALTYPES_H)
# define LIN_GENERALTYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
# include "Std_Types.h"

/*!
  \name LIN General Types
  \{
*/

/**********************************************************************************************************************
 * LIN General Types
 *********************************************************************************************************************/

/*! [Defined by AUTOSAR]: LIN operation states for a LIN channel or frame, as returned by the API service
                          Lin_GetStatus(). */
typedef enum Lin_StatusTypeTag
{
  /*! LIN frame operation return value.
      Development or production error occurred. */
  LIN_NOT_OK = 0x00u,

  /*! LIN frame operation return value.
      Successful transmission. */
  LIN_TX_OK = 0x01u,

  /*! LIN frame operation return value.
      Ongoing transmission (Header or Response). */
  LIN_TX_BUSY = 0x02u,

  /*! LIN frame operation return value.
      Erroneous header transmission such as:
       - Mismatch between sent and read back data
       - Identifier parity error or
       - Physical bus error */
  LIN_TX_HEADER_ERROR = 0x03u,

  /*! LIN frame operation return value.
      Erroneous response transmission such as:
       - Mismatch between sent and read back data
       - Physical bus error */
  LIN_TX_ERROR = 0x04u,

  /*! LIN frame operation return value.
      Successful frame response reception. */
  LIN_RX_OK = 0x05u,

  /*! LIN frame operation return value.
      Ongoing reception: at least one response byte has been received, but the checksum byte has not been received. */
  LIN_RX_BUSY = 0x06u,

  /*! LIN frame operation return value.
      Erroneous response reception such as:
       - Framing error
       - Overrun error
       - Checksum error or
       - Short response */
  LIN_RX_ERROR = 0x07u,

  /*! LIN frame operation return value.
      No response byte has been received. */
  LIN_RX_NO_RESPONSE = 0x08u,

  /*! LIN channel state return value.
      Normal operation; the related LIN channel is ready to transmit next header. No data from previous frame available
      (e.g. after initialization). */
  LIN_OPERATIONAL = 0x09u,

  /*! LIN channel state return value.
      Sleep state operation; in this state wake-up detection from responder nodes is enabled. */
  LIN_CH_SLEEP = 0x0Au
} Lin_StatusType;

/*! [Defined by AUTOSAR]: This type represents the slave error types that are detected during header reception and
                          response transmission / reception. */
typedef enum Lin_SlaveErrorTypeTag
{
  /*! Error in header. */
  LIN_ERR_HEADER = 0x00u,

  /*! Framing error in response. */
  LIN_ERR_RESP_STOPBIT = 0x01u,

  /*! Checksum error. */
  LIN_ERR_RESP_CHKSUM = 0x02u,

  /*! Monitoring error of transmitted data bit in response. */
  LIN_ERR_RESP_DATABIT = 0x03u,

  /*! No response. */
  LIN_ERR_NO_RESP = 0x04u,

  /*! Incomplete response. */
  LIN_ERR_INC_RESP = 0x05u
} Lin_SlaveErrorType;


/*! [Defined by Vector]: Pointer to a shadow buffer or memory mapped LIN hardware receive buffer where the current SDU
                         is stored. */
typedef P2VAR(uint8, TYPEDEF, AUTOMATIC) Lin_u8PtrType;

/*! [Defined by Vector]: Pointer to pointer to a shadow buffer or memory mapped LIN hardware receive buffer where the
                         current SDU is stored. */
typedef P2VAR(Lin_u8PtrType, TYPEDEF, AUTOMATIC) Lin_u8PtrPtrType;


/*! [Defined by AUTOSAR]: Represents all valid protected identifier used by Lin_SendFrame(). */
typedef uint8 Lin_FramePidType;


/*! [Defined by AUTOSAR]: This type is used to specify the checksum model to be used for the LIN frame. */
typedef enum Lin_FrameCsModelTypeTag
{
  /*! Enhanced checksum model. */
  LIN_ENHANCED_CS = 0x00u,
  /*! Classic checksum model. */
  LIN_CLASSIC_CS = 0x01u
} Lin_FrameCsModelType;


/*! [Defined by AUTOSAR, extended by Vector]: This type is used to specify whether the frame processor is required to
                                              transmit the response part of the LIN frame. */
typedef enum Lin_FrameResponseTypeTag
{
  /*! Lin_FrameResponseType according to AUTOSAR <= 4.3.1 */
  LIN_MASTER_RESPONSE = 0x00u, /*!< Response is generated from this (master) node */
  LIN_SLAVE_RESPONSE  = 0x01u, /*!< Response is generated from a remote slave node */
  LIN_SLAVE_TO_SLAVE  = 0x02u, /*!< Response is generated from one slave to another slave */

  /*!  Lin_FrameResponseType according to AUTOSAR >= 4.4.0 */
  LIN_FRAMERESPONSE_TX     = 0x00u, /*!< Response is generated by this node. */
  LIN_FRAMERESPONSE_RX     = 0x01u, /*!< Response is generated by another node. */
  LIN_FRAMERESPONSE_IGNORE = 0x02u  /*!< Response is ignored by this node. */
} Lin_FrameResponseType;



/*! [Defined by AUTOSAR]: This type is used to specify the number of SDU data bytes to copy.
                          Range: 1 - 8, data length of a LIN frame. */
typedef uint8 Lin_FrameDlType;


/*! [Defined by AUTOSAR]: This type is used to provide PID, checksum model, data length and SDU pointer of a LIN frame
                          from the LIN Interface to the LIN driver. */
typedef struct Lin_PduTypeTag
{
  /*! Valid protected identifier. */
  VAR(Lin_FramePidType, TYPEDEF)      Pid;
  /*! Specified Checksum model. */
  VAR(Lin_FrameCsModelType, TYPEDEF)  Cs;
  /*! Type of response part. */
  VAR(Lin_FrameResponseType, TYPEDEF) Drc;
  /*! Number of SDU data bytes to copy. */
  VAR(Lin_FrameDlType, TYPEDEF)       Dl;
  /*! Pointer to SDU data bytes. */
  P2VAR(uint8, TYPEDEF, AUTOMATIC) SduPtr;
} Lin_PduType;

/*! [Defined by Vector]: Pointer Type for the Lin_PduType */
typedef P2VAR(Lin_PduType, TYPEDEF, AUTOMATIC) Lin_PduPtrType;

/*! \} */

/*!
  \name LIN Transceiver General Types
  \{
*/

/**********************************************************************************************************************
 * LIN Transceiver General Types
 *********************************************************************************************************************/

/*! [Defined by AUTOSAR]: This type is used to indicate and set the operation mode of the transceiver. */
typedef enum LinTrcv_TrcvModeTypeTag
{
  /*! Normal mode. */
  LINTRCV_TRCV_MODE_NORMAL = 0x00u,
  /*! Standby mode. */
  LINTRCV_TRCV_MODE_STANDBY = 0x01u,
  /*! Sleep mode. */
  LINTRCV_TRCV_MODE_SLEEP = 0x02u
} LinTrcv_TrcvModeType;

/*! [Defined by AUTOSAR]: This type is used to configure the wakeup setting of the transceiver. */
typedef enum LinTrcv_TrcvWakeupModeTypeTag
{
  /*! Enable wakeup reporting. */
  LINTRCV_WUMODE_ENABLE = 0x00u,
  /*! Disable wakeup reporting. */
  LINTRCV_WUMODE_DISABLE = 0x01u,
  /*! Clear the stored wakeup reason. */
  LINTRCV_WUMODE_CLEAR = 0x02u
} LinTrcv_TrcvWakeupModeType;

/*! [Defined by AUTOSAR]: This type is used to indicate the wakeup reason. */
typedef enum LinTrcv_TrcvWakeupReasonTypeTag
{
  /*! Error, wakeup reason was not detected. */
  LINTRCV_WU_ERROR = 0x00u,
  /*! Wakeup reporting is not supported. */
  LINTRCV_WU_NOT_SUPPORTED = 0x01u,
  /*! Wakeup caused by the network was detected. */
  LINTRCV_WU_BY_BUS = 0x02u,
  /*! Wakeup caused by a transceiver pin was detected. */
  LINTRCV_WU_BY_PIN = 0x03u,
  /*! Wakeup caused by a ECU request was detected. */
  LINTRCV_WU_INTERNALLY = 0x04u,
  /*! Wakeup caused by a ECU reset was detected. */
  LINTRCV_WU_RESET = 0x05u,
  /*! Wakeup caused by a ECU reset after power on was detected. */
  LINTRCV_WU_POWER_ON = 0x06u
} LinTrcv_TrcvWakeupReasonType;

/*! \} */

#endif /* LIN_GENERALTYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: Lin_GeneralTypes.h
 *********************************************************************************************************************/

