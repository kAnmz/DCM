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
/**        \file  EthSwt_GeneralTypes.h
 *        \brief  General Type Header of MICROSAR Ethernet Switch Driver
 *
 *      \details  The General Type Header contains the data types used.
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to Eth_GeneralTypes.h
 *********************************************************************************************************************/

#if !defined (ETHSWT_GENERALTYPES_H)
# define ETHSWT_GENERALTYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
# ifndef ETH_GENERAL_TYPES_H
#  include "Eth_GeneralTypesDefs.h"
#  include "EthTrcv_GeneralTypes.h"
# endif

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/*! Vendor and module identification */
# define ETHSWT_30_VECTOR_VENDOR_ID             (30u)
# define ETHSWT_30_VECTOR_MODULE_ID             (89u)

/*! EthSwt_StateType values */
/*! \trace SPEC-2265331 */
# define ETHSWT_STATE_UNINIT                  (0x00u)
# define ETHSWT_STATE_INIT                    (0x01u)
# define ETHSWT_STATE_ACTIVE                  (0x02u)

/*! EthSwt_MacLearningType values */
/*! \trace SPEC-2265334 */
# define ETHSWT_MACLEARNING_HWDISABLED        (0x00u)
# define ETHSWT_MACLEARNING_HWENABLED         (0x01u)
# define ETHSWT_MACLEARNING_SWENABLED         (0x02u)

/*! EthSwt_PortModeType values */
# define ETHSWT_MODE_DOWN_SWITCHPORT          ETHTRCV_MODE_DOWN
# define ETHSWT_MODE_ACTIVE_SWITCHPORT        ETHTRCV_MODE_ACTIVE

/*! EthSwt_VlanFwType values */
# define ETHSWT_NOT_SENT                      (0x00u)
# define ETHSWT_SENT_TAGGED                   (0x01u)
# define ETHSWT_SENT_UNTAGGED                 (0x02u)

/*! Enumeration values for type EthSwt_PhysicalLayerType */
# define ETHSWT_PORT_BROAD_R_REACH               (0u)
# define ETHSWT_PORT_BASE_T                      (1u)
# define ETHSWT_PORT_RTPGE                       (2u)
# define ETHSWT_PORT_X_MII                       (3u)
# define ETHSWT_PORT_INTERNAL                    (4u)
# define ETHSWT_PORT_10BASE_T1S                  (5u)

/*! Enumeration values for the different possible speed configurations of a switch port */
# define ETHSWT_PORT_SPEED_10                 ETHTRCV_BAUD_RATE_10MBIT
# define ETHSWT_PORT_SPEED_100                ETHTRCV_BAUD_RATE_100MBIT
# define ETHSWT_PORT_SPEED_1000               ETHTRCV_BAUD_RATE_1000MBIT
# define ETHSWT_PORT_SPEED_2500               ETHTRCV_BAUD_RATE_2500MBIT
# define ETHSWT_PORT_SPEED_5000               ETHTRCV_BAUD_RATE_5000MBIT
# define ETHSWT_PORT_SPEED_10000              ETHTRCV_BAUD_RATE_10000MBIT
# define ETHSWT_PORT_SPEED_DONT_CARE          (0xFFu)

/*! Enumeration values for the different possible duplex mode configurations of a switch port */
#define ETHSWT_DUPLEX_MODE_HALF               ETHTRCV_DUPLEX_MODE_HALF
#define ETHSWT_DUPLEX_MODE_FULL               ETHTRCV_DUPLEX_MODE_FULL

/*! Enumeration values for type EthSwt_XMiiPortMgmtType */
# define ETHSWT_NO_PHY                           (0u)
# define ETHSWT_PHY_MANAGED_BY_MCU               (1u)
# define ETHSWT_PHY_MANAGED_BY_SWITCH            (2u)

/*! Enumeration values for type EthSwt_XMiiPortConnectionType */
#define ETHSWT_RVMII                          (0x00u)
#define ETHSWT_MII                            (0x01u)
#define ETHSWT_RGMII                          (0x02u)
#define ETHSWT_SGMII                          (0x03u)
#define ETHSWT_USXGMII                        (0x04u)
#define ETHSWT_HISGMII                        (0x05u)
#define ETHSWT_RMII                           (0x06u)
#define ETHSWT_XGMII                          (0x07u)

/*! Enumeration values for type EthSwt_MCastPortAssignActionType */
# define ETHSWT_MCAST_PORT_ASSIGN_ACTION_ADD     (0u)
# define ETHSWT_MCAST_PORT_ASSIGN_ACTION_REMOVE  (1u)

/*! Enumeration values for type EthSwt_ArlEntryTypeType */
# define ETHSWT_ARL_TABLE_ENTRY_TYPE_ANY         (0u)
# define ETHSWT_ARL_TABLE_ENTRY_TYPE_LEARNED     (1u)
# define ETHSWT_ARL_TABLE_ENTRY_TYPE_STATIC      (2u)

