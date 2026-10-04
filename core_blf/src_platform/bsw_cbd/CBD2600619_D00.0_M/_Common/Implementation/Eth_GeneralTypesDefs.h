/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2025 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Eth_GeneralTypesDefs.h
 *        \brief  General types header for the Ethernet stack
 *
 *      \details  Holds general data types and defines provided to and used by multiple components of the Vector
 *                Ethernet stack.
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to Eth_GeneralTypes.h
 *********************************************************************************************************************/

#ifndef ETH_GENERAL_TYPES_DEFS_H
# define ETH_GENERAL_TYPES_DEFS_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
# include "Std_Types.h"
# include "ComStack_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/* ETH modes */
# define ETH_MODE_DOWN                                   (0x00u)
# define ETH_MODE_ACTIVE                                 (0x01u)
# define ETH_MODE_ACTIVE_WITH_WAKEUP_REQUEST             (0x02u)
# define ETH_MODE_ACTIVE_TX_OFFLINE                      (0x03u)

/* ETH return type */
# define ETH_OK                                          (0x00u)
# define ETH_E_NOT_OK                                    (0x01u)
# define ETH_E_NO_ACCESS                                 (0x02u)

/* ETH RX status type */
# define ETH_RECEIVED                                    (0x00u)
# define ETH_NOT_RECEIVED                                (0x01u)
# define ETH_RECEIVED_MORE_DATA_AVAILABLE                (0x02u)
# define ETH_RECEIVED_FRAMES_LOST                        (0x03u)

/* ETH filter action types */
# define ETH_ADD_TO_FILTER                               (0x00u)
# define ETH_REMOVE_FROM_FILTER                          (0x01u)

/* ETH states */
# define ETH_STATE_UNINIT                                (0x00u)
# define ETH_STATE_INIT                                  (0x01u)
# define ETH_STATE_ACTIVE                                (0x02u)
# define ETH_STATE_MODE_DOWN                             (0x03u)
# define ETH_STATE_MODE_ACTIVE                           (0x04u)

/* ETH MII modes */
# define ETH_MII_MODE                                    (0x00u)
# define ETH_RMII_MODE                                   (0x01u)
# define ETH_GMII_MODE                                   (0x02u)
# define ETH_RGMII_MODE                                  (0x03u)
# define ETH_SGMII_MODE                                  (0x04u)
# define ETH_USXGMII_MODE                                (0x05u)

# define ETH_INVALID_FRAME_ID                            (0x00u)

# define ETH_PHYS_ADDR_LEN_BYTE                          (6u)
# define ETH_ETHER_TYPE_LEN_BYTE                         (2u)
# define ETH_HEADER_LEN_BYTE                             (14u)

/* ETH Timestamp Quality Types */
# define ETH_TIMESTAMP_VALID                             (0u)
# define ETH_TIMESTAMP_INVALID                           (1u)
# define ETH_TIMESTAMP_UNCERTAIN                         (2u)

/* ETH Timestamp Quality Types */
# define ETH_VALID                                       (0u) /* Timestamp is valid */
# define ETH_INVALID                                     (1u) /* Timestamp is invalid */
# define ETH_UNCERTAIN                                   (2u) /* Status of timestamp is uncertain */

/*! Value defining that the counter isn't supported */
# define ETH_RXTX_STATS_INV_COUNTER_VAL                  (0xFFFFFFFFu)
/*! Value defining that the counter has overflown */
# define ETH_RXTX_STATS_COUNTER_OVERFLOW_VAL             (0xFFFFFFFEu)
/*! Value defining the maximum possible counter value */
# define ETH_RXTX_STATS_MAX_COUNTER_VAL                  (0xFFFFFFFDu)

/* Transceiver speeds in [bit/s] */
# define ETH_TRCV_SPEED_10MBITS_IN_BITS                  (10000000u)
# define ETH_TRCV_SPEED_100MBITS_IN_BITS                 (100000000u)
# define ETH_TRCV_SPEED_1000MBITS_IN_BITS                (1000000000u)
# define ETH_TRCV_SPEED_2500MBITS_IN_BITS                (2500000000u)
# define ETH_TRCV_SPEED_5000MBITS_IN_BITS                (5000000000u)
# define ETH_TRCV_SPEED_10000MBITS_IN_BITS               (10000000000u)
# define ETH_TRCV_SPEED_DONT_CARE                        (0xFFFFFFFFu)

