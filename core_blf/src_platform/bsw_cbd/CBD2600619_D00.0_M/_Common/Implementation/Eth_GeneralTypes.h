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
/**        \file  Eth_GeneralTypes.h
 *        \brief  General types header for the Ethernet stack
 *
 *      \details  Holds general data types and defines provided to and used by multiple components of the Vector
 *                Ethernet stack.
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  REVISION HISTORY
 *  ----------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author       Change Id     Description
 *  ----------------------------------------------------------------------------------------------------------------------
 *  00.01.00  2017-07-14  visfer       -             Initial creation based on merge of Eth_GeneralTypes.h,
 *                                                   EthTrcv_GeneralTypes.hand EthSwt_GeneralTypes.h,
 *                                                   adaptions for AUTOSAR compliance
 *  00.02.00  2017-10-04  visfer       -             Reorder members of Eth_TimeStampType, added Eth_CounterType and
 *                                                   Eth_TxErrorCounterValuesType
 *  03.00.00  2018-11-20  visnhe       STORYC-5875   Release Impl_EthGeneralTypes of CommonAsr__Common
 *  03.00.01  2019-02-25  vismha       ESCAN00102246 Compiler error: EthSwt_GeneralTypes.h missing identifiers
 *  04.00.00  2019-04-29  visdrr       STORYC-7881   Interface between DrvEth__coreAsr and DrvEthSwitch__coreAsr according to ASR4.4.x (DrvEthSwitch__coreAsr)
 *                                     STORYC-7882   Interface between DrvEth__coreAsr and DrvEthSwitch__coreAsr according to ASR4.4.x (DrvEth__coreAsr)
 *  04.00.01  2019-05-22  visdrr       ESCAN00103216 Unused types and struct members defined in Eth_GeneralTypes and
 *                                                   EthSwt_GeneralTypes
 *            2019-07-02  vismha       STORYC-7864   Introduce management object retrieval in reception path
 *                                     STORYC-7865   Introduce management object retrieval in transmission path
 *  04.01.00  2020-04-16  visdrr       ETH-1255      Provide information about dropped frames due to insufficient Tx/Rx
 *                                                   software buffers
 *            2020-04-23  visken       ESCAN00105580 SGMII configuration incomplete - Added type and defenitions in
 *                                                   EthSwt_GeneralTypes to store xMII connection type of a switch port
 *  04.02.00  2021-05-11  visken       ETHPLAY-28    Allow basic switching based on MAC address only - Added new definitions
 *                                                   for PortSpeed, BaudRate and XMiiPortConnectionType
 *  04.03.00  2021-11-17  virpab       ETHPLAY-1759  Introduction of new definitions for CableDiagResult to CommonAsr__Common
 *  04.04.00  2022-08-09  visapp       ETHPLAY-2576  Change typedef EthSwt_MacVlanType in EthSwt_GeneralTypes.h to support
 *                                                   uint32 bitmask in element SwitchPort
 *  04.05.00  2022-11-25  dkeswani     ETHPLAY-1788  Add asymmetric time synchronization support
 *  04.06.00  2023-03-01  baubeck      ETHCIF-2465   Added missing types from ASR 4.3.0, 4.6.0 and 4.7.0.
 *                                                   Changed Eth_RateRatioType to struct.
 *  04.07.00  2023-04-03  mloy         ETHCIF-1591   Implement USXGMII support.
 *  04.08.00  2023-06-12  mmares       ETHCIF-4052   Communication speeds 5Gbit/s and 10 Gbit/s were added
 *  04.09.00  2023-07-10  dkeswani     ETHPLAY-4899  Add Destination Port Modification Types in EthSwtGeneralTypes.h
 *  04.10.00  2024-10-22  visdep       OSHAL-2156    Introduced conditional typedef for Eth_TimeStampType based on the
 *                                                   existence of TimeStampType to avoid type redefinition conflicts.
 *  04.11.00  2024-11-05  dkeswani     ETHPLAY-5526  Define EthSwt_HwFilterEntryConfigType at EthSwt_GeneralTypes.h
 *            2024-11-06  pkotteti     DADC-145      WODL feature supportive Transceiver Macros
 *            2024-11-11  dkeswani     ETHPLAY-3532  Analyse how to configure half duplex mode and implement it - Added new
 *                                                   types for Half and Full Duplex
 *  04.12.00  2024-11-22  visdep       OSHAL-2322    Conditionally introduced TimeStamp types from AR23-11 if they are not
 *                                                   already defined in ComStack_Types.h
 *  04.13.00  2024-11-22  pkotteti     DADC-145      WODL feature supportive Transceiver Macros
 *  04.14.00  2025-02-25  baubeck      ETHCIF-10194  Introduce Eth_RateDeviationType and Eth_StreamStatisticCounterType
 *  04.15.00  2025-02-27  viraid       ETHPLAY-5370  Change the Eth_DataType from uint32 to uint8
 *  04.16.00  2025-02-27  pkotteti     PS-7666       WODL feature supportive Transceiver Macros
 *  04.17.00  2025-06-23  baubeck      ETHCIF-11432  Add Preprocessor Conditionals Around Eth_SpiStatusType and
 *                                                   Eth_RateDeviationType
 *  04.18.00  2025-06-25  mbodenstein  ENOVA-59      Introduce Eth_TimestampQualType and #define ETH_TIMESTAMP_QUAL_TYPE_IN_ETH_GENERAL_TYPES
 *                                                   to indicate that Eth_TimestampQualType is available in Eth_GeneralTypes.
 *  04.18.01  2025-07-03  mbodenstein  ENOVA-1256    Fix Typo in Eth_TimeStampQualType.
 *  04.19.00  2025-07-07  mschmitt     ETHPLAY-7001  Add PhysicalLayerType for 10BASE-T1S
 *  04.20.00  2025-08-07  jgrandhi     ETHPLAY-1710  Move All SWS EthernetDriver related Definations to new file Eth_GeneralTypesDefs.h
 *  04.21.00  2025-10-24  dkeswani     ETHPLAY-7948  Introduction of PENDING state as return value for HW Filter APIs
 *  04.21.01  2026-04-23  mhasanovic   ENOVA-2339    Add SwitchPortIdx member to EthSwt_MgmtInfoType for AUTOSAR SWS_EthSwt_91002 compliance
 **********************************************************************************************************************/
#ifndef ETH_GENERAL_TYPES_H
# define ETH_GENERAL_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
# include "Std_Types.h"
# include "ComStack_Types.h"
# include "Eth_GeneralTypesDefs.h"
# include "EthTrcv_GeneralTypes.h"
# include "EthSwt_GeneralTypes.h"

#endif /* ETH_GENERAL_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: Eth_GeneralTypes.h
 *********************************************************************************************************************/