/*! Hardware port identification */
# define ETHSWT_PORT_0                           (0u)
# define ETHSWT_PORT_1                           (1u)
# define ETHSWT_PORT_2                           (2u)
# define ETHSWT_PORT_3                           (3u)
# define ETHSWT_PORT_4                           (4u)
# define ETHSWT_PORT_5                           (5u)
# define ETHSWT_PORT_6                           (6u)
# define ETHSWT_PORT_7                           (7u)
# define ETHSWT_PORT_8                           (8u)
# define ETHSWT_PORT_9                           (9u)
# define ETHSWT_PORT_10                         (10u)
# define ETHSWT_PORT_11                         (11u)
# define ETHSWT_PORT_12                         (12u)
# define ETHSWT_PORT_13                         (13u)
# define ETHSWT_PORT_14                         (14u)
# define ETHSWT_PORT_15                         (15u)
# define ETHSWT_PORT_16                         (16u)
# define ETHSWT_PORT_17                         (17u)
# define ETHSWT_PORT_18                         (18u)
# define ETHSWT_PORT_19                         (19u)
# define ETHSWT_PORT_20                         (20u)
# define ETHSWT_PORT_21                         (21u)
# define ETHSWT_PORT_22                         (22u)
# define ETHSWT_PORT_23                         (23u)
# define ETHSWT_PORT_24                         (24u)
# define ETHSWT_PORT_25                         (25u)
# define ETHSWT_PORT_26                         (26u)
# define ETHSWT_PORT_27                         (27u)
# define ETHSWT_PORT_28                         (28u)
# define ETHSWT_PORT_29                         (29u)
# define ETHSWT_PORT_30                         (30u)
# define ETHSWT_PORT_31                         (31u)

/*! Highest valid VLAN ID */
# define ETHSWT_VLAN_MAX_VID                   (4094u)
/*! Invalid VLAN ID */
# define ETHSWT_VLAN_INV_VID                   (ETHSWT_VLAN_MAX_VID + 1u)

# define ETHSWT_MAX_ARL_ENTRIES              (65535u)

# define ETHSWT_DROP_COUNT_NUM                  (14u)
# define ETHSWT_ETHERT_STATS_NUM                (17u)

/*! Identification of invalid/unused switch ports */
# define ETHSWT_INV_PORT_IDX                  (0xFFu)
# define ETHSWT_PORT_NOT_CONFIGURED           ETHSWT_INV_PORT_IDX
# define ETHSWT_PORT_NO_TRCV_DRV_USED         ETHSWT_INV_PORT_IDX
# define ETHSWT_PORT_NO_MII_ACCESS            ETHSWT_INV_PORT_IDX
# define ETHSWT_NO_XMII_PORT                  ETHSWT_INV_PORT_IDX

/*! Enumeration values for type EthSwt_PortMirrorStateType */
# define ETHSWT_PORT_MIRROR_DISABLED          (0x00u)
# define ETHSWT_PORT_MIRROR_ENABLED           (0x01u)
# define ETHSWT_PORT_MIRROR_INVALID           (0x02u)

/*! Enumeration values for MirroringMode */
# define ETHSWT_MIRROR_MODE_NO_VLAN_RETAGGING     (0x00u)
# define ETHSWT_MIRROR_MODE_VLAN_RETAGGING        (0x01u)
# define ETHSWT_MIRROR_MODE_DOUBLE_VLAN_RETAGGING (0x02u)

/*! Enumeration values for EthSwt_MgmtOwner */
# define ETHSWT_MGMT_OBJ_UNUSED                (0x00u)
# define ETHSWT_MGMT_OBJ_OWNED_BY_ETHSWT       (0x01u)
# define ETHSWT_MGMT_OBJ_OWNED_BY_UPPER_LAYER  (0x02u)

/*! User Defined return value returned by Hardware Filter interface */
# define ETHSWT_HW_FILTER_E_STATE_PENDING       (2u)
/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
/* PRQA S 0342,0881 ETHSWT_GENERAL_GLUE_OPERATOR */ /* MD_MSR_19.13_0342 */

/*! Macro for better readability of start of exclusive area */
# define EthSwt_EnterExclusiveArea(Derivative, Area) \
          SchM_Enter_EthSwt_30_##Derivative##_EXCLUSIVE_AREA_##Area()

/*! Macro for better readability of end of exclusive area */
# define EthSwt_ExitExclusiveArea(Derivative, Area) \
          SchM_Exit_EthSwt_30_##Derivative##_EXCLUSIVE_AREA_##Area()