/* ETH Measurement Index Types */
# define ETH_MEAS_ALL                                    (0xFFu)
# define ETH_MEAS_VENDOR_SPECIFIC_DROP_INSUFF_TX_BUFFER  (0x90u)
# define ETH_MEAS_VENDOR_SPECIFIC_WARN_FULL_RX_BUFFER    (0x91u)
# define ETH_MEAS_VENDOR_SPECIFIC_DROP_INSUFF_RX_BUFFER  (0x92u)

# ifndef NO_ETH_RATE_DEVIATION_TYPE_IN_ETH_GENERAL_TYPES
/* Type that indicates the current status of the rate calculation */
#  define ETH_RATE_OK                                    (0x00u) /* A valid rate deviaton value is available/calculated */
#  define ETH_RATE_NOT_AVAILABLE                         (0xFEu) /* No valid rate deviation value available/calculated */
#  define ETH_RATE_EXCEEDED                              (0xFFu) /* The calculated rate deviation value exceeds limits */
# endif /* NO_ETH_RATE_DEVIATION_TYPE_IN_ETH_GENERAL_TYPES */

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef uint8          Eth_ReturnType;
typedef uint8          Eth_ModeType;
typedef uint16         Eth_FrameType;
typedef uint8          Eth_DataType;
typedef uint8          Eth_RxStatusType;
typedef uint8          Eth_FilterActionType;
typedef uint32         Eth_BufIdxType;
typedef uint8          Eth_StateType;
typedef uint8          Eth_MeasurementIdxType;
# ifndef NO_ETH_RATE_DEVIATION_TYPE_IN_ETH_GENERAL_TYPES
typedef uint8          Eth_RateDeviationStatusType;
# endif /* NO_ETH_RATE_DEVIATION_TYPE_IN_ETH_GENERAL_TYPES */

/* ETH Physical Address Type */
typedef uint8 Eth_PhysAddrType[ETH_PHYS_ADDR_LEN_BYTE];

/* If the TimeStampType is defined in ComStack_Types.h then typedef the Eth_TimeStampType to TimeStampType.
   Otherwise define the Eth_TimeStampType explicitly */
# ifdef TIME_STAMP_TYPE
typedef TimeStampType  Eth_TimeStampType;
# else
/*! \brief Type defining a time stamp according to AUTOSAR 4.2 */
typedef struct
{
  uint32 nanoseconds;
  uint32 seconds;
  uint16 secondsHi;
} Eth_TimeStampType;

/* Definition of AR23-11 TimeStamp types if they are not defined through ComStack_Types.h to provide backward
   compatibility */
typedef struct
{
  uint32 nanoseconds; /* Nanoseconds part of the time */
  uint32 seconds;     /* 32 bit LSB of the 48 bits Seconds part of the time */
  uint16 secondsHi;   /* 16 bit MSB of the 48 bits Seconds part of the time */
} TimeStampType;      /* ASR CP R23-11 */

typedef enum
{
  VALID     = 0,     /* Timestamp is valid */
  INVALID   = 1,     /* Timestamp is invalid */
  UNCERTAIN = 2      /* Status of timestamp is uncertain */
} TimeStampQualType; /* ASR CP R23-11 */

typedef struct
{
  TimeStampType timestampClockValue;   /* Value of the clock, which is used of ingress/egress timestamping */
  TimeStampType disciplinedClockValue; /* Value of the adjustable HW clock */
  TimeStampQualType timeQuality;       /* Status of time tuple */
} TimeTupleType;
# endif /* TIME_STAMP_TYPE */

/*! \brief Type defining the quality of a time stamp */
typedef uint8    Eth_TimestampQualityType;

/*! \brief Type defining the quality of a time stamp */
typedef uint8 Eth_TimeStampQualType;

/* Define ETH_TIMESTAMP_QUAL_TYPE_IN_ETH_GENERAL_TYPES to indicate that Eth_TimestampQualType is available in Eth_GeneralTypes. */
#define ETH_TIMESTAMP_QUAL_TYPE_IN_ETH_GENERAL_TYPES

/*! \brief Vector type defining the difference between time stamps */
typedef sint32   Eth_TimediffType;

/*! \brief AUTOSAR type defining the difference between time stamps */
typedef struct
{
  Eth_TimeStampType diff;
  boolean sign;
} Eth_TimeIntDiffType;

/*! \brief Type defining the drift of a clock related to another clock */
typedef struct
{
  Eth_TimeIntDiffType IngressTimeStampDelta;
  Eth_TimeIntDiffType OriginTimeStampDelta;
} Eth_RateRatioType;

/*! brief Type to read out addresses from the address resolution logic (ARL) table of the switch */
typedef struct
{
  uint8  MacAddr[6];
  uint16 VlanId;
  uint32 SwitchPort;
} Eth_MacVlanType;