/* PRQA L:ETHSWT_GENERAL_GLUE_OPERATOR */

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
/*! Dummy type for multiple configuration. (Isn't supported by AUTOSAR at the moment) */
/*! \trace SPEC-2265332 */
typedef struct
{
  uint8 DummyData; /**< dummy data because multiple configuration isn't supported */
} EthSwt_ConfigType;

/*! AUTOSAR type (deviation) for holding MAC address, VLAN ID and port mapping information. */
/*! \trace SPEC-2265333 */
typedef struct
{
  uint8  MacAddr[6]; /**< MAC address */
  uint16 VlanId;     /**< VLAN ID */
  uint32 SwitchPort; /**< Switch port bitmask, bit indices correspond to EthSwtPortIdx (deviation) */
} EthSwt_MacVlanType;

/*! AUTOSAR type for module state. */
/*! \trace SPEC-2265331 */
typedef uint8  EthSwt_StateType;

/*! AUTOSAR type for switch index. */
typedef uint8  EthSwt_SwitchIdxType;

/*! AUTOSAR type for port index. */
typedef uint8 EthSwt_PortIdxType;

/*! AUTOSAR type for buffer level. */
typedef uint32 EthSwt_BufferLevelType;

/*! AUTOSAR type for MAC learning type. */
/*! \trace SPEC-2265334 */
typedef uint8 EthSwt_MacLearningType;

/*! AUTOSAR type for port mode. */
typedef uint8 EthSwt_PortModeType;

/*! Type of VLAN forwarding */
typedef uint8 EthSwt_VlanFwType;

/*! Type of the phyiscal layer of a port */
typedef uint8 EthSwt_PhysicalLayerType;

/*! Type for indicating which interface is used for managing a PHY connected to a xMii port */
typedef uint8 EthSwt_XMiiPortMgmtType;

/*! Type for indicating which connection type is used for a PHY connected to a xMii port */
typedef uint8 EthSwt_XMiiPortConnectionType;

/*! AUTOSAR type for holding the management information for Ethernet frames received/transmitted on switch ports. */
/*! \trace SWS_EthSwt_91002 (AR-2511)*/
typedef struct
{
  EthSwt_SwitchIdxType  SwitchIdx;     /**< EthSwt switch index */
  uint8                 PortIdx;       /**< EthSwt port index, config view (SNV) - Vector name */
  uint8                 SwitchPortIdx; /**< EthSwt port index, config view (SNV) - AUTOSAR SWS name (SWS_EthSwt_91002) */
} EthSwt_MgmtInfoType;

/*! AUTOSAR type for holding validity information of the management information contained in EthSwt_MgmtObjectType */
typedef struct
{
  Std_ReturnType IngressTimestampValid;
  Std_ReturnType EgressTimestampValid;
  Std_ReturnType MgmtInfoValid;
} EthSwt_MgmtObjectValidType;

/*! AUTOSAR type for holding ownership information of EthSwt_MgmtObjectType */
typedef uint8 EthSwt_MgmtOwner;

/*! Type for holding egress timestamp information for asymmetric time synchronization */
typedef struct
{
  uint8             CfgPortIdx;           /*!< EthSwt port index, config view (SNV) */
  Std_ReturnType    EgressTimestampValid;
  Eth_TimeStampType EgressTimestamp;
} EthSwt_VMgmtEgrTsInfoType;

/*! Type for holding additional information for asymmetric time synchronization of EthSwt_MgmtObjectType */
typedef struct
{
  uint8                       NumEgrTsInfos;
  EthSwt_VMgmtEgrTsInfoType  *EgrTsInfoPtr;
} EthSwt_VMgmtObjectAddInfoType;

/*! AUTOSAR type (deviation) for sharing management information with protocol stack (upper layers) */
/*! \trace SPEC-20655611 */
typedef struct
{
  EthSwt_MgmtObjectValidType    Validation;
  Eth_TimeStampType             IngressTimestamp;
  Eth_TimeStampType             EgressTimestamp;
  EthSwt_MgmtInfoType           MgmtInfo;
  EthSwt_MgmtOwner              Ownership;
  EthSwt_VMgmtObjectAddInfoType AddInfo;  /*!< For asymmetric time synchronization */
} EthSwt_MgmtObjectType;

/*! Type for defining the action that is applied during EthSwt_UpdateMCastPortAssignment() */
typedef uint8 EthSwt_MCastPortAssignActionType;

/*! Type of address resolution table entry */
typedef uint8 EthSwt_ArlEntryTypeType;

/*! MAC address forwarding type */
typedef struct
{
  uint32 PortFwVector;                /*!< Bitmask defining the port forwarding vector: Bit 0 -> HwPort 0, Bit 1 -> HwPort 1, ... */
  uint8  Mac[ETH_PHYS_ADDR_LEN_BYTE]; /*!< Related MAC address */
} EthSwt_MacFwInfoType;