/*! brief Structure holding statistic counters for diagnostics */
typedef struct
{
  uint32 DropPktBufOverrun;
  uint32 DropPktCrc;
  uint32 UndersizePkt;
  uint32 OversizePkt;
  uint32 AlgnmtErr;
  uint32 SqeTestErr;
  uint32 DiscInbdPkt;
  uint32 ErrInbdPkt;
  uint32 DiscOtbdPkt;
  uint32 ErrOtbdPkt;
  uint32 SnglCollPkt;
  uint32 MultCollPkt;
  uint32 DfrdPkt;
  uint32 LatCollPkt;
  uint32 HwDepCtr0;
  uint32 HwDepCtr1;
  uint32 HwDepCtr2;
  uint32 HwDepCtr3;
} Eth_CounterType;

/*! \brief Structure holding transmission statistic counters related to the Eth controller. */
typedef struct
{
  uint32 TxNumberOfOctets;
  uint32 TxNUcastPkts;
  uint32 TxUniCastPkts;
} Eth_TxStatsType;

/*! brief Structure holding reception statistic counters related to the Eth controller. */
typedef struct
{
  uint32 RxStatsDropEvents;
  uint32 RxStatsOctets;
  uint32 RxStatsPkts;
  uint32 RxStatsBroadcastPkts;
  uint32 RxStatsMulticastPkts;
  uint32 RxStatsCrcAlignErrors;
  uint32 RxStatsUndersizePkts;
  uint32 RxStatsOversizePkts;
  uint32 RxStatsFragments;
  uint32 RxStatsJabbers;
  uint32 RxStatsCollisions;
  uint32 RxStatsPkts64Octets;
  uint32 RxStatsPkts65to127Octets;
  uint32 RxStatsPkts128to255Octets;
  uint32 RxStatsPkts256to511Octets;
  uint32 RxStatsPkts512to1023Octets;
  uint32 RxStatsPkts1024to1518Octets;
  uint32 RxUnicastFrames;
} Eth_RxStatsType;

/*! brief Type for statistic counters for tx diagnostics. */
typedef struct
{
  uint32 TxDroppedNoErrorPkts;
  uint32 TxDroppedErrorPkts;
  uint32 TxDeferredTrans;
  uint32 TxSingleCollision;
  uint32 TxMultipleCollision;
  uint32 TxLateCollision;
  uint32 TxExcessiveCollison;
} Eth_TxErrorCounterValuesType;

# ifndef NO_ETH_SPI_STATUS_TYPE_IN_ETH_GENERAL_TYPES
/*! brief Type to return the Spi status, errors and configuration state. */
typedef struct
{
  uint32  SpiStatusRegister;
  boolean Sync;
  uint8   BufferStatusTxCredit;
  uint8   BufferStatusRxCredit;
} Eth_SpiStatusType;
# endif /* NO_ETH_SPI_STATUS_TYPE_IN_ETH_GENERAL_TYPES */

# ifndef NO_ETH_RATE_DEVIATION_TYPE_IN_ETH_GENERAL_TYPES
/*! brief Rate deviation value and status */
typedef struct
{
  sint32                      rateDeviationValue;  /* Rate deviation value (resolution: 2^{-32}) */
  Eth_RateDeviationStatusType rateDeviationStatus; /* Current state of the rate deviation calculation */
} Eth_RateDeviationType;
# endif /* NO_ETH_RATE_DEVIATION_TYPE_IN_ETH_GENERAL_TYPES */

/*! brief Type for holding the bucket counter values for a stream */
typedef struct
{
  uint8  BucketIdx;    /* Bucket Index */
  uint32 CounterValue; /* Bucket counter value */
} Eth_StreamStatisticCounterType;

/*! brief Type to return the pre-correction time, applied rate deviation and new PHC rate. */
typedef struct
{
  TimeStampType PreCorrTime;          /* Value of the PHC right before the correction is applied. */
  sint32        AppliedRateDeviation; /* The actual applied rate deviation (resolution: 2^{-32}). Although this parameter could be calculated using "NewPhcRate", it is explicitly returned to avoid inaccuracies in the calculation on UL side. */
  sint32        NewPhcRate;           /* The resulting new rate of the PHC compared to initialization (1.0) (resolution: 2^{-32}). */
} Eth_PhcCorrInfoType;

#endif /* ETH_GENERAL_TYPES_DEFS_H */

/**********************************************************************************************************************
 *  END OF FILE:  Eth_GeneralTypesDefs.h
 *********************************************************************************************************************/