/*! VLAN modification type */
typedef struct
{
  uint32 EgressAllowed;  /*!< Bit mask defining egress allowed ports: Bit 0 -> HwPort 0, Bit 1 -> HwPort 1, ... */
  uint32 IngressAllowed; /*!< Bit mask defining ingress allowed ports: Bit 0 -> HwPort 0, Bit 1 -> HwPort 1, ... */
  uint32 EgressTagged;   /*!< Bit mask defining egress tagged ports: Bit 0 -> HwPort 0, Bit 1 -> HwPort 1, ... */
  uint16 VlanId;         /*!< Related VLAN ID */
} EthSwt_VlanModType;

/*! Port mirroring configuration type */
typedef struct
{
  uint8    CapturePortIdx;                            /*!< Switch port which captures mirrored traffic
                                                           - symbolic name value from configuration must be used */
  uint8    srcMacAddrFilter[ETH_PHYS_ADDR_LEN_BYTE];  /*!< Source MAC address of packets which shall be mirrored */
  uint8    dstMacAddrFilter[ETH_PHYS_ADDR_LEN_BYTE];  /*!< Destination MAC address of packets which shall be mirrored */
  uint16   VlanIdFilter;                              /*!< VLAN ID of frames which shall be mirrored */
  uint8    MirroringPacketDivider;                    /*!< Limits mirrored frames: 1 -> all frames, 2 -> every second frame, ... */
  uint8    MirroringMode;                             /*!< Retagging of mirrored frames: 0x00 == no VLAN retagging,
                                                       *   0x01 == VLAN retagging, 0x02 == VLAN double retagging */
  uint16   VlanOuterTag;                              /*!< VLAN ID used for VLAN retagging or as outer tag for VLAN double retagging */
  uint16   VlanInnerTag;                              /*!< VLAN ID used as inner tag for VLAN double retagging */
  uint32   MirroredSwitchEgressPortIdxBitMask;        /*!< Bit mask defining ports where egress frames shall be mirrored
                                                           - symbolic name values from configuration must be used */
  uint32   MirroredSwitchIngressPortIdxBitMask;       /*!< Bit mask defining ports where ingress frames shall be mirrored
                                                           - symbolic name values from configuration must be used */
} EthSwt_PortMirrorCfgType;

/*! Switch port mirroring state type */
typedef uint8 EthSwt_PortMirrorStateType;

/*! Type for Hardware Filter match data */
typedef uint8 FilterEntryMatchDataType;

/*! Type for Hardware Filter mask data */
typedef uint8 FilterEntryMaskDataType;

/*! Type for total lenth of hardware filter match and mask data */
typedef uint16 FilterEntryLengthType;

/*! Type for indicating which Hardware Filter Action needs to be selected */
typedef enum
{
  ETHSWT_FILTER_ACTION_NONE,
  ETHSWT_FILTER_ACTION_ALLOW,
  ETHSWT_FILTER_ACTION_FORWARD,
  ETHSWT_FILTER_ACTION_BLOCK,
  ETHSWT_FILTER_ACTION_VLAN_MODIFICATION,
  ETHSWT_FILTER_ACTION_VLAN_MODIFICATION_FORWARD
} EthSwt_HwFilterEntryActionType;

/*! Type for indicating which Destination Port Modification type is used when Destination Port Modification is selected */
typedef enum
{
  ETHSWT_STREAM_EGRESS_DESTINATION_TYPE_DONT_CARE,
  ETHSWT_STREAM_EGRESS_DESTINATION_EXTEND,
  ETHSWT_STREAM_EGRESS_DESTINATION_LIMIT,
  ETHSWT_STREAM_EGRESS_DESTINATION_OVERWRITE
} EthSwt_StreamFiltActionDPVType;

/*! Type for configuring mask and match data for Hardware Filter entry */
typedef struct
{
  const FilterEntryMatchDataType       *FilterEntryMatchDataPtr;
  const FilterEntryMaskDataType        *FilterEntryMaskDataPtr;
  FilterEntryLengthType                 FilterEntryLength;
} EthSwt_FilterEntryInfoType;

/*! Type for configuring entries in hardware using Hardware Filter interface */
typedef struct
{
  EthSwt_FilterEntryInfoType             HwFilterEntryInfo;
  uint32                                 UsedPortsMask;
  uint32                                 DestPortsMask;
  uint32                                 RxQueueId;
  uint16                                 ModifiedVlanID;
  uint16                                 StreamId;
  uint16                                 FlowMeterId;
  EthSwt_HwFilterEntryActionType         HwFilterAction;
  EthSwt_StreamFiltActionDPVType         DPVType;
} EthSwt_HwFilterEntryConfigType;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

#endif /* ETHSWT_GENERALTYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: EthSwt_GeneralTypes.h
 *********************************************************************************************************************/
